-- Starter-rule regression: drives a REAL new game from erased flash through
-- the intro (Birch speech, naming screen, truck questions menu) headlessly.
--
-- Two paths, selected by CM_PATH (default "red"):
--   red    -- questions menu -> Character Mode (index 2) -> START commits the
--             default pick (Gen I / Red). Asserts the starter is granted AT
--             COMMIT (party 0 -> 1), then that the intro's generic starter
--             menu was SKIPPED (party still exactly 1 in the overworld --
--             the historical double-starter bug gave Red a Meowth too),
--             and that slot 0 is Pikachu Lv10 with CM flag/var set.
--   normal -- questions menu -> Start Game (index 3, NOT 2: this fork
--             inserted Character Mode at 2, the documented index-drift trap)
--             -> generic starter menu case 0 -> Meowth Lv10, CM flag/var
--             clear, party exactly 1.
--
-- Menu navigation is closed-loop: gTestMenuPtr (src/menu.c) exposes sMenu,
-- so the driver reads the live multichoice cursor instead of counting blind
-- keypresses. After consuming a menu the driver poisons maxCursorPos so a
-- stale value can never satisfy the next wait.
--
-- Run (no CM_SAV -- erased flash IS the point, it boots into New Game):
--   CM_PATH=red timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/starter_regression.lua pokeemerald.gba \
--     > /tmp/starter_red.log 2>&1

local H = dofile("tools/mgba_scripts/harness.lua")

local path = os.getenv("CM_PATH") or "red"
if path ~= "red" and path ~= "normal" then
    error("CM_PATH must be 'red' or 'normal', got: " .. tostring(path))
end
H.log("PATH: " .. path)

-- ---------------------------------------------------------------- constants

local SPECIES_PIKACHU = 25
local SPECIES_MEOWTH  = 52

local FLAG_CHARACTER_MODE  = 9135
-- NOT the 0x860 the flags.h comment claims: this fork widened trainer flags
-- (MAX_TRAINERS_COUNT 2000), so SYSTEM_FLAGS = 0x500 + 2000 = 3280.
local FLAG_SYS_POKEMON_GET = 3280
local VAR_CHARACTER_ID     = 17001

local MAP_TRUCK_GROUP = 25   -- MAP_INSIDE_OF_TRUCK = (40 | (25 << 8))
local MAP_TRUCK_NUM   = 40

local QUESTIONS_MAX   = 3    -- MULTI_NEW_GAME_QUESTIONS: 4 rows, max cursor 3
local IDX_CHARACTER_MODE = 2
local IDX_START_GAME     = 3

-- Request ids come from anchors.lua (derived from the C enum by
-- gen_anchors.py); the enum is positional, so literals here rot
-- silently the moment a request is inserted rather than appended.
local REQ_QUERY_PARTY_MON = H.anchors.REQ.QUERY_PARTY_MON
local REQ_QUERY_FLAG = H.anchors.REQ.QUERY_FLAG
local REQ_QUERY_VAR = H.anchors.REQ.QUERY_VAR

local STATUS_DONE     = 1
local STATUS_REJECTED = 2

local MB       = H.anchors.gCharacterModeTestMailbox
local MB_MAGIC = 0x434D5442

local DEADLINE = 150000  -- ~85 s headless; the Birch intro is long

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
local function partyCount() return H.rd8(H.anchors.gPlayerPartyCount) end

-- SaveBlock1 starts with Coords16 pos (4 bytes) then WarpData location
-- (mapGroup s8 at +4, mapNum s8 at +5).
local function mapGroup() return H.rd8(H.rd32(H.anchors.gSaveBlock1Ptr) + 4) end
local function mapNum()   return H.rd8(H.rd32(H.anchors.gSaveBlock1Ptr) + 5) end
local function inTruck()
    return mapGroup() == MAP_TRUCK_GROUP and mapNum() == MAP_TRUCK_NUM
end

-- struct Menu (src/menu.c): +2 cursorPos (s8), +4 maxCursorPos (s8)
local function menuAddr()  return H.rd32(H.anchors.gTestMenuPtr) end
local function menuCur()   return H.rd8(menuAddr() + 2) end
local function menuMax()   return H.rd8(menuAddr() + 4) end
local function poisonMenu() H.wr8(menuAddr() + 4, 0x7F) end

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

