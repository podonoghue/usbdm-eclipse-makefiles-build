/**
 ============================================================================
 * @file    cmp-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo using Cmp class
 *
 * It will be necessary to configure the CMP in the USBDM configuration
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */

#include "hardware.h"
#include "cmp.h"

using namespace USBDM;

// Connections - change as required
using Cmp    = Cmp0;
using CmpPin = Cmp::Pin<Cmp0Input_CmpIn2>;

// Led to control - change as required
using Led   = GpioA<2, ActiveLow>;

/**
 * Comparator callback
 *
 * @param[in]  status Struct indicating interrupt source and state
 */
void callback(CmpStatus status) {
   switch(status.event) {
      case CmpEvent_Falling:
         // Falling edge
         console.write("Falling, State = ");
         break;
      case CmpEvent_Rising:
         // Rising edge
         console.write("Rising,  State = ");
         break;
      case CmpEvent_Both:
         // Rising+Falling edges
         console.write("Both,    State = ");
         break;
      default:
         /* Do nothing */;
#ifdef DEBUG_BUILD
         /* Unexpected */
         __BKPT();
#endif
   }
   Led::write(status.state);
   console.writeln(status.state);
}

int main() {
   console.writeln("Starting");

   // LED initially off (active low)
   Led::setOutput();
   Led::off();

   // Enable comparator before use
   Cmp::configure();

   // Internal DAC used for one input - set level
   Cmp::setDacLevel(20);

   // Set callback to execute on event
   Cmp::setCallback(callback);

   // Connect CMP input to pin
   CmpPin::setInput();

   // Set Comparator inputs
   Cmp::selectInputs(CmpPin::pinNum, Cmp0Input_DacRef);

   // Connect CMP output to pin
   Cmp::setOutput(PinDriveStrength_High, PinDriveMode_PushPull);

   // Enable interrupts on Rising and Falling edges
   Cmp::enableInterrupts(CmpInterrupt_Both);
   Cmp::enableNvicInterrupts(NvicPriority_Normal);

   for(;;) {
      //      Led::toggle();
      USBDM::waitMS(100);
      //      console.writeln("Tick");
   }
   return 0;
}
