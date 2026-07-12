# 1 "data/scripts/interview.pory"

# 2 "data/scripts/interview.pory"
Interview_EventScript_EndInterview::
# 3 "data/scripts/interview.pory"
	special InterviewAfter
# 4 "data/scripts/interview.pory"
	incrementgamestat GAME_STAT_GOT_INTERVIEWED
# 5 "data/scripts/interview.pory"
	release
# 6 "data/scripts/interview.pory"
	end
# 7 "data/scripts/interview.pory"

# 8 "data/scripts/interview.pory"
@ Shares reporter object with TVSHOW_PKMN_FAN_CLUB_OPINIONS
# 9 "data/scripts/interview.pory"
SlateportCity_PokemonFanClub_EventScript_ReporterNoNickname::
# 10 "data/scripts/interview.pory"
	setvar VAR_0x8005, TVSHOW_FAN_CLUB_LETTER
# 11 "data/scripts/interview.pory"
	special InterviewBefore
# 12 "data/scripts/interview.pory"
	compare VAR_RESULT, TRUE
# 13 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_AlreadyInterviewed2
# 14 "data/scripts/interview.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 15 "data/scripts/interview.pory"
	msgbox SlateportCity_PokemonFanClub_Text_InterviewRequest, MSGBOX_YESNO
# 16 "data/scripts/interview.pory"
	compare VAR_RESULT, YES
# 17 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_AcceptInterview2
# 18 "data/scripts/interview.pory"
	compare VAR_RESULT, NO
# 19 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_DeclineInterview2
# 20 "data/scripts/interview.pory"
	end
# 21 "data/scripts/interview.pory"

# 22 "data/scripts/interview.pory"
SlateportCity_PokemonFanClub_EventScript_AcceptInterview2::
# 23 "data/scripts/interview.pory"
	msgbox SlateportCity_PokemonFanClub_Text_TellMeAnythingAboutYourMon, MSGBOX_DEFAULT
# 24 "data/scripts/interview.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_INTERVIEW
# 25 "data/scripts/interview.pory"
	copyvar VAR_0x8005, VAR_0x8009
# 26 "data/scripts/interview.pory"
	setvar VAR_0x8006, EASY_CHAT_PERSON_REPORTER_FEMALE
# 27 "data/scripts/interview.pory"
	call Common_ShowEasyChatScreen
# 28 "data/scripts/interview.pory"
	lock
# 29 "data/scripts/interview.pory"
	faceplayer
# 30 "data/scripts/interview.pory"
	compare VAR_RESULT, 1
# 31 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_SubmitResponse2
# 32 "data/scripts/interview.pory"
	compare VAR_RESULT, 0
# 33 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_DeclineInterview2
# 34 "data/scripts/interview.pory"
	end
# 35 "data/scripts/interview.pory"

# 36 "data/scripts/interview.pory"
SlateportCity_PokemonFanClub_EventScript_DeclineInterview2::
# 37 "data/scripts/interview.pory"
	msgbox SlateportCity_PokemonFanClub_Text_HereIfYouGetUrgeToTellMe, MSGBOX_DEFAULT
# 38 "data/scripts/interview.pory"
	release
# 39 "data/scripts/interview.pory"
	end
# 40 "data/scripts/interview.pory"

# 41 "data/scripts/interview.pory"
SlateportCity_PokemonFanClub_EventScript_SubmitResponse2::
# 42 "data/scripts/interview.pory"
	msgbox SlateportCity_PokemonFanClub_Text_ThatsAllForInterview2, MSGBOX_DEFAULT
# 43 "data/scripts/interview.pory"
	setvar VAR_0x8005, TVSHOW_FAN_CLUB_LETTER
# 44 "data/scripts/interview.pory"
	goto Interview_EventScript_EndInterview
# 45 "data/scripts/interview.pory"
	end
# 46 "data/scripts/interview.pory"

# 47 "data/scripts/interview.pory"
SlateportCity_PokemonFanClub_EventScript_AlreadyInterviewed2::
# 48 "data/scripts/interview.pory"
	msgbox SlateportCity_PokemonFanClub_Text_EnjoyDoingInterviews, MSGBOX_DEFAULT
# 49 "data/scripts/interview.pory"
	release