local function heartbeat(f)
    if (f % 1000) == 0 then
        H.log(string.format(
            "hb f=%d cb2=%s field=%s map=%d/%d party=%d menu cur=%d max=%d",
            f, H.hex(cb2()), tostring(onField()), mapGroup(), mapNum(),
            partyCount(), menuCur(), menuMax()))
    end
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

-- Closed-loop multichoice pick: wait for the questions menu (maxCursorPos ==
-- QUESTIONS_MAX while in the truck), steer the cursor to `target`, press A,
-- then poison the stale cursor bounds. `doneFn` decides when the selection
-- visibly took (so a swallowed A retries rather than silently passing).
local function questionsPick(name, target, doneFn, timeout)
    local picked = false
    addStep(name,
        function() picked = false end,
        function(f)
            heartbeat(f)
            if picked and doneFn(f) then
                clearAll()
                return true
            end
            if f - stepStart > (timeout or 30000) then
                H.assertTrue(name .. " (completed before step timeout)", false)
                return true
            end
            local menuUp = inTruck() and menuMax() == QUESTIONS_MAX
            if not menuUp then
                -- still walking dialogue (or the selection is processing).
                -- A advances text; an occasional START finishes the naming
                -- screen (jumps to OK; inert in dialogue and multichoices).
                if not picked then
                    tapEvery(f, H.KEY.A, 29)
                    tapEvery(f, H.KEY.START, 173)
                end
                return false
            end
            emu:clearKey(H.KEY.START)
            if (f % 17) == 0 then
                local cur = menuCur()
                if cur < target then
                    emu:addKey(H.KEY.DOWN)
                elseif cur > target then
                    emu:addKey(H.KEY.UP)
                else
                    emu:addKey(H.KEY.A)
                    picked = true
                    -- poison AFTER the pick so wrap logic never saw it
                end
            else
                emu:clearKey(H.KEY.A)
                emu:clearKey(H.KEY.DOWN)
                emu:clearKey(H.KEY.UP)
                if picked then poisonMenu() end
            end
            return false
        end)
end

-- ------------------------------------------------------------------- steps

-- 1. Erased flash boots into New Game; mash A through copyright, title,
--    main menu, Birch speech, gender pick and the naming screen (A fills the
--    name buffer; START jumps the cursor to OK; A confirms), then through
--    the truck dialogue until the 4-entry questions menu is up.
--    An A landing the frame the menu opens picks index 0 (Game Level) --
--    harmless: mashing A through that submenu returns to the questions menu.

if path == "red" then
    -- 2. Pick Character Mode (index 2); done when the mode-menu UI owns CB2.
    questionsPick("pick Character Mode at questions index 2",
        IDX_CHARACTER_MODE,
        function() return not onField() end)

    -- 3. Commit the default (Gen I / Red) with START. The starter is granted
    --    inside the commit handler, so party 0 -> 1 IS the proof.
    addStep("START commits the mode menu; starter granted at commit",
        nil,
        function(f)
            heartbeat(f)
            if partyCount() == 1 then
                clearAll()
                H.log("commit grant seen at frame " .. f)
                return true
            end
            if f - stepStart > 20000 then
                H.assertTrue("mode-menu commit granted the roster starter", false)
                return true
            end
            if f - stepStart > 400 then  -- let the menu finish loading
                tapEvery(f, H.KEY.START, 47)
            end
            return false
        end)

    -- 4. Back at the questions menu, pick Start Game (index 3).
    questionsPick("pick Start Game at questions index 3 (after CM commit)",
        IDX_START_GAME,
        function()
            -- selection took once the script moves past the menu: the next
            -- interaction (difficulty text, clock, city pick) drops the
            -- poisoned bounds or leaves the truck entirely.
            return menuMax() ~= QUESTIONS_MAX or not inTruck()
        end)
else
    -- 2'. Straight to Start Game (index 3 -- the index-drift regression).
    questionsPick("pick Start Game at questions index 3",
        IDX_START_GAME,
        function()
            return menuMax() ~= QUESTIONS_MAX or not inTruck()
        end)
end

