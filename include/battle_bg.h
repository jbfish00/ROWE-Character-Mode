#ifndef GUARD_BATTLE_BG_H
#define GUARD_BATTLE_BG_H

void BattleInitBgsAndWindows(void);
void InitBattleBgsVideo(void);
void LoadBattleMenuWindowGfx(void);
void DrawMainBattleBackground(void);
void LoadBattleTextboxAndBackground(void);
void InitLinkBattleVsScreen(u8 taskId);
void DrawBattleEntryBackground(void);
bool8 LoadChosenBattleElement(u8 caseId);
void DrawTerrainTypeBattleBackground(void);

#endif // GUARD_BATTLE_BG_H

// Shiny battle frame -- PLAN.md item #13. The tint is pure and separately
// declared so the headless suite can assert the transform without a battle.
u16 CharacterMode_ShinyFrameTint(u16 color);
bool8 CharacterMode_ApplyShinyBattleFrame(void);
