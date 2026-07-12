# 1 "data/scripts/mevent_aurora_ticket.pory"

# 2 "data/scripts/mevent_aurora_ticket.pory"
MysteryEventScript_AuroraTicket::
# 3 "data/scripts/mevent_aurora_ticket.pory"
	setvaddress MysteryEventScript_AuroraTicket
# 4 "data/scripts/mevent_aurora_ticket.pory"
	lock
# 5 "data/scripts/mevent_aurora_ticket.pory"
	faceplayer
# 6 "data/scripts/mevent_aurora_ticket.pory"
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
# 7 "data/scripts/mevent_aurora_ticket.pory"
	vgoto_if_set FLAG_BATTLED_DEOXYS, AuroraTicket_Obtained
# 8 "data/scripts/mevent_aurora_ticket.pory"
	checkitem ITEM_AURORA_TICKET, 1
# 9 "data/scripts/mevent_aurora_ticket.pory"
	compare VAR_RESULT, TRUE
# 10 "data/scripts/mevent_aurora_ticket.pory"
	vgoto_if_eq AuroraTicket_Obtained
# 11 "data/scripts/mevent_aurora_ticket.pory"
	vmessage sText_AuroraTicketForYou
# 12 "data/scripts/mevent_aurora_ticket.pory"
	waitmessage
# 13 "data/scripts/mevent_aurora_ticket.pory"
	waitbuttonpress
# 14 "data/scripts/mevent_aurora_ticket.pory"
	checkitemspace ITEM_AURORA_TICKET, 1
# 15 "data/scripts/mevent_aurora_ticket.pory"
	compare VAR_RESULT, FALSE
# 16 "data/scripts/mevent_aurora_ticket.pory"
	vgoto_if_eq AuroraTicket_NoBagSpace
# 17 "data/scripts/mevent_aurora_ticket.pory"
	giveitem ITEM_AURORA_TICKET
# 18 "data/scripts/mevent_aurora_ticket.pory"
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
# 19 "data/scripts/mevent_aurora_ticket.pory"
	setflag FLAG_RECEIVED_AURORA_TICKET
# 20 "data/scripts/mevent_aurora_ticket.pory"
	vmessage sText_AuroraTicketUseAtPort
# 21 "data/scripts/mevent_aurora_ticket.pory"
	waitmessage
# 22 "data/scripts/mevent_aurora_ticket.pory"
	waitbuttonpress
# 23 "data/scripts/mevent_aurora_ticket.pory"
	release
# 24 "data/scripts/mevent_aurora_ticket.pory"
	end
# 25 "data/scripts/mevent_aurora_ticket.pory"

# 26 "data/scripts/mevent_aurora_ticket.pory"
AuroraTicket_NoBagSpace:
# 27 "data/scripts/mevent_aurora_ticket.pory"
	vmessage sText_AuroraTicketBagFull
# 28 "data/scripts/mevent_aurora_ticket.pory"
	waitmessage
# 29 "data/scripts/mevent_aurora_ticket.pory"
	waitbuttonpress
# 30 "data/scripts/mevent_aurora_ticket.pory"
	release
# 31 "data/scripts/mevent_aurora_ticket.pory"
	end
# 32 "data/scripts/mevent_aurora_ticket.pory"

# 33 "data/scripts/mevent_aurora_ticket.pory"
AuroraTicket_Obtained:
# 34 "data/scripts/mevent_aurora_ticket.pory"
	vmessage sText_AuroraTicketThankYou
# 35 "data/scripts/mevent_aurora_ticket.pory"
	waitmessage
# 36 "data/scripts/mevent_aurora_ticket.pory"
	waitbuttonpress
# 37 "data/scripts/mevent_aurora_ticket.pory"
	release
# 38 "data/scripts/mevent_aurora_ticket.pory"
	end
# 39 "data/scripts/mevent_aurora_ticket.pory"

# 40 "data/scripts/mevent_aurora_ticket.pory"
sText_AuroraTicketForYou:
# 41 "data/scripts/mevent_aurora_ticket.pory"
	.string "Thank you for using the Mystery\n"
# 42 "data/scripts/mevent_aurora_ticket.pory"
	.string "Gift System.\p"
# 43 "data/scripts/mevent_aurora_ticket.pory"
	.string "You must be {PLAYER}.\n"
# 44 "data/scripts/mevent_aurora_ticket.pory"
	.string "There is a ticket here for you.$"
# 45 "data/scripts/mevent_aurora_ticket.pory"

# 46 "data/scripts/mevent_aurora_ticket.pory"
sText_AuroraTicketUseAtPort:
# 47 "data/scripts/mevent_aurora_ticket.pory"
	.string "It appears to be for use at the\n"
# 48 "data/scripts/mevent_aurora_ticket.pory"
	.string "Lilycove City port.\p"
# 49 "data/scripts/mevent_aurora_ticket.pory"
	.string "Why not give it a try and see what\n"
# 50 "data/scripts/mevent_aurora_ticket.pory"
	.string "it is about?$"
# 51 "data/scripts/mevent_aurora_ticket.pory"

# 52 "data/scripts/mevent_aurora_ticket.pory"
sText_AuroraTicketThankYou:
# 53 "data/scripts/mevent_aurora_ticket.pory"
	.string "Thank you for using the Mystery\n"
# 54 "data/scripts/mevent_aurora_ticket.pory"
	.string "Gift System.$"
# 55 "data/scripts/mevent_aurora_ticket.pory"

# 56 "data/scripts/mevent_aurora_ticket.pory"
sText_AuroraTicketBagFull:
# 57 "data/scripts/mevent_aurora_ticket.pory"
	.string "Oh, I'm sorry, {PLAYER}.\n"
# 58 "data/scripts/mevent_aurora_ticket.pory"
	.string "Your bag's Key Items Pocket is full.\p"
# 59 "data/scripts/mevent_aurora_ticket.pory"
	.string "Please store something on your PC,\n"
# 60 "data/scripts/mevent_aurora_ticket.pory"
	.string "then come back for this.$"
