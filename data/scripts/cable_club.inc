# 1 "data/scripts/cable_club.pory"

# 2 "data/scripts/cable_club.pory"
CableClub_OnTransition: @ 8276ACF
# 3 "data/scripts/cable_club.pory"
	call CableClub_EventScript_HideOrShowMysteryGiftMan
# 4 "data/scripts/cable_club.pory"
	end
# 5 "data/scripts/cable_club.pory"

# 6 "data/scripts/cable_club.pory"
CableClub_EventScript_HideOrShowMysteryGiftMan:: @ 8276AD5
# 7 "data/scripts/cable_club.pory"
	specialvar VAR_RESULT, ShouldDistributeEonTicket
# 8 "data/scripts/cable_club.pory"
	compare VAR_RESULT, TRUE
# 9 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_ShowMysteryGiftMan
# 10 "data/scripts/cable_club.pory"
	specialvar VAR_RESULT, ValidateReceivedWonderCard
# 11 "data/scripts/cable_club.pory"
	compare VAR_RESULT, FALSE
# 12 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_HideMysteryGiftMan
# 13 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_ShowMysteryGiftMan
# 14 "data/scripts/cable_club.pory"
	end
# 15 "data/scripts/cable_club.pory"

# 16 "data/scripts/cable_club.pory"
CableClub_EventScript_ShowMysteryGiftMan:: @ 8276AFB
# 17 "data/scripts/cable_club.pory"
	clearflag FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN
# 18 "data/scripts/cable_club.pory"
	return
# 19 "data/scripts/cable_club.pory"

# 20 "data/scripts/cable_club.pory"
CableClub_EventScript_HideMysteryGiftMan:: @ 8276AFF
# 21 "data/scripts/cable_club.pory"
	setflag FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN
# 22 "data/scripts/cable_club.pory"
	return
# 23 "data/scripts/cable_club.pory"

# 24 "data/scripts/cable_club.pory"
CableClub_EventScript_MysteryGiftMan:: @ 8276B03
# 25 "data/scripts/cable_club.pory"
	specialvar VAR_RESULT, ShouldDistributeEonTicket
# 26 "data/scripts/cable_club.pory"
	compare VAR_RESULT, TRUE
# 27 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_DistributeEonTicket
# 28 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_AlreadyGotEonTicket
# 29 "data/scripts/cable_club.pory"
	end
# 30 "data/scripts/cable_club.pory"

# 31 "data/scripts/cable_club.pory"
CableClub_EventScript_AlreadyGotEonTicket:: @ 8276B19
# 32 "data/scripts/cable_club.pory"
	gotoram
# 33 "data/scripts/cable_club.pory"

# 34 "data/scripts/cable_club.pory"
@ Unused?
# 35 "data/scripts/cable_club.pory"
CableClub_EventScript_MysteryGiftThankYou:: @ 8276B1A
# 36 "data/scripts/cable_club.pory"
	msgbox gText_ThankYouForAccessingMysteryGift, MSGBOX_NPC
# 37 "data/scripts/cable_club.pory"
	end
# 38 "data/scripts/cable_club.pory"

# 39 "data/scripts/cable_club.pory"
CableClub_EventScript_DistributeEonTicket:: @ 8276B23
# 40 "data/scripts/cable_club.pory"
	checkitem ITEM_EON_TICKET, 1
# 41 "data/scripts/cable_club.pory"
	compare VAR_RESULT, TRUE
# 42 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AlreadyGotEonTicket
# 43 "data/scripts/cable_club.pory"
	goto_if_set FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, CableClub_EventScript_AlreadyGotEonTicket
# 44 "data/scripts/cable_club.pory"
	msgbox Mevent_Text_TheresATicketForYou, MSGBOX_DEFAULT
# 45 "data/scripts/cable_club.pory"
	giveitem ITEM_EON_TICKET
# 46 "data/scripts/cable_club.pory"
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
# 47 "data/scripts/cable_club.pory"
	setvar VAR_DISTRIBUTE_EON_TICKET, 0
# 48 "data/scripts/cable_club.pory"
	msgbox Mevent_Text_TryUsingItAtLilycovePort, MSGBOX_DEFAULT
# 49 "data/scripts/cable_club.pory"
	release
# 50 "data/scripts/cable_club.pory"
	end
# 51 "data/scripts/cable_club.pory"

# 52 "data/scripts/cable_club.pory"
@ Unused?
# 53 "data/scripts/cable_club.pory"
CableClub_EventScript_MysteryGiftThankYou2:: @ 8276B62
# 54 "data/scripts/cable_club.pory"
	msgbox gText_ThankYouForAccessingMysteryGift, MSGBOX_DEFAULT
# 55 "data/scripts/cable_club.pory"
	release
# 56 "data/scripts/cable_club.pory"
	end
# 57 "data/scripts/cable_club.pory"

# 58 "data/scripts/cable_club.pory"
CableClub_OnWarp: @ 8276B6C
# 59 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, CableClub_EventScript_CheckTurnAttendant
# 60 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, CableClub_EventScript_CheckTurnAttendant
# 61 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, CableClub_EventScript_CheckTurnAttendant
# 62 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, CableClub_EventScript_CheckTurnAttendant
# 63 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_RECORD_CORNER, CableClub_EventScript_CheckTurnAttendant
# 64 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, CableClub_EventScript_CheckTurnAttendant
# 65 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, CableClub_EventScript_CheckTurnAttendant
# 66 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
# 67 "data/scripts/cable_club.pory"
	.2byte 0
# 68 "data/scripts/cable_club.pory"

# 69 "data/scripts/cable_club.pory"
CableClub_EventScript_CheckTurnAttendant:: @ 8276BAE
# 70 "data/scripts/cable_club.pory"
	compare VAR_0x8007, 0
# 71 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_DontTurnAttendant
# 72 "data/scripts/cable_club.pory"
	turnobject VAR_0x8007, DIR_WEST
# 73 "data/scripts/cable_club.pory"
CableClub_EventScript_DontTurnAttendant:: @ 8276BBD
# 74 "data/scripts/cable_club.pory"
	end
# 75 "data/scripts/cable_club.pory"

# 76 "data/scripts/cable_club.pory"
CableClub_OnLoad: @ 8276BBE
# 77 "data/scripts/cable_club.pory"
	compare VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE
# 78 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_OnLoadFromColosseum
# 79 "data/scripts/cable_club.pory"
	compare VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE
# 80 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_OnLoadFromColosseum
# 81 "data/scripts/cable_club.pory"
	compare VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE
# 82 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_OnLoadFromColosseum
# 83 "data/scripts/cable_club.pory"
	compare VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER
# 84 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_OnLoadFromTradeCenter
# 85 "data/scripts/cable_club.pory"
	compare VAR_CABLE_CLUB_STATE, USING_RECORD_CORNER
# 86 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_OnLoadFromRecordCorner
# 87 "data/scripts/cable_club.pory"
	compare VAR_CABLE_CLUB_STATE, USING_UNION_ROOM
# 88 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_OnLoadFromUnionRoom
# 89 "data/scripts/cable_club.pory"
	compare VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH
# 90 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_OnLoadFromBerryCrush
# 91 "data/scripts/cable_club.pory"
	compare VAR_CABLE_CLUB_STATE, USING_MINIGAME
# 92 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_OnLoadFromGameCorner
# 93 "data/scripts/cable_club.pory"
	end
# 94 "data/scripts/cable_club.pory"

# 95 "data/scripts/cable_club.pory"
CableClub_EventScript_OnLoadFromColosseum:: @ 8276C17
# 96 "data/scripts/cable_club.pory"
	call CableClub_EventScript_OpenDirectCornerBarrier
# 97 "data/scripts/cable_club.pory"
	end
# 98 "data/scripts/cable_club.pory"

# 99 "data/scripts/cable_club.pory"
CableClub_EventScript_OnLoadFromTradeCenter:: @ 8276C1D
# 100 "data/scripts/cable_club.pory"
	call CableClub_EventScript_OpenDirectCornerBarrier
# 101 "data/scripts/cable_club.pory"
	end
# 102 "data/scripts/cable_club.pory"

# 103 "data/scripts/cable_club.pory"
CableClub_EventScript_OnLoadFromRecordCorner:: @ 8276C23
# 104 "data/scripts/cable_club.pory"
	call CableClub_EventScript_OpenDirectCornerBarrier
# 105 "data/scripts/cable_club.pory"
	end
# 106 "data/scripts/cable_club.pory"

# 107 "data/scripts/cable_club.pory"
CableClub_EventScript_OnLoadFromUnionRoom:: @ 8276C29
# 108 "data/scripts/cable_club.pory"
	call CableClub_EventScript_OpenUnionRoomBarrier
# 109 "data/scripts/cable_club.pory"
	end
# 110 "data/scripts/cable_club.pory"

# 111 "data/scripts/cable_club.pory"
CableClub_EventScript_OnLoadFromBerryCrush:: @ 8276C2F
# 112 "data/scripts/cable_club.pory"
	call CableClub_EventScript_OpenDirectCornerBarrier
# 113 "data/scripts/cable_club.pory"
	end
# 114 "data/scripts/cable_club.pory"

# 115 "data/scripts/cable_club.pory"
CableClub_EventScript_OnLoadFromGameCorner:: @ 8276C35
# 116 "data/scripts/cable_club.pory"
	call EventScript_OpenMossdeepGameCornerBarrier
# 117 "data/scripts/cable_club.pory"
	end
# 118 "data/scripts/cable_club.pory"

# 119 "data/scripts/cable_club.pory"
CableClub_OnFrame: @ 8276C3B
# 120 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_TUTORIAL_STATE, 1, CableClub_EventScript_Tutorial
# 121 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, CableClub_EventScript_ExitLinkRoom
# 122 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, CableClub_EventScript_ExitLinkRoom
# 123 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, CableClub_EventScript_ExitLinkRoom
# 124 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, CableClub_EventScript_ExitTradeCenter
# 125 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_RECORD_CORNER, CableClub_EventScript_ExitRecordCorner
# 126 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, CableClub_EventScript_ExitUnionRoom
# 127 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, CableClub_EventScript_ExitLinkRoom
# 128 "data/scripts/cable_club.pory"
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
# 129 "data/scripts/cable_club.pory"
	.2byte 0
# 130 "data/scripts/cable_club.pory"

# 131 "data/scripts/cable_club.pory"
CableClub_EventScript_ExitLinkRoom:: @ 8276C85
# 132 "data/scripts/cable_club.pory"
	lockall
# 133 "data/scripts/cable_club.pory"
	call CableClub_EventScript_CloseLinkAndExitLinkRoom
# 134 "data/scripts/cable_club.pory"
	call CableClub_EventScript_CloseDirectCornerBarrier
# 135 "data/scripts/cable_club.pory"
	special DrawWholeMapView
# 136 "data/scripts/cable_club.pory"
	playse SE_CLICK
# 137 "data/scripts/cable_club.pory"
	erasebox 0, 0, 29, 19
# 138 "data/scripts/cable_club.pory"
	releaseall
# 139 "data/scripts/cable_club.pory"
	end
# 140 "data/scripts/cable_club.pory"

# 141 "data/scripts/cable_club.pory"
CableClub_EventScript_ExitMinigameRoom:: @ 8276C9D
# 142 "data/scripts/cable_club.pory"
	lockall
# 143 "data/scripts/cable_club.pory"
	call CableClub_EventScript_CloseLinkAndExitLinkRoom
# 144 "data/scripts/cable_club.pory"
	call EventScript_CloseMossdeepGameCornerBarrier
# 145 "data/scripts/cable_club.pory"
	special DrawWholeMapView
# 146 "data/scripts/cable_club.pory"
	playse SE_CLICK
# 147 "data/scripts/cable_club.pory"
	erasebox 0, 0, 29, 19
# 148 "data/scripts/cable_club.pory"
	releaseall
# 149 "data/scripts/cable_club.pory"
	end
# 150 "data/scripts/cable_club.pory"

# 151 "data/scripts/cable_club.pory"
CableClub_EventScript_CloseLinkAndExitLinkRoom:: @ 8276CB5
# 152 "data/scripts/cable_club.pory"
	special CloseLink
# 153 "data/scripts/cable_club.pory"
	setvar VAR_CABLE_CLUB_STATE, 0
# 154 "data/scripts/cable_club.pory"
	compare VAR_0x8007, 0
# 155 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_PlayerExitLinkRoom
# 156 "data/scripts/cable_club.pory"
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
# 157 "data/scripts/cable_club.pory"
	waitmovement 0
# 158 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerExitLinkRoom
# 159 "data/scripts/cable_club.pory"
	waitmovement 0
# 160 "data/scripts/cable_club.pory"
	applymovement VAR_0x8007, Movement_AttendantFaceDown
# 161 "data/scripts/cable_club.pory"
	waitmovement 0
# 162 "data/scripts/cable_club.pory"
	return
# 163 "data/scripts/cable_club.pory"

# 164 "data/scripts/cable_club.pory"
CableClub_EventScript_ExitTradeCenter:: @ 8276CE7
# 165 "data/scripts/cable_club.pory"
	lockall
# 166 "data/scripts/cable_club.pory"
	call CableClub_EventScript_PlayerExitTradeCenter
# 167 "data/scripts/cable_club.pory"
	call CableClub_EventScript_CloseDirectCornerBarrier
# 168 "data/scripts/cable_club.pory"
	special DrawWholeMapView
# 169 "data/scripts/cable_club.pory"
	playse SE_CLICK
# 170 "data/scripts/cable_club.pory"
	erasebox 0, 0, 29, 19
# 171 "data/scripts/cable_club.pory"
	releaseall
# 172 "data/scripts/cable_club.pory"
	end
# 173 "data/scripts/cable_club.pory"

# 174 "data/scripts/cable_club.pory"
CableClub_EventScript_PlayerExitTradeCenter:: @ 8276CFF
# 175 "data/scripts/cable_club.pory"
	special CloseLink
# 176 "data/scripts/cable_club.pory"
	setvar VAR_CABLE_CLUB_STATE, 0
# 177 "data/scripts/cable_club.pory"
	compare VAR_0x8007, 0
# 178 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_PlayerExitLinkRoom
# 179 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerFaceAttendantRight
# 180 "data/scripts/cable_club.pory"
	waitmovement 0
# 181 "data/scripts/cable_club.pory"
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
# 182 "data/scripts/cable_club.pory"
	waitmovement 0
# 183 "data/scripts/cable_club.pory"
	call CableClub_EventScript_TrainerCardDataOverwritten
# 184 "data/scripts/cable_club.pory"
	return
# 185 "data/scripts/cable_club.pory"

# 186 "data/scripts/cable_club.pory"
CableClub_EventScript_ExitRecordCorner:: @ 8276D2C
# 187 "data/scripts/cable_club.pory"
	lockall
