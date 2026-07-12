# 1 "data/scripts/safari_zone.pory"

# 2 "data/scripts/safari_zone.pory"
SafariZone_EventScript_OutOfBallsMidBattle::
# 3 "data/scripts/safari_zone.pory"
	setvar VAR_SAFARI_ZONE_STATE, 1
# 4 "data/scripts/safari_zone.pory"
	special ExitSafariMode
# 5 "data/scripts/safari_zone.pory"
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 255, 2, 5
# 6 "data/scripts/safari_zone.pory"
	end
# 7 "data/scripts/safari_zone.pory"

# 8 "data/scripts/safari_zone.pory"
SafariZone_EventScript_Exit::
# 9 "data/scripts/safari_zone.pory"
	setvar VAR_SAFARI_ZONE_STATE, 1
# 10 "data/scripts/safari_zone.pory"
	special ExitSafariMode
# 11 "data/scripts/safari_zone.pory"
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 255, 2, 5
# 12 "data/scripts/safari_zone.pory"
	waitstate
# 13 "data/scripts/safari_zone.pory"
	end
# 14 "data/scripts/safari_zone.pory"

# 15 "data/scripts/safari_zone.pory"
SafariZone_EventScript_RetirePrompt::
# 16 "data/scripts/safari_zone.pory"
	lockall
# 17 "data/scripts/safari_zone.pory"
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
# 18 "data/scripts/safari_zone.pory"
	compare VAR_RESULT, YES
# 19 "data/scripts/safari_zone.pory"
	goto_if_eq SafariZone_EventScript_Retire
# 20 "data/scripts/safari_zone.pory"
	releaseall
# 21 "data/scripts/safari_zone.pory"
	end
# 22 "data/scripts/safari_zone.pory"

# 23 "data/scripts/safari_zone.pory"
SafariZone_EventScript_Retire::
# 24 "data/scripts/safari_zone.pory"
	goto SafariZone_EventScript_Exit
# 25 "data/scripts/safari_zone.pory"

# 26 "data/scripts/safari_zone.pory"
SafariZone_EventScript_TimesUp::
# 27 "data/scripts/safari_zone.pory"
	lockall
# 28 "data/scripts/safari_zone.pory"
	playse SE_DING_DONG
# 29 "data/scripts/safari_zone.pory"
	message SafariZone_Text_TimesUp
# 30 "data/scripts/safari_zone.pory"
	waitmessage
# 31 "data/scripts/safari_zone.pory"
	waitbuttonpress
# 32 "data/scripts/safari_zone.pory"
	releaseall
# 33 "data/scripts/safari_zone.pory"
	goto SafariZone_EventScript_Exit
# 34 "data/scripts/safari_zone.pory"

# 35 "data/scripts/safari_zone.pory"
SafariZone_EventScript_OutOfBalls::
# 36 "data/scripts/safari_zone.pory"
	lockall
# 37 "data/scripts/safari_zone.pory"
	playse SE_DING_DONG
# 38 "data/scripts/safari_zone.pory"
	message SafariZone_Text_OutOfBalls
# 39 "data/scripts/safari_zone.pory"
	waitmessage
# 40 "data/scripts/safari_zone.pory"
	waitbuttonpress
# 41 "data/scripts/safari_zone.pory"
	releaseall
# 42 "data/scripts/safari_zone.pory"
	goto SafariZone_EventScript_Exit
# 43 "data/scripts/safari_zone.pory"

# 44 "data/scripts/safari_zone.pory"
EventScript_PokeBlockFeeder::
# 45 "data/scripts/safari_zone.pory"
	lockall
# 46 "data/scripts/safari_zone.pory"
	special GetPokeblockFeederInFront
# 47 "data/scripts/safari_zone.pory"
	compare VAR_RESULT, 0xFFFF
# 48 "data/scripts/safari_zone.pory"
	goto_if_ne SafariZone_EventScript_PokeblockPresent
