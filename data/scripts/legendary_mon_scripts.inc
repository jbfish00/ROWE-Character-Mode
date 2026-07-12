Common_EventScript_SetLegendaryDefaultData::
# 4 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_TOTEM_BATTLE
# 5 "data/scripts/legendary_mon_scripts.pory"
	setvar VAR_NUM_WILD_POKEMON_STAT_BOOST, 2
# 6 "data/scripts/legendary_mon_scripts.pory"
	setvar VAR_BOSS_BATTLE_HP_MULTIPIER, LEGENDARY_HP_MULTIPLIER
	return


TerraCave_End_EventScript_Groudon::
# 11 "data/scripts/legendary_mon_scripts.pory"
	lockall
# 12 "data/scripts/legendary_mon_scripts.pory"
	call Common_EventScript_SetLegendaryDefaultData
# 13 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_MEGA_EVOLVE_WILD_POKEMON
# 14 "data/scripts/legendary_mon_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 15 "data/scripts/legendary_mon_scripts.pory"
	waitmovement 0
# 16 "data/scripts/legendary_mon_scripts.pory"
	applymovement LOCALID_GROUDON, TerraCave_End_Movement_GroudonApproach
# 17 "data/scripts/legendary_mon_scripts.pory"
	waitmovement 0
# 18 "data/scripts/legendary_mon_scripts.pory"
	waitse
# 19 "data/scripts/legendary_mon_scripts.pory"
	playmoncry SPECIES_GROUDON, 2
# 20 "data/scripts/legendary_mon_scripts.pory"
	delay 40
# 21 "data/scripts/legendary_mon_scripts.pory"
	waitmoncry
# 22 "data/scripts/legendary_mon_scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_GROUDON
# 23 "data/scripts/legendary_mon_scripts.pory"
	setwildbattlewithcustommoves SPECIES_GROUDON, 75, ITEM_RED_ORB, MOVE_PRECIPICE_BLADES, MOVE_HEAT_CRASH, MOVE_HAMMER_ARM, MOVE_HEAVY_SLAM, 0, NATURE_ADAMANT
# 24 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 25 "data/scripts/legendary_mon_scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 26 "data/scripts/legendary_mon_scripts.pory"
	waitstate
# 27 "data/scripts/legendary_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 28 "data/scripts/legendary_mon_scripts.pory"
	setvar VAR_TEMP_1, 0
# 29 "data/scripts/legendary_mon_scripts.pory"
	switch VAR_RESULT
# 30 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, TerraCave_End_EventScript_Groudon_3
# 37 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_RAN, TerraCave_End_EventScript_Groudon_4
# 38 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_WON, TerraCave_End_EventScript_Groudon_4
# 39 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, TerraCave_End_EventScript_Groudon_4
TerraCave_End_EventScript_Groudon_1:
# 46 "data/scripts/legendary_mon_scripts.pory"
	release
	end

TerraCave_End_EventScript_Groudon_3:
# 31 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_DEFEATED_GROUDON
# 32 "data/scripts/legendary_mon_scripts.pory"
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
# 33 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 34 "data/scripts/legendary_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 35 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto TerraCave_End_EventScript_Groudon_1

TerraCave_End_EventScript_Groudon_4:
# 40 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 41 "data/scripts/legendary_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 42 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 43 "data/scripts/legendary_mon_scripts.pory"
	msgbox TerraCave_End_EventScript_Groudon_Text_0, MSGBOX_DEFAULT
	goto TerraCave_End_EventScript_Groudon_1


MarineCave_End_EventScript_Kyogre::
# 51 "data/scripts/legendary_mon_scripts.pory"
	lockall
# 52 "data/scripts/legendary_mon_scripts.pory"
	call Common_EventScript_SetLegendaryDefaultData
# 53 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_MEGA_EVOLVE_WILD_POKEMON
# 54 "data/scripts/legendary_mon_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 55 "data/scripts/legendary_mon_scripts.pory"
	waitmovement 0
# 56 "data/scripts/legendary_mon_scripts.pory"
	applymovement LOCALID_KYOGRE, MarineCave_End_Movement_KyogreApproach
