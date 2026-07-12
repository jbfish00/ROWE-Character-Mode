# 1 "data/scripts/gabby_and_ty.pory"

# 2 "data/scripts/gabby_and_ty.pory"
@ Unused
# 3 "data/scripts/gabby_and_ty.pory"
EventScript_28CCAA::
# 4 "data/scripts/gabby_and_ty.pory"
	setvar VAR_0x8005, 8
# 5 "data/scripts/gabby_and_ty.pory"
	special InterviewBefore
# 6 "data/scripts/gabby_and_ty.pory"
	compare VAR_RESULT, 1
# 7 "data/scripts/gabby_and_ty.pory"
	goto_if_eq EventScript_UnusedRet
# 8 "data/scripts/gabby_and_ty.pory"
	setvar VAR_0x8005, 8
# 9 "data/scripts/gabby_and_ty.pory"
	special InterviewAfter
# 10 "data/scripts/gabby_and_ty.pory"
	return
# 11 "data/scripts/gabby_and_ty.pory"

# 12 "data/scripts/gabby_and_ty.pory"
EventScript_UnusedRet::
# 13 "data/scripts/gabby_and_ty.pory"
	return
# 14 "data/scripts/gabby_and_ty.pory"

# 15 "data/scripts/gabby_and_ty.pory"
@ Gabby and Ty always move to the same spots for the first 5 battles
# 16 "data/scripts/gabby_and_ty.pory"
@ From the 6th battle onwards, they move randomly between locations 6-8
# 17 "data/scripts/gabby_and_ty.pory"
@ Note: The local IDs of Gabby and Ty are hard-coded in GabbyAndTySetScriptVarsToObjectEventLocalIds
# 18 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_UpdateLocation::
# 19 "data/scripts/gabby_and_ty.pory"
	cleartrainerflag TRAINER_GABBY_AND_TY_6
# 20 "data/scripts/gabby_and_ty.pory"
	specialvar VAR_RESULT, GabbyAndTyGetBattleNum
# 21 "data/scripts/gabby_and_ty.pory"
	switch VAR_RESULT
# 22 "data/scripts/gabby_and_ty.pory"
	case 0, GabbyAndTy_EventScript_MoveForBattle1
# 23 "data/scripts/gabby_and_ty.pory"
	case 1, GabbyAndTy_EventScript_MoveForBattle2
# 24 "data/scripts/gabby_and_ty.pory"
	case 2, GabbyAndTy_EventScript_MoveForBattle3
# 25 "data/scripts/gabby_and_ty.pory"
	case 3, GabbyAndTy_EventScript_MoveForBattle4
# 26 "data/scripts/gabby_and_ty.pory"
	case 4, GabbyAndTy_EventScript_MoveForBattle5
# 27 "data/scripts/gabby_and_ty.pory"
	case 5, GabbyAndTy_EventScript_MoveForBattle6
# 28 "data/scripts/gabby_and_ty.pory"
	case 6, GabbyAndTy_EventScript_MoveForBattle7
# 29 "data/scripts/gabby_and_ty.pory"
	case 7, GabbyAndTy_EventScript_MoveForBattle8
# 30 "data/scripts/gabby_and_ty.pory"
	case 8, GabbyAndTy_EventScript_MoveForBattle9
# 31 "data/scripts/gabby_and_ty.pory"
	end
# 32 "data/scripts/gabby_and_ty.pory"

# 33 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_MoveForBattle1::
# 34 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_ShowAtRoute111_1
# 35 "data/scripts/gabby_and_ty.pory"
	return
# 36 "data/scripts/gabby_and_ty.pory"

# 37 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_MoveForBattle2::
# 38 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_ShowAtRoute118_1
# 39 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_HideAtRoute111_1
# 40 "data/scripts/gabby_and_ty.pory"
	return
# 41 "data/scripts/gabby_and_ty.pory"

# 42 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_MoveForBattle3::
# 43 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_ShowAtRoute120_1
# 44 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_HideAtRoute118_1
# 45 "data/scripts/gabby_and_ty.pory"
	return
# 46 "data/scripts/gabby_and_ty.pory"

# 47 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_MoveForBattle4::
# 48 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_ShowAtRoute111_3
# 49 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_HideAtRoute120_1
# 50 "data/scripts/gabby_and_ty.pory"
	return
# 51 "data/scripts/gabby_and_ty.pory"

# 52 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_MoveForBattle5::
# 53 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_ShowAtRoute118_2
# 54 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_HideAtRoute111_3
# 55 "data/scripts/gabby_and_ty.pory"
	return
