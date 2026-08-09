#include "global.h"
#include "character_mode.h"
#include "field_control_avatar.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_script_commands.h"
#include "battle_arena.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_pyramid.h"
#include "battle_scripts.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_util.h"
#include "berry.h"
#include "bg.h"
#include "data.h"
#include "daycare.h"
#include "dexnav.h"
#include "decompress.h"
#include "dma3.h"
#include "event_data.h"
#include "evolution_scene.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "main.h"
#include "malloc.h"
#include "trade.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "recorded_battle.h"
#include "roamer.h"
#include "overworld.h"
#include "safari_zone.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "trig.h"
#include "tv.h"
#include "util.h"
#include "wild_encounter.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/battle_config.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "cable_club.h"
#include "../gflib/string_util.h"
#include "printf.h"
#include "mgba.h"

//Easy Mode Levels Scaling
const u8 Easy_Mode_Trainer_Max_Pokemon_Number[] = {2,2,3,3,3,3,4,4,4,4,4,4,5,5,5,5,6,6,6};					//Trainers Number of Pokemon
const u8 Easy_Mode_Boss_Pokemon_Number[] = {3,3,4,4,4,5,5,5,5,5,6,6,6,6,6,6,6,6,6};					//Gym Leaders Number of Pokemon
const u8 Easy_Mode_Double_Max_Pokemon_Number[] = {2,2,2,2,2,4,4,4,4,4,4,4,4,4,6,6,6,6,6};					//Number of Pokemon in a Double Battle
const u8 Easy_Mode_Trainer_Pokemon_Min_Level[] = {6,10,13,16,19,21,23,25,27,29,31,33,35,37,39,42,45,50,60};		//Levels for Trainer Pokemon
const u8 Easy_Mode_Boss_Pokemon_Min_Level[] = {12,16,20,23,26,28,30,32,34,36,38,41,44,48,52,55,58,64,70};		//Levels for Gym Leaders
const u8 Easy_Mode_Min_Wild_Pokemon_Level[] = {4,8,12,15,18,20,22,24,26,28,30,32,34,36,38,40,43,48,60};		//Levels for Wild Pokemon

//Normal Mode Levels
const u8 Normal_Mode_Trainer_Max_Pokemon_Number[] = {2,2,3,3,3,3,4,4,4,4,4,4,5,5,5,5,6,6,6};				//Trainers Number of Pokemon
const u8 Normal_Mode_Boss_Pokemon_Number[] = {3,3,4,4,4,5,5,5,5,5,6,6,6,6,6,6,6,6,6};				//Gym Leaders Number of Pokemon
const u8 Normal_Mode_Double_Max_Pokemon_Number[] = {2,2,2,2,2,4,4,4,4,4,4,4,4,4,6,6,6,6,6};				//Number of Pokemon in a Double Battle
const u8 Normal_Mode_Boss_Pokemon_Min_Level[] = {13,18,22,25,28,31,34,37,40,43,46,49,51,54,57,64,70,76,82};	//Levels for Gym Leaders
const u8 Normal_Mode_Trainer_Pokemon_Min_Level[] = {7,11,14,17,20,23,25,28,31,34,36,39,42,45,48,51,55,60,70};	//Levels for Trainer Pokemon
const u8 Normal_Mode_Min_Wild_Pokemon_Level[] = {5,9,12,15,17,19,21,23,25,27,30,32,35,37,40,43,47,53,65};	//Levels for Wild Pokemon

//Hard Mode Levels
const u8 Hard_Mode_Trainer_Max_Pokemon_Number[] = {2,2,3,3,3,3,4,4,4,4,4,4,5,5,5,5,6,6,6};				//Trainers Number of Pokemon
const u8 Hard_Mode_Boss_Pokemon_Number[] = {3,3,4,4,4,5,5,5,5,5,6,6,6,6,6,6,6,6,6};				//Gym Leaders Number of Pokemon
const u8 Hard_Mode_Double_Max_Pokemon_Number[] = {2,2,2,2,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6};				//Number of Pokemon in a Double Battle
const u8 Hard_Mode_Boss_Pokemon_Min_Level[] = {13,18,22,25,28,31,34,37,40,44,47,50,53,56,59,66,72,77,85};	//Levels for Gym Leaders
const u8 Hard_Mode_Trainer_Pokemon_Min_Level[] = {7,12,15,18,21,24,27,30,33,36,39,42,45,48,52,57,62,68,73};	//Levels for Trainer Pokemon
const u8 Hard_Mode_Min_Wild_Pokemon_Level[] = {5,9,12,15,18,20,23,25,27,30,33,36,39,42,46,51,56,61,68};	//Levels for Wild Pokemon

//Order Mode
const u8 Normal_Mode_Min_Wild_Pokemon_Level_Order[] = {5,8,11,14,17,20,23,26,29,32,35,38,41,44,47,50,53,56,59,62,65};

#define LEVEL_SCALING_FOR_TRAINERS FALSE

u16 SplitEvolutions(u16 basespecies, u8 level);
u16 CheckforLegendary(u16 species);
u16 GetCurrentMapWildPokemon(u8 isWaterMon, u8 index);
u16 GetRandomizedWildPokemon(u16 basespecies, u8 level, u16 heldItem);
u16 GetRandomizedTrainerPokemon(u16 basespecies, u8 level);
u8 getMapLevel(u8 id);
u8 getOrder(u8 id);
u8 getCityOrder(u8 id);
u8 getScaledWildPokemonLevel();

// NB: these legacy per-mode arrays are superseded by gScalingInfo, but 53 call
// sites still index them by GetNumBadges() -- which now reaches 18 (16 badges +
// after-league + endgame). They are padded to 19 entries with the 2.X values so
// those indexes stay in bounds.
//Wild Pokemon Scaling
// 19 entries -- GetNumBadges() reaches 18. (GetCurrentMovePowerLimit()
// reads gScalingInfo instead; this array only survives for one legacy
// call site, but it must still be long enough to index safely.)
const u8 MovePowerLimit[] = {60,70,75,80,85,90,95,100,125,150,175,200,250,250,250,250,250,250,250};

u8 GetNumBadges(void);   // defined below; the scaling table keys off it

// ===== 2.X scaling table + level caps (ported from RoweRepo) =====
// 2.X replaced the flat per-badge arrays with one table keyed by
// [difficulty][what][badges], which is also what drives its level caps.
// 19 badge columns: 0-16 badges, then post-league and endgame.
#define SCALING_AFTER_LEAGUE        17
#define SCALING_ENDGAME             18
#define NUM_CURRENT_SCALING_LEVELS  19
#define LITTLE_CUP_LEVEL            5

enum{
	SCALING_WILD_MON_LEVEL,
	SCALING_TRAINER_MON_LEVEL,
	SCALING_BOSS_MON_LEVEL,
	SCALING_TRAINER_MAX_MON_NUM,
	SCALING_DOUBLE_MAX_MON_NUM,
	SCALING_BOSS_MAX_MON_NUM,
	SCALING_WHITEOUT_MONEY,
	SCALING_MOVE_POWER_LIMIT,
	NUM_SCALING_OPTIONS,
};

const u16 gScalingInfo[NUM_DIFFICULTIES][NUM_SCALING_OPTIONS][NUM_CURRENT_SCALING_LEVELS] = {
	[DIFFICULTY_EASY] = {               //  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18
		[SCALING_WILD_MON_LEVEL]      = {  4,  8, 12, 15, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 43, 48, 60 },
		[SCALING_TRAINER_MON_LEVEL]   = {  6, 10, 13, 16, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 42, 45, 50, 60 },
		[SCALING_BOSS_MON_LEVEL]      = { 12, 16, 20, 23, 26, 28, 30, 32, 34, 36, 38, 41, 44, 48, 52, 55, 58, 64, 70 },
		[SCALING_TRAINER_MAX_MON_NUM] = {  2,  2,  3,  3,  3,  3,  4,  4,  4,  4,  4,  4,  5,  5,  5,  5,  6,  6,  6 },
		[SCALING_DOUBLE_MAX_MON_NUM]  = {  2,  2,  2,  2,  2,  4,  4,  4,  4,  4,  4,  4,  4,  4,  6,  6,  6,  6,  6 },
		[SCALING_BOSS_MAX_MON_NUM]    = {  3,  3,  4,  4,  4,  5,  5,  5,  5,  5,  6,  6,  6,  6,  6,  6,  6,  6,  6 },
		[SCALING_MOVE_POWER_LIMIT]    = { 60, 70, 75, 80, 85, 90, 95,100,125,150,175,200,250,275,300,325,350,375,500 },
		[SCALING_WHITEOUT_MONEY]      = {  8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,116,120,120,120,120,120 },
	},
	[DIFFICULTY_NORMAL] = {             //  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18
		[SCALING_WILD_MON_LEVEL]      = {  5,  9, 12, 15, 17, 19, 21, 23, 25, 27, 30, 32, 35, 37, 40, 43, 47, 53, 65 },
		[SCALING_TRAINER_MON_LEVEL]   = {  7, 11, 14, 17, 20, 23, 25, 28, 31, 34, 36, 39, 42, 45, 48, 51, 55, 60, 70 },
		[SCALING_BOSS_MON_LEVEL]      = { 13, 18, 22, 25, 28, 31, 34, 37, 40, 43, 46, 49, 51, 54, 57, 64, 70, 76, 82 },
		[SCALING_TRAINER_MAX_MON_NUM] = {  2,  2,  3,  3,  3,  3,  4,  4,  4,  4,  4,  4,  5,  5,  5,  5,  6,  6,  6 },
		[SCALING_DOUBLE_MAX_MON_NUM]  = {  2,  2,  2,  2,  2,  4,  4,  4,  4,  4,  4,  4,  4,  4,  6,  6,  6,  6,  6 },
		[SCALING_BOSS_MAX_MON_NUM]    = {  3,  3,  4,  4,  4,  5,  5,  5,  5,  5,  6,  6,  6,  6,  6,  6,  6,  6,  6 },
		[SCALING_MOVE_POWER_LIMIT]    = { 60, 70, 75, 80, 85, 90, 95,100,125,150,175,200,250,275,300,325,350,375,500 },
		[SCALING_WHITEOUT_MONEY]      = {  8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,116,120,120,120,120,120 },
	},
	[DIFFICULTY_HARD] = {               //  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18
		[SCALING_WILD_MON_LEVEL]      = {  5,  9, 12, 15, 18, 20, 23, 25, 27, 30, 33, 36, 39, 42, 46, 51, 56, 61, 68 },
		[SCALING_TRAINER_MON_LEVEL]   = {  7, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 52, 57, 62, 68, 73 },
		[SCALING_BOSS_MON_LEVEL]      = { 13, 18, 22, 25, 28, 31, 34, 37, 40, 44, 47, 50, 53, 56, 59, 66, 72, 77, 85 },
		[SCALING_TRAINER_MAX_MON_NUM] = {  2,  2,  3,  3,  3,  3,  4,  4,  4,  4,  4,  4,  5,  5,  5,  5,  6,  6,  6 },
		[SCALING_DOUBLE_MAX_MON_NUM]  = {  2,  2,  2,  2,  4,  4,  4,  4,  4,  4,  4,  4,  6,  6,  6,  6,  6,  6,  6 },
		[SCALING_BOSS_MAX_MON_NUM]    = {  3,  3,  4,  4,  4,  5,  5,  5,  5,  5,  6,  6,  6,  6,  6,  6,  6,  6,  6 },
		[SCALING_MOVE_POWER_LIMIT]    = { 60, 70, 75, 80, 85, 90, 95,100,125,150,175,200,250,275,300,325,350,375,500 },
		[SCALING_WHITEOUT_MONEY]      = {  8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96,104,116,120,120,120,120,120 },
	},
};

// 2.X ordering (EASY, NORMAL, HARD) -- gScalingInfo is indexed by this.
u8 GetGameDifficultyLevel(){
	if (FlagGet(FLAG_EASY_MODE))
		return DIFFICULTY_EASY;
	else if (FlagGet(FLAG_HARD_MODE))
		return DIFFICULTY_HARD;
	else
		return DIFFICULTY_NORMAL;
}

static u16 getScalingDataForBadge(u8 type, u8 numBadges){
	if (numBadges >= NUM_CURRENT_SCALING_LEVELS)
		numBadges = NUM_CURRENT_SCALING_LEVELS - 1;
	return gScalingInfo[GetGameDifficultyLevel()][type][numBadges];
}

static u16 getScalingData(u8 type){
	return getScalingDataForBadge(type, GetNumBadges());
}

// The cap is the level of the current gym leader's ace: boss level for the
// badge count, plus its party size (2.X adds the two).
u16 GetCurrentRawLevelCap(void)
{
	if (GetNumBadges() >= SCALING_ENDGAME)
		return MAX_LEVEL;

	return getScalingData(SCALING_BOSS_MON_LEVEL)
	     + getScalingData(SCALING_BOSS_MAX_MON_NUM);
}

u16 GetCurrentLevelCap(void)
{
	if (FlagGet(FLAG_LITTLE_CUP_MODE) && !FlagGet(FLAG_GRINDLESS_MODE))
		return LITTLE_CUP_LEVEL;

	return GetCurrentRawLevelCap();
}

u16 GetNextLevelCap(void)
{
	u8 badges = GetNumBadges();

	if (badges >= SCALING_ENDGAME)
		return MAX_LEVEL;

	return getScalingDataForBadge(SCALING_BOSS_MON_LEVEL, badges + 1)
	     + getScalingDataForBadge(SCALING_BOSS_MAX_MON_NUM, badges + 1);
}




u8 IsHardMode(){
	if (FlagGet(FLAG_HARD_MODE))
		return 1;
	else
		return 0;
}

#include "data/pokemon/pre_evolution.h"

// Reverse of gEvolutionTable: species -> the species that evolves INTO it, or
// SPECIES_NONE when nothing does.
//
// WHY. GetFirstEvolution used to be a triple-nested scan: for each walk-back
// step it swept all NUM_SPECIES * EVOS_PER_MON entries looking for anything
// targeting the current species. For a species with no pre-evolution that is
// ~14,820 comparisons that find nothing, on EVERY call -- and it has nine
// callers, including CharacterMode_FamilyBase (the catch gate, hit on every
// caught species) and six learnset helpers in pokemon.c. Measured through the
// wild-encounter path before it stopped calling this: ~3.3M cycles, about
// 0.2 s of GBA time, per fired encounter.
//
// It lives in ROM, generated by tools/character_mode/emit_pre_evolution.py, and
// NOT built at boot: EWRAM has under 1 KB free in this tree, so a 2,964-byte
// runtime cache overflows it and the link fails outright.
// The reference implementation, kept so the fast path can be PROVEN equivalent
// rather than assumed. CM_REQ_VERIFY_PREEVO sweeps every species through both.
// Do not call it in gameplay code -- it is the slow version on purpose.
u16 GetFirstEvolutionReference(u16 species){
    int i, j, k;
    bool8 found;

    for (i = 0; i < EVOS_PER_MON; i++)
    {
        found = FALSE;
        for (j = 1; j < NUM_SPECIES; j++)
        {
            for (k = 0; k < EVOS_PER_MON; k++)
            {
                if (gEvolutionTable[j][k].targetSpecies == species)
                {
                    species = j;
                    found = TRUE;
                    break;
                }
            }

            if (found)
                break;
        }

        if (j == NUM_SPECIES)
            break;
    }

    return species;
}

