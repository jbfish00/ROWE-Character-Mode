# 1 "data/scripts/shared_secret_base.pory"

# 2 "data/scripts/shared_secret_base.pory"
SecretBase_MapScripts::
# 3 "data/scripts/shared_secret_base.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SecretBase_OnWarp
# 4 "data/scripts/shared_secret_base.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SecretBase_OnTransition
# 5 "data/scripts/shared_secret_base.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SecretBase_OnFrame
# 6 "data/scripts/shared_secret_base.pory"
	map_script MAP_SCRIPT_ON_RESUME, SecretBase_OnResume
# 7 "data/scripts/shared_secret_base.pory"
	.byte 0
# 8 "data/scripts/shared_secret_base.pory"

# 9 "data/scripts/shared_secret_base.pory"
SecretBase_OnWarp:
# 10 "data/scripts/shared_secret_base.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, SecretBase_EventScript_InitDecorations
# 11 "data/scripts/shared_secret_base.pory"
	.2byte 0
# 12 "data/scripts/shared_secret_base.pory"

# 13 "data/scripts/shared_secret_base.pory"
SecretBase_OnTransition:
# 14 "data/scripts/shared_secret_base.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 15 "data/scripts/shared_secret_base.pory"
	special SetSecretBaseOwnerGfxId
# 16 "data/scripts/shared_secret_base.pory"
	special InitSecretBaseVars
# 17 "data/scripts/shared_secret_base.pory"
	end
# 18 "data/scripts/shared_secret_base.pory"

# 19 "data/scripts/shared_secret_base.pory"
SecretBase_OnFrame:
# 20 "data/scripts/shared_secret_base.pory"
	map_script_2 VAR_INIT_SECRET_BASE, 0, SecretBase_EventScript_FirstEntrance
# 21 "data/scripts/shared_secret_base.pory"
	.2byte 0
# 22 "data/scripts/shared_secret_base.pory"

# 23 "data/scripts/shared_secret_base.pory"
SecretBase_OnResume:
# 24 "data/scripts/shared_secret_base.pory"
	setstepcallback STEP_CB_SECRET_BASE
# 25 "data/scripts/shared_secret_base.pory"
	end
# 26 "data/scripts/shared_secret_base.pory"

# 27 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_PC::
# 28 "data/scripts/shared_secret_base.pory"
	lockall
# 29 "data/scripts/shared_secret_base.pory"
	playse SE_PC_LOGIN
# 30 "data/scripts/shared_secret_base.pory"
	message SecretBase_Text_BootUpPC
# 31 "data/scripts/shared_secret_base.pory"
	dofieldeffect FLDEFF_PCTURN_ON
# 32 "data/scripts/shared_secret_base.pory"
	waitstate
# 33 "data/scripts/shared_secret_base.pory"
	waitmessage
# 34 "data/scripts/shared_secret_base.pory"
	waitbuttonpress
# 35 "data/scripts/shared_secret_base.pory"
	playse SE_SELECT
# 36 "data/scripts/shared_secret_base.pory"
	goto SecretBase_EventScript_PCShowMainMenu
# 37 "data/scripts/shared_secret_base.pory"
	end
# 38 "data/scripts/shared_secret_base.pory"

# 39 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_PCShowMainMenu::
# 40 "data/scripts/shared_secret_base.pory"
	message SecretBase_Text_WhatWouldYouLikeToDo
# 41 "data/scripts/shared_secret_base.pory"
	waitmessage
# 42 "data/scripts/shared_secret_base.pory"
	goto_if_set FLAG_SECRET_BASE_REGISTRY_ENABLED, SecretBase_EventScript_PCMainMenuWithRegister
# 43 "data/scripts/shared_secret_base.pory"
	goto SecretBase_EventScript_PCMainMenuWithoutRegister
# 44 "data/scripts/shared_secret_base.pory"
	end
# 45 "data/scripts/shared_secret_base.pory"

# 46 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_PCCancel::
# 47 "data/scripts/shared_secret_base.pory"
	lockall
# 48 "data/scripts/shared_secret_base.pory"
	goto SecretBase_EventScript_PCShowMainMenu
# 49 "data/scripts/shared_secret_base.pory"
	end
# 50 "data/scripts/shared_secret_base.pory"

# 51 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_PCMainMenuWithRegister::
# 52 "data/scripts/shared_secret_base.pory"
	multichoice 0, 0, MULTI_BASE_PC_WITH_REGISTRY, 0
# 53 "data/scripts/shared_secret_base.pory"
	switch VAR_RESULT
# 54 "data/scripts/shared_secret_base.pory"
	case 0, SecretBase_EventScript_PCDecorationMenu
