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
# 410 "data/scripts/pkmn_center_jack.pory"
	lock
# 411 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 412 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_0, MSGBOX_DEFAULT
# 413 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_COSTUMES, 0, 0, 6, TRUE
# 414 "data/scripts/pkmn_center_jack.pory"
	special ApplyCostumeChoice
# 415 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq Common_EventScript_PkmnCenterJack_Change_Costume_2
# 419 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_2, MSGBOX_DEFAULT
Common_EventScript_PkmnCenterJack_Change_Costume_1:
# 421 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end

Common_EventScript_PkmnCenterJack_Change_Costume_2:
# 416 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1


Common_EventScript_PkmnCenterJack_WonderTrade::
# 427 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
# 428 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 429 "data/scripts/pkmn_center_jack.pory"
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
# 430 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x8009, VAR_RESULT
# 432 "data/scripts/pkmn_center_jack.pory"
	checkitem ITEM_WONDER_CHARM, 1
# 433 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_2
# 439 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_WonderTrade_Text_1, MSGBOX_YESNO
Common_EventScript_PkmnCenterJack_WonderTrade_1:
# 442 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, NO
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_6
# 447 "data/scripts/pkmn_center_jack.pory"
	checkitem ITEM_WONDER_CHARM, 1
# 448 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_10
Common_EventScript_PkmnCenterJack_WonderTrade_9:
# 452 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_12
# 457 "data/scripts/pkmn_center_jack.pory"
	special ChoosePartyMon
# 458 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 460 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 0xFF
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_16
Common_EventScript_PkmnCenterJack_WonderTrade_15:
# 463 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 464 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 465 "data/scripts/pkmn_center_jack.pory"
	specialvar VAR_RESULT, GetTradeSpecies
# 466 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x800B, VAR_RESULT
# 467 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, VAR_0x8009
# 468 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 469 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 470 "data/scripts/pkmn_center_jack.pory"
	special CreateInGameWonderTradePokemon
# 471 "data/scripts/pkmn_center_jack.pory"
	special DoInGameTradeScene
# 472 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 473 "data/scripts/pkmn_center_jack.pory"
	special DestroyFollower
# 474 "data/scripts/pkmn_center_jack.pory"
	bufferspeciesname 0, VAR_0x8009
# 475 "data/scripts/pkmn_center_jack.pory"
	playse SE_SHOP
# 477 "data/scripts/pkmn_center_jack.pory"
	checkitem ITEM_WONDER_CHARM, 1
# 478 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_19
Common_EventScript_PkmnCenterJack_WonderTrade_18:
# 482 "data/scripts/pkmn_center_jack.pory"
	clearflag FLAG_FOLLOWER_IS_ENABLED
# 483 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_WonderTrade_Text_3, MSGBOX_DEFAULT
Common_EventScript_PkmnCenterJack_WonderTrade_5:
# 486 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_EventScript_PkmnCenterJack_WonderTrade_2:
# 434 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 435 "data/scripts/pkmn_center_jack.pory"
	showbpbox 0, 0, 0
# 436 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_WonderTrade_Text_0, MSGBOX_YESNO
	goto Common_EventScript_PkmnCenterJack_WonderTrade_1

Common_EventScript_PkmnCenterJack_WonderTrade_6:
# 443 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_WonderTrade_Cancel
	goto Common_EventScript_PkmnCenterJack_WonderTrade_5

Common_EventScript_PkmnCenterJack_WonderTrade_10:
# 449 "data/scripts/pkmn_center_jack.pory"
	checkbp WONDER_TRADE_PRICE, 0
	goto Common_EventScript_PkmnCenterJack_WonderTrade_9

Common_EventScript_PkmnCenterJack_WonderTrade_12:
# 453 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_WonderTrade_Text_2, MSGBOX_DEFAULT
# 454 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, 0
	goto Common_EventScript_PkmnCenterJack_WonderTrade_5

