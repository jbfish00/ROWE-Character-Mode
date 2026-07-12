# 1 "data/scripts/trainer_battle.pory"

# 2 "data/scripts/trainer_battle.pory"
EventScript_271354::
# 3 "data/scripts/trainer_battle.pory"
	cmdD8
# 4 "data/scripts/trainer_battle.pory"
	cmdD9
# 5 "data/scripts/trainer_battle.pory"

# 6 "data/scripts/trainer_battle.pory"
EventScript_ShowSecondTrainerIntro::
# 7 "data/scripts/trainer_battle.pory"
	special SetUpTrainerEncounterMusic
# 8 "data/scripts/trainer_battle.pory"
	special EndTrainerApproach
# 9 "data/scripts/trainer_battle.pory"
	waitstate
# 10 "data/scripts/trainer_battle.pory"
	goto EventScript_ShowTrainerIntroMsg
# 11 "data/scripts/trainer_battle.pory"

# 12 "data/scripts/trainer_battle.pory"
EventScript_TryDoNormalTrainerBattle::
# 13 "data/scripts/trainer_battle.pory"
	lock
# 14 "data/scripts/trainer_battle.pory"
	faceplayer
# 15 "data/scripts/trainer_battle.pory"
	applymovement VAR_LAST_TALKED, Movement_RevealTrainer
# 16 "data/scripts/trainer_battle.pory"
	waitmovement 0
# 17 "data/scripts/trainer_battle.pory"
	specialvar VAR_RESULT, GetTrainerFlag
# 18 "data/scripts/trainer_battle.pory"
	compare VAR_RESULT, 0
# 19 "data/scripts/trainer_battle.pory"
	goto_if_ne EventScript_NoNormalTrainerBattle
# 20 "data/scripts/trainer_battle.pory"
	special SetUpTrainerEncounterMusic
# 21 "data/scripts/trainer_battle.pory"
	special SetUpTrainerMovement
# 22 "data/scripts/trainer_battle.pory"
	goto EventScript_ShowTrainerIntroMsg
# 23 "data/scripts/trainer_battle.pory"
EventScript_NoNormalTrainerBattle::
# 24 "data/scripts/trainer_battle.pory"
	gotopostbattlescript
# 25 "data/scripts/trainer_battle.pory"

# 26 "data/scripts/trainer_battle.pory"
EventScript_TryDoDoubleTrainerBattle::
# 27 "data/scripts/trainer_battle.pory"
	lock
# 28 "data/scripts/trainer_battle.pory"
	faceplayer
# 29 "data/scripts/trainer_battle.pory"
	call EventScript_RevealTrainer
# 30 "data/scripts/trainer_battle.pory"
	specialvar VAR_RESULT, GetTrainerFlag
# 31 "data/scripts/trainer_battle.pory"
	compare VAR_RESULT, 0
# 32 "data/scripts/trainer_battle.pory"
	goto_if_ne EventScript_NoDoubleTrainerBattle
# 33 "data/scripts/trainer_battle.pory"
	special HasEnoughMonsForDoubleBattle
# 34 "data/scripts/trainer_battle.pory"
	compare VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS
# 35 "data/scripts/trainer_battle.pory"
	goto_if_ne EventScript_NotEnoughMonsForDoubleBattle
# 36 "data/scripts/trainer_battle.pory"
	special SetUpTrainerEncounterMusic
# 37 "data/scripts/trainer_battle.pory"
	special SetUpTrainerMovement
# 38 "data/scripts/trainer_battle.pory"
	goto EventScript_ShowTrainerIntroMsg
# 39 "data/scripts/trainer_battle.pory"
EventScript_NotEnoughMonsForDoubleBattle::
# 40 "data/scripts/trainer_battle.pory"
	special ShowTrainerCantBattleSpeech
# 41 "data/scripts/trainer_battle.pory"
	waitmessage
# 42 "data/scripts/trainer_battle.pory"
	waitbuttonpress
# 43 "data/scripts/trainer_battle.pory"
	release
# 44 "data/scripts/trainer_battle.pory"
	end
