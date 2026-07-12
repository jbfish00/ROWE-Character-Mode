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
Common_EventScript_PkmnCenterJack_11:
# 53 "data/scripts/pkmn_center_jack.pory"
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
	goto_if_set FLAG_METRONOME_ONLY_MODE, Common_EventScript_PkmnCenterJack_13
# 28 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
Common_EventScript_PkmnCenterJack_12:
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

Common_EventScript_PkmnCenterJack_13:
# 24 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Text_0
# 25 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	goto Common_EventScript_PkmnCenterJack_12


Common_EventScript_PkmnCenterJack_Double_Battle_Mode::
# 61 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_DOUBLE_BATTLE_MODE, Common_EventScript_PkmnCenterJack_Double_Battle_Mode_2
# 67 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_1, MSGBOX_DEFAULT
# 68 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 69 "data/scripts/pkmn_center_jack.pory"
	multichoice 0, 0, MULTI_GAME_MODE_DISABLE, 0
Common_EventScript_PkmnCenterJack_Double_Battle_Mode_1:
# 72 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 73 "data/scripts/pkmn_center_jack.pory"
	case 0, Common_EventScript_PkmnCenterJack_Double_Battle_Mode_7
# 87 "data/scripts/pkmn_center_jack.pory"
	case 1, Common_EventScript_PkmnCenterJack_Double_Battle_Mode_8
# 90 "data/scripts/pkmn_center_jack.pory"
	case 2, Common_EventScript_PkmnCenterJack_Double_Battle_Mode_9
# 91 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_Double_Battle_Mode_9
Common_EventScript_PkmnCenterJack_Double_Battle_Mode_5:
# 96 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Double_Battle_Mode
	return

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_2:
# 62 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_0, MSGBOX_DEFAULT
# 63 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 64 "data/scripts/pkmn_center_jack.pory"
	multichoice 0, 0, MULTI_GAME_MODE_ENABLE, 0
	goto Common_EventScript_PkmnCenterJack_Double_Battle_Mode_1

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_7:
# 74 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_DOUBLE_BATTLE_MODE, Common_EventScript_PkmnCenterJack_Double_Battle_Mode_11
# 81 "data/scripts/pkmn_center_jack.pory"
	playfanfare SE_BOO
# 82 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_3, MSGBOX_DEFAULT
# 83 "data/scripts/pkmn_center_jack.pory"
	waitfanfare
# 84 "data/scripts/pkmn_center_jack.pory"
	clearflag FLAG_DOUBLE_BATTLE_MODE
Common_EventScript_PkmnCenterJack_Double_Battle_Mode_10:
	goto Common_EventScript_PkmnCenterJack_Double_Battle_Mode_5

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_8:
# 88 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_4, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterJack_Double_Battle_Mode_5

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_9:
# 92 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_ComeBackAnytime
	goto Common_EventScript_PkmnCenterJack_Double_Battle_Mode_5

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_11:
# 75 "data/scripts/pkmn_center_jack.pory"
	playfanfare SE_SAVE
# 76 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_2, MSGBOX_DEFAULT
# 77 "data/scripts/pkmn_center_jack.pory"
	waitfanfare
# 78 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_DOUBLE_BATTLE_MODE
	goto Common_EventScript_PkmnCenterJack_Double_Battle_Mode_10


Common_EventScript_PkmnCenterJack_Companion_Stuff::
# 100 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_GotPokemonQuestions, MSGBOX_DEFAULT
# 101 "data/scripts/pkmn_center_jack.pory"
	multichoice 16, 0, MULTI_COMPANION_OPTIONS, 0
# 102 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 103 "data/scripts/pkmn_center_jack.pory"
	switch VAR_TEMP_1
# 104 "data/scripts/pkmn_center_jack.pory"
	case 0, Common_EventScript_PkmnCenterJack_Companion_Stuff_3
# 105 "data/scripts/pkmn_center_jack.pory"
	case 4, Common_EventScript_PkmnCenterJack_Companion_Stuff_4
# 106 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_Companion_Stuff_5
Common_EventScript_PkmnCenterJack_Companion_Stuff_1:
	end

Common_EventScript_PkmnCenterJack_Companion_Stuff_3:
# 104 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Companion_Get_Trainer_Password
	goto Common_EventScript_PkmnCenterJack_Companion_Stuff_1

Common_EventScript_PkmnCenterJack_Companion_Stuff_4:
# 105 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	goto Common_EventScript_PkmnCenterJack_Companion_Stuff_1

Common_EventScript_PkmnCenterJack_Companion_Stuff_5:
# 106 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	goto Common_EventScript_PkmnCenterJack_Companion_Stuff_1


Common_EventScript_PkmnCenterJack_ComeBackAnytime::
# 112 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
# 113 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_StartARandomBattle::
# 119 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MockBattle, MSGBOX_DEFAULT
# 120 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 121 "data/scripts/pkmn_center_jack.pory"
	multichoice 0, 0, MULTI_MOCK_BATTLE_OPTIONS, 0
# 122 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 123 "data/scripts/pkmn_center_jack.pory"
	case 0, Common_EventScript_PkmnCenterJack_StartARandomBattle_3
# 124 "data/scripts/pkmn_center_jack.pory"
	case 1, Common_EventScript_PkmnCenterJack_StartARandomBattle_4
# 125 "data/scripts/pkmn_center_jack.pory"
	case 2, Common_EventScript_PkmnCenterJack_StartARandomBattle_5
# 126 "data/scripts/pkmn_center_jack.pory"
	case 3, Common_EventScript_PkmnCenterJack_StartARandomBattle_6
# 127 "data/scripts/pkmn_center_jack.pory"
	case 4, Common_EventScript_PkmnCenterJack_StartARandomBattle_7
# 128 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_StartARandomBattle_8
Common_EventScript_PkmnCenterJack_StartARandomBattle_1:
	end

Common_EventScript_PkmnCenterJack_StartARandomBattle_3:
# 123 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_Easy
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_1

Common_EventScript_PkmnCenterJack_StartARandomBattle_4:
# 124 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_Medium
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_1

Common_EventScript_PkmnCenterJack_StartARandomBattle_5:
# 125 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_Hard
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_1

Common_EventScript_PkmnCenterJack_StartARandomBattle_6:
# 126 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_PSS
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_1

Common_EventScript_PkmnCenterJack_StartARandomBattle_7:
# 127 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_1

Common_EventScript_PkmnCenterJack_StartARandomBattle_8:
# 128 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	goto Common_EventScript_PkmnCenterJack_StartARandomBattle_1


Common_EventScript_PkmnCenterJack_StartARandomBattle_Easy::
# 134 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MockBattle_Easy, MSGBOX_DEFAULT
# 135 "data/scripts/pkmn_center_jack.pory"
	trainerbattle_no_intro TRAINER_NURSE_KIRSTEN, Common_PkmnCenterJack_Text_MockBattle_Defeat
# 136 "data/scripts/pkmn_center_jack.pory"
	special HealPlayerParty
# 137 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
# 138 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_StartARandomBattle_Medium::
# 143 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MockBattle_Normal, MSGBOX_DEFAULT
# 144 "data/scripts/pkmn_center_jack.pory"
	trainerbattle_no_intro TRAINER_NURSE_SACHIKO, Common_PkmnCenterJack_Text_MockBattle_Defeat
# 145 "data/scripts/pkmn_center_jack.pory"
	special HealPlayerParty
