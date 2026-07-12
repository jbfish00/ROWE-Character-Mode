EventScript_PictureBookShelf::
# 2 "data/scripts/check_furniture.pory"
	msgbox Text_PictureBookShelf, MSGBOX_SIGN
	end


EventScript_BookShelf::
# 7 "data/scripts/check_furniture.pory"
	msgbox Text_BookShelf, MSGBOX_SIGN
	end


EventScript_PokemonCenterBookShelf::
# 12 "data/scripts/check_furniture.pory"
	msgbox Text_PokemonCenterBookShelf, MSGBOX_SIGN
	end


EventScript_Vase::
# 17 "data/scripts/check_furniture.pory"
	msgbox Text_Vase, MSGBOX_SIGN
	end


EventScript_EmptyTrashCan::
# 22 "data/scripts/check_furniture.pory"
	msgbox Text_EmptyTrashCan, MSGBOX_SIGN
	end


EventScript_ShopShelf::
# 27 "data/scripts/check_furniture.pory"
	msgbox Text_ShopShelf, MSGBOX_SIGN
	end


EventScript_Blueprint::
# 32 "data/scripts/check_furniture.pory"
	msgbox Text_Blueprint, MSGBOX_SIGN
	end


EventScript_Common_Invert_Time_Bed_Player_House::
# 37 "data/scripts/check_furniture.pory"
	lockall
# 38 "data/scripts/check_furniture.pory"
	goto_if_unset FLAG_DEFEATED_DARKRAI, EventScript_Common_Invert_Time_Bed_Player_House_4
EventScript_Common_Invert_Time_Bed_Player_House_3:
# 46 "data/scripts/check_furniture.pory"
	msgbox EventScript_Common_Invert_Time_Bed_Player_House_Text_2, MSGBOX_DEFAULT
# 47 "data/scripts/check_furniture.pory"
	closemessage
# 48 "data/scripts/check_furniture.pory"
	goto_if_set FLAG_IS_DAYNIGHT_INVERTED, EventScript_Common_Invert_Time_Bed_Player_House_8
# 52 "data/scripts/check_furniture.pory"
	setflag FLAG_IS_DAYNIGHT_INVERTED
EventScript_Common_Invert_Time_Bed_Player_House_7:
# 54 "data/scripts/check_furniture.pory"
	call Common_EventScript_OutOfCenterPartyHeal
EventScript_Common_Invert_Time_Bed_Player_House_1:
# 56 "data/scripts/check_furniture.pory"
	releaseall
	end

EventScript_Common_Invert_Time_Bed_Player_House_2:
# 39 "data/scripts/check_furniture.pory"
	msgbox EventScript_Common_Invert_Time_Bed_Player_House_Text_0, MSGBOX_DEFAULT
# 40 "data/scripts/check_furniture.pory"
	fadescreen FADE_TO_BLACK
# 41 "data/scripts/check_furniture.pory"
	special HealPlayerParty
# 42 "data/scripts/check_furniture.pory"
	msgbox EventScript_Common_Invert_Time_Bed_Player_House_Text_1, MSGBOX_DEFAULT
# 43 "data/scripts/check_furniture.pory"
	call Common_EventScript_Darkrai_Encounter
	goto EventScript_Common_Invert_Time_Bed_Player_House_1

EventScript_Common_Invert_Time_Bed_Player_House_4:
# 38 "data/scripts/check_furniture.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, EventScript_Common_Invert_Time_Bed_Player_House_2
	goto EventScript_Common_Invert_Time_Bed_Player_House_3

EventScript_Common_Invert_Time_Bed_Player_House_8:
# 49 "data/scripts/check_furniture.pory"
	clearflag FLAG_IS_DAYNIGHT_INVERTED
	goto EventScript_Common_Invert_Time_Bed_Player_House_7


EventScript_Common_Invert_Time_Bed_Weather_Institute::
# 61 "data/scripts/check_furniture.pory"
	lockall
# 62 "data/scripts/check_furniture.pory"
	msgbox EventScript_Common_Invert_Time_Bed_Player_House_Text_2, MSGBOX_DEFAULT
# 63 "data/scripts/check_furniture.pory"
	closemessage
# 64 "data/scripts/check_furniture.pory"
	goto_if_set FLAG_IS_DAYNIGHT_INVERTED, EventScript_Common_Invert_Time_Bed_Weather_Institute_2
# 68 "data/scripts/check_furniture.pory"
	setflag FLAG_IS_DAYNIGHT_INVERTED
EventScript_Common_Invert_Time_Bed_Weather_Institute_1:
# 70 "data/scripts/check_furniture.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 71 "data/scripts/check_furniture.pory"
	releaseall
	end

EventScript_Common_Invert_Time_Bed_Weather_Institute_2:
# 65 "data/scripts/check_furniture.pory"
	clearflag FLAG_IS_DAYNIGHT_INVERTED
	goto EventScript_Common_Invert_Time_Bed_Weather_Institute_1


EventScript_Common_Invert_Time_Bed_Player_House_Text_0:
# 39 "data/scripts/check_furniture.pory"
	.string "There's a bed…\n"
	.string "Let's take a rest...$"

EventScript_Common_Invert_Time_Bed_Player_House_Text_1:
# 42 "data/scripts/check_furniture.pory"
	.string "{PLAYER} seems to be having a bad dream!$"

EventScript_Common_Invert_Time_Bed_Player_House_Text_2:
# 46 "data/scripts/check_furniture.pory"
	.string "There's a bed…\n"
	.string "Let's take a rest.$"
