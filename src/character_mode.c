#include "global.h"
#include "character_mode.h"
#include "event_data.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "level_scaling.h"
#include "constants/species.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/event_objects.h"
#include "constants/trainers.h"

#include "data/characters.h"

u16 GetCharacterCount(void)
{
    return NUM_CHARACTERS;
}

bool8 InCharacterMode(void)
{
    return FlagGet(FLAG_CHARACTER_MODE) && VarGet(VAR_CHARACTER_ID) != 0
        && VarGet(VAR_CHARACTER_ID) <= NUM_CHARACTERS;
}

const struct CharacterInfo *GetActiveCharacter(void)
{
    if (!InCharacterMode())
        return NULL;
    return &gCharacters[VarGet(VAR_CHARACTER_ID) - 1];
}

// The character whose SPRITES the player wears. A costume from the Pokemon Center
// overrides the one you are playing as -- a costume changes how you look, while
// VAR_CHARACTER_ID still decides your roster. Roster code must keep calling
// GetActiveCharacter(); only appearance code calls this.
const struct CharacterInfo *GetAppearanceCharacter(void)
{
    u16 costume = VarGet(VAR_COSTUME_CHARACTER);

    if (costume == COSTUME_CHARACTER_BASE)
        return NULL;    // wearing a base outfit on purpose; don't let the character override it
    if (costume != 0 && costume <= NUM_CHARACTERS)
        return &gCharacters[costume - 1];
    return GetActiveCharacter();
}

// Only characters with overworld art can be worn -- the other 81 have no sprite
// to put on the map, and handing their id to the avatar code draws garbage.
bool8 CharacterHasOverworldSprite(u16 index)
{
    if (index >= NUM_CHARACTERS)
        return FALSE;
    return gCharacters[index].owGfxId != CHAR_ASSET_NONE;
}

u16 CharacterMode_GetRosterSize(const struct CharacterInfo *character)
{
    u16 count = 0;

    while (character->roster[count] != SPECIES_NONE)
        count++;
    return count;
}

// A species is allowed if the base stage of its evolution family is on the
// active character's roster (rosters store base stages only, so whole
// families are always allowed together).
bool8 IsSpeciesAllowedForCharacter(u16 species)
{
    const struct CharacterInfo *character = GetActiveCharacter();
    u16 base;
    u32 i;

    if (character == NULL)
        return TRUE;
    if (species == SPECIES_NONE || species >= NUM_SPECIES)
        return FALSE;

    base = GetFirstEvolution(GetBaseFormSpeciesId(species));
    for (i = 0; character->roster[i] != SPECIES_NONE; i++)
    {
        if (character->roster[i] == base)
            return TRUE;
    }
    return FALSE;
}

bool8 CharacterMode_PartyHasAllowedMon(void)
{
    u32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);

        if (species != SPECIES_NONE
            && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, NULL)
            && IsSpeciesAllowedForCharacter(species))
            return TRUE;
    }
    return FALSE;
}

// Move every off-roster party member to the PC. Never leaves the party
// empty: if all members are off-roster, slot 0 is kept. Mons stay in the
// party if the boxes are full.
void CharacterMode_SweepPartyToPC(void)
{
    u32 i;
    bool8 keptOne = FALSE;

    if (!InCharacterMode())
        return;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);

        if (species == SPECIES_NONE)
            continue;
        if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, NULL)
            || IsSpeciesAllowedForCharacter(species))
        {
            keptOne = TRUE;
            continue;
        }
    }

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);

        if (species == SPECIES_NONE
            || GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG, NULL)
            || IsSpeciesAllowedForCharacter(species))
            continue;
        if (!keptOne)
        {
            keptOne = TRUE; // never empty the party
            continue;
        }
        if (SendMonToPC(&gPlayerParty[i]) != MON_CANT_GIVE)
            ZeroMonData(&gPlayerParty[i]);
    }

    CompactPartySlots();
    CalculatePlayerPartyCount();
}

// Special. Character Mode hands the player their character's starter the moment the mode
// is committed (ui_mode_menu.c: ScriptGiveMon(GetStarterAt(starterselection), ...)), so the
// intro must NOT go on to offer the generic starter menu -- doing so handed out a second,
// off-roster mon (Red walked out with Pikachu AND Meowth, and the party sweep had already
// run, so the Meowth stayed).
// NB this tree's `specialvar` uses the special's RETURN VALUE
// (scrcmd.c: *var = gSpecials[...]()), not gSpecialVar_Result. A void special that only
// writes gSpecialVar_Result hands the script whatever happened to be in r0.
u8 IsPlayerInCharacterMode(void)
{
    return InCharacterMode();
}