# 146 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
# 147 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_StartARandomBattle_Hard::
# 152 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MockBattle_Hard, MSGBOX_DEFAULT
# 153 "data/scripts/pkmn_center_jack.pory"
	trainerbattle_no_intro TRAINER_NURSE_SHERY, Common_PkmnCenterJack_Text_MockBattle_Defeat
# 154 "data/scripts/pkmn_center_jack.pory"
	special HealPlayerParty
# 155 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
# 156 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_StartARandomBattle_PSS::
# 161 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MockBattle_PSS, MSGBOX_DEFAULT
# 162 "data/scripts/pkmn_center_jack.pory"
	trainerbattle_no_intro TRAINER_PSS_TRAINER, Common_PkmnCenterJack_Text_MockBattle_Defeat
# 163 "data/scripts/pkmn_center_jack.pory"
	special HealPlayerParty
# 164 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
# 165 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_NameRater_ChooseMonToRate::
# 171 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
# 172 "data/scripts/pkmn_center_jack.pory"
	special ChoosePartyMon
# 173 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 174 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 255
	goto_if_ne Common_EventScript_PkmnCenterJack_NameRater_ChooseMonToRate_2
Common_EventScript_PkmnCenterJack_NameRater_ChooseMonToRate_1:
# 177 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_NameRater_DeclineNameRate
	end

Common_EventScript_PkmnCenterJack_NameRater_ChooseMonToRate_2:
# 175 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname
	goto Common_EventScript_PkmnCenterJack_NameRater_ChooseMonToRate_1


Common_EventScript_PkmnCenterJack_NameRater_DeclineNameRate::
# 182 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_DoVisitAgain, MSGBOX_DEFAULT
# 183 "data/scripts/pkmn_center_jack.pory"
	release
	end


Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname::
# 188 "data/scripts/pkmn_center_jack.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 189 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname_2
Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname_1:
# 192 "data/scripts/pkmn_center_jack.pory"
	special BufferMonNickname
# 193 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
# 194 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname_5
Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname_4:
# 197 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_NameRater_DeclineNameRate
	end

Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname_2:
# 190 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_NameRater_CantRateEgg
	goto Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname_1

Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname_5:
# 195 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_NameRater_ChangeNickname
	goto Common_EventScript_PkmnCenterJack_NameRater_RateMonNickname_4


Common_EventScript_PkmnCenterJack_NameRater_CantRateEgg::
# 202 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
# 203 "data/scripts/pkmn_center_jack.pory"
	release
	end


Common_EventScript_PkmnCenterJack_NameRater_ChangeNickname::
# 208 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
# 209 "data/scripts/pkmn_center_jack.pory"
	call Common_EventScript_NameReceivedPartyMon
# 210 "data/scripts/pkmn_center_jack.pory"
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
# 211 "data/scripts/pkmn_center_jack.pory"
	special BufferMonNickname
# 212 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_PkmnCenterJack_NameRater_ChangeNickname_2
Common_EventScript_PkmnCenterJack_NameRater_ChangeNickname_1:
# 215 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
# 216 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_EventScript_PkmnCenterJack_NameRater_ChangeNickname_2:
# 213 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_NameRater_NewNameDifferent
	goto Common_EventScript_PkmnCenterJack_NameRater_ChangeNickname_1


Common_EventScript_PkmnCenterJack_NameRater_NewNameDifferent::
# 221 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
# 222 "data/scripts/pkmn_center_jack.pory"
	release
	end


Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget::
# 228 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_WhichMonShouldForget, MSGBOX_DEFAULT
# 229 "data/scripts/pkmn_center_jack.pory"
	special ChoosePartyMon
# 230 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 231 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_2
Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_1:
# 234 "data/scripts/pkmn_center_jack.pory"
	special IsSelectedMonEgg
# 235 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_5
Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_4:
# 238 "data/scripts/pkmn_center_jack.pory"
	special GetNumMovesSelectedMonHas
# 239 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, 1
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_8
Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_7:
# 242 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
# 243 "data/scripts/pkmn_center_jack.pory"
	fadescreen FADE_TO_BLACK
# 244 "data/scripts/pkmn_center_jack.pory"
	special MoveDeleterChooseMoveToForget
# 245 "data/scripts/pkmn_center_jack.pory"
	fadescreen FADE_FROM_BLACK
# 246 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8005, MAX_MON_MOVES
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_11
Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_10:
# 249 "data/scripts/pkmn_center_jack.pory"
	special BufferMoveDeleterNicknameAndMove
# 250 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
# 251 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 252 "data/scripts/pkmn_center_jack.pory"
	case YES, Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_15
# 253 "data/scripts/pkmn_center_jack.pory"
	case NO, Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_16
Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_13:
# 255 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end

Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_2:
# 232 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ComeAgain
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_1

Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_5:
# 236 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_EggCantForgetMoves
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_4

Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_8:
# 240 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_MonOnlyKnowsOneMove
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_7

Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_11:
# 247 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_10

Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_15:
# 252 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_TryForgetMove
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_13

Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_16:
# 253 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ComeAgain
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget_13


Common_EventScript_PkmnCenterJack_MoveDeleter_TryForgetMove::
# 260 "data/scripts/pkmn_center_jack.pory"
	special IsLastMonThatKnowsSurf
# 261 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_PkmnCenterJack_MoveDeleter_TryForgetMove_2
Common_EventScript_PkmnCenterJack_MoveDeleter_TryForgetMove_1:
# 264 "data/scripts/pkmn_center_jack.pory"
	special MoveDeleterForgetMove
# 265 "data/scripts/pkmn_center_jack.pory"
	playfanfare MUS_MOVE_DELETED
# 266 "data/scripts/pkmn_center_jack.pory"
	waitfanfare
# 267 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MonHasForgottenMove, MSGBOX_DEFAULT
# 268 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end

Common_EventScript_PkmnCenterJack_MoveDeleter_TryForgetMove_2:
# 262 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_LastMonWithSurf
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_TryForgetMove_1


Common_EventScript_PkmnCenterJack_MoveDeleter_MonOnlyKnowsOneMove::
# 273 "data/scripts/pkmn_center_jack.pory"
	special BufferMoveDeleterNicknameAndMove
# 274 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
# 275 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_MoveDeleter_EggCantForgetMoves::
# 280 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_EggCantForgetMoves, MSGBOX_DEFAULT
# 281 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_MoveDeleter_ComeAgain::
# 286 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_ComeAgain, MSGBOX_DEFAULT
# 287 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_MoveDeleter_LastMonWithSurf::
# 292 "data/scripts/pkmn_center_jack.pory"
	special BufferMoveDeleterNicknameAndMove
# 293 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_PkmnCenterJack_Text_CantForgetSurf, MSGBOX_DEFAULT
# 294 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_EventScript_PkmnCenterJack_MoveReminder_ComeBackAnytime::
# 301 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_ComeBackAnytime, MSGBOX_DEFAULT
# 302 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end


Common_Eventscript_CheckForItems::
# 308 "data/scripts/pkmn_center_jack.pory"
	checkitem ITEM_ITEMFINDER, 1
# 309 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_Eventscript_CheckForItems_2
Common_Eventscript_CheckForItems_1:
	return

Common_Eventscript_CheckForItems_2:
# 310 "data/scripts/pkmn_center_jack.pory"
	additem ITEM_ITEMFINDER
	goto Common_Eventscript_CheckForItems_1


