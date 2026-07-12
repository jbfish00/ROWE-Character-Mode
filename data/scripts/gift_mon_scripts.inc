Common_EventScript_Grass_Starter_Man::
# 3 "data/scripts/gift_mon_scripts.pory"
	lock
# 4 "data/scripts/gift_mon_scripts.pory"
	faceplayer
# 5 "data/scripts/gift_mon_scripts.pory"
	checkitem ITEM_GREEN_SHARD, 2
# 6 "data/scripts/gift_mon_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_Grass_Starter_Man_2
# 129 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Grass_Starter_Man_Text_5, MSGBOX_DEFAULT
Common_EventScript_Grass_Starter_Man_1:
# 131 "data/scripts/gift_mon_scripts.pory"
	release
	end

Common_EventScript_Grass_Starter_Man_2:
# 7 "data/scripts/gift_mon_scripts.pory"
	playse SE_PIN
# 8 "data/scripts/gift_mon_scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 9 "data/scripts/gift_mon_scripts.pory"
	waitmovement 0
# 10 "data/scripts/gift_mon_scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
# 11 "data/scripts/gift_mon_scripts.pory"
	waitmovement 0
# 12 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Grass_Starter_Man_Text_0, MSGBOX_YESNO
# 13 "data/scripts/gift_mon_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_Grass_Starter_Man_5
# 125 "data/scripts/gift_mon_scripts.pory"
	goto Common_EventScript_Starter_Man_No_Trade
	goto Common_EventScript_Grass_Starter_Man_1

Common_EventScript_Grass_Starter_Man_5:
# 14 "data/scripts/gift_mon_scripts.pory"
	compare VAR_LAST_AVAILABLE_GEN, 1
	goto_if_ne Common_EventScript_Grass_Starter_Man_9
# 19 "data/scripts/gift_mon_scripts.pory"
	setvar VAR_RESULT, GEN_1
Common_EventScript_Grass_Starter_Man_8:
# 22 "data/scripts/gift_mon_scripts.pory"
	switch VAR_RESULT
# 23 "data/scripts/gift_mon_scripts.pory"
	case GEN_1, Common_EventScript_Grass_Starter_Man_14
# 33 "data/scripts/gift_mon_scripts.pory"
	case GEN_2, Common_EventScript_Grass_Starter_Man_15
# 43 "data/scripts/gift_mon_scripts.pory"
	case GEN_3, Common_EventScript_Grass_Starter_Man_16
# 53 "data/scripts/gift_mon_scripts.pory"
	case GEN_4, Common_EventScript_Grass_Starter_Man_17
# 63 "data/scripts/gift_mon_scripts.pory"
	case GEN_5, Common_EventScript_Grass_Starter_Man_18
# 73 "data/scripts/gift_mon_scripts.pory"
	case GEN_6, Common_EventScript_Grass_Starter_Man_19
# 83 "data/scripts/gift_mon_scripts.pory"
	case GEN_7, Common_EventScript_Grass_Starter_Man_20
# 93 "data/scripts/gift_mon_scripts.pory"
	case GEN_8, Common_EventScript_Grass_Starter_Man_21
# 103 "data/scripts/gift_mon_scripts.pory"
	case GEN_9, Common_EventScript_Grass_Starter_Man_22
# 114 "data/scripts/gift_mon_scripts.pory"
	goto Common_EventScript_Starter_Man_No_Trade
Common_EventScript_Grass_Starter_Man_12:
# 117 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Grass_Starter_Man_Text_2, MSGBOX_DEFAULT
# 118 "data/scripts/gift_mon_scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 119 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Grass_Starter_Man_Text_3, MSGBOX_DEFAULT
# 120 "data/scripts/gift_mon_scripts.pory"
	waitfanfare
# 121 "data/scripts/gift_mon_scripts.pory"
	removeitem ITEM_GREEN_SHARD, 2
# 122 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Grass_Starter_Man_Text_4, MSGBOX_DEFAULT
	goto Common_EventScript_Grass_Starter_Man_1