u16 GetFirstEvolution(u16 species){
    u32 i;

    // Same bound as the old outer loop, so a cyclic evolution chain terminates
    // after exactly as many steps and returns exactly the same species.
    for (i = 0; i < EVOS_PER_MON; i++)
    {
        u16 prev;

        if (species >= NUM_SPECIES)
            break;
        prev = gPreEvolutionSpecies[species];
        if (prev == SPECIES_NONE)
            break;
        species = prev;
    }

    return species;
}


// 2.X: 16 badges. The 8 Hoenn gyms are still counted the way 1.9.4 did it --
// by the TM each leader hands out (ROWE never set the vanilla badge flags for
// them) -- while the 8 Johto gyms on the Sevii Islands set FLAG_RECEIVED_BADGE_09
// .. _16 directly. Counted highest-first, so the Johto badges stack on top of
// the Hoenn eight.
//
// The post-league values 1.9.4 used (GAME_CLEAR = 9, RAYQUAZA = 10) now map to
// the scaling table's SCALING_AFTER_LEAGUE (17) and SCALING_ENDGAME (18) rows,
// which is what those rows are for.
// This is the index into every scaling table in this file -- wild levels, trainer
// levels, level caps, trainer party sizes, move power limits, item tiers. Getting it
// wrong does not crash; the whole game just quietly stops getting harder.
//
// It used to infer the Hoenn badge count from the gym leaders' TM flags
// (FLAG_RECEIVED_TM39 -> 1 badge, TM08 -> 2, ...). NOTHING in the tree ever sets those
// flags -- the gym scripts hand the TM over with giveitem, which does not flag it -- so
// this returned 0 for the entire Hoenn game no matter how many gyms you had beaten.
// Count the badges the gyms actually award instead: the vanilla FLAG_BADGE01_GET.. run
// for Hoenn and the separate FLAG_RECEIVED_BADGE_09..16 block for the Johto eight.
u8 GetNumBadges()
{
	u16 flag;
	u8 count = 0;

	if (FlagGet(FLAG_DEFEATED_RAYQUAZA))
		return SCALING_ENDGAME;        // 18
	if (FlagGet(FLAG_SYS_GAME_CLEAR))
		return SCALING_AFTER_LEAGUE;   // 17

	for (flag = FLAG_BADGE01_GET; flag < FLAG_BADGE01_GET + NUM_BADGES_PER_REGION; flag++)
	{
		if (FlagGet(flag))
			count++;
	}

	for (flag = FLAG_RECEIVED_BADGE_09; flag <= FLAG_RECEIVED_BADGE_16; flag++)
	{
		if (FlagGet(flag))
			count++;
	}

	return count;   // 0..16, and the tables have 19 columns, so this always indexes safely
};

u8 GetCurrentMovePowerLimit(){
	u16 limit;

	if (FlagGet(FLAG_NEW_GAME_PLUS))
		return 250;

	// 2.X sources this from gScalingInfo (difficulty-aware, 16-badge aware)
	limit = getScalingData(SCALING_MOVE_POWER_LIMIT);
	if (limit > 255)
		limit = 255;

	return limit;
}

u8 checkLevel(u8 level){
	if(level >= 100)
		return 100;
	else
		return level;
}

u8 getLevelBoost(){
	u8 levelboost = Random() % (GetNumBadges()+2);
	u8 levelboosthard = Random() % GetNumBadges() + levelboost;
	if(FlagGet(FLAG_HARD_MODE)||(FlagGet(FLAG_SYS_GAME_CLEAR) && FlagGet(FLAG_NORMAL_MODE)))
		return levelboosthard;
	else
		return levelboost;
}

u8 GetPlayerPartyMaxLevel(void)
{
    u32 i;
	u8 maxlevel = 0;
	u8 currentlevel = 0;
	
	for (i = 0; i < CalculatePlayerPartyCount(); i++)
    {
		currentlevel = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
		if(maxlevel < currentlevel)
			maxlevel = currentlevel;
    }
	
	return maxlevel;
}

static bool32 IsMonValidSpecies(struct Pokemon *pokemon)
{
    u16 species = GetMonData(pokemon, MON_DATA_SPECIES2);
    if (species == SPECIES_NONE || species == SPECIES_EGG)
    {
        return FALSE;
    }
    return TRUE;
}

u8 GetPlayerUsableMons(void)
{
    int i;
	u8 PartySize = 0;
    struct Pokemon *pokemon = gPlayerParty;

    for (i = 0; i < PARTY_SIZE; i++, pokemon++)
    {
        if (IsMonValidSpecies(pokemon) && GetMonData(pokemon, MON_DATA_HP) != 0)
        {
            PartySize++;
        }
    }
    return PartySize;
}

u8 GetPlayerPartySize(void)
{
    int i;
	u8 PartySize = 0;
    struct Pokemon *pokemon = gPlayerParty;

    for (i = 0; i < PARTY_SIZE; i++, pokemon++)
    {
        if (IsMonValidSpecies(pokemon))
        {
            PartySize++;
        }
    }
    return PartySize;
}

u16 GetFirstStage(u16 species)
{
    int i, j, k;
    bool8 found;

    // Working backwards up to 5 times seems arbitrary, since the maximum number
    // of times would only be 3 for 3-stage evolutions.
    for (i = 0; i < EVOS_PER_MON; i++)
    {
        found = FALSE;
        for (j = 1; j < NUM_SPECIES; j++)
        {
            for (k = 0; k < EVOS_PER_MON; k++)
            {
                if (gEvolutionTable[j][k].targetSpecies == species)
                {
                    species = j;
                    found = TRUE;
                    break;
                }
            }

            if (found)
                break;
        }

        if (j == NUM_SPECIES)
            break;
    }

    return species;
}

u16 GetBaseSpecie(u16 basespecies){
	u16 randomizedspecie  = GetRandomFirstStage(basespecies);
	return randomizedspecie;
}

u8 getGymLeaderMinLevel(){
	u8 NewGamePlusCount = VarGet(VAR_NEW_GAME_PLUS_COUNT);

	if(FlagGet(FLAG_NEW_GAME_PLUS) && LEVEL_SCALING_FOR_TRAINERS){
		if(FlagGet(FLAG_HARD_MODE)){
			if(GetPlayerPartyMaxLevel() > (Hard_Mode_Boss_Pokemon_Min_Level[GetNumBadges()]))
				return GetPlayerPartyMaxLevel() + NewGamePlusCount;
			else
				return Hard_Mode_Boss_Pokemon_Min_Level[GetNumBadges()] + NewGamePlusCount;
		}
		else if(FlagGet(FLAG_EASY_MODE)){
			if(GetPlayerPartyMaxLevel() > (Easy_Mode_Boss_Pokemon_Min_Level[GetNumBadges()]))
				return GetPlayerPartyMaxLevel() + NewGamePlusCount;
			else
				return Easy_Mode_Boss_Pokemon_Min_Level[GetNumBadges()] + NewGamePlusCount;
		}
		else{
			if(GetPlayerPartyMaxLevel() > (Normal_Mode_Boss_Pokemon_Min_Level[GetNumBadges()]))
				return GetPlayerPartyMaxLevel() + NewGamePlusCount;
			else
				return Normal_Mode_Boss_Pokemon_Min_Level[GetNumBadges()] + NewGamePlusCount;
		}
	}
	else{
		if(FlagGet(FLAG_HARD_MODE))
			return Hard_Mode_Boss_Pokemon_Min_Level[GetNumBadges()];
		else if(FlagGet(FLAG_EASY_MODE))
			return Easy_Mode_Boss_Pokemon_Min_Level[GetNumBadges()];
		else
			return Normal_Mode_Boss_Pokemon_Min_Level[GetNumBadges()];
	}
}

u8 getTrainerMinLevel(){
	u8 NewGamePlusCount = VarGet(VAR_NEW_GAME_PLUS_COUNT);
	u8 levelboost = getLevelBoost();

	if(FlagGet(FLAG_NEW_GAME_PLUS) && LEVEL_SCALING_FOR_TRAINERS){
		if(FlagGet(FLAG_HARD_MODE)){
			if(GetPlayerPartyMaxLevel() > (Hard_Mode_Trainer_Pokemon_Min_Level[GetNumBadges()] + levelboost))
				return GetPlayerPartyMaxLevel() + NewGamePlusCount;
			else
				return Hard_Mode_Trainer_Pokemon_Min_Level[GetNumBadges()] + levelboost + NewGamePlusCount;
		}
		else if(FlagGet(FLAG_EASY_MODE)){
			if(GetPlayerPartyMaxLevel() > (Easy_Mode_Trainer_Pokemon_Min_Level[GetNumBadges()] + levelboost))
				return GetPlayerPartyMaxLevel() + NewGamePlusCount;
			else
				return Easy_Mode_Trainer_Pokemon_Min_Level[GetNumBadges()] + levelboost + NewGamePlusCount;
		}
		else{
			if(GetPlayerPartyMaxLevel() > (Normal_Mode_Trainer_Pokemon_Min_Level[GetNumBadges()] + levelboost))
				return GetPlayerPartyMaxLevel();
			else
				return Normal_Mode_Trainer_Pokemon_Min_Level[GetNumBadges()] + levelboost + NewGamePlusCount;
		}
	}
	else{
		if(FlagGet(FLAG_HARD_MODE))
			return Hard_Mode_Trainer_Pokemon_Min_Level[GetNumBadges()]+levelboost;
		else if(FlagGet(FLAG_EASY_MODE))
			return Easy_Mode_Trainer_Pokemon_Min_Level[GetNumBadges()]+levelboost;
		else
			return Normal_Mode_Trainer_Pokemon_Min_Level[GetNumBadges()]+levelboost;
	}
}

u8 getWildPokemonLevel(){
	u8 NewGamePlusCount = VarGet(VAR_NEW_GAME_PLUS_COUNT);
	//u8 ability = getMonAbility(&gPlayerParty[0]);
	u8 levelboost = getLevelBoost();
	if(FlagGet(FLAG_HARD_MODE))
		return Hard_Mode_Min_Wild_Pokemon_Level[GetNumBadges()] + getLevelBoost() + NewGamePlusCount;
	else if(FlagGet(FLAG_EASY_MODE))
		return Easy_Mode_Min_Wild_Pokemon_Level[GetNumBadges()] + getLevelBoost() + NewGamePlusCount;
	else
		return Normal_Mode_Min_Wild_Pokemon_Level[GetNumBadges()] + getLevelBoost() + NewGamePlusCount;
}

u8 getMinWildPokemonLevel(){
	u8 NewGamePlusCount = VarGet(VAR_NEW_GAME_PLUS_COUNT);
	//u8 ability = getMonAbility(&gPlayerParty[0]);
	if(FlagGet(FLAG_HARD_MODE))
		return Hard_Mode_Min_Wild_Pokemon_Level[GetNumBadges()] + getLevelBoost() + NewGamePlusCount;
	else if(FlagGet(FLAG_EASY_MODE))
		return Easy_Mode_Min_Wild_Pokemon_Level[GetNumBadges()] + getLevelBoost() + NewGamePlusCount;
	else
		return Normal_Mode_Min_Wild_Pokemon_Level[GetNumBadges()] + getLevelBoost() + NewGamePlusCount;
}

u8 getScaledWildPokemonLevel(){
	u8 NewGamePlusCount = VarGet(VAR_NEW_GAME_PLUS_COUNT);
	//u8 ability = getMonAbility(&gPlayerParty[0]);
	if(FlagGet(FLAG_HARD_MODE))
		return Hard_Mode_Min_Wild_Pokemon_Level[GetNumBadges()] + getLevelBoost() + NewGamePlusCount;
	else if(FlagGet(FLAG_EASY_MODE))
		return Easy_Mode_Min_Wild_Pokemon_Level[GetNumBadges()] + getLevelBoost() + NewGamePlusCount;
	else
		return Normal_Mode_Min_Wild_Pokemon_Level[GetNumBadges()] + getLevelBoost() + NewGamePlusCount;
}

u8 getTrainerPokemonNum(){
	u8 NewGamePlusCount = VarGet(VAR_NEW_GAME_PLUS_COUNT);
	u8 PartySize = GetPlayerUsableMons();

	if(FlagGet(FLAG_NEW_GAME_PLUS) && LEVEL_SCALING_FOR_TRAINERS){
		if(FlagGet(FLAG_HARD_MODE)){
			if(PartySize > Hard_Mode_Trainer_Max_Pokemon_Number[GetNumBadges()])
				return PartySize + NewGamePlusCount;
			else
				return Hard_Mode_Trainer_Max_Pokemon_Number[GetNumBadges()] + NewGamePlusCount;
		}
		else if(FlagGet(FLAG_EASY_MODE)){
			if(PartySize > Easy_Mode_Trainer_Max_Pokemon_Number[GetNumBadges()])
				return PartySize + NewGamePlusCount;
			else
				return Easy_Mode_Trainer_Max_Pokemon_Number[GetNumBadges()] + NewGamePlusCount;
		}
		else{
			if(PartySize > Normal_Mode_Trainer_Max_Pokemon_Number[GetNumBadges()])
				return PartySize + NewGamePlusCount;
			else
				return Normal_Mode_Trainer_Max_Pokemon_Number[GetNumBadges()] + NewGamePlusCount;
		}
	}
	else{
		if(FlagGet(FLAG_HARD_MODE))
			return Hard_Mode_Trainer_Max_Pokemon_Number[GetNumBadges()];
		else if(FlagGet(FLAG_EASY_MODE))
			return Easy_Mode_Trainer_Max_Pokemon_Number[GetNumBadges()];
		else
			return Normal_Mode_Trainer_Max_Pokemon_Number[GetNumBadges()];
	}
}

u8 getLeaderPokemonNum(){
	u8 NewGamePlusCount = VarGet(VAR_NEW_GAME_PLUS_COUNT);
	u8 PartySize = GetPlayerUsableMons();

	if(FlagGet(FLAG_NEW_GAME_PLUS) && LEVEL_SCALING_FOR_TRAINERS){
		if(FlagGet(FLAG_HARD_MODE)){
			if(PartySize > Hard_Mode_Boss_Pokemon_Number[GetNumBadges()])
				return PartySize + NewGamePlusCount;
			else
				return Hard_Mode_Boss_Pokemon_Number[GetNumBadges()] + NewGamePlusCount;
		}
		else if(FlagGet(FLAG_EASY_MODE)){
			if(PartySize > Easy_Mode_Boss_Pokemon_Number[GetNumBadges()])
				return PartySize + NewGamePlusCount;
			else
				return Easy_Mode_Boss_Pokemon_Number[GetNumBadges()] + NewGamePlusCount;
		}
		else{
			if(PartySize > Normal_Mode_Boss_Pokemon_Number[GetNumBadges()])
				return PartySize + NewGamePlusCount;
			else
				return Normal_Mode_Boss_Pokemon_Number[GetNumBadges()] + NewGamePlusCount;
		}
	}
	else{
		if(FlagGet(FLAG_HARD_MODE))
			return Hard_Mode_Boss_Pokemon_Number[GetNumBadges()];
		else if(FlagGet(FLAG_EASY_MODE))
			return Easy_Mode_Boss_Pokemon_Number[GetNumBadges()];
		else
			return Normal_Mode_Boss_Pokemon_Number[GetNumBadges()];
	}
}

