EventScript_SetLarvestaFamilyGfx::
# 5 "data/scripts/wild_mon_scripts.pory"
	special ShouldStaticEncounterBeFirstStage
# 6 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_SetLarvestaFamilyGfx_2
# 6 "data/scripts/wild_mon_scripts.pory"
	goto_if_unset FLAG_BADGE04_GET, EventScript_SetLarvestaFamilyGfx_2
# 11 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, ( OBJ_EVENT_GFX_POKEMON_000 + SPECIES_VOLCARONA )
# 12 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_TEMP_F, SPECIES_VOLCARONA
EventScript_SetLarvestaFamilyGfx_1:
	return

EventScript_SetLarvestaFamilyGfx_2:
# 7 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, ( OBJ_EVENT_GFX_POKEMON_000 + SPECIES_LARVESTA )
# 8 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_TEMP_F, SPECIES_LARVESTA
	goto EventScript_SetLarvestaFamilyGfx_1


EventScript_Battle_Static_Mon::
# 18 "data/scripts/wild_mon_scripts.pory"
	lock
# 19 "data/scripts/wild_mon_scripts.pory"
	faceplayer
# 20 "data/scripts/wild_mon_scripts.pory"
	switch VAR_TEMP_F
# 22 "data/scripts/wild_mon_scripts.pory"
	case SPECIES_LARVESTA, EventScript_Battle_Static_Mon_3
# 50 "data/scripts/wild_mon_scripts.pory"
	case SPECIES_VOLCARONA, EventScript_Battle_Static_Mon_4
EventScript_Battle_Static_Mon_1:
# 79 "data/scripts/wild_mon_scripts.pory"
	release
	end

EventScript_Battle_Static_Mon_3:
# 23 "data/scripts/wild_mon_scripts.pory"
	playmoncry SPECIES_LARVESTA, 2
# 24 "data/scripts/wild_mon_scripts.pory"
	setwildbattle SPECIES_LARVESTA, 2, ITEM_SUN_STONE
# 25 "data/scripts/wild_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 26 "data/scripts/wild_mon_scripts.pory"
	dowildbattle
# 27 "data/scripts/wild_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 28 "data/scripts/wild_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 29 "data/scripts/wild_mon_scripts.pory"
	switch VAR_RESULT
# 30 "data/scripts/wild_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, EventScript_Battle_Static_Mon_7
# 36 "data/scripts/wild_mon_scripts.pory"
	case B_OUTCOME_RAN, EventScript_Battle_Static_Mon_8
# 37 "data/scripts/wild_mon_scripts.pory"
	case B_OUTCOME_WON, EventScript_Battle_Static_Mon_8
# 38 "data/scripts/wild_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, EventScript_Battle_Static_Mon_8
EventScript_Battle_Static_Mon_5:
	goto EventScript_Battle_Static_Mon_1

EventScript_Battle_Static_Mon_4:
# 51 "data/scripts/wild_mon_scripts.pory"
	playmoncry SPECIES_VOLCARONA, 2
# 52 "data/scripts/wild_mon_scripts.pory"
	setwildbattle SPECIES_VOLCARONA, 2, ITEM_SUN_STONE
# 53 "data/scripts/wild_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 54 "data/scripts/wild_mon_scripts.pory"
	dowildbattle
# 55 "data/scripts/wild_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 56 "data/scripts/wild_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 57 "data/scripts/wild_mon_scripts.pory"
	switch VAR_RESULT
# 58 "data/scripts/wild_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, EventScript_Battle_Static_Mon_11
# 64 "data/scripts/wild_mon_scripts.pory"
	case B_OUTCOME_RAN, EventScript_Battle_Static_Mon_12
# 65 "data/scripts/wild_mon_scripts.pory"
	case B_OUTCOME_WON, EventScript_Battle_Static_Mon_12
# 66 "data/scripts/wild_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, EventScript_Battle_Static_Mon_12
EventScript_Battle_Static_Mon_9:
	goto EventScript_Battle_Static_Mon_1

EventScript_Battle_Static_Mon_7:
# 31 "data/scripts/wild_mon_scripts.pory"
	setflag FLAG_DAILY_WILD_LARVESTA
