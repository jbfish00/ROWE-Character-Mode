-- In-game trade e2e — checklist item 11, the last automatable gap.
--
-- `CharacterMode_SweepPartyToPC` is called from `trade.c:3905`, `:4422` and
-- `:5723`, and until now that was a **static audit**: nobody had ever run a
-- trade. Those call sites sit at case 74 of the trade cutscene's state machine,
-- after the fade, the animation and the free -- so the only way to prove they
-- fire is to run the whole cutscene, which is what this does. The mailbox sets
-- the same two script vars the trade scripts set and calls the same two
-- specials in the same order (`CreateInGameTradePokemon`, `DoInGameTradeScene`).
--
-- ⭐ THE DISCRIMINATING PAIR. "The traded-for mon went to the PC" passes both
-- when the gate works and when a trade dumps EVERYTHING to the PC, so the same
-- run trades for an ON-roster mon and requires it to STAY in the party:
--
--   1. off-roster incoming (Dracovish) -> swept to the PC, party count drops,
--      box count rises by exactly one
--   2. on-roster incoming (your own Pikachu, via the engine's trade-index 6
--      "get your own mon back" mode) -> stays in the party, box count unchanged
--
-- ⭐ AND THE CONTROLS CHECK THEMSELVES. "Dracovish is off Red's roster" is an
-- assumption that a roster edit can quietly falsify -- that has already happened
-- once in this repo (the 2026-07-24 sync gave Red the Persian line and three
-- tests using Meowth as their off-roster control silently started testing
-- nothing). So both species are put through the gift gate FIRST, and the run
-- fails loudly if either is not what it claims to be.
--
--   CM_SAV=<fixture.sav> timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/trade_gate_e2e.lua pokeemerald.gba \
--     > /tmp/trade_gate_e2e.log 2>&1
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

local CHARACTER_RED = 1
local SPECIES_PIKACHU = 25
-- What INGAME_TRADE_HORSEA hands over (src/data/trade.h). Resolved with the C
-- preprocessor, not guessed.
local SPECIES_DRACOVISH = 882

-- INGAME_TRADE_HORSEA (include/constants/trade.h) hands over DRACOVISH.
local TRADE_DRACOVISH = 2
-- CreateInGameTradePokemon's index 6: `gEnemyParty[0] = gPlayerParty[slot]`,
-- i.e. trade a mon and receive it back. A live engine path (the Pokemon Center
-- Jack wonder-trade chain uses it), and the only way to get an ON-roster
-- incoming mon out of a table whose four real entries are all off-roster.
local TRADE_GIVE_BACK = 6

local MON_GIVEN_TO_PARTY = 0
local MON_GIVEN_TO_PC    = 1

local ALL_BOXES = 0xFFFF

local REQ_SET_CHARACTER = H.anchors.REQ.SET_CHARACTER
local REQ_GIVE_MON = H.anchors.REQ.GIVE_MON
local REQ_QUERY_PARTY_MON = H.anchors.REQ.QUERY_PARTY_MON
local REQ_UNLOCK = H.anchors.REQ.UNLOCK
local REQ_INGAME_TRADE = H.anchors.REQ.INGAME_TRADE
local REQ_BOX_COUNT = H.anchors.REQ.BOX_COUNT

if not REQ_INGAME_TRADE or not REQ_BOX_COUNT then
    error("anchors.lua predates the trade requests -- re-run gen_anchors.py")
end

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

local function cb2()        return H.rd32(H.anchors.gMain + 4) end
local function onField()    return cb2() == H.anchors.CB2_Overworld + 1 end
local function partyCount() return H.rd8(H.anchors.gPlayerPartyCount) end

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

-- ------------------------------------------------------------------- steps

addStep("continue to overworld", nil, function(f)
    if onField() and H.rd32(MB) == MB_MAGIC then
        emu:clearKey(H.KEY.A)
        return true
    end
    if f - stepStart > 200 then mashEvery(f, H.KEY.A, 25) end
    return false
end)

addStep("settle on the field", nil, function(f)
    if f - stepStart >= 240 then
        emu:clearKey(H.KEY.B)
        return true
    end
    mashEvery(f, H.KEY.B, 30)
    return false
end)

mbStep("enter Character Mode as Red", REQ_SET_CHARACTER, CHARACTER_RED, 0, function()
    H.assertEq("InCharacterMode() after SET_CHARACTER(1)", mbResult(), 1)
end)

-- --- the controls check themselves ------------------------------------------
--
-- Both species go through the gift gate, which is the same roster test the
-- sweep uses. If a roster edit ever puts Dracovish on Red or takes Pikachu off,
-- this run says so instead of quietly proving nothing.

mbStep("control: an on-roster gift joins the party (Pikachu is on Red)",
    REQ_GIVE_MON, SPECIES_PIKACHU, 10, function()
        H.assertEq("Pikachu is ON Red's roster (gift went to the party)",
                   mbResult(), MON_GIVEN_TO_PARTY)
    end)

mbStep("control: Dracovish really is OFF Red's roster",
    REQ_GIVE_MON, SPECIES_DRACOVISH, 10, function()
        -- Same roster test the sweep uses. If a future roster edit puts the
        -- Dracovish family on Red, the trade below stops being a test of
        -- anything -- and this line is what says so.
        H.assertEq("Dracovish is OFF Red's roster (gift routed to the PC)",
                   mbResult(), MON_GIVEN_TO_PC)
    end)

