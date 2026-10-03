#include "global.h"
#include "character_mode.h"
#include "character_roster_menu.h"
#include "data.h"
#include "event_data.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "map_name_popup.h"
#include "menu.h"
#include "menu_helpers.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "window.h"
#include "constants/songs.h"

// ===== Character Mode: the active character's roster =====
// Until this existed, nothing in the ROM told the player which Pokemon their
// character is allowed to keep -- the only source was docs/ROSTERS.md, read
// outside the game. The encounter markers say "destined for RED!" AFTER a wild
// mon appears; this answers the question the player actually has, which is what
// to go looking for.
//
// One row per FAMILY ROOT, which is exactly what CharacterInfo.roster stores.
// Listing every evolution stage was considered and rejected: the roster is the
// authored data, the family rule ("canon if any member is") is what makes the
// stages legal, and a list of roots is 10 rows for the median character where
// the expanded set is hundreds.
//
// The icon is ONE sprite tracking the highlighted row, not a per-row icon.
// Mon icons share three palettes, so N icons blitted into one text window is a
// palette-allocation problem; a single sprite is not.
//
// NOTE: this file deliberately has NO mutable file-scope state, so it needs no
// entry in sym_bss.txt / sym_common.txt / sym_ewram.txt -- exactly like
// trainer_skills_menu.o, the template it was cloned from. All per-open state
// lives in the input task's data[], and the allocated item array is reached
// through the list menu's own template.

#define ROSTER_MENU_WIDTH    13
#define ROSTER_MENU_ROWS      6
#define ROSTER_HEADER_WIDTH  16
// Two lines: "<name>'s roster", then sText_RosterHint. The list shows family
// roots only while enforcement allows every stage, so the screen says so
// (user ruling 2026-10-02: a hint line, not every stage as its own row).
#define ROSTER_HEADER_HEIGHT  4
// The 20-tile screen holds header frame (rows 0-5) + list frame (rows 6-19)
// exactly: header at row 1 for 4 rows, list at row 7 for 2*ROSTER_MENU_ROWS.
#define ROSTER_MENU_TOP      (1 + ROSTER_HEADER_HEIGHT + 2)

// The icon sits in its own framed box to the right of the list (which ends at
// x=112) and below the header. The box is 5x5 tiles at (19,8), i.e. x 152..192
// and y 64..104, so a 32x32 icon centred at (172,84) leaves a 4px margin all
// round. DrawStdWindowFrame draws one further tile outside that, x 144..200 /
// y 56..112, which still clears the list frame (ends x=120) and the header
// frame (ends y=48 since the header became two lines).
#define ROSTER_ICON_WIN_LEFT  19
#define ROSTER_ICON_WIN_TOP    8
#define ROSTER_ICON_WIN_SIZE   5
// AddWindow's failure return; this tree has no WINDOW_NONE constant.
#define ROSTER_NO_WINDOW    0xFF
#define ROSTER_ICON_X        172
// 80, not the box's geometric centre of 84: mon icon art is bottom-weighted
// inside its 32x32 frame, so centring the SPRITE leaves the creature sitting
// low with dead space above it. Measured on the rendered screen -- Pikachu's
// ink came out dx=-0.5, dy=+4.0 from the box centre -- so the sprite is
// raised by that 4. (Icons bob under SpriteCB_MonIcon, so treat a 1-2px
// residual as phase, not error.)
#define ROSTER_ICON_Y         80

#define tListTaskId  data[0]
#define tWindowId    data[1]
#define tHeaderId    data[2]
#define tIconSprite  data[3]
#define tItemsHi     data[4]
#define tItemsLo     data[5]
#define tIconWinId   data[6]
#define tIconSpecies data[7]    // whose icon palette tIconSprite holds

static void RosterMenu_HandleInput(u8 taskId);
static void RosterMenu_Destroy(u8 taskId);
static void RosterMenu_MoveCursor(s32 itemId, bool8 onInit, struct ListMenu *list);

