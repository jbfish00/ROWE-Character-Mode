# 1 "data/scripts/contest_hall.pory"

# 2 "data/scripts/contest_hall.pory"
.set LOCALID_MC, 1
# 3 "data/scripts/contest_hall.pory"
.set LOCALID_JUDGE, 2
# 4 "data/scripts/contest_hall.pory"
.set LOCALID_CONTESTANT_1, 3
# 5 "data/scripts/contest_hall.pory"
.set LOCALID_CONTESTANT_2, 4
# 6 "data/scripts/contest_hall.pory"
.set LOCALID_CONTESTANT_3, 5
# 7 "data/scripts/contest_hall.pory"
.set LOCALID_AUDIENCE_1, 6
# 8 "data/scripts/contest_hall.pory"
.set LOCALID_AUDIENCE_3, 7
# 9 "data/scripts/contest_hall.pory"
.set LOCALID_AUDIENCE_4, 8
# 10 "data/scripts/contest_hall.pory"
.set LOCALID_AUDIENCE_5, 9
# 11 "data/scripts/contest_hall.pory"
.set LOCALID_AUDIENCE_6, 10
# 12 "data/scripts/contest_hall.pory"
.set LOCALID_AUDIENCE_7, 11
# 13 "data/scripts/contest_hall.pory"
.set LOCALID_AUDIENCE_2, 12
# 14 "data/scripts/contest_hall.pory"
.set LOCALID_POKEBALL, 13
# 15 "data/scripts/contest_hall.pory"
.set LOCALID_CONTESTANT_4, 14
# 16 "data/scripts/contest_hall.pory"
.set LOCALID_ARTIST, 15
# 17 "data/scripts/contest_hall.pory"

# 18 "data/scripts/contest_hall.pory"
@ Either ends or returns to EventScript_ContestReceptionist after submitting a contest entry
# 19 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_SpeakToContestReceptionist:: @ 8279CC5
# 20 "data/scripts/contest_hall.pory"
	lock
# 21 "data/scripts/contest_hall.pory"
	faceplayer
# 22 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_PRIZE_PICKUP, 0
# 23 "data/scripts/contest_hall.pory"
	goto_if_ne LilycoveCity_ContestLobby_EventScript_PickUpPrize
# 24 "data/scripts/contest_hall.pory"
	call_if_set FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_ReceptionWelcome
# 25 "data/scripts/contest_hall.pory"
	call_if_unset FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_GivePokeblockCase
# 26 "data/scripts/contest_hall.pory"
	goto LilycoveCity_ContestLobby_EventScript_AskEnterContest
# 27 "data/scripts/contest_hall.pory"
	end
# 28 "data/scripts/contest_hall.pory"

# 29 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_ReceptionWelcome:: @ 8279CEA
# 30 "data/scripts/contest_hall.pory"
	msgbox LilycoveCity_ContestLobby_Text_ContestReception, MSGBOX_DEFAULT
# 31 "data/scripts/contest_hall.pory"
	return
# 32 "data/scripts/contest_hall.pory"

# 33 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_GivePokeblockCase:: @ 8279CF3
# 34 "data/scripts/contest_hall.pory"
	msgbox LilycoveCity_ContestLobby_Text_ReceptionDontHavePokeblockCase, MSGBOX_DEFAULT
# 35 "data/scripts/contest_hall.pory"
	giveitem ITEM_POKEBLOCK_CASE
# 36 "data/scripts/contest_hall.pory"
	setflag FLAG_RECEIVED_POKEBLOCK_CASE
# 37 "data/scripts/contest_hall.pory"
	msgbox LilycoveCity_ContestLobby_Text_NowThatWeveClearedThatUp, MSGBOX_DEFAULT
# 38 "data/scripts/contest_hall.pory"
	return
# 39 "data/scripts/contest_hall.pory"

# 40 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_PickUpPrize:: @ 8279D13
# 41 "data/scripts/contest_hall.pory"
	msgbox LilycoveCity_ContestLobby_Text_PokemonWonWeHavePrize, MSGBOX_DEFAULT
# 42 "data/scripts/contest_hall.pory"
	switch VAR_CONTEST_PRIZE_PICKUP
# 43 "data/scripts/contest_hall.pory"
	case 4, LilycoveCity_ContestLobby_EventScript_GiveLuxuryBallAtCounter
# 44 "data/scripts/contest_hall.pory"
	end
# 45 "data/scripts/contest_hall.pory"

# 46 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_GiveLuxuryBallAtCounter:: @ 8279D2C
# 47 "data/scripts/contest_hall.pory"
	giveitem ITEM_LUXURY_BALL
# 48 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, FALSE
# 49 "data/scripts/contest_hall.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_NoRoomForLuxuryBallAtCounter
# 50 "data/scripts/contest_hall.pory"
	setvar VAR_CONTEST_PRIZE_PICKUP, 0
# 51 "data/scripts/contest_hall.pory"
	closemessage
# 52 "data/scripts/contest_hall.pory"
	release
# 53 "data/scripts/contest_hall.pory"
	end
# 54 "data/scripts/contest_hall.pory"

# 55 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_NoRoomForLuxuryBallAtCounter:: @ 8279D4B
# 56 "data/scripts/contest_hall.pory"
	call Common_EventScript_BagIsFull
# 57 "data/scripts/contest_hall.pory"
	msgbox LilycoveCity_ContestLobby_Text_ComeBackForPrizeLater, MSGBOX_DEFAULT
# 58 "data/scripts/contest_hall.pory"
	release
# 59 "data/scripts/contest_hall.pory"
	end
# 60 "data/scripts/contest_hall.pory"

# 61 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_AskEnterContest:: @ 8279D5A
# 62 "data/scripts/contest_hall.pory"
	message LilycoveCity_ContestLobby_Text_EnterContest1
# 63 "data/scripts/contest_hall.pory"
	waitmessage
# 64 "data/scripts/contest_hall.pory"
	multichoice 0, 0, MULTI_ENTERINFO, 0
# 65 "data/scripts/contest_hall.pory"
	switch VAR_RESULT
# 66 "data/scripts/contest_hall.pory"
	case 0, LilycoveCity_ContestLobby_EventScript_ChooseContestRank
# 67 "data/scripts/contest_hall.pory"
	case 1, LilycoveCity_ContestLobby_EventScript_ContestInfo
# 68 "data/scripts/contest_hall.pory"
	case 2, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
# 69 "data/scripts/contest_hall.pory"
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
# 70 "data/scripts/contest_hall.pory"
	end
# 71 "data/scripts/contest_hall.pory"

# 72 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_ContestInfo:: @ 8279D97
# 73 "data/scripts/contest_hall.pory"
	message LilycoveCity_ContestLobby_Text_WhichTopic1
# 74 "data/scripts/contest_hall.pory"
	waitmessage
# 75 "data/scripts/contest_hall.pory"
	multichoice 0, 0, MULTI_CONTEST_INFO, 0
# 76 "data/scripts/contest_hall.pory"
	switch VAR_RESULT
# 77 "data/scripts/contest_hall.pory"
	case 0, LilycoveCity_ContestLobby_EventScript_ExplainContests
# 78 "data/scripts/contest_hall.pory"
	case 1, LilycoveCity_ContestLobby_EventScript_ExplainContestTypes
# 79 "data/scripts/contest_hall.pory"
	case 2, LilycoveCity_ContestLobby_EventScript_ExplainContestRanks
# 80 "data/scripts/contest_hall.pory"
	case 3, LilycoveCity_ContestLobby_EventScript_AskEnterContest
# 81 "data/scripts/contest_hall.pory"
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_AskEnterContest
# 82 "data/scripts/contest_hall.pory"
	end
# 83 "data/scripts/contest_hall.pory"

# 84 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_ExplainContests:: @ 8279DDF
# 85 "data/scripts/contest_hall.pory"
	msgbox LilycoveCity_ContestLobby_Text_ExplainContests, MSGBOX_DEFAULT
# 86 "data/scripts/contest_hall.pory"
	goto LilycoveCity_ContestLobby_EventScript_ContestInfo
# 87 "data/scripts/contest_hall.pory"
	end
# 88 "data/scripts/contest_hall.pory"

# 89 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_ExplainContestTypes:: @ 8279DED
# 90 "data/scripts/contest_hall.pory"
	msgbox LilycoveCity_ContestLobby_Text_ExplainContestTypes, MSGBOX_DEFAULT
# 91 "data/scripts/contest_hall.pory"
	goto LilycoveCity_ContestLobby_EventScript_ContestInfo
# 92 "data/scripts/contest_hall.pory"
	end
# 93 "data/scripts/contest_hall.pory"

# 94 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_ExplainContestRanks:: @ 8279DFB
# 95 "data/scripts/contest_hall.pory"
	msgbox LilycoveCity_ContestLobby_Text_ExplainContestRanks, MSGBOX_DEFAULT
# 96 "data/scripts/contest_hall.pory"
	goto LilycoveCity_ContestLobby_EventScript_ContestInfo
# 97 "data/scripts/contest_hall.pory"
	end
# 98 "data/scripts/contest_hall.pory"

# 99 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_CancelEnterContest:: @ 8279E09
# 100 "data/scripts/contest_hall.pory"
	msgbox LilycoveCity_ContestLobby_Text_ParticipateAnotherTime, MSGBOX_DEFAULT
# 101 "data/scripts/contest_hall.pory"
	release
# 102 "data/scripts/contest_hall.pory"
	end
# 103 "data/scripts/contest_hall.pory"

# 104 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_ChooseContestMon:: @ 8279E13
# 105 "data/scripts/contest_hall.pory"
	msgbox LilycoveCity_ContestLobby_Text_EnterWhichPokemon1, MSGBOX_DEFAULT
# 106 "data/scripts/contest_hall.pory"
	choosecontestmon
# 107 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 255
# 108 "data/scripts/contest_hall.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CancelEnterContest
# 109 "data/scripts/contest_hall.pory"
	special TryEnterContestMon
# 110 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, CANT_ENTER_CONTEST
# 111 "data/scripts/contest_hall.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CantEnterLowRank
# 112 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, CAN_ENTER_CONTEST_EQUAL_RANK
# 113 "data/scripts/contest_hall.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_EnterMon
# 114 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, CAN_ENTER_CONTEST_HIGH_RANK
# 115 "data/scripts/contest_hall.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_ConfirmEntryAlreadyWon
# 116 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, CANT_ENTER_CONTEST_EGG
# 117 "data/scripts/contest_hall.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CantEnterEgg
# 118 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, CANT_ENTER_CONTEST_FAINTED
# 119 "data/scripts/contest_hall.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_CantEnterFainted
# 120 "data/scripts/contest_hall.pory"
	end
# 121 "data/scripts/contest_hall.pory"

# 122 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_ChooseContestRank:: @ 8279E62
# 123 "data/scripts/contest_hall.pory"
	message LilycoveCity_ContestLobby_Text_EnterWhichRank
# 124 "data/scripts/contest_hall.pory"
	waitmessage
# 125 "data/scripts/contest_hall.pory"
	multichoice 0, 0, MULTI_CONTEST_RANK, 0
# 126 "data/scripts/contest_hall.pory"
	switch VAR_RESULT
# 127 "data/scripts/contest_hall.pory"
	case 0, LilycoveCity_ContestLobby_EventScript_EnterNormalRank
# 128 "data/scripts/contest_hall.pory"
	case 1, LilycoveCity_ContestLobby_EventScript_EnterSuperRank
# 129 "data/scripts/contest_hall.pory"
	case 2, LilycoveCity_ContestLobby_EventScript_EnterHyperRank
# 130 "data/scripts/contest_hall.pory"
	case 3, LilycoveCity_ContestLobby_EventScript_EnterMasterRank
# 131 "data/scripts/contest_hall.pory"
	case 4, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
# 132 "data/scripts/contest_hall.pory"
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
# 133 "data/scripts/contest_hall.pory"
	end
# 134 "data/scripts/contest_hall.pory"

# 135 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_EnterNormalRank:: @ 8279EB5
# 136 "data/scripts/contest_hall.pory"
	setvar VAR_CONTEST_RANK, CONTEST_RANK_NORMAL
# 137 "data/scripts/contest_hall.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
# 138 "data/scripts/contest_hall.pory"
	end
# 139 "data/scripts/contest_hall.pory"

# 140 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_EnterSuperRank:: @ 8279EC0
# 141 "data/scripts/contest_hall.pory"
	setvar VAR_CONTEST_RANK, CONTEST_RANK_SUPER
# 142 "data/scripts/contest_hall.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
# 143 "data/scripts/contest_hall.pory"
	end
# 144 "data/scripts/contest_hall.pory"

# 145 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_EnterHyperRank:: @ 8279ECB
# 146 "data/scripts/contest_hall.pory"
	setvar VAR_CONTEST_RANK, CONTEST_RANK_HYPER
# 147 "data/scripts/contest_hall.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
# 148 "data/scripts/contest_hall.pory"
	end
# 149 "data/scripts/contest_hall.pory"

# 150 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_EnterMasterRank:: @ 8279ED6
# 151 "data/scripts/contest_hall.pory"
	setvar VAR_CONTEST_RANK, CONTEST_RANK_MASTER
# 152 "data/scripts/contest_hall.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestType
# 153 "data/scripts/contest_hall.pory"
	end
# 154 "data/scripts/contest_hall.pory"

# 155 "data/scripts/contest_hall.pory"
@ The multichoice selection IDs are equal to the CATEGORY values
# 156 "data/scripts/contest_hall.pory"
@ So rather than list the cases they just copy VAR_RESULT for a valid selection into VAR_CONTEST_CATEGORY
# 157 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_ChooseContestType:: @ 8279EE1
# 158 "data/scripts/contest_hall.pory"
	message LilycoveCity_ContestLobby_Text_EnterWhichContest1
# 159 "data/scripts/contest_hall.pory"
	waitmessage
# 160 "data/scripts/contest_hall.pory"
	multichoice 0, 0, MULTI_CONTEST_TYPE, 0
# 161 "data/scripts/contest_hall.pory"
	switch VAR_RESULT
# 162 "data/scripts/contest_hall.pory"
	case 5, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
# 163 "data/scripts/contest_hall.pory"
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelEnterContest
# 164 "data/scripts/contest_hall.pory"
	copyvar VAR_CONTEST_CATEGORY, VAR_RESULT
# 165 "data/scripts/contest_hall.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
# 166 "data/scripts/contest_hall.pory"
	end
# 167 "data/scripts/contest_hall.pory"

# 168 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_CantEnterLowRank:: @ 8279F12
# 169 "data/scripts/contest_hall.pory"
	msgbox LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank, MSGBOX_DEFAULT
# 170 "data/scripts/contest_hall.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
# 171 "data/scripts/contest_hall.pory"
	release
# 172 "data/scripts/contest_hall.pory"
	end
# 173 "data/scripts/contest_hall.pory"

# 174 "data/scripts/contest_hall.pory"
@ Unused
# 175 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_ConfirmEntry:: @ 8279F21
# 176 "data/scripts/contest_hall.pory"
	msgbox LilycoveCity_ContestLobby_Text_ConfirmContestMon, MSGBOX_YESNO
# 177 "data/scripts/contest_hall.pory"
	switch VAR_RESULT
# 178 "data/scripts/contest_hall.pory"
	case NO, LilycoveCity_ContestLobby_EventScript_ChooseContestMon
# 179 "data/scripts/contest_hall.pory"
	case YES, LilycoveCity_ContestLobby_EventScript_EnterMon
# 180 "data/scripts/contest_hall.pory"
	end
# 181 "data/scripts/contest_hall.pory"

# 182 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_ConfirmEntryAlreadyWon:: @ 8279F45
# 183 "data/scripts/contest_hall.pory"
	msgbox LilycoveCity_ContestLobby_Text_AlreadyWonEnterAnyway, MSGBOX_YESNO
# 184 "data/scripts/contest_hall.pory"
	switch VAR_RESULT
# 185 "data/scripts/contest_hall.pory"
	case NO, LilycoveCity_ContestLobby_EventScript_ChooseContestMon
# 186 "data/scripts/contest_hall.pory"
	case YES, LilycoveCity_ContestLobby_EventScript_EnterMon
# 187 "data/scripts/contest_hall.pory"
	end
# 188 "data/scripts/contest_hall.pory"

# 189 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_CantEnterEgg:: @ 8279F69
# 190 "data/scripts/contest_hall.pory"
	msgbox LilycoveCity_ContestLobby_Text_EggCannotTakePart, MSGBOX_DEFAULT
# 191 "data/scripts/contest_hall.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
# 192 "data/scripts/contest_hall.pory"
	release
# 193 "data/scripts/contest_hall.pory"
	end
# 194 "data/scripts/contest_hall.pory"

# 195 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_CantEnterFainted:: @ 8279F78
# 196 "data/scripts/contest_hall.pory"
	msgbox LilycoveCity_ContestLobby_Text_MonInNoConditionForContest, MSGBOX_DEFAULT
# 197 "data/scripts/contest_hall.pory"
	goto LilycoveCity_ContestLobby_EventScript_ChooseContestMon
# 198 "data/scripts/contest_hall.pory"
	release
# 199 "data/scripts/contest_hall.pory"
	end
# 200 "data/scripts/contest_hall.pory"

# 201 "data/scripts/contest_hall.pory"
@ The return here is back to LilycoveCity_ContestLobby_EventScript_ContestReceptionist
# 202 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_EnterMon:: @ 8279F87
# 203 "data/scripts/contest_hall.pory"
	msgbox LilycoveCity_ContestLobby_Text_YourMonIsEntryNum4, MSGBOX_DEFAULT
# 204 "data/scripts/contest_hall.pory"
	closemessage
# 205 "data/scripts/contest_hall.pory"
	releaseall
# 206 "data/scripts/contest_hall.pory"
	setvar VAR_CONTEST_HALL_STATE, 1
# 207 "data/scripts/contest_hall.pory"
	return
