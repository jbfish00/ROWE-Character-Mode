-- OT / name-length round trip: the regression gate for the 12-character-name
-- change (POKEMON_NAME_LENGTH and PLAYER_NAME_LENGTH 10/7 -> 12, OT_NAME_LENGTH
-- deliberately left at 7 so BoxPokemon stays 80 bytes and PC storage never grows).
--
-- WHAT THIS ACTUALLY TESTS, AND WHY IT IS NOT THE OBEDIENCE TEST THE PLAN ASKED
-- FOR. The handover notes called for proving a caught Pokemon OBEYS, on the
-- theory that a wrong ownership comparison makes every self-caught mon read as
-- traded. That cannot be observed in this ROM: IsMonDisobedient (battle_util.c)
-- has its entire body commented out and unconditionally returns 0, and
-- IsTradedMon (pokemon.c) is stubbed to return FALSE. Those are IsOtherTrainer's
-- only two callers, so nothing in ROWE can disobey and an "it obeyed" assertion
-- would pass no matter what the comparison did -- a test that cannot fail.
--
-- The real exposure of decoupling OT_NAME_LENGTH from PLAYER_NAME_LENGTH is
-- memory, not behaviour: the OT field is 7 bytes inside BoxPokemon, immediately
-- followed by markings and the checksum. An accessor still copying
-- PLAYER_NAME_LENGTH bytes overruns it, and the audit that preceded this change
-- found nine such overflows that all compiled clean. So this asserts the
-- round trip and the integrity of the struct around it:
--
--   * the player name really is at PLAYER_NAME_LENGTH -- set explicitly, NOT
--     taken from the naming screen. The intro A-mash lands on a 6-character
--     name, which is SHORTER than OT_NAME_LENGTH, so a drive that trusts it
--     never truncates an OT and the whole test silently proves nothing.
--   * a caught Pokemon's OT reads back as exactly OT_NAME_LENGTH characters,
--     truncated from a player name nearly twice that long
--   * that OT matches the player's name over those characters
--   * IsOtherTrainer says the mon is the player's own (correct today, and the
--     assertion that starts meaning something the moment disobedience is re-enabled)
--   * the mon is NOT a Bad Egg -- i.e. nothing overran otName into the checksum
--   * a maximum-length nickname round-trips at full length
--   * all of the above still hold after a save and a reload
--
-- Run (no CM_SAV -- it drives a real new game, which is where a 12-character
-- player name comes from):
--   timeout 300 <mgba-headless> \
--     --script tools/mgba_scripts/ot_roundtrip_e2e.lua pokeemerald.gba \
--     > /tmp/ot.log 2>&1

local H = dofile("tools/mgba_scripts/harness.lua")
local D = dofile("tools/mgba_scripts/intro_drive.lua")(H)

-- Must match include/constants/global.h / include/pokemon.h.
local POKEMON_NAME_LENGTH = 12
local PLAYER_NAME_LENGTH  = 12
local OT_NAME_LENGTH      = 7

local SPECIES_PIKACHU = 25   -- on Red's roster, so the catch gate allows it
local CHAR_A          = 0xBB -- 'A' in the charmap

-- CM_REQ_QUERY_OT packs its answer into one word; mirror the C side exactly.
local function unpackOt(r)
    return {
        isOther    = r % 2,
        badEgg     = math.floor(r / 2) % 2,
        nameMatch  = math.floor(r / 4) % 2,
        otLen      = math.floor(r / 0x100) % 0x100,
        nickLen    = math.floor(r / 0x10000) % 0x100,
        playerLen  = math.floor(r / 0x1000000) % 0x100,
    }
end

