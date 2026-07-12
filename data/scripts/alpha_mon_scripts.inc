Common_EventScript_SetAlphaDefaultData::
# 4 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_ALPHA_CREATION
# 5 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_ENABLE_ALPHA_WILD_BATTLE_BOOST
# 6 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOOD_MOVESET_CREATION
# 7 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SMART_AI
# 8 "data/scripts/alpha_mon_scripts.pory"
	setvar VAR_BOSS_BATTLE_HP_MULTIPIER, 100
	return


Common_Eventscript_Enable_Alphas::
# 13 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_BADGE_11, Common_Eventscript_Enable_Alphas_1
# 17 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return

Common_Eventscript_Enable_Alphas_1:
# 14 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_DISABLE_PORTALS
	return


Common_Eventscript_Enable_Alphas_Clefable::
# 22 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 23 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_CLEFABLE_MEGA_STONE, Common_Eventscript_Enable_Alphas_Clefable_1
	return

Common_Eventscript_Enable_Alphas_Clefable_1:
# 24 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Clefable::
# 29 "data/scripts/alpha_mon_scripts.pory"
	lock
# 30 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 31 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 32 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_CLEFABLE, 2
# 33 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_CLEFABLE, LEVEL_SCALE_WILD_BOSS, ITEM_CLEFABLITE
# 34 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 35 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 36 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 37 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 38 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 39 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Clefable_3
# 40 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Clefable_3
# 52 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Clefable_4
# 53 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Clefable_4
Common_EventScript_Alpha_Clefable_1:
# 63 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Clefable_3:
# 41 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_CLEFABLE_MEGA_STONE
# 42 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 43 "data/scripts/alpha_mon_scripts.pory"
	setweather WEATHER_NONE
# 44 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 45 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 46 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 47 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Clefable_6
Common_EventScript_Alpha_Clefable_5:
	goto Common_EventScript_Alpha_Clefable_1

Common_EventScript_Alpha_Clefable_4:
# 54 "data/scripts/alpha_mon_scripts.pory"
	setvar VAR_0x8004, SPECIES_CLEFABLE
# 55 "data/scripts/alpha_mon_scripts.pory"
	setweather WEATHER_NONE
# 56 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 57 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 58 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 59 "data/scripts/alpha_mon_scripts.pory"
	bufferspeciesname 0, VAR_0x8004
# 60 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Clefable_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Clefable_1

Common_EventScript_Alpha_Clefable_6:
# 48 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Clefable_Text_0, MSGBOX_DEFAULT
# 49 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_CLEFABLITE, 1
	goto Common_EventScript_Alpha_Clefable_5


Common_Eventscript_Enable_Alphas_Dragonite::
# 68 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 69 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_DRAGONITE_MEGA_STONE, Common_Eventscript_Enable_Alphas_Dragonite_1
	return

Common_Eventscript_Enable_Alphas_Dragonite_1:
# 70 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Dragonite::
# 75 "data/scripts/alpha_mon_scripts.pory"
	lock
# 76 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 77 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 78 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_DRAGONITE, 2
# 79 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_DRAGONITE, LEVEL_SCALE_WILD_BOSS, ITEM_DRAGONINITE
# 80 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 81 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 82 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 83 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 84 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 85 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Dragonite_3
# 86 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Dragonite_3
# 98 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Dragonite_4
# 99 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Dragonite_4
Common_EventScript_Alpha_Dragonite_1:
# 109 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Dragonite_3:
# 87 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_DRAGONITE_MEGA_STONE
# 88 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 89 "data/scripts/alpha_mon_scripts.pory"
	setweather WEATHER_NONE
# 90 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 91 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 92 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 93 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Dragonite_6
Common_EventScript_Alpha_Dragonite_5:
	goto Common_EventScript_Alpha_Dragonite_1

Common_EventScript_Alpha_Dragonite_4:
# 100 "data/scripts/alpha_mon_scripts.pory"
	setvar VAR_0x8004, SPECIES_DRAGONITE
# 101 "data/scripts/alpha_mon_scripts.pory"
	setweather WEATHER_NONE
# 102 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 103 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 104 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 105 "data/scripts/alpha_mon_scripts.pory"
	bufferspeciesname 0, VAR_0x8004
# 106 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Dragonite_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Dragonite_1

Common_EventScript_Alpha_Dragonite_6:
# 94 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Dragonite_Text_0, MSGBOX_DEFAULT
# 95 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_DRAGONINITE, 1
	goto Common_EventScript_Alpha_Dragonite_5


Common_Eventscript_Enable_Alphas_Starmie::
# 114 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 115 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_STARMIE_MEGA_STONE, Common_Eventscript_Enable_Alphas_Starmie_1
	return

Common_Eventscript_Enable_Alphas_Starmie_1:
# 116 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Starmie::
# 121 "data/scripts/alpha_mon_scripts.pory"
	lock
# 122 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 123 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 124 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_STARMIE, 2
# 125 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_STARMIE, LEVEL_SCALE_WILD_BOSS, ITEM_STARMINITE
# 126 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 127 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 128 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 129 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 130 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 131 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Starmie_3
# 132 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Starmie_3
# 144 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Starmie_4
# 145 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Starmie_4
Common_EventScript_Alpha_Starmie_1:
# 155 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Starmie_3:
# 133 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_STARMIE_MEGA_STONE
# 134 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 135 "data/scripts/alpha_mon_scripts.pory"
	setweather WEATHER_NONE
# 136 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 137 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 138 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 139 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Starmie_6
Common_EventScript_Alpha_Starmie_5:
	goto Common_EventScript_Alpha_Starmie_1

Common_EventScript_Alpha_Starmie_4:
# 146 "data/scripts/alpha_mon_scripts.pory"
	setvar VAR_0x8004, SPECIES_STARMIE
# 147 "data/scripts/alpha_mon_scripts.pory"
	setweather WEATHER_NONE
# 148 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 149 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 150 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 151 "data/scripts/alpha_mon_scripts.pory"
	bufferspeciesname 0, VAR_0x8004
# 152 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Starmie_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Starmie_1

Common_EventScript_Alpha_Starmie_6:
# 140 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Starmie_Text_0, MSGBOX_DEFAULT
# 141 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_STARMINITE, 1
	goto Common_EventScript_Alpha_Starmie_5


Common_Eventscript_Enable_Alphas_Victreebel::
# 160 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 161 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_VICTREEBEL_MEGA_STONE, Common_Eventscript_Enable_Alphas_Victreebel_1
	return

Common_Eventscript_Enable_Alphas_Victreebel_1:
# 162 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Victreebel::
# 167 "data/scripts/alpha_mon_scripts.pory"
	lock
# 168 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 169 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 170 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_VICTREEBEL, 2
# 171 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_VICTREEBEL, LEVEL_SCALE_WILD_BOSS, ITEM_VICTRIBELITE
# 172 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 173 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 174 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 175 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 176 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 177 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Victreebel_3
# 178 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Victreebel_3
# 190 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Victreebel_4
# 191 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Victreebel_4
Common_EventScript_Alpha_Victreebel_1:
# 201 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Victreebel_3:
# 179 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_VICTREEBEL_MEGA_STONE
# 180 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 181 "data/scripts/alpha_mon_scripts.pory"
	setweather WEATHER_NONE
# 182 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 183 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 184 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 185 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Victreebel_6
Common_EventScript_Alpha_Victreebel_5:
	goto Common_EventScript_Alpha_Victreebel_1

Common_EventScript_Alpha_Victreebel_4:
# 192 "data/scripts/alpha_mon_scripts.pory"
	setvar VAR_0x8004, SPECIES_STARMIE
# 193 "data/scripts/alpha_mon_scripts.pory"
	setweather WEATHER_NONE
# 194 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 195 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 196 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 197 "data/scripts/alpha_mon_scripts.pory"
	bufferspeciesname 0, VAR_0x8004
# 198 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Victreebel_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Victreebel_1

Common_EventScript_Alpha_Victreebel_6:
# 186 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Victreebel_Text_0, MSGBOX_DEFAULT
# 187 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_VICTRIBELITE, 1
	goto Common_EventScript_Alpha_Victreebel_5


Common_Eventscript_Enable_Alphas_Excadrill::
# 206 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 207 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_EXCADRILL_MEGA_STONE, Common_Eventscript_Enable_Alphas_Excadrill_1
	return

Common_Eventscript_Enable_Alphas_Excadrill_1:
# 208 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Excadrill::
# 213 "data/scripts/alpha_mon_scripts.pory"
	lock
# 214 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 215 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 216 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_EXCADRILL, 2
# 217 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_EXCADRILL, LEVEL_SCALE_WILD_BOSS, ITEM_EXCADRITE
# 218 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 219 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 220 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 221 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 222 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 223 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Excadrill_3
# 224 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Excadrill_3
# 235 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Excadrill_4
# 236 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Excadrill_4
Common_EventScript_Alpha_Excadrill_1:
# 243 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Excadrill_3:
# 225 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_EXCADRILL_MEGA_STONE
# 226 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 227 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 228 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 229 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 230 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Excadrill_6
Common_EventScript_Alpha_Excadrill_5:
	goto Common_EventScript_Alpha_Excadrill_1

Common_EventScript_Alpha_Excadrill_4:
# 237 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 238 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 239 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 240 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Excadrill_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Excadrill_1

Common_EventScript_Alpha_Excadrill_6:
# 231 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Excadrill_Text_0, MSGBOX_DEFAULT
# 232 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_EXCADRITE, 1
	goto Common_EventScript_Alpha_Excadrill_5


Common_Eventscript_Enable_Alphas_Froslass::
# 248 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 249 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_FROSLASS_MEGA_STONE, Common_Eventscript_Enable_Alphas_Froslass_1
	return

Common_Eventscript_Enable_Alphas_Froslass_1:
# 250 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Froslass::
# 255 "data/scripts/alpha_mon_scripts.pory"
	lock
# 256 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 257 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 258 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_FROSLASS, 2
# 259 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_FROSLASS, LEVEL_SCALE_WILD_BOSS, ITEM_FROSLASSITE
# 260 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 261 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 262 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 263 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 264 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 265 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Froslass_3
# 266 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Froslass_3
# 277 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Froslass_4
# 278 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Froslass_4
Common_EventScript_Alpha_Froslass_1:
# 285 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Froslass_3:
# 267 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_FROSLASS_MEGA_STONE
# 268 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 269 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 270 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 271 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 272 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Froslass_6
Common_EventScript_Alpha_Froslass_5:
	goto Common_EventScript_Alpha_Froslass_1

Common_EventScript_Alpha_Froslass_4:
# 279 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 280 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 281 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 282 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Froslass_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Froslass_1

Common_EventScript_Alpha_Froslass_6:
# 273 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Froslass_Text_0, MSGBOX_DEFAULT
# 274 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_FROSLASSITE, 1
	goto Common_EventScript_Alpha_Froslass_5


Common_Eventscript_Enable_Alphas_Scolipede::
# 290 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 291 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_SCOLIPEDE_MEGA_STONE, Common_Eventscript_Enable_Alphas_Scolipede_1
	return

Common_Eventscript_Enable_Alphas_Scolipede_1:
# 292 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Scolipede::
# 297 "data/scripts/alpha_mon_scripts.pory"
	lock
# 298 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 299 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 300 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_SCOLIPEDE, 2
# 301 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_SCOLIPEDE, LEVEL_SCALE_WILD_BOSS, ITEM_SCOLIPITE
# 302 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 303 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 304 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 305 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 306 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 307 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Scolipede_3
# 308 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Scolipede_3
# 319 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Scolipede_4
# 320 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Scolipede_4
Common_EventScript_Alpha_Scolipede_1:
# 327 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Scolipede_3:
# 309 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_SCOLIPEDE_MEGA_STONE
# 310 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 311 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 312 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 313 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 314 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Scolipede_6
Common_EventScript_Alpha_Scolipede_5:
	goto Common_EventScript_Alpha_Scolipede_1

Common_EventScript_Alpha_Scolipede_4:
# 321 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 322 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 323 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 324 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Scolipede_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Scolipede_1

Common_EventScript_Alpha_Scolipede_6:
# 315 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Scolipede_Text_0, MSGBOX_DEFAULT
# 316 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_SCOLIPITE, 1
	goto Common_EventScript_Alpha_Scolipede_5


Common_Eventscript_Enable_Alphas_Skarmory::
# 332 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 333 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_SKARMORY_MEGA_STONE, Common_Eventscript_Enable_Alphas_Skarmory_1
	return

Common_Eventscript_Enable_Alphas_Skarmory_1:
# 334 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Skarmory::
# 339 "data/scripts/alpha_mon_scripts.pory"
	lock
# 340 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 341 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 342 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_SKARMORY, 2
# 343 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_SKARMORY, LEVEL_SCALE_WILD_BOSS, ITEM_SKARMORITE
# 344 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 345 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 346 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 347 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 348 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 349 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Skarmory_3
# 350 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Skarmory_3
# 361 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Skarmory_4
# 362 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Skarmory_4
Common_EventScript_Alpha_Skarmory_1:
# 369 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Skarmory_3:
# 351 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_SKARMORY_MEGA_STONE
# 352 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 353 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 354 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 355 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 356 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Skarmory_6
Common_EventScript_Alpha_Skarmory_5:
	goto Common_EventScript_Alpha_Skarmory_1

Common_EventScript_Alpha_Skarmory_4:
# 363 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 364 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 365 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 366 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Skarmory_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Skarmory_1

Common_EventScript_Alpha_Skarmory_6:
# 357 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Skarmory_Text_0, MSGBOX_DEFAULT
# 358 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_SKARMORITE, 1
	goto Common_EventScript_Alpha_Skarmory_5


Common_Eventscript_Enable_Alphas_Emboar::
# 374 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 375 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_EMBOAR_MEGA_STONE, Common_Eventscript_Enable_Alphas_Emboar_1
	return

Common_Eventscript_Enable_Alphas_Emboar_1:
# 376 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Emboar::
# 381 "data/scripts/alpha_mon_scripts.pory"
	lock
# 382 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 383 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 384 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_EMBOAR, 2
# 385 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_EMBOAR, LEVEL_SCALE_WILD_BOSS, ITEM_EMBOARITE
# 386 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 387 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 388 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 389 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 390 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 391 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Emboar_3
# 392 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Emboar_3
# 403 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Emboar_4
# 404 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Emboar_4
Common_EventScript_Alpha_Emboar_1:
# 411 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Emboar_3:
# 393 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_EMBOAR_MEGA_STONE
# 394 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 395 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 396 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 397 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 398 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Emboar_6
Common_EventScript_Alpha_Emboar_5:
	goto Common_EventScript_Alpha_Emboar_1

Common_EventScript_Alpha_Emboar_4:
# 405 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 406 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 407 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 408 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Emboar_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Emboar_1

Common_EventScript_Alpha_Emboar_6:
# 399 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Emboar_Text_0, MSGBOX_DEFAULT
# 400 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_EMBOARITE, 1
	goto Common_EventScript_Alpha_Emboar_5


Common_Eventscript_Enable_Alphas_Scrafty::
# 416 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 417 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_SCRAFTY_MEGA_STONE, Common_Eventscript_Enable_Alphas_Scrafty_1
	return

Common_Eventscript_Enable_Alphas_Scrafty_1:
# 418 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Scrafty::
# 423 "data/scripts/alpha_mon_scripts.pory"
	lock
# 424 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 425 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 426 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_SCRAFTY, 2
# 427 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_SCRAFTY, LEVEL_SCALE_WILD_BOSS, ITEM_SCRAFTINITE
# 428 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 429 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 430 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 431 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 432 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 433 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Scrafty_3
# 434 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Scrafty_3
# 445 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Scrafty_4
# 446 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Scrafty_4
Common_EventScript_Alpha_Scrafty_1:
# 453 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Scrafty_3:
# 435 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_SCRAFTY_MEGA_STONE
# 436 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 437 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 438 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 439 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 440 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Scrafty_6
Common_EventScript_Alpha_Scrafty_5:
	goto Common_EventScript_Alpha_Scrafty_1

Common_EventScript_Alpha_Scrafty_4:
# 447 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 448 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 449 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 450 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Scrafty_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Scrafty_1