-- --- 1. off-roster incoming must be swept to the PC --------------------------

local partyBefore, boxesBefore = 0, 0

-- Slot 1, never slot 0. CharacterMode_SweepPartyToPC has a keptOne guard that
-- refuses to empty the party, so a run whose ONLY remaining mon is the
-- off-roster incoming would watch it be KEPT and read that as a broken gate.
-- Slot 0 holds an on-roster Pikachu throughout, so the guard is never in play.
local TRADE_SLOT = 1

mbStep("count the PC before the trade", REQ_BOX_COUNT, ALL_BOXES, 0, function()
    boxesBefore = mbResult()
    H.log("PC holds " .. boxesBefore .. " before the trade")
end)

addStep("snapshot the party before the trade", nil, function()
    partyBefore = partyCount()
    H.assertTrue("party has at least 2 mons, so the keptOne guard is not in play",
                 partyBefore >= 2)
    H.log("trading away slot " .. TRADE_SLOT .. " of " .. partyBefore)
    return true
end)

mbStep("run the REAL in-game trade cutscene (off-roster Dracovish incoming)",
    REQ_INGAME_TRADE, TRADE_DRACOVISH, TRADE_SLOT, nil)

addStep("wait for the trade cutscene to return to the field", nil, function(f)
    if f - stepStart > 400 and onField() then
        emu:clearKey(H.KEY.A)
        emu:clearKey(H.KEY.B)
        return true
    end
    -- The cutscene walks its own state machine but ends in message boxes.
    mashEvery(f, H.KEY.A, 31)
    if (f % 47) == 0 then emu:addKey(H.KEY.B) elseif (f % 47) == 8 then emu:clearKey(H.KEY.B) end
    if f - stepStart > 60000 then
        H.assertTrue("the trade cutscene returned to the field", false)
        return true
    end
    return false
end)

mbStep("unlock the field after the trade", REQ_UNLOCK, 0, 0)

mbStep("count the PC after the off-roster trade", REQ_BOX_COUNT, ALL_BOXES, 0,
    function()
        local after = mbResult()
        -- The positive claim. "It left the party" is also true if the trade
        -- simply deleted it, which is why the box count is asserted and not
        -- just the party count.
        H.assertEq("the off-roster traded-for mon landed in the PC " ..
                   "(box count +1)", after, boxesBefore + 1)
    end)

addStep("party shrank by exactly the swept mon", nil, function()
    H.assertEq("party count dropped by one after the off-roster trade",
               partyCount(), partyBefore - 1)
    return true
end)

mbStep("slot 0 is still the on-roster Pikachu", REQ_QUERY_PARTY_MON, 0, 0,
    function()
        H.assertEq("slot 0 species is still Pikachu (the sweep left it alone)",
                   mbResult() % 65536, SPECIES_PIKACHU)
    end)

-- --- 2. THE IN-BAND CONTROL: on-roster incoming must STAY -------------------
--
-- Without this, every assertion above is equally satisfied by a build that
-- sweeps the whole party to the PC after any trade.

local boxesBeforeGood, partyBeforeGood = 0, 0

mbStep("count the PC before the on-roster trade", REQ_BOX_COUNT, ALL_BOXES, 0,
    function() boxesBeforeGood = mbResult() end)

addStep("snapshot the party before the on-roster trade", nil, function()
    partyBeforeGood = partyCount()
    return true
end)

-- Slot 0 this time: index 6 copies that slot into gEnemyParty, so the incoming
-- mon IS the on-roster Pikachu sitting there.
mbStep("run the REAL trade cutscene again, on-roster mon incoming",
    REQ_INGAME_TRADE, TRADE_GIVE_BACK, 0, nil)

addStep("wait for the second trade to return to the field", nil, function(f)
    if f - stepStart > 400 and onField() then
        emu:clearKey(H.KEY.A)
        emu:clearKey(H.KEY.B)
        return true
    end
    mashEvery(f, H.KEY.A, 31)
    if (f % 47) == 0 then emu:addKey(H.KEY.B) elseif (f % 47) == 8 then emu:clearKey(H.KEY.B) end
    if f - stepStart > 60000 then
        H.assertTrue("the second trade cutscene returned to the field", false)
        return true
    end
    return false
end)

mbStep("unlock the field after the second trade", REQ_UNLOCK, 0, 0)

mbStep("count the PC after the on-roster trade", REQ_BOX_COUNT, ALL_BOXES, 0,
    function()
        H.assertEq("an ON-roster traded-for mon was NOT swept (box count " ..
                   "unchanged)", mbResult(), boxesBeforeGood)
    end)

addStep("the on-roster mon is still in the party", nil, function()
    H.assertEq("party count unchanged by the on-roster trade",
               partyCount(), partyBeforeGood)
    return true
end)

mbStep("slot 0 survived the on-roster trade", REQ_QUERY_PARTY_MON, 0, 0,
    function()
        H.assertEq("slot 0 species is Pikachu after the on-roster trade",
                   mbResult() % 65536, SPECIES_PIKACHU)
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