static const u8 sText_RosterTitle[] = _("{STR_VAR_1}'s roster");
static const u8 sText_RosterHint[] = _("Evolutions count too.");
static const u8 sText_RosterEmpty[] = _("No roster in this game.");

static const struct ListMenuTemplate sRosterMenuTemplate = {
    .items = NULL,                  // filled in at open time from the roster
    .moveCursorFunc = RosterMenu_MoveCursor,
    .totalItems = 0,
};

static const struct WindowTemplate sRosterMenuWindow = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = ROSTER_MENU_TOP,
    .width = ROSTER_MENU_WIDTH,
    .height = 2 * ROSTER_MENU_ROWS,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const struct WindowTemplate sRosterHeaderWindow = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = ROSTER_HEADER_WIDTH,
    .height = ROSTER_HEADER_HEIGHT,
    .paletteNum = 15,
    .baseBlock = 1 + ROSTER_MENU_WIDTH * 2 * ROSTER_MENU_ROWS,
};

static struct ListMenuItem *GetRosterItems(u8 taskId)
{
    return (struct ListMenuItem *)((gTasks[taskId].tItemsHi << 16)
                                   | (u16)gTasks[taskId].tItemsLo);
}

static void SetRosterItems(u8 taskId, struct ListMenuItem *items)
{
    gTasks[taskId].tItemsHi = (u32)items >> 16;
    gTasks[taskId].tItemsLo = (u32)items & 0xFFFF;
}

// A plain framed box for the icon to sit in. It holds no text -- it is filled
// and copied so the frame reads as a deliberate container rather than a hole
// in the map.
static const struct WindowTemplate sRosterIconWindow = {
    .bg = 0,
    .tilemapLeft = ROSTER_ICON_WIN_LEFT,
    .tilemapTop = ROSTER_ICON_WIN_TOP,
    .width = ROSTER_ICON_WIN_SIZE,
    .height = ROSTER_ICON_WIN_SIZE,
    .paletteNum = 15,
    .baseBlock = 1 + ROSTER_MENU_WIDTH * 2 * ROSTER_MENU_ROWS
                   + ROSTER_HEADER_WIDTH * ROSTER_HEADER_HEIGHT,
};

static void RosterMenu_DrawHeader(u8 windowId, const struct CharacterInfo *character)
{
    StringCopy(gStringVar1, character->name);
    StringExpandPlaceholders(gStringVar4, sText_RosterTitle);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(windowId, 1, gStringVar4, 0, 1, 0, NULL);
    AddTextPrinterParameterized(windowId, 1, sText_RosterHint, 0, 16, 0, NULL);
    CopyWindowToVram(windowId, 3);
}

// Removes the one icon sprite AND the palette it was drawn with.
// ⚠️ FreeAndDestroyMonIconSprite does NOT free the palette: it is
// sub_80D328C, which only calls DestroySprite. Until 2026-09-28 this file said
// the opposite, called nothing else, and every icon palette the cursor touched
// (tags POKE_ICON_BASE_PAL_TAG+0..6) stayed loaded on the field after the
// screen closed, up to 7 of the 16 sprite palette slots. roster_menu_e2e.lua
// now checks that no icon palette survives the close.
static void RosterMenu_DestroyIcon(u8 taskId)
{
    if (gTasks[taskId].tIconSprite != MAX_SPRITES)
    {
        FreeAndDestroyMonIconSprite(&gSprites[gTasks[taskId].tIconSprite]);
        FreeMonIconPalette(gTasks[taskId].tIconSpecies);
        gTasks[taskId].tIconSprite = MAX_SPRITES;
    }
}