Common_EventScript_Grass_Starter_Man_9:
# 15 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Grass_Starter_Man_Text_1, MSGBOX_DEFAULT
# 16 "data/scripts/gift_mon_scripts.pory"
	scrollingmultichoice SCROLLING_STARTER_REGION, 0, 0, 6, TRUE
	goto Common_EventScript_Grass_Starter_Man_8

Common_EventScript_Grass_Starter_Man_14:
# 24 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_BULBASAUR
# 25 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_VENUSAUR_MEGA_STONE, Common_EventScript_Grass_Starter_Man_25
# 30 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_BULBASAUR, 1, ITEM_NONE
Common_EventScript_Grass_Starter_Man_24:
	goto Common_EventScript_Grass_Starter_Man_12

Common_EventScript_Grass_Starter_Man_15:
# 34 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_CHIKORITA
# 35 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_MEGANIUM_MEGA_STONE, Common_EventScript_Grass_Starter_Man_29
# 40 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_CHIKORITA, 1, ITEM_NONE
Common_EventScript_Grass_Starter_Man_28:
	goto Common_EventScript_Grass_Starter_Man_12

Common_EventScript_Grass_Starter_Man_16:
# 44 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_TREECKO
# 45 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_SCEPTILE_MEGA_STONE, Common_EventScript_Grass_Starter_Man_33
# 50 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_TREECKO, 1, ITEM_NONE
Common_EventScript_Grass_Starter_Man_32:
	goto Common_EventScript_Grass_Starter_Man_12

Common_EventScript_Grass_Starter_Man_17:
# 54 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_TURTWIG
# 55 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_GRASS_STARTER_DELTA_ORB, Common_EventScript_Grass_Starter_Man_37
# 60 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_TURTWIG, 1, ITEM_NONE
Common_EventScript_Grass_Starter_Man_36:
	goto Common_EventScript_Grass_Starter_Man_12

Common_EventScript_Grass_Starter_Man_18:
# 64 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_SNIVY
# 65 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_SERPERIOR_MEGA_STONE, Common_EventScript_Grass_Starter_Man_41
# 70 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_SNIVY, 1, ITEM_NONE
Common_EventScript_Grass_Starter_Man_40:
	goto Common_EventScript_Grass_Starter_Man_12

Common_EventScript_Grass_Starter_Man_19:
# 74 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_CHESPIN
# 75 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_DELPHOX_MEGA_STONE, Common_EventScript_Grass_Starter_Man_45
# 80 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_CHESPIN, 1, ITEM_NONE
Common_EventScript_Grass_Starter_Man_44:
	goto Common_EventScript_Grass_Starter_Man_12

Common_EventScript_Grass_Starter_Man_20:
# 84 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_ROWLET
# 85 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_GRASS_STARTER_DELTA_ORB, Common_EventScript_Grass_Starter_Man_49
# 90 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_ROWLET, 1, ITEM_NONE
Common_EventScript_Grass_Starter_Man_48:
	goto Common_EventScript_Grass_Starter_Man_12

Common_EventScript_Grass_Starter_Man_21:
# 94 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_GROOKEY
# 95 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_RILLABOOM_MEGA_STONE, Common_EventScript_Grass_Starter_Man_53
# 100 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_GROOKEY, 1, ITEM_NONE
Common_EventScript_Grass_Starter_Man_52:
	goto Common_EventScript_Grass_Starter_Man_12

Common_EventScript_Grass_Starter_Man_22:
# 104 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_SPRIGATITO
# 105 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_GRASS_STARTER_DELTA_ORB, Common_EventScript_Grass_Starter_Man_57
# 110 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_SPRIGATITO, 1, ITEM_NONE
Common_EventScript_Grass_Starter_Man_56:
	goto Common_EventScript_Grass_Starter_Man_12

Common_EventScript_Grass_Starter_Man_25:
# 26 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_BULBASAUR, 1, ITEM_VENUSAURITE
# 27 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_VENUSAUR_MEGA_STONE
	goto Common_EventScript_Grass_Starter_Man_24

Common_EventScript_Grass_Starter_Man_29:
# 36 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_CHIKORITA, 1, ITEM_MEGANIUMITE
# 37 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_MEGANIUM_MEGA_STONE
	goto Common_EventScript_Grass_Starter_Man_28