Common_EventScript_PkmnCenterJack_WonderTrade_16:
# 461 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_WonderTrade_Cancel
	goto Common_EventScript_PkmnCenterJack_WonderTrade_15

Common_EventScript_PkmnCenterJack_WonderTrade_19:
# 479 "data/scripts/pkmn_center_jack.pory"
	takebp WONDER_TRADE_PRICE, 0
	goto Common_EventScript_PkmnCenterJack_WonderTrade_18


Common_EventScript_PkmnCenterJack_WonderTrade_Cancel::
# 491 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_WonderTrade_Cancel_Text_0, MSGBOX_DEFAULT
# 492 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	return


Common_EventScript_PkmnCenterJack_EggMoveTutor_Price::
# 498 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_PARTY_MENU_TUTOR_STATE, MOVE_TUTOR_EGG_MOVES
# 499 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_IS_MOVE_TUTOR
# 500 "data/scripts/pkmn_center_jack.pory"
	compare VAR_NUM_BADGES, 6
	goto_if_ge Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_1
# 525 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_2, MSGBOX_DEFAULT
# 526 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_1:
# 501 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 502 "data/scripts/pkmn_center_jack.pory"
	showbpbox 0, 0, 0
# 503 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_0, MSGBOX_YESNO
# 504 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_4
# 520 "data/scripts/pkmn_center_jack.pory"
	hidebpbox
# 521 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_4:
# 506 "data/scripts/pkmn_center_jack.pory"
	checkbp 4, 0
# 507 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_7
# 513 "data/scripts/pkmn_center_jack.pory"
	hidebpbox
# 514 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_1, MSGBOX_DEFAULT
# 515 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_7:
# 508 "data/scripts/pkmn_center_jack.pory"
	hidebpbox
# 509 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon::
# 531 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_0, MSGBOX_DEFAULT
# 532 "data/scripts/pkmn_center_jack.pory"
	special ChooseMonForMoveRelearner
# 533 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 534 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_1
# 538 "data/scripts/pkmn_center_jack.pory"
	special IsSelectedMonEgg
# 539 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_4
# 544 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8005, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_7
# 549 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_3, MSGBOX_DEFAULT
# 550 "data/scripts/pkmn_center_jack.pory"
	special TeachMoveRelearnerMove
# 551 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 552 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_10
# 556 "data/scripts/pkmn_center_jack.pory"
	playse SE_SHOP
# 557 "data/scripts/pkmn_center_jack.pory"
	takebp 4, 0
# 558 "data/scripts/pkmn_center_jack.pory"
	call Common_EventScript_PkmnCenterJack_Clear_Move_Tutor_Data
# 559 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_4, MSGBOX_DEFAULT
# 560 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_1:
# 535 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_4:
# 540 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_1, MSGBOX_DEFAULT
# 541 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_7:
# 545 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_2, MSGBOX_DEFAULT
	return

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_10:
# 553 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price::
# 571 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_PARTY_MENU_TUTOR_STATE, MOVE_TUTOR_MOVES
# 572 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_IS_MOVE_TUTOR
# 573 "data/scripts/pkmn_center_jack.pory"
	compare VAR_NUM_BADGES, 9
	goto_if_ge Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_1
# 598 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_Text_1, MSGBOX_DEFAULT
# 599 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_1:
# 574 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 575 "data/scripts/pkmn_center_jack.pory"
	showbpbox 0, 0, 0
# 576 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_Text_0, MSGBOX_YESNO
# 577 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_4
# 593 "data/scripts/pkmn_center_jack.pory"
	hidebpbox
# 594 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_4:
# 579 "data/scripts/pkmn_center_jack.pory"
	checkbp 6, 0
# 580 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_7
# 586 "data/scripts/pkmn_center_jack.pory"
	hidebpbox
# 587 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_1, MSGBOX_DEFAULT
# 588 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_7:
# 581 "data/scripts/pkmn_center_jack.pory"
	hidebpbox
