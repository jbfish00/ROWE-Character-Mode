# 1 "data/scripts/players_house.pory"

# 2 "data/scripts/players_house.pory"
@ Local IDs are the same for both players houses
# 3 "data/scripts/players_house.pory"
.set LOCALID_MOM, 1
# 4 "data/scripts/players_house.pory"
.set LOCALID_DAD, 5
# 5 "data/scripts/players_house.pory"
.set LOCALID_MOM_2F, 14
# 6 "data/scripts/players_house.pory"

# 7 "data/scripts/players_house.pory"
PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet::
# 8 "data/scripts/players_house.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
# 9 "data/scripts/players_house.pory"
	return
# 10 "data/scripts/players_house.pory"

# 11 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_EnterHouseMovingIn::
# 12 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_IsntItNiceInHere, MSGBOX_DEFAULT
# 13 "data/scripts/players_house.pory"
	applymovement VAR_0x8004, Common_Movement_FacePlayer
# 14 "data/scripts/players_house.pory"
	waitmovement 0
# 15 "data/scripts/players_house.pory"
	compare VAR_0x8005, MALE
# 16 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_MomFacePlayerMovingInMale
# 17 "data/scripts/players_house.pory"
	compare VAR_0x8005, FEMALE
# 18 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_MomFacePlayerMovingInFemale
# 19 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_MoversPokemonGoSetClock, MSGBOX_DEFAULT
# 20 "data/scripts/players_house.pory"
	closemessage
# 21 "data/scripts/players_house.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
# 22 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerWalkIn
# 23 "data/scripts/players_house.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestUp
# 24 "data/scripts/players_house.pory"
	waitmovement 0
# 25 "data/scripts/players_house.pory"
	releaseall
# 26 "data/scripts/players_house.pory"
	end
# 27 "data/scripts/players_house.pory"

# 28 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomFacePlayerMovingInMale::
# 29 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 30 "data/scripts/players_house.pory"
	waitmovement 0
# 31 "data/scripts/players_house.pory"
	return
# 32 "data/scripts/players_house.pory"

# 33 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomFacePlayerMovingInFemale::
# 34 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 35 "data/scripts/players_house.pory"
	waitmovement 0
# 36 "data/scripts/players_house.pory"
	return
# 37 "data/scripts/players_house.pory"

# 38 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerWalkIn:
# 39 "data/scripts/players_house.pory"
	walk_up
# 40 "data/scripts/players_house.pory"
	step_end
# 41 "data/scripts/players_house.pory"

# 42 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomGoSeeRoom::
# 43 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_ArentYouInterestedInRoom, MSGBOX_DEFAULT
# 44 "data/scripts/players_house.pory"
	closemessage
# 45 "data/scripts/players_house.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestUp
# 46 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_MovePlayerAwayFromDoor
# 47 "data/scripts/players_house.pory"
	waitmovement 0
# 48 "data/scripts/players_house.pory"
	releaseall
# 49 "data/scripts/players_house.pory"
	end
# 50 "data/scripts/players_house.pory"

# 51 "data/scripts/players_house.pory"
LittlerootTown_BrendansHouse_2F_EventScript_WallClock::
# 52 "data/scripts/players_house.pory"
	lockall
# 53 "data/scripts/players_house.pory"
	setvar VAR_0x8004, MALE
# 54 "data/scripts/players_house.pory"
	goto PlayersHouse_2F_EventScript_WallClock
# 55 "data/scripts/players_house.pory"
	end
# 56 "data/scripts/players_house.pory"

# 57 "data/scripts/players_house.pory"
LittlerootTown_MaysHouse_2F_EventScript_WallClock::
# 58 "data/scripts/players_house.pory"
	lockall
# 59 "data/scripts/players_house.pory"
	setvar VAR_0x8004, FEMALE
# 60 "data/scripts/players_house.pory"
	goto PlayersHouse_2F_EventScript_WallClock
# 61 "data/scripts/players_house.pory"
	end
# 62 "data/scripts/players_house.pory"

# 63 "data/scripts/players_house.pory"
PlayersHouse_2F_EventScript_WallClock::
# 64 "data/scripts/players_house.pory"
	goto_if_set FLAG_SET_WALL_CLOCK, PlayersHouse_2F_EventScript_CheckWallClock
# 65 "data/scripts/players_house.pory"
	msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
# 66 "data/scripts/players_house.pory"
	call PlayersHouse_2F_EventScript_SetWallClock
# 67 "data/scripts/players_house.pory"
	delay 30
# 68 "data/scripts/players_house.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 6
# 69 "data/scripts/players_house.pory"
	setflag FLAG_SET_WALL_CLOCK
# 70 "data/scripts/players_house.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
# 71 "data/scripts/players_house.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
# 72 "data/scripts/players_house.pory"
	checkplayergender
# 73 "data/scripts/players_house.pory"
	//compare VAR_RESULT, MALE
# 74 "data/scripts/players_house.pory"
	//call_if_eq PlayersHouse_2F_EventScript_MomComesUpstairsMale
# 75 "data/scripts/players_house.pory"
	//compare VAR_RESULT, FEMALE
# 76 "data/scripts/players_house.pory"
	//call_if_eq PlayersHouse_2F_EventScript_MomComesUpstairsFemale
# 77 "data/scripts/players_house.pory"
	//playse SE_EXIT
# 78 "data/scripts/players_house.pory"
	removeobject VAR_0x8008
# 79 "data/scripts/players_house.pory"
	releaseall
# 80 "data/scripts/players_house.pory"
	end
# 81 "data/scripts/players_house.pory"

# 82 "data/scripts/players_house.pory"
PlayersHouse_2F_EventScript_MomComesUpstairsMale::
# 83 "data/scripts/players_house.pory"
	setvar VAR_0x8008, LOCALID_MOM_2F