Common_EventScript_PkmnCenterJack_Clear_Move_Tutor_Data::
# 316 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_NORMAL
# 317 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_PARTY_MENU_TUTOR_STATE, MOVE_TUTOR_LEVEL_UP_MOVES
# 318 "data/scripts/pkmn_center_jack.pory"
	clearflag FLAG_IS_MOVE_TUTOR
	return


Common_EventScript_PkmnCenterJack_Move_Learner::
# 323 "data/scripts/pkmn_center_jack.pory"
	call Common_EventScript_PkmnCenterJack_Clear_Move_Tutor_Data
# 324 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PkmnCenterJack_TeachMoves, MSGBOX_DEFAULT
# 325 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_BLUE_NURSE_MOVE_LEARN, 0, 0, 5, TRUE
# 326 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 327 "data/scripts/pkmn_center_jack.pory"
	case 0, Common_EventScript_PkmnCenterJack_Move_Learner_2
# 330 "data/scripts/pkmn_center_jack.pory"
	case 1, Common_EventScript_PkmnCenterJack_Move_Learner_3
# 333 "data/scripts/pkmn_center_jack.pory"
	case 2, Common_EventScript_PkmnCenterJack_Move_Learner_4
# 336 "data/scripts/pkmn_center_jack.pory"
	case 3, Common_EventScript_PkmnCenterJack_Move_Learner_5
# 339 "data/scripts/pkmn_center_jack.pory"
	case 5, Common_EventScript_PkmnCenterJack_Move_Learner_6
Common_EventScript_PkmnCenterJack_Move_Learner_6:
# 341 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_ComeBackAnytime
	return

Common_EventScript_PkmnCenterJack_Move_Learner_2:
# 328 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_MoveDeleter_ChooseMonAndMoveToForget
	return

Common_EventScript_PkmnCenterJack_Move_Learner_3:
# 331 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_EggMoveTutor_Price
	return

Common_EventScript_PkmnCenterJack_Move_Learner_4:
# 334 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price
	return

Common_EventScript_PkmnCenterJack_Move_Learner_5:
# 337 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TmMoveTutor_Price
	return


Common_EventScript_PkmnCenterJack_Lower_Difficulty::
# 347 "data/scripts/pkmn_center_jack.pory"
	compare VAR_DIFFICULTY, DIFFICULTY_EASY
	goto_if_ne Common_EventScript_PkmnCenterJack_Lower_Difficulty_2
# 373 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Lower_Difficulty_Text_3
# 374 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
Common_EventScript_PkmnCenterJack_Lower_Difficulty_1:
# 376 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_EventScript_PkmnCenterJack_Lower_Difficulty_2:
# 348 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Lower_Difficulty_Text_0, MSGBOX_YESNO
# 349 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 350 "data/scripts/pkmn_center_jack.pory"
	case YES, Common_EventScript_PkmnCenterJack_Lower_Difficulty_6
# 365 "data/scripts/pkmn_center_jack.pory"
	case NO, Common_EventScript_PkmnCenterJack_Lower_Difficulty_7
# 366 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_Lower_Difficulty_7
Common_EventScript_PkmnCenterJack_Lower_Difficulty_7:
# 368 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	goto Common_EventScript_PkmnCenterJack_Lower_Difficulty_1

Common_EventScript_PkmnCenterJack_Lower_Difficulty_6:
# 351 "data/scripts/pkmn_center_jack.pory"
	compare VAR_DIFFICULTY, DIFFICULTY_HARD
	goto_if_eq Common_EventScript_PkmnCenterJack_Lower_Difficulty_9
# 357 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_DIFFICULTY, DIFFICULTY_EASY
# 358 "data/scripts/pkmn_center_jack.pory"
	playfanfare MUS_OBTAIN_ITEM
# 359 "data/scripts/pkmn_center_jack.pory"
	message Common_EventScript_PkmnCenterJack_Lower_Difficulty_Text_2
Common_EventScript_PkmnCenterJack_Lower_Difficulty_8:
# 361 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 362 "data/scripts/pkmn_center_jack.pory"
	waitfanfare
# 363 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	goto Common_EventScript_PkmnCenterJack_Lower_Difficulty_1

Common_EventScript_PkmnCenterJack_Lower_Difficulty_9:
# 352 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_DIFFICULTY, DIFFICULTY_NORMAL
# 353 "data/scripts/pkmn_center_jack.pory"
	playfanfare MUS_OBTAIN_ITEM
# 354 "data/scripts/pkmn_center_jack.pory"
	message Common_EventScript_PkmnCenterJack_Lower_Difficulty_Text_1
	goto Common_EventScript_PkmnCenterJack_Lower_Difficulty_8


Common_EventScript_PkmnCenterJack_Change_Costume::
# 381 "data/scripts/pkmn_center_jack.pory"
	lock
# 382 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 383 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_0, MSGBOX_DEFAULT
# 384 "data/scripts/pkmn_center_jack.pory"
	checkplayergender
# 385 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, GENDER_FEMALE
	goto_if_eq Common_EventScript_PkmnCenterJack_Change_Costume_2
# 430 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_COSTUMES_MALE, 0, 0, 6, TRUE
# 431 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 432 "data/scripts/pkmn_center_jack.pory"
	case 0, Common_EventScript_PkmnCenterJack_Change_Costume_15
# 437 "data/scripts/pkmn_center_jack.pory"
	case 1, Common_EventScript_PkmnCenterJack_Change_Costume_16
# 442 "data/scripts/pkmn_center_jack.pory"
	case 2, Common_EventScript_PkmnCenterJack_Change_Costume_17
# 447 "data/scripts/pkmn_center_jack.pory"
	case 3, Common_EventScript_PkmnCenterJack_Change_Costume_18
# 452 "data/scripts/pkmn_center_jack.pory"
	case 4, Common_EventScript_PkmnCenterJack_Change_Costume_19
# 457 "data/scripts/pkmn_center_jack.pory"
	case 5, Common_EventScript_PkmnCenterJack_Change_Costume_20
# 462 "data/scripts/pkmn_center_jack.pory"
	case 6, Common_EventScript_PkmnCenterJack_Change_Costume_21
# 467 "data/scripts/pkmn_center_jack.pory"
	case 7, Common_EventScript_PkmnCenterJack_Change_Costume_22
# 472 "data/scripts/pkmn_center_jack.pory"
	case 8, Common_EventScript_PkmnCenterJack_Change_Costume_23
# 478 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_Change_Costume_24
Common_EventScript_PkmnCenterJack_Change_Costume_24:
# 479 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_2, MSGBOX_DEFAULT
Common_EventScript_PkmnCenterJack_Change_Costume_1:
# 483 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end

Common_EventScript_PkmnCenterJack_Change_Costume_2:
# 386 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_COSTUMES_FEMALE, 0, 0, 6, TRUE
# 387 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 388 "data/scripts/pkmn_center_jack.pory"
	case 0, Common_EventScript_PkmnCenterJack_Change_Costume_6
# 393 "data/scripts/pkmn_center_jack.pory"
	case 1, Common_EventScript_PkmnCenterJack_Change_Costume_7
# 398 "data/scripts/pkmn_center_jack.pory"
	case 2, Common_EventScript_PkmnCenterJack_Change_Costume_8
# 403 "data/scripts/pkmn_center_jack.pory"
	case 3, Common_EventScript_PkmnCenterJack_Change_Costume_9
# 408 "data/scripts/pkmn_center_jack.pory"
	case 4, Common_EventScript_PkmnCenterJack_Change_Costume_10
