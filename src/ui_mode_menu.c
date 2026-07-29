#include "global.h"
#include "character_mode.h"
#include "ui_mode_menu.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_icon.h"
#include "item_use.h"
#include "field_screen_effect.h"
#include "international_string_util.h"
#include "main.h"
#include "main_menu.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon_icon.h"
#include "random.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "overworld.h"
#include "event_data.h"
#include "script_pokemon_util.h"
#include "constants/map_groups.h"
#include "constants/maps.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"

/*
 * 
 */

//==========DEFINES==========//
struct MenuResources
{
    MainCallback savedCallback;     // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
};

enum WindowIds
{
    WINDOW_1,
	WINDOW_STARTER,
};

//==========EWRAM==========//
static EWRAM_DATA struct MenuResources *sMenuDataPtr = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

//==========STATIC=DEFINES==========//
static void Menu_RunSetup(void);
static bool8 Menu_DoGfxSetup(void);
static bool8 Menu_Mode_InitBgs(void);
static void Menu_FadeAndBail(void);
static bool8 Menu_LoadGraphics(void);
static void Menu_Mode_InitWindows(void);
static void PrintToWindow(u8 windowId, u8 colorIdx);
static void Task_MenuWaitFadeIn(u8 taskId);
static void Task_MenuMain(u8 taskId);

static u8 ShowSpeciesIcon(u16 species, u16 formId, u8 x, u8 y);
static void DestroySpeciesIcon(void);
//==========CONST=DATA==========//
static const struct BgTemplate sMenuBgTemplates[] =
{
    {
        .bg = 0,    // windows, etc
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    }, 
    {
        .bg = 1,    // this bg loads the UI tilemap
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    },
    {
        .bg = 2,    // this bg loads the UI tilemap
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .priority = 0
    }
};

static const struct WindowTemplate sMenuWindowTemplates[] = 
{
    [WINDOW_1] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 1,   // position from left (per 8 pixels)
        .tilemapTop = 3,    // position from top (per 8 pixels)
        .width = 26,        // width (per 8 pixels)
        .height = 16,       // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },
	[WINDOW_STARTER] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 4,   // position from left (per 8 pixels)
        .tilemapTop = 8,    // position from top (per 8 pixels)
        .width = 10,        // width (per 8 pixels)
        .height = 3,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },
};

static const u32 sMenuTiles[] 			= INCBIN_U32("graphics/ui_menu/tiles.4bpp.lz");
static const u32 sMenuTilemap[] 		= INCBIN_U32("graphics/ui_menu/tilemap.bin.lz");
static const u16 sMenuPalette[] 		= INCBIN_U16("graphics/ui_menu/palette.gbapal");
static const u8 sStartMenuCursor[] 		= INCBIN_U8("graphics/ui_menu/select_arrow.4bpp");
static const u8 sStartModeCheck[] 		= INCBIN_U8("graphics/ui_menu/mode_check.4bpp");
static const u8 sStartModeSelection[] 	= INCBIN_U8("graphics/ui_menu/mode_selection.4bpp");

#define  NUM_ROWS   	 		 5
#define  NUM_MODES  	 		 9
#define  NUM_STARTERS  	 		 10
#define  NUM_DIFFICULTY_OPTIONS  3
#define  NUM_STARTING_AREAS  	 14

// EWRAM
EWRAM_DATA static u8 	cursorRow 		  		  = 0;
EWRAM_DATA static u8 	cursorRowModes   		  = 0;
EWRAM_DATA static u8 	starterselection 		  = 0;
EWRAM_DATA static u8 	selection_StartingArea 	  = 0;
EWRAM_DATA static u8 	Difficulty_Mode 		  = 1;
EWRAM_DATA static bool8 Mode_Selection 			  = FALSE;
EWRAM_DATA static u16 	characterSelection 		  = 0;
EWRAM_DATA static u8 	genSelection 			  = 0; // EWRAM inits are discarded; set on menu open
//EWRAM_DATA static bool8 Mode_Checks[NUM_MODES];