# 84 "data/scripts/players_house.pory"
	addobject VAR_0x8008
# 85 "data/scripts/players_house.pory"
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomEntersMale
# 86 "data/scripts/players_house.pory"
	waitmovement 0
# 87 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 88 "data/scripts/players_house.pory"
	waitmovement 0
# 89 "data/scripts/players_house.pory"
	msgbox PlayersHouse_2F_Text_HowDoYouLikeYourRoom, MSGBOX_DEFAULT
# 90 "data/scripts/players_house.pory"
	closemessage
# 91 "data/scripts/players_house.pory"
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomExitsMale
# 92 "data/scripts/players_house.pory"
	waitmovement 0
# 93 "data/scripts/players_house.pory"
	return
# 94 "data/scripts/players_house.pory"

# 95 "data/scripts/players_house.pory"
PlayersHouse_2F_EventScript_MomComesUpstairsFemale::
# 96 "data/scripts/players_house.pory"
	setvar VAR_0x8008, LOCALID_MOM_2F
# 97 "data/scripts/players_house.pory"
	addobject VAR_0x8008
# 98 "data/scripts/players_house.pory"
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomEntersFemale
# 99 "data/scripts/players_house.pory"
	waitmovement 0
# 100 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 101 "data/scripts/players_house.pory"
	waitmovement 0
# 102 "data/scripts/players_house.pory"
	msgbox PlayersHouse_2F_Text_HowDoYouLikeYourRoom, MSGBOX_DEFAULT
# 103 "data/scripts/players_house.pory"
	closemessage
# 104 "data/scripts/players_house.pory"
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomExitsFemale
# 105 "data/scripts/players_house.pory"
	waitmovement 0
# 106 "data/scripts/players_house.pory"
	return
# 107 "data/scripts/players_house.pory"

# 108 "data/scripts/players_house.pory"
PlayersHouse_2F_EventScript_CheckWallClock::
# 109 "data/scripts/players_house.pory"
	incrementgamestat GAME_STAT_CHECKED_CLOCK
# 110 "data/scripts/players_house.pory"
	fadescreen FADE_TO_BLACK
# 111 "data/scripts/players_house.pory"
	special Special_ViewWallClock
# 112 "data/scripts/players_house.pory"
	waitstate
# 113 "data/scripts/players_house.pory"
	releaseall
# 114 "data/scripts/players_house.pory"
	end
# 115 "data/scripts/players_house.pory"

# 116 "data/scripts/players_house.pory"
PlayersHouse_2F_EventScript_SetWallClock::
# 117 "data/scripts/players_house.pory"
	fadescreen FADE_TO_BLACK
# 118 "data/scripts/players_house.pory"
	special StartWallClock
# 119 "data/scripts/players_house.pory"
	waitstate
# 120 "data/scripts/players_house.pory"
	return
# 121 "data/scripts/players_house.pory"

# 122 "data/scripts/players_house.pory"
PlayersHouse_2F_Movement_MomEntersMale:
# 123 "data/scripts/players_house.pory"
	delay_8
# 124 "data/scripts/players_house.pory"
	walk_down
# 125 "data/scripts/players_house.pory"
	walk_in_place_fastest_left
# 126 "data/scripts/players_house.pory"
	delay_16
# 127 "data/scripts/players_house.pory"
	delay_8
# 128 "data/scripts/players_house.pory"
	walk_left
# 129 "data/scripts/players_house.pory"
	step_end
# 130 "data/scripts/players_house.pory"

# 131 "data/scripts/players_house.pory"
PlayersHouse_2F_Movement_MomExitsMale:
# 132 "data/scripts/players_house.pory"
	walk_right
# 133 "data/scripts/players_house.pory"
	walk_up
# 134 "data/scripts/players_house.pory"
	delay_8
# 135 "data/scripts/players_house.pory"
	step_end
# 136 "data/scripts/players_house.pory"

# 137 "data/scripts/players_house.pory"
PlayersHouse_2F_Movement_MomEntersFemale:
# 138 "data/scripts/players_house.pory"
	delay_8
# 139 "data/scripts/players_house.pory"
	walk_down
# 140 "data/scripts/players_house.pory"
	walk_in_place_fastest_right
# 141 "data/scripts/players_house.pory"
	delay_16
# 142 "data/scripts/players_house.pory"
	delay_8
# 143 "data/scripts/players_house.pory"
	walk_right
# 144 "data/scripts/players_house.pory"
	step_end
# 145 "data/scripts/players_house.pory"

# 146 "data/scripts/players_house.pory"
PlayersHouse_2F_Movement_MomExitsFemale:
# 147 "data/scripts/players_house.pory"
	walk_left
# 148 "data/scripts/players_house.pory"
	walk_up
# 149 "data/scripts/players_house.pory"
	delay_8
# 150 "data/scripts/players_house.pory"
	step_end
# 151 "data/scripts/players_house.pory"

# 152 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_SetWatchedBroadcast::
# 153 "data/scripts/players_house.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
# 154 "data/scripts/players_house.pory"
	releaseall
# 155 "data/scripts/players_house.pory"
	end
# 156 "data/scripts/players_house.pory"

# 157 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_PetalburgGymReportMale::
# 158 "data/scripts/players_house.pory"
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFastestRight
# 159 "data/scripts/players_house.pory"
	waitmovement 0
# 160 "data/scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_MomNoticeGymBroadcast
# 161 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForGymMale
# 162 "data/scripts/players_house.pory"
	waitmovement 0
# 163 "data/scripts/players_house.pory"
	playbgm MUS_ENCOUNTER_INTERVIEWER, 0
