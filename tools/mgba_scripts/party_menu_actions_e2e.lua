-- Party-menu action bound, measured in-engine -- PLAN.md item #7.
--
-- The actions[] overflow and the tilemapTop underflow above 9 rows were both
-- found on 2026-08-19 by READING SetPartyMonFieldSelectionActions. At 21/21
-- green, NOTHING in the suite opened the party menu's action window, so no run
-- had ever observed how many rows the builder actually wants. This is that run.
--
-- It drives CharacterMode_ProbePartyMenuActions and
-- CharacterMode_SweepPartyMenuActions, which call THE REAL BUILDER through the
-- same dispatcher the field menu uses. They do not re-derive its arithmetic --
-- re-deriving the arithmetic is what the inspection already did, and it would
-- agree with itself no matter what the shipped code does.
--
-- ⚠️ WHAT THIS PROVES AND WHAT IT DOES NOT.
--   PROVES: how many rows the builder ATTEMPTS to append for real mon data,
--   that the clamp holds at MAX_PARTY_MENU_ACTIONS, and that the window
--   arithmetic stays on-screen at the clamped count.
--   DOES NOT PROVE: that the window RENDERS correctly, or anything at all about
--   input, the cursor, or what a row does when selected. No pixel is inspected
--   and no key is pressed at the party menu. The UI path remains undriven --
--   that is still open, and calling this "the party menu is tested" would be
--   the same overclaim that §10 is a monument to.
--
-- The controls, because a green first try means nothing here:
--   * numActions must equal min(demand, 9) at EVERY probe. Asserting on
--     numActions alone is vacuous -- it is clamped, so it reads the same on a
--     build whose builder never wants a 9th row.
--   * The automatic-follower option is turned ON, probed, turned OFF, and
--     probed again. The demand must drop by EXACTLY ONE. A probe that returned
--     a constant, or that ignored save state, fails this and passes everything
--     else.
--   * The chunk maxima across the sweep must not be all-equal. A probe wired to
--     a fixed number satisfies every inequality above and dies here.
--   * The live measurement on a real party member must equal what the synthetic
--     sweep predicted for the same species. Synthetic-only would be a weaker
--     claim and this test would not be able to tell.
--
-- Run (no CM_SAV -- fresh flash, normal-path intro; the party menu is global,
-- Character Mode is not involved):
--   timeout 240 <mgba-headless> \
--     --script tools/mgba_scripts/party_menu_actions_e2e.lua pokeemerald.gba \
--     > /tmp/party_menu_actions.log 2>&1

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
local REQ_PARTY_MENU_ACTIONS = H.anchors.REQ.PARTY_MENU_ACTIONS
local REQ_PARTY_ACTION_SWEEP = H.anchors.REQ.PARTY_ACTION_SWEEP
local REQ_GIVE_MON           = H.anchors.REQ.GIVE_MON
local REQ_QUERY_PARTY_MON    = H.anchors.REQ.QUERY_PARTY_MON
local REQ_SET_FOLLOWER_OPT   = H.anchors.REQ.SET_FOLLOWER_OPTION
local REQ_SET_MON_MOVE       = H.anchors.REQ.SET_MON_MOVE
local REQ_NICKNAME_APPLY     = H.anchors.REQ.NICKNAME_APPLY

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

-- ------------------------------------------- phase 2: the live starter, as-is
--
-- No state touched. Whatever this reports is what the player would see today.

-- Through a request, not a raw write: the option is a one-bit bitfield and the
-- byte it lives in carries other options.
mbStep("turn the automatic-follower option ON", REQ_SET_FOLLOWER_OPT, 1, 0,
    function()
        H.assertEq("the follower option reads back as ON", mbResult(), 1)
    end)