Common_EventScript_Alpha_Scrafty_6:
# 441 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Scrafty_Text_0, MSGBOX_DEFAULT
# 442 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_SCRAFTINITE, 1
	goto Common_EventScript_Alpha_Scrafty_5


Common_Eventscript_Enable_Alphas_Eelektross::
# 458 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 459 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_EELEKTROSS_MEGA_STONE, Common_Eventscript_Enable_Alphas_Eelektross_1
	return

Common_Eventscript_Enable_Alphas_Eelektross_1:
# 460 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Eelektross::
# 465 "data/scripts/alpha_mon_scripts.pory"
	lock
# 466 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 467 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 468 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_EELEKTROSS, 2
# 469 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_EELEKTROSS, LEVEL_SCALE_WILD_BOSS, ITEM_EELEKTROSSITE
# 470 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 471 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 472 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 473 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 474 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 475 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Eelektross_3
# 476 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Eelektross_3
# 487 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Eelektross_4
# 488 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Eelektross_4
Common_EventScript_Alpha_Eelektross_1:
# 495 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Eelektross_3:
# 477 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_EELEKTROSS_MEGA_STONE
# 478 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 479 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 480 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 481 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 482 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Eelektross_6
Common_EventScript_Alpha_Eelektross_5:
	goto Common_EventScript_Alpha_Eelektross_1

Common_EventScript_Alpha_Eelektross_4:
# 489 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 490 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 491 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 492 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Eelektross_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Eelektross_1

Common_EventScript_Alpha_Eelektross_6:
# 483 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Eelektross_Text_0, MSGBOX_DEFAULT
# 484 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_EELEKTROSSITE, 1
	goto Common_EventScript_Alpha_Eelektross_5


Common_Eventscript_Enable_Alphas_Chandelure::
# 500 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 501 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_CHANDELURE_MEGA_STONE, Common_Eventscript_Enable_Alphas_Chandelure_1
	return

Common_Eventscript_Enable_Alphas_Chandelure_1:
# 502 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Chandelure::
# 507 "data/scripts/alpha_mon_scripts.pory"
	lock
# 508 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 509 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 510 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_CHANDELURE, 2
# 511 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_CHANDELURE, LEVEL_SCALE_WILD_BOSS, ITEM_CHANDELURITE
# 512 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 513 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 514 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 515 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 516 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 517 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Chandelure_3
# 518 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Chandelure_3
# 529 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Chandelure_4
# 530 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Chandelure_4
Common_EventScript_Alpha_Chandelure_1:
# 537 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Chandelure_3:
# 519 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_CHANDELURE_MEGA_STONE
# 520 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 521 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 522 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 523 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 524 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Chandelure_6
Common_EventScript_Alpha_Chandelure_5:
	goto Common_EventScript_Alpha_Chandelure_1

Common_EventScript_Alpha_Chandelure_4:
# 531 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 532 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 533 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 534 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Chandelure_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Chandelure_1

Common_EventScript_Alpha_Chandelure_6:
# 525 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Chandelure_Text_0, MSGBOX_DEFAULT
# 526 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_CHANDELURITE, 1
	goto Common_EventScript_Alpha_Chandelure_5


Common_Eventscript_Enable_Alphas_Delphox::
# 542 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 543 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_DELPHOX_MEGA_STONE, Common_Eventscript_Enable_Alphas_Delphox_1
	return

Common_Eventscript_Enable_Alphas_Delphox_1:
# 544 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Delphox::
# 549 "data/scripts/alpha_mon_scripts.pory"
	lock
# 550 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 551 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 552 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_DELPHOX, 2
# 553 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_DELPHOX, LEVEL_SCALE_WILD_BOSS, ITEM_DELPHOXITE
# 554 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 555 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 556 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 557 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 558 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 559 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Delphox_3
# 560 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Delphox_3
# 571 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Delphox_4
# 572 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Delphox_4
Common_EventScript_Alpha_Delphox_1:
# 579 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Delphox_3:
# 561 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_DELPHOX_MEGA_STONE
# 562 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 563 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 564 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 565 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 566 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Delphox_6
Common_EventScript_Alpha_Delphox_5:
	goto Common_EventScript_Alpha_Delphox_1

Common_EventScript_Alpha_Delphox_4:
# 573 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 574 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 575 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 576 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Delphox_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Delphox_1

Common_EventScript_Alpha_Delphox_6:
# 567 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Delphox_Text_0, MSGBOX_DEFAULT
# 568 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_DELPHOXITE, 1
	goto Common_EventScript_Alpha_Delphox_5


Common_Eventscript_Enable_Alphas_Chesnaught::
# 584 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 585 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_CHESNAUGHT_MEGA_STONE, Common_Eventscript_Enable_Alphas_Chesnaught_1
	return

Common_Eventscript_Enable_Alphas_Chesnaught_1:
# 586 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Chesnaught::
# 591 "data/scripts/alpha_mon_scripts.pory"
	lock
# 592 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 593 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 594 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_CHESNAUGHT, 2
# 595 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_CHESNAUGHT, LEVEL_SCALE_WILD_BOSS, ITEM_CHESNAUGHTITE
# 596 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 597 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 598 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 599 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 600 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 601 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Chesnaught_3
# 602 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Chesnaught_3
# 613 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Chesnaught_4
# 614 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Chesnaught_4
Common_EventScript_Alpha_Chesnaught_1:
# 621 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Chesnaught_3:
# 603 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_CHESNAUGHT_MEGA_STONE
# 604 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 605 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 606 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 607 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 608 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Chesnaught_6
Common_EventScript_Alpha_Chesnaught_5:
	goto Common_EventScript_Alpha_Chesnaught_1

Common_EventScript_Alpha_Chesnaught_4:
# 615 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 616 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 617 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 618 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Chesnaught_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Chesnaught_1

Common_EventScript_Alpha_Chesnaught_6:
# 609 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Chesnaught_Text_0, MSGBOX_DEFAULT
# 610 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_CHESNAUGHTITE, 1
	goto Common_EventScript_Alpha_Chesnaught_5


Common_Eventscript_Enable_Alphas_Greninja::
# 626 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 627 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_GRENINJA_MEGA_STONE, Common_Eventscript_Enable_Alphas_Greninja_1
	return

Common_Eventscript_Enable_Alphas_Greninja_1:
# 628 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Greninja::
# 633 "data/scripts/alpha_mon_scripts.pory"
	lock
# 634 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 635 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 636 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_GRENINJA, 2
# 637 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_GRENINJA, LEVEL_SCALE_WILD_BOSS, ITEM_GRENINJITE
# 638 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 639 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 640 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 641 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 642 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 643 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Greninja_3
# 644 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Greninja_3
# 655 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Greninja_4
# 656 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Greninja_4
Common_EventScript_Alpha_Greninja_1:
# 663 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Greninja_3:
# 645 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_GRENINJA_MEGA_STONE
# 646 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 647 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 648 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 649 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 650 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Greninja_6
Common_EventScript_Alpha_Greninja_5:
	goto Common_EventScript_Alpha_Greninja_1

Common_EventScript_Alpha_Greninja_4:
# 657 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 658 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 659 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 660 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Greninja_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Greninja_1

Common_EventScript_Alpha_Greninja_6:
# 651 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Greninja_Text_0, MSGBOX_DEFAULT
# 652 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_GRENINJITE, 1
	goto Common_EventScript_Alpha_Greninja_5


Common_Eventscript_Enable_Alphas_Pyroar::
# 668 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 669 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_PYROAR_MEGA_STONE, Common_Eventscript_Enable_Alphas_Pyroar_1
	return

Common_Eventscript_Enable_Alphas_Pyroar_1:
# 670 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Pyroar::
# 675 "data/scripts/alpha_mon_scripts.pory"
	lock
# 676 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 677 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 678 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_PYROAR, 2
# 679 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_PYROAR, LEVEL_SCALE_WILD_BOSS, ITEM_PYROARITE
# 680 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 681 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 682 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 683 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 684 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 685 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Pyroar_3
# 686 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Pyroar_3
# 697 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Pyroar_4
# 698 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Pyroar_4
Common_EventScript_Alpha_Pyroar_1:
# 705 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Pyroar_3:
# 687 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_PYROAR_MEGA_STONE
# 688 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 689 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 690 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 691 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 692 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Pyroar_6
Common_EventScript_Alpha_Pyroar_5:
	goto Common_EventScript_Alpha_Pyroar_1

Common_EventScript_Alpha_Pyroar_4:
# 699 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 700 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 701 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 702 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Pyroar_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Pyroar_1

Common_EventScript_Alpha_Pyroar_6:
# 693 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Pyroar_Text_0, MSGBOX_DEFAULT
# 694 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_PYROARITE, 1
	goto Common_EventScript_Alpha_Pyroar_5


Common_Eventscript_Enable_Alphas_Malamar::
# 710 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 711 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_MALAMAR_MEGA_STONE, Common_Eventscript_Enable_Alphas_Malamar_1
	return

Common_Eventscript_Enable_Alphas_Malamar_1:
# 712 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Malamar::
# 717 "data/scripts/alpha_mon_scripts.pory"
	lock
# 718 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 719 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 720 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_MALAMAR, 2
# 721 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_MALAMAR, LEVEL_SCALE_WILD_BOSS, ITEM_MALAMARITE
# 722 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 723 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 724 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 725 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 726 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 727 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Malamar_3
# 728 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Malamar_3
# 739 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Malamar_4
# 740 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Malamar_4
Common_EventScript_Alpha_Malamar_1:
# 747 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Malamar_3:
# 729 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_MALAMAR_MEGA_STONE
# 730 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 731 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 732 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 733 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 734 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Malamar_6
Common_EventScript_Alpha_Malamar_5:
	goto Common_EventScript_Alpha_Malamar_1

Common_EventScript_Alpha_Malamar_4:
# 741 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 742 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 743 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 744 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Malamar_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Malamar_1

Common_EventScript_Alpha_Malamar_6:
# 735 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Malamar_Text_0, MSGBOX_DEFAULT
# 736 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_MALAMARITE, 1
	goto Common_EventScript_Alpha_Malamar_5


Common_Eventscript_Enable_Alphas_Barbaracle::
# 752 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 753 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_BARBARACLE_MEGA_STONE, Common_Eventscript_Enable_Alphas_Barbaracle_1
	return

Common_Eventscript_Enable_Alphas_Barbaracle_1:
# 754 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Barbaracle::
# 759 "data/scripts/alpha_mon_scripts.pory"
	lock
# 760 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 761 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 762 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_BARBARACLE, 2
# 763 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_BARBARACLE, LEVEL_SCALE_WILD_BOSS, ITEM_BARBARACITE
# 764 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 765 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 766 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 767 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 768 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 769 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Barbaracle_3
# 770 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Barbaracle_3
# 781 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Barbaracle_4
# 782 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Barbaracle_4
Common_EventScript_Alpha_Barbaracle_1:
# 789 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Barbaracle_3:
# 771 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_BARBARACLE_MEGA_STONE
# 772 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 773 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 774 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 775 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 776 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Barbaracle_6
Common_EventScript_Alpha_Barbaracle_5:
	goto Common_EventScript_Alpha_Barbaracle_1

Common_EventScript_Alpha_Barbaracle_4:
# 783 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 784 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 785 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 786 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Barbaracle_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Barbaracle_1

Common_EventScript_Alpha_Barbaracle_6:
# 777 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Barbaracle_Text_0, MSGBOX_DEFAULT
# 778 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_BARBARACITE, 1
	goto Common_EventScript_Alpha_Barbaracle_5


Common_Eventscript_Enable_Alphas_Dragalge::
# 794 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 795 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_DRAGALGE_MEGA_STONE, Common_Eventscript_Enable_Alphas_Dragalge_1
	return

Common_Eventscript_Enable_Alphas_Dragalge_1:
# 796 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Dragalge::
# 801 "data/scripts/alpha_mon_scripts.pory"
	lock
# 802 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 803 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 804 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_DRAGALGE, 2
# 805 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_DRAGALGE, LEVEL_SCALE_WILD_BOSS, ITEM_DRAGALGITE
# 806 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 807 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 808 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 809 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 810 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 811 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Dragalge_3
# 812 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Dragalge_3
# 823 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Dragalge_4
# 824 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Dragalge_4
Common_EventScript_Alpha_Dragalge_1:
# 831 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Dragalge_3:
# 813 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_DRAGALGE_MEGA_STONE
# 814 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 815 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 816 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 817 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 818 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Dragalge_6
Common_EventScript_Alpha_Dragalge_5:
	goto Common_EventScript_Alpha_Dragalge_1

Common_EventScript_Alpha_Dragalge_4:
# 825 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 826 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 827 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 828 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Dragalge_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Dragalge_1

Common_EventScript_Alpha_Dragalge_6:
# 819 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Dragalge_Text_0, MSGBOX_DEFAULT
# 820 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_DRAGALGITE, 1
	goto Common_EventScript_Alpha_Dragalge_5


Common_Eventscript_Enable_Alphas_Hawlucha::
# 836 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 837 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_HAWLUCHA_MEGA_STONE, Common_Eventscript_Enable_Alphas_Hawlucha_1
	return

Common_Eventscript_Enable_Alphas_Hawlucha_1:
# 838 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Hawlucha::
# 843 "data/scripts/alpha_mon_scripts.pory"
	lock
# 844 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 845 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 846 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_HAWLUCHA, 2
# 847 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_HAWLUCHA, LEVEL_SCALE_WILD_BOSS, ITEM_HAWLUCHANITE
# 848 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 849 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 850 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 851 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 852 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 853 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Hawlucha_3
# 854 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Hawlucha_3
# 865 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Hawlucha_4
# 866 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Hawlucha_4
Common_EventScript_Alpha_Hawlucha_1:
# 873 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Hawlucha_3:
# 855 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_HAWLUCHA_MEGA_STONE
# 856 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 857 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 858 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 859 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 860 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Hawlucha_6
Common_EventScript_Alpha_Hawlucha_5:
	goto Common_EventScript_Alpha_Hawlucha_1

Common_EventScript_Alpha_Hawlucha_4:
# 867 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 868 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 869 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 870 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Hawlucha_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Hawlucha_1

Common_EventScript_Alpha_Hawlucha_6:
# 861 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Hawlucha_Text_0, MSGBOX_DEFAULT
# 862 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_HAWLUCHANITE, 1
	goto Common_EventScript_Alpha_Hawlucha_5


Common_Eventscript_Enable_Alphas_Zygarde::
# 878 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 879 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_ZYGARDE_MEGA_STONE, Common_Eventscript_Enable_Alphas_Zygarde_1
	return

Common_Eventscript_Enable_Alphas_Zygarde_1:
# 880 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Zygarde::
# 885 "data/scripts/alpha_mon_scripts.pory"
	lock
# 886 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 887 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 888 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_ZYGARDE, 2
# 889 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_ZYGARDE, LEVEL_SCALE_WILD_BOSS, ITEM_ZYGARDITE
# 890 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 891 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 892 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 893 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 894 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 895 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Zygarde_3
# 896 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Zygarde_3
# 907 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Zygarde_4
# 908 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Zygarde_4
Common_EventScript_Alpha_Zygarde_1:
# 915 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Zygarde_3:
# 897 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_ZYGARDE_MEGA_STONE
# 898 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 899 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 900 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 901 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 902 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Zygarde_6
Common_EventScript_Alpha_Zygarde_5:
	goto Common_EventScript_Alpha_Zygarde_1

Common_EventScript_Alpha_Zygarde_4:
# 909 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 910 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 911 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 912 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Zygarde_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Zygarde_1

Common_EventScript_Alpha_Zygarde_6:
# 903 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Zygarde_Text_0, MSGBOX_DEFAULT
# 904 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_ZYGARDITE, 1
	goto Common_EventScript_Alpha_Zygarde_5


Common_Eventscript_Enable_Alphas_Drampa::
# 920 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 921 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_DRAMPA_MEGA_STONE, Common_Eventscript_Enable_Alphas_Drampa_1
	return

Common_Eventscript_Enable_Alphas_Drampa_1:
# 922 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Drampa::
# 927 "data/scripts/alpha_mon_scripts.pory"
	lock
