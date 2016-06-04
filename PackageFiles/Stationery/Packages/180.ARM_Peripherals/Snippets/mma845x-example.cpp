/**
 * @file mma845x-example.cpp
 */
#include <stdio.h>
#include <math.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "i2c.h"
#include "mma845x.h"
#include "delay.h"

using namespace USBDM;

/**
 * Demonstrates use of MMA845x Accelerometer over I2C
 *
 * You may need to change the pin-mapping of the I2C interface
 */
void report(MMA845x *accelerometer) {
   int accelStatus;
   int16_t accelX,accelY,accelZ;

   accelerometer->readAccelerometerXYZ(&accelStatus, &accelX, &accelY, &accelZ);
   printf("s=0x%02X, aX=%10d, aY=%10d, aZ=%10d\n", accelStatus, accelX, accelY, accelZ);
}

int main() {
   printf("Starting\n");

   // Instantiate interface
   I2c *i2c = new $(demo.cpp.mma845x.i2c:I2c0)();
   MMA845x *accelerometer = new MMA845x(i2c, MMA845x::ACCEL_2Gmode);

   uint8_t id = accelerometer->readID();
   printf("Device ID = 0x%02X (should be 0x1A)\n", id);

   printf("Before simple calibration (make sure the device is level!)\n");
   report(accelerometer);
   waitMS(400);
   report(accelerometer);
   waitMS(400);
   report(accelerometer);
   waitMS(400);

   accelerometer->calibrateAccelerometer();

   // Make sure we have new values
   waitMS(100);

   printf("After calibration\n");
   for(;;) {
      report(accelerometer);
      waitMS(400);
   }
}

