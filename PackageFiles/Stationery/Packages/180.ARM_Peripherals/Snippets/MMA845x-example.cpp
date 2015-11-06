#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"
#include "I2C.h"
#include "MMA845x.h"

/**
 * Demonstrates use of MMA845x Accelerometer over I2C
 *
 * You may need to change the pin-mapping of the I2C interface
 */

int main() {
   // Instantiate interface
   I2C *i2c = new $(demo.cpp.accelerometer.i2c)();
   MMA845x *accelerometer = new MMA845x(i2c, MMA845x::MMA45x_2Gmode);
   uint8_t id = accelerometer->readID();
   printf("Accelerometer ID = 0x%02X (should be 0x1A)\n", id);
   int status;
   int16_t accelX,accelY,accelZ;
   for(;;) {
      accelerometer->readXYZ(&status, &accelX, &accelY, &accelZ);
      printf("X=%10d, Y=%10d, Z=%10d\n", accelX, accelY, accelZ);
   }
}