# 56 "data/scripts/gabby_and_ty.pory"

# 57 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_MoveForBattle6::
# 58 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_ShowAtRoute120_2
# 59 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_HideAtRoute118_2
# 60 "data/scripts/gabby_and_ty.pory"
	return
# 61 "data/scripts/gabby_and_ty.pory"

# 62 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_MoveForBattle7::
# 63 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_ShowAtRoute111_2
# 64 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_HideAtRoute120_2
# 65 "data/scripts/gabby_and_ty.pory"
	return
# 66 "data/scripts/gabby_and_ty.pory"

# 67 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_MoveForBattle8::
# 68 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_ShowAtRoute118_3
# 69 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_HideAtRoute111_2
# 70 "data/scripts/gabby_and_ty.pory"
	return
# 71 "data/scripts/gabby_and_ty.pory"

# 72 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_MoveForBattle9::
# 73 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_ShowAtRoute120_2
# 74 "data/scripts/gabby_and_ty.pory"
	call GabbyAndTy_EventScript_HideAtRoute118_3
# 75 "data/scripts/gabby_and_ty.pory"
	return
# 76 "data/scripts/gabby_and_ty.pory"

# 77 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_HideAtRoute111_1::
# 78 "data/scripts/gabby_and_ty.pory"
	setflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_1
# 79 "data/scripts/gabby_and_ty.pory"
	return
# 80 "data/scripts/gabby_and_ty.pory"

# 81 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_ShowAtRoute111_1::
# 82 "data/scripts/gabby_and_ty.pory"
	clearflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_1
# 83 "data/scripts/gabby_and_ty.pory"
	return
# 84 "data/scripts/gabby_and_ty.pory"

# 85 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_HideAtRoute118_1::
# 86 "data/scripts/gabby_and_ty.pory"
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_1
# 87 "data/scripts/gabby_and_ty.pory"
	return
# 88 "data/scripts/gabby_and_ty.pory"

# 89 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_ShowAtRoute118_1::
# 90 "data/scripts/gabby_and_ty.pory"
	clearflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_1
# 91 "data/scripts/gabby_and_ty.pory"
	return
# 92 "data/scripts/gabby_and_ty.pory"

# 93 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_HideAtRoute120_1::
# 94 "data/scripts/gabby_and_ty.pory"
	setflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_1
# 95 "data/scripts/gabby_and_ty.pory"
	return
# 96 "data/scripts/gabby_and_ty.pory"

# 97 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_ShowAtRoute120_1::
# 98 "data/scripts/gabby_and_ty.pory"
	clearflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_1
# 99 "data/scripts/gabby_and_ty.pory"
	return
# 100 "data/scripts/gabby_and_ty.pory"

# 101 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_HideAtRoute111_3::
# 102 "data/scripts/gabby_and_ty.pory"
	setflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_3
# 103 "data/scripts/gabby_and_ty.pory"
	return
# 104 "data/scripts/gabby_and_ty.pory"

# 105 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_ShowAtRoute111_3::
# 106 "data/scripts/gabby_and_ty.pory"
	clearflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_3
# 107 "data/scripts/gabby_and_ty.pory"
	return
# 108 "data/scripts/gabby_and_ty.pory"

# 109 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_HideAtRoute118_2::
# 110 "data/scripts/gabby_and_ty.pory"
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_2
# 111 "data/scripts/gabby_and_ty.pory"
	return
# 112 "data/scripts/gabby_and_ty.pory"

# 113 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_ShowAtRoute118_2::
# 114 "data/scripts/gabby_and_ty.pory"
	clearflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_2
# 115 "data/scripts/gabby_and_ty.pory"
	return
# 116 "data/scripts/gabby_and_ty.pory"

# 117 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_HideAtRoute120_2::
# 118 "data/scripts/gabby_and_ty.pory"
	setflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_2
# 119 "data/scripts/gabby_and_ty.pory"
	return
# 120 "data/scripts/gabby_and_ty.pory"

# 121 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_ShowAtRoute120_2::
# 122 "data/scripts/gabby_and_ty.pory"
	clearflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_2
# 123 "data/scripts/gabby_and_ty.pory"
	return
# 124 "data/scripts/gabby_and_ty.pory"

# 125 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_HideAtRoute111_2::
# 126 "data/scripts/gabby_and_ty.pory"
	setflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_2
# 127 "data/scripts/gabby_and_ty.pory"
	return