# 57 "data/scripts/legendary_mon_scripts.pory"
	waitmovement 0
# 58 "data/scripts/legendary_mon_scripts.pory"
	waitse
# 59 "data/scripts/legendary_mon_scripts.pory"
	playmoncry SPECIES_KYOGRE, 2
# 60 "data/scripts/legendary_mon_scripts.pory"
	delay 40
# 61 "data/scripts/legendary_mon_scripts.pory"
	waitmoncry
# 62 "data/scripts/legendary_mon_scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_KYOGRE
# 63 "data/scripts/legendary_mon_scripts.pory"
	setwildbattlewithcustommoves SPECIES_KYOGRE, 75, ITEM_BLUE_ORB, MOVE_ORIGIN_PULSE, MOVE_ICE_BEAM, MOVE_THUNDER, MOVE_ANCIENT_POWER, 0, NATURE_MODEST
# 64 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 65 "data/scripts/legendary_mon_scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 66 "data/scripts/legendary_mon_scripts.pory"
	waitstate
# 67 "data/scripts/legendary_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 68 "data/scripts/legendary_mon_scripts.pory"
	setvar VAR_TEMP_1, 0
# 69 "data/scripts/legendary_mon_scripts.pory"
	switch VAR_RESULT
# 70 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, MarineCave_End_EventScript_Kyogre_3
# 77 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_RAN, MarineCave_End_EventScript_Kyogre_4
# 78 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_WON, MarineCave_End_EventScript_Kyogre_4
# 79 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, MarineCave_End_EventScript_Kyogre_4
MarineCave_End_EventScript_Kyogre_1:
# 86 "data/scripts/legendary_mon_scripts.pory"
	release
	end

MarineCave_End_EventScript_Kyogre_3:
# 71 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_DEFEATED_KYOGRE
# 72 "data/scripts/legendary_mon_scripts.pory"
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
# 73 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 74 "data/scripts/legendary_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 75 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto MarineCave_End_EventScript_Kyogre_1

MarineCave_End_EventScript_Kyogre_4:
# 80 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 81 "data/scripts/legendary_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 82 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 83 "data/scripts/legendary_mon_scripts.pory"
	msgbox TerraCave_End_EventScript_Groudon_Text_0, MSGBOX_DEFAULT
	goto MarineCave_End_EventScript_Kyogre_1


Common_EventScript_Mesprit_Encounter::
# 91 "data/scripts/legendary_mon_scripts.pory"
	lock
# 92 "data/scripts/legendary_mon_scripts.pory"
	faceplayer
# 93 "data/scripts/legendary_mon_scripts.pory"
	call Common_EventScript_SetLegendaryDefaultData
# 94 "data/scripts/legendary_mon_scripts.pory"
	playmoncry SPECIES_MESPRIT, 2
# 95 "data/scripts/legendary_mon_scripts.pory"
	msgbox Common_EventScript_Mesprit_Encounter_Text_0
# 96 "data/scripts/legendary_mon_scripts.pory"
	setwildbattlewithcustommoves SPECIES_MESPRIT, 75, ITEM_LEFTOVERS, MOVE_PSYSHOCK, MOVE_DAZZLING_GLEAM, MOVE_GRASS_KNOT, MOVE_POWER_GEM, 0, NATURE_TIMID
# 97 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 98 "data/scripts/legendary_mon_scripts.pory"
	dowildbattle
# 99 "data/scripts/legendary_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 100 "data/scripts/legendary_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 101 "data/scripts/legendary_mon_scripts.pory"
	switch VAR_RESULT
# 102 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Mesprit_Encounter_3
# 108 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Mesprit_Encounter_4
# 109 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Mesprit_Encounter_4
# 110 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Mesprit_Encounter_4
Common_EventScript_Mesprit_Encounter_1:
# 117 "data/scripts/legendary_mon_scripts.pory"
	release
	end

Common_EventScript_Mesprit_Encounter_3:
# 103 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_DEFEATED_MESPRIT
# 104 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 105 "data/scripts/legendary_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 106 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Common_EventScript_Mesprit_Encounter_1

