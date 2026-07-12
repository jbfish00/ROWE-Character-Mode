# 1 "data/scripts/mauville_man.pory"

# 2 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan:: @ 828E066
# 3 "data/scripts/mauville_man.pory"
	special ScrSpecial_GetCurrentMauvilleMan
# 4 "data/scripts/mauville_man.pory"
	switch VAR_RESULT
# 5 "data/scripts/mauville_man.pory"
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
# 6 "data/scripts/mauville_man.pory"
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
# 7 "data/scripts/mauville_man.pory"
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
# 8 "data/scripts/mauville_man.pory"
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
# 9 "data/scripts/mauville_man.pory"
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
# 10 "data/scripts/mauville_man.pory"
	end
# 11 "data/scripts/mauville_man.pory"

# 12 "data/scripts/mauville_man.pory"
@ Bard
# 13 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_Bard:: @ 828E0A6
# 14 "data/scripts/mauville_man.pory"
	lock
# 15 "data/scripts/mauville_man.pory"
	faceplayer
# 16 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
# 17 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, YES
# 18 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
# 19 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, NO
# 20 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
# 21 "data/scripts/mauville_man.pory"
	end
# 22 "data/scripts/mauville_man.pory"

# 23 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_PlaySong:: @ 828E0C7
# 24 "data/scripts/mauville_man.pory"
	setvar VAR_0x8004, 0
# 25 "data/scripts/mauville_man.pory"
	special ScrSpecial_PlayBardSong
# 26 "data/scripts/mauville_man.pory"
	delay 60
# 27 "data/scripts/mauville_man.pory"
	special ScrSpecial_HasBardSongBeenChanged
# 28 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, FALSE
# 29 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
# 30 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
# 31 "data/scripts/mauville_man.pory"
	release
# 32 "data/scripts/mauville_man.pory"
	end
# 33 "data/scripts/mauville_man.pory"

# 34 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong:: @ 828E0EA
# 35 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
# 36 "data/scripts/mauville_man.pory"
	release
# 37 "data/scripts/mauville_man.pory"
	end
# 38 "data/scripts/mauville_man.pory"

# 39 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics:: @ 828E0F4
# 40 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
# 41 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, YES
# 42 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
# 43 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, NO
# 44 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
# 45 "data/scripts/mauville_man.pory"
	end
# 46 "data/scripts/mauville_man.pory"

# 47 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics:: @ 828E113
# 48 "data/scripts/mauville_man.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
# 49 "data/scripts/mauville_man.pory"
	call Common_ShowEasyChatScreen
# 50 "data/scripts/mauville_man.pory"
	lock
# 51 "data/scripts/mauville_man.pory"
	faceplayer
# 52 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, 0
# 53 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
# 54 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
# 55 "data/scripts/mauville_man.pory"
	setvar VAR_0x8004, 1
# 56 "data/scripts/mauville_man.pory"
	special ScrSpecial_PlayBardSong
# 57 "data/scripts/mauville_man.pory"
	delay 60
# 58 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
# 59 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, NO
# 60 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
# 61 "data/scripts/mauville_man.pory"
	special ScrSpecial_SaveBardSongLyrics
# 62 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
# 63 "data/scripts/mauville_man.pory"
	release
# 64 "data/scripts/mauville_man.pory"
	end
# 65 "data/scripts/mauville_man.pory"

# 66 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics:: @ 828E15D
# 67 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
# 68 "data/scripts/mauville_man.pory"
	release
# 69 "data/scripts/mauville_man.pory"
	end
# 70 "data/scripts/mauville_man.pory"

# 71 "data/scripts/mauville_man.pory"
@ Hipster
# 72 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_Hipster:: @ 828E167
# 73 "data/scripts/mauville_man.pory"
	lock
# 74 "data/scripts/mauville_man.pory"
	faceplayer
# 75 "data/scripts/mauville_man.pory"
	setflag FLAG_SYS_HIPSTER_MEET
# 76 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
# 77 "data/scripts/mauville_man.pory"
	special ScrSpecial_GetHipsterSpokenFlag
# 78 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, FALSE
# 79 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
# 80 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
# 81 "data/scripts/mauville_man.pory"
	release
# 82 "data/scripts/mauville_man.pory"
	end
# 83 "data/scripts/mauville_man.pory"

# 84 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord:: @ 828E18C
# 85 "data/scripts/mauville_man.pory"
	special ScrSpecial_HipsterTeachWord
# 86 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, TRUE
# 87 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
# 88 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
# 89 "data/scripts/mauville_man.pory"
	release
# 90 "data/scripts/mauville_man.pory"
	end
# 91 "data/scripts/mauville_man.pory"

# 92 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_TeachWord:: @ 828E1A4
# 93 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase, MSGBOX_DEFAULT
# 94 "data/scripts/mauville_man.pory"
	special ScrSpecial_SetHipsterSpokenFlag
# 95 "data/scripts/mauville_man.pory"
	release
# 96 "data/scripts/mauville_man.pory"
	end
# 97 "data/scripts/mauville_man.pory"

# 98 "data/scripts/mauville_man.pory"
@ Trader
# 99 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor: @ 828E1B1
# 100 "data/scripts/mauville_man.pory"
	.string "Hi, I'm the TRADER.\n"
# 101 "data/scripts/mauville_man.pory"
	.string "Want to trade decorations with me?$"
# 102 "data/scripts/mauville_man.pory"

# 103 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues: @ 828E1E8
# 104 "data/scripts/mauville_man.pory"
	.string "Oh…\n"
# 105 "data/scripts/mauville_man.pory"
	.string "You've left me feeling the blues…$"
# 106 "data/scripts/mauville_man.pory"

# 107 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded: @ 828E20E
# 108 "data/scripts/mauville_man.pory"
	.string "But we've traded decorations already,\n"
# 109 "data/scripts/mauville_man.pory"
	.string "you and I.$"
# 110 "data/scripts/mauville_man.pory"

# 111 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_PickADecorItem: @ 828E23F
# 112 "data/scripts/mauville_man.pory"
	.string "If you see any decorative item that\n"
# 113 "data/scripts/mauville_man.pory"
	.string "you want of mine, speak up.$"
# 114 "data/scripts/mauville_man.pory"

# 115 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything: @ 828E27F
# 116 "data/scripts/mauville_man.pory"
	.string "You don't want anything?\n"
# 117 "data/scripts/mauville_man.pory"
	.string "I feel unwanted…$"
# 118 "data/scripts/mauville_man.pory"

# 119 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt: @ 828E2A9
# 120 "data/scripts/mauville_man.pory"
	.string "That decorative item once belonged\n"
# 121 "data/scripts/mauville_man.pory"
	.string "to {STR_VAR_1}.\p"
# 122 "data/scripts/mauville_man.pory"
	.string "Do you want it?$"
# 123 "data/scripts/mauville_man.pory"

# 124 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor: @ 828E2E3
# 125 "data/scripts/mauville_man.pory"
	.string "Uh… Wait a second. You don't have a\n"
# 126 "data/scripts/mauville_man.pory"
	.string "single piece of decoration!$"
# 127 "data/scripts/mauville_man.pory"

