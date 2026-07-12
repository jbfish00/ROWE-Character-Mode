# 1 "data/scripts/cave_hole.pory"

# 2 "data/scripts/cave_hole.pory"
CaveHole_CheckFallDownHole:
# 3 "data/scripts/cave_hole.pory"
	map_script_2 VAR_ICE_STEP_COUNT, 0, EventScript_FallDownHole
# 4 "data/scripts/cave_hole.pory"
	.2byte 0
# 5 "data/scripts/cave_hole.pory"

# 6 "data/scripts/cave_hole.pory"
CaveHole_FixCrackedGround:
# 7 "data/scripts/cave_hole.pory"
	copyvar VAR_ICE_STEP_COUNT, 1
# 8 "data/scripts/cave_hole.pory"
	end

# 11 "data/scripts/cave_hole.pory"

# 12 "data/scripts/cave_hole.pory"
EventScript_FallDownHole::
# 13 "data/scripts/cave_hole.pory"
	lockall
# 14 "data/scripts/cave_hole.pory"
	delay 20
# 15 "data/scripts/cave_hole.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
# 16 "data/scripts/cave_hole.pory"
	waitmovement 0
# 17 "data/scripts/cave_hole.pory"
	playse SE_FALL
# 18 "data/scripts/cave_hole.pory"
	delay 60
# 19 "data/scripts/cave_hole.pory"
	warphole MAP_UNDEFINED
# 20 "data/scripts/cave_hole.pory"
	waitstate
# 21 "data/scripts/cave_hole.pory"
	end

# 24 "data/scripts/cave_hole.pory"

# 25 "data/scripts/cave_hole.pory"
EventScript_FallDownHoleMtPyre::
# 26 "data/scripts/cave_hole.pory"
	lockall
# 27 "data/scripts/cave_hole.pory"
	delay 20
# 28 "data/scripts/cave_hole.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
# 29 "data/scripts/cave_hole.pory"
	waitmovement 0
# 30 "data/scripts/cave_hole.pory"
	playse SE_FALL
# 31 "data/scripts/cave_hole.pory"
	delay 60
# 32 "data/scripts/cave_hole.pory"
	special DoFallWarp
# 33 "data/scripts/cave_hole.pory"
	waitstate
# 34 "data/scripts/cave_hole.pory"
	end

# 37 "data/scripts/cave_hole.pory"
Movement_SetInvisible:
# 38 "data/scripts/cave_hole.pory"
	set_invisible
# 39 "data/scripts/cave_hole.pory"
	step_end
