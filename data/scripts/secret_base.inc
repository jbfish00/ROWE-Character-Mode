# 1 "data/scripts/secret_base.pory"

# 2 "data/scripts/secret_base.pory"
SecretBase_Text_TreeCanBeClimbed: @ 8274746
# 3 "data/scripts/secret_base.pory"
	.string "If some vines drop down, this tree can\n"
# 4 "data/scripts/secret_base.pory"
	.string "be climbed.$"
# 5 "data/scripts/secret_base.pory"

# 6 "data/scripts/secret_base.pory"
SecretBase_Text_TreeUseSecretPower: @ 8274779
# 7 "data/scripts/secret_base.pory"
	.string "If some vines drop down, this tree can\n"
# 8 "data/scripts/secret_base.pory"
	.string "be climbed.\p"
# 9 "data/scripts/secret_base.pory"
	.string "Use the Secret Power?$"
# 10 "data/scripts/secret_base.pory"

# 11 "data/scripts/secret_base.pory"
SecretBase_Text_VineDroppedDown: @ 82747C2
# 12 "data/scripts/secret_base.pory"
	.string "A thick vine dropped down!$"
# 13 "data/scripts/secret_base.pory"

# 14 "data/scripts/secret_base.pory"
SecretBase_Text_ClumpOfGrass: @ 82747DD
# 15 "data/scripts/secret_base.pory"
	.string "If this clump of grass can be moved,\n"
# 16 "data/scripts/secret_base.pory"
	.string "it might be possible to go inside.$"
# 17 "data/scripts/secret_base.pory"

# 18 "data/scripts/secret_base.pory"
SecretBase_Text_ClumpUseSecretPower: @ 8274825
# 19 "data/scripts/secret_base.pory"
	.string "If this clump of grass can be moved,\n"
# 20 "data/scripts/secret_base.pory"
	.string "it might be possible to go inside.\p"
# 21 "data/scripts/secret_base.pory"
	.string "Use the Secret Power?$"
# 22 "data/scripts/secret_base.pory"

# 23 "data/scripts/secret_base.pory"
SecretBase_Text_DiscoveredSmallEntrance: @ 8274883
# 24 "data/scripts/secret_base.pory"
	.string "Discovered a small entrance!$"
# 25 "data/scripts/secret_base.pory"

# 26 "data/scripts/secret_base.pory"
	.include "data/text/secret_base_trainers.inc"
# 27 "data/scripts/secret_base.pory"

# 28 "data/scripts/secret_base.pory"
SecretBase_EventScript_CheckEntrance:: @ 82759F1
# 29 "data/scripts/secret_base.pory"
	special GetSecretBaseTypeInFrontOfPlayer
# 30 "data/scripts/secret_base.pory"
	special CheckPlayerHasSecretBase
# 31 "data/scripts/secret_base.pory"
	compare VAR_RESULT, TRUE
# 32 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_AlreadyHasSecretBase
# 33 "data/scripts/secret_base.pory"
	checkpartymove MOVE_SECRET_POWER
# 34 "data/scripts/secret_base.pory"
	setfieldeffectargument 0, VAR_RESULT
# 35 "data/scripts/secret_base.pory"
	buffermovename 1, MOVE_SECRET_POWER
# 36 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_RED_CAVE
# 37 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Cave
# 38 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_BROWN_CAVE
# 39 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Cave
# 40 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_BLUE_CAVE
# 41 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Cave
# 42 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_YELLOW_CAVE
# 43 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Cave
# 44 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_TREE
# 45 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Tree
# 46 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_SHRUB
# 47 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Shrub
# 48 "data/scripts/secret_base.pory"
	end
# 49 "data/scripts/secret_base.pory"

# 50 "data/scripts/secret_base.pory"
SecretBase_EventScript_Cave:: @ 8275A50
# 51 "data/scripts/secret_base.pory"
	lockall
# 52 "data/scripts/secret_base.pory"
	compare VAR_RESULT, PARTY_SIZE
# 53 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_CaveNoSecretPower
# 54 "data/scripts/secret_base.pory"
	bufferpartymonnick 0, VAR_RESULT
# 55 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_IndentUseSecretPower, MSGBOX_YESNO
# 56 "data/scripts/secret_base.pory"
	compare VAR_RESULT, NO
# 57 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_CancelOnEntrance
# 58 "data/scripts/secret_base.pory"
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
# 59 "data/scripts/secret_base.pory"
	closemessage
# 60 "data/scripts/secret_base.pory"
	dofieldeffect FLDEFF_USE_SECRET_POWER_CAVE
# 61 "data/scripts/secret_base.pory"
	waitstate
# 62 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_CaveEnter
# 63 "data/scripts/secret_base.pory"
	end
# 64 "data/scripts/secret_base.pory"

# 65 "data/scripts/secret_base.pory"
SecretBase_EventScript_CaveUseSecretPower:: @ 8275A86
# 66 "data/scripts/secret_base.pory"
	lockall
# 67 "data/scripts/secret_base.pory"
	dofieldeffect FLDEFF_USE_SECRET_POWER_CAVE
# 68 "data/scripts/secret_base.pory"
	waitstate
# 69 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_CaveEnter
# 70 "data/scripts/secret_base.pory"
	end
# 71 "data/scripts/secret_base.pory"

# 72 "data/scripts/secret_base.pory"
SecretBase_EventScript_CaveNoSecretPower:: @ 8275A91
# 73 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_SmallIndentInWall, MSGBOX_DEFAULT
# 74 "data/scripts/secret_base.pory"
	releaseall
# 75 "data/scripts/secret_base.pory"
	end
# 76 "data/scripts/secret_base.pory"

# 77 "data/scripts/secret_base.pory"
SecretBase_EventScript_CaveEnter:: @ 8275A9B
# 78 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_DiscoveredSmallCavern, MSGBOX_DEFAULT
# 79 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_InitSecretBase
# 80 "data/scripts/secret_base.pory"
	end
# 81 "data/scripts/secret_base.pory"

# 82 "data/scripts/secret_base.pory"
SecretBase_EventScript_Tree:: @ 8275AA9
# 83 "data/scripts/secret_base.pory"
	lockall
# 84 "data/scripts/secret_base.pory"
	compare VAR_RESULT, PARTY_SIZE
# 85 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_TreeNoSecretPower
# 86 "data/scripts/secret_base.pory"
	bufferpartymonnick 0, VAR_RESULT
# 87 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_TreeUseSecretPower, MSGBOX_YESNO
# 88 "data/scripts/secret_base.pory"
	compare VAR_RESULT, NO
# 89 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_CancelOnEntrance
# 90 "data/scripts/secret_base.pory"
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
# 91 "data/scripts/secret_base.pory"
	closemessage