# 49 "data/scripts/safari_zone.pory"
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
# 50 "data/scripts/safari_zone.pory"
	compare VAR_RESULT, YES
# 51 "data/scripts/safari_zone.pory"
	goto_if_eq SafariZone_EventScript_ChoosePokeblock
# 52 "data/scripts/safari_zone.pory"
	releaseall
# 53 "data/scripts/safari_zone.pory"
	end
# 54 "data/scripts/safari_zone.pory"

# 55 "data/scripts/safari_zone.pory"
SafariZone_EventScript_ChoosePokeblock::
# 56 "data/scripts/safari_zone.pory"
	fadescreen FADE_TO_BLACK
# 57 "data/scripts/safari_zone.pory"
	special OpenPokeblockCaseOnFeeder
# 58 "data/scripts/safari_zone.pory"
	waitstate
# 59 "data/scripts/safari_zone.pory"
	compare VAR_RESULT, 0xFFFF
# 60 "data/scripts/safari_zone.pory"
	goto_if_ne SafariZone_EventScript_PokeblockPlaced
# 61 "data/scripts/safari_zone.pory"
	end
# 62 "data/scripts/safari_zone.pory"

# 63 "data/scripts/safari_zone.pory"
SafariZone_EventScript_PokeblockPlaced::
# 64 "data/scripts/safari_zone.pory"
	message SafariZone_Text_PokeblockWasPlaced
# 65 "data/scripts/safari_zone.pory"
	waitmessage
# 66 "data/scripts/safari_zone.pory"
	waitbuttonpress
# 67 "data/scripts/safari_zone.pory"
	releaseall
# 68 "data/scripts/safari_zone.pory"
	end
# 69 "data/scripts/safari_zone.pory"

# 70 "data/scripts/safari_zone.pory"
SafariZone_EventScript_PokeblockPresent::
# 71 "data/scripts/safari_zone.pory"
	message SafariZone_Text_PokeblockStillHere
# 72 "data/scripts/safari_zone.pory"
	waitmessage
# 73 "data/scripts/safari_zone.pory"
	waitbuttonpress
# 74 "data/scripts/safari_zone.pory"
	releaseall
# 75 "data/scripts/safari_zone.pory"
	end
# 76 "data/scripts/safari_zone.pory"

# 77 "data/scripts/safari_zone.pory"
SafariZone_Text_WouldYouLikeToExit:
# 78 "data/scripts/safari_zone.pory"
	.string "Would you like to exit the Safari\n"
# 79 "data/scripts/safari_zone.pory"
	.string "Zone right now?$"
# 80 "data/scripts/safari_zone.pory"

# 81 "data/scripts/safari_zone.pory"
SafariZone_Text_TimesUp:
# 82 "data/scripts/safari_zone.pory"
	.string "Ding-dong! Time's up!\n"
# 83 "data/scripts/safari_zone.pory"
	.string "Your Safari Game is over.$"
# 84 "data/scripts/safari_zone.pory"

# 85 "data/scripts/safari_zone.pory"
SafariZone_Text_OutOfBalls:
# 86 "data/scripts/safari_zone.pory"
	.string "You've run out of Safari Balls.\n"
# 87 "data/scripts/safari_zone.pory"
	.string "Your Safari Game is over.$"
# 88 "data/scripts/safari_zone.pory"

# 89 "data/scripts/safari_zone.pory"
SafariZone_Text_PlacePokeblockOnFeeder:
# 90 "data/scripts/safari_zone.pory"
	.string "Would you like to place a {POKEBLOCK}\n"
# 91 "data/scripts/safari_zone.pory"
	.string "on the {POKEBLOCK} Feeder?$"
# 92 "data/scripts/safari_zone.pory"

# 93 "data/scripts/safari_zone.pory"
SafariZone_Text_PokeblockStillHere:
# 94 "data/scripts/safari_zone.pory"
	.string "The {STR_VAR_1} you left\n"
