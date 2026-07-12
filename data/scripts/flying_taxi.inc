Common_EventScript_FlyingTaxi::
# 2 "data/scripts/flying_taxi.pory"
	lock
# 3 "data/scripts/flying_taxi.pory"
	faceplayer
# 4 "data/scripts/flying_taxi.pory"
	setvar VAR_0x800A, LAST_TALKED_TO_FLYING_TAXI
# 5 "data/scripts/flying_taxi.pory"
	checkitem ITEM_FLY_CHARM, 1
# 6 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_FlyingTaxi_2
# 12 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_FlyingTaxi_Text_1, MSGBOX_YESNO
Common_EventScript_FlyingTaxi_1:
# 14 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_FlyingTaxi_6
Common_EventScript_FlyingTaxi_5:
# 38 "data/scripts/flying_taxi.pory"
	checkitem ITEM_FLY_CHARM, 1
# 39 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_FlyingTaxi_9
Common_EventScript_FlyingTaxi_8:
# 42 "data/scripts/flying_taxi.pory"
	msgbox gText_WeHopeToSeeYouAgain, MSGBOX_DEFAULT
# 43 "data/scripts/flying_taxi.pory"
	setvar VAR_LAST_TALKED, 0
# 44 "data/scripts/flying_taxi.pory"
	releaseall
	end

Common_EventScript_FlyingTaxi_2:
# 7 "data/scripts/flying_taxi.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 8 "data/scripts/flying_taxi.pory"
	showbpbox 0, 0, 0
# 9 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_FlyingTaxi_Text_0, MSGBOX_YESNO
	goto Common_EventScript_FlyingTaxi_1

Common_EventScript_FlyingTaxi_6:
# 16 "data/scripts/flying_taxi.pory"
	checkitem ITEM_FLY_CHARM, 1
# 17 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_FlyingTaxi_12
Common_EventScript_FlyingTaxi_11:
# 21 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_FlyingTaxi_14
# 26 "data/scripts/flying_taxi.pory"
	checkitem ITEM_FLY_CHARM, 1
# 27 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_FlyingTaxi_18
Common_EventScript_FlyingTaxi_17:
# 35 "data/scripts/flying_taxi.pory"
	special FieldLoadFlyMap
	goto Common_EventScript_FlyingTaxi_5

Common_EventScript_FlyingTaxi_9:
# 40 "data/scripts/flying_taxi.pory"
	hidebpbox
	goto Common_EventScript_FlyingTaxi_8

Common_EventScript_FlyingTaxi_12:
# 18 "data/scripts/flying_taxi.pory"
	checkbp FLYING_TAXIS_PRICE, 0
	goto Common_EventScript_FlyingTaxi_11

Common_EventScript_FlyingTaxi_14:
# 22 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_FlyingTaxi_Text_2, MSGBOX_DEFAULT
# 23 "data/scripts/flying_taxi.pory"
	setvar VAR_SHOP_MONEY_TYPE, 0
	goto Common_EventScript_FlyingTaxi_5

Common_EventScript_FlyingTaxi_18:
# 28 "data/scripts/flying_taxi.pory"
	playse SE_SHOP
# 31 "data/scripts/flying_taxi.pory"
	takebp FLYING_TAXIS_PRICE, 0
# 32 "data/scripts/flying_taxi.pory"
	setflag FLAG_USING_FLYING_TAXIS
# 33 "data/scripts/flying_taxi.pory"
	hidebpbox
	goto Common_EventScript_FlyingTaxi_17


LilycoveCity_Harbor_EventScript_ExitSailSelect::
# 67 "data/scripts/flying_taxi.pory"
	msgbox LilycoveCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
# 68 "data/scripts/flying_taxi.pory"
	release
	end


LilycoveCity_Harbor_EventScript_FerryAttendant::
# 73 "data/scripts/flying_taxi.pory"
	lock
# 74 "data/scripts/flying_taxi.pory"
	faceplayer
# 75 "data/scripts/flying_taxi.pory"
	msgbox LilycoveCity_Harbor_EventScript_FerryAttendant_Text_0, MSGBOX_DEFAULT
# 78 "data/scripts/flying_taxi.pory"
	goto LilycoveCity_Harbor_EventScript_Ferry_Location_Select
	end


LilycoveCity_Harbor_EventScript_Ferry_Location_Select::
# 83 "data/scripts/flying_taxi.pory"
	clearflag FLAG_SAILED_FROM_SLATEPORT
# 84 "data/scripts/flying_taxi.pory"
	msgbox LilycoveCity_Harbor_EventScript_Ferry_Location_Select_Text_0, MSGBOX_DEFAULT
# 85 "data/scripts/flying_taxi.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_Ferry_Location_Select_2
# 95 "data/scripts/flying_taxi.pory"
	scrollingmultichoice SCROLLING_LILYCOVE_HARBOR_AFTER_LEAGUE_OPTIONS, 0, 0, 4, TRUE
# 96 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_WarpUsingFerry
LilycoveCity_Harbor_EventScript_Ferry_Location_Select_1:
# 98 "data/scripts/flying_taxi.pory"
	waitstate
# 99 "data/scripts/flying_taxi.pory"
	release
	end

LilycoveCity_Harbor_EventScript_Ferry_Location_Select_2:
# 86 "data/scripts/flying_taxi.pory"
	scrollingmultichoice SCROLLING_LILYCOVE_HARBOR_BEFORE_LEAGUE_OPTIONS, 0, 0, 4, TRUE
# 87 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, 9
	goto_if_lt LilycoveCity_Harbor_EventScript_Ferry_Location_Select_5
# 91 "data/scripts/flying_taxi.pory"
	goto LilycoveCity_Harbor_EventScript_ExitSailSelect
	goto LilycoveCity_Harbor_EventScript_Ferry_Location_Select_1

LilycoveCity_Harbor_EventScript_Ferry_Location_Select_5:
# 88 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_WarpUsingFerry
	goto LilycoveCity_Harbor_EventScript_Ferry_Location_Select_1


Common_EventScript_Colress_One_Island::
# 104 "data/scripts/flying_taxi.pory"
	lock
# 105 "data/scripts/flying_taxi.pory"
	faceplayer
# 106 "data/scripts/flying_taxi.pory"
	setvar VAR_CURRENT_SEVII, 0
# 107 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress
	return


Common_EventScript_Colress_Two_Island::
# 111 "data/scripts/flying_taxi.pory"
	lock
# 112 "data/scripts/flying_taxi.pory"
	faceplayer
# 113 "data/scripts/flying_taxi.pory"
	setvar VAR_CURRENT_SEVII, 1
# 114 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress
	return


Common_EventScript_Colress_Three_Island::
# 118 "data/scripts/flying_taxi.pory"
	lock
# 119 "data/scripts/flying_taxi.pory"
	faceplayer
# 120 "data/scripts/flying_taxi.pory"
	setvar VAR_CURRENT_SEVII, 2
# 121 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress
	return


Common_EventScript_Colress_Four_Island::
# 125 "data/scripts/flying_taxi.pory"
	lock
# 126 "data/scripts/flying_taxi.pory"
	faceplayer
# 127 "data/scripts/flying_taxi.pory"
	setvar VAR_CURRENT_SEVII, 3
# 128 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress
	return


Common_EventScript_Colress_Five_Island::
# 132 "data/scripts/flying_taxi.pory"
	lock
# 133 "data/scripts/flying_taxi.pory"
	faceplayer
# 134 "data/scripts/flying_taxi.pory"
	setvar VAR_CURRENT_SEVII, 4
# 135 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress
	return