# 208 "data/scripts/contest_hall.pory"

# 209 "data/scripts/contest_hall.pory"
ContestHall_EventScript_DoContest:: @ 8279F97
# 210 "data/scripts/contest_hall.pory"
	special LinkContestTryShowWirelessIndicator
# 211 "data/scripts/contest_hall.pory"
	setvar VAR_0x8006, 0
# 212 "data/scripts/contest_hall.pory"
	lockall
# 213 "data/scripts/contest_hall.pory"
	applymovement LOCALID_CONTESTANT_4, ContestHall_Movement_Player4FaceUp
# 214 "data/scripts/contest_hall.pory"
	waitmovement 0
# 215 "data/scripts/contest_hall.pory"
	applymovement LOCALID_MC, ContestHall_Movement_MCWalkDown
# 216 "data/scripts/contest_hall.pory"
	waitmovement 0
# 217 "data/scripts/contest_hall.pory"
	releaseall
# 218 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 219 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_GetContestRankStringId
# 220 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_GetContestCategory
# 221 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_ContestGettingStarted
# 222 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_ShowContestMons
# 223 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_DoContestAppeals
# 224 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_ContestResults
# 225 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_GetWinnerObjEventId
# 226 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_CongratulateWinner
# 227 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_AudienceLookAround
# 228 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_GiveWinnerPrize
# 229 "data/scripts/contest_hall.pory"
	setvar VAR_CONTEST_HALL_STATE, 2
# 230 "data/scripts/contest_hall.pory"
	return
# 231 "data/scripts/contest_hall.pory"

# 232 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetContestRankStringId:: @ 8279FF2
# 233 "data/scripts/contest_hall.pory"
	switch VAR_CONTEST_RANK
# 234 "data/scripts/contest_hall.pory"
	case CONTEST_RANK_NORMAL, ContestHall_EventScript_GetNormalStringId
# 235 "data/scripts/contest_hall.pory"
	case CONTEST_RANK_SUPER, ContestHall_EventScript_GetSuperStringId
# 236 "data/scripts/contest_hall.pory"
	case CONTEST_RANK_HYPER, ContestHall_EventScript_GetHyperStringId
# 237 "data/scripts/contest_hall.pory"
	case CONTEST_RANK_MASTER, ContestHall_EventScript_GetMasterStringId
# 238 "data/scripts/contest_hall.pory"
	return
# 239 "data/scripts/contest_hall.pory"

# 240 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetNormalStringId:: @ 827A024
# 241 "data/scripts/contest_hall.pory"
	setvar VAR_0x8009, STDSTRING_NORMAL
# 242 "data/scripts/contest_hall.pory"
	return
# 243 "data/scripts/contest_hall.pory"

# 244 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetSuperStringId:: @ 827A02A
# 245 "data/scripts/contest_hall.pory"
	setvar VAR_0x8009, STDSTRING_SUPER
# 246 "data/scripts/contest_hall.pory"
	return
# 247 "data/scripts/contest_hall.pory"

# 248 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetHyperStringId:: @ 827A030
# 249 "data/scripts/contest_hall.pory"
	setvar VAR_0x8009, STDSTRING_HYPER
# 250 "data/scripts/contest_hall.pory"
	return
# 251 "data/scripts/contest_hall.pory"

# 252 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetMasterStringId:: @ 827A036
# 253 "data/scripts/contest_hall.pory"
	setvar VAR_0x8009, STDSTRING_MASTER
# 254 "data/scripts/contest_hall.pory"
	return
# 255 "data/scripts/contest_hall.pory"

# 256 "data/scripts/contest_hall.pory"
@ This whole switch is equivalent to copyvar VAR_0x8008, VAR_CONTEST_CATEGORY
# 257 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetContestCategory:: @ 827A03C
# 258 "data/scripts/contest_hall.pory"
	switch VAR_CONTEST_CATEGORY
# 259 "data/scripts/contest_hall.pory"
	case CONTEST_CATEGORY_COOL, ContestHall_EventScript_GetCategoryCool
# 260 "data/scripts/contest_hall.pory"
	case CONTEST_CATEGORY_BEAUTY, ContestHall_EventScript_GetCategoryBeauty
# 261 "data/scripts/contest_hall.pory"
	case CONTEST_CATEGORY_CUTE, ContestHall_EventScript_GetCategoryCute
# 262 "data/scripts/contest_hall.pory"
	case CONTEST_CATEGORY_SMART, ContestHall_EventScript_GetCategorySmart
# 263 "data/scripts/contest_hall.pory"
	case CONTEST_CATEGORY_TOUGH, ContestHall_EventScript_GetCategoryTough
# 264 "data/scripts/contest_hall.pory"
	return
# 265 "data/scripts/contest_hall.pory"

# 266 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetCategoryCool:: @ 827A079
# 267 "data/scripts/contest_hall.pory"
	setvar VAR_0x8008, CONTEST_CATEGORY_COOL
# 268 "data/scripts/contest_hall.pory"
	return
# 269 "data/scripts/contest_hall.pory"

# 270 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetCategoryBeauty:: @ 827A07F
# 271 "data/scripts/contest_hall.pory"
	setvar VAR_0x8008, CONTEST_CATEGORY_BEAUTY
# 272 "data/scripts/contest_hall.pory"
	return
# 273 "data/scripts/contest_hall.pory"

# 274 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetCategoryCute:: @ 827A085
# 275 "data/scripts/contest_hall.pory"
	setvar VAR_0x8008, CONTEST_CATEGORY_CUTE
# 276 "data/scripts/contest_hall.pory"
	return
# 277 "data/scripts/contest_hall.pory"

# 278 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetCategorySmart:: @ 827A08B
# 279 "data/scripts/contest_hall.pory"
	setvar VAR_0x8008, CONTEST_CATEGORY_SMART
# 280 "data/scripts/contest_hall.pory"
	return
# 281 "data/scripts/contest_hall.pory"

# 282 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetCategoryTough:: @ 827A091
# 283 "data/scripts/contest_hall.pory"
	setvar VAR_0x8008, CONTEST_CATEGORY_TOUGH
# 284 "data/scripts/contest_hall.pory"
	return
# 285 "data/scripts/contest_hall.pory"

# 286 "data/scripts/contest_hall.pory"
ContestHall_EventScript_ContestGettingStarted:: @ 827A097
# 287 "data/scripts/contest_hall.pory"
	buffercontesttypestring 1, VAR_0x8008
# 288 "data/scripts/contest_hall.pory"
	bufferstdstring 2, VAR_0x8009
# 289 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_GettingStarted
# 290 "data/scripts/contest_hall.pory"
	lockall
# 291 "data/scripts/contest_hall.pory"
	applymovement LOCALID_MC, ContestHall_Movement_MCBackUp
# 292 "data/scripts/contest_hall.pory"
	waitmovement 0
# 293 "data/scripts/contest_hall.pory"
	releaseall
# 294 "data/scripts/contest_hall.pory"
	return
# 295 "data/scripts/contest_hall.pory"

# 296 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GettingStarted:: @ 827A0B1
# 297 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
# 298 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_GettingStartedLink
# 299 "data/scripts/contest_hall.pory"
	lockall
# 300 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_GettingStartedParticipantsAsFollows, MSGBOX_DEFAULT
# 301 "data/scripts/contest_hall.pory"
	releaseall
# 302 "data/scripts/contest_hall.pory"
	return
# 303 "data/scripts/contest_hall.pory"

# 304 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GettingStartedLink:: @ 827A0C7
# 305 "data/scripts/contest_hall.pory"
	specialvar VAR_RESULT, IsWirelessContest
# 306 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, TRUE
# 307 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_GettingStartedWireless
# 308 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_GettingStartedParticipantsAsFollowsLink
# 309 "data/scripts/contest_hall.pory"
	waitmessage
# 310 "data/scripts/contest_hall.pory"
	return
# 311 "data/scripts/contest_hall.pory"

# 312 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GettingStartedWireless:: @ 827A0DE
# 313 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_GettingStartedWireless
# 314 "data/scripts/contest_hall.pory"
	waitmessage
# 315 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 316 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_ParticipantsAsFollows
# 317 "data/scripts/contest_hall.pory"
	waitmessage
# 318 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 319 "data/scripts/contest_hall.pory"
	return
# 320 "data/scripts/contest_hall.pory"

# 321 "data/scripts/contest_hall.pory"
ContestHall_EventScript_ShowContestMons:: @ 827A0F5
# 322 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_ContestantWalkToCenter
# 323 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_ShowContestMonPic
# 324 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_AudienceHeartEmotes
# 325 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_AudienceReactToContestant
# 326 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_ContestantReturn
# 327 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 328 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 329 "data/scripts/contest_hall.pory"
	addvar VAR_0x8006, 1
# 330 "data/scripts/contest_hall.pory"
	compare VAR_0x8006, CONTESTANT_COUNT
# 331 "data/scripts/contest_hall.pory"
	goto_if_ne ContestHall_EventScript_ShowContestMons
# 332 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_AudienceVote
# 333 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_1, 6
# 334 "data/scripts/contest_hall.pory"
	return
# 335 "data/scripts/contest_hall.pory"

# 336 "data/scripts/contest_hall.pory"
ContestHall_EventScript_TryWaitForLink:: @ 827A133
# 337 "data/scripts/contest_hall.pory"
	specialvar VAR_RESULT, IsWirelessContest
# 338 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, TRUE
# 339 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_WaitForLink
# 340 "data/scripts/contest_hall.pory"
	return
# 341 "data/scripts/contest_hall.pory"

# 342 "data/scripts/contest_hall.pory"
ContestHall_EventScript_WaitForLink:: @ 827A144
# 343 "data/scripts/contest_hall.pory"
	special LinkContestWaitForConnection
# 344 "data/scripts/contest_hall.pory"
	waitstate
# 345 "data/scripts/contest_hall.pory"
	return
# 346 "data/scripts/contest_hall.pory"

# 347 "data/scripts/contest_hall.pory"
ContestHall_EventScript_ContestantWalkToCenter:: @ 827A149
# 348 "data/scripts/contest_hall.pory"
	compare VAR_0x8006, 0
# 349 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_Player1WalkToCenter
# 350 "data/scripts/contest_hall.pory"
	compare VAR_0x8006, 1
# 351 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_Player2WalkToCenter
# 352 "data/scripts/contest_hall.pory"
	compare VAR_0x8006, 2
# 353 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_Player3WalkToCenter
# 354 "data/scripts/contest_hall.pory"
	compare VAR_0x8006, 3
# 355 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_Player4WalkToCenter
# 356 "data/scripts/contest_hall.pory"
	return
# 357 "data/scripts/contest_hall.pory"

# 358 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Player1WalkToCenter:: @ 827A176
# 359 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 360 "data/scripts/contest_hall.pory"
	lockall
# 361 "data/scripts/contest_hall.pory"
	applymovement LOCALID_CONTESTANT_1, ContestHall_Movement_Player1WalkToCenter
# 362 "data/scripts/contest_hall.pory"
	waitmovement 0
# 363 "data/scripts/contest_hall.pory"
	releaseall
# 364 "data/scripts/contest_hall.pory"
	setvar VAR_0x800B, LOCALID_CONTESTANT_1
# 365 "data/scripts/contest_hall.pory"
	return
# 366 "data/scripts/contest_hall.pory"

# 367 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Player2WalkToCenter:: @ 827A18D
# 368 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 369 "data/scripts/contest_hall.pory"
	lockall
# 370 "data/scripts/contest_hall.pory"
	applymovement LOCALID_CONTESTANT_2, ContestHall_Movement_Player2WalkToCenter
# 371 "data/scripts/contest_hall.pory"
	waitmovement 0
# 372 "data/scripts/contest_hall.pory"
	releaseall
# 373 "data/scripts/contest_hall.pory"
	setvar VAR_0x800B, LOCALID_CONTESTANT_2
# 374 "data/scripts/contest_hall.pory"
	return
# 375 "data/scripts/contest_hall.pory"

# 376 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Player3WalkToCenter:: @ 827A1A4
# 377 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 378 "data/scripts/contest_hall.pory"
	lockall
# 379 "data/scripts/contest_hall.pory"
	applymovement LOCALID_CONTESTANT_3, ContestHall_Movement_Player3WalkToCenter
# 380 "data/scripts/contest_hall.pory"
	waitmovement 0
# 381 "data/scripts/contest_hall.pory"
	releaseall
# 382 "data/scripts/contest_hall.pory"
	setvar VAR_0x800B, LOCALID_CONTESTANT_3
# 383 "data/scripts/contest_hall.pory"
	return
# 384 "data/scripts/contest_hall.pory"

# 385 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Player4WalkToCenter:: @ 827A1BB
# 386 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 387 "data/scripts/contest_hall.pory"
	lockall
# 388 "data/scripts/contest_hall.pory"
	applymovement LOCALID_CONTESTANT_4, ContestHall_Movement_Player4WalkToCenter
# 389 "data/scripts/contest_hall.pory"
	waitmovement 0
# 390 "data/scripts/contest_hall.pory"
	releaseall
# 391 "data/scripts/contest_hall.pory"
	setvar VAR_0x800B, LOCALID_CONTESTANT_4
# 392 "data/scripts/contest_hall.pory"
	return
# 393 "data/scripts/contest_hall.pory"

# 394 "data/scripts/contest_hall.pory"
ContestHall_EventScript_ShowContestMonPic:: @ 827A1D2
# 395 "data/scripts/contest_hall.pory"
	special BufferContestTrainerAndMonNames
# 396 "data/scripts/contest_hall.pory"
	addvar VAR_0x8006, 1
# 397 "data/scripts/contest_hall.pory"
	buffernumberstring 1, VAR_0x8006
# 398 "data/scripts/contest_hall.pory"
	lockall
# 399 "data/scripts/contest_hall.pory"
	applymovement VAR_0x800B, ContestHall_Movement_ContestantDelay32
# 400 "data/scripts/contest_hall.pory"
	waitmovement 0
# 401 "data/scripts/contest_hall.pory"
	releaseall
# 402 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 403 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_CheckIfContestWithRSPlayer
# 404 "data/scripts/contest_hall.pory"
	addobject LOCALID_POKEBALL
# 405 "data/scripts/contest_hall.pory"
	playse SE_LEDGE
# 406 "data/scripts/contest_hall.pory"
	lockall
# 407 "data/scripts/contest_hall.pory"
	applymovement VAR_0x800B, ContestHall_Movement_ContestantDelay32
# 408 "data/scripts/contest_hall.pory"
	waitmovement 0
# 409 "data/scripts/contest_hall.pory"
	releaseall
# 410 "data/scripts/contest_hall.pory"
	addvar VAR_0x8006, -1
# 411 "data/scripts/contest_hall.pory"
	playse SE_BALL_OPEN
# 412 "data/scripts/contest_hall.pory"
	special ShowContestEntryMonPic
# 413 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_EntryXTrainersMon
# 414 "data/scripts/contest_hall.pory"
	return
# 415 "data/scripts/contest_hall.pory"

# 416 "data/scripts/contest_hall.pory"
ContestHall_EventScript_EntryXTrainersMon:: @ 827A217
# 417 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
# 418 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_EntryXTrainersMonLink
# 419 "data/scripts/contest_hall.pory"
	message ContestHall_Text_EntryXTrainersMon
# 420 "data/scripts/contest_hall.pory"
	waitmessage
# 421 "data/scripts/contest_hall.pory"
	return
# 422 "data/scripts/contest_hall.pory"

# 423 "data/scripts/contest_hall.pory"
ContestHall_EventScript_EntryXTrainersMonLink:: @ 827A229
# 424 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_EntryXTrainersMon
# 425 "data/scripts/contest_hall.pory"
	waitmessage
# 426 "data/scripts/contest_hall.pory"
	return
# 427 "data/scripts/contest_hall.pory"

# 428 "data/scripts/contest_hall.pory"
ContestHall_EventScript_AudienceVote:: @ 827A230
# 429 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_AudienceWillVote
# 430 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_VotingUnderWay
# 431 "data/scripts/contest_hall.pory"
	playse SE_M_ENCORE2
# 432 "data/scripts/contest_hall.pory"
	waitmessage
# 433 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_AudienceLookAround
# 434 "data/scripts/contest_hall.pory"
	applymovement LOCALID_MC, ContestHall_Movement_MCFaceJudge2
# 435 "data/scripts/contest_hall.pory"
	waitmovement 0
# 436 "data/scripts/contest_hall.pory"
	applymovement LOCALID_JUDGE, ContestHall_Movement_JudgeFaceMC
# 437 "data/scripts/contest_hall.pory"
	waitmovement 0
# 438 "data/scripts/contest_hall.pory"
	delay 20
# 439 "data/scripts/contest_hall.pory"
	applymovement LOCALID_MC, ContestHall_Movement_FaceContestants
# 440 "data/scripts/contest_hall.pory"
	applymovement LOCALID_JUDGE, ContestHall_Movement_FaceContestants
# 441 "data/scripts/contest_hall.pory"
	waitmovement 0
# 442 "data/scripts/contest_hall.pory"
	return
# 443 "data/scripts/contest_hall.pory"

# 444 "data/scripts/contest_hall.pory"
ContestHall_EventScript_AudienceWillVote:: @ 827A26C
# 445 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
# 446 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_AudienceWillVoteLink
# 447 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_SeenContestantsAudienceWillVote, MSGBOX_DEFAULT
# 448 "data/scripts/contest_hall.pory"
	return
# 449 "data/scripts/contest_hall.pory"

# 450 "data/scripts/contest_hall.pory"
ContestHall_EventScript_AudienceWillVoteLink:: @ 827A280
# 451 "data/scripts/contest_hall.pory"
	specialvar VAR_RESULT, IsWirelessContest
# 452 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, TRUE
# 453 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_AudienceWillVoteWireless
# 454 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_SeenContestantsAudienceWillVote
# 455 "data/scripts/contest_hall.pory"
	waitmessage
# 456 "data/scripts/contest_hall.pory"
	return