# 582 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon::
# 604 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_0, MSGBOX_DEFAULT
# 605 "data/scripts/pkmn_center_jack.pory"
	special ChooseMonForMoveRelearner
# 606 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 607 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_1
# 611 "data/scripts/pkmn_center_jack.pory"
	special IsSelectedMonEgg
# 612 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_4
# 617 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8005, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_7
# 622 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_3, MSGBOX_DEFAULT
# 623 "data/scripts/pkmn_center_jack.pory"
	special TeachMoveRelearnerMove
# 624 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 625 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_10
# 629 "data/scripts/pkmn_center_jack.pory"
	playse SE_SHOP
# 630 "data/scripts/pkmn_center_jack.pory"
	takebp 6, 0
# 631 "data/scripts/pkmn_center_jack.pory"
	call Common_EventScript_PkmnCenterJack_Clear_Move_Tutor_Data
# 632 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_4, MSGBOX_DEFAULT
# 633 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end

Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_1:
# 608 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_4:
# 613 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_1, MSGBOX_DEFAULT
# 614 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_7:
# 618 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_2, MSGBOX_DEFAULT
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_10:
# 626 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_TmMoveTutor_Price::
# 644 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_PARTY_MENU_TUTOR_STATE, MOVE_TUTOR_TM_MOVES
# 645 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_IS_MOVE_TUTOR
# 646 "data/scripts/pkmn_center_jack.pory"
	compare VAR_NUM_BADGES, 12
	goto_if_ge Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_1
# 671 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_Text_1, MSGBOX_DEFAULT
# 672 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_1:
# 647 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 648 "data/scripts/pkmn_center_jack.pory"
	showbpbox 0, 0, 0
# 649 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_Text_0, MSGBOX_YESNO
# 650 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_4
# 666 "data/scripts/pkmn_center_jack.pory"
	hidebpbox
# 667 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_4:
# 652 "data/scripts/pkmn_center_jack.pory"
	checkbp 8, 0
# 653 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_7
# 659 "data/scripts/pkmn_center_jack.pory"
	hidebpbox
# 660 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_1, MSGBOX_DEFAULT
# 661 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_7:
# 654 "data/scripts/pkmn_center_jack.pory"
	hidebpbox
# 655 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon::
# 677 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_0, MSGBOX_DEFAULT
# 678 "data/scripts/pkmn_center_jack.pory"
	special ChooseMonForMoveRelearner
# 679 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 680 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_1
# 684 "data/scripts/pkmn_center_jack.pory"
	special IsSelectedMonEgg
# 685 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_4
# 690 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8005, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_7
# 695 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_3, MSGBOX_DEFAULT
# 696 "data/scripts/pkmn_center_jack.pory"
	special TeachMoveRelearnerMove
# 697 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 698 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_10
# 702 "data/scripts/pkmn_center_jack.pory"
	playse SE_SHOP
# 703 "data/scripts/pkmn_center_jack.pory"
	takebp 8, 0
# 704 "data/scripts/pkmn_center_jack.pory"
	call Common_EventScript_PkmnCenterJack_Clear_Move_Tutor_Data
# 705 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_4, MSGBOX_DEFAULT
# 706 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end

Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_1:
# 681 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_4:
# 686 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_1, MSGBOX_DEFAULT
# 687 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_7:
# 691 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_2, MSGBOX_DEFAULT
	return

Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_10:
# 699 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_ChangeSeason::
# 715 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_0, MSGBOX_DEFAULT
# 716 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 717 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_SEASONS, 0, 0, 5, TRUE
# 718 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 719 "data/scripts/pkmn_center_jack.pory"
	case SEASON_SPRING, Common_EventScript_PkmnCenterJack_ChangeSeason_3
# 724 "data/scripts/pkmn_center_jack.pory"
	case SEASON_SUMMER, Common_EventScript_PkmnCenterJack_ChangeSeason_4