# 128 "data/scripts/gabby_and_ty.pory"

# 129 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_ShowAtRoute111_2::
# 130 "data/scripts/gabby_and_ty.pory"
	clearflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_2
# 131 "data/scripts/gabby_and_ty.pory"
	return
# 132 "data/scripts/gabby_and_ty.pory"

# 133 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_HideAtRoute118_3::
# 134 "data/scripts/gabby_and_ty.pory"
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_3
# 135 "data/scripts/gabby_and_ty.pory"
	return
# 136 "data/scripts/gabby_and_ty.pory"

# 137 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_ShowAtRoute118_3::
# 138 "data/scripts/gabby_and_ty.pory"
	clearflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_3
# 139 "data/scripts/gabby_and_ty.pory"
	return
# 140 "data/scripts/gabby_and_ty.pory"

# 141 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_GabbyBattle1::
# 142 "data/scripts/gabby_and_ty.pory"
	trainerbattle_double TRAINER_GABBY_AND_TY_1, GabbyAndTy_Text_GabbyPreFirstBattle, GabbyAndTy_Text_GabbyDefeatFirstTime, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_FirstInterview
# 143 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
# 144 "data/scripts/gabby_and_ty.pory"
	release
# 145 "data/scripts/gabby_and_ty.pory"
	end
# 146 "data/scripts/gabby_and_ty.pory"

# 147 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_TyBattle1::
# 148 "data/scripts/gabby_and_ty.pory"
	trainerbattle_double TRAINER_GABBY_AND_TY_1, GabbyAndTy_Text_TyPreFirstBattle, GabbyAndTy_Text_TyDefeatFirstTime, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_FirstInterview
# 149 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
# 150 "data/scripts/gabby_and_ty.pory"
	release
# 151 "data/scripts/gabby_and_ty.pory"
	end
# 152 "data/scripts/gabby_and_ty.pory"

# 153 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_GabbyBattle2::
# 154 "data/scripts/gabby_and_ty.pory"
	trainerbattle_double TRAINER_GABBY_AND_TY_2, GabbyAndTy_Text_GabbyIntro, GabbyAndTy_Text_GabbyDefeat, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
# 155 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
# 156 "data/scripts/gabby_and_ty.pory"
	release
# 157 "data/scripts/gabby_and_ty.pory"
	end
# 158 "data/scripts/gabby_and_ty.pory"

# 159 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_TyBattle2::
# 160 "data/scripts/gabby_and_ty.pory"
	trainerbattle_double TRAINER_GABBY_AND_TY_2, GabbyAndTy_Text_TyIntro, GabbyAndTy_Text_TyDefeat, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
# 161 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
# 162 "data/scripts/gabby_and_ty.pory"
	release
# 163 "data/scripts/gabby_and_ty.pory"
	end
# 164 "data/scripts/gabby_and_ty.pory"

# 165 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_GabbyBattle3::
# 166 "data/scripts/gabby_and_ty.pory"
	trainerbattle_double TRAINER_GABBY_AND_TY_3, GabbyAndTy_Text_GabbyIntro, GabbyAndTy_Text_GabbyDefeat, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
# 167 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
# 168 "data/scripts/gabby_and_ty.pory"
	release
# 169 "data/scripts/gabby_and_ty.pory"
	end
# 170 "data/scripts/gabby_and_ty.pory"

# 171 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_TyBattle3::
# 172 "data/scripts/gabby_and_ty.pory"
	trainerbattle_double TRAINER_GABBY_AND_TY_3, GabbyAndTy_Text_TyIntro, GabbyAndTy_Text_TyDefeat, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
# 173 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
# 174 "data/scripts/gabby_and_ty.pory"
	release
# 175 "data/scripts/gabby_and_ty.pory"
	end
# 176 "data/scripts/gabby_and_ty.pory"

# 177 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_GabbyBattle4::
# 178 "data/scripts/gabby_and_ty.pory"
	trainerbattle_double TRAINER_GABBY_AND_TY_4, GabbyAndTy_Text_GabbyIntro, GabbyAndTy_Text_GabbyDefeat, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
# 179 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
# 180 "data/scripts/gabby_and_ty.pory"
	release
# 181 "data/scripts/gabby_and_ty.pory"
	end
# 182 "data/scripts/gabby_and_ty.pory"

# 183 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_TyBattle4::
# 184 "data/scripts/gabby_and_ty.pory"
	trainerbattle_double TRAINER_GABBY_AND_TY_4, GabbyAndTy_Text_TyIntro, GabbyAndTy_Text_TyDefeat, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