# 457 "data/scripts/contest_hall.pory"

# 458 "data/scripts/contest_hall.pory"
ContestHall_EventScript_AudienceWillVoteWireless:: @ 827A297
# 459 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_WeveSeenContestants
# 460 "data/scripts/contest_hall.pory"
	waitmessage
# 461 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 462 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_AudienceWillVote
# 463 "data/scripts/contest_hall.pory"
	waitmessage
# 464 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 465 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_LetVotingBegin
# 466 "data/scripts/contest_hall.pory"
	waitmessage
# 467 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 468 "data/scripts/contest_hall.pory"
	return
# 469 "data/scripts/contest_hall.pory"

# 470 "data/scripts/contest_hall.pory"
ContestHall_EventScript_VotingUnderWay:: @ 827A2B9
# 471 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
# 472 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_VotingUnderWayLink
# 473 "data/scripts/contest_hall.pory"
	message ContestHall_Text_VotingUnderWay
# 474 "data/scripts/contest_hall.pory"
	return
# 475 "data/scripts/contest_hall.pory"

# 476 "data/scripts/contest_hall.pory"
ContestHall_EventScript_VotingUnderWayLink:: @ 827A2CA
# 477 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_VotingUnderWay
# 478 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 479 "data/scripts/contest_hall.pory"
	return
# 480 "data/scripts/contest_hall.pory"

# 481 "data/scripts/contest_hall.pory"
ContestHall_EventScript_AudienceReactToContestant:: @ 827A2D5
# 482 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 483 "data/scripts/contest_hall.pory"
	applymovement LOCALID_MC, ContestHall_Movement_AudienceMemberLookLeft
# 484 "data/scripts/contest_hall.pory"
	waitmovement 0
# 485 "data/scripts/contest_hall.pory"
	playse SE_M_ENCORE2
# 486 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_VObjectAudienceLookAround
# 487 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_5, ContestHall_Movement_AudienceMemberLookRight
# 488 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_2, ContestHall_Movement_AudienceMemberLookDown
# 489 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_3, ContestHall_Movement_AudienceMemberLookRight
# 490 "data/scripts/contest_hall.pory"
	waitmovement 0
# 491 "data/scripts/contest_hall.pory"
	applymovement LOCALID_MC, ContestHall_Movement_AudienceMemberLookRight
# 492 "data/scripts/contest_hall.pory"
	waitmovement 0
# 493 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_6, ContestHall_Movement_AudienceMemberLookLeft
# 494 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_7, ContestHall_Movement_AudienceMemberLookDown
# 495 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_1, ContestHall_Movement_AudienceMemberLookUp
# 496 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_4, ContestHall_Movement_AudienceMemberLookLeft
# 497 "data/scripts/contest_hall.pory"
	waitmovement 0
# 498 "data/scripts/contest_hall.pory"
	applymovement LOCALID_MC, ContestHall_Movement_MCLookAtJudge
# 499 "data/scripts/contest_hall.pory"
	waitmovement 0
# 500 "data/scripts/contest_hall.pory"
	applymovement LOCALID_MC, ContestHall_Movement_MCWalkInPlaceDown
# 501 "data/scripts/contest_hall.pory"
	applymovement LOCALID_JUDGE, ContestHall_Movement_JudgeLookAtMC
# 502 "data/scripts/contest_hall.pory"
	waitmovement 0
# 503 "data/scripts/contest_hall.pory"
	releaseall
# 504 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 505 "data/scripts/contest_hall.pory"
	return
# 506 "data/scripts/contest_hall.pory"

# 507 "data/scripts/contest_hall.pory"
@ For below VAR_TEMP_0 is the number of heart emotes to try to display in the audience
# 508 "data/scripts/contest_hall.pory"
@ The number of hearts to try to display is based on the condition of the presented pokemon and the rank
# 509 "data/scripts/contest_hall.pory"
@ For each heart to display a random audience member is chosen, and a new one chosen if they already displayed a heart
# 510 "data/scripts/contest_hall.pory"
@ VAR_TEMP_1 through VAR_TEMP_8 represent each of the 8 audience members that are actual object events
# 511 "data/scripts/contest_hall.pory"
@    and are set to 9 if they havent displayed a heart yet, and 1 if they have
# 512 "data/scripts/contest_hall.pory"
ContestHall_EventScript_AudienceHeartEmotes:: @ 827A34F
# 513 "data/scripts/contest_hall.pory"
	special GetContestMonCondition
# 514 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL
# 515 "data/scripts/contest_hall.pory"
	call_if_eq ContestHall_EventScript_GetNumberOfHeartsNormal
# 516 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER
# 517 "data/scripts/contest_hall.pory"
	call_if_eq ContestHall_EventScript_GetNumberOfHeartsSuper
# 518 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_HYPER
# 519 "data/scripts/contest_hall.pory"
	call_if_eq ContestHall_EventScript_GetNumberOfHeartsHyper
# 520 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_MASTER
# 521 "data/scripts/contest_hall.pory"
	call_if_eq ContestHall_EventScript_GetNumberOfHeartsMaster
# 522 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
# 523 "data/scripts/contest_hall.pory"
	call_if_eq ContestHall_EventScript_GetNumberOfHeartsLink
# 524 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_1, 9
# 525 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_2, 9
# 526 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_3, 9
# 527 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_4, 9
# 528 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_5, 9
# 529 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_6, 9
# 530 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_7, 9
# 531 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_8, 9
# 532 "data/scripts/contest_hall.pory"
	compare VAR_TEMP_0, 0
# 533 "data/scripts/contest_hall.pory"
	call_if_gt ContestHall_EventScript_DisplayHearts
# 534 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_1, 0
# 535 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_2, 0
# 536 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_3, 0
# 537 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_4, 0
# 538 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_5, 0
# 539 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_6, 0
# 540 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_7, 0
# 541 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_8, 0
# 542 "data/scripts/contest_hall.pory"
	return
# 543 "data/scripts/contest_hall.pory"

# 544 "data/scripts/contest_hall.pory"
ContestHall_EventScript_DisplayHearts:: @ 827A3E5
# 545 "data/scripts/contest_hall.pory"
	setvar VAR_RESULT, 8
# 546 "data/scripts/contest_hall.pory"
	special GenerateContestRand
# 547 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, 0
# 548 "data/scripts/contest_hall.pory"
	call_if_eq ContestHall_EventScript_TryDisplayHeartAudienceMember1
# 549 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, 1
# 550 "data/scripts/contest_hall.pory"
	call_if_eq ContestHall_EventScript_TryDisplayHeartAudienceMember2
# 551 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, 2
# 552 "data/scripts/contest_hall.pory"
	call_if_eq ContestHall_EventScript_TryDisplayHeartAudienceMember3
# 553 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, 3
# 554 "data/scripts/contest_hall.pory"
	call_if_eq ContestHall_EventScript_TryDisplayHeartAudienceMember4
# 555 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, 4
# 556 "data/scripts/contest_hall.pory"
	call_if_eq ContestHall_EventScript_TryDisplayHeartAudienceMember5
# 557 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, 5
# 558 "data/scripts/contest_hall.pory"
	call_if_eq ContestHall_EventScript_TryDisplayHeartAudienceMember6
# 559 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, 6
# 560 "data/scripts/contest_hall.pory"
	call_if_eq ContestHall_EventScript_TryDisplayHeartAudienceMember7
# 561 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, 7
# 562 "data/scripts/contest_hall.pory"
	call_if_eq ContestHall_EventScript_TryDisplayHeartAudienceMember8
# 563 "data/scripts/contest_hall.pory"
	compare VAR_TEMP_0, 0  @ Still more hearts to display
# 564 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_DisplayHearts
# 565 "data/scripts/contest_hall.pory"
	waitmovement 0
# 566 "data/scripts/contest_hall.pory"
	return
# 567 "data/scripts/contest_hall.pory"

# 568 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetNumberOfHeartsNormal:: @ 827A454
# 569 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 80
# 570 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set8Hearts
# 571 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 70
# 572 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set7Hearts
# 573 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 60
# 574 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set6Hearts
# 575 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 50
# 576 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set5Hearts
# 577 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 40
# 578 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set4Hearts
# 579 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 30
# 580 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set3Hearts
# 581 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 20
# 582 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set2Hearts
# 583 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 10
# 584 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set1Heart
# 585 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_0, 0
# 586 "data/scripts/contest_hall.pory"
	return
# 587 "data/scripts/contest_hall.pory"

# 588 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetNumberOfHeartsSuper:: @ 827A4B2
# 589 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 230
# 590 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set8Hearts
# 591 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 210
# 592 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set7Hearts
# 593 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 190
# 594 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set6Hearts
# 595 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 170
# 596 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set5Hearts
# 597 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 150
# 598 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set4Hearts
# 599 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 130
# 600 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set3Hearts
# 601 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 110
# 602 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set2Hearts
# 603 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 90
# 604 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set1Heart
# 605 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_0, 0
# 606 "data/scripts/contest_hall.pory"
	return
# 607 "data/scripts/contest_hall.pory"

# 608 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetNumberOfHeartsHyper:: @ 827A510
# 609 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 380
# 610 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set8Hearts
# 611 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 350
# 612 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set7Hearts
# 613 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 320
# 614 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set6Hearts
# 615 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 290
# 616 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set5Hearts
# 617 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 260
# 618 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set4Hearts
# 619 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 230
# 620 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set3Hearts
# 621 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 200
# 622 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set2Hearts
# 623 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 170
# 624 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set1Heart
# 625 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_0, 0
# 626 "data/scripts/contest_hall.pory"
	return
# 627 "data/scripts/contest_hall.pory"

# 628 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetNumberOfHeartsMaster:: @ 827A56E
# 629 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 600
# 630 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set8Hearts
# 631 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 560
# 632 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set7Hearts
# 633 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 520
# 634 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set6Hearts
# 635 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 480
# 636 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set5Hearts
# 637 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 440
# 638 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set4Hearts
# 639 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 400
# 640 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set3Hearts
# 641 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 360
# 642 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set2Hearts
# 643 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 320
# 644 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set1Heart
# 645 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_0, 0
# 646 "data/scripts/contest_hall.pory"
	return
# 647 "data/scripts/contest_hall.pory"

# 648 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetNumberOfHeartsLink:: @ 827A5CC
# 649 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 600
# 650 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set8Hearts
# 651 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 550
# 652 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set7Hearts
# 653 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 500
# 654 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set6Hearts
# 655 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 450
# 656 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set5Hearts
# 657 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 400
# 658 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set4Hearts
# 659 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 300
# 660 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set3Hearts
# 661 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 200
# 662 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set2Hearts
# 663 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, 100
# 664 "data/scripts/contest_hall.pory"
	goto_if_gt ContestHall_EventScript_Set1Heart
# 665 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_0, 0
# 666 "data/scripts/contest_hall.pory"
	return
# 667 "data/scripts/contest_hall.pory"

# 668 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Set1Heart:: @ 827A62A
# 669 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_0, 1
# 670 "data/scripts/contest_hall.pory"
	return
# 671 "data/scripts/contest_hall.pory"

# 672 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Set2Hearts:: @ 827A630
# 673 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_0, 2
# 674 "data/scripts/contest_hall.pory"
	return
# 675 "data/scripts/contest_hall.pory"

# 676 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Set3Hearts:: @ 827A636
# 677 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_0, 3
# 678 "data/scripts/contest_hall.pory"
	return
# 679 "data/scripts/contest_hall.pory"

# 680 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Set4Hearts:: @ 827A63C
# 681 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_0, 4
# 682 "data/scripts/contest_hall.pory"
	return
# 683 "data/scripts/contest_hall.pory"

# 684 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Set5Hearts:: @ 827A642
# 685 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_0, 5
# 686 "data/scripts/contest_hall.pory"
	return
# 687 "data/scripts/contest_hall.pory"

# 688 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Set6Hearts:: @ 827A648
# 689 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_0, 6
# 690 "data/scripts/contest_hall.pory"
	return
# 691 "data/scripts/contest_hall.pory"

# 692 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Set7Hearts:: @ 827A64E
# 693 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_0, 7
# 694 "data/scripts/contest_hall.pory"
	return
# 695 "data/scripts/contest_hall.pory"

# 696 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Set8Hearts:: @ 827A654
# 697 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_0, 8
# 698 "data/scripts/contest_hall.pory"
	return
# 699 "data/scripts/contest_hall.pory"

# 700 "data/scripts/contest_hall.pory"
ContestHall_EventScript_TryDisplayHeartAudienceMember1:: @ 827A65A
# 701 "data/scripts/contest_hall.pory"
	compare VAR_TEMP_1, 1
# 702 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_AudienceMember1AlreadyEmoted
# 703 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_1, ContestHall_Movement_Heart
# 704 "data/scripts/contest_hall.pory"
	playse SE_PIN
# 705 "data/scripts/contest_hall.pory"
	delay 14
# 706 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_1, 1
# 707 "data/scripts/contest_hall.pory"
	addvar VAR_TEMP_0, -1
# 708 "data/scripts/contest_hall.pory"
	return
# 709 "data/scripts/contest_hall.pory"

# 710 "data/scripts/contest_hall.pory"
ContestHall_EventScript_AudienceMember1AlreadyEmoted:: @ 827A67D
# 711 "data/scripts/contest_hall.pory"
	return
# 712 "data/scripts/contest_hall.pory"

# 713 "data/scripts/contest_hall.pory"
ContestHall_EventScript_TryDisplayHeartAudienceMember2:: @ 827A67E
# 714 "data/scripts/contest_hall.pory"
	compare VAR_TEMP_2, 1
# 715 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_AudienceMember2AlreadyEmoted
# 716 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_2, ContestHall_Movement_Heart
# 717 "data/scripts/contest_hall.pory"
	playse SE_PIN
# 718 "data/scripts/contest_hall.pory"
	delay 14
# 719 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_2, 1
# 720 "data/scripts/contest_hall.pory"
	addvar VAR_TEMP_0, -1
# 721 "data/scripts/contest_hall.pory"
	return
# 722 "data/scripts/contest_hall.pory"

# 723 "data/scripts/contest_hall.pory"
ContestHall_EventScript_AudienceMember2AlreadyEmoted:: @ 827A6A1
# 724 "data/scripts/contest_hall.pory"
	return
# 725 "data/scripts/contest_hall.pory"

# 726 "data/scripts/contest_hall.pory"
ContestHall_EventScript_TryDisplayHeartAudienceMember3:: @ 827A6A2
# 727 "data/scripts/contest_hall.pory"
	compare VAR_TEMP_3, 1
# 728 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_AudienceMember3AlreadyEmoted
# 729 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_3, ContestHall_Movement_Heart
# 730 "data/scripts/contest_hall.pory"
	playse SE_PIN
# 731 "data/scripts/contest_hall.pory"
	delay 14
# 732 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_3, 1
# 733 "data/scripts/contest_hall.pory"
	addvar VAR_TEMP_0, -1
# 734 "data/scripts/contest_hall.pory"
	return
# 735 "data/scripts/contest_hall.pory"

# 736 "data/scripts/contest_hall.pory"
ContestHall_EventScript_AudienceMember3AlreadyEmoted:: @ 827A6C5
# 737 "data/scripts/contest_hall.pory"
	return
# 738 "data/scripts/contest_hall.pory"

# 739 "data/scripts/contest_hall.pory"
ContestHall_EventScript_TryDisplayHeartAudienceMember4:: @ 827A6C6
# 740 "data/scripts/contest_hall.pory"
	compare VAR_TEMP_4, 1
# 741 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_Audience4MemberAlreadyEmoted
# 742 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_4, ContestHall_Movement_Heart
# 743 "data/scripts/contest_hall.pory"
	playse SE_PIN
# 744 "data/scripts/contest_hall.pory"
	delay 14
# 745 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_4, 1
# 746 "data/scripts/contest_hall.pory"
	addvar VAR_TEMP_0, -1
# 747 "data/scripts/contest_hall.pory"
	return
# 748 "data/scripts/contest_hall.pory"

# 749 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Audience4MemberAlreadyEmoted:: @ 827A6E9
# 750 "data/scripts/contest_hall.pory"
	return
# 751 "data/scripts/contest_hall.pory"

# 752 "data/scripts/contest_hall.pory"
ContestHall_EventScript_TryDisplayHeartAudienceMember5:: @ 827A6EA
# 753 "data/scripts/contest_hall.pory"
	compare VAR_TEMP_5, 1
# 754 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_AudienceMember5AlreadyEmoted
# 755 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_5, ContestHall_Movement_Heart
# 756 "data/scripts/contest_hall.pory"
	playse SE_PIN
# 757 "data/scripts/contest_hall.pory"
	delay 14
# 758 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_5, 1
# 759 "data/scripts/contest_hall.pory"
	addvar VAR_TEMP_0, -1
# 760 "data/scripts/contest_hall.pory"
	return
# 761 "data/scripts/contest_hall.pory"

# 762 "data/scripts/contest_hall.pory"
ContestHall_EventScript_AudienceMember5AlreadyEmoted:: @ 827A70D
# 763 "data/scripts/contest_hall.pory"
	return
# 764 "data/scripts/contest_hall.pory"

# 765 "data/scripts/contest_hall.pory"
ContestHall_EventScript_TryDisplayHeartAudienceMember6:: @ 827A70E
# 766 "data/scripts/contest_hall.pory"
	compare VAR_TEMP_6, 1
# 767 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_AudienceMember6AlreadyEmoted
# 768 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_6, ContestHall_Movement_Heart
# 769 "data/scripts/contest_hall.pory"
	playse SE_PIN
# 770 "data/scripts/contest_hall.pory"
	delay 14
# 771 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_6, 1
# 772 "data/scripts/contest_hall.pory"
	addvar VAR_TEMP_0, -1
# 773 "data/scripts/contest_hall.pory"
	return
# 774 "data/scripts/contest_hall.pory"

