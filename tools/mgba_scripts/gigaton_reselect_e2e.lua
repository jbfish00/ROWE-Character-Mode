-- Gigaton Hammer re-selection e2e: proves the no-twice-in-a-row SELECTION
-- gate (TrySetCantSelectMoveBattleScript) at memory level, closing the
-- Phase 6 "Gigaton Hammer re-selection UI check" without needing eyes:
--   turn 1: Gigaton Hammer selectable and executes
--            (gBattleResults.lastUsedMovePlayer == 757)
--   turn 2: re-picking it is REJECTED -- gSelectionBattleScripts[0] is set
--            to BattleScript_SelectingTormentedMove (zeroed by the harness
--            before each attempt, so the read is a fresh edge) -- and the
--            fallback Tackle executes instead
--   turn 3: Gigaton Hammer selectable again (lock is exactly one turn)
--
-- NB Gigaton Hammer / Blood Moon are currently in NO learnset/TM/tutor/
-- script, so normal play cannot reach this gate today; this proves the
-- mechanism for whenever a port adds an acquisition path.
--
-- Setup: Continue from CM_SAV, overwrite the lead's move 0 with Gigaton
-- Hammer and move 1 with Tackle (CM_REQ_SET_MON_MOVE), then a scripted
-- wild Magikarp Lv5 (knows only Splash -- zero threat) whose battle HP is
-- refilled every frame so nothing can end the battle early.
--
-- Run. CM_SAV must be a fixture in the CURRENT save format -- saves written
-- before the 12-character-name change are refused by design. Regenerate with
-- tools/mgba_scripts/make_fixture_save.lua (see continue_smoke.lua's header).
--   CM_SAV=~/Documents/rowe_fixture.sav timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/gigaton_reselect_e2e.lua pokeemerald.gba \
--     > /tmp/gigaton.log 2>&1

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

local MOVE_GIGATON_HAMMER = 757
local MOVE_TACKLE         = 33
local SPECIES_MAGIKARP    = 129

local REQ_SET_CHARACTER = 1
local REQ_WILD_BATTLE   = 4
local REQ_UNLOCK        = 6
local REQ_SET_MON_HP    = 12
local REQ_SET_MON_MOVE  = 14

local STATUS_DONE     = 1
local STATUS_REJECTED = 2

local MB       = H.anchors.gCharacterModeTestMailbox
local MB_MAGIC = 0x434D5442

-- Struct offsets come from the compiler via H.off (the gTestStructOffsets
-- beacon), NEVER from literals. The literals that used to live here --
-- BattlePokemon 0x5C / hp 0x2A / maxHP 0x2E, BattleResults turn 0x13 /
-- lastMove 0x22 -- were correct when probed and silently wrong afterwards:
-- POKEMON_NAME_LENGTH 10 -> 12 grew playerMon1Name inside BattleResults and
-- pushed turn to 0x15 and lastMove to 0x26. This test then read a turn counter
-- that never moved, concluded the Gigaton Hammer gate was broken, and that was
-- recorded as a release blocker while the ROM was behaving correctly.
local BMON_SIZE   = H.off.battleMon_size
local BMON_MOVES  = H.off.battleMon_moves
local BMON_HP     = H.off.battleMon_hp
local BMON_MAXHP  = H.off.battleMon_maxHP

local BRES_TURNS    = H.off.battleResults_turnCounter
local BRES_LASTMOVE = H.off.battleResults_lastUsedMovePlayer

if not (BMON_SIZE and BRES_TURNS and BRES_LASTMOVE) then
    error("struct offsets missing -- re-run tools/mgba_scripts/gen_anchors.py")
end
H.log(string.format("offsets: bmon=%d hp=%d maxHP=%d moves=%d turn=%d lastMove=%d",
                    BMON_SIZE, BMON_HP, BMON_MAXHP, BMON_MOVES,
                    BRES_TURNS, BRES_LASTMOVE))

local TORMENT_SCRIPT = H.anchors.BattleScript_SelectingTormentedMove

local DEADLINE = 100000

-- ------------------------------------------------------------- mailbox pipe

local function mbRequest(req, a, b)
    H.wr16(MB + 6, a or 0)
    H.wr16(MB + 8, b or 0)
    H.wr32(MB + 12, 0)
    H.wr8(MB + 5, 0)
    H.wr8(MB + 4, req)
end

local function mbStatus() return H.rd8(MB + 5) end
local function mbResult() return H.rd32(MB + 12) end

-- --------------------------------------------------------------- game state

local function cb2()        return H.rd32(H.anchors.gMain + 4) end
local function onField()    return cb2() == H.anchors.CB2_Overworld + 1 end
local function inBattle()   return cb2() == H.anchors.BattleMainCB2 + 1 end
local function partyCount() return H.rd8(H.anchors.gPlayerPartyCount) end

local function turnCount()  return H.rd8(H.anchors.gBattleResults + BRES_TURNS) end
local function lastMove()   return H.rd16(H.anchors.gBattleResults + BRES_LASTMOVE) end
local function actionCur()  return H.rd8(H.anchors.gActionSelectionCursor) end
local function moveCur()    return H.rd8(H.anchors.gMoveSelectionCursor) end
local function selScript()  return H.rd32(H.anchors.gSelectionBattleScripts) end

-- The stored pointer is the selection script's CURRENT instruction, so it
-- advances as the script runs (observed: the label, then label+3 one frame
-- later). An exact-equality test therefore has a one-or-two frame window and
-- loses the race whenever the poll misses it. Accept the whole script body.
local function inTormentScript()
    local s = selScript()
    return s >= TORMENT_SCRIPT and s < TORMENT_SCRIPT + 0x20
end

local function refillEnemyHp()
    if inBattle() then
        local base = H.anchors.gBattleMons + BMON_SIZE  -- battler 1 = enemy
        local max = H.rd16(base + BMON_MAXHP)
        if max > 0 then H.wr16(base + BMON_HP, max) end
    end
end

-- ------------------------------------------------------------ state machine

local steps = {}
local stepIndex = 0
local stepStart = 0
local current = nil

local function addStep(name, enter, tick)
    table.insert(steps, { name = name, enter = enter, tick = tick })
end

local function tapEvery(f, key, every, phase)
    if (f % every) == (phase or 0) then emu:addKey(key) else emu:clearKey(key) end
end

local function clearAll()
    for _, k in pairs(H.KEY) do emu:clearKey(k) end
end

local function mashEvery(f, key, every)
    if (f % every) == 0 then emu:addKey(key) else emu:clearKey(key) end
end

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
            if f - stepStart > 2000 then
                H.assertTrue(name .. " (mailbox answered)", false)
                return true
            end
            return false
        end)