# 55 "data/scripts/shared_secret_base.pory"
	case 1, SecretBase_EventScript_PCPackUp
# 56 "data/scripts/shared_secret_base.pory"
	case 2, SecretBase_EventScript_PCRegistryMenu
# 57 "data/scripts/shared_secret_base.pory"
	case 3, SecretBase_EventScript_PCTurnOff
# 58 "data/scripts/shared_secret_base.pory"
	case MULTI_B_PRESSED, SecretBase_EventScript_PCTurnOff
# 59 "data/scripts/shared_secret_base.pory"
	end
# 60 "data/scripts/shared_secret_base.pory"

# 61 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_PCMainMenuWithoutRegister::
# 62 "data/scripts/shared_secret_base.pory"
	multichoice 0, 0, MULTI_BASE_PC_NO_REGISTRY, 0
# 63 "data/scripts/shared_secret_base.pory"
	switch VAR_RESULT
# 64 "data/scripts/shared_secret_base.pory"
	case 0, SecretBase_EventScript_PCDecorationMenu
# 65 "data/scripts/shared_secret_base.pory"
	case 1, SecretBase_EventScript_PCPackUp
# 66 "data/scripts/shared_secret_base.pory"
	case 2, SecretBase_EventScript_PCTurnOff
# 67 "data/scripts/shared_secret_base.pory"
	case MULTI_B_PRESSED, SecretBase_EventScript_PCTurnOff
# 68 "data/scripts/shared_secret_base.pory"
	end
# 69 "data/scripts/shared_secret_base.pory"

# 70 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_PCPackUp::
# 71 "data/scripts/shared_secret_base.pory"
	msgbox SecretBase_Text_AllDecorationsWillBeReturned, MSGBOX_YESNO
# 72 "data/scripts/shared_secret_base.pory"
	compare VAR_RESULT, NO
# 73 "data/scripts/shared_secret_base.pory"
	goto_if_eq SecretBase_EventScript_PCShowMainMenu
# 74 "data/scripts/shared_secret_base.pory"
	closemessage
# 75 "data/scripts/shared_secret_base.pory"
	special MoveOutOfSecretBase
# 76 "data/scripts/shared_secret_base.pory"
	releaseall
# 77 "data/scripts/shared_secret_base.pory"
	end
# 78 "data/scripts/shared_secret_base.pory"

# 79 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_PCDecorationMenu::
# 80 "data/scripts/shared_secret_base.pory"
	special ShowSecretBaseDecorationMenu
# 81 "data/scripts/shared_secret_base.pory"
	end
# 82 "data/scripts/shared_secret_base.pory"

# 83 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_PCRegistryMenu::
# 84 "data/scripts/shared_secret_base.pory"
	special ShowSecretBaseRegistryMenu
# 85 "data/scripts/shared_secret_base.pory"
	end
# 86 "data/scripts/shared_secret_base.pory"

# 87 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_RecordMixingPC::
# 88 "data/scripts/shared_secret_base.pory"
	lockall
# 89 "data/scripts/shared_secret_base.pory"
	message SecretBase_Text_BootUpPC
# 90 "data/scripts/shared_secret_base.pory"
	playse SE_PC_LOGIN
# 91 "data/scripts/shared_secret_base.pory"
	dofieldeffect FLDEFF_PCTURN_ON
# 92 "data/scripts/shared_secret_base.pory"
	waitstate
# 93 "data/scripts/shared_secret_base.pory"
	waitmessage
# 94 "data/scripts/shared_secret_base.pory"
	waitbuttonpress
# 95 "data/scripts/shared_secret_base.pory"
	playse SE_SELECT
# 96 "data/scripts/shared_secret_base.pory"
	goto SecretBase_EventScript_PCRegisterMenu
# 97 "data/scripts/shared_secret_base.pory"
	end
# 98 "data/scripts/shared_secret_base.pory"

# 99 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_PCRegisterMenu::
# 100 "data/scripts/shared_secret_base.pory"
	message SecretBase_Text_WhatWouldYouLikeToDo
# 101 "data/scripts/shared_secret_base.pory"
	waitmessage
# 102 "data/scripts/shared_secret_base.pory"
	multichoice 0, 0, MULTI_REGISTER_MENU, 0
# 103 "data/scripts/shared_secret_base.pory"
	switch VAR_RESULT
# 104 "data/scripts/shared_secret_base.pory"
	case 0, SecretBase_EventScript_PCRegister
# 105 "data/scripts/shared_secret_base.pory"
	case 1, SecretBase_EventScript_PCRegistryMenu
# 106 "data/scripts/shared_secret_base.pory"
	case 2, SecretBase_EventScript_PCRegistryInfo