# 32 "data/scripts/wild_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 33 "data/scripts/wild_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 34 "data/scripts/wild_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto EventScript_Battle_Static_Mon_5

EventScript_Battle_Static_Mon_8:
# 39 "data/scripts/wild_mon_scripts.pory"
	setflag FLAG_DAILY_WILD_LARVESTA
# 40 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_0x8004, SPECIES_LARVESTA
# 41 "data/scripts/wild_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 42 "data/scripts/wild_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 43 "data/scripts/wild_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 44 "data/scripts/wild_mon_scripts.pory"
	bufferspeciesname 0, VAR_0x8004
# 45 "data/scripts/wild_mon_scripts.pory"
	msgbox EventScript_Battle_Static_Mon_Text_0, MSGBOX_DEFAULT
	goto EventScript_Battle_Static_Mon_5

EventScript_Battle_Static_Mon_11:
# 59 "data/scripts/wild_mon_scripts.pory"
	setflag FLAG_DAILY_WILD_LARVESTA
# 60 "data/scripts/wild_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 61 "data/scripts/wild_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 62 "data/scripts/wild_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto EventScript_Battle_Static_Mon_9

EventScript_Battle_Static_Mon_12:
# 67 "data/scripts/wild_mon_scripts.pory"
	setflag FLAG_DAILY_WILD_LARVESTA
# 68 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_0x8004, SPECIES_VOLCARONA
# 69 "data/scripts/wild_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 70 "data/scripts/wild_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 71 "data/scripts/wild_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 72 "data/scripts/wild_mon_scripts.pory"
	bufferspeciesname 0, VAR_0x8004
# 73 "data/scripts/wild_mon_scripts.pory"
	msgbox EventScript_Battle_Static_Mon_Text_0, MSGBOX_DEFAULT
	goto EventScript_Battle_Static_Mon_9


Common_EventScript_Wild_Lapras::
# 85 "data/scripts/wild_mon_scripts.pory"
	lock
# 86 "data/scripts/wild_mon_scripts.pory"
	faceplayer
# 87 "data/scripts/wild_mon_scripts.pory"
	playmoncry SPECIES_LAPRAS, 2
# 88 "data/scripts/wild_mon_scripts.pory"
	setwildbattle SPECIES_LAPRAS, 2, ITEM_WATER_STONE
# 89 "data/scripts/wild_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 90 "data/scripts/wild_mon_scripts.pory"
	dowildbattle
# 91 "data/scripts/wild_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 92 "data/scripts/wild_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 93 "data/scripts/wild_mon_scripts.pory"
	switch VAR_RESULT
# 94 "data/scripts/wild_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Wild_Lapras_3
# 101 "data/scripts/wild_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Wild_Lapras_4
# 102 "data/scripts/wild_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Wild_Lapras_4
# 103 "data/scripts/wild_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Wild_Lapras_4
Common_EventScript_Wild_Lapras_1:
# 113 "data/scripts/wild_mon_scripts.pory"
	release
	end

Common_EventScript_Wild_Lapras_3:
# 95 "data/scripts/wild_mon_scripts.pory"
	setflag FLAG_DAILY_WILD_LAPRAS
# 96 "data/scripts/wild_mon_scripts.pory"
	setweather WEATHER_NONE
# 97 "data/scripts/wild_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 98 "data/scripts/wild_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 99 "data/scripts/wild_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto Common_EventScript_Wild_Lapras_1

Common_EventScript_Wild_Lapras_4:
# 104 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_0x8004, SPECIES_LAPRAS
# 105 "data/scripts/wild_mon_scripts.pory"
	setweather WEATHER_NONE
# 106 "data/scripts/wild_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 107 "data/scripts/wild_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 108 "data/scripts/wild_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 109 "data/scripts/wild_mon_scripts.pory"
	bufferspeciesname 0, VAR_0x8004
# 110 "data/scripts/wild_mon_scripts.pory"
	msgbox Common_EventScript_Wild_Lapras_Text_0, MSGBOX_DEFAULT
	goto Common_EventScript_Wild_Lapras_1


