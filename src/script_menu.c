#include "global.h"
#include "main.h"
#include "character_mode.h"
#include "event_data.h"
#include "field_control_avatar.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "item.h"
#include "malloc.h"
#include "menu.h"
#include "palette.h"
#include "script.h"
#include "script_menu.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "list_menu.h"
#include "constants/event_objects.h"
#include "constants/field_specials.h"
#include "constants/items.h"
#include "constants/script_menu.h"
#include "constants/songs.h"
#include "constants/vars.h"
#include "data/script_menu.h"
#include "trainer_skills.h"

static EWRAM_DATA u8 sProcessInputDelay = 0;

static u8 sLilycoveSSTidalSelections[SSTIDAL_SELECTION_COUNT];

static void Task_HandleMultichoiceInput(u8 taskId);
static void Task_HandleYesNoInput(u8 taskId);
static void Task_HandleMultichoiceGridInput(u8 taskId);
static void DrawMultichoiceMenu(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 cursorPos);
static void InitMultichoiceCheckWrap(bool8 ignoreBPress, u8 count, u8 windowId, u8 multichoiceId);
static void DrawLinkServicesMultichoiceMenu(u8 multichoiceId);
static void CreatePCMultichoice(void);
static void CreateLilycoveSSTidalMultichoice(void);
static bool8 IsPicboxClosed(void);
static void CreateStartMenuForPokenavTutorial(void);
static void InitMultichoiceNoWrap(bool8 ignoreBPress, u8 unusedCount, u8 windowId, u8 multichoiceId);

bool8 ScriptMenu_Multichoice(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DrawMultichoiceMenu(left, top, multichoiceId, ignoreBPress, 0);
        return TRUE;
    }
}

bool8 ScriptMenu_MultichoiceWithDefault(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 defaultChoice)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DrawMultichoiceMenu(left, top, multichoiceId, ignoreBPress, defaultChoice);
        return TRUE;
    }
}

// Unused
static u16 GetLengthWithExpandedPlayerName(const u8 *str)
{
    u16 length = 0;

    while (*str != EOS)
    {
        if (*str == PLACEHOLDER_BEGIN)
        {
            str++;
            if (*str == PLACEHOLDER_ID_PLAYER)
            {
                length += StringLength(gSaveBlock2Ptr->playerName);
                str++;
            }
        }
        else
        {
            str++;
            length++;
        }
    }

    return length;
}

static void DrawMultichoiceMenuCustom(u8 left, u8 top, u8 multichoiceId, u8 ignoreBPress, u8 cursorPos, const struct MenuAction *actions, int count)
{
    int i;
    u8 windowId;
    int width = 0;
    u8 newWidth;

    for (i = 0; i < count; i++)
    {
        width = DisplayTextAndGetWidth(actions[i].text, width);
    }

    newWidth = ConvertPixelWidthToTileWidth(width);
    left = ScriptMenu_AdjustLeftCoordFromWidth(left, newWidth);
    windowId = CreateWindowFromRect(left, top, newWidth, count * 2);
    SetStandardWindowBorderStyle(windowId, 0);
    PrintMenuTable(windowId, count, actions);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, count, cursorPos);
    ScheduleBgCopyTilemapToVram(0);
    InitMultichoiceCheckWrap(ignoreBPress, count, windowId, multichoiceId);
}

static void DrawMultichoiceMenu(u8 left, u8 top, u8 multichoiceId, u8 ignoreBPress, u8 cursorPos)
{
    DrawMultichoiceMenuCustom(left, top, multichoiceId, ignoreBPress, cursorPos, sMultichoiceLists[multichoiceId].list, sMultichoiceLists[multichoiceId].count);
}

void TryDrawRepelMenu(void)
{
    static const u16 repelItems[] = {ITEM_REPEL, ITEM_SUPER_REPEL, ITEM_MAX_REPEL};
    struct MenuAction menuItems[4] = {NULL};
    int i, count = 0;

    for (i = 0; i < ARRAY_COUNT(repelItems); i++)
    {
        if (CheckBagHasItem(repelItems[i], 1))
        {
            VarSet(VAR_0x8004 + count, repelItems[i]);
            menuItems[count].text = ItemId_GetName(repelItems[i]);
            count++;
        }
    }

    if (count > 1)
        DrawMultichoiceMenuCustom(0, 0, 0, FALSE, 0, menuItems, count);

    gSpecialVar_Result = (count > 1);
}

void HandleRepelMenuChoice(void)
{
    gSpecialVar_0x8004 = VarGet(VAR_0x8004 + gSpecialVar_Result); // Get item Id;
    VarSet(VAR_REPEL_STEP_COUNT, ApplySkillStayAway(ItemId_GetHoldEffectParam(gSpecialVar_0x8004)));
}

void TryDrawLureMenu(void)
{
    static const u16 lureItems[] = {ITEM_LURE, ITEM_SUPER_LURE, ITEM_MAX_LURE};
    struct MenuAction menuItems[4] = {NULL};
    int i, count = 0;

    for (i = 0; i < ARRAY_COUNT(lureItems); i++)
    {
        if (CheckBagHasItem(lureItems[i], 1))
        {
            VarSet(VAR_0x8004 + count, lureItems[i]);
            menuItems[count].text = ItemId_GetName(lureItems[i]);
            count++;
        }
    }

    if (count > 1)
        DrawMultichoiceMenuCustom(0, 0, 0, FALSE, 0, menuItems, count);

    gSpecialVar_Result = (count > 1);
}

void HandleLureMenuChoice(void)
{
    gSpecialVar_0x8004 = VarGet(VAR_0x8004 + gSpecialVar_Result); // Get item Id;
    VarSet(VAR_LURE_STEP_COUNT, ItemId_GetHoldEffectParam(gSpecialVar_0x8004));
}

#define tLeft           data[0]
#define tTop            data[1]
#define tRight          data[2]
#define tBottom         data[3]
#define tIgnoreBPress   data[4]
#define tDoWrap         data[5]
#define tWindowId       data[6]
#define tMultichoiceId  data[7]

static void InitMultichoiceCheckWrap(bool8 ignoreBPress, u8 count, u8 windowId, u8 multichoiceId)
{
    u8 i;
    u8 taskId;
    sProcessInputDelay = 2;

    for (i = 0; i < ARRAY_COUNT(sLinkServicesMultichoiceIds); i++)
    {
        if (sLinkServicesMultichoiceIds[i] == multichoiceId)
        {
            sProcessInputDelay = 12;
        }
    }

    taskId = CreateTask(Task_HandleMultichoiceInput, 80);

    gTasks[taskId].tIgnoreBPress = ignoreBPress;

    if (count > 3)
        gTasks[taskId].tDoWrap = TRUE;
    else
        gTasks[taskId].tDoWrap = FALSE;

    gTasks[taskId].tWindowId = windowId;
    gTasks[taskId].tMultichoiceId = multichoiceId;

    DrawLinkServicesMultichoiceMenu(multichoiceId);
}

static void Task_HandleMultichoiceInput(u8 taskId)
{
    s8 selection;
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        if (sProcessInputDelay)
        {
            sProcessInputDelay--;
        }
        else
        {
            if (!tDoWrap)
                selection = Menu_ProcessInputNoWrap();
            else
                selection = Menu_ProcessInput();

            if (JOY_NEW(DPAD_UP | DPAD_DOWN))
            {
                DrawLinkServicesMultichoiceMenu(tMultichoiceId);
            }

            if (selection != MENU_NOTHING_CHOSEN)
            {
                if (selection == MENU_B_PRESSED)
                {
                    if (tIgnoreBPress)
                        return;
                    PlaySE(SE_SELECT);
                    gSpecialVar_Result = MULTI_B_PRESSED;
                }
                else
                {
                    gSpecialVar_Result = selection;
                }
                ClearToTransparentAndRemoveWindow(tWindowId);
                DestroyTask(taskId);
                EnableBothScriptContexts();
            }
        }
    }
}

