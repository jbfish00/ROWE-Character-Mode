// Character Mode roster/appearance table.
// PLACEHOLDER for wiring development - will be regenerated from Bulbapedia
// data by tools/character_mode/ scripts.

static const u16 sRoster_Steven[] =
{
    SPECIES_BELDUM, SPECIES_ARON, SPECIES_BALTOY, SPECIES_LILEEP,
    SPECIES_ANORITH, SPECIES_SKARMORY,
    SPECIES_NONE,
};

static const u16 sRoster_Cynthia[] =
{
    SPECIES_GIBLE, SPECIES_SPIRITOMB, SPECIES_BUDEW, SPECIES_RIOLU,
    SPECIES_EEVEE, SPECIES_TOGEPI,
    SPECIES_NONE,
};

static const u16 sRoster_Ash[] =
{
    SPECIES_PICHU, SPECIES_BULBASAUR, SPECIES_CHARMANDER, SPECIES_SQUIRTLE,
    SPECIES_CATERPIE, SPECIES_PIDGEY, SPECIES_KRABBY, SPECIES_MUK,
    SPECIES_TAUROS, SPECIES_LAPRAS,
    SPECIES_NONE,
};

static const u8 sName_Steven[] = _("Steven");
static const u8 sName_Cynthia[] = _("Cynthia");
static const u8 sName_Ash[] = _("Ash");

const struct CharacterInfo gCharacters[] =
{
    {
        .name = sName_Steven,
        .roster = sRoster_Steven,
        .owGfxId = OBJ_EVENT_GFX_STEVEN,
        .trainerFrontPic = TRAINER_PIC_STEVEN,
        .backPic = TRAINER_BACK_PIC_STEVEN,
    },
    {
        .name = sName_Cynthia,
        .roster = sRoster_Cynthia,
        .owGfxId = CHAR_ASSET_NONE,
        .trainerFrontPic = CHAR_ASSET_NONE,
        .backPic = CHAR_ASSET_NONE_U8,
    },
    {
        .name = sName_Ash,
        .roster = sRoster_Ash,
        .owGfxId = CHAR_ASSET_NONE,
        .trainerFrontPic = CHAR_ASSET_NONE,
        .backPic = CHAR_ASSET_NONE_U8,
    },
};

#define NUM_CHARACTERS (ARRAY_COUNT(gCharacters))
