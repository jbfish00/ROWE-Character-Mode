# 1 "data/scripts/std_msgbox.pory"

# 2 "data/scripts/std_msgbox.pory"
Std_MsgboxNPC:
# 3 "data/scripts/std_msgbox.pory"
	lock
# 4 "data/scripts/std_msgbox.pory"
	faceplayer
# 5 "data/scripts/std_msgbox.pory"
	message 0x0
# 6 "data/scripts/std_msgbox.pory"
	waitmessage
# 7 "data/scripts/std_msgbox.pory"
	waitbuttonpress
# 8 "data/scripts/std_msgbox.pory"
	release
# 9 "data/scripts/std_msgbox.pory"
	return
# 10 "data/scripts/std_msgbox.pory"

# 11 "data/scripts/std_msgbox.pory"
Std_MsgboxSign:
# 12 "data/scripts/std_msgbox.pory"
	lockall
# 13 "data/scripts/std_msgbox.pory"
	message 0x0
# 14 "data/scripts/std_msgbox.pory"
	waitmessage
# 15 "data/scripts/std_msgbox.pory"
	waitbuttonpress
# 16 "data/scripts/std_msgbox.pory"
	releaseall
# 17 "data/scripts/std_msgbox.pory"
	return
# 18 "data/scripts/std_msgbox.pory"

# 19 "data/scripts/std_msgbox.pory"
Std_MsgboxDefault:
# 20 "data/scripts/std_msgbox.pory"
	message 0x0
# 21 "data/scripts/std_msgbox.pory"
	waitmessage
# 22 "data/scripts/std_msgbox.pory"
	waitbuttonpress
# 23 "data/scripts/std_msgbox.pory"
	return
# 24 "data/scripts/std_msgbox.pory"

# 25 "data/scripts/std_msgbox.pory"
Std_MsgboxYesNo:
# 26 "data/scripts/std_msgbox.pory"
	message 0x0
# 27 "data/scripts/std_msgbox.pory"
	waitmessage
# 28 "data/scripts/std_msgbox.pory"
	yesnobox 20, 8
# 29 "data/scripts/std_msgbox.pory"
	return
# 30 "data/scripts/std_msgbox.pory"

# 31 "data/scripts/std_msgbox.pory"
Std_MsgboxGetPoints:
# 32 "data/scripts/std_msgbox.pory"
	message 0x0
# 33 "data/scripts/std_msgbox.pory"
	playfanfare MUS_OBTAIN_B_POINTS
# 34 "data/scripts/std_msgbox.pory"
	waitfanfare
# 35 "data/scripts/std_msgbox.pory"
	waitmessage
# 36 "data/scripts/std_msgbox.pory"
	return
# 37 "data/scripts/std_msgbox.pory"

# 38 "data/scripts/std_msgbox.pory"
Std_10:
# 39 "data/scripts/std_msgbox.pory"
	pokenavcall 0x0
# 40 "data/scripts/std_msgbox.pory"
	waitmessage
# 41 "data/scripts/std_msgbox.pory"
	return
# 42 "data/scripts/std_msgbox.pory"

# 43 "data/scripts/std_msgbox.pory"
EventScript_UnusedReturn:
# 44 "data/scripts/std_msgbox.pory"
	return
# 45 "data/scripts/std_msgbox.pory"

# 46 "data/scripts/std_msgbox.pory"
Common_EventScript_SaveGame::
# 47 "data/scripts/std_msgbox.pory"
	special SaveGame
# 48 "data/scripts/std_msgbox.pory"
	waitstate
# 49 "data/scripts/std_msgbox.pory"
	return
