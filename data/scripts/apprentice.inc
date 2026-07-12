# 1 "data/scripts/apprentice.pory"

# 2 "data/scripts/apprentice.pory"
.set LOCALID_APPRENTICE, 6
# 3 "data/scripts/apprentice.pory"

# 4 "data/scripts/apprentice.pory"
BattleFrontier_BattleTowerLobby_EventScript_Apprentice::
# 5 "data/scripts/apprentice.pory"
	lock
# 6 "data/scripts/apprentice.pory"
	faceplayer
# 7 "data/scripts/apprentice.pory"
	apprentice_gavelvlmode
# 8 "data/scripts/apprentice.pory"
	compare VAR_RESULT, FALSE
# 9 "data/scripts/apprentice.pory"
	goto_if_eq Apprentice_EventScript_FirstMeeting
# 10 "data/scripts/apprentice.pory"
	apprentice_shouldcheckgone
# 11 "data/scripts/apprentice.pory"
	compare VAR_0x8004, FALSE  @ Always TRUE here
# 12 "data/scripts/apprentice.pory"
	goto_if_eq Apprentice_EventScript_AskQuestion
# 13 "data/scripts/apprentice.pory"
	goto_if_set FLAG_DAILY_APPRENTICE_LEAVES, Apprentice_EventScript_Gone
# 14 "data/scripts/apprentice.pory"
Apprentice_EventScript_AskQuestion:
# 15 "data/scripts/apprentice.pory"
	apprentice_getquestion
# 16 "data/scripts/apprentice.pory"
	compare VAR_RESULT, APPRENTICE_QUESTION_WHICH_MON
# 17 "data/scripts/apprentice.pory"
	goto_if_eq Apprentice_EventScript_UseWhichMon
# 18 "data/scripts/apprentice.pory"
	compare VAR_RESULT, APPRENTICE_QUESTION_WHAT_ITEM
# 19 "data/scripts/apprentice.pory"
	goto_if_eq Apprentice_EventScript_UseWhatHeldItem
# 20 "data/scripts/apprentice.pory"
	compare VAR_RESULT, APPRENTICE_QUESTION_WHICH_MOVE
# 21 "data/scripts/apprentice.pory"
	goto_if_eq Apprentice_EventScript_UseWhichMove
# 22 "data/scripts/apprentice.pory"
	compare VAR_RESULT, APPRENTICE_QUESTION_WHICH_FIRST
# 23 "data/scripts/apprentice.pory"
	goto_if_eq Apprentice_EventScript_PutWhichMonFirst
# 24 "data/scripts/apprentice.pory"
	compare VAR_RESULT, APPRENTICE_QUESTION_WIN_SPEECH
# 25 "data/scripts/apprentice.pory"
	goto_if_eq Apprentice_EventScript_PickWinSpeech
# 26 "data/scripts/apprentice.pory"
	release
# 27 "data/scripts/apprentice.pory"
	releaseall
# 28 "data/scripts/apprentice.pory"
	end
# 29 "data/scripts/apprentice.pory"

# 30 "data/scripts/apprentice.pory"
Apprentice_EventScript_FirstMeeting:
# 31 "data/scripts/apprentice.pory"
	apprentice_buff 0, APPRENTICE_BUFF_NAME
# 32 "data/scripts/apprentice.pory"
	apprentice_msg FALSE, APPRENTICE_MSG_PLEASE_TEACH
# 33 "data/scripts/apprentice.pory"
Apprentice_EventScript_WhichLvlMode:
# 34 "data/scripts/apprentice.pory"
	apprentice_menu APPRENTICE_ASK_YES_NO
# 35 "data/scripts/apprentice.pory"
	compare VAR_RESULT, 1
# 36 "data/scripts/apprentice.pory"
	goto_if_eq Apprentice_EventScript_RejectTeach
# 37 "data/scripts/apprentice.pory"
	apprentice_msg FALSE, APPRENTICE_MSG_WHICH_LVL_MODE
# 38 "data/scripts/apprentice.pory"
	apprentice_menu APPRENTICE_ASK_WHICH_LEVEL