//Sprites
EWRAM_DATA static u8 StarterSpriteId = 0;

// NO CHARACTER PORTRAIT HERE, AND IT IS NOT AN OVERSIGHT -- see PLAN.md §7.4.
// A 64x64 trainer pic was wired up on 2026-07-28 and REVERTED the same day:
// there is no free 64x64 region on this screen. The reasoning that put it at
// (150, 60) checked the mode CHECKBOX column (screen x 184) and missed that the
// mode LABELS start at x ~118, so the sprite covered the "MODES" heading and
// seven of the nine labels. Rendering graphics/ui_menu/tilemap.bin over
// tiles.png shows the layout is full: the widest free gaps are the 16 px
// between the left panel and the modes panel, and the 40 px right of it.
// Showing a portrait needs the menu tilemap redrawn to make room -- art, not
// wiring.

static const u16 StarterPokemon[] = {
	SPECIES_MEOWTH,
	SPECIES_SLUGMA,
	SPECIES_BARBOACH,
	SPECIES_KRICKETOT,
	SPECIES_CUBCHOO,
	SPECIES_SKIDDO,
	SPECIES_SANDYGAST,
	SPECIES_CUFANT,
	SPECIES_SMEARGLE,
	SPECIES_NONE,
};

static const u16 ModeFlags[] = {
	FLAG_PERFECT_IVS_MODE,
	FLAG_NO_EVS_MODE,
	FLAG_INVERSE_MODE,
	FLAG_RANDOMIZED_MODE,
	FLAG_DOUBLE_BATTLE_MODE,
	FLAG_NO_EVOLUTION_MODE,
	FLAG_LEVELESS_MODE,
	FLAG_NO_SPLIT_MODE,
	FLAG_VANILLA_MODE
};

// Character Mode: the starter row cycles the chosen character's roster.
static u16 GetStarterAt(u8 idx)
{
    if (characterSelection != 0)
        return gCharacters[characterSelection - 1].roster[idx];
    return StarterPokemon[idx];
}

static u8 GetNumStarters(void)
{
    if (characterSelection != 0)
    {
        // Legendaries sit at the roster tail and are never starter options.
        if (gCharacters[characterSelection - 1].starterCount != 0)
            return gCharacters[characterSelection - 1].starterCount;
        return CharacterMode_GetRosterSize(&gCharacters[characterSelection - 1]);
    }
    return NUM_STARTERS;
}

// Default starter: the character's signature ace when known (roster[0]),
// otherwise a random non-legendary roster member.
//
// An ALL-LEGENDARY roster (starterCount == 0) has no non-legendary member to
// roll, so GetNumStarters() falls back to the whole roster -- and rolling over
// THAT handed the character a random legendary. It is roster[0], deliberately:
// the user's rule is that such a character still gets a starter and always the
// same one, so Tobias always starts with Darkrai rather than a coin flip
// between Darkrai and Latios.
//
// Tobias is currently the only character in this state. Cogita and Iscan --
// the sharp cases in Unbound and Radical Red -- resolve to EMPTY rosters in
// ROWE's dex and are not in gCharacters at all, so nothing else reaches here.
static void RandomizeStarterSelection(void)
{
    const struct CharacterInfo *character;

    if (characterSelection == 0)
    {
        starterselection = 0;
        return;
    }

    character = &gCharacters[characterSelection - 1];
    if (character->hasSignature || character->starterCount == 0)
        starterselection = 0;
    else
        starterselection = Random() % GetNumStarters();
}

// 1-based index of the first character in a generation (a character always
// exists in every generation 1-9).
static u16 FirstCharacterInGen(u8 gen)
{
    u16 i;

    for (i = 0; i < GetCharacterCount(); i++)
    {
        if (gCharacters[i].generation == gen && gCharacters[i].selectable)
            return i + 1;
    }
    return 1;
}

