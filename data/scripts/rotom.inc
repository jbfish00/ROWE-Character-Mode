# 1 "data/scripts/rotom.pory"

# 2 "data/scripts/rotom.pory"
@ Rotom form change script
# 3 "data/scripts/rotom.pory"
@ Vars used:
# 4 "data/scripts/rotom.pory"
@ gSpecialVar_0x8004: set to the party slot of the chosen Rotom, or the first Rotom found if there's only one
# 5 "data/scripts/rotom.pory"
@ gSpecialVar_0x8005: set to the form to change Rotom to (e.g. SPECIES_ROTOM_WASH)
# 6 "data/scripts/rotom.pory"
@ gSpecialVar_0x8006: special move learned by Rotom after form change (set by ChangeRotomForm)
# 7 "data/scripts/rotom.pory"
@ gSpecialVar_0x8007: Rotom's initial form
# 8 "data/scripts/rotom.pory"
@ gSpecialVar_0x8008: Rotom's initial special move (set by RotomForgetSpecialMove)
# 9 "data/scripts/rotom.pory"

# 10 "data/scripts/rotom.pory"
Rotom_Appliances_Main::
# 11 "data/scripts/rotom.pory"
	lockall
# 12 "data/scripts/rotom.pory"
	specialVar VAR_RESULT, CountRotomInParty
# 13 "data/scripts/rotom.pory"
	switch VAR_RESULT
# 14 "data/scripts/rotom.pory"
	case 0, Rotom_Appliances_NoRotomInParty
# 15 "data/scripts/rotom.pory"
	case 1, Rotom_Appliances_RotomInParty
# 16 "data/scripts/rotom.pory"
	goto Rotom_Appliances_WhichRotom
# 17 "data/scripts/rotom.pory"

# 18 "data/scripts/rotom.pory"
Rotom_Appliances_RotomInParty::
# 19 "data/scripts/rotom.pory"
	msgbox Rotom_Text_RotomWouldLikeToInvestigate, MSGBOX_YESNO
# 20 "data/scripts/rotom.pory"
	compare VAR_RESULT, NO
# 21 "data/scripts/rotom.pory"
	goto_if_eq Rotom_Appliances_Exit
# 22 "data/scripts/rotom.pory"
	goto Rotom_Appliances_Multichoice
# 23 "data/scripts/rotom.pory"

# 24 "data/scripts/rotom.pory"
Rotom_Appliances_WhichRotom::
# 25 "data/scripts/rotom.pory"
	msgbox Rotom_Text_RotomWouldLikeToInvestigate, MSGBOX_YESNO
# 26 "data/scripts/rotom.pory"
	compare VAR_RESULT, NO
# 27 "data/scripts/rotom.pory"
	goto_if_eq Rotom_Appliances_Exit
# 28 "data/scripts/rotom.pory"
	msgbox Rotom_Text_WhichRotom, MSGBOX_DEFAULT
# 29 "data/scripts/rotom.pory"
	special ChoosePartyMon
# 30 "data/scripts/rotom.pory"
	waitstate
# 31 "data/scripts/rotom.pory"
	compare VAR_0x8004, 255
# 32 "data/scripts/rotom.pory"
	goto_if_eq Rotom_Appliances_Exit
# 33 "data/scripts/rotom.pory"
	special IsSelectedMonEgg
# 34 "data/scripts/rotom.pory"
	compare VAR_RESULT, TRUE
# 35 "data/scripts/rotom.pory"
	goto_if_eq Rotom_Appliances_SelectedMonIsEgg
# 36 "data/scripts/rotom.pory"
	specialvar VAR_RESULT, IsSelectedMonRotom
# 37 "data/scripts/rotom.pory"
	compare VAR_RESULT, FALSE
# 38 "data/scripts/rotom.pory"
	goto_if_eq Rotom_Appliances_SelectedMonIsntRotom
# 39 "data/scripts/rotom.pory"
	compare VAR_0x8004, PARTY_SIZE
