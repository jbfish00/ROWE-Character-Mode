#include "global.h"
#include <stddef.h>  // offsetof, for the struct-layout beacon below
#include "character_mode.h"
#include "battle.h"
#include "battle_setup.h"
#include "event_data.h"
#include "item.h"
#include "mgba.h"
#include "pokemon.h"
#include "save.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "string_util.h"
#include "text.h"  // EOS
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
    CM_REQ_SWEEP_PARTY,    // run CharacterMode_SweepPartyToPC() (the exact
                           // call Cb2_ExitPSS makes on leaving the storage
                           // UI); result = party count after the sweep
    CM_REQ_SAVE,           // TrySavingData(SAVE_NORMAL); result = its return.
                           // Lets a headless run mint a .sav fixture in the
                           // CURRENT save format instead of shipping a stale
                           // one -- see tools/mgba_scripts/make_fixture_save.lua
    CM_REQ_QUERY_OT,       // argA: party slot. Everything the 12-character-name
                           // change put at risk, in one word:
                           //   bit0    IsOtherTrainer(otId, otName)  (want 0)
                           //   bit1    MON_DATA_SANITY_IS_BAD_EGG    (want 0)
                           //   bit2    OT name matches the player's  (want 1)
                           //   b8-15   strlen of the OT name read back
                           //   b16-23  strlen of the nickname read back
                           //   b24-31  strlen of the player name
    CM_REQ_SET_PLAYER_NAME,// argA: character to repeat, argB: how many (clamped
                           // to PLAYER_NAME_LENGTH). The naming screen's A-mash
                           // happens to stop at 6 characters, which is SHORTER
                           // than OT_NAME_LENGTH -- so a drive that relies on it
                           // never exercises OT truncation at all. This sets the
                           // name directly so the truncating case is reachable.
                           // result = strlen of the player name read back.
    CM_REQ_SET_NICKNAME,   // argA: party slot, argB: character to repeat.
                           // Fills the nickname with POKEMON_NAME_LENGTH copies
                           // of argB -- a maximum-length name with no room for
                           // a terminator, which is the case that overflows.
                           // result = strlen of the nickname read back.
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
    // Off-roster control: Meowth until 2026-07-24, when the roster sync gave
    // Red the Persian line (his researched rematch teams). Controls must be
    // picked by FAMILY BASE and re-checked after any roster change.
    Check("Red: Poochyena blocked",
          IsSpeciesAllowedForCharacter(SPECIES_POOCHYENA) == FALSE);
    Check("Red: Treecko blocked",
          IsSpeciesAllowedForCharacter(SPECIES_TREECKO) == FALSE);
    Check("Red: SPECIES_NONE blocked",
          IsSpeciesAllowedForCharacter(SPECIES_NONE) == FALSE);
    Check("Red: out-of-range species blocked",
          IsSpeciesAllowedForCharacter(NUM_SPECIES) == FALSE);

    // --- wild encounter roster override (10% swap, never a legendary) ---
    Check("legendary check: Mewtwo flagged",
          CharacterMode_IsLegendaryOrMythical(SPECIES_MEWTWO) == TRUE);
    Check("legendary check: Pikachu not flagged",
          CharacterMode_IsLegendaryOrMythical(SPECIES_PIKACHU) == FALSE);
    Check("legendary check: Raichu (evolved form) not flagged",
          CharacterMode_IsLegendaryOrMythical(SPECIES_RAICHU) == FALSE);

    Check("stage pick: Bulbasaur at Lv.5 stays Bulbasaur",
          CharacterMode_PickEvolutionStageForLevel(SPECIES_BULBASAUR, 5) == SPECIES_BULBASAUR);
    Check("stage pick: Bulbasaur at Lv.20 becomes Ivysaur (evolves at 16)",
          CharacterMode_PickEvolutionStageForLevel(SPECIES_BULBASAUR, 20) == SPECIES_IVYSAUR);
    Check("stage pick: Bulbasaur at Lv.40 becomes Venusaur (Ivysaur evolves at 32)",
          CharacterMode_PickEvolutionStageForLevel(SPECIES_BULBASAUR, 40) == SPECIES_VENUSAUR);

    {
        // Red's roster includes Articuno/Deoxys/Entei/Raikou/Regigigas/Suicune
        // (6 legendaries) alongside ~41 ordinary members. 200 rolls at 10%
        // fire close to certainly (P(zero fires) = 0.9^200 ~= 1.6e-10) and
        // give the legendary exclusion many chances to fail if it's broken.
        u32 trial, fired = 0;
        bool8 anyLegendary = FALSE;

        for (trial = 0; trial < 200; trial++)
        {
            u16 result = CharacterMode_RollWildOverrideSpecies(30);
            if (result != SPECIES_NONE)
            {
                fired++;
                if (CharacterMode_IsLegendaryOrMythical(result))
                    anyLegendary = TRUE;
            }
        }
        Check("wild override: fired at least once in 200 rolls at 10% (Red active)",
              fired > 0);
        Check("wild override: never produced a legendary/mythical",
              anyLegendary == FALSE);
    }

    FlagClear(FLAG_CHARACTER_MODE);
    VarSet(VAR_CHARACTER_ID, 0);
    Check("mode off: everything allowed",
          IsSpeciesAllowedForCharacter(SPECIES_MEOWTH) == TRUE);
    Check("wild override: mode off never fires",
          CharacterMode_RollWildOverrideSpecies(30) == SPECIES_NONE);

    if (savedFlag)
        FlagSet(FLAG_CHARACTER_MODE);
    VarSet(VAR_CHARACTER_ID, savedChar);

    mgba_printf(gCharacterModeSelftestResult.failed ? MGBA_LOG_ERROR : MGBA_LOG_WARN,
                "CM-SELFTEST: %d passed, %d failed",
                gCharacterModeSelftestResult.passed,
                gCharacterModeSelftestResult.failed);
    gCharacterModeSelftestResult.magic = CM_SELFTEST_MAGIC;
}