u8 getDoubleTrainerPokemonNum(){
	if(FlagGet(FLAG_HARD_MODE))
		return Hard_Mode_Double_Max_Pokemon_Number[GetNumBadges()];
	else if(FlagGet(FLAG_EASY_MODE))
		return Easy_Mode_Double_Max_Pokemon_Number[GetNumBadges()];
	else
		return Normal_Mode_Double_Max_Pokemon_Number[GetNumBadges()];
}

u8 getLevelDifference(){
	u8 easy = Easy_Mode_Boss_Pokemon_Min_Level[GetNumBadges()];
	u8 level = getGymLeaderMinLevel();
	u8 difference = level - easy;
	if(FlagGet(FLAG_SYS_GAME_CLEAR))
		return difference*2;
	else
	return difference;
}

bool8 IsPokemonValid(u16 mon)
{
	if(mon > NUM_SPECIES || mon <= 0 || mon == SPECIES_NONE)
		return FALSE;
	else
		return TRUE;
}

u16 GetWildPokemon(u16 basespecies, u8 level, u16 heldItem){
	//Variables
	u16 split = SplitEvolutions(basespecies,level);
	u8 numbadges = GetNumBadges();
	u8 rand = 0;
	u8 FriendshipLevel = 24;
	u8 BadgesMidgame = 5;
	u8 BadgesLategame = 7;
	
	if(basespecies == SPECIES_AUDINO || basespecies == SPECIES_RELICANTH)
		return basespecies;
	// ⚠️ Character Mode outranks the wild RANDOMIZERS -- and only those two
	// branches. The rest of this function is ordinary evolution-stage scaling
	// that Character Mode players need exactly as much as anyone else; an early
	// return here would hand them base-stage wild mons for the whole game.
	//
	// The invariant is enforced HERE rather than only at the mode menu because
	// the Game Modes menu can raise FLAG_RANDOMIZED_MODE at any point after the
	// character is committed. Without it, GetRandomFirstStage() remapped the
	// species the 10% roster override (and the 1% legendary) had just chosen
	// onto an unrelated family -- deleting the override outright, leaving the
	// catch gate to refuse the result, while the battle still announced it as
	// "destined for {CHARACTER}". Precisely the false bug report the encounter
	// markers exist to prevent.
	else if(!InCharacterMode() && FlagGet(FLAG_RANDOMIZED_MODE) && !FlagGet(FLAG_FULL_RANDOMIZED_MODE) && IsPokemonValid(GetRandomFirstStage(basespecies)))
		return GetRandomizedWildPokemon(GetRandomFirstStage(basespecies), level, heldItem);
	else if(!InCharacterMode() && FlagGet(FLAG_FULL_RANDOMIZED_MODE))
		return GetRandomizedWildPokemon(GetRandomFirstStage(SPECIES_NONE), level, heldItem);
	else if(FlagGet(FLAG_NO_EVOLUTION_MODE))
		return GetFirstStage(basespecies);
	
	if (heldItem == ITEM_EVERSTONE 
	||  heldItem == ITEM_EVIOLITE
	|| !GetSetPokedexFlag(SpeciesToNationalPokedexNum(basespecies), FLAG_GET_SEEN)
	||  level == getMinWildPokemonLevel()
	||  basespecies == 133)
		return basespecies;
	
	switch(gEvolutionTable[split][0].method)
	{
		//Friendship Evolution Only
		case EVO_FRIENDSHIP:
		case EVO_FRIENDSHIP_DAY:
		case EVO_FRIENDSHIP_NIGHT:
		case EVO_ITEM_HOLD_DAY:
		if(level >= FriendshipLevel)
			return GetWildPokemon(gEvolutionTable[split][0].targetSpecies, level-1, heldItem);
		break;
		
		//Level based Evolutions
		case EVO_LEVEL:
		case EVO_LEVEL_NINJASK:
		case EVO_LEVEL_DAY:
		case EVO_LEVEL_MALE:
		case EVO_LEVEL_NIGHT:
		case EVO_LEVEL_FEMALE:
		case EVO_VIVILLON:
		case EVO_TOXTRICITY:
		//case EVO_HUSIAN:
		//case EVO_MELMETAL:
		case EVO_ALCREMIE:
		case EVO_EXIOLITE:
		case EVO_LEVEL_RAIN:
		case EVO_LEVEL_DUSK:
		case EVO_LEVEL_DARK_TYPE_MON_IN_PARTY:
		case EVO_LEVEL_SEVII:
		case EVO_LEVEL_NOT_SEVII:
			if(gEvolutionTable[split][0].param && gEvolutionTable[split][0].param <= level)
			{
				if(GetWildPokemon(gEvolutionTable[split][0].targetSpecies, level, heldItem))
					return GetWildPokemon(gEvolutionTable[split][0].targetSpecies, level-1, heldItem);
				else
					return gEvolutionTable[split][0].targetSpecies;
			}
		break;
		
		//Midgame Evolutions
		case EVO_BEAUTY:
		case EVO_ITEM_HOLD_NIGHT:
		case EVO_SPECIFIC_MON_IN_PARTY:
		
			if(BadgesMidgame <= numbadges)
				return GetWildPokemon(gEvolutionTable[split][0].targetSpecies, level-1, heldItem);
		break;
	
		//Lategame Evolutions
		case EVO_MOVE:
		case EVO_ITEM:
		case EVO_TRADE:
		case EVO_MAPSEC:
		case EVO_ITEM_MALE:
		case EVO_TRADE_ITEM:
		case EVO_ITEM_FEMALE:
			if(BadgesLategame <= numbadges)
				return GetWildPokemon(gEvolutionTable[split][0].targetSpecies, level-1, heldItem);
		break;
		
	}
	return split;
}

u16 GetRandomizedWildPokemon(u16 basespecies, u8 level, u16 heldItem){
	//Variables
	u16 split = SplitEvolutions(basespecies,level);
	u8 numbadges = GetNumBadges();
	u8 rand = 0;
	u8 FriendshipLevel = 24;
	u8 BadgesMidgame = 5;
	u8 BadgesLategame = 7;
	
	if(FlagGet(FLAG_NO_EVOLUTION_MODE))
	return GetFirstStage(basespecies);
	
	if (heldItem == ITEM_EVERSTONE 
	||  heldItem == ITEM_EVIOLITE
	|| !GetSetPokedexFlag(SpeciesToNationalPokedexNum(basespecies), FLAG_GET_SEEN)
	||  level == getMinWildPokemonLevel()
	||  basespecies == 133)
		return basespecies;
	
	switch(gEvolutionTable[split][0].method)
	{
		//Friendship Evolution Only
		case EVO_FRIENDSHIP:
		case EVO_ITEM_HOLD_DAY:
		case EVO_FRIENDSHIP_DAY:
		case EVO_FRIENDSHIP_NIGHT:
		if(level >= FriendshipLevel)
			return GetRandomizedWildPokemon(gEvolutionTable[split][0].targetSpecies, level-1, heldItem);
		break;
		
		//Level based Evolutions
		case EVO_LEVEL:
		case EVO_LEVEL_NINJASK:
		case EVO_LEVEL_DAY:
		case EVO_LEVEL_MALE:
		case EVO_LEVEL_NIGHT:
		case EVO_LEVEL_FEMALE:
		case EVO_VIVILLON:
		case EVO_TOXTRICITY:
		//case EVO_HUSIAN:
		//case EVO_MELMETAL:
		case EVO_ALCREMIE:
		case EVO_EXIOLITE:
		case EVO_LEVEL_RAIN:
		case EVO_LEVEL_DUSK:
		case EVO_LEVEL_DARK_TYPE_MON_IN_PARTY:
		case EVO_LEVEL_SEVII:
		case EVO_LEVEL_NOT_SEVII:
			if(gEvolutionTable[split][0].param && gEvolutionTable[split][0].param <= level)
			{
				if(GetRandomizedWildPokemon(gEvolutionTable[split][0].targetSpecies, level, heldItem))
					return GetRandomizedWildPokemon(gEvolutionTable[split][0].targetSpecies, level-1, heldItem);
				else
					return gEvolutionTable[split][0].targetSpecies;
			}
		break;
		
		//Midgame Evolutions
		case EVO_BEAUTY:
		case EVO_ITEM_HOLD_NIGHT:
		case EVO_SPECIFIC_MON_IN_PARTY:
			if(BadgesMidgame <= numbadges)
				return GetRandomizedWildPokemon(gEvolutionTable[split][0].targetSpecies, level-1, heldItem);
		break;
	
		//Lategame Evolutions
		case EVO_MOVE:
		case EVO_ITEM:
		case EVO_TRADE:
		case EVO_MAPSEC:
		case EVO_ITEM_MALE:
		case EVO_TRADE_ITEM:
		case EVO_ITEM_FEMALE:
			if(BadgesLategame <= numbadges)
				return GetRandomizedWildPokemon(gEvolutionTable[split][0].targetSpecies, level-1, heldItem);
		break;
		
	}
	return split;
}

u16 GetTrainerPokemon(u16 basespecies, u8 level){
	//Variables
	u16 split = SplitEvolutions(basespecies,level);
	u8 numbadges = GetNumBadges();
	u8 rand = 0;
	u8 FriendshipLevel = 12;
	u8 BadgesMidgame = 4;
	u8 BadgesLategame = 6;
     
	if(basespecies == SPECIES_AUDINO)
		return SPECIES_AUDINO;
	else if(FlagGet(FLAG_RANDOMIZED_MODE) && !FlagGet(FLAG_FULL_RANDOMIZED_MODE))
		return GetRandomizedTrainerPokemon(GetRandomFirstStage(basespecies), level);
	else if(FlagGet(FLAG_FULL_RANDOMIZED_MODE))
		return GetRandomizedTrainerPokemon(GetRandomFirstStage(SPECIES_NONE), level);
	else if(FlagGet(FLAG_NO_EVOLUTION_MODE))
		return GetFirstStage(basespecies);
	
	switch(gEvolutionTable[split][0].method)
	{
		//Friendship Evolution Only
		case EVO_FRIENDSHIP:
		case EVO_ITEM_HOLD_DAY:
		case EVO_FRIENDSHIP_DAY:
		case EVO_FRIENDSHIP_NIGHT:
		if(level >= FriendshipLevel)
			return GetTrainerPokemon(gEvolutionTable[split][0].targetSpecies, level);
		break;
		
		//Level based Evolutions
		case EVO_LEVEL:
		case EVO_LEVEL_NINJASK:
		case EVO_LEVEL_DAY:
		case EVO_LEVEL_MALE:
		case EVO_LEVEL_NIGHT:
		case EVO_LEVEL_FEMALE:
		case EVO_VIVILLON:
		case EVO_TOXTRICITY:
		//case EVO_HUSIAN:
		case EVO_MELMETAL:
		case EVO_ALCREMIE:
		case EVO_EXIOLITE:
		case EVO_LEVEL_RAIN:
		case EVO_LEVEL_DUSK:
		case EVO_LEVEL_DARK_TYPE_MON_IN_PARTY:
		case EVO_LEVEL_SEVII:
		case EVO_LEVEL_NOT_SEVII:
			if(gEvolutionTable[split][0].param && gEvolutionTable[split][0].param <= level)
			{
				if(GetTrainerPokemon(gEvolutionTable[split][0].targetSpecies, level))
					return GetTrainerPokemon(gEvolutionTable[split][0].targetSpecies, level);
				else
					return gEvolutionTable[split][0].targetSpecies;
			}
		break;
		
		//Midgame Evolutions
		case EVO_TRADE_SPECIFIC_MON:
		case EVO_BEAUTY:
		case EVO_ITEM_HOLD_NIGHT:
		case EVO_SPECIFIC_MON_IN_PARTY:
			if(BadgesMidgame <= numbadges)
				return GetTrainerPokemon(gEvolutionTable[split][0].targetSpecies, level);
		break;
	
		//Lategame Evolutions
		case EVO_MOVE:
		case EVO_ITEM:
		case EVO_TRADE:
		case EVO_MAPSEC:
		case EVO_ITEM_MALE:
		case EVO_TRADE_ITEM:
		case EVO_ITEM_FEMALE:
			if(BadgesLategame <= numbadges)
				return GetTrainerPokemon(gEvolutionTable[split][0].targetSpecies, level);
		break;
		
	}
	return split;
}

u16 GetRandomizedTrainerPokemon(u16 basespecies, u8 level){
	//Variables
	u16 split = SplitEvolutions(basespecies,level);
	u8 numbadges = GetNumBadges();
	u8 rand = 0;
	u8 FriendshipLevel = 12;
	u8 BadgesMidgame = 4;
	u8 BadgesLategame = 6;
	
	if(FlagGet(FLAG_NO_EVOLUTION_MODE))
		return GetFirstStage(basespecies);
	
	switch(gEvolutionTable[split][0].method)
	{
		//Friendship Evolution Only
		case EVO_FRIENDSHIP:
		case EVO_ITEM_HOLD_DAY:
		case EVO_FRIENDSHIP_DAY:
		case EVO_FRIENDSHIP_NIGHT:
		if(level >= FriendshipLevel)
			return GetRandomizedTrainerPokemon(gEvolutionTable[split][0].targetSpecies, level);
		break;
		
		//Level based Evolutions
		case EVO_LEVEL:
		case EVO_LEVEL_NINJASK:
		case EVO_LEVEL_DAY:
		case EVO_LEVEL_MALE:
		case EVO_LEVEL_NIGHT:
		case EVO_LEVEL_FEMALE:
		case EVO_VIVILLON:
		case EVO_TOXTRICITY:
		//case EVO_HUSIAN:
		case EVO_MELMETAL:
		case EVO_ALCREMIE:
		case EVO_EXIOLITE:
		case EVO_LEVEL_RAIN:
		case EVO_LEVEL_DUSK:
		case EVO_LEVEL_DARK_TYPE_MON_IN_PARTY:
		case EVO_LEVEL_SEVII:
		case EVO_LEVEL_NOT_SEVII:
			if(gEvolutionTable[split][0].param && gEvolutionTable[split][0].param <= level)
			{
				if(GetRandomizedTrainerPokemon(gEvolutionTable[split][0].targetSpecies, level))
					return GetRandomizedTrainerPokemon(gEvolutionTable[split][0].targetSpecies, level);
				else
					return gEvolutionTable[split][0].targetSpecies;
			}
		break;
		
		//Midgame Evolutions
		case EVO_TRADE_SPECIFIC_MON:
		case EVO_BEAUTY:
		case EVO_ITEM_HOLD_NIGHT:
		case EVO_SPECIFIC_MON_IN_PARTY:
			if(BadgesMidgame <= numbadges)
				return GetRandomizedTrainerPokemon(gEvolutionTable[split][0].targetSpecies, level);
		break;
	
		//Lategame Evolutions
		case EVO_MOVE:
		case EVO_ITEM:
		case EVO_TRADE:
		case EVO_MAPSEC:
		case EVO_ITEM_MALE:
		case EVO_TRADE_ITEM:
		case EVO_ITEM_FEMALE:
			if(BadgesLategame <= numbadges)
				return GetRandomizedTrainerPokemon(gEvolutionTable[split][0].targetSpecies, level);
		break;
		
	}
	return split;
}

u16 noEvolutionModeCheck(u16 basespecies){
	if(FlagGet(FLAG_NO_EVOLUTION_MODE))
		return GetFirstStage(basespecies);
	else
		return basespecies;
}

