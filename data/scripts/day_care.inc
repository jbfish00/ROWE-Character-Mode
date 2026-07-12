# 1 "data/scripts/day_care.pory"

# 2 "data/scripts/day_care.pory"
.set LOCALID_DAYCARE_LADY, 1
# 3 "data/scripts/day_care.pory"

# 4 "data/scripts/day_care.pory"
Route117_EventScript_DaycareMan::
# 5 "data/scripts/day_care.pory"
	lock
# 6 "data/scripts/day_care.pory"
	faceplayer
# 7 "data/scripts/day_care.pory"
	special GetDaycareMonNicknames
# 8 "data/scripts/day_care.pory"
	specialvar VAR_RESULT, GetDaycareState
# 9 "data/scripts/day_care.pory"
	compare VAR_RESULT, DAYCARE_EGG_WAITING
# 10 "data/scripts/day_care.pory"
	goto_if_eq Route117_EventScript_DaycareEggWaiting
# 11 "data/scripts/day_care.pory"
	compare VAR_RESULT, DAYCARE_ONE_MON
# 12 "data/scripts/day_care.pory"
	goto_if_eq Route117_EventScript_CheckOnOneMon
# 13 "data/scripts/day_care.pory"
	compare VAR_RESULT, DAYCARE_TWO_MONS
# 14 "data/scripts/day_care.pory"
	goto_if_eq Route117_EventScript_CheckOnTwoMons
# 15 "data/scripts/day_care.pory"
	msgbox Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
# 16 "data/scripts/day_care.pory"
	release
# 17 "data/scripts/day_care.pory"
	end
# 18 "data/scripts/day_care.pory"

# 19 "data/scripts/day_care.pory"
Route117_EventScript_DaycareEggWaiting::
# 20 "data/scripts/day_care.pory"
	msgbox Route117_Text_DoYouWantEgg, MSGBOX_YESNO
# 21 "data/scripts/day_care.pory"
	compare VAR_RESULT, YES
# 22 "data/scripts/day_care.pory"
	goto_if_eq Route117_EventScript_DaycareAcceptEgg
# 23 "data/scripts/day_care.pory"
	msgbox Route117_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
# 24 "data/scripts/day_care.pory"
	compare VAR_RESULT, YES
# 25 "data/scripts/day_care.pory"
	goto_if_eq Route117_EventScript_DaycareAcceptEgg
# 26 "data/scripts/day_care.pory"
	msgbox Route117_Text_IllKeepIt, MSGBOX_DEFAULT
# 27 "data/scripts/day_care.pory"
	clearflag FLAG_PENDING_DAYCARE_EGG
# 28 "data/scripts/day_care.pory"
	special RejectEggFromDayCare
# 29 "data/scripts/day_care.pory"
	release
# 30 "data/scripts/day_care.pory"
	end
# 31 "data/scripts/day_care.pory"

# 32 "data/scripts/day_care.pory"
Route117_EventScript_DaycareAcceptEgg::
# 33 "data/scripts/day_care.pory"
	specialvar VAR_RESULT, CalculatePlayerPartyCount
# 34 "data/scripts/day_care.pory"
	compare VAR_RESULT, PARTY_SIZE
# 35 "data/scripts/day_care.pory"
	goto_if_ne Route117_EventScript_DaycareReceiveEgg
# 36 "data/scripts/day_care.pory"
	msgbox Route117_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
# 37 "data/scripts/day_care.pory"
	release
# 38 "data/scripts/day_care.pory"
	end
# 39 "data/scripts/day_care.pory"

# 40 "data/scripts/day_care.pory"
Route117_EventScript_DaycareReceiveEgg::
# 41 "data/scripts/day_care.pory"
	message Route117_Text_ReceivedEgg
# 42 "data/scripts/day_care.pory"
	playfanfare MUS_LEVEL_UP
# 43 "data/scripts/day_care.pory"
	waitfanfare
