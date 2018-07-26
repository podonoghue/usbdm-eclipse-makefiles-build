/**
 ============================================================================
 * @file    digital-interrupt-example.cpp (180.ARM_Peripherals/Snippets/)
 * @brief   Basic C++ demo of GPIO interrupts.
 *
 *  Created on: 26/7/2017
 *      Author: podonoghue
 ============================================================================
 */
/**
 * This example uses GPIO interrupts.
 *
 * It is necessary to enable these in Configure.usbdmProject
 * under the "Peripheral Parameters"->GPIOx tab.
 * Select irqHandlers option (Class Method - Software ...)
 */
#include "hardware.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

// Connections - change as required
using Led      = USBDM::GpioA<2,USBDM::ActiveLow>;
using Switch   = USBDM::GpioC<0,USBDM::ActiveLow>;

// Call-back function to execute on interrupt
/**
 * PORT interrupt call back.
 * This callback is _shared_ by all port pins
 *
 * @param[in] status 32-bit value from ISFR (each bit indicates a possible pin interrupt source)
 */
static void callBack(uint32_t status) {
   static int count = 0;
   console.write(count++).write(": Status = 0x").writeln(status, Radix_16);
}

int main() {
   Led::setOutput();

   // Install interrupt call-back
   Switch::setCallback(callBack);
   Switch::setInput(PinPull_Up, PinAction_IrqFalling, PinFilter_Passive);
   Switch::enableNvicInterrupts();

   for(;;) {
      Led::write(Switch::read());
   }
   return 0;
}
