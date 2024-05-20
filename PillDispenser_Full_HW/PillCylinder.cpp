#include "PillCylinder.h"
#include <elapsedMillis.h>  //https://github.com/pfeerick/elapsedMillis/wiki - handling events for prepareCylinder()


namespace PillCylinder {

    elapsedMillis timeElapsed;

    AccelStepper blockerStepper(AccelStepper::FULL4WIRE, In1, In3, In2, In4);
    AccelStepper cylinderStepper(AccelStepper::FULL4WIRE, In2_1, In2_3, In2_2, In2_4);



    void prepareCylinder(Interfaces::MoveCommunication *communicator) {
        cylinderStepper.setMaxSpeed(MOTOR_CYLINDER_MAX_SPEED);
        cylinderStepper.setSpeed(MOTOR_CYLINDER_BASE_SPEED);
        cylinderStepper.setAcceleration(MOTOR_CYLINDER_ACCELERATION);

        communicator->inProgress = true;
        communicator->cylinderMove = true;
        int cylinderState = true;
        while (communicator->cylinderMove) {
            Serial.print("CYLINDER | During setup ");
            Serial.println(cylinderState);
            digitalWrite(SM_Enable, HIGH);
            cylinderStepper.runToNewPosition(cylinderStepper.currentPosition() + MOTOR_CYLINDER_SETUP_STEP);
            cylinderState = digitalRead(PIN_CYLINDER_Home);
            if (!cylinderState) {
                communicator->cylinderMove = false;
                digitalWrite(SM_Enable, LOW);
            }
        }

        if (!communicator->blockerMove) {
            communicator->inProgress = false;
            Serial.println("Setup finished!");
        }
    }

    void prepareBlocker(Interfaces::MoveCommunication *communicator) {
        blockerStepper.setMaxSpeed(MOTOR_BLOCKER_MAX_SPEED);
        blockerStepper.setSpeed(MOTOR_BLOCKER_BASE_SPEED);
        blockerStepper.setAcceleration(MOTOR_BLOCKER_ACCELERATION);

        communicator->inProgress = true;
        communicator->blockerMove = true;
        int blockerState = false;
        while (communicator->blockerMove) {
            Serial.print("BLOCKER | During setup ");
            Serial.println(blockerState);
            digitalWrite(SM_Enable, HIGH);
            blockerStepper.runToNewPosition(blockerStepper.currentPosition() - MOTOR_BLOCKER_SETUP_STEP);
            blockerState = digitalRead(PIN_BLOCKER_Home);
            if (blockerState) {
                communicator->blockerMove = false;
                digitalWrite(SM_Enable, LOW);
            }
        }

        if (!communicator->cylinderMove) {
            communicator->inProgress = false;
            Serial.println("Setup finished!");
        }
    }

    void motorLoop(Interfaces::MoveCommunication *communicator) {
        if (communicator->inProgress) {
            digitalWrite(SM_Enable, HIGH);
            Serial.print("MOVING | cylinderMove: ");
            Serial.print(communicator->cylinderMove);
            Serial.print(" | blockerMove: ");
            Serial.print(communicator->blockerMove);
            Serial.print(" | steps: ");
            Serial.println(communicator->steps);
            if (communicator->cylinderMove){
                cylinderStepper.runToNewPosition(cylinderStepper.currentPosition() + communicator->steps);
                communicator->cylinderMove = false;
            }
            else if (communicator->blockerMove) {
                blockerStepper.runToNewPosition(blockerStepper.currentPosition() + communicator->steps);
                communicator->blockerMove = false;
            }
            communicator->steps = 0;
            communicator->inProgress = false;
            digitalWrite(SM_Enable, LOW);
        }

    }
}