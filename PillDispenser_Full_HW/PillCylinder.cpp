//
// Created by szype on 18.05.2024.
//

#include "PillCylinder.h"

#include <elapsedMillis.h>  //https://github.com/pfeerick/elapsedMillis/wiki - handling events



namespace PillCylinder {

    elapsedMillis timeElapsed;

    AccelStepper blockerStepper(AccelStepper::FULL4WIRE, In1, In3, In2, In4); //motor for rotation
    AccelStepper cylinderStepper(AccelStepper::FULL4WIRE, In2_1, In2_3, In2_2, In2_4); //motor for bottom cover

//    uint8_t currSectionId = 0;
//    uint8_t maxSectionId = 13;

    void initialize() {
        blockerStepper.setMaxSpeed(1000);
        blockerStepper.setSpeed(450);
        blockerStepper.setAcceleration(500);

        cylinderStepper.setMaxSpeed(1000);
        cylinderStepper.setSpeed(450);
        cylinderStepper.setAcceleration(1000);
        digitalWrite(SM_Enable, LOW);

    }

    void cylinderLoop(Interfaces::MoveCommunication *communicator) {

        if (communicator->inProgress) {
            digitalWrite(SM_Enable, HIGH);
            if (communicator->cylinderMove){
                cylinderStepper.runToNewPosition(cylinderStepper.currentPosition() + communicator->steps);
                communicator->cylinderMove = false;
            }
            if (communicator->blockerMove) {
                blockerStepper.runToNewPosition(blockerStepper.currentPosition() + communicator->steps);
                communicator->blockerMove = false;
            }
            communicator->steps = 0;
            communicator->inProgress = false;
            digitalWrite(SM_Enable, LOW);
        }
    }

}