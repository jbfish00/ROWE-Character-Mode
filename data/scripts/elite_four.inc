# 1 "data/scripts/elite_four.pory"

# 2 "data/scripts/elite_four.pory"
PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles::
# 3 "data/scripts/elite_four.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
# 4 "data/scripts/elite_four.pory"
	waitmovement 0
# 5 "data/scripts/elite_four.pory"
	playse SE_DOOR
# 6 "data/scripts/elite_four.pory"
	setmetatile 6, 1, METATILE_EliteFour_OpenDoor_Frame, 0
# 7 "data/scripts/elite_four.pory"
	setmetatile 6, 2, METATILE_EliteFour_OpenDoor_Opening, 0
# 8 "data/scripts/elite_four.pory"
	setmetatile 0, 2, METATILE_EliteFour_RightSpotlightOff, 1
# 9 "data/scripts/elite_four.pory"
	setmetatile 1, 2, METATILE_EliteFour_LeftSpotlightOff, 1
# 10 "data/scripts/elite_four.pory"
	setmetatile 2, 2, METATILE_EliteFour_RightSpotlightOff, 1
# 11 "data/scripts/elite_four.pory"
	setmetatile 3, 2, METATILE_EliteFour_LeftSpotlightOff, 1
# 12 "data/scripts/elite_four.pory"
	setmetatile 4, 2, METATILE_EliteFour_RightSpotlightOff, 1
# 13 "data/scripts/elite_four.pory"
	setmetatile 8, 2, METATILE_EliteFour_LeftSpotlightOff, 1
# 14 "data/scripts/elite_four.pory"
	setmetatile 9, 2, METATILE_EliteFour_RightSpotlightOff, 1
# 15 "data/scripts/elite_four.pory"
	setmetatile 10, 2, METATILE_EliteFour_LeftSpotlightOff, 1
# 16 "data/scripts/elite_four.pory"
	setmetatile 11, 2, METATILE_EliteFour_RightSpotlightOff, 1
# 17 "data/scripts/elite_four.pory"
	setmetatile 12, 2, METATILE_EliteFour_LeftSpotlightOff, 1
# 18 "data/scripts/elite_four.pory"
	special DrawWholeMapView
# 19 "data/scripts/elite_four.pory"
	return
# 20 "data/scripts/elite_four.pory"

# 21 "data/scripts/elite_four.pory"
PokemonLeague_EliteFour_EventScript_WalkInCloseDoor::
# 22 "data/scripts/elite_four.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp6
# 23 "data/scripts/elite_four.pory"
	waitmovement 0
# 24 "data/scripts/elite_four.pory"
	playse SE_TRUCK_DOOR
# 25 "data/scripts/elite_four.pory"
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
# 26 "data/scripts/elite_four.pory"
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
# 27 "data/scripts/elite_four.pory"
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
# 28 "data/scripts/elite_four.pory"
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
# 29 "data/scripts/elite_four.pory"
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
# 30 "data/scripts/elite_four.pory"
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
# 31 "data/scripts/elite_four.pory"
	special DrawWholeMapView
# 32 "data/scripts/elite_four.pory"
	return
# 33 "data/scripts/elite_four.pory"

# 34 "data/scripts/elite_four.pory"
@ Essentially unused, only necessary when re-entering an Elite Four room after defeating the member, which isnt normally possible
# 35 "data/scripts/elite_four.pory"
PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom::
# 36 "data/scripts/elite_four.pory"
	setmetatile 6, 1, METATILE_EliteFour_OpenDoor_Frame, 0
# 37 "data/scripts/elite_four.pory"
	setmetatile 6, 2, METATILE_EliteFour_OpenDoor_Opening, 0
# 38 "data/scripts/elite_four.pory"
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
# 39 "data/scripts/elite_four.pory"
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
# 40 "data/scripts/elite_four.pory"
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
# 41 "data/scripts/elite_four.pory"
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
# 42 "data/scripts/elite_four.pory"
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
# 43 "data/scripts/elite_four.pory"
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
# 44 "data/scripts/elite_four.pory"
	setmetatile 0, 2, METATILE_EliteFour_RightSpotlightOff, 1
# 45 "data/scripts/elite_four.pory"
	setmetatile 1, 2, METATILE_EliteFour_LeftSpotlightOff, 1
# 46 "data/scripts/elite_four.pory"
	setmetatile 2, 2, METATILE_EliteFour_RightSpotlightOff, 1
# 47 "data/scripts/elite_four.pory"
	setmetatile 3, 2, METATILE_EliteFour_LeftSpotlightOff, 1
# 48 "data/scripts/elite_four.pory"
	setmetatile 4, 2, METATILE_EliteFour_RightSpotlightOff, 1
# 49 "data/scripts/elite_four.pory"
	setmetatile 8, 2, METATILE_EliteFour_LeftSpotlightOff, 1
# 50 "data/scripts/elite_four.pory"
	setmetatile 9, 2, METATILE_EliteFour_RightSpotlightOff, 1
# 51 "data/scripts/elite_four.pory"
	setmetatile 10, 2, METATILE_EliteFour_LeftSpotlightOff, 1
# 52 "data/scripts/elite_four.pory"
	setmetatile 11, 2, METATILE_EliteFour_RightSpotlightOff, 1
# 53 "data/scripts/elite_four.pory"
	setmetatile 12, 2, METATILE_EliteFour_LeftSpotlightOff, 1
# 54 "data/scripts/elite_four.pory"
	return
# 55 "data/scripts/elite_four.pory"

# 56 "data/scripts/elite_four.pory"
PokemonLeague_EliteFour_EventScript_CloseDoor::
# 57 "data/scripts/elite_four.pory"
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
# 58 "data/scripts/elite_four.pory"
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
# 59 "data/scripts/elite_four.pory"
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
# 60 "data/scripts/elite_four.pory"
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
# 61 "data/scripts/elite_four.pory"
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
# 62 "data/scripts/elite_four.pory"
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
# 63 "data/scripts/elite_four.pory"
	return