# 729 "data/scripts/pkmn_center_jack.pory"
	case SEASON_AUTUMN, Common_EventScript_PkmnCenterJack_ChangeSeason_5
# 734 "data/scripts/pkmn_center_jack.pory"
	case SEASON_WINTER, Common_EventScript_PkmnCenterJack_ChangeSeason_6
# 742 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_ChangeSeason_8
# 740 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_5
Common_EventScript_PkmnCenterJack_ChangeSeason_1:
# 745 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	return

Common_EventScript_PkmnCenterJack_ChangeSeason_3:
# 720 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_CURRENT_SEASON, SEASON_SPRING
# 721 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_SYS_DISABLE_AUTOMATIC_SEASON
# 722 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_1
	goto Common_EventScript_PkmnCenterJack_ChangeSeason_1

Common_EventScript_PkmnCenterJack_ChangeSeason_4:
# 725 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_CURRENT_SEASON, SEASON_SUMMER
# 726 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_SYS_DISABLE_AUTOMATIC_SEASON
# 727 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_2
	goto Common_EventScript_PkmnCenterJack_ChangeSeason_1

Common_EventScript_PkmnCenterJack_ChangeSeason_5:
# 730 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_CURRENT_SEASON, SEASON_AUTUMN
# 731 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_SYS_DISABLE_AUTOMATIC_SEASON
# 732 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_3
	goto Common_EventScript_PkmnCenterJack_ChangeSeason_1

Common_EventScript_PkmnCenterJack_ChangeSeason_6:
# 735 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_CURRENT_SEASON, SEASON_WINTER
# 736 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_SYS_DISABLE_AUTOMATIC_SEASON
# 737 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_4
	goto Common_EventScript_PkmnCenterJack_ChangeSeason_1

Common_EventScript_PkmnCenterJack_ChangeSeason_8:
	goto Common_EventScript_PkmnCenterJack_ChangeSeason_1


Common_EventScript_PkmnCenterJack_ChangeYear::
# 749 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeYear_Text_0, MSGBOX_DEFAULT
# 750 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 751 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_YEAR, 0, 0, 5, TRUE
# 752 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 757 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_ChangeYear_4
# 754 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 755 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_ChangeMonth
Common_EventScript_PkmnCenterJack_ChangeYear_1:
# 763 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	return

Common_EventScript_PkmnCenterJack_ChangeYear_4:
# 758 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 0
# 759 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 1
# 760 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 2
	goto Common_EventScript_PkmnCenterJack_ChangeYear_1


Common_EventScript_PkmnCenterJack_ChangeMonth::
# 767 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeMonth_Text_0, MSGBOX_DEFAULT
# 768 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 769 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_MONTH, 0, 0, 5, TRUE
# 770 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 775 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_ChangeMonth_4
# 772 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 773 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_ChangeDay
Common_EventScript_PkmnCenterJack_ChangeMonth_1:
# 781 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	return

Common_EventScript_PkmnCenterJack_ChangeMonth_4:
# 776 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 0
# 777 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 1
# 778 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 2
	goto Common_EventScript_PkmnCenterJack_ChangeMonth_1


Common_EventScript_PkmnCenterJack_ChangeDay::
# 785 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeDay_Text_0, MSGBOX_DEFAULT
# 786 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 787 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_DAY, 0, 0, 5, TRUE
# 788 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 799 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_ChangeDay_4
# 790 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 795 "data/scripts/pkmn_center_jack.pory"
	special SetGameDate
# 796 "data/scripts/pkmn_center_jack.pory"
	drawbox
# 797 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeDay_Text_1
Common_EventScript_PkmnCenterJack_ChangeDay_1:
# 806 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	return

Common_EventScript_PkmnCenterJack_ChangeDay_4:
# 800 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 0
# 801 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 1
# 802 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 2
	goto Common_EventScript_PkmnCenterJack_ChangeDay_1


	.align 2
