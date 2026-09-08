LatiTempleLatias_MapScripts::
# 2 "data/maps/LatiTempleLatias/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LatiTempleLatias_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

LatiTempleLatias_MapScripts_MAP_SCRIPT_ON_LOAD:
# 3 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_RefreshPuzzle
	return


LatiTemple_Latias::
# 8 "data/maps/LatiTempleLatias/scripts.pory"
	lock
# 9 "data/maps/LatiTempleLatias/scripts.pory"
	faceplayer
# 10 "data/maps/LatiTempleLatias/scripts.pory"
	bosslegendaryencounterwithmoves SPECIES_LATIAS, 80, LOCALID_LATIAS, FLAG_HIDE_LATIAS, 3, SPECIES_NONE, 110, MOVE_MIST_BALL, MOVE_ICE_BEAM, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT
# 12 "data/maps/LatiTempleLatias/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq LatiTemple_Latias_2
LatiTemple_Latias_1:
# 15 "data/maps/LatiTempleLatias/scripts.pory"
	release
	end

LatiTemple_Latias_2:
# 13 "data/maps/LatiTempleLatias/scripts.pory"
	setflag FLAG_CAUGHT_LATIAS
	goto LatiTemple_Latias_1


ResetLatiasPuzzle::
# 20 "data/maps/LatiTempleLatias/scripts.pory"
	lock
# 21 "data/maps/LatiTempleLatias/scripts.pory"
	msgbox ResetLatiasPuzzle_Text_0, MSGBOX_YESNO
# 22 "data/maps/LatiTempleLatias/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ResetLatiasPuzzle_2
ResetLatiasPuzzle_1:
# 33 "data/maps/LatiTempleLatias/scripts.pory"
	releaseall
	end

ResetLatiasPuzzle_2:
# 23 "data/maps/LatiTempleLatias/scripts.pory"
	clearflag FLAG_LATITEMPLE_SWITCH1
# 24 "data/maps/LatiTempleLatias/scripts.pory"
	clearflag FLAG_LATITEMPLE_SWITCH2
# 25 "data/maps/LatiTempleLatias/scripts.pory"
	clearflag FLAG_LATITEMPLE_SWITCH3
# 26 "data/maps/LatiTempleLatias/scripts.pory"
	clearflag FLAG_LATITEMPLE_SWITCH4
# 27 "data/maps/LatiTempleLatias/scripts.pory"
	clearflag FLAG_LATITEMPLE_SWITCH5
# 28 "data/maps/LatiTempleLatias/scripts.pory"
	playse SE_PIN
# 29 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_RefreshPuzzle
# 30 "data/maps/LatiTempleLatias/scripts.pory"
	special DrawWholeMapView
# 31 "data/maps/LatiTempleLatias/scripts.pory"
	waitse
	goto ResetLatiasPuzzle_1


LatiTemple_Switch1::
# 38 "data/maps/LatiTempleLatias/scripts.pory"
	lockall
# 39 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH1, LatiTemple_Switch1_2
# 42 "data/maps/LatiTempleLatias/scripts.pory"
	setflag FLAG_LATITEMPLE_SWITCH1
LatiTemple_Switch1_1:
# 44 "data/maps/LatiTempleLatias/scripts.pory"
	playse SE_PIN
# 45 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_RefreshPuzzle
# 46 "data/maps/LatiTempleLatias/scripts.pory"
	special DrawWholeMapView
# 47 "data/maps/LatiTempleLatias/scripts.pory"
	waitse
# 48 "data/maps/LatiTempleLatias/scripts.pory"
	releaseall
	return

LatiTemple_Switch1_2:
# 40 "data/maps/LatiTempleLatias/scripts.pory"
	clearflag FLAG_LATITEMPLE_SWITCH1
	goto LatiTemple_Switch1_1


LatiTemple_Switch2::
# 52 "data/maps/LatiTempleLatias/scripts.pory"
	lockall
# 53 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH2, LatiTemple_Switch2_2
# 56 "data/maps/LatiTempleLatias/scripts.pory"
	setflag FLAG_LATITEMPLE_SWITCH2
LatiTemple_Switch2_1:
# 58 "data/maps/LatiTempleLatias/scripts.pory"
	playse SE_PIN
# 59 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_RefreshPuzzle
# 60 "data/maps/LatiTempleLatias/scripts.pory"
	special DrawWholeMapView
# 61 "data/maps/LatiTempleLatias/scripts.pory"
	waitse
# 62 "data/maps/LatiTempleLatias/scripts.pory"
	releaseall
	return

LatiTemple_Switch2_2:
# 54 "data/maps/LatiTempleLatias/scripts.pory"
	clearflag FLAG_LATITEMPLE_SWITCH2
	goto LatiTemple_Switch2_1


LatiTemple_Switch3::
# 66 "data/maps/LatiTempleLatias/scripts.pory"
	lockall
