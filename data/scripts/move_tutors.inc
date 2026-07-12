# 1 "data/scripts/move_tutors.pory"

# 2 "data/scripts/move_tutors.pory"
SlateportCity_PokemonFanClub_EventScript_SwaggerTutor::
# 3 "data/scripts/move_tutors.pory"
	lock
# 4 "data/scripts/move_tutors.pory"
	faceplayer
# 5 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SwaggerTeach, MSGBOX_YESNO
# 6 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 7 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_SwaggerDeclined
# 8 "data/scripts/move_tutors.pory"
	//
# 9 "data/scripts/move_tutors.pory"
	checkitem ITEM_HEART_SCALE, 1
# 10 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, FALSE
# 11 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_NoHeartScale
# 12 "data/scripts/move_tutors.pory"
	//
# 13 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 14 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 15 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_SwaggerDeclined
# 16 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SwaggerWhichMon, MSGBOX_DEFAULT
# 17 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, TUTOR_MOVE_SWAGGER
# 18 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 19 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, 0
# 20 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_SwaggerDeclined
# 21 "data/scripts/move_tutors.pory"
	removeitem ITEM_HEART_SCALE
# 22 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_SwaggerTaught
# 23 "data/scripts/move_tutors.pory"
	end
# 24 "data/scripts/move_tutors.pory"

# 25 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_NoHeartScale::
# 26 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_NoHeartScale, MSGBOX_DEFAULT
# 27 "data/scripts/move_tutors.pory"
	release
# 28 "data/scripts/move_tutors.pory"
	end
# 29 "data/scripts/move_tutors.pory"

# 30 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_SwaggerDeclined::
# 31 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SwaggerDeclined, MSGBOX_DEFAULT
# 32 "data/scripts/move_tutors.pory"
	release
# 33 "data/scripts/move_tutors.pory"
	end
# 34 "data/scripts/move_tutors.pory"

# 35 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_SwaggerTaught::
# 36 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SwaggerTaught, MSGBOX_DEFAULT
# 37 "data/scripts/move_tutors.pory"
	release
# 38 "data/scripts/move_tutors.pory"
	end
# 39 "data/scripts/move_tutors.pory"

# 40 "data/scripts/move_tutors.pory"
MauvilleCity_EventScript_RolloutTutor::
# 41 "data/scripts/move_tutors.pory"
	lock
# 42 "data/scripts/move_tutors.pory"
	faceplayer
# 43 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_RolloutTeach, MSGBOX_YESNO
# 44 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 45 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_RolloutDeclined
# 46 "data/scripts/move_tutors.pory"
	//
# 47 "data/scripts/move_tutors.pory"
	checkitem ITEM_HEART_SCALE, 1
# 48 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, FALSE
# 49 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_NoHeartScale
# 50 "data/scripts/move_tutors.pory"
	//
# 51 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 52 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 53 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_RolloutDeclined
# 54 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_RolloutWhichMon, MSGBOX_DEFAULT
# 55 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, TUTOR_MOVE_ROLLOUT
# 56 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 57 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, 0
# 58 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_RolloutDeclined
# 59 "data/scripts/move_tutors.pory"
	removeitem ITEM_HEART_SCALE
# 60 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_RolloutTaught
# 61 "data/scripts/move_tutors.pory"
	end
# 62 "data/scripts/move_tutors.pory"

# 63 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_RolloutDeclined::
# 64 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_RolloutDeclined, MSGBOX_DEFAULT
# 65 "data/scripts/move_tutors.pory"
	release
# 66 "data/scripts/move_tutors.pory"
	end
# 67 "data/scripts/move_tutors.pory"

# 68 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_RolloutTaught::
# 69 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_RolloutTaught, MSGBOX_DEFAULT
# 70 "data/scripts/move_tutors.pory"
	release
# 71 "data/scripts/move_tutors.pory"
	end
# 72 "data/scripts/move_tutors.pory"

# 73 "data/scripts/move_tutors.pory"
VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor::
# 74 "data/scripts/move_tutors.pory"
	lock
# 75 "data/scripts/move_tutors.pory"
	faceplayer
# 76 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_FuryCutterTeach, MSGBOX_YESNO
# 77 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 78 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_FuryCutterDeclined
# 79 "data/scripts/move_tutors.pory"
	//
# 80 "data/scripts/move_tutors.pory"
	checkitem ITEM_HEART_SCALE, 1
# 81 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, FALSE
# 82 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_NoHeartScale
# 83 "data/scripts/move_tutors.pory"
	//