# 188 "data/scripts/cable_club.pory"
	call CableClub_EventScript_PlayerExitRecordCorner
# 189 "data/scripts/cable_club.pory"
	call CableClub_EventScript_CloseDirectCornerBarrier
# 190 "data/scripts/cable_club.pory"
	special DrawWholeMapView
# 191 "data/scripts/cable_club.pory"
	playse SE_CLICK
# 192 "data/scripts/cable_club.pory"
	erasebox 0, 0, 29, 19
# 193 "data/scripts/cable_club.pory"
	releaseall
# 194 "data/scripts/cable_club.pory"
	end
# 195 "data/scripts/cable_club.pory"

# 196 "data/scripts/cable_club.pory"
CableClub_EventScript_PlayerExitRecordCorner:: @ 8276D44
# 197 "data/scripts/cable_club.pory"
	special CloseLink
# 198 "data/scripts/cable_club.pory"
	setvar VAR_CABLE_CLUB_STATE, 0
# 199 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerExitLinkRoom
# 200 "data/scripts/cable_club.pory"
	waitmovement 0
# 201 "data/scripts/cable_club.pory"
	compare VAR_0x8007, 0
# 202 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_ExitRecordCornerRet
# 203 "data/scripts/cable_club.pory"
	applymovement VAR_0x8007, Movement_AttendantFaceDown
# 204 "data/scripts/cable_club.pory"
	waitmovement 0
# 205 "data/scripts/cable_club.pory"
CableClub_EventScript_ExitRecordCornerRet:: @ 8276D6B
# 206 "data/scripts/cable_club.pory"
	return
# 207 "data/scripts/cable_club.pory"

# 208 "data/scripts/cable_club.pory"
CableClub_EventScript_ExitUnionRoom:: @ 8276D6C
# 209 "data/scripts/cable_club.pory"
	lockall
# 210 "data/scripts/cable_club.pory"
	call CableClub_EventScript_PlayerExitUnionRoom
# 211 "data/scripts/cable_club.pory"
	call CableClub_EventScript_CloseUnionRoomBarrier
# 212 "data/scripts/cable_club.pory"
	special DrawWholeMapView
# 213 "data/scripts/cable_club.pory"
	playse SE_CLICK
# 214 "data/scripts/cable_club.pory"
	erasebox 0, 0, 29, 19
# 215 "data/scripts/cable_club.pory"
	releaseall
# 216 "data/scripts/cable_club.pory"
	end
# 217 "data/scripts/cable_club.pory"

# 218 "data/scripts/cable_club.pory"
CableClub_EventScript_PlayerExitUnionRoom:: @ 8276D84
# 219 "data/scripts/cable_club.pory"
	setvar VAR_CABLE_CLUB_STATE, 0
# 220 "data/scripts/cable_club.pory"
	compare VAR_0x8007, 0
# 221 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_PlayerExitLinkRoom
# 222 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerFaceAttendantRight
# 223 "data/scripts/cable_club.pory"
	waitmovement 0
# 224 "data/scripts/cable_club.pory"
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
# 225 "data/scripts/cable_club.pory"
	waitmovement 0
# 226 "data/scripts/cable_club.pory"
	call CableClub_EventScript_TrainerCardDataOverwritten
# 227 "data/scripts/cable_club.pory"
	return
# 228 "data/scripts/cable_club.pory"

# 229 "data/scripts/cable_club.pory"
CableClub_EventScript_TrainerCardDataOverwritten:: @ 8276DAE
# 230 "data/scripts/cable_club.pory"
	message CableClub_Text_TrainerCardDataOverwritten
# 231 "data/scripts/cable_club.pory"
	waitmessage
# 232 "data/scripts/cable_club.pory"
	playse SE_PIN
# 233 "data/scripts/cable_club.pory"
	delay 60
# 234 "data/scripts/cable_club.pory"
	message CableClub_Text_HopeToSeeYouAgain
# 235 "data/scripts/cable_club.pory"
	waitmessage
# 236 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerExitLinkRoom
# 237 "data/scripts/cable_club.pory"
	waitmovement 0
# 238 "data/scripts/cable_club.pory"
	applymovement VAR_0x8007, Movement_AttendantFaceDown
# 239 "data/scripts/cable_club.pory"
	waitmovement 0
# 240 "data/scripts/cable_club.pory"
	return
# 241 "data/scripts/cable_club.pory"

# 242 "data/scripts/cable_club.pory"
CableClub_EventScript_PlayerExitLinkRoom:: @ 8276DD5
# 243 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerExitLinkRoom
# 244 "data/scripts/cable_club.pory"
	waitmovement 0
# 245 "data/scripts/cable_club.pory"
	return
# 246 "data/scripts/cable_club.pory"

# 247 "data/scripts/cable_club.pory"
CableClub_EventScript_Tutorial:: @ 8276DE0
# 248 "data/scripts/cable_club.pory"
	lockall
# 249 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
# 250 "data/scripts/cable_club.pory"
	waitmovement 0
# 251 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_FirstTimeRightThisWay, MSGBOX_DEFAULT
# 252 "data/scripts/cable_club.pory"
	closemessage
# 253 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, CableClub_Movement_PlayerApproachCounter
# 254 "data/scripts/cable_club.pory"
	waitmovement 0
# 255 "data/scripts/cable_club.pory"
	delay 30
# 256 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_ExplainWirelessClubFirstTime, MSGBOX_DEFAULT
# 257 "data/scripts/cable_club.pory"
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 2
# 258 "data/scripts/cable_club.pory"
	releaseall
# 259 "data/scripts/cable_club.pory"
	end
# 260 "data/scripts/cable_club.pory"

# 261 "data/scripts/cable_club.pory"
CableClub_Movement_PlayerApproachCounter: @ 8276E10
# 262 "data/scripts/cable_club.pory"
	walk_up
# 263 "data/scripts/cable_club.pory"
	walk_up
# 264 "data/scripts/cable_club.pory"
	step_end
# 265 "data/scripts/cable_club.pory"

# 266 "data/scripts/cable_club.pory"
CableClub_EventScript_WelcomeToCableClub:: @ 8276E13
# 267 "data/scripts/cable_club.pory"
	message CableClub_Text_WelcomeWhichCableClubService
# 268 "data/scripts/cable_club.pory"
	waitmessage
# 269 "data/scripts/cable_club.pory"
	delay 28
# 270 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_SelectCableClubRoom
# 271 "data/scripts/cable_club.pory"
	end
# 272 "data/scripts/cable_club.pory"

# 273 "data/scripts/cable_club.pory"
CableClub_EventScript_UnusedWelcomeToCableClub:: @ 8276E22
# 274 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_WhichService, MSGBOX_DEFAULT
# 275 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_SelectCableClubRoom
# 276 "data/scripts/cable_club.pory"
	end
# 277 "data/scripts/cable_club.pory"

# 278 "data/scripts/cable_club.pory"
CableClub_EventScript_SelectCableClubRoom:: @ 8276E30
# 279 "data/scripts/cable_club.pory"
	setvar VAR_0x8004, 0
# 280 "data/scripts/cable_club.pory"
	goto_if_set FLAG_VISITED_MAUVILLE_CITY, CableClub_EventScript_CableClubUnlockedRecordCorner
# 281 "data/scripts/cable_club.pory"
	multichoice 0, 0, MULTI_CABLE_CLUB_NO_RECORD_MIX, 0
# 282 "data/scripts/cable_club.pory"
	switch VAR_RESULT
# 283 "data/scripts/cable_club.pory"
	case 0, UDTrade_EventScript_OpenDimensionList
# 284 "data/scripts/cable_club.pory"
	case 1, CableClub_EventScript_Colosseum
# 285 "data/scripts/cable_club.pory"
	case 2, CableClub_EventScript_AbortLink
# 286 "data/scripts/cable_club.pory"
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
# 287 "data/scripts/cable_club.pory"
	end
# 288 "data/scripts/cable_club.pory"

# 289 "data/scripts/cable_club.pory"
CableClub_EventScript_CableClubUnlockedRecordCorner:: @ 8276E75
# 290 "data/scripts/cable_club.pory"
	multichoice 0, 0, MULTI_CABLE_CLUB_WITH_RECORD_MIX, 0
# 291 "data/scripts/cable_club.pory"
	switch VAR_RESULT
# 292 "data/scripts/cable_club.pory"
	case 0, UDTrade_EventScript_OpenDimensionList
# 293 "data/scripts/cable_club.pory"
	case 1, CableClub_EventScript_Colosseum
# 294 "data/scripts/cable_club.pory"
	case 2, CableClub_EventScript_RecordCorner
# 295 "data/scripts/cable_club.pory"
	case 3, CableClub_EventScript_AbortLink
# 296 "data/scripts/cable_club.pory"
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
# 297 "data/scripts/cable_club.pory"
	end
# 298 "data/scripts/cable_club.pory"

# 299 "data/scripts/cable_club.pory"
CableClub_EventScript_Colosseum:: @ 8276EB7
# 300 "data/scripts/cable_club.pory"
	copyvar VAR_0x8007, VAR_LAST_TALKED
# 301 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_SelectBattleMode
# 302 "data/scripts/cable_club.pory"
	end
# 303 "data/scripts/cable_club.pory"

# 304 "data/scripts/cable_club.pory"
CableClub_EventScript_SelectBattleMode:: @ 8276EC2
# 305 "data/scripts/cable_club.pory"
	message CableClub_Text_PlayWhichBattleMode
# 306 "data/scripts/cable_club.pory"
	waitmessage
# 307 "data/scripts/cable_club.pory"
	multichoice 0, 0, MULTI_BATTLE_MODE, 0
# 308 "data/scripts/cable_club.pory"
	switch VAR_RESULT
# 309 "data/scripts/cable_club.pory"
	case 0, CableClub_EventScript_SingleBattleMode
# 310 "data/scripts/cable_club.pory"
	case 1, CableClub_EventScript_DoubleBattleMode
# 311 "data/scripts/cable_club.pory"
	case 2, CableClub_EventScript_MultiBattleMode
# 312 "data/scripts/cable_club.pory"
	case 3, CableClub_EventScript_BattleModeInfo
# 313 "data/scripts/cable_club.pory"
	case 4, CableClub_EventScript_AbortLink
# 314 "data/scripts/cable_club.pory"
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
# 315 "data/scripts/cable_club.pory"
	end
# 316 "data/scripts/cable_club.pory"

# 317 "data/scripts/cable_club.pory"
CableClub_EventScript_BattleModeInfo:: @ 8276F15
# 318 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_ExplainBattleModes, MSGBOX_DEFAULT
# 319 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_SelectBattleMode
# 320 "data/scripts/cable_club.pory"
	end
# 321 "data/scripts/cable_club.pory"

# 322 "data/scripts/cable_club.pory"
CableClub_EventScript_SingleBattleMode:: @ 8276F23
# 323 "data/scripts/cable_club.pory"
	setvar VAR_0x8004, USING_SINGLE_BATTLE
# 324 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_TryEnterColosseum
# 325 "data/scripts/cable_club.pory"
	end
# 326 "data/scripts/cable_club.pory"

# 327 "data/scripts/cable_club.pory"
CableClub_EventScript_DoubleBattleMode:: @ 8276F2E
# 328 "data/scripts/cable_club.pory"
	special HasEnoughMonsForDoubleBattle
# 329 "data/scripts/cable_club.pory"
	compare VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS
# 330 "data/scripts/cable_club.pory"
	goto_if_ne CableClub_EventScript_NeedTwoMonsForDoubleBattle
# 331 "data/scripts/cable_club.pory"
	setvar VAR_0x8004, USING_DOUBLE_BATTLE
# 332 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_TryEnterColosseum
# 333 "data/scripts/cable_club.pory"
	end
# 334 "data/scripts/cable_club.pory"

# 335 "data/scripts/cable_club.pory"
CableClub_EventScript_NeedTwoMonsForDoubleBattle:: @ 8276F47
# 336 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle, MSGBOX_DEFAULT
# 337 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_SelectBattleMode
# 338 "data/scripts/cable_club.pory"
	end
# 339 "data/scripts/cable_club.pory"

# 340 "data/scripts/cable_club.pory"
CableClub_EventScript_MultiBattleMode:: @ 8276F55
# 341 "data/scripts/cable_club.pory"
	setvar VAR_0x8004, USING_MULTI_BATTLE
# 342 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_TryEnterColosseum
# 343 "data/scripts/cable_club.pory"
	end
# 344 "data/scripts/cable_club.pory"

# 345 "data/scripts/cable_club.pory"
CableClub_EventScript_TryEnterColosseum:: @ 8276F60
# 346 "data/scripts/cable_club.pory"
	call Common_EventScript_SaveGame
# 347 "data/scripts/cable_club.pory"
	compare VAR_RESULT, 0
# 348 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLink
# 349 "data/scripts/cable_club.pory"
	message gText_PleaseWaitForLink
# 350 "data/scripts/cable_club.pory"
	waitmessage
# 351 "data/scripts/cable_club.pory"
	special TryBattleLinkup
# 352 "data/scripts/cable_club.pory"
	waitstate
# 353 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_SUCCESS
# 354 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_EnterColosseum
# 355 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_SOMEONE_NOT_READY
# 356 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkSomeoneNotReady
# 357 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_DIFF_SELECTIONS
# 358 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkDifferentSelections
# 359 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS
# 360 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers
# 361 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 362 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLink
# 363 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_CONNECTION_ERROR
# 364 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkConnectionError
# 365 "data/scripts/cable_club.pory"
	end
# 366 "data/scripts/cable_club.pory"

# 367 "data/scripts/cable_club.pory"
CableClub_EventScript_EnterColosseum:: @ 8276FBD
# 368 "data/scripts/cable_club.pory"
	special HealPlayerParty
# 369 "data/scripts/cable_club.pory"
	special SavePlayerParty
# 370 "data/scripts/cable_club.pory"
	special LoadPlayerBag
# 371 "data/scripts/cable_club.pory"
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
# 372 "data/scripts/cable_club.pory"
	messageautoscroll CableClub_Text_PleaseEnter
# 373 "data/scripts/cable_club.pory"
	waitmessage
# 374 "data/scripts/cable_club.pory"
	call CableClub_EventScript_OpenDirectCornerBarrier
# 375 "data/scripts/cable_club.pory"
	special DrawWholeMapView
# 376 "data/scripts/cable_club.pory"
	playse SE_CLICK
# 377 "data/scripts/cable_club.pory"
	delay 60
# 378 "data/scripts/cable_club.pory"
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
# 379 "data/scripts/cable_club.pory"
	waitmovement 0
# 380 "data/scripts/cable_club.pory"
	closemessage
# 381 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
# 382 "data/scripts/cable_club.pory"
	waitmovement 0
# 383 "data/scripts/cable_club.pory"
	opendoor 9, 1
# 384 "data/scripts/cable_club.pory"
	waitdooranim
