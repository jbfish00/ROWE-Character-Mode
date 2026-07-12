# 1 "data/scripts/hall_of_fame.pory"

# 2 "data/scripts/hall_of_fame.pory"
EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags::
# 3 "data/scripts/hall_of_fame.pory"
	special SetChampionSaveWarp
# 4 "data/scripts/hall_of_fame.pory"
	setflag FLAG_IS_CHAMPION
# 5 "data/scripts/hall_of_fame.pory"
	call EverGrandeCity_HallOfFame_EventScript_ResetDefeatedEventLegendaries
# 6 "data/scripts/hall_of_fame.pory"
	compare VAR_FOSSIL_MANIAC_STATE, 0
# 7 "data/scripts/hall_of_fame.pory"
	call_if_eq EverGrandeCity_HallOfFame_EventScript_SetDesertUnderpassCommentReady
# 8 "data/scripts/hall_of_fame.pory"
	clearflag FLAG_HIDE_LILCOVE_MOTEL_GAME_DESIGNERS
# 9 "data/scripts/hall_of_fame.pory"
	call EverGrandeCity_HallOfFame_EventScript_ResetEliteFour
# 10 "data/scripts/hall_of_fame.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
# 11 "data/scripts/hall_of_fame.pory"
	clearflag FLAG_HIDE_SS_TIDAL_CORRIDOR_MR_BRINEY
# 12 "data/scripts/hall_of_fame.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_INVISIBLE_NINJA_BOY
# 13 "data/scripts/hall_of_fame.pory"
	setvar VAR_STEVENS_HOUSE_STATE, 2
# 14 "data/scripts/hall_of_fame.pory"
	setflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
# 15 "data/scripts/hall_of_fame.pory"
	clearflag FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY
# 16 "data/scripts/hall_of_fame.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
# 17 "data/scripts/hall_of_fame.pory"
	clearflag FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL
# 18 "data/scripts/hall_of_fame.pory"
	setflag FLAG_HIDE_LILYCOVE_CITY_RIVAL
# 19 "data/scripts/hall_of_fame.pory"
	special UpdateTrainerFanClubGameClear
# 20 "data/scripts/hall_of_fame.pory"
	call_if_unset FLAG_RECEIVED_SS_TICKET, EverGrandeCity_HallOfFame_EventScript_ReadyReceiveSSTicketEvent
# 21 "data/scripts/hall_of_fame.pory"
	call_if_unset FLAG_RECEIVED_BELDUM, EverGrandeCity_HallOfFame_EventScript_ShowStevensHouseBeldum
# 22 "data/scripts/hall_of_fame.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 23 "data/scripts/hall_of_fame.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 24 "data/scripts/hall_of_fame.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0
# 25 "data/scripts/hall_of_fame.pory"
	call_if_eq EverGrandeCity_HallOfFame_EventScript_ReadyDexUpgradeEvent
# 26 "data/scripts/hall_of_fame.pory"
	return
# 27 "data/scripts/hall_of_fame.pory"

# 28 "data/scripts/hall_of_fame.pory"
EverGrandeCity_HallOfFame_EventScript_ResetDefeatedEventLegendaries::
# 29 "data/scripts/hall_of_fame.pory"
	clearflag FLAG_DEFEATED_MEW
# 30 "data/scripts/hall_of_fame.pory"
	clearflag FLAG_DEFEATED_LATIAS_OR_LATIOS
# 31 "data/scripts/hall_of_fame.pory"
	clearflag FLAG_DEFEATED_DEOXYS
# 32 "data/scripts/hall_of_fame.pory"
	clearflag FLAG_DEFEATED_LUGIA
# 33 "data/scripts/hall_of_fame.pory"
	clearflag FLAG_DEFEATED_HO_OH
# 34 "data/scripts/hall_of_fame.pory"
	return
# 35 "data/scripts/hall_of_fame.pory"

# 36 "data/scripts/hall_of_fame.pory"
EverGrandeCity_HallOfFame_EventScript_SetDesertUnderpassCommentReady::
# 37 "data/scripts/hall_of_fame.pory"
	setvar VAR_FOSSIL_MANIAC_STATE, 1
# 38 "data/scripts/hall_of_fame.pory"
	return
# 39 "data/scripts/hall_of_fame.pory"

# 40 "data/scripts/hall_of_fame.pory"
EverGrandeCity_HallOfFame_EventScript_ShowStevensHouseBeldum::
# 41 "data/scripts/hall_of_fame.pory"
	clearflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL
# 42 "data/scripts/hall_of_fame.pory"
	return
# 43 "data/scripts/hall_of_fame.pory"

# 44 "data/scripts/hall_of_fame.pory"
EverGrandeCity_HallOfFame_EventScript_ReadyReceiveSSTicketEvent::
# 45 "data/scripts/hall_of_fame.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 3
# 46 "data/scripts/hall_of_fame.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 3
# 47 "data/scripts/hall_of_fame.pory"
	clearflag FLAG_HIDE_PLAYERS_HOUSE_DAD
# 48 "data/scripts/hall_of_fame.pory"
	return
# 49 "data/scripts/hall_of_fame.pory"

# 50 "data/scripts/hall_of_fame.pory"
EverGrandeCity_HallOfFame_EventScript_ReadyDexUpgradeEvent::
# 51 "data/scripts/hall_of_fame.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1
# 52 "data/scripts/hall_of_fame.pory"
	return
