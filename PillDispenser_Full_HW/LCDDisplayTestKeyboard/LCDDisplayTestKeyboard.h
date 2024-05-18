//
// Created by szype on 17.05.2024.
//

#ifndef EMBEDDED_PILL_DISPENSER_GUITEST_H
#define EMBEDDED_PILL_DISPENSER_GUITEST_H

#include "ConfigLCDTest.h"
#include <TFT_eSPI.h>       // WaveShare TFT touch screen handled by https://github.com/Bodmer/TFT_eSPI (+ two files updated manually!)

namespace LCDDisplayTestKeyboard {

    void initialize();
    void guiLoop();
    void drawKeypad();
    void touchCalibrate();
    void status(const char *msg);
};



#endif //EMBEDDED_PILL_DISPENSER_GUITEST_H
