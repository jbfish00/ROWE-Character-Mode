Special_Gym_EventScript_Give_Item::
# 115 "data/scripts/gym_scripts.pory"
	setflag FLAG_GYM_ATTENDANT_CALL
# 116 "data/scripts/gym_scripts.pory"
	switch VAR_NUM_BADGES
# 117 "data/scripts/gym_scripts.pory"
	case 0, Special_Gym_EventScript_Give_Item_2
# 123 "data/scripts/gym_scripts.pory"
	case 1, Special_Gym_EventScript_Give_Item_3
# 129 "data/scripts/gym_scripts.pory"
	case 2, Special_Gym_EventScript_Give_Item_4
# 135 "data/scripts/gym_scripts.pory"
	case 3, Special_Gym_EventScript_Give_Item_5
# 141 "data/scripts/gym_scripts.pory"
	case 4, Special_Gym_EventScript_Give_Item_6
# 147 "data/scripts/gym_scripts.pory"
	case 5, Special_Gym_EventScript_Give_Item_7
# 153 "data/scripts/gym_scripts.pory"
	case 6, Special_Gym_EventScript_Give_Item_8
# 159 "data/scripts/gym_scripts.pory"
	case 7, Special_Gym_EventScript_Give_Item_9
# 165 "data/scripts/gym_scripts.pory"
	case 8, Special_Gym_EventScript_Give_Item_10
# 171 "data/scripts/gym_scripts.pory"
	case 9, Special_Gym_EventScript_Give_Item_11
# 177 "data/scripts/gym_scripts.pory"
	case 10, Special_Gym_EventScript_Give_Item_12
# 183 "data/scripts/gym_scripts.pory"
	case 11, Special_Gym_EventScript_Give_Item_13
# 189 "data/scripts/gym_scripts.pory"
	case 12, Special_Gym_EventScript_Give_Item_14
# 195 "data/scripts/gym_scripts.pory"
	case 13, Special_Gym_EventScript_Give_Item_15
# 201 "data/scripts/gym_scripts.pory"
	case 14, Special_Gym_EventScript_Give_Item_16
# 207 "data/scripts/gym_scripts.pory"
	case 15, Special_Gym_EventScript_Give_Item_17
	return

Special_Gym_EventScript_Give_Item_2:
# 118 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BADGE_01
# 119 "data/scripts/gym_scripts.pory"
	giveitem ITEM_AMULET_COIN
# 120 "data/scripts/gym_scripts.pory"
	msgbox Special_Gym_Text_Explain_Item_01, MSGBOX_DEFAULT
# 121 "data/scripts/gym_scripts.pory"
	setvar VAR_NUM_BADGES, 1
	return

Special_Gym_EventScript_Give_Item_3:
# 124 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BADGE_02
# 125 "data/scripts/gym_scripts.pory"
	giveitem ITEM_ITEMFINDER
# 126 "data/scripts/gym_scripts.pory"
	msgbox Special_Gym_Text_Explain_Item_02, MSGBOX_DEFAULT
# 127 "data/scripts/gym_scripts.pory"
	setvar VAR_NUM_BADGES, 2
	return

Special_Gym_EventScript_Give_Item_4:
# 130 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BADGE_03
# 131 "data/scripts/gym_scripts.pory"
	giveitem ITEM_GOOD_ROD
# 132 "data/scripts/gym_scripts.pory"
	msgbox Special_Gym_Text_Explain_Item_03, MSGBOX_DEFAULT
# 133 "data/scripts/gym_scripts.pory"
	setvar VAR_NUM_BADGES, 3
	return

Special_Gym_EventScript_Give_Item_5:
# 136 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BADGE_04
# 137 "data/scripts/gym_scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 138 "data/scripts/gym_scripts.pory"
	msgbox Special_Gym_Text_Explain_Item_04, MSGBOX_DEFAULT
# 139 "data/scripts/gym_scripts.pory"
	setvar VAR_NUM_BADGES, 4
	return

Special_Gym_EventScript_Give_Item_6:
# 142 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BADGE_05
# 143 "data/scripts/gym_scripts.pory"
	giveitem ITEM_CATCHING_CHARM
# 144 "data/scripts/gym_scripts.pory"
	msgbox Special_Gym_Text_Explain_Item_05, MSGBOX_DEFAULT
# 145 "data/scripts/gym_scripts.pory"
	setvar VAR_NUM_BADGES, 5
	return

Special_Gym_EventScript_Give_Item_7:
# 148 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BADGE_06
# 149 "data/scripts/gym_scripts.pory"
	giveitem ITEM_EXP_SHARE
# 150 "data/scripts/gym_scripts.pory"
	msgbox Special_Gym_Text_Explain_Item_06, MSGBOX_DEFAULT
# 151 "data/scripts/gym_scripts.pory"
	setvar VAR_NUM_BADGES, 6
	return

Special_Gym_EventScript_Give_Item_8:
# 154 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BADGE_07
# 155 "data/scripts/gym_scripts.pory"
	giveitem ITEM_MACHO_BRACE
# 156 "data/scripts/gym_scripts.pory"
	msgbox Special_Gym_Text_Explain_Item_07, MSGBOX_DEFAULT
# 157 "data/scripts/gym_scripts.pory"
	setvar VAR_NUM_BADGES, 7
	return

Special_Gym_EventScript_Give_Item_9:
# 160 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BADGE_08
# 161 "data/scripts/gym_scripts.pory"
	giveitem ITEM_SUPER_ROD
# 162 "data/scripts/gym_scripts.pory"
	msgbox Special_Gym_Text_Explain_Item_08, MSGBOX_DEFAULT
# 163 "data/scripts/gym_scripts.pory"
	setvar VAR_NUM_BADGES, 8
	return

Special_Gym_EventScript_Give_Item_10:
# 166 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BADGE_09
# 167 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FLY_CHARM
# 168 "data/scripts/gym_scripts.pory"
	msgbox Special_Gym_Text_Explain_Item_09, MSGBOX_DEFAULT
# 169 "data/scripts/gym_scripts.pory"
	setvar VAR_NUM_BADGES, 9
	return

Special_Gym_EventScript_Give_Item_11:
# 172 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BADGE_10
# 173 "data/scripts/gym_scripts.pory"
	giveitem ITEM_MASTER_BALL
# 174 "data/scripts/gym_scripts.pory"
	msgbox Special_Gym_Text_Explain_Item_10, MSGBOX_DEFAULT
# 175 "data/scripts/gym_scripts.pory"
	setvar VAR_NUM_BADGES, 10
	return

Special_Gym_EventScript_Give_Item_12:
# 178 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BADGE_11
# 179 "data/scripts/gym_scripts.pory"
	giveitem ITEM_MEGA_BRACELET
# 180 "data/scripts/gym_scripts.pory"
	msgbox Special_Gym_Text_Explain_Item_11, MSGBOX_DEFAULT
# 181 "data/scripts/gym_scripts.pory"
	setvar VAR_NUM_BADGES, 11
	return

Special_Gym_EventScript_Give_Item_13:
# 184 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BADGE_12
# 185 "data/scripts/gym_scripts.pory"
	giveitem ITEM_EXP_CHARM
# 186 "data/scripts/gym_scripts.pory"
	msgbox Special_Gym_Text_Explain_Item_12, MSGBOX_DEFAULT
# 187 "data/scripts/gym_scripts.pory"
	setvar VAR_NUM_BADGES, 12
	return

Special_Gym_EventScript_Give_Item_14:
# 190 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BADGE_13
# 191 "data/scripts/gym_scripts.pory"
	giveitem ITEM_OVAL_CHARM
# 192 "data/scripts/gym_scripts.pory"
	msgbox Special_Gym_Text_Explain_Item_13, MSGBOX_DEFAULT
# 193 "data/scripts/gym_scripts.pory"
	setvar VAR_NUM_BADGES, 13
	return

Special_Gym_EventScript_Give_Item_15:
# 196 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BADGE_14
# 197 "data/scripts/gym_scripts.pory"
	giveitem ITEM_ALPHA_CHARM
# 198 "data/scripts/gym_scripts.pory"
	msgbox Special_Gym_Text_Explain_Item_14, MSGBOX_DEFAULT
# 199 "data/scripts/gym_scripts.pory"
	setvar VAR_NUM_BADGES, 14
	return

Special_Gym_EventScript_Give_Item_16:
# 202 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BADGE_15
# 203 "data/scripts/gym_scripts.pory"
	giveitem ITEM_WONDER_CHARM
# 204 "data/scripts/gym_scripts.pory"
	msgbox Special_Gym_Text_Explain_Item_15, MSGBOX_DEFAULT
# 205 "data/scripts/gym_scripts.pory"
	setvar VAR_NUM_BADGES, 15
	return

Special_Gym_EventScript_Give_Item_17:
# 208 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BADGE_16
# 209 "data/scripts/gym_scripts.pory"
	giveitem ITEM_SHINY_CHARM
# 210 "data/scripts/gym_scripts.pory"
	msgbox Special_Gym_Text_Explain_Item_16, MSGBOX_DEFAULT
# 211 "data/scripts/gym_scripts.pory"
	setvar VAR_NUM_BADGES, 16
	return


EventScript_Gym_Attendant_Call::
# 217 "data/scripts/gym_scripts.pory"
	lockall
# 218 "data/scripts/gym_scripts.pory"
	switch VAR_NUM_BADGES
# 219 "data/scripts/gym_scripts.pory"
	case 1, EventScript_Gym_Attendant_Call_3
# 220 "data/scripts/gym_scripts.pory"
	case 2, EventScript_Gym_Attendant_Call_4
# 221 "data/scripts/gym_scripts.pory"
	case 3, EventScript_Gym_Attendant_Call_5
# 222 "data/scripts/gym_scripts.pory"
	case 4, EventScript_Gym_Attendant_Call_6
# 223 "data/scripts/gym_scripts.pory"
	case 5, EventScript_Gym_Attendant_Call_7
# 224 "data/scripts/gym_scripts.pory"
	case 6, EventScript_Gym_Attendant_Call_8
# 225 "data/scripts/gym_scripts.pory"
	case 7, EventScript_Gym_Attendant_Call_9
# 226 "data/scripts/gym_scripts.pory"
	case 8, EventScript_Gym_Attendant_Call_10
# 227 "data/scripts/gym_scripts.pory"
	case 9, EventScript_Gym_Attendant_Call_11
# 228 "data/scripts/gym_scripts.pory"
	case 10, EventScript_Gym_Attendant_Call_12
# 229 "data/scripts/gym_scripts.pory"
	case 11, EventScript_Gym_Attendant_Call_13
# 230 "data/scripts/gym_scripts.pory"
	case 12, EventScript_Gym_Attendant_Call_14
# 231 "data/scripts/gym_scripts.pory"
	case 13, EventScript_Gym_Attendant_Call_15
# 232 "data/scripts/gym_scripts.pory"
	case 14, EventScript_Gym_Attendant_Call_16
# 233 "data/scripts/gym_scripts.pory"
	case 15, EventScript_Gym_Attendant_Call_17
# 234 "data/scripts/gym_scripts.pory"
	case 16, EventScript_Gym_Attendant_Call_18
EventScript_Gym_Attendant_Call_1:
# 236 "data/scripts/gym_scripts.pory"
	waitmessage
# 237 "data/scripts/gym_scripts.pory"
	clearflag FLAG_GYM_ATTENDANT_CALL
# 238 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_ATTENDANT_STEP_COUNTER, 0
# 239 "data/scripts/gym_scripts.pory"
	releaseall
	end

EventScript_Gym_Attendant_Call_3:
# 219 "data/scripts/gym_scripts.pory"
	pokenavcall EventScript_Gym_Attendant_Call_Text_0
	goto EventScript_Gym_Attendant_Call_1

EventScript_Gym_Attendant_Call_4:
# 220 "data/scripts/gym_scripts.pory"
	pokenavcall EventScript_Gym_Attendant_Call_Text_1
	goto EventScript_Gym_Attendant_Call_1

EventScript_Gym_Attendant_Call_5:
# 221 "data/scripts/gym_scripts.pory"
	pokenavcall EventScript_Gym_Attendant_Call_Text_2
	goto EventScript_Gym_Attendant_Call_1

EventScript_Gym_Attendant_Call_6:
# 222 "data/scripts/gym_scripts.pory"
	pokenavcall EventScript_Gym_Attendant_Call_Text_3
	goto EventScript_Gym_Attendant_Call_1

EventScript_Gym_Attendant_Call_7:
# 223 "data/scripts/gym_scripts.pory"
	pokenavcall EventScript_Gym_Attendant_Call_Text_4
	goto EventScript_Gym_Attendant_Call_1

EventScript_Gym_Attendant_Call_8:
# 224 "data/scripts/gym_scripts.pory"
	pokenavcall EventScript_Gym_Attendant_Call_Text_5
	goto EventScript_Gym_Attendant_Call_1

EventScript_Gym_Attendant_Call_9:
# 225 "data/scripts/gym_scripts.pory"
	pokenavcall EventScript_Gym_Attendant_Call_Text_6
	goto EventScript_Gym_Attendant_Call_1

EventScript_Gym_Attendant_Call_10:
# 226 "data/scripts/gym_scripts.pory"
	pokenavcall EventScript_Gym_Attendant_Call_Text_7
	goto EventScript_Gym_Attendant_Call_1

EventScript_Gym_Attendant_Call_11:
# 227 "data/scripts/gym_scripts.pory"
	pokenavcall EventScript_Gym_Attendant_Call_Text_8
	goto EventScript_Gym_Attendant_Call_1

EventScript_Gym_Attendant_Call_12:
# 228 "data/scripts/gym_scripts.pory"
	pokenavcall EventScript_Gym_Attendant_Call_Text_9
	goto EventScript_Gym_Attendant_Call_1

EventScript_Gym_Attendant_Call_13:
# 229 "data/scripts/gym_scripts.pory"
	pokenavcall EventScript_Gym_Attendant_Call_Text_10
	goto EventScript_Gym_Attendant_Call_1

EventScript_Gym_Attendant_Call_14:
# 230 "data/scripts/gym_scripts.pory"
	pokenavcall EventScript_Gym_Attendant_Call_Text_11
	goto EventScript_Gym_Attendant_Call_1

EventScript_Gym_Attendant_Call_15:
# 231 "data/scripts/gym_scripts.pory"
	pokenavcall EventScript_Gym_Attendant_Call_Text_12
	goto EventScript_Gym_Attendant_Call_1

EventScript_Gym_Attendant_Call_16:
# 232 "data/scripts/gym_scripts.pory"
	pokenavcall EventScript_Gym_Attendant_Call_Text_13
	goto EventScript_Gym_Attendant_Call_1

EventScript_Gym_Attendant_Call_17:
# 233 "data/scripts/gym_scripts.pory"
	pokenavcall EventScript_Gym_Attendant_Call_Text_14
	goto EventScript_Gym_Attendant_Call_1

EventScript_Gym_Attendant_Call_18:
# 234 "data/scripts/gym_scripts.pory"
	pokenavcall EventScript_Gym_Attendant_Call_Text_15
	goto EventScript_Gym_Attendant_Call_1


Gym_EventScript_Reset_Rematches::
# 245 "data/scripts/gym_scripts.pory"
	clearflag FLAG_ROXANNE_REMATCH
# 246 "data/scripts/gym_scripts.pory"
	clearflag FLAG_BRAWLY_REMATCH
# 247 "data/scripts/gym_scripts.pory"
	clearflag FLAG_WATTSON_REMATCH
# 248 "data/scripts/gym_scripts.pory"
	clearflag FLAG_FLANNERY_REMATCH
# 249 "data/scripts/gym_scripts.pory"
	clearflag FLAG_NORMAN_REMATCH
# 250 "data/scripts/gym_scripts.pory"
	clearflag FLAG_WINONA_REMATCH
# 251 "data/scripts/gym_scripts.pory"
	clearflag FLAG_TATE_AND_LIZA_REMATCH
# 252 "data/scripts/gym_scripts.pory"
	clearflag FLAG_JUAN_REMATCH
# 254 "data/scripts/gym_scripts.pory"
	clearflag FLAG_FALKNER_REMATCH
# 255 "data/scripts/gym_scripts.pory"
	clearflag FLAG_BUGSY_REMATCH
# 256 "data/scripts/gym_scripts.pory"
	clearflag FLAG_WHITNEY_REMATCH
# 257 "data/scripts/gym_scripts.pory"
	clearflag FLAG_MORTY_REMATCH
# 258 "data/scripts/gym_scripts.pory"
	clearflag FLAG_CHUCK_REMATCH
# 259 "data/scripts/gym_scripts.pory"
	clearflag FLAG_JASMINE_REMATCH
# 260 "data/scripts/gym_scripts.pory"
	clearflag FLAG_PRYCE_REMATCH
# 261 "data/scripts/gym_scripts.pory"
	clearflag FLAG_CLAIR_REMATCH
	return


RustboroCity_Gym_EventScript_GymGuide_New::
# 266 "data/scripts/gym_scripts.pory"
	lock
# 267 "data/scripts/gym_scripts.pory"
	faceplayer
# 268 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuide_New_2
# 284 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_NPC
RustboroCity_Gym_EventScript_GymGuide_New_1:
# 286 "data/scripts/gym_scripts.pory"
	release
	end

RustboroCity_Gym_EventScript_GymGuide_New_2:
# 269 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_ROXANNE_REMATCH, RustboroCity_Gym_EventScript_GymGuide_New_5
# 280 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_NPC
	goto RustboroCity_Gym_EventScript_GymGuide_New_1

RustboroCity_Gym_EventScript_GymGuide_New_5:
# 270 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_0, MSGBOX_YESNO
# 271 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_Gym_EventScript_GymGuide_New_8
# 276 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_2, MSGBOX_NPC
	goto RustboroCity_Gym_EventScript_GymGuide_New_1

RustboroCity_Gym_EventScript_GymGuide_New_8:
# 272 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_1, MSGBOX_NPC
# 273 "data/scripts/gym_scripts.pory"
	warp MAP_RUSTBORO_CITY_GYM, 255, 5, 3
	goto RustboroCity_Gym_EventScript_GymGuide_New_1


RustboroCity_Gym_EventScript_Roxanne_New::
# 291 "data/scripts/gym_scripts.pory"
	lock
# 292 "data/scripts/gym_scripts.pory"
	faceplayer
# 293 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_Roxanne_New_8
RustboroCity_Gym_EventScript_Roxanne_New_6:
# 313 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_Roxanne_New_5
RustboroCity_Gym_EventScript_Roxanne_New_4:
# 331 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxanneIntro, MSGBOX_NPC
# 333 "data/scripts/gym_scripts.pory"
	call RustboroCity_Gym_EventScript_Roxanne_Battle_New
# 336 "data/scripts/gym_scripts.pory"
	message RustboroCity_Gym_EventScript_Roxanne_New_Text_4
# 337 "data/scripts/gym_scripts.pory"
	waitmessage
# 338 "data/scripts/gym_scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 339 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_5, MSGBOX_NPC
# 340 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 341 "data/scripts/gym_scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 342 "data/scripts/gym_scripts.pory"
	setflag FLAG_BADGE01_GET
# 345 "data/scripts/gym_scripts.pory"
	call Special_Gym_EventScript_Give_Item
# 348 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM39_ROCK_TOMB
# 349 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_6, MSGBOX_NPC
# 353 "data/scripts/gym_scripts.pory"
	waitfanfare
# 354 "data/scripts/gym_scripts.pory"
	closemessage
# 355 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 358 "data/scripts/gym_scripts.pory"
	call RustboroCity_Gym_EventScript_Roxanne_Give_Gifts
# 361 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 1
# 362 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 365 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
# 366 "data/scripts/gym_scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 367 "data/scripts/gym_scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
# 368 "data/scripts/gym_scripts.pory"
	waitfanfare
# 369 "data/scripts/gym_scripts.pory"
	closemessage
# 372 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_NPC
# 373 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 376 "data/scripts/gym_scripts.pory"
	setflag FLAG_ROXANNE_REMATCH
RustboroCity_Gym_EventScript_Roxanne_New_1:
# 378 "data/scripts/gym_scripts.pory"
	release
	end

RustboroCity_Gym_EventScript_Roxanne_New_2:
# 296 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxannePreRematch, MSGBOX_NPC
# 298 "data/scripts/gym_scripts.pory"
	call RustboroCity_Gym_EventScript_Roxanne_Battle_New
# 301 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_NPC
# 302 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 305 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
# 306 "data/scripts/gym_scripts.pory"
	call RustboroCity_Gym_EventScript_Roxanne_Give_Gifts
# 308 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_1, MSGBOX_NPC
# 311 "data/scripts/gym_scripts.pory"
	setflag FLAG_ROXANNE_REMATCH
	goto RustboroCity_Gym_EventScript_Roxanne_New_1

RustboroCity_Gym_EventScript_Roxanne_New_3:
# 315 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_2, MSGBOX_YESNO
# 316 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_Gym_EventScript_Roxanne_New_11
# 323 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 1
# 324 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 325 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_1, MSGBOX_NPC
	goto RustboroCity_Gym_EventScript_Roxanne_New_1

RustboroCity_Gym_EventScript_Roxanne_New_5:
# 313 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_ROXANNE_REMATCH, RustboroCity_Gym_EventScript_Roxanne_New_3
	goto RustboroCity_Gym_EventScript_Roxanne_New_4

RustboroCity_Gym_EventScript_Roxanne_New_8:
# 293 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_ROXANNE_REMATCH, RustboroCity_Gym_EventScript_Roxanne_New_2
	goto RustboroCity_Gym_EventScript_Roxanne_New_6

RustboroCity_Gym_EventScript_Roxanne_New_11:
# 317 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 1
# 318 "data/scripts/gym_scripts.pory"
	call Common_EventScript_ClearGymTrainers
# 319 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_3, MSGBOX_NPC
	goto RustboroCity_Gym_EventScript_Roxanne_New_1


RustboroCity_Gym_EventScript_Roxanne_Battle_New::
# 383 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_Roxanne_Battle_New_2
# 389 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, RustboroCity_Gym_EventScript_Roxanne_Battle_New_5
# 402 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneRematchDefeat
RustboroCity_Gym_EventScript_Roxanne_Battle_New_1:
	return

RustboroCity_Gym_EventScript_Roxanne_Battle_New_2:
# 385 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneDefeat
	goto RustboroCity_Gym_EventScript_Roxanne_Battle_New_1

RustboroCity_Gym_EventScript_Roxanne_Battle_New_5:
# 391 "data/scripts/gym_scripts.pory"
	setflag FLAG_SYS_DISABLE_SCALED_TRAINERS
# 392 "data/scripts/gym_scripts.pory"
	random 5
# 393 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 394 "data/scripts/gym_scripts.pory"
	case 0, RustboroCity_Gym_EventScript_Roxanne_Battle_New_9
# 395 "data/scripts/gym_scripts.pory"
	case 1, RustboroCity_Gym_EventScript_Roxanne_Battle_New_10
# 396 "data/scripts/gym_scripts.pory"
	case 2, RustboroCity_Gym_EventScript_Roxanne_Battle_New_11
# 397 "data/scripts/gym_scripts.pory"
	case 3, RustboroCity_Gym_EventScript_Roxanne_Battle_New_12
# 398 "data/scripts/gym_scripts.pory"
	case 4, RustboroCity_Gym_EventScript_Roxanne_Battle_New_13
	goto RustboroCity_Gym_EventScript_Roxanne_Battle_New_1

RustboroCity_Gym_EventScript_Roxanne_Battle_New_9:
# 394 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneRematchDefeat
	goto RustboroCity_Gym_EventScript_Roxanne_Battle_New_1

RustboroCity_Gym_EventScript_Roxanne_Battle_New_10:
# 395 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_ROXANNE_2, RustboroCity_Gym_Text_RoxanneRematchDefeat
	goto RustboroCity_Gym_EventScript_Roxanne_Battle_New_1

RustboroCity_Gym_EventScript_Roxanne_Battle_New_11:
# 396 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_ROXANNE_3, RustboroCity_Gym_Text_RoxanneRematchDefeat
	goto RustboroCity_Gym_EventScript_Roxanne_Battle_New_1

RustboroCity_Gym_EventScript_Roxanne_Battle_New_12:
# 397 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_ROXANNE_4, RustboroCity_Gym_Text_RoxanneRematchDefeat
	goto RustboroCity_Gym_EventScript_Roxanne_Battle_New_1

RustboroCity_Gym_EventScript_Roxanne_Battle_New_13:
# 398 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_ROXANNE_5, RustboroCity_Gym_Text_RoxanneRematchDefeat
	goto RustboroCity_Gym_EventScript_Roxanne_Battle_New_1


RustboroCity_Gym_EventScript_Roxanne_Give_Gifts::
# 410 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM69_ROCK_POLISH, 1
# 411 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_SECOND_TM_BADGES_COUNT
	goto_if_ge RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_3
RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_1:
# 418 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM110_STEALTH_ROCK, 1
# 419 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_THIRD_TM_BADGES_COUNT
	goto_if_ge RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_8
RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_6:
# 426 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM107_POWER_GEM, 1
# 427 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_FOURTH_TM_BADGES_COUNT
	goto_if_ge RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_13
RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_11:
# 434 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM71_STONE_EDGE, 1
# 435 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_FIFTH_TM_BADGES_COUNT
	goto_if_ge RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_18
RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_16:
# 442 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_MEGA_STONES_BADGES_COUNT
	goto_if_ge RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_25
RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_24:
# 449 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_23
RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_21:
# 462 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_CheckForAllBadges
	return

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_2:
# 412 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM69_ROCK_POLISH
# 413 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_Text_0, MSGBOX_NPC
# 414 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_1

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_3:
# 411 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_2
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_1

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_7:
# 420 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM110_STEALTH_ROCK
# 421 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_Text_1, MSGBOX_NPC
# 422 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_6

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_8:
# 419 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_7
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_6

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_12:
# 428 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM107_POWER_GEM
# 429 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_Text_2, MSGBOX_NPC
# 430 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_11

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_13:
# 427 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_12
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_11

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_17:
# 436 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM71_STONE_EDGE
# 437 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_Text_3, MSGBOX_NPC
# 438 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_16

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_18:
# 435 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_17
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_16

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_22:
# 443 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_Text_4, MSGBOX_NPC
# 444 "data/scripts/gym_scripts.pory"
	giveitem ITEM_AGGRONITE
# 445 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_Text_5, MSGBOX_NPC
# 446 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_AGGRON_MEGA_STONE
# 447 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_21

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_23:
# 451 "data/scripts/gym_scripts.pory"
	random 7
# 452 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 453 "data/scripts/gym_scripts.pory"
	case 0, RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_29
# 454 "data/scripts/gym_scripts.pory"
	case 1, RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_30
# 455 "data/scripts/gym_scripts.pory"
	case 2, RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_31
# 456 "data/scripts/gym_scripts.pory"
	case 3, RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_32
# 457 "data/scripts/gym_scripts.pory"
	case 4, RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_33
# 458 "data/scripts/gym_scripts.pory"
	case 5, RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_34
# 459 "data/scripts/gym_scripts.pory"
	case 6, RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_35
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_21

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_25:
# 442 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_AGGRON_MEGA_STONE, RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_22
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_24

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_29:
# 453 "data/scripts/gym_scripts.pory"
	giveitem ITEM_ROCK_GEM, 2
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_21

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_30:
# 454 "data/scripts/gym_scripts.pory"
	giveitem ITEM_ROCKY_HELMET, 2
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_21

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_31:
# 455 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FOCUS_SASH, 2
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_21

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_32:
# 456 "data/scripts/gym_scripts.pory"
	giveitem ITEM_HARD_STONE, 2
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_21

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_33:
# 457 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FLOAT_STONE, 2
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_21

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_34:
# 458 "data/scripts/gym_scripts.pory"
	giveitem ITEM_METAL_COAT, 2
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_21

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_35:
# 459 "data/scripts/gym_scripts.pory"
	giveitem ITEM_PROTECTOR, 2
	goto RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_21


RustboroCity_Gym_EventScript_Gym_Aaron::
# 467 "data/scripts/gym_scripts.pory"
	lock
# 468 "data/scripts/gym_scripts.pory"
	faceplayer
# 469 "data/scripts/gym_scripts.pory"
	switch VAR_GYM_POKEMON_SPECIES
# 470 "data/scripts/gym_scripts.pory"
	case SPECIES_ARON, RustboroCity_Gym_EventScript_Gym_Aaron_3
# 488 "data/scripts/gym_scripts.pory"
	case SPECIES_LAIRON, RustboroCity_Gym_EventScript_Gym_Aaron_4
# 505 "data/scripts/gym_scripts.pory"
	case SPECIES_AGGRON, RustboroCity_Gym_EventScript_Gym_Aaron_5
RustboroCity_Gym_EventScript_Gym_Aaron_1:
# 531 "data/scripts/gym_scripts.pory"
	release
	end

RustboroCity_Gym_EventScript_Gym_Aaron_3:
# 471 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_Gym_Aaron_12
RustboroCity_Gym_EventScript_Gym_Aaron_10:
# 477 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_Gym_Aaron_9
RustboroCity_Gym_EventScript_Gym_Aaron_8:
# 484 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_4, MSGBOX_NPC
# 485 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_5, MSGBOX_SIGN
# 486 "data/scripts/gym_scripts.pory"
	waitmessage
	goto RustboroCity_Gym_EventScript_Gym_Aaron_1

RustboroCity_Gym_EventScript_Gym_Aaron_4:
# 489 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_Gym_Aaron_21
RustboroCity_Gym_EventScript_Gym_Aaron_19:
# 495 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_Gym_Aaron_18
RustboroCity_Gym_EventScript_Gym_Aaron_17:
# 501 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_8, MSGBOX_NPC
# 502 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_9, MSGBOX_SIGN
# 503 "data/scripts/gym_scripts.pory"
	waitmessage
	goto RustboroCity_Gym_EventScript_Gym_Aaron_1

RustboroCity_Gym_EventScript_Gym_Aaron_5:
# 506 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_Gym_Aaron_34
RustboroCity_Gym_EventScript_Gym_Aaron_32:
# 512 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_Gym_Aaron_31
RustboroCity_Gym_EventScript_Gym_Aaron_29:
# 518 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_MEGA_STONES_BADGES_COUNT
	goto_if_ge RustboroCity_Gym_EventScript_Gym_Aaron_28
RustboroCity_Gym_EventScript_Gym_Aaron_27:
# 526 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_14, MSGBOX_NPC
# 527 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_15, MSGBOX_SIGN
# 528 "data/scripts/gym_scripts.pory"
	waitmessage
	goto RustboroCity_Gym_EventScript_Gym_Aaron_1

RustboroCity_Gym_EventScript_Gym_Aaron_6:
# 473 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_0, MSGBOX_NPC
# 474 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_1, MSGBOX_SIGN
# 475 "data/scripts/gym_scripts.pory"
	waitmessage
	goto RustboroCity_Gym_EventScript_Gym_Aaron_1

RustboroCity_Gym_EventScript_Gym_Aaron_7:
# 479 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_2, MSGBOX_NPC
# 480 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_3, MSGBOX_SIGN
# 481 "data/scripts/gym_scripts.pory"
	waitmessage
	goto RustboroCity_Gym_EventScript_Gym_Aaron_1

RustboroCity_Gym_EventScript_Gym_Aaron_9:
# 477 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_ROXANNE_REMATCH, RustboroCity_Gym_EventScript_Gym_Aaron_7
	goto RustboroCity_Gym_EventScript_Gym_Aaron_8

RustboroCity_Gym_EventScript_Gym_Aaron_12:
# 471 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_ROXANNE_REMATCH, RustboroCity_Gym_EventScript_Gym_Aaron_6
	goto RustboroCity_Gym_EventScript_Gym_Aaron_10

RustboroCity_Gym_EventScript_Gym_Aaron_15:
# 491 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_6, MSGBOX_NPC
# 492 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_1, MSGBOX_SIGN
# 493 "data/scripts/gym_scripts.pory"
	waitmessage
	goto RustboroCity_Gym_EventScript_Gym_Aaron_1

RustboroCity_Gym_EventScript_Gym_Aaron_16:
# 496 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_7, MSGBOX_NPC
# 497 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_3, MSGBOX_SIGN
# 498 "data/scripts/gym_scripts.pory"
	waitmessage
	goto RustboroCity_Gym_EventScript_Gym_Aaron_1

RustboroCity_Gym_EventScript_Gym_Aaron_18:
# 495 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_ROXANNE_REMATCH, RustboroCity_Gym_EventScript_Gym_Aaron_16
	goto RustboroCity_Gym_EventScript_Gym_Aaron_17

RustboroCity_Gym_EventScript_Gym_Aaron_21:
# 489 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_ROXANNE_REMATCH, RustboroCity_Gym_EventScript_Gym_Aaron_15
	goto RustboroCity_Gym_EventScript_Gym_Aaron_19

RustboroCity_Gym_EventScript_Gym_Aaron_24:
# 508 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_10, MSGBOX_NPC
# 509 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_11, MSGBOX_SIGN
# 510 "data/scripts/gym_scripts.pory"
	waitmessage
	goto RustboroCity_Gym_EventScript_Gym_Aaron_1

RustboroCity_Gym_EventScript_Gym_Aaron_25:
# 514 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_12, MSGBOX_NPC
# 515 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_3, MSGBOX_SIGN
# 516 "data/scripts/gym_scripts.pory"
	waitmessage
	goto RustboroCity_Gym_EventScript_Gym_Aaron_1

RustboroCity_Gym_EventScript_Gym_Aaron_26:
# 520 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_10, MSGBOX_NPC
# 521 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_13, MSGBOX_SIGN
# 522 "data/scripts/gym_scripts.pory"
	waitmessage
	goto RustboroCity_Gym_EventScript_Gym_Aaron_1

RustboroCity_Gym_EventScript_Gym_Aaron_28:
# 518 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_AGGRON_MEGA_STONE, RustboroCity_Gym_EventScript_Gym_Aaron_26
	goto RustboroCity_Gym_EventScript_Gym_Aaron_27

RustboroCity_Gym_EventScript_Gym_Aaron_31:
# 512 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_ROXANNE_REMATCH, RustboroCity_Gym_EventScript_Gym_Aaron_25
	goto RustboroCity_Gym_EventScript_Gym_Aaron_29

RustboroCity_Gym_EventScript_Gym_Aaron_34:
# 506 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_ROXANNE_REMATCH, RustboroCity_Gym_EventScript_Gym_Aaron_24
	goto RustboroCity_Gym_EventScript_Gym_Aaron_32


RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species::
# 536 "data/scripts/gym_scripts.pory"
	setflag FLAG_HIDE_GYM_MONS
# 537 "data/scripts/gym_scripts.pory"
	switch VAR_NUM_BADGES
# 538 "data/scripts/gym_scripts.pory"
	case 0, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_3
# 539 "data/scripts/gym_scripts.pory"
	case 1, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_4
# 540 "data/scripts/gym_scripts.pory"
	case 2, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_5
# 541 "data/scripts/gym_scripts.pory"
	case 3, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_6
# 542 "data/scripts/gym_scripts.pory"
	case 4, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_7
# 543 "data/scripts/gym_scripts.pory"
	case 5, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_8
# 544 "data/scripts/gym_scripts.pory"
	case 6, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_9
# 545 "data/scripts/gym_scripts.pory"
	case 7, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_10
# 546 "data/scripts/gym_scripts.pory"
	case 8, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_11
# 547 "data/scripts/gym_scripts.pory"
	case 9, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_12
# 548 "data/scripts/gym_scripts.pory"
	case 10, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_13
# 549 "data/scripts/gym_scripts.pory"
	case 11, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_14
# 550 "data/scripts/gym_scripts.pory"
	case 12, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_15
# 551 "data/scripts/gym_scripts.pory"
	case 13, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_16
# 552 "data/scripts/gym_scripts.pory"
	case 14, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_17
# 553 "data/scripts/gym_scripts.pory"
	case 15, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_18
# 554 "data/scripts/gym_scripts.pory"
	case 16, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_19
# 555 "data/scripts/gym_scripts.pory"
	case 17, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_20
RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1:
# 558 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_NO_EVOLUTION_MODE, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_22
# 558 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_LITTLE_CUP_MODE, RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_22
RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_21:
	return

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_3:
# 538 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_ARON
# 538 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_ARON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_4:
# 539 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_ARON
# 539 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_ARON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_5:
# 540 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_ARON
# 540 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_ARON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_6:
# 541 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_ARON
# 541 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_ARON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_7:
# 542 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_ARON
# 542 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_ARON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_8:
# 543 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_ARON
# 543 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_ARON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_9:
# 544 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_LAIRON
# 544 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_LAIRON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_10:
# 545 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_LAIRON
# 545 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_LAIRON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_11:
# 546 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_LAIRON
# 546 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_LAIRON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_12:
# 547 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_LAIRON
# 547 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_LAIRON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_13:
# 548 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_AGGRON
# 548 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_AGGRON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_14:
# 549 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_AGGRON
# 549 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_AGGRON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_15:
# 550 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_AGGRON
# 550 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_AGGRON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_16:
# 551 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_AGGRON
# 551 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_AGGRON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_17:
# 552 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_AGGRON
# 552 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_AGGRON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_18:
# 553 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_AGGRON
# 553 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_AGGRON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_19:
# 554 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_AGGRON
# 554 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_AGGRON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_20:
# 555 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_AGGRON
# 555 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_AGGRON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_22:
# 559 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_ARON
# 559 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_ARON
	goto RustboroCity_Gym_EventScript_Set_Gym_Pokemon_Species_21


DewfordTown_Gym_EventScript_GymGuide_New::
# 566 "data/scripts/gym_scripts.pory"
	lock
# 567 "data/scripts/gym_scripts.pory"
	faceplayer
# 568 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuide_New_2
# 584 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_NPC
DewfordTown_Gym_EventScript_GymGuide_New_1:
# 586 "data/scripts/gym_scripts.pory"
	release
	end

DewfordTown_Gym_EventScript_GymGuide_New_2:
# 569 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_BRAWLY_REMATCH, DewfordTown_Gym_EventScript_GymGuide_New_5
# 580 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_NPC
	goto DewfordTown_Gym_EventScript_GymGuide_New_1

DewfordTown_Gym_EventScript_GymGuide_New_5:
# 570 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_0, MSGBOX_YESNO
# 571 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_Gym_EventScript_GymGuide_New_8
# 576 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_2, MSGBOX_NPC
	goto DewfordTown_Gym_EventScript_GymGuide_New_1

DewfordTown_Gym_EventScript_GymGuide_New_8:
# 572 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_1, MSGBOX_NPC
# 573 "data/scripts/gym_scripts.pory"
	warp MAP_DEWFORD_TOWN_GYM, 255, 4, 4
	goto DewfordTown_Gym_EventScript_GymGuide_New_1


DewfordTown_Gym_EventScript_Brawly_New::
# 591 "data/scripts/gym_scripts.pory"
	lock
