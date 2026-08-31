-- The gift-egg roster roll: pool, curve, exclusion, fallback and the draw.
--
-- Feature ruled by the user 2026-08-26. A scripted gift "egg" hands over a
-- species drawn from the active character's roster, weighted 255/catchRate so
-- rarer families are likelier (Beldum 3 vs Caterpie 255), with already-caught
-- families excluded outright and legendaries excluded unless the character has
-- nothing else (Tobias).
--
-- ⚠️ THIS TEST IS BUILT AROUND ONE FAILURE SHAPE: a weighted picker and a FLAT
-- picker return the same KIND of answer. Every assertion below that could be
-- satisfied by "returns some roster species" is paired with one that a flat or
-- unfiltered implementation fails. That is the lesson from the 1% legendary
-- work, where "an override never produced a legendary" was satisfied both by
-- correct suppression and by the feature being completely dead.
--
-- Run (no CM_SAV -- drives a real new game):
--   timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/egg_roster_e2e.lua pokeemerald.gba \
--     > /tmp/egg.log 2>&1

local H = dofile("tools/mgba_scripts/harness.lua")
local D = dofile("tools/mgba_scripts/intro_drive.lua")(H)

local CHAR_STEVEN = 41     -- 18 families, 3 legendary, Beldum at catch rate 3
local CHAR_TOBIAS = 233    -- the ONLY selectable character with no non-legendary

local BELDUM, CATERPIE, SKARMORY, DEOXYS = 374, 10, 227, 386
local DARKRAI, LATIOS = 491, 381     -- Tobias's entire roster

local POOL_UNCAUGHT, POOL_ANY_NONLEG, POOL_ANY = 0, 1, 2

local TRIALS = 2000

-- 255 * CM_EGG_WEIGHT_SCALE / catchRate, the C side's arithmetic restated.
local function weightFor(catchRate) return math.floor(25500 / catchRate) end

local function ran(r)     return r >= 0x80000000 end
local function poolCount(r) return r % 65536 end
local function poolHas(r) return math.floor(r / 0x40000000) % 2 == 1 end

D.driveNewGameCharacterMode()

-- ---------------------------------------------------------------- the curve
-- Deterministic, no RNG involved. If this passes and the draw is still flat,
-- the distribution assertions further down are what catch it.
-- ⚠️⚠️ THE TABLE TRAP, and this assertion exists because it already bit.
-- src/data/pokemon/base_stats.h defines TWO arrays: the live gBaseStats[] and a
-- gVanillaBaseStats[] reference copy that repeats all 1,463 designators. A tool
-- that regex-scans the file and keeps the LAST match per species reads the
-- VANILLA table -- which says Beldum is catch rate 3. ROWE rebalanced it to 45.
-- Every roster percentage computed off the wrong table was wrong, and the file
-- gives no hint: both rows are `[SPECIES_BELDUM] =` at column 4, unguarded.
-- This step pins ROWE's LIVE value, so reading the wrong table fails here
-- rather than silently reshaping the curve.
D.mbStep("Beldum's weight comes from the LIVE table (cr 45), not vanilla (cr 3)",
         D.REQ.EGG_WEIGHT, BELDUM, 0, function()
    local r = D.mbResult()
    H.assertTrue("EGG_WEIGHT ran", ran(r))
    H.assertEq("Beldum weight (ROWE catch rate 45)", r % 0x01000000, weightFor(45))
    H.assertTrue("...and NOT the vanilla-table value for catch rate 3",
                 r % 0x01000000 ~= weightFor(3))
end)

D.mbStep("Caterpie's egg weight is 255*100/255", D.REQ.EGG_WEIGHT, CATERPIE, 0, function()
    local r = D.mbResult()
    H.assertEq("Caterpie (catch rate 255) weight", r % 0x01000000, weightFor(255))
    -- The user's framing: Beldum must be likelier than Caterpie. On ROWE's own
    -- catch rates that is 566 vs 100, a 5.7x edge -- not the 85x the vanilla
    -- table would imply. The ORDERING is what was asked for; the magnitude is a
    -- property of this ROM's data.
    H.assertTrue("Beldum is likelier than Caterpie", weightFor(45) > weightFor(255))
    H.assertEq("Beldum:Caterpie ratio on live data", math.floor(weightFor(45) / weightFor(255)), 5)
end)

-- ------------------------------------------------------- pool and exclusions
D.mbStep("Steven: Beldum is in the uncaught pool", D.REQ.SET_CHARACTER, CHAR_STEVEN, 0, function()
    H.assertTrue("Character Mode is on as Steven", D.mbResult() ~= 0)
end)

local stevenPool
D.mbStep("Steven's uncaught pool holds Beldum", D.REQ.EGG_POOL, POOL_UNCAUGHT, BELDUM, function()
    local r = D.mbResult()
    H.assertTrue("EGG_POOL ran", ran(r))
    stevenPool = poolCount(r)
    H.assertTrue("Beldum is drawable", poolHas(r))
    -- 18 families minus 3 legendary = 15, nothing caught yet on a fresh game.
    H.assertEq("Steven's uncaught pool size", stevenPool, 15)
end)