Common_EventScript_Mesprit_Encounter_4:
# 111 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 112 "data/scripts/legendary_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 113 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 114 "data/scripts/legendary_mon_scripts.pory"
	msgbox Common_EventScript_Mesprit_Encounter_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Mesprit_Encounter_1


Common_EventScript_Landorus_Encounter::
# 122 "data/scripts/legendary_mon_scripts.pory"
	lock
# 123 "data/scripts/legendary_mon_scripts.pory"
	faceplayer
# 124 "data/scripts/legendary_mon_scripts.pory"
	call Common_EventScript_SetLegendaryDefaultData
# 125 "data/scripts/legendary_mon_scripts.pory"
	playmoncry SPECIES_LANDORUS, 2
# 126 "data/scripts/legendary_mon_scripts.pory"
	msgbox Common_EventScript_Landorus_Encounter_Text_0
# 127 "data/scripts/legendary_mon_scripts.pory"
	setwildbattlewithcustommoves SPECIES_LANDORUS, 75, ITEM_LEFTOVERS, MOVE_EARTH_POWER, MOVE_SLUDGE_BOMB, MOVE_GRASS_KNOT, MOVE_CALM_MIND, 0, NATURE_TIMID
# 128 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 129 "data/scripts/legendary_mon_scripts.pory"
	dowildbattle
# 130 "data/scripts/legendary_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 131 "data/scripts/legendary_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 132 "data/scripts/legendary_mon_scripts.pory"
	switch VAR_RESULT
# 133 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Landorus_Encounter_3
# 139 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Landorus_Encounter_4
# 140 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Landorus_Encounter_4
# 141 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Landorus_Encounter_4
Common_EventScript_Landorus_Encounter_1:
# 148 "data/scripts/legendary_mon_scripts.pory"
	release
	end

Common_EventScript_Landorus_Encounter_3:
# 134 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_DEFEATED_LANDORUS
# 135 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 136 "data/scripts/legendary_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 137 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Common_EventScript_Landorus_Encounter_1

Common_EventScript_Landorus_Encounter_4:
# 142 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 143 "data/scripts/legendary_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 144 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 145 "data/scripts/legendary_mon_scripts.pory"
	msgbox Common_EventScript_Landorus_Encounter_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Landorus_Encounter_1


Common_EventScript_Darkrai_Encounter::
# 153 "data/scripts/legendary_mon_scripts.pory"
	call Common_EventScript_SetLegendaryDefaultData
# 154 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_MEGA_EVOLVE_WILD_POKEMON
# 155 "data/scripts/legendary_mon_scripts.pory"
	playmoncry SPECIES_DARKRAI, 2
# 156 "data/scripts/legendary_mon_scripts.pory"
	msgbox Common_EventScript_Darkrai_Encounter_Text_0
# 157 "data/scripts/legendary_mon_scripts.pory"
	setwildbattlewithcustommoves SPECIES_DARKRAI, 80, ITEM_DARKRAITE, MOVE_DARK_PULSE, MOVE_DARK_VOID, MOVE_PSYSHOCK, MOVE_SHADOW_BALL, 0, NATURE_TIMID
# 158 "data/scripts/legendary_mon_scripts.pory"
	dowildbattle
# 159 "data/scripts/legendary_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 160 "data/scripts/legendary_mon_scripts.pory"
	switch VAR_RESULT
# 161 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Darkrai_Encounter_3
# 169 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Darkrai_Encounter_4
# 170 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Darkrai_Encounter_4
# 171 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Darkrai_Encounter_4
Common_EventScript_Darkrai_Encounter_1:
# 179 "data/scripts/legendary_mon_scripts.pory"
	release
	end

Common_EventScript_Darkrai_Encounter_3:
# 162 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_DEFEATED_DARKRAI
# 163 "data/scripts/legendary_mon_scripts.pory"
	msgbox Common_EventScript_Darkrai_Encounter_Text_1, MSGBOX_DEFAULT
