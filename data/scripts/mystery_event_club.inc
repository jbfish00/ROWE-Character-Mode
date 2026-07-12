# 1 "data/scripts/mystery_event_club.pory"

# 2 "data/scripts/mystery_event_club.pory"
MysteryEventClub_EventScript_Man::
# 3 "data/scripts/mystery_event_club.pory"
	lock
# 4 "data/scripts/mystery_event_club.pory"
	faceplayer
# 5 "data/scripts/mystery_event_club.pory"
	goto_if_set FLAG_SYS_CHAT_USED, MysteryEventClub_EventScript_GivenProfileBefore
# 6 "data/scripts/mystery_event_club.pory"
	msgbox MysteryEventClub_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
# 7 "data/scripts/mystery_event_club.pory"
	goto MysteryEventClub_EventScript_AskToSeeProfile
# 8 "data/scripts/mystery_event_club.pory"
	end
# 9 "data/scripts/mystery_event_club.pory"

# 10 "data/scripts/mystery_event_club.pory"
MysteryEventClub_EventScript_AskToSeeProfile::
# 11 "data/scripts/mystery_event_club.pory"
	msgbox MysteryEventClub_Text_MayISeeYourProfile, MSGBOX_DEFAULT
# 12 "data/scripts/mystery_event_club.pory"
	multichoice 17, 6, MULTI_YESNOINFO_2, 0
# 13 "data/scripts/mystery_event_club.pory"
	switch VAR_RESULT
# 14 "data/scripts/mystery_event_club.pory"
	case 0, MysteryEventClub_EventScript_CreateProfile
# 15 "data/scripts/mystery_event_club.pory"
	case 1, MysteryEventClub_EventScript_DeclineShowProfile
# 16 "data/scripts/mystery_event_club.pory"
	case 2, MysteryEventClub_EventScript_Info
# 17 "data/scripts/mystery_event_club.pory"
	case MULTI_B_PRESSED, MysteryEventClub_EventScript_DeclineShowProfile
# 18 "data/scripts/mystery_event_club.pory"
	end
# 19 "data/scripts/mystery_event_club.pory"

# 20 "data/scripts/mystery_event_club.pory"
MysteryEventClub_EventScript_Info::
# 21 "data/scripts/mystery_event_club.pory"
	msgbox MysteryEventClub_Text_EasyChatExplanation, MSGBOX_DEFAULT
# 22 "data/scripts/mystery_event_club.pory"
	goto MysteryEventClub_EventScript_AskToSeeProfile
# 23 "data/scripts/mystery_event_club.pory"
	end
# 24 "data/scripts/mystery_event_club.pory"

# 25 "data/scripts/mystery_event_club.pory"
MysteryEventClub_EventScript_CreateProfile::
# 26 "data/scripts/mystery_event_club.pory"
	msgbox MysteryEventClub_Text_LetsSeeItThen, MSGBOX_DEFAULT
# 27 "data/scripts/mystery_event_club.pory"
	closemessage
# 28 "data/scripts/mystery_event_club.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
# 29 "data/scripts/mystery_event_club.pory"
	call Common_ShowEasyChatScreen
# 30 "data/scripts/mystery_event_club.pory"
	lock
# 31 "data/scripts/mystery_event_club.pory"
	faceplayer
# 32 "data/scripts/mystery_event_club.pory"
	compare VAR_RESULT, 0
# 33 "data/scripts/mystery_event_club.pory"
	goto_if_eq MysteryEventClub_EventScript_CancelShowProfile
# 34 "data/scripts/mystery_event_club.pory"
	compare VAR_RESULT, 1
# 35 "data/scripts/mystery_event_club.pory"
	goto_if_eq MysteryEventClub_EventScript_ShowProfile
# 36 "data/scripts/mystery_event_club.pory"
	end
# 37 "data/scripts/mystery_event_club.pory"

# 38 "data/scripts/mystery_event_club.pory"
MysteryEventClub_EventScript_CancelShowProfile::
# 39 "data/scripts/mystery_event_club.pory"
	msgbox MysteryEventClub_Text_NotIntoItRightNow, MSGBOX_DEFAULT
# 40 "data/scripts/mystery_event_club.pory"
	release
# 41 "data/scripts/mystery_event_club.pory"
	end
# 42 "data/scripts/mystery_event_club.pory"

