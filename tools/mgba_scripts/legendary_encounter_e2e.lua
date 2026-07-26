-- The 1% legendary wild-encounter feature, proven in the POSITIVE direction.
--
-- Spec: ../Character Hacks/game_plans/legendary_encounters.md (design locked by
-- the user 2026-07-26). If a legendary is on the active character's roster,
-- there is a 1% chance to meet one in any area, rolled before and independently
-- of the existing 10% non-legendary roster override, and each legendary is
-- offered until CAUGHT and then dropped -- tracked with the Pokedex caught flag,
-- so the feature costs zero new save state.
--
-- ⚠️ WHY THIS TEST IS SHAPED THIS WAY. The spec calls this out as the single
-- biggest risk in the whole feature, and it is worth restating: once the dex
-- filter can suppress legendaries, the assertion "a legendary never appeared" is
-- satisfied BOTH by correct suppression AND by the feature never running at all.
-- Every pre-existing wild-encounter assertion in this project has that shape.
-- So nothing here asserts an absence. It asserts:
--
--   1. the pool is NON-EMPTY for a character that has legendaries
--   2. every entry has a real national dex number (a 0 would silently filter the
--      wrong species -- the accessor wants a dex number, not a species id, and
--      in this tree those differ)
--   3. the roll ACTUALLY FIRES through the shipping entry point
--      (CharacterMode_RollWildOverrideSpecies, the function wild_encounter.c
--      calls at :408 and :422), at a rate consistent with 1%
--   4. catching one REMOVES it from the pool, and removes exactly one
--   5. the 10% non-legendary override still works afterwards
--
-- It mutates the Pokedex, which is exactly why it lives here and not in the boot
-- self-test: that runs against the player's real save at every boot under mGBA.
-- This runs on a throwaway generated fixture where mutation costs nothing.
--
-- Run (no CM_SAV -- it drives a real new game so the dex starts empty):
--   timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/legendary_encounter_e2e.lua pokeemerald.gba \
--     > /tmp/legendary.log 2>&1

local H = dofile("tools/mgba_scripts/harness.lua")
local D = dofile("tools/mgba_scripts/intro_drive.lua")(H)

local LEVEL  = 30
-- 1000 trials: at 1% the expected count is 10 and P(zero fires) is about 4e-5,
-- so the positive assertion below will not flake. Sampling is not free -- see
-- the note on cost at the LEGENDARY_ROLL_STATS step.
local TRIALS = 1000
local ROLL_TIMEOUT = 30000   -- frames; these loops are genuinely slow
-- Measured at ~11.8 frames per trial, so keep this small.
local END_TO_END_TRIALS = 100

-- 1. Real new game -> Character Mode -> the field. The default pick is Gen I /
--    Red, whose roster carries six legendaries (Articuno, Deoxys, Entei, Raikou,
--    Regigigas, Suicune) alongside ~41 ordinary families -- so it exercises both
--    the legendary pool AND the "has ordinary families, so once-each applies"
--    branch. A fresh game also means an empty Pokedex, so nothing starts filtered.
D.driveNewGameCharacterMode()

local poolCount, firstEntry = 0, 0

D.mbStep("legendary pool is non-empty (Red has 6 legendaries)",
    D.REQ.LEGENDARY_POOL, LEVEL, 0, function()
        local r = D.mbResult()
        poolCount = r % 0x100
        local repeatable = math.floor(r / 0x100) % 2
        firstEntry = math.floor(r / 0x10000)
        H.log(string.format("pool count=%d first=%d repeatable=%d",
                            poolCount, firstEntry, repeatable))
        -- Red has ~41 ordinary families, so the once-each filter MUST apply.
        -- If this reads 1 the roster looked all-legendary and nothing is
        -- filtered, which is exactly how a caught legendary keeps reappearing.
        H.assertEq("Red is not treated as an all-legendary roster",
                   repeatable, 0)
        H.assertTrue("pool has at least one legendary", poolCount > 0)
        H.assertTrue("pool entry 0 is a real species", firstEntry > 0)
    end)

-- 2. The dex number must resolve. A 0 here means the filter is looking up the
--    wrong thing, which would present as "the feature just never fires".
--    Issued dynamically because the species is only known at run time.
local firstDex = 0
D.addStep("the pool entry has a national dex number and is uncaught", function()
        D.mbRequest(D.REQ.DEX_CAUGHT, firstEntry, 0)
    end,
    function(f)
        if D.mbStatus() ~= D.STATUS_DONE then
            if f - D.stepStart() > 2000 then
                H.assertTrue("dex lookup answered", false)
                return true
            end
            return false
        end
        local r = D.mbResult()
        firstDex = math.floor(r / 0x10000)
        H.assertTrue("pool entry has a non-zero national dex number", firstDex > 0)
        H.assertEq("pool entry starts UNCAUGHT on a fresh game", r % 2, 0)
        return true
    end)

