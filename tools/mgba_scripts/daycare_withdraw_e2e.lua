-- The daycare WITHDRAW path, gated -- PLAN.md item #10.
--
-- TakeSelectedPokemonFromDaycare (src/daycare.c:254) writes straight into
-- gPlayerParty[PARTY_SIZE - 1] and was the last ungated party writer in the
-- tree; _GiveEggFromDaycare twenty lines below it got the sweep in July and
-- this did not. Fixed in 78512b0b by calling CharacterMode_SweepPartyToPC()
-- before it returns -- and then NO script in tools/mgba_scripts/ drove the path
-- at all, so the fix has never been observed to work.
--
-- Reachability, from the fix's own comment: benign in ordinary play (rosters
-- are fixed after the intro and the daycare does not evolve), but reachable the
-- moment an off-roster mon is in the party at all -- the boxes-full branch of
-- SweepPartyToPC leaves one there, and the debug mode toggle makes it trivial.
--
-- This drives the REAL pair through the mailbox: StoreSelectedPokemonInDaycare
-- with gPartyMenu.slotId set the way the party menu sets it (the deposit reads
-- it back through GetCursorSelectionMonId), and TakePokemonFromDaycare reading
-- gSpecialVar_0x8004 the way the script command does.
--
-- ⭐ THE CONTROL IS THE SECOND HALF, and without it the first half is vacuous:
-- "the off-roster mon went to the PC" is equally true of a build that routes
-- EVERY withdrawal to the PC. So an ON-roster mon is deposited and withdrawn
-- too, and it must come back to the PARTY.
--
-- Run (no CM_SAV -- drives a real new game):
--   timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/daycare_withdraw_e2e.lua pokeemerald.gba \
--     > /tmp/daycare_withdraw.log 2>&1

local H = dofile("tools/mgba_scripts/harness.lua")
local D = dofile("tools/mgba_scripts/intro_drive.lua")(H)

local SPECIES_MEOWTH  = 52
local SPECIES_PIKACHU = 25

-- 1-based gCharacters index. Lt. Surge's roster has the Pikachu family and not
-- the Meowth one -- the same pairing pc_sweep_e2e uses, and the same warning
-- applies: RE-CHECK THESE BY FAMILY BASE after any roster change. That test has
-- had to move its control character twice for exactly this reason.
local CHAR_LT_SURGE = 11

local DAYCARE_DEPOSIT  = 0
local DAYCARE_WITHDRAW = 1
local DAYCARE_QUERY    = 2

local MON_GIVEN_TO_PARTY = 0

local function dc(op, slot) return op + slot * 256 end
local function lo(r) return r % 65536 end
local function hi(r) return math.floor(r / 65536) end

D.driveNewGameCharacterMode()

-- Character Mode diverts an off-roster GIFT to the PC, which would leave the
-- party empty and make everything below vacuous. Set the fixture up with the
-- mode off, then turn it on for the part being tested.
D.mbStep("character mode off, so the gifts land in the party",
    D.REQ.SET_CHARACTER, 0, 0,
    function() H.assertEq("InCharacterMode() is now false", D.mbResult(), 0) end)

D.mbStep("gift a Meowth", D.REQ.GIVE_MON, SPECIES_MEOWTH, 20,
    function() H.assertEq("Meowth went to the PARTY", D.mbResult(), MON_GIVEN_TO_PARTY) end)

D.mbStep("gift a Pikachu", D.REQ.GIVE_MON, SPECIES_PIKACHU, 20,
    function() H.assertEq("Pikachu went to the PARTY", D.mbResult(), MON_GIVEN_TO_PARTY) end)

D.mbStep("Meowth is in slot 1", D.REQ.QUERY_PARTY_MON, 1, 0,
    function() H.assertEq("slot 1 is Meowth", lo(D.mbResult()), SPECIES_MEOWTH) end)

D.mbStep("Pikachu is in slot 2", D.REQ.QUERY_PARTY_MON, 2, 0,
    function() H.assertEq("slot 2 is Pikachu", lo(D.mbResult()), SPECIES_PIKACHU) end)

-- ---------------------------------------------------------------------------
-- The off-roster case
-- ---------------------------------------------------------------------------

D.mbStep("deposit Meowth (party slot 1) into the daycare",
    D.REQ.DAYCARE, dc(DAYCARE_DEPOSIT, 1), 0,
    function() H.assertEq("the daycare holds 1 Pokemon", D.mbResult(), 1) end)

