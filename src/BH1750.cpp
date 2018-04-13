#include "BH1750.h"

BH1750::BH1750(byte addr) {
  _addr = addr;
}

void BH1750::begin(uint8_t mode) {
  Wire.begin();
  write(mode);
}

void BH1750::send(uint8_t cmd) {
  Wire.beginTransmission(_addr);
  Wire.write(cmd);
  Wire.endTransmission();
}

bool BH1750::write(uint8_t cmd) {
  switch (cmd) {
    case BH1750_CONTINUOUS_HIGHRES:
    case BH1750_CONTINUOUS_HIGHRES2:
    case BH1750_ONETIME_HIGHRES:
    case BH1750_ONETIME_HIGHRES2:
      send(cmd);
      delay(120);
      return true;
      break;
    case BH1750_CONTINUOUS_LOWRES:
    case BH1750_ONETIME_LOWRES:
      send(cmd);
      delay(16);
      return true;
      break;
    case BH1750_POWER_DOWN:
    case BH1750_POWER_ON:
    case BH1750_RESET:
      send(cmd);
      return true;
      break;
    default:
      return false;
      break;
  }
}

float BH1750::read() {
  uint16_t level;
  float val;

  Wire.beginTransmission(_addr);
  Wire.requestFrom(_addr, 2);
  level = Wire.read();
  level <<= 8;
  level |= Wire.read();
  Wire.endTransmission();
    
  val = level / 1.2; // convert to lux
  return val;
}
