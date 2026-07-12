# 1 "data/scripts/test_signpost.pory"

# 2 "data/scripts/test_signpost.pory"
Text_ThisIsATestSignpostMsg::
# 3 "data/scripts/test_signpost.pory"
	.string "This is a test message.\n"
# 4 "data/scripts/test_signpost.pory"
	.string "This is a signpost.$"
# 5 "data/scripts/test_signpost.pory"

# 6 "data/scripts/test_signpost.pory"
EventScript_TestSignpostMsg::
# 7 "data/scripts/test_signpost.pory"
	msgbox Text_ThisIsATestSignpostMsg, MSGBOX_SIGN
# 8 "data/scripts/test_signpost.pory"
	end
# 9 "data/scripts/test_signpost.pory"

# 10 "data/scripts/test_signpost.pory"
Text_Flying_Follower::
# 11 "data/scripts/test_signpost.pory"
	.string "Do you want to Fly\n"
# 12 "data/scripts/test_signpost.pory"
	.string "with your Pokémon?$"
# 13 "data/scripts/test_signpost.pory"

# 14 "data/scripts/test_signpost.pory"
EventScript_Flying_Follower::
# 15 "data/scripts/test_signpost.pory"
    lock
# 16 "data/scripts/test_signpost.pory"
    faceplayer
# 17 "data/scripts/test_signpost.pory"
    msgbox Text_Flying_Follower, MSGBOX_YESNO
# 18 "data/scripts/test_signpost.pory"
    compare VAR_RESULT, YES
# 19 "data/scripts/test_signpost.pory"
    goto_if_eq EventScript_Flying_Follower_ChooseDestination
# 20 "data/scripts/test_signpost.pory"
    compare VAR_RESULT, NO
# 21 "data/scripts/test_signpost.pory"
    goto_if_eq EventScript_Flying_Follower_Goodbye
# 22 "data/scripts/test_signpost.pory"
    end
# 23 "data/scripts/test_signpost.pory"

# 24 "data/scripts/test_signpost.pory"
EventScript_Flying_Follower_ChooseDestination::
# 25 "data/scripts/test_signpost.pory"
	setvar VAR_0x800A, LAST_TALKED_TO_FLYING_TAXI
# 26 "data/scripts/test_signpost.pory"
    special FieldLoadFlyMap
# 27 "data/scripts/test_signpost.pory"
    goto EventScript_Flying_Follower_Goodbye
# 28 "data/scripts/test_signpost.pory"
    end
# 29 "data/scripts/test_signpost.pory"

# 30 "data/scripts/test_signpost.pory"
EventScript_Flying_Follower_Goodbye::
# 31 "data/scripts/test_signpost.pory"
    setvar VAR_LAST_TALKED, 0
# 32 "data/scripts/test_signpost.pory"
    releaseall
# 33 "data/scripts/test_signpost.pory"
    return
# 34 "data/scripts/test_signpost.pory"

# 35 "data/scripts/test_signpost.pory"
EventScript_Normal_Follower::
# 36 "data/scripts/test_signpost.pory"
    releaseall
# 37 "data/scripts/test_signpost.pory"
    return
# 38 "data/scripts/test_signpost.pory"
	end
# 39 "data/scripts/test_signpost.pory"

# 40 "data/scripts/test_signpost.pory"
gText_FollowerLovesYou::
# 41 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1} is regarding you with\nadoration!$"
# 42 "data/scripts/test_signpost.pory"

# 43 "data/scripts/test_signpost.pory"
gText_FollowerLostInThought::
# 44 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1} seems lost in thought.$"
# 45 "data/scripts/test_signpost.pory"

# 46 "data/scripts/test_signpost.pory"
gText_FollowerDefault::
# 47 "data/scripts/test_signpost.pory"
  .string "ERROR 404: Script not found.$"
# 48 "data/scripts/test_signpost.pory"

# 49 "data/scripts/test_signpost.pory"
gText_FollowerUnhappyToBeWet::
# 50 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1} looks unhappy to be wet.$"
# 51 "data/scripts/test_signpost.pory"

# 52 "data/scripts/test_signpost.pory"
gText_FollowerSplashesAround::
# 53 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1} splashes around happily!$"
# 54 "data/scripts/test_signpost.pory"

# 55 "data/scripts/test_signpost.pory"
gText_WantsToFly::
# 56 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1} looks up at the\nsky restlessly.\pWould you like to Fly?$"
# 57 "data/scripts/test_signpost.pory"

# 58 "data/scripts/test_signpost.pory"
gText_FollowerUnhappyFace::
# 59 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1} is making an unhappy face...$"
# 60 "data/scripts/test_signpost.pory"