# 592 "data/scripts/gym_scripts.pory"
	faceplayer
# 593 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_Brawly_New_8
DewfordTown_Gym_EventScript_Brawly_New_6:
# 613 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_Brawly_New_5
DewfordTown_Gym_EventScript_Brawly_New_4:
# 630 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyIntro, MSGBOX_NPC
# 632 "data/scripts/gym_scripts.pory"
	call DewfordTown_Gym_EventScript_Brawly_Battle_New
# 635 "data/scripts/gym_scripts.pory"
	message DewfordTown_Gym_EventScript_Brawly_New_Text_3
# 636 "data/scripts/gym_scripts.pory"
	waitmessage
# 637 "data/scripts/gym_scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 638 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_5, MSGBOX_NPC
# 639 "data/scripts/gym_scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 640 "data/scripts/gym_scripts.pory"
	setflag FLAG_BADGE02_GET
# 643 "data/scripts/gym_scripts.pory"
	call Special_Gym_EventScript_Give_Item
# 646 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM08_BULK_UP
# 647 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Brawly_New_Text_4, MSGBOX_NPC
# 649 "data/scripts/gym_scripts.pory"
	waitfanfare
# 650 "data/scripts/gym_scripts.pory"
	closemessage
# 651 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 654 "data/scripts/gym_scripts.pory"
	call DewfordTown_Gym_EventScript_Brawly_Give_Gifts
# 657 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 2
# 658 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 661 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
# 662 "data/scripts/gym_scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 663 "data/scripts/gym_scripts.pory"
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
# 664 "data/scripts/gym_scripts.pory"
	waitfanfare
# 665 "data/scripts/gym_scripts.pory"
	closemessage
# 668 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_NPC
# 669 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 672 "data/scripts/gym_scripts.pory"
	setflag FLAG_BRAWLY_REMATCH
DewfordTown_Gym_EventScript_Brawly_New_1:
# 674 "data/scripts/gym_scripts.pory"
	release
	end

DewfordTown_Gym_EventScript_Brawly_New_2:
# 596 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyPreRematch, MSGBOX_NPC
# 598 "data/scripts/gym_scripts.pory"
	call DewfordTown_Gym_EventScript_Brawly_Battle_New
# 601 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_NPC
# 602 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 605 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
# 606 "data/scripts/gym_scripts.pory"
	call DewfordTown_Gym_EventScript_Brawly_Give_Gifts
# 608 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Brawly_New_Text_0, MSGBOX_NPC
# 611 "data/scripts/gym_scripts.pory"
	setflag FLAG_BRAWLY_REMATCH
	goto DewfordTown_Gym_EventScript_Brawly_New_1

DewfordTown_Gym_EventScript_Brawly_New_3:
# 615 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Brawly_New_Text_1, MSGBOX_YESNO
# 616 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_Gym_EventScript_Brawly_New_11
# 622 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 2
# 623 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 624 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Brawly_New_Text_0, MSGBOX_NPC
	goto DewfordTown_Gym_EventScript_Brawly_New_1

DewfordTown_Gym_EventScript_Brawly_New_5:
# 613 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BRAWLY_REMATCH, DewfordTown_Gym_EventScript_Brawly_New_3
	goto DewfordTown_Gym_EventScript_Brawly_New_4

DewfordTown_Gym_EventScript_Brawly_New_8:
# 593 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_BRAWLY_REMATCH, DewfordTown_Gym_EventScript_Brawly_New_2
	goto DewfordTown_Gym_EventScript_Brawly_New_6

DewfordTown_Gym_EventScript_Brawly_New_11:
# 617 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 2
# 618 "data/scripts/gym_scripts.pory"
	call Common_EventScript_ClearGymTrainers
# 619 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Brawly_New_Text_2, MSGBOX_NPC
	goto DewfordTown_Gym_EventScript_Brawly_New_1


DewfordTown_Gym_EventScript_Brawly_Battle_New::
# 679 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_Brawly_Battle_New_2
# 685 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, DewfordTown_Gym_EventScript_Brawly_Battle_New_5
# 698 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyRematchDefeat
DewfordTown_Gym_EventScript_Brawly_Battle_New_1:
	return

DewfordTown_Gym_EventScript_Brawly_Battle_New_2:
# 681 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyDefeat
	goto DewfordTown_Gym_EventScript_Brawly_Battle_New_1

DewfordTown_Gym_EventScript_Brawly_Battle_New_5:
# 687 "data/scripts/gym_scripts.pory"
	setflag FLAG_SYS_DISABLE_SCALED_TRAINERS
# 688 "data/scripts/gym_scripts.pory"
	random 5
# 689 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 690 "data/scripts/gym_scripts.pory"
	case 0, DewfordTown_Gym_EventScript_Brawly_Battle_New_9
# 691 "data/scripts/gym_scripts.pory"
	case 1, DewfordTown_Gym_EventScript_Brawly_Battle_New_10
# 692 "data/scripts/gym_scripts.pory"
	case 2, DewfordTown_Gym_EventScript_Brawly_Battle_New_11
# 693 "data/scripts/gym_scripts.pory"
	case 3, DewfordTown_Gym_EventScript_Brawly_Battle_New_12
# 694 "data/scripts/gym_scripts.pory"
	case 4, DewfordTown_Gym_EventScript_Brawly_Battle_New_13
	goto DewfordTown_Gym_EventScript_Brawly_Battle_New_1

DewfordTown_Gym_EventScript_Brawly_Battle_New_9:
# 690 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyRematchDefeat
	goto DewfordTown_Gym_EventScript_Brawly_Battle_New_1

DewfordTown_Gym_EventScript_Brawly_Battle_New_10:
# 691 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_2, DewfordTown_Gym_Text_BrawlyRematchDefeat
	goto DewfordTown_Gym_EventScript_Brawly_Battle_New_1

DewfordTown_Gym_EventScript_Brawly_Battle_New_11:
# 692 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_3, DewfordTown_Gym_Text_BrawlyRematchDefeat
	goto DewfordTown_Gym_EventScript_Brawly_Battle_New_1

DewfordTown_Gym_EventScript_Brawly_Battle_New_12:
# 693 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_4, DewfordTown_Gym_Text_BrawlyRematchDefeat
	goto DewfordTown_Gym_EventScript_Brawly_Battle_New_1

DewfordTown_Gym_EventScript_Brawly_Battle_New_13:
# 694 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_BRAWLY_5, DewfordTown_Gym_Text_BrawlyRematchDefeat
	goto DewfordTown_Gym_EventScript_Brawly_Battle_New_1


DewfordTown_Gym_EventScript_Brawly_Give_Gifts::
# 706 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM51_LOW_SWEEP, 1
# 707 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_SECOND_TM_BADGES_COUNT
	goto_if_ge DewfordTown_Gym_EventScript_Brawly_Give_Gifts_3
DewfordTown_Gym_EventScript_Brawly_Give_Gifts_1:
# 714 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM87_SWAGGER, 1
# 715 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_THIRD_TM_BADGES_COUNT
	goto_if_ge DewfordTown_Gym_EventScript_Brawly_Give_Gifts_8
DewfordTown_Gym_EventScript_Brawly_Give_Gifts_6:
# 722 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM52_FOCUS_BLAST, 1
# 723 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_FOURTH_TM_BADGES_COUNT
	goto_if_ge DewfordTown_Gym_EventScript_Brawly_Give_Gifts_13
DewfordTown_Gym_EventScript_Brawly_Give_Gifts_11:
# 730 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM106_AURA_SPHERE, 1
# 731 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_FIFTH_TM_BADGES_COUNT
	goto_if_ge DewfordTown_Gym_EventScript_Brawly_Give_Gifts_18
DewfordTown_Gym_EventScript_Brawly_Give_Gifts_16:
# 738 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_MEGA_STONES_BADGES_COUNT
	goto_if_ge DewfordTown_Gym_EventScript_Brawly_Give_Gifts_25
DewfordTown_Gym_EventScript_Brawly_Give_Gifts_24:
# 745 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, DewfordTown_Gym_EventScript_Brawly_Give_Gifts_23
DewfordTown_Gym_EventScript_Brawly_Give_Gifts_21:
# 758 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_CheckForAllBadges
	return

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_2:
# 708 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM51_LOW_SWEEP
# 709 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Brawly_Give_Gifts_Text_0, MSGBOX_NPC
# 710 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_1

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_3:
# 707 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_Gym_EventScript_Brawly_Give_Gifts_2
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_1

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_7:
# 716 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM87_SWAGGER
# 717 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Brawly_Give_Gifts_Text_1, MSGBOX_NPC
# 718 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_6

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_8:
# 715 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_Gym_EventScript_Brawly_Give_Gifts_7
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_6

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_12:
# 724 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM52_FOCUS_BLAST
# 725 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Brawly_Give_Gifts_Text_2, MSGBOX_NPC
# 726 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_11

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_13:
# 723 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_Gym_EventScript_Brawly_Give_Gifts_12
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_11

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_17:
# 732 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM106_AURA_SPHERE
# 733 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Brawly_Give_Gifts_Text_3, MSGBOX_NPC
# 734 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_16

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_18:
# 731 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_Gym_EventScript_Brawly_Give_Gifts_17
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_16

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_22:
# 739 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Brawly_Give_Gifts_Text_4, MSGBOX_NPC
# 740 "data/scripts/gym_scripts.pory"
	giveitem ITEM_HERACRONITE
# 741 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Brawly_Give_Gifts_Text_5, MSGBOX_NPC
# 742 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_HERACROSS_MEGA_STONE
# 743 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_21

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_23:
# 747 "data/scripts/gym_scripts.pory"
	random 7
# 748 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 749 "data/scripts/gym_scripts.pory"
	case 0, DewfordTown_Gym_EventScript_Brawly_Give_Gifts_29
# 750 "data/scripts/gym_scripts.pory"
	case 1, DewfordTown_Gym_EventScript_Brawly_Give_Gifts_30
# 751 "data/scripts/gym_scripts.pory"
	case 2, DewfordTown_Gym_EventScript_Brawly_Give_Gifts_31
# 752 "data/scripts/gym_scripts.pory"
	case 3, DewfordTown_Gym_EventScript_Brawly_Give_Gifts_32
# 753 "data/scripts/gym_scripts.pory"
	case 4, DewfordTown_Gym_EventScript_Brawly_Give_Gifts_33
# 754 "data/scripts/gym_scripts.pory"
	case 5, DewfordTown_Gym_EventScript_Brawly_Give_Gifts_34
# 755 "data/scripts/gym_scripts.pory"
	case 6, DewfordTown_Gym_EventScript_Brawly_Give_Gifts_35
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_21

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_25:
# 738 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_HERACROSS_MEGA_STONE, DewfordTown_Gym_EventScript_Brawly_Give_Gifts_22
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_24

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_29:
# 749 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FIGHTING_GEM, 2
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_21

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_30:
# 750 "data/scripts/gym_scripts.pory"
	giveitem ITEM_MUSCLE_WING, 10
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_21

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_31:
# 751 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FOCUS_BAND, 2
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_21

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_32:
# 752 "data/scripts/gym_scripts.pory"
	giveitem ITEM_CHOICE_BAND, 2
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_21

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_33:
# 753 "data/scripts/gym_scripts.pory"
	giveitem ITEM_PAYAPA_BERRY, 5
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_21

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_34:
# 754 "data/scripts/gym_scripts.pory"
	giveitem ITEM_KINGS_ROCK, 2
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_21

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_35:
# 755 "data/scripts/gym_scripts.pory"
	giveitem ITEM_EXPERT_BELT, 2
	goto DewfordTown_Gym_EventScript_Brawly_Give_Gifts_21


DewfordTown_Gym_EventScript_Gym_Makuhita::
# 763 "data/scripts/gym_scripts.pory"
	lock
# 764 "data/scripts/gym_scripts.pory"
	faceplayer
# 765 "data/scripts/gym_scripts.pory"
	switch VAR_GYM_POKEMON_SPECIES
# 766 "data/scripts/gym_scripts.pory"
	case SPECIES_MAKUHITA, DewfordTown_Gym_EventScript_Gym_Makuhita_3
# 784 "data/scripts/gym_scripts.pory"
	case SPECIES_HARIYAMA, DewfordTown_Gym_EventScript_Gym_Makuhita_4
DewfordTown_Gym_EventScript_Gym_Makuhita_1:
# 802 "data/scripts/gym_scripts.pory"
	release
	end

DewfordTown_Gym_EventScript_Gym_Makuhita_3:
# 767 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_Gym_Makuhita_11
DewfordTown_Gym_EventScript_Gym_Makuhita_9:
# 773 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_Gym_Makuhita_8
DewfordTown_Gym_EventScript_Gym_Makuhita_7:
# 780 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Gym_Makuhita_Text_4, MSGBOX_NPC
# 781 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Gym_Makuhita_Text_5, MSGBOX_SIGN
# 782 "data/scripts/gym_scripts.pory"
	waitmessage
	goto DewfordTown_Gym_EventScript_Gym_Makuhita_1

DewfordTown_Gym_EventScript_Gym_Makuhita_4:
# 785 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_Gym_Makuhita_20
DewfordTown_Gym_EventScript_Gym_Makuhita_18:
# 791 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_Gym_Makuhita_17
DewfordTown_Gym_EventScript_Gym_Makuhita_16:
# 797 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Gym_Makuhita_Text_10, MSGBOX_NPC
# 798 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Gym_Makuhita_Text_11, MSGBOX_SIGN
# 799 "data/scripts/gym_scripts.pory"
	waitmessage
	goto DewfordTown_Gym_EventScript_Gym_Makuhita_1

DewfordTown_Gym_EventScript_Gym_Makuhita_5:
# 769 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Gym_Makuhita_Text_0, MSGBOX_NPC
# 770 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Gym_Makuhita_Text_1, MSGBOX_SIGN
# 771 "data/scripts/gym_scripts.pory"
	waitmessage
	goto DewfordTown_Gym_EventScript_Gym_Makuhita_1

DewfordTown_Gym_EventScript_Gym_Makuhita_6:
# 775 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Gym_Makuhita_Text_2, MSGBOX_NPC
# 776 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Gym_Makuhita_Text_3, MSGBOX_SIGN
# 777 "data/scripts/gym_scripts.pory"
	waitmessage
	goto DewfordTown_Gym_EventScript_Gym_Makuhita_1

DewfordTown_Gym_EventScript_Gym_Makuhita_8:
# 773 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BRAWLY_REMATCH, DewfordTown_Gym_EventScript_Gym_Makuhita_6
	goto DewfordTown_Gym_EventScript_Gym_Makuhita_7

DewfordTown_Gym_EventScript_Gym_Makuhita_11:
# 767 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_BRAWLY_REMATCH, DewfordTown_Gym_EventScript_Gym_Makuhita_5
	goto DewfordTown_Gym_EventScript_Gym_Makuhita_9

DewfordTown_Gym_EventScript_Gym_Makuhita_14:
# 787 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Gym_Makuhita_Text_6, MSGBOX_NPC
# 788 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Gym_Makuhita_Text_7, MSGBOX_SIGN
# 789 "data/scripts/gym_scripts.pory"
	waitmessage
	goto DewfordTown_Gym_EventScript_Gym_Makuhita_1

DewfordTown_Gym_EventScript_Gym_Makuhita_15:
# 792 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Gym_Makuhita_Text_8, MSGBOX_NPC
# 793 "data/scripts/gym_scripts.pory"
	msgbox DewfordTown_Gym_EventScript_Gym_Makuhita_Text_9, MSGBOX_SIGN
# 794 "data/scripts/gym_scripts.pory"
	waitmessage
	goto DewfordTown_Gym_EventScript_Gym_Makuhita_1

DewfordTown_Gym_EventScript_Gym_Makuhita_17:
# 791 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BRAWLY_REMATCH, DewfordTown_Gym_EventScript_Gym_Makuhita_15
	goto DewfordTown_Gym_EventScript_Gym_Makuhita_16

DewfordTown_Gym_EventScript_Gym_Makuhita_20:
# 785 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_BRAWLY_REMATCH, DewfordTown_Gym_EventScript_Gym_Makuhita_14
	goto DewfordTown_Gym_EventScript_Gym_Makuhita_18


DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species::
# 807 "data/scripts/gym_scripts.pory"
	setflag FLAG_HIDE_GYM_MONS
# 808 "data/scripts/gym_scripts.pory"
	switch VAR_NUM_BADGES
# 809 "data/scripts/gym_scripts.pory"
	case 0, DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_3
# 810 "data/scripts/gym_scripts.pory"
	case 1, DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_4
# 811 "data/scripts/gym_scripts.pory"
	case 2, DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_5
# 812 "data/scripts/gym_scripts.pory"
	case 3, DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_6
# 813 "data/scripts/gym_scripts.pory"
	case 4, DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_7
# 814 "data/scripts/gym_scripts.pory"
	case 5, DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_8
# 815 "data/scripts/gym_scripts.pory"
	case 6, DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_9
# 816 "data/scripts/gym_scripts.pory"
	case 7, DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_10
# 817 "data/scripts/gym_scripts.pory"
	case 8, DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_11
DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_1:
# 820 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_NO_EVOLUTION_MODE, DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_13
# 820 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_LITTLE_CUP_MODE, DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_13
DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_12:
	return

DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_3:
# 809 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_MAKUHITA
# 809 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_MAKUHITA
	goto DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_1

DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_4:
# 810 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_MAKUHITA
# 810 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_MAKUHITA
	goto DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_1

DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_5:
# 811 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_HARIYAMA
# 811 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_HARIYAMA
	goto DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_1

DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_6:
# 812 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_HARIYAMA
# 812 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_HARIYAMA
	goto DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_1

DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_7:
# 813 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_HARIYAMA
# 813 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_HARIYAMA
	goto DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_1

DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_8:
# 814 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_HARIYAMA
# 814 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_HARIYAMA
	goto DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_1

DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_9:
# 815 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_HARIYAMA
# 815 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_HARIYAMA
	goto DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_1

DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_10:
# 816 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_HARIYAMA
# 816 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_HARIYAMA
	goto DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_1

DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_11:
# 817 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_HARIYAMA
# 817 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_HARIYAMA
	goto DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_1

DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_13:
# 821 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_MAKUHITA
# 821 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_MAKUHITA
	goto DewfordTown_Gym_EventScript_Set_Gym_Pokemon_Species_12


MauvilleCity_Gym_EventScript_Wattson_New::
# 828 "data/scripts/gym_scripts.pory"
	lock
# 829 "data/scripts/gym_scripts.pory"
	faceplayer
# 830 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_Wattson_New_8
MauvilleCity_Gym_EventScript_Wattson_New_6:
# 850 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_Wattson_New_5
MauvilleCity_Gym_EventScript_Wattson_New_4:
# 867 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonIntro_New, MSGBOX_NPC
# 869 "data/scripts/gym_scripts.pory"
	call MauvilleCity_Gym_EventScript_Wattson_Battle_New
# 872 "data/scripts/gym_scripts.pory"
	message MauvilleCity_Gym_EventScript_Wattson_New_Text_3
# 873 "data/scripts/gym_scripts.pory"
	waitmessage
# 874 "data/scripts/gym_scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 875 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_5, MSGBOX_NPC
# 876 "data/scripts/gym_scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 877 "data/scripts/gym_scripts.pory"
	setflag FLAG_BADGE03_GET
# 880 "data/scripts/gym_scripts.pory"
	call Special_Gym_EventScript_Give_Item
# 883 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM73_THUNDER_WAVE
# 884 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Wattson_New_Text_4, MSGBOX_NPC
# 886 "data/scripts/gym_scripts.pory"
	waitfanfare
# 887 "data/scripts/gym_scripts.pory"
	closemessage
# 888 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 891 "data/scripts/gym_scripts.pory"
	call MauvilleCity_Gym_EventScript_Wattson_Give_Gifts
# 894 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 3
# 895 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 898 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
# 899 "data/scripts/gym_scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 900 "data/scripts/gym_scripts.pory"
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
# 901 "data/scripts/gym_scripts.pory"
	waitfanfare
# 902 "data/scripts/gym_scripts.pory"
	closemessage
# 905 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_NPC
# 906 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 909 "data/scripts/gym_scripts.pory"
	setflag FLAG_WATTSON_REMATCH
MauvilleCity_Gym_EventScript_Wattson_New_1:
# 911 "data/scripts/gym_scripts.pory"
	release
	end

MauvilleCity_Gym_EventScript_Wattson_New_2:
# 833 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonPreRematch, MSGBOX_NPC
# 835 "data/scripts/gym_scripts.pory"
	call MauvilleCity_Gym_EventScript_Wattson_Battle_New
# 838 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_NPC
# 839 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 842 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
# 843 "data/scripts/gym_scripts.pory"
	call MauvilleCity_Gym_EventScript_Wattson_Give_Gifts
# 845 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Wattson_New_Text_0, MSGBOX_NPC
# 848 "data/scripts/gym_scripts.pory"
	setflag FLAG_WATTSON_REMATCH
	goto MauvilleCity_Gym_EventScript_Wattson_New_1

MauvilleCity_Gym_EventScript_Wattson_New_3:
# 852 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Wattson_New_Text_1, MSGBOX_YESNO
# 853 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_Gym_EventScript_Wattson_New_11
# 859 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 3
# 860 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 861 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Wattson_New_Text_0, MSGBOX_NPC
	goto MauvilleCity_Gym_EventScript_Wattson_New_1

MauvilleCity_Gym_EventScript_Wattson_New_5:
# 850 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_WATTSON_REMATCH, MauvilleCity_Gym_EventScript_Wattson_New_3
	goto MauvilleCity_Gym_EventScript_Wattson_New_4

MauvilleCity_Gym_EventScript_Wattson_New_8:
# 830 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_WATTSON_REMATCH, MauvilleCity_Gym_EventScript_Wattson_New_2
	goto MauvilleCity_Gym_EventScript_Wattson_New_6

MauvilleCity_Gym_EventScript_Wattson_New_11:
# 854 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 3
# 855 "data/scripts/gym_scripts.pory"
	call Common_EventScript_ClearGymTrainers
# 856 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Wattson_New_Text_2, MSGBOX_NPC
	goto MauvilleCity_Gym_EventScript_Wattson_New_1


MauvilleCity_Gym_EventScript_Wattson_Battle_New::
# 916 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_Wattson_Battle_New_2
# 922 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MauvilleCity_Gym_EventScript_Wattson_Battle_New_5
# 935 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonRematchDefeat
MauvilleCity_Gym_EventScript_Wattson_Battle_New_1:
	return

MauvilleCity_Gym_EventScript_Wattson_Battle_New_2:
# 918 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonDefeat
	goto MauvilleCity_Gym_EventScript_Wattson_Battle_New_1

MauvilleCity_Gym_EventScript_Wattson_Battle_New_5:
# 924 "data/scripts/gym_scripts.pory"
	setflag FLAG_SYS_DISABLE_SCALED_TRAINERS
# 925 "data/scripts/gym_scripts.pory"
	random 5
# 926 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 927 "data/scripts/gym_scripts.pory"
	case 0, MauvilleCity_Gym_EventScript_Wattson_Battle_New_9
# 928 "data/scripts/gym_scripts.pory"
	case 1, MauvilleCity_Gym_EventScript_Wattson_Battle_New_10
# 929 "data/scripts/gym_scripts.pory"
	case 2, MauvilleCity_Gym_EventScript_Wattson_Battle_New_11
# 930 "data/scripts/gym_scripts.pory"
	case 3, MauvilleCity_Gym_EventScript_Wattson_Battle_New_12
# 931 "data/scripts/gym_scripts.pory"
	case 4, MauvilleCity_Gym_EventScript_Wattson_Battle_New_13
	goto MauvilleCity_Gym_EventScript_Wattson_Battle_New_1

MauvilleCity_Gym_EventScript_Wattson_Battle_New_9:
# 927 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonRematchDefeat
	goto MauvilleCity_Gym_EventScript_Wattson_Battle_New_1

MauvilleCity_Gym_EventScript_Wattson_Battle_New_10:
# 928 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_WATTSON_2, MauvilleCity_Gym_Text_WattsonRematchDefeat
	goto MauvilleCity_Gym_EventScript_Wattson_Battle_New_1

MauvilleCity_Gym_EventScript_Wattson_Battle_New_11:
# 929 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_WATTSON_3, MauvilleCity_Gym_Text_WattsonRematchDefeat
	goto MauvilleCity_Gym_EventScript_Wattson_Battle_New_1

MauvilleCity_Gym_EventScript_Wattson_Battle_New_12:
# 930 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_WATTSON_4, MauvilleCity_Gym_Text_WattsonRematchDefeat
	goto MauvilleCity_Gym_EventScript_Wattson_Battle_New_1

MauvilleCity_Gym_EventScript_Wattson_Battle_New_13:
# 931 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_WATTSON_5, MauvilleCity_Gym_Text_WattsonRematchDefeat
	goto MauvilleCity_Gym_EventScript_Wattson_Battle_New_1


MauvilleCity_Gym_EventScript_Wattson_Give_Gifts::
# 943 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM34_SHOCK_WAVE, 1
# 944 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_SECOND_TM_BADGES_COUNT
	goto_if_ge MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_3
MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_1:
# 951 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM57_CHARGE_BEAM, 1
# 952 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_THIRD_TM_BADGES_COUNT
	goto_if_ge MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_8
MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_6:
# 959 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM72_VOLT_SWITCH, 1
# 960 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_FOURTH_TM_BADGES_COUNT
	goto_if_ge MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_13
MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_11:
# 967 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM93_WILD_CHARGE, 1
# 968 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_FIFTH_TM_BADGES_COUNT
	goto_if_ge MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_18
MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_16:
# 975 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_MEGA_STONES_BADGES_COUNT
	goto_if_ge MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_25
MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_24:
# 982 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_23
MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_21:
# 995 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_CheckForAllBadges
	return

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_2:
# 945 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM34_SHOCK_WAVE
# 946 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_Text_0, MSGBOX_NPC
# 947 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_1

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_3:
# 944 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_2
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_1

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_7:
# 953 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM57_CHARGE_BEAM
# 954 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_Text_1, MSGBOX_NPC
# 955 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_6

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_8:
# 952 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_7
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_6

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_12:
# 961 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM72_VOLT_SWITCH
# 962 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_Text_2, MSGBOX_NPC
# 963 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_11

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_13:
# 960 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_12
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_11

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_17:
# 969 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM93_WILD_CHARGE
# 970 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_Text_3, MSGBOX_NPC
# 971 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_16

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_18:
# 968 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_17
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_16

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_22:
# 976 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_Text_4, MSGBOX_NPC
# 977 "data/scripts/gym_scripts.pory"
	giveitem ITEM_MANECTITE
# 978 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_Text_5, MSGBOX_NPC
# 979 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_MANECTRIC_MEGA_STONE
# 980 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_21

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_23:
# 984 "data/scripts/gym_scripts.pory"
	random 7
# 985 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 986 "data/scripts/gym_scripts.pory"
	case 0, MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_29
# 987 "data/scripts/gym_scripts.pory"
	case 1, MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_30
# 988 "data/scripts/gym_scripts.pory"
	case 2, MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_31
# 989 "data/scripts/gym_scripts.pory"
	case 3, MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_32
# 990 "data/scripts/gym_scripts.pory"
	case 4, MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_33
# 991 "data/scripts/gym_scripts.pory"
	case 5, MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_34
# 992 "data/scripts/gym_scripts.pory"
	case 6, MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_35
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_21

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_25:
# 975 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_MANECTRIC_MEGA_STONE, MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_22
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_24

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_29:
# 986 "data/scripts/gym_scripts.pory"
	giveitem ITEM_CELL_BATTERY, 2
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_21

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_30:
# 987 "data/scripts/gym_scripts.pory"
	giveitem ITEM_MAGNET, 2
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_21

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_31:
# 988 "data/scripts/gym_scripts.pory"
	giveitem ITEM_LIGHT_BALL, 2
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_21

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_32:
# 989 "data/scripts/gym_scripts.pory"
	giveitem ITEM_ELECTRIC_SEED, 2
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_21

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_33:
# 990 "data/scripts/gym_scripts.pory"
	giveitem ITEM_WACAN_BERRY, 5
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_21

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_34:
# 991 "data/scripts/gym_scripts.pory"
	giveitem ITEM_THUNDER_STONE, 2
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_21

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_35:
# 992 "data/scripts/gym_scripts.pory"
	giveitem ITEM_ELECTRIC_GEM, 2
	goto MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_21


MauvilleCity_Gym_EventScript_GymGuide_New::
# 1000 "data/scripts/gym_scripts.pory"
	lock
# 1001 "data/scripts/gym_scripts.pory"
	faceplayer
# 1002 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuide_New_2
# 1018 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_NPC
MauvilleCity_Gym_EventScript_GymGuide_New_1:
# 1020 "data/scripts/gym_scripts.pory"
	release
	end

MauvilleCity_Gym_EventScript_GymGuide_New_2:
# 1003 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_WATTSON_REMATCH, MauvilleCity_Gym_EventScript_GymGuide_New_5
# 1014 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_NPC
	goto MauvilleCity_Gym_EventScript_GymGuide_New_1

MauvilleCity_Gym_EventScript_GymGuide_New_5:
# 1004 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_0, MSGBOX_YESNO
# 1005 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_Gym_EventScript_GymGuide_New_8
# 1010 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_2, MSGBOX_NPC
	goto MauvilleCity_Gym_EventScript_GymGuide_New_1

MauvilleCity_Gym_EventScript_GymGuide_New_8:
# 1006 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_1, MSGBOX_NPC
# 1007 "data/scripts/gym_scripts.pory"
	warp MAP_MAUVILLE_CITY_GYM, 255, 5, 3
	goto MauvilleCity_Gym_EventScript_GymGuide_New_1


MauvilleCity_Gym_EventScript_Gym_Electrike::
# 1025 "data/scripts/gym_scripts.pory"
	lock
# 1026 "data/scripts/gym_scripts.pory"
	faceplayer
# 1027 "data/scripts/gym_scripts.pory"
	switch VAR_GYM_POKEMON_SPECIES
# 1028 "data/scripts/gym_scripts.pory"
	case SPECIES_ELECTRIKE, MauvilleCity_Gym_EventScript_Gym_Electrike_3
# 1046 "data/scripts/gym_scripts.pory"
	case SPECIES_MANECTRIC, MauvilleCity_Gym_EventScript_Gym_Electrike_4
MauvilleCity_Gym_EventScript_Gym_Electrike_1:
# 1070 "data/scripts/gym_scripts.pory"
	release
	end

MauvilleCity_Gym_EventScript_Gym_Electrike_3:
# 1029 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_Gym_Electrike_11
MauvilleCity_Gym_EventScript_Gym_Electrike_9:
# 1035 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_Gym_Electrike_8
MauvilleCity_Gym_EventScript_Gym_Electrike_7:
# 1042 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Gym_Electrike_Text_4, MSGBOX_NPC
# 1043 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Gym_Electrike_Text_5, MSGBOX_SIGN
# 1044 "data/scripts/gym_scripts.pory"
	waitmessage
	goto MauvilleCity_Gym_EventScript_Gym_Electrike_1

MauvilleCity_Gym_EventScript_Gym_Electrike_4:
# 1047 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_Gym_Electrike_24
MauvilleCity_Gym_EventScript_Gym_Electrike_22:
# 1053 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_Gym_Electrike_21
MauvilleCity_Gym_EventScript_Gym_Electrike_19:
# 1058 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, 6
	goto_if_ge MauvilleCity_Gym_EventScript_Gym_Electrike_18
MauvilleCity_Gym_EventScript_Gym_Electrike_17:
# 1065 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Gym_Electrike_Text_12, MSGBOX_NPC
# 1066 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Gym_Electrike_Text_13, MSGBOX_SIGN
# 1067 "data/scripts/gym_scripts.pory"
	waitmessage
	goto MauvilleCity_Gym_EventScript_Gym_Electrike_1

MauvilleCity_Gym_EventScript_Gym_Electrike_5:
# 1031 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Gym_Electrike_Text_0, MSGBOX_NPC
# 1032 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Gym_Electrike_Text_1, MSGBOX_SIGN
# 1033 "data/scripts/gym_scripts.pory"
	waitmessage
	goto MauvilleCity_Gym_EventScript_Gym_Electrike_1

MauvilleCity_Gym_EventScript_Gym_Electrike_6:
# 1037 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Gym_Electrike_Text_2, MSGBOX_NPC
# 1038 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Gym_Electrike_Text_3, MSGBOX_SIGN
# 1039 "data/scripts/gym_scripts.pory"
	waitmessage
	goto MauvilleCity_Gym_EventScript_Gym_Electrike_1

MauvilleCity_Gym_EventScript_Gym_Electrike_8:
# 1035 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_WATTSON_REMATCH, MauvilleCity_Gym_EventScript_Gym_Electrike_6
	goto MauvilleCity_Gym_EventScript_Gym_Electrike_7

MauvilleCity_Gym_EventScript_Gym_Electrike_11:
# 1029 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_WATTSON_REMATCH, MauvilleCity_Gym_EventScript_Gym_Electrike_5
	goto MauvilleCity_Gym_EventScript_Gym_Electrike_9

MauvilleCity_Gym_EventScript_Gym_Electrike_14:
# 1049 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Gym_Electrike_Text_6, MSGBOX_NPC
# 1050 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Gym_Electrike_Text_7, MSGBOX_SIGN
# 1051 "data/scripts/gym_scripts.pory"
	waitmessage
	goto MauvilleCity_Gym_EventScript_Gym_Electrike_1

MauvilleCity_Gym_EventScript_Gym_Electrike_15:
# 1054 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Gym_Electrike_Text_8, MSGBOX_NPC
# 1055 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Gym_Electrike_Text_9, MSGBOX_SIGN
# 1056 "data/scripts/gym_scripts.pory"
	waitmessage
	goto MauvilleCity_Gym_EventScript_Gym_Electrike_1

MauvilleCity_Gym_EventScript_Gym_Electrike_16:
# 1060 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Gym_Electrike_Text_10, MSGBOX_NPC
# 1061 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Gym_Electrike_Text_11, MSGBOX_SIGN
# 1062 "data/scripts/gym_scripts.pory"
	waitmessage
	goto MauvilleCity_Gym_EventScript_Gym_Electrike_1

MauvilleCity_Gym_EventScript_Gym_Electrike_18:
# 1058 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_MANECTRIC_MEGA_STONE, MauvilleCity_Gym_EventScript_Gym_Electrike_16
	goto MauvilleCity_Gym_EventScript_Gym_Electrike_17

MauvilleCity_Gym_EventScript_Gym_Electrike_21:
# 1053 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_WATTSON_REMATCH, MauvilleCity_Gym_EventScript_Gym_Electrike_15
	goto MauvilleCity_Gym_EventScript_Gym_Electrike_19

MauvilleCity_Gym_EventScript_Gym_Electrike_24:
# 1047 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_WATTSON_REMATCH, MauvilleCity_Gym_EventScript_Gym_Electrike_14
	goto MauvilleCity_Gym_EventScript_Gym_Electrike_22


MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species::
# 1075 "data/scripts/gym_scripts.pory"
	setflag FLAG_HIDE_GYM_MONS
# 1076 "data/scripts/gym_scripts.pory"
	switch VAR_NUM_BADGES
# 1077 "data/scripts/gym_scripts.pory"
	case 0, MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_3
# 1078 "data/scripts/gym_scripts.pory"
	case 1, MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_4
# 1079 "data/scripts/gym_scripts.pory"
	case 2, MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_5
# 1080 "data/scripts/gym_scripts.pory"
	case 3, MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_6
# 1081 "data/scripts/gym_scripts.pory"
	case 4, MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_7
# 1082 "data/scripts/gym_scripts.pory"
	case 5, MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_8
# 1083 "data/scripts/gym_scripts.pory"
	case 6, MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_9
# 1084 "data/scripts/gym_scripts.pory"
	case 7, MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_10
# 1085 "data/scripts/gym_scripts.pory"
	case 8, MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_11
MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_1:
# 1088 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_NO_EVOLUTION_MODE, MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_13
# 1088 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_LITTLE_CUP_MODE, MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_13
MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_12:
	return

MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_3:
# 1077 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_ELECTRIKE
# 1077 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_ELECTRIKE
	goto MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_4:
# 1078 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_ELECTRIKE
# 1078 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_ELECTRIKE
	goto MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_5:
# 1079 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_MANECTRIC
# 1079 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_MANECTRIC
	goto MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_6:
# 1080 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_MANECTRIC
# 1080 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_MANECTRIC
	goto MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_7:
# 1081 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_MANECTRIC
# 1081 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_MANECTRIC
	goto MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_8:
# 1082 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_MANECTRIC
# 1082 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_MANECTRIC
	goto MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_9:
# 1083 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_MANECTRIC
# 1083 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_MANECTRIC
	goto MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_10:
# 1084 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_MANECTRIC
# 1084 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_MANECTRIC
	goto MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_11:
# 1085 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_MANECTRIC
# 1085 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_MANECTRIC
	goto MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_13:
# 1089 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_ELECTRIKE
# 1089 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_ELECTRIKE
	goto MauvilleCity_Gym_EventScript_Set_Gym_Pokemon_Species_12


LavaridgeTown_Gym_1F_EventScript_Flannery_New::
# 1114 "data/scripts/gym_scripts.pory"
	lock
# 1115 "data/scripts/gym_scripts.pory"
	faceplayer
# 1116 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_Flannery_New_8
LavaridgeTown_Gym_1F_EventScript_Flannery_New_6:
# 1136 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_Flannery_New_5
LavaridgeTown_Gym_1F_EventScript_Flannery_New_4:
# 1153 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryIntro, MSGBOX_NPC
# 1155 "data/scripts/gym_scripts.pory"
	call LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New
# 1158 "data/scripts/gym_scripts.pory"
	message LavaridgeTown_Gym_1F_EventScript_Flannery_New_Text_3
# 1159 "data/scripts/gym_scripts.pory"
	waitmessage
# 1160 "data/scripts/gym_scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 1161 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_5, MSGBOX_NPC
# 1162 "data/scripts/gym_scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 1163 "data/scripts/gym_scripts.pory"
	setflag FLAG_BADGE04_GET
# 1166 "data/scripts/gym_scripts.pory"
	call Special_Gym_EventScript_Give_Item
# 1169 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM61_WILL_O_WISP
# 1170 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Flannery_New_Text_4, MSGBOX_NPC
# 1172 "data/scripts/gym_scripts.pory"
	waitfanfare
# 1173 "data/scripts/gym_scripts.pory"
	closemessage
# 1174 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 1177 "data/scripts/gym_scripts.pory"
	call LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts
# 1180 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 4
# 1181 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 1184 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
# 1185 "data/scripts/gym_scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1186 "data/scripts/gym_scripts.pory"
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
# 1187 "data/scripts/gym_scripts.pory"
	waitfanfare
