#ifndef EMBEDDED_PILL_DISPENSER_PILLCYLINDER_H
#define EMBEDDED_PILL_DISPENSER_PILLCYLINDER_H
#include <AccelStepper.h>   //https://www.airspayce.com/mikem/arduino/AccelStepper/ - improved lib for stepper motors
#include "Config.h"

namespace PillCylinder {
    void prepareCylinder(Interfaces::MoveCommunication *communicator);
    void prepareBlocker(Interfaces::MoveCommunication *communicator);
    void motorLoop(Interfaces::MoveCommunication *communicator);
};


#endif //EMBEDDED_PILL_DISPENSER_PILLCYLINDER_H