# 40 "data/scripts/rotom.pory"
	goto_if_ge Rotom_Appliances_Exit
# 41 "data/scripts/rotom.pory"
	goto Rotom_Appliances_Multichoice
# 42 "data/scripts/rotom.pory"

# 43 "data/scripts/rotom.pory"
Rotom_Appliances_Multichoice::
# 44 "data/scripts/rotom.pory"
	special GetRotomState
# 45 "data/scripts/rotom.pory"
	bufferpartymonnick 0, VAR_0x8004
# 46 "data/scripts/rotom.pory"
	msgbox Rotom_Text_WhichAppliancesMotor, MSGBOX_DEFAULT
# 47 "data/scripts/rotom.pory"
	waitmessage
# 48 "data/scripts/rotom.pory"
	multichoice 0, 0, MULTI_ROTOM_APPLIANCES, 0
# 49 "data/scripts/rotom.pory"
	switch VAR_RESULT
# 50 "data/scripts/rotom.pory"
	case 0, Rotom_Appliances_Heat
# 51 "data/scripts/rotom.pory"
	case 1, Rotom_Appliances_Wash
# 52 "data/scripts/rotom.pory"
	case 2, Rotom_Appliances_Frost
# 53 "data/scripts/rotom.pory"
	case 3, Rotom_Appliances_Fan
# 54 "data/scripts/rotom.pory"
	case 4, Rotom_Appliances_Mow
# 55 "data/scripts/rotom.pory"
	case 5, Rotom_Appliances_Recall
# 56 "data/scripts/rotom.pory"
	case MULTI_B_PRESSED, Rotom_Appliances_Exit
# 57 "data/scripts/rotom.pory"

# 58 "data/scripts/rotom.pory"
Rotom_Appliances_Heat::
# 59 "data/scripts/rotom.pory"
	setvar VAR_0x8005, SPECIES_ROTOM_HEAT
# 60 "data/scripts/rotom.pory"
	goto Rotom_Appliances_CheckForSpecialMove
# 61 "data/scripts/rotom.pory"

# 62 "data/scripts/rotom.pory"
Rotom_Appliances_Wash::
# 63 "data/scripts/rotom.pory"
	setvar VAR_0x8005, SPECIES_ROTOM_WASH
# 64 "data/scripts/rotom.pory"
	goto Rotom_Appliances_CheckForSpecialMove
# 65 "data/scripts/rotom.pory"

# 66 "data/scripts/rotom.pory"
Rotom_Appliances_Frost::
# 67 "data/scripts/rotom.pory"
	setvar VAR_0x8005, SPECIES_ROTOM_FROST
# 68 "data/scripts/rotom.pory"
	goto Rotom_Appliances_CheckForSpecialMove
# 69 "data/scripts/rotom.pory"

# 70 "data/scripts/rotom.pory"
Rotom_Appliances_Fan::
# 71 "data/scripts/rotom.pory"
	setvar VAR_0x8005, SPECIES_ROTOM_FAN
# 72 "data/scripts/rotom.pory"
	goto Rotom_Appliances_CheckForSpecialMove
# 73 "data/scripts/rotom.pory"

# 74 "data/scripts/rotom.pory"
Rotom_Appliances_Mow::
# 75 "data/scripts/rotom.pory"
	setvar VAR_0x8005, SPECIES_ROTOM_MOW
# 76 "data/scripts/rotom.pory"
	goto Rotom_Appliances_CheckForSpecialMove
# 77 "data/scripts/rotom.pory"

# 78 "data/scripts/rotom.pory"
Rotom_Appliances_Recall::
# 79 "data/scripts/rotom.pory"
	setvar VAR_0x8005, SPECIES_ROTOM
# 80 "data/scripts/rotom.pory"
	goto Rotom_Appliances_RecallFromMotor
# 81 "data/scripts/rotom.pory"

# 82 "data/scripts/rotom.pory"
Rotom_Appliances_CheckForSpecialMove::
# 83 "data/scripts/rotom.pory"
	compare VAR_0x8005, VAR_0x8007