# 775 "data/scripts/contest_hall.pory"
ContestHall_EventScript_AudienceMember6AlreadyEmoted:: @ 827A731
# 776 "data/scripts/contest_hall.pory"
	return
# 777 "data/scripts/contest_hall.pory"

# 778 "data/scripts/contest_hall.pory"
ContestHall_EventScript_TryDisplayHeartAudienceMember7:: @ 827A732
# 779 "data/scripts/contest_hall.pory"
	compare VAR_TEMP_7, 1
# 780 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_AudienceMember7AlreadyEmoted
# 781 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_7, ContestHall_Movement_Heart
# 782 "data/scripts/contest_hall.pory"
	playse SE_PIN
# 783 "data/scripts/contest_hall.pory"
	delay 14
# 784 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_7, 1
# 785 "data/scripts/contest_hall.pory"
	addvar VAR_TEMP_0, -1
# 786 "data/scripts/contest_hall.pory"
	return
# 787 "data/scripts/contest_hall.pory"

# 788 "data/scripts/contest_hall.pory"
ContestHall_EventScript_AudienceMember7AlreadyEmoted:: @ 827A755
# 789 "data/scripts/contest_hall.pory"
	return
# 790 "data/scripts/contest_hall.pory"

# 791 "data/scripts/contest_hall.pory"
ContestHall_EventScript_TryDisplayHeartAudienceMember8:: @ 827A756
# 792 "data/scripts/contest_hall.pory"
	compare VAR_TEMP_8, 1
# 793 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_AudienceMember8AlreadyEmoted
# 794 "data/scripts/contest_hall.pory"
	applymovement LOCALID_ARTIST, ContestHall_Movement_Heart
# 795 "data/scripts/contest_hall.pory"
	playse SE_PIN
# 796 "data/scripts/contest_hall.pory"
	delay 14
# 797 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_8, 1
# 798 "data/scripts/contest_hall.pory"
	addvar VAR_TEMP_0, -1
# 799 "data/scripts/contest_hall.pory"
	return
# 800 "data/scripts/contest_hall.pory"

# 801 "data/scripts/contest_hall.pory"
ContestHall_EventScript_AudienceMember8AlreadyEmoted:: @ 827A779
# 802 "data/scripts/contest_hall.pory"
	return
# 803 "data/scripts/contest_hall.pory"

# 804 "data/scripts/contest_hall.pory"
ContestHall_EventScript_ContestantReturn:: @ 827A77A
# 805 "data/scripts/contest_hall.pory"
	closemessage
# 806 "data/scripts/contest_hall.pory"
	release
# 807 "data/scripts/contest_hall.pory"
	removeobject LOCALID_POKEBALL
# 808 "data/scripts/contest_hall.pory"
	special HideContestEntryMonPic
# 809 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 810 "data/scripts/contest_hall.pory"
	switch VAR_0x8006
# 811 "data/scripts/contest_hall.pory"
	case 0, ContestHall_EventScript_Player1WalkBack
# 812 "data/scripts/contest_hall.pory"
	case 1, ContestHall_EventScript_Player2WalkBack
# 813 "data/scripts/contest_hall.pory"
	case 2, ContestHall_EventScript_Player3WalkBack
# 814 "data/scripts/contest_hall.pory"
	case 3, ContestHall_EventScript_Player4WalkBack
# 815 "data/scripts/contest_hall.pory"
	return
# 816 "data/scripts/contest_hall.pory"

# 817 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Player1WalkBack:: @ 827A7B9
# 818 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 819 "data/scripts/contest_hall.pory"
	lockall
# 820 "data/scripts/contest_hall.pory"
	applymovement VAR_0x800B, ContestHall_Movement_Player1WalkBack
# 821 "data/scripts/contest_hall.pory"
	waitmovement 0
# 822 "data/scripts/contest_hall.pory"
	releaseall
# 823 "data/scripts/contest_hall.pory"
	return
# 824 "data/scripts/contest_hall.pory"

# 825 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Player2WalkBack:: @ 827A7CB
# 826 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 827 "data/scripts/contest_hall.pory"
	lockall
# 828 "data/scripts/contest_hall.pory"
	applymovement VAR_0x800B, ContestHall_Movement_Player2WalkBack
# 829 "data/scripts/contest_hall.pory"
	waitmovement 0
# 830 "data/scripts/contest_hall.pory"
	releaseall
# 831 "data/scripts/contest_hall.pory"
	return
# 832 "data/scripts/contest_hall.pory"

# 833 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Player3WalkBack:: @ 827A7DD
# 834 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 835 "data/scripts/contest_hall.pory"
	lockall
# 836 "data/scripts/contest_hall.pory"
	applymovement VAR_0x800B, ContestHall_Movement_Player3WalkBack
# 837 "data/scripts/contest_hall.pory"
	waitmovement 0
# 838 "data/scripts/contest_hall.pory"
	releaseall
# 839 "data/scripts/contest_hall.pory"
	return
# 840 "data/scripts/contest_hall.pory"

# 841 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Player4WalkBack:: @ 827A7EF
# 842 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 843 "data/scripts/contest_hall.pory"
	lockall
# 844 "data/scripts/contest_hall.pory"
	applymovement VAR_0x800B, ContestHall_Movement_Player4WalkBack
# 845 "data/scripts/contest_hall.pory"
	waitmovement 0
# 846 "data/scripts/contest_hall.pory"
	releaseall
# 847 "data/scripts/contest_hall.pory"
	return
# 848 "data/scripts/contest_hall.pory"

# 849 "data/scripts/contest_hall.pory"
ContestHall_EventScript_DoContestAppeals:: @ 827A801
# 850 "data/scripts/contest_hall.pory"
	lockall
# 851 "data/scripts/contest_hall.pory"
	applymovement LOCALID_MC, ContestHall_Movement_FaceContestants2
# 852 "data/scripts/contest_hall.pory"
	waitmovement 0
# 853 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 854 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_LetsAppeal
# 855 "data/scripts/contest_hall.pory"
	waitmessage
# 856 "data/scripts/contest_hall.pory"
	applymovement LOCALID_MC, ContestHall_Movement_WalkStageLeft
# 857 "data/scripts/contest_hall.pory"
	applymovement LOCALID_JUDGE, ContestHall_Movement_WalkStageRight
# 858 "data/scripts/contest_hall.pory"
	waitmovement 0
# 859 "data/scripts/contest_hall.pory"
	releaseall
# 860 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 861 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_9, 1
# 862 "data/scripts/contest_hall.pory"
	special LinkContestTryHideWirelessIndicator
# 863 "data/scripts/contest_hall.pory"
	startcontest
# 864 "data/scripts/contest_hall.pory"
	special LinkContestTryShowWirelessIndicator
# 865 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_9, 0
# 866 "data/scripts/contest_hall.pory"
	lockall
# 867 "data/scripts/contest_hall.pory"
	applymovement LOCALID_MC, ContestHall_Movement_WalkStageRight
# 868 "data/scripts/contest_hall.pory"
	applymovement LOCALID_JUDGE, ContestHall_Movement_WalkStageLeft
# 869 "data/scripts/contest_hall.pory"
	waitmovement 0
# 870 "data/scripts/contest_hall.pory"
	releaseall
# 871 "data/scripts/contest_hall.pory"
	return
# 872 "data/scripts/contest_hall.pory"

# 873 "data/scripts/contest_hall.pory"
ContestHall_EventScript_LetsAppeal:: @ 827A853
# 874 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
# 875 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_LetsAppealLink
# 876 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_VotingCompleteLetsAppeal, MSGBOX_DEFAULT
# 877 "data/scripts/contest_hall.pory"
	return
# 878 "data/scripts/contest_hall.pory"

# 879 "data/scripts/contest_hall.pory"
ContestHall_EventScript_LetsAppealLink:: @ 827A867
# 880 "data/scripts/contest_hall.pory"
	specialvar VAR_RESULT, IsWirelessContest
# 881 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, TRUE
# 882 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_LetsAppealWireless
# 883 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_VotingCompleteLetsAppeal
# 884 "data/scripts/contest_hall.pory"
	waitmessage
# 885 "data/scripts/contest_hall.pory"
	return
# 886 "data/scripts/contest_hall.pory"

# 887 "data/scripts/contest_hall.pory"
ContestHall_EventScript_LetsAppealWireless:: @ 827A87E
# 888 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 889 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_VotingComplete
# 890 "data/scripts/contest_hall.pory"
	waitmessage
# 891 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 892 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_SecondStageOfJudging
# 893 "data/scripts/contest_hall.pory"
	waitmessage
# 894 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 895 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_LetsAppeal
# 896 "data/scripts/contest_hall.pory"
	waitmessage
# 897 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 898 "data/scripts/contest_hall.pory"
	return
# 899 "data/scripts/contest_hall.pory"

# 900 "data/scripts/contest_hall.pory"
ContestHall_EventScript_ContestResults:: @ 827A8A5
# 901 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 902 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_ThatsItForJudging
# 903 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 904 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_ThankYouForAppeals
# 905 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 906 "data/scripts/contest_hall.pory"
	applymovement LOCALID_MC, ContestHall_Movement_MCFaceJudge
# 907 "data/scripts/contest_hall.pory"
	waitmovement 0
# 908 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_JudgeLooksReady
# 909 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 910 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_WeWillDeclareWinner
# 911 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 912 "data/scripts/contest_hall.pory"
	applymovement LOCALID_MC, ContestHall_Movement_FaceContestants
# 913 "data/scripts/contest_hall.pory"
	waitmovement 0
# 914 "data/scripts/contest_hall.pory"
	closemessage
# 915 "data/scripts/contest_hall.pory"
	releaseall
# 916 "data/scripts/contest_hall.pory"
	special LinkContestTryHideWirelessIndicator
# 917 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_9, 1
# 918 "data/scripts/contest_hall.pory"
	showcontestresults
# 919 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_9, 0
# 920 "data/scripts/contest_hall.pory"
	playbgm MUS_CONTEST_WINNER, 0
# 921 "data/scripts/contest_hall.pory"
	return
# 922 "data/scripts/contest_hall.pory"

# 923 "data/scripts/contest_hall.pory"
ContestHall_EventScript_ThatsItForJudging:: @ 827A8FB
# 924 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
# 925 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_ThatsItForJudgingLink
# 926 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_ThatsItForJudging, MSGBOX_DEFAULT
# 927 "data/scripts/contest_hall.pory"
	return
# 928 "data/scripts/contest_hall.pory"

# 929 "data/scripts/contest_hall.pory"
ContestHall_EventScript_ThatsItForJudgingLink:: @ 827A90F
# 930 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 931 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_ThatsItForJudging
# 932 "data/scripts/contest_hall.pory"
	waitmessage
# 933 "data/scripts/contest_hall.pory"
	delay 30
# 934 "data/scripts/contest_hall.pory"
	return
# 935 "data/scripts/contest_hall.pory"

# 936 "data/scripts/contest_hall.pory"
ContestHall_EventScript_ThankYouForAppeals:: @ 827A91E
# 937 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
# 938 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_ThankYouForAppealsLink
# 939 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_ThankYouForAppeals, MSGBOX_DEFAULT
# 940 "data/scripts/contest_hall.pory"
	return
# 941 "data/scripts/contest_hall.pory"

# 942 "data/scripts/contest_hall.pory"
ContestHall_EventScript_ThankYouForAppealsLink:: @ 827A932
# 943 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 944 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_ThankYouForAppeals
# 945 "data/scripts/contest_hall.pory"
	waitmessage
# 946 "data/scripts/contest_hall.pory"
	delay 30
# 947 "data/scripts/contest_hall.pory"
	return
# 948 "data/scripts/contest_hall.pory"

# 949 "data/scripts/contest_hall.pory"
ContestHall_EventScript_JudgeLooksReady:: @ 827A941
# 950 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
# 951 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_JudgeLooksReadyLink
# 952 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_JudgeLooksReady, MSGBOX_DEFAULT
# 953 "data/scripts/contest_hall.pory"
	return
# 954 "data/scripts/contest_hall.pory"

# 955 "data/scripts/contest_hall.pory"
ContestHall_EventScript_JudgeLooksReadyLink:: @ 827A955
# 956 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 957 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_JudgeLooksReady
# 958 "data/scripts/contest_hall.pory"
	waitmessage
# 959 "data/scripts/contest_hall.pory"
	delay 30
# 960 "data/scripts/contest_hall.pory"
	return
# 961 "data/scripts/contest_hall.pory"

# 962 "data/scripts/contest_hall.pory"
ContestHall_EventScript_WeWillDeclareWinner:: @ 827A964
# 963 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
# 964 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_WeWillDeclareWinnerLink
# 965 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_WeWillNowDeclareWinner, MSGBOX_DEFAULT
# 966 "data/scripts/contest_hall.pory"
	return
# 967 "data/scripts/contest_hall.pory"

# 968 "data/scripts/contest_hall.pory"
ContestHall_EventScript_WeWillDeclareWinnerLink:: @ 827A978
# 969 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_TryWaitForLink
# 970 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_WeWillNowDeclareWinner
# 971 "data/scripts/contest_hall.pory"
	waitmessage
# 972 "data/scripts/contest_hall.pory"
	delay 30
# 973 "data/scripts/contest_hall.pory"
	return
# 974 "data/scripts/contest_hall.pory"

# 975 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetWinnerObjEventId:: @ 827A987
# 976 "data/scripts/contest_hall.pory"
	special GetContestWinnerId
# 977 "data/scripts/contest_hall.pory"
	switch VAR_0x8005
# 978 "data/scripts/contest_hall.pory"
	case 0, ContestHall_EventScript_GetPlayer1ObjEventId
# 979 "data/scripts/contest_hall.pory"
	case 1, ContestHall_EventScript_GetPlayer2ObjEventId
# 980 "data/scripts/contest_hall.pory"
	case 2, ContestHall_EventScript_GetPlayer3ObjEventId
# 981 "data/scripts/contest_hall.pory"
	case 3, ContestHall_EventScript_GetPlayer4ObjEventId
# 982 "data/scripts/contest_hall.pory"
	return
# 983 "data/scripts/contest_hall.pory"

# 984 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetPlayer1ObjEventId:: @ 827A9BC
# 985 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_1
# 986 "data/scripts/contest_hall.pory"
	return
# 987 "data/scripts/contest_hall.pory"

# 988 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetPlayer2ObjEventId:: @ 827A9C2
# 989 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_2
# 990 "data/scripts/contest_hall.pory"
	return
# 991 "data/scripts/contest_hall.pory"

# 992 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetPlayer3ObjEventId:: @ 827A9C8
# 993 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_3
# 994 "data/scripts/contest_hall.pory"
	return
# 995 "data/scripts/contest_hall.pory"

# 996 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GetPlayer4ObjEventId:: @ 827A9CE
# 997 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_3, LOCALID_CONTESTANT_4
# 998 "data/scripts/contest_hall.pory"
	return
# 999 "data/scripts/contest_hall.pory"

# 1000 "data/scripts/contest_hall.pory"
ContestHall_EventScript_CongratulateWinner:: @ 827A9D4
# 1001 "data/scripts/contest_hall.pory"
	special BufferContestWinnerTrainerName
# 1002 "data/scripts/contest_hall.pory"
	special BufferContestWinnerMonName
# 1003 "data/scripts/contest_hall.pory"
	addvar VAR_0x8005, 1
# 1004 "data/scripts/contest_hall.pory"
	buffernumberstring 1, VAR_0x8005
# 1005 "data/scripts/contest_hall.pory"
	addvar VAR_0x8005, -1
# 1006 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_CongratsWinner
# 1007 "data/scripts/contest_hall.pory"
	applymovement VAR_TEMP_3, ContestHall_Movement_WinningPlayerWalkUp
# 1008 "data/scripts/contest_hall.pory"
	waitmovement 0
# 1009 "data/scripts/contest_hall.pory"
	playse SE_M_ENCORE2
# 1010 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_1, 0
# 1011 "data/scripts/contest_hall.pory"
	return
# 1012 "data/scripts/contest_hall.pory"

# 1013 "data/scripts/contest_hall.pory"
ContestHall_EventScript_CongratsWinner:: @ 827AA00
# 1014 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
# 1015 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_CongratsWinnerLink
# 1016 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_CongratsTrainerXandMon, MSGBOX_DEFAULT
# 1017 "data/scripts/contest_hall.pory"
	return
# 1018 "data/scripts/contest_hall.pory"

# 1019 "data/scripts/contest_hall.pory"
ContestHall_EventScript_CongratsWinnerLink:: @ 827AA14
# 1020 "data/scripts/contest_hall.pory"
	messageautoscroll ContestHall_Text_CongratsTrainerXandMon
# 1021 "data/scripts/contest_hall.pory"
	waitmessage
# 1022 "data/scripts/contest_hall.pory"
	return
# 1023 "data/scripts/contest_hall.pory"

# 1024 "data/scripts/contest_hall.pory"
ContestHall_EventScript_AudienceLookAround:: @ 827AA1B
# 1025 "data/scripts/contest_hall.pory"
	addvar VAR_TEMP_1, 1
# 1026 "data/scripts/contest_hall.pory"
	lockall
# 1027 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL
# 1028 "data/scripts/contest_hall.pory"
	call_if_gt ContestHall_EventScript_VObjectAudienceLookAround
# 1029 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_5, ContestHall_Movement_AudienceMemberLookRight
# 1030 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_2, ContestHall_Movement_AudienceMemberLookDown
# 1031 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_3, ContestHall_Movement_AudienceMemberLookRight
# 1032 "data/scripts/contest_hall.pory"
	delay 30
# 1033 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_6, ContestHall_Movement_AudienceMemberLookLeft
# 1034 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_7, ContestHall_Movement_AudienceMemberLookDown
# 1035 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_1, ContestHall_Movement_AudienceMemberLookUp
# 1036 "data/scripts/contest_hall.pory"
	applymovement LOCALID_AUDIENCE_4, ContestHall_Movement_AudienceMemberLookLeft