# 1188 "data/scripts/gym_scripts.pory"
	closemessage
# 1191 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_NPC
# 1192 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 1195 "data/scripts/gym_scripts.pory"
	setflag FLAG_FLANNERY_REMATCH
LavaridgeTown_Gym_1F_EventScript_Flannery_New_1:
# 1197 "data/scripts/gym_scripts.pory"
	release
	end

LavaridgeTown_Gym_1F_EventScript_Flannery_New_2:
# 1119 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, MSGBOX_NPC
# 1121 "data/scripts/gym_scripts.pory"
	call LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New
# 1124 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_NPC
# 1125 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 1128 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
# 1129 "data/scripts/gym_scripts.pory"
	call LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts
# 1131 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Flannery_New_Text_0, MSGBOX_NPC
# 1134 "data/scripts/gym_scripts.pory"
	setflag FLAG_FLANNERY_REMATCH
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_New_1

LavaridgeTown_Gym_1F_EventScript_Flannery_New_3:
# 1138 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Flannery_New_Text_1, MSGBOX_YESNO
# 1139 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_Flannery_New_11
# 1145 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 4
# 1146 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 1147 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Flannery_New_Text_0, MSGBOX_NPC
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_New_1

LavaridgeTown_Gym_1F_EventScript_Flannery_New_5:
# 1136 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_FLANNERY_REMATCH, LavaridgeTown_Gym_1F_EventScript_Flannery_New_3
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_New_4

LavaridgeTown_Gym_1F_EventScript_Flannery_New_8:
# 1116 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_FLANNERY_REMATCH, LavaridgeTown_Gym_1F_EventScript_Flannery_New_2
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_New_6

LavaridgeTown_Gym_1F_EventScript_Flannery_New_11:
# 1140 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 4
# 1141 "data/scripts/gym_scripts.pory"
	call Common_EventScript_ClearGymTrainers
# 1142 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Flannery_New_Text_2, MSGBOX_NPC
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_New_1


LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New::
# 1202 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_2
# 1208 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_5
# 1221 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat
LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_1:
	return

LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_2:
# 1204 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryDefeat
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_1

LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_5:
# 1210 "data/scripts/gym_scripts.pory"
	setflag FLAG_SYS_DISABLE_SCALED_TRAINERS
# 1211 "data/scripts/gym_scripts.pory"
	random 5
# 1212 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 1213 "data/scripts/gym_scripts.pory"
	case 0, LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_9
# 1214 "data/scripts/gym_scripts.pory"
	case 1, LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_10
# 1215 "data/scripts/gym_scripts.pory"
	case 2, LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_11
# 1216 "data/scripts/gym_scripts.pory"
	case 3, LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_12
# 1217 "data/scripts/gym_scripts.pory"
	case 4, LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_13
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_1

LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_9:
# 1213 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_1

LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_10:
# 1214 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_FLANNERY_2, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_1

LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_11:
# 1215 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_FLANNERY_3, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_1

LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_12:
# 1216 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_FLANNERY_4, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_1

LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_13:
# 1217 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_FLANNERY_5, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Battle_New_1


LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts::
# 1229 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM120_MYSTICAL_FIRE, 1
# 1230 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_SECOND_TM_BADGES_COUNT
	goto_if_ge LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_3
LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_1:
# 1237 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM111_HEAT_CRASH, 1
# 1238 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_THIRD_TM_BADGES_COUNT
	goto_if_ge LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_8
LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_6:
# 1245 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM117_BLAZE_KICK, 1
# 1246 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_FOURTH_TM_BADGES_COUNT
	goto_if_ge LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_13
LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_11:
# 1253 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM50_OVERHEAT, 1
# 1254 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_FIFTH_TM_BADGES_COUNT
	goto_if_ge LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_18
LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_16:
# 1261 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_MEGA_STONES_BADGES_COUNT
	goto_if_ge LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_25
LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_24:
# 1268 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_23
LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_21:
# 1281 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_CheckForAllBadges
	return

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_2:
# 1231 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM120_MYSTICAL_FIRE
# 1232 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_Text_0, MSGBOX_NPC
# 1233 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_1

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_3:
# 1230 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_2
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_1

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_7:
# 1239 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM111_HEAT_CRASH
# 1240 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_Text_1, MSGBOX_NPC
# 1241 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_6

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_8:
# 1238 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_7
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_6

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_12:
# 1247 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM117_BLAZE_KICK
# 1248 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_Text_2, MSGBOX_NPC
# 1249 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_11

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_13:
# 1246 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_12
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_11

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_17:
# 1255 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM50_OVERHEAT
# 1256 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_Text_3, MSGBOX_NPC
# 1257 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_16

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_18:
# 1254 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_17
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_16

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_22:
# 1262 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_Text_4, MSGBOX_NPC
# 1263 "data/scripts/gym_scripts.pory"
	giveitem ITEM_HOUNDOOMINITE
# 1264 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_Text_5, MSGBOX_NPC
# 1265 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_HOUNDOOM_MEGA_STONE
# 1266 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_21

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_23:
# 1270 "data/scripts/gym_scripts.pory"
	random 7
# 1271 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 1272 "data/scripts/gym_scripts.pory"
	case 0, LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_29
# 1273 "data/scripts/gym_scripts.pory"
	case 1, LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_30
# 1274 "data/scripts/gym_scripts.pory"
	case 2, LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_31
# 1275 "data/scripts/gym_scripts.pory"
	case 3, LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_32
# 1276 "data/scripts/gym_scripts.pory"
	case 4, LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_33
# 1277 "data/scripts/gym_scripts.pory"
	case 5, LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_34
# 1278 "data/scripts/gym_scripts.pory"
	case 6, LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_35
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_21

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_25:
# 1261 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_HOUNDOOM_MEGA_STONE, LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_22
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_24

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_29:
# 1272 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FIRE_GEM, 2
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_21

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_30:
# 1273 "data/scripts/gym_scripts.pory"
	giveitem ITEM_CHARCOAL, 2
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_21

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_31:
# 1274 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FLAME_ORB, 2
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_21

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_32:
# 1275 "data/scripts/gym_scripts.pory"
	giveitem ITEM_HEAT_ROCK, 2
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_21

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_33:
# 1276 "data/scripts/gym_scripts.pory"
	giveitem ITEM_OCCA_BERRY, 5
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_21

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_34:
# 1277 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FIRE_STONE, 2
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_21

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_35:
# 1278 "data/scripts/gym_scripts.pory"
	giveitem ITEM_MAGMARIZER, 2
	goto LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_21


LavaridgeTown_Gym_1F_EventScript_GymGuide_New::
# 1286 "data/scripts/gym_scripts.pory"
	lock
# 1287 "data/scripts/gym_scripts.pory"
	faceplayer
# 1288 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuide_New_2
# 1304 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_NPC
LavaridgeTown_Gym_1F_EventScript_GymGuide_New_1:
# 1306 "data/scripts/gym_scripts.pory"
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide_New_2:
# 1289 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_FLANNERY_REMATCH, LavaridgeTown_Gym_1F_EventScript_GymGuide_New_5
# 1300 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_NPC
	goto LavaridgeTown_Gym_1F_EventScript_GymGuide_New_1

LavaridgeTown_Gym_1F_EventScript_GymGuide_New_5:
# 1290 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_0, MSGBOX_YESNO
# 1291 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq LavaridgeTown_Gym_1F_EventScript_GymGuide_New_8
# 1296 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_2, MSGBOX_NPC
	goto LavaridgeTown_Gym_1F_EventScript_GymGuide_New_1

LavaridgeTown_Gym_1F_EventScript_GymGuide_New_8:
# 1292 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_1, MSGBOX_NPC
# 1293 "data/scripts/gym_scripts.pory"
	warp MAP_LAVARIDGE_TOWN_GYM_1F, 255, 13, 10
	goto LavaridgeTown_Gym_1F_EventScript_GymGuide_New_1


LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal::
# 1311 "data/scripts/gym_scripts.pory"
	lock
# 1312 "data/scripts/gym_scripts.pory"
	faceplayer
# 1313 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_8
LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_6:
# 1319 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_5
LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_4:
# 1325 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_Text_4, MSGBOX_NPC
# 1326 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_Text_5, MSGBOX_SIGN
# 1327 "data/scripts/gym_scripts.pory"
	waitmessage
LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_1:
# 1329 "data/scripts/gym_scripts.pory"
	release
	end

LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_2:
# 1315 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_Text_0, MSGBOX_NPC
# 1316 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_Text_1, MSGBOX_SIGN
# 1317 "data/scripts/gym_scripts.pory"
	waitmessage
	goto LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_1

LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_3:
# 1320 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_Text_2, MSGBOX_NPC
# 1321 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_Text_3, MSGBOX_SIGN
# 1322 "data/scripts/gym_scripts.pory"
	waitmessage
	goto LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_1

LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_5:
# 1319 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_FLANNERY_REMATCH, LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_3
	goto LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_4

LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_8:
# 1313 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_FLANNERY_REMATCH, LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_2
	goto LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_6


PetalburgCity_Gym_EventScript_Norman_New::
# 1335 "data/scripts/gym_scripts.pory"
	lock
# 1336 "data/scripts/gym_scripts.pory"
	faceplayer
# 1337 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_Norman_New_8
PetalburgCity_Gym_EventScript_Norman_New_6:
# 1357 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_Norman_New_5
PetalburgCity_Gym_EventScript_Norman_New_4:
# 1374 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanIntro, MSGBOX_NPC
# 1376 "data/scripts/gym_scripts.pory"
	call PetalburgCity_Gym_EventScript_Norman_Battle_New
# 1379 "data/scripts/gym_scripts.pory"
	message PetalburgCity_Gym_EventScript_Norman_New_Text_3
# 1380 "data/scripts/gym_scripts.pory"
	waitmessage
# 1381 "data/scripts/gym_scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 1382 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_5, MSGBOX_NPC
# 1383 "data/scripts/gym_scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 1384 "data/scripts/gym_scripts.pory"
	setflag FLAG_BADGE05_GET
# 1387 "data/scripts/gym_scripts.pory"
	call Special_Gym_EventScript_Give_Item
# 1390 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM54_FALSE_SWIPE
# 1391 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Norman_New_Text_4, MSGBOX_NPC
# 1393 "data/scripts/gym_scripts.pory"
	waitfanfare
# 1394 "data/scripts/gym_scripts.pory"
	closemessage
# 1395 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 1398 "data/scripts/gym_scripts.pory"
	call PetalburgCity_Gym_EventScript_Norman_Give_Gifts
# 1401 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 5
# 1402 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 1412 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_Text_DadGoingToKeepTraining, MSGBOX_NPC
# 1413 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 1416 "data/scripts/gym_scripts.pory"
	setflag FLAG_NORMAN_REMATCH
PetalburgCity_Gym_EventScript_Norman_New_1:
# 1418 "data/scripts/gym_scripts.pory"
	release
	end

PetalburgCity_Gym_EventScript_Norman_New_2:
# 1340 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanPreRematch, MSGBOX_NPC
# 1342 "data/scripts/gym_scripts.pory"
	call PetalburgCity_Gym_EventScript_Norman_Battle_New
# 1345 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_Text_NormanPostRematch, MSGBOX_NPC
# 1346 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 1349 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
# 1350 "data/scripts/gym_scripts.pory"
	call PetalburgCity_Gym_EventScript_Norman_Give_Gifts
# 1352 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Norman_New_Text_0, MSGBOX_NPC
# 1355 "data/scripts/gym_scripts.pory"
	setflag FLAG_NORMAN_REMATCH
	goto PetalburgCity_Gym_EventScript_Norman_New_1

PetalburgCity_Gym_EventScript_Norman_New_3:
# 1359 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Norman_New_Text_1, MSGBOX_YESNO
# 1360 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_Norman_New_11
# 1366 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 5
# 1367 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 1368 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Norman_New_Text_0, MSGBOX_NPC
	goto PetalburgCity_Gym_EventScript_Norman_New_1

PetalburgCity_Gym_EventScript_Norman_New_5:
# 1357 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_NORMAN_REMATCH, PetalburgCity_Gym_EventScript_Norman_New_3
	goto PetalburgCity_Gym_EventScript_Norman_New_4

PetalburgCity_Gym_EventScript_Norman_New_8:
# 1337 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_NORMAN_REMATCH, PetalburgCity_Gym_EventScript_Norman_New_2
	goto PetalburgCity_Gym_EventScript_Norman_New_6

PetalburgCity_Gym_EventScript_Norman_New_11:
# 1361 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 5
# 1362 "data/scripts/gym_scripts.pory"
	call Common_EventScript_ClearGymTrainers
# 1363 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Norman_New_Text_2, MSGBOX_NPC
	goto PetalburgCity_Gym_EventScript_Norman_New_1


PetalburgCity_Gym_EventScript_Norman_Battle_New::
# 1423 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_Norman_Battle_New_2
# 1429 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_Norman_Battle_New_5
# 1442 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanRematchDefeat
PetalburgCity_Gym_EventScript_Norman_Battle_New_1:
	return

PetalburgCity_Gym_EventScript_Norman_Battle_New_2:
# 1425 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanDefeat
	goto PetalburgCity_Gym_EventScript_Norman_Battle_New_1

PetalburgCity_Gym_EventScript_Norman_Battle_New_5:
# 1431 "data/scripts/gym_scripts.pory"
	setflag FLAG_SYS_DISABLE_SCALED_TRAINERS
# 1432 "data/scripts/gym_scripts.pory"
	random 5
# 1433 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 1434 "data/scripts/gym_scripts.pory"
	case 0, PetalburgCity_Gym_EventScript_Norman_Battle_New_9
# 1435 "data/scripts/gym_scripts.pory"
	case 1, PetalburgCity_Gym_EventScript_Norman_Battle_New_10
# 1436 "data/scripts/gym_scripts.pory"
	case 2, PetalburgCity_Gym_EventScript_Norman_Battle_New_11
# 1437 "data/scripts/gym_scripts.pory"
	case 3, PetalburgCity_Gym_EventScript_Norman_Battle_New_12
# 1438 "data/scripts/gym_scripts.pory"
	case 4, PetalburgCity_Gym_EventScript_Norman_Battle_New_13
	goto PetalburgCity_Gym_EventScript_Norman_Battle_New_1

PetalburgCity_Gym_EventScript_Norman_Battle_New_9:
# 1434 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanRematchDefeat
	goto PetalburgCity_Gym_EventScript_Norman_Battle_New_1

PetalburgCity_Gym_EventScript_Norman_Battle_New_10:
# 1435 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_2, PetalburgCity_Gym_Text_NormanRematchDefeat
	goto PetalburgCity_Gym_EventScript_Norman_Battle_New_1

PetalburgCity_Gym_EventScript_Norman_Battle_New_11:
# 1436 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_3, PetalburgCity_Gym_Text_NormanRematchDefeat
	goto PetalburgCity_Gym_EventScript_Norman_Battle_New_1

PetalburgCity_Gym_EventScript_Norman_Battle_New_12:
# 1437 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_4, PetalburgCity_Gym_Text_NormanRematchDefeat
	goto PetalburgCity_Gym_EventScript_Norman_Battle_New_1

PetalburgCity_Gym_EventScript_Norman_Battle_New_13:
# 1438 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_NORMAN_5, PetalburgCity_Gym_Text_NormanRematchDefeat
	goto PetalburgCity_Gym_EventScript_Norman_Battle_New_1


PetalburgCity_Gym_EventScript_Norman_Give_Gifts::
# 1450 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM100_CONFIDE, 1
# 1451 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_SECOND_TM_BADGES_COUNT
	goto_if_ge PetalburgCity_Gym_EventScript_Norman_Give_Gifts_3
PetalburgCity_Gym_EventScript_Norman_Give_Gifts_1:
# 1458 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM96_NATURE_POWER, 1
# 1459 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_THIRD_TM_BADGES_COUNT
	goto_if_ge PetalburgCity_Gym_EventScript_Norman_Give_Gifts_8
PetalburgCity_Gym_EventScript_Norman_Give_Gifts_6:
# 1466 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM42_FACADE, 1
# 1467 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_FOURTH_TM_BADGES_COUNT
	goto_if_ge PetalburgCity_Gym_EventScript_Norman_Give_Gifts_13
PetalburgCity_Gym_EventScript_Norman_Give_Gifts_11:
# 1474 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM68_GIGA_IMPACT, 1
# 1475 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_FIFTH_TM_BADGES_COUNT
	goto_if_ge PetalburgCity_Gym_EventScript_Norman_Give_Gifts_18
PetalburgCity_Gym_EventScript_Norman_Give_Gifts_16:
# 1482 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_MEGA_STONES_BADGES_COUNT
	goto_if_ge PetalburgCity_Gym_EventScript_Norman_Give_Gifts_25
PetalburgCity_Gym_EventScript_Norman_Give_Gifts_24:
# 1489 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, PetalburgCity_Gym_EventScript_Norman_Give_Gifts_23
PetalburgCity_Gym_EventScript_Norman_Give_Gifts_21:
# 1502 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_CheckForAllBadges
	return

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_2:
# 1452 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM100_CONFIDE
# 1453 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Norman_Give_Gifts_Text_0, MSGBOX_NPC
# 1454 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_1

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_3:
# 1451 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgCity_Gym_EventScript_Norman_Give_Gifts_2
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_1

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_7:
# 1460 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM96_NATURE_POWER
# 1461 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Norman_Give_Gifts_Text_1, MSGBOX_NPC
# 1462 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_6

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_8:
# 1459 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgCity_Gym_EventScript_Norman_Give_Gifts_7
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_6

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_12:
# 1468 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM42_FACADE
# 1469 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Norman_Give_Gifts_Text_2, MSGBOX_NPC
# 1470 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_11

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_13:
# 1467 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgCity_Gym_EventScript_Norman_Give_Gifts_12
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_11

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_17:
# 1476 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM68_GIGA_IMPACT
# 1477 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Norman_Give_Gifts_Text_3, MSGBOX_NPC
# 1478 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_16

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_18:
# 1475 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgCity_Gym_EventScript_Norman_Give_Gifts_17
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_16

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_22:
# 1483 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Norman_Give_Gifts_Text_4, MSGBOX_NPC
# 1484 "data/scripts/gym_scripts.pory"
	giveitem ITEM_KANGASKHANITE
# 1485 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Norman_Give_Gifts_Text_5, MSGBOX_NPC
# 1486 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_KANGASKHAN_MEGA_STONE
# 1487 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_21

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_23:
# 1491 "data/scripts/gym_scripts.pory"
	random 7
# 1492 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 1493 "data/scripts/gym_scripts.pory"
	case 0, PetalburgCity_Gym_EventScript_Norman_Give_Gifts_29
# 1494 "data/scripts/gym_scripts.pory"
	case 1, PetalburgCity_Gym_EventScript_Norman_Give_Gifts_30
# 1495 "data/scripts/gym_scripts.pory"
	case 2, PetalburgCity_Gym_EventScript_Norman_Give_Gifts_31
# 1496 "data/scripts/gym_scripts.pory"
	case 3, PetalburgCity_Gym_EventScript_Norman_Give_Gifts_32
# 1497 "data/scripts/gym_scripts.pory"
	case 4, PetalburgCity_Gym_EventScript_Norman_Give_Gifts_33
# 1498 "data/scripts/gym_scripts.pory"
	case 5, PetalburgCity_Gym_EventScript_Norman_Give_Gifts_34
# 1499 "data/scripts/gym_scripts.pory"
	case 6, PetalburgCity_Gym_EventScript_Norman_Give_Gifts_35
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_21

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_25:
# 1482 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_KANGASKHAN_MEGA_STONE, PetalburgCity_Gym_EventScript_Norman_Give_Gifts_22
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_24

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_29:
# 1493 "data/scripts/gym_scripts.pory"
	giveitem ITEM_NORMAL_GEM, 2
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_21

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_30:
# 1494 "data/scripts/gym_scripts.pory"
	giveitem ITEM_CHILAN_BERRY, 5
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_21

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_31:
# 1495 "data/scripts/gym_scripts.pory"
	giveitem ITEM_SILK_SCARF, 2
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_21

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_32:
# 1496 "data/scripts/gym_scripts.pory"
	giveitem ITEM_LUCKY_EGG, 2
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_21

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_33:
# 1497 "data/scripts/gym_scripts.pory"
	giveitem ITEM_NUGGET, 2
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_21

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_34:
# 1498 "data/scripts/gym_scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES, 2
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_21

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_35:
# 1499 "data/scripts/gym_scripts.pory"
	giveitem ITEM_QUICK_POWDER, 2
	goto PetalburgCity_Gym_EventScript_Norman_Give_Gifts_21


PetalburgCity_Gym_EventScript_GymGuide_New::
# 1507 "data/scripts/gym_scripts.pory"
	lock
# 1508 "data/scripts/gym_scripts.pory"
	faceplayer
# 1510 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymGuide_New_2
# 1526 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice, MSGBOX_NPC
PetalburgCity_Gym_EventScript_GymGuide_New_1:
# 1528 "data/scripts/gym_scripts.pory"
	release
	end

PetalburgCity_Gym_EventScript_GymGuide_New_2:
# 1511 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_NORMAN_REMATCH, PetalburgCity_Gym_EventScript_GymGuide_New_5
# 1522 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_Text_GymGuidePostVictory, MSGBOX_NPC
	goto PetalburgCity_Gym_EventScript_GymGuide_New_1

PetalburgCity_Gym_EventScript_GymGuide_New_5:
# 1512 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_0, MSGBOX_YESNO
# 1513 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_GymGuide_New_8
# 1518 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_2, MSGBOX_NPC
	goto PetalburgCity_Gym_EventScript_GymGuide_New_1

PetalburgCity_Gym_EventScript_GymGuide_New_8:
# 1514 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_1, MSGBOX_NPC
# 1515 "data/scripts/gym_scripts.pory"
	warp MAP_PETALBURG_CITY_GYM, 255, 4, 3
	goto PetalburgCity_Gym_EventScript_GymGuide_New_1


PetalburgCity_Gym_EventScript_Gym_Slakoth::
# 1533 "data/scripts/gym_scripts.pory"
	lock
# 1534 "data/scripts/gym_scripts.pory"
	faceplayer
# 1535 "data/scripts/gym_scripts.pory"
	switch VAR_GYM_POKEMON_SPECIES
# 1536 "data/scripts/gym_scripts.pory"
	case SPECIES_SLAKOTH, PetalburgCity_Gym_EventScript_Gym_Slakoth_3
# 1554 "data/scripts/gym_scripts.pory"
	case SPECIES_VIGOROTH, PetalburgCity_Gym_EventScript_Gym_Slakoth_4
# 1572 "data/scripts/gym_scripts.pory"
	case SPECIES_SLAKING, PetalburgCity_Gym_EventScript_Gym_Slakoth_5
PetalburgCity_Gym_EventScript_Gym_Slakoth_1:
# 1590 "data/scripts/gym_scripts.pory"
	release
	end

PetalburgCity_Gym_EventScript_Gym_Slakoth_3:
# 1537 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_Gym_Slakoth_12
PetalburgCity_Gym_EventScript_Gym_Slakoth_10:
# 1543 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_Gym_Slakoth_9
PetalburgCity_Gym_EventScript_Gym_Slakoth_8:
# 1550 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_4, MSGBOX_NPC
# 1551 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_5, MSGBOX_SIGN
# 1552 "data/scripts/gym_scripts.pory"
	waitmessage
	goto PetalburgCity_Gym_EventScript_Gym_Slakoth_1

PetalburgCity_Gym_EventScript_Gym_Slakoth_4:
# 1555 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_Gym_Slakoth_21
PetalburgCity_Gym_EventScript_Gym_Slakoth_19:
# 1561 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_Gym_Slakoth_18
PetalburgCity_Gym_EventScript_Gym_Slakoth_17:
# 1568 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_9, MSGBOX_NPC
# 1569 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_10, MSGBOX_SIGN
# 1570 "data/scripts/gym_scripts.pory"
	waitmessage
	goto PetalburgCity_Gym_EventScript_Gym_Slakoth_1

PetalburgCity_Gym_EventScript_Gym_Slakoth_5:
# 1573 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_Gym_Slakoth_30
PetalburgCity_Gym_EventScript_Gym_Slakoth_28:
# 1579 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_Gym_Slakoth_27
PetalburgCity_Gym_EventScript_Gym_Slakoth_26:
# 1585 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_15, MSGBOX_NPC
# 1586 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_16, MSGBOX_SIGN
# 1587 "data/scripts/gym_scripts.pory"
	waitmessage
	goto PetalburgCity_Gym_EventScript_Gym_Slakoth_1

PetalburgCity_Gym_EventScript_Gym_Slakoth_6:
# 1539 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_0, MSGBOX_NPC
# 1540 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_1, MSGBOX_SIGN
# 1541 "data/scripts/gym_scripts.pory"
	waitmessage
	goto PetalburgCity_Gym_EventScript_Gym_Slakoth_1

PetalburgCity_Gym_EventScript_Gym_Slakoth_7:
# 1545 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_2, MSGBOX_NPC
# 1546 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_3, MSGBOX_SIGN
# 1547 "data/scripts/gym_scripts.pory"
	waitmessage
	goto PetalburgCity_Gym_EventScript_Gym_Slakoth_1

PetalburgCity_Gym_EventScript_Gym_Slakoth_9:
# 1543 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_NORMAN_REMATCH, PetalburgCity_Gym_EventScript_Gym_Slakoth_7
	goto PetalburgCity_Gym_EventScript_Gym_Slakoth_8

PetalburgCity_Gym_EventScript_Gym_Slakoth_12:
# 1537 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_NORMAN_REMATCH, PetalburgCity_Gym_EventScript_Gym_Slakoth_6
	goto PetalburgCity_Gym_EventScript_Gym_Slakoth_10

PetalburgCity_Gym_EventScript_Gym_Slakoth_15:
# 1557 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_6, MSGBOX_NPC
# 1558 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_7, MSGBOX_SIGN
# 1559 "data/scripts/gym_scripts.pory"
	waitmessage
	goto PetalburgCity_Gym_EventScript_Gym_Slakoth_1

PetalburgCity_Gym_EventScript_Gym_Slakoth_16:
# 1563 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_8, MSGBOX_NPC
# 1564 "data/scripts/gym_scripts.pory"
	msgbox MauvilleCity_Gym_EventScript_Gym_Electrike_Text_3, MSGBOX_SIGN
# 1565 "data/scripts/gym_scripts.pory"
	waitmessage
	goto PetalburgCity_Gym_EventScript_Gym_Slakoth_1

PetalburgCity_Gym_EventScript_Gym_Slakoth_18:
# 1561 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_NORMAN_REMATCH, PetalburgCity_Gym_EventScript_Gym_Slakoth_16
	goto PetalburgCity_Gym_EventScript_Gym_Slakoth_17

PetalburgCity_Gym_EventScript_Gym_Slakoth_21:
# 1555 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_NORMAN_REMATCH, PetalburgCity_Gym_EventScript_Gym_Slakoth_15
	goto PetalburgCity_Gym_EventScript_Gym_Slakoth_19

PetalburgCity_Gym_EventScript_Gym_Slakoth_24:
# 1575 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_11, MSGBOX_NPC
# 1576 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_12, MSGBOX_SIGN
# 1577 "data/scripts/gym_scripts.pory"
	waitmessage
	goto PetalburgCity_Gym_EventScript_Gym_Slakoth_1

PetalburgCity_Gym_EventScript_Gym_Slakoth_25:
# 1580 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_13, MSGBOX_NPC
# 1581 "data/scripts/gym_scripts.pory"
	msgbox PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_14, MSGBOX_SIGN
# 1582 "data/scripts/gym_scripts.pory"
	waitmessage
	goto PetalburgCity_Gym_EventScript_Gym_Slakoth_1

PetalburgCity_Gym_EventScript_Gym_Slakoth_27:
# 1579 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_NORMAN_REMATCH, PetalburgCity_Gym_EventScript_Gym_Slakoth_25
	goto PetalburgCity_Gym_EventScript_Gym_Slakoth_26

PetalburgCity_Gym_EventScript_Gym_Slakoth_30:
# 1573 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_NORMAN_REMATCH, PetalburgCity_Gym_EventScript_Gym_Slakoth_24
	goto PetalburgCity_Gym_EventScript_Gym_Slakoth_28


PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species::
# 1595 "data/scripts/gym_scripts.pory"
	setflag FLAG_HIDE_GYM_MONS
# 1596 "data/scripts/gym_scripts.pory"
	switch VAR_NUM_BADGES
# 1597 "data/scripts/gym_scripts.pory"
	case 0, PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_3
# 1598 "data/scripts/gym_scripts.pory"
	case 1, PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_4
# 1599 "data/scripts/gym_scripts.pory"
	case 2, PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_5
# 1600 "data/scripts/gym_scripts.pory"
	case 3, PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_6
# 1601 "data/scripts/gym_scripts.pory"
	case 4, PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_7
# 1602 "data/scripts/gym_scripts.pory"
	case 5, PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_8
# 1603 "data/scripts/gym_scripts.pory"
	case 6, PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_9
# 1604 "data/scripts/gym_scripts.pory"
	case 7, PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_10
# 1605 "data/scripts/gym_scripts.pory"
	case 8, PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_11
PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_1:
# 1609 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_NO_EVOLUTION_MODE, PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_13
# 1609 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_LITTLE_CUP_MODE, PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_13
PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_12:
	return

PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_3:
# 1597 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_SLAKOTH
# 1597 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_SLAKOTH
	goto PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_4:
# 1598 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_VIGOROTH
# 1598 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_VIGOROTH
	goto PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_5:
# 1599 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_VIGOROTH
# 1599 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_VIGOROTH
	goto PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_6:
# 1600 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_VIGOROTH
# 1600 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_VIGOROTH
	goto PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_7:
# 1601 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_SLAKING
# 1601 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_SLAKING
	goto PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_8:
# 1602 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_SLAKING
# 1602 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_SLAKING
	goto PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_9:
# 1603 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_SLAKING
# 1603 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_SLAKING
	goto PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_10:
# 1604 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_SLAKING
# 1604 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_SLAKING
	goto PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_11:
# 1605 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_SLAKING
# 1605 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_SLAKING
	goto PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_13:
# 1610 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_SLAKOTH
# 1610 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_SLAKOTH
	goto PetalburgCity_Gym_EventScript_Set_Gym_Pokemon_Species_12


FortreeCity_Gym_EventScript_Winona_New::
# 1617 "data/scripts/gym_scripts.pory"
	lock
# 1618 "data/scripts/gym_scripts.pory"
	faceplayer
# 1619 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_Winona_New_8
FortreeCity_Gym_EventScript_Winona_New_6:
# 1639 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_Winona_New_5
FortreeCity_Gym_EventScript_Winona_New_4:
# 1656 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_Text_WinonaIntro, MSGBOX_NPC
# 1658 "data/scripts/gym_scripts.pory"
	call FortreeCity_Gym_EventScript_Winona_Battle_New
# 1661 "data/scripts/gym_scripts.pory"
	message FortreeCity_Gym_EventScript_Winona_New_Text_3
# 1662 "data/scripts/gym_scripts.pory"
	waitmessage
# 1663 "data/scripts/gym_scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 1664 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_5, MSGBOX_NPC
# 1665 "data/scripts/gym_scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 1666 "data/scripts/gym_scripts.pory"
	setflag FLAG_BADGE06_GET
# 1669 "data/scripts/gym_scripts.pory"
	call Special_Gym_EventScript_Give_Item
# 1672 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM58_ROOST
# 1673 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Winona_New_Text_4, MSGBOX_NPC
# 1675 "data/scripts/gym_scripts.pory"
	waitfanfare
# 1676 "data/scripts/gym_scripts.pory"
	closemessage
# 1677 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 1680 "data/scripts/gym_scripts.pory"
	call FortreeCity_Gym_EventScript_Winona_Give_Gifts
# 1683 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 6
# 1684 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 1687 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
# 1688 "data/scripts/gym_scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1689 "data/scripts/gym_scripts.pory"
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
# 1690 "data/scripts/gym_scripts.pory"
	waitfanfare
# 1691 "data/scripts/gym_scripts.pory"
	closemessage
# 1694 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_NPC
# 1695 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 1698 "data/scripts/gym_scripts.pory"
	setflag FLAG_WINONA_REMATCH
FortreeCity_Gym_EventScript_Winona_New_1:
# 1700 "data/scripts/gym_scripts.pory"
	release
	end

FortreeCity_Gym_EventScript_Winona_New_2:
# 1622 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_Text_WinonaPreRematch, MSGBOX_NPC
# 1624 "data/scripts/gym_scripts.pory"
	call FortreeCity_Gym_EventScript_Winona_Battle_New
# 1627 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_NPC
# 1628 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 1631 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
# 1632 "data/scripts/gym_scripts.pory"
	call FortreeCity_Gym_EventScript_Winona_Give_Gifts
# 1634 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Winona_New_Text_0, MSGBOX_NPC
# 1637 "data/scripts/gym_scripts.pory"
	setflag FLAG_WINONA_REMATCH
	goto FortreeCity_Gym_EventScript_Winona_New_1

FortreeCity_Gym_EventScript_Winona_New_3:
# 1641 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Winona_New_Text_1, MSGBOX_YESNO
# 1642 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FortreeCity_Gym_EventScript_Winona_New_11
# 1648 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 6
# 1649 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 1650 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Winona_New_Text_0, MSGBOX_NPC
	goto FortreeCity_Gym_EventScript_Winona_New_1

FortreeCity_Gym_EventScript_Winona_New_5:
# 1639 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_WINONA_REMATCH, FortreeCity_Gym_EventScript_Winona_New_3
	goto FortreeCity_Gym_EventScript_Winona_New_4

FortreeCity_Gym_EventScript_Winona_New_8:
# 1619 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_WINONA_REMATCH, FortreeCity_Gym_EventScript_Winona_New_2
	goto FortreeCity_Gym_EventScript_Winona_New_6

FortreeCity_Gym_EventScript_Winona_New_11:
# 1643 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 6
# 1644 "data/scripts/gym_scripts.pory"
	call Common_EventScript_ClearGymTrainers
# 1645 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Winona_New_Text_2, MSGBOX_NPC
	goto FortreeCity_Gym_EventScript_Winona_New_1


FortreeCity_Gym_EventScript_Winona_Battle_New::
# 1705 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_Winona_Battle_New_2
# 1711 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, FortreeCity_Gym_EventScript_Winona_Battle_New_5
# 1724 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaRematchDefeat
FortreeCity_Gym_EventScript_Winona_Battle_New_1:
	return

FortreeCity_Gym_EventScript_Winona_Battle_New_2:
# 1707 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaDefeat
	goto FortreeCity_Gym_EventScript_Winona_Battle_New_1

FortreeCity_Gym_EventScript_Winona_Battle_New_5:
# 1713 "data/scripts/gym_scripts.pory"
	setflag FLAG_SYS_DISABLE_SCALED_TRAINERS
# 1714 "data/scripts/gym_scripts.pory"
	random 5
# 1715 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 1716 "data/scripts/gym_scripts.pory"
	case 0, FortreeCity_Gym_EventScript_Winona_Battle_New_9
# 1717 "data/scripts/gym_scripts.pory"
	case 1, FortreeCity_Gym_EventScript_Winona_Battle_New_10
# 1718 "data/scripts/gym_scripts.pory"
	case 2, FortreeCity_Gym_EventScript_Winona_Battle_New_11
# 1719 "data/scripts/gym_scripts.pory"
	case 3, FortreeCity_Gym_EventScript_Winona_Battle_New_12
# 1720 "data/scripts/gym_scripts.pory"
	case 4, FortreeCity_Gym_EventScript_Winona_Battle_New_13
	goto FortreeCity_Gym_EventScript_Winona_Battle_New_1

FortreeCity_Gym_EventScript_Winona_Battle_New_9:
# 1716 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaRematchDefeat
	goto FortreeCity_Gym_EventScript_Winona_Battle_New_1

FortreeCity_Gym_EventScript_Winona_Battle_New_10:
# 1717 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_WINONA_2, FortreeCity_Gym_Text_WinonaRematchDefeat
	goto FortreeCity_Gym_EventScript_Winona_Battle_New_1

FortreeCity_Gym_EventScript_Winona_Battle_New_11:
# 1718 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_WINONA_3, FortreeCity_Gym_Text_WinonaRematchDefeat
	goto FortreeCity_Gym_EventScript_Winona_Battle_New_1

FortreeCity_Gym_EventScript_Winona_Battle_New_12:
# 1719 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_WINONA_4, FortreeCity_Gym_Text_WinonaRematchDefeat
	goto FortreeCity_Gym_EventScript_Winona_Battle_New_1

FortreeCity_Gym_EventScript_Winona_Battle_New_13:
# 1720 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_WINONA_5, FortreeCity_Gym_Text_WinonaRematchDefeat
	goto FortreeCity_Gym_EventScript_Winona_Battle_New_1


FortreeCity_Gym_EventScript_Winona_Give_Gifts::
# 1732 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM40_AERIAL_ACE, 1
# 1733 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_SECOND_TM_BADGES_COUNT
	goto_if_ge FortreeCity_Gym_EventScript_Winona_Give_Gifts_3
FortreeCity_Gym_EventScript_Winona_Give_Gifts_1:
# 1740 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM62_ACROBATICS, 1
# 1741 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_THIRD_TM_BADGES_COUNT
	goto_if_ge FortreeCity_Gym_EventScript_Winona_Give_Gifts_8
FortreeCity_Gym_EventScript_Winona_Give_Gifts_6:
# 1748 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM76_FLY, 1
# 1749 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_FOURTH_TM_BADGES_COUNT
	goto_if_ge FortreeCity_Gym_EventScript_Winona_Give_Gifts_13
FortreeCity_Gym_EventScript_Winona_Give_Gifts_11:
# 1756 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM114_BRAVE_BIRD, 1
# 1757 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_FIFTH_TM_BADGES_COUNT
	goto_if_ge FortreeCity_Gym_EventScript_Winona_Give_Gifts_18
FortreeCity_Gym_EventScript_Winona_Give_Gifts_16:
# 1764 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_MEGA_STONES_BADGES_COUNT
	goto_if_ge FortreeCity_Gym_EventScript_Winona_Give_Gifts_25
FortreeCity_Gym_EventScript_Winona_Give_Gifts_24:
# 1771 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, FortreeCity_Gym_EventScript_Winona_Give_Gifts_23
FortreeCity_Gym_EventScript_Winona_Give_Gifts_21:
# 1784 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_CheckForAllBadges
	return

FortreeCity_Gym_EventScript_Winona_Give_Gifts_2:
# 1734 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM40_AERIAL_ACE
# 1735 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Winona_Give_Gifts_Text_0, MSGBOX_NPC
# 1736 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_1

FortreeCity_Gym_EventScript_Winona_Give_Gifts_3:
# 1733 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FortreeCity_Gym_EventScript_Winona_Give_Gifts_2
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_1

