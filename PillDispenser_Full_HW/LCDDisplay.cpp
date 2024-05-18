//
// Created by szype on 17.05.2024.
//
#include "LCDDisplay.h"

namespace LCDDisplay {

TFT_eSPI tft = TFT_eSPI(); // Invoke custom library;
// Other declaration in config file

// Invoke the TFT_eSPI button class and create all the button objects
// Create 5 keys for the keypad
char keyLabel[5][9] = {CYLINDER_BT_LEFT_TEXT, CYLINDER_BT_RIGHT_TEXT,
                       BLOCKER_BT_MORNING_TEXT, BLOCKER_BT_NOON_TEXT, BLOCKER_BT_EVENING_TEXT
};
uint16_t keyColor[5] = {CYLINDER_BT_COLOR, CYLINDER_BT_COLOR,
                        BLOCKER_BT_MORNING_COLOR, BLOCKER_BT_NOON_COLOR, BLOCKER_BT_EVENING_COLOR
};
TFT_eSPI_Button key[5];


void initialize() {
    // Initialise the TFT screen
    tft.init();

    // Rotate the screen for horizontal view
    tft.setRotation(SCREEN_ROTATION);

    // invert colors for proper color representation on screen
    tft.invertDisplay( true );

    // Clear the screen
    tft.fillScreen(BG_COLOR);
}

void guiLoop() {

}


void drawKeypad()
{
    // Draw the keys

}

}