Common_EventScript_Grass_Starter_Man_33:
# 46 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_TREECKO, 1, ITEM_SCEPTILITE
# 47 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_SCEPTILE_MEGA_STONE
	goto Common_EventScript_Grass_Starter_Man_32

Common_EventScript_Grass_Starter_Man_37:
# 56 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_TURTWIG, 1, ITEM_BOOSTER_STONE
# 57 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_GRASS_STARTER_DELTA_ORB
	goto Common_EventScript_Grass_Starter_Man_36

Common_EventScript_Grass_Starter_Man_41:
# 66 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_SNIVY, 1, ITEM_SERPERIORITE
# 67 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_SERPERIOR_MEGA_STONE
	goto Common_EventScript_Grass_Starter_Man_40

Common_EventScript_Grass_Starter_Man_45:
# 76 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_CHESPIN, 1, ITEM_CHESNAUGHTITE
# 77 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_CHESNAUGHT_MEGA_STONE
	goto Common_EventScript_Grass_Starter_Man_44

Common_EventScript_Grass_Starter_Man_49:
# 86 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_ROWLET, 1, ITEM_BOOSTER_STONE
# 87 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_GRASS_STARTER_DELTA_ORB
	goto Common_EventScript_Grass_Starter_Man_48

Common_EventScript_Grass_Starter_Man_53:
# 96 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_GROOKEY, 1, ITEM_RILABOOMITE
# 97 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_RILLABOOM_MEGA_STONE
	goto Common_EventScript_Grass_Starter_Man_52

Common_EventScript_Grass_Starter_Man_57:
# 106 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_SPRIGATITO, 1, ITEM_BOOSTER_STONE
# 107 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_GRASS_STARTER_DELTA_ORB
	goto Common_EventScript_Grass_Starter_Man_56


Common_EventScript_Fire_Starter_Man::
# 136 "data/scripts/gift_mon_scripts.pory"
	lock
# 137 "data/scripts/gift_mon_scripts.pory"
	faceplayer
# 138 "data/scripts/gift_mon_scripts.pory"
	checkitem ITEM_RED_SHARD, 2
# 139 "data/scripts/gift_mon_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_Fire_Starter_Man_2
# 262 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Fire_Starter_Man_Text_1, MSGBOX_DEFAULT
Common_EventScript_Fire_Starter_Man_1:
# 264 "data/scripts/gift_mon_scripts.pory"
	release
	end

Common_EventScript_Fire_Starter_Man_2:
# 140 "data/scripts/gift_mon_scripts.pory"
	playse SE_PIN
# 141 "data/scripts/gift_mon_scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 142 "data/scripts/gift_mon_scripts.pory"
	waitmovement 0
# 143 "data/scripts/gift_mon_scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
# 144 "data/scripts/gift_mon_scripts.pory"
	waitmovement 0
# 145 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Fire_Starter_Man_Text_0, MSGBOX_YESNO
# 146 "data/scripts/gift_mon_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_Fire_Starter_Man_5
# 258 "data/scripts/gift_mon_scripts.pory"
	goto Common_EventScript_Starter_Man_No_Trade
	goto Common_EventScript_Fire_Starter_Man_1

Common_EventScript_Fire_Starter_Man_5:
# 147 "data/scripts/gift_mon_scripts.pory"
	compare VAR_LAST_AVAILABLE_GEN, 1
	goto_if_ne Common_EventScript_Fire_Starter_Man_9
# 152 "data/scripts/gift_mon_scripts.pory"
	setvar VAR_RESULT, GEN_1
Common_EventScript_Fire_Starter_Man_8:
# 155 "data/scripts/gift_mon_scripts.pory"
	switch VAR_RESULT
# 156 "data/scripts/gift_mon_scripts.pory"
	case GEN_1, Common_EventScript_Fire_Starter_Man_14
# 166 "data/scripts/gift_mon_scripts.pory"
	case GEN_2, Common_EventScript_Fire_Starter_Man_15