# 1037 "data/scripts/contest_hall.pory"
	compare VAR_TEMP_1, 4
# 1038 "data/scripts/contest_hall.pory"
	goto_if_ne ContestHall_EventScript_AudienceLookAround
# 1039 "data/scripts/contest_hall.pory"
	delay 30
# 1040 "data/scripts/contest_hall.pory"
	return
# 1041 "data/scripts/contest_hall.pory"

# 1042 "data/scripts/contest_hall.pory"
ContestHall_EventScript_VObjectAudienceLookAround:: @ 827AA6F
# 1043 "data/scripts/contest_hall.pory"
	turnvobject 0, DIR_SOUTH
# 1044 "data/scripts/contest_hall.pory"
	turnvobject 2, DIR_SOUTH
# 1045 "data/scripts/contest_hall.pory"
	turnvobject 4, DIR_EAST
# 1046 "data/scripts/contest_hall.pory"
	turnvobject 6, DIR_SOUTH
# 1047 "data/scripts/contest_hall.pory"
	turnvobject 8, DIR_SOUTH
# 1048 "data/scripts/contest_hall.pory"
	turnvobject 10, DIR_SOUTH
# 1049 "data/scripts/contest_hall.pory"
	turnvobject 12, DIR_SOUTH
# 1050 "data/scripts/contest_hall.pory"
	turnvobject 14, DIR_SOUTH
# 1051 "data/scripts/contest_hall.pory"
	turnvobject 16, DIR_SOUTH
# 1052 "data/scripts/contest_hall.pory"
	turnvobject 18, DIR_SOUTH
# 1053 "data/scripts/contest_hall.pory"
	turnvobject 20, DIR_EAST
# 1054 "data/scripts/contest_hall.pory"
	turnvobject 22, DIR_EAST
# 1055 "data/scripts/contest_hall.pory"
	turnvobject 25, DIR_EAST
# 1056 "data/scripts/contest_hall.pory"
	turnvobject 27, DIR_WEST
# 1057 "data/scripts/contest_hall.pory"
	turnvobject 28, DIR_EAST
# 1058 "data/scripts/contest_hall.pory"
	delay 10
# 1059 "data/scripts/contest_hall.pory"
	turnvobject 0, DIR_EAST
# 1060 "data/scripts/contest_hall.pory"
	turnvobject 2, DIR_EAST
# 1061 "data/scripts/contest_hall.pory"
	turnvobject 4, DIR_EAST
# 1062 "data/scripts/contest_hall.pory"
	turnvobject 6, DIR_EAST
# 1063 "data/scripts/contest_hall.pory"
	turnvobject 8, DIR_EAST
# 1064 "data/scripts/contest_hall.pory"
	turnvobject 10, DIR_WEST
# 1065 "data/scripts/contest_hall.pory"
	turnvobject 12, DIR_WEST
# 1066 "data/scripts/contest_hall.pory"
	turnvobject 14, DIR_WEST
# 1067 "data/scripts/contest_hall.pory"
	turnvobject 16, DIR_WEST
# 1068 "data/scripts/contest_hall.pory"
	turnvobject 18, DIR_WEST
# 1069 "data/scripts/contest_hall.pory"
	turnvobject 20, DIR_SOUTH
# 1070 "data/scripts/contest_hall.pory"
	turnvobject 22, DIR_SOUTH
# 1071 "data/scripts/contest_hall.pory"
	turnvobject 25, DIR_NORTH
# 1072 "data/scripts/contest_hall.pory"
	turnvobject 27, DIR_NORTH
# 1073 "data/scripts/contest_hall.pory"
	turnvobject 28, DIR_NORTH
# 1074 "data/scripts/contest_hall.pory"
	delay 10
# 1075 "data/scripts/contest_hall.pory"
	turnvobject 1, DIR_NORTH
# 1076 "data/scripts/contest_hall.pory"
	turnvobject 3, DIR_NORTH
# 1077 "data/scripts/contest_hall.pory"
	turnvobject 5, DIR_NORTH
# 1078 "data/scripts/contest_hall.pory"
	turnvobject 7, DIR_NORTH
# 1079 "data/scripts/contest_hall.pory"
	turnvobject 9, DIR_EAST
# 1080 "data/scripts/contest_hall.pory"
	turnvobject 11, DIR_NORTH
# 1081 "data/scripts/contest_hall.pory"
	turnvobject 15, DIR_NORTH
# 1082 "data/scripts/contest_hall.pory"
	turnvobject 13, DIR_NORTH
# 1083 "data/scripts/contest_hall.pory"
	turnvobject 17, DIR_NORTH
# 1084 "data/scripts/contest_hall.pory"
	turnvobject 19, DIR_NORTH
# 1085 "data/scripts/contest_hall.pory"
	turnvobject 21, DIR_WEST
# 1086 "data/scripts/contest_hall.pory"
	turnvobject 23, DIR_WEST
# 1087 "data/scripts/contest_hall.pory"
	turnvobject 24, DIR_WEST
# 1088 "data/scripts/contest_hall.pory"
	turnvobject 26, DIR_EAST
# 1089 "data/scripts/contest_hall.pory"
	turnvobject 29, DIR_WEST
# 1090 "data/scripts/contest_hall.pory"
	turnvobject 30, DIR_WEST
# 1091 "data/scripts/contest_hall.pory"
	delay 10
# 1092 "data/scripts/contest_hall.pory"
	turnvobject 1, DIR_EAST
# 1093 "data/scripts/contest_hall.pory"
	turnvobject 3, DIR_EAST
# 1094 "data/scripts/contest_hall.pory"
	turnvobject 5, DIR_EAST
# 1095 "data/scripts/contest_hall.pory"
	turnvobject 7, DIR_EAST
# 1096 "data/scripts/contest_hall.pory"
	turnvobject 9, DIR_EAST
# 1097 "data/scripts/contest_hall.pory"
	turnvobject 11, DIR_WEST
# 1098 "data/scripts/contest_hall.pory"
	turnvobject 15, DIR_WEST
# 1099 "data/scripts/contest_hall.pory"
	turnvobject 13, DIR_WEST
# 1100 "data/scripts/contest_hall.pory"
	turnvobject 17, DIR_WEST
# 1101 "data/scripts/contest_hall.pory"
	turnvobject 19, DIR_WEST
# 1102 "data/scripts/contest_hall.pory"
	turnvobject 21, DIR_SOUTH
# 1103 "data/scripts/contest_hall.pory"
	turnvobject 23, DIR_SOUTH
# 1104 "data/scripts/contest_hall.pory"
	turnvobject 24, DIR_SOUTH
# 1105 "data/scripts/contest_hall.pory"
	turnvobject 26, DIR_NORTH
# 1106 "data/scripts/contest_hall.pory"
	turnvobject 29, DIR_NORTH
# 1107 "data/scripts/contest_hall.pory"
	turnvobject 30, DIR_NORTH
# 1108 "data/scripts/contest_hall.pory"
	delay 10
# 1109 "data/scripts/contest_hall.pory"
	return
# 1110 "data/scripts/contest_hall.pory"

# 1111 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GiveWinnerPrize:: @ 827AB36
# 1112 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
# 1113 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_EndLinkContest
# 1114 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_CheckShouldSkipPrize
# 1115 "data/scripts/contest_hall.pory"
	goto_if_set FLAG_TEMP_2, ContestHall_EventScript_SkipPrize
# 1116 "data/scripts/contest_hall.pory"
	lockall
# 1117 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_AcceptYourPrize, MSGBOX_DEFAULT
# 1118 "data/scripts/contest_hall.pory"
	releaseall
# 1119 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_WinnerApproachForPrize
# 1120 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_GivePrizeIfWinner
# 1121 "data/scripts/contest_hall.pory"
	playse SE_M_ENCORE2
# 1122 "data/scripts/contest_hall.pory"
	setvar VAR_TEMP_1, 0
# 1123 "data/scripts/contest_hall.pory"
	call ContestHall_EventScript_AudienceLookAround
# 1124 "data/scripts/contest_hall.pory"
	delay 30
# 1125 "data/scripts/contest_hall.pory"
	special ShouldReadyContestArtist
# 1126 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, TRUE
# 1127 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_SetReadyForContestArtist
# 1128 "data/scripts/contest_hall.pory"
	return
# 1129 "data/scripts/contest_hall.pory"

# 1130 "data/scripts/contest_hall.pory"
ContestHall_EventScript_SkipPrize:: @ 827AB82
# 1131 "data/scripts/contest_hall.pory"
	lockall
# 1132 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
# 1133 "data/scripts/contest_hall.pory"
	releaseall
# 1134 "data/scripts/contest_hall.pory"
	delay 90
# 1135 "data/scripts/contest_hall.pory"
	special ShouldReadyContestArtist
# 1136 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, TRUE
# 1137 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_SetReadyForContestArtist
# 1138 "data/scripts/contest_hall.pory"
	return
# 1139 "data/scripts/contest_hall.pory"

# 1140 "data/scripts/contest_hall.pory"
ContestHall_EventScript_CheckShouldSkipPrize:: @ 827AB9E
# 1141 "data/scripts/contest_hall.pory"
	specialvar VAR_RESULT, HasMonWonThisContestBefore
# 1142 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, TRUE
# 1143 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_CheckPlayerWon
# 1144 "data/scripts/contest_hall.pory"
	return
# 1145 "data/scripts/contest_hall.pory"

# 1146 "data/scripts/contest_hall.pory"
ContestHall_EventScript_CheckPlayerWon:: @ 827ABAF
# 1147 "data/scripts/contest_hall.pory"
	special GetContestWinnerId
# 1148 "data/scripts/contest_hall.pory"
	compare VAR_0x8005, 3
# 1149 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_CheckRankIsMaster
# 1150 "data/scripts/contest_hall.pory"
	return
# 1151 "data/scripts/contest_hall.pory"

# 1152 "data/scripts/contest_hall.pory"
ContestHall_EventScript_CheckRankIsMaster:: @ 827ABBE
# 1153 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_RANK, CONTEST_RANK_MASTER
# 1154 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_DontSkipPrize
# 1155 "data/scripts/contest_hall.pory"
	setflag FLAG_TEMP_2
# 1156 "data/scripts/contest_hall.pory"
	return
# 1157 "data/scripts/contest_hall.pory"

# 1158 "data/scripts/contest_hall.pory"
ContestHall_EventScript_DontSkipPrize:: @ 827ABCD
# 1159 "data/scripts/contest_hall.pory"
	return
# 1160 "data/scripts/contest_hall.pory"

# 1161 "data/scripts/contest_hall.pory"
@ This flag is never read
# 1162 "data/scripts/contest_hall.pory"
ContestHall_EventScript_SetSketchFlag:: @ 827ABCE
# 1163 "data/scripts/contest_hall.pory"
	setflag FLAG_CONTEST_SKETCH_CREATED
# 1164 "data/scripts/contest_hall.pory"
	return
# 1165 "data/scripts/contest_hall.pory"

# 1166 "data/scripts/contest_hall.pory"
ContestHall_EventScript_SetReadyForContestArtist:: @ 827ABD2
# 1167 "data/scripts/contest_hall.pory"
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1
# 1168 "data/scripts/contest_hall.pory"
	return
# 1169 "data/scripts/contest_hall.pory"

# 1170 "data/scripts/contest_hall.pory"
ContestHall_EventScript_EndLinkContest:: @ 827ABD8
# 1171 "data/scripts/contest_hall.pory"
	delay 60
# 1172 "data/scripts/contest_hall.pory"
	special GetContestPlayerId
# 1173 "data/scripts/contest_hall.pory"
	special GetContestWinnerId
# 1174 "data/scripts/contest_hall.pory"
	special ShouldReadyContestArtist
# 1175 "data/scripts/contest_hall.pory"
	compare VAR_0x8004, TRUE
# 1176 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_SetReadyForLinkContestArtist
# 1177 "data/scripts/contest_hall.pory"
	closemessage
# 1178 "data/scripts/contest_hall.pory"
	return
# 1179 "data/scripts/contest_hall.pory"

# 1180 "data/scripts/contest_hall.pory"
ContestHall_EventScript_SetReadyForLinkContestArtist:: @ 827ABF1
# 1181 "data/scripts/contest_hall.pory"
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 2
# 1182 "data/scripts/contest_hall.pory"
	return
# 1183 "data/scripts/contest_hall.pory"

# 1184 "data/scripts/contest_hall.pory"
@ Unused
# 1185 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Ret:: @ 827ABF7
# 1186 "data/scripts/contest_hall.pory"
	return
# 1187 "data/scripts/contest_hall.pory"

# 1188 "data/scripts/contest_hall.pory"
ContestHall_EventScript_WinnerApproachForPrize:: @ 827ABF8
# 1189 "data/scripts/contest_hall.pory"
	switch VAR_0x8005
# 1190 "data/scripts/contest_hall.pory"
	case 0, ContestHall_EventScript_Player1ApproachForPrize
# 1191 "data/scripts/contest_hall.pory"
	case 1, ContestHall_EventScript_Player2ApproachForPrize
# 1192 "data/scripts/contest_hall.pory"
	case 2, ContestHall_EventScript_Player3ApproachForPrize
# 1193 "data/scripts/contest_hall.pory"
	case 3, ContestHall_EventScript_Player4ApproachForPrize
# 1194 "data/scripts/contest_hall.pory"
	return
# 1195 "data/scripts/contest_hall.pory"

# 1196 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Player1ApproachForPrize:: @ 827AC2A
# 1197 "data/scripts/contest_hall.pory"
	lockall
# 1198 "data/scripts/contest_hall.pory"
	applymovement VAR_TEMP_3, ContestHall_Movement_Player1ApproachForPrize
# 1199 "data/scripts/contest_hall.pory"
	waitmovement 0
# 1200 "data/scripts/contest_hall.pory"
	releaseall
# 1201 "data/scripts/contest_hall.pory"
	return
# 1202 "data/scripts/contest_hall.pory"

# 1203 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Player2ApproachForPrize:: @ 827AC37
# 1204 "data/scripts/contest_hall.pory"
	lockall
# 1205 "data/scripts/contest_hall.pory"
	applymovement VAR_TEMP_3, ContestHall_Movement_Player2ApproachForPrize
# 1206 "data/scripts/contest_hall.pory"
	waitmovement 0
# 1207 "data/scripts/contest_hall.pory"
	releaseall
# 1208 "data/scripts/contest_hall.pory"
	return
# 1209 "data/scripts/contest_hall.pory"

# 1210 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Player3ApproachForPrize:: @ 827AC44
# 1211 "data/scripts/contest_hall.pory"
	lockall
# 1212 "data/scripts/contest_hall.pory"
	applymovement VAR_TEMP_3, ContestHall_Movement_Player3ApproachForPrize
# 1213 "data/scripts/contest_hall.pory"
	waitmovement 0
# 1214 "data/scripts/contest_hall.pory"
	releaseall
# 1215 "data/scripts/contest_hall.pory"
	return
# 1216 "data/scripts/contest_hall.pory"

# 1217 "data/scripts/contest_hall.pory"
ContestHall_EventScript_Player4ApproachForPrize:: @ 827AC51
# 1218 "data/scripts/contest_hall.pory"
	lockall
# 1219 "data/scripts/contest_hall.pory"
	applymovement VAR_TEMP_3, ContestHall_Movement_Player4ApproachForPrize
# 1220 "data/scripts/contest_hall.pory"
	waitmovement 0
# 1221 "data/scripts/contest_hall.pory"
	releaseall
# 1222 "data/scripts/contest_hall.pory"
	return
# 1223 "data/scripts/contest_hall.pory"

# 1224 "data/scripts/contest_hall.pory"
@ In NPC Contests, the player is always entry 4 (id number 3)
# 1225 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GivePrizeIfWinner:: @ 827AC5E
# 1226 "data/scripts/contest_hall.pory"
	special GetContestWinnerId
# 1227 "data/scripts/contest_hall.pory"
	compare VAR_0x8005, 3
# 1228 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_GiveContestPrizes
# 1229 "data/scripts/contest_hall.pory"
	lockall
# 1230 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
# 1231 "data/scripts/contest_hall.pory"
	releaseall
# 1232 "data/scripts/contest_hall.pory"
	return
# 1233 "data/scripts/contest_hall.pory"

# 1234 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GiveContestPrizes:: @ 827AC77
# 1235 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER
# 1236 "data/scripts/contest_hall.pory"
	call_if_eq ContestHall_EventScript_SetSketchFlag
# 1237 "data/scripts/contest_hall.pory"
	specialvar VAR_RESULT, HasMonWonThisContestBefore
# 1238 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, FALSE
# 1239 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_ReceiveContestRibbon
# 1240 "data/scripts/contest_hall.pory"
	compare VAR_CONTEST_RANK, CONTEST_RANK_MASTER
# 1241 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_GiveLuxuryBall
# 1242 "data/scripts/contest_hall.pory"
	lockall
# 1243 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
# 1244 "data/scripts/contest_hall.pory"
	releaseall
# 1245 "data/scripts/contest_hall.pory"
	return
# 1246 "data/scripts/contest_hall.pory"

# 1247 "data/scripts/contest_hall.pory"
ContestHall_EventScript_NoRoomForLuxuryBall:: @ 827ACA8
# 1248 "data/scripts/contest_hall.pory"
	lockall
# 1249 "data/scripts/contest_hall.pory"
	call Common_EventScript_BagIsFull
# 1250 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_PickUpPrizeAtCounterLater, MSGBOX_DEFAULT
# 1251 "data/scripts/contest_hall.pory"
	releaseall
# 1252 "data/scripts/contest_hall.pory"
	setvar VAR_CONTEST_PRIZE_PICKUP, 4
# 1253 "data/scripts/contest_hall.pory"
	return
# 1254 "data/scripts/contest_hall.pory"

# 1255 "data/scripts/contest_hall.pory"
ContestHall_EventScript_GiveLuxuryBall:: @ 827ACBD
# 1256 "data/scripts/contest_hall.pory"
	giveitem ITEM_LUXURY_BALL