bool8 ScriptMenu_YesNo(u8 left, u8 top)
{
    u8 taskId;

    if (FuncIsActiveTask(Task_HandleYesNoInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DisplayYesNoMenuDefaultYes();
        taskId = CreateTask(Task_HandleYesNoInput, 0x50);
        return TRUE;
    }
}

// Unused
bool8 IsScriptActive(void)
{
    if (gSpecialVar_Result == 0xFF)
        return FALSE;
    else
        return TRUE;
}

static void Task_HandleYesNoInput(u8 taskId)
{
    if (gTasks[taskId].tRight < 5)
    {
        gTasks[taskId].tRight++;
        return;
    }

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case MENU_NOTHING_CHOSEN:
        return;
    case MENU_B_PRESSED:
    case 1:
        PlaySE(SE_SELECT);
        gSpecialVar_Result = 0;
        break;
    case 0:
        gSpecialVar_Result = 1;
        break;
    }

    DestroyTask(taskId);
    EnableBothScriptContexts();
}

bool8 ScriptMenu_MultichoiceGrid(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 columnCount)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceGridInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        u8 taskId;
        u8 rowCount, newWidth;
        int i, width;

        gSpecialVar_Result = 0xFF;
        width = 0;

        for (i = 0; i < sMultichoiceLists[multichoiceId].count; i++)
        {
            width = DisplayTextAndGetWidth(sMultichoiceLists[multichoiceId].list[i].text, width);
        }

        newWidth = ConvertPixelWidthToTileWidth(width);

        left = ScriptMenu_AdjustLeftCoordFromWidth(left, columnCount * newWidth);
        rowCount = sMultichoiceLists[multichoiceId].count / columnCount;

        taskId = CreateTask(Task_HandleMultichoiceGridInput, 80);

        gTasks[taskId].tIgnoreBPress = ignoreBPress;
        gTasks[taskId].tWindowId = CreateWindowFromRect(left, top, columnCount * newWidth, rowCount * 2);
        SetStandardWindowBorderStyle(gTasks[taskId].tWindowId, 0);
        PrintMenuGridTable(gTasks[taskId].tWindowId, newWidth * 8, columnCount, rowCount, sMultichoiceLists[multichoiceId].list);
        sub_8199944(gTasks[taskId].tWindowId, newWidth * 8, columnCount, rowCount, 0);
        CopyWindowToVram(gTasks[taskId].tWindowId, 3);
        return TRUE;
    }
}

static void Task_HandleMultichoiceGridInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s8 selection = Menu_ProcessInputGridLayout();

    switch (selection)
    {
    case MENU_NOTHING_CHOSEN:
        return;
    case MENU_B_PRESSED:
        if (tIgnoreBPress)
            return;
        PlaySE(SE_SELECT);
        gSpecialVar_Result = MULTI_B_PRESSED;
        break;
    default:
        gSpecialVar_Result = selection;
        break;
    }

    ClearToTransparentAndRemoveWindow(tWindowId);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

#undef tWindowId

bool16 ScriptMenu_CreatePCMultichoice(void)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        CreatePCMultichoice();
        return TRUE;
    }
}

static void CreatePCMultichoice(void)
{
    u8 y = 8;
    u32 pixelWidth = 0;
    u8 width;
    u8 numChoices;
    u8 windowId;
    int i;

    for (i = 0; i < ARRAY_COUNT(sPCNameStrings); i++)
    {
        pixelWidth = DisplayTextAndGetWidth(sPCNameStrings[i], pixelWidth);
    }

    if (FlagGet(FLAG_SYS_GAME_CLEAR))
    {
        pixelWidth = DisplayTextAndGetWidth(gText_HallOfFame, pixelWidth);
    }

    width = ConvertPixelWidthToTileWidth(pixelWidth);

    // Include Hall of Fame option if player is champion
    if (FlagGet(FLAG_SYS_GAME_CLEAR))
    {
        numChoices = 4;
        windowId = CreateWindowFromRect(0, 0, width, 8);
        SetStandardWindowBorderStyle(windowId, 0);
        AddTextPrinterParameterized(windowId, 1, gText_HallOfFame, y, 33, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(windowId, 1, gText_LogOff, y, 49, TEXT_SPEED_FF, NULL);
    }
    else
    {
        numChoices = 3;
        windowId = CreateWindowFromRect(0, 0, width, 6);
        SetStandardWindowBorderStyle(windowId, 0);
        AddTextPrinterParameterized(windowId, 1, gText_LogOff, y, 33, TEXT_SPEED_FF, NULL);
    }

    // Change PC name if player has met Lanette
    if (FlagGet(FLAG_SYS_PC_LANETTE))
        AddTextPrinterParameterized(windowId, 1, gText_LanettesPC, y, 1, TEXT_SPEED_FF, NULL);
    else
        AddTextPrinterParameterized(windowId, 1, gText_SomeonesPC, y, 1, TEXT_SPEED_FF, NULL);

    StringExpandPlaceholders(gStringVar4, gText_PlayersPC);
    PrintPlayerNameOnWindow(windowId, gStringVar4, y, 17);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, numChoices, 0);
    CopyWindowToVram(windowId, 3);
    InitMultichoiceCheckWrap(FALSE, numChoices, windowId, MULTI_PC);
}

void ScriptMenu_DisplayPCStartupPrompt(void)
{
    sub_819786C(0, TRUE);
    AddTextPrinterParameterized2(0, 1, gText_WhichPCShouldBeAccessed, 0, NULL, 2, 1, 3);
}

bool8 ScriptMenu_CreateLilycoveSSTidalMultichoice(void)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        CreateLilycoveSSTidalMultichoice();
        return TRUE;
    }
}

// gSpecialVar_0x8004 is 1 if the Sailor was shown multiple event tickets at the same time
// otherwise gSpecialVar_0x8004 is 0
static void CreateLilycoveSSTidalMultichoice(void)
{
    u8 selectionCount = 0;
    u8 count;
    u32 pixelWidth;
    u8 width;
    u8 windowId;
    u8 i;
    u32 j;

    for (i = 0; i < SSTIDAL_SELECTION_COUNT; i++)
    {
        sLilycoveSSTidalSelections[i] = 0xFF;
    }

    GetFontAttribute(1, FONTATTR_MAX_LETTER_WIDTH);

    if (gSpecialVar_0x8004 == 0)
    {
        sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_SLATEPORT;
        selectionCount++;

        if (FlagGet(FLAG_MET_SCOTT_ON_SS_TIDAL) == TRUE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_BATTLE_FRONTIER;
            selectionCount++;
        }
    }

    if (FlagGet(FLAG_SYS_FRONTIER_PASS) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_SOUTHERN_ISLAND;
            selectionCount++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_SHOWN_EON_TICKET) == FALSE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_SOUTHERN_ISLAND;
            selectionCount++;
            FlagSet(FLAG_SHOWN_EON_TICKET);
        }
    }

    if (FlagGet(FLAG_SYS_FRONTIER_PASS) == TRUE && FLAG_DEFEATED_RAYQUAZA)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_NAVEL_ROCK;
            selectionCount++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_SHOWN_MYSTIC_TICKET) == FALSE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_NAVEL_ROCK;
            selectionCount++;
            FlagSet(FLAG_SHOWN_MYSTIC_TICKET);
        }
    }

    if (FlagGet(FLAG_SYS_FRONTIER_PASS) == TRUE && FLAG_DEFEATED_RAYQUAZA)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_BIRTH_ISLAND;
            selectionCount++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_SHOWN_AURORA_TICKET) == FALSE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_BIRTH_ISLAND;
            selectionCount++;
            FlagSet(FLAG_SHOWN_AURORA_TICKET);
        }
    }

    if (FlagGet(FLAG_SYS_FRONTIER_PASS) == TRUE && FLAG_DEFEATED_RAYQUAZA)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_FARAWAY_ISLAND;
            selectionCount++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_SHOWN_OLD_SEA_MAP) == FALSE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_FARAWAY_ISLAND;
            selectionCount++;
            FlagSet(FLAG_SHOWN_OLD_SEA_MAP);
        }
    }

    sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_EXIT;
    selectionCount++;

    if (gSpecialVar_0x8004 == 0 && FlagGet(FLAG_MET_SCOTT_ON_SS_TIDAL) == TRUE)
    {
        count = selectionCount;
    }

    count = selectionCount;
    if (count == SSTIDAL_SELECTION_COUNT)
    {
        gSpecialVar_0x8004 = SCROLL_MULTI_SS_TIDAL_DESTINATION;
        ShowScrollableMultichoice();
    }
    else
    {
        pixelWidth = 0;

        for (j = 0; j < SSTIDAL_SELECTION_COUNT; j++)
        {
            u8 selection = sLilycoveSSTidalSelections[j];
            if (selection != 0xFF)
            {
                pixelWidth = DisplayTextAndGetWidth(sLilycoveSSTidalDestinations[selection], pixelWidth);
            }
        }

        width = ConvertPixelWidthToTileWidth(pixelWidth);
        windowId = CreateWindowFromRect(MAX_MULTICHOICE_WIDTH - width, (6 - count) * 2, width, count * 2);
        SetStandardWindowBorderStyle(windowId, 0);

        for (selectionCount = 0, i = 0; i < SSTIDAL_SELECTION_COUNT; i++)
        {
            if (sLilycoveSSTidalSelections[i] != 0xFF)
            {
                AddTextPrinterParameterized(windowId, 1, sLilycoveSSTidalDestinations[sLilycoveSSTidalSelections[i]], 8, selectionCount * 16 + 1, TEXT_SPEED_FF, NULL);
                selectionCount++;
            }
        }

        InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, count, count - 1);
        CopyWindowToVram(windowId, 3);
        InitMultichoiceCheckWrap(FALSE, count, windowId, MULTI_SSTIDAL_LILYCOVE);
    }
}

