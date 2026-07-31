-- Character Mode <-> Randomized Party Mode exclusion, end to end.
--
-- Randomized Party Mode (FLAG_FULL_RANDOMIZED_MODE, shipped c231ba2a) is
-- mutually exclusive with Character Mode by user ruling. The exclusion is
-- enforced in FOUR places (PLAN.md 7.10) and had zero e2e coverage; this run
-- drives all four on a real ROM. It closes items 21, 22 and 23 of
-- PLAYTHROUGH_CHECKLISTS.md section 4.
--
--   point 1  Start_EventScript_Game_Mode_Random_Party -- enabling RPM while
--            Character Mode is on prompts "Turn Character Mode off?".
--            NO changes NOTHING; YES clears FLAG_CHARACTER_MODE and
--            VAR_CHARACTER_ID and turns RPM on.                    (item 21)
--   point 2  Start_EventScript_Character_Mode -- the mirror prompt, asked
--            BEFORE the menu opens because Task_MenuMain has no B_BUTTON case:
--            the character screen cannot be backed out of and entering it
--            always commits a character. This prompt is the only place a NO
--            can still mean anything.                              (item 22)
--   point 3  ui_mode_menu.c at the START commit -- FlagClear(RPM).
--   point 4  battle_main.c at the RandomizeParty() call site -- Character Mode
--            WINS if both are somehow set. This is the guard that actually
--            protects the roster (an old save, the debug toggle), and the one
--            to keep if the others are ever refactored away.       (item 23)
--
-- ---------------------------------------------------------------------------
-- WHY THIS TEST IS BUILT THE WAY IT IS
-- ---------------------------------------------------------------------------
-- The recurring failure in this repo is THE TEST THAT CANNOT FAIL, and the
-- obvious form of item 23 has exactly that shape: "the party was not re-rolled"
-- passes when the exclusion works AND when RandomizeParty() never ran at all.
-- So every assertion here is PAIRED with its own opposite, in the same run, on
-- the same ROM:
--
--   * item 23 runs TWO battles. The first has both flags set and asserts the
--     party is untouched. The second clears Character Mode ONLY -- same party,
--     same battle call, same RPM flag -- and asserts the party IS re-rolled.
--     If RandomizeParty were dead, battle 2 goes red.
--   * item 22 answers NO and asserts nothing happened, then answers YES on the
--     identical prompt and asserts the character screen DID open and the flag
--     DID clear. If the prompt were never reached, the YES pass goes red.
--   * item 21 answers NO then YES on the identical prompt, same reasoning.
--
-- Every menu answer is confirmed through gSpecialVar_Result rather than assumed
-- from a keypress. A swallowed A press and a genuine "NO changed nothing" leave
-- the game in *identical* states, so watching only the flags cannot tell them
-- apart -- the drive writes a sentinel into VAR_RESULT and waits for the menu's
-- own answer to replace it, and fails loudly on the wrong answer.
--
-- ---------------------------------------------------------------------------
-- ⚠️ WHAT THE EXCLUSION DOES *NOT* COVER, found by running this
-- ---------------------------------------------------------------------------
-- With both flags set, party LEVELS still move. Randomized Party Mode's other
-- readers are not gated by Character Mode at all -- in particular
-- GetGrowthRate() (pokemon.c:9632) returns SPECIES_BULBASAUR for every species
-- while RPM is on, and RandomizeIfSpeciesNone() -- which runs unconditionally
-- immediately after the guard -- calls CalculateMonStats on every party mon, so
-- the stored level is recomputed from the same EXP on Bulbasaur's MEDIUM_SLOW
-- curve. A Lv10 MEDIUM_FAST Pikachu reads back as Lv12. Species, moves and slot
-- order are untouched, which is what the ROSTER guard promises; this is a real
-- but separate leak, and the test asserts on species and moves rather than
-- pretending the level is stable.
--
-- Run (no CM_SAV -- drives a real new game):
--   timeout 150 <mgba-headless> \
--     --script tools/mgba_scripts/mode_exclusion_e2e.lua pokeemerald.gba \
--     > /tmp/mode_exclusion.log 2>&1