# 1257 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, FALSE
# 1258 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_NoRoomForLuxuryBall
# 1259 "data/scripts/contest_hall.pory"
	lockall
# 1260 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_CongratsPleaseCompeteAgain, MSGBOX_DEFAULT
# 1261 "data/scripts/contest_hall.pory"
	releaseall
# 1262 "data/scripts/contest_hall.pory"
	return
# 1263 "data/scripts/contest_hall.pory"

# 1264 "data/scripts/contest_hall.pory"
ContestHall_EventScript_ReceiveContestRibbon:: @ 827ACDF
# 1265 "data/scripts/contest_hall.pory"
	special GiveMonContestRibbon
# 1266 "data/scripts/contest_hall.pory"
	incrementgamestat GAME_STAT_RECEIVED_RIBBONS
# 1267 "data/scripts/contest_hall.pory"
	setflag FLAG_SYS_RIBBON_GET
# 1268 "data/scripts/contest_hall.pory"
	lockall
# 1269 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_ConferRibbonAsPrize, MSGBOX_DEFAULT
# 1270 "data/scripts/contest_hall.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1271 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_ReceivedRibbon, MSGBOX_DEFAULT
# 1272 "data/scripts/contest_hall.pory"
	waitfanfare
# 1273 "data/scripts/contest_hall.pory"
	special BufferContestWinnerMonName
# 1274 "data/scripts/contest_hall.pory"
	msgbox ContestHall_Text_PutRibbonOnMon, MSGBOX_DEFAULT
# 1275 "data/scripts/contest_hall.pory"
	releaseall
# 1276 "data/scripts/contest_hall.pory"
	return
# 1277 "data/scripts/contest_hall.pory"

# 1278 "data/scripts/contest_hall.pory"
ContestHall_Movement_MCWalkDown: @ 827AD09
# 1279 "data/scripts/contest_hall.pory"
	walk_down
# 1280 "data/scripts/contest_hall.pory"
	step_end
# 1281 "data/scripts/contest_hall.pory"

# 1282 "data/scripts/contest_hall.pory"
ContestHall_Movement_MCBackUp: @ 827AD0B
# 1283 "data/scripts/contest_hall.pory"
	lock_facing_direction
# 1284 "data/scripts/contest_hall.pory"
	walk_up
# 1285 "data/scripts/contest_hall.pory"
	unlock_facing_direction
# 1286 "data/scripts/contest_hall.pory"
	step_end
# 1287 "data/scripts/contest_hall.pory"

# 1288 "data/scripts/contest_hall.pory"
ContestHall_Movement_MCFaceJudge: @ 827AD0F
# 1289 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_right
# 1290 "data/scripts/contest_hall.pory"
	step_end
# 1291 "data/scripts/contest_hall.pory"

# 1292 "data/scripts/contest_hall.pory"
ContestHall_Movement_Heart: @ 827AD11
# 1293 "data/scripts/contest_hall.pory"
	emote_heart
# 1294 "data/scripts/contest_hall.pory"
	step_end
# 1295 "data/scripts/contest_hall.pory"

# 1296 "data/scripts/contest_hall.pory"
ContestHall_Movement_FaceContestants: @ 827AD13
# 1297 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_down
# 1298 "data/scripts/contest_hall.pory"
	step_end
# 1299 "data/scripts/contest_hall.pory"

# 1300 "data/scripts/contest_hall.pory"
ContestHall_Movement_WalkStageLeft: @ 827AD15
# 1301 "data/scripts/contest_hall.pory"
	walk_left
# 1302 "data/scripts/contest_hall.pory"
	walk_left
# 1303 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_down
# 1304 "data/scripts/contest_hall.pory"
	step_end
# 1305 "data/scripts/contest_hall.pory"

# 1306 "data/scripts/contest_hall.pory"
ContestHall_Movement_WalkStageRight: @ 827AD19
# 1307 "data/scripts/contest_hall.pory"
	walk_right
# 1308 "data/scripts/contest_hall.pory"
	walk_right
# 1309 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_down
# 1310 "data/scripts/contest_hall.pory"
	step_end
# 1311 "data/scripts/contest_hall.pory"

# 1312 "data/scripts/contest_hall.pory"
ContestHall_Movement_WinningPlayerWalkUp: @ 827AD1D
# 1313 "data/scripts/contest_hall.pory"
	walk_up
# 1314 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_down
# 1315 "data/scripts/contest_hall.pory"
	step_end
# 1316 "data/scripts/contest_hall.pory"

# 1317 "data/scripts/contest_hall.pory"
ContestHall_Movement_ContestantDelay32: @ 827AD20
# 1318 "data/scripts/contest_hall.pory"
	delay_16
# 1319 "data/scripts/contest_hall.pory"
	delay_16
# 1320 "data/scripts/contest_hall.pory"
	step_end
# 1321 "data/scripts/contest_hall.pory"

# 1322 "data/scripts/contest_hall.pory"
ContestHall_Movement_MCFaceJudge2: @ 827AD23
# 1323 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_right
# 1324 "data/scripts/contest_hall.pory"
	step_end
# 1325 "data/scripts/contest_hall.pory"

# 1326 "data/scripts/contest_hall.pory"
ContestHall_Movement_JudgeFaceMC: @ 827AD25
# 1327 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_left
# 1328 "data/scripts/contest_hall.pory"
	step_end
# 1329 "data/scripts/contest_hall.pory"

# 1330 "data/scripts/contest_hall.pory"
ContestHall_Movement_FaceContestants2: @ 827AD27
# 1331 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_down
# 1332 "data/scripts/contest_hall.pory"
	step_end
# 1333 "data/scripts/contest_hall.pory"

# 1334 "data/scripts/contest_hall.pory"
ContestHall_Movement_Player3ApproachForPrize: @ 827AD29
# 1335 "data/scripts/contest_hall.pory"
	walk_left
# 1336 "data/scripts/contest_hall.pory"
	walk_left
# 1337 "data/scripts/contest_hall.pory"
	walk_up
# 1338 "data/scripts/contest_hall.pory"
	step_end
# 1339 "data/scripts/contest_hall.pory"

# 1340 "data/scripts/contest_hall.pory"
ContestHall_Movement_Player4ApproachForPrize: @ 827AD2D
# 1341 "data/scripts/contest_hall.pory"
	walk_left
# 1342 "data/scripts/contest_hall.pory"
	walk_left
# 1343 "data/scripts/contest_hall.pory"
	walk_left
# 1344 "data/scripts/contest_hall.pory"
	walk_left
# 1345 "data/scripts/contest_hall.pory"
	walk_up
# 1346 "data/scripts/contest_hall.pory"
	step_end
# 1347 "data/scripts/contest_hall.pory"

# 1348 "data/scripts/contest_hall.pory"
ContestHall_Movement_AudienceMemberLookLeft: @ 827AD33
# 1349 "data/scripts/contest_hall.pory"
	face_left
# 1350 "data/scripts/contest_hall.pory"
	delay_16
# 1351 "data/scripts/contest_hall.pory"
	face_original_direction
# 1352 "data/scripts/contest_hall.pory"
	step_end
# 1353 "data/scripts/contest_hall.pory"

# 1354 "data/scripts/contest_hall.pory"
ContestHall_Movement_AudienceMemberLookUp: @ 827AD37
# 1355 "data/scripts/contest_hall.pory"
	face_up
# 1356 "data/scripts/contest_hall.pory"
	delay_16
# 1357 "data/scripts/contest_hall.pory"
	face_original_direction
# 1358 "data/scripts/contest_hall.pory"
	step_end
# 1359 "data/scripts/contest_hall.pory"

# 1360 "data/scripts/contest_hall.pory"
ContestHall_Movement_AudienceMemberLookRight: @ 827AD3B
# 1361 "data/scripts/contest_hall.pory"
	face_right
# 1362 "data/scripts/contest_hall.pory"
	delay_16
# 1363 "data/scripts/contest_hall.pory"
	face_original_direction
# 1364 "data/scripts/contest_hall.pory"
	step_end
# 1365 "data/scripts/contest_hall.pory"

# 1366 "data/scripts/contest_hall.pory"
ContestHall_Movement_AudienceMemberLookDown: @ 827AD3F
# 1367 "data/scripts/contest_hall.pory"
	face_down
# 1368 "data/scripts/contest_hall.pory"
	delay_16
# 1369 "data/scripts/contest_hall.pory"
	face_original_direction
# 1370 "data/scripts/contest_hall.pory"
	step_end
# 1371 "data/scripts/contest_hall.pory"

# 1372 "data/scripts/contest_hall.pory"
ContestHall_Movement_Player4FaceUp: @ 827AD43
# 1373 "data/scripts/contest_hall.pory"
	face_up
# 1374 "data/scripts/contest_hall.pory"
	step_end
# 1375 "data/scripts/contest_hall.pory"

# 1376 "data/scripts/contest_hall.pory"
ContestHall_Movement_MCLookAtJudge: @ 827AD45
# 1377 "data/scripts/contest_hall.pory"
	face_up
# 1378 "data/scripts/contest_hall.pory"
	delay_16
# 1379 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_right
# 1380 "data/scripts/contest_hall.pory"
	step_end
# 1381 "data/scripts/contest_hall.pory"

# 1382 "data/scripts/contest_hall.pory"
ContestHall_Movement_JudgeLookAtMC: @ 827AD49
# 1383 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_left
# 1384 "data/scripts/contest_hall.pory"
	delay_16
# 1385 "data/scripts/contest_hall.pory"
	delay_16
# 1386 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_down
# 1387 "data/scripts/contest_hall.pory"
	step_end
# 1388 "data/scripts/contest_hall.pory"

# 1389 "data/scripts/contest_hall.pory"
ContestHall_Movement_MCWalkInPlaceDown: @ 827AD4E
# 1390 "data/scripts/contest_hall.pory"
	delay_16
# 1391 "data/scripts/contest_hall.pory"
	delay_16
# 1392 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_down
# 1393 "data/scripts/contest_hall.pory"
	step_end
# 1394 "data/scripts/contest_hall.pory"

# 1395 "data/scripts/contest_hall.pory"
ContestHall_Movement_Player1WalkToCenter: @ 827AD52
# 1396 "data/scripts/contest_hall.pory"
	walk_up
# 1397 "data/scripts/contest_hall.pory"
	walk_right
# 1398 "data/scripts/contest_hall.pory"
	walk_right
# 1399 "data/scripts/contest_hall.pory"
	walk_right
# 1400 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_up
# 1401 "data/scripts/contest_hall.pory"
	step_end
# 1402 "data/scripts/contest_hall.pory"

# 1403 "data/scripts/contest_hall.pory"
ContestHall_Movement_Player1WalkBack: @ 827AD58
# 1404 "data/scripts/contest_hall.pory"
	walk_fast_left
# 1405 "data/scripts/contest_hall.pory"
	walk_fast_left
# 1406 "data/scripts/contest_hall.pory"
	walk_fast_left
# 1407 "data/scripts/contest_hall.pory"
	walk_fast_down
# 1408 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_up
# 1409 "data/scripts/contest_hall.pory"
	step_end
# 1410 "data/scripts/contest_hall.pory"

# 1411 "data/scripts/contest_hall.pory"
ContestHall_Movement_Player2WalkToCenter: @ 827AD5E
# 1412 "data/scripts/contest_hall.pory"
	walk_up
# 1413 "data/scripts/contest_hall.pory"
	walk_right
# 1414 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_up
# 1415 "data/scripts/contest_hall.pory"
	step_end
# 1416 "data/scripts/contest_hall.pory"

# 1417 "data/scripts/contest_hall.pory"
ContestHall_Movement_Player2WalkBack: @ 827AD62
# 1418 "data/scripts/contest_hall.pory"
	walk_fast_left
# 1419 "data/scripts/contest_hall.pory"
	walk_fast_down
# 1420 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_up
# 1421 "data/scripts/contest_hall.pory"
	step_end
# 1422 "data/scripts/contest_hall.pory"

# 1423 "data/scripts/contest_hall.pory"
ContestHall_Movement_Player3WalkToCenter: @ 827AD66
# 1424 "data/scripts/contest_hall.pory"
	walk_up
# 1425 "data/scripts/contest_hall.pory"
	walk_left
# 1426 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_up
# 1427 "data/scripts/contest_hall.pory"
	step_end
# 1428 "data/scripts/contest_hall.pory"

# 1429 "data/scripts/contest_hall.pory"
ContestHall_Movement_Player3WalkBack: @ 827AD6A
# 1430 "data/scripts/contest_hall.pory"
	walk_fast_right
# 1431 "data/scripts/contest_hall.pory"
	walk_fast_down
# 1432 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_up
# 1433 "data/scripts/contest_hall.pory"
	step_end
# 1434 "data/scripts/contest_hall.pory"

# 1435 "data/scripts/contest_hall.pory"
ContestHall_Movement_Player4WalkToCenter: @ 827AD6E
# 1436 "data/scripts/contest_hall.pory"
	walk_up
# 1437 "data/scripts/contest_hall.pory"
	walk_left
# 1438 "data/scripts/contest_hall.pory"
	walk_left
# 1439 "data/scripts/contest_hall.pory"
	walk_left
# 1440 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_up
# 1441 "data/scripts/contest_hall.pory"
	step_end
# 1442 "data/scripts/contest_hall.pory"

# 1443 "data/scripts/contest_hall.pory"
ContestHall_Movement_Player4WalkBack: @ 827AD74
# 1444 "data/scripts/contest_hall.pory"
	walk_fast_right
# 1445 "data/scripts/contest_hall.pory"
	walk_fast_right
# 1446 "data/scripts/contest_hall.pory"
	walk_fast_right
# 1447 "data/scripts/contest_hall.pory"
	walk_fast_down
# 1448 "data/scripts/contest_hall.pory"
	walk_in_place_fastest_up
# 1449 "data/scripts/contest_hall.pory"
	step_end
# 1450 "data/scripts/contest_hall.pory"

# 1451 "data/scripts/contest_hall.pory"
ContestHall_Movement_Player1ApproachForPrize: @ 827AD7A
# 1452 "data/scripts/contest_hall.pory"
	walk_right
# 1453 "data/scripts/contest_hall.pory"
	walk_right
# 1454 "data/scripts/contest_hall.pory"
	walk_up
# 1455 "data/scripts/contest_hall.pory"
	step_end
# 1456 "data/scripts/contest_hall.pory"

# 1457 "data/scripts/contest_hall.pory"
ContestHall_Movement_Player2ApproachForPrize: @ 827AD7E
# 1458 "data/scripts/contest_hall.pory"
	walk_up
# 1459 "data/scripts/contest_hall.pory"
	step_end
# 1460 "data/scripts/contest_hall.pory"

# 1461 "data/scripts/contest_hall.pory"
@ IsContestWithRSPlayer has no side effect, so this is nop
# 1462 "data/scripts/contest_hall.pory"
ContestHall_EventScript_CheckIfContestWithRSPlayer:: @ 827AD80
# 1463 "data/scripts/contest_hall.pory"
	specialvar VAR_RESULT, IsContestWithRSPlayer
# 1464 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, TRUE
# 1465 "data/scripts/contest_hall.pory"
	goto_if_eq ContestHall_EventScript_RetRSPlayer
# 1466 "data/scripts/contest_hall.pory"
	return
# 1467 "data/scripts/contest_hall.pory"

# 1468 "data/scripts/contest_hall.pory"
ContestHall_EventScript_RetRSPlayer:: @ 827AD91
# 1469 "data/scripts/contest_hall.pory"
	return
# 1470 "data/scripts/contest_hall.pory"

# 1471 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_DelayIfContestWithRSPlayer:: @ 827AD92
# 1472 "data/scripts/contest_hall.pory"
	specialvar VAR_RESULT, IsContestWithRSPlayer
# 1473 "data/scripts/contest_hall.pory"
	compare VAR_RESULT, TRUE
# 1474 "data/scripts/contest_hall.pory"
	goto_if_eq LilycoveCity_ContestLobby_EventScript_DelayForRSPlayer
# 1475 "data/scripts/contest_hall.pory"
	return
# 1476 "data/scripts/contest_hall.pory"

# 1477 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_EventScript_DelayForRSPlayer:: @ 827ADA3
# 1478 "data/scripts/contest_hall.pory"
	delay 9
# 1479 "data/scripts/contest_hall.pory"
	return
# 1480 "data/scripts/contest_hall.pory"

# 1481 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_ReceptionDontHavePokeblockCase: @ 827ADA7
# 1482 "data/scripts/contest_hall.pory"
	.string "Hello!\p"
# 1483 "data/scripts/contest_hall.pory"
	.string "This is the reception counter for\n"
# 1484 "data/scripts/contest_hall.pory"
	.string "Pokémon Contests.\p"
# 1485 "data/scripts/contest_hall.pory"
	.string "Oh? It appears that you don't have\n"
# 1486 "data/scripts/contest_hall.pory"
	.string "a {POKEBLOCK} Case yet.\p"
# 1487 "data/scripts/contest_hall.pory"
	.string "In that case, we need to provide you\n"
# 1488 "data/scripts/contest_hall.pory"
	.string "with this!$"
# 1489 "data/scripts/contest_hall.pory"

# 1490 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_NowThatWeveClearedThatUp: @ 827AE47
# 1491 "data/scripts/contest_hall.pory"
	.string "Okay, now that we've cleared that\n"
# 1492 "data/scripts/contest_hall.pory"
	.string "up…\p"
# 1493 "data/scripts/contest_hall.pory"
	.string "Hello!\p"
# 1494 "data/scripts/contest_hall.pory"
	.string "This is the reception counter for\n"
# 1495 "data/scripts/contest_hall.pory"
	.string "Pokémon Contests.$"
# 1496 "data/scripts/contest_hall.pory"

# 1497 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_ContestReception: @ 827AEA8
# 1498 "data/scripts/contest_hall.pory"
	.string "Hello!\p"