void GetLilycoveSSTidalSelection(void)
{
    if (gSpecialVar_Result != MULTI_B_PRESSED)
    {
        gSpecialVar_Result = sLilycoveSSTidalSelections[gSpecialVar_Result];
    }
}

#define tState       data[0]
#define tMonSpecies  data[1]
#define tMonSpriteId data[2]
#define tWindowX     data[3]
#define tWindowY     data[4]
#define tWindowId    data[5]

static void Task_PokemonPicWindow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->tState++;
        break;
    case 1:
        break;
    case 2:
        FreeResourcesAndDestroySprite(&gSprites[task->tMonSpriteId], task->tMonSpriteId);
        task->tState++;
        break;
    case 3:
        ClearToTransparentAndRemoveWindow(task->tWindowId);
        DestroyTask(taskId);
        break;
    }
}

bool8 ScriptMenu_ShowPokemonPic(u16 species, u8 x, u8 y, bool8 isShiny)
{
    u8 taskId;
    u8 spriteId;

    if (FindTaskIdByFunc(Task_PokemonPicWindow) != 0xFF)
    {
        return FALSE;
    }
    else
    {
        spriteId = CreateMonSprite_PicBox(species, x * 8 + 40, y * 8 + 40, 0, isShiny);
        taskId = CreateTask(Task_PokemonPicWindow, 0x50);
        gTasks[taskId].tWindowId = CreateWindowFromRect(x, y, 8, 8);
        gTasks[taskId].tState = 0;
        gTasks[taskId].tMonSpecies = species;
        gTasks[taskId].tMonSpriteId = spriteId;
        gSprites[spriteId].callback = SpriteCallbackDummy;
        gSprites[spriteId].oam.priority = 0;
        SetStandardWindowBorderStyle(gTasks[taskId].tWindowId, 1);
        ScheduleBgCopyTilemapToVram(0);
        return TRUE;
    }
}

bool8 (*ScriptMenu_GetPicboxWaitFunc(void))(void)
{
    u8 taskId = FindTaskIdByFunc(Task_PokemonPicWindow);

    if (taskId == 0xFF)
        return NULL;
    gTasks[taskId].tState++;
    return IsPicboxClosed;
}

static bool8 IsPicboxClosed(void)
{
    if (FindTaskIdByFunc(Task_PokemonPicWindow) == 0xFF)
        return TRUE;
    else
        return FALSE;
}

#undef tState
#undef tMonSpecies
#undef tMonSpriteId
#undef tWindowX
#undef tWindowY
#undef tWindowId

u8 CreateWindowFromRect(u8 x, u8 y, u8 width, u8 height)
{
    struct WindowTemplate template = CreateWindowTemplate(0, x + 1, y + 1, width, height, 15, 100);
    u8 windowId = AddWindow(&template);
    PutWindowTilemap(windowId);
    return windowId;
}

void ClearToTransparentAndRemoveWindow(u8 windowId)
{
    ClearStdWindowAndFrameToTransparent(windowId, TRUE);
    RemoveWindow(windowId);
}

