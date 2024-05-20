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
const int PIN_BLOCKER_Home = 28; // HIGH - on MORNING
const int PIN_CYLINDER_Home = 14;
const int SM_Enable = 7;
const int GP_Button = 22;



// File for calibration data
#define CALIBRATION_FILE "/TouchCalData2"


// KEYPAD DEFINITIONS

#define SCREEN_ROTATION 1 // 0 - vertical, 1 - horizontal

// colors
#define BG_COLOR TFT_DARKGREY
#define CYLINDER_BT_COLOR TFT_PINK
#define BLOCKER_BT_BLOCK_COLOR TFT_RED
#define BLOCKER_BT_MOVE_COLOR TFT_VIOLET
#define BLOCKER_BT_MORNING_COLOR TFT_GREENYELLOW
#define BLOCKER_BT_NOON_COLOR TFT_SKYBLUE
#define BLOCKER_BT_EVENING_COLOR TFT_GOLD
#define BT_OUTLINE TFT_BLACK
#define BT_LABEL_COLOR TFT_BLACK


// dimensions
#define SCREEN_HEIGHT 320
#define SCREEN_WIDTH 480
#define KEYPAD_PADDING 30
#define CYLINDER_BT_SIZE 100
#define BLOCKER_BT_HEIGHT 50
#define BLOCKER_BT_WIDTH 120
#define BLOCKER_BT_GAP 30
#define ROWS_GAP 30

// font styling and size
#define KEYPAD_FONT &FreeSansBold12pt7b
#define CYLINDER_BT_FONT_SIZE 2
#define BLOCKER_BT_FONT_SIZE 1

// buttons content

#define CYLINDER_BT_LEFT_TEXT "<"
#define CYLINDER_BT_RIGHT_TEXT ">"
#define BLOCKER_BT_BLOCK_TEXT "blokuj"
#define BLOCKER_BT_MORNING_TEXT "rano"
#define BLOCKER_BT_NOON_TEXT "poludnie"
#define BLOCKER_BT_EVENING_TEXT "wieczor"

// CYLINDER DEFINITIONS

#define MOTOR_CYLINDER_SETUP_STEP 100
#define MOTOR_CYLINDER_STEP 512L
#define MOTOR_CYLINDER_MOVE 20L
#define MOTOR_CYLINDER_MAX_SPEED 1000
#define MOTOR_CYLINDER_BASE_SPEED 450
#define MOTOR_CYLINDER_ACCELERATION 1000

// BLOCKER DEFINITIONS

#define MOTOR_BLOCKER_SETUP_STEP 100
#define MOTOR_BLOCKER_STEP 706L
#define MOTOR_BLOCKER_MOVE 50L
#define MOTOR_BLOCKER_MAX_SPEED 500
#define MOTOR_BLOCKER_BASE_SPEED 450
#define MOTOR_BLOCKER_ACCELERATION 1000

namespace Interfaces {
    struct MoveCommunication {
        bool inProgress;
        bool cylinderMove; // false - not for this device
        bool blockerMove;
        long steps;
    };
}

#endif //EMBEDDED_PILL_DISPENSER_CONFIG_H