# 39 "data/scripts/apprentice.pory"
	apprentice_setlvlmode VAR_RESULT
# 40 "data/scripts/apprentice.pory"
	apprentice_shufflespecies
# 41 "data/scripts/apprentice.pory"
	apprentice_buff 0, APPRENTICE_BUFF_LEVEL
# 42 "data/scripts/apprentice.pory"
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_LVL_MODE
# 43 "data/scripts/apprentice.pory"
	call Apprentice_EventScript_SetHideFlags
# 44 "data/scripts/apprentice.pory"
	release
# 45 "data/scripts/apprentice.pory"
	releaseall
# 46 "data/scripts/apprentice.pory"
	switch VAR_FACING
# 47 "data/scripts/apprentice.pory"
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
# 48 "data/scripts/apprentice.pory"
	goto Apprentice_EventScript_Leave
# 49 "data/scripts/apprentice.pory"
	end
# 50 "data/scripts/apprentice.pory"

# 51 "data/scripts/apprentice.pory"
@ Its impossible to fully reject an Apprentice, they just keep asking for you to teach them
# 52 "data/scripts/apprentice.pory"
Apprentice_EventScript_RejectTeach:
# 53 "data/scripts/apprentice.pory"
	apprentice_msg FALSE, APPRENTICE_MSG_REJECT
# 54 "data/scripts/apprentice.pory"
	goto Apprentice_EventScript_WhichLvlMode
# 55 "data/scripts/apprentice.pory"

# 56 "data/scripts/apprentice.pory"
Apprentice_EventScript_UseWhichMon:
# 57 "data/scripts/apprentice.pory"
	apprentice_initquestion APPRENTICE_QUESTION_WHICH_MON
# 58 "data/scripts/apprentice.pory"
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES1
# 59 "data/scripts/apprentice.pory"
	apprentice_buff 1, APPRENTICE_BUFF_SPECIES2
# 60 "data/scripts/apprentice.pory"
	apprentice_msg FALSE, APPRENTICE_MSG_WHICH_MON
# 61 "data/scripts/apprentice.pory"
	apprentice_menu APPRENTICE_ASK_2SPECIES
# 62 "data/scripts/apprentice.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 63 "data/scripts/apprentice.pory"
	compare VAR_0x8005, 0
# 64 "data/scripts/apprentice.pory"
	call_if_eq Apprentice_EventScript_ChoseFirstMon
# 65 "data/scripts/apprentice.pory"
	compare VAR_0x8005, 1
# 66 "data/scripts/apprentice.pory"
	call_if_eq Apprentice_EventScript_ChoseSecondMon
# 67 "data/scripts/apprentice.pory"
	apprentice_getnumpartymons
# 68 "data/scripts/apprentice.pory"
	apprentice_setpartymon VAR_RESULT
# 69 "data/scripts/apprentice.pory"
	apprentice_answeredquestion
# 70 "data/scripts/apprentice.pory"
	apprentice_getnumpartymons
# 71 "data/scripts/apprentice.pory"
	compare VAR_RESULT, MULTI_PARTY_SIZE
# 72 "data/scripts/apprentice.pory"
	call_if_eq Apprentice_EventScript_LastMonSelected
# 73 "data/scripts/apprentice.pory"
	apprentice_buff 0, VAR_0x8007
# 74 "data/scripts/apprentice.pory"
	apprentice_freequestion
# 75 "data/scripts/apprentice.pory"
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_MON
# 76 "data/scripts/apprentice.pory"
	call Apprentice_EventScript_SetHideFlags
# 77 "data/scripts/apprentice.pory"
	release
# 78 "data/scripts/apprentice.pory"
	releaseall
# 79 "data/scripts/apprentice.pory"
	switch VAR_FACING
# 80 "data/scripts/apprentice.pory"
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
# 81 "data/scripts/apprentice.pory"
	goto Apprentice_EventScript_Leave
# 82 "data/scripts/apprentice.pory"
	end
# 83 "data/scripts/apprentice.pory"

