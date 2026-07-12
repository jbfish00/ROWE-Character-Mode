EventScript_MixRecordsPrompt::
# 2 "data/scripts/record_mix.pory"
	lock
# 3 "data/scripts/record_mix.pory"
	faceplayer
# 4 "data/scripts/record_mix.pory"
	msgbox Text_WouldYouLikeToMixRecords, MSGBOX_YESNO
# 5 "data/scripts/record_mix.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_MixRecordsPrompt_2
EventScript_MixRecordsPrompt_1:
# 8 "data/scripts/record_mix.pory"
	goto EventScript_DeclineMixRecords
	return

EventScript_MixRecordsPrompt_2:
# 6 "data/scripts/record_mix.pory"
	goto EventScript_MixRecords
	goto EventScript_MixRecordsPrompt_1


# 11 "data/scripts/record_mix.pory"

# 12 "data/scripts/record_mix.pory"
EventScript_MixRecords::
# 13 "data/scripts/record_mix.pory"
	special RecordMixingPlayerSpotTriggered
# 14 "data/scripts/record_mix.pory"
	waitstate
# 15 "data/scripts/record_mix.pory"
	lock
# 16 "data/scripts/record_mix.pory"
	faceplayer

EventScript_DeclineMixRecords::
# 20 "data/scripts/record_mix.pory"
	message Text_WeHopeToSeeYouAgain
# 21 "data/scripts/record_mix.pory"
	waitmessage
# 22 "data/scripts/record_mix.pory"
	waitbuttonpress
# 23 "data/scripts/record_mix.pory"
	release
	end