# 92 "data/scripts/secret_base.pory"
	dofieldeffect FLDEFF_USE_SECRET_POWER_TREE
# 93 "data/scripts/secret_base.pory"
	waitstate
# 94 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_TreeEnter
# 95 "data/scripts/secret_base.pory"
	end
# 96 "data/scripts/secret_base.pory"

# 97 "data/scripts/secret_base.pory"
SecretBase_EventScript_TreeUseSecretPower:: @ 8275ADF
# 98 "data/scripts/secret_base.pory"
	lockall
# 99 "data/scripts/secret_base.pory"
	dofieldeffect FLDEFF_USE_SECRET_POWER_TREE
# 100 "data/scripts/secret_base.pory"
	waitstate
# 101 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_TreeEnter
# 102 "data/scripts/secret_base.pory"
	end
# 103 "data/scripts/secret_base.pory"

# 104 "data/scripts/secret_base.pory"
SecretBase_EventScript_TreeNoSecretPower:: @ 8275AEA
# 105 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_TreeCanBeClimbed, MSGBOX_DEFAULT
# 106 "data/scripts/secret_base.pory"
	releaseall
# 107 "data/scripts/secret_base.pory"
	end
# 108 "data/scripts/secret_base.pory"

# 109 "data/scripts/secret_base.pory"
SecretBase_EventScript_TreeEnter:: @ 8275AF4
# 110 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_VineDroppedDown, MSGBOX_DEFAULT
# 111 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_InitSecretBase
# 112 "data/scripts/secret_base.pory"
	end
# 113 "data/scripts/secret_base.pory"

# 114 "data/scripts/secret_base.pory"
SecretBase_EventScript_Shrub:: @ 8275B02
# 115 "data/scripts/secret_base.pory"
	lockall
# 116 "data/scripts/secret_base.pory"
	compare VAR_RESULT, PARTY_SIZE
# 117 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_ShrubNoSecretPower
# 118 "data/scripts/secret_base.pory"
	bufferpartymonnick 0, VAR_RESULT
# 119 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_ClumpUseSecretPower, MSGBOX_YESNO
# 120 "data/scripts/secret_base.pory"
	compare VAR_RESULT, NO
# 121 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_CancelOnEntrance
# 122 "data/scripts/secret_base.pory"
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
# 123 "data/scripts/secret_base.pory"
	closemessage
# 124 "data/scripts/secret_base.pory"
	dofieldeffect FLDEFF_USE_SECRET_POWER_SHRUB
# 125 "data/scripts/secret_base.pory"
	waitstate
# 126 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_ShrubEnter
# 127 "data/scripts/secret_base.pory"
	end
# 128 "data/scripts/secret_base.pory"

# 129 "data/scripts/secret_base.pory"
SecretBase_EventScript_ShrubUseSecretPower:: @ 8275B38
# 130 "data/scripts/secret_base.pory"
	lockall
# 131 "data/scripts/secret_base.pory"
	dofieldeffect FLDEFF_USE_SECRET_POWER_SHRUB
# 132 "data/scripts/secret_base.pory"
	waitstate
# 133 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_ShrubEnter
# 134 "data/scripts/secret_base.pory"
	end
# 135 "data/scripts/secret_base.pory"

# 136 "data/scripts/secret_base.pory"
SecretBase_EventScript_ShrubNoSecretPower:: @ 8275B43
# 137 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_ClumpOfGrass, MSGBOX_DEFAULT
# 138 "data/scripts/secret_base.pory"
	releaseall
# 139 "data/scripts/secret_base.pory"
	end
# 140 "data/scripts/secret_base.pory"

# 141 "data/scripts/secret_base.pory"
SecretBase_EventScript_ShrubEnter:: @ 8275B4D
# 142 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_DiscoveredSmallEntrance, MSGBOX_DEFAULT
# 143 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_InitSecretBase
# 144 "data/scripts/secret_base.pory"
	end
# 145 "data/scripts/secret_base.pory"

# 146 "data/scripts/secret_base.pory"
SecretBase_EventScript_InitSecretBase:: @ 8275B5B
# 147 "data/scripts/secret_base.pory"
	closemessage
# 148 "data/scripts/secret_base.pory"
	playse SE_EXIT
# 149 "data/scripts/secret_base.pory"
	setvar VAR_INIT_SECRET_BASE, 0
# 150 "data/scripts/secret_base.pory"
	setflag FLAG_DECORATION_0
# 151 "data/scripts/secret_base.pory"
	special SetPlayerSecretBase
# 152 "data/scripts/secret_base.pory"
	special EnterSecretBase
# 153 "data/scripts/secret_base.pory"
	setvar VAR_0x8004, 0
# 154 "data/scripts/secret_base.pory"
	setvar VAR_0x8005, 0
# 155 "data/scripts/secret_base.pory"
	special InitSecretBaseDecorationSprites
# 156 "data/scripts/secret_base.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 1
# 157 "data/scripts/secret_base.pory"
	waitstate
# 158 "data/scripts/secret_base.pory"
	end
# 159 "data/scripts/secret_base.pory"

# 160 "data/scripts/secret_base.pory"
SecretBase_EventScript_FirstEntrance:: @ 8275B81
# 161 "data/scripts/secret_base.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SecretBase_Movement_275BB4
# 162 "data/scripts/secret_base.pory"
	waitmovement 0
# 163 "data/scripts/secret_base.pory"
	setvar VAR_INIT_SECRET_BASE, 1
# 164 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_WantToMakeYourSecretBaseHere, MSGBOX_YESNO
# 165 "data/scripts/secret_base.pory"
	compare VAR_RESULT, YES
# 166 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_SetAsBase
# 167 "data/scripts/secret_base.pory"
	closemessage
# 168 "data/scripts/secret_base.pory"
	playse SE_EXIT
# 169 "data/scripts/secret_base.pory"
	special ClearAndLeaveSecretBase
# 170 "data/scripts/secret_base.pory"
	end
# 171 "data/scripts/secret_base.pory"

# 172 "data/scripts/secret_base.pory"
SecretBase_EventScript_SetAsBase:: @ 8275BAB
# 173 "data/scripts/secret_base.pory"
	closemessage
# 174 "data/scripts/secret_base.pory"
	setflag FLAG_RECEIVED_SECRET_POWER
# 175 "data/scripts/secret_base.pory"
	special EnterNewlyCreatedSecretBase
# 176 "data/scripts/secret_base.pory"
	waitstate
# 177 "data/scripts/secret_base.pory"
	end
# 178 "data/scripts/secret_base.pory"

# 179 "data/scripts/secret_base.pory"
SecretBase_Movement_275BB4: @ 8275BB4
# 180 "data/scripts/secret_base.pory"
	walk_up