D.mbStep("become Lt. Surge -- Meowth is off his roster, Pikachu is on it",
    D.REQ.SET_CHARACTER, CHAR_LT_SURGE, 0,
    function() H.assertEq("InCharacterMode() is now true", D.mbResult(), 1) end)

-- Sweep FIRST, so the party is already settled and the withdraw's own sweep is
-- the only thing that can move a mon after this point. Without this the
-- starter granted by the intro would be swept by the withdraw too and the box
-- delta below would not be attributable.
D.mbStep("sweep the party clean before measuring", D.REQ.SWEEP_PARTY, 0, 0, nil)

local partyBefore, boxBefore = 0, 0

D.mbStep("record the party count", D.REQ.QUERY_PARTY_MON, 0, 0, function()
    partyBefore = D.partyCount()
    H.assertTrue("the party is not empty before the withdraw (the keptOne "
                 .. "guard held)", partyBefore >= 1)
end)

D.mbStep("record the box count", D.REQ.BOX_COUNT, 0xFFFF, 0, function()
    boxBefore = D.mbResult()
end)

D.mbStep("withdraw Meowth from the daycare", D.REQ.DAYCARE, dc(DAYCARE_WITHDRAW, 0), 0,
    function()
        local r = D.mbResult()
        H.assertEq("TakePokemonFromDaycare returned Meowth", hi(r), SPECIES_MEOWTH)
        -- The party count it reports is AFTER the sweep the fix added.
        H.assertEq("the party count is unchanged -- the off-roster Meowth did "
                   .. "not stay in it", lo(r), partyBefore)
    end)

D.mbStep("Meowth is nowhere in the party", D.REQ.QUERY_PARTY_MON, 1, 0, function()
    H.assertTrue("party slot 1 is not Meowth", lo(D.mbResult()) ~= SPECIES_MEOWTH)
end)

D.mbStep("and it landed in the PC", D.REQ.BOX_COUNT, 0xFFFF, 0, function()
    H.assertEq("exactly one mon was added to the PC", D.mbResult(), boxBefore + 1)
end)

-- ---------------------------------------------------------------------------
-- ⭐ THE CONTROL: an ON-roster withdrawal must come back to the PARTY
-- ---------------------------------------------------------------------------
--
-- The mon in slot 0 is party-legal BY CONSTRUCTION: it just survived the sweep
-- above as Lt. Surge. So its species is not hardcoded here -- it is read back
-- and asserted against itself, which is what keeps this control alive across
-- the roster changes that have twice forced pc_sweep_e2e to move characters.

local keptSpecies = 0

D.mbStep("read the party-legal mon in slot 0", D.REQ.QUERY_PARTY_MON, 0, 0, function()
    keptSpecies = lo(D.mbResult())
    H.assertTrue("slot 0 holds a real Pokemon to run the control with",
                 keptSpecies > 0)
end)

-- ⚠️ GIFT A SECOND LEGAL MON FIRST. After the sweep the party can be down to a
-- single Pokemon, and depositing that one would leave the party EMPTY for the
-- frame between this request and the next. The game itself never allows that
-- (the daycare UI refuses your last mon), so it is a state no other code here
-- is written to survive -- not a thing to prove the gate against.
D.mbStep("gift a second on-roster mon so the party cannot empty",
    D.REQ.GIVE_MON, SPECIES_PIKACHU, 15,
    function() H.assertEq("it went to the PARTY -- Pikachu is on Lt. Surge's "
                          .. "roster", D.mbResult(), MON_GIVEN_TO_PARTY) end)

D.mbStep("deposit that party-legal mon", D.REQ.DAYCARE, dc(DAYCARE_DEPOSIT, 0), 0,
    function() H.assertEq("the daycare holds it", D.mbResult(), 1) end)

D.mbStep("withdraw it -- it must come back to the PARTY",
    D.REQ.DAYCARE, dc(DAYCARE_WITHDRAW, 0), 0,
    function()
        local r = D.mbResult()
        H.assertEq("TakePokemonFromDaycare returned the same mon",
                   hi(r), keptSpecies)
        -- partyBefore + 1: the second legal mon gifted just above is in the
        -- party too by now. Getting this wrong would have been a green test
        -- asserting the wrong number.
        H.assertEq("the party count is back to where it was -- the gate did "
                   .. "NOT eat a legal mon", lo(r), partyBefore + 1)
    end)

D.mbStep("and the PC did not grow", D.REQ.BOX_COUNT, 0xFFFF, 0, function()
    H.assertEq("nothing was added to the PC by the on-roster withdrawal",
               D.mbResult(), boxBefore + 1)
end)

D.run()
