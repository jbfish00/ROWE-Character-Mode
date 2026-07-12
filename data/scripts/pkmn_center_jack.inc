Common_EventScript_PkmnCenterJack::
# 3 "data/scripts/pkmn_center_jack.pory"
	lockall
# 4 "data/scripts/pkmn_center_jack.pory"
	call Common_Eventscript_CheckForItems
# 5 "data/scripts/pkmn_center_jack.pory"
	call Common_Eventscript_CheckForSeviiTicket
# 6 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_GotPokemonQuestions, MSGBOX_DEFAULT
# 7 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_BLUE_NURSE_OPTIONS, 0, 0, 6, TRUE
# 8 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 9 "data/scripts/pkmn_center_jack.pory"
	case 0, Common_EventScript_PkmnCenterJack_2
# 13 "data/scripts/pkmn_center_jack.pory"
	case 1, Common_EventScript_PkmnCenterJack_3
# 17 "data/scripts/pkmn_center_jack.pory"
	case 2, Common_EventScript_PkmnCenterJack_4
# 21 "data/scripts/pkmn_center_jack.pory"
	case 3, Common_EventScript_PkmnCenterJack_5
# 31 "data/scripts/pkmn_center_jack.pory"
	case 4, Common_EventScript_PkmnCenterJack_6
# 35 "data/scripts/pkmn_center_jack.pory"
	case 5, Common_EventScript_PkmnCenterJack_7
# 39 "data/scripts/pkmn_center_jack.pory"
	case 6, Common_EventScript_PkmnCenterJack_8
# 43 "data/scripts/pkmn_center_jack.pory"
	case 7, Common_EventScript_PkmnCenterJack_9
# 47 "data/scripts/pkmn_center_jack.pory"
	case 8, Common_EventScript_PkmnCenterJack_10
# 51 "data/scripts/pkmn_center_jack.pory"
	case 9, Common_EventScript_PkmnCenterJack_11
# 56 "data/scripts/pkmn_center_jack.pory"
	case 10, Common_EventScript_PkmnCenterJack_12
# 61 "data/scripts/pkmn_center_jack.pory"
	case 11, Common_EventScript_PkmnCenterJack_13
Common_EventScript_PkmnCenterJack_13:
# 63 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_ComeBackAnytime
	return

Common_EventScript_PkmnCenterJack_2:
# 11 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Change_Costume
	return

Common_EventScript_PkmnCenterJack_3:
# 15 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle
	return

Common_EventScript_PkmnCenterJack_4:
# 19 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_NameRater_ChooseMonToRate
	return

Common_EventScript_PkmnCenterJack_5:
# 23 "data/scripts/pkmn_center_jack.pory"
	goto_if_set FLAG_METRONOME_ONLY_MODE, Common_EventScript_PkmnCenterJack_15
# 28 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
Common_EventScript_PkmnCenterJack_14:
	return

Common_EventScript_PkmnCenterJack_6:
# 33 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_WonderTrade
	return

Common_EventScript_PkmnCenterJack_7:
# 37 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Double_Battle_Mode
	return

Common_EventScript_PkmnCenterJack_8:
# 41 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Lower_Difficulty
	return

Common_EventScript_PkmnCenterJack_9:
# 45 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_ChangeSeason
	return

Common_EventScript_PkmnCenterJack_10:
# 49 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_ChangeYear
	return

Common_EventScript_PkmnCenterJack_11:
# 54 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TravelToSevii
	return

Common_EventScript_PkmnCenterJack_12:
# 59 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Companion_Stuff
	return

Common_EventScript_PkmnCenterJack_15:
# 24 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Text_0
# 25 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	goto Common_EventScript_PkmnCenterJack_14


Common_EventScript_PkmnCenterJack_TravelToSevii::
# 73 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_Colress
	return


Common_EventScript_PkmnCenterJack_Double_Battle_Mode::
# 79 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_DOUBLE_BATTLE_MODE, Common_EventScript_PkmnCenterJack_Double_Battle_Mode_2
# 85 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_1, MSGBOX_DEFAULT
# 86 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 87 "data/scripts/pkmn_center_jack.pory"
	multichoice 0, 0, MULTI_GAME_MODE_DISABLE, 0
Common_EventScript_PkmnCenterJack_Double_Battle_Mode_1:
# 90 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 91 "data/scripts/pkmn_center_jack.pory"
	case 0, Common_EventScript_PkmnCenterJack_Double_Battle_Mode_7
# 105 "data/scripts/pkmn_center_jack.pory"
	case 1, Common_EventScript_PkmnCenterJack_Double_Battle_Mode_8
# 108 "data/scripts/pkmn_center_jack.pory"
	case 2, Common_EventScript_PkmnCenterJack_Double_Battle_Mode_9
# 109 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_Double_Battle_Mode_9
Common_EventScript_PkmnCenterJack_Double_Battle_Mode_5:
# 114 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Double_Battle_Mode
	return

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_2:
# 80 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_0, MSGBOX_DEFAULT
# 81 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 82 "data/scripts/pkmn_center_jack.pory"
	multichoice 0, 0, MULTI_GAME_MODE_ENABLE, 0
	goto Common_EventScript_PkmnCenterJack_Double_Battle_Mode_1

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_7:
# 92 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_DOUBLE_BATTLE_MODE, Common_EventScript_PkmnCenterJack_Double_Battle_Mode_11
# 99 "data/scripts/pkmn_center_jack.pory"
	playfanfare SE_BOO
# 100 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_3, MSGBOX_DEFAULT
# 101 "data/scripts/pkmn_center_jack.pory"
	waitfanfare
# 102 "data/scripts/pkmn_center_jack.pory"
	clearflag FLAG_DOUBLE_BATTLE_MODE
Common_EventScript_PkmnCenterJack_Double_Battle_Mode_10:
	goto Common_EventScript_PkmnCenterJack_Double_Battle_Mode_5

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_8:
# 106 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_4, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterJack_Double_Battle_Mode_5

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_9:
# 110 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_ComeBackAnytime
	goto Common_EventScript_PkmnCenterJack_Double_Battle_Mode_5

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_11:
# 93 "data/scripts/pkmn_center_jack.pory"
	playfanfare SE_SAVE
# 94 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_2, MSGBOX_DEFAULT
# 95 "data/scripts/pkmn_center_jack.pory"
	waitfanfare
# 96 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_DOUBLE_BATTLE_MODE
	goto Common_EventScript_PkmnCenterJack_Double_Battle_Mode_10


Common_EventScript_PkmnCenterJack_Companion_Stuff::
# 118 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_GotPokemonQuestions, MSGBOX_DEFAULT
# 119 "data/scripts/pkmn_center_jack.pory"
	multichoice 16, 0, MULTI_COMPANION_OPTIONS, 0
# 120 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 121 "data/scripts/pkmn_center_jack.pory"
	switch VAR_TEMP_1
# 122 "data/scripts/pkmn_center_jack.pory"
	case 0, Common_EventScript_PkmnCenterJack_Companion_Stuff_3
# 126 "data/scripts/pkmn_center_jack.pory"
	case 1, Common_EventScript_PkmnCenterJack_Companion_Stuff_4
# 127 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_Companion_Stuff_5
# 128 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_ComeBackAnytime
Common_EventScript_PkmnCenterJack_Companion_Stuff_1:
	end

