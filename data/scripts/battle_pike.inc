# 1 "data/scripts/battle_pike.pory"

# 2 "data/scripts/battle_pike.pory"
@ Note: LOCALIDs shared with BattleFrontier_BattlePikeRoomNormal
# 3 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoomNormal_MapScripts_2C3E1B:
# 4 "data/scripts/battle_pike.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePikeRoom_OnTransition
# 5 "data/scripts/battle_pike.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoom_OnWarp
# 6 "data/scripts/battle_pike.pory"

# 7 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoom_OnTransition:
# 8 "data/scripts/battle_pike.pory"
	pike_setroomobjects
# 9 "data/scripts/battle_pike.pory"
	pike_getroomtype
# 10 "data/scripts/battle_pike.pory"
	switch VAR_RESULT
# 11 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_SINGLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_SetOneObjectRoomPos
# 12 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_HEAL_FULL, BattleFrontier_BattlePikeRoomNormal_EventScript_SetOneObjectRoomPos
# 13 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_NPC, BattleFrontier_BattlePikeRoomNormal_EventScript_SetNPCRoomObjPos
# 14 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeRoomNormal_EventScript_SetTwoObjectRoomPos
# 15 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_HEAL_PART, BattleFrontier_BattlePikeRoomNormal_EventScript_SetOneObjectRoomPos
# 16 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_DOUBLE_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_SetDoubleBattleObjPos
# 17 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_HARD_BATTLE, BattleFrontier_BattlePikeRoomNormal_EventScript_SetTwoObjectRoomPos
# 18 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_BRAIN, BattleFrontier_BattlePikeRoomNormal_EventScript_SetBrainRoomObjPos
# 19 "data/scripts/battle_pike.pory"
	end
# 20 "data/scripts/battle_pike.pory"

# 21 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetDoubleBattleObjPos::
# 22 "data/scripts/battle_pike.pory"
	setobjectxyperm LOCALID_OBJ_0, 2, 5
# 23 "data/scripts/battle_pike.pory"
	setobjectxyperm LOCALID_OBJ_1, 6, 5
# 24 "data/scripts/battle_pike.pory"
	end
# 25 "data/scripts/battle_pike.pory"

# 26 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetTwoObjectRoomPos::
# 27 "data/scripts/battle_pike.pory"
	setobjectxyperm LOCALID_OBJ_0, 4, 4
# 28 "data/scripts/battle_pike.pory"
	setobjectxyperm LOCALID_OBJ_1, 3, 4
# 29 "data/scripts/battle_pike.pory"
	end
# 30 "data/scripts/battle_pike.pory"

# 31 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetOneObjectRoomPos::
# 32 "data/scripts/battle_pike.pory"
	setobjectxyperm LOCALID_OBJ_0, 4, 4
# 33 "data/scripts/battle_pike.pory"
	setobjectxyperm LOCALID_OBJ_1, 0, 0
# 34 "data/scripts/battle_pike.pory"
	end
# 35 "data/scripts/battle_pike.pory"

# 36 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetNPCRoomObjPos::
# 37 "data/scripts/battle_pike.pory"
	setobjectxyperm LOCALID_OBJ_0, 5, 5
# 38 "data/scripts/battle_pike.pory"
	setobjectxyperm LOCALID_OBJ_1, 0, 0
# 39 "data/scripts/battle_pike.pory"
	end
# 40 "data/scripts/battle_pike.pory"

# 41 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetBrainRoomObjPos::
# 42 "data/scripts/battle_pike.pory"
	setobjectxyperm LOCALID_OBJ_0, 4, 3
# 43 "data/scripts/battle_pike.pory"
	setobjectxyperm LOCALID_OBJ_1, 4, 4
# 44 "data/scripts/battle_pike.pory"
	end
# 45 "data/scripts/battle_pike.pory"

# 46 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoom_OnWarp:
# 47 "data/scripts/battle_pike.pory"
	map_script_2 VAR_TEMP_4, 0, BattleFrontier_BattlePikeRoomNormal_EventScript_InitRoomObjects
# 48 "data/scripts/battle_pike.pory"
	.2byte 0
# 49 "data/scripts/battle_pike.pory"