# 84 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 85 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 86 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_FuryCutterDeclined
# 87 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_FuryCutterWhichMon, MSGBOX_DEFAULT
# 88 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, TUTOR_MOVE_FURY_CUTTER
# 89 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 90 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, 0
# 91 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_FuryCutterDeclined
# 92 "data/scripts/move_tutors.pory"
	removeitem ITEM_HEART_SCALE
# 93 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_FuryCutterTaught
# 94 "data/scripts/move_tutors.pory"
	end
# 95 "data/scripts/move_tutors.pory"

# 96 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_FuryCutterDeclined::
# 97 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_FuryCutterDeclined, MSGBOX_DEFAULT
# 98 "data/scripts/move_tutors.pory"
	release
# 99 "data/scripts/move_tutors.pory"
	end
# 100 "data/scripts/move_tutors.pory"

# 101 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_FuryCutterTaught::
# 102 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_FuryCutterTaught, MSGBOX_DEFAULT
# 103 "data/scripts/move_tutors.pory"
	release
# 104 "data/scripts/move_tutors.pory"
	end
# 105 "data/scripts/move_tutors.pory"

# 106 "data/scripts/move_tutors.pory"
LavaridgeTown_House_EventScript_MimicTutor::
# 107 "data/scripts/move_tutors.pory"
	lock
# 108 "data/scripts/move_tutors.pory"
	faceplayer
# 109 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_MimicTeach, MSGBOX_YESNO
# 110 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 111 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_MimicDeclined
# 112 "data/scripts/move_tutors.pory"
	//
# 113 "data/scripts/move_tutors.pory"
	checkitem ITEM_HEART_SCALE, 1
# 114 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, FALSE
# 115 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_NoHeartScale
# 116 "data/scripts/move_tutors.pory"
	//
# 117 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 118 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 119 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_MimicDeclined
# 120 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_MimicWhichMon, MSGBOX_DEFAULT
# 121 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, TUTOR_MOVE_MIMIC
# 122 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 123 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, 0
# 124 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_MimicDeclined
# 125 "data/scripts/move_tutors.pory"
	removeitem ITEM_HEART_SCALE
# 126 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_MimicTaught
# 127 "data/scripts/move_tutors.pory"
	end
# 128 "data/scripts/move_tutors.pory"

# 129 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_MimicDeclined::
# 130 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_MimicDeclined, MSGBOX_DEFAULT
# 131 "data/scripts/move_tutors.pory"
	release
# 132 "data/scripts/move_tutors.pory"
	end
# 133 "data/scripts/move_tutors.pory"

# 134 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_MimicTaught::
# 135 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_MimicTaught, MSGBOX_DEFAULT
# 136 "data/scripts/move_tutors.pory"
	release
# 137 "data/scripts/move_tutors.pory"
	end
# 138 "data/scripts/move_tutors.pory"

# 139 "data/scripts/move_tutors.pory"
FallarborTown_Mart_EventScript_MetronomeTutor::
# 140 "data/scripts/move_tutors.pory"
	lock
# 141 "data/scripts/move_tutors.pory"
	faceplayer
# 142 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_MetronomeTeach, MSGBOX_YESNO
# 143 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 144 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_MetronomeDeclined
# 145 "data/scripts/move_tutors.pory"
	//
# 146 "data/scripts/move_tutors.pory"
	checkitem ITEM_HEART_SCALE, 1
# 147 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, FALSE
# 148 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_NoHeartScale
# 149 "data/scripts/move_tutors.pory"
	//
# 150 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 151 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 152 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_MetronomeDeclined
# 153 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_MetronomeWhichMon, MSGBOX_DEFAULT
# 154 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, TUTOR_MOVE_METRONOME
# 155 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 156 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, 0
# 157 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_MetronomeDeclined
# 158 "data/scripts/move_tutors.pory"
	removeitem ITEM_HEART_SCALE
# 159 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_MetronomeTaught
# 160 "data/scripts/move_tutors.pory"
	end
# 161 "data/scripts/move_tutors.pory"

# 162 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_MetronomeDeclined::
# 163 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_MetronomeDeclined, MSGBOX_DEFAULT
# 164 "data/scripts/move_tutors.pory"
	release
# 165 "data/scripts/move_tutors.pory"
	end
# 166 "data/scripts/move_tutors.pory"

# 167 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_MetronomeTaught::
# 168 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_MetronomeTaught, MSGBOX_DEFAULT
# 169 "data/scripts/move_tutors.pory"
	release
# 170 "data/scripts/move_tutors.pory"
	end
# 171 "data/scripts/move_tutors.pory"

# 172 "data/scripts/move_tutors.pory"
FortreeCity_House2_EventScript_SleepTalkTutor::
# 173 "data/scripts/move_tutors.pory"
	lock
# 174 "data/scripts/move_tutors.pory"
	faceplayer
