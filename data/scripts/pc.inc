EventScript_PC::
# 2 "data/scripts/pc.pory"
	lockall
# 3 "data/scripts/pc.pory"
	setvar VAR_0x8004, 0
# 4 "data/scripts/pc.pory"
	goto_if_unset FLAG_OPEN_PC_BOX_FROM_MENU, EventScript_PC_2
EventScript_PC_1:
# 7 "data/scripts/pc.pory"
	playse SE_PC_ON
# 8 "data/scripts/pc.pory"
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
# 9 "data/scripts/pc.pory"
	goto EventScript_PCMainMenu
	end

EventScript_PC_2:
# 5 "data/scripts/pc.pory"
	special DoPCTurnOnEffect
	goto EventScript_PC_1


EventScript_PCMainMenu::
# 14 "data/scripts/pc.pory"
	message gText_WhichPCShouldBeAccessed
# 15 "data/scripts/pc.pory"
	waitmessage
# 16 "data/scripts/pc.pory"
	special ScriptMenu_CreatePCMultichoice
# 17 "data/scripts/pc.pory"
	waitstate
# 18 "data/scripts/pc.pory"
	goto EventScript_AccessPC
	end


EventScript_AccessPC::
# 23 "data/scripts/pc.pory"
	switch VAR_RESULT
# 24 "data/scripts/pc.pory"
	case 0, EventScript_AccessPC_3
# 25 "data/scripts/pc.pory"
	case 1, EventScript_AccessPC_4
# 26 "data/scripts/pc.pory"
	case 2, EventScript_AccessPC_5
# 27 "data/scripts/pc.pory"
	case 3, EventScript_AccessPC_6
# 28 "data/scripts/pc.pory"
	case MULTI_B_PRESSED, EventScript_AccessPC_7
EventScript_AccessPC_1:
	end

EventScript_AccessPC_3:
# 24 "data/scripts/pc.pory"
	goto EventScript_AccessPokemonStorage
	goto EventScript_AccessPC_1

EventScript_AccessPC_4:
# 25 "data/scripts/pc.pory"
	goto EventScript_AccessPlayersPC
	goto EventScript_AccessPC_1

EventScript_AccessPC_5:
# 26 "data/scripts/pc.pory"
	goto EventScript_AccessHallOfFame
	goto EventScript_AccessPC_1

EventScript_AccessPC_6:
# 27 "data/scripts/pc.pory"
	goto EventScript_TurnOffPC
	goto EventScript_AccessPC_1

EventScript_AccessPC_7:
# 28 "data/scripts/pc.pory"
	goto EventScript_TurnOffPC
	goto EventScript_AccessPC_1


EventScript_AccessPlayersPC::
# 34 "data/scripts/pc.pory"
	playse SE_PC_LOGIN
# 35 "data/scripts/pc.pory"
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
# 36 "data/scripts/pc.pory"
	special PlayerPC
# 37 "data/scripts/pc.pory"
	waitstate
# 38 "data/scripts/pc.pory"
	goto EventScript_PCMainMenu
	end


EventScript_AccessPokemonStorage::
# 43 "data/scripts/pc.pory"
	playse SE_PC_LOGIN
# 44 "data/scripts/pc.pory"
	goto_if_set FLAG_SYS_PC_LANETTE, EventScript_AccessPokemonStorage_2
# 47 "data/scripts/pc.pory"
	msgbox gText_AccessedSomeonesPC, MSGBOX_DEFAULT
EventScript_AccessPokemonStorage_1:
# 49 "data/scripts/pc.pory"
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
# 50 "data/scripts/pc.pory"
	special ShowPokemonStorageSystemPC
# 51 "data/scripts/pc.pory"
	waitstate
# 52 "data/scripts/pc.pory"
	goto EventScript_PCMainMenu
	end

EventScript_AccessPokemonStorage_2:
# 45 "data/scripts/pc.pory"
	msgbox gText_AccessedLanettesPC, MSGBOX_DEFAULT
	goto EventScript_AccessPokemonStorage_1


EventScript_TurnOffPC::
# 57 "data/scripts/pc.pory"
	setvar VAR_0x8004, 0
# 58 "data/scripts/pc.pory"
	playse SE_PC_OFF
# 59 "data/scripts/pc.pory"
	goto_if_unset FLAG_OPEN_PC_BOX_FROM_MENU, EventScript_TurnOffPC_2
EventScript_TurnOffPC_1:
# 62 "data/scripts/pc.pory"
	clearflag FLAG_OPEN_PC_BOX_FROM_MENU
# 63 "data/scripts/pc.pory"
	releaseall
	end

EventScript_TurnOffPC_2:
# 60 "data/scripts/pc.pory"
	special DoPCTurnOffEffect
	goto EventScript_TurnOffPC_1


EventScript_AccessHallOfFame::
# 68 "data/scripts/pc.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_AccessHallOfFame_2
EventScript_AccessHallOfFame_1:
# 71 "data/scripts/pc.pory"
	playse SE_PC_LOGIN
# 72 "data/scripts/pc.pory"
	special AccessHallOfFamePC
# 73 "data/scripts/pc.pory"
	waitstate
# 74 "data/scripts/pc.pory"
	goto EventScript_AccessPC
	end

EventScript_AccessHallOfFame_2:
# 69 "data/scripts/pc.pory"
	goto EventScript_TurnOffPC
	goto EventScript_AccessHallOfFame_1

