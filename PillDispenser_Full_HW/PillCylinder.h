#ifndef EMBEDDED_PILL_DISPENSER_PILLCYLINDER_H
#define EMBEDDED_PILL_DISPENSER_PILLCYLINDER_H
#include <AccelStepper.h>   //https://www.airspayce.com/mikem/arduino/AccelStepper/ - improved lib for stepper motors
#include "Config.h"

namespace PillCylinder {
    void initialize();
    void cylinderLoop(Interfaces::MoveCommunication *communicator);
};


#endif //EMBEDDED_PILL_DISPENSER_PILLCYLINDER_H