# 176 "data/scripts/gift_mon_scripts.pory"
	case GEN_3, Common_EventScript_Fire_Starter_Man_16
# 186 "data/scripts/gift_mon_scripts.pory"
	case GEN_4, Common_EventScript_Fire_Starter_Man_17
# 196 "data/scripts/gift_mon_scripts.pory"
	case GEN_5, Common_EventScript_Fire_Starter_Man_18
# 206 "data/scripts/gift_mon_scripts.pory"
	case GEN_6, Common_EventScript_Fire_Starter_Man_19
# 216 "data/scripts/gift_mon_scripts.pory"
	case GEN_7, Common_EventScript_Fire_Starter_Man_20
# 226 "data/scripts/gift_mon_scripts.pory"
	case GEN_8, Common_EventScript_Fire_Starter_Man_21
# 236 "data/scripts/gift_mon_scripts.pory"
	case GEN_9, Common_EventScript_Fire_Starter_Man_22
# 247 "data/scripts/gift_mon_scripts.pory"
	goto Common_EventScript_Starter_Man_No_Trade
Common_EventScript_Fire_Starter_Man_12:
# 250 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Grass_Starter_Man_Text_2, MSGBOX_DEFAULT
# 251 "data/scripts/gift_mon_scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 252 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Grass_Starter_Man_Text_3, MSGBOX_DEFAULT
# 253 "data/scripts/gift_mon_scripts.pory"
	waitfanfare
# 254 "data/scripts/gift_mon_scripts.pory"
	removeitem ITEM_RED_SHARD, 2
# 255 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Grass_Starter_Man_Text_4, MSGBOX_DEFAULT
	goto Common_EventScript_Fire_Starter_Man_1

Common_EventScript_Fire_Starter_Man_9:
# 148 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Grass_Starter_Man_Text_1, MSGBOX_DEFAULT
# 149 "data/scripts/gift_mon_scripts.pory"
	scrollingmultichoice SCROLLING_STARTER_REGION, 0, 0, 6, TRUE
	goto Common_EventScript_Fire_Starter_Man_8

Common_EventScript_Fire_Starter_Man_14:
# 157 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_CHARMANDER
# 158 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_CHARIZARD_Y_MEGA_STONE, Common_EventScript_Fire_Starter_Man_25
# 163 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_CHARMANDER, 1, ITEM_NONE
Common_EventScript_Fire_Starter_Man_24:
	goto Common_EventScript_Fire_Starter_Man_12

Common_EventScript_Fire_Starter_Man_15:
# 167 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_CYNDAQUIL
# 168 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_TYPHLOSION_MEGA_STONE, Common_EventScript_Fire_Starter_Man_29
# 173 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_CYNDAQUIL, 1, ITEM_NONE
Common_EventScript_Fire_Starter_Man_28:
	goto Common_EventScript_Fire_Starter_Man_12

Common_EventScript_Fire_Starter_Man_16:
# 177 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_TORCHIC
# 178 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_BLAZIKEN_MEGA_STONE, Common_EventScript_Fire_Starter_Man_33
# 183 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_TORCHIC, 1, ITEM_NONE
Common_EventScript_Fire_Starter_Man_32:
	goto Common_EventScript_Fire_Starter_Man_12

Common_EventScript_Fire_Starter_Man_17:
# 187 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_CHIMCHAR
# 188 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_FIRE_STARTER_DELTA_ORB, Common_EventScript_Fire_Starter_Man_37
# 193 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_CHIMCHAR, 1, ITEM_NONE
Common_EventScript_Fire_Starter_Man_36:
	goto Common_EventScript_Fire_Starter_Man_12

Common_EventScript_Fire_Starter_Man_18:
# 197 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_TEPIG
# 198 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_EMBOAR_MEGA_STONE, Common_EventScript_Fire_Starter_Man_41
# 203 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_TEPIG, 1, ITEM_NONE
Common_EventScript_Fire_Starter_Man_40:
	goto Common_EventScript_Fire_Starter_Man_12

