-- Mint a .sav fixture in the CURRENT save format, headlessly.
--
-- WHY THIS EXISTS. The 12-character-name change moved SaveBlock1 and bumped the
-- per-sector signature (0x8012025 -> 0x8012026), so every .sav written before it
-- is refused by design: GetSaveValidStatus returns SAVE_STATUS_OLD_FORMAT and the
-- main menu offers New Game only. Three suites (continue_smoke, catch_gate_e2e,
-- gigaton_reselect_e2e) load a fixture .sav via CM_SAV, and all three went red on
-- exactly that -- not on a game defect. Checking a regenerated binary .sav into
-- the tree just moves the problem to the next save-format change; generating one
-- is the fix that keeps working.
--
-- Drives a real new game (Character Mode, default Gen I / Red), then asks the
-- game itself to save through TrySavingData -- the same call the Select-menu
-- Save item makes. The bytes are therefore written by the ROM under test, in
-- whatever format that ROM currently uses.
--
--   CM_SAV_OUT=/path/to/out.sav timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/make_fixture_save.lua pokeemerald.gba \
--     > /tmp/fixture.log 2>&1
--
-- The output file MUST already exist and be 128 KiB (mGBA binds it as the
-- cartridge's backing store and writes through to it; it does not create it):
--   head -c 131072 /dev/zero | tr '\0' '\377' > out.sav
--
-- NB mGBA's Lua has no explicit "flush savedata" call, so this waits after the
-- save for the write-through to land, then re-reads nothing -- the real proof
-- is continue_smoke passing against the generated file.

local H = dofile("tools/mgba_scripts/harness.lua")
local D = dofile("tools/mgba_scripts/intro_drive.lua")(H)

local out = os.getenv("CM_SAV_OUT")
if not out then
    error("set CM_SAV_OUT to the .sav path to write (must exist, 128 KiB of 0xFF)")
end
if not emu:loadSaveFile(out, false) then
    error("loadSaveFile failed (does it exist?): " .. out)
end
emu:reset()

H.log("writing fixture save to: " .. out)

-- 1. Erased flash -> new game -> Character Mode (Red) -> the field.
D.driveNewGameCharacterMode()

-- 2. Prove the drive produced the state a fixture needs before saving it. A
--    fixture with an empty party would make every consumer fail confusingly.
D.addStep("party is populated before saving", nil, function()
    H.assertTrue("party count 1..6 before save",
                 D.partyCount() >= 1 and D.partyCount() <= 6)
    return true
end)

-- 3. Give the lead a maximum-length nickname, unless CM_NO_NICK is set. A
--    fixture carrying a POKEMON_NAME_LENGTH name with no room for a terminator
--    exercises the name change on every subsequent Continue -- which is what you
--    want from a fixture, but it also makes the fixture a variable in every test
--    that consumes it. CM_NO_NICK=1 mints the otherwise-identical control.
if not os.getenv("CM_NO_NICK") then
    D.mbStep("set a maximum-length nickname on the lead",
        D.REQ.SET_NICKNAME, 0, 0xBB, function()  -- 0xBB = 'A' in the charmap
            H.assertEq("nickname read back at POKEMON_NAME_LENGTH",
                       D.mbResult(), 12)
        end)
else
    H.log("CM_NO_NICK set: leaving the lead's default species name")
end

-- 4. Save through the game's own path.
D.mbStep("TrySavingData(SAVE_NORMAL)", D.REQ.SAVE, 0, 0, function()
    H.assertEq("save reported SAVE_STATUS_OK", D.mbResult(), 1)
end)

-- 5. Let the write-through reach the host file before the run is killed.
D.waitFrames("settle so the flash write reaches disk", 3000)

D.addStep("done", nil, function()
    H.log("fixture written: " .. out)
    return true
end)

D.run()