mbStep("probe the live starter in slot 0", REQ_PARTY_MENU_ACTIONS, 0, 0,
    function()
        H.assertTrue("the probe ran on the live party", probeRan())
        H.assertTrue("the starter gets at least Summary and Cancel",
                     probeNumShown() >= 2)
        H.assertTrue("the starter's row count is within the window",
                     probeNumShown() <= MAX_ACTIONS)
        H.assertEq("numActions is min(demand, 9) for the starter",
                   probeNumShown(),
                   math.min(probeDemand(), MAX_ACTIONS))
        H.assertTrue("the last visible row is Cancel", probeCancel())
        -- PLAN.md item #8: the Nickname row has never been observed to exist.
        H.assertTrue("the Nickname row is offered on a non-egg party mon",
                     probeNickname())
        H.log(string.format(
            "LIVE starter: shown=%d demand=%d tilemapTop=%d",
            probeNumShown(), probeDemand(), probeTop()))
    end)

-- ------------------------------------ phase 3: the exhaustive species sweep

local speciesCount = 0
local sweepMax     = 0
local sweepWorst   = 0
local sweepOver    = 0
local sweepSkip    = 0
local chunkMaxima  = {}
local chunkFails   = 0
local chunkIndex   = 0

mbStep("ask how many species there are", REQ_PARTY_ACTION_SWEEP, 0, 0,
    function()
        H.assertTrue("the species-count query ran", probeRan())
        speciesCount = mbResult() % 65536
        -- Fail loudly on an empty set. Three tests in this repo have passed
        -- vacuously against one (PLAN.md §9).
        H.assertTrue("the species table is not empty (>= 400)",
                     speciesCount >= 400)
        H.log("NUM_SPECIES = " .. speciesCount)
    end)

-- The chunk steps are built now but READ speciesCount at enter time. There are
-- more of them than any table can need; each one past the end is skipped, so
-- the assertion tally does not move with the species count.
for i = 0, 63 do
    local base = i * SWEEP_CHUNK
    addStep("sweep species " .. base .. ".." .. (base + SWEEP_CHUNK - 1),
        function()
            if base >= speciesCount then return end
            mbRequest(REQ_PARTY_ACTION_SWEEP, base, SWEEP_CHUNK)
        end,
        function(f)
            if base >= speciesCount then return true end
            local s = mbStatus()
            if s == STATUS_REJECTED then
                chunkFails = chunkFails + 1
                return true
            end
            if s == STATUS_DONE then
                if not probeRan() then
                    chunkFails = chunkFails + 1
                    return true
                end
                chunkIndex = chunkIndex + 1
                local m = sweepMaxDemand()
                table.insert(chunkMaxima, m)
                if m > sweepMax then
                    sweepMax = m
                    sweepWorst = sweepWorstSpecies()
                end
                sweepOver = sweepOver + sweepOverCount()
                sweepSkip = sweepSkip + sweepSkipped()
                return true
            end
            if f - stepStart > 4000 then
                -- The sweep writes the species it is ABOUT to probe into the
                -- result word before probing it, so a wedge names itself
                -- instead of expiring anonymously.
                chunkFails = chunkFails + 1
                H.log(string.format(
                    "CHUNK %d..%d NEVER ANSWERED -- last species attempted: %d",
                    base, base + SWEEP_CHUNK - 1, mbResult() % 2048))
                return true
            end
            return false
        end)
end

addStep("the sweep covered every species and answered every chunk", nil,
    function()
        H.assertEq("no sweep chunk failed or came back empty", chunkFails, 0)
        H.assertEq("chunk count matches the species table",
                   chunkIndex, math.ceil(speciesCount / SWEEP_CHUNK))

        -- ⚠️ HEADLINE 1, and the one PLAN.md §12.2 actually asserts: the
        -- builder wants a 9th row for an ORDINARY Pokemon, so the u8[8] this
        -- buffer used to be was overflowed -- the 9th append landing on
        -- numActions itself. Measured, not argued.
        H.assertTrue(string.format(
            "the builder overflows the OLD 8-entry buffer " ..
            "(max demand %d > %d, species %d)",
            sweepMax, OLD_ACTIONS_BUFFER, sweepWorst),
            sweepMax > OLD_ACTIONS_BUFFER)

        -- ⚠️ The window question is SEPARATE and this is not the phase that
        -- settles it. On natural level-50 movesets nothing exceeds 9; the
        -- Cut + Secret Power phase below is where that gets pushed. Logged
        -- either way so a future change that makes a bare species exceed the
        -- window cannot slip past unremarked.
        H.log(string.format(
            "species exceeding the WINDOW on a natural moveset: %d", sweepOver))

        -- NON-CONSTANCY CONTROL. Every inequality above is satisfied by a probe
        -- hardwired to a large number; this is the one that is not.
        local allSame = true
        for _, m in ipairs(chunkMaxima) do
            if m ~= chunkMaxima[1] then allSame = false break end
        end
        H.assertTrue("the sweep does not report the same maximum everywhere",
                     not allSame)

        -- No silent caps: the skipped ids are named, not quietly dropped.
        H.log(string.format(
            "SWEEP: %d ids, %d skipped as having no gBaseStats row, " ..
            "max demand %d (species %d), %d over the window",
            speciesCount, sweepSkip, sweepMax, sweepWorst, sweepOver))
        H.assertTrue("the skipped ids are a handful, not a whole generation",
                     sweepSkip < 32)
        return true
    end)