# 164 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_MaybeDadWillBeOn, MSGBOX_DEFAULT
# 165 "data/scripts/players_house.pory"
	closemessage
# 166 "data/scripts/players_house.pory"
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomMakeRoomToSeeTVMale
# 167 "data/scripts/players_house.pory"
	waitmovement 0
# 168 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerMoveToTVMale
# 169 "data/scripts/players_house.pory"
	waitmovement 0
# 170 "data/scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_WatchGymBroadcast
# 171 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 172 "data/scripts/players_house.pory"
	waitmovement 0
# 173 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_ItsOverWeMissedHim, MSGBOX_DEFAULT
# 174 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor, MSGBOX_DEFAULT
# 175 "data/scripts/players_house.pory"
	closemessage
# 176 "data/scripts/players_house.pory"
	setvar VAR_TEMP_1, 1
# 177 "data/scripts/players_house.pory"
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomReturnToSeatMale
# 178 "data/scripts/players_house.pory"
	waitmovement 0
# 179 "data/scripts/players_house.pory"
	goto PlayersHouse_1F_EventScript_SetWatchedBroadcast
# 180 "data/scripts/players_house.pory"
	end
# 181 "data/scripts/players_house.pory"

# 182 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_PetalburgGymReportFemale::
# 183 "data/scripts/players_house.pory"
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFastestLeft
# 184 "data/scripts/players_house.pory"
	waitmovement 0
# 185 "data/scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_MomNoticeGymBroadcast
# 186 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForGymFemale
# 187 "data/scripts/players_house.pory"
	waitmovement 0
# 188 "data/scripts/players_house.pory"
	playbgm MUS_ENCOUNTER_INTERVIEWER, 0
# 189 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_MaybeDadWillBeOn, MSGBOX_DEFAULT
# 190 "data/scripts/players_house.pory"
	closemessage
# 191 "data/scripts/players_house.pory"
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomMakeRoomToSeeTVFemale
# 192 "data/scripts/players_house.pory"
	waitmovement 0
# 193 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerMoveToTVFemale
# 194 "data/scripts/players_house.pory"
	waitmovement 0
# 195 "data/scripts/players_house.pory"
	call PlayersHouse_1F_EventScript_WatchGymBroadcast
# 196 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 197 "data/scripts/players_house.pory"
	waitmovement 0
# 198 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_ItsOverWeMissedHim, MSGBOX_DEFAULT
# 199 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor, MSGBOX_DEFAULT
# 200 "data/scripts/players_house.pory"
	closemessage
# 201 "data/scripts/players_house.pory"
	setvar VAR_TEMP_1, 1
# 202 "data/scripts/players_house.pory"
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomReturnToSeatFemale
# 203 "data/scripts/players_house.pory"
	waitmovement 0
# 204 "data/scripts/players_house.pory"
	goto PlayersHouse_1F_EventScript_SetWatchedBroadcast
# 205 "data/scripts/players_house.pory"
	end
# 206 "data/scripts/players_house.pory"

# 207 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomNoticeGymBroadcast::
# 208 "data/scripts/players_house.pory"
	playse SE_PIN
# 209 "data/scripts/players_house.pory"
	applymovement VAR_0x8005, Common_Movement_ExclamationMark
# 210 "data/scripts/players_house.pory"
	waitmovement 0
# 211 "data/scripts/players_house.pory"
	applymovement VAR_0x8005, Common_Movement_Delay48
# 212 "data/scripts/players_house.pory"
	waitmovement 0
# 213 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_OhComeQuickly, MSGBOX_DEFAULT
# 214 "data/scripts/players_house.pory"
	closemessage
# 215 "data/scripts/players_house.pory"
	return
# 216 "data/scripts/players_house.pory"

# 217 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_WatchGymBroadcast::
# 218 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 219 "data/scripts/players_house.pory"
	waitmovement 0
# 220 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_ReportFromPetalburgGym, MSGBOX_DEFAULT
# 221 "data/scripts/players_house.pory"
	fadedefaultbgm
# 222 "data/scripts/players_house.pory"
	special TurnOffTVScreen
# 223 "data/scripts/players_house.pory"
	setflag FLAG_SYS_TV_HOME
# 224 "data/scripts/players_house.pory"
	delay 35
# 225 "data/scripts/players_house.pory"
	return
# 226 "data/scripts/players_house.pory"

# 227 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachDadMale:
# 228 "data/scripts/players_house.pory"
	walk_up
# 229 "data/scripts/players_house.pory"
	walk_right
# 230 "data/scripts/players_house.pory"
	walk_right
# 231 "data/scripts/players_house.pory"
	walk_right
# 232 "data/scripts/players_house.pory"
	walk_right
# 233 "data/scripts/players_house.pory"
	walk_down
# 234 "data/scripts/players_house.pory"
	walk_in_place_fastest_right
# 235 "data/scripts/players_house.pory"
	step_end
# 236 "data/scripts/players_house.pory"

# 237 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachDadFemale:
# 238 "data/scripts/players_house.pory"
	walk_up
# 239 "data/scripts/players_house.pory"
	walk_left
# 240 "data/scripts/players_house.pory"
	walk_left
# 241 "data/scripts/players_house.pory"
	walk_left
# 242 "data/scripts/players_house.pory"
	walk_left
# 243 "data/scripts/players_house.pory"
	walk_down
# 244 "data/scripts/players_house.pory"
	walk_in_place_fastest_left
# 245 "data/scripts/players_house.pory"
	step_end
# 246 "data/scripts/players_house.pory"

# 247 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachPlayerMale:
# 248 "data/scripts/players_house.pory"
	walk_right
# 249 "data/scripts/players_house.pory"
	step_end
# 250 "data/scripts/players_house.pory"

