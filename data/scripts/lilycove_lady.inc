# 1 "data/scripts/lilycove_lady.pory"

# 2 "data/scripts/lilycove_lady.pory"
.set LOCALID_LILYCOVE_LADY, 4
# 3 "data/scripts/lilycove_lady.pory"
.set LOCALID_LADYS_MON, 5
# 4 "data/scripts/lilycove_lady.pory"

# 5 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_LilycoveLady:: @ 82A836B
# 6 "data/scripts/lilycove_lady.pory"
    special Script_GetLilycoveLadyId
# 7 "data/scripts/lilycove_lady.pory"
    switch VAR_RESULT
# 8 "data/scripts/lilycove_lady.pory"
    case LILYCOVE_LADY_QUIZ, LilycoveCity_PokemonCenter_1F_EventScript_QuizLady
# 9 "data/scripts/lilycove_lady.pory"
    case LILYCOVE_LADY_FAVOR, LilycoveCity_PokemonCenter_1F_EventScript_FavorLady
# 10 "data/scripts/lilycove_lady.pory"
    case LILYCOVE_LADY_CONTEST, LilycoveCity_PokemonCenter_1F_EventScript_ContestLady
# 11 "data/scripts/lilycove_lady.pory"
    end
# 12 "data/scripts/lilycove_lady.pory"

# 13 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_FavorLady:: @ 82A8395
# 14 "data/scripts/lilycove_lady.pory"
    lock
# 15 "data/scripts/lilycove_lady.pory"
    faceplayer
# 16 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady, MSGBOX_DEFAULT
# 17 "data/scripts/lilycove_lady.pory"
    specialvar VAR_RESULT, GetFavorLadyState
# 18 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, LILYCOVE_LADY_STATE_READY
# 19 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady
# 20 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED
# 21 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted
# 22 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE
# 23 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
# 24 "data/scripts/lilycove_lady.pory"
    end
# 25 "data/scripts/lilycove_lady.pory"

# 26 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted:: @ 82A83C6
# 27 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime, MSGBOX_DEFAULT
# 28 "data/scripts/lilycove_lady.pory"
    release
# 29 "data/scripts/lilycove_lady.pory"
    end
# 30 "data/scripts/lilycove_lady.pory"

# 31 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady:: @ 82A83D0
# 32 "data/scripts/lilycove_lady.pory"
    special BufferFavorLadyRequest
# 33 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing, MSGBOX_DEFAULT
# 34 "data/scripts/lilycove_lady.pory"
    specialvar VAR_RESULT, HasAnotherPlayerGivenFavorLadyItem
# 35 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, FALSE
# 36 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
# 37 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, TRUE
# 38 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem
# 39 "data/scripts/lilycove_lady.pory"
    end
# 40 "data/scripts/lilycove_lady.pory"

# 41 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem:: @ 82A83F7
# 42 "data/scripts/lilycove_lady.pory"
    special BufferFavorLadyItemName
# 43 "data/scripts/lilycove_lady.pory"
    special BufferFavorLadyPlayerName
# 44 "data/scripts/lilycove_lady.pory"
    specialvar VAR_RESULT, DidFavorLadyLikeItem
# 45 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, FALSE
# 46 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing
# 47 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, TRUE
# 48 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing
# 49 "data/scripts/lilycove_lady.pory"
    end
# 50 "data/scripts/lilycove_lady.pory"

# 51 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing:: @ 82A8419
# 52 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing, MSGBOX_DEFAULT
# 53 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
# 54 "data/scripts/lilycove_lady.pory"
    end
# 55 "data/scripts/lilycove_lady.pory"

# 56 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing:: @ 82A8427
# 57 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing, MSGBOX_DEFAULT
# 58 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
# 59 "data/scripts/lilycove_lady.pory"
    end
# 60 "data/scripts/lilycove_lady.pory"

# 61 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_RequestItem:: @ 82A8435
# 62 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing, MSGBOX_YESNO
# 63 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, NO
# 64 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
# 65 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, YES
# 66 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor
# 67 "data/scripts/lilycove_lady.pory"
    end
# 68 "data/scripts/lilycove_lady.pory"

# 69 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor:: @ 82A8454
# 70 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye, MSGBOX_DEFAULT
# 71 "data/scripts/lilycove_lady.pory"
    release
# 72 "data/scripts/lilycove_lady.pory"
    end
# 73 "data/scripts/lilycove_lady.pory"

# 74 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor:: @ 82A845E
# 75 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe, MSGBOX_DEFAULT
# 76 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
# 77 "data/scripts/lilycove_lady.pory"
    end
# 78 "data/scripts/lilycove_lady.pory"

# 79 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem:: @ 82A846C
# 80 "data/scripts/lilycove_lady.pory"
    fadescreen FADE_TO_BLACK
# 81 "data/scripts/lilycove_lady.pory"
    setvar VAR_RESULT, 0
# 82 "data/scripts/lilycove_lady.pory"
    special Script_FavorLadyOpenBagMenu
# 83 "data/scripts/lilycove_lady.pory"
    waitstate
# 84 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, 0
# 85 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem
# 86 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, 1
# 87 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem
# 88 "data/scripts/lilycove_lady.pory"
    end
# 89 "data/scripts/lilycove_lady.pory"

# 90 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem:: @ 82A848E
# 91 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare, MSGBOX_YESNO
# 92 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, YES
# 93 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
# 94 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, NO
# 95 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
# 96 "data/scripts/lilycove_lady.pory"
    end
# 97 "data/scripts/lilycove_lady.pory"

# 98 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem:: @ 82A84AD
# 99 "data/scripts/lilycove_lady.pory"
    specialvar VAR_RESULT, Script_DoesFavorLadyLikeItem
# 100 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, FALSE
# 101 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem
# 102 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, TRUE
# 103 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem
# 104 "data/scripts/lilycove_lady.pory"
    end
# 105 "data/scripts/lilycove_lady.pory"

# 106 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem:: @ 82A84C9
# 107 "data/scripts/lilycove_lady.pory"
    special BufferFavorLadyRequest
# 108 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt, MSGBOX_DEFAULT
# 109 "data/scripts/lilycove_lady.pory"
    release
# 110 "data/scripts/lilycove_lady.pory"
    end
# 111 "data/scripts/lilycove_lady.pory"

# 112 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem:: @ 82A84D6
# 113 "data/scripts/lilycove_lady.pory"
    specialvar VAR_RESULT, IsFavorLadyThresholdMet
# 114 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, FALSE
# 115 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem
# 116 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, TRUE
# 117 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem
# 118 "data/scripts/lilycove_lady.pory"
    end
# 119 "data/scripts/lilycove_lady.pory"

# 120 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem:: @ 82A84F2
# 121 "data/scripts/lilycove_lady.pory"
    special BufferFavorLadyRequest
# 122 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis, MSGBOX_DEFAULT
# 123 "data/scripts/lilycove_lady.pory"
    release
