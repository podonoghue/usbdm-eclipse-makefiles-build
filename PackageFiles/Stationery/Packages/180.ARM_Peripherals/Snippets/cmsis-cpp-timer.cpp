/**
 ============================================================================
 * @file cmsis-cpp-timer.cpp
 * @brief RTX Timer example program
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "cmsis.h"                      // CMSIS RTX
#include "hardware.h"                   // Hardware interface

using RED_LED   = USBDM::$(demo.cpp.red.led:GpioB<0>);
using GREEN_LED = USBDM::$(demo.cpp.green.led:GpioB<1>);

/**
 * Timer example
 */
void timerExample() {
   // Callback to toggle first LED
   // This could also be a global function
   static auto cb1 = [] (const void *) {
      RED_LED::toggle();
   };
   // Callback to toggle second LED
   static auto cb2 = [] (const void *) {
      GREEN_LED::toggle();
   };

   // Set the LEDs as outputs
   GREEN_LED::setOutput();
   RED_LED::setOutput();

   // Create two timers
   static CMSIS::Timer myTimer1(cb1);
   static CMSIS::Timer myTimer2(cb2);

   // Start the timers
   myTimer1.start(1000);
   myTimer2.start(500);

   // Report the timer IDs
   printf(" myTimer1::getId() = %p\n\r", myTimer1.getId());
   printf(" myTimer2::getId() = %p\n\r", myTimer2.getId());
}

int main() {
   timerExample();

   for(;;) {
   }
   return 0;
}

