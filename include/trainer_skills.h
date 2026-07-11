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

#endif // GUARD_TRAINER_SKILLS_H