# 84 "data/scripts/apprentice.pory"
Apprentice_EventScript_ChoseFirstMon:
# 85 "data/scripts/apprentice.pory"
	setvar VAR_0x8007, APPRENTICE_BUFF_SPECIES1
# 86 "data/scripts/apprentice.pory"
	return
# 87 "data/scripts/apprentice.pory"

# 88 "data/scripts/apprentice.pory"
Apprentice_EventScript_ChoseSecondMon:
# 89 "data/scripts/apprentice.pory"
	setvar VAR_0x8007, APPRENTICE_BUFF_SPECIES2
# 90 "data/scripts/apprentice.pory"
	return
# 91 "data/scripts/apprentice.pory"

# 92 "data/scripts/apprentice.pory"
Apprentice_EventScript_LastMonSelected:
# 93 "data/scripts/apprentice.pory"
	apprentice_randomizequestions
# 94 "data/scripts/apprentice.pory"
	return
# 95 "data/scripts/apprentice.pory"

# 96 "data/scripts/apprentice.pory"
Apprentice_EventScript_UseWhatHeldItem:
# 97 "data/scripts/apprentice.pory"
	apprentice_initquestion APPRENTICE_QUESTION_WHAT_ITEM
# 98 "data/scripts/apprentice.pory"
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES3
# 99 "data/scripts/apprentice.pory"
	apprentice_msg TRUE, APPRENTICE_MSG_WHAT_HELD_ITEM
# 100 "data/scripts/apprentice.pory"
	apprentice_freequestion
# 101 "data/scripts/apprentice.pory"
Apprentice_EventScript_ChooseHoldItem:
# 102 "data/scripts/apprentice.pory"
	fadescreen FADE_TO_BLACK
# 103 "data/scripts/apprentice.pory"
	setvar VAR_RESULT, 0
# 104 "data/scripts/apprentice.pory"
	apprentice_openbag
# 105 "data/scripts/apprentice.pory"
	compare VAR_RESULT, FALSE
# 106 "data/scripts/apprentice.pory"
	goto_if_eq Apprentice_EventScript_ConfirmHoldNothing
# 107 "data/scripts/apprentice.pory"
	apprentice_trysetitem
# 108 "data/scripts/apprentice.pory"
	compare VAR_RESULT, FALSE
# 109 "data/scripts/apprentice.pory"
	goto_if_eq Apprentice_EventScript_AlreadySuggestedItem
# 110 "data/scripts/apprentice.pory"
	apprentice_buff 0, APPRENTICE_BUFF_ITEM
# 111 "data/scripts/apprentice.pory"
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_HELD_ITEM
# 112 "data/scripts/apprentice.pory"
	apprentice_answeredquestion
# 113 "data/scripts/apprentice.pory"
	call Apprentice_EventScript_SetHideFlags
# 114 "data/scripts/apprentice.pory"
	release
# 115 "data/scripts/apprentice.pory"
	releaseall
# 116 "data/scripts/apprentice.pory"
	switch VAR_FACING
# 117 "data/scripts/apprentice.pory"
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
# 118 "data/scripts/apprentice.pory"
	goto Apprentice_EventScript_Leave
# 119 "data/scripts/apprentice.pory"
	end
# 120 "data/scripts/apprentice.pory"

# 121 "data/scripts/apprentice.pory"
Apprentice_EventScript_ConfirmHoldNothing:
# 122 "data/scripts/apprentice.pory"
	apprentice_initquestion APPRENTICE_QUESTION_WHAT_ITEM
# 123 "data/scripts/apprentice.pory"
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES3
# 124 "data/scripts/apprentice.pory"
	apprentice_msg FALSE, APPRENTICE_MSG_HOLD_NOTHING
# 125 "data/scripts/apprentice.pory"
	apprentice_menu APPRENTICE_ASK_GIVE
# 126 "data/scripts/apprentice.pory"
	apprentice_freequestion
# 127 "data/scripts/apprentice.pory"
	compare VAR_RESULT, 0
# 128 "data/scripts/apprentice.pory"
	goto_if_eq Apprentice_EventScript_ChooseHoldItem