Common_EventScript_Fire_Starter_Man_19:
# 207 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_FENNEKIN
# 208 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_DELPHOX_MEGA_STONE, Common_EventScript_Fire_Starter_Man_45
# 213 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_FENNEKIN, 1, ITEM_NONE
Common_EventScript_Fire_Starter_Man_44:
	goto Common_EventScript_Fire_Starter_Man_12

Common_EventScript_Fire_Starter_Man_20:
# 217 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_LITTEN
# 218 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_FIRE_STARTER_DELTA_ORB, Common_EventScript_Fire_Starter_Man_49
# 223 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_LITTEN, 1, ITEM_NONE
Common_EventScript_Fire_Starter_Man_48:
	goto Common_EventScript_Fire_Starter_Man_12

Common_EventScript_Fire_Starter_Man_21:
# 227 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_SCORBUNNY
# 228 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_CINDERACE_MEGA_STONE, Common_EventScript_Fire_Starter_Man_53
# 233 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_SCORBUNNY, 1, ITEM_NONE
Common_EventScript_Fire_Starter_Man_52:
	goto Common_EventScript_Fire_Starter_Man_12

Common_EventScript_Fire_Starter_Man_22:
# 237 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_FUECOCO
# 238 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_FIRE_STARTER_DELTA_ORB, Common_EventScript_Fire_Starter_Man_57
# 243 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_FUECOCO, 1, ITEM_NONE
Common_EventScript_Fire_Starter_Man_56:
	goto Common_EventScript_Fire_Starter_Man_12

Common_EventScript_Fire_Starter_Man_25:
# 159 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_CHARMANDER, 1, ITEM_CHARIZARDITE_Y
# 160 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_CHARIZARD_Y_MEGA_STONE
	goto Common_EventScript_Fire_Starter_Man_24

Common_EventScript_Fire_Starter_Man_29:
# 169 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_CYNDAQUIL, 1, ITEM_TYPHLOSIONITE
# 170 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_TYPHLOSION_MEGA_STONE
	goto Common_EventScript_Fire_Starter_Man_28

Common_EventScript_Fire_Starter_Man_33:
# 179 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_TORCHIC, 1, ITEM_BLAZIKENITE
# 180 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_BLAZIKEN_MEGA_STONE
	goto Common_EventScript_Fire_Starter_Man_32

Common_EventScript_Fire_Starter_Man_37:
# 189 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_CHIMCHAR, 1, ITEM_BOOSTER_STONE
# 190 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_FIRE_STARTER_DELTA_ORB
	goto Common_EventScript_Fire_Starter_Man_36

Common_EventScript_Fire_Starter_Man_41:
# 199 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_TEPIG, 1, ITEM_EMBOARITE
# 200 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_EMBOAR_MEGA_STONE
	goto Common_EventScript_Fire_Starter_Man_40

Common_EventScript_Fire_Starter_Man_45:
# 209 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_FENNEKIN, 1, ITEM_DELPHOXITE
# 210 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_DELPHOX_MEGA_STONE
	goto Common_EventScript_Fire_Starter_Man_44

Common_EventScript_Fire_Starter_Man_49:
# 219 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_LITTEN, 1, ITEM_BOOSTER_STONE
# 220 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_FIRE_STARTER_DELTA_ORB
	goto Common_EventScript_Fire_Starter_Man_48

Common_EventScript_Fire_Starter_Man_53:
# 229 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_SCORBUNNY, 1, ITEM_CINDERACITE
# 230 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_CINDERACE_MEGA_STONE
	goto Common_EventScript_Fire_Starter_Man_52

Common_EventScript_Fire_Starter_Man_57:
# 239 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_FUECOCO, 1, ITEM_BOOSTER_STONE
# 240 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_FIRE_STARTER_DELTA_ORB
	goto Common_EventScript_Fire_Starter_Man_56


Common_EventScript_Water_Starter_Man::
# 269 "data/scripts/gift_mon_scripts.pory"
	lock
# 270 "data/scripts/gift_mon_scripts.pory"
	faceplayer
# 271 "data/scripts/gift_mon_scripts.pory"
	checkitem ITEM_BLUE_SHARD, 2