# 95 "data/scripts/safari_zone.pory"
	.string "before is still here.$"
# 96 "data/scripts/safari_zone.pory"

# 97 "data/scripts/safari_zone.pory"
SafariZone_Text_PokeblockWasPlaced:
# 98 "data/scripts/safari_zone.pory"
	.string "The {STR_VAR_1} was placed\n"
# 99 "data/scripts/safari_zone.pory"
	.string "on the {POKEBLOCK} Feeder.$"
# 100 "data/scripts/safari_zone.pory"

# 101 "data/scripts/safari_zone.pory"
Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
# 102 "data/scripts/safari_zone.pory"
	.string "Welcome to the Safari Zone!\p"
# 103 "data/scripts/safari_zone.pory"
	.string "Here, you may witness many kinds of\n"
# 104 "data/scripts/safari_zone.pory"
	.string "Pokémon rarely seen in Hoenn.\p"
# 105 "data/scripts/safari_zone.pory"
	.string "And, you'll see them in their wild,\n"
# 106 "data/scripts/safari_zone.pory"
	.string "untamed state in natural habitats.\p"
# 107 "data/scripts/safari_zone.pory"
	.string "What's more, we've thrown open the\n"
# 108 "data/scripts/safari_zone.pory"
	.string "gates to Pokémon Trainers.\p"
# 109 "data/scripts/safari_zone.pory"
	.string "You're encouraged to catch Pokémon\n"
# 110 "data/scripts/safari_zone.pory"
	.string "for keeps!\p"
# 111 "data/scripts/safari_zone.pory"
	.string "Come in and enjoy the Safari Zone!$"
# 112 "data/scripts/safari_zone.pory"

# 113 "data/scripts/safari_zone.pory"
Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
# 114 "data/scripts/safari_zone.pory"
	.string "Welcome to the Safari Zone!\n"
# 115 "data/scripts/safari_zone.pory"
	.string "Is it your first time here?$"
# 116 "data/scripts/safari_zone.pory"

# 117 "data/scripts/safari_zone.pory"
Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
# 118 "data/scripts/safari_zone.pory"
	.string "Come in and enjoy the Safari Zone!$"
# 119 "data/scripts/safari_zone.pory"

# 120 "data/scripts/safari_zone.pory"
Route121_SafariZoneEntrance_Text_FirstTimeInfo:
# 121 "data/scripts/safari_zone.pory"
	.string "When you enter the Safari Zone, you\n"
# 122 "data/scripts/safari_zone.pory"
	.string "start with 30 Safari Balls for\l"
# 123 "data/scripts/safari_zone.pory"
	.string "catching Pokémon.\p"
# 124 "data/scripts/safari_zone.pory"
	.string "The Safari Game is over when you run\n"
# 125 "data/scripts/safari_zone.pory"
	.string "out of Safari Balls, or when you've\l"
# 126 "data/scripts/safari_zone.pory"
	.string "walked 500 steps.\p"
# 127 "data/scripts/safari_zone.pory"
	.string "Come in and enjoy the Safari Zone!$"
# 128 "data/scripts/safari_zone.pory"

# 129 "data/scripts/safari_zone.pory"
Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
# 130 "data/scripts/safari_zone.pory"
	.string "Welcome to the Safari Zone!\p"
# 131 "data/scripts/safari_zone.pory"
	.string "All you can catch for just ¥500!\n"
# 132 "data/scripts/safari_zone.pory"
	.string "Would you like to play a Safari Game?$"
# 133 "data/scripts/safari_zone.pory"

# 134 "data/scripts/safari_zone.pory"
Route121_SafariZoneEntrance_Text_HasSafariPass:
# 135 "data/scripts/safari_zone.pory"
	.string "Welcome to the Safari Zone!\p"
# 136 "data/scripts/safari_zone.pory"
	.string "All you can catch for just...\n"
