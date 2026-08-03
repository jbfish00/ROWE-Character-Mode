-- Costume persistence across a save/reload — checklist item 26's missing half.
--
-- Item 26 is "save / reload → party intact and mode + costume persist". Party
-- and mode were covered (`continue_smoke`, `ot_roundtrip_e2e`); **the costume
-- was not**, and it is the one of the three stored in a var nobody else writes.
--
-- The two vars, and why both matter:
--   VAR_COSTUME_CHARACTER (17008) — 0 = wear the character you are PLAYING as,
--     1..N = wear character N, 0xFFFF = you explicitly picked a base outfit.
--     ⚠️ It reuses a free slot so SaveBlock1 did not grow, which is exactly the
--     kind of reuse that a later save-format change can silently reclaim.
--   VAR_COSTUME_NUMBER (0x409D) — the base outfit, clamped by GetCostume().
--
-- ⭐ THE CONTROL, and it is what makes this a test rather than a var round-trip.
-- A GBA reset re-runs the boot code, which zero-fills EWRAM — so a value that
-- survives a reset came out of FLASH, not out of RAM. The run therefore does
-- the same thing twice with the save removed from the middle:
--
--   1. set both vars, SAVE, reset, Continue  -> both read back the new values
--   2. set them to something else, do NOT save, reset, Continue
--                                            -> both read back the OLD values
--
-- Step 2 is the half that can fail. Without it, "the var still reads 7" passes
-- on a build where the reload silently never happened, where the var lives
-- somewhere that survives a reset, or where the write never landed and 7 was
-- already there.
--
--   CM_SAV=<fixture.sav> timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/costume_persist_e2e.lua pokeemerald.gba \
--     > /tmp/costume_persist_e2e.log 2>&1
--
-- ⚠️ THIS RUN WRITES TO ITS FIXTURE, unlike every other suite script. It has to:
-- proving something survives a save means saving. run_suite.sh mints a fresh
-- fixture per invocation, so that is safe there -- but never point CM_SAV at a
-- .sav you care about.

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

local CHARACTER_RED = 1

local VAR_COSTUME_CHARACTER = 17008
local VAR_COSTUME_NUMBER    = 0x409D

-- The values written in phase 1 and expected back after the reload. Both are
-- deliberately non-zero and different from each other: a swapped pair of var
-- ids would read back "the right values" if they matched.
local COSTUME_CHARACTER_SET = 7
local COSTUME_NUMBER_SET    = 2

-- Phase 2 writes these and never saves them. They must NOT come back.
local COSTUME_CHARACTER_UNSAVED = 21
local COSTUME_NUMBER_UNSAVED    = 3

local SAVE_STATUS_OK = 1

local REQ_SET_CHARACTER = H.anchors.REQ.SET_CHARACTER
local REQ_QUERY_VAR = H.anchors.REQ.QUERY_VAR
local REQ_QUERY_FLAG = H.anchors.REQ.QUERY_FLAG
local REQ_SET_VAR = H.anchors.REQ.SET_VAR
local REQ_SAVE = H.anchors.REQ.SAVE

if not REQ_SET_VAR then
    error("anchors.lua predates CM_REQ_SET_VAR -- re-run gen_anchors.py")
end

local FLAG_CHARACTER_MODE = 9135

local STATUS_DONE     = 1
local STATUS_REJECTED = 2

local MB       = H.anchors.gCharacterModeTestMailbox
local MB_MAGIC = 0x434D5442

local DEADLINE = 200000

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

local function cb2()       return H.rd32(H.anchors.gMain + 4) end
local function onField()   return cb2() == H.anchors.CB2_Overworld + 1 end
local function mbAlive()   return H.rd32(MB) == MB_MAGIC end

-- ------------------------------------------------------------ state machine

local steps = {}
local stepIndex = 0
local stepStart = 0
local current = nil

local function addStep(name, enter, tick)
    table.insert(steps, { name = name, enter = enter, tick = tick })
end

local function mashEvery(f, key, every)
    if (f % every) == 0 then emu:addKey(key) else emu:clearKey(key) end
end

local function mbStep(name, req, a, b, onDone, timeoutFrames)
    local limit = timeoutFrames or 4000
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
            if f - stepStart > limit then
                H.assertTrue(name .. " (mailbox answered)", false)
                return true
            end
            return false
        end)
end

local function reachField(label)
    addStep(label, nil, function(f)
        if onField() and mbAlive() then
            emu:clearKey(H.KEY.A)
            return true
        end
        if f - stepStart > 200 then mashEvery(f, H.KEY.A, 25) end
        if f - stepStart > 60000 then
            H.assertTrue(label .. " (reached the field)", false)
            return true
        end
        return false
    end)

    addStep(label .. " — settle", nil, function(f)
        if f - stepStart >= 240 then
            emu:clearKey(H.KEY.B)
            return true
        end
        mashEvery(f, H.KEY.B, 30)
        return false
    end)
