Common_EventScript_PkmnCenterNurse::
# 5 "data/scripts/pkmn_center_nurse.pory"
	lock
# 6 "data/scripts/pkmn_center_nurse.pory"
	setvar VAR_ENDLESS_BATTLE_CURE_TYPE, 0
# 8 "data/scripts/pkmn_center_nurse.pory"
	incrementgamestat GAME_STAT_USED_POKECENTER
# 9 "data/scripts/pkmn_center_nurse.pory"
	message Common_EventScript_PkmnCenterNurse_Text_0
# 10 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 11 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFastestLeft
# 12 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 13 "data/scripts/pkmn_center_nurse.pory"
	dofieldeffect FLDEFF_POKECENTER_HEAL
# 14 "data/scripts/pkmn_center_nurse.pory"
	special HealPlayerParty
# 15 "data/scripts/pkmn_center_nurse.pory"
	waitfieldeffect FLDEFF_POKECENTER_HEAL
# 16 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFastestDown
# 17 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 18 "data/scripts/pkmn_center_nurse.pory"
	goto_if_unset FLAG_ASKED_NO_CUSTOM_FORMS, Common_EventScript_PkmnCenterNurse_2
Common_EventScript_PkmnCenterNurse_1:
# 55 "data/scripts/pkmn_center_nurse.pory"
	message Common_EventScript_PkmnCenterNurse_Text_10
# 56 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 57 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_EventScript_PkmnCenterNurse_Movement_0
# 58 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 59 "data/scripts/pkmn_center_nurse.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_EventScript_PkmnCenterNurse_Movement_1
# 60 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 61 "data/scripts/pkmn_center_nurse.pory"
	release
	end

Common_EventScript_PkmnCenterNurse_2:
# 19 "data/scripts/pkmn_center_nurse.pory"
	setflag FLAG_ASKED_NO_CUSTOM_FORMS
# 20 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_1, MSGBOX_DEFAULT
# 21 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_2, MSGBOX_DEFAULT
# 22 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_3, MSGBOX_DEFAULT
# 23 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_4, MSGBOX_YESNO
# 24 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterNurse_4
# 37 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_8, MSGBOX_YESNO
# 38 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterNurse_10
# 42 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_5, MSGBOX_YESNO
# 43 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterNurse_13
# 50 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_9, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterNurse_1

Common_EventScript_PkmnCenterNurse_4:
# 25 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_5, MSGBOX_YESNO
# 26 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterNurse_7
# 33 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_7, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterNurse_1

Common_EventScript_PkmnCenterNurse_7:
# 27 "data/scripts/pkmn_center_nurse.pory"
	setflag FLAG_NO_CUSTOM_FORMS_MODE
# 28 "data/scripts/pkmn_center_nurse.pory"
	playfanfare SE_SAVE
# 29 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_6, MSGBOX_DEFAULT
# 30 "data/scripts/pkmn_center_nurse.pory"
	waitfanfare
	goto Common_EventScript_PkmnCenterNurse_1

Common_EventScript_PkmnCenterNurse_10:
# 39 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_9, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterNurse_1

Common_EventScript_PkmnCenterNurse_13:
# 44 "data/scripts/pkmn_center_nurse.pory"
	setflag FLAG_NO_CUSTOM_FORMS_MODE
# 45 "data/scripts/pkmn_center_nurse.pory"
	playfanfare SE_SAVE
# 46 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_6, MSGBOX_DEFAULT
# 47 "data/scripts/pkmn_center_nurse.pory"
	waitfanfare
	goto Common_EventScript_PkmnCenterNurse_1


Common_EventScript_PkmnCenterNurse_Old::
# 66 "data/scripts/pkmn_center_nurse.pory"
	lock
# 67 "data/scripts/pkmn_center_nurse.pory"
	setvar VAR_0x8004, 0
# 68 "data/scripts/pkmn_center_nurse.pory"
	setvar VAR_ENDLESS_BATTLE_CURE_TYPE, 0
# 69 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, CountPlayerTrainerStars
# 70 "data/scripts/pkmn_center_nurse.pory"
	incrementgamestat GAME_STAT_USED_POKECENTER
# 72 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 4
	goto_if_eq Common_EventScript_PkmnCenterNurse_Old_2
Common_EventScript_PkmnCenterNurse_Old_1:
# 76 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Old_Text_0
# 78 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFastestLeft
# 79 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 81 "data/scripts/pkmn_center_nurse.pory"
	dofieldeffect FLDEFF_POKECENTER_HEAL
