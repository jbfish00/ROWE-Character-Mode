CaveOfOrigin_EventScript_LegendaryCry::
# 2 "data/scripts/cave_of_origin.pory"
	lockall
# 3 "data/scripts/cave_of_origin.pory"
	waitse
# 4 "data/scripts/cave_of_origin.pory"
	playmoncry SPECIES_KYOGRE, 2
# 5 "data/scripts/cave_of_origin.pory"
	waitmoncry
# 6 "data/scripts/cave_of_origin.pory"
	setvar VAR_TEMP_5, 1
# 7 "data/scripts/cave_of_origin.pory"
	releaseall
	return


CaveOfOrigin_EventScript_Shake1::
# 11 "data/scripts/cave_of_origin.pory"
	lockall
# 12 "data/scripts/cave_of_origin.pory"
	setvar VAR_TEMP_1, 1
# 13 "data/scripts/cave_of_origin.pory"
	goto CaveOfOrigin_EventScript_Shake
	return


CaveOfOrigin_EventScript_Shake2::
# 17 "data/scripts/cave_of_origin.pory"
	lockall
# 18 "data/scripts/cave_of_origin.pory"
	setvar VAR_TEMP_2, 1
# 19 "data/scripts/cave_of_origin.pory"
	goto CaveOfOrigin_EventScript_Shake
	return


CaveOfOrigin_EventScript_Shake3::
# 23 "data/scripts/cave_of_origin.pory"
	lockall
# 24 "data/scripts/cave_of_origin.pory"
	setvar VAR_TEMP_3, 1
# 25 "data/scripts/cave_of_origin.pory"
	goto CaveOfOrigin_EventScript_Shake
	return


CaveOfOrigin_EventScript_Shake::
# 29 "data/scripts/cave_of_origin.pory"
	setvar VAR_0x8004, 1
# 30 "data/scripts/cave_of_origin.pory"
	setvar VAR_0x8005, 1
# 31 "data/scripts/cave_of_origin.pory"
	setvar VAR_0x8006, 8
# 32 "data/scripts/cave_of_origin.pory"
	setvar VAR_0x8007, 5
# 33 "data/scripts/cave_of_origin.pory"
	special ShakeCamera
# 34 "data/scripts/cave_of_origin.pory"
	waitstate
# 35 "data/scripts/cave_of_origin.pory"
	releaseall
	return


CaveOfOrigin_EventScript_SetTempVars::
# 39 "data/scripts/cave_of_origin.pory"
	setvar VAR_TEMP_1, 1
# 40 "data/scripts/cave_of_origin.pory"
	setvar VAR_TEMP_2, 1
# 41 "data/scripts/cave_of_origin.pory"
	setvar VAR_TEMP_3, 1
# 42 "data/scripts/cave_of_origin.pory"
	setvar VAR_TEMP_4, 1
# 43 "data/scripts/cave_of_origin.pory"
	setvar VAR_TEMP_5, 1
	return

