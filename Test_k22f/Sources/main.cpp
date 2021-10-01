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
#include "crc.h"
#include "dac.h"
#include "dma.h"
#include "ewm.h"
#include "ftm.h"
#include "flash.h"
#include "i2c.h"
#include "i2s.h"
#include "llwu.h"
#include "lptmr.h"
#include "lpuart.h"
#include "mcm.h"
#include "pdb.h"
#include "pit.h"
#include "pmc.h"
#include "rcm.h"
#include "rnga.h"
#include "rtc.h"
#include "smc.h"
#include "spi.h"
#include "vref.h"
#include "wdog.h"

// Open namespace
using namespace USBDM;

// LED connections - change as required
const GpioD<5,ActiveLow> led;
const GpioAField<2,1,ActiveLow> leds;

extern void doStuff(const Gpio &led, const GpioField &leds);

int main() {
   console.writeln("Starting\n");
   console.write("SystemCoreClock = ").writeln(SystemCoreClock);
   console.write("SystemBusClock  = ").writeln(SystemBusClock);
   console.write("&led  = ").writeln(&led);
   console.write("&leds = ").writeln(&leds);

   Spi1 spi{};

   Vref vref{};
   vref.configure();
   vref.setOutput();

//   leds.port->DFCR = 0;
//   led.port->DFER = 0;

   // Must configure here
   led.setOutput();
   leds.setOutput();

   for(int count = 0;;count++) {
      doStuff(led, leds);
      waitMS(100);
      console.write(count).writeln(": Tick...");
   }
   return 0;
}