# 385 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
# 386 "data/scripts/cable_club.pory"
	waitmovement 0
# 387 "data/scripts/cable_club.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 388 "data/scripts/cable_club.pory"
	closedoor 9, 1
# 389 "data/scripts/cable_club.pory"
	waitdooranim
# 390 "data/scripts/cable_club.pory"
	release
# 391 "data/scripts/cable_club.pory"
	compare VAR_0x8004, USING_MULTI_BATTLE
# 392 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_WarpTo4PColosseum
# 393 "data/scripts/cable_club.pory"
	special SetCableClubWarp
# 394 "data/scripts/cable_club.pory"
	warp MAP_BATTLE_COLOSSEUM_2P, 255, 6, 8
# 395 "data/scripts/cable_club.pory"
	special DoCableClubWarp
# 396 "data/scripts/cable_club.pory"
	waitstate
# 397 "data/scripts/cable_club.pory"
	end
# 398 "data/scripts/cable_club.pory"

# 399 "data/scripts/cable_club.pory"
@ Unused
# 400 "data/scripts/cable_club.pory"
CableClub_EventScript_PlayerApproachLinkRoomRight:: @ 827702B
# 401 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomRight
# 402 "data/scripts/cable_club.pory"
	waitmovement 0
# 403 "data/scripts/cable_club.pory"
	return
# 404 "data/scripts/cable_club.pory"

# 405 "data/scripts/cable_club.pory"
CableClub_EventScript_WarpTo4PColosseum:: @ 8277036
# 406 "data/scripts/cable_club.pory"
	special SetCableClubWarp
# 407 "data/scripts/cable_club.pory"
	warp MAP_BATTLE_COLOSSEUM_4P, 255, 5, 8
# 408 "data/scripts/cable_club.pory"
	special DoCableClubWarp
# 409 "data/scripts/cable_club.pory"
	waitstate
# 410 "data/scripts/cable_club.pory"
	end
# 411 "data/scripts/cable_club.pory"

# 412 "data/scripts/cable_club.pory"
CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers:: @ 8277046
# 413 "data/scripts/cable_club.pory"
	switch VAR_0x8004
# 414 "data/scripts/cable_club.pory"
	case USING_SINGLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForSingleBattle
# 415 "data/scripts/cable_club.pory"
	case USING_DOUBLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle
# 416 "data/scripts/cable_club.pory"
	case USING_MULTI_BATTLE,  CableClub_EventScript_AbortLinkNeedFourPlayers
# 417 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
# 418 "data/scripts/cable_club.pory"
	end
# 419 "data/scripts/cable_club.pory"

# 420 "data/scripts/cable_club.pory"
CableClub_EventScript_AbortLinkNeedFourPlayers:: @ 8277072
# 421 "data/scripts/cable_club.pory"
	special CloseLink
# 422 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_NeedFourPlayers, MSGBOX_DEFAULT
# 423 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_ConfirmNumberAndRestart
# 424 "data/scripts/cable_club.pory"
	end
# 425 "data/scripts/cable_club.pory"

# 426 "data/scripts/cable_club.pory"
CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle:: @ 8277083
# 427 "data/scripts/cable_club.pory"
	special CloseLink
# 428 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_CantDoubleBattleWithXPlayers, MSGBOX_DEFAULT
# 429 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_ConfirmNumberAndRestart
# 430 "data/scripts/cable_club.pory"
	end
# 431 "data/scripts/cable_club.pory"

# 432 "data/scripts/cable_club.pory"
CableClub_EventScript_AbortLinkWrongNumberForSingleBattle:: @ 8277094
# 433 "data/scripts/cable_club.pory"
	special CloseLink
# 434 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_CantSingleBattleWithXPlayers, MSGBOX_DEFAULT
# 435 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_ConfirmNumberAndRestart
# 436 "data/scripts/cable_club.pory"
	end
# 437 "data/scripts/cable_club.pory"

# 438 "data/scripts/cable_club.pory"
CableClub_EventScript_ConfirmNumberAndRestart:: @ 82770A5
# 439 "data/scripts/cable_club.pory"
	special CloseLink  @ Redundant
# 440 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_PleaseConfirmNumberAndRestart, MSGBOX_DEFAULT
# 441 "data/scripts/cable_club.pory"
	release
# 442 "data/scripts/cable_club.pory"
	end
# 443 "data/scripts/cable_club.pory"

# 444 "data/scripts/cable_club.pory"
CableClub_EventScript_TradeCenter:: @ 82770B2
# 445 "data/scripts/cable_club.pory"
	copyvar VAR_0x8007, VAR_LAST_TALKED
# 446 "data/scripts/cable_club.pory"
	call CableClub_EventScript_CheckPartyTradeRequirements
# 447 "data/scripts/cable_club.pory"
	compare VAR_RESULT, 0
# 448 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLink
# 449 "data/scripts/cable_club.pory"
	call Common_EventScript_SaveGame
# 450 "data/scripts/cable_club.pory"
	compare VAR_RESULT, 0
# 451 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLink
# 452 "data/scripts/cable_club.pory"
	message gText_PleaseWaitForLink
# 453 "data/scripts/cable_club.pory"
	waitmessage
# 454 "data/scripts/cable_club.pory"
	special TryTradeLinkup
# 455 "data/scripts/cable_club.pory"
	waitstate
# 456 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_SUCCESS
# 457 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_EnterTradeCenter
# 458 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_SOMEONE_NOT_READY
# 459 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkSomeoneNotReady
# 460 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_DIFF_SELECTIONS
# 461 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkDifferentSelections
# 462 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS
# 463 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
# 464 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 465 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLink
# 466 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_CONNECTION_ERROR
# 467 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkConnectionError
# 468 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_PLAYER_NOT_READY
# 469 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkPlayerNotReady
# 470 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_PARTNER_NOT_READY
# 471 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkOtherTrainerNotReady
# 472 "data/scripts/cable_club.pory"
	end
# 473 "data/scripts/cable_club.pory"

# 474 "data/scripts/cable_club.pory"
CableClub_EventScript_EnterTradeCenter:: @ 827713A
# 475 "data/scripts/cable_club.pory"
	setvar VAR_0x8004, USING_TRADE_CENTER
# 476 "data/scripts/cable_club.pory"
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
# 477 "data/scripts/cable_club.pory"
	messageautoscroll CableClub_Text_PleaseEnter
# 478 "data/scripts/cable_club.pory"
	waitmessage
# 479 "data/scripts/cable_club.pory"
	call CableClub_EventScript_OpenDirectCornerBarrier
# 480 "data/scripts/cable_club.pory"
	special DrawWholeMapView
# 481 "data/scripts/cable_club.pory"
	playse SE_CLICK
# 482 "data/scripts/cable_club.pory"
	delay 60
# 483 "data/scripts/cable_club.pory"
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
# 484 "data/scripts/cable_club.pory"
	waitmovement 0
# 485 "data/scripts/cable_club.pory"
	closemessage
# 486 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
# 487 "data/scripts/cable_club.pory"
	waitmovement 0
# 488 "data/scripts/cable_club.pory"
	opendoor 9, 1
# 489 "data/scripts/cable_club.pory"
	waitdooranim
# 490 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
# 491 "data/scripts/cable_club.pory"
	waitmovement 0
# 492 "data/scripts/cable_club.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 493 "data/scripts/cable_club.pory"
	closedoor 9, 1
# 494 "data/scripts/cable_club.pory"
	waitdooranim
# 495 "data/scripts/cable_club.pory"
	release
# 496 "data/scripts/cable_club.pory"
	special SetCableClubWarp
# 497 "data/scripts/cable_club.pory"
	setwarp MAP_TRADE_CENTER, 255, 5, 8
# 498 "data/scripts/cable_club.pory"
	special DoCableClubWarp
# 499 "data/scripts/cable_club.pory"
	waitstate
# 500 "data/scripts/cable_club.pory"
	end
# 501 "data/scripts/cable_club.pory"

# 502 "data/scripts/cable_club.pory"
CableClub_EventScript_CheckPartyTradeRequirements:: @ 8277199
# 503 "data/scripts/cable_club.pory"
	specialvar VAR_RESULT, CalculatePlayerPartyCount
# 504 "data/scripts/cable_club.pory"
	compare VAR_RESULT, 2
# 505 "data/scripts/cable_club.pory"
	goto_if_lt CableClub_EventScript_NeedTwoMonsToTrade
# 506 "data/scripts/cable_club.pory"
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
# 507 "data/scripts/cable_club.pory"
	compare VAR_RESULT, TRUE
# 508 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_CantTradeEnigmaBerry
# 509 "data/scripts/cable_club.pory"
	setvar VAR_RESULT, 1
# 510 "data/scripts/cable_club.pory"
	return
# 511 "data/scripts/cable_club.pory"

# 512 "data/scripts/cable_club.pory"
CableClub_EventScript_NeedTwoMonsToTrade:: @ 82771BF
# 513 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_NeedTwoMonsToTrade, MSGBOX_DEFAULT
# 514 "data/scripts/cable_club.pory"
	setvar VAR_RESULT, 0
# 515 "data/scripts/cable_club.pory"
	return
# 516 "data/scripts/cable_club.pory"

# 517 "data/scripts/cable_club.pory"
CableClub_EventScript_CantTradeEnigmaBerry:: @ 82771CD
# 518 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_CantTradeEnigmaBerry, MSGBOX_DEFAULT
# 519 "data/scripts/cable_club.pory"
	setvar VAR_RESULT, 0
# 520 "data/scripts/cable_club.pory"
	return
# 521 "data/scripts/cable_club.pory"

# 522 "data/scripts/cable_club.pory"
CableClub_EventScript_RecordCorner:: @ 82771DB
# 523 "data/scripts/cable_club.pory"
	copyvar VAR_0x8007, VAR_LAST_TALKED
# 524 "data/scripts/cable_club.pory"
	call Common_EventScript_SaveGame
# 525 "data/scripts/cable_club.pory"
	compare VAR_RESULT, 0
# 526 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLink
# 527 "data/scripts/cable_club.pory"
	message gText_PleaseWaitForLink
# 528 "data/scripts/cable_club.pory"
	waitmessage
# 529 "data/scripts/cable_club.pory"
	special TryRecordMixLinkup
# 530 "data/scripts/cable_club.pory"
	waitstate
# 531 "data/scripts/cable_club.pory"
	special ValidateMixingGameLanguage
# 532 "data/scripts/cable_club.pory"
	waitstate
# 533 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_FOREIGN_GAME
# 534 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkForeignGame
# 535 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_SUCCESS
# 536 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_EnterRecordCorner
# 537 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_SOMEONE_NOT_READY
# 538 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkSomeoneNotReady
# 539 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_DIFF_SELECTIONS
# 540 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkDifferentSelections
# 541 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS
# 542 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
# 543 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 544 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLink
# 545 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_CONNECTION_ERROR
# 546 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkConnectionError
# 547 "data/scripts/cable_club.pory"
	end
# 548 "data/scripts/cable_club.pory"

# 549 "data/scripts/cable_club.pory"
CableClub_EventScript_EnterRecordCorner:: @ 827724C
# 550 "data/scripts/cable_club.pory"
	setvar VAR_0x8004, USING_RECORD_CORNER
# 551 "data/scripts/cable_club.pory"
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
# 552 "data/scripts/cable_club.pory"
	messageautoscroll CableClub_Text_PleaseEnter
# 553 "data/scripts/cable_club.pory"
	waitmessage
# 554 "data/scripts/cable_club.pory"
	call CableClub_EventScript_OpenDirectCornerBarrier
# 555 "data/scripts/cable_club.pory"
	special DrawWholeMapView
# 556 "data/scripts/cable_club.pory"
	playse SE_CLICK
# 557 "data/scripts/cable_club.pory"
	delay 60
# 558 "data/scripts/cable_club.pory"
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
# 559 "data/scripts/cable_club.pory"
	waitmovement 0
# 560 "data/scripts/cable_club.pory"
	closemessage
# 561 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
# 562 "data/scripts/cable_club.pory"
	waitmovement 0
# 563 "data/scripts/cable_club.pory"
	opendoor 9, 1
# 564 "data/scripts/cable_club.pory"
	waitdooranim
# 565 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
# 566 "data/scripts/cable_club.pory"
	waitmovement 0
# 567 "data/scripts/cable_club.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 568 "data/scripts/cable_club.pory"
	closedoor 9, 1
# 569 "data/scripts/cable_club.pory"
	waitdooranim
# 570 "data/scripts/cable_club.pory"
	release
# 571 "data/scripts/cable_club.pory"
	special SetCableClubWarp
# 572 "data/scripts/cable_club.pory"
	setwarp MAP_RECORD_CORNER, 255, 8, 9
# 573 "data/scripts/cable_club.pory"
	special DoCableClubWarp
# 574 "data/scripts/cable_club.pory"
	waitstate
# 575 "data/scripts/cable_club.pory"
	end
# 576 "data/scripts/cable_club.pory"

# 577 "data/scripts/cable_club.pory"
CableClub_EventScript_AbortLinkPlayerNotReady:: @ 82772AB
# 578 "data/scripts/cable_club.pory"
	special CloseLink
# 579 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_NotSetUpForFarAwayRegion, MSGBOX_DEFAULT
# 580 "data/scripts/cable_club.pory"
	release
# 581 "data/scripts/cable_club.pory"
	end
# 582 "data/scripts/cable_club.pory"

# 583 "data/scripts/cable_club.pory"
CableClub_EventScript_AbortLinkOtherTrainerNotReady:: @ 82772B8
# 584 "data/scripts/cable_club.pory"
	special CloseLink
# 585 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_OtherTrainerNotReady, MSGBOX_DEFAULT
# 586 "data/scripts/cable_club.pory"
	release
# 587 "data/scripts/cable_club.pory"
	end
# 588 "data/scripts/cable_club.pory"

# 589 "data/scripts/cable_club.pory"
CableClub_EventScript_AbortLinkConnectionError:: @ 82772C5
# 590 "data/scripts/cable_club.pory"
	special CloseLink
# 591 "data/scripts/cable_club.pory"
	msgbox Text_LinkErrorPleaseReset, MSGBOX_DEFAULT
# 592 "data/scripts/cable_club.pory"
	release
# 593 "data/scripts/cable_club.pory"
	end
# 594 "data/scripts/cable_club.pory"

# 595 "data/scripts/cable_club.pory"
CableClub_EventScript_AbortLinkSomeoneNotReady:: @ 82772D2
# 596 "data/scripts/cable_club.pory"
	special CloseLink
# 597 "data/scripts/cable_club.pory"
	msgbox Text_SomeoneIsNotReadyToLink, MSGBOX_DEFAULT
# 598 "data/scripts/cable_club.pory"
	release
# 599 "data/scripts/cable_club.pory"
	end
# 600 "data/scripts/cable_club.pory"

