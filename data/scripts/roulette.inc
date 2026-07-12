# 1 "data/scripts/roulette.pory"

# 2 "data/scripts/roulette.pory"
Roulette_EventScript_Table1::
# 3 "data/scripts/roulette.pory"
	checkitem ITEM_COIN_CASE, 1
# 4 "data/scripts/roulette.pory"
	compare VAR_RESULT, FALSE
# 5 "data/scripts/roulette.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
# 6 "data/scripts/roulette.pory"
	setvar VAR_0x8004, 0
# 7 "data/scripts/roulette.pory"
	getpricereduction POKENEWS_GAME_CORNER
# 8 "data/scripts/roulette.pory"
	compare VAR_RESULT, FALSE
# 9 "data/scripts/roulette.pory"
	goto_if_eq Roulette_EventScript_Play
# 10 "data/scripts/roulette.pory"
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
# 11 "data/scripts/roulette.pory"
	goto Roulette_EventScript_Play
# 12 "data/scripts/roulette.pory"
	end
# 13 "data/scripts/roulette.pory"

# 14 "data/scripts/roulette.pory"
Roulette_EventScript_Table2::
# 15 "data/scripts/roulette.pory"
	checkitem ITEM_COIN_CASE, 1
# 16 "data/scripts/roulette.pory"
	compare VAR_RESULT, FALSE
# 17 "data/scripts/roulette.pory"
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
# 18 "data/scripts/roulette.pory"
	setvar VAR_0x8004, 1
# 19 "data/scripts/roulette.pory"
	getpricereduction POKENEWS_GAME_CORNER
# 20 "data/scripts/roulette.pory"
	compare VAR_RESULT, FALSE
# 21 "data/scripts/roulette.pory"
	goto_if_eq Roulette_EventScript_Play
# 22 "data/scripts/roulette.pory"
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
# 23 "data/scripts/roulette.pory"
	goto Roulette_EventScript_Play
# 24 "data/scripts/roulette.pory"
	end
# 25 "data/scripts/roulette.pory"

# 26 "data/scripts/roulette.pory"
Roulette_EventScript_Play::
# 27 "data/scripts/roulette.pory"
	special PlayRoulette
# 28 "data/scripts/roulette.pory"
	waitstate
# 29 "data/scripts/roulette.pory"
	end

Roulette_Text_PlayMinimumWagerIsX::
# 32 "data/scripts/roulette.pory"
	.string "The minimum wager at this table\n"
	.string "is {STR_VAR_1}. Do you want to play?$"

Roulette_Text_NotEnoughCoins::
# 37 "data/scripts/roulette.pory"
	.string "You don't have enough Coins.$"

Roulette_Text_SpecialRateTable::
# 41 "data/scripts/roulette.pory"
	.string "Special rate table right now!$"

Roulette_Text_ControlsInstruction::
# 45 "data/scripts/roulette.pory"
	.string "Place your wager with the + Control\n"
	.string "Pad, then press the A Button.$"

Roulette_Text_ItsAHit::
# 50 "data/scripts/roulette.pory"
	.string "It's a hit!$"

Roulette_Text_Jackpot::
# 54 "data/scripts/roulette.pory"
	.string "Jackpot!$"

Roulette_Text_NothingDoing::
# 58 "data/scripts/roulette.pory"
	.string "Nothing doing!$"

Roulette_Text_YouveWonXCoins::
# 62 "data/scripts/roulette.pory"
	.string "You've won {STR_VAR_1} Coins!$"

Roulette_Text_NoCoinsLeft::
# 66 "data/scripts/roulette.pory"
	.string "No Coins left…$"

Roulette_Text_KeepPlaying::
# 70 "data/scripts/roulette.pory"
	.string "Keep playing?$"

Roulette_Text_BoardWillBeCleared::
# 74 "data/scripts/roulette.pory"
	.string "The Roulette board will be cleared.$"

Roulette_Text_YouDontHaveACoinCase::
# 78 "data/scripts/roulette.pory"
	.string "You don't have a Coin Case.$"

Roulette_Text_CoinCaseIsFull::
# 82 "data/scripts/roulette.pory"
	.string "Your Coin Case is full!\n"
	.string "Coins can be exchanged for prizes.$"