# 50 "data/scripts/interview.pory"
	end
# 51 "data/scripts/interview.pory"

# 52 "data/scripts/interview.pory"
SlateportCity_OceanicMuseum_1F_EventScript_Reporter::
# 53 "data/scripts/interview.pory"
	lock
# 54 "data/scripts/interview.pory"
	faceplayer
# 55 "data/scripts/interview.pory"
	setvar VAR_0x8005, TVSHOW_RECENT_HAPPENINGS
# 56 "data/scripts/interview.pory"
	special InterviewBefore
# 57 "data/scripts/interview.pory"
	compare VAR_RESULT, TRUE
# 58 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_AlreadyInterviewed
# 59 "data/scripts/interview.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 60 "data/scripts/interview.pory"
	goto_if_set FLAG_OCEANIC_MUSEUM_MET_REPORTER, SlateportCity_OceanicMuseum_1F_EventScript_RequestInterviewShort
# 61 "data/scripts/interview.pory"
	setflag FLAG_OCEANIC_MUSEUM_MET_REPORTER
# 62 "data/scripts/interview.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_InterviewRequest, MSGBOX_YESNO
# 63 "data/scripts/interview.pory"
	compare VAR_RESULT, YES
# 64 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_AcceptInterview
# 65 "data/scripts/interview.pory"
	compare VAR_RESULT, NO
# 66 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_DeclineInterview
# 67 "data/scripts/interview.pory"
	end
# 68 "data/scripts/interview.pory"

# 69 "data/scripts/interview.pory"
SlateportCity_OceanicMuseum_1F_EventScript_RequestInterviewShort::
# 70 "data/scripts/interview.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_InterviewRequestShort, MSGBOX_YESNO
# 71 "data/scripts/interview.pory"
	compare VAR_RESULT, YES
# 72 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_AcceptInterview
# 73 "data/scripts/interview.pory"
	compare VAR_RESULT, NO
# 74 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_DeclineInterview
# 75 "data/scripts/interview.pory"
	end
# 76 "data/scripts/interview.pory"

# 77 "data/scripts/interview.pory"
SlateportCity_OceanicMuseum_1F_EventScript_AcceptInterview::
# 78 "data/scripts/interview.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_TellMeExperienceInvolvingPokemon, MSGBOX_DEFAULT
# 79 "data/scripts/interview.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_INTERVIEW
# 80 "data/scripts/interview.pory"
	copyvar VAR_0x8005, VAR_0x8009
# 81 "data/scripts/interview.pory"
	setvar VAR_0x8006, EASY_CHAT_PERSON_REPORTER_MALE
# 82 "data/scripts/interview.pory"
	call Common_ShowEasyChatScreen
# 83 "data/scripts/interview.pory"
	lock
# 84 "data/scripts/interview.pory"
	faceplayer
# 85 "data/scripts/interview.pory"
	compare VAR_RESULT, 1
# 86 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_SubmitResponse
# 87 "data/scripts/interview.pory"
	compare VAR_RESULT, 0
# 88 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_DeclineInterview
# 89 "data/scripts/interview.pory"
	end
# 90 "data/scripts/interview.pory"

# 91 "data/scripts/interview.pory"
SlateportCity_OceanicMuseum_1F_EventScript_DeclineInterview::
# 92 "data/scripts/interview.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_LetMeKnowIfYouHaveStory, MSGBOX_DEFAULT
# 93 "data/scripts/interview.pory"
	release
# 94 "data/scripts/interview.pory"
	end
# 95 "data/scripts/interview.pory"

# 96 "data/scripts/interview.pory"
SlateportCity_OceanicMuseum_1F_EventScript_SubmitResponse::
# 97 "data/scripts/interview.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_ThatsAllForInterview, MSGBOX_DEFAULT
# 98 "data/scripts/interview.pory"
	setvar VAR_0x8005, TVSHOW_RECENT_HAPPENINGS
# 99 "data/scripts/interview.pory"
	goto Interview_EventScript_EndInterview
# 100 "data/scripts/interview.pory"
	end
# 101 "data/scripts/interview.pory"