# 413 "data/scripts/pkmn_center_jack.pory"
	case 5, Common_EventScript_PkmnCenterJack_Change_Costume_11
# 418 "data/scripts/pkmn_center_jack.pory"
	case 6, Common_EventScript_PkmnCenterJack_Change_Costume_12
# 424 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_Change_Costume_13
Common_EventScript_PkmnCenterJack_Change_Costume_13:
# 425 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_2, MSGBOX_DEFAULT
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_6:
# 389 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, RS_COSTUME
# 390 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 391 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_7:
# 394 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, EMERALD_COSTUME
# 395 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 396 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_8:
# 399 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, ORAS_COSTUME
# 400 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 401 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_9:
# 404 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, RBY_COSTUME
# 405 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 406 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_10:
# 409 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, FRLG_COSTUME
# 410 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 411 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_11:
# 414 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, DP_COSTUME
# 415 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 416 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_12:
# 419 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, EXTRA_COSTUME
# 420 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 421 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_15:
# 433 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, RS_COSTUME
# 434 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 435 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_16:
# 438 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, EMERALD_COSTUME
# 439 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 440 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_17:
# 443 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, ORAS_COSTUME
# 444 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 445 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_18:
# 448 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, RBY_COSTUME
# 449 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 450 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_19:
# 453 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, FRLG_COSTUME
# 454 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 455 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_20:
# 458 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, EXTRA_COSTUME
# 459 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 460 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_21:
# 463 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, GSC_COSTUME
# 464 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 465 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_22:
# 468 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, DP_COSTUME
# 469 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 470 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1

Common_EventScript_PkmnCenterJack_Change_Costume_23:
# 473 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_COSTUME_NUMBER, BW_COSTUME
# 474 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Change_Costume_Text_1, MSGBOX_DEFAULT
# 475 "data/scripts/pkmn_center_jack.pory"
	warp MAP_LITTLEROOT_TOWN, 192, 192, 192
	goto Common_EventScript_PkmnCenterJack_Change_Costume_1


Common_EventScript_PkmnCenterJack_WonderTrade::
# 489 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
# 490 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 491 "data/scripts/pkmn_center_jack.pory"
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
# 492 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x8009, VAR_RESULT
# 494 "data/scripts/pkmn_center_jack.pory"
	checkitem ITEM_WONDER_CHARM, 1
# 495 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_2
# 501 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_WonderTrade_Text_1, MSGBOX_YESNO
Common_EventScript_PkmnCenterJack_WonderTrade_1:
# 504 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, NO
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_6
# 509 "data/scripts/pkmn_center_jack.pory"
	checkitem ITEM_WONDER_CHARM, 1
# 510 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_10
Common_EventScript_PkmnCenterJack_WonderTrade_9:
# 514 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_12
# 519 "data/scripts/pkmn_center_jack.pory"
	special ChoosePartyMon
# 520 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 522 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 0xFF
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_16
Common_EventScript_PkmnCenterJack_WonderTrade_15:
# 525 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x800A, VAR_0x8004
# 526 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 527 "data/scripts/pkmn_center_jack.pory"
	specialvar VAR_RESULT, GetTradeSpecies
# 528 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x800B, VAR_RESULT
# 529 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, VAR_0x8009
# 530 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 531 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_0x8005, VAR_0x800A
# 532 "data/scripts/pkmn_center_jack.pory"
	special CreateInGameWonderTradePokemon
# 533 "data/scripts/pkmn_center_jack.pory"
	special DoInGameTradeScene
# 534 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 535 "data/scripts/pkmn_center_jack.pory"
	special DestroyFollower
# 536 "data/scripts/pkmn_center_jack.pory"
	bufferspeciesname 0, VAR_0x8009
# 537 "data/scripts/pkmn_center_jack.pory"
	playse SE_SHOP
# 539 "data/scripts/pkmn_center_jack.pory"
	checkitem ITEM_WONDER_CHARM, 1
# 540 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_PkmnCenterJack_WonderTrade_19
Common_EventScript_PkmnCenterJack_WonderTrade_18:
# 544 "data/scripts/pkmn_center_jack.pory"
	clearflag FLAG_FOLLOWER_IS_ENABLED
# 545 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_WonderTrade_Text_3, MSGBOX_DEFAULT
Common_EventScript_PkmnCenterJack_WonderTrade_5:
# 548 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_EventScript_PkmnCenterJack_WonderTrade_2:
# 496 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 497 "data/scripts/pkmn_center_jack.pory"
	showmoneybox 0, 0, 0
# 498 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_WonderTrade_Text_0, MSGBOX_YESNO
	goto Common_EventScript_PkmnCenterJack_WonderTrade_1

Common_EventScript_PkmnCenterJack_WonderTrade_6:
# 505 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_WonderTrade_Cancel
	goto Common_EventScript_PkmnCenterJack_WonderTrade_5

Common_EventScript_PkmnCenterJack_WonderTrade_10:
# 511 "data/scripts/pkmn_center_jack.pory"
	checkmoney WONDER_TRADE_PRICE, 0
	goto Common_EventScript_PkmnCenterJack_WonderTrade_9

Common_EventScript_PkmnCenterJack_WonderTrade_12:
# 515 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_WonderTrade_Text_2, MSGBOX_DEFAULT
# 516 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, 0
	goto Common_EventScript_PkmnCenterJack_WonderTrade_5

Common_EventScript_PkmnCenterJack_WonderTrade_16:
# 523 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_WonderTrade_Cancel
	goto Common_EventScript_PkmnCenterJack_WonderTrade_15

Common_EventScript_PkmnCenterJack_WonderTrade_19:
# 541 "data/scripts/pkmn_center_jack.pory"
	removemoney WONDER_TRADE_PRICE, 0
	goto Common_EventScript_PkmnCenterJack_WonderTrade_18


Common_EventScript_PkmnCenterJack_WonderTrade_Cancel::
# 553 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_WonderTrade_Cancel_Text_0, MSGBOX_DEFAULT
# 554 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	return


Common_EventScript_PkmnCenterJack_EggMoveTutor_Price::
# 560 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_PARTY_MENU_TUTOR_STATE, MOVE_TUTOR_EGG_MOVES
# 561 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_IS_MOVE_TUTOR
# 562 "data/scripts/pkmn_center_jack.pory"
	compare VAR_NUM_BADGES, 6
	goto_if_ge Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_1
# 587 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_2, MSGBOX_DEFAULT
# 588 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_1:
# 563 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 564 "data/scripts/pkmn_center_jack.pory"
	showmoneybox 0, 0, 0
# 565 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_0, MSGBOX_YESNO
# 566 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_4
# 582 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 583 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_4:
# 568 "data/scripts/pkmn_center_jack.pory"
	checkmoney 4, 0
# 569 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_7
# 575 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 576 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_1, MSGBOX_DEFAULT
# 577 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_7:
# 570 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 571 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon::
# 593 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_0, MSGBOX_DEFAULT
# 594 "data/scripts/pkmn_center_jack.pory"
	special ChooseMonForMoveRelearner
# 595 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 596 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_1
# 600 "data/scripts/pkmn_center_jack.pory"
	special IsSelectedMonEgg
# 601 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_4
# 606 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8005, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_7
# 611 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_3, MSGBOX_DEFAULT
# 612 "data/scripts/pkmn_center_jack.pory"
	special TeachMoveRelearnerMove
