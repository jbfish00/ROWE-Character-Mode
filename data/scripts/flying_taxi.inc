Common_EventScript_FlyingTaxi::
    lock
    faceplayer
    setvar VAR_0x800A, LAST_TALKED_TO_FLYING_TAXI
    msgbox gText_FlyingTaxi_Intro, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_FlyingTaxi_ChooseDestination
    compare VAR_RESULT, NO
    goto_if_eq EventScript_FlyingTaxi_Goodbye
    end

EventScript_FlyingTaxi_ChooseDestination::
    special FieldLoadFlyMap
    goto EventScript_FlyingTaxi_Goodbye
    end

EventScript_FlyingTaxi_Goodbye::
    message gText_WeHopeToSeeYouAgain
    setvar VAR_LAST_TALKED, 0
    releaseall
    return
	
//Gym Items
// 2.X: 16 badges (8 Hoenn + the 8 Johto leaders on the Sevii Islands), each
// with its own reward. The Mega Bracelet is the 11th, not the 7th -- the mega
// stone gurus in gym_scripts.inc all gate on `compare VAR_NUM_BADGES, 11`.
//
// Slots 9-16 follow 2.X. Slots 1-6 keep the 1.9.4 items rather than 2.X's:
// 2.X hands out HM-replacement tools there (Axe, Waterfall Tool, ...), which
// only make sense once the tool-based field-move system is ported. Those items
// exist in our tree but are still fieldUseFunc = CannotUse, so giving them here
// would replace working rewards with dead ones. Revisit when that system lands.
// Dispatch on VAR_NUM_BADGES, not on the badge flags -- this is what 2.X does,
// and it is load-bearing. The 8 Johto leaders each `setflag FLAG_RECEIVED_BADGE_NN`
// *before* calling here (Hoenn's leaders do not), so a flag-keyed chain would
// see the badge already set, skip its reward, and hand out the next slot's item
// instead. VAR_NUM_BADGES is the count of rewards handed out, so it stays correct
// either way.
Special_Gym_EventScript_Give_Item::
	setflag (FLAG_GYM_ATTENDANT_CALL)
	switch VAR_NUM_BADGES
	case  0, Special_Gym_EventScript_Amulet_Coin
	case  1, Special_Gym_EventScript_Item_Finder
	case  2, Special_Gym_EventScript_Good_Rod
	case  3, Special_Gym_EventScript_Catching_Charm
	case  4, Special_Gym_EventScript_Super_Rod
	case  5, Special_Gym_EventScript_Lucky_Egg
	case  6, Special_Gym_EventScript_Exp_Charm
	case  7, Special_Gym_EventScript_Oval_Charm
	case  8, Special_Gym_EventScript_Fly_Charm
	case  9, Special_Gym_EventScript_Fly_Tool
	case 10, Special_Gym_EventScript_Mega_Bracelet
	case 11, Special_Gym_EventScript_Effort_Tool
	case 12, Special_Gym_EventScript_Alpha_Charm
	case 13, Special_Gym_EventScript_Wonder_Charm
	case 14, Special_Gym_EventScript_Master_Ball
	case 15, Special_Gym_EventScript_Shiny_Charm
	return

Special_Gym_EventScript_Amulet_Coin::
	giveitem ITEM_AMULET_COIN
	msgbox   Special_Gym_Text_Explain_Amulet_Coin, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_01
	setvar   VAR_NUM_BADGES, 1
	return
	end
	
Special_Gym_EventScript_Item_Finder::
	giveitem ITEM_ITEMFINDER
	msgbox   Special_Gym_Text_Explain_Item_Finder, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_02
	setvar   VAR_NUM_BADGES, 2
	return
	end
	
Special_Gym_EventScript_Good_Rod::
	giveitem ITEM_GOOD_ROD
	msgbox   Special_Gym_Text_Explain_Good_Rod, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_03
	setvar   VAR_NUM_BADGES, 3
	return
	end
	
Special_Gym_EventScript_Catching_Charm::
	giveitem ITEM_CATCHING_CHARM
	msgbox   Special_Gym_Text_Explain_Catching_Charm, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_04
	setvar   VAR_NUM_BADGES, 4
	return
	end
	
Special_Gym_EventScript_Super_Rod::
	giveitem ITEM_SUPER_ROD
	msgbox   Special_Gym_Text_Explain_Super_Rod, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_05
	setvar   VAR_NUM_BADGES, 5
	return
	end
	
Special_Gym_EventScript_Lucky_Egg::
	giveitem ITEM_LUCKY_EGG
	msgbox   Special_Gym_Text_Explain_Lucky_Egg, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_06
	setvar   VAR_NUM_BADGES, 6
	return
	end
	
Special_Gym_EventScript_Exp_Charm::
	giveitem ITEM_EXP_CHARM
	msgbox   Special_Gym_Text_Explain_Exp_Charm, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_07
	setvar   VAR_NUM_BADGES, 7
	return
	end