# 928 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 929 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 930 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_DRAMPA, 2
# 931 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_DRAMPA, LEVEL_SCALE_WILD_BOSS, ITEM_DRAMPANITE
# 932 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 933 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 934 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 935 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 936 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 937 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Drampa_3
# 938 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Drampa_3
# 949 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Drampa_4
# 950 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Drampa_4
Common_EventScript_Alpha_Drampa_1:
# 957 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Drampa_3:
# 939 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_DRAMPA_MEGA_STONE
# 940 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 941 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 942 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 943 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 944 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Drampa_6
Common_EventScript_Alpha_Drampa_5:
	goto Common_EventScript_Alpha_Drampa_1

Common_EventScript_Alpha_Drampa_4:
# 951 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 952 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 953 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 954 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Drampa_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Drampa_1

Common_EventScript_Alpha_Drampa_6:
# 945 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Drampa_Text_0, MSGBOX_DEFAULT
# 946 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_DRAMPANITE, 1
	goto Common_EventScript_Alpha_Drampa_5


Common_Eventscript_Enable_Alphas_Falinks::
# 962 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 963 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_FALINKS_MEGA_STONE, Common_Eventscript_Enable_Alphas_Falinks_1
	return

Common_Eventscript_Enable_Alphas_Falinks_1:
# 964 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Falinks::
# 969 "data/scripts/alpha_mon_scripts.pory"
	lock
# 970 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 971 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 972 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_FALINKS, 2
# 973 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_FALINKS, LEVEL_SCALE_WILD_BOSS, ITEM_FALINKSITE
# 974 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 975 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 976 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 977 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 978 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 979 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Falinks_3
# 980 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Falinks_3
# 991 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Falinks_4
# 992 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Falinks_4
Common_EventScript_Alpha_Falinks_1:
# 999 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Falinks_3:
# 981 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_FALINKS_MEGA_STONE
# 982 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 983 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 984 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 985 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 986 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Falinks_6
Common_EventScript_Alpha_Falinks_5:
	goto Common_EventScript_Alpha_Falinks_1

Common_EventScript_Alpha_Falinks_4:
# 993 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 994 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 995 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 996 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Falinks_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Falinks_1

Common_EventScript_Alpha_Falinks_6:
# 987 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Falinks_Text_0, MSGBOX_DEFAULT
# 988 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_FALINKSITE, 1
	goto Common_EventScript_Alpha_Falinks_5


Common_Eventscript_Enable_Alphas_Raichu_X::
# 1004 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1005 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_RAICHU_X_MEGA_STONE, Common_Eventscript_Enable_Alphas_Raichu_X_1
	return

Common_Eventscript_Enable_Alphas_Raichu_X_1:
# 1006 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Raichu_X::
# 1011 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1012 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1013 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1014 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_RAICHU, 2
# 1015 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_RAICHU, LEVEL_SCALE_WILD_BOSS, ITEM_RAICHUNITE_X
# 1016 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1017 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1018 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1019 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1020 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1021 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Raichu_X_3
# 1022 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Raichu_X_3
# 1033 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Raichu_X_4
# 1034 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Raichu_X_4
Common_EventScript_Alpha_Raichu_X_1:
# 1041 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Raichu_X_3:
# 1023 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_RAICHU_X_MEGA_STONE
# 1024 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1025 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1026 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1027 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1028 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Raichu_X_6
Common_EventScript_Alpha_Raichu_X_5:
	goto Common_EventScript_Alpha_Raichu_X_1

Common_EventScript_Alpha_Raichu_X_4:
# 1035 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1036 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1037 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1038 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Raichu_X_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Raichu_X_1

Common_EventScript_Alpha_Raichu_X_6:
# 1029 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Raichu_X_Text_0, MSGBOX_DEFAULT
# 1030 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_RAICHUNITE_X, 1
	goto Common_EventScript_Alpha_Raichu_X_5


Common_Eventscript_Enable_Alphas_Raichu_Y::
# 1046 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1047 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_RAICHU_Y_MEGA_STONE, Common_Eventscript_Enable_Alphas_Raichu_Y_1
	return

Common_Eventscript_Enable_Alphas_Raichu_Y_1:
# 1048 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Raichu_Y::
# 1053 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1054 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1055 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1056 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_RAICHU, 2
# 1057 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_RAICHU, LEVEL_SCALE_WILD_BOSS, ITEM_RAICHUNITE_Y
# 1058 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1059 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1060 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1061 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1062 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1063 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Raichu_Y_3
# 1064 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Raichu_Y_3
# 1075 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Raichu_Y_4
# 1076 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Raichu_Y_4
Common_EventScript_Alpha_Raichu_Y_1:
# 1083 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Raichu_Y_3:
# 1065 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_RAICHU_Y_MEGA_STONE
# 1066 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1067 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1068 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1069 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1070 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Raichu_Y_6
Common_EventScript_Alpha_Raichu_Y_5:
	goto Common_EventScript_Alpha_Raichu_Y_1

Common_EventScript_Alpha_Raichu_Y_4:
# 1077 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1078 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1079 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1080 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Raichu_Y_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Raichu_Y_1

Common_EventScript_Alpha_Raichu_Y_6:
# 1071 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Raichu_Y_Text_0, MSGBOX_DEFAULT
# 1072 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_RAICHUNITE_Y, 1
	goto Common_EventScript_Alpha_Raichu_Y_5


Common_Eventscript_Enable_Alphas_Dewgong::
# 1088 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1089 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_DEWGONG_MEGA_STONE, Common_Eventscript_Enable_Alphas_Dewgong_1
	return

Common_Eventscript_Enable_Alphas_Dewgong_1:
# 1090 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Dewgong::
# 1095 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1096 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1097 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1098 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_DEWGONG, 2
# 1099 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_DEWGONG, LEVEL_SCALE_WILD_BOSS, ITEM_DEWGONGITE
# 1100 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1101 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1102 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1103 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1104 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1105 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Dewgong_3
# 1106 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Dewgong_3
# 1117 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Dewgong_4
# 1118 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Dewgong_4
Common_EventScript_Alpha_Dewgong_1:
# 1125 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Dewgong_3:
# 1107 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_DEWGONG_MEGA_STONE
# 1108 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1109 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1110 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1111 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1112 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Dewgong_6
Common_EventScript_Alpha_Dewgong_5:
	goto Common_EventScript_Alpha_Dewgong_1

Common_EventScript_Alpha_Dewgong_4:
# 1119 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1120 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1121 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1122 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Dewgong_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Dewgong_1

Common_EventScript_Alpha_Dewgong_6:
# 1113 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Dewgong_Text_0, MSGBOX_DEFAULT
# 1114 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_DEWGONGITE, 1
	goto Common_EventScript_Alpha_Dewgong_5


Common_Eventscript_Enable_Alphas_Typhlosion::
# 1130 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1131 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_TYPHLOSION_MEGA_STONE, Common_Eventscript_Enable_Alphas_Typhlosion_1
	return

Common_Eventscript_Enable_Alphas_Typhlosion_1:
# 1132 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Typhlosion::
# 1137 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1138 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1139 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1140 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_TYPHLOSION, 2
# 1141 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_TYPHLOSION, LEVEL_SCALE_WILD_BOSS, ITEM_TYPHLOSIONITE
# 1142 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1143 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1144 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1145 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1146 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1147 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Typhlosion_3
# 1148 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Typhlosion_3
# 1159 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Typhlosion_4
# 1160 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Typhlosion_4
Common_EventScript_Alpha_Typhlosion_1:
# 1167 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Typhlosion_3:
# 1149 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_TYPHLOSION_MEGA_STONE
# 1150 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1151 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1152 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1153 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1154 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Typhlosion_6
Common_EventScript_Alpha_Typhlosion_5:
	goto Common_EventScript_Alpha_Typhlosion_1

Common_EventScript_Alpha_Typhlosion_4:
# 1161 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1162 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1163 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1164 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Typhlosion_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Typhlosion_1

Common_EventScript_Alpha_Typhlosion_6:
# 1155 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Typhlosion_Text_0, MSGBOX_DEFAULT
# 1156 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_TYPHLOSIONITE, 1
	goto Common_EventScript_Alpha_Typhlosion_5


Common_Eventscript_Enable_Alphas_Lanturn::
# 1172 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1173 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_LANTURN_MEGA_STONE, Common_Eventscript_Enable_Alphas_Lanturn_1
	return

Common_Eventscript_Enable_Alphas_Lanturn_1:
# 1174 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Lanturn::
# 1179 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1180 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1181 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1182 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_LANTURN, 2
# 1183 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_LANTURN, LEVEL_SCALE_WILD_BOSS, ITEM_LANTURNITE
# 1184 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1185 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1186 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1187 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1188 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1189 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Lanturn_3
# 1190 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Lanturn_3
# 1201 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Lanturn_4
# 1202 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Lanturn_4
Common_EventScript_Alpha_Lanturn_1:
# 1209 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Lanturn_3:
# 1191 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_LANTURN_MEGA_STONE
# 1192 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1193 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1194 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1195 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1196 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Lanturn_6
Common_EventScript_Alpha_Lanturn_5:
	goto Common_EventScript_Alpha_Lanturn_1

Common_EventScript_Alpha_Lanturn_4:
# 1203 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1204 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1205 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1206 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Lanturn_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Lanturn_1

Common_EventScript_Alpha_Lanturn_6:
# 1197 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Lanturn_Text_0, MSGBOX_DEFAULT
# 1198 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_LANTURNITE, 1
	goto Common_EventScript_Alpha_Lanturn_5


Common_Eventscript_Enable_Alphas_Quagsire::
# 1214 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1215 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_QUAGSIRE_MEGA_STONE, Common_Eventscript_Enable_Alphas_Quagsire_1
	return

Common_Eventscript_Enable_Alphas_Quagsire_1:
# 1216 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Quagsire::
# 1221 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1222 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1223 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1224 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_QUAGSIRE, 2
# 1225 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_QUAGSIRE, LEVEL_SCALE_WILD_BOSS, ITEM_QUAGSIRITE
# 1226 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1227 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1228 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1229 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1230 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1231 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Quagsire_3
# 1232 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Quagsire_3
# 1243 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Quagsire_4
# 1244 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Quagsire_4
Common_EventScript_Alpha_Quagsire_1:
# 1251 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Quagsire_3:
# 1233 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_QUAGSIRE_MEGA_STONE
# 1234 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1235 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1236 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1237 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1238 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Quagsire_6
Common_EventScript_Alpha_Quagsire_5:
	goto Common_EventScript_Alpha_Quagsire_1

Common_EventScript_Alpha_Quagsire_4:
# 1245 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1246 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1247 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1248 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Quagsire_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Quagsire_1

Common_EventScript_Alpha_Quagsire_6:
# 1239 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Quagsire_Text_0, MSGBOX_DEFAULT
# 1240 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_QUAGSIRITE, 1
	goto Common_EventScript_Alpha_Quagsire_5


Common_Eventscript_Enable_Alphas_Breloom::
# 1256 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1257 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_BRELOOM_MEGA_STONE, Common_Eventscript_Enable_Alphas_Breloom_1
	return

Common_Eventscript_Enable_Alphas_Breloom_1:
# 1258 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Breloom::
# 1263 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1264 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1265 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1266 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_BRELOOM, 2
# 1267 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_BRELOOM, LEVEL_SCALE_WILD_BOSS, ITEM_BRELOOMITE
# 1268 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1269 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1270 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1271 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1272 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1273 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Breloom_3
# 1274 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Breloom_3
# 1285 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Breloom_4
# 1286 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Breloom_4
Common_EventScript_Alpha_Breloom_1:
# 1293 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Breloom_3:
# 1275 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_BRELOOM_MEGA_STONE
# 1276 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1277 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1278 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1279 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1280 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Breloom_6
Common_EventScript_Alpha_Breloom_5:
	goto Common_EventScript_Alpha_Breloom_1

Common_EventScript_Alpha_Breloom_4:
# 1287 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1288 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1289 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1290 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Breloom_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Breloom_1

Common_EventScript_Alpha_Breloom_6:
# 1281 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Breloom_Text_0, MSGBOX_DEFAULT
# 1282 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_BRELOOMITE, 1
	goto Common_EventScript_Alpha_Breloom_5


Common_Eventscript_Enable_Alphas_Shedinja::
# 1298 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1299 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_SHEDINJA_MEGA_STONE, Common_Eventscript_Enable_Alphas_Shedinja_1
	return

Common_Eventscript_Enable_Alphas_Shedinja_1:
# 1300 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Shedinja::
# 1305 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1306 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1307 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1308 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_SHEDINJA, 2
# 1309 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_SHEDINJA, LEVEL_SCALE_WILD_BOSS, ITEM_SHEDINJITE
# 1310 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1311 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1312 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1313 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1314 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1315 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Shedinja_3
# 1316 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Shedinja_3
# 1327 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Shedinja_4
# 1328 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Shedinja_4
Common_EventScript_Alpha_Shedinja_1:
# 1335 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Shedinja_3:
# 1317 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_SHEDINJA_MEGA_STONE
# 1318 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1319 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1320 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1321 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1322 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Shedinja_6
Common_EventScript_Alpha_Shedinja_5:
	goto Common_EventScript_Alpha_Shedinja_1

Common_EventScript_Alpha_Shedinja_4:
# 1329 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1330 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1331 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1332 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Shedinja_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Shedinja_1

Common_EventScript_Alpha_Shedinja_6:
# 1323 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Shedinja_Text_0, MSGBOX_DEFAULT
# 1324 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_SHEDINJITE, 1
	goto Common_EventScript_Alpha_Shedinja_5


Common_Eventscript_Enable_Alphas_Flygon::
# 1340 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1341 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_FLYGON_MEGA_STONE, Common_Eventscript_Enable_Alphas_Flygon_1
	return

Common_Eventscript_Enable_Alphas_Flygon_1:
# 1342 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Flygon::
# 1347 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1348 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1349 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1350 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Flygon_Text_0, MSGBOX_DEFAULT
# 1351 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_FLYGON, 2
# 1352 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_FLYGON, LEVEL_SCALE_WILD_BOSS, ITEM_FLYGONITE
# 1353 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1354 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1355 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1356 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1357 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1358 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Flygon_3
# 1359 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Flygon_3
# 1370 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Flygon_4
# 1371 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Flygon_4
Common_EventScript_Alpha_Flygon_1:
# 1378 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Flygon_3:
# 1360 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_FLYGON_MEGA_STONE
# 1361 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1362 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1363 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1364 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1365 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Flygon_6
Common_EventScript_Alpha_Flygon_5:
	goto Common_EventScript_Alpha_Flygon_1

Common_EventScript_Alpha_Flygon_4:
# 1372 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1373 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1374 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1375 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Flygon_Text_2, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Flygon_1

Common_EventScript_Alpha_Flygon_6:
# 1366 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Flygon_Text_1, MSGBOX_DEFAULT
# 1367 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_FLYGONITE, 1
	goto Common_EventScript_Alpha_Flygon_5


Common_Eventscript_Enable_Alphas_Serperior::
# 1383 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1384 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_SERPERIOR_MEGA_STONE, Common_Eventscript_Enable_Alphas_Serperior_1
	return

Common_Eventscript_Enable_Alphas_Serperior_1:
# 1385 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Serperior::
# 1390 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1391 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1392 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1393 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_SERPERIOR, 2
# 1394 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_SERPERIOR, LEVEL_SCALE_WILD_BOSS, ITEM_SERPERIORITE
# 1395 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1396 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1397 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1398 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1399 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1400 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Serperior_3
# 1401 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Serperior_3
# 1412 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Serperior_4
# 1413 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Serperior_4
Common_EventScript_Alpha_Serperior_1:
# 1420 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Serperior_3:
# 1402 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_SERPERIOR_MEGA_STONE
# 1403 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1404 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1405 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1406 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1407 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Serperior_6
Common_EventScript_Alpha_Serperior_5:
	goto Common_EventScript_Alpha_Serperior_1

Common_EventScript_Alpha_Serperior_4:
# 1414 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1415 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1416 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1417 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Serperior_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Serperior_1

Common_EventScript_Alpha_Serperior_6:
# 1408 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Serperior_Text_0, MSGBOX_DEFAULT
# 1409 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_SERPERIORITE, 1
	goto Common_EventScript_Alpha_Serperior_5


Common_Eventscript_Enable_Alphas_Samurott::
# 1425 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1426 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_SAMUROTT_MEGA_STONE, Common_Eventscript_Enable_Alphas_Samurott_1
	return

