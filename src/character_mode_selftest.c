#include "global.h"
#include "character_mode.h"
#include "battle_setup.h"
#include "event_data.h"
#include "item.h"
#include "mgba.h"
#include "pokemon.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "constants/species.h"
#include "constants/flags.h"
#include "constants/items.h"
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

// Headless test mailbox. The Lua harness (tools/mgba_scripts/) writes a
// request into this struct; CB2_Overworld pumps it once per field frame, so
// every request executes the REAL game calls (FlagSet/AddBagItem/
// CreateScriptedWildMon/ScriptGiveMon) from a legal overworld context.
// Gated exactly like the boot self-test: mGBA only (the pump keys off the
// self-test magic, which only a boot under mGBA ever sets), zero cost on
// hardware, absent entirely without GBA_PRINTF.
//
// Field offsets (the Lua side mirrors these): +0 magic u32, +4 request u8,
// +5 status u8, +6 argA u16, +8 argB u16, +12 result u32.

// battle_interface.h can't be included here (it pulls battle_controllers.h,
// which needs the full battle.h type soup); declare the one guard we probe.
bool32 CanThrowLastUsedBall(void);

#define CM_TESTMB_MAGIC 0x434D5442  // "CMTB"

enum
{
    CM_REQ_NONE = 0,
    CM_REQ_SET_CHARACTER,  // argA: character id (1-based), 0 = mode off; result = InCharacterMode()
    CM_REQ_GIVE_ITEM,      // argA: item id, argB: quantity; result = AddBagItem()
    CM_REQ_SET_LAST_BALL,  // argA: ball item id (for the R-button quick throw)
    CM_REQ_WILD_BATTLE,    // argA: species, argB: level. Level must be >= 5:
                           // CreateScriptedWildMon treats 1-4 as scaling codes.
    CM_REQ_GIVE_MON,       // argA: species, argB: level; result = ScriptGiveMon() code
    CM_REQ_UNLOCK,         // ScriptContext2_Disable() -- a scripted wild battle
                           // returns to the field with the script lock still held
    CM_REQ_QUERY_BALL,     // argA: item id. result = lastUsedBall << 16
                           //   | CanThrowLastUsedBall() << 1 | CheckBagHasItem(argA, 1)
    CM_REQ_QUERY_PARTY_MON,// argA: party slot. result = level << 16 | species
                           // (0 for an empty/out-of-range slot)
    CM_REQ_QUERY_FLAG,     // argA: flag id. result = FlagGet(argA)
    CM_REQ_QUERY_VAR,      // argA: var id. result = VarGet(argA)
    CM_REQ_RUN_SCRIPT,     // argA: script address low 16, argB: high 16.
                           // Rejected while another script holds the lock.
    CM_REQ_SET_MON_HP,     // argA: party slot, argB: hp (0 faints the mon,
                           // e.g. so a scripted battle auto-sends the next)
    CM_REQ_SET_BATTLE_STYLE, // argA: 0 = SHIFT, 1 = SET. SET kills the
                             // "will you switch?" prompt a blind battle
                             // drive can wedge on.
    CM_REQ_SET_MON_MOVE,   // argA: party slot | (move slot << 8),
                           // argB: move id. PP is set to 10.
};

enum
{
    CM_STATUS_WORKING = 0,  // Lua sets this before writing request
    CM_STATUS_DONE = 1,
    CM_STATUS_REJECTED = 2, // request not runnable right now (script lock held)
};

struct CharacterModeTestMailbox
{
    u32 magic;
    u8 request;
    u8 status;
    u16 argA;
    u16 argB;
    u16 padding;
    u32 result;
};

EWRAM_DATA struct CharacterModeTestMailbox gCharacterModeTestMailbox = {0};

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

