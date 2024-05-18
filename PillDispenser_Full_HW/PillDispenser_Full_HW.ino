// testing HW for PilDispenser:
// WaveShare LCD with Touch screen
// Two stepper motors connected
// Two home sensors for rotation and bottom blocker
// Pills sensor
// RTC?
// Push button - call for action
// ...?
#include <TimeLib.h>        //standard Time library for setting date & time
#include <DS1307RTC.h>      // RTC module library by Michael Margolis
#include <AccelStepper.h>   //https://www.airspayce.com/mikem/arduino/AccelStepper/ - improved lib for stepper motors
#include <elapsedMillis.h>  //https://github.com/pfeerick/elapsedMillis/wiki - handling events
#include "FS.h"             // ?
#include <SPI.h>            // standard arduino SPI library
#include "Config.h"
// #include "LCDDisplay.h"



AccelStepper Stepper_1(AccelStepper::FULL4WIRE, In1, In3, In2, In4); //motor for rotation
AccelStepper Stepper_2(AccelStepper::FULL4WIRE, In2_1, In2_3, In2_2, In2_4); //motor for bottom cover

void setup() {
  // pin setup
  pinMode(SM_Enable, OUTPUT);
  digitalWrite(SM_Enable, HIGH);

  // Use serial port
  Serial.begin(115200);
  Stepper_1.setMaxSpeed(1000);
  Stepper_2.setMaxSpeed(1000);
  Stepper_1.setSpeed(450);
  Stepper_2.setSpeed(450);

  LCDDisplay::initialize();
  LCDDisplay::drawKeypad();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(void) {
  Stepper_1.runSpeed(); // running motor 1
  Stepper_2.runSpeed(); // running motor 2

  LCDDisplay::guiLoop();
}
