# 1 "data/scripts/mevent_battle_card.pory"

# 2 "data/scripts/mevent_battle_card.pory"
MysteryEventScript_BattleCard::
# 3 "data/scripts/mevent_battle_card.pory"
	setvaddress MysteryEventScript_BattleCard
# 4 "data/scripts/mevent_battle_card.pory"
	vgoto_if_set FLAG_MYSTERY_EVENT_DONE, MysteryEventScript_BattleCardInfo
# 5 "data/scripts/mevent_battle_card.pory"
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
# 6 "data/scripts/mevent_battle_card.pory"
	specialvar VAR_0x8008, GetMysteryEventCardVal
# 7 "data/scripts/mevent_battle_card.pory"
	compare VAR_0x8008, REQUIRED_CARD_BATTLES
# 8 "data/scripts/mevent_battle_card.pory"
	vgoto_if_ne MysteryEventScript_BattleCardInfo
# 9 "data/scripts/mevent_battle_card.pory"
	lock
# 10 "data/scripts/mevent_battle_card.pory"
	faceplayer
# 11 "data/scripts/mevent_battle_card.pory"
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
# 12 "data/scripts/mevent_battle_card.pory"
	waitmessage
# 13 "data/scripts/mevent_battle_card.pory"
	waitbuttonpress
# 14 "data/scripts/mevent_battle_card.pory"
	giveitem ITEM_POTION
# 15 "data/scripts/mevent_battle_card.pory"
	release
# 16 "data/scripts/mevent_battle_card.pory"
	setflag FLAG_MYSTERY_EVENT_DONE
# 17 "data/scripts/mevent_battle_card.pory"
	end
# 18 "data/scripts/mevent_battle_card.pory"

# 19 "data/scripts/mevent_battle_card.pory"
MysteryEventScript_BattleCardInfo:
# 20 "data/scripts/mevent_battle_card.pory"
	lock
# 21 "data/scripts/mevent_battle_card.pory"
	faceplayer
# 22 "data/scripts/mevent_battle_card.pory"
	vmessage sText_MysteryGiftBattleCountCard
# 23 "data/scripts/mevent_battle_card.pory"
	waitmessage
# 24 "data/scripts/mevent_battle_card.pory"
	waitbuttonpress
# 25 "data/scripts/mevent_battle_card.pory"
	release
# 26 "data/scripts/mevent_battle_card.pory"
	end
# 27 "data/scripts/mevent_battle_card.pory"

# 28 "data/scripts/mevent_battle_card.pory"
sText_MysteryGiftBattleCountCard:
# 29 "data/scripts/mevent_battle_card.pory"
	.string "Thank you for using the Mystery\n"
# 30 "data/scripts/mevent_battle_card.pory"
	.string "Gift System.\p"
# 31 "data/scripts/mevent_battle_card.pory"
	.string "Your Battle Count Card keeps\n"
# 32 "data/scripts/mevent_battle_card.pory"
	.string "track of your battle record against\l"
# 33 "data/scripts/mevent_battle_card.pory"
	.string "Trainers with the same Card.\p"
# 34 "data/scripts/mevent_battle_card.pory"
	.string "Look for and battle Trainers who\n"
# 35 "data/scripts/mevent_battle_card.pory"
	.string "have the same Card as you.\p"
# 36 "data/scripts/mevent_battle_card.pory"
	.string "You may check the overall rankings\n"
# 37 "data/scripts/mevent_battle_card.pory"
	.string "by reading the news.\p"
# 38 "data/scripts/mevent_battle_card.pory"
	.string "Please do give it a try!$"
# 39 "data/scripts/mevent_battle_card.pory"

# 40 "data/scripts/mevent_battle_card.pory"
sText_MysteryGiftBattleCountCard_WonPrize:
# 41 "data/scripts/mevent_battle_card.pory"
	.string "Thank you for using the Mystery\n"
# 42 "data/scripts/mevent_battle_card.pory"
	.string "Gift System.\p"
# 43 "data/scripts/mevent_battle_card.pory"
	.string "Congratulations!\p"
# 44 "data/scripts/mevent_battle_card.pory"
	.string "You have won a prize for winning\n"
# 45 "data/scripts/mevent_battle_card.pory"
	.string "three battles!\p"
# 46 "data/scripts/mevent_battle_card.pory"
	.string "We hope you will be inspired to\n"
# 47 "data/scripts/mevent_battle_card.pory"
	.string "battle some more.$"