# 128 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade: @ 828E323
# 129 "data/scripts/mauville_man.pory"
	.string "Okay, pick the decoration that you'll\n"
# 130 "data/scripts/mauville_man.pory"
	.string "trade to me.$"
# 131 "data/scripts/mauville_man.pory"

# 132 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade: @ 828E356
# 133 "data/scripts/mauville_man.pory"
	.string "You won't trade with me?\n"
# 134 "data/scripts/mauville_man.pory"
	.string "I feel unwanted…$"
# 135 "data/scripts/mauville_man.pory"

# 136 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis: @ 828E380
# 137 "data/scripts/mauville_man.pory"
	.string "You've got all the {STR_VAR_2}s that can\n"
# 138 "data/scripts/mauville_man.pory"
	.string "be stored. You've no room for this.$"
# 139 "data/scripts/mauville_man.pory"

# 140 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor: @ 828E3C4
# 141 "data/scripts/mauville_man.pory"
	.string "Okay, so we'll trade my {STR_VAR_3}\n"
# 142 "data/scripts/mauville_man.pory"
	.string "for your {STR_VAR_2}?$"
# 143 "data/scripts/mauville_man.pory"

# 144 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse: @ 828E3EC
# 145 "data/scripts/mauville_man.pory"
	.string "That piece of decoration is in use.\n"
# 146 "data/scripts/mauville_man.pory"
	.string "You can't trade it.$"
# 147 "data/scripts/mauville_man.pory"

# 148 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC: @ 828E424
# 149 "data/scripts/mauville_man.pory"
	.string "Then we'll trade!\n"
# 150 "data/scripts/mauville_man.pory"
	.string "I'll send my decoration to your PC.$"
# 151 "data/scripts/mauville_man.pory"

# 152 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne: @ 828E45A
# 153 "data/scripts/mauville_man.pory"
	.string "Oops! Sorry! That's a really rare\n"
# 154 "data/scripts/mauville_man.pory"
	.string "piece of decoration.\l"
# 155 "data/scripts/mauville_man.pory"
	.string "I can't trade that one away!\p"
# 156 "data/scripts/mauville_man.pory"
	.string "Can I interest you in something else?$"
# 157 "data/scripts/mauville_man.pory"

# 158 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_Trader:: @ 828E4D4
# 159 "data/scripts/mauville_man.pory"
	lock
# 160 "data/scripts/mauville_man.pory"
	faceplayer
# 161 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
# 162 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, NO
# 163 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
# 164 "data/scripts/mauville_man.pory"
	special ScrSpecial_GetTraderTradedFlag
# 165 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, TRUE
# 166 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
# 167 "data/scripts/mauville_man.pory"
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
# 168 "data/scripts/mauville_man.pory"
	waitmessage
# 169 "data/scripts/mauville_man.pory"
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
# 170 "data/scripts/mauville_man.pory"
	end
# 171 "data/scripts/mauville_man.pory"

# 172 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade:: @ 828E503
# 173 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
# 174 "data/scripts/mauville_man.pory"
	release
# 175 "data/scripts/mauville_man.pory"
	end
# 176 "data/scripts/mauville_man.pory"

# 177 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded:: @ 828E50D
# 178 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
# 179 "data/scripts/mauville_man.pory"
	release
# 180 "data/scripts/mauville_man.pory"
	end
# 181 "data/scripts/mauville_man.pory"

# 182 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive:: @ 828E517
# 183 "data/scripts/mauville_man.pory"
	special ScrSpecial_TraderMenuGetDecoration
# 184 "data/scripts/mauville_man.pory"
	waitstate
# 185 "data/scripts/mauville_man.pory"
	compare VAR_0x8004, 0
# 186 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
# 187 "data/scripts/mauville_man.pory"
	compare VAR_0x8004, 0xFFFF
# 188 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
# 189 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
# 190 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, NO
# 191 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
# 192 "data/scripts/mauville_man.pory"
	special ScrSpecial_DoesPlayerHaveNoDecorations
# 193 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, TRUE
# 194 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
# 195 "data/scripts/mauville_man.pory"
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
# 196 "data/scripts/mauville_man.pory"
	end
# 197 "data/scripts/mauville_man.pory"

# 198 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor:: @ 828E558
# 199 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
# 200 "data/scripts/mauville_man.pory"
	release
# 201 "data/scripts/mauville_man.pory"
	end
# 202 "data/scripts/mauville_man.pory"

# 203 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor:: @ 828E562
# 204 "data/scripts/mauville_man.pory"
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
# 205 "data/scripts/mauville_man.pory"
	waitmessage
# 206 "data/scripts/mauville_man.pory"
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
# 207 "data/scripts/mauville_man.pory"
	end
# 208 "data/scripts/mauville_man.pory"

# 209 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor:: @ 828E56E
# 210 "data/scripts/mauville_man.pory"
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
# 211 "data/scripts/mauville_man.pory"
	waitmessage
# 212 "data/scripts/mauville_man.pory"
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
# 213 "data/scripts/mauville_man.pory"
	end
# 214 "data/scripts/mauville_man.pory"

# 215 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor:: @ 828E57A
# 216 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
# 217 "data/scripts/mauville_man.pory"
	release
# 218 "data/scripts/mauville_man.pory"
	end
# 219 "data/scripts/mauville_man.pory"

# 220 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive:: @ 828E584
# 221 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
# 222 "data/scripts/mauville_man.pory"
	special ScrSpecial_TraderMenuGiveDecoration
# 223 "data/scripts/mauville_man.pory"
	waitstate
# 224 "data/scripts/mauville_man.pory"
	compare VAR_0x8006, 0
# 225 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
# 226 "data/scripts/mauville_man.pory"
	compare VAR_0x8006, 0xFFFF
# 227 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
# 228 "data/scripts/mauville_man.pory"
	special ScrSpecial_IsDecorationFull
# 229 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, TRUE
# 230 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
# 231 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
# 232 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, NO
# 233 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
# 234 "data/scripts/mauville_man.pory"
	special ScrSpecial_TraderDoDecorationTrade
# 235 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
# 236 "data/scripts/mauville_man.pory"
	release
# 237 "data/scripts/mauville_man.pory"
	end
# 238 "data/scripts/mauville_man.pory"

# 239 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor:: @ 828E5D4
# 240 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
# 241 "data/scripts/mauville_man.pory"
	release
# 242 "data/scripts/mauville_man.pory"
	end
# 243 "data/scripts/mauville_man.pory"

# 244 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse:: @ 828E5DE
# 245 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
# 246 "data/scripts/mauville_man.pory"
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
# 247 "data/scripts/mauville_man.pory"
	end
# 248 "data/scripts/mauville_man.pory"

# 249 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor:: @ 828E5EC
# 250 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
# 251 "data/scripts/mauville_man.pory"
	release
# 252 "data/scripts/mauville_man.pory"
	end
# 253 "data/scripts/mauville_man.pory"

# 254 "data/scripts/mauville_man.pory"
@ Storyteller
# 255 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale: @ 828E5F6
# 256 "data/scripts/mauville_man.pory"
	.string "I'm the Storyteller.\n"
# 257 "data/scripts/mauville_man.pory"
	.string "I'll tell you tales of legendary\l"
# 258 "data/scripts/mauville_man.pory"
	.string "Trainers.\p"
