#include "global.h"
#include "event_data.h"
#include "pokemon.h"
#include "random.h"
#include "trainer_skills.h"
#include "constants/trainer_skills.h"
#include "constants/pokemon.h"
#include "constants/battle.h"
#include "constants/moves.h"
#include "constants/vars.h"

// ===== 2.X Trainer Skills =====
// Trainer XP is earned every time an enemy Pokemon is defeated or caught, and
// converts into Skill Points at milestones. Points are spent on the skills in
// constants/trainer_skills.h.
//
// The headline mechanic (doc sheet): the six stat-boost skills REPLACE
// Pokemon IVs. Every mon has 0 IVs in a stat until points go into that skill,
// at which point EVERY Pokemon the player owns -- party, PC, and ones not yet
// caught -- gains them. So IVs are a trainer-wide investment, not a per-mon
// roll.

// Skill Points come at increasing XP milestones: point N costs N * 100 XP
// (cumulative), which keeps early points quick and later ones a real
// investment.
#define SKILL_POINT_BASE_COST 100

u16 getMaxSkillPoints(void)
{
    u32 exp = gSaveBlock1Ptr->trainerExp;
    u16 points = 0;
    u32 cost = SKILL_POINT_BASE_COST;

    while (exp >= cost && points < 255)
    {
        exp -= cost;
        points++;
        cost = (u32)(points + 1) * SKILL_POINT_BASE_COST;
    }

    return points;
}

u16 getCurrentSkillPoints(void)
{
    u16 spent = 0;
    u8 i;

    for (i = 0; i < NUM_TRAINER_SKILLS; i++)
        spent += gSaveBlock1Ptr->trainerSkillLevel[i];

    return spent;
}

u16 getRemainingSkillPoints(void)
{
    u16 max = getMaxSkillPoints();
    u16 spent = getCurrentSkillPoints();

    if (spent >= max)
        return 0;

    return max - spent;
}

u8 getTrainerSkillLevel(u8 skillNum)
{
    if (skillNum >= NUM_TRAINER_SKILLS)
        return 0;

    return gSaveBlock1Ptr->trainerSkillLevel[skillNum];
}

bool8 TryRaiseTrainerSkill(u8 skillNum)
{
    if (skillNum >= NUM_TRAINER_SKILLS)
        return FALSE;
    if (gSaveBlock1Ptr->trainerSkillLevel[skillNum] >= MAX_SKILL_LEVEL)
        return FALSE;
    if (getRemainingSkillPoints() == 0)
        return FALSE;

    gSaveBlock1Ptr->trainerSkillLevel[skillNum]++;
    return TRUE;
}

bool8 TryLowerTrainerSkill(u8 skillNum)
{
    if (skillNum >= NUM_TRAINER_SKILLS)
        return FALSE;
    if (gSaveBlock1Ptr->trainerSkillLevel[skillNum] == 0)
        return FALSE;

    gSaveBlock1Ptr->trainerSkillLevel[skillNum]--;
    return TRUE;
}

void ResetSkills(void)
{
    u8 i;

    for (i = 0; i < MAX_SKILL_NUM; i++)
        gSaveBlock1Ptr->trainerSkillLevel[i] = 0;
}

// Trainer XP scales with the defeated mon's level; the XP Boost - Trainer
// skill multiplies it (10% per level).
u16 calculateTrainerExp(u16 exp, u16 species, bool8 isTrainer)
{
    u32 gained = exp;

    if (isTrainer)
        gained = gained * 3 / 2;

    gained = gained * (100 + 10 * getTrainerSkillLevel(SKILL_XP_BOOST_TRAINER)) / 100;

    if (gained > 0xFFFF)
        gained = 0xFFFF;

    return gained;
}

bool8 tryToGivePlayerExp(u16 exp)
{
    u16 before = getMaxSkillPoints();

    if (gSaveBlock1Ptr->trainerExp > 0xFFFFFFFF - exp)
        gSaveBlock1Ptr->trainerExp = 0xFFFFFFFF;
    else
        gSaveBlock1Ptr->trainerExp += exp;

    // TRUE when this XP crossed a milestone (a new Skill Point is available)
    return (getMaxSkillPoints() > before);
}

