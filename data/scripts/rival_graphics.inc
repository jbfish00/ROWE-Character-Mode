# 1 "data/scripts/rival_graphics.pory"

# 2 "data/scripts/rival_graphics.pory"
Common_EventScript_SetupRivalGfxId::
# 3 "data/scripts/rival_graphics.pory"
	checkplayergender
# 4 "data/scripts/rival_graphics.pory"
	compare VAR_RESULT, MALE
# 5 "data/scripts/rival_graphics.pory"
	goto_if_eq EventScript_SetupRivalGfxIdFemale
# 6 "data/scripts/rival_graphics.pory"
	compare VAR_RESULT, FEMALE
# 7 "data/scripts/rival_graphics.pory"
	goto_if_eq EventScript_SetupRivalGfxIdMale
# 8 "data/scripts/rival_graphics.pory"
	end
# 9 "data/scripts/rival_graphics.pory"

# 10 "data/scripts/rival_graphics.pory"
EventScript_SetupRivalGfxIdFemale::
# 11 "data/scripts/rival_graphics.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 12 "data/scripts/rival_graphics.pory"
	return
# 13 "data/scripts/rival_graphics.pory"

# 14 "data/scripts/rival_graphics.pory"
EventScript_SetupRivalGfxIdMale::
# 15 "data/scripts/rival_graphics.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 16 "data/scripts/rival_graphics.pory"
	return
# 17 "data/scripts/rival_graphics.pory"

# 18 "data/scripts/rival_graphics.pory"
Common_EventScript_SetupRivalOnBikeGfxId::
# 19 "data/scripts/rival_graphics.pory"
	checkplayergender
# 20 "data/scripts/rival_graphics.pory"
	compare VAR_RESULT, MALE
# 21 "data/scripts/rival_graphics.pory"
	goto_if_eq EventScript_SetupRivalOnBikeGfxIdFemale
# 22 "data/scripts/rival_graphics.pory"
	compare VAR_RESULT, FEMALE
# 23 "data/scripts/rival_graphics.pory"
	goto_if_eq EventScript_SetupRivalOnBikeGfxIdMale
# 24 "data/scripts/rival_graphics.pory"
	end
# 25 "data/scripts/rival_graphics.pory"

# 26 "data/scripts/rival_graphics.pory"
EventScript_SetupRivalOnBikeGfxIdFemale::
# 27 "data/scripts/rival_graphics.pory"
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_MAY_MACH_BIKE
# 28 "data/scripts/rival_graphics.pory"
	return
# 29 "data/scripts/rival_graphics.pory"

# 30 "data/scripts/rival_graphics.pory"
EventScript_SetupRivalOnBikeGfxIdMale::
# 31 "data/scripts/rival_graphics.pory"
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_BRENDAN_MACH_BIKE
# 32 "data/scripts/rival_graphics.pory"
	return
# 33 "data/scripts/rival_graphics.pory"

# 34 "data/scripts/rival_graphics.pory"
Common_EventScript_SetupRivalGfxIdSameGender::
# 35 "data/scripts/rival_graphics.pory"
	checkplayergender
# 36 "data/scripts/rival_graphics.pory"
	compare VAR_RESULT, MALE
# 37 "data/scripts/rival_graphics.pory"
	goto_if_eq EventScript_SetupRivalGfxIdMale2
# 38 "data/scripts/rival_graphics.pory"
	compare VAR_RESULT, FEMALE
# 39 "data/scripts/rival_graphics.pory"
	goto_if_eq EventScript_SetupRivalGfxIdFemale2
# 40 "data/scripts/rival_graphics.pory"
	end
# 41 "data/scripts/rival_graphics.pory"

# 42 "data/scripts/rival_graphics.pory"
EventScript_SetupRivalGfxIdMale2::
# 43 "data/scripts/rival_graphics.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
# 44 "data/scripts/rival_graphics.pory"
	return
# 45 "data/scripts/rival_graphics.pory"

# 46 "data/scripts/rival_graphics.pory"
EventScript_SetupRivalGfxIdFemale2::
# 47 "data/scripts/rival_graphics.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
# 48 "data/scripts/rival_graphics.pory"
	return
