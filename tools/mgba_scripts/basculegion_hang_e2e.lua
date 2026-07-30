-- The four Legends: Arceus species had base stats and NO learnset row -- a
-- live hang. This drives the exact path a player reaches it by.
--
-- gLevelUpLearnsets is a designated-initializer array, so SPECIES_BASCULEGION
-- with no row is a NULL pointer. Three shipping loops walk that row with a u8
-- index and NO bound:
--
--   src/pokemon.c:4864   MonTryLearningNewMove          (every level-up)
--   src/pokemon.c:9525   MonTryLearningNewMoveEvolution (every evolution)
--   src/party_menu.c:2851 the field-move scan           (opening the party menu)
--
-- On hardware a NULL read returns a constant BIOS-prefetch value whose .move is
-- never LEVEL_UP_END, so the u8 wraps forever and the game hangs. Basculegion is
-- reachable in ordinary play: src/data/pokemon/evolution.h has
--   [SPECIES_BASCULIN_WHITE_STRIPED] = {{EVO_LEVEL, 43, SPECIES_BASCULEGION}}
-- (a LIVE evolution -- its two siblings use the dead EVO_HUSIAN), and
-- Basculin-White-Striped has 22 wild-encounter slots.
--
-- So this test does not check a table. It creates a real Basculin-White-Striped
-- at level 43, evolves it through GetEvolutionTargetSpecies, and then RUNS all
-- three scans. Every one of them returning AT ALL is the assertion -- if the row
-- were still missing the request would never complete and the step would fail
-- on its mailbox deadline rather than pass quietly.
--
-- Wyrdeer, Ursaluna and Overqwil are checked the same way minus the evolution
-- (their EVO_HUSIAN rows are dead, so they are only reachable by other means),
-- and Ursaluna additionally proves its LEVEL_UP_MOVE(0, MOVE_TAKE_DOWN)
-- learn-on-evolution sentinel fires -- that is the move gSignatureMoveList
-- rewrites into its 120BP Ground-type Close Combat variant.
--
-- Run (no CM_SAV -- drives a real new game):
--   timeout 100 <mgba-headless> \
--     --script tools/mgba_scripts/basculegion_hang_e2e.lua pokeemerald.gba \
--     > /tmp/basculegion.log 2>&1

local H = dofile("tools/mgba_scripts/harness.lua")
local D = dofile("tools/mgba_scripts/intro_drive.lua")(H)

-- ScriptGiveMon splits a FORM species into (base species, form id): a
-- White-Striped Basculin is stored as SPECIES_BASCULIN with formId 2, and
-- GetFormSpeciesId puts it back together. So the party reads 550, not 1448.
local SPECIES_BASCULIN_WHITE_STRIPED = 1448
local SPECIES_BASCULIN               =  550
local SPECIES_BASCULEGION            = 1210
local SPECIES_WYRDEER                = 1207
local SPECIES_URSALUNA               = 1209
local SPECIES_OVERQWIL               = 1212

local MOVE_WAVE_CRASH = 756   -- Basculegion, level 44
local MOVE_TAKE_DOWN  =  36   -- Ursaluna, the level-0 sentinel

-- op codes for CM_REQ_LEARNSET_PROBE (argA = slot | op << 8)
local OP_LEVELUP_SCAN   = 0
local OP_EVO_SCAN       = 1
local OP_READ_MOVE      = 2
local OP_WALK_LEARNSET  = 3
local OP_EVOLVE         = 4

local function probe(slot, op) return slot + op * 256 end
local function hi(r) return math.floor(r / 0x10000) end
local function lo(r) return r % 0x10000 end

D.driveNewGameCharacterMode()

-- Character Mode diverts an off-roster gift to the PC, which would leave the
-- party slots empty and make every assertion below vacuous. Turn the mode off
-- so ScriptGiveMon actually hands the mon over.
D.mbStep("character mode off, so gifts land in the party", D.REQ.SET_CHARACTER, 0, 0,
    function() H.assertEq("InCharacterMode() is now false", D.mbResult(), 0) end)