# 185 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
# 186 "data/scripts/gabby_and_ty.pory"
	release
# 187 "data/scripts/gabby_and_ty.pory"
	end
# 188 "data/scripts/gabby_and_ty.pory"

# 189 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_GabbyBattle5::
# 190 "data/scripts/gabby_and_ty.pory"
	trainerbattle_double TRAINER_GABBY_AND_TY_5, GabbyAndTy_Text_GabbyIntro, GabbyAndTy_Text_GabbyDefeat, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
# 191 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
# 192 "data/scripts/gabby_and_ty.pory"
	release
# 193 "data/scripts/gabby_and_ty.pory"
	end
# 194 "data/scripts/gabby_and_ty.pory"

# 195 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_TyBattle5::
# 196 "data/scripts/gabby_and_ty.pory"
	trainerbattle_double TRAINER_GABBY_AND_TY_5, GabbyAndTy_Text_TyIntro, GabbyAndTy_Text_TyDefeat, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
# 197 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
# 198 "data/scripts/gabby_and_ty.pory"
	release
# 199 "data/scripts/gabby_and_ty.pory"
	end
# 200 "data/scripts/gabby_and_ty.pory"

# 201 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_GabbyBattle6::
# 202 "data/scripts/gabby_and_ty.pory"
	trainerbattle_double TRAINER_GABBY_AND_TY_6, GabbyAndTy_Text_GabbyIntro, GabbyAndTy_Text_GabbyDefeat, GabbyAndTy_Text_GabbyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
# 203 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
# 204 "data/scripts/gabby_and_ty.pory"
	release
# 205 "data/scripts/gabby_and_ty.pory"
	end
# 206 "data/scripts/gabby_and_ty.pory"

# 207 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_TyBattle6::
# 208 "data/scripts/gabby_and_ty.pory"
	trainerbattle_double TRAINER_GABBY_AND_TY_6, GabbyAndTy_Text_TyIntro, GabbyAndTy_Text_TyDefeat, GabbyAndTy_Text_TyNotEnoughMons, GabbyAndTy_EventScript_RequestInterview
# 209 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_TyPostBattle, MSGBOX_DEFAULT
# 210 "data/scripts/gabby_and_ty.pory"
	release
# 211 "data/scripts/gabby_and_ty.pory"
	end
# 212 "data/scripts/gabby_and_ty.pory"

# 213 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_FirstInterview::
# 214 "data/scripts/gabby_and_ty.pory"
	special GabbyAndTyBeforeInterview
# 215 "data/scripts/gabby_and_ty.pory"
	special GabbyAndTySetScriptVarsToObjectEventLocalIds
# 216 "data/scripts/gabby_and_ty.pory"
	compare VAR_FACING, DIR_NORTH
# 217 "data/scripts/gabby_and_ty.pory"
	call_if_eq GabbyAndTy_EventScript_FacePlayerNorth
# 218 "data/scripts/gabby_and_ty.pory"
	compare VAR_FACING, DIR_SOUTH
# 219 "data/scripts/gabby_and_ty.pory"
	call_if_eq GabbyAndTy_EventScript_FacePlayerSouth
# 220 "data/scripts/gabby_and_ty.pory"
	compare VAR_FACING, DIR_EAST
# 221 "data/scripts/gabby_and_ty.pory"
	call_if_eq GabbyAndTy_EventScript_FacePlayerEast
# 222 "data/scripts/gabby_and_ty.pory"
	goto_if_set FLAG_TEMP_1, GabbyAndTy_EventScript_KeepingAnEyeOutForYou
# 223 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_WhoAreYouInterview, MSGBOX_YESNO
# 224 "data/scripts/gabby_and_ty.pory"
	goto GabbyAndTy_EventScript_Interview
# 225 "data/scripts/gabby_and_ty.pory"
	end
# 226 "data/scripts/gabby_and_ty.pory"

# 227 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_FacePlayerNorth::
# 228 "data/scripts/gabby_and_ty.pory"
	applymovement VAR_0x8004, GabbyAndTy_Movement_WalkInPlaceDown
# 229 "data/scripts/gabby_and_ty.pory"
	waitmovement 0
# 230 "data/scripts/gabby_and_ty.pory"
	return
# 231 "data/scripts/gabby_and_ty.pory"

# 232 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_FacePlayerSouth::
# 233 "data/scripts/gabby_and_ty.pory"
	applymovement VAR_0x8004, GabbyAndTy_Movement_WalkInPlaceUp