# 84 "data/scripts/rotom.pory"
	goto_if_eq Rotom_Appliances_AlreadyEnteredThatMotor
# 85 "data/scripts/rotom.pory"
	special GetRotomNewSpecialMove
# 86 "data/scripts/rotom.pory"
	special ChangeRotomForm
# 87 "data/scripts/rotom.pory"
	msgbox Rotom_Text_EnteredTheMotor, MSGBOX_DEFAULT
# 88 "data/scripts/rotom.pory"
	specialVar VAR_RESULT, DoesRotomKnowSpecialMove
# 89 "data/scripts/rotom.pory"
	compare VAR_RESULT, TRUE
# 90 "data/scripts/rotom.pory"
	goto_if_eq Rotom_Appliances_DeleteSpecialMove
# 91 "data/scripts/rotom.pory"
	special GetNumMovesSelectedMonHas
# 92 "data/scripts/rotom.pory"
	compare VAR_RESULT, MAX_MON_MOVES
# 93 "data/scripts/rotom.pory"
	goto_if_eq Rotom_Appliances_ChooseMoveToForget
# 94 "data/scripts/rotom.pory"
	goto Rotom_Appliances_LearnSpecialMove
# 95 "data/scripts/rotom.pory"

# 96 "data/scripts/rotom.pory"
Rotom_Appliances_DeleteSpecialMove::
# 97 "data/scripts/rotom.pory"
	special RotomForgetSpecialMove
# 98 "data/scripts/rotom.pory"
	bufferpartymonnick 0, VAR_0x8004
# 99 "data/scripts/rotom.pory"
	buffermovename 1, VAR_0x8008
# 100 "data/scripts/rotom.pory"
	msgbox Rotom_Text_RotomForgotMove, MSGBOX_DEFAULT
# 101 "data/scripts/rotom.pory"
	goto Rotom_Appliances_LearnSpecialMove
# 102 "data/scripts/rotom.pory"

# 103 "data/scripts/rotom.pory"
Rotom_Appliances_ChooseMoveToForget::
# 104 "data/scripts/rotom.pory"
	buffermovename 1, VAR_0x8006
# 105 "data/scripts/rotom.pory"
	msgbox Rotom_Text_TryLearnSpecialMove, MSGBOX_YESNO
# 106 "data/scripts/rotom.pory"
	compare VAR_RESULT, NO
# 107 "data/scripts/rotom.pory"
	goto_if_eq Rotom_Appliances_GaveUpOnEnteringMotor
# 108 "data/scripts/rotom.pory"
	msgbox Rotom_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
# 109 "data/scripts/rotom.pory"
	fadescreen FADE_TO_BLACK
# 110 "data/scripts/rotom.pory"
	special MoveDeleterChooseMoveToForget
# 111 "data/scripts/rotom.pory"
	fadescreen FADE_FROM_BLACK
# 112 "data/scripts/rotom.pory"
	compare VAR_0x8005, MAX_MON_MOVES
# 113 "data/scripts/rotom.pory"
	goto_if_eq Rotom_Appliances_GaveUpOnEnteringMotor
# 114 "data/scripts/rotom.pory"
	special BufferMoveDeleterNicknameAndMove
# 115 "data/scripts/rotom.pory"
	msgbox Rotom_Text_RotomForgotMove, MSGBOX_DEFAULT
# 116 "data/scripts/rotom.pory"
	special MoveDeleterForgetMove
# 117 "data/scripts/rotom.pory"
	goto Rotom_Appliances_LearnSpecialMove
# 118 "data/scripts/rotom.pory"

# 119 "data/scripts/rotom.pory"
Rotom_Appliances_LearnSpecialMove::
# 120 "data/scripts/rotom.pory"
	special TeachRotomMove
# 121 "data/scripts/rotom.pory"
	bufferpartymonnick 0, VAR_0x8004
# 122 "data/scripts/rotom.pory"
	buffermovename 1, VAR_0x8006