# 44 "data/scripts/day_care.pory"
	waitbuttonpress
# 45 "data/scripts/day_care.pory"
	msgbox Route117_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
# 46 "data/scripts/day_care.pory"
	special GiveEggFromDaycare
# 47 "data/scripts/day_care.pory"
	clearflag FLAG_PENDING_DAYCARE_EGG
# 48 "data/scripts/day_care.pory"
	release
# 49 "data/scripts/day_care.pory"
	end
# 50 "data/scripts/day_care.pory"

# 51 "data/scripts/day_care.pory"
Route117_EventScript_CheckMonReceivedMail::
# 52 "data/scripts/day_care.pory"
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
# 53 "data/scripts/day_care.pory"
	compare VAR_RESULT, 1
# 54 "data/scripts/day_care.pory"
	call_if_eq Route117_EventScript_MonReceivedMail
# 55 "data/scripts/day_care.pory"
	return
# 56 "data/scripts/day_care.pory"

# 57 "data/scripts/day_care.pory"
Route117_EventScript_MonReceivedMail::
# 58 "data/scripts/day_care.pory"
	msgbox Route117_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
# 59 "data/scripts/day_care.pory"
	return
# 60 "data/scripts/day_care.pory"

# 61 "data/scripts/day_care.pory"
Route117_EventScript_CheckOnOneMon::
# 62 "data/scripts/day_care.pory"
	special GetDaycareMonNicknames
# 63 "data/scripts/day_care.pory"
	msgbox Route117_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
# 64 "data/scripts/day_care.pory"
	setvar VAR_0x8004, 0
# 65 "data/scripts/day_care.pory"
	call Route117_EventScript_CheckMonReceivedMail
# 66 "data/scripts/day_care.pory"
	release
# 67 "data/scripts/day_care.pory"
	end
# 68 "data/scripts/day_care.pory"

# 69 "data/scripts/day_care.pory"
Route117_EventScript_CheckOnTwoMons::
# 70 "data/scripts/day_care.pory"
	special GetDaycareMonNicknames
# 71 "data/scripts/day_care.pory"
	msgbox Route117_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
# 72 "data/scripts/day_care.pory"
	special SetDaycareCompatibilityString
# 73 "data/scripts/day_care.pory"
	special ShowFieldMessageStringVar4
# 74 "data/scripts/day_care.pory"
	waitmessage
# 75 "data/scripts/day_care.pory"
	waitbuttonpress
# 76 "data/scripts/day_care.pory"
	setvar VAR_0x8004, 0
# 77 "data/scripts/day_care.pory"
	call Route117_EventScript_CheckMonReceivedMail
# 78 "data/scripts/day_care.pory"
	setvar VAR_0x8004, 1
# 79 "data/scripts/day_care.pory"
	call Route117_EventScript_CheckMonReceivedMail
# 80 "data/scripts/day_care.pory"
	release
# 81 "data/scripts/day_care.pory"
	end
# 82 "data/scripts/day_care.pory"

# 83 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_DaycareWoman::
# 84 "data/scripts/day_care.pory"
	lock
# 85 "data/scripts/day_care.pory"
	faceplayer
# 86 "data/scripts/day_care.pory"
	specialvar VAR_RESULT, GetDaycareState
# 87 "data/scripts/day_care.pory"
	compare VAR_RESULT, DAYCARE_EGG_WAITING
# 88 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_EggWaiting
# 89 "data/scripts/day_care.pory"
	compare VAR_RESULT, DAYCARE_ONE_MON
# 90 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_OneMonInDaycare
# 91 "data/scripts/day_care.pory"
	compare VAR_RESULT, DAYCARE_TWO_MONS
# 92 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_TwoMonsInDaycare
# 93 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
# 94 "data/scripts/day_care.pory"
	compare VAR_RESULT, YES
# 95 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_GiveMonToRaise
# 96 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
# 97 "data/scripts/day_care.pory"
	release