Common_EventScript_Colress_Six_Island::
# 139 "data/scripts/flying_taxi.pory"
	lock
# 140 "data/scripts/flying_taxi.pory"
	faceplayer
# 141 "data/scripts/flying_taxi.pory"
	setvar VAR_CURRENT_SEVII, 5
# 142 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress
	return


Common_EventScript_Colress_Seven_Island::
# 146 "data/scripts/flying_taxi.pory"
	lock
# 147 "data/scripts/flying_taxi.pory"
	faceplayer
# 148 "data/scripts/flying_taxi.pory"
	setvar VAR_CURRENT_SEVII, 6
# 149 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress
	return


Common_EventScript_Colress_Eight_Island::
# 153 "data/scripts/flying_taxi.pory"
	lock
# 154 "data/scripts/flying_taxi.pory"
	faceplayer
# 155 "data/scripts/flying_taxi.pory"
	setvar VAR_CURRENT_SEVII, 7
# 156 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress
	return


Common_EventScript_Colress::
# 160 "data/scripts/flying_taxi.pory"
	switch VAR_VISITED_SEVII
# 161 "data/scripts/flying_taxi.pory"
	case 0, Common_EventScript_Colress_3
# 164 "data/scripts/flying_taxi.pory"
	case 1, Common_EventScript_Colress_4
# 165 "data/scripts/flying_taxi.pory"
	case 2, Common_EventScript_Colress_4
# 166 "data/scripts/flying_taxi.pory"
	case 3, Common_EventScript_Colress_4
# 167 "data/scripts/flying_taxi.pory"
	case 4, Common_EventScript_Colress_4
# 168 "data/scripts/flying_taxi.pory"
	case 5, Common_EventScript_Colress_4
# 169 "data/scripts/flying_taxi.pory"
	case 6, Common_EventScript_Colress_4
# 172 "data/scripts/flying_taxi.pory"
	case 7, Common_EventScript_Colress_5
# 173 "data/scripts/flying_taxi.pory"
	case 8, Common_EventScript_Colress_5
Common_EventScript_Colress_1:
	end

Common_EventScript_Colress_3:
# 162 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter
	goto Common_EventScript_Colress_1

Common_EventScript_Colress_4:
# 170 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_Second_Encounter
	goto Common_EventScript_Colress_1

Common_EventScript_Colress_5:
# 174 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_Final_Encounter
	goto Common_EventScript_Colress_1


Common_EventScript_Colress_First_Encounter::
# 183 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_Text_0, MSGBOX_DEFAULT
# 184 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_Text_1, MSGBOX_DEFAULT
# 185 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_Text_2, MSGBOX_DEFAULT
# 186 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_Text_3, MSGBOX_DEFAULT
# 187 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
	return


Common_EventScript_Colress_Second_Encounter::
# 191 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_Second_Encounter_Text_0, MSGBOX_DEFAULT
# 192 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
	return


Common_EventScript_Colress_Final_Encounter::
# 196 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_Final_Encounter_Text_0, MSGBOX_DEFAULT
# 197 "data/scripts/flying_taxi.pory"
	giveitem ITEM_SHOCK_DRIVE
# 198 "data/scripts/flying_taxi.pory"
	giveitem ITEM_BURN_DRIVE
# 199 "data/scripts/flying_taxi.pory"
	giveitem ITEM_CHILL_DRIVE
# 200 "data/scripts/flying_taxi.pory"
	giveitem ITEM_DOUSE_DRIVE
# 201 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_Final_Encounter_Text_1, MSGBOX_YESNO
# 202 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_Colress_Final_Encounter_2
# 206 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_Final_Encounter_Text_3, MSGBOX_DEFAULT
Common_EventScript_Colress_Final_Encounter_1:
# 208 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_Final_Encounter_Text_4, MSGBOX_DEFAULT
# 209 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_Final_Encounter_Text_5, MSGBOX_DEFAULT
# 210 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_Final_Encounter_Text_6, MSGBOX_DEFAULT
# 211 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_Final_Encounter_Text_7, MSGBOX_DEFAULT
# 212 "data/scripts/flying_taxi.pory"
	call Common_EventScript_Colress_SetTicketFlag
# 213 "data/scripts/flying_taxi.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	return

Common_EventScript_Colress_Final_Encounter_2:
# 203 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_Final_Encounter_Text_2, MSGBOX_DEFAULT
	goto Common_EventScript_Colress_Final_Encounter_1


Common_EventScript_Colress_First_Encounter_ChooseIsland::
# 217 "data/scripts/flying_taxi.pory"
	scrollingmultichoice SCROLLING_SEVII_TICKET, 0, 0, 4, TRUE
# 218 "data/scripts/flying_taxi.pory"
	switch VAR_RESULT
# 219 "data/scripts/flying_taxi.pory"
	case 0, Common_EventScript_Colress_First_Encounter_ChooseIsland_2
# 244 "data/scripts/flying_taxi.pory"
	case 1, Common_EventScript_Colress_First_Encounter_ChooseIsland_3
# 269 "data/scripts/flying_taxi.pory"
	case 2, Common_EventScript_Colress_First_Encounter_ChooseIsland_4
# 294 "data/scripts/flying_taxi.pory"
	case 3, Common_EventScript_Colress_First_Encounter_ChooseIsland_5
# 319 "data/scripts/flying_taxi.pory"
	case 4, Common_EventScript_Colress_First_Encounter_ChooseIsland_6
# 344 "data/scripts/flying_taxi.pory"
	case 5, Common_EventScript_Colress_First_Encounter_ChooseIsland_7
# 369 "data/scripts/flying_taxi.pory"
	case 6, Common_EventScript_Colress_First_Encounter_ChooseIsland_8
# 394 "data/scripts/flying_taxi.pory"
	case 7, Common_EventScript_Colress_First_Encounter_ChooseIsland_9
	return

Common_EventScript_Colress_First_Encounter_ChooseIsland_2:
# 221 "data/scripts/flying_taxi.pory"
	checkitem ITEM_SEVII_TICKET_1, 1
# 222 "data/scripts/flying_taxi.pory"
	setvar VAR_TEMP_A, 0
# 223 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_11
# 233 "data/scripts/flying_taxi.pory"
	compare VAR_CURRENT_SEVII, 0
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_12
# 239 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_4, MSGBOX_DEFAULT
# 240 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3, MSGBOX_DEFAULT
# 241 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
Common_EventScript_Colress_First_Encounter_ChooseIsland_10:
	return

Common_EventScript_Colress_First_Encounter_ChooseIsland_3:
# 246 "data/scripts/flying_taxi.pory"
	checkitem ITEM_SEVII_TICKET_2, 1
# 247 "data/scripts/flying_taxi.pory"
	setvar VAR_TEMP_A, 1
# 248 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_17
# 258 "data/scripts/flying_taxi.pory"
	compare VAR_CURRENT_SEVII, 1
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_18
# 264 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_4, MSGBOX_DEFAULT
# 265 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3, MSGBOX_DEFAULT
# 266 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
Common_EventScript_Colress_First_Encounter_ChooseIsland_16:
	return

Common_EventScript_Colress_First_Encounter_ChooseIsland_4:
# 271 "data/scripts/flying_taxi.pory"
	checkitem ITEM_SEVII_TICKET_3, 1
# 272 "data/scripts/flying_taxi.pory"
	setvar VAR_TEMP_A, 2
# 273 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_23
# 283 "data/scripts/flying_taxi.pory"
	compare VAR_CURRENT_SEVII, 2
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_24
# 289 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_4, MSGBOX_DEFAULT
# 290 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3, MSGBOX_DEFAULT
# 291 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
Common_EventScript_Colress_First_Encounter_ChooseIsland_22:
	return