# 102 "data/scripts/interview.pory"
SlateportCity_OceanicMuseum_1F_EventScript_AlreadyInterviewed::
# 103 "data/scripts/interview.pory"
	msgbox SlateportCity_OceanicMuseum_1F_Text_BetterWriteUpStory, MSGBOX_DEFAULT
# 104 "data/scripts/interview.pory"
	release
# 105 "data/scripts/interview.pory"
	end
# 106 "data/scripts/interview.pory"

# 107 "data/scripts/interview.pory"
SlateportCity_PokemonFanClub_EventScript_Reporter::
# 108 "data/scripts/interview.pory"
	lock
# 109 "data/scripts/interview.pory"
	faceplayer
# 110 "data/scripts/interview.pory"
	specialvar VAR_RESULT, IsLeadMonNicknamedOrNotEnglish
# 111 "data/scripts/interview.pory"
	compare VAR_RESULT, FALSE
# 112 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_ReporterNoNickname
# 113 "data/scripts/interview.pory"
	setvar VAR_0x8005, TVSHOW_PKMN_FAN_CLUB_OPINIONS
# 114 "data/scripts/interview.pory"
	special InterviewBefore
# 115 "data/scripts/interview.pory"
	compare VAR_RESULT, TRUE
# 116 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_AlreadyInterviewed
# 117 "data/scripts/interview.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 118 "data/scripts/interview.pory"
	msgbox SlateportCity_PokemonFanClub_Text_InterviewRequestHasName, MSGBOX_YESNO
# 119 "data/scripts/interview.pory"
	compare VAR_RESULT, YES
# 120 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_AcceptInterview
# 121 "data/scripts/interview.pory"
	compare VAR_RESULT, NO
# 122 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_DeclineInterview
# 123 "data/scripts/interview.pory"
	end
# 124 "data/scripts/interview.pory"

# 125 "data/scripts/interview.pory"
SlateportCity_PokemonFanClub_EventScript_AcceptInterview::
# 126 "data/scripts/interview.pory"
	msgbox SlateportCity_PokemonFanClub_Text_HereGoesQuickAnswers, MSGBOX_DEFAULT
# 127 "data/scripts/interview.pory"
	random 3
# 128 "data/scripts/interview.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 129 "data/scripts/interview.pory"
	switch VAR_RESULT
# 130 "data/scripts/interview.pory"
	case 0, SlateportCity_PokemonFanClub_EventScript_RandomQuestion1
# 131 "data/scripts/interview.pory"
	case 1, SlateportCity_PokemonFanClub_EventScript_RandomQuestion2
# 132 "data/scripts/interview.pory"
	case 2, SlateportCity_PokemonFanClub_EventScript_RandomQuestion3
# 133 "data/scripts/interview.pory"
	end
# 134 "data/scripts/interview.pory"

# 135 "data/scripts/interview.pory"
SlateportCity_PokemonFanClub_EventScript_RandomQuestion1::
# 136 "data/scripts/interview.pory"
	msgbox SlateportCity_PokemonFanClub_Text_DescribeFeelingsFirstMetMon, MSGBOX_DEFAULT
# 137 "data/scripts/interview.pory"
	goto SlateportCity_PokemonFanClub_EventScript_ContinueInterview
# 138 "data/scripts/interview.pory"
	end
# 139 "data/scripts/interview.pory"

# 140 "data/scripts/interview.pory"
SlateportCity_PokemonFanClub_EventScript_RandomQuestion2::
# 141 "data/scripts/interview.pory"
	msgbox SlateportCity_PokemonFanClub_Text_LikenMonToSomethingYouLike, MSGBOX_DEFAULT
# 142 "data/scripts/interview.pory"
	goto SlateportCity_PokemonFanClub_EventScript_ContinueInterview
# 143 "data/scripts/interview.pory"
	end
# 144 "data/scripts/interview.pory"

# 145 "data/scripts/interview.pory"
SlateportCity_PokemonFanClub_EventScript_RandomQuestion3::
# 146 "data/scripts/interview.pory"
	msgbox SlateportCity_PokemonFanClub_Text_WhatAttractedYouAboutMon, MSGBOX_DEFAULT
# 147 "data/scripts/interview.pory"
	goto SlateportCity_PokemonFanClub_EventScript_ContinueInterview
# 148 "data/scripts/interview.pory"
	end