# 259 "data/scripts/mauville_man.pory"
	.string "Will you hear my tale?$"
# 260 "data/scripts/mauville_man.pory"

# 261 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues: @ 828E64D
# 262 "data/scripts/mauville_man.pory"
	.string "Oh…\n"
# 263 "data/scripts/mauville_man.pory"
	.string "You've left me feeling the blues…$"
# 264 "data/scripts/mauville_man.pory"

# 265 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell: @ 828E673
# 266 "data/scripts/mauville_man.pory"
	.string "I know of these legends.\n"
# 267 "data/scripts/mauville_man.pory"
	.string "Which tale will you have me tell?$"
# 268 "data/scripts/mauville_man.pory"

# 269 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales: @ 828E6AE
# 270 "data/scripts/mauville_man.pory"
	.string "But, I know of no legendary Trainers.\n"
# 271 "data/scripts/mauville_man.pory"
	.string "Hence, I know no tales.\p"
# 272 "data/scripts/mauville_man.pory"
	.string "Where does one find a Trainer worthy\n"
# 273 "data/scripts/mauville_man.pory"
	.string "of a legendary tale?$"
# 274 "data/scripts/mauville_man.pory"

# 275 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes: @ 828E726
# 276 "data/scripts/mauville_man.pory"
	.string "What's that?!\n"
# 277 "data/scripts/mauville_man.pory"
	.string "You… You…\p"
# 278 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_2}\n"
# 279 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} time(s)?!\p"
# 280 "data/scripts/mauville_man.pory"
	.string "That is indeed magnificent!\n"
# 281 "data/scripts/mauville_man.pory"
	.string "It's the birth of a new legend!$"
# 282 "data/scripts/mauville_man.pory"

# 283 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends: @ 828E78A
# 284 "data/scripts/mauville_man.pory"
	.string "It gets me thinking, could there be\n"
# 285 "data/scripts/mauville_man.pory"
	.string "other Trainers with more impressive\l"
# 286 "data/scripts/mauville_man.pory"
	.string "legends awaiting discovery?$"
# 287 "data/scripts/mauville_man.pory"

# 288 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales: @ 828E7EE
# 289 "data/scripts/mauville_man.pory"
	.string "Are you a Trainer?\p"
# 290 "data/scripts/mauville_man.pory"
	.string "Then tell me, have you any tales that\n"
# 291 "data/scripts/mauville_man.pory"
	.string "are even remotely legendary?$"
# 292 "data/scripts/mauville_man.pory"

# 293 "data/scripts/mauville_man.pory"
@ Unused
# 294 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale: @ 828E844
# 295 "data/scripts/mauville_man.pory"
	.string "Incidentally… Would you care to hear\n"
# 296 "data/scripts/mauville_man.pory"
	.string "another legendary tale?$"
# 297 "data/scripts/mauville_man.pory"

# 298 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend: @ 828E881
# 299 "data/scripts/mauville_man.pory"
	.string "Hmm…\n"
# 300 "data/scripts/mauville_man.pory"
	.string "I'm not satisfied…\p"
# 301 "data/scripts/mauville_man.pory"
	.string "I wish you would bring me news worthy\n"
# 302 "data/scripts/mauville_man.pory"
	.string "of being called a legend.$"
# 303 "data/scripts/mauville_man.pory"

# 304 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested: @ 828E8D9
# 305 "data/scripts/mauville_man.pory"
	.string "I wish more people would be interested\n"
# 306 "data/scripts/mauville_man.pory"
	.string "in hearing my epic tales of legendary\l"
# 307 "data/scripts/mauville_man.pory"
	.string "Trainers.$"
# 308 "data/scripts/mauville_man.pory"

# 309 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle:: @ 828E930
# 310 "data/scripts/mauville_man.pory"
	.string "The Save-Happy Trainer$"
# 311 "data/scripts/mauville_man.pory"

# 312 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_SavedGameAction:: @ 828E947
# 313 "data/scripts/mauville_man.pory"
	.string "Saved the game$"
# 314 "data/scripts/mauville_man.pory"

# 315 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_SavedGameStory:: @ 828E956
# 316 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 317 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 318 "data/scripts/mauville_man.pory"
	.string "This Trainer saved the game\n"
# 319 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 320 "data/scripts/mauville_man.pory"
	.string "A more cautious Trainer than\n"
# 321 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} one will never find!$"
# 322 "data/scripts/mauville_man.pory"

# 323 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle:: @ 828E9D7
# 324 "data/scripts/mauville_man.pory"
	.string "The Trendsetter Trainer$"
# 325 "data/scripts/mauville_man.pory"

# 326 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction:: @ 828E9EF
# 327 "data/scripts/mauville_man.pory"
	.string "Started trends$"
# 328 "data/scripts/mauville_man.pory"

# 329 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory:: @ 828E9FE
# 330 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 331 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 332 "data/scripts/mauville_man.pory"
	.string "This Trainer started new trends\n"
# 333 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 334 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} is setting trends for all\n"
# 335 "data/scripts/mauville_man.pory"
	.string "the Hoenn region!$"
# 336 "data/scripts/mauville_man.pory"

# 337 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle:: @ 828EA7D
# 338 "data/scripts/mauville_man.pory"
    .string "The Berry-Planting Trainer$"
# 339 "data/scripts/mauville_man.pory"

# 340 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction:: @ 828EA98
# 341 "data/scripts/mauville_man.pory"
	.string "Planted Berries$"
# 342 "data/scripts/mauville_man.pory"

# 343 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory:: @ 828EAA8
# 344 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 345 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 346 "data/scripts/mauville_man.pory"
	.string "This Trainer planted Berries\n"
# 347 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 348 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} is a legendary lover of\n"
# 349 "data/scripts/mauville_man.pory"
	.string "Berries!$"
# 350 "data/scripts/mauville_man.pory"

# 351 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle:: @ 828EB19
# 352 "data/scripts/mauville_man.pory"
	.string "The Bike-Loving Trainer$"
# 353 "data/scripts/mauville_man.pory"

# 354 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction:: @ 828EB31
# 355 "data/scripts/mauville_man.pory"
	.string "Traded Bikes$"
# 356 "data/scripts/mauville_man.pory"

# 357 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory:: @ 828EB3E
# 358 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 359 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 360 "data/scripts/mauville_man.pory"
	.string "This Trainer swapped Bikes\n"
# 361 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 362 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} must love Bikes deeply\n"
# 363 "data/scripts/mauville_man.pory"
	.string "and passionately!$"
# 364 "data/scripts/mauville_man.pory"

# 365 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle:: @ 828EBB5
# 366 "data/scripts/mauville_man.pory"
	.string "The Interviewed Trainer$"
# 367 "data/scripts/mauville_man.pory"

# 368 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_InterviewsAction:: @ 828EBCD
# 369 "data/scripts/mauville_man.pory"
	.string "Got interviewed$"
# 370 "data/scripts/mauville_man.pory"

# 371 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_InterviewsStory:: @ 828EBDD
# 372 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 373 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 374 "data/scripts/mauville_man.pory"
	.string "This Trainer got interviewed\n"
