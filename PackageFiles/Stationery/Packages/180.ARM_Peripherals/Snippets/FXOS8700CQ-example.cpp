#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"
#include "I2C.h"
#include "FXOS8700CQ.h"
#include "delay.h"

#define M_PI      3.14159265358979323846

/**
 * Demonstrates use of FXOS8700CQ Accelerometer and Magnetometer over I2C
 *
 * You may need to change the pin-mapping of the I2C interface
 */

void report(FXOS8700CQ *accelerometer) {
   int accelStatus, magStatus;
   int16_t accelX,accelY,accelZ;
   int16_t magX,magY,magZ;

   accelerometer->readAccelerometerXYZ(&accelStatus, &accelX, &accelY, &accelZ);
   accelerometer->readMagnetometerXYZ(&magStatus, &magX, &magY, &magZ);
   printf("s=0x%02X, aX=%10d, aY=%10d, aZ=%10d, ", accelStatus, accelX, accelY, accelZ);
   printf("s=0x%02X, mX=%10d, mY=%10d, mZ=%10d, ", magStatus,   magX,   magY,   magZ);
   printf("a=%d\n", (int)(180*atan2(magX, magY)/M_PI));
   waitMS(400);
}

int main() {
   printf("Starting\n");

   // Instantiate interface
   I2C *i2c = new $(demo.cpp.magnetometer.i2c)();
   FXOS8700CQ *accelerometer = new FXOS8700CQ(i2c, FXOS8700CQ::ACCEL_2Gmode);

   uint8_t id = accelerometer->readID();
   printf("Device ID = 0x%02X (should be 0x0D)\n", id);

   printf("Before simple calibration (make sure the device is level!)\n");
   report(accelerometer);
   report(accelerometer);
   report(accelerometer);

   accelerometer->calibrateAccelerometer();
   // Make sure we have new values
   waitMS(100);

   printf("After calibration\n");
   for(;;) {
      report(accelerometer);
   }
}