Common_EventScript_Colress_First_Encounter_ChooseIsland_5:
# 296 "data/scripts/flying_taxi.pory"
	checkitem ITEM_SEVII_TICKET_4, 1
# 297 "data/scripts/flying_taxi.pory"
	setvar VAR_TEMP_A, 3
# 298 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_29
# 308 "data/scripts/flying_taxi.pory"
	compare VAR_CURRENT_SEVII, 3
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_30
# 314 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_4, MSGBOX_DEFAULT
# 315 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3, MSGBOX_DEFAULT
# 316 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
Common_EventScript_Colress_First_Encounter_ChooseIsland_28:
	return

Common_EventScript_Colress_First_Encounter_ChooseIsland_6:
# 321 "data/scripts/flying_taxi.pory"
	checkitem ITEM_SEVII_TICKET_5, 1
# 322 "data/scripts/flying_taxi.pory"
	setvar VAR_TEMP_A, 4
# 323 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_35
# 333 "data/scripts/flying_taxi.pory"
	compare VAR_CURRENT_SEVII, 4
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_36
# 339 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_4, MSGBOX_DEFAULT
# 340 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3, MSGBOX_DEFAULT
# 341 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
Common_EventScript_Colress_First_Encounter_ChooseIsland_34:
	return

Common_EventScript_Colress_First_Encounter_ChooseIsland_7:
# 346 "data/scripts/flying_taxi.pory"
	checkitem ITEM_SEVII_TICKET_6, 1
# 347 "data/scripts/flying_taxi.pory"
	setvar VAR_TEMP_A, 5
# 348 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_41
# 358 "data/scripts/flying_taxi.pory"
	compare VAR_CURRENT_SEVII, 5
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_42
# 364 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_4, MSGBOX_DEFAULT
# 365 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3, MSGBOX_DEFAULT
# 366 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
Common_EventScript_Colress_First_Encounter_ChooseIsland_40:
	return

Common_EventScript_Colress_First_Encounter_ChooseIsland_8:
# 371 "data/scripts/flying_taxi.pory"
	checkitem ITEM_SEVII_TICKET_7, 1
# 372 "data/scripts/flying_taxi.pory"
	setvar VAR_TEMP_A, 6
# 373 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_47
# 383 "data/scripts/flying_taxi.pory"
	compare VAR_CURRENT_SEVII, 6
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_48
# 389 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_4, MSGBOX_DEFAULT
# 390 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3, MSGBOX_DEFAULT
# 391 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
Common_EventScript_Colress_First_Encounter_ChooseIsland_46:
	return

Common_EventScript_Colress_First_Encounter_ChooseIsland_9:
# 396 "data/scripts/flying_taxi.pory"
	checkitem ITEM_SEVII_TICKET_8, 1
# 397 "data/scripts/flying_taxi.pory"
	setvar VAR_TEMP_A, 7
# 398 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_53
# 410 "data/scripts/flying_taxi.pory"
	compare VAR_CURRENT_SEVII, 7
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_54
# 416 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_4, MSGBOX_DEFAULT
# 417 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3, MSGBOX_DEFAULT
# 418 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
Common_EventScript_Colress_First_Encounter_ChooseIsland_52:
	return

Common_EventScript_Colress_First_Encounter_ChooseIsland_11:
# 224 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_0, MSGBOX_DEFAULT
# 225 "data/scripts/flying_taxi.pory"
	giveitem ITEM_SEVII_TICKET_1
# 226 "data/scripts/flying_taxi.pory"
	addvar VAR_VISITED_SEVII, 1
# 228 "data/scripts/flying_taxi.pory"
	compare VAR_VISITED_SEVII, 1
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_59
Common_EventScript_Colress_First_Encounter_ChooseIsland_58:
# 231 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_AskForWarping
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_10

Common_EventScript_Colress_First_Encounter_ChooseIsland_12:
# 234 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_2, MSGBOX_DEFAULT
# 235 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3, MSGBOX_DEFAULT
# 236 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_10

Common_EventScript_Colress_First_Encounter_ChooseIsland_17:
# 249 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_5, MSGBOX_DEFAULT
# 250 "data/scripts/flying_taxi.pory"
	giveitem ITEM_SEVII_TICKET_2
# 251 "data/scripts/flying_taxi.pory"
	addvar VAR_VISITED_SEVII, 1
# 253 "data/scripts/flying_taxi.pory"
	compare VAR_VISITED_SEVII, 1
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_62
Common_EventScript_Colress_First_Encounter_ChooseIsland_61:
# 256 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_AskForWarping
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_16

Common_EventScript_Colress_First_Encounter_ChooseIsland_18:
# 259 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_2, MSGBOX_DEFAULT
# 260 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3, MSGBOX_DEFAULT
# 261 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_16

Common_EventScript_Colress_First_Encounter_ChooseIsland_23:
# 274 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_6, MSGBOX_DEFAULT
# 275 "data/scripts/flying_taxi.pory"
	giveitem ITEM_SEVII_TICKET_3
# 276 "data/scripts/flying_taxi.pory"
	addvar VAR_VISITED_SEVII, 1
# 278 "data/scripts/flying_taxi.pory"
	compare VAR_VISITED_SEVII, 1
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_65
Common_EventScript_Colress_First_Encounter_ChooseIsland_64:
# 281 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_AskForWarping
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_22

Common_EventScript_Colress_First_Encounter_ChooseIsland_24:
# 284 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_2, MSGBOX_DEFAULT
# 285 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3, MSGBOX_DEFAULT
# 286 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_22

Common_EventScript_Colress_First_Encounter_ChooseIsland_29:
# 299 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_7, MSGBOX_DEFAULT
# 300 "data/scripts/flying_taxi.pory"
	giveitem ITEM_SEVII_TICKET_4
# 301 "data/scripts/flying_taxi.pory"
	addvar VAR_VISITED_SEVII, 1
# 303 "data/scripts/flying_taxi.pory"
	compare VAR_VISITED_SEVII, 1
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_68
Common_EventScript_Colress_First_Encounter_ChooseIsland_67:
# 306 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_AskForWarping
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_28

Common_EventScript_Colress_First_Encounter_ChooseIsland_30:
# 309 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_2, MSGBOX_DEFAULT
# 310 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3, MSGBOX_DEFAULT
# 311 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_28

Common_EventScript_Colress_First_Encounter_ChooseIsland_35:
# 324 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_8, MSGBOX_DEFAULT
# 325 "data/scripts/flying_taxi.pory"
	giveitem ITEM_SEVII_TICKET_5
# 326 "data/scripts/flying_taxi.pory"
	addvar VAR_VISITED_SEVII, 1
# 328 "data/scripts/flying_taxi.pory"
	compare VAR_VISITED_SEVII, 1
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_71
Common_EventScript_Colress_First_Encounter_ChooseIsland_70:
# 331 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_AskForWarping
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_34

Common_EventScript_Colress_First_Encounter_ChooseIsland_36:
# 334 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_2, MSGBOX_DEFAULT
# 335 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3, MSGBOX_DEFAULT
# 336 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_34

Common_EventScript_Colress_First_Encounter_ChooseIsland_41:
# 349 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_9, MSGBOX_DEFAULT
# 350 "data/scripts/flying_taxi.pory"
	giveitem ITEM_SEVII_TICKET_6
# 351 "data/scripts/flying_taxi.pory"
	addvar VAR_VISITED_SEVII, 1