// Struct-layout beacon for the Lua harness.
//
// The mGBA scripts used to hardcode struct offsets recovered from a savestate
// probe (`struct BattleResults: battleTurnCounter +0x13, lastUsedMovePlayer
// +0x22`). Those went stale the moment POKEMON_NAME_LENGTH went 10 -> 12,
// because BattleResults embeds playerMon1Name[POKEMON_NAME_LENGTH + 1] at 0x8 --
// so battleTurnCounter moved to 0x15 and lastUsedMovePlayer to 0x26.
//
// The cost of that was not a broken game but a LYING TEST:
// gigaton_reselect_e2e read a turn counter that never changed and a last-move
// that was always 0, so it reported the Gigaton Hammer selection gate broken
// while the ROM was performing it correctly -- and the handover notes recorded
// that as a red suite blocking the release.
//
// Offsets now come from the compiler. A test that reads them here cannot drift.
// Append only, and mirror any addition in tools/mgba_scripts/harness.lua.
const u16 gTestStructOffsets[] =
{
    offsetof(struct BattleResults, battleTurnCounter),   // [0]
    offsetof(struct BattleResults, lastUsedMovePlayer),  // [1]
    sizeof(struct BattlePokemon),                        // [2]
    offsetof(struct BattlePokemon, hp),                  // [3]
    offsetof(struct BattlePokemon, maxHP),               // [4]
    offsetof(struct BattlePokemon, moves),               // [5]
    offsetof(struct BattlePokemon, nickname),            // [6]
    offsetof(struct BattlePokemon, otName),              // [7]
};

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
    case CM_REQ_SWEEP_PARTY:
        CharacterMode_SweepPartyToPC();
        mb->result = CalculatePlayerPartyCount();
        break;
    case CM_REQ_SAVE:
        mb->result = TrySavingData(SAVE_NORMAL);
        break;
    case CM_REQ_QUERY_OT:
        if (mb->argA < PARTY_SIZE)
        {
            struct Pokemon *mon = &gPlayerParty[mb->argA];
            u8 otName[OT_NAME_LENGTH + 1];
            u8 nickname[POKEMON_NAME_LENGTH + 1];
            u32 otId;
            u8 i;
            bool8 matches = TRUE;

            // Both buffers are sized the way the game sizes them. If either
            // accessor still writes PLAYER_NAME_LENGTH bytes, this smashes the
            // stack -- which is exactly the defect worth catching.
            GetMonData(mon, MON_DATA_OT_NAME, otName);
            GetMonData(mon, MON_DATA_NICKNAME, nickname);
            otId = GetMonData(mon, MON_DATA_OT_ID, NULL);

            for (i = 0; i < OT_NAME_LENGTH; i++)
            {
                if (otName[i] == EOS)
                    break;
                if (otName[i] != gSaveBlock2Ptr->playerName[i])
                    matches = FALSE;
            }

            mb->result = (IsOtherTrainer(otId, otName) ? 1 : 0)
                       | (GetMonData(mon, MON_DATA_SANITY_IS_BAD_EGG, NULL) ? 2 : 0)
                       | (matches ? 4 : 0)
                       | ((u32)StringLength(otName) << 8)
                       | ((u32)StringLength(nickname) << 16)
                       | ((u32)StringLength(gSaveBlock2Ptr->playerName) << 24);
        }
        break;
    case CM_REQ_SET_PLAYER_NAME:
        {
            u8 n = mb->argB;
            u8 i;

            if (n > PLAYER_NAME_LENGTH)
                n = PLAYER_NAME_LENGTH;
            for (i = 0; i < n; i++)
                gSaveBlock2Ptr->playerName[i] = mb->argA;
            // playerName is PLAYER_NAME_LENGTH + 1 bytes, so a full-length name
            // still terminates inside the field.
            gSaveBlock2Ptr->playerName[n] = EOS;
            mb->result = StringLength(gSaveBlock2Ptr->playerName);
        }
        break;
    case CM_REQ_SET_NICKNAME:
        if (mb->argA < PARTY_SIZE)
        {
            u8 nickname[POKEMON_NAME_LENGTH + 1];
            u8 i;

            for (i = 0; i < POKEMON_NAME_LENGTH; i++)
                nickname[i] = mb->argB;
            nickname[POKEMON_NAME_LENGTH] = EOS;

            SetMonData(&gPlayerParty[mb->argA], MON_DATA_NICKNAME, nickname);
            GetMonData(&gPlayerParty[mb->argA], MON_DATA_NICKNAME, nickname);
            mb->result = StringLength(nickname);
        }
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