# 375 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 376 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} must be a Trainer who's\n"
# 377 "data/scripts/mauville_man.pory"
	.string "attracting much attention!$"
# 378 "data/scripts/mauville_man.pory"

# 379 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle:: @ 828EC60
# 380 "data/scripts/mauville_man.pory"
	.string "The Battle-Happy Trainer$"
# 381 "data/scripts/mauville_man.pory"

# 382 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction:: @ 828EC79
# 383 "data/scripts/mauville_man.pory"
	.string "Battled$"
# 384 "data/scripts/mauville_man.pory"

# 385 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory:: @ 828EC81
# 386 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 387 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 388 "data/scripts/mauville_man.pory"
	.string "This Trainer battled {STR_VAR_1} times!\p"
# 389 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} must be a Trainer who can\n"
# 390 "data/scripts/mauville_man.pory"
	.string "never refuse a chance to battle!$"
# 391 "data/scripts/mauville_man.pory"

# 392 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle:: @ 828ED04
# 393 "data/scripts/mauville_man.pory"
	.string "The Pokémon-Catching Trainer$"
# 394 "data/scripts/mauville_man.pory"

# 395 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction:: @ 828ED21
# 396 "data/scripts/mauville_man.pory"
	.string "Caught Pokémon$"
# 397 "data/scripts/mauville_man.pory"

# 398 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory:: @ 828ED30
# 399 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 400 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 401 "data/scripts/mauville_man.pory"
	.string "This Trainer caught\n"
# 402 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} Pokémon!\p"
# 403 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} is a legendary catcher of\n"
# 404 "data/scripts/mauville_man.pory"
	.string "wild Pokémon!$"
# 405 "data/scripts/mauville_man.pory"

# 406 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle:: @ 828EDA1
# 407 "data/scripts/mauville_man.pory"
	.string "The Fishing Trainer$"
# 408 "data/scripts/mauville_man.pory"

# 409 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction:: @ 828EDB5
# 410 "data/scripts/mauville_man.pory"
	.string "Caught Pokémon with a Rod$"
# 411 "data/scripts/mauville_man.pory"

# 412 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory:: @ 828EDCF
# 413 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 414 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 415 "data/scripts/mauville_man.pory"
	.string "This Trainer caught\n"
# 416 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} Pokémon while fishing!\p"
# 417 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} is a legendary fishing\n"
# 418 "data/scripts/mauville_man.pory"
	.string "expert!$"
# 419 "data/scripts/mauville_man.pory"

# 420 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle:: @ 828EE45
# 421 "data/scripts/mauville_man.pory"
	.string "The Egg-Warming Trainer$"
# 422 "data/scripts/mauville_man.pory"

# 423 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction:: @ 828EE5D
# 424 "data/scripts/mauville_man.pory"
	.string "Hatched Eggs$"
# 425 "data/scripts/mauville_man.pory"

# 426 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory:: @ 828EE6A
# 427 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 428 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 429 "data/scripts/mauville_man.pory"
	.string "This Trainer hatched {STR_VAR_1} Pokémon\n"
# 430 "data/scripts/mauville_man.pory"
	.string "from Eggs!\p"
# 431 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} is a legendary warmer\n"
# 432 "data/scripts/mauville_man.pory"
	.string "of Eggs!$"
# 433 "data/scripts/mauville_man.pory"

# 434 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle:: @ 828EEDD
# 435 "data/scripts/mauville_man.pory"
	.string "The Evolver Trainer$"
# 436 "data/scripts/mauville_man.pory"

# 437 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction:: @ 828EEF1
# 438 "data/scripts/mauville_man.pory"
	.string "Evolved Pokémon$"
# 439 "data/scripts/mauville_man.pory"

# 440 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory:: @ 828EF01
# 441 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 442 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 443 "data/scripts/mauville_man.pory"
	.string "This Trainer made {STR_VAR_1} Pokémon\n"
# 444 "data/scripts/mauville_man.pory"
	.string "evolve!\p"
# 445 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} is the ultimate evolver\n"
# 446 "data/scripts/mauville_man.pory"
	.string "of Pokémon!$"
# 447 "data/scripts/mauville_man.pory"

# 448 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle:: @ 828EF73
# 449 "data/scripts/mauville_man.pory"
	.string "The Pokémon Center-Loving Trainer$"
# 450 "data/scripts/mauville_man.pory"

# 451 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction:: @ 828EF95
# 452 "data/scripts/mauville_man.pory"
	.string "Used Pokémon Centers$"
# 453 "data/scripts/mauville_man.pory"

# 454 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory:: @ 828EFAA
# 455 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 456 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 457 "data/scripts/mauville_man.pory"
	.string "This Trainer healed Pokémon\n"
# 458 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times at Pokémon Centers!\p"
# 459 "data/scripts/mauville_man.pory"
	.string "There could be no greater lover of\n"
# 460 "data/scripts/mauville_man.pory"
	.string "Pokémon Centers than {STR_VAR_3}!$"
# 461 "data/scripts/mauville_man.pory"

# 462 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle:: @ 828F045
# 463 "data/scripts/mauville_man.pory"
	.string "The Homebody Trainer$"
# 464 "data/scripts/mauville_man.pory"

# 465 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction:: @ 828F05A
# 466 "data/scripts/mauville_man.pory"
	.string "Rested Pokémon at home$"
# 467 "data/scripts/mauville_man.pory"

# 468 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory:: @ 828F071
# 469 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 470 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 471 "data/scripts/mauville_man.pory"
	.string "This Trainer healed Pokémon\n"
# 472 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times at home!\p"
# 473 "data/scripts/mauville_man.pory"
	.string "There could be no more of a homebody\n"
# 474 "data/scripts/mauville_man.pory"
	.string "than {STR_VAR_3}!$"
# 475 "data/scripts/mauville_man.pory"

# 476 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle:: @ 828F0F3
# 477 "data/scripts/mauville_man.pory"
	.string "The Safari-Loving Trainer$"
# 478 "data/scripts/mauville_man.pory"

# 479 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction:: @ 828F10D
# 480 "data/scripts/mauville_man.pory"
	.string "Entered the Safari Zone$"
# 481 "data/scripts/mauville_man.pory"

# 482 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory:: @ 828F125
# 483 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 484 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 485 "data/scripts/mauville_man.pory"
	.string "This Trainer went into the Safari Zone\n"
# 486 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 487 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} is a Trainer whose wild side\n"
# 488 "data/scripts/mauville_man.pory"
	.string "must come out in the Safari Zone!$"
# 489 "data/scripts/mauville_man.pory"

# 490 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle:: @ 828F1BE
# 491 "data/scripts/mauville_man.pory"
	.string "The Cut-Frenzy Trainer$"
# 492 "data/scripts/mauville_man.pory"

# 493 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedCutAction:: @ 828F1D5
# 494 "data/scripts/mauville_man.pory"
	.string "Used Cut$"
# 495 "data/scripts/mauville_man.pory"

# 496 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedCutStory:: @ 828F1DE
# 497 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 498 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 499 "data/scripts/mauville_man.pory"
	.string "This Trainer used Cut\n"
# 500 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 501 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} is a Trainer who just must\n"
# 502 "data/scripts/mauville_man.pory"
	.string "love to Cut!$"