# 98 "data/scripts/day_care.pory"
	end
# 99 "data/scripts/day_care.pory"

# 100 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_GiveMonToRaise::
# 101 "data/scripts/day_care.pory"
	specialvar VAR_RESULT, CountPartyNonEggMons
# 102 "data/scripts/day_care.pory"
	compare VAR_RESULT, 1
# 103 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_OnlyOneMon
# 104 "data/scripts/day_care.pory"
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
# 105 "data/scripts/day_care.pory"
	compare VAR_RESULT, 2
# 106 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons
# 107 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
# 108 "data/scripts/day_care.pory"
	fadescreen FADE_TO_BLACK
# 109 "data/scripts/day_care.pory"
	special ChooseSendDaycareMon
# 110 "data/scripts/day_care.pory"
	waitstate
# 111 "data/scripts/day_care.pory"
	compare VAR_0x8004, 255
# 112 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_ComeAgain
# 113 "data/scripts/day_care.pory"
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
# 114 "data/scripts/day_care.pory"
	compare VAR_RESULT, 0
# 115 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_OnlyOneAliveMon
# 116 "data/scripts/day_care.pory"
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
# 117 "data/scripts/day_care.pory"
	waitse
# 118 "data/scripts/day_care.pory"
	playmoncry VAR_0x8005, 0
# 119 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
# 120 "data/scripts/day_care.pory"
	waitmoncry
# 121 "data/scripts/day_care.pory"
	special StoreSelectedPokemonInDaycare
# 122 "data/scripts/day_care.pory"
	special DestroyFollower
# 123 "data/scripts/day_care.pory"
	incrementgamestat GAME_STAT_USED_DAYCARE
# 124 "data/scripts/day_care.pory"
	specialvar VAR_RESULT, GetDaycareState
# 125 "data/scripts/day_care.pory"
	compare VAR_RESULT, DAYCARE_ONE_MON
# 126 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_CanRaiseOneMore
# 127 "data/scripts/day_care.pory"
	release
# 128 "data/scripts/day_care.pory"
	end
# 129 "data/scripts/day_care.pory"

# 130 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_ComeAgain::
# 131 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
# 132 "data/scripts/day_care.pory"
	release
# 133 "data/scripts/day_care.pory"
	end
# 134 "data/scripts/day_care.pory"

# 135 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_CanRaiseOneMore::
# 136 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
# 137 "data/scripts/day_care.pory"
	compare VAR_RESULT, YES
# 138 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_GiveMonToRaise
# 139 "data/scripts/day_care.pory"
	goto Route117_PokemonDayCare_EventScript_ComeAgain
# 140 "data/scripts/day_care.pory"
	end
# 141 "data/scripts/day_care.pory"

# 142 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_OnlyOneMon::
# 143 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
# 144 "data/scripts/day_care.pory"
	release
# 145 "data/scripts/day_care.pory"
	end
# 146 "data/scripts/day_care.pory"

# 147 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_OnlyOneAliveMon::
# 148 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
# 149 "data/scripts/day_care.pory"
	release
# 150 "data/scripts/day_care.pory"
	end
# 151 "data/scripts/day_care.pory"

# 152 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons::
# 153 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
# 154 "data/scripts/day_care.pory"
	release
# 155 "data/scripts/day_care.pory"
	end
# 156 "data/scripts/day_care.pory"

# 157 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_EggWaiting::
# 158 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
# 159 "data/scripts/day_care.pory"
	release
# 160 "data/scripts/day_care.pory"
	end
# 161 "data/scripts/day_care.pory"

# 162 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
# 163 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
# 164 "data/scripts/day_care.pory"
	return
# 165 "data/scripts/day_care.pory"

# 166 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_DisplayLevelsGained::
# 167 "data/scripts/day_care.pory"
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
# 168 "data/scripts/day_care.pory"
	compare VAR_RESULT, 0
