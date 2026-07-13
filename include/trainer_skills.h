#ifndef GUARD_TRAINER_SKILLS_H
#define GUARD_TRAINER_SKILLS_H

#include "constants/trainer_skills.h"

u16 getMaxSkillPoints(void);
u16 getCurrentSkillPoints(void);
u16 getRemainingSkillPoints(void);
u8  getTrainerSkillLevel(u8 skillNum);
bool8 TryRaiseTrainerSkill(u8 skillNum);
bool8 TryLowerTrainerSkill(u8 skillNum);
void ResetSkills(void);
u16 calculateTrainerExp(u16 exp, u16 species, bool8 isTrainer);
bool8 tryToGivePlayerExp(u16 exp);
u8  GetSkillIV(u8 statId);

u32 ApplySkillExpBoost(u32 exp);
u32 ApplySkillGoldRush(u32 money);
u32 ApplySkillBargain(u32 price);
u32 ApplySkillSniperBall(u32 odds, u32 baseOdds);
u16 ApplySkillStayAway(u16 steps);
u16 GetSkillEscapeBonus(void);
s8  ApplySkillJoyBoost(s8 mod);
u8  GetSkillMaxPpBonus(u8 basePP);
u8  GetSkillHiddenMonBonus(void);
void ResetDexNavChain(void);
u8  GetSkillEggChanceBonus(void);
void ApplySkillStepHeal(void);
void ApplyPostBattleSkills(u32 battleOutcome, u32 battleTypeFlags);

void TrainerSkillsMenu_Open(void);
void Task_OpenTrainerSkillsMenu(u8 taskId);

#endif // GUARD_TRAINER_SKILLS_H
