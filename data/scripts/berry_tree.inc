# 1 "data/scripts/berry_tree.pory"

# 2 "data/scripts/berry_tree.pory"
BerryTreeScript::
# 3 "data/scripts/berry_tree.pory"
	special ObjectEventInteractionGetBerryTreeData
# 4 "data/scripts/berry_tree.pory"
	switch VAR_0x8004
# 5 "data/scripts/berry_tree.pory"
	case BERRY_STAGE_SPARKLING, BerryTree_EventScript_Sparkling
# 6 "data/scripts/berry_tree.pory"
	case BERRY_STAGE_NO_BERRY, BerryTree_EventScript_CheckSoil
# 7 "data/scripts/berry_tree.pory"
	case BERRY_STAGE_PLANTED, BerryTree_EventScript_CheckBerryStage1
# 8 "data/scripts/berry_tree.pory"
	case BERRY_STAGE_SPROUTED, BerryTree_EventScript_CheckBerryStage2
# 9 "data/scripts/berry_tree.pory"
	case BERRY_STAGE_TALLER, BerryTree_EventScript_CheckBerryStage3
# 10 "data/scripts/berry_tree.pory"
	case BERRY_STAGE_FLOWERING, BerryTree_EventScript_CheckBerryStage4
# 11 "data/scripts/berry_tree.pory"
	case BERRY_STAGE_BERRIES, BerryTree_EventScript_CheckBerryFullyGrown
# 12 "data/scripts/berry_tree.pory"
	end
# 13 "data/scripts/berry_tree.pory"

# 14 "data/scripts/berry_tree.pory"
BerryTree_EventScript_Sparkling::
# 15 "data/scripts/berry_tree.pory"
	lockall
# 16 "data/scripts/berry_tree.pory"
	message BerryTree_Text_ExclamationPoint
# 17 "data/scripts/berry_tree.pory"
	waitmessage
# 18 "data/scripts/berry_tree.pory"
	waitbuttonpress
# 19 "data/scripts/berry_tree.pory"
	releaseall
# 20 "data/scripts/berry_tree.pory"
	end
# 21 "data/scripts/berry_tree.pory"

# 22 "data/scripts/berry_tree.pory"
BerryTree_EventScript_CheckSoil::
# 23 "data/scripts/berry_tree.pory"
	lock
# 24 "data/scripts/berry_tree.pory"
	faceplayer
# 25 "data/scripts/berry_tree.pory"
	specialvar VAR_RESULT, PlayerHasBerries
# 26 "data/scripts/berry_tree.pory"
	compare VAR_RESULT, TRUE
# 27 "data/scripts/berry_tree.pory"
	goto_if_eq BerryTree_EventScript_WantToPlant
# 28 "data/scripts/berry_tree.pory"
	message BerryTree_Text_ItsSoftLoamySoil
# 29 "data/scripts/berry_tree.pory"
	waitmessage
# 30 "data/scripts/berry_tree.pory"
	waitbuttonpress
# 31 "data/scripts/berry_tree.pory"
	release
# 32 "data/scripts/berry_tree.pory"
	end
# 33 "data/scripts/berry_tree.pory"

# 34 "data/scripts/berry_tree.pory"
BerryTree_EventScript_WantToPlant::
# 35 "data/scripts/berry_tree.pory"
	msgbox BerryTree_Text_WantToPlant, MSGBOX_YESNO
# 36 "data/scripts/berry_tree.pory"
	compare VAR_RESULT, YES
# 37 "data/scripts/berry_tree.pory"
	goto_if_eq BerryTree_EventScript_ChooseBerryToPlant
# 38 "data/scripts/berry_tree.pory"
	compare VAR_RESULT, NO
# 39 "data/scripts/berry_tree.pory"
	goto_if_eq BerryTree_EventScript_CancelPlanting
# 40 "data/scripts/berry_tree.pory"
	end
# 41 "data/scripts/berry_tree.pory"

