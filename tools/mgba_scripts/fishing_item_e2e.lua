-- Fishing can pull up an item -- PLAN.md item #13, the SoulGold QoL group.
--
-- The roll happens AFTER a bite has already landed, so it changes what is on
-- the end of the line and never how often the rod gets a bite. This drives
-- CharacterMode_PickFishingItem (the pure roll) and CharacterMode_TryFishingItem
-- (the whole path, bag included) -- the same functions Fishing_MonOnHook calls,
-- not a host-side model of their odds.
--
-- ⭐ THE PER-ROD TABLE IS READ OUT OF THE ROM (request op 3) rather than retyped
-- here. A membership assertion against three ids copied into a Lua file agrees
-- with a wrong table forever; one against the game's own list cannot.
--
-- ⭐ AND THE RATE IS BOUNDED ON BOTH SIDES. "the roll fired" is satisfied by a
-- feature that fires every single time, which would replace fishing entirely;
-- "the roll did not fire" is satisfied by a dead one. This repo has shipped the
-- second shape (an override that never produced a legendary was equally true of
-- a dead feature), so both ends are asserted.
--
-- ⚠️ NOT COVERED: the field task itself. Fishing_MonOnHook -> the text printer
-- -> FISHING_SHOW_RESULT is overworld UI, and no headless run in this repo
-- drives the fishing minigame. What is proven is the roll, the table, the bag
-- effect and the rod guard.
--
-- Run (no CM_SAV -- drives a real new game):
--   timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/fishing_item_e2e.lua pokeemerald.gba \
--     > /tmp/fishing_item.log 2>&1

local H = dofile("tools/mgba_scripts/harness.lua")
local D = dofile("tools/mgba_scripts/intro_drive.lua")(H)

local OLD_ROD, GOOD_ROD, SUPER_ROD = 0, 1, 2
local ITEMS_PER_ROD = 3
local BAD_ROD = 9              -- past the end of the table

local OP_COUNT, OP_DRAW, OP_FULL_PATH, OP_TABLE = 0, 1, 2, 3

local TRIALS      = 2000
local DRAW_TRIES  = 400        -- P(no hit in 400 at 10%) is about 1e-18
local LONG_TIMEOUT = 30000

local ITEM_NONE = 0

local function req(rod, op) return rod + op * 256 end
local function bit(v, n) return math.floor(v / 2 ^ n) % 2 == 1 end
local function item(r) return r % 65536 end

D.driveNewGameCharacterMode()

-- ------------------------------------------------- the game's own item table

local table_ = { [OLD_ROD] = {}, [GOOD_ROD] = {}, [SUPER_ROD] = {} }

for _, rod in ipairs({ OLD_ROD, GOOD_ROD, SUPER_ROD }) do
    for idx = 0, ITEMS_PER_ROD - 1 do
        D.mbStep(string.format("read rod %d item %d out of the ROM", rod, idx),
            D.REQ.FISHING_ITEM, req(rod, OP_TABLE), idx, function()
                table_[rod][idx] = D.mbResult()
            end)
    end
end

D.addStep("every rod offers three real items", nil, function()
    for _, rod in ipairs({ OLD_ROD, GOOD_ROD, SUPER_ROD }) do
        local seen = {}
        for idx = 0, ITEMS_PER_ROD - 1 do
            local it = table_[rod][idx]
            H.assertTrue(string.format("rod %d slot %d is a real item (got %d)",
                                       rod, idx, it or -1),
                         it ~= nil and it ~= ITEM_NONE)
            H.assertTrue(string.format("rod %d slot %d is not a duplicate", rod, idx),
                         not seen[it])
            seen[it] = true
        end
    end
    return true
end)

-- --------------------------------------------------------------- the odds

D.mbStep("roll the Super Rod " .. TRIALS .. " times",
    D.REQ.FISHING_ITEM, req(SUPER_ROD, OP_COUNT), TRIALS, function()
        local r = D.mbResult()
        H.assertTrue("the roll ran", bit(r, 31))
        local hits = r % 65536
        H.log(string.format("fishing item hits: %d / %d (%.1f%%)",
                            hits, TRIALS, hits * 100 / TRIALS))
        -- Both ends. A feature that always fires and a feature that never fires
        -- are each consistent with a one-sided check.
        H.assertTrue("the roll fires sometimes -- it is not dead", hits > 0)
        H.assertTrue("the roll does NOT fire every time -- fishing still "
                     .. "produces Pokemon", hits < TRIALS)
        H.assertTrue(string.format("the rate is near 10%%, not merely nonzero "
                                   .. "(got %d/%d)", hits, TRIALS),
                     hits > TRIALS * 0.05 and hits < TRIALS * 0.16)
    end, LONG_TIMEOUT)

-- ------------------------------------------- what comes up is from the table

for _, rod in ipairs({ OLD_ROD, GOOD_ROD, SUPER_ROD }) do
    D.mbStep(string.format("draw an item with rod %d", rod),
        D.REQ.FISHING_ITEM, req(rod, OP_DRAW), DRAW_TRIES, function()
            local drawn = D.mbResult()
            H.assertTrue(string.format("rod %d drew something in %d tries",
                                       rod, DRAW_TRIES), drawn ~= ITEM_NONE)
            local ok = false
            for idx = 0, ITEMS_PER_ROD - 1 do
                if table_[rod][idx] == drawn then ok = true end
            end
            H.assertTrue(string.format("rod %d drew item %d, which is on ITS "
                                       .. "OWN list", rod, drawn), ok)
        end, LONG_TIMEOUT)
end

-- ------------------------------------------------- and it reaches the bag

D.mbStep("the whole path puts the item in the BAG",
    D.REQ.FISHING_ITEM, req(SUPER_ROD, OP_FULL_PATH), DRAW_TRIES, function()
        local r = D.mbResult()
        H.assertTrue("the path ran", bit(r, 31))
        H.assertTrue("it produced an item", item(r) ~= ITEM_NONE)
        H.assertTrue("and the bag actually grew -- the item was not merely "
                     .. "named", bit(r, 30))
    end, LONG_TIMEOUT)

-- ------------------------------------------------------------- the guard

D.mbStep("an out-of-range rod draws nothing",
    D.REQ.FISHING_ITEM, req(BAD_ROD, OP_COUNT), 200, function()
        H.assertEq("rod " .. BAD_ROD .. " never produces an item",
                   D.mbResult() % 65536, 0)
    end, LONG_TIMEOUT)

D.run()
