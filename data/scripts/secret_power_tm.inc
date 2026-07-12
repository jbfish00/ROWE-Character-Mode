# 40 "data/scripts/secret_power_tm.pory"

# 41 "data/scripts/secret_power_tm.pory"
Route111_EventScript_SecretPowerMan::
# 42 "data/scripts/secret_power_tm.pory"
	lock
# 43 "data/scripts/secret_power_tm.pory"
	faceplayer
# 44 "data/scripts/secret_power_tm.pory"
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
# 45 "data/scripts/secret_power_tm.pory"
	compare VAR_RESULT, YES
# 46 "data/scripts/secret_power_tm.pory"
	goto_if_eq Route111_EventScript_GiveSecretPower
# 47 "data/scripts/secret_power_tm.pory"
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
# 48 "data/scripts/secret_power_tm.pory"
	release
# 49 "data/scripts/secret_power_tm.pory"
	end
# 50 "data/scripts/secret_power_tm.pory"

# 51 "data/scripts/secret_power_tm.pory"
Route111_EventScript_GiveSecretPower::
# 52 "data/scripts/secret_power_tm.pory"
	giveitem ITEM_TM43
# 53 "data/scripts/secret_power_tm.pory"
	compare VAR_RESULT, FALSE
# 54 "data/scripts/secret_power_tm.pory"
	goto_if_eq Route111_EventScript_NoRoomForSecretPower
# 55 "data/scripts/secret_power_tm.pory"
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
# 56 "data/scripts/secret_power_tm.pory"
	closemessage
# 57 "data/scripts/secret_power_tm.pory"
	setflag FLAG_RECEIVED_SECRET_POWER
# 58 "data/scripts/secret_power_tm.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
# 59 "data/scripts/secret_power_tm.pory"
	compare VAR_FACING, DIR_WEST
# 60 "data/scripts/secret_power_tm.pory"
	call_if_eq Route111_EventScript_SecretPowerManExit
# 61 "data/scripts/secret_power_tm.pory"
	compare VAR_FACING, DIR_EAST
# 62 "data/scripts/secret_power_tm.pory"
	call_if_eq Route111_EventScript_SecretPowerManExit
# 63 "data/scripts/secret_power_tm.pory"
	compare VAR_FACING, DIR_NORTH
# 64 "data/scripts/secret_power_tm.pory"
	call_if_eq Route111_EventScript_SecretPowerManExitNorth
# 65 "data/scripts/secret_power_tm.pory"
	removeobject VAR_LAST_TALKED
# 66 "data/scripts/secret_power_tm.pory"
	release
# 67 "data/scripts/secret_power_tm.pory"
	end
# 68 "data/scripts/secret_power_tm.pory"

# 69 "data/scripts/secret_power_tm.pory"
Route111_EventScript_SecretPowerManExit::
# 70 "data/scripts/secret_power_tm.pory"
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
# 71 "data/scripts/secret_power_tm.pory"
	waitmovement 0
# 72 "data/scripts/secret_power_tm.pory"
	return
# 73 "data/scripts/secret_power_tm.pory"

# 74 "data/scripts/secret_power_tm.pory"
Route111_EventScript_SecretPowerManExitNorth::
# 75 "data/scripts/secret_power_tm.pory"
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
# 76 "data/scripts/secret_power_tm.pory"
	waitmovement 0
# 77 "data/scripts/secret_power_tm.pory"
	return
# 78 "data/scripts/secret_power_tm.pory"

# 79 "data/scripts/secret_power_tm.pory"
Route111_EventScript_NoRoomForSecretPower::
# 80 "data/scripts/secret_power_tm.pory"
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
# 81 "data/scripts/secret_power_tm.pory"
	release
# 82 "data/scripts/secret_power_tm.pory"
	end

# 85 "data/scripts/secret_power_tm.pory"
Route111_Movement_SecretPowerManExit:
# 86 "data/scripts/secret_power_tm.pory"
	walk_down
# 87 "data/scripts/secret_power_tm.pory"
	walk_down
# 88 "data/scripts/secret_power_tm.pory"
	walk_down
# 89 "data/scripts/secret_power_tm.pory"
	walk_down
# 90 "data/scripts/secret_power_tm.pory"
	walk_down
# 91 "data/scripts/secret_power_tm.pory"
	walk_left
# 92 "data/scripts/secret_power_tm.pory"
	walk_left
# 93 "data/scripts/secret_power_tm.pory"
	walk_left
# 94 "data/scripts/secret_power_tm.pory"
	walk_left
# 95 "data/scripts/secret_power_tm.pory"
	walk_down
# 96 "data/scripts/secret_power_tm.pory"
	walk_down
	step_end

# 99 "data/scripts/secret_power_tm.pory"
Route111_Movement_SecretPowerManExitNorth:
# 100 "data/scripts/secret_power_tm.pory"
	walk_left
# 101 "data/scripts/secret_power_tm.pory"
	walk_down
# 102 "data/scripts/secret_power_tm.pory"
	walk_down
# 103 "data/scripts/secret_power_tm.pory"
	walk_down
# 104 "data/scripts/secret_power_tm.pory"
	walk_down
# 105 "data/scripts/secret_power_tm.pory"
	walk_down
# 106 "data/scripts/secret_power_tm.pory"
	walk_left
# 107 "data/scripts/secret_power_tm.pory"
	walk_left
# 108 "data/scripts/secret_power_tm.pory"
	walk_left
# 109 "data/scripts/secret_power_tm.pory"
	walk_down
# 110 "data/scripts/secret_power_tm.pory"
	walk_down
	step_end

Route111_Text_MakingRoomUseTMToMakeYourOwn::
# 1 "data/scripts/secret_power_tm.pory"
	.string "What's that?\n"
	.string "What am I doing?\p"
	.string "I'm thinking about making my own room\n"
	.string "here using a Pokémon move.\p"
	.string "I know! I'll give you this TM.\n"
	.string "Will you use it to make your own room?$"

Route111_Text_ExplainSecretPower::
# 10 "data/scripts/secret_power_tm.pory"
	.string "Find a big tree that looks like it might\n"
	.string "drop some vines.\p"
	.string "Use Secret Power in front of the tree.\n"
	.string "Some vines should get free and drop\l"
	.string "down, so you can climb the tree.\p"
	.string "You'll find a lot of space for putting\n"
	.string "your favorite things.\p"
	.string "It'll be your own secret room…\n"
	.string "A Secret Base!\p"
	.string "You should make one, too.\p"
	.string "Another thing, you don't always have\n"
	.string "to make your Secret Base in a tree.\p"
	.string "Try using Secret Power on rock walls\n"
	.string "that have small indents in them.\p"
	.string "I'm going to look for other places, too.\n"
	.string "Okay, bye!$"

Route111_Text_DontWantThis::
# 29 "data/scripts/secret_power_tm.pory"
	.string "Oh, you don't want this?\n"
	.string "If you change your mind, tell me, okay?$"

Route111_Text_DontHaveAnyRoom::
# 34 "data/scripts/secret_power_tm.pory"
	.string "Oh, you don't have any room for this.\p"
	.string "I'll hold on to it, so come back for it\n"
	.string "another time, okay?$"
