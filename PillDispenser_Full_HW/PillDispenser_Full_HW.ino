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
#include <elapsedMillis.h>  //https://github.com/pfeerick/elapsedMillis/wiki - handling events
#include "FS.h"             // ?
#include <SPI.h>            // standard arduino SPI library
#include "Config.h"
#include "LCDDisplay.h"
#include "PillCylinder.h"



void setup() {
    // Use serial port
    Serial.begin(115200);

    LCDDisplay::initialize();
    LCDDisplay::drawKeypad();
    pinMode(LED_BUILTIN, OUTPUT);
}

void setup1() {
    // pin setup
    pinMode(SM_Enable, OUTPUT);
    digitalWrite(SM_Enable, HIGH);
    PillCylinder::initialize();
}

void loop(void) {
    LCDDisplay::guiLoop();
}

void loop1() {
    PillCylinder::cylinderLoop();
}
