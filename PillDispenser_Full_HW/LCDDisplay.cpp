//
// Created by szype on 17.05.2024.
//
#include "LCDDisplay.h"

namespace LCDDisplay {

TFT_eSPI tft = TFT_eSPI(); // Invoke custom library;
// Other declaration in config file

// Invoke the TFT_eSPI button class and create all the button objects
// Create 5 keys for the keypad
char bt_label_tab[5][9] = {CYLINDER_BT_LEFT_TEXT, CYLINDER_BT_RIGHT_TEXT,
                       BLOCKER_BT_MORNING_TEXT, BLOCKER_BT_NOON_TEXT, BLOCKER_BT_EVENING_TEXT
};
uint16_t bt_color_tab[5] = {CYLINDER_BT_COLOR, CYLINDER_BT_COLOR,
                        BLOCKER_BT_MORNING_COLOR, BLOCKER_BT_NOON_COLOR, BLOCKER_BT_EVENING_COLOR
};
TFT_eSPI_Button bt_struct_tab[5];


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
    uint16_t touch_x = 0, touch_y = 0; // To store the touch coordinates

    // Pressed will be set true is there is a valid touch on the screen
    bool pressed = tft.getTouch(&touch_x, &touch_y);

    // / Check if any key coordinate boxes contain the touch coordinates
    for (uint8_t bt_id = 0; bt_id < 5; bt_id++) {
        if (pressed && bt_struct_tab[bt_id].contains(touch_x, touch_y)) {
            bt_struct_tab[bt_id].press(true);  // tell the button it is pressed
        } else {
            bt_struct_tab[bt_id].press(false);  // tell the button it is NOT pressed
        }
    }

    // Check if any key has changed state
    for (uint8_t bt_id = 0; bt_id < 5; bt_id++) {
        if (bt_struct_tab[bt_id].justReleased()) bt_struct_tab[bt_id].drawButton();     // draw normal

        if (bt_struct_tab[bt_id].justPressed()) {
            bt_struct_tab[bt_id].drawButton(true);  // draw invert
            
            delay(10); // UI debouncing
        }
    }
}


void drawKeypad()
{
    // Draw the keys
    for (uint8_t bt_id = 0; bt_id<5; bt_id++){
        int pos_x, pos_y, width, height;
        uint8_t font_size;
        switch (bt_id) {
            case 0:
                pos_x = KEYPAD_PADDING + CYLINDER_BT_SIZE/2;
                pos_y = KEYPAD_PADDING + CYLINDER_BT_SIZE/2;
                width = CYLINDER_BT_SIZE;
                height = CYLINDER_BT_SIZE;
                break;
            case 1:
                pos_x = SCREEN_WIDTH - (CYLINDER_BT_SIZE/2) - KEYPAD_PADDING;
                pos_y = KEYPAD_PADDING + CYLINDER_BT_SIZE/2;
                width = CYLINDER_BT_SIZE;
                height = CYLINDER_BT_SIZE;
                break;
            case 2:
                pos_x = KEYPAD_PADDING + BLOCKER_BT_WIDTH/2;
                pos_y = SCREEN_HEIGHT - KEYPAD_PADDING - BLOCKER_BT_HEIGHT/2;
                width = BLOCKER_BT_WIDTH;
                height = BLOCKER_BT_HEIGHT;
                break;
            case 3:
                pos_x = KEYPAD_PADDING + BLOCKER_BT_WIDTH*1.5 + BLOCKER_BT_GAP;
                pos_y = SCREEN_HEIGHT - KEYPAD_PADDING - BLOCKER_BT_HEIGHT/2;
                width = BLOCKER_BT_WIDTH;
                height = BLOCKER_BT_HEIGHT;
                break;
            case 4:
                pos_x = KEYPAD_PADDING + BLOCKER_BT_WIDTH*2.5 + BLOCKER_BT_GAP*2;
                pos_y = SCREEN_HEIGHT - KEYPAD_PADDING - BLOCKER_BT_HEIGHT/2;
                width = BLOCKER_BT_WIDTH;
                height = BLOCKER_BT_HEIGHT;
                break;
        }

        if (bt_id < 2) font_size = CYLINDER_BT_FONT_SIZE;
        else font_size = BLOCKER_BT_FONT_SIZE;

        tft.setFreeFont(KEYPAD_FONT);
        bt_struct_tab[bt_id].initButton(&tft, pos_x, pos_y, // x, y, w, h, outline, fill, text
                          width, height, BT_OUTLINE, bt_color_tab[bt_id], BT_LABEL_COLOR,
                          bt_label_tab[bt_id], font_size);
        bt_struct_tab[bt_id].drawButton();
    }
}

}