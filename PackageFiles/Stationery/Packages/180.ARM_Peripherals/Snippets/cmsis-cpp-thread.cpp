/*----------------------------------------------------------------------------
 * @file cmsis-cpp-thread.cpp
 *
 * RTX example program
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include "cmsis.h"                      // CMSIS RTX
#include "hardware.h"                   // Hardware interface

using GREEN_LED   = USBDM::$(demo.cpp.green.led:GpioB<0>);

/*
 * Thread example
 */
void threadExample() {
   static auto threadFn = [] (const void *) {
      for(;;) {
         GREEN_LED::toggle();
         osDelay(2000);
      }
   };
   static CMSIS::Thread thread(threadFn);

   GREEN_LED::setOutput();

   thread.run();
   printf(" thread::getId() = %p\n\r", thread.getId());
}

int main() {
   threadExample();

   for(;;) {
   }
   return 0;
}