Common_Eventscript_Enable_Alphas_Samurott_1:
# 1427 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Samurott::
# 1432 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1433 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1434 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1435 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_SAMUROTT, 2
# 1436 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_SAMUROTT, LEVEL_SCALE_WILD_BOSS, ITEM_SAMUROTTITE
# 1437 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1438 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1439 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1440 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1441 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1442 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Samurott_3
# 1443 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Samurott_3
# 1454 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Samurott_4
# 1455 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Samurott_4
Common_EventScript_Alpha_Samurott_1:
# 1462 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Samurott_3:
# 1444 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_SAMUROTT_MEGA_STONE
# 1445 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1446 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1447 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1448 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1449 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Samurott_6
Common_EventScript_Alpha_Samurott_5:
	goto Common_EventScript_Alpha_Samurott_1

Common_EventScript_Alpha_Samurott_4:
# 1456 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1457 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1458 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1459 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Samurott_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Samurott_1

Common_EventScript_Alpha_Samurott_6:
# 1450 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Samurott_Text_0, MSGBOX_DEFAULT
# 1451 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_SAMUROTTITE, 1
	goto Common_EventScript_Alpha_Samurott_5


Common_Eventscript_Enable_Alphas_Ribombee::
# 1467 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1468 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_RIBOMBEE_MEGA_STONE, Common_Eventscript_Enable_Alphas_Ribombee_1
	return

Common_Eventscript_Enable_Alphas_Ribombee_1:
# 1469 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Ribombee::
# 1474 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1475 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1476 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1477 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_RIBOMBEE, 2
# 1478 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_RIBOMBEE, LEVEL_SCALE_WILD_BOSS, ITEM_RIBOMBITE
# 1479 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1480 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1481 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1482 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1483 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1484 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Ribombee_3
# 1485 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Ribombee_3
# 1496 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Ribombee_4
# 1497 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Ribombee_4
Common_EventScript_Alpha_Ribombee_1:
# 1504 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Ribombee_3:
# 1486 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_RIBOMBEE_MEGA_STONE
# 1487 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1488 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1489 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1490 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1491 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Ribombee_6
Common_EventScript_Alpha_Ribombee_5:
	goto Common_EventScript_Alpha_Ribombee_1

Common_EventScript_Alpha_Ribombee_4:
# 1498 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1499 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1500 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1501 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Ribombee_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Ribombee_1

Common_EventScript_Alpha_Ribombee_6:
# 1492 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Ribombee_Text_0, MSGBOX_DEFAULT
# 1493 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_RIBOMBITE, 1
	goto Common_EventScript_Alpha_Ribombee_5


Common_Eventscript_Enable_Alphas_Clodsire::
# 1509 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1510 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_CLODSIRE_MEGA_STONE, Common_Eventscript_Enable_Alphas_Clodsire_1
	return

Common_Eventscript_Enable_Alphas_Clodsire_1:
# 1511 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Clodsire::
# 1516 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1517 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1518 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1519 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_CLODSIRE, 2
# 1520 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_CLODSIRE, LEVEL_SCALE_WILD_BOSS, ITEM_CLODSIRITE
# 1521 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1522 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1523 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1524 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1525 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1526 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Clodsire_3
# 1527 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Clodsire_3
# 1538 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Clodsire_4
# 1539 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Clodsire_4
Common_EventScript_Alpha_Clodsire_1:
# 1546 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Clodsire_3:
# 1528 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_CLODSIRE_MEGA_STONE
# 1529 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1530 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1531 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1532 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1533 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Clodsire_6
Common_EventScript_Alpha_Clodsire_5:
	goto Common_EventScript_Alpha_Clodsire_1

Common_EventScript_Alpha_Clodsire_4:
# 1540 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1541 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1542 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1543 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Clodsire_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Clodsire_1

Common_EventScript_Alpha_Clodsire_6:
# 1534 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Clodsire_Text_0, MSGBOX_DEFAULT
# 1535 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_CLODSIRITE, 1
	goto Common_EventScript_Alpha_Clodsire_5


Common_Eventscript_Enable_Alphas_Sandslash::
# 1551 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1552 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_SANDSLASH_MEGA_STONE, Common_Eventscript_Enable_Alphas_Sandslash_1
	return

Common_Eventscript_Enable_Alphas_Sandslash_1:
# 1553 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Sandslash::
# 1558 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1559 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1560 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1561 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_SANDSLASH, 2
# 1562 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_SANDSLASH, LEVEL_SCALE_WILD_BOSS, ITEM_SANDSLASHITE
# 1563 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1564 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1565 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1566 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1567 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1568 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Sandslash_3
# 1569 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Sandslash_3
# 1580 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Sandslash_4
# 1581 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Sandslash_4
Common_EventScript_Alpha_Sandslash_1:
# 1588 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Sandslash_3:
# 1570 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_SANDSLASH_MEGA_STONE
# 1571 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1572 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1573 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1574 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1575 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Sandslash_6
Common_EventScript_Alpha_Sandslash_5:
	goto Common_EventScript_Alpha_Sandslash_1

Common_EventScript_Alpha_Sandslash_4:
# 1582 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1583 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1584 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1585 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Sandslash_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Sandslash_1

Common_EventScript_Alpha_Sandslash_6:
# 1576 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Sandslash_Text_0, MSGBOX_DEFAULT
# 1577 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_SANDSLASHITE, 1
	goto Common_EventScript_Alpha_Sandslash_5


Common_Eventscript_Enable_Alphas_Toucannon::
# 1593 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1594 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_TOUCANNON_MEGA_STONE, Common_Eventscript_Enable_Alphas_Toucannon_1
	return

Common_Eventscript_Enable_Alphas_Toucannon_1:
# 1595 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Toucannon::
# 1600 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1601 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1602 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1603 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_TOUCANNON, 2
# 1604 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_TOUCANNON, LEVEL_SCALE_WILD_BOSS, ITEM_TOUCANNONITE
# 1605 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1606 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1607 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1608 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1609 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1610 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Toucannon_3
# 1611 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Toucannon_3
# 1622 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Toucannon_4
# 1623 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Toucannon_4
Common_EventScript_Alpha_Toucannon_1:
# 1630 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Toucannon_3:
# 1612 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_TOUCANNON_MEGA_STONE
# 1613 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1614 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1615 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1616 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1617 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Toucannon_6
Common_EventScript_Alpha_Toucannon_5:
	goto Common_EventScript_Alpha_Toucannon_1

Common_EventScript_Alpha_Toucannon_4:
# 1624 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1625 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1626 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1627 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Toucannon_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Toucannon_1

Common_EventScript_Alpha_Toucannon_6:
# 1618 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Toucannon_Text_0, MSGBOX_DEFAULT
# 1619 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_TOUCANNONITE, 1
	goto Common_EventScript_Alpha_Toucannon_5


Common_Eventscript_Enable_Alphas_Vanilluxe::
# 1635 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1636 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_VANILLUXE_MEGA_STONE, Common_Eventscript_Enable_Alphas_Vanilluxe_1
	return

Common_Eventscript_Enable_Alphas_Vanilluxe_1:
# 1637 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Vanilluxe::
# 1642 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1643 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1644 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1645 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_VANILLUXE, 2
# 1646 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_VANILLUXE, LEVEL_SCALE_WILD_BOSS, ITEM_VANILLUXITE
# 1647 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1648 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1649 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1650 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1651 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1652 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Vanilluxe_3
# 1653 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Vanilluxe_3
# 1664 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Vanilluxe_4
# 1665 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Vanilluxe_4
Common_EventScript_Alpha_Vanilluxe_1:
# 1672 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Vanilluxe_3:
# 1654 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_VANILLUXE_MEGA_STONE
# 1655 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1656 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1657 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1658 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1659 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Vanilluxe_6
Common_EventScript_Alpha_Vanilluxe_5:
	goto Common_EventScript_Alpha_Vanilluxe_1

Common_EventScript_Alpha_Vanilluxe_4:
# 1666 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1667 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1668 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1669 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Vanilluxe_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Vanilluxe_1

Common_EventScript_Alpha_Vanilluxe_6:
# 1660 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Vanilluxe_Text_0, MSGBOX_DEFAULT
# 1661 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_VANILLUXITE, 1
	goto Common_EventScript_Alpha_Vanilluxe_5


Common_Eventscript_Enable_Alphas_Tinkaton::
# 1677 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1678 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_TINKATON_MEGA_STONE, Common_Eventscript_Enable_Alphas_Tinkaton_1
	return

Common_Eventscript_Enable_Alphas_Tinkaton_1:
# 1679 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Tinkaton::
# 1684 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1685 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1686 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1687 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_TINKATON, 2
# 1688 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_TINKATON, LEVEL_SCALE_WILD_BOSS, ITEM_TINKATITE
# 1689 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1690 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1691 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1692 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1693 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1694 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Tinkaton_3
# 1695 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Tinkaton_3
# 1706 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Tinkaton_4
# 1707 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Tinkaton_4
Common_EventScript_Alpha_Tinkaton_1:
# 1714 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Tinkaton_3:
# 1696 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_TINKATON_MEGA_STONE
# 1697 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1698 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1699 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1700 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1701 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Tinkaton_6
Common_EventScript_Alpha_Tinkaton_5:
	goto Common_EventScript_Alpha_Tinkaton_1

Common_EventScript_Alpha_Tinkaton_4:
# 1708 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1709 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1710 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1711 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Tinkaton_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Tinkaton_1

Common_EventScript_Alpha_Tinkaton_6:
# 1702 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Tinkaton_Text_0, MSGBOX_DEFAULT
# 1703 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_TINKATITE, 1
	goto Common_EventScript_Alpha_Tinkaton_5


Common_Eventscript_Enable_Alphas_Shuckle::
# 1719 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1720 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_SHUCKLE_MEGA_STONE, Common_Eventscript_Enable_Alphas_Shuckle_1
	return

Common_Eventscript_Enable_Alphas_Shuckle_1:
# 1721 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Shuckle::
# 1726 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1727 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1728 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1729 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_SHUCKLE, 2
# 1730 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_SHUCKLE, LEVEL_SCALE_WILD_BOSS, ITEM_SHUCKLENITE
# 1731 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1732 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1733 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1734 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1735 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1736 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Shuckle_3
# 1737 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Shuckle_3
# 1748 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Shuckle_4
# 1749 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Shuckle_4
Common_EventScript_Alpha_Shuckle_1:
# 1756 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Shuckle_3:
# 1738 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_SHUCKLE_MEGA_STONE
# 1739 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1740 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1741 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1742 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1743 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Shuckle_6
Common_EventScript_Alpha_Shuckle_5:
	goto Common_EventScript_Alpha_Shuckle_1

Common_EventScript_Alpha_Shuckle_4:
# 1750 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1751 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1752 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1753 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Shuckle_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Shuckle_1

Common_EventScript_Alpha_Shuckle_6:
# 1744 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Shuckle_Text_0, MSGBOX_DEFAULT
# 1745 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_SHUCKLENITE, 1
	goto Common_EventScript_Alpha_Shuckle_5


Common_Eventscript_Enable_Alphas_Krookodile::
# 1761 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1762 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_KROOKODILE_MEGA_STONE, Common_Eventscript_Enable_Alphas_Krookodile_1
	return

Common_Eventscript_Enable_Alphas_Krookodile_1:
# 1763 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Krookodile::
# 1768 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1769 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1770 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1771 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_KROOKODILE, 2
# 1772 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_KROOKODILE, LEVEL_SCALE_WILD_BOSS, ITEM_KROOKODILENITE
# 1773 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1774 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1775 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1776 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1777 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1778 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Krookodile_3
# 1779 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Krookodile_3
# 1790 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Krookodile_4
# 1791 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Krookodile_4
Common_EventScript_Alpha_Krookodile_1:
# 1798 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Krookodile_3:
# 1780 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_KROOKODILE_MEGA_STONE
# 1781 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1782 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1783 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1784 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1785 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Krookodile_6
Common_EventScript_Alpha_Krookodile_5:
	goto Common_EventScript_Alpha_Krookodile_1

Common_EventScript_Alpha_Krookodile_4:
# 1792 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1793 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1794 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1795 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Krookodile_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Krookodile_1

Common_EventScript_Alpha_Krookodile_6:
# 1786 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Krookodile_Text_0, MSGBOX_DEFAULT
# 1787 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_KROOKODILENITE, 1
	goto Common_EventScript_Alpha_Krookodile_5


Common_Eventscript_Enable_Alphas_Luxray::
# 1803 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1804 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_LUXRAY_MEGA_STONE, Common_Eventscript_Enable_Alphas_Luxray_1
	return

Common_Eventscript_Enable_Alphas_Luxray_1:
# 1805 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Luxray::
# 1810 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1811 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1812 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1813 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_LUXRAY, 2
# 1814 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_LUXRAY, LEVEL_SCALE_WILD_BOSS, ITEM_LUXRAYNITE
# 1815 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1816 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1817 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1818 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1819 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1820 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Luxray_3
# 1821 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Luxray_3
# 1832 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Luxray_4
# 1833 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Luxray_4
Common_EventScript_Alpha_Luxray_1:
# 1840 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Luxray_3:
# 1822 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_LUXRAY_MEGA_STONE
# 1823 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1824 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1825 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1826 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1827 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Luxray_6
Common_EventScript_Alpha_Luxray_5:
	goto Common_EventScript_Alpha_Luxray_1

Common_EventScript_Alpha_Luxray_4:
# 1834 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1835 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1836 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1837 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Luxray_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Luxray_1

Common_EventScript_Alpha_Luxray_6:
# 1828 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Luxray_Text_0, MSGBOX_DEFAULT
# 1829 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_LUXRAYNITE, 1
	goto Common_EventScript_Alpha_Luxray_5


Common_Eventscript_Enable_Alphas_Milotic::
# 1845 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1846 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_MILOTIC_MEGA_STONE, Common_Eventscript_Enable_Alphas_Milotic_1
	return

Common_Eventscript_Enable_Alphas_Milotic_1:
# 1847 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Milotic::
# 1852 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1853 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1854 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1855 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_MILOTIC, 2
# 1856 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_MILOTIC, LEVEL_SCALE_WILD_BOSS, ITEM_MILOTICITE
# 1857 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1858 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1859 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1860 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1861 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1862 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Milotic_3
# 1863 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Milotic_3
# 1874 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Milotic_4
# 1875 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Milotic_4
Common_EventScript_Alpha_Milotic_1:
# 1882 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Milotic_3:
# 1864 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_MILOTIC_MEGA_STONE
# 1865 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1866 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1867 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1868 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1869 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Milotic_6
Common_EventScript_Alpha_Milotic_5:
	goto Common_EventScript_Alpha_Milotic_1

Common_EventScript_Alpha_Milotic_4:
# 1876 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1877 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1878 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1879 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Milotic_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Milotic_1

Common_EventScript_Alpha_Milotic_6:
# 1870 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Milotic_Text_0, MSGBOX_DEFAULT
# 1871 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_MILOTICITE, 1
	goto Common_EventScript_Alpha_Milotic_5


Common_Eventscript_Enable_Alphas_Tsareena::
# 1887 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1888 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_TSAREENA_MEGA_STONE, Common_Eventscript_Enable_Alphas_Tsareena_1
	return

Common_Eventscript_Enable_Alphas_Tsareena_1:
# 1889 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Tsareena::
# 1894 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1895 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1896 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1897 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_TSAREENA, 2
# 1898 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_TSAREENA, LEVEL_SCALE_WILD_BOSS, ITEM_TSEERENITE
# 1899 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1900 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1901 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1902 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1903 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1904 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Tsareena_3
# 1905 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Tsareena_3
# 1916 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Tsareena_4
# 1917 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Tsareena_4
Common_EventScript_Alpha_Tsareena_1:
# 1924 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Tsareena_3:
# 1906 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_TSAREENA_MEGA_STONE
# 1907 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1908 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1909 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1910 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1911 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Tsareena_6
Common_EventScript_Alpha_Tsareena_5:
	goto Common_EventScript_Alpha_Tsareena_1

Common_EventScript_Alpha_Tsareena_4:
# 1918 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1919 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1920 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1921 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Tsareena_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Tsareena_1

Common_EventScript_Alpha_Tsareena_6:
# 1912 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Tsareena_Text_0, MSGBOX_DEFAULT
# 1913 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_TSEERENITE, 1
	goto Common_EventScript_Alpha_Tsareena_5