# 272 "data/scripts/gift_mon_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_Water_Starter_Man_2
# 395 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Water_Starter_Man_Text_1, MSGBOX_DEFAULT
Common_EventScript_Water_Starter_Man_1:
# 397 "data/scripts/gift_mon_scripts.pory"
	release
	end

Common_EventScript_Water_Starter_Man_2:
# 273 "data/scripts/gift_mon_scripts.pory"
	playse SE_PIN
# 274 "data/scripts/gift_mon_scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 275 "data/scripts/gift_mon_scripts.pory"
	waitmovement 0
# 276 "data/scripts/gift_mon_scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
# 277 "data/scripts/gift_mon_scripts.pory"
	waitmovement 0
# 278 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Water_Starter_Man_Text_0, MSGBOX_YESNO
# 279 "data/scripts/gift_mon_scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Common_EventScript_Water_Starter_Man_5
# 391 "data/scripts/gift_mon_scripts.pory"
	goto Common_EventScript_Starter_Man_No_Trade
	goto Common_EventScript_Water_Starter_Man_1

Common_EventScript_Water_Starter_Man_5:
# 280 "data/scripts/gift_mon_scripts.pory"
	compare VAR_LAST_AVAILABLE_GEN, 1
	goto_if_ne Common_EventScript_Water_Starter_Man_9
# 285 "data/scripts/gift_mon_scripts.pory"
	setvar VAR_RESULT, GEN_1
Common_EventScript_Water_Starter_Man_8:
# 288 "data/scripts/gift_mon_scripts.pory"
	switch VAR_RESULT
# 289 "data/scripts/gift_mon_scripts.pory"
	case GEN_1, Common_EventScript_Water_Starter_Man_14
# 299 "data/scripts/gift_mon_scripts.pory"
	case GEN_2, Common_EventScript_Water_Starter_Man_15
# 309 "data/scripts/gift_mon_scripts.pory"
	case GEN_3, Common_EventScript_Water_Starter_Man_16
# 319 "data/scripts/gift_mon_scripts.pory"
	case GEN_4, Common_EventScript_Water_Starter_Man_17
# 329 "data/scripts/gift_mon_scripts.pory"
	case GEN_5, Common_EventScript_Water_Starter_Man_18
# 339 "data/scripts/gift_mon_scripts.pory"
	case GEN_6, Common_EventScript_Water_Starter_Man_19
# 349 "data/scripts/gift_mon_scripts.pory"
	case GEN_7, Common_EventScript_Water_Starter_Man_20
# 359 "data/scripts/gift_mon_scripts.pory"
	case GEN_8, Common_EventScript_Water_Starter_Man_21
# 369 "data/scripts/gift_mon_scripts.pory"
	case GEN_9, Common_EventScript_Water_Starter_Man_22
# 380 "data/scripts/gift_mon_scripts.pory"
	goto Common_EventScript_Starter_Man_No_Trade
Common_EventScript_Water_Starter_Man_12:
# 383 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Grass_Starter_Man_Text_2, MSGBOX_DEFAULT
# 384 "data/scripts/gift_mon_scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 385 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Grass_Starter_Man_Text_3, MSGBOX_DEFAULT
# 386 "data/scripts/gift_mon_scripts.pory"
	waitfanfare
# 387 "data/scripts/gift_mon_scripts.pory"
	removeitem ITEM_BLUE_SHARD, 2
# 388 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Grass_Starter_Man_Text_4, MSGBOX_DEFAULT
	goto Common_EventScript_Water_Starter_Man_1

Common_EventScript_Water_Starter_Man_9:
# 281 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Grass_Starter_Man_Text_1, MSGBOX_DEFAULT
# 282 "data/scripts/gift_mon_scripts.pory"
	scrollingmultichoice SCROLLING_STARTER_REGION, 0, 0, 6, TRUE
	goto Common_EventScript_Water_Starter_Man_8

Common_EventScript_Water_Starter_Man_14:
# 290 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_SQUIRTLE
# 291 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_BLASTOISE_MEGA_STONE, Common_EventScript_Water_Starter_Man_25
# 296 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_SQUIRTLE, 1, ITEM_NONE
Common_EventScript_Water_Starter_Man_24:
	goto Common_EventScript_Water_Starter_Man_12

