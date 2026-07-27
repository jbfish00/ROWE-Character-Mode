-- Shared headless intro drive + step machine.
--
-- starter_regression.lua grew a REAL new-game drive (erased flash -> Birch
-- speech -> naming screen -> truck questions menu -> Character Mode commit ->
-- clock -> city pick -> overworld) and a small step state machine. Both are
-- reusable, and copying them into every new test is how drives drift apart.
-- This module is that code, extracted verbatim in behaviour.
--
-- starter_regression.lua is deliberately NOT converted to use this: it is the
-- regression gate for the intro itself, so it keeps its own copy and the two
-- can be diffed against each other if a drive ever breaks.
--
--   local H = dofile("tools/mgba_scripts/harness.lua")
--   local D = dofile("tools/mgba_scripts/intro_drive.lua")(H)
--   D.driveNewGameCharacterMode()      -- queues steps up to "on the field"
--   D.mbStep("query x", D.REQ.QUERY_FLAG, 123, 0, function() ... end)
--   D.run()                            -- installs the frame pump
--
-- Everything below is frame-bounded: the harness runs ~1800 fps and nothing
-- here may wait on an event that can silently never arrive.

return function(H)

local D = {}

-- ---------------------------------------------------------------- constants

D.FLAG_CHARACTER_MODE  = 9135
-- NOT the 0x860 the flags.h comment claims: this fork widened trainer flags
-- (MAX_TRAINERS_COUNT 2000), so SYSTEM_FLAGS = 0x500 + 2000 = 3280.
D.FLAG_SYS_POKEMON_GET = 3280
D.VAR_CHARACTER_ID     = 17001

D.MAP_TRUCK_GROUP = 25   -- MAP_INSIDE_OF_TRUCK = (40 | (25 << 8))
D.MAP_TRUCK_NUM   = 40

D.QUESTIONS_MAX      = 3  -- MULTI_NEW_GAME_QUESTIONS: 4 rows, max cursor 3
D.IDX_CHARACTER_MODE = 2
D.IDX_START_GAME     = 3

-- Mailbox request ids, DERIVED from the enum in src/character_mode_selftest.c
-- by gen_anchors.py. They used to be mirrored by hand here, and the enum is
-- positional -- so adding a request in the middle silently renumbered every
-- later one and a passing test carried on asking for something else. That
-- happened four times in one session before this was automated. If D.REQ is
-- missing an id you just added, re-run gen_anchors.py.
D.REQ = H.anchors.REQ or {}
if not D.REQ.SET_CHARACTER then
    error("anchors.lua has no REQ table -- re-run tools/mgba_scripts/gen_anchors.py")
end

D.STATUS_DONE     = 1
D.STATUS_REJECTED = 2

D.MB       = H.anchors.gCharacterModeTestMailbox
D.MB_MAGIC = 0x434D5442

D.DEADLINE = 150000  -- ~85 s headless; the Birch intro is long

-- ------------------------------------------------------------- mailbox pipe

function D.mbRequest(req, a, b)
    H.wr16(D.MB + 6, a or 0)
    H.wr16(D.MB + 8, b or 0)
    H.wr32(D.MB + 12, 0)
    H.wr8(D.MB + 5, 0)
    H.wr8(D.MB + 4, req)
end

function D.mbStatus() return H.rd8(D.MB + 5) end
function D.mbResult() return H.rd32(D.MB + 12) end
function D.mbAlive()  return H.rd32(D.MB) == D.MB_MAGIC end

-- --------------------------------------------------------------- game state

function D.cb2()        return H.rd32(H.anchors.gMain + 4) end
function D.onField()    return D.cb2() == H.anchors.CB2_Overworld + 1 end
function D.partyCount() return H.rd8(H.anchors.gPlayerPartyCount) end