# 234 "data/scripts/gabby_and_ty.pory"
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFastestUp
# 235 "data/scripts/gabby_and_ty.pory"
	waitmovement 0
# 236 "data/scripts/gabby_and_ty.pory"
	return
# 237 "data/scripts/gabby_and_ty.pory"

# 238 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_FacePlayerEast::
# 239 "data/scripts/gabby_and_ty.pory"
	applymovement VAR_0x8004, GabbyAndTy_Movement_WalkInPlaceLeft
# 240 "data/scripts/gabby_and_ty.pory"
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFastestLeft
# 241 "data/scripts/gabby_and_ty.pory"
	waitmovement 0
# 242 "data/scripts/gabby_and_ty.pory"
	return
# 243 "data/scripts/gabby_and_ty.pory"

# 244 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_RequestInterview::
# 245 "data/scripts/gabby_and_ty.pory"
	special GabbyAndTyBeforeInterview
# 246 "data/scripts/gabby_and_ty.pory"
	special GabbyAndTySetScriptVarsToObjectEventLocalIds
# 247 "data/scripts/gabby_and_ty.pory"
	compare VAR_FACING, DIR_NORTH
# 248 "data/scripts/gabby_and_ty.pory"
	call_if_eq GabbyAndTy_EventScript_FacePlayerNorth
# 249 "data/scripts/gabby_and_ty.pory"
	compare VAR_FACING, DIR_SOUTH
# 250 "data/scripts/gabby_and_ty.pory"
	call_if_eq GabbyAndTy_EventScript_FacePlayerSouth
# 251 "data/scripts/gabby_and_ty.pory"
	compare VAR_FACING, DIR_EAST
# 252 "data/scripts/gabby_and_ty.pory"
	call_if_eq GabbyAndTy_EventScript_FacePlayerEast
# 253 "data/scripts/gabby_and_ty.pory"
	goto_if_set FLAG_TEMP_1, GabbyAndTy_EventScript_KeepingAnEyeOutForYou
# 254 "data/scripts/gabby_and_ty.pory"
	specialvar VAR_RESULT, GabbyAndTyGetLastQuote
# 255 "data/scripts/gabby_and_ty.pory"
	compare VAR_RESULT, 0
# 256 "data/scripts/gabby_and_ty.pory"
	goto_if_eq GabbyAndTy_EventScript_DidntInterviewLastTime
# 257 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_QuoteFromLastInterview, MSGBOX_DEFAULT
# 258 "data/scripts/gabby_and_ty.pory"
	specialvar VAR_RESULT, GabbyAndTyGetLastBattleTrivia
# 259 "data/scripts/gabby_and_ty.pory"
	switch VAR_RESULT
# 260 "data/scripts/gabby_and_ty.pory"
	case 0, GabbyAndTy_EventScript_RequestInterviewNoTrivia
# 261 "data/scripts/gabby_and_ty.pory"
	case 1, GabbyAndTy_EventScript_RequestInterviewShortBattle
# 262 "data/scripts/gabby_and_ty.pory"
	case 2, GabbyAndTy_EventScript_RequestInterviewThrewBall
# 263 "data/scripts/gabby_and_ty.pory"
	case 3, GabbyAndTy_EventScript_RequestInterviewUsedItems
# 264 "data/scripts/gabby_and_ty.pory"
	case 4, GabbyAndTy_EventScript_RequestInterviewLostAMon
# 265 "data/scripts/gabby_and_ty.pory"
	end
# 266 "data/scripts/gabby_and_ty.pory"

# 267 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_Movement_WalkInPlaceDown:
# 268 "data/scripts/gabby_and_ty.pory"
	walk_in_place_down
# 269 "data/scripts/gabby_and_ty.pory"
	step_end
# 270 "data/scripts/gabby_and_ty.pory"

# 271 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_Movement_WalkInPlaceUp:
# 272 "data/scripts/gabby_and_ty.pory"
	walk_in_place_up
# 273 "data/scripts/gabby_and_ty.pory"
	step_end
# 274 "data/scripts/gabby_and_ty.pory"

# 275 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_Movement_WalkInPlaceLeft:
# 276 "data/scripts/gabby_and_ty.pory"
	walk_in_place_left
# 277 "data/scripts/gabby_and_ty.pory"
	step_end
# 278 "data/scripts/gabby_and_ty.pory"

