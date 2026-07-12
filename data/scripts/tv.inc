# 1 "data/scripts/tv.pory"

# 2 "data/scripts/tv.pory"
EventScript_TV::
# 3 "data/scripts/tv.pory"
	lockall
# 4 "data/scripts/tv.pory"
	incrementgamestat GAME_STAT_WATCHED_TV
# 5 "data/scripts/tv.pory"
	special ResetTVShowState
# 6 "data/scripts/tv.pory"
	specialvar VAR_RESULT, CheckForBigMovieOrEmergencyNewsOnTV
# 7 "data/scripts/tv.pory"
	compare VAR_RESULT, 2
# 8 "data/scripts/tv.pory"
	goto_if_eq EventScript_PlayersHouseMovie
# 9 "data/scripts/tv.pory"
	compare VAR_RESULT, 1
# 10 "data/scripts/tv.pory"
	goto_if_eq EventScript_PlayersHouseLatiNewsFlash
# 11 "data/scripts/tv.pory"
	goto_if_unset FLAG_SYS_TV_START, EventScript_MomDadMightLikeThis1
# 12 "data/scripts/tv.pory"
	goto_if_set FLAG_SYS_TV_WATCH, EventScript_MomDadMightLikeThis1
# 13 "data/scripts/tv.pory"
	specialvar VAR_RESULT, IsTVShowInSearchOfTrainersAiring
# 14 "data/scripts/tv.pory"
	compare VAR_RESULT, TRUE
# 15 "data/scripts/tv.pory"
	goto_if_eq EventScript_DoInSearchOfTrainers
# 16 "data/scripts/tv.pory"
	goto EventScript_TryDoPokeNews
# 17 "data/scripts/tv.pory"
	end
# 18 "data/scripts/tv.pory"

# 19 "data/scripts/tv.pory"
EventScript_TryDoTVShow::
# 20 "data/scripts/tv.pory"
	specialvar VAR_0x8004, GetRandomActiveShowIdx
# 21 "data/scripts/tv.pory"
	compare VAR_0x8004, 255
# 22 "data/scripts/tv.pory"
	goto_if_eq EventScript_MomDadMightLikeThis2
# 23 "data/scripts/tv.pory"
	specialvar VAR_RESULT, GetNextActiveShowIfMassOutbreak
# 24 "data/scripts/tv.pory"
	compare VAR_RESULT, 255
# 25 "data/scripts/tv.pory"
	goto_if_eq EventScript_MomDadMightLikeThis2
# 26 "data/scripts/tv.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 27 "data/scripts/tv.pory"
	specialvar VAR_RESULT, GetSelectedTVShow
# 28 "data/scripts/tv.pory"
	compare VAR_RESULT, 0
# 29 "data/scripts/tv.pory"
	goto_if_ne EventScript_DoTVShow
# 30 "data/scripts/tv.pory"
	end
# 31 "data/scripts/tv.pory"

# 32 "data/scripts/tv.pory"
EventScript_MomDadMightLikeThis1::
# 33 "data/scripts/tv.pory"
	special GetMomOrDadStringForTVMessage
# 34 "data/scripts/tv.pory"
	msgbox gText_MomOrDadMightLikeThisProgram, MSGBOX_DEFAULT
# 35 "data/scripts/tv.pory"
	special TurnOffTVScreen
# 36 "data/scripts/tv.pory"
	releaseall
# 37 "data/scripts/tv.pory"
	end
# 38 "data/scripts/tv.pory"

# 39 "data/scripts/tv.pory"
EventScript_PlayersHouseMovie::
# 40 "data/scripts/tv.pory"
	msgbox PlayersHouse_1F_Text_TheresAMovieOnTV, MSGBOX_DEFAULT
# 41 "data/scripts/tv.pory"
	releaseall
# 42 "data/scripts/tv.pory"
	end
# 43 "data/scripts/tv.pory"

# 44 "data/scripts/tv.pory"
EventScript_PlayersHouseLatiNewsFlash::
# 45 "data/scripts/tv.pory"
	msgbox PlayersHouse_1F_Text_LatiEmergencyNewsFlash, MSGBOX_DEFAULT
# 46 "data/scripts/tv.pory"
	special InitRoamer
# 47 "data/scripts/tv.pory"
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
# 48 "data/scripts/tv.pory"
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
# 49 "data/scripts/tv.pory"
	special TurnOffTVScreen
# 50 "data/scripts/tv.pory"
	releaseall
# 51 "data/scripts/tv.pory"
	end
# 52 "data/scripts/tv.pory"

# 53 "data/scripts/tv.pory"
EventScript_DoTVShow::
# 54 "data/scripts/tv.pory"
	special DoTVShow
# 55 "data/scripts/tv.pory"
	waitmessage
# 56 "data/scripts/tv.pory"
	waitbuttonpress
# 57 "data/scripts/tv.pory"
	compare VAR_RESULT, 1
# 58 "data/scripts/tv.pory"
	goto_if_ne EventScript_DoTVShow
# 59 "data/scripts/tv.pory"
	goto EventScript_TurnOffTV
# 60 "data/scripts/tv.pory"
	end
# 61 "data/scripts/tv.pory"

# 62 "data/scripts/tv.pory"
EventScript_TurnOffTV::
# 63 "data/scripts/tv.pory"
	special TurnOffTVScreen
# 64 "data/scripts/tv.pory"
	setflag FLAG_SYS_TV_WATCH
# 65 "data/scripts/tv.pory"
	releaseall
# 66 "data/scripts/tv.pory"
	end
# 67 "data/scripts/tv.pory"

# 68 "data/scripts/tv.pory"
EventScript_MomDadMightLikeThis2::
# 69 "data/scripts/tv.pory"
	special GetMomOrDadStringForTVMessage
# 70 "data/scripts/tv.pory"
	msgbox gText_MomOrDadMightLikeThisProgram, MSGBOX_DEFAULT
# 71 "data/scripts/tv.pory"
	goto EventScript_TurnOffTV
# 72 "data/scripts/tv.pory"
	end
# 73 "data/scripts/tv.pory"

# 74 "data/scripts/tv.pory"
EventScript_TryDoPokeNews::
# 75 "data/scripts/tv.pory"
	special DoPokeNews
# 76 "data/scripts/tv.pory"
	compare VAR_RESULT, FALSE
# 77 "data/scripts/tv.pory"
	goto_if_eq EventScript_TryDoTVShow
# 78 "data/scripts/tv.pory"
	waitmessage
# 79 "data/scripts/tv.pory"
	waitbuttonpress
# 80 "data/scripts/tv.pory"
	goto EventScript_TurnOffTV
# 81 "data/scripts/tv.pory"
	end
# 82 "data/scripts/tv.pory"

# 83 "data/scripts/tv.pory"
EventScript_DoInSearchOfTrainers::
# 84 "data/scripts/tv.pory"
	special DoTVShowInSearchOfTrainers
# 85 "data/scripts/tv.pory"
	waitmessage
# 86 "data/scripts/tv.pory"
	waitbuttonpress
# 87 "data/scripts/tv.pory"
	compare VAR_RESULT, 0
# 88 "data/scripts/tv.pory"
	goto_if_eq EventScript_DoInSearchOfTrainers
# 89 "data/scripts/tv.pory"
	goto EventScript_TurnOffTV
# 90 "data/scripts/tv.pory"
	end