# 251 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachPlayerFemale:
# 252 "data/scripts/players_house.pory"
	walk_left
# 253 "data/scripts/players_house.pory"
	step_end
# 254 "data/scripts/players_house.pory"

# 255 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_MomNoticesLatiBroadcastMale:
# 256 "data/scripts/players_house.pory"
	walk_in_place_fastest_left
# 257 "data/scripts/players_house.pory"
	delay_16
# 258 "data/scripts/players_house.pory"
	delay_16
# 259 "data/scripts/players_house.pory"
	delay_16
# 260 "data/scripts/players_house.pory"
	delay_16
# 261 "data/scripts/players_house.pory"
	walk_in_place_fastest_right
# 262 "data/scripts/players_house.pory"
	delay_16
# 263 "data/scripts/players_house.pory"
	delay_16
# 264 "data/scripts/players_house.pory"
	step_end
# 265 "data/scripts/players_house.pory"

# 266 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_MomNoticesLatiBroadcastFemale:
# 267 "data/scripts/players_house.pory"
	walk_in_place_fastest_right
# 268 "data/scripts/players_house.pory"
	delay_16
# 269 "data/scripts/players_house.pory"
	delay_16
# 270 "data/scripts/players_house.pory"
	delay_16
# 271 "data/scripts/players_house.pory"
	delay_16
# 272 "data/scripts/players_house.pory"
	walk_in_place_fastest_left
# 273 "data/scripts/players_house.pory"
	delay_16
# 274 "data/scripts/players_house.pory"
	delay_16
# 275 "data/scripts/players_house.pory"
	step_end
# 276 "data/scripts/players_house.pory"

# 277 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachPlayerAfterTVMale:
# 278 "data/scripts/players_house.pory"
	walk_up
# 279 "data/scripts/players_house.pory"
	walk_left
# 280 "data/scripts/players_house.pory"
	walk_left
# 281 "data/scripts/players_house.pory"
	step_end
# 282 "data/scripts/players_house.pory"

# 283 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_MomApproachPlayerAfterTVFemale:
# 284 "data/scripts/players_house.pory"
	walk_up
# 285 "data/scripts/players_house.pory"
	walk_right
# 286 "data/scripts/players_house.pory"
	walk_right
# 287 "data/scripts/players_house.pory"
	step_end
# 288 "data/scripts/players_house.pory"

# 289 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_MomMakeRoomToSeeTVMale:
# 290 "data/scripts/players_house.pory"
	walk_left
# 291 "data/scripts/players_house.pory"
	walk_in_place_fastest_right
# 292 "data/scripts/players_house.pory"
	step_end
# 293 "data/scripts/players_house.pory"

# 294 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_MomMakeRoomToSeeTVFemale:
# 295 "data/scripts/players_house.pory"
	walk_right
# 296 "data/scripts/players_house.pory"
	walk_in_place_fastest_left
# 297 "data/scripts/players_house.pory"
	step_end
# 298 "data/scripts/players_house.pory"

# 299 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_MomReturnToSeatMale:
# 300 "data/scripts/players_house.pory"
	walk_left
# 301 "data/scripts/players_house.pory"
	walk_down
# 302 "data/scripts/players_house.pory"
	walk_in_place_fastest_right
# 303 "data/scripts/players_house.pory"
	step_end
# 304 "data/scripts/players_house.pory"

# 305 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_MomReturnToSeatFemale:
# 306 "data/scripts/players_house.pory"
	walk_right
# 307 "data/scripts/players_house.pory"
	walk_down
# 308 "data/scripts/players_house.pory"
	walk_in_place_fastest_left
# 309 "data/scripts/players_house.pory"
	step_end
# 310 "data/scripts/players_house.pory"

# 311 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_Mom::
# 312 "data/scripts/players_house.pory"
	lock
# 313 "data/scripts/players_house.pory"
	faceplayer
# 314 "data/scripts/players_house.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_MAY, 4
# 315 "data/scripts/players_house.pory"
	goto_if_eq PlayersHouse_1F_EventScript_DontPushYourselfTooHard
# 316 "data/scripts/players_house.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4
# 317 "data/scripts/players_house.pory"
	goto_if_eq PlayersHouse_1F_EventScript_DontPushYourselfTooHard
# 318 "data/scripts/players_house.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PlayersHouse_1F_EventScript_TryRegisterMom
# 319 "data/scripts/players_house.pory"
	goto_if_set FLAG_RESCUED_BIRCH, PlayersHouse_1F_EventScript_MomHealsParty
# 320 "data/scripts/players_house.pory"
	compare VAR_TEMP_1, 1
# 321 "data/scripts/players_house.pory"
	goto_if_eq PlayersHouse_1F_EventScript_SeeYouHoney
# 322 "data/scripts/players_house.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 7
# 323 "data/scripts/players_house.pory"
	goto_if_eq PlayersHouse_1F_EventScript_DidYouMeetProfBirch
# 324 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_IsntItNiceInHere, MSGBOX_DEFAULT
# 325 "data/scripts/players_house.pory"
	release
# 326 "data/scripts/players_house.pory"
	end
# 327 "data/scripts/players_house.pory"

# 328 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_DontPushYourselfTooHard::
# 329 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
# 330 "data/scripts/players_house.pory"
	release
# 331 "data/scripts/players_house.pory"
	end
# 332 "data/scripts/players_house.pory"

# 333 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_TryRegisterMom::
# 334 "data/scripts/players_house.pory"
	goto_if_set FLAG_ENABLE_MOM_MATCH_CALL, PlayersHouse_1F_EventScript_CheckGiveAmuletCoin
# 335 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_IsThatAPokenav, MSGBOX_DEFAULT
# 336 "data/scripts/players_house.pory"
	closemessage
# 337 "data/scripts/players_house.pory"
	delay 30
