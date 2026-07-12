# 1 "data/scripts/mevent.pory"

# 2 "data/scripts/mevent.pory"
EventScript_Questionnaire::
# 3 "data/scripts/mevent.pory"
	lockall
# 4 "data/scripts/mevent.pory"
	msgbox Mevent_Text_FillOutQuestionnaire, MSGBOX_YESNO
# 5 "data/scripts/mevent.pory"
	compare VAR_RESULT, NO
# 6 "data/scripts/mevent.pory"
	goto_if_eq Mevent_EventScript_Release
# 7 "data/scripts/mevent.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_QUESTIONNAIRE
# 8 "data/scripts/mevent.pory"
	call Common_ShowEasyChatScreen
# 9 "data/scripts/mevent.pory"
	lock
# 10 "data/scripts/mevent.pory"
	faceplayer
# 11 "data/scripts/mevent.pory"
	specialvar VAR_0x8008, GetMartEmployeeObjectEventId
# 12 "data/scripts/mevent.pory"
	compare VAR_0x8004, 1
# 13 "data/scripts/mevent.pory"
	goto_if_eq Mevent_EventScript_PlayerInputMysteryEventPhrase
# 14 "data/scripts/mevent.pory"
	compare VAR_0x8004, 2
# 15 "data/scripts/mevent.pory"
	goto_if_eq Mevent_EventScript_PlayerInputMysteryGiftPhrase
# 16 "data/scripts/mevent.pory"
	compare VAR_RESULT, 0
# 17 "data/scripts/mevent.pory"
	goto_if_eq Mevent_EventScript_Release
# 18 "data/scripts/mevent.pory"
	compare VAR_RESULT, 1
# 19 "data/scripts/mevent.pory"
	goto_if_eq Mevent_EventScript_QuestionnaireThankYou
# 20 "data/scripts/mevent.pory"
	end
# 21 "data/scripts/mevent.pory"

# 22 "data/scripts/mevent.pory"
Mevent_EventScript_PlayerInputMysteryEventPhrase::
# 23 "data/scripts/mevent.pory"
	goto_if_unset FLAG_SYS_POKEDEX_GET, Mevent_EventScript_QuestionnaireThankYou
# 24 "data/scripts/mevent.pory"
	goto_if_set FLAG_SYS_MYSTERY_EVENT_ENABLE, Mevent_EventScript_QuestionnaireThankYou
# 25 "data/scripts/mevent.pory"
	applymovement VAR_0x8008, Common_Movement_FaceDown
# 26 "data/scripts/mevent.pory"
	waitmovement 0
# 27 "data/scripts/mevent.pory"
	playse SE_PIN
# 28 "data/scripts/mevent.pory"
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 29 "data/scripts/mevent.pory"
	waitmovement 0
# 30 "data/scripts/mevent.pory"
	applymovement VAR_0x8008, Common_Movement_Delay48
# 31 "data/scripts/mevent.pory"
	waitmovement 0
# 32 "data/scripts/mevent.pory"
	msgbox Mevent_Text_YouKnowThoseWordsEvent, MSGBOX_DEFAULT
# 33 "data/scripts/mevent.pory"
	setflag FLAG_SYS_MYSTERY_EVENT_ENABLE
# 34 "data/scripts/mevent.pory"
	msgbox Mevent_Text_YouCanAccessMysteryEvent, MSGBOX_DEFAULT
# 35 "data/scripts/mevent.pory"
	releaseall
# 36 "data/scripts/mevent.pory"
	end
# 37 "data/scripts/mevent.pory"

# 38 "data/scripts/mevent.pory"
Mevent_EventScript_PlayerInputMysteryGiftPhrase::
# 39 "data/scripts/mevent.pory"
	goto_if_unset FLAG_SYS_POKEDEX_GET, Mevent_EventScript_QuestionnaireThankYou
# 40 "data/scripts/mevent.pory"
	goto_if_set FLAG_SYS_MYSTERY_GIFT_ENABLE, Mevent_EventScript_QuestionnaireThankYou
# 41 "data/scripts/mevent.pory"
	applymovement VAR_0x8008, Common_Movement_FaceDown
# 42 "data/scripts/mevent.pory"
	waitmovement 0
# 43 "data/scripts/mevent.pory"
	playse SE_PIN
# 44 "data/scripts/mevent.pory"
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 45 "data/scripts/mevent.pory"
	waitmovement 0
# 46 "data/scripts/mevent.pory"
	applymovement VAR_0x8008, Common_Movement_Delay48
# 47 "data/scripts/mevent.pory"
	waitmovement 0
# 48 "data/scripts/mevent.pory"
	msgbox Mevent_Text_YouKnowThoseWordsGift, MSGBOX_DEFAULT
# 49 "data/scripts/mevent.pory"
	setflag FLAG_SYS_MYSTERY_GIFT_ENABLE
# 50 "data/scripts/mevent.pory"
	msgbox Mevent_Text_YouCanAccessMysteryGift, MSGBOX_DEFAULT
# 51 "data/scripts/mevent.pory"
	releaseall
# 52 "data/scripts/mevent.pory"
	end
# 53 "data/scripts/mevent.pory"

# 54 "data/scripts/mevent.pory"
Mevent_EventScript_Release::
# 55 "data/scripts/mevent.pory"
	releaseall
# 56 "data/scripts/mevent.pory"
	end
# 57 "data/scripts/mevent.pory"

# 58 "data/scripts/mevent.pory"
Mevent_EventScript_QuestionnaireThankYou::
# 59 "data/scripts/mevent.pory"
	applymovement VAR_0x8008, Common_Movement_FaceDown
# 60 "data/scripts/mevent.pory"
	waitmovement 0
# 61 "data/scripts/mevent.pory"
	msgbox Mevent_Text_QuestionnaireThankYou, MSGBOX_DEFAULT
# 62 "data/scripts/mevent.pory"
	releaseall
# 63 "data/scripts/mevent.pory"
	end