// Cycle within the selected generation; there is no "None" entry - a
// character is always selected.
static void CycleCharacter(int delta)
{
    int step = delta > 0 ? 1 : -1;
    int count = delta > 0 ? delta : -delta;
    int sel = characterSelection;
    int guard;

    while (count--)
    {
        guard = GetCharacterCount() + 1;
        do
        {
            sel += step;
            if (sel < 1)
                sel = GetCharacterCount();
            else if (sel > (int)GetCharacterCount())
                sel = 1;
        } while (guard-- > 0
                 && (gCharacters[sel - 1].generation != genSelection
                     || !gCharacters[sel - 1].selectable));
    }
    characterSelection = sel;
    RandomizeStarterSelection();
}

static void CycleGeneration(int delta)
{
    int gen = (int)genSelection + delta;

    if (gen < 1)
        gen = 9;
    else if (gen > 9)
        gen = 1;
    genSelection = gen;
    characterSelection = FirstCharacterInGen(gen);
    RandomizeStarterSelection();
}

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};
static const u8 sMenuWindowFontColors[][3] = 
{
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_DARK_GREY,  TEXT_COLOR_LIGHT_GREY},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_WHITE,  TEXT_COLOR_DARK_GREY},
    [FONT_RED]   = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GREY},
    [FONT_BLUE]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_BLUE,       TEXT_COLOR_LIGHT_GREY},
};