FortreeCity_Gym_EventScript_Winona_Give_Gifts_7:
# 1742 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM62_ACROBATICS
# 1743 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Winona_Give_Gifts_Text_1, MSGBOX_NPC
# 1744 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_6

FortreeCity_Gym_EventScript_Winona_Give_Gifts_8:
# 1741 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FortreeCity_Gym_EventScript_Winona_Give_Gifts_7
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_6

FortreeCity_Gym_EventScript_Winona_Give_Gifts_12:
# 1750 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM76_FLY
# 1751 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Winona_Give_Gifts_Text_2, MSGBOX_NPC
# 1752 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_11

FortreeCity_Gym_EventScript_Winona_Give_Gifts_13:
# 1749 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FortreeCity_Gym_EventScript_Winona_Give_Gifts_12
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_11

FortreeCity_Gym_EventScript_Winona_Give_Gifts_17:
# 1758 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM114_BRAVE_BIRD
# 1759 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Winona_Give_Gifts_Text_3, MSGBOX_NPC
# 1760 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_16

FortreeCity_Gym_EventScript_Winona_Give_Gifts_18:
# 1757 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FortreeCity_Gym_EventScript_Winona_Give_Gifts_17
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_16

FortreeCity_Gym_EventScript_Winona_Give_Gifts_22:
# 1765 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Winona_Give_Gifts_Text_4, MSGBOX_NPC
# 1766 "data/scripts/gym_scripts.pory"
	giveitem ITEM_ALTARIANITE
# 1767 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Winona_Give_Gifts_Text_5, MSGBOX_NPC
# 1768 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_ALTARIA_MEGA_STONE
# 1769 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_21

FortreeCity_Gym_EventScript_Winona_Give_Gifts_23:
# 1773 "data/scripts/gym_scripts.pory"
	random 7
# 1774 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 1775 "data/scripts/gym_scripts.pory"
	case 0, FortreeCity_Gym_EventScript_Winona_Give_Gifts_29
# 1776 "data/scripts/gym_scripts.pory"
	case 1, FortreeCity_Gym_EventScript_Winona_Give_Gifts_30
# 1777 "data/scripts/gym_scripts.pory"
	case 2, FortreeCity_Gym_EventScript_Winona_Give_Gifts_31
# 1778 "data/scripts/gym_scripts.pory"
	case 3, FortreeCity_Gym_EventScript_Winona_Give_Gifts_32
# 1779 "data/scripts/gym_scripts.pory"
	case 4, FortreeCity_Gym_EventScript_Winona_Give_Gifts_33
# 1780 "data/scripts/gym_scripts.pory"
	case 5, FortreeCity_Gym_EventScript_Winona_Give_Gifts_34
# 1781 "data/scripts/gym_scripts.pory"
	case 6, FortreeCity_Gym_EventScript_Winona_Give_Gifts_35
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_21

FortreeCity_Gym_EventScript_Winona_Give_Gifts_25:
# 1764 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_ALTARIA_MEGA_STONE, FortreeCity_Gym_EventScript_Winona_Give_Gifts_22
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_24

FortreeCity_Gym_EventScript_Winona_Give_Gifts_29:
# 1775 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FLYING_GEM, 2
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_21

FortreeCity_Gym_EventScript_Winona_Give_Gifts_30:
# 1776 "data/scripts/gym_scripts.pory"
	giveitem ITEM_POWER_HERB, 2
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_21

FortreeCity_Gym_EventScript_Winona_Give_Gifts_31:
# 1777 "data/scripts/gym_scripts.pory"
	giveitem ITEM_AIR_BALLOON, 2
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_21

FortreeCity_Gym_EventScript_Winona_Give_Gifts_32:
# 1778 "data/scripts/gym_scripts.pory"
	giveitem ITEM_SWIFT_WING, 2
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_21

FortreeCity_Gym_EventScript_Winona_Give_Gifts_33:
# 1779 "data/scripts/gym_scripts.pory"
	giveitem ITEM_SHARP_BEAK, 5
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_21

FortreeCity_Gym_EventScript_Winona_Give_Gifts_34:
# 1780 "data/scripts/gym_scripts.pory"
	giveitem ITEM_COBA_BERRY, 2
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_21

FortreeCity_Gym_EventScript_Winona_Give_Gifts_35:
# 1781 "data/scripts/gym_scripts.pory"
	giveitem ITEM_GREPA_BERRY, 2
	goto FortreeCity_Gym_EventScript_Winona_Give_Gifts_21


FortreeCity_Gym_EventScript_GymGuide_New::
# 1789 "data/scripts/gym_scripts.pory"
	lock
# 1790 "data/scripts/gym_scripts.pory"
	faceplayer
# 1791 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuide_New_2
# 1807 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_NPC
FortreeCity_Gym_EventScript_GymGuide_New_1:
# 1809 "data/scripts/gym_scripts.pory"
	release
	end

FortreeCity_Gym_EventScript_GymGuide_New_2:
# 1792 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_WINONA_REMATCH, FortreeCity_Gym_EventScript_GymGuide_New_5
# 1803 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_NPC
	goto FortreeCity_Gym_EventScript_GymGuide_New_1

FortreeCity_Gym_EventScript_GymGuide_New_5:
# 1793 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_0, MSGBOX_YESNO
# 1794 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FortreeCity_Gym_EventScript_GymGuide_New_8
# 1799 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_2, MSGBOX_NPC
	goto FortreeCity_Gym_EventScript_GymGuide_New_1

FortreeCity_Gym_EventScript_GymGuide_New_8:
# 1795 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_1, MSGBOX_NPC
# 1796 "data/scripts/gym_scripts.pory"
	warp MAP_FORTREE_CITY_GYM, 255, 15, 3
	goto FortreeCity_Gym_EventScript_GymGuide_New_1


FortreeCity_Gym_EventScript_Gym_Taillow::
# 1814 "data/scripts/gym_scripts.pory"
	lock
# 1815 "data/scripts/gym_scripts.pory"
	faceplayer
# 1816 "data/scripts/gym_scripts.pory"
	switch VAR_GYM_POKEMON_SPECIES
# 1817 "data/scripts/gym_scripts.pory"
	case SPECIES_TAILLOW, FortreeCity_Gym_EventScript_Gym_Taillow_3
# 1835 "data/scripts/gym_scripts.pory"
	case SPECIES_SWELLOW, FortreeCity_Gym_EventScript_Gym_Taillow_4
FortreeCity_Gym_EventScript_Gym_Taillow_1:
# 1853 "data/scripts/gym_scripts.pory"
	release
	end

FortreeCity_Gym_EventScript_Gym_Taillow_3:
# 1818 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_Gym_Taillow_11
FortreeCity_Gym_EventScript_Gym_Taillow_9:
# 1824 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_Gym_Taillow_8
FortreeCity_Gym_EventScript_Gym_Taillow_7:
# 1831 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Gym_Taillow_Text_4, MSGBOX_NPC
# 1832 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Gym_Taillow_Text_5, MSGBOX_SIGN
# 1833 "data/scripts/gym_scripts.pory"
	waitmessage
	goto FortreeCity_Gym_EventScript_Gym_Taillow_1

FortreeCity_Gym_EventScript_Gym_Taillow_4:
# 1836 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_Gym_Taillow_20
FortreeCity_Gym_EventScript_Gym_Taillow_18:
# 1842 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_Gym_Taillow_17
FortreeCity_Gym_EventScript_Gym_Taillow_16:
# 1848 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Gym_Taillow_Text_10, MSGBOX_NPC
# 1849 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Gym_Taillow_Text_11, MSGBOX_SIGN
# 1850 "data/scripts/gym_scripts.pory"
	waitmessage
	goto FortreeCity_Gym_EventScript_Gym_Taillow_1

FortreeCity_Gym_EventScript_Gym_Taillow_5:
# 1820 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Gym_Taillow_Text_0, MSGBOX_NPC
# 1821 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Gym_Taillow_Text_1, MSGBOX_SIGN
# 1822 "data/scripts/gym_scripts.pory"
	waitmessage
	goto FortreeCity_Gym_EventScript_Gym_Taillow_1

FortreeCity_Gym_EventScript_Gym_Taillow_6:
# 1826 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Gym_Taillow_Text_2, MSGBOX_NPC
# 1827 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Gym_Taillow_Text_3, MSGBOX_SIGN
# 1828 "data/scripts/gym_scripts.pory"
	waitmessage
	goto FortreeCity_Gym_EventScript_Gym_Taillow_1

FortreeCity_Gym_EventScript_Gym_Taillow_8:
# 1824 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_WINONA_REMATCH, FortreeCity_Gym_EventScript_Gym_Taillow_6
	goto FortreeCity_Gym_EventScript_Gym_Taillow_7

FortreeCity_Gym_EventScript_Gym_Taillow_11:
# 1818 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_WINONA_REMATCH, FortreeCity_Gym_EventScript_Gym_Taillow_5
	goto FortreeCity_Gym_EventScript_Gym_Taillow_9

FortreeCity_Gym_EventScript_Gym_Taillow_14:
# 1838 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Gym_Taillow_Text_6, MSGBOX_NPC
# 1839 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Gym_Taillow_Text_7, MSGBOX_SIGN
# 1840 "data/scripts/gym_scripts.pory"
	waitmessage
	goto FortreeCity_Gym_EventScript_Gym_Taillow_1

FortreeCity_Gym_EventScript_Gym_Taillow_15:
# 1843 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Gym_Taillow_Text_8, MSGBOX_NPC
# 1844 "data/scripts/gym_scripts.pory"
	msgbox FortreeCity_Gym_EventScript_Gym_Taillow_Text_9, MSGBOX_SIGN
# 1845 "data/scripts/gym_scripts.pory"
	waitmessage
	goto FortreeCity_Gym_EventScript_Gym_Taillow_1

FortreeCity_Gym_EventScript_Gym_Taillow_17:
# 1842 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_WINONA_REMATCH, FortreeCity_Gym_EventScript_Gym_Taillow_15
	goto FortreeCity_Gym_EventScript_Gym_Taillow_16

FortreeCity_Gym_EventScript_Gym_Taillow_20:
# 1836 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_WINONA_REMATCH, FortreeCity_Gym_EventScript_Gym_Taillow_14
	goto FortreeCity_Gym_EventScript_Gym_Taillow_18


FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species::
# 1858 "data/scripts/gym_scripts.pory"
	setflag FLAG_HIDE_GYM_MONS
# 1859 "data/scripts/gym_scripts.pory"
	switch VAR_NUM_BADGES
# 1860 "data/scripts/gym_scripts.pory"
	case 0, FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_3
# 1861 "data/scripts/gym_scripts.pory"
	case 1, FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_4
# 1862 "data/scripts/gym_scripts.pory"
	case 2, FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_5
# 1863 "data/scripts/gym_scripts.pory"
	case 3, FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_6
# 1864 "data/scripts/gym_scripts.pory"
	case 4, FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_7
# 1865 "data/scripts/gym_scripts.pory"
	case 5, FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_8
# 1866 "data/scripts/gym_scripts.pory"
	case 6, FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_9
# 1867 "data/scripts/gym_scripts.pory"
	case 7, FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_10
# 1868 "data/scripts/gym_scripts.pory"
	case 8, FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_11
FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_1:
# 1871 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_NO_EVOLUTION_MODE, FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_13
# 1871 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_LITTLE_CUP_MODE, FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_13
FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_12:
	return

FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_3:
# 1860 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_TAILLOW
# 1860 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_TAILLOW
	goto FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_4:
# 1861 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_TAILLOW
# 1861 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_TAILLOW
	goto FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_5:
# 1862 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_TAILLOW
# 1862 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_TAILLOW
	goto FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_6:
# 1863 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_SWELLOW
# 1863 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_SWELLOW
	goto FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_7:
# 1864 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_SWELLOW
# 1864 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_SWELLOW
	goto FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_8:
# 1865 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_SWELLOW
# 1865 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_SWELLOW
	goto FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_9:
# 1866 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_SWELLOW
# 1866 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_SWELLOW
	goto FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_10:
# 1867 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_SWELLOW
# 1867 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_SWELLOW
	goto FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_11:
# 1868 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_SWELLOW
# 1868 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_SWELLOW
	goto FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_1

FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_13:
# 1872 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_TAILLOW
# 1872 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_TAILLOW
	goto FortreeCity_Gym_EventScript_Set_Gym_Pokemon_Species_12


MossdeepCity_Gym_EventScript_TateAndLiza_New::
# 1878 "data/scripts/gym_scripts.pory"
	lock
# 1879 "data/scripts/gym_scripts.pory"
	faceplayer
# 1880 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_TateAndLiza_New_8
MossdeepCity_Gym_EventScript_TateAndLiza_New_6:
# 1902 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_TateAndLiza_New_5
MossdeepCity_Gym_EventScript_TateAndLiza_New_4:
# 1923 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_Text_TateAndLizaIntro, MSGBOX_NPC
# 1925 "data/scripts/gym_scripts.pory"
	call MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New
# 1928 "data/scripts/gym_scripts.pory"
	message MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_9
# 1929 "data/scripts/gym_scripts.pory"
	waitmessage
# 1930 "data/scripts/gym_scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 1931 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_5, MSGBOX_NPC
# 1932 "data/scripts/gym_scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 1933 "data/scripts/gym_scripts.pory"
	setflag FLAG_BADGE07_GET
# 1936 "data/scripts/gym_scripts.pory"
	call Special_Gym_EventScript_Give_Item
# 1939 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM04_CALM_MIND
# 1940 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_10, MSGBOX_NPC
# 1942 "data/scripts/gym_scripts.pory"
	waitfanfare
# 1943 "data/scripts/gym_scripts.pory"
	closemessage
# 1944 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 1947 "data/scripts/gym_scripts.pory"
	call MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts
# 1950 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 7
# 1951 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 1954 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
# 1955 "data/scripts/gym_scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1956 "data/scripts/gym_scripts.pory"
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
# 1957 "data/scripts/gym_scripts.pory"
	waitfanfare
# 1958 "data/scripts/gym_scripts.pory"
	closemessage
# 1961 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_NPC
# 1962 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 1965 "data/scripts/gym_scripts.pory"
	setflag FLAG_TATE_AND_LIZA_REMATCH
MossdeepCity_Gym_EventScript_TateAndLiza_New_1:
# 1967 "data/scripts/gym_scripts.pory"
	release
	end

MossdeepCity_Gym_EventScript_TateAndLiza_New_2:
# 1883 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_Text_TateAndLizaPreRematch, MSGBOX_NPC
# 1885 "data/scripts/gym_scripts.pory"
	call MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New
# 1888 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_NPC
# 1889 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 1892 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_0, MSGBOX_NPC
# 1893 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_1, MSGBOX_NPC
# 1894 "data/scripts/gym_scripts.pory"
	call MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts
# 1896 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_2, MSGBOX_NPC
# 1897 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_3, MSGBOX_NPC
# 1900 "data/scripts/gym_scripts.pory"
	setflag FLAG_TATE_AND_LIZA_REMATCH
	goto MossdeepCity_Gym_EventScript_TateAndLiza_New_1

MossdeepCity_Gym_EventScript_TateAndLiza_New_3:
# 1904 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_4, MSGBOX_NPC
# 1905 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_5, MSGBOX_NPC
# 1906 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_6, MSGBOX_YESNO
# 1907 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MossdeepCity_Gym_EventScript_TateAndLiza_New_11
# 1914 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 7
# 1915 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 1916 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_2, MSGBOX_NPC
# 1917 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_3, MSGBOX_NPC
	goto MossdeepCity_Gym_EventScript_TateAndLiza_New_1

MossdeepCity_Gym_EventScript_TateAndLiza_New_5:
# 1902 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_TATE_AND_LIZA_REMATCH, MossdeepCity_Gym_EventScript_TateAndLiza_New_3
	goto MossdeepCity_Gym_EventScript_TateAndLiza_New_4

MossdeepCity_Gym_EventScript_TateAndLiza_New_8:
# 1880 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TATE_AND_LIZA_REMATCH, MossdeepCity_Gym_EventScript_TateAndLiza_New_2
	goto MossdeepCity_Gym_EventScript_TateAndLiza_New_6

MossdeepCity_Gym_EventScript_TateAndLiza_New_11:
# 1908 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 7
# 1909 "data/scripts/gym_scripts.pory"
	call Common_EventScript_ClearGymTrainers
# 1910 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_7, MSGBOX_NPC
# 1911 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_8, MSGBOX_NPC
	goto MossdeepCity_Gym_EventScript_TateAndLiza_New_1


MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New::
# 1972 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_2
# 1978 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_5
# 1991 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat
MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_1:
	return

MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_2:
# 1974 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaDefeat
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_1

MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_5:
# 1980 "data/scripts/gym_scripts.pory"
	setflag FLAG_SYS_DISABLE_SCALED_TRAINERS
# 1981 "data/scripts/gym_scripts.pory"
	random 5
# 1982 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 1983 "data/scripts/gym_scripts.pory"
	case 0, MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_9
# 1984 "data/scripts/gym_scripts.pory"
	case 1, MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_10
# 1985 "data/scripts/gym_scripts.pory"
	case 2, MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_11
# 1986 "data/scripts/gym_scripts.pory"
	case 3, MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_12
# 1987 "data/scripts/gym_scripts.pory"
	case 4, MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_13
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_1

MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_9:
# 1983 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_1

MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_10:
# 1984 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_TATE_AND_LIZA_2, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_1

MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_11:
# 1985 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_TATE_AND_LIZA_3, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_1

MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_12:
# 1986 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_TATE_AND_LIZA_4, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_1

MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_13:
# 1987 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_TATE_AND_LIZA_5, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Battle_New_1


MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts::
# 1999 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM85_DREAM_EATER, 1
# 2000 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_SECOND_TM_BADGES_COUNT
	goto_if_ge MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_3
MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_1:
# 2008 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM92_TRICK_ROOM, 1
# 2009 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_THIRD_TM_BADGES_COUNT
	goto_if_ge MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_8
MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_6:
# 2017 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM105_PSYSHOCK, 1
# 2018 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_FOURTH_TM_BADGES_COUNT
	goto_if_ge MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_13
MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_11:
# 2034 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_MEGA_STONES_BADGES_COUNT
	goto_if_ge MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_20
MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_19:
# 2042 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_18
MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_16:
# 2055 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_CheckForAllBadges
	return

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_2:
# 2001 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM85_DREAM_EATER
# 2002 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_Text_0, MSGBOX_NPC
# 2003 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_Text_1, MSGBOX_NPC
# 2004 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_1

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_3:
# 2000 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_2
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_1

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_7:
# 2010 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM92_TRICK_ROOM
# 2011 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_Text_2, MSGBOX_NPC
# 2012 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_Text_3, MSGBOX_NPC
# 2013 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_6

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_8:
# 2009 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_7
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_6

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_12:
# 2019 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM105_PSYSHOCK
# 2020 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_Text_4, MSGBOX_NPC
# 2021 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_Text_5, MSGBOX_NPC
# 2022 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_11

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_13:
# 2018 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_12
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_11

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_17:
# 2035 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_Text_6, MSGBOX_NPC
# 2036 "data/scripts/gym_scripts.pory"
	giveitem ITEM_GARDEVOIRITE
# 2037 "data/scripts/gym_scripts.pory"
	giveitem ITEM_GALLADITE
# 2038 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_Text_7, MSGBOX_NPC
# 2039 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_GARDEVOIR_MEGA_STONE
# 2040 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_16

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_18:
# 2044 "data/scripts/gym_scripts.pory"
	random 7
# 2045 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 2046 "data/scripts/gym_scripts.pory"
	case 0, MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_24
# 2047 "data/scripts/gym_scripts.pory"
	case 1, MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_25
# 2048 "data/scripts/gym_scripts.pory"
	case 2, MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_26
# 2049 "data/scripts/gym_scripts.pory"
	case 3, MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_27
# 2050 "data/scripts/gym_scripts.pory"
	case 4, MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_28
# 2051 "data/scripts/gym_scripts.pory"
	case 5, MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_29
# 2052 "data/scripts/gym_scripts.pory"
	case 6, MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_30
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_16

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_20:
# 2034 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_GARDEVOIR_MEGA_STONE, MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_17
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_19

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_24:
# 2046 "data/scripts/gym_scripts.pory"
	giveitem ITEM_LIFE_ORB, 2
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_16

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_25:
# 2047 "data/scripts/gym_scripts.pory"
	giveitem ITEM_PSYCHIC_GEM, 2
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_16

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_26:
# 2048 "data/scripts/gym_scripts.pory"
	giveitem ITEM_SUN_STONE, 2
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_16

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_27:
# 2049 "data/scripts/gym_scripts.pory"
	giveitem ITEM_MOON_STONE, 2
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_16

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_28:
# 2050 "data/scripts/gym_scripts.pory"
	giveitem ITEM_SCOPE_LENS, 2
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_16

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_29:
# 2051 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TERRAIN_EXTENDER, 2
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_16

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_30:
# 2052 "data/scripts/gym_scripts.pory"
	giveitem ITEM_COLBUR_BERRY, 2
	goto MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_16


MossdeepCity_Gym_EventScript_GymGuide_New::
# 2060 "data/scripts/gym_scripts.pory"
	lock
# 2061 "data/scripts/gym_scripts.pory"
	faceplayer
# 2062 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuide_New_2
# 2078 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_NPC
MossdeepCity_Gym_EventScript_GymGuide_New_1:
# 2080 "data/scripts/gym_scripts.pory"
	release
	end

MossdeepCity_Gym_EventScript_GymGuide_New_2:
# 2063 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TATE_AND_LIZA_REMATCH, MossdeepCity_Gym_EventScript_GymGuide_New_5
# 2074 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_NPC
	goto MossdeepCity_Gym_EventScript_GymGuide_New_1

MossdeepCity_Gym_EventScript_GymGuide_New_5:
# 2064 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_GymGuide_New_Text_0, MSGBOX_YESNO
# 2065 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq MossdeepCity_Gym_EventScript_GymGuide_New_8
# 2070 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_2, MSGBOX_NPC
	goto MossdeepCity_Gym_EventScript_GymGuide_New_1

MossdeepCity_Gym_EventScript_GymGuide_New_8:
# 2066 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_GymGuide_New_Text_1, MSGBOX_NPC
# 2067 "data/scripts/gym_scripts.pory"
	warp MAP_MOSSDEEP_CITY_GYM, 255, 12, 13
	goto MossdeepCity_Gym_EventScript_GymGuide_New_1


MossdeepCity_Gym_EventScript_Gym_Solrock::
# 2085 "data/scripts/gym_scripts.pory"
	lock
# 2086 "data/scripts/gym_scripts.pory"
	faceplayer
# 2087 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_Gym_Solrock_8
MossdeepCity_Gym_EventScript_Gym_Solrock_6:
# 2093 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_Gym_Solrock_5
MossdeepCity_Gym_EventScript_Gym_Solrock_4:
# 2099 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_Gym_Solrock_Text_3, MSGBOX_NPC
# 2100 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_Text_5, MSGBOX_SIGN
# 2101 "data/scripts/gym_scripts.pory"
	waitmessage
MossdeepCity_Gym_EventScript_Gym_Solrock_1:
# 2103 "data/scripts/gym_scripts.pory"
	release
	end

MossdeepCity_Gym_EventScript_Gym_Solrock_2:
# 2089 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_Gym_Solrock_Text_0, MSGBOX_NPC
# 2090 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_Gym_Solrock_Text_1, MSGBOX_SIGN
# 2091 "data/scripts/gym_scripts.pory"
	waitmessage
	goto MossdeepCity_Gym_EventScript_Gym_Solrock_1

MossdeepCity_Gym_EventScript_Gym_Solrock_3:
# 2094 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_Gym_Solrock_Text_2, MSGBOX_NPC
# 2095 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_Text_3, MSGBOX_SIGN
# 2096 "data/scripts/gym_scripts.pory"
	waitmessage
	goto MossdeepCity_Gym_EventScript_Gym_Solrock_1

MossdeepCity_Gym_EventScript_Gym_Solrock_5:
# 2093 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_TATE_AND_LIZA_REMATCH, MossdeepCity_Gym_EventScript_Gym_Solrock_3
	goto MossdeepCity_Gym_EventScript_Gym_Solrock_4

MossdeepCity_Gym_EventScript_Gym_Solrock_8:
# 2087 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TATE_AND_LIZA_REMATCH, MossdeepCity_Gym_EventScript_Gym_Solrock_2
	goto MossdeepCity_Gym_EventScript_Gym_Solrock_6


MossdeepCity_Gym_EventScript_Gym_Lunatone::
# 2108 "data/scripts/gym_scripts.pory"
	lock
# 2109 "data/scripts/gym_scripts.pory"
	faceplayer
# 2110 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_Gym_Lunatone_8
MossdeepCity_Gym_EventScript_Gym_Lunatone_6:
# 2116 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_Gym_Lunatone_5
MossdeepCity_Gym_EventScript_Gym_Lunatone_4:
# 2122 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_Gym_Lunatone_Text_2, MSGBOX_NPC
# 2123 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_Text_5, MSGBOX_SIGN
# 2124 "data/scripts/gym_scripts.pory"
	waitmessage
MossdeepCity_Gym_EventScript_Gym_Lunatone_1:
# 2126 "data/scripts/gym_scripts.pory"
	release
	end

MossdeepCity_Gym_EventScript_Gym_Lunatone_2:
# 2112 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_Gym_Lunatone_Text_0, MSGBOX_NPC
# 2113 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_Gym_Solrock_Text_1, MSGBOX_SIGN
# 2114 "data/scripts/gym_scripts.pory"
	waitmessage
	goto MossdeepCity_Gym_EventScript_Gym_Lunatone_1

MossdeepCity_Gym_EventScript_Gym_Lunatone_3:
# 2117 "data/scripts/gym_scripts.pory"
	msgbox MossdeepCity_Gym_EventScript_Gym_Lunatone_Text_1, MSGBOX_NPC
# 2118 "data/scripts/gym_scripts.pory"
	msgbox LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_Text_3, MSGBOX_SIGN
# 2119 "data/scripts/gym_scripts.pory"
	waitmessage
	goto MossdeepCity_Gym_EventScript_Gym_Lunatone_1

MossdeepCity_Gym_EventScript_Gym_Lunatone_5:
# 2116 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_TATE_AND_LIZA_REMATCH, MossdeepCity_Gym_EventScript_Gym_Lunatone_3
	goto MossdeepCity_Gym_EventScript_Gym_Lunatone_4

MossdeepCity_Gym_EventScript_Gym_Lunatone_8:
# 2110 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TATE_AND_LIZA_REMATCH, MossdeepCity_Gym_EventScript_Gym_Lunatone_2
	goto MossdeepCity_Gym_EventScript_Gym_Lunatone_6


SootopolisCity_Gym_1F_EventScript_Juan_New::
# 2131 "data/scripts/gym_scripts.pory"
	lock
# 2132 "data/scripts/gym_scripts.pory"
	faceplayer
# 2133 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_Juan_New_8
SootopolisCity_Gym_1F_EventScript_Juan_New_6:
# 2153 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_Juan_New_5
SootopolisCity_Gym_1F_EventScript_Juan_New_4:
# 2171 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_JuanIntro, MSGBOX_NPC
# 2173 "data/scripts/gym_scripts.pory"
	call SootopolisCity_Gym_1F_EventScript_Juan_Battle_New
# 2176 "data/scripts/gym_scripts.pory"
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
# 2177 "data/scripts/gym_scripts.pory"
	waitmessage
# 2178 "data/scripts/gym_scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 2179 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_5, MSGBOX_NPC
# 2180 "data/scripts/gym_scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 2181 "data/scripts/gym_scripts.pory"
	setflag FLAG_BADGE08_GET
# 2184 "data/scripts/gym_scripts.pory"
	call Special_Gym_EventScript_Give_Item
# 2187 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM03_WATER_PULSE
# 2188 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Juan_New_Text_3, MSGBOX_NPC
# 2190 "data/scripts/gym_scripts.pory"
	waitfanfare
# 2191 "data/scripts/gym_scripts.pory"
	closemessage
# 2192 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 2195 "data/scripts/gym_scripts.pory"
	call SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts
# 2198 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 8
# 2199 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 2202 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
# 2203 "data/scripts/gym_scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 2204 "data/scripts/gym_scripts.pory"
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
# 2205 "data/scripts/gym_scripts.pory"
	waitfanfare
# 2206 "data/scripts/gym_scripts.pory"
	closemessage
# 2209 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_NPC
# 2210 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 2213 "data/scripts/gym_scripts.pory"
	setflag FLAG_JUAN_REMATCH
SootopolisCity_Gym_1F_EventScript_Juan_New_1:
# 2215 "data/scripts/gym_scripts.pory"
	release
	end

SootopolisCity_Gym_1F_EventScript_Juan_New_2:
# 2136 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_JuanPreRematch, MSGBOX_NPC
# 2138 "data/scripts/gym_scripts.pory"
	call SootopolisCity_Gym_1F_EventScript_Juan_Battle_New
# 2141 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_NPC
# 2142 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 2145 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
# 2146 "data/scripts/gym_scripts.pory"
	call SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts
# 2148 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Juan_New_Text_0, MSGBOX_NPC
# 2151 "data/scripts/gym_scripts.pory"
	setflag FLAG_JUAN_REMATCH
	goto SootopolisCity_Gym_1F_EventScript_Juan_New_1

SootopolisCity_Gym_1F_EventScript_Juan_New_3:
# 2155 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Juan_New_Text_1, MSGBOX_YESNO
# 2156 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SootopolisCity_Gym_1F_EventScript_Juan_New_11
# 2163 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 8
# 2164 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 2165 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Juan_New_Text_0, MSGBOX_NPC
	goto SootopolisCity_Gym_1F_EventScript_Juan_New_1

SootopolisCity_Gym_1F_EventScript_Juan_New_5:
# 2153 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_JUAN_REMATCH, SootopolisCity_Gym_1F_EventScript_Juan_New_3
	goto SootopolisCity_Gym_1F_EventScript_Juan_New_4

SootopolisCity_Gym_1F_EventScript_Juan_New_8:
# 2133 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_JUAN_REMATCH, SootopolisCity_Gym_1F_EventScript_Juan_New_2
	goto SootopolisCity_Gym_1F_EventScript_Juan_New_6

SootopolisCity_Gym_1F_EventScript_Juan_New_11:
# 2157 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 8
# 2158 "data/scripts/gym_scripts.pory"
	call Common_EventScript_ClearGymTrainers
# 2159 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Juan_New_Text_2, MSGBOX_NPC
	goto SootopolisCity_Gym_1F_EventScript_Juan_New_1


SootopolisCity_Gym_1F_EventScript_Juan_Battle_New::
# 2220 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_2
# 2226 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_5
# 2239 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanRematchDefeat
SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_1:
	return

SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_2:
# 2222 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanDefeat
	goto SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_1

SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_5:
# 2228 "data/scripts/gym_scripts.pory"
	setflag FLAG_SYS_DISABLE_SCALED_TRAINERS
# 2229 "data/scripts/gym_scripts.pory"
	random 5
# 2230 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 2231 "data/scripts/gym_scripts.pory"
	case 0, SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_9
# 2232 "data/scripts/gym_scripts.pory"
	case 1, SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_10
# 2233 "data/scripts/gym_scripts.pory"
	case 2, SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_11
# 2234 "data/scripts/gym_scripts.pory"
	case 3, SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_12
# 2235 "data/scripts/gym_scripts.pory"
	case 4, SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_13
	goto SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_1

SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_9:
# 2231 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanRematchDefeat
	goto SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_1

SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_10:
# 2232 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_JUAN_2, SootopolisCity_Gym_1F_Text_JuanRematchDefeat
	goto SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_1

SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_11:
# 2233 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_JUAN_3, SootopolisCity_Gym_1F_Text_JuanRematchDefeat
	goto SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_1

SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_12:
# 2234 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_JUAN_4, SootopolisCity_Gym_1F_Text_JuanRematchDefeat
	goto SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_1

SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_13:
# 2235 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_JUAN_5, SootopolisCity_Gym_1F_Text_JuanRematchDefeat
	goto SootopolisCity_Gym_1F_EventScript_Juan_Battle_New_1


SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts::
# 2246 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM55_SCALD, 1
# 2247 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_SECOND_TM_BADGES_COUNT
	goto_if_ge SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_3
SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_1:
# 2254 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM94_SURF, 1
# 2255 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_THIRD_TM_BADGES_COUNT
	goto_if_ge SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_8
SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_6:
# 2262 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM98_WATERFALL, 1
# 2263 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_FOURTH_TM_BADGES_COUNT
	goto_if_ge SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_13
SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_11:
# 2270 "data/scripts/gym_scripts.pory"
	checkitem ITEM_TM102_LIQUIDATION, 1
# 2271 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_FIFTH_TM_BADGES_COUNT
	goto_if_ge SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_18
SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_16:
# 2278 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, GYM_MEGA_STONES_BADGES_COUNT
	goto_if_ge SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_25
SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_24:
# 2285 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_23
SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_21:
# 2298 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_CheckForAllBadges
	return

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_2:
# 2248 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM55_SCALD
# 2249 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_Text_0, MSGBOX_NPC
# 2250 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_1

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_3:
# 2247 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_2
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_1

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_7:
# 2256 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM94_SURF
# 2257 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_Text_1, MSGBOX_NPC
# 2258 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_6

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_8:
# 2255 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_7
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_6

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_12:
# 2264 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM98_WATERFALL
# 2265 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_Text_2, MSGBOX_NPC
# 2266 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_11

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_13:
# 2263 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_12
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_11

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_17:
# 2272 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TM102_LIQUIDATION
# 2273 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_Text_3, MSGBOX_NPC
# 2274 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_16

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_18:
# 2271 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_17
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_16

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_22:
# 2279 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_Text_4, MSGBOX_NPC
# 2280 "data/scripts/gym_scripts.pory"
	giveitem ITEM_GYARADOSITE
# 2281 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_Text_5, MSGBOX_NPC
# 2282 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_GYARADOS_MEGA_STONE
# 2283 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_21

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_23:
# 2287 "data/scripts/gym_scripts.pory"
	random 7
# 2288 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 2289 "data/scripts/gym_scripts.pory"
	case 0, SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_29
# 2290 "data/scripts/gym_scripts.pory"
	case 1, SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_30
# 2291 "data/scripts/gym_scripts.pory"
	case 2, SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_31
# 2292 "data/scripts/gym_scripts.pory"
	case 3, SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_32
# 2293 "data/scripts/gym_scripts.pory"
	case 4, SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_33
# 2294 "data/scripts/gym_scripts.pory"
	case 5, SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_34
# 2295 "data/scripts/gym_scripts.pory"
	case 6, SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_35
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_21

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_25:
# 2278 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_GYARADOS_MEGA_STONE, SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_22
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_24

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_29:
# 2289 "data/scripts/gym_scripts.pory"
	giveitem ITEM_WATER_GEM, 2
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_21

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_30:
# 2290 "data/scripts/gym_scripts.pory"
	giveitem ITEM_WATER_STONE, 2
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_21

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_31:
# 2291 "data/scripts/gym_scripts.pory"
	giveitem ITEM_LURE_BALL_SEAL, 2
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_21

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_32:
# 2292 "data/scripts/gym_scripts.pory"
	giveitem ITEM_DRAGON_SCALE, 2
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_21

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_33:
# 2293 "data/scripts/gym_scripts.pory"
	giveitem ITEM_PRISM_SCALE, 2
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_21

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_34:
# 2294 "data/scripts/gym_scripts.pory"
	giveitem ITEM_DAMP_ROCK, 2
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_21

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_35:
# 2295 "data/scripts/gym_scripts.pory"
	giveitem ITEM_LUSTROUS_ORB, 2
	goto SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_21


SootopolisCity_Gym_1F_EventScript_GymGuide_New::
# 2302 "data/scripts/gym_scripts.pory"
	lock
# 2303 "data/scripts/gym_scripts.pory"
	faceplayer
# 2304 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuide_New_2
# 2320 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_NPC
SootopolisCity_Gym_1F_EventScript_GymGuide_New_1:
# 2322 "data/scripts/gym_scripts.pory"
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuide_New_2:
# 2305 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_JUAN_REMATCH, SootopolisCity_Gym_1F_EventScript_GymGuide_New_5
# 2316 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_NPC
	goto SootopolisCity_Gym_1F_EventScript_GymGuide_New_1

SootopolisCity_Gym_1F_EventScript_GymGuide_New_5:
# 2306 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_0, MSGBOX_YESNO
# 2307 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SootopolisCity_Gym_1F_EventScript_GymGuide_New_8
# 2312 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_2, MSGBOX_NPC
	goto SootopolisCity_Gym_1F_EventScript_GymGuide_New_1

SootopolisCity_Gym_1F_EventScript_GymGuide_New_8:
# 2308 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_GymGuide_New_Text_1, MSGBOX_NPC
# 2309 "data/scripts/gym_scripts.pory"
	warp MAP_SOOTOPOLIS_CITY_GYM_1F, 255, 8, 3
	goto SootopolisCity_Gym_1F_EventScript_GymGuide_New_1


SootopolisCity_Gym_1F_EventScript_Gym_Horsea::
# 2327 "data/scripts/gym_scripts.pory"
	lock
# 2328 "data/scripts/gym_scripts.pory"
	faceplayer
# 2329 "data/scripts/gym_scripts.pory"
	switch VAR_GYM_POKEMON_SPECIES
# 2330 "data/scripts/gym_scripts.pory"
	case SPECIES_HORSEA, SootopolisCity_Gym_1F_EventScript_Gym_Horsea_3
# 2348 "data/scripts/gym_scripts.pory"
	case SPECIES_SEADRA, SootopolisCity_Gym_1F_EventScript_Gym_Horsea_4
# 2365 "data/scripts/gym_scripts.pory"
	case SPECIES_KINGDRA, SootopolisCity_Gym_1F_EventScript_Gym_Horsea_5