# 503 "data/scripts/mauville_man.pory"

# 504 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle:: @ 828F24F
# 505 "data/scripts/mauville_man.pory"
	.string "The Rock-Smashing Trainer$"
# 506 "data/scripts/mauville_man.pory"

# 507 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction:: @ 828F269
# 508 "data/scripts/mauville_man.pory"
	.string "Smashed rocks$"
# 509 "data/scripts/mauville_man.pory"

# 510 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory:: @ 828F277
# 511 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 512 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 513 "data/scripts/mauville_man.pory"
	.string "This Trainer used Rock Smash\n"
# 514 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 515 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} must be a Trainer who\n"
# 516 "data/scripts/mauville_man.pory"
	.string "can't leave a stone unsmashed!$"
# 517 "data/scripts/mauville_man.pory"

# 518 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle:: @ 828F2FC
# 519 "data/scripts/mauville_man.pory"
	.string "The Move-Loving Trainer$"
# 520 "data/scripts/mauville_man.pory"

# 521 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction:: @ 828F314
# 522 "data/scripts/mauville_man.pory"
	.string "Moved the Secret Base$"
# 523 "data/scripts/mauville_man.pory"

# 524 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory:: @ 828F32A
# 525 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 526 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 527 "data/scripts/mauville_man.pory"
	.string "This Trainer moved the Secret Base\n"
# 528 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 529 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} is a Trainer who loves\n"
# 530 "data/scripts/mauville_man.pory"
	.string "to move houses often!$"
# 531 "data/scripts/mauville_man.pory"

# 532 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle:: @ 828F3AD
# 533 "data/scripts/mauville_man.pory"
	.string "The Splash-Happy Trainer$"
# 534 "data/scripts/mauville_man.pory"

# 535 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction:: @ 828F3C6
# 536 "data/scripts/mauville_man.pory"
	.string "Used Splash$"
# 537 "data/scripts/mauville_man.pory"

# 538 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory:: @ 828F3D2
# 539 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 540 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 541 "data/scripts/mauville_man.pory"
	.string "This Trainer used Splash\n"
# 542 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 543 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} is a Trainer who must love\n"
# 544 "data/scripts/mauville_man.pory"
	.string "Splashing around!$"
# 545 "data/scripts/mauville_man.pory"

# 546 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle:: @ 828F44B
# 547 "data/scripts/mauville_man.pory"
	.string "The Tenacious Trainer$"
# 548 "data/scripts/mauville_man.pory"

# 549 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction:: @ 828F461
# 550 "data/scripts/mauville_man.pory"
	.string "Resorted to using Struggle$"
# 551 "data/scripts/mauville_man.pory"

# 552 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory:: @ 828F47C
# 553 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 554 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 555 "data/scripts/mauville_man.pory"
	.string "This Trainer had to rely on Struggle\n"
# 556 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 557 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} is a tenacious Trainer\n"
# 558 "data/scripts/mauville_man.pory"
	.string "who never gives in to adversity!$"
# 559 "data/scripts/mauville_man.pory"

# 560 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle:: @ 828F50C
# 561 "data/scripts/mauville_man.pory"
	.string "The Slot Champ$"
# 562 "data/scripts/mauville_man.pory"

# 563 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction:: @ 828F51B
# 564 "data/scripts/mauville_man.pory"
	.string "Won the jackpot on the Slots$"
# 565 "data/scripts/mauville_man.pory"

# 566 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory:: @ 828F538
# 567 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 568 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 569 "data/scripts/mauville_man.pory"
	.string "This Trainer won the jackpot on\n"
# 570 "data/scripts/mauville_man.pory"
	.string "the Slots {STR_VAR_1} times.\p"
# 571 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} is a Trainer who was lucky\n"
# 572 "data/scripts/mauville_man.pory"
	.string "on the Slots!$"
# 573 "data/scripts/mauville_man.pory"

# 574 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle:: @ 828F5BE
# 575 "data/scripts/mauville_man.pory"
	.string "The Roulette Champ$"
# 576 "data/scripts/mauville_man.pory"

# 577 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction:: @ 828F5D1
# 578 "data/scripts/mauville_man.pory"
	.string "Had consecutive Roulette wins of$"
# 579 "data/scripts/mauville_man.pory"

# 580 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory:: @ 828F5F2
# 581 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 582 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 583 "data/scripts/mauville_man.pory"
	.string "This Trainer won in Roulette\n"
# 584 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times in a row.\p"
# 585 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} was lucky when the ball\n"
# 586 "data/scripts/mauville_man.pory"
	.string "bounced in Roulette!$"
# 587 "data/scripts/mauville_man.pory"

# 588 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle:: @ 828F678
# 589 "data/scripts/mauville_man.pory"
	.string "The Battle Tower Challenger$"
# 590 "data/scripts/mauville_man.pory"

# 591 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction:: @ 828F694
# 592 "data/scripts/mauville_man.pory"
	.string "Took the Battle Tower challenge$"
# 593 "data/scripts/mauville_man.pory"

# 594 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory:: @ 828F6B4
# 595 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 596 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 597 "data/scripts/mauville_man.pory"
	.string "This Trainer took the Battle Tower\n"
# 598 "data/scripts/mauville_man.pory"
	.string "challenge {STR_VAR_1} times!\p"
# 599 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} is a Trainer who aspires\n"
# 600 "data/scripts/mauville_man.pory"
	.string "for excellence in the Battle Tower!$"
# 601 "data/scripts/mauville_man.pory"

# 602 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle:: @ 828F751
# 603 "data/scripts/mauville_man.pory"
	.string "The Blend-Loving Trainer$"
# 604 "data/scripts/mauville_man.pory"

# 605 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction:: @ 828F76A
# 606 "data/scripts/mauville_man.pory"
	.string "Made {POKEBLOCK}s$"
# 607 "data/scripts/mauville_man.pory"

# 608 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory:: @ 828F776
# 609 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 610 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 611 "data/scripts/mauville_man.pory"
	.string "This Trainer made {POKEBLOCK}s\n"
# 612 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 613 "data/scripts/mauville_man.pory"
	.string "There is none better at using a Berry\n"
# 614 "data/scripts/mauville_man.pory"
	.string "Blender than {STR_VAR_3}!$"
# 615 "data/scripts/mauville_man.pory"

# 616 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle:: @ 828F7F6
# 617 "data/scripts/mauville_man.pory"
	.string "The Contest-Loving Trainer$"
# 618 "data/scripts/mauville_man.pory"

# 619 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction:: @ 828F811
# 620 "data/scripts/mauville_man.pory"
	.string "Entered Contests$"
# 621 "data/scripts/mauville_man.pory"

# 622 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory:: @ 828F822
# 623 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 624 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 625 "data/scripts/mauville_man.pory"
	.string "This Trainer entered Contests\n"
# 626 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 627 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} must love showing off\n"
# 628 "data/scripts/mauville_man.pory"
	.string "Pokémon to others!$"
# 629 "data/scripts/mauville_man.pory"

# 630 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle:: @ 828F89C
# 631 "data/scripts/mauville_man.pory"
	.string "The Contest Master$"
# 632 "data/scripts/mauville_man.pory"

