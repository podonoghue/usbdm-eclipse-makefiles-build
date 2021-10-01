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
#include "adc.h"
#include "cmp.h"
#include "dac.h"
#include "dma.h"
#include "flash.h"
#include "i2c.h"
#include "llwu.h"
#include "lptmr.h"
#include "pit.h"
#include "pmc.h"
#include "rcm.h"
#include "rtc.h"
#include "smc.h"
#include "spi.h"
#include "tpm.h"


// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

/**
 * See more examples in Snippets directory
 */

// LED connection - change as required
using Led   = GpioB<18,ActiveLow>;

int main() {
   console.writeln("Starting\n");
   console.write("SystemCoreClock = ").writeln(SystemCoreClock);
   console.write("SystemBusClock  = ").writeln(SystemBusClock);

   Led::setOutput();

   for(int count = 0;;count++) {
      Led::toggle();
      waitMS(100);
      console.write(count).writeln(": Tick...");
   }
   return 0;
}