Common_EventScript_PkmnCenterJack_Companion_Stuff_3:
# 122 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Companion_Get_Trainer_Password
	goto Common_EventScript_PkmnCenterJack_Companion_Stuff_1

Common_EventScript_PkmnCenterJack_Companion_Stuff_4:
# 126 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	goto Common_EventScript_PkmnCenterJack_Companion_Stuff_1

Common_EventScript_PkmnCenterJack_Companion_Stuff_5:
# 127 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	goto Common_EventScript_PkmnCenterJack_Companion_Stuff_1


Common_EventScript_PkmnCenterJack_ComeBackAnytime::
# 134 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
# 135 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_StartARandomBattle::
# 141 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MockBattle, MSGBOX_DEFAULT
# 142 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 143 "data/scripts/pkmn_center_jack.pory"
	multichoice 0, 0, MULTI_MOCK_BATTLE_OPTIONS, 0
# 144 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 145 "data/scripts/pkmn_center_jack.pory"
	case 0, Common_EventScript_PkmnCenterJack_StartARandomBattle_3
# 146 "data/scripts/pkmn_center_jack.pory"
	case 1, Common_EventScript_PkmnCenterJack_StartARandomBattle_4
# 147 "data/scripts/pkmn_center_jack.pory"
	case 2, Common_EventScript_PkmnCenterJack_StartARandomBattle_5
# 148 "data/scripts/pkmn_center_jack.pory"
	case 3, Common_EventScript_PkmnCenterJack_StartARandomBattle_6
# 149 "data/scripts/pkmn_center_jack.pory"
	case 4, Common_EventScript_PkmnCenterJack_StartARandomBattle_7
# 150 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_StartARandomBattle_8
Common_EventScript_PkmnCenterJack_StartARandomBattle_1:
	end

Common_EventScript_PkmnCenterJack_StartARandomBattle_3:
# 145 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_Easy
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_1

Common_EventScript_PkmnCenterJack_StartARandomBattle_4:
# 146 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_Medium
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_1

Common_EventScript_PkmnCenterJack_StartARandomBattle_5:
# 147 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_Hard
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_1

Common_EventScript_PkmnCenterJack_StartARandomBattle_6:
# 148 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_PSS
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_1

Common_EventScript_PkmnCenterJack_StartARandomBattle_7:
# 149 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_1

Common_EventScript_PkmnCenterJack_StartARandomBattle_8:
# 150 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_1


Common_EventScript_PkmnCenterJack_StartARandomBattle_Easy::
# 156 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MockBattle_Easy, MSGBOX_DEFAULT
# 157 "data/scripts/pkmn_center_jack.pory"
	trainerbattle_no_intro TRAINER_NURSE_KIRSTEN, Common_PkmnCenterJack_Text_MockBattle_Defeat
# 158 "data/scripts/pkmn_center_jack.pory"
	special HealPlayerParty
# 159 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
# 160 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_StartARandomBattle_Medium::
# 165 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MockBattle_Normal, MSGBOX_DEFAULT
# 166 "data/scripts/pkmn_center_jack.pory"
	trainerbattle_no_intro TRAINER_NURSE_SACHIKO, Common_PkmnCenterJack_Text_MockBattle_Defeat
# 167 "data/scripts/pkmn_center_jack.pory"
	special HealPlayerParty
# 168 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
# 169 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_StartARandomBattle_Hard::
# 174 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MockBattle_Hard, MSGBOX_DEFAULT
# 175 "data/scripts/pkmn_center_jack.pory"
	trainerbattle_no_intro TRAINER_NURSE_SHERY, Common_PkmnCenterJack_Text_MockBattle_Defeat
# 176 "data/scripts/pkmn_center_jack.pory"
	special HealPlayerParty
# 177 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
# 178 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_StartARandomBattle_PSS::
# 183 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MockBattle_PSS, MSGBOX_DEFAULT
# 184 "data/scripts/pkmn_center_jack.pory"
	trainerbattle_no_intro TRAINER_PSS_TRAINER, Common_PkmnCenterJack_Text_MockBattle_Defeat
# 185 "data/scripts/pkmn_center_jack.pory"
	special HealPlayerParty
# 186 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
# 187 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_NameRater_ChooseMonToRate::
# 193 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
# 194 "data/scripts/pkmn_center_jack.pory"
	special ChoosePartyMon
# 195 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 196 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 255
	goto_if_ne Common_EventScript_PkmnCenterJack_NameRater_ChooseMonToRate_2
Common_EventScript_PkmnCenterJack_NameRater_ChooseMonToRate_1:
# 199 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_NameRater_DeclineNameRate
	end

Common_EventScript_PkmnCenterJack_NameRater_ChooseMonToRate_2:
# 197 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname
	goto Common_EventScript_PkmnCenterJack_NameRater_ChooseMonToRate_1


Common_EventScript_PkmnCenterJack_NameRater_DeclineNameRate::
# 204 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_DoVisitAgain, MSGBOX_DEFAULT
# 205 "data/scripts/pkmn_center_jack.pory"
	release
	end


Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname::
# 210 "data/scripts/pkmn_center_jack.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 211 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname_2
Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname_1:
# 214 "data/scripts/pkmn_center_jack.pory"
	special BufferMonNickname
# 215 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
# 216 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname_5
Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname_4:
# 219 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_NameRater_DeclineNameRate
	end

Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname_2:
# 212 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_NameRater_CantRateEgg
	goto Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname_1

Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname_5:
# 217 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_NameRater_ChangeNickname
	goto Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname_4


Common_EventScript_PkmnCenterJack_NameRater_CantRateEgg::
# 224 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
# 225 "data/scripts/pkmn_center_jack.pory"
	release
	end


Common_EventScript_PkmnCenterJack_NameRater_ChangeNickname::
# 230 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
# 231 "data/scripts/pkmn_center_jack.pory"
	call Common_EventScript_NameReceivedPartyMon
# 232 "data/scripts/pkmn_center_jack.pory"
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
# 233 "data/scripts/pkmn_center_jack.pory"
	special BufferMonNickname
# 234 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_PkmnCenterJack_NameRater_ChangeNickname_2
Common_EventScript_PkmnCenterJack_NameRater_ChangeNickname_1:
# 237 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
# 238 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_EventScript_PkmnCenterJack_NameRater_ChangeNickname_2:
# 235 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_NameRater_NewNameDifferent
	goto Common_EventScript_PkmnCenterJack_NameRater_ChangeNickname_1


Common_EventScript_PkmnCenterJack_NameRater_NewNameDifferent::
# 243 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
# 244 "data/scripts/pkmn_center_jack.pory"
	release
	end


Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget::
# 250 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_WhichMonShouldForget, MSGBOX_DEFAULT
# 251 "data/scripts/pkmn_center_jack.pory"
	special ChoosePartyMon
# 252 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 253 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_2
Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_1:
# 256 "data/scripts/pkmn_center_jack.pory"
	special IsSelectedMonEgg
# 257 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_5
Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_4:
# 260 "data/scripts/pkmn_center_jack.pory"
	special GetNumMovesSelectedMonHas
# 261 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, 1
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_8
Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_7:
# 264 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
# 265 "data/scripts/pkmn_center_jack.pory"
	fadescreen FADE_TO_BLACK
# 266 "data/scripts/pkmn_center_jack.pory"
	special MoveDeleterChooseMoveToForget