# 42 "data/scripts/berry_tree.pory"
BerryTree_EventScript_ChooseBerryToPlant::
# 43 "data/scripts/berry_tree.pory"
	fadescreen FADE_TO_BLACK
# 44 "data/scripts/berry_tree.pory"
	closemessage
# 45 "data/scripts/berry_tree.pory"
	special Bag_ChooseBerry
# 46 "data/scripts/berry_tree.pory"
	waitstate
# 47 "data/scripts/berry_tree.pory"
	compare VAR_ITEM_ID, 0
# 48 "data/scripts/berry_tree.pory"
	goto_if_eq BerryTree_EventScript_CancelPlanting
# 49 "data/scripts/berry_tree.pory"
	removeitem VAR_ITEM_ID
# 50 "data/scripts/berry_tree.pory"
	call BerryTree_EventScript_PlantBerry
# 51 "data/scripts/berry_tree.pory"

# 52 "data/scripts/berry_tree.pory"
BerryTree_EventScript_CancelPlanting::
# 53 "data/scripts/berry_tree.pory"
	release
# 54 "data/scripts/berry_tree.pory"
	end
# 55 "data/scripts/berry_tree.pory"

# 56 "data/scripts/berry_tree.pory"
BerryTree_EventScript_CheckBerryStage1::
# 57 "data/scripts/berry_tree.pory"
	lockall
# 58 "data/scripts/berry_tree.pory"
	special ObjectEventInteractionGetBerryCountString
# 59 "data/scripts/berry_tree.pory"
	message BerryTree_Text_BerryGrowthStage1
# 60 "data/scripts/berry_tree.pory"
	waitmessage
# 61 "data/scripts/berry_tree.pory"
	waitbuttonpress
# 62 "data/scripts/berry_tree.pory"
	goto BerryTree_EventScript_WantToWater
# 63 "data/scripts/berry_tree.pory"

# 64 "data/scripts/berry_tree.pory"
BerryTree_EventScript_CheckBerryStage2::
# 65 "data/scripts/berry_tree.pory"
	lockall
# 66 "data/scripts/berry_tree.pory"
	special ObjectEventInteractionGetBerryName
# 67 "data/scripts/berry_tree.pory"
	message BerryTree_Text_BerryGrowthStage2
# 68 "data/scripts/berry_tree.pory"
	waitmessage
# 69 "data/scripts/berry_tree.pory"
	waitbuttonpress
# 70 "data/scripts/berry_tree.pory"
	goto BerryTree_EventScript_WantToWater
# 71 "data/scripts/berry_tree.pory"

# 72 "data/scripts/berry_tree.pory"
BerryTree_EventScript_CheckBerryStage3::
# 73 "data/scripts/berry_tree.pory"
	lockall
# 74 "data/scripts/berry_tree.pory"
	special ObjectEventInteractionGetBerryName
# 75 "data/scripts/berry_tree.pory"
	message BerryTree_Text_BerryGrowthStage3
# 76 "data/scripts/berry_tree.pory"
	waitmessage
# 77 "data/scripts/berry_tree.pory"
	waitbuttonpress
# 78 "data/scripts/berry_tree.pory"
	goto BerryTree_EventScript_WantToWater
# 79 "data/scripts/berry_tree.pory"

# 80 "data/scripts/berry_tree.pory"
BerryTree_EventScript_CheckBerryStage4::
# 81 "data/scripts/berry_tree.pory"
	call BerryTree_EventScript_GetCareAdverb
# 82 "data/scripts/berry_tree.pory"
	lockall
# 83 "data/scripts/berry_tree.pory"
	special ObjectEventInteractionGetBerryName
# 84 "data/scripts/berry_tree.pory"
	message BerryTree_Text_BerryGrowthStage4
# 85 "data/scripts/berry_tree.pory"
	waitmessage
# 86 "data/scripts/berry_tree.pory"
	waitbuttonpress
# 87 "data/scripts/berry_tree.pory"
	goto BerryTree_EventScript_WantToWater
# 88 "data/scripts/berry_tree.pory"