Common_Eventscript_Enable_Alphas_Crobat::
# 1929 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1930 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_CROBAT_MEGA_STONE, Common_Eventscript_Enable_Alphas_Crobat_1
	return

Common_Eventscript_Enable_Alphas_Crobat_1:
# 1931 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Crobat::
# 1936 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1937 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1938 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1939 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_CROBAT, 2
# 1940 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_CROBAT, LEVEL_SCALE_WILD_BOSS, ITEM_CROBATITE
# 1941 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1942 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1943 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1944 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1945 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1946 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Crobat_3
# 1947 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Crobat_3
# 1958 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Crobat_4
# 1959 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Crobat_4
Common_EventScript_Alpha_Crobat_1:
# 1966 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Crobat_3:
# 1948 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_CROBAT_MEGA_STONE
# 1949 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1950 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1951 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1952 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1953 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Crobat_6
Common_EventScript_Alpha_Crobat_5:
	goto Common_EventScript_Alpha_Crobat_1

Common_EventScript_Alpha_Crobat_4:
# 1960 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1961 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1962 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1963 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Crobat_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Crobat_1

Common_EventScript_Alpha_Crobat_6:
# 1954 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Crobat_Text_0, MSGBOX_DEFAULT
# 1955 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_CROBATITE, 1
	goto Common_EventScript_Alpha_Crobat_5


Common_Eventscript_Enable_Alphas_Slowking::
# 1971 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 1972 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_SLOWKING_MEGA_STONE, Common_Eventscript_Enable_Alphas_Slowking_1
	return

Common_Eventscript_Enable_Alphas_Slowking_1:
# 1973 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Slowking::
# 1978 "data/scripts/alpha_mon_scripts.pory"
	lock
# 1979 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 1980 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 1981 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_SLOWKING, 2
# 1982 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_SLOWKING, LEVEL_SCALE_WILD_BOSS, ITEM_SLOWKINGITE
# 1983 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 1984 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 1985 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 1986 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1987 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 1988 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Slowking_3
# 1989 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Slowking_3
# 2000 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Slowking_4
# 2001 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Slowking_4
Common_EventScript_Alpha_Slowking_1:
# 2008 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Slowking_3:
# 1990 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_SLOWKING_MEGA_STONE
# 1991 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 1992 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 1993 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 1994 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 1995 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Slowking_6
Common_EventScript_Alpha_Slowking_5:
	goto Common_EventScript_Alpha_Slowking_1

Common_EventScript_Alpha_Slowking_4:
# 2002 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2003 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2004 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2005 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Slowking_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Slowking_1

Common_EventScript_Alpha_Slowking_6:
# 1996 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Slowking_Text_0, MSGBOX_DEFAULT
# 1997 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_SLOWKINGITE, 1
	goto Common_EventScript_Alpha_Slowking_5


Common_Eventscript_Enable_Alphas_Grimmsnarl::
# 2013 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2014 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_GRIMMSNARL_MEGA_STONE, Common_Eventscript_Enable_Alphas_Grimmsnarl_1
	return

Common_Eventscript_Enable_Alphas_Grimmsnarl_1:
# 2015 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Grimmsnarl::
# 2020 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2021 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2022 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2023 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_GRIMMSNARL, 2
# 2024 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_GRIMMSNARL, LEVEL_SCALE_WILD_BOSS, ITEM_GRIMMSNARLITE
# 2025 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2026 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2027 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2028 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2029 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2030 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Grimmsnarl_3
# 2031 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Grimmsnarl_3
# 2042 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Grimmsnarl_4
# 2043 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Grimmsnarl_4
Common_EventScript_Alpha_Grimmsnarl_1:
# 2050 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Grimmsnarl_3:
# 2032 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_GRIMMSNARL_MEGA_STONE
# 2033 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2034 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2035 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2036 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2037 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Grimmsnarl_6
Common_EventScript_Alpha_Grimmsnarl_5:
	goto Common_EventScript_Alpha_Grimmsnarl_1

Common_EventScript_Alpha_Grimmsnarl_4:
# 2044 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2045 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2046 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2047 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Grimmsnarl_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Grimmsnarl_1

Common_EventScript_Alpha_Grimmsnarl_6:
# 2038 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Grimmsnarl_Text_0, MSGBOX_DEFAULT
# 2039 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_GRIMMSNARLITE, 1
	goto Common_EventScript_Alpha_Grimmsnarl_5


Common_Eventscript_Enable_Alphas_Melmetal::
# 2055 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2056 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_MELMETAL_MEGA_STONE, Common_Eventscript_Enable_Alphas_Melmetal_1
	return

Common_Eventscript_Enable_Alphas_Melmetal_1:
# 2057 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Melmetal::
# 2062 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2063 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2064 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2065 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_MELMETAL, 2
# 2066 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_MELMETAL, LEVEL_SCALE_WILD_BOSS, ITEM_MELMETALITE
# 2067 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2068 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2069 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2070 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2071 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2072 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Melmetal_3
# 2073 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Melmetal_3
# 2084 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Melmetal_4
# 2085 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Melmetal_4
Common_EventScript_Alpha_Melmetal_1:
# 2092 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Melmetal_3:
# 2074 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_MELMETAL_MEGA_STONE
# 2075 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2076 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2077 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2078 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2079 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Melmetal_6
Common_EventScript_Alpha_Melmetal_5:
	goto Common_EventScript_Alpha_Melmetal_1

Common_EventScript_Alpha_Melmetal_4:
# 2086 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2087 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2088 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2089 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Melmetal_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Melmetal_1

Common_EventScript_Alpha_Melmetal_6:
# 2080 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Melmetal_Text_0, MSGBOX_DEFAULT
# 2081 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_MELMETALITE, 1
	goto Common_EventScript_Alpha_Melmetal_5


Common_Eventscript_Enable_Alphas_Rillaboom::
# 2097 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2098 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_RILLABOOM_MEGA_STONE, Common_Eventscript_Enable_Alphas_Rillaboom_1
	return

Common_Eventscript_Enable_Alphas_Rillaboom_1:
# 2099 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Rillaboom::
# 2104 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2105 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2106 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2107 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_RILLABOOM, 2
# 2108 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_RILLABOOM, LEVEL_SCALE_WILD_BOSS, ITEM_RILABOOMITE
# 2109 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2110 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2111 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2112 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2113 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2114 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Rillaboom_3
# 2115 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Rillaboom_3
# 2126 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Rillaboom_4
# 2127 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Rillaboom_4
Common_EventScript_Alpha_Rillaboom_1:
# 2134 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Rillaboom_3:
# 2116 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_RILLABOOM_MEGA_STONE
# 2117 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2118 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2119 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2120 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2121 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Rillaboom_6
Common_EventScript_Alpha_Rillaboom_5:
	goto Common_EventScript_Alpha_Rillaboom_1

Common_EventScript_Alpha_Rillaboom_4:
# 2128 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2129 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2130 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2131 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Rillaboom_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Rillaboom_1

Common_EventScript_Alpha_Rillaboom_6:
# 2122 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Rillaboom_Text_0, MSGBOX_DEFAULT
# 2123 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_RILABOOMITE, 1
	goto Common_EventScript_Alpha_Rillaboom_5


Common_Eventscript_Enable_Alphas_Cinderace::
# 2139 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2140 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_CINDERACE_MEGA_STONE, Common_Eventscript_Enable_Alphas_Cinderace_1
	return

Common_Eventscript_Enable_Alphas_Cinderace_1:
# 2141 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Cinderace::
# 2146 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2147 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2148 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2149 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_CINDERACE, 2
# 2150 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_CINDERACE, LEVEL_SCALE_WILD_BOSS, ITEM_CINDERACITE
# 2151 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2152 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2153 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2154 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2155 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2156 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Cinderace_3
# 2157 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Cinderace_3
# 2168 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Cinderace_4
# 2169 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Cinderace_4
Common_EventScript_Alpha_Cinderace_1:
# 2176 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Cinderace_3:
# 2158 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_CINDERACE_MEGA_STONE
# 2159 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2160 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2161 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2162 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2163 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Cinderace_6
Common_EventScript_Alpha_Cinderace_5:
	goto Common_EventScript_Alpha_Cinderace_1

Common_EventScript_Alpha_Cinderace_4:
# 2170 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2171 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2172 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2173 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Cinderace_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Cinderace_1

Common_EventScript_Alpha_Cinderace_6:
# 2164 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Cinderace_Text_0, MSGBOX_DEFAULT
# 2165 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_CINDERACITE, 1
	goto Common_EventScript_Alpha_Cinderace_5


Common_Eventscript_Enable_Alphas_Inteleon::
# 2181 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2182 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_INTELEON_MEGA_STONE, Common_Eventscript_Enable_Alphas_Inteleon_1
	return

Common_Eventscript_Enable_Alphas_Inteleon_1:
# 2183 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Inteleon::
# 2188 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2189 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2190 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2191 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_INTELEON, 2
# 2192 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_INTELEON, LEVEL_SCALE_WILD_BOSS, ITEM_INTELEONITE
# 2193 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2194 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2195 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2196 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2197 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2198 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Inteleon_3
# 2199 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Inteleon_3
# 2210 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Inteleon_4
# 2211 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Inteleon_4
Common_EventScript_Alpha_Inteleon_1:
# 2218 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Inteleon_3:
# 2200 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_INTELEON_MEGA_STONE
# 2201 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2202 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2203 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2204 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2205 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Inteleon_6
Common_EventScript_Alpha_Inteleon_5:
	goto Common_EventScript_Alpha_Inteleon_1

Common_EventScript_Alpha_Inteleon_4:
# 2212 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2213 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2214 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2215 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Inteleon_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Inteleon_1

Common_EventScript_Alpha_Inteleon_6:
# 2206 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Inteleon_Text_0, MSGBOX_DEFAULT
# 2207 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_INTELEONITE, 1
	goto Common_EventScript_Alpha_Inteleon_5


Common_Eventscript_Enable_Alphas_Chimecho::
# 2223 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2224 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_CHIMECHO_MEGA_STONE, Common_Eventscript_Enable_Alphas_Chimecho_1
	return

Common_Eventscript_Enable_Alphas_Chimecho_1:
# 2225 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Chimecho::
# 2230 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2231 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2232 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2233 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_CHIMECHO, 2
# 2234 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_CHIMECHO, LEVEL_SCALE_WILD_BOSS, ITEM_CHIMECHITE
# 2235 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2236 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2237 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2238 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2239 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2240 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Chimecho_3
# 2241 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Chimecho_3
# 2252 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Chimecho_4
# 2253 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Chimecho_4
Common_EventScript_Alpha_Chimecho_1:
# 2260 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Chimecho_3:
# 2242 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_CHIMECHO_MEGA_STONE
# 2243 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2244 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2245 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2246 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2247 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Chimecho_6
Common_EventScript_Alpha_Chimecho_5:
	goto Common_EventScript_Alpha_Chimecho_1

Common_EventScript_Alpha_Chimecho_4:
# 2254 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2255 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2256 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2257 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Chimecho_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Chimecho_1

Common_EventScript_Alpha_Chimecho_6:
# 2248 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Chimecho_Text_0, MSGBOX_DEFAULT
# 2249 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_CHIMECHITE, 1
	goto Common_EventScript_Alpha_Chimecho_5


Common_Eventscript_Enable_Alphas_Staraptor::
# 2265 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2266 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_STARAPTOR_MEGA_STONE, Common_Eventscript_Enable_Alphas_Staraptor_1
	return

Common_Eventscript_Enable_Alphas_Staraptor_1:
# 2267 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Staraptor::
# 2272 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2273 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2274 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2275 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_STARAPTOR, 2
# 2276 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_STARAPTOR, LEVEL_SCALE_WILD_BOSS, ITEM_STARAPTORITE
# 2277 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2278 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2279 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2280 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2281 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2282 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Staraptor_3
# 2283 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Staraptor_3
# 2294 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Staraptor_4
# 2295 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Staraptor_4
Common_EventScript_Alpha_Staraptor_1:
# 2302 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Staraptor_3:
# 2284 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_STARAPTOR_MEGA_STONE
# 2285 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2286 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2287 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2288 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2289 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Staraptor_6
Common_EventScript_Alpha_Staraptor_5:
	goto Common_EventScript_Alpha_Staraptor_1

Common_EventScript_Alpha_Staraptor_4:
# 2296 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2297 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2298 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2299 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Staraptor_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Staraptor_1

Common_EventScript_Alpha_Staraptor_6:
# 2290 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Staraptor_Text_0, MSGBOX_DEFAULT
# 2291 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_STARAPTORITE, 1
	goto Common_EventScript_Alpha_Staraptor_5


Common_Eventscript_Enable_Alphas_Golurk::
# 2307 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2308 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_GOLURK_MEGA_STONE, Common_Eventscript_Enable_Alphas_Golurk_1
	return

Common_Eventscript_Enable_Alphas_Golurk_1:
# 2309 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Golurk::
# 2314 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2315 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2316 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2317 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_GOLURK, 2
# 2318 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_GOLURK, LEVEL_SCALE_WILD_BOSS, ITEM_GOLURKITE
# 2319 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2320 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2321 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2322 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2323 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2324 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Golurk_3
# 2325 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Golurk_3
# 2336 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Golurk_4
# 2337 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Golurk_4
Common_EventScript_Alpha_Golurk_1:
# 2344 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Golurk_3:
# 2326 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_GOLURK_MEGA_STONE
# 2327 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2328 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2329 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2330 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2331 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Golurk_6
Common_EventScript_Alpha_Golurk_5:
	goto Common_EventScript_Alpha_Golurk_1

Common_EventScript_Alpha_Golurk_4:
# 2338 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2339 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2340 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2341 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Golurk_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Golurk_1

Common_EventScript_Alpha_Golurk_6:
# 2332 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Golurk_Text_0, MSGBOX_DEFAULT
# 2333 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_GOLURKITE, 1
	goto Common_EventScript_Alpha_Golurk_5


Common_Eventscript_Enable_Alphas_Crabominable::
# 2349 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2350 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_CRABOMINABLE_MEGA_STONE, Common_Eventscript_Enable_Alphas_Crabominable_1
	return

Common_Eventscript_Enable_Alphas_Crabominable_1:
# 2351 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Crabominable::
# 2356 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2357 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2358 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2359 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_CRABOMINABLE, 2
# 2360 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_CRABOMINABLE, LEVEL_SCALE_WILD_BOSS, ITEM_CRABOMINABLITE
# 2361 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2362 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2363 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2364 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2365 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2366 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Crabominable_3
# 2367 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Crabominable_3
# 2378 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Crabominable_4
# 2379 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Crabominable_4
Common_EventScript_Alpha_Crabominable_1:
# 2386 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Crabominable_3:
# 2368 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_CRABOMINABLE_MEGA_STONE
# 2369 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2370 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2371 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2372 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2373 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Crabominable_6
Common_EventScript_Alpha_Crabominable_5:
	goto Common_EventScript_Alpha_Crabominable_1

Common_EventScript_Alpha_Crabominable_4:
# 2380 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2381 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2382 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2383 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Crabominable_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Crabominable_1

Common_EventScript_Alpha_Crabominable_6:
# 2374 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Crabominable_Text_0, MSGBOX_DEFAULT
# 2375 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_CRABOMINABLITE, 1
	goto Common_EventScript_Alpha_Crabominable_5


Common_Eventscript_Enable_Alphas_Golisopod::
# 2391 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2392 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_GOLISOPOD_MEGA_STONE, Common_Eventscript_Enable_Alphas_Golisopod_1
	return

Common_Eventscript_Enable_Alphas_Golisopod_1:
# 2393 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Golisopod::
# 2398 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2399 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2400 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2401 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_GOLISOPOD, 2
# 2402 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_GOLISOPOD, LEVEL_SCALE_WILD_BOSS, ITEM_GOLISPODITE
# 2403 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2404 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2405 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2406 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2407 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2408 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Golisopod_3
# 2409 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Golisopod_3
# 2420 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Golisopod_4
# 2421 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Golisopod_4
Common_EventScript_Alpha_Golisopod_1:
# 2428 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Golisopod_3:
# 2410 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_GOLISOPOD_MEGA_STONE
# 2411 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2412 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2413 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2414 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2415 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Golisopod_6
Common_EventScript_Alpha_Golisopod_5:
	goto Common_EventScript_Alpha_Golisopod_1