# 45 "data/scripts/trainer_battle.pory"
EventScript_NoDoubleTrainerBattle::
# 46 "data/scripts/trainer_battle.pory"
	gotopostbattlescript
# 47 "data/scripts/trainer_battle.pory"

# 48 "data/scripts/trainer_battle.pory"
EventScript_DoNoIntroTrainerBattle::
# 49 "data/scripts/trainer_battle.pory"
	applymovement VAR_LAST_TALKED, Movement_RevealTrainer
# 50 "data/scripts/trainer_battle.pory"
	waitmovement 0
# 51 "data/scripts/trainer_battle.pory"
	special SetUpTrainerEncounterMusic
# 52 "data/scripts/trainer_battle.pory"
	trainerbattlebegin
# 53 "data/scripts/trainer_battle.pory"
	gotopostbattlescript
# 54 "data/scripts/trainer_battle.pory"

# 55 "data/scripts/trainer_battle.pory"
EventScript_TryDoRematchBattle::
# 56 "data/scripts/trainer_battle.pory"
	call EventScript_RevealTrainer
# 57 "data/scripts/trainer_battle.pory"
	specialvar VAR_RESULT, IsTrainerReadyForRematch
# 58 "data/scripts/trainer_battle.pory"
	compare VAR_RESULT, FALSE
# 59 "data/scripts/trainer_battle.pory"
	goto_if_eq EventScript_NoRematchTrainerBattle
# 60 "data/scripts/trainer_battle.pory"
	special SetUpTrainerEncounterMusic
# 61 "data/scripts/trainer_battle.pory"
	special SetUpTrainerMovement
# 62 "data/scripts/trainer_battle.pory"
	special ShowTrainerIntroSpeech
# 63 "data/scripts/trainer_battle.pory"
	waitmessage
# 64 "data/scripts/trainer_battle.pory"
	waitbuttonpress
# 65 "data/scripts/trainer_battle.pory"
	special BattleSetup_StartRematchBattle
# 66 "data/scripts/trainer_battle.pory"
	waitstate
# 67 "data/scripts/trainer_battle.pory"
	releaseall
# 68 "data/scripts/trainer_battle.pory"
	end
# 69 "data/scripts/trainer_battle.pory"
EventScript_NoRematchTrainerBattle::
# 70 "data/scripts/trainer_battle.pory"
	gotopostbattlescript
# 71 "data/scripts/trainer_battle.pory"

# 72 "data/scripts/trainer_battle.pory"
EventScript_TryDoDoubleRematchBattle::
# 73 "data/scripts/trainer_battle.pory"
	specialvar VAR_RESULT, IsTrainerReadyForRematch
# 74 "data/scripts/trainer_battle.pory"
	compare VAR_RESULT, FALSE
# 75 "data/scripts/trainer_battle.pory"
	goto_if_eq EventScript_NoDoubleRematchTrainerBattle
# 76 "data/scripts/trainer_battle.pory"
	special HasEnoughMonsForDoubleBattle
# 77 "data/scripts/trainer_battle.pory"
	compare VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS
# 78 "data/scripts/trainer_battle.pory"
	goto_if_ne EventScript_NotEnoughMonsForDoubleRematchBattle
# 79 "data/scripts/trainer_battle.pory"
	special SetUpTrainerEncounterMusic
# 80 "data/scripts/trainer_battle.pory"
	special SetUpTrainerMovement
# 81 "data/scripts/trainer_battle.pory"
	special ShowTrainerIntroSpeech
# 82 "data/scripts/trainer_battle.pory"
	waitmessage
# 83 "data/scripts/trainer_battle.pory"
	waitbuttonpress
# 84 "data/scripts/trainer_battle.pory"
	special BattleSetup_StartRematchBattle
# 85 "data/scripts/trainer_battle.pory"
	waitstate
# 86 "data/scripts/trainer_battle.pory"
	releaseall
# 87 "data/scripts/trainer_battle.pory"
	end
# 88 "data/scripts/trainer_battle.pory"
EventScript_NoDoubleRematchTrainerBattle::
# 89 "data/scripts/trainer_battle.pory"
	gotopostbattlescript
