# 1 "data/scripts/prof_birch.pory"

# 2 "data/scripts/prof_birch.pory"
ProfBirch_EventScript_UpdateLocation::
# 3 "data/scripts/prof_birch.pory"
	compare VAR_PETALBURG_GYM_STATE, 0
# 4 "data/scripts/prof_birch.pory"
	goto_if_eq Common_EventScript_NopReturn
# 5 "data/scripts/prof_birch.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, ProfBirch_EventScript_MoveToLab
# 6 "data/scripts/prof_birch.pory"
	compare VAR_BIRCH_STATE, 0
# 7 "data/scripts/prof_birch.pory"
	call_if_eq ProfBirch_EventScript_MoveToLab
# 8 "data/scripts/prof_birch.pory"
	compare VAR_BIRCH_STATE, 1
# 9 "data/scripts/prof_birch.pory"
	call_if_eq ProfBirch_EventScript_MoveToLab
# 10 "data/scripts/prof_birch.pory"
	compare VAR_BIRCH_STATE, 2
# 11 "data/scripts/prof_birch.pory"
	call_if_eq ProfBirch_EventScript_MoveToRoute101
# 12 "data/scripts/prof_birch.pory"
	compare VAR_BIRCH_STATE, 3
# 13 "data/scripts/prof_birch.pory"
	call_if_eq ProfBirch_EventScript_MoveToRoute101
# 14 "data/scripts/prof_birch.pory"
	compare VAR_BIRCH_STATE, 4
# 15 "data/scripts/prof_birch.pory"
	call_if_eq ProfBirch_EventScript_MoveToRoute103
# 16 "data/scripts/prof_birch.pory"
	compare VAR_BIRCH_STATE, 5
# 17 "data/scripts/prof_birch.pory"
	call_if_eq ProfBirch_EventScript_MoveToRoute103
# 18 "data/scripts/prof_birch.pory"
	compare VAR_BIRCH_STATE, 6
# 19 "data/scripts/prof_birch.pory"
	call_if_eq ProfBirch_EventScript_MoveToLab
# 20 "data/scripts/prof_birch.pory"
	compare VAR_BIRCH_STATE, 7
# 21 "data/scripts/prof_birch.pory"
	call_if_eq ProfBirch_EventScript_MoveToLab
# 22 "data/scripts/prof_birch.pory"
	return
# 23 "data/scripts/prof_birch.pory"

# 24 "data/scripts/prof_birch.pory"
ProfBirch_EventScript_MoveToLab::
# 25 "data/scripts/prof_birch.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
# 26 "data/scripts/prof_birch.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
# 27 "data/scripts/prof_birch.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH
# 28 "data/scripts/prof_birch.pory"
	setflag FLAG_HIDE_ROUTE_103_BIRCH
# 29 "data/scripts/prof_birch.pory"
	return
# 30 "data/scripts/prof_birch.pory"

# 31 "data/scripts/prof_birch.pory"
ProfBirch_EventScript_MoveToRoute101::
# 32 "data/scripts/prof_birch.pory"
	clearflag FLAG_HIDE_ROUTE_101_BIRCH
# 33 "data/scripts/prof_birch.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
# 34 "data/scripts/prof_birch.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
# 35 "data/scripts/prof_birch.pory"
	setflag FLAG_HIDE_ROUTE_103_BIRCH
# 36 "data/scripts/prof_birch.pory"
	return
# 37 "data/scripts/prof_birch.pory"

# 38 "data/scripts/prof_birch.pory"
ProfBirch_EventScript_MoveToRoute103::
# 39 "data/scripts/prof_birch.pory"
	clearflag FLAG_HIDE_ROUTE_103_BIRCH
# 40 "data/scripts/prof_birch.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH
# 41 "data/scripts/prof_birch.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
# 42 "data/scripts/prof_birch.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
# 43 "data/scripts/prof_birch.pory"
	return
# 44 "data/scripts/prof_birch.pory"

# 45 "data/scripts/prof_birch.pory"
ProfBirch_EventScript_RatePokedexOrRegister::
# 46 "data/scripts/prof_birch.pory"
	lock