# 67 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH3, LatiTemple_Switch3_2
# 70 "data/maps/LatiTempleLatias/scripts.pory"
	setflag FLAG_LATITEMPLE_SWITCH3
LatiTemple_Switch3_1:
# 72 "data/maps/LatiTempleLatias/scripts.pory"
	playse SE_PIN
# 73 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_RefreshPuzzle
# 74 "data/maps/LatiTempleLatias/scripts.pory"
	special DrawWholeMapView
# 75 "data/maps/LatiTempleLatias/scripts.pory"
	waitse
# 76 "data/maps/LatiTempleLatias/scripts.pory"
	releaseall
	return

LatiTemple_Switch3_2:
# 68 "data/maps/LatiTempleLatias/scripts.pory"
	clearflag FLAG_LATITEMPLE_SWITCH3
	goto LatiTemple_Switch3_1


LatiTemple_Switch4::
# 80 "data/maps/LatiTempleLatias/scripts.pory"
	lockall
# 81 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH4, LatiTemple_Switch4_2
# 84 "data/maps/LatiTempleLatias/scripts.pory"
	setflag FLAG_LATITEMPLE_SWITCH4
LatiTemple_Switch4_1:
# 86 "data/maps/LatiTempleLatias/scripts.pory"
	playse SE_PIN
# 87 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_RefreshPuzzle
# 88 "data/maps/LatiTempleLatias/scripts.pory"
	special DrawWholeMapView
# 89 "data/maps/LatiTempleLatias/scripts.pory"
	waitse
# 90 "data/maps/LatiTempleLatias/scripts.pory"
	releaseall
	return

LatiTemple_Switch4_2:
# 82 "data/maps/LatiTempleLatias/scripts.pory"
	clearflag FLAG_LATITEMPLE_SWITCH4
	goto LatiTemple_Switch4_1


LatiTemple_Switch5::
# 94 "data/maps/LatiTempleLatias/scripts.pory"
	lockall
# 95 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH5, LatiTemple_Switch5_2
# 98 "data/maps/LatiTempleLatias/scripts.pory"
	setflag FLAG_LATITEMPLE_SWITCH5
LatiTemple_Switch5_1:
# 100 "data/maps/LatiTempleLatias/scripts.pory"
	playse SE_PIN
# 101 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_RefreshPuzzle
# 102 "data/maps/LatiTempleLatias/scripts.pory"
	special DrawWholeMapView
# 103 "data/maps/LatiTempleLatias/scripts.pory"
	waitse
# 104 "data/maps/LatiTempleLatias/scripts.pory"
	releaseall
	return

LatiTemple_Switch5_2:
# 96 "data/maps/LatiTempleLatias/scripts.pory"
	clearflag FLAG_LATITEMPLE_SWITCH5
	goto LatiTemple_Switch5_1


LatiTemple_RefreshPuzzle::
# 108 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_SetSwitch1State
# 109 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_SetSwitch2State
# 110 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_SetSwitch3State
# 111 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_SetSwitch4State
# 112 "data/maps/LatiTempleLatias/scripts.pory"
	call LatiTemple_SetSwitch5State
	return


LatiTemple_SetSwitch1State::
# 117 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH1, LatiTemple_SetSwitch1State_2
# 131 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 17, 27, METATILE_LatiTemple_ActiveGray, FALSE
# 132 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 33, 33, METATILE_LatiTemple_ActiveGray, FALSE
# 134 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 36, 21, METATILE_LatiTemple_InactiveGreen, TRUE
# 135 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 18, 23, METATILE_LatiTemple_InactiveGreen, TRUE
# 137 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 18, 17, METATILE_LatiTemple_InactiveGray, TRUE
# 138 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 34, 1, METATILE_LatiTemple_InactiveGray, TRUE
# 140 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 21, 4, METATILE_LatiTemple_ActiveGreen, FALSE
# 141 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 51, 31, METATILE_LatiTemple_ActiveGreen, FALSE
# 142 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 32, 21, METATILE_LatiTemple_CrystalSwitchInactive, TRUE
LatiTemple_SetSwitch1State_1:
	return

LatiTemple_SetSwitch1State_2:
# 118 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 17, 27, METATILE_LatiTemple_InactiveGray, TRUE
# 119 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 33, 33, METATILE_LatiTemple_InactiveGray, TRUE
# 121 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 36, 21, METATILE_LatiTemple_ActiveGreen, FALSE
# 122 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 18, 23, METATILE_LatiTemple_ActiveGreen, FALSE
# 124 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 18, 17, METATILE_LatiTemple_ActiveGray, FALSE
# 125 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 34, 1, METATILE_LatiTemple_ActiveGray, FALSE
# 127 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 21, 4, METATILE_LatiTemple_InactiveGreen, TRUE
# 128 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 51, 31, METATILE_LatiTemple_InactiveGreen, TRUE
# 129 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 32, 21, METATILE_LatiTemple_CrystalSwitchActive, TRUE
	goto LatiTemple_SetSwitch1State_1