// Redraws the single icon sprite for whichever row the cursor is now on.
// ListMenuInit calls this once with onInit set, which is why the input task is
// created BEFORE ListMenuInit -- the sprite id has to have somewhere to live
// on that very first call.
//
// ⚠️ THE FIRST PARAMETER IS THE ITEM'S ID, NOT ITS INDEX. list_menu.c:886:
//     moveCursorFunc(list->template.items[scrollOffset + selectedRow].id, ...)
// The name `itemIndex` is the donor's and it is a lie. Indexing items[] with
// it drew the WRONG SPECIES -- with the cursor on Red's Pikachu (id 25) it
// drew items[25], which is Scyther, and because Scyther is green the symptom
// looked exactly like a palette bug rather than a wrong-species bug. Two
// rebuilds went into "fixing" a palette that was never broken. Since .id IS
// the species here (see CharacterRosterMenu_Open), the parameter is already
// what this function needs and items[] must not be indexed at all.
static void RosterMenu_MoveCursor(s32 itemId, bool8 onInit, struct ListMenu *list)
{
    u8 taskId = FindTaskIdByFunc(RosterMenu_HandleInput);
    u16 species;

    if (taskId == TASK_NONE || itemId <= 0)
        return;

    if (!onInit)
        PlaySE(SE_SELECT);

    RosterMenu_DestroyIcon(taskId);

    species = (u16)itemId;
    // LoadMonIconPalette(species), not LoadMonIconPalettes(): load the one
    // palette this row needs rather than all seven. This screen runs over the
    // live field, where overworld sprites already hold most of the sprite
    // palette slots, and DrawDexNavSearchMonIcon -- the only other mon icon
    // drawn over the field in this repo -- loads per species for that reason.
    // (It is NOT the fix for the wrong-colour icon; that was the item-id bug
    // above, and the palette was innocent.)
    LoadMonIconPalette(species);
    gTasks[taskId].tIconSprite = CreateMonIcon(species, SpriteCB_MonIcon,
                                               ROSTER_ICON_X, ROSTER_ICON_Y, 0, 0,
                                               GetFormIdFromFormSpeciesId(species));
    if (gTasks[taskId].tIconSprite == MAX_SPRITES)
    {
        // No sprite to own the palette, so nothing would ever free it.
        FreeMonIconPalette(species);
        return;
    }
    gTasks[taskId].tIconSpecies = species;
    gSprites[gTasks[taskId].tIconSprite].oam.priority = 0;
}