# 633 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_WonContestsAction:: @ 828F8AF
# 634 "data/scripts/mauville_man.pory"
	.string "Won Contests$"
# 635 "data/scripts/mauville_man.pory"

# 636 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_WonContestsStory:: @ 828F8BC
# 637 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 638 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 639 "data/scripts/mauville_man.pory"
	.string "This Trainer won Contests\n"
# 640 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 641 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} must be an incredible\n"
# 642 "data/scripts/mauville_man.pory"
	.string "Contest master!$"
# 643 "data/scripts/mauville_man.pory"

# 644 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle:: @ 828F92F
# 645 "data/scripts/mauville_man.pory"
	.string "The Happy Shopper$"
# 646 "data/scripts/mauville_man.pory"

# 647 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction:: @ 828F941
# 648 "data/scripts/mauville_man.pory"
	.string "Shopped$"
# 649 "data/scripts/mauville_man.pory"

# 650 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory:: @ 828F949
# 651 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 652 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 653 "data/scripts/mauville_man.pory"
	.string "This Trainer bought items in shops\n"
# 654 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 655 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} must be one of those\n"
# 656 "data/scripts/mauville_man.pory"
	.string "people who are born to shop.$"
# 657 "data/scripts/mauville_man.pory"

# 658 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle:: @ 828F9D1
# 659 "data/scripts/mauville_man.pory"
	.string "The Item-Finding Trainer$"
# 660 "data/scripts/mauville_man.pory"

# 661 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction:: @ 828F9EA
# 662 "data/scripts/mauville_man.pory"
	.string "Used an Itemfinder$"
# 663 "data/scripts/mauville_man.pory"

# 664 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory:: @ 828F9FD
# 665 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 666 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 667 "data/scripts/mauville_man.pory"
	.string "This Trainer used an Itemfinder\n"
# 668 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 669 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} must enjoy scouring the\n"
# 670 "data/scripts/mauville_man.pory"
	.string "ground for hidden items!$"
# 671 "data/scripts/mauville_man.pory"

# 672 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle:: @ 828FA81
# 673 "data/scripts/mauville_man.pory"
	.string "The Rain-Soaked Trainer$"
# 674 "data/scripts/mauville_man.pory"

# 675 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction:: @ 828FA99
# 676 "data/scripts/mauville_man.pory"
	.string "Got rained on$"
# 677 "data/scripts/mauville_man.pory"

# 678 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory:: @ 828FAA7
# 679 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 680 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 681 "data/scripts/mauville_man.pory"
	.string "This Trainer got soaked by rain\n"
# 682 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 683 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3}'s charisma must even\n"
# 684 "data/scripts/mauville_man.pory"
	.string "attract rain!$"
# 685 "data/scripts/mauville_man.pory"

# 686 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle:: @ 828FB1D
# 687 "data/scripts/mauville_man.pory"
	.string "The Avid Pokédex Reader$"
# 688 "data/scripts/mauville_man.pory"

# 689 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction:: @ 828FB35
# 690 "data/scripts/mauville_man.pory"
	.string "Checked a Pokédex$"
# 691 "data/scripts/mauville_man.pory"

# 692 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory:: @ 828FB47
# 693 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 694 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 695 "data/scripts/mauville_man.pory"
	.string "This Trainer checked a Pokédex\n"
# 696 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 697 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} must love inspecting\n"
# 698 "data/scripts/mauville_man.pory"
	.string "Pokémon in a Pokédex!$"
# 699 "data/scripts/mauville_man.pory"

# 700 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle:: @ 828FBC4
# 701 "data/scripts/mauville_man.pory"
	.string "The Ribbon Collector$"
# 702 "data/scripts/mauville_man.pory"

# 703 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction:: @ 828FBD9
# 704 "data/scripts/mauville_man.pory"
	.string "Received Ribbons$"
# 705 "data/scripts/mauville_man.pory"

# 706 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory:: @ 828FBEA
# 707 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 708 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 709 "data/scripts/mauville_man.pory"
	.string "This Trainer received Ribbons\n"
# 710 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 711 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} must be a Trainer who\n"
# 712 "data/scripts/mauville_man.pory"
	.string "loves to collect Ribbons!$"
# 713 "data/scripts/mauville_man.pory"

# 714 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle:: @ 828FC6B
# 715 "data/scripts/mauville_man.pory"
	.string "The Ledge-Jumping Trainer$"
# 716 "data/scripts/mauville_man.pory"

# 717 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction:: @ 828FC85
# 718 "data/scripts/mauville_man.pory"
	.string "Jumped down ledges$"
# 719 "data/scripts/mauville_man.pory"

# 720 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory:: @ 828FC98
# 721 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 722 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 723 "data/scripts/mauville_man.pory"
	.string "This Trainer jumped down ledges\n"
# 724 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 725 "data/scripts/mauville_man.pory"
	.string "If there's a ledge to be jumped,\n"
# 726 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} can't ignore it!$"
# 727 "data/scripts/mauville_man.pory"

# 728 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle:: @ 828FD1D
# 729 "data/scripts/mauville_man.pory"
	.string "The Legendary TV Viewer$"
# 730 "data/scripts/mauville_man.pory"

# 731 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction:: @ 828FD35
# 732 "data/scripts/mauville_man.pory"
	.string "Watched TV$"
# 733 "data/scripts/mauville_man.pory"

# 734 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory:: @ 828FD40
# 735 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 736 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 737 "data/scripts/mauville_man.pory"
	.string "This Trainer watched TV\n"
# 738 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 739 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} must love watching TV!$"
# 740 "data/scripts/mauville_man.pory"

# 741 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle:: @ 828FDA2
# 742 "data/scripts/mauville_man.pory"
	.string "The Time-Conscious Trainer$"
# 743 "data/scripts/mauville_man.pory"

# 744 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction:: @ 828FDBD
# 745 "data/scripts/mauville_man.pory"
	.string "Checked the time$"
# 746 "data/scripts/mauville_man.pory"

# 747 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory:: @ 828FDCE
# 748 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 749 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 750 "data/scripts/mauville_man.pory"
	.string "This Trainer checked the time\n"
# 751 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 752 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} must be a punctual Trainer\n"
# 753 "data/scripts/mauville_man.pory"
	.string "who's conscious of the time.$"
# 754 "data/scripts/mauville_man.pory"

# 755 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle:: @ 828FE57
# 756 "data/scripts/mauville_man.pory"
	.string "The Pokémon Lottery Wizard$"
# 757 "data/scripts/mauville_man.pory"

# 758 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction:: @ 828FE72
# 759 "data/scripts/mauville_man.pory"
	.string "Won Pokémon Lotteries$"
# 760 "data/scripts/mauville_man.pory"

# 761 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory:: @ 828FE88
# 762 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 763 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 764 "data/scripts/mauville_man.pory"
	.string "This Trainer won Pokémon Lotteries\n"
# 765 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 766 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} must have many friends\n"
# 767 "data/scripts/mauville_man.pory"
	.string "to trade Pokémon with!$"
# 768 "data/scripts/mauville_man.pory"

# 769 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle:: @ 828FF0C
# 770 "data/scripts/mauville_man.pory"
	.string "The Day Care-Using Trainer$"
