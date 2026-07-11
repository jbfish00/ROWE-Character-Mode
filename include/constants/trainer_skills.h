#ifndef GUARD_CONSTANTS_TRAINER_SKILLS_H
#define GUARD_CONSTANTS_TRAINER_SKILLS_H

// 2.X Trainer Skills. Skill points are earned from Trainer XP (every enemy
// Pokemon defeated or caught) and spent here. Order matches the doc sheet.
enum {
    SKILL_XP_BOOST_TRAINER,
    SKILL_XP_BOOST_POKEMON,
    SKILL_GOLD_RUSH,
    SKILL_BARGAIN,
    SKILL_SNIPER_BALL,
    SKILL_STEP_HEAL,
    SKILL_REBIRTH,
    SKILL_STAY_AWAY,
    SKILL_SKILL_RESTORE,
    SKILL_JOY_BOOST,
    SKILL_REVITALIZE,
    SKILL_DEEP_SCAN,
    SKILL_EGGCELERATE,
    SKILL_RARE_SIGHT,
    SKILL_QUICK_EXIT,
    SKILL_BONUS_BATTLE,
    SKILL_LOOT_BOOST,
    // The stat boosts REPLACE Pokemon IVs (doc: "These skills replace Pokemon
    // IVs in this ROM hack"). Keep these six contiguous and in STAT_* order so
    // the IV lookup can index them directly.
    SKILL_HP_BOOST,
    SKILL_ATTACK_BOOST,
    SKILL_DEFENSE_BOOST,
    SKILL_SPEED_BOOST,
    SKILL_SPATK_BOOST,
    SKILL_SPDEF_BOOST,
    SKILL_MAX_PP_BOOST,
    SKILL_ROCK_SMASH_BOOST,
    NUM_TRAINER_SKILLS,
};

#define MAX_SKILL_NUM        100   // saveblock array size (2.X value)
#define MAX_SKILL_LEVEL      10    // per skill

// 10 points fill a stat: 9 x 3 IVs + a final point worth 4 = exactly 31.
#define SKILL_IV_PER_LEVEL   3
#define SKILL_IV_MAX         31

#endif // GUARD_CONSTANTS_TRAINER_SKILLS_H
