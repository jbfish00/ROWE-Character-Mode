-- PC-withdraw sweep e2e (belt-and-braces Phase 6 item): drives
-- CharacterMode_SweepPartyToPC() -- the exact call Cb2_ExitPSS makes when
-- the player leaves the storage UI -- against real party/PC state:
--   1. mode off: gift a Pikachu next to the Meowth starter (both legal)
--   2. become Lt. Surge: Meowth is off-roster, Pikachu on -> SWEEP: Meowth
--      to the PC, Pikachu compacts to slot 0, count 2 -> 1.
--      This step has moved twice as the rosters changed: Red until
--      2026-07-24 (the roster sync gave him the Persian line, so Meowth
--      stopped being off-roster), then Falkner until 2026-07-25 (the
--      adversarial audit removed his Pichu, so the gifted Pikachu stopped
--      being ON-roster). Re-check the control characters BY FAMILY BASE
--      after any roster change -- this fixture has caught every one.
--   3. become Lance (roster has NO Pichu family -- Falkner's does, which
--      is what the first version of this test tripped over): the remaining
--      Pikachu is off-roster and ALONE -> SWEEP: the keptOne guard must
--      keep it (never empty the party)
--   4. gift an on-roster Dratini (party: off-roster Pikachu + Dratini)
--      -> SWEEP: Pikachu to the PC, Dratini alone remains
--
-- The call-site link (Cb2_ExitPSS -> sweep on every PSS exit) is a
-- one-line, code-verified hook; this proves the sweep semantics it runs.
--
-- Run (no CM_SAV -- fresh flash, normal-path intro):
--   timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/pc_sweep_e2e.lua pokeemerald.gba \
--     > /tmp/pc_sweep.log 2>&1

local H = dofile("tools/mgba_scripts/harness.lua")

-- ---------------------------------------------------------------- constants

local SPECIES_PIKACHU = 25
local SPECIES_MEOWTH  = 52
local SPECIES_DRATINI = 147

-- Character indices are 1-based positions in gCharacters (characters.txt
-- order). New characters are only ever APPENDED, so these stay valid.
local CHAR_LANCE    = 4
local CHAR_LT_SURGE = 11

local MAP_TRUCK_GROUP = 25
local MAP_TRUCK_NUM   = 40

local QUESTIONS_MAX  = 3
local IDX_START_GAME = 3

-- Request ids come from anchors.lua (derived from the C enum by
-- gen_anchors.py); the enum is positional, so literals here rot
-- silently the moment a request is inserted rather than appended.
local REQ_SET_CHARACTER = H.anchors.REQ.SET_CHARACTER
local REQ_GIVE_MON = H.anchors.REQ.GIVE_MON
local REQ_QUERY_PARTY_MON = H.anchors.REQ.QUERY_PARTY_MON
local REQ_SWEEP_PARTY = H.anchors.REQ.SWEEP_PARTY

local MON_GIVEN_TO_PARTY = 0

local STATUS_DONE     = 1
local STATUS_REJECTED = 2

local MB       = H.anchors.gCharacterModeTestMailbox
local MB_MAGIC = 0x434D5442

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
local function partyCount() return H.rd8(H.anchors.gPlayerPartyCount) end

local function mapGroup() return H.rd8(H.rd32(H.anchors.gSaveBlock1Ptr) + 4) end
local function mapNum()   return H.rd8(H.rd32(H.anchors.gSaveBlock1Ptr) + 5) end
local function inTruck()
    return mapGroup() == MAP_TRUCK_GROUP and mapNum() == MAP_TRUCK_NUM
end

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

-- ------------------------------- phase 1: intro drive (normal path, Meowth)

