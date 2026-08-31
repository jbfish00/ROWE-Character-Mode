#include "global.h"
#include "character_mode.h"
#include "event_data.h"
#include "pokedex.h"  // GetSetPokedexFlag -- the "offered until caught" filter
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
// Legendaries/mythicals/Ultra Beasts are excluded from THAT roll -- they come
// from the separate 1% roll below instead, which is offered-until-caught.

#define WILD_OVERRIDE_CHANCE_PERCENT 10

// If a legendary is on the roster, a 1% chance to meet one in any area. Rolled
// BEFORE the 10% override and independent of it, so the rates compose to ~1%
// legendary / ~9.9% roster / ~89% the game's own table -- and a character with
// no legendary is completely unaffected, same code path and same rates as
// before. (Carving the 1% out of the existing 10% was rejected: it would change
// the feel of a shipped feature.)
#define WILD_LEGENDARY_CHANCE_PERCENT 1

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

// Legendary test for a ROSTER ENTRY specifically, with no CharacterMode_FamilyBase
// walk. Rosters store canonical family bases, so plain membership in
// sLegendaryFamilyBases is exact for them.
//
// This matters because FamilyBase is brutally expensive: it calls
// GetFirstEvolution (level_scaling.c), which is a triple-nested scan over
// gEvolutionTable -- for a species with no pre-evolution it compares all
// NUM_SPECIES * EVOS_PER_MON entries and finds nothing. The wild-override path
// ran that for all ~47 roster entries on every fired encounter: ~3.3M cycles,
// about 0.2 s of GBA time, measured at ~11.8 emulated frames per roll.
//
// The equivalence is not assumed -- audit_rosters.py fails the build if any
// roster entry's direct membership disagrees with its canonical base's. Today
// the only non-canonical entries are Pikachu, Galarian Zigzagoon and Paldean
// Wooper, none of them legendary.
//
// Use CharacterMode_IsLegendaryOrMythical instead for an ARBITRARY species (a
// caught mon, a rolled evolution stage) -- those are not roster entries and do
// need the walk.
static bool8 IsLegendaryRosterEntry(u16 species)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sLegendaryFamilyBases); i++)
    {
        if (sLegendaryFamilyBases[i] == species)
            return TRUE;
    }
    return FALSE;
}

static bool8 RosterHasLegendary(const struct CharacterInfo *character)
{
    u32 i;

    for (i = 0; character->roster[i] != SPECIES_NONE; i++)
    {
        if (IsLegendaryRosterEntry(character->roster[i]))
            return TRUE;
    }
    return FALSE;
}

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
// Build the legendary pool for the active character at `level`, and return how
// many entries were written. Exposed (not static) so the boot self-test can
// assert on the pool DIRECTLY rather than inferring it from a 1% roll -- see the
// warning in CharacterMode_RollWildLegendarySpecies.
//
// "Offered until caught" is filtered on the Pokedex CAUGHT flag, which costs
// zero new save state -- the reason this design is implementable in the five
// closed-binary ports too.
//
// Two consequences of using the dex, both accepted at design time: a legendary
// caught BEFORE Character Mode was enabled is never offered, and one that is
// caught then released or traded stays flagged and never returns.
u8 CharacterMode_BuildLegendaryPool(u8 level, u16 *out, u8 outCount,
                                    bool8 *outRepeatable)
{
    const struct CharacterInfo *character = GetActiveCharacter();
    u8 count = 0;
    bool8 hasOrdinary = FALSE;
    u32 i;

    if (outRepeatable != NULL)
        *outRepeatable = FALSE;
    if (character == NULL || out == NULL || outCount == 0)
        return 0;

    // A roster with no ordinary families keeps its legendaries REPEATABLE.
    // Without this, Cogita -- whose roster is a single legendary family --
    // catches it once and can then catch nothing at all for the rest of the run,
    // while still being offered by the playability threshold, which exempts her
    // precisely FOR having a legendary.
    for (i = 0; character->roster[i] != SPECIES_NONE; i++)
    {
        if (!IsLegendaryRosterEntry(character->roster[i]))
        {
            hasOrdinary = TRUE;
            break;
        }
    }

    if (outRepeatable != NULL)
        *outRepeatable = !hasOrdinary;

    for (i = 0; character->roster[i] != SPECIES_NONE && count < outCount; i++)
    {
        u16 offered;

        if (!IsLegendaryRosterEntry(character->roster[i]))
            continue;

        // Filter on the species actually OFFERED, not the family base: the few
        // multi-stage legendary lines (Cosmog, Type: Null, Kubfu, Poipole,
        // Phione) should keep offering Solgaleo until Solgaleo is caught.
        offered = CharacterMode_PickEvolutionStageForLevel(character->roster[i], level);
        if (offered == SPECIES_NONE)
            continue;

        // NB the accessor takes a NATIONAL DEX number, not a species id, and in
        // this tree those differ. Passing a species id would silently filter the
        // wrong Pokemon, which reads exactly like the feature not firing.
        if (hasOrdinary
         && GetSetPokedexFlag(SpeciesToNationalPokedexNum(offered), FLAG_GET_CAUGHT))
            continue;

        out[count++] = offered;
    }

    return count;
}

