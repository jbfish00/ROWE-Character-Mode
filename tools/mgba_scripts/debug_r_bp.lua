-- Diagnostic: is CanThrowLastUsedBall even CALLED when R is pressed at the
-- battle action menu? Arms breakpoints (requires MGBA_HEADLESS_DEBUGGER=1)
-- only once the battle has settled -- the core single-steps while armed.
--
--   MGBA_HEADLESS_DEBUGGER=1 CM_SAV=~/Documents/rowe_test_skills.sav \
--     timeout 240 <mgba-headless> --script tools/mgba_scripts/debug_r_bp.lua \
--     pokeemerald.gba

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

local CAN_THROW = 0x0809c71c
local TRY_HIDE  = 0x0809ca04

local stage = 0
local waitUntil = 0
local probeStart = 0
local canThrowCalls, tryHideCalls = 0, 0

H.onFrame(function(f)
    if stage == 0 then
        if onField() and H.rd32(MB) == 0x434D5442 then
            emu:clearKey(H.KEY.A); stage = 1; waitUntil = f + 240
        elseif f > 200 then
            if (f % 25) == 0 then emu:addKey(H.KEY.A) else emu:clearKey(H.KEY.A) end
        end
    elseif stage == 1 then
        if f >= waitUntil then mbRequest(1, 1, 0); stage = 2 end
    elseif stage == 2 then
        if mbIdle() then mbRequest(2, 1, 5); stage = 3 end
    elseif stage == 3 then
        if mbIdle() then mbRequest(3, 1, 0); stage = 4 end
    elseif stage == 4 then
        if mbIdle() then mbRequest(4, 52, 10); stage = 90 end
    elseif stage == 90 then
        if inBattle() then stage = 91; waitUntil = f + 600 end
    elseif stage == 91 then
        if f >= waitUntil then
            H.log("arming breakpoints at frame " .. f)
            H.breakpoint("CanThrowLastUsed", CAN_THROW, function()
                canThrowCalls = canThrowCalls + 1
            end)
            H.breakpoint("TryHideLastBall", TRY_HIDE, function()
                tryHideCalls = tryHideCalls + 1
            end)
            stage = 100
            probeStart = f
        end
    elseif stage == 100 then
        local rel = f - probeStart
        local phase = rel % 60
        if phase == 0 then emu:addKey(H.KEY.R)
        elseif phase == 8 then emu:clearKey(H.KEY.R) end
        if rel > 420 then
            H.log(string.format(
                "probe done: CanThrowLastUsedBall calls=%d TryHideLastUsedBall calls=%d outcome=%d instr=%08X",
                canThrowCalls, tryHideCalls, H.rd8(H.anchors.gBattleOutcome),
                H.rd32(H.anchors.gBattlescriptCurrInstr)))
            H.finish()
            stage = 999
        end
    end
end)