Common_EventScript_Water_Starter_Man_15:
# 300 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_TOTODILE
# 301 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_FERALIGATR_MEGA_STONE, Common_EventScript_Water_Starter_Man_29
# 306 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_TOTODILE, 1, ITEM_NONE
Common_EventScript_Water_Starter_Man_28:
	goto Common_EventScript_Water_Starter_Man_12

Common_EventScript_Water_Starter_Man_16:
# 310 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_MUDKIP
# 311 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_SWAMPERT_MEGA_STONE, Common_EventScript_Water_Starter_Man_33
# 316 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_MUDKIP, 1, ITEM_NONE
Common_EventScript_Water_Starter_Man_32:
	goto Common_EventScript_Water_Starter_Man_12

Common_EventScript_Water_Starter_Man_17:
# 320 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_PIPLUP
# 321 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_WATER_STARTER_DELTA_ORB, Common_EventScript_Water_Starter_Man_37
# 326 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_PIPLUP, 1, ITEM_NONE
Common_EventScript_Water_Starter_Man_36:
	goto Common_EventScript_Water_Starter_Man_12

Common_EventScript_Water_Starter_Man_18:
# 330 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_OSHAWOTT
# 331 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_SAMUROTT_MEGA_STONE, Common_EventScript_Water_Starter_Man_41
# 336 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_OSHAWOTT, 1, ITEM_NONE
Common_EventScript_Water_Starter_Man_40:
	goto Common_EventScript_Water_Starter_Man_12

Common_EventScript_Water_Starter_Man_19:
# 340 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_FROAKIE
# 341 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_GRENINJA_MEGA_STONE, Common_EventScript_Water_Starter_Man_45
# 346 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_FROAKIE, 1, ITEM_NONE
Common_EventScript_Water_Starter_Man_44:
	goto Common_EventScript_Water_Starter_Man_12

Common_EventScript_Water_Starter_Man_20:
# 350 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_POPPLIO
# 351 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_WATER_STARTER_DELTA_ORB, Common_EventScript_Water_Starter_Man_49
# 356 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_POPPLIO, 1, ITEM_NONE
Common_EventScript_Water_Starter_Man_48:
	goto Common_EventScript_Water_Starter_Man_12

Common_EventScript_Water_Starter_Man_21:
# 360 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_SOBBLE
# 361 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_INTELEON_MEGA_STONE, Common_EventScript_Water_Starter_Man_53
# 366 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_SOBBLE, 1, ITEM_NONE
Common_EventScript_Water_Starter_Man_52:
	goto Common_EventScript_Water_Starter_Man_12

Common_EventScript_Water_Starter_Man_22:
# 370 "data/scripts/gift_mon_scripts.pory"
	bufferspeciesname 1, SPECIES_QUAXLY
# 371 "data/scripts/gift_mon_scripts.pory"
	goto_if_unset FLAG_GOT_WATER_STARTER_DELTA_ORB, Common_EventScript_Water_Starter_Man_57
# 376 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_QUAXLY, 1, ITEM_NONE
Common_EventScript_Water_Starter_Man_56:
	goto Common_EventScript_Water_Starter_Man_12

Common_EventScript_Water_Starter_Man_25:
# 292 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_SQUIRTLE, 1, ITEM_BLASTOISINITE
# 293 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_BLASTOISE_MEGA_STONE
	goto Common_EventScript_Water_Starter_Man_24

Common_EventScript_Water_Starter_Man_29:
# 302 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_TOTODILE, 1, ITEM_FERALIGITE
# 303 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_FERALIGATR_MEGA_STONE
	goto Common_EventScript_Water_Starter_Man_28

Common_EventScript_Water_Starter_Man_33:
# 312 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_MUDKIP, 1, ITEM_SWAMPERTITE
# 313 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_SWAMPERT_MEGA_STONE
	goto Common_EventScript_Water_Starter_Man_32

Common_EventScript_Water_Starter_Man_37:
# 322 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_PIPLUP, 1, ITEM_BOOSTER_STONE
# 323 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_WATER_STARTER_DELTA_ORB
	goto Common_EventScript_Water_Starter_Man_36