u16 SplitEvolutions(u16 basespecies, u8 level){
	u8 numbadges = GetNumBadges();
	u8 rand = Random() % 12;
	bool8 disablealternateforms = FALSE;
	
	switch(basespecies){
		case SPECIES_WURMPLE:
			if(level >= 7){
				u16 PossibleEvo[] = {
					SPECIES_CASCOON,
					SPECIES_SILCOON,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_EEVEE:
			
		break;
		case SPECIES_POLIWHIRL:
			if(level >= 38){
				u16 PossibleEvo[] = {
					SPECIES_POLIWRATH,
					SPECIES_POLITOED,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_TYROGUE:
			if(level >= 20){
				u16 PossibleEvo[] = {
					SPECIES_HITMONLEE,
					SPECIES_HITMONCHAN,
					SPECIES_HITMONTOP,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_SLOWPOKE:
			if(level >= 37){
				u16 PossibleEvo[] = {
					SPECIES_SLOWBRO,
					SPECIES_SLOWKING,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_GLOOM:
			if(level >= 36){
				u16 PossibleEvo[] = {
					SPECIES_VILEPLUME,
					SPECIES_BELLOSSOM,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_KIRLIA:
			if(level >= 30){
				u16 PossibleEvo[] = {
					SPECIES_GARDEVOIR,
					SPECIES_GALLADE,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_NINCADA:
			if(level >= 20){
				u16 PossibleEvo[] = {
					SPECIES_SHEDINJA,
					SPECIES_NINJASK,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_APPLIN:
			if(level >= 34){
				u16 PossibleEvo[] = {
					SPECIES_FLAPPLE,
					SPECIES_APPLETUN,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_SNORUNT:
			if(level >= 42){
				u16 PossibleEvo[] = {
					SPECIES_GLALIE,
					SPECIES_FROSLASS,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_CLAMPERL:
			if(level >= 26){
				u16 PossibleEvo[] = {
					SPECIES_HUNTAIL,
					SPECIES_GOREBYSS,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_BURMY:
		case SPECIES_BURMY_SANDY_CLOAK:
		case SPECIES_BURMY_TRASH_CLOAK:
			if(level >= 20){
				u16 PossibleEvo[] = {
					SPECIES_WORMADAM,
					SPECIES_MOTHIM,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
	}
	
	//Alternate Forms
	switch(basespecies){
		case SPECIES_VIVILLON:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_VIVILLON,
					SPECIES_VIVILLON_POLAR,
					SPECIES_VIVILLON_TUNDRA,
					SPECIES_VIVILLON_CONTINENTAL,
					SPECIES_VIVILLON_GARDEN,
					SPECIES_VIVILLON_ELEGANT,
					SPECIES_VIVILLON_MEADOW,
					SPECIES_VIVILLON_MODERN,
					SPECIES_VIVILLON_MARINE,
					SPECIES_VIVILLON_ARCHIPELAGO,
					SPECIES_VIVILLON_HIGH_PLAINS,
					SPECIES_VIVILLON_SANDSTORM,
					SPECIES_VIVILLON_RIVER,
					SPECIES_VIVILLON_MONSOON,
					SPECIES_VIVILLON_SAVANNA,
					SPECIES_VIVILLON_SUN,
					SPECIES_VIVILLON_OCEAN,
					SPECIES_VIVILLON_JUNGLE,
					SPECIES_VIVILLON_FANCY,
					SPECIES_VIVILLON_POKE_BALL,
				};
					
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_TOXTRICITY:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_TOXTRICITY,
					SPECIES_TOXTRICITY_LOW_KEY,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_ALCREMIE:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_ALCREMIE,
					SPECIES_ALCREMIE_RUBY_CREAM,
					SPECIES_ALCREMIE_MATCHA_CREAM,
					SPECIES_ALCREMIE_MINT_CREAM,
					SPECIES_ALCREMIE_LEMON_CREAM,
					SPECIES_ALCREMIE_SALTED_CREAM,
					SPECIES_ALCREMIE_RUBY_SWIRL,
					SPECIES_ALCREMIE_CARAMEL_SWIRL,
					SPECIES_ALCREMIE_RAINBOW_SWIRL,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_LYCANROC:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_LYCANROC,
					SPECIES_LYCANROC_MIDNIGHT,
					SPECIES_LYCANROC_DUSK,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_BURMY:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_BURMY,
					SPECIES_BURMY_SANDY_CLOAK,
					SPECIES_BURMY_TRASH_CLOAK,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_WORMADAM:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_WORMADAM,
					SPECIES_WORMADAM_SANDY_CLOAK,
					SPECIES_WORMADAM_TRASH_CLOAK,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_DEERLING:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_DEERLING,
					SPECIES_DEERLING_SUMMER,
					SPECIES_DEERLING_AUTUMN,
					SPECIES_DEERLING_WINTER,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_SAWSBUCK:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_DEERLING,
					SPECIES_DEERLING_SUMMER,
					SPECIES_DEERLING_AUTUMN,
					SPECIES_SAWSBUCK_WINTER,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_FLABEBE:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_FLABEBE,
					SPECIES_FLABEBE_YELLOW_FLOWER,
					SPECIES_FLABEBE_ORANGE_FLOWER,
					SPECIES_FLABEBE_BLUE_FLOWER,
					SPECIES_FLABEBE_WHITE_FLOWER,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_FLOETTE:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_FLOETTE,
					SPECIES_FLOETTE_YELLOW_FLOWER,
					SPECIES_FLOETTE_ORANGE_FLOWER,
					SPECIES_FLOETTE_BLUE_FLOWER,
					SPECIES_FLOETTE_WHITE_FLOWER,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_FLORGES:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_FLORGES,
					SPECIES_FLORGES_YELLOW_FLOWER,
					SPECIES_FLORGES_ORANGE_FLOWER,
					SPECIES_FLORGES_BLUE_FLOWER,
					SPECIES_FLORGES_WHITE_FLOWER,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_FURFROU:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_FURFROU,
					SPECIES_FURFROU_HEART_TRIM,
					SPECIES_FURFROU_STAR_TRIM,
					SPECIES_FURFROU_DIAMOND_TRIM,
					SPECIES_FURFROU_DEBUTANTE_TRIM,
					SPECIES_FURFROU_MATRON_TRIM,
					SPECIES_FURFROU_DANDY_TRIM,
					SPECIES_FURFROU_LA_REINE_TRIM,
					SPECIES_FURFROU_KABUKI_TRIM,
					SPECIES_FURFROU_PHARAOH_TRIM,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_PUMPKABOO:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_PUMPKABOO,
					SPECIES_PUMPKABOO_SMALL,
					SPECIES_PUMPKABOO_LARGE,
					SPECIES_PUMPKABOO_SUPER,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_GOURGEIST:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_GOURGEIST,
					SPECIES_GOURGEIST_SMALL,
					SPECIES_GOURGEIST_LARGE,
					SPECIES_GOURGEIST_SUPER,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_SINISTEA:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_SINISTEA,
					SPECIES_SINISTEA_ANTIQUE,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_MINIOR:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_MINIOR,
					SPECIES_MINIOR_CORE_RED,
					SPECIES_MINIOR_CORE_ORANGE,
					SPECIES_MINIOR_CORE_YELLOW,
					SPECIES_MINIOR_CORE_GREEN,
					SPECIES_MINIOR_CORE_BLUE,
					SPECIES_MINIOR_CORE_INDIGO,
					SPECIES_MINIOR_CORE_VIOLET,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_ORICORIO:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_ORICORIO,
					SPECIES_ORICORIO_POM_POM,
					SPECIES_ORICORIO_PA_U,
					SPECIES_ORICORIO_SENSU,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_INDEEDEE:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_INDEEDEE,
					SPECIES_INDEEDEE_FEMALE,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
		case SPECIES_MEOWSTIC:
			if(!disablealternateforms){
				u16 PossibleEvo[] = {
					SPECIES_MEOWSTIC,
					SPECIES_MEOWSTIC_FEMALE,
				};
				
				return PossibleEvo[rand % (sizeof(PossibleEvo)/sizeof(PossibleEvo[0]))];
			}
		break;
	}
	
	//Regional forms
	switch(basespecies){
		case SPECIES_RAICHU:
			if(gMapHeader.region == REGION_SEVII)
				return SPECIES_RAICHU_ALOLAN;
			else
				return basespecies;
		break;
		case SPECIES_EXEGGUTOR:
			if(gMapHeader.region == REGION_SEVII)
				return SPECIES_EXEGGUTOR_ALOLAN;
			else
				return basespecies;
		break;
		case SPECIES_MAROWAK:
			if(gMapHeader.region == REGION_SEVII)
				return SPECIES_MAROWAK_ALOLAN;
			else
				return SPECIES_MAROWAK;
		break;
		case SPECIES_MR_MIME:
			if(gMapHeader.region == REGION_SEVII)
				return SPECIES_MR_MIME_GALARIAN;
			else
				return basespecies;
		break;
		case SPECIES_WEEZING:
			if(gMapHeader.region == REGION_SEVII)
				return SPECIES_WEEZING_GALARIAN;
			else
				return basespecies;
		break;
	}
	
	return basespecies;
}

u16 CheckforLegendary(u16 species){
	u16 id = gSaveBlock2Ptr->playerTrainerId[1];
	u16 LegendariesNum1[] = {144,150,243,249,377,480,638,716,785};
	u16 LegendariesNum2[] = {147,152,246,252,387,495,650,722,810};
	u8 i = 0;
	
	for(i = 0; i < 9;i++){
	if(species == 772 || species == 773)
		return 132;
	if(species < LegendariesNum1[i])
		return species;
	else if(species < LegendariesNum2[i])
		return CheckforLegendary(1+((species*id)% 884));
	}
	return species;
}

u16 GetHeldItem(u16 baseitem)
{
	u16 holdEffect = ItemId_GetHoldEffect(baseitem);
	u16 NumBadges = GetNumBadges();
	if(IsHardMode() == 1)
		NumBadges = NumBadges + 1;
	
	if(holdEffect != HOLD_EFFECT_MEGA_STONE){
	if (NumBadges >= 7)
		return baseitem;
	else 
		return ITEM_SITRUS_BERRY;
	}
	
	if(baseitem == ITEM_ORAN_BERRY)//HP restorative items
	{
		if(NumBadges >= 6)
			return ITEM_SITRUS_BERRY;
		if(NumBadges >= 3)
			return ITEM_BERRY_JUICE;
		
		return baseitem;
	}
	
	if(baseitem == ITEM_LUM_BERRY)//Defense Styled Pokemon
	{
		if(NumBadges >= 8)
			return ITEM_FIGY_BERRY;
		if(NumBadges >= 6)
			return ITEM_LEFTOVERS;
	    if(NumBadges >= 4)
			return ITEM_LUM_BERRY;
	}
	
	if(baseitem == ITEM_MAGOST_BERRY)//Attack Oriented Pokemon
	{
		if(NumBadges >= 7)
			return ITEM_LIFE_ORB;
		if(NumBadges >= 5)
			return ITEM_FOCUS_SASH;
	    if(NumBadges >= 3)
			return ITEM_NORMAL_GEM;
	}
	
	if(baseitem == ITEM_RABUTA_BERRY)//Speed Oriented Pokemon
	{
		if(NumBadges >= 7)
			return ITEM_QUICK_CLAW;
		if(NumBadges >= 5)
			return ITEM_CUSTAP_BERRY;
	    if(NumBadges >= 3)
			return ITEM_SALAC_BERRY;
	}
	
	if(baseitem == ITEM_NOMEL_BERRY)//Normal Type Pokemon
		{
		if(NumBadges >= 7)
			return ITEM_NORMAL_GEM;
		if(NumBadges >= 5)
			return ITEM_CHOPLE_BERRY;
	    if(NumBadges >= 3)
			return ITEM_LUM_BERRY;
	}
	
	return baseitem;
}

u8 GetEvsfromPokemon(u8 evs)
{
	u8  NumBadges = GetNumBadges();
	u8  NumFlags = 10;
	u8  ScaledEvs = (evs/NumFlags)*NumBadges; 
	if(IsHardMode() == 1 && NumBadges != NumFlags)
		ScaledEvs = (evs/NumFlags)*NumBadges+1; 
	
	return ScaledEvs;
}

bool8 IsMoveUsable(u8 movepower)
{	
	if(movepower <= MovePowerLimit[GetNumBadges()])
		return TRUE;
	else if(FlagGet(FLAG_EASY_MODE))
		return FALSE;
	else
		return TRUE;
}

u16 GetMapRandomPokemon(u16 TrainerClass, u16 species)
{
	u8 i = 0;
	u8 j = 0;
	u8 k = 0;
	u8 rand = Random() % 12;
	u16 Landspecies[] = 
	{SPECIES_NONE,SPECIES_NONE,SPECIES_NONE,SPECIES_NONE,SPECIES_NONE,SPECIES_NONE,
	 SPECIES_NONE,SPECIES_NONE,SPECIES_NONE,SPECIES_NONE,SPECIES_NONE,SPECIES_NONE};
	u16 Waterspecies[] = 
	{SPECIES_NONE,SPECIES_NONE,SPECIES_NONE,SPECIES_NONE,SPECIES_NONE,SPECIES_NONE,
	 SPECIES_NONE,SPECIES_NONE,SPECIES_NONE,SPECIES_NONE,SPECIES_NONE,SPECIES_NONE};
	
	u16 randspecie = SPECIES_NONE;
	
	if(!FlagGet(FLAG_RANDOMIZED_MODE)){
	for(i = 0; i < 12 ;i++){
		Landspecies[i]  = GetCurrentMapWildPokemon(0, i+rand);
		Waterspecies[j] = GetCurrentMapWildPokemon(1, j+rand);
	}}else{
		Landspecies[i]  = GetBaseSpecie(GetCurrentMapWildPokemon(0, i+rand));
		Waterspecies[j] = GetBaseSpecie(GetCurrentMapWildPokemon(1, j+rand));
	}
	
	if(rand <= 6)
		return species;
		
	switch(TrainerClass)
	{
		case TRAINER_CLASS_EXPERT:
		case TRAINER_CLASS_POKEMANIAC:
		for(k = 0; k < 12 ;k++){
		if(gBaseStats[Landspecies[k]].growthRate == GROWTH_SLOW || gBaseStats[Landspecies[k]].growthRate == GROWTH_MEDIUM_SLOW)
		{
		if(IsPokemonValid(Landspecies[k]))
				return Landspecies[k];
			else
				return species;
		}}
			return species;
		break;
		case TRAINER_CLASS_LADY:
		for(k = 0; k < 12 ;k++){
		if(gBaseStats[Landspecies[k]].type1 == TYPE_FAIRY || gBaseStats[Landspecies[k]].type2 == TYPE_FAIRY||
		gBaseStats[Landspecies[k]].type1 == TYPE_GRASS || gBaseStats[Landspecies[k]].type2 == TYPE_GRASS ||
		gBaseStats[Landspecies[k]].bodyColor == BODY_COLOR_PINK || gBaseStats[Landspecies[k]].eggGroup1 == EGG_GROUP_UNDISCOVERED ||
		(gBaseStats[Landspecies[k]].type2 == TYPE_NORMAL && gBaseStats[Landspecies[k]].type2 == TYPE_NORMAL))
		{
			if(IsPokemonValid(Landspecies[k]))
				return Landspecies[k];
			else
				return species;
		}}
			return species;
		break;
		case TRAINER_CLASS_HIKER:
		case TRAINER_CLASS_RUIN_MANIAC:
		for(k = 0; k < 12 ;k++){
		if(gBaseStats[Landspecies[k]].type1 == TYPE_GROUND || gBaseStats[Landspecies[k]].type2 == TYPE_GROUND ||
		   gBaseStats[Landspecies[k]].type1 == TYPE_ROCK || gBaseStats[Landspecies[k]].type2 == TYPE_ROCK)
		{
			if(IsPokemonValid(Landspecies[k]))
				return Landspecies[k];
			else
				return species;
		}}
			return species;
		break;
		case TRAINER_CLASS_HEX_MANIAC:
		for(k = 0; k < 12 ;k++){
		if(gBaseStats[Landspecies[k]].type1 == TYPE_GHOST || gBaseStats[Landspecies[k]].type2 == TYPE_GHOST ||
		   gBaseStats[Landspecies[k]].type1 == TYPE_PSYCHIC || gBaseStats[Landspecies[k]].type2 == TYPE_PSYCHIC ||
		   gBaseStats[Landspecies[k]].type1 == TYPE_DARK || gBaseStats[Landspecies[k]].type2 == TYPE_DARK)
		{
			if(IsPokemonValid(Landspecies[k]))
				return Landspecies[k];
			else
				return species;
		}}
			return species;
		break;
		case TRAINER_CLASS_AROMA_LADY:
		for(k = 0; k < 12 ;k++){
		if(gBaseStats[Landspecies[k]].type1 == TYPE_GRASS || gBaseStats[Landspecies[k]].type2 == TYPE_GRASS ||
		   gBaseStats[Landspecies[k]].eggGroup1 == EGG_GROUP_GRASS || gBaseStats[Landspecies[k]].eggGroup2 == EGG_GROUP_GRASS||
		   gBaseStats[Landspecies[k]].eggGroup1 == EGG_GROUP_FAIRY || gBaseStats[Landspecies[k]].eggGroup2 == EGG_GROUP_FAIRY)
		{
			if(IsPokemonValid(Landspecies[k]))
				return Landspecies[k];
			else
				return species;
		}}
			return species;
		break;
		case TRAINER_CLASS_GUITARIST:
		for(k = 0; k < 12 ;k++){
		if(gBaseStats[Landspecies[k]].type1 == TYPE_ELECTRIC || gBaseStats[Landspecies[k]].type2 == TYPE_ELECTRIC ||
		   gBaseStats[Landspecies[k]].abilities[0] == ABILITY_SOUNDPROOF || gBaseStats[Landspecies[k]].abilities[1] == ABILITY_SOUNDPROOF)
		{
			if(IsPokemonValid(Landspecies[k]))
				return Landspecies[k];
			else
				return species;
		}}
			return species;
		break;
		case TRAINER_CLASS_BUG_MANIAC:
		case TRAINER_CLASS_BUG_CATCHER:
		for(k = 0; k < 12 ;k++){
		if(gBaseStats[Landspecies[k]].type1 == TYPE_BUG || gBaseStats[Landspecies[k]].type2 == TYPE_BUG)
		{
			if(IsPokemonValid(Landspecies[k]))
				return Landspecies[k];
			else
				return species;
		}}
			return species;
		break;
		break;
		case TRAINER_CLASS_DRAGON_TAMER:
		for(k = 0; k < 12 ;k++){
		if(gBaseStats[Landspecies[k]].type1 == TYPE_DRAGON 
		|| gBaseStats[Landspecies[k]].type2 == TYPE_DRAGON
		|| gBaseStats[Landspecies[k]].eggGroup1 == EGG_GROUP_DRAGON 
		|| gBaseStats[Landspecies[k]].eggGroup2 == EGG_GROUP_DRAGON)
		{
			if(IsPokemonValid(Landspecies[k]))
				return Landspecies[k];
			else
				return species;
		}}
			return species;
		break;
		case TRAINER_CLASS_BATTLE_GIRL:
		case TRAINER_CLASS_BLACK_BELT:
		case TRAINER_CLASS_CRUSH_KIN:
		for(k = 0; k < 12 ;k++){
		if(gBaseStats[Landspecies[k]].type1 == TYPE_FIGHTING || gBaseStats[Landspecies[k]].type2 == TYPE_FIGHTING ||
		(gBaseStats[Landspecies[k]].eggGroup1 == EGG_GROUP_HUMAN_LIKE && gBaseStats[Landspecies[k]].evYield_Attack != 0))
		{
			if(IsPokemonValid(Landspecies[k]))
				return Landspecies[k];
			else
				return species;
		}}
			return species;
		break;
		case TRAINER_CLASS_PSYCHIC:
		for(k = 0; k < 12 ;k++){
		if(gBaseStats[Landspecies[k]].type1 == TYPE_PSYCHIC || gBaseStats[Landspecies[k]].type2 == TYPE_PSYCHIC)
		{
			if(IsPokemonValid(Landspecies[k]))
				return Landspecies[k];
			else
				return species;
		}}
			return species;
		break;
		case TRAINER_CLASS_BIRD_KEEPER:
		case TRAINER_CLASS_TRIATHLETE:
		for(k = 0; k < 12 ;k++){
		if(gBaseStats[Landspecies[k]].type1 == TYPE_FLYING || gBaseStats[Landspecies[k]].type2 == TYPE_FLYING
		||gBaseStats[Landspecies[k]].eggGroup1 == EGG_GROUP_FLYING)
		{
			if(IsPokemonValid(Landspecies[k]))
				return Landspecies[k];
			else
				return species;
		}}
			return species;
		break;
		case TRAINER_CLASS_SCHOOL_KID:
		case TRAINER_CLASS_LASS:
		case TRAINER_CLASS_YOUNGSTER:
		for(k = 0; k < 12 ;k++){
		if(gBaseStats[Landspecies[k]].growthRate == GROWTH_FAST || gBaseStats[Landspecies[k]].growthRate == GROWTH_MEDIUM_FAST)
		{
			if(IsPokemonValid(Landspecies[k]))
				return Landspecies[k];
			else
				return species;
		}}
			return species;
		break;
		case TRAINER_CLASS_FISHERMAN:
		case TRAINER_CLASS_SWIMMER_F:
		case TRAINER_CLASS_SWIMMER_M:
		if(IsPokemonValid(Waterspecies[0]))
			return Waterspecies[0];
		else
			return species;
		break;
		default:
		return species;
	}
	return species;
}

u16 GetCurrentMapWildPokemon(u8 isWaterMon, u8 index)
{
    u16 headerId;
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *waterMonsInfo;
    headerId = GetCurrentMapWildMonHeaderId();
	
    if (headerId == 0xFFFF)
        return SPECIES_NONE;
    landMonsInfo = gWildMonHeaders[headerId].landMonsInfo;
    waterMonsInfo = gWildMonHeaders[headerId].waterMonsInfo;
    //Land Pokemon
	if(isWaterMon == 0){
	if (landMonsInfo == NULL)
        return SPECIES_NONE;
	else
		return landMonsInfo->wildPokemon[index%11].species;
	}else if (waterMonsInfo == NULL)
        return SPECIES_NONE;
	else
		return waterMonsInfo->wildPokemon[index%4].species;
	
	return SPECIES_NONE;
}

u16 GetScaledItem(u16 itemId)
{
	u16 newItemId = ITEM_POKE_BALL;
	u16 newFossilId = ITEM_DOME_FOSSIL;
	
	u16 sFossilItemList[] = {
		ITEM_DOME_FOSSIL,			//Kabuto
		ITEM_HELIX_FOSSIL,			//Omanyte
		ITEM_OLD_AMBER,				//Aerodactyl
		ITEM_ROOT_FOSSIL,			//Lileep
		ITEM_CLAW_FOSSIL,			//Anorith
		ITEM_SKULL_FOSSIL,			//Cranidos
		ITEM_ARMOR_FOSSIL,			//Shieldon
		ITEM_COVER_FOSSIL,			//Tirtuga
		ITEM_PLUME_FOSSIL,			//Archen
		ITEM_JAW_FOSSIL,			//Tyrunt
		ITEM_SAIL_FOSSIL,			//Amaura
	};
	
	u16 sScaledItems_ZeroBadges[] = {	//Zero or One Badges
		ITEM_POKE_BALL,			//01
		ITEM_POKE_BALL,			//02
		ITEM_POKE_BALL,			//03
		ITEM_POTION,			//04
		ITEM_POTION,			//05
		ITEM_POTION,			//06
		ITEM_ETHER,				//07
		ITEM_ETHER,				//08
		ITEM_ETHER,				//09
		ITEM_ANTIDOTE,			//10
		ITEM_BURN_HEAL,			//11
		ITEM_ICE_HEAL,			//12
		ITEM_AWAKENING,			//13
		ITEM_PARALYZE_HEAL,		//14
		ITEM_TINY_MUSHROOM,		//15
		ITEM_REPEL,				//16
		ITEM_REPEL,				//17
		ITEM_REPEL,				//18
		ITEM_LURE,				//19
		ITEM_PP_UP,				//20
		ITEM_ESCAPE_ROPE,		//21
		ITEM_RED_SHARD,			//22
		ITEM_BLUE_SHARD,		//23
		ITEM_GREEN_SHARD,		//24
		ITEM_YELLOW_SHARD		//25
	};
	
	u16 sScaledItems_TwoBadges[] = {	//Two or Three Badges
		ITEM_POKE_BALL,			//01
		ITEM_GREAT_BALL,		//02
		ITEM_GREAT_BALL,		//03
		ITEM_POTION,			//04
		ITEM_SUPER_POTION,		//05
		ITEM_SUPER_POTION,		//06
		ITEM_ETHER,				//07
		ITEM_MAX_ETHER,			//08
		ITEM_MAX_ETHER,			//09
		ITEM_ANTIDOTE,			//10
		ITEM_BURN_HEAL,			//11
		ITEM_ICE_HEAL,			//12
		ITEM_AWAKENING,			//13
		ITEM_PARALYZE_HEAL,		//14
		ITEM_TINY_MUSHROOM,		//15
		ITEM_BIG_MUSHROOM,		//16
		ITEM_REVIVE,		    //17
		ITEM_REPEL,				//18
		ITEM_SUPER_REPEL,		//19
		ITEM_SUPER_REPEL,		//20
		ITEM_LURE,				//21
		ITEM_PP_UP,				//22
		ITEM_ESCAPE_ROPE,		//23
		ITEM_RED_SHARD,			//24
		ITEM_BLUE_SHARD,		//25
		ITEM_GREEN_SHARD,		//26
		ITEM_YELLOW_SHARD		//27
	};
	
	u16 sScaledItems_FourBadges[] = {	//Four or Five Badges
		ITEM_GREAT_BALL,		//01
		ITEM_GREAT_BALL,		//02
		ITEM_GREAT_BALL,		//03
		ITEM_SUPER_POTION,		//04
		ITEM_SUPER_POTION,		//05
		ITEM_SUPER_POTION,		//06
		ITEM_MAX_ETHER,			//07
		ITEM_MAX_ETHER,			//08
		ITEM_ELIXIR,			//09
		ITEM_FULL_HEAL,			//10
		ITEM_REVIVE,		    //11
		ITEM_BIG_MUSHROOM,		//12
		ITEM_ULTRA_BALL,		//13
		ITEM_SUPER_REPEL,		//14
		ITEM_SUPER_REPEL,		//15
		ITEM_MAX_REPEL,			//16
		ITEM_SUPER_LURE,		//17
		ITEM_PP_UP,				//18
		ITEM_ESCAPE_ROPE,		//19
		ITEM_RED_SHARD,			//20
		ITEM_BLUE_SHARD,		//21
		ITEM_GREEN_SHARD,		//22
		ITEM_YELLOW_SHARD		//23
	};
	
	u16 sScaledItems_SixBadges[] = {	//Six or Seven Badges
		ITEM_GREAT_BALL,		//01
		ITEM_ULTRA_BALL,		//02
		ITEM_ULTRA_BALL,		//03
		ITEM_SUPER_POTION,		//04
		ITEM_HYPER_POTION,		//05
		ITEM_HYPER_POTION,		//06
		ITEM_MAX_ETHER,			//07
		ITEM_ELIXIR,			//08
		ITEM_MAX_ELIXIR,		//09
		ITEM_FULL_HEAL,			//10
		ITEM_REVIVE,		    //11
		ITEM_MAX_REVIVE,		//11
		ITEM_BIG_MUSHROOM,		//12
		ITEM_ULTRA_BALL,		//13
		ITEM_SUPER_REPEL,		//14
		ITEM_MAX_REPEL,			//15
		ITEM_MAX_REPEL,			//16
		ITEM_SUPER_LURE,		//17
		ITEM_PP_UP,				//18
		ITEM_PP_MAX,			//19
		ITEM_ESCAPE_ROPE,		//20
		ITEM_RED_SHARD,			//21
		ITEM_BLUE_SHARD,		//22
		ITEM_GREEN_SHARD,		//23
		ITEM_YELLOW_SHARD,		//24
		ITEM_RARE_CANDY			//25
	};
	
	u16 sScaledItems_EightBadges[] = {	//Eight Badges
		ITEM_ULTRA_BALL,		//01
		ITEM_ULTRA_BALL,		//02
		ITEM_ULTRA_BALL,		//03
		ITEM_HYPER_POTION,		//04
		ITEM_HYPER_POTION,		//05
		ITEM_MAX_POTION,		//06
		ITEM_ELIXIR,			//07
		ITEM_ELIXIR,			//08
		ITEM_MAX_ELIXIR,		//09
		ITEM_FULL_HEAL,			//10
		ITEM_REVIVE,		    //11
		ITEM_MAX_REVIVE,		//11
		ITEM_STAR_PIECE,		//12
		ITEM_ULTRA_BALL,		//13
		ITEM_MAX_REPEL,			//14
		ITEM_MAX_REPEL,			//15
		ITEM_MAX_REPEL,			//16
		ITEM_MAX_LURE,			//17
		ITEM_PP_UP,				//18
		ITEM_PP_MAX,			//19
		ITEM_ESCAPE_ROPE,		//20
		ITEM_RED_SHARD,			//21
		ITEM_BLUE_SHARD,		//22
		ITEM_GREEN_SHARD,		//23
		ITEM_YELLOW_SHARD,		//24
		ITEM_RARE_CANDY			//25
	};
	
	u16 sScaledItems_PostGame[] = {	//Eight Badges
		ITEM_ULTRA_BALL,		//01
		ITEM_QUICK_BALL,		//02
		ITEM_DUSK_BALL,			//03
		ITEM_MAX_POTION,		//04
		ITEM_MAX_POTION,		//05
		ITEM_MAX_POTION,		//06
		ITEM_FULL_RESTORE,		//07
		ITEM_ELIXIR,			//08
		ITEM_MAX_ELIXIR,		//09
		ITEM_MAX_ELIXIR,		//10
		ITEM_FULL_HEAL,			//11
		ITEM_FULL_HEAL,			//12
		ITEM_FULL_HEAL,			//13
		ITEM_REVIVE,			//14
		ITEM_REVIVE,			//15
		ITEM_MAX_REVIVE,		//16
		ITEM_MAX_REPEL,			//17
		ITEM_MAX_REPEL,			//18
		ITEM_MAX_REPEL,			//19
		ITEM_MAX_LURE,			//20
		ITEM_PP_MAX,			//21
		ITEM_ESCAPE_ROPE,		//22
		ITEM_HEART_SCALE,		//23
		ITEM_LUCKY_EGG,			//24
		ITEM_RARE_CANDY,		//25
		ITEM_NUGGET,			//26
		ITEM_RED_SHARD,			//27
		ITEM_BLUE_SHARD,		//28
		ITEM_GREEN_SHARD,		//29
		ITEM_YELLOW_SHARD		//30
	};
	
	switch(GetNumBadges()){
		case 0:
		case 1:
		newItemId = sScaledItems_ZeroBadges[Random() % (sizeof(sScaledItems_ZeroBadges)/sizeof(sScaledItems_ZeroBadges[0]))];
		break;
		case 2:
		case 3:
		newItemId = sScaledItems_TwoBadges[Random() % (sizeof(sScaledItems_TwoBadges)/sizeof(sScaledItems_TwoBadges[0]))];
		break;
		case 4:
		case 5:
		newItemId = sScaledItems_FourBadges[Random() % (sizeof(sScaledItems_FourBadges)/sizeof(sScaledItems_FourBadges[0]))];
		break;
		case 6:
		case 7:
		newItemId = sScaledItems_SixBadges[Random() % (sizeof(sScaledItems_SixBadges)/sizeof(sScaledItems_SixBadges[0]))];
		break;
		case 8:
		newItemId = sScaledItems_EightBadges[Random() % (sizeof(sScaledItems_EightBadges)/sizeof(sScaledItems_EightBadges[0]))];
		break;
		case 9:
		case 10:
		newItemId = sScaledItems_PostGame[Random() % (sizeof(sScaledItems_PostGame)/sizeof(sScaledItems_PostGame[0]))];
		break;
	}
	
	newFossilId = sFossilItemList[Random() % (sizeof(sFossilItemList)/sizeof(sFossilItemList[0]))];
	
	switch(itemId){
		case ITEM_POKE_BALL:
		case ITEM_GREAT_BALL:
		case ITEM_ULTRA_BALL:
		case ITEM_REPEL:
		case ITEM_SUPER_REPEL:
		case ITEM_MAX_REPEL:
		case ITEM_POTION:
		case ITEM_SUPER_POTION:
		case ITEM_HYPER_POTION:
		case ITEM_MAX_POTION:
		case ITEM_FULL_RESTORE:
		case ITEM_ELIXIR:
		case ITEM_MAX_ELIXIR:
		case ITEM_ETHER:
		case ITEM_ANTIDOTE:
		case ITEM_BURN_HEAL:
		case ITEM_ICE_HEAL:
		case ITEM_AWAKENING:
		case ITEM_PARALYZE_HEAL:
		case ITEM_FULL_HEAL:
		case ITEM_REVIVE:
		case ITEM_MAX_REVIVE:
		case ITEM_RARE_CANDY:
		case ITEM_PP_MAX:
		case ITEM_PP_UP:
		case ITEM_NUGGET:
			return newItemId;
		break;
		case ITEM_HELIX_FOSSIL:
			return newFossilId;
	}
	return itemId;
}

u8 getMapLevel(u8 id){
	
	return 0;
	/*/u8 Level1 = 0;
	u8 Level2 = 0;
	u8 Level3 = 0;
	u8 WildLevel = getScaledWildPokemonLevel();
	
	switch(id){
	//Route 101
	//1
	case ORDER_ROUTE101:
	if(FlagGet(FLAG_VISITED_LITTLEROOT_TOWN) && FlagGet(FLAG_VISITED_OLDALE_TOWN)){
		Level1 = getOrder(ORDER_LITTLEROOT_TOWN);
		Level2 = getOrder(ORDER_OLDALE_TOWN);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 102
	//2
	case ORDER_ROUTE102:
	if(FlagGet(FLAG_VISITED_PETALBURG_CITY) && FlagGet(FLAG_VISITED_OLDALE_TOWN)){
		Level1 = getOrder(ORDER_PETALBURG_CITY);
		Level2 = getOrder(ORDER_OLDALE_TOWN);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return 0;
	break;
	//Route 103
	//3
	case ORDER_ROUTE103:
	if(FlagGet(FLAG_VISITED_SLATEPORT_CITY) && FlagGet(FLAG_VISITED_OLDALE_TOWN)){
		Level1 = getOrder(ORDER_SLATEPORT_CITY);
		Level2 = getOrder(ORDER_OLDALE_TOWN);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 104 && Petalburg Woods
	//4
	case ORDER_ROUTE104:
	if(FlagGet(FLAG_VISITED_PETALBURG_CITY) && FlagGet(FLAG_VISITED_RUSTBORO_CITY)){
		Level1 = getOrder(ORDER_PETALBURG_CITY);
		Level2 = getOrder(ORDER_RUSTBORO_CITY);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 105 && Route 106
	//5
	case ORDER_ROUTE105:
	case ORDER_ROUTE106:
	if(FlagGet(FLAG_VISITED_PETALBURG_CITY) && FlagGet(FLAG_VISITED_DEWFORD_TOWN)){
		Level1 = getOrder(ORDER_PETALBURG_CITY);
		Level2 = getOrder(ORDER_DEWFORD_TOWN);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 107 && Route 108 && Route 109
	//6
	case ORDER_ROUTE107:
	case ORDER_ROUTE108:
	case ORDER_ROUTE109:
	if(FlagGet(FLAG_VISITED_SLATEPORT_CITY) && FlagGet(FLAG_VISITED_DEWFORD_TOWN)){
		Level1 = getOrder(ORDER_SLATEPORT_CITY);
		Level2 = getOrder(ORDER_DEWFORD_TOWN);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 110
	//7
	case ORDER_ROUTE110:
	if(FlagGet(FLAG_VISITED_SLATEPORT_CITY) && FlagGet(FLAG_VISITED_MAUVILLE_CITY)){
		Level1 = getOrder(ORDER_SLATEPORT_CITY);
		Level2 = getOrder(ORDER_MAUVILLE_CITY);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 111 & Route 112 & Jagged Pass & Mt.Chimney
	//8
	case ORDER_ROUTE111:
	if(FlagGet(FLAG_VISITED_SLATEPORT_CITY) && FlagGet(FLAG_VISITED_MAUVILLE_CITY)){
		Level1 = getOrder(ORDER_SLATEPORT_CITY);
		Level2 = getOrder(ORDER_MAUVILLE_CITY);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 113 & Fiery Path
	//9
	case ORDER_ROUTE113:
	if(FlagGet(FLAG_VISITED_LAVARIDGE_TOWN) && FlagGet(FLAG_VISITED_FALLARBOR_TOWN)){
		Level1 = getOrder(ORDER_LAVARIDGE_TOWN);
		Level2 = getOrder(ORDER_FALLARBOR_TOWN);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 114 & Route 115 & Meteor Falls
	//10
	case ORDER_ROUTE114:
	case ORDER_ROUTE115:
	if(FlagGet(FLAG_VISITED_PETALBURG_CITY) && FlagGet(FLAG_VISITED_FALLARBOR_TOWN)){
		Level1 = getOrder(ORDER_PETALBURG_CITY);
		Level2 = getOrder(ORDER_FALLARBOR_TOWN);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 116 & Route 117 & Rusturf Tunnel
	//11
	case ORDER_ROUTE116:
	case ORDER_ROUTE117:
	if(FlagGet(FLAG_VISITED_MAUVILLE_CITY) && FlagGet(FLAG_VISITED_VERDANTURF_TOWN)){
		Level1 = getOrder(ORDER_MAUVILLE_CITY);
		Level2 = getOrder(ORDER_VERDANTURF_TOWN);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 118 & Route 121
	//12
	case ORDER_ROUTE118:
	case ORDER_ROUTE121:
	if( FlagGet(FLAG_VISITED_MAUVILLE_CITY) &&
		FlagGet(FLAG_VISITED_LILYCOVE_CITY) &&
		FlagGet(FLAG_VISITED_FORTREE_CITY)){
		//After you visited them all
		Level1 = getOrder(ORDER_MAUVILLE_CITY);
		Level2 = getOrder(ORDER_LILYCOVE_CITY);
		Level3 = getOrder(ORDER_FORTREE_CITY);
		if(Level1 > Level2 && Level1 > Level3)
			return Level1;
		else if (Level2 > Level3)
			return level 2;
		else 
			return Level3;
	}else( !FlagGet(FLAG_VISITED_MAUVILLE_CITY) &&
			FlagGet(FLAG_VISITED_LILYCOVE_CITY) &&
			FlagGet(FLAG_VISITED_FORTREE_CITY)){
		//Fortree <-> Lilycove
		Level1 = getOrder(ORDER_LILYCOVE_CITY);
		Level2 = getOrder(ORDER_FORTREE_CITY);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else(  FlagGet(FLAG_VISITED_MAUVILLE_CITY) &&
			FlagGet(FLAG_VISITED_LILYCOVE_CITY) &&
		   !FlagGet(FLAG_VISITED_FORTREE_CITY)){
		//Mauville <-> Lilycove
		Level1 = getOrder(ORDER_LILYCOVE_CITY);
		Level2 = getOrder(ORDER_MAUVILLE_CITY);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 119
	//13
	case ORDER_ROUTE119:
	if(FlagGet(FLAG_VISITED_MAUVILLE_CITY) && FlagGet(FLAG_VISITED_FORTREE_CITY)){
		Level1 = getOrder(ORDER_MAUVILLE_CITY);
		Level2 = getOrder(ORDER_FORTREE_CITY);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 120
	//14
	case ORDER_ROUTE120:
	if(FlagGet(FLAG_VISITED_LILYCOVE_CITY) && FlagGet(FLAG_VISITED_FORTREE_CITY)){
		Level1 = getOrder(ORDER_LILYCOVE_CITY);
		Level2 = getOrder(ORDER_FORTREE_CITY);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 122 && Route 123
	//15
	case ORDER_ROUTE122:
	case ORDER_ROUTE123:
	if(FlagGet(FLAG_VISITED_MAUVILLE_CITY) && FlagGet(FLAG_VISITED_FORTREE_CITY)){
		Level1 = getOrder(ORDER_MAUVILLE_CITY);
		Level2 = getOrder(ORDER_FORTREE_CITY);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 124 & Route 125
	//16
	case ORDER_ROUTE124:
	case ORDER_ROUTE125:
	if(FlagGet(FLAG_VISITED_LILYCOVE_CITY) && FlagGet(FLAG_VISITED_MOSSDEEP_CITY)){
		Level1 = getOrder(ORDER_LILYCOVE_CITY);
		Level2 = getOrder(ORDER_MOSSDEEP_CITY);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 126 & Route 127
	//17
	case ORDER_ROUTE126:
	case ORDER_ROUTE127:
	if(FlagGet(FLAG_VISITED_SOOTOPOLIS_CITY) && FlagGet(FLAG_VISITED_MOSSDEEP_CITY)){
		Level1 = getOrder(ORDER_SOOTOPOLIS_CITY);
		Level2 = getOrder(ORDER_MOSSDEEP_CITY);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 128 & Route 129 & Route 130 & Route 131
	//18
	case ORDER_ROUTE128:
	case ORDER_ROUTE129:
	case ORDER_ROUTE130:
	case ORDER_ROUTE131:
	if(FlagGet(FLAG_VISITED_SOOTOPOLIS_CITY) && FlagGet(FLAG_PACIFIDLOG_TOWN)){
		Level1 = getOrder(ORDER_SOOTOPOLIS_CITY);
		Level2 = getOrder(ORDER_PACIFIDLOG_TOWN);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Route 132 & Route 133 & Route 134
	//19
	case ORDER_ROUTE132:
	case ORDER_ROUTE133:
	case ORDER_ROUTE134:
	if(FlagGet(FLAG_VISITED_SLATEPORT_CITY) && FlagGet(FLAG_PACIFIDLOG_TOWN)){
		Level1 = getOrder(ORDER_SLATEPORT_CITY);
		Level2 = getOrder(ORDER_PACIFIDLOG_TOWN);
		if(Level1 > Level2)
			return Level1;
		else 
			return Level2;
	}else
		return WildLevel;
	break;
	//Side Areas: New Mauville, Meteor Falls(Post Game Area), Safari Zone, Shoal Cave
	case ORDER_SIDE_AREA:
	return WildLevel;
	break;
	}/*/
}

u8 getOrder(u8 id){
	if(FlagGet(FLAG_HARD_MODE))
		return Normal_Mode_Min_Wild_Pokemon_Level_Order[getCityOrder(id)] + getLevelBoost();
	else if(FlagGet(FLAG_EASY_MODE))
		return Normal_Mode_Min_Wild_Pokemon_Level_Order[getCityOrder(id)] + getLevelBoost();
	else
		return Normal_Mode_Min_Wild_Pokemon_Level_Order[getCityOrder(id)] + getLevelBoost();
}

u8 getCityOrder(u8 id){
	return id;
}

void RandomizeParty(void)
{
	u32 i, j;
	u16 randomizedspecie;
	u8 level;
	
	//Clear Battle Moves
	for (i = 0; i < CalculatePlayerPartyCount(); i++)
    {
        for (j = 0; j < 4; j++)
        {
            SetMonMoveSlot(&gPlayerParty[i], MOVE_NONE, j);
        }
	}
	
	//Randomize Species
	for (i = 0; i < CalculatePlayerPartyCount(); i++)
    {
		level = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
		randomizedspecie = GetRandomizedTrainerPokemon(GetRandomFirstStage(SPECIES_NONE), level);
		SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &randomizedspecie);
		SetMonData(&gPlayerParty[i], MON_DATA_NICKNAME, &gSpeciesNames[randomizedspecie]);
		CalculateMonStats(&gPlayerParty[i]);
		
		GiveMonInitialMoveset(&gPlayerParty[i]);
    }
}

void RandomizeIfSpeciesNone(void)
{
	u32 i, j;
	u16 randomizedspecie;
	u8 level;
	u16 newSpecies = SPECIES_BULBASAUR;
	u16 newFormID = 0;
	
	//Clear Battle Moves
	for (i = 0; i < CalculatePlayerPartyCount(); i++)
    {
		if(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_NONE){
			for (j = 0; j < 4; j++)
			{
				SetMonMoveSlot(&gPlayerParty[i], MOVE_NONE, j);
			}
		}
	}
	
	//For Permanent Mega Latios and Mega Latias
	for (i = 0; i < CalculatePlayerPartyCount(); i++)
    {
		if(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_LATIOS_MEGA){
			newSpecies = SPECIES_LATIOS;
			SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &newSpecies);
			SetMonData(&gPlayerParty[i], MON_DATA_NICKNAME, &gSpeciesNames[newSpecies]);
			GiveMonInitialMoveset(&gPlayerParty[i]);
			CalculateMonStats(&gPlayerParty[i]);
		}
		else if(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_LATIAS_MEGA){
			newSpecies = SPECIES_LATIAS;
			SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &newSpecies);
			SetMonData(&gPlayerParty[i], MON_DATA_NICKNAME, &gSpeciesNames[newSpecies]);
			GiveMonInitialMoveset(&gPlayerParty[i]);
			CalculateMonStats(&gPlayerParty[i]);
		}
	}
	
	//Randomize Species
	for (i = 0; i < CalculatePlayerPartyCount(); i++)
    {
		if(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_NONE){
			level = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
			randomizedspecie = GetRandomizedTrainerPokemon(GetRandomFirstStage(SPECIES_NONE), level);
			SetMonData(&gPlayerParty[i], MON_DATA_SPECIES, &randomizedspecie);
			SetMonData(&gPlayerParty[i], MON_DATA_NICKNAME, &gSpeciesNames[randomizedspecie]);
			GiveMonInitialMoveset(&gPlayerParty[i]);
		}
		CalculateMonStats(&gPlayerParty[i]);
    }
}

u8 GetEggMoveTutorMovesfromSpecies(u16 formSpeciesId, u16 *moves)
{
    u8 numMoves = 0;
	u16 eggMoveBuffer[EGG_MOVES_ARRAY_COUNT];
	u16 firsStage = GetFirstEvolution(formSpeciesId);
	u16 numEggMoves = GetEggMovesSpecies(firsStage, eggMoveBuffer);
    int i;
	const u8 *learnableMoves;
	
	for (i = 0; i < numEggMoves; i++)
    {
        moves[numMoves++] = eggMoveBuffer[i];
    }
	
    return numMoves;
}

u16 GetRandomItem(u16 species, u16 ability, u8 count, bool8 canMega)
{
    u32 i;
	u16 item = 0;
	u8 rand = Random();
	
	u16 sHeldItemList[] = {
		ITEM_LUM_BERRY,
		ITEM_FOCUS_SASH,
		ITEM_SITRUS_BERRY,
		ITEM_LIFE_ORB,
		ITEM_LEFTOVERS,
		ITEM_QUICK_CLAW,
		ITEM_WHITE_HERB,
		ITEM_WEAKNESS_POLICY,
		ITEM_POWER_HERB,
		ITEM_ASSAULT_VEST,
		ITEM_ROCKY_HELMET,
		ITEM_EXPERT_BELT,
		ITEM_ZOOM_LENS,
		ITEM_WIDE_LENS,
		ITEM_PROTECTIVE_PADS,
		ITEM_KINGS_ROCK,
		ITEM_FOCUS_BAND,
	};
	
	item = sHeldItemList[Random() % (sizeof(sHeldItemList)/sizeof(sHeldItemList[0]))];
	
	switch(ability)
	{
		case ABILITY_DRIZZLE:
			item = ITEM_DAMP_ROCK;
		break;
		case ABILITY_DROUGHT:
			item = ITEM_HEAT_ROCK;
		break;
		case ABILITY_SNOW_WARNING:
			item = ITEM_ICY_ROCK;
		break;
		case ABILITY_SAND_STREAM:
			item = ITEM_SMOOTH_ROCK;
		break;
		case ABILITY_ELECTRIC_SURGE:
		case ABILITY_GRASSY_SURGE:
		case ABILITY_MISTY_SURGE:
		case ABILITY_PSYCHIC_SURGE:
		case ABILITY_OPPOSITE_DAY:
		case ABILITY_TRICKSTER:
			item = ITEM_TERRAIN_EXTENDER;
		break;
		case ABILITY_GUTS:
		case ABILITY_QUICK_FEET:
		case ABILITY_POISON_HEAL:
		case ABILITY_TOXIC_BOOST:
			item = ITEM_TOXIC_ORB;
		break;
		case ABILITY_FLARE_BOOST:
			item = ITEM_FLAME_ORB;
		break;
		case ABILITY_HARVEST:
			item = ITEM_SITRUS_BERRY;
		break;
		case ABILITY_IRON_BARBS:
		case ABILITY_ROUGH_SKIN:
			item = ITEM_ROCKY_HELMET;
		break;
		case ABILITY_SKILL_LINK:
			item = ITEM_KINGS_ROCK;
		break;
	}
	
	switch(gBaseStats[species].type1){
		case TYPE_ELECTRIC:
			if(Random() % 4 <= 1)
				item = ITEM_AIR_BALLOON;
		break;
		case TYPE_POISON:
			if(Random() % 4 <= 1)
				item = ITEM_BLACK_SLUDGE;
		break;
		case TYPE_NORMAL:
			if(Random() % 4 <= 1)
				item = ITEM_NORMAL_GEM;
		break;
		case TYPE_DRAGON:
			if(Random() % 4 <= 1 && (gBaseStats[species].type2 == TYPE_GROUND || gBaseStats[species].type2 == TYPE_FLYING))
				item = ITEM_ROSELI_BERRY;
		break;
	}
	
	//Removed this to avoid the same item on all the party
	switch(gBaseStats[species].type2){
		case TYPE_ELECTRIC:
			if(Random() % 4 <= 1)
				item = ITEM_AIR_BALLOON;
		break;
		case TYPE_POISON:
			if(Random() % 4 <= 1)
				item = ITEM_BLACK_SLUDGE;
		break;
		case TYPE_NORMAL:
			if(Random() % 4 <= 1)
				item = ITEM_NORMAL_GEM;
		break;
		case TYPE_DRAGON:
			if(Random() % 4 <= 1 && (gBaseStats[species].type1 == TYPE_GROUND || gBaseStats[species].type1 == TYPE_FLYING))
				item = ITEM_ROSELI_BERRY;
		break;
	}
	
	switch(species)
	{
		case SPECIES_PICHU:
		case SPECIES_PIKACHU:
		case SPECIES_RAICHU:
		case SPECIES_RAICHU_ALOLAN:
		case SPECIES_MINUN:
		case SPECIES_PLUSLE:
			item = ITEM_LIGHT_BALL;
		break;
		case SPECIES_FARFETCHD:
		case SPECIES_FARFETCHD_GALARIAN:
		case SPECIES_SIRFETCHD:
			item = ITEM_STICK;
		break;
		case SPECIES_CUBONE:
		case SPECIES_MAROWAK_ALOLAN:
		case SPECIES_MAROWAK:
			item = ITEM_THICK_CLUB;
		break;
		case SPECIES_DITTO:
			item = ITEM_QUICK_POWDER;
		break;
		case SPECIES_ABOMASNOW:
			if(canMega)
				item = ITEM_ABOMASITE;
		break;
		case SPECIES_ABSOL:
			if(canMega)
				item = ITEM_ABSOLITE;
		break;
		case SPECIES_AERODACTYL:
			if(canMega)
				item = ITEM_AERODACTYLITE;
		break;
		case SPECIES_AGGRON:
			if(canMega)
				item = ITEM_AGGRONITE;
		break;
		case SPECIES_ALAKAZAM:
			if(canMega)
				item = ITEM_ALAKAZITE;
		break;
		case SPECIES_ALTARIA:
			if(canMega)
				item = ITEM_ALTARIANITE;
		break;
		case SPECIES_AMPHAROS:
			if(canMega)
				item = ITEM_AMPHAROSITE;
		break;
		case SPECIES_AUDINO:
			if(canMega)
				item = ITEM_AUDINITE;
		break;
		case SPECIES_BANETTE:
			if(canMega)
				item = ITEM_BANETTITE;
		break;
		case SPECIES_BEEDRILL:
			if(canMega)
				item = ITEM_BEEDRILLITE;
		break;
		case SPECIES_BLASTOISE:
			if(canMega)
				item = ITEM_BLASTOISINITE;
		break;
		case SPECIES_BLAZIKEN:
			if(canMega)
				item = ITEM_BLAZIKENITE;
		break;
		case SPECIES_CAMERUPT:
			if(canMega)
				item = ITEM_CAMERUPTITE;
		break;
		case SPECIES_CHARIZARD:
			if(canMega)
				item = ITEM_CHARIZARDITE_Y;
		break;
		case SPECIES_GALLADE:
			if(canMega)
				item = ITEM_GALLADITE;
		break;
		case SPECIES_GARCHOMP:
			if(canMega)
				item = ITEM_GARCHOMPITE;
		break;
		case SPECIES_GARDEVOIR:
			if(canMega)
				item = ITEM_GARDEVOIRITE;
		break;
		case SPECIES_GENGAR:
			if(canMega)
				item = ITEM_GENGARITE;
		break;
		case SPECIES_GLALIE:
			if(canMega)
				item = ITEM_GLALITITE;
		break;
		case SPECIES_GYARADOS:
			if(canMega)
				item = ITEM_GYARADOSITE;
		break;
		case SPECIES_HERACROSS:
			if(canMega)
				item = ITEM_HERACRONITE;
		break;
		case SPECIES_HOUNDOOM:
			if(canMega)
				item = ITEM_HOUNDOOMINITE;
		break;
		case SPECIES_KANGASKHAN:
			if(canMega)
				item = ITEM_KANGASKHANITE;
		break;
		case SPECIES_LOPUNNY:
			if(canMega)
				item = ITEM_LOPUNNITE;
		break;
		case SPECIES_LUCARIO:
			if(canMega)
				item = ITEM_LUCARIONITE;
		break;
		case SPECIES_MANECTRIC:
			if(canMega)
				item = ITEM_MANECTITE;
		break;
		case SPECIES_MAWILE:
			if(canMega)
				item = ITEM_MAWILITE;
		break;
		case SPECIES_MEDICHAM:
			if(canMega)
				item = ITEM_MEDICHAMITE;
		break;
		case SPECIES_METAGROSS:
			if(canMega)
				item = ITEM_METAGROSSITE;
		break;
		case SPECIES_PIDGEOT:
			if(canMega)
				item = ITEM_PIDGEOTITE;
		break;
		case SPECIES_PINSIR:
			if(canMega)
				item = ITEM_PINSIRITE;
		break;
		case SPECIES_SABLEYE:
			if(canMega)
				item = ITEM_SABLENITE;
		break;
		case SPECIES_SALAMENCE:
			if(canMega)
				item = ITEM_SALAMENCITE;
		break;
		case SPECIES_SCEPTILE:
			if(canMega)
				item = ITEM_SCEPTILITE;
		break;
		case SPECIES_SCIZOR:
			if(canMega)
				item = ITEM_SCIZORITE;
		break;
		case SPECIES_SHARPEDO:
			if(canMega)
				item = ITEM_SHARPEDONITE;
		break;
		case SPECIES_SLOWBRO:
			if(canMega)
				item = ITEM_SLOWBRONITE;
		break;
		case SPECIES_STEELIX:
			if(canMega)
				item = ITEM_STEELIXITE;
		break;
		case SPECIES_SWAMPERT:
			if(canMega)
				item = ITEM_SWAMPERTITE;
		break;
		case SPECIES_TYRANITAR:
			if(canMega)
				item = ITEM_TYRANITARITE;
		break;
		case SPECIES_VENUSAUR:
			if(canMega)
				item = ITEM_VENUSAURITE;
		break;
	}
	
	return item;
}

bool8 canPokemonLearnMove(u16 species, u8 formId, u16 move){
	u8 j, k;
	u16 formSpeciesId = GetFormSpeciesId(species, formId);
	u16 eggMoves[EGG_MOVES_ARRAY_COUNT];
	u8 numEggMoves = 0;
	
	if(move > MOVES_COUNT)
		return FALSE;
	else
		return TRUE;// <-- Here
	
	//I disabled the check since there are some things that need to be fixed
	
	//Species Check, check moves for specific species;
	switch(formSpeciesId){
		case SPECIES_DITTO:
			if(move == MOVE_TRANSFORM)
				return TRUE;
			else
				return FALSE;
		break;
		case SPECIES_SMEARGLE:
			return TRUE;
		break;
		case SPECIES_EEVEE:
			if(move == MOVE_CELEBRATE || move == MOVE_HOLD_BACK)
				return TRUE;
		break;
		case SPECIES_PICHU_SPIKY_EARED:
			if(move == MOVE_VOLT_TACKLE)
				return TRUE;
		break;
		case SPECIES_ROTOM_WASH:
			if(move == MOVE_HYDRO_PUMP)
				return TRUE;
		break;
		case SPECIES_ROTOM_HEAT:
			if(move == MOVE_HEAT_WAVE)
				return TRUE;
		break;
		case SPECIES_ROTOM_FAN:
			if(move == MOVE_AIR_SLASH ||
			   move == MOVE_HURRICANE)
				return TRUE;
		break;
		case SPECIES_ROTOM_MOW:
			if(move == MOVE_LEAF_STORM)
				return TRUE;
		break;
		case SPECIES_ROTOM_FROST:
			if(move == MOVE_BLIZZARD ||
			   move == MOVE_FREEZE_DRY)
				return TRUE;
		break;
		case SPECIES_MACHAMP:
			if(move == MOVE_FISSURE)
				return TRUE;
		break;
	}
	
	//Check for specific moves that are learned by every Pokemon
	switch(move){
		case MOVE_NONE:
		case MOVE_HIDDEN_POWER:
		case MOVE_TOXIC:
			return TRUE;
		break;
	}
	
	//Removes moves that don't have any effect and won't work
	if(gBattleMoves[move].effect == EFFECT_PLACEHOLDER)
		return FALSE;
	
	//Checks for level up moves
	for (k = 0; gLevelUpLearnsets[formSpeciesId][k].move != LEVEL_UP_END; k++){
		if(gLevelUpLearnsets[formSpeciesId][k].move == move)
			return TRUE;
	}
	
	//Checks for TMs
	for (k = 0; k< 120; k++){
		if (sTMHMMoves[k] == move && (CanSpeciesLearnTMHM(formSpeciesId, k)))
		{
			return TRUE;
		}
	}
	
	//Checks for move tutor moves
	for (k = 0; k< TUTOR_MOVE_COUNT; k++){
		if (gTutorMoves[k] == move && CanLearnTutorMove(formSpeciesId, k))
			return TRUE;
	}

	//Generates a list with all the egg moves
	numEggMoves = GetEggMoveTutorMovesfromSpecies(formSpeciesId, eggMoves);
	//Checks for egg moves
	for (k = 0; k< numEggMoves; k++){
		if (eggMoves[k] == move)
			return TRUE;
	}
	
	return FALSE;
}

bool8 CheckforMetronomeBattle(void)
{
	u32 i, j;
	u16 move;
	
	if(CalculatePlayerPartyCount() != PARTY_SIZE)
		return FALSE;
	
	for (i = 0; i < CalculatePlayerPartyCount(); i++)
    {
		
		for (j = 0; j < MAX_MON_MOVES; j++)
		{
			move = GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + j);
			
			if(move != MOVE_METRONOME && move != MOVE_NONE)
				return FALSE;
		}
    }
	
	return TRUE;
}

//Companion Stuff
#define COMPRESSED_PLAYER_PARTY_BYTE_SIZE 156
#define NUM_CLEAN_EWRAM_DATA 0

struct Pokemon CreateMonFromCompressedBattleMon(struct CompressedBattlemon CompressedBattlemon){
	struct Pokemon mon;
    u8 i;
	u16 nationalDexNum;
    int sentToPc;
    u8 formId = 0;
    u32 personality = Random32();
    u32 otid = gSaveBlock2Ptr->playerTrainerId[0]
            | (gSaveBlock2Ptr->playerTrainerId[1] << 8)
            | (gSaveBlock2Ptr->playerTrainerId[2] << 16)
            | (gSaveBlock2Ptr->playerTrainerId[3] << 24);
    u16 species    = CompressedBattlemon.species;
    u16 heldItem   = CompressedBattlemon.heldItem;
    u8 nature      = CompressedBattlemon.nature;
    bool8 exiolite = CompressedBattlemon.exiolite;

    u8 hpIV        = CompressedBattlemon.hpIV;
    u8 attackIV    = CompressedBattlemon.attackIV;
    u8 defenseIV   = CompressedBattlemon.defenseIV;
    u8 spAttackIV  = CompressedBattlemon.spAttackIV;
    u8 spDefenseIV = CompressedBattlemon.spDefenseIV;
    u8 speedIV     = CompressedBattlemon.speedIV;

    bool8 otGender = CompressedBattlemon.otGender;
    u8 hpEV        = CompressedBattlemon.hpEV;
    u8 attackEV    = CompressedBattlemon.attackEV;
    u8 defenseEV   = CompressedBattlemon.defenseEV;
    u8 spAttackEV  = CompressedBattlemon.spAttackEV;
    u8 spDefenseEV = CompressedBattlemon.spDefenseEV;
    u8 speedEV     = CompressedBattlemon.speedEV;
    u8 level       = CompressedBattlemon.level;
    u16 moves1     = CompressedBattlemon.moves1;
    u16 moves2     = CompressedBattlemon.moves2;
    u16 moves3     = CompressedBattlemon.moves3;
    u16 moves4     = CompressedBattlemon.moves4;
    u8 abilityNum  = CompressedBattlemon.abilityNum;
    u8 pokeball    = CompressedBattlemon.pokeball;

    CreateMon(&mon, species, level, 32, 1, personality, OT_ID_PRESET, otid, formId);

    SetMonData(&mon, MON_DATA_HELD_ITEM,        &heldItem);
    SetMonData(&mon, MON_DATA_HIDDEN_NATURE,    &nature);
    SetMonData(&mon, MON_DATA_EXIOLITE_ENABLED, &exiolite);
    SetMonData(&mon, MON_DATA_HP_IV,            &hpIV);
    SetMonData(&mon, MON_DATA_ATK_IV,           &attackIV);
    SetMonData(&mon, MON_DATA_DEF_IV,           &defenseIV);
    SetMonData(&mon, MON_DATA_SPATK_IV,         &spAttackIV);
    SetMonData(&mon, MON_DATA_SPDEF_IV,         &spDefenseIV);
    SetMonData(&mon, MON_DATA_SPEED_IV,         &speedIV);
    SetMonData(&mon, MON_DATA_HP_EV,            &hpEV);
    SetMonData(&mon, MON_DATA_ATK_EV,           &attackEV);
    SetMonData(&mon, MON_DATA_DEF_EV,           &defenseEV);
    SetMonData(&mon, MON_DATA_SPATK_EV,         &spAttackEV);
    SetMonData(&mon, MON_DATA_SPDEF_EV,         &spDefenseEV);
    SetMonData(&mon, MON_DATA_SPEED_EV,         &speedEV);
    SetMonData(&mon, MON_DATA_LEVEL,            &level);
    SetMonData(&mon, MON_DATA_MOVE1,            &moves1);
    SetMonData(&mon, MON_DATA_MOVE2,            &moves2);
    SetMonData(&mon, MON_DATA_MOVE3,            &moves3);
    SetMonData(&mon, MON_DATA_MOVE4,            &moves4);
    SetMonData(&mon, MON_DATA_ABILITY_NUM,      &abilityNum);
    SetMonData(&mon, MON_DATA_POKEBALL,         &pokeball);
   
    return mon;
}

#define USED_COMPRESSED_PLAYER_PARTY_BYTE_SIZE 144
struct CompressedPlayerParty CreatePartyFromRamData(){
    u8 i;
    u32 password[COMPRESSED_PLAYER_PARTY_BYTE_SIZE / 4];
    struct CompressedPlayerParty CompressedPlayerParty;
    for(i = 0; i < COMPRESSED_PLAYER_PARTY_BYTE_SIZE / 4; i++){
        password[i] = *(u32 *)(EWRAM_START + 0x3fd40 + (i * 0x4)); //Sends the password data into an array
    }
    memcpy(&CompressedPlayerParty, password, sizeof(CompressedPlayerParty));

    return CompressedPlayerParty;
}

struct Pokemon CreateMonFromPartyRamData(u8 num){
	struct Pokemon mon;
    u8 i, j;
	struct CompressedPlayerParty CompressedPlayerParty = CreatePartyFromRamData();
	struct CompressedBattlemon CompressedBattlemon = CompressedPlayerParty.CompressedParty[num];
    u32 personality = Random32();
    u16 speciesID   = CompressedBattlemon.species;
    u16 species     = GetBaseFormSpeciesId(speciesID);
    u8  formId      = GetFormIdFromFormSpeciesId(speciesID);
    u16 heldItem    = CompressedBattlemon.heldItem;
    u8  nature      = CompressedBattlemon.nature;
    bool8 exiolite  = CompressedBattlemon.exiolite;
	bool8 isShiny   = CompressedBattlemon.shinyness;

    u8 hpIV         = CompressedBattlemon.hpIV;
    u8 attackIV     = CompressedBattlemon.attackIV;
    u8 defenseIV    = CompressedBattlemon.defenseIV;
    u8 spAttackIV   = CompressedBattlemon.spAttackIV;
    u8 spDefenseIV  = CompressedBattlemon.spDefenseIV;
    u8 speedIV      = CompressedBattlemon.speedIV;

    bool8 otGender  = CompressedBattlemon.otGender;
    u8 hpEV         = CompressedBattlemon.hpEV;
    u8 attackEV     = CompressedBattlemon.attackEV;
    u8 defenseEV    = CompressedBattlemon.defenseEV;
    u8 spAttackEV   = CompressedBattlemon.spAttackEV;
    u8 spDefenseEV  = CompressedBattlemon.spDefenseEV;
    u8 speedEV      = CompressedBattlemon.speedEV;
    u8 level        = CompressedBattlemon.level;
    u16 moves1      = CompressedBattlemon.moves1;
    u16 moves2      = CompressedBattlemon.moves2;
    u16 moves3      = CompressedBattlemon.moves3;
    u16 moves4      = CompressedBattlemon.moves4;
    u8 abilityNum   = CompressedBattlemon.abilityNum;
    u8 pokeball     = CompressedBattlemon.pokeball;

    u32 otid = gSaveBlock2Ptr->playerTrainerId[0]
            | (gSaveBlock2Ptr->playerTrainerId[1] << 8)
            | (gSaveBlock2Ptr->playerTrainerId[2] << 16)
            | (gSaveBlock2Ptr->playerTrainerId[3] << 24);

	if (isShiny)
    {
        do
        {
            personality = Random32();
            personality = ((((Random() % 8) ^ (HIHALF(otid) ^ LOHALF(otid))) ^ LOHALF(personality)) << 16) | LOHALF(personality);
        } while (nature != GetNatureFromPersonality(personality));
    }

    CreateMon(&mon, species, level, 32, TRUE, personality, OT_ID_PRESET, otid, formId);

	
	if(FlagGet(FLAG_MGBA_PRINT_ENABLED))
		mgba_printf(MGBA_LOG_WARN, "Species %d", GetMonData(&mon, MON_DATA_SPECIES));

    SetMonData(&mon, MON_DATA_HELD_ITEM,        &heldItem);
    SetMonData(&mon, MON_DATA_HIDDEN_NATURE,    &nature);
    SetMonData(&mon, MON_DATA_EXIOLITE_ENABLED, &exiolite);
    SetMonData(&mon, MON_DATA_HP_IV,            &hpIV);
    SetMonData(&mon, MON_DATA_ATK_IV,           &attackIV);
    SetMonData(&mon, MON_DATA_DEF_IV,           &defenseIV);
    SetMonData(&mon, MON_DATA_SPATK_IV,         &spAttackIV);
    SetMonData(&mon, MON_DATA_SPDEF_IV,         &spDefenseIV);
    SetMonData(&mon, MON_DATA_SPEED_IV,         &speedIV);
    SetMonData(&mon, MON_DATA_HP_EV,            &hpEV);
    SetMonData(&mon, MON_DATA_ATK_EV,           &attackEV);
    SetMonData(&mon, MON_DATA_DEF_EV,           &defenseEV);
    SetMonData(&mon, MON_DATA_SPATK_EV,         &spAttackEV);
    SetMonData(&mon, MON_DATA_SPDEF_EV,         &spDefenseEV);
    SetMonData(&mon, MON_DATA_SPEED_EV,         &speedEV);
    SetMonData(&mon, MON_DATA_LEVEL,            &level);
    SetMonData(&mon, MON_DATA_MOVE1,            &moves1);
    SetMonData(&mon, MON_DATA_MOVE2,            &moves2);
    SetMonData(&mon, MON_DATA_MOVE3,            &moves3);
    SetMonData(&mon, MON_DATA_MOVE4,            &moves4);
    SetMonData(&mon, MON_DATA_ABILITY_NUM,      &abilityNum);
    SetMonData(&mon, MON_DATA_POKEBALL,         &pokeball);
   
    return mon;
}

void ClearPartyFromRam(){
    u8 i;

    for(i = 0; i < COMPRESSED_PLAYER_PARTY_BYTE_SIZE; i++){
        DmaFill16(3, NUM_CLEAN_EWRAM_DATA, EWRAM_START + 0x3fd40 + (i * 0x1), 0x2); //Clears the data
    }
}

enum{
    PASSWORD_TRAINER_NEWBIE,
    PASSWORD_TRAINER_NORMAL,
    PASSWORD_TRAINER_CHAMPION,
    PASSWORD_TRAINER_MASTER,
    PASSWORD_TRAINER_LEGEND,
};

#define COMPRESSED_BATTLEMON_BYTE_SIZE 24
struct CompressedBattlemon partyToCompressedBattlemon(u8 num){
    struct CompressedBattlemon CompressedBattlemon;
    struct CompressedBattlemon from;
    struct CompressedBattlemon newBattlemon;
    struct Pokemon *mon = &gPlayerParty[num];
    u8 to[COMPRESSED_BATTLEMON_BYTE_SIZE];

    CompressedBattlemon.species     = GetMonData(mon, MON_DATA_SPECIES2, NULL);
    CompressedBattlemon.heldItem    = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
    CompressedBattlemon.nature      = GetNature(mon, TRUE);
    CompressedBattlemon.exiolite    = GetMonData(mon, MON_DATA_EXIOLITE_ENABLED, NULL);
    CompressedBattlemon.hpIV        = GetMonData(mon, MON_DATA_HP_IV, NULL);
    CompressedBattlemon.attackIV    = GetMonData(mon, MON_DATA_ATK_IV, NULL);
    CompressedBattlemon.defenseIV   = GetMonData(mon, MON_DATA_DEF_IV, NULL);
    CompressedBattlemon.spAttackIV  = GetMonData(mon, MON_DATA_SPATK_IV, NULL);
    CompressedBattlemon.spDefenseIV = GetMonData(mon, MON_DATA_SPDEF_IV, NULL);
    CompressedBattlemon.speedIV     = GetMonData(mon, MON_DATA_SPEED_IV, NULL);

    CompressedBattlemon.hpEV        = GetMonData(mon, MON_DATA_HP_EV, NULL);
    CompressedBattlemon.attackEV    = GetMonData(mon, MON_DATA_ATK_EV, NULL);
    CompressedBattlemon.defenseEV   = GetMonData(mon, MON_DATA_DEF_EV, NULL);
    CompressedBattlemon.spAttackEV  = GetMonData(mon, MON_DATA_SPATK_EV, NULL);
    CompressedBattlemon.spDefenseEV = GetMonData(mon, MON_DATA_SPDEF_EV, NULL);
    CompressedBattlemon.speedEV     = GetMonData(mon, MON_DATA_SPEED_EV, NULL);

    CompressedBattlemon.level       = GetMonData(mon, MON_DATA_LEVEL, NULL);
    CompressedBattlemon.moves1      = GetMonData(mon, MON_DATA_MOVE1, NULL);
    CompressedBattlemon.moves2      = GetMonData(mon, MON_DATA_MOVE2, NULL);
    CompressedBattlemon.moves3      = GetMonData(mon, MON_DATA_MOVE3, NULL);
    CompressedBattlemon.moves4      = GetMonData(mon, MON_DATA_MOVE4, NULL);
    CompressedBattlemon.abilityNum  = GetMonData(mon, MON_DATA_ABILITY_NUM, NULL);
    CompressedBattlemon.pokeball    = GetMonData(mon, MON_DATA_POKEBALL, NULL);
    if(IsMonShiny(mon))
        CompressedBattlemon.shinyness = TRUE;
    else
        CompressedBattlemon.shinyness = FALSE;

    return CompressedBattlemon;
}

bool8 CreatePlayerPartyPassword(void){
    u8 i;
    struct CompressedPlayerParty CompressedPlayerParty;
    struct CompressedBattlemon CompressedParty[PARTY_SIZE];
    u16 to[COMPRESSED_PLAYER_PARTY_BYTE_SIZE / 2];

    CompressedPlayerParty.trainerGender  = gSaveBlock2Ptr->playerGender;
    CompressedPlayerParty.trainerCostume = GetCostume();
    CompressedPlayerParty.redColor       = gSaveBlock2Ptr->playerRGB[0];
    CompressedPlayerParty.greenColor     = gSaveBlock2Ptr->playerRGB[1];
    CompressedPlayerParty.blueColor      = gSaveBlock2Ptr->playerRGB[2];
    CompressedPlayerParty.partySize      = GetPlayerPartySize();

    if(FlagGet(FLAG_SYS_GAME_CLEAR)){
        if(FlagGet(FLAG_EASY_MODE) || FlagGet(FLAG_NORMAL_MODE))
            CompressedPlayerParty.title = PASSWORD_TRAINER_CHAMPION;
        else
            CompressedPlayerParty.title = PASSWORD_TRAINER_MASTER;
    }
    else{
        if(FlagGet(FLAG_EASY_MODE))
            CompressedPlayerParty.title = PASSWORD_TRAINER_NEWBIE;
        else
            CompressedPlayerParty.title = PASSWORD_TRAINER_NORMAL;
    }
    
    for(i = 0; i < PLAYER_NAME_LENGTH + 1; i++){
        CompressedPlayerParty.trainerName[i] = gSaveBlock2Ptr->playerName[i];
    }

    for(i = 0; i < PARTY_SIZE; i++){
        CompressedPlayerParty.CompressedParty[i] = partyToCompressedBattlemon(i);
    }

    ClearPartyFromRam();//Just in case
    //To tell the game you gave the instruction to add this
    DmaFill16(3, TRUE, EWRAM_START + 0x3fd3f, 0x2);

    memcpy(to, &CompressedPlayerParty, sizeof(to));
    for(i = 0; i < (COMPRESSED_PLAYER_PARTY_BYTE_SIZE / 2); i++){
        DmaFill16(3, to[i], EWRAM_START + 0x3fd40 + (i * 0x2), 0x2);
    }

	return TRUE;
}

bool8 CheckRamForPasswordTrainer(void){
	u8 i;
    struct CompressedPlayerParty CompressedPlayerParty = CreatePartyFromRamData();
	u8 partySize = CompressedPlayerParty.partySize;
	u16 species;

	for(i = 0; i < partySize; i++){
		struct Pokemon newMon = CreateMonFromPartyRamData(i);
        species = GetMonData(&newMon, MON_DATA_SPECIES);
		if(species == SPECIES_NONE){
			if(FlagGet(FLAG_MGBA_PRINT_ENABLED))
				mgba_printf(MGBA_LOG_WARN, "Check %d Failed", i);
			return FALSE;
		}
	}

	if(partySize == 0){
		return FALSE;
	}

	return TRUE;
}