SootopolisCity_Gym_1F_EventScript_Gym_Horsea_1:
# 2385 "data/scripts/gym_scripts.pory"
	release
	end

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_3:
# 2331 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_Gym_Horsea_12
SootopolisCity_Gym_1F_EventScript_Gym_Horsea_10:
# 2337 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_Gym_Horsea_9
SootopolisCity_Gym_1F_EventScript_Gym_Horsea_8:
# 2344 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_3, MSGBOX_NPC
# 2345 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_4, MSGBOX_SIGN
# 2346 "data/scripts/gym_scripts.pory"
	waitmessage
	goto SootopolisCity_Gym_1F_EventScript_Gym_Horsea_1

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_4:
# 2349 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_Gym_Horsea_21
SootopolisCity_Gym_1F_EventScript_Gym_Horsea_19:
# 2355 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_Gym_Horsea_18
SootopolisCity_Gym_1F_EventScript_Gym_Horsea_17:
# 2361 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_7, MSGBOX_NPC
# 2362 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_8, MSGBOX_SIGN
# 2363 "data/scripts/gym_scripts.pory"
	waitmessage
	goto SootopolisCity_Gym_1F_EventScript_Gym_Horsea_1

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_5:
# 2366 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_Gym_Horsea_30
SootopolisCity_Gym_1F_EventScript_Gym_Horsea_28:
# 2372 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_Gym_Horsea_27
SootopolisCity_Gym_1F_EventScript_Gym_Horsea_26:
# 2380 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_11, MSGBOX_NPC
# 2381 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_12, MSGBOX_SIGN
# 2382 "data/scripts/gym_scripts.pory"
	waitmessage
	goto SootopolisCity_Gym_1F_EventScript_Gym_Horsea_1

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_6:
# 2333 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_0, MSGBOX_NPC
# 2334 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_1, MSGBOX_SIGN
# 2335 "data/scripts/gym_scripts.pory"
	waitmessage
	goto SootopolisCity_Gym_1F_EventScript_Gym_Horsea_1

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_7:
# 2339 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_2, MSGBOX_NPC
# 2340 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_3, MSGBOX_SIGN
# 2341 "data/scripts/gym_scripts.pory"
	waitmessage
	goto SootopolisCity_Gym_1F_EventScript_Gym_Horsea_1

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_9:
# 2337 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_JUAN_REMATCH, SootopolisCity_Gym_1F_EventScript_Gym_Horsea_7
	goto SootopolisCity_Gym_1F_EventScript_Gym_Horsea_8

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_12:
# 2331 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_JUAN_REMATCH, SootopolisCity_Gym_1F_EventScript_Gym_Horsea_6
	goto SootopolisCity_Gym_1F_EventScript_Gym_Horsea_10

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_15:
# 2351 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_5, MSGBOX_NPC
# 2352 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_1, MSGBOX_SIGN
# 2353 "data/scripts/gym_scripts.pory"
	waitmessage
	goto SootopolisCity_Gym_1F_EventScript_Gym_Horsea_1

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_16:
# 2356 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_6, MSGBOX_NPC
# 2357 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_3, MSGBOX_SIGN
# 2358 "data/scripts/gym_scripts.pory"
	waitmessage
	goto SootopolisCity_Gym_1F_EventScript_Gym_Horsea_1

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_18:
# 2355 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_JUAN_REMATCH, SootopolisCity_Gym_1F_EventScript_Gym_Horsea_16
	goto SootopolisCity_Gym_1F_EventScript_Gym_Horsea_17

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_21:
# 2349 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_JUAN_REMATCH, SootopolisCity_Gym_1F_EventScript_Gym_Horsea_15
	goto SootopolisCity_Gym_1F_EventScript_Gym_Horsea_19

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_24:
# 2368 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_9, MSGBOX_NPC
# 2369 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_11, MSGBOX_SIGN
# 2370 "data/scripts/gym_scripts.pory"
	waitmessage
	goto SootopolisCity_Gym_1F_EventScript_Gym_Horsea_1

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_25:
# 2374 "data/scripts/gym_scripts.pory"
	msgbox SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_10, MSGBOX_NPC
# 2375 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Gym_Aaron_Text_3, MSGBOX_SIGN
# 2376 "data/scripts/gym_scripts.pory"
	waitmessage
	goto SootopolisCity_Gym_1F_EventScript_Gym_Horsea_1

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_27:
# 2372 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_JUAN_REMATCH, SootopolisCity_Gym_1F_EventScript_Gym_Horsea_25
	goto SootopolisCity_Gym_1F_EventScript_Gym_Horsea_26

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_30:
# 2366 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_JUAN_REMATCH, SootopolisCity_Gym_1F_EventScript_Gym_Horsea_24
	goto SootopolisCity_Gym_1F_EventScript_Gym_Horsea_28


SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species::
# 2390 "data/scripts/gym_scripts.pory"
	switch VAR_NUM_BADGES
# 2391 "data/scripts/gym_scripts.pory"
	case 0, SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_3
# 2392 "data/scripts/gym_scripts.pory"
	case 1, SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_4
# 2393 "data/scripts/gym_scripts.pory"
	case 2, SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_5
# 2394 "data/scripts/gym_scripts.pory"
	case 3, SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_6
# 2395 "data/scripts/gym_scripts.pory"
	case 4, SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_7
# 2396 "data/scripts/gym_scripts.pory"
	case 5, SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_8
# 2397 "data/scripts/gym_scripts.pory"
	case 6, SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_9
# 2398 "data/scripts/gym_scripts.pory"
	case 7, SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_10
# 2399 "data/scripts/gym_scripts.pory"
	case 8, SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_11
SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_1:
# 2402 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_NO_EVOLUTION_MODE, SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_13
# 2402 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_LITTLE_CUP_MODE, SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_13
SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_12:
	return

SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_3:
# 2391 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_HORSEA
# 2391 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_HORSEA
	goto SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_1

SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_4:
# 2392 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_HORSEA
# 2392 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_HORSEA
	goto SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_1

SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_5:
# 2393 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_HORSEA
# 2393 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_HORSEA
	goto SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_1

SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_6:
# 2394 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_SEADRA
# 2394 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_SEADRA
	goto SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_1

SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_7:
# 2395 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_SEADRA
# 2395 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_SEADRA
	goto SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_1

SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_8:
# 2396 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_KINGDRA
# 2396 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_KINGDRA
	goto SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_1

SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_9:
# 2397 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_KINGDRA
# 2397 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_KINGDRA
	goto SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_1

SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_10:
# 2398 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_KINGDRA
# 2398 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_KINGDRA
	goto SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_1

SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_11:
# 2399 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_KINGDRA
# 2399 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_KINGDRA
	goto SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_1

SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_13:
# 2403 "data/scripts/gym_scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_POKEMON_000 + SPECIES_HORSEA
# 2403 "data/scripts/gym_scripts.pory"
	setvar VAR_GYM_POKEMON_SPECIES, SPECIES_HORSEA
	goto SootopolisCity_Gym_1F_EventScript_Set_Gym_Pokemon_Species_12


Common_Eventscript_Gym_Leader_Falkner::
# 2414 "data/scripts/gym_scripts.pory"
	lock
# 2415 "data/scripts/gym_scripts.pory"
	faceplayer
# 2416 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_09, Common_Eventscript_Gym_Leader_Falkner_8
Common_Eventscript_Gym_Leader_Falkner_6:
# 2432 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_09, Common_Eventscript_Gym_Leader_Falkner_5
Common_Eventscript_Gym_Leader_Falkner_4:
# 2450 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Text_5, MSGBOX_NPC
# 2452 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Falkner_Battle_New
# 2454 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Text_6, MSGBOX_NPC
# 2455 "data/scripts/gym_scripts.pory"
	message Common_Eventscript_Gym_Leader_Falkner_Text_7
# 2456 "data/scripts/gym_scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 2457 "data/scripts/gym_scripts.pory"
	waitmessage
# 2458 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_5, MSGBOX_NPC
# 2459 "data/scripts/gym_scripts.pory"
	setflag FLAG_RECEIVED_BADGE_09
# 2460 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 2462 "data/scripts/gym_scripts.pory"
	call Special_Gym_EventScript_Give_Item
# 2463 "data/scripts/gym_scripts.pory"
	waitfanfare
# 2464 "data/scripts/gym_scripts.pory"
	closemessage
# 2466 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Falkner_Give_Gifts
# 2467 "data/scripts/gym_scripts.pory"
	setflag FLAG_RECEIVED_BADGE_09
# 2469 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Text_8, MSGBOX_NPC
# 2470 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 2471 "data/scripts/gym_scripts.pory"
	clearflag FLAG_FALKNER_REMATCH
# 2472 "data/scripts/gym_scripts.pory"
	special HealPlayerParty
Common_Eventscript_Gym_Leader_Falkner_1:
# 2474 "data/scripts/gym_scripts.pory"
	release
	end

Common_Eventscript_Gym_Leader_Falkner_2:
# 2419 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Text_0, MSGBOX_NPC
# 2421 "data/scripts/gym_scripts.pory"
	special HealPlayerParty
# 2422 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Falkner_Battle_New
# 2424 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Text_1, MSGBOX_NPC
# 2425 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 2427 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Falkner_Give_Gifts
# 2428 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Text_2, MSGBOX_NPC
# 2430 "data/scripts/gym_scripts.pory"
	setflag FLAG_FALKNER_REMATCH
	goto Common_Eventscript_Gym_Leader_Falkner_1

Common_Eventscript_Gym_Leader_Falkner_3:
# 2434 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Text_3, MSGBOX_YESNO
# 2435 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Common_Eventscript_Gym_Leader_Falkner_11
# 2442 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 9
# 2443 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 2444 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Text_2, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Falkner_1

Common_Eventscript_Gym_Leader_Falkner_5:
# 2432 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_FALKNER_REMATCH, Common_Eventscript_Gym_Leader_Falkner_3
	goto Common_Eventscript_Gym_Leader_Falkner_4

Common_Eventscript_Gym_Leader_Falkner_8:
# 2416 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_FALKNER_REMATCH, Common_Eventscript_Gym_Leader_Falkner_2
	goto Common_Eventscript_Gym_Leader_Falkner_6

Common_Eventscript_Gym_Leader_Falkner_11:
# 2436 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 9
# 2437 "data/scripts/gym_scripts.pory"
	call Common_EventScript_ClearGymTrainers
# 2438 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Text_4, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Falkner_1


Common_Eventscript_Gym_Leader_Falkner_Give_Gifts::
# 2480 "data/scripts/gym_scripts.pory"
	random 8
# 2482 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_CORVIKNIGHT_MEGA_STONE, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_3
Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_1:
# 2486 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 2487 "data/scripts/gym_scripts.pory"
	case 0, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_8
# 2493 "data/scripts/gym_scripts.pory"
	case 1, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_9
# 2499 "data/scripts/gym_scripts.pory"
	case 2, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_10
# 2505 "data/scripts/gym_scripts.pory"
	case 3, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_11
# 2511 "data/scripts/gym_scripts.pory"
	case 4, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_12
# 2517 "data/scripts/gym_scripts.pory"
	case 5, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_13
# 2523 "data/scripts/gym_scripts.pory"
	case 6, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_14
# 2529 "data/scripts/gym_scripts.pory"
	case 7, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_15
Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_15:
# 2531 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_38
Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_37:
# 2534 "data/scripts/gym_scripts.pory"
	giveitem ITEM_CORVIKNITE, 1
# 2535 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_CORVIKNIGHT_MEGA_STONE
Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_6:
# 2538 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_CheckForAllBadges
	return

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_2:
# 2483 "data/scripts/gym_scripts.pory"
	setvar VAR_RESULT, 7
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_1

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_3:
# 2482 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, 11
	goto_if_gt Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_2
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_1

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_8:
# 2488 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_17
Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_16:
# 2491 "data/scripts/gym_scripts.pory"
	giveitem ITEM_COBA_BERRY, 3
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_6

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_9:
# 2494 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_20
Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_19:
# 2497 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FLYING_GEM, 2
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_6

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_10:
# 2500 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_23
Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_22:
# 2503 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FLYING_MEMORY, 1
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_6

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_11:
# 2506 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_26
Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_25:
# 2509 "data/scripts/gym_scripts.pory"
	giveitem ITEM_AIR_BALLOON, 1
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_6

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_12:
# 2512 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_29
Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_28:
# 2515 "data/scripts/gym_scripts.pory"
	giveitem ITEM_UTILITY_UMBRELLA, 1
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_6

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_13:
# 2518 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_32
Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_31:
# 2521 "data/scripts/gym_scripts.pory"
	giveitem ITEM_HEAVY_DUTY_BOOTS, 1
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_6

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_14:
# 2524 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_35
Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_34:
# 2527 "data/scripts/gym_scripts.pory"
	giveitem ITEM_POWER_HERB, 1
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_6

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_17:
# 2489 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_16

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_20:
# 2495 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_19

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_23:
# 2501 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_22

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_26:
# 2507 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_25

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_29:
# 2513 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_28

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_32:
# 2519 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_31

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_35:
# 2525 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_34

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_38:
# 2532 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_37


Common_Eventscript_Gym_Leader_Falkner_Battle_New::
# 2544 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_RECEIVED_BADGE_09, Common_Eventscript_Gym_Leader_Falkner_Battle_New_2
# 2550 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Common_Eventscript_Gym_Leader_Falkner_Battle_New_5
# 2556 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_FALKNER, Common_Eventscript_Gym_Leader_Falkner_Battle_New_Text_2
Common_Eventscript_Gym_Leader_Falkner_Battle_New_1:
	return

Common_Eventscript_Gym_Leader_Falkner_Battle_New_2:
# 2546 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_FALKNER, Common_Eventscript_Gym_Leader_Falkner_Battle_New_Text_0
	goto Common_Eventscript_Gym_Leader_Falkner_Battle_New_1

Common_Eventscript_Gym_Leader_Falkner_Battle_New_5:
# 2553 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_FALKNER, Common_Eventscript_Gym_Leader_Falkner_Battle_New_Text_1
	goto Common_Eventscript_Gym_Leader_Falkner_Battle_New_1


Common_Eventscript_Gym_Leader_Bugsy::
# 2565 "data/scripts/gym_scripts.pory"
	lock
# 2566 "data/scripts/gym_scripts.pory"
	faceplayer
# 2567 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_10, Common_Eventscript_Gym_Leader_Bugsy_8
Common_Eventscript_Gym_Leader_Bugsy_6:
# 2583 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_10, Common_Eventscript_Gym_Leader_Bugsy_5
Common_Eventscript_Gym_Leader_Bugsy_4:
# 2601 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Bugsy_Text_5, MSGBOX_NPC
# 2603 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Bugsy_Battle_New
# 2605 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Bugsy_Text_6, MSGBOX_NPC
# 2606 "data/scripts/gym_scripts.pory"
	message Common_Eventscript_Gym_Leader_Bugsy_Text_7
# 2607 "data/scripts/gym_scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 2608 "data/scripts/gym_scripts.pory"
	waitmessage
# 2609 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_5, MSGBOX_NPC
# 2610 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 2611 "data/scripts/gym_scripts.pory"
	setflag FLAG_RECEIVED_BADGE_10
# 2613 "data/scripts/gym_scripts.pory"
	call Special_Gym_EventScript_Give_Item
# 2614 "data/scripts/gym_scripts.pory"
	waitfanfare
# 2615 "data/scripts/gym_scripts.pory"
	closemessage
# 2617 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts
# 2619 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Bugsy_Text_8, MSGBOX_NPC
# 2620 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 2621 "data/scripts/gym_scripts.pory"
	clearflag FLAG_BUGSY_REMATCH
# 2622 "data/scripts/gym_scripts.pory"
	special HealPlayerParty
Common_Eventscript_Gym_Leader_Bugsy_1:
# 2624 "data/scripts/gym_scripts.pory"
	release
	end

Common_Eventscript_Gym_Leader_Bugsy_2:
# 2570 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Bugsy_Text_0, MSGBOX_NPC
# 2572 "data/scripts/gym_scripts.pory"
	special HealPlayerParty
# 2573 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Bugsy_Battle_New
# 2575 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Bugsy_Text_1, MSGBOX_NPC
# 2576 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 2578 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts
# 2579 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Bugsy_Text_2, MSGBOX_NPC
# 2581 "data/scripts/gym_scripts.pory"
	setflag FLAG_BUGSY_REMATCH
	goto Common_Eventscript_Gym_Leader_Bugsy_1

Common_Eventscript_Gym_Leader_Bugsy_3:
# 2585 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Bugsy_Text_3, MSGBOX_YESNO
# 2586 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Common_Eventscript_Gym_Leader_Bugsy_11
# 2593 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 10
# 2594 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 2595 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Bugsy_Text_2, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Bugsy_1

Common_Eventscript_Gym_Leader_Bugsy_5:
# 2583 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BUGSY_REMATCH, Common_Eventscript_Gym_Leader_Bugsy_3
	goto Common_Eventscript_Gym_Leader_Bugsy_4

Common_Eventscript_Gym_Leader_Bugsy_8:
# 2567 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_BUGSY_REMATCH, Common_Eventscript_Gym_Leader_Bugsy_2
	goto Common_Eventscript_Gym_Leader_Bugsy_6

Common_Eventscript_Gym_Leader_Bugsy_11:
# 2587 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 10
# 2588 "data/scripts/gym_scripts.pory"
	call Common_EventScript_ClearGymTrainers
# 2589 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Bugsy_Text_4, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Bugsy_1


Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts::
# 2630 "data/scripts/gym_scripts.pory"
	random 8
# 2632 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_BUTTERFREE_MEGA_STONE, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_3
Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_1:
# 2636 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 2637 "data/scripts/gym_scripts.pory"
	case 0, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_8
# 2643 "data/scripts/gym_scripts.pory"
	case 1, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_9
# 2649 "data/scripts/gym_scripts.pory"
	case 2, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_10
# 2655 "data/scripts/gym_scripts.pory"
	case 3, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_11
# 2661 "data/scripts/gym_scripts.pory"
	case 4, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_12
# 2667 "data/scripts/gym_scripts.pory"
	case 5, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_13
# 2673 "data/scripts/gym_scripts.pory"
	case 6, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_14
# 2679 "data/scripts/gym_scripts.pory"
	case 7, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_15
Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_15:
# 2681 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_38
Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_37:
# 2684 "data/scripts/gym_scripts.pory"
	giveitem ITEM_BUTTERFRITE, 1
# 2685 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_BUTTERFREE_MEGA_STONE
Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_6:
# 2688 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_CheckForAllBadges
	return

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_2:
# 2633 "data/scripts/gym_scripts.pory"
	setvar VAR_RESULT, 7
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_1

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_3:
# 2632 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, 11
	goto_if_gt Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_2
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_1

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_8:
# 2638 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_17
Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_16:
# 2641 "data/scripts/gym_scripts.pory"
	giveitem ITEM_TANGA_BERRY, 3
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_6

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_9:
# 2644 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_20
Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_19:
# 2647 "data/scripts/gym_scripts.pory"
	giveitem ITEM_BUG_GEM, 2
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_6

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_10:
# 2650 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_23
Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_22:
# 2653 "data/scripts/gym_scripts.pory"
	giveitem ITEM_BUG_MEMORY, 1
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_6

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_11:
# 2656 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_26
Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_25:
# 2659 "data/scripts/gym_scripts.pory"
	giveitem ITEM_NET_BALL, 5
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_6

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_12:
# 2662 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_29
Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_28:
# 2665 "data/scripts/gym_scripts.pory"
	giveitem ITEM_HONEY, 3
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_6

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_13:
# 2668 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_32
Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_31:
# 2671 "data/scripts/gym_scripts.pory"
	giveitem ITEM_SHED_SHELL, 1
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_6

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_14:
# 2674 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_35
Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_34:
# 2677 "data/scripts/gym_scripts.pory"
	giveitem ITEM_GRIP_CLAW, 1
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_6

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_17:
# 2639 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_16

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_20:
# 2645 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_19

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_23:
# 2651 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_22

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_26:
# 2657 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_25

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_29:
# 2663 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_28

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_32:
# 2669 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_31

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_35:
# 2675 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_34

Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_38:
# 2682 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Bugsy_Give_Gifts_37


Common_Eventscript_Gym_Leader_Bugsy_Battle_New::
# 2694 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_RECEIVED_BADGE_10, Common_Eventscript_Gym_Leader_Bugsy_Battle_New_2
# 2700 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Common_Eventscript_Gym_Leader_Bugsy_Battle_New_5
# 2706 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_BUGSY, Common_Eventscript_Gym_Leader_Bugsy_Battle_New_Text_2
Common_Eventscript_Gym_Leader_Bugsy_Battle_New_1:
	return

Common_Eventscript_Gym_Leader_Bugsy_Battle_New_2:
# 2696 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_BUGSY, Common_Eventscript_Gym_Leader_Bugsy_Battle_New_Text_0
	goto Common_Eventscript_Gym_Leader_Bugsy_Battle_New_1

Common_Eventscript_Gym_Leader_Bugsy_Battle_New_5:
# 2703 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_BUGSY, Common_Eventscript_Gym_Leader_Bugsy_Battle_New_Text_1
	goto Common_Eventscript_Gym_Leader_Bugsy_Battle_New_1


Common_Eventscript_Gym_Leader_Whitney::
# 2715 "data/scripts/gym_scripts.pory"
	lock
# 2716 "data/scripts/gym_scripts.pory"
	faceplayer
# 2717 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_11, Common_Eventscript_Gym_Leader_Whitney_8
Common_Eventscript_Gym_Leader_Whitney_6:
# 2733 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_11, Common_Eventscript_Gym_Leader_Whitney_5
Common_Eventscript_Gym_Leader_Whitney_4:
# 2751 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Whitney_Text_5, MSGBOX_NPC
# 2753 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Whitney_Battle_New
# 2755 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Whitney_Text_6, MSGBOX_NPC
# 2756 "data/scripts/gym_scripts.pory"
	message Common_Eventscript_Gym_Leader_Whitney_Text_7
# 2757 "data/scripts/gym_scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 2758 "data/scripts/gym_scripts.pory"
	waitmessage
# 2759 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_5, MSGBOX_NPC
# 2760 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 2761 "data/scripts/gym_scripts.pory"
	setflag FLAG_RECEIVED_BADGE_11
# 2763 "data/scripts/gym_scripts.pory"
	call Special_Gym_EventScript_Give_Item
# 2764 "data/scripts/gym_scripts.pory"
	waitfanfare
# 2765 "data/scripts/gym_scripts.pory"
	closemessage
# 2767 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Whitney_Give_Gifts
# 2769 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Whitney_Text_8, MSGBOX_NPC
# 2770 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 2771 "data/scripts/gym_scripts.pory"
	clearflag FLAG_WHITNEY_REMATCH
# 2772 "data/scripts/gym_scripts.pory"
	special HealPlayerParty
Common_Eventscript_Gym_Leader_Whitney_1:
# 2774 "data/scripts/gym_scripts.pory"
	release
	end

Common_Eventscript_Gym_Leader_Whitney_2:
# 2720 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Whitney_Text_0, MSGBOX_NPC
# 2722 "data/scripts/gym_scripts.pory"
	special HealPlayerParty
# 2723 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Whitney_Battle_New
# 2725 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Whitney_Text_1, MSGBOX_NPC
# 2726 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 2728 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Whitney_Give_Gifts
# 2729 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Whitney_Text_2, MSGBOX_NPC
# 2731 "data/scripts/gym_scripts.pory"
	setflag FLAG_WHITNEY_REMATCH
	goto Common_Eventscript_Gym_Leader_Whitney_1

Common_Eventscript_Gym_Leader_Whitney_3:
# 2735 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Whitney_Text_3, MSGBOX_YESNO
# 2736 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Common_Eventscript_Gym_Leader_Whitney_11
# 2743 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 11
# 2744 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 2745 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Whitney_Text_2, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Whitney_1

Common_Eventscript_Gym_Leader_Whitney_5:
# 2733 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_WHITNEY_REMATCH, Common_Eventscript_Gym_Leader_Whitney_3
	goto Common_Eventscript_Gym_Leader_Whitney_4

Common_Eventscript_Gym_Leader_Whitney_8:
# 2717 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_WHITNEY_REMATCH, Common_Eventscript_Gym_Leader_Whitney_2
	goto Common_Eventscript_Gym_Leader_Whitney_6

Common_Eventscript_Gym_Leader_Whitney_11:
# 2737 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 11
# 2738 "data/scripts/gym_scripts.pory"
	call Common_EventScript_ClearGymTrainers
# 2739 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Whitney_Text_4, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Whitney_1


Common_Eventscript_Gym_Leader_Whitney_Give_Gifts::
# 2780 "data/scripts/gym_scripts.pory"
	random 8
# 2782 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_SNORLAX_MEGA_STONE, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_3
Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_1:
# 2786 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 2787 "data/scripts/gym_scripts.pory"
	case 0, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_8
# 2793 "data/scripts/gym_scripts.pory"
	case 1, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_9
# 2799 "data/scripts/gym_scripts.pory"
	case 2, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_10
# 2805 "data/scripts/gym_scripts.pory"
	case 3, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_11
# 2811 "data/scripts/gym_scripts.pory"
	case 4, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_12
# 2817 "data/scripts/gym_scripts.pory"
	case 5, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_13
# 2823 "data/scripts/gym_scripts.pory"
	case 6, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_14
# 2829 "data/scripts/gym_scripts.pory"
	case 7, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_15
Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_15:
# 2831 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_38
Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_37:
# 2834 "data/scripts/gym_scripts.pory"
	giveitem ITEM_SNORLAXITE, 1
# 2835 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_SNORLAX_MEGA_STONE
Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_6:
# 2838 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_CheckForAllBadges
	return

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_2:
# 2783 "data/scripts/gym_scripts.pory"
	setvar VAR_RESULT, 7
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_1

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_3:
# 2782 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, 11
	goto_if_gt Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_2
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_1

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_8:
# 2788 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_17
Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_16:
# 2791 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FAIRY_GEM, 2
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_6

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_9:
# 2794 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_20
Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_19:
# 2797 "data/scripts/gym_scripts.pory"
	giveitem ITEM_NORMAL_GEM, 2
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_6

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_10:
# 2800 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_23
Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_22:
# 2803 "data/scripts/gym_scripts.pory"
	giveitem ITEM_SILK_SCARF, 1
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_6

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_11:
# 2806 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_26
Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_25:
# 2809 "data/scripts/gym_scripts.pory"
	giveitem ITEM_ROSELI_BERRY, 3
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_6

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_12:
# 2812 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_29
Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_28:
# 2815 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FAIRY_MEMORY, 1
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_6

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_13:
# 2818 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_32
Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_31:
# 2821 "data/scripts/gym_scripts.pory"
	giveitem ITEM_CHILAN_BERRY, 3
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_6

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_14:
# 2824 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_35
Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_34:
# 2827 "data/scripts/gym_scripts.pory"
	giveitem ITEM_SAFETY_GOGGLES, 1
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_6

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_17:
# 2789 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_16

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_20:
# 2795 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_19

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_23:
# 2801 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_22

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_26:
# 2807 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_25

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_29:
# 2813 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_28

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_32:
# 2819 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_31

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_35:
# 2825 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_34

Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_38:
# 2832 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Whitney_Give_Gifts_37


Common_Eventscript_Gym_Leader_Whitney_Battle_New::
# 2844 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_RECEIVED_BADGE_11, Common_Eventscript_Gym_Leader_Whitney_Battle_New_2
# 2850 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Common_Eventscript_Gym_Leader_Whitney_Battle_New_5
# 2856 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_WHITNEY, Common_Eventscript_Gym_Leader_Whitney_Battle_New_Text_2
Common_Eventscript_Gym_Leader_Whitney_Battle_New_1:
	return

Common_Eventscript_Gym_Leader_Whitney_Battle_New_2:
# 2846 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_WHITNEY, Common_Eventscript_Gym_Leader_Whitney_Battle_New_Text_0
	goto Common_Eventscript_Gym_Leader_Whitney_Battle_New_1

Common_Eventscript_Gym_Leader_Whitney_Battle_New_5:
# 2853 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_WHITNEY, Common_Eventscript_Gym_Leader_Whitney_Battle_New_Text_1
	goto Common_Eventscript_Gym_Leader_Whitney_Battle_New_1


Common_Eventscript_Gym_Leader_Morty::
# 2865 "data/scripts/gym_scripts.pory"
	lock
# 2866 "data/scripts/gym_scripts.pory"
	faceplayer
# 2867 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_12, Common_Eventscript_Gym_Leader_Morty_8
Common_Eventscript_Gym_Leader_Morty_6:
# 2883 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_12, Common_Eventscript_Gym_Leader_Morty_5
Common_Eventscript_Gym_Leader_Morty_4:
# 2901 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Morty_Text_5, MSGBOX_NPC
# 2903 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Morty_Battle_New
# 2905 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Morty_Text_6, MSGBOX_NPC
# 2906 "data/scripts/gym_scripts.pory"
	message Common_Eventscript_Gym_Leader_Morty_Text_7
# 2907 "data/scripts/gym_scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 2908 "data/scripts/gym_scripts.pory"
	waitmessage
# 2909 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_5, MSGBOX_NPC
# 2910 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 2911 "data/scripts/gym_scripts.pory"
	setflag FLAG_RECEIVED_BADGE_12
# 2913 "data/scripts/gym_scripts.pory"
	call Special_Gym_EventScript_Give_Item
# 2914 "data/scripts/gym_scripts.pory"
	waitfanfare
# 2915 "data/scripts/gym_scripts.pory"
	closemessage
# 2917 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Morty_Give_Gifts
# 2919 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Morty_Text_8, MSGBOX_NPC
# 2920 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 2921 "data/scripts/gym_scripts.pory"
	clearflag FLAG_MORTY_REMATCH
# 2922 "data/scripts/gym_scripts.pory"
	special HealPlayerParty
Common_Eventscript_Gym_Leader_Morty_1:
# 2924 "data/scripts/gym_scripts.pory"
	release
	end

Common_Eventscript_Gym_Leader_Morty_2:
# 2870 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Morty_Text_0, MSGBOX_NPC
# 2872 "data/scripts/gym_scripts.pory"
	special HealPlayerParty
# 2873 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Morty_Battle_New
# 2875 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Morty_Text_1, MSGBOX_NPC
# 2876 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 2878 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Morty_Give_Gifts
# 2879 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Morty_Text_2, MSGBOX_NPC
# 2881 "data/scripts/gym_scripts.pory"
	setflag FLAG_MORTY_REMATCH
	goto Common_Eventscript_Gym_Leader_Morty_1

Common_Eventscript_Gym_Leader_Morty_3:
# 2885 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Morty_Text_3, MSGBOX_YESNO
# 2886 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Common_Eventscript_Gym_Leader_Morty_11
# 2893 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 12
# 2894 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 2895 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Morty_Text_2, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Morty_1

Common_Eventscript_Gym_Leader_Morty_5:
# 2883 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_MORTY_REMATCH, Common_Eventscript_Gym_Leader_Morty_3
	goto Common_Eventscript_Gym_Leader_Morty_4

Common_Eventscript_Gym_Leader_Morty_8:
# 2867 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_MORTY_REMATCH, Common_Eventscript_Gym_Leader_Morty_2
	goto Common_Eventscript_Gym_Leader_Morty_6

Common_Eventscript_Gym_Leader_Morty_11:
# 2887 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 12
# 2888 "data/scripts/gym_scripts.pory"
	call Common_EventScript_ClearGymTrainers
# 2889 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Morty_Text_4, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Morty_1


Common_Eventscript_Gym_Leader_Morty_Give_Gifts::
# 2930 "data/scripts/gym_scripts.pory"
	random 8
# 2932 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_GENGAR_MEGA_STONE, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_3
Common_Eventscript_Gym_Leader_Morty_Give_Gifts_1:
# 2936 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 2937 "data/scripts/gym_scripts.pory"
	case 0, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_8
# 2943 "data/scripts/gym_scripts.pory"
	case 1, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_9
# 2949 "data/scripts/gym_scripts.pory"
	case 2, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_10
# 2955 "data/scripts/gym_scripts.pory"
	case 3, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_11
# 2961 "data/scripts/gym_scripts.pory"
	case 4, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_12
# 2967 "data/scripts/gym_scripts.pory"
	case 5, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_13
# 2973 "data/scripts/gym_scripts.pory"
	case 6, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_14
# 2979 "data/scripts/gym_scripts.pory"
	case 7, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_15
Common_Eventscript_Gym_Leader_Morty_Give_Gifts_15:
# 2981 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_38
Common_Eventscript_Gym_Leader_Morty_Give_Gifts_37:
# 2984 "data/scripts/gym_scripts.pory"
	giveitem ITEM_GENGARITE, 1
# 2985 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_GENGAR_MEGA_STONE
Common_Eventscript_Gym_Leader_Morty_Give_Gifts_6:
# 2988 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_CheckForAllBadges
	return

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_2:
# 2933 "data/scripts/gym_scripts.pory"
	setvar VAR_RESULT, 7
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_1

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_3:
# 2932 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, 11
	goto_if_gt Common_Eventscript_Gym_Leader_Morty_Give_Gifts_2
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_1

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_8:
# 2938 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_17
Common_Eventscript_Gym_Leader_Morty_Give_Gifts_16:
# 2941 "data/scripts/gym_scripts.pory"
	giveitem ITEM_GHOST_GEM, 2
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_6

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_9:
# 2944 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_20
Common_Eventscript_Gym_Leader_Morty_Give_Gifts_19:
# 2947 "data/scripts/gym_scripts.pory"
	giveitem ITEM_CLEANSE_TAG, 2
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_6

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_10:
# 2950 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_23
Common_Eventscript_Gym_Leader_Morty_Give_Gifts_22:
# 2953 "data/scripts/gym_scripts.pory"
	giveitem ITEM_SPELL_TAG, 1
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_6

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_11:
# 2956 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_26
Common_Eventscript_Gym_Leader_Morty_Give_Gifts_25:
# 2959 "data/scripts/gym_scripts.pory"
	giveitem ITEM_KASIB_BERRY, 3
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_6

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_12:
# 2962 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_29
Common_Eventscript_Gym_Leader_Morty_Give_Gifts_28:
# 2965 "data/scripts/gym_scripts.pory"
	giveitem ITEM_GHOST_MEMORY, 1
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_6

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_13:
# 2968 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_32
Common_Eventscript_Gym_Leader_Morty_Give_Gifts_31:
# 2971 "data/scripts/gym_scripts.pory"
	giveitem ITEM_ODD_INCENSE, 1
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_6

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_14:
# 2974 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Morty_Give_Gifts_35
Common_Eventscript_Gym_Leader_Morty_Give_Gifts_34:
# 2977 "data/scripts/gym_scripts.pory"
	giveitem ITEM_DUSK_BALL, 5
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_6

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_17:
# 2939 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_16

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_20:
# 2945 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_19

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_23:
# 2951 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_22

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_26:
# 2957 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_25

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_29:
# 2963 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_28

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_32:
# 2969 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_31

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_35:
# 2975 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_34

Common_Eventscript_Gym_Leader_Morty_Give_Gifts_38:
# 2982 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Morty_Give_Gifts_37


Common_Eventscript_Gym_Leader_Morty_Battle_New::
# 2994 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_RECEIVED_BADGE_12, Common_Eventscript_Gym_Leader_Morty_Battle_New_2
# 3000 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Common_Eventscript_Gym_Leader_Morty_Battle_New_5
# 3006 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_MORTY, Common_Eventscript_Gym_Leader_Morty_Battle_New_Text_0
Common_Eventscript_Gym_Leader_Morty_Battle_New_1:
	return

Common_Eventscript_Gym_Leader_Morty_Battle_New_2:
# 2996 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_MORTY, Common_Eventscript_Gym_Leader_Morty_Battle_New_Text_0
	goto Common_Eventscript_Gym_Leader_Morty_Battle_New_1

Common_Eventscript_Gym_Leader_Morty_Battle_New_5:
# 3003 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_MORTY, Common_Eventscript_Gym_Leader_Morty_Battle_New_Text_1
	goto Common_Eventscript_Gym_Leader_Morty_Battle_New_1


Common_Eventscript_Gym_Leader_Chuck::
# 3015 "data/scripts/gym_scripts.pory"
	lock
# 3016 "data/scripts/gym_scripts.pory"
	faceplayer
# 3017 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_13, Common_Eventscript_Gym_Leader_Chuck_8
Common_Eventscript_Gym_Leader_Chuck_6:
# 3033 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_13, Common_Eventscript_Gym_Leader_Chuck_5
Common_Eventscript_Gym_Leader_Chuck_4:
# 3051 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Chuck_Text_5, MSGBOX_NPC
# 3053 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Chuck_Battle_New
# 3055 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Chuck_Text_6, MSGBOX_NPC
# 3056 "data/scripts/gym_scripts.pory"
	message Common_Eventscript_Gym_Leader_Chuck_Text_7
# 3057 "data/scripts/gym_scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 3058 "data/scripts/gym_scripts.pory"
	waitmessage
# 3059 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_5, MSGBOX_NPC
# 3060 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 3061 "data/scripts/gym_scripts.pory"
	setflag FLAG_RECEIVED_BADGE_13
# 3063 "data/scripts/gym_scripts.pory"
	call Special_Gym_EventScript_Give_Item
# 3064 "data/scripts/gym_scripts.pory"
	waitfanfare
# 3065 "data/scripts/gym_scripts.pory"
	closemessage
# 3067 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Chuck_Give_Gifts
# 3069 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Chuck_Text_8, MSGBOX_NPC
# 3070 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 3071 "data/scripts/gym_scripts.pory"
	clearflag FLAG_CHUCK_REMATCH
# 3072 "data/scripts/gym_scripts.pory"
	special HealPlayerParty
Common_Eventscript_Gym_Leader_Chuck_1:
# 3074 "data/scripts/gym_scripts.pory"
	release
	end

Common_Eventscript_Gym_Leader_Chuck_2:
# 3020 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Chuck_Text_0, MSGBOX_NPC
# 3022 "data/scripts/gym_scripts.pory"
	special HealPlayerParty
# 3023 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Chuck_Battle_New
# 3025 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Chuck_Text_1, MSGBOX_NPC
# 3026 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 3028 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Chuck_Give_Gifts
# 3029 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Chuck_Text_2, MSGBOX_NPC
# 3031 "data/scripts/gym_scripts.pory"
	setflag FLAG_CHUCK_REMATCH
	goto Common_Eventscript_Gym_Leader_Chuck_1

Common_Eventscript_Gym_Leader_Chuck_3:
# 3035 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Chuck_Text_3, MSGBOX_YESNO
# 3036 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Common_Eventscript_Gym_Leader_Chuck_11
# 3043 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 13
# 3044 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 3045 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Chuck_Text_2, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Chuck_1

Common_Eventscript_Gym_Leader_Chuck_5:
# 3033 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_CHUCK_REMATCH, Common_Eventscript_Gym_Leader_Chuck_3
	goto Common_Eventscript_Gym_Leader_Chuck_4

Common_Eventscript_Gym_Leader_Chuck_8:
# 3017 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_CHUCK_REMATCH, Common_Eventscript_Gym_Leader_Chuck_2
	goto Common_Eventscript_Gym_Leader_Chuck_6

Common_Eventscript_Gym_Leader_Chuck_11:
# 3037 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 13
# 3038 "data/scripts/gym_scripts.pory"
	call Common_EventScript_ClearGymTrainers
# 3039 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Chuck_Text_4, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Chuck_1


Common_Eventscript_Gym_Leader_Chuck_Give_Gifts::
# 3080 "data/scripts/gym_scripts.pory"
	random 8
# 3082 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_MACHAMP_MEGA_STONE, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_3
Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_1:
# 3086 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 3087 "data/scripts/gym_scripts.pory"
	case 0, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_8
# 3093 "data/scripts/gym_scripts.pory"
	case 1, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_9
