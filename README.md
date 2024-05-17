# Embedded-pill-dispenser
Repository for pill dispenser code

# Set-up 

1. Download Arduino IDE
2. Open the `PillDispenser_Full_HW\PillDispenser_Full_HW.ino` file with Arduino IDE
3. Then set-up Arduino IDE using the [folowing instruction](https://randomnerdtutorials.com/programming-raspberry-pi-pico-w-arduino-ide/)
4. Then install all the required libraries:
    - `AccelStepper` by mikem (Mike McCauley)
    - `ElapsedMillis` by Paul Stoffregen
    - `TFT_eSPI` by Bodmer
    - `DS1307RTC` and `Time` by Michael Margolis
5. Download the [sample demo](https://files.waveshare.com/upload/f/fc/Pico-ResTouch-LCD-X_X_Code.zip)
    - Unpack the compressed ZIP file and move 2 files from `Arduino/ResTouch-LCD-3.5` to proper directories:
        1. Go to folder where all Arduino libraries are installed and find TFT_eSPI library
        2. In main directory replace the `User_Setup_Select.h` with file from ZIP
        3. Replace `User_Setups/Setup60_RP2040_ILI9341.h` file with above mentioned ZIP file.
6. In Select Board choose Raspberry Pi Pico W

After all those steps it should compile properly



Additional info on LCD used by us is here: https://www.waveshare.com/pico-restouch-lcd-3.5.htm 