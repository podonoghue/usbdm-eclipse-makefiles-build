/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main.cpp)
 * @brief   Basic C++ demo
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

/**
 * See more examples in Snippets directory
 */

// LED connection - change as required
using Led   = $(demo.cpp.led:GpioB<3>);

int main() {
   console.writeln("Starting\n");
   console.write("SystemBusClock  = ").writeln(::SystemBusClock);

   Led::setOutput();
   for(;;) {
      Led::toggle();
      USBDM::waitMS(100);
      console.writeln("Tick\n");
   }
   return 0;
}
