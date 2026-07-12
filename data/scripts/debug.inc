Debug_ShowFieldMessageStringVar4::
# 2 "data/scripts/debug.pory"
	special ShowFieldMessageStringVar4
# 3 "data/scripts/debug.pory"
	waitmessage
# 4 "data/scripts/debug.pory"
	waitbuttonpress
# 5 "data/scripts/debug.pory"
	releaseall
	end


Debug_CheatStart::
# 10 "data/scripts/debug.pory"
	goto Common_EventScript_Alpha_Starmie
# 11 "data/scripts/debug.pory"
	trainerbattle_single TRAINER_DEBUG_OPPONENT, Debug_CheatStart_Text_0, Debug_CheatStart_Text_1
# 12 "data/scripts/debug.pory"
	msgbox Debug_CheatStart_Text_2, MSGBOX_AUTOCLOSE
	return


Common_EventScript_Refresh_Map::
# 16 "data/scripts/debug.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	end


Debug_CheatStart_Text_0:
# 11 "data/scripts/debug.pory"
	.string "Debug Battle Start!$"

Debug_CheatStart_Text_1:
# 11 "data/scripts/debug.pory"
	.string "Is this for real?$"

Debug_CheatStart_Text_2:
# 12 "data/scripts/debug.pory"
	.string "...$"
