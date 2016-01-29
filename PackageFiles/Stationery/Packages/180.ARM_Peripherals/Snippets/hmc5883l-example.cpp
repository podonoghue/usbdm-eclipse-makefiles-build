/**
 * @file hmc5883l-example.cpp
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"
#include "i2c.h"
#include "hmc5883l.h"

using namespace USBDM;

/**
 * Demonstrates use of HMC5883L Compass over I2C
 *
 * You may need to change the pin-mapping of the I2C interface
 */

int main() {
   printf("Starting\n");

   // Instantiate interface
   I2c *i2c = new $(demo.cpp.external.i2c:I2c0)();

   HMC5883L *compass = new HMC5883L(i2c);

   compass->setGain(3);

   uint32_t id = compass->readID();
   printf("Compass ID = 0x%6lX (should be 0x483433)\n", id);

   for(;;) {
      int16_t compassX,compassY,compassZ;
      compass->doMeasurement(&compassX, &compassY, &compassZ);
      printf("X=%10d, Y=%10d, Z=%10d\n", compassX, compassY, compassZ);
   }
}
