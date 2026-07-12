# 1 "data/scripts/mevent_old_sea_map.pory"

# 2 "data/scripts/mevent_old_sea_map.pory"
MysteryEventScript_OldSeaMap::
# 3 "data/scripts/mevent_old_sea_map.pory"
	setvaddress MysteryEventScript_OldSeaMap
# 4 "data/scripts/mevent_old_sea_map.pory"
	lock
# 5 "data/scripts/mevent_old_sea_map.pory"
	faceplayer
# 6 "data/scripts/mevent_old_sea_map.pory"
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
# 7 "data/scripts/mevent_old_sea_map.pory"
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
# 8 "data/scripts/mevent_old_sea_map.pory"
	checkitem ITEM_OLD_SEA_MAP, 1
# 9 "data/scripts/mevent_old_sea_map.pory"
	compare VAR_RESULT, TRUE
# 10 "data/scripts/mevent_old_sea_map.pory"
	vgoto_if_eq OldSeaMap_Obtained
# 11 "data/scripts/mevent_old_sea_map.pory"
	vmessage sText_MysteryGiftOldSeaMapForYou
# 12 "data/scripts/mevent_old_sea_map.pory"
	waitmessage
# 13 "data/scripts/mevent_old_sea_map.pory"
	waitbuttonpress
# 14 "data/scripts/mevent_old_sea_map.pory"
	checkitemspace ITEM_OLD_SEA_MAP, 1
# 15 "data/scripts/mevent_old_sea_map.pory"
	compare VAR_RESULT, FALSE
# 16 "data/scripts/mevent_old_sea_map.pory"
	vgoto_if_eq OldSeaMap_NoBagSpace
# 17 "data/scripts/mevent_old_sea_map.pory"
	giveitem ITEM_OLD_SEA_MAP
# 18 "data/scripts/mevent_old_sea_map.pory"
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
# 19 "data/scripts/mevent_old_sea_map.pory"
	setflag FLAG_RECEIVED_OLD_SEA_MAP
# 20 "data/scripts/mevent_old_sea_map.pory"
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
# 21 "data/scripts/mevent_old_sea_map.pory"
	waitmessage
# 22 "data/scripts/mevent_old_sea_map.pory"
	waitbuttonpress
# 23 "data/scripts/mevent_old_sea_map.pory"
	release
# 24 "data/scripts/mevent_old_sea_map.pory"
	end
# 25 "data/scripts/mevent_old_sea_map.pory"

# 26 "data/scripts/mevent_old_sea_map.pory"
OldSeaMap_NoBagSpace:
# 27 "data/scripts/mevent_old_sea_map.pory"
	vmessage sText_MysteryGiftOldSeaMapBagFull
# 28 "data/scripts/mevent_old_sea_map.pory"
	waitmessage
# 29 "data/scripts/mevent_old_sea_map.pory"
	waitbuttonpress
# 30 "data/scripts/mevent_old_sea_map.pory"
	release
# 31 "data/scripts/mevent_old_sea_map.pory"
	end
# 32 "data/scripts/mevent_old_sea_map.pory"

# 33 "data/scripts/mevent_old_sea_map.pory"
OldSeaMap_Obtained:
# 34 "data/scripts/mevent_old_sea_map.pory"
	vmessage sText_MysteryGiftOldSeaMapThankYou
# 35 "data/scripts/mevent_old_sea_map.pory"
	waitmessage
# 36 "data/scripts/mevent_old_sea_map.pory"
	waitbuttonpress
# 37 "data/scripts/mevent_old_sea_map.pory"
	release
# 38 "data/scripts/mevent_old_sea_map.pory"
	end
# 39 "data/scripts/mevent_old_sea_map.pory"

# 40 "data/scripts/mevent_old_sea_map.pory"
sText_MysteryGiftOldSeaMapForYou:
# 41 "data/scripts/mevent_old_sea_map.pory"
	.string "Thank you for using the Mystery\n"
# 42 "data/scripts/mevent_old_sea_map.pory"
	.string "Gift System.\p"
# 43 "data/scripts/mevent_old_sea_map.pory"
	.string "Let me confirm--you are {PLAYER}?\p"
# 44 "data/scripts/mevent_old_sea_map.pory"
	.string "We received this Old Sea Map\n"
# 45 "data/scripts/mevent_old_sea_map.pory"
	.string "addressed to you.$"
# 46 "data/scripts/mevent_old_sea_map.pory"

# 47 "data/scripts/mevent_old_sea_map.pory"
sText_MysteryGiftOldSeaMapUseAtPort:
# 48 "data/scripts/mevent_old_sea_map.pory"
	.string "It appears to be for use at the\n"
# 49 "data/scripts/mevent_old_sea_map.pory"
	.string "Lilycove City port.\p"
# 50 "data/scripts/mevent_old_sea_map.pory"
	.string "Why not give it a try and see what\n"
# 51 "data/scripts/mevent_old_sea_map.pory"
	.string "it is about?$"
# 52 "data/scripts/mevent_old_sea_map.pory"

# 53 "data/scripts/mevent_old_sea_map.pory"
sText_MysteryGiftOldSeaMapThankYou:
# 54 "data/scripts/mevent_old_sea_map.pory"
	.string "Thank you for using the Mystery\n"
# 55 "data/scripts/mevent_old_sea_map.pory"
	.string "Gift System.$"
# 56 "data/scripts/mevent_old_sea_map.pory"

# 57 "data/scripts/mevent_old_sea_map.pory"
sText_MysteryGiftOldSeaMapBagFull:
# 58 "data/scripts/mevent_old_sea_map.pory"
	.string "Oh, I'm sorry, {PLAYER}.\n"
# 59 "data/scripts/mevent_old_sea_map.pory"
	.string "Your Bag's Key Items Pocket is full.\p"
# 60 "data/scripts/mevent_old_sea_map.pory"
	.string "Please store something on your PC,\n"
# 61 "data/scripts/mevent_old_sea_map.pory"
	.string "then come back for this.$"
