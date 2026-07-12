# 1 "data/scripts/mevent_altering_cave.pory"

# 2 "data/scripts/mevent_altering_cave.pory"
MysteryEventScript_AlteringCave::
# 3 "data/scripts/mevent_altering_cave.pory"
	setvaddress MysteryEventScript_AlteringCave
# 4 "data/scripts/mevent_altering_cave.pory"
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
# 5 "data/scripts/mevent_altering_cave.pory"
	compare VAR_ALTERING_CAVE_WILD_SET, 10
# 6 "data/scripts/mevent_altering_cave.pory"
	vgoto_if_ne MysteryEventScript_AlteringCave_
# 7 "data/scripts/mevent_altering_cave.pory"
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
# 8 "data/scripts/mevent_altering_cave.pory"
MysteryEventScript_AlteringCave_:
# 9 "data/scripts/mevent_altering_cave.pory"
	lock
# 10 "data/scripts/mevent_altering_cave.pory"
	faceplayer
# 11 "data/scripts/mevent_altering_cave.pory"
	vmessage sText_MysteryGiftAlteringCave
# 12 "data/scripts/mevent_altering_cave.pory"
	waitmessage
# 13 "data/scripts/mevent_altering_cave.pory"
	waitbuttonpress
# 14 "data/scripts/mevent_altering_cave.pory"
	release
# 15 "data/scripts/mevent_altering_cave.pory"
	end
# 16 "data/scripts/mevent_altering_cave.pory"

# 17 "data/scripts/mevent_altering_cave.pory"
sText_MysteryGiftAlteringCave::
# 18 "data/scripts/mevent_altering_cave.pory"
	.string "Thank you for using the Mystery\n"
# 19 "data/scripts/mevent_altering_cave.pory"
	.string "Gift System.\p"
# 20 "data/scripts/mevent_altering_cave.pory"
	.string "There appears to be a rumor about\n"
# 21 "data/scripts/mevent_altering_cave.pory"
	.string "rare Pokémon sightings.\p"
# 22 "data/scripts/mevent_altering_cave.pory"
	.string "The sightings reportedly came from\n"
# 23 "data/scripts/mevent_altering_cave.pory"
	.string "the Altering Cave on Route 103.\p"
# 24 "data/scripts/mevent_altering_cave.pory"
	.string "Perhaps it would be worthwhile for\n"
# 25 "data/scripts/mevent_altering_cave.pory"
	.string "you to investigate this rumor.$"