# 771 "data/scripts/mauville_man.pory"

# 772 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction:: @ 828FF27
# 773 "data/scripts/mauville_man.pory"
	.string "Left Pokémon at the Day Care$"
# 774 "data/scripts/mauville_man.pory"

# 775 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory:: @ 828FF44
# 776 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 777 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 778 "data/scripts/mauville_man.pory"
	.string "This Trainer left Pokémon with the\n"
# 779 "data/scripts/mauville_man.pory"
	.string "Day Care {STR_VAR_1} times!\p"
# 780 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} must be a real go-getter\n"
# 781 "data/scripts/mauville_man.pory"
	.string "who raises Pokémon aggressively!$"
# 782 "data/scripts/mauville_man.pory"

# 783 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle:: @ 828FFDD
# 784 "data/scripts/mauville_man.pory"
	.string "The Cable Car-Loving Trainer$"
# 785 "data/scripts/mauville_man.pory"

# 786 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction:: @ 828FFFA
# 787 "data/scripts/mauville_man.pory"
	.string "Rode the Cable Car$"
# 788 "data/scripts/mauville_man.pory"

# 789 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory:: @ 829000D
# 790 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 791 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 792 "data/scripts/mauville_man.pory"
	.string "This Trainer rode the Cable Car\n"
# 793 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 794 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} must be a busy Trainer\n"
# 795 "data/scripts/mauville_man.pory"
	.string "who's up and down all the time!$"
# 796 "data/scripts/mauville_man.pory"

# 797 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle:: @ 8290097
# 798 "data/scripts/mauville_man.pory"
	.string "The Hot Spring-Loving Trainer$"
# 799 "data/scripts/mauville_man.pory"

# 800 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction:: @ 82900B5
# 801 "data/scripts/mauville_man.pory"
	.string "Bathed in hot springs$"
# 802 "data/scripts/mauville_man.pory"

# 803 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory:: @ 82900CB
# 804 "data/scripts/mauville_man.pory"
	.string "This is a tale of a Trainer\n"
# 805 "data/scripts/mauville_man.pory"
	.string "named {STR_VAR_3}.\p"
# 806 "data/scripts/mauville_man.pory"
	.string "This Trainer bathed in hot springs\n"
# 807 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_1} times!\p"
# 808 "data/scripts/mauville_man.pory"
	.string "{STR_VAR_3} must be a Trainer with\n"
# 809 "data/scripts/mauville_man.pory"
	.string "baby-smooth skin!$"
# 810 "data/scripts/mauville_man.pory"

# 811 "data/scripts/mauville_man.pory"

# 812 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_Storyteller:: @ 829014A
# 813 "data/scripts/mauville_man.pory"
	lock
# 814 "data/scripts/mauville_man.pory"
	faceplayer
# 815 "data/scripts/mauville_man.pory"
	setvar VAR_0x8008, 0
# 816 "data/scripts/mauville_man.pory"
	setvar VAR_0x8009, 0
# 817 "data/scripts/mauville_man.pory"
	setvar VAR_0x800A, 0
# 818 "data/scripts/mauville_man.pory"
	setvar VAR_0x800B, 0
# 819 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
# 820 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, NO
# 821 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
# 822 "data/scripts/mauville_man.pory"
	specialvar VAR_RESULT, ScrSpecial_StorytellerGetFreeStorySlot
# 823 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, 0
# 824 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
# 825 "data/scripts/mauville_man.pory"
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
# 826 "data/scripts/mauville_man.pory"
	waitmessage
# 827 "data/scripts/mauville_man.pory"
	special ScrSpecial_StorytellerStoryListMenu
# 828 "data/scripts/mauville_man.pory"
	waitstate
# 829 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, 0
# 830 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
# 831 "data/scripts/mauville_man.pory"
	setvar VAR_0x8008, 1
# 832 "data/scripts/mauville_man.pory"
	special ScrSpecial_StorytellerDisplayStory
# 833 "data/scripts/mauville_man.pory"
	waitmessage
# 834 "data/scripts/mauville_man.pory"
	waitbuttonpress
# 835 "data/scripts/mauville_man.pory"
	specialvar VAR_RESULT, ScrSpecial_StorytellerUpdateStat
# 836 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, 0
# 837 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
# 838 "data/scripts/mauville_man.pory"
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
# 839 "data/scripts/mauville_man.pory"

# 840 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection:: @ 82901B7
# 841 "data/scripts/mauville_man.pory"
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
# 842 "data/scripts/mauville_man.pory"
	end
# 843 "data/scripts/mauville_man.pory"

# 844 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales:: @ 82901BD
# 845 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
# 846 "data/scripts/mauville_man.pory"
	specialvar VAR_RESULT, ScrSpecial_HasStorytellerAlreadyRecorded
# 847 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, TRUE
# 848 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
# 849 "data/scripts/mauville_man.pory"
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales
# 850 "data/scripts/mauville_man.pory"

# 851 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales:: @ 82901DA
# 852 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
# 853 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales:: @ 82901E2
# 854 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
# 855 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, NO
# 856 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
# 857 "data/scripts/mauville_man.pory"
	specialvar VAR_RESULT, ScrSpecial_StorytellerInitializeRandomStat
# 858 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, 1
# 859 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
# 860 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
# 861 "data/scripts/mauville_man.pory"
	release
# 862 "data/scripts/mauville_man.pory"
	end
# 863 "data/scripts/mauville_man.pory"

# 864 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale:: @ 829020F
# 865 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
# 866 "data/scripts/mauville_man.pory"
	release
# 867 "data/scripts/mauville_man.pory"
	end
# 868 "data/scripts/mauville_man.pory"

# 869 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller:: @ 8290219
# 870 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
# 871 "data/scripts/mauville_man.pory"
	release
# 872 "data/scripts/mauville_man.pory"
	end
# 873 "data/scripts/mauville_man.pory"

# 874 "data/scripts/mauville_man.pory"
@ Unused
# 875 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix:: @ 8290223
# 876 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
# 877 "data/scripts/mauville_man.pory"
	release
# 878 "data/scripts/mauville_man.pory"
	end
# 879 "data/scripts/mauville_man.pory"

# 880 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd:: @ 829022D
# 881 "data/scripts/mauville_man.pory"
	release
# 882 "data/scripts/mauville_man.pory"
	end
# 883 "data/scripts/mauville_man.pory"

# 884 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_HearMyStory: @ 829022F
# 885 "data/scripts/mauville_man.pory"
	.string "I'm Giddy!\n"
# 886 "data/scripts/mauville_man.pory"
	.string "I have a scintillating story for you!\p"
# 887 "data/scripts/mauville_man.pory"
	.string "Would you like to hear my story?$"
# 888 "data/scripts/mauville_man.pory"

# 889 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues: @ 8290281
# 890 "data/scripts/mauville_man.pory"
	.string "Oh…\n"
# 891 "data/scripts/mauville_man.pory"
	.string "You've left me feeling the blues…$"
# 892 "data/scripts/mauville_man.pory"

# 893 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking: @ 82902A7
# 894 "data/scripts/mauville_man.pory"
	.string "Also, I was thinking…$"
# 895 "data/scripts/mauville_man.pory"