end

-- ------------------------------------------------------------------- steps

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

mbStep("character mode off", REQ_SET_CHARACTER, 0, 0)

mbStep("lead move 0 = Gigaton Hammer", REQ_SET_MON_MOVE,
    0 | (0 * 256), MOVE_GIGATON_HAMMER, function()
        H.assertEq("move 0 written", mbResult(), MOVE_GIGATON_HAMMER)
    end)

mbStep("lead move 1 = Tackle", REQ_SET_MON_MOVE,
    0 | (1 * 256), MOVE_TACKLE, function()
        H.assertEq("move 1 written", mbResult(), MOVE_TACKLE)
    end)

mbStep("lead hp = 10 (alive)", REQ_SET_MON_HP, 0, 10, function()
    H.assertEq("lead hp set", mbResult(), 10)
end)

mbStep("start wild battle vs Splash-only Magikarp", REQ_WILD_BATTLE,
    SPECIES_MAGIKARP, 5)

-- The three-turn selection drive. Which menu is LIVE is read from the
-- player controller's input-handler function pointer
-- (gBattlerControllerFuncs[0] == HandleInputChooseAction / ChooseMove --
-- statics, resolved via the gen_anchors nm fallback). Everything else
-- (messages, animations, the rejection text) gets a B tap. The enemy's HP
-- is refilled every frame, so only our selections advance the battle.