# 1499 "data/scripts/contest_hall.pory"
	.string "This is the reception counter for\n"
# 1500 "data/scripts/contest_hall.pory"
	.string "Pokémon Contests.$"
# 1501 "data/scripts/contest_hall.pory"

# 1502 "data/scripts/contest_hall.pory"
@ Unused
# 1503 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_CounterOnlyFor4PlayerContests: @ 827AEE3
# 1504 "data/scripts/contest_hall.pory"
	.string "Hello!\p"
# 1505 "data/scripts/contest_hall.pory"
	.string "This reception counter is only\n"
# 1506 "data/scripts/contest_hall.pory"
	.string "for 4-player Pokémon Contests.$"
# 1507 "data/scripts/contest_hall.pory"

# 1508 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_EnterContest1: @ 827AF28
# 1509 "data/scripts/contest_hall.pory"
	.string "Would you like to enter your Pokémon\n"
# 1510 "data/scripts/contest_hall.pory"
	.string "in our Contests?$"
# 1511 "data/scripts/contest_hall.pory"

# 1512 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_WhichTopic1: @ 827AF5E
# 1513 "data/scripts/contest_hall.pory"
	.string "Which topic would you like?$"
# 1514 "data/scripts/contest_hall.pory"

# 1515 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_ExplainContests: @ 827AF7A
# 1516 "data/scripts/contest_hall.pory"
	.string "A Pokémon Contest involves four\n"
# 1517 "data/scripts/contest_hall.pory"
	.string "Trainers entering one Pokémon each\l"
# 1518 "data/scripts/contest_hall.pory"
	.string "in competitive judging.\p"
# 1519 "data/scripts/contest_hall.pory"
	.string "A Contest has two stages of judging,\n"
# 1520 "data/scripts/contest_hall.pory"
	.string "primary and secondary.\p"
# 1521 "data/scripts/contest_hall.pory"
	.string "Primary judging is a popularity poll\n"
# 1522 "data/scripts/contest_hall.pory"
	.string "involving the audience.\p"
# 1523 "data/scripts/contest_hall.pory"
	.string "Secondary judging features appeals\n"
# 1524 "data/scripts/contest_hall.pory"
	.string "by the Pokémon using their moves.\p"
# 1525 "data/scripts/contest_hall.pory"
	.string "Plan appeals carefully to earn the\n"
# 1526 "data/scripts/contest_hall.pory"
	.string "most attention of the Judge and\l"
# 1527 "data/scripts/contest_hall.pory"
	.string "excite the audience.\l"
# 1528 "data/scripts/contest_hall.pory"
	.string "Do your best to stand out.\p"
# 1529 "data/scripts/contest_hall.pory"
	.string "The primary and secondary scores are\n"
# 1530 "data/scripts/contest_hall.pory"
	.string "added at the end.\p"
# 1531 "data/scripts/contest_hall.pory"
	.string "The Pokémon garnering the highest\n"
# 1532 "data/scripts/contest_hall.pory"
	.string "score is declared the winner.$"
# 1533 "data/scripts/contest_hall.pory"

# 1534 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_ExplainContestTypes: @ 827B17D
# 1535 "data/scripts/contest_hall.pory"
	.string "There are five kinds of Contests.\p"
# 1536 "data/scripts/contest_hall.pory"
	.string "Cool, Beauty, Cute, Smart, and\n"
# 1537 "data/scripts/contest_hall.pory"
	.string "Tough are the five categories.\p"
# 1538 "data/scripts/contest_hall.pory"
	.string "Choose the Contest that is right for\n"
# 1539 "data/scripts/contest_hall.pory"
	.string "the Pokémon you plan to enter.$"
# 1540 "data/scripts/contest_hall.pory"

# 1541 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_ExplainContestRanks: @ 827B221
# 1542 "data/scripts/contest_hall.pory"
	.string "There are four ranks of Pokémon\n"
# 1543 "data/scripts/contest_hall.pory"
	.string "Contests.\p"
# 1544 "data/scripts/contest_hall.pory"
	.string "Normal, Super, Hyper, and Master\n"
# 1545 "data/scripts/contest_hall.pory"
	.string "are the four ranks.\p"
# 1546 "data/scripts/contest_hall.pory"
	.string "In the Normal Rank, any Pokémon may\n"
# 1547 "data/scripts/contest_hall.pory"
	.string "enter.\p"
# 1548 "data/scripts/contest_hall.pory"
	.string "Any Pokémon that won a Normal Rank\n"
# 1549 "data/scripts/contest_hall.pory"
	.string "Contest may move up to the Super Rank\l"
# 1550 "data/scripts/contest_hall.pory"
	.string "in the same category.\p"
# 1551 "data/scripts/contest_hall.pory"
	.string "In the same way, a Super Rank winner\n"
# 1552 "data/scripts/contest_hall.pory"
	.string "can move up to the Hyper Rank, and\l"
# 1553 "data/scripts/contest_hall.pory"
	.string "a Hyper Rank winner can advance to\l"
# 1554 "data/scripts/contest_hall.pory"
	.string "the Master Rank in the same category.\p"
# 1555 "data/scripts/contest_hall.pory"
	.string "A Pokémon that won in the Master Rank\n"
# 1556 "data/scripts/contest_hall.pory"
	.string "may compete in the Master Rank as\l"
# 1557 "data/scripts/contest_hall.pory"
	.string "often as its Trainer wants.$"
# 1558 "data/scripts/contest_hall.pory"

# 1559 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_EnterWhichRank: @ 827B3FF
# 1560 "data/scripts/contest_hall.pory"
	.string "Which Rank would you like to enter?$"
# 1561 "data/scripts/contest_hall.pory"

# 1562 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_EnterWhichContest1: @ 827B423
# 1563 "data/scripts/contest_hall.pory"
	.string "Which Contest would you like to enter?$"
# 1564 "data/scripts/contest_hall.pory"

# 1565 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_EnterWhichPokemon1: @ 827B44A
# 1566 "data/scripts/contest_hall.pory"
	.string "Which Pokémon would you like to enter?$"
# 1567 "data/scripts/contest_hall.pory"

# 1568 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank: @ 827B471
# 1569 "data/scripts/contest_hall.pory"
	.string "I'm terribly sorry, but your Pokémon\n"
# 1570 "data/scripts/contest_hall.pory"
	.string "is not qualified to compete at this\l"
# 1571 "data/scripts/contest_hall.pory"
	.string "Rank yet…$"
# 1572 "data/scripts/contest_hall.pory"

# 1573 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_EggCannotTakePart: @ 827B4C4
# 1574 "data/scripts/contest_hall.pory"
	.string "I'm sorry, but an Egg cannot take part\n"
# 1575 "data/scripts/contest_hall.pory"
	.string "in a Pokémon Contest.$"
# 1576 "data/scripts/contest_hall.pory"

# 1577 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_MonInNoConditionForContest: @ 827B501
# 1578 "data/scripts/contest_hall.pory"
	.string "Your Pokémon appears to be in no\n"
# 1579 "data/scripts/contest_hall.pory"
	.string "condition to take part in a Contest…$"
# 1580 "data/scripts/contest_hall.pory"

# 1581 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_AlreadyWonEnterAnyway: @ 827B547
# 1582 "data/scripts/contest_hall.pory"
	.string "Oh, but that Ribbon…\p"
# 1583 "data/scripts/contest_hall.pory"
	.string "Your Pokémon has won this Contest\n"
# 1584 "data/scripts/contest_hall.pory"
	.string "before, hasn't it?\p"
# 1585 "data/scripts/contest_hall.pory"
	.string "Would you like to enter it in this\n"
# 1586 "data/scripts/contest_hall.pory"
	.string "Contest anyway?$"
# 1587 "data/scripts/contest_hall.pory"

# 1588 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_ConfirmContestMon: @ 827B5C4
# 1589 "data/scripts/contest_hall.pory"
	.string "Is that your Contest Pokémon?$"
# 1590 "data/scripts/contest_hall.pory"

# 1591 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_YourMonIsEntryNum4: @ 827B5E2
# 1592 "data/scripts/contest_hall.pory"
	.string "Okay, your Pokémon will be entered\n"
# 1593 "data/scripts/contest_hall.pory"
	.string "in this Contest.\p"
# 1594 "data/scripts/contest_hall.pory"
	.string "Your Pokémon is Entry No. 4.\n"
# 1595 "data/scripts/contest_hall.pory"
	.string "The Contest will begin shortly.$"
# 1596 "data/scripts/contest_hall.pory"

# 1597 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_ComeThroughHere: @ 827B653
# 1598 "data/scripts/contest_hall.pory"
	.string "Please come in through here.\n"
# 1599 "data/scripts/contest_hall.pory"
	.string "Good luck!$"
# 1600 "data/scripts/contest_hall.pory"

# 1601 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_PokemonWonWeHavePrize: @ 827B67B
# 1602 "data/scripts/contest_hall.pory"
	.string "Congratulations! Your Pokémon is the\n"
# 1603 "data/scripts/contest_hall.pory"
	.string "Contest winner!\p"
# 1604 "data/scripts/contest_hall.pory"
	.string "We have your prize right here.\n"
# 1605 "data/scripts/contest_hall.pory"
	.string "Please, right this way!$"
# 1606 "data/scripts/contest_hall.pory"

# 1607 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_ComeBackForPrizeLater: @ 827B6E7
# 1608 "data/scripts/contest_hall.pory"
	.string "Please come back for your prize\n"
# 1609 "data/scripts/contest_hall.pory"
	.string "later on.$"
# 1610 "data/scripts/contest_hall.pory"

# 1611 "data/scripts/contest_hall.pory"
ContestHall_Text_GettingStartedParticipantsAsFollows: @ 827B711
# 1612 "data/scripts/contest_hall.pory"
	.string "MC: Hello! We're just getting started\n"
# 1613 "data/scripts/contest_hall.pory"
	.string "with a {STR_VAR_3} Rank Pokémon\l"
# 1614 "data/scripts/contest_hall.pory"
	.string "{STR_VAR_2}!\p"
# 1615 "data/scripts/contest_hall.pory"
	.string "The participating Trainers and their\n"
# 1616 "data/scripts/contest_hall.pory"
	.string "Pokémon are as follows:$"
# 1617 "data/scripts/contest_hall.pory"

# 1618 "data/scripts/contest_hall.pory"
ContestHall_Text_GettingStartedParticipantsAsFollowsLink: @ 827B78F
# 1619 "data/scripts/contest_hall.pory"
	.string "MC: Hello! We're just getting started\n"
# 1620 "data/scripts/contest_hall.pory"
	.string "with a 4-player linked Pokémon\l"
# 1621 "data/scripts/contest_hall.pory"
	.string "{STR_VAR_2}!\p"
# 1622 "data/scripts/contest_hall.pory"
	.string "The participating Trainers and their\n"
# 1623 "data/scripts/contest_hall.pory"
	.string "Pokémon are as follows:$"
# 1624 "data/scripts/contest_hall.pory"

# 1625 "data/scripts/contest_hall.pory"
ContestHall_Text_EntryXTrainersMon: @ 827B815
# 1626 "data/scripts/contest_hall.pory"
	.string "MC: Entry No. {STR_VAR_2}!\n"
# 1627 "data/scripts/contest_hall.pory"
	.string "{STR_VAR_1}'s {STR_VAR_3}!$"
# 1628 "data/scripts/contest_hall.pory"

# 1629 "data/scripts/contest_hall.pory"
ContestHall_Text_SeenContestantsAudienceWillVote: @ 827B830
# 1630 "data/scripts/contest_hall.pory"
	.string "MC: We've just seen the four Pokémon\n"
# 1631 "data/scripts/contest_hall.pory"
	.string "contestants.\p"
# 1632 "data/scripts/contest_hall.pory"
	.string "Now it's time for primary judging!\p"
# 1633 "data/scripts/contest_hall.pory"
	.string "The audience will vote on their\n"
# 1634 "data/scripts/contest_hall.pory"
	.string "favorite Pokémon contestants.\p"
# 1635 "data/scripts/contest_hall.pory"
	.string "Without any further ado, let the\n"
# 1636 "data/scripts/contest_hall.pory"
	.string "voting begin!$"
# 1637 "data/scripts/contest_hall.pory"

# 1638 "data/scripts/contest_hall.pory"
ContestHall_Text_VotingUnderWay: @ 827B8F2
# 1639 "data/scripts/contest_hall.pory"
	.string "Voting under way…$"
# 1640 "data/scripts/contest_hall.pory"

# 1641 "data/scripts/contest_hall.pory"
ContestHall_Text_VotingCompleteLetsAppeal: @ 827B904
# 1642 "data/scripts/contest_hall.pory"
	.string "Voting is now complete!\p"
# 1643 "data/scripts/contest_hall.pory"
	.string "While the votes are being tallied,\n"
# 1644 "data/scripts/contest_hall.pory"
	.string "let's move on to secondary judging!\p"
# 1645 "data/scripts/contest_hall.pory"
	.string "The second stage of judging is the\n"
# 1646 "data/scripts/contest_hall.pory"
	.string "much anticipated appeal time!\p"
# 1647 "data/scripts/contest_hall.pory"
	.string "May the contestants amaze us with\n"
# 1648 "data/scripts/contest_hall.pory"
	.string "superb appeals of dazzling moves!\p"
# 1649 "data/scripts/contest_hall.pory"
	.string "Let's see a little enthusiasm!\n"
# 1650 "data/scripts/contest_hall.pory"
	.string "Let's appeal!$"
# 1651 "data/scripts/contest_hall.pory"

# 1652 "data/scripts/contest_hall.pory"
ContestHall_Text_ThatsItForJudging: @ 827BA15
# 1653 "data/scripts/contest_hall.pory"
	.string "MC: That's it for judging!$"
# 1654 "data/scripts/contest_hall.pory"

# 1655 "data/scripts/contest_hall.pory"
ContestHall_Text_ThankYouForAppeals: @ 827BA30
# 1656 "data/scripts/contest_hall.pory"
	.string "Thank you all for a most wonderful\n"
# 1657 "data/scripts/contest_hall.pory"
	.string "display of quality appeals!\p"
# 1658 "data/scripts/contest_hall.pory"
	.string "This concludes all judging!\n"
# 1659 "data/scripts/contest_hall.pory"
	.string "Thank you for your fine efforts!$"
# 1660 "data/scripts/contest_hall.pory"

# 1661 "data/scripts/contest_hall.pory"
ContestHall_Text_JudgeLooksReady: @ 827BAAC
# 1662 "data/scripts/contest_hall.pory"
	.string "Now, all that remains is the pulse-\n"
# 1663 "data/scripts/contest_hall.pory"
	.string "pounding proclamation of the winner.\p"
# 1664 "data/scripts/contest_hall.pory"
	.string "The Judge looks ready to make\n"
# 1665 "data/scripts/contest_hall.pory"
	.string "the announcement!$"
# 1666 "data/scripts/contest_hall.pory"

# 1667 "data/scripts/contest_hall.pory"
ContestHall_Text_WeWillNowDeclareWinner: @ 827BB25
# 1668 "data/scripts/contest_hall.pory"
	.string "Judge: We will now declare the winner!$"
# 1669 "data/scripts/contest_hall.pory"

# 1670 "data/scripts/contest_hall.pory"
ContestHall_Text_CongratsTrainerXandMon: @ 827BB4C
# 1671 "data/scripts/contest_hall.pory"
	.string "MC: Entry No. {STR_VAR_2}!\p"
# 1672 "data/scripts/contest_hall.pory"
	.string "{STR_VAR_3} and {STR_VAR_1},\n"
# 1673 "data/scripts/contest_hall.pory"
	.string "congratulations!$"
# 1674 "data/scripts/contest_hall.pory"

# 1675 "data/scripts/contest_hall.pory"
ContestHall_Text_CongratsPleaseCompeteAgain: @ 827BB7A
# 1676 "data/scripts/contest_hall.pory"
	.string "MC: Congratulations!\n"
# 1677 "data/scripts/contest_hall.pory"
	.string "Please do compete again!$"
# 1678 "data/scripts/contest_hall.pory"

# 1679 "data/scripts/contest_hall.pory"
ContestHall_Text_AcceptYourPrize: @ 827BBA8
# 1680 "data/scripts/contest_hall.pory"
	.string "MC: Here you are!\n"
# 1681 "data/scripts/contest_hall.pory"
	.string "Please accept your prize!$"
# 1682 "data/scripts/contest_hall.pory"

# 1683 "data/scripts/contest_hall.pory"
ContestHall_Text_ConferRibbonAsPrize: @ 827BBD4
# 1684 "data/scripts/contest_hall.pory"
	.string "We confer on you this Ribbon\n"
# 1685 "data/scripts/contest_hall.pory"
	.string "as your prize!$"
# 1686 "data/scripts/contest_hall.pory"

# 1687 "data/scripts/contest_hall.pory"
ContestHall_Text_ReceivedRibbon: @ 827BC00
# 1688 "data/scripts/contest_hall.pory"
	.string "{PLAYER} received a Ribbon.$"
# 1689 "data/scripts/contest_hall.pory"

# 1690 "data/scripts/contest_hall.pory"
ContestHall_Text_PutRibbonOnMon: @ 827BC16
# 1691 "data/scripts/contest_hall.pory"
	.string "{PLAYER} put the Ribbon on\n"
# 1692 "data/scripts/contest_hall.pory"
	.string "{STR_VAR_1}.$"
# 1693 "data/scripts/contest_hall.pory"

# 1694 "data/scripts/contest_hall.pory"
ContestHall_Text_PickUpPrizeAtCounterLater: @ 827BC2F
# 1695 "data/scripts/contest_hall.pory"
	.string "Please pick up your prize at\n"
# 1696 "data/scripts/contest_hall.pory"
	.string "the reception counter later.\l"
# 1697 "data/scripts/contest_hall.pory"
	.string "Please do compete again!$"
# 1698 "data/scripts/contest_hall.pory"

