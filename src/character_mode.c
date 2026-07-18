#include "global.h"
#include "character_mode.h"
#include "event_data.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "level_scaling.h"
#include "random.h"
#include "constants/species.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/event_objects.h"
#include "constants/trainers.h"

#include "data/characters.h"

u16 GetCharacterCount(void)
{
    return NUM_CHARACTERS;
}

bool8 InCharacterMode(void)
{
    return FlagGet(FLAG_CHARACTER_MODE) && VarGet(VAR_CHARACTER_ID) != 0
        && VarGet(VAR_CHARACTER_ID) <= NUM_CHARACTERS;
}

const struct CharacterInfo *GetActiveCharacter(void)
{
    if (!InCharacterMode())
        return NULL;
    return &gCharacters[VarGet(VAR_CHARACTER_ID) - 1];
}

// The character whose SPRITES the player wears. A costume from the Pokemon Center
// overrides the one you are playing as -- a costume changes how you look, while
// VAR_CHARACTER_ID still decides your roster. Roster code must keep calling
// GetActiveCharacter(); only appearance code calls this.
const struct CharacterInfo *GetAppearanceCharacter(void)
{
    u16 costume = VarGet(VAR_COSTUME_CHARACTER);

    if (costume == COSTUME_CHARACTER_BASE)
        return NULL;    // wearing a base outfit on purpose; don't let the character override it
    if (costume != 0 && costume <= NUM_CHARACTERS)
        return &gCharacters[costume - 1];
    return GetActiveCharacter();
}

// Only characters with overworld art can be worn -- the other 81 have no sprite
// to put on the map, and handing their id to the avatar code draws garbage.
bool8 CharacterHasOverworldSprite(u16 index)
{
    if (index >= NUM_CHARACTERS)
        return FALSE;
    return gCharacters[index].owGfxId != CHAR_ASSET_NONE;
}

u16 CharacterMode_GetRosterSize(const struct CharacterInfo *character)
{
    u16 count = 0;

    while (character->roster[count] != SPECIES_NONE)
        count++;
    return count;
}

// Canonical representative of a species' whole extended family: alternate
// form-collapse and evolution-walk until stable. One step of each is NOT
// enough -- forms and evolution interleave (Sirfetch'd devolves to Galarian
// Farfetch'd, a FORM of Farfetch'd; Clodsire devolves to Paldean Wooper, a
// form of Wooper), and the one-shot version made family members canonicalize
// to DIFFERENT species, so rosters matched some stages and not others.
// Consequence, accepted: regional variants share the family of their base
// species (the engine's form tables treat them as one species).
u16 CharacterMode_FamilyBase(u16 species)
{
    u16 prev;
    u32 guard;

    for (guard = 0; guard < 8; guard++)
    {
        prev = species;
        species = GetFirstEvolution(GetBaseFormSpeciesId(species));
        if (species == prev)
            break;
    }
    return species;
}

// A species is allowed if the canonical base of its evolution family is on
// the active character's roster (rosters store family bases only, so whole
// families are always allowed together).
bool8 IsSpeciesAllowedForCharacter(u16 species)
{
    const struct CharacterInfo *character = GetActiveCharacter();
    u16 base;
    u32 i;

    if (character == NULL)
        return TRUE;
    if (species == SPECIES_NONE || species >= NUM_SPECIES)
        return FALSE;

    base = CharacterMode_FamilyBase(species);
    for (i = 0; character->roster[i] != SPECIES_NONE; i++)
    {
        if (character->roster[i] == base)
            return TRUE;
    }
    return FALSE;
}

bool8 CharacterMode_PartyHasAllowedMon(void)
{
    u32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);

        if (species != SPECIES_NONE
            && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, NULL)
            && IsSpeciesAllowedForCharacter(species))
            return TRUE;
    }
    return FALSE;
}

// Move every off-roster party member to the PC. Never leaves the party
// empty: if all members are off-roster, slot 0 is kept. Mons stay in the
// party if the boxes are full.
void CharacterMode_SweepPartyToPC(void)
{
    u32 i;
    bool8 keptOne = FALSE;

    if (!InCharacterMode())
        return;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);

        if (species == SPECIES_NONE)
            continue;
        if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, NULL)
            || IsSpeciesAllowedForCharacter(species))
        {
            keptOne = TRUE;
            continue;
        }
    }

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);

        if (species == SPECIES_NONE
            || GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, NULL)
            || IsSpeciesAllowedForCharacter(species))
            continue;
        if (!keptOne)
        {
            keptOne = TRUE; // never empty the party
            continue;
        }
        if (SendMonToPC(&gPlayerParty[i]) != MON_CANT_GIVE)
            ZeroMonData(&gPlayerParty[i]);
    }

    CompactPartySlots();
    CalculatePlayerPartyCount();
}