# 124 "data/scripts/lilycove_lady.pory"
    end
# 125 "data/scripts/lilycove_lady.pory"

# 126 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem:: @ 82A84FF
# 127 "data/scripts/lilycove_lady.pory"
    special BufferFavorLadyRequest
# 128 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis, MSGBOX_DEFAULT
# 129 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
# 130 "data/scripts/lilycove_lady.pory"
    end
# 131 "data/scripts/lilycove_lady.pory"

# 132 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize:: @ 82A8510
# 133 "data/scripts/lilycove_lady.pory"
    setvar VAR_0x8004, 0
# 134 "data/scripts/lilycove_lady.pory"
    specialvar VAR_0x8004, FavorLadyGetPrize
# 135 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn, MSGBOX_DEFAULT
# 136 "data/scripts/lilycove_lady.pory"
    giveitem VAR_0x8004
# 137 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, 0
# 138 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize
# 139 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, 1
# 140 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize
# 141 "data/scripts/lilycove_lady.pory"
    end
# 142 "data/scripts/lilycove_lady.pory"

# 143 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize:: @ 82A8545
# 144 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt, MSGBOX_DEFAULT
# 145 "data/scripts/lilycove_lady.pory"
    release
# 146 "data/scripts/lilycove_lady.pory"
    end
# 147 "data/scripts/lilycove_lady.pory"

# 148 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize:: @ 82A854F
# 149 "data/scripts/lilycove_lady.pory"
    special SetFavorLadyState_Complete
# 150 "data/scripts/lilycove_lady.pory"
    release
# 151 "data/scripts/lilycove_lady.pory"
    end
# 152 "data/scripts/lilycove_lady.pory"

# 153 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_QuizLady:: @ 82A8554
# 154 "data/scripts/lilycove_lady.pory"
    lock
# 155 "data/scripts/lilycove_lady.pory"
    faceplayer
# 156 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady, MSGBOX_DEFAULT
# 157 "data/scripts/lilycove_lady.pory"
    specialvar VAR_RESULT, GetQuizLadyState
# 158 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, LILYCOVE_LADY_STATE_READY
# 159 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz
# 160 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED
# 161 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz
# 162 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE
# 163 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
# 164 "data/scripts/lilycove_lady.pory"
    end
# 165 "data/scripts/lilycove_lady.pory"

# 166 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz:: @ 82A8585
# 167 "data/scripts/lilycove_lady.pory"
    specialvar VAR_RESULT, GetQuizAuthor
# 168 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, QUIZ_AUTHOR_PLAYER
# 169 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
# 170 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, QUIZ_AUTHOR_OTHER_PLAYER
# 171 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady
# 172 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, QUIZ_AUTHOR_LADY
# 173 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady
# 174 "data/scripts/lilycove_lady.pory"
    end
# 175 "data/scripts/lilycove_lady.pory"

# 176 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz:: @ 82A85AC
# 177 "data/scripts/lilycove_lady.pory"
    specialvar VAR_RESULT, IsQuizLadyWaitingForChallenger
# 178 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, FALSE
# 179 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
# 180 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, TRUE
# 181 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
# 182 "data/scripts/lilycove_lady.pory"
    end
# 183 "data/scripts/lilycove_lady.pory"

# 184 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz:: @ 82A85C8
# 185 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz, MSGBOX_DEFAULT
# 186 "data/scripts/lilycove_lady.pory"
    release
# 187 "data/scripts/lilycove_lady.pory"
    end
# 188 "data/scripts/lilycove_lady.pory"

# 189 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady:: @ 82A85D2
# 190 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
# 191 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
# 192 "data/scripts/lilycove_lady.pory"
    end
# 193 "data/scripts/lilycove_lady.pory"

# 194 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady:: @ 82A85E0
# 195 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
# 196 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
# 197 "data/scripts/lilycove_lady.pory"
    end
# 198 "data/scripts/lilycove_lady.pory"

# 199 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz:: @ 82A85EE
# 200 "data/scripts/lilycove_lady.pory"
    setvar VAR_0x8004, 0
# 201 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge, MSGBOX_YESNO
# 202 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, YES
# 203 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
# 204 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, NO
# 205 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz
# 206 "data/scripts/lilycove_lady.pory"
    end
# 207 "data/scripts/lilycove_lady.pory"

# 208 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz:: @ 82A8612
# 209 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_HowBoringBye, MSGBOX_DEFAULT
# 210 "data/scripts/lilycove_lady.pory"
    release
# 211 "data/scripts/lilycove_lady.pory"
    end
# 212 "data/scripts/lilycove_lady.pory"

# 213 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz:: @ 82A861C
# 214 "data/scripts/lilycove_lady.pory"
    special ClearQuizLadyPlayerAnswer
# 215 "data/scripts/lilycove_lady.pory"
    compare VAR_0x8004, 0
# 216 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion
# 217 "data/scripts/lilycove_lady.pory"
    compare VAR_0x8004, EASY_CHAT_TYPE_QUIZ_ANSWER
# 218 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer
# 219 "data/scripts/lilycove_lady.pory"

# 220 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState:: @ 82A8635
# 221 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, 0
# 222 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz
# 223 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, 1
# 224 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse
# 225 "data/scripts/lilycove_lady.pory"
    end
# 226 "data/scripts/lilycove_lady.pory"

# 227 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion:: @ 82A864C
# 228 "data/scripts/lilycove_lady.pory"
    special QuizLadyShowQuizQuestion
# 229 "data/scripts/lilycove_lady.pory"
    waitstate
# 230 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
# 231 "data/scripts/lilycove_lady.pory"
    end
# 232 "data/scripts/lilycove_lady.pory"

# 233 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer:: @ 82A8656
# 234 "data/scripts/lilycove_lady.pory"
    special QuizLadyGetPlayerAnswer
# 235 "data/scripts/lilycove_lady.pory"
    waitstate
# 236 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
# 237 "data/scripts/lilycove_lady.pory"
    end
# 238 "data/scripts/lilycove_lady.pory"

# 239 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz:: @ 82A8660
# 240 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit, MSGBOX_YESNO
# 241 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, YES
# 242 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz
# 243 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, NO
# 244 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
# 245 "data/scripts/lilycove_lady.pory"
    end
# 246 "data/scripts/lilycove_lady.pory"

# 247 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz:: @ 82A867F
# 248 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime, MSGBOX_DEFAULT
# 249 "data/scripts/lilycove_lady.pory"
    release
# 250 "data/scripts/lilycove_lady.pory"
    end
# 251 "data/scripts/lilycove_lady.pory"

# 252 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse:: @ 82A8689
# 253 "data/scripts/lilycove_lady.pory"
    special SetQuizLadyState_Complete
# 254 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer, MSGBOX_DEFAULT
# 255 "data/scripts/lilycove_lady.pory"
    specialvar VAR_RESULT, IsQuizAnswerCorrect
# 256 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, FALSE
# 257 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse
# 258 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, TRUE
# 259 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse
# 260 "data/scripts/lilycove_lady.pory"
    end