# 89 "data/scripts/berry_tree.pory"
@ VAR_0x8005 here is the number of times watered
# 90 "data/scripts/berry_tree.pory"
@ Buffered by ObjectEventInteractionGetBerryTreeData
# 91 "data/scripts/berry_tree.pory"
BerryTree_EventScript_GetCareAdverb::
# 92 "data/scripts/berry_tree.pory"
	compare VAR_0x8005, 0
# 93 "data/scripts/berry_tree.pory"
	goto_if_eq BerryTree_EventScript_SetAdverbPoor
# 94 "data/scripts/berry_tree.pory"
	compare VAR_0x8005, 4
# 95 "data/scripts/berry_tree.pory"
	goto_if_eq BerryTree_EventScript_SetAdverbGreat
# 96 "data/scripts/berry_tree.pory"
	bufferstring 1, BerryTree_Text_CareAdverbGood
# 97 "data/scripts/berry_tree.pory"
	return
# 98 "data/scripts/berry_tree.pory"

# 99 "data/scripts/berry_tree.pory"
BerryTree_EventScript_SetAdverbGreat::
# 100 "data/scripts/berry_tree.pory"
	bufferstring 1, BerryTree_Text_CareAdverbGreat
# 101 "data/scripts/berry_tree.pory"
	return
# 102 "data/scripts/berry_tree.pory"

# 103 "data/scripts/berry_tree.pory"
BerryTree_EventScript_SetAdverbPoor::
# 104 "data/scripts/berry_tree.pory"
	bufferstring 1, BerryTree_Text_CareAdverbPoor
# 105 "data/scripts/berry_tree.pory"
	return
# 106 "data/scripts/berry_tree.pory"

# 107 "data/scripts/berry_tree.pory"
@ VAR_0x8006 here is the number of berries
# 108 "data/scripts/berry_tree.pory"
BerryTree_EventScript_CheckBerryFullyGrown::
# 109 "data/scripts/berry_tree.pory"
	buffernumberstring 1, VAR_0x8006
# 110 "data/scripts/berry_tree.pory"
	lock
# 111 "data/scripts/berry_tree.pory"
	faceplayer
# 112 "data/scripts/berry_tree.pory"
	special ObjectEventInteractionGetBerryCountString
# 113 "data/scripts/berry_tree.pory"
	msgbox BerryTree_Text_WantToPick, MSGBOX_YESNO
# 114 "data/scripts/berry_tree.pory"
	compare VAR_RESULT, YES
# 115 "data/scripts/berry_tree.pory"
	goto_if_eq BerryTree_EventScript_PickBerry
# 116 "data/scripts/berry_tree.pory"
	compare VAR_RESULT, NO
# 117 "data/scripts/berry_tree.pory"
	goto_if_eq BerryTree_EventScript_CancelPickingBerry
# 118 "data/scripts/berry_tree.pory"

# 119 "data/scripts/berry_tree.pory"
BerryTree_EventScript_PickBerry::
# 120 "data/scripts/berry_tree.pory"
	special ObjectEventInteractionPickBerryTree
# 121 "data/scripts/berry_tree.pory"
	compare VAR_0x8004, 0
# 122 "data/scripts/berry_tree.pory"
	goto_if_eq BerryTree_EventScript_BerryPocketFull
# 123 "data/scripts/berry_tree.pory"
	special IncrementDailyPickedBerries
# 124 "data/scripts/berry_tree.pory"
	special ObjectEventInteractionRemoveBerryTree
# 125 "data/scripts/berry_tree.pory"
	message BerryTree_Text_PickedTheBerry
# 126 "data/scripts/berry_tree.pory"
    delay 10
# 127 "data/scripts/berry_tree.pory"
    showberrydesc
# 128 "data/scripts/berry_tree.pory"
	playfanfare MUS_OBTAIN_BERRY
# 129 "data/scripts/berry_tree.pory"
	waitmessage
# 130 "data/scripts/berry_tree.pory"
	waitfanfare
