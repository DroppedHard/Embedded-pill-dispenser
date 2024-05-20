#ifndef EMBEDDED_PILL_DISPENSER_GUITEST_H
#define EMBEDDED_PILL_DISPENSER_GUITEST_H

#include "Config.h"
#include <TFT_eSPI.h>       // WaveShare TFT touch screen handled by https://github.com/Bodmer/TFT_eSPI (+ two files updated manually!)

namespace LCDDisplay {
    enum class BlockerState : uint8_t {
        morning = 0,
        noon = 1,
        evening = 2,
        block = 3,
    };

    void initialize();
    void drawKeypad();
    void guiLoop(Interfaces::MoveCommunication *communicator);
    void orderMovement(Interfaces::MoveCommunication *communicator, bool isCylinder, long steps);
    long calculateBlockerSteps(BlockerState desiredState);
};



#endif //EMBEDDED_PILL_DISPENSER_GUITEST_H
