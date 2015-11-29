#include <math.h>
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"
#include "I2C.h"
#include "MAG3310.h"
#include "delay.h"

using namespace USBDM;

/**
 * Demonstrates use of MAG3310 Magnetometer over I2C
 *
 * You may need to change the pin-mapping of the I2C interface
 */

#define M_PI      3.14159265358979323846

int main() {
   printf("Starting\n");

   // Instantiate interface
   I2C *i2c = new $(demo.cpp.magnetometer.i2c)();
   MAG3310 *magnetometer = new MAG3310(i2c);

   uint8_t id = magnetometer->readID();
   printf("Device ID = 0x%02X (should be 0xC4)\n", id);

   printf("Calibrating magnetometer\n"
          "Please rotate the board in all dimensions until complete (~20 s)\n");
   magnetometer->calibrateMagnetometer();

   for(;;) {
      waitMS(120);
      int magStatus;
      int16_t magX,magY,magZ;
      magnetometer->readMagnetometerXYZ(&magStatus, &magX, &magY, &magZ);
      printf("s=0x%02X, mX=%10d, mY=%10d, mZ=%10d, ", magStatus,   magX,   magY,   magZ);
      // Assumes the sensor is level
      printf("a=%d\n", (int)(180*atan2(magX, magY)/M_PI));
   }
}