# 175 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SleepTalkTeach, MSGBOX_YESNO
# 176 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 177 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_SleepTalkDeclined
# 178 "data/scripts/move_tutors.pory"
	//
# 179 "data/scripts/move_tutors.pory"
	checkitem ITEM_HEART_SCALE, 1
# 180 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, FALSE
# 181 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_NoHeartScale
# 182 "data/scripts/move_tutors.pory"
	//
# 183 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 184 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 185 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_SleepTalkDeclined
# 186 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SleepTalkWhichMon, MSGBOX_DEFAULT
# 187 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, TUTOR_MOVE_SLEEP_TALK
# 188 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 189 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, 0
# 190 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_SleepTalkDeclined
# 191 "data/scripts/move_tutors.pory"
	removeitem ITEM_HEART_SCALE
# 192 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_SleepTalkTaught
# 193 "data/scripts/move_tutors.pory"
	end
# 194 "data/scripts/move_tutors.pory"

# 195 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_SleepTalkDeclined::
# 196 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SleepTalkDeclined, MSGBOX_DEFAULT
# 197 "data/scripts/move_tutors.pory"
	release
# 198 "data/scripts/move_tutors.pory"
	end
# 199 "data/scripts/move_tutors.pory"

# 200 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_SleepTalkTaught::
# 201 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SleepTalkTaught, MSGBOX_DEFAULT
# 202 "data/scripts/move_tutors.pory"
	release
# 203 "data/scripts/move_tutors.pory"
	end
# 204 "data/scripts/move_tutors.pory"

# 205 "data/scripts/move_tutors.pory"
LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTutor::
# 206 "data/scripts/move_tutors.pory"
	lock
# 207 "data/scripts/move_tutors.pory"
	faceplayer
# 208 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SubstituteTeach, MSGBOX_YESNO
# 209 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 210 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_SubstituteDeclined
# 211 "data/scripts/move_tutors.pory"
	//
# 212 "data/scripts/move_tutors.pory"
	checkitem ITEM_HEART_SCALE, 1
# 213 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, FALSE
# 214 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_NoHeartScale
# 215 "data/scripts/move_tutors.pory"
	//
# 216 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 217 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 218 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_SubstituteDeclined
# 219 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SubstituteWhichMon, MSGBOX_DEFAULT
# 220 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, TUTOR_MOVE_SUBSTITUTE
# 221 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 222 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, 0
# 223 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_SubstituteDeclined
# 224 "data/scripts/move_tutors.pory"
	removeitem ITEM_HEART_SCALE
# 225 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_SubstituteTaught
# 226 "data/scripts/move_tutors.pory"
	end
# 227 "data/scripts/move_tutors.pory"

# 228 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_SubstituteDeclined::
# 229 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SubstituteDeclined, MSGBOX_DEFAULT
# 230 "data/scripts/move_tutors.pory"
	release
# 231 "data/scripts/move_tutors.pory"
	end
# 232 "data/scripts/move_tutors.pory"

# 233 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_SubstituteTaught::
# 234 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_SubstituteTaught, MSGBOX_DEFAULT
# 235 "data/scripts/move_tutors.pory"
	release
# 236 "data/scripts/move_tutors.pory"
	end
# 237 "data/scripts/move_tutors.pory"

# 238 "data/scripts/move_tutors.pory"
MossdeepCity_EventScript_DynamicPunchTutor::
# 239 "data/scripts/move_tutors.pory"
	lock
# 240 "data/scripts/move_tutors.pory"
	faceplayer
# 241 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DynamicPunchTeach, MSGBOX_YESNO
# 242 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 243 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_DynamicPunchDeclined
# 244 "data/scripts/move_tutors.pory"
	//
# 245 "data/scripts/move_tutors.pory"
	checkitem ITEM_HEART_SCALE, 1
# 246 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, FALSE
# 247 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_NoHeartScale
# 248 "data/scripts/move_tutors.pory"
	//
# 249 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 250 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 251 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_DynamicPunchDeclined
# 252 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DynamicPunchWhichMon, MSGBOX_DEFAULT
# 253 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, TUTOR_MOVE_DYNAMIC_PUNCH
# 254 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 255 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, 0
# 256 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_DynamicPunchDeclined
# 257 "data/scripts/move_tutors.pory"
	removeitem ITEM_HEART_SCALE
# 258 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_DynamicPunchTaught
# 259 "data/scripts/move_tutors.pory"
	end
# 260 "data/scripts/move_tutors.pory"

# 261 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_DynamicPunchDeclined::
# 262 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DynamicPunchDeclined, MSGBOX_DEFAULT
# 263 "data/scripts/move_tutors.pory"
	release