Common_EventScript_Alpha_Golisopod_4:
# 2422 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2423 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2424 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2425 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Golisopod_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Golisopod_1

Common_EventScript_Alpha_Golisopod_6:
# 2416 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Golisopod_Text_0, MSGBOX_DEFAULT
# 2417 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_GOLISPODITE, 1
	goto Common_EventScript_Alpha_Golisopod_5


Common_Eventscript_Enable_Alphas_Magearna::
# 2433 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2434 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_MAGEARNA_MEGA_STONE, Common_Eventscript_Enable_Alphas_Magearna_1
	return

Common_Eventscript_Enable_Alphas_Magearna_1:
# 2435 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Magearna::
# 2440 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2441 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2442 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2443 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_MAGEARNA, 2
# 2444 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_MAGEARNA, LEVEL_SCALE_WILD_BOSS, ITEM_MAGEARNITE
# 2445 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2446 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2447 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2448 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2449 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2450 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Magearna_3
# 2451 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Magearna_3
# 2462 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Magearna_4
# 2463 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Magearna_4
Common_EventScript_Alpha_Magearna_1:
# 2470 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Magearna_3:
# 2452 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_MAGEARNA_MEGA_STONE
# 2453 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2454 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2455 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2456 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2457 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Magearna_6
Common_EventScript_Alpha_Magearna_5:
	goto Common_EventScript_Alpha_Magearna_1

Common_EventScript_Alpha_Magearna_4:
# 2464 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2465 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2466 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2467 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Magearna_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Magearna_1

Common_EventScript_Alpha_Magearna_6:
# 2458 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Magearna_Text_0, MSGBOX_DEFAULT
# 2459 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_MAGEARNITE, 1
	goto Common_EventScript_Alpha_Magearna_5


Common_Eventscript_Enable_Alphas_Scovillain::
# 2475 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2476 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_SCOVILLAIN_MEGA_STONE, Common_Eventscript_Enable_Alphas_Scovillain_1
	return

Common_Eventscript_Enable_Alphas_Scovillain_1:
# 2477 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Scovillain::
# 2482 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2483 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2484 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2485 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_SCOVILLAIN, 2
# 2486 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_SCOVILLAIN, LEVEL_SCALE_WILD_BOSS, ITEM_SCOVILLAINITE
# 2487 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2488 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2489 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2490 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2491 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2492 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Scovillain_3
# 2493 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Scovillain_3
# 2504 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Scovillain_4
# 2505 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Scovillain_4
Common_EventScript_Alpha_Scovillain_1:
# 2512 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Scovillain_3:
# 2494 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_SCOVILLAIN_MEGA_STONE
# 2495 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2496 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2497 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2498 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2499 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Scovillain_6
Common_EventScript_Alpha_Scovillain_5:
	goto Common_EventScript_Alpha_Scovillain_1

Common_EventScript_Alpha_Scovillain_4:
# 2506 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2507 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2508 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2509 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Scovillain_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Scovillain_1

Common_EventScript_Alpha_Scovillain_6:
# 2500 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Scovillain_Text_0, MSGBOX_DEFAULT
# 2501 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_SCOVILLAINITE, 1
	goto Common_EventScript_Alpha_Scovillain_5


Common_Eventscript_Enable_Alphas_Glimmora::
# 2517 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2518 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_GLIMMORA_MEGA_STONE, Common_Eventscript_Enable_Alphas_Glimmora_1
	return

Common_Eventscript_Enable_Alphas_Glimmora_1:
# 2519 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Glimmora::
# 2524 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2525 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2526 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2527 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_GLIMMORA, 2
# 2528 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_GLIMMORA, LEVEL_SCALE_WILD_BOSS, ITEM_GLIMMORITE
# 2529 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2530 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2531 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2532 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2533 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2534 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Glimmora_3
# 2535 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Glimmora_3
# 2546 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Glimmora_4
# 2547 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Glimmora_4
Common_EventScript_Alpha_Glimmora_1:
# 2554 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Glimmora_3:
# 2536 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_GLIMMORA_MEGA_STONE
# 2537 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2538 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2539 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2540 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2541 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Glimmora_6
Common_EventScript_Alpha_Glimmora_5:
	goto Common_EventScript_Alpha_Glimmora_1

Common_EventScript_Alpha_Glimmora_4:
# 2548 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2549 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2550 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2551 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Glimmora_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Glimmora_1

Common_EventScript_Alpha_Glimmora_6:
# 2542 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Glimmora_Text_0, MSGBOX_DEFAULT
# 2543 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_GLIMMORITE, 1
	goto Common_EventScript_Alpha_Glimmora_5


Common_Eventscript_Enable_Alphas_Baxcalibur::
# 2559 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2560 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_BAXCALIBUR_MEGA_STONE, Common_Eventscript_Enable_Alphas_Baxcalibur_1
	return

Common_Eventscript_Enable_Alphas_Baxcalibur_1:
# 2561 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Baxcalibur::
# 2566 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2567 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2568 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2569 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_BAXCALIBUR, 2
# 2570 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_BAXCALIBUR, LEVEL_SCALE_WILD_BOSS, ITEM_BAXCALIBURITE
# 2571 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2572 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2573 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2574 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2575 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2576 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Baxcalibur_3
# 2577 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Baxcalibur_3
# 2588 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Baxcalibur_4
# 2589 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Baxcalibur_4
Common_EventScript_Alpha_Baxcalibur_1:
# 2596 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Baxcalibur_3:
# 2578 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_BAXCALIBUR_MEGA_STONE
# 2579 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2580 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2581 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2582 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2583 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Baxcalibur_6
Common_EventScript_Alpha_Baxcalibur_5:
	goto Common_EventScript_Alpha_Baxcalibur_1

Common_EventScript_Alpha_Baxcalibur_4:
# 2590 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2591 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2592 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2593 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Baxcalibur_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Baxcalibur_1

Common_EventScript_Alpha_Baxcalibur_6:
# 2584 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Baxcalibur_Text_0, MSGBOX_DEFAULT
# 2585 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_BAXCALIBURITE, 1
	goto Common_EventScript_Alpha_Baxcalibur_5


Common_Eventscript_Enable_Alphas_Zeraora::
# 2601 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2602 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_ZERAORA_MEGA_STONE, Common_Eventscript_Enable_Alphas_Zeraora_1
	return

Common_Eventscript_Enable_Alphas_Zeraora_1:
# 2603 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Zeraora::
# 2608 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2609 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2610 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2611 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_ZERAORA, 2
# 2612 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_ZERAORA, LEVEL_SCALE_WILD_BOSS, ITEM_ZERAORANITE
# 2613 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2614 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2615 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2616 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2617 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2618 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Zeraora_3
# 2619 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Zeraora_3
# 2630 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Zeraora_4
# 2631 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Zeraora_4
Common_EventScript_Alpha_Zeraora_1:
# 2638 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Zeraora_3:
# 2620 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_ZERAORA_MEGA_STONE
# 2621 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2622 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2623 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2624 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2625 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Zeraora_6
Common_EventScript_Alpha_Zeraora_5:
	goto Common_EventScript_Alpha_Zeraora_1

Common_EventScript_Alpha_Zeraora_4:
# 2632 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2633 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2634 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2635 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Zeraora_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Zeraora_1

Common_EventScript_Alpha_Zeraora_6:
# 2626 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Zeraora_Text_0, MSGBOX_DEFAULT
# 2627 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_ZERAORANITE, 1
	goto Common_EventScript_Alpha_Zeraora_5


Common_Eventscript_Enable_Alphas_Arbok::
# 2643 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2644 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_ARBOK_MEGA_STONE, Common_Eventscript_Enable_Alphas_Arbok_1
	return

Common_Eventscript_Enable_Alphas_Arbok_1:
# 2645 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Arbok::
# 2650 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2651 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2652 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2653 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_ARBOK, 2
# 2654 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_ARBOK, LEVEL_SCALE_WILD_BOSS, ITEM_ARBOKITE
# 2655 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2656 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2657 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2658 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2659 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2660 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Arbok_3
# 2661 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Arbok_3
# 2672 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Arbok_4
# 2673 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Arbok_4
Common_EventScript_Alpha_Arbok_1:
# 2680 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Arbok_3:
# 2662 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_ARBOK_MEGA_STONE
# 2663 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2664 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2665 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2666 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2667 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Arbok_6
Common_EventScript_Alpha_Arbok_5:
	goto Common_EventScript_Alpha_Arbok_1

Common_EventScript_Alpha_Arbok_4:
# 2674 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2675 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2676 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2677 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Arbok_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Arbok_1

Common_EventScript_Alpha_Arbok_6:
# 2668 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Arbok_Text_0, MSGBOX_DEFAULT
# 2669 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_ARBOKITE, 1
	goto Common_EventScript_Alpha_Arbok_5


Common_Eventscript_Enable_Alphas_Toxtricity::
# 2685 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2686 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_TOXTRICITY_MEGA_STONE, Common_Eventscript_Enable_Alphas_Toxtricity_1
	return

Common_Eventscript_Enable_Alphas_Toxtricity_1:
# 2687 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Toxtricity::
# 2692 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2693 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2694 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2695 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_TOXTRICITY, 2
# 2696 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_TOXTRICITY, LEVEL_SCALE_WILD_BOSS, ITEM_TOXTRICITITE
# 2697 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2698 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2699 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2700 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2701 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2702 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Toxtricity_3
# 2703 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Toxtricity_3
# 2714 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Toxtricity_4
# 2715 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Toxtricity_4
Common_EventScript_Alpha_Toxtricity_1:
# 2722 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Toxtricity_3:
# 2704 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_TOXTRICITY_MEGA_STONE
# 2705 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2706 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2707 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2708 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2709 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Toxtricity_6
Common_EventScript_Alpha_Toxtricity_5:
	goto Common_EventScript_Alpha_Toxtricity_1

Common_EventScript_Alpha_Toxtricity_4:
# 2716 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2717 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2718 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2719 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Toxtricity_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Toxtricity_1

Common_EventScript_Alpha_Toxtricity_6:
# 2710 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Toxtricity_Text_0, MSGBOX_DEFAULT
# 2711 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_TOXTRICITITE, 1
	goto Common_EventScript_Alpha_Toxtricity_5


Common_Eventscript_Enable_Alphas_Urshifu::
# 2727 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2728 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_URSHIFU_MEGA_STONE, Common_Eventscript_Enable_Alphas_Urshifu_1
	return

Common_Eventscript_Enable_Alphas_Urshifu_1:
# 2729 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Urshifu::
# 2734 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2735 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2736 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2737 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_URSHIFU, 2
# 2738 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_URSHIFU, LEVEL_SCALE_WILD_BOSS, ITEM_URISHIFUNITE
# 2739 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2740 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2741 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2742 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2743 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2744 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Urshifu_3
# 2745 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Urshifu_3
# 2756 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Urshifu_4
# 2757 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Urshifu_4
Common_EventScript_Alpha_Urshifu_1:
# 2764 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Urshifu_3:
# 2746 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_URSHIFU_MEGA_STONE
# 2747 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2748 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2749 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2750 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2751 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Urshifu_6
Common_EventScript_Alpha_Urshifu_5:
	goto Common_EventScript_Alpha_Urshifu_1

Common_EventScript_Alpha_Urshifu_4:
# 2758 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2759 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2760 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2761 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Urshifu_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Urshifu_1

Common_EventScript_Alpha_Urshifu_6:
# 2752 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Urshifu_Text_0, MSGBOX_DEFAULT
# 2753 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_URISHIFUNITE, 1
	goto Common_EventScript_Alpha_Urshifu_5


Common_Eventscript_Enable_Alphas_Meowstic::
# 2769 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2770 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_MEOWSTIC_MEGA_STONE, Common_Eventscript_Enable_Alphas_Meowstic_1
	return

Common_Eventscript_Enable_Alphas_Meowstic_1:
# 2771 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Meowstic::
# 2776 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2777 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2778 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2779 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_MEOWSTIC, 2
# 2780 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_MEOWSTIC, LEVEL_SCALE_WILD_BOSS, ITEM_MEOWSTITE
# 2781 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2782 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2783 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2784 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2785 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2786 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Meowstic_3
# 2787 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Meowstic_3
# 2798 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Meowstic_4
# 2799 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Meowstic_4
Common_EventScript_Alpha_Meowstic_1:
# 2806 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Meowstic_3:
# 2788 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_MEOWSTIC_MEGA_STONE
# 2789 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2790 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2791 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2792 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2793 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Meowstic_6
Common_EventScript_Alpha_Meowstic_5:
	goto Common_EventScript_Alpha_Meowstic_1

Common_EventScript_Alpha_Meowstic_4:
# 2800 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2801 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2802 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2803 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Meowstic_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Meowstic_1

Common_EventScript_Alpha_Meowstic_6:
# 2794 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Meowstic_Text_0, MSGBOX_DEFAULT
# 2795 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_MEOWSTITE, 1
	goto Common_EventScript_Alpha_Meowstic_5


Common_Eventscript_Enable_Alphas_Tatsugiri::
# 2811 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2812 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_TATSUGIRI_MEGA_STONE, Common_Eventscript_Enable_Alphas_Tatsugiri_1
	return

Common_Eventscript_Enable_Alphas_Tatsugiri_1:
# 2813 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Tatsugiri::
# 2818 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2819 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2820 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2821 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_TATSUGIRI, 2
# 2822 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_TATSUGIRI, LEVEL_SCALE_WILD_BOSS, ITEM_TATSIGIRITE
# 2823 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2824 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2825 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2826 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2827 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2828 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Tatsugiri_3
# 2829 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Tatsugiri_3
# 2840 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Tatsugiri_4
# 2841 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Tatsugiri_4
Common_EventScript_Alpha_Tatsugiri_1:
# 2848 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Tatsugiri_3:
# 2830 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_TATSUGIRI_MEGA_STONE
# 2831 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2832 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2833 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2834 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2835 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Tatsugiri_6
Common_EventScript_Alpha_Tatsugiri_5:
	goto Common_EventScript_Alpha_Tatsugiri_1

Common_EventScript_Alpha_Tatsugiri_4:
# 2842 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2843 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2844 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2845 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Tatsugiri_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Tatsugiri_1

Common_EventScript_Alpha_Tatsugiri_6:
# 2836 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Tatsugiri_Text_0, MSGBOX_DEFAULT
# 2837 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_TATSIGIRITE, 1
	goto Common_EventScript_Alpha_Tatsugiri_5


Common_Eventscript_Enable_Alphas_Darkrai::
# 2853 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2854 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_DARKRAI_MEGA_STONE, Common_Eventscript_Enable_Alphas_Darkrai_1
	return

Common_Eventscript_Enable_Alphas_Darkrai_1:
# 2855 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Darkrai::
# 2860 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2861 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2862 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2863 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_DARKRAI, 2
# 2864 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_DARKRAI, LEVEL_SCALE_WILD_BOSS, ITEM_DARKRAITE
# 2865 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2866 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2867 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2868 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2869 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2870 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Darkrai_3
# 2871 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Darkrai_3
# 2882 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Darkrai_4
# 2883 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Darkrai_4
Common_EventScript_Alpha_Darkrai_1:
# 2890 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Darkrai_3:
# 2872 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_DARKRAI_MEGA_STONE
# 2873 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2874 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2875 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2876 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2877 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Darkrai_6
Common_EventScript_Alpha_Darkrai_5:
	goto Common_EventScript_Alpha_Darkrai_1

Common_EventScript_Alpha_Darkrai_4:
# 2884 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2885 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2886 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2887 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Darkrai_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Darkrai_1

Common_EventScript_Alpha_Darkrai_6:
# 2878 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Darkrai_Text_0, MSGBOX_DEFAULT
# 2879 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_DARKRAITE, 1
	goto Common_EventScript_Alpha_Darkrai_5


Common_Eventscript_Enable_Alphas_Floette_Eternal::
# 2895 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2896 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_FLOETTE_ETERNAL_MEGA_STONE, Common_Eventscript_Enable_Alphas_Floette_Eternal_1
	return