// ===== Skill effects =====
// The doc sheet gives each skill's effect but not its per-level numbers (those live in
// 2.X engine code the donor does not ship). Magnitudes below are reconstructed; each is
// stated next to its function. All are no-ops at level 0, so an unspent tree plays like
// stock 1.9.4.

// XP Boost - Pokemon: +5% battle EXP per level.
u32 ApplySkillExpBoost(u32 exp)
{
    return exp * (100 + 5 * getTrainerSkillLevel(SKILL_XP_BOOST_POKEMON)) / 100;
}

// Gold Rush: +10% victory money per level.
u32 ApplySkillGoldRush(u32 money)
{
    return money * (100 + 10 * getTrainerSkillLevel(SKILL_GOLD_RUSH)) / 100;
}

// Bargain: -1% off shop buy prices per level (the one magnitude the doc states).
// Hooked into shop.c's GetItemBuyPrice(); money shops only, BP prices stay full.
u32 ApplySkillBargain(u32 price)
{
    return price * (100 - getTrainerSkillLevel(SKILL_BARGAIN)) / 100;
}

// Sniper Ball: critical-capture odds gain 10% of the throw's base catch odds per
// level, ADDED after the dex-count scaling -- so it still helps early game, when a
// small dex zeroes the normal crit chance.
u32 ApplySkillSniperBall(u32 odds, u32 baseOdds)
{
    return odds + baseOdds * getTrainerSkillLevel(SKILL_SNIPER_BALL) / 10;
}

// Stay Away: +20 repel steps per level (the doc names repels only; lures untouched).
u16 ApplySkillStayAway(u16 steps)
{
    return steps + 20 * getTrainerSkillLevel(SKILL_STAY_AWAY);
}

// Quick Exit: +10 per level on the 0..255 escape roll.
u16 GetSkillEscapeBonus(void)
{
    return 10 * getTrainerSkillLevel(SKILL_QUICK_EXIT);
}

// Joy Boost: positive friendship changes grow by level*10%, rounded up (doubled at
// max). Vanilla gains are 2..5, so plain percentage math would floor to nothing.
s8 ApplySkillJoyBoost(s8 mod)
{
    if (mod > 0)
        mod += (mod * getTrainerSkillLevel(SKILL_JOY_BOOST) + 9) / 10;

    return mod;
}

// Max PP Boost: +5% of a move's base PP per level (a PP Up is 20%).
u8 GetSkillMaxPpBonus(u8 basePP)
{
    return basePP * getTrainerSkillLevel(SKILL_MAX_PP_BOOST) / 20;
}

// Rare Sight: +2% per level on the hidden-Pokemon search roll (base 60%).
u8 GetSkillHiddenMonBonus(void)
{
    return 2 * getTrainerSkillLevel(SKILL_RARE_SIGHT);
}

// Deep Scan: whenever the DexNav chain resets, it restarts at 5*level instead of 0,
// so every search begins with that much search-level benefit already banked.
void ResetDexNavChain(void)
{
    VarSet(VAR_DEXNAV_CHAIN, 5 * getTrainerSkillLevel(SKILL_DEEP_SCAN));
}

// Eggcelerate: +5% per level on the daycare compatibility roll.
u8 GetSkillEggChanceBonus(void)
{
    return 5 * getTrainerSkillLevel(SKILL_EGGCELERATE);
}