# 812 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_XY:
# 813 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 814 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ABOMASITE
# 815 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ABSOLITE
# 816 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_AERODACTYLITE
# 817 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ALAKAZITE
# 818 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_AMPHAROSITE
# 819 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_AUDINITE
# 820 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BANETTITE
# 821 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BLASTOISINITE
# 822 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CHARIZARDITE_X
# 823 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CHARIZARDITE_Y
# 824 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GALLADITE
# 825 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GARCHOMPITE
# 826 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GARDEVOIRITE
# 827 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GENGARITE
# 828 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GYARADOSITE
# 829 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_HERACRONITE
# 830 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_HOUNDOOMINITE
# 831 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_KANGASKHANITE
# 832 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LUCARIONITE
# 833 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MANECTITE
# 834 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MAWILITE
# 835 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MEDICHAMITE
# 836 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_PINSIRITE
# 837 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SCIZORITE
# 838 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TYRANITARITE
# 839 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_VENUSAURITE
	.2byte ITEM_NONE

	.align 2
# 842 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_ORAS:
# 843 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 844 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BLAZIKENITE
# 845 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BEEDRILLITE
# 846 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_PIDGEOTITE
# 847 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SLOWBRONITE
# 848 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_STEELIXITE
# 849 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SWAMPERTITE
# 850 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SCEPTILITE
# 851 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SABLENITE
# 852 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SHARPEDONITE
# 853 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CAMERUPTITE
# 854 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ALTARIANITE
# 855 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GLALITITE
# 856 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SALAMENCITE
# 857 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_METAGROSSITE
# 858 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LOPUNNITE
	.2byte ITEM_NONE

	.align 2
# 861 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_G:
# 862 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 863 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_VENAUSURITE_G
# 864 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BLASTOISTE_G
# 865 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GRIMMSNARLITE
# 866 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_RILABOOMITE
# 867 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CINDERACITE
# 868 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_INTELEONITE
# 869 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TOXTRICITITE
# 870 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ALCREMITE
# 871 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_APPLETITE
# 872 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BUTTERFRITE
# 873 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CENTISITE
# 874 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_COALOSSITE
# 875 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CORVIKNITE
# 876 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DREDNAWITE
# 877 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FLAPPLITE
# 878 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GARBODORITE
# 879 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_HATTERENITE
# 880 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_KINGLERITE
# 881 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LAPRITE
# 882 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MACHAMPITE
# 883 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ORBEETLITE
# 884 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SANDACONDITE
# 885 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SNORLAXITE
	.2byte ITEM_NONE

	.align 2
# 888 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_ER:
# 889 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 890 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SLOWKINGITE
# 891 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CROBATITE
# 892 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DEWGONGITE
# 893 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TYPHLOSIONITE
# 894 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LANTURNITE
# 895 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_QUAGSIRITE
# 896 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BRELOOMITE
# 897 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SHEDINJITE
# 898 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FLYGONITE
# 899 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MILOTICITE
# 900 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SERPERIORITE
# 901 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SAMUROTTITE
# 902 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_RIBOMBITE
# 903 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CLODSIRITE
# 904 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SANDSLASHITE
# 905 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TOUCANNONITE
# 906 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_VANILLUXITE
# 907 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TINKATITE
# 908 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SHUCKLENITE
# 909 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_KROOKODILENITE
# 910 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TSEERENITE
# 911 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LUXRAYNITE
# 912 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CLEFABLITE_R
# 914 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ARBOKITE
	.2byte ITEM_NONE

	.align 2