# 169 "data/scripts/day_care.pory"
	call_if_ne Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels
# 170 "data/scripts/day_care.pory"
	return
# 171 "data/scripts/day_care.pory"

# 172 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_OneMonInDaycare::
# 173 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
# 174 "data/scripts/day_care.pory"
	setvar VAR_0x8004, 0
# 175 "data/scripts/day_care.pory"
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
# 176 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
# 177 "data/scripts/day_care.pory"
	compare VAR_RESULT, YES
# 178 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_GiveMonToRaise
# 179 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
# 180 "data/scripts/day_care.pory"
	compare VAR_RESULT, YES
# 181 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_TryRetrieveMon
# 182 "data/scripts/day_care.pory"
	goto Route117_PokemonDayCare_EventScript_ComeAgain
# 183 "data/scripts/day_care.pory"
	end
# 184 "data/scripts/day_care.pory"

# 185 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_TryRetrieveMon::
# 186 "data/scripts/day_care.pory"
	specialvar VAR_RESULT, CalculatePlayerPartyCount
# 187 "data/scripts/day_care.pory"
	compare VAR_RESULT, PARTY_SIZE
# 188 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_NoRoom
# 189 "data/scripts/day_care.pory"
	specialvar VAR_RESULT, GetDaycareState
# 190 "data/scripts/day_care.pory"
	setvar VAR_0x8004, 0
# 191 "data/scripts/day_care.pory"
	compare VAR_RESULT, DAYCARE_ONE_MON
# 192 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_CostPrompt
# 193 "data/scripts/day_care.pory"
	special ShowDaycareLevelMenu
# 194 "data/scripts/day_care.pory"
	waitstate
# 195 "data/scripts/day_care.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 196 "data/scripts/day_care.pory"
	compare VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU
# 197 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_ComeAgain
# 198 "data/scripts/day_care.pory"
	goto Route117_PokemonDayCare_EventScript_CostPrompt
# 199 "data/scripts/day_care.pory"
	end
# 200 "data/scripts/day_care.pory"

# 201 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_CostPrompt::
# 202 "data/scripts/day_care.pory"
	special GetDaycareCost
# 203 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
# 204 "data/scripts/day_care.pory"
	compare VAR_RESULT, YES
# 205 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_CheckEnoughMoney
# 206 "data/scripts/day_care.pory"
	goto Route117_PokemonDayCare_EventScript_ComeAgain
# 207 "data/scripts/day_care.pory"
	end
# 208 "data/scripts/day_care.pory"

# 209 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_CheckEnoughMoney::
# 210 "data/scripts/day_care.pory"
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
# 211 "data/scripts/day_care.pory"
	compare VAR_RESULT, 1
# 212 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_RetrieveMon
# 213 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
# 214 "data/scripts/day_care.pory"
	release
# 215 "data/scripts/day_care.pory"
	end
# 216 "data/scripts/day_care.pory"

# 217 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_RetrieveMon::
# 218 "data/scripts/day_care.pory"
	applymovement LOCALID_DAYCARE_LADY, Route117_PokemonDayCare_Movement_RetrieveDaycareMon
# 219 "data/scripts/day_care.pory"
	waitmovement 0
# 220 "data/scripts/day_care.pory"
	specialvar VAR_RESULT, TakePokemonFromDaycare
# 221 "data/scripts/day_care.pory"
	special SubtractMoneyFromVar0x8005
# 222 "data/scripts/day_care.pory"
	playse SE_SHOP
# 223 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
# 224 "data/scripts/day_care.pory"
	waitse
# 225 "data/scripts/day_care.pory"
	playmoncry VAR_RESULT, 0
# 226 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
# 227 "data/scripts/day_care.pory"
	waitmoncry
# 228 "data/scripts/day_care.pory"
	specialvar VAR_RESULT, GetDaycareState
# 229 "data/scripts/day_care.pory"
	compare VAR_RESULT, DAYCARE_ONE_MON
