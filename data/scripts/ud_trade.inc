UDTrade_EventScript_OpenDimensionList::
# 2 "data/scripts/ud_trade.pory"
	lockall
# 3 "data/scripts/ud_trade.pory"
	faceplayer
# 4 "data/scripts/ud_trade.pory"
	message UDTrade_Text_WhichDimension
# 5 "data/scripts/ud_trade.pory"
	waitmessage
# 6 "data/scripts/ud_trade.pory"
	delay 28
# 7 "data/scripts/ud_trade.pory"
	special OpenUDTradeMenu
# 8 "data/scripts/ud_trade.pory"
	waitstate
	return


UDTrade_EventScript_SpeciesNotAllowed::
# 12 "data/scripts/ud_trade.pory"
	msgbox UDTrade_Text_SpeciesNotAllowed
# 13 "data/scripts/ud_trade.pory"
	goto UDTrade_EventScript_OpenDimensionList
	return


UDTrade_EventScript_ItemNotAllowed::
# 17 "data/scripts/ud_trade.pory"
	msgbox UDTrade_Text_ItemNotAllowed
# 18 "data/scripts/ud_trade.pory"
	goto UDTrade_EventScript_OpenDimensionList
	return


UDTrade_EventScript_MoveNotAllowed::
# 22 "data/scripts/ud_trade.pory"
	msgbox UDTrade_Text_MoveNotAllowed
# 23 "data/scripts/ud_trade.pory"
	goto UDTrade_EventScript_OpenDimensionList
	return


UDTrade_EventScript_on_Mantainance::
# 27 "data/scripts/ud_trade.pory"
	msgbox UDTrade_Text_on_Mantainance
# 28 "data/scripts/ud_trade.pory"
	goto UDTrade_EventScript_OpenDimensionList
	return


UDTrade_EventScript_Mode_Not_Allowed_To_Trade::
# 32 "data/scripts/ud_trade.pory"
	msgbox UDTrade_Text_Mode_Not_Allowed_To_Trade
# 33 "data/scripts/ud_trade.pory"
	goto UDTrade_EventScript_OpenDimensionList
	return


UDTrade_Text_WhichDimension::
# 36 "data/scripts/ud_trade.pory"
	.string "With which Ultra Dimension do you\n"
	.string "wish to link with?$"

UDTrade_Text_on_Mantainance::
# 41 "data/scripts/ud_trade.pory"
	.string "I'm sorry, but {STR_VAR_1} is not\n"
	.string "working at the moment.$"

UDTrade_Text_SpeciesNotAllowed::
# 46 "data/scripts/ud_trade.pory"
	.string "I'm sorry, but {STR_VAR_1} is not\n"
	.string "allowed in the {STR_VAR_2}.$"

UDTrade_Text_ItemNotAllowed::
# 51 "data/scripts/ud_trade.pory"
	.string "I'm sorry, but {STR_VAR_1} can't carry\n"
	.string "a Held Item into the {STR_VAR_2}.$"

UDTrade_Text_Mode_Not_Allowed_To_Trade::
# 56 "data/scripts/ud_trade.pory"
	.string "I'm sorry, but you can't trade\n"
	.string "with the modes you have enabled.$"

UDTrade_Text_MoveNotAllowed::
# 61 "data/scripts/ud_trade.pory"
	.string "I'm sorry, but {STR_VAR_1} can't go\n"
	.string "into the {STR_VAR_2} while\l"
	.string "knowing the move {STR_VAR_3}.$"