local H = dofile("tools/mgba_scripts/harness.lua")
local D = dofile("tools/mgba_scripts/intro_drive.lua")(H)

-- ---------------------------------------------------------------- constants

local FLAG_CHARACTER_MODE      = D.FLAG_CHARACTER_MODE   -- 9135
local FLAG_FULL_RANDOMIZED_MODE = 9137
local VAR_CHARACTER_ID         = D.VAR_CHARACTER_ID      -- 17001

local CHAR_RED = 1

-- All on Red's roster (src/data/characters.h sRoster_Red), so Character Mode's
-- gift gate hands them to the PARTY rather than diverting them to the PC --
-- an empty party would make every "unchanged" assertion below vacuous.
local SPECIES_BULBASAUR  = 1
local SPECIES_CHARMANDER = 4
local SPECIES_SQUIRTLE   = 7
local SPECIES_PIKACHU    = 25
local SPECIES_POOCHYENA  = 261   -- the wild opponent; off every roster used here

local PARTY_SLOTS = 4            -- Pikachu (intro) + the three gifts

local MENU_SENTINEL = 0xFFFF     -- not a menu result; MULTI_B_PRESSED is 127
-- ScriptMenu_Multichoice and ScriptMenu_YesNo both write 0xFF into VAR_RESULT
-- the moment they CREATE the menu (src/script_menu.c:54, :275). That is a free,
-- unambiguous "the prompt really appeared" signal -- without it, a NO-changed-
-- nothing assertion could not be told from a prompt that never ran.
local MENU_OPENED = 0xFF
local YESNO_YES = 1              -- gSpecialVar_Result after CreateYesNoMenu
local YESNO_NO  = 0
local CURSOR_YES = 0             -- gText_YesNo is "YES" then "NO"
local CURSOR_NO  = 1

-- A green run finishes around frame 9000. This is set well above that but well
-- below what `timeout 100` allows (~180000 frames at ~1800 fps), so a hung step
-- reports RESULT: FAIL rather than being cut off with no verdict at all.
D.DEADLINE = 120000

-- --------------------------------------------------------------- game state

local function inBattle() return D.cb2() == H.anchors.BattleMainCB2 + 1 end
local function varResult() return H.rd16(H.anchors.gSpecialVar_Result) end

-- ------------------------------------------------------------ step helpers

local function assertFlagStep(name, flagId, want)
    D.mbStep(name, D.REQ.QUERY_FLAG, flagId, 0, function()
        H.assertEq(name, D.mbResult(), want)
    end)
end

local function assertVarStep(name, varId, want)
    D.mbStep(name, D.REQ.QUERY_VAR, varId, 0, function()
        H.assertEq(name, D.mbResult(), want)
    end)
end

-- Set/clear a flag by writing SaveBlock1.flags directly, then read it back
-- through the game's own FlagGet. The raw write exists because the mailbox pump
-- only runs from CB2_Overworld and BattleMainCB2 -- while the Character Mode
-- menu owns the screen there is no other way to touch game state -- and the
-- readback exists so a wrong address can never read as a pass.
local function setFlagStep(name, flagId, on)
    D.addStep(name, nil, function()
        H.rawFlagSet(flagId, on)
        return true
    end)
    D.mbStep(name .. ": the game's own FlagGet agrees", D.REQ.QUERY_FLAG, flagId, 0,
        function()
            H.assertEq(name .. ": the game's own FlagGet agrees",
                       D.mbResult(), on and 1 or 0)
        end)
end