-- 5. Mash A through the rest of the intro: difficulty text, (normal path:
--    the generic starter menu -- A picks case 0 Meowth, A confirms the
--    yes/no), the clock, the follower question, and the city scroll-list
--    (A picks Littleroot, A confirms) -> warp.
--
--    THE CLOCK IS A TRAP for a naive A-mash: its "Is this the correct
--    time?" yes/no defaults to NO, so A forever cycles confirm-open ->
--    pick-NO. Closed loop instead: UP moves the yes/no cursor to YES, and
--    if repeated UPs don't move the (possibly stale) cursor we are in
--    adjust mode, so press A to open the confirm and try again.
local upTries = 0
addStep("reach the overworld outside the truck",
    nil,
    function(f)
        heartbeat(f)
        if not inTruck() and onField() and partyCount() >= 1
           and H.rd32(MB) == MB_MAGIC then
            clearAll()
            H.log("overworld reached at frame " .. f ..
                  " map " .. mapGroup() .. "/" .. mapNum())
            return true
        end
        if f - stepStart > 40000 then
            H.assertTrue("reached the overworld before step timeout", false)
            return true
        end
        -- CB2_WallClock itself is static (not in the map); every wallclock
        -- CB2 lives within ~0x800 bytes of the exported CB2_StartWallClock.
        if cb2() >= H.anchors.CB2_StartWallClock
           and cb2() < H.anchors.CB2_StartWallClock + 0x800 then
            emu:clearKey(H.KEY.A)
            emu:clearKey(H.KEY.UP)
            if (f % 21) == 0 then
                if menuCur() == 0 then
                    emu:addKey(H.KEY.A)       -- cursor on YES: confirm
                elseif upTries < 3 then
                    emu:addKey(H.KEY.UP)      -- move yes/no cursor to YES
                    upTries = upTries + 1
                else
                    emu:addKey(H.KEY.A)       -- stale cursor: open the confirm
                    upTries = 0
                end
            end
            return false
        end
        emu:clearKey(H.KEY.UP)
        tapEvery(f, H.KEY.A, 31)
        return false
    end)

-- 6. A stray A from the mash can open a menu or dialogue; B it closed.
addStep("settle on the field",
    nil,
    function(f)
        if f - stepStart >= 300 then
            clearAll()
            return true
        end
        tapEvery(f, H.KEY.B, 30)
        return false
    end)

-- 7. Final asserts via the mailbox (pumped by CB2_Overworld).

addStep("assert party size (the double-starter regression)",
    nil,
    function()
        H.assertEq("party count is exactly 1", partyCount(), 1)
        return true
    end)

if path == "red" then
    mbStep("query CM flag", REQ_QUERY_FLAG, FLAG_CHARACTER_MODE, 0, function()
        H.assertEq("FLAG_CHARACTER_MODE set", mbResult(), 1)
    end)
    mbStep("query character id", REQ_QUERY_VAR, VAR_CHARACTER_ID, 0, function()
        H.assertEq("VAR_CHARACTER_ID == 1 (Red)", mbResult(), 1)
    end)
    mbStep("query party slot 0", REQ_QUERY_PARTY_MON, 0, 0, function()
        local r = mbResult()
        H.assertEq("slot 0 species is Pikachu (Red roster[0])",
                   r % 65536, SPECIES_PIKACHU)
        H.assertEq("slot 0 level is 10", math.floor(r / 65536), 10)
    end)
else
    mbStep("query CM flag", REQ_QUERY_FLAG, FLAG_CHARACTER_MODE, 0, function()
        H.assertEq("FLAG_CHARACTER_MODE clear", mbResult(), 0)
    end)
    mbStep("query character id", REQ_QUERY_VAR, VAR_CHARACTER_ID, 0, function()
        H.assertEq("VAR_CHARACTER_ID == 0", mbResult(), 0)
    end)
    mbStep("query party slot 0", REQ_QUERY_PARTY_MON, 0, 0, function()
        local r = mbResult()
        H.assertEq("slot 0 species is Meowth (generic starter 1)",
                   r % 65536, SPECIES_MEOWTH)
        H.assertEq("slot 0 level is 10", math.floor(r / 65536), 10)
    end)
end

mbStep("query FLAG_SYS_POKEMON_GET", REQ_QUERY_FLAG, FLAG_SYS_POKEMON_GET, 0,
    function()
        H.assertEq("FLAG_SYS_POKEMON_GET set", mbResult(), 1)
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
