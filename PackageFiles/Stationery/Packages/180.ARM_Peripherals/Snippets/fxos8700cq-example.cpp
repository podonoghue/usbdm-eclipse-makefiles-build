/**
 * @file fxos8700cq-example.cpp
 */
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "i2c.h"
#include "fxos8700cq.h"
#include "delay.h"

using namespace USBDM;

constexpr double M_PI = 3.14159265358979323846;

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
}

int main() {
   printf("Starting\n");

   // Instantiate interface
   I2c *i2c = new $(demo.cpp.fx0s8700cq.i2c:I2c0)();
   FXOS8700CQ *accelmag = new FXOS8700CQ(i2c, FXOS8700CQ::ACCEL_2Gmode);

   uint8_t id = accelmag->readID();
   printf("Device ID = 0x%02X (should be 0xC7)\n", id);

   // Enable both Accelerometer and magnetometer
   accelmag->enable(FXOS8700CQ::ACCEL_MAG);

   printf("Before simple calibration (make sure the device is level!)\n");
   report(accelmag);
   report(accelmag);
   report(accelmag);

   accelmag->calibrateAccelerometer();
   // Make sure we have new values
   waitMS(100);

   printf("After calibration\n");
   report(accelmag);

   printf("Calibrating magnetometer\nPlease rotate the board in all dimensions until complete\n");
   for (int time=5; time>0; time--) {
      printf("Calibrating for %2d seconds\n", time);
      accelmag->calibrateMagnetometer(1);
   }

   for(;;) {
      report(accelmag);
      waitMS(400);
   }





}