# 149 "data/scripts/interview.pory"

# 150 "data/scripts/interview.pory"
SlateportCity_PokemonFanClub_EventScript_ContinueInterview::
# 151 "data/scripts/interview.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_CLUB
# 152 "data/scripts/interview.pory"
	copyvar VAR_0x8005, VAR_0x8009
# 153 "data/scripts/interview.pory"
	setvar VAR_0x8006, 0
# 154 "data/scripts/interview.pory"
	call Common_ShowEasyChatScreen
# 155 "data/scripts/interview.pory"
	lock
# 156 "data/scripts/interview.pory"
	faceplayer
# 157 "data/scripts/interview.pory"
	compare VAR_RESULT, 0
# 158 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_DeclineInterview
# 159 "data/scripts/interview.pory"
	msgbox SlateportCity_PokemonFanClub_Text_WhatDoPokemonMeanToYou, MSGBOX_DEFAULT
# 160 "data/scripts/interview.pory"
	setvar VAR_0x8006, 1
# 161 "data/scripts/interview.pory"
	call Common_ShowEasyChatScreen
# 162 "data/scripts/interview.pory"
	lock
# 163 "data/scripts/interview.pory"
	faceplayer
# 164 "data/scripts/interview.pory"
	compare VAR_RESULT, 0
# 165 "data/scripts/interview.pory"
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_DeclineInterview
# 166 "data/scripts/interview.pory"
	msgbox SlateportCity_PokemonFanClub_Text_ThatsAllForInterview, MSGBOX_DEFAULT
# 167 "data/scripts/interview.pory"
	copyvar VAR_0x8007, VAR_0x800A
# 168 "data/scripts/interview.pory"
	setvar VAR_0x8005, TVSHOW_PKMN_FAN_CLUB_OPINIONS
# 169 "data/scripts/interview.pory"
	goto Interview_EventScript_EndInterview
# 170 "data/scripts/interview.pory"
	end
# 171 "data/scripts/interview.pory"

# 172 "data/scripts/interview.pory"
SlateportCity_PokemonFanClub_EventScript_DeclineInterview::
# 173 "data/scripts/interview.pory"
	msgbox SlateportCity_PokemonFanClub_Text_HereIfYouGetUrgeToTellMe, MSGBOX_DEFAULT
# 174 "data/scripts/interview.pory"
	release
# 175 "data/scripts/interview.pory"
	end
# 176 "data/scripts/interview.pory"

# 177 "data/scripts/interview.pory"
SlateportCity_PokemonFanClub_EventScript_AlreadyInterviewed::
# 178 "data/scripts/interview.pory"
	msgbox SlateportCity_PokemonFanClub_Text_EnjoyDoingInterviews, MSGBOX_DEFAULT
# 179 "data/scripts/interview.pory"
	release
# 180 "data/scripts/interview.pory"
	end
# 181 "data/scripts/interview.pory"

# 182 "data/scripts/interview.pory"
LilycoveCity_ContestLobby_EventScript_Reporter::
# 183 "data/scripts/interview.pory"
	lock
# 184 "data/scripts/interview.pory"
	faceplayer
# 185 "data/scripts/interview.pory"
	goto_if_set FLAG_TEMP_2, LilycoveCity_ContestLobby_EventScript_AlreadyInterviewed
# 186 "data/scripts/interview.pory"
	setvar VAR_0x8005, TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE
# 187 "data/scripts/interview.pory"
	special InterviewBefore
# 188 "data/scripts/interview.pory"
	compare VAR_RESULT, TRUE
# 189 "data/scripts/interview.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_AlreadyInterviewed
# 190 "data/scripts/interview.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 191 "data/scripts/interview.pory"
	msgbox LilycoveCity_ContestLobby_Text_InterviewRequest, MSGBOX_YESNO
# 192 "data/scripts/interview.pory"
	compare VAR_RESULT, YES
# 193 "data/scripts/interview.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_AcceptInterview
# 194 "data/scripts/interview.pory"
	compare VAR_RESULT, NO
# 195 "data/scripts/interview.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_DeclineInterview
# 196 "data/scripts/interview.pory"
	end
# 197 "data/scripts/interview.pory"

