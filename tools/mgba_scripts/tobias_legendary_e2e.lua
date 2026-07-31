-- tobias_legendary_e2e.lua -- the all-legendary-roster exemption.
--
-- Closes playthrough checklist item 15: "Tobias is the exception -- his roster
-- is Darkrai + Latios and nothing else, so his legendaries stay REPEATABLE
-- rather than retiring on catch."
--
-- Everything else in this suite proves the opposite rule. The 1% legendary
-- encounter is normally "offered until caught": catch one and it leaves the
-- pool, tracked by the Pokedex caught flag so it costs no save state.
-- legendary_encounter_e2e asserts exactly that, as Red.
--
-- Tobias breaks it, and has to. His roster is ENTIRELY legendary, so applying
-- the once-each filter would empty his wild pool the moment he caught both --
-- and he has nothing else to catch. CharacterMode_BuildLegendaryPool therefore
-- reports a `repeatable` exemption for an all-legendary roster and skips the
-- filter. He is the only character in ROWE in that state.
--
-- ⚠️ THE ASSERTION SHAPE HERE IS THE DANGEROUS ONE, so read this before
-- editing. "The pool still has 2 entries after catching one" passes when the
-- exemption works -- and ALSO passes if `repeatable` were hardwired TRUE, or if
-- the catch never registered, or if the pool were never filtered by anything.
-- So this run carries its own contrast: it asks the SAME question as Red
-- immediately afterwards and requires the opposite answer. If the exemption
-- stops being per-character, the Red half goes red. A test that only ever asks
-- the exempt case cannot tell an exemption from a no-op.
--
-- Run:
--   timeout 300 <mgba-headless> \
--       --script tools/mgba_scripts/tobias_legendary_e2e.lua pokeemerald.gba

local H = dofile("tools/mgba_scripts/harness.lua")
local D = dofile("tools/mgba_scripts/intro_drive.lua")(H)

local TOBIAS = 233   -- 1-based index into gCharacters
local RED    = 1
local LEVEL  = 20    -- area level the pool is built for; any sane value works

local SPECIES_DARKRAI = 491
local SPECIES_LATIOS  = 381

-- Unpack CM_REQ_LEGENDARY_POOL: entry<<16 | repeatable<<8 | count.
local function unpackPool(r)
    return r % 0x100,                        -- count
           math.floor(r / 0x100) % 2,        -- repeatable exemption
           math.floor(r / 0x10000)           -- the requested entry
end

D.driveNewGameCharacterMode()

-- ------------------------------------------------------------------- Tobias

D.mbStep("become Tobias", D.REQ.SET_CHARACTER, TOBIAS, 0, function()
    H.assertEq("InCharacterMode() after SET_CHARACTER(Tobias)", D.mbResult(), 1)
end)

local tobiasCount, entry0, entry1 = 0, 0, 0

D.mbStep("Tobias's pool is exempt from the once-each filter",
    D.REQ.LEGENDARY_POOL, LEVEL, 0, function()
        local count, repeatable, entry = unpackPool(D.mbResult())
        tobiasCount, entry0 = count, entry
        H.log(string.format("Tobias pool count=%d repeatable=%d entry0=%d",
                            count, repeatable, entry))
        -- The exemption itself. This is the line the 2026-07-28 ruling created.
        H.assertEq("Tobias IS treated as an all-legendary roster", repeatable, 1)
        H.assertEq("his pool is exactly his two legendaries", count, 2)
        H.assertTrue("pool entry 0 is a real species", entry > 0)
    end)

D.mbStep("his second pool entry", D.REQ.LEGENDARY_POOL, LEVEL, 1, function()
    local _, _, entry = unpackPool(D.mbResult())
    entry1 = entry
    -- Checked as a SET, because which one comes first is not the contract.
    local got = { [entry0] = true, [entry1] = true }
    H.assertTrue("the pool is exactly {Darkrai, Latios} (got " ..
                 entry0 .. ", " .. entry1 .. ")",
                 got[SPECIES_DARKRAI] == true and got[SPECIES_LATIOS] == true)
end)

-- Issued as a raw request rather than mbStep, because the species is only
-- known at run time (it comes out of the pool query above).
D.addStep("mark entry 0 CAUGHT in the Pokedex", function()
        D.mbRequest(D.REQ.DEX_CAUGHT, entry0, 1)
    end,
    function(f)
        if D.mbStatus() ~= D.STATUS_DONE then
            if f - D.stepStart() > 2000 then
                H.assertTrue("DEX_CAUGHT answered for entry 0", false)
                return true
            end
            return false
        end
        local r = D.mbResult()
        H.assertTrue("entry 0 has a real national dex number",
                     math.floor(r / 0x10000) > 0)
        -- Proves the catch actually registered. Without this the "pool
        -- unchanged" assertion below would also pass on a build where the
        -- catch silently did nothing.
        H.assertEq("entry 0 now reads as CAUGHT", r % 2, 1)
        return true
    end)

D.mbStep("catching one does NOT retire it -- the pool is unchanged",
    D.REQ.LEGENDARY_POOL, LEVEL, 0, function()
        local count, repeatable, entry = unpackPool(D.mbResult())
        H.log(string.format("after catch: count=%d repeatable=%d entry0=%d",
                            count, repeatable, entry))
        -- For Red this number drops by exactly one. For Tobias it must not
        -- move, or he runs out of anything to meet in the wild.
        H.assertEq("Tobias's pool is STILL 2 after catching one",
                   count, tobiasCount)
        H.assertEq("the exemption still holds after the catch", repeatable, 1)
        H.assertTrue("entry 0 is still one of his two",
                     entry == SPECIES_DARKRAI or entry == SPECIES_LATIOS)
    end)

-- --------------------------------------------------- the in-band contrast
--
-- Same question, different character, opposite required answer. Without this
-- the run above passes just as happily on a build where `repeatable` is
-- hardwired TRUE for everybody -- which would silently make every character's
-- legendaries farmable and break the rule the feature exists to enforce.

D.mbStep("become Red", D.REQ.SET_CHARACTER, RED, 0, function()
    H.assertEq("InCharacterMode() after SET_CHARACTER(Red)", D.mbResult(), 1)
end)

D.mbStep("CONTRAST: Red is NOT exempt, so the flag is per-character",
    D.REQ.LEGENDARY_POOL, LEVEL, 0, function()
        local count, repeatable, _ = unpackPool(D.mbResult())
        H.log(string.format("Red pool count=%d repeatable=%d", count, repeatable))
        -- If this reads 1, the exemption is not being computed from the roster
        -- and every assertion in the Tobias half above is meaningless.
        H.assertEq("Red is NOT treated as an all-legendary roster", repeatable, 0)
        H.assertTrue("Red still has a non-empty legendary pool", count > 0)
        -- Red has many ordinary families; if his pool were the same size as
        -- Tobias's two, the pool builder is not reading the roster at all.
        H.assertTrue("Red's pool differs from Tobias's two-entry pool",
                     count ~= tobiasCount)
    end)

D.run()
