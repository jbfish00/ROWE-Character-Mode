# 1 "data/scripts/mevent_mystic_ticket.pory"

# 2 "data/scripts/mevent_mystic_ticket.pory"
MysteryEventScript_MysticTicket::
# 3 "data/scripts/mevent_mystic_ticket.pory"
	setvaddress MysteryEventScript_MysticTicket
# 4 "data/scripts/mevent_mystic_ticket.pory"
	lock
# 5 "data/scripts/mevent_mystic_ticket.pory"
	faceplayer
# 6 "data/scripts/mevent_mystic_ticket.pory"
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
# 7 "data/scripts/mevent_mystic_ticket.pory"
	vgoto_if_set FLAG_CAUGHT_LUGIA, MysticTicket_Obtained
# 8 "data/scripts/mevent_mystic_ticket.pory"
	vgoto_if_set FLAG_CAUGHT_HO_OH, MysticTicket_Obtained
# 9 "data/scripts/mevent_mystic_ticket.pory"
	checkitem ITEM_MYSTIC_TICKET, 1
# 10 "data/scripts/mevent_mystic_ticket.pory"
	compare VAR_RESULT, TRUE
# 11 "data/scripts/mevent_mystic_ticket.pory"
	vgoto_if_eq MysticTicket_Obtained
# 12 "data/scripts/mevent_mystic_ticket.pory"
	vmessage sText_MysticTicketForYou
# 13 "data/scripts/mevent_mystic_ticket.pory"
	waitmessage
# 14 "data/scripts/mevent_mystic_ticket.pory"
	waitbuttonpress
# 15 "data/scripts/mevent_mystic_ticket.pory"
	checkitemspace ITEM_MYSTIC_TICKET, 1
# 16 "data/scripts/mevent_mystic_ticket.pory"
	compare VAR_RESULT, FALSE
# 17 "data/scripts/mevent_mystic_ticket.pory"
	vgoto_if_eq MysticTicket_NoBagSpace
# 18 "data/scripts/mevent_mystic_ticket.pory"
	giveitem ITEM_MYSTIC_TICKET
# 19 "data/scripts/mevent_mystic_ticket.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 20 "data/scripts/mevent_mystic_ticket.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 21 "data/scripts/mevent_mystic_ticket.pory"
	vmessage sText_MysticTicketUseAtPort
# 22 "data/scripts/mevent_mystic_ticket.pory"
	waitmessage
# 23 "data/scripts/mevent_mystic_ticket.pory"
	waitbuttonpress
# 24 "data/scripts/mevent_mystic_ticket.pory"
	release
# 25 "data/scripts/mevent_mystic_ticket.pory"
	end
# 26 "data/scripts/mevent_mystic_ticket.pory"

# 27 "data/scripts/mevent_mystic_ticket.pory"
MysticTicket_NoBagSpace:
# 28 "data/scripts/mevent_mystic_ticket.pory"
	vmessage sText_MysticTicketBagFull
# 29 "data/scripts/mevent_mystic_ticket.pory"
	waitmessage
# 30 "data/scripts/mevent_mystic_ticket.pory"
	waitbuttonpress
# 31 "data/scripts/mevent_mystic_ticket.pory"
	release
# 32 "data/scripts/mevent_mystic_ticket.pory"
	end
# 33 "data/scripts/mevent_mystic_ticket.pory"

# 34 "data/scripts/mevent_mystic_ticket.pory"
MysticTicket_Obtained:
# 35 "data/scripts/mevent_mystic_ticket.pory"
	vmessage sText_MysticTicketThankYou
# 36 "data/scripts/mevent_mystic_ticket.pory"
	waitmessage
# 37 "data/scripts/mevent_mystic_ticket.pory"
	waitbuttonpress
# 38 "data/scripts/mevent_mystic_ticket.pory"
	release
# 39 "data/scripts/mevent_mystic_ticket.pory"
	end
# 40 "data/scripts/mevent_mystic_ticket.pory"

# 41 "data/scripts/mevent_mystic_ticket.pory"
sText_MysticTicketForYou:
# 42 "data/scripts/mevent_mystic_ticket.pory"
	.string "Thank you for using the Mystery\n"
# 43 "data/scripts/mevent_mystic_ticket.pory"
	.string "Gift System.\p"
# 44 "data/scripts/mevent_mystic_ticket.pory"
	.string "You must be {PLAYER}.\n"
# 45 "data/scripts/mevent_mystic_ticket.pory"
	.string "There is a ticket here for you.$"
# 46 "data/scripts/mevent_mystic_ticket.pory"

# 47 "data/scripts/mevent_mystic_ticket.pory"
sText_MysticTicketUseAtPort:
# 48 "data/scripts/mevent_mystic_ticket.pory"
	.string "It appears to be for use at the\n"
# 49 "data/scripts/mevent_mystic_ticket.pory"
	.string "Lilycove City port.\p"
# 50 "data/scripts/mevent_mystic_ticket.pory"
	.string "Why not give it a try and see what\n"
# 51 "data/scripts/mevent_mystic_ticket.pory"
	.string "it is about?$"
# 52 "data/scripts/mevent_mystic_ticket.pory"

# 53 "data/scripts/mevent_mystic_ticket.pory"
sText_MysticTicketThankYou:
# 54 "data/scripts/mevent_mystic_ticket.pory"
	.string "Thank you for using the Mystery\n"
# 55 "data/scripts/mevent_mystic_ticket.pory"
	.string "Gift System.$"
# 56 "data/scripts/mevent_mystic_ticket.pory"

# 57 "data/scripts/mevent_mystic_ticket.pory"
sText_MysticTicketBagFull:
# 58 "data/scripts/mevent_mystic_ticket.pory"
	.string "Oh, I'm sorry, {PLAYER}.\n"
# 59 "data/scripts/mevent_mystic_ticket.pory"
	.string "Your Bag's Key Items Pocket is full.\p"
# 60 "data/scripts/mevent_mystic_ticket.pory"
	.string "Please store something on your PC,\n"
# 61 "data/scripts/mevent_mystic_ticket.pory"
	.string "then come back for this.$"
