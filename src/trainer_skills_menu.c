#include "global.h"
#include "bg.h"
#include "event_data.h"
#include "field_effect.h"
#include "list_menu.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "map_name_popup.h"
#include "palette.h"
#include "pokemon.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "trainer_skills.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/trainer_skills.h"

// ===== 2.X Trainer Skills menu =====
// The donor ships only the header for its skills menu, so this is a fresh
// implementation on the standard list-menu framework: a scrollable list of the
// skills with their level, RIGHT/A to spend a point, LEFT/B... to refund one.
// The header window shows the points still available.

#define SKILLS_MENU_WIDTH   17
#define SKILLS_MENU_HEIGHT  6
#define SKILLS_HEADER_WIDTH 12

static void SkillsMenu_HandleInput(u8 taskId);
static void SkillsMenu_Destroy(u8 taskId);
static void SkillsMenu_RedrawHeader(u8 windowId);

static const u8 sText_SkillsTitle[]  = _("Points left: {STR_VAR_1}");
static const u8 sText_SkillFmt[]     = _("{STR_VAR_1} {STR_VAR_2}");

static const u8 sText_Skill_XpTrainer[]  = _("XP Boost-Trainer");
static const u8 sText_Skill_XpPokemon[]  = _("XP Boost-Pokemon");
static const u8 sText_Skill_GoldRush[]   = _("Gold Rush");
static const u8 sText_Skill_Bargain[]    = _("Bargain");
static const u8 sText_Skill_SniperBall[] = _("Sniper Ball");
static const u8 sText_Skill_StepHeal[]   = _("Step Heal");
static const u8 sText_Skill_Rebirth[]    = _("Rebirth");
static const u8 sText_Skill_StayAway[]   = _("Stay Away");
static const u8 sText_Skill_SkillRest[]  = _("Skill Restore");
static const u8 sText_Skill_JoyBoost[]   = _("Joy Boost");
static const u8 sText_Skill_Revitalize[] = _("Revitalize");
static const u8 sText_Skill_DeepScan[]   = _("Deep Scan");
static const u8 sText_Skill_Eggcelerate[]= _("Eggcelerate");
static const u8 sText_Skill_RareSight[]  = _("Rare Sight");
static const u8 sText_Skill_QuickExit[]  = _("Quick Exit");
static const u8 sText_Skill_BonusBattle[]= _("Bonus Battle");
static const u8 sText_Skill_LootBoost[]  = _("Loot Boost");
static const u8 sText_Skill_HpBoost[]    = _("HP Boost");
static const u8 sText_Skill_AtkBoost[]   = _("Attack Boost");
static const u8 sText_Skill_DefBoost[]   = _("Defense Boost");
static const u8 sText_Skill_SpeBoost[]   = _("Speed Boost");
static const u8 sText_Skill_SpaBoost[]   = _("Sp. Atk Boost");
static const u8 sText_Skill_SpdBoost[]   = _("Sp. Def Boost");
static const u8 sText_Skill_MaxPp[]      = _("Max PP Boost");
static const u8 sText_Skill_RockSmash[]  = _("Rock Smash Boost");

