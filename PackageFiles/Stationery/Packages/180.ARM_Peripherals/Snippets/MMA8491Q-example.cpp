#include <stdio.h>
#include <math.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"
#include "I2C.h"
#include "MMA8491Q.h"
#include "delay.h"

#define MMA8491Q_Enable digitalIO_D8

/**
 * Demonstrates use of MMA8491Q Accelerometer over I2C
 *
 * You may need to change the pin-mapping of the I2C interface
 */
void report(MMA8491Q *accelerometer) {
   int accelStatus;
   int16_t accelX,accelY,accelZ;

   MMA8491Q_Enable.set();
   waitMS(1000);
   accelerometer->readAccelerometerXYZ(&accelStatus, &accelX, &accelY, &accelZ);
   MMA8491Q_Enable.clear();
   printf("s=0x%02X, aX=%10d, aY=%10d, aZ=%10d\n", accelStatus, accelX, accelY, accelZ);
}

int main() {
   printf("Starting\n");

   // Instantiate interface
   I2C *i2c = new $(demo.cpp.accelerometer.i2c)();
   MMA8491Q *accelerometer = new MMA8491Q(i2c, &MMA8491Q_Enable);

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

