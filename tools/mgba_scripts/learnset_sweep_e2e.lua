-- Every species that can EXIST has a level-up learnset that TERMINATES.
--
-- PLAN.md item #12. basculegion_hang_e2e drives the three unbounded scans over
-- gLevelUpLearnsets, but only for the four Legends: Arceus species that hung
-- the game in July. tmhm_bound_e2e and pre_evolution_e2e sweep their tables
-- exhaustively; this one did not, so a FIFTH malformed row would ship.
--
-- What "malformed" means here, and why the answer cannot be read off a static
-- checker: gLevelUpLearnsets is sized [NUM_SPECIES] but is a designated-
-- initializer array, so a species with no row is a NULL POINTER. Three shipping
-- loops walk that row with a u8 index and NO bound:
--
--   src/pokemon.c:4864    MonTryLearningNewMove           (every level-up)
--   src/pokemon.c:9525    MonTryLearningNewMoveEvolution  (every evolution)
--   src/party_menu.c:2851 the field-move scan             (opening the party menu)
--
-- On hardware the NULL read returns a constant BIOS-prefetch word whose .move
-- is never LEVEL_UP_END, so the index wraps forever and the game HANGS.
--
-- tools/check_species_tables.py makes the same claim statically, by parsing the
-- source. This asserts it against the LINKED ROM, walking the pointers the
-- build actually emitted -- the two are independent, and it is the second one
-- that would notice a table the checker's parser silently misread.
--
-- ⚠️ The C side deliberately does NOT walk a NULL row: that is the defect, and
-- walking it would wedge the harness rather than report the species. It counts
-- one instead.
--
-- Run (no CM_SAV -- drives a real new game):
--   timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/learnset_sweep_e2e.lua pokeemerald.gba \
--     > /tmp/learnset_sweep.log 2>&1

local H = dofile("tools/mgba_scripts/harness.lua")
local D = dofile("tools/mgba_scripts/intro_drive.lua")(H)

local NUM_SPECIES   = 1482   -- SPECIES_EGG; the C side clamps to it anyway
local CHUNK         = 64     -- the mailbox caps at this
local CHUNK_TIMEOUT = 30000

-- Cross-check against a number another layer measured independently:
-- basculegion_hang_e2e asserts "Basculegion's learnset is 18 entries long" by
-- walking it through the SHIPPING party-menu scan. If this sweep's own walk
-- disagrees, one of the two is not walking what it says it is.
local SPECIES_BASCULEGION      = 1210
local BASCULEGION_ENTRIES      = 18

D.driveNewGameCharacterMode()

local totalChecked, totalBad, totalEntries = 0, 0, 0

for first = 0, NUM_SPECIES - 1, CHUNK do
    D.mbStep(string.format("species %d..%d terminate", first, first + CHUNK - 1),
        D.REQ.LEARNSET_SWEEP, first, CHUNK, function()
            -- entries << 16 | checked << 8 | bad
            local r = D.mbResult()
            totalBad     = totalBad     + (r % 256)
            totalChecked = totalChecked + (math.floor(r / 256) % 256)
            totalEntries = totalEntries + math.floor(r / 65536)
        end, CHUNK_TIMEOUT)
end

-- One species, on its own, so the accounting is anchored to a number this repo
-- measured through a completely different code path.
D.mbStep("Basculegion alone, cross-checked against basculegion_hang_e2e",
    D.REQ.LEARNSET_SWEEP, SPECIES_BASCULEGION, 1, function()
        local r = D.mbResult()
        H.assertEq("exactly one species was checked", math.floor(r / 256) % 256, 1)
        H.assertEq("Basculegion's row is not broken", r % 256, 0)
        H.assertEq("and it is 18 entries long, the same length the shipping "
                   .. "party-menu scan reports", math.floor(r / 65536),
                   BASCULEGION_ENTRIES)
    end, CHUNK_TIMEOUT)

D.addStep("every reachable species has a terminating learnset", nil, function()
    H.log(string.format("checked %d species with base stats, %d bad rows, "
                        .. "%d learnset entries walked",
                        totalChecked, totalBad, totalEntries))

    -- THE CLAIM.
    H.assertEq("no reachable species has a NULL or non-terminating learnset",
               totalBad, 0)

    -- ⭐ THE IN-BAND CONTROLS. "0 bad" is equally true of a sweep that checked
    -- nothing and of one whose walk was neutered to stop immediately -- the
    -- exact shape that let "an override never produced a legendary" be
    -- satisfied by a dead feature. Both are asserted separately, because a
    -- single combined counter hid precisely this in tmhm_bound_e2e's first
    -- version.
    H.assertTrue("the sweep covered the whole species table",
                 totalChecked >= NUM_SPECIES - CHUNK)
    H.assertTrue("the sweep actually WALKED the rows (entries > 10000), so a "
                 .. "walk that returns at index 0 cannot pass",
                 totalEntries > 10000)
    return true
end)

D.run()