# 43 "data/scripts/mystery_event_club.pory"
MysteryEventClub_EventScript_ShowProfile::
# 44 "data/scripts/mystery_event_club.pory"
	setvar VAR_0x8004, 0
# 45 "data/scripts/mystery_event_club.pory"
	special ShowEasyChatProfile
# 46 "data/scripts/mystery_event_club.pory"
	waitmessage
# 47 "data/scripts/mystery_event_club.pory"
	delay 80
# 48 "data/scripts/mystery_event_club.pory"
	msgbox MysteryEventClub_Text_FantasticProfile, MSGBOX_DEFAULT
# 49 "data/scripts/mystery_event_club.pory"
	release
# 50 "data/scripts/mystery_event_club.pory"
	end
# 51 "data/scripts/mystery_event_club.pory"

# 52 "data/scripts/mystery_event_club.pory"
MysteryEventClub_EventScript_DeclineShowProfile::
# 53 "data/scripts/mystery_event_club.pory"
	msgbox MysteryEventClub_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
# 54 "data/scripts/mystery_event_club.pory"
	release
# 55 "data/scripts/mystery_event_club.pory"
	end
# 56 "data/scripts/mystery_event_club.pory"

# 57 "data/scripts/mystery_event_club.pory"
MysteryEventClub_EventScript_GivenProfileBefore::
# 58 "data/scripts/mystery_event_club.pory"
	msgbox MysteryEventClub_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
# 59 "data/scripts/mystery_event_club.pory"
	goto MysteryEventClub_EventScript_AskToSeeNewProfile
# 60 "data/scripts/mystery_event_club.pory"
	end
# 61 "data/scripts/mystery_event_club.pory"

# 62 "data/scripts/mystery_event_club.pory"
MysteryEventClub_EventScript_AskToSeeNewProfile::
# 63 "data/scripts/mystery_event_club.pory"
	msgbox MysteryEventClub_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
# 64 "data/scripts/mystery_event_club.pory"
	multichoice 17, 6, MULTI_YESNOINFO_2, 0
# 65 "data/scripts/mystery_event_club.pory"
	switch VAR_RESULT
# 66 "data/scripts/mystery_event_club.pory"
	case 0, MysteryEventClub_EventScript_CreateNewProfile
# 67 "data/scripts/mystery_event_club.pory"
	case 1, MysteryEventClub_EventScript_DeclineNewProfile
# 68 "data/scripts/mystery_event_club.pory"
	case 2, MysteryEventClub_EventScript_InfoNewProfile
# 69 "data/scripts/mystery_event_club.pory"
	case MULTI_B_PRESSED, MysteryEventClub_EventScript_DeclineNewProfile
# 70 "data/scripts/mystery_event_club.pory"
	end
# 71 "data/scripts/mystery_event_club.pory"

# 72 "data/scripts/mystery_event_club.pory"
MysteryEventClub_EventScript_InfoNewProfile::
# 73 "data/scripts/mystery_event_club.pory"
	msgbox MysteryEventClub_Text_EasyChatExplanation, MSGBOX_DEFAULT
# 74 "data/scripts/mystery_event_club.pory"
	goto MysteryEventClub_EventScript_AskToSeeNewProfile
# 75 "data/scripts/mystery_event_club.pory"
	end
# 76 "data/scripts/mystery_event_club.pory"

# 77 "data/scripts/mystery_event_club.pory"
MysteryEventClub_EventScript_CreateNewProfile::
# 78 "data/scripts/mystery_event_club.pory"
	msgbox MysteryEventClub_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
# 79 "data/scripts/mystery_event_club.pory"
	closemessage
# 80 "data/scripts/mystery_event_club.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
# 81 "data/scripts/mystery_event_club.pory"
	call Common_ShowEasyChatScreen
# 82 "data/scripts/mystery_event_club.pory"
	lock
# 83 "data/scripts/mystery_event_club.pory"
	faceplayer
# 84 "data/scripts/mystery_event_club.pory"
	compare VAR_RESULT, 0
# 85 "data/scripts/mystery_event_club.pory"
	goto_if_eq MysteryEventClub_EventScript_CancelShowProfile
# 86 "data/scripts/mystery_event_club.pory"
	compare VAR_RESULT, 1
# 87 "data/scripts/mystery_event_club.pory"
	goto_if_eq MysteryEventClub_EventScript_ShowProfile
