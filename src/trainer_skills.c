#include "global.h"
#include "event_data.h"
#include "pokemon.h"
#include "random.h"
#include "trainer_skills.h"
#include "constants/trainer_skills.h"
#include "constants/pokemon.h"

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