# 261 "data/scripts/lilycove_lady.pory"

# 262 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse:: @ 82A86B0
# 263 "data/scripts/lilycove_lady.pory"
    playse SE_SUCCESS
# 264 "data/scripts/lilycove_lady.pory"
    delay 10
# 265 "data/scripts/lilycove_lady.pory"
    playse SE_SUCCESS
# 266 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRight, MSGBOX_DEFAULT
# 267 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
# 268 "data/scripts/lilycove_lady.pory"
    end
# 269 "data/scripts/lilycove_lady.pory"

# 270 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse:: @ 82A86C7
# 271 "data/scripts/lilycove_lady.pory"
    special BufferQuizCorrectAnswer
# 272 "data/scripts/lilycove_lady.pory"
    special BufferQuizPrizeName
# 273 "data/scripts/lilycove_lady.pory"
    playse SE_FAILURE
# 274 "data/scripts/lilycove_lady.pory"
    delay 10
# 275 "data/scripts/lilycove_lady.pory"
    playse SE_FAILURE
# 276 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs, MSGBOX_DEFAULT
# 277 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize, MSGBOX_DEFAULT
# 278 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
# 279 "data/scripts/lilycove_lady.pory"
    end
# 280 "data/scripts/lilycove_lady.pory"

# 281 "data/scripts/lilycove_lady.pory"
@ VAR_RESULT is essentially ignored, both jumps are identical
# 282 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize:: @ 82A86EC
# 283 "data/scripts/lilycove_lady.pory"
    specialvar VAR_RESULT, BufferQuizAuthorNameAndCheckIfLady
# 284 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, 1
# 285 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1
# 286 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, 0
# 287 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0
# 288 "data/scripts/lilycove_lady.pory"
    end
# 289 "data/scripts/lilycove_lady.pory"

# 290 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1:: @ 82A8708
# 291 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
# 292 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
# 293 "data/scripts/lilycove_lady.pory"
    end
# 294 "data/scripts/lilycove_lady.pory"

# 295 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0:: @ 82A8716
# 296 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
# 297 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
# 298 "data/scripts/lilycove_lady.pory"
    end
# 299 "data/scripts/lilycove_lady.pory"

# 300 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_GivePrize:: @ 82A8724
# 301 "data/scripts/lilycove_lady.pory"
    setvar VAR_0x8005, 0
# 302 "data/scripts/lilycove_lady.pory"
    special BufferQuizPrizeItem
# 303 "data/scripts/lilycove_lady.pory"
    special SetQuizLadyState_Complete
# 304 "data/scripts/lilycove_lady.pory"
    giveitem VAR_0x8005
# 305 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, FALSE
# 306 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize
# 307 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
# 308 "data/scripts/lilycove_lady.pory"
    end
# 309 "data/scripts/lilycove_lady.pory"

# 310 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize:: @ 82A874C
# 311 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp, MSGBOX_DEFAULT
# 312 "data/scripts/lilycove_lady.pory"
    special SetQuizLadyState_GivePrize
# 313 "data/scripts/lilycove_lady.pory"
    release
# 314 "data/scripts/lilycove_lady.pory"
    end
# 315 "data/scripts/lilycove_lady.pory"

# 316 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz:: @ 82A8759
# 317 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz, MSGBOX_YESNO
# 318 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, YES
# 319 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz
# 320 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, NO
# 321 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
# 322 "data/scripts/lilycove_lady.pory"
    end
# 323 "data/scripts/lilycove_lady.pory"

# 324 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz:: @ 82A8778
# 325 "data/scripts/lilycove_lady.pory"
    special QuizLadyPickNewQuestion
# 326 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime, MSGBOX_DEFAULT
# 327 "data/scripts/lilycove_lady.pory"
    release
# 328 "data/scripts/lilycove_lady.pory"
    end
# 329 "data/scripts/lilycove_lady.pory"

# 330 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz:: @ 82A8785
# 331 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_PickYourPrize, MSGBOX_DEFAULT
# 332 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_PickPrize:: @ 82A878D
# 333 "data/scripts/lilycove_lady.pory"
    fadescreen FADE_TO_BLACK
# 334 "data/scripts/lilycove_lady.pory"
    setvar VAR_RESULT, 0
# 335 "data/scripts/lilycove_lady.pory"
    special Script_QuizLadyOpenBagMenu
# 336 "data/scripts/lilycove_lady.pory"
    waitstate
# 337 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, 0
# 338 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize
# 339 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, 1
# 340 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz
# 341 "data/scripts/lilycove_lady.pory"
    end
# 342 "data/scripts/lilycove_lady.pory"

# 343 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize:: @ 82A87AF
# 344 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize, MSGBOX_YESNO
# 345 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, YES
# 346 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
# 347 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, NO
# 348 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_PickPrize
# 349 "data/scripts/lilycove_lady.pory"
    end
# 350 "data/scripts/lilycove_lady.pory"

# 351 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz:: @ 82A87CE
# 352 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz, MSGBOX_DEFAULT
# 353 "data/scripts/lilycove_lady.pory"
    special ClearQuizLadyQuestionAndAnswer
# 354 "data/scripts/lilycove_lady.pory"
    special ClearQuizLadyPlayerAnswer
# 355 "data/scripts/lilycove_lady.pory"
    setvar VAR_0x8004, EASY_CHAT_TYPE_QUIZ_QUESTION
# 356 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion:: @ 82A87E1
# 357 "data/scripts/lilycove_lady.pory"
    fadescreen FADE_TO_BLACK
# 358 "data/scripts/lilycove_lady.pory"
    special QuizLadySetCustomQuestion
# 359 "data/scripts/lilycove_lady.pory"
    waitstate
# 360 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, 0
# 361 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion
# 362 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz
# 363 "data/scripts/lilycove_lady.pory"
    end
# 364 "data/scripts/lilycove_lady.pory"

# 365 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion:: @ 82A87F8
# 366 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion, MSGBOX_YESNO
# 367 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, YES
# 368 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
# 369 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, NO
# 370 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion
# 371 "data/scripts/lilycove_lady.pory"
    end
# 372 "data/scripts/lilycove_lady.pory"

# 373 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz:: @ 82A8817
# 374 "data/scripts/lilycove_lady.pory"
    special QuizLadyTakePrizeForCustomQuiz
# 375 "data/scripts/lilycove_lady.pory"
    special QuizLadyRecordCustomQuizData
# 376 "data/scripts/lilycove_lady.pory"
    special QuizLadySetWaitingForChallenger
# 377 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger, MSGBOX_DEFAULT
# 378 "data/scripts/lilycove_lady.pory"
    release
# 379 "data/scripts/lilycove_lady.pory"
    end
# 380 "data/scripts/lilycove_lady.pory"

# 381 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_ContestLady:: @ 82A882A
# 382 "data/scripts/lilycove_lady.pory"
    lock