# 896 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain: @ 82902BD
# 897 "data/scripts/mauville_man.pory"
	.string "That's about it, I think…\p"
# 898 "data/scripts/mauville_man.pory"
	.string "We should chat again!\n"
# 899 "data/scripts/mauville_man.pory"
	.string "Bye-bye!$"
# 900 "data/scripts/mauville_man.pory"

# 901 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_Giddy:: @ 82902F6
# 902 "data/scripts/mauville_man.pory"
	lock
# 903 "data/scripts/mauville_man.pory"
	faceplayer
# 904 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
# 905 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, YES
# 906 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
# 907 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, NO
# 908 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
# 909 "data/scripts/mauville_man.pory"
	end
# 910 "data/scripts/mauville_man.pory"

# 911 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale:: @ 8290317
# 912 "data/scripts/mauville_man.pory"
	special ScrSpecial_GiddyShouldTellAnotherTale
# 913 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, TRUE
# 914 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
# 915 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, FALSE
# 916 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
# 917 "data/scripts/mauville_man.pory"
	end
# 918 "data/scripts/mauville_man.pory"

# 919 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale:: @ 8290331
# 920 "data/scripts/mauville_man.pory"
	special ScrSpecial_GiddyShouldTellAnotherTale
# 921 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, TRUE
# 922 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
# 923 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, FALSE
# 924 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
# 925 "data/scripts/mauville_man.pory"
	end
# 926 "data/scripts/mauville_man.pory"

# 927 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale:: @ 829034B
# 928 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
# 929 "data/scripts/mauville_man.pory"
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
# 930 "data/scripts/mauville_man.pory"
	end
# 931 "data/scripts/mauville_man.pory"

# 932 "data/scripts/mauville_man.pory"
@ Regardless of whether yes or no is selected below, Giddy will continue to tell stories until he's told 10
# 933 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale:: @ 8290359
# 934 "data/scripts/mauville_man.pory"
	special ScrSpecial_GenerateGiddyLine
# 935 "data/scripts/mauville_man.pory"
	special ShowFieldMessageStringVar4
# 936 "data/scripts/mauville_man.pory"
	waitmessage
# 937 "data/scripts/mauville_man.pory"
	yesnobox 20, 8
# 938 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, 1
# 939 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
# 940 "data/scripts/mauville_man.pory"
	compare VAR_RESULT, 0
# 941 "data/scripts/mauville_man.pory"
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
# 942 "data/scripts/mauville_man.pory"
	end
# 943 "data/scripts/mauville_man.pory"

# 944 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy:: @ 829037A
# 945 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
# 946 "data/scripts/mauville_man.pory"
	release
# 947 "data/scripts/mauville_man.pory"
	end
# 948 "data/scripts/mauville_man.pory"

# 949 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales:: @ 8290384
# 950 "data/scripts/mauville_man.pory"
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
# 951 "data/scripts/mauville_man.pory"
	release
# 952 "data/scripts/mauville_man.pory"
	end
# 953 "data/scripts/mauville_man.pory"

# 954 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong: @ 829038E
# 955 "data/scripts/mauville_man.pory"
	.string "Hi, I'm the Bard.\n"
# 956 "data/scripts/mauville_man.pory"
	.string "Would you like to hear my song?$"
# 957 "data/scripts/mauville_man.pory"

# 958 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1: @ 82903C0
# 959 "data/scripts/mauville_man.pory"
	.string "Oh…\n"
# 960 "data/scripts/mauville_man.pory"
	.string "You've left me feeling the blues…$"
# 961 "data/scripts/mauville_man.pory"

# 962 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers: @ 82903E6
# 963 "data/scripts/mauville_man.pory"
	.string "Oh, what a moving song…\n"
# 964 "data/scripts/mauville_man.pory"
	.string "I wish I could play it for others…$"
# 965 "data/scripts/mauville_man.pory"

# 966 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics: @ 8290421
# 967 "data/scripts/mauville_man.pory"
	.string "So?\n"
# 968 "data/scripts/mauville_man.pory"
	.string "How do you like my song?\p"
# 969 "data/scripts/mauville_man.pory"
	.string "But I'm none too happy about\n"
# 970 "data/scripts/mauville_man.pory"
	.string "the lyrics.\p"
# 971 "data/scripts/mauville_man.pory"
	.string "How would you like to write some\n"
# 972 "data/scripts/mauville_man.pory"
	.string "new lyrics for me?$"
# 973 "data/scripts/mauville_man.pory"

# 974 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2: @ 829049B
# 975 "data/scripts/mauville_man.pory"
	.string "Oh…\n"
# 976 "data/scripts/mauville_man.pory"
	.string "You've left me feeling the blues…$"
# 977 "data/scripts/mauville_man.pory"

# 978 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou: @ 82904C1
# 979 "data/scripts/mauville_man.pory"
	.string "Thank you kindly!\n"
# 980 "data/scripts/mauville_man.pory"
	.string "Let me sing it for you.$"
# 981 "data/scripts/mauville_man.pory"

# 982 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo: @ 82904EB
# 983 "data/scripts/mauville_man.pory"
	.string "Was that how you wanted your song\n"
# 984 "data/scripts/mauville_man.pory"
	.string "to go?$"
# 985 "data/scripts/mauville_man.pory"

# 986 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile: @ 8290514
# 987 "data/scripts/mauville_man.pory"
	.string "Okay! That's it, then.\n"
# 988 "data/scripts/mauville_man.pory"
	.string "I'll sing this song for a while.$"
# 989 "data/scripts/mauville_man.pory"

# 990 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening: @ 829054C
# 991 "data/scripts/mauville_man.pory"
	.string "Hey, yo! They call me the Hipster.\n"
# 992 "data/scripts/mauville_man.pory"
	.string "I'll teach you what's hip and happening.$"
# 993 "data/scripts/mauville_man.pory"

# 994 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou: @ 8290598
# 995 "data/scripts/mauville_man.pory"
	.string "But, hey, I taught you what's hip and\n"
# 996 "data/scripts/mauville_man.pory"
	.string "happening already.\p"
# 997 "data/scripts/mauville_man.pory"
	.string "I'd like to spread the good word to\n"
# 998 "data/scripts/mauville_man.pory"
	.string "other folks.$"
# 999 "data/scripts/mauville_man.pory"

# 1000 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach: @ 8290602
# 1001 "data/scripts/mauville_man.pory"
	.string "But, hey, you already know a lot about\n"
# 1002 "data/scripts/mauville_man.pory"
	.string "what's hip and happening.\p"
# 1003 "data/scripts/mauville_man.pory"
	.string "I've got nothing new to teach you!$"
# 1004 "data/scripts/mauville_man.pory"

# 1005 "data/scripts/mauville_man.pory"
MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase: @ 8290666
# 1006 "data/scripts/mauville_man.pory"
	.string "Hey, have you heard about\n"
# 1007 "data/scripts/mauville_man.pory"
	.string "“{STR_VAR_1}”?\p"
# 1008 "data/scripts/mauville_man.pory"
	.string "What's it mean? Well…\n"
# 1009 "data/scripts/mauville_man.pory"
	.string "Ask your daddy or mommy, okay?$"