# 181 "data/scripts/secret_base.pory"
	walk_up
# 182 "data/scripts/secret_base.pory"
	step_end
# 183 "data/scripts/secret_base.pory"

# 184 "data/scripts/secret_base.pory"
SecretBase_EventScript_Enter:: @ 8275BB7
# 185 "data/scripts/secret_base.pory"
	lockall
# 186 "data/scripts/secret_base.pory"
	setvar VAR_INIT_SECRET_BASE, 1
# 187 "data/scripts/secret_base.pory"
	playse SE_EXIT
# 188 "data/scripts/secret_base.pory"
	special IsCurSecretBaseOwnedByAnotherPlayer
# 189 "data/scripts/secret_base.pory"
	compare VAR_RESULT, FALSE
# 190 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_EnterPlayersBase
# 191 "data/scripts/secret_base.pory"
	clearflag FLAG_DECORATION_0
# 192 "data/scripts/secret_base.pory"
	special EnterSecretBase
# 193 "data/scripts/secret_base.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
# 194 "data/scripts/secret_base.pory"
	waitstate
# 195 "data/scripts/secret_base.pory"
	end
# 196 "data/scripts/secret_base.pory"

# 197 "data/scripts/secret_base.pory"
SecretBase_EventScript_EnterPlayersBase:: @ 8275BDB
# 198 "data/scripts/secret_base.pory"
	setflag FLAG_DECORATION_0
# 199 "data/scripts/secret_base.pory"
	special EnterSecretBase
# 200 "data/scripts/secret_base.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
# 201 "data/scripts/secret_base.pory"
	waitstate
# 202 "data/scripts/secret_base.pory"
	end
# 203 "data/scripts/secret_base.pory"

# 204 "data/scripts/secret_base.pory"
SecretBase_EventScript_AlreadyHasSecretBase:: @ 8275BE8
# 205 "data/scripts/secret_base.pory"
	checkpartymove MOVE_SECRET_POWER
# 206 "data/scripts/secret_base.pory"
	compare VAR_RESULT, PARTY_SIZE
# 207 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_NoSecretPower
# 208 "data/scripts/secret_base.pory"
	setfieldeffectargument 0, VAR_RESULT
# 209 "data/scripts/secret_base.pory"
	setorcopyvar VAR_0x8004, VAR_RESULT
# 210 "data/scripts/secret_base.pory"
	lockall
# 211 "data/scripts/secret_base.pory"
	special GetSecretBaseNearbyMapName
# 212 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_WouldYouLikeToMoveBases, MSGBOX_YESNO
# 213 "data/scripts/secret_base.pory"
	compare VAR_RESULT, NO
# 214 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_CancelOnEntrance
# 215 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_AllDecorationsWillBeReturned, MSGBOX_YESNO
# 216 "data/scripts/secret_base.pory"
	compare VAR_RESULT, NO
# 217 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_CancelOnEntrance
# 218 "data/scripts/secret_base.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 219 "data/scripts/secret_base.pory"
	special MoveOutOfSecretBaseFromOutside
# 220 "data/scripts/secret_base.pory"
	closemessage
# 221 "data/scripts/secret_base.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 222 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_MovingCompletedUseSecretPower, MSGBOX_YESNO
# 223 "data/scripts/secret_base.pory"
	compare VAR_RESULT, NO
# 224 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_CancelOnEntrance
# 225 "data/scripts/secret_base.pory"
	bufferpartymonnick 0, VAR_0x8004
# 226 "data/scripts/secret_base.pory"
	buffermovename 1, MOVE_SECRET_POWER
# 227 "data/scripts/secret_base.pory"
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
# 228 "data/scripts/secret_base.pory"
	closemessage
# 229 "data/scripts/secret_base.pory"
	closemessage
# 230 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_RED_CAVE
# 231 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_CaveUseSecretPower
# 232 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_BROWN_CAVE
# 233 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_CaveUseSecretPower
# 234 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_BLUE_CAVE
# 235 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_CaveUseSecretPower
# 236 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_YELLOW_CAVE
# 237 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_CaveUseSecretPower
# 238 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_TREE
# 239 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_TreeUseSecretPower
# 240 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_SHRUB
# 241 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_ShrubUseSecretPower
# 242 "data/scripts/secret_base.pory"
	releaseall
# 243 "data/scripts/secret_base.pory"
	end
# 244 "data/scripts/secret_base.pory"

# 245 "data/scripts/secret_base.pory"
SecretBase_EventScript_NoSecretPower:: @ 8275C9A
# 246 "data/scripts/secret_base.pory"
	lockall
# 247 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_RED_CAVE
# 248 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_CaveNoSecretPower
# 249 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_BROWN_CAVE
# 250 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_CaveNoSecretPower
# 251 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_BLUE_CAVE
# 252 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_CaveNoSecretPower
# 253 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_YELLOW_CAVE
# 254 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_CaveNoSecretPower
# 255 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_TREE
# 256 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_TreeNoSecretPower
# 257 "data/scripts/secret_base.pory"
	compare VAR_0x8007, SECRET_BASE_SHRUB
# 258 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_ShrubNoSecretPower
# 259 "data/scripts/secret_base.pory"
	end
# 260 "data/scripts/secret_base.pory"

# 261 "data/scripts/secret_base.pory"
SecretBase_EventScript_CancelOnEntrance:: @ 8275CDE
# 262 "data/scripts/secret_base.pory"
	closemessage
# 263 "data/scripts/secret_base.pory"
	releaseall
# 264 "data/scripts/secret_base.pory"
	end
# 265 "data/scripts/secret_base.pory"

# 266 "data/scripts/secret_base.pory"
SecretBase_EventScript_SetDecorationFlags:: @ 8275CE1
# 267 "data/scripts/secret_base.pory"
	setflag FLAG_DECORATION_1
# 268 "data/scripts/secret_base.pory"
	setflag FLAG_DECORATION_2
# 269 "data/scripts/secret_base.pory"
	setflag FLAG_DECORATION_3
# 270 "data/scripts/secret_base.pory"
	setflag FLAG_DECORATION_4
# 271 "data/scripts/secret_base.pory"
	setflag FLAG_DECORATION_5
# 272 "data/scripts/secret_base.pory"
	setflag FLAG_DECORATION_6
# 273 "data/scripts/secret_base.pory"
	setflag FLAG_DECORATION_7
# 274 "data/scripts/secret_base.pory"
	setflag FLAG_DECORATION_8
# 275 "data/scripts/secret_base.pory"
	setflag FLAG_DECORATION_9
# 276 "data/scripts/secret_base.pory"
	setflag FLAG_DECORATION_10