Route120_EventScript_Kecleon1::
# 119 "data/scripts/wild_mon_scripts.pory"
	lock
# 120 "data/scripts/wild_mon_scripts.pory"
	faceplayer
# 121 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_0x8009, 1
# 122 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_Kecleon
	end


Route120_EventScript_Kecleon2::
# 127 "data/scripts/wild_mon_scripts.pory"
	lock
# 128 "data/scripts/wild_mon_scripts.pory"
	faceplayer
# 129 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_0x8009, 2
# 130 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_Kecleon
	end


Route120_EventScript_Kecleon3::
# 135 "data/scripts/wild_mon_scripts.pory"
	lock
# 136 "data/scripts/wild_mon_scripts.pory"
	faceplayer
# 137 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_0x8009, 3
# 138 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_Kecleon
	end


Route120_EventScript_Kecleon4::
# 143 "data/scripts/wild_mon_scripts.pory"
	lock
# 144 "data/scripts/wild_mon_scripts.pory"
	faceplayer
# 145 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_0x8009, 4
# 146 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_Kecleon
	end


Route120_EventScript_Kecleon5::
# 151 "data/scripts/wild_mon_scripts.pory"
	lock
# 152 "data/scripts/wild_mon_scripts.pory"
	faceplayer
# 153 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_0x8009, 5
# 154 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_Kecleon
	end


Route119_EventScript_Kecleon1::
# 159 "data/scripts/wild_mon_scripts.pory"
	lock
# 160 "data/scripts/wild_mon_scripts.pory"
	faceplayer
# 161 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_0x8009, 6
# 162 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_Kecleon
	end


Route119_EventScript_Kecleon2::
# 167 "data/scripts/wild_mon_scripts.pory"
	lock
# 168 "data/scripts/wild_mon_scripts.pory"
	faceplayer
# 169 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_0x8009, 7
# 170 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_Kecleon
	end


EventScript_Kecleon::
# 175 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_AskUseDevonScope
# 177 "data/scripts/wild_mon_scripts.pory"
	release
	end


EventScript_AskUseDevonScope::
# 182 "data/scripts/wild_mon_scripts.pory"
	msgbox Kecleon_Text_WantToUseDevonScope, MSGBOX_YESNO
# 183 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_AskUseDevonScope_2
EventScript_AskUseDevonScope_1:
# 186 "data/scripts/wild_mon_scripts.pory"
	release
	end

EventScript_AskUseDevonScope_2:
# 184 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_BattleKecleon
	goto EventScript_AskUseDevonScope_1


EventScript_BattleKecleon::
# 191 "data/scripts/wild_mon_scripts.pory"
	msgbox Kecleon_Text_UseDevonScopeMonAttacked, MSGBOX_DEFAULT
# 192 "data/scripts/wild_mon_scripts.pory"
	closemessage
# 193 "data/scripts/wild_mon_scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 194 "data/scripts/wild_mon_scripts.pory"
	waitmovement 0
# 195 "data/scripts/wild_mon_scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
# 196 "data/scripts/wild_mon_scripts.pory"
	waitmovement 0
# 197 "data/scripts/wild_mon_scripts.pory"
	waitse
# 198 "data/scripts/wild_mon_scripts.pory"
	playmoncry SPECIES_KECLEON, 2
# 199 "data/scripts/wild_mon_scripts.pory"
	delay 40
# 200 "data/scripts/wild_mon_scripts.pory"
	waitmoncry
# 201 "data/scripts/wild_mon_scripts.pory"
	setwildbattle SPECIES_KECLEON, 1, ITEM_NONE
# 202 "data/scripts/wild_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 203 "data/scripts/wild_mon_scripts.pory"
	dowildbattle
# 204 "data/scripts/wild_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 205 "data/scripts/wild_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 206 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_BattleKecleon_2
EventScript_BattleKecleon_1:
# 209 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_BattleKecleon_5
EventScript_BattleKecleon_4:
# 212 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_BattleKecleon_8
EventScript_BattleKecleon_7:
# 215 "data/scripts/wild_mon_scripts.pory"
	release
	end

