-- Catch-gate + gift-gate e2e: proves Character Mode enforcement in a REAL
-- battle, end to end -- the Phase 6 item the smokes couldn't reach.
--
-- Drives: Continue into the overworld, then via the in-ROM test mailbox
-- (src/character_mode_selftest.c, pumped by CB2_Overworld under mGBA only):
--   1. SET_CHARACTER(1) = Red             -> InCharacterMode() == TRUE
--   2. Master Ball into the bag + set as last-used ball (R = quick throw)
--   3. WILD_BATTLE Poochyena (off-roster)    -> R throw lands in
--      BattleScript_CharacterBallBlock, battle does NOT end in a catch
--   4. WILD_BATTLE Pikachu (on-roster)    -> R throw catches (outcome 7)
--   5. GIVE_MON Poochyena  (off-roster gift) -> routed to the PC
--   6. GIVE_MON Pikachu (on-roster gift)  -> party if there is room
--
-- Run. CM_SAV must be a fixture in the CURRENT save format -- saves written
-- before the 12-character-name change are refused by design and this test then
-- fails in ways that look like the catch gate broke. Regenerate with
-- tools/mgba_scripts/make_fixture_save.lua (see continue_smoke.lua's header).
--   CM_SAV=~/Documents/rowe_fixture.sav timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/catch_gate_e2e.lua pokeemerald.gba \
--     > /tmp/catch_gate_e2e.log 2>&1
--
-- Nothing is saved; every mutation lives and dies in RAM.

local H = dofile("tools/mgba_scripts/harness.lua")

local sav = os.getenv("CM_SAV")
if not sav then
    error("set CM_SAV to the .sav file to continue from")
end
if not emu:loadSaveFile(sav, false) then
    error("loadSaveFile failed: " .. sav)
end
emu:reset()

-- ---------------------------------------------------------------- constants

local SPECIES_PIKACHU  = 25
-- Off-roster control. This was Meowth until 2026-07-24, when the roster sync
-- gave Red the Persian line (his researched rematch teams) and Meowth stopped
-- being off-roster for him. Choose controls by FAMILY BASE and re-check them
-- after any roster change: Poochyena is absent from Red, Falkner and Lance.
local SPECIES_POOCHYENA = 261
local ITEM_MASTER_BALL = 1

local B_OUTCOME_CAUGHT = 7

local MON_GIVEN_TO_PARTY = 0
local MON_GIVEN_TO_PC    = 1

local REQ_SET_CHARACTER = 1
local REQ_GIVE_ITEM     = 2
local REQ_SET_LAST_BALL = 3
local REQ_WILD_BATTLE   = 4
local REQ_GIVE_MON      = 5
local REQ_UNLOCK        = 6
local REQ_QUERY_BALL    = 7

local STATUS_DONE     = 1
local STATUS_REJECTED = 2

local MB           = H.anchors.gCharacterModeTestMailbox
local MB_MAGIC     = 0x434D5442  -- "CMTB", written by the pump once alive
local BALLBLOCK    = H.anchors.BattleScript_CharacterBallBlock
local BALLBLOCK_END = BALLBLOCK + 0x20  -- script is ~15 bytes; pad for safety

local DEADLINE = 60000  -- total frames (~33 s headless) before hard failure

-- ------------------------------------------------------------- mailbox pipe

local function mbRequest(req, a, b)
    H.wr16(MB + 6, a or 0)
    H.wr16(MB + 8, b or 0)
    H.wr32(MB + 12, 0)
    H.wr8(MB + 5, 0)      -- status = working
    H.wr8(MB + 4, req)    -- request last: the pump triggers on this
end

local function mbStatus() return H.rd8(MB + 5) end
local function mbResult() return H.rd32(MB + 12) end

-- --------------------------------------------------------------- game state

local function cb2()        return H.rd32(H.anchors.gMain + 4) end
local function onField()    return cb2() == H.anchors.CB2_Overworld + 1 end
local function inBattle()   return cb2() == H.anchors.BattleMainCB2 + 1 end
local function partyCount() return H.rd8(H.anchors.gPlayerPartyCount) end

-- ------------------------------------------------------------ state machine
--
-- Each step is {name, enter(f), tick(f) -> true when complete}. Input is
-- injected directly from tick() (per-frame), not via H.press queues, so a
-- step can key off live RAM instead of guessed frame counts.

local steps = {}
local stepIndex = 0
local stepStart = 0
local current = nil

local function addStep(name, enter, tick)
    table.insert(steps, { name = name, enter = enter, tick = tick })
end

local function mashEvery(f, key, every)
    -- one-frame taps, spaced out; mGBA latches keys per frame
    if (f % every) == 0 then emu:addKey(key) else emu:clearKey(key) end
end

-- Step helper: issue one mailbox request on entry, complete when done.
local function mbStep(name, req, a, b, onDone)
    addStep(name,
        function() mbRequest(req, a, b) end,
        function(f)
            local s = mbStatus()
            if s == STATUS_REJECTED then
                H.assertTrue(name .. " (mailbox rejected the request)", false)
                return true
            end
            if s == STATUS_DONE then
                if onDone then onDone() end
                return true
            end
            return false
        end)
end

-- ------------------------------------------------------------------- steps

-- 1. Continue into the overworld (mash A through copyright/title/main menu).
addStep("continue to overworld",
    nil,
    function(f)
        if onField() and H.rd32(MB) == MB_MAGIC then
            emu:clearKey(H.KEY.A)
            H.assertTrue("party count sane after Continue (1..6)",
                         partyCount() >= 1 and partyCount() <= 6)
            return true
        end
        if f - stepStart > 200 then mashEvery(f, H.KEY.A, 25) end
        return false
    end)

-- A stray A tap from the Continue mash can open the start menu or an NPC
-- dialogue right as the field appears; B-mash for a moment to close anything.
addStep("settle on the field",
    nil,
    function(f)
        if f - stepStart >= 240 then
            emu:clearKey(H.KEY.B)
            return true
        end
        mashEvery(f, H.KEY.B, 30)
        return false
    end)

mbStep("enter Character Mode as Red", REQ_SET_CHARACTER, 1, 0, function()
    H.assertEq("InCharacterMode() after SET_CHARACTER(1)", mbResult(), 1)
end)

mbStep("give 5 Master Balls", REQ_GIVE_ITEM, ITEM_MASTER_BALL, 5, function()
    H.assertEq("AddBagItem(Master Ball, 5)", mbResult(), 1)
end)

mbStep("set last-used ball = Master Ball", REQ_SET_LAST_BALL, ITEM_MASTER_BALL, 0)

mbStep("query quick-throw guard state", REQ_QUERY_BALL, ITEM_MASTER_BALL, 0, function()
    local r = mbResult()
    H.log(string.format("QUERY_BALL: lastUsedBall=%d canThrowLastUsedBall=%d bagHasMasterBall=%d",
                        math.floor(r / 65536), math.floor(r / 2) % 2, r % 2))
    H.assertEq("bag has the Master Ball", r % 2, 1)
    H.assertEq("lastUsedBall == Master Ball", math.floor(r / 65536), ITEM_MASTER_BALL)
end)

-- 2. Off-roster catch attempt: Poochyena, Master Ball -> must be BLOCKED.
local partyBeforePoochyena = 0
local sawBallBlock = false

addStep("snapshot party before Poochyena battle",
    nil,
    function()
        partyBeforePoochyena = partyCount()
        H.log("party count before Poochyena battle = " .. partyBeforePoochyena)
        return true
    end)

mbStep("start wild battle vs Poochyena", REQ_WILD_BATTLE, SPECIES_POOCHYENA, 10)

-- NB the battle intro in this hack waits on a keypress before reaching the
-- action menu (proven by breakpoint: R-only mashing never even CALLS
-- CanThrowLastUsedBall). B advances the intro text and is a no-op at the
-- action menu in singles, so interleave B (text) with R (quick throw).
addStep("throw at Poochyena, expect Character block",
    function() sawBallBlock = false end,
    function(f)
        if inBattle() then
            local instr = H.rd32(H.anchors.gBattlescriptCurrInstr)
            if instr >= BALLBLOCK and instr < BALLBLOCK_END then
                sawBallBlock = true
            end
            if not sawBallBlock then
                mashEvery(f, H.KEY.B, 37)
                mashEvery(f, H.KEY.R, 53)   -- quick-throw the Master Ball
            else
                emu:clearKey(H.KEY.R)
                emu:clearKey(H.KEY.B)
                return true
            end
        end
        if f - stepStart > 20000 then
            H.assertTrue("saw BattleScript_CharacterBallBlock vs Poochyena", false)
            return true
        end
        return false
    end)

addStep("escape the Poochyena battle",
    nil,
    function(f)
        if not inBattle() and onField() then
            emu:clearKey(H.KEY.B)
            local outcome = H.rd8(H.anchors.gBattleOutcome)
            H.assertTrue("saw BattleScript_CharacterBallBlock vs Poochyena", sawBallBlock)
            H.assertTrue("Poochyena battle did NOT end in a catch (outcome " ..
                         outcome .. ")", outcome ~= B_OUTCOME_CAUGHT)
            H.assertEq("party count unchanged after blocked throw",
                       partyCount(), partyBeforePoochyena)
            return true
        end
        -- Run: steer the action cursor to bottom-right (Run = 3) and confirm.
        -- All keys are cleared first so nothing stays latched across branches;
        -- the periodic B backs out of any stray submenu and advances text.
        if inBattle() then
            emu:clearKey(H.KEY.A)
            emu:clearKey(H.KEY.B)
            emu:clearKey(H.KEY.DOWN)
            emu:clearKey(H.KEY.RIGHT)
            local cursor = H.rd8(H.anchors.gActionSelectionCursor)
            local tick = f % 24
            if tick == 0 then
                if cursor == 3 then
                    emu:addKey(H.KEY.A)
                elseif cursor == 2 then
                    emu:addKey(H.KEY.RIGHT)
                else
                    emu:addKey(H.KEY.DOWN)
                end
            elseif tick == 12 then
                emu:addKey(H.KEY.B)
            end
        end
        if f - stepStart > 20000 then
            H.assertTrue("escaped the Poochyena battle before deadline", false)
            return true
        end
        return false
    end)

mbStep("unlock field after scripted battle 1", REQ_UNLOCK, 0, 0)

-- 3. On-roster catch: Pikachu, Master Ball -> must SUCCEED.
local partyBeforePikachu = 0

addStep("snapshot party before Pikachu battle",
    nil,
    function()
        partyBeforePikachu = partyCount()
        H.wr8(H.anchors.gBattleOutcome, 0)
        return true
    end)

mbStep("start wild battle vs Pikachu", REQ_WILD_BATTLE, SPECIES_PIKACHU, 10)

local pikachuThrown = false
addStep("throw at Pikachu, expect catch",
    function() pikachuThrown = false end,
    function(f)
        local outcome = H.rd8(H.anchors.gBattleOutcome)
        if inBattle() and outcome == 0 and not pikachuThrown then
            local instr = H.rd32(H.anchors.gBattlescriptCurrInstr)
            if instr >= BALLBLOCK and instr < BALLBLOCK_END then
                -- wrong: on-roster species must not be blocked
                H.assertTrue("Pikachu throw was NOT character-blocked", false)
                pikachuThrown = true
                return false
            end
            mashEvery(f, H.KEY.B, 37)   -- advance the intro text (see above)
            mashEvery(f, H.KEY.R, 53)
        elseif inBattle() and outcome ~= 0 then
            pikachuThrown = true
            emu:clearKey(H.KEY.R)
            mashEvery(f, H.KEY.B, 30)  -- decline nickname etc.
        elseif not inBattle() and onField() and pikachuThrown then
            emu:clearKey(H.KEY.B)
            return true
        end
        if f - stepStart > 20000 then
            H.assertTrue("Pikachu battle resolved before deadline", false)
            return true
        end
        return false
    end)

addStep("assert Pikachu was caught",
    nil,
    function()
        local outcome = H.rd8(H.anchors.gBattleOutcome)
        H.assertEq("Pikachu battle outcome == B_OUTCOME_CAUGHT",
                   outcome, B_OUTCOME_CAUGHT)
        if partyBeforePikachu < 6 then
            H.assertEq("caught Pikachu joined the party",
                       partyCount(), partyBeforePikachu + 1)
        else
            H.log("party was full; caught Pikachu went to the PC (not asserted)")
        end
        return true
    end)

mbStep("unlock field after scripted battle 2", REQ_UNLOCK, 0, 0)

-- 4. Gift gate: off-roster gift -> PC, on-roster gift -> party (if room).
local partyBeforeGifts = 0

addStep("snapshot party before gifts",
    nil,
    function()
        partyBeforeGifts = partyCount()
        return true
    end)

mbStep("gift an off-roster Poochyena", REQ_GIVE_MON, SPECIES_POOCHYENA, 10, function()
    H.assertEq("off-roster gift Poochyena routed to PC",
               mbResult(), MON_GIVEN_TO_PC)
    H.assertEq("party count unchanged by off-roster gift",
               partyCount(), partyBeforeGifts)
end)

mbStep("gift an on-roster Pikachu", REQ_GIVE_MON, SPECIES_PIKACHU, 10, function()
    if partyBeforeGifts < 6 then
        H.assertEq("on-roster gift Pikachu joined the party",
                   mbResult(), MON_GIVEN_TO_PARTY)
        H.assertEq("party count +1 after on-roster gift",
                   partyCount(), partyBeforeGifts + 1)
    else
        H.assertEq("on-roster gift went to PC (party full)",
                   mbResult(), MON_GIVEN_TO_PC)
    end
end)

-- -------------------------------------------------------------------- pump

local finished = false

H.onFrame(function(f)
    if finished then return end

    if f >= DEADLINE then
        finished = true
        H.assertTrue("finished all steps before global deadline (stuck at: " ..
                     (current and current.name or "?") .. ")", false)
        H.finish()
        return
    end

    if current == nil then
        stepIndex = stepIndex + 1
        current = steps[stepIndex]
        if current == nil then
            finished = true
            H.finish()
            return
        end
        stepStart = f
        H.log(string.format("STEP %d/%d: %s (frame %d)",
                            stepIndex, #steps, current.name, f))
        if current.enter then current.enter(f) end
    end

    if current.tick and current.tick(f) then
        current = nil
    end
end)