# 3099 "data/scripts/gym_scripts.pory"
	case 2, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_10
# 3105 "data/scripts/gym_scripts.pory"
	case 3, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_11
# 3111 "data/scripts/gym_scripts.pory"
	case 4, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_12
# 3117 "data/scripts/gym_scripts.pory"
	case 5, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_13
# 3123 "data/scripts/gym_scripts.pory"
	case 6, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_14
# 3130 "data/scripts/gym_scripts.pory"
	case 7, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_15
Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_15:
# 3131 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_41
Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_40:
# 3134 "data/scripts/gym_scripts.pory"
	giveitem ITEM_MACHAMPITE, 1
# 3135 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_MACHAMP_MEGA_STONE
Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_6:
# 3138 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_CheckForAllBadges
	return

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_2:
# 3083 "data/scripts/gym_scripts.pory"
	setvar VAR_RESULT, 7
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_1

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_3:
# 3082 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, 11
	goto_if_gt Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_2
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_1

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_8:
# 3088 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_17
Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_16:
# 3091 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FIGHTING_GEM, 2
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_6

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_9:
# 3094 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_20
Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_19:
# 3097 "data/scripts/gym_scripts.pory"
	giveitem ITEM_CHOPLE_BERRY, 3
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_6

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_10:
# 3100 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_23
Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_22:
# 3103 "data/scripts/gym_scripts.pory"
	giveitem ITEM_BLACK_BELT, 1
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_6

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_11:
# 3106 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_26
Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_25:
# 3109 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FOCUS_SASH, 1
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_6

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_12:
# 3112 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_29
Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_28:
# 3115 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FIGHTING_MEMORY, 1
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_6

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_13:
# 3118 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_32
Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_31:
# 3121 "data/scripts/gym_scripts.pory"
	giveitem ITEM_CHOICE_BAND, 1
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_6

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_14:
# 3124 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_35
Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_34:
# 3127 "data/scripts/gym_scripts.pory"
	giveitem ITEM_EXPERT_BELT, 1
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_6

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_17:
# 3089 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_16

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_20:
# 3095 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_19

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_23:
# 3101 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_22

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_26:
# 3107 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_25

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_29:
# 3113 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_28

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_32:
# 3119 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_31

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_35:
# 3125 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_34

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_37:
# 3134 "data/scripts/gym_scripts.pory"
	giveitem ITEM_MACHAMPITE, 1
# 3135 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_MACHAMP_MEGA_STONE
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_6

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_38:
# 3132 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_37

# 3131 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_38
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_37

Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_41:
# 3132 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Chuck_Give_Gifts_40


Common_Eventscript_Gym_Leader_Chuck_Battle_New::
# 3144 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_RECEIVED_BADGE_13, Common_Eventscript_Gym_Leader_Chuck_Battle_New_2
# 3150 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Common_Eventscript_Gym_Leader_Chuck_Battle_New_5
# 3156 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_CHUCK, Common_Eventscript_Gym_Leader_Chuck_Battle_New_Text_1
Common_Eventscript_Gym_Leader_Chuck_Battle_New_1:
	return

Common_Eventscript_Gym_Leader_Chuck_Battle_New_2:
# 3146 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_CHUCK, Common_Eventscript_Gym_Leader_Chuck_Battle_New_Text_0
	goto Common_Eventscript_Gym_Leader_Chuck_Battle_New_1

Common_Eventscript_Gym_Leader_Chuck_Battle_New_5:
# 3153 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_CHUCK, Common_Eventscript_Gym_Leader_Chuck_Battle_New_Text_1
	goto Common_Eventscript_Gym_Leader_Chuck_Battle_New_1


Common_Eventscript_Gym_Leader_Jasmine::
# 3165 "data/scripts/gym_scripts.pory"
	lock
# 3166 "data/scripts/gym_scripts.pory"
	faceplayer
# 3167 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_14, Common_Eventscript_Gym_Leader_Jasmine_8
Common_Eventscript_Gym_Leader_Jasmine_6:
# 3183 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_14, Common_Eventscript_Gym_Leader_Jasmine_5
Common_Eventscript_Gym_Leader_Jasmine_4:
# 3201 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Jasmine_Text_5, MSGBOX_NPC
# 3203 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Jasmine_Battle_New
# 3205 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Jasmine_Text_6, MSGBOX_NPC
# 3206 "data/scripts/gym_scripts.pory"
	message Common_Eventscript_Gym_Leader_Jasmine_Text_7
# 3207 "data/scripts/gym_scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 3208 "data/scripts/gym_scripts.pory"
	waitmessage
# 3209 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_5, MSGBOX_NPC
# 3210 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 3211 "data/scripts/gym_scripts.pory"
	setflag FLAG_RECEIVED_BADGE_14
# 3213 "data/scripts/gym_scripts.pory"
	call Special_Gym_EventScript_Give_Item
# 3214 "data/scripts/gym_scripts.pory"
	waitfanfare
# 3215 "data/scripts/gym_scripts.pory"
	closemessage
# 3217 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts
# 3219 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Jasmine_Text_8, MSGBOX_NPC
# 3220 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 3221 "data/scripts/gym_scripts.pory"
	clearflag FLAG_JASMINE_REMATCH
# 3222 "data/scripts/gym_scripts.pory"
	special HealPlayerParty
Common_Eventscript_Gym_Leader_Jasmine_1:
# 3224 "data/scripts/gym_scripts.pory"
	release
	end

Common_Eventscript_Gym_Leader_Jasmine_2:
# 3170 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Jasmine_Text_0, MSGBOX_NPC
# 3172 "data/scripts/gym_scripts.pory"
	special HealPlayerParty
# 3173 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Jasmine_Battle_New
# 3175 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Jasmine_Text_1, MSGBOX_NPC
# 3176 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 3178 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts
# 3179 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Jasmine_Text_2, MSGBOX_NPC
# 3181 "data/scripts/gym_scripts.pory"
	setflag FLAG_JASMINE_REMATCH
	goto Common_Eventscript_Gym_Leader_Jasmine_1

Common_Eventscript_Gym_Leader_Jasmine_3:
# 3185 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Jasmine_Text_3, MSGBOX_YESNO
# 3186 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Common_Eventscript_Gym_Leader_Jasmine_11
# 3193 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 14
# 3194 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 3195 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Jasmine_Text_2, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Jasmine_1

Common_Eventscript_Gym_Leader_Jasmine_5:
# 3183 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_JASMINE_REMATCH, Common_Eventscript_Gym_Leader_Jasmine_3
	goto Common_Eventscript_Gym_Leader_Jasmine_4

Common_Eventscript_Gym_Leader_Jasmine_8:
# 3167 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_JASMINE_REMATCH, Common_Eventscript_Gym_Leader_Jasmine_2
	goto Common_Eventscript_Gym_Leader_Jasmine_6

Common_Eventscript_Gym_Leader_Jasmine_11:
# 3187 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 14
# 3188 "data/scripts/gym_scripts.pory"
	call Common_EventScript_ClearGymTrainers
# 3189 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Jasmine_Text_4, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Jasmine_1


Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts::
# 3230 "data/scripts/gym_scripts.pory"
	random 8
# 3232 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_STEELIX_MEGA_STONE, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_3
Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_1:
# 3236 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 3237 "data/scripts/gym_scripts.pory"
	case 0, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_8
# 3243 "data/scripts/gym_scripts.pory"
	case 1, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_9
# 3249 "data/scripts/gym_scripts.pory"
	case 2, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_10
# 3255 "data/scripts/gym_scripts.pory"
	case 3, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_11
# 3261 "data/scripts/gym_scripts.pory"
	case 4, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_12
# 3267 "data/scripts/gym_scripts.pory"
	case 5, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_13
# 3273 "data/scripts/gym_scripts.pory"
	case 6, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_14
# 3279 "data/scripts/gym_scripts.pory"
	case 7, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_15
Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_15:
# 3281 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_38
Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_37:
# 3284 "data/scripts/gym_scripts.pory"
	giveitem ITEM_STEELIXITE, 1
# 3285 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_STEELIX_MEGA_STONE
Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_6:
# 3288 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_CheckForAllBadges
	return

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_2:
# 3233 "data/scripts/gym_scripts.pory"
	setvar VAR_RESULT, 7
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_1

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_3:
# 3232 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, 11
	goto_if_gt Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_2
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_1

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_8:
# 3238 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_17
Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_16:
# 3241 "data/scripts/gym_scripts.pory"
	giveitem ITEM_STEEL_GEM, 2
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_6

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_9:
# 3244 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_20
Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_19:
# 3247 "data/scripts/gym_scripts.pory"
	giveitem ITEM_BABIRI_BERRY, 3
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_6

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_10:
# 3250 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_23
Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_22:
# 3253 "data/scripts/gym_scripts.pory"
	giveitem ITEM_METAL_COAT, 1
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_6

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_11:
# 3256 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_26
Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_25:
# 3259 "data/scripts/gym_scripts.pory"
	giveitem ITEM_ASSAULT_VEST, 1
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_6

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_12:
# 3262 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_29
Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_28:
# 3265 "data/scripts/gym_scripts.pory"
	giveitem ITEM_STEEL_MEMORY, 1
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_6

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_13:
# 3268 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_32
Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_31:
# 3271 "data/scripts/gym_scripts.pory"
	giveitem ITEM_EJECT_BUTTON, 1
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_6

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_14:
# 3274 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_35
Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_34:
# 3277 "data/scripts/gym_scripts.pory"
	giveitem ITEM_IRON_BALL, 1
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_6

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_17:
# 3239 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_16

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_20:
# 3245 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_19

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_23:
# 3251 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_22

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_26:
# 3257 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_25

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_29:
# 3263 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_28

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_32:
# 3269 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_31

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_35:
# 3275 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_34

Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_38:
# 3282 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Jasmine_Give_Gifts_37


Common_Eventscript_Gym_Leader_Jasmine_Battle_New::
# 3294 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_RECEIVED_BADGE_14, Common_Eventscript_Gym_Leader_Jasmine_Battle_New_2
# 3300 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Common_Eventscript_Gym_Leader_Jasmine_Battle_New_5
# 3306 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_JASMINE, Common_Eventscript_Gym_Leader_Jasmine_Battle_New_Text_1
Common_Eventscript_Gym_Leader_Jasmine_Battle_New_1:
	return

Common_Eventscript_Gym_Leader_Jasmine_Battle_New_2:
# 3296 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_JASMINE, Common_Eventscript_Gym_Leader_Jasmine_Battle_New_Text_0
	goto Common_Eventscript_Gym_Leader_Jasmine_Battle_New_1

Common_Eventscript_Gym_Leader_Jasmine_Battle_New_5:
# 3303 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_JASMINE, Common_Eventscript_Gym_Leader_Jasmine_Battle_New_Text_1
	goto Common_Eventscript_Gym_Leader_Jasmine_Battle_New_1


Common_Eventscript_Gym_Leader_Pryce::
# 3315 "data/scripts/gym_scripts.pory"
	lock
# 3316 "data/scripts/gym_scripts.pory"
	faceplayer
# 3317 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_15, Common_Eventscript_Gym_Leader_Pryce_8
Common_Eventscript_Gym_Leader_Pryce_6:
# 3333 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_15, Common_Eventscript_Gym_Leader_Pryce_5
Common_Eventscript_Gym_Leader_Pryce_4:
# 3351 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Pryce_Text_5, MSGBOX_NPC
# 3353 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Pryce_Battle_New
# 3355 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Pryce_Text_6, MSGBOX_NPC
# 3356 "data/scripts/gym_scripts.pory"
	message Common_Eventscript_Gym_Leader_Pryce_Text_7
# 3357 "data/scripts/gym_scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 3358 "data/scripts/gym_scripts.pory"
	waitmessage
# 3359 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_5, MSGBOX_NPC
# 3360 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 3361 "data/scripts/gym_scripts.pory"
	setflag FLAG_RECEIVED_BADGE_15
# 3363 "data/scripts/gym_scripts.pory"
	call Special_Gym_EventScript_Give_Item
# 3364 "data/scripts/gym_scripts.pory"
	waitfanfare
# 3365 "data/scripts/gym_scripts.pory"
	closemessage
# 3367 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Pryce_Give_Gifts
# 3369 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Pryce_Text_8, MSGBOX_NPC
# 3370 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 3371 "data/scripts/gym_scripts.pory"
	clearflag FLAG_PRYCE_REMATCH
# 3372 "data/scripts/gym_scripts.pory"
	special HealPlayerParty
Common_Eventscript_Gym_Leader_Pryce_1:
# 3374 "data/scripts/gym_scripts.pory"
	release
	end

Common_Eventscript_Gym_Leader_Pryce_2:
# 3320 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Pryce_Text_0, MSGBOX_NPC
# 3322 "data/scripts/gym_scripts.pory"
	special HealPlayerParty
# 3323 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Pryce_Battle_New
# 3325 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Pryce_Text_1, MSGBOX_NPC
# 3326 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 3328 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Pryce_Give_Gifts
# 3329 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Pryce_Text_2, MSGBOX_NPC
# 3331 "data/scripts/gym_scripts.pory"
	setflag FLAG_PRYCE_REMATCH
	goto Common_Eventscript_Gym_Leader_Pryce_1

Common_Eventscript_Gym_Leader_Pryce_3:
# 3335 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Pryce_Text_3, MSGBOX_YESNO
# 3336 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Common_Eventscript_Gym_Leader_Pryce_11
# 3343 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 15
# 3344 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 3345 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Pryce_Text_2, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Pryce_1

Common_Eventscript_Gym_Leader_Pryce_5:
# 3333 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_PRYCE_REMATCH, Common_Eventscript_Gym_Leader_Pryce_3
	goto Common_Eventscript_Gym_Leader_Pryce_4

Common_Eventscript_Gym_Leader_Pryce_8:
# 3317 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_PRYCE_REMATCH, Common_Eventscript_Gym_Leader_Pryce_2
	goto Common_Eventscript_Gym_Leader_Pryce_6

Common_Eventscript_Gym_Leader_Pryce_11:
# 3337 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 15
# 3338 "data/scripts/gym_scripts.pory"
	call Common_EventScript_ClearGymTrainers
# 3339 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Pryce_Text_4, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Pryce_1


Common_Eventscript_Gym_Leader_Pryce_Give_Gifts::
# 3380 "data/scripts/gym_scripts.pory"
	random 8
# 3382 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_LAPRAS_MEGA_STONE, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_3
Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_1:
# 3385 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 3386 "data/scripts/gym_scripts.pory"
	case 0, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_8
# 3392 "data/scripts/gym_scripts.pory"
	case 1, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_9
# 3398 "data/scripts/gym_scripts.pory"
	case 2, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_10
# 3404 "data/scripts/gym_scripts.pory"
	case 3, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_11
# 3410 "data/scripts/gym_scripts.pory"
	case 4, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_12
# 3416 "data/scripts/gym_scripts.pory"
	case 5, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_13
# 3422 "data/scripts/gym_scripts.pory"
	case 6, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_14
# 3428 "data/scripts/gym_scripts.pory"
	case 7, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_15
Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_15:
# 3430 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_38
Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_37:
# 3433 "data/scripts/gym_scripts.pory"
	giveitem ITEM_LAPRITE, 1
# 3434 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_LAPRAS_MEGA_STONE
Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_6:
# 3437 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_CheckForAllBadges
	return

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_2:
# 3383 "data/scripts/gym_scripts.pory"
	setvar VAR_RESULT, 7
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_1

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_3:
# 3382 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, 11
	goto_if_gt Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_2
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_1

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_8:
# 3387 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_17
Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_16:
# 3390 "data/scripts/gym_scripts.pory"
	giveitem ITEM_ICE_GEM, 2
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_6

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_9:
# 3393 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_20
Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_19:
# 3396 "data/scripts/gym_scripts.pory"
	giveitem ITEM_YACHE_BERRY, 3
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_6

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_10:
# 3399 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_23
Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_22:
# 3402 "data/scripts/gym_scripts.pory"
	giveitem ITEM_SNOWBALL, 1
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_6

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_11:
# 3405 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_26
Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_25:
# 3408 "data/scripts/gym_scripts.pory"
	giveitem ITEM_NEVER_MELT_ICE, 1
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_6

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_12:
# 3411 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_29
Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_28:
# 3414 "data/scripts/gym_scripts.pory"
	giveitem ITEM_ICE_MEMORY, 1
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_6

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_13:
# 3417 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_32
Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_31:
# 3420 "data/scripts/gym_scripts.pory"
	giveitem ITEM_ICY_ROCK, 1
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_6

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_14:
# 3423 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_35
Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_34:
# 3426 "data/scripts/gym_scripts.pory"
	giveitem ITEM_ICE_STONE, 1
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_6

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_17:
# 3388 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_16

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_20:
# 3394 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_19

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_23:
# 3400 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_22

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_26:
# 3406 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_25

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_29:
# 3412 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_28

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_32:
# 3418 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_31

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_35:
# 3424 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_34

Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_38:
# 3431 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Pryce_Give_Gifts_37


Common_Eventscript_Gym_Leader_Pryce_Battle_New::
# 3443 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_RECEIVED_BADGE_15, Common_Eventscript_Gym_Leader_Pryce_Battle_New_2
# 3449 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Common_Eventscript_Gym_Leader_Pryce_Battle_New_5
# 3455 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_PRYCE, Common_Eventscript_Gym_Leader_Pryce_Battle_New_Text_1
Common_Eventscript_Gym_Leader_Pryce_Battle_New_1:
	return

Common_Eventscript_Gym_Leader_Pryce_Battle_New_2:
# 3445 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_PRYCE, Common_Eventscript_Gym_Leader_Pryce_Battle_New_Text_0
	goto Common_Eventscript_Gym_Leader_Pryce_Battle_New_1

Common_Eventscript_Gym_Leader_Pryce_Battle_New_5:
# 3452 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_PRYCE, Common_Eventscript_Gym_Leader_Pryce_Battle_New_Text_1
	goto Common_Eventscript_Gym_Leader_Pryce_Battle_New_1


Common_Eventscript_Gym_Leader_Clair::
# 3465 "data/scripts/gym_scripts.pory"
	lock
# 3466 "data/scripts/gym_scripts.pory"
	faceplayer
# 3467 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_16, Common_Eventscript_Gym_Leader_Clair_8
Common_Eventscript_Gym_Leader_Clair_6:
# 3483 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_16, Common_Eventscript_Gym_Leader_Clair_5
Common_Eventscript_Gym_Leader_Clair_4:
# 3501 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Clair_Text_5, MSGBOX_NPC
# 3503 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Clair_Battle_New
# 3505 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Clair_Text_6, MSGBOX_NPC
# 3506 "data/scripts/gym_scripts.pory"
	message Common_Eventscript_Gym_Leader_Clair_Text_7
# 3507 "data/scripts/gym_scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 3508 "data/scripts/gym_scripts.pory"
	waitmessage
# 3509 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_5, MSGBOX_NPC
# 3510 "data/scripts/gym_scripts.pory"
	setflag FLAG_TEMP_9
# 3511 "data/scripts/gym_scripts.pory"
	setflag FLAG_RECEIVED_BADGE_16
# 3513 "data/scripts/gym_scripts.pory"
	call Special_Gym_EventScript_Give_Item
# 3514 "data/scripts/gym_scripts.pory"
	waitfanfare
# 3515 "data/scripts/gym_scripts.pory"
	closemessage
# 3517 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Clair_Give_Gifts
# 3519 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Clair_Text_8, MSGBOX_NPC
# 3520 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 3521 "data/scripts/gym_scripts.pory"
	clearflag FLAG_CLAIR_REMATCH
# 3522 "data/scripts/gym_scripts.pory"
	special HealPlayerParty
Common_Eventscript_Gym_Leader_Clair_1:
# 3524 "data/scripts/gym_scripts.pory"
	release
	end

Common_Eventscript_Gym_Leader_Clair_2:
# 3470 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Clair_Text_0, MSGBOX_NPC
# 3472 "data/scripts/gym_scripts.pory"
	special HealPlayerParty
# 3473 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Clair_Battle_New
# 3475 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Clair_Text_1, MSGBOX_NPC
# 3476 "data/scripts/gym_scripts.pory"
	call Gym_EventScript_Reset_Rematches
# 3478 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_Clair_Give_Gifts
# 3479 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Clair_Text_2, MSGBOX_NPC
# 3481 "data/scripts/gym_scripts.pory"
	setflag FLAG_CLAIR_REMATCH
	goto Common_Eventscript_Gym_Leader_Clair_1

Common_Eventscript_Gym_Leader_Clair_3:
# 3485 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Clair_Text_3, MSGBOX_YESNO
# 3486 "data/scripts/gym_scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Common_Eventscript_Gym_Leader_Clair_11
# 3493 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 16
# 3494 "data/scripts/gym_scripts.pory"
	call Common_EventScript_SetGymTrainers
# 3495 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Clair_Text_2, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Clair_1

Common_Eventscript_Gym_Leader_Clair_5:
# 3483 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_CLAIR_REMATCH, Common_Eventscript_Gym_Leader_Clair_3
	goto Common_Eventscript_Gym_Leader_Clair_4

Common_Eventscript_Gym_Leader_Clair_8:
# 3467 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_CLAIR_REMATCH, Common_Eventscript_Gym_Leader_Clair_2
	goto Common_Eventscript_Gym_Leader_Clair_6

Common_Eventscript_Gym_Leader_Clair_11:
# 3487 "data/scripts/gym_scripts.pory"
	setvar VAR_0x8008, 16
# 3488 "data/scripts/gym_scripts.pory"
	call Common_EventScript_ClearGymTrainers
# 3489 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Clair_Text_4, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Clair_1


Common_Eventscript_Gym_Leader_Clair_Give_Gifts::
# 3530 "data/scripts/gym_scripts.pory"
	random 8
# 3532 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_GOT_FLAPPLE_MEGA_STONE, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_3
Common_Eventscript_Gym_Leader_Clair_Give_Gifts_1:
# 3535 "data/scripts/gym_scripts.pory"
	switch VAR_RESULT
# 3536 "data/scripts/gym_scripts.pory"
	case 0, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_8
# 3542 "data/scripts/gym_scripts.pory"
	case 1, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_9
# 3548 "data/scripts/gym_scripts.pory"
	case 2, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_10
# 3554 "data/scripts/gym_scripts.pory"
	case 3, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_11
# 3560 "data/scripts/gym_scripts.pory"
	case 4, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_12
# 3566 "data/scripts/gym_scripts.pory"
	case 5, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_13
# 3572 "data/scripts/gym_scripts.pory"
	case 6, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_14
# 3578 "data/scripts/gym_scripts.pory"
	case 7, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_15
Common_Eventscript_Gym_Leader_Clair_Give_Gifts_15:
# 3580 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_38
Common_Eventscript_Gym_Leader_Clair_Give_Gifts_37:
# 3583 "data/scripts/gym_scripts.pory"
	giveitem ITEM_FLAPPLITE, 1
# 3584 "data/scripts/gym_scripts.pory"
	setflag FLAG_GOT_FLAPPLE_MEGA_STONE
Common_Eventscript_Gym_Leader_Clair_Give_Gifts_6:
# 3587 "data/scripts/gym_scripts.pory"
	call Common_Eventscript_Gym_Leader_CheckForAllBadges
	return

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_2:
# 3533 "data/scripts/gym_scripts.pory"
	setvar VAR_RESULT, 7
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_1

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_3:
# 3532 "data/scripts/gym_scripts.pory"
	compare VAR_NUM_BADGES, 11
	goto_if_gt Common_Eventscript_Gym_Leader_Clair_Give_Gifts_2
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_1

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_8:
# 3537 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_17
Common_Eventscript_Gym_Leader_Clair_Give_Gifts_16:
# 3540 "data/scripts/gym_scripts.pory"
	giveitem ITEM_DRAGON_GEM, 2
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_6

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_9:
# 3543 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_20
Common_Eventscript_Gym_Leader_Clair_Give_Gifts_19:
# 3546 "data/scripts/gym_scripts.pory"
	giveitem ITEM_HABAN_BERRY, 3
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_6

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_10:
# 3549 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_23
Common_Eventscript_Gym_Leader_Clair_Give_Gifts_22:
# 3552 "data/scripts/gym_scripts.pory"
	giveitem ITEM_DRAGON_SCALE, 1
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_6

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_11:
# 3555 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_26
Common_Eventscript_Gym_Leader_Clair_Give_Gifts_25:
# 3558 "data/scripts/gym_scripts.pory"
	giveitem ITEM_DRAGON_FANG, 1
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_6

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_12:
# 3561 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_29
Common_Eventscript_Gym_Leader_Clair_Give_Gifts_28:
# 3564 "data/scripts/gym_scripts.pory"
	giveitem ITEM_DRAGON_MEMORY, 1
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_6

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_13:
# 3567 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_32
Common_Eventscript_Gym_Leader_Clair_Give_Gifts_31:
# 3570 "data/scripts/gym_scripts.pory"
	giveitem ITEM_LIFE_ORB, 1
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_6

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_14:
# 3573 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_TEMP_9, Common_Eventscript_Gym_Leader_Clair_Give_Gifts_35
Common_Eventscript_Gym_Leader_Clair_Give_Gifts_34:
# 3576 "data/scripts/gym_scripts.pory"
	giveitem ITEM_EVIOLITE, 1
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_6

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_17:
# 3538 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_16

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_20:
# 3544 "data/scripts/gym_scripts.pory"
	msgbox RustboroCity_Gym_EventScript_Roxanne_New_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_19

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_23:
# 3550 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_22

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_26:
# 3556 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_25

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_29:
# 3562 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_28

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_32:
# 3568 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_31

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_35:
# 3574 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_34

Common_Eventscript_Gym_Leader_Clair_Give_Gifts_38:
# 3581 "data/scripts/gym_scripts.pory"
	msgbox Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0, MSGBOX_NPC
	goto Common_Eventscript_Gym_Leader_Clair_Give_Gifts_37


Common_Eventscript_Gym_Leader_Clair_Battle_New::
# 3593 "data/scripts/gym_scripts.pory"
	goto_if_unset FLAG_RECEIVED_BADGE_16, Common_Eventscript_Gym_Leader_Clair_Battle_New_2
# 3599 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Common_Eventscript_Gym_Leader_Clair_Battle_New_5
# 3605 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_CLAIR, Common_Eventscript_Gym_Leader_Clair_Battle_New_Text_2
Common_Eventscript_Gym_Leader_Clair_Battle_New_1:
	return

Common_Eventscript_Gym_Leader_Clair_Battle_New_2:
# 3595 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_CLAIR, Common_Eventscript_Gym_Leader_Clair_Battle_New_Text_0
	goto Common_Eventscript_Gym_Leader_Clair_Battle_New_1

Common_Eventscript_Gym_Leader_Clair_Battle_New_5:
# 3602 "data/scripts/gym_scripts.pory"
	trainerbattle_no_intro TRAINER_LEADER_CLAIR, Common_Eventscript_Gym_Leader_Clair_Battle_New_Text_1
	goto Common_Eventscript_Gym_Leader_Clair_Battle_New_1


Common_Eventscript_Gym_Leader_CheckForAllBadges::
# 3612 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE01_GET, Common_Eventscript_Gym_Leader_CheckForAllBadges_3
	return

Common_Eventscript_Gym_Leader_CheckForAllBadges_1:
# 3628 "data/scripts/gym_scripts.pory"
	setflag FLAG_DEFEATED_ALL_GYMS
	return

Common_Eventscript_Gym_Leader_CheckForAllBadges_2:
# 3614 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE03_GET, Common_Eventscript_Gym_Leader_CheckForAllBadges_7
	return

Common_Eventscript_Gym_Leader_CheckForAllBadges_3:
# 3613 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE02_GET, Common_Eventscript_Gym_Leader_CheckForAllBadges_2
	return

Common_Eventscript_Gym_Leader_CheckForAllBadges_6:
# 3616 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE05_GET, Common_Eventscript_Gym_Leader_CheckForAllBadges_11
	return

Common_Eventscript_Gym_Leader_CheckForAllBadges_7:
# 3615 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE04_GET, Common_Eventscript_Gym_Leader_CheckForAllBadges_6
	return

Common_Eventscript_Gym_Leader_CheckForAllBadges_10:
# 3618 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE07_GET, Common_Eventscript_Gym_Leader_CheckForAllBadges_15
	return

Common_Eventscript_Gym_Leader_CheckForAllBadges_11:
# 3617 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE06_GET, Common_Eventscript_Gym_Leader_CheckForAllBadges_10
	return

Common_Eventscript_Gym_Leader_CheckForAllBadges_14:
# 3620 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_09, Common_Eventscript_Gym_Leader_CheckForAllBadges_19
	return

Common_Eventscript_Gym_Leader_CheckForAllBadges_15:
# 3619 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_BADGE08_GET, Common_Eventscript_Gym_Leader_CheckForAllBadges_14
	return

Common_Eventscript_Gym_Leader_CheckForAllBadges_18:
# 3622 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_11, Common_Eventscript_Gym_Leader_CheckForAllBadges_23
	return

Common_Eventscript_Gym_Leader_CheckForAllBadges_19:
# 3621 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_10, Common_Eventscript_Gym_Leader_CheckForAllBadges_18
	return

Common_Eventscript_Gym_Leader_CheckForAllBadges_22:
# 3624 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_13, Common_Eventscript_Gym_Leader_CheckForAllBadges_27
	return

Common_Eventscript_Gym_Leader_CheckForAllBadges_23:
# 3623 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_12, Common_Eventscript_Gym_Leader_CheckForAllBadges_22
	return

Common_Eventscript_Gym_Leader_CheckForAllBadges_26:
# 3626 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_15, Common_Eventscript_Gym_Leader_CheckForAllBadges_30
	return

Common_Eventscript_Gym_Leader_CheckForAllBadges_27:
# 3625 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_14, Common_Eventscript_Gym_Leader_CheckForAllBadges_26
	return

Common_Eventscript_Gym_Leader_CheckForAllBadges_30:
# 3627 "data/scripts/gym_scripts.pory"
	goto_if_set FLAG_RECEIVED_BADGE_16, Common_Eventscript_Gym_Leader_CheckForAllBadges_1
	return


Common_EventScript_SetGymTrainers::
# 3635 "data/scripts/gym_scripts.pory"
	switch VAR_0x8008
# 3637 "data/scripts/gym_scripts.pory"
	case 1, Common_EventScript_SetGymTrainers_3
# 3644 "data/scripts/gym_scripts.pory"
	case 2, Common_EventScript_SetGymTrainers_4
# 3653 "data/scripts/gym_scripts.pory"
	case 3, Common_EventScript_SetGymTrainers_5
# 3661 "data/scripts/gym_scripts.pory"
	case 4, Common_EventScript_SetGymTrainers_6
# 3672 "data/scripts/gym_scripts.pory"
	case 5, Common_EventScript_SetGymTrainers_7
# 3682 "data/scripts/gym_scripts.pory"
	case 6, Common_EventScript_SetGymTrainers_8
# 3691 "data/scripts/gym_scripts.pory"
	case 7, Common_EventScript_SetGymTrainers_9
# 3705 "data/scripts/gym_scripts.pory"
	case 8, Common_EventScript_SetGymTrainers_10
# 3718 "data/scripts/gym_scripts.pory"
	case 9, Common_EventScript_SetGymTrainers_11
# 3723 "data/scripts/gym_scripts.pory"
	case 10, Common_EventScript_SetGymTrainers_12
# 3730 "data/scripts/gym_scripts.pory"
	case 11, Common_EventScript_SetGymTrainers_13
# 3737 "data/scripts/gym_scripts.pory"
	case 12, Common_EventScript_SetGymTrainers_14
# 3744 "data/scripts/gym_scripts.pory"
	case 13, Common_EventScript_SetGymTrainers_15
# 3751 "data/scripts/gym_scripts.pory"
	case 14, Common_EventScript_SetGymTrainers_16
# 3754 "data/scripts/gym_scripts.pory"
	case 15, Common_EventScript_SetGymTrainers_17
# 3762 "data/scripts/gym_scripts.pory"
	case 16, Common_EventScript_SetGymTrainers_18
Common_EventScript_SetGymTrainers_1:
	return

Common_EventScript_SetGymTrainers_3:
# 3638 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_JOSH
# 3639 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_TOMMY
# 3640 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_MARC
# 3641 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_SYLVIA
	goto Common_EventScript_SetGymTrainers_1

Common_EventScript_SetGymTrainers_4:
# 3645 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_TAKAO
# 3646 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_JOCELYN
# 3647 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_LAURA
# 3648 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BRENDEN
# 3649 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_CRISTIAN
# 3650 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_LILITH
	goto Common_EventScript_SetGymTrainers_1

Common_EventScript_SetGymTrainers_5:
# 3654 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_KIRK
# 3655 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_SHAWN
# 3656 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BEN
# 3657 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_VIVIAN
# 3658 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_ANGELO
	goto Common_EventScript_SetGymTrainers_1

Common_EventScript_SetGymTrainers_6:
# 3662 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_COLE
# 3663 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_AXLE
# 3664 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_KEEGAN
# 3665 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_GERALD
# 3666 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_DANIELLE
# 3667 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_JACE
# 3668 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_JEFF
# 3669 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_ELI
	goto Common_EventScript_SetGymTrainers_1

Common_EventScript_SetGymTrainers_7:
# 3673 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_RANDALL
# 3674 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_PARKER
# 3675 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_GEORGE
# 3676 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BERKE
# 3677 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_MARY
# 3678 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_ALEXIA
# 3679 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_JODY
	goto Common_EventScript_SetGymTrainers_1

Common_EventScript_SetGymTrainers_8:
# 3683 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_JARED
# 3684 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_FLINT
# 3685 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_ASHLEY
# 3686 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_EDWARDO
# 3687 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_HUMBERTO
# 3688 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_DARIUS
	goto Common_EventScript_SetGymTrainers_1

Common_EventScript_SetGymTrainers_9:
# 3692 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_PRESTON
# 3693 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_VIRGIL
# 3694 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BLAKE
# 3695 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_HANNAH
# 3696 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_SAMANTHA
# 3697 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_MAURA
# 3698 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_NATE
# 3699 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_KATHLEEN
# 3700 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_CLIFFORD
# 3701 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_MACEY
# 3702 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_NICHOLAS
	goto Common_EventScript_SetGymTrainers_1

Common_EventScript_SetGymTrainers_10:
# 3706 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_ANDREA
# 3707 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_CRISSY
# 3708 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BRIANNA
# 3709 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_CONNIE
# 3710 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BRIDGET
# 3711 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_OLIVIA
# 3712 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_TIFFANY
# 3713 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BETHANY
# 3714 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_ANNIKA
# 3715 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_DAPHNE
	goto Common_EventScript_SetGymTrainers_1

Common_EventScript_SetGymTrainers_11:
# 3719 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BIRD_KEEPER_ROD
# 3720 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BIRD_KEEPER_ABE
	goto Common_EventScript_SetGymTrainers_1

Common_EventScript_SetGymTrainers_12:
# 3724 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_TWINS_AMY_AND_MAY
# 3725 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BUG_CATCHER_BENNY
# 3726 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BUG_CATCHER_AL
# 3727 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BUG_CATCHER_JOSH
	goto Common_EventScript_SetGymTrainers_1

Common_EventScript_SetGymTrainers_13:
# 3731 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BEAUTY_VICTORIA
# 3732 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BEAUTY_SAMANTHA
# 3733 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_LASS_CARRIE
# 3734 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_LASS_BRIDGET
	goto Common_EventScript_SetGymTrainers_1

Common_EventScript_SetGymTrainers_14:
# 3738 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_SAGE_JEFFREY
# 3739 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_SAGE_PING
# 3740 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_MEDIUM_MARTHA
# 3741 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_MEDIUM_GRACE
	goto Common_EventScript_SetGymTrainers_1

Common_EventScript_SetGymTrainers_15:
# 3745 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BLACKBELT_YOSHI
# 3746 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BLACKBELT_LAO
# 3747 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BLACKBELT_NOB
# 3748 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BLACKBELT_LUNG
	goto Common_EventScript_SetGymTrainers_1

Common_EventScript_SetGymTrainers_16:
	goto Common_EventScript_SetGymTrainers_1

Common_EventScript_SetGymTrainers_17:
# 3755 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_SKIER_ROXANNE
# 3756 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_SKIER_CLARISSA
# 3757 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BOARDER_RONALD
# 3758 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BOARDER_BRAD
# 3759 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_BOARDER_DOUGLAS
	goto Common_EventScript_SetGymTrainers_1

Common_EventScript_SetGymTrainers_18:
# 3763 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_COOLTRAINERM_CODY
# 3764 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_COOLTRAINERF_FRAN
# 3765 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_COOLTRAINERM_PAUL
# 3766 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_COOLTRAINERM_MIKE
# 3767 "data/scripts/gym_scripts.pory"
	settrainerflag TRAINER_COOLTRAINERF_LOLA
	goto Common_EventScript_SetGymTrainers_1


Common_EventScript_ClearGymTrainers::
# 3774 "data/scripts/gym_scripts.pory"
	switch VAR_0x8008
# 3776 "data/scripts/gym_scripts.pory"
	case 1, Common_EventScript_ClearGymTrainers_3
# 3783 "data/scripts/gym_scripts.pory"
	case 2, Common_EventScript_ClearGymTrainers_4
# 3792 "data/scripts/gym_scripts.pory"
	case 3, Common_EventScript_ClearGymTrainers_5
# 3800 "data/scripts/gym_scripts.pory"
	case 4, Common_EventScript_ClearGymTrainers_6
# 3811 "data/scripts/gym_scripts.pory"
	case 5, Common_EventScript_ClearGymTrainers_7
# 3821 "data/scripts/gym_scripts.pory"
	case 6, Common_EventScript_ClearGymTrainers_8
# 3830 "data/scripts/gym_scripts.pory"
	case 7, Common_EventScript_ClearGymTrainers_9
# 3844 "data/scripts/gym_scripts.pory"
	case 8, Common_EventScript_ClearGymTrainers_10
# 3857 "data/scripts/gym_scripts.pory"
	case 9, Common_EventScript_ClearGymTrainers_11
# 3862 "data/scripts/gym_scripts.pory"
	case 10, Common_EventScript_ClearGymTrainers_12
# 3869 "data/scripts/gym_scripts.pory"
	case 11, Common_EventScript_ClearGymTrainers_13
# 3876 "data/scripts/gym_scripts.pory"
	case 12, Common_EventScript_ClearGymTrainers_14
# 3883 "data/scripts/gym_scripts.pory"
	case 13, Common_EventScript_ClearGymTrainers_15
# 3890 "data/scripts/gym_scripts.pory"
	case 14, Common_EventScript_ClearGymTrainers_16
# 3893 "data/scripts/gym_scripts.pory"
	case 15, Common_EventScript_ClearGymTrainers_17
# 3901 "data/scripts/gym_scripts.pory"
	case 16, Common_EventScript_ClearGymTrainers_18