-- RUN_SCRIPT, retried. The mailbox rejects it while another script holds the
-- lock, and the tail of the previous phase (Starter_Chose's lock/release pair)
-- can still be in flight, so a single-shot request is a race.
local function runScriptStep(name, addr)
    D.addStep(name,
        nil,
        function(f)
            local age = f - D.stepStart()
            if age > 0 and D.mbStatus() == D.STATUS_DONE then
                H.assertTrue(name .. " (RUN_SCRIPT accepted)", true)
                return true
            end
            if age > 8000 then
                H.assertTrue(name .. " (RUN_SCRIPT accepted)", false)
                return true
            end
            if (age % 120) == 0 then
                D.mbRequest(D.REQ.RUN_SCRIPT, addr % 65536, math.floor(addr / 65536))
            end
            return false
        end)
end

-- Answer one on-screen menu and PROVE the answer landed.
--
--   expectMax     struct Menu maxCursorPos while this menu is up (itemCount-1).
--                 Only plain multichoice and yes/no write sMenu; the scrolling
--                 multichoice uses a ListMenu and never touches it.
--   target        cursor row to select.
--   expectResult  what gSpecialVar_Result must become. A different value is a
--                 hard failure, not a retry: it means the drive answered the
--                 wrong row.
--
-- The sentinel is written 60 frames in, never on entry: the previous menu's
-- own result is still being read by the script's switch for a few frames after
-- the task hands control back, and clobbering it there would send the script
-- down its default branch.
local function chooseMenu(name, expectMax, target, expectResult, timeout)
    local armed, sawOpen = false, false
    D.addStep(name,
        function() armed, sawOpen = false, false end,
        function(f)
            local age = f - D.stepStart()
            D.heartbeat(f)

            if not armed then
                if age >= 60 then
                    H.wr16(H.anchors.gSpecialVar_Result, MENU_SENTINEL)
                    armed = true
                end
                return false
            end

            local r = varResult()
            if r == MENU_OPENED then sawOpen = true end
            if r == expectResult then
                D.clearAll()
                H.assertTrue(name .. " -- the prompt was really created", sawOpen)
                H.assertTrue(name, true)
                return true
            end
            if r ~= MENU_SENTINEL and r ~= MENU_OPENED then
                D.clearAll()
                H.assertEq(name .. " (VAR_RESULT)", r, expectResult)
                return true
            end
            if age > (timeout or 30000) then
                D.clearAll()
                H.assertTrue(name .. " -- the prompt was really created", sawOpen)
                H.assertTrue(name .. " (menu answered before deadline)", false)
                return true
            end

            if D.menuMax() ~= expectMax then
                -- Dialogue page (these messages contain \p), fanfare, or a
                -- menu that has not been built yet: A advances text.
                D.tapEvery(f, H.KEY.A, 31)
                return false
            end

            -- The menu is up. Steer first, press only when the cursor is on
            -- the target -- so a swallowed press is simply repeated on the same
            -- row rather than landing on a different one.
            local cur = D.menuCur()
            if cur ~= target then
                emu:clearKey(H.KEY.A)
                if (f % 17) == 0 then
                    if cur < target then emu:addKey(H.KEY.DOWN)
                    else emu:addKey(H.KEY.UP) end
                else
                    emu:clearKey(H.KEY.DOWN)
                    emu:clearKey(H.KEY.UP)
                end
                return false
            end
            emu:clearKey(H.KEY.DOWN)
            emu:clearKey(H.KEY.UP)
            -- Hold for a few frames: a one-frame tap is what gets dropped.
            if (f % 24) < 5 then emu:addKey(H.KEY.A) else emu:clearKey(H.KEY.A) end
            return false
        end)
end

-- sMenu is never cleared when a menu closes, so a stale maxCursorPos can make
-- the NEXT drive think its menu is already up. Poison it while nothing is on
-- screen, exactly as intro_drive does after the questions menu.
local function poisonStep(name)
    D.addStep(name or "poison the stale menu bounds", nil, function()
        D.poisonMenu()
        return true
    end)
end

-- Drive the Character Mode menu's START commit. `beforeCommit` runs once, on
-- the field-less frame after the menu has finished loading -- that is the only
-- window in which FLAG_FULL_RANDOMIZED_MODE can be set behind the menu's back,
-- which is what point 3 needs.
local function commitCharacterMenu(name, sawMenu, beforeCommit)
    D.addStep(name,
        nil,
        function(f)
            local age = f - D.stepStart()
            D.heartbeat(f)
            if not sawMenu.opened then
                if not D.onField() then
                    sawMenu.opened = true
                    sawMenu.openFrame = f
                    H.log(string.format("character menu opened at frame %d, cb2=%s",
                                        f, H.hex(D.cb2())))
                end
                if age > 20000 then
                    H.assertTrue(name .. " (character screen opened)", false)
                    return true
                end
                return false
            end
            if not sawMenu.armed and f - sawMenu.openFrame > 400 then
                sawMenu.armed = true
                if beforeCommit then beforeCommit() end
            end
            if sawMenu.armed and D.onField() then
                D.clearAll()
                H.log("character menu committed at frame " .. f)
                return true
            end
            if age > 40000 then
                H.assertTrue(name .. " (START committed the character menu)", false)
                return true
            end
            if sawMenu.armed then D.tapEvery(f, H.KEY.START, 47) end
            return false
        end)
end

-- Read PARTY_SLOTS party slots into `tbl`: species, level, and move slot 0.
--
-- The move matters as much as the species here. RandomizeParty wipes ALL FOUR
-- move slots before it touches the species, so an intact move 0 is a second,
-- independent witness that the function did not run -- and unlike the level it
-- is not disturbed by anything else Randomized Party Mode does.
local OP_READ_MOVE = 2   -- CM_REQ_LEARNSET_PROBE op (argA = slot | op << 8)

local function readParty(prefix, tbl)
    for slot = 0, PARTY_SLOTS - 1 do
        local s = slot
        D.mbStep(prefix .. ": read slot " .. s, D.REQ.QUERY_PARTY_MON, s, 0,
            function()
                local r = D.mbResult()
                tbl[s] = { species = r % 65536, level = math.floor(r / 65536) }
            end)
        D.mbStep(prefix .. ": read slot " .. s .. " move 0", D.REQ.LEARNSET_PROBE,
            s + OP_READ_MOVE * 256, 0,
            function()
                tbl[s].move0 = D.mbResult()
                H.log(string.format("%s slot %d: species=%d level=%d move0=%d",
                                    prefix, s, tbl[s].species, tbl[s].level,
                                    tbl[s].move0))
            end)
    end
end

-- Start a scripted wild battle and read the party back from INSIDE it. The
-- re-roll (or not) happens in CB2_InitBattleInternal, before BattleMainCB2 ever
-- runs, so the first in-battle read is the earliest observation there is.
local function battleAndReadParty(label, tbl)
    -- CM_REQ_WILD_BATTLE is refused while a script holds ScriptContext2, and
    -- the tail of the PREVIOUS scripted battle re-enables it after the return
    -- to the field -- so a single UNLOCK-then-battle pair is a race that only
    -- sometimes wins. Unlock, ask, and go round again on a refusal; stop asking
    -- the moment the request is accepted so the battle is never started twice.
    local bst = {}
    D.addStep(label .. ": start a wild battle and reach it",
        function() bst.st, bst.t = nil, 0 end,
        function(f)
            local st = bst.st
            D.heartbeat(f)
            if inBattle() then
                D.clearAll()
                H.assertTrue(label .. ": reached the battle", true)
                return true
            end
            if f - D.stepStart() > 40000 then
                H.assertTrue(label .. ": reached the battle", false)
                return true
            end
            if st == nil then
                D.mbRequest(D.REQ.UNLOCK, 0, 0)
                bst.st, bst.t = "unlocking", f
            elseif st == "unlocking" then
                if f - bst.t > 30 then
                    D.mbRequest(D.REQ.WILD_BATTLE, SPECIES_POOCHYENA, 10)
                    bst.st, bst.t = "asking", f
                end
            elseif st == "asking" then
                local s = D.mbStatus()
                if s == D.STATUS_DONE then
                    bst.st = "started"
                elseif s == D.STATUS_REJECTED or f - bst.t > 300 then
                    H.log(label .. ": WILD_BATTLE refused (script lock); retrying")
                    bst.st = nil
                end
            else
                D.tapEvery(f, H.KEY.B, 37)  -- the battle intro waits on a keypress
            end
            return false
        end)

    readParty(label .. " (in battle)", tbl)

    D.addStep(label .. ": escape the battle",
        nil,
        function(f)
            if not inBattle() and D.onField() then
                D.clearAll()
                return true
            end
            if inBattle() then
                emu:clearKey(H.KEY.A)
                emu:clearKey(H.KEY.B)
                emu:clearKey(H.KEY.DOWN)
                emu:clearKey(H.KEY.RIGHT)
                local cursor = H.rd8(H.anchors.gActionSelectionCursor)
                local tick = f % 24
                if tick == 0 then
                    if cursor == 3 then emu:addKey(H.KEY.A)       -- RUN
                    elseif cursor == 2 then emu:addKey(H.KEY.RIGHT)
                    else emu:addKey(H.KEY.DOWN) end
                elseif tick == 12 then
                    emu:addKey(H.KEY.B)   -- advance intro/outro text
                end
            end
            if f - D.stepStart() > 40000 then
                H.assertTrue(label .. ": escaped the battle", false)
                return true
            end
            return false
        end)

    D.mbStep(label .. ": unlock the field", D.REQ.UNLOCK, 0, 0)
end

-- ===========================================================================
-- Phase 0 -- a real new game, committed as Red in Character Mode.
-- ===========================================================================

D.driveNewGameCharacterMode()

assertFlagStep("baseline: FLAG_CHARACTER_MODE set", FLAG_CHARACTER_MODE, 1)
assertVarStep("baseline: VAR_CHARACTER_ID == 1 (Red)", VAR_CHARACTER_ID, CHAR_RED)
assertFlagStep("baseline: FLAG_FULL_RANDOMIZED_MODE clear",
               FLAG_FULL_RANDOMIZED_MODE, 0)

-- ===========================================================================
-- ITEM 22 / point 2 -- Start_EventScript_Character_Mode asks FIRST, and NO
-- must return without opening the character screen.
--
-- This is the sharp one. Task_MenuMain has no B_BUTTON case, so once the
-- character screen is open a character WILL be committed; the prompt in front
-- of it is the only surviving NO.
-- ===========================================================================

D.mbStep("item 22 setup: leave Character Mode", D.REQ.SET_CHARACTER, 0, 0,
    function() H.assertEq("item 22 setup: InCharacterMode() is false",
                          D.mbResult(), 0) end)
setFlagStep("item 22 setup: Randomized Party Mode ON", FLAG_FULL_RANDOMIZED_MODE, true)
assertVarStep("item 22 setup: VAR_CHARACTER_ID cleared to 0", VAR_CHARACTER_ID, 0)

poisonStep()
runScriptStep("item 22: run Start_EventScript_Character_Mode (RPM is on)",
              H.anchors.Start_EventScript_Character_Mode)

-- Watch every frame of the prompt: cb2 must never leave CB2_Overworld, i.e.
-- Special_OpenCharacterModeMenu must never run. (fadescreen stays in
-- CB2_Overworld; Menu_Mode_Init is what changes the callback.)
local cmWatch = { active = false, left = false }
H.onFrame(function()
    if cmWatch.active and not D.onField() then cmWatch.left = true end
end)

D.addStep("item 22: start watching for the character screen",
    nil,
    function()
        cmWatch.left = false
        cmWatch.active = true
        return true
    end)

chooseMenu("item 22: the exclusion prompt appeared and was answered NO",
           1, CURSOR_NO, YESNO_NO)

-- Give the script room to reach Starter_Chose (which, post-intro, is the
-- release-only Starter_No_Exploit branch) and to open the menu if it were
-- going to. If NO leaked through, this is where the screen would show up.
D.waitFrames("item 22: settle after the NO", 1200)

D.addStep("item 22: NO never opened the character screen",
    nil,
    function()
        H.assertTrue("item 22: NO never opened the character screen",
                     not cmWatch.left)
        cmWatch.active = false
        return true
    end)
assertFlagStep("item 22: FLAG_CHARACTER_MODE still clear after NO",
               FLAG_CHARACTER_MODE, 0)
assertVarStep("item 22: VAR_CHARACTER_ID unchanged (0) after NO",
              VAR_CHARACTER_ID, 0)
assertFlagStep("item 22: Randomized Party Mode still ON after NO",
               FLAG_FULL_RANDOMIZED_MODE, 1)

-- ------- the pair: the SAME prompt, answered YES, must do all of it -------

poisonStep()
runScriptStep("item 22 control: run Start_EventScript_Character_Mode again",
              H.anchors.Start_EventScript_Character_Mode)
chooseMenu("item 22 control: the same prompt answered YES",
           1, CURSOR_YES, YESNO_YES)

local yesMenu = { opened = false, armed = false }
commitCharacterMenu("item 22 control: YES opened the character screen; START commits",
                    yesMenu, nil)

assertFlagStep("item 22 control: Randomized Party Mode cleared by YES",
               FLAG_FULL_RANDOMIZED_MODE, 0)
assertFlagStep("item 22 control: FLAG_CHARACTER_MODE set by the commit",
               FLAG_CHARACTER_MODE, 1)
assertVarStep("item 22 control: VAR_CHARACTER_ID == 1 (default Gen I/Red)",
              VAR_CHARACTER_ID, CHAR_RED)

-- ===========================================================================
-- POINT 3 -- the START commit in ui_mode_menu.c clears FLAG_FULL_RANDOMIZED_MODE.
--
-- Isolated: RPM is off when the script runs, so no prompt appears and the menu
-- opens straight away; the flag is then set behind the menu's back (the mailbox
-- pump is dead while Menu_MainCB owns the screen, which is exactly why the raw
-- SaveBlock1 write exists) and START must clear it.
-- ===========================================================================