# 137 "data/scripts/safari_zone.pory"
	.string "Huh?\p"
# 138 "data/scripts/safari_zone.pory"
	.string "That's a Safari Pass...\p"
# 139 "data/scripts/safari_zone.pory"
	.string "That means that you're allowed to\n"
# 140 "data/scripts/safari_zone.pory"
	.string "enter without restriction.\p"
# 141 "data/scripts/safari_zone.pory"
	.string "If you still want to play the\n"
# 142 "data/scripts/safari_zone.pory"
	.string "Safari game, please talk to me.$"
# 143 "data/scripts/safari_zone.pory"

# 144 "data/scripts/safari_zone.pory"
Route121_SafariZoneEntrance_Text_PlayAnotherTime:
# 145 "data/scripts/safari_zone.pory"
	.string "Okay.\n"
# 146 "data/scripts/safari_zone.pory"
	.string "Please play another time!$"
# 147 "data/scripts/safari_zone.pory"

# 148 "data/scripts/safari_zone.pory"
Route121_SafariZoneEntrance_Text_NotEnoughMoney:
# 149 "data/scripts/safari_zone.pory"
	.string "You don't have enough money.\n"
# 150 "data/scripts/safari_zone.pory"
	.string "Sorry.$"
# 151 "data/scripts/safari_zone.pory"

# 152 "data/scripts/safari_zone.pory"
Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
# 153 "data/scripts/safari_zone.pory"
	.string "That will be ¥500, please.$"
# 154 "data/scripts/safari_zone.pory"

# 155 "data/scripts/safari_zone.pory"
Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
# 156 "data/scripts/safari_zone.pory"
	.string "Here are your Safari Balls.$"
# 157 "data/scripts/safari_zone.pory"

# 158 "data/scripts/safari_zone.pory"
Route121_SafariZoneEntrance_Text_Received30SafariBalls:
# 159 "data/scripts/safari_zone.pory"
	.string "{PLAYER} received 30 Safari Balls.$"
# 160 "data/scripts/safari_zone.pory"

# 161 "data/scripts/safari_zone.pory"
Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
# 162 "data/scripts/safari_zone.pory"
	.string "We'll let you know when your game\n"
# 163 "data/scripts/safari_zone.pory"
	.string "is over.\p"
# 164 "data/scripts/safari_zone.pory"
	.string "So, until then, enjoy yourself, please!\n"
# 165 "data/scripts/safari_zone.pory"
	.string "Off you go on your wild excursion!$"
# 166 "data/scripts/safari_zone.pory"

# 167 "data/scripts/safari_zone.pory"
Route121_SafariZoneEntrance_Text_PCIsFull:
# 168 "data/scripts/safari_zone.pory"
	.string "Excuse me!\n"
# 169 "data/scripts/safari_zone.pory"
	.string "Your PC Box is full.$"
# 170 "data/scripts/safari_zone.pory"

# 171 "data/scripts/safari_zone.pory"
Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
# 172 "data/scripts/safari_zone.pory"
	.string "Excuse me!\n"
# 173 "data/scripts/safari_zone.pory"
	.string "You seem to be without a {POKEBLOCK} Case.\p"
# 174 "data/scripts/safari_zone.pory"
	.string "Your Safari Game will be much more\n"
# 175 "data/scripts/safari_zone.pory"
	.string "fruitful if you use {POKEBLOCK}s.\p"
# 176 "data/scripts/safari_zone.pory"
	.string "Please come back with a {POKEBLOCK} Case.\p"
# 177 "data/scripts/safari_zone.pory"
	.string "You may obtain a {POKEBLOCK} Case from\n"
# 178 "data/scripts/safari_zone.pory"
	.string "the Lilycove Contest Hall.$"
# 179 "data/scripts/safari_zone.pory"

# 180 "data/scripts/safari_zone.pory"
SafariZone_South_Text_StillHaveTimeExit:
# 181 "data/scripts/safari_zone.pory"
	.string "You still have time left. Would you like\n"