# 131 "data/scripts/berry_tree.pory"
	waitbuttonpress
# 132 "data/scripts/berry_tree.pory"
	message BerryTree_Text_PutAwayBerry
# 133 "data/scripts/berry_tree.pory"
	waitmessage
# 134 "data/scripts/berry_tree.pory"
	waitbuttonpress
# 135 "data/scripts/berry_tree.pory"
    hideitemdesc
# 136 "data/scripts/berry_tree.pory"
	release
# 137 "data/scripts/berry_tree.pory"
	end
# 138 "data/scripts/berry_tree.pory"

# 139 "data/scripts/berry_tree.pory"
BerryTree_EventScript_BerryPocketFull::
# 140 "data/scripts/berry_tree.pory"
	message BerryTree_Text_BerryPocketFull
# 141 "data/scripts/berry_tree.pory"
	waitmessage
# 142 "data/scripts/berry_tree.pory"
	waitbuttonpress
# 143 "data/scripts/berry_tree.pory"
	release
# 144 "data/scripts/berry_tree.pory"
	end
# 145 "data/scripts/berry_tree.pory"

# 146 "data/scripts/berry_tree.pory"
BerryTree_EventScript_CancelPickingBerry::
# 147 "data/scripts/berry_tree.pory"
	message BerryTree_Text_BerryLeftUnpicked
# 148 "data/scripts/berry_tree.pory"
	waitmessage
# 149 "data/scripts/berry_tree.pory"
	waitbuttonpress
# 150 "data/scripts/berry_tree.pory"
	release
# 151 "data/scripts/berry_tree.pory"
	end
# 152 "data/scripts/berry_tree.pory"

# 153 "data/scripts/berry_tree.pory"
BerryTree_EventScript_ItemUsePlantBerry::
# 154 "data/scripts/berry_tree.pory"
	lockall
# 155 "data/scripts/berry_tree.pory"
	special ObjectEventInteractionGetBerryTreeData
# 156 "data/scripts/berry_tree.pory"
	call BerryTree_EventScript_PlantBerry
# 157 "data/scripts/berry_tree.pory"
	releaseall
# 158 "data/scripts/berry_tree.pory"
	end
# 159 "data/scripts/berry_tree.pory"

# 160 "data/scripts/berry_tree.pory"
BerryTree_EventScript_WantToWater::
# 161 "data/scripts/berry_tree.pory"
	checkitem ITEM_WAILMER_PAIL, 1
# 162 "data/scripts/berry_tree.pory"
	compare VAR_RESULT, 0
# 163 "data/scripts/berry_tree.pory"
	goto_if_eq BerryTree_EventScript_DontWater
# 164 "data/scripts/berry_tree.pory"
	special ObjectEventInteractionGetBerryName
# 165 "data/scripts/berry_tree.pory"
	msgbox BerryTree_Text_WantToWater, MSGBOX_YESNO
# 166 "data/scripts/berry_tree.pory"
	compare VAR_RESULT, YES
# 167 "data/scripts/berry_tree.pory"
	goto_if_eq BerryTree_EventScript_WaterBerry
# 168 "data/scripts/berry_tree.pory"
	compare VAR_RESULT, NO
# 169 "data/scripts/berry_tree.pory"
	goto_if_eq BerryTree_EventScript_DontWater
# 170 "data/scripts/berry_tree.pory"

# 171 "data/scripts/berry_tree.pory"
BerryTree_EventScript_DontWater::
# 172 "data/scripts/berry_tree.pory"
	releaseall
# 173 "data/scripts/berry_tree.pory"
	end
# 174 "data/scripts/berry_tree.pory"

# 175 "data/scripts/berry_tree.pory"
BerryTree_EventScript_ItemUseWailmerPail::
# 176 "data/scripts/berry_tree.pory"
	special ObjectEventInteractionGetBerryTreeData
# 177 "data/scripts/berry_tree.pory"
	lockall