# 601 "data/scripts/cable_club.pory"
CableClub_EventScript_AbortLinkDifferentSelections:: @ 82772DF
# 602 "data/scripts/cable_club.pory"
	special CloseLink
# 603 "data/scripts/cable_club.pory"
	msgbox Text_PlayersMadeDifferentSelections, MSGBOX_DEFAULT
# 604 "data/scripts/cable_club.pory"
	release
# 605 "data/scripts/cable_club.pory"
	end
# 606 "data/scripts/cable_club.pory"

# 607 "data/scripts/cable_club.pory"
CableClub_EventScript_AbortLink:: @ 82772EC
# 608 "data/scripts/cable_club.pory"
	special CloseLink
# 609 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_PleaseVisitAgain, MSGBOX_DEFAULT
# 610 "data/scripts/cable_club.pory"
	release
# 611 "data/scripts/cable_club.pory"
	end
# 612 "data/scripts/cable_club.pory"

# 613 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_AbortMinigame:: @ 82772F9
# 614 "data/scripts/cable_club.pory"
	special CloseLink
# 615 "data/scripts/cable_club.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_ComeAgain, MSGBOX_DEFAULT
# 616 "data/scripts/cable_club.pory"
	release
# 617 "data/scripts/cable_club.pory"
	end
# 618 "data/scripts/cable_club.pory"

# 619 "data/scripts/cable_club.pory"
@ Unused
# 620 "data/scripts/cable_club.pory"
CableClub_EventScript_CableClubWarp:: @ 8277306
# 621 "data/scripts/cable_club.pory"
	special SetCableClubWarp
# 622 "data/scripts/cable_club.pory"
	special DoCableClubWarp
# 623 "data/scripts/cable_club.pory"
	waitstate
# 624 "data/scripts/cable_club.pory"
	end
# 625 "data/scripts/cable_club.pory"

# 626 "data/scripts/cable_club.pory"
CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants:: @ 827730E
# 627 "data/scripts/cable_club.pory"
	special CloseLink
# 628 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_IncorrectNumberOfParticipants, MSGBOX_DEFAULT
# 629 "data/scripts/cable_club.pory"
	release
# 630 "data/scripts/cable_club.pory"
	end
# 631 "data/scripts/cable_club.pory"

# 632 "data/scripts/cable_club.pory"
CableClub_EventScript_AbortLinkPlayerHasBadEgg:: @ 827731B
# 633 "data/scripts/cable_club.pory"
	special CloseLink
# 634 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_YouHaveAMonThatCantBeTaken, MSGBOX_DEFAULT
# 635 "data/scripts/cable_club.pory"
	release
# 636 "data/scripts/cable_club.pory"
	end
# 637 "data/scripts/cable_club.pory"

# 638 "data/scripts/cable_club.pory"
CableClub_EventScript_AbortLinkForeignGame:: @ 8277328
# 639 "data/scripts/cable_club.pory"
	special CloseLink
# 640 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_CantMixWithJapaneseGame, MSGBOX_DEFAULT
# 641 "data/scripts/cable_club.pory"
	release
# 642 "data/scripts/cable_club.pory"
	end
# 643 "data/scripts/cable_club.pory"

# 644 "data/scripts/cable_club.pory"
CableClub_EventScript_WirelessClubAdjustements:: @ 8277335
# 645 "data/scripts/cable_club.pory"
	msgbox gText_SorryWirelessClubAdjustments, MSGBOX_DEFAULT
# 646 "data/scripts/cable_club.pory"
	release
# 647 "data/scripts/cable_club.pory"
	end
# 648 "data/scripts/cable_club.pory"

# 649 "data/scripts/cable_club.pory"
CableClub_EventScript_NotReadyYet:: @ 827733F
# 650 "data/scripts/cable_club.pory"
	msgbox gText_UndergoingAdjustments, MSGBOX_DEFAULT
# 651 "data/scripts/cable_club.pory"
	releaseall
# 652 "data/scripts/cable_club.pory"
	end
# 653 "data/scripts/cable_club.pory"

# 654 "data/scripts/cable_club.pory"
Movement_AttendantFaceDown: @ 8277349
# 655 "data/scripts/cable_club.pory"
	face_down
# 656 "data/scripts/cable_club.pory"
	step_end
# 657 "data/scripts/cable_club.pory"

# 658 "data/scripts/cable_club.pory"
@ Unused
# 659 "data/scripts/cable_club.pory"
Movement_AttendantFaceRight: @ 827734B
# 660 "data/scripts/cable_club.pory"
	face_right
# 661 "data/scripts/cable_club.pory"
	step_end
# 662 "data/scripts/cable_club.pory"

# 663 "data/scripts/cable_club.pory"
Movement_AttendantFaceLeft: @ 827734D
# 664 "data/scripts/cable_club.pory"
	face_left
# 665 "data/scripts/cable_club.pory"
	step_end
# 666 "data/scripts/cable_club.pory"

# 667 "data/scripts/cable_club.pory"
Movement_PlayerExitLinkRoom: @ 827734F
# 668 "data/scripts/cable_club.pory"
	walk_down
# 669 "data/scripts/cable_club.pory"
	walk_down
# 670 "data/scripts/cable_club.pory"
	step_end
# 671 "data/scripts/cable_club.pory"

# 672 "data/scripts/cable_club.pory"
@ Functionally unused
# 673 "data/scripts/cable_club.pory"
Movement_PlayerApproachLinkRoomRight: @ 8277352
# 674 "data/scripts/cable_club.pory"
	walk_right
# 675 "data/scripts/cable_club.pory"
	walk_up
# 676 "data/scripts/cable_club.pory"
	walk_up
# 677 "data/scripts/cable_club.pory"
	step_end
# 678 "data/scripts/cable_club.pory"

# 679 "data/scripts/cable_club.pory"
Movement_PlayerApproachLinkRoomLeft: @ 8277356
# 680 "data/scripts/cable_club.pory"
	walk_left
# 681 "data/scripts/cable_club.pory"
	walk_up
# 682 "data/scripts/cable_club.pory"
	walk_up
# 683 "data/scripts/cable_club.pory"
	step_end
# 684 "data/scripts/cable_club.pory"

# 685 "data/scripts/cable_club.pory"
Movement_PlayerEnterLinkRoom: @ 827735A
# 686 "data/scripts/cable_club.pory"
	walk_up
# 687 "data/scripts/cable_club.pory"
	step_end
# 688 "data/scripts/cable_club.pory"

# 689 "data/scripts/cable_club.pory"
@ Unused
# 690 "data/scripts/cable_club.pory"
Movement_PlayerFaceAttendantLeft: @ 827735C
# 691 "data/scripts/cable_club.pory"
	face_left
# 692 "data/scripts/cable_club.pory"
	step_end
# 693 "data/scripts/cable_club.pory"

# 694 "data/scripts/cable_club.pory"
Movement_PlayerFaceAttendantRight: @ 827735E
# 695 "data/scripts/cable_club.pory"
	face_right
# 696 "data/scripts/cable_club.pory"
	step_end
# 697 "data/scripts/cable_club.pory"

# 698 "data/scripts/cable_club.pory"
Movement_PlayerEnterMinigameRoom: @ 8277360
# 699 "data/scripts/cable_club.pory"
	walk_left
# 700 "data/scripts/cable_club.pory"
	walk_up
# 701 "data/scripts/cable_club.pory"
	walk_up
# 702 "data/scripts/cable_club.pory"
	walk_up
# 703 "data/scripts/cable_club.pory"
	step_end
# 704 "data/scripts/cable_club.pory"

# 705 "data/scripts/cable_club.pory"
EventScript_CableBoxResults:: @ 8277365
# 706 "data/scripts/cable_club.pory"
	lockall
# 707 "data/scripts/cable_club.pory"
	setvar VAR_0x8004, 0
# 708 "data/scripts/cable_club.pory"
	special ShowLinkBattleRecords
# 709 "data/scripts/cable_club.pory"
	waitbuttonpress
# 710 "data/scripts/cable_club.pory"
	special RemoveRecordsWindow
# 711 "data/scripts/cable_club.pory"
	releaseall
# 712 "data/scripts/cable_club.pory"
	end
# 713 "data/scripts/cable_club.pory"

# 714 "data/scripts/cable_club.pory"
EventScript_BattleColosseum_2P_PlayerSpot0:: @ 8277374
# 715 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 0
# 716 "data/scripts/cable_club.pory"
	special ColosseumPlayerSpotTriggered
# 717 "data/scripts/cable_club.pory"
	waitstate
# 718 "data/scripts/cable_club.pory"
	end
# 719 "data/scripts/cable_club.pory"

# 720 "data/scripts/cable_club.pory"
EventScript_BattleColosseum_2P_PlayerSpot1:: @ 827737E
# 721 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 1
# 722 "data/scripts/cable_club.pory"
	special ColosseumPlayerSpotTriggered
# 723 "data/scripts/cable_club.pory"
	waitstate
# 724 "data/scripts/cable_club.pory"
	end
# 725 "data/scripts/cable_club.pory"

# 726 "data/scripts/cable_club.pory"
EventScript_BattleColosseum_4P_PlayerSpot0:: @ 8277388
# 727 "data/scripts/cable_club.pory"
	fadescreen FADE_TO_BLACK
# 728 "data/scripts/cable_club.pory"
	special ChooseHalfPartyForBattle
# 729 "data/scripts/cable_club.pory"
	waitstate
# 730 "data/scripts/cable_club.pory"
	compare VAR_RESULT, 0
# 731 "data/scripts/cable_club.pory"
	goto_if_eq EventScript_BattleColosseum_4P_CancelSpotTrigger
# 732 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 0
# 733 "data/scripts/cable_club.pory"
	special ColosseumPlayerSpotTriggered
# 734 "data/scripts/cable_club.pory"
	waitstate
# 735 "data/scripts/cable_club.pory"
	end
# 736 "data/scripts/cable_club.pory"

# 737 "data/scripts/cable_club.pory"
EventScript_BattleColosseum_4P_PlayerSpot1:: @ 82773A3
# 738 "data/scripts/cable_club.pory"
	fadescreen FADE_TO_BLACK
# 739 "data/scripts/cable_club.pory"
	special ChooseHalfPartyForBattle
# 740 "data/scripts/cable_club.pory"
	waitstate
# 741 "data/scripts/cable_club.pory"
	compare VAR_RESULT, 0
# 742 "data/scripts/cable_club.pory"
	goto_if_eq EventScript_BattleColosseum_4P_CancelSpotTrigger
# 743 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 1
# 744 "data/scripts/cable_club.pory"
	special ColosseumPlayerSpotTriggered
# 745 "data/scripts/cable_club.pory"
	waitstate
# 746 "data/scripts/cable_club.pory"
	end
# 747 "data/scripts/cable_club.pory"

# 748 "data/scripts/cable_club.pory"
EventScript_BattleColosseum_4P_PlayerSpot2:: @ 82773BE
# 749 "data/scripts/cable_club.pory"
	fadescreen FADE_TO_BLACK
# 750 "data/scripts/cable_club.pory"
	special ChooseHalfPartyForBattle
# 751 "data/scripts/cable_club.pory"
	waitstate
# 752 "data/scripts/cable_club.pory"
	compare VAR_RESULT, 0
# 753 "data/scripts/cable_club.pory"
	goto_if_eq EventScript_BattleColosseum_4P_CancelSpotTrigger
# 754 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 2
# 755 "data/scripts/cable_club.pory"
	special ColosseumPlayerSpotTriggered
# 756 "data/scripts/cable_club.pory"
	waitstate
# 757 "data/scripts/cable_club.pory"
	end
# 758 "data/scripts/cable_club.pory"

# 759 "data/scripts/cable_club.pory"
EventScript_BattleColosseum_4P_PlayerSpot3:: @ 82773D9
# 760 "data/scripts/cable_club.pory"
	fadescreen FADE_TO_BLACK
# 761 "data/scripts/cable_club.pory"
	special ChooseHalfPartyForBattle
# 762 "data/scripts/cable_club.pory"
	waitstate
# 763 "data/scripts/cable_club.pory"
	compare VAR_RESULT, 0
# 764 "data/scripts/cable_club.pory"
	goto_if_eq EventScript_BattleColosseum_4P_CancelSpotTrigger
# 765 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 3
# 766 "data/scripts/cable_club.pory"
	special ColosseumPlayerSpotTriggered
# 767 "data/scripts/cable_club.pory"
	waitstate
# 768 "data/scripts/cable_club.pory"
	end
# 769 "data/scripts/cable_club.pory"

# 770 "data/scripts/cable_club.pory"
EventScript_BattleColosseum_4P_CancelSpotTrigger:: @ 82773F4
# 771 "data/scripts/cable_club.pory"
	end
# 772 "data/scripts/cable_club.pory"

# 773 "data/scripts/cable_club.pory"
EventScript_TradeCenter_Chair0:: @ 82773F5
# 774 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 0
# 775 "data/scripts/cable_club.pory"
	special PlayerEnteredTradeSeat
# 776 "data/scripts/cable_club.pory"
	waitstate
# 777 "data/scripts/cable_club.pory"
	end
# 778 "data/scripts/cable_club.pory"

# 779 "data/scripts/cable_club.pory"
EventScript_TradeCenter_Chair1:: @ 82773FF
# 780 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 1
# 781 "data/scripts/cable_club.pory"
	special PlayerEnteredTradeSeat
# 782 "data/scripts/cable_club.pory"
	waitstate
# 783 "data/scripts/cable_club.pory"
	end
# 784 "data/scripts/cable_club.pory"

# 785 "data/scripts/cable_club.pory"
/* Never used */
# 786 "data/scripts/cable_club.pory"
EventScript_TradeCenter_Chair2:: @ 8277409
# 787 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 2
# 788 "data/scripts/cable_club.pory"
	special PlayerEnteredTradeSeat
# 789 "data/scripts/cable_club.pory"
	waitstate
# 790 "data/scripts/cable_club.pory"
	end
# 791 "data/scripts/cable_club.pory"

# 792 "data/scripts/cable_club.pory"
/* Never used */
# 793 "data/scripts/cable_club.pory"
EventScript_TradeCenter_Chair3:: @ 8277413
# 794 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 3
# 795 "data/scripts/cable_club.pory"
	special PlayerEnteredTradeSeat
# 796 "data/scripts/cable_club.pory"
	waitstate
# 797 "data/scripts/cable_club.pory"
	end
# 798 "data/scripts/cable_club.pory"

# 799 "data/scripts/cable_club.pory"
@ VAR_TEMP_1 for below scripts set by ReceiveGiftItem
# 800 "data/scripts/cable_club.pory"
EventScript_RecordCenter_Spot0:: @ 827741D
# 801 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 0
# 802 "data/scripts/cable_club.pory"
	special RecordMixingPlayerSpotTriggered