# 267 "data/scripts/pkmn_center_jack.pory"
	fadescreen FADE_FROM_BLACK
# 268 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8005, MAX_MON_MOVES
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_11
Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_10:
# 271 "data/scripts/pkmn_center_jack.pory"
	special BufferMoveDeleterNicknameAndMove
# 272 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
# 273 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 274 "data/scripts/pkmn_center_jack.pory"
	case YES, Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_15
# 275 "data/scripts/pkmn_center_jack.pory"
	case NO, Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_16
Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_13:
# 277 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end

Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_2:
# 254 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ComeAgain
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_1

Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_5:
# 258 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_EggCantForgetMoves
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_4

Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_8:
# 262 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_MonOnlyKnowsOneMove
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_7

Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_11:
# 269 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_10

Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_15:
# 274 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_TryForgetMove
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_13

Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_16:
# 275 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ComeAgain
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_13


Common_EventScript_PkmnCenterJack_MoveDeleter_TryForgetMove::
# 282 "data/scripts/pkmn_center_jack.pory"
	special IsLastMonThatKnowsSurf
# 283 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveDeleter_TryForgetMove_2
Common_EventScript_PkmnCenterJack_MoveDeleter_TryForgetMove_1:
# 286 "data/scripts/pkmn_center_jack.pory"
	special MoveDeleterForgetMove
# 287 "data/scripts/pkmn_center_jack.pory"
	playfanfare MUS_MOVE_DELETED
# 288 "data/scripts/pkmn_center_jack.pory"
	waitfanfare
# 289 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MonHasForgottenMove, MSGBOX_DEFAULT
# 290 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end

Common_EventScript_PkmnCenterJack_MoveDeleter_TryForgetMove_2:
# 284 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_LastMonWithSurf
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_TryForgetMove_1


Common_EventScript_PkmnCenterJack_MoveDeleter_MonOnlyKnowsOneMove::
# 295 "data/scripts/pkmn_center_jack.pory"
	special BufferMoveDeleterNicknameAndMove
# 296 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
# 297 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_MoveDeleter_EggCantForgetMoves::
# 302 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_EggCantForgetMoves, MSGBOX_DEFAULT
# 303 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_MoveDeleter_ComeAgain::
# 308 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_ComeAgain, MSGBOX_DEFAULT
# 309 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_MoveDeleter_LastMonWithSurf::
# 314 "data/scripts/pkmn_center_jack.pory"
	special BufferMoveDeleterNicknameAndMove
# 315 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_CantForgetSurf, MSGBOX_DEFAULT
# 316 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_MoveReminder_ComeBackAnytime::
# 323 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
# 324 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_Eventscript_CheckForItems::
# 330 "data/scripts/pkmn_center_jack.pory"
	checkitem ITEM_ITEMFINDER, 1
# 331 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_Eventscript_CheckForItems_2
Common_Eventscript_CheckForItems_1:
	return

Common_Eventscript_CheckForItems_2:
# 332 "data/scripts/pkmn_center_jack.pory"
	additem ITEM_ITEMFINDER
	goto Common_Eventscript_CheckForItems_1


Common_EventScript_PkmnCenterJack_Clear_Move_Tutor_Data::
# 338 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_NORMAL
# 339 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_PARTY_MENU_TUTOR_STATE, MOVE_TUTOR_LEVEL_UP_MOVES
# 340 "data/scripts/pkmn_center_jack.pory"
	clearflag FLAG_IS_MOVE_TUTOR
	return


Common_EventScript_PkmnCenterJack_Move_Learner::
# 345 "data/scripts/pkmn_center_jack.pory"
	call Common_EventScript_PkmnCenterJack_Clear_Move_Tutor_Data
# 346 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_TeachMoves, MSGBOX_DEFAULT
# 347 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_BLUE_NURSE_MOVE_LEARN, 0, 0, 5, TRUE
# 348 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 349 "data/scripts/pkmn_center_jack.pory"
	case 0, Common_EventScript_PkmnCenterJack_Move_Learner_2
# 352 "data/scripts/pkmn_center_jack.pory"
	case 1, Common_EventScript_PkmnCenterJack_Move_Learner_3
# 355 "data/scripts/pkmn_center_jack.pory"
	case 2, Common_EventScript_PkmnCenterJack_Move_Learner_4
# 358 "data/scripts/pkmn_center_jack.pory"
	case 3, Common_EventScript_PkmnCenterJack_Move_Learner_5
# 361 "data/scripts/pkmn_center_jack.pory"
	case 5, Common_EventScript_PkmnCenterJack_Move_Learner_6
Common_EventScript_PkmnCenterJack_Move_Learner_6:
# 363 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_ComeBackAnytime
	return

Common_EventScript_PkmnCenterJack_Move_Learner_2:
# 350 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget
	return

Common_EventScript_PkmnCenterJack_Move_Learner_3:
# 353 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_EggMoveTutor_Price
	return

Common_EventScript_PkmnCenterJack_Move_Learner_4:
# 356 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price
	return

Common_EventScript_PkmnCenterJack_Move_Learner_5:
# 359 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TmMoveTutor_Price
	return


Common_EventScript_PkmnCenterJack_Lower_Difficulty::
# 369 "data/scripts/pkmn_center_jack.pory"
	compare VAR_DIFFICULTY, DIFFICULTY_EASY
	goto_if_ne Common_EventScript_PkmnCenterJack_Lower_Difficulty_2
# 395 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Lower_Difficulty_Text_3
# 396 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
Common_EventScript_PkmnCenterJack_Lower_Difficulty_1:
# 398 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_EventScript_PkmnCenterJack_Lower_Difficulty_2:
# 370 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Lower_Difficulty_Text_0, MSGBOX_YESNO
# 371 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 372 "data/scripts/pkmn_center_jack.pory"
	case YES, Common_EventScript_PkmnCenterJack_Lower_Difficulty_6
# 387 "data/scripts/pkmn_center_jack.pory"
	case NO, Common_EventScript_PkmnCenterJack_Lower_Difficulty_7
# 388 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_Lower_Difficulty_7
Common_EventScript_PkmnCenterJack_Lower_Difficulty_7:
# 390 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	goto Common_EventScript_PkmnCenterJack_Lower_Difficulty_1

Common_EventScript_PkmnCenterJack_Lower_Difficulty_6:
# 373 "data/scripts/pkmn_center_jack.pory"
	compare VAR_DIFFICULTY, DIFFICULTY_HARD
	goto_if_eq Common_EventScript_PkmnCenterJack_Lower_Difficulty_9
# 379 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_DIFFICULTY, DIFFICULTY_EASY
# 380 "data/scripts/pkmn_center_jack.pory"
	playfanfare MUS_OBTAIN_ITEM
# 381 "data/scripts/pkmn_center_jack.pory"
	message Common_EventScript_PkmnCenterJack_Lower_Difficulty_Text_2
Common_EventScript_PkmnCenterJack_Lower_Difficulty_8:
# 383 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 384 "data/scripts/pkmn_center_jack.pory"
	waitfanfare
# 385 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	goto Common_EventScript_PkmnCenterJack_Lower_Difficulty_1

Common_EventScript_PkmnCenterJack_Lower_Difficulty_9:
# 374 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_DIFFICULTY, DIFFICULTY_NORMAL
# 375 "data/scripts/pkmn_center_jack.pory"
	playfanfare MUS_OBTAIN_ITEM
