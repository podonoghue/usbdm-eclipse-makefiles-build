/**
 ============================================================================
 * @file cmsis-cpp-thread.cpp
 * @brief RTX Thread example program
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "cmsis.h"                      // CMSIS RTX
#include "hardware.h"                   // Hardware interface

using namespace USBDM;

using GREEN_LED   = USBDM::$(demo.cpp.green.led:GpioB<0>);

/*
 * Thread example
 */
static void threadExample() {
   /** Thread function */
   static auto threadFn = [] (const void *) {
      for(;;) {
         GREEN_LED::toggle();
         osDelay(2000);
      }
   };
   /** Thread class */
   static CMSIS::Thread thread(threadFn);

   GREEN_LED::setOutput();

   /* Start thread */
   thread.run();

   console.write(" thread::getId() = ").write(thread.getId());
}

int main() {
   threadExample();

   for(;;) {
   }
   return 0;
}