# 123 "data/scripts/rotom.pory"
	playfanfare MUS_LEVEL_UP
# 124 "data/scripts/rotom.pory"
	msgbox Rotom_Text_LearnedMove, MSGBOX_DEFAULT
# 125 "data/scripts/rotom.pory"
	releaseall
# 126 "data/scripts/rotom.pory"
	end
# 127 "data/scripts/rotom.pory"

# 128 "data/scripts/rotom.pory"
Rotom_Appliances_RecallFromMotor::
# 129 "data/scripts/rotom.pory"
	compare VAR_0x8007, SPECIES_ROTOM
# 130 "data/scripts/rotom.pory"
	goto_if_eq Rotom_Appliances_RotomHasntEnteredMotor
# 131 "data/scripts/rotom.pory"
	special GetRotomNewSpecialMove
# 132 "data/scripts/rotom.pory"
	special ChangeRotomForm
# 133 "data/scripts/rotom.pory"
	msgbox Rotom_Text_EmergedFromTheMotor, MSGBOX_DEFAULT
# 134 "data/scripts/rotom.pory"
	specialVar VAR_RESULT, DoesRotomKnowSpecialMove
# 135 "data/scripts/rotom.pory"
	compare VAR_RESULT, TRUE
# 136 "data/scripts/rotom.pory"
	goto_if_eq Rotom_Appliances_DeleteSpecialMove
# 137 "data/scripts/rotom.pory"
	releaseall
# 138 "data/scripts/rotom.pory"
	end
# 139 "data/scripts/rotom.pory"

# 140 "data/scripts/rotom.pory"
Rotom_Appliances_AlreadyEnteredThatMotor::
# 141 "data/scripts/rotom.pory"
	msgbox Rotom_Text_AlreadyEnteredTheMotor, MSGBOX_DEFAULT
# 142 "data/scripts/rotom.pory"
	releaseall
# 143 "data/scripts/rotom.pory"
	end
# 144 "data/scripts/rotom.pory"

# 145 "data/scripts/rotom.pory"
Rotom_Appliances_SelectedMonIsEgg::
# 146 "data/scripts/rotom.pory"
	msgbox Rotom_Text_EggCantEnterMotor, MSGBOX_DEFAULT
# 147 "data/scripts/rotom.pory"
	releaseall
# 148 "data/scripts/rotom.pory"
	end
# 149 "data/scripts/rotom.pory"

# 150 "data/scripts/rotom.pory"
Rotom_Appliances_SelectedMonIsntRotom::
# 151 "data/scripts/rotom.pory"
	msgbox Rotom_Text_CantEnterMotor, MSGBOX_DEFAULT
# 152 "data/scripts/rotom.pory"
	releaseall
# 153 "data/scripts/rotom.pory"
	end
# 154 "data/scripts/rotom.pory"

# 155 "data/scripts/rotom.pory"
Rotom_Appliances_NoRotomInParty::
# 156 "data/scripts/rotom.pory"
	msgbox Rotom_Text_ItsFullOfCarboardBoxes, MSGBOX_DEFAULT
# 157 "data/scripts/rotom.pory"
	releaseall
# 158 "data/scripts/rotom.pory"
	end
# 159 "data/scripts/rotom.pory"

# 160 "data/scripts/rotom.pory"
Rotom_Appliances_GaveUpOnEnteringMotor::
# 161 "data/scripts/rotom.pory"
	copyvar VAR_0x8005, VAR_0x8007
# 162 "data/scripts/rotom.pory"
	special ChangeRotomForm
# 163 "data/scripts/rotom.pory"
	msgbox Rotom_Text_NicknameReluctantlyGaveUp, MSGBOX_DEFAULT
# 164 "data/scripts/rotom.pory"
	releaseall
# 165 "data/scripts/rotom.pory"
	end
# 166 "data/scripts/rotom.pory"