# 82 "data/scripts/pkmn_center_nurse.pory"
	special HealPlayerParty
# 83 "data/scripts/pkmn_center_nurse.pory"
	waitfieldeffect FLDEFF_POKECENTER_HEAL
# 85 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFastestDown
# 86 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 87 "data/scripts/pkmn_center_nurse.pory"
	goto_if_unset FLAG_POKERUS_EXPLAINED, Common_EventScript_PkmnCenterNurse_Old_5
# 97 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_0x8004, 1
	goto_if_eq Common_EventScript_PkmnCenterNurse_Old_6
Common_EventScript_PkmnCenterNurse_Old_4:
# 101 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, EventScript_PkmnCenterNurse_Bow
# 102 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 104 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_10
# 105 "data/scripts/pkmn_center_nurse.pory"
	closemessage
# 107 "data/scripts/pkmn_center_nurse.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 108 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 109 "data/scripts/pkmn_center_nurse.pory"
	release
	end

Common_EventScript_PkmnCenterNurse_Old_2:
# 73 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_GoldCard
	goto Common_EventScript_PkmnCenterNurse_Old_1

Common_EventScript_PkmnCenterNurse_Old_5:
# 88 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, IsPokerusInParty
# 90 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_PkmnCenterNurse_Old_9
# 94 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_ReturnPkmn
	goto Common_EventScript_PkmnCenterNurse_Old_4

Common_EventScript_PkmnCenterNurse_Old_6:
# 98 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_ReturnPkmn2
	goto Common_EventScript_PkmnCenterNurse_Old_4

Common_EventScript_PkmnCenterNurse_Old_9:
# 91 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_ExplainPokerus
	goto Common_EventScript_PkmnCenterNurse_Old_4


EventScript_PkmnCenterNurse_Goodbye::
# 114 "data/scripts/pkmn_center_nurse.pory"
	msgbox Common_EventScript_PkmnCenterNurse_Text_10
	return


EventScript_PkmnCenterNurse_HealPkmn::
# 120 "data/scripts/pkmn_center_nurse.pory"
	incrementgamestat GAME_STAT_USED_POKECENTER
# 121 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_0x8004, 0
	goto_if_eq EventScript_PkmnCenterNurse_HealPkmn_2
# 125 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_IllTakeYourPkmn2
EventScript_PkmnCenterNurse_HealPkmn_1:
# 127 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 128 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFastestLeft
# 129 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 130 "data/scripts/pkmn_center_nurse.pory"
	dofieldeffect FLDEFF_POKECENTER_HEAL
# 131 "data/scripts/pkmn_center_nurse.pory"
	special HealPlayerParty
# 132 "data/scripts/pkmn_center_nurse.pory"
	waitfieldeffect FLDEFF_POKECENTER_HEAL
# 133 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFastestDown
# 134 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 135 "data/scripts/pkmn_center_nurse.pory"
	goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_HealPkmn_6
EventScript_PkmnCenterNurse_HealPkmn_5:
# 138 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_ReturnPkmn
	return

EventScript_PkmnCenterNurse_HealPkmn_2:
# 122 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_IllTakeYourPkmn
	goto EventScript_PkmnCenterNurse_HealPkmn_1

EventScript_PkmnCenterNurse_HealPkmn_6:
# 136 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_CheckPokerus
	goto EventScript_PkmnCenterNurse_HealPkmn_5


EventScript_PkmnCenterNurse_TakeAndHealPkmn::
# 142 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFastestLeft
# 143 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 144 "data/scripts/pkmn_center_nurse.pory"
	dofieldeffect FLDEFF_POKECENTER_HEAL
# 145 "data/scripts/pkmn_center_nurse.pory"
	waitfieldeffect FLDEFF_POKECENTER_HEAL
# 146 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFastestDown
# 147 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 148 "data/scripts/pkmn_center_nurse.pory"
	special HealPlayerParty
	return


EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom::
# 153 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
# 154 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, 0
	goto_if_eq EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_2
EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_1:
# 157 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
# 158 "data/scripts/pkmn_center_nurse.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 159 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_0x8008, 0
	goto_if_eq EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_5
EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_4:
# 162 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_0x8008, 1
	goto_if_eq EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_7
	return

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_2:
# 155 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_ReturnPkmn
	goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_1

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_5:
# 160 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_ReturnPkmn
	goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_4

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom_7:
# 163 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
	return