# 917 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_ZA_DLC:
# 918 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 919 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CHIMECHITE
# 920 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ABSOLITE_Z
# 921 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_STARAPTORITE
# 922 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GARCHOMPITE_Z
# 923 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LUCARIONITE_Z
# 924 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MEOWSTITE
# 925 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GOLURKITE
# 926 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CRABOMINABLITE
# 927 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GOLISPODITE
# 928 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MAGEARNITE
# 929 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SCOVILLAINITE
# 930 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GLIMMORITE
# 931 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TATSIGIRITE
# 932 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BAXCALIBURITE
# 933 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_RAICHUNITE_X
# 934 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_RAICHUNITE_Y
	.2byte ITEM_NONE

	.align 2
# 937 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_Legendaries:
# 938 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 939 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_RED_ORB
# 940 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BLUE_ORB
# 942 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DARKRAITE
# 946 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MELMETALITE
# 947 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MEWTWONITE_X
# 948 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MEWTWONITE_Y
# 950 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FLOETTITE
# 951 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LATIASITE
# 952 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LATIOSITE
# 953 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DIANCITE
	.2byte ITEM_NONE

	.align 2
# 956 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_ZA:
# 957 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 958 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CLEFABLITE
# 959 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_VICTRIBELITE
# 960 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_STARMINITE
# 961 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DRAGONINITE
# 962 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MEGANIUMITE
# 963 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FERALIGITE
# 964 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SKARMORITE
# 965 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FROSLASSITE
# 966 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_EMBOARITE
# 967 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_EXCADRITE
# 968 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SCOLIPITE
# 969 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SCRAFTINITE
# 970 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_EELEKTROSSITE
# 971 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CHANDELURITE
# 972 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DELPHOXITE
# 973 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CHESNAUGHTITE
# 974 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GRENINJITE
# 975 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_PYROARITE
# 976 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MALAMARITE
# 977 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BARBARACITE
# 978 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DRAGALGITE
# 979 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_HAWLUCHANITE
# 980 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DRAMPANITE
# 981 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FALINKSITE
	.2byte ITEM_NONE

Common_Mega_Stone_Guru_No_Braclet::
# 985 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_Mega_Stone_Guru_No_Braclet_Text_0, MSGBOX_NPC
# 986 "data/scripts/pkmn_center_jack.pory"
	release
	end


Common_Mega_Stone_Guru_XY::
# 991 "data/scripts/pkmn_center_jack.pory"
	lock
# 992 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 993 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_XY_2
Common_Mega_Stone_Guru_XY_1:
# 996 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 997 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 998 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_XY_Text_0
# 999 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1000 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_XY
# 1001 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1002 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_XY_2:
# 994 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_XY_1


Common_Mega_Stone_Guru_ORAS::
# 1007 "data/scripts/pkmn_center_jack.pory"
	lock
# 1008 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1009 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_ORAS_2
Common_Mega_Stone_Guru_ORAS_1:
# 1012 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1013 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1014 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_ORAS_Text_0
# 1015 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1016 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_ORAS
# 1017 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1018 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_ORAS_2:
# 1010 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_ORAS_1


Common_Mega_Stone_Guru_SWSH::
# 1023 "data/scripts/pkmn_center_jack.pory"
	lock
# 1024 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1025 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_SWSH_2
Common_Mega_Stone_Guru_SWSH_1:
# 1028 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1029 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1030 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_SWSH_Text_0
# 1031 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1032 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_G
# 1033 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1034 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_SWSH_2:
# 1026 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_SWSH_1


Common_Mega_Stone_Guru_ZA::
# 1039 "data/scripts/pkmn_center_jack.pory"
	lock
# 1040 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1041 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_ZA_2
Common_Mega_Stone_Guru_ZA_1:
# 1044 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1045 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1046 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_ZA_Text_0
# 1047 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1048 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_ZA
# 1049 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1050 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_ZA_2:
# 1042 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_ZA_1


Common_Mega_Stone_Guru_ZA_DLC::
# 1055 "data/scripts/pkmn_center_jack.pory"
	lock
