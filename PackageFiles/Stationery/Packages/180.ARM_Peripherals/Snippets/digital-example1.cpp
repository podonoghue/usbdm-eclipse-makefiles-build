/**
 ============================================================================
 * @file digital-example1.cpp (180.ARM_Peripherals/Snippets/)
 * @brief Basic C++ GPIO output example
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"

using namespace USBDM;

/*
 * Simple example flashing LEDs on digital outputs
 */

// Connection mapping - change as required
using RedLed   = $(demo.cpp.red.led:GpioB<0,ActiveLow>);
using GreenLed = $(demo.cpp.green.led:GpioB<1,ActiveLow>);

int main() {
   RedLed::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);
   GreenLed::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);
   for(;;) {
      RedLed::toggle();
      USBDM::waitMS(100);
      RedLed::toggle();
      USBDM::waitMS(100);
      GreenLed::toggle();
      USBDM::waitMS(100);
      GreenLed::toggle();
      USBDM::waitMS(100);
   }
}
