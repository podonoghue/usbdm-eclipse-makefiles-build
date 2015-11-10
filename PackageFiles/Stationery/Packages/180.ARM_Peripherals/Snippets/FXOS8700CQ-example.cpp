#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"
#include "I2C.h"
#include "FXOS8700CQ.h"

/**
 * Demonstrates use of FXOS8700CQ Accelerometer and Magnetometer over I2C
 *
 * You may need to change the pin-mapping of the I2C interface
 */

int main() {
   printf("Starting\n");

   // Instantiate interface
   I2C *i2c = new $(demo.cpp.magnetometer.i2c)();
   FXOS8700CQ *accelerometer = new FXOS8700CQ(i2c, FXOS8700CQ::ACCEL_2Gmode);

   uint8_t id = accelerometer->readID();
   printf("Device ID = 0x%02X (should be 0x0D)\n", id);

   int status;
   int16_t accelX,accelY,accelZ;
   for(;;) {
      accelerometer->readAccelerometerXYZ(&status, &accelX, &accelY, &accelZ);
      printf("aX=%10d, aY=%10d, aZ=%10d\n", accelX, accelY, accelZ);
      accelerometer->readMagnetometerXYZ(&status, &accelX, &accelY, &accelZ);
      printf("mX=%10d, mY=%10d, mZ=%10d\n", accelX, accelY, accelZ);
   }
}
