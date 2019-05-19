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

// LEDs to use
using RedLed   = GpioC<3, ActiveLow>;
using GreenLed = GpioD<4, ActiveLow>;

/**
 * Task to flash LED
 */
class Flasher : public TaskClass {

private:
   // Name of the task
   const char * const     name;

   // Blink delay
   const long  delayTime;

   void (*const toggler)(void);

public:
   /**
    * Constructor for Task
    *
    * @param name  Name of task
    *
    * Other task parameters are defaulted.
    */
   /**
    * Constructor for Flashing Task
    *
    * @param name       Name of task
    * @param delayTime  Flash On time
    * @param toggler    Method to toggle LED
    */
   Flasher(char const *name, long delayTime, void (*toggler)()) :
      TaskClass(name, TaskPrio_Low, configMINIMAL_STACK_SIZE), name(name), delayTime(delayTime), toggler(toggler) {
   }

   /**
    * Task function
    *
    * Sends messages in endless loop
    */
   void task() override {
      for(;;) {
         console.lock().write("Blink from ").writeln(name).unlock();
         toggler();
         delayMilliseconds(delayTime);
      }
   }
};

int main() {
   console.writeln("Starting");

   RedLed::setOutput(PinDriveStrength_High);

   GreenLed::setOutput(PinDriveStrength_High);

   static auto toggleRed = []() {
      RedLed::toggle();
   };
   static auto toggleGreen = []() {
      GreenLed::toggle();
   };

   // Create two threads
   new Flasher("Flasher 1", 100, toggleRed);
   new Flasher("Flasher 2", 200, toggleGreen);

   /*
    * Start the tasks running.
    */
   vTaskStartScheduler();

   /*
    * Shouldn't get here
    */
   console.writeln("Opps!!!!");
   for( ;; ) {
   }

}

