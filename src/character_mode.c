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