# 50 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_InitRoomObjects::
# 51 "data/scripts/battle_pike.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LINK_RECEPTIONIST
# 52 "data/scripts/battle_pike.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LINK_RECEPTIONIST
# 53 "data/scripts/battle_pike.pory"
	pike_getroomtype
# 54 "data/scripts/battle_pike.pory"
	compare VAR_RESULT, PIKE_ROOM_STATUS
# 55 "data/scripts/battle_pike.pory"
	goto_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_InitTwoObjectRoom
# 56 "data/scripts/battle_pike.pory"
	compare VAR_RESULT, PIKE_ROOM_HARD_BATTLE
# 57 "data/scripts/battle_pike.pory"
	goto_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_InitTwoObjectRoom
# 58 "data/scripts/battle_pike.pory"
	compare VAR_RESULT, PIKE_ROOM_DOUBLE_BATTLE
# 59 "data/scripts/battle_pike.pory"
	goto_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_InitTwoObjectRoom
# 60 "data/scripts/battle_pike.pory"
	compare VAR_RESULT, PIKE_ROOM_BRAIN
# 61 "data/scripts/battle_pike.pory"
	goto_if_eq BattleFrontier_BattlePikeRoomNormal_EventScript_InitBrainRoomObjects
# 62 "data/scripts/battle_pike.pory"
	hideobjectat LOCALID_OBJ_1, MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL
# 63 "data/scripts/battle_pike.pory"
	setvar VAR_TEMP_4, 1
# 64 "data/scripts/battle_pike.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 65 "data/scripts/battle_pike.pory"
	end
# 66 "data/scripts/battle_pike.pory"

# 67 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_InitTwoObjectRoom::
# 68 "data/scripts/battle_pike.pory"
	setvar VAR_TEMP_4, 1
# 69 "data/scripts/battle_pike.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 70 "data/scripts/battle_pike.pory"
	end
# 71 "data/scripts/battle_pike.pory"

# 72 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_InitBrainRoomObjects::
# 73 "data/scripts/battle_pike.pory"
	setvar VAR_TEMP_4, 1
# 74 "data/scripts/battle_pike.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 75 "data/scripts/battle_pike.pory"
	hideobjectat LOCALID_OBJ_0, MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL  @ Pike Queen hidden initially
# 76 "data/scripts/battle_pike.pory"
	end
# 77 "data/scripts/battle_pike.pory"

# 78 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_LeftRoomWarp::
# 79 "data/scripts/battle_pike.pory"
	setvar VAR_0x8007, PIKE_ROOM_LEFT
# 80 "data/scripts/battle_pike.pory"
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_RoomWarp
# 81 "data/scripts/battle_pike.pory"
	end
# 82 "data/scripts/battle_pike.pory"

# 83 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_CenterRoomWarp::
# 84 "data/scripts/battle_pike.pory"
	setvar VAR_0x8007, PIKE_ROOM_CENTER
# 85 "data/scripts/battle_pike.pory"
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_RoomWarp
# 86 "data/scripts/battle_pike.pory"
	end
# 87 "data/scripts/battle_pike.pory"

# 88 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_RightRoomWarp::
# 89 "data/scripts/battle_pike.pory"
	setvar VAR_0x8007, PIKE_ROOM_RIGHT
# 90 "data/scripts/battle_pike.pory"
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_RoomWarp
# 91 "data/scripts/battle_pike.pory"
	end
# 92 "data/scripts/battle_pike.pory"

# 93 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_RoomWarp::
# 94 "data/scripts/battle_pike.pory"
	pike_get PIKE_DATA_WIN_STREAK
# 95 "data/scripts/battle_pike.pory"
	addvar VAR_RESULT, 1
# 96 "data/scripts/battle_pike.pory"
	pike_set PIKE_DATA_WIN_STREAK, VAR_RESULT
# 97 "data/scripts/battle_pike.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 98 "data/scripts/battle_pike.pory"
	addvar VAR_RESULT, 1
# 99 "data/scripts/battle_pike.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 100 "data/scripts/battle_pike.pory"
	pike_setnextroom
# 101 "data/scripts/battle_pike.pory"
	pike_getroomtype
# 102 "data/scripts/battle_pike.pory"
	switch VAR_RESULT