# 107 "data/scripts/shared_secret_base.pory"
	case 3, SecretBase_EventScript_PCTurnOff
# 108 "data/scripts/shared_secret_base.pory"
	case MULTI_B_PRESSED, SecretBase_EventScript_PCTurnOff
# 109 "data/scripts/shared_secret_base.pory"
	end
# 110 "data/scripts/shared_secret_base.pory"

# 111 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_ShowRegisterMenu::
# 112 "data/scripts/shared_secret_base.pory"
	lockall
# 113 "data/scripts/shared_secret_base.pory"
	goto SecretBase_EventScript_PCRegisterMenu
# 114 "data/scripts/shared_secret_base.pory"
	end
# 115 "data/scripts/shared_secret_base.pory"

# 116 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_PCRegister::
# 117 "data/scripts/shared_secret_base.pory"
	special GetCurSecretBaseRegistrationValidity
# 118 "data/scripts/shared_secret_base.pory"
	compare VAR_RESULT, 1
# 119 "data/scripts/shared_secret_base.pory"
	goto_if_eq SecretBase_EventScript_AlreadyRegistered
# 120 "data/scripts/shared_secret_base.pory"
	compare VAR_RESULT, 2
# 121 "data/scripts/shared_secret_base.pory"
	goto_if_eq SecretBase_EventScript_CantRegisterTooManyBases
# 122 "data/scripts/shared_secret_base.pory"
	special CopyCurSecretBaseOwnerName_StrVar1
# 123 "data/scripts/shared_secret_base.pory"
	msgbox SecretBase_Text_WantToRegisterSecretBase, MSGBOX_YESNO
# 124 "data/scripts/shared_secret_base.pory"
	compare VAR_RESULT, NO
# 125 "data/scripts/shared_secret_base.pory"
	goto_if_eq SecretBase_EventScript_PCRegisterMenu
# 126 "data/scripts/shared_secret_base.pory"
	msgbox SecretBase_Text_RegistrationCompleted, MSGBOX_SIGN
# 127 "data/scripts/shared_secret_base.pory"
	special ToggleCurSecretBaseRegistry
# 128 "data/scripts/shared_secret_base.pory"
	special DoSecretBasePCTurnOffEffect
# 129 "data/scripts/shared_secret_base.pory"
	releaseall
# 130 "data/scripts/shared_secret_base.pory"
	end
# 131 "data/scripts/shared_secret_base.pory"

# 132 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_AlreadyRegistered::
# 133 "data/scripts/shared_secret_base.pory"
	msgbox SecretBase_Text_AlreadyRegisteredDelete, MSGBOX_YESNO
# 134 "data/scripts/shared_secret_base.pory"
	compare VAR_RESULT, NO
# 135 "data/scripts/shared_secret_base.pory"
	goto_if_eq SecretBase_EventScript_PCRegisterMenu
# 136 "data/scripts/shared_secret_base.pory"
	msgbox SecretBase_Text_DataUnregistered, MSGBOX_SIGN
# 137 "data/scripts/shared_secret_base.pory"
	special ToggleCurSecretBaseRegistry
# 138 "data/scripts/shared_secret_base.pory"
	special DoSecretBasePCTurnOffEffect
# 139 "data/scripts/shared_secret_base.pory"
	releaseall
# 140 "data/scripts/shared_secret_base.pory"
	end
# 141 "data/scripts/shared_secret_base.pory"

# 142 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_CantRegisterTooManyBases::
# 143 "data/scripts/shared_secret_base.pory"
	msgbox SecretBase_Text_TooManyBasesDeleteSome, MSGBOX_SIGN
# 144 "data/scripts/shared_secret_base.pory"
	special DoSecretBasePCTurnOffEffect
# 145 "data/scripts/shared_secret_base.pory"
	closemessage
# 146 "data/scripts/shared_secret_base.pory"
	releaseall
# 147 "data/scripts/shared_secret_base.pory"
	end
# 148 "data/scripts/shared_secret_base.pory"

# 149 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_PCRegistryInfo::
# 150 "data/scripts/shared_secret_base.pory"
	msgbox SecretBase_Text_RegistryInfo, MSGBOX_DEFAULT
# 151 "data/scripts/shared_secret_base.pory"
	goto SecretBase_EventScript_PCRegisterMenu
# 152 "data/scripts/shared_secret_base.pory"
	end
# 153 "data/scripts/shared_secret_base.pory"

# 154 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_PCTurnOff::
# 155 "data/scripts/shared_secret_base.pory"
	special DoSecretBasePCTurnOffEffect
# 156 "data/scripts/shared_secret_base.pory"
	closemessage
# 157 "data/scripts/shared_secret_base.pory"
	releaseall
# 158 "data/scripts/shared_secret_base.pory"
	end
