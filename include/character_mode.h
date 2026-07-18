#ifndef GUARD_CHARACTER_MODE_H
#define GUARD_CHARACTER_MODE_H

#include "global.h"

// Sentinels for characters with no dedicated art (fall back to costume).
#define CHAR_ASSET_NONE     0xFFFF
#define CHAR_ASSET_NONE_U8  0xFF

// VAR_COSTUME_CHARACTER: 0 = no costume chosen, so the character you are PLAYING AS supplies
// the sprite (Character Mode's default). 1..N = wearing that character. The sentinel below =
// you explicitly picked one of the base outfits, so no character sprite should be worn at all
// -- without it, picking "Emerald" while playing as Red silently did nothing, because the
// active character always won.
#define COSTUME_CHARACTER_BASE  0xFFFF

struct CharacterInfo
{
    const u8 *name;         // display name, charmap-encoded
    const u16 *roster;      // base-stage species, SPECIES_NONE-terminated
    u16 owGfxId;            // OBJ_EVENT_GFX_* or CHAR_ASSET_NONE
    u16 trainerFrontPic;    // TRAINER_PIC_* or CHAR_ASSET_NONE
    u8 backPic;             // TRAINER_BACK_PIC_* or CHAR_ASSET_NONE_U8
    u8 generation;          // debut generation, 1-9 (menu grouping)
    u8 starterCount;        // leading roster entries offerable as starters
                            // (legendaries sort to the tail; 0 = no filter)
    u8 hasSignature;        // roster[0] is the character's known ace/starter
};

extern const struct CharacterInfo gCharacters[];

u16 GetCharacterCount(void);
bool8 InCharacterMode(void);
const struct CharacterInfo *GetActiveCharacter(void);
const struct CharacterInfo *GetAppearanceCharacter(void);
bool8 CharacterHasOverworldSprite(u16 index);
u16 CharacterMode_FamilyBase(u16 species);
bool8 IsSpeciesAllowedForCharacter(u16 species);
void CharacterMode_SweepPartyToPC(void);
bool8 CharacterMode_PartyHasAllowedMon(void);
u16 CharacterMode_GetRosterSize(const struct CharacterInfo *character);
bool8 CharacterMode_IsLegendaryOrMythical(u16 species);
u16 CharacterMode_PickEvolutionStageForLevel(u16 species, u8 level);
u16 CharacterMode_RollWildOverrideSpecies(u8 level);
void CharacterMode_RunBootSelftest(void);
void CharacterMode_PumpTestMailbox(void);

#endif // GUARD_CHARACTER_MODE_H