static void DrawLinkServicesMultichoiceMenu(u8 multichoiceId)
{
    switch (multichoiceId)
    {
    case MULTI_WIRELESS_NO_BERRY:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, sWirelessOptionsNoBerryCrush[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case MULTI_CABLE_CLUB_WITH_RECORD_MIX:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, sCableClubOptions_WithRecordMix[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case MULTI_WIRELESS_NO_RECORD:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, sWirelessOptions_NoRecordMix[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case MULTI_WIRELESS_ALL_SERVICES:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, sWirelessOptions_AllServices[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case MULTI_WIRELESS_NO_RECORD_BERRY:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, sWirelessOptions_NoRecordMixBerryCrush[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    case MULTI_CABLE_CLUB_NO_RECORD_MIX:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, sCableClubOptions_NoRecordMix[Menu_GetCursorPos()], 0, NULL, 2, 1, 3);
        break;
    }
}

bool16 ScriptMenu_CreateStartMenuForPokenavTutorial(void)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        CreateStartMenuForPokenavTutorial();
        return TRUE;
    }
}

static void CreateStartMenuForPokenavTutorial(void)
{
    u8 windowId = CreateWindowFromRect(21, 0, 7, 18);
    SetStandardWindowBorderStyle(windowId, 0);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionPokedex, 8, 9, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionPokemon, 8, 25, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionBag, 8, 41, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionPokenav, 8, 57, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gSaveBlock2Ptr->playerName, 8, 73, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionSave, 8, 89, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionOption, 8, 105, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(windowId, 1, gText_MenuOptionExit, 8, 121, TEXT_SPEED_FF, NULL);
    Menu_InitCursor(windowId, 1, 0, 9, 16, ARRAY_COUNT(MultichoiceList_ForcedStartMenu), 0);
    InitMultichoiceNoWrap(FALSE, ARRAY_COUNT(MultichoiceList_ForcedStartMenu), windowId, MULTI_FORCED_START_MENU);
    CopyWindowToVram(windowId, 3);
}

#define tWindowId       data[6]

static void InitMultichoiceNoWrap(bool8 ignoreBPress, u8 unusedCount, u8 windowId, u8 multichoiceId)
{
    u8 taskId;
    sProcessInputDelay = 2;
    taskId = CreateTask(Task_HandleMultichoiceInput, 80);
    gTasks[taskId].tIgnoreBPress = ignoreBPress;
    gTasks[taskId].tDoWrap = 0;
    gTasks[taskId].tWindowId = windowId;
    gTasks[taskId].tMultichoiceId = multichoiceId;
}

#undef tLeft
#undef tTop
#undef tRight
#undef tBottom
#undef tIgnoreBPress
#undef tDoWrap
#undef tWindowId
#undef tMultichoiceId

static int DisplayTextAndGetWidthInternal(const u8 *str)
{
    u8 temp[64];
    StringExpandPlaceholders(temp, str);
    return GetStringWidth(1, temp, 0);
}

int DisplayTextAndGetWidth(const u8 *str, int prevWidth)
{
    int width = DisplayTextAndGetWidthInternal(str);
    if (width < prevWidth)
    {
        width = prevWidth;
    }
    return width;
}

int ConvertPixelWidthToTileWidth(int width)
{
    return (((width + 9) / 8) + 1) > MAX_MULTICHOICE_WIDTH ? MAX_MULTICHOICE_WIDTH : (((width + 9) / 8) + 1);
}

int ScriptMenu_AdjustLeftCoordFromWidth(int left, int width)
{
    int adjustedLeft = left;

    if (left + width > MAX_MULTICHOICE_WIDTH)
    {
        if (MAX_MULTICHOICE_WIDTH - width < 0)
        {
            adjustedLeft = 0;
        }
        else
        {
            adjustedLeft = MAX_MULTICHOICE_WIDTH - width;
        }
    }

    return adjustedLeft;
}

//
// Text displayed as options.
static const u8 sText_Surprise[] = _("Surprise Me");

static const u8 gText_City_01[] = _("Littleroot Town");
static const u8 gText_City_02[] = _("Oldale Town");
static const u8 gText_City_03[] = _("Petalburg City");
static const u8 gText_City_04[] = _("Rustboro City");
static const u8 gText_City_05[] = _("Dewford Town");
static const u8 gText_City_06[] = _("Slateport City");
static const u8 gText_City_07[] = _("Mauville City");
static const u8 gText_City_08[] = _("Verdanturf Town");
static const u8 gText_City_09[] = _("Fallarbor Town");
static const u8 gText_City_10[] = _("Lavaridge Town");
static const u8 gText_City_11[] = _("Fortree City");
static const u8 gText_City_12[] = _("Lilycove City");
static const u8 gText_City_13[] = _("Mossdeep City");
static const u8 gText_City_14[] = _("Sootopolis City");
static const u8 gText_City_15[] = _("Pacifidlog Town");

static const u8 gText_Island_01[] = _("One Island");
static const u8 gText_Island_02[] = _("Two Island");
static const u8 gText_Island_03[] = _("Three Island");
static const u8 gText_Island_04[] = _("Four Island");
static const u8 gText_Island_05[] = _("Five Island");
static const u8 gText_Island_06[] = _("Six Island");
static const u8 gText_Island_07[] = _("Seven Island");
static const u8 gText_Island_08[] = _("Eight Island");
static const u8 gText_City_16[] = _("Ever Grande City");
static const u8 gText_City_17[] = _("Battle Frontier");

static const u8 sText_Fossil_1[] = _("Dome Fossil");
static const u8 sText_Fossil_2[] = _("Helix Fossil");
static const u8 sText_Fossil_3[] = _("Old Amber");
static const u8 sText_Fossil_4[] = _("Root Fossil");
static const u8 sText_Fossil_5[] = _("Claw Fossil");
static const u8 sText_Fossil_6[] = _("Skull Fossil");
static const u8 sText_Fossil_7[] = _("Armor Fossil");
static const u8 sText_Fossil_8[] = _("Cover Fossil");
static const u8 sText_Fossil_9[] = _("Plume Fossil");
static const u8 sText_Fossil_10[] = _("Jaw Fossil");
static const u8 sText_Fossil_11[] = _("Sail Fossil");
// 2.X's Devon script also revives the four Galar fossil combos (cases 11-14). Our list
// stopped at 10, so those four were simply unreachable. They are keyed by the revived
// mon, not a single fossil, because each needs two Fossilized items.
static const u8 sText_Fossil_12[] = _("Dracozolt");
static const u8 sText_Fossil_13[] = _("Dracovish");
static const u8 sText_Fossil_14[] = _("Arctozolt");
static const u8 sText_Fossil_15[] = _("Arctovish");

// Sets of multichoices.

//City Selection
static const struct ListMenuItem sSet0[] =
{
    {gText_City_01, 0},
    {gText_City_02, 1},
    {gText_City_03, 2},
    {gText_City_04, 3},
    {gText_City_05, 4},
    {gText_City_06, 5},
    {gText_City_07, 6},
    {gText_City_08, 7},
    {gText_City_09, 8},
	{gText_City_10, 9},
    {gText_City_11, 10},
    {gText_City_12, 11},
    {gText_City_13, 12},
    {gText_City_14, 13},
    {gText_City_15, 14},
    {sText_Surprise, 15},
    // 2.X Sevii. Appended after "Surprise Me" so the existing indices (which the
    // case labels in InsideOfTruck/scripts.inc key off) do not move.
    {gText_Island_01, 16},
    {gText_Island_02, 17},
    {gText_Island_03, 18},
    {gText_Island_04, 19},
    {gText_Island_05, 20},
    {gText_Island_06, 21},
    {gText_Island_07, 22},
    {gText_Island_08, 23},
};

//Starter Selection -------------------------------------------------------------------------
static const u8 sText_Starter_1[] = _("Meowth");
static const u8 sText_Starter_2[] = _("Slugma");
static const u8 sText_Starter_3[] = _("Barboach");
static const u8 sText_Starter_4[] = _("Kricketot");
static const u8 sText_Starter_5[] = _("Cubchoo");
static const u8 sText_Starter_6[] = _("Skiddo");
static const u8 sText_Starter_7[] = _("Sandygast");
static const u8 sText_Starter_8[] = _("Cufant");
static const u8 sText_Starter_9[] = _("Smeargle");


static const struct ListMenuItem sSet1[] =
{
    {sText_Starter_1, 0},
    {sText_Starter_2, 1},
    {sText_Starter_3, 2},
    {sText_Starter_4, 3},
    {sText_Starter_5, 4},
    {sText_Starter_6, 5},
    {sText_Starter_7, 6},
    {sText_Starter_8, 7},
    {sText_Starter_9, 8},
	{sText_Surprise, 9},
};

//----------------------------------------------------------------------------------------

static const u8 gText_Lilycove[]   		= _("Lilycove");
static const u8 gText_Slateport[]  		= _("Slateport");
static const u8 gText_OneIsland[]  		= _("One Island");
static const u8 gText_TwoIsland[]  		= _("Two Island");
static const u8 gText_ThreeIsland[]  	= _("Three Island");
static const u8 gText_FourIsland[]  	= _("Four Island");
static const u8 gText_FiveIsland[]  	= _("Five Island");
static const u8 gText_SixIsland[]  		= _("Six Island");
static const u8 gText_SevenIsland[]  	= _("Seven Island");
static const u8 gText_EightIsland[]  	= _("Eight Island");
static const u8 gText_BattleFrontier[]  = _("Battle Frontier");
static const u8 gText_SouthernIsland[]  = _("Southern Island");
static const u8 gText_NavelRock[]  		= _("Navel Rock");
static const u8 gText_BirthIsland[]  	= _("Birth Island");
static const u8 gText_FarawayIsland[]  	= _("Faraway Island");
static const u8 gText_Cancel2 []  		= _("Cancel");

// THE FERRY LISTS BELOW ARE INDEX-CRITICAL.
// flying_taxi.pory's Common_Evenscript_WarpUsingFerry switches on VAR_RESULT *directly*
// as a SAIL_TO_* value, so item N here IS destination N. They must read:
//   0 = the other mainland harbour, 1..8 = Sevii 1..8, 9 = Battle Frontier,
//   10 = Navel Rock, 11 = Birth Island, 12 = Faraway Island, 13 = Southern Island.
// The pre-league lists stop at 8 and put Cancel at 9, because the script rejects
// anything >= SAIL_TO_BATTLE_FRONTIER (9) before the league is cleared.
// These were previously our 1.9.4 lists, which are a different order: "Battle Frontier"
// sat at 5 (= SAIL_TO_SEVII_5) and Cancel at 10 (= SAIL_TO_NAVEL_ROCK), so picking
// Cancel sailed you to Navel Rock. Do not reorder without changing the script.
// Slateport's list offers Lilycove and vice versa -- the script sets/clears
// FLAG_SAILED_FROM_SLATEPORT to decide which way destination 0 goes.

// SCROLLING_SLATEPORT_HARBOR_* is the list shown AT Slateport, so destination 0 is Lilycove.
static const struct ListMenuItem sSet2[] =   // Slateport Harbor, pre-league
{
    {gText_Lilycove,        0},   // SAIL_TO_SLATEPORT/LILYCOVE
    {gText_OneIsland,       1},
    {gText_TwoIsland,       2},
    {gText_ThreeIsland,     3},
    {gText_FourIsland,      4},
    {gText_FiveIsland,      5},
    {gText_SixIsland,       6},
    {gText_SevenIsland,     7},
    {gText_EightIsland,     8},
    {gText_Cancel2,         9},   // >= SAIL_TO_BATTLE_FRONTIER -> the script exits
};

static const struct ListMenuItem sSet3[] =   // Slateport Harbor, post-league
{
    {gText_Lilycove,        0},
    {gText_OneIsland,       1},
    {gText_TwoIsland,       2},
    {gText_ThreeIsland,     3},
    {gText_FourIsland,      4},
    {gText_FiveIsland,      5},
    {gText_SixIsland,       6},
    {gText_SevenIsland,     7},
    {gText_EightIsland,     8},
    {gText_BattleFrontier,  9},
    {gText_NavelRock,      10},
    {gText_BirthIsland,    11},
    {gText_FarawayIsland,  12},
    {gText_SouthernIsland, 13},
    {gText_Cancel2,        14},   // no SAIL_TO_ case -> the script's default exits
};

// SCROLLING_LILYCOVE_HARBOR_* is the list shown AT Lilycove, so destination 0 is Slateport.
static const struct ListMenuItem sSet4[] =   // Lilycove Harbor, pre-league
{
    {gText_Slateport,       0},
    {gText_OneIsland,       1},
    {gText_TwoIsland,       2},
    {gText_ThreeIsland,     3},
    {gText_FourIsland,      4},
    {gText_FiveIsland,      5},
    {gText_SixIsland,       6},
    {gText_SevenIsland,     7},
    {gText_EightIsland,     8},
    {gText_Cancel2,         9},
};

static const struct ListMenuItem sSet8[] =   // Lilycove Harbor, post-league
{
    {gText_Slateport,       0},
    {gText_OneIsland,       1},
    {gText_TwoIsland,       2},
    {gText_ThreeIsland,     3},
    {gText_FourIsland,      4},
    {gText_FiveIsland,      5},
    {gText_SixIsland,       6},
    {gText_SevenIsland,     7},
    {gText_EightIsland,     8},
    {gText_BattleFrontier,  9},
    {gText_NavelRock,      10},
    {gText_BirthIsland,    11},
    {gText_FarawayIsland,  12},
    {gText_SouthernIsland, 13},
    {gText_Cancel2,        14},
};

//Devon Corp
static const struct ListMenuItem sSet5[] =
{
    {sText_Fossil_1, 0},
    {sText_Fossil_2, 1},
    {sText_Fossil_3, 2},
    {sText_Fossil_4, 3},
    {sText_Fossil_5, 4},
    {sText_Fossil_6, 5},
    {sText_Fossil_7, 6},
    {sText_Fossil_8, 7},
    {sText_Fossil_9, 8},
    {sText_Fossil_10, 9},
    {sText_Fossil_11, 10},
    {sText_Fossil_12, 11},
    {sText_Fossil_13, 12},
    {sText_Fossil_14, 13},
    {sText_Fossil_15, 14},
    {gText_Cancel2,   15},   // no case 15 -> the script's default declines
};

//Mode Selection -------------------------------------------------------------------------

static const u8 sText_Mode_Grindless[] 		     = _("Grindless Mode");
static const u8 sText_Mode_No_Evs[] 		     = _("No Evs Mode");
static const u8 sText_Mode_Last_Gen[] 		     = _("Last Gen Mode");
static const u8 sText_Mode_Monotype[] 		     = _("Monotype Mode");
static const u8 sText_Mode_Gym_Shuffle[] 	     = _("Gym Shuffle Mode");
static const u8 sText_Mode_Randomized[] 	     = _("Randomized Mode");
static const u8 sText_Mode_Double_Battle[] 	     = _("Double Battle Mode");
static const u8 sText_Mode_Little_Cup[] 	     = _("Little Cup Mode");
static const u8 sText_Mode_More_Modes[] 	     = _("More Modes...");
static const u8 sText_Mode_Save[] 			     = _("Save");

static const u8 sText_Mode_Scalemon[] 		     = _("Scalemon Mode");
static const u8 sText_Mode_Inverse[] 		     = _("Inverse Mode");
static const u8 sText_Mode_True_Random[] 	     = _("True Random Mode");
static const u8 sText_Mode_Random_Party[] 	     = _("Random Party Mode");
static const u8 sText_Mode_Random_Type_Mode[]    = _("Random Type Mode");
static const u8 sText_Mode_Random_Ability_Mode[] = _("Random Ability Mode");
static const u8 sText_Mode_Third_Type_Mode[]     = _("Third Type Mode");
static const u8 sText_Mode_Old_STAB_Mode[] 		 = _("Old STAB Mode");
static const u8 sText_Mode_No_Split[] 		     = _("No Split Mode");
static const u8 sText_Mode_No_Mega[] 		     = _("No Mega Mode");
static const u8 sText_Mode_Metronome_Only[]      = _("Metronome Only Mode");
static const u8 sText_Mode_Vanilla[] 		     = _("Vanilla Mode");
static const u8 sText_Mode_No_Custom_Forms[]     = _("No Custom Forms");
static const u8 sText_Mode_No_Signature[] 	     = _("No Signature Mode");
static const u8 sText_Mode_Back[] 			     = _("Back");

// INDEX-CRITICAL: rows here are matched by POSITION against the switch in
// Start_EventScript_Game_Modes (data/maps/InsideOfTruck/scripts.pory). The list
// is ours, the switch is 2.X's, and nothing checks that they agree -- the
// Blue Nurse and the Slateport ferry drifted apart the same way at the rebase.
//
// This one HAD drifted, and every row but two ran the wrong mode: the old list
// was a 17-entry grab-bag against a 9-case switch, so "Perfect Iv Mode" set
// Grindless, "Randomized Mode" set Gym Shuffle, and "Random Party Mode" set
// plain Randomized. Perfect IVs, No Evolution and Leveless are NOT dropped by
// the correction -- the switch never had a case for them and they are set from
// the checkbox panel in ui_mode_menu.c instead.
//
// Row 9 (Save) deliberately has no case: the switch's `default` is Save.
static const struct ListMenuItem sSet6[] =
{
	{sText_Mode_Grindless, 		     0},
    {sText_Mode_No_Evs, 		     1},
	{sText_Mode_Last_Gen, 		     2},
    {sText_Mode_Monotype, 		     3},
    {sText_Mode_Gym_Shuffle, 	     4},
    {sText_Mode_Randomized, 	     5},
    {sText_Mode_Double_Battle, 	     6},
    {sText_Mode_Little_Cup, 	     7},
    {sText_Mode_More_Modes, 	     8},
	{sText_Mode_Save, 			     9},
};

// INDEX-CRITICAL, same contract: matched by position against the switch in
// Start_EventScript_Game_Modes_Other. SCROLLING_OTHER_GAME_MODES was pointed at
// sSet6 as a placeholder and never given a list of its own, so all 14 of these
// rows were reading the game-modes labels. Row 14 (Back) has no case; the
// switch's `default` returns to the main modes menu.
static const struct ListMenuItem sSetOtherGameModes[] =
{
	{sText_Mode_Scalemon, 		     0},
    {sText_Mode_Inverse, 		     1},
	{sText_Mode_True_Random, 	     2},
    {sText_Mode_Random_Party, 	     3},
    {sText_Mode_Random_Type_Mode, 	 4},
    {sText_Mode_Random_Ability_Mode, 5},
    {sText_Mode_Third_Type_Mode, 	 6},
    {sText_Mode_Old_STAB_Mode, 		 7},
    {sText_Mode_No_Split, 		     8},
    {sText_Mode_No_Mega, 		     9},
    {sText_Mode_Metronome_Only, 	 10},
    {sText_Mode_Vanilla, 		     11},
    {sText_Mode_No_Custom_Forms, 	 12},
    {sText_Mode_No_Signature, 		 13},
	{sText_Mode_Back, 			     14},
};

//----------------------------------------------------------------------------------------

static const u8 sText_Mode_Enable[]  		= _("Enable");
static const u8 sText_Mode_Disable[] 		= _("Disable");

//Enable Disable Mode Selection
static const struct ListMenuItem sSet7[] =
{
	{sText_Mode_Enable,  0},
    {sText_Mode_Disable, 1},
};
//----------------------------------------------------------------------------------------

//Blue Nurse -------------------------------------------------------------------------
static const u8 gText_RateANickname[]   	= _("Rate a Nickname");
static const u8 gText_TeachAMove[]  		= _("Teach a Move");
static const u8 gText_ForgetAMove[]  		= _("Forget a Move");
static const u8 gText_TryWondertrading[]  	= _("Try Wonder Trading");
static const u8 gText_ChangeCostume[]  		= _("Change Costume");
static const u8 gText_StartABattle[]  		= _("Start a Mock Battle");
static const u8 gText_Companion_Stuff[]     = _("Companion Stuff");
static const u8 gText_DoubleBattles[]       = _("Double Battles");
static const u8 gText_LowerDifficulty[]     = _("Lower Difficulty");
static const u8 gText_ChangeSeason[]        = _("Change Season");
static const u8 gText_ChangeDate[]          = _("Change Date");

// INDEX-CRITICAL: this must match the switch in data/scripts/pkmn_center_jack.pory,
// which is 2.X's and dispatches in 2.X's order -- NOT the 1.9.4 order this list used to
// be in. While they disagreed every option ran the wrong action (picking "Travel to
// Sevii" ran Change Season) and the Colress ticket chain was unreachable.
// 0-8 are 2.X's; 9-11 are ours, appended, with matching cases added to the script.
static const struct ListMenuItem sSetBlueNurse[] =
{
    {gText_ChangeCostume,       0},
    {gText_StartABattle,        1},
    {gText_RateANickname,       2},
    {gText_TeachAMove,          3},   // opens the move-tutor submenu
    {gText_TryWondertrading,    4},
    {gText_DoubleBattles,       5},
    {gText_LowerDifficulty,     6},
    {gText_ChangeSeason,        7},
    {gText_ChangeDate,          8},
    {gText_TravelToSevii,       9},   // ours: Colress / the Sevii ferry
    {gText_Companion_Stuff,    10},   // ours: kept from 1.9.4, 2.X drops it
    {gText_Cancel2,            11},
};

//------------------------------------------------------------------------------------


// INDEX-CRITICAL: matches Common_EventScript_PkmnCenterJack_Move_Learner's switch.
// The old 3-entry list mapped "Teach a Move" onto the move DELETER and "Forget a Move"
// onto the egg-move tutor. Case 4 has no handler, so it falls to the script's default
// (come back anytime), which is what Cancel wants anyway.
static const u8 gText_EggMoves[]            = _("Egg Moves");
static const u8 gText_TutorMoves[]          = _("Move Tutor");
static const u8 gText_TmMoves[]             = _("TM Moves");

static const struct ListMenuItem sSetBlueNurseMoveLearn[] =
{
    {gText_ForgetAMove,         0},
    {gText_EggMoves,            1},
    {gText_TutorMoves,          2},
    {gText_TmMoves,             3},
    {gText_Cancel2,             4},
};

// ---- Costumes -----------------------------------------------------------------------
// The costume list is BUILT AT RUNTIME (BuildCostumeList) from the four base outfits plus
// every gCharacters[] entry that has an overworld sprite, and it is consumed by
// ApplyCostumeChoice in this same file. That is deliberate: the list and the code that acts
// on the chosen index now live together, so they cannot drift apart the way a C list and a
// .pory switch do. The script just shows the list and calls the special.
//
// It replaces 2.X's two static lists, which offered nine outfits when only four
// (EMERALD/RS/FRLG/BW) have sprite data -- nine of their sixteen entries setvar'd
// VAR_COSTUME_NUMBER to an unrenderable 4..8.
static const u8 gText_CostumeEmerald[]  = _("Emerald");
static const u8 gText_CostumeRS[]       = _("Ruby/Sapphire");
static const u8 gText_CostumeFRLG[]     = _("FireRed/LeafGreen");
static const u8 gText_CostumeBW[]       = _("Black/White");

// Base outfits, indexed BY the costume id so item N is costume N. These are the only four
// with bike/surf/fishing frames, so they stay first in the list and are the way back to a
// complete sprite set after wearing a character.
static const u8 *const sBaseCostumeNames[NUM_COSTUMES] =
{
    [EMERALD_COSTUME] = gText_CostumeEmerald,
    [RS_COSTUME]      = gText_CostumeRS,
    [FRLG_COSTUME]    = gText_CostumeFRLG,
    [BW_COSTUME]      = gText_CostumeBW,
};

// Item ids in the costume list. Characters sit above the base outfits, clear of
// MULTI_B_PRESSED (0x7F), which Task_ScrollingMultichoiceInput returns on a B press.
#define COSTUME_CHOICE_CHARACTER_BASE  1000

// EWRAM_DATA, not a plain static: pokeemerald's linker script discards .data, so a mutable
// initialized global has to be placed explicitly. Six bytes; the list itself is on the heap.
static EWRAM_DATA struct ListMenuItem *sCostumeItems = NULL;   // freed with the menu task
static EWRAM_DATA u16 sCostumeItemCount = 0;

static const struct ListMenuItem sSetSeviiTicket[] =
{
    {gText_SeviiOneIsland,      0},
    {gText_SeviiTwoIsland,      1},
    {gText_SeviiThreeIsland,    2},
    {gText_SeviiFourIsland,     3},
    {gText_SeviiFiveIsland,     4},
    {gText_SeviiSixIsland,      5},
    {gText_SeviiSevenIsland,    6},
    {gText_SeviiEightIsland,    7},
};

// Table of your multichoice sets.
// ---- 2.X sets referenced by the rebased map scripts ----
static const u8 sText_Gen_1[] = _("Kanto");
static const u8 sText_Gen_2[] = _("Johto");
static const u8 sText_Gen_3[] = _("Hoenn");
static const u8 sText_Gen_4[] = _("Sinnoh");
static const u8 sText_Gen_5[] = _("Unova");
static const u8 sText_Gen_6[] = _("Kalos");
static const u8 sText_Gen_7[] = _("Alola");
static const u8 sText_Gen_8[] = _("Galar");
static const u8 sText_Gen_9[] = _("Paldea");

static const struct ListMenuItem sSetGenerations[] =
{
    {sText_Gen_1, 0}, {sText_Gen_2, 1}, {sText_Gen_3, 2},
    {sText_Gen_4, 3}, {sText_Gen_5, 4}, {sText_Gen_6, 5},
    {sText_Gen_7, 6}, {sText_Gen_8, 7}, {sText_Gen_9, 8},
};

static const u8 sText_Type_Normal[] = _("Normal");
static const u8 sText_Type_Fighting[] = _("Fighting");
static const u8 sText_Type_Flying[] = _("Flying");
static const u8 sText_Type_Poison[] = _("Poison");
static const u8 sText_Type_Ground[] = _("Ground");
static const u8 sText_Type_Rock[] = _("Rock");
static const u8 sText_Type_Bug[] = _("Bug");
static const u8 sText_Type_Ghost[] = _("Ghost");
static const u8 sText_Type_Steel[] = _("Steel");
static const u8 sText_Type_Fire[] = _("Fire");
static const u8 sText_Type_Water[] = _("Water");
static const u8 sText_Type_Grass[] = _("Grass");
static const u8 sText_Type_Electric[] = _("Electric");
static const u8 sText_Type_Psychic[] = _("Psychic");
static const u8 sText_Type_Ice[] = _("Ice");
static const u8 sText_Type_Dragon[] = _("Dragon");
static const u8 sText_Type_Dark[] = _("Dark");
static const u8 sText_Type_Fairy[] = _("Fairy");

static const struct ListMenuItem sSetTypes[] =
{
    {sText_Type_Normal, 0},  {sText_Type_Fighting, 1}, {sText_Type_Flying, 2},
    {sText_Type_Poison, 3},  {sText_Type_Ground, 4},   {sText_Type_Rock, 5},
    {sText_Type_Bug, 6},     {sText_Type_Ghost, 7},    {sText_Type_Steel, 8},
    {sText_Type_Fire, 9},    {sText_Type_Water, 10},   {sText_Type_Grass, 11},
    {sText_Type_Electric, 12},{sText_Type_Psychic, 13},{sText_Type_Ice, 14},
    {sText_Type_Dragon, 15}, {sText_Type_Dark, 16},    {sText_Type_Fairy, 17},
};

static const u8 sText_Season_Spring[] = _("Spring");
static const u8 sText_Season_Summer[] = _("Summer");
static const u8 sText_Season_Autumn[] = _("Autumn");
static const u8 sText_Season_Winter[] = _("Winter");

static const struct ListMenuItem sSetSeasons[] =
{
    {sText_Season_Spring, 0}, {sText_Season_Summer, 1},
    {sText_Season_Autumn, 2}, {sText_Season_Winter, 3},
};

static const u8 sText_EB_Easy[] = _("Easy");
static const u8 sText_EB_Normal[] = _("Normal");
static const u8 sText_EB_Hard[] = _("Hard");

static const struct ListMenuItem sSetEndlessBattleDifficulty[] =
{
    {sText_EB_Easy, 0}, {sText_EB_Normal, 1}, {sText_EB_Hard, 2},
};

static const u8 sText_EB_Start[] = _("Start a battle");
static const u8 sText_EB_Explain[] = _("What is this?");
static const u8 sText_EB_Leave[] = _("Leave");

static const struct ListMenuItem sSetEndlessBattleQuestion[] =
{
    {sText_EB_Start, 0}, {sText_EB_Explain, 1}, {sText_EB_Leave, 2},
};


// 2.X also addresses these sets by name (year/month/day pickers, the Monopoly
// minigame, costume lists). Placeholder contents: the scripts index them, so they
// must exist and be the right length, but the systems behind them are not ported.
static const u8 sText_Num_1[] = _("1");
static const u8 sText_Num_2[] = _("2");
static const u8 sText_Num_3[] = _("3");
static const u8 sText_Num_4[] = _("4");
static const u8 sText_Num_5[] = _("5");
static const u8 sText_Cancel_Opt[] = _("Cancel");


// Blue Nurse -> Change Date. INDEX-CRITICAL in the *other* direction from the rest of
// this file: a scrolling multichoice returns the selected item's `id` (see
// Task_ScrollingMultichoiceInput -> gSpecialVar_Result = input), not its row number, so
// these ids carry the REAL year/month/day. The script copies VAR_RESULT straight into
// VAR_TEMP_1/2/3 and SetGameDate() consumes them as values. They used to point at
// sSetGeneric5, a 6-entry "1..5, Cancel" placeholder, so the menus showed nonsense.
// Year ids are the RTC's two-digit form (25 = 2025), which is what ConvertDateToDayCount wants.
static const u8 sText_Year_25[] = _("2025");
static const u8 sText_Year_26[] = _("2026");
static const u8 sText_Year_27[] = _("2027");
static const u8 sText_Year_28[] = _("2028");
static const u8 sText_Year_29[] = _("2029");
static const u8 sText_Year_30[] = _("2030");
static const u8 sText_Year_31[] = _("2031");
static const u8 sText_Year_32[] = _("2032");
static const u8 sText_Year_33[] = _("2033");
static const u8 sText_Year_34[] = _("2034");
static const u8 sText_Year_35[] = _("2035");
static const u8 sText_Year_36[] = _("2036");
static const u8 sText_Year_37[] = _("2037");
static const u8 sText_Year_38[] = _("2038");
static const u8 sText_Year_39[] = _("2039");
static const u8 sText_Year_40[] = _("2040");

static const u8 sText_Month_01[] = _("January");
static const u8 sText_Month_02[] = _("February");
static const u8 sText_Month_03[] = _("March");
static const u8 sText_Month_04[] = _("April");
static const u8 sText_Month_05[] = _("May");
static const u8 sText_Month_06[] = _("June");
static const u8 sText_Month_07[] = _("July");
static const u8 sText_Month_08[] = _("August");
static const u8 sText_Month_09[] = _("September");
static const u8 sText_Month_10[] = _("October");
static const u8 sText_Month_11[] = _("November");
static const u8 sText_Month_12[] = _("December");

static const u8 sText_Day_01[] = _("1");
static const u8 sText_Day_02[] = _("2");
static const u8 sText_Day_03[] = _("3");
static const u8 sText_Day_04[] = _("4");
static const u8 sText_Day_05[] = _("5");
static const u8 sText_Day_06[] = _("6");
static const u8 sText_Day_07[] = _("7");
static const u8 sText_Day_08[] = _("8");
static const u8 sText_Day_09[] = _("9");
static const u8 sText_Day_10[] = _("10");
static const u8 sText_Day_11[] = _("11");
static const u8 sText_Day_12[] = _("12");
static const u8 sText_Day_13[] = _("13");
static const u8 sText_Day_14[] = _("14");
static const u8 sText_Day_15[] = _("15");
static const u8 sText_Day_16[] = _("16");
static const u8 sText_Day_17[] = _("17");
static const u8 sText_Day_18[] = _("18");
static const u8 sText_Day_19[] = _("19");
static const u8 sText_Day_20[] = _("20");
static const u8 sText_Day_21[] = _("21");
static const u8 sText_Day_22[] = _("22");
static const u8 sText_Day_23[] = _("23");
static const u8 sText_Day_24[] = _("24");
static const u8 sText_Day_25[] = _("25");
static const u8 sText_Day_26[] = _("26");
static const u8 sText_Day_27[] = _("27");
static const u8 sText_Day_28[] = _("28");
static const u8 sText_Day_29[] = _("29");
static const u8 sText_Day_30[] = _("30");
static const u8 sText_Day_31[] = _("31");

static const struct ListMenuItem sSetYears[] =
{
    {sText_Year_25, 25},
    {sText_Year_26, 26},
    {sText_Year_27, 27},
    {sText_Year_28, 28},
    {sText_Year_29, 29},
    {sText_Year_30, 30},
    {sText_Year_31, 31},
    {sText_Year_32, 32},
    {sText_Year_33, 33},
    {sText_Year_34, 34},
    {sText_Year_35, 35},
    {sText_Year_36, 36},
    {sText_Year_37, 37},
    {sText_Year_38, 38},
    {sText_Year_39, 39},
    {sText_Year_40, 40},
};

static const struct ListMenuItem sSetMonths[] =
{
    {sText_Month_01, 1},
    {sText_Month_02, 2},
    {sText_Month_03, 3},
    {sText_Month_04, 4},
    {sText_Month_05, 5},
    {sText_Month_06, 6},
    {sText_Month_07, 7},
    {sText_Month_08, 8},
    {sText_Month_09, 9},
    {sText_Month_10, 10},
    {sText_Month_11, 11},
    {sText_Month_12, 12},
};

static const struct ListMenuItem sSetDays[] =
{
    {sText_Day_01, 1},
    {sText_Day_02, 2},
    {sText_Day_03, 3},
    {sText_Day_04, 4},
    {sText_Day_05, 5},
    {sText_Day_06, 6},
    {sText_Day_07, 7},
    {sText_Day_08, 8},
    {sText_Day_09, 9},
    {sText_Day_10, 10},
    {sText_Day_11, 11},
    {sText_Day_12, 12},
    {sText_Day_13, 13},
    {sText_Day_14, 14},
    {sText_Day_15, 15},
    {sText_Day_16, 16},
    {sText_Day_17, 17},
    {sText_Day_18, 18},
    {sText_Day_19, 19},
    {sText_Day_20, 20},
    {sText_Day_21, 21},
    {sText_Day_22, 22},
    {sText_Day_23, 23},
    {sText_Day_24, 24},
    {sText_Day_25, 25},
    {sText_Day_26, 26},
    {sText_Day_27, 27},
    {sText_Day_28, 28},
    {sText_Day_29, 29},
    {sText_Day_30, 30},
    {sText_Day_31, 31},
};

static const struct ListMenuItem sSetGeneric5[] =
{
    {sText_Num_1, 0}, {sText_Num_2, 1}, {sText_Num_3, 2},
    {sText_Num_4, 3}, {sText_Num_5, 4}, {sText_Cancel_Opt, 5},
};

struct
{
    const struct ListMenuItem *set;
    int count;
} static const sScrollingSets[] =
{
    {sSet0,  ARRAY_COUNT(sSet0)},	
    {sSet1,  ARRAY_COUNT(sSet1)},
    {sSet2,  ARRAY_COUNT(sSet2)},
	{sSet3,  ARRAY_COUNT(sSet3)},
	{sSet4,  ARRAY_COUNT(sSet4)},
	{sSet5,  ARRAY_COUNT(sSet5)},
	{sSet6,  ARRAY_COUNT(sSet6)},
	{sSet7,  ARRAY_COUNT(sSet7)},
	{sSet8,  ARRAY_COUNT(sSet8)},
	{sSetBlueNurse,  ARRAY_COUNT(sSetBlueNurse)},	// 09
	{sSetBlueNurseMoveLearn, ARRAY_COUNT(sSetBlueNurseMoveLearn)},	// 10
	{sSetSeasons, ARRAY_COUNT(sSetSeasons)},	// 11 SCROLLING_SEASONS
	{sSetSeviiTicket, ARRAY_COUNT(sSetSeviiTicket)},	// 12 SCROLLING_SEVII_TICKET
	{sSetGenerations, ARRAY_COUNT(sSetGenerations)},	// 13 SCROLLING_GENERATIONS
	{sSetTypes, ARRAY_COUNT(sSetTypes)},	// 14 SCROLLING_TYPES
	{sSetOtherGameModes, ARRAY_COUNT(sSetOtherGameModes)},	// 15 SCROLLING_OTHER_GAME_MODES
	{sSetGenerations, ARRAY_COUNT(sSetGenerations)},	// 16 SCROLLING_STARTER_REGION
	{sSetEndlessBattleDifficulty, ARRAY_COUNT(sSetEndlessBattleDifficulty)},	// 17
	{sSetEndlessBattleQuestion, ARRAY_COUNT(sSetEndlessBattleQuestion)},	// 18
	{sSetYears, ARRAY_COUNT(sSetYears)},	// 19 SCROLLING_YEAR
	{sSetMonths, ARRAY_COUNT(sSetMonths)},	// 20 SCROLLING_MONTH
	{sSetDays, ARRAY_COUNT(sSetDays)},	// 21 SCROLLING_DAY
	{sSetGeneric5, ARRAY_COUNT(sSetGeneric5)},	// 22 SCROLLING_MONOPOLY
	{sSetGeneric5, ARRAY_COUNT(sSetGeneric5)},	// 23 SCROLLING_MONOPOLY_PC
	// 24/25 SCROLLING_COSTUMES_MALE/FEMALE are built at runtime by BuildCostumeList and
	// intercepted in ScriptMenu_ScrollingMultichoice; these entries are never read. Both
	// genders get the same list -- every character sprite is wearable by anyone.
	{NULL, 0},	// 24 SCROLLING_COSTUMES_MALE
	{NULL, 0},	// 25 SCROLLING_COSTUMES_FEMALE
};

// Every character with overworld art, plus the four base outfits. Built on the heap because
// static EWRAM is 99% full, and the menu is transient anyway.
static bool8 BuildCostumeList(void)
{
    u16 i;

    sCostumeItemCount = 0;
    sCostumeItems = Alloc((NUM_COSTUMES + GetCharacterCount() + 1) * sizeof(struct ListMenuItem));
    if (sCostumeItems == NULL)
        return FALSE;

    for (i = 0; i < NUM_COSTUMES; i++)
    {
        sCostumeItems[sCostumeItemCount].name = sBaseCostumeNames[i];
        sCostumeItems[sCostumeItemCount].id = i;
        sCostumeItemCount++;
    }

    for (i = 0; i < GetCharacterCount(); i++)
    {
        if (!CharacterHasOverworldSprite(i))
            continue;
        sCostumeItems[sCostumeItemCount].name = gCharacters[i].name;
        sCostumeItems[sCostumeItemCount].id = COSTUME_CHOICE_CHARACTER_BASE + i;
        sCostumeItemCount++;
    }

    sCostumeItems[sCostumeItemCount].name = gText_Cancel2;
    sCostumeItems[sCostumeItemCount].id = MULTI_B_PRESSED;
    sCostumeItemCount++;
    return TRUE;
}

static void FreeCostumeList(void)
{
    if (sCostumeItems != NULL)
    {
        Free(sCostumeItems);
        sCostumeItems = NULL;
        sCostumeItemCount = 0;
    }
}

// Consumes the id BuildCostumeList put on the chosen row. Called by the script straight
// after the multichoice, so there is no case-index mapping to get wrong.
void ApplyCostumeChoice(void)
{
    u16 choice = gSpecialVar_Result;

    if (choice == MULTI_B_PRESSED)
        return;

    if (choice >= COSTUME_CHOICE_CHARACTER_BASE)
    {
        VarSet(VAR_COSTUME_CHARACTER, choice - COSTUME_CHOICE_CHARACTER_BASE + 1);
    }
    else
    {
        // Back to a full outfit. Must be the BASE sentinel, not 0: 0 means "no costume
        // chosen", which falls back to the Character Mode character, so picking Emerald
        // while playing as Red would leave you looking like Red.
        VarSet(VAR_COSTUME_CHARACTER, COSTUME_CHARACTER_BASE);
        SetCostume(choice);
    }
    RefreshPlayerAvatarGraphics();
}

static void Task_ScrollingMultichoiceInput(u8 taskId);

static const struct ListMenuTemplate sMultichoiceListTemplate =
{
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 1,
    .cursorKind = 0
};

// 0x8004 = set id
// 0x8005 = window X
// 0x8006 = window y
// 0x8007 = showed at once
// 0x8008 = Allow B press
void ScriptMenu_ScrollingMultichoice(void)
{
    int i, windowId, taskId, width = 0;
    int setId = gSpecialVar_0x8004;
    int left = gSpecialVar_0x8005;
    int top = gSpecialVar_0x8006;
    int maxShowed = gSpecialVar_0x8007;
    const struct ListMenuItem *items = sScrollingSets[setId].set;
    int count = sScrollingSets[setId].count;

    // The costume list has no static table -- it is assembled from gCharacters[].
    if (setId == SCROLLING_COSTUMES_MALE || setId == SCROLLING_COSTUMES_FEMALE)
    {
        FreeCostumeList();   // a previous menu that was torn down without its task finishing
        if (!BuildCostumeList())
            return;
        items = sCostumeItems;
        count = sCostumeItemCount;
    }

    for (i = 0; i < count; i++)
        width = DisplayTextAndGetWidth(items[i].name, width);

    width = ConvertPixelWidthToTileWidth(width);
    left = ScriptMenu_AdjustLeftCoordFromWidth(left, width);
    windowId = CreateWindowFromRect(left, top, width, maxShowed * 2);
    SetStandardWindowBorderStyle(windowId, 0);
    CopyWindowToVram(windowId, 3);

    gMultiuseListMenuTemplate = sMultichoiceListTemplate;
    gMultiuseListMenuTemplate.windowId = windowId;
    gMultiuseListMenuTemplate.items = items;
    gMultiuseListMenuTemplate.totalItems = count;
    gMultiuseListMenuTemplate.maxShowed = maxShowed;

    taskId = CreateTask(Task_ScrollingMultichoiceInput, 0);
    gTasks[taskId].data[0] = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
    gTasks[taskId].data[1] = gSpecialVar_0x8008;
    gTasks[taskId].data[2] = windowId;
}

static void Task_ScrollingMultichoiceInput(u8 taskId)
{
    bool32 done = FALSE;
    s32 input = ListMenu_ProcessInput(gTasks[taskId].data[0]);

    switch (input)
    {
    case LIST_HEADER:
    case LIST_NOTHING_CHOSEN:
        break;
    case LIST_CANCEL:
        if (gTasks[taskId].data[1])
        {
            gSpecialVar_Result = 0x7F;
            done = TRUE;
        }
        break;
    default:
        gSpecialVar_Result = input;
        done = TRUE;
        break;
    }

    if (done)
    {
        DestroyListMenuTask(gTasks[taskId].data[0], NULL, NULL);
        ClearStdWindowAndFrame(gTasks[taskId].data[2], TRUE);
        RemoveWindow(gTasks[taskId].data[2]);
        // No-op unless this was the costume menu; the list menu is done reading it by now.
        FreeCostumeList();
        EnableBothScriptContexts();
        DestroyTask(taskId);
    }
}