static const u8 *const sSkillNames[NUM_TRAINER_SKILLS] = {
    [SKILL_XP_BOOST_TRAINER] = sText_Skill_XpTrainer,
    [SKILL_XP_BOOST_POKEMON] = sText_Skill_XpPokemon,
    [SKILL_GOLD_RUSH]        = sText_Skill_GoldRush,
    [SKILL_BARGAIN]          = sText_Skill_Bargain,
    [SKILL_SNIPER_BALL]      = sText_Skill_SniperBall,
    [SKILL_STEP_HEAL]        = sText_Skill_StepHeal,
    [SKILL_REBIRTH]          = sText_Skill_Rebirth,
    [SKILL_STAY_AWAY]        = sText_Skill_StayAway,
    [SKILL_SKILL_RESTORE]    = sText_Skill_SkillRest,
    [SKILL_JOY_BOOST]        = sText_Skill_JoyBoost,
    [SKILL_REVITALIZE]       = sText_Skill_Revitalize,
    [SKILL_DEEP_SCAN]        = sText_Skill_DeepScan,
    [SKILL_EGGCELERATE]      = sText_Skill_Eggcelerate,
    [SKILL_RARE_SIGHT]       = sText_Skill_RareSight,
    [SKILL_QUICK_EXIT]       = sText_Skill_QuickExit,
    [SKILL_BONUS_BATTLE]     = sText_Skill_BonusBattle,
    [SKILL_LOOT_BOOST]       = sText_Skill_LootBoost,
    [SKILL_HP_BOOST]         = sText_Skill_HpBoost,
    [SKILL_ATTACK_BOOST]     = sText_Skill_AtkBoost,
    [SKILL_DEFENSE_BOOST]    = sText_Skill_DefBoost,
    [SKILL_SPEED_BOOST]      = sText_Skill_SpeBoost,
    [SKILL_SPATK_BOOST]      = sText_Skill_SpaBoost,
    [SKILL_SPDEF_BOOST]      = sText_Skill_SpdBoost,
    [SKILL_MAX_PP_BOOST]     = sText_Skill_MaxPp,
    [SKILL_ROCK_SMASH_BOOST] = sText_Skill_RockSmash,
};

static const struct ListMenuItem sSkillsMenuItems[] = {
    {sText_Skill_XpTrainer,  SKILL_XP_BOOST_TRAINER},
    {sText_Skill_XpPokemon,  SKILL_XP_BOOST_POKEMON},
    {sText_Skill_GoldRush,   SKILL_GOLD_RUSH},
    {sText_Skill_Bargain,    SKILL_BARGAIN},
    {sText_Skill_SniperBall, SKILL_SNIPER_BALL},
    {sText_Skill_StepHeal,   SKILL_STEP_HEAL},
    {sText_Skill_Rebirth,    SKILL_REBIRTH},
    {sText_Skill_StayAway,   SKILL_STAY_AWAY},
    {sText_Skill_SkillRest,  SKILL_SKILL_RESTORE},
    {sText_Skill_JoyBoost,   SKILL_JOY_BOOST},
    {sText_Skill_Revitalize, SKILL_REVITALIZE},
    {sText_Skill_DeepScan,   SKILL_DEEP_SCAN},
    {sText_Skill_Eggcelerate,SKILL_EGGCELERATE},
    {sText_Skill_RareSight,  SKILL_RARE_SIGHT},
    {sText_Skill_QuickExit,  SKILL_QUICK_EXIT},
    {sText_Skill_BonusBattle,SKILL_BONUS_BATTLE},
    {sText_Skill_LootBoost,  SKILL_LOOT_BOOST},
    {sText_Skill_HpBoost,    SKILL_HP_BOOST},
    {sText_Skill_AtkBoost,   SKILL_ATTACK_BOOST},
    {sText_Skill_DefBoost,   SKILL_DEFENSE_BOOST},
    {sText_Skill_SpeBoost,   SKILL_SPEED_BOOST},
    {sText_Skill_SpaBoost,   SKILL_SPATK_BOOST},
    {sText_Skill_SpdBoost,   SKILL_SPDEF_BOOST},
    {sText_Skill_MaxPp,      SKILL_MAX_PP_BOOST},
    {sText_Skill_RockSmash,  SKILL_ROCK_SMASH_BOOST},
};

static const struct ListMenuTemplate sSkillsMenuTemplate = {
    .items = sSkillsMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .totalItems = ARRAY_COUNT(sSkillsMenuItems),
};

static const struct WindowTemplate sSkillsMenuWindow = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = SKILLS_MENU_WIDTH,
    .height = 2 * SKILLS_MENU_HEIGHT,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const struct WindowTemplate sSkillsHeaderWindow = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = SKILLS_HEADER_WIDTH,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 1 + SKILLS_MENU_WIDTH * 2 * SKILLS_MENU_HEIGHT,
};

