/**
 ============================================================================
 * @file     mma845x-example.cpp
 * @brief    Demonstrates use of MMA845x Accelerometer over I2C
 * @version  V4.11.1.80
 * @author   podonoghue
 *
 * You may need to change the pin-mapping of the I2C interface
============================================================================
 */
#include <stdio.h>
#include <math.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "i2c.h"
#include "mma845x.h"
#include "delay.h"

// Allows access to USBDM library name-space
using namespace USBDM;

/*************************************************
 * Global objects representing hardware
 **************************************************/

// I2C interface
I2c0     i2c0;

// Accelerometer via I2C
MMA845x  accelerometer(i2c0, MMA845x::ACCEL_2Gmode);

/**************************************************/

/**
 * Report accelerometer values
 *
 * @param[in] accelerometer Accelerometer to use
 */
void report(MMA845x &accelerometer) {
   int accelStatus;
   int16_t accelX,accelY,accelZ;

   accelerometer.readAccelerometerXYZ(accelStatus, accelX, accelY, accelZ);
   printf("s=0x%02X, aX=%10d, aY=%10d, aZ=%10d\n", accelStatus, accelX, accelY, accelZ);
}

int main() {
   printf("Starting\n");

   uint8_t id = accelerometer.readID();
   printf("Device ID = 0x%02X (should be 0x1A)\n", id);

   report(accelerometer);

   printf("Doing simple calibration\n"
          "Make sure the device is level!\n");
   waitMS(2000);

   if (!accelerometer.calibrateAccelerometer()) {
      printf("Calibration failed!\n");
      __asm__("bkpt");
   }

   // Make sure we have new values
   waitMS(100);

   printf("After calibration\n");
   for(;;) {
      report(accelerometer);
      waitMS(400);
   }
}