# 383 "data/scripts/lilycove_lady.pory"
    faceplayer
# 384 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady, MSGBOX_DEFAULT
# 385 "data/scripts/lilycove_lady.pory"
    specialvar VAR_RESULT, HasPlayerGivenContestLadyPokeblock
# 386 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, FALSE
# 387 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock
# 388 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, TRUE
# 389 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
# 390 "data/scripts/lilycove_lady.pory"
    end
# 391 "data/scripts/lilycove_lady.pory"

# 392 "data/scripts/lilycove_lady.pory"
@ Redundant with above script, VAR_RESULT will always be FALSE here
# 393 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock:: @ 82A8850
# 394 "data/scripts/lilycove_lady.pory"
    specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
# 395 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, FALSE
# 396 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock
# 397 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, TRUE
# 398 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
# 399 "data/scripts/lilycove_lady.pory"
    end
# 400 "data/scripts/lilycove_lady.pory"

# 401 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock:: @ 82A886C
# 402 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock, MSGBOX_DEFAULT
# 403 "data/scripts/lilycove_lady.pory"
    release
# 404 "data/scripts/lilycove_lady.pory"
    end
# 405 "data/scripts/lilycove_lady.pory"

# 406 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock:: @ 82A8876
# 407 "data/scripts/lilycove_lady.pory"
    special Script_BufferContestLadyCategoryAndMonName
# 408 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality, MSGBOX_DEFAULT
# 409 "data/scripts/lilycove_lady.pory"
    checkitem ITEM_POKEBLOCK_CASE, 1
# 410 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, FALSE
# 411 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase
# 412 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock, MSGBOX_YESNO
# 413 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, NO
# 414 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
# 415 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, YES
# 416 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
# 417 "data/scripts/lilycove_lady.pory"
    end
# 418 "data/scripts/lilycove_lady.pory"

# 419 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock:: @ 82A88B0
# 420 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate, MSGBOX_DEFAULT
# 421 "data/scripts/lilycove_lady.pory"
    release
# 422 "data/scripts/lilycove_lady.pory"
    end
# 423 "data/scripts/lilycove_lady.pory"

# 424 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock:: @ 82A88BA
# 425 "data/scripts/lilycove_lady.pory"
    fadescreen FADE_TO_BLACK
# 426 "data/scripts/lilycove_lady.pory"
    special OpenPokeblockCaseForContestLady
# 427 "data/scripts/lilycove_lady.pory"
    waitstate
# 428 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, 0xFFFF
# 429 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock
# 430 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, 0xFFFF
# 431 "data/scripts/lilycove_lady.pory"
    goto_if_ne LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock
# 432 "data/scripts/lilycove_lady.pory"
    end
# 433 "data/scripts/lilycove_lady.pory"

# 434 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock:: @ 82A88D7
# 435 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock, MSGBOX_YESNO
# 436 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, YES
# 437 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
# 438 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, NO
# 439 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
# 440 "data/scripts/lilycove_lady.pory"
    end
# 441 "data/scripts/lilycove_lady.pory"

# 442 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock:: @ 82A88F6
# 443 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock, MSGBOX_DEFAULT
# 444 "data/scripts/lilycove_lady.pory"
    special SetContestLadyGivenPokeblock
# 445 "data/scripts/lilycove_lady.pory"
    special GetContestLadyMonSpecies
# 446 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock
# 447 "data/scripts/lilycove_lady.pory"
    end
# 448 "data/scripts/lilycove_lady.pory"

# 449 "data/scripts/lilycove_lady.pory"
@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
# 450 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock:: @ 82A890A
# 451 "data/scripts/lilycove_lady.pory"
    applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon
# 452 "data/scripts/lilycove_lady.pory"
    waitmovement 0
# 453 "data/scripts/lilycove_lady.pory"
    delay 60
# 454 "data/scripts/lilycove_lady.pory"
    applymovement LOCALID_LADYS_MON, LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady
# 455 "data/scripts/lilycove_lady.pory"
    waitmovement 0
# 456 "data/scripts/lilycove_lady.pory"
    delay 60
# 457 "data/scripts/lilycove_lady.pory"
    waitse
# 458 "data/scripts/lilycove_lady.pory"
    playmoncry VAR_0x8005, 0
# 459 "data/scripts/lilycove_lady.pory"
    delay 120
# 460 "data/scripts/lilycove_lady.pory"
    waitmoncry
# 461 "data/scripts/lilycove_lady.pory"
    compare VAR_0x8004, 1
# 462 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock
# 463 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock
# 464 "data/scripts/lilycove_lady.pory"
    end
# 465 "data/scripts/lilycove_lady.pory"

# 466 "data/scripts/lilycove_lady.pory"
@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
# 467 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock:: @ 82A893F
# 468 "data/scripts/lilycove_lady.pory"
    applymovement LOCALID_LADYS_MON, LilycoveCity_PokemonCenter_1F_Movement_MonJump
# 469 "data/scripts/lilycove_lady.pory"
    waitmovement 0
# 470 "data/scripts/lilycove_lady.pory"
    delay 60
# 471 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock:: @ 82A894C
# 472 "data/scripts/lilycove_lady.pory"
    applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer
# 473 "data/scripts/lilycove_lady.pory"
    waitmovement 0
# 474 "data/scripts/lilycove_lady.pory"
    delay 60
# 475 "data/scripts/lilycove_lady.pory"
    compare VAR_0x8004, 0
# 476 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock
# 477 "data/scripts/lilycove_lady.pory"
    compare VAR_0x8004, 1
# 478 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock
# 479 "data/scripts/lilycove_lady.pory"
    end
# 480 "data/scripts/lilycove_lady.pory"

# 481 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock:: @ 82A8970
# 482 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks, MSGBOX_DEFAULT
# 483 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
# 484 "data/scripts/lilycove_lady.pory"
    end
# 485 "data/scripts/lilycove_lady.pory"

# 486 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock:: @ 82A897E
# 487 "data/scripts/lilycove_lady.pory"
    special Script_BufferContestLadyCategoryAndMonName
# 488 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks, MSGBOX_DEFAULT
# 489 "data/scripts/lilycove_lady.pory"
    goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
# 490 "data/scripts/lilycove_lady.pory"
    end
# 491 "data/scripts/lilycove_lady.pory"

# 492 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow:: @ 82A898F
# 493 "data/scripts/lilycove_lady.pory"
    specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
# 494 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, 1
# 495 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow
# 496 "data/scripts/lilycove_lady.pory"
    release
# 497 "data/scripts/lilycove_lady.pory"
    end
# 498 "data/scripts/lilycove_lady.pory"

# 499 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow:: @ 82A89A1
# 500 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests, MSGBOX_DEFAULT
# 501 "data/scripts/lilycove_lady.pory"
    special PutLilycoveContestLadyShowOnTheAir
# 502 "data/scripts/lilycove_lady.pory"
    release