local CHOOSE_MOVE = H.anchors.HandleInputChooseMove + 1
local CHOOSE_ACT1 = H.anchors.HandleInputChooseAction + 1
local CHOOSE_ACT2 = (H.anchors.HandleInputChooseAction_2 or 0) + 1

local function ctrlFunc() return H.rd32(H.anchors.gBattlerControllerFuncs) end
local function atMoveMenu() return ctrlFunc() == CHOOSE_MOVE end
local function atActionMenu()
    local c = ctrlFunc()
    return c == CHOOSE_ACT1 or c == CHOOSE_ACT2
end

local phase = "enter"       -- enter -> t1 -> t2a (GH rejected) -> t2b
                            -- (Tackle) -> t3 -> done
local baseTurn = 0
local sawReject = false

addStep("three-turn Gigaton Hammer selection contract",
    function()
        phase = "enter"; sawReject = false
    end,
    function(f)
        refillEnemyHp()
        if (f % 2000) == 0 then
            H.log(string.format(
                "dbg f=%d phase=%s turn=%d last=%d act=%d mov=%d cf=%s sel=%s",
                f, phase, turnCount(), lastMove(), actionCur(), moveCur(),
                H.hex(ctrlFunc()), H.hex(selScript())))
        end
        if f - stepStart > 80000 then
            H.assertTrue("selection contract finished (stuck at " ..
                         phase .. ")", false)
            return true
        end
        if not inBattle() then
            if phase ~= "enter" then
                H.assertTrue("battle survived the three-turn contract", false)
                return true
            end
            mashEvery(f, H.KEY.B, 37)
            return false
        end
        if phase == "enter" then
            emu:clearKey(H.KEY.B)
            phase = "t1"
            baseTurn = turnCount()
            H.log(string.format("battle entered; turn counter base=%d", baseTurn))
            return false
        end

        -- phase transitions (checked every frame)
        if phase == "t2a" and inTormentScript() then
            H.assertTrue("turn 2: Gigaton re-pick rejected with " ..
                         "BattleScript_SelectingTormentedMove", true)
            sawReject = true
            phase = "t2b"
        end
        if turnCount() ~= baseTurn then
            baseTurn = turnCount()
            if phase == "t1" then
                H.assertEq("turn 1: Gigaton Hammer executed",
                           lastMove(), MOVE_GIGATON_HAMMER)
                phase = "t2a"
            elseif phase == "t2a" then
                H.assertTrue("turn 2: Gigaton re-pick was blocked " ..
                             "(move executed instead: " .. lastMove() .. ")",
                             false)
                return true
            elseif phase == "t2b" then
                H.assertEq("turn 2: fallback Tackle executed",
                           lastMove(), MOVE_TACKLE)
                phase = "t3"
            elseif phase == "t3" then
                H.assertEq("turn 3: Gigaton Hammer selectable again",
                           lastMove(), MOVE_GIGATON_HAMMER)
                H.assertTrue("saw the turn-2 rejection", sawReject)
                clearAll()
                return true
            end
        end

        -- input (one tap slot every 23 frames)
        if (f % 23) ~= 0 then
            clearAll()
            return false
        end
        if atActionMenu() then
            local cur = actionCur()
            if cur == 0 then emu:addKey(H.KEY.A)
            elseif cur == 1 then emu:addKey(H.KEY.LEFT)
            else emu:addKey(H.KEY.UP) end
        elseif atMoveMenu() then
            -- fresh edge for the rejection detector before every pick
            H.wr32(H.anchors.gSelectionBattleScripts, 0)
            local target = (phase == "t2b") and 1 or 0
            local cur = moveCur()
            if cur == target then emu:addKey(H.KEY.A)
            elseif (cur % 2) ~= (target % 2) then
                if (target % 2) == 1 then emu:addKey(H.KEY.RIGHT)
                else emu:addKey(H.KEY.LEFT) end
            elseif cur > target then emu:addKey(H.KEY.UP)
            else emu:addKey(H.KEY.DOWN) end
        else
            emu:addKey(H.KEY.B)  -- messages, anims, the rejection text
        end
        return false
    end)

mbStep("unlock the field", REQ_UNLOCK, 0, 0)

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
