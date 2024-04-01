/**
 ============================================================================
 * @file    cmp-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Basic C++ demo using Cmp class
 *
 * It will be necessary to configure the CMP inputs and output in the
 * USBDM configuration.
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */

#include "hardware.h"
#include "cmp.h"

using namespace USBDM;

// Connections - change as required
using Cmp              = Cmp0;

using CmpPositiveInput = Cmp0::Pin<Cmp0InputMinus_Ptc6>;   // Change as needed
using CmpNegativeInput = Cmp0::Pin<Cmp0InputMinus_CmpDac>; // Change as needed

// Led to control - change as required
using Led   = GpioA<2, ActiveLow>;

/**
 * Comparator callback
 *
 * @param[in]  status Struct indicating interrupt source and state
 */
void callback(const CmpStatus &status) {
   switch(status.event) {
      case CmpEventId_FallingEdge:
         // Falling edge
         console.write("Falling, State = ");
         break;
      case CmpEventId_RisingEdge:
         // Rising edge
         console.write("Rising,  State = ");
         break;
      case CmpEventId_BothEdges:
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

   // Configure comparator before use
   static constexpr Cmp::Init cmpInit {
      CmpPower_HighSpeed,
      CmpHysteresis_Level_2,
      CmpPolarity_Normal,
      Cmp::MAXIMUM_DAC_VALUE/2,
      CmpEvent_OnEither,
      CmpPositiveInput::plusPin,
      CmpNegativeInput::minusPin,
      callback,
   };
   Cmp::configure(cmpInit);

   // Connect CMP inputs to pins as needed
   CmpPositiveInput::setInput();
//   CmpNegativeInput::setInput(); // No actual pin for DacRef as internal connection

   // Connect CMP output to pin
   Cmp::setOutput(PinDriveStrength_High, PinDriveMode_PushPull);

   for(;;) {
      //      Led::toggle();
      USBDM::waitMS(100);
      //      console.writeln("Tick");
   }
   return 0;
}