# 613 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 614 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_10
# 618 "data/scripts/pkmn_center_jack.pory"
	playse SE_SHOP
# 619 "data/scripts/pkmn_center_jack.pory"
	removemoney 4, 0
# 620 "data/scripts/pkmn_center_jack.pory"
	call Common_EventScript_PkmnCenterJack_Clear_Move_Tutor_Data
# 621 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_4, MSGBOX_DEFAULT
# 622 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_1:
# 597 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_4:
# 602 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_1, MSGBOX_DEFAULT
# 603 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_7:
# 607 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_2, MSGBOX_DEFAULT
	return

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_10:
# 615 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price::
# 633 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_PARTY_MENU_TUTOR_STATE, MOVE_TUTOR_MOVES
# 634 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_IS_MOVE_TUTOR
# 635 "data/scripts/pkmn_center_jack.pory"
	compare VAR_NUM_BADGES, 9
	goto_if_ge Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_1
# 660 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_Text_1, MSGBOX_DEFAULT
# 661 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_1:
# 636 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 637 "data/scripts/pkmn_center_jack.pory"
	showmoneybox 0, 0, 0
# 638 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_Text_0, MSGBOX_YESNO
# 639 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_4
# 655 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 656 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_4:
# 641 "data/scripts/pkmn_center_jack.pory"
	checkmoney 6, 0
# 642 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_7
# 648 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 649 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_1, MSGBOX_DEFAULT
# 650 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_7:
# 643 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 644 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon::
# 666 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_0, MSGBOX_DEFAULT
# 667 "data/scripts/pkmn_center_jack.pory"
	special ChooseMonForMoveRelearner
# 668 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 669 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_1
# 673 "data/scripts/pkmn_center_jack.pory"
	special IsSelectedMonEgg
# 674 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_4
# 679 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8005, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_7
# 684 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_3, MSGBOX_DEFAULT
# 685 "data/scripts/pkmn_center_jack.pory"
	special TeachMoveRelearnerMove
# 686 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 687 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_10
# 691 "data/scripts/pkmn_center_jack.pory"
	playse SE_SHOP
# 692 "data/scripts/pkmn_center_jack.pory"
	removemoney 6, 0
# 693 "data/scripts/pkmn_center_jack.pory"
	call Common_EventScript_PkmnCenterJack_Clear_Move_Tutor_Data
# 694 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_4, MSGBOX_DEFAULT
# 695 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end

Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_1:
# 670 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_4:
# 675 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_1, MSGBOX_DEFAULT
# 676 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_7:
# 680 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_2, MSGBOX_DEFAULT
	return

Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon_10:
# 688 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_TmMoveTutor_Price::
# 706 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_PARTY_MENU_TUTOR_STATE, MOVE_TUTOR_TM_MOVES
# 707 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_IS_MOVE_TUTOR
# 708 "data/scripts/pkmn_center_jack.pory"
	compare VAR_NUM_BADGES, 12
	goto_if_ge Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_1
# 733 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_Text_1, MSGBOX_DEFAULT
# 734 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_1:
# 709 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 710 "data/scripts/pkmn_center_jack.pory"
	showmoneybox 0, 0, 0
# 711 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_Text_0, MSGBOX_YESNO
# 712 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_4
# 728 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 729 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_4:
# 714 "data/scripts/pkmn_center_jack.pory"
	checkmoney 8, 0
# 715 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_7
# 721 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 722 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_1, MSGBOX_DEFAULT
# 723 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_7:
# 716 "data/scripts/pkmn_center_jack.pory"
	hidemoneybox
# 717 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon::
# 739 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_0, MSGBOX_DEFAULT
# 740 "data/scripts/pkmn_center_jack.pory"
	special ChooseMonForMoveRelearner
# 741 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 742 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 255
	goto_if_eq Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_1
# 746 "data/scripts/pkmn_center_jack.pory"
	special IsSelectedMonEgg
# 747 "data/scripts/pkmn_center_jack.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_4
# 752 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8005, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_7
# 757 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_3, MSGBOX_DEFAULT
# 758 "data/scripts/pkmn_center_jack.pory"
	special TeachMoveRelearnerMove
# 759 "data/scripts/pkmn_center_jack.pory"
	waitstate
# 760 "data/scripts/pkmn_center_jack.pory"
	compare VAR_0x8004, 0
	goto_if_eq Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_10
# 764 "data/scripts/pkmn_center_jack.pory"
	playse SE_SHOP
# 765 "data/scripts/pkmn_center_jack.pory"
	removemoney 8, 0
# 766 "data/scripts/pkmn_center_jack.pory"
	call Common_EventScript_PkmnCenterJack_Clear_Move_Tutor_Data
# 767 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_4, MSGBOX_DEFAULT
# 768 "data/scripts/pkmn_center_jack.pory"
	releaseall
	end

Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_1:
# 743 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_4:
# 748 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_1, MSGBOX_DEFAULT
# 749 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_Move_Learner
	return

Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_7:
# 753 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_2, MSGBOX_DEFAULT
	return

Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon_10:
# 761 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_TM_TutorMoveTutor_ChooseMon
	return


Common_EventScript_PkmnCenterJack_ChangeSeason::
# 777 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_0, MSGBOX_DEFAULT
# 778 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 779 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_SEASONS, 0, 0, 5, TRUE
# 780 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 781 "data/scripts/pkmn_center_jack.pory"
	case SEASON_SPRING, Common_EventScript_PkmnCenterJack_ChangeSeason_3
# 786 "data/scripts/pkmn_center_jack.pory"
	case SEASON_SUMMER, Common_EventScript_PkmnCenterJack_ChangeSeason_4
# 791 "data/scripts/pkmn_center_jack.pory"
	case SEASON_AUTUMN, Common_EventScript_PkmnCenterJack_ChangeSeason_5
# 796 "data/scripts/pkmn_center_jack.pory"
	case SEASON_WINTER, Common_EventScript_PkmnCenterJack_ChangeSeason_6
# 804 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_ChangeSeason_8
# 802 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_5
Common_EventScript_PkmnCenterJack_ChangeSeason_1:
# 807 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	return

Common_EventScript_PkmnCenterJack_ChangeSeason_3:
# 782 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_CURRENT_SEASON, SEASON_SPRING
# 783 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_SYS_DISABLE_AUTOMATIC_SEASON
# 784 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_1
	goto Common_EventScript_PkmnCenterJack_ChangeSeason_1

Common_EventScript_PkmnCenterJack_ChangeSeason_4:
# 787 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_CURRENT_SEASON, SEASON_SUMMER
# 788 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_SYS_DISABLE_AUTOMATIC_SEASON
# 789 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_2
	goto Common_EventScript_PkmnCenterJack_ChangeSeason_1

Common_EventScript_PkmnCenterJack_ChangeSeason_5:
# 792 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_CURRENT_SEASON, SEASON_AUTUMN
# 793 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_SYS_DISABLE_AUTOMATIC_SEASON
# 794 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_3
	goto Common_EventScript_PkmnCenterJack_ChangeSeason_1

Common_EventScript_PkmnCenterJack_ChangeSeason_6:
# 797 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_CURRENT_SEASON, SEASON_WINTER
# 798 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_SYS_DISABLE_AUTOMATIC_SEASON
# 799 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeSeason_Text_4
	goto Common_EventScript_PkmnCenterJack_ChangeSeason_1

