-- The battle frame goes gold when the wild Pokemon is shiny.
-- PLAN.md item #13, the shiny half of the SoulGold QoL group.
--
-- ⭐ NO NEW ART: the battle textbox palette that was just loaded is re-tinted in
-- place. That is why this one could be built at all -- every other art-shaped
-- item on the open list (PLAN.md 4-6) is blocked on assets that do not exist.
--
-- The tint is a PURE function, so the transform is asserted directly rather
-- than by photographing a battle. What the pure half cannot prove is that the
-- right battles get it, so the whole thing is driven twice:
--
--   ⭐ SHINY -> the frame changes.  NOT SHINY -> it does not.
--
-- Without the second, "the frame was tinted" is equally satisfied by a build
-- that tints EVERY battle, which is the same shape as "an override never
-- produced a legendary" being satisfied by a dead feature.
--
-- The shiny case needs no brute-force search: otId ^ personality == 0 is shiny
-- by construction, so the C side builds the lead with both set to zero.
--
-- ⚠️ The requests RESTORE the palette afterwards -- they run on the overworld,
-- where those 32 entries are the live overworld palette, not a battle's.
--
-- Run (no CM_SAV -- drives a real new game):
--   timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/shiny_frame_e2e.lua pokeemerald.gba \
--     > /tmp/shiny_frame.log 2>&1

local H = dofile("tools/mgba_scripts/harness.lua")
local D = dofile("tools/mgba_scripts/intro_drive.lua")(H)

local OP_TINT, OP_SHINY, OP_NOT_SHINY = 0, 1, 2

-- The blend's fixed point: r = (r+31)/2, g = (g+27)/2, b = (b+8)/2 all settle
-- here, so this is the ONE colour the tint legitimately leaves alone. Asserting
-- a sample against it is what makes "the tint changed the colour" a statement
-- about the transform rather than about the sample.
local GOLD = 31 + 27 * 32 + 8 * 1024

local BLACK = 0
local WHITE = 31 + 31 * 32 + 31 * 1024

local function bit(v, n) return math.floor(v / 2 ^ n) % 2 == 1 end
local function val(r) return r % 65536 end

D.driveNewGameCharacterMode()

-- ------------------------------------------------------------ the transform

local tintBlack, tintWhite = nil, nil

D.mbStep("tint black", D.REQ.SHINY_FRAME, OP_TINT, BLACK, function()
    tintBlack = val(D.mbResult())
    H.assertTrue("the tint moves black away from black", tintBlack ~= BLACK)
end)

D.mbStep("tint white", D.REQ.SHINY_FRAME, OP_TINT, WHITE, function()
    tintWhite = val(D.mbResult())
    H.assertTrue("the tint moves white too", tintWhite ~= WHITE)
end)

D.mbStep("tint black again -- the transform is deterministic",
    D.REQ.SHINY_FRAME, OP_TINT, BLACK, function()
        H.assertEq("same input, same output", val(D.mbResult()), tintBlack)
    end)

D.mbStep("the gold the blend converges on is its fixed point",
    D.REQ.SHINY_FRAME, OP_TINT, GOLD, function()
        -- If this moved, the tint is not the blend it claims to be.
        H.assertEq("tint(gold) == gold", val(D.mbResult()), GOLD)
    end)

D.addStep("black and white land on DIFFERENT colours", nil, function()
    -- A "tint" that maps everything to one colour would pass every assertion
    -- above and flatten the frame to a solid block.
    H.assertTrue("the tint is a blend, not a fill", tintBlack ~= tintWhite)
    return true
end)

-- --------------------------------------------- and only for a shiny lead

D.mbStep("a SHINY wild lead tints the frame", D.REQ.SHINY_FRAME, OP_SHINY, 0,
    function()
        local r = D.mbResult()
        H.assertTrue("the request ran", bit(r, 31))
        H.assertTrue("it reported applying the frame", bit(r, 30))
        H.assertTrue("and palette entries actually changed", bit(r, 29))
        -- 30 of the 32 entries are eligible (index 0 and 16 are the
        -- transparent/backdrop colours and are skipped on purpose). A couple
        -- may already sit on the blend's fixed point, so this is a floor.
        H.assertTrue(string.format("most eligible entries moved (got %d of 30)",
                                   val(r)), val(r) >= 25)
    end)

D.mbStep("a NON-shiny wild lead leaves it alone",
    D.REQ.SHINY_FRAME, OP_NOT_SHINY, 0, function()
        local r = D.mbResult()
        H.assertTrue("the request ran", bit(r, 31))
        H.assertTrue("it did NOT report applying the frame", not bit(r, 30))
        H.assertTrue("and not one palette entry changed", not bit(r, 29))
    end)

D.run()