# 803 "data/scripts/cable_club.pory"
	waitstate
# 804 "data/scripts/cable_club.pory"
	compare VAR_TEMP_1, ITEM_NONE
# 805 "data/scripts/cable_club.pory"
	goto_if_ne RecordCorner_EventScript_ReceivedGiftItem
# 806 "data/scripts/cable_club.pory"
	end
# 807 "data/scripts/cable_club.pory"

# 808 "data/scripts/cable_club.pory"
EventScript_RecordCenter_Spot1:: @ 8277432
# 809 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 1
# 810 "data/scripts/cable_club.pory"
	special RecordMixingPlayerSpotTriggered
# 811 "data/scripts/cable_club.pory"
	waitstate
# 812 "data/scripts/cable_club.pory"
	compare VAR_TEMP_1, ITEM_NONE
# 813 "data/scripts/cable_club.pory"
	goto_if_ne RecordCorner_EventScript_ReceivedGiftItem
# 814 "data/scripts/cable_club.pory"
	end
# 815 "data/scripts/cable_club.pory"

# 816 "data/scripts/cable_club.pory"
EventScript_RecordCenter_Spot2:: @ 8277447
# 817 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 2
# 818 "data/scripts/cable_club.pory"
	special RecordMixingPlayerSpotTriggered
# 819 "data/scripts/cable_club.pory"
	waitstate
# 820 "data/scripts/cable_club.pory"
	compare VAR_TEMP_1, ITEM_NONE
# 821 "data/scripts/cable_club.pory"
	goto_if_ne RecordCorner_EventScript_ReceivedGiftItem
# 822 "data/scripts/cable_club.pory"
	end
# 823 "data/scripts/cable_club.pory"

# 824 "data/scripts/cable_club.pory"
EventScript_RecordCenter_Spot3:: @ 827745C
# 825 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 3
# 826 "data/scripts/cable_club.pory"
	special RecordMixingPlayerSpotTriggered
# 827 "data/scripts/cable_club.pory"
	waitstate
# 828 "data/scripts/cable_club.pory"
	compare VAR_TEMP_1, ITEM_NONE
# 829 "data/scripts/cable_club.pory"
	goto_if_ne RecordCorner_EventScript_ReceivedGiftItem
# 830 "data/scripts/cable_club.pory"
	end
# 831 "data/scripts/cable_club.pory"

# 832 "data/scripts/cable_club.pory"
RecordCorner_EventScript_ReceivedGiftItem:: @ 8277471
# 833 "data/scripts/cable_club.pory"
	bufferitemname 1, VAR_TEMP_1
# 834 "data/scripts/cable_club.pory"
	message RecordCorner_Text_PlayerSentOverOneX
# 835 "data/scripts/cable_club.pory"
	waitmessage
# 836 "data/scripts/cable_club.pory"
	waitbuttonpress
# 837 "data/scripts/cable_club.pory"
	releaseall
# 838 "data/scripts/cable_club.pory"
	end
# 839 "data/scripts/cable_club.pory"

# 840 "data/scripts/cable_club.pory"
CableClub_EventScript_ReadTrainerCard:: @ 827747E
# 841 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_GotToLookAtTrainerCard, MSGBOX_DEFAULT
# 842 "data/scripts/cable_club.pory"
	fadescreen FADE_TO_BLACK
# 843 "data/scripts/cable_club.pory"
	special Script_ShowLinkTrainerCard
# 844 "data/scripts/cable_club.pory"
	waitstate
# 845 "data/scripts/cable_club.pory"
	end
# 846 "data/scripts/cable_club.pory"

# 847 "data/scripts/cable_club.pory"
CableClub_EventScript_ReadTrainerCardColored:: @ 827748D
# 848 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_GotToLookAtColoredTrainerCard, MSGBOX_DEFAULT
# 849 "data/scripts/cable_club.pory"
	fadescreen FADE_TO_BLACK
# 850 "data/scripts/cable_club.pory"
	special Script_ShowLinkTrainerCard
# 851 "data/scripts/cable_club.pory"
	waitstate
# 852 "data/scripts/cable_club.pory"
	end
# 853 "data/scripts/cable_club.pory"

# 854 "data/scripts/cable_club.pory"
CableClub_EventScript_TooBusyToNotice:: @ 827749C
# 855 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_TooBusyToNotice, MSGBOX_DEFAULT
# 856 "data/scripts/cable_club.pory"
	closemessage
# 857 "data/scripts/cable_club.pory"
	end
# 858 "data/scripts/cable_club.pory"

# 859 "data/scripts/cable_club.pory"
BattleColosseum_2P_EventScript_Attendant:: @ 82774A6
# 860 "data/scripts/cable_club.pory"
	special Script_FacePlayer
# 861 "data/scripts/cable_club.pory"
	msgbox BattleColosseum_2P_Text_TakePlaceStartBattle, MSGBOX_DEFAULT
# 862 "data/scripts/cable_club.pory"
	special Script_ClearHeldMovement
# 863 "data/scripts/cable_club.pory"
	closemessage
# 864 "data/scripts/cable_club.pory"
	end
# 865 "data/scripts/cable_club.pory"

# 866 "data/scripts/cable_club.pory"
TradeCenter_EventScript_Attendant:: @ 82774B6
# 867 "data/scripts/cable_club.pory"
	special Script_FacePlayer
# 868 "data/scripts/cable_club.pory"
	msgbox TradeCenter_Text_TakeSeatStartTrade, MSGBOX_DEFAULT
# 869 "data/scripts/cable_club.pory"
	special Script_ClearHeldMovement
# 870 "data/scripts/cable_club.pory"
	closemessage
# 871 "data/scripts/cable_club.pory"
	end
# 872 "data/scripts/cable_club.pory"

# 873 "data/scripts/cable_club.pory"
RecordCorner_EventScript_Attendant:: @ 82774C6
# 874 "data/scripts/cable_club.pory"
	compare VAR_TEMP_0, 0
# 875 "data/scripts/cable_club.pory"
	goto_if_ne RecordCorner_EventScript_AlreadyMixed
# 876 "data/scripts/cable_club.pory"
	special Script_FacePlayer
# 877 "data/scripts/cable_club.pory"
	message RecordCorner_Text_TakeSeatAndWait
# 878 "data/scripts/cable_club.pory"
	waitmessage
# 879 "data/scripts/cable_club.pory"
	waitbuttonpress
# 880 "data/scripts/cable_club.pory"
	special Script_ClearHeldMovement
# 881 "data/scripts/cable_club.pory"
	closemessage
# 882 "data/scripts/cable_club.pory"
	end
# 883 "data/scripts/cable_club.pory"

# 884 "data/scripts/cable_club.pory"
RecordCorner_EventScript_AlreadyMixed:: @ 82774E0
# 885 "data/scripts/cable_club.pory"
	special Script_FacePlayer
# 886 "data/scripts/cable_club.pory"
	message RecordCorner_Text_ThanksForComing
# 887 "data/scripts/cable_club.pory"
	waitmessage
# 888 "data/scripts/cable_club.pory"
	waitbuttonpress
# 889 "data/scripts/cable_club.pory"
	special Script_ClearHeldMovement
# 890 "data/scripts/cable_club.pory"
	closemessage
# 891 "data/scripts/cable_club.pory"
	end
# 892 "data/scripts/cable_club.pory"

# 893 "data/scripts/cable_club.pory"
EventScript_ConfirmLeaveTradeRoom:: @ 82774EF
# 894 "data/scripts/cable_club.pory"
	msgbox Text_TerminateLinkConfirmation, MSGBOX_YESNO
# 895 "data/scripts/cable_club.pory"
	compare VAR_RESULT, YES
# 896 "data/scripts/cable_club.pory"
	goto_if_eq EventScript_TerminateLink
# 897 "data/scripts/cable_club.pory"
	erasebox 0, 0, 29, 19
# 898 "data/scripts/cable_club.pory"
	releaseall
# 899 "data/scripts/cable_club.pory"
	end
# 900 "data/scripts/cable_club.pory"

# 901 "data/scripts/cable_club.pory"
EventScript_TerminateLink:: @ 8277509
# 902 "data/scripts/cable_club.pory"
	messageautoscroll Text_TerminateLinkPleaseWait
# 903 "data/scripts/cable_club.pory"
	waitmessage
# 904 "data/scripts/cable_club.pory"
	special ExitLinkRoom
# 905 "data/scripts/cable_club.pory"
	end
# 906 "data/scripts/cable_club.pory"

# 907 "data/scripts/cable_club.pory"
EventScript_DoLinkRoomExit:: @ 8277513
# 908 "data/scripts/cable_club.pory"
	special CleanupLinkRoomState
# 909 "data/scripts/cable_club.pory"
	special ReturnFromLinkRoom
# 910 "data/scripts/cable_club.pory"
	waitstate
# 911 "data/scripts/cable_club.pory"
	end
# 912 "data/scripts/cable_club.pory"

# 913 "data/scripts/cable_club.pory"
CableClub_EventScript_UnionRoomAttendant:: @ 827751B
# 914 "data/scripts/cable_club.pory"
	lock
# 915 "data/scripts/cable_club.pory"
	faceplayer
# 916 "data/scripts/cable_club.pory"
	setvar VAR_FRONTIER_FACILITY, FACILITY_UNION_ROOM
# 917 "data/scripts/cable_club.pory"
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
# 918 "data/scripts/cable_club.pory"
	specialvar VAR_RESULT, IsBadEggInParty
# 919 "data/scripts/cable_club.pory"
	compare VAR_RESULT, TRUE
# 920 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkPlayerHasBadEgg
# 921 "data/scripts/cable_club.pory"
	copyvar VAR_0x8007, VAR_LAST_TALKED
# 922 "data/scripts/cable_club.pory"
	specialvar VAR_RESULT, IsWirelessAdapterConnected
# 923 "data/scripts/cable_club.pory"
	compare VAR_RESULT, FALSE
# 924 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_UnionRoomAdapterNotConnected
# 925 "data/scripts/cable_club.pory"
	message CableClub_Text_WelcomeUnionRoomEnter
# 926 "data/scripts/cable_club.pory"
	waitmessage
# 927 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_UnionRoomSelect
# 928 "data/scripts/cable_club.pory"
	end
# 929 "data/scripts/cable_club.pory"

# 930 "data/scripts/cable_club.pory"
CableClub_EventScript_UnionRoomSelect:: @ 827755C
# 931 "data/scripts/cable_club.pory"
	multichoice 17, 6, MULTI_YESNOINFO, 0
# 932 "data/scripts/cable_club.pory"
	switch VAR_RESULT
# 933 "data/scripts/cable_club.pory"
	case 0, CableClub_EventScript_EnterUnionRoom
# 934 "data/scripts/cable_club.pory"
	case 1, CableClub_EventScript_AbortLink
# 935 "data/scripts/cable_club.pory"
	case 2, CableClub_EventScript_UnionRoomInfo
# 936 "data/scripts/cable_club.pory"
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
# 937 "data/scripts/cable_club.pory"
	end
# 938 "data/scripts/cable_club.pory"

# 939 "data/scripts/cable_club.pory"
CableClub_EventScript_UnionRoomInfo:: @ 8277593
# 940 "data/scripts/cable_club.pory"
	message CableClub_Text_UnionRoomInfo
# 941 "data/scripts/cable_club.pory"
	waitmessage
# 942 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_UnionRoomSelect
# 943 "data/scripts/cable_club.pory"
	end
# 944 "data/scripts/cable_club.pory"

# 945 "data/scripts/cable_club.pory"
CableClub_EventScript_EnterUnionRoom:: @ 827759F
# 946 "data/scripts/cable_club.pory"
	call CableClub_EventScript_CheckPartyUnionRoomRequirements
# 947 "data/scripts/cable_club.pory"
	compare VAR_RESULT, 0
# 948 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLink
# 949 "data/scripts/cable_club.pory"
	call Common_EventScript_SaveGame
# 950 "data/scripts/cable_club.pory"
	compare VAR_RESULT, 0
# 951 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLink
# 952 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_EnjoyUnionRoom, MSGBOX_DEFAULT
# 953 "data/scripts/cable_club.pory"
	closemessage
# 954 "data/scripts/cable_club.pory"
	special HealPlayerParty
# 955 "data/scripts/cable_club.pory"
	setvar VAR_0x8004, USING_UNION_ROOM
# 956 "data/scripts/cable_club.pory"
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
# 957 "data/scripts/cable_club.pory"
	call CableClub_EventScript_OpenUnionRoomBarrier
# 958 "data/scripts/cable_club.pory"
	special DrawWholeMapView
# 959 "data/scripts/cable_club.pory"
	playse SE_CLICK
# 960 "data/scripts/cable_club.pory"
	delay 60
# 961 "data/scripts/cable_club.pory"
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
# 962 "data/scripts/cable_club.pory"
	waitmovement 0
# 963 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
# 964 "data/scripts/cable_club.pory"
	waitmovement 0
# 965 "data/scripts/cable_club.pory"
	opendoor 5, 1
# 966 "data/scripts/cable_club.pory"
	waitdooranim
# 967 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
# 968 "data/scripts/cable_club.pory"
	waitmovement 0
# 969 "data/scripts/cable_club.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 970 "data/scripts/cable_club.pory"
	closedoor 5, 1
# 971 "data/scripts/cable_club.pory"
	waitdooranim
# 972 "data/scripts/cable_club.pory"
	special Script_ResetUnionRoomTrade
# 973 "data/scripts/cable_club.pory"
	special SetCableClubWarp
# 974 "data/scripts/cable_club.pory"
	warpteleport2 MAP_UNION_ROOM, 255, 7, 11
# 975 "data/scripts/cable_club.pory"
	waitstate
# 976 "data/scripts/cable_club.pory"
	special RunUnionRoom
# 977 "data/scripts/cable_club.pory"
	waitstate
# 978 "data/scripts/cable_club.pory"
	end
# 979 "data/scripts/cable_club.pory"

# 980 "data/scripts/cable_club.pory"
CableClub_EventScript_CheckPartyUnionRoomRequirements:: @ 8277626
# 981 "data/scripts/cable_club.pory"
	specialvar VAR_RESULT, CountPartyNonEggMons
# 982 "data/scripts/cable_club.pory"
	compare VAR_RESULT, 2
# 983 "data/scripts/cable_club.pory"
	goto_if_lt CableClub_EventScript_NeedTwoMonsForUnionRoom
# 984 "data/scripts/cable_club.pory"
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
# 985 "data/scripts/cable_club.pory"
	compare VAR_RESULT, TRUE
# 986 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_NoEnigmaBerryInUnionRoom
# 987 "data/scripts/cable_club.pory"
	setvar VAR_RESULT, 1
# 988 "data/scripts/cable_club.pory"
	return
# 989 "data/scripts/cable_club.pory"