# 47 "data/scripts/prof_birch.pory"
	faceplayer
# 48 "data/scripts/prof_birch.pory"
	goto_if_unset FLAG_HAS_MATCH_CALL, ProfBirch_EventScript_AskRatePokedex
# 49 "data/scripts/prof_birch.pory"
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
# 50 "data/scripts/prof_birch.pory"

# 51 "data/scripts/prof_birch.pory"
ProfBirch_EventScript_AskRatePokedex::
# 52 "data/scripts/prof_birch.pory"
	msgbox gBirchDexRatingText_AreYouCurious, MSGBOX_YESNO
# 53 "data/scripts/prof_birch.pory"
	compare VAR_RESULT, NO
# 54 "data/scripts/prof_birch.pory"
	goto_if_eq ProfBirch_EventScript_DeclineRating
# 55 "data/scripts/prof_birch.pory"
	call ProfBirch_EventScript_RatePokedex
# 56 "data/scripts/prof_birch.pory"
	release
# 57 "data/scripts/prof_birch.pory"
	end
# 58 "data/scripts/prof_birch.pory"

# 59 "data/scripts/prof_birch.pory"
ProfBirch_EventScript_DeclineRating::
# 60 "data/scripts/prof_birch.pory"
	msgbox gBirchDexRatingText_Cancel, MSGBOX_DEFAULT
# 61 "data/scripts/prof_birch.pory"
	release
# 62 "data/scripts/prof_birch.pory"
	end
# 63 "data/scripts/prof_birch.pory"

# 64 "data/scripts/prof_birch.pory"
ProfBirch_EventScript_ShowRatingMessage::
# 65 "data/scripts/prof_birch.pory"
	copyvar VAR_0x8004, VAR_0x8009
# 66 "data/scripts/prof_birch.pory"
	special ShowPokedexRatingMessage
# 67 "data/scripts/prof_birch.pory"
	waitmessage
# 68 "data/scripts/prof_birch.pory"
	waitbuttonpress
# 69 "data/scripts/prof_birch.pory"
	return
# 70 "data/scripts/prof_birch.pory"

# 71 "data/scripts/prof_birch.pory"
ProfBirch_EventScript_RatePokedex::
# 72 "data/scripts/prof_birch.pory"
	setvar VAR_0x8004, 0
# 73 "data/scripts/prof_birch.pory"
	specialvar VAR_RESULT, ScriptGetPokedexInfo
# 74 "data/scripts/prof_birch.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 75 "data/scripts/prof_birch.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 76 "data/scripts/prof_birch.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 77 "data/scripts/prof_birch.pory"
	buffernumberstring 0, VAR_0x8008
# 78 "data/scripts/prof_birch.pory"
	buffernumberstring 1, VAR_0x8009
# 79 "data/scripts/prof_birch.pory"
	msgbox gBirchDexRatingText_SoYouveSeenAndCaught, MSGBOX_DEFAULT
# 80 "data/scripts/prof_birch.pory"
	call ProfBirch_EventScript_ShowRatingMessage
# 81 "data/scripts/prof_birch.pory"
	compare VAR_0x800A, 0
# 82 "data/scripts/prof_birch.pory"
	goto_if_eq Common_EventScript_NopReturn
# 83 "data/scripts/prof_birch.pory"
	setvar VAR_0x8004, 1
# 84 "data/scripts/prof_birch.pory"
	specialvar VAR_RESULT, ScriptGetPokedexInfo
# 85 "data/scripts/prof_birch.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 86 "data/scripts/prof_birch.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 87 "data/scripts/prof_birch.pory"
	buffernumberstring 0, VAR_0x8008
# 88 "data/scripts/prof_birch.pory"
	buffernumberstring 1, VAR_0x8009
# 89 "data/scripts/prof_birch.pory"
	msgbox gBirchDexRatingText_OnANationwideBasis, MSGBOX_DEFAULT
# 90 "data/scripts/prof_birch.pory"
	return
