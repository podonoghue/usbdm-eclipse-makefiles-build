/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main.cpp)
 * @brief   Basic C++ demo using GPIO class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

/**
 * See more examples in Snippets directory
 */

// LED connection - change as required
using Led   = $(demo.cpp.led:GpioB<3>);

int main() {
//   printf("Starting\n");

//   printf("SystemBusClock  = %ld\n", ::SystemBusClock);
//   printf("SystemCoreClock = %ld\n", ::SystemCoreClock);

   Led::setOutput();
   for(;;) {
      Led::toggle();
      USBDM::waitMS(100);
//      printf("Tick\n");
   }
   return 0;
}