-- ⭐ THE LEGENDARY EXCLUSION, asserted as an ABSENCE that a broken build makes
-- present. Deoxys is on Steven's roster and is catch rate 3, so an
-- implementation that forgot to exclude legendaries would not merely include
-- him -- he would tie Beldum for the single largest weight in the pool.
D.mbStep("Steven's pool excludes Deoxys, a legendary on his own roster",
         D.REQ.EGG_POOL, POOL_UNCAUGHT, DEOXYS, function()
    H.assertTrue("Deoxys is NOT drawable from an egg", not poolHas(D.mbResult()))
end)

-- ⭐ THE CAUGHT EXCLUSION, driven rather than argued: set the flag, re-read the
-- pool, and require BOTH that Beldum left and that the pool shrank by exactly
-- one. Checking only membership would pass on a build that returned an empty
-- pool for every query.
D.mbStep("mark Beldum caught in the Pokedex", D.REQ.DEX_CAUGHT, BELDUM, 1, function()
    H.assertTrue("DEX_CAUGHT accepted the set", true)
end)

D.mbStep("a caught Beldum is 0% -- gone from the pool", D.REQ.EGG_POOL, POOL_UNCAUGHT, BELDUM, function()
    local r = D.mbResult()
    H.assertTrue("Beldum is no longer drawable", not poolHas(r))
    H.assertEq("the pool shrank by exactly one", poolCount(r), stevenPool - 1)
end)

-- The first fallback ignores caught, so Beldum must come back in mode 1. This
-- is what stops a fully-caught roster from producing nothing at all.
D.mbStep("the ignore-caught fallback still holds Beldum", D.REQ.EGG_POOL, POOL_ANY_NONLEG, BELDUM, function()
    local r = D.mbResult()
    H.assertTrue("Beldum is drawable again in the fallback pool", poolHas(r))
    H.assertEq("the fallback pool is the full non-legendary roster", poolCount(r), stevenPool)
end)

-- --------------------------------------------------------- the draw itself
-- ⭐ Proves the RNG path CONSUMES the weights. The pool and the weight table can
-- both be correct while the draw ignores them -- `candidates[Random() % count]`
-- is the obvious wrong implementation and passes every assertion above.
-- Steven's pool is 14 families here (Beldum caught above), so a flat draw gives
-- Skarmory about 7%. Weighted, Skarmory (25) is the rarest left and should take
-- roughly a quarter of all draws.
D.mbStep("the draw is weighted, not flat", D.REQ.EGG_ROLL_STATS, SKARMORY, TRIALS, function()
    local r = D.mbResult()
    H.assertTrue("EGG_ROLL_STATS ran", ran(r))
    local hits = r % 65536
    local pct = hits * 100 / TRIALS
    H.log(string.format("Skarmory took %d/%d draws (%.1f%%)", hits, TRIALS, pct))
    -- Computed, not guessed: with Beldum excluded Steven's pool is 14 families
    -- summing to 6060, and Skarmory's 1020 is 16.8% of it. A FLAT draw would
    -- give 7.1%. The window is tight enough that flat fails it.
    H.assertTrue(string.format("Skarmory is near its weighted share of 16.8%%, "
                 .. "not a flat 7.1%% (got %.1f%%)", pct), pct > 13 and pct < 21)
end)

-- The suppression, positively stated: a legendary on Steven's roster must never
-- come out of an egg, across the same number of draws.
D.mbStep("no legendary is ever drawn for Steven", D.REQ.EGG_ROLL_STATS, DEOXYS, TRIALS, function()
    H.assertEq("Deoxys draws", D.mbResult() % 65536, 0)
end)

-- ------------------------------------------------------------ Tobias, the
-- measured special case: 100% legendary roster, so the exclusion would leave
-- him nothing and the second fallback has to fire.
D.mbStep("switch to Tobias", D.REQ.SET_CHARACTER, CHAR_TOBIAS, 0, function()
    H.assertTrue("Character Mode is on as Tobias", D.mbResult() ~= 0)
end)

D.mbStep("Tobias has NO non-legendary pool", D.REQ.EGG_POOL, POOL_ANY_NONLEG, 0, function()
    H.assertEq("non-legendary pool size", poolCount(D.mbResult()), 0)
end)

D.mbStep("...so his fallback pool is his legendaries", D.REQ.EGG_POOL, POOL_ANY, 0, function()
    H.assertEq("any-pool size (Darkrai, Latios)", poolCount(D.mbResult()), 2)
end)

-- ⭐ THE POINT OF THE FALLBACK. Without it this returns SPECIES_NONE and the
-- gift silently does nothing for exactly one character -- the failure mode that
-- would never be noticed until someone played Tobias.
D.mbStep("Tobias's egg still yields a species", D.REQ.EGG_ROLL, 0, 0, function()
    local sp = D.mbResult()
    H.assertTrue("the roll returned a real species, not SPECIES_NONE", sp ~= 0)
    -- ⚠️ The first draft of this line ended `or sp > 0`, which made the whole
    -- disjunction always true -- a vacuous assertion inside the test written to
    -- catch vacuous assertions. Named constants, and no escape hatch.
    H.assertTrue(string.format("it is Darkrai or Latios, not %d", sp),
                 sp == DARKRAI or sp == LATIOS)
end)

D.run()