EventScript_PkmnCenterNurse_ReturnPkmn::
# 169 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_0x8004, 1
	goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn_2
EventScript_PkmnCenterNurse_ReturnPkmn_1:
# 174 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, EventScript_PkmnCenterNurse_Bow
# 175 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 176 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_WeHopeToSeeYouAgain
# 177 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_PlayerTurn
	return

EventScript_PkmnCenterNurse_ReturnPkmn_2:
# 170 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_ReturnPkmn2
	goto EventScript_PkmnCenterNurse_ReturnPkmn_1


# 181 "data/scripts/pkmn_center_nurse.pory"
PkmnCenterNurse_Movement_FaceDown:
# 182 "data/scripts/pkmn_center_nurse.pory"
	face_down
	step_end

EventScript_PkmnCenterNurse_ReturnPkmn2::
# 186 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_PlayerTurn
	return


EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
# 190 "data/scripts/pkmn_center_nurse.pory"
	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_2
EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_1:
# 193 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
# 194 "data/scripts/pkmn_center_nurse.pory"
	setflag FLAG_NURSE_UNION_ROOM_REMINDER
# 195 "data/scripts/pkmn_center_nurse.pory"
	msgbox CableClub_Text_PlayerIsWaiting
# 196 "data/scripts/pkmn_center_nurse.pory"
	waitmessage
# 197 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, EventScript_PkmnCenterNurse_Bow
# 198 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 199 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_2:
# 191 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_ReturnPkmn
	goto EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_1


EventScript_PkmnCenterNurse_CheckPokerus::
# 204 "data/scripts/pkmn_center_nurse.pory"
	specialvar VAR_RESULT, IsPokerusInParty
# 205 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_PkmnCenterNurse_CheckPokerus_2
EventScript_PkmnCenterNurse_CheckPokerus_1:
# 208 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_PkmnCenterNurse_CheckPokerus_4
	return

EventScript_PkmnCenterNurse_CheckPokerus_2:
# 206 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_ExplainPokerus
	goto EventScript_PkmnCenterNurse_CheckPokerus_1

EventScript_PkmnCenterNurse_CheckPokerus_4:
# 209 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_ReturnPkmn
	return


EventScript_PkmnCenterNurse_ExplainPokerus::
# 214 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_PokerusExplanation
# 215 "data/scripts/pkmn_center_nurse.pory"
	setflag FLAG_POKERUS_EXPLAINED
	return


EventScript_PkmnCenterNurse_GoldCard::
# 220 "data/scripts/pkmn_center_nurse.pory"
	goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_GoldCard_2
EventScript_PkmnCenterNurse_GoldCard_1:
# 223 "data/scripts/pkmn_center_nurse.pory"
	setflag FLAG_NURSE_MENTIONS_GOLD_CARD
# 224 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
# 225 "data/scripts/pkmn_center_nurse.pory"
	playse SE_PIN
# 226 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_ExclamationMark
# 227 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 228 "data/scripts/pkmn_center_nurse.pory"
	applymovement VAR_0x800B, Common_Movement_Delay48
# 229 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 230 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_NoticesGoldCard, MSGBOX_YESNO
# 231 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_PkmnCenterNurse_GoldCard_5
EventScript_PkmnCenterNurse_GoldCard_4:
# 234 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_GoldCard_2:
# 221 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_AskForUsual
	goto EventScript_PkmnCenterNurse_GoldCard_1

EventScript_PkmnCenterNurse_GoldCard_5:
# 232 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_GoldCardHealPkmn
	goto EventScript_PkmnCenterNurse_GoldCard_4


EventScript_PkmnCenterNurse_AskForUsual::
# 239 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_YouWantTheUsual, MSGBOX_YESNO
# 240 "data/scripts/pkmn_center_nurse.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_PkmnCenterNurse_AskForUsual_2
EventScript_PkmnCenterNurse_AskForUsual_1:
# 243 "data/scripts/pkmn_center_nurse.pory"
	msgbox gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_AskForUsual_2:
# 241 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_GoldCardHealPkmn
	goto EventScript_PkmnCenterNurse_AskForUsual_1


EventScript_PkmnCenterNurse_GoldCardHealPkmn::
# 248 "data/scripts/pkmn_center_nurse.pory"
	setvar VAR_0x8004, 1