# 164 "data/scripts/legendary_mon_scripts.pory"
	playfanfare MUS_HEAL
# 165 "data/scripts/legendary_mon_scripts.pory"
	waitfanfare
# 166 "data/scripts/legendary_mon_scripts.pory"
	special HealPlayerParty
# 167 "data/scripts/legendary_mon_scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto Common_EventScript_Darkrai_Encounter_1

Common_EventScript_Darkrai_Encounter_4:
# 172 "data/scripts/legendary_mon_scripts.pory"
	msgbox Common_EventScript_Darkrai_Encounter_Text_1, MSGBOX_DEFAULT
# 173 "data/scripts/legendary_mon_scripts.pory"
	playfanfare MUS_HEAL
# 174 "data/scripts/legendary_mon_scripts.pory"
	waitfanfare
# 175 "data/scripts/legendary_mon_scripts.pory"
	special HealPlayerParty
# 176 "data/scripts/legendary_mon_scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto Common_EventScript_Darkrai_Encounter_1


Common_EventScript_Cobalion_Encounter::
# 184 "data/scripts/legendary_mon_scripts.pory"
	lock
# 185 "data/scripts/legendary_mon_scripts.pory"
	faceplayer
# 186 "data/scripts/legendary_mon_scripts.pory"
	call Common_EventScript_SetLegendaryDefaultData
# 187 "data/scripts/legendary_mon_scripts.pory"
	playmoncry SPECIES_COBALION, 2
# 188 "data/scripts/legendary_mon_scripts.pory"
	msgbox Common_EventScript_Cobalion_Encounter_Text_0
# 189 "data/scripts/legendary_mon_scripts.pory"
	setwildbattlewithcustommoves SPECIES_COBALION, 75, ITEM_STEEL_GEM, MOVE_POISON_JAB, MOVE_SACRED_SWORD, MOVE_IRON_HEAD, MOVE_ROCK_SLIDE, 0, NATURE_ADAMANT
# 190 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 191 "data/scripts/legendary_mon_scripts.pory"
	dowildbattle
# 192 "data/scripts/legendary_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 193 "data/scripts/legendary_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 194 "data/scripts/legendary_mon_scripts.pory"
	switch VAR_RESULT
# 195 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Cobalion_Encounter_3
# 201 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Cobalion_Encounter_4
# 202 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Cobalion_Encounter_4
# 203 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Cobalion_Encounter_4
Common_EventScript_Cobalion_Encounter_1:
# 210 "data/scripts/legendary_mon_scripts.pory"
	release
	end

Common_EventScript_Cobalion_Encounter_3:
# 196 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_DEFEATED_COBALION
# 197 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 198 "data/scripts/legendary_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 199 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Common_EventScript_Cobalion_Encounter_1

Common_EventScript_Cobalion_Encounter_4:
# 204 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 205 "data/scripts/legendary_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 206 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 207 "data/scripts/legendary_mon_scripts.pory"
	msgbox Common_EventScript_Cobalion_Encounter_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Cobalion_Encounter_1


Common_EventScript_Virizion_Encounter::
# 215 "data/scripts/legendary_mon_scripts.pory"
	lock
# 216 "data/scripts/legendary_mon_scripts.pory"
	faceplayer
# 217 "data/scripts/legendary_mon_scripts.pory"
	call Common_EventScript_SetLegendaryDefaultData
# 218 "data/scripts/legendary_mon_scripts.pory"
	playmoncry SPECIES_VIRIZION, 2
# 219 "data/scripts/legendary_mon_scripts.pory"
	msgbox Common_EventScript_Virizion_Encounter_Text_0
# 220 "data/scripts/legendary_mon_scripts.pory"
	setwildbattlewithcustommoves SPECIES_VIRIZION, 75, ITEM_GRASS_GEM, MOVE_LEAF_BLADE, MOVE_SACRED_SWORD, MOVE_X_SCISSOR, MOVE_STONE_EDGE, 0, NATURE_ADAMANT
# 221 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 222 "data/scripts/legendary_mon_scripts.pory"
	dowildbattle
