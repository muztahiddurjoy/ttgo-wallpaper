#include <TFT_eSPI.h>

#include "ali.h"
#include "arab.h"
#include "khabib.h"
#include "mercedes.h"
#include "nababi.h"

#define next_pin 35
#define prev_pin 0

TFT_eSPI tft = TFT_eSPI();
int active = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(prev_pin, INPUT_PULLUP);
  pinMode(next_pin, INPUT_PULLUP);
  
  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.setSwapBytes(true);
}

void loop() {
  int prev_state = digitalRead(prev_pin);
  int next_state = digitalRead(next_pin);

  handlePrevious(prev_state);
  handleNext(next_state);
  updateImage();
}

void updateImage() {
  switch (active) {
    case 0:
      tft.pushImage(0, 30, 128, 186, khabib);
      break;
    case 1:
      tft.pushImage(0, 30, 128, 198, ali);
      break;
    case 2:
      tft.pushImage(0, 30, 128, 181, arab);
      break;
    case 3:
      tft.pushImage(0, 20, 128, 226, mercedes);
      break;
  }
}

void handleNext(int state) {
  if (state == 0) {
    delay(500);
    tft.fillScreen(TFT_BLACK);
    if (active == 3) {
      active = 0;
    } else {
      active++;
    }
  }
}

void handlePrevious(int state) {
  if (state == 0) {
    delay(500);
    tft.fillScreen(TFT_BLACK);
    if (active == 0) {
      active = 3;
    } else {
      active--;
    }
  }
}