EventScript_BattleKecleon_2:
# 207 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_RemoveKecleon
	goto EventScript_BattleKecleon_1

EventScript_BattleKecleon_5:
# 210 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_RemoveKecleon
	goto EventScript_BattleKecleon_4

EventScript_BattleKecleon_8:
# 213 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_RemoveKecleon
	goto EventScript_BattleKecleon_7


EventScript_RemoveKecleon::
# 220 "data/scripts/wild_mon_scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
	end


# 224 "data/scripts/wild_mon_scripts.pory"
Movement_KecleonAppears:
# 225 "data/scripts/wild_mon_scripts.pory"
	set_visible
# 226 "data/scripts/wild_mon_scripts.pory"
	delay_4
# 227 "data/scripts/wild_mon_scripts.pory"
	set_invisible
# 228 "data/scripts/wild_mon_scripts.pory"
	delay_4
# 229 "data/scripts/wild_mon_scripts.pory"
	set_visible
# 230 "data/scripts/wild_mon_scripts.pory"
	delay_4
# 231 "data/scripts/wild_mon_scripts.pory"
	set_invisible
# 232 "data/scripts/wild_mon_scripts.pory"
	delay_4
# 233 "data/scripts/wild_mon_scripts.pory"
	set_visible
# 234 "data/scripts/wild_mon_scripts.pory"
	delay_8
# 235 "data/scripts/wild_mon_scripts.pory"
	set_invisible
# 236 "data/scripts/wild_mon_scripts.pory"
	delay_8
# 237 "data/scripts/wild_mon_scripts.pory"
	set_visible
# 238 "data/scripts/wild_mon_scripts.pory"
	delay_8
# 239 "data/scripts/wild_mon_scripts.pory"
	set_invisible
# 240 "data/scripts/wild_mon_scripts.pory"
	delay_8
# 241 "data/scripts/wild_mon_scripts.pory"
	set_visible
# 242 "data/scripts/wild_mon_scripts.pory"
	delay_16
# 243 "data/scripts/wild_mon_scripts.pory"
	set_invisible
# 244 "data/scripts/wild_mon_scripts.pory"
	delay_16
# 245 "data/scripts/wild_mon_scripts.pory"
	set_visible
# 246 "data/scripts/wild_mon_scripts.pory"
	step_end

EventScript_SetMunchlaxFamilyGfx::
# 251 "data/scripts/wild_mon_scripts.pory"
	special ShouldStaticEncounterBeFirstStage
# 252 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_SetMunchlaxFamilyGfx_2
EventScript_SetMunchlaxFamilyGfx_1:
# 255 "data/scripts/wild_mon_scripts.pory"
	goto_if_unset FLAG_BADGE04_GET, EventScript_SetMunchlaxFamilyGfx_5
EventScript_SetMunchlaxFamilyGfx_4:
# 258 "data/scripts/wild_mon_scripts.pory"
	goto_if_set FLAG_BADGE04_GET, EventScript_SetMunchlaxFamilyGfx_8
EventScript_SetMunchlaxFamilyGfx_7:
	return

EventScript_SetMunchlaxFamilyGfx_2:
# 253 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_SetMunchlaxGfx
	goto EventScript_SetMunchlaxFamilyGfx_1

EventScript_SetMunchlaxFamilyGfx_5:
# 256 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_SetMunchlaxGfx
	goto EventScript_SetMunchlaxFamilyGfx_4

EventScript_SetMunchlaxFamilyGfx_8:
# 259 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_SetSnorlaxGfx
	goto EventScript_SetMunchlaxFamilyGfx_7


EventScript_SetMunchlaxGfx::
# 265 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MUNCHLAX
	return


EventScript_SetSnorlaxGfx::
# 270 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SNORLAX
	return


EventScript_Snorlax::
# 275 "data/scripts/wild_mon_scripts.pory"
	msgbox EventScript_Snorlax_Text_0, MSGBOX_DEFAULT
# 276 "data/scripts/wild_mon_scripts.pory"
	checkitem ITEM_BLUE_FLUTE, 1
# 277 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_Snorlax_2
EventScript_Snorlax_1:
# 280 "data/scripts/wild_mon_scripts.pory"
	release
	end

