#include "BH1750.h"

//initialize device
BH1750 bh1750;

float brightness = 0.0;

void setup() {
  Serial.begin(9600);
  //configure as continuous high resolution mode
  bh1750.begin(BH1750_CONTINUOUS_HIGHRES);
}

void loop() {
  //read data
  brightness = bh1750.read();

  Serial.print(brightness);
  Serial.println(" lux");
  delay(1000);
}
