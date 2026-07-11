const struct BattleMove gBattleMoves[MOVES_COUNT] =
{
    [MOVE_NONE] =
    {
        .effect = EFFECT_HIT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_POUND] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_KARATE_CHOP] =
    {
        .effect = EFFECT_BRICK_BREAK,
        .power = 50,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DOUBLE_SLAP] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_COMET_PUNCH] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MEGA_PUNCH] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PAY_DAY] =
    {
        .effect = EFFECT_PAY_DAY,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FIRE_PUNCH] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 75,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ICE_PUNCH] =
    {
        .effect = EFFECT_FREEZE_HIT,
        .power = 75,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_THUNDER_PUNCH] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 75,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SCRATCH] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_VICE_GRIP] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_GUILLOTINE] =
    {
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 30,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_RAZOR_WIND] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #endif
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 110,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SWORDS_DANCE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 20,
        #else
            .pp = 30,
        #endif
        .effect = EFFECT_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_DANCE,
        .split = SPLIT_STATUS,
    },

    [MOVE_CUT] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_GUST] =
    {
        .effect = EFFECT_GUST,
        .power = 40,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_IN_AIR | FLAG_WIND_BASED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_WING_ATTACK] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_WHIRLWIND] =
    {
        .effect = EFFECT_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .split = SPLIT_STATUS,
        .accuracy = 0,
        .flags = FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_WIND_BASED,
    },

    [MOVE_FLY] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 110,
        #else
            .power = 70,
        #endif
        .effect = EFFECT_SEMI_INVULNERABLE,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BIND] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 85,
        #else
            .accuracy = 75,
        #endif
        .effect = EFFECT_TRAP,
        .power = 15,
        .type = TYPE_NORMAL,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SLAM] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_VINE_WHIP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 45,
            .pp = 25,
        #elif B_UPDATED_MOVE_DATA >= GEN_4
            .power = 35,
            .pp = 15,
        #else
            .power = 35,
            .pp = 10,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STOMP] =
    {
        .effect = EFFECT_FLINCH_MINIMIZE_HIT,
        .power = 65,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_MINIMIZE | FLAG_STRIKER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DOUBLE_KICK] =
    {
        .effect = EFFECT_DOUBLE_HIT,
        .power = 30,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_STRIKER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MEGA_KICK] =
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_STRIKER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_JUMP_KICK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 100,
            .pp = 10,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 85,
            .pp = 25,
        #else
            .power = 70,
            .pp = 25,
        #endif
        .effect = EFFECT_RECOIL_IF_MISS,
        .type = TYPE_FIGHTING,
        .accuracy = 95,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST | FLAG_STRIKER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ROLLING_KICK] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 85,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRIKER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SAND_ATTACK] =
    {
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEADBUTT] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HORN_ATTACK] =
    {
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FURY_ATTACK] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HORN_DRILL] =
    {
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 30,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TACKLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 40,
            .accuracy = 100,
        #elif B_UPDATED_MOVE_DATA >= GEN_5
            .power = 50,
            .accuracy = 100,
        #else
            .power = 35,
            .accuracy = 95,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_NORMAL,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BODY_SLAM] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 85,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_MINIMIZE,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_WRAP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 90,
        #else
            .accuracy = 85,
        #endif
        .effect = EFFECT_TRAP,
        .power = 15,
        .type = TYPE_NORMAL,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TAKE_DOWN] =
    {
        .effect = EFFECT_RECOIL_25,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_THRASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 120,
            .pp = 10,
        #else
            .power = 90,
            .pp = 20,
        #endif
        .effect = EFFECT_RAMPAGE,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DOUBLE_EDGE] =
    {
        .effect = EFFECT_RECOIL_33,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TAIL_WHIP] =
    {
        .effect = EFFECT_DEFENSE_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_POISON_STING] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 15,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TWINEEDLE] =
    {
        .effect = EFFECT_TWINEEDLE,
        .power = 35,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PIN_MISSILE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 25,
            .accuracy = 95,
        #else
            .power = 14,
            .accuracy = 85,
        #endif
        .effect = EFFECT_MULTI_HIT,
        .type = TYPE_BUG,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LEER] =
    {
        .effect = EFFECT_DEFENSE_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BITE] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_GROWL] =
    {
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_ROAR] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 0,
            .flags = FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND | FLAG_MAGICCOAT_AFFECTED,
        #elif B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 100,
            .flags = FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND | FLAG_MAGICCOAT_AFFECTED,
        #else
            .accuracy = 100,
            .flags = FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        #endif
        .effect = EFFECT_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .split = SPLIT_STATUS,
    },

    [MOVE_SING] =
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 55,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_SUPERSONIC] =
    {
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 55,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_SONIC_BOOM] =
    {
        .effect = EFFECT_SONICBOOM,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DISABLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .accuracy = 80,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .accuracy = 55,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_DISABLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ACID] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        #else
            .effect = EFFECT_DEFENSE_DOWN_HIT,
        #endif
        .power = 40,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_EMBER] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 40,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FLAMETHROWER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
        #else
            .power = 95,
        #endif
        .effect = EFFECT_BURN_HIT,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MIST] =
    {
        .effect = EFFECT_MIST,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_WATER_GUN] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HYDRO_PUMP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 110,
        #else
            .power = 120,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_WATER,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SURF] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
            .target = MOVE_TARGET_FOES_AND_ALLY,
        #elif B_UPDATED_MOVE_DATA >= GEN_4
            .power = 95,
            .target = MOVE_TARGET_FOES_AND_ALLY,
        #else
            .power = 95,
            .target = MOVE_TARGET_BOTH,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_UNDERWATER,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ICE_BEAM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
        #else
            .power = 95,
        #endif
        .effect = EFFECT_FREEZE_HIT,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BLIZZARD] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 110,
        #else
            .power = 120,
        #endif
        .effect = EFFECT_FREEZE_HIT,
        .type = TYPE_ICE,
        .accuracy = 70,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_WIND_BASED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PSYBEAM] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 65,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BUBBLE_BEAM] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_AURORA_BEAM] =
    {
        .effect = EFFECT_ATTACK_DOWN_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HYPER_BEAM] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 150,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PECK] =
    {
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DRILL_PECK] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SUBMISSION] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 20,
        #else
            .pp = 25,
        #endif
        .effect = EFFECT_RECOIL_25,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 80,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LOW_KICK] =
    {
        .effect = EFFECT_LOW_KICK,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_COUNTER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_COUNTER,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = -5,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SEISMIC_TOSS] =
    {
        .effect = EFFECT_LEVEL_DAMAGE,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STRENGTH] =
    {
        .effect = EFFECT_ATTACK_UP_HIT,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },  

    [MOVE_ABSORB] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 25,
        #else
            .pp = 20,
        #endif
        .effect = EFFECT_ABSORB,
        .power = 20,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MEGA_DRAIN] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 15,
        #else
            .pp = 10,
        #endif
        .effect = EFFECT_ABSORB,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_LEECH_SEED] =
    {
        .effect = EFFECT_LEECH_SEED,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_GROWTH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 20,
        #else
            .pp = 40,
        #endif
        .effect = EFFECT_GROWTH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_RAZOR_LEAF] =
    {
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_GRASS,
        .accuracy = 95,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SOLAR_BEAM] =
    {
        .effect = EFFECT_SOLARBEAM,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POISON_POWDER] =
    {
        .effect = EFFECT_POISON,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 75,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
    },

    [MOVE_STUN_SPORE] =
    {
        .effect = EFFECT_PARALYZE,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 75,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
    },

    [MOVE_SLEEP_POWDER] =
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 75,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
    },

    [MOVE_PETAL_DANCE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 120,
            .pp = 10,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 90,
            .pp = 20,
        #else
            .power = 70,
            .pp = 20,
        #endif
        .effect = EFFECT_RAMPAGE,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DANCE,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_STRING_SHOT] =
    {
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_DRAGON_RAGE] =
    {
        .effect = EFFECT_DRAGON_RAGE,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FIRE_SPIN] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 35,
            .accuracy = 85,
        #else
            .power = 15,
            .accuracy = 70,
        #endif
        .effect = EFFECT_TRAP,
        .type = TYPE_FIRE,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_THUNDER_SHOCK] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 40,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_THUNDERBOLT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
        #else
            .power = 95,
        #endif
        .effect = EFFECT_PARALYZE_HIT,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_THUNDER_WAVE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .accuracy = 90,
        #else
            .accuracy = 100,
        #endif
        .effect = EFFECT_PARALYZE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_THUNDER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 110,
        #else
            .power = 120,
        #endif
        .effect = EFFECT_THUNDER,
        .type = TYPE_ELECTRIC,
        .accuracy = 70,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_HIT_IN_AIR,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ROCK_THROW] =
    {
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_EARTHQUAKE] =
    {
        .effect = EFFECT_EARTHQUAKE,
        .power = 100,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_UNDERGROUND,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FISSURE] =
    {
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 30,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_DMG_UNDERGROUND,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DIG] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 80,
        #else
            .power = 60,
        #endif
        .effect = EFFECT_SEMI_INVULNERABLE,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TOXIC] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 90,
        #else
            .accuracy = 85,
        #endif
        .effect = EFFECT_TOXIC,
        .power = 0,
        .type = TYPE_POISON,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_CONFUSION] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 50,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PSYCHIC] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 90,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HYPNOSIS] =
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 60,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_MEDITATE] =
    {
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_AGILITY] =
    {
        .effect = EFFECT_SPEED_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_QUICK_ATTACK] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_RAGE] =
    {
        .effect = EFFECT_RAGE,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TELEPORT] =
    {
        .effect = EFFECT_TELEPORT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = -6,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_NIGHT_SHADE] =
    {
        .effect = EFFECT_LEVEL_DAMAGE,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MIMIC] =
    {
        .effect = EFFECT_MIMIC,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SCREECH] =
    {
        .effect = EFFECT_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_DOUBLE_TEAM] =
    {
        .effect = EFFECT_EVASION_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_RECOVER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 10,
        #else
            .pp = 20,
        #endif
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HARDEN] =
    {
        .effect = EFFECT_DEFENSE_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_MINIMIZE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 10,
        #else
            .pp = 20,
        #endif
        .effect = EFFECT_MINIMIZE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SMOKESCREEN] =
    {
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_CONFUSE_RAY] =
    {
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_WITHDRAW] =
    {
        .effect = EFFECT_DEFENSE_UP,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_DEFENSE_CURL] =
    {
        .effect = EFFECT_DEFENSE_CURL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BARRIER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 20,
        #else
            .pp = 30,
        #endif
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_LIGHT_SCREEN] =
    {
        .effect = EFFECT_LIGHT_SCREEN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HAZE] =
    {
        .effect = EFFECT_HAZE,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_REFLECT] =
    {
        .effect = EFFECT_REFLECT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FOCUS_ENERGY] =
    {
        .effect = EFFECT_FOCUS_ENERGY,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BIDE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 0,
            .priority = 1,
        #else
            .accuracy = 100,
            .priority = 0,
        #endif
        .effect = EFFECT_BIDE,
        .power = 1,
        .type = TYPE_NORMAL,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_METRONOME] =
    {
        .effect = EFFECT_METRONOME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_MIRROR_MOVE] =
    {
        .effect = EFFECT_MIRROR_MOVE,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_SELF_DESTRUCT] =
    {
        .effect = EFFECT_EXPLOSION,
        .power = 200,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_EGG_BOMB] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LICK] =
    {
        .power = 40,
        .effect = EFFECT_PARALYZE_HIT,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SMOG] =
    {
        .power = 35,
        .effect = EFFECT_POISON_HIT,
        .type = TYPE_POISON,
        .accuracy = 90,
        .pp = 20,
        .secondaryEffectChance = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SLUDGE] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 65,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BONE_CLUB] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 65,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 20,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_HIT_IN_AIR,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FIRE_BLAST] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 120,
        #else
            .power = 110,
        #endif
        .effect = EFFECT_BURN_HIT,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_WATERFALL] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .effect = EFFECT_FLINCH_HIT,
        #else
            .effect = EFFECT_HIT,
        #endif
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CLAMP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 85,
            .pp = 15,
        #else
            .accuracy = 75,
            .pp = 10,
        #endif
        .effect = EFFECT_TRAP,
        .power = 35,
        .type = TYPE_WATER,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SWIFT] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SKULL_BASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 130,
            .pp = 10,
        #else
            .power = 100,
            .pp = 15,
        #endif
        .effect = EFFECT_SKULL_BASH,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SPIKE_CANNON] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CONSTRICT] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AMNESIA] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_KINESIS] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 80,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_SOFT_BOILED] =
    {
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HI_JUMP_KICK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 130,
            .pp = 10,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 100,
            .pp = 20,
        #else
            .power = 85,
            .pp = 20,
        #endif
        .effect = EFFECT_RECOIL_IF_MISS,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST | FLAG_STRIKER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_GLARE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 90,
        #else
            .accuracy = 75,
        #endif
        .effect = EFFECT_PARALYZE,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_DREAM_EATER] =
    {
        .effect = EFFECT_DREAM_EATER,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POISON_GAS] =
    {
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 90,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .effect = EFFECT_POISON,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BARRAGE] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LEECH_LIFE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 80,
            .pp = 10,
        #else
            .power = 20,
            .pp = 15,
        #endif
        .effect = EFFECT_ABSORB,
        .type = TYPE_BUG,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LOVELY_KISS] =
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SKY_ATTACK] =
    {
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_FLINCH,
    },

    [MOVE_TRANSFORM] =
    {
        .effect = EFFECT_TRANSFORM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_BUBBLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 40,
        #else
            .power = 20,
        #endif
        .effect = EFFECT_SPEED_DOWN_HIT,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DIZZY_PUNCH] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SPORE] =
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
    },

    [MOVE_FLASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 100,
        #else
            .accuracy = 70,
        #endif
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_PSYWAVE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 100,
        #else
            .accuracy = 80,
        #endif
        .effect = EFFECT_PSYWAVE,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SPLASH] =
    {
        .effect = EFFECT_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ACID_ARMOR] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 20,
        #else
            .pp = 40,
        #endif
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_CRABHAMMER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 100,
            .accuracy = 90,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 90,
            .accuracy = 90,
        #else
            .power = 90,
            .accuracy = 85,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_WATER,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_EXPLOSION] =
    {
        .effect = EFFECT_EXPLOSION,
        .power = 250,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FURY_SWIPES] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 18,
        .type = TYPE_NORMAL,
        .accuracy = 80,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BONEMERANG] =
    {
        .effect = EFFECT_DOUBLE_HIT,
        .power = 50,
        .type = TYPE_GROUND,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED  | FLAG_HIT_IN_AIR,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_REST] =
    {
        .effect = EFFECT_REST,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ROCK_SLIDE] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 75,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HYPER_FANG] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_STRONG_JAW_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SHARPEN] =
    {
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_CONVERSION] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_CONVERSION,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_TRI_ATTACK] =
    {
        .effect = EFFECT_TRI_ATTACK,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SUPER_FANG] =
    {
        .effect = EFFECT_SUPER_FANG,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SLASH] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SUBSTITUTE] =
    {
        .effect = EFFECT_SUBSTITUTE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_STRUGGLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 0,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #else
            .accuracy = 100,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #endif
        .effect = EFFECT_RECOIL_25,
        .power = 50,
        .type = TYPE_NORMAL,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SKETCH] =
    {
        .effect = EFFECT_SKETCH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_TRIPLE_KICK] =
    {
        .effect = EFFECT_TRIPLE_KICK,
        .power = 25,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_STRIKER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_THIEF] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 60,
            .pp = 25,
        #else
            .power = 40,
            .pp = 10,
        #endif
        .effect = EFFECT_THIEF,
        .type = TYPE_DARK,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SPIDER_WEB] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .flags = FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_MIND_READER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 0,
        #else
            .accuracy = 100,
        #endif
        .effect = EFFECT_LOCK_ON,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_NIGHTMARE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 100,
        #else
            .accuracy = 0,
        #endif
        .effect = EFFECT_NIGHTMARE,
        .power = 0,
        .type = TYPE_GHOST,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FLAME_WHEEL] =
    {
        .effect = EFFECT_THAW_HIT,
        .power = 60,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SNORE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 50,
        #else
            .power = 40,
        #endif
        .effect = EFFECT_SNORE,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_CURSE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .type = TYPE_GHOST,
        #else
            .type = TYPE_MYSTERY,
        #endif
        .effect = EFFECT_CURSE,
        .power = 0,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_FLAIL] =
    {
        .effect = EFFECT_FLAIL,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CONVERSION_2] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .target = MOVE_TARGET_USER,
        #else
            .target = MOVE_TARGET_FOES_AND_ALLY,
        #endif
        .effect = EFFECT_CONVERSION_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_AEROBLAST] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_COTTON_SPORE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 100,
            .target = MOVE_TARGET_BOTH,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 100,
            .target = MOVE_TARGET_FOES_AND_ALLY,
        #else
            .accuracy = 85,
            .target = MOVE_TARGET_FOES_AND_ALLY,
        #endif
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_GRASS,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
    },

    [MOVE_REVERSAL] =
    {
        .effect = EFFECT_FLAIL,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SPITE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_SPITE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_POWDER_SNOW] =
    {
        .effect = EFFECT_FREEZE_HIT,
        .power = 40,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PROTECT] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
    },

    [MOVE_MACH_PUNCH] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SCARY_FACE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 100,
        #else
            .accuracy = 90,
        #endif
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FAINT_ATTACK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SWEET_KISS] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .type = TYPE_FAIRY,
        #else
            .type = TYPE_NORMAL,
        #endif
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .accuracy = 75,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BELLY_DRUM] =
    {
        .effect = EFFECT_BELLY_DRUM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SLUDGE_BOMB] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 90,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MUD_SLAP] =
    {
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .power = 20,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_OCTAZOOKA] =
    {
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST | FLAG_BALLISTIC | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SPIKES] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAGICCOAT_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_SPIKES,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ZAP_CANNON] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 120,
        #else
            .power = 100,
        #endif
        .effect = EFFECT_PARALYZE_HIT,
        .type = TYPE_ELECTRIC,
        .accuracy = 50,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FORESIGHT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 0,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
        #elif B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 0,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_FORESIGHT,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_DESTINY_BOND] =
    {
        .effect = EFFECT_DESTINY_BOND,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_PERISH_SONG] =
    {
        .effect = EFFECT_PERISH_SONG,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_ICY_WIND] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 55,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_WIND_BASED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DETECT] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
    },

    [MOVE_BONE_RUSH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 90,
        #else
            .accuracy = 80,
        #endif
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_GROUND,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIT_IN_AIR,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LOCK_ON] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 100,
        #else
            .accuracy = 0,
        #endif
        .effect = EFFECT_LOCK_ON,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_OUTRAGE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 120,
            .pp = 10,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 120,
            .pp = 15,
        #else
            .power = 90,
            .pp = 15,
        #endif
        .effect = EFFECT_RAMPAGE,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SANDSTORM] =
    {
        .effect = EFFECT_SANDSTORM,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_WIND_BASED,
        .split = SPLIT_STATUS,
    },

    [MOVE_GIGA_DRAIN] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 75,
            .pp = 10,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 60,
            .pp = 10,
        #else
            .power = 60,
            .pp = 5,
        #endif
        .effect = EFFECT_ABSORB,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ENDURE] =
    {
        .effect = EFFECT_ENDURE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
    },

    [MOVE_CHARM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .type = TYPE_FAIRY,
        #else
            .type = TYPE_NORMAL,
        #endif
        .effect = EFFECT_ATTACK_DOWN_2,
        .power = 0,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ROLLOUT] =
    {
        .effect = EFFECT_ROLLOUT,
        .power = 30,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FALSE_SWIPE] =
    {
        .effect = EFFECT_FALSE_SWIPE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SWAGGER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .accuracy = 85,
        #else
            .accuracy = 90,
        #endif
        .effect = EFFECT_SWAGGER,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_MILK_DRINK] =
    {
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SPARK] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FURY_CUTTER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 40,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 20,
        #else
            .power = 10,
        #endif
        .effect = EFFECT_FURY_CUTTER,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STEEL_WING] =
    {
        .effect = EFFECT_DEFENSE_UP_HIT,
        .power = 70,
        .type = TYPE_STEEL,
        .accuracy = 90,
        .pp = 25,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MEAN_LOOK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .flags = FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ATTRACT] =
    {
        .effect = EFFECT_ATTRACT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SLEEP_TALK] =
    {
        .effect = EFFECT_SLEEP_TALK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEAL_BELL] =
    {
        .effect = EFFECT_HEAL_BELL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_RETURN] =
    {
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PRESENT] =
    {
        .effect = EFFECT_HIT_ENEMY_HEAL_ALLY,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FRUSTRATION] =
    {
        .effect = EFFECT_FRUSTRATION,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SAFEGUARD] =
    {
        .effect = EFFECT_SAFEGUARD,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_PAIN_SPLIT] =
    {
        .effect = EFFECT_PAIN_SPLIT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SACRED_FIRE] =
    {
        .effect = EFFECT_THAW_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MAGNITUDE] =
    {
        .effect = EFFECT_MAGNITUDE,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_UNDERGROUND,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DYNAMIC_PUNCH] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 50,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MEGAHORN] =
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_BUG,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DRAGON_BREATH] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BATON_PASS] =
    {
        .effect = EFFECT_BATON_PASS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ENCORE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_ENCORE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_PURSUIT] =
    {
        .effect = EFFECT_PURSUIT,
        .power = 40,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_RAPID_SPIN] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 50,
        #else
            .power = 20,
        #endif
        .effect = EFFECT_RAPID_SPIN,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SWEET_SCENT] =
    {
        .effect = EFFECT_EVASION_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_IRON_TAIL] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 75,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_METAL_CLAW] =
    {
        .effect = EFFECT_ATTACK_UP_HIT,
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 95,
        .pp = 35,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_VITAL_THROW] =
    {
        .effect = EFFECT_VITAL_THROW,
        .power = 70,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MORNING_SUN] =
    {
        .effect = EFFECT_MORNING_SUN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SYNTHESIS] =
    {
        .effect = EFFECT_SYNTHESIS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_MOONLIGHT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .type = TYPE_FAIRY,
        #else
            .type = TYPE_NORMAL,
        #endif
        .effect = EFFECT_MOONLIGHT,
        .power = 0,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HIDDEN_POWER] =
    {
        .effect = EFFECT_HIDDEN_POWER,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_CROSS_CHOP] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TWISTER] =
    {
        .effect = EFFECT_TWISTER,
        .power = 40,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_IN_AIR | FLAG_WIND_BASED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_RAIN_DANCE] =
    {
        .effect = EFFECT_RAIN_DANCE,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_SUNNY_DAY] =
    {
        .effect = EFFECT_SUNNY_DAY,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_CRUNCH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .effect = EFFECT_DEFENSE_DOWN_HIT,
        #else
            .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        #endif
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MIRROR_COAT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_PROTECT_AFFECTED,
        #else
            .flags = FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_MIRROR_COAT,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = -5,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PSYCH_UP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_PSYCH_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_EXTREME_SPEED] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 2,
        #else
            .priority = 1,
        #endif
        .effect = EFFECT_SPEED_UP_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ANCIENT_POWER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #endif
        .effect = EFFECT_ALL_STATS_UP_HIT,
        .power = 60,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SHADOW_BALL] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FUTURE_SIGHT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 120,
            .accuracy = 100,
            .pp = 10,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 100,
            .accuracy = 100,
            .pp = 10,
        #else
            .power = 80,
            .accuracy = 90,
            .pp = 15,
        #endif
        .effect = EFFECT_FUTURE_SIGHT,
        .type = TYPE_PSYCHIC,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ROCK_SMASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 40,
        #else
            .power = 20,
        #endif
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_WHIRLPOOL] =
    {
        .power = 50,
        .accuracy = 100,
        .effect = EFFECT_TRAP,
        .type = TYPE_WATER,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_UNDERWATER,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BEAT_UP] =
    {
        .effect = EFFECT_BEAT_UP,
        #if B_BEAT_UP_DMG >= GEN_5
            .power = 1,
        #else
            .power = 10,
        #endif
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FAKE_OUT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #endif
        .effect = EFFECT_FAKE_OUT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 3,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_UPROAR] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 90,
        #else
            .power = 50,
        #endif
        .effect = EFFECT_UPROAR,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_STOCKPILE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 20,
        #else
            .pp = 10,
        #endif
        .effect = EFFECT_STOCKPILE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SPIT_UP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 1,
        #else
            .power = 100,
        #endif
        .effect = EFFECT_SPIT_UP,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SWALLOW] =
    {
        .effect = EFFECT_SWALLOW,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEAT_WAVE] =
    {
        .power = 95,
        .effect = EFFECT_BURN_HIT,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_WIND_BASED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HAIL] =
    {
        .effect = EFFECT_HAIL,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_TORMENT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_TORMENT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_FLATTER] =
    {
        .effect = EFFECT_FLATTER,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_WILL_O_WISP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 85,
        #else
            .accuracy = 75,
        #endif
        .effect = EFFECT_WILL_O_WISP,
        .power = 0,
        .type = TYPE_FIRE,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_MEMENTO] =
    {
        .effect = EFFECT_MEMENTO,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FACADE] =
    {
        .effect = EFFECT_FACADE,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FOCUS_PUNCH] =
    {
        .effect = EFFECT_FOCUS_PUNCH,
        .power = 150,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -3,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SMELLING_SALT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 70,
        #else
            .power = 60,
        #endif
        .effect = EFFECT_SMELLINGSALT,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_PARALYSIS,
    },

    [MOVE_FOLLOW_ME] =
    {
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 2,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_NATURE_POWER] =
    {
        .effect = EFFECT_NATURE_POWER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_CHARGE] =
    {
        .effect = EFFECT_CHARGE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_TAUNT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED,
        #endif
        .effect = EFFECT_TAUNT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_HELPING_HAND] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .target = MOVE_TARGET_ALLY,
        #else
            .target = MOVE_TARGET_USER,
        #endif
        .effect = EFFECT_HELPING_HAND,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 5,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_TRICK] =
    {
        .effect = EFFECT_TRICK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ROLE_PLAY] =
    {
        .effect = EFFECT_ROLE_PLAY,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_WISH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_WISH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ASSIST] =
    {
        .effect = EFFECT_ASSIST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_INGRAIN] =
    {
        .effect = EFFECT_INGRAIN,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SUPERPOWER] =
    {
        .effect = EFFECT_SUPERPOWER,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MAGIC_COAT] =
    {
        .effect = EFFECT_MAGIC_COAT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 4,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_RECYCLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_RECYCLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_REVENGE] =
    {
        .effect = EFFECT_REVENGE,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -4,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BRICK_BREAK] =
    {
        .effect = EFFECT_BRICK_BREAK,
        .power = 75,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_YAWN] =
    {
        .effect = EFFECT_YAWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_KNOCK_OFF] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 65,
        #else
            .power = 20,
        #endif
        .effect = EFFECT_KNOCK_OFF,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ENDEAVOR] =
    {
        .effect = EFFECT_ENDEAVOR,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ERUPTION] =
    {
        .effect = EFFECT_ERUPTION,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SKILL_SWAP] =
    {
        .effect = EFFECT_SKILL_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_IMPRISON] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_SNATCH_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED,
        #endif
        .effect = EFFECT_IMPRISON,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_REFRESH] =
    {
        .effect = EFFECT_REFRESH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_GRUDGE] =
    {
        .effect = EFFECT_GRUDGE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SNATCH] =
    {
        .effect = EFFECT_SNATCH,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 4,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SECRET_POWER] =
    {
        .effect = EFFECT_HIDDEN_POWER,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DIVE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 110,
        #else
            .power = 60,
        #endif
        .effect = EFFECT_SEMI_INVULNERABLE,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ARM_THRUST] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CAMOUFLAGE] =
    {
        .effect = EFFECT_CAMOUFLAGE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_TAIL_GLOW] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_UP_3,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_LUSTER_PURGE] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MIST_BALL] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_BALLISTIC | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FEATHER_DANCE] =
    {
        .effect = EFFECT_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_DANCE,
        .split = SPLIT_STATUS,
    },

    [MOVE_TEETER_DANCE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_DANCE,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_DANCE,
        #endif
        .effect = EFFECT_TEETER_DANCE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_BLAZE_KICK] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 85,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HIGH_CRIT | FLAG_SHEER_FORCE_BOOST | FLAG_STRIKER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MUD_SPORT] =
    {
        .effect = EFFECT_MUD_SPORT,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ICE_BALL] =
    {
        .effect = EFFECT_ROLLOUT,
        .power = 30,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_NEEDLE_ARM] =
    {
        .effect = EFFECT_FLINCH_MINIMIZE_HIT,
        .power = 95,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SLACK_OFF] =
    {
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HYPER_VOICE] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POISON_FANG] =
    {
        .effect = EFFECT_POISON_FANG,
        .power = 75,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
		.secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CRUSH_CLAW] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 75,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BLAST_BURN] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HYDRO_CANNON] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 150,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_METEOR_MASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
            .accuracy = 90,
        #else
            .power = 100,
            .accuracy = 85,
        #endif
        .effect = EFFECT_ATTACK_UP_HIT,
        .type = TYPE_STEEL,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ASTONISH] =
    {
        .effect = EFFECT_FLINCH_MINIMIZE_HIT,
        .power = 30,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_WEATHER_BALL] =
    {
        .effect = EFFECT_WEATHER_BALL,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_AROMATHERAPY] =
    {
        .effect = EFFECT_HEAL_BELL,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FAKE_TEARS] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_AIR_CUTTER] =
    {
        .power = 60,
        .effect = EFFECT_HIT,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT | FLAG_WIND_BASED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_OVERHEAT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 130,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #elif B_UPDATED_MOVE_DATA >= GEN_4
            .power = 130,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #else
            .power = 140,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #endif
        .effect = EFFECT_OVERHEAT,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ODOR_SLEUTH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 0,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
        #else
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_FORESIGHT,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ROCK_TOMB] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 60,
            .accuracy = 95,
            .pp = 15,
        #else
            .power = 50,
            .accuracy = 80,
            .pp = 10,
        #endif
        .effect = EFFECT_SPEED_DOWN_HIT,
        .type = TYPE_ROCK,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SILVER_WIND] =
    {
        .effect = EFFECT_ALL_STATS_UP_HIT,
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_WIND_BASED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_METAL_SOUND] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_GRASS_WHISTLE] =
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 55,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_TICKLE] =
    {
        .effect = EFFECT_TICKLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_COSMIC_POWER] =
    {
        .effect = EFFECT_COSMIC_POWER,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_WATER_SPOUT] =
    {
        .effect = EFFECT_ERUPTION,
        .power = 150,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SIGNAL_BEAM] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 75,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SHADOW_PUNCH] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_EXTRASENSORY] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 20,
        #else
            .pp = 30,
        #endif
        .effect = EFFECT_FLINCH_MINIMIZE_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SKY_UPPERCUT] =
    {
        .effect = EFFECT_SKY_UPPERCUT,
        .power = 85,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_HIT_IN_AIR,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SAND_TOMB] =
    {
        .power = 50,
        .accuracy = 100,
        .effect = EFFECT_TRAP,
        .type = TYPE_GROUND,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SHEER_COLD] =
    {
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_ICE,
        .accuracy = 30,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MUDDY_WATER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
        #else
            .power = 95,
        #endif
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BULLET_SEED] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 25,
        #else
            .power = 10,
        #endif
        .effect = EFFECT_MULTI_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AERIAL_ACE] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ICICLE_SPEAR] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 25,
        #else
            .power = 10,
        #endif
        .effect = EFFECT_MULTI_HIT,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_IRON_DEFENSE] =
    {
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BLOCK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .flags = FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_HOWL] =
    {
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_DRAGON_CLAW] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FRENZY_PLANT] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 150,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BULK_UP] =
    {
        .effect = EFFECT_BULK_UP,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BOUNCE] =
    {
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 85,
        .type = TYPE_FLYING,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_PARALYSIS,
    },

    [MOVE_MUD_SHOT] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 55,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POISON_TAIL] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_COVET] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 60,
            .pp = 25,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 60,
            .pp = 40,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 40,
            .pp = 40,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .power = 40,
            .pp = 40,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_THIEF,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_VOLT_TACKLE] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 90,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MAGICAL_LEAF] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_WATER_SPORT] =
    {
        .effect = EFFECT_WATER_SPORT,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_CALM_MIND] =
    {
        .effect = EFFECT_CALM_MIND,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_LEAF_BLADE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 90,
        #else
            .power = 70,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DRAGON_DANCE] =
    {
        .effect = EFFECT_DRAGON_DANCE,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_DANCE,
        .split = SPLIT_STATUS,
    },

    [MOVE_ROCK_BLAST] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 90,
        #else
            .accuracy = 80,
        #endif
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_ROCK,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SHOCK_WAVE] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_WATER_PULSE] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DOOM_DESIRE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 140,
            .accuracy = 100,
        #else
            .power = 120,
            .accuracy = 85,
        #endif
        .effect = EFFECT_FUTURE_SIGHT,
        .type = TYPE_STEEL,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PSYCHO_BOOST] =
    {
        .effect = EFFECT_OVERHEAT,
        .power = 140,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ROOST] =
    {
        .effect = EFFECT_ROOST,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_GRAVITY] =
    {
        .effect = EFFECT_GRAVITY,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_MIRACLE_EYE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_MIRACLE_EYE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_WAKE_UP_SLAP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 70,
        #else
            .power = 60,
        #endif
        .effect = EFFECT_WAKE_UP_SLAP,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_SLEEP,
    },

    [MOVE_HAMMER_ARM] =
    {
        .effect = EFFECT_HAMMER_ARM,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_GYRO_BALL] =
    {
        .effect = EFFECT_GYRO_BALL,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HEALING_WISH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_HEALING_WISH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_BRINE] =
    {
        .effect = EFFECT_BRINE,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_NATURAL_GIFT] =
    {
        .effect = EFFECT_NATURAL_GIFT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FEINT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 30,
            .flags = FLAG_MIRROR_MOVE_AFFECTED,
        #elif B_UPDATED_MOVE_DATA >= GEN_5
            .power = 30,
            .flags = 0,
        #else
            .power = 50,
            .flags = 0,
        #endif
        .effect = EFFECT_FEINT,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 2,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PLUCK] =
    {
        .effect = EFFECT_BUG_BITE,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TAILWIND] =
    {
        .pp = 15,
        .effect = EFFECT_TAILWIND,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_WIND_BASED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ACUPRESSURE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = 0,
        #else
            .flags = FLAG_SNATCH_AFFECTED,
        #endif
        .effect = EFFECT_ACUPRESSURE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER | MOVE_TARGET_ALLY,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_METAL_BURST] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_METAL_BURST,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_U_TURN] =
    {
        .effect = EFFECT_HIT_ESCAPE,
        .power = 70,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CLOSE_COMBAT] =
    {
        .effect = EFFECT_CLOSE_COMBAT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PAYBACK] =
    {
        .effect = EFFECT_PAYBACK,
        .power = 50,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ASSURANCE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 60,
        #else
            .power = 50,
        #endif
        .effect = EFFECT_ASSURANCE,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_EMBARGO] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_EMBARGO,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_FLING] =
    {
        .effect = EFFECT_FLING,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PSYCHO_SHIFT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 100,
        #else
            .accuracy = 90,
        #endif
        .effect = EFFECT_PSYCHO_SHIFT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_TRUMP_CARD] =
    {
        .effect = EFFECT_TRUMP_CARD,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HEAL_BLOCK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_HEAL_BLOCK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_WRING_OUT] =
    {
        .effect = EFFECT_WRING_OUT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POWER_TRICK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_POWER_TRICK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_GASTRO_ACID] =
    {
        .effect = EFFECT_GASTRO_ACID,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_LUCKY_CHANT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_LUCKY_CHANT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ME_FIRST] =
    {
        .effect = EFFECT_ME_FIRST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_COPYCAT] =
    {
        .effect = EFFECT_COPYCAT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_POWER_SWAP] =
    {
        .effect = EFFECT_POWER_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_GUARD_SWAP] =
    {
        .effect = EFFECT_GUARD_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_PUNISHMENT] =
    {
        .effect = EFFECT_PUNISHMENT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LAST_RESORT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 140,
        #else
            .power = 130,
        #endif
        .effect = EFFECT_LAST_RESORT,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_WORRY_SEED] =
    {
        .effect = EFFECT_WORRY_SEED,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SUCKER_PUNCH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 70,
        #else
            .power = 80,
        #endif
        .effect = EFFECT_SUCKER_PUNCH,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_IRON_FIST_BOOST| FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TOXIC_SPIKES] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAGICCOAT_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_TOXIC_SPIKES,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEART_SWAP] =
    {
        .effect = EFFECT_HEART_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_AQUA_RING] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_AQUA_RING,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_MAGNET_RISE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_MAGNET_RISE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_FLARE_BLITZ] =
    {
        .effect = EFFECT_RECOIL_33_STATUS,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_BURN,
    },

    [MOVE_FORCE_PALM] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AURA_SPHERE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 80,
        #else
            .power = 90,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ROCK_POLISH] =
    {
        .effect = EFFECT_SPEED_UP_2,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_POISON_JAB] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 80,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DARK_PULSE] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_NIGHT_SLASH] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AQUA_TAIL] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SEED_BOMB] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AIR_SLASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 15,
        #else
            .pp = 20,
        #endif
        .effect = EFFECT_FLINCH_HIT,
        .power = 75,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_X_SCISSOR] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BUG_BUZZ] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DRAGON_PULSE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 85,
        #else
            .power = 90,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DRAGON_RUSH] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 75,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_MINIMIZE,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_POWER_GEM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 80,
        #else
            .power = 70,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DRAIN_PUNCH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 75,
            .pp = 10,
        #else
            .power = 60,
            .pp = 5,
        #endif
        .effect = EFFECT_ABSORB,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_VACUUM_WAVE] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FOCUS_BLAST] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 70,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ENERGY_BALL] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
        #else
            .power = 80,
        #endif
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_BALLISTIC | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BRAVE_BIRD] =
    {
        .effect = EFFECT_RECOIL_33,
        .power = 120,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_EARTH_POWER] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SWITCHEROO] =
    {
        .effect = EFFECT_TRICK,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_GIGA_IMPACT] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 150,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_NASTY_PLOT] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BULLET_PUNCH] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AVALANCHE] =
    {
        .effect = EFFECT_REVENGE,
        .power = 60,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = -4,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ICE_SHARD] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SHADOW_CLAW] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_THUNDER_FANG] =
    {
        .effect = EFFECT_FLINCH_STATUS,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_PARALYSIS,
    },

    [MOVE_ICE_FANG] =
    {
        .effect = EFFECT_FLINCH_STATUS,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_FREEZE,
    },

    [MOVE_FIRE_FANG] =
    {
        .effect = EFFECT_FLINCH_STATUS,
        .power = 65,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_BURN,
    },

    [MOVE_SHADOW_SNEAK] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MUD_BOMB] =
    {
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .power = 65,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PSYCHO_CUT] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ZEN_HEADBUTT] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MIRROR_SHOT] =
    {
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .power = 65,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FLASH_CANNON] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ROCK_CLIMB] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DEFOG] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_DEFOG,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_TRICK_ROOM] =
    {
        .effect = EFFECT_TRICK_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = -7,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_DRACO_METEOR] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 130,
        #else
            .power = 140,
        #endif
        .effect = EFFECT_OVERHEAT,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DISCHARGE] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_LAVA_PLUME] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_LEAF_STORM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 130,
        #else
            .power = 140,
        #endif
        .effect = EFFECT_OVERHEAT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POWER_WHIP] =
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ROCK_WRECKER] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 150,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CROSS_POISON] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 70,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT | FLAG_BLADEMASTER_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_GUNK_SHOT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 80,
        #else
            .accuracy = 70,
        #endif
        .effect = EFFECT_POISON_HIT,
        .power = 120,
        .type = TYPE_POISON,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_IRON_HEAD] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MAGNET_BOMB] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STONE_EDGE] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ROCK,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CAPTIVATE] =
    {
        .effect = EFFECT_CAPTIVATE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_STEALTH_ROCK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAGICCOAT_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_STEALTH_ROCK,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_GRASS_KNOT] =
    {
        .effect = EFFECT_LOW_KICK,
        .power = 1,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_CHATTER] =
    {
        .power = 70,
        .effect = EFFECT_CONFUSE_HIT,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SOUND | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_JUDGMENT] =
    {
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .argument = HOLD_EFFECT_PLATE,
    },

    [MOVE_BUG_BITE] =
    {
        .effect = EFFECT_BUG_BITE,
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CHARGE_BEAM] =
    {
        .effect = EFFECT_SP_ATTACK_UP_HIT,
        .power = 50,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_WOOD_HAMMER] =
    {
        .effect = EFFECT_RECOIL_25,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AQUA_JET] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ATTACK_ORDER] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DEFEND_ORDER] =
    {
        .effect = EFFECT_COSMIC_POWER,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEAL_ORDER] =
    {
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEAD_SMASH] =
    {
        .effect = EFFECT_RECOIL_50,
        .power = 150,
        .type = TYPE_ROCK,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DOUBLE_HIT] =
    {
        .effect = EFFECT_DOUBLE_HIT,
        .power = 35,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ROAR_OF_TIME] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 150,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SPACIAL_REND] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_LUNAR_DANCE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_DANCE | FLAG_SNATCH_AFFECTED,
        #else
            .flags = FLAG_DANCE,
        #endif
        .effect = EFFECT_HEALING_WISH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_CRUSH_GRIP] =
    {
        .effect = EFFECT_WRING_OUT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MAGMA_STORM] =
    {
        .power = 100,
        .accuracy = 75,
        .effect = EFFECT_TRAP,
        .type = TYPE_FIRE,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DARK_VOID] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .accuracy = 50,
        #else
            .accuracy = 80,
        #endif
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_DARK,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SEED_FLARE] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT_2,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_OMINOUS_WIND] =
    {
        .effect = EFFECT_ALL_STATS_UP_HIT,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_WIND_BASED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SHADOW_FORCE] =
    {
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 130,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HONE_CLAWS] =
    {
        .effect = EFFECT_ATTACK_ACCURACY_UP,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_WIDE_GUARD] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 3,
        .flags = FLAG_PROTECTION_MOVE | FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TRUE, // Protects the whole side.
    },

    [MOVE_GUARD_SPLIT] =
    {
        .effect = EFFECT_GUARD_SPLIT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_POWER_SPLIT] =
    {
        .effect = EFFECT_POWER_SPLIT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_WONDER_ROOM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .priority = 0,
        #else
            .priority = -7,
        #endif
        .effect = EFFECT_WONDER_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_PSYSHOCK] =
    {
        .effect = EFFECT_PSYSHOCK,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_VENOSHOCK] =
    {
        .effect = EFFECT_VENOSHOCK,
        .power = 65,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_AUTOTOMIZE] =
    {
        .effect = EFFECT_AUTOTOMIZE,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_RAGE_POWDER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .priority = 2,
        #else
            .priority = 3,
        #endif
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_POWDER,
        .split = SPLIT_STATUS,
    },

    [MOVE_TELEKINESIS] =
    {
        .effect = EFFECT_TELEKINESIS,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_MAGIC_ROOM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .priority = 0,
        #else
            .priority = -7,
        #endif
        .effect = EFFECT_MAGIC_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_SMACK_DOWN] =
    {
        .effect = EFFECT_SMACK_DOWN,
        .power = 50,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIT_IN_AIR,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STORM_THROW] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 60,
        #else
            .power = 40,
        #endif
        .effect = EFFECT_ALWAYS_CRIT,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FLAME_BURST] =
    {
        .effect = EFFECT_FLAME_BURST,
        .power = 70,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SLUDGE_WAVE] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 95,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_QUIVER_DANCE] =
    {
        .effect = EFFECT_QUIVER_DANCE,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_DANCE,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEAVY_SLAM] =
    {
        .effect = EFFECT_HEAT_CRASH,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_MINIMIZE,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SYNCHRONOISE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 120,
            .pp = 10,
        #else
            .power = 70,
            .pp = 15,
        #endif
        .effect = EFFECT_SYNCHRONOISE,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ELECTRO_BALL] =
    {
        .effect = EFFECT_ELECTRO_BALL,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SOAK] =
    {
        .effect = EFFECT_SOAK,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FLAME_CHARGE] =
    {
        .effect = EFFECT_SPEED_UP_HIT,
        .power = 50,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_COIL] =
    {
        .effect = EFFECT_COIL,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_LOW_SWEEP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 65,
        #else
            .power = 60,
        #endif
        .effect = EFFECT_SPEED_DOWN_HIT,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ACID_SPRAY] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT_2,
        .power = 40,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FOUL_PLAY] =
    {
        .effect = EFFECT_FOUL_PLAY,
        .power = 95,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SIMPLE_BEAM] =
    {
        .effect = EFFECT_SIMPLE_BEAM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ENTRAINMENT] =
    {
        .effect = EFFECT_ENTRAINMENT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_AFTER_YOU] =
    {
        .effect = EFFECT_AFTER_YOU,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ROUND] =
    {
        .effect = EFFECT_ROUND,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ECHOED_VOICE] =
    {
        .effect = EFFECT_ECHOED_VOICE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_CHIP_AWAY] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_STAT_STAGES_IGNORED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CLEAR_SMOG] =
    {
        .effect = EFFECT_CLEAR_SMOG,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_STORED_POWER] =
    {
        .effect = EFFECT_STORED_POWER,
        .power = 20,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_QUICK_GUARD] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 3,
        .flags = FLAG_PROTECTION_MOVE | FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TRUE, // Protects the whole side.
    },

    [MOVE_ALLY_SWITCH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .priority = 2,
        #else
            .priority = 1,
        #endif
        .effect = EFFECT_ALLY_SWITCH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_SCALD] =
    {
        .effect = EFFECT_SCALD,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SHELL_SMASH] =
    {
        .effect = EFFECT_SHELL_SMASH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEAL_PULSE] =
    {
        .effect = EFFECT_HEAL_PULSE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEX] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 65,
        #else
            .power = 50,
        #endif
        .effect = EFFECT_HEX,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SKY_DROP] =
    {
        .effect = EFFECT_PLACEHOLDER, // Needs a custom move effect
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SHIFT_GEAR] =
    {
        .effect = EFFECT_SHIFT_GEAR,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_CIRCLE_THROW] =
    {
        .effect = EFFECT_HIT_SWITCH_TARGET,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_INCINERATE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 60,
        #else
            .power = 30,
        #endif
        .effect = EFFECT_INCINERATE,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_QUASH] =
    {
        .effect = EFFECT_QUASH,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ACROBATICS] =
    {
        .effect = EFFECT_ACROBATICS,
        .power = 55,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_REFLECT_TYPE] =
    {
        .effect = EFFECT_REFLECT_TYPE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_RETALIATE] =
    {
        .effect = EFFECT_RETALITATE,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FINAL_GAMBIT] =
    {
        .effect = EFFECT_FINAL_GAMBIT,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BESTOW] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .flags = FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_BESTOW,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_INFERNO] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 50,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_WATER_PLEDGE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 80,
        #else
            .power = 50,
        #endif
        .effect = EFFECT_PLEDGE,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FIRE_PLEDGE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 80,
        #else
            .power = 50,
        #endif
        .effect = EFFECT_PLEDGE,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_GRASS_PLEDGE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 80,
        #else
            .power = 50,
        #endif
        .effect = EFFECT_PLEDGE,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_VOLT_SWITCH] =
    {
        .effect = EFFECT_HIT_ESCAPE,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_STRUGGLE_BUG] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 50,
        #else
            .power = 30,
        #endif
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BULLDOZE] =
    {
        .effect = EFFECT_BULLDOZE,
        .power = 60,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FROST_BREATH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 60,
        #else
            .power = 40,
        #endif
        .effect = EFFECT_ALWAYS_CRIT,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DRAGON_TAIL] =
    {
        .effect = EFFECT_HIT_SWITCH_TARGET,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_WORK_UP] =
    {
        .effect = EFFECT_ATTACK_SPATK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ELECTROWEB] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 55,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_WILD_CHARGE] =
    {
        .effect = EFFECT_RECOIL_25,
        .power = 90,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DRILL_RUN] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DUAL_CHOP] =
    {
        .effect = EFFECT_DOUBLE_HIT,
        .power = 40,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HEART_STAMP] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 60,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HORN_LEECH] =
    {
        .effect = EFFECT_ABSORB,
        .power = 75,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SACRED_SWORD] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 15,
        #else
            .pp = 20,
        #endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_STAT_STAGES_IGNORED | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_RAZOR_SHELL] =
    {
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_HIGH_CRIT | FLAG_MIRROR_MOVE_AFFECTED | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HEAT_CRASH] =
    {
        .effect = EFFECT_HEAT_CRASH,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_MINIMIZE,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LEAF_TORNADO] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_STEAMROLLER] =
    {
        .effect = EFFECT_FLINCH_MINIMIZE_HIT,
        .power = 65,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_DMG_MINIMIZE | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_COTTON_GUARD] =
    {
        .effect = EFFECT_DEFENSE_UP_3,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_NIGHT_DAZE] =
    {
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PSYSTRIKE] =
    {
        .effect = EFFECT_PSYSHOCK,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_TAIL_SLAP] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HURRICANE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 110,
        #else
            .power = 120,
        #endif
        .effect = EFFECT_HURRICANE,
        .type = TYPE_FLYING,
        .accuracy = 70,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_HIT_IN_AIR  | FLAG_WIND_BASED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HEAD_CHARGE] =
    {
        .effect = EFFECT_RECOIL_25,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_GEAR_GRIND] =
    {
        .effect = EFFECT_DOUBLE_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SEARING_SHOT] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_TECHNO_BLAST] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 120,
        #else
            .power = 85,
        #endif
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .argument = HOLD_EFFECT_DRIVE
    },

    [MOVE_RELIC_SONG] =
    {
        .effect = EFFECT_SLEEP_HIT,   //EFFECT_SLEEP_HIT,
        .power = 75,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SECRET_SWORD] =
    {
        .effect = EFFECT_PSYSHOCK,
        .power = 85,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_GLACIATE] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BOLT_STRIKE] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 130,
        .type = TYPE_ELECTRIC,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BLUE_FLARE] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 130,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FIERY_DANCE] =
    {
        .effect = EFFECT_SP_ATTACK_UP_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DANCE | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FREEZE_SHOCK] =
    {
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_PARALYSIS,
    },

    [MOVE_ICE_BURN] =
    {
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .argument = MOVE_EFFECT_BURN,
    },

    [MOVE_SNARL] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .power = 55,
        .type = TYPE_DARK,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ICICLE_CRASH] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 85,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_V_CREATE] =
    {
        .effect = EFFECT_V_CREATE,
        .power = 180,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FUSION_FLARE] =
    {
        .effect = EFFECT_FUSION_COMBO,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FUSION_BOLT] =
    {
        .effect = EFFECT_FUSION_COMBO,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FLYING_PRESS] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 100,
        #else
            .power = 80,
        #endif
        .effect = EFFECT_TWO_TYPED_MOVE,
        .type = TYPE_FIGHTING,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_MINIMIZE,
        .split = SPLIT_PHYSICAL,
        .argument = TYPE_FLYING,
    },

    [MOVE_MAT_BLOCK] =
    {
        .effect = EFFECT_MAT_BLOCK,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TRUE, // Protects the whole side.
    },

    [MOVE_BELCH] =
    {
        .effect = EFFECT_BELCH,
        .power = 120,
        .type = TYPE_POISON,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ROTOTILLER] =
    {
        .effect = EFFECT_ROTOTILLER,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY | MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_STICKY_WEB] =
    {
        .effect = EFFECT_STICKY_WEB,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .flags = FLAG_MAGICCOAT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FELL_STINGER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 50,
        #else
            .power = 30,
        #endif
        .effect = EFFECT_FELL_STINGER,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PHANTOM_FORCE] =
    {
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 110,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_FEINT,
    },

    [MOVE_TRICK_OR_TREAT] =
    {
        .effect = EFFECT_THIRD_TYPE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TYPE_GHOST,
    },

    [MOVE_NOBLE_ROAR] =
    {
        .effect = EFFECT_NOBLE_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_ION_DELUGE] =
    {
        .effect = EFFECT_ION_DELUGE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 1,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_PARABOLIC_CHARGE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 65,
        #else
            .power = 50,
        #endif
        .effect = EFFECT_ABSORB,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FORESTS_CURSE] =
    {
        .effect = EFFECT_THIRD_TYPE,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TYPE_GRASS,
    },

    [MOVE_PETAL_BLIZZARD] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_WIND_BASED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FREEZE_DRY] =
    {
        .effect = EFFECT_FREEZE_DRY,
        .power = 70,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DISARMING_VOICE] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PARTING_SHOT] =
    {
        .effect = EFFECT_PARTING_SHOT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_TOPSY_TURVY] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .accuracy = 0,
        #else
            .accuracy = 100,
        #endif
        .effect = EFFECT_TOPSY_TURVY,
        .power = 0,
        .type = TYPE_DARK,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_DRAINING_KISS] =
    {
        .effect = EFFECT_ABSORB,
        .power = 50,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .argument = 75, // restores 75% HP instead of 50% HP
    },

    [MOVE_CRAFTY_SHIELD] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 3,
        .flags = 0,
        .split = SPLIT_STATUS,
        .argument = TRUE, // Protects the whole side.
    },

    [MOVE_FLOWER_SHIELD] =
    {
        .effect = EFFECT_FLOWER_SHIELD,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER | MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_GRASSY_TERRAIN] =
    {
        .effect = EFFECT_GRASSY_TERRAIN,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_MISTY_TERRAIN] =
    {
        .effect = EFFECT_MISTY_TERRAIN,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ELECTRIFY] =
    {
        .effect = EFFECT_ELECTRIFY,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_PLAY_ROUGH] =
    {
        .effect = EFFECT_ATTACK_DOWN_HIT,
        .power = 90,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FAIRY_WIND] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_WIND_BASED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MOONBLAST] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .power = 95,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BOOMBURST] =
    {
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FAIRY_LOCK] =
    {
        .effect = EFFECT_FAIRY_LOCK,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_KINGS_SHIELD] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
    },

    [MOVE_PLAY_NICE] =
    {
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_CONFIDE] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_DIAMOND_STORM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .effect = EFFECT_DEFENSE_UP2_HIT,
        #else
            .effect = EFFECT_DEFENSE_UP_HIT,
        #endif
        .power = 100,
        .type = TYPE_ROCK,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_STEAM_ERUPTION] =
    {
        .effect = EFFECT_SCALD,
        .power = 110,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HYPERSPACE_HOLE] =
    {
        .effect = EFFECT_FEINT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_WATER_SHURIKEN] =
    {
        #if B_WATER_SHURIKEN_SPLIT >= GEN_7
            .split = SPLIT_SPECIAL,
        #else
            .split = SPLIT_PHYSICAL,
        #endif
        .effect = EFFECT_MULTI_HIT,
        .power = 15,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
    },

    [MOVE_MYSTICAL_FIRE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 75,
        #else
            .power = 65,
        #endif
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SPIKY_SHIELD] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
    },

    [MOVE_AROMATIC_MIST] =
    {
        .effect = EFFECT_AROMATIC_MIST,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALLY,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_EERIE_IMPULSE] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_VENOM_DRENCH] =
    {
        .effect = EFFECT_VENOM_DRENCH,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_POWDER] =
    {
        .effect = EFFECT_POWDER,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
    },

    [MOVE_GEOMANCY] =
    {
        .effect = EFFECT_GEOMANCY,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_MAGNETIC_FLUX] =
    {
        .effect = EFFECT_MAGNETIC_FLUX,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HAPPY_HOUR] =
    {
        .effect = EFFECT_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ELECTRIC_TERRAIN] =
    {
        .effect = EFFECT_ELECTRIC_TERRAIN,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_DAZZLING_GLEAM] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_CELEBRATE] =
    {
        .effect = EFFECT_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_HOLD_HANDS] =
    {
        .effect = EFFECT_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALLY,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_BABY_DOLL_EYES] =
    {
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_NUZZLE] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 20,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HOLD_BACK] =
    {
        .effect = EFFECT_FALSE_SWIPE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_INFESTATION] =
    {
        .effect = EFFECT_TRAP,
        .power = 50,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POWER_UP_PUNCH] =
    {
        .effect = EFFECT_ATTACK_UP_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_OBLIVION_WING] =
    {
        .effect = EFFECT_ABSORB,
        .power = 80,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .argument = 75, // restores 75% HP instead of 50% HP
    },

    [MOVE_THOUSAND_ARROWS] =
    {
        .effect = EFFECT_SMACK_DOWN,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIT_IN_AIR,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_THOUSAND_WAVES] =
    {
        .effect = EFFECT_HIT_PREVENT_ESCAPE,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LANDS_WRATH] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LIGHT_OF_RUIN] =
    {
        .effect = EFFECT_RECOIL_50,
        .power = 140,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ORIGIN_PULSE] =
    {
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PRECIPICE_BLADES] =
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DRAGON_ASCENT] =
    {
        .effect = EFFECT_CLOSE_COMBAT,
        .power = 120,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HYPERSPACE_FURY] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SHORE_UP] =
    {
        .effect = EFFECT_SHORE_UP,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FIRST_IMPRESSION] =
    {
        .effect = EFFECT_FAKE_OUT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 2,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BANEFUL_BUNKER] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
    },

    [MOVE_SPIRIT_SHACKLE] =
    {
        .effect = EFFECT_HIT_PREVENT_ESCAPE,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DARKEST_LARIAT] =
    {
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_STAT_STAGES_IGNORED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SPARKLING_ARIA] =
    {
        .effect = EFFECT_SPARKLING_ARIA,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .argument = STATUS1_BURN,
    },

    [MOVE_ICE_HAMMER] =
    {
        .effect = EFFECT_HAMMER_ARM,
        .power = 100,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FLORAL_HEALING] =
    {
        .effect = EFFECT_HEAL_PULSE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HIGH_HORSEPOWER] =
    {
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_STRIKER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STRENGTH_SAP] =
    {
        .effect = EFFECT_STRENGTH_SAP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SOLAR_BLADE] =
    {
        .effect = EFFECT_SOLARBEAM,
        .power = 125,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LEAFAGE] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SPOTLIGHT] =
    {
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 3,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_TOXIC_THREAD] =
    {
        .effect = EFFECT_TOXIC_THREAD,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_LASER_FOCUS] =
    {
        .effect = EFFECT_LASER_FOCUS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_GEAR_UP] =
    {
        .effect = EFFECT_GEAR_UP,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_THROAT_CHOP] =
    {
        .effect = EFFECT_THROAT_CHOP,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_POLLEN_PUFF] =
    {
        .effect = EFFECT_HIT_ENEMY_HEAL_ALLY,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ANCHOR_SHOT] =
    {
        .effect = EFFECT_HIT_PREVENT_ESCAPE,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PSYCHIC_TERRAIN] =
    {
        .effect = EFFECT_PSYCHIC_TERRAIN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_LUNGE] =
    {
        .effect = EFFECT_ATTACK_DOWN_HIT,
        .power = 80,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FIRE_LASH] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_POWER_TRIP] =
    {
        .effect = EFFECT_STORED_POWER,
        .power = 20,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BURN_UP] =
    {
        .effect = EFFECT_BURN_UP,
        .power = 130,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SPEED_SWAP] =
    {
        .effect = EFFECT_SPEED_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SMART_STRIKE] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PURIFY] =
    {
        .effect = EFFECT_PURIFY,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_REVELATION_DANCE] =
    {
        .effect = EFFECT_REVELATION_DANCE,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DANCE,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_CORE_ENFORCER] =
    {
        .effect = EFFECT_CORE_ENFORCER,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_TROP_KICK] =
    {
        .effect = EFFECT_ATTACK_DOWN_HIT,
        .power = 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRIKER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_INSTRUCT] =
    {
        .effect = EFFECT_INSTRUCT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BEAK_BLAST] =
    {
		.effect = EFFECT_BEAK_BLAST,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = -3,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CLANGING_SCALES] =
    {
        .effect = EFFECT_ATTACKER_DEFENSE_DOWN_HIT,
        .power = 110,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DRAGON_HAMMER] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BRUTAL_SWING] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AURORA_VEIL] =
    {
        .effect = EFFECT_AURORA_VEIL,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SHELL_TRAP] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -3,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FLEUR_CANNON] =
    {
        .effect = EFFECT_OVERHEAT,
        .power = 130,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PSYCHIC_FANGS] =
    {
        .effect = EFFECT_BRICK_BREAK,
        .power = 75,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STOMPING_TANTRUM] =
    {
        .effect = EFFECT_STOMPING_TANTRUM,
        .power = 75,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SHADOW_BONE] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 85,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ACCELEROCK] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LIQUIDATION] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 85,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PRISMATIC_LASER] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 160,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SPECTRAL_THIEF] =
    {
        .effect = EFFECT_SPECTRAL_THIEF,
        .power = 90,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SUNSTEEL_STRIKE] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_TARGET_ABILITY_IGNORED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MOONGEIST_BEAM] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_TARGET_ABILITY_IGNORED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_TEARFUL_LOOK] =
    {
        .effect = EFFECT_NOBLE_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ZING_ZAP] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_NATURES_MADNESS] =
    {
        .effect = EFFECT_SUPER_FANG,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MULTI_ATTACK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 120,
        #else
            .power = 90,
        #endif
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = HOLD_EFFECT_MEMORY,
    },

    [MOVE_MIND_BLOWN] =
    {
        .effect = EFFECT_MIND_BLOWN,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PLASMA_FISTS] =
    {
        .effect = EFFECT_HIT, // Needs a custom move effect
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PHOTON_GEYSER] =
    {
        .effect = EFFECT_HIT, // Needs a custom move effect
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ZIPPY_ZAP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 80,
            .pp = 10,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #else
            .power = 50,
            .pp = 15,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #endif
        .effect = EFFECT_ALWAYS_CRIT,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 2,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SPLISHY_SPLASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #endif
        .effect = EFFECT_PARALYZE_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FLOATY_FALL] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
        #endif
        .effect = EFFECT_FLINCH_HIT,
        .power = 90,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PIKA_PAPOW] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #endif
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BOUNCY_BUBBLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 60,
            .pp = 20,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
            .argument = 100, // restores 100% HP instead of 50% HP
        #else
            .power = 90,
            .pp = 15,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #endif
        .effect = EFFECT_ABSORB,
        .type = TYPE_WATER,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BUZZY_BUZZ] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 60,
            .pp = 20,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #else
            .power = 90,
            .pp = 15,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #endif
        .effect = EFFECT_PARALYZE_HIT,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SIZZLY_SLIDE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 60,
            .pp = 20,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #else
            .power = 90,
            .pp = 15,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #endif
        .effect = EFFECT_BURN_HIT,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_GLITZY_GLOW] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 80,
            .accuracy = 95,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #else
            .power = 90,
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #endif
        .effect = EFFECT_PLACEHOLDER,   //TODO (Light Screen + Hit)
        .type = TYPE_PSYCHIC,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BADDY_BAD] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 80,
            .accuracy = 95,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #else
            .power = 90,
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #endif
        .effect = EFFECT_PLACEHOLDER,   //TODO (Reflect + Hit)
        .type = TYPE_DARK,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SAPPY_SEED] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 100,
            .accuracy = 90,
            .pp = 10,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #else
            .power = 90,
            .accuracy = 100,
            .pp = 15,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #endif
        .effect = EFFECT_PLACEHOLDER,   //TODO (Leech Seed + Hit)
        .type = TYPE_GRASS,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FREEZY_FROST] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 100,
            .accuracy = 90,
            .pp = 10,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #else
            .power = 90,
            .accuracy = 100,
            .pp = 15,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #endif
        .effect = EFFECT_PLACEHOLDER,   //TODO (Haze + Hit)
        .type = TYPE_ICE,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SPARKLY_SWIRL] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 120,
            .accuracy = 85,
            .pp = 5,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #else
            .power = 90,
            .accuracy = 100,
            .pp = 15,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #endif
        .effect = EFFECT_PLACEHOLDER,   //TODO (Heal Bell + Hit)
        .type = TYPE_FAIRY,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_VEEVEE_VOLLEY] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        #endif
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DOUBLE_IRON_BASH] =
    {
        .effect = EFFECT_DOUBLE_HIT,   //TODO (EFFECT_FLINCH_HIT + EFFECT_DOUBLE_HIT)
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_DMG_MINIMIZE | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    
    [MOVE_DYNAMAX_CANNON] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SNIPE_SHOT] =
    {
        .effect = EFFECT_HIT,   //TODO
        .power = 70,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST | FLAG_HIGH_CRIT | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_JAW_LOCK] =
    {
        .effect = EFFECT_JAW_LOCK,
        .power = 90,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STUFF_CHEEKS] =
    {
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_NO_RETREAT] =
    {
        .effect = EFFECT_NO_RETREAT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_TAR_SHOT] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_TAR_SHOT,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_MAGIC_POWDER] =
    {
        .effect = EFFECT_SOAK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
        .argument = TYPE_PSYCHIC,
    },

    [MOVE_DRAGON_DARTS] =
    {
        .effect = EFFECT_DOUBLE_HIT, //EFFECT_DRAGON_DARTS,
        .power = 50,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TEATIME] =
    {
        .effect = EFFECT_PLACEHOLDER,   //TODO
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_OCTOLOCK] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_OCTOLOCK,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BOLT_BEAK] =
    {
        .effect = EFFECT_BOLT_BEAK,
        .power = 85,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FISHIOUS_REND] =
    {
        .effect = EFFECT_BOLT_BEAK,
        .power = 85,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_COURT_CHANGE] =
    {
        .effect = EFFECT_PLACEHOLDER,   //TODO
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_CLANGOROUS_SOUL] =
    {
        .effect = EFFECT_CLANGOROUS_SOUL,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_BODY_PRESS] =
    {
        .effect = EFFECT_BODY_PRESS,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DECORATE] =
    {
        .effect = EFFECT_PLACEHOLDER,   // TODO .. EFFECT_DECORATE
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_DRUM_BEATING] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SNAP_TRAP] =
    {
        .effect = EFFECT_TRAP,
        .power = 50,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PYRO_BALL] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC | FLAG_STRIKER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BEHEMOTH_BLADE] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BEHEMOTH_BASH] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AURA_WHEEL] =
    {
        .effect = EFFECT_SPEED_UP_HIT,
        .power = 110,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BREAKING_SWIPE] =
    {
        .effect = EFFECT_ATTACK_DOWN_HIT,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BRANCH_POKE] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_OVERDRIVE] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_APPLE_ACID] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_GRAV_APPLE] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SPIRIT_BREAK] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .power = 75,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STRANGE_STEAM] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 90,
        .type = TYPE_FAIRY,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_LIFE_DEW] =
    {
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_OBSTRUCT] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
    },

    [MOVE_FALSE_SURRENDER] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_METEOR_ASSAULT] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 150,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ETERNABEAM] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 160,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_STEEL_BEAM] =
    {
        .effect = EFFECT_MIND_BLOWN,
        .power = 140,
        .type = TYPE_STEEL,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_EXPANDING_FORCE] =
    {
        .effect = EFFECT_EXPANDING_FORCE,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_STEEL_ROLLER] =
    {
        .effect = EFFECT_PLACEHOLDER,   //TODO
        .power = 130,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SCALE_SHOT] =
    {
        .effect = EFFECT_SCALE_SHOT,
        .power = 25,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_METEOR_BEAM] =
    {
        .effect = EFFECT_HIT,   //TODO
        .power = 85,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SHELL_SIDE_ARM] =
    {
        .effect = EFFECT_POISON,   //TODO
        .power = 90,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MISTY_EXPLOSION] =
    {
        .effect = EFFECT_EXPLOSION,  //TODO
        .power = 150,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_GRASSY_GLIDE] =
    {
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_RISING_VOLTAGE] =
    {
        .effect = EFFECT_RISING_VOLTAGE,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_TERRAIN_PULSE] =
    {
        .effect = EFFECT_HIT,   //TODO
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SKITTER_SMACK] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .power = 70,
        .type = TYPE_BUG,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BURNING_JEALOUSY] =
    {
        .effect = EFFECT_HIT,   //TODO
        .power = 70,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_LASH_OUT] =
    {
        .effect = EFFECT_HIT,   //TODO
        .power = 90,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_POLTERGEIST] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_POLTERGEIST,
        .power = 110,
        .type = TYPE_GHOST,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CORROSIVE_GAS] =
    {
        .effect = EFFECT_PLACEHOLDER,   //TODO
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_COACHING] =
    {
        .effect = EFFECT_PLACEHOLDER,   //TODO
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALLY,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_FLIP_TURN] =
    {
        .effect = EFFECT_HIT_ESCAPE,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TRIPLE_AXEL] =
    {
        .effect = EFFECT_TRIPLE_KICK,   //TODO: Increase damage by 20 instead of 10
        .power = 35,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_STRIKER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DUAL_WINGBEAT] =
    {
        .effect = EFFECT_DOUBLE_HIT,
        .power = 40,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SCORCHING_SANDS] =
    {
        .effect = EFFECT_SCALD,
        .power = 70,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_JUNGLE_HEALING] =
    {
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_WICKED_BLOW] =
    {
        .effect = EFFECT_ALWAYS_CRIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SURGING_STRIKES] =
    {
        .effect = EFFECT_MULTI_HIT,   //TODO (Multi hit + Always Crit)
        .power = 25,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_THUNDER_CAGE] =
    {
        .effect = EFFECT_TRAP,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DRAGON_ENERGY] =
    {
        .effect = EFFECT_ERUPTION,
        .power = 150,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FREEZING_GLARE] =
    {
        .power = 90,
        .effect = EFFECT_FREEZE_HIT,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FIERY_WRATH] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 90,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_THUNDEROUS_KICK] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_STRIKER_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_GLACIAL_LANCE] =
    {
        .effect = EFFECT_HIT,
        .power = 130,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ASTRAL_BARRAGE] =
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_EERIE_SPELL] =
    {
        .effect = EFFECT_EERIE_SPELL, // To do. It's a copy of Spite that inflicts damage and reduced the target's last move's PP by 3 instead of 4.
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },
// ROWEMOVE-PORT-START moves (generated by tools/character_mode/port_2x_moves.py)
    [MOVE_ALLURING_VOICE] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_WAVE_CRASH] =
    {
        .effect = EFFECT_RECOIL_33,
        .power = 120,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_GIGATON_HAMMER] =
    {
        .effect = EFFECT_HIT,
        .power = 160,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_AQUA_CUTTER] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_AQUA_STEP] =
    {
        .effect = EFFECT_SPEED_UP_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DANCE | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_ARMOR_CANNON] =
    {
        .effect = EFFECT_CLOSE_COMBAT,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_AXE_KICK] =
    {
        .power = 120,
        .pp = 10,
        .effect = EFFECT_RECOIL_IF_MISS,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_BITTER_BLADE] =
    {
        .effect = EFFECT_ABSORB,
        .power = 90,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_BLAZING_TORQUE] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_BLOOD_MOON] =
    {
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_BURNING_BULWARK] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = 0,
        .split = SPLIT_STATUS,
    },
    [MOVE_CHILLING_WATER] =
    {
        .effect = EFFECT_ATTACK_DOWN_HIT,
        .power = 50,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_CHILLY_RECEPTION] =
    {
        .effect = EFFECT_CHILLY_RECEPTION,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },
    [MOVE_COLLISION_COURSE] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_COLLISION_COURSE
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_COMBAT_TORQUE] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_COMEUPPANCE] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_REFLECT_DAMAGE
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_DOODLE] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_DOODLE
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_DOUBLE_SHOCK] =
    {
        .effect = EFFECT_BURN_UP,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_DRAGON_CHEER] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_DRAGON_CHEER
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALLY,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },
    [MOVE_ELECTRO_DRIFT] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_COLLISION_COURSE
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_ELECTRO_SHOT] =
    {
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 130,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_FICKLE_BEAM] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_FICKLE_BEAM
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_FILLET_AWAY] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_FILLET_AWAY
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_FLOWER_TRICK] =
    {
        .effect = EFFECT_ALWAYS_CRIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_GLAIVE_RUSH] =
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_HARD_PRESS] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_POWER_BASED_ON_TARGET_HP
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_HYDRO_STEAM] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_HYDRO_STEAM
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_HYPER_DRILL] =
    {
        .effect = EFFECT_HIT, //Bypasses  Protect, Detect, Spiky Shield, King's Shield, Baneful Bunker, Silk Trap, and Burning Bulwark
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_ICE_SPINNER] =
    {
        .power = 80,
        .effect = EFFECT_RAPID_SPIN,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_IVY_CUDGEL] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_IVY_CUDGEL
        .power = 100,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_JET_PUNCH] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_KOWTOW_CLEAVE] =
    {
        //Hit + No Guard
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_LAST_RESPECTS] =
    {
        .power = 50,
        .effect = EFFECT_HIT,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = 0,
    },
    [MOVE_LUMINA_CRASH] =
    {
        //Hit + Lowers Special Defense x2
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_MAGICAL_TORQUE] =
    {
        //Quest Move
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_MAKE_IT_RAIN] =
    {
        .power = 120,
        .effect = EFFECT_OVERHEAT,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_MALIGNANT_CHAIN] =
    {
        //Hit + Toxic Poison
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_MATCHA_GOTCHA] =
    {
        //Effect + Burn
        .effect = EFFECT_ABSORB,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_MIGHTY_CLEAVE] =
    {
        //Hit + Ignore Protect
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_MORTAL_SPIN] =
    {
        //Rapid Spin + Remove Binding moves
        .effect = EFFECT_RAPID_SPIN,
        .power = 30,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_NOXIOUS_TORQUE] =
    {
        //Quest Move
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_ORDER_UP] =
    {
        //Commander Stuff
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_POPULATION_BOMB] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_POUNCE] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 50,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_PSYBLADE] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = 0,
    },
    [MOVE_PSYCHIC_NOISE] =
    {
        //Hit + Heal Block
        .effect = EFFECT_HIT,
        .power = 75,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_RAGE_FIST] =
    {
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = 0,
    },
    [MOVE_RAGING_BULL] =
    {
        .effect = EFFECT_BRICK_BREAK,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_REVIVAL_BLESSING] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_REVIVAL_BLESSING
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },
    [MOVE_RUINATION] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_FIXED_PERCENT_DAMAGE
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_SALT_CURE] =
    {
        //Hit + 1/8 damage per turn effect
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_SHED_TAIL] =
    {
        .effect = EFFECT_SHED_TAIL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },
    [MOVE_SILK_TRAP] =
    {
        //Silk Trap + Lower Speed
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = 0,
        .split = SPLIT_STATUS,
    },
    [MOVE_SNOWSCAPE] =
    {
        .effect = EFFECT_HAIL,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },
    [MOVE_SPICY_EXTRACT] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_SPICY_EXTRACT
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_SPIN_OUT] =
    {
        //Hit + Lower user speed
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_SUPERCELL_SLAM] =
    {
        .effect = EFFECT_RECOIL_IF_MISS,
        .power = 100,
        .pp = 10,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_MINIMIZE,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_SYRUP_BOMB] =
    {
        //Hit + Speed Down each turn for 3 turns
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_TACHYON_CUTTER] =
    {
        .effect = EFFECT_DOUBLE_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BLADEMASTER_BOOST,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_TEMPER_FLARE] =
    {
        .effect = EFFECT_STOMPING_TANTRUM,
        .power = 75,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_TERA_BLAST] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_TERA_BLAST
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_TERA_STARSTORM] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_TERA_STARSTORM
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_THUNDERCLAP] =
    {
        .effect = EFFECT_SUCKER_PUNCH,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_TIDY_UP] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_TIDY_UP
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },
    [MOVE_TRAILBLAZE] =
    {
        .effect = EFFECT_SPEED_UP_HIT,
        .power = 50,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_TRIPLE_DIVE] =
    {
        .effect = EFFECT_TRIPLE_KICK,
        .power = 30,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_TWIN_BEAM] =
    {
        .effect = EFFECT_DOUBLE_HIT,
        .power = 40,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_UPPER_HAND] =
    {
        .effect = EFFECT_PLACEHOLDER, //EFFECT_UPPER_HAND
        .power = 65,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 3,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_WICKED_TORQUE] =
    {
        //Quest Moves
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_NEUTRAL_PULSE] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_SEASONAL_BEAM] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_HIGHEST,
        .argument = 0,
    },
    [MOVE_RAGING_FURY] =
    {
        .power = 120,
        .pp = 15,
        .effect = EFFECT_RAMPAGE,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },
    [MOVE_HITONOME] =
    {
        .effect = EFFECT_METRONOME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },
    [MOVE_TRICKONOME] =
    {
        .effect = EFFECT_METRONOME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 80,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },
    [MOVE_AMPONOME] =
    {
        .effect = EFFECT_METRONOME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },
    [MOVE_WEAKONOME] =
    {
        .effect = EFFECT_METRONOME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },
    [MOVE_TORCH_SONG] =
    {
        .effect = EFFECT_SP_ATTACK_UP_HIT,
        .power = 60,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },
    [MOVE_INVERSE_ROOM] =
    {
        .effect = EFFECT_INVERSE_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = -7,
        .flags = 0,
        .split = SPLIT_STATUS,
    },
    [MOVE_BARB_BARRAGE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_BITTER_MALICE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_BLEAKWIND_STORM] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_WIND_BASED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_CEASELESS_EDGE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BLADEMASTER_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_CHLOROBLAST] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_DIRE_CLAW] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_ESPER_WING] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_HEADLONG_RUSH] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_INFERNAL_PARADE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_LUNAR_BLESSING] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_MOUNTAIN_GALE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MYSTICAL_POWER] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_POWER_SHIFT] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_PSYSHIELD_BASH] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_SANDSEAR_STORM] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_WIND_BASED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_SHELTER] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_SPRINGTIDE_STORM] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_WIND_BASED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_STONE_AXE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BLADEMASTER_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_TAKE_HEART] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_TRIPLE_ARROWS] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HIGH_CRIT | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_VICTORY_DANCE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_DANCE,
        .split = SPLIT_STATUS,
    },
    [MOVE_WILDBOLT_STORM] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_WIND_BASED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_10000000_VOLT_THUNDERBOLT] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_STATUS,
    },
    [MOVE_ACID_DOWNPOUR] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_ALL_OUT_PUMMELING] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_BLACK_HOLE_ECLIPSE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_BLOOM_DOOM] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_BREAKNECK_BLITZ] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_CATASTROPIKA] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_CLANGOROUS_SOULBLAZE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_CONTINENTAL_CRUSH] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_CORKSCREW_CRASH] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_DEVASTATING_DRAKE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_EXTREME_EVOBOOST] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },
    [MOVE_GENESIS_SUPERNOVA] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_GIGAVOLT_HAVOC] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_GUARDIAN_OF_ALOLA] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_HYDRO_VORTEX] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_INFERNO_OVERDRIVE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_LETS_SNUGGLE_FOREVER] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_LIGHT_THAT_BURNS_THE_SKY] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_TARGET_ABILITY_IGNORED,
        .split = SPLIT_STATUS,
    },
    [MOVE_MALICIOUS_MOONSAULT] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_MINIMIZE,
        .split = SPLIT_STATUS,
    },
    [MOVE_MENACING_MOONRAZE_MAELSTROM] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_TARGET_ABILITY_IGNORED,
        .split = SPLIT_STATUS,
    },
    [MOVE_NEVER_ENDING_NIGHTMARE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_OCEANIC_OPERETTA] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_PULVERIZING_PANCAKE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_SAVAGE_SPIN_OUT] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_SEARING_SUNRAZE_SMASH] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_TARGET_ABILITY_IGNORED,
        .split = SPLIT_STATUS,
    },
    [MOVE_SHATTERED_PSYCHE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_SINISTER_ARROW_RAID] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_SOUL_STEALING_7_STAR_STRIKE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_SPLINTERED_STORMSHARDS] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_STOKED_SPARKSURFER] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_SUBZERO_SLAMMER] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_SUPERSONIC_SKYSTRIKE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_TECTONIC_RAGE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_TWINKLE_TACKLE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_AIRSTREAM] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_DARKNESS] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_FLARE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_FLUTTERBY] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_GEYSER] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_GUARD] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_HAILSTORM] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_KNUCKLE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_LIGHTNING] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_MINDSTORM] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_OOZE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_OVERGROWTH] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_PHANTASM] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_QUAKE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_ROCKFALL] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_STARFALL] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_STEELSPIKE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_STRIKE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_MAX_WYRMWIND] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_BEFUDDLE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_CANNONADE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_CENTIFERNO] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_CHI_STRIKE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_CUDDLE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_DEPLETION] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_DRUM_SOLO] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_TARGET_ABILITY_IGNORED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_FINALE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_FIREBALL] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_TARGET_ABILITY_IGNORED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_FOAM_BURST] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_GOLD_RUSH] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_GRAVITAS] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_HYDROSNIPE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_TARGET_ABILITY_IGNORED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_MALODOR] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_MELTDOWN] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_ONE_BLOW] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_RAPID_FLOW] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_REPLENISH] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_RESONANCE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_SANDBLAST] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_SMITE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_SNOOZE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_STEELSURGE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_STONESURGE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_STUN_SHOCK] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_SWEETNESS] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_TARTNESS] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_TERROR] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_VINE_LASH] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_VOLCALITH] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_VOLT_CRASH] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_WILDFIRE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_G_MAX_WIND_RAGE] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_STATUS,
    },
    [MOVE_PLACEHOLDER] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },
// ROWEMOVE-PORT-END moves
};

const struct SignatureMove gSignatureMoveList[NUM_SPECIES] = {
// ROWESIG-PORT-START (generated by tools/character_mode/port_2x_signature_moves.py)
    [SPECIES_BULBASAUR] =
    {
        .move = MOVE_LEECH_SEED,
        .differentDescription = TRUE,
        .description = _("Becomes a 40 BP move that seeds the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 40,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_LEECH_SEED,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_HIGHEST,
    },
    [SPECIES_IVYSAUR] =
    {
        .move = MOVE_VINE_WHIP,
        .differentDescription = TRUE,
        .description = _("Becomes a 2 hit 35 BP move that can seed the target."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_DOUBLE_HIT,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 35,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_LEECH_SEED,
        .chance3 = 15,
    },
    [SPECIES_VENUSAUR] =
    {
        .move = MOVE_SOLAR_BEAM,
        .differentDescription = TRUE,
        .description = _("Becomes a 100BP move normally and 120BP in the sun, always charges in one turn and restores 20% of the damage done as "),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_DRAIN,
        .argument3 = 20,
    },
    [SPECIES_VENUSAUR_MEGA] =
    {
        .move = MOVE_SOLAR_BEAM,
        .differentDescription = TRUE,
        .description = _("Becomes a 110BP move normally and 130BP in the sun, always charges in one turn and restores 25% of the damage done as "),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 110,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_DRAIN,
        .argument3 = 25,
    },
    [SPECIES_VENUSAUR_MEGA_G] =
    {
        .move = MOVE_SOLAR_BEAM,
        .differentDescription = TRUE,
        .description = _("Becomes a physical 110BP move normally and 130BP in the sun, always charges in one turn and restores 25% of the damage"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 110,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_DRAIN,
        .argument3 = 25,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_PHYSICAL,
    },
    [SPECIES_CHARMANDER] =
    {
        .move = MOVE_TAIL_WHIP,
        .differentDescription = TRUE,
        .description = _("Becomes a 30 BP move that burns the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 30,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_HIGHEST,
    },
    [SPECIES_CHARIZARD] =
    {
        .move = MOVE_FLAMETHROWER,
        .differentDescription = TRUE,
        .description = _("Has a 30% chance to burn the target and is super effective against Rock types."),
        .modification = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable = 30,
        .modification2 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable2 = TYPE_ROCK,
    },
    [SPECIES_CHARIZARD_MEGA_Y] =
    {
        .move = MOVE_FLAMETHROWER,
        .differentDescription = TRUE,
        .description = _("Becomes a 110BP move that has a 40% chance of burning and hits Rock types x2."),
        .modification = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable = 40,
        .modification2 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable2 = TYPE_ROCK,
        .modification3 = SIGNATURE_MOD_POWER,
        .variable3 = 110,
    },
    [SPECIES_CHARIZARD_MEGA_X] =
    {
        .move = MOVE_FLAMETHROWER,
        .differentDescription = TRUE,
        .description = _("Becomes a Fire/Dragon type move that hits Rock types x2 and uses the highest attacking stat."),
        .modification = SIGNATURE_MOD_SECOND_TYPE,
        .variable = TYPE_DRAGON,
        .modification2 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable2 = TYPE_ROCK,
        .modification3 = SIGNATURE_MOD_PSS_CHANGE,
        .variable3 = SPLIT_HIGHEST,
    },
    [SPECIES_BLASTOISE] =
    {
        .move = MOVE_HYDRO_PUMP,
        .differentDescription = TRUE,
        .description = _("Becomes a 95 Accuracy move that ignores target stat changes and becomes a launcher move."),
        .modification = SIGNATURE_MOD_ACCURACY,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_ADD_FLAG,
        .variable2 = FLAG_STAT_STAGES_IGNORED,
        .modification3 = SIGNATURE_MOD_ADD_FLAG,
        .variable3 = FLAG_MEGA_LAUNCHER_BOOST,
    },
    [SPECIES_BLASTOISE_MEGA] =
    {
        .move = MOVE_HYDRO_PUMP,
        .differentDescription = TRUE,
        .description = _("Becomes a 100 Accuracy move that ignores target stat changes and becomes a launcher move."),
        .modification = SIGNATURE_MOD_ACCURACY,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_ADD_FLAG,
        .variable2 = FLAG_STAT_STAGES_IGNORED,
        .modification3 = SIGNATURE_MOD_ADD_FLAG,
        .variable3 = FLAG_MEGA_LAUNCHER_BOOST,
    },
    [SPECIES_BLASTOISE_MEGA_G] =
    {
        .move = MOVE_HYDRO_PUMP,
        .differentDescription = TRUE,
        .description = _("Becomes a 100 Accuracy move that ignores target stat changes and becomes a launcher move."),
        .modification = SIGNATURE_MOD_ACCURACY,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_ADD_FLAG,
        .variable2 = FLAG_STAT_STAGES_IGNORED,
        .modification3 = SIGNATURE_MOD_ADD_FLAG,
        .variable3 = FLAG_MEGA_LAUNCHER_BOOST,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_PHYSICAL,
    },
    [SPECIES_CATERPIE] =
    {
        .move = MOVE_STRING_SHOT,
        .differentDescription = TRUE,
        .description = _("Becomes a 40 BP move that lowers the target speed and has a chance on infesting the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 40,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT,
        .modification3 = SIGNATURE_MOD_TARGET_STAT_DOWN,
        .variable3 = STAT_SPEED,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_INFESTATION,
        .chance4 = 30,
        .modification5 = SIGNATURE_MOD_PSS_CHANGE,
        .variable5 = SPLIT_HIGHEST,
    },
    [SPECIES_METAPOD] =
    {
        .move = MOVE_HARDEN,
        .differentDescription = TRUE,
        .description = _("Raises the Defense of the user twice."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_DEFENSE_UP_2,
    },
    [SPECIES_BUTTERFREE] =
    {
        .move = MOVE_GUST,
        .differentDescription = TRUE,
        .description = _("Becomes a 80BP move, that can poison the foe and set up tailwind to its team."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_POISON,
        .chance = 30,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 80,
        .modification3 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable3 = FIELD_SELF_SET_TAILWIND,
        .chance3 = 10,
    },
    [SPECIES_BUTTERFREE_MEGA] =
    {
        .move = MOVE_HURRICANE,
        .differentDescription = TRUE,
        .description = _("Becomes a move that can poison the foe and set up tailwind to its team and has 95% accuracy."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_POISON,
        .chance = 30,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SELF_SET_TAILWIND,
        .chance2 = 10,
        .modification3 = SIGNATURE_MOD_ACCURACY,
        .variable3 = 95,
    },
    [SPECIES_KAKUNA] =
    {
        .move = MOVE_HARDEN,
        .differentDescription = TRUE,
        .description = _("Raises the Defense of the user twice."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_DEFENSE_UP_2,
    },
    [SPECIES_BEEDRILL] =
    {
        .move = MOVE_TWINEEDLE,
        .differentDescription = TRUE,
        .description = _("Becomes a 45 BP move that hits Bug types x2 and ignores the target Defense changes."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 45,
        .modification2 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable2 = TYPE_BUG,
        .modification3 = SIGNATURE_MOD_PENETRATING,
        .variable3 = 0,
    },
    [SPECIES_BEEDRILL_MEGA] =
    {
        .move = MOVE_TWINEEDLE,
        .differentDescription = TRUE,
        .description = _("Becomes a 50 BP move that hits Bug types x2 and ignores the target Defense changes."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 50,
        .modification2 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable2 = TYPE_BUG,
        .modification3 = SIGNATURE_MOD_PENETRATING,
        .variable3 = 0,
    },
    [SPECIES_RATICATE] =
    {
        .move = MOVE_HYPER_FANG,
        .differentDescription = TRUE,
        .description = _("Becomes a 95 BP move that ignores target stat changes."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
    },
    [SPECIES_RATICATE_ALOLA] =
    {
        .move = MOVE_CRUNCH,
        .differentDescription = TRUE,
        .description = _("Becomes a 95 BP move that ignores target stat changes."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
    },
    [SPECIES_FEAROW] =
    {
        .move = MOVE_DRILL_PECK,
        .differentDescription = TRUE,
        .description = _("Becomes a 95 BP move that hits Ground types x2 and ignores target stat changes"),
        .modification = SIGNATURE_MOD_PENETRATING,
        .variable = 0,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 95,
        .modification3 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable3 = TYPE_GROUND,
    },
    [SPECIES_PICHU] =
    {
        .move = MOVE_VOLT_TACKLE,
        .differentDescription = TRUE,
        .description = _("Becomes a recoil 130 BP move that has a 20% chance of setting electric terrain and uses the highest attacking stat for"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 130,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_TERRAIN_ELECTRIC,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_RECKOIL,
        .argument3 = 35,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_HIGHEST,
    },
    [SPECIES_PIKACHU] =
    {
        .move = MOVE_VOLT_TACKLE,
        .differentDescription = TRUE,
        .description = _("Becomes a recoil 120 BP move that has a 15% chance of setting electric terrain and uses the highest attacking stat for"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 120,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_TERRAIN_ELECTRIC,
        .chance2 = 15,
        .modification3 = SIGNATURE_MOD_PSS_CHANGE,
        .variable3 = SPLIT_HIGHEST,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_RECKOIL,
        .argument4 = 25,
    },
    [SPECIES_RAICHU] =
    {
        .move = MOVE_VOLT_TACKLE,
        .differentDescription = TRUE,
        .description = _("Becomes a recoil 120 BP move that has a chance of setting electric terrain and uses the highest attacking stat for dam"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 120,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_TERRAIN_ELECTRIC,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_PSS_CHANGE,
        .variable3 = SPLIT_HIGHEST,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_RECKOIL,
        .argument4 = 25,
    },
    [SPECIES_RAICHU_MEGA_X] =
    {
        .move = MOVE_VOLT_TACKLE,
        .differentDescription = TRUE,
        .description = _("Becomes a recoil 125 BP move that has a chance of setting electric terrain, hits super effective against electric type"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 125,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_TERRAIN_ELECTRIC,
        .chance2 = 30,
        .modification3 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable3 = TYPE_ELECTRIC,
        .modification4 = SIGNATURE_MOD_ADD_FLAG,
        .variable4 = FLAG_STAT_STAGES_IGNORED,
        .modification5 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable5 = SIGNATURE_SECONDARY_EFFECT_RECKOIL,
        .argument5 = 25,
    },
    [SPECIES_RAICHU_MEGA_Y] =
    {
        .move = MOVE_VOLT_TACKLE,
        .differentDescription = TRUE,
        .description = _("Becomes an special 125 BP recoil move that has a chance of setting electric terrain, can paralyze the target and does "),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 125,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_TERRAIN_ELECTRIC,
        .chance2 = 30,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_PARALYSIS,
        .chance3 = 30,
        .modification4 = SIGNATURE_MOD_REMOVE_FLAG,
        .variable4 = FLAG_MAKES_CONTACT,
        .modification5 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable5 = SIGNATURE_SECONDARY_EFFECT_RECKOIL,
        .argument5 = 25,
    },
    [SPECIES_RAICHU_ALOLA] =
    {
        .move = MOVE_VOLT_TACKLE,
        .differentDescription = TRUE,
        .description = _("Becomes a 120 BP Electric and Psychic type move that has a 15% chance of setting electric terrain"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 120,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_TERRAIN_ELECTRIC,
        .chance2 = 15,
        .modification3 = SIGNATURE_MOD_SECOND_TYPE,
        .variable3 = TYPE_PSYCHIC,
    },
    [SPECIES_ARBOK] =
    {
        .move = MOVE_POISON_FANG,
        .differentDescription = TRUE,
        .description = _("Becomes a 95BP moves that hit steel types x2 and has a 30% chance of paralyzing the target and blocks healing for 5 tu"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable2 = TYPE_STEEL,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_PARALYSIS,
        .chance3 = 30,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_SET_HEAL_BLOCK,
    },
    [SPECIES_JIGGLYPUFF] =
    {
        .move = MOVE_SING,
        .differentDescription = TRUE,
        .description = _("Becomes a 30 BP move with 80% accuracy that makes the target sleep."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 30,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_SLEEP,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_SPECIAL,
        .modification5 = SIGNATURE_MOD_ACCURACY,
        .variable5 = 80,
    },
    [SPECIES_WIGGLYTUFF] =
    {
        .move = MOVE_HYPER_VOICE,
        .differentDescription = TRUE,
        .description = _("Becomes a 100 BP Fairy-type move that can make the target sleep."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_SLEEP,
        .chance = 20,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_FAIRY,
        .modification3 = SIGNATURE_MOD_POWER,
        .variable3 = 100,
    },
    [SPECIES_VULPIX] =
    {
        .move = MOVE_WILL_O_WISP,
        .differentDescription = TRUE,
        .description = _("Becomes a 35 BP move that burns the target and doubles in power when the target is affected by status problems."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 35,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HEX,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_SPECIAL,
    },
    [SPECIES_NINETALES] =
    {
        .move = MOVE_WILL_O_WISP,
        .differentDescription = TRUE,
        .description = _("Becomes a 45 BP move that burns the target and doubles in power when the target is affected by status problems."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 45,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HEX,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_SPECIAL,
    },
    [SPECIES_HYPNO] =
    {
        .move = MOVE_HYPNOSIS,
        .differentDescription = TRUE,
        .description = _("Becomes a 30 BP move with 85% accuracy that makes the target sleep and becomes stronger in psychic terrain."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 30,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_EXPANDING_FORCE,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_SLEEP,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_SPECIAL,
        .modification5 = SIGNATURE_MOD_ACCURACY,
        .variable5 = 85,
    },
    [SPECIES_GOLEM] =
    {
        .move = MOVE_EXPLOSION,
        .differentDescription = TRUE,
        .description = _("Becomes a Rock-type move that ignores the target defense and sets up Stealth Rock when used."),
        .modification = SIGNATURE_MOD_MODIFY_FIELD,
        .variable = FIELD_OPPONET_SET_STEALTH_ROCK,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
        .modification3 = SIGNATURE_MOD_TYPE,
        .variable3 = TYPE_ROCK,
    },
    [SPECIES_GOLEM_ALOLA] =
    {
        .move = MOVE_EXPLOSION,
        .differentDescription = TRUE,
        .description = _("Becomes an Electric-type move that ignores the target defense and sets up Electric Terrain when used."),
        .modification = SIGNATURE_MOD_MODIFY_FIELD,
        .variable = FIELD_SET_TERRAIN_ELECTRIC,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
        .modification3 = SIGNATURE_MOD_TYPE,
        .variable3 = TYPE_ELECTRIC,
    },
    [SPECIES_DUGTRIO] =
    {
        .move = MOVE_DIG,
        .differentDescription = TRUE,
        .description = _("Becomes a 35 BP move that hits the target 3 times, can flinch the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 35,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_TRIPLE_KICK,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance3 = 10,
    },
    [SPECIES_DUGTRIO_ALOLA] =
    {
        .move = MOVE_DIG,
        .differentDescription = TRUE,
        .description = _("Becomes a 35 BP move that hits the target 3 times, can lower the target speed."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 35,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_TRIPLE_KICK,
        .modification3 = SIGNATURE_MOD_TARGET_STAT_DOWN,
        .variable3 = STAT_SPEED,
        .chance3 = 10,
    },
    [SPECIES_DODUO] =
    {
        .move = MOVE_PECK,
        .differentDescription = TRUE,
        .description = _("Becomes a 40 BP move that hits the target twice, can raise the user attack."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 40,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_DOUBLE_HIT,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_ATK,
        .chance3 = 15,
    },
    [SPECIES_DODRIO] =
    {
        .move = MOVE_DRILL_PECK,
        .differentDescription = TRUE,
        .description = _("Becomes a 35 BP move that hits the target 3 times, can raise the user attack."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 35,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_TRIPLE_KICK,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_ATK,
        .chance3 = 10,
    },
    [SPECIES_MAGNETON] =
    {
        .move = MOVE_DISCHARGE,
        .differentDescription = TRUE,
        .description = _("Becomes a 35 BP move that hits the target 3 times, paralysis chances becomes 10% per hit."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 35,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_TRIPLE_KICK,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_PARALYSIS,
        .chance3 = 10,
    },
    [SPECIES_MEOWTH] =
    {
        .move = MOVE_PAY_DAY,
        .differentDescription = TRUE,
        .description = _("Becomes a 80BP move that can raise the user speed and flinch the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_SPEED,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance3 = 10,
    },
    [SPECIES_PERSIAN] =
    {
        .move = MOVE_PAY_DAY,
        .differentDescription = TRUE,
        .description = _("Becomes a 90BP move that can raise the user speed or flinch the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_SPEED,
        .chance2 = 10,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance3 = 10,
    },
    [SPECIES_MEOWTH_ALOLA] =
    {
        .move = MOVE_PAY_DAY,
        .differentDescription = TRUE,
        .description = _("Becomes a special 90BP Dark-type move that can raise Sp.Atk and uses the highest attacking stat."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_DARK,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 80,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_SPATK,
        .chance3 = 20,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_HIGHEST,
    },
    [SPECIES_PERSIAN_ALOLA] =
    {
        .move = MOVE_PAY_DAY,
        .differentDescription = TRUE,
        .description = _("Becomes a special 90BP Dark-type move that can raise Sp.Atk and uses the highest attacking stat."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_DARK,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 90,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_SPATK,
        .chance3 = 10,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_HIGHEST,
    },
    [SPECIES_MEOWTH_GALAR] =
    {
        .move = MOVE_PAY_DAY,
        .differentDescription = TRUE,
        .description = _("Becomes a 80BP Steel Type move that can raise Attack and ignores the target defense changes."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_STEEL,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 80,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_ATK,
        .chance3 = 20,
        .modification4 = SIGNATURE_MOD_PENETRATING,
        .variable4 = 0,
    },
    [SPECIES_PERRSERKER] =
    {
        .move = MOVE_PAY_DAY,
        .differentDescription = TRUE,
        .description = _("Becomes a 90BP Steel Type move that can raise Attack and ignores the target defense changes."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_STEEL,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 90,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_ATK,
        .chance3 = 10,
        .modification4 = SIGNATURE_MOD_PENETRATING,
        .variable4 = 0,
    },
    [SPECIES_PARAS] =
    {
        .move = MOVE_SLASH,
        .differentDescription = TRUE,
        .description = _("Becomes a Grass type move that has a 30% chance of seeding the target and cures the user."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_GRASS,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_LEECH_SEED,
        .chance2 = 30,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_CURE,
        .argument3 = 25,
    },
    [SPECIES_PARASECT] =
    {
        .move = MOVE_LEECH_LIFE,
        .differentDescription = TRUE,
        .description = _("Becomes a Bug/Ghost type move that has a 10% chance of cursing the target and ignores the target defense."),
        .modification = SIGNATURE_MOD_SECOND_TYPE,
        .variable = TYPE_GHOST,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_CURSE,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_PENETRATING,
        .variable3 = 0,
    },
    [SPECIES_CUBONE] =
    {
        .move = MOVE_BONEMERANG,
        .differentDescription = TRUE,
        .description = _("Gains priority in sandstorms and hits Flying-types super effectively also hits airborne targets."),
        .modification = SIGNATURE_MOD_PRIORITY,
        .variable = SIGNATURE_PRIORITY_IN_CONDITIONS,
        .chance = SIGNATURE_CONDITION_WEATHER_SAND,
        .modification2 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable2 = TYPE_FLYING,
        .modification3 = SIGNATURE_MOD_ADD_FLAG,
        .variable3 = FLAG_HIT_IN_AIR,
    },
    [SPECIES_MAROWAK] =
    {
        .move = MOVE_BONE_CLUB,
        .differentDescription = TRUE,
        .description = _("Becomes a 75BP move that gains priority in sandstorms, hits Flying-types super effectively and hits airborne targets."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 75,
        .modification2 = SIGNATURE_MOD_PRIORITY,
        .variable2 = SIGNATURE_PRIORITY_IN_CONDITIONS,
        .chance2 = SIGNATURE_CONDITION_WEATHER_SAND,
        .modification3 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable3 = TYPE_FLYING,
        .modification4 = SIGNATURE_MOD_ADD_FLAG,
        .variable4 = FLAG_HIT_IN_AIR,
    },
    [SPECIES_MAROWAK_ALOLA] =
    {
        .move = MOVE_SHADOW_BONE,
        .differentDescription = TRUE,
        .description = _("Has a 10% chance of cursing the target or raise the user attack."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_CURSE,
        .chance = 10,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_ATK,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_ADD_FLAG,
        .variable3 = FLAG_HIT_IN_AIR,
    },
    [SPECIES_EXEGGUTOR] =
    {
        .move = MOVE_SEED_BOMB,
        .differentDescription = TRUE,
        .description = _("Becomes a 100BP move that has a 25% chance to confuse and uses the user highest attacking stat."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_CONFUSION,
        .chance2 = 25,
        .modification3 = SIGNATURE_MOD_PSS_CHANGE,
        .variable3 = SPLIT_HIGHEST,
    },
    [SPECIES_EXEGGUTOR_ALOLA] =
    {
        .move = MOVE_DRAGON_HAMMER,
        .differentDescription = TRUE,
        .description = _("Becomes a 100BP move that has a 10% chance to flinch and uses the user highest attacking stat."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance2 = 10,
    },
    [SPECIES_MACHAMP] =
    {
        .move = MOVE_STRENGTH,
        .differentDescription = TRUE,
        .description = _("Becomes a 95BP move that has a 50% chance of boosting the user defense."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_DEF,
        .chance2 = 50,
    },
    [SPECIES_MACHAMP_MEGA] =
    {
        .move = MOVE_STRENGTH,
        .differentDescription = TRUE,
        .description = _("Becomes a 95BP move that hits the target attack stat rather than defense."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_DAMAGE_STAT,
        .variable2 = STAT_ATK,
    },
    [SPECIES_LICKITUNG] =
    {
        .move = MOVE_LICK,
        .differentDescription = TRUE,
        .description = _("Becomes a 75BP Normal-type move that restores 25% of the user's health."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 75,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_CURE,
        .argument2 = 25,
        .modification3 = SIGNATURE_MOD_TYPE,
        .variable3 = TYPE_NORMAL,
    },
    [SPECIES_LICKILICKY] =
    {
        .move = MOVE_ROLLOUT,
        .differentDescription = TRUE,
        .description = _("Becomes a 85BP Normal-type move that hits the target once but still doubles from defense curl."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_HIT,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 85,
        .modification3 = SIGNATURE_MOD_TYPE,
        .variable3 = TYPE_NORMAL,
    },
    [SPECIES_CLEFABLE] =
    {
        .move = MOVE_MOONBLAST,
        .differentDescription = TRUE,
        .description = _("Becomes a 100BP move that may raise the user special attack and may set up Stealth Rocks."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_OPPONET_SET_STEALTH_ROCK,
        .chance2 = 25,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_SPATK,
        .chance3 = 20,
    },
    [SPECIES_CLEFABLE_MEGA] =
    {
        .move = MOVE_MOONBLAST,
        .differentDescription = TRUE,
        .description = _("Becomes a 100BP move that may raise the user special attack and may set up Stealth Rocks."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_OPPONET_SET_STEALTH_ROCK,
        .chance2 = 25,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_SPATK,
        .chance3 = 30,
    },
    [SPECIES_VICTREEBEL] =
    {
        .move = MOVE_JAW_LOCK,
        .differentDescription = TRUE,
        .description = _("Becomes a Poison-type move traps the foe for two to five turns, doing damage each turn and has a high chance of poison"),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_TRAP,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_POISON,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_POISON,
        .chance3 = 30,
    },
    [SPECIES_VICTREEBEL_MEGA] =
    {
        .move = MOVE_JAW_LOCK,
        .differentDescription = TRUE,
        .description = _("Becomes a Poison-type move traps the foe for two to five turns, doing damage each turn and has a high chance of poison"),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_TRAP,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_POISON,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_POISON,
        .chance3 = 50,
    },
    [SPECIES_HITMONLEE] =
    {
        .move = MOVE_HI_JUMP_KICK,
        .differentDescription = TRUE,
        .description = _("Gets an accuracy of 100 and can raise speed."),
        .modification = SIGNATURE_MOD_ACCURACY,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_SPEED,
        .chance2 = 30,
    },
    [SPECIES_HITMONCHAN] =
    {
        .move = MOVE_MACH_PUNCH,
        .differentDescription = TRUE,
        .description = _("Becomes a 60BP move that ignores the target stat changes and can raise the user defense."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 60,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_DEF,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_PENETRATING,
        .variable3 = 0,
    },
    [SPECIES_HITMONTOP] =
    {
        .move = MOVE_TRIPLE_KICK,
        .differentDescription = TRUE,
        .description = _("Becomes a 35BP move that can raise Attack and removes hazards."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 35,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_ATK,
        .chance2 = 10,
        .modification3 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable3 = FIELD_SELF_REMOVE_HAZARDS,
    },
    [SPECIES_ANNIHILAPE] =
    {
        .move = MOVE_RAGE_FIST,
        .differentDescription = TRUE,
        .description = _("Now heals a portion of the damage done and can hit normal-type targets."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_DRAIN,
        .argument = 30,
        .modification2 = SIGNATURE_MOD_NEUTRAL_AGAINST_TYPE,
        .variable2 = TYPE_NORMAL,
    },
    [SPECIES_VOLTORB] =
    {
        .move = MOVE_ELECTRO_BALL,
        .differentDescription = TRUE,
        .description = _("Becomes a 70BP move that uses the user's Speed stat to calculate damage and can raise the user speed."),
        .modification = SIGNATURE_MOD_DAMAGE_STAT,
        .variable = STAT_SPEED,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 70,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_SPEED,
        .chance3 = 20,
    },
    [SPECIES_ELECTRODE] =
    {
        .move = MOVE_ELECTRO_BALL,
        .differentDescription = TRUE,
        .description = _("Becomes a 70BP move that uses the user's Speed stat to calculate damage and can raise the user speed."),
        .modification = SIGNATURE_MOD_DAMAGE_STAT,
        .variable = STAT_SPEED,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 80,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_SPEED,
        .chance3 = 10,
    },
    [SPECIES_VOLTORB_HISUI] =
    {
        .move = MOVE_ENERGY_BALL,
        .differentDescription = TRUE,
        .description = _("Becomes a 70BP move that uses the user's Speed stat to calculate damage and can raise the user speed."),
        .modification = SIGNATURE_MOD_DAMAGE_STAT,
        .variable = STAT_SPEED,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 70,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_SPEED,
        .chance3 = 20,
    },
    [SPECIES_ELECTRODE_HISUI] =
    {
        .move = MOVE_ENERGY_BALL,
        .differentDescription = TRUE,
        .description = _("Becomes a 70BP move that uses the user's Speed stat to calculate damage and can raise the user speed."),
        .modification = SIGNATURE_MOD_DAMAGE_STAT,
        .variable = STAT_SPEED,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 70,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_SPEED,
        .chance3 = 10,
    },
    [SPECIES_KOFFING] =
    {
        .move = MOVE_SMOG,
        .differentDescription = TRUE,
        .description = _("Becomes a 60BP move that has 90% chance of poisoning the target with 90 accuracy."),
        .modification = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 60,
        .modification3 = SIGNATURE_MOD_ACCURACY,
        .variable3 = 90,
    },
    [SPECIES_WEEZING] =
    {
        .move = MOVE_SMOG,
        .differentDescription = TRUE,
        .description = _("Becomes a 45BP move that has 100% chance of poisoning the target with 95 accuracy."),
        .modification = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 45,
        .modification3 = SIGNATURE_MOD_ACCURACY,
        .variable3 = 95,
    },
    [SPECIES_WEEZING_GALAR] =
    {
        .move = MOVE_SMOG,
        .differentDescription = TRUE,
        .description = _("Becomes a 45BP move that has 100% chance of poisoning the target with 95 accuracy and gains the Fairy type."),
        .modification = SIGNATURE_MOD_SECOND_TYPE,
        .variable = TYPE_FAIRY,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable2 = 100,
        .modification3 = SIGNATURE_MOD_POWER,
        .variable3 = 45,
        .modification4 = SIGNATURE_MOD_ACCURACY,
        .variable4 = 95,
    },
    [SPECIES_STARYU] =
    {
        .move = MOVE_SWIFT,
        .differentDescription = TRUE,
        .description = _("Becomes a 50BP Water-type priority move that can confuse the foe, hits a single target."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_WATER,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 50,
        .modification3 = SIGNATURE_MOD_PRIORITY,
        .variable3 = SIGNATURE_PRIORITY_ALWAYS,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_CONFUSION,
        .chance4 = 20,
        .modification5 = SIGNATURE_MOD_CHANGE_TARGET,
        .variable5 = MOVE_TARGET_SELECTED,
    },
    [SPECIES_STARMIE] =
    {
        .move = MOVE_SWIFT,
        .differentDescription = TRUE,
        .description = _("Becomes a 60BP Water-type priority move that can confuse the foe, hits a single target."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_WATER,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 60,
        .modification3 = SIGNATURE_MOD_PRIORITY,
        .variable3 = SIGNATURE_PRIORITY_ALWAYS,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_CONFUSION,
        .chance4 = 10,
        .modification5 = SIGNATURE_MOD_CHANGE_TARGET,
        .variable5 = MOVE_TARGET_SELECTED,
    },
    [SPECIES_STARMIE_MEGA] =
    {
        .move = MOVE_SWIFT,
        .differentDescription = TRUE,
        .description = _("Becomes a 70BP Physical Water-type priority move that can confuse the foe, hits a single target."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_WATER,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 70,
        .modification3 = SIGNATURE_MOD_PRIORITY,
        .variable3 = SIGNATURE_PRIORITY_ALWAYS,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_CONFUSION,
        .chance4 = 20,
        .modification5 = SIGNATURE_MOD_CHANGE_TARGET,
        .variable5 = MOVE_TARGET_SELECTED,
        .modification6 = SIGNATURE_MOD_PSS_CHANGE,
        .variable6 = SPLIT_PHYSICAL,
    },
    [SPECIES_CLOYSTER] =
    {
        .move = MOVE_SPIKE_CANNON,
        .differentDescription = TRUE,
        .description = _("Becomes a Water-type move that can set up spikes."),
        .modification = SIGNATURE_MOD_MODIFY_FIELD,
        .variable = FIELD_OPPONET_SET_SPIKES,
        .chance = 10,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_WATER,
    },
    [SPECIES_ARCANINE] =
    {
        .move = MOVE_EXTREME_SPEED,
        .differentDescription = TRUE,
        .description = _("Becomes a 70 BP Fire type move that can burn the target."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_FIRE,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 70,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance3 = 10,
    },
    [SPECIES_ARCANINE_HISUI] =
    {
        .move = MOVE_EXTREME_SPEED,
        .differentDescription = TRUE,
        .description = _("Becomes a 70 BP Rock type move that can burn the target."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_ROCK,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 70,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance3 = 10,
    },
    [SPECIES_SMOOCHUM] =
    {
        .move = MOVE_DRAINING_KISS,
        .differentDescription = TRUE,
        .description = _("Becomes a 70 BP Psychic-type move that may infatuate the target, ignores defense changes."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 70,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_INFATUATION,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_TYPE,
        .variable3 = TYPE_PSYCHIC,
        .modification4 = SIGNATURE_MOD_PENETRATING,
        .variable4 = 0,
    },
    [SPECIES_JYNX] =
    {
        .move = MOVE_DRAINING_KISS,
        .differentDescription = TRUE,
        .description = _("Becomes a 90 BP Ice-type move that may infatuate the target, ignores defense changes."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_INFATUATION,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_TYPE,
        .variable3 = TYPE_ICE,
        .modification4 = SIGNATURE_MOD_PENETRATING,
        .variable4 = 0,
    },
    [SPECIES_TAUROS] =
    {
        .move = MOVE_RAGING_BULL,
        .differentDescription = TRUE,
        .description = _("Becomes a 120 BP recoil move."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 120,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_RECKOIL,
        .argument2 = 25,
    },
    [SPECIES_TAUROS_PALDEA_AQUA] =
    {
        .move = MOVE_RAGING_BULL,
        .differentDescription = TRUE,
        .description = _("Becomes a Water-type move."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_WATER,
    },
    [SPECIES_TAUROS_PALDEA_BLAZE] =
    {
        .move = MOVE_RAGING_BULL,
        .differentDescription = TRUE,
        .description = _("Becomes a Fire-type move."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_FIRE,
    },
    [SPECIES_TAUROS_PALDEA_COMBAT] =
    {
        .move = MOVE_RAGING_BULL,
        .differentDescription = TRUE,
        .description = _("Becomes a Fighting-type move."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_FIGHTING,
    },
    [SPECIES_CHANSEY] =
    {
        .move = MOVE_SOFT_BOILED,
        .differentDescription = TRUE,
        .description = _("Has a high chance of boosting its own defense and curing its own status problems."),
        .modification = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable = STAT_DEF,
        .chance = 50,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_HEAL_STATUS,
        .chance2 = 20,
    },
    [SPECIES_BLISSEY] =
    {
        .move = MOVE_SOFT_BOILED,
        .differentDescription = TRUE,
        .description = _("Has a high chance of boosting its own defense and curing its own status problems."),
        .modification = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable = STAT_DEF,
        .chance = 50,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_HEAL_STATUS,
        .chance2 = 20,
    },
    [SPECIES_MAGIKARP] =
    {
        .move = MOVE_SPLASH,
        .differentDescription = TRUE,
        .description = _("Becomes a 20 BP move that targets both enemies and lowers their accuracy."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 20,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_ACCURACY_DOWN_HIT,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable3 = 100,
        .modification4 = SIGNATURE_MOD_CHANGE_TARGET,
        .variable4 = MOVE_TARGET_BOTH,
        .modification5 = SIGNATURE_MOD_PSS_CHANGE,
        .variable5 = SPLIT_HIGHEST,
    },
    [SPECIES_GYARADOS] =
    {
        .move = MOVE_THRASH,
        .differentDescription = TRUE,
        .description = _("Becomes a single hit 100 BP Flying-type move that does not lock the user."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_FLYING,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable3 = EFFECT_HIT,
    },
    [SPECIES_GYARADOS_MEGA] =
    {
        .move = MOVE_THRASH,
        .differentDescription = TRUE,
        .description = _("Becomes a single hit 110 BP Water-type move that does not lock the user."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 110,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_WATER,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable3 = EFFECT_HIT,
    },
    [SPECIES_LAPRAS] =
    {
        .move = MOVE_SURF,
        .differentDescription = TRUE,
        .description = _("Becomes a Water and Ice type move that can frostbite the target, does not hit allies."),
        .modification = SIGNATURE_MOD_SECOND_TYPE,
        .variable = TYPE_ICE,
        .modification2 = SIGNATURE_MOD_CHANGE_TARGET,
        .variable2 = MOVE_TARGET_BOTH,
    },
    [SPECIES_LAPRAS_MEGA] =
    {
        .move = MOVE_SURF,
        .differentDescription = TRUE,
        .description = _("Becomes a Water and Ice type move that can frostbite the target, does not hit allies."),
        .modification = SIGNATURE_MOD_SECOND_TYPE,
        .variable = TYPE_ICE,
        .modification2 = SIGNATURE_MOD_CHANGE_TARGET,
        .variable2 = MOVE_TARGET_BOTH,
    },
    [SPECIES_DITTO] =
    {
        .move = MOVE_TRANSFORM,
        .differentDescription = TRUE,
        .description = _("Becomes a Priority move."),
        .modification = SIGNATURE_MOD_PRIORITY,
        .variable = SIGNATURE_PRIORITY_ALWAYS,
    },
    [SPECIES_AERODACTYL] =
    {
        .move = MOVE_CRUNCH,
        .differentDescription = TRUE,
        .description = _("Becomes a 95 BP Flying-type move that ignores stat changes and has a higher chance of lowering the target defense."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_FLYING,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 95,
        .modification3 = SIGNATURE_MOD_ADD_FLAG,
        .variable3 = FLAG_STAT_STAGES_IGNORED,
        .modification4 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable4 = 30,
    },
    [SPECIES_AERODACTYL_MEGA] =
    {
        .move = MOVE_CRUNCH,
        .differentDescription = TRUE,
        .description = _("Becomes a 100 BP Rock-type move that ignores stat changes and has a higher chance of lowering the target defense."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_ROCK,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 100,
        .modification3 = SIGNATURE_MOD_ADD_FLAG,
        .variable3 = FLAG_STAT_STAGES_IGNORED,
        .modification4 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable4 = 40,
    },
    [SPECIES_DRAGONITE] =
    {
        .move = MOVE_EXTREME_SPEED,
        .differentDescription = TRUE,
        .description = _("Becomes a 70BP Flying type move."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_FLYING,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 70,
    },
    [SPECIES_DRAGONITE_MEGA] =
    {
        .move = MOVE_EXTREME_SPEED,
        .differentDescription = TRUE,
        .description = _("Becomes a 70BP Flying type move that restores some of the damage done to the target."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_FLYING,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 70,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_DRAIN,
        .argument3 = 25,
    },
    [SPECIES_ARTICUNO] =
    {
        .move = MOVE_BLIZZARD,
        .differentDescription = TRUE,
        .description = _("Becomes an Ice move that can hit x2 against Water-types, set up hail and has a 90% accuracy."),
        .modification = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable = TYPE_WATER,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_WEATHER_HAIL,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_ACCURACY,
        .variable3 = 90,
    },
    [SPECIES_ZAPDOS] =
    {
        .move = MOVE_THUNDER,
        .differentDescription = TRUE,
        .description = _("Becomes an Electric move that can hit x2 against Grass-types, set up electric terrain and has a 90% accuracy."),
        .modification = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable = TYPE_GRASS,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable2 = FIELD_SET_TERRAIN_ELECTRIC,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_ACCURACY,
        .variable3 = 90,
    },
    [SPECIES_MOLTRES] =
    {
        .move = MOVE_FIRE_BLAST,
        .differentDescription = TRUE,
        .description = _("Becomes a Fire move that can hit x2 against Water-types, set up Sunny Day and has a 90% accuracy."),
        .modification = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable = TYPE_WATER,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable2 = FIELD_SET_WEATHER_SUN,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_ACCURACY,
        .variable3 = 90,
    },
    [SPECIES_MEGANIUM] =
    {
        .move = MOVE_PETAL_BLIZZARD,
        .differentDescription = TRUE,
        .description = _("Becomes a special 100BP move that lowers the target's attack stat, can set up Grassy Terrain and does not hit allies."),
        .modification = SIGNATURE_MOD_TARGET_STAT_DOWN,
        .variable = STAT_ATK,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 100,
        .modification3 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable3 = FIELD_SET_TERRAIN_GRASS,
        .chance3 = 20,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_SPECIAL,
    },
    [SPECIES_MEGANIUM_MEGA] =
    {
        .move = MOVE_PETAL_BLIZZARD,
        .differentDescription = TRUE,
        .description = _("Becomes a special 110BP move that lowers the target's special defense stat, can set up misty terrain and does not hit "),
        .modification = SIGNATURE_MOD_TARGET_STAT_DOWN,
        .variable = STAT_SPDEF,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 110,
        .modification3 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable3 = FIELD_SET_TERRAIN_MISTY,
        .chance3 = 30,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_SPECIAL,
    },
    [SPECIES_TYPHLOSION] =
    {
        .move = MOVE_ERUPTION,
        .differentDescription = TRUE,
        .description = _("Can set up the sun and only goes down to 60BP."),
        .modification = SIGNATURE_MOD_OTHER,
        .variable = 0,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_WEATHER_SUN,
        .chance2 = 10,
    },
    [SPECIES_TYPHLOSION_MEGA] =
    {
        .move = MOVE_ERUPTION,
        .differentDescription = TRUE,
        .description = _("Can set up the sun and only goes down to 60BP."),
        .modification = SIGNATURE_MOD_OTHER,
        .variable = 0,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_WEATHER_SUN,
        .chance2 = 20,
    },
    [SPECIES_TYPHLOSION_HISUI] =
    {
        .move = MOVE_INFERNO,
        .differentDescription = TRUE,
        .description = _("Becomes a 75BP Ghost-type move that does extra damage to targets affected by status conditions and has a high chance o"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 75,
        .modification2 = SIGNATURE_MOD_ACCURACY,
        .variable2 = 100,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable3 = EFFECT_HIT,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance4 = 30,
    },
    [SPECIES_TYPHLOSION_HISUI_MEGA] =
    {
        .move = MOVE_INFERNO,
        .differentDescription = TRUE,
        .description = _("Becomes a 75BP Ghost-type move that does extra damage to targets affected by status conditions and has a high chance o"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_ACCURACY,
        .variable2 = 100,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable3 = EFFECT_HIT,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance4 = 30,
    },
    [SPECIES_FERALIGATR] =
    {
        .move = MOVE_JAW_LOCK,
        .differentDescription = TRUE,
        .description = _("Becomes a Water-type move that can confuse the target and can hit underwater targets."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_CONFUSION,
        .chance = 30,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_WATER,
        .modification3 = SIGNATURE_MOD_ADD_FLAG,
        .variable3 = FLAG_DMG_UNDERWATER,
    },
    [SPECIES_FERALIGATR_MEGA] =
    {
        .move = MOVE_JAW_LOCK,
        .differentDescription = TRUE,
        .description = _("Becomes a Dragon-type move that can confuse the target, does not make contact and can hit underwater targets."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_CONFUSION,
        .chance = 30,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_DRAGON,
        .modification3 = SIGNATURE_MOD_ADD_FLAG,
        .variable3 = FLAG_DMG_UNDERWATER,
        .modification4 = SIGNATURE_MOD_REMOVE_FLAG,
        .variable4 = FLAG_MAKES_CONTACT,
    },
    [SPECIES_FURRET] =
    {
        .move = MOVE_COIL,
        .differentDescription = TRUE,
        .description = _("Now also raises the speed stat and gains priority"),
        .modification = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable = STAT_SPEED,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_NORMAL,
        .modification3 = SIGNATURE_MOD_PRIORITY,
        .variable3 = SIGNATURE_PRIORITY_ALWAYS,
    },
    [SPECIES_FORRETRESS] =
    {
        .move = MOVE_GYRO_BALL,
        .differentDescription = TRUE,
        .description = _("Now also lowers the user speed and may boost the attack or defense stats."),
        .modification = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable = STAT_ATK,
        .chance = 33,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_DEF,
        .chance2 = 33,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_SPEED,
        .argument3 = TRUE,
    },
    [SPECIES_PHANPY] =
    {
        .move = MOVE_ROLLOUT,
        .differentDescription = TRUE,
        .description = _("Becomes a 65 BP single hit Ground-type move that removes the field hazards and boost the user speed."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 65,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_RAPID_SPIN,
        .modification3 = SIGNATURE_MOD_TYPE,
        .variable3 = TYPE_GROUND,
    },
    [SPECIES_DONPHAN] =
    {
        .move = MOVE_ROLLOUT,
        .differentDescription = TRUE,
        .description = _("Becomes a 80 BP single hit Ground-type move that removes the field hazards and boost the user speed."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_RAPID_SPIN,
        .modification3 = SIGNATURE_MOD_TYPE,
        .variable3 = TYPE_GROUND,
    },
    [SPECIES_TOGEKISS] =
    {
        .move = MOVE_AIR_SLASH,
        .differentDescription = TRUE,
        .description = _("Becomes a 85BP move with a 100% accuracy that may lower the target speed."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 85,
        .modification2 = SIGNATURE_MOD_ACCURACY,
        .variable2 = 100,
        .modification3 = SIGNATURE_MOD_TARGET_STAT_DOWN,
        .variable3 = STAT_SPEED,
        .chance3 = 25,
    },
    [SPECIES_MAGCARGO] =
    {
        .move = MOVE_ANCIENT_POWER,
        .differentDescription = TRUE,
        .description = _("Becomes a 40BP move that has a higher chance of boosting its stats and always burns the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 40,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable2 = 15,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_BURN,
    },
    [SPECIES_AMPHAROS] =
    {
        .move = MOVE_DISCHARGE,
        .differentDescription = TRUE,
        .description = _("Becomes a 90BP move that can set up electric terrain"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_TERRAIN_ELECTRIC,
        .chance2 = 25,
    },
    [SPECIES_AMPHAROS_MEGA] =
    {
        .move = MOVE_DISCHARGE,
        .differentDescription = TRUE,
        .description = _("Becomes a 90BP move that can set up electric terrain"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_TERRAIN_ELECTRIC,
        .chance2 = 35,
    },
    [SPECIES_SUNFLORA] =
    {
        .move = MOVE_SOLAR_BEAM,
        .differentDescription = TRUE,
        .description = _("Becomes a 100BP single turn move that restores the user's HP by half of the damage dealt and may seed the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_ABSORB,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_LEECH_SEED,
        .chance3 = 30,
    },
    [SPECIES_URSALUNA] =
    {
        .move = MOVE_TAKE_DOWN,
        .differentDescription = TRUE,
        .description = _("Becomes a 120BP Ground-Type Close Combat variant that hits both targets."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_GROUND,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 120,
        .modification3 = SIGNATURE_MOD_CHANGE_TARGET,
        .variable3 = MOVE_TARGET_BOTH,
        .modification4 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable4 = EFFECT_CLOSE_COMBAT,
    },
    [SPECIES_GIRAFARIG] =
    {
        .move = MOVE_TWIN_BEAM,
        .differentDescription = TRUE,
        .description = _("Becomes a 45BP move that hits twice having a chance to boost the user Sp.Atk."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 45,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_SPATK,
        .chance2 = 25,
    },
    [SPECIES_FARIGIRAF] =
    {
        .move = MOVE_TWIN_BEAM,
        .differentDescription = TRUE,
        .description = _("Becomes a 50BP move that hits twice having a chance to boost the user Sp.Atk."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 50,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_SPATK,
        .chance2 = 20,
    },
    [SPECIES_HERACROSS] =
    {
        .move = MOVE_MEGAHORN,
        .differentDescription = TRUE,
        .description = _("Becomes a 95BP move with 100% accuracy that may boost the user Attack."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_ACCURACY,
        .variable2 = 100,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_ATK,
        .chance3 = 25,
    },
    [SPECIES_HERACROSS_MEGA] =
    {
        .move = MOVE_MEGAHORN,
        .differentDescription = TRUE,
        .description = _("Becomes a 100BP move with 100% accuracy that may boost the user Attack."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_ACCURACY,
        .variable2 = 100,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_ATK,
        .chance3 = 30,
    },
    [SPECIES_SNUBBULL] =
    {
        .move = MOVE_BITE,
        .differentDescription = TRUE,
        .description = _("Becomes a 70BP Fairy-type move that can infatuate the target"),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_FAIRY,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 70,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_INFATUATION,
        .chance3 = 15,
    },
    [SPECIES_GRANBULL] =
    {
        .move = MOVE_JAW_LOCK,
        .differentDescription = TRUE,
        .description = _("Becomes a 90BP Fairy-type move that can infatuate the target"),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_FAIRY,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 90,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_INFATUATION,
        .chance3 = 20,
    },
    [SPECIES_DUNSPARCE] =
    {
        .move = MOVE_U_TURN,
        .differentDescription = TRUE,
        .description = _("Becomes a priority 80BP move that can taunt the target"),
        .modification = SIGNATURE_MOD_PRIORITY,
        .variable = SIGNATURE_PRIORITY_ALWAYS,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 80,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_TAUNT,
        .chance3 = 20,
    },
    [SPECIES_DUDUNSPARCE] =
    {
        .move = MOVE_U_TURN,
        .differentDescription = TRUE,
        .description = _("Becomes a priority 90BP move that can taunt the target"),
        .modification = SIGNATURE_MOD_PRIORITY,
        .variable = SIGNATURE_PRIORITY_ALWAYS,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 90,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_TAUNT,
        .chance3 = 20,
    },
    [SPECIES_DUDUNSPARCE_THREE_SEGMENT] =
    {
        .move = MOVE_U_TURN,
        .differentDescription = TRUE,
        .description = _("Becomes a priority 90BP move that can taunt the target"),
        .modification = SIGNATURE_MOD_PRIORITY,
        .variable = SIGNATURE_PRIORITY_ALWAYS,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 90,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_TAUNT,
        .chance3 = 20,
    },
    [SPECIES_XATU] =
    {
        .move = MOVE_FUTURE_SIGHT,
        .differentDescription = TRUE,
        .description = _("Becomes a priority move that sets up psychic terrain"),
        .modification = SIGNATURE_MOD_MODIFY_FIELD,
        .variable = FIELD_SET_TERRAIN_PSYCHIC,
        .modification2 = SIGNATURE_MOD_PRIORITY,
        .variable2 = SIGNATURE_PRIORITY_ALWAYS,
    },
    [SPECIES_SKARMORY] =
    {
        .move = MOVE_STEEL_WING,
        .differentDescription = TRUE,
        .description = _("Now uses the Defense Stat to calculate the damage and has a 95% accuracy."),
        .modification = SIGNATURE_MOD_DAMAGE_STAT,
        .variable = STAT_DEF,
        .modification2 = SIGNATURE_MOD_ACCURACY,
        .variable2 = 95,
    },
    [SPECIES_SKARMORY_MEGA] =
    {
        .move = MOVE_STEEL_WING,
        .differentDescription = TRUE,
        .description = _("Now has a 100% accuracy, is twice as fast and boost the user defense."),
        .modification = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable = STAT_DEF,
        .modification2 = SIGNATURE_MOD_ACCURACY,
        .variable2 = 100,
        .modification3 = SIGNATURE_MOD_SPEED,
        .variable3 = 200,
    },
    [SPECIES_CHINCHOU] =
    {
        .move = MOVE_WATER_PULSE,
        .differentDescription = TRUE,
        .description = _("Becomes a 70BP Water/Electric move that gives the target the Water-type"),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_GIVE_THIRD_TYPE,
        .argument = TYPE_WATER,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 70,
        .modification3 = SIGNATURE_MOD_SECOND_TYPE,
        .variable3 = TYPE_ELECTRIC,
    },
    [SPECIES_LANTURN] =
    {
        .move = MOVE_WATER_PULSE,
        .differentDescription = TRUE,
        .description = _("Becomes a 80BP Water/Electric type move that gives the target the Water-type"),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_GIVE_THIRD_TYPE,
        .argument = TYPE_WATER,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 80,
        .modification3 = SIGNATURE_MOD_SECOND_TYPE,
        .variable3 = TYPE_ELECTRIC,
    },
    [SPECIES_SPINARAK] =
    {
        .move = MOVE_TOXIC_THREAD,
        .differentDescription = TRUE,
        .description = _("Now also sets up Sticky Web"),
        .modification = SIGNATURE_MOD_MODIFY_FIELD,
        .variable = FIELD_OPPONET_SET_STICKY_WEB,
    },
    [SPECIES_ARIADOS] =
    {
        .move = MOVE_TOXIC_THREAD,
        .differentDescription = TRUE,
        .description = _("Now also sets up Sticky Web"),
        .modification = SIGNATURE_MOD_MODIFY_FIELD,
        .variable = FIELD_OPPONET_SET_STICKY_WEB,
    },
    [SPECIES_SCIZOR] =
    {
        .move = MOVE_METAL_CLAW,
        .differentDescription = TRUE,
        .description = _("Becomes a 90BP move that now has a 20% chance of increasing the user attack stat and ignores the target defense stat c"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable2 = 20,
        .modification3 = SIGNATURE_MOD_PENETRATING,
        .variable3 = 0,
    },
    [SPECIES_SCIZOR_MEGA] =
    {
        .move = MOVE_METAL_CLAW,
        .differentDescription = TRUE,
        .description = _("Becomes a 100BP move that now has a 20% chance of increasing the user attack stat and ignores the target defense stat "),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable2 = 20,
        .modification3 = SIGNATURE_MOD_PENETRATING,
        .variable3 = 0,
    },
    [SPECIES_STEELIX] =
    {
        .move = MOVE_IRON_TAIL,
        .differentDescription = TRUE,
        .description = _("Has a 95% accuracy and can set up sandstorm."),
        .modification = SIGNATURE_MOD_ACCURACY,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_WEATHER_SANDSTORM,
        .chance2 = 25,
    },
    [SPECIES_STEELIX_MEGA] =
    {
        .move = MOVE_IRON_TAIL,
        .differentDescription = TRUE,
        .description = _("Has a 100% accuracy and can set up sandstorm."),
        .modification = SIGNATURE_MOD_ACCURACY,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_WEATHER_SANDSTORM,
        .chance2 = 35,
    },
    [SPECIES_OCTILLERY] =
    {
        .move = MOVE_OCTAZOOKA,
        .differentDescription = TRUE,
        .description = _("Becomes a 80BP move that taunts the target"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_TAUNT,
    },
    [SPECIES_QWILFISH] =
    {
        .move = MOVE_PIN_MISSILE,
        .differentDescription = TRUE,
        .description = _("It now has a 10% chance of setting a layer of toxic spikes per hit, becomes a Poison type move and hits a minimum of 4"),
        .modification = SIGNATURE_MOD_MODIFY_FIELD,
        .variable = FIELD_OPPONET_SET_TOXIC_SPIKES,
        .chance = 10,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_POISON,
        .modification3 = SIGNATURE_MOD_MULTI_HIT_MIN_TIMES,
        .variable3 = 4,
    },
    [SPECIES_QWILFISH_HISUI] =
    {
        .move = MOVE_PIN_MISSILE,
        .differentDescription = TRUE,
        .description = _("It now has a 10% chance of setting a layer of toxic spikes per hit, becomes a Dark-type move and hits a minimum of 3 t"),
        .modification = SIGNATURE_MOD_MODIFY_FIELD,
        .variable = FIELD_OPPONET_SET_TOXIC_SPIKES,
        .chance = 10,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_DARK,
        .modification3 = SIGNATURE_MOD_MULTI_HIT_MIN_TIMES,
        .variable3 = 3,
    },
    [SPECIES_OVERQWIL] =
    {
        .move = MOVE_PIN_MISSILE,
        .differentDescription = TRUE,
        .description = _("It now has a 10% chance of setting a layer of toxic spikes per hit, becomes a Dark-type move and hits a minimum of 4 t"),
        .modification = SIGNATURE_MOD_MODIFY_FIELD,
        .variable = FIELD_OPPONET_SET_TOXIC_SPIKES,
        .chance = 15,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_DARK,
        .modification3 = SIGNATURE_MOD_MULTI_HIT_MIN_TIMES,
        .variable3 = 4,
    },
    [SPECIES_DELIBIRD] =
    {
        .move = MOVE_PRESENT,
        .differentDescription = TRUE,
        .description = _("It now sets Hail when used and becomes an Ice-Type move, it uses the highest attacking stat for damage calculation, ab"),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_ICE,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_WEATHER_HAIL,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_DRAIN,
        .argument3 = 25,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_HIGHEST,
    },
    [SPECIES_IRON_BUNDLE] =
    {
        .move = MOVE_PRESENT,
        .differentDescription = TRUE,
        .description = _("It can set Electric Terrain when used and becomes an Ice-Type move, it uses the highest attacking stat for damage calc"),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_ICE,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_TERRAIN_ELECTRIC,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_PSS_CHANGE,
        .variable3 = SPLIT_HIGHEST,
    },
    [SPECIES_BELLOSSOM] =
    {
        .move = MOVE_PETAL_DANCE,
        .differentDescription = TRUE,
        .description = _("Becomes a 95BP move that does not lock the user, it has a 30% chance of raising the user speed and can set up grassy t"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_SPEED,
        .chance2 = 30,
        .modification3 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable3 = FIELD_SET_TERRAIN_GRASS,
        .chance3 = 50,
        .modification4 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable4 = EFFECT_HIT,
    },
    [SPECIES_CROBAT] =
    {
        .move = MOVE_CROSS_POISON,
        .differentDescription = TRUE,
        .description = _("It becomes a 85BP move that hits SE against Steel-types, has a chance of lowering the defense and blocks healing for 5"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 85,
        .modification2 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable2 = TYPE_STEEL,
        .modification3 = SIGNATURE_MOD_TARGET_STAT_DOWN,
        .variable3 = STAT_DEF,
        .chance3 = 30,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_SET_HEAL_BLOCK,
    },
    [SPECIES_CROBAT_MEGA] =
    {
        .move = MOVE_CROSS_POISON,
        .differentDescription = TRUE,
        .description = _("It becomes a 85BP move that hits SE against Steel-types, has a chance of lowering the defense and blocks healing for 5"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 85,
        .modification2 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable2 = TYPE_STEEL,
        .modification3 = SIGNATURE_MOD_TARGET_STAT_DOWN,
        .variable3 = STAT_DEF,
        .chance3 = 30,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_SET_HEAL_BLOCK,
    },
    [SPECIES_SCEPTILE] =
    {
        .move = MOVE_LEAF_BLADE,
        .differentDescription = TRUE,
        .description = _("It now uses the highest attacking stat to calculate it's damage and can set up grassy terrain, ignores the target defe"),
        .modification = SIGNATURE_MOD_PSS_CHANGE,
        .variable = SPLIT_HIGHEST,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_TERRAIN_GRASS,
        .chance2 = 25,
        .modification3 = SIGNATURE_MOD_PENETRATING,
        .variable3 = 0,
    },
    [SPECIES_SCEPTILE_MEGA] =
    {
        .move = MOVE_LEAF_BLADE,
        .differentDescription = TRUE,
        .description = _("It now uses the highest attacking stat to calculate it's damage and has a 35% chance to set up grassy terrain, ignores"),
        .modification = SIGNATURE_MOD_PSS_CHANGE,
        .variable = SPLIT_HIGHEST,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_TERRAIN_GRASS,
        .chance2 = 35,
        .modification3 = SIGNATURE_MOD_PENETRATING,
        .variable3 = 0,
    },
    [SPECIES_BLAZIKEN] =
    {
        .move = MOVE_BLAZE_KICK,
        .differentDescription = TRUE,
        .description = _("Its becomes a Fire and Fighting move with a power of 95 that has a 25% chance of setting up Sunny Day."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_WEATHER_SUN,
        .chance2 = 25,
        .modification3 = SIGNATURE_MOD_PENETRATING,
        .variable3 = 0,
    },
    [SPECIES_BLAZIKEN_MEGA] =
    {
        .move = MOVE_BLAZE_KICK,
        .differentDescription = TRUE,
        .description = _("Its becomes a Fire and Fighting move with a power of 95 that has a 35% chance of setting up Sunny Day."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_WEATHER_SUN,
        .chance2 = 35,
        .modification3 = SIGNATURE_MOD_SECOND_TYPE,
        .variable3 = TYPE_GROUND,
    },
    [SPECIES_SWAMPERT] =
    {
        .move = MOVE_MUDDY_WATER,
        .differentDescription = TRUE,
        .description = _("Becomes a Physical Water and Ground move that has a 25% chance of setting up Rain."),
        .modification = SIGNATURE_MOD_PSS_CHANGE,
        .variable = SPLIT_HIGHEST,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_WEATHER_RAIN,
        .chance2 = 25,
        .modification3 = SIGNATURE_MOD_SECOND_TYPE,
        .variable3 = TYPE_GROUND,
    },
    [SPECIES_SWAMPERT_MEGA] =
    {
        .move = MOVE_MUDDY_WATER,
        .differentDescription = TRUE,
        .description = _("Becomes a Physical Water and Ground move that can set up Rain."),
        .modification = SIGNATURE_MOD_PSS_CHANGE,
        .variable = SPLIT_HIGHEST,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_WEATHER_RAIN,
        .chance2 = 35,
        .modification3 = SIGNATURE_MOD_SECOND_TYPE,
        .variable3 = TYPE_GROUND,
    },
    [SPECIES_MIGHTYENA] =
    {
        .move = MOVE_BITE,
        .differentDescription = TRUE,
        .description = _("It Becomes a move with a power of 80 that has a 30% chance of lowering the target's speed."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_TARGET_STAT_DOWN,
        .variable2 = STAT_SPEED,
        .chance2 = 30,
    },
    [SPECIES_LINOONE] =
    {
        .move = MOVE_EXTREME_SPEED,
        .differentDescription = TRUE,
        .description = _("It now raises the Speed stat of the user after using it and cures some of its HP."),
        .modification = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable = STAT_SPEED,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_CURE,
        .argument2 = 20,
    },
    [SPECIES_BEAUTIFLY] =
    {
        .move = MOVE_SILVER_WIND,
        .differentDescription = TRUE,
        .description = _("Becomes a 80BP move that has a 20% chance of raising all of the user stats."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable2 = 20,
    },
    [SPECIES_DUSTOX] =
    {
        .move = MOVE_OMINOUS_WIND,
        .differentDescription = TRUE,
        .description = _("Becomes a 80BP Poison-type move that has a 20% chance of raising all of the user stats."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_POISON,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable3 = 20,
    },
    [SPECIES_SWELLOW] =
    {
        .move = MOVE_AERIAL_ACE,
        .differentDescription = TRUE,
        .description = _("Becomes a 70 BP move that doubles its power if the user is poisoned, burned, or paralyzed."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_FACADE,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 70,
    },
    [SPECIES_EXPLOUD] =
    {
        .move = MOVE_ROAR,
        .differentDescription = TRUE,
        .description = _("Becomes a 60 BP move that knocks away the target and drags out another Pokémon in its party, also boosts SP.Atk."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 60,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT_SWITCH_TARGET,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_SPATK,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_SPECIAL,
    },
    [SPECIES_LUDICOLO] =
    {
        .move = MOVE_RAIN_DANCE,
        .differentDescription = TRUE,
        .description = _("It becomes a 75BP special move that always sets up rain and hits both targets."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_HIT,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_WEATHER_RAIN,
        .modification3 = SIGNATURE_MOD_POWER,
        .variable3 = 75,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_SPECIAL,
        .modification5 = SIGNATURE_MOD_CHANGE_TARGET,
        .variable5 = MOVE_TARGET_BOTH,
    },
    [SPECIES_SHIFTRY] =
    {
        .move = MOVE_LEAF_TORNADO,
        .differentDescription = TRUE,
        .description = _("It Becomes a Grass and Flying type Physical move with a power of 80 with a 20% chance of setting up Tailwind."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable2 = 0,
        .modification3 = SIGNATURE_MOD_PSS_CHANGE,
        .variable3 = SPLIT_PHYSICAL,
        .modification4 = SIGNATURE_MOD_SECOND_TYPE,
        .variable4 = TYPE_FLYING,
        .modification5 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable5 = FIELD_SELF_SET_TAILWIND,
        .chance5 = 20,
    },
    [SPECIES_TRAPINCH] =
    {
        .move = MOVE_BITE,
        .differentDescription = TRUE,
        .description = _("Becomes a Ground-type move that ignores target stat changes, has a higher flinch chance."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_GROUND,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable3 = 30,
    },
    [SPECIES_FLYGON] =
    {
        .move = MOVE_DUAL_WINGBEAT,
        .differentDescription = TRUE,
        .description = _("Becomes a 45BP Ground and Flying move that can set up a Sandstorm."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 45,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_GROUND,
        .modification3 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable3 = FIELD_SET_WEATHER_SANDSTORM,
        .chance3 = 25,
        .modification4 = SIGNATURE_MOD_SECOND_TYPE,
        .variable4 = TYPE_FLYING,
    },
    [SPECIES_FLYGON_MEGA] =
    {
        .move = MOVE_DUAL_WINGBEAT,
        .differentDescription = TRUE,
        .description = _("Becomes a 50BP Ground and Flying move that can set up a Sandstorm or Tailwind."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 50,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_GROUND,
        .modification3 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable3 = FIELD_SET_WEATHER_SANDSTORM,
        .chance3 = 25,
        .modification4 = SIGNATURE_MOD_SECOND_TYPE,
        .variable4 = TYPE_FLYING,
        .modification5 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable5 = FIELD_SELF_SET_TAILWIND,
        .chance5 = 20,
    },
    [SPECIES_SLAKOTH] =
    {
        .move = MOVE_SLACK_OFF,
        .differentDescription = TRUE,
        .description = _("It lets you use another move after using it and now has a higher priority."),
        .modification = SIGNATURE_MOD_OTHER,
        .variable = 0,
        .modification2 = SIGNATURE_MOD_PRIORITY,
        .variable2 = SIGNATURE_PRIORITY_ALWAYS,
    },
    [SPECIES_VIGOROTH] =
    {
        .move = MOVE_SLASH,
        .differentDescription = TRUE,
        .description = _("Can hit Ghost-types, has a chance of boosting the user attack and cures some of the user hp upon use."),
        .modification = SIGNATURE_MOD_NEUTRAL_AGAINST_TYPE,
        .variable = TYPE_GHOST,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_CURE,
        .argument2 = 20,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_ATK,
        .chance3 = 20,
    },
    [SPECIES_SLAKING] =
    {
        .move = MOVE_SLACK_OFF,
        .differentDescription = TRUE,
        .description = _("It lets you use another move after using it and now has a higher priority."),
        .modification = SIGNATURE_MOD_OTHER,
        .variable = 0,
        .modification2 = SIGNATURE_MOD_PRIORITY,
        .variable2 = SIGNATURE_PRIORITY_ALWAYS,
    },
    [SPECIES_CHIMECHO] =
    {
        .move = MOVE_HYPER_VOICE,
        .differentDescription = TRUE,
        .description = _("Becomes a Psychic-type move that heals the user status and can flinch the target."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_PSYCHIC,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_HEAL_STATUS,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance3 = 30,
    },
    [SPECIES_CHIMECHO_MEGA] =
    {
        .move = MOVE_HYPER_VOICE,
        .differentDescription = TRUE,
        .description = _("Becomes an Steel-type move that heals the user status and can flinch the target, restores 25% of its max HP upon use."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_STEEL,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_HEAL_STATUS,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance3 = 30,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_CURE,
        .argument4 = 25,
    },
    [SPECIES_ABSOL] =
    {
        .move = MOVE_NIGHT_SLASH,
        .differentDescription = TRUE,
        .description = _("Becomes a 90BP move that heals some of the damage done as HP."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 85,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_DRAIN,
        .argument2 = 50,
    },
    [SPECIES_ABSOL_MEGA] =
    {
        .move = MOVE_NIGHT_SLASH,
        .differentDescription = TRUE,
        .description = _("Becomes a 95BP move that heals some of the damage done as HP, can now flinch the target and ignores its defense stat c"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_DRAIN,
        .argument2 = 50,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance3 = 30,
        .modification4 = SIGNATURE_MOD_PENETRATING,
        .variable4 = 0,
    },
    [SPECIES_ABSOL_MEGA_Z] =
    {
        .move = MOVE_NIGHT_SLASH,
        .differentDescription = TRUE,
        .description = _("Becomes a 95BP Ghost-type move that heals some of the damage done as HP, can now flinch the target and ignores its def"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_DRAIN,
        .argument2 = 50,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance3 = 30,
        .modification4 = SIGNATURE_MOD_PENETRATING,
        .variable4 = 0,
        .modification5 = SIGNATURE_MOD_TYPE,
        .variable5 = TYPE_GHOST,
    },
    [SPECIES_MAWILE] =
    {
        .move = MOVE_HYPER_FANG,
        .differentDescription = TRUE,
        .description = _("Becomes a 80 BP Fairy-type move that prevents the target from switching and ignores the target stat changes."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT_PREVENT_ESCAPE,
        .modification3 = SIGNATURE_MOD_TYPE,
        .variable3 = TYPE_FAIRY,
        .modification4 = SIGNATURE_MOD_ADD_FLAG,
        .variable4 = FLAG_STAT_STAGES_IGNORED,
    },
    [SPECIES_MAWILE_MEGA] =
    {
        .move = MOVE_HYPER_FANG,
        .differentDescription = TRUE,
        .description = _("Becomes a 50 BP Fairy-type move hits twice and ignores the target stat changes, may boost attack."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 50,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_DOUBLE_HIT,
        .modification3 = SIGNATURE_MOD_TYPE,
        .variable3 = TYPE_FAIRY,
        .modification4 = SIGNATURE_MOD_ADD_FLAG,
        .variable4 = FLAG_STAT_STAGES_IGNORED,
        .modification5 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable5 = STAT_ATK,
        .chance5 = 15,
    },
    [SPECIES_NINJASK] =
    {
        .move = MOVE_FURY_CUTTER,
        .differentDescription = TRUE,
        .description = _("It becomes an Speed version of Body Press."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_DAMAGE_STAT,
        .variable2 = STAT_SPEED,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable3 = EFFECT_HIT,
    },
    [SPECIES_SHEDINJA] =
    {
        .move = MOVE_LEECH_LIFE,
        .differentDescription = TRUE,
        .description = _("Becomes a 90BP move that may curse the target or boost the user Attack stat."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_CURSE,
        .chance = 25,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 90,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_ATK,
        .chance3 = 25,
    },
    [SPECIES_HARIYAMA] =
    {
        .move = MOVE_ARM_THRUST,
        .differentDescription = TRUE,
        .description = _("It gets a 10% Paralysis chance for each hit and hits Ghost-types for x2 damage, hits a minimum 4 times."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_PARALYSIS,
        .chance = 10,
        .modification2 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable2 = TYPE_GHOST,
        .modification3 = SIGNATURE_MOD_MULTI_HIT_MIN_TIMES,
        .variable3 = 4,
    },
    [SPECIES_ZANGOOSE] =
    {
        .move = MOVE_CRUSH_CLAW,
        .differentDescription = TRUE,
        .description = _("It becomes Super-Effective against Poison-types and ignores the target's defense stat changes."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable2 = TYPE_POISON,
        .modification3 = SIGNATURE_MOD_PENETRATING,
        .variable3 = 0,
    },
    [SPECIES_SEVIPER] =
    {
        .move = MOVE_POISON_TAIL,
        .differentDescription = TRUE,
        .description = _("It becomes Super-Effective against Normal-types"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 75,
        .modification2 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable2 = TYPE_NORMAL,
    },
    [SPECIES_SPINDA] =
    {
        .move = MOVE_DIZZY_PUNCH,
        .differentDescription = TRUE,
        .description = _("It becomes a 80 BP Priority move when used by Spinda"),
        .modification = SIGNATURE_MOD_PRIORITY,
        .variable = SIGNATURE_PRIORITY_ALWAYS,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 80,
    },
    [SPECIES_LUVDISC] =
    {
        .move = MOVE_DRAINING_KISS,
        .differentDescription = TRUE,
        .description = _("It becomes a 90 bp move and doubles your speed while using it, has a chance of infatuating the target."),
        .modification = SIGNATURE_MOD_SPEED,
        .variable = 200,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 90,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_INFATUATION,
        .chance3 = 30,
    },
    [SPECIES_KECLEON] =
    {
        .move = MOVE_LICK,
        .differentDescription = TRUE,
        .description = _("Becomes a 75BP Normal-type move that is twice as fast and can flinch the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 75,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_TYPE,
        .variable3 = TYPE_NORMAL,
        .modification4 = SIGNATURE_MOD_SPEED,
        .variable4 = 200,
    },
    [SPECIES_RELICANTH] =
    {
        .move = MOVE_HEADBUTT,
        .differentDescription = TRUE,
        .description = _("Becomes a Rock-type move with a power of 60 and a priority of +1, now it has a 20% flinch chance"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 60,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_ROCK,
        .modification3 = SIGNATURE_MOD_PRIORITY,
        .variable3 = SIGNATURE_PRIORITY_ALWAYS,
        .modification4 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable4 = 20,
    },
    [SPECIES_GLALIE] =
    {
        .move = MOVE_ICE_FANG,
        .differentDescription = TRUE,
        .description = _("Becomes a 80BP move that has a 30% chance of freezing the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable2 = 30,
    },
    [SPECIES_GLALIE_MEGA] =
    {
        .move = MOVE_ICE_FANG,
        .differentDescription = TRUE,
        .description = _("Becomes a 75BP move that has a 40% chance of freezing the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 75,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable2 = 40,
    },
    [SPECIES_ANORITH] =
    {
        .move = MOVE_FURY_CUTTER,
        .differentDescription = TRUE,
        .description = _("Becomes a 75 BP move that has priority in the rain and can raise the user speed."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 75,
        .modification2 = SIGNATURE_MOD_PRIORITY,
        .variable2 = SIGNATURE_PRIORITY_IN_CONDITIONS,
        .chance2 = SIGNATURE_CONDITION_WEATHER_RAIN,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_SPEED,
        .chance3 = 15,
        .modification4 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable4 = EFFECT_HIT,
    },
    [SPECIES_ARMALDO] =
    {
        .move = MOVE_FURY_CUTTER,
        .differentDescription = TRUE,
        .description = _("Becomes a 90 BP Rock-type move that has a 30% chance of raising the user's Speed."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_ROCK,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_SPEED,
        .chance3 = 30,
        .modification4 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable4 = EFFECT_HIT,
    },
    [SPECIES_LILEEP] =
    {
        .move = MOVE_MEGA_DRAIN,
        .differentDescription = TRUE,
        .description = _("Becomes a 80BP Rock-type move that always inflicts Leech Seed."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_ROCK,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_LEECH_SEED,
    },
    [SPECIES_CRADILY] =
    {
        .move = MOVE_MEGA_DRAIN,
        .differentDescription = TRUE,
        .description = _("Becomes a 80BP Rock-type move that always inflicts Leech Seed."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_ROCK,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_LEECH_SEED,
    },
    [SPECIES_DUSCLOPS] =
    {
        .move = MOVE_SHADOW_PUNCH,
        .differentDescription = TRUE,
        .description = _("Deals neutral damage to Normal-types and may curse the target."),
        .modification = SIGNATURE_MOD_NEUTRAL_AGAINST_TYPE,
        .variable = TYPE_NORMAL,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_CURSE,
        .chance2 = 20,
    },
    [SPECIES_DUSKNOIR] =
    {
        .move = MOVE_SHADOW_PUNCH,
        .differentDescription = TRUE,
        .description = _("Deals Super Effective damage to Normal-types and may curse the target."),
        .modification = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable = TYPE_NORMAL,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_CURSE,
        .chance2 = 30,
    },
    [SPECIES_CASTFORM] =
    {
        .move = MOVE_WEATHER_BALL,
        .differentDescription = TRUE,
        .description = _("Becomes an 100BP move that can boost the user special attack."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_SPATK,
        .chance2 = 25,
    },
    [SPECIES_CASTFORM_SUNNY] =
    {
        .move = MOVE_WEATHER_BALL,
        .differentDescription = TRUE,
        .description = _("Becomes a Fire-type move that has a 25% chance of Burning its target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance2 = 25,
    },
    [SPECIES_CASTFORM_SNOWY] =
    {
        .move = MOVE_WEATHER_BALL,
        .differentDescription = TRUE,
        .description = _("Becomes an Ice-type move that has a 25% chance of Frostbiting its target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 100,
    },
    [SPECIES_CASTFORM_RAINY] =
    {
        .move = MOVE_WEATHER_BALL,
        .differentDescription = TRUE,
        .description = _("Becomes a Water-type move that slows down its target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_TARGET_STAT_DOWN,
        .variable2 = STAT_SPEED,
    },
    [SPECIES_REGICE] =
    {
        .move = MOVE_ANCIENT_POWER,
        .differentDescription = TRUE,
        .description = _("Becomes an Ice-type move that has a 30% chance of raising all of the user stats."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable2 = 30,
        .modification3 = SIGNATURE_MOD_TYPE,
        .variable3 = TYPE_ICE,
    },
    [SPECIES_REGIROCK] =
    {
        .move = MOVE_ANCIENT_POWER,
        .differentDescription = TRUE,
        .description = _("Becomes a Rock-type move that has a 30% chance of raising all of the user stats."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable2 = 30,
        .modification3 = SIGNATURE_MOD_PSS_CHANGE,
        .variable3 = SPLIT_PHYSICAL,
    },
    [SPECIES_REGISTEEL] =
    {
        .move = MOVE_ANCIENT_POWER,
        .differentDescription = TRUE,
        .description = _("Becomes a Steel-type move that has a 30% chance of raising all of the user stats."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable2 = 30,
        .modification3 = SIGNATURE_MOD_PSS_CHANGE,
        .variable3 = SPLIT_PHYSICAL,
        .modification4 = SIGNATURE_MOD_TYPE,
        .variable4 = TYPE_STEEL,
    },
    [SPECIES_TORTERRA] =
    {
        .move = MOVE_EARTHQUAKE,
        .differentDescription = TRUE,
        .description = _("Absorbs some of the damage done as HP, can now hit flying-types and airbone targets."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_DRAIN,
        .argument = 50,
        .modification2 = SIGNATURE_MOD_NEUTRAL_AGAINST_TYPE,
        .variable2 = TYPE_FLYING,
    },
    [SPECIES_INFERNAPE] =
    {
        .move = MOVE_MACH_PUNCH,
        .differentDescription = TRUE,
        .description = _("Becomes a 50BP Fire-type move that has a 25% chance of burning the target, uses the highest attacking stat."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 50,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_FIRE,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance3 = 25,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_HIGHEST,
    },
    [SPECIES_EMPOLEON] =
    {
        .move = MOVE_METAL_CLAW,
        .differentDescription = TRUE,
        .description = _("Becomes a Steel and Water-type move that uses the user's highest attacking stat and raises Sp.Atk rather than Attack."),
        .modification = SIGNATURE_MOD_SECOND_TYPE,
        .variable = TYPE_WATER,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 80,
        .modification3 = SIGNATURE_MOD_PSS_CHANGE,
        .variable3 = SPLIT_HIGHEST,
        .modification4 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable4 = 0,
        .modification5 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable5 = STAT_SPATK,
        .chance5 = 20,
    },
    [SPECIES_BIDOOF] =
    {
        .move = MOVE_HYPER_FANG,
        .differentDescription = TRUE,
        .description = _("Becomes Super Effective against Grass-types and ignores the target defense changes."),
        .modification = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable = TYPE_GRASS,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
    },
    [SPECIES_BIBAREL] =
    {
        .move = MOVE_HYPER_FANG,
        .differentDescription = TRUE,
        .description = _("Becomes Super Effective against Grass-types and ignores the target defense changes."),
        .modification = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable = TYPE_GRASS,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
    },
    [SPECIES_STARAPTOR] =
    {
        .move = MOVE_DOUBLE_EDGE,
        .differentDescription = TRUE,
        .description = _("Does less damage to itself, can now flinch the target and can hit Ghost-types."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_HIT,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_RECKOIL,
        .argument2 = 20,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance3 = 15,
        .modification4 = SIGNATURE_MOD_NEUTRAL_AGAINST_TYPE,
        .variable4 = TYPE_NORMAL,
    },
    [SPECIES_STARAPTOR_MEGA] =
    {
        .move = MOVE_DOUBLE_EDGE,
        .differentDescription = TRUE,
        .description = _("Becomes a Fighting-type move that does less damage to itself, can now flinch the target and can hit Ghost-types."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_HIT,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_RECKOIL,
        .argument2 = 20,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance3 = 15,
        .modification4 = SIGNATURE_MOD_NEUTRAL_AGAINST_TYPE,
        .variable4 = TYPE_NORMAL,
        .modification5 = SIGNATURE_MOD_TYPE,
        .variable5 = TYPE_ROCK,
    },
    [SPECIES_CHATOT] =
    {
        .move = MOVE_CHATTER,
        .differentDescription = TRUE,
        .description = _("Becomes a 80BP move that has a 20% chance of setting up Tailwind."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SELF_SET_TAILWIND,
        .chance2 = 20,
    },
    [SPECIES_CRANIDOS] =
    {
        .move = MOVE_HEADBUTT,
        .differentDescription = TRUE,
        .description = _("Becomes a Rock-type move with a power of 50 and a priority of +1, now it has a 20% flinch chance"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 50,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_ROCK,
        .modification3 = SIGNATURE_MOD_PRIORITY,
        .variable3 = SIGNATURE_PRIORITY_ALWAYS,
        .modification4 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable4 = 20,
    },
    [SPECIES_RAMPARDOS] =
    {
        .move = MOVE_HEADBUTT,
        .differentDescription = TRUE,
        .description = _("Becomes a Rock-type move with a power of 60 and a priority of +1, now it has a 10% flinch chance"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 60,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_ROCK,
        .modification3 = SIGNATURE_MOD_PRIORITY,
        .variable3 = SIGNATURE_PRIORITY_ALWAYS,
        .modification4 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable4 = 10,
    },
    [SPECIES_BASTIODON] =
    {
        .move = MOVE_IRON_HEAD,
        .differentDescription = TRUE,
        .description = _("Becomes a 95BP move that uses the Defense Stat to calculate the damage and can flinch."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_DAMAGE_STAT,
        .variable2 = STAT_DEF,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance3 = 20,
    },
    [SPECIES_CARNIVINE] =
    {
        .move = MOVE_JAW_LOCK,
        .differentDescription = TRUE,
        .description = _("Becomes a Grass-type move that is Super- Effective against Bug and Flying types."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_GRASS,
        .modification2 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable2 = TYPE_BUG,
        .modification3 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable3 = TYPE_FLYING,
    },
    [SPECIES_STUNKY] =
    {
        .move = MOVE_GUNK_SHOT,
        .differentDescription = TRUE,
        .description = _("Becomes a 95 accuracy move that hits Steel-types Super-Effectively using the user's highest attack stat."),
        .modification = SIGNATURE_MOD_ACCURACY,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable2 = TYPE_STEEL,
        .modification3 = SIGNATURE_MOD_PSS_CHANGE,
        .variable3 = SPLIT_HIGHEST,
    },
    [SPECIES_SKUNTANK] =
    {
        .move = MOVE_GUNK_SHOT,
        .differentDescription = TRUE,
        .description = _("Becomes a 100 accuracy move that hits Steel-types Super-Effectively using the user's highest attack stat,"),
        .modification = SIGNATURE_MOD_ACCURACY,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable2 = TYPE_STEEL,
        .modification3 = SIGNATURE_MOD_PSS_CHANGE,
        .variable3 = SPLIT_HIGHEST,
    },
    [SPECIES_PACHIRISU] =
    {
        .move = MOVE_HYPER_FANG,
        .differentDescription = TRUE,
        .description = _("Becomes an 80 BP Electric-type move that can paralyze the target and is 50% faster than other moves."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_ELECTRIC,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_PARALYSIS,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_SPEED,
        .variable3 = 150,
    },
    [SPECIES_CROAGUNK] =
    {
        .move = MOVE_SUCKER_PUNCH,
        .differentDescription = TRUE,
        .description = _("Becomes a Poison-type move with a 30% chance of poisoning the target."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_POISON,
        .chance = 30,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_POISON,
    },
    [SPECIES_TOXICROAK] =
    {
        .move = MOVE_SUCKER_PUNCH,
        .differentDescription = TRUE,
        .description = _("Becomes a Poison-type move with a 30% chance of taunting the target."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_TAUNT,
        .chance = 30,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_POISON,
    },
    [SPECIES_HONCHKROW] =
    {
        .move = MOVE_BEAT_UP,
        .differentDescription = TRUE,
        .description = _("Becomes a 25 BP move that can lower the target's defense stat."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 25,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_MULTI_HIT,
        .modification3 = SIGNATURE_MOD_TARGET_STAT_DOWN,
        .variable3 = STAT_DEF,
        .chance3 = 5,
    },
    [SPECIES_PROBOPASS] =
    {
        .move = MOVE_MAGNET_BOMB,
        .differentDescription = TRUE,
        .description = _("Becomes a 90 BP Steel-type move that can paralyze the target and is super effective against Steel-types."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_STEEL,
        .modification3 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable3 = TYPE_STEEL,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_PARALYSIS,
        .chance4 = 20,
    },
    [SPECIES_ABOMASNOW] =
    {
        .move = MOVE_BLIZZARD,
        .differentDescription = TRUE,
        .description = _("It now uses the highest attacking stat to calculate it's damage always has a 90% accuracy and can raise the user defen"),
        .modification = SIGNATURE_MOD_PSS_CHANGE,
        .variable = SPLIT_HIGHEST,
        .modification2 = SIGNATURE_MOD_ACCURACY,
        .variable2 = 90,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_DEF,
        .chance3 = 20,
    },
    [SPECIES_ABOMASNOW_MEGA] =
    {
        .move = MOVE_BLIZZARD,
        .differentDescription = TRUE,
        .description = _("It now uses the highest attacking stat to calculate it's damage always has a 95% accuracy and can raise the user defen"),
        .modification = SIGNATURE_MOD_PSS_CHANGE,
        .variable = SPLIT_HIGHEST,
        .modification2 = SIGNATURE_MOD_ACCURACY,
        .variable2 = 95,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_DEF,
        .chance3 = 30,
    },
    [SPECIES_RIOLU] =
    {
        .move = MOVE_VACUUM_WAVE,
        .differentDescription = TRUE,
        .description = _("Becomes a 60BP move that can raise the user's Special Attack by 1 stage with a 10% chance, uses the highest attack sta"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 60,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_SPATK,
        .chance2 = 25,
        .modification3 = SIGNATURE_MOD_PSS_CHANGE,
        .variable3 = SPLIT_HIGHEST,
    },
    [SPECIES_LUCARIO] =
    {
        .move = MOVE_AURA_SPHERE,
        .differentDescription = TRUE,
        .description = _("Becomes a 95BP move that can raise the user's Special Attack by 1 stage with a 10% chance, uses the highest attack."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_SPATK,
        .chance2 = 10,
        .modification3 = SIGNATURE_MOD_PSS_CHANGE,
        .variable3 = SPLIT_HIGHEST,
    },
    [SPECIES_LUCARIO_MEGA] =
    {
        .move = MOVE_AURA_SPHERE,
        .differentDescription = TRUE,
        .description = _("Becomes a physical 105BP move that can raise the user's Attack by 1 stage with a 10% chance."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 105,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_ATK,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_PSS_CHANGE,
        .variable3 = SPLIT_PHYSICAL,
    },
    [SPECIES_LUCARIO_MEGA_Z] =
    {
        .move = MOVE_AURA_SPHERE,
        .differentDescription = TRUE,
        .description = _("Becomes a 105BP move that raises the user's Special Attack by 1 stage with a 10% chance."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 105,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_SPATK,
        .chance2 = 20,
    },
    [SPECIES_LOPUNNY] =
    {
        .move = MOVE_RETURN,
        .differentDescription = TRUE,
        .description = _("Becomes a 110BP move with a 30% chance of infatuating the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 110,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_INFATUATION,
        .chance2 = 30,
    },
    [SPECIES_LOPUNNY_MEGA] =
    {
        .move = MOVE_RETURN,
        .differentDescription = TRUE,
        .description = _("Becomes a 110BP Fighting-type move with a 35% chance of infatuating the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 110,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_INFATUATION,
        .chance2 = 35,
        .modification3 = SIGNATURE_MOD_TYPE,
        .variable3 = TYPE_FIGHTING,
    },
    [SPECIES_FROSLASS] =
    {
        .move = MOVE_HEX,
        .differentDescription = TRUE,
        .description = _("Becomes a 80BP move with a 30% chance of frostbiting the target, does extra damage to targets with an status problems."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT,
    },
    [SPECIES_FROSLASS_MEGA] =
    {
        .move = MOVE_HEX,
        .differentDescription = TRUE,
        .description = _("Becomes a 90BP move with a 30% chance of frostbiting the target, does extra damage to targets with an status problems."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT,
    },
    [SPECIES_SPIRITOMB] =
    {
        .move = MOVE_HEX,
        .differentDescription = TRUE,
        .description = _("Becomes a 80BP move with a 20% chance of burning the target, does extra damage to targets with an status problems."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable3 = EFFECT_HIT,
    },
    [SPECIES_GIBLE] =
    {
        .move = MOVE_BITE,
        .differentDescription = TRUE,
        .description = _("Becomes a Ground-type move that ignores target stat changes."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_GROUND,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
    },
    [SPECIES_GABITE] =
    {
        .move = MOVE_CRUNCH,
        .differentDescription = TRUE,
        .description = _("Becomes a Ground-type move that ignores target stat changes."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_GROUND,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
    },
    [SPECIES_GARCHOMP] =
    {
        .move = MOVE_DIG,
        .differentDescription = TRUE,
        .description = _("Becomes a 55BP faster move that charges in one turn and hits underground targets."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_HIT,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 55,
        .modification3 = SIGNATURE_MOD_SPEED,
        .variable3 = 200,
        .modification4 = SIGNATURE_MOD_ADD_FLAG,
        .variable4 = FLAG_DMG_UNDERGROUND,
    },
    [SPECIES_GARCHOMP_MEGA] =
    {
        .move = MOVE_DIG,
        .differentDescription = TRUE,
        .description = _("Becomes a 60BP priority move that charges in one turn and hits underground targets."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_HIT,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 60,
        .modification3 = SIGNATURE_MOD_PRIORITY,
        .variable3 = SIGNATURE_PRIORITY_ALWAYS,
        .modification4 = SIGNATURE_MOD_ADD_FLAG,
        .variable4 = FLAG_DMG_UNDERGROUND,
    },
    [SPECIES_DARKRAI] =
    {
        .move = MOVE_DARK_VOID,
        .differentDescription = TRUE,
        .description = _("Becomes a 75 BP move that has an small chance of sleeping the target and heals the user for half the damage dealt."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 75,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_ABSORB,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_SLEEP,
        .chance3 = 15,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_HIGHEST,
        .modification5 = SIGNATURE_MOD_ACCURACY,
        .variable5 = 90,
        .modification6 = SIGNATURE_MOD_CHANGE_TARGET,
        .variable6 = MOVE_TARGET_SELECTED,
    },
    [SPECIES_DARKRAI_MEGA] =
    {
        .move = MOVE_DARK_VOID,
        .differentDescription = TRUE,
        .description = _("Becomes a 80 BP move that has an small chance of sleeping the target and heals the user for half the damage dealt."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_ABSORB,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_SLEEP,
        .chance3 = 20,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_HIGHEST,
        .modification5 = SIGNATURE_MOD_ACCURACY,
        .variable5 = 90,
        .modification6 = SIGNATURE_MOD_CHANGE_TARGET,
        .variable6 = MOVE_TARGET_SELECTED,
    },
    [SPECIES_SERPERIOR] =
    {
        .move = MOVE_WRAP,
        .differentDescription = TRUE,
        .description = _("Becomes a 70 BP Grass-type move that prevents the target from switching out and leeches the target uses the special at"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 70,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT_PREVENT_ESCAPE,
        .modification3 = SIGNATURE_MOD_TYPE,
        .variable3 = TYPE_GRASS,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_LEECH_SEED,
        .modification5 = SIGNATURE_MOD_PSS_CHANGE,
        .variable5 = SPLIT_SPECIAL,
    },
    [SPECIES_SERPERIOR_MEGA] =
    {
        .move = MOVE_WRAP,
        .differentDescription = TRUE,
        .description = _("Becomes a 90 BP Grass-type move that prevents the target from switching out, steals its positive stat changes and beco"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT_PREVENT_ESCAPE,
        .modification3 = SIGNATURE_MOD_TYPE,
        .variable3 = TYPE_GRASS,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_STEAL_POSITIVE_STAT_CHANGES,
        .modification5 = SIGNATURE_MOD_PSS_CHANGE,
        .variable5 = SPLIT_SPECIAL,
    },
    [SPECIES_EMBOAR] =
    {
        .move = MOVE_HEAT_CRASH,
        .differentDescription = TRUE,
        .description = _("Becomes a 130 BP move with 90% accuracy, If this move misses the user takes damage instead, has a 20% chance of burnin"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 130,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_RECOIL_IF_MISS,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance3 = 20,
        .modification4 = SIGNATURE_MOD_ACCURACY,
        .variable4 = 90,
        .modification5 = SIGNATURE_MOD_ADD_FLAG,
        .variable5 = FLAG_RECKLESS_BOOST,
    },
    [SPECIES_EMBOAR_MEGA] =
    {
        .move = MOVE_HEAT_CRASH,
        .differentDescription = TRUE,
        .description = _("Becomes a 130 BP move with 95% accuracy, If this move misses the user takes damage instead, has a 20% chance of burnin"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 130,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_RECOIL_IF_MISS,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance3 = 20,
        .modification4 = SIGNATURE_MOD_ACCURACY,
        .variable4 = 95,
        .modification5 = SIGNATURE_MOD_ADD_FLAG,
        .variable5 = FLAG_RECKLESS_BOOST,
    },
    [SPECIES_SAMUROTT] =
    {
        .move = MOVE_RAZOR_SHELL,
        .differentDescription = TRUE,
        .description = _("Becomes a 90 BP move that sets up Spikes when used, ignores the target defense changes."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_OPPONET_SET_SPIKES,
        .modification3 = SIGNATURE_MOD_PENETRATING,
        .variable3 = 0,
    },
    [SPECIES_SAMUROTT_MEGA] =
    {
        .move = MOVE_RAZOR_SHELL,
        .differentDescription = TRUE,
        .description = _("Becomes a 95 BP move that restores the user's HP by half of the damage dealt and sets up spikes."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_ABSORB,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 95,
        .modification3 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable3 = FIELD_OPPONET_SET_SPIKES,
    },
    [SPECIES_SAMUROTT_HISUI] =
    {
        .move = MOVE_NIGHT_SLASH,
        .differentDescription = TRUE,
        .description = _("Becomes a 90 BP move that sets up Spikes when used, ignores the target defense changes."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_OPPONET_SET_SPIKES,
        .modification3 = SIGNATURE_MOD_PENETRATING,
        .variable3 = 0,
    },
    [SPECIES_SAMUROTT_HISUI_MEGA] =
    {
        .move = MOVE_NIGHT_SLASH,
        .differentDescription = TRUE,
        .description = _("Becomes a 95 BP move that restores the user's HP by half of the damage dealt and sets up spikes."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_ABSORB,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 95,
        .modification3 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable3 = FIELD_OPPONET_SET_SPIKES,
    },
    [SPECIES_EXCADRILL] =
    {
        .move = MOVE_CRUSH_CLAW,
        .differentDescription = TRUE,
        .description = _("Becomes a Ground-type move that has a higher chance of critical hits and ignores the target Defense stat changes."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_GROUND,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
        .modification3 = SIGNATURE_MOD_ADD_FLAG,
        .variable3 = FLAG_HIGH_CRIT,
    },
    [SPECIES_EXCADRILL_MEGA] =
    {
        .move = MOVE_CRUSH_CLAW,
        .differentDescription = TRUE,
        .description = _("Becomes a Ground-type move that has a higher chance of critical hits and always lower the target defense."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_GROUND,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable2 = 100,
        .modification3 = SIGNATURE_MOD_ADD_FLAG,
        .variable3 = FLAG_HIGH_CRIT,
    },
    [SPECIES_TOUCANNON] =
    {
        .move = MOVE_FURY_ATTACK,
        .differentDescription = TRUE,
        .description = _("Becomes a 20 BP Flying-type move that can burn the target or boost the user attack stat."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 20,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance2 = 10,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_ATK,
        .chance3 = 10,
        .modification4 = SIGNATURE_MOD_TYPE,
        .variable4 = TYPE_FLYING,
    },
    [SPECIES_SCRAFTY] =
    {
        .move = MOVE_LOW_KICK,
        .differentDescription = TRUE,
        .description = _("Becomes a Dark-type move that taunts the target."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_TAUNT,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_DARK,
    },
    [SPECIES_SCRAFTY_MEGA] =
    {
        .move = MOVE_LOW_KICK,
        .differentDescription = TRUE,
        .description = _("Becomes a Dark-type move that taunts the target, cures some of the target hp upon use."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_TAUNT,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_DARK,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_DRAIN,
        .argument3 = 20,
    },
    [SPECIES_EELEKTROSS] =
    {
        .move = MOVE_CRUNCH,
        .differentDescription = TRUE,
        .description = _("Becomes a 90BP Electric-type move that can paralyze the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_ELECTRIC,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_PARALYSIS,
        .chance3 = 20,
    },
    [SPECIES_EELEKTROSS_MEGA] =
    {
        .move = MOVE_CRUNCH,
        .differentDescription = TRUE,
        .description = _("Becomes a 95BP Electric-type move that can paralyze the target, does extra damage to targets with an status condition."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_ELECTRIC,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_PARALYSIS,
        .chance3 = 30,
    },
    [SPECIES_CHANDELURE] =
    {
        .move = MOVE_WILL_O_WISP,
        .differentDescription = TRUE,
        .description = _("Becomes an special 80 BP Ghost-type move that can burn the target, blocks the target from curing itself."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance3 = 25,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_SET_HEAL_BLOCK,
        .modification5 = SIGNATURE_MOD_PSS_CHANGE,
        .variable5 = SPLIT_SPECIAL,
        .modification6 = SIGNATURE_MOD_TYPE,
        .variable6 = TYPE_GHOST,
    },
    [SPECIES_CHANDELURE_MEGA] =
    {
        .move = MOVE_WILL_O_WISP,
        .differentDescription = TRUE,
        .description = _("Becomes an special 90 BP Ghost-type move that can burn the target, blocks the target from curing itself and cures some"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_ABSORB,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance3 = 35,
        .modification4 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable4 = SIGNATURE_SECONDARY_EFFECT_SET_HEAL_BLOCK,
        .modification5 = SIGNATURE_MOD_PSS_CHANGE,
        .variable5 = SPLIT_SPECIAL,
        .modification6 = SIGNATURE_MOD_TYPE,
        .variable6 = TYPE_GHOST,
    },
    [SPECIES_SAWK] =
    {
        .move = MOVE_ROCK_SMASH,
        .differentDescription = TRUE,
        .description = _("Becomes a move with a 50% chance of setting up Stealth Rock and raises the user's Attack by 1 stage with a 50% chance."),
        .modification = SIGNATURE_MOD_MODIFY_FIELD,
        .variable = FIELD_OPPONET_SET_STEALTH_ROCK,
        .chance = 50,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_ATK,
        .chance2 = 50,
    },
    [SPECIES_VENIPEDE] =
    {
        .move = MOVE_ROLLOUT,
        .differentDescription = TRUE,
        .description = _("Becomes a Bug-type move that raises the user defense and may flinch the target"),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_BUG,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_DEF,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance3 = 10,
    },
    [SPECIES_WHIRLIPEDE] =
    {
        .move = MOVE_ROLLOUT,
        .differentDescription = TRUE,
        .description = _("Becomes a Poison-type move that raises the user speed and may poison the target"),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_POISON,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_SPEED,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_POISON,
        .chance3 = 10,
    },
    [SPECIES_SCOLIPEDE] =
    {
        .move = MOVE_ROLLOUT,
        .differentDescription = TRUE,
        .description = _("Becomes a Bug-type move that raises the user attack and may flinch the target"),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_BUG,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_ATK,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance3 = 10,
    },
    [SPECIES_SCOLIPEDE_MEGA] =
    {
        .move = MOVE_ROLLOUT,
        .differentDescription = TRUE,
        .description = _("Becomes a Poison-type move that raises the user defense and may paralyze the target"),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_POISON,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_DEF,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_PARALYSIS,
        .chance3 = 20,
    },
    [SPECIES_JOLTIK] =
    {
        .move = MOVE_ELECTROWEB,
        .differentDescription = TRUE,
        .description = _("Becomes a 70BP move that sets up Sticky Web."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 70,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_OPPONET_SET_STICKY_WEB,
    },
    [SPECIES_GALVANTULA] =
    {
        .move = MOVE_ELECTROWEB,
        .differentDescription = TRUE,
        .description = _("Becomes a 75BP move that sets up Sticky Web."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 75,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_OPPONET_SET_STICKY_WEB,
    },
    [SPECIES_BOUFFALANT] =
    {
        .move = MOVE_HEAD_CHARGE,
        .differentDescription = TRUE,
        .description = _("Becomes a 140 BP move."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 140,
    },
    [SPECIES_GOLURK] =
    {
        .move = MOVE_SHADOW_PUNCH,
        .differentDescription = TRUE,
        .description = _("Becomes a move 90BP with a 25% chance of lowering the target's defense, becomes a priority move in Trick Room."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_TARGET_STAT_DOWN,
        .variable2 = STAT_DEF,
        .chance2 = 25,
    },
    [SPECIES_GOLURK_MEGA] =
    {
        .move = MOVE_SHADOW_PUNCH,
        .differentDescription = TRUE,
        .description = _("Becomes a move 95BP with a 30% chance of lowering the target's defense, becomes a priority move in Trick Room and drai"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_TARGET_STAT_DOWN,
        .variable2 = STAT_DEF,
        .chance2 = 30,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_DRAIN,
        .argument3 = 50,
    },
    [SPECIES_VOLCARONA] =
    {
        .move = MOVE_FIERY_DANCE,
        .differentDescription = TRUE,
        .description = _("Becomes a 90 BP move that has a higher chance to boost the user Sp.Atk and can burn the target."),
        .modification = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable = 75,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_POWER,
        .variable3 = 90,
    },
    [SPECIES_SLITHER_WING] =
    {
        .move = MOVE_SUPERPOWER,
        .differentDescription = TRUE,
        .description = _("Becomes a 90 BP move that has a high chance to boost the user Atk and can set up the sun, no longer lowers stats."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_ATTACK_UP_HIT,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable2 = 75,
        .modification3 = SIGNATURE_MOD_POWER,
        .variable3 = 90,
        .modification4 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable4 = FIELD_SET_WEATHER_SUN,
        .chance4 = 20,
    },
    [SPECIES_ZWEILOUS] =
    {
        .move = MOVE_DRAGON_BREATH,
        .differentDescription = TRUE,
        .description = _("Becomes a 45 BP move that hits the target 2 times."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 45,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_DOUBLE_HIT,
    },
    [SPECIES_HYDREIGON] =
    {
        .move = MOVE_DRAGON_PULSE,
        .differentDescription = TRUE,
        .description = _("Becomes a 30 BP move that hits the target 3 times, can paralyze the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 30,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_TRIPLE_KICK,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_PARALYSIS,
        .chance3 = 10,
    },
    [SPECIES_CHESNAUGHT] =
    {
        .move = MOVE_HAMMER_ARM,
        .differentDescription = TRUE,
        .description = _("Power becomes 110 and becomes a Fighting and Grass-type move with a 30% chance of leeching the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 110,
        .modification2 = SIGNATURE_MOD_SECOND_TYPE,
        .variable2 = TYPE_GRASS,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_LEECH_SEED,
        .chance3 = 30,
    },
    [SPECIES_CHESNAUGHT_MEGA] =
    {
        .move = MOVE_HAMMER_ARM,
        .differentDescription = TRUE,
        .description = _("Power becomes 110 and becomes a Fighting and Grass-type move with a 30% chance of leeching the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 110,
        .modification2 = SIGNATURE_MOD_SECOND_TYPE,
        .variable2 = TYPE_GRASS,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_LEECH_SEED,
        .chance3 = 30,
    },
    [SPECIES_DELPHOX] =
    {
        .move = MOVE_MYSTICAL_FIRE,
        .differentDescription = TRUE,
        .description = _("Power becomes 85 and becomes a Fire and Psychic-type move with a 30% chance of confusing the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 85,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_CONFUSION,
        .chance2 = 30,
        .modification3 = SIGNATURE_MOD_SECOND_TYPE,
        .variable3 = TYPE_PSYCHIC,
    },
    [SPECIES_DELPHOX_MEGA] =
    {
        .move = MOVE_MYSTICAL_FIRE,
        .differentDescription = TRUE,
        .description = _("Power becomes 85 and becomes a Fire and Psychic-type move with a 30% chance of confusing the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 85,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_CONFUSION,
        .chance2 = 30,
        .modification3 = SIGNATURE_MOD_SECOND_TYPE,
        .variable3 = TYPE_PSYCHIC,
    },
    [SPECIES_GRENINJA] =
    {
        .move = MOVE_WATER_SHURIKEN,
        .differentDescription = TRUE,
        .description = _("Becomes a 20BP Water and Dark type move that always hits 3 times."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 20,
        .modification2 = SIGNATURE_MOD_SECOND_TYPE,
        .variable2 = TYPE_DARK,
        .modification3 = SIGNATURE_MOD_MULTI_HIT_ALWAYS,
        .variable3 = 3,
    },
    [SPECIES_GRENINJA_MEGA] =
    {
        .move = MOVE_WATER_SHURIKEN,
        .differentDescription = TRUE,
        .description = _("Becomes a 25BP Water and Dark type move that always hits 4 times."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 22,
        .modification2 = SIGNATURE_MOD_SECOND_TYPE,
        .variable2 = TYPE_DARK,
        .modification3 = SIGNATURE_MOD_MULTI_HIT_ALWAYS,
        .variable3 = 4,
    },
    [SPECIES_GRENINJA_ASH] =
    {
        .move = MOVE_WATER_SHURIKEN,
        .differentDescription = TRUE,
        .description = _("Becomes a 22BP Water and Dark type move that always hits 3 times."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 22,
        .modification2 = SIGNATURE_MOD_SECOND_TYPE,
        .variable2 = TYPE_DARK,
        .modification3 = SIGNATURE_MOD_MULTI_HIT_ALWAYS,
        .variable3 = 3,
    },
    [SPECIES_DIGGERSBY] =
    {
        .move = MOVE_BODY_SLAM,
        .differentDescription = TRUE,
        .description = _("Becomes a 65 BP priority move that hits SE against Ghost-types, it has a lower chance of paralyzing the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 65,
        .modification2 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable2 = TYPE_GHOST,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable3 = 10,
        .modification4 = SIGNATURE_MOD_PRIORITY,
        .variable4 = SIGNATURE_PRIORITY_ALWAYS,
    },
    [SPECIES_TYRUNT] =
    {
        .move = MOVE_CRUNCH,
        .differentDescription = TRUE,
        .description = _("Becomes a Dragon-type move that ignores the target's defense stat changes."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_DRAGON,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
    },
    [SPECIES_TYRANTRUM] =
    {
        .move = MOVE_CRUNCH,
        .differentDescription = TRUE,
        .description = _("Becomes a Dragon-type move that ignores the target's defense stat changes."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_DRAGON,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
    },
    [SPECIES_TREVENANT] =
    {
        .move = MOVE_WOOD_HAMMER,
        .differentDescription = TRUE,
        .description = _("Becomes a Grass/Ghost-type move with a 30% chance of giving the target the Ghost-type."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_GIVE_THIRD_TYPE,
        .argument = TYPE_GHOST,
        .chance = 30,
        .modification2 = SIGNATURE_MOD_SECOND_TYPE,
        .variable2 = TYPE_GHOST,
    },
    [SPECIES_GOURGEIST] =
    {
        .move = MOVE_WILL_O_WISP,
        .differentDescription = TRUE,
        .description = _("Becomes a 80 BP Fire/Ghost move that can burn the target and gives it the Ghost-type."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 70,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance3 = 20,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_HIGHEST,
        .modification5 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable5 = SIGNATURE_SECONDARY_EFFECT_GIVE_THIRD_TYPE,
        .argument5 = TYPE_GHOST,
        .modification6 = SIGNATURE_MOD_SECOND_TYPE,
        .variable6 = TYPE_GHOST,
    },
    [SPECIES_GOURGEIST_LARGE] =
    {
        .move = MOVE_WILL_O_WISP,
        .differentDescription = TRUE,
        .description = _("Becomes a 80 BP Fire/Ghost move that can burn the target and gives it the Ghost-type."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 70,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance3 = 20,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_HIGHEST,
        .modification5 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable5 = SIGNATURE_SECONDARY_EFFECT_GIVE_THIRD_TYPE,
        .argument5 = TYPE_GHOST,
        .modification6 = SIGNATURE_MOD_SECOND_TYPE,
        .variable6 = TYPE_GHOST,
    },
    [SPECIES_GOURGEIST_SMALL] =
    {
        .move = MOVE_WILL_O_WISP,
        .differentDescription = TRUE,
        .description = _("Becomes a 80 BP Fire/Ghost move that can burn the target and gives it the Ghost-type."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 70,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance3 = 20,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_HIGHEST,
        .modification5 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable5 = SIGNATURE_SECONDARY_EFFECT_GIVE_THIRD_TYPE,
        .argument5 = TYPE_GHOST,
        .modification6 = SIGNATURE_MOD_SECOND_TYPE,
        .variable6 = TYPE_GHOST,
    },
    [SPECIES_GOURGEIST_SUPER] =
    {
        .move = MOVE_WILL_O_WISP,
        .differentDescription = TRUE,
        .description = _("Becomes a 80 BP Fire/Ghost move that can burn the target and gives it the Ghost-type."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 70,
        .modification2 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable2 = EFFECT_HIT,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance3 = 20,
        .modification4 = SIGNATURE_MOD_PSS_CHANGE,
        .variable4 = SPLIT_HIGHEST,
        .modification5 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable5 = SIGNATURE_SECONDARY_EFFECT_GIVE_THIRD_TYPE,
        .argument5 = TYPE_GHOST,
        .modification6 = SIGNATURE_MOD_SECOND_TYPE,
        .variable6 = TYPE_GHOST,
    },
    [SPECIES_MALAMAR] =
    {
        .move = MOVE_EXPANDING_FORCE,
        .differentDescription = TRUE,
        .description = _("Becomes a 90 BP move that uses the user's highest attack stat and can put the target to sleep."),
        .modification = SIGNATURE_MOD_PSS_CHANGE,
        .variable = SPLIT_HIGHEST,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_SLEEP,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_POWER,
        .variable3 = 90,
    },
    [SPECIES_NOIBAT] =
    {
        .move = MOVE_SUPERSONIC,
        .differentDescription = TRUE,
        .description = _("Becomes a 60 BP Flying-type move that can confuse the target."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_FLYING,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 60,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable3 = EFFECT_CONFUSE_HIT,
        .modification4 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable4 = 20,
        .modification5 = SIGNATURE_MOD_PSS_CHANGE,
        .variable5 = SPLIT_SPECIAL,
    },
    [SPECIES_NOIVERN] =
    {
        .move = MOVE_SUPERSONIC,
        .differentDescription = TRUE,
        .description = _("Becomes a 80 BP Flying-type move that can confuse the target."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_FLYING,
        .modification2 = SIGNATURE_MOD_POWER,
        .variable2 = 80,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable3 = EFFECT_CONFUSE_HIT,
        .modification4 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable4 = 20,
        .modification5 = SIGNATURE_MOD_PSS_CHANGE,
        .variable5 = SPLIT_SPECIAL,
    },
    [SPECIES_HONEDGE] =
    {
        .move = MOVE_SLASH,
        .differentDescription = TRUE,
        .description = _("Becomes a 85BP Ghost-type move that ignores the target's defense and steals half the damage inflicted."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_GHOST,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable3 = EFFECT_ABSORB,
    },
    [SPECIES_DOUBLADE] =
    {
        .move = MOVE_SLASH,
        .differentDescription = TRUE,
        .description = _("Becomes a Ghost-type 45 BP move that ignores the target's defense and hits twice."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_GHOST,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
        .modification3 = SIGNATURE_MOD_POWER,
        .variable3 = 45,
        .modification4 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable4 = EFFECT_DOUBLE_HIT,
    },
    [SPECIES_AEGISLASH] =
    {
        .move = MOVE_SLASH,
        .differentDescription = TRUE,
        .description = _("Becomes a 90BP Ghost-type move that ignores the target's defense."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_GHOST,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
        .modification3 = SIGNATURE_MOD_POWER,
        .variable3 = 90,
    },
    [SPECIES_AEGISLASH_BLADE] =
    {
        .move = MOVE_SLASH,
        .differentDescription = TRUE,
        .description = _("Becomes a 90BP Ghost-type move that ignores the target's defense."),
        .modification = SIGNATURE_MOD_TYPE,
        .variable = TYPE_GHOST,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
        .modification3 = SIGNATURE_MOD_POWER,
        .variable3 = 90,
    },
    [SPECIES_FLORGES] =
    {
        .move = MOVE_MOONBLAST,
        .differentDescription = TRUE,
        .description = _("Becomes a 100BP move that can set up Misty Terrain and has a 35% chance of lowering the target's Special Attack by 1 s"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 100,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_SET_TERRAIN_MISTY,
        .chance2 = 35,
    },
    [SPECIES_DECIDUEYE] =
    {
        .move = MOVE_SPIRIT_SHACKLE,
        .differentDescription = TRUE,
        .description = _("Becomes a 90BP move that can curse the target and has a high crit ratio."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_CURSE,
        .chance2 = 10,
        .modification3 = SIGNATURE_MOD_ADD_FLAG,
        .variable3 = FLAG_HIGH_CRIT,
    },
    [SPECIES_DECIDUEYE_HISUI] =
    {
        .move = MOVE_LOW_SWEEP,
        .differentDescription = TRUE,
        .description = _("Becomes a 90 BP move that can flinch the target and lower its defense stat also becomes high-crit."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_TARGET_STAT_DOWN,
        .variable2 = STAT_DEF,
        .chance2 = 50,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance3 = 30,
        .modification4 = SIGNATURE_MOD_ADD_FLAG,
        .variable4 = FLAG_HIGH_CRIT,
    },
    [SPECIES_INCINEROAR] =
    {
        .move = MOVE_DARKEST_LARIAT,
        .differentDescription = TRUE,
        .description = _("Becomes a 95BP move that can burn the target and its super-effective against Fighting-Types."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance2 = 20,
        .modification3 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable3 = TYPE_FIGHTING,
    },
    [SPECIES_PRIMARINA] =
    {
        .move = MOVE_SPARKLING_ARIA,
        .differentDescription = TRUE,
        .description = _("Becomes a 110BP move that no longer heals burn from the target and does not hit allies."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 110,
        .modification2 = SIGNATURE_MOD_CHANGE_TARGET,
        .variable2 = MOVE_TARGET_BOTH,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable3 = EFFECT_HIT,
    },
    [SPECIES_PALOSSAND] =
    {
        .move = MOVE_SHORE_UP,
        .differentDescription = TRUE,
        .description = _("Becomes a move that sets up Sandstorm with a 30% chance."),
        .modification = SIGNATURE_MOD_MODIFY_FIELD,
        .variable = FIELD_SET_WEATHER_SANDSTORM,
        .chance = 30,
    },
    [SPECIES_WIMPOD] =
    {
        .move = MOVE_AQUA_JET,
        .differentDescription = TRUE,
        .description = _("May lower the target Defense and ignores it if higher."),
        .modification = SIGNATURE_MOD_PENETRATING,
        .variable = 0,
        .modification2 = SIGNATURE_MOD_TARGET_STAT_DOWN,
        .variable2 = STAT_DEF,
        .chance2 = 25,
    },
    [SPECIES_GOLISOPOD] =
    {
        .move = MOVE_FIRST_IMPRESSION,
        .differentDescription = TRUE,
        .description = _("May lower the target Defense and ignores it if higher."),
        .modification = SIGNATURE_MOD_TARGET_STAT_DOWN,
        .variable = STAT_DEF,
        .chance = 50,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
    },
    [SPECIES_ORICORIO] =
    {
        .move = MOVE_REVELATION_DANCE,
        .differentDescription = TRUE,
        .description = _("Becomes a move Fire/Flying move with a 20% chance of burning the target."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance = 20,
        .modification2 = SIGNATURE_MOD_SECOND_TYPE,
        .variable2 = TYPE_FLYING,
    },
    [SPECIES_ORICORIO_POM_POM] =
    {
        .move = MOVE_REVELATION_DANCE,
        .differentDescription = TRUE,
        .description = _("Becomes a move Electric/Flying move 20% chance of paralyzing the target."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_PARALYSIS,
        .chance = 20,
        .modification2 = SIGNATURE_MOD_SECOND_TYPE,
        .variable2 = TYPE_FLYING,
    },
    [SPECIES_ORICORIO_PAU] =
    {
        .move = MOVE_REVELATION_DANCE,
        .differentDescription = TRUE,
        .description = _("Becomes a move Psychic/Flying move 20% chance of confusing the target."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_CONFUSION,
        .chance = 20,
        .modification2 = SIGNATURE_MOD_SECOND_TYPE,
        .variable2 = TYPE_FLYING,
    },
    [SPECIES_ORICORIO_SENSU] =
    {
        .move = MOVE_REVELATION_DANCE,
        .differentDescription = TRUE,
        .description = _("Becomes a move Ghost/Flying move 20% chance of cursing the target."),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_CURSE,
        .chance = 15,
        .modification2 = SIGNATURE_MOD_SECOND_TYPE,
        .variable2 = TYPE_FLYING,
    },
    [SPECIES_COMFEY] =
    {
        .move = MOVE_DRAINING_KISS,
        .differentDescription = TRUE,
        .description = _("Becomes a 70 BP that leeches the target and may boost the user Special Attack."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 70,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_LEECH_SEED,
        .chance2 = 50,
        .modification3 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable3 = STAT_SPATK,
        .chance3 = 10,
    },
    [SPECIES_TOGEDEMARU] =
    {
        .move = MOVE_PIN_MISSILE,
        .differentDescription = TRUE,
        .description = _("Becomes a 25BP Steel-type move that boosts the user's Speed but lowers its Defense."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_SCALE_SHOT,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_STEEL,
        .modification3 = SIGNATURE_MOD_POWER,
        .variable3 = 25,
    },
    [SPECIES_RILLABOOM] =
    {
        .move = MOVE_DRUM_BEATING,
        .differentDescription = TRUE,
        .description = _("Becomes a 95BP sound move that ignores the target stat changes and can seed the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_ADD_FLAG,
        .variable2 = FLAG_SOUND,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_LEECH_SEED,
        .chance3 = 20,
        .modification4 = SIGNATURE_MOD_ADD_FLAG,
        .variable4 = FLAG_STAT_STAGES_IGNORED,
    },
    [SPECIES_RILLABOOM_MEGA] =
    {
        .move = MOVE_DRUM_BEATING,
        .differentDescription = TRUE,
        .description = _("Becomes a 95BP sound move that ignores the target stat changes and can seed the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_ADD_FLAG,
        .variable2 = FLAG_SOUND,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_LEECH_SEED,
        .chance3 = 20,
        .modification4 = SIGNATURE_MOD_ADD_FLAG,
        .variable4 = FLAG_STAT_STAGES_IGNORED,
    },
    [SPECIES_INTELEON] =
    {
        .move = MOVE_SNIPE_SHOT,
        .differentDescription = TRUE,
        .description = _("Becomes a 95BP move that ignores the target defense and can flinch the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance3 = 10,
    },
    [SPECIES_INTELEON_MEGA] =
    {
        .move = MOVE_SNIPE_SHOT,
        .differentDescription = TRUE,
        .description = _("Becomes a 95BP move that ignores the target defense and can flinch the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_ADD_FLAG,
        .variable2 = FLAG_STAT_STAGES_IGNORED,
        .modification3 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable3 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance3 = 10,
    },
    [SPECIES_CINDERACE] =
    {
        .move = MOVE_PYRO_BALL,
        .differentDescription = TRUE,
        .description = _("Becomes a move that bypasses Protect with a 20% chance of burning the target."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_FEINT,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance2 = 20,
    },
    [SPECIES_CINDERACE_MEGA] =
    {
        .move = MOVE_PYRO_BALL,
        .differentDescription = TRUE,
        .description = _("Becomes a move that bypasses Protect with a 20% chance of burning the target."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_FEINT,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance2 = 20,
    },
    [SPECIES_CORVIKNIGHT] =
    {
        .move = MOVE_BRAVE_BIRD,
        .differentDescription = TRUE,
        .description = _("Doesn't take damage from recoil and may flinch the target."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_HIT,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance2 = 10,
    },
    [SPECIES_CORVIKNIGHT_MEGA] =
    {
        .move = MOVE_BRAVE_BIRD,
        .differentDescription = TRUE,
        .description = _("Doesn't take damage from recoil and may boost the user speed."),
        .modification = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable = EFFECT_HIT,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_SPEED,
        .chance2 = 15,
    },
    [SPECIES_CHEWTLE] =
    {
        .move = MOVE_JAW_LOCK,
        .differentDescription = TRUE,
        .description = _("Becomes a 90 BP Water-type move."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_WATER,
    },
    [SPECIES_DREDNAW] =
    {
        .move = MOVE_JAW_LOCK,
        .differentDescription = TRUE,
        .description = _("Becomes a 90 BP Rock-type move."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 90,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_ROCK,
    },
    [SPECIES_DREDNAW_MEGA] =
    {
        .move = MOVE_JAW_LOCK,
        .differentDescription = TRUE,
        .description = _("Becomes a 95 BP Rock-type move that ignores the target defense."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_TYPE,
        .variable2 = TYPE_ROCK,
        .modification3 = SIGNATURE_MOD_PENETRATING,
        .variable3 = 0,
    },
    [SPECIES_HATTERENE] =
    {
        .move = MOVE_PSYCHO_CUT,
        .differentDescription = TRUE,
        .description = _("Becomes a 80 BP move that uses the highest attacking stat for damage calculation, it can also flinch and becomes SE ag"),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance = 10,
        .modification2 = SIGNATURE_MOD_PSS_CHANGE,
        .variable2 = SPLIT_HIGHEST,
        .modification3 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable3 = TYPE_STEEL,
        .modification4 = SIGNATURE_MOD_POWER,
        .variable4 = 80,
    },
    [SPECIES_HATTERENE_MEGA] =
    {
        .move = MOVE_PSYCHO_CUT,
        .differentDescription = TRUE,
        .description = _("Becomes a 85 BP move that uses the highest attacking stat for damage calculation, it can also flinch the target and be"),
        .modification = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance = 20,
        .modification2 = SIGNATURE_MOD_PSS_CHANGE,
        .variable2 = SPLIT_HIGHEST,
        .modification3 = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable3 = TYPE_STEEL,
        .modification4 = SIGNATURE_MOD_POWER,
        .variable4 = 85,
    },
    [SPECIES_DRACOVISH] =
    {
        .move = MOVE_FISHIOUS_REND,
        .differentDescription = TRUE,
        .description = _("Becomes a 95BP move that ignores the target defense."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_PENETRATING,
        .variable2 = 0,
    },
    [SPECIES_ARCTOVISH] =
    {
        .move = MOVE_FISHIOUS_REND,
        .differentDescription = TRUE,
        .description = _("Becomes a 95 BP move that may boost the user speed."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_SPEED,
        .chance2 = 20,
    },
    [SPECIES_DRACOZOLT] =
    {
        .move = MOVE_BOLT_BEAK,
        .differentDescription = TRUE,
        .description = _("Becomes a 95 BP move that may boost the user speed."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_SPEED,
        .chance2 = 20,
    },
    [SPECIES_ARCTOZOLT] =
    {
        .move = MOVE_BOLT_BEAK,
        .differentDescription = TRUE,
        .description = _("Becomes a 95 BP move that may boost the user speed."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 95,
        .modification2 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable2 = STAT_SPEED,
        .chance2 = 20,
    },
    [SPECIES_KLEAVOR] =
    {
        .move = MOVE_HAMMER_ARM,
        .differentDescription = TRUE,
        .description = _("Becomes a 75 BP Rock-type move sets up Stealth Rock when used and no longer lowers the user speed, can flinch the targ"),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 75,
        .modification2 = SIGNATURE_MOD_MODIFY_FIELD,
        .variable2 = FIELD_OPPONET_SET_STEALTH_ROCK,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable3 = EFFECT_HIT,
        .modification4 = SIGNATURE_MOD_TYPE,
        .variable4 = TYPE_ROCK,
        .modification5 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable5 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance5 = 10,
    },
    [SPECIES_MEOWSCARADA] =
    {
        .move = MOVE_FLOWER_TRICK,
        .differentDescription = TRUE,
        .description = _("Becomes a 75 BP move that may seed the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 75,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_LEECH_SEED,
        .chance2 = 30,
    },
    [SPECIES_QUAQUAVAL] =
    {
        .move = MOVE_AQUA_STEP,
        .differentDescription = TRUE,
        .description = _("Becomes a 80 BP move that may flinch the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance2 = 15,
    },
    [SPECIES_SKELEDIRGE] =
    {
        .move = MOVE_TORCH_SONG,
        .differentDescription = TRUE,
        .description = _("Becomes a 80 BP move that may burn the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance2 = 20,
    },
    [SPECIES_TINKATON] =
    {
        .move = MOVE_GIGATON_HAMMER,
        .differentDescription = TRUE,
        .description = _("Becomes super effective against Steel-types and can flinch the target, no longer makes contact."),
        .modification = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable = TYPE_STEEL,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance2 = 15,
        .modification3 = SIGNATURE_MOD_REMOVE_FLAG,
        .variable3 = FLAG_MAKES_CONTACT,
    },
    [SPECIES_CERULEDGE] =
    {
        .move = MOVE_BITTER_BLADE,
        .differentDescription = TRUE,
        .description = _("Becomes super effective against Water types and can burn the target."),
        .modification = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable = TYPE_WATER,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance2 = 20,
    },
    [SPECIES_ARMAROUGE] =
    {
        .move = MOVE_ARMOR_CANNON,
        .differentDescription = TRUE,
        .description = _("Becomes super effective against Water types and can burn the target."),
        .modification = SIGNATURE_MOD_SE_AGAINST_TYPE,
        .variable = TYPE_WATER,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_BURN,
        .chance2 = 30,
    },
    [SPECIES_WUGTRIO] =
    {
        .move = MOVE_TRIPLE_DIVE,
        .differentDescription = TRUE,
        .description = _("Becomes a 35 BP move that hits the target 3 times, can flinch the target."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 35,
        .modification2 = SIGNATURE_MOD_SECONDARY_EFFECT,
        .variable2 = SIGNATURE_SECONDARY_EFFECT_FLINCH,
        .chance2 = 10,
    },
    [SPECIES_TANDEMAUS] =
    {
        .move = MOVE_SCRATCH,
        .differentDescription = TRUE,
        .description = _("Becomes a 20BP move that can hit up to 10 times."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 20,
        .modification2 = SIGNATURE_MOD_MULTI_HIT_MAX_TIMES,
        .variable2 = 10,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable3 = EFFECT_MULTI_HIT,
    },
    [SPECIES_MAUSHOLD] =
    {
        .move = MOVE_SCRATCH,
        .differentDescription = TRUE,
        .description = _("Becomes a 20BP move that can hit up to 10 times."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 20,
        .modification2 = SIGNATURE_MOD_MULTI_HIT_MAX_TIMES,
        .variable2 = 10,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable3 = EFFECT_MULTI_HIT,
    },
    [SPECIES_MAUSHOLD_FOUR] =
    {
        .move = MOVE_SCRATCH,
        .differentDescription = TRUE,
        .description = _("Becomes a 20BP move that can hit up to 10 times."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 20,
        .modification2 = SIGNATURE_MOD_MULTI_HIT_MAX_TIMES,
        .variable2 = 10,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANGE,
        .variable3 = EFFECT_MULTI_HIT,
    },
    [SPECIES_CYCLIZAR] =
    {
        .move = MOVE_DRAGON_RUSH,
        .differentDescription = TRUE,
        .description = _("Becomes a 80 BP move with 95% accuracy, can flinch the target or raise the user attack."),
        .modification = SIGNATURE_MOD_POWER,
        .variable = 80,
        .modification2 = SIGNATURE_MOD_ACCURACY,
        .variable2 = 95,
        .modification3 = SIGNATURE_MOD_EFFECT_CHANCE,
        .variable3 = 10,
        .modification4 = SIGNATURE_MOD_ATTACKER_STAT_UP,
        .variable4 = STAT_ATK,
        .chance4 = 30,
    },
    [SPECIES_NONE] =
    {
        .move = MOVE_NONE,
        .differentDescription = FALSE,
        .description = _("Default Description"),
        .modification = SIGNATURE_MOD_NONE,
        .variable = 0,
    },
// ROWESIG-PORT-END

};