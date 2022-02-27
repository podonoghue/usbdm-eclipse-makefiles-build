/**
 ============================================================================
 * @file cmsis-cpp-thread.cpp (180.ARM_Peripherals/Snippets)
 * @brief RTX Thread example program
 *
 *  Created on: 10/6/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"                   // Hardware interface
#include "cmsis.h"                      // CMSIS RTX

using namespace USBDM;
using namespace CMSIS;

using GREEN_LED   = GpioB<0>;

class MyThread : public ThreadClass {
private:
   const char     *fName;
   const unsigned  fDelayTime;
   unsigned count = 0;

   virtual void task() override {
            for(;;) {
               console
                  .lock()
                  .writeln("Hello from ", fName, ", ", count++)
                  .unlock();
               delay(fDelayTime);
            }
         }

public:
   MyThread(const char *name, unsigned delayTime) :
      ThreadClass(), fName(name), fDelayTime(delayTime) {
   }
};


int main() {
   MyThread thread1("Thread 1", 200);
   MyThread thread2("             Thread 2", 400);

   thread1.run();
   thread2.run();

   for(;;) {
      __asm("nop");
      console
         .lock()
         .writeln("This is the main thread running in a loop")
         .unlock();
      Thread::delay(100);
   }
   return 0;
}

