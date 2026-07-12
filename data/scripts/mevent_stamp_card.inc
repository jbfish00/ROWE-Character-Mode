# 1 "data/scripts/mevent_stamp_card.pory"

# 2 "data/scripts/mevent_stamp_card.pory"
MysteryEventScript_StampCard::
# 3 "data/scripts/mevent_stamp_card.pory"
	setvaddress MysteryEventScript_StampCard
# 4 "data/scripts/mevent_stamp_card.pory"
	setorcopyvar VAR_RESULT, GET_MAX_STAMPS
# 5 "data/scripts/mevent_stamp_card.pory"
	specialvar VAR_0x8008, GetMysteryEventCardVal
# 6 "data/scripts/mevent_stamp_card.pory"
	setorcopyvar VAR_RESULT, GET_NUM_STAMPS
# 7 "data/scripts/mevent_stamp_card.pory"
	specialvar VAR_0x8009, GetMysteryEventCardVal
# 8 "data/scripts/mevent_stamp_card.pory"
	subvar VAR_0x8008, VAR_0x8009
# 9 "data/scripts/mevent_stamp_card.pory"
	buffernumberstring 0, VAR_0x8008
# 10 "data/scripts/mevent_stamp_card.pory"
	lock
# 11 "data/scripts/mevent_stamp_card.pory"
	faceplayer
# 12 "data/scripts/mevent_stamp_card.pory"
	vmessage sText_MysteryGiftStampCard
# 13 "data/scripts/mevent_stamp_card.pory"
	waitmessage
# 14 "data/scripts/mevent_stamp_card.pory"
	waitbuttonpress
# 15 "data/scripts/mevent_stamp_card.pory"
	release
# 16 "data/scripts/mevent_stamp_card.pory"
	end
# 17 "data/scripts/mevent_stamp_card.pory"

# 18 "data/scripts/mevent_stamp_card.pory"
sText_MysteryGiftStampCard:
# 19 "data/scripts/mevent_stamp_card.pory"
	.string "Thank you for using the Stamp Card\n"
# 20 "data/scripts/mevent_stamp_card.pory"
	.string "System.\p"
# 21 "data/scripts/mevent_stamp_card.pory"
	.string "You have {STR_VAR_1} more to collect to\n"
# 22 "data/scripts/mevent_stamp_card.pory"
	.string "fill your Stamp Card.$"
