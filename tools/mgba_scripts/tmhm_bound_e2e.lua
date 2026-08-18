-- Prove the party menu's three field-move lookups are BOUNDED, for every
-- species in the game.
--
-- ShowPartyMenu calls CanMonLearnTMHM twice (Fly, Dig) and CanLearnTutorMove
-- once (Cut) on the highlighted slot, to decide which field moves to offer.
-- Both accessors indexed a designated-initializer table by raw species id and
-- then WALKED the returned pointer until they happened to find 0xFF:
--
--     learnableMoves = gTMHMLearnsets[formSpeciesId];
--     while (*learnableMoves != 0xFF) ...
--
-- gTMHMLearnsets ended at its highest designator (1199 elements) and
-- sTutorLearnsets at 1207, against NUM_SPECIES 1482. 49 species on this
-- branch's own rosters sat past that end -- ⚠️ Nemona's FIXED starter is
-- SPECIES_PAWMI, id 1245, granted at level 10 in the intro -- so opening the
-- party menu read an arbitrary ROM word and walked it as a pointer. 813 more
-- species were in-bounds with no row at all, i.e. a NULL walked the same way.
--
-- Fixed 2026-08-09 by sizing both tables to [NUM_SPECIES] and bound- plus
-- NULL-checking all three accessors. Nothing in the suite reached them, which
-- is why the defect survived an 18/18 green run.
--
-- ⚠️ THE PRIMARY ASSERTION IS THAT THE SWEEP RETURNS AT ALL -- the same shape as
-- basculegion_hang_e2e and the July hang. An unbounded walk does not report a
-- wrong answer, it never answers: the emulator wedges inside the loop and every
-- later step dies on its deadline.
--
-- Run (no CM_SAV -- drives a real new game):
--   timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/tmhm_bound_e2e.lua pokeemerald.gba \
--     > /tmp/tmhm.log 2>&1

local H = dofile("tools/mgba_scripts/harness.lua")
local D = dofile("tools/mgba_scripts/intro_drive.lua")(H)

local NUM_SPECIES   = 1482   -- SPECIES_EGG; the C side clamps to it anyway
local CHUNK         = 256    -- the mailbox caps at this
local CHUNK_TIMEOUT = 30000

local PAWMI = 1245           -- Nemona's fixed starter, past the OLD array end

D.driveNewGameCharacterMode()

local totalChecked, totalTmhm, totalTutor = 0, 0, 0

for first = 0, NUM_SPECIES - 1, CHUNK do
    D.mbStep(string.format("species %d..%d answer", first, first + CHUNK - 1),
        D.REQ.TMHM_PROBE, first, CHUNK, function()
            -- checked << 20 | tutorHits << 10 | tmhmHits
            local r = D.mbResult()
            totalTmhm    = totalTmhm  + (r % 1024)
            totalTutor   = totalTutor + (math.floor(r / 1024) % 1024)
            totalChecked = totalChecked + math.floor(r / 1048576)
        end, CHUNK_TIMEOUT)
end

-- The exact reachable case, on its own, so a failure names it rather than
-- pointing at a range.
D.addStep("Nemona's starter Pawmi is reached by the sweep above", nil, function()
    H.assertTrue(string.format(
        "the sweep covered SPECIES_PAWMI (%d) -- the id that made this "
        .. "reachable from the intro", PAWMI), totalChecked > PAWMI)
    return true
end)

D.addStep("the sweep covered the species table and the accessors still work", nil, function()
    H.log(string.format("checked %d species, %d TMHM hits, %d tutor hits",
                        totalChecked, totalTmhm, totalTutor))

    -- Guard against the sweep silently checking nothing, which would make
    -- "it returned" vacuous -- the failure shape this repo has shipped five
    -- times.
    H.assertTrue("the sweep checked the whole species table",
                 totalChecked >= NUM_SPECIES - CHUNK)

    -- ⭐ THE IN-BAND CONTROL, and the reason this test is not just "it did not
    -- hang". Bounding an unbounded accessor is one edit away from neutering it:
    -- `return FALSE` at the top is perfectly safe, never wedges, and silently
    -- removes Fly, Dig and Cut from every party menu in the game. A build where
    -- the guards over-reject answers just as promptly as a correct one.
    --
    -- ⚠️ ASSERT THE TWO ACCESSORS SEPARATELY. The first version of this test
    -- summed them into one counter, and the commit-time negative control --
    -- `return FALSE` at the top of CanSpeciesLearnTMHM -- left that counter at
    -- 265 because CanLearnTutorMove was still answering. The run did fail, but
    -- on unrelated intro-drive steps rather than on the control that was
    -- supposed to catch it, which is a control that does not control anything.
    H.assertTrue("CanSpeciesLearnTMHM still returns TRUE for some species -- "
                 .. "the bound did not neuter it", totalTmhm > 0)
    H.assertTrue("CanLearnTutorMove still returns TRUE for some species -- "
                 .. "the bound did not neuter it", totalTutor > 0)
    return true
end)

D.run()