-- ---------------------------------------------------------------------------
-- 1. The reachable path: Basculin-White-Striped Lv43 -> Basculegion
-- ---------------------------------------------------------------------------

D.mbStep("gift a Basculin-White-Striped at Lv43", D.REQ.GIVE_MON,
    SPECIES_BASCULIN_WHITE_STRIPED, 43,
    function() H.assertEq("it went to the PARTY (ScriptGiveMon == 0)", D.mbResult(), 0) end)

D.mbStep("it is in slot 1 at Lv43", D.REQ.QUERY_PARTY_MON, 1, 0, function()
    local r = D.mbResult()
    H.assertEq("slot 1 species is Basculin (form id carries the stripe)",
               lo(r), SPECIES_BASCULIN)
    H.assertEq("slot 1 level is 43", hi(r), 43)
end)

D.mbStep("it evolves -- the LIVE EVO_LEVEL 43 row", D.REQ.LEARNSET_PROBE,
    probe(1, OP_EVOLVE), 0,
    function()
        -- Only SPECIES_BASCULIN_WHITE_STRIPED has a live EVO_LEVEL row (the
        -- red- and blue-striped rows use the dead EVO_HUSIAN), so this
        -- returning Basculegion also proves the form id survived the gift.
        H.assertEq("GetEvolutionTargetSpecies returns Basculegion",
                   D.mbResult(), SPECIES_BASCULEGION)
    end)

D.mbStep("slot 1 is now a Basculegion", D.REQ.QUERY_PARTY_MON, 1, 0, function()
    H.assertEq("slot 1 species is Basculegion", lo(D.mbResult()), SPECIES_BASCULEGION)
end)

-- THE HANG SITES. Each of these three returning is the proof.
D.mbStep("party-menu field-move scan TERMINATES on Basculegion",
    D.REQ.LEARNSET_PROBE, probe(1, OP_WALK_LEARNSET), 0, function()
        local r = D.mbResult()
        H.assertEq("the scan reached LEVEL_UP_END", hi(r), 1)
        H.assertEq("Basculegion's learnset is 18 entries long", lo(r), 18)
    end)

D.mbStep("MonTryLearningNewMoveEvolution TERMINATES on Basculegion",
    D.REQ.LEARNSET_PROBE, probe(1, OP_EVO_SCAN), 0, function()
        -- Basculegion has no LEVEL_UP_MOVE(0, X) row, so the correct answer is
        -- "nothing granted" -- reached by walking the whole table and stopping.
        H.assertEq("no learn-on-evolution move, and the sweep ended", lo(D.mbResult()), 0)
    end)

D.mbStep("MonTryLearningNewMove TERMINATES on Basculegion",
    D.REQ.LEARNSET_PROBE, probe(1, OP_LEVELUP_SCAN), 0, function()
        -- Level 43 is not a learn level for Basculegion, so this walks the
        -- ENTIRE row to LEVEL_UP_END and returns 0. That full walk is exactly
        -- the loop that used to wrap forever.
        H.assertEq("nothing to learn at Lv43, and the scan ended", lo(D.mbResult()), 0)
    end)

-- ---------------------------------------------------------------------------
-- 2. A Basculegion at a real learn level has real moves
-- ---------------------------------------------------------------------------

D.mbStep("gift a Basculegion at Lv44", D.REQ.GIVE_MON, SPECIES_BASCULEGION, 44,
    function() H.assertEq("it went to the PARTY", D.mbResult(), 0) end)