# 1056 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1057 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_ZA_DLC_2
Common_Mega_Stone_Guru_ZA_DLC_1:
# 1060 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1061 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1062 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_ZA_DLC_Text_0
# 1063 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1064 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_ZA_DLC
# 1065 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1066 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_ZA_DLC_2:
# 1058 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_ZA_DLC_1


Common_Mega_Stone_Guru_ER::
# 1071 "data/scripts/pkmn_center_jack.pory"
	lock
# 1072 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1073 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_ER_2
Common_Mega_Stone_Guru_ER_1:
# 1076 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1077 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1078 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_ER_Text_0
# 1079 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1080 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_ER
# 1081 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1082 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_ER_2:
# 1074 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_ER_1


Common_Mega_Stone_Guru_Legendary::
# 1087 "data/scripts/pkmn_center_jack.pory"
	lock
# 1088 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1089 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_Legendary_2
Common_Mega_Stone_Guru_Legendary_1:
# 1092 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1093 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1094 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_Legendary_Text_0
# 1095 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1096 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_Legendaries
# 1097 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1098 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_Legendary_2:
# 1090 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_Legendary_1


OldaleTown_House1_EventScript_BattleMart_Mega::
# 1103 "data/scripts/pkmn_center_jack.pory"
	lock
# 1104 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1105 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, OldaleTown_House1_EventScript_BattleMart_Mega_2
OldaleTown_House1_EventScript_BattleMart_Mega_1:
# 1108 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1109 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1110 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_XY_Text_0
# 1111 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1112 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_XY
# 1113 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1114 "data/scripts/pkmn_center_jack.pory"
	release
	end

OldaleTown_House1_EventScript_BattleMart_Mega_2:
# 1106 "data/scripts/pkmn_center_jack.pory"
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
# 412 "data/scripts/pkmn_center_jack.pory"
	.string "What outfit do you want to use today?$"

Common_EventScript_PkmnCenterJack_Change_Costume_Text_1:
# 416 "data/scripts/pkmn_center_jack.pory"
	.string "Come back anytime you want to change\n"
	.string "outfits!$"

Common_EventScript_PkmnCenterJack_Change_Costume_Text_2:
# 419 "data/scripts/pkmn_center_jack.pory"
	.string "There you go, that outfit looks great\n"
	.string "on you!$"

Common_EventScript_PkmnCenterJack_WonderTrade_Text_0:
# 436 "data/scripts/pkmn_center_jack.pory"
	.string "Do you want to try Wonder Trading, its\n"
	.string "only 5BP per try?$"

Common_EventScript_PkmnCenterJack_WonderTrade_Text_1:
# 439 "data/scripts/pkmn_center_jack.pory"
	.string "Do you want to try Wonder Trading?, its\n"
	.string "free for you$"

Common_EventScript_PkmnCenterJack_WonderTrade_Text_2:
# 453 "data/scripts/pkmn_center_jack.pory"
	.string "But it seems you can't afford wonder\n"
	.string "trading right now.\p"
	.string "Please come back when you have atleast\n"
	.string "5BP.$"

Common_EventScript_PkmnCenterJack_WonderTrade_Text_3:
# 483 "data/scripts/pkmn_center_jack.pory"
	.string "Please take care of your new Pokémon.$"