# 376 "data/scripts/pkmn_center_jack.pory"
	message Common_EventScript_PkmnCenterJack_Lower_Difficulty_Text_1
	goto Common_EventScript_PkmnCenterJack_Lower_Difficulty_8


Common_EventScript_PkmnCenterJack_Change_Costume::
# 403 "data/scripts/pkmn_center_jack.pory"
	lock
# 404 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 405 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_0, MSGBOX_DEFAULT
# 406 "data/scripts/pkmn_center_jack.pory"
	checkplayergender
# 407 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, GENDER_FEMALE
	goto_if_eq Common_EventScript_PkmnCenterJack_Change_Costume_2
# 452 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_COSTUMES_MALE, 0, 0, 6, TRUE
# 453 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 454 "data/scripts/pkmn_center_jack.pory"
	case 0, Common_EventScript_PkmnCenterJack_Change_Costume_15
# 459 "data/scripts/pkmn_center_jack.pory"
	case 1, Common_EventScript_PkmnCenterJack_Change_Costume_16
# 464 "data/scripts/pkmn_center_jack.pory"
	case 2, Common_EventScript_PkmnCenterJack_Change_Costume_17
# 469 "data/scripts/pkmn_center_jack.pory"
	case 3, Common_EventScript_PkmnCenterJack_Change_Costume_18
# 474 "data/scripts/pkmn_center_jack.pory"
	case 4, Common_EventScript_PkmnCenterJack_Change_Costume_19
# 479 "data/scripts/pkmn_center_jack.pory"
	case 5, Common_EventScript_PkmnCenterJack_Change_Costume_20
# 484 "data/scripts/pkmn_center_jack.pory"
	case 6, Common_EventScript_PkmnCenterJack_Change_Costume_21
# 489 "data/scripts/pkmn_center_jack.pory"
	case 7, Common_EventScript_PkmnCenterJack_Change_Costume_22
# 494 "data/scripts/pkmn_center_jack.pory"
	case 8, Common_EventScript_PkmnCenterJack_Change_Costume_23
# 500 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_Change_Costume_24
Common_EventScript_PkmnCenterJack_Change_Costume_24:
# 501 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_2, MSGBOX_DEFAULT
Common_EventScript_PkmnCenterJack_Change_Costume_1:
# 505 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end

Common_EventScript_PkmnCenterJack_Change_Costume_2:
# 408 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_COSTUMES_FEMALE, 0, 0, 6, TRUE
# 409 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 410 "data/scripts/pkmn_center_jack.pory"
	case 0, Common_EventScript_PkmnCenterJack_Change_Costume_6
# 415 "data/scripts/pkmn_center_jack.pory"
	case 1, Common_EventScript_PkmnCenterJack_Change_Costume_7
# 420 "data/scripts/pkmn_center_jack.pory"
	case 2, Common_EventScript_PkmnCenterJack_Change_Costume_8
# 425 "data/scripts/pkmn_center_jack.pory"
	case 3, Common_EventScript_PkmnCenterJack_Change_Costume_9
# 430 "data/scripts/pkmn_center_jack.pory"
	case 4, Common_EventScript_PkmnCenterJack_Change_Costume_10
# 435 "data/scripts/pkmn_center_jack.pory"
	case 5, Common_EventScript_PkmnCenterJack_Change_Costume_11
# 440 "data/scripts/pkmn_center_jack.pory"
	case 6, Common_EventScript_PkmnCenterJack_Change_Costume_12
# 446 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_Change_Costume_13
Common_EventScript_PkmnCenterJack_Change_Costume_13:
# 447 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_2, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_6:
# 411 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, RS_COSTUME
# 412 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 413 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_7:
# 416 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, EMERALD_COSTUME
# 417 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 418 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_8:
# 421 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, ORAS_COSTUME
# 422 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 423 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_9:
# 426 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, RBY_COSTUME
# 427 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 428 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_10:
# 431 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, FRLG_COSTUME
# 432 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 433 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_11:
# 436 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, DP_COSTUME
# 437 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 438 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_12:
# 441 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, EXTRA_COSTUME
# 442 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 443 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_15:
# 455 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, RS_COSTUME
# 456 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 457 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_16:
# 460 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, EMERALD_COSTUME
# 461 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 462 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_17:
# 465 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, ORAS_COSTUME
# 466 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 467 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_18:
# 470 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, RBY_COSTUME
# 471 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 472 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_19:
# 475 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, FRLG_COSTUME
# 476 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 477 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_20:
# 480 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, EXTRA_COSTUME
# 481 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 482 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_21:
# 485 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, GSC_COSTUME
# 486 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 487 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_22:
# 490 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, DP_COSTUME
# 491 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 492 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_23:
# 495 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, BW_COSTUME
# 496 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 497 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1


Common_EventScript_PkmnCenterJack_WonderTrade::
# 511 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
# 512 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 513 "data/scripts/pkmn_center_jack.pory"
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
# 514 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x8009, VAR_RESULT
# 516 "data/scripts/pkmn_center_jack.pory"
	checkitem ITEM_WONDER_CHARM, 1
# 517 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_2
# 523 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_WonderTrade_Text_1, MSGBOX_YESNO
Common_EventScript_PkmnCenterJack_WonderTrade_1:
# 526 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, NO
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_6
# 531 "data/scripts/pkmn_center_jack.pory"
	checkitem ITEM_WONDER_CHARM, 1
# 532 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_10
Common_EventScript_PkmnCenterJack_WonderTrade_9:
# 536 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_12
# 541 "data/scripts/pkmn_center_jack.pory"
	special ChoosePartyMon
# 542 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 544 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 0xFF
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_16
Common_EventScript_PkmnCenterJack_WonderTrade_15:
# 547 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 548 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 549 "data/scripts/pkmn_center_jack.pory"
	specialvar VAR_RESULT, GetTradeSpecies
# 550 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x800B, VAR_RESULT
# 551 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, VAR_0x8009
# 552 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 553 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 554 "data/scripts/pkmn_center_jack.pory"
	special CreateInGameWonderTradePokemon
# 555 "data/scripts/pkmn_center_jack.pory"
	special DoInGameTradeScene
# 556 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 557 "data/scripts/pkmn_center_jack.pory"
	special DestroyFollower
# 558 "data/scripts/pkmn_center_jack.pory"
	bufferspeciesname 0, VAR_0x8009
# 559 "data/scripts/pkmn_center_jack.pory"
	playse SE_SHOP
# 561 "data/scripts/pkmn_center_jack.pory"
	checkitem ITEM_WONDER_CHARM, 1
# 562 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_19
Common_EventScript_PkmnCenterJack_WonderTrade_18:
# 566 "data/scripts/pkmn_center_jack.pory"
	clearflag FLAG_FOLLOWER_IS_ENABLED
# 567 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_WonderTrade_Text_3, MSGBOX_DEFAULT
Common_EventScript_PkmnCenterJack_WonderTrade_5:
# 570 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_EventScript_PkmnCenterJack_WonderTrade_2:
# 518 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 519 "data/scripts/pkmn_center_jack.pory"
	showmoneybox 0, 0, 0
# 520 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_WonderTrade_Text_0, MSGBOX_YESNO
	goto Common_EventScript_PkmnCenterJack_WonderTrade_1