# 223 "data/scripts/legendary_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 224 "data/scripts/legendary_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 225 "data/scripts/legendary_mon_scripts.pory"
	switch VAR_RESULT
# 226 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Virizion_Encounter_3
# 232 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Virizion_Encounter_4
# 233 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Virizion_Encounter_4
# 234 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Virizion_Encounter_4
Common_EventScript_Virizion_Encounter_1:
# 241 "data/scripts/legendary_mon_scripts.pory"
	release
	end

Common_EventScript_Virizion_Encounter_3:
# 227 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_DEFEATED_VIRIZION
# 228 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 229 "data/scripts/legendary_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 230 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Common_EventScript_Virizion_Encounter_1

Common_EventScript_Virizion_Encounter_4:
# 235 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 236 "data/scripts/legendary_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 237 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 238 "data/scripts/legendary_mon_scripts.pory"
	msgbox Common_EventScript_Virizion_Encounter_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Virizion_Encounter_1


Common_EventScript_Keldeo_Encounter::
# 246 "data/scripts/legendary_mon_scripts.pory"
	lock
# 247 "data/scripts/legendary_mon_scripts.pory"
	faceplayer
# 248 "data/scripts/legendary_mon_scripts.pory"
	playmoncry SPECIES_KELDEO, 2
# 249 "data/scripts/legendary_mon_scripts.pory"
	setvar VAR_BOSS_BATTLE_HP_MULTIPIER, LEGENDARY_HP_MULTIPLIER
# 250 "data/scripts/legendary_mon_scripts.pory"
	msgbox Common_EventScript_Keldeo_Encounter_Text_0
# 253 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_TOTEM_BATTLE
# 254 "data/scripts/legendary_mon_scripts.pory"
	setvar VAR_NUM_WILD_POKEMON_STAT_BOOST, 2
# 255 "data/scripts/legendary_mon_scripts.pory"
	setwildbattlewithcustommoves SPECIES_KELDEO, 75, ITEM_WATER_GEM, MOVE_SECRET_SWORD, MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_AIR_SLASH, 0, NATURE_TIMID
# 256 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 257 "data/scripts/legendary_mon_scripts.pory"
	dowildbattle
# 258 "data/scripts/legendary_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 259 "data/scripts/legendary_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 260 "data/scripts/legendary_mon_scripts.pory"
	switch VAR_RESULT
# 261 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Keldeo_Encounter_3
# 267 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Keldeo_Encounter_4
# 268 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Keldeo_Encounter_4
# 269 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Keldeo_Encounter_4
Common_EventScript_Keldeo_Encounter_1:
# 276 "data/scripts/legendary_mon_scripts.pory"
	release
	end

Common_EventScript_Keldeo_Encounter_3:
# 262 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_DEFEATED_KELDEO
# 263 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 264 "data/scripts/legendary_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 265 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Common_EventScript_Keldeo_Encounter_1

Common_EventScript_Keldeo_Encounter_4:
# 270 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 271 "data/scripts/legendary_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 272 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 273 "data/scripts/legendary_mon_scripts.pory"
	msgbox Common_EventScript_Keldeo_Encounter_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Keldeo_Encounter_1


Common_EventScript_Victini_Encounter::
# 281 "data/scripts/legendary_mon_scripts.pory"
	lock
# 282 "data/scripts/legendary_mon_scripts.pory"
	faceplayer
# 283 "data/scripts/legendary_mon_scripts.pory"
	playmoncry SPECIES_VICTINI, 2
# 284 "data/scripts/legendary_mon_scripts.pory"
	setvar VAR_BOSS_BATTLE_HP_MULTIPIER, LEGENDARY_HP_MULTIPLIER
# 285 "data/scripts/legendary_mon_scripts.pory"
	msgbox Common_EventScript_Victini_Encounter_Text_0
# 286 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_TOTEM_BATTLE
# 287 "data/scripts/legendary_mon_scripts.pory"
	setvar VAR_NUM_WILD_POKEMON_STAT_BOOST, 2