# 249 "data/scripts/pkmn_center_nurse.pory"
	goto EventScript_PkmnCenterNurse_HealPkmn
	return


# 252 "data/scripts/pkmn_center_nurse.pory"
EventScript_PkmnCenterNurse_Bow:
# 253 "data/scripts/pkmn_center_nurse.pory"
	nurse_joy_bow
# 254 "data/scripts/pkmn_center_nurse.pory"
	delay_4
	step_end

EventScript_PkmnCenterNurse_PlayerTurn::
# 258 "data/scripts/pkmn_center_nurse.pory"
	closemessage
# 259 "data/scripts/pkmn_center_nurse.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 260 "data/scripts/pkmn_center_nurse.pory"
	waitmovement 0
# 261 "data/scripts/pkmn_center_nurse.pory"
	release
	return


# 57 "data/scripts/pkmn_center_nurse.pory"
Common_EventScript_PkmnCenterNurse_Movement_0:
# 57 "data/scripts/pkmn_center_nurse.pory"
	nurse_joy_bow
# 57 "data/scripts/pkmn_center_nurse.pory"
	delay_4
	step_end

# 59 "data/scripts/pkmn_center_nurse.pory"
Common_EventScript_PkmnCenterNurse_Movement_1:
# 59 "data/scripts/pkmn_center_nurse.pory"
	face_down
	step_end

Common_EventScript_PkmnCenterNurse_Text_0:
# 9 "data/scripts/pkmn_center_nurse.pory"
	.string "Welcome, I'll take your Pokémon for a\n"
	.string "few seconds to heal them.$"

Common_EventScript_PkmnCenterNurse_Text_1:
# 20 "data/scripts/pkmn_center_nurse.pory"
	.string "By the way, a new option has been\n"
	.string "added!\n"
	.string "It's called {COLOR BLUE}No Custom Forms Mode{COLOR DARK_GREY}.$"

Common_EventScript_PkmnCenterNurse_Text_2:
# 21 "data/scripts/pkmn_center_nurse.pory"
	.string "It removes custom Pokémon forms that\n"
	.string "were made for this game.\n"
	.string "Only official forms will appear.$"

Common_EventScript_PkmnCenterNurse_Text_3:
# 22 "data/scripts/pkmn_center_nurse.pory"
	.string "{COLOR RED}Important:{COLOR DARK_GREY} This choice is {COLOR RED}permanent{COLOR DARK_GREY}.\n"
	.string "It cannot be changed on this save file.$"

Common_EventScript_PkmnCenterNurse_Text_4:
# 23 "data/scripts/pkmn_center_nurse.pory"
	.string "Would you like to {COLOR GREEN}enable{COLOR DARK_GREY} {COLOR BLUE}No Custom\n"
	.string "Forms Mode{COLOR DARK_GREY}?$"

Common_EventScript_PkmnCenterNurse_Text_5:
# 25 "data/scripts/pkmn_center_nurse.pory"
	.string "This {COLOR RED}cannot be undone{COLOR DARK_GREY}.\n"
	.string "Are you sure you want to enable it?$"

Common_EventScript_PkmnCenterNurse_Text_6:
# 29 "data/scripts/pkmn_center_nurse.pory"
	.string "{COLOR BLUE}No Custom Forms Mode{COLOR DARK_GREY} has been {COLOR GREEN}enabled{COLOR DARK_GREY}!$"

Common_EventScript_PkmnCenterNurse_Text_7:
# 33 "data/scripts/pkmn_center_nurse.pory"
	.string "Understood! Custom forms will stay\n"
	.string "active.$"

Common_EventScript_PkmnCenterNurse_Text_8:
# 37 "data/scripts/pkmn_center_nurse.pory"
	.string "You won't be asked again.\n"
	.string "Are you sure you want to keep custom\l"
	.string "forms?$"

Common_EventScript_PkmnCenterNurse_Text_9:
# 39 "data/scripts/pkmn_center_nurse.pory"
	.string "Got it! Custom forms will remain active.$"

Common_EventScript_PkmnCenterNurse_Text_10:
# 55 "data/scripts/pkmn_center_nurse.pory"
	.string "We hope to see you again!$"

Common_EventScript_PkmnCenterNurse_Old_Text_0:
# 76 "data/scripts/pkmn_center_nurse.pory"
	.string "Okay, I'll take your Pokémon for a few\n"
	.string "seconds.$"