# 279 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_DidntInterviewLastTime::
# 280 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_GiveUsAnInterviewThisTime, MSGBOX_YESNO
# 281 "data/scripts/gabby_and_ty.pory"
	goto GabbyAndTy_EventScript_Interview
# 282 "data/scripts/gabby_and_ty.pory"
	end
# 283 "data/scripts/gabby_and_ty.pory"

# 284 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_RequestInterviewNoTrivia::
# 285 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_InterviewAgain, MSGBOX_YESNO
# 286 "data/scripts/gabby_and_ty.pory"
	goto GabbyAndTy_EventScript_Interview
# 287 "data/scripts/gabby_and_ty.pory"
	end
# 288 "data/scripts/gabby_and_ty.pory"

# 289 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_RequestInterviewShortBattle::
# 290 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_YouStompedUsInterviewAgain, MSGBOX_YESNO
# 291 "data/scripts/gabby_and_ty.pory"
	goto GabbyAndTy_EventScript_Interview
# 292 "data/scripts/gabby_and_ty.pory"
	end
# 293 "data/scripts/gabby_and_ty.pory"

# 294 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_RequestInterviewThrewBall::
# 295 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_YouThrewABallAtUsInterviewAgain, MSGBOX_YESNO
# 296 "data/scripts/gabby_and_ty.pory"
	goto GabbyAndTy_EventScript_Interview
# 297 "data/scripts/gabby_and_ty.pory"
	end
# 298 "data/scripts/gabby_and_ty.pory"

# 299 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_RequestInterviewUsedItems::
# 300 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_CleverItemSkillsInterviewAgain, MSGBOX_YESNO
# 301 "data/scripts/gabby_and_ty.pory"
	goto GabbyAndTy_EventScript_Interview
# 302 "data/scripts/gabby_and_ty.pory"
	end
# 303 "data/scripts/gabby_and_ty.pory"

# 304 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_RequestInterviewLostAMon::
# 305 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_WeLookedRespectableInterviewAgain, MSGBOX_YESNO
# 306 "data/scripts/gabby_and_ty.pory"
	goto GabbyAndTy_EventScript_Interview
# 307 "data/scripts/gabby_and_ty.pory"
	end
# 308 "data/scripts/gabby_and_ty.pory"

# 309 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_Interview::
# 310 "data/scripts/gabby_and_ty.pory"
	compare VAR_RESULT, NO
# 311 "data/scripts/gabby_and_ty.pory"
	goto_if_eq GabbyAndTy_EventScript_DontGiveUpKeepingEyeOut
# 312 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_DescribeYourFeelings, MSGBOX_DEFAULT
# 313 "data/scripts/gabby_and_ty.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_GABBY_AND_TY
# 314 "data/scripts/gabby_and_ty.pory"
	call Common_ShowEasyChatScreen
# 315 "data/scripts/gabby_and_ty.pory"
	lock
# 316 "data/scripts/gabby_and_ty.pory"
	faceplayer
# 317 "data/scripts/gabby_and_ty.pory"
	compare VAR_RESULT, 0
# 318 "data/scripts/gabby_and_ty.pory"
	goto_if_eq GabbyAndTy_EventScript_DontGiveUpKeepingEyeOut
# 319 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_PerfectWellBeSeeingYou, MSGBOX_DEFAULT
# 320 "data/scripts/gabby_and_ty.pory"
	special GabbyAndTyAfterInterview
# 321 "data/scripts/gabby_and_ty.pory"
	setflag FLAG_TEMP_1
# 322 "data/scripts/gabby_and_ty.pory"
	release
# 323 "data/scripts/gabby_and_ty.pory"
	end
# 324 "data/scripts/gabby_and_ty.pory"

# 325 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_DontGiveUpKeepingEyeOut::
# 326 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_DontGiveUpKeepingEyeOut, MSGBOX_DEFAULT
# 327 "data/scripts/gabby_and_ty.pory"
	setflag FLAG_TEMP_1
# 328 "data/scripts/gabby_and_ty.pory"
	release
# 329 "data/scripts/gabby_and_ty.pory"
	end
# 330 "data/scripts/gabby_and_ty.pory"

# 331 "data/scripts/gabby_and_ty.pory"
GabbyAndTy_EventScript_KeepingAnEyeOutForYou::
# 332 "data/scripts/gabby_and_ty.pory"
	msgbox GabbyAndTy_Text_KeepingAnEyeOutForYou, MSGBOX_DEFAULT
# 333 "data/scripts/gabby_and_ty.pory"
	release
# 334 "data/scripts/gabby_and_ty.pory"
	end
