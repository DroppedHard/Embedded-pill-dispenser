#include "LCDDisplay.h"

namespace LCDDisplay {

TFT_eSPI tft = TFT_eSPI();

#define BT_NUM 10

char bt_label_tab[BT_NUM][9] = {CYLINDER_BT_LEFT_TEXT, CYLINDER_BT_RIGHT_TEXT,
                       CYLINDER_BT_LEFT_TEXT, CYLINDER_BT_RIGHT_TEXT,
                       BLOCKER_BT_BLOCK_TEXT, CYLINDER_BT_LEFT_TEXT, CYLINDER_BT_RIGHT_TEXT,
                       BLOCKER_BT_MORNING_TEXT, BLOCKER_BT_NOON_TEXT, BLOCKER_BT_EVENING_TEXT
};
uint16_t bt_color_tab[BT_NUM] = {CYLINDER_BT_COLOR, CYLINDER_BT_COLOR,
                            CYLINDER_BT_COLOR, CYLINDER_BT_COLOR,
                            BLOCKER_BT_BLOCK_COLOR, BLOCKER_BT_MOVE_COLOR, BLOCKER_BT_MOVE_COLOR,
                        BLOCKER_BT_MORNING_COLOR, BLOCKER_BT_NOON_COLOR, BLOCKER_BT_EVENING_COLOR
};
TFT_eSPI_Button bt_struct_tab[BT_NUM];


void initialize() {
    tft.init();
    tft.setRotation(SCREEN_ROTATION);
    tft.invertDisplay( true );
    tft.fillScreen(BG_COLOR);
}

void guiLoop(Interfaces::MoveCommunication *communicator) {
    uint16_t touch_x = 0, touch_y = 0;

    bool pressed = tft.getTouch(&touch_x, &touch_y);

    for (uint8_t bt_id = 0; bt_id < BT_NUM; bt_id++) {
        if (pressed && bt_struct_tab[bt_id].contains(touch_x, touch_y)) {
            bt_struct_tab[bt_id].press(true);
        } else {
            bt_struct_tab[bt_id].press(false);
        }
    }

    // Check if any key has changed state
    for (uint8_t bt_id = 0; bt_id < BT_NUM; bt_id++) {
        if (bt_struct_tab[bt_id].justReleased()) bt_struct_tab[bt_id].drawButton();

        if (bt_struct_tab[bt_id].justPressed()) {
            bt_struct_tab[bt_id].drawButton(true);
            communicator->inProgress = true;
            switch (bt_id) {
                case 0: // cylinder left section
                    orderMovement(communicator, true, -MOTOR_CYLINDER_STEP);
                    break;
                case 1: // cylinder right section
                    orderMovement(communicator, true, MOTOR_CYLINDER_STEP);
                    break;
                case 2: // cylinder small move left
                    orderMovement(communicator, true, -MOTOR_CYLINDER_MOVE);
                    break;
                case 3: // cylinder small move right
                    orderMovement(communicator, true, MOTOR_CYLINDER_MOVE);
                    break;
                case 4: // blocker block button

                    break;
                case 5: // blocker move left
                    orderMovement(communicator, false, -512);
                    break;
                case 6: // blocker move right
                    orderMovement(communicator, false, 512);
                    break;
                case 7: // blocker morning
;
                    break;
                case 8: // blocker noon

                    break;
                case 9: // blocker evening

                    break;
            }
            delay(10); // UI debouncing
        }
    }
}


void drawKeypad()
{
    for (uint8_t bt_id = 0; bt_id<BT_NUM; bt_id++){
        int pos_x, pos_y, width, height;
        uint8_t font_size;
        switch (bt_id) {
            case 0: // cylinder left section
                pos_x = KEYPAD_PADDING + CYLINDER_BT_SIZE/2;
                pos_y = KEYPAD_PADDING + CYLINDER_BT_SIZE/2;
                width = CYLINDER_BT_SIZE;
                height = CYLINDER_BT_SIZE;
                break;
            case 1: // cylinder right section
                pos_x = SCREEN_WIDTH - (CYLINDER_BT_SIZE/2) - KEYPAD_PADDING;
                pos_y = KEYPAD_PADDING + CYLINDER_BT_SIZE/2;
                width = CYLINDER_BT_SIZE;
                height = CYLINDER_BT_SIZE;
                break;
            case 2: // cylinder small move left
                pos_x = SCREEN_WIDTH/2 - (CYLINDER_BT_SIZE/4) - KEYPAD_PADDING/2;
                pos_y = KEYPAD_PADDING + CYLINDER_BT_SIZE/4;
                width = CYLINDER_BT_SIZE/2;
                height = CYLINDER_BT_SIZE/2;
                break;
            case 3: // cylinder small move right
                pos_x = SCREEN_WIDTH/2 + (CYLINDER_BT_SIZE/4) + KEYPAD_PADDING/2;
                pos_y = KEYPAD_PADDING + CYLINDER_BT_SIZE/4;
                width = CYLINDER_BT_SIZE/2;
                height = CYLINDER_BT_SIZE/2;
                break;
            case 4: // blocker block button
                pos_x = KEYPAD_PADDING + BLOCKER_BT_WIDTH/2;
                pos_y = SCREEN_HEIGHT - KEYPAD_PADDING - BLOCKER_BT_HEIGHT*1.5 - BLOCKER_BT_GAP;
                width = BLOCKER_BT_WIDTH;
                height = BLOCKER_BT_HEIGHT;
                break;
            case 5: // blocker move left
                pos_x = KEYPAD_PADDING + BLOCKER_BT_WIDTH*1.5 + BLOCKER_BT_GAP;
                pos_y = SCREEN_HEIGHT - KEYPAD_PADDING - BLOCKER_BT_HEIGHT*1.5 - BLOCKER_BT_GAP;
                width = BLOCKER_BT_WIDTH;
                height = BLOCKER_BT_HEIGHT;
                break;
            case 6: // blocker move right
                pos_x = KEYPAD_PADDING + BLOCKER_BT_WIDTH*2.5 + BLOCKER_BT_GAP*2;
                pos_y = SCREEN_HEIGHT - KEYPAD_PADDING - BLOCKER_BT_HEIGHT*1.5 - BLOCKER_BT_GAP;
                width = BLOCKER_BT_WIDTH;
                height = BLOCKER_BT_HEIGHT;
                break;
            case 7: // blocker morning
                pos_x = KEYPAD_PADDING + BLOCKER_BT_WIDTH/2;
                pos_y = SCREEN_HEIGHT - KEYPAD_PADDING - BLOCKER_BT_HEIGHT/2;
                width = BLOCKER_BT_WIDTH;
                height = BLOCKER_BT_HEIGHT;
                break;
            case 8: // blocker noon
                pos_x = KEYPAD_PADDING + BLOCKER_BT_WIDTH*1.5 + BLOCKER_BT_GAP;
                pos_y = SCREEN_HEIGHT - KEYPAD_PADDING - BLOCKER_BT_HEIGHT/2;
                width = BLOCKER_BT_WIDTH;
                height = BLOCKER_BT_HEIGHT;
                break;
            case 9: // blocker evening
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

void orderMovement(Interfaces::MoveCommunication *communicator, bool isCylinder, long steps) {
    if (isCylinder) communicator->cylinderMove = true;
    else communicator->blockerMove = true;
    communicator->steps = steps;
}

}