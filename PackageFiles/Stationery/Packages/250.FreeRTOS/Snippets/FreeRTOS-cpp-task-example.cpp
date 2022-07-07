/*
 * main.cpp
 *
 *  Created on: 1May,2017
 *      Author: podonoghue
 */

#include "FreeRTOS_CPP.h"
#include "hardware.h"

using namespace FREERTOS_CPP; // Open namespace for FREERTOS wrapper functions
using namespace USBDM;        // Open namespace for USBDM wrapper functions

/**
 * Class representing the Threads
 */
class MyThread : public TaskClass {

private:
   // Name of the task
   const char * const name;
   // How long to wait between messages
   const long delayTime;
   // Iteration counter
   int   count = 0;

public:
   /**
    * Constructor
    * This creates the thread instance.
    * It also records some information about the task
    *
    * @param[in] name       Name of the task
    * @param[in] delayTime  How long to wait between messages in milliseconds
    *
    * @note  Default values for priority and stack size are used.
    */
   MyThread(
         char const          *name,
         long                 delayTime) :
            TaskClass(name, TaskPrio_Idle, 100), name(name), delayTime(delayTime) {
   }

   void task() override {
      for(;;) {
         // Print message
         console
            .lock()
            .write("Hello from ")
            .write(name)
            .write(", ")
            .writeln(count++)
            .unlock();

//         yield();
         // Wait a while
         delayMilliseconds(delayTime);
      }
   }
};

// Create two static threads
static MyThread task1("Task 1", 500);
static MyThread task2("          Task 2", 1500);

int main() {
   console.write("Starting\n\r");

   /*
    * Start the tasks running.
    */
   vTaskStartScheduler();

   /*
    * Shouldn't get here
    */
   console.write("Opps!!!!\n\r");
   for( ;; ) {
      __asm__("BKPT");
   }
}
