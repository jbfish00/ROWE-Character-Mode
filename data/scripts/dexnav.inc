EventScript_StartDexNavBattle::
# 2 "data/scripts/dexnav.pory"
	lock
# 3 "data/scripts/dexnav.pory"
	playse 0x15
# 4 "data/scripts/dexnav.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 5 "data/scripts/dexnav.pory"
	waitmovement 0
# 6 "data/scripts/dexnav.pory"
	waitse
# 7 "data/scripts/dexnav.pory"
	dowildbattle
# 8 "data/scripts/dexnav.pory"
	release
	return


EventScript_NotFoundNearby::
# 12 "data/scripts/dexnav.pory"
	msgbox sText_NotFoundNearby, MSGBOX_SIGN
	return


EventScript_MovedTooFast::
# 21 "data/scripts/dexnav.pory"
	msgbox sText_TryMovingSlower, MSGBOX_SIGN
	return


EventScript_PokemonGotAway::
# 30 "data/scripts/dexnav.pory"
	msgbox sText_PokemonGotAway, MSGBOX_SIGN
	return


EventScript_LostSignal::
# 38 "data/scripts/dexnav.pory"
	msgbox sText_LostSignal, MSGBOX_SIGN
	return


EventScript_TooDark::
# 47 "data/scripts/dexnav.pory"
	msgbox sText_TooDark, MSGBOX_SIGN
	return


sText_NotFoundNearby::
# 15 "data/scripts/dexnav.pory"
	.string "It couldn't be found nearby.\n"
	.string "Try looking in a different area!$"

sText_TryMovingSlower::
# 24 "data/scripts/dexnav.pory"
	.string "The Pokémon got away! Try moving\n"
	.string "more slowly by holding the A button.$"

sText_PokemonGotAway::
# 33 "data/scripts/dexnav.pory"
	.string "The Pokémon got away!$"

sText_LostSignal::
# 41 "data/scripts/dexnav.pory"
	.string "There is no reaction.\n"
	.string "The signal was lost!$"

sText_TooDark::
# 50 "data/scripts/dexnav.pory"
	.string "It's too dark to search\nfor a Pokémon!$"