Common_EventScript_PkmnCenterJack_WonderTrade_6:
# 527 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_WonderTrade_Cancel
	goto Common_EventScript_PkmnCenterJack_WonderTrade_5

Common_EventScript_PkmnCenterJack_WonderTrade_10:
# 533 "data/scripts/pkmn_center_jack.pory"
	checkmoney WONDER_TRADE_PRICE, 0
	goto Common_EventScript_PkmnCenterJack_WonderTrade_9

Common_EventScript_PkmnCenterJack_WonderTrade_12:
# 537 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_WonderTrade_Text_2, MSGBOX_DEFAULT
# 538 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, 0
	goto Common_EventScript_PkmnCenterJack_WonderTrade_5

Common_EventScript_PkmnCenterJack_WonderTrade_16:
# 545 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_WonderTrade_Cancel
	goto Common_EventScript_PkmnCenterJack_WonderTrade_15

Common_EventScript_PkmnCenterJack_WonderTrade_19:
# 563 "data/scripts/pkmn_center_jack.pory"
	removemoney WONDER_TRADE_PRICE, 0
	goto Common_EventScript_PkmnCenterJack_WonderTrade_18


Common_EventScript_PkmnCenterJack_WonderTrade_Cancel::
# 575 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_WonderTrade_Cancel_Text_0, MSGBOX_DEFAULT
# 576 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	return


Common_EventScript_PkmnCenterJack_EggMoveTutor_Price::
# 582 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_PARTY_MENU_TUTOR_STATE, MOVE_TUTOR_EGG_MOVES
# 583 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_IS_MOVE_TUTOR
# 584 "data/scripts/pkmn_center_jack.pory"
	compare VAR_NUM_BADGES, 6
	goto_if_ge Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_1
# 609 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_2, MSGBOX_DEFAULT
# 610 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_1:
# 585 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 586 "data/scripts/pkmn_center_jack.pory"
	showmoneybox 0, 0, 0
# 587 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_0, MSGBOX_YESNO
# 588 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_4
# 604 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 605 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_4:
# 590 "data/scripts/pkmn_center_jack.pory"
	checkmoney 4, 0
# 591 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_7
# 597 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 598 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_1, MSGBOX_DEFAULT
# 599 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_7:
# 592 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 593 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon::
# 615 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_0, MSGBOX_DEFAULT
# 616 "data/scripts/pkmn_center_jack.pory"
	special ChooseMonForMoveRelearner
# 617 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 618 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_1
# 622 "data/scripts/pkmn_center_jack.pory"
	special IsSelectedMonEgg
# 623 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_4
# 628 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8005, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_7
# 633 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_3, MSGBOX_DEFAULT
# 634 "data/scripts/pkmn_center_jack.pory"
	special TeachMoveRelearnerMove
# 635 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 636 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_10
# 640 "data/scripts/pkmn_center_jack.pory"
	playse SE_SHOP
# 641 "data/scripts/pkmn_center_jack.pory"
	removemoney 4, 0
# 642 "data/scripts/pkmn_center_jack.pory"
	call Common_EventScript_PkmnCenterJack_Clear_Move_Tutor_Data
# 643 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_4, MSGBOX_DEFAULT
# 644 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_1:
# 619 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_4:
# 624 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_1, MSGBOX_DEFAULT
# 625 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_7:
# 629 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_2, MSGBOX_DEFAULT
	return

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_10:
# 637 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price::
# 655 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_PARTY_MENU_TUTOR_STATE, MOVE_TUTOR_MOVES
# 656 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_IS_MOVE_TUTOR
# 657 "data/scripts/pkmn_center_jack.pory"
	compare VAR_NUM_BADGES, 9
	goto_if_ge Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_1
# 682 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_Text_1, MSGBOX_DEFAULT
# 683 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_1:
# 658 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 659 "data/scripts/pkmn_center_jack.pory"
	showmoneybox 0, 0, 0
# 660 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_Text_0, MSGBOX_YESNO
# 661 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_4
# 677 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 678 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_4:
# 663 "data/scripts/pkmn_center_jack.pory"
	checkmoney 6, 0
# 664 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_7
# 670 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 671 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_1, MSGBOX_DEFAULT
# 672 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_7:
# 665 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 666 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon::
# 688 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_0, MSGBOX_DEFAULT
# 689 "data/scripts/pkmn_center_jack.pory"
	special ChooseMonForMoveRelearner
# 690 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 691 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_1
# 695 "data/scripts/pkmn_center_jack.pory"
	special IsSelectedMonEgg
# 696 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_4
# 701 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8005, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_7
# 706 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_3, MSGBOX_DEFAULT
# 707 "data/scripts/pkmn_center_jack.pory"
	special TeachMoveRelearnerMove
# 708 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 709 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_10
# 713 "data/scripts/pkmn_center_jack.pory"
	playse SE_SHOP
# 714 "data/scripts/pkmn_center_jack.pory"
	removemoney 6, 0
# 715 "data/scripts/pkmn_center_jack.pory"
	call Common_EventScript_PkmnCenterJack_Clear_Move_Tutor_Data
# 716 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_4, MSGBOX_DEFAULT
# 717 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end

Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_1:
# 692 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_4:
# 697 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_1, MSGBOX_DEFAULT
# 698 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_7:
# 702 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_2, MSGBOX_DEFAULT
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_10:
# 710 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_TmMoveTutor_Price::
# 728 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_PARTY_MENU_TUTOR_STATE, MOVE_TUTOR_TM_MOVES
# 729 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_IS_MOVE_TUTOR
# 730 "data/scripts/pkmn_center_jack.pory"
	compare VAR_NUM_BADGES, 12
	goto_if_ge Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_1
# 755 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_Text_1, MSGBOX_DEFAULT
# 756 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_1:
# 731 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 732 "data/scripts/pkmn_center_jack.pory"
	showmoneybox 0, 0, 0
# 733 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_Text_0, MSGBOX_YESNO
# 734 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_4
# 750 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 751 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_4:
# 736 "data/scripts/pkmn_center_jack.pory"
	checkmoney 8, 0
# 737 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_7
# 743 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 744 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_1, MSGBOX_DEFAULT
# 745 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_7:
# 738 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 739 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon::
# 761 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_0, MSGBOX_DEFAULT
# 762 "data/scripts/pkmn_center_jack.pory"
	special ChooseMonForMoveRelearner
# 763 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 764 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_1
# 768 "data/scripts/pkmn_center_jack.pory"
	special IsSelectedMonEgg
# 769 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_4
# 774 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8005, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_7
# 779 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_3, MSGBOX_DEFAULT
# 780 "data/scripts/pkmn_center_jack.pory"
	special TeachMoveRelearnerMove
# 781 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 782 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_10
# 786 "data/scripts/pkmn_center_jack.pory"
	playse SE_SHOP
# 787 "data/scripts/pkmn_center_jack.pory"
	removemoney 8, 0
# 788 "data/scripts/pkmn_center_jack.pory"
	call Common_EventScript_PkmnCenterJack_Clear_Move_Tutor_Data
# 789 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_4, MSGBOX_DEFAULT
# 790 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end

Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_1:
# 765 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_4:
# 770 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_1, MSGBOX_DEFAULT
# 771 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_7:
# 775 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_2, MSGBOX_DEFAULT
	return

Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_10:
# 783 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_ChangeSeason::
# 799 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_0, MSGBOX_DEFAULT
# 800 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 801 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_SEASONS, 0, 0, 5, TRUE
# 802 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 803 "data/scripts/pkmn_center_jack.pory"
	case SEASON_SPRING, Common_EventScript_PkmnCenterJack_ChangeSeason_3