# 353 "data/scripts/flying_taxi.pory"
	compare VAR_VISITED_SEVII, 1
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_74
Common_EventScript_Colress_First_Encounter_ChooseIsland_73:
# 356 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_AskForWarping
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_40

Common_EventScript_Colress_First_Encounter_ChooseIsland_42:
# 359 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_2, MSGBOX_DEFAULT
# 360 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3, MSGBOX_DEFAULT
# 361 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_40

Common_EventScript_Colress_First_Encounter_ChooseIsland_47:
# 374 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_10, MSGBOX_DEFAULT
# 375 "data/scripts/flying_taxi.pory"
	giveitem ITEM_SEVII_TICKET_7
# 376 "data/scripts/flying_taxi.pory"
	addvar VAR_VISITED_SEVII, 1
# 378 "data/scripts/flying_taxi.pory"
	compare VAR_VISITED_SEVII, 1
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_77
Common_EventScript_Colress_First_Encounter_ChooseIsland_76:
# 381 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_AskForWarping
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_46

Common_EventScript_Colress_First_Encounter_ChooseIsland_48:
# 384 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_2, MSGBOX_DEFAULT
# 385 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3, MSGBOX_DEFAULT
# 386 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_46

Common_EventScript_Colress_First_Encounter_ChooseIsland_53:
# 399 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_11, MSGBOX_DEFAULT
# 400 "data/scripts/flying_taxi.pory"
	delay 90
# 401 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_12, MSGBOX_DEFAULT
# 402 "data/scripts/flying_taxi.pory"
	giveitem ITEM_SEVII_TICKET_8
# 403 "data/scripts/flying_taxi.pory"
	addvar VAR_VISITED_SEVII, 1
# 405 "data/scripts/flying_taxi.pory"
	compare VAR_VISITED_SEVII, 1
	goto_if_eq Common_EventScript_Colress_First_Encounter_ChooseIsland_80
Common_EventScript_Colress_First_Encounter_ChooseIsland_79:
# 408 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_AskForWarping
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_52

Common_EventScript_Colress_First_Encounter_ChooseIsland_54:
# 411 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_2, MSGBOX_DEFAULT
# 412 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3, MSGBOX_DEFAULT
# 413 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_52

Common_EventScript_Colress_First_Encounter_ChooseIsland_59:
# 229 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_58

Common_EventScript_Colress_First_Encounter_ChooseIsland_62:
# 254 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_61

Common_EventScript_Colress_First_Encounter_ChooseIsland_65:
# 279 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_64

Common_EventScript_Colress_First_Encounter_ChooseIsland_68:
# 304 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_67

Common_EventScript_Colress_First_Encounter_ChooseIsland_71:
# 329 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_70

Common_EventScript_Colress_First_Encounter_ChooseIsland_74:
# 354 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_73

Common_EventScript_Colress_First_Encounter_ChooseIsland_77:
# 379 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_76

Common_EventScript_Colress_First_Encounter_ChooseIsland_80:
# 406 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_Colress_First_Encounter_ChooseIsland_79


Common_EventScript_Colress_AskForWarping::
# 425 "data/scripts/flying_taxi.pory"
	call Common_EventScript_Colress_SetTicketFlag
# 426 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_AskForWarping_Text_0, MSGBOX_YESNO
# 427 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_Colress_AskForWarping_2
# 431 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_WarpToSevii
Common_EventScript_Colress_AskForWarping_1:
# 433 "data/scripts/flying_taxi.pory"
	waitstate
# 434 "data/scripts/flying_taxi.pory"
	release
	end

Common_EventScript_Colress_AskForWarping_2:
# 428 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress_NoWarp
	goto Common_EventScript_Colress_AskForWarping_1


Common_EventScript_Colress_SetTicketFlag::
# 439 "data/scripts/flying_taxi.pory"
	switch VAR_CURRENT_SEVII
# 440 "data/scripts/flying_taxi.pory"
	case 0, Common_EventScript_Colress_SetTicketFlag_3
# 443 "data/scripts/flying_taxi.pory"
	case 1, Common_EventScript_Colress_SetTicketFlag_4
# 446 "data/scripts/flying_taxi.pory"
	case 2, Common_EventScript_Colress_SetTicketFlag_5
# 449 "data/scripts/flying_taxi.pory"
	case 3, Common_EventScript_Colress_SetTicketFlag_6
# 452 "data/scripts/flying_taxi.pory"
	case 4, Common_EventScript_Colress_SetTicketFlag_7
# 455 "data/scripts/flying_taxi.pory"
	case 5, Common_EventScript_Colress_SetTicketFlag_8
# 458 "data/scripts/flying_taxi.pory"
	case 6, Common_EventScript_Colress_SetTicketFlag_9
# 461 "data/scripts/flying_taxi.pory"
	case 7, Common_EventScript_Colress_SetTicketFlag_10
Common_EventScript_Colress_SetTicketFlag_1:
	return

Common_EventScript_Colress_SetTicketFlag_3:
# 441 "data/scripts/flying_taxi.pory"
	setflag FLAG_GOT_SEVII_TICKET_1
	goto Common_EventScript_Colress_SetTicketFlag_1

Common_EventScript_Colress_SetTicketFlag_4:
# 444 "data/scripts/flying_taxi.pory"
	setflag FLAG_GOT_SEVII_TICKET_2
	goto Common_EventScript_Colress_SetTicketFlag_1

Common_EventScript_Colress_SetTicketFlag_5:
# 447 "data/scripts/flying_taxi.pory"
	setflag FLAG_GOT_SEVII_TICKET_3
	goto Common_EventScript_Colress_SetTicketFlag_1

Common_EventScript_Colress_SetTicketFlag_6:
# 450 "data/scripts/flying_taxi.pory"
	setflag FLAG_GOT_SEVII_TICKET_4
	goto Common_EventScript_Colress_SetTicketFlag_1

Common_EventScript_Colress_SetTicketFlag_7:
# 453 "data/scripts/flying_taxi.pory"
	setflag FLAG_GOT_SEVII_TICKET_5
	goto Common_EventScript_Colress_SetTicketFlag_1

Common_EventScript_Colress_SetTicketFlag_8:
# 456 "data/scripts/flying_taxi.pory"
	setflag FLAG_GOT_SEVII_TICKET_6
	goto Common_EventScript_Colress_SetTicketFlag_1

Common_EventScript_Colress_SetTicketFlag_9:
# 459 "data/scripts/flying_taxi.pory"
	setflag FLAG_GOT_SEVII_TICKET_7
	goto Common_EventScript_Colress_SetTicketFlag_1

Common_EventScript_Colress_SetTicketFlag_10:
# 462 "data/scripts/flying_taxi.pory"
	setflag FLAG_GOT_SEVII_TICKET_8
	goto Common_EventScript_Colress_SetTicketFlag_1


Common_EventScript_Colress_NoWarp::
# 469 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_NoWarp_Text_0, MSGBOX_DEFAULT
# 470 "data/scripts/flying_taxi.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
# 471 "data/scripts/flying_taxi.pory"
	waitstate
# 472 "data/scripts/flying_taxi.pory"
	release
	end


Common_EventScript_Colress_WarpToSevii::
# 477 "data/scripts/flying_taxi.pory"
	msgbox Common_EventScript_Colress_WarpToSevii_Text_0, MSGBOX_DEFAULT
# 479 "data/scripts/flying_taxi.pory"
	switch VAR_TEMP_A
# 480 "data/scripts/flying_taxi.pory"
	case 0, Common_EventScript_Colress_WarpToSevii_3
# 483 "data/scripts/flying_taxi.pory"
	case 1, Common_EventScript_Colress_WarpToSevii_4
