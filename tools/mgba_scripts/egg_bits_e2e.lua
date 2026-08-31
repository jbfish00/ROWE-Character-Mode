-- GetBoxMonData's non-vanilla `else` no longer corrupts the mon it reads.
-- PLAN.md item #9, §12.7.
--
-- The defect: for any field past MON_DATA_ENCRYPT_SEPARATOR, GetBoxMonData
-- decrypts, checks the checksum, and -- in this tree only -- has an `else` that
-- vanilla does not:
--
--     else { boxMon->isBadEgg = 0; boxMon->isEgg = 0; substruct3->isEgg = 0; }
--
-- It clears both egg bits on every read of a checksum-healthy mon, then
-- re-encrypts WITHOUT recomputing the checksum. Two consequences, of very
-- different severity:
--
--   1. Permanent: GetMonData(mon, MON_DATA_IS_EGG) can never return 1, for any
--      Pokemon, anywhere. That is a GAMEPLAY ruling, not a bug -- ROWE disabled
--      eggs deliberately (IsBoxMonBadEgg is hardwired FALSE, the daycare hands
--      over hatched babies) and the user confirmed on 2026-08-26 that they stay
--      disabled. The `else` therefore STAYS. This layer pins that, so a future
--      session cannot delete it by accident and call it a fix.
--   2. A real bug with no design content: the stale checksum makes
--      SetBoxMonData's guard silently DROP the next encrypted write. Fixed
--      2026-08-26 by re-stamping the checksum in the `else`.
--
-- ⚠️⚠️ WHY EVERY MEASUREMENT HERE IS ONE MAILBOX REQUEST. §12.7 measured the
-- damage as SELF-HEALING: the next encrypted read re-stamps the checksum. Two
-- mailbox requests are a frame apart, and the party/overworld code reads mons
-- every frame -- so a two-request version of this test repairs the very state
-- it is trying to observe and passes on a BROKEN build. Ops 5 and 6 do the
-- getter and the observation back to back inside one call for that reason.
--
-- ⚠️⚠️ AND WHY THE EGG BIT IS RE-SET BEFORE OP 5. The `else` only changes the
-- mon when a bit was actually set -- clearing an already-clear bit leaves the
-- checksum correct. Op 6's own getter clears it, so without setting it again
-- first, op 5 would run against a clean mon and PASS ON A BROKEN BUILD. This is
-- the "your control must reach the code" trap, and the first draft of this file
-- had it.
--
-- Run (no CM_SAV -- drives a real new game):
--   timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/egg_bits_e2e.lua pokeemerald.gba \
--     > /tmp/egg_bits.log 2>&1

local H = dofile("tools/mgba_scripts/harness.lua")
local D = dofile("tools/mgba_scripts/intro_drive.lua")(H)

local SLOT = 0

local DIAG_CHECKSUM      = 0   -- computed << 16 | stored
local DIAG_RAW           = 1   -- bit0 sanity isEgg, bit1 encrypted isEgg
local DIAG_WRITE_ENC     = 3   -- write MON_DATA_IS_EGG, then read the raw bits
local DIAG_GETTER        = 4   -- what GetMonData reports
local DIAG_WRITE_AFTER   = 5   -- one getter, then an encrypted write, read back
local DIAG_CHECKSUM_AFTER = 6  -- one getter, then the checksum pair

local ITEM_POTION = 28

-- ops 0 and 6 return a bare (computed << 16) | stored with NO "ran" bit, on
-- purpose: CM_EGGDIAG_RAN is 0x80000000 and a u16 checksum shifted left 16
-- reaches bit 31, so ORing the two forces bit 15 of the computed half and makes
-- this comparison a coin flip for any checksum below 32768. See the comment on
-- CharacterMode_EggDiag in src/pokemon.c.
local function lo(r) return r % 65536 end
local function hi(r) return math.floor(r / 65536) % 65536 end

D.driveNewGameCharacterMode()

-- --------------------------------------------------------------- baseline

D.mbStep("the starter's checksum is healthy to begin with",
    D.REQ.EGG_DIAG, SLOT, DIAG_CHECKSUM, function()
        local r = D.mbResult()
        H.assertEq("computed == stored", hi(r), lo(r))
    end)

-- ------------------------------------------- the write lands in STORAGE

D.mbStep("write MON_DATA_IS_EGG -- it reaches storage",
    D.REQ.EGG_DIAG, SLOT, DIAG_WRITE_ENC, function()
        -- Not vacuous decoration: this is what makes the "the getter reports 0"
        -- assertion below a statement about the GETTER rather than about a
        -- write that never happened.
        local r = D.mbResult()
        H.assertTrue("the encrypted isEgg bit is set in storage",
                     math.floor(r / 2) % 2 == 1)
    end)

-- --------------------------------- THE FIX: one getter leaves it healthy

D.mbStep("after exactly one getter, the checksum still agrees",
    D.REQ.EGG_DIAG, SLOT, DIAG_CHECKSUM_AFTER, function()
        local r = D.mbResult()
        H.assertEq("computed == stored after the `else` ran -- before the "
                   .. "re-stamp this read 38122 against a stored 54506",
                   hi(r), lo(r))
    end)

-- ------------------ THE CONSEQUENCE: the next encrypted write is not dropped

D.mbStep("re-set the egg bit, so the `else` has something to clear",
    D.REQ.EGG_DIAG, SLOT, DIAG_WRITE_ENC, function()
        H.assertTrue("the bit is set again -- without this the check below "
                     .. "would run against a clean mon and pass on a broken build",
                     math.floor(D.mbResult() / 2) % 2 == 1)
    end)

D.mbStep("an encrypted write immediately after a getter LANDS",
    D.REQ.EGG_DIAG, SLOT, DIAG_WRITE_AFTER, function()
        H.assertEq("the held item reads back as the Potion that was just "
                   .. "written -- SetBoxMonData's checksum guard did not drop it",
                   lo(D.mbResult()), ITEM_POTION)
    end)

-- ------------------------------------- the RULING: eggs are still disabled

D.mbStep("and GetMonData still reports 'not an egg' -- by design",
    D.REQ.EGG_DIAG, SLOT, DIAG_GETTER, function()
        local r = D.mbResult()
        H.assertEq("MON_DATA_SANITY_IS_EGG reads 0", r % 2, 0)
        H.assertEq("MON_DATA_IS_EGG reads 0 -- the `else` is deliberately "
                   .. "still there; eggs stay disabled in ROWE",
                   math.floor(r / 2) % 2, 0)
    end)

D.run()