-- SaveBlock1 starts with Coords16 pos (4 bytes) then WarpData location
-- (mapGroup s8 at +4, mapNum s8 at +5).
function D.mapGroup() return H.rd8(H.rd32(H.anchors.gSaveBlock1Ptr) + 4) end
function D.mapNum()   return H.rd8(H.rd32(H.anchors.gSaveBlock1Ptr) + 5) end
function D.inTruck()
    return D.mapGroup() == D.MAP_TRUCK_GROUP and D.mapNum() == D.MAP_TRUCK_NUM
end

-- struct Menu (src/menu.c): +2 cursorPos (s8), +4 maxCursorPos (s8)
function D.menuAddr()  return H.rd32(H.anchors.gTestMenuPtr) end
function D.menuCur()   return H.rd8(D.menuAddr() + 2) end
function D.menuMax()   return H.rd8(D.menuAddr() + 4) end
function D.poisonMenu() H.wr8(D.menuAddr() + 4, 0x7F) end

-- ------------------------------------------------------------ step machine

local steps = {}
local stepIndex = 0
local stepStart = 0
local current = nil

function D.addStep(name, enter, tick)
    table.insert(steps, { name = name, enter = enter, tick = tick })
end

function D.stepStart() return stepStart end

function D.tapEvery(f, key, every, phase)
    if (f % every) == (phase or 0) then emu:addKey(key) else emu:clearKey(key) end
end

function D.clearAll()
    for _, k in pairs(H.KEY) do emu:clearKey(k) end
end

function D.heartbeat(f)
    if (f % 1000) == 0 then
        H.log(string.format(
            "hb f=%d cb2=%s field=%s map=%d/%d party=%d menu cur=%d max=%d",
            f, H.hex(D.cb2()), tostring(D.onField()), D.mapGroup(), D.mapNum(),
            D.partyCount(), D.menuCur(), D.menuMax()))
    end
end