# 277 "data/scripts/secret_base.pory"
	setflag FLAG_DECORATION_11
# 278 "data/scripts/secret_base.pory"
	setflag FLAG_DECORATION_12
# 279 "data/scripts/secret_base.pory"
	setflag FLAG_DECORATION_13
# 280 "data/scripts/secret_base.pory"
	setflag FLAG_DECORATION_14
# 281 "data/scripts/secret_base.pory"
	return
# 282 "data/scripts/secret_base.pory"

# 283 "data/scripts/secret_base.pory"
SecretBase_EventScript_InitDecorations:: @ 8275D0C
# 284 "data/scripts/secret_base.pory"
	setvar VAR_0x8004, 0
# 285 "data/scripts/secret_base.pory"
	setvar VAR_0x8005, 0
# 286 "data/scripts/secret_base.pory"
	special InitSecretBaseDecorationSprites
# 287 "data/scripts/secret_base.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 1
# 288 "data/scripts/secret_base.pory"
	end
# 289 "data/scripts/secret_base.pory"

# 290 "data/scripts/secret_base.pory"
SecretBase_EventScript_SetDecoration:: @ 8275D1F
# 291 "data/scripts/secret_base.pory"
	setvar VAR_0x8005, 0
# 292 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_SetDecoration2
# 293 "data/scripts/secret_base.pory"
	end
# 294 "data/scripts/secret_base.pory"

# 295 "data/scripts/secret_base.pory"
SecretBase_EventScript_SetDecoration2:: @ 8275D2A
# 296 "data/scripts/secret_base.pory"
	special SetDecoration
# 297 "data/scripts/secret_base.pory"
	end
# 298 "data/scripts/secret_base.pory"

# 299 "data/scripts/secret_base.pory"
SecretBase_EventScript_PutAwayDecoration:: @ 8275D2E
# 300 "data/scripts/secret_base.pory"
	setvar VAR_0x8004, 0
# 301 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_PutAwayDecorationLoop
# 302 "data/scripts/secret_base.pory"
	end
# 303 "data/scripts/secret_base.pory"

# 304 "data/scripts/secret_base.pory"
SecretBase_EventScript_PutAwayDecorationLoop:: @ 8275D39
# 305 "data/scripts/secret_base.pory"
	special PutAwayDecorationIteration
# 306 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 1
# 307 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_PutAwayDecorationEnd
# 308 "data/scripts/secret_base.pory"
	addvar VAR_0x8004, 1
# 309 "data/scripts/secret_base.pory"
	compare VAR_0x8005, 0
# 310 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_PutAwayDecorationLoop
# 311 "data/scripts/secret_base.pory"
	removeobject VAR_0x8006
# 312 "data/scripts/secret_base.pory"
	setflag VAR_0x8005  @ UB: VAR_0x8005 is set to a flag by PutAwayDecorationIteration, but ScrCmd_setflag doesn't use VarGet
# 313 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_PutAwayDecorationLoop
# 314 "data/scripts/secret_base.pory"
	end
# 315 "data/scripts/secret_base.pory"

# 316 "data/scripts/secret_base.pory"
SecretBase_EventScript_PutAwayDecorationEnd:: @ 8275D63
# 317 "data/scripts/secret_base.pory"
	end
# 318 "data/scripts/secret_base.pory"

# 319 "data/scripts/secret_base.pory"
SecretBase_EventScript_RecordMixTrainer:: @ 8275D64
# 320 "data/scripts/secret_base.pory"
	special GetSecretBaseOwnerAndState
# 321 "data/scripts/secret_base.pory"
	compare VAR_0x8004, 0
# 322 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer0
# 323 "data/scripts/secret_base.pory"
	compare VAR_0x8004, 1
# 324 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer1
# 325 "data/scripts/secret_base.pory"
	compare VAR_0x8004, 2
# 326 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer2
# 327 "data/scripts/secret_base.pory"
	compare VAR_0x8004, 3
# 328 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer3
# 329 "data/scripts/secret_base.pory"
	compare VAR_0x8004, 4
# 330 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer4
# 331 "data/scripts/secret_base.pory"
	compare VAR_0x8004, 5
# 332 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer5
# 333 "data/scripts/secret_base.pory"
	compare VAR_0x8004, 6
# 334 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer6
# 335 "data/scripts/secret_base.pory"
	compare VAR_0x8004, 7
# 336 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer7
# 337 "data/scripts/secret_base.pory"
	compare VAR_0x8004, 8
# 338 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer8
# 339 "data/scripts/secret_base.pory"
	compare VAR_0x8004, 9
# 340 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer9
# 341 "data/scripts/secret_base.pory"
	end
# 342 "data/scripts/secret_base.pory"

# 343 "data/scripts/secret_base.pory"
@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
# 344 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer0:: @ 8275DD6
# 345 "data/scripts/secret_base.pory"
	lock
# 346 "data/scripts/secret_base.pory"
	faceplayer
# 347 "data/scripts/secret_base.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer0PreChampion
# 348 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 1
# 349 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer0PostBattle
# 350 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer0Intro, MSGBOX_YESNO
# 351 "data/scripts/secret_base.pory"
	compare VAR_RESULT, NO
# 352 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer0DeclineBattle
# 353 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 1
# 354 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 355 "data/scripts/secret_base.pory"
	call Common_EventScript_SaveGame
# 356 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 0
# 357 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer0DeclineBattle
# 358 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer0AcceptBattle, MSGBOX_DEFAULT
# 359 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_BattleTrainer
# 360 "data/scripts/secret_base.pory"
	end
# 361 "data/scripts/secret_base.pory"

# 362 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer0PreChampion:: @ 8275E25
# 363 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer0PreChampion, MSGBOX_DEFAULT
# 364 "data/scripts/secret_base.pory"
	release
# 365 "data/scripts/secret_base.pory"
	end
# 366 "data/scripts/secret_base.pory"

# 367 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer0DeclineBattle:: @ 8275E2F
# 368 "data/scripts/secret_base.pory"
	special DeclinedSecretBaseBattle
# 369 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 0
# 370 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 371 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer0DeclineBattle, MSGBOX_DEFAULT
# 372 "data/scripts/secret_base.pory"
	release
# 373 "data/scripts/secret_base.pory"
	end
# 374 "data/scripts/secret_base.pory"

# 375 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer0PostBattle:: @ 8275E44
# 376 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer0PostBattle, MSGBOX_DEFAULT
# 377 "data/scripts/secret_base.pory"
	release
# 378 "data/scripts/secret_base.pory"
	end
# 379 "data/scripts/secret_base.pory"

# 380 "data/scripts/secret_base.pory"
@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
# 381 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer1:: @ 8275E4E
# 382 "data/scripts/secret_base.pory"
	lock
