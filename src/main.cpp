#include <MD_MAX72XX.h>
#include <MD_Parola.h>
#include <RTClib.h>
#include <SPI.h>
#include <Wire.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 10

MD_Parola matrix = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
RTC_DS3231 rtc;

void setup() {
  Wire.begin();
  rtc.begin();

  matrix.begin();
  matrix.setIntensity(1);
  matrix.displayClear();
  matrix.displayText("--:--", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);

  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

bool mShowSplit = true;
void loop() {
  DateTime now = rtc.now();

  char timeStr[6]; // "HH:MM"
  String timeFormat = mShowSplit ? "%02d:%02d" : "%02d %02d";
  snprintf(timeStr, sizeof(timeStr), timeFormat.c_str(), now.hour(),
           now.minute());

  matrix.displayClear();
  matrix.displayText(timeStr, PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
  matrix.displayAnimate();
  mShowSplit = !mShowSplit;

  delay(1000);
}