Common_EventScript_PkmnCenterJack_ChangeSeason_8:
	goto Common_EventScript_PkmnCenterJack_ChangeSeason_1


Common_EventScript_PkmnCenterJack_ChangeYear::
# 811 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeYear_Text_0, MSGBOX_DEFAULT
# 812 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 813 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_YEAR, 0, 0, 5, TRUE
# 814 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 819 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_ChangeYear_4
# 816 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 817 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_ChangeMonth
Common_EventScript_PkmnCenterJack_ChangeYear_1:
# 825 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	return

Common_EventScript_PkmnCenterJack_ChangeYear_4:
# 820 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 0
# 821 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 1
# 822 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 2
	goto Common_EventScript_PkmnCenterJack_ChangeYear_1


Common_EventScript_PkmnCenterJack_ChangeMonth::
# 829 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeMonth_Text_0, MSGBOX_DEFAULT
# 830 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 831 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_MONTH, 0, 0, 5, TRUE
# 832 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 837 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_ChangeMonth_4
# 834 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 835 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack_ChangeDay
Common_EventScript_PkmnCenterJack_ChangeMonth_1:
# 843 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	return

Common_EventScript_PkmnCenterJack_ChangeMonth_4:
# 838 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 0
# 839 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 1
# 840 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 2
	goto Common_EventScript_PkmnCenterJack_ChangeMonth_1


Common_EventScript_PkmnCenterJack_ChangeDay::
# 847 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeDay_Text_0, MSGBOX_DEFAULT
# 848 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 849 "data/scripts/pkmn_center_jack.pory"
	scrollingmultichoice SCROLLING_DAY, 0, 0, 5, TRUE
# 850 "data/scripts/pkmn_center_jack.pory"
	switch VAR_RESULT
# 858 "data/scripts/pkmn_center_jack.pory"
	case MULTI_B_PRESSED, Common_EventScript_PkmnCenterJack_ChangeDay_4
# 852 "data/scripts/pkmn_center_jack.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 853 "data/scripts/pkmn_center_jack.pory"
	setflag FLAG_SYS_RESET_DATE
# 854 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_OVERWORLD_SPECIALS, SPECIAL_SET_DATE
# 855 "data/scripts/pkmn_center_jack.pory"
	drawbox
# 856 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_EventScript_PkmnCenterJack_ChangeDay_Text_1
Common_EventScript_PkmnCenterJack_ChangeDay_1:
# 865 "data/scripts/pkmn_center_jack.pory"
	goto Common_EventScript_PkmnCenterJack
	return

Common_EventScript_PkmnCenterJack_ChangeDay_4:
# 859 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 0
# 860 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 1
# 861 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_TEMP_1, 2
	goto Common_EventScript_PkmnCenterJack_ChangeDay_1


	.align 2
# 871 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_XY:
# 872 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 873 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ABOMASITE
# 874 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ABSOLITE
# 875 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_AERODACTYLITE
# 876 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ALAKAZITE
# 877 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_AMPHAROSITE
# 878 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_AUDINITE
# 879 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BANETTITE
# 880 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BLASTOISINITE
# 881 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CHARIZARDITE_X
# 882 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CHARIZARDITE_Y
# 883 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GALLADITE
# 884 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GARCHOMPITE
# 885 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GARDEVOIRITE
# 886 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GENGARITE
# 887 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GYARADOSITE
# 888 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_HERACRONITE
# 889 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_HOUNDOOMINITE
# 890 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_KANGASKHANITE
# 891 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LUCARIONITE
# 892 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MANECTITE
# 893 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MAWILITE
# 894 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MEDICHAMITE
# 895 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_PINSIRITE
# 896 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SCIZORITE
# 897 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TYRANITARITE
# 898 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_VENUSAURITE
	.2byte ITEM_NONE

	.align 2
# 901 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_ORAS:
# 902 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 903 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BLAZIKENITE
# 904 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BEEDRILLITE
# 905 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_PIDGEOTITE
# 906 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SLOWBRONITE
# 907 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_STEELIXITE
# 908 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SWAMPERTITE
# 909 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SCEPTILITE
# 910 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SABLENITE
# 911 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SHARPEDONITE
# 912 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CAMERUPTITE
# 913 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ALTARIANITE
# 914 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GLALITITE
# 915 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SALAMENCITE
# 916 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_METAGROSSITE
# 917 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LOPUNNITE
	.2byte ITEM_NONE

	.align 2
# 920 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_G:
# 921 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 922 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_VENAUSURITE_G
# 923 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BLASTOISTE_G
# 924 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GRIMMSNARLITE
# 925 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_RILABOOMITE
# 926 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CINDERACITE
# 927 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_INTELEONITE
# 928 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TOXTRICITITE
# 929 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ALCREMITE
# 930 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_APPLETITE
# 931 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BUTTERFRITE
# 932 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CENTISITE
# 933 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_COALOSSITE
# 934 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CORVIKNITE
# 935 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DREDNAWITE
# 936 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FLAPPLITE
# 937 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GARBODORITE
# 938 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_HATTERENITE
# 939 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_KINGLERITE
# 940 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LAPRITE
# 941 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MACHAMPITE
# 942 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ORBEETLITE
# 943 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SANDACONDITE
# 944 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SNORLAXITE
	.2byte ITEM_NONE

	.align 2
# 947 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_ER:
# 948 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 949 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SLOWKINGITE
# 950 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CROBATITE
# 951 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DEWGONGITE
# 952 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TYPHLOSIONITE
# 953 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LANTURNITE
# 954 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_QUAGSIRITE
# 955 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BRELOOMITE
# 956 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SHEDINJITE
# 957 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FLYGONITE
# 958 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MILOTICITE
# 959 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SERPERIORITE
# 960 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SAMUROTTITE
# 961 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_RIBOMBITE
# 962 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CLODSIRITE
# 963 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SANDSLASHITE
# 964 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TOUCANNONITE
# 965 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_VANILLUXITE
# 966 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TINKATITE
# 967 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SHUCKLENITE
# 968 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_KROOKODILENITE
# 969 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TSEERENITE
# 970 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LUXRAYNITE
# 971 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CLEFABLITE_R
# 973 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ARBOKITE
	.2byte ITEM_NONE

	.align 2
# 976 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_ZA_DLC:
# 977 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 978 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CHIMECHITE
# 979 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_ABSOLITE_Z
# 980 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_STARAPTORITE
# 981 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GARCHOMPITE_Z
# 982 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LUCARIONITE_Z
# 983 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MEOWSTITE
# 984 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GOLURKITE
# 985 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CRABOMINABLITE
# 986 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GOLISPODITE
# 987 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MAGEARNITE
# 988 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SCOVILLAINITE
# 989 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GLIMMORITE
# 990 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_TATSIGIRITE
# 991 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BAXCALIBURITE
# 992 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_RAICHUNITE_X
# 993 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_RAICHUNITE_Y
	.2byte ITEM_NONE

	.align 2
# 996 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_Legendaries:
# 997 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 998 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_RED_ORB
# 999 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BLUE_ORB
# 1001 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DARKRAITE
# 1005 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MELMETALITE
# 1006 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MEWTWONITE_X
# 1007 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MEWTWONITE_Y
# 1009 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FLOETTITE
# 1010 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LATIASITE
# 1011 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_LATIOSITE
# 1012 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DIANCITE
	.2byte ITEM_NONE

	.align 2
