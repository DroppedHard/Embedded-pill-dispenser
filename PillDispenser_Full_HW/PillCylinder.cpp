//
// Created by szype on 18.05.2024.
//

#include "PillCylinder.h"

namespace PillCylinder {

    AccelStepper Stepper_1(AccelStepper::FULL4WIRE, In1, In3, In2, In4); //motor for rotation
    AccelStepper Stepper_2(AccelStepper::FULL4WIRE, In2_1, In2_3, In2_2, In2_4); //motor for bottom cover

    void initialize() {
        Stepper_1.setMaxSpeed(1000);
        Stepper_2.setMaxSpeed(1000);
        Stepper_1.setSpeed(450);
        Stepper_2.setSpeed(450);
    }

    void cylinderLoop() {
        Stepper_1.runSpeed(); // running motor 1
        Stepper_2.runSpeed(); // running motor 2
    }
}