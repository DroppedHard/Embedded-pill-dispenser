#include <TimeLib.h>        //standard Time library for setting date & time
#include <DS1307RTC.h>      // RTC module library by Michael Margolis
#include "FS.h"             // ?
#include <SPI.h>            // standard arduino SPI library
#include "Config.h"
#include "LCDDisplay.h"
#include "PillCylinder.h"

Interfaces::MoveCommunication communicator;


void setup() {
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    LCDDisplay::initialize();
    LCDDisplay::drawKeypad();
}

void setup1() {
    pinMode(SM_Enable, OUTPUT);
    digitalWrite(SM_Enable, HIGH);
    pinMode(PIN_CYLINDER_Home, INPUT);
    pinMode(PIN_BLOCKER_Home, INPUT);
    PillCylinder::initialize();
}

void loop() {
    LCDDisplay::guiLoop(&communicator);
}

void loop1() {
    PillCylinder::cylinderLoop(&communicator);
}