Common_EventScript_PkmnCenterJack_WonderTrade_Cancel_Text_0:
# 491 "data/scripts/pkmn_center_jack.pory"
	.string "All right. Let me know if you want to\n"
	.string "give it a try.$"

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_0:
# 503 "data/scripts/pkmn_center_jack.pory"
	.string "Learning an Egg move will cost you 4\n"
	.string "Battle Points, do you want to continue?$"

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_1:
# 514 "data/scripts/pkmn_center_jack.pory"
	.string "It seems like you don't have enough\n"
	.string "Battle Points!$"

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_2:
# 525 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry, you need 6 badges to use this\n"
	.string "service!$"

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_0:
# 531 "data/scripts/pkmn_center_jack.pory"
	.string "Which Pokémon should I teach a move?$"

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_1:
# 540 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry, I can't teach moves to an Egg!$"

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_2:
# 545 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry, this Pokémon can't learn any\n"
	.string "Tutor Move!$"

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_3:
# 549 "data/scripts/pkmn_center_jack.pory"
	.string "Which move should I teach it?$"

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_4:
# 559 "data/scripts/pkmn_center_jack.pory"
	.string "Your Pokémon was able to learn the move\n"
	.string "successfuly, please continue to use\l"
	.string "our services!$"

Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_Text_0:
# 576 "data/scripts/pkmn_center_jack.pory"
	.string "Learning a Tutor move will cost you 6\n"
	.string "Battle Points, do you want to continue?$"

Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_Text_1:
# 598 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry, you need 9 badges to use this\n"
	.string "service!$"

Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_Text_0:
# 649 "data/scripts/pkmn_center_jack.pory"
	.string "Learning a TM move will cost you 8\n"
	.string "Battle Points, do you want to continue?$"

Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_Text_1:
# 671 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry, you need 12 badges to use this\n"
	.string "service!$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_0:
# 715 "data/scripts/pkmn_center_jack.pory"
	.string "Please chose the season you like the\n"
	.string "best.$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_1:
# 722 "data/scripts/pkmn_center_jack.pory"
	.string "You will play in Spring!$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_2:
# 727 "data/scripts/pkmn_center_jack.pory"
	.string "You will play in Summer!$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_3:
# 732 "data/scripts/pkmn_center_jack.pory"
	.string "You will play in Autumn!$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_4:
# 737 "data/scripts/pkmn_center_jack.pory"
	.string "You will play in Winter!$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_5:
# 740 "data/scripts/pkmn_center_jack.pory"
	.string "The season will update according to the\n"
	.string "real time!$"

Common_EventScript_PkmnCenterJack_ChangeYear_Text_0:
# 749 "data/scripts/pkmn_center_jack.pory"
	.string "Please tell me the current year$"

Common_EventScript_PkmnCenterJack_ChangeMonth_Text_0:
# 767 "data/scripts/pkmn_center_jack.pory"
	.string "Please tell me the current month$"

Common_EventScript_PkmnCenterJack_ChangeDay_Text_0:
# 785 "data/scripts/pkmn_center_jack.pory"
	.string "Please tell me the current day$"

Common_EventScript_PkmnCenterJack_ChangeDay_Text_1:
# 797 "data/scripts/pkmn_center_jack.pory"
	.string "You Changed the Date!$"

Common_Mega_Stone_Guru_No_Braclet_Text_0:
# 985 "data/scripts/pkmn_center_jack.pory"
	.string "I'm an stone collector, I have a big\n"
	.string "collection but I don't know what to do\l"
	.string "with it right now, maybe I could sell\l"
	.string "them in a time of need.$"

Common_Mega_Stone_Guru_XY_Text_0:
# 998 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell rare stones from Kalos!,\n"
	.string "How may I serve you?$"

Common_Mega_Stone_Guru_ORAS_Text_0:
# 1014 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell rare stones!, How may I\n"
	.string "serve you?$"

Common_Mega_Stone_Guru_SWSH_Text_0:
# 1030 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell big stones from Galar!, How\n"
	.string "may I serve you?$"

Common_Mega_Stone_Guru_ZA_Text_0:
# 1046 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell shiny new stones from\n"
	.string "Kalos!, How may I serve you?$"

Common_Mega_Stone_Guru_ZA_DLC_Text_0:
# 1062 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell weird stones from Kalos!,\n"
	.string "How may I serve you?$"

Common_Mega_Stone_Guru_ER_Text_0:
# 1078 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell rare stones from a strange\n"
	.string "place!, How may I serve you?$"

Common_Mega_Stone_Guru_Legendary_Text_0:
# 1094 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell powerful stones!, How may I\n"
	.string "serve you?$"