void CharacterRosterMenu_Open(void)
{
    struct ListMenuTemplate menuTemplate;
    const struct CharacterInfo *character = GetActiveCharacter();
    struct ListMenuItem *items = NULL;
    u8 windowId, headerId, inputTaskId;
    u8 iconWinId = ROSTER_NO_WINDOW;
    u16 count, i;

    // The START-menu row is gated on InCharacterMode(), so this is unreachable
    // in a normal game -- but a script or a debug warp could still get here.
    if (character == NULL)
        return;

    HideMapNamePopUpWindow();
    LoadMessageBoxAndBorderGfx();

    headerId = AddWindow(&sRosterHeaderWindow);
    DrawStdWindowFrame(headerId, FALSE);
    RosterMenu_DrawHeader(headerId, character);

    windowId = AddWindow(&sRosterMenuWindow);
    DrawStdWindowFrame(windowId, FALSE);

    count = CharacterMode_GetRosterSize(character);

    if (count != 0)
    {
        // Names point straight into gSpeciesNames -- the table is fixed-width
        // and terminated, so there is nothing to compose and no scratch buffer
        // to size. Only the {name, id} array is allocated.
        items = Alloc(count * sizeof(struct ListMenuItem));
        if (items == NULL)
            count = 0;
    }

    // Only frame the icon when there will BE an icon: an empty roster draws
    // no sprite, and an empty framed box would read as a missing graphic.
    if (count != 0)
    {
        iconWinId = AddWindow(&sRosterIconWindow);
        DrawStdWindowFrame(iconWinId, FALSE);
        FillWindowPixelBuffer(iconWinId, PIXEL_FILL(1));
        CopyWindowToVram(iconWinId, 3);
    }

    ScriptContext2_Enable();   // freeze the field while the overlay is up
    inputTaskId = CreateTask(RosterMenu_HandleInput, 3);
    gTasks[inputTaskId].tListTaskId = TASK_NONE;
    gTasks[inputTaskId].tWindowId = windowId;
    gTasks[inputTaskId].tHeaderId = headerId;
    gTasks[inputTaskId].tIconSprite = MAX_SPRITES;
    gTasks[inputTaskId].tIconWinId = iconWinId;
    SetRosterItems(inputTaskId, items);

    if (count == 0)
    {
        // Defensive: every ROWE roster is non-empty, but the ports are not all
        // like that (Lazarus has 17 empty rosters, Seaglass 3), and this screen
        // is the thing being ported. An empty list menu is not a safe object,
        // so say so in words and let B close it.
        FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
        AddTextPrinterParameterized(windowId, 1, sText_RosterEmpty, 0, 1, 0, NULL);
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            items[i].name = gSpeciesNames[character->roster[i]];
            items[i].id = character->roster[i];
        }

        // No LoadMonIconPalettes() here -- see RosterMenu_MoveCursor, which
        // loads exactly the one palette the highlighted row needs.
        menuTemplate = sRosterMenuTemplate;
        menuTemplate.items = items;
        menuTemplate.totalItems = count;
        menuTemplate.maxShowed = (count < ROSTER_MENU_ROWS) ? count : ROSTER_MENU_ROWS;
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
        gTasks[inputTaskId].tListTaskId = ListMenuInit(&menuTemplate, 0, 0);
    }

    CopyWindowToVram(windowId, 3);
}

void Task_OpenCharacterRosterMenu(u8 taskId)
{
    CharacterRosterMenu_Open();
    DestroyTask(taskId);
}

// Read-only screen: A and B both close it. There is nothing to choose, so
// treating A as "confirm" would only invite the player to expect an action.
static void RosterMenu_HandleInput(u8 taskId)
{
    if (gTasks[taskId].tListTaskId != TASK_NONE)
    {
        if (ListMenu_ProcessInput(gTasks[taskId].tListTaskId) != LIST_NOTHING_CHOSEN
            || JOY_NEW(B_BUTTON))
            RosterMenu_Destroy(taskId);
    }
    else if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
    {
        RosterMenu_Destroy(taskId);
    }
}

static void RosterMenu_Destroy(u8 taskId)
{
    struct ListMenuItem *items = GetRosterItems(taskId);

    if (gTasks[taskId].tListTaskId != TASK_NONE)
    {
        DestroyListMenuTask(gTasks[taskId].tListTaskId, NULL, NULL);
        // Frees the sprite AND the one icon palette it holds. Not
        // FreeMonIconPalettes(): this screen never loaded them all, so it
        // frees only the one it did load.
        RosterMenu_DestroyIcon(taskId);
    }

    if (items != NULL)
        Free(items);

    ClearStdWindowAndFrame(gTasks[taskId].tWindowId, TRUE);
    RemoveWindow(gTasks[taskId].tWindowId);
    ClearStdWindowAndFrame(gTasks[taskId].tHeaderId, TRUE);
    RemoveWindow(gTasks[taskId].tHeaderId);
    if (gTasks[taskId].tIconWinId != ROSTER_NO_WINDOW)
    {
        ClearStdWindowAndFrame(gTasks[taskId].tIconWinId, TRUE);
        RemoveWindow(gTasks[taskId].tIconWinId);
    }
    DestroyTask(taskId);
    ScriptContext2_Disable();
}

#undef tListTaskId
#undef tWindowId
#undef tHeaderId
#undef tIconSprite
#undef tItemsHi
#undef tItemsLo
#undef tIconWinId
#undef tIconSpecies