// Special. Character Mode hands the player their character's starter the moment the mode
// is committed (ui_mode_menu.c: ScriptGiveMon(GetStarterAt(starterselection), ...)), so the
// intro must NOT go on to offer the generic starter menu -- doing so handed out a second,
// off-roster mon (Red walked out with Pikachu AND Meowth, and the party sweep had already
// run, so the Meowth stayed).
// NB this tree's `specialvar` uses the special's RETURN VALUE
// (scrcmd.c: *var = gSpecials[...]()), not gSpecialVar_Result. A void special that only
// writes gSpecialVar_Result hands the script whatever happened to be in r0.
u8 IsPlayerInCharacterMode(void)
{
    return InCharacterMode();
}

// --- Wild encounter roster override -----------------------------------
//
// Character Mode gives every wild-encounter roll (grass/cave, surf, rock
// smash, headbutt/cut, and all fishing rods -- anything that draws a
// species out of a WildPokemonInfo table; see wild_encounter.c's
// TryGenerateWildMon/GenerateFishingWildMon) a 10% chance to be replaced by
// a random, level-appropriate member of the active character's roster.
// Legendaries/mythicals/Ultra Beasts never come out of this roll -- they
// stay route/story-only, exactly like the catch gate already keeps them.

#define WILD_OVERRIDE_CHANCE_PERCENT 10

// Same set as tools/character_mode/emit_characters.py's LEGENDARY_BASES --
// keep the two in sync by hand if either changes. That script uses this set
// to keep these species off starter offers; here it keeps them off the wild
// roster-override roll for the same reason (they're meant to stay
// route/story encounters, not something that turns up while grinding).
static const u16 sLegendaryFamilyBases[] =
{
    SPECIES_ARTICUNO, SPECIES_ZAPDOS, SPECIES_MOLTRES, SPECIES_MEWTWO, SPECIES_MEW,
    SPECIES_RAIKOU, SPECIES_ENTEI, SPECIES_SUICUNE, SPECIES_LUGIA, SPECIES_HO_OH, SPECIES_CELEBI,
    SPECIES_REGIROCK, SPECIES_REGICE, SPECIES_REGISTEEL, SPECIES_LATIAS, SPECIES_LATIOS,
    SPECIES_KYOGRE, SPECIES_GROUDON, SPECIES_RAYQUAZA, SPECIES_JIRACHI, SPECIES_DEOXYS,
    SPECIES_UXIE, SPECIES_MESPRIT, SPECIES_AZELF, SPECIES_DIALGA, SPECIES_PALKIA, SPECIES_HEATRAN,
    SPECIES_REGIGIGAS, SPECIES_GIRATINA, SPECIES_CRESSELIA, SPECIES_PHIONE, SPECIES_MANAPHY,
    SPECIES_DARKRAI, SPECIES_SHAYMIN, SPECIES_ARCEUS,
    SPECIES_VICTINI, SPECIES_COBALION, SPECIES_TERRAKION, SPECIES_VIRIZION, SPECIES_TORNADUS,
    SPECIES_THUNDURUS, SPECIES_RESHIRAM, SPECIES_ZEKROM, SPECIES_LANDORUS, SPECIES_KYUREM,
    SPECIES_KELDEO, SPECIES_MELOETTA, SPECIES_GENESECT,
    SPECIES_XERNEAS, SPECIES_YVELTAL, SPECIES_ZYGARDE, SPECIES_DIANCIE, SPECIES_HOOPA, SPECIES_VOLCANION,
    SPECIES_TYPE_NULL, SPECIES_TAPU_KOKO, SPECIES_TAPU_LELE, SPECIES_TAPU_BULU, SPECIES_TAPU_FINI,
    SPECIES_COSMOG, SPECIES_NECROZMA, SPECIES_MAGEARNA, SPECIES_MARSHADOW, SPECIES_ZERAORA, SPECIES_MELTAN,
    SPECIES_NIHILEGO, SPECIES_BUZZWOLE, SPECIES_PHEROMOSA, SPECIES_XURKITREE, SPECIES_CELESTEELA,
    SPECIES_KARTANA, SPECIES_GUZZLORD, SPECIES_POIPOLE, SPECIES_STAKATAKA, SPECIES_BLACEPHALON,
    SPECIES_ZACIAN, SPECIES_ZAMAZENTA, SPECIES_ETERNATUS, SPECIES_KUBFU, SPECIES_ZARUDE,
    SPECIES_REGIELEKI, SPECIES_REGIDRAGO, SPECIES_GLASTRIER, SPECIES_SPECTRIER, SPECIES_CALYREX, SPECIES_ENAMORUS,
    SPECIES_WO_CHIEN, SPECIES_CHIEN_PAO, SPECIES_TING_LU, SPECIES_CHI_YU, SPECIES_KORAIDON, SPECIES_MIRAIDON,
    SPECIES_OKIDOGI, SPECIES_MUNKIDORI, SPECIES_FEZANDIPITI, SPECIES_OGERPON, SPECIES_TERAPAGOS, SPECIES_PECHARUNT,
};