# 198 "data/scripts/interview.pory"
LilycoveCity_ContestLobby_EventScript_AcceptInterview::
# 199 "data/scripts/interview.pory"
	msgbox LilycoveCity_ContestLobby_Text_DescribeContest, MSGBOX_DEFAULT
# 200 "data/scripts/interview.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_CONTEST_INTERVIEW
# 201 "data/scripts/interview.pory"
	copyvar VAR_0x8005, VAR_0x8009
# 202 "data/scripts/interview.pory"
	setvar VAR_0x8006, 0
# 203 "data/scripts/interview.pory"
	call Common_ShowEasyChatScreen
# 204 "data/scripts/interview.pory"
	lock
# 205 "data/scripts/interview.pory"
	faceplayer
# 206 "data/scripts/interview.pory"
	compare VAR_RESULT, 1
# 207 "data/scripts/interview.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_SubmitResponse
# 208 "data/scripts/interview.pory"
	compare VAR_RESULT, 0
# 209 "data/scripts/interview.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_DeclineInterview
# 210 "data/scripts/interview.pory"
	end
# 211 "data/scripts/interview.pory"

# 212 "data/scripts/interview.pory"
LilycoveCity_ContestLobby_EventScript_DeclineInterview::
# 213 "data/scripts/interview.pory"
	msgbox LilycoveCity_ContestLobby_Text_PleaseDoShareStoryWithMe, MSGBOX_DEFAULT
# 214 "data/scripts/interview.pory"
	release
# 215 "data/scripts/interview.pory"
	end
# 216 "data/scripts/interview.pory"

# 217 "data/scripts/interview.pory"
LilycoveCity_ContestLobby_EventScript_SubmitResponse::
# 218 "data/scripts/interview.pory"
	setvar VAR_0x8004, 24
# 219 "data/scripts/interview.pory"
	special SetContestCategoryStringVarForInterview
# 220 "data/scripts/interview.pory"
	msgbox LilycoveCity_ContestLobby_Text_WhatImageWhenYouHearX, MSGBOX_DEFAULT
# 221 "data/scripts/interview.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_CONTEST_INTERVIEW
# 222 "data/scripts/interview.pory"
	copyvar VAR_0x8005, VAR_0x8009
# 223 "data/scripts/interview.pory"
	setvar VAR_0x8006, 1
# 224 "data/scripts/interview.pory"
	call Common_ShowEasyChatScreen
# 225 "data/scripts/interview.pory"
	lock
# 226 "data/scripts/interview.pory"
	faceplayer
# 227 "data/scripts/interview.pory"
	compare VAR_RESULT, 0
# 228 "data/scripts/interview.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_DeclineInterview
# 229 "data/scripts/interview.pory"
	msgbox LilycoveCity_ContestLobby_Text_ThatsAllForInterview, MSGBOX_DEFAULT
# 230 "data/scripts/interview.pory"
	setflag FLAG_TEMP_2
# 231 "data/scripts/interview.pory"
	setvar VAR_0x8005, TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE
# 232 "data/scripts/interview.pory"
	goto Interview_EventScript_EndInterview
# 233 "data/scripts/interview.pory"
	end
# 234 "data/scripts/interview.pory"

# 235 "data/scripts/interview.pory"
LilycoveCity_ContestLobby_EventScript_AlreadyInterviewed::
# 236 "data/scripts/interview.pory"
	msgbox LilycoveCity_ContestLobby_Text_LookingForwardToNextContest, MSGBOX_DEFAULT
# 237 "data/scripts/interview.pory"
	release
# 238 "data/scripts/interview.pory"
	end
# 239 "data/scripts/interview.pory"

# 240 "data/scripts/interview.pory"
LilycoveCity_ContestLobby_EventScript_TryShowContestReporter::
# 241 "data/scripts/interview.pory"
	compare VAR_CONTEST_HALL_STATE, 2
# 242 "data/scripts/interview.pory"
	goto_if_ne LilycoveCity_ContestLobby_EventScript_DontShowContestReporter
# 243 "data/scripts/interview.pory"
	setvar VAR_0x8005, TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE
# 244 "data/scripts/interview.pory"
	special InterviewBefore
# 245 "data/scripts/interview.pory"
	compare VAR_RESULT, TRUE