# 808 "data/scripts/pkmn_center_jack.pory"
	case SEASON_SUMMER, Common_EventScript_PkmnCenterJack_ChangeSeason_4
# 813 "data/scripts/pkmn_center_jack.pory"
	case SEASON_AUTUMN, Common_EventScript_PkmnCenterJack_ChangeSeason_5
# 818 "data/scripts/pkmn_center_jack.pory"
	case SEASON_WINTER, Common_EventScript_PkmnCenterJack_ChangeSeason_6
# 826 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_ChangeSeason_8
# 824 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_5
Common_EventScript_PkmnCenterJack_ChangeSeason_1:
# 829 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	return

Common_EventScript_PkmnCenterJack_ChangeSeason_3:
# 804 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_CURRENT_SEASON, SEASON_SPRING
# 805 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_SYS_DISABLE_AUTOMATIC_SEASON
# 806 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_1
	goto Common_EventScript_PkmnCenterJack_ChangeSeason_1

Common_EventScript_PkmnCenterJack_ChangeSeason_4:
# 809 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_CURRENT_SEASON, SEASON_SUMMER
# 810 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_SYS_DISABLE_AUTOMATIC_SEASON
# 811 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_2
	goto Common_EventScript_PkmnCenterJack_ChangeSeason_1

Common_EventScript_PkmnCenterJack_ChangeSeason_5:
# 814 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_CURRENT_SEASON, SEASON_AUTUMN
# 815 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_SYS_DISABLE_AUTOMATIC_SEASON
# 816 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_3
	goto Common_EventScript_PkmnCenterJack_ChangeSeason_1

Common_EventScript_PkmnCenterJack_ChangeSeason_6:
# 819 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_CURRENT_SEASON, SEASON_WINTER
# 820 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_SYS_DISABLE_AUTOMATIC_SEASON
# 821 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_4
	goto Common_EventScript_PkmnCenterJack_ChangeSeason_1

Common_EventScript_PkmnCenterJack_ChangeSeason_8:
	goto Common_EventScript_PkmnCenterJack_ChangeSeason_1


Common_EventScript_PkmnCenterJack_ChangeYear::
# 833 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeYear_Text_0, MSGBOX_DEFAULT
# 834 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 835 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_YEAR, 0, 0, 5, TRUE
# 836 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 841 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_ChangeYear_4
# 838 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 839 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_ChangeMonth
Common_EventScript_PkmnCenterJack_ChangeYear_1:
# 847 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	return

Common_EventScript_PkmnCenterJack_ChangeYear_4:
# 842 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 0
# 843 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 1
# 844 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 2
	goto Common_EventScript_PkmnCenterJack_ChangeYear_1


Common_EventScript_PkmnCenterJack_ChangeMonth::
# 851 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeMonth_Text_0, MSGBOX_DEFAULT
# 852 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 853 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_MONTH, 0, 0, 5, TRUE
# 854 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 859 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_ChangeMonth_4
# 856 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 857 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_ChangeDay
Common_EventScript_PkmnCenterJack_ChangeMonth_1:
# 865 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	return

Common_EventScript_PkmnCenterJack_ChangeMonth_4:
# 860 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 0
# 861 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 1
# 862 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 2
	goto Common_EventScript_PkmnCenterJack_ChangeMonth_1


Common_EventScript_PkmnCenterJack_ChangeDay::
# 869 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeDay_Text_0, MSGBOX_DEFAULT
# 870 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 871 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_DAY, 0, 0, 5, TRUE
# 872 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 883 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_ChangeDay_4
# 874 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 879 "data/scripts/pkmn_center_jack.pory"
	special SetGameDate
# 880 "data/scripts/pkmn_center_jack.pory"
	drawbox
# 881 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeDay_Text_1
Common_EventScript_PkmnCenterJack_ChangeDay_1:
# 890 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	return

Common_EventScript_PkmnCenterJack_ChangeDay_4:
# 884 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 0
# 885 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 1
# 886 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 2
	goto Common_EventScript_PkmnCenterJack_ChangeDay_1


	.align 2
# 896 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_XY:
# 897 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 898 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ABOMASITE
# 899 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ABSOLITE
# 900 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_AERODACTYLITE
# 901 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ALAKAZITE
# 902 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_AMPHAROSITE
# 903 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_AUDINITE
# 904 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BANETTITE
# 905 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BLASTOISINITE
# 906 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CHARIZARDITE_X
# 907 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CHARIZARDITE_Y
# 908 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GALLADITE
# 909 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GARCHOMPITE
# 910 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GARDEVOIRITE
# 911 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GENGARITE
# 912 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GYARADOSITE
# 913 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_HERACRONITE
# 914 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_HOUNDOOMINITE
# 915 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_KANGASKHANITE
# 916 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LUCARIONITE
# 917 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MANECTITE
# 918 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MAWILITE
# 919 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MEDICHAMITE
# 920 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_PINSIRITE
# 921 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SCIZORITE
# 922 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TYRANITARITE
# 923 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_VENUSAURITE
	.2byte ITEM_NONE

	.align 2
# 926 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_ORAS:
# 927 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 928 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BLAZIKENITE
# 929 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BEEDRILLITE
# 930 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_PIDGEOTITE
# 931 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SLOWBRONITE
# 932 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_STEELIXITE
# 933 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SWAMPERTITE
# 934 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SCEPTILITE
# 935 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SABLENITE
# 936 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SHARPEDONITE
# 937 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CAMERUPTITE
# 938 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ALTARIANITE
# 939 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GLALITITE
# 940 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SALAMENCITE
# 941 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_METAGROSSITE
# 942 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LOPUNNITE
	.2byte ITEM_NONE

	.align 2
# 945 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_G:
# 946 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 947 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_VENAUSURITE_G
# 948 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BLASTOISTE_G
# 949 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GRIMMSNARLITE
# 950 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_RILABOOMITE
# 951 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CINDERACITE
# 952 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_INTELEONITE
# 953 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TOXTRICITITE
# 954 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ALCREMITE
# 955 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_APPLETITE
# 956 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BUTTERFRITE
# 957 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CENTISITE
# 958 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_COALOSSITE
# 959 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CORVIKNITE
# 960 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DREDNAWITE
# 961 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FLAPPLITE
# 962 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GARBODORITE
# 963 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_HATTERENITE
# 964 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_KINGLERITE
# 965 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LAPRITE
# 966 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MACHAMPITE
# 967 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ORBEETLITE
# 968 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SANDACONDITE
# 969 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SNORLAXITE
	.2byte ITEM_NONE

	.align 2
# 972 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_ER:
# 973 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 974 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SLOWKINGITE
# 975 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CROBATITE
# 976 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DEWGONGITE
# 977 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TYPHLOSIONITE
# 978 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LANTURNITE
# 979 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_QUAGSIRITE
# 980 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BRELOOMITE
# 981 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SHEDINJITE
# 982 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FLYGONITE
# 983 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MILOTICITE
# 984 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SERPERIORITE
# 985 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SAMUROTTITE
# 986 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_RIBOMBITE
# 987 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CLODSIRITE
# 988 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SANDSLASHITE
# 989 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TOUCANNONITE
# 990 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_VANILLUXITE
# 991 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TINKATITE
# 992 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SHUCKLENITE
# 993 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_KROOKODILENITE
# 994 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TSEERENITE
# 995 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LUXRAYNITE
# 996 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CLEFABLITE_R
# 998 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ARBOKITE
	.2byte ITEM_NONE

	.align 2
