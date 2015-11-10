#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"
#include "I2C.h"
#include "HMC5883L.h"

/**
 * Demonstrates use of HMC5883L Compass over I2C
 *
 * You may need to change the pin-mapping of the I2C interface
 */

int main() {
   printf("Starting\n");

   // Instantiate interface
   I2C *i2c = new $(demo.cpp.magnetometer.i2c)();
   HMC5883L *compass = new HMC5883L(i2c);
   compass->setGain(1);

   uint32_t id = compass->readID();
   printf("Compass ID = 0x%6lX (should be 0x483433)\n", id);

   int16_t compassX,compassY,compassZ;
   for(;;) {
      compass->doMeasurement(&compassX, &compassY, &compassZ);
      printf("X=%10d, Y=%10d, Z=%10d\n", compassX, compassY, compassZ);
   }
}