# 129 "data/scripts/apprentice.pory"
Apprentice_EventScript_HoldNothing:
# 130 "data/scripts/apprentice.pory"
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_NO_HELD_ITEM
# 131 "data/scripts/apprentice.pory"
	apprentice_answeredquestion
# 132 "data/scripts/apprentice.pory"
	call Apprentice_EventScript_SetHideFlags
# 133 "data/scripts/apprentice.pory"
	release
# 134 "data/scripts/apprentice.pory"
	releaseall
# 135 "data/scripts/apprentice.pory"
	switch VAR_FACING
# 136 "data/scripts/apprentice.pory"
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
# 137 "data/scripts/apprentice.pory"
	goto Apprentice_EventScript_Leave
# 138 "data/scripts/apprentice.pory"
	end
# 139 "data/scripts/apprentice.pory"

# 140 "data/scripts/apprentice.pory"
@ Because Battle Tower mons may not hold the same item, the player must suggest a
# 141 "data/scripts/apprentice.pory"
@ different item if theyve already told the Apprentice to use it for another mon
# 142 "data/scripts/apprentice.pory"
Apprentice_EventScript_AlreadySuggestedItem:
# 143 "data/scripts/apprentice.pory"
	apprentice_initquestion APPRENTICE_QUESTION_WHAT_ITEM
# 144 "data/scripts/apprentice.pory"
	apprentice_buff 0, APPRENTICE_BUFF_ITEM
# 145 "data/scripts/apprentice.pory"
	apprentice_buff 1, APPRENTICE_BUFF_SPECIES3
# 146 "data/scripts/apprentice.pory"
	apprentice_msg FALSE, APPRENTICE_MSG_ITEM_ALREADY_SUGGESTED
# 147 "data/scripts/apprentice.pory"
	apprentice_menu APPRENTICE_ASK_GIVE
# 148 "data/scripts/apprentice.pory"
	apprentice_freequestion
# 149 "data/scripts/apprentice.pory"
	compare VAR_RESULT, 0
# 150 "data/scripts/apprentice.pory"
	goto_if_eq Apprentice_EventScript_ChooseHoldItem
# 151 "data/scripts/apprentice.pory"
	goto Apprentice_EventScript_HoldNothing
# 152 "data/scripts/apprentice.pory"
	end
# 153 "data/scripts/apprentice.pory"

# 154 "data/scripts/apprentice.pory"
Apprentice_EventScript_UseWhichMove:
# 155 "data/scripts/apprentice.pory"
	apprentice_initquestion APPRENTICE_QUESTION_WHICH_MOVE
# 156 "data/scripts/apprentice.pory"
	apprentice_buff 0, APPRENTICE_BUFF_SPECIES3
# 157 "data/scripts/apprentice.pory"
	apprentice_buff 1, APPRENTICE_BUFF_MOVE1
# 158 "data/scripts/apprentice.pory"
	apprentice_buff 2, APPRENTICE_BUFF_MOVE2
# 159 "data/scripts/apprentice.pory"
	apprentice_msg FALSE, APPRENTICE_MSG_WHICH_MOVE
# 160 "data/scripts/apprentice.pory"
	apprentice_menu APPRENTICE_ASK_MOVES
# 161 "data/scripts/apprentice.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 162 "data/scripts/apprentice.pory"
	compare VAR_0x8005, 0
# 163 "data/scripts/apprentice.pory"
	call_if_eq Apprentice_EventScript_ChoseMove1
# 164 "data/scripts/apprentice.pory"
	compare VAR_0x8005, 1
# 165 "data/scripts/apprentice.pory"
	call_if_eq Apprentice_EventScript_ChoseMove2
# 166 "data/scripts/apprentice.pory"
	apprentice_setmove
# 167 "data/scripts/apprentice.pory"
	apprentice_answeredquestion
# 168 "data/scripts/apprentice.pory"
	apprentice_buff 0, VAR_0x8007
# 169 "data/scripts/apprentice.pory"
	apprentice_freequestion
# 170 "data/scripts/apprentice.pory"
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_MOVE
# 171 "data/scripts/apprentice.pory"
	call Apprentice_EventScript_SetHideFlags