# 486 "data/scripts/flying_taxi.pory"
	case 2, Common_EventScript_Colress_WarpToSevii_5
# 489 "data/scripts/flying_taxi.pory"
	case 3, Common_EventScript_Colress_WarpToSevii_6
# 492 "data/scripts/flying_taxi.pory"
	case 4, Common_EventScript_Colress_WarpToSevii_7
# 495 "data/scripts/flying_taxi.pory"
	case 5, Common_EventScript_Colress_WarpToSevii_8
# 498 "data/scripts/flying_taxi.pory"
	case 6, Common_EventScript_Colress_WarpToSevii_9
# 501 "data/scripts/flying_taxi.pory"
	case 7, Common_EventScript_Colress_WarpToSevii_10
Common_EventScript_Colress_WarpToSevii_1:
# 505 "data/scripts/flying_taxi.pory"
	waitstate
# 506 "data/scripts/flying_taxi.pory"
	release
	end

Common_EventScript_Colress_WarpToSevii_3:
# 481 "data/scripts/flying_taxi.pory"
	warp MAP_ONE_ISLAND, 255, 28, 17
	goto Common_EventScript_Colress_WarpToSevii_1

Common_EventScript_Colress_WarpToSevii_4:
# 484 "data/scripts/flying_taxi.pory"
	warp MAP_TWO_ISLAND, 255, 10, 7
	goto Common_EventScript_Colress_WarpToSevii_1

Common_EventScript_Colress_WarpToSevii_5:
# 487 "data/scripts/flying_taxi.pory"
	warp MAP_THREE_ISLAND_PORT, 255, 12, 12
	goto Common_EventScript_Colress_WarpToSevii_1

Common_EventScript_Colress_WarpToSevii_6:
# 490 "data/scripts/flying_taxi.pory"
	warp MAP_FOUR_ISLAND, 255, 10, 27
	goto Common_EventScript_Colress_WarpToSevii_1

Common_EventScript_Colress_WarpToSevii_7:
# 493 "data/scripts/flying_taxi.pory"
	warp MAP_FIVE_ISLAND, 255, 23, 23
	goto Common_EventScript_Colress_WarpToSevii_1

Common_EventScript_Colress_WarpToSevii_8:
# 496 "data/scripts/flying_taxi.pory"
	warp MAP_SIX_ISLAND, 255, 27, 22
	goto Common_EventScript_Colress_WarpToSevii_1

Common_EventScript_Colress_WarpToSevii_9:
# 499 "data/scripts/flying_taxi.pory"
	warp MAP_SEVEN_ISLAND, 255, 19, 12
	goto Common_EventScript_Colress_WarpToSevii_1

Common_EventScript_Colress_WarpToSevii_10:
# 502 "data/scripts/flying_taxi.pory"
	warp MAP_EIGHT_ISLAND, 255, 20, 33
	goto Common_EventScript_Colress_WarpToSevii_1


SlateportCity_Harbor_EventScript_FerryAttendant::
# 511 "data/scripts/flying_taxi.pory"
	lock
# 512 "data/scripts/flying_taxi.pory"
	faceplayer
# 513 "data/scripts/flying_taxi.pory"
	msgbox LilycoveCity_Harbor_EventScript_FerryAttendant_Text_0, MSGBOX_DEFAULT
# 516 "data/scripts/flying_taxi.pory"
	goto SlateportCity_Harbor_EventScript_Ferry_Location_Select
	end


SlateportCity_Harbor_EventScript_Ferry_Location_Select::
# 521 "data/scripts/flying_taxi.pory"
	setflag FLAG_SAILED_FROM_SLATEPORT
# 522 "data/scripts/flying_taxi.pory"
	msgbox LilycoveCity_Harbor_EventScript_Ferry_Location_Select_Text_0, MSGBOX_DEFAULT
# 523 "data/scripts/flying_taxi.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_Ferry_Location_Select_2
# 533 "data/scripts/flying_taxi.pory"
	scrollingmultichoice SCROLLING_SLATEPORT_HARBOR_AFTER_LEAGUE_OPTIONS, 0, 0, 4, TRUE
# 534 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_WarpUsingFerry
SlateportCity_Harbor_EventScript_Ferry_Location_Select_1:
# 536 "data/scripts/flying_taxi.pory"
	waitstate
# 537 "data/scripts/flying_taxi.pory"
	release
	end

SlateportCity_Harbor_EventScript_Ferry_Location_Select_2:
# 524 "data/scripts/flying_taxi.pory"
	scrollingmultichoice SCROLLING_SLATEPORT_HARBOR_BEFORE_LEAGUE_OPTIONS, 0, 0, 4, TRUE
# 525 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, 9
	goto_if_lt SlateportCity_Harbor_EventScript_Ferry_Location_Select_5
# 529 "data/scripts/flying_taxi.pory"
	goto LilycoveCity_Harbor_EventScript_ExitSailSelect
	goto SlateportCity_Harbor_EventScript_Ferry_Location_Select_1

SlateportCity_Harbor_EventScript_Ferry_Location_Select_5:
# 526 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_WarpUsingFerry
	goto SlateportCity_Harbor_EventScript_Ferry_Location_Select_1


Common_EventScript_Ferry_Location_Exit::
# 542 "data/scripts/flying_taxi.pory"
	clearflag FLAG_SAILED_FROM_SLATEPORT
# 543 "data/scripts/flying_taxi.pory"
	release
	end


Common_Evenscript_WarpUsingFerry::
# 548 "data/scripts/flying_taxi.pory"
	switch VAR_RESULT
# 549 "data/scripts/flying_taxi.pory"
	case 0, Common_Evenscript_WarpUsingFerry_3
# 571 "data/scripts/flying_taxi.pory"
	case 1, Common_Evenscript_WarpUsingFerry_4
# 582 "data/scripts/flying_taxi.pory"
	case 2, Common_Evenscript_WarpUsingFerry_5
# 593 "data/scripts/flying_taxi.pory"
	case 3, Common_Evenscript_WarpUsingFerry_6
# 604 "data/scripts/flying_taxi.pory"
	case 4, Common_Evenscript_WarpUsingFerry_7
# 615 "data/scripts/flying_taxi.pory"
	case 5, Common_Evenscript_WarpUsingFerry_8
# 626 "data/scripts/flying_taxi.pory"
	case 6, Common_Evenscript_WarpUsingFerry_9
# 637 "data/scripts/flying_taxi.pory"
	case 7, Common_Evenscript_WarpUsingFerry_10
# 648 "data/scripts/flying_taxi.pory"
	case 8, Common_Evenscript_WarpUsingFerry_11
# 659 "data/scripts/flying_taxi.pory"
	case 9, Common_Evenscript_WarpUsingFerry_12
# 669 "data/scripts/flying_taxi.pory"
	case 10, Common_Evenscript_WarpUsingFerry_13
# 680 "data/scripts/flying_taxi.pory"
	case 11, Common_Evenscript_WarpUsingFerry_14
# 691 "data/scripts/flying_taxi.pory"
	case 12, Common_Evenscript_WarpUsingFerry_15
# 702 "data/scripts/flying_taxi.pory"
	case 13, Common_Evenscript_WarpUsingFerry_16
# 714 "data/scripts/flying_taxi.pory"
	case MULTI_B_PRESSED, Common_Evenscript_WarpUsingFerry_17
Common_Evenscript_WarpUsingFerry_17:
# 715 "data/scripts/flying_taxi.pory"
	goto LilycoveCity_Harbor_EventScript_ExitSailSelect