// "Points left: N" plus the highlighted skill's level, so the player can see
// what a point actually bought without leaving the list.
static void SkillsMenu_RedrawHeader(u8 windowId)
{
    ConvertIntToDecimalStringN(gStringVar1, getRemainingSkillPoints(),
                               STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, sText_SkillsTitle);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(windowId, 1, gStringVar4, 0, 1, 0, NULL);
    CopyWindowToVram(windowId, 3);
}

void TrainerSkillsMenu_Open(void)
{
    struct ListMenuTemplate menuTemplate;
    u8 windowId, headerId, menuTaskId, inputTaskId;

    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();

    headerId = AddWindow(&sSkillsHeaderWindow);
    DrawStdWindowFrame(headerId, FALSE);
    SkillsMenu_RedrawHeader(headerId);

    windowId = AddWindow(&sSkillsMenuWindow);
    DrawStdWindowFrame(windowId, FALSE);

    menuTemplate = sSkillsMenuTemplate;
    menuTemplate.maxShowed = SKILLS_MENU_HEIGHT;
    menuTemplate.windowId = windowId;
    menuTemplate.header_X = 0;
    menuTemplate.item_X = 8;
    menuTemplate.cursor_X = 0;
    menuTemplate.upText_Y = 1;
    menuTemplate.cursorPal = 2;
    menuTemplate.fillValue = 1;
    menuTemplate.cursorShadowPal = 3;
    menuTemplate.lettersSpacing = 1;
    menuTemplate.itemVerticalPadding = 0;
    menuTemplate.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    menuTemplate.fontId = 1;
    menuTemplate.cursorKind = 0;
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    CopyWindowToVram(windowId, 3);

    ScriptContext2_Enable();   // freeze the field while the overlay is up
    inputTaskId = CreateTask(SkillsMenu_HandleInput, 3);
    gTasks[inputTaskId].data[0] = menuTaskId;
    gTasks[inputTaskId].data[1] = windowId;
    gTasks[inputTaskId].data[2] = headerId;
}

void Task_OpenTrainerSkillsMenu(u8 taskId)
{
    TrainerSkillsMenu_Open();
    DestroyTask(taskId);
}

static void SkillsMenu_HandleInput(u8 taskId)
{
    s32 selection = ListMenu_ProcessInput(gTasks[taskId].data[0]);
    u16 arrayId = 0;
    u8 skill;

    ListMenuGetCurrentItemArrayId(gTasks[taskId].data[0], &arrayId);
    skill = (u8)arrayId;

    if (JOY_NEW(DPAD_RIGHT) || selection != LIST_NOTHING_CHOSEN)
    {
        if (selection == LIST_CANCEL)
        {
            SkillsMenu_Destroy(taskId);
            return;
        }
        if (skill < NUM_TRAINER_SKILLS)
        {
            if (TryRaiseTrainerSkill(skill))
                PlaySE(SE_SELECT);
            else
                PlaySE(SE_FAILURE);

            SkillsMenu_RedrawHeader(gTasks[taskId].data[2]);
        }
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (skill < NUM_TRAINER_SKILLS)
        {
            if (TryLowerTrainerSkill(skill))
                PlaySE(SE_SELECT);
            else
                PlaySE(SE_FAILURE);

            SkillsMenu_RedrawHeader(gTasks[taskId].data[2]);
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        SkillsMenu_Destroy(taskId);
    }
}

static void SkillsMenu_Destroy(u8 taskId)
{
    DestroyListMenuTask(gTasks[taskId].data[0], NULL, NULL);
    ClearStdWindowAndFrame(gTasks[taskId].data[1], TRUE);
    RemoveWindow(gTasks[taskId].data[1]);
    ClearStdWindowAndFrame(gTasks[taskId].data[2], TRUE);
    RemoveWindow(gTasks[taskId].data[2]);
    DestroyTask(taskId);
    // Skill changes retune every Pokemon's IVs, so recompute the party.
    {
        u8 i;

        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) != SPECIES_NONE)
                CalculateMonStats(&gPlayerParty[i]);
        }
    }
    ScriptContext2_Disable();
}