Common_Eventscript_Enable_Alphas_Floette_Eternal_1:
# 2897 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Floette_Eternal::
# 2902 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2903 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2904 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2905 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_FLOETTE, 2
# 2906 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_FLOETTE, LEVEL_SCALE_WILD_BOSS, ITEM_FLOETTITE
# 2907 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2908 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2909 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2910 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2911 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2912 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Floette_Eternal_3
# 2913 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Floette_Eternal_3
# 2924 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Floette_Eternal_4
# 2925 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Floette_Eternal_4
Common_EventScript_Alpha_Floette_Eternal_1:
# 2932 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Floette_Eternal_3:
# 2914 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_FLOETTE_ETERNAL_MEGA_STONE
# 2915 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2916 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2917 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2918 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2919 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Floette_Eternal_6
Common_EventScript_Alpha_Floette_Eternal_5:
	goto Common_EventScript_Alpha_Floette_Eternal_1

Common_EventScript_Alpha_Floette_Eternal_4:
# 2926 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2927 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2928 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2929 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Floette_Eternal_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Floette_Eternal_1

Common_EventScript_Alpha_Floette_Eternal_6:
# 2920 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Floette_Eternal_Text_0, MSGBOX_DEFAULT
# 2921 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_FLOETTITE, 1
	goto Common_EventScript_Alpha_Floette_Eternal_5


Common_Eventscript_Enable_Alphas_Clefable_R::
# 2937 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2938 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_CLEFABLE_R_MEGA_STONE, Common_Eventscript_Enable_Alphas_Clefable_R_1
	return

Common_Eventscript_Enable_Alphas_Clefable_R_1:
# 2939 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Clefable_R::
# 2944 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2945 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2946 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2947 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_CLEFABLE, 2
# 2948 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_CLEFABLE, LEVEL_SCALE_WILD_BOSS, ITEM_CLEFABLITE_R
# 2949 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2950 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2951 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2952 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2953 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2954 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Clefable_R_3
# 2955 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Clefable_R_3
# 2966 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Clefable_R_4
# 2967 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Clefable_R_4
Common_EventScript_Alpha_Clefable_R_1:
# 2974 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Clefable_R_3:
# 2956 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_CLEFABLE_R_MEGA_STONE
# 2957 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 2958 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2959 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2960 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2961 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Clefable_R_6
Common_EventScript_Alpha_Clefable_R_5:
	goto Common_EventScript_Alpha_Clefable_R_1

Common_EventScript_Alpha_Clefable_R_4:
# 2968 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 2969 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 2970 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 2971 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Clefable_R_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Clefable_R_1

Common_EventScript_Alpha_Clefable_R_6:
# 2962 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Clefable_R_Text_0, MSGBOX_DEFAULT
# 2963 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_CLEFABLITE_R, 1
	goto Common_EventScript_Alpha_Clefable_R_5


Common_Eventscript_Enable_Alphas_Starmie_R::
# 2979 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 2980 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_STARMIE_R_MEGA_STONE, Common_Eventscript_Enable_Alphas_Starmie_R_1
	return

Common_Eventscript_Enable_Alphas_Starmie_R_1:
# 2981 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Starmie_R::
# 2986 "data/scripts/alpha_mon_scripts.pory"
	lock
# 2987 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 2988 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 2989 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_STARMIE, 2
# 2990 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_STARMIE, LEVEL_SCALE_WILD_BOSS, ITEM_STARMINITE_R
# 2991 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 2992 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 2993 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 2994 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 2995 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 2996 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Starmie_R_3
# 2997 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Starmie_R_3
# 3008 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Starmie_R_4
# 3009 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Starmie_R_4
Common_EventScript_Alpha_Starmie_R_1:
# 3016 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Starmie_R_3:
# 2998 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_STARMIE_R_MEGA_STONE
# 2999 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 3000 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 3001 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 3002 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 3003 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Starmie_R_6
Common_EventScript_Alpha_Starmie_R_5:
	goto Common_EventScript_Alpha_Starmie_R_1

Common_EventScript_Alpha_Starmie_R_4:
# 3010 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 3011 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 3012 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 3013 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Starmie_R_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Starmie_R_1

Common_EventScript_Alpha_Starmie_R_6:
# 3004 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Starmie_R_Text_0, MSGBOX_DEFAULT
# 3005 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_STARMINITE_R, 1
	goto Common_EventScript_Alpha_Starmie_R_5


Common_Eventscript_Enable_Alphas_Absol_Z::
# 3021 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 3022 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_ABSOL_MEGA_STONE_Z, Common_Eventscript_Enable_Alphas_Absol_Z_1
	return

Common_Eventscript_Enable_Alphas_Absol_Z_1:
# 3023 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Absol_Z::
# 3028 "data/scripts/alpha_mon_scripts.pory"
	lock
# 3029 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 3030 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 3031 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_ABSOL, 2
# 3032 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_ABSOL, LEVEL_SCALE_WILD_BOSS, ITEM_ABSOLITE_Z
# 3033 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 3034 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 3035 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 3036 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 3037 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 3038 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Absol_Z_3
# 3039 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Absol_Z_3
# 3050 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Absol_Z_4
# 3051 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Absol_Z_4
Common_EventScript_Alpha_Absol_Z_1:
# 3058 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Absol_Z_3:
# 3040 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_ABSOL_MEGA_STONE_Z
# 3041 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 3042 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 3043 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 3044 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 3045 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Absol_Z_6
Common_EventScript_Alpha_Absol_Z_5:
	goto Common_EventScript_Alpha_Absol_Z_1

Common_EventScript_Alpha_Absol_Z_4:
# 3052 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 3053 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 3054 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 3055 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Absol_Z_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Absol_Z_1

Common_EventScript_Alpha_Absol_Z_6:
# 3046 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Absol_Z_Text_0, MSGBOX_DEFAULT
# 3047 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_ABSOLITE_Z, 1
	goto Common_EventScript_Alpha_Absol_Z_5


Common_Eventscript_Enable_Alphas_Lucario_Z::
# 3063 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 3064 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_LUCARIO_MEGA_STONE_Z, Common_Eventscript_Enable_Alphas_Lucario_Z_1
	return

Common_Eventscript_Enable_Alphas_Lucario_Z_1:
# 3065 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Lucario_Z::
# 3070 "data/scripts/alpha_mon_scripts.pory"
	lock
# 3071 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 3072 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 3073 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_LUCARIO, 2
# 3074 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_LUCARIO, LEVEL_SCALE_WILD_BOSS, ITEM_LUCARIONITE_Z
# 3075 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 3076 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 3077 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 3078 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 3079 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 3080 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Lucario_Z_3
# 3081 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Lucario_Z_3
# 3092 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Lucario_Z_4
# 3093 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Lucario_Z_4
Common_EventScript_Alpha_Lucario_Z_1:
# 3100 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Lucario_Z_3:
# 3082 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_LUCARIO_MEGA_STONE_Z
# 3083 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 3084 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 3085 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 3086 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 3087 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Lucario_Z_6
Common_EventScript_Alpha_Lucario_Z_5:
	goto Common_EventScript_Alpha_Lucario_Z_1

Common_EventScript_Alpha_Lucario_Z_4:
# 3094 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 3095 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 3096 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 3097 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Lucario_Z_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Lucario_Z_1

Common_EventScript_Alpha_Lucario_Z_6:
# 3088 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Lucario_Z_Text_0, MSGBOX_DEFAULT
# 3089 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_LUCARIONITE_Z, 1
	goto Common_EventScript_Alpha_Lucario_Z_5


Common_Eventscript_Enable_Alphas_Garchomp_Z::
# 3105 "data/scripts/alpha_mon_scripts.pory"
	call Common_Eventscript_Enable_Alphas
# 3106 "data/scripts/alpha_mon_scripts.pory"
	goto_if_set FLAG_GOT_GARCHOMP_MEGA_STONE_Z, Common_Eventscript_Enable_Alphas_Garchomp_Z_1
	return

Common_Eventscript_Enable_Alphas_Garchomp_Z_1:
# 3107 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
	return


Common_EventScript_Alpha_Garchomp_Z::
# 3112 "data/scripts/alpha_mon_scripts.pory"
	lock
# 3113 "data/scripts/alpha_mon_scripts.pory"
	faceplayer
# 3114 "data/scripts/alpha_mon_scripts.pory"
	call Common_EventScript_SetAlphaDefaultData
# 3115 "data/scripts/alpha_mon_scripts.pory"
	playmoncry SPECIES_GARCHOMP, 2
# 3116 "data/scripts/alpha_mon_scripts.pory"
	setwildbattle SPECIES_GARCHOMP, LEVEL_SCALE_WILD_BOSS, ITEM_GARCHOMPITE_Z
# 3117 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 3118 "data/scripts/alpha_mon_scripts.pory"
	dowildbattle
# 3119 "data/scripts/alpha_mon_scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 3120 "data/scripts/alpha_mon_scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 3121 "data/scripts/alpha_mon_scripts.pory"
	switch VAR_RESULT
# 3122 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_CAUGHT, Common_EventScript_Alpha_Garchomp_Z_3
# 3123 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_WON, Common_EventScript_Alpha_Garchomp_Z_3
# 3134 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_RAN, Common_EventScript_Alpha_Garchomp_Z_4
# 3135 "data/scripts/alpha_mon_scripts.pory"
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Alpha_Garchomp_Z_4
Common_EventScript_Alpha_Garchomp_Z_1:
# 3142 "data/scripts/alpha_mon_scripts.pory"
	release
	end

Common_EventScript_Alpha_Garchomp_Z_3:
# 3124 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_GOT_GARCHOMP_MEGA_STONE_Z
# 3125 "data/scripts/alpha_mon_scripts.pory"
	setflag FLAG_DISABLE_PORTALS
# 3126 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 3127 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 3128 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 3129 "data/scripts/alpha_mon_scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Common_EventScript_Alpha_Garchomp_Z_6
Common_EventScript_Alpha_Garchomp_Z_5:
	goto Common_EventScript_Alpha_Garchomp_Z_1

Common_EventScript_Alpha_Garchomp_Z_4:
# 3136 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 3137 "data/scripts/alpha_mon_scripts.pory"
	removeobject VAR_LAST_TALKED
# 3138 "data/scripts/alpha_mon_scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 3139 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Garchomp_Z_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Alpha_Garchomp_Z_1

Common_EventScript_Alpha_Garchomp_Z_6:
# 3130 "data/scripts/alpha_mon_scripts.pory"
	msgbox Common_EventScript_Alpha_Garchomp_Z_Text_0, MSGBOX_DEFAULT
# 3131 "data/scripts/alpha_mon_scripts.pory"
	giveitem ITEM_GARCHOMPITE_Z, 1
	goto Common_EventScript_Alpha_Garchomp_Z_5


Common_EventScript_Alpha_Clefable_Text_0:
# 48 "data/scripts/alpha_mon_scripts.pory"
	.string "Clefable teleported but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Clefable_Text_1:
# 60 "data/scripts/alpha_mon_scripts.pory"
	.string "Clefable teleported!$"

Common_EventScript_Alpha_Dragonite_Text_0:
# 94 "data/scripts/alpha_mon_scripts.pory"
	.string "Dragonite flew away but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Dragonite_Text_1:
# 106 "data/scripts/alpha_mon_scripts.pory"
	.string "Dragonite flew away!$"

Common_EventScript_Alpha_Starmie_Text_0:
# 140 "data/scripts/alpha_mon_scripts.pory"
	.string "Starmie teleported but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Starmie_Text_1:
# 152 "data/scripts/alpha_mon_scripts.pory"
	.string "Starmie teleported!$"

Common_EventScript_Alpha_Victreebel_Text_0:
# 186 "data/scripts/alpha_mon_scripts.pory"
	.string "Victreebel ran away but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Victreebel_Text_1:
# 198 "data/scripts/alpha_mon_scripts.pory"
	.string "Victreebel ran away!$"

Common_EventScript_Alpha_Excadrill_Text_0:
# 231 "data/scripts/alpha_mon_scripts.pory"
	.string "Excadrill dug out of the cave but\n"
	.string "something was left behind!$"

Common_EventScript_Alpha_Excadrill_Text_1:
# 240 "data/scripts/alpha_mon_scripts.pory"
	.string "Excadrill dug out of the cave!$"

Common_EventScript_Alpha_Froslass_Text_0:
# 273 "data/scripts/alpha_mon_scripts.pory"
	.string "Froslass escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Froslass_Text_1:
# 282 "data/scripts/alpha_mon_scripts.pory"
	.string "Froslass escaped!$"

Common_EventScript_Alpha_Scolipede_Text_0:
# 315 "data/scripts/alpha_mon_scripts.pory"
	.string "Scolipede escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Scolipede_Text_1:
# 324 "data/scripts/alpha_mon_scripts.pory"
	.string "Scolipede escaped!$"

Common_EventScript_Alpha_Skarmory_Text_0:
# 357 "data/scripts/alpha_mon_scripts.pory"
	.string "Skarmory flew away but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Skarmory_Text_1:
# 366 "data/scripts/alpha_mon_scripts.pory"
	.string "Skarmory flew away!$"

Common_EventScript_Alpha_Emboar_Text_0:
# 399 "data/scripts/alpha_mon_scripts.pory"
	.string "Emboar escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Emboar_Text_1:
# 408 "data/scripts/alpha_mon_scripts.pory"
	.string "Emboar escaped!$"

Common_EventScript_Alpha_Scrafty_Text_0:
# 441 "data/scripts/alpha_mon_scripts.pory"
	.string "Scrafty escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Scrafty_Text_1:
# 450 "data/scripts/alpha_mon_scripts.pory"
	.string "Scrafty escaped!$"

Common_EventScript_Alpha_Eelektross_Text_0:
# 483 "data/scripts/alpha_mon_scripts.pory"
	.string "Eelektross escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Eelektross_Text_1:
# 492 "data/scripts/alpha_mon_scripts.pory"
	.string "Eelektross escaped!$"

Common_EventScript_Alpha_Chandelure_Text_0:
# 525 "data/scripts/alpha_mon_scripts.pory"
	.string "Chandelure escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Chandelure_Text_1:
# 534 "data/scripts/alpha_mon_scripts.pory"
	.string "Chandelure escaped!$"

Common_EventScript_Alpha_Delphox_Text_0:
# 567 "data/scripts/alpha_mon_scripts.pory"
	.string "Delphox escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Delphox_Text_1:
# 576 "data/scripts/alpha_mon_scripts.pory"
	.string "Delphox escaped!$"

Common_EventScript_Alpha_Chesnaught_Text_0:
# 609 "data/scripts/alpha_mon_scripts.pory"
	.string "Chesnaught escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Chesnaught_Text_1:
# 618 "data/scripts/alpha_mon_scripts.pory"
	.string "Chesnaught escaped!$"

Common_EventScript_Alpha_Greninja_Text_0:
# 651 "data/scripts/alpha_mon_scripts.pory"
	.string "Greninja escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Greninja_Text_1:
# 660 "data/scripts/alpha_mon_scripts.pory"
	.string "Greninja escaped!$"

Common_EventScript_Alpha_Pyroar_Text_0:
# 693 "data/scripts/alpha_mon_scripts.pory"
	.string "Pyroar escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Pyroar_Text_1:
# 702 "data/scripts/alpha_mon_scripts.pory"
	.string "Pyroar escaped!$"

Common_EventScript_Alpha_Malamar_Text_0:
# 735 "data/scripts/alpha_mon_scripts.pory"
	.string "Malamar escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Malamar_Text_1:
# 744 "data/scripts/alpha_mon_scripts.pory"
	.string "Malamar escaped!$"

Common_EventScript_Alpha_Barbaracle_Text_0:
# 777 "data/scripts/alpha_mon_scripts.pory"
	.string "Barbaracle escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Barbaracle_Text_1:
# 786 "data/scripts/alpha_mon_scripts.pory"
	.string "Barbaracle escaped!$"

Common_EventScript_Alpha_Dragalge_Text_0:
# 819 "data/scripts/alpha_mon_scripts.pory"
	.string "Dragalge escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Dragalge_Text_1:
# 828 "data/scripts/alpha_mon_scripts.pory"
	.string "Dragalge escaped!$"

Common_EventScript_Alpha_Hawlucha_Text_0:
# 861 "data/scripts/alpha_mon_scripts.pory"
	.string "Hawlucha escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Hawlucha_Text_1:
# 870 "data/scripts/alpha_mon_scripts.pory"
	.string "Hawlucha escaped!$"

Common_EventScript_Alpha_Zygarde_Text_0:
# 903 "data/scripts/alpha_mon_scripts.pory"
	.string "Zygarde escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Zygarde_Text_1:
# 912 "data/scripts/alpha_mon_scripts.pory"
	.string "Zygarde escaped!$"

Common_EventScript_Alpha_Drampa_Text_0:
# 945 "data/scripts/alpha_mon_scripts.pory"
	.string "Drampa escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Drampa_Text_1:
# 954 "data/scripts/alpha_mon_scripts.pory"
	.string "Drampa escaped!$"

Common_EventScript_Alpha_Falinks_Text_0:
# 987 "data/scripts/alpha_mon_scripts.pory"
	.string "Falinks escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Falinks_Text_1:
# 996 "data/scripts/alpha_mon_scripts.pory"
	.string "Falinks escaped!$"

Common_EventScript_Alpha_Raichu_X_Text_0:
# 1029 "data/scripts/alpha_mon_scripts.pory"
	.string "Raichu X escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Raichu_X_Text_1:
# 1038 "data/scripts/alpha_mon_scripts.pory"
	.string "Raichu X escaped!$"

Common_EventScript_Alpha_Raichu_Y_Text_0:
# 1071 "data/scripts/alpha_mon_scripts.pory"
	.string "Raichu Y escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Raichu_Y_Text_1:
# 1080 "data/scripts/alpha_mon_scripts.pory"
	.string "Raichu Y escaped!$"

Common_EventScript_Alpha_Dewgong_Text_0:
# 1113 "data/scripts/alpha_mon_scripts.pory"
	.string "Dewgong escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Dewgong_Text_1:
# 1122 "data/scripts/alpha_mon_scripts.pory"
	.string "Dewgong escaped!$"

Common_EventScript_Alpha_Typhlosion_Text_0:
# 1155 "data/scripts/alpha_mon_scripts.pory"
	.string "Typhlosion escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Typhlosion_Text_1:
# 1164 "data/scripts/alpha_mon_scripts.pory"
	.string "Typhlosion escaped!$"

Common_EventScript_Alpha_Lanturn_Text_0:
# 1197 "data/scripts/alpha_mon_scripts.pory"
	.string "Lanturn escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Lanturn_Text_1:
# 1206 "data/scripts/alpha_mon_scripts.pory"
	.string "Lanturn escaped!$"

Common_EventScript_Alpha_Quagsire_Text_0:
# 1239 "data/scripts/alpha_mon_scripts.pory"
	.string "Quagsire escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Quagsire_Text_1:
# 1248 "data/scripts/alpha_mon_scripts.pory"
	.string "Quagsire escaped!$"

Common_EventScript_Alpha_Breloom_Text_0:
# 1281 "data/scripts/alpha_mon_scripts.pory"
	.string "Breloom escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Breloom_Text_1:
# 1290 "data/scripts/alpha_mon_scripts.pory"
	.string "Breloom escaped!$"

Common_EventScript_Alpha_Shedinja_Text_0:
# 1323 "data/scripts/alpha_mon_scripts.pory"
	.string "Shedinja escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Shedinja_Text_1:
# 1332 "data/scripts/alpha_mon_scripts.pory"
	.string "Shedinja escaped!$"

Common_EventScript_Alpha_Flygon_Text_0:
# 1350 "data/scripts/alpha_mon_scripts.pory"
	.string "Flygon: gon!$"

Common_EventScript_Alpha_Flygon_Text_1:
# 1366 "data/scripts/alpha_mon_scripts.pory"
	.string "Flygon escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Flygon_Text_2:
# 1375 "data/scripts/alpha_mon_scripts.pory"
	.string "Flygon escaped!$"

Common_EventScript_Alpha_Serperior_Text_0:
# 1408 "data/scripts/alpha_mon_scripts.pory"
	.string "Serperior escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Serperior_Text_1:
# 1417 "data/scripts/alpha_mon_scripts.pory"
	.string "Serperior escaped!$"

Common_EventScript_Alpha_Samurott_Text_0:
# 1450 "data/scripts/alpha_mon_scripts.pory"
	.string "Samurott escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Samurott_Text_1:
# 1459 "data/scripts/alpha_mon_scripts.pory"
	.string "Samurott escaped!$"

Common_EventScript_Alpha_Ribombee_Text_0:
# 1492 "data/scripts/alpha_mon_scripts.pory"
	.string "Ribombee escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Ribombee_Text_1:
# 1501 "data/scripts/alpha_mon_scripts.pory"
	.string "Ribombee escaped!$"

Common_EventScript_Alpha_Clodsire_Text_0:
# 1534 "data/scripts/alpha_mon_scripts.pory"
	.string "Clodsire escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Clodsire_Text_1:
# 1543 "data/scripts/alpha_mon_scripts.pory"
	.string "Clodsire escaped!$"

Common_EventScript_Alpha_Sandslash_Text_0:
# 1576 "data/scripts/alpha_mon_scripts.pory"
	.string "Sandslash escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Sandslash_Text_1:
# 1585 "data/scripts/alpha_mon_scripts.pory"
	.string "Sandslash escaped!$"

Common_EventScript_Alpha_Toucannon_Text_0:
# 1618 "data/scripts/alpha_mon_scripts.pory"
	.string "Toucannon escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Toucannon_Text_1:
# 1627 "data/scripts/alpha_mon_scripts.pory"
	.string "Toucannon escaped!$"

Common_EventScript_Alpha_Vanilluxe_Text_0:
# 1660 "data/scripts/alpha_mon_scripts.pory"
	.string "Vanilluxe escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Vanilluxe_Text_1:
# 1669 "data/scripts/alpha_mon_scripts.pory"
	.string "Vanilluxe escaped!$"

Common_EventScript_Alpha_Tinkaton_Text_0:
# 1702 "data/scripts/alpha_mon_scripts.pory"
	.string "Tinkaton escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Tinkaton_Text_1:
# 1711 "data/scripts/alpha_mon_scripts.pory"
	.string "Tinkaton escaped!$"

Common_EventScript_Alpha_Shuckle_Text_0:
# 1744 "data/scripts/alpha_mon_scripts.pory"
	.string "Shuckle escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Shuckle_Text_1:
# 1753 "data/scripts/alpha_mon_scripts.pory"
	.string "Shuckle escaped!$"

Common_EventScript_Alpha_Krookodile_Text_0:
# 1786 "data/scripts/alpha_mon_scripts.pory"
	.string "Krookodile escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Krookodile_Text_1:
# 1795 "data/scripts/alpha_mon_scripts.pory"
	.string "Krookodile escaped!$"

Common_EventScript_Alpha_Luxray_Text_0:
# 1828 "data/scripts/alpha_mon_scripts.pory"
	.string "Luxray escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Luxray_Text_1:
# 1837 "data/scripts/alpha_mon_scripts.pory"
	.string "Luxray escaped!$"

Common_EventScript_Alpha_Milotic_Text_0:
# 1870 "data/scripts/alpha_mon_scripts.pory"
	.string "Milotic escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Milotic_Text_1:
# 1879 "data/scripts/alpha_mon_scripts.pory"
	.string "Milotic escaped!$"

Common_EventScript_Alpha_Tsareena_Text_0:
# 1912 "data/scripts/alpha_mon_scripts.pory"
	.string "Tsareena escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Tsareena_Text_1:
# 1921 "data/scripts/alpha_mon_scripts.pory"
	.string "Tsareena escaped!$"

Common_EventScript_Alpha_Crobat_Text_0:
# 1954 "data/scripts/alpha_mon_scripts.pory"
	.string "Crobat escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Crobat_Text_1:
# 1963 "data/scripts/alpha_mon_scripts.pory"
	.string "Crobat escaped!$"

Common_EventScript_Alpha_Slowking_Text_0:
# 1996 "data/scripts/alpha_mon_scripts.pory"
	.string "Slowking escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Slowking_Text_1:
# 2005 "data/scripts/alpha_mon_scripts.pory"
	.string "Slowking escaped!$"

Common_EventScript_Alpha_Grimmsnarl_Text_0:
# 2038 "data/scripts/alpha_mon_scripts.pory"
	.string "Grimmsnarl escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Grimmsnarl_Text_1:
# 2047 "data/scripts/alpha_mon_scripts.pory"
	.string "Grimmsnarl escaped!$"

Common_EventScript_Alpha_Melmetal_Text_0:
# 2080 "data/scripts/alpha_mon_scripts.pory"
	.string "Melmetal escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Melmetal_Text_1:
# 2089 "data/scripts/alpha_mon_scripts.pory"
	.string "Melmetal escaped!$"

Common_EventScript_Alpha_Rillaboom_Text_0:
# 2122 "data/scripts/alpha_mon_scripts.pory"
	.string "Rillaboom escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Rillaboom_Text_1:
# 2131 "data/scripts/alpha_mon_scripts.pory"
	.string "Rillaboom escaped!$"

Common_EventScript_Alpha_Cinderace_Text_0:
# 2164 "data/scripts/alpha_mon_scripts.pory"
	.string "Cinderace escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Cinderace_Text_1:
# 2173 "data/scripts/alpha_mon_scripts.pory"
	.string "Cinderace escaped!$"

Common_EventScript_Alpha_Inteleon_Text_0:
# 2206 "data/scripts/alpha_mon_scripts.pory"
	.string "Inteleon escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Inteleon_Text_1:
# 2215 "data/scripts/alpha_mon_scripts.pory"
	.string "Inteleon escaped!$"

Common_EventScript_Alpha_Chimecho_Text_0:
# 2248 "data/scripts/alpha_mon_scripts.pory"
	.string "Chimecho escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Chimecho_Text_1:
# 2257 "data/scripts/alpha_mon_scripts.pory"
	.string "Chimecho escaped!$"

Common_EventScript_Alpha_Staraptor_Text_0:
# 2290 "data/scripts/alpha_mon_scripts.pory"
	.string "Staraptor escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Staraptor_Text_1:
# 2299 "data/scripts/alpha_mon_scripts.pory"
	.string "Staraptor escaped!$"

Common_EventScript_Alpha_Golurk_Text_0:
# 2332 "data/scripts/alpha_mon_scripts.pory"
	.string "Golurk escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Golurk_Text_1:
# 2341 "data/scripts/alpha_mon_scripts.pory"
	.string "Golurk escaped!$"

Common_EventScript_Alpha_Crabominable_Text_0:
# 2374 "data/scripts/alpha_mon_scripts.pory"
	.string "Crabominable escaped but something\n"
	.string "was left behind!$"

Common_EventScript_Alpha_Crabominable_Text_1:
# 2383 "data/scripts/alpha_mon_scripts.pory"
	.string "Crabominable escaped!$"

Common_EventScript_Alpha_Golisopod_Text_0:
# 2416 "data/scripts/alpha_mon_scripts.pory"
	.string "Golisopod escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Golisopod_Text_1:
# 2425 "data/scripts/alpha_mon_scripts.pory"
	.string "Golisopod escaped!$"

Common_EventScript_Alpha_Magearna_Text_0:
# 2458 "data/scripts/alpha_mon_scripts.pory"
	.string "Magearna escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Magearna_Text_1:
# 2467 "data/scripts/alpha_mon_scripts.pory"
	.string "Magearna escaped!$"

Common_EventScript_Alpha_Scovillain_Text_0:
# 2500 "data/scripts/alpha_mon_scripts.pory"
	.string "Scovillain escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Scovillain_Text_1:
# 2509 "data/scripts/alpha_mon_scripts.pory"
	.string "Scovillain escaped!$"

Common_EventScript_Alpha_Glimmora_Text_0:
# 2542 "data/scripts/alpha_mon_scripts.pory"
	.string "Glimmora escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Glimmora_Text_1:
# 2551 "data/scripts/alpha_mon_scripts.pory"
	.string "Glimmora escaped!$"

Common_EventScript_Alpha_Baxcalibur_Text_0:
# 2584 "data/scripts/alpha_mon_scripts.pory"
	.string "Baxcalibur escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Baxcalibur_Text_1:
# 2593 "data/scripts/alpha_mon_scripts.pory"
	.string "Baxcalibur escaped!$"

Common_EventScript_Alpha_Zeraora_Text_0:
# 2626 "data/scripts/alpha_mon_scripts.pory"
	.string "Zeraora escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Zeraora_Text_1:
# 2635 "data/scripts/alpha_mon_scripts.pory"
	.string "Zeraora escaped!$"

Common_EventScript_Alpha_Arbok_Text_0:
# 2668 "data/scripts/alpha_mon_scripts.pory"
	.string "Arbok escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Arbok_Text_1:
# 2677 "data/scripts/alpha_mon_scripts.pory"
	.string "Arbok escaped!$"

Common_EventScript_Alpha_Toxtricity_Text_0:
# 2710 "data/scripts/alpha_mon_scripts.pory"
	.string "Toxtricity escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Toxtricity_Text_1:
# 2719 "data/scripts/alpha_mon_scripts.pory"
	.string "Toxtricity escaped!$"

Common_EventScript_Alpha_Urshifu_Text_0:
# 2752 "data/scripts/alpha_mon_scripts.pory"
	.string "Urshifu escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Urshifu_Text_1:
# 2761 "data/scripts/alpha_mon_scripts.pory"
	.string "Urshifu escaped!$"

Common_EventScript_Alpha_Meowstic_Text_0:
# 2794 "data/scripts/alpha_mon_scripts.pory"
	.string "Meowstic escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Meowstic_Text_1:
# 2803 "data/scripts/alpha_mon_scripts.pory"
	.string "Meowstic escaped!$"

Common_EventScript_Alpha_Tatsugiri_Text_0:
# 2836 "data/scripts/alpha_mon_scripts.pory"
	.string "Tatsugiri escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Tatsugiri_Text_1:
# 2845 "data/scripts/alpha_mon_scripts.pory"
	.string "Tatsugiri escaped!$"

Common_EventScript_Alpha_Darkrai_Text_0:
# 2878 "data/scripts/alpha_mon_scripts.pory"
	.string "Darkrai escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Darkrai_Text_1:
# 2887 "data/scripts/alpha_mon_scripts.pory"
	.string "Darkrai escaped!$"

Common_EventScript_Alpha_Floette_Eternal_Text_0:
# 2920 "data/scripts/alpha_mon_scripts.pory"
	.string "Floette escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Floette_Eternal_Text_1:
# 2929 "data/scripts/alpha_mon_scripts.pory"
	.string "Floette escaped!$"

Common_EventScript_Alpha_Clefable_R_Text_0:
# 2962 "data/scripts/alpha_mon_scripts.pory"
	.string "Clefable escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Clefable_R_Text_1:
# 2971 "data/scripts/alpha_mon_scripts.pory"
	.string "Clefable escaped!$"

Common_EventScript_Alpha_Starmie_R_Text_0:
# 3004 "data/scripts/alpha_mon_scripts.pory"
	.string "Starmie escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Starmie_R_Text_1:
# 3013 "data/scripts/alpha_mon_scripts.pory"
	.string "Starmie escaped!$"

Common_EventScript_Alpha_Absol_Z_Text_0:
# 3046 "data/scripts/alpha_mon_scripts.pory"
	.string "Absol escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Absol_Z_Text_1:
# 3055 "data/scripts/alpha_mon_scripts.pory"
	.string "Absol escaped!$"

Common_EventScript_Alpha_Lucario_Z_Text_0:
# 3088 "data/scripts/alpha_mon_scripts.pory"
	.string "Lucario escaped but something was left\n"
	.string "behind!$"

Common_EventScript_Alpha_Lucario_Z_Text_1:
# 3097 "data/scripts/alpha_mon_scripts.pory"
	.string "Lucario escaped!$"

Common_EventScript_Alpha_Garchomp_Z_Text_0:
# 3130 "data/scripts/alpha_mon_scripts.pory"
	.string "Garchomp escaped but something was\n"
	.string "left behind!$"

Common_EventScript_Alpha_Garchomp_Z_Text_1:
# 3139 "data/scripts/alpha_mon_scripts.pory"
	.string "Garchomp escaped!$"