# 182 "data/scripts/safari_zone.pory"
	.string "to exit the Safari Zone now?$"
# 183 "data/scripts/safari_zone.pory"

# 184 "data/scripts/safari_zone.pory"
SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
# 185 "data/scripts/safari_zone.pory"
	.string "Please enjoy the rest of your wild\n"
# 186 "data/scripts/safari_zone.pory"
	.string "adventure!$"
# 187 "data/scripts/safari_zone.pory"

# 188 "data/scripts/safari_zone.pory"
SafariZone_South_Text_ExitEarlyThankYouForPlaying:
# 189 "data/scripts/safari_zone.pory"
	.string "Okay.\p"
# 190 "data/scripts/safari_zone.pory"
	.string "I'll take back your remaining Safari\n"
# 191 "data/scripts/safari_zone.pory"
	.string "Balls.\p"
# 192 "data/scripts/safari_zone.pory"
	.string "Thank you for playing.\n"
# 193 "data/scripts/safari_zone.pory"
	.string "We hope to see you again.$"
# 194 "data/scripts/safari_zone.pory"

# 195 "data/scripts/safari_zone.pory"
SafariZone_South_Text_GoodLuck:
# 196 "data/scripts/safari_zone.pory"
	.string "Good luck!\p"
# 197 "data/scripts/safari_zone.pory"
	.string "If you need anything, don't hesitate\n"
# 198 "data/scripts/safari_zone.pory"
	.string "to tell me, please!$"
# 199 "data/scripts/safari_zone.pory"

# 200 "data/scripts/safari_zone.pory"
SafariZone_South_Text_Boy:
# 201 "data/scripts/safari_zone.pory"
	.string "Did you know?\p"
# 202 "data/scripts/safari_zone.pory"
	.string "If you put a {POKEBLOCK} in that square box,\n"
# 203 "data/scripts/safari_zone.pory"
	.string "Pokémon gather around.$"
# 204 "data/scripts/safari_zone.pory"

# 205 "data/scripts/safari_zone.pory"
SafariZone_South_Text_Man:
# 206 "data/scripts/safari_zone.pory"
	.string "I want to keep going deeper, but I\n"
# 207 "data/scripts/safari_zone.pory"
	.string "forgot to bring a Bike.\p"
# 208 "data/scripts/safari_zone.pory"
	.string "Something tells me that rare Pokémon\n"
# 209 "data/scripts/safari_zone.pory"
	.string "live in the outlying areas.$"
# 210 "data/scripts/safari_zone.pory"

# 211 "data/scripts/safari_zone.pory"
SafariZone_Southwest_Text_Woman:
# 212 "data/scripts/safari_zone.pory"
	.string "Sometimes, when I toss a {POKEBLOCK} at \n"
# 213 "data/scripts/safari_zone.pory"
	.string "Pokémon, it gets ignored.\p"
# 214 "data/scripts/safari_zone.pory"
	.string "Do Pokémon have likes and dislikes\n"
# 215 "data/scripts/safari_zone.pory"
	.string "about what they eat?$"
# 216 "data/scripts/safari_zone.pory"

# 217 "data/scripts/safari_zone.pory"
SafariZone_Northwest_Text_Man:
# 218 "data/scripts/safari_zone.pory"
	.string "Gasp… Gasp…\n"
# 219 "data/scripts/safari_zone.pory"
	.string "I…made it out here…but…\p"
# 220 "data/scripts/safari_zone.pory"
	.string "I'm exhausted… I don't have the\n"
# 221 "data/scripts/safari_zone.pory"
	.string "energy to catch Pokémon…$"
# 222 "data/scripts/safari_zone.pory"

# 223 "data/scripts/safari_zone.pory"
SafariZone_North_Text_Fisherman:
# 224 "data/scripts/safari_zone.pory"
	.string "I'm on a mission to find Water Pokémon\n"