# 383 "data/scripts/secret_base.pory"
	faceplayer
# 384 "data/scripts/secret_base.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer1PreChampion
# 385 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 1
# 386 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer1PostBattle
# 387 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer1Intro, MSGBOX_YESNO
# 388 "data/scripts/secret_base.pory"
	compare VAR_RESULT, NO
# 389 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer1DeclineBattle
# 390 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 1
# 391 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 392 "data/scripts/secret_base.pory"
	call Common_EventScript_SaveGame
# 393 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 0
# 394 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer1DeclineBattle
# 395 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer1AcceptBattle, MSGBOX_DEFAULT
# 396 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_BattleTrainer
# 397 "data/scripts/secret_base.pory"
	end
# 398 "data/scripts/secret_base.pory"

# 399 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer1PreChampion:: @ 8275E9D
# 400 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer1PreChampion, MSGBOX_DEFAULT
# 401 "data/scripts/secret_base.pory"
	release
# 402 "data/scripts/secret_base.pory"
	end
# 403 "data/scripts/secret_base.pory"

# 404 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer1DeclineBattle:: @ 8275EA7
# 405 "data/scripts/secret_base.pory"
	special DeclinedSecretBaseBattle
# 406 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 0
# 407 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 408 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer1DeclineBattle, MSGBOX_DEFAULT
# 409 "data/scripts/secret_base.pory"
	release
# 410 "data/scripts/secret_base.pory"
	end
# 411 "data/scripts/secret_base.pory"

# 412 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer1PostBattle:: @ 8275EBC
# 413 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer1PostBattle, MSGBOX_DEFAULT
# 414 "data/scripts/secret_base.pory"
	release
# 415 "data/scripts/secret_base.pory"
	end
# 416 "data/scripts/secret_base.pory"

# 417 "data/scripts/secret_base.pory"
@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
# 418 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer2:: @ 8275EC6
# 419 "data/scripts/secret_base.pory"
	lock
# 420 "data/scripts/secret_base.pory"
	faceplayer
# 421 "data/scripts/secret_base.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer2PreChampion
# 422 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 1
# 423 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer2PostBattle
# 424 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer2Intro, MSGBOX_YESNO
# 425 "data/scripts/secret_base.pory"
	compare VAR_RESULT, NO
# 426 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer2DeclineBattle
# 427 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 1
# 428 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 429 "data/scripts/secret_base.pory"
	call Common_EventScript_SaveGame
# 430 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 0
# 431 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer2DeclineBattle
# 432 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer2AcceptBattle, MSGBOX_DEFAULT
# 433 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_BattleTrainer
# 434 "data/scripts/secret_base.pory"
	end
# 435 "data/scripts/secret_base.pory"

# 436 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer2PreChampion:: @ 8275F15
# 437 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer2PreChampion, MSGBOX_DEFAULT
# 438 "data/scripts/secret_base.pory"
	release
# 439 "data/scripts/secret_base.pory"
	end
# 440 "data/scripts/secret_base.pory"

# 441 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer2DeclineBattle:: @ 8275F1F
# 442 "data/scripts/secret_base.pory"
	special DeclinedSecretBaseBattle
# 443 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 0
# 444 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 445 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer2DeclineBattle, MSGBOX_DEFAULT
# 446 "data/scripts/secret_base.pory"
	release
# 447 "data/scripts/secret_base.pory"
	end
# 448 "data/scripts/secret_base.pory"

# 449 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer2PostBattle:: @ 8275F34
# 450 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer2PostBattle, MSGBOX_DEFAULT
# 451 "data/scripts/secret_base.pory"
	release
# 452 "data/scripts/secret_base.pory"
	end
# 453 "data/scripts/secret_base.pory"

# 454 "data/scripts/secret_base.pory"
@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
# 455 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer3:: @ 8275F3E
# 456 "data/scripts/secret_base.pory"
	lock
# 457 "data/scripts/secret_base.pory"
	faceplayer
# 458 "data/scripts/secret_base.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer3PreChampion
# 459 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 1
# 460 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer3PostBattle
# 461 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer3Intro, MSGBOX_YESNO
# 462 "data/scripts/secret_base.pory"
	compare VAR_RESULT, NO
# 463 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer3DeclineBattle
# 464 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 1
# 465 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 466 "data/scripts/secret_base.pory"
	call Common_EventScript_SaveGame
# 467 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 0
# 468 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer3DeclineBattle
# 469 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer3AcceptBattle, MSGBOX_DEFAULT
# 470 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_BattleTrainer
# 471 "data/scripts/secret_base.pory"
	end
# 472 "data/scripts/secret_base.pory"

# 473 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer3PreChampion:: @ 8275F8D
# 474 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer3PreChampion, MSGBOX_DEFAULT
# 475 "data/scripts/secret_base.pory"
	release
# 476 "data/scripts/secret_base.pory"
	end
# 477 "data/scripts/secret_base.pory"

# 478 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer3DeclineBattle:: @ 8275F97
# 479 "data/scripts/secret_base.pory"
	special DeclinedSecretBaseBattle
# 480 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 0
# 481 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 482 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer3DeclineBattle, MSGBOX_DEFAULT
# 483 "data/scripts/secret_base.pory"
	release
# 484 "data/scripts/secret_base.pory"
	end
# 485 "data/scripts/secret_base.pory"

# 486 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer3PostBattle:: @ 8275FAC
# 487 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer3PostBattle, MSGBOX_DEFAULT
# 488 "data/scripts/secret_base.pory"
	release
# 489 "data/scripts/secret_base.pory"
	end
# 490 "data/scripts/secret_base.pory"

# 491 "data/scripts/secret_base.pory"
@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
# 492 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer4:: @ 8275FB6
# 493 "data/scripts/secret_base.pory"
	lock
# 494 "data/scripts/secret_base.pory"
	faceplayer
# 495 "data/scripts/secret_base.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer4PreChampion
# 496 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 1
# 497 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer4PostBattle
# 498 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer4Intro, MSGBOX_YESNO
# 499 "data/scripts/secret_base.pory"
	compare VAR_RESULT, NO
# 500 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer4DeclineBattle
# 501 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 1
# 502 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 503 "data/scripts/secret_base.pory"
	call Common_EventScript_SaveGame
# 504 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 0
# 505 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer4DeclineBattle
# 506 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer4AcceptBattle, MSGBOX_DEFAULT
# 507 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_BattleTrainer
# 508 "data/scripts/secret_base.pory"
	end
# 509 "data/scripts/secret_base.pory"

# 510 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer4PreChampion:: @ 8276005
# 511 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer4PreChampion, MSGBOX_DEFAULT
# 512 "data/scripts/secret_base.pory"
	release
