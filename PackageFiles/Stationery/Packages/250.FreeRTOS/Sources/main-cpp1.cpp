/*
 * main.cpp
 *
 *  Created on: 1May,2017
 *      Author: podonoghue
 */

#include "FreeRTOS_CPP.h"
#include "hardware.h"

using namespace FREERTOS_CPP; // Open namespace for CMSIS wrapper functions
using namespace USBDM; // Open namespace for CMSIS wrapper functions

/**
 * Class representing the Thread
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
    * @param name       Name of the task
    * @param delayTime  How long to wait between messages
    * @param priority   Priority for the task
    * @param stackDepth How much stack space to allocate to the task
    */
   MyThread(
         char const          *name,
         long                 delayTime,
         TaskPriority         priority    =  TaskPrio_Idle,
         unsigned portSHORT   stackDepth  =  configMINIMAL_STACK_SIZE) :
            TaskClass(name, priority, stackDepth), name(name), delayTime(delayTime) {
   }

   void task() override {
      for(;;) {
         // Print message
         console
            .write("Hello from ")
            .write(name)
            .write(", ").
            writeln(count++);
         // Wait a while
         delay(delayTime);
      }
   }
};

// Create two static threads with default priority and stack sizes
static MyThread task1("Task 1", 1000);
static MyThread task2("Task 2", 1100);

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