# 246 "data/scripts/interview.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_DontShowContestReporter
# 247 "data/scripts/interview.pory"
	switch VAR_CONTEST_TYPE
# 248 "data/scripts/interview.pory"
	case 0, LilycoveCity_ContestLobby_EventScript_DontShowContestReporter
# 249 "data/scripts/interview.pory"
	case 2, LilycoveCity_ContestLobby_EventScript_ShowContestReporter
# 250 "data/scripts/interview.pory"
	case 1, LilycoveCity_ContestLobby_EventScript_ShowContestReporter
# 251 "data/scripts/interview.pory"
	case 3, LilycoveCity_ContestLobby_EventScript_ShowContestReporter
# 252 "data/scripts/interview.pory"
	case 4, LilycoveCity_ContestLobby_EventScript_ShowContestReporter
# 253 "data/scripts/interview.pory"
	case 5, LilycoveCity_ContestLobby_EventScript_DontShowContestReporter
# 254 "data/scripts/interview.pory"
	end
# 255 "data/scripts/interview.pory"

# 256 "data/scripts/interview.pory"
LilycoveCity_ContestLobby_EventScript_ShowContestReporter::
# 257 "data/scripts/interview.pory"
	clearflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
# 258 "data/scripts/interview.pory"
	return
# 259 "data/scripts/interview.pory"

# 260 "data/scripts/interview.pory"
LilycoveCity_ContestLobby_EventScript_DontShowContestReporter::
# 261 "data/scripts/interview.pory"
	return
# 262 "data/scripts/interview.pory"

# 263 "data/scripts/interview.pory"
BattleFrontier_BattleTowerLobby_EventScript_Reporter::
# 264 "data/scripts/interview.pory"
	lock
# 265 "data/scripts/interview.pory"
	faceplayer
# 266 "data/scripts/interview.pory"
	goto_if_set FLAG_TEMP_2, BattleFrontier_BattleTowerLobby_EventScript_AlreadyInterviewed
# 267 "data/scripts/interview.pory"
	setvar VAR_0x8005, TVSHOW_BRAVO_TRAINER_BATTLE_TOWER_PROFILE
# 268 "data/scripts/interview.pory"
	special InterviewBefore
# 269 "data/scripts/interview.pory"
	compare VAR_RESULT, TRUE
# 270 "data/scripts/interview.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_AlreadyInterviewed
# 271 "data/scripts/interview.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 272 "data/scripts/interview.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_InterviewRequest, MSGBOX_YESNO
# 273 "data/scripts/interview.pory"
	compare VAR_RESULT, YES
# 274 "data/scripts/interview.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_AcceptInterview
# 275 "data/scripts/interview.pory"
	compare VAR_RESULT, NO
# 276 "data/scripts/interview.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_DeclineInterview
# 277 "data/scripts/interview.pory"
	end
# 278 "data/scripts/interview.pory"

# 279 "data/scripts/interview.pory"
BattleFrontier_BattleTowerLobby_EventScript_AcceptInterview::
# 280 "data/scripts/interview.pory"
	message BattleFrontier_BattleTowerLobby_Text_HowDidBattleTowerTurnOut
# 281 "data/scripts/interview.pory"
	waitmessage
# 282 "data/scripts/interview.pory"
	multichoice 20, 8, MULTI_SATISFACTION, 1
# 283 "data/scripts/interview.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 284 "data/scripts/interview.pory"
	compare VAR_RESULT, 0
# 285 "data/scripts/interview.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_Satisfied
# 286 "data/scripts/interview.pory"
	compare VAR_RESULT, 1
# 287 "data/scripts/interview.pory"
	call_if_eq BattleFrontier_BattleTowerLobby_EventScript_Dissatisfied
# 288 "data/scripts/interview.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_DescribeYourBattle, MSGBOX_DEFAULT
# 289 "data/scripts/interview.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_TOWER_INTERVIEW
# 290 "data/scripts/interview.pory"
	copyvar VAR_0x8005, VAR_0x8009
# 291 "data/scripts/interview.pory"
	call Common_ShowEasyChatScreen
# 292 "data/scripts/interview.pory"
	lock
# 293 "data/scripts/interview.pory"
	faceplayer