# 230 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon
# 231 "data/scripts/day_care.pory"
	goto Route117_PokemonDayCare_EventScript_ComeAgain
# 232 "data/scripts/day_care.pory"
	end
# 233 "data/scripts/day_care.pory"

# 234 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon::
# 235 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
# 236 "data/scripts/day_care.pory"
	compare VAR_RESULT, YES
# 237 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_TryRetrieveMon
# 238 "data/scripts/day_care.pory"
	goto Route117_PokemonDayCare_EventScript_ComeAgain
# 239 "data/scripts/day_care.pory"
	end
# 240 "data/scripts/day_care.pory"

# 241 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_NoRoom::
# 242 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
# 243 "data/scripts/day_care.pory"
	release
# 244 "data/scripts/day_care.pory"
	end
# 245 "data/scripts/day_care.pory"

# 246 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Movement_RetrieveDaycareMon:
# 247 "data/scripts/day_care.pory"
	delay_16
# 248 "data/scripts/day_care.pory"
	delay_16
# 249 "data/scripts/day_care.pory"
	face_left
# 250 "data/scripts/day_care.pory"
	delay_16
# 251 "data/scripts/day_care.pory"
	delay_16
# 252 "data/scripts/day_care.pory"
	face_right
# 253 "data/scripts/day_care.pory"
	delay_16
# 254 "data/scripts/day_care.pory"
	delay_16
# 255 "data/scripts/day_care.pory"
	face_up
# 256 "data/scripts/day_care.pory"
	walk_slow_up
# 257 "data/scripts/day_care.pory"
	set_invisible
# 258 "data/scripts/day_care.pory"
	delay_16
# 259 "data/scripts/day_care.pory"
	delay_16
# 260 "data/scripts/day_care.pory"
	delay_16
# 261 "data/scripts/day_care.pory"
	delay_16
# 262 "data/scripts/day_care.pory"
	delay_16
# 263 "data/scripts/day_care.pory"
	face_down
# 264 "data/scripts/day_care.pory"
	set_visible
# 265 "data/scripts/day_care.pory"
	walk_slow_down
# 266 "data/scripts/day_care.pory"
	step_end
# 267 "data/scripts/day_care.pory"

# 268 "data/scripts/day_care.pory"
@ Unused. Possibly a commented script, or a typo end added to the above Movement script
# 269 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_UnusedEnd::
# 270 "data/scripts/day_care.pory"
	end
# 271 "data/scripts/day_care.pory"

# 272 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_TwoMonsInDaycare::
# 273 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
# 274 "data/scripts/day_care.pory"
	setvar VAR_0x8004, 0
# 275 "data/scripts/day_care.pory"
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
# 276 "data/scripts/day_care.pory"
	setvar VAR_0x8004, 1
# 277 "data/scripts/day_care.pory"
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
# 278 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
# 279 "data/scripts/day_care.pory"
	compare VAR_RESULT, YES
# 280 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_TryRetrieveMon
# 281 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
# 282 "data/scripts/day_care.pory"
	release
# 283 "data/scripts/day_care.pory"
	end
# 284 "data/scripts/day_care.pory"

# 285 "data/scripts/day_care.pory"
@ Unused
# 286 "data/scripts/day_care.pory"
Route117_PokemonDayCare_EventScript_UnusedRetrieveMon::
# 287 "data/scripts/day_care.pory"
	special ShowDaycareLevelMenu
# 288 "data/scripts/day_care.pory"
	waitstate
# 289 "data/scripts/day_care.pory"
	compare VAR_RESULT, 2
# 290 "data/scripts/day_care.pory"
	goto_if_eq Route117_PokemonDayCare_EventScript_ComeAgain
# 291 "data/scripts/day_care.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 292 "data/scripts/day_care.pory"
	specialvar VAR_RESULT, TakePokemonFromDaycare
# 293 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
# 294 "data/scripts/day_care.pory"
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
# 295 "data/scripts/day_care.pory"
	release