end

-- ------------------------------------------------------------------- steps

reachField("continue to overworld (first boot)")

mbStep("enter Character Mode as Red", REQ_SET_CHARACTER, CHARACTER_RED, 0, function()
    H.assertEq("InCharacterMode() after SET_CHARACTER(1)", mbResult(), 1)
end)

-- --- phase 1: write, save, reload -------------------------------------------

mbStep("set VAR_COSTUME_CHARACTER", REQ_SET_VAR,
    VAR_COSTUME_CHARACTER, COSTUME_CHARACTER_SET, function()
        H.assertEq("VAR_COSTUME_CHARACTER took the write",
                   mbResult(), COSTUME_CHARACTER_SET)
    end)

mbStep("set VAR_COSTUME_NUMBER", REQ_SET_VAR,
    VAR_COSTUME_NUMBER, COSTUME_NUMBER_SET, function()
        H.assertEq("VAR_COSTUME_NUMBER took the write",
                   mbResult(), COSTUME_NUMBER_SET)
    end)

mbStep("save the game", REQ_SAVE, 0, 0, function()
    H.assertEq("TrySavingData(SAVE_NORMAL) reported OK", mbResult(), SAVE_STATUS_OK)
end)

addStep("reset the console (EWRAM is zero-filled at boot)", nil, function()
    emu:reset()
    return true
end)

reachField("continue to overworld (after the save)")

mbStep("VAR_COSTUME_CHARACTER survived the reload", REQ_QUERY_VAR,
    VAR_COSTUME_CHARACTER, 0, function()
        H.assertEq("VAR_COSTUME_CHARACTER after save+reset+continue",
                   mbResult(), COSTUME_CHARACTER_SET)
    end)

mbStep("VAR_COSTUME_NUMBER survived the reload", REQ_QUERY_VAR,
    VAR_COSTUME_NUMBER, 0, function()
        H.assertEq("VAR_COSTUME_NUMBER after save+reset+continue",
                   mbResult(), COSTUME_NUMBER_SET)
    end)

-- Item 26's other two thirds, re-asserted on the same reload so the three
-- travel together rather than being proved on three different saves.
mbStep("Character Mode itself survived the reload", REQ_QUERY_FLAG,
    FLAG_CHARACTER_MODE, 0, function()
        H.assertEq("FLAG_CHARACTER_MODE after save+reset+continue", mbResult(), 1)
    end)

addStep("party survived the reload", nil, function()
    H.assertTrue("party count sane after the reload (1..6)",
                 H.rd8(H.anchors.gPlayerPartyCount) >= 1
                 and H.rd8(H.anchors.gPlayerPartyCount) <= 6)
    return true
end)

-- --- phase 2: THE CONTROL — write, do NOT save, reload ----------------------

mbStep("overwrite VAR_COSTUME_CHARACTER without saving", REQ_SET_VAR,
    VAR_COSTUME_CHARACTER, COSTUME_CHARACTER_UNSAVED, function()
        H.assertEq("the unsaved write landed in RAM first",
                   mbResult(), COSTUME_CHARACTER_UNSAVED)
    end)

mbStep("overwrite VAR_COSTUME_NUMBER without saving", REQ_SET_VAR,
    VAR_COSTUME_NUMBER, COSTUME_NUMBER_UNSAVED, function()
        H.assertEq("the unsaved write landed in RAM first",
                   mbResult(), COSTUME_NUMBER_UNSAVED)
    end)

addStep("reset the console again, with nothing saved since", nil, function()
    emu:reset()
    return true
end)

reachField("continue to overworld (after the UNSAVED writes)")

mbStep("the unsaved costume character did NOT come back", REQ_QUERY_VAR,
    VAR_COSTUME_CHARACTER, 0, function()
        -- If this reads 21, the reload is not reloading: the run would have
        -- "proved" persistence on a build that never touched flash.
        H.assertEq("VAR_COSTUME_CHARACTER is the SAVED value, not the unsaved one",
                   mbResult(), COSTUME_CHARACTER_SET)
    end)

mbStep("the unsaved costume number did NOT come back", REQ_QUERY_VAR,
    VAR_COSTUME_NUMBER, 0, function()
        H.assertEq("VAR_COSTUME_NUMBER is the SAVED value, not the unsaved one",
                   mbResult(), COSTUME_NUMBER_SET)
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