# 167 "data/scripts/rotom.pory"
Rotom_Appliances_RotomHasntEnteredMotor::
# 168 "data/scripts/rotom.pory"
	msgbox Rotom_Text_HasntEnteredAMotor, MSGBOX_DEFAULT
# 169 "data/scripts/rotom.pory"
	releaseall
# 170 "data/scripts/rotom.pory"
	end
# 171 "data/scripts/rotom.pory"

# 172 "data/scripts/rotom.pory"
Rotom_Appliances_Exit::
# 173 "data/scripts/rotom.pory"
	releaseall
# 174 "data/scripts/rotom.pory"
	end

Rotom_Text_ItsFullOfCarboardBoxes::
# 177 "data/scripts/rotom.pory"
	.string "It's full of cardboard boxes with\n"
	.string "electrical appliances in them.$"

Rotom_Text_RotomWouldLikeToInvestigate::
# 182 "data/scripts/rotom.pory"
	.string "It's full of cardboard boxes with\n"
	.string "electrical appliances in them.\p"
	.string "Oh?\p"
	.string "Rotom would like to investigate the\n"
	.string "motors of the electrical appliances…\l"
	.string "Is that OK?$"

Rotom_Text_RotomReluctantlyGaveUp::
# 191 "data/scripts/rotom.pory"
	.string "Rotom reluctantly gave up on entering\n"
	.string "a motor…$"

Rotom_Text_NicknameReluctantlyGaveUp::
# 196 "data/scripts/rotom.pory"
	.string "{STR_VAR_1} reluctantly gave up on\n"
	.string "entering a motor…$"

Rotom_Text_WhichRotom::
# 201 "data/scripts/rotom.pory"
	.string "Which Rotom will you allow to enter\n"
	.string "a motor?$"

Rotom_Text_CantEnterMotor::
# 206 "data/scripts/rotom.pory"
	.string "That Pokémon can't enter a motor.$"

Rotom_Text_EggCantEnterMotor::
# 210 "data/scripts/rotom.pory"
	.string "An Egg can't enter a motor.$"

Rotom_Text_WhichAppliancesMotor::
# 214 "data/scripts/rotom.pory"
	.string "Which appliance's motor will you\n"
	.string "allow {STR_VAR_1} to enter?$"

Rotom_Text_EnteredTheMotor::
# 219 "data/scripts/rotom.pory"
	.string "{STR_VAR_1} entered the motor.$"

Rotom_Text_TryLearnSpecialMove::
# 223 "data/scripts/rotom.pory"
	.string "{STR_VAR_1} is trying to learn\n{STR_VAR_2}.\p"
	.string "But {STR_VAR_1} can't learn more\n"
	.string "than four moves.\p"
	.string "Delete an older move to make\n"
	.string "room for {STR_VAR_2}?$"

Rotom_Text_AlreadyEnteredTheMotor::
# 231 "data/scripts/rotom.pory"
	.string "{STR_VAR_1} has already entered that\n"
	.string "appliance motor.$"

Rotom_Text_EmergedFromTheMotor::
# 236 "data/scripts/rotom.pory"
	.string "{STR_VAR_1} emerged from the motor.$"

Rotom_Text_HasntEnteredAMotor::
# 240 "data/scripts/rotom.pory"
	.string "{STR_VAR_1} hasn't entered a motor.$"

Rotom_Text_RotomForgotMove::
# 244 "data/scripts/rotom.pory"
	.string "{PAUSE 32}1, {PAUSE 15}2, and {PAUSE 15}… {PAUSE 15}… {PAUSE 15}… {PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}Poof!\p"
	.string "{STR_VAR_1} forgot how to use\n"
	.string "{STR_VAR_2}.\p"
	.string "And…$"

Rotom_Text_LearnedMove::
# 251 "data/scripts/rotom.pory"
	.string "{STR_VAR_1} learned {STR_VAR_2}!{WAIT_SE}$"

Rotom_Text_WhichMoveShouldBeForgotten::
# 255 "data/scripts/rotom.pory"
	.string "Which move should be forgotten?$"