# 503 "data/scripts/lilycove_lady.pory"
    end
# 504 "data/scripts/lilycove_lady.pory"

# 505 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase:: @ 82A89AE
# 506 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase, MSGBOX_DEFAULT
# 507 "data/scripts/lilycove_lady.pory"
    release
# 508 "data/scripts/lilycove_lady.pory"
    end
# 509 "data/scripts/lilycove_lady.pory"

# 510 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon: @ 82A89B8
# 511 "data/scripts/lilycove_lady.pory"
    face_right
# 512 "data/scripts/lilycove_lady.pory"
    delay_8
# 513 "data/scripts/lilycove_lady.pory"
    step_end
# 514 "data/scripts/lilycove_lady.pory"

# 515 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady: @ 82A89BB
# 516 "data/scripts/lilycove_lady.pory"
    face_left
# 517 "data/scripts/lilycove_lady.pory"
    delay_8
# 518 "data/scripts/lilycove_lady.pory"
    step_end
# 519 "data/scripts/lilycove_lady.pory"

# 520 "data/scripts/lilycove_lady.pory"
@ Unused
# 521 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Movement_MonFaceDown: @ 82A89BE
# 522 "data/scripts/lilycove_lady.pory"
    face_down
# 523 "data/scripts/lilycove_lady.pory"
    step_end
# 524 "data/scripts/lilycove_lady.pory"

# 525 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer: @ 82A89C0
# 526 "data/scripts/lilycove_lady.pory"
    face_player
# 527 "data/scripts/lilycove_lady.pory"
    step_end
# 528 "data/scripts/lilycove_lady.pory"

# 529 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Movement_MonJump: @ 82A89C2
# 530 "data/scripts/lilycove_lady.pory"
    disable_jump_landing_ground_effect
# 531 "data/scripts/lilycove_lady.pory"
    jump_in_place_left
# 532 "data/scripts/lilycove_lady.pory"
    disable_jump_landing_ground_effect
# 533 "data/scripts/lilycove_lady.pory"
    jump_in_place_left
# 534 "data/scripts/lilycove_lady.pory"
    step_end
# 535 "data/scripts/lilycove_lady.pory"

# 536 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_ContestLadyMon:: @ 82A89C7
# 537 "data/scripts/lilycove_lady.pory"
    specialvar VAR_RESULT, GetContestLadyCategory
# 538 "data/scripts/lilycove_lady.pory"
    special Script_BufferContestLadyCategoryAndMonName
# 539 "data/scripts/lilycove_lady.pory"
    special GetContestLadyMonSpecies
# 540 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, CONTEST_CATEGORY_COOL
# 541 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon
# 542 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, CONTEST_CATEGORY_BEAUTY
# 543 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_Skitty
# 544 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, CONTEST_CATEGORY_CUTE
# 545 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_Poochyena
# 546 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, CONTEST_CATEGORY_SMART
# 547 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_Kecleon
# 548 "data/scripts/lilycove_lady.pory"
    compare VAR_RESULT, CONTEST_CATEGORY_TOUGH
# 549 "data/scripts/lilycove_lady.pory"
    goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_Pikachu
# 550 "data/scripts/lilycove_lady.pory"
    end
# 551 "data/scripts/lilycove_lady.pory"

# 552 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon:: @ 82A8A0A
# 553 "data/scripts/lilycove_lady.pory"
    lock
# 554 "data/scripts/lilycove_lady.pory"
    faceplayer
# 555 "data/scripts/lilycove_lady.pory"
    waitse
# 556 "data/scripts/lilycove_lady.pory"
    playmoncry VAR_0x8005, 0
# 557 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_Zigzagoon, MSGBOX_DEFAULT
# 558 "data/scripts/lilycove_lady.pory"
    waitmoncry
# 559 "data/scripts/lilycove_lady.pory"
    release
# 560 "data/scripts/lilycove_lady.pory"
    end
# 561 "data/scripts/lilycove_lady.pory"

# 562 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_Skitty:: @ 82A8A1D
# 563 "data/scripts/lilycove_lady.pory"
    lock
# 564 "data/scripts/lilycove_lady.pory"
    faceplayer
# 565 "data/scripts/lilycove_lady.pory"
    waitse
# 566 "data/scripts/lilycove_lady.pory"
    playmoncry VAR_0x8005, 0
# 567 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
# 568 "data/scripts/lilycove_lady.pory"
    waitmoncry
# 569 "data/scripts/lilycove_lady.pory"
    release
# 570 "data/scripts/lilycove_lady.pory"
    end
# 571 "data/scripts/lilycove_lady.pory"

# 572 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_Poochyena:: @ 82A8A30
# 573 "data/scripts/lilycove_lady.pory"
    lock
# 574 "data/scripts/lilycove_lady.pory"
    faceplayer
# 575 "data/scripts/lilycove_lady.pory"
    waitse
# 576 "data/scripts/lilycove_lady.pory"
    playmoncry VAR_0x8005, 0
# 577 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_Poochyena, MSGBOX_DEFAULT
# 578 "data/scripts/lilycove_lady.pory"
    waitmoncry
# 579 "data/scripts/lilycove_lady.pory"
    release
# 580 "data/scripts/lilycove_lady.pory"
    end
# 581 "data/scripts/lilycove_lady.pory"

# 582 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_Kecleon:: @ 82A8A43
# 583 "data/scripts/lilycove_lady.pory"
    lock
# 584 "data/scripts/lilycove_lady.pory"
    faceplayer
# 585 "data/scripts/lilycove_lady.pory"
    waitse
# 586 "data/scripts/lilycove_lady.pory"
    playmoncry VAR_0x8005, 0
# 587 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_Kecleon, MSGBOX_DEFAULT
# 588 "data/scripts/lilycove_lady.pory"
    waitmoncry
# 589 "data/scripts/lilycove_lady.pory"
    release
# 590 "data/scripts/lilycove_lady.pory"
    end
# 591 "data/scripts/lilycove_lady.pory"

# 592 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_EventScript_Pikachu:: @ 82A8A56
# 593 "data/scripts/lilycove_lady.pory"
    lock
# 594 "data/scripts/lilycove_lady.pory"
    faceplayer
# 595 "data/scripts/lilycove_lady.pory"
    waitse
# 596 "data/scripts/lilycove_lady.pory"
    playmoncry VAR_0x8005, 0
# 597 "data/scripts/lilycove_lady.pory"
    msgbox LilycoveCity_PokemonCenter_1F_Text_Pikachu, MSGBOX_DEFAULT
# 598 "data/scripts/lilycove_lady.pory"
    waitmoncry
# 599 "data/scripts/lilycove_lady.pory"
    release
# 600 "data/scripts/lilycove_lady.pory"
    end
# 601 "data/scripts/lilycove_lady.pory"

# 602 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady: @ 82A8A69
# 603 "data/scripts/lilycove_lady.pory"
    .string "I'm the Favor Lady…$"
# 604 "data/scripts/lilycove_lady.pory"