# 990 "data/scripts/cable_club.pory"
CableClub_EventScript_NeedTwoMonsForUnionRoom:: @ 827764C
# 991 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_NeedTwoMonsForUnionRoom, MSGBOX_DEFAULT
# 992 "data/scripts/cable_club.pory"
	goto EventScript_CableClub_SetVarResult0
# 993 "data/scripts/cable_club.pory"
	end
# 994 "data/scripts/cable_club.pory"

# 995 "data/scripts/cable_club.pory"
CableClub_EventScript_NoEnigmaBerryInUnionRoom:: @ 827765A
# 996 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_NoEnigmaBerryInUnionRoom, MSGBOX_DEFAULT
# 997 "data/scripts/cable_club.pory"
	goto EventScript_CableClub_SetVarResult0
# 998 "data/scripts/cable_club.pory"
	end
# 999 "data/scripts/cable_club.pory"

# 1000 "data/scripts/cable_club.pory"
CableClub_EventScript_UnionRoomAdapterNotConnected:: @ 8277668
# 1001 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_UnionRoomAdapterNotConnected, MSGBOX_DEFAULT
# 1002 "data/scripts/cable_club.pory"
	release
# 1003 "data/scripts/cable_club.pory"
	return
# 1004 "data/scripts/cable_club.pory"

# 1005 "data/scripts/cable_club.pory"
CableClub_EventScript_WirelessClubAttendant:: @ 8277672
# 1006 "data/scripts/cable_club.pory"
	lock
# 1007 "data/scripts/cable_club.pory"
	faceplayer
# 1008 "data/scripts/cable_club.pory"
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
# 1009 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_AskAboutLinking, MSGBOX_YESNO
# 1010 "data/scripts/cable_club.pory"
	compare VAR_RESULT, NO
# 1011 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_DontAskAboutLinking
# 1012 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_ExplainWirelessClub, MSGBOX_DEFAULT
# 1013 "data/scripts/cable_club.pory"
	release
# 1014 "data/scripts/cable_club.pory"
	return
# 1015 "data/scripts/cable_club.pory"

# 1016 "data/scripts/cable_club.pory"
CableClub_EventScript_DontAskAboutLinking:: @ 827769A
# 1017 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_HopeYouEnjoyWirelessSystem, MSGBOX_DEFAULT
# 1018 "data/scripts/cable_club.pory"
	release
# 1019 "data/scripts/cable_club.pory"
	return
# 1020 "data/scripts/cable_club.pory"

# 1021 "data/scripts/cable_club.pory"
CableClub_EventScript_DirectCornerAttendant:: @ 82776A4
# 1022 "data/scripts/cable_club.pory"
	lock
# 1023 "data/scripts/cable_club.pory"
	faceplayer
# 1024 "data/scripts/cable_club.pory"
	setvar VAR_FRONTIER_FACILITY, FACILITY_MULTI_OR_EREADER  @ Set preemptively for multi battles, ignored otherwise
# 1025 "data/scripts/cable_club.pory"
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
# 1026 "data/scripts/cable_club.pory"
	specialvar VAR_RESULT, IsBadEggInParty
# 1027 "data/scripts/cable_club.pory"
	compare VAR_RESULT, TRUE
# 1028 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLinkPlayerHasBadEgg
# 1029 "data/scripts/cable_club.pory"
	specialvar VAR_RESULT, IsWirelessAdapterConnected
# 1030 "data/scripts/cable_club.pory"
	compare VAR_RESULT, FALSE
# 1031 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_WelcomeToCableClub
# 1032 "data/scripts/cable_club.pory"
	message CableClub_Text_WelcomeWhichDirectCornerRoom
# 1033 "data/scripts/cable_club.pory"
	waitmessage
# 1034 "data/scripts/cable_club.pory"
	delay 28
# 1035 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_DirectCornerSelectService
# 1036 "data/scripts/cable_club.pory"
	end
# 1037 "data/scripts/cable_club.pory"

# 1038 "data/scripts/cable_club.pory"
CableClub_EventScript_DirectCornerSelectService:: @ 82776E3
# 1039 "data/scripts/cable_club.pory"
	checkitem ITEM_POWDER_JAR, 1
# 1040 "data/scripts/cable_club.pory"
	compare VAR_RESULT, FALSE
# 1041 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_DirectCornerNoBerry
# 1042 "data/scripts/cable_club.pory"
	goto_if_set FLAG_VISITED_MAUVILLE_CITY, CableClub_EventScript_DirectCornerSelectAllServices
# 1043 "data/scripts/cable_club.pory"
	multichoice 0, 0, MULTI_WIRELESS_NO_RECORD, 0
# 1044 "data/scripts/cable_club.pory"
	switch VAR_RESULT
# 1045 "data/scripts/cable_club.pory"
	case 0, CableClub_EventScript_WirelessTrade
# 1046 "data/scripts/cable_club.pory"
	case 1, CableClub_EventScript_WirelessBattleSelect
# 1047 "data/scripts/cable_club.pory"
	case 2, CableClub_EventScript_WirelessBerryCrush
# 1048 "data/scripts/cable_club.pory"
	case 3, CableClub_EventScript_AbortLink
# 1049 "data/scripts/cable_club.pory"
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
# 1050 "data/scripts/cable_club.pory"
	end
# 1051 "data/scripts/cable_club.pory"

# 1052 "data/scripts/cable_club.pory"
CableClub_EventScript_DirectCornerSelectAllServices:: @ 827773E
# 1053 "data/scripts/cable_club.pory"
	multichoice 0, 0, MULTI_WIRELESS_ALL_SERVICES, 0
# 1054 "data/scripts/cable_club.pory"
	switch VAR_RESULT
# 1055 "data/scripts/cable_club.pory"
	case 0, CableClub_EventScript_WirelessTrade
# 1056 "data/scripts/cable_club.pory"
	case 1, CableClub_EventScript_WirelessBattleSelect
# 1057 "data/scripts/cable_club.pory"
	case 2, CableClub_EventScript_WirelessRecordMix
# 1058 "data/scripts/cable_club.pory"
	case 3, CableClub_EventScript_WirelessBerryCrush
# 1059 "data/scripts/cable_club.pory"
	case 4, CableClub_EventScript_AbortLink
# 1060 "data/scripts/cable_club.pory"
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
# 1061 "data/scripts/cable_club.pory"
	end
# 1062 "data/scripts/cable_club.pory"

# 1063 "data/scripts/cable_club.pory"
CableClub_EventScript_DirectCornerNoBerry:: @ 827778B
# 1064 "data/scripts/cable_club.pory"
	goto_if_set FLAG_VISITED_MAUVILLE_CITY, CableClub_EventScript_DirectCornerHasRecordMix
# 1065 "data/scripts/cable_club.pory"
	multichoice 0, 0, MULTI_WIRELESS_NO_RECORD_BERRY, 0
# 1066 "data/scripts/cable_club.pory"
	switch VAR_RESULT
# 1067 "data/scripts/cable_club.pory"
	case 0, CableClub_EventScript_WirelessTrade
# 1068 "data/scripts/cable_club.pory"
	case 1, CableClub_EventScript_WirelessBattleSelect
# 1069 "data/scripts/cable_club.pory"
	case 2, CableClub_EventScript_AbortLink
# 1070 "data/scripts/cable_club.pory"
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
# 1071 "data/scripts/cable_club.pory"
	end
# 1072 "data/scripts/cable_club.pory"

# 1073 "data/scripts/cable_club.pory"
CableClub_EventScript_DirectCornerHasRecordMix:: @ 82777CB
# 1074 "data/scripts/cable_club.pory"
	multichoice 0, 0, MULTI_WIRELESS_NO_BERRY, 0
# 1075 "data/scripts/cable_club.pory"
	switch VAR_RESULT
# 1076 "data/scripts/cable_club.pory"
	case 0, CableClub_EventScript_WirelessTrade
# 1077 "data/scripts/cable_club.pory"
	case 1, CableClub_EventScript_WirelessBattleSelect
# 1078 "data/scripts/cable_club.pory"
	case 2, CableClub_EventScript_WirelessRecordMix
# 1079 "data/scripts/cable_club.pory"
	case 3, CableClub_EventScript_AbortLink
# 1080 "data/scripts/cable_club.pory"
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
# 1081 "data/scripts/cable_club.pory"
	end
# 1082 "data/scripts/cable_club.pory"

# 1083 "data/scripts/cable_club.pory"
CableClub_EventScript_WirelessTrade:: @ 827780D
# 1084 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_TradePokemon, MSGBOX_YESNO
# 1085 "data/scripts/cable_club.pory"
	compare VAR_RESULT, NO
# 1086 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLink
# 1087 "data/scripts/cable_club.pory"
	call CableClub_EventScript_CheckPartyTradeRequirements
# 1088 "data/scripts/cable_club.pory"
	compare VAR_RESULT, 0
# 1089 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLink
# 1090 "data/scripts/cable_club.pory"
	setvar VAR_0x8004, LINK_GROUP_TRADE
# 1091 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_SaveAndChooseLinkLeader
# 1092 "data/scripts/cable_club.pory"
	end
# 1093 "data/scripts/cable_club.pory"

# 1094 "data/scripts/cable_club.pory"
CableClub_EventScript_WirelessBattleSelect:: @ 827783B
# 1095 "data/scripts/cable_club.pory"
	message CableClub_Text_PlayWhichBattleMode
# 1096 "data/scripts/cable_club.pory"
	waitmessage
# 1097 "data/scripts/cable_club.pory"
	multichoice 0, 0, MULTI_BATTLE_MODE, 0
# 1098 "data/scripts/cable_club.pory"
	switch VAR_RESULT
# 1099 "data/scripts/cable_club.pory"
	case 0, CableClub_EventScript_WirelessSingleBattle
# 1100 "data/scripts/cable_club.pory"
	case 1, CableClub_EventScript_WirelessDoubleBattle
# 1101 "data/scripts/cable_club.pory"
	case 2, CableClub_EventScript_WirelessMultiBattle
# 1102 "data/scripts/cable_club.pory"
	case 3, CableClub_EventScript_WirelessBattleInfo
# 1103 "data/scripts/cable_club.pory"
	case 4, CableClub_EventScript_AbortLink
# 1104 "data/scripts/cable_club.pory"
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
# 1105 "data/scripts/cable_club.pory"
	end
# 1106 "data/scripts/cable_club.pory"

# 1107 "data/scripts/cable_club.pory"
CableClub_EventScript_WirelessSingleBattle:: @ 827788E
# 1108 "data/scripts/cable_club.pory"
	setvar VAR_0x8004, LINK_GROUP_SINGLE_BATTLE
# 1109 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_SaveAndChooseLinkLeader
# 1110 "data/scripts/cable_club.pory"
	end
# 1111 "data/scripts/cable_club.pory"

# 1112 "data/scripts/cable_club.pory"
CableClub_EventScript_WirelessDoubleBattle:: @ 8277899
# 1113 "data/scripts/cable_club.pory"
	special HasEnoughMonsForDoubleBattle
# 1114 "data/scripts/cable_club.pory"
	compare VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS
# 1115 "data/scripts/cable_club.pory"
	goto_if_ne CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle
# 1116 "data/scripts/cable_club.pory"
	setvar VAR_0x8004, LINK_GROUP_DOUBLE_BATTLE
# 1117 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_SaveAndChooseLinkLeader
# 1118 "data/scripts/cable_club.pory"
	end
# 1119 "data/scripts/cable_club.pory"

# 1120 "data/scripts/cable_club.pory"
CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle:: @ 82778B2
# 1121 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle, MSGBOX_DEFAULT
# 1122 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_WirelessBattleSelect
# 1123 "data/scripts/cable_club.pory"
	end
# 1124 "data/scripts/cable_club.pory"

# 1125 "data/scripts/cable_club.pory"
CableClub_EventScript_WirelessMultiBattle:: @ 82778C0
# 1126 "data/scripts/cable_club.pory"
	setvar VAR_0x8004, LINK_GROUP_MULTI_BATTLE
# 1127 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_SaveAndChooseLinkLeader
# 1128 "data/scripts/cable_club.pory"
	end
# 1129 "data/scripts/cable_club.pory"

# 1130 "data/scripts/cable_club.pory"
CableClub_EventScript_WirelessBattleInfo:: @ 82778CB
# 1131 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_ExplainBattleModes, MSGBOX_DEFAULT
# 1132 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_WirelessBattleSelect
# 1133 "data/scripts/cable_club.pory"
	end
# 1134 "data/scripts/cable_club.pory"

# 1135 "data/scripts/cable_club.pory"
CableClub_EventScript_WirelessRecordMix:: @ 82778D9
# 1136 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_AccessRecordCorner, MSGBOX_YESNO
# 1137 "data/scripts/cable_club.pory"
	compare VAR_RESULT, NO
# 1138 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLink
# 1139 "data/scripts/cable_club.pory"
	setvar VAR_0x8004, LINK_GROUP_RECORD_CORNER
# 1140 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_SaveAndChooseLinkLeader
# 1141 "data/scripts/cable_club.pory"
	end
# 1142 "data/scripts/cable_club.pory"

# 1143 "data/scripts/cable_club.pory"
CableClub_EventScript_WirelessBerryCrush:: @ 82778F7
# 1144 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_UseBerryCrush, MSGBOX_YESNO
# 1145 "data/scripts/cable_club.pory"
	compare VAR_RESULT, NO
# 1146 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLink
# 1147 "data/scripts/cable_club.pory"
	special HasAtLeastOneBerry
# 1148 "data/scripts/cable_club.pory"
	compare VAR_RESULT, FALSE
# 1149 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_NeedBerryForBerryCrush
# 1150 "data/scripts/cable_club.pory"
	setvar VAR_0x8004, LINK_GROUP_BERRY_CRUSH
# 1151 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_SaveAndChooseLinkLeader
# 1152 "data/scripts/cable_club.pory"
	end
# 1153 "data/scripts/cable_club.pory"

# 1154 "data/scripts/cable_club.pory"
CableClub_EventScript_NeedBerryForBerryCrush:: @ 8277923
# 1155 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_NeedBerryForBerryCrush, MSGBOX_DEFAULT
# 1156 "data/scripts/cable_club.pory"
	goto CableClub_EventScript_DirectCornerSelectService
# 1157 "data/scripts/cable_club.pory"
	end
# 1158 "data/scripts/cable_club.pory"

# 1159 "data/scripts/cable_club.pory"
CableClub_EventScript_SaveAndChooseLinkLeader:: @ 8277931
# 1160 "data/scripts/cable_club.pory"
	call Common_EventScript_SaveGame
# 1161 "data/scripts/cable_club.pory"
	compare VAR_RESULT, 0
# 1162 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AbortLink
# 1163 "data/scripts/cable_club.pory"
	switch VAR_0x8004
# 1164 "data/scripts/cable_club.pory"
	case LINK_GROUP_TRADE, CableClub_EventScript_ChooseLinkLeaderFrom2
