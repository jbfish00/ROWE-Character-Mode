#include "global.h"
#include "character_mode.h"
#include "event_data.h"
#include "mgba.h"
#include "constants/species.h"
#include "constants/flags.h"
#include "constants/vars.h"

// Character Mode boot self-test.
//
// Runs once per boot (CB2_InitCopyrightScreenAfterBootup), ONLY under mGBA --
// mgba_open() fails on hardware and other emulators, so players never pay for
// it. Results go to the mGBA log (visible in mgba-qt's log window and on
// mgba-headless stderr) AND to gCharacterModeSelftestResult in EWRAM, which
// the headless Lua harness (tools/mgba_scripts/boot_smoke.lua) reads at the
// address recorded for it in pokeemerald.map. This is the ROWE port of the
// Lazarus/Radical Red in-ROM self-test technique: the assertions execute the
// REAL in-ROM code paths, not a host-side re-implementation of them.

struct CharacterModeSelftestResult
{
    u32 magic;   // CM_SELFTEST_MAGIC once the run is complete
    u16 passed;
    u16 failed;
};

#define CM_SELFTEST_MAGIC 0x434D5354  // "CMST"

EWRAM_DATA struct CharacterModeSelftestResult gCharacterModeSelftestResult = {0};

#ifdef GBA_PRINTF

static void Check(const char *what, bool32 cond)
{
    if (cond)
    {
        gCharacterModeSelftestResult.passed++;
    }
    else
    {
        gCharacterModeSelftestResult.failed++;
        mgba_printf(MGBA_LOG_ERROR, "CM-SELFTEST FAIL: %s", what);
    }
}

// How many rosters contain the canonical family base of `species`.
static u32 CountRostersCovering(u16 species)
{
    u16 base = CharacterMode_FamilyBase(species);
    u32 count = 0;
    u32 i, j;

    for (i = 0; i < GetCharacterCount(); i++)
    {
        for (j = 0; gCharacters[i].roster[j] != SPECIES_NONE; j++)
        {
            if (gCharacters[i].roster[j] == base)
            {
                count++;
                break;
            }
        }
    }
    return count;
}

void CharacterMode_RunBootSelftest(void)
{
    u16 savedChar;
    bool8 savedFlag;

    if (!mgba_open())
        return;

    gCharacterModeSelftestResult.magic = 0;
    gCharacterModeSelftestResult.passed = 0;
    gCharacterModeSelftestResult.failed = 0;

    // --- family canonicalization: forms and evolution interleave ---
    Check("FamilyBase(Pikachu) == Pichu",
          CharacterMode_FamilyBase(SPECIES_PIKACHU) == SPECIES_PICHU);
    Check("FamilyBase(Raichu) == Pichu",
          CharacterMode_FamilyBase(SPECIES_RAICHU) == SPECIES_PICHU);
    Check("FamilyBase(Bulbasaur) == itself",
          CharacterMode_FamilyBase(SPECIES_BULBASAUR) == SPECIES_BULBASAUR);
    Check("FamilyBase(Charizard) == Charmander",
          CharacterMode_FamilyBase(SPECIES_CHARIZARD) == SPECIES_CHARMANDER);
    Check("FamilyBase(Galarian Farfetch'd) == Farfetch'd",
          CharacterMode_FamilyBase(SPECIES_FARFETCHD_GALARIAN) == SPECIES_FARFETCHD);
    Check("FamilyBase(Sirfetch'd) == Farfetch'd",
          CharacterMode_FamilyBase(SPECIES_SIRFETCHD) == SPECIES_FARFETCHD);
    Check("FamilyBase(Clodsire) == Wooper",
          CharacterMode_FamilyBase(SPECIES_CLODSIRE) == SPECIES_WOOPER);
    Check("FamilyBase(Paldean Wooper) == Wooper",
          CharacterMode_FamilyBase(SPECIES_WOOPER_PALDEA) == SPECIES_WOOPER);
    Check("FamilyBase(Shedinja) == Nincada",
          CharacterMode_FamilyBase(SPECIES_SHEDINJA) == SPECIES_NINCADA);

    // --- roster data coverage (regressions found 2026-07-16) ---
    Check("Clodsire line reachable on >= 4 rosters (Rika/Katy/Larry/Tulip)",
          CountRostersCovering(SPECIES_CLODSIRE) >= 4);
    Check("Galarian Farfetch'd line reachable on >= 6 rosters",
          CountRostersCovering(SPECIES_FARFETCHD_GALARIAN) >= 6);

    // --- the gate itself, driven through the real flag/var state ---
    savedChar = VarGet(VAR_CHARACTER_ID);
    savedFlag = FlagGet(FLAG_CHARACTER_MODE);

    FlagSet(FLAG_CHARACTER_MODE);
    VarSet(VAR_CHARACTER_ID, 1);  // gCharacters[0] = Red (characters.txt order)
    Check("canary: character 1 roster leads with Pikachu (Red)",
          gCharacters[0].roster[0] == SPECIES_PIKACHU);
    Check("Red: Pikachu allowed",
          IsSpeciesAllowedForCharacter(SPECIES_PIKACHU) == TRUE);
    Check("Red: Pichu allowed",
          IsSpeciesAllowedForCharacter(SPECIES_PICHU) == TRUE);
    Check("Red: Raichu allowed",
          IsSpeciesAllowedForCharacter(SPECIES_RAICHU) == TRUE);
    Check("Red: Charizard allowed",
          IsSpeciesAllowedForCharacter(SPECIES_CHARIZARD) == TRUE);
    Check("Red: Meowth blocked",
          IsSpeciesAllowedForCharacter(SPECIES_MEOWTH) == FALSE);
    Check("Red: Treecko blocked",
          IsSpeciesAllowedForCharacter(SPECIES_TREECKO) == FALSE);
    Check("Red: SPECIES_NONE blocked",
          IsSpeciesAllowedForCharacter(SPECIES_NONE) == FALSE);
    Check("Red: out-of-range species blocked",
          IsSpeciesAllowedForCharacter(NUM_SPECIES) == FALSE);

    FlagClear(FLAG_CHARACTER_MODE);
    VarSet(VAR_CHARACTER_ID, 0);
    Check("mode off: everything allowed",
          IsSpeciesAllowedForCharacter(SPECIES_MEOWTH) == TRUE);

    if (savedFlag)
        FlagSet(FLAG_CHARACTER_MODE);
    VarSet(VAR_CHARACTER_ID, savedChar);

    mgba_printf(gCharacterModeSelftestResult.failed ? MGBA_LOG_ERROR : MGBA_LOG_WARN,
                "CM-SELFTEST: %d passed, %d failed",
                gCharacterModeSelftestResult.passed,
                gCharacterModeSelftestResult.failed);
    gCharacterModeSelftestResult.magic = CM_SELFTEST_MAGIC;
}

#else

void CharacterMode_RunBootSelftest(void)
{
}

#endif // GBA_PRINTF