# 605 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing: @ 82A8A7D
# 606 "data/scripts/lilycove_lady.pory"
    .string "I've recently developed an obsession\n"
# 607 "data/scripts/lilycove_lady.pory"
    .string "for {STR_VAR_1} things…$"
# 608 "data/scripts/lilycove_lady.pory"

# 609 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime: @ 82A8AB1
# 610 "data/scripts/lilycove_lady.pory"
    .string "Oh…\n"
# 611 "data/scripts/lilycove_lady.pory"
    .string "Thank you for last time…$"
# 612 "data/scripts/lilycove_lady.pory"

# 613 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing: @ 82A8ACE
# 614 "data/scripts/lilycove_lady.pory"
    .string "Before, I think it was {STR_VAR_3}…\p"
# 615 "data/scripts/lilycove_lady.pory"
    .string "{STR_VAR_3} gave me one {STR_VAR_2},\n"
# 616 "data/scripts/lilycove_lady.pory"
    .string "saying it was {STR_VAR_1}.\p"
# 617 "data/scripts/lilycove_lady.pory"
    .string "But it wasn't {STR_VAR_1}.\n"
# 618 "data/scripts/lilycove_lady.pory"
    .string "Not in the least bit.$"
# 619 "data/scripts/lilycove_lady.pory"

# 620 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing: @ 82A8B36
# 621 "data/scripts/lilycove_lady.pory"
    .string "Before, {STR_VAR_3} gave me a very\n"
# 622 "data/scripts/lilycove_lady.pory"
    .string "{STR_VAR_1} {STR_VAR_2}.\p"
# 623 "data/scripts/lilycove_lady.pory"
    .string "I cherish it now.$"
# 624 "data/scripts/lilycove_lady.pory"

# 625 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing: @ 82A8B69
# 626 "data/scripts/lilycove_lady.pory"
    .string "Listen, if you have anything that\n"
# 627 "data/scripts/lilycove_lady.pory"
    .string "is {STR_VAR_1}, will you share it\l"
# 628 "data/scripts/lilycove_lady.pory"
    .string "with me?$"
# 629 "data/scripts/lilycove_lady.pory"

# 630 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe: @ 82A8BAD
# 631 "data/scripts/lilycove_lady.pory"
    .string "…Really?\n"
# 632 "data/scripts/lilycove_lady.pory"
    .string "What will you give me?$"
# 633 "data/scripts/lilycove_lady.pory"

# 634 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye: @ 82A8BCD
# 635 "data/scripts/lilycove_lady.pory"
    .string "Is that so?\n"
# 636 "data/scripts/lilycove_lady.pory"
    .string "Then, it's good-bye…$"
# 637 "data/scripts/lilycove_lady.pory"

# 638 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare: @ 82A8BEE
# 639 "data/scripts/lilycove_lady.pory"
    .string "Oh…\n"
# 640 "data/scripts/lilycove_lady.pory"
    .string "You're not willing to share?$"
# 641 "data/scripts/lilycove_lady.pory"

# 642 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt: @ 82A8C0F
# 643 "data/scripts/lilycove_lady.pory"
    .string "Oh?\n"
# 644 "data/scripts/lilycove_lady.pory"
    .string "That {STR_VAR_2} is {STR_VAR_1}?\p"
# 645 "data/scripts/lilycove_lady.pory"
    .string "…Oh, is that right?\p"
# 646 "data/scripts/lilycove_lady.pory"
    .string "Well, I owe you a thanks anyway.\n"
# 647 "data/scripts/lilycove_lady.pory"
    .string "I'll try to cherish it…$"
# 648 "data/scripts/lilycove_lady.pory"

# 649 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis: @ 82A8C6F
# 650 "data/scripts/lilycove_lady.pory"
    .string "Oh…\p"
# 651 "data/scripts/lilycove_lady.pory"
    .string "That's a quite {STR_VAR_1}\n"
# 652 "data/scripts/lilycove_lady.pory"
    .string "{STR_VAR_2}…\p"
# 653 "data/scripts/lilycove_lady.pory"
    .string "Isn't it nice?\n"
# 654 "data/scripts/lilycove_lady.pory"
    .string "It's so dreamy…\p"
# 655 "data/scripts/lilycove_lady.pory"
    .string "Thank you…\n"
# 656 "data/scripts/lilycove_lady.pory"
    .string "I will cherish this…$"
# 657 "data/scripts/lilycove_lady.pory"

# 658 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis: @ 82A8CC8
# 659 "data/scripts/lilycove_lady.pory"
    .string "…Oh, oh, oh…\p"
# 660 "data/scripts/lilycove_lady.pory"
    .string "This is amazing!\n"
# 661 "data/scripts/lilycove_lady.pory"
    .string "This really is {STR_VAR_1}!\p"
# 662 "data/scripts/lilycove_lady.pory"
    .string "I never knew that one {STR_VAR_2}\n"
# 663 "data/scripts/lilycove_lady.pory"
    .string "could be this {STR_VAR_1}!\p"
# 664 "data/scripts/lilycove_lady.pory"
    .string "Thank you!\p"
# 665 "data/scripts/lilycove_lady.pory"
    .string "I will treasure this for the rest\n"
# 666 "data/scripts/lilycove_lady.pory"
    .string "of my life!$"
# 667 "data/scripts/lilycove_lady.pory"

# 668 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn: @ 82A8D5D
# 669 "data/scripts/lilycove_lady.pory"
    .string "I'll give you this wonderful item in\n"
# 670 "data/scripts/lilycove_lady.pory"
    .string "return for your fabulous gift.\p"
# 671 "data/scripts/lilycove_lady.pory"
    .string "I hope you will cherish it…$"
# 672 "data/scripts/lilycove_lady.pory"

# 673 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt: @ 82A8DBD
# 674 "data/scripts/lilycove_lady.pory"
    .string "Oh, you can't have it if you don't have\n"
# 675 "data/scripts/lilycove_lady.pory"
    .string "the space for it.\p"
# 676 "data/scripts/lilycove_lady.pory"
    .string "Please come see me when you get\n"
# 677 "data/scripts/lilycove_lady.pory"
    .string "your Bag organized…$"
# 678 "data/scripts/lilycove_lady.pory"

# 679 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady: @ 82A8E2B
# 680 "data/scripts/lilycove_lady.pory"
    .string "I'm the Quiz Lady!\n"
# 681 "data/scripts/lilycove_lady.pory"
    .string "I love quizzes!$"
# 682 "data/scripts/lilycove_lady.pory"

# 683 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz: @ 82A8E4E
# 684 "data/scripts/lilycove_lady.pory"
    .string "Oh?\p"
# 685 "data/scripts/lilycove_lady.pory"
    .string "I'm waiting for a challenger to answer\n"
# 686 "data/scripts/lilycove_lady.pory"
    .string "the quiz you made.\p"
# 687 "data/scripts/lilycove_lady.pory"
    .string "We can chat another time, okay?$"
