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
using Switch =   $(/HARDWARE/Switch1:GpioD<5,ActiveLow>);
using Led    =   $(/HARDWARE/Led1:GpioA<2,ActiveLow>);

#if 1
/**
 * PORT interrupt call back.
 * This callback is _shared_ by all port pins
 *
 * @param[in] status 32-bit value from ISFR (each bit indicates a possible pin interrupt source)
 */
static void callBack() {
   static int count = 0;

   if (Switch::getInterruptState()) {
      Switch::clearInterruptState();
      console.writeln(": Pin interrupt #", ++count);
   }
   else {
      console.writeln("Unexpected Pin interrupt");
   }
}
#else
/**
 * PORT interrupt call back.
 * This callback is _shared_ by all port pins
 *
 * Can explicitly instantiate the handler instead of using the trampoline
 */
template<>
void PcrBase::irqHandler<Switch::IRQ_INDEX>() {
   static int count = 0;

   if (Switch::getInterruptState()) {
      Switch::clearInterruptState();
      console.writeln(": Pin interrupt #", ++count);
   }
   else {
      console.writeln("Unexpected Pin interrupt");
   }
}
#endif

int main() {
   Led::setOutput();
   
   // Install interrupt call-back using trampoline
   Switch::setPinCallback(callBack);

   // PUP + IRQ on falling edge
   Switch::setInput(
         PinPull_Up,
         PinAction_IrqFalling,
         PinFilter_Passive);
   Switch::enableNvicPinInterrupts();

   for(;;) {
      Led::write(Switch::read());
   }
   return 0;
}
