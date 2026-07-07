#ifndef GUARD_CHARACTER_MODE_H
#define GUARD_CHARACTER_MODE_H

#include "global.h"

// Sentinels for characters with no dedicated art (fall back to costume).
#define CHAR_ASSET_NONE     0xFFFF
#define CHAR_ASSET_NONE_U8  0xFF

struct CharacterInfo
{
    const u8 *name;         // display name, charmap-encoded
    const u16 *roster;      // base-stage species, SPECIES_NONE-terminated
    u16 owGfxId;            // OBJ_EVENT_GFX_* or CHAR_ASSET_NONE
    u16 trainerFrontPic;    // TRAINER_PIC_* or CHAR_ASSET_NONE
    u8 backPic;             // TRAINER_BACK_PIC_* or CHAR_ASSET_NONE_U8
};

extern const struct CharacterInfo gCharacters[];

u16 GetCharacterCount(void);
bool8 InCharacterMode(void);
const struct CharacterInfo *GetActiveCharacter(void);
bool8 IsSpeciesAllowedForCharacter(u16 species);
void CharacterMode_SweepPartyToPC(void);
u16 CharacterMode_GetRosterSize(const struct CharacterInfo *character);

#endif // GUARD_CHARACTER_MODE_H