-- ----------------------- phase 4: the worst species, in a LIVE party, for real
--
-- The sweep is synthetic. This puts the same species in gPlayerParty and probes
-- it through the live path, and the two numbers have to agree.

local liveSlot = 0
local liveDemandNatural = 0
local liveDemandTaught  = 0

mbStep("give the worst species to the live party", REQ_GIVE_MON,
    function() return sweepWorst end, 50,
    function()
        H.assertTrue("the party now holds at least two Pokemon",
                     partyCount() >= 2)
        liveSlot = partyCount() - 1
    end)

mbStep("the given mon is the species the sweep named", REQ_QUERY_PARTY_MON,
    function() return liveSlot end, 0,
    function()
        H.assertEq("slot holds the swept species",
                   mbResult() % 65536, sweepWorst)
    end)

mbStep("probe the worst species in the LIVE party", REQ_PARTY_MENU_ACTIONS,
    function() return liveSlot end, 0,
    function()
        H.assertTrue("the live probe ran", probeRan())
        liveDemandNatural = probeDemand()

        -- Synthetic and live must agree, or the sweep is measuring something
        -- the game does not do.
        H.assertEq("live demand equals what the synthetic sweep predicted",
                   liveDemandNatural, sweepMax)
        H.assertEq("numActions is min(demand, 9)",
                   probeNumShown(), math.min(probeDemand(), MAX_ACTIONS))
        H.assertTrue("the last visible row is Cancel", probeCancel())
        H.log(string.format(
            "LIVE natural: species=%d shown=%d demand=%d tilemapTop=%d",
            sweepWorst, probeNumShown(), probeDemand(), probeTop()))
    end)

-- ------------------- phase 5: past the WINDOW, with two ordinary player moves
--
-- A natural moveset tops out at 9, which overflows the old buffer but does not
-- reach the tilemapTop underflow at 10. Cut and Secret Power are the only two
-- sFieldMoves the known-move loop does not skip, and both are ordinary player
-- moves (HM01, TM43). Cut is the sharp one: this mon can already LEARN Cut, so
-- it has a tutor row, and knowing the move adds a SECOND Cut row.

mbStep("teach the mon Cut", REQ_SET_MON_MOVE,
    function() return liveSlot end, MOVE_CUT,
    function()
        H.assertEq("move slot 0 holds Cut", mbResult(), MOVE_CUT)
    end)

mbStep("teach the mon Secret Power", REQ_SET_MON_MOVE,
    function() return liveSlot + 256 end, MOVE_SECRET_POWER,
    function()
        H.assertEq("move slot 1 holds Secret Power",
                   mbResult(), MOVE_SECRET_POWER)
    end)

