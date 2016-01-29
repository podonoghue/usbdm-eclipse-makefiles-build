/**
 * @file digital-example2.cpp
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "gpio.h"

using namespace USBDM;

/*
 * Simple Digital I/O example
 *
 * Echoes an external switch to an external LED
 * Uses arduino aliases if available
 *
 *  SWITCH + LED
 *  1 x Digital input
 *  1 x Digital output
 *
 */

// Connection mapping - change as required
using SWITCH =   $(demo.cpp.external.switch:USBDM::GpioB<0>);
using LED    =   $(demo.cpp.external.led:USBDM::GpioB<1>);

int main(void) {
   LED::setOutput();
   SWITCH::setInput();

   for(;;) {
      LED::write(!SWITCH::read());
   }
}