# 296 "data/scripts/day_care.pory"
	end
# 297 "data/scripts/day_care.pory"

# 298 "data/scripts/day_care.pory"
EventScript_EggHatch::
# 299 "data/scripts/day_care.pory"
	lockall
# 300 "data/scripts/day_care.pory"
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
# 301 "data/scripts/day_care.pory"
	special EggHatch
# 302 "data/scripts/day_care.pory"
	waitstate
# 303 "data/scripts/day_care.pory"
	releaseall
# 304 "data/scripts/day_care.pory"
	end
# 305 "data/scripts/day_care.pory"

# 306 "data/scripts/day_care.pory"
Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon:
# 307 "data/scripts/day_care.pory"
	.string "I'm the Day-Care Man.\p"
# 308 "data/scripts/day_care.pory"
	.string "I help take care of the precious\n"
# 309 "data/scripts/day_care.pory"
	.string "Pokémon of Trainers.\p"
# 310 "data/scripts/day_care.pory"
	.string "If you'd like me to raise your Pokémon,\n"
# 311 "data/scripts/day_care.pory"
	.string "have a word with my wife.$"
# 312 "data/scripts/day_care.pory"

# 313 "data/scripts/day_care.pory"
Route117_Text_DoYouWantEgg:
# 314 "data/scripts/day_care.pory"
	.string "Ah, it's you!\p"
# 315 "data/scripts/day_care.pory"
	.string "We were raising your Pokémon,\n"
# 316 "data/scripts/day_care.pory"
	.string "and my goodness, were we surprised!\p"
# 317 "data/scripts/day_care.pory"
	.string "Your Pokémon had a Baby!\p"
# 318 "data/scripts/day_care.pory"
	.string "We don't know how it got there,\n"
# 319 "data/scripts/day_care.pory"
	.string "but your Pokémon had it.\p"
# 320 "data/scripts/day_care.pory"
	.string "You do want it, yes?$"
# 321 "data/scripts/day_care.pory"

# 322 "data/scripts/day_care.pory"
Route117_Text_YourMonIsDoingFine:
# 323 "data/scripts/day_care.pory"
	.string "Ah, it's you! Good to see you.\n"
# 324 "data/scripts/day_care.pory"
	.string "Your {STR_VAR_1}'s doing fine.$"
# 325 "data/scripts/day_care.pory"

# 326 "data/scripts/day_care.pory"
Route117_Text_IllKeepIt:
# 327 "data/scripts/day_care.pory"
	.string "Well then, I'll keep it.\n"
# 328 "data/scripts/day_care.pory"
	.string "Thanks!$"
# 329 "data/scripts/day_care.pory"

# 330 "data/scripts/day_care.pory"
Route117_Text_YouHaveNoRoomForIt:
# 331 "data/scripts/day_care.pory"
	.string "You have no room for it…\n"
# 332 "data/scripts/day_care.pory"
	.string "Come back when you've made room.$"
# 333 "data/scripts/day_care.pory"

# 334 "data/scripts/day_care.pory"
Route117_Text_ReceivedEgg:
# 335 "data/scripts/day_care.pory"
	.string "{PLAYER} received the Pokémon from\n"
# 336 "data/scripts/day_care.pory"
	.string "the Day-Care Man.$"
# 337 "data/scripts/day_care.pory"

# 338 "data/scripts/day_care.pory"
Route117_Text_TakeGoodCareOfIt:
# 339 "data/scripts/day_care.pory"
	.string "Take good care of it.$"
# 340 "data/scripts/day_care.pory"

# 341 "data/scripts/day_care.pory"
Route117_Text_FriendlyWithOtherTrainersMon:
# 342 "data/scripts/day_care.pory"
	.string "By the way, about your {STR_VAR_1},\n"
# 343 "data/scripts/day_care.pory"
	.string "it seemed to be friendly with\l"