addStep("pick Start Game at questions index 3",
    nil,
    function(f)
        if f - stepStart > 30000 then
            H.assertTrue("picked Start Game before step timeout", false)
            return true
        end
        local menuUp = inTruck() and menuMax() == QUESTIONS_MAX
        if not menuUp then
            tapEvery(f, H.KEY.A, 29)
            tapEvery(f, H.KEY.START, 173)
            return false
        end
        emu:clearKey(H.KEY.START)
        if (f % 17) == 0 then
            local cur = menuCur()
            if cur < IDX_START_GAME then
                emu:addKey(H.KEY.DOWN)
            elseif cur > IDX_START_GAME then
                emu:addKey(H.KEY.UP)
            else
                emu:addKey(H.KEY.A)
                poisonMenu()
                clearAll()
                return true
            end
        else
            emu:clearKey(H.KEY.A)
            emu:clearKey(H.KEY.DOWN)
            emu:clearKey(H.KEY.UP)
        end
        return false
    end)

local upTries = 0
addStep("reach the overworld outside the truck",
    nil,
    function(f)
        if not inTruck() and onField() and partyCount() >= 1
           and H.rd32(MB) == MB_MAGIC then
            clearAll()
            return true
        end
        if f - stepStart > 40000 then
            H.assertTrue("reached the overworld before step timeout", false)
            return true
        end
        if cb2() >= H.anchors.CB2_StartWallClock
           and cb2() < H.anchors.CB2_StartWallClock + 0x800 then
            emu:clearKey(H.KEY.A)
            emu:clearKey(H.KEY.UP)
            if (f % 21) == 0 then
                if menuCur() == 0 then
                    emu:addKey(H.KEY.A)
                elseif upTries < 3 then
                    emu:addKey(H.KEY.UP)
                    upTries = upTries + 1
                else
                    emu:addKey(H.KEY.A)
                    upTries = 0
                end
            end
            return false
        end
        emu:clearKey(H.KEY.UP)
        tapEvery(f, H.KEY.A, 31)
        return false
    end)

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

-- ------------------------------------------- phase 2: the sweep scenarios

-- 1. mode off: a second legal mon
mbStep("gift Pikachu with mode off", REQ_GIVE_MON, SPECIES_PIKACHU, 10,
    function()
        H.assertEq("Pikachu joined the party (mode off)",
                   mbResult(), MON_GIVEN_TO_PARTY)
        H.assertEq("party is Meowth + Pikachu", partyCount(), 2)
    end)

-- 2. become Falkner; sweep must remove the off-roster Meowth only
mbStep("become Lt. Surge", REQ_SET_CHARACTER, CHAR_LT_SURGE, 0)

mbStep("sweep as Lt. Surge (Meowth off-roster)", REQ_SWEEP_PARTY, 0, 0, function()
    H.assertEq("sweep left exactly 1 mon", mbResult(), 1)
end)

mbStep("slot 0 after Lt. Surge sweep", REQ_QUERY_PARTY_MON, 0, 0, function()
    H.assertEq("Pikachu compacted to slot 0 (Meowth swept to PC)",
               mbResult() % 65536, SPECIES_PIKACHU)
end)

-- 3. become Lance; the lone Pikachu is off-roster but must be KEPT
mbStep("become Lance", REQ_SET_CHARACTER, CHAR_LANCE, 0)

mbStep("sweep as Lance (lone off-roster mon)", REQ_SWEEP_PARTY, 0, 0,
    function()
        H.assertEq("keptOne guard: party not emptied", mbResult(), 1)
    end)

mbStep("slot 0 after guard sweep", REQ_QUERY_PARTY_MON, 0, 0, function()
    H.assertEq("the kept mon is still Pikachu",
               mbResult() % 65536, SPECIES_PIKACHU)
end)

-- 4. with an on-roster companion the off-roster mon IS swept
mbStep("gift on-roster Dratini", REQ_GIVE_MON, SPECIES_DRATINI, 10,
    function()
        H.assertEq("Dratini joined the party", mbResult(), MON_GIVEN_TO_PARTY)
        H.assertEq("party is Pikachu + Dratini", partyCount(), 2)
    end)

mbStep("sweep as Lance (off-roster mon has company)", REQ_SWEEP_PARTY, 0, 0,
    function()
        H.assertEq("sweep left exactly 1 mon", mbResult(), 1)
    end)

mbStep("slot 0 after final sweep", REQ_QUERY_PARTY_MON, 0, 0, function()
    H.assertEq("Dratini remains; Pikachu swept to PC",
               mbResult() % 65536, SPECIES_DRATINI)
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