# 90 "data/scripts/trainer_battle.pory"
EventScript_NotEnoughMonsForDoubleRematchBattle::
# 91 "data/scripts/trainer_battle.pory"
	special ShowTrainerCantBattleSpeech
# 92 "data/scripts/trainer_battle.pory"
	waitmessage
# 93 "data/scripts/trainer_battle.pory"
	waitbuttonpress
# 94 "data/scripts/trainer_battle.pory"
	release
# 95 "data/scripts/trainer_battle.pory"
	end
# 96 "data/scripts/trainer_battle.pory"

# 97 "data/scripts/trainer_battle.pory"
EventScript_RevealTrainer::
# 98 "data/scripts/trainer_battle.pory"
	applymovement VAR_LAST_TALKED, Movement_RevealTrainer
# 99 "data/scripts/trainer_battle.pory"
	waitmovement 0
# 100 "data/scripts/trainer_battle.pory"
	return

# 103 "data/scripts/trainer_battle.pory"
Movement_RevealTrainer:
# 104 "data/scripts/trainer_battle.pory"
	reveal_trainer
	step_end

# 107 "data/scripts/trainer_battle.pory"

# 108 "data/scripts/trainer_battle.pory"
EventScript_ShowTrainerIntroMsg::
# 109 "data/scripts/trainer_battle.pory"
	special ShowTrainerIntroSpeech
# 110 "data/scripts/trainer_battle.pory"
	waitmessage
# 111 "data/scripts/trainer_battle.pory"
	waitbuttonpress
# 112 "data/scripts/trainer_battle.pory"
	special TryPrepareSecondApproachingTrainer
# 113 "data/scripts/trainer_battle.pory"
	compare VAR_RESULT, TRUE
# 114 "data/scripts/trainer_battle.pory"
	goto_if_eq EventScript_ShowSecondTrainerIntro
# 115 "data/scripts/trainer_battle.pory"
	goto EventScript_DoTrainerBattle
# 116 "data/scripts/trainer_battle.pory"

# 117 "data/scripts/trainer_battle.pory"
EventScript_DoTrainerBattle::
# 118 "data/scripts/trainer_battle.pory"
	trainerbattlebegin
# 119 "data/scripts/trainer_battle.pory"
	specialvar VAR_RESULT, GetTrainerBattleMode
# 120 "data/scripts/trainer_battle.pory"
	compare VAR_RESULT, TRAINER_BATTLE_SINGLE
# 121 "data/scripts/trainer_battle.pory"
	goto_if_eq EventScript_EndTrainerBattle
# 122 "data/scripts/trainer_battle.pory"
	compare VAR_RESULT, TRAINER_BATTLE_CONTINUE_SCRIPT
# 123 "data/scripts/trainer_battle.pory"
	goto_if_eq EventScript_EndTrainerBattle
# 124 "data/scripts/trainer_battle.pory"
	compare VAR_RESULT, TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC
# 125 "data/scripts/trainer_battle.pory"
	goto_if_eq EventScript_EndTrainerBattle
# 126 "data/scripts/trainer_battle.pory"
	compare VAR_RESULT, TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE
# 127 "data/scripts/trainer_battle.pory"
	goto_if_eq EventScript_EndTrainerBattle
# 128 "data/scripts/trainer_battle.pory"
	compare VAR_RESULT, TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC
# 129 "data/scripts/trainer_battle.pory"
	goto_if_eq EventScript_EndTrainerBattle
# 130 "data/scripts/trainer_battle.pory"
EventScript_EndTrainerBattle::
# 131 "data/scripts/trainer_battle.pory"
	gotobeatenscript
# 132 "data/scripts/trainer_battle.pory"
	releaseall
# 133 "data/scripts/trainer_battle.pory"
	end
# 134 "data/scripts/trainer_battle.pory"

# 135 "data/scripts/trainer_battle.pory"
Std_MsgboxAutoclose::
# 136 "data/scripts/trainer_battle.pory"
	message 0x0
# 137 "data/scripts/trainer_battle.pory"
	waitmessage
# 138 "data/scripts/trainer_battle.pory"
	waitbuttonpress
# 139 "data/scripts/trainer_battle.pory"
	release
# 140 "data/scripts/trainer_battle.pory"
	return
