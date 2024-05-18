//
// Created by szype on 17.05.2024.
//

#ifndef EMBEDDED_PILL_DISPENSER_CONFIG_H
#define EMBEDDED_PILL_DISPENSER_CONFIG_H

#include <cstdint>

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



// This is the file name used to store the calibration data
// You can change this to create new calibration files.
// The SPIFFS file name must start with "/".
#define CALIBRATION_FILE "/TouchCalData2"

// Set REPEAT_CAL to true instead of false to run calibration
// again, otherwise it will only be done once.
// Repeat calibration if you change the screen rotation.
#define REPEAT_CAL false


// DEMO KEYPAD DEFINITIONS

// Keypad start position, key sizes and spacing
#define KEY_X 80 // Centre of key
#define KEY_Y 96
#define KEY_W 124 // Width and height
#define KEY_H 30
#define KEY_SPACING_X 36 // X and Y gap
#define KEY_SPACING_Y 20
#define KEY_TEXTSIZE 1   // Font size multiplier

// Using two fonts since numbers are nice when bold
#define LABEL1_FONT &FreeSansOblique12pt7b // Key label font 1
#define LABEL2_FONT &FreeSansBold12pt7b    // Key label font 2

// Numeric display box size and location
#define DISP_X 10
#define DISP_Y 10
#define DISP_W 460
#define DISP_H 50
#define DISP_TSIZE 3
#define DISP_TCOLOR TFT_CYAN

// Number length, buffer for storing it and character index
#define NUM_LEN 24


// We have a status line for messages
#define STATUS_X 120 // Centred on this
#define STATUS_Y 65


//------------------------------------------------------------------------------------------



#endif //EMBEDDED_PILL_DISPENSER_CONFIG_H