# 159 "data/scripts/shared_secret_base.pory"

# 160 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_Poster::
# 161 "data/scripts/shared_secret_base.pory"
	special CheckInteractedWithFriendsPosterDecor
# 162 "data/scripts/shared_secret_base.pory"
	end
# 163 "data/scripts/shared_secret_base.pory"

# 164 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_FurnitureBottom::
# 165 "data/scripts/shared_secret_base.pory"
	special CheckInteractedWithFriendsFurnitureBottom
# 166 "data/scripts/shared_secret_base.pory"
	end
# 167 "data/scripts/shared_secret_base.pory"

# 168 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_FurnitureMiddle::
# 169 "data/scripts/shared_secret_base.pory"
	special CheckInteractedWithFriendsFurnitureMiddle
# 170 "data/scripts/shared_secret_base.pory"
	end
# 171 "data/scripts/shared_secret_base.pory"

# 172 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_FurnitureTop::
# 173 "data/scripts/shared_secret_base.pory"
	special CheckInteractedWithFriendsFurnitureTop
# 174 "data/scripts/shared_secret_base.pory"
	end
# 175 "data/scripts/shared_secret_base.pory"

# 176 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_SandOrnament::
# 177 "data/scripts/shared_secret_base.pory"
	special CheckInteractedWithFriendsSandOrnament
# 178 "data/scripts/shared_secret_base.pory"
	dofieldeffect FLDEFF_SAND_PILLAR
# 179 "data/scripts/shared_secret_base.pory"
	waitstate
# 180 "data/scripts/shared_secret_base.pory"
	end
# 181 "data/scripts/shared_secret_base.pory"

# 182 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_ShieldOrToyTV::
# 183 "data/scripts/shared_secret_base.pory"
	special InteractWithShieldOrTVDecoration
# 184 "data/scripts/shared_secret_base.pory"
	compare VAR_RESULT, 0
# 185 "data/scripts/shared_secret_base.pory"
	goto_if_eq SecretBase_EventScript_BattleTowerShield
# 186 "data/scripts/shared_secret_base.pory"
	compare VAR_RESULT, 1
# 187 "data/scripts/shared_secret_base.pory"
	goto_if_eq SecretBase_EventScript_ToyTV
# 188 "data/scripts/shared_secret_base.pory"
	compare VAR_RESULT, 2
# 189 "data/scripts/shared_secret_base.pory"
	goto_if_eq SecretBase_EventScript_SeedotTV
# 190 "data/scripts/shared_secret_base.pory"
	compare VAR_RESULT, 3
# 191 "data/scripts/shared_secret_base.pory"
	goto_if_eq SecretBase_EventScript_SkittyTV
# 192 "data/scripts/shared_secret_base.pory"
	end
# 193 "data/scripts/shared_secret_base.pory"

# 194 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_BattleTowerShield::
# 195 "data/scripts/shared_secret_base.pory"
	msgbox SecretBase_Text_BattleTowerShield, MSGBOX_SIGN
# 196 "data/scripts/shared_secret_base.pory"
	end
# 197 "data/scripts/shared_secret_base.pory"

# 198 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_ToyTV::
# 199 "data/scripts/shared_secret_base.pory"
	msgbox SecretBase_Text_ToyTV, MSGBOX_SIGN
# 200 "data/scripts/shared_secret_base.pory"
	end
# 201 "data/scripts/shared_secret_base.pory"

# 202 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_SeedotTV::
# 203 "data/scripts/shared_secret_base.pory"
	msgbox SecretBase_Text_SeedotTV, MSGBOX_SIGN
# 204 "data/scripts/shared_secret_base.pory"
	end
# 205 "data/scripts/shared_secret_base.pory"

# 206 "data/scripts/shared_secret_base.pory"
SecretBase_EventScript_SkittyTV::
# 207 "data/scripts/shared_secret_base.pory"
	msgbox SecretBase_Text_SkittyTV, MSGBOX_SIGN
# 208 "data/scripts/shared_secret_base.pory"
	end

SecretBase_Text_SmallIndentInWall::
# 211 "data/scripts/shared_secret_base.pory"
	.string "There's a small indent in the wall.$"

SecretBase_Text_IndentUseSecretPower::
# 215 "data/scripts/shared_secret_base.pory"
	.string "There's a small indent in the wall.\p"
	.string "Use the Secret Power?$"

SecretBase_Text_DiscoveredSmallCavern::
# 220 "data/scripts/shared_secret_base.pory"
	.string "Discovered a small cavern!$"

SecretBase_Text_WantToMakeYourSecretBaseHere::
# 224 "data/scripts/shared_secret_base.pory"
	.string "Want to make your Secret Base here?$"
