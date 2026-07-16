-- Boot smoke test: boot the ROM headlessly and read back the in-ROM
-- Character Mode self-test (src/character_mode_selftest.c), which runs in
-- CB2_InitCopyrightScreenAfterBootup and publishes its result to
-- gCharacterModeSelftestResult in EWRAM (magic "CMST" when complete).
--
-- The assertions themselves execute IN the ROM, on the real code paths --
-- this script only collects the verdict, so it stays valid no matter how the
-- Character Mode internals change.
--
-- Run from the repo root:
--   timeout 120 <mgba-headless> --script tools/mgba_scripts/boot_smoke.lua \
--     pokeemerald.gba > /tmp/boot_smoke.log 2>&1
--   grep RESULT /tmp/boot_smoke.log

local H = dofile("tools/mgba_scripts/harness.lua")

local MAGIC = 0x434D5354  -- "CMST"
local DEADLINE = 3000     -- frames (~50s of GBA time; headless takes seconds)
local done = false

H.onFrame(function(f)
    if done then return end

    local r = H.anchors.gCharacterModeSelftestResult
    if H.rd32(r) == MAGIC then
        done = true
        local passed = H.rd16(r + 4)
        local failed = H.rd16(r + 6)
        H.log(string.format("selftest complete at frame %d", f))
        H.assertTrue("in-ROM selftest ran some checks", passed > 0)
        H.assertEq("in-ROM selftest failures", failed, 0)
        H.log(string.format("in-ROM checks passed: %d", passed))
        H.finish()
    elseif f >= DEADLINE then
        done = true
        H.assertTrue("selftest published its result before frame " .. DEADLINE,
                     false)
        H.finish()
    end
end)