Common_EventScript_Water_Starter_Man_41:
# 332 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_OSHAWOTT, 1, ITEM_SAMUROTTITE
# 333 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_SAMUROTT_MEGA_STONE
	goto Common_EventScript_Water_Starter_Man_40

Common_EventScript_Water_Starter_Man_45:
# 342 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_FROAKIE, 1, ITEM_GRENINJITE
# 343 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_GRENINJA_MEGA_STONE
	goto Common_EventScript_Water_Starter_Man_44

Common_EventScript_Water_Starter_Man_49:
# 352 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_POPPLIO, 1, ITEM_BOOSTER_STONE
# 353 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_WATER_STARTER_DELTA_ORB
	goto Common_EventScript_Water_Starter_Man_48

Common_EventScript_Water_Starter_Man_53:
# 362 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_SOBBLE, 1, ITEM_INTELEONITE
# 363 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_INTELEON_MEGA_STONE
	goto Common_EventScript_Water_Starter_Man_52

Common_EventScript_Water_Starter_Man_57:
# 372 "data/scripts/gift_mon_scripts.pory"
	givemon SPECIES_QUAXLY, 1, ITEM_BOOSTER_STONE
# 373 "data/scripts/gift_mon_scripts.pory"
	setflag FLAG_GOT_WATER_STARTER_DELTA_ORB
	goto Common_EventScript_Water_Starter_Man_56


Common_EventScript_Starter_Man_No_Trade::
# 402 "data/scripts/gift_mon_scripts.pory"
	msgbox Common_EventScript_Starter_Man_No_Trade_Text_0, MSGBOX_DEFAULT
# 403 "data/scripts/gift_mon_scripts.pory"
	release
	end


Common_EventScript_Grass_Starter_Man_Text_0:
# 12 "data/scripts/gift_mon_scripts.pory"
	.string "Are those Green Shards?\p"
	.string "Do you want to trade them\n"
	.string "for one of my Pokémon?$"

Common_EventScript_Grass_Starter_Man_Text_1:
# 15 "data/scripts/gift_mon_scripts.pory"
	.string "What region do you like the most?$"

Common_EventScript_Grass_Starter_Man_Text_2:
# 117 "data/scripts/gift_mon_scripts.pory"
	.string "Here you go!$"

Common_EventScript_Grass_Starter_Man_Text_3:
# 119 "data/scripts/gift_mon_scripts.pory"
	.string "{PLAYER} received {STR_VAR_2} from\n"
	.string "the Poke Fan.$"

Common_EventScript_Grass_Starter_Man_Text_4:
# 122 "data/scripts/gift_mon_scripts.pory"
	.string "Please come again when you have spare\n"
	.string "shards!$"

Common_EventScript_Grass_Starter_Man_Text_5:
# 129 "data/scripts/gift_mon_scripts.pory"
	.string "If you have 2 Green Shards I can give\n"
	.string "you a good Pokémon.$"

Common_EventScript_Fire_Starter_Man_Text_0:
# 145 "data/scripts/gift_mon_scripts.pory"
	.string "Are those Red Shards?\p"
	.string "Do you want to trade them\n"
	.string "for one of my Pokémon?$"

Common_EventScript_Fire_Starter_Man_Text_1:
# 262 "data/scripts/gift_mon_scripts.pory"
	.string "If you have 2 Red Shards I can give you\n"
	.string "a good Pokémon.$"

Common_EventScript_Water_Starter_Man_Text_0:
# 278 "data/scripts/gift_mon_scripts.pory"
	.string "Are those Blue Shards?\p"
	.string "Do you want to trade them\n"
	.string "for one of my Pokémon?$"

Common_EventScript_Water_Starter_Man_Text_1:
# 395 "data/scripts/gift_mon_scripts.pory"
	.string "If you have 2 Blue Shards I can give you\n"
	.string "a good Pokémon.$"

Common_EventScript_Starter_Man_No_Trade_Text_0:
# 402 "data/scripts/gift_mon_scripts.pory"
	.string "Oh well, come again if you want to trade.$"