# 178 "data/scripts/berry_tree.pory"
BerryTree_EventScript_WaterBerry::
# 179 "data/scripts/berry_tree.pory"
	special ObjectEventInteractionGetBerryName
# 180 "data/scripts/berry_tree.pory"
	message BerryTree_Text_WateredTheBerry
# 181 "data/scripts/berry_tree.pory"
	waitmessage
# 182 "data/scripts/berry_tree.pory"
	special ObjectEventInteractionWaterBerryTree
# 183 "data/scripts/berry_tree.pory"
	special DoWateringBerryTreeAnim
# 184 "data/scripts/berry_tree.pory"
	waitstate
# 185 "data/scripts/berry_tree.pory"
	message BerryTree_Text_PlantIsDelighted
# 186 "data/scripts/berry_tree.pory"
	waitmessage
# 187 "data/scripts/berry_tree.pory"
	waitbuttonpress
# 188 "data/scripts/berry_tree.pory"
	releaseall
# 189 "data/scripts/berry_tree.pory"
	end
# 190 "data/scripts/berry_tree.pory"

# 191 "data/scripts/berry_tree.pory"
BerryTree_EventScript_PlantBerry::
# 192 "data/scripts/berry_tree.pory"
	special ObjectEventInteractionPlantBerryTree
# 193 "data/scripts/berry_tree.pory"
	incrementgamestat GAME_STAT_PLANTED_BERRIES
# 194 "data/scripts/berry_tree.pory"
	special IncrementDailyPlantedBerries
# 195 "data/scripts/berry_tree.pory"
	special ObjectEventInteractionGetBerryCountString
# 196 "data/scripts/berry_tree.pory"
	message BerryTree_Text_PlantedOneBerry
# 197 "data/scripts/berry_tree.pory"
	waitmessage
# 198 "data/scripts/berry_tree.pory"
	waitbuttonpress
# 199 "data/scripts/berry_tree.pory"
	return
# 200 "data/scripts/berry_tree.pory"

# 201 "data/scripts/berry_tree.pory"
BerryTree_Text_ItsSoftLoamySoil:
# 202 "data/scripts/berry_tree.pory"
	.string "It's soft, loamy soil.$"
# 203 "data/scripts/berry_tree.pory"

# 204 "data/scripts/berry_tree.pory"
BerryTree_Text_WantToPlant:
# 205 "data/scripts/berry_tree.pory"
	.string "It's soft, loamy soil.\n"
# 206 "data/scripts/berry_tree.pory"
	.string "Want to plant a Berry?$"
# 207 "data/scripts/berry_tree.pory"

# 208 "data/scripts/berry_tree.pory"
BerryTree_Text_PlantedOneBerry:
# 209 "data/scripts/berry_tree.pory"
	.string "{PLAYER} planted one {STR_VAR_1} in\n"
# 210 "data/scripts/berry_tree.pory"
	.string "the soft, loamy soil.$"
# 211 "data/scripts/berry_tree.pory"

# 212 "data/scripts/berry_tree.pory"
BerryTree_Text_BerryGrowthStage1:
# 213 "data/scripts/berry_tree.pory"
	.string "One {STR_VAR_1} was planted here.$"
# 214 "data/scripts/berry_tree.pory"

# 215 "data/scripts/berry_tree.pory"
BerryTree_Text_BerryGrowthStage2:
# 216 "data/scripts/berry_tree.pory"
	.string "{STR_VAR_1} has sprouted.$"
# 217 "data/scripts/berry_tree.pory"

# 218 "data/scripts/berry_tree.pory"
BerryTree_Text_BerryGrowthStage3:
# 219 "data/scripts/berry_tree.pory"
	.string "This {STR_VAR_1} plant is growing taller.$"
# 220 "data/scripts/berry_tree.pory"

# 221 "data/scripts/berry_tree.pory"
BerryTree_Text_BerryGrowthStage4:
# 222 "data/scripts/berry_tree.pory"
	.string "These {STR_VAR_1} flowers are blooming\n"