EventScript_Snorlax_2:
# 278 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_Snorlax_AskUseFlute
	goto EventScript_Snorlax_1


EventScript_Snorlax_AskUseFlute::
# 285 "data/scripts/wild_mon_scripts.pory"
	msgbox EventScript_Snorlax_AskUseFlute_Text_0, MSGBOX_YESNO
# 286 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_Snorlax_AskUseFlute_2
EventScript_Snorlax_AskUseFlute_1:
# 289 "data/scripts/wild_mon_scripts.pory"
	release
	end

EventScript_Snorlax_AskUseFlute_2:
# 287 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_BattleSnorlax
	goto EventScript_Snorlax_AskUseFlute_1


EventScript_BattleSnorlax::
# 294 "data/scripts/wild_mon_scripts.pory"
	goto_if_unset FLAG_BADGE04_GET, EventScript_BattleSnorlax_2
EventScript_BattleSnorlax_1:
# 297 "data/scripts/wild_mon_scripts.pory"
	goto_if_set FLAG_TEMP_5, EventScript_BattleSnorlax_5
EventScript_BattleSnorlax_4:
# 300 "data/scripts/wild_mon_scripts.pory"
	msgbox EventScript_BattleSnorlax_Text_0, MSGBOX_DEFAULT
# 301 "data/scripts/wild_mon_scripts.pory"
	playfanfare MUS_RG_JIGGLYPUFF
# 302 "data/scripts/wild_mon_scripts.pory"
	delay 400
# 303 "data/scripts/wild_mon_scripts.pory"
	playse SE_PIN
# 304 "data/scripts/wild_mon_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 305 "data/scripts/wild_mon_scripts.pory"
	waitmovement 0
# 306 "data/scripts/wild_mon_scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
# 307 "data/scripts/wild_mon_scripts.pory"
	waitmovement 0
# 308 "data/scripts/wild_mon_scripts.pory"
	msgbox EventScript_BattleSnorlax_Text_1, MSGBOX_DEFAULT
# 309 "data/scripts/wild_mon_scripts.pory"
	closemessage
# 310 "data/scripts/wild_mon_scripts.pory"
	waitse
# 311 "data/scripts/wild_mon_scripts.pory"
	playmoncry SPECIES_SNORLAX, 2
# 312 "data/scripts/wild_mon_scripts.pory"
	delay 40
# 313 "data/scripts/wild_mon_scripts.pory"
	waitmoncry
# 314 "data/scripts/wild_mon_scripts.pory"
	setwildbattle SPECIES_SNORLAX, 2, ITEM_LEFTOVERS
# 315 "data/scripts/wild_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 316 "data/scripts/wild_mon_scripts.pory"
	dowildbattle
# 317 "data/scripts/wild_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 318 "data/scripts/wild_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 319 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_BattleSnorlax_8
EventScript_BattleSnorlax_7:
# 322 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq EventScript_BattleSnorlax_11
EventScript_BattleSnorlax_10:
# 325 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_BattleSnorlax_14
EventScript_BattleSnorlax_13:
# 328 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_BattleSnorlax_17
EventScript_BattleSnorlax_16:
# 331 "data/scripts/wild_mon_scripts.pory"
	release
	end

EventScript_BattleSnorlax_2:
# 295 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_BattleMunchlax
	goto EventScript_BattleSnorlax_1

EventScript_BattleSnorlax_5:
# 298 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_BattleMunchlax
	goto EventScript_BattleSnorlax_4

EventScript_BattleSnorlax_8:
# 320 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_RemoveSnorlax
	goto EventScript_BattleSnorlax_7

EventScript_BattleSnorlax_11:
# 323 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_RemoveSnorlax
	goto EventScript_BattleSnorlax_10

EventScript_BattleSnorlax_14:
# 326 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_RemoveSnorlax
	goto EventScript_BattleSnorlax_13

EventScript_BattleSnorlax_17:
# 329 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_RemoveSnorlax
	goto EventScript_BattleSnorlax_16


EventScript_BattleMunchlax::
# 336 "data/scripts/wild_mon_scripts.pory"
	msgbox EventScript_BattleSnorlax_Text_0, MSGBOX_DEFAULT