# 1015 "data/scripts/pkmn_center_jack.pory"
Mart_Guru_Stones_ZA:
# 1016 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BOOSTER_STONE
# 1017 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CLEFABLITE
# 1018 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_VICTRIBELITE
# 1019 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_STARMINITE
# 1020 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DRAGONINITE
# 1021 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MEGANIUMITE
# 1022 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FERALIGITE
# 1023 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SKARMORITE
# 1024 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FROSLASSITE
# 1025 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_EMBOARITE
# 1026 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_EXCADRITE
# 1027 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SCOLIPITE
# 1028 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_SCRAFTINITE
# 1029 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_EELEKTROSSITE
# 1030 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CHANDELURITE
# 1031 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DELPHOXITE
# 1032 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_CHESNAUGHTITE
# 1033 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_GRENINJITE
# 1034 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_PYROARITE
# 1035 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_MALAMARITE
# 1036 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_BARBARACITE
# 1037 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DRAGALGITE
# 1038 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_HAWLUCHANITE
# 1039 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_DRAMPANITE
# 1040 "data/scripts/pkmn_center_jack.pory"
	.2byte ITEM_FALINKSITE
	.2byte ITEM_NONE

Common_Mega_Stone_Guru_No_Braclet::
# 1044 "data/scripts/pkmn_center_jack.pory"
	msgbox Common_Mega_Stone_Guru_No_Braclet_Text_0, MSGBOX_NPC
# 1045 "data/scripts/pkmn_center_jack.pory"
	release
	end


Common_Mega_Stone_Guru_XY::
# 1050 "data/scripts/pkmn_center_jack.pory"
	lock
# 1051 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1052 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_XY_2
Common_Mega_Stone_Guru_XY_1:
# 1055 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1056 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1057 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_XY_Text_0
# 1058 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1059 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_XY
# 1060 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1061 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_XY_2:
# 1053 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_XY_1


Common_Mega_Stone_Guru_ORAS::
# 1066 "data/scripts/pkmn_center_jack.pory"
	lock
# 1067 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1068 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_ORAS_2
Common_Mega_Stone_Guru_ORAS_1:
# 1071 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1072 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1073 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_ORAS_Text_0
# 1074 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1075 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_ORAS
# 1076 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1077 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_ORAS_2:
# 1069 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_ORAS_1


Common_Mega_Stone_Guru_SWSH::
# 1082 "data/scripts/pkmn_center_jack.pory"
	lock
# 1083 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1084 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_SWSH_2
Common_Mega_Stone_Guru_SWSH_1:
# 1087 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1088 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1089 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_SWSH_Text_0
# 1090 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1091 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_G
# 1092 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1093 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_SWSH_2:
# 1085 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_SWSH_1


Common_Mega_Stone_Guru_ZA::
# 1098 "data/scripts/pkmn_center_jack.pory"
	lock
# 1099 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1100 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_ZA_2
Common_Mega_Stone_Guru_ZA_1:
# 1103 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1104 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1105 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_ZA_Text_0
# 1106 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1107 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_ZA
# 1108 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1109 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_ZA_2:
# 1101 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_ZA_1


Common_Mega_Stone_Guru_ZA_DLC::
# 1114 "data/scripts/pkmn_center_jack.pory"
	lock
# 1115 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1116 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_ZA_DLC_2
Common_Mega_Stone_Guru_ZA_DLC_1:
# 1119 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1120 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1121 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_ZA_DLC_Text_0
# 1122 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1123 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_ZA_DLC
# 1124 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1125 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_ZA_DLC_2:
# 1117 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_ZA_DLC_1


Common_Mega_Stone_Guru_ER::
# 1130 "data/scripts/pkmn_center_jack.pory"
	lock
# 1131 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1132 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_ER_2
Common_Mega_Stone_Guru_ER_1:
# 1135 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1136 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1137 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_ER_Text_0
# 1138 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1139 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_ER
# 1140 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1141 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_ER_2:
# 1133 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_ER_1


Common_Mega_Stone_Guru_Legendary::
# 1146 "data/scripts/pkmn_center_jack.pory"
	lock
# 1147 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1148 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, Common_Mega_Stone_Guru_Legendary_2
Common_Mega_Stone_Guru_Legendary_1:
# 1151 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1152 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1153 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_Legendary_Text_0
# 1154 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1155 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_Legendaries
# 1156 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1157 "data/scripts/pkmn_center_jack.pory"
	release
	end

Common_Mega_Stone_Guru_Legendary_2:
# 1149 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto Common_Mega_Stone_Guru_Legendary_1


OldaleTown_House1_EventScript_BattleMart_Mega::
# 1162 "data/scripts/pkmn_center_jack.pory"
	lock
# 1163 "data/scripts/pkmn_center_jack.pory"
	faceplayer
# 1164 "data/scripts/pkmn_center_jack.pory"
	goto_if_unset FLAG_GOT_BADGE_11, OldaleTown_House1_EventScript_BattleMart_Mega_2
OldaleTown_House1_EventScript_BattleMart_Mega_1:
# 1167 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_TYPE, MART_TYPE_NORMAL
# 1168 "data/scripts/pkmn_center_jack.pory"
	setvar VAR_SHOP_MONEY_TYPE, MART_MONEY_TYPE_BATTLE_POINTS
# 1169 "data/scripts/pkmn_center_jack.pory"
	message Common_Mega_Stone_Guru_XY_Text_0
# 1170 "data/scripts/pkmn_center_jack.pory"
	waitmessage
# 1171 "data/scripts/pkmn_center_jack.pory"
	pokemart Mart_Guru_Stones_XY
# 1172 "data/scripts/pkmn_center_jack.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 1173 "data/scripts/pkmn_center_jack.pory"
	release
	end

OldaleTown_House1_EventScript_BattleMart_Mega_2:
# 1165 "data/scripts/pkmn_center_jack.pory"
	goto Common_Mega_Stone_Guru_No_Braclet
	goto OldaleTown_House1_EventScript_BattleMart_Mega_1


Common_EventScript_PkmnCenterJack_Text_0:
# 24 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry you can't learn or forget moves\n"
	.string "on this mode!$"

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_0:
# 62 "data/scripts/pkmn_center_jack.pory"
	.string "Do you want to {COLOR GREEN}enable{COLOR DARK_GREY} the {COLOR BLUE}Double Battle\n"
	.string "Mode{COLOR DARK_GREY}?$"

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_1:
# 67 "data/scripts/pkmn_center_jack.pory"
	.string "Do you want to {COLOR RED}disable{COLOR DARK_GREY} the {COLOR BLUE}Double\n"
	.string "Battle Mode{COLOR DARK_GREY}?$"

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_2:
# 76 "data/scripts/pkmn_center_jack.pory"
	.string "The {COLOR BLUE}Double Battle Mode{COLOR DARK_GREY} was {COLOR GREEN}enabled{COLOR DARK_GREY}!$"

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_3:
# 82 "data/scripts/pkmn_center_jack.pory"
	.string "The {COLOR BLUE}Double Battle Mode{COLOR DARK_GREY} was {COLOR RED}disabled{COLOR DARK_GREY}!$"

Common_EventScript_PkmnCenterJack_Double_Battle_Mode_Text_4:
# 88 "data/scripts/pkmn_center_jack.pory"
	.string "This will make every battle a Double\n"
	.string "Battle as long as you have 2 Pokémon\l"
	.string "that can battle.$"

