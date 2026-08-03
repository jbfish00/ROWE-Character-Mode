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

// Which roll, if any, produced the wild Pokemon the player is about to fight.
// Read by battle_message.c to pick the intro string, and by nothing else.
//
// This exists because a 10% override that returns a family ROOT is invisible:
// rosters store canonical family bases, so the override hands you a Gible, and
// a wild Gible is exactly what the map's own table might have produced anyway.
// Platinum shipped the identical feature, a playthrough reported "no on-roster
// encounters", and there was no bug -- naming the character in the message is
// the whole fix. Message only: the rates are not this feature's business.
#define CHAR_WILD_ENCOUNTER_NORMAL     0
#define CHAR_WILD_ENCOUNTER_ROSTER     1  // the 10% roster override fired
#define CHAR_WILD_ENCOUNTER_LEGENDARY  2  // the 1% legendary roll fired

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
    u8 selectable;          // 0 = present but NOT offerable. The 2026-07-25
                            // roster audit drops characters with fewer than 6
                            // fully-evolved obtainable Pokemon (unless one is
                            // legendary), but a save stores the character
                            // INDEX -- deleting the row would silently
                            // repoint every existing save at a different
                            // character, so the row stays and the menu skips
                            // it instead.
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
// outKind (may be NULL) reports WHICH roll produced the species, so a caller
// that is about to start a battle can label it. It is only ever written when
// the return value is a real species -- see CHAR_WILD_ENCOUNTER_* above.
u16 CharacterMode_RollWildOverrideSpecies(u8 level, u8 *outKind);
// The encounter kind belongs to the BATTLE, not to the roll. The roll runs per
// encounter ATTEMPT -- repel, Keen Eye and the self-test's 4000-trial loops all
// call it with no battle in sight -- so the kind is recorded next to the mon's
// creation and cleared by every other path that makes a wild mon.
void CharacterMode_SetWildEncounterKind(u8 kind);
u8 CharacterMode_GetWildEncounterKind(void);
// The 1% legendary encounter roll, and the pool it draws from. The pool builder
// is public so a test can assert the POSITIVE direction deterministically --
// a 1% event otherwise hides a test that cannot fail.
u16 CharacterMode_RollWildLegendarySpecies(u8 level);
u8 CharacterMode_BuildLegendaryPool(u8 level, u16 *out, u8 outCount,
                                   bool8 *outRepeatable);
void CharacterMode_RunBootSelftest(void);
void CharacterMode_PumpTestMailbox(void);

#endif // GUARD_CHARACTER_MODE_H
