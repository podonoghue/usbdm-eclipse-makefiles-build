/*----------------------------------------------------------------------------
 * @file main.cpp
 *
 * Generated from main-RTX-CPP.cpp
 *
 * RTX example program
 *----------------------------------------------------------------------------
 */
#include "hardware.h"                   // Hardware interface
#include "console.h"
#include "cmsis.h"                      // CMSIS RTX

using namespace USBDM;

using RED_LED   = GpioC<3>;
using GREEN_LED = GpioD<4>;
using BLUE_LED  = GpioA<2>;

// Thread to toggle first LED
static void threadLed1Toggle(const void *) {
   for(;;) {
      RED_LED::toggle();
      osDelay(1000);
   }
};

// Thread to toggle second LED
static void threadLed2Toggle(const void *) {
   for(;;) {
      GREEN_LED::toggle();
      osDelay(2000);
   }
};

// Callback to toggle third LED
static void callbackLed3Toggle(const void *) {
   BLUE_LED::toggle();
};

// Callback to print "Tick"
static void callbackTick(const void *) {
   static int i = 0;
   // Report the callback
   console.write("Callback - ").writeln(i++);
};

/**
 * Timer example
 */
static void timerExample() {

   // Set the LEDs as outputs
   GREEN_LED::setOutput();
   RED_LED::setOutput();
   BLUE_LED::setOutput();

   // Create two timers
   static CMSIS::Timer timer1(callbackLed3Toggle);
   static CMSIS::Timer timer2(callbackTick);

   // Create two threads
   static CMSIS::Thread thread1(threadLed1Toggle);
   static CMSIS::Thread thread2(threadLed2Toggle);

   // Start the 2 timers with different periods
   timer1.start(500);
   timer2.start(1000);

   // Start the two threads
   thread1.run();
   thread2.run();

   // Report the IDs
   console.write("timer1::getId()   = 0x").writeln(timer1.getId(), Radix_16);
   console.write("timer2::getId()   = 0x").writeln(timer2.getId(), Radix_16);

   console.write("thread1::getId()  = 0x").writeln(thread1.getId(), Radix_16);
   console.write("thread2::getId()  = 0x").writeln(thread2.getId(), Radix_16);
}

int main() {
   timerExample();

   for(;;) {
      CMSIS::Thread::delay(osWaitForever);
   }
   return 0;
}

