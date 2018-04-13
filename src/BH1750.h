#ifndef BH1750_h
#define BH1750_h

#include "application.h"
#include <Wire.h>

// Default I2C Slave Address
#define BH1750_I2CADDR 0x23

// Power Down
#define BH1750_POWER_DOWN 0x00
// Power On
#define BH1750_POWER_ON 0x01
// Reset
#define BH1750_RESET 0x07

// Continuously High Resolution Mode: 1lx, 120ms
#define BH1750_CONTINUOUS_HIGHRES 0x10
// Continuously High Resolution Mode2: 0.5lx, 120ms
#define BH1750_CONTINUOUS_HIGHRES2 0x11
// Continuously Low Resolution Mode: 4lx, 16ms
#define BH1750_CONTINUOUS_LOWRES 0x13

// One Time High Resolution Mode: 1lx, 120ms
#define BH1750_ONETIME_HIGHRES 0x20
// One Time High Resolution Mode2: 0.5lx, 120ms
#define BH1750_ONETIME_HIGHRES2 0x21
// One Time Low Resolution Mode: 4lx, 16ms
#define BH1750_ONETIME_LOWRES 0x23

class BH1750 {
  public:
    BH1750(byte addr = BH1750_I2CADDR);
    void begin(uint8_t mode);
    bool write(uint8_t cmd);
    float read();
  private:
    byte _addr;
    void send(uint8_t cmd);
};

#endif