-- A mailbox round trip as a step. Fails loudly on rejection or no answer --
-- a silently-unanswered request must never read as a pass.
-- `timeoutFrames` defaults to 2000. Raise it for a request that does real work
-- in the pump: the pump runs the whole request inside one call, but the GBA's
-- VBlank keeps firing regardless, so frames DO advance while it computes and a
-- long request trips the deadline while still perfectly healthy. A 4000-trial
-- wild-roll loop needs well over 2000 frames.
function D.mbStep(name, req, a, b, onDone, timeoutFrames)
    local limit = timeoutFrames or 2000
    D.addStep(name,
        function() D.mbRequest(req, a, b) end,
        function(f)
            local s = D.mbStatus()
            if s == D.STATUS_REJECTED then
                H.assertTrue(name .. " (mailbox rejected the request)", false)
                return true
            end
            if s == D.STATUS_DONE then
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

-- Wait an explicit number of frames. Used where an effect is asynchronous
-- (flash writes) and there is no flag to watch.
function D.waitFrames(name, n)
    D.addStep(name, nil, function(f)
        if f - stepStart >= n then return true end
        return false
    end)
end

-- Closed-loop multichoice pick: wait for the questions menu, steer the cursor
-- to `target`, press A, then poison the stale cursor bounds. `doneFn` decides
-- when the selection visibly took, so a swallowed A retries rather than
-- silently passing.
function D.questionsPick(name, target, doneFn, timeout)
    local picked = false
    D.addStep(name,
        function() picked = false end,
        function(f)
            D.heartbeat(f)
            if picked and doneFn(f) then
                D.clearAll()
                return true
            end
            if f - stepStart > (timeout or 30000) then
                H.assertTrue(name .. " (completed before step timeout)", false)
                return true
            end
            local menuUp = D.inTruck() and D.menuMax() == D.QUESTIONS_MAX
            if not menuUp then
                -- still walking dialogue (or the selection is processing).
                -- A advances text; an occasional START finishes the naming
                -- screen (jumps to OK; inert in dialogue and multichoices).
                if not picked then
                    D.tapEvery(f, H.KEY.A, 29)
                    D.tapEvery(f, H.KEY.START, 173)
                end
                return false
            end
            emu:clearKey(H.KEY.START)
            if (f % 17) == 0 then
                local cur = D.menuCur()
                if cur < target then
                    emu:addKey(H.KEY.DOWN)
                elseif cur > target then
                    emu:addKey(H.KEY.UP)
                else
                    emu:addKey(H.KEY.A)
                    picked = true
                end
            else
                emu:clearKey(H.KEY.A)
                emu:clearKey(H.KEY.DOWN)
                emu:clearKey(H.KEY.UP)
                if picked then D.poisonMenu() end
            end
            return false
        end)
end

-- ------------------------------------------------------------- the drive

-- Queues every step from erased flash to standing on the field in Character
-- Mode as the default Gen I / Red pick, with exactly one party Pokemon.
--
-- The naming screen is where a 12-character player name comes from: A fills
-- the name buffer to PLAYER_NAME_LENGTH with the cursor's letter, so after the
-- change this drive produces a MAXIMUM-length name -- which is precisely the
-- input the OT round-trip test needs, and the input a 7-character build could
-- never produce.
function D.driveNewGameCharacterMode()
    D.questionsPick("pick Character Mode at questions index 2",
        D.IDX_CHARACTER_MODE,
        function() return not D.onField() end)

    D.addStep("START commits the mode menu; starter granted at commit",
        nil,
        function(f)
            D.heartbeat(f)
            if D.partyCount() == 1 then
                D.clearAll()
                H.log("commit grant seen at frame " .. f)
                return true
            end
            if f - stepStart > 20000 then
                H.assertTrue("mode-menu commit granted the roster starter", false)
                return true
            end
            if f - stepStart > 400 then  -- let the menu finish loading
                D.tapEvery(f, H.KEY.START, 47)
            end
            return false
        end)

    D.questionsPick("pick Start Game at questions index 3 (after CM commit)",
        D.IDX_START_GAME,
        function()
            return D.menuMax() ~= D.QUESTIONS_MAX or not D.inTruck()
        end)

    -- THE CLOCK IS A TRAP for a naive A-mash: its "Is this the correct time?"
    -- yes/no defaults to NO, so A forever cycles confirm-open -> pick-NO.
    -- Closed loop instead: UP moves the cursor to YES; if repeated UPs don't
    -- move the (possibly stale) cursor we are in adjust mode, so press A.
    local upTries = 0
    D.addStep("reach the overworld outside the truck",
        nil,
        function(f)
            D.heartbeat(f)
            if not D.inTruck() and D.onField() and D.partyCount() >= 1
               and D.mbAlive() then
                D.clearAll()
                H.log("overworld reached at frame " .. f ..
                      " map " .. D.mapGroup() .. "/" .. D.mapNum())
                return true
            end
            if f - stepStart > 40000 then
                H.assertTrue("reached the overworld before step timeout", false)
                return true
            end
            if D.cb2() >= H.anchors.CB2_StartWallClock
               and D.cb2() < H.anchors.CB2_StartWallClock + 0x800 then
                emu:clearKey(H.KEY.A)
                emu:clearKey(H.KEY.UP)
                if (f % 21) == 0 then
                    if D.menuCur() == 0 then
                        emu:addKey(H.KEY.A)       -- cursor on YES: confirm
                    elseif upTries < 3 then
                        emu:addKey(H.KEY.UP)
                        upTries = upTries + 1
                    else
                        emu:addKey(H.KEY.A)       -- stale cursor: open confirm
                        upTries = 0
                    end
                end
                return false
            end
            emu:clearKey(H.KEY.UP)
            D.tapEvery(f, H.KEY.A, 31)
            return false
        end)

    -- A stray A from the mash can open a menu or dialogue; B it closed.
    D.addStep("settle on the field",
        nil,
        function(f)
            if f - stepStart >= 300 then
                D.clearAll()
                return true
            end
            D.tapEvery(f, H.KEY.B, 30)
            return false
        end)
end

-- -------------------------------------------------------------------- pump

function D.run()
    local finished = false

    H.onFrame(function(f)
        if finished then return end

        if f >= D.DEADLINE then
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
end

return D

end
