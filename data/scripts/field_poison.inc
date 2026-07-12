# 1 "data/scripts/field_poison.pory"

# 2 "data/scripts/field_poison.pory"
EventScript_FieldPoison::
# 3 "data/scripts/field_poison.pory"
	lockall
# 4 "data/scripts/field_poison.pory"
	special TryFieldPoisonWhiteOut
# 5 "data/scripts/field_poison.pory"
	waitstate
# 6 "data/scripts/field_poison.pory"
	compare VAR_RESULT, FLDPSN_WHITEOUT
# 7 "data/scripts/field_poison.pory"
	goto_if_eq EventScript_FieldWhiteOut
# 8 "data/scripts/field_poison.pory"
	compare VAR_RESULT, FLDPSN_FRONTIER_WHITEOUT
# 9 "data/scripts/field_poison.pory"
	goto_if_eq EventScript_FrontierFieldWhiteOut
# 10 "data/scripts/field_poison.pory"
	releaseall
# 11 "data/scripts/field_poison.pory"
	end
# 12 "data/scripts/field_poison.pory"

# 13 "data/scripts/field_poison.pory"
EventScript_FieldWhiteOut::
# 14 "data/scripts/field_poison.pory"
	message gText_PlayerWhitedOut
# 15 "data/scripts/field_poison.pory"
	waitmessage
# 16 "data/scripts/field_poison.pory"
	waitbuttonpress
# 17 "data/scripts/field_poison.pory"
	special Script_FadeOutMapMusic
# 18 "data/scripts/field_poison.pory"
	waitstate
# 19 "data/scripts/field_poison.pory"
	fadescreen FADE_TO_BLACK
# 20 "data/scripts/field_poison.pory"
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, EventScript_SetRespawnLavaridgePkmnCenter
# 21 "data/scripts/field_poison.pory"
	special SetCB2WhiteOut
# 22 "data/scripts/field_poison.pory"
	waitstate
# 23 "data/scripts/field_poison.pory"
	end
# 24 "data/scripts/field_poison.pory"

# 25 "data/scripts/field_poison.pory"
EventScript_SetRespawnLavaridgePkmnCenter::
# 26 "data/scripts/field_poison.pory"
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
# 27 "data/scripts/field_poison.pory"
	return
# 28 "data/scripts/field_poison.pory"

# 29 "data/scripts/field_poison.pory"
EventScript_FrontierFieldWhiteOut::
# 30 "data/scripts/field_poison.pory"
	message gText_PlayerWhitedOut
# 31 "data/scripts/field_poison.pory"
	waitmessage
# 32 "data/scripts/field_poison.pory"
	waitbuttonpress
# 33 "data/scripts/field_poison.pory"
	pike_inchallenge
# 34 "data/scripts/field_poison.pory"
	compare VAR_RESULT, TRUE
# 35 "data/scripts/field_poison.pory"
	goto_if_eq BattleFrontier_BattlePike_EventScript_Retire
# 36 "data/scripts/field_poison.pory"
	pyramid_inchallenge
# 37 "data/scripts/field_poison.pory"
	compare VAR_RESULT, 1
# 38 "data/scripts/field_poison.pory"
	goto_if_eq BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 39 "data/scripts/field_poison.pory"
	compare VAR_RESULT, 2
# 40 "data/scripts/field_poison.pory"
	goto_if_eq BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
# 41 "data/scripts/field_poison.pory"
	trainerhill_inchallenge
# 42 "data/scripts/field_poison.pory"
	compare VAR_RESULT, TRUE
# 43 "data/scripts/field_poison.pory"
	goto_if_eq TrainerHill_1F_EventScript_Lost
# 44 "data/scripts/field_poison.pory"
	special Script_FadeOutMapMusic
# 45 "data/scripts/field_poison.pory"
	waitstate
# 46 "data/scripts/field_poison.pory"
	fadescreen FADE_TO_BLACK
# 47 "data/scripts/field_poison.pory"
	special SetCB2WhiteOut
# 48 "data/scripts/field_poison.pory"
	waitstate
# 49 "data/scripts/field_poison.pory"
	end