// The 1% roll. Returns SPECIES_NONE when it doesn't fire, when the character has
// no legendary, or when every legendary on the roster is already caught.
//
// ⚠️ A 1% event is the perfect hiding place for a test that cannot fail. Once the
// dex filter can suppress legendaries, "no legendary appeared" is satisfied both
// by correct suppression AND by this function never running. Any test of this
// must assert the POSITIVE direction, on a state with a known-uncaught legendary
// -- CharacterMode_BuildLegendaryPool exists so that can be done deterministically.
u16 CharacterMode_RollWildLegendarySpecies(u8 level)
{
    const struct CharacterInfo *character = GetActiveCharacter();
    u16 candidates[16];
    u8 count;

    if (character == NULL)
        return SPECIES_NONE;

    // THE DATA CHECK MUST PRECEDE THE RNG CALL. Consuming a Random() before
    // knowing the character even has a legendary shifts the encounter RNG
    // stream for every character that does not -- 113 of the 206 selectable
    // ones here -- which breaks the design's guarantee that they are completely
    // unaffected by this feature. Nothing looks broken; their rolls just stop
    // matching what the same save produced before. Unbound hit this first and
    // the spec now states it as a rule for every game.
    if (!RosterHasLegendary(character))
        return SPECIES_NONE;

    if (Random() % 100 >= WILD_LEGENDARY_CHANCE_PERCENT)
        return SPECIES_NONE;

    // Max legendaries on any one roster in this repo is 12; 16 is headroom.
    count = CharacterMode_BuildLegendaryPool(level, candidates,
                                            ARRAY_COUNT(candidates), NULL);
    if (count == 0)
        return SPECIES_NONE;

    return candidates[Random() % count];
}

u16 CharacterMode_RollWildOverrideSpecies(u8 level, u8 *outKind)
{
    const struct CharacterInfo *character = GetActiveCharacter();
    // ⚠️ This must hold the largest NON-LEGENDARY roster, not a round number.
    // At 64 it silently truncated Goh (83 non-legendary families): the loop
    // below stops at the cap, his roster is alphabetical, and so the entire
    // S-Z tail -- Sentret through Zubat, 19 families -- could never be produced
    // by the 10% override, while ENCOUNTERS.md advertised all 83. Nothing
    // failed; the feature just quietly did less than the docs promised.
    // tools/character_mode/audit_rosters.py now fails the build-time audit if
    // any roster outgrows this, so it cannot rot silently again.
    u16 candidates[CHARACTER_MAX_ROSTER_CANDIDATES];
    u8 candidateCount = 0;
    u32 i;
    u16 legendary;

    if (character == NULL)
        return SPECIES_NONE;

    // Legendary roll first, and independent -- see WILD_LEGENDARY_CHANCE_PERCENT.
    legendary = CharacterMode_RollWildLegendarySpecies(level);
    if (legendary != SPECIES_NONE)
    {
        if (outKind != NULL)
            *outKind = CHAR_WILD_ENCOUNTER_LEGENDARY;
        return legendary;
    }

    if (Random() % 100 >= WILD_OVERRIDE_CHANCE_PERCENT)
        return SPECIES_NONE;

    for (i = 0; character->roster[i] != SPECIES_NONE && candidateCount < ARRAY_COUNT(candidates); i++)
    {
        if (!IsLegendaryRosterEntry(character->roster[i]))
            candidates[candidateCount++] = character->roster[i];
    }

    if (candidateCount == 0)
        return SPECIES_NONE;

    if (outKind != NULL)
        *outKind = CHAR_WILD_ENCOUNTER_ROSTER;
    return CharacterMode_PickEvolutionStageForLevel(candidates[Random() % candidateCount], level);
}