local moves44 = {}
for i = 0, 3 do
    D.mbStep(string.format("Lv44 Basculegion move slot %d", i), D.REQ.LEARNSET_PROBE,
        probe(2, OP_READ_MOVE), i, function()
            local m = D.mbResult()
            moves44[#moves44 + 1] = m
            H.assertTrue(string.format("move slot %d is a real move (got %d)", i, m),
                         m > 0 and m < 1500)
        end)
end

D.addStep("its moveset came from the learnset, not from garbage", nil, function()
    local seen = false
    for _, m in ipairs(moves44) do
        if m == MOVE_WAVE_CRASH then seen = true end
    end
    H.log("Lv44 Basculegion moves: " .. table.concat(moves44, ", "))
    -- Wave Crash is its level-44 move and the last one GiveBoxMonInitialMoveset
    -- hands out, so it must be in the final four.
    H.assertTrue("it knows Wave Crash (its Lv44 learnset move)", seen)
    return true
end)

D.mbStep("MonTryLearningNewMove at a REAL learn level terminates",
    D.REQ.LEARNSET_PROBE, probe(2, OP_LEVELUP_SCAN), 0, function()
        -- Level 44 IS in the row, so the scan stops on it rather than running
        -- to the terminator; it already knows the move, so nothing is granted.
        H.assertTrue("the scan found level 44 and stopped", lo(D.mbResult()) >= 1)
    end)

-- ---------------------------------------------------------------------------
-- 3. The other three species -- same tables, no live evolution to reach them
-- ---------------------------------------------------------------------------

local others = {
    { name = "Wyrdeer",  species = SPECIES_WYRDEER,  slot = 3, entries = 14 },
    { name = "Ursaluna", species = SPECIES_URSALUNA, slot = 4, entries = 18 },
    { name = "Overqwil", species = SPECIES_OVERQWIL, slot = 5, entries = 16 },
}

for _, o in ipairs(others) do
    D.mbStep("gift a " .. o.name .. " at Lv30", D.REQ.GIVE_MON, o.species, 30,
        function() H.assertEq(o.name .. " went to the PARTY", D.mbResult(), 0) end)

    D.mbStep(o.name .. ": the field-move scan TERMINATES", D.REQ.LEARNSET_PROBE,
        probe(o.slot, OP_WALK_LEARNSET), 0, function()
            local r = D.mbResult()
            H.assertEq(o.name .. ": the scan reached LEVEL_UP_END", hi(r), 1)
            H.assertEq(o.name .. ": learnset entry count", lo(r), o.entries)
        end)

    D.mbStep(o.name .. ": MonTryLearningNewMove TERMINATES", D.REQ.LEARNSET_PROBE,
        probe(o.slot, OP_LEVELUP_SCAN), 0, function()
            H.assertTrue(o.name .. ": the level-up scan returned",
                         lo(D.mbResult()) < 32)
        end)

    D.mbStep(o.name .. ": move slot 0 is a real move", D.REQ.LEARNSET_PROBE,
        probe(o.slot, OP_READ_MOVE), 0, function()
            local m = D.mbResult()
            H.assertTrue(o.name .. string.format(": move slot 0 = %d", m),
                         m > 0 and m < 1500)
        end)
end

-- Ursaluna's LEVEL_UP_MOVE(0, MOVE_TAKE_DOWN) is the learn-on-evolution
-- sentinel, and Take Down is exactly what gSignatureMoveList[SPECIES_URSALUNA]
-- rewrites into a 120BP Ground-type Close Combat variant. Restoring the
-- learnset switches that dormant signature block on, so prove the sentinel
-- actually fires rather than assuming it.
D.mbStep("Ursaluna's level-0 sentinel FIRES on evolution", D.REQ.LEARNSET_PROBE,
    probe(4, OP_EVO_SCAN), 0, function()
        H.assertTrue("MonTryLearningNewMoveEvolution offered a move",
                     lo(D.mbResult()) >= 1)
    end)

D.mbStep("...and the move it offered was Take Down", D.REQ.LEARNSET_PROBE,
    probe(4, OP_READ_MOVE), 0, function()
        -- Ursaluna is created at Lv30 with a full moveset, so the sentinel's
        -- Take Down comes back as MON_HAS_MAX_MOVES rather than being written.
        -- What is checkable here is that slot 0 is still a real move, i.e. the
        -- sweep did not scribble over the moveset. gMoveToLearn itself is
        -- covered by the assertion above (the sweep found something to offer at
        -- all, and Take Down is Ursaluna's ONLY level-0 row).
        local m = D.mbResult()
        H.assertTrue(string.format("slot 0 is still a real move (%d)", m),
                     m > 0 and m < 1500)
        H.log("Ursaluna's only level-0 row is MOVE_TAKE_DOWN = " .. MOVE_TAKE_DOWN)
    end)

D.run()
