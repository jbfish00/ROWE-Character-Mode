# 1 "data/scripts/mevent_trainer.pory"

# 2 "data/scripts/mevent_trainer.pory"
MysteryEventScript_VisitingTrainer::
# 3 "data/scripts/mevent_trainer.pory"
	setvaddress MysteryEventScript_VisitingTrainer
# 4 "data/scripts/mevent_trainer.pory"
	special ValidateEReaderTrainer
# 5 "data/scripts/mevent_trainer.pory"
	compare VAR_RESULT, 0
# 6 "data/scripts/mevent_trainer.pory"
	vgoto_if_eq MysteryEventScript_VisitingTrainerArrived
# 7 "data/scripts/mevent_trainer.pory"
	lock
# 8 "data/scripts/mevent_trainer.pory"
	faceplayer
# 9 "data/scripts/mevent_trainer.pory"
	vmessage sText_MysteryGiftVisitingTrainerInstructions
# 10 "data/scripts/mevent_trainer.pory"
	waitmessage
# 11 "data/scripts/mevent_trainer.pory"
	waitbuttonpress
# 12 "data/scripts/mevent_trainer.pory"
	release
# 13 "data/scripts/mevent_trainer.pory"
	end
# 14 "data/scripts/mevent_trainer.pory"

# 15 "data/scripts/mevent_trainer.pory"
MysteryEventScript_VisitingTrainerArrived:
# 16 "data/scripts/mevent_trainer.pory"
	lock
# 17 "data/scripts/mevent_trainer.pory"
	faceplayer
# 18 "data/scripts/mevent_trainer.pory"
	vmessage sText_MysteryGiftVisitingTrainerArrived
# 19 "data/scripts/mevent_trainer.pory"
	waitmessage
# 20 "data/scripts/mevent_trainer.pory"
	waitbuttonpress
# 21 "data/scripts/mevent_trainer.pory"
	release
# 22 "data/scripts/mevent_trainer.pory"
	end
# 23 "data/scripts/mevent_trainer.pory"

# 24 "data/scripts/mevent_trainer.pory"
sText_MysteryGiftVisitingTrainerInstructions:
# 25 "data/scripts/mevent_trainer.pory"
	.string "Thank you for using the Mystery\n"
# 26 "data/scripts/mevent_trainer.pory"
	.string "Gift System.\p"
# 27 "data/scripts/mevent_trainer.pory"
	.string "By holding this Wonder Card, you\n"
# 28 "data/scripts/mevent_trainer.pory"
	.string "may take part in a survey at a\l"
# 29 "data/scripts/mevent_trainer.pory"
	.string "Pokémon Mart.\p"
# 30 "data/scripts/mevent_trainer.pory"
	.string "Use these surveys to invite\n"
# 31 "data/scripts/mevent_trainer.pory"
	.string "Trainers to Sootopolis City.\p"
# 32 "data/scripts/mevent_trainer.pory"
	.string "…Let me give you a secret\n"
# 33 "data/scripts/mevent_trainer.pory"
	.string "password for a survey:\p"
# 34 "data/scripts/mevent_trainer.pory"
	.string "“Give Me\n"
# 35 "data/scripts/mevent_trainer.pory"
	.string "Awesome Trainer”\p"
# 36 "data/scripts/mevent_trainer.pory"
	.string "Write that in on a survey and send\n"
# 37 "data/scripts/mevent_trainer.pory"
	.string "it to the Wireless\l"
# 38 "data/scripts/mevent_trainer.pory"
	.string "Communication System.$"
# 39 "data/scripts/mevent_trainer.pory"

# 40 "data/scripts/mevent_trainer.pory"
sText_MysteryGiftVisitingTrainerArrived:
# 41 "data/scripts/mevent_trainer.pory"
	.string "Thank you for using the Mystery\n"
# 42 "data/scripts/mevent_trainer.pory"
	.string "Gift System.\p"
# 43 "data/scripts/mevent_trainer.pory"
	.string "A Trainer has arrived in\n"
# 44 "data/scripts/mevent_trainer.pory"
	.string "Sootopolis City looking for you.\p"
# 45 "data/scripts/mevent_trainer.pory"
	.string "We hope you will enjoy\n"
# 46 "data/scripts/mevent_trainer.pory"
	.string "battling the visiting Trainer.\p"
# 47 "data/scripts/mevent_trainer.pory"
	.string "You may invite other Trainers by\n"
# 48 "data/scripts/mevent_trainer.pory"
	.string "entering other passwords.\p"
# 49 "data/scripts/mevent_trainer.pory"
	.string "Try looking for other passwords\n"
# 50 "data/scripts/mevent_trainer.pory"
	.string "that may work.$"
