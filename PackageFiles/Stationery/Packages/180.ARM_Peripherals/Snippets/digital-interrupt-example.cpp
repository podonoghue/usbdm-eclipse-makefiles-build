/*
 ============================================================================
 * @file    pin-interrupt-example.cpp (180.ARM_Peripherals/Sources/pin-interrupt-example.cpp)
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

// Connections - change as required
using Led      = USBDM::GpioA<2,USBDM::ActiveLow>;
using Switch   = USBDM::GpioC<0,USBDM::ActiveLow>;

// Call-back function to execute on interrupt
static void callBack(uint32_t status) {
   static int count = 0;
   console.write(count++).write(": Status = 0x").writeln(status, Radix_16);
}

int main() {
   Led::setOutput();

   // Install interrupt call-back
   Switch::setCallback(callBack);
   Switch::setInput(PinPull_Up, PinIrq_Falling, PinFilter_Passive);
   Switch::enableNvicInterrupts();

   for(;;) {
      Led::write(Switch::read());
   }
   return 0;
}