# 88 "data/scripts/mystery_event_club.pory"
	end
# 89 "data/scripts/mystery_event_club.pory"

# 90 "data/scripts/mystery_event_club.pory"
MysteryEventClub_EventScript_DeclineNewProfile::
# 91 "data/scripts/mystery_event_club.pory"
	msgbox MysteryEventClub_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
# 92 "data/scripts/mystery_event_club.pory"
	release
# 93 "data/scripts/mystery_event_club.pory"
	end

# 97 "data/scripts/mystery_event_club.pory"

# 98 "data/scripts/mystery_event_club.pory"
MysteryEventClub_EventScript_Ret::
# 99 "data/scripts/mystery_event_club.pory"
	return

MysteryEventClub_Text_CollectTrainerProfiles::
# 102 "data/scripts/mystery_event_club.pory"
	.string "Hello there, Trainer!\n"
	.string "You've got a wonderful smile, there.\p"
	.string "I have a hobby--collecting the profiles\n"
	.string "of Pokémon Trainers.$"

MysteryEventClub_Text_MayISeeYourProfile::
# 109 "data/scripts/mystery_event_club.pory"
	.string "So, how about it?\n"
	.string "May I see your profile?$"

MysteryEventClub_Text_EasyChatExplanation::
# 114 "data/scripts/mystery_event_club.pory"
	.string "You make your own profile by putting\n"
	.string "together four words or phrases.\p"
	.string "Here, I'll show you an example of a\n"
	.string "profile using four pieces of text.\p"
	.string "You can switch those four pieces with\n"
	.string "other text pieces any which way you\l"
	.string "like to make your own profile.\p"
	.string "There are a lot of text pieces that\n"
	.string "you can use.\p"
	.string "They are arranged in groups like\n"
	.string "Pokémon, lifestyles, and hobbies so\l"
	.string "it is easier to look them up.\p"
	.string "So, first, choose the group of text\n"
	.string "pieces to display a list of choices.\p"
	.string "Then, pick the choice you want.\p"
	.string "Repeat for the remaining text choices,\n"
	.string "and you'll have your very own profile.$"

MysteryEventClub_Text_LetsSeeItThen::
# 134 "data/scripts/mystery_event_club.pory"
	.string "Yes! Thank you!\n"
	.string "So, let's see it, then.$"

MysteryEventClub_Text_ImagineYouWouldHaveWonderfulProfile::
# 139 "data/scripts/mystery_event_club.pory"
	.string "Oh, no, really?\p"
	.string "I imagine someone like you would have\n"
	.string "a wonderful profile…$"

MysteryEventClub_Text_NotIntoItRightNow::
# 145 "data/scripts/mystery_event_club.pory"
	.string "Oh? You're not into it right now?\p"
	.string "Well, anytime is good by me!$"

MysteryEventClub_Text_YouHaveWonderfulSmile::
# 150 "data/scripts/mystery_event_club.pory"
	.string "Hello there, Trainer!\n"
	.string "You've got a wonderful smile.$"

MysteryEventClub_Text_MayISeeYourNewProfile::
# 155 "data/scripts/mystery_event_club.pory"
	.string "May I see your new profile?$"

MysteryEventClub_Text_EvenBetterThanLastProfile::
# 159 "data/scripts/mystery_event_club.pory"
	.string "Yes! Thank you!\p"
	.string "I hope it's even better than the profile\n"
	.string "you showed me before.$"

MysteryEventClub_Text_LikeProfileWayItIs::
# 165 "data/scripts/mystery_event_club.pory"
	.string "Oh, you like your profile the way it is.\p"
	.string "I don't blame you--it's a wonderful\n"
	.string "profile the way it is now.$"

MysteryEventClub_Text_FantasticProfile::
# 171 "data/scripts/mystery_event_club.pory"
	.string "F-fantastic!\p"
	.string "Your profile, it's wonderful!\n"
	.string "It really says what you're about.\p"
	.string "Why, anyone hearing this profile would\n"
	.string "be captivated by you!\p"
	.string "Thank you!$"

MysteryEventClub_Text_YouKnowSecretSaying::
# 181 "data/scripts/mystery_event_club.pory"
	.string "Oh?\n"
	.string "You know the secret saying!\p"
	.string "That means you're now a fellow member\n"
	.string "of the Mystery Event Club!$"