# 344 "data/scripts/day_care.pory"
	.string "{STR_VAR_2}'s {STR_VAR_3}.\p"
# 345 "data/scripts/day_care.pory"
	.string "I may even have seen it receiving\n"
# 346 "data/scripts/day_care.pory"
	.string "a piece of Mail.$"
# 347 "data/scripts/day_care.pory"

# 348 "data/scripts/day_care.pory"
Route117_Text_SeeWifeIfYouWantToPickUpMon:
# 349 "data/scripts/day_care.pory"
	.string "If you want to pick up your Pokémon,\n"
# 350 "data/scripts/day_care.pory"
	.string "have a word with my wife.$"
# 351 "data/scripts/day_care.pory"

# 352 "data/scripts/day_care.pory"
Route117_Text_YourMonsAreDoingFine:
# 353 "data/scripts/day_care.pory"
	.string "Ah, it's you! Your {STR_VAR_1} and\n"
# 354 "data/scripts/day_care.pory"
	.string "{STR_VAR_2} are doing fine.$"
# 355 "data/scripts/day_care.pory"

# 356 "data/scripts/day_care.pory"
Route117_Text_IWillKeepDoYouWantIt:
# 357 "data/scripts/day_care.pory"
	.string "I really will keep it.\n"
# 358 "data/scripts/day_care.pory"
	.string "You do want this, yes?$"
# 359 "data/scripts/day_care.pory"

# 360 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon:
# 361 "data/scripts/day_care.pory"
	.string "I'm the Day-Care Lady.\p"
# 362 "data/scripts/day_care.pory"
	.string "We can raise Pokémon for you.\p"
# 363 "data/scripts/day_care.pory"
	.string "Would you like us to raise one?$"
# 364 "data/scripts/day_care.pory"

# 365 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_WhichMonShouldWeRaise:
# 366 "data/scripts/day_care.pory"
	.string "Which Pokémon should we raise for\n"
# 367 "data/scripts/day_care.pory"
	.string "you?$"
# 368 "data/scripts/day_care.pory"

# 369 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_WellRaiseYourMon:
# 370 "data/scripts/day_care.pory"
	.string "Fine, we'll raise your {STR_VAR_1}\n"
# 371 "data/scripts/day_care.pory"
	.string "for a while.\p"
# 372 "data/scripts/day_care.pory"
	.string "Come back for it later.$"
# 373 "data/scripts/day_care.pory"

# 374 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_WeCanRaiseOneMore:
# 375 "data/scripts/day_care.pory"
	.string "We can raise two of your Pokémon.\n"
# 376 "data/scripts/day_care.pory"
	.string "Would you like us to raise one more?$"
# 377 "data/scripts/day_care.pory"

# 378 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_HusbandWasLookingForYou:
# 379 "data/scripts/day_care.pory"
	.string "My husband was looking for you.$"
# 380 "data/scripts/day_care.pory"

# 381 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_FineThenComeAgain:
# 382 "data/scripts/day_care.pory"
	.string "Oh, fine, then.\n"
# 383 "data/scripts/day_care.pory"
	.string "Come again.$"
# 384 "data/scripts/day_care.pory"

# 385 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_NotEnoughMoney:
# 386 "data/scripts/day_care.pory"
	.string "You don't have enough money…$"
# 387 "data/scripts/day_care.pory"

# 388 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_TakeOtherOneBackToo:
# 389 "data/scripts/day_care.pory"
	.string "Will you take back the other one,\n"
# 390 "data/scripts/day_care.pory"
	.string "too?$"
# 391 "data/scripts/day_care.pory"

# 392 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_ComeAgain:
# 393 "data/scripts/day_care.pory"
	.string "Fine.\n"
# 394 "data/scripts/day_care.pory"
	.string "Come again.$"
# 395 "data/scripts/day_care.pory"

# 396 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_GoodToSeeYou:
# 397 "data/scripts/day_care.pory"
	.string "Ah, it's you! Good to see you.\n"