Common_Evenscript_WarpUsingFerry_1:
# 718 "data/scripts/flying_taxi.pory"
	waitstate
# 719 "data/scripts/flying_taxi.pory"
	release
	end

Common_Evenscript_WarpUsingFerry_3:
# 550 "data/scripts/flying_taxi.pory"
	goto_if_unset FLAG_SAILED_FROM_SLATEPORT, Common_Evenscript_WarpUsingFerry_19
# 561 "data/scripts/flying_taxi.pory"
	goto_if_set FLAG_VISITED_LILYCOVE_CITY, Common_Evenscript_WarpUsingFerry_77
# 566 "data/scripts/flying_taxi.pory"
	msgbox Common_Evenscript_WarpUsingFerry_Text_1, MSGBOX_DEFAULT
# 567 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Ferry_Location_Exit
Common_Evenscript_WarpUsingFerry_18:
	goto Common_Evenscript_WarpUsingFerry_1

Common_Evenscript_WarpUsingFerry_4:
# 572 "data/scripts/flying_taxi.pory"
	checkitem ITEM_SEVII_TICKET_1, 1
# 573 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Common_Evenscript_WarpUsingFerry_23
# 579 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_CantSailThereWithoutATicket
Common_Evenscript_WarpUsingFerry_22:
	goto Common_Evenscript_WarpUsingFerry_1

Common_Evenscript_WarpUsingFerry_5:
# 583 "data/scripts/flying_taxi.pory"
	checkitem ITEM_SEVII_TICKET_2, 1
# 584 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Common_Evenscript_WarpUsingFerry_27
# 590 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_CantSailThereWithoutATicket
Common_Evenscript_WarpUsingFerry_26:
	goto Common_Evenscript_WarpUsingFerry_1

Common_Evenscript_WarpUsingFerry_6:
# 594 "data/scripts/flying_taxi.pory"
	checkitem ITEM_SEVII_TICKET_3, 1
# 595 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Common_Evenscript_WarpUsingFerry_31
# 601 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_CantSailThereWithoutATicket
Common_Evenscript_WarpUsingFerry_30:
	goto Common_Evenscript_WarpUsingFerry_1

Common_Evenscript_WarpUsingFerry_7:
# 605 "data/scripts/flying_taxi.pory"
	checkitem ITEM_SEVII_TICKET_4, 1
# 606 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Common_Evenscript_WarpUsingFerry_35
# 612 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_CantSailThereWithoutATicket
Common_Evenscript_WarpUsingFerry_34:
	goto Common_Evenscript_WarpUsingFerry_1

Common_Evenscript_WarpUsingFerry_8:
# 616 "data/scripts/flying_taxi.pory"
	checkitem ITEM_SEVII_TICKET_5, 1
# 617 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Common_Evenscript_WarpUsingFerry_39
# 623 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_CantSailThereWithoutATicket
Common_Evenscript_WarpUsingFerry_38:
	goto Common_Evenscript_WarpUsingFerry_1

Common_Evenscript_WarpUsingFerry_9:
# 627 "data/scripts/flying_taxi.pory"
	checkitem ITEM_SEVII_TICKET_6, 1
# 628 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Common_Evenscript_WarpUsingFerry_43
# 634 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_CantSailThereWithoutATicket
Common_Evenscript_WarpUsingFerry_42:
	goto Common_Evenscript_WarpUsingFerry_1

Common_Evenscript_WarpUsingFerry_10:
# 638 "data/scripts/flying_taxi.pory"
	checkitem ITEM_SEVII_TICKET_7, 1
# 639 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Common_Evenscript_WarpUsingFerry_47
# 645 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_CantSailThereWithoutATicket
Common_Evenscript_WarpUsingFerry_46:
	goto Common_Evenscript_WarpUsingFerry_1

Common_Evenscript_WarpUsingFerry_11:
# 649 "data/scripts/flying_taxi.pory"
	checkitem ITEM_SEVII_TICKET_8, 1
# 650 "data/scripts/flying_taxi.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Common_Evenscript_WarpUsingFerry_51
# 656 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_CantSailThereWithoutATicket
Common_Evenscript_WarpUsingFerry_50:
	goto Common_Evenscript_WarpUsingFerry_1

Common_Evenscript_WarpUsingFerry_12:
# 661 "data/scripts/flying_taxi.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Common_Evenscript_WarpUsingFerry_55
# 666 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_CantSailThereWithoutATicket
Common_Evenscript_WarpUsingFerry_54:
	goto Common_Evenscript_WarpUsingFerry_1

Common_Evenscript_WarpUsingFerry_13:
# 672 "data/scripts/flying_taxi.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Common_Evenscript_WarpUsingFerry_59
# 677 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_CantSailThereWithoutATicket
Common_Evenscript_WarpUsingFerry_58:
	goto Common_Evenscript_WarpUsingFerry_1

Common_Evenscript_WarpUsingFerry_14:
# 683 "data/scripts/flying_taxi.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Common_Evenscript_WarpUsingFerry_63
# 688 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_CantSailThereWithoutATicket
Common_Evenscript_WarpUsingFerry_62:
	goto Common_Evenscript_WarpUsingFerry_1

Common_Evenscript_WarpUsingFerry_15:
# 694 "data/scripts/flying_taxi.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Common_Evenscript_WarpUsingFerry_67
# 699 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_CantSailThereWithoutATicket
Common_Evenscript_WarpUsingFerry_66:
	goto Common_Evenscript_WarpUsingFerry_1

Common_Evenscript_WarpUsingFerry_16:
# 705 "data/scripts/flying_taxi.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, Common_Evenscript_WarpUsingFerry_71
# 710 "data/scripts/flying_taxi.pory"
	goto Common_Evenscript_CantSailThereWithoutATicket
Common_Evenscript_WarpUsingFerry_70:
	goto Common_Evenscript_WarpUsingFerry_1

Common_Evenscript_WarpUsingFerry_19:
# 551 "data/scripts/flying_taxi.pory"
	goto_if_set FLAG_VISITED_SLATEPORT_CITY, Common_Evenscript_WarpUsingFerry_74
# 556 "data/scripts/flying_taxi.pory"
	msgbox Common_Evenscript_WarpUsingFerry_Text_0, MSGBOX_DEFAULT
# 557 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Ferry_Location_Exit
	goto Common_Evenscript_WarpUsingFerry_18

Common_Evenscript_WarpUsingFerry_23:
# 574 "data/scripts/flying_taxi.pory"
	setrespawn HEAL_LOCATION_ONE_ISLAND
# 575 "data/scripts/flying_taxi.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 576 "data/scripts/flying_taxi.pory"
	warp MAP_ONE_ISLAND, 255, 28, 17
	goto Common_Evenscript_WarpUsingFerry_22

Common_Evenscript_WarpUsingFerry_27:
# 585 "data/scripts/flying_taxi.pory"
	setrespawn HEAL_LOCATION_TWO_ISLAND
# 586 "data/scripts/flying_taxi.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 587 "data/scripts/flying_taxi.pory"
	warp MAP_TWO_ISLAND, 255, 10, 7
	goto Common_Evenscript_WarpUsingFerry_26

Common_Evenscript_WarpUsingFerry_31:
# 596 "data/scripts/flying_taxi.pory"
	setrespawn HEAL_LOCATION_THREE_ISLAND
# 597 "data/scripts/flying_taxi.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 598 "data/scripts/flying_taxi.pory"
	warp MAP_THREE_ISLAND_PORT, 255, 12, 12
	goto Common_Evenscript_WarpUsingFerry_30

Common_Evenscript_WarpUsingFerry_35:
# 607 "data/scripts/flying_taxi.pory"
	setrespawn HEAL_LOCATION_FOUR_ISLAND