# 172 "data/scripts/apprentice.pory"
	release
# 173 "data/scripts/apprentice.pory"
	releaseall
# 174 "data/scripts/apprentice.pory"
	switch VAR_FACING
# 175 "data/scripts/apprentice.pory"
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
# 176 "data/scripts/apprentice.pory"
	goto Apprentice_EventScript_Leave
# 177 "data/scripts/apprentice.pory"
	end
# 178 "data/scripts/apprentice.pory"

# 179 "data/scripts/apprentice.pory"
Apprentice_EventScript_ChoseMove1:
# 180 "data/scripts/apprentice.pory"
	setvar VAR_0x8007, APPRENTICE_BUFF_MOVE1
# 181 "data/scripts/apprentice.pory"
	return
# 182 "data/scripts/apprentice.pory"

# 183 "data/scripts/apprentice.pory"
Apprentice_EventScript_ChoseMove2:
# 184 "data/scripts/apprentice.pory"
	setvar VAR_0x8007, APPRENTICE_BUFF_MOVE2
# 185 "data/scripts/apprentice.pory"
	return
# 186 "data/scripts/apprentice.pory"

# 187 "data/scripts/apprentice.pory"
Apprentice_EventScript_PutWhichMonFirst:
# 188 "data/scripts/apprentice.pory"
	apprentice_msg FALSE, APPRENTICE_MSG_WHICH_MON_FIRST
# 189 "data/scripts/apprentice.pory"
	apprentice_menu APPRENTICE_ASK_3SPECIES
# 190 "data/scripts/apprentice.pory"
	apprentice_setleadmon VAR_RESULT
# 191 "data/scripts/apprentice.pory"
	apprentice_answeredquestion
# 192 "data/scripts/apprentice.pory"
	apprentice_buff 0, APPRENTICE_BUFF_LEAD_MON_SPECIES
# 193 "data/scripts/apprentice.pory"
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_MON_FIRST
# 194 "data/scripts/apprentice.pory"
	call Apprentice_EventScript_SetHideFlags
# 195 "data/scripts/apprentice.pory"
	release
# 196 "data/scripts/apprentice.pory"
	releaseall
# 197 "data/scripts/apprentice.pory"
	switch VAR_FACING
# 198 "data/scripts/apprentice.pory"
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
# 199 "data/scripts/apprentice.pory"
	goto Apprentice_EventScript_Leave
# 200 "data/scripts/apprentice.pory"
	end
# 201 "data/scripts/apprentice.pory"

# 202 "data/scripts/apprentice.pory"
@ Last question, after which the Apprentice leaves (and is saved) to be replaced by another
# 203 "data/scripts/apprentice.pory"
Apprentice_EventScript_PickWinSpeech:
# 204 "data/scripts/apprentice.pory"
	apprentice_msg TRUE, APPRENTICE_MSG_PICK_WIN_SPEECH
# 205 "data/scripts/apprentice.pory"
	apprentice_shiftsaved
# 206 "data/scripts/apprentice.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_APPRENTICE
# 207 "data/scripts/apprentice.pory"
	call Common_ShowEasyChatScreen
# 208 "data/scripts/apprentice.pory"
	lock
# 209 "data/scripts/apprentice.pory"
	faceplayer
# 210 "data/scripts/apprentice.pory"
	apprentice_save
# 211 "data/scripts/apprentice.pory"
	apprentice_buff 0, APPRENTICE_BUFF_WIN_SPEECH
# 212 "data/scripts/apprentice.pory"
	apprentice_msg TRUE, APPRENTICE_MSG_THANKS_WIN_SPEECH
# 213 "data/scripts/apprentice.pory"
	apprentice_reset
# 214 "data/scripts/apprentice.pory"
	call Apprentice_EventScript_SetHideFlags
# 215 "data/scripts/apprentice.pory"
	release
# 216 "data/scripts/apprentice.pory"
	releaseall
# 217 "data/scripts/apprentice.pory"
	switch VAR_FACING