poisonStep()
runScriptStep("point 3: open the character menu with RPM off",
              H.anchors.Start_EventScript_Character_Mode)

local p3Menu = { opened = false, armed = false }
local p3RawSet = -1
commitCharacterMenu("point 3: set RPM behind the open menu, then START",
    p3Menu,
    function()
        p3RawSet = H.rawFlagSet(FLAG_FULL_RANDOMIZED_MODE, true)
        H.log("point 3: raw-set FLAG_FULL_RANDOMIZED_MODE while the menu was open -> "
              .. tostring(p3RawSet))
    end)

D.addStep("point 3: the flag really was set while the menu was open",
    nil,
    function()
        H.assertEq("point 3: the flag really was set while the menu was open",
                   p3RawSet, 1)
        return true
    end)
assertFlagStep("point 3: the START commit cleared FLAG_FULL_RANDOMIZED_MODE",
               FLAG_FULL_RANDOMIZED_MODE, 0)
assertFlagStep("point 3: FLAG_CHARACTER_MODE set by the same commit",
               FLAG_CHARACTER_MODE, 1)

-- ===========================================================================
-- ITEM 23 / point 4 -- battle_main.c: Character Mode WINS if both are set.
--
-- The load-bearing guard. RandomizeParty() (level_scaling.c:2325) wipes all
-- four move slots, replaces the species, renames and recalculates stats,
-- keeping only the level -- so a Character Mode save would come out of the next
-- battle holding Pokemon its own catch gate would have refused.
-- ===========================================================================