# 337 "data/scripts/wild_mon_scripts.pory"
	playfanfare MUS_RG_JIGGLYPUFF
# 338 "data/scripts/wild_mon_scripts.pory"
	delay 400
# 339 "data/scripts/wild_mon_scripts.pory"
	playse SE_PIN
# 340 "data/scripts/wild_mon_scripts.pory"
	msgbox EventScript_BattleSnorlax_Text_1, MSGBOX_DEFAULT
# 341 "data/scripts/wild_mon_scripts.pory"
	closemessage
# 342 "data/scripts/wild_mon_scripts.pory"
	waitse
# 343 "data/scripts/wild_mon_scripts.pory"
	playmoncry SPECIES_MUNCHLAX, 2
# 344 "data/scripts/wild_mon_scripts.pory"
	delay 40
# 345 "data/scripts/wild_mon_scripts.pory"
	waitmoncry
# 346 "data/scripts/wild_mon_scripts.pory"
	setwildbattle SPECIES_MUNCHLAX, 2, ITEM_LEFTOVERS
# 347 "data/scripts/wild_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 348 "data/scripts/wild_mon_scripts.pory"
	dowildbattle
# 349 "data/scripts/wild_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 350 "data/scripts/wild_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 351 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_BattleMunchlax_2
EventScript_BattleMunchlax_1:
# 354 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq EventScript_BattleMunchlax_5
EventScript_BattleMunchlax_4:
# 357 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_BattleMunchlax_8
EventScript_BattleMunchlax_7:
# 360 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_BattleMunchlax_11
EventScript_BattleMunchlax_10:
# 363 "data/scripts/wild_mon_scripts.pory"
	release
	end

EventScript_BattleMunchlax_2:
# 352 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_RemoveSnorlax
	goto EventScript_BattleMunchlax_1

EventScript_BattleMunchlax_5:
# 355 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_RemoveSnorlax
	goto EventScript_BattleMunchlax_4

EventScript_BattleMunchlax_8:
# 358 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_RemoveSnorlax
	goto EventScript_BattleMunchlax_7

EventScript_BattleMunchlax_11:
# 361 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_RemoveSnorlax
	goto EventScript_BattleMunchlax_10


EventScript_RemoveSnorlax::
# 368 "data/scripts/wild_mon_scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
	end


EventScript_SetSudowoodoFamilyGfx::
# 374 "data/scripts/wild_mon_scripts.pory"
	special ShouldStaticEncounterBeFirstStage
# 375 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_SetSudowoodoFamilyGfx_2
EventScript_SetSudowoodoFamilyGfx_1:
# 378 "data/scripts/wild_mon_scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, EventScript_SetSudowoodoFamilyGfx_5
EventScript_SetSudowoodoFamilyGfx_4:
# 381 "data/scripts/wild_mon_scripts.pory"
	goto_if_set FLAG_BADGE03_GET, EventScript_SetSudowoodoFamilyGfx_8
EventScript_SetSudowoodoFamilyGfx_7:
	return

EventScript_SetSudowoodoFamilyGfx_2:
# 376 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_SetBonslyGfx
	goto EventScript_SetSudowoodoFamilyGfx_1

EventScript_SetSudowoodoFamilyGfx_5:
# 379 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_SetBonslyGfx
	goto EventScript_SetSudowoodoFamilyGfx_4

EventScript_SetSudowoodoFamilyGfx_8:
# 382 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_SetSudowoodoGfx
	goto EventScript_SetSudowoodoFamilyGfx_7


EventScript_SetBonslyGfx::
# 388 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BONSLY
	return


EventScript_SetSudowoodoGfx::
# 393 "data/scripts/wild_mon_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SUDOWOODO
	return


EventScript_Sudowoodo::
# 398 "data/scripts/wild_mon_scripts.pory"
	lock
# 399 "data/scripts/wild_mon_scripts.pory"
	faceplayer
# 400 "data/scripts/wild_mon_scripts.pory"
	waitse
# 401 "data/scripts/wild_mon_scripts.pory"
	playse SE_SUDOWOODO_SHAKE