# 1699 "data/scripts/contest_hall.pory"
@ Unused
# 1700 "data/scripts/contest_hall.pory"
ContestHall_Text_OnlyRegister4Players: @ 827BC82
# 1701 "data/scripts/contest_hall.pory"
	.string "I only register four players for\n"
# 1702 "data/scripts/contest_hall.pory"
	.string "Pokémon Contests.\p"
# 1703 "data/scripts/contest_hall.pory"
	.string "If three other players link up, all\n"
# 1704 "data/scripts/contest_hall.pory"
	.string "four may enter the same Contest.\p"
# 1705 "data/scripts/contest_hall.pory"
	.string "Would you like to take part?$"
# 1706 "data/scripts/contest_hall.pory"

# 1707 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_ProgressWillBeSaved: @ 827BD17
# 1708 "data/scripts/contest_hall.pory"
	.string "Before entering a Contest, your\n"
# 1709 "data/scripts/contest_hall.pory"
	.string "progress will be saved.$"
# 1710 "data/scripts/contest_hall.pory"

# 1711 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_ParticipateAnotherTime: @ 827BD4F
# 1712 "data/scripts/contest_hall.pory"
	.string "We hope you will participate another\n"
# 1713 "data/scripts/contest_hall.pory"
	.string "time.$"
# 1714 "data/scripts/contest_hall.pory"

# 1715 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_EnterContest2: @ 827BD7A
# 1716 "data/scripts/contest_hall.pory"
	.string "Would you like to enter a Contest?$"
# 1717 "data/scripts/contest_hall.pory"

# 1718 "data/scripts/contest_hall.pory"
@ Unused
# 1719 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_Explain4PlayerContest: @ 827BD9D
# 1720 "data/scripts/contest_hall.pory"
	.string "When four players are ready, connect\n"
# 1721 "data/scripts/contest_hall.pory"
	.string "over a Game Link cable, and register\l"
# 1722 "data/scripts/contest_hall.pory"
	.string "with me, please.\p"
# 1723 "data/scripts/contest_hall.pory"
	.string "Please choose the same Contest\n"
# 1724 "data/scripts/contest_hall.pory"
	.string "as your fellow contestants.\p"
# 1725 "data/scripts/contest_hall.pory"
	.string "The Contest begins as soon as all\n"
# 1726 "data/scripts/contest_hall.pory"
	.string "players register their entry.\p"
# 1727 "data/scripts/contest_hall.pory"
	.string "After that, the usual Contest rules\n"
# 1728 "data/scripts/contest_hall.pory"
	.string "apply.$"
# 1729 "data/scripts/contest_hall.pory"

# 1730 "data/scripts/contest_hall.pory"
@ Unused
# 1731 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_EnterWhichContest2: @ 827BE9E
# 1732 "data/scripts/contest_hall.pory"
	.string "Which Contest would you like to enter?$"
# 1733 "data/scripts/contest_hall.pory"

# 1734 "data/scripts/contest_hall.pory"
@ Unused
# 1735 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_EnterWhichPokemon2: @ 827BEC5
# 1736 "data/scripts/contest_hall.pory"
	.string "Which Pokémon would you like to enter?$"
# 1737 "data/scripts/contest_hall.pory"

# 1738 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_Transmitting: @ 827BEEC
# 1739 "data/scripts/contest_hall.pory"
	.string "Transmitting…$"
# 1740 "data/scripts/contest_hall.pory"

# 1741 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_TransmissionError: @ 827BEFA
# 1742 "data/scripts/contest_hall.pory"
	.string "Transmission error…$"
# 1743 "data/scripts/contest_hall.pory"

# 1744 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_PlayersChoseDifferentContest: @ 827BF0E
# 1745 "data/scripts/contest_hall.pory"
	.string "You may have chosen a different\n"
# 1746 "data/scripts/contest_hall.pory"
	.string "Contest than another player.$"
# 1747 "data/scripts/contest_hall.pory"

# 1748 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_PlayersMadeDifferentChoice: @ 827BF4B
# 1749 "data/scripts/contest_hall.pory"
	.string "You may have made a different\n"
# 1750 "data/scripts/contest_hall.pory"
	.string "choice than another player.$"
# 1751 "data/scripts/contest_hall.pory"

# 1752 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_PleaseWaitBButtonCancel: @ 827BF85
# 1753 "data/scripts/contest_hall.pory"
	.string "Please wait.\n"
# 1754 "data/scripts/contest_hall.pory"
	.string "… … B Button: Cancel$"
# 1755 "data/scripts/contest_hall.pory"

# 1756 "data/scripts/contest_hall.pory"
@ Unused
# 1757 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_ParticipateAnotherTime2: @ 827BFA7
# 1758 "data/scripts/contest_hall.pory"
	.string "We hope you will participate another\n"
# 1759 "data/scripts/contest_hall.pory"
	.string "time.$"
# 1760 "data/scripts/contest_hall.pory"

# 1761 "data/scripts/contest_hall.pory"
@ Unused
# 1762 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_TransmissionErrorTryAgain: @ 827BFD2
# 1763 "data/scripts/contest_hall.pory"
	.string "Transmission error.\n"
# 1764 "data/scripts/contest_hall.pory"
	.string "Please try again.$"
# 1765 "data/scripts/contest_hall.pory"

# 1766 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_YourMonIsEntryNumX: @ 827BFF8
# 1767 "data/scripts/contest_hall.pory"
	.string "Your Pokémon will be entered in\n"
# 1768 "data/scripts/contest_hall.pory"
	.string "the Contest.\p"
# 1769 "data/scripts/contest_hall.pory"
	.string "Your Pokémon is Entry No. {STR_VAR_2}.$"
# 1770 "data/scripts/contest_hall.pory"

# 1771 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_ContestBeginShortly: @ 827C043
# 1772 "data/scripts/contest_hall.pory"
	.string "The Contest will begin shortly.$"
# 1773 "data/scripts/contest_hall.pory"

# 1774 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_LinkContestReception: @ 827C063
# 1775 "data/scripts/contest_hall.pory"
	.string "Welcome! This is the Pokémon Contest\n"
# 1776 "data/scripts/contest_hall.pory"
	.string "link reception counter.\p"
# 1777 "data/scripts/contest_hall.pory"
	.string "You may enter Contests together with\n"
# 1778 "data/scripts/contest_hall.pory"
	.string "one or more friends.$"
# 1779 "data/scripts/contest_hall.pory"

# 1780 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_WhichTopic2: @ 827C0DA
# 1781 "data/scripts/contest_hall.pory"
	.string "Which topic would you like?$"
# 1782 "data/scripts/contest_hall.pory"

# 1783 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_EnterContest3: @ 827C0F6
# 1784 "data/scripts/contest_hall.pory"
	.string "Would you like to enter a Contest?$"
# 1785 "data/scripts/contest_hall.pory"

# 1786 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_EnterWhichContest3: @ 827C119
# 1787 "data/scripts/contest_hall.pory"
	.string "Which Contest would you like to enter?$"
# 1788 "data/scripts/contest_hall.pory"

# 1789 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_MonInNoCondition2: @ 827C140
# 1790 "data/scripts/contest_hall.pory"
	.string "Your Pokémon appears to be in no\n"
# 1791 "data/scripts/contest_hall.pory"
	.string "condition to take part in a Contest…$"
# 1792 "data/scripts/contest_hall.pory"

# 1793 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_EggCannotTakePart2: @ 827C186
# 1794 "data/scripts/contest_hall.pory"
	.string "I'm sorry, but an Egg cannot take part\n"
# 1795 "data/scripts/contest_hall.pory"
	.string "in a Pokémon Contest.$"
# 1796 "data/scripts/contest_hall.pory"

# 1797 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_EnterWhichPokemon3: @ 827C1C3
# 1798 "data/scripts/contest_hall.pory"
	.string "Which Pokémon would you like to enter?$"
# 1799 "data/scripts/contest_hall.pory"

# 1800 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_PleaseDecideLinkLeader: @ 827C1EA
# 1801 "data/scripts/contest_hall.pory"
	.string "Please decide which of you will\n"
# 1802 "data/scripts/contest_hall.pory"
	.string "become the Group Leader.\p"
# 1803 "data/scripts/contest_hall.pory"
	.string "The other players must then choose\n"
# 1804 "data/scripts/contest_hall.pory"
	.string "“Join Group.”$"
# 1805 "data/scripts/contest_hall.pory"

# 1806 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_PlayerAt4PCounterUseGMode: @ 827C254
# 1807 "data/scripts/contest_hall.pory"
	.string "At least one player has entered using\n"
# 1808 "data/scripts/contest_hall.pory"
	.string "the 4-player reception counter.\p"
# 1809 "data/scripts/contest_hall.pory"
	.string "There must be four players connected\n"
# 1810 "data/scripts/contest_hall.pory"
	.string "using a GBA Game Link cable.\p"
# 1811 "data/scripts/contest_hall.pory"
	.string "When the four players are ready,\n"
# 1812 "data/scripts/contest_hall.pory"
	.string "select G-Mode (Global Mode),\l"
# 1813 "data/scripts/contest_hall.pory"
	.string "then register to enter again, please.$"
# 1814 "data/scripts/contest_hall.pory"

# 1815 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_ExplainLinkContest: @ 827C340
# 1816 "data/scripts/contest_hall.pory"
	.string "This is a Contest for two to four\n"
# 1817 "data/scripts/contest_hall.pory"
	.string "players linked using a Wireless\l"
# 1818 "data/scripts/contest_hall.pory"
	.string "Adapter or a GBA Game Link cable.\p"
# 1819 "data/scripts/contest_hall.pory"
	.string "Participants are first asked to choose\n"
# 1820 "data/scripts/contest_hall.pory"
	.string "the mode they wish to enter.\p"
# 1821 "data/scripts/contest_hall.pory"
	.string "There are two different modes.\p"
# 1822 "data/scripts/contest_hall.pory"
	.string "E-Mode (Emerald Mode) is for\n"
# 1823 "data/scripts/contest_hall.pory"
	.string "two to four players, each with a\l"
# 1824 "data/scripts/contest_hall.pory"
	.string "Pokémon Emerald Game Pak.\p"
# 1825 "data/scripts/contest_hall.pory"
	.string "G-Mode (Global Mode) is only for\n"
# 1826 "data/scripts/contest_hall.pory"
	.string "four players, each with a Pokémon\l"
# 1827 "data/scripts/contest_hall.pory"
	.string "Emerald, Ruby, or Sapphire Game Pak.\p"
# 1828 "data/scripts/contest_hall.pory"
	.string "The players should discuss which mode\n"
# 1829 "data/scripts/contest_hall.pory"
	.string "they want, then choose the same mode.\p"
# 1830 "data/scripts/contest_hall.pory"
	.string "Once all the players have chosen\n"
# 1831 "data/scripts/contest_hall.pory"
	.string "the same Contest in the same mode,\l"
# 1832 "data/scripts/contest_hall.pory"
	.string "the entry registration is complete.\p"
# 1833 "data/scripts/contest_hall.pory"
	.string "After that, a Contest will start in\n"
# 1834 "data/scripts/contest_hall.pory"
	.string "the usual manner.$"
# 1835 "data/scripts/contest_hall.pory"

# 1836 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_ExplainEMode: @ 827C5B1
# 1837 "data/scripts/contest_hall.pory"
	.string "In E-Mode (Emerald Mode),\n"
# 1838 "data/scripts/contest_hall.pory"
	.string "a Link Contest can be held with\l"
# 1839 "data/scripts/contest_hall.pory"
	.string "two to four players. Each player must\l"
# 1840 "data/scripts/contest_hall.pory"
	.string "have a Pokémon Emerald Game Pak.\p"
# 1841 "data/scripts/contest_hall.pory"
	.string "The players must be linked with each\n"
# 1842 "data/scripts/contest_hall.pory"
	.string "other using Wireless Adapters or\l"
# 1843 "data/scripts/contest_hall.pory"
	.string "GBA Game Link cables.\p"
# 1844 "data/scripts/contest_hall.pory"
	.string "If there are fewer than four players,\n"
# 1845 "data/scripts/contest_hall.pory"
	.string "Trainers in the hall will join to fill\l"
# 1846 "data/scripts/contest_hall.pory"
	.string "the 4-player Contest lineup.\p"
# 1847 "data/scripts/contest_hall.pory"
	.string "Please be aware that E-Mode is not\n"
# 1848 "data/scripts/contest_hall.pory"
	.string "available in Pokémon Ruby or Sapphire.$"
# 1849 "data/scripts/contest_hall.pory"

# 1850 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_ExplainGMode: @ 827C742
# 1851 "data/scripts/contest_hall.pory"
	.string "G-Mode (Global Mode) is specifically\n"
# 1852 "data/scripts/contest_hall.pory"
	.string "for four players who are linked using\l"
# 1853 "data/scripts/contest_hall.pory"
	.string "GBA Game Link cables.\p"
# 1854 "data/scripts/contest_hall.pory"
	.string "Each player must have a Pokémon\n"
# 1855 "data/scripts/contest_hall.pory"
	.string "Emerald, Ruby, or Sapphire Game Pak.\p"
# 1856 "data/scripts/contest_hall.pory"
	.string "The Contest starts after all players\n"
# 1857 "data/scripts/contest_hall.pory"
	.string "choose G-Mode (Pokémon Emerald) or\l"
# 1858 "data/scripts/contest_hall.pory"
	.string "enter through the 4-player reception\l"
# 1859 "data/scripts/contest_hall.pory"
	.string "counter (Pokémon Ruby or Sapphire).$"
# 1860 "data/scripts/contest_hall.pory"

# 1861 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_NoWirelessAdapterInGMode: @ 827C879
# 1862 "data/scripts/contest_hall.pory"
	.string "I'm terribly sorry.\p"
# 1863 "data/scripts/contest_hall.pory"
	.string "G-Mode does not function\n"
# 1864 "data/scripts/contest_hall.pory"
	.string "with Wireless Adapters.\p"
# 1865 "data/scripts/contest_hall.pory"
	.string "Please select E-Mode or try\n"
# 1866 "data/scripts/contest_hall.pory"
	.string "again using a GBA Game Link cable.$"
# 1867 "data/scripts/contest_hall.pory"

# 1868 "data/scripts/contest_hall.pory"
LilycoveCity_ContestLobby_Text_WhichContestMode: @ 827C8FD
# 1869 "data/scripts/contest_hall.pory"
	.string "Which Contest Mode would you like\n"
# 1870 "data/scripts/contest_hall.pory"
	.string "to enter?$"
# 1871 "data/scripts/contest_hall.pory"

# 1872 "data/scripts/contest_hall.pory"
ContestHall_Text_GettingStartedWireless: @ 827C929
# 1873 "data/scripts/contest_hall.pory"
	.string "MC: Hello! We're just getting started\n"
# 1874 "data/scripts/contest_hall.pory"
	.string "with a 4-player linked Pokémon\l"
# 1875 "data/scripts/contest_hall.pory"
	.string "{STR_VAR_2}!$"
# 1876 "data/scripts/contest_hall.pory"

# 1877 "data/scripts/contest_hall.pory"
ContestHall_Text_ParticipantsAsFollows: @ 827C972
# 1878 "data/scripts/contest_hall.pory"
	.string "The participating Trainers and their\n"
# 1879 "data/scripts/contest_hall.pory"
	.string "Pokémon are as follows:$"
# 1880 "data/scripts/contest_hall.pory"

# 1881 "data/scripts/contest_hall.pory"
ContestHall_Text_WeveSeenContestants: @ 827C9AF
# 1882 "data/scripts/contest_hall.pory"
	.string "MC: We've just seen the four Pokémon\n"
# 1883 "data/scripts/contest_hall.pory"
	.string "contestants.\p"
# 1884 "data/scripts/contest_hall.pory"
	.string "Now it's time for primary judging!$"
# 1885 "data/scripts/contest_hall.pory"

# 1886 "data/scripts/contest_hall.pory"
ContestHall_Text_AudienceWillVote: @ 827CA04
# 1887 "data/scripts/contest_hall.pory"
	.string "The audience will vote on their\n"
# 1888 "data/scripts/contest_hall.pory"
	.string "favorite Pokémon contestants.$"
# 1889 "data/scripts/contest_hall.pory"

# 1890 "data/scripts/contest_hall.pory"
ContestHall_Text_LetVotingBegin: @ 827CA42
# 1891 "data/scripts/contest_hall.pory"
	.string "Without any further ado,\n"
# 1892 "data/scripts/contest_hall.pory"
	.string "let the voting begin!$"
# 1893 "data/scripts/contest_hall.pory"

# 1894 "data/scripts/contest_hall.pory"
ContestHall_Text_VotingComplete: @ 827CA71
# 1895 "data/scripts/contest_hall.pory"
	.string "Voting is now complete!\p"
# 1896 "data/scripts/contest_hall.pory"
	.string "While the votes are being tallied,\n"
# 1897 "data/scripts/contest_hall.pory"
	.string "let's move on to secondary judging!$"
# 1898 "data/scripts/contest_hall.pory"

# 1899 "data/scripts/contest_hall.pory"
ContestHall_Text_SecondStageOfJudging: @ 827CAD0
# 1900 "data/scripts/contest_hall.pory"
	.string "The second stage of judging is\n"
# 1901 "data/scripts/contest_hall.pory"
	.string "the much-anticipated appeal time!\p"
# 1902 "data/scripts/contest_hall.pory"
	.string "May the contestants amaze us with\n"
# 1903 "data/scripts/contest_hall.pory"
	.string "superb appeals of dazzling moves!$"
# 1904 "data/scripts/contest_hall.pory"

# 1905 "data/scripts/contest_hall.pory"
ContestHall_Text_LetsAppeal: @ 827CB55
# 1906 "data/scripts/contest_hall.pory"
	.string "Let's see a little enthusiasm!\n"
# 1907 "data/scripts/contest_hall.pory"
	.string "Let's appeal!$"
