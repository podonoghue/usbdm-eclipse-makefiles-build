/*----------------------------------------------------------------------------
 * @file main.cpp
 *
 * Generated from main-RTX-CPP.cpp
 *
 * RTX example program
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include "cmsis.h"                      // CMSIS RTX
#include "hardware.h"                   // Hardware interface
#include "RTX_Conf_CM.cfg"

using RED_LED   = USBDM::$(demo.cpp.red.led:GpioB<3>);
using GREEN_LED = USBDM::$(demo.cpp.green.led:GpioB<4>);
using BLUE_LED  = USBDM::$(demo.cpp.blue.led:GpioB<5>);

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
   (void)i;
#if (OS_TIMERSTKSZ<(800/4))
#warning "Requires RTX Timer Thread stack size to be increased to about 800 bytes for printf()"
#else
   // Report the callback
   printf("Callback - %d\n\r", i++);
#endif
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

#if (OS_MAINSTKSIZE<(800/4))
#warning "Requires RTX Main Thread stack size to be increased to about 800 bytes for printf()"
#else
   // Report the IDs
   printf(" timer1::getId()   = %p\n\r", timer1.getId());
   printf(" timer2::getId()   = %p\n\r", timer2.getId());

   printf(" thread1::getId()  = %p\n\r", thread1.getId());
   printf(" thread2::getId()  = %p\n\r", thread2.getId());
#endif

}

int main() {
   timerExample();

   for(;;) {
      CMSIS::Thread::delay(osWaitForever);
   }
   return 0;
}