# 1001 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_ZA_DLC:
# 1002 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 1003 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CHIMECHITE
# 1004 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ABSOLITE_Z
# 1005 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_STARAPTORITE
# 1006 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GARCHOMPITE_Z
# 1007 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LUCARIONITE_Z
# 1008 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MEOWSTITE
# 1009 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GOLURKITE
# 1010 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CRABOMINABLITE
# 1011 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GOLISPODITE
# 1012 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MAGEARNITE
# 1013 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SCOVILLAINITE
# 1014 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GLIMMORITE
# 1015 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TATSIGIRITE
# 1016 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BAXCALIBURITE
# 1017 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_RAICHUNITE_X
# 1018 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_RAICHUNITE_Y
	.2byte ITEM_NONE

	.align 2
# 1021 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_Legendaries:
# 1022 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 1023 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_RED_ORB
# 1024 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BLUE_ORB
# 1026 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DARKRAITE
# 1030 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MELMETALITE
# 1031 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MEWTWONITE_X
# 1032 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MEWTWONITE_Y
# 1034 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FLOETTITE
# 1035 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LATIASITE
# 1036 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LATIOSITE
# 1037 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DIANCITE
	.2byte ITEM_NONE

	.align 2
# 1040 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_ZA:
# 1041 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 1042 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CLEFABLITE
# 1043 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_VICTRIBELITE
# 1044 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_STARMINITE
# 1045 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DRAGONINITE
# 1046 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MEGANIUMITE
# 1047 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FERALIGITE
# 1048 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SKARMORITE
# 1049 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FROSLASSITE
# 1050 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_EMBOARITE
# 1051 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_EXCADRITE
# 1052 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SCOLIPITE
# 1053 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SCRAFTINITE
# 1054 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_EELEKTROSSITE
# 1055 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CHANDELURITE
# 1056 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DELPHOXITE
# 1057 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CHESNAUGHTITE
# 1058 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GRENINJITE
# 1059 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_PYROARITE
# 1060 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MALAMARITE
# 1061 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BARBARACITE
# 1062 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DRAGALGITE
# 1063 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_HAWLUCHANITE
# 1064 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DRAMPANITE
# 1065 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FALINKSITE
	.2byte ITEM_NONE

Common_Mega_Stone_Guru_No_Braclet::
# 1069 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_Mega_Stone_Guru_No_Braclet_Text_0, MSGBOX_NPC
# 1070 "data/scripts/pkmn_center_jack.pory"
	release
	end


Common_Mega_Stone_Guru_XY::
# 1075 "data/scripts/pkmn_center_jack.pory"
	lock
# 1076 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1077 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_XY_2
Common_Mega_Stone_Guru_XY_1:
# 1080 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1081 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1082 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_XY_Text_0
# 1083 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1084 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_XY
# 1085 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1086 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_XY_2:
# 1078 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_XY_1


Common_Mega_Stone_Guru_ORAS::
# 1091 "data/scripts/pkmn_center_jack.pory"
	lock
# 1092 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1093 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_ORAS_2
Common_Mega_Stone_Guru_ORAS_1:
# 1096 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1097 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1098 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_ORAS_Text_0
# 1099 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1100 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_ORAS
# 1101 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1102 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_ORAS_2:
# 1094 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_ORAS_1


Common_Mega_Stone_Guru_SWSH::
# 1107 "data/scripts/pkmn_center_jack.pory"
	lock
# 1108 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1109 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_SWSH_2
Common_Mega_Stone_Guru_SWSH_1:
# 1112 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1113 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1114 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_SWSH_Text_0
# 1115 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1116 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_G
# 1117 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1118 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_SWSH_2:
# 1110 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_SWSH_1


Common_Mega_Stone_Guru_ZA::
# 1123 "data/scripts/pkmn_center_jack.pory"
	lock
# 1124 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1125 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_ZA_2
Common_Mega_Stone_Guru_ZA_1:
# 1128 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1129 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1130 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_ZA_Text_0
# 1131 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1132 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_ZA
# 1133 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1134 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_ZA_2:
# 1126 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_ZA_1


Common_Mega_Stone_Guru_ZA_DLC::
# 1139 "data/scripts/pkmn_center_jack.pory"
	lock
# 1140 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1141 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_ZA_DLC_2
Common_Mega_Stone_Guru_ZA_DLC_1:
# 1144 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1145 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1146 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_ZA_DLC_Text_0
# 1147 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1148 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_ZA_DLC
# 1149 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1150 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_ZA_DLC_2:
# 1142 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_ZA_DLC_1


Common_Mega_Stone_Guru_ER::
# 1155 "data/scripts/pkmn_center_jack.pory"
	lock
# 1156 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1157 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_ER_2
Common_Mega_Stone_Guru_ER_1:
# 1160 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1161 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1162 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_ER_Text_0
# 1163 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1164 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_ER
# 1165 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1166 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_ER_2:
# 1158 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_ER_1


Common_Mega_Stone_Guru_Legendary::
# 1171 "data/scripts/pkmn_center_jack.pory"
	lock
# 1172 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1173 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_Legendary_2
Common_Mega_Stone_Guru_Legendary_1:
# 1176 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1177 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1178 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_Legendary_Text_0
# 1179 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1180 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_Legendaries
# 1181 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1182 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_Legendary_2:
# 1174 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_Legendary_1


OldaleTown_House1_EventScript_BattleMart_Mega::
# 1187 "data/scripts/pkmn_center_jack.pory"
	lock
# 1188 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1189 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, OldaleTown_House1_EventScript_BattleMart_Mega_2
OldaleTown_House1_EventScript_BattleMart_Mega_1:
# 1192 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1193 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1194 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_XY_Text_0
# 1195 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1196 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_XY
# 1197 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1198 "data/scripts/pkmn_center_jack.pory"
	release
	end

OldaleTown_House1_EventScript_BattleMart_Mega_2:
# 1190 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto OldaleTown_House1_EventScript_BattleMart_Mega_1


Common_EventScript_PkmnCenterJack_Text_0:
# 24 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry you can't learn or forget moves\n"
	.string "on this mode!$"

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_0:
# 80 "data/scripts/pkmn_center_jack.pory"
	.string "Do you want to {COLOR GREEN}enable{COLOR DARK_GREY} the {COLOR BLUE}Double Battle\n"
	.string "Mode{COLOR DARK_GREY}?$"

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_1:
# 85 "data/scripts/pkmn_center_jack.pory"
	.string "Do you want to {COLOR RED}disable{COLOR DARK_GREY} the {COLOR BLUE}Double\n"
	.string "Battle Mode{COLOR DARK_GREY}?$"

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_2:
# 94 "data/scripts/pkmn_center_jack.pory"
	.string "The {COLOR BLUE}Double Battle Mode{COLOR DARK_GREY} was {COLOR GREEN}enabled{COLOR DARK_GREY}!$"

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_3:
# 100 "data/scripts/pkmn_center_jack.pory"
	.string "The {COLOR BLUE}Double Battle Mode{COLOR DARK_GREY} was {COLOR RED}disabled{COLOR DARK_GREY}!$"

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_4:
# 106 "data/scripts/pkmn_center_jack.pory"
	.string "This will make every battle a Double\n"
	.string "Battle as long as you have 2 Pokémon\l"
	.string "that can battle.$"