# 103 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_SINGLE_BATTLE, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom
# 104 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_HEAL_FULL, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom
# 105 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_NPC, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom
# 106 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_STATUS, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom
# 107 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_HEAL_PART, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom
# 108 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_WILD_MONS, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpWildMonRoom
# 109 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_HARD_BATTLE, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom
# 110 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_DOUBLE_BATTLE, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom
# 111 "data/scripts/battle_pike.pory"
	case PIKE_ROOM_BRAIN, BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom
# 112 "data/scripts/battle_pike.pory"
	end
# 113 "data/scripts/battle_pike.pory"

# 114 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpNPCRoom::
# 115 "data/scripts/battle_pike.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoom_Movement_HidePlayer
# 116 "data/scripts/battle_pike.pory"
	waitmovement 0
# 117 "data/scripts/battle_pike.pory"
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
# 118 "data/scripts/battle_pike.pory"
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_NORMAL, 255, 4, 7
# 119 "data/scripts/battle_pike.pory"
	waitstate
# 120 "data/scripts/battle_pike.pory"
	end
# 121 "data/scripts/battle_pike.pory"

# 122 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_WarpWildMonRoom::
# 123 "data/scripts/battle_pike.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoom_Movement_HidePlayer
# 124 "data/scripts/battle_pike.pory"
	waitmovement 0
# 125 "data/scripts/battle_pike.pory"
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
# 126 "data/scripts/battle_pike.pory"
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS, 255, 4, 19
# 127 "data/scripts/battle_pike.pory"
	waitstate
# 128 "data/scripts/battle_pike.pory"
	end
# 129 "data/scripts/battle_pike.pory"

# 130 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_SetEnteredRoom::
# 131 "data/scripts/battle_pike.pory"
	setvar VAR_TEMP_3, 1
# 132 "data/scripts/battle_pike.pory"
	setvar VAR_TEMP_2, 1
# 133 "data/scripts/battle_pike.pory"
	end
# 134 "data/scripts/battle_pike.pory"

# 135 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_NoTurningBack::
# 136 "data/scripts/battle_pike.pory"
	setvar VAR_TEMP_3, 0
# 137 "data/scripts/battle_pike.pory"
	setvar VAR_TEMP_2, 0
# 138 "data/scripts/battle_pike.pory"
	lockall
# 139 "data/scripts/battle_pike.pory"
	msgbox BattleFrontier_BattlePike_Text_PathBlockedNoTurningBack, MSGBOX_DEFAULT
# 140 "data/scripts/battle_pike.pory"
	closemessage
# 141 "data/scripts/battle_pike.pory"
	end
# 142 "data/scripts/battle_pike.pory"

# 143 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_SetEnteredRoom::
# 144 "data/scripts/battle_pike.pory"
	setvar VAR_TEMP_3, 1
# 145 "data/scripts/battle_pike.pory"
	setvar VAR_TEMP_2, 1
# 146 "data/scripts/battle_pike.pory"
	end
# 147 "data/scripts/battle_pike.pory"

# 148 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_NoTurningBack::
# 149 "data/scripts/battle_pike.pory"
	setvar VAR_TEMP_3, 0
# 150 "data/scripts/battle_pike.pory"
	setvar VAR_TEMP_2, 0
# 151 "data/scripts/battle_pike.pory"
	lockall
# 152 "data/scripts/battle_pike.pory"
	msgbox BattleFrontier_BattlePike_Text_PathBlockedNoTurningBack, MSGBOX_DEFAULT
# 153 "data/scripts/battle_pike.pory"
	closemessage
# 154 "data/scripts/battle_pike.pory"
	end
# 155 "data/scripts/battle_pike.pory"

# 156 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoomNormal_EventScript_Exit::
# 157 "data/scripts/battle_pike.pory"
	pike_ispartyfullhealth
# 158 "data/scripts/battle_pike.pory"
	compare VAR_RESULT, TRUE
# 159 "data/scripts/battle_pike.pory"
	call_if_eq BattleFrontier_BattlePikeRoom_EventScript_DisableHealing
# 160 "data/scripts/battle_pike.pory"
	compare VAR_RESULT, TRUE