# 688 "data/scripts/lilycove_lady.pory"

# 689 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger: @ 82A8EAC
# 690 "data/scripts/lilycove_lady.pory"
    .string "I'm waiting for someone to challenge\n"
# 691 "data/scripts/lilycove_lady.pory"
    .string "a quiz this {STR_VAR_1} thought up!$"
# 692 "data/scripts/lilycove_lady.pory"

# 693 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge: @ 82A8EEC
# 694 "data/scripts/lilycove_lady.pory"
    .string "If you answer correctly, you can win\n"
# 695 "data/scripts/lilycove_lady.pory"
    .string "fabulous prizes!\p"
# 696 "data/scripts/lilycove_lady.pory"
    .string "Would you like to take the quiz\n"
# 697 "data/scripts/lilycove_lady.pory"
    .string "challenge?$"
# 698 "data/scripts/lilycove_lady.pory"

# 699 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer: @ 82A8F4D
# 700 "data/scripts/lilycove_lady.pory"
    .string "… … … … … …\n"
# 701 "data/scripts/lilycove_lady.pory"
    .string "… … … … … …$"
# 702 "data/scripts/lilycove_lady.pory"

# 703 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_HowBoringBye: @ 82A8F65
# 704 "data/scripts/lilycove_lady.pory"
    .string "Oh, how boring!\n"
# 705 "data/scripts/lilycove_lady.pory"
    .string "Bye-bye!$"
# 706 "data/scripts/lilycove_lady.pory"

# 707 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit: @ 82A8F7E
# 708 "data/scripts/lilycove_lady.pory"
    .string "Awww!\n"
# 709 "data/scripts/lilycove_lady.pory"
    .string "You're going to quit?$"
# 710 "data/scripts/lilycove_lady.pory"

# 711 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime: @ 82A8F9A
# 712 "data/scripts/lilycove_lady.pory"
    .string "Please take the quiz challenge\n"
# 713 "data/scripts/lilycove_lady.pory"
    .string "another time!$"
# 714 "data/scripts/lilycove_lady.pory"

# 715 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_YouGotItRight: @ 82A8FC7
# 716 "data/scripts/lilycove_lady.pory"
    .string "You're amazing! You've got it right!\n"
# 717 "data/scripts/lilycove_lady.pory"
    .string "You're one sharp customer!$"
# 718 "data/scripts/lilycove_lady.pory"

# 719 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize: @ 82A9007
# 720 "data/scripts/lilycove_lady.pory"
    .string "Congratulations!\n"
# 721 "data/scripts/lilycove_lady.pory"
    .string "You've got the quiz right!\p"
# 722 "data/scripts/lilycove_lady.pory"
    .string "You've won a prize provided by\n"
# 723 "data/scripts/lilycove_lady.pory"
    .string "{STR_VAR_1}!$"
# 724 "data/scripts/lilycove_lady.pory"

# 725 "data/scripts/lilycove_lady.pory"
@ Unused
# 726 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_XReceivedOneY: @ 82A9056
# 727 "data/scripts/lilycove_lady.pory"
    .string "{STR_VAR_1} received\n"
# 728 "data/scripts/lilycove_lady.pory"
    .string "one {STR_VAR_2}!$"
# 729 "data/scripts/lilycove_lady.pory"

# 730 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp: @ 82A906A
# 731 "data/scripts/lilycove_lady.pory"
    .string "Oh? Your Bag is filled up!\n"
# 732 "data/scripts/lilycove_lady.pory"
    .string "Come see me when you have room.$"
# 733 "data/scripts/lilycove_lady.pory"

# 734 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs: @ 82A90A5
# 735 "data/scripts/lilycove_lady.pory"
    .string "Hmm… Wrong!\n"
# 736 "data/scripts/lilycove_lady.pory"
    .string "The correct answer is “{STR_VAR_3}”!$"
# 737 "data/scripts/lilycove_lady.pory"

# 738 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize: @ 82A90CD
# 739 "data/scripts/lilycove_lady.pory"
    .string "Too bad!\p"
# 740 "data/scripts/lilycove_lady.pory"
    .string "I get to keep the quiz prize\n"
# 741 "data/scripts/lilycove_lady.pory"
    .string "{STR_VAR_1} now!$"
# 742 "data/scripts/lilycove_lady.pory"

# 743 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz: @ 82A90FB
# 744 "data/scripts/lilycove_lady.pory"
    .string "Listen, listen!\n"
# 745 "data/scripts/lilycove_lady.pory"
    .string "Would you like to make your own quiz?$"
# 746 "data/scripts/lilycove_lady.pory"

# 747 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime: @ 82A9131
# 748 "data/scripts/lilycove_lady.pory"
    .string "Oh, I see…\n"
# 749 "data/scripts/lilycove_lady.pory"
    .string "Well, maybe next time!$"
# 750 "data/scripts/lilycove_lady.pory"

# 751 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_PickYourPrize: @ 82A9153
# 752 "data/scripts/lilycove_lady.pory"
    .string "Okay, the first thing you have to do\n"
# 753 "data/scripts/lilycove_lady.pory"
    .string "is pick the prize for the person that\l"
# 754 "data/scripts/lilycove_lady.pory"
    .string "answers your quiz correctly.\p"
# 755 "data/scripts/lilycove_lady.pory"
    .string "But beware, if the person taking\n"
# 756 "data/scripts/lilycove_lady.pory"
    .string "the quiz can't get it right, I get to\l"
# 757 "data/scripts/lilycove_lady.pory"
    .string "keep the prize!$"
# 758 "data/scripts/lilycove_lady.pory"

# 759 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize: @ 82A9212
# 760 "data/scripts/lilycove_lady.pory"
    .string "If you don't choose a prize,\n"
# 761 "data/scripts/lilycove_lady.pory"
    .string "your quiz can't be made.\p"
# 762 "data/scripts/lilycove_lady.pory"
    .string "Are you going to quit making\n"
# 763 "data/scripts/lilycove_lady.pory"
    .string "your quiz?$"
# 764 "data/scripts/lilycove_lady.pory"

# 765 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz: @ 82A9270
# 766 "data/scripts/lilycove_lady.pory"
    .string "Oh, how nice!\n"
# 767 "data/scripts/lilycove_lady.pory"
    .string "That's a wonderful prize!\p"
# 768 "data/scripts/lilycove_lady.pory"
    .string "Next, you need to write your quiz\n"
# 769 "data/scripts/lilycove_lady.pory"
    .string "question and its answer.$"
# 770 "data/scripts/lilycove_lady.pory"

# 771 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion: @ 82A92D3
# 772 "data/scripts/lilycove_lady.pory"
    .string "Are you going to quit writing\n"
# 773 "data/scripts/lilycove_lady.pory"
    .string "your quiz question?$"
# 774 "data/scripts/lilycove_lady.pory"

# 775 "data/scripts/lilycove_lady.pory"
@ Unused
# 776 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizAnswer: @ 82A9305
# 777 "data/scripts/lilycove_lady.pory"
    .string "Are you going to quit choosing\n"