# 402 "data/scripts/wild_mon_scripts.pory"
	applymovement VAR_LAST_TALKED, Sudowoodo_Movement_SudowoodoShake
# 403 "data/scripts/wild_mon_scripts.pory"
	waitmovement 0
# 404 "data/scripts/wild_mon_scripts.pory"
	release
	end


EventScript_WaterSudowoodo::
# 409 "data/scripts/wild_mon_scripts.pory"
	lock
# 410 "data/scripts/wild_mon_scripts.pory"
	faceplayer
# 411 "data/scripts/wild_mon_scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, EventScript_WaterSudowoodo_2
EventScript_WaterSudowoodo_1:
# 414 "data/scripts/wild_mon_scripts.pory"
	goto_if_set FLAG_TEMP_5, EventScript_WaterSudowoodo_5
EventScript_WaterSudowoodo_4:
# 417 "data/scripts/wild_mon_scripts.pory"
	special DoWateringBerryTreeAnim
# 418 "data/scripts/wild_mon_scripts.pory"
	waitstate
# 419 "data/scripts/wild_mon_scripts.pory"
	waitse
# 420 "data/scripts/wild_mon_scripts.pory"
	playse SE_SUDOWOODO_SHAKE
# 421 "data/scripts/wild_mon_scripts.pory"
	applymovement VAR_LAST_TALKED, Sudowoodo_Movement_SudowoodoShake
# 422 "data/scripts/wild_mon_scripts.pory"
	waitmovement 0
# 423 "data/scripts/wild_mon_scripts.pory"
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
# 424 "data/scripts/wild_mon_scripts.pory"
	closemessage
# 425 "data/scripts/wild_mon_scripts.pory"
	waitse
# 426 "data/scripts/wild_mon_scripts.pory"
	playmoncry SPECIES_SUDOWOODO, 2
# 427 "data/scripts/wild_mon_scripts.pory"
	delay 40
# 428 "data/scripts/wild_mon_scripts.pory"
	waitmoncry
# 429 "data/scripts/wild_mon_scripts.pory"
	setwildbattle SPECIES_SUDOWOODO, 1, ITEM_NONE
# 430 "data/scripts/wild_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 431 "data/scripts/wild_mon_scripts.pory"
	dowildbattle
# 432 "data/scripts/wild_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 433 "data/scripts/wild_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 434 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_WaterSudowoodo_8
EventScript_WaterSudowoodo_7:
# 437 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_WaterSudowoodo_11
EventScript_WaterSudowoodo_10:
# 440 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_WaterSudowoodo_14
EventScript_WaterSudowoodo_13:
# 443 "data/scripts/wild_mon_scripts.pory"
	release
	end

EventScript_WaterSudowoodo_2:
# 412 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_WaterBonsly
	goto EventScript_WaterSudowoodo_1

EventScript_WaterSudowoodo_5:
# 415 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_WaterBonsly
	goto EventScript_WaterSudowoodo_4

EventScript_WaterSudowoodo_8:
# 435 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_DefeatedSudowoodo
	goto EventScript_WaterSudowoodo_7

EventScript_WaterSudowoodo_11:
# 438 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_DefeatedSudowoodo
	goto EventScript_WaterSudowoodo_10

EventScript_WaterSudowoodo_14:
# 441 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_DefeatedSudowoodo
	goto EventScript_WaterSudowoodo_13


EventScript_WaterBonsly::
# 448 "data/scripts/wild_mon_scripts.pory"
	special DoWateringBerryTreeAnim
# 449 "data/scripts/wild_mon_scripts.pory"
	waitstate
# 450 "data/scripts/wild_mon_scripts.pory"
	waitse
# 451 "data/scripts/wild_mon_scripts.pory"
	playse SE_SUDOWOODO_SHAKE
# 452 "data/scripts/wild_mon_scripts.pory"
	applymovement VAR_LAST_TALKED, Sudowoodo_Movement_SudowoodoShake
# 453 "data/scripts/wild_mon_scripts.pory"
	waitmovement 0
