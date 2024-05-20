#include <TimeLib.h>        //standard Time library for setting date & time
#include <DS1307RTC.h>      // RTC module library by Michael Margolis
#include "FS.h"             // ?
#include <SPI.h>            // standard arduino SPI library
#include "Config.h"
#include "LCDDisplay.h"
#include "PillCylinder.h"


Interfaces::MoveCommunication communicator;

void setup() {
    // Serial.begin(115200);
    // pinMode(SM_Enable, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    // pinMode(PIN_CYLINDER_Home, INPUT_PULLUP);
    
    LCDDisplay::initialize();
    LCDDisplay::drawKeypad();
}

void setup1() {
    Serial.begin(115200);
    pinMode(SM_Enable, OUTPUT);
    pinMode(PIN_CYLINDER_Home, INPUT_PULLUP);
    pinMode(PIN_BLOCKER_Home, INPUT_PULLUP);
    digitalWrite(SM_Enable, LOW);
    PillCylinder::prepareCylinder(&communicator);
    PillCylinder::prepareBlocker(&communicator);
}

void loop() {
    LCDDisplay::guiLoop(&communicator);
}

void loop1() {
    PillCylinder::motorLoop(&communicator);
}