Common_EventScript_PkmnCenterJack_Lower_Difficulty_Text_0:
# 348 "data/scripts/pkmn_center_jack.pory"
	.string "Do you want to lower the difficulty?$"

Common_EventScript_PkmnCenterJack_Lower_Difficulty_Text_1:
# 354 "data/scripts/pkmn_center_jack.pory"
	.string "The difficulty became Normal.$"

Common_EventScript_PkmnCenterJack_Lower_Difficulty_Text_2:
# 359 "data/scripts/pkmn_center_jack.pory"
	.string "The difficulty became Easy.$"

Common_EventScript_PkmnCenterJack_Lower_Difficulty_Text_3:
# 373 "data/scripts/pkmn_center_jack.pory"
	.string "You are already in the lowest\n"
	.string "difficulty!$"

Common_EventScript_PkmnCenterJack_Change_Costume_Text_0:
# 383 "data/scripts/pkmn_center_jack.pory"
	.string "What outfit do you want to use today?$"

Common_EventScript_PkmnCenterJack_Change_Costume_Text_1:
# 390 "data/scripts/pkmn_center_jack.pory"
	.string "Come this way so you can change your\n"
	.string "outfit$"

Common_EventScript_PkmnCenterJack_Change_Costume_Text_2:
# 425 "data/scripts/pkmn_center_jack.pory"
	.string "Come back anytime you want to change\n"
	.string "outfits!$"

Common_EventScript_PkmnCenterJack_WonderTrade_Text_0:
# 498 "data/scripts/pkmn_center_jack.pory"
	.string "Do you want to try Wonder Trading, its\n"
	.string "only 5BP per try?$"

Common_EventScript_PkmnCenterJack_WonderTrade_Text_1:
# 501 "data/scripts/pkmn_center_jack.pory"
	.string "Do you want to try Wonder Trading?, its\n"
	.string "free for you$"

Common_EventScript_PkmnCenterJack_WonderTrade_Text_2:
# 515 "data/scripts/pkmn_center_jack.pory"
	.string "But it seems you can't afford wonder\n"
	.string "trading right now.\p"
	.string "Please come back when you have atleast\n"
	.string "5BP.$"

Common_EventScript_PkmnCenterJack_WonderTrade_Text_3:
# 545 "data/scripts/pkmn_center_jack.pory"
	.string "Please take care of your new Pokémon.$"

Common_EventScript_PkmnCenterJack_WonderTrade_Cancel_Text_0:
# 553 "data/scripts/pkmn_center_jack.pory"
	.string "All right. Let me know if you want to\n"
	.string "give it a try.$"

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_0:
# 565 "data/scripts/pkmn_center_jack.pory"
	.string "Learning an Egg move will cost you 4\n"
	.string "Battle Points, do you want to continue?$"

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_1:
# 576 "data/scripts/pkmn_center_jack.pory"
	.string "It seems like you don't have enough\n"
	.string "Battle Points!$"

Common_EventScript_PkmnCenterJack_EggMoveTutor_Price_Text_2:
# 587 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry, you need 6 badges to use this\n"
	.string "service!$"

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_0:
# 593 "data/scripts/pkmn_center_jack.pory"
	.string "Which Pokémon should I teach a move?$"

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_1:
# 602 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry, I can't teach moves to an Egg!$"

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_2:
# 607 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry, this Pokémon can't learn any\n"
	.string "Tutor Move!$"

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_3:
# 611 "data/scripts/pkmn_center_jack.pory"
	.string "Which move should I teach it?$"

Common_EventScript_PkmnCenterJack_Egg_TutorMoveTutor_ChooseMon_Text_4:
# 621 "data/scripts/pkmn_center_jack.pory"
	.string "Your Pokémon was able to learn the move\n"
	.string "successfuly, please continue to use\l"
	.string "our services!$"

Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_Text_0:
# 638 "data/scripts/pkmn_center_jack.pory"
	.string "Learning a Tutor move will cost you 6\n"
	.string "Battle Points, do you want to continue?$"

Common_EventScript_PkmnCenterJack_TutorMoveTutor_Price_Text_1:
# 660 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry, you need 9 badges to use this\n"
	.string "service!$"

Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_Text_0:
# 711 "data/scripts/pkmn_center_jack.pory"
	.string "Learning a TM move will cost you 8\n"
	.string "Battle Points, do you want to continue?$"

Common_EventScript_PkmnCenterJack_TmMoveTutor_Price_Text_1:
# 733 "data/scripts/pkmn_center_jack.pory"
	.string "Sorry, you need 12 badges to use this\n"
	.string "service!$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_0:
# 777 "data/scripts/pkmn_center_jack.pory"
	.string "Please chose the season you like the\n"
	.string "best.$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_1:
# 784 "data/scripts/pkmn_center_jack.pory"
	.string "You will play in Spring!$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_2:
# 789 "data/scripts/pkmn_center_jack.pory"
	.string "You will play in Summer!$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_3:
# 794 "data/scripts/pkmn_center_jack.pory"
	.string "You will play in Autumn!$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_4:
# 799 "data/scripts/pkmn_center_jack.pory"
	.string "You will play in Winter!$"

Common_EventScript_PkmnCenterJack_ChangeSeason_Text_5:
# 802 "data/scripts/pkmn_center_jack.pory"
	.string "The season will update according to the\n"
	.string "real time!$"

Common_EventScript_PkmnCenterJack_ChangeYear_Text_0:
# 811 "data/scripts/pkmn_center_jack.pory"
	.string "Please tell me the current year$"

Common_EventScript_PkmnCenterJack_ChangeMonth_Text_0:
# 829 "data/scripts/pkmn_center_jack.pory"
	.string "Please tell me the current month$"

Common_EventScript_PkmnCenterJack_ChangeDay_Text_0:
# 847 "data/scripts/pkmn_center_jack.pory"
	.string "Please tell me the current day$"

Common_EventScript_PkmnCenterJack_ChangeDay_Text_1:
# 856 "data/scripts/pkmn_center_jack.pory"
	.string "You Changed the Date!$"

Common_Mega_Stone_Guru_No_Braclet_Text_0:
# 1044 "data/scripts/pkmn_center_jack.pory"
	.string "I'm an stone collector, I have a big\n"
	.string "collection but I don't know what to do\l"
	.string "with it right now, maybe I could sell\l"
	.string "them in a time of need.$"

Common_Mega_Stone_Guru_XY_Text_0:
# 1057 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell rare stones from Kalos!,\n"
	.string "How may I serve you?$"

Common_Mega_Stone_Guru_ORAS_Text_0:
# 1073 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell rare stones!, How may I\n"
	.string "serve you?$"

Common_Mega_Stone_Guru_SWSH_Text_0:
# 1089 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell big stones from Galar!, How\n"
	.string "may I serve you?$"

Common_Mega_Stone_Guru_ZA_Text_0:
# 1105 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell shiny new stones from\n"
	.string "Kalos!, How may I serve you?$"

Common_Mega_Stone_Guru_ZA_DLC_Text_0:
# 1121 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell weird stones from Kalos!,\n"
	.string "How may I serve you?$"

Common_Mega_Stone_Guru_ER_Text_0:
# 1137 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell rare stones from a strange\n"
	.string "place!, How may I serve you?$"

Common_Mega_Stone_Guru_Legendary_Text_0:
# 1153 "data/scripts/pkmn_center_jack.pory"
	.string "Hello, I sell powerful stones!, How may I\n"
	.string "serve you?$"