# 338 "data/scripts/players_house.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 339 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_RegisteredMom, MSGBOX_DEFAULT
# 340 "data/scripts/players_house.pory"
	waitfanfare
# 341 "data/scripts/players_house.pory"
	closemessage
# 342 "data/scripts/players_house.pory"
	delay 30
# 343 "data/scripts/players_house.pory"
	setflag FLAG_ENABLE_MOM_MATCH_CALL
# 344 "data/scripts/players_house.pory"
	release
# 345 "data/scripts/players_house.pory"
	end
# 346 "data/scripts/players_house.pory"

# 347 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_CheckGiveAmuletCoin::
# 348 "data/scripts/players_house.pory"
	goto_if_set FLAG_BADGE05_GET, PlayersHouse_1F_EventScript_TryGiveAmuletCoin
# 349 "data/scripts/players_house.pory"
	goto PlayersHouse_1F_EventScript_MomHealsParty
# 350 "data/scripts/players_house.pory"

# 351 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_TryGiveAmuletCoin::
# 352 "data/scripts/players_house.pory"
	goto_if_set FLAG_RECEIVED_AMULET_COIN, PlayersHouse_1F_EventScript_MomHealsParty
# 353 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom, MSGBOX_DEFAULT
# 354 "data/scripts/players_house.pory"
	giveitem ITEM_AMULET_COIN
# 355 "data/scripts/players_house.pory"
	compare VAR_RESULT, FALSE
# 356 "data/scripts/players_house.pory"
	goto_if_eq Common_EventScript_ShowBagIsFull
# 357 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
# 358 "data/scripts/players_house.pory"
	setflag FLAG_RECEIVED_AMULET_COIN
# 359 "data/scripts/players_house.pory"
	release
# 360 "data/scripts/players_house.pory"
	end
# 361 "data/scripts/players_house.pory"

# 362 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomHealsParty::
# 363 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_YouShouldRestABit, MSGBOX_DEFAULT
# 364 "data/scripts/players_house.pory"
	goto PlayersHouse_1F_EventScript_HealParty
# 365 "data/scripts/players_house.pory"
	end
# 366 "data/scripts/players_house.pory"

# 367 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_SeeYouHoney::
# 368 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_SeeYouHoney, MSGBOX_DEFAULT
# 369 "data/scripts/players_house.pory"
	release
# 370 "data/scripts/players_house.pory"
	end
# 371 "data/scripts/players_house.pory"

# 372 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_HealParty::
# 373 "data/scripts/players_house.pory"
	closemessage
# 374 "data/scripts/players_house.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 375 "data/scripts/players_house.pory"
	incrementgamestat GAME_STAT_RESTED_AT_HOME
# 376 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_TakeCareHoney, MSGBOX_DEFAULT
# 377 "data/scripts/players_house.pory"
	release
# 378 "data/scripts/players_house.pory"
	end
# 379 "data/scripts/players_house.pory"

# 380 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_DidYouMeetProfBirch::
# 381 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_DidYouMeetProfBirch, MSGBOX_DEFAULT
# 382 "data/scripts/players_house.pory"
	release
# 383 "data/scripts/players_house.pory"
	end
# 384 "data/scripts/players_house.pory"

# 385 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_Vigoroth1::
# 386 "data/scripts/players_house.pory"
	lock
# 387 "data/scripts/players_house.pory"
	faceplayer
# 388 "data/scripts/players_house.pory"
	waitse
# 389 "data/scripts/players_house.pory"
	playmoncry SPECIES_VIGOROTH, 0
# 390 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_Vigoroth1, MSGBOX_DEFAULT
# 391 "data/scripts/players_house.pory"
	waitmoncry
# 392 "data/scripts/players_house.pory"
	release
# 393 "data/scripts/players_house.pory"
	end
# 394 "data/scripts/players_house.pory"

# 395 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_Vigoroth2::
# 396 "data/scripts/players_house.pory"
	lock
# 397 "data/scripts/players_house.pory"
	faceplayer
# 398 "data/scripts/players_house.pory"
	waitse
# 399 "data/scripts/players_house.pory"
	playmoncry SPECIES_VIGOROTH, 0
# 400 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_Vigoroth2, MSGBOX_DEFAULT
# 401 "data/scripts/players_house.pory"
	waitmoncry
# 402 "data/scripts/players_house.pory"
	release
# 403 "data/scripts/players_house.pory"
	end
# 404 "data/scripts/players_house.pory"

# 405 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerApproachTVForGymMale:
# 406 "data/scripts/players_house.pory"
	walk_down
# 407 "data/scripts/players_house.pory"
	walk_down
# 408 "data/scripts/players_house.pory"
	walk_left
# 409 "data/scripts/players_house.pory"
	walk_left
# 410 "data/scripts/players_house.pory"
	walk_left
# 411 "data/scripts/players_house.pory"
	step_end
# 412 "data/scripts/players_house.pory"

# 413 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerMoveToTVMale:
# 414 "data/scripts/players_house.pory"
	walk_left
# 415 "data/scripts/players_house.pory"
	step_end
# 416 "data/scripts/players_house.pory"

# 417 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerApproachTVForGymFemale:
# 418 "data/scripts/players_house.pory"
	walk_down
# 419 "data/scripts/players_house.pory"
	walk_down
# 420 "data/scripts/players_house.pory"
	walk_right
# 421 "data/scripts/players_house.pory"
	walk_right
# 422 "data/scripts/players_house.pory"
	walk_right
# 423 "data/scripts/players_house.pory"
	step_end
# 424 "data/scripts/players_house.pory"

# 425 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerMoveToTVFemale:
# 426 "data/scripts/players_house.pory"
	walk_right
