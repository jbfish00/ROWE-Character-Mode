-- Diagnostic: does a scripted R press reach the game in battle?
-- Drives the same path as catch_gate_e2e up to the Meowth battle, then
-- presses R with varying hold lengths and logs what gMain.newKeys/heldKeys
-- actually contain, plus the action cursor and battlescript pointer.
--
--   CM_SAV=~/Documents/rowe_test_skills.sav timeout 120 <mgba-headless> \
--     --script tools/mgba_scripts/debug_r_input.lua pokeemerald.gba

local H = dofile("tools/mgba_scripts/harness.lua")

local sav = os.getenv("CM_SAV")
if not sav then error("set CM_SAV") end
if not emu:loadSaveFile(sav, false) then error("loadSaveFile failed") end
emu:reset()

local MB = H.anchors.gCharacterModeTestMailbox
local function mbRequest(req, a, b)
    H.wr16(MB + 6, a or 0); H.wr16(MB + 8, b or 0)
    H.wr32(MB + 12, 0); H.wr8(MB + 5, 0); H.wr8(MB + 4, req)
end
local function mbIdle() return H.rd8(MB + 5) ~= 0 end

local function cb2() return H.rd32(H.anchors.gMain + 4) end
local function onField() return cb2() == H.anchors.CB2_Overworld + 1 end
local function inBattle() return cb2() == H.anchors.BattleMainCB2 + 1 end

local NEWKEYS  = H.anchors.gMain + 0x2E
local HELDKEYS = H.anchors.gMain + 0x2C

local stage = 0        -- 0 boot, 1..n mailbox setup, 90 battle-wait, 100 probing
local waitUntil = 0
local probeStart = 0
local rHeld = false
local logsLeft = 40

H.onFrame(function(f)
    if stage == 0 then
        if onField() and H.rd32(MB) == 0x434D5442 then
            emu:clearKey(H.KEY.A)
            stage = 1
            waitUntil = f + 240
        elseif f > 200 then
            if (f % 25) == 0 then emu:addKey(H.KEY.A) else emu:clearKey(H.KEY.A) end
        end
    elseif stage == 1 then
        if f >= waitUntil then mbRequest(1, 1, 0); stage = 2 end   -- SET_CHARACTER Red
    elseif stage == 2 then
        if mbIdle() then mbRequest(2, 1, 5); stage = 3 end         -- GIVE_ITEM master x5
    elseif stage == 3 then
        if mbIdle() then mbRequest(3, 1, 0); stage = 4 end         -- SET_LAST_BALL
    elseif stage == 4 then
        if mbIdle() then mbRequest(4, 52, 10); stage = 90 end      -- WILD_BATTLE Meowth
    elseif stage == 90 then
        if inBattle() then
            H.log("in battle at frame " .. f)
            stage = 95
            waitUntil = f + 600
        end
    elseif stage == 95 then
        -- battle intro should be done; ask the pump (now also wired into
        -- BattleMainCB2) what the quick-throw guard sees from IN the battle
        if f >= waitUntil then mbRequest(7, 1, 0); stage = 96 end
    elseif stage == 96 then
        if mbIdle() then
            local r = H.rd32(MB + 12)
            H.log(string.format(
                "IN-BATTLE QUERY: lastUsedBall=%d canThrowLastUsedBall=%d bagHasMasterBall=%d",
                math.floor(r / 65536), math.floor(r / 2) % 2, r % 2))
            stage = 100
            probeStart = f
        end
    elseif stage == 100 then
        if f < probeStart then return end
        local rel = f - probeStart
        -- hold R for 8 frames out of every 60
        local phase = rel % 60
        if phase == 0 then emu:addKey(H.KEY.R); rHeld = true
        elseif phase == 8 then emu:clearKey(H.KEY.R); rHeld = false end

        if logsLeft > 0 and (phase <= 9 or (rel % 240) == 30) then
            H.log(string.format(
                "f=%d phase=%d rHeld=%s newKeys=%04X heldKeys=%04X cursor=%d instr=%08X",
                f, phase, tostring(rHeld), H.rd16(NEWKEYS), H.rd16(HELDKEYS),
                H.rd8(H.anchors.gActionSelectionCursor),
                H.rd32(H.anchors.gBattlescriptCurrInstr)))
            logsLeft = logsLeft - 1
        end
        if logsLeft == 0 or rel > 3000 then
            H.log("probe done; outcome=" .. H.rd8(H.anchors.gBattleOutcome))
            H.finish()
            logsLeft = -1
        end
    end
end)