Common_EventScript_ClearGymTrainers_1:
	return

Common_EventScript_ClearGymTrainers_3:
# 3777 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_JOSH
# 3778 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_TOMMY
# 3779 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_MARC
# 3780 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_SYLVIA
	goto Common_EventScript_ClearGymTrainers_1

Common_EventScript_ClearGymTrainers_4:
# 3784 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_TAKAO
# 3785 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_JOCELYN
# 3786 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_LAURA
# 3787 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BRENDEN
# 3788 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_CRISTIAN
# 3789 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_LILITH
	goto Common_EventScript_ClearGymTrainers_1

Common_EventScript_ClearGymTrainers_5:
# 3793 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_KIRK
# 3794 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_SHAWN
# 3795 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BEN
# 3796 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_VIVIAN
# 3797 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_ANGELO
	goto Common_EventScript_ClearGymTrainers_1

Common_EventScript_ClearGymTrainers_6:
# 3801 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_COLE
# 3802 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_AXLE
# 3803 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_KEEGAN
# 3804 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_GERALD
# 3805 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_DANIELLE
# 3806 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_JACE
# 3807 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_JEFF
# 3808 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_ELI
	goto Common_EventScript_ClearGymTrainers_1

Common_EventScript_ClearGymTrainers_7:
# 3812 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_RANDALL
# 3813 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_PARKER
# 3814 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_GEORGE
# 3815 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BERKE
# 3816 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_MARY
# 3817 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_ALEXIA
# 3818 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_JODY
	goto Common_EventScript_ClearGymTrainers_1

Common_EventScript_ClearGymTrainers_8:
# 3822 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_JARED
# 3823 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_FLINT
# 3824 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_ASHLEY
# 3825 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_EDWARDO
# 3826 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_HUMBERTO
# 3827 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_DARIUS
	goto Common_EventScript_ClearGymTrainers_1

Common_EventScript_ClearGymTrainers_9:
# 3831 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_PRESTON
# 3832 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_VIRGIL
# 3833 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BLAKE
# 3834 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_HANNAH
# 3835 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_SAMANTHA
# 3836 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_MAURA
# 3837 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_NATE
# 3838 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_KATHLEEN
# 3839 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_CLIFFORD
# 3840 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_MACEY
# 3841 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_NICHOLAS
	goto Common_EventScript_ClearGymTrainers_1

Common_EventScript_ClearGymTrainers_10:
# 3845 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_ANDREA
# 3846 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_CRISSY
# 3847 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BRIANNA
# 3848 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_CONNIE
# 3849 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BRIDGET
# 3850 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_OLIVIA
# 3851 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_TIFFANY
# 3852 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BETHANY
# 3853 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_ANNIKA
# 3854 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_DAPHNE
	goto Common_EventScript_ClearGymTrainers_1

Common_EventScript_ClearGymTrainers_11:
# 3858 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BIRD_KEEPER_ROD
# 3859 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BIRD_KEEPER_ABE
	goto Common_EventScript_ClearGymTrainers_1

Common_EventScript_ClearGymTrainers_12:
# 3863 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_TWINS_AMY_AND_MAY
# 3864 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BUG_CATCHER_BENNY
# 3865 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BUG_CATCHER_AL
# 3866 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BUG_CATCHER_JOSH
	goto Common_EventScript_ClearGymTrainers_1

Common_EventScript_ClearGymTrainers_13:
# 3870 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BEAUTY_VICTORIA
# 3871 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BEAUTY_SAMANTHA
# 3872 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_LASS_CARRIE
# 3873 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_LASS_BRIDGET
	goto Common_EventScript_ClearGymTrainers_1

Common_EventScript_ClearGymTrainers_14:
# 3877 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_SAGE_JEFFREY
# 3878 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_SAGE_PING
# 3879 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_MEDIUM_MARTHA
# 3880 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_MEDIUM_GRACE
	goto Common_EventScript_ClearGymTrainers_1

Common_EventScript_ClearGymTrainers_15:
# 3884 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BLACKBELT_YOSHI
# 3885 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BLACKBELT_LAO
# 3886 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BLACKBELT_NOB
# 3887 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BLACKBELT_LUNG
	goto Common_EventScript_ClearGymTrainers_1

Common_EventScript_ClearGymTrainers_16:
	goto Common_EventScript_ClearGymTrainers_1

Common_EventScript_ClearGymTrainers_17:
# 3894 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_SKIER_ROXANNE
# 3895 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_SKIER_CLARISSA
# 3896 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BOARDER_RONALD
# 3897 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BOARDER_BRAD
# 3898 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_BOARDER_DOUGLAS
	goto Common_EventScript_ClearGymTrainers_1

Common_EventScript_ClearGymTrainers_18:
# 3902 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_COOLTRAINERM_CODY
# 3903 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_COOLTRAINERF_FRAN
# 3904 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_COOLTRAINERM_PAUL
# 3905 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_COOLTRAINERM_MIKE
# 3906 "data/scripts/gym_scripts.pory"
	cleartrainerflag TRAINER_COOLTRAINERF_LOLA
	goto Common_EventScript_ClearGymTrainers_1


EventScript_Gym_Attendant_Call_Text_0:
# 219 "data/scripts/gym_scripts.pory"
	.string "Scott: Hey {PLAYER}, I heard you\n"
	.string "won your first Gym battle! That's\l"
	.string "an incredible start.\p"
	.string "You should head to Lilycove or\n"
	.string "Slateport. From there, you can\l"
	.string "reach the Sevii Islands, which\l"
	.string "also have 8 Gyms.\p"
	.string "Good luck!$"

EventScript_Gym_Attendant_Call_Text_1:
# 220 "data/scripts/gym_scripts.pory"
	.string "Scott: Great job on earning your\n"
	.string "second badge, {PLAYER}! I knew you\l"
	.string "had what it takes.\p"
	.string "By the way, did you know your\n"
	.string "Pokémon can share Egg or Tutor\l"
	.string "moves through the 'Learn Move'\l"
	.string "feature in the Party screen?\p"
	.string "Keep pushing forward!$"

EventScript_Gym_Attendant_Call_Text_2:
# 221 "data/scripts/gym_scripts.pory"
	.string "Scott: Wow, three badges already,\n"
	.string "{PLAYER}! You're moving fast!\p"
	.string "If you give your lead Pokémon an\n"
	.string "Everstone or Eviolite, you'll\l"
	.string "encounter only first stage\l"
	.string "Pokémon in the wild. Cool trick,\l"
	.string "huh?\p"
	.string "Take care!$"

EventScript_Gym_Attendant_Call_Text_3:
# 222 "data/scripts/gym_scripts.pory"
	.string "Scott: Four badges, {PLAYER}!\n"
	.string "That's a quarter of the way\l"
	.string "through the challenge.\p"
	.string "Have you visited the Battle Mart\n"
	.string "in Oldale? They've got Nature\l"
	.string "Mints that might help your\l"
	.string "Pokémon grow stronger.\p"
	.string "Keep up the momentum!$"

EventScript_Gym_Attendant_Call_Text_4:
# 223 "data/scripts/gym_scripts.pory"
	.string "Scott: Five badges, {PLAYER}!\n"
	.string "You're making amazing progress!\p"
	.string "Have you tried Wonder Trading\n"
	.string "yet? It costs 5BP, but you can get\l"
	.string "some incredible Pokémon that way.\p"
	.string "Best of luck on the next one!$"

EventScript_Gym_Attendant_Call_Text_5:
# 224 "data/scripts/gym_scripts.pory"
	.string "Scott: Six badges under your belt,\n"
	.string "{PLAYER}. That's impressive!\p"
	.string "Did you know the blue haired nurse\n"
	.string "in Pokémon Centers now teaches\l"
	.string "Egg Moves? That might be useful\l"
	.string "for your team.\p"
	.string "Keep up the hard work!$"

EventScript_Gym_Attendant_Call_Text_6:
# 225 "data/scripts/gym_scripts.pory"
	.string "Scott: Seven badges, {PLAYER}!\n"
	.string "You're so close to conquering this\l"
	.string "challenge!\p"
	.string "I heard the Lilycove Department\n"
	.string "Store has stocked up on Evolution\l"
	.string "items. It's worth checking out.\p"
	.string "Good luck!$"

EventScript_Gym_Attendant_Call_Text_7:
# 226 "data/scripts/gym_scripts.pory"
	.string "Scott: Eight badges already,\n"
	.string "{PLAYER}? That's incredible!\p"
	.string "If this were a single region\n"
	.string "league, you'd be ready for the\l"
	.string "Elite Four, but there's still 8 more\l"
	.string "to go. I believe in you!$"

EventScript_Gym_Attendant_Call_Text_8:
# 227 "data/scripts/gym_scripts.pory"
	.string "Scott: Nine badges, {PLAYER}!\n"
	.string "You're on a roll.\p"
	.string "The blue haired nurse in Pokémon\n"
	.string "Centers now offers to teach Tutor\l"
	.string "Moves. Maybe give it a look.\p"
	.string "Keep it up!$"

EventScript_Gym_Attendant_Call_Text_9:
# 228 "data/scripts/gym_scripts.pory"
	.string "Scott: Ten badges? Amazing work,\n"
	.string "{PLAYER}!\p"
	.string "The next Gym Leader should give\n"
	.string "you a Mega Ring. With that, your\l"
	.string "team will reach a whole new level.\l"
	.string "Keep going!$"

EventScript_Gym_Attendant_Call_Text_10:
# 229 "data/scripts/gym_scripts.pory"
	.string "Scott: Eleven badges, {PLAYER}.\n"
	.string "You're almost there!\p"
	.string "Now that you have a Mega Ring, you\n"
	.string "can Mega Evolve your Pokémon.\l"
	.string "Just press the Start Button\l"
	.string "during battle while selecting a\l"
	.string "move.\p"
	.string "Also, I've been hearing reports of\n"
	.string "unusually strong Pokémon\l"
	.string "appearing in various areas. Be\l"
	.string "careful if you run into one, but if\l"
	.string "you manage to defeat them, they\l"
	.string "might leave behind something\l"
	.string "special.\p"
	.string "Good luck!$"

EventScript_Gym_Attendant_Call_Text_11:
# 230 "data/scripts/gym_scripts.pory"
	.string "Scott: Twelve badges? You're\n"
	.string "unstoppable, {PLAYER}!\p"
	.string "The blue haired nurse in Pokémon\n"
	.string "Centers can now teach TM Moves to\l"
	.string "your Pokémon. That might help for\l"
	.string "the next challenge.\p"
	.string "You've got this!$"

EventScript_Gym_Attendant_Call_Text_12:
# 231 "data/scripts/gym_scripts.pory"
	.string "Scott: Three more badges to go,\n"
	.string "{PLAYER}. You're in the final\l"
	.string "stretch now!\p"
	.string "I'm rooting for you all the way!$"

EventScript_Gym_Attendant_Call_Text_13:
# 232 "data/scripts/gym_scripts.pory"
	.string "Scott: Fourteen badges just two\n"
	.string "more left, {PLAYER}!\p"
	.string "I know you've got what it takes to\n"
	.string "finish strong!$"

EventScript_Gym_Attendant_Call_Text_14:
# 233 "data/scripts/gym_scripts.pory"
	.string "Scott: Fifteen badges! Only one\n"
	.string "more, {PLAYER}!\p"
	.string "The Wonder Charm should let you\n"
	.string "Wonder Trade for free now, so\l"
	.string "check that out at the Pokémon\l"
	.string "Center.\p"
	.string "I'm waiting to hear the big news!$"

EventScript_Gym_Attendant_Call_Text_15:
# 234 "data/scripts/gym_scripts.pory"
	.string "Scott: {PLAYER}, you did it! All Gym\n"
	.string "badges in Hoenn and Sevii are\l"
	.string "yours!\p"
	.string "Come see me at the Pokémon Center\n"
	.string "in Ever Grande City before\l"
	.string "tackling Victory Road and the\l"
	.string "Pokémon League.\p"
	.string "There's a green haired trainer\n"
	.string "here who seems really strong you\l"
	.string "might want to test your skills\l"
	.string "against them.\p"
	.string "Good luck!$"

RustboroCity_Gym_EventScript_GymGuide_New_Text_0:
# 270 "data/scripts/gym_scripts.pory"
	.string "Guide: Hello {PLAYER}, I see you came to\n"
	.string "this Gym again, do you want me to take\l"
	.string "you to the Leader?$"

RustboroCity_Gym_EventScript_GymGuide_New_Text_1:
# 272 "data/scripts/gym_scripts.pory"
	.string "Let me tell the leader that you are\n"
	.string "here.$"

RustboroCity_Gym_EventScript_GymGuide_New_Text_2:
# 276 "data/scripts/gym_scripts.pory"
	.string "I see, you can also go throught the Gym\n"
	.string "if you want.$"

RustboroCity_Gym_EventScript_Roxanne_New_Text_0:
# 305 "data/scripts/gym_scripts.pory"
	.string "Please take these items with you.$"

RustboroCity_Gym_EventScript_Roxanne_New_Text_1:
# 308 "data/scripts/gym_scripts.pory"
	.string "Roxanne: Come back tomorrow so we can\n"
	.string "battle again.$"

RustboroCity_Gym_EventScript_Roxanne_New_Text_2:
# 315 "data/scripts/gym_scripts.pory"
	.string "Roxanne: My Pokémon are tired for\n"
	.string "today, but the other trainers here need\l"
	.string "training, do you want to try battling\l"
	.string "them again?$"

RustboroCity_Gym_EventScript_Roxanne_New_Text_3:
# 319 "data/scripts/gym_scripts.pory"
	.string "Roxanne: I will tell them to get ready,\n"
	.string "so take care on your way out.$"

RustboroCity_Gym_EventScript_Roxanne_New_Text_4:
# 336 "data/scripts/gym_scripts.pory"
	.string "{PLAYER} received the Stone Badge from\n"
	.string "Roxanne.$"

RustboroCity_Gym_EventScript_Roxanne_New_Text_5:
# 339 "data/scripts/gym_scripts.pory"
	.string "Please take these items with you too.$"

RustboroCity_Gym_EventScript_Roxanne_New_Text_6:
# 349 "data/scripts/gym_scripts.pory"
	.string "That Technical Machine contains the\n"
	.string "move Rock Tomb.\p"
	.string "It not only inflicts damage by dropping\n"
	.string "rocks, it also lowers the target Speed.\p"
	.string "If you use a TM, it instantly teaches\n"
	.string "the move to a Pokémon.\p"
	.string "A TM can be used indefinitely, so use it\n"
	.string "without thinking it twice.$"

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_Text_0:
# 413 "data/scripts/gym_scripts.pory"
	.string "Roxanne: This move raises the speed of\n"
	.string "Rock-type Pokémon by 2 stages, its\l"
	.string "really useful.$"

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_Text_1:
# 421 "data/scripts/gym_scripts.pory"
	.string "Roxanne: This move does damage every\n"
	.string "time an opposing Pokémon enters to the\l"
	.string "battle, try it at the start of the\l"
	.string "battle.$"

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_Text_2:
# 429 "data/scripts/gym_scripts.pory"
	.string "Roxanne: This is a Rock-type damage\n"
	.string "move made specially for Rock-type\l"
	.string "Pokémon with high Special Attack.$"

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_Text_3:
# 437 "data/scripts/gym_scripts.pory"
	.string "Roxanne: This is a Rock-type damage\n"
	.string "move with a high base attack, but\l"
	.string "misses a lot too so be careful when\l"
	.string "using it.$"

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_Text_4:
# 443 "data/scripts/gym_scripts.pory"
	.string "Roxanne: Take this as an special gift\n"
	.string "from me, it's an Aggronite.$"

RustboroCity_Gym_EventScript_Roxanne_Give_Gifts_Text_5:
# 445 "data/scripts/gym_scripts.pory"
	.string "Make an Aggron hold it to unleash its\n"
	.string "true potential.$"

RustboroCity_Gym_EventScript_Gym_Aaron_Text_0:
# 473 "data/scripts/gym_scripts.pory"
	.string "Aron: ron!$"

RustboroCity_Gym_EventScript_Gym_Aaron_Text_1:
# 474 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems like it wants a\n"
	.string "rematch with You, its skin look's really\l"
	.string "shiny.$"

RustboroCity_Gym_EventScript_Gym_Aaron_Text_2:
# 479 "data/scripts/gym_scripts.pory"
	.string "Aron: ron...$"

RustboroCity_Gym_EventScript_Gym_Aaron_Text_3:
# 480 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems tired after today's\n"
	.string "battle, its better to let it rest.$"

RustboroCity_Gym_EventScript_Gym_Aaron_Text_4:
# 484 "data/scripts/gym_scripts.pory"
	.string "Aron: ron?$"

RustboroCity_Gym_EventScript_Gym_Aaron_Text_5:
# 485 "data/scripts/gym_scripts.pory"
	.string "The Pokémon is currently eating a little\n"
	.string "chunk of metal.$"

RustboroCity_Gym_EventScript_Gym_Aaron_Text_6:
# 491 "data/scripts/gym_scripts.pory"
	.string "Lairon: ron!$"

RustboroCity_Gym_EventScript_Gym_Aaron_Text_7:
# 496 "data/scripts/gym_scripts.pory"
	.string "Lairon: ron...$"

RustboroCity_Gym_EventScript_Gym_Aaron_Text_8:
# 501 "data/scripts/gym_scripts.pory"
	.string "Lairon: ron?$"

RustboroCity_Gym_EventScript_Gym_Aaron_Text_9:
# 502 "data/scripts/gym_scripts.pory"
	.string "The Pokémon is currently eating a chunk\n"
	.string "of metal.$"

RustboroCity_Gym_EventScript_Gym_Aaron_Text_10:
# 508 "data/scripts/gym_scripts.pory"
	.string "Aggron: ron!$"

RustboroCity_Gym_EventScript_Gym_Aaron_Text_11:
# 509 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems like it wants a\n"
	.string "rematch with You, its skin look's really\l"
	.string "tought.$"

RustboroCity_Gym_EventScript_Gym_Aaron_Text_12:
# 514 "data/scripts/gym_scripts.pory"
	.string "Aggron: ron...$"

RustboroCity_Gym_EventScript_Gym_Aaron_Text_13:
# 521 "data/scripts/gym_scripts.pory"
	.string "The Pokémon is currently looking at a\n"
	.string "shiny rock on its arm with\l"
	.string "determination.$"

RustboroCity_Gym_EventScript_Gym_Aaron_Text_14:
# 526 "data/scripts/gym_scripts.pory"
	.string "Aggron: ron?$"

RustboroCity_Gym_EventScript_Gym_Aaron_Text_15:
# 527 "data/scripts/gym_scripts.pory"
	.string "The Pokémon is currently eating what it\n"
	.string "looks to be a big rock.$"

DewfordTown_Gym_EventScript_Brawly_New_Text_0:
# 608 "data/scripts/gym_scripts.pory"
	.string "Brawly: Come back tomorrow so we can\n"
	.string "battle again.$"

DewfordTown_Gym_EventScript_Brawly_New_Text_1:
# 615 "data/scripts/gym_scripts.pory"
	.string "Brawly: My Pokémon are tired for today,\n"
	.string "but the other trainers here need\l"
	.string "training, do you want to try battling\l"
	.string "them again?$"

DewfordTown_Gym_EventScript_Brawly_New_Text_2:
# 619 "data/scripts/gym_scripts.pory"
	.string "Brawly: I will tell them to get ready, so\n"
	.string "take care on your way out.$"

DewfordTown_Gym_EventScript_Brawly_New_Text_3:
# 635 "data/scripts/gym_scripts.pory"
	.string "{PLAYER} received the Knuckle Badge\n"
	.string "from Brawly.$"

DewfordTown_Gym_EventScript_Brawly_New_Text_4:
# 647 "data/scripts/gym_scripts.pory"
	.string "That technical machine contains the\n"
	.string "move Bulk Up.\p"
	.string "It's a move that raises both Attack and\n"
	.string "Defense stats for the User.$"

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_Text_0:
# 709 "data/scripts/gym_scripts.pory"
	.string "Brawly: This move not only inflicts\n"
	.string "damage, it also lowers the target Speed\l"
	.string "stat by one stage.$"

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_Text_1:
# 717 "data/scripts/gym_scripts.pory"
	.string "Brawly: This move confuses the target\n"
	.string "but it also raises its attack stat, use\l"
	.string "it with caution.$"

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_Text_2:
# 725 "data/scripts/gym_scripts.pory"
	.string "Brawly: This is a Fighting-type damage\n"
	.string "move with a really high base attack, but\l"
	.string "misses a lot too so be careful when\l"
	.string "using it.$"

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_Text_3:
# 733 "data/scripts/gym_scripts.pory"
	.string "Brawly: This is a Fighting-type damage\n"
	.string "move made specially for Fighting-type\l"
	.string "Pokémon with high Special Attack.$"

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_Text_4:
# 739 "data/scripts/gym_scripts.pory"
	.string "Brawly: Take this as an special gift\n"
	.string "from me, it's a Heracronite.$"

DewfordTown_Gym_EventScript_Brawly_Give_Gifts_Text_5:
# 741 "data/scripts/gym_scripts.pory"
	.string "Make a Heracross hold it to unleash its\n"
	.string "real potential.$"

DewfordTown_Gym_EventScript_Gym_Makuhita_Text_0:
# 769 "data/scripts/gym_scripts.pory"
	.string "Makuhita: hita!$"

DewfordTown_Gym_EventScript_Gym_Makuhita_Text_1:
# 770 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems like it wants a\n"
	.string "rematch with You, it has a really\l"
	.string "professional fighting stance.$"

DewfordTown_Gym_EventScript_Gym_Makuhita_Text_2:
# 775 "data/scripts/gym_scripts.pory"
	.string "Makuhita: hita...$"

DewfordTown_Gym_EventScript_Gym_Makuhita_Text_3:
# 776 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems tired after today's\n"
	.string "battle, but even then it has a lot of\l"
	.string "energy left.$"

DewfordTown_Gym_EventScript_Gym_Makuhita_Text_4:
# 780 "data/scripts/gym_scripts.pory"
	.string "Makuhita: hita?$"

DewfordTown_Gym_EventScript_Gym_Makuhita_Text_5:
# 781 "data/scripts/gym_scripts.pory"
	.string "The Pokémon is looking at a little\n"
	.string "surfboard on its hand.$"

DewfordTown_Gym_EventScript_Gym_Makuhita_Text_6:
# 787 "data/scripts/gym_scripts.pory"
	.string "Hariyama: yama!$"

DewfordTown_Gym_EventScript_Gym_Makuhita_Text_7:
# 788 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems like it wants a\n"
	.string "rematch, it is stomping the ground with\l"
	.string "determination.$"

DewfordTown_Gym_EventScript_Gym_Makuhita_Text_8:
# 792 "data/scripts/gym_scripts.pory"
	.string "Hariyama: yama...$"

DewfordTown_Gym_EventScript_Gym_Makuhita_Text_9:
# 793 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems tired after today's\n"
	.string "battle, but its thanking you for the\l"
	.string "battle very politely.$"

DewfordTown_Gym_EventScript_Gym_Makuhita_Text_10:
# 797 "data/scripts/gym_scripts.pory"
	.string "Hariyama: yama?$"

DewfordTown_Gym_EventScript_Gym_Makuhita_Text_11:
# 798 "data/scripts/gym_scripts.pory"
	.string "The Pokémon is currently looking at\n"
	.string "you, it may be studying your movements.$"

MauvilleCity_Gym_EventScript_Wattson_New_Text_0:
# 845 "data/scripts/gym_scripts.pory"
	.string "Wattson: Come back tomorrow so we can\n"
	.string "battle again.$"

MauvilleCity_Gym_EventScript_Wattson_New_Text_1:
# 852 "data/scripts/gym_scripts.pory"
	.string "Wattson: My Pokémon are tired for\n"
	.string "today, but the other trainers here need\l"
	.string "training, do you want to try battling\l"
	.string "them again?$"

MauvilleCity_Gym_EventScript_Wattson_New_Text_2:
# 856 "data/scripts/gym_scripts.pory"
	.string "Wattson: I will tell them to get ready,\n"
	.string "so take care on your way out.$"

MauvilleCity_Gym_EventScript_Wattson_New_Text_3:
# 872 "data/scripts/gym_scripts.pory"
	.string "{PLAYER} received the Dynamo Badge\n"
	.string "from Wattson.$"

MauvilleCity_Gym_EventScript_Wattson_New_Text_4:
# 884 "data/scripts/gym_scripts.pory"
	.string "That technical machine contains the\n"
	.string "move Thunder Wave.\p"
	.string "This move paralyzes the target so you\n"
	.string "can attack before them, its really\l"
	.string "useful.$"

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_Text_0:
# 946 "data/scripts/gym_scripts.pory"
	.string "Wattson: This move inflicts damage and\n"
	.string "always lands, use it if you had your\l"
	.string "accuracy lowered.$"

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_Text_1:
# 954 "data/scripts/gym_scripts.pory"
	.string "Wattson: This move inflicts damage and\n"
	.string "always rises the user Special Attack so\l"
	.string "it becomes stronger on each hit.$"

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_Text_2:
# 962 "data/scripts/gym_scripts.pory"
	.string "Wattson: This move inflicts damage and\n"
	.string "lets you switch your Pokémon on the\l"
	.string "same turn, use it to switch if you are\l"
	.string "faster than your enemy.$"

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_Text_3:
# 970 "data/scripts/gym_scripts.pory"
	.string "Wattson: This is an Electric-type\n"
	.string "damage move made specially for\l"
	.string "Electric-type Pokémon with high\l"
	.string "Physical Attack, it also inflicts recoil\l"
	.string "damage to the user so use it wisely.$"

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_Text_4:
# 976 "data/scripts/gym_scripts.pory"
	.string "Wattson: Take this as an special gift\n"
	.string "from me, it's a Manectite.$"

MauvilleCity_Gym_EventScript_Wattson_Give_Gifts_Text_5:
# 978 "data/scripts/gym_scripts.pory"
	.string "Make a Manectric hold it to unleash its\n"
	.string "real potential.$"

MauvilleCity_Gym_EventScript_Gym_Electrike_Text_0:
# 1031 "data/scripts/gym_scripts.pory"
	.string "Electrike: trike!$"

MauvilleCity_Gym_EventScript_Gym_Electrike_Text_1:
# 1032 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems like it wants a\n"
	.string "rematch with You, its fur looks like it\l"
	.string "has a lot of electricity.$"

MauvilleCity_Gym_EventScript_Gym_Electrike_Text_2:
# 1037 "data/scripts/gym_scripts.pory"
	.string "Electrike: trike...$"

MauvilleCity_Gym_EventScript_Gym_Electrike_Text_3:
# 1038 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems tired after today's\n"
	.string "battle, it let out a loud yawn.$"

MauvilleCity_Gym_EventScript_Gym_Electrike_Text_4:
# 1042 "data/scripts/gym_scripts.pory"
	.string "Electrike: trike?$"

MauvilleCity_Gym_EventScript_Gym_Electrike_Text_5:
# 1043 "data/scripts/gym_scripts.pory"
	.string "The Pokémon is chewing on a little toy.$"

MauvilleCity_Gym_EventScript_Gym_Electrike_Text_6:
# 1049 "data/scripts/gym_scripts.pory"
	.string "Manectric: tric!$"

MauvilleCity_Gym_EventScript_Gym_Electrike_Text_7:
# 1050 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems like it wants a\n"
	.string "rematch, it may even create\l"
	.string "thunderclouds.$"

MauvilleCity_Gym_EventScript_Gym_Electrike_Text_8:
# 1054 "data/scripts/gym_scripts.pory"
	.string "Manectric: tric...$"

MauvilleCity_Gym_EventScript_Gym_Electrike_Text_9:
# 1055 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems tired after today's\n"
	.string "battle, but it is still alert.$"

MauvilleCity_Gym_EventScript_Gym_Electrike_Text_10:
# 1060 "data/scripts/gym_scripts.pory"
	.string "Manectric: ron!$"

MauvilleCity_Gym_EventScript_Gym_Electrike_Text_11:
# 1061 "data/scripts/gym_scripts.pory"
	.string "The Pokémon is proudly wearing a collar\n"
	.string "with an stone attatched to it.$"

MauvilleCity_Gym_EventScript_Gym_Electrike_Text_12:
# 1065 "data/scripts/gym_scripts.pory"
	.string "Manectric: tric?$"

MauvilleCity_Gym_EventScript_Gym_Electrike_Text_13:
# 1066 "data/scripts/gym_scripts.pory"
	.string "The Pokémon is currently eating\n"
	.string "something.$"

LavaridgeTown_Gym_1F_EventScript_Flannery_New_Text_0:
# 1131 "data/scripts/gym_scripts.pory"
	.string "Flannery: Come back tomorrow so we can\n"
	.string "battle again.$"

LavaridgeTown_Gym_1F_EventScript_Flannery_New_Text_1:
# 1138 "data/scripts/gym_scripts.pory"
	.string "Flannery: My Pokémon are tired for\n"
	.string "today, but the other trainers here need\l"
	.string "training, do you want to try battling\l"
	.string "them again?$"

LavaridgeTown_Gym_1F_EventScript_Flannery_New_Text_2:
# 1142 "data/scripts/gym_scripts.pory"
	.string "Flannery: I will tell them to get ready,\n"
	.string "so take care on your way out.$"

LavaridgeTown_Gym_1F_EventScript_Flannery_New_Text_3:
# 1158 "data/scripts/gym_scripts.pory"
	.string "{PLAYER} received the Heat Badge from\n"
	.string "Flannery.$"

LavaridgeTown_Gym_1F_EventScript_Flannery_New_Text_4:
# 1170 "data/scripts/gym_scripts.pory"
	.string "That technical machine contains the\n"
	.string "move Will-o-Wisp.\p"
	.string "This move burns the target damaging\n"
	.string "the Pokémon every turn while also\l"
	.string "lowering its Physical Attack.$"

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_Text_0:
# 1232 "data/scripts/gym_scripts.pory"
	.string "Flannery: This move inflicts damage and\n"
	.string "always lowers the enemy Special Attack.$"

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_Text_1:
# 1240 "data/scripts/gym_scripts.pory"
	.string "Flannery: This move inflicts damage\n"
	.string "depending on the user's weight, use it\l"
	.string "with Pokémon like my Torkoal.$"

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_Text_2:
# 1248 "data/scripts/gym_scripts.pory"
	.string "Flannery: This is an Fire-type damage\n"
	.string "move made specially for Fire-type\l"
	.string "Pokémon with high Physical Attack.$"

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_Text_3:
# 1256 "data/scripts/gym_scripts.pory"
	.string "Flannery: This is one of the strongest\n"
	.string "Fire-type moves but it also lowers the\l"
	.string "user Special Attack after each use, use\l"
	.string "it only while you are in a pinch or with a\l"
	.string "Pokémon holding a White Herb.$"

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_Text_4:
# 1262 "data/scripts/gym_scripts.pory"
	.string "Flannery: Take this as an special gift\n"
	.string "from me, it's a Houndoomite.$"

LavaridgeTown_Gym_1F_EventScript_Flannery_Give_Gifts_Text_5:
# 1264 "data/scripts/gym_scripts.pory"
	.string "Make a Houndoom hold it to unleash its\n"
	.string "real potential.$"

LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_Text_0:
# 1315 "data/scripts/gym_scripts.pory"
	.string "Torkoal: koal!$"

LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_Text_1:
# 1316 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems like it wants a\n"
	.string "rematch with You, the smoke on its back\l"
	.string "its really hot.$"

LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_Text_2:
# 1320 "data/scripts/gym_scripts.pory"
	.string "Torkoal: koal...$"

LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_Text_3:
# 1321 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems tired after today's\n"
	.string "battle, its better to leave it rest$"

LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_Text_4:
# 1325 "data/scripts/gym_scripts.pory"
	.string "Torkoal: koal?$"

LavaridgeTown_Gym_1F_EventScript_Gym_Torkoal_Text_5:
# 1326 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems curious about how\n"
	.string "strong you are.$"

PetalburgCity_Gym_EventScript_Norman_New_Text_0:
# 1352 "data/scripts/gym_scripts.pory"
	.string "Dad: {PLAYER}, please come back\n"
	.string "tomorrow so you can battle with your\l"
	.string "dad again.$"

PetalburgCity_Gym_EventScript_Norman_New_Text_1:
# 1359 "data/scripts/gym_scripts.pory"
	.string "Dad: {PLAYER}, I'm tired for today, but\n"
	.string "the trainers here need training, could\l"
	.string "you shape them a little?$"

PetalburgCity_Gym_EventScript_Norman_New_Text_2:
# 1363 "data/scripts/gym_scripts.pory"
	.string "Dad: I will tell them to get ready, so\n"
	.string "take care on your way out.$"

PetalburgCity_Gym_EventScript_Norman_New_Text_3:
# 1379 "data/scripts/gym_scripts.pory"
	.string "{PLAYER} received the Balance Badge\n"
	.string "from Norman.$"

PetalburgCity_Gym_EventScript_Norman_New_Text_4:
# 1391 "data/scripts/gym_scripts.pory"
	.string "That technical machine contains the\n"
	.string "move False swipe.\p"
	.string "This move inflicts damage but never\n"
	.string "defeats the target, its a perfect for\l"
	.string "catching wild Pokémon.$"

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_Text_0:
# 1453 "data/scripts/gym_scripts.pory"
	.string "Dad: This move lowers the target\n"
	.string "Special Attack by 1 stage.$"

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_Text_1:
# 1461 "data/scripts/gym_scripts.pory"
	.string "Dad: This move changes depending on\n"
	.string "where you use it, its great for Pokémon\l"
	.string "without a lot of variety.$"

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_Text_2:
# 1469 "data/scripts/gym_scripts.pory"
	.string "Dad: This move inflicts damage and\n"
	.string "becomes stronger if the user has.$"

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_Text_3:
# 1477 "data/scripts/gym_scripts.pory"
	.string "Dad: This is the strongest physical\n"
	.string "Normal-type move, it does not let you\l"
	.string "attack on the next turn, so use it\l"
	.string "wisely.$"

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_Text_4:
# 1483 "data/scripts/gym_scripts.pory"
	.string "Dad: Take this as an special gift from\n"
	.string "me, it's a Kangaskhanite.$"

PetalburgCity_Gym_EventScript_Norman_Give_Gifts_Text_5:
# 1485 "data/scripts/gym_scripts.pory"
	.string "Make a Kangaskhan hold it to unleash\n"
	.string "its real potential.$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_0:
# 1539 "data/scripts/gym_scripts.pory"
	.string "Slakoth: koth!$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_1:
# 1540 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems like it has some\n"
	.string "energy and wants to battle you.$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_2:
# 1545 "data/scripts/gym_scripts.pory"
	.string "Slakoth: koth...$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_3:
# 1546 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems tired after today's\n"
	.string "battle, it let out a really loud yawn.$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_4:
# 1550 "data/scripts/gym_scripts.pory"
	.string "Slakoth: koth?$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_5:
# 1551 "data/scripts/gym_scripts.pory"
	.string "The Pokémon is currently loafing around\n"
	.string "while looking at you.$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_6:
# 1557 "data/scripts/gym_scripts.pory"
	.string "Vigoroth: roth!$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_7:
# 1558 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems like it wants a\n"
	.string "rematch with You, it looks determined\l"
	.string "to beat you.$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_8:
# 1563 "data/scripts/gym_scripts.pory"
	.string "Vigoroth: roth...$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_9:
# 1568 "data/scripts/gym_scripts.pory"
	.string "Vigoroth: roth!!$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_10:
# 1569 "data/scripts/gym_scripts.pory"
	.string "The Pokémon is warmly welcoming you.$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_11:
# 1575 "data/scripts/gym_scripts.pory"
	.string "Slaking: king!$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_12:
# 1576 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems like it wants a\n"
	.string "rematch, it looks proud on how much you\l"
	.string "have grown.$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_13:
# 1580 "data/scripts/gym_scripts.pory"
	.string "Slaking: king...$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_14:
# 1581 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems tired after today's\n"
	.string "battle, but it still looks happy that\l"
	.string "you are so strong.$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_15:
# 1585 "data/scripts/gym_scripts.pory"
	.string "Slaking: king!!$"

PetalburgCity_Gym_EventScript_Gym_Slakoth_Text_16:
# 1586 "data/scripts/gym_scripts.pory"
	.string "The Pokémon looks surprised on how muh\n"
	.string "you have grown.$"

FortreeCity_Gym_EventScript_Winona_New_Text_0:
# 1634 "data/scripts/gym_scripts.pory"
	.string "Winona: Come back tomorrow so we can\n"
	.string "battle again.$"

FortreeCity_Gym_EventScript_Winona_New_Text_1:
# 1641 "data/scripts/gym_scripts.pory"
	.string "Winona: My Pokémon are tired for today,\n"
	.string "but the other trainers here need\l"
	.string "training, do you want to try battling\l"
	.string "them again?$"

FortreeCity_Gym_EventScript_Winona_New_Text_2:
# 1645 "data/scripts/gym_scripts.pory"
	.string "Winona: I will tell them to get ready, so\n"
	.string "take care on your way out.$"

FortreeCity_Gym_EventScript_Winona_New_Text_3:
# 1661 "data/scripts/gym_scripts.pory"
	.string "{PLAYER} received the Feather Badge\n"
	.string "from Winona.$"

FortreeCity_Gym_EventScript_Winona_New_Text_4:
# 1673 "data/scripts/gym_scripts.pory"
	.string "That technical machine contains the\n"
	.string "move Roost.\p"
	.string "It's a move that cures your Flying-type\n"
	.string "Pokémon.$"

FortreeCity_Gym_EventScript_Winona_Give_Gifts_Text_0:
# 1735 "data/scripts/gym_scripts.pory"
	.string "Winona: This move inflicts damage and\n"
	.string "never fails, use it when you are low on\l"
	.string "accuracy.$"

FortreeCity_Gym_EventScript_Winona_Give_Gifts_Text_1:
# 1743 "data/scripts/gym_scripts.pory"
	.string "Winona: This move inflicts double the\n"
	.string "damage if its used by a Pokémon without\l"
	.string "a held item.$"

FortreeCity_Gym_EventScript_Winona_Give_Gifts_Text_2:
# 1751 "data/scripts/gym_scripts.pory"
	.string "Winona: This is a two turns Flying-type\n"
	.string "move, its really powerful and lets you\l"
	.string "stay out of the enemy range for 1 turn.$"

FortreeCity_Gym_EventScript_Winona_Give_Gifts_Text_3:
# 1759 "data/scripts/gym_scripts.pory"
	.string "Winona: This is one of the best\n"
	.string "Flying-type moves, it does a lot of\l"
	.string "damage but also hurts the user.$"

FortreeCity_Gym_EventScript_Winona_Give_Gifts_Text_4:
# 1765 "data/scripts/gym_scripts.pory"
	.string "Winona: Take this as an special gift\n"
	.string "from me, it's a Altaria.$"