# 398 "data/scripts/day_care.pory"
	.string "Your Pokémon can only be doing good!$"
# 399 "data/scripts/day_care.pory"

# 400 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_YourMonHasGrownXLevels:
# 401 "data/scripts/day_care.pory"
	.string "By level, your {STR_VAR_1} has\n"
# 402 "data/scripts/day_care.pory"
	.string "grown by {STR_VAR_2}.$"
# 403 "data/scripts/day_care.pory"

# 404 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_YourTeamIsFull:
# 405 "data/scripts/day_care.pory"
	.string "Your Pokémon team is full.\n"
# 406 "data/scripts/day_care.pory"
	.string "Make room, then come see me.$"
# 407 "data/scripts/day_care.pory"

# 408 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_TakeBackWhichMon:
# 409 "data/scripts/day_care.pory"
	.string "Which Pokémon will you take back?$"
# 410 "data/scripts/day_care.pory"

# 411 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_ItWillCostX:
# 412 "data/scripts/day_care.pory"
	.string "If you want your {STR_VAR_1} back,\n"
# 413 "data/scripts/day_care.pory"
	.string "it will cost ¥{STR_VAR_2}.$"
# 414 "data/scripts/day_care.pory"

# 415 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_HeresYourMon:
# 416 "data/scripts/day_care.pory"
	.string "Perfect!\n"
# 417 "data/scripts/day_care.pory"
	.string "Here's your Pokémon.$"
# 418 "data/scripts/day_care.pory"

# 419 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_TookBackMon:
# 420 "data/scripts/day_care.pory"
	.string "{PLAYER} took back {STR_VAR_1} from\n"
# 421 "data/scripts/day_care.pory"
	.string "the Day-Care Lady.$"
# 422 "data/scripts/day_care.pory"

# 423 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_YouHaveJustOneMon:
# 424 "data/scripts/day_care.pory"
	.string "Oh? But you have just one\n"
# 425 "data/scripts/day_care.pory"
	.string "Pokémon.\p"
# 426 "data/scripts/day_care.pory"
	.string "Come back another time.$"
# 427 "data/scripts/day_care.pory"

# 428 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_TakeYourMonBack:
# 429 "data/scripts/day_care.pory"
	.string "Will you take your Pokémon back?$"
# 430 "data/scripts/day_care.pory"

# 431 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_WhatWillYouBattleWith:
# 432 "data/scripts/day_care.pory"
	.string "If you leave me that Pokémon,\n"
# 433 "data/scripts/day_care.pory"
	.string "what will you battle with?\p"
# 434 "data/scripts/day_care.pory"
	.string "Come back another time.$"
# 435 "data/scripts/day_care.pory"

# 436 "data/scripts/day_care.pory"
#if GAME_LANGUAGE == LANGUAGE_SPANISH
# 437 "data/scripts/day_care.pory"
Text_EggHatchHuh:
# 438 "data/scripts/day_care.pory"
	.string "¿Y esto?$"
# 439 "data/scripts/day_care.pory"
#else
# 440 "data/scripts/day_care.pory"
Text_EggHatchHuh:
# 441 "data/scripts/day_care.pory"
	.string "Huh?$"
# 442 "data/scripts/day_care.pory"
#endif
# 443 "data/scripts/day_care.pory"

# 444 "data/scripts/day_care.pory"
Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne:
# 445 "data/scripts/day_care.pory"
	.string "Huh?\n"
# 446 "data/scripts/day_care.pory"
	.string "Now, now.\p"
# 447 "data/scripts/day_care.pory"
	.string "If you leave that Pokémon with\n"
# 448 "data/scripts/day_care.pory"
	.string "me, you'll be left with just one.\p"
# 449 "data/scripts/day_care.pory"
	.string "You will be better off if you catch\n"
# 450 "data/scripts/day_care.pory"
	.string "some more, I dare say.$"
