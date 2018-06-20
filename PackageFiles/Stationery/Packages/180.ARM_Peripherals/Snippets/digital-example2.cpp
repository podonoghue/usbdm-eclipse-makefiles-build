/**
 ============================================================================
 * @file digital-example1.cpp
 * @brief Basic digital input/output example
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
 * Uses arduino aliases if available
 *
 *  Switch + LED
 *  1 x Digital input
 *  1 x Digital output
 *
 */

// Connection mapping - change as required
using Switch =   $(demo.cpp.external.switch:USBDM::GpioB<0,ActiveLow>);
using Led    =   $(demo.cpp.external.led:USBDM::GpioB<1,ActiveLow>);

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