bool8 CharacterMode_IsLegendaryOrMythical(u16 species)
{
    u16 base = CharacterMode_FamilyBase(species);
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sLegendaryFamilyBases); i++)
    {
        if (sLegendaryFamilyBases[i] == base)
            return TRUE;
    }
    return FALSE;
}

// Level assumed for evolutions whose trigger isn't level-based (item, trade,
// friendship, beauty, ...) -- those methods don't carry a real level number,
// so a canon mid-game breakpoint stands in per evolution depth (most 1st
// evolutions land around Lv.16, most 2nd ones around Lv.32-40 across the
// vanilla games this hack is built on).
static const u8 sEvoDepthFallbackLevel[EVOS_PER_MON] = {16, 32, 40, 48, 56, 64, 72, 80, 88, 96};

static bool8 IsLevelBasedEvoMethod(u16 method)
{
    switch (method)
    {
    case EVO_LEVEL:
    case EVO_LEVEL_ATK_GT_DEF:
    case EVO_LEVEL_ATK_EQ_DEF:
    case EVO_LEVEL_ATK_LT_DEF:
    case EVO_LEVEL_SILCOON:
    case EVO_LEVEL_CASCOON:
    case EVO_LEVEL_NINJASK:
    case EVO_LEVEL_SHEDINJA:
    case EVO_LEVEL_FEMALE:
    case EVO_LEVEL_MALE:
    case EVO_LEVEL_NIGHT:
    case EVO_LEVEL_DAY:
    case EVO_LEVEL_DUSK:
    case EVO_LEVEL_RAIN:
    case EVO_LEVEL_DARK_TYPE_MON_IN_PARTY:
    case EVO_LEVEL_NIGHT_ALOLA:
    case EVO_LEVEL_SEVII:
    case EVO_LEVEL_NOT_SEVII:
        return TRUE;
    default:
        return FALSE;
    }
}

// Walks a family forward from `species` (normally a roster family base),
// evolving one stage at a time for as long as `level` clears the next
// stage's evolution requirement. Always lands on *some* stage (the base
// itself at worst), which is the "closest available stage" fallback the
// spec asks for -- there's no such thing as a level with no fit since stage
// 0 always covers levels down to 1. Branching families (Eevee, Wurmple,
// Tyrogue, ...) pick uniformly at random among whichever branches qualify
// at the current level; there's no "best" branch by level alone.
u16 CharacterMode_PickEvolutionStageForLevel(u16 species, u8 level)
{
    u32 depth;

    for (depth = 0; depth < EVOS_PER_MON; depth++)
    {
        u16 candidates[EVOS_PER_MON];
        u8 candidateCount = 0;
        u8 fallbackLevel = sEvoDepthFallbackLevel[depth];
        u32 k;

        for (k = 0; k < EVOS_PER_MON; k++)
        {
            u16 method = gEvolutionTable[species][k].method;
            u16 target = gEvolutionTable[species][k].targetSpecies;
            u16 requiredLevel;

            if (target == SPECIES_NONE || target == species)
                continue;
            if (method == EVO_MEGA_EVOLUTION || method == EVO_MOVE_MEGA_EVOLUTION)
                continue; // battle-only forms, not a real wild spawn stage

            requiredLevel = IsLevelBasedEvoMethod(method)
                          ? gEvolutionTable[species][k].param
                          : fallbackLevel;
            if (requiredLevel > level)
                continue;

            candidates[candidateCount++] = target;
        }

        if (candidateCount == 0)
            break; // can't evolve any further at this level -- best fit found

        species = candidates[Random() % candidateCount];
    }

    return species;
}

// Called from the wild-encounter species rolls (wild_encounter.c) right
// after the normal table roll has picked a species+level. Returns
// SPECIES_NONE if the override doesn't apply (mode off) or didn't fire (90%
// of the time, or an all-legendary roster with nothing eligible) -- callers
// keep the table's species in that case.
u16 CharacterMode_RollWildOverrideSpecies(u8 level)
{
    const struct CharacterInfo *character = GetActiveCharacter();
    u16 candidates[64];
    u8 candidateCount = 0;
    u32 i;

    if (character == NULL)
        return SPECIES_NONE;
    if (Random() % 100 >= WILD_OVERRIDE_CHANCE_PERCENT)
        return SPECIES_NONE;

    for (i = 0; character->roster[i] != SPECIES_NONE && candidateCount < ARRAY_COUNT(candidates); i++)
    {
        if (!CharacterMode_IsLegendaryOrMythical(character->roster[i]))
            candidates[candidateCount++] = character->roster[i];
    }

    if (candidateCount == 0)
        return SPECIES_NONE;

    return CharacterMode_PickEvolutionStageForLevel(candidates[Random() % candidateCount], level);
}
