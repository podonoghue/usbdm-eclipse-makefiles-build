/**
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main-mcg.cpp)
 * @brief   Basic C++ demo
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "mcg.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

/**
 * See more examples in Snippets directory
 */

// LED connection - change as required
using Led   = $(/HARDWARE/Led1:GpioB<3,ActiveLow>);

int main() {
   console.writeln("\nStarting");
   console.writeln("Clock mode      = ", Mcg::getClockModeName());
   console.writeln("SystemCoreClock = ", SystemCoreClock, " Hz");
   console.writeln("SystemBusClock  = ", SystemBusClock, " Hz");

   Led::setOutput();

   for(int count = 0;;count++) {
      Led::toggle();
      waitMS(100);
      console.writeln(count, ": Tick...");
   }
   return 0;
}