# 61 "data/scripts/test_signpost.pory"
gText_FollowerDislikesThisPlace::
# 62 "data/scripts/test_signpost.pory"
  .string "It looks like {STR_VAR_1} \nreally dislikes this place$"
# 63 "data/scripts/test_signpost.pory"

# 64 "data/scripts/test_signpost.pory"
gText_FollowerLikesThisPlace::
# 65 "data/scripts/test_signpost.pory"
  .string "It looks like {STR_VAR_1} \nis happy to be here$"
# 66 "data/scripts/test_signpost.pory"

# 67 "data/scripts/test_signpost.pory"
gText_FollowerHappyRain::
# 68 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1} seems to be happy\nabout the rain!$"
# 69 "data/scripts/test_signpost.pory"

# 70 "data/scripts/test_signpost.pory"
gText_FollowerHappySnow::
# 71 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1} is happily playing\nwith the snow!$"
# 72 "data/scripts/test_signpost.pory"

# 73 "data/scripts/test_signpost.pory"
gText_FollowerHoldingItem::
# 74 "data/scripts/test_signpost.pory"
  .string "It looks like {STR_VAR_1} its holding\nsomething!$"
# 75 "data/scripts/test_signpost.pory"

# 76 "data/scripts/test_signpost.pory"
gText_FollowerPresent::
# 77 "data/scripts/test_signpost.pory"
  .string "It looks like {STR_VAR_1} has a gift\nfor you!$"
# 78 "data/scripts/test_signpost.pory"

# 79 "data/scripts/test_signpost.pory"
gText_FollowerMetLocation::
# 80 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1} looks around fondly.\nIt seems familiar with this place.$"
# 81 "data/scripts/test_signpost.pory"

# 82 "data/scripts/test_signpost.pory"
gText_FollowerSkeptical::
# 83 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1} looks skeptical...\pWhat could it mean?$"
# 84 "data/scripts/test_signpost.pory"

# 85 "data/scripts/test_signpost.pory"
gText_FollowerAppraising::
# 86 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1} carefully follows behind.$"
# 87 "data/scripts/test_signpost.pory"

# 88 "data/scripts/test_signpost.pory"
gText_FollowerPickup::
# 89 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1} is carefully looking\naround for items.$"
# 90 "data/scripts/test_signpost.pory"

# 91 "data/scripts/test_signpost.pory"
gText_FollowerHappyWalk::
# 92 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1} skips happily behind you!$"
# 93 "data/scripts/test_signpost.pory"

# 94 "data/scripts/test_signpost.pory"
gText_FollowerAboutToFall::
# 95 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1} seems to be about\nto fall over!$"
# 96 "data/scripts/test_signpost.pory"

# 97 "data/scripts/test_signpost.pory"
gText_FollowerTryingToKeepUp::
# 98 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1} is trying very hard\nto keep up with you...$"
# 99 "data/scripts/test_signpost.pory"

# 100 "data/scripts/test_signpost.pory"
gText_FollowerIsShivering::
# 101 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1} is shivering.$"
# 102 "data/scripts/test_signpost.pory"

# 103 "data/scripts/test_signpost.pory"
gText_FollowerBurnPainful::
# 104 "data/scripts/test_signpost.pory"
  .string "{STR_VAR_1}'s burn looks painful!$'"
# 105 "data/scripts/test_signpost.pory"

# 106 "data/scripts/test_signpost.pory"
.macro playfirstmoncry
# 107 "data/scripts/test_signpost.pory"
callfunc ScrFunc_playfirstmoncry
# 108 "data/scripts/test_signpost.pory"
.endm
# 109 "data/scripts/test_signpost.pory"

# 110 "data/scripts/test_signpost.pory"
.macro bufferlivemonspeciesname out:req
# 111 "data/scripts/test_signpost.pory"
callfunc ScrFunc_bufferlivemonspeciesname
# 112 "data/scripts/test_signpost.pory"
.byte \out
# 113 "data/scripts/test_signpost.pory"
.endm
# 114 "data/scripts/test_signpost.pory"

# 115 "data/scripts/test_signpost.pory"
EventScript_Follower::
# 116 "data/scripts/test_signpost.pory"
  lock
# 117 "data/scripts/test_signpost.pory"
  faceplayer
# 118 "data/scripts/test_signpost.pory"
  bufferlivemonspeciesname 0
# 119 "data/scripts/test_signpost.pory"
  playfirstmoncry
# 120 "data/scripts/test_signpost.pory"
  callfunc ScrFunc_getfolloweraction
# 121 "data/scripts/test_signpost.pory"
  canFollowerFly
# 122 "data/scripts/test_signpost.pory"
  compare VAR_RESULT 6
# 123 "data/scripts/test_signpost.pory"
  goto_if_eq EventScript_FollowerEnd
