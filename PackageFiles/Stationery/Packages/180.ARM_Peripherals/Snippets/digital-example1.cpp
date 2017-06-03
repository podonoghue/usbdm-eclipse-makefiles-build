/**
 ============================================================================
 * @file digital-example1.cpp
 * @brief Basic digital output example
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
 * Simple example flashing LEDs on digital outputs
 */

// Connection mapping - change as required
using RED_LED   = $(demo.cpp.red.led:USBDM::GpioB<0>);
using GREEN_LED = $(demo.cpp.green.led:USBDM::GpioB<1>);

int main() {
   RED_LED::setOutput();
   GREEN_LED::setOutput();
   RED_LED::set();
   GREEN_LED::set();
   for(;;) {
      RED_LED::toggle();
      USBDM::waitMS(100);
      RED_LED::toggle();
      USBDM::waitMS(100);
      GREEN_LED::toggle();
      USBDM::waitMS(100);
      GREEN_LED::toggle();
      USBDM::waitMS(100);
   }
}
