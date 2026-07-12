# 1 "data/scripts/repel.pory"

# 2 "data/scripts/repel.pory"
EventScript_RepelWoreOff::
# 3 "data/scripts/repel.pory"
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
# 4 "data/scripts/repel.pory"
	checkitem ITEM_REPEL, 1
# 5 "data/scripts/repel.pory"
	compare VAR_RESULT, TRUE
# 6 "data/scripts/repel.pory"
	goto_if_eq EventScript_RepelWoreOff_AskAnother
# 7 "data/scripts/repel.pory"
	checkitem ITEM_SUPER_REPEL, 1
# 8 "data/scripts/repel.pory"
	compare VAR_RESULT, TRUE
# 9 "data/scripts/repel.pory"
	goto_if_eq EventScript_RepelWoreOff_AskAnother
# 10 "data/scripts/repel.pory"
	checkitem ITEM_MAX_REPEL, 1
# 11 "data/scripts/repel.pory"
	compare VAR_RESULT, FALSE
# 12 "data/scripts/repel.pory"
	goto_if_eq EventScript_RepelWoreOff_End
# 13 "data/scripts/repel.pory"
EventScript_RepelWoreOff_AskAnother:
# 14 "data/scripts/repel.pory"
	msgbox Text_RepelAskAnother, MSGBOX_YESNO
# 15 "data/scripts/repel.pory"
	closemessage
# 16 "data/scripts/repel.pory"
	compare VAR_RESULT, 0
# 17 "data/scripts/repel.pory"
	goto_if_eq EventScript_RepelWoreOff_End
# 18 "data/scripts/repel.pory"
	callnative TryDrawRepelMenu
# 19 "data/scripts/repel.pory"
	compare VAR_RESULT, FALSE
# 20 "data/scripts/repel.pory"
	goto_if_eq EventScript_RepelWoreOff_Chose
# 21 "data/scripts/repel.pory"
	waitstate
# 22 "data/scripts/repel.pory"
	compare VAR_RESULT, 127
# 23 "data/scripts/repel.pory"
	goto_if_eq EventScript_RepelWoreOff_End
# 24 "data/scripts/repel.pory"
EventScript_RepelWoreOff_Chose:
# 25 "data/scripts/repel.pory"
	callnative HandleRepelMenuChoice
# 26 "data/scripts/repel.pory"
	bufferitemname 1, VAR_0x8004
# 27 "data/scripts/repel.pory"
	removeitem VAR_0x8004, 1
# 28 "data/scripts/repel.pory"
	playse SE_REPEL
# 29 "data/scripts/repel.pory"
	msgbox gText_PlayerUsedVar2, MSGBOX_SIGN
# 30 "data/scripts/repel.pory"
EventScript_RepelWoreOff_End:
# 31 "data/scripts/repel.pory"
	end
# 32 "data/scripts/repel.pory"

# 33 "data/scripts/repel.pory"
EventScript_LureWoreOff::
# 34 "data/scripts/repel.pory"
	msgbox Text_LureWoreOff, MSGBOX_SIGN
# 35 "data/scripts/repel.pory"
	checkitem ITEM_LURE, 1
# 36 "data/scripts/repel.pory"
	compare VAR_RESULT, TRUE
# 37 "data/scripts/repel.pory"
	goto_if_eq EventScript_LureWoreOff_AskAnother
# 38 "data/scripts/repel.pory"
	checkitem ITEM_SUPER_LURE, 1
# 39 "data/scripts/repel.pory"
	compare VAR_RESULT, TRUE
# 40 "data/scripts/repel.pory"
	goto_if_eq EventScript_LureWoreOff_AskAnother
# 41 "data/scripts/repel.pory"
	checkitem ITEM_MAX_LURE, 1
# 42 "data/scripts/repel.pory"
	compare VAR_RESULT, FALSE
# 43 "data/scripts/repel.pory"
	goto_if_eq EventScript_LureWoreOff_End
# 44 "data/scripts/repel.pory"
EventScript_LureWoreOff_AskAnother:
# 45 "data/scripts/repel.pory"
	msgbox Text_RepelAskAnother, MSGBOX_YESNO
# 46 "data/scripts/repel.pory"
	closemessage
# 47 "data/scripts/repel.pory"
	compare VAR_RESULT, 0
# 48 "data/scripts/repel.pory"
	goto_if_eq EventScript_LureWoreOff_End
# 49 "data/scripts/repel.pory"
	callnative TryDrawLureMenu
# 50 "data/scripts/repel.pory"
	compare VAR_RESULT, FALSE
# 51 "data/scripts/repel.pory"
	goto_if_eq EventScript_LureWoreOff_Chose
# 52 "data/scripts/repel.pory"
	waitstate
# 53 "data/scripts/repel.pory"
	compare VAR_RESULT, 127
# 54 "data/scripts/repel.pory"
	goto_if_eq EventScript_LureWoreOff_End
# 55 "data/scripts/repel.pory"
EventScript_LureWoreOff_Chose:
# 56 "data/scripts/repel.pory"
	callnative HandleLureMenuChoice
# 57 "data/scripts/repel.pory"
	bufferitemname 1, VAR_0x8004
# 58 "data/scripts/repel.pory"
	removeitem VAR_0x8004, 1
# 59 "data/scripts/repel.pory"
	playse SE_REPEL
# 60 "data/scripts/repel.pory"
	msgbox gText_PlayerUsedVar2, MSGBOX_SIGN
# 61 "data/scripts/repel.pory"
EventScript_LureWoreOff_End:
# 62 "data/scripts/repel.pory"
	end
# 63 "data/scripts/repel.pory"

# 64 "data/scripts/repel.pory"
Text_RepelWoreOff:
# 65 "data/scripts/repel.pory"
	.string "Repel's effect wore off…$"
# 66 "data/scripts/repel.pory"
Text_RepelAskAnother:
# 67 "data/scripts/repel.pory"
	.string "Would you like to use another one?$"
# 68 "data/scripts/repel.pory"
Text_LureWoreOff:
# 69 "data/scripts/repel.pory"
	.string "Lure's effect wore off…$"