D.mbStep("item 23 setup: gift Bulbasaur Lv20 (on Red's roster)", D.REQ.GIVE_MON,
    SPECIES_BULBASAUR, 20,
    function() H.assertEq("item 23 setup: Bulbasaur joined the party",
                          D.mbResult(), 0) end)
D.mbStep("item 23 setup: gift Charmander Lv30 (on Red's roster)", D.REQ.GIVE_MON,
    SPECIES_CHARMANDER, 30,
    function() H.assertEq("item 23 setup: Charmander joined the party",
                          D.mbResult(), 0) end)
D.mbStep("item 23 setup: gift Squirtle Lv40 (on Red's roster)", D.REQ.GIVE_MON,
    SPECIES_SQUIRTLE, 40,
    function() H.assertEq("item 23 setup: Squirtle joined the party",
                          D.mbResult(), 0) end)

D.addStep("item 23 setup: four party slots to compare",
    nil,
    function()
        H.assertEq("item 23 setup: party count is 4", D.partyCount(), PARTY_SLOTS)
        return true
    end)

setFlagStep("item 23 setup: force Randomized Party Mode ON alongside Character Mode",
            FLAG_FULL_RANDOMIZED_MODE, true)
assertFlagStep("item 23: BOTH modes are set going into the battle",
               FLAG_CHARACTER_MODE, 1)