# 427 "data/scripts/players_house.pory"
	step_end
# 428 "data/scripts/players_house.pory"

# 429 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_MovePlayerAwayFromDoor:
# 430 "data/scripts/players_house.pory"
	walk_up
# 431 "data/scripts/players_house.pory"
	step_end
# 432 "data/scripts/players_house.pory"

# 433 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV::
# 434 "data/scripts/players_house.pory"
	lockall
# 435 "data/scripts/players_house.pory"
	checkplayergender
# 436 "data/scripts/players_house.pory"
	compare VAR_RESULT, MALE
# 437 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_SetUpObjectEventVarsMale
# 438 "data/scripts/players_house.pory"
	compare VAR_RESULT, FEMALE
# 439 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_SetUpObjectEventVarsFemale
# 440 "data/scripts/players_house.pory"
	compare VAR_0x8008, MALE
# 441 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_PlayerEnterRoomMale
# 442 "data/scripts/players_house.pory"
	compare VAR_0x8008, FEMALE
# 443 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_PlayerEnterRoomFemale
# 444 "data/scripts/players_house.pory"
	applymovement VAR_0x8009, Common_Movement_FacePlayer
# 445 "data/scripts/players_house.pory"
	waitmovement 0
# 446 "data/scripts/players_house.pory"
	playse SE_PIN
# 447 "data/scripts/players_house.pory"
	applymovement VAR_0x8009, Common_Movement_ExclamationMark
# 448 "data/scripts/players_house.pory"
	waitmovement 0
# 449 "data/scripts/players_house.pory"
	applymovement VAR_0x8009, Common_Movement_Delay48
# 450 "data/scripts/players_house.pory"
	waitmovement 0
# 451 "data/scripts/players_house.pory"
	delay 20
# 452 "data/scripts/players_house.pory"
	compare VAR_0x8008, MALE
# 453 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_DadApproachPlayerMale
# 454 "data/scripts/players_house.pory"
	compare VAR_0x8008, FEMALE
# 455 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_DadApproachPlayerFemale
# 456 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_TicketFromBrineyCameForYou, MSGBOX_DEFAULT
# 457 "data/scripts/players_house.pory"
	giveitem ITEM_SS_TICKET
# 458 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_PortsInSlateportLilycove, MSGBOX_DEFAULT
# 459 "data/scripts/players_house.pory"
	closemessage
# 460 "data/scripts/players_house.pory"
	delay 20
# 461 "data/scripts/players_house.pory"
	compare VAR_0x8008, MALE
# 462 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_MomApproachDadMale
# 463 "data/scripts/players_house.pory"
	compare VAR_0x8008, FEMALE
# 464 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_MomApproachDadFemale
# 465 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_BetterGetBackToGym, MSGBOX_DEFAULT
# 466 "data/scripts/players_house.pory"
	closemessage
# 467 "data/scripts/players_house.pory"
	compare VAR_0x8008, MALE
# 468 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_DadExitsMale
# 469 "data/scripts/players_house.pory"
	compare VAR_0x8008, FEMALE
# 470 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_DadExitsFemale
# 471 "data/scripts/players_house.pory"
	playse SE_DOOR
# 472 "data/scripts/players_house.pory"
	removeobject VAR_0x8009
# 473 "data/scripts/players_house.pory"
	setflag FLAG_RECEIVED_SS_TICKET
# 474 "data/scripts/players_house.pory"
	delay 30
# 475 "data/scripts/players_house.pory"
	compare VAR_0x8008, MALE
# 476 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_MomApproachPlayerMale
# 477 "data/scripts/players_house.pory"
	compare VAR_0x8008, FEMALE
# 478 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_MomApproachPlayerFemale
# 479 "data/scripts/players_house.pory"
	delay 20
# 480 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_DadShouldStayLonger, MSGBOX_DEFAULT
# 481 "data/scripts/players_house.pory"
	closemessage
# 482 "data/scripts/players_house.pory"
	setflag FLAG_SYS_TV_LATIAS_LATIOS
# 483 "data/scripts/players_house.pory"
	special TurnOnTVScreen
# 484 "data/scripts/players_house.pory"
	delay 60
# 485 "data/scripts/players_house.pory"
	compare VAR_0x8008, MALE
# 486 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastMale
# 487 "data/scripts/players_house.pory"
	compare VAR_0x8008, FEMALE
# 488 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastFemale
# 489 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_IsThatABreakingStory, MSGBOX_DEFAULT
# 490 "data/scripts/players_house.pory"
	closemessage
# 491 "data/scripts/players_house.pory"
	compare VAR_0x8008, MALE
# 492 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_PlayerApproachTVForLatiMale
# 493 "data/scripts/players_house.pory"
	compare VAR_0x8008, FEMALE
# 494 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_PlayerApproachTVForLatiFemale
# 495 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_LatiEmergencyNewsFlash, MSGBOX_DEFAULT
# 496 "data/scripts/players_house.pory"
	closemessage
# 497 "data/scripts/players_house.pory"
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
# 498 "data/scripts/players_house.pory"
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
# 499 "data/scripts/players_house.pory"
	special TurnOffTVScreen
# 500 "data/scripts/players_house.pory"
	compare VAR_0x8008, MALE
# 501 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVMale
# 502 "data/scripts/players_house.pory"
	compare VAR_0x8008, FEMALE
# 503 "data/scripts/players_house.pory"
	call_if_eq PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVFemale
# 504 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_WhatColorDidTheySay, MSGBOX_DEFAULT
# 505 "data/scripts/players_house.pory"
	multichoice 22, 8, MULTI_TV_LATI, 1
# 506 "data/scripts/players_house.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 507 "data/scripts/players_house.pory"
	copyvar VAR_ROAMER_POKEMON, VAR_RESULT