# 124 "data/scripts/test_signpost.pory"
  bufferlivemonspeciesname 0
# 125 "data/scripts/test_signpost.pory"
  msgbox gText_WantsToFly, MSGBOX_YESNO
# 126 "data/scripts/test_signpost.pory"
  switch VAR_RESULT
# 127 "data/scripts/test_signpost.pory"
  case NO, EventScript_FollowerEnd
# 128 "data/scripts/test_signpost.pory"
  case YES, EventScript_FollowerFly
# 129 "data/scripts/test_signpost.pory"
  case MULTI_B_PRESSED, EventScript_FollowerEnd
# 130 "data/scripts/test_signpost.pory"
EventScript_FollowerFly::
# 131 "data/scripts/test_signpost.pory"
  callfunc ScrFunc_followerfly
# 132 "data/scripts/test_signpost.pory"
EventScript_FollowerEnd::
# 133 "data/scripts/test_signpost.pory"
  release
# 134 "data/scripts/test_signpost.pory"
  end
# 135 "data/scripts/test_signpost.pory"

# 136 "data/scripts/test_signpost.pory"
EventScript_FollowerHappyWalk::
# 137 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerHappyWalk, MSGBOX_DEFAULT
# 138 "data/scripts/test_signpost.pory"
  waitmoncry
# 139 "data/scripts/test_signpost.pory"
  return
# 140 "data/scripts/test_signpost.pory"

# 141 "data/scripts/test_signpost.pory"
EventScript_FollowerPickup::
# 142 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerPickup, MSGBOX_DEFAULT
# 143 "data/scripts/test_signpost.pory"
  waitmoncry
# 144 "data/scripts/test_signpost.pory"
  return
# 145 "data/scripts/test_signpost.pory"

# 146 "data/scripts/test_signpost.pory"
EventScript_FollowerHoldingItem::
# 147 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerHoldingItem, MSGBOX_DEFAULT
# 148 "data/scripts/test_signpost.pory"
  waitmoncry
# 149 "data/scripts/test_signpost.pory"
  giveitem ITEM_POKE_BALL
# 150 "data/scripts/test_signpost.pory"
  return
# 151 "data/scripts/test_signpost.pory"

# 152 "data/scripts/test_signpost.pory"
EventScript_FollowerPresent_1::
# 153 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerPresent, MSGBOX_DEFAULT
# 154 "data/scripts/test_signpost.pory"
  waitmoncry
# 155 "data/scripts/test_signpost.pory"
  giveitem ITEM_SNOWBALL
# 156 "data/scripts/test_signpost.pory"
  return
# 157 "data/scripts/test_signpost.pory"

# 158 "data/scripts/test_signpost.pory"
EventScript_FollowerPresent_2::
# 159 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerPresent, MSGBOX_DEFAULT
# 160 "data/scripts/test_signpost.pory"
  waitmoncry
# 161 "data/scripts/test_signpost.pory"
  giveitem ITEM_CHARCOAL
# 162 "data/scripts/test_signpost.pory"
  return
# 163 "data/scripts/test_signpost.pory"

# 164 "data/scripts/test_signpost.pory"
EventScript_FollowerAppraising::
# 165 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerAppraising, MSGBOX_DEFAULT
# 166 "data/scripts/test_signpost.pory"
  waitmoncry
# 167 "data/scripts/test_signpost.pory"
  return
# 168 "data/scripts/test_signpost.pory"

# 169 "data/scripts/test_signpost.pory"
EventScript_FollowerSkeptical::
# 170 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerSkeptical, MSGBOX_DEFAULT
# 171 "data/scripts/test_signpost.pory"
  waitmoncry
# 172 "data/scripts/test_signpost.pory"
  return
# 173 "data/scripts/test_signpost.pory"

# 174 "data/scripts/test_signpost.pory"
EventScript_FollowerMetLocation::
# 175 "data/scripts/test_signpost.pory"
  applymovement 0xFE Common_Movement_QuestionMark
# 176 "data/scripts/test_signpost.pory"
  waitmoncry
# 177 "data/scripts/test_signpost.pory"
  waitmovement 0xFE
# 178 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerMetLocation, MSGBOX_DEFAULT
# 179 "data/scripts/test_signpost.pory"
  return
# 180 "data/scripts/test_signpost.pory"

# 181 "data/scripts/test_signpost.pory"
EventScript_FollowerUnhappyFace::
# 182 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerUnhappyFace, MSGBOX_DEFAULT
# 183 "data/scripts/test_signpost.pory"
  waitmoncry
# 184 "data/scripts/test_signpost.pory"
  return
# 185 "data/scripts/test_signpost.pory"