Common_EventScript_PkmnCenterJack_Lower_Difficulty_Text_0:
# 370 "data/scripts/pkmn_center_jack.pory"
	.string "Do you want to lower the difficulty?$"

Common_EventScript_PkmnCenterJack_Lower_Difficulty_Text_1:
# 376 "data/scripts/pkmn_center_jack.pory"
	.string "The difficulty became Normal.$"

Common_EventScript_PkmnCenterJack_Lower_Difficulty_Text_2:
# 381 "data/scripts/pkmn_center_jack.pory"
	.string "The difficulty became Easy.$"

Common_EventScript_PkmnCenterJack_Lower_Difficulty_Text_3:
# 395 "data/scripts/pkmn_center_jack.pory"
	.string "You are already in the lowest\n"
	.string "difficulty!$"

Common_EventScript_PkmnCenterJack_Change_Costume_Text_0:
# 405 "data/scripts/pkmn_center_jack.pory"
	.string "What outfit do you want to use today?$"

Common_EventScript_PkmnCenterJack_Change_Costume_Text_1:
# 412 "data/scripts/pkmn_center_jack.pory"
	.string "Come this way so you can change your\n"
	.string "outfit$"

Common_EventScript_PkmnCenterJack_Change_Costume_Text_2:
# 447 "data/scripts/pkmn_center_jack.pory"
	.string "Come back anytime you want to change\n"
	.string "outfits!$"

Common_EventScript_PkmnCenterJack_WonderTrade_Text_0:
# 520 "data/scripts/pkmn_center_jack.pory"
	.string "Do you want to try Wonder Trading, its\n"
	.string "only 5BP per try?$"

Common_EventScript_PkmnCenterJack_WonderTrade_Text_1:
# 523 "data/scripts/pkmn_center_jack.pory"
	.string "Do you want to try Wonder Trading?, its\n"
	.string "free for you$"

Common_EventScript_PkmnCenterJack_WonderTrade_Text_2:
# 537 "data/scripts/pkmn_center_jack.pory"
	.string "But it seems you can't afford wonder\n"
	.string "trading right now.\p"
	.string "Please come back when you have atleast\n"
	.string "5BP.$"

Common_EventScript_PkmnCenterJack_WonderTrade_Text_3:
# 567 "data/scripts/pkmn_center_jack.pory"
	.string "Please take care of your new Pokémon.$"

Common_EventScript_PkmnCenterJack_WonderTrade_Cancel_Text_0:
# 575 "data/scripts/pkmn_center_jack.pory"
	.string "All right. Let me know if you want to\n"
	.string "give it a try.$"

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_0:
# 587 "data/scripts/pkmn_center_jack.pory"
	.string "Learning an Egg move will cost you 4\n"
	.string "Battle Points, do you want to continue?$"

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_1:
# 598 "data/scripts/pkmn_center_jack.pory"
	.string "It seems like you don't have enough\n"
	.string "Battle Points!$"

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_2:
# 609 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry, you need 6 badges to use this\n"
	.string "service!$"

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_0:
# 615 "data/scripts/pkmn_center_jack.pory"
	.string "Which Pokémon should I teach a move?$"

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_1:
# 624 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry, I can't teach moves to an Egg!$"

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_2:
# 629 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry, this Pokémon can't learn any\n"
	.string "Tutor Move!$"

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_3:
# 633 "data/scripts/pkmn_center_jack.pory"
	.string "Which move should I teach it?$"

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_4:
# 643 "data/scripts/pkmn_center_jack.pory"
	.string "Your Pokémon was able to learn the move\n"
	.string "successfuly, please continue to use\l"
	.string "our services!$"

Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_Text_0:
# 660 "data/scripts/pkmn_center_jack.pory"
	.string "Learning a Tutor move will cost you 6\n"
	.string "Battle Points, do you want to continue?$"

Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_Text_1:
# 682 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry, you need 9 badges to use this\n"
	.string "service!$"

Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_Text_0:
# 733 "data/scripts/pkmn_center_jack.pory"
	.string "Learning a TM move will cost you 8\n"
	.string "Battle Points, do you want to continue?$"

Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_Text_1:
# 755 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry, you need 12 badges to use this\n"
	.string "service!$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_0:
# 799 "data/scripts/pkmn_center_jack.pory"
	.string "Please chose the season you like the\n"
	.string "best.$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_1:
# 806 "data/scripts/pkmn_center_jack.pory"
	.string "You will play in Spring!$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_2:
# 811 "data/scripts/pkmn_center_jack.pory"
	.string "You will play in Summer!$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_3:
# 816 "data/scripts/pkmn_center_jack.pory"
	.string "You will play in Autumn!$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_4:
# 821 "data/scripts/pkmn_center_jack.pory"
	.string "You will play in Winter!$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_5:
# 824 "data/scripts/pkmn_center_jack.pory"
	.string "The season will update according to the\n"
	.string "real time!$"

Common_EventScript_PkmnCenterJack_ChangeYear_Text_0:
# 833 "data/scripts/pkmn_center_jack.pory"
	.string "Please tell me the current year$"

Common_EventScript_PkmnCenterJack_ChangeMonth_Text_0:
# 851 "data/scripts/pkmn_center_jack.pory"
	.string "Please tell me the current month$"

Common_EventScript_PkmnCenterJack_ChangeDay_Text_0:
# 869 "data/scripts/pkmn_center_jack.pory"
	.string "Please tell me the current day$"

Common_EventScript_PkmnCenterJack_ChangeDay_Text_1:
# 881 "data/scripts/pkmn_center_jack.pory"
	.string "You Changed the Date!$"

Common_Mega_Stone_Guru_No_Braclet_Text_0:
# 1069 "data/scripts/pkmn_center_jack.pory"
	.string "I'm an stone collector, I have a big\n"
	.string "collection but I don't know what to do\l"
	.string "with it right now, maybe I could sell\l"
	.string "them in a time of need.$"

Common_Mega_Stone_Guru_XY_Text_0:
# 1082 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell rare stones from Kalos!,\n"
	.string "How may I serve you?$"

Common_Mega_Stone_Guru_ORAS_Text_0:
# 1098 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell rare stones!, How may I\n"
	.string "serve you?$"

Common_Mega_Stone_Guru_SWSH_Text_0:
# 1114 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell big stones from Galar!, How\n"
	.string "may I serve you?$"

Common_Mega_Stone_Guru_ZA_Text_0:
# 1130 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell shiny new stones from\n"
	.string "Kalos!, How may I serve you?$"

Common_Mega_Stone_Guru_ZA_DLC_Text_0:
# 1146 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell weird stones from Kalos!,\n"
	.string "How may I serve you?$"

Common_Mega_Stone_Guru_ER_Text_0:
# 1162 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell rare stones from a strange\n"
	.string "place!, How may I serve you?$"

Common_Mega_Stone_Guru_Legendary_Text_0:
# 1178 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell powerful stones!, How may I\n"
	.string "serve you?$"