# 608 "data/scripts/flying_taxi.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 609 "data/scripts/flying_taxi.pory"
	warp MAP_FOUR_ISLAND, 255, 10, 27
	goto Common_Evenscript_WarpUsingFerry_34

Common_Evenscript_WarpUsingFerry_39:
# 618 "data/scripts/flying_taxi.pory"
	setrespawn HEAL_LOCATION_FIVE_ISLAND
# 619 "data/scripts/flying_taxi.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 620 "data/scripts/flying_taxi.pory"
	warp MAP_FIVE_ISLAND, 255, 23, 23
	goto Common_Evenscript_WarpUsingFerry_38

Common_Evenscript_WarpUsingFerry_43:
# 629 "data/scripts/flying_taxi.pory"
	setrespawn HEAL_LOCATION_SIX_ISLAND
# 630 "data/scripts/flying_taxi.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 631 "data/scripts/flying_taxi.pory"
	warp MAP_SIX_ISLAND, 255, 27, 22
	goto Common_Evenscript_WarpUsingFerry_42

Common_Evenscript_WarpUsingFerry_47:
# 640 "data/scripts/flying_taxi.pory"
	setrespawn HEAL_LOCATION_SEVEN_ISLAND
# 641 "data/scripts/flying_taxi.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 642 "data/scripts/flying_taxi.pory"
	warp MAP_SEVEN_ISLAND, 255, 19, 12
	goto Common_Evenscript_WarpUsingFerry_46

Common_Evenscript_WarpUsingFerry_51:
# 651 "data/scripts/flying_taxi.pory"
	setrespawn HEAL_LOCATION_EIGHT_ISLAND
# 652 "data/scripts/flying_taxi.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 653 "data/scripts/flying_taxi.pory"
	warp MAP_EIGHT_ISLAND, 255, 20, 33
	goto Common_Evenscript_WarpUsingFerry_50

Common_Evenscript_WarpUsingFerry_55:
# 662 "data/scripts/flying_taxi.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 663 "data/scripts/flying_taxi.pory"
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 255, 19, 67
	goto Common_Evenscript_WarpUsingFerry_54

Common_Evenscript_WarpUsingFerry_59:
# 673 "data/scripts/flying_taxi.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 674 "data/scripts/flying_taxi.pory"
	warp MAP_NAVEL_ROCK_HARBOR, 255, 8, 4
	goto Common_Evenscript_WarpUsingFerry_58

Common_Evenscript_WarpUsingFerry_63:
# 684 "data/scripts/flying_taxi.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 685 "data/scripts/flying_taxi.pory"
	warp MAP_BIRTH_ISLAND_HARBOR, 255, 8, 4
	goto Common_Evenscript_WarpUsingFerry_62

Common_Evenscript_WarpUsingFerry_67:
# 695 "data/scripts/flying_taxi.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 696 "data/scripts/flying_taxi.pory"
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 255, 13, 38
	goto Common_Evenscript_WarpUsingFerry_66

Common_Evenscript_WarpUsingFerry_71:
# 706 "data/scripts/flying_taxi.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 707 "data/scripts/flying_taxi.pory"
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 255, 13, 22
	goto Common_Evenscript_WarpUsingFerry_70

Common_Evenscript_WarpUsingFerry_74:
# 552 "data/scripts/flying_taxi.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 553 "data/scripts/flying_taxi.pory"
	warp MAP_SLATEPORT_CITY_HARBOR, 255, 8, 11
	goto Common_Evenscript_WarpUsingFerry_18

Common_Evenscript_WarpUsingFerry_77:
# 562 "data/scripts/flying_taxi.pory"
	call LilycoveCity_Harbor_EventScript_BoardFerry
# 563 "data/scripts/flying_taxi.pory"
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
	goto Common_Evenscript_WarpUsingFerry_18


Common_Evenscript_CantSailThereWithoutATicket::
# 724 "data/scripts/flying_taxi.pory"
	msgbox Common_Evenscript_CantSailThereWithoutATicket_Text_0, MSGBOX_DEFAULT
# 725 "data/scripts/flying_taxi.pory"
	release
	end


LilycoveCity_Harbor_EventScript_BoardFerry::
# 730 "data/scripts/flying_taxi.pory"
	msgbox LilycoveCity_Harbor_Text_PleaseBoard, MSGBOX_DEFAULT
# 731 "data/scripts/flying_taxi.pory"
	closemessage
# 732 "data/scripts/flying_taxi.pory"
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFastestUp
# 733 "data/scripts/flying_taxi.pory"
	waitmovement 0
# 734 "data/scripts/flying_taxi.pory"
	delay 30
# 735 "data/scripts/flying_taxi.pory"
	hideobjectat LOCALID_ATTENDANT, MAP_LILYCOVE_CITY_HARBOR
# 736 "data/scripts/flying_taxi.pory"
	hideobjectat LOCALID_ATTENDANT, MAP_SLATEPORT_CITY_HARBOR
# 737 "data/scripts/flying_taxi.pory"
	special HideFollower
# 738 "data/scripts/flying_taxi.pory"
	compare VAR_FACING, DIR_NORTH
# 739 "data/scripts/flying_taxi.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth
# 740 "data/scripts/flying_taxi.pory"
	compare VAR_FACING, DIR_EAST
# 741 "data/scripts/flying_taxi.pory"
	call_if_eq LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast
# 742 "data/scripts/flying_taxi.pory"
	delay 30
# 743 "data/scripts/flying_taxi.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 744 "data/scripts/flying_taxi.pory"
	setvar VAR_0x8004, LOCALID_SS_TIDAL
# 745 "data/scripts/flying_taxi.pory"
	call Common_EventScript_FerryDepart
	return


Common_EventScript_FlyingTaxi_Text_0:
# 9 "data/scripts/flying_taxi.pory"
	.string "Do you want to Fly with us, its only 2BP?$"

Common_EventScript_FlyingTaxi_Text_1:
# 12 "data/scripts/flying_taxi.pory"
	.string "Do you want to Fly with us?, its\n"
	.string "completely free.$"

Common_EventScript_FlyingTaxi_Text_2:
# 22 "data/scripts/flying_taxi.pory"
	.string "But it seems you can't afford using the\n"
	.string "flying taxis right now.\p"
	.string "Please come back when you have atleast\n"
	.string "2BP.$"

LilycoveCity_Harbor_EventScript_FerryAttendant_Text_0:
# 75 "data/scripts/flying_taxi.pory"
	.string "Hello, are you here for the ferry?, May I\n"
	.string "see your Tickets?$"

LilycoveCity_Harbor_EventScript_Ferry_Location_Select_Text_0:
# 84 "data/scripts/flying_taxi.pory"
	.string "Where would you like to go?$"

Common_EventScript_Colress_First_Encounter_Text_0:
# 183 "data/scripts/flying_taxi.pory"
	.string "Oh, excuse me! I am a scientist. My name\n"
	.string "is Colress. My research focuses on\l"
	.string "regional variations between species.\l"
	.string "For example, Vulpix from Kanto has\l"
	.string "developed differently compared to\l"
	.string "those found in Alola. It seems a similar\l"
	.string "phenomenon is occurring here in the\l"
	.string "Sevii Islands.$"

Common_EventScript_Colress_First_Encounter_Text_1:
# 184 "data/scripts/flying_taxi.pory"
	.string "Thats why I came to these islands, to\n"
	.string "uncover the reasons behind why this\l"
	.string "happens.$"