# 161 "data/scripts/battle_pike.pory"
	call_if_ne BattleFrontier_BattlePikeRoom_EventScript_EnableHealing
# 162 "data/scripts/battle_pike.pory"
	pike_get PIKE_DATA_WIN_STREAK
# 163 "data/scripts/battle_pike.pory"
	addvar VAR_RESULT, 1
# 164 "data/scripts/battle_pike.pory"
	pike_set PIKE_DATA_WIN_STREAK, VAR_RESULT
# 165 "data/scripts/battle_pike.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 166 "data/scripts/battle_pike.pory"
	addvar VAR_RESULT, 1
# 167 "data/scripts/battle_pike.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 168 "data/scripts/battle_pike.pory"
	pike_isfinalroom
# 169 "data/scripts/battle_pike.pory"
	compare VAR_RESULT, TRUE
# 170 "data/scripts/battle_pike.pory"
	call_if_eq BattleFrontier_BattlePikeRoom_EventScript_WarpToFinalRoom
# 171 "data/scripts/battle_pike.pory"
	compare VAR_RESULT, FALSE
# 172 "data/scripts/battle_pike.pory"
	call_if_eq BattleFrontier_BattlePikeRoom_EventScript_WarpToThreePathRoom
# 173 "data/scripts/battle_pike.pory"
	waitstate
# 174 "data/scripts/battle_pike.pory"
	end
# 175 "data/scripts/battle_pike.pory"

# 176 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoom_EventScript_DisableHealing::
# 177 "data/scripts/battle_pike.pory"
	pike_nohealing TRUE
# 178 "data/scripts/battle_pike.pory"
	return
# 179 "data/scripts/battle_pike.pory"

# 180 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoom_EventScript_EnableHealing::
# 181 "data/scripts/battle_pike.pory"
	pike_nohealing FALSE
# 182 "data/scripts/battle_pike.pory"
	return
# 183 "data/scripts/battle_pike.pory"

# 184 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoom_EventScript_WarpToFinalRoom::
# 185 "data/scripts/battle_pike.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoom_Movement_HidePlayer
# 186 "data/scripts/battle_pike.pory"
	waitmovement 0
# 187 "data/scripts/battle_pike.pory"
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
# 188 "data/scripts/battle_pike.pory"
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_FINAL, 255, 2, 7
# 189 "data/scripts/battle_pike.pory"
	return
# 190 "data/scripts/battle_pike.pory"

# 191 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoom_EventScript_WarpToThreePathRoom::
# 192 "data/scripts/battle_pike.pory"
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeRoom_Movement_HidePlayer
# 193 "data/scripts/battle_pike.pory"
	waitmovement 0
# 194 "data/scripts/battle_pike.pory"
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
# 195 "data/scripts/battle_pike.pory"
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_THREE_PATH_ROOM, 255, 6, 10
# 196 "data/scripts/battle_pike.pory"
	return
# 197 "data/scripts/battle_pike.pory"

# 198 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoomWildMons_EventScript_Exit::
# 199 "data/scripts/battle_pike.pory"
	pike_exitwildmonroom
# 200 "data/scripts/battle_pike.pory"
	pike_ispartyfullhealth
# 201 "data/scripts/battle_pike.pory"
	compare VAR_RESULT, TRUE
# 202 "data/scripts/battle_pike.pory"
	call_if_eq BattleFrontier_BattlePikeRoom_EventScript_DisableHealing
# 203 "data/scripts/battle_pike.pory"
	compare VAR_RESULT, TRUE
# 204 "data/scripts/battle_pike.pory"
	call_if_ne BattleFrontier_BattlePikeRoom_EventScript_EnableHealing
# 205 "data/scripts/battle_pike.pory"
	pike_get PIKE_DATA_WIN_STREAK
# 206 "data/scripts/battle_pike.pory"
	addvar VAR_RESULT, 1
# 207 "data/scripts/battle_pike.pory"
	pike_set PIKE_DATA_WIN_STREAK, VAR_RESULT
# 208 "data/scripts/battle_pike.pory"
	frontier_get FRONTIER_DATA_BATTLE_NUM
# 209 "data/scripts/battle_pike.pory"
	addvar VAR_RESULT, 1