# 513 "data/scripts/secret_base.pory"
	end
# 514 "data/scripts/secret_base.pory"

# 515 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer4DeclineBattle:: @ 827600F
# 516 "data/scripts/secret_base.pory"
	special DeclinedSecretBaseBattle
# 517 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 0
# 518 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 519 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer4DeclineBattle, MSGBOX_DEFAULT
# 520 "data/scripts/secret_base.pory"
	release
# 521 "data/scripts/secret_base.pory"
	end
# 522 "data/scripts/secret_base.pory"

# 523 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer4PostBattle:: @ 8276024
# 524 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer4PostBattle, MSGBOX_DEFAULT
# 525 "data/scripts/secret_base.pory"
	release
# 526 "data/scripts/secret_base.pory"
	end
# 527 "data/scripts/secret_base.pory"

# 528 "data/scripts/secret_base.pory"
@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
# 529 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer5:: @ 827602E
# 530 "data/scripts/secret_base.pory"
	lock
# 531 "data/scripts/secret_base.pory"
	faceplayer
# 532 "data/scripts/secret_base.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer5PreChampion
# 533 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 1
# 534 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer5PostBattle
# 535 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer5Intro, MSGBOX_YESNO
# 536 "data/scripts/secret_base.pory"
	compare VAR_RESULT, NO
# 537 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer5DeclineBattle
# 538 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 1
# 539 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 540 "data/scripts/secret_base.pory"
	call Common_EventScript_SaveGame
# 541 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 0
# 542 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer5DeclineBattle
# 543 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer5AcceptBattle, MSGBOX_DEFAULT
# 544 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_BattleTrainer
# 545 "data/scripts/secret_base.pory"
	end
# 546 "data/scripts/secret_base.pory"

# 547 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer5PreChampion:: @ 827607D
# 548 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer5PreChampion, MSGBOX_DEFAULT
# 549 "data/scripts/secret_base.pory"
	release
# 550 "data/scripts/secret_base.pory"
	end
# 551 "data/scripts/secret_base.pory"

# 552 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer5DeclineBattle:: @ 8276087
# 553 "data/scripts/secret_base.pory"
	special DeclinedSecretBaseBattle
# 554 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 0
# 555 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 556 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer5DeclineBattle, MSGBOX_DEFAULT
# 557 "data/scripts/secret_base.pory"
	release
# 558 "data/scripts/secret_base.pory"
	end
# 559 "data/scripts/secret_base.pory"

# 560 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer5PostBattle:: @ 827609C
# 561 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer5PostBattle, MSGBOX_DEFAULT
# 562 "data/scripts/secret_base.pory"
	release
# 563 "data/scripts/secret_base.pory"
	end
# 564 "data/scripts/secret_base.pory"

# 565 "data/scripts/secret_base.pory"
@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
# 566 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer6:: @ 82760A6
# 567 "data/scripts/secret_base.pory"
	lock
# 568 "data/scripts/secret_base.pory"
	faceplayer
# 569 "data/scripts/secret_base.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer6PreChampion
# 570 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 1
# 571 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer6PostBattle
# 572 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer6Intro, MSGBOX_YESNO
# 573 "data/scripts/secret_base.pory"
	compare VAR_RESULT, NO
# 574 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer6DeclineBattle
# 575 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 1
# 576 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 577 "data/scripts/secret_base.pory"
	call Common_EventScript_SaveGame
# 578 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 0
# 579 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer6DeclineBattle
# 580 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer6AcceptBattle, MSGBOX_DEFAULT
# 581 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_BattleTrainer
# 582 "data/scripts/secret_base.pory"
	end
# 583 "data/scripts/secret_base.pory"

# 584 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer6PreChampion:: @ 82760F5
# 585 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer6PreChampion, MSGBOX_DEFAULT
# 586 "data/scripts/secret_base.pory"
	release
# 587 "data/scripts/secret_base.pory"
	end
# 588 "data/scripts/secret_base.pory"

# 589 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer6DeclineBattle:: @ 82760FF
# 590 "data/scripts/secret_base.pory"
	special DeclinedSecretBaseBattle
# 591 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 0
# 592 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 593 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer6DeclineBattle, MSGBOX_DEFAULT
# 594 "data/scripts/secret_base.pory"
	release
# 595 "data/scripts/secret_base.pory"
	end
# 596 "data/scripts/secret_base.pory"

# 597 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer6PostBattle:: @ 8276114
# 598 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer6PostBattle, MSGBOX_DEFAULT
# 599 "data/scripts/secret_base.pory"
	release
# 600 "data/scripts/secret_base.pory"
	end
# 601 "data/scripts/secret_base.pory"

# 602 "data/scripts/secret_base.pory"
@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
# 603 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer7:: @ 827611E
# 604 "data/scripts/secret_base.pory"
	lock
# 605 "data/scripts/secret_base.pory"
	faceplayer
# 606 "data/scripts/secret_base.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer7PreChampion
# 607 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 1
# 608 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer7PostBattle
# 609 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer7Intro, MSGBOX_YESNO
# 610 "data/scripts/secret_base.pory"
	compare VAR_RESULT, NO
# 611 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer7DeclineBattle
# 612 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 1
# 613 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 614 "data/scripts/secret_base.pory"
	call Common_EventScript_SaveGame
# 615 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 0
# 616 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer7DeclineBattle
# 617 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer7AcceptBattle, MSGBOX_DEFAULT
# 618 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_BattleTrainer
# 619 "data/scripts/secret_base.pory"
	end
# 620 "data/scripts/secret_base.pory"

# 621 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer7PreChampion:: @ 827616D
# 622 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer7PreChampion, MSGBOX_DEFAULT
# 623 "data/scripts/secret_base.pory"
	release
# 624 "data/scripts/secret_base.pory"
	end
# 625 "data/scripts/secret_base.pory"

# 626 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer7DeclineBattle:: @ 8276177
# 627 "data/scripts/secret_base.pory"
	special DeclinedSecretBaseBattle
# 628 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 0
# 629 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 630 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer7DeclineBattle, MSGBOX_DEFAULT
# 631 "data/scripts/secret_base.pory"
	release
# 632 "data/scripts/secret_base.pory"
	end
# 633 "data/scripts/secret_base.pory"

# 634 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer7PostBattle:: @ 827618C
# 635 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer7PostBattle, MSGBOX_DEFAULT
# 636 "data/scripts/secret_base.pory"
	release
# 637 "data/scripts/secret_base.pory"
	end
# 638 "data/scripts/secret_base.pory"

# 639 "data/scripts/secret_base.pory"
@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
# 640 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer8:: @ 8276196
# 641 "data/scripts/secret_base.pory"
	lock
