-- Continue smoke test: boot with a real .sav next to the ROM, A-mash through
-- copyright/title/main menu into Continue, and assert the save actually
-- loaded (party populated, SaveBlock1 pointer valid). Exercises the
-- save-load path end to end -- the layer a boot smoke never touches.
--
-- Needs a save with a party, in the CURRENT save format, passed via CM_SAV.
--
-- DO NOT point this at ~/Documents/rowe_test_skills.sav or any other save from
-- before the 12-character-name change. That change bumped the per-sector
-- signature, so those files are refused BY DESIGN (SAVE_STATUS_OLD_FORMAT ->
-- the main menu offers New Game only), and this test then A-mashes a "Continue"
-- that is not there and fails looking exactly like a save-system bug. It is not
-- one. Generate a current fixture instead:
--
--   head -c 131072 /dev/zero | tr '\0' '\377' > ~/Documents/rowe_fixture.sav
--   CM_SAV_OUT=~/Documents/rowe_fixture.sav timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/make_fixture_save.lua pokeemerald.gba
--
--   CM_SAV=~/Documents/rowe_fixture.sav timeout 120 <mgba-headless> \
--     --script tools/mgba_scripts/continue_smoke.lua pokeemerald.gba \
--     > /tmp/continue_smoke.log 2>&1
--
-- NB the headless build does NOT auto-load a .sav sidecar next to the ROM
-- (it boots with erased flash -- cost this session a false "save is corrupt"
-- trail). emu:loadSaveFile + emu:reset is the reliable way in.

local H = dofile("tools/mgba_scripts/harness.lua")

local sav = os.getenv("CM_SAV")
if not sav then
    error("set CM_SAV to the .sav file to continue from")
end
if not emu:loadSaveFile(sav, false) then
    error("loadSaveFile failed: " .. sav)
end
emu:reset()

local DEADLINE = 12000
local done = false

-- Continue is the main menu's first option when a valid save exists, so a
-- plain A-mash reaches the field. (START also works on the title screen.)
H.mash(H.KEY.A, 200, DEADLINE, 25)

H.onFrame(function(f)
    if done then return end

    local count = H.rd8(H.anchors.gPlayerPartyCount)
    local sb1 = H.rd32(H.anchors.gSaveBlock1Ptr)
    -- On the field and nowhere else, gMain.callback2 is CB2_Overworld (+1 for
    -- the Thumb bit). The party populates much earlier (save staging during
    -- the copyright screen), so callback2 is the real "Continue worked" signal.
    local cb2 = H.rd32(H.anchors.gMain + 4)

    if cb2 == H.anchors.CB2_Overworld + 1 then
        done = true
        H.log(string.format("overworld reached at frame %d", f))
        H.assertTrue("party count sane after Continue (1..6)",
                     count >= 1 and count <= 6)
        H.log(string.format("party count = %d, SaveBlock1 @ %s", count, H.hex(sb1)))
        -- First two SaveBlock1 halfwords are the player's map coords.
        local x, y = H.rd16(sb1), H.rd16(sb1 + 2)
        H.assertTrue("player coords plausible (x,y < 1024)", x < 1024 and y < 1024)
        H.finish()
    elseif f >= DEADLINE then
        done = true
        H.assertTrue("continue reached the overworld before frame " .. DEADLINE,
                     false)
        H.log(string.format("at deadline: partyCount=%d sb1=%s cb2=%s",
                            count, H.hex(sb1), H.hex(cb2)))
        H.finish()
    end
end)