// CharacterMode_{Set,Get}WildEncounterKind live in src/wild_encounter.c, next to
// the CreateWildMon call that clears the marker -- see the comment there. This
// file has no mutable statics and no entry in sym_ewram.txt/sym_bss.txt, and
// wild_encounter.o already has one, so putting the byte there costs nothing.


// ===========================================================================
// Gift-egg roster roll -- the weighted picker behind ScriptGiveEgg
// ===========================================================================
//
// Design ruled by the user 2026-08-26. A scripted gift "egg" hands over a
// species drawn from the active character's roster, biased so that RARER
// Pokemon are likelier: Beldum (catch rate 3) against Caterpie (255).
//
// The five rules, in the order they are applied:
//
//   1. Character Mode only. Outside it this is never called and the vanilla
//      species is given, unchanged.
//   2. Legendaries are excluded, exactly as the 10% wild override excludes
//      them -- they all sit at catch rate 3 and would otherwise take 86% of
//      Red's eggs, which is what the 1% legendary rule exists to prevent.
//   3. A family whose base is already flagged CAUGHT in the Pokedex is
//      excluded outright (weight 0), so eggs fill gaps instead of handing out
//      duplicates. Same mechanism the legendary rule uses for
//      offered-until-caught, and it costs no new save state.
//   4. Weight is 255/catchRate, scaled -- see CM_EGG_WEIGHT_SCALE.
//   5. Two fallbacks, narrowest first: if every eligible family is caught,
//      re-open the whole non-legendary roster; if the roster has NO
//      non-legendary family at all, allow legendaries. ⚠️ That last branch is
//      not hypothetical and not general: it is TOBIAS, and measured to be
//      Tobias alone -- he is the only SELECTABLE character whose roster (2
//      families) is 100% legendary. Three more (Penny, Adaman, Irida) have
//      exactly one non-legendary family, so their egg is deterministic; that
//      is a property of their rosters, not a bug here.
//
// ⚠️ THE DATA CHECK MUST PRECEDE THE RNG CALL. Building the pool first and
// returning SPECIES_NONE without drawing is deliberate: a character with no
// pool must not consume a Random(), or every downstream roll in the game
// shifts for them and nothing looks broken. Unbound hit this, ROWE shipped it
// wrong in the legendary rule and fixed it in a5befab7. Do not "simplify" the
// early return into a draw-then-discard.
// (pool mode constants live in character_mode.h -- see the note there)



// 255/catchRate in integer arithmetic collapses the middle of the range --
// 255/45 truncates to 5 and 255/3 is 85, so a cr-45 family would read as 1/17th
// of Beldum instead of 1/15th, and every cr>127 family would land on 1 or 2 and
// become indistinguishable. Scaling by 100 first keeps the ratios intact in u32
// and still cannot overflow: 25500 * 96 candidates = 2,448,000, well inside u32.
#define CM_EGG_WEIGHT_SCALE 100
#define CM_EGG_WEIGHT_MAX   (255 * CM_EGG_WEIGHT_SCALE)  // catchRate 1