# 223 "data/scripts/berry_tree.pory"
	.string "{STR_VAR_2}.$"
# 224 "data/scripts/berry_tree.pory"

# 225 "data/scripts/berry_tree.pory"
BerryTree_Text_CareAdverbGreat:
# 226 "data/scripts/berry_tree.pory"
	.string "very beautifully$"
# 227 "data/scripts/berry_tree.pory"

# 228 "data/scripts/berry_tree.pory"
BerryTree_Text_CareAdverbPoor:
# 229 "data/scripts/berry_tree.pory"
	.string "cutely$"
# 230 "data/scripts/berry_tree.pory"

# 231 "data/scripts/berry_tree.pory"
BerryTree_Text_CareAdverbGood:
# 232 "data/scripts/berry_tree.pory"
	.string "prettily$"
# 233 "data/scripts/berry_tree.pory"

# 234 "data/scripts/berry_tree.pory"
BerryTree_Text_WantToPick:
# 235 "data/scripts/berry_tree.pory"
	.string "You found {STR_VAR_2} {STR_VAR_1}!\p"
# 236 "data/scripts/berry_tree.pory"
	.string "Do you want to pick the\n"
# 237 "data/scripts/berry_tree.pory"
	.string "{STR_VAR_1}?$"
# 238 "data/scripts/berry_tree.pory"

# 239 "data/scripts/berry_tree.pory"
BerryTree_Text_PickedTheBerry:
# 240 "data/scripts/berry_tree.pory"
	.string "{PLAYER} picked the {STR_VAR_2} {STR_VAR_1}.$"
# 241 "data/scripts/berry_tree.pory"

# 242 "data/scripts/berry_tree.pory"
BerryTree_Text_PutAwayBerry:
# 243 "data/scripts/berry_tree.pory"
	.string "{PLAYER} put away the {STR_VAR_1}\n"
# 244 "data/scripts/berry_tree.pory"
	.string "in the Bag's Berries Pocket.\p"
# 245 "data/scripts/berry_tree.pory"
	.string "The soil returned to its soft and\n"
# 246 "data/scripts/berry_tree.pory"
	.string "loamy state.$"
# 247 "data/scripts/berry_tree.pory"

# 248 "data/scripts/berry_tree.pory"
BerryTree_Text_BerryPocketFull:
# 249 "data/scripts/berry_tree.pory"
	.string "The Bag's Berries Pocket is full.\p"
# 250 "data/scripts/berry_tree.pory"
	.string "The {STR_VAR_1} couldn't be taken.$"
# 251 "data/scripts/berry_tree.pory"

# 252 "data/scripts/berry_tree.pory"
BerryTree_Text_BerryLeftUnpicked:
# 253 "data/scripts/berry_tree.pory"
	.string "{PLAYER} left the {STR_VAR_1}\n"
# 254 "data/scripts/berry_tree.pory"
	.string "unpicked.$"
# 255 "data/scripts/berry_tree.pory"

# 256 "data/scripts/berry_tree.pory"
BerryTree_Text_WantToWater:
# 257 "data/scripts/berry_tree.pory"
	.string "Want to water the {STR_VAR_1} with the\n"
# 258 "data/scripts/berry_tree.pory"
	.string "Wailmer Pail?$"
# 259 "data/scripts/berry_tree.pory"

# 260 "data/scripts/berry_tree.pory"
BerryTree_Text_WateredTheBerry:
# 261 "data/scripts/berry_tree.pory"
	.string "{PLAYER} watered the {STR_VAR_1}.$"
# 262 "data/scripts/berry_tree.pory"

# 263 "data/scripts/berry_tree.pory"
BerryTree_Text_PlantIsDelighted:
# 264 "data/scripts/berry_tree.pory"
	.string "The plant seems to be delighted.$"
# 265 "data/scripts/berry_tree.pory"

# 266 "data/scripts/berry_tree.pory"
BerryTree_Text_ExclamationPoint:
# 267 "data/scripts/berry_tree.pory"
	.string "!$"