LatiTemple_SetSwitch2State::
# 148 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH2, LatiTemple_SetSwitch2State_2
# 153 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 45, 25, METATILE_LatiTemple_InactiveGray, TRUE
# 154 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 54, 20, METATILE_LatiTemple_InactiveGray, TRUE
# 155 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 32, 3, METATILE_LatiTemple_CrystalSwitchInactive, TRUE
LatiTemple_SetSwitch2State_1:
	return

LatiTemple_SetSwitch2State_2:
# 149 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 45, 25, METATILE_LatiTemple_ActiveGray, FALSE
# 150 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 54, 20, METATILE_LatiTemple_ActiveGray, FALSE
# 151 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 32, 3, METATILE_LatiTemple_CrystalSwitchActive, TRUE
	goto LatiTemple_SetSwitch2State_1


LatiTemple_SetSwitch3State::
# 161 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH3, LatiTemple_SetSwitch3State_2
# 172 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 37, 30, METATILE_LatiTemple_ActiveBlue, FALSE
# 173 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 28, 21, METATILE_LatiTemple_ActiveBlue, FALSE
# 175 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 45, 11, METATILE_LatiTemple_ActiveGreen, FALSE
# 176 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 43, 18, METATILE_LatiTemple_ActiveGreen, FALSE
# 178 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 51, 23, METATILE_LatiTemple_InactiveBlue, TRUE
# 179 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 14, 10, METATILE_LatiTemple_InactiveBlue, TRUE
# 180 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 46, 21, METATILE_LatiTemple_CrystalSwitchInactive, TRUE
LatiTemple_SetSwitch3State_1:
	return

LatiTemple_SetSwitch3State_2:
# 162 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 37, 30, METATILE_LatiTemple_InactiveBlue, TRUE
# 163 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 28, 21, METATILE_LatiTemple_InactiveBlue, TRUE
# 165 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 45, 11, METATILE_LatiTemple_InactiveGreen, TRUE
# 166 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 43, 18, METATILE_LatiTemple_InactiveGreen, TRUE
# 168 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 51, 23, METATILE_LatiTemple_ActiveBlue, FALSE
# 169 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 14, 10, METATILE_LatiTemple_ActiveBlue, FALSE
# 170 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 46, 21, METATILE_LatiTemple_CrystalSwitchActive, TRUE
	goto LatiTemple_SetSwitch3State_1


LatiTemple_SetSwitch4State::
# 186 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH4, LatiTemple_SetSwitch4State_2
# 191 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 21, 30, METATILE_LatiTemple_InactiveBlue, TRUE
# 192 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 41, 31, METATILE_LatiTemple_InactiveBlue, TRUE
# 193 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 15, 6, METATILE_LatiTemple_CrystalSwitchInactive, TRUE
LatiTemple_SetSwitch4State_1:
	return

LatiTemple_SetSwitch4State_2:
# 187 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 21, 30, METATILE_LatiTemple_ActiveBlue, FALSE
# 188 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 41, 31, METATILE_LatiTemple_ActiveBlue, FALSE
# 189 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 15, 6, METATILE_LatiTemple_CrystalSwitchActive, TRUE
	goto LatiTemple_SetSwitch4State_1


LatiTemple_SetSwitch5State::
# 199 "data/maps/LatiTempleLatias/scripts.pory"
	goto_if_set FLAG_LATITEMPLE_SWITCH5, LatiTemple_SetSwitch5State_2
# 207 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 30, 5, METATILE_LatiTemple_ActiveBlue, FALSE
# 208 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 51, 11, METATILE_LatiTemple_ActiveBlue, FALSE
# 210 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 12, 30, METATILE_LatiTemple_InactiveGreen, TRUE
# 211 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 5, 23, METATILE_LatiTemple_InactiveGreen, TRUE
# 212 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 51, 28, METATILE_LatiTemple_CrystalSwitchInactive, TRUE
LatiTemple_SetSwitch5State_1:
	return

LatiTemple_SetSwitch5State_2:
# 200 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 30, 5, METATILE_LatiTemple_InactiveBlue, TRUE
# 201 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 51, 11, METATILE_LatiTemple_InactiveBlue, TRUE
# 203 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 12, 30, METATILE_LatiTemple_ActiveGreen, FALSE
# 204 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 5, 23, METATILE_LatiTemple_ActiveGreen, FALSE
# 205 "data/maps/LatiTempleLatias/scripts.pory"
	setmetatile 51, 28, METATILE_LatiTemple_CrystalSwitchActive, TRUE
	goto LatiTemple_SetSwitch5State_1


ResetLatiasPuzzle_Text_0:
# 21 "data/maps/LatiTempleLatias/scripts.pory"
	.string "Would you like to reset the puzzle?$"
