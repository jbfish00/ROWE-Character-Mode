# 1 "data/scripts/trainer_script.pory"

# 2 "data/scripts/trainer_script.pory"
Std_RegisteredInMatchCall::
# 3 "data/scripts/trainer_script.pory"
	buffertrainerclassname 0, VAR_0x8000
# 4 "data/scripts/trainer_script.pory"
	buffertrainername 1, VAR_0x8000
# 5 "data/scripts/trainer_script.pory"
	closemessage
# 6 "data/scripts/trainer_script.pory"
	delay 30
# 7 "data/scripts/trainer_script.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 8 "data/scripts/trainer_script.pory"
	msgbox gText_RegisteredTrainerinPokeNav, MSGBOX_DEFAULT
# 9 "data/scripts/trainer_script.pory"
	waitfanfare
# 10 "data/scripts/trainer_script.pory"
	closemessage
# 11 "data/scripts/trainer_script.pory"
	delay 30
# 12 "data/scripts/trainer_script.pory"
	return
# 13 "data/scripts/trainer_script.pory"

# 14 "data/scripts/trainer_script.pory"
EventScript_TryGetTrainerScript::
# 15 "data/scripts/trainer_script.pory"
	special ShouldTryGetTrainerScript
# 16 "data/scripts/trainer_script.pory"
	compare VAR_RESULT, 1
# 17 "data/scripts/trainer_script.pory"
	goto_if_eq EventScript_GotoTrainerScript
# 18 "data/scripts/trainer_script.pory"
	releaseall
# 19 "data/scripts/trainer_script.pory"
	end
# 20 "data/scripts/trainer_script.pory"

# 21 "data/scripts/trainer_script.pory"
EventScript_GotoTrainerScript::
# 22 "data/scripts/trainer_script.pory"
	gotobeatenscript
# 23 "data/scripts/trainer_script.pory"
	releaseall
# 24 "data/scripts/trainer_script.pory"
	end