# 508 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_StillUnknownPokemon, MSGBOX_DEFAULT
# 509 "data/scripts/players_house.pory"
	closemessage
# 510 "data/scripts/players_house.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 4
# 511 "data/scripts/players_house.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4
# 512 "data/scripts/players_house.pory"
	releaseall
# 513 "data/scripts/players_house.pory"
	end
# 514 "data/scripts/players_house.pory"

# 515 "data/scripts/players_house.pory"
@ Never called.
# 516 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_AirLatiBroadcast::
# 517 "data/scripts/players_house.pory"
	setflag FLAG_SYS_TV_LATIAS_LATIOS
# 518 "data/scripts/players_house.pory"
	return
# 519 "data/scripts/players_house.pory"

# 520 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_SetUpObjectEventVarsMale::
# 521 "data/scripts/players_house.pory"
	setvar VAR_0x8008, MALE
# 522 "data/scripts/players_house.pory"
	setvar VAR_0x8009, LOCALID_DAD
# 523 "data/scripts/players_house.pory"
	setvar VAR_0x800A, LOCALID_MOM
# 524 "data/scripts/players_house.pory"
	return
# 525 "data/scripts/players_house.pory"

# 526 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_SetUpObjectEventVarsFemale::
# 527 "data/scripts/players_house.pory"
	setvar VAR_0x8008, FEMALE
# 528 "data/scripts/players_house.pory"
	setvar VAR_0x8009, LOCALID_DAD
# 529 "data/scripts/players_house.pory"
	setvar VAR_0x800A, LOCALID_MOM
# 530 "data/scripts/players_house.pory"
	return
# 531 "data/scripts/players_house.pory"

# 532 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_DadApproachPlayerMale::
# 533 "data/scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadApproachPlayerMale
# 534 "data/scripts/players_house.pory"
	waitmovement 0
# 535 "data/scripts/players_house.pory"
	return
# 536 "data/scripts/players_house.pory"

# 537 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_DadApproachPlayerFemale::
# 538 "data/scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadApproachPlayerFemale
# 539 "data/scripts/players_house.pory"
	waitmovement 0
# 540 "data/scripts/players_house.pory"
	return
# 541 "data/scripts/players_house.pory"

# 542 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachDadMale::
# 543 "data/scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachDadMale
# 544 "data/scripts/players_house.pory"
	waitmovement 0
# 545 "data/scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadFaceMomMale
# 546 "data/scripts/players_house.pory"
	waitmovement 0
# 547 "data/scripts/players_house.pory"
	return
# 548 "data/scripts/players_house.pory"

# 549 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachDadFemale::
# 550 "data/scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachDadFemale
# 551 "data/scripts/players_house.pory"
	waitmovement 0
# 552 "data/scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadFaceMomFemale
# 553 "data/scripts/players_house.pory"
	waitmovement 0
# 554 "data/scripts/players_house.pory"
	return
# 555 "data/scripts/players_house.pory"

# 556 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_DadExitsMale::
# 557 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
# 558 "data/scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
# 559 "data/scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadExitsMale
# 560 "data/scripts/players_house.pory"
	waitmovement 0
# 561 "data/scripts/players_house.pory"
	return
# 562 "data/scripts/players_house.pory"

# 563 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_DadExitsFemale::
# 564 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
# 565 "data/scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
# 566 "data/scripts/players_house.pory"
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadExitsFemale
# 567 "data/scripts/players_house.pory"
	waitmovement 0
# 568 "data/scripts/players_house.pory"
	return
# 569 "data/scripts/players_house.pory"

# 570 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_PlayerEnterRoomMale::
# 571 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerEnterRoomMale
# 572 "data/scripts/players_house.pory"
	waitmovement 0
# 573 "data/scripts/players_house.pory"
	return
# 574 "data/scripts/players_house.pory"

# 575 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_PlayerEnterRoomFemale::
# 576 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerEnterRoomFemale
# 577 "data/scripts/players_house.pory"
	waitmovement 0
# 578 "data/scripts/players_house.pory"
	return
# 579 "data/scripts/players_house.pory"

# 580 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_PlayerApproachTVForLatiMale::
# 581 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForLatiMale
# 582 "data/scripts/players_house.pory"
	waitmovement 0
# 583 "data/scripts/players_house.pory"
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceFastestLeft
# 584 "data/scripts/players_house.pory"
	waitmovement 0
# 585 "data/scripts/players_house.pory"
	return
# 586 "data/scripts/players_house.pory"

# 587 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_PlayerApproachTVForLatiFemale::
# 588 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForLatiFemale
# 589 "data/scripts/players_house.pory"
	waitmovement 0
# 590 "data/scripts/players_house.pory"
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceFastestRight
# 591 "data/scripts/players_house.pory"
	waitmovement 0
# 592 "data/scripts/players_house.pory"
	return
# 593 "data/scripts/players_house.pory"

# 594 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachPlayerMale::
# 595 "data/scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerMale
# 596 "data/scripts/players_house.pory"
	waitmovement 0
# 597 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 598 "data/scripts/players_house.pory"
	waitmovement 0
# 599 "data/scripts/players_house.pory"
	return
# 600 "data/scripts/players_house.pory"

# 601 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachPlayerFemale::
# 602 "data/scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerFemale
# 603 "data/scripts/players_house.pory"
	waitmovement 0
# 604 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 605 "data/scripts/players_house.pory"
	waitmovement 0
# 606 "data/scripts/players_house.pory"
	return
# 607 "data/scripts/players_house.pory"

# 608 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastMale::
# 609 "data/scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomNoticesLatiBroadcastMale
# 610 "data/scripts/players_house.pory"
	waitmovement 0
