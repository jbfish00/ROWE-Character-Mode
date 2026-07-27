-- Prove the generated pre-evolution table is EXACTLY equivalent to the scan it
-- replaced, for every species in the game.
--
-- GetFirstEvolution used to sweep all of gEvolutionTable per walk-back step.
-- src/data/pokemon/pre_evolution.h reverses that table once at build time so the
-- lookup is O(1) per step. The generator parses evolution.h in Python, which is
-- a real risk: a parse that quietly disagrees with the C table would produce
-- wrong families, and the failure would surface far away -- as a catch gate
-- refusing a legal Pokemon, or a learnset helper returning the wrong stage.
--
-- So this does not spot-check. GetFirstEvolutionReference (the original scan) is
-- kept in level_scaling.c, and CM_REQ_VERIFY_PREEVO runs both implementations
-- over a range of species and returns the mismatch count. This sweeps the whole
-- species table in chunks -- chunked because the reference is
-- O(NUM_SPECIES * EVOS_PER_MON) per call, so a full sweep in one request would
-- run for millions of iterations inside a single mailbox pump.
--
-- Run (no CM_SAV -- drives a real new game):
--   timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/pre_evolution_e2e.lua pokeemerald.gba \
--     > /tmp/preevo.log 2>&1

local H = dofile("tools/mgba_scripts/harness.lua")
local D = dofile("tools/mgba_scripts/intro_drive.lua")(H)

local NUM_SPECIES = 1482   -- SPECIES_EGG; the C side clamps to it anyway
local CHUNK = 64           -- the mailbox caps at this
local CHUNK_TIMEOUT = 30000

D.driveNewGameCharacterMode()

local totalChecked, totalMismatch = 0, 0

for first = 0, NUM_SPECIES - 1, CHUNK do
    D.mbStep(string.format("species %d..%d agree", first, first + CHUNK - 1),
        D.REQ.VERIFY_PREEVO, first, CHUNK, function()
            local r = D.mbResult()
            local mismatches = r % 0x10000
            local checked = math.floor(r / 0x10000)
            totalChecked = totalChecked + checked
            totalMismatch = totalMismatch + mismatches
            if mismatches ~= 0 then
                H.assertTrue(string.format(
                    "species %d..%d: fast path matches the reference (%d differ)",
                    first, first + CHUNK - 1, mismatches), false)
            end
        end, CHUNK_TIMEOUT)
end

D.addStep("the sweep actually covered the species table", nil, function()
    H.log(string.format("checked %d species, %d mismatches",
                        totalChecked, totalMismatch))
    -- Guard against the sweep silently checking nothing, which would make every
    -- assertion above vacuous -- the failure mode that has bitten this repo
    -- three times.
    H.assertTrue("the sweep checked the whole species table",
                 totalChecked >= NUM_SPECIES - CHUNK)
    H.assertEq("no species disagrees between fast and reference paths",
               totalMismatch, 0)
    return true
end)

D.run()
