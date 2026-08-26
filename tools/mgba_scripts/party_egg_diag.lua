-- MON_DATA_IS_EGG diagnostic -- PLAN.md item #9. NOT A SUITE TEST.
--
-- §12.3 recorded that both egg bits read back 0 after being written and named
-- the SetBoxMonData checksum guard as the suspect. That was a guess: nothing
-- had looked at the checksum, and nothing had read the bits at their storage
-- locations rather than through GetMonData -- so "the write was dropped" and
-- "the write landed and the getter lies" were the same observation.
--
-- This prints, in order, the checksum the guard compares and the two bits as
-- STORED, before and after each write. It asserts almost nothing on purpose:
-- it is here to produce numbers to read, and it must not become a test until
-- #9 is root-caused, for the same reason CM_REQ_SET_MON_EGG carries that
-- warning -- a test built on a broken write passes by never making an egg.
--
--   timeout 240 <mgba-headless> \
--     --script tools/mgba_scripts/party_egg_diag.lua pokeemerald.gba

local H = dofile("tools/mgba_scripts/harness.lua")

-- ---------------------------------------------------------------- constants

-- Mirrors MAX_PARTY_MENU_ACTIONS (include/party_menu.h). It is the WINDOW's
-- ceiling, not a buffer size: at 10 actions tilemapTop is 19 - 20 = -1, which
-- wraps to 255 in a u8 and puts the window off a 20-row screen.
local MAX_ACTIONS = 9

-- What PartyMenuInternal.actions WAS until 2026-08-19. The buffer-overflow
-- question is "does the builder ever want a 9th row", i.e. demand > 8 -- NOT
-- demand > 9, which is the separate WINDOW question. The first version of this
-- test conflated the two and reported the overflow as unreproduced on a run
-- that had in fact reproduced it.
local OLD_ACTIONS_BUFFER = 8

-- The only two sFieldMoves entries the known-move loop does not skip
-- (src/data/party_menu.h:1023 against the break-list in the builder), so these
-- are the only two moves a player can teach that ADD a row. Cut is the sharp
-- one: a mon that can LEARN Cut already has a tutor row, and knowing it adds a
-- SECOND. Both are ordinary player moves here -- HM01 and TM43.
local MOVE_CUT          = 15
local MOVE_SECRET_POWER = 290

local MAP_TRUCK_GROUP = 25
local MAP_TRUCK_NUM   = 40

local QUESTIONS_MAX  = 3
local IDX_START_GAME = 3

local SWEEP_CHUNK = 64

-- Request ids come from anchors.lua (derived from the C enum by
-- gen_anchors.py); the enum is positional, so literals here rot silently the
-- moment a request is inserted rather than appended.
local REQ_GIVE_MON           = H.anchors.REQ.GIVE_MON
local REQ_QUERY_PARTY_MON    = H.anchors.REQ.QUERY_PARTY_MON
local REQ_EGG_DIAG           = H.anchors.REQ.EGG_DIAG

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

-- ------------------------------------------------- unpacking the result word
--
-- [31] ran | [25] Nickname row | [24] last visible row is Cancel
-- [23:16] tilemapTop | [15:8] demand (attempted) | [7:0] numActions (shown)

local function bit(v, n) return math.floor(v / 2 ^ n) % 2 == 1 end

local function probeRan()      return bit(mbResult(), 31) end
local function probeNumShown() return mbResult() % 256 end
local function probeDemand()   return math.floor(mbResult() / 256) % 256 end
local function probeTop()      return math.floor(mbResult() / 65536) % 256 end
local function probeCancel()   return bit(mbResult(), 24) end
local function probeNickname() return bit(mbResult(), 25) end

-- Sweep: [31] ran | [30:24] skipped | [23:17] over-window | [16:11] max demand
--        [10:0] the species that produced it
local function sweepWorstSpecies() return mbResult() % 2048 end
local function sweepMaxDemand()    return math.floor(mbResult() / 2048) % 64 end
local function sweepOverCount()    return math.floor(mbResult() / 131072) % 128 end
local function sweepSkipped()      return math.floor(mbResult() / 16777216) % 128 end

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

-- `a` and `b` are resolved at ENTER time, not at script-build time: the sweep
-- chunks and the worst species are not known until earlier steps have run.
local function mbStep(name, req, a, b, onDone)
    addStep(name,
        function()
            local av = (type(a) == "function") and a() or a
            local bv = (type(b) == "function") and b() or b
            mbRequest(req, av, bv)
        end,
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
            if f - stepStart > 4000 then
                H.assertTrue(name .. " (mailbox answered)", false)
                return true
            end
            return false
        end)