# 264 "data/scripts/move_tutors.pory"
	end
# 265 "data/scripts/move_tutors.pory"

# 266 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_DynamicPunchTaught::
# 267 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DynamicPunchTaught, MSGBOX_DEFAULT
# 268 "data/scripts/move_tutors.pory"
	release
# 269 "data/scripts/move_tutors.pory"
	end
# 270 "data/scripts/move_tutors.pory"

# 271 "data/scripts/move_tutors.pory"
SootopolisCity_PokemonCenter_1F_EventScript_DoubleEdgeTutor::
# 272 "data/scripts/move_tutors.pory"
	lock
# 273 "data/scripts/move_tutors.pory"
	faceplayer
# 274 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DoubleEdgeTeach, MSGBOX_YESNO
# 275 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 276 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_DoubleEdgeDeclined
# 277 "data/scripts/move_tutors.pory"
	//
# 278 "data/scripts/move_tutors.pory"
	checkitem ITEM_HEART_SCALE, 1
# 279 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, FALSE
# 280 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_NoHeartScale
# 281 "data/scripts/move_tutors.pory"
	//
# 282 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
# 283 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, NO
# 284 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_DoubleEdgeDeclined
# 285 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DoubleEdgeWhichMon, MSGBOX_DEFAULT
# 286 "data/scripts/move_tutors.pory"
	setvar VAR_0x8005, TUTOR_MOVE_DOUBLE_EDGE
# 287 "data/scripts/move_tutors.pory"
	call MoveTutor_EventScript_OpenPartyMenu
# 288 "data/scripts/move_tutors.pory"
	compare VAR_RESULT, 0
# 289 "data/scripts/move_tutors.pory"
	goto_if_eq MoveTutor_EventScript_DoubleEdgeDeclined
# 290 "data/scripts/move_tutors.pory"
	removeitem ITEM_HEART_SCALE
# 291 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_DoubleEdgeTaught
# 292 "data/scripts/move_tutors.pory"
	end
# 293 "data/scripts/move_tutors.pory"

# 294 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_DoubleEdgeDeclined::
# 295 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DoubleEdgeDeclined, MSGBOX_DEFAULT
# 296 "data/scripts/move_tutors.pory"
	release
# 297 "data/scripts/move_tutors.pory"
	end
# 298 "data/scripts/move_tutors.pory"

# 299 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_DoubleEdgeTaught::
# 300 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_DoubleEdgeTaught, MSGBOX_DEFAULT
# 301 "data/scripts/move_tutors.pory"
	release
# 302 "data/scripts/move_tutors.pory"
	end
# 303 "data/scripts/move_tutors.pory"

# 304 "data/scripts/move_tutors.pory"
PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTutor::
# 305 "data/scripts/move_tutors.pory"
	lock
# 306 "data/scripts/move_tutors.pory"
	faceplayer
# 307 "data/scripts/move_tutors.pory"
	goto_if_set FLAG_RECEIVED_PACIFIDLOG_TM_EXPLOSION, MoveTutor_EventScript_ExplosionTaught
# 308 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_ExplosionTeach, MSGBOX_DEFAULT
# 309 "data/scripts/move_tutors.pory"
	giveitem ITEM_TM64
# 310 "data/scripts/move_tutors.pory"
	setflag FLAG_RECEIVED_PACIFIDLOG_TM_EXPLOSION
# 311 "data/scripts/move_tutors.pory"
	goto MoveTutor_EventScript_ExplosionTaught
# 312 "data/scripts/move_tutors.pory"
	end
# 313 "data/scripts/move_tutors.pory"

# 314 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_ExplosionTaught::
# 315 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_ExplosionTaught, MSGBOX_DEFAULT
# 316 "data/scripts/move_tutors.pory"
	release
# 317 "data/scripts/move_tutors.pory"
	end
# 318 "data/scripts/move_tutors.pory"

# 319 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_OpenPartyMenu::
# 320 "data/scripts/move_tutors.pory"
	special ChooseMonForMoveTutor
# 321 "data/scripts/move_tutors.pory"
	waitstate
# 322 "data/scripts/move_tutors.pory"
	lock
# 323 "data/scripts/move_tutors.pory"
	faceplayer
# 324 "data/scripts/move_tutors.pory"
	return
# 325 "data/scripts/move_tutors.pory"

# 326 "data/scripts/move_tutors.pory"
MoveTutor_EventScript_CanOnlyBeLearnedOnce::
# 327 "data/scripts/move_tutors.pory"
	msgbox MoveTutor_Text_ThisMoveCanOnlyBeLearnedOnce, MSGBOX_YESNO
# 328 "data/scripts/move_tutors.pory"
	return
