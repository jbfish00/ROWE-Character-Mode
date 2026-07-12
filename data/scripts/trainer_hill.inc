# 1 "data/scripts/trainer_hill.pory"

# 2 "data/scripts/trainer_hill.pory"
TrainerHill_OnResume:
# 3 "data/scripts/trainer_hill.pory"
	setvar VAR_TEMP_2, 0
# 4 "data/scripts/trainer_hill.pory"
	trainerhill_resumetimer
# 5 "data/scripts/trainer_hill.pory"
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
# 6 "data/scripts/trainer_hill.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
# 7 "data/scripts/trainer_hill.pory"
	goto_if_eq TrainerHill_1F_EventScript_Lost
# 8 "data/scripts/trainer_hill.pory"
	compare VAR_RESULT, B_OUTCOME_DREW
# 9 "data/scripts/trainer_hill.pory"
	goto_if_eq TrainerHill_1F_EventScript_Lost
# 10 "data/scripts/trainer_hill.pory"
	compare VAR_RESULT, B_OUTCOME_FORFEITED
# 11 "data/scripts/trainer_hill.pory"
	goto_if_eq TrainerHill_1F_EventScript_Lost
# 12 "data/scripts/trainer_hill.pory"
	end
# 13 "data/scripts/trainer_hill.pory"

# 14 "data/scripts/trainer_hill.pory"
TrainerHill_OnWarp:
# 15 "data/scripts/trainer_hill.pory"
	map_script_2 VAR_TEMP_3, 0, TrainerHill_1F_EventScript_DummyOnWarp
# 16 "data/scripts/trainer_hill.pory"
	.2byte 0
# 17 "data/scripts/trainer_hill.pory"

# 18 "data/scripts/trainer_hill.pory"
TrainerHill_1F_EventScript_DummyOnWarp::
# 19 "data/scripts/trainer_hill.pory"
	setvar VAR_TEMP_3, 1
# 20 "data/scripts/trainer_hill.pory"
@ forced stop
# 21 "data/scripts/trainer_hill.pory"

# 22 "data/scripts/trainer_hill.pory"
TrainerHill_OnFrame:
# 23 "data/scripts/trainer_hill.pory"
	map_script_2 VAR_TEMP_2, 0, TrainerHill_1F_EventScript_DummyWarpToEntranceCounter
# 24 "data/scripts/trainer_hill.pory"
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
# 25 "data/scripts/trainer_hill.pory"
	.2byte 0
# 26 "data/scripts/trainer_hill.pory"

# 27 "data/scripts/trainer_hill.pory"
EventScript_TrainerHillTimer::
# 28 "data/scripts/trainer_hill.pory"
	lockall
# 29 "data/scripts/trainer_hill.pory"
	trainerhill_gettime
# 30 "data/scripts/trainer_hill.pory"
	msgbox TrainerHill_Entrance_Text_ChallengeTime, MSGBOX_DEFAULT
# 31 "data/scripts/trainer_hill.pory"
	releaseall
# 32 "data/scripts/trainer_hill.pory"
	end
# 33 "data/scripts/trainer_hill.pory"

# 34 "data/scripts/trainer_hill.pory"
TrainerHill_1F_EventScript_DummyWarpToEntranceCounter::
# 35 "data/scripts/trainer_hill.pory"
	setvar VAR_TEMP_2, 1
# 36 "data/scripts/trainer_hill.pory"
	trainerhill_getusingereader
# 37 "data/scripts/trainer_hill.pory"
	compare VAR_RESULT, TRUE
# 38 "data/scripts/trainer_hill.pory"
	goto_if_eq TrainerHill_1F_EventScript_WarpSilentToEntranceCounter
# 39 "data/scripts/trainer_hill.pory"
	end
# 40 "data/scripts/trainer_hill.pory"

# 41 "data/scripts/trainer_hill.pory"
@ Never reached
# 42 "data/scripts/trainer_hill.pory"
TrainerHill_1F_EventScript_WarpSilentToEntranceCounter::
# 43 "data/scripts/trainer_hill.pory"
	warpsilent MAP_TRAINER_HILL_ENTRANCE, 255, 9, 6
# 44 "data/scripts/trainer_hill.pory"
	waitstate
# 45 "data/scripts/trainer_hill.pory"
	end
# 46 "data/scripts/trainer_hill.pory"

# 47 "data/scripts/trainer_hill.pory"
TrainerHill_1F_EventScript_Lost::
# 48 "data/scripts/trainer_hill.pory"
	trainerhill_settrainerflags
# 49 "data/scripts/trainer_hill.pory"
	trainerhill_lost
# 50 "data/scripts/trainer_hill.pory"
	setvar VAR_TEMP_1, 1
# 51 "data/scripts/trainer_hill.pory"
	end
# 52 "data/scripts/trainer_hill.pory"

# 53 "data/scripts/trainer_hill.pory"
TrainerHill_EventScript_WarpToEntranceCounter::
# 54 "data/scripts/trainer_hill.pory"
	setvar VAR_TEMP_1, 0
# 55 "data/scripts/trainer_hill.pory"
	warp MAP_TRAINER_HILL_ENTRANCE, 255, 9, 6
# 56 "data/scripts/trainer_hill.pory"
	waitstate
# 57 "data/scripts/trainer_hill.pory"
	end

# 60 "data/scripts/trainer_hill.pory"
TrainerHill_1F_Movement_SetInvisible:
# 61 "data/scripts/trainer_hill.pory"
	set_invisible
# 62 "data/scripts/trainer_hill.pory"
	step_end

# 65 "data/scripts/trainer_hill.pory"

# 66 "data/scripts/trainer_hill.pory"
@ TRAINER_PHILLIP is an actual Trainer on the SS Tidal, but is used as a placeholder here
# 67 "data/scripts/trainer_hill.pory"
TrainerHill_EventScript_TrainerBattle::
# 68 "data/scripts/trainer_hill.pory"
	trainerbattle TRAINER_BATTLE_HILL, TRAINER_PHILLIP, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
# 69 "data/scripts/trainer_hill.pory"
	trainerhill_postbattletext
# 70 "data/scripts/trainer_hill.pory"
	waitmessage
# 71 "data/scripts/trainer_hill.pory"
	waitbuttonpress
# 72 "data/scripts/trainer_hill.pory"
	closemessage
# 73 "data/scripts/trainer_hill.pory"
	end