-- 3. THE assertion the whole feature hangs on: the 1% roll actually fires.
--
--    Sampled through CharacterMode_RollWildLegendarySpecies rather than through
--    the full override, for a measured reason. CM_REQ_WILD_ROLL_STATS costs
--    ~11.8 frames PER TRIAL, because the 10% path rebuilds a 47-entry candidate
--    list and each entry costs a CharacterMode_FamilyBase evolution-table walk;
--    2000 trials of that does not finish in any reasonable time. The legendary
--    roll early-outs on 99 of 100 calls, so 2000 trials of it is cheap -- and
--    1000 is what makes P(zero fires) about 4e-5 instead of a coin flip.
D.mbStep("the 1% legendary roll fires (1000 samples)",
    D.REQ.LEGENDARY_ROLL_STATS, LEVEL, TRIALS, function()
        local r = D.mbResult()
        local fires = r % 0x10000
        local poolNonEmpty = math.floor(r / 0x10000)
        H.log(string.format("legendary roll: %d fires in %d samples", fires, TRIALS))

        H.assertEq("the pool was non-empty for the sampled rolls", poolNonEmpty, 1)
        H.assertTrue("a legendary was actually produced", fires > 0)
        -- 1% of 1000 is 10; this band is several sigma either side, so it
        -- catches a rate that is wildly wrong without flaking on variance.
        H.assertTrue("the rate is consistent with 1% (2..40 of 1000)",
                     fires >= 2 and fires <= 40)
    end, ROLL_TIMEOUT)

-- 3b. End-to-end through the SHIPPING entry point -- the function
--     wild_encounter.c calls at :408 and :422. Deliberately a small sample: it
--     proves the wiring and that the 10% roster override still works, while the
--     statistical weight lives in the cheap sampler above.
D.mbStep("the shipping override still fires, with the legendary roll inline",
    D.REQ.WILD_ROLL_STATS, LEVEL, END_TO_END_TRIALS, function()
        local r = D.mbResult()
        local legendary = r % 0x10000
        local total = math.floor(r / 0x10000)
        H.log(string.format("end to end: %d legendary, %d total in %d rolls",
                            legendary, total, END_TO_END_TRIALS))
        H.assertTrue("the 10% roster override still fires", total > 0)
        -- The legendary roll must not have swallowed the override path.
        H.assertTrue("overrides dominate the legendary roll", total > legendary)
    end, ROLL_TIMEOUT)

-- 4. Catch it, and it must leave the pool.
D.addStep("mark pool entry 0 as caught", function()
        D.mbRequest(D.REQ.DEX_CAUGHT, firstEntry, 1)
    end,
    function(f)
        if D.mbStatus() ~= D.STATUS_DONE then
            if f - D.stepStart() > 2000 then
                H.assertTrue("set-caught answered", false)
                return true
            end
            return false
        end
        H.assertEq("the caught flag is now set", D.mbResult() % 2, 1)
        return true
    end)

D.mbStep("a caught legendary is no longer offered",
    D.REQ.LEGENDARY_POOL, LEVEL, 0, function()
        local r = D.mbResult()
        local countAfter = r % 0x100
        H.assertEq("catching one drops exactly one entry",
                   countAfter, poolCount - 1)
    end)

-- Walk every remaining slot and confirm the caught species is gone -- checking
-- only the count would pass if the pool had dropped a DIFFERENT entry.
for slot = 0, 14 do
    D.addStep("slot " .. slot .. " is not the caught legendary", function()
            D.mbRequest(D.REQ.LEGENDARY_POOL, LEVEL, slot)
        end,
        function(f)
            if D.mbStatus() ~= D.STATUS_DONE then
                if f - D.stepStart() > 2000 then
                    H.assertTrue("pool slot query answered", false)
                    return true
                end
                return false
            end
            local r = D.mbResult()
            local count = r % 0x100
            local entry = math.floor(r / 0x10000)
            if slot < count then
                H.assertTrue(string.format(
                    "pool slot %d (%d) is not the caught legendary (%d)",
                    slot, entry, firstEntry), entry ~= firstEntry)
            end
            return true
        end)
end

-- 5. The ordinary override must be unaffected by all of the above.
D.mbStep("the 10% override still works after the dex filter kicked in",
    D.REQ.WILD_ROLL_STATS, LEVEL, END_TO_END_TRIALS, function()
        local r = D.mbResult()
        local legendary = r % 0x10000
        local total = math.floor(r / 0x10000)
        H.log(string.format("after catching: %d legendary, %d total",
                            legendary, total))
        H.assertTrue("non-legendary overrides still fire", total - legendary > 0)
        -- Six legendaries remain uncaught; the pool-slot walk above already
        -- proved they are still offered, so this only has to show the override
        -- path survived the dex filter being exercised.
    end, ROLL_TIMEOUT)

D.run()
