/**
 ============================================================================
 * @file digital-example1.cpp
 * @brief Basic digital input/output example
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
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
using Switch =   $(demo.cpp.external.switch:USBDM::GpioB<0>);
using Led    =   $(demo.cpp.external.led:USBDM::GpioB<1>);

int main(void) {
   Led::setOutput(PinDriveStrengthHigh);
   Switch::setInput(PinPullUp);

   for(;;) {
      Led::write(!Switch::read());
   }
}