# 642 "data/scripts/secret_base.pory"
	faceplayer
# 643 "data/scripts/secret_base.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer8PreChampion
# 644 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 1
# 645 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer8PostBattle
# 646 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer8Intro, MSGBOX_YESNO
# 647 "data/scripts/secret_base.pory"
	compare VAR_RESULT, NO
# 648 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer8DeclineBattle
# 649 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 1
# 650 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 651 "data/scripts/secret_base.pory"
	call Common_EventScript_SaveGame
# 652 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 0
# 653 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer8DeclineBattle
# 654 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer8AcceptBattle, MSGBOX_DEFAULT
# 655 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_BattleTrainer
# 656 "data/scripts/secret_base.pory"
	end
# 657 "data/scripts/secret_base.pory"

# 658 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer8PreChampion:: @ 82761E5
# 659 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer8PreChampion, MSGBOX_DEFAULT
# 660 "data/scripts/secret_base.pory"
	release
# 661 "data/scripts/secret_base.pory"
	end
# 662 "data/scripts/secret_base.pory"

# 663 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer8DeclineBattle:: @ 82761EF
# 664 "data/scripts/secret_base.pory"
	special DeclinedSecretBaseBattle
# 665 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 0
# 666 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 667 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer8DeclineBattle, MSGBOX_DEFAULT
# 668 "data/scripts/secret_base.pory"
	release
# 669 "data/scripts/secret_base.pory"
	end
# 670 "data/scripts/secret_base.pory"

# 671 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer8PostBattle:: @ 8276204
# 672 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer8PostBattle, MSGBOX_DEFAULT
# 673 "data/scripts/secret_base.pory"
	release
# 674 "data/scripts/secret_base.pory"
	end
# 675 "data/scripts/secret_base.pory"

# 676 "data/scripts/secret_base.pory"
@ VAR_RESULT is initially set by GetSecretBaseOwnerAndState
# 677 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer9:: @ 827620E
# 678 "data/scripts/secret_base.pory"
	lock
# 679 "data/scripts/secret_base.pory"
	faceplayer
# 680 "data/scripts/secret_base.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, SecretBase_EventScript_Trainer9PreChampion
# 681 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 1
# 682 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer9PostBattle
# 683 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer9Intro, MSGBOX_YESNO
# 684 "data/scripts/secret_base.pory"
	compare VAR_RESULT, NO
# 685 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer9DeclineBattle
# 686 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 1
# 687 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 688 "data/scripts/secret_base.pory"
	call Common_EventScript_SaveGame
# 689 "data/scripts/secret_base.pory"
	compare VAR_RESULT, 0
# 690 "data/scripts/secret_base.pory"
	goto_if_eq SecretBase_EventScript_Trainer9DeclineBattle
# 691 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer9AcceptBattle, MSGBOX_DEFAULT
# 692 "data/scripts/secret_base.pory"
	goto SecretBase_EventScript_BattleTrainer
# 693 "data/scripts/secret_base.pory"
	end
# 694 "data/scripts/secret_base.pory"

# 695 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer9PreChampion:: @ 827625D
# 696 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer9PreChampion, MSGBOX_DEFAULT
# 697 "data/scripts/secret_base.pory"
	release
# 698 "data/scripts/secret_base.pory"
	end
# 699 "data/scripts/secret_base.pory"

# 700 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer9DeclineBattle:: @ 8276267
# 701 "data/scripts/secret_base.pory"
	special DeclinedSecretBaseBattle
# 702 "data/scripts/secret_base.pory"
	setvar VAR_RESULT, 0
# 703 "data/scripts/secret_base.pory"
	special SetBattledOwnerFromResult
# 704 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer9DeclineBattle, MSGBOX_DEFAULT
# 705 "data/scripts/secret_base.pory"
	release
# 706 "data/scripts/secret_base.pory"
	end
# 707 "data/scripts/secret_base.pory"

# 708 "data/scripts/secret_base.pory"
SecretBase_EventScript_Trainer9PostBattle:: @ 827627C
# 709 "data/scripts/secret_base.pory"
	msgbox SecretBase_Text_Trainer9PostBattle, MSGBOX_DEFAULT
# 710 "data/scripts/secret_base.pory"
	release
# 711 "data/scripts/secret_base.pory"
	end
# 712 "data/scripts/secret_base.pory"

# 713 "data/scripts/secret_base.pory"
SecretBase_EventScript_BattleTrainer:: @ 8276286
# 714 "data/scripts/secret_base.pory"
	special PrepSecretBaseBattleFlags
# 715 "data/scripts/secret_base.pory"
	setvar VAR_0x8004, SPECIAL_BATTLE_SECRET_BASE
# 716 "data/scripts/secret_base.pory"
	setvar VAR_0x8005, 0
# 717 "data/scripts/secret_base.pory"
	special DoSpecialTrainerBattle
# 718 "data/scripts/secret_base.pory"
	waitstate
# 719 "data/scripts/secret_base.pory"
	compare VAR_RESULT, B_OUTCOME_DREW
# 720 "data/scripts/secret_base.pory"
	call_if_eq SecretBase_EventScript_DrewSecretBaseBattle
# 721 "data/scripts/secret_base.pory"
	compare VAR_RESULT, B_OUTCOME_WON
# 722 "data/scripts/secret_base.pory"
	call_if_eq SecretBase_EventScript_WonSecretBaseBattle
# 723 "data/scripts/secret_base.pory"
	compare VAR_RESULT, B_OUTCOME_LOST
# 724 "data/scripts/secret_base.pory"
	call_if_eq SecretBase_EventScript_LostSecretBaseBattle
# 725 "data/scripts/secret_base.pory"
	special HealPlayerParty
# 726 "data/scripts/secret_base.pory"
	release
# 727 "data/scripts/secret_base.pory"
	end
# 728 "data/scripts/secret_base.pory"

# 729 "data/scripts/secret_base.pory"
SecretBase_EventScript_DrewSecretBaseBattle:: @ 82762BD
# 730 "data/scripts/secret_base.pory"
	special DrewSecretBaseBattle
# 731 "data/scripts/secret_base.pory"
	return
# 732 "data/scripts/secret_base.pory"

# 733 "data/scripts/secret_base.pory"
SecretBase_EventScript_WonSecretBaseBattle:: @ 82762C1
# 734 "data/scripts/secret_base.pory"
	special WonSecretBaseBattle
# 735 "data/scripts/secret_base.pory"
	return
# 736 "data/scripts/secret_base.pory"

# 737 "data/scripts/secret_base.pory"
SecretBase_EventScript_LostSecretBaseBattle:: @ 82762C5
# 738 "data/scripts/secret_base.pory"
	special LostSecretBaseBattle