# 1165 "data/scripts/cable_club.pory"
	case LINK_GROUP_SINGLE_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom2
# 1166 "data/scripts/cable_club.pory"
	case LINK_GROUP_DOUBLE_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom2
# 1167 "data/scripts/cable_club.pory"
	case LINK_GROUP_MULTI_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom4
# 1168 "data/scripts/cable_club.pory"
	case LINK_GROUP_BERRY_CRUSH, CableClub_EventScript_ChooseLinkLeader
# 1169 "data/scripts/cable_club.pory"
	case LINK_GROUP_RECORD_CORNER, CableClub_EventScript_ChooseLinkLeader
# 1170 "data/scripts/cable_club.pory"
	end
# 1171 "data/scripts/cable_club.pory"

# 1172 "data/scripts/cable_club.pory"
CableClub_EventScript_ChooseLinkLeaderFrom2:: @ 8277989
# 1173 "data/scripts/cable_club.pory"
	message CableClub_Text_ChooseGroupLeaderOfTwo
# 1174 "data/scripts/cable_club.pory"
	waitmessage
# 1175 "data/scripts/cable_club.pory"
	multichoice 16, 6, MULTI_LINK_LEADER, 0
# 1176 "data/scripts/cable_club.pory"
	switch VAR_RESULT
# 1177 "data/scripts/cable_club.pory"
	case 0, CableClub_EventScript_TryJoinGroup2Players
# 1178 "data/scripts/cable_club.pory"
	case 1, CableClub_EventScript_TryLeadGroup2Players
# 1179 "data/scripts/cable_club.pory"
	case 2, CableClub_EventScript_AbortLink
# 1180 "data/scripts/cable_club.pory"
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
# 1181 "data/scripts/cable_club.pory"
	end
# 1182 "data/scripts/cable_club.pory"

# 1183 "data/scripts/cable_club.pory"
CableClub_EventScript_TryLeadGroup2Players:: @ 82779C6
# 1184 "data/scripts/cable_club.pory"
	call CableClub_EventScript_TryBecomeLinkLeader
# 1185 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_SUCCESS
# 1186 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
# 1187 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 1188 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_ChooseLinkLeaderFrom2
# 1189 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
# 1190 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_TryLeadGroup2Players
# 1191 "data/scripts/cable_club.pory"
	release
# 1192 "data/scripts/cable_club.pory"
	return
# 1193 "data/scripts/cable_club.pory"

# 1194 "data/scripts/cable_club.pory"
CableClub_EventScript_TryJoinGroup2Players:: @ 82779EE
# 1195 "data/scripts/cable_club.pory"
	call CableClub_EventScript_TryJoinLinkGroup
# 1196 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_SUCCESS
# 1197 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
# 1198 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 1199 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_ChooseLinkLeaderFrom2
# 1200 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
# 1201 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_TryJoinGroup2Players
# 1202 "data/scripts/cable_club.pory"
	release
# 1203 "data/scripts/cable_club.pory"
	return
# 1204 "data/scripts/cable_club.pory"

# 1205 "data/scripts/cable_club.pory"
CableClub_EventScript_ChooseLinkLeaderFrom4:: @ 8277A16
# 1206 "data/scripts/cable_club.pory"
	message CableClub_Text_ChooseGroupLeaderOfFour
# 1207 "data/scripts/cable_club.pory"
	waitmessage
# 1208 "data/scripts/cable_club.pory"
	multichoice 16, 6, MULTI_LINK_LEADER, 0
# 1209 "data/scripts/cable_club.pory"
	switch VAR_RESULT
# 1210 "data/scripts/cable_club.pory"
	case 0, CableClub_EventScript_TryJoinGroup4Players
# 1211 "data/scripts/cable_club.pory"
	case 1, CableClub_EventScript_TryLeadGroup4Players
# 1212 "data/scripts/cable_club.pory"
	case 2, CableClub_EventScript_AbortLink
# 1213 "data/scripts/cable_club.pory"
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
# 1214 "data/scripts/cable_club.pory"
	end
# 1215 "data/scripts/cable_club.pory"

# 1216 "data/scripts/cable_club.pory"
CableClub_EventScript_TryLeadGroup4Players:: @ 8277A53
# 1217 "data/scripts/cable_club.pory"
	call CableClub_EventScript_TryBecomeLinkLeader
# 1218 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_SUCCESS
# 1219 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
# 1220 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 1221 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_ChooseLinkLeaderFrom4
# 1222 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
# 1223 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_TryLeadGroup4Players
# 1224 "data/scripts/cable_club.pory"
	release
# 1225 "data/scripts/cable_club.pory"
	return
# 1226 "data/scripts/cable_club.pory"

# 1227 "data/scripts/cable_club.pory"
CableClub_EventScript_TryJoinGroup4Players:: @ 8277A7B
# 1228 "data/scripts/cable_club.pory"
	call CableClub_EventScript_TryJoinLinkGroup
# 1229 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_SUCCESS
# 1230 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
# 1231 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 1232 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_ChooseLinkLeaderFrom4
# 1233 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
# 1234 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_TryJoinGroup4Players
# 1235 "data/scripts/cable_club.pory"
	release
# 1236 "data/scripts/cable_club.pory"
	return
# 1237 "data/scripts/cable_club.pory"

# 1238 "data/scripts/cable_club.pory"
CableClub_EventScript_ChooseLinkLeader:: @ 8277AA3
# 1239 "data/scripts/cable_club.pory"
	message CableClub_Text_ChooseGroupLeader
# 1240 "data/scripts/cable_club.pory"
	waitmessage
# 1241 "data/scripts/cable_club.pory"
	multichoice 16, 6, MULTI_LINK_LEADER, 0
# 1242 "data/scripts/cable_club.pory"
	switch VAR_RESULT
# 1243 "data/scripts/cable_club.pory"
	case 0, CableClub_EventScript_TryJoinGroupXPlayers
# 1244 "data/scripts/cable_club.pory"
	case 1, CableClub_EventScript_TryLeadGroupXPlayers
# 1245 "data/scripts/cable_club.pory"
	case 2, CableClub_EventScript_AbortLink
# 1246 "data/scripts/cable_club.pory"
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink
# 1247 "data/scripts/cable_club.pory"
	end
# 1248 "data/scripts/cable_club.pory"

# 1249 "data/scripts/cable_club.pory"
CableClub_EventScript_TryLeadGroupXPlayers:: @ 8277AE0
# 1250 "data/scripts/cable_club.pory"
	call CableClub_EventScript_TryBecomeLinkLeader
# 1251 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_SUCCESS
# 1252 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
# 1253 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 1254 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_ChooseLinkLeader
# 1255 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
# 1256 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_TryLeadGroupXPlayers
# 1257 "data/scripts/cable_club.pory"
	release
# 1258 "data/scripts/cable_club.pory"
	return
# 1259 "data/scripts/cable_club.pory"

# 1260 "data/scripts/cable_club.pory"
CableClub_EventScript_TryJoinGroupXPlayers:: @ 8277B08
# 1261 "data/scripts/cable_club.pory"
	call CableClub_EventScript_TryJoinLinkGroup
# 1262 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_SUCCESS
# 1263 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_EnterWirelessLinkRoom
# 1264 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 1265 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_ChooseLinkLeader
# 1266 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
# 1267 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_TryJoinGroupXPlayers
# 1268 "data/scripts/cable_club.pory"
	release
# 1269 "data/scripts/cable_club.pory"
	return
# 1270 "data/scripts/cable_club.pory"

# 1271 "data/scripts/cable_club.pory"
CableClub_EventScript_TryBecomeLinkLeader:: @ 8277B30
# 1272 "data/scripts/cable_club.pory"
	special TryBecomeLinkLeader
# 1273 "data/scripts/cable_club.pory"
	waitstate
# 1274 "data/scripts/cable_club.pory"
	return
# 1275 "data/scripts/cable_club.pory"

# 1276 "data/scripts/cable_club.pory"
CableClub_EventScript_TryJoinLinkGroup:: @ 8277B35
# 1277 "data/scripts/cable_club.pory"
	special TryJoinLinkGroup
# 1278 "data/scripts/cable_club.pory"
	waitstate
# 1279 "data/scripts/cable_club.pory"
	return
# 1280 "data/scripts/cable_club.pory"

# 1281 "data/scripts/cable_club.pory"
CableClub_EventScript_EnterWirelessLinkRoom:: @ 8277B3A
# 1282 "data/scripts/cable_club.pory"
	messageautoscroll CableClub_Text_DirectYouToYourRoom
# 1283 "data/scripts/cable_club.pory"
	waitmessage
# 1284 "data/scripts/cable_club.pory"
	delay 60
# 1285 "data/scripts/cable_club.pory"
	closemessage
# 1286 "data/scripts/cable_club.pory"
	copyvar VAR_0x8007, VAR_LAST_TALKED
# 1287 "data/scripts/cable_club.pory"
	call CableClub_EventScript_OpenDirectCornerBarrier
# 1288 "data/scripts/cable_club.pory"
	special DrawWholeMapView
# 1289 "data/scripts/cable_club.pory"
	playse SE_CLICK
# 1290 "data/scripts/cable_club.pory"
	delay 60
# 1291 "data/scripts/cable_club.pory"
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
# 1292 "data/scripts/cable_club.pory"
	waitmovement 0
# 1293 "data/scripts/cable_club.pory"
	closemessage
# 1294 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
# 1295 "data/scripts/cable_club.pory"
	waitmovement 0
# 1296 "data/scripts/cable_club.pory"
	opendoor 9, 1
# 1297 "data/scripts/cable_club.pory"
	waitdooranim
# 1298 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
# 1299 "data/scripts/cable_club.pory"
	waitmovement 0
# 1300 "data/scripts/cable_club.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 1301 "data/scripts/cable_club.pory"
	closedoor 9, 1
# 1302 "data/scripts/cable_club.pory"
	waitdooranim
# 1303 "data/scripts/cable_club.pory"
	release
# 1304 "data/scripts/cable_club.pory"
	waitstate
# 1305 "data/scripts/cable_club.pory"
	end
# 1306 "data/scripts/cable_club.pory"

# 1307 "data/scripts/cable_club.pory"
EventScript_WirelessBoxResults:: @ 8277B8A
# 1308 "data/scripts/cable_club.pory"
	lockall
# 1309 "data/scripts/cable_club.pory"
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_NotReadyYet
# 1310 "data/scripts/cable_club.pory"
	specialvar VAR_RESULT, IsWirelessAdapterConnected
# 1311 "data/scripts/cable_club.pory"
	compare VAR_RESULT, FALSE
# 1312 "data/scripts/cable_club.pory"
	goto_if_eq CableClub_EventScript_AdapterNotConnected
# 1313 "data/scripts/cable_club.pory"
	fadescreen FADE_TO_BLACK
# 1314 "data/scripts/cable_club.pory"
	special ShowWirelessCommunicationScreen
# 1315 "data/scripts/cable_club.pory"
	waitstate
# 1316 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_ParticipantsStepUpToCounter, MSGBOX_DEFAULT
# 1317 "data/scripts/cable_club.pory"
	releaseall
# 1318 "data/scripts/cable_club.pory"
	end
# 1319 "data/scripts/cable_club.pory"

# 1320 "data/scripts/cable_club.pory"
CableClub_EventScript_AdapterNotConnected:: @ 8277BB4
# 1321 "data/scripts/cable_club.pory"
	msgbox CableClub_Text_AdapterNotConnected, MSGBOX_DEFAULT
# 1322 "data/scripts/cable_club.pory"
	releaseall
# 1323 "data/scripts/cable_club.pory"
	end
# 1324 "data/scripts/cable_club.pory"

# 1325 "data/scripts/cable_club.pory"
CableClub_EventScript_OpenUnionRoomBarrier:: @ 8277BBE
# 1326 "data/scripts/cable_club.pory"
	setmetatile 5, 2, METATILE_PokemonCenter_Floor_ShadowTop_Alt, 0
# 1327 "data/scripts/cable_club.pory"
	setmetatile 5, 3, METATILE_PokemonCenter_Floor_Plain_Alt, 0
# 1328 "data/scripts/cable_club.pory"
	return
# 1329 "data/scripts/cable_club.pory"

# 1330 "data/scripts/cable_club.pory"
CableClub_EventScript_CloseUnionRoomBarrier:: @ 8277BD1
# 1331 "data/scripts/cable_club.pory"
	setmetatile 5, 2, METATILE_PokemonCenter_Floor_ShadowTop, 1
# 1332 "data/scripts/cable_club.pory"
	setmetatile 5, 3, METATILE_PokemonCenter_CounterBarrier, 1
# 1333 "data/scripts/cable_club.pory"
	return
# 1334 "data/scripts/cable_club.pory"

# 1335 "data/scripts/cable_club.pory"
CableClub_EventScript_OpenDirectCornerBarrier:: @ 8277BE4
# 1336 "data/scripts/cable_club.pory"
	setmetatile 9, 2, METATILE_PokemonCenter_Floor_ShadowTop_Alt, 0
# 1337 "data/scripts/cable_club.pory"
	setmetatile 9, 3, METATILE_PokemonCenter_Floor_Plain_Alt, 0
# 1338 "data/scripts/cable_club.pory"
	return
# 1339 "data/scripts/cable_club.pory"

# 1340 "data/scripts/cable_club.pory"
CableClub_EventScript_CloseDirectCornerBarrier:: @ 8277BF7
# 1341 "data/scripts/cable_club.pory"
	setmetatile 9, 2, METATILE_PokemonCenter_Floor_ShadowTop, 1
# 1342 "data/scripts/cable_club.pory"
	setmetatile 9, 3, METATILE_PokemonCenter_CounterBarrier, 1
# 1343 "data/scripts/cable_club.pory"
	return
# 1344 "data/scripts/cable_club.pory"

# 1345 "data/scripts/cable_club.pory"
EventScript_OpenMossdeepGameCornerBarrier:: @ 8277C0A
# 1346 "data/scripts/cable_club.pory"
	setmetatile 5, 2, METATILE_MossdeepGameCorner_CounterOpen_Top, 0
# 1347 "data/scripts/cable_club.pory"
	setmetatile 5, 3, METATILE_MossdeepGameCorner_CounterOpen_Bottom, 0
# 1348 "data/scripts/cable_club.pory"
	return
# 1349 "data/scripts/cable_club.pory"

# 1350 "data/scripts/cable_club.pory"
EventScript_CloseMossdeepGameCornerBarrier:: @ 8277C1D
# 1351 "data/scripts/cable_club.pory"
	setmetatile 5, 2, METATILE_MossdeepGameCorner_CounterClosed_Top, 1
# 1352 "data/scripts/cable_club.pory"
	setmetatile 5, 3, METATILE_MossdeepGameCorner_CounterClosed_Bottom, 1