# 210 "data/scripts/battle_pike.pory"
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
# 211 "data/scripts/battle_pike.pory"
	pike_isfinalroom
# 212 "data/scripts/battle_pike.pory"
	compare VAR_RESULT, TRUE
# 213 "data/scripts/battle_pike.pory"
	call_if_eq BattleFrontier_BattlePikeRoom_EventScript_WarpToFinalRoom
# 214 "data/scripts/battle_pike.pory"
	compare VAR_RESULT, FALSE
# 215 "data/scripts/battle_pike.pory"
	call_if_eq BattleFrontier_BattlePikeRoom_EventScript_WarpToThreePathRoom
# 216 "data/scripts/battle_pike.pory"
	waitstate
# 217 "data/scripts/battle_pike.pory"
	end
# 218 "data/scripts/battle_pike.pory"

# 219 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoomWildMons_EventScript_SetEnteredRoom::
# 220 "data/scripts/battle_pike.pory"
	setvar VAR_TEMP_3, 1
# 221 "data/scripts/battle_pike.pory"
	setvar VAR_TEMP_2, 1
# 222 "data/scripts/battle_pike.pory"
	end
# 223 "data/scripts/battle_pike.pory"

# 224 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoomWildMons_EventScript_NoTurningBack::
# 225 "data/scripts/battle_pike.pory"
	setvar VAR_TEMP_3, 0
# 226 "data/scripts/battle_pike.pory"
	setvar VAR_TEMP_2, 0
# 227 "data/scripts/battle_pike.pory"
	lockall
# 228 "data/scripts/battle_pike.pory"
	msgbox BattleFrontier_BattlePike_Text_PathBlockedNoTurningBack, MSGBOX_DEFAULT
# 229 "data/scripts/battle_pike.pory"
	closemessage
# 230 "data/scripts/battle_pike.pory"
	end
# 231 "data/scripts/battle_pike.pory"

# 232 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePike_EventScript_Retire::
# 233 "data/scripts/battle_pike.pory"
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS CHALLENGE_STATUS_LOST
# 234 "data/scripts/battle_pike.pory"
	warp MAP_BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 255, 5, 6
# 235 "data/scripts/battle_pike.pory"
	waitstate
# 236 "data/scripts/battle_pike.pory"
	end
# 237 "data/scripts/battle_pike.pory"

# 238 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoom_OnResume:
# 239 "data/scripts/battle_pike.pory"
	setorcopyvar VAR_0x8006, VAR_RESULT  @ Save VAR_RESULT from being overwritten
# 240 "data/scripts/battle_pike.pory"
	frontier_get FRONTIER_DATA_CHALLENGE_STATUS
# 241 "data/scripts/battle_pike.pory"
	compare VAR_RESULT, CHALLENGE_STATUS_PAUSED
# 242 "data/scripts/battle_pike.pory"
	goto_if_eq BattleFrontier_BattlePikeThreePathRoom_EventScript_EndOnResume
# 243 "data/scripts/battle_pike.pory"
	compare VAR_RESULT, CHALLENGE_STATUS_SAVING
# 244 "data/scripts/battle_pike.pory"
	goto_if_eq BattleFrontier_BattlePikeThreePathRoom_EventScript_EndOnResume
# 245 "data/scripts/battle_pike.pory"
	call BattleFrontier_BattlePikeRoom_EventScript_ResetSketchedMoves
# 246 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeThreePathRoom_EventScript_EndOnResume::
# 247 "data/scripts/battle_pike.pory"
	setorcopyvar VAR_RESULT, VAR_0x8006
# 248 "data/scripts/battle_pike.pory"
	end
# 249 "data/scripts/battle_pike.pory"

# 250 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoom_EventScript_ResetSketchedMoves::
# 251 "data/scripts/battle_pike.pory"
	frontier_resetsketch
# 252 "data/scripts/battle_pike.pory"
	return
# 253 "data/scripts/battle_pike.pory"

# 254 "data/scripts/battle_pike.pory"
BattleFrontier_BattlePikeRoom_Movement_HidePlayer:
# 255 "data/scripts/battle_pike.pory"
	set_invisible
# 256 "data/scripts/battle_pike.pory"
	step_end