mbStep("probe the mon again with both field moves known",
    REQ_PARTY_MENU_ACTIONS, function() return liveSlot end, 0,
    function()
        H.assertTrue("the probe ran", probeRan())
        liveDemandTaught = probeDemand()

        -- ⚠️ HEADLINE 2. The tilemapTop underflow needs a TENTH row, and this
        -- is a Pokemon a player can build with two HM/TM moves.
        H.assertTrue(string.format(
            "two taught field moves push the builder past the WINDOW " ..
            "(demand %d > %d)", liveDemandTaught, MAX_ACTIONS),
            liveDemandTaught > MAX_ACTIONS)

        H.assertTrue("teaching field moves added rows",
                     liveDemandTaught > liveDemandNatural)

        -- What the clamp is FOR. Unfixed, numActions would be liveDemandTaught
        -- and 19 - 2*numActions would wrap in a u8; here it is pinned at 9.
        H.assertEq("the menu still clamps to the window",
                   probeNumShown(), MAX_ACTIONS)
        H.assertEq("tilemapTop is on-screen, not wrapped past 255",
                   probeTop(), 19 - MAX_ACTIONS * 2)
        H.assertTrue("Cancel still holds the last visible row when rows are dropped",
                     probeCancel())
        H.log(string.format(
            "LIVE taught: shown=%d demand=%d tilemapTop=%d (natural was %d)",
            probeNumShown(), probeDemand(), probeTop(), liveDemandNatural))
    end)

-- STATE CONTROL. Turn the follower option off and probe the same mon again.
-- The demand must fall by exactly one. A probe that returns a constant, or that
-- never reads the save, passes every other assertion in this file and fails
-- this one.
mbStep("turn the automatic-follower option OFF", REQ_SET_FOLLOWER_OPT, 0, 0,
    function()
        H.assertEq("the follower option reads back as OFF", mbResult(), 0)
    end)

mbStep("re-probe the same mon with the follower option off",
    REQ_PARTY_MENU_ACTIONS, function() return liveSlot end, 0,
    function()
        H.assertTrue("the re-probe ran", probeRan())
        H.assertEq("dropping the Follow row costs exactly one row",
                   probeDemand(), liveDemandTaught - 1)
    end)

-- ---------------------------------------------------------------------------
-- PLAN.md item #8, second half: the Nickname row's BEHAVIOUR
-- ---------------------------------------------------------------------------
--
-- The probe above asserts the row is PRESENT. That says nothing about what
-- choosing it does. CB2_SetPartyMonNickname is the whole of what it does --
-- everything between the naming screen and the mon is its one SetMonData --
-- and CharacterMode_TestNicknameApply calls THAT function, through the real
-- slot selector (gPartyMenu.slotId) and the real buffer (gStringVar2), rather
-- than re-implementing the write the way CM_REQ_SET_NICKNAME does.
--
-- ⚠️ The naming screen itself is still undriven. DoNamingScreen -> keyboard ->
-- this callback is party-menu UI and no headless run in this repo drives UI.
-- Do not read a green run here as "the Nickname row is tested end to end".
--
-- Two DIFFERENT characters are written, and that is the control: one write
-- reading back correctly is equally consistent with a read-back that returns
-- whatever was asked for.

local NAME_LENGTH = 12          -- POKEMON_NAME_LENGTH, 12/12 since 71cebcbe
local CHAR_A      = 0xBB        -- 'A' in the game's charmap
local CHAR_B      = 0xBC        -- 'B'

local function nickLen(r)     return math.floor(r / 65536) % 256 end
local function nickFirstBad(r) return r % 65536 end

mbStep("rename slot 0 through the real party-menu callback", REQ_NICKNAME_APPLY,
    0, CHAR_A,
    function()
        local r = mbResult()
        H.assertTrue("the rename ran", bit(r, 31))
        H.assertEq("every one of the 12 characters survived the round trip",
                   nickFirstBad(r), 0)
        H.assertEq("and the stored nickname is the full 12 characters long",
                   nickLen(r), NAME_LENGTH)
    end)

mbStep("rename it again with a different character", REQ_NICKNAME_APPLY,
    0, CHAR_B,
    function()
        local r = mbResult()
        H.assertEq("the second name also survived intact -- so the read-back "
                   .. "is reading the mon, not echoing the request",
                   nickFirstBad(r), 0)
        H.assertEq("still 12 characters", nickLen(r), NAME_LENGTH)
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
        if current.enter then current.enter(f) end
    end

    if current.tick and current.tick(f) then
        current = nil
    end
end)