# 1353 "data/scripts/cable_club.pory"
	return
# 1354 "data/scripts/cable_club.pory"

# 1355 "data/scripts/cable_club.pory"
CableClub_OnResume: @ 8277C30
# 1356 "data/scripts/cable_club.pory"
	special InitUnionRoom
# 1357 "data/scripts/cable_club.pory"
	end
# 1358 "data/scripts/cable_club.pory"

# 1359 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_InfoMan2:: @ 8277C34
# 1360 "data/scripts/cable_club.pory"
	lock
# 1361 "data/scripts/cable_club.pory"
	faceplayer
# 1362 "data/scripts/cable_club.pory"
	message MossdeepCity_GameCorner_1F_Text_DescribeWhichGame
# 1363 "data/scripts/cable_club.pory"
	waitmessage
# 1364 "data/scripts/cable_club.pory"
	multichoice 0, 0, MULTI_WIRELESS_MINIGAME, 0
# 1365 "data/scripts/cable_club.pory"
	switch VAR_RESULT
# 1366 "data/scripts/cable_club.pory"
	case 0, MossdeepCity_GameCorner_1F_EventScript_PokemonJumpInfo
# 1367 "data/scripts/cable_club.pory"
	case 1, MossdeepCity_GameCorner_1F_EventScript_DodrioBerryPickingInfo
# 1368 "data/scripts/cable_club.pory"
	case 2, MossdeepCity_GameCorner_1F_EventScript_MinigameInfoExit
# 1369 "data/scripts/cable_club.pory"
	case MULTI_B_PRESSED, MossdeepCity_GameCorner_1F_EventScript_MinigameInfoExit
# 1370 "data/scripts/cable_club.pory"
	end
# 1371 "data/scripts/cable_club.pory"

# 1372 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_PokemonJumpInfo:: @ 8277C73
# 1373 "data/scripts/cable_club.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_PokemonJumpInfo, MSGBOX_DEFAULT
# 1374 "data/scripts/cable_club.pory"
	release
# 1375 "data/scripts/cable_club.pory"
	end
# 1376 "data/scripts/cable_club.pory"

# 1377 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_DodrioBerryPickingInfo:: @ 8277C7D
# 1378 "data/scripts/cable_club.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_DodrioBerryPickingInfo, MSGBOX_DEFAULT
# 1379 "data/scripts/cable_club.pory"
	release
# 1380 "data/scripts/cable_club.pory"
	end
# 1381 "data/scripts/cable_club.pory"

# 1382 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_MinigameInfoExit:: @ 8277C87
# 1383 "data/scripts/cable_club.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_TalkToOldManToPlay, MSGBOX_DEFAULT
# 1384 "data/scripts/cable_club.pory"
	release
# 1385 "data/scripts/cable_club.pory"
	end
# 1386 "data/scripts/cable_club.pory"

# 1387 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_OldMan2:: @ 8277C91
# 1388 "data/scripts/cable_club.pory"
	lock
# 1389 "data/scripts/cable_club.pory"
	faceplayer
# 1390 "data/scripts/cable_club.pory"
	message MossdeepCity_GameCorner_1F_Text_WelcomeCanYouWait
# 1391 "data/scripts/cable_club.pory"
	waitmessage
# 1392 "data/scripts/cable_club.pory"
	//specialvar VAR_RESULT, IsWirelessAdapterConnected
# 1393 "data/scripts/cable_club.pory"
	//compare VAR_RESULT, FALSE
# 1394 "data/scripts/cable_club.pory"
	//goto_if_eq MossdeepCity_GameCorner_1F_EventScript_AdapterNotConnected
# 1395 "data/scripts/cable_club.pory"
	delay 30
# 1396 "data/scripts/cable_club.pory"
	message MossdeepCity_GameCorner_1F_Text_PlayWhichGame
# 1397 "data/scripts/cable_club.pory"
	waitmessage
# 1398 "data/scripts/cable_club.pory"
	multichoice 0, 0, MULTI_WIRELESS_MINIGAME, 0
# 1399 "data/scripts/cable_club.pory"
	switch VAR_RESULT
# 1400 "data/scripts/cable_club.pory"
	case 0, MossdeepCity_GameCorner_1F_EventScript_PlayPokemonJump
# 1401 "data/scripts/cable_club.pory"
	case 1, MossdeepCity_GameCorner_1F_EventScript_PlayDodrioBerryPicking
# 1402 "data/scripts/cable_club.pory"
	case 2, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
# 1403 "data/scripts/cable_club.pory"
	case MULTI_B_PRESSED, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
# 1404 "data/scripts/cable_club.pory"
	end
# 1405 "data/scripts/cable_club.pory"

# 1406 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_PlayPokemonJump:: @ 8277CE9
# 1407 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 0
# 1408 "data/scripts/cable_club.pory"
	special IsPokemonJumpSpeciesInParty
# 1409 "data/scripts/cable_club.pory"
	compare VAR_RESULT, FALSE
# 1410 "data/scripts/cable_club.pory"
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_DontHaveRequiredMon
# 1411 "data/scripts/cable_club.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_EnterWhichPokemon, MSGBOX_DEFAULT
# 1412 "data/scripts/cable_club.pory"
	fadescreen FADE_TO_BLACK
# 1413 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 0
# 1414 "data/scripts/cable_club.pory"
	special ChooseMonForWirelessMinigame
# 1415 "data/scripts/cable_club.pory"
	waitstate
# 1416 "data/scripts/cable_club.pory"
	compare VAR_0x8004, PARTY_SIZE
# 1417 "data/scripts/cable_club.pory"
	goto_if_ge MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
# 1418 "data/scripts/cable_club.pory"
	call Common_EventScript_SaveGame
# 1419 "data/scripts/cable_club.pory"
	compare VAR_RESULT, 0
# 1420 "data/scripts/cable_club.pory"
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
# 1421 "data/scripts/cable_club.pory"
	setvar VAR_0x8004, LINK_GROUP_POKEMON_JUMP
# 1422 "data/scripts/cable_club.pory"
	goto MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader
# 1423 "data/scripts/cable_club.pory"
	end
# 1424 "data/scripts/cable_club.pory"

# 1425 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_PlayDodrioBerryPicking:: @ 8277D35
# 1426 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 1
# 1427 "data/scripts/cable_club.pory"
	special IsDodrioInParty
# 1428 "data/scripts/cable_club.pory"
	compare VAR_RESULT, FALSE
# 1429 "data/scripts/cable_club.pory"
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_DontHaveRequiredMon
# 1430 "data/scripts/cable_club.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_EnterWhichPokemon, MSGBOX_DEFAULT
# 1431 "data/scripts/cable_club.pory"
	fadescreen FADE_TO_BLACK
# 1432 "data/scripts/cable_club.pory"
	setvar VAR_0x8005, 1
# 1433 "data/scripts/cable_club.pory"
	special ChooseMonForWirelessMinigame
# 1434 "data/scripts/cable_club.pory"
	waitstate
# 1435 "data/scripts/cable_club.pory"
	compare VAR_0x8004, PARTY_SIZE
# 1436 "data/scripts/cable_club.pory"
	goto_if_ge MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
# 1437 "data/scripts/cable_club.pory"
	//call Common_EventScript_SaveGame
# 1438 "data/scripts/cable_club.pory"
	//compare VAR_RESULT, 0
# 1439 "data/scripts/cable_club.pory"
	//goto_if_eq MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
# 1440 "data/scripts/cable_club.pory"
	setvar VAR_0x8004, LINK_GROUP_BERRY_PICKING
# 1441 "data/scripts/cable_club.pory"
	goto MossdeepCity_GameCorner_1F_EventScript_EnterMinigameRoom
# 1442 "data/scripts/cable_club.pory"
	//goto MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader
# 1443 "data/scripts/cable_club.pory"
	end
# 1444 "data/scripts/cable_club.pory"

# 1445 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader:: @ 8277D81
# 1446 "data/scripts/cable_club.pory"
	message CableClub_Text_ChooseGroupLeader
# 1447 "data/scripts/cable_club.pory"
	waitmessage
# 1448 "data/scripts/cable_club.pory"
	multichoice 16, 6, MULTI_LINK_LEADER, 0
# 1449 "data/scripts/cable_club.pory"
	switch VAR_RESULT
# 1450 "data/scripts/cable_club.pory"
	case 0, MossdeepCity_GameCorner_1F_EventScript_TryJoinLinkGroup
# 1451 "data/scripts/cable_club.pory"
	case 1, MossdeepCity_GameCorner_1F_EventScript_TryBecomeLinkLeader
# 1452 "data/scripts/cable_club.pory"
	case 2, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
# 1453 "data/scripts/cable_club.pory"
	case MULTI_B_PRESSED, MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
# 1454 "data/scripts/cable_club.pory"
	end
# 1455 "data/scripts/cable_club.pory"

# 1456 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_TryBecomeLinkLeader:: @ 8277DBE
# 1457 "data/scripts/cable_club.pory"
	call CableClub_EventScript_TryBecomeLinkLeader
# 1458 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_SUCCESS
# 1459 "data/scripts/cable_club.pory"
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_EnterMinigameRoom
# 1460 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 1461 "data/scripts/cable_club.pory"
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader
# 1462 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
# 1463 "data/scripts/cable_club.pory"
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_TryBecomeLinkLeader
# 1464 "data/scripts/cable_club.pory"
	release
# 1465 "data/scripts/cable_club.pory"
	return
# 1466 "data/scripts/cable_club.pory"

# 1467 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_TryJoinLinkGroup:: @ 8277DE6
# 1468 "data/scripts/cable_club.pory"
	call CableClub_EventScript_TryJoinLinkGroup
# 1469 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_SUCCESS
# 1470 "data/scripts/cable_club.pory"
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_EnterMinigameRoom
# 1471 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_FAILED
# 1472 "data/scripts/cable_club.pory"
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_ChooseLinkLeader
# 1473 "data/scripts/cable_club.pory"
	compare VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN
# 1474 "data/scripts/cable_club.pory"
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_TryJoinLinkGroup
# 1475 "data/scripts/cable_club.pory"
	release
# 1476 "data/scripts/cable_club.pory"
	return
# 1477 "data/scripts/cable_club.pory"

# 1478 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_EnterMinigameRoom:: @ 8277E0E
# 1479 "data/scripts/cable_club.pory"
	messageautoscroll MossdeepCity_GameCorner_1F_Text_AllGoodToGo
# 1480 "data/scripts/cable_club.pory"
	waitmessage
# 1481 "data/scripts/cable_club.pory"
	delay 60
# 1482 "data/scripts/cable_club.pory"
	closemessage
# 1483 "data/scripts/cable_club.pory"
	copyvar VAR_0x8007, VAR_LAST_TALKED
# 1484 "data/scripts/cable_club.pory"
	call EventScript_OpenMossdeepGameCornerBarrier
# 1485 "data/scripts/cable_club.pory"
	special DrawWholeMapView
# 1486 "data/scripts/cable_club.pory"
	playse SE_CLICK
# 1487 "data/scripts/cable_club.pory"
	delay 60
# 1488 "data/scripts/cable_club.pory"
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
# 1489 "data/scripts/cable_club.pory"
	waitmovement 0
# 1490 "data/scripts/cable_club.pory"
	closemessage
# 1491 "data/scripts/cable_club.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterMinigameRoom
# 1492 "data/scripts/cable_club.pory"
	waitmovement 0
# 1493 "data/scripts/cable_club.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 1494 "data/scripts/cable_club.pory"
	release
# 1495 "data/scripts/cable_club.pory"
	waitstate
# 1496 "data/scripts/cable_club.pory"
	end
# 1497 "data/scripts/cable_club.pory"

# 1498 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_AdapterNotConnected:: @ 8277E48
# 1499 "data/scripts/cable_club.pory"
	delay 60
# 1500 "data/scripts/cable_club.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_AdapterNotConnected, MSGBOX_DEFAULT
# 1501 "data/scripts/cable_club.pory"
	release
# 1502 "data/scripts/cable_club.pory"
	end
# 1503 "data/scripts/cable_club.pory"

# 1504 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_DontHaveRequiredMon:: @ 8277E55
# 1505 "data/scripts/cable_club.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_ExplainRequiredMon, MSGBOX_YESNO
# 1506 "data/scripts/cable_club.pory"
	compare VAR_RESULT, NO
# 1507 "data/scripts/cable_club.pory"
	goto_if_eq MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
# 1508 "data/scripts/cable_club.pory"
	compare VAR_0x8005, 0
# 1509 "data/scripts/cable_club.pory"
	call_if_eq MossdeepCity_GameCorner_1F_EventScript_ExplainPokemonJumpRequirements
# 1510 "data/scripts/cable_club.pory"
	compare VAR_0x8005, 1
# 1511 "data/scripts/cable_club.pory"
	call_if_eq MossdeepCity_GameCorner_1F_EventScript_ExplainDodrioBerryPickingRequirements
# 1512 "data/scripts/cable_club.pory"
	goto MossdeepCity_GameCorner_1F_EventScript_AbortMinigame
# 1513 "data/scripts/cable_club.pory"
	end
# 1514 "data/scripts/cable_club.pory"

# 1515 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_ExplainPokemonJumpRequirements:: @ 8277E84
# 1516 "data/scripts/cable_club.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_ShortJumpingPokemonAllowed, MSGBOX_DEFAULT
# 1517 "data/scripts/cable_club.pory"
	return
# 1518 "data/scripts/cable_club.pory"

# 1519 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_ExplainDodrioBerryPickingRequirements:: @ 8277E8D
# 1520 "data/scripts/cable_club.pory"
	msgbox MossdeepCity_GameCorner_1F_Text_OnlyDodrioAllowed, MSGBOX_DEFAULT
# 1521 "data/scripts/cable_club.pory"
	return
# 1522 "data/scripts/cable_club.pory"

# 1523 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_PokemonJumpRecords:: @ 8277E96
# 1524 "data/scripts/cable_club.pory"
	lockall
# 1525 "data/scripts/cable_club.pory"
	special ShowPokemonJumpRecords
# 1526 "data/scripts/cable_club.pory"
	waitstate
# 1527 "data/scripts/cable_club.pory"
	releaseall
# 1528 "data/scripts/cable_club.pory"
	end
# 1529 "data/scripts/cable_club.pory"

# 1530 "data/scripts/cable_club.pory"
MossdeepCity_GameCorner_1F_EventScript_DodrioBerryPickingRecords:: @ 8277E9D
# 1531 "data/scripts/cable_club.pory"
	lockall
# 1532 "data/scripts/cable_club.pory"
	special ShowDodrioBerryPickingRecords
# 1533 "data/scripts/cable_club.pory"
	waitstate
# 1534 "data/scripts/cable_club.pory"
	releaseall
# 1535 "data/scripts/cable_club.pory"
	end