# 288 "data/scripts/legendary_mon_scripts.pory"
	setwildbattlewithcustommoves SPECIES_VICTINI, 75, ITEM_FIRE_GEM, MOVE_V_CREATE, MOVE_PSYSHOCK, MOVE_THUNDERBOLT, MOVE_SHADOW_BALL, 0, NATURE_TIMID
# 289 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 290 "data/scripts/legendary_mon_scripts.pory"
	dowildbattle
# 291 "data/scripts/legendary_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 292 "data/scripts/legendary_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 293 "data/scripts/legendary_mon_scripts.pory"
	switch VAR_RESULT
# 294 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Victini_Encounter_3
# 300 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Victini_Encounter_4
# 301 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Victini_Encounter_4
# 302 "data/scripts/legendary_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Victini_Encounter_4
Common_EventScript_Victini_Encounter_1:
# 309 "data/scripts/legendary_mon_scripts.pory"
	release
	end

Common_EventScript_Victini_Encounter_3:
# 295 "data/scripts/legendary_mon_scripts.pory"
	setflag FLAG_DEFEATED_VICTINI
# 296 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 297 "data/scripts/legendary_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 298 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Common_EventScript_Victini_Encounter_1

Common_EventScript_Victini_Encounter_4:
# 303 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 304 "data/scripts/legendary_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 305 "data/scripts/legendary_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 306 "data/scripts/legendary_mon_scripts.pory"
	msgbox Common_EventScript_Victini_Encounter_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Victini_Encounter_1


TerraCave_End_EventScript_Groudon_Text_0:
# 43 "data/scripts/legendary_mon_scripts.pory"
	.string "Groudon dived into the magma$"

Common_EventScript_Mesprit_Encounter_Text_0:
# 95 "data/scripts/legendary_mon_scripts.pory"
	.string "Mesprit: Mes...$"

Common_EventScript_Mesprit_Encounter_Text_1:
# 114 "data/scripts/legendary_mon_scripts.pory"
	.string "Mesprit teleported to somewhere$"

Common_EventScript_Landorus_Encounter_Text_0:
# 126 "data/scripts/legendary_mon_scripts.pory"
	.string "Landorus: Lan...$"

Common_EventScript_Landorus_Encounter_Text_1:
# 145 "data/scripts/legendary_mon_scripts.pory"
	.string "Landorus away!$"

Common_EventScript_Darkrai_Encounter_Text_0:
# 156 "data/scripts/legendary_mon_scripts.pory"
	.string "Darkrai: Dar!$"

Common_EventScript_Darkrai_Encounter_Text_1:
# 163 "data/scripts/legendary_mon_scripts.pory"
	.string "The bad dream went away and {PLAYER}\n"
	.string "could rest peacefully.$"

Common_EventScript_Cobalion_Encounter_Text_0:
# 188 "data/scripts/legendary_mon_scripts.pory"
	.string "Cobalion: Coba!$"

Common_EventScript_Cobalion_Encounter_Text_1:
# 207 "data/scripts/legendary_mon_scripts.pory"
	.string "Cobalion escaped to somewhere$"

Common_EventScript_Virizion_Encounter_Text_0:
# 219 "data/scripts/legendary_mon_scripts.pory"
	.string "Virizion: Viri!$"

Common_EventScript_Virizion_Encounter_Text_1:
# 238 "data/scripts/legendary_mon_scripts.pory"
	.string "Virizion escaped to somewhere$"

Common_EventScript_Keldeo_Encounter_Text_0:
# 250 "data/scripts/legendary_mon_scripts.pory"
	.string "Keldeo: Kel!$"

Common_EventScript_Keldeo_Encounter_Text_1:
# 273 "data/scripts/legendary_mon_scripts.pory"
	.string "Keldeo escaped to somewhere$"

Common_EventScript_Victini_Encounter_Text_0:
# 285 "data/scripts/legendary_mon_scripts.pory"
	.string "Victini: Vic!$"

Common_EventScript_Victini_Encounter_Text_1:
# 306 "data/scripts/legendary_mon_scripts.pory"
	.string "Victini teleported to somewhere$"