# 186 "data/scripts/test_signpost.pory"
EventScript_FollowerDislikesThisPlace::
# 187 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerDislikesThisPlace, MSGBOX_DEFAULT
# 188 "data/scripts/test_signpost.pory"
  waitmoncry
# 189 "data/scripts/test_signpost.pory"
  return
# 190 "data/scripts/test_signpost.pory"

# 191 "data/scripts/test_signpost.pory"
EventScript_FollowerLikesThisPlace::
# 192 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerLikesThisPlace, MSGBOX_DEFAULT
# 193 "data/scripts/test_signpost.pory"
  waitmoncry
# 194 "data/scripts/test_signpost.pory"
  return
# 195 "data/scripts/test_signpost.pory"

# 196 "data/scripts/test_signpost.pory"
EventScript_FollowerHappySnow::
# 197 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerHappySnow, MSGBOX_DEFAULT
# 198 "data/scripts/test_signpost.pory"
  waitmoncry
# 199 "data/scripts/test_signpost.pory"
  return
# 200 "data/scripts/test_signpost.pory"

# 201 "data/scripts/test_signpost.pory"
EventScript_FollowerHappyRain::
# 202 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerHappyRain, MSGBOX_DEFAULT
# 203 "data/scripts/test_signpost.pory"
  waitmoncry
# 204 "data/scripts/test_signpost.pory"
  return
# 205 "data/scripts/test_signpost.pory"

# 206 "data/scripts/test_signpost.pory"
EventScript_FollowerUnhappyToBeWet::
# 207 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerUnhappyToBeWet, MSGBOX_DEFAULT
# 208 "data/scripts/test_signpost.pory"
  waitmoncry
# 209 "data/scripts/test_signpost.pory"
  return
# 210 "data/scripts/test_signpost.pory"

# 211 "data/scripts/test_signpost.pory"
EventScript_FollowerSplashesAbout::
# 212 "data/scripts/test_signpost.pory"
  applymovement 0xFE FollowerSplashMovement
# 213 "data/scripts/test_signpost.pory"
  waitmovement 0xFE
# 214 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerSplashesAround, MSGBOX_DEFAULT
# 215 "data/scripts/test_signpost.pory"
  return
# 216 "data/scripts/test_signpost.pory"

# 217 "data/scripts/test_signpost.pory"
EventScript_FollowerLovesYou::
# 218 "data/scripts/test_signpost.pory"
  applymovement 0xFE ContestHall_Movement_Heart
# 219 "data/scripts/test_signpost.pory"
  waitmovement 0xFE
# 220 "data/scripts/test_signpost.pory"
  waitmoncry
# 221 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerLovesYou, MSGBOX_DEFAULT
# 222 "data/scripts/test_signpost.pory"
  return
# 223 "data/scripts/test_signpost.pory"

# 224 "data/scripts/test_signpost.pory"
EventScript_FollowerAboutToFall::
# 225 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerAboutToFall, MSGBOX_DEFAULT
# 226 "data/scripts/test_signpost.pory"
  waitmoncry
# 227 "data/scripts/test_signpost.pory"
  return
# 228 "data/scripts/test_signpost.pory"

# 229 "data/scripts/test_signpost.pory"
EventScript_FollowerTryingToKeepUp::
# 230 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerTryingToKeepUp, MSGBOX_DEFAULT
# 231 "data/scripts/test_signpost.pory"
  waitmoncry
# 232 "data/scripts/test_signpost.pory"
  return
# 233 "data/scripts/test_signpost.pory"

# 234 "data/scripts/test_signpost.pory"
EventScript_FollowerIsShivering::
# 235 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerIsShivering, MSGBOX_DEFAULT
# 236 "data/scripts/test_signpost.pory"
  waitmoncry
# 237 "data/scripts/test_signpost.pory"
  return
# 238 "data/scripts/test_signpost.pory"

# 239 "data/scripts/test_signpost.pory"
EventScript_FollowerBurnPainful::
# 240 "data/scripts/test_signpost.pory"
  msgbox gText_FollowerBurnPainful, MSGBOX_DEFAULT
# 241 "data/scripts/test_signpost.pory"
  waitmoncry
# 242 "data/scripts/test_signpost.pory"
  return
# 243 "data/scripts/test_signpost.pory"

# 244 "data/scripts/test_signpost.pory"
FollowerSplashMovement:: @ defined in movement.inc
# 245 "data/scripts/test_signpost.pory"
  jump_in_place_down
# 246 "data/scripts/test_signpost.pory"
  delay_4
# 247 "data/scripts/test_signpost.pory"
  jump_in_place_down
# 248 "data/scripts/test_signpost.pory"
  face_player
# 249 "data/scripts/test_signpost.pory"
  step_end
