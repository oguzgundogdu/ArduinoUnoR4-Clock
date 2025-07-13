# Arduino Uno R4 Clock

This project demonstrates how to build a simple clock using the Arduino Uno R4. The clock displays the current time.

## Features
- Real-time clock functionality.
- Easy-to-read display.

## Requirements
- Arduino Uno R4.
- Real-Time Clock (RTC) module (e.g., DS3231).
- 8x8 or larger FC16_HW display.
- Breadboard and jumper wires.

## Installation
1. Clone this repository:
    ```bash
    git clone https://github.com/oguzgundogdu/ArduinoUnoR4-Clock
    ```
2. Open the `.ino` file in the Arduino IDE.
3. Install required libraries:
    - [RTClib](https://github.com/adafruit/RTClib) for RTC module.
    - [MD_MAX72XX](https://github.com/MajicDesigns/MD_MAX72XX) for 8x8 led screen integration.
    - [MD_Parola](https://github.com/MajicDesigns/MD_Parola) for 8x8 led screen high-level functions.
4. Upload the code to your Arduino Uno R4.

## Usage
- Power on the Arduino Uno R4.
- Use the buttons to set the current time.
- The display will show the updated time in real-time.