Common_EventScript_Colress_First_Encounter_Text_2:
# 185 "data/scripts/flying_taxi.pory"
	.string "Now that I think of it, I never asked\n"
	.string "your name...$"

Common_EventScript_Colress_First_Encounter_Text_3:
# 186 "data/scripts/flying_taxi.pory"
	.string "{PLAYER}, is it? I'll remember your name.\n"
	.string "To commemorate our encounter, I will let\l"
	.string "you decide which Sevii Island I should\l"
	.string "visit next!$"

Common_EventScript_Colress_Second_Encounter_Text_0:
# 191 "data/scripts/flying_taxi.pory"
	.string "Oh {PLAYER}, I was just finishing\n"
	.string "organizing the data that I found here,\l"
	.string "but I'm already excited on what I will\l"
	.string "find next so help me decide what Sevii\l"
	.string "Island I should visit next!$"

Common_EventScript_Colress_Final_Encounter_Text_0:
# 196 "data/scripts/flying_taxi.pory"
	.string "{PLAYER} this is so exciting! I finally\n"
	.string "completed my research here. The\l"
	.string "regional variations occur because of\l"
	.string "the unique environments you helped me\l"
	.string "explore. As a token of appreciation for\l"
	.string "your hard work, I have some prizes for\l"
	.string "you!!$"

Common_EventScript_Colress_Final_Encounter_Text_1:
# 201 "data/scripts/flying_taxi.pory"
	.string "Do you know of the Pokémon called\n"
	.string "Genesect?$"

Common_EventScript_Colress_Final_Encounter_Text_2:
# 203 "data/scripts/flying_taxi.pory"
	.string "Then allow me to inform you!$"

Common_EventScript_Colress_Final_Encounter_Text_3:
# 206 "data/scripts/flying_taxi.pory"
	.string "Then I have no choice but to admit that\n"
	.string "you are all I would expect you to be!$"

Common_EventScript_Colress_Final_Encounter_Text_4:
# 208 "data/scripts/flying_taxi.pory"
	.string "Genesect is a Pokémon that lived 300\n"
	.string "million years ago. Then an organization\l"
	.string "called Team Plasma modified it,\l"
	.string "attaching a cannon to its back.$"

Common_EventScript_Colress_Final_Encounter_Text_5:
# 209 "data/scripts/flying_taxi.pory"
	.string "The cannon's abilities could be\n"
	.string "activated using certain drives created\l"
	.string "by the scientists in the P2 Laboratory.\l"
	.string "I think that you might be able to use\l"
	.string "them as they should be used.$"

Common_EventScript_Colress_Final_Encounter_Text_6:
# 210 "data/scripts/flying_taxi.pory"
	.string "Simply believing in your Pokémon will\n"
	.string "not guarantee that you can do\l"
	.string "everything you want. But there are many\l"
	.string "things that are guaranteed to fail if\l"
	.string "you do not believe in them. It is the\l"
	.string "trust between a Trainer and a Pokémon\l"
	.string "alone that can overcome those hurdles!$"

Common_EventScript_Colress_Final_Encounter_Text_7:
# 211 "data/scripts/flying_taxi.pory"
	.string "My next quest will be looking for\n"
	.string "Genesect, I hope our paths cross again,\l"
	.string "thanks for everything!$"

Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_0:
# 224 "data/scripts/flying_taxi.pory"
	.string "One Island huh? I think there is a giant\n"
	.string "volcano there, it could lead to some\l"
	.string "interesting information for my\l"
	.string "research, so let's see each other over\l"
	.string "there!$"

Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_1:
# 229 "data/scripts/flying_taxi.pory"
	.string "That's right, you will help me with my\n"
	.string "research since you seem like an\l"
	.string "interesting Trainer.$"

Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_2:
# 234 "data/scripts/flying_taxi.pory"
	.string "But we are already there, take this more\n"
	.string "seriously!$"

Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_3:
# 235 "data/scripts/flying_taxi.pory"
	.string "{PLAYER} what Sevii Island I should\n"
	.string "visit next?$"

Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_4:
# 239 "data/scripts/flying_taxi.pory"
	.string "But we already visited that Island,\n"
	.string "take this more seriously!$"

Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_5:
# 249 "data/scripts/flying_taxi.pory"
	.string "Two Island huh? I think there is a\n"
	.string "swamp route there, it could lead to some\l"
	.string "interesting information for my\l"
	.string "research, so let's see each other over\l"
	.string "there!$"

Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_6:
# 274 "data/scripts/flying_taxi.pory"
	.string "Three Island huh? I think there is a\n"
	.string "Forest full of berries there, it could\l"
	.string "lead to some interesting information\l"
	.string "for my research, so let's see each other\l"
	.string "over there!$"

Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_7:
# 299 "data/scripts/flying_taxi.pory"
	.string "Four Island huh? I think there is a\n"
	.string "really cold cave in there, it could lead\l"
	.string "to some interesting information for my\l"
	.string "research, so let's see each other over\l"
	.string "there!$"

Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_8:
# 324 "data/scripts/flying_taxi.pory"
	.string "Five Island huh? I think there is a\n"
	.string "Water Labrynth in there, it could lead\l"
	.string "to some interesting information for my\l"
	.string "research, so let's see each other over\l"
	.string "there!$"

Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_9:
# 349 "data/scripts/flying_taxi.pory"
	.string "Six Island huh? I think there are some\n"
	.string "Ruins in there, it could lead to some\l"
	.string "interesting information for my\l"
	.string "research, so let's see each other over\l"
	.string "there!$"

Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_10:
# 374 "data/scripts/flying_taxi.pory"
	.string "Seven Island huh? I think there is a\n"
	.string "Canyon in there, it could lead to some\l"
	.string "interesting information for my\l"
	.string "research, so let's see each other over\l"
	.string "there!$"

Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_11:
# 399 "data/scripts/flying_taxi.pory"
	.string "Eight Island?, first time I heard of\n"
	.string "such Island, let me search for\l"
	.string "information on it...$"

Common_EventScript_Colress_First_Encounter_ChooseIsland_Text_12:
# 401 "data/scripts/flying_taxi.pory"
	.string "I see so that island was recently\n"
	.string "discovered by a famous Dragon Tamer,\l"
	.string "seems like an interesting place, let's\l"
	.string "see each other over there!$"

Common_EventScript_Colress_AskForWarping_Text_0:
# 426 "data/scripts/flying_taxi.pory"
	.string "I'm on my way back to that Island do you\n"
	.string "want to go there with me?$"

Common_EventScript_Colress_NoWarp_Text_0:
# 469 "data/scripts/flying_taxi.pory"
	.string "Well then, {PLAYER}, I hope to see you\n"
	.string "again in there.$"

Common_EventScript_Colress_WarpToSevii_Text_0:
# 477 "data/scripts/flying_taxi.pory"
	.string "Splendid! Let's get out of here!$"

Common_Evenscript_WarpUsingFerry_Text_0:
# 556 "data/scripts/flying_taxi.pory"
	.string "I'm terribly sorry, there seems to be a\n"
	.string "problem visiting Slateport right now,\l"
	.string "maybe visiting it yourself could help.$"

Common_Evenscript_WarpUsingFerry_Text_1:
# 566 "data/scripts/flying_taxi.pory"
	.string "I'm terribly sorry, there seems to be a\n"
	.string "problem visiting Lilycove right now,\l"
	.string "maybe visiting it yourself could help.$"

Common_Evenscript_CantSailThereWithoutATicket_Text_0:
# 724 "data/scripts/flying_taxi.pory"
	.string "{PLAYER} doesn't have the Ticket to\n"
	.string "this location…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have that Ticket to board the\n"
	.string "ferry.$"