# 611 "data/scripts/players_house.pory"
	return
# 612 "data/scripts/players_house.pory"

# 613 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastFemale::
# 614 "data/scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomNoticesLatiBroadcastFemale
# 615 "data/scripts/players_house.pory"
	waitmovement 0
# 616 "data/scripts/players_house.pory"
	return
# 617 "data/scripts/players_house.pory"

# 618 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVMale::
# 619 "data/scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerAfterTVMale
# 620 "data/scripts/players_house.pory"
	waitmovement 0
# 621 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
# 622 "data/scripts/players_house.pory"
	waitmovement 0
# 623 "data/scripts/players_house.pory"
	return
# 624 "data/scripts/players_house.pory"

# 625 "data/scripts/players_house.pory"
PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVFemale::
# 626 "data/scripts/players_house.pory"
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerAfterTVFemale
# 627 "data/scripts/players_house.pory"
	waitmovement 0
# 628 "data/scripts/players_house.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
# 629 "data/scripts/players_house.pory"
	waitmovement 0
# 630 "data/scripts/players_house.pory"
	return
# 631 "data/scripts/players_house.pory"

# 632 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_DadApproachPlayerMale:
# 633 "data/scripts/players_house.pory"
	walk_right
# 634 "data/scripts/players_house.pory"
	walk_right
# 635 "data/scripts/players_house.pory"
	step_end
# 636 "data/scripts/players_house.pory"

# 637 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_DadApproachPlayerFemale:
# 638 "data/scripts/players_house.pory"
	walk_left
# 639 "data/scripts/players_house.pory"
	walk_left
# 640 "data/scripts/players_house.pory"
	step_end
# 641 "data/scripts/players_house.pory"

# 642 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_DadFaceMomMale:
# 643 "data/scripts/players_house.pory"
	face_left
# 644 "data/scripts/players_house.pory"
	step_end
# 645 "data/scripts/players_house.pory"

# 646 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_DadFaceMomFemale:
# 647 "data/scripts/players_house.pory"
	face_right
# 648 "data/scripts/players_house.pory"
	step_end
# 649 "data/scripts/players_house.pory"

# 650 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_DadExitsMale:
# 651 "data/scripts/players_house.pory"
	walk_down
# 652 "data/scripts/players_house.pory"
	walk_right
# 653 "data/scripts/players_house.pory"
	walk_down
# 654 "data/scripts/players_house.pory"
	delay_8
# 655 "data/scripts/players_house.pory"
	step_end
# 656 "data/scripts/players_house.pory"

# 657 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_DadExitsFemale:
# 658 "data/scripts/players_house.pory"
	walk_down
# 659 "data/scripts/players_house.pory"
	walk_left
# 660 "data/scripts/players_house.pory"
	walk_down
# 661 "data/scripts/players_house.pory"
	delay_8
# 662 "data/scripts/players_house.pory"
	step_end
# 663 "data/scripts/players_house.pory"

# 664 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerEnterRoomMale:
# 665 "data/scripts/players_house.pory"
	delay_16
# 666 "data/scripts/players_house.pory"
	walk_down
# 667 "data/scripts/players_house.pory"
	walk_down
# 668 "data/scripts/players_house.pory"
	walk_down
# 669 "data/scripts/players_house.pory"
	walk_in_place_fastest_left
# 670 "data/scripts/players_house.pory"
	step_end
# 671 "data/scripts/players_house.pory"

# 672 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit:
# 673 "data/scripts/players_house.pory"
	delay_8
# 674 "data/scripts/players_house.pory"
	delay_16
# 675 "data/scripts/players_house.pory"
	delay_16
# 676 "data/scripts/players_house.pory"
	walk_in_place_fastest_down
# 677 "data/scripts/players_house.pory"
	step_end
# 678 "data/scripts/players_house.pory"

# 679 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerEnterRoomFemale:
# 680 "data/scripts/players_house.pory"
	delay_16
# 681 "data/scripts/players_house.pory"
	walk_down
# 682 "data/scripts/players_house.pory"
	walk_down
# 683 "data/scripts/players_house.pory"
	walk_down
# 684 "data/scripts/players_house.pory"
	walk_in_place_fastest_right
# 685 "data/scripts/players_house.pory"
	step_end
# 686 "data/scripts/players_house.pory"

# 687 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerApproachTVForLatiMale:
# 688 "data/scripts/players_house.pory"
	walk_up
# 689 "data/scripts/players_house.pory"
	walk_left
# 690 "data/scripts/players_house.pory"
	walk_left
# 691 "data/scripts/players_house.pory"
	walk_left
# 692 "data/scripts/players_house.pory"
	walk_left
# 693 "data/scripts/players_house.pory"
	walk_in_place_fastest_up
# 694 "data/scripts/players_house.pory"
	step_end
# 695 "data/scripts/players_house.pory"

# 696 "data/scripts/players_house.pory"
PlayersHouse_1F_Movement_PlayerApproachTVForLatiFemale:
# 697 "data/scripts/players_house.pory"
	walk_up
# 698 "data/scripts/players_house.pory"
	walk_right
# 699 "data/scripts/players_house.pory"
	walk_right
# 700 "data/scripts/players_house.pory"
	walk_right
# 701 "data/scripts/players_house.pory"
	walk_right
# 702 "data/scripts/players_house.pory"
	walk_in_place_fastest_up
# 703 "data/scripts/players_house.pory"
	step_end
# 704 "data/scripts/players_house.pory"

# 705 "data/scripts/players_house.pory"
EventScript_RunningShoesManual::
# 706 "data/scripts/players_house.pory"
	msgbox PlayersHouse_1F_Text_RunningShoesManual, MSGBOX_SIGN
# 707 "data/scripts/players_house.pory"
	end