void CharacterMode_PumpTestMailbox(void)
{
    struct CharacterModeTestMailbox *mb = &gCharacterModeTestMailbox;

    // Only a boot under mGBA sets the self-test magic; on hardware and other
    // emulators this compare is the whole cost of the pump.
    if (gCharacterModeSelftestResult.magic != CM_SELFTEST_MAGIC)
        return;

    mb->magic = CM_TESTMB_MAGIC;  // tells the harness the pump is alive
    if (mb->request == CM_REQ_NONE)
        return;

    mb->result = 0;
    switch (mb->request)
    {
    case CM_REQ_SET_CHARACTER:
        if (mb->argA == 0)
        {
            FlagClear(FLAG_CHARACTER_MODE);
            VarSet(VAR_CHARACTER_ID, 0);
        }
        else
        {
            FlagSet(FLAG_CHARACTER_MODE);
            VarSet(VAR_CHARACTER_ID, mb->argA);
        }
        mb->result = InCharacterMode();
        break;
    case CM_REQ_GIVE_ITEM:
        mb->result = AddBagItem(mb->argA, mb->argB);
        break;
    case CM_REQ_SET_LAST_BALL:
        gSaveBlock2Ptr->lastUsedBall = mb->argA;
        break;
    case CM_REQ_WILD_BATTLE:
        if (ScriptContext2_IsEnabled())
        {
            mb->request = CM_REQ_NONE;
            mb->status = CM_STATUS_REJECTED;
            return;
        }
        CreateScriptedWildMon(mb->argA, mb->argB, ITEM_NONE);
        BattleSetup_StartScriptedWildBattle();
        break;
    case CM_REQ_GIVE_MON:
        mb->result = ScriptGiveMon(mb->argA, mb->argB, ITEM_NONE, 3, 0, 0);
        break;
    case CM_REQ_UNLOCK:
        ScriptContext2_Disable();
        break;
    case CM_REQ_QUERY_BALL:
        mb->result = ((u32)gSaveBlock2Ptr->lastUsedBall << 16)
                   | (CanThrowLastUsedBall() ? 2 : 0)
                   | (CheckBagHasItem(mb->argA, 1) ? 1 : 0);
        break;
    case CM_REQ_QUERY_PARTY_MON:
        if (mb->argA < PARTY_SIZE)
            mb->result = ((u32)GetMonData(&gPlayerParty[mb->argA], MON_DATA_LEVEL, NULL) << 16)
                       | GetMonData(&gPlayerParty[mb->argA], MON_DATA_SPECIES, NULL);
        break;
    case CM_REQ_QUERY_FLAG:
        mb->result = FlagGet(mb->argA);
        break;
    case CM_REQ_QUERY_VAR:
        mb->result = VarGet(mb->argA);
        break;
    case CM_REQ_RUN_SCRIPT:
        if (ScriptContext2_IsEnabled())
        {
            mb->request = CM_REQ_NONE;
            mb->status = CM_STATUS_REJECTED;
            return;
        }
        ScriptContext1_SetupScript((const u8 *)((u32)mb->argA | ((u32)mb->argB << 16)));
        break;
    case CM_REQ_SET_MON_HP:
        if (mb->argA < PARTY_SIZE)
        {
            u16 hp = mb->argB;
            SetMonData(&gPlayerParty[mb->argA], MON_DATA_HP, &hp);
            mb->result = GetMonData(&gPlayerParty[mb->argA], MON_DATA_HP, NULL);
        }
        break;
    case CM_REQ_SET_BATTLE_STYLE:
        gSaveBlock2Ptr->optionsBattleStyle = mb->argA;
        mb->result = gSaveBlock2Ptr->optionsBattleStyle;
        break;
    case CM_REQ_SET_MON_MOVE:
        {
            u8 slot = mb->argA & 0xFF;
            u8 moveSlot = mb->argA >> 8;
            u16 move = mb->argB;
            u8 pp = 10;
            if (slot < PARTY_SIZE && moveSlot < MAX_MON_MOVES)
            {
                SetMonData(&gPlayerParty[slot], MON_DATA_MOVE1 + moveSlot, &move);
                SetMonData(&gPlayerParty[slot], MON_DATA_PP1 + moveSlot, &pp);
                mb->result = GetMonData(&gPlayerParty[slot], MON_DATA_MOVE1 + moveSlot, NULL);
            }
        }
        break;
    }
    mb->request = CM_REQ_NONE;
    mb->status = CM_STATUS_DONE;
}

#else

void CharacterMode_RunBootSelftest(void)
{
}

void CharacterMode_PumpTestMailbox(void)
{
}

#endif // GBA_PRINTF