FortreeCity_Gym_EventScript_Winona_Give_Gifts_Text_5:
# 1767 "data/scripts/gym_scripts.pory"
	.string "Make a Altaria hold it to unleash its\n"
	.string "real potential.$"

FortreeCity_Gym_EventScript_Gym_Taillow_Text_0:
# 1820 "data/scripts/gym_scripts.pory"
	.string "Taillow: low!$"

FortreeCity_Gym_EventScript_Gym_Taillow_Text_1:
# 1821 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems like it wants a\n"
	.string "rematch with You, it is flying really\l"
	.string "fast.$"

FortreeCity_Gym_EventScript_Gym_Taillow_Text_2:
# 1826 "data/scripts/gym_scripts.pory"
	.string "Taillow: low...$"

FortreeCity_Gym_EventScript_Gym_Taillow_Text_3:
# 1827 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems tired after today's\n"
	.string "battle, it is currently eating a\l"
	.string "sunflower seed.$"

FortreeCity_Gym_EventScript_Gym_Taillow_Text_4:
# 1831 "data/scripts/gym_scripts.pory"
	.string "Taillow: low?$"

FortreeCity_Gym_EventScript_Gym_Taillow_Text_5:
# 1832 "data/scripts/gym_scripts.pory"
	.string "The Pokémon is looking confused on how\n"
	.string "you finished the puzzle.$"

FortreeCity_Gym_EventScript_Gym_Taillow_Text_6:
# 1838 "data/scripts/gym_scripts.pory"
	.string "Swellow: low!$"

FortreeCity_Gym_EventScript_Gym_Taillow_Text_7:
# 1839 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems like it wants a\n"
	.string "rematch, it is flying really fast.$"

FortreeCity_Gym_EventScript_Gym_Taillow_Text_8:
# 1843 "data/scripts/gym_scripts.pory"
	.string "Swellow: low...$"

FortreeCity_Gym_EventScript_Gym_Taillow_Text_9:
# 1844 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems tired after today's\n"
	.string "battle, it may want to rest a little\l"
	.string "more.$"

FortreeCity_Gym_EventScript_Gym_Taillow_Text_10:
# 1848 "data/scripts/gym_scripts.pory"
	.string "Swellow: low?$"

FortreeCity_Gym_EventScript_Gym_Taillow_Text_11:
# 1849 "data/scripts/gym_scripts.pory"
	.string "The Pokémon is currently looking at you\n"
	.string "while flying.$"

MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_0:
# 1892 "data/scripts/gym_scripts.pory"
	.string "Tate: Please take$"

MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_1:
# 1893 "data/scripts/gym_scripts.pory"
	.string "Liza: these items with you.$"

MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_2:
# 1896 "data/scripts/gym_scripts.pory"
	.string "Tate: Come back tomorrow$"

MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_3:
# 1897 "data/scripts/gym_scripts.pory"
	.string "Liza: so we can battle again.$"

MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_4:
# 1904 "data/scripts/gym_scripts.pory"
	.string "Tate: Our Pokémon are tired for today,\n"
	.string "do you want to try battling them again?$"

MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_5:
# 1905 "data/scripts/gym_scripts.pory"
	.string "Liza: but the other trainers here need\n"
	.string "training$"

MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_6:
# 1906 "data/scripts/gym_scripts.pory"
	.string "Tate: Do you want to try battling them\n"
	.string "again?$"

MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_7:
# 1910 "data/scripts/gym_scripts.pory"
	.string "Tate: I will tell them to get ready.$"

MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_8:
# 1911 "data/scripts/gym_scripts.pory"
	.string "Liza: so take care on your way out.$"

MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_9:
# 1928 "data/scripts/gym_scripts.pory"
	.string "{PLAYER} received the Mind Badge from\n"
	.string "Tate and Liza.$"

MossdeepCity_Gym_EventScript_TateAndLiza_New_Text_10:
# 1940 "data/scripts/gym_scripts.pory"
	.string "Tate: That technical machine contains\n"
	.string "the move Calm Mind.\p"
	.string "Liza: This move raises your Pokémon\n"
	.string "Special Attack and Special Defense at\l"
	.string "the same time.$"

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_Text_0:
# 2002 "data/scripts/gym_scripts.pory"
	.string "Tate: This move can only hit.$"

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_Text_1:
# 2003 "data/scripts/gym_scripts.pory"
	.string "Liza: if the Target is asleep.$"

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_Text_2:
# 2011 "data/scripts/gym_scripts.pory"
	.string "Tate: This move reverses the turn\n"
	.string "order.$"

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_Text_3:
# 2012 "data/scripts/gym_scripts.pory"
	.string "Liza: but only for 5 turns.$"

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_Text_4:
# 2020 "data/scripts/gym_scripts.pory"
	.string "Tate: This move inflicts damage.$"

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_Text_5:
# 2021 "data/scripts/gym_scripts.pory"
	.string "Liza: but its based on the target\n"
	.string "physical Defense.$"

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_Text_6:
# 2035 "data/scripts/gym_scripts.pory"
	.string "Tate: Take this as an special gift from\n"
	.string "us, it's a pair of Mega Stones.$"

MossdeepCity_Gym_EventScript_TateAndLiza_Give_Gifts_Text_7:
# 2038 "data/scripts/gym_scripts.pory"
	.string "Liza: Make a Gardevoir or a Gallade hold\n"
	.string "it to unleash their real potential.$"

MossdeepCity_Gym_EventScript_GymGuide_New_Text_0:
# 2064 "data/scripts/gym_scripts.pory"
	.string "Guide: Hello {PLAYER}, I see you came to\n"
	.string "this Gym again, do you want me to take\l"
	.string "you to the Leaders?$"

MossdeepCity_Gym_EventScript_GymGuide_New_Text_1:
# 2066 "data/scripts/gym_scripts.pory"
	.string "Let me tell them that you are here.$"

MossdeepCity_Gym_EventScript_Gym_Solrock_Text_0:
# 2089 "data/scripts/gym_scripts.pory"
	.string "Solrock: rock!$"

MossdeepCity_Gym_EventScript_Gym_Solrock_Text_1:
# 2090 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems like it wants a\n"
	.string "rematch with You, it looks really bright.$"

MossdeepCity_Gym_EventScript_Gym_Solrock_Text_2:
# 2094 "data/scripts/gym_scripts.pory"
	.string "Solrock: rock...$"

MossdeepCity_Gym_EventScript_Gym_Solrock_Text_3:
# 2099 "data/scripts/gym_scripts.pory"
	.string "Solrock: rock?$"

MossdeepCity_Gym_EventScript_Gym_Lunatone_Text_0:
# 2112 "data/scripts/gym_scripts.pory"
	.string "Lunatone: tone!$"

MossdeepCity_Gym_EventScript_Gym_Lunatone_Text_1:
# 2117 "data/scripts/gym_scripts.pory"
	.string "Lunatone: tone...$"

MossdeepCity_Gym_EventScript_Gym_Lunatone_Text_2:
# 2122 "data/scripts/gym_scripts.pory"
	.string "Lunatone: tone?$"

SootopolisCity_Gym_1F_EventScript_Juan_New_Text_0:
# 2148 "data/scripts/gym_scripts.pory"
	.string "Juan: Come back tomorrow so we can\n"
	.string "battle again.$"

SootopolisCity_Gym_1F_EventScript_Juan_New_Text_1:
# 2155 "data/scripts/gym_scripts.pory"
	.string "Juan: My Pokémon are tired for today,\n"
	.string "but the other trainers here need\l"
	.string "training, do you want to try battling\l"
	.string "them again?$"

SootopolisCity_Gym_1F_EventScript_Juan_New_Text_2:
# 2159 "data/scripts/gym_scripts.pory"
	.string "Juan: I will tell them to get ready, so\n"
	.string "take care on your way out.$"

SootopolisCity_Gym_1F_EventScript_Juan_New_Text_3:
# 2188 "data/scripts/gym_scripts.pory"
	.string "That Technical Machine contains the\n"
	.string "move Water Pulse.\p"
	.string "This move inflicts damage and has a\n"
	.string "chance of confusing the target.$"

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_Text_0:
# 2249 "data/scripts/gym_scripts.pory"
	.string "Juan: This move inflicts damage and has\n"
	.string "a high chance of burning the target.$"

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_Text_1:
# 2257 "data/scripts/gym_scripts.pory"
	.string "Juan: This move does damages\n"
	.string "everything on the field even your\l"
	.string "allies.$"

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_Text_2:
# 2265 "data/scripts/gym_scripts.pory"
	.string "Juan: This is a Physical oriented\n"
	.string "Water-type move, it can flinch the\l"
	.string "target.$"

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_Text_3:
# 2273 "data/scripts/gym_scripts.pory"
	.string "Juan: This is one of the best physical\n"
	.string "Water-type moves it has a chance of\l"
	.string "lowering the target defense.$"

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_Text_4:
# 2279 "data/scripts/gym_scripts.pory"
	.string "Juan: Take this as an special gift from\n"
	.string "me, it's an Gyarados.$"

SootopolisCity_Gym_1F_EventScript_Juan_Give_Gifts_Text_5:
# 2281 "data/scripts/gym_scripts.pory"
	.string "Make an Gyarados hold it to unleash its\n"
	.string "real potential.$"

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_0:
# 2333 "data/scripts/gym_scripts.pory"
	.string "Horsea: sea!$"

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_1:
# 2334 "data/scripts/gym_scripts.pory"
	.string "The Pokémon seems like it wants a\n"
	.string "rematch with You, it looks really\l"
	.string "excited.$"

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_2:
# 2339 "data/scripts/gym_scripts.pory"
	.string "Horsea: sea...$"

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_3:
# 2344 "data/scripts/gym_scripts.pory"
	.string "Horsea: sea?$"

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_4:
# 2345 "data/scripts/gym_scripts.pory"
	.string "The Pokémon is currently looking\n"
	.string "shooting ink from its mouth.$"

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_5:
# 2351 "data/scripts/gym_scripts.pory"
	.string "Seadra: dra!$"

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_6:
# 2356 "data/scripts/gym_scripts.pory"
	.string "Seadra: dra...$"

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_7:
# 2361 "data/scripts/gym_scripts.pory"
	.string "Seadra: dra?$"

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_8:
# 2362 "data/scripts/gym_scripts.pory"
	.string "The Pokémon is currently looking at\n"
	.string "some ring targets.$"

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_9:
# 2368 "data/scripts/gym_scripts.pory"
	.string "Seaking: ron!$"

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_10:
# 2374 "data/scripts/gym_scripts.pory"
	.string "Seaking: king...$"

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_11:
# 2380 "data/scripts/gym_scripts.pory"
	.string "Seaking: king?$"

SootopolisCity_Gym_1F_EventScript_Gym_Horsea_Text_12:
# 2381 "data/scripts/gym_scripts.pory"
	.string "The Pokémon is currently shooting some\n"
	.string "ring targets.$"

Common_Eventscript_Gym_Leader_Falkner_Text_0:
# 2419 "data/scripts/gym_scripts.pory"
	.string "Falkner: Hi! I've been waiting for you!\n"
	.string "It's a pleasure to be able to battle you\l"
	.string "again.$"

Common_Eventscript_Gym_Leader_Falkner_Text_1:
# 2424 "data/scripts/gym_scripts.pory"
	.string "Falkner: Mmm... It's still a long way to\n"
	.string "become the best Trainer, but I won't\l"
	.string "give up!$"

Common_Eventscript_Gym_Leader_Falkner_Text_2:
# 2428 "data/scripts/gym_scripts.pory"
	.string "Falkner: Come back tomorrow so we can\n"
	.string "battle again.$"

Common_Eventscript_Gym_Leader_Falkner_Text_3:
# 2434 "data/scripts/gym_scripts.pory"
	.string "Falkner: My Pokémon are tired for\n"
	.string "today, but the other trainers here need\l"
	.string "training, do you want to try battling\l"
	.string "them again?$"

Common_Eventscript_Gym_Leader_Falkner_Text_4:
# 2438 "data/scripts/gym_scripts.pory"
	.string "Falkner: I will tell them to get ready,\n"
	.string "so take care on your way out.$"

Common_Eventscript_Gym_Leader_Falkner_Text_5:
# 2450 "data/scripts/gym_scripts.pory"
	.string "I'm Falkner, this Island Pokémon Gym\n"
	.string "Leader! People say you can clip\l"
	.string "Flying-type Pokémon's wings with a jolt\l"
	.string "of electricity... I won't allow such\l"
	.string "insults to bird Pokémon! I'll show you\l"
	.string "the real power of the magnificent bird\l"
	.string "Pokémon!$"

Common_Eventscript_Gym_Leader_Falkner_Text_6:
# 2454 "data/scripts/gym_scripts.pory"
	.string "For pity's sake! My dad's cherished bird\n"
	.string "Pokémon... But a defeat is a defeat. All\l"
	.string "right. Take this official Pokémon\l"
	.string "League Badge. This one is the Zephyr\l"
	.string "Badge.$"

Common_Eventscript_Gym_Leader_Falkner_Text_7:
# 2455 "data/scripts/gym_scripts.pory"
	.string "{PLAYER} received the Zephyr Badge from\n"
	.string "Falkner.$"

Common_Eventscript_Gym_Leader_Falkner_Text_8:
# 2469 "data/scripts/gym_scripts.pory"
	.string "I'm going to train harder to become the\n"
	.string "greatest Bird Keeper of all so let's\l"
	.string "fight again tomorrow!$"

Common_Eventscript_Gym_Leader_Falkner_Give_Gifts_Text_0:
# 2501 "data/scripts/gym_scripts.pory"
	.string "Please take this item with you.$"

Common_Eventscript_Gym_Leader_Falkner_Battle_New_Text_0:
# 2546 "data/scripts/gym_scripts.pory"
	.string "...Darn! My Dad's cherished bird\n"
	.string "Pokémon...$"

Common_Eventscript_Gym_Leader_Falkner_Battle_New_Text_1:
# 2553 "data/scripts/gym_scripts.pory"
	.string "A defeat is a defeat. You are strong\n"
	.string "indeed. I'm going to train harder with my\l"
	.string "Pokémon to become the greatest Bird\l"
	.string "Keeper of all!$"

Common_Eventscript_Gym_Leader_Falkner_Battle_New_Text_2:
# 2556 "data/scripts/gym_scripts.pory"
	.string "I understand... I'll bow out gracefully.$"

Common_Eventscript_Gym_Leader_Bugsy_Text_0:
# 2570 "data/scripts/gym_scripts.pory"
	.string "Bugsy: Good to see you again! Behold my\n"
	.string "bug research!$"

Common_Eventscript_Gym_Leader_Bugsy_Text_1:
# 2575 "data/scripts/gym_scripts.pory"
	.string "Bugsy: You must have studied a lot\n"
	.string "about Pokémon!$"

Common_Eventscript_Gym_Leader_Bugsy_Text_2:
# 2579 "data/scripts/gym_scripts.pory"
	.string "Bugsy: Come back tomorrow so we can\n"
	.string "battle again.$"

Common_Eventscript_Gym_Leader_Bugsy_Text_3:
# 2585 "data/scripts/gym_scripts.pory"
	.string "Bugsy: My Pokémon are tired for today,\n"
	.string "but the other trainers here need\l"
	.string "training, do you want to try battling\l"
	.string "them again?$"

Common_Eventscript_Gym_Leader_Bugsy_Text_4:
# 2589 "data/scripts/gym_scripts.pory"
	.string "Bugsy: I will tell them to get ready, so\n"
	.string "take care on your way out.$"

Common_Eventscript_Gym_Leader_Bugsy_Text_5:
# 2601 "data/scripts/gym_scripts.pory"
	.string "I'm Bugsy! I never lose when it comes to\n"
	.string "bug Pokémon. My research is going to\l"
	.string "make me the authority on bug Pokémon!\l"
	.string "Let me demonstrate what I've learned\l"
	.string "from my studies.$"

Common_Eventscript_Gym_Leader_Bugsy_Text_6:
# 2605 "data/scripts/gym_scripts.pory"
	.string "Whoa, amazing! You're an expert on\n"
	.string "Pokémon! My research isn't complete\l"
	.string "yet. OK, you win. Take this Badge.$"

Common_Eventscript_Gym_Leader_Bugsy_Text_7:
# 2606 "data/scripts/gym_scripts.pory"
	.string "{PLAYER} received the Hive Badge from\n"
	.string "Bugsy.$"

Common_Eventscript_Gym_Leader_Bugsy_Text_8:
# 2619 "data/scripts/gym_scripts.pory"
	.string "Bug-type Pokémon are deep. There are\n"
	.string "many mysteries to explore. Study your\l"
	.string "top choices thoroughly. Let's fight\l"
	.string "again tomorrow!$"

Common_Eventscript_Gym_Leader_Bugsy_Battle_New_Text_0:
# 2696 "data/scripts/gym_scripts.pory"
	.string "Aw, that's the end of it...$"

Common_Eventscript_Gym_Leader_Bugsy_Battle_New_Text_1:
# 2703 "data/scripts/gym_scripts.pory"
	.string "Whoa, amazing! You're an expert on\n"
	.string "Pokémon!$"

Common_Eventscript_Gym_Leader_Bugsy_Battle_New_Text_2:
# 2706 "data/scripts/gym_scripts.pory"
	.string "Whoa, amazing!$"

Common_Eventscript_Gym_Leader_Whitney_Text_0:
# 2720 "data/scripts/gym_scripts.pory"
	.string "Whitney: I never break my promises! Are\n"
	.string "you ready?$"

Common_Eventscript_Gym_Leader_Whitney_Text_1:
# 2725 "data/scripts/gym_scripts.pory"
	.string "Whitney: You really are strong! But I\n"
	.string "won't lose next time!$"

Common_Eventscript_Gym_Leader_Whitney_Text_2:
# 2729 "data/scripts/gym_scripts.pory"
	.string "Whitney: Come back tomorrow so we can\n"
	.string "battle again.$"

Common_Eventscript_Gym_Leader_Whitney_Text_3:
# 2735 "data/scripts/gym_scripts.pory"
	.string "Whitney: My Pokémon are tired for\n"
	.string "today, but the other trainers here need\l"
	.string "training, do you want to try battling\l"
	.string "them again?$"

Common_Eventscript_Gym_Leader_Whitney_Text_4:
# 2739 "data/scripts/gym_scripts.pory"
	.string "Whitney: I will tell them to get ready,\n"
	.string "so take care on your way out.$"

Common_Eventscript_Gym_Leader_Whitney_Text_5:
# 2751 "data/scripts/gym_scripts.pory"
	.string "Hi! I'm Whitney! Everyone was into\n"
	.string "Pokémon, so I got into it too! Pokémon\l"
	.string "are super-cute! You want to battle? I'm\l"
	.string "warning you--I'm good!$"

Common_Eventscript_Gym_Leader_Whitney_Text_6:
# 2755 "data/scripts/gym_scripts.pory"
	.string "...Sniff... What? What do you want? A\n"
	.string "Badge? Oh, right. I forgot. Here's Plain\l"
	.string "Badge, isn't it just perfect for a cutie\l"
	.string "like me?$"

Common_Eventscript_Gym_Leader_Whitney_Text_7:
# 2756 "data/scripts/gym_scripts.pory"
	.string "{PLAYER} received the Plain Badge from\n"
	.string "Whitney.$"

Common_Eventscript_Gym_Leader_Whitney_Text_8:
# 2769 "data/scripts/gym_scripts.pory"
	.string "Ah, that was a good cry! Come for a visit\n"
	.string "again! Bye-bye!$"

Common_Eventscript_Gym_Leader_Whitney_Battle_New_Text_0:
# 2846 "data/scripts/gym_scripts.pory"
	.string "Sob... ...Waaaaaaah! You're mean! You\n"
	.string "shouldn't be so serious! You...you child,\l"
	.string "you! Waaaaah! Waaaaah! ...Snivel, hic...\l"
	.string "...You meanie!$"

Common_Eventscript_Gym_Leader_Whitney_Battle_New_Text_1:
# 2853 "data/scripts/gym_scripts.pory"
	.string "Poor me!$"

Common_Eventscript_Gym_Leader_Whitney_Battle_New_Text_2:
# 2856 "data/scripts/gym_scripts.pory"
	.string "Waaaaah! Waaaaah! ...Snivel, hic. ... You\n"
	.string "meanie!$"

Common_Eventscript_Gym_Leader_Morty_Text_0:
# 2870 "data/scripts/gym_scripts.pory"
	.string "Morty: I was just talking about you...\n"
	.string "Let's battle!$"

Common_Eventscript_Gym_Leader_Morty_Text_1:
# 2875 "data/scripts/gym_scripts.pory"
	.string "Morty: I've lost again... You may have\n"
	.string "something more than just strength.$"

Common_Eventscript_Gym_Leader_Morty_Text_2:
# 2879 "data/scripts/gym_scripts.pory"
	.string "Morty: Come back tomorrow so we can\n"
	.string "battle again.$"

Common_Eventscript_Gym_Leader_Morty_Text_3:
# 2885 "data/scripts/gym_scripts.pory"
	.string "Morty: My Pokémon are tired for today,\n"
	.string "but the other trainers here need\l"
	.string "training, do you want to try battling\l"
	.string "them again?$"

Common_Eventscript_Gym_Leader_Morty_Text_4:
# 2889 "data/scripts/gym_scripts.pory"
	.string "Morty: I will tell them to get ready, so\n"
	.string "take care on your way out.$"

Common_Eventscript_Gym_Leader_Morty_Text_5:
# 2901 "data/scripts/gym_scripts.pory"
	.string "Whether you choose to believe or not,\n"
	.string "mystic power does exist.\p"
	.string "You can bear witness to the fruits of\n"
	.string "my training.\p"
	.string "You must make your soul one with that\n"
	.string "of Pokémon. Can you do this?$"

Common_Eventscript_Gym_Leader_Morty_Text_6:
# 2905 "data/scripts/gym_scripts.pory"
	.string "I don't think our potentials are so\n"
	.string "different. But you seem to have\l"
	.string "something more than that... So be it.\l"
	.string "This Badge is yours.$"

Common_Eventscript_Gym_Leader_Morty_Text_7:
# 2906 "data/scripts/gym_scripts.pory"
	.string "{PLAYER} received the Fog Badge from\n"
	.string "Morty.$"

Common_Eventscript_Gym_Leader_Morty_Text_8:
# 2919 "data/scripts/gym_scripts.pory"
	.string "I see... Your journey has taken you to\n"
	.string "far-away places. And you have\l"
	.string "witnessed much more than I. I envy you\l"
	.string "for that...$"

Common_Eventscript_Gym_Leader_Morty_Battle_New_Text_0:
# 2996 "data/scripts/gym_scripts.pory"
	.string "How is this possible...$"

Common_Eventscript_Gym_Leader_Morty_Battle_New_Text_1:
# 3003 "data/scripts/gym_scripts.pory"
	.string "I'm not good enough yet...$"

Common_Eventscript_Gym_Leader_Chuck_Text_0:
# 3020 "data/scripts/gym_scripts.pory"
	.string "Chuck: There you are! Taste my 24-hour\n"
	.string "training!$"

Common_Eventscript_Gym_Leader_Chuck_Text_1:
# 3025 "data/scripts/gym_scripts.pory"
	.string "Chuck: Wahaha! A battle with you is\n"
	.string "never boring!$"

Common_Eventscript_Gym_Leader_Chuck_Text_2:
# 3029 "data/scripts/gym_scripts.pory"
	.string "Chuck: Come back tomorrow so we can\n"
	.string "battle again.$"

Common_Eventscript_Gym_Leader_Chuck_Text_3:
# 3035 "data/scripts/gym_scripts.pory"
	.string "Chuck: My Pokémon are tired for today,\n"
	.string "but the other trainers here need\l"
	.string "training, do you want to try battling\l"
	.string "them again?$"

Common_Eventscript_Gym_Leader_Chuck_Text_4:
# 3039 "data/scripts/gym_scripts.pory"
	.string "Chuck: I will tell them to get ready, so\n"
	.string "take care on your way out.$"

Common_Eventscript_Gym_Leader_Chuck_Text_5:
# 3051 "data/scripts/gym_scripts.pory"
	.string "WAHAHAH! So you've come this far! Let\n"
	.string "me tell you, I'm tough!\p"
	.string "I can crush stones and shatter bones!\p"
	.string "Scared now, are you? What? It has\n"
	.string "nothing to do with Pokémon? That's\l"
	.string "true! Come on. We shall do battle!$"

Common_Eventscript_Gym_Leader_Chuck_Text_6:
# 3055 "data/scripts/gym_scripts.pory"
	.string "Hmm... I lost? How about that! All right.\n"
	.string "You're worthy of the Storm Badge!$"

Common_Eventscript_Gym_Leader_Chuck_Text_7:
# 3056 "data/scripts/gym_scripts.pory"
	.string "{PLAYER} received the Storm Badge from\n"
	.string "Chuck.$"

Common_Eventscript_Gym_Leader_Chuck_Text_8:
# 3069 "data/scripts/gym_scripts.pory"
	.string "Wahahah! I enjoyed battling you! But a\n"
	.string "loss is a loss! From now on, I'm going to\l"
	.string "train 24 hours a day!$"

Common_Eventscript_Gym_Leader_Chuck_Battle_New_Text_0:
# 3146 "data/scripts/gym_scripts.pory"
	.string "Wha? Huh? I lost?...$"

Common_Eventscript_Gym_Leader_Chuck_Battle_New_Text_1:
# 3153 "data/scripts/gym_scripts.pory"
	.string "Wahaha! I enjoyed battling you.$"

Common_Eventscript_Gym_Leader_Jasmine_Text_0:
# 3170 "data/scripts/gym_scripts.pory"
	.string "Jasmine: We're here as we promised... Are\n"
	.string "you prepared?$"

Common_Eventscript_Gym_Leader_Jasmine_Text_1:
# 3175 "data/scripts/gym_scripts.pory"
	.string "Jasmine: Properly tempered steel won't\n"
	.string "be made rusty by things like this!$"

Common_Eventscript_Gym_Leader_Jasmine_Text_2:
# 3179 "data/scripts/gym_scripts.pory"
	.string "Jasmine: Come back tomorrow so we can\n"
	.string "battle again.$"

Common_Eventscript_Gym_Leader_Jasmine_Text_3:
# 3185 "data/scripts/gym_scripts.pory"
	.string "Jasmine: My Pokémon are tired for\n"
	.string "today, but the other trainers here need\l"
	.string "training, do you want to try battling\l"
	.string "them again?$"

Common_Eventscript_Gym_Leader_Jasmine_Text_4:
# 3189 "data/scripts/gym_scripts.pory"
	.string "Jasmine: I will tell them to get ready,\n"
	.string "so take care on your way out.$"

Common_Eventscript_Gym_Leader_Jasmine_Text_5:
# 3201 "data/scripts/gym_scripts.pory"
	.string "Please allow me to introduce myself. I'm\n"
	.string "Jasmine, a Gym Leader. I use the...clang!\l"
	.string "Steel type! ...Do you know about the\l"
	.string "Steel type? They are very hard, cold,\l"
	.string "sharp, and really strong! Um... I'm not\l"
	.string "lying.$"

Common_Eventscript_Gym_Leader_Jasmine_Text_6:
# 3205 "data/scripts/gym_scripts.pory"
	.string "You are a better trainer than me, in\n"
	.string "both skill and kindness. In accordance\l"
	.string "with League rules, I confer upon you\l"
	.string "this Badge.$"

Common_Eventscript_Gym_Leader_Jasmine_Text_7:
# 3206 "data/scripts/gym_scripts.pory"
	.string "{PLAYER} received the Mineral Badge\n"
	.string "from Jasmine.$"

Common_Eventscript_Gym_Leader_Jasmine_Text_8:
# 3219 "data/scripts/gym_scripts.pory"
	.string "Um... I don't know how to say this, but\n"
	.string "good luck...$"

Common_Eventscript_Gym_Leader_Jasmine_Battle_New_Text_0:
# 3296 "data/scripts/gym_scripts.pory"
	.string "Well done...$"

Common_Eventscript_Gym_Leader_Jasmine_Battle_New_Text_1:
# 3303 "data/scripts/gym_scripts.pory"
	.string "True to your reputation...$"

Common_Eventscript_Gym_Leader_Pryce_Text_0:
# 3320 "data/scripts/gym_scripts.pory"
	.string "Pryce: Finally. No need for words. A\n"
	.string "Pokémon battle is the way for us to\l"
	.string "communicate.$"

Common_Eventscript_Gym_Leader_Pryce_Text_1:
# 3325 "data/scripts/gym_scripts.pory"
	.string "Pryce: If it's someone like you, I'm sure\n"
	.string "you'll keep winning and will find\l"
	.string "something important. Keep it up.$"

Common_Eventscript_Gym_Leader_Pryce_Text_2:
# 3329 "data/scripts/gym_scripts.pory"
	.string "Pryce: Come back tomorrow so we can\n"
	.string "battle again.$"

Common_Eventscript_Gym_Leader_Pryce_Text_3:
# 3335 "data/scripts/gym_scripts.pory"
	.string "Pryce: My Pokémon are tired for today,\n"
	.string "but the other trainers here need\l"
	.string "training, do you want to try battling\l"
	.string "them again?$"

Common_Eventscript_Gym_Leader_Pryce_Text_4:
# 3339 "data/scripts/gym_scripts.pory"
	.string "Pryce: I will tell them to get ready, so\n"
	.string "take care on your way out.$"

Common_Eventscript_Gym_Leader_Pryce_Text_5:
# 3351 "data/scripts/gym_scripts.pory"
	.string "Pokémon have many experiences in their\n"
	.string "lives, just like we do. I, too, have seen\l"
	.string "and suffered much in my life. Since I am\l"
	.string "your elder, let me show you what I mean.\l"
	.string "I have been with Pokémon since before\l"
	.string "you were born. I do not lose easily. I,\l"
	.string "Pryce--the winter trainer--shall\l"
	.string "demonstrate my power!$"

Common_Eventscript_Gym_Leader_Pryce_Text_6:
# 3355 "data/scripts/gym_scripts.pory"
	.string "I am impressed by your prowess. With\n"
	.string "your strong will, I know you will\l"
	.string "overcome all life's obstacles. You are\l"
	.string "worthy of this Badge!$"

Common_Eventscript_Gym_Leader_Pryce_Text_7:
# 3356 "data/scripts/gym_scripts.pory"
	.string "{PLAYER} received the Glacier Badge\n"
	.string "from Pryce.$"

Common_Eventscript_Gym_Leader_Pryce_Text_8:
# 3369 "data/scripts/gym_scripts.pory"
	.string "When the ice and snow melt, spring\n"
	.string "arrives. You and your Pokémon will be\l"
	.string "together for many years to come.\l"
	.string "Cherish your time together!$"

Common_Eventscript_Gym_Leader_Pryce_Battle_New_Text_0:
# 3445 "data/scripts/gym_scripts.pory"
	.string "Hmm. Seems as if my luck has run out.$"

Common_Eventscript_Gym_Leader_Pryce_Battle_New_Text_1:
# 3452 "data/scripts/gym_scripts.pory"
	.string "Mmm... Impressive!$"

Common_Eventscript_Gym_Leader_Clair_Text_0:
# 3470 "data/scripts/gym_scripts.pory"
	.string "...You are here. Now let's battle!$"

Common_Eventscript_Gym_Leader_Clair_Text_1:
# 3475 "data/scripts/gym_scripts.pory"
	.string "Way to go. ... Now give it your all!$"

Common_Eventscript_Gym_Leader_Clair_Text_2:
# 3479 "data/scripts/gym_scripts.pory"
	.string "Come back tomorrow so we can battle\n"
	.string "again.$"

Common_Eventscript_Gym_Leader_Clair_Text_3:
# 3485 "data/scripts/gym_scripts.pory"
	.string "My Pokémon are tired for today, but the\n"
	.string "other trainers here need training, do\l"
	.string "you want to try battling them again?$"

Common_Eventscript_Gym_Leader_Clair_Text_4:
# 3489 "data/scripts/gym_scripts.pory"
	.string "I will tell them to get ready, so take\n"
	.string "care on your way out.$"

Common_Eventscript_Gym_Leader_Clair_Text_5:
# 3501 "data/scripts/gym_scripts.pory"
	.string "I am Clair. The world's best Dragon\n"
	.string "master. I can hold my own against even\l"
	.string "the Pokémon League's Elite Four. Do you\l"
	.string "still want to take me on? ...Fine. Let's\l"
	.string "do it! As a trainer, I will use my full\l"
	.string "power against any opponent!$"

Common_Eventscript_Gym_Leader_Clair_Text_6:
# 3505 "data/scripts/gym_scripts.pory"
	.string "What I was missing until now... Battling\n"
	.string "with you made me realize what it is.\l"
	.string "That's how I feel. You are worthy of\l"
	.string "this Badge!$"

Common_Eventscript_Gym_Leader_Clair_Text_7:
# 3506 "data/scripts/gym_scripts.pory"
	.string "{PLAYER} received the Rising Badge from\n"
	.string "Clair.$"

Common_Eventscript_Gym_Leader_Clair_Text_8:
# 3519 "data/scripts/gym_scripts.pory"
	.string "Whatever you have to face from now,\n"
	.string "don't you dare give up! If you do, I'll\l"
	.string "feel even worse about having lost to\l"
	.string "you! Give it your all.$"

Common_Eventscript_Gym_Leader_Clair_Battle_New_Text_0:
# 3595 "data/scripts/gym_scripts.pory"
	.string "I lost? I don't believe it. There must be\n"
	.string "some mistake... ...You can brag about it.\l"
	.string "Because you beat me!$"

Common_Eventscript_Gym_Leader_Clair_Battle_New_Text_1:
# 3602 "data/scripts/gym_scripts.pory"
	.string "It's over...$"

Common_Eventscript_Gym_Leader_Clair_Battle_New_Text_2:
# 3605 "data/scripts/gym_scripts.pory"
	.string "Oh, I see..$"

Special_Gym_Text_Explain_Item_01::
# 30 "data/scripts/gym_scripts.pory"
	.string "This item is the Axe. You can use it cut\n"
	.string "small trees on your path.$"

Special_Gym_Text_Explain_Item_02::
# 40 "data/scripts/gym_scripts.pory"
	.string "This item is the Waterfall Tool. It lets\n"
	.string "you ascend using any waterfall you\l"
	.string "find.$"

Special_Gym_Text_Explain_Item_03::
# 45 "data/scripts/gym_scripts.pory"
	.string "This item is the Good Rod. You can use it\n"
	.string "to find stronger Pokémon than the Old\l"
	.string "Rod.$"

Special_Gym_Text_Explain_Item_04::
# 50 "data/scripts/gym_scripts.pory"
	.string "This item is the Pickaxe. It lets you\n"
	.string "break small rocks.$"

Special_Gym_Text_Explain_Item_05::
# 55 "data/scripts/gym_scripts.pory"
	.string "This item is a Catching Charm. It\n"
	.string "increase the chance of getting a\l"
	.string "critical catch.$"

Special_Gym_Text_Explain_Item_06::
# 60 "data/scripts/gym_scripts.pory"
	.string "This item is the Power Glove. It lets you\n"
	.string "move big rocks.$"

Special_Gym_Text_Explain_Item_07::
# 65 "data/scripts/gym_scripts.pory"
	.string "This item is the Rock Climb Tool. It lets\n"
	.string "ascend or descend using any rocky\l"
	.string "path.$"

Special_Gym_Text_Explain_Item_08::
# 70 "data/scripts/gym_scripts.pory"
	.string "This item is the Super Rod. Its the\n"
	.string "ultimate Rod you can find, its used by\l"
	.string "the pros for catching the strongest\l"
	.string "water Pokémon.$"

Special_Gym_Text_Explain_Item_09::
# 75 "data/scripts/gym_scripts.pory"
	.string "This item is the Fly Charm. It lets you\n"
	.string "use the Flying taxis for free.$"

Special_Gym_Text_Explain_Item_10::
# 80 "data/scripts/gym_scripts.pory"
	.string "This item is the Flying Mount. It lets\n"
	.string "you move use Fly using your own Pokémon\l"
	.string "at any time!$"

Special_Gym_Text_Explain_Item_11::
# 85 "data/scripts/gym_scripts.pory"
	.string "This item is the Mega Bracelet. This\n"
	.string "item will make you able to Mega Evolve\l"
	.string "your Pokémon Pressing Start with a\l"
	.string "Pokémon that can Mega Evolve in Battle.$"

Special_Gym_Text_Explain_Item_12::
# 90 "data/scripts/gym_scripts.pory"
	.string "This item is the Exp Charm. This item will\n"
	.string "make it so you receive double the\l"
	.string "Experience from battle.$"

Special_Gym_Text_Explain_Item_13::
# 95 "data/scripts/gym_scripts.pory"
	.string "This item is an Oval Charm. Its an item\n"
	.string "that doubles the possibilites of\l"
	.string "getting an Baby Pokémon from the\l"
	.string "Daycare.$"

Special_Gym_Text_Explain_Item_14::
# 100 "data/scripts/gym_scripts.pory"
	.string "This item is the Alpha Charm. It will let\n"
	.string "you encounter wild alpha Pokémon in the\l"
	.string "wild.$"

Special_Gym_Text_Explain_Item_15::
# 105 "data/scripts/gym_scripts.pory"
	.string "This item is the Wonder Charm. It will\n"
	.string "let you Wonder Trade for free.$"

Special_Gym_Text_Explain_Item_16::
# 110 "data/scripts/gym_scripts.pory"
	.string "This item is the Shiny Charm. Its an item\n"
	.string "that doubles the possibilites of\l"
	.string "getting a shiny Pokémon.$"

MauvilleCity_Gym_Text_WattsonIntro::
# 1094 "data/scripts/gym_scripts.pory"
	.string "I've given up on my plans to convert\n"
	.string "the city, I have.\p"
	.string "And so, I put my time into making\n"
	.string "door traps in my Gym.\p"
	.string "Oh? Now, what are you doing here?\p"
	.string "What's that? You say you've gotten\n"
	.string "past all my rigged doors?\p"
	.string "Wahahahah!\n"
	.string "Now, that is amusing!\p"
	.string "Then, I, Wattson, the Leader of\n"
	.string "Mauville Gym, shall electrify you!$"

MauvilleCity_Gym_Text_WattsonIntro_New::
# 1108 "data/scripts/gym_scripts.pory"
	.string "What? You say you've gotten past all my\n"
	.string "rigged doors? Wahahahah! Now, that is\l"
	.string "amusing! The plans to reform Mauville\l"
	.string "are done for now. Making traps for my\l"
	.string "Gym and battling with young Trainers\l"
	.string "like you are the things I live for now!\l"
	.string "Then I, Wattson, the Leader of Mauville\l"
	.string "Gym, shall electrify you!$"