# 778 "data/scripts/lilycove_lady.pory"
    .string "your quiz answer?$"
# 779 "data/scripts/lilycove_lady.pory"

# 780 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger: @ 82A9336
# 781 "data/scripts/lilycove_lady.pory"
    .string "Thank you!\n"
# 782 "data/scripts/lilycove_lady.pory"
    .string "You've put together a nice quiz.\p"
# 783 "data/scripts/lilycove_lady.pory"
    .string "I'll go look for someone who'll take\n"
# 784 "data/scripts/lilycove_lady.pory"
    .string "your quiz challenge right away.$"
# 785 "data/scripts/lilycove_lady.pory"

# 786 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady: @ 82A93A7
# 787 "data/scripts/lilycove_lady.pory"
    .string "I'm the Contest Lady!\n"
# 788 "data/scripts/lilycove_lady.pory"
    .string "I sure do love Contests!$"
# 789 "data/scripts/lilycove_lady.pory"

# 790 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock: @ 82A93D6
# 791 "data/scripts/lilycove_lady.pory"
    .string "Thanks for your {POKEBLOCK} before!$"
# 792 "data/scripts/lilycove_lady.pory"

# 793 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality: @ 82A93F4
# 794 "data/scripts/lilycove_lady.pory"
    .string "This is my friend {STR_VAR_1}!\n"
# 795 "data/scripts/lilycove_lady.pory"
    .string "It's the epitome of {STR_VAR_2}!\p"
# 796 "data/scripts/lilycove_lady.pory"
    .string "But I think that it will display\n"
# 797 "data/scripts/lilycove_lady.pory"
    .string "even more {STR_VAR_2}!$"
# 798 "data/scripts/lilycove_lady.pory"

# 799 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase: @ 82A9451
# 800 "data/scripts/lilycove_lady.pory"
    .string "So, I need your help!\p"
# 801 "data/scripts/lilycove_lady.pory"
    .string "Please, may I have one {POKEBLOCK}?\n"
# 802 "data/scripts/lilycove_lady.pory"
    .string "All I'm asking for is one!\p"
# 803 "data/scripts/lilycove_lady.pory"
    .string "…Oh, but…\n"
# 804 "data/scripts/lilycove_lady.pory"
    .string "Don't you have a {POKEBLOCK} CASE?\l"
# 805 "data/scripts/lilycove_lady.pory"
    .string "That's no good. Next time, then!$"
# 806 "data/scripts/lilycove_lady.pory"

# 807 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock: @ 82A94E8
# 808 "data/scripts/lilycove_lady.pory"
    .string "So, I need your help!\p"
# 809 "data/scripts/lilycove_lady.pory"
    .string "Please, may I have one {POKEBLOCK}?\n"
# 810 "data/scripts/lilycove_lady.pory"
    .string "All I'm asking for is one!$"
# 811 "data/scripts/lilycove_lady.pory"

# 812 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock: @ 82A9537
# 813 "data/scripts/lilycove_lady.pory"
    .string "Awww!\n"
# 814 "data/scripts/lilycove_lady.pory"
    .string "I can't have one {POKEBLOCK}?!$"
# 815 "data/scripts/lilycove_lady.pory"

# 816 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate: @ 82A9556
# 817 "data/scripts/lilycove_lady.pory"
    .string "Sheesh!\n"
# 818 "data/scripts/lilycove_lady.pory"
    .string "What a cheapskate!$"
# 819 "data/scripts/lilycove_lady.pory"

# 820 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock: @ 82A9571
# 821 "data/scripts/lilycove_lady.pory"
    .string "Yay!\n"
# 822 "data/scripts/lilycove_lady.pory"
    .string "Thank you!\p"
# 823 "data/scripts/lilycove_lady.pory"
    .string "I'll feed my Pokémon your {POKEBLOCK}\n"
# 824 "data/scripts/lilycove_lady.pory"
    .string "right away.$"
# 825 "data/scripts/lilycove_lady.pory"

# 826 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks: @ 82A95AD
# 827 "data/scripts/lilycove_lady.pory"
    .string "…It doesn't seem to have changed\n"
# 828 "data/scripts/lilycove_lady.pory"
    .string "in any way at all…\p"
# 829 "data/scripts/lilycove_lady.pory"
    .string "Hmm…\p"
# 830 "data/scripts/lilycove_lady.pory"
    .string "Oh, well!\n"
# 831 "data/scripts/lilycove_lady.pory"
    .string "Thank you very much!$"
# 832 "data/scripts/lilycove_lady.pory"

# 833 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks: @ 82A9605
# 834 "data/scripts/lilycove_lady.pory"
    .string "Oh, yay!\n"
# 835 "data/scripts/lilycove_lady.pory"
    .string "It's really delighted!\p"
# 836 "data/scripts/lilycove_lady.pory"
    .string "I think it really improved {STR_VAR_1}'s\n"
# 837 "data/scripts/lilycove_lady.pory"
    .string "{STR_VAR_2} quality, too.\p"
# 838 "data/scripts/lilycove_lady.pory"
    .string "Thank you so much!$"
# 839 "data/scripts/lilycove_lady.pory"

# 840 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests: @ 82A9669
# 841 "data/scripts/lilycove_lady.pory"
    .string "Hmm…\p"
# 842 "data/scripts/lilycove_lady.pory"
    .string "I think we may be ready to enter\n"
# 843 "data/scripts/lilycove_lady.pory"
    .string "some Contests.\p"
# 844 "data/scripts/lilycove_lady.pory"
    .string "If you see us in one somewhere,\n"
# 845 "data/scripts/lilycove_lady.pory"
    .string "I hope you'll cheer for us.$"
# 846 "data/scripts/lilycove_lady.pory"

# 847 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_Zigzagoon: @ 82A96DA
# 848 "data/scripts/lilycove_lady.pory"
    .string "{STR_VAR_1}: Guguuh!$"
# 849 "data/scripts/lilycove_lady.pory"

# 850 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_Kecleon: @ 82A96E6
# 851 "data/scripts/lilycove_lady.pory"
    .string "{STR_VAR_1}: Igigigiiih!$"
# 852 "data/scripts/lilycove_lady.pory"

# 853 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_Poochyena: @ 82A96F6
# 854 "data/scripts/lilycove_lady.pory"
    .string "{STR_VAR_1}: Baaarun…$"
# 855 "data/scripts/lilycove_lady.pory"

# 856 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_Pikachu: @ 82A9703
# 857 "data/scripts/lilycove_lady.pory"
    .string "{STR_VAR_1}: Pikka!$"
# 858 "data/scripts/lilycove_lady.pory"

# 859 "data/scripts/lilycove_lady.pory"
LilycoveCity_PokemonCenter_1F_Text_Skitty: @ 82A970E
# 860 "data/scripts/lilycove_lady.pory"
    .string "{STR_VAR_1}: Umyaaaan!$"
