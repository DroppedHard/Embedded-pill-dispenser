//
// Created by szype on 17.05.2024.
//

#ifndef EMBEDDED_PILL_DISPENSER_CONFIG_H
#define EMBEDDED_PILL_DISPENSER_CONFIG_H

#include <cstdint>

// pins
const int In1 =   2;
const int In2 =   3;
const int In3 =   26;
const int In4 =   27;
const int In2_1 = 18;
const int In2_2 = 19;
const int In2_3 = 20;
const int In2_4 = 21;
const int SM1_Home = 14;
const int SM2_Home = 28;
const int SM_Enable = 7;
const int GP_Button = 22;



// File for calibration data
#define CALIBRATION_FILE "/TouchCalData2"


// KEYPAD DEFINITIONS

#define SCREEN_ROTATION 1 // 0 - vertical, 1 - horizontal

// colors
#define BG_COLOR TFT_DARKGREY
#define CYLINDER_BT_COLOR TFT_PINK
#define BLOCKER_BT_MORNING_COLOR TFT_GREENYELLOW
#define BLOCKER_BT_NOON_COLOR TFT_SKYBLUE
#define BLOCKER_BT_EVENING_COLOR TFT_GOLD


// dimensions
#define SCREEN_HEIGHT 320
#define SCREEN_WIDTH 480
#define KEYPAD_PADDING 30
#define CYLINDER_BT_SIZE 130
#define BLOCKER_BT_HEIGHT 100
#define BLOCKER_BT_WIDTH 120
#define BLOCKER_BT_GAP 30
#define ROWS_GAP 30

// font styling and size
#define KEYPAD_FONT &FreeSansBold12pt7b    // Key label font 2
#define CYLINDER_BT_FONT_SIZE 96
#define BLOCKER_BT_FONT_SIZE 20

// buttons content

#define CYLINDER_BT_LEFT_TEXT "<"
#define CYLINDER_BT_RIGHT_TEXT ">"
#define BLOCKER_BT_MORNING_TEXT "rano"
#define BLOCKER_BT_NOON_TEXT "południe"
#define BLOCKER_BT_EVENING_TEXT "wieczór"

#endif //EMBEDDED_PILL_DISPENSER_CONFIG_H