end

-- ------------------------------ phase 1: intro drive (normal path, mode off)

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
        else
            tapEvery(f, H.KEY.A, 23)
        end
        return false
    end)


-- ---------------------------------------------------------------- phase 2

local function raw(label)
    local r = mbResult()
    local sanity = r % 2
    local enc    = math.floor(r / 2) % 2
    H.log(string.format("%-34s sanity=%d encrypted=%d  (raw 0x%08X)",
                        label, sanity, enc, r))
end

local function checksum(label)
    local r = mbResult()
    local computed = math.floor(r / 65536) % 65536
    local stored   = r % 65536
    H.log(string.format("%-34s computed=%5d stored=%5d  %s",
                        label, computed, stored,
                        computed == stored and "MATCH -- guard does NOT fire"
                                            or "MISMATCH -- GUARD FIRES"))
end

local DIAG_CHECKSUM, DIAG_RAW, DIAG_WRITE_SANITY, DIAG_WRITE_ENC, DIAG_GETTER
    = 0, 1, 2, 3, 4

mbStep("checksum, before anything",  REQ_EGG_DIAG, 0, DIAG_CHECKSUM,
    function() checksum("BEFORE  checksum") end)
mbStep("raw bits, before anything",  REQ_EGG_DIAG, 0, DIAG_RAW,
    function() raw("BEFORE  raw") end)
mbStep("getter, before anything",    REQ_EGG_DIAG, 0, DIAG_GETTER,
    function() raw("BEFORE  getter") end)

mbStep("write the SANITY bit",       REQ_EGG_DIAG, 0, DIAG_WRITE_SANITY,
    function() raw("AFTER SANITY write  raw") end)
mbStep("getter after SANITY",        REQ_EGG_DIAG, 0, DIAG_GETTER,
    function() raw("AFTER SANITY write  getter") end)
mbStep("checksum after SANITY",      REQ_EGG_DIAG, 0, DIAG_CHECKSUM,
    function() checksum("AFTER SANITY write  checksum") end)

mbStep("write the ENCRYPTED bit",    REQ_EGG_DIAG, 0, DIAG_WRITE_ENC,
    function() raw("AFTER ENCRYPTED write  raw") end)
-- ⚠️ THE CONTROL. Re-read RAW, with no getter in between, immediately after
-- the write. If the bit survives here and dies only once a getter has run,
-- the getter is the thing clearing it -- which is the opposite of where §12.3
-- pointed (the SetBoxMonData write guard).
mbStep("raw again, NO getter in between", REQ_EGG_DIAG, 0, DIAG_RAW,
    function() raw("AFTER ENCRYPTED write  raw again") end)
mbStep("checksum, still no getter",  REQ_EGG_DIAG, 0, DIAG_CHECKSUM,
    function() checksum("AFTER ENCRYPTED write  checksum (pre-getter)") end)

mbStep("getter after ENCRYPTED",     REQ_EGG_DIAG, 0, DIAG_GETTER,
    function() raw("AFTER ENCRYPTED write  getter") end)
mbStep("raw AFTER the getter has run", REQ_EGG_DIAG, 0, DIAG_RAW,
    function() raw("AFTER getter          raw") end)
mbStep("checksum after ENCRYPTED",   REQ_EGG_DIAG, 0, DIAG_CHECKSUM,
    function() checksum("AFTER ENCRYPTED write  checksum") end)

-- Does the damage persist? GetBoxMonData re-stamps a mismatched checksum
-- before it tests for a bad egg, so a SECOND read may repair what the first
-- broke. That decides whether the corruption window is one call wide or the
-- rest of the Pokemon's life -- a difference worth measuring, not assuming.
mbStep("a SECOND getter",            REQ_EGG_DIAG, 0, DIAG_GETTER,
    function() raw("SECOND getter         getter") end)
mbStep("checksum after second getter", REQ_EGG_DIAG, 0, DIAG_CHECKSUM,
    function() checksum("AFTER second getter  checksum") end)

-- One assertion, so a run that boots and does nothing cannot report success.
addStep("the diagnostic produced readings", nil, function()
    H.assertTrue("the mailbox answered every diagnostic op", true)
    return true
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
        if current == nil then finished = true; H.finish(); return end
        stepStart = f
        if current.enter then current.enter(f) end
    end
    if current.tick and current.tick(f) then current = nil end
end)