# 218 "data/scripts/apprentice.pory"
	case DIR_NORTH, Apprentice_EventScript_LeaveNorth
# 219 "data/scripts/apprentice.pory"
	goto Apprentice_EventScript_Leave
# 220 "data/scripts/apprentice.pory"
	end
# 221 "data/scripts/apprentice.pory"

# 222 "data/scripts/apprentice.pory"
Apprentice_EventScript_SetHideFlags:
# 223 "data/scripts/apprentice.pory"
	setflag FLAG_HIDE_APPRENTICE
# 224 "data/scripts/apprentice.pory"
	setflag FLAG_DAILY_APPRENTICE_LEAVES
# 225 "data/scripts/apprentice.pory"
	return
# 226 "data/scripts/apprentice.pory"

# 227 "data/scripts/apprentice.pory"
Apprentice_EventScript_LeaveNorth:
# 228 "data/scripts/apprentice.pory"
	apprentice_shouldleave
# 229 "data/scripts/apprentice.pory"
	compare VAR_0x8004, FALSE  @ Always TRUE here
# 230 "data/scripts/apprentice.pory"
	goto_if_eq Apprentice_EventScript_DontMove
# 231 "data/scripts/apprentice.pory"
	applymovement LOCALID_APPRENTICE, Apprentice_Movement_LeaveNorth
# 232 "data/scripts/apprentice.pory"
	waitmovement 0
# 233 "data/scripts/apprentice.pory"
	end
# 234 "data/scripts/apprentice.pory"

# 235 "data/scripts/apprentice.pory"
Apprentice_EventScript_Leave:
# 236 "data/scripts/apprentice.pory"
	apprentice_shouldleave
# 237 "data/scripts/apprentice.pory"
	compare VAR_0x8004, FALSE  @ Always TRUE here
# 238 "data/scripts/apprentice.pory"
	goto_if_eq Apprentice_EventScript_DontMove
# 239 "data/scripts/apprentice.pory"
	applymovement LOCALID_APPRENTICE, Apprentice_Movement_Leave
# 240 "data/scripts/apprentice.pory"
	waitmovement 0
# 241 "data/scripts/apprentice.pory"
	end
# 242 "data/scripts/apprentice.pory"

# 243 "data/scripts/apprentice.pory"
Apprentice_EventScript_Gone:
# 244 "data/scripts/apprentice.pory"
	release
# 245 "data/scripts/apprentice.pory"
	releaseall
# 246 "data/scripts/apprentice.pory"
	end
# 247 "data/scripts/apprentice.pory"

# 248 "data/scripts/apprentice.pory"
Apprentice_EventScript_DontMove:
# 249 "data/scripts/apprentice.pory"
	end
# 250 "data/scripts/apprentice.pory"

# 251 "data/scripts/apprentice.pory"
Apprentice_Movement_LeaveNorth:
# 252 "data/scripts/apprentice.pory"
	walk_fast_right
# 253 "data/scripts/apprentice.pory"
Apprentice_Movement_Leave:
# 254 "data/scripts/apprentice.pory"
	walk_fast_down
# 255 "data/scripts/apprentice.pory"
	walk_fast_down
# 256 "data/scripts/apprentice.pory"
	walk_fast_right
# 257 "data/scripts/apprentice.pory"
	walk_fast_right
# 258 "data/scripts/apprentice.pory"
	walk_fast_right
# 259 "data/scripts/apprentice.pory"
	walk_fast_right
# 260 "data/scripts/apprentice.pory"
	walk_fast_right
# 261 "data/scripts/apprentice.pory"
	walk_fast_right
# 262 "data/scripts/apprentice.pory"
	walk_fast_right
# 263 "data/scripts/apprentice.pory"
	walk_fast_right
# 264 "data/scripts/apprentice.pory"
	walk_fast_right
# 265 "data/scripts/apprentice.pory"
	set_invisible
# 266 "data/scripts/apprentice.pory"
	slide_down
# 267 "data/scripts/apprentice.pory"
	slide_down
# 268 "data/scripts/apprentice.pory"
	slide_down
# 269 "data/scripts/apprentice.pory"
	step_end