-- The same battery, run before and after the save/reload so a field that only
-- survives in RAM cannot pass. `when` labels which pass an assertion came from.
local function assertOt(when, r)
    local o = unpackOt(r)
    H.log(string.format(
        "%s: raw=%s isOther=%d badEgg=%d nameMatch=%d otLen=%d nickLen=%d playerLen=%d",
        when, H.hex(r), o.isOther, o.badEgg, o.nameMatch, o.otLen, o.nickLen,
        o.playerLen))

    -- The premise: the name really is long enough to force truncation. If this
    -- fails, the name-length change is not in the ROM and every assertion below
    -- is testing the old format against a name that never needed truncating.
    H.assertEq(when .. ": player name is at PLAYER_NAME_LENGTH",
               o.playerLen, PLAYER_NAME_LENGTH)
    H.assertTrue(when .. ": that name is longer than the OT field",
                 PLAYER_NAME_LENGTH > OT_NAME_LENGTH)

    -- A stored OT is truncated to OT_NAME_LENGTH. Reading back more than that
    -- means an accessor is running off the end of the field; reading back fewer
    -- means the truncation dropped characters it should have kept.
    H.assertEq(when .. ": OT name reads back at exactly OT_NAME_LENGTH",
               o.otLen, OT_NAME_LENGTH)
    H.assertEq(when .. ": OT name matches the player's over those characters",
               o.nameMatch, 1)
    H.assertEq(when .. ": IsOtherTrainer says the mon is the player's own",
               o.isOther, 0)

    -- The overflow canary. otName is immediately followed by markings and the
    -- checksum; an overrun corrupts the checksum and the mon decodes as a Bad Egg.
    H.assertEq(when .. ": mon is not a Bad Egg (no overrun into the checksum)",
               o.badEgg, 0)

    H.assertEq(when .. ": nickname holds POKEMON_NAME_LENGTH characters",
               o.nickLen, POKEMON_NAME_LENGTH)
end

-- 1. Real new game -> Character Mode (Red) -> the field.
D.driveNewGameCharacterMode()

-- 1b. Force the player name to PLAYER_NAME_LENGTH. This must happen BEFORE the
--     gift below, because the OT is stamped at creation -- and it is the whole
--     point of the test: a 12-character name truncated into a 7-character field
--     is the exact operation the change introduced. The naming screen's A-mash
--     yields 6 characters, which fits without truncating and proves nothing.
D.mbStep("set the player name to PLAYER_NAME_LENGTH",
    D.REQ.SET_PLAYER_NAME, CHAR_A, PLAYER_NAME_LENGTH, function()
        H.assertEq("player name is now PLAYER_NAME_LENGTH long",
                   D.mbResult(), PLAYER_NAME_LENGTH)
    end)

-- 2. Give the player a second Pokemon through the game's own gift path, so the
--    mon under test is one this build created with the current struct layout
--    (the starter was created in the same boot, but through the commit handler).
D.mbStep("give an on-roster Pikachu", D.REQ.GIVE_MON, SPECIES_PIKACHU, 10,
    function()
        -- ScriptGiveMon: 0 = went to the party, 1 = went to the PC.
        H.assertEq("gifted Pikachu joined the party (on Red's roster)",
                   D.mbResult(), 0)
    end)

D.addStep("party now holds two", nil, function()
    H.assertEq("party count is 2", D.partyCount(), 2)
    return true
end)

-- 3. Maximum-length nickname on the gifted mon: POKEMON_NAME_LENGTH characters
--    with no room for a terminator, the case that overflows if any writer is
--    still using the old length.
D.mbStep("set a maximum-length nickname", D.REQ.SET_NICKNAME, 1, CHAR_A,
    function()
        H.assertEq("nickname round-trips at POKEMON_NAME_LENGTH",
                   D.mbResult(), POKEMON_NAME_LENGTH)
    end)

-- 4. The battery, in RAM.
D.mbStep("query OT state (in RAM)", D.REQ.QUERY_OT, 1, 0, function()
    assertOt("in RAM", D.mbResult())
end)

-- 5. Save, then verify the same mon still reads correctly. This is what catches
--    a field that survives in RAM but is mangled by the save serialisation --
--    the layer the 4000 -> 4084 SECTOR_DATA_SIZE change touched.
D.mbStep("save the game", D.REQ.SAVE, 0, 0, function()
    H.assertEq("save reported SAVE_STATUS_OK", D.mbResult(), 1)
end)

D.waitFrames("let the save settle", 600)

D.mbStep("query OT state (after save)", D.REQ.QUERY_OT, 1, 0, function()
    assertOt("after save", D.mbResult())
end)

D.run()
