/**
 ============================================================================
 * @file digital-example2.cpp (180.ARM_Peripherals/Snippets/)
 * @brief Basic C++ GPIO input/output example
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"

using namespace USBDM;

/*
 * Simple Digital I/O example
 *
 * Echoes an external switch to an external LED
 *
 *  Switch + LED
 *  1 x Digital input
 *  1 x Digital output
 *
 */
 
// Connection mapping - change as required
using Switch =   $(/HARDWARE/Switch1:GpioD<5,ActiveLow>);
using Led    =   $(/HARDWARE/Led1:GpioA<2,ActiveLow>);

int main(void) {
   Led::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);
   Switch::setInput(
         PinPull_Up,
         PinAction_None,
         PinFilter_Passive);

   for(;;) {
      Led::write(!Switch::read());
   }
}