//==========FUNCTIONS==========//
// UI loader template
// Script entry point (intro truck question, data/specials.inc).
void Special_OpenCharacterModeMenu(void)
{
    CleanupOverworldWindowsAndTilemaps();
    Menu_Mode_Init(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void Task_OpenModeMenuFromStartMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        Menu_Mode_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

// This is our main initialization function if you want to call the menu from elsewhere
void Menu_Mode_Init(MainCallback callback)
{
    if ((sMenuDataPtr = AllocZeroed(sizeof(struct MenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    // initialize stuff
    sMenuDataPtr->gfxLoadState = 0;
    sMenuDataPtr->savedCallback = callback;

    SetMainCallback2(Menu_RunSetup);
}

static void Menu_RunSetup(void)
{
    while (1)
    {
        if (Menu_DoGfxSetup() == TRUE)
            break;
    }
}

static void Menu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Menu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static bool8 Menu_DoGfxSetup(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (Menu_Mode_InitBgs())
        {
            sMenuDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            Menu_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        if (Menu_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        LoadMessageBoxAndBorderGfx();
        Menu_Mode_InitWindows();
        gMain.state++;
        break;
    case 5:
        // Restore selections BEFORE the first draw: EWRAM initializers are
        // discarded on GBA, so genSelection boots as 0 and would index
        // sGenTexts out of bounds if PrintToWindow ran first.
		characterSelection = VarGet(VAR_CHARACTER_ID) <= GetCharacterCount() ? VarGet(VAR_CHARACTER_ID) : 0;
		genSelection = characterSelection != 0 ? gCharacters[characterSelection - 1].generation : 1;
		if (genSelection < 1 || genSelection > 9)
			genSelection = 1;
		if (characterSelection == 0) // no "None" entry: always have a pick
			characterSelection = FirstCharacterInGen(genSelection);
		if (starterselection >= GetNumStarters())
			starterselection = 0;

        PrintToWindow(WINDOW_1, FONT_BLACK);
        taskId = CreateTask(Task_MenuWaitFadeIn, 0);
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);

		DestroySpeciesIcon();
		ShowSpeciesIcon(GetStarterAt(starterselection), 0, (13*8)+4, (16*8)+4);

        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(Menu_VBlankCB);
        SetMainCallback2(Menu_MainCB);
        return TRUE;
    }
    return FALSE;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void Menu_FreeResources(void)
{
    try_free(sMenuDataPtr);
    try_free(sBg1TilemapBuffer);
    FreeAllWindowBuffers();
}


static void Task_MenuWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

static void Menu_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_MenuWaitFadeAndBail, 0);
    SetVBlankCallback(Menu_VBlankCB);
    SetMainCallback2(Menu_MainCB);
}

static bool8 Menu_Mode_InitBgs(void)
{
    ResetAllBgsCoordinates();
    sBg1TilemapBuffer = Alloc(0x800);
    if (sBg1TilemapBuffer == NULL)
        return FALSE;

    memset(sBg1TilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sMenuBgTemplates, NELEMS(sMenuBgTemplates));
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    return TRUE;
}

static bool8 Menu_LoadGraphics(void)
{
    switch (sMenuDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sMenuTiles, 0, 0, 0);
        sMenuDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sMenuTilemap, sBg1TilemapBuffer);
            sMenuDataPtr->gfxLoadState++;
        }
        break;
    case 2:
        LoadPalette(sMenuPalette, 0, 32);
        sMenuDataPtr->gfxLoadState++;
        break;
    default:
        sMenuDataPtr->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void Menu_Mode_InitWindows(void)
{
    u32 i;

    InitWindows(sMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);

    FillWindowPixelBuffer(WINDOW_1, 0);
    LoadUserWindowBorderGfx(WINDOW_1, 720, 14 * 16);
    PutWindowTilemap(WINDOW_1);
    CopyWindowToVram(WINDOW_1, 3);

    ScheduleBgCopyTilemapToVram(2);
}

static const u8 sText_Difficulty[] 				= _("Difficulty");
static const u8 sText_Difficulty_Easy[] 		= _("Easy");
static const u8 sText_Difficulty_Normal[] 		= _("Normal");
static const u8 sText_Difficulty_Hard[] 		= _("Hard");
static const u8 sText_Starter[] 				= _("Starter");
static const u8 sText_Starting_Area[] 			= _("Starting Area");
static const u8 sText_Gen_1[] = _("Gen I");
static const u8 sText_Gen_2[] = _("Gen II");
static const u8 sText_Gen_3[] = _("Gen III");
static const u8 sText_Gen_4[] = _("Gen IV");
static const u8 sText_Gen_5[] = _("Gen V");
static const u8 sText_Gen_6[] = _("Gen VI");
static const u8 sText_Gen_7[] = _("Gen VII");
static const u8 sText_Gen_8[] = _("Gen VIII");
static const u8 sText_Gen_9[] = _("Gen IX");
static const u8 *const sGenTexts[9] =
{
    sText_Gen_1, sText_Gen_2, sText_Gen_3, sText_Gen_4, sText_Gen_5,
    sText_Gen_6, sText_Gen_7, sText_Gen_8, sText_Gen_9,
};
static const u8 sText_IVs_Mode[] 				= _("Perfect IVs");
static const u8 sText_StarterChose_Surprise[] 	= _("Surprise Me");
static const u8 sText_Mode_Enabled[] 			= _("Enabled    ");
static const u8 sText_Mode_Disabled[] 			= _("Disabled    ");

static const u8 gText_Littleroot[] 	 = _("Littleroot");
static const u8 gText_Oldale[] 		 = _("Oldale");
//static const u8 gText_Petalburg[] 	 = _("Petalburg");  //Already defined in strings.h
static const u8 gText_Rustboro[] 	 = _("Rustboro");
//static const u8 gText_Dewford[] 	 = _("Dewford");		//Already defined in strings.h
//static const u8 gText_Slateport[]    = _("Slateport");	//Already defined in strings.h
static const u8 gText_Mauville[]   	 = _("Mauville");
static const u8 gText_Fallarbor[]    = _("Fallarbor");
static const u8 gText_Fortree[]   	 = _("Fortree");
static const u8 gText_Lilycove[]   	 = _("Lilycove");
static const u8 gText_Mossdeep[]   	 = _("Mossdeep");
static const u8 gText_Sootopolis[]   = _("Sootopolis");
static const u8 gText_Pacifidlog[]   = _("Pacifidlog");

static void PrintToWindow(u8 windowId, u8 colorIdx)
{
	const u8 *StartingArea;
	u8 strArray[16];
	const u8 *Difficulty;
	u8 i;
    u8 x = 0;
    u8 y = 1;
	
	StringCopy(&strArray[0], &gSpeciesNames[GetStarterAt(starterselection)][0]);
	
	switch(selection_StartingArea){
	case 0:		StartingArea = gText_Littleroot;				break;
    case 1:		StartingArea = gText_Oldale;					break;
	case 2:		StartingArea = gText_Petalburg;					break;
	case 3:		StartingArea = gText_Rustboro;					break;
	case 4:		StartingArea = gText_Dewford;					break;
	case 5:		StartingArea = gText_Slateport;					break;
	case 6:		StartingArea = gText_Mauville;					break;
	case 7:		StartingArea = gText_Fallarbor;					break;
	case 8:		StartingArea = gText_Fortree;					break;
	case 9:		StartingArea = gText_Lilycove;					break;
	case 10:	StartingArea = gText_Mossdeep;					break;
	case 11:	StartingArea = gText_Sootopolis;				break;
	case 12:	StartingArea = gText_Pacifidlog;				break;
	default:	StartingArea = sText_StarterChose_Surprise;		break;
	}
	
	switch(Difficulty_Mode){
	case 0:		Difficulty = sText_Difficulty_Easy;		break;
    case 1:		Difficulty = sText_Difficulty_Normal;	break;
	case 2:		Difficulty = sText_Difficulty_Hard;		break;
	}
	
    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
	if(!Mode_Selection)
		BlitBitmapToWindow(windowId, sStartMenuCursor, 2, (cursorRow*3 + 1)*8 + 4, 8, 8);
	else
		BlitBitmapToWindow(windowId, sStartModeSelection, 22*8, (cursorRowModes+2)*8, 8, 8);
	
	for(i = 0; i < NUM_MODES; i++){
		if(FlagGet(ModeFlags[i]))
		BlitBitmapToWindow(windowId, sStartModeCheck, 22*8, (i+2)*8, 8, 8);
	}
	
	x = 2;
	//Options -------------------------------------------------------------------------------------------
	//AddTextPrinterParameterized4(windowId, 7, x*8, y*8, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Starter);		y = y+3;
	//AddTextPrinterParameterized4(windowId, 7, x*8, y*8, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Starting_Area);	y = y+3;
	//AddTextPrinterParameterized4(windowId, 7, x*8, y*8, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_Difficulty);		y = y+3;
	y = 1;
	//x = 9;
	//Config  -------------------------------------------------------------------------------------------
	if(GetStarterAt(starterselection) != SPECIES_NONE)
		AddTextPrinterParameterized4(windowId, 7, (x*8)+2, (y*8), 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, &strArray[0]);		
	else
		AddTextPrinterParameterized4(windowId, 7, (x*8)+2, (y*8), 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sText_StarterChose_Surprise);	
	y = y+3; 
	AddTextPrinterParameterized4(windowId, 7, (x*8)+2, (y*8), 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, StartingArea);			y = y+3;
	AddTextPrinterParameterized4(windowId, 7, (x*8)+2, (y*8), 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, Difficulty);			y = y+3;
	AddTextPrinterParameterized4(windowId, 7, (x*8)+2, (y*8), 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, sGenTexts[genSelection - 1]);
	y = y+3;
	if(characterSelection == 0) // safety: should be preselected on menu open
		characterSelection = FirstCharacterInGen(genSelection);
	AddTextPrinterParameterized4(windowId, 7, (x*8)+2, (y*8), 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, gCharacters[characterSelection - 1].name);
	y = y+3;
	x = 20;
	y = 5;
	
	PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
	PutWindowTilemap(windowId);
}

static u8 ShowSpeciesIcon(u16 species, u16 formId, u8 x, u8 y)
{
	LoadMonIconPalette(species);
	
    if (StarterSpriteId == 0xFF)
        StarterSpriteId = CreateMonIcon(species, SpriteCB_MonIcon, x, y, 0, 0, formId);

    gSprites[StarterSpriteId].invisible = FALSE;
    return StarterSpriteId;
}

static void DestroySpeciesIcon(void)
{
    // FreeAndDestroyMonIconSprite also releases the icon's VRAM tiles;
    // plain DestroySprite leaked them, blanking icons after ~60 cycles.
    if (StarterSpriteId != 0xFF)
        FreeAndDestroyMonIconSprite(&gSprites[StarterSpriteId]);
    StarterSpriteId = 0xFF;
}

static void Task_MenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_MenuMain;
}

static void Task_MenuTurnOff(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

/* This is the meat of the UI. This is where you wait for player inputs and can branch to other tasks accordingly */
static void Task_MenuMain(u8 taskId)
{
	if (JOY_NEW(A_BUTTON))
    {
		if(Mode_Selection)
		{
			if(FlagGet(ModeFlags[cursorRowModes]))
			{
				FlagClear(ModeFlags[cursorRowModes]);
				PlaySE(SE_FAILURE);
			}
			else
			{
				FlagSet(ModeFlags[cursorRowModes]);
				PlaySE(SE_SELECT);
			}
		}
		else
		{
			if(cursorRow == 0 && GetStarterAt(starterselection) != SPECIES_NONE)
			PlayCry3(GetStarterAt(starterselection), 0, 0);	
		}
	}
	
	if (JOY_NEW(START_BUTTON))
    {
        if (characterSelection != 0)
        {
            FlagSet(FLAG_CHARACTER_MODE);
            VarSet(VAR_CHARACTER_ID, characterSelection);
            CharacterMode_SweepPartyToPC();
            // Give the roster starter only if no roster member remains,
            // so re-committing can't mint duplicate starters; the second
            // sweep then clears any off-roster mon the first one spared.
            if (!CharacterMode_PartyHasAllowedMon())
            {
                ScriptGiveMon(GetStarterAt(starterselection), 10, ITEM_NONE, 0,0,0);
                CharacterMode_SweepPartyToPC();
            }
        }
        else
        {
            FlagClear(FLAG_CHARACTER_MODE);
            VarSet(VAR_CHARACTER_ID, 0);
            if (CalculatePlayerPartyCount() == 0)
                ScriptGiveMon(GetStarterAt(starterselection), 10, ITEM_NONE, 0,0,0);
        }
		
		FlagClear(FLAG_EASY_MODE);
		FlagClear(FLAG_NORMAL_MODE);
		FlagClear(FLAG_HARD_MODE);
		switch(Difficulty_Mode){
		case 0:
		FlagSet(FLAG_EASY_MODE);	
		break;
		case 1:
		FlagSet(FLAG_NORMAL_MODE);	
		break;
		case 2:
		FlagSet(FLAG_HARD_MODE);	
		break;
		}
		
		PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
		
		//SetWarpDestinationToMapWarp(MAP_GROUP(PETALBURG_CITY), MAP_NUM(PETALBURG_CITY), 0);
        //DoWarp();
        //ResetInitialPlayerAvatarState();
		//gTasks[taskId].func = Task_NewGameBirchSpeech_Cleanup;
		gTasks[taskId].func = Task_MenuTurnOff;
    }
	
	
	if (JOY_NEW(L_BUTTON) && !Mode_Selection && cursorRow == 4)
    {
		CycleCharacter(10);
		DestroySpeciesIcon();
		ShowSpeciesIcon(GetStarterAt(starterselection), 0, (13*8)+4, (16*8)+4);
		PlaySE(SE_SELECT);
	}

	if (JOY_NEW(R_BUTTON))
    {
		if(Mode_Selection)
			Mode_Selection = FALSE;
		else
			Mode_Selection = TRUE;
	}
	
	if (JOY_NEW(DPAD_DOWN)){
		if(!Mode_Selection)
		{
			if(cursorRow < NUM_ROWS-1)
				cursorRow++;
			else
				cursorRow = 0;
		}
		else
		{
			if(cursorRowModes < NUM_MODES-1)
				cursorRowModes++;
			else
				cursorRowModes = 0;
		}
		PlaySE(SE_SELECT);
	}
	
	if (JOY_NEW(DPAD_UP)){
		if(!Mode_Selection)
		{
			if(cursorRow != 0)
				cursorRow--;
			else
				cursorRow = NUM_ROWS-1;
		}
		else
		{
			if(cursorRowModes != 0)
				cursorRowModes--;
			else
				cursorRowModes = NUM_MODES-1;
		}
		PlaySE(SE_SELECT);	
	}

	if(JOY_NEW(DPAD_RIGHT))
	{
		if(!Mode_Selection)
		{
			switch(cursorRow){
			//Starter Selection ---------------------------------------------
			case 0: 
			if(starterselection < GetNumStarters()-1)
				starterselection++;
			else
				starterselection = 0; 
			
			DestroySpeciesIcon();
			ShowSpeciesIcon(GetStarterAt(starterselection), 0, (13*8)+4, (16*8)+4);
			
			if(GetStarterAt(starterselection) != SPECIES_NONE)
			PlayCry3(GetStarterAt(starterselection), 0, 0);	
			break;
			//Starting Area ---------------------------------------------------
			case 1:
			if(selection_StartingArea < NUM_STARTING_AREAS-1)
				selection_StartingArea++;
			else
				selection_StartingArea = 0; 
			break;
			
			PlaySE(SE_SELECT);
			//Difficulty Mode ---------------------------------------------------
			case 2:
			if(Difficulty_Mode < NUM_DIFFICULTY_OPTIONS-1)
				Difficulty_Mode++;
			else
				Difficulty_Mode= 0; 
			
			PlaySE(SE_SELECT);
			break;
			//Generation ---------------------------------------------------
			case 3:
			CycleGeneration(1);
			DestroySpeciesIcon();
			ShowSpeciesIcon(GetStarterAt(starterselection), 0, (13*8)+4, (16*8)+4);
			PlaySE(SE_SELECT);
			break;
			//Character ---------------------------------------------------
			case 4:
			CycleCharacter(1);
			DestroySpeciesIcon();
			ShowSpeciesIcon(GetStarterAt(starterselection), 0, (13*8)+4, (16*8)+4);
			PlaySE(SE_SELECT);
			}
			
		}
	}
	
	if(JOY_NEW(DPAD_LEFT))
	{
		if(!Mode_Selection)
		{
			switch(cursorRow){
			//Starter Selection ---------------------------------------------
			case 0: 
			if(starterselection != 0)
				starterselection--;
			else
				starterselection = GetNumStarters()-1;
			
			DestroySpeciesIcon();
			ShowSpeciesIcon(GetStarterAt(starterselection), 0, (13*8)+4, (16*8)+4);
			
			if(GetStarterAt(starterselection) != SPECIES_NONE)
			PlayCry3(GetStarterAt(starterselection), 0, 0);	
		
			
			break;
			//Staring Area ---------------------------------------------------
			case 1:
			if(selection_StartingArea != 0)
				selection_StartingArea--;
			else
				selection_StartingArea = NUM_STARTING_AREAS-1;
			
			PlaySE(SE_SELECT);
			break;
			//Difficulty Mode ---------------------------------------------------
			case 2:
			if(Difficulty_Mode != 0)
				Difficulty_Mode--;
			else
				Difficulty_Mode = NUM_DIFFICULTY_OPTIONS-1;
			
			PlaySE(SE_SELECT);
			break;
			//Generation ---------------------------------------------------
			case 3:
			CycleGeneration(-1);
			DestroySpeciesIcon();
			ShowSpeciesIcon(GetStarterAt(starterselection), 0, (13*8)+4, (16*8)+4);
			PlaySE(SE_SELECT);
			break;
			//Character ---------------------------------------------------
			case 4:
			CycleCharacter(-1);
			DestroySpeciesIcon();
			ShowSpeciesIcon(GetStarterAt(starterselection), 0, (13*8)+4, (16*8)+4);
			PlaySE(SE_SELECT);
			break;
			}
		}
	}
	
	PrintToWindow(WINDOW_1, FONT_BLACK);
}