local rosterBefore, rosterAfter = {}, {}
readParty("item 23 (before)", rosterBefore)

D.addStep("item 23: the roster party is the one we expect",
    nil,
    function()
        H.assertEq("item 23: slot 0 is Pikachu", rosterBefore[0].species, SPECIES_PIKACHU)
        H.assertEq("item 23: slot 1 is Bulbasaur", rosterBefore[1].species, SPECIES_BULBASAUR)
        H.assertEq("item 23: slot 2 is Charmander", rosterBefore[2].species, SPECIES_CHARMANDER)
        H.assertEq("item 23: slot 3 is Squirtle", rosterBefore[3].species, SPECIES_SQUIRTLE)
        return true
    end)

battleAndReadParty("item 23 both-modes battle", rosterAfter)

D.addStep("item 23: the party was NOT re-rolled",
    nil,
    function()
        for i = 0, PARTY_SLOTS - 1 do
            H.assertEq(string.format(
                "item 23: slot %d species survived the battle start", i),
                rosterAfter[i].species, rosterBefore[i].species)
            H.assertEq(string.format(
                "item 23: slot %d move 0 survived the battle start "
                .. "(RandomizeParty wipes all four)", i),
                rosterAfter[i].move0, rosterBefore[i].move0)
        end
        -- Slots 1..3 are Bulbasaur/Charmander/Squirtle, all GROWTH_MEDIUM_SLOW,
        -- so their stored level is unaffected by the growth-rate override below.
        for i = 1, PARTY_SLOTS - 1 do
            H.assertEq(string.format(
                "item 23: slot %d level survived the battle start", i),
                rosterAfter[i].level, rosterBefore[i].level)
        end
        -- ⚠️ SLOT 0'S LEVEL LEGITIMATELY MOVES, AND IT IS NOT A RE-ROLL.
        -- Randomized Party Mode also makes GetGrowthRate() (pokemon.c:9632)
        -- return SPECIES_BULBASAUR for EVERY species, and RandomizeIfSpeciesNone
        -- -- which runs unconditionally right after the guard -- calls
        -- CalculateMonStats on every party mon, so the stored level is recomputed
        -- from the same EXP on Bulbasaur's MEDIUM_SLOW curve. Pikachu is
        -- MEDIUM_FAST (1000 EXP at Lv10 -> Lv12 on MEDIUM_SLOW); the other three
        -- are MEDIUM_SLOW already and do not move. The four enforcement points
        -- protect the ROSTER, not every RPM side effect -- see the report note.
        H.log(string.format(
            "item 23: slot 0 level %d -> %d (RPM growth-rate override, species "
            .. "and moves intact)", rosterBefore[0].level, rosterAfter[0].level))
        H.assertTrue(
            "item 23: slot 0's level only ever moved UP by the growth-rate "
            .. "recompute, never re-rolled",
            rosterAfter[0].level >= rosterBefore[0].level)
        return true
    end)

-- ------------------------------------------------------------------------
-- The pair. Same party, same battle call, same RPM flag -- Character Mode is
-- the ONLY thing that changes. Without this, "not re-rolled" would pass just
-- as happily if RandomizeParty() were dead code.
-- ------------------------------------------------------------------------

D.mbStep("item 23 control: turn Character Mode OFF, leave RPM on",
    D.REQ.SET_CHARACTER, 0, 0,
    function() H.assertEq("item 23 control: InCharacterMode() is false",
                          D.mbResult(), 0) end)
assertFlagStep("item 23 control: Randomized Party Mode is still ON",
               FLAG_FULL_RANDOMIZED_MODE, 1)

local ctrlBefore, ctrlAfter = {}, {}
readParty("item 23 control (before)", ctrlBefore)
battleAndReadParty("item 23 control battle", ctrlAfter)

D.addStep("item 23 control: with Character Mode off the party IS re-rolled",
    nil,
    function()
        local changed, movesWiped = 0, 0
        for i = 0, PARTY_SLOTS - 1 do
            if ctrlAfter[i].species ~= ctrlBefore[i].species then
                changed = changed + 1
            end
            if ctrlAfter[i].move0 ~= ctrlBefore[i].move0 then
                movesWiped = movesWiped + 1
            end
            -- RandomizeParty keeps the level; if levels moved, something other
            -- than the re-roll is at work and the comparison means nothing.
            H.assertEq(string.format(
                "item 23 control: slot %d level is preserved by the re-roll", i),
                ctrlAfter[i].level, ctrlBefore[i].level)
        end
        H.log("item 23 control: " .. changed .. " of " .. PARTY_SLOTS ..
              " slots changed species, " .. movesWiped .. " changed move 0")
        H.assertTrue("item 23 control: RandomizeParty() IS live in this ROM " ..
                     "(at least 3 of 4 slots changed species)", changed >= 3)
        H.assertTrue("item 23 control: RandomizeParty() rewrote the movesets too "
                     .. "(at least 3 of 4 slots changed move 0)", movesWiped >= 3)
        return true
    end)