# 225 "data/scripts/safari_zone.pory"
	.string "you don't see in Hoenn.\p"
# 226 "data/scripts/safari_zone.pory"
	.string "Do you have any idea where the lake is?$"
# 227 "data/scripts/safari_zone.pory"

# 228 "data/scripts/safari_zone.pory"
SafariZone_North_Text_Man:
# 229 "data/scripts/safari_zone.pory"
	.string "I'm going to catch a lot of rare Pokémon\n"
# 230 "data/scripts/safari_zone.pory"
	.string "here and trade them with my friends!$"
# 231 "data/scripts/safari_zone.pory"

# 232 "data/scripts/safari_zone.pory"
SafariZone_South_Text_Youngster:
# 233 "data/scripts/safari_zone.pory"
	.string "I put a {POKEBLOCK} on the {POKEBLOCK} Feeder.\n"
# 234 "data/scripts/safari_zone.pory"
	.string "But it seems to have disappeared.\p"
# 235 "data/scripts/safari_zone.pory"
	.string "I guess Pokémon must have eaten it\n"
# 236 "data/scripts/safari_zone.pory"
	.string "without me noticing.$"
# 237 "data/scripts/safari_zone.pory"

# 238 "data/scripts/safari_zone.pory"
Route121_SafariZoneEntrance_Text_TrainerTip:
# 239 "data/scripts/safari_zone.pory"
	.string "Safari Zone Trainer Tip!\p"
# 240 "data/scripts/safari_zone.pory"
	.string "Throw {POKEBLOCK}s at wild Pokémon to make\n"
# 241 "data/scripts/safari_zone.pory"
	.string "them less likely to flee.$"
# 242 "data/scripts/safari_zone.pory"

# 243 "data/scripts/safari_zone.pory"
SafariZone_Southwest_Text_RestHouseSign:
# 244 "data/scripts/safari_zone.pory"
	.string "“Relieve your tired feet.”\n"
# 245 "data/scripts/safari_zone.pory"
	.string "Rest House$"
# 246 "data/scripts/safari_zone.pory"

# 247 "data/scripts/safari_zone.pory"
SafariZone_RestHouse_Text_Youngster:
# 248 "data/scripts/safari_zone.pory"
	.string "I don't have any {POKEBLOCK}s, but I caught\n"
# 249 "data/scripts/safari_zone.pory"
	.string "a good number of Pokémon.\p"
# 250 "data/scripts/safari_zone.pory"
	.string "You can improve your chances of making\n"
# 251 "data/scripts/safari_zone.pory"
	.string "a catch by getting closer to them\l"
# 252 "data/scripts/safari_zone.pory"
	.string "before throwing a Safari Ball.$"
# 253 "data/scripts/safari_zone.pory"

# 254 "data/scripts/safari_zone.pory"
SafariZone_RestHouse_Text_PsychicM:
# 255 "data/scripts/safari_zone.pory"
	.string "If you use {POKEBLOCK}s, wild Pokémon won't\n"
# 256 "data/scripts/safari_zone.pory"
	.string "be so quick to run away.\p"
# 257 "data/scripts/safari_zone.pory"
	.string "It's not much use to give {POKEBLOCK}s to\n"
# 258 "data/scripts/safari_zone.pory"
	.string "Pokémon that don't flee easily.$"
# 259 "data/scripts/safari_zone.pory"

# 260 "data/scripts/safari_zone.pory"
SafariZone_RestHouse_Text_FatMan:
# 261 "data/scripts/safari_zone.pory"
	.string "If you put a {POKEBLOCK} on the Feeder,\n"
# 262 "data/scripts/safari_zone.pory"
	.string "Pokémon are attracted to it.\p"
# 263 "data/scripts/safari_zone.pory"
	.string "I think Pokémon with the same sort of\n"