# 739 "data/scripts/secret_base.pory"
	return
# 740 "data/scripts/secret_base.pory"

# 741 "data/scripts/secret_base.pory"

# 742 "data/scripts/secret_base.pory"
SecretBase_EventScript_DollInteract:: @ 82766A2
# 743 "data/scripts/secret_base.pory"
	special CheckInteractedWithFriendsDollDecor
# 744 "data/scripts/secret_base.pory"
	end
# 745 "data/scripts/secret_base.pory"

# 746 "data/scripts/secret_base.pory"
SecretBase_EventScript_CushionInteract:: @ 82766A6
# 747 "data/scripts/secret_base.pory"
	special CheckInteractedWithFriendsCushionDecor
# 748 "data/scripts/secret_base.pory"
	end
# 749 "data/scripts/secret_base.pory"

# 750 "data/scripts/secret_base.pory"
SecretBase_Text_AllDecorationsWillBeReturned: @ 82766AA
# 751 "data/scripts/secret_base.pory"
	.string "All decorations and furniture in your\n"
# 752 "data/scripts/secret_base.pory"
	.string "Secret Base will be returned to your PC.\p"
# 753 "data/scripts/secret_base.pory"
	.string "Is that okay?$"
# 754 "data/scripts/secret_base.pory"

# 755 "data/scripts/secret_base.pory"
SecretBase_Text_WantToRegisterSecretBase: @ 8276707
# 756 "data/scripts/secret_base.pory"
	.string "Do you want to register\n"
# 757 "data/scripts/secret_base.pory"
	.string "{STR_VAR_1}'s Secret Base?$"
# 758 "data/scripts/secret_base.pory"

# 759 "data/scripts/secret_base.pory"
SecretBase_Text_AlreadyRegisteredDelete: @ 8276731
# 760 "data/scripts/secret_base.pory"
	.string "This data is already registered.\n"
# 761 "data/scripts/secret_base.pory"
	.string "Would you like to delete it?$"
# 762 "data/scripts/secret_base.pory"

# 763 "data/scripts/secret_base.pory"
SecretBase_Text_TooManyBasesDeleteSome: @ 827676F
# 764 "data/scripts/secret_base.pory"
	.string "Up to 10 locations can be registered.\p"
# 765 "data/scripts/secret_base.pory"
	.string "Delete a location if you want to\n"
# 766 "data/scripts/secret_base.pory"
	.string "register another location.$"
# 767 "data/scripts/secret_base.pory"

# 768 "data/scripts/secret_base.pory"
SecretBase_Text_RegistrationCompleted: @ 82767D1
# 769 "data/scripts/secret_base.pory"
	.string "Registration completed.$"
# 770 "data/scripts/secret_base.pory"

# 771 "data/scripts/secret_base.pory"
SecretBase_Text_DataUnregistered: @ 82767E9
# 772 "data/scripts/secret_base.pory"
	.string "Data has been unregistered.$"
# 773 "data/scripts/secret_base.pory"

# 774 "data/scripts/secret_base.pory"
SecretBase_Text_BootUpPC: @ 8276805
# 775 "data/scripts/secret_base.pory"
	.string "{PLAYER} booted up the PC.$"
# 776 "data/scripts/secret_base.pory"

# 777 "data/scripts/secret_base.pory"
SecretBase_Text_WhatWouldYouLikeToDo: @ 827681A
# 778 "data/scripts/secret_base.pory"
	.string "What would you like to do?$"
# 779 "data/scripts/secret_base.pory"

# 780 "data/scripts/secret_base.pory"
SecretBase_Text_RegistryInfo: @ 8276835
# 781 "data/scripts/secret_base.pory"
	.string "Once registered, a Secret Base will not\n"
# 782 "data/scripts/secret_base.pory"
	.string "disappear unless the other Trainer\l"
# 783 "data/scripts/secret_base.pory"
	.string "moves it to a different location.\p"
# 784 "data/scripts/secret_base.pory"
	.string "If a Secret Base is deleted from the\n"
# 785 "data/scripts/secret_base.pory"
	.string "registered list, another one may take\l"
# 786 "data/scripts/secret_base.pory"
	.string "its place.\p"
# 787 "data/scripts/secret_base.pory"
	.string "Up to ten Secret Base locations\n"
# 788 "data/scripts/secret_base.pory"
	.string "may be registered.$"
# 789 "data/scripts/secret_base.pory"

# 790 "data/scripts/secret_base.pory"
SecretBase_Text_BattleTowerShield: @ 827692B
# 791 "data/scripts/secret_base.pory"
	.string "A shield of {STR_VAR_2} that marks winning\n"
# 792 "data/scripts/secret_base.pory"
	.string "{STR_VAR_1} times in a row at the Battle Tower.$"
# 793 "data/scripts/secret_base.pory"

# 794 "data/scripts/secret_base.pory"
SecretBase_Text_ToyTV: @ 8276974
# 795 "data/scripts/secret_base.pory"
	.string "A realistic toy TV. It could be easily\n"
# 796 "data/scripts/secret_base.pory"
	.string "mistaken for the real thing.$"
# 797 "data/scripts/secret_base.pory"

# 798 "data/scripts/secret_base.pory"
SecretBase_Text_SeedotTV: @ 82769B8
# 799 "data/scripts/secret_base.pory"
	.string "A toy TV shaped like a Seedot.\n"
# 800 "data/scripts/secret_base.pory"
	.string "It looks ready to roll away on its own…$"
# 801 "data/scripts/secret_base.pory"

# 802 "data/scripts/secret_base.pory"
SecretBase_Text_SkittyTV: @ 82769FF
# 803 "data/scripts/secret_base.pory"
	.string "A toy TV shaped like a Skitty.\n"
# 804 "data/scripts/secret_base.pory"
	.string "It looks ready to stroll away…$"
# 805 "data/scripts/secret_base.pory"

# 806 "data/scripts/secret_base.pory"
SecretBase_Text_WouldYouLikeToMoveBases: @ 8276A3D
# 807 "data/scripts/secret_base.pory"
	.string "You may only make one Secret Base.\p"
# 808 "data/scripts/secret_base.pory"
	.string "Would you like to move from the Secret\n"
# 809 "data/scripts/secret_base.pory"
	.string "Base near {STR_VAR_1}?$"
# 810 "data/scripts/secret_base.pory"

# 811 "data/scripts/secret_base.pory"
SecretBase_Text_MovingCompletedUseSecretPower: @ 8276A95
# 812 "data/scripts/secret_base.pory"
	.string "Moving completed.\p"
# 813 "data/scripts/secret_base.pory"
	.string "Would you like to use the Secret Power?$"