-- ===========================================================================
-- ITEM 21 / point 1 -- Start_EventScript_Game_Mode_Random_Party asks before it
-- changes anything, and NO changes NOTHING.
-- ===========================================================================

D.mbStep("item 21 setup: back into Character Mode as Red",
    D.REQ.SET_CHARACTER, CHAR_RED, 0,
    function() H.assertEq("item 21 setup: InCharacterMode() is true",
                          D.mbResult(), 1) end)
setFlagStep("item 21 setup: Randomized Party Mode OFF", FLAG_FULL_RANDOMIZED_MODE, false)

poisonStep()
runScriptStep("item 21: run Start_EventScript_Game_Mode_Random_Party",
              H.anchors.Start_EventScript_Game_Mode_Random_Party)

-- MULTI_GAME_MODE_ENABLE is {Enable, Info, Cancel} -> maxCursorPos 2, row 0
-- is Enable, which is the branch that has to notice Character Mode.
chooseMenu("item 21: chose Enable on the Randomized Party Mode menu",
           2, 0, 0)
chooseMenu("item 21: the exclusion prompt appeared and was answered NO",
           1, CURSOR_NO, YESNO_NO)

assertFlagStep("item 21: FLAG_CHARACTER_MODE still set after NO",
               FLAG_CHARACTER_MODE, 1)
assertVarStep("item 21: VAR_CHARACTER_ID unchanged (1) after NO",
              VAR_CHARACTER_ID, CHAR_RED)
assertFlagStep("item 21: Randomized Party Mode still OFF after NO",
               FLAG_FULL_RANDOMIZED_MODE, 0)

-- ------- the pair: same menu, same prompt, answered YES this time -------

chooseMenu("item 21 control: chose Enable again (the NO returned to the menu)",
           2, 0, 0)
chooseMenu("item 21 control: the same prompt answered YES",
           1, CURSOR_YES, YESNO_YES)

assertFlagStep("item 21 control: YES cleared FLAG_CHARACTER_MODE",
               FLAG_CHARACTER_MODE, 0)
assertVarStep("item 21 control: YES cleared VAR_CHARACTER_ID",
              VAR_CHARACTER_ID, 0)

-- setflag(FLAG_FULL_RANDOMIZED_MODE) is the LAST thing the enable branch does,
-- after a fanfare and a message, so poll rather than assert immediately.
local rpmPoll = false
D.addStep("item 21 control: Randomized Party Mode was enabled",
    function() rpmPoll = false end,
    function(f)
        local age = f - D.stepStart()
        if age > 30000 then
            H.assertTrue("item 21 control: Randomized Party Mode was enabled", false)
            return true
        end
        D.tapEvery(f, H.KEY.A, 31)
        if not rpmPoll and (age % 401) == 0 then
            D.mbRequest(D.REQ.QUERY_FLAG, FLAG_FULL_RANDOMIZED_MODE, 0)
            rpmPoll = true
        elseif rpmPoll and D.mbStatus() == D.STATUS_DONE then
            rpmPoll = false
            if D.mbResult() == 1 then
                D.clearAll()
                H.assertTrue("item 21 control: Randomized Party Mode was enabled", true)
                return true
            end
        end
        return false
    end)

D.run()