static u32 EggWeightForSpecies(u16 species)
{
    u8 catchRate = gBaseStats[species].catchRate;

    // ⚠️ A species with NO gBaseStats row reads 0 out of the zero-filled tail of
    // the table, and 255/0 is undefined behaviour, not a big number. This is the
    // SPECIES_ENAMORUS hazard from §12.6 arriving somewhere new: that species
    // sits in sLegendaryFamilyBases with no base-stats row, and any future
    // roster pass could add another. Skipping it here is the safe direction --
    // an unweighted species simply cannot be drawn.
    if (catchRate == 0)
        return 0;

    return CM_EGG_WEIGHT_MAX / catchRate;
}

// Already-caught test, on the FAMILY BASE (the user's ruling). Note this reads
// the Pokedex CAUGHT flag, so it is permanent: releasing or trading a Beldum
// away does not make the family eligible again, and evolving one marks every
// stage caught. A species with no national dex number returns 0 from
// GetSetPokedexFlag (the §6 out-of-bounds guard) and so counts as NOT caught,
// which keeps it eligible -- the safe direction, since the alternative silently
// shrinks the pool.
static bool8 EggFamilyAlreadyCaught(u16 species)
{
    u16 dexNum = SpeciesToNationalPokedexNum(species);

    return GetSetPokedexFlag(dexNum, FLAG_GET_CAUGHT) != 0;
}

// Public wrapper so a test can assert the CURVE deterministically. Asserting
// the weighting from drawn species alone needs thousands of trials to tell
// 255/catchRate from flat, and a distribution test that cannot distinguish
// those is the vacuity shape this repo keeps re-inventing.
u32 CharacterMode_EggWeight(u16 species)
{
    return EggWeightForSpecies(species);
}

// Fills `out` with the eligible families for one pool mode and returns how many.
// Split out from the roll so a test can assert the POOL deterministically --
// asserting only on drawn species would need thousands of trials to notice that
// an exclusion had stopped working.
u8 CharacterMode_BuildEggPool(u8 mode, u16 *out, u8 outCount)
{
    const struct CharacterInfo *character = GetActiveCharacter();
    u8 count = 0;
    u32 i;

    if (character == NULL || out == NULL)
        return 0;

    for (i = 0; character->roster[i] != SPECIES_NONE && count < outCount; i++)
    {
        u16 species = character->roster[i];

        if (mode != CM_EGG_POOL_ANY && IsLegendaryRosterEntry(species))
            continue;
        if (mode == CM_EGG_POOL_UNCAUGHT && EggFamilyAlreadyCaught(species))
            continue;
        if (EggWeightForSpecies(species) == 0)
            continue;

        out[count++] = species;
    }

    return count;
}

u16 CharacterMode_RollEggSpecies(void)
{
    u16 candidates[CHARACTER_MAX_ROSTER_CANDIDATES];
    u32 total = 0;
    u32 roll;
    u8 count;
    u8 mode;
    u32 i;

    if (!InCharacterMode() || GetActiveCharacter() == NULL)
        return SPECIES_NONE;

    // Narrowest pool first; widen only when the narrower one came back empty.
    for (mode = CM_EGG_POOL_UNCAUGHT; mode <= CM_EGG_POOL_ANY; mode++)
    {
        count = CharacterMode_BuildEggPool(mode, candidates, ARRAY_COUNT(candidates));
        if (count != 0)
            break;
    }

    // Data check BEFORE the RNG -- see the block comment above.
    if (count == 0)
        return SPECIES_NONE;

    for (i = 0; i < count; i++)
        total += EggWeightForSpecies(candidates[i]);

    if (total == 0)
        return SPECIES_NONE;

    // Random32(), not Random(): the weight sum passes 65535 with as few as
    // three cr-3 families, so a u16 draw would silently never reach the tail of
    // the pool -- it would look like a working feature with a biased curve.
    roll = Random32() % total;

    for (i = 0; i < count; i++)
    {
        u32 weight = EggWeightForSpecies(candidates[i]);

        if (roll < weight)
            return candidates[i];
        roll -= weight;
    }

    // Unreachable while total is the sum of the same weights, but a silent
    // fallthrough here would hand back SPECIES_NONE and read as "the gift did
    // nothing"; the last candidate is the honest answer.
    return candidates[count - 1];
}