# 454 "data/scripts/wild_mon_scripts.pory"
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
# 455 "data/scripts/wild_mon_scripts.pory"
	closemessage
# 456 "data/scripts/wild_mon_scripts.pory"
	waitse
# 457 "data/scripts/wild_mon_scripts.pory"
	playmoncry SPECIES_BONSLY, 2
# 458 "data/scripts/wild_mon_scripts.pory"
	delay 40
# 459 "data/scripts/wild_mon_scripts.pory"
	waitmoncry
# 460 "data/scripts/wild_mon_scripts.pory"
	setwildbattle SPECIES_BONSLY, 1, ITEM_NONE
# 461 "data/scripts/wild_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 462 "data/scripts/wild_mon_scripts.pory"
	dowildbattle
# 463 "data/scripts/wild_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 464 "data/scripts/wild_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 465 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_WaterBonsly_2
EventScript_WaterBonsly_1:
# 468 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_WaterBonsly_5
EventScript_WaterBonsly_4:
# 471 "data/scripts/wild_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_WaterBonsly_8
EventScript_WaterBonsly_7:
# 474 "data/scripts/wild_mon_scripts.pory"
	release
	end

EventScript_WaterBonsly_2:
# 466 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_DefeatedSudowoodo
	goto EventScript_WaterBonsly_1

EventScript_WaterBonsly_5:
# 469 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_DefeatedSudowoodo
	goto EventScript_WaterBonsly_4

EventScript_WaterBonsly_8:
# 472 "data/scripts/wild_mon_scripts.pory"
	goto EventScript_DefeatedSudowoodo
	goto EventScript_WaterBonsly_7


EventScript_DefeatedSudowoodo::
# 479 "data/scripts/wild_mon_scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
	end


# 483 "data/scripts/wild_mon_scripts.pory"
Sudowoodo_Movement_SudowoodoShake:
# 484 "data/scripts/wild_mon_scripts.pory"
	face_right
# 485 "data/scripts/wild_mon_scripts.pory"
	delay_8
# 486 "data/scripts/wild_mon_scripts.pory"
	face_down
# 487 "data/scripts/wild_mon_scripts.pory"
	delay_8
# 488 "data/scripts/wild_mon_scripts.pory"
	face_left
# 489 "data/scripts/wild_mon_scripts.pory"
	delay_8
# 490 "data/scripts/wild_mon_scripts.pory"
	face_down
# 491 "data/scripts/wild_mon_scripts.pory"
	delay_8
# 492 "data/scripts/wild_mon_scripts.pory"
	face_right
# 493 "data/scripts/wild_mon_scripts.pory"
	delay_8
# 494 "data/scripts/wild_mon_scripts.pory"
	face_down
# 495 "data/scripts/wild_mon_scripts.pory"
	delay_8
# 496 "data/scripts/wild_mon_scripts.pory"
	face_left
# 497 "data/scripts/wild_mon_scripts.pory"
	delay_8
# 498 "data/scripts/wild_mon_scripts.pory"
	face_down
# 499 "data/scripts/wild_mon_scripts.pory"
	step_end

EventScript_Battle_Static_Mon_Text_0:
# 45 "data/scripts/wild_mon_scripts.pory"
	.string "{STR_VAR_1} disappeared.$"

Common_EventScript_Wild_Lapras_Text_0:
# 110 "data/scripts/wild_mon_scripts.pory"
	.string "Lapras dove away$"

EventScript_Snorlax_Text_0:
# 275 "data/scripts/wild_mon_scripts.pory"
	.string "A Pokémon is sprawled out in\n"
	.string "a deep and comfortable slumber.$"

EventScript_Snorlax_AskUseFlute_Text_0:
# 285 "data/scripts/wild_mon_scripts.pory"
	.string "Do you want to use the Blue Flute?$"

EventScript_BattleSnorlax_Text_0:
# 300 "data/scripts/wild_mon_scripts.pory"
	.string "{PLAYER} played the Blue Flute.$"

EventScript_BattleSnorlax_Text_1:
# 308 "data/scripts/wild_mon_scripts.pory"
	.string "The Pokémon woke up!\p"
	.string "It attacked in a grumpy rage!$"