# 294 "data/scripts/interview.pory"
	compare VAR_RESULT, 1
# 295 "data/scripts/interview.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_SubmitResponse
# 296 "data/scripts/interview.pory"
	compare VAR_RESULT, 0
# 297 "data/scripts/interview.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_CancelInterview
# 298 "data/scripts/interview.pory"
	end
# 299 "data/scripts/interview.pory"

# 300 "data/scripts/interview.pory"
BattleFrontier_BattleTowerLobby_EventScript_DeclineInterview::
# 301 "data/scripts/interview.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_SorryWeDisturbedYou, MSGBOX_DEFAULT
# 302 "data/scripts/interview.pory"
	release
# 303 "data/scripts/interview.pory"
	end
# 304 "data/scripts/interview.pory"

# 305 "data/scripts/interview.pory"
BattleFrontier_BattleTowerLobby_EventScript_Satisfied::
# 306 "data/scripts/interview.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ObviousYouHadGreatBattle, MSGBOX_DEFAULT
# 307 "data/scripts/interview.pory"
	return
# 308 "data/scripts/interview.pory"

# 309 "data/scripts/interview.pory"
BattleFrontier_BattleTowerLobby_EventScript_Dissatisfied::
# 310 "data/scripts/interview.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_DifficultToMakeBattleTurnOutAsPlanned, MSGBOX_DEFAULT
# 311 "data/scripts/interview.pory"
	return
# 312 "data/scripts/interview.pory"

# 313 "data/scripts/interview.pory"
BattleFrontier_BattleTowerLobby_EventScript_SubmitResponse::
# 314 "data/scripts/interview.pory"
	compare VAR_RESULT, 0
# 315 "data/scripts/interview.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_CancelInterview
# 316 "data/scripts/interview.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_ThatsGreatLine, MSGBOX_DEFAULT
# 317 "data/scripts/interview.pory"
	setflag FLAG_TEMP_2
# 318 "data/scripts/interview.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 319 "data/scripts/interview.pory"
	setvar VAR_0x8005, TVSHOW_BRAVO_TRAINER_BATTLE_TOWER_PROFILE
# 320 "data/scripts/interview.pory"
	goto Interview_EventScript_EndInterview
# 321 "data/scripts/interview.pory"
	end
# 322 "data/scripts/interview.pory"

# 323 "data/scripts/interview.pory"
BattleFrontier_BattleTowerLobby_EventScript_CancelInterview::
# 324 "data/scripts/interview.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_SilentType, MSGBOX_DEFAULT
# 325 "data/scripts/interview.pory"
	release
# 326 "data/scripts/interview.pory"
	end
# 327 "data/scripts/interview.pory"

# 328 "data/scripts/interview.pory"
BattleFrontier_BattleTowerLobby_EventScript_AlreadyInterviewed::
# 329 "data/scripts/interview.pory"
	msgbox BattleFrontier_BattleTowerLobby_Text_LookingForwardToNextBattle, MSGBOX_DEFAULT
# 330 "data/scripts/interview.pory"
	release
# 331 "data/scripts/interview.pory"
	end
# 332 "data/scripts/interview.pory"

# 333 "data/scripts/interview.pory"
BattleFrontier_BattleTowerLobby_EventScript_ShowOrHideReporter::
# 334 "data/scripts/interview.pory"
	compare VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
# 335 "data/scripts/interview.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_HideReporter
# 336 "data/scripts/interview.pory"
	setvar VAR_0x8005, TVSHOW_BRAVO_TRAINER_BATTLE_TOWER_PROFILE
# 337 "data/scripts/interview.pory"
	special InterviewBefore
# 338 "data/scripts/interview.pory"
	compare VAR_RESULT, TRUE
# 339 "data/scripts/interview.pory"
	goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_HideReporter
# 340 "data/scripts/interview.pory"
	clearflag FLAG_HIDE_BATTLE_TOWER_REPORTER
# 341 "data/scripts/interview.pory"
	return
# 342 "data/scripts/interview.pory"

# 343 "data/scripts/interview.pory"
BattleFrontier_BattleTowerLobby_EventScript_HideReporter::
# 344 "data/scripts/interview.pory"
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
# 345 "data/scripts/interview.pory"
	return
