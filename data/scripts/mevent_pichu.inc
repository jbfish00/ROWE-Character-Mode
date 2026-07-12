# 1 "data/scripts/mevent_pichu.pory"

# 2 "data/scripts/mevent_pichu.pory"
MysteryEventScript_SurfPichu::
# 3 "data/scripts/mevent_pichu.pory"
	setvaddress MysteryEventScript_SurfPichu
# 4 "data/scripts/mevent_pichu.pory"
	vgoto_if_unset FLAG_MYSTERY_EVENT_DONE, SurfPichu_GiveIfPossible
# 5 "data/scripts/mevent_pichu.pory"
	returnram
# 6 "data/scripts/mevent_pichu.pory"

# 7 "data/scripts/mevent_pichu.pory"
SurfPichu_GiveIfPossible:
# 8 "data/scripts/mevent_pichu.pory"
	specialvar VAR_EVENT_PICHU_SLOT, CalculatePlayerPartyCount
# 9 "data/scripts/mevent_pichu.pory"
	compare VAR_EVENT_PICHU_SLOT, PARTY_SIZE
# 10 "data/scripts/mevent_pichu.pory"
	vgoto_if_eq SurfPichu_FullParty
# 11 "data/scripts/mevent_pichu.pory"
	setflag FLAG_MYSTERY_EVENT_DONE
# 12 "data/scripts/mevent_pichu.pory"
	vcall SurfPichu_GiveEgg
# 13 "data/scripts/mevent_pichu.pory"
	lock
# 14 "data/scripts/mevent_pichu.pory"
	faceplayer
# 15 "data/scripts/mevent_pichu.pory"
	vmessage sText_MysteryGiftEgg
# 16 "data/scripts/mevent_pichu.pory"
	waitmessage
# 17 "data/scripts/mevent_pichu.pory"
	waitbuttonpress
# 18 "data/scripts/mevent_pichu.pory"
	playfanfare MUS_OBTAIN_ITEM
# 19 "data/scripts/mevent_pichu.pory"
	waitfanfare
# 20 "data/scripts/mevent_pichu.pory"
	release
# 21 "data/scripts/mevent_pichu.pory"
	end
# 22 "data/scripts/mevent_pichu.pory"

# 23 "data/scripts/mevent_pichu.pory"
SurfPichu_FullParty:
# 24 "data/scripts/mevent_pichu.pory"
	lock
# 25 "data/scripts/mevent_pichu.pory"
	faceplayer
# 26 "data/scripts/mevent_pichu.pory"
	vmessage sText_FullParty
# 27 "data/scripts/mevent_pichu.pory"
	waitmessage
# 28 "data/scripts/mevent_pichu.pory"
	waitbuttonpress
# 29 "data/scripts/mevent_pichu.pory"
	release
# 30 "data/scripts/mevent_pichu.pory"
	end
# 31 "data/scripts/mevent_pichu.pory"

# 32 "data/scripts/mevent_pichu.pory"
SurfPichu_GiveEgg:
# 33 "data/scripts/mevent_pichu.pory"
	giveegg SPECIES_PICHU
# 34 "data/scripts/mevent_pichu.pory"
	setmonobedient VAR_EVENT_PICHU_SLOT
# 35 "data/scripts/mevent_pichu.pory"
	setmonmetlocation VAR_EVENT_PICHU_SLOT, METLOC_FATEFUL_ENCOUNTER
# 36 "data/scripts/mevent_pichu.pory"
	compare VAR_EVENT_PICHU_SLOT, 1
# 37 "data/scripts/mevent_pichu.pory"
	vgoto_if_eq SurfPichu_Slot1
# 38 "data/scripts/mevent_pichu.pory"
	compare VAR_EVENT_PICHU_SLOT, 2
# 39 "data/scripts/mevent_pichu.pory"
	vgoto_if_eq SurfPichu_Slot2
# 40 "data/scripts/mevent_pichu.pory"
	compare VAR_EVENT_PICHU_SLOT, 3
# 41 "data/scripts/mevent_pichu.pory"
	vgoto_if_eq SurfPichu_Slot3
# 42 "data/scripts/mevent_pichu.pory"
	compare VAR_EVENT_PICHU_SLOT, 4
# 43 "data/scripts/mevent_pichu.pory"
	vgoto_if_eq SurfPichu_Slot4
# 44 "data/scripts/mevent_pichu.pory"
	compare VAR_EVENT_PICHU_SLOT, 5
# 45 "data/scripts/mevent_pichu.pory"
	vgoto_if_eq SurfPichu_Slot5
# 46 "data/scripts/mevent_pichu.pory"
	return
# 47 "data/scripts/mevent_pichu.pory"

# 48 "data/scripts/mevent_pichu.pory"
SurfPichu_Slot1:
# 49 "data/scripts/mevent_pichu.pory"
	setmonmove 1, 2, MOVE_SURF
# 50 "data/scripts/mevent_pichu.pory"
	return
# 51 "data/scripts/mevent_pichu.pory"

# 52 "data/scripts/mevent_pichu.pory"
SurfPichu_Slot2::
# 53 "data/scripts/mevent_pichu.pory"
	setmonmove 2, 2, MOVE_SURF
# 54 "data/scripts/mevent_pichu.pory"
	return
# 55 "data/scripts/mevent_pichu.pory"

# 56 "data/scripts/mevent_pichu.pory"
SurfPichu_Slot3:
# 57 "data/scripts/mevent_pichu.pory"
	setmonmove 3, 2, MOVE_SURF
# 58 "data/scripts/mevent_pichu.pory"
	return
# 59 "data/scripts/mevent_pichu.pory"

# 60 "data/scripts/mevent_pichu.pory"
SurfPichu_Slot4:
# 61 "data/scripts/mevent_pichu.pory"
	setmonmove 4, 2, MOVE_SURF
# 62 "data/scripts/mevent_pichu.pory"
	return
# 63 "data/scripts/mevent_pichu.pory"

# 64 "data/scripts/mevent_pichu.pory"
SurfPichu_Slot5:
# 65 "data/scripts/mevent_pichu.pory"
	setmonmove 5, 2, MOVE_SURF
# 66 "data/scripts/mevent_pichu.pory"
	return
# 67 "data/scripts/mevent_pichu.pory"

# 68 "data/scripts/mevent_pichu.pory"
sText_MysteryGiftEgg:
# 69 "data/scripts/mevent_pichu.pory"
	.string "Thank you for using the Mystery\n"
# 70 "data/scripts/mevent_pichu.pory"
	.string "Gift System.\p"
# 71 "data/scripts/mevent_pichu.pory"
	.string "From the Pokémon Center we\n"
# 72 "data/scripts/mevent_pichu.pory"
	.string "have a gift--a Pokémon egg!\p"
# 73 "data/scripts/mevent_pichu.pory"
	.string "Please raise it with love and\n"
# 74 "data/scripts/mevent_pichu.pory"
	.string "kindness.$"
# 75 "data/scripts/mevent_pichu.pory"

# 76 "data/scripts/mevent_pichu.pory"
sText_FullParty:
# 77 "data/scripts/mevent_pichu.pory"
	.string "Oh, your party appears to be full.\p"
# 78 "data/scripts/mevent_pichu.pory"
	.string "Please come see me after storing\n"
# 79 "data/scripts/mevent_pichu.pory"
	.string "a Pokémon on a PC.$"