# 264 "data/scripts/safari_zone.pory"
	.string "nature are drawn by a certain {POKEBLOCK}.$"
# 265 "data/scripts/safari_zone.pory"

# 266 "data/scripts/safari_zone.pory"
SafariZone_South_Text_AreaOffLimits1:
# 267 "data/scripts/safari_zone.pory"
	.string "This area is still under construction.\n"
# 268 "data/scripts/safari_zone.pory"
	.string "It's off-limits, sorry!$"
# 269 "data/scripts/safari_zone.pory"

# 270 "data/scripts/safari_zone.pory"
SafariZone_Southeast_Text_ExpansionIsFinished:
# 271 "data/scripts/safari_zone.pory"
	.string "The Safari Zone's expansion project\n"
# 272 "data/scripts/safari_zone.pory"
	.string "is finished now.\p"
# 273 "data/scripts/safari_zone.pory"
	.string "We hope you will enjoy the new area.$"
# 274 "data/scripts/safari_zone.pory"

# 275 "data/scripts/safari_zone.pory"
SafariZone_South_Text_AreaOffLimits2:
# 276 "data/scripts/safari_zone.pory"
	.string "This area is still under construction.\n"
# 277 "data/scripts/safari_zone.pory"
	.string "It's off-limits, sorry!$"
# 278 "data/scripts/safari_zone.pory"

# 279 "data/scripts/safari_zone.pory"
SafariZone_Southeast_Text_LittleGirl:
# 280 "data/scripts/safari_zone.pory"
	.string "Wow! Whee! I haven't seen any of\n"
# 281 "data/scripts/safari_zone.pory"
	.string "these Pokémon before!$"
# 282 "data/scripts/safari_zone.pory"

# 283 "data/scripts/safari_zone.pory"
SafariZone_Southeast_Text_FatMan:
# 284 "data/scripts/safari_zone.pory"
	.string "The Pokémon in this area are all\n"
# 285 "data/scripts/safari_zone.pory"
	.string "new to me.\p"
# 286 "data/scripts/safari_zone.pory"
	.string "And I'm allowed to catch these rare\n"
# 287 "data/scripts/safari_zone.pory"
	.string "Pokémon! Too cool!$"
# 288 "data/scripts/safari_zone.pory"

# 289 "data/scripts/safari_zone.pory"
SafariZone_Southeast_Text_RichBoy:
# 290 "data/scripts/safari_zone.pory"
	.string "The Pokémon around here seem to be\n"
# 291 "data/scripts/safari_zone.pory"
	.string "from somewhere other than Hoenn.$"
# 292 "data/scripts/safari_zone.pory"

# 293 "data/scripts/safari_zone.pory"
SafariZone_Northeast_Text_Boy:
# 294 "data/scripts/safari_zone.pory"
	.string "I only have a couple Safari Balls left.\p"
# 295 "data/scripts/safari_zone.pory"
	.string "I'm having a hard time trying to\n"
# 296 "data/scripts/safari_zone.pory"
	.string "decide what I should catch.$"
# 297 "data/scripts/safari_zone.pory"

# 298 "data/scripts/safari_zone.pory"
SafariZone_Northeast_Text_Woman:
# 299 "data/scripts/safari_zone.pory"
	.string "I heard that you can see Pikachu here.\n"
# 300 "data/scripts/safari_zone.pory"
	.string "Where might one be?$"
# 301 "data/scripts/safari_zone.pory"

# 302 "data/scripts/safari_zone.pory"
SafariZone_Northeast_Text_Girl:
# 303 "data/scripts/safari_zone.pory"
	.string "Oh, boo!\n"
# 304 "data/scripts/safari_zone.pory"
	.string "I can't seem to catch anything!\p"
# 305 "data/scripts/safari_zone.pory"
	.string "I'll end up wasting the admission\n"
# 306 "data/scripts/safari_zone.pory"
	.string "price if I don't catch something!$"