Special_Gym_EventScript_Oval_Charm::
	giveitem ITEM_OVAL_CHARM
	msgbox   Special_Gym_Text_Explain_Oval_Charm, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_08
	setvar   VAR_NUM_BADGES, 8
	return
	end

// ---- Johto gyms on the Sevii Islands (badges 9-16) ----
Special_Gym_EventScript_Fly_Charm::
	giveitem ITEM_FLY_CHARM
	msgbox   Special_Gym_Text_Explain_Fly_Charm, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_09
	setvar   VAR_NUM_BADGES, 9
	return
	end

Special_Gym_EventScript_Fly_Tool::
	giveitem ITEM_FLY_TOOL
	msgbox   Special_Gym_Text_Explain_Fly_Tool, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_10
	setvar   VAR_NUM_BADGES, 10
	return
	end

Special_Gym_EventScript_Mega_Bracelet::
	giveitem ITEM_MEGA_BRACELET
	msgbox   Special_Gym_Text_Explain_Mega_Bracelet, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_11
	setvar   VAR_NUM_BADGES, 11
	return
	end

Special_Gym_EventScript_Effort_Tool::
	giveitem ITEM_EFFORT_TOOL
	msgbox   Special_Gym_Text_Explain_Effort_Tool, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_12
	setvar   VAR_NUM_BADGES, 12
	return
	end

Special_Gym_EventScript_Alpha_Charm::
	giveitem ITEM_ALPHA_CHARM
	msgbox   Special_Gym_Text_Explain_Alpha_Charm, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_13
	setvar   VAR_NUM_BADGES, 13
	return
	end

Special_Gym_EventScript_Wonder_Charm::
	giveitem ITEM_WONDER_CHARM
	msgbox   Special_Gym_Text_Explain_Wonder_Charm, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_14
	setvar   VAR_NUM_BADGES, 14
	return
	end

Special_Gym_EventScript_Master_Ball::
	giveitem ITEM_MASTER_BALL
	msgbox   Special_Gym_Text_Explain_Master_Ball, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_15
	setvar   VAR_NUM_BADGES, 15
	return
	end

Special_Gym_EventScript_Shiny_Charm::
	giveitem ITEM_SHINY_CHARM
	msgbox   Special_Gym_Text_Explain_Shiny_Charm, MSGBOX_DEFAULT
	setflag  FLAG_RECEIVED_BADGE_16
	setvar   VAR_NUM_BADGES, 16
	return
	end

Common_EventScript_Colress_Eight_Island::
# 150 "data/scripts/flying_taxi.pory"
	lock
# 151 "data/scripts/flying_taxi.pory"
	faceplayer
# 152 "data/scripts/flying_taxi.pory"
	setvar VAR_CURRENT_SEVII, 7
# 153 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress
	return



Common_EventScript_Colress_Five_Island::
# 129 "data/scripts/flying_taxi.pory"
	lock
# 130 "data/scripts/flying_taxi.pory"
	faceplayer
# 131 "data/scripts/flying_taxi.pory"
	setvar VAR_CURRENT_SEVII, 4
# 132 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress
	return



Common_EventScript_Colress_Seven_Island::
# 143 "data/scripts/flying_taxi.pory"
	lock
# 144 "data/scripts/flying_taxi.pory"
	faceplayer
# 145 "data/scripts/flying_taxi.pory"
	setvar VAR_CURRENT_SEVII, 6
# 146 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress
	return



Common_EventScript_Colress_Six_Island::
# 136 "data/scripts/flying_taxi.pory"
	lock
# 137 "data/scripts/flying_taxi.pory"
	faceplayer
# 138 "data/scripts/flying_taxi.pory"
	setvar VAR_CURRENT_SEVII, 5
# 139 "data/scripts/flying_taxi.pory"
	goto Common_EventScript_Colress
	return



@ ---------------------------------------------------------------------------
@ Colress on islands 1-4. He is how the player gets the ticket to the NEXT
@ island, so without these four the chain dead-ends: start on One Island and
@ there is nobody to hand you another ticket.
@
@ These were missed because Mt. Ember, Cape Brink, Berry Forest and Icefall Cave
@ ALREADY EXISTED in the 1.9.4 tree, and the Phase 4 import only copied maps we
@ did not have -- so it never merged the donor's edits (the Colress objects) into
@ maps we already owned. Islands 5-8's Colress came in only because those maps
@ were new.
@ ---------------------------------------------------------------------------

Common_EventScript_Colress_One_Island::
	lock
	faceplayer
	setvar VAR_CURRENT_SEVII, 0
	goto Common_EventScript_Colress
	return


Common_EventScript_Colress_Two_Island::
	lock
	faceplayer
	setvar VAR_CURRENT_SEVII, 1
	goto Common_EventScript_Colress
	return


Common_EventScript_Colress_Three_Island::
	lock
	faceplayer
	setvar VAR_CURRENT_SEVII, 2
	goto Common_EventScript_Colress
	return


Common_EventScript_Colress_Four_Island::
	lock
	faceplayer
	setvar VAR_CURRENT_SEVII, 3
	goto Common_EventScript_Colress
	return