// Step Heal: every 100 steps, each party Pokemon recovers `level` HP. (The 2.X doc
// says "Gain 1 HP each 100 Steps" and flags it as bugged there; this is the working
// reconstruction, scaled by level so points past the first matter.)
void ApplySkillStepHeal(void)
{
    u8 level = getTrainerSkillLevel(SKILL_STEP_HEAL);
    u16 steps;
    u16 hp, maxHP;
    u32 i;

    if (level == 0)
        return;

    steps = VarGet(VAR_SKILL_STEPS) + 1;
    if (steps < 100)
    {
        VarSet(VAR_SKILL_STEPS, steps);
        return;
    }
    VarSet(VAR_SKILL_STEPS, 0);

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_NONE
         || GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, NULL))
            continue;

        hp = GetMonData(&gPlayerParty[i], MON_DATA_HP, NULL);
        maxHP = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP, NULL);
        // Step Heal never revives -- that is Rebirth's job.
        if (hp == 0 || hp >= maxHP)
            continue;

        hp += level;
        if (hp > maxHP)
            hp = maxHP;
        SetMonData(&gPlayerParty[i], MON_DATA_HP, &hp);
    }
}

// Rebirth / Revitalize / Skill Restore, all rolled once per won (or catch-won) battle:
// - Rebirth: each fainted mon has a 5%-per-level chance to come back at 25% max HP.
// - Revitalize: each standing mon recovers level*10% of its max HP.
// - Skill Restore: each standing mon recovers level*10% of every move's max PP.
// Revived mons get neither top-up; coming back at all is the reward.
void ApplyPostBattleSkills(u32 battleOutcome, u32 battleTypeFlags)
{
    u8 rebirth = getTrainerSkillLevel(SKILL_REBIRTH);
    u8 revitalize = getTrainerSkillLevel(SKILL_REVITALIZE);
    u8 restore = getTrainerSkillLevel(SKILL_SKILL_RESTORE);
    u16 hp, maxHP;
    u8 maxPP, pp;
    u16 move;
    u32 i, j;

    if (rebirth + revitalize + restore == 0)
        return;
    if (battleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_FRONTIER | BATTLE_TYPE_TRAINER_HILL | BATTLE_TYPE_SAFARI))
        return;
    if (battleOutcome != B_OUTCOME_WON && battleOutcome != B_OUTCOME_CAUGHT)
        return;

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == SPECIES_NONE
         || GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, NULL))
            continue;

        hp = GetMonData(&gPlayerParty[i], MON_DATA_HP, NULL);
        maxHP = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP, NULL);

        if (hp == 0)
        {
            if (rebirth != 0 && (Random() % 100) < 5 * rebirth)
            {
                hp = maxHP / 4;
                if (hp == 0)
                    hp = 1;
                SetMonData(&gPlayerParty[i], MON_DATA_HP, &hp);
            }
            continue;
        }

        if (revitalize != 0 && hp < maxHP)
        {
            hp += maxHP * revitalize / 10;
            if (hp > maxHP)
                hp = maxHP;
            SetMonData(&gPlayerParty[i], MON_DATA_HP, &hp);
        }

        if (restore != 0)
        {
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                move = GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + j, NULL);
                if (move == MOVE_NONE)
                    continue;

                maxPP = CalculatePPWithBonus(move, GetMonData(&gPlayerParty[i], MON_DATA_PP_BONUSES, NULL), j);
                pp = GetMonData(&gPlayerParty[i], MON_DATA_PP1 + j, NULL);
                if (pp >= maxPP)
                    continue;

                pp += maxPP * restore / 10;
                if (pp > maxPP)
                    pp = maxPP;
                SetMonData(&gPlayerParty[i], MON_DATA_PP1 + j, &pp);
            }
        }
    }
}

// ---- the IV replacement ----
// statId is a STAT_* (STAT_HP..STAT_SPDEF); the six stat-boost skills are laid
// out contiguously in that same order, so this indexes straight across.
u8 GetSkillIV(u8 statId)
{
    u8 level;

    if (statId >= NUM_STATS)
        return 0;

    level = getTrainerSkillLevel(SKILL_HP_BOOST + statId);

    if (level >= MAX_SKILL_LEVEL)
        return SKILL_IV_MAX;   // final point is worth 4, landing exactly on 31

    return level * SKILL_IV_PER_LEVEL;
}
