/**
 ==================================================================================
 * @file  cmsis-cpp-timer-mma845x.cpp
 * @brief Demonstrates use of CMSIS with MMA845x Accelerometer over I2C
 * @version  V4.11.1.90
 * @author   podonoghue
===================================================================================
 */
/*
 * You may need to change the pin-mapping of the I2C interface
 * You may need to increase the RTOS timer stack size to ~800 bytes for printf()
 */
#include <stdio.h>
#include <math.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "i2c.h"
#include "mma845x.h"
#include "delay.h"
#include "cmsis.h"
#include "RTX_Conf_CM.cfg"

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
 * This function is called from main and 2 timers
 *
 * @param accelerometer Accelerometer to use
 */
static void report(const char *name, MMA845x &accelerometer) {
   int accelStatus;
   int16_t accelX,accelY,accelZ;
   static CMSIS::Mutex mutex;

   // Take reading from accelerometer
   // I2C code is thread safe and MMA845x interface is stateless
   accelerometer.readAccelerometerXYZ(accelStatus, accelX, accelY, accelZ);

#if (OS_STKSIZE<(800/4))
#error "Requires RTX Default Thread stack size to be increased to about 800 bytes for printf()"
#endif
   mutex.lock();
   printf("%s: s=0x%02X, aX=%10d, aY=%10d, aZ=%10d\n", name, accelStatus, accelX, accelY, accelZ);
   mutex.unlock();
}

/**
 * Thread class incorporating timer function
 */
class MyTimer : public CMSIS::TimerClass {

private:
   // Name to use
   const char *fName;

   /**
    *  Function executed as timer
    */
   virtual void callback() override {
      report(fName, accelerometer);
   }

public:
   /**
    *  Constructor
    *
    *  @param Name for timer function to report
    */
   MyTimer(const char *name) : fName(name) {
   }

};

int main() {

#if (OS_MAINSTKSIZE<(800/4))
#error "Requires RTX Main Thread stack size to be increased to about 800 bytes for printf()"
#endif

   printf("Starting\n");

   uint8_t id = accelerometer.readID();
   printf("Device ID = 0x%02X (should be 0x1A)\n", id);

   printf("Doing simple calibration\n"
          "Make sure the device is level!\n");
   report("Startup", accelerometer);
   waitMS(400);
   report("Startup", accelerometer);
   waitMS(400);
   report("Startup", accelerometer);
   waitMS(400);

   accelerometer.calibrateAccelerometer();

   // Make sure we have new values
   waitMS(100);

   printf("After calibration\n");

#if 1
   /**
    * Method 1
    *
    * Create timers using static functions controlled by CMSIS::Timer class
    */
   // Convenient to declare timer function as lambda function wrapping report()
   static auto timerFn = [](const void *arg) {
      const char *name = (const char *)arg;
      report(name, accelerometer);
   };

   // Create timer instances
   CMSIS::Timer timer1(timerFn, (void*)("Th 1"), osTimerPeriodic);
   CMSIS::Timer timer2(timerFn, (void*)("Th 2"), osTimerPeriodic);

   // Start timers
   timer1.start(300);
   timer2.start(100);

#else
   /**
    * Method 2
    *
    * Use classes derived from CMSIS::TimerClass
    */
   // Create timer instances
   static MyTimer timer1("Th 1");
   static MyTimer timer2("Th 2");

   // Start timers
   timer1.start(300);
   timer2.start(100);
#endif

   for(;;) {
      report("main", accelerometer);
      CMSIS::Thread::delay(400);
   }
}

