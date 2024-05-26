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
      NvicPriority_Normal,
      callback,

      CmpEnable_Enabled ,                     // (cmp_cr1_en)               Comparator Enable - Comparator is enabled
      CmpMode_Direct ,                        // (cmp_cr1_mode)             Operating mode - Direct
      CmpPower_HighSpeed ,                    // (cmp_cr1_pmode)            Power Mode Select - High-Speed
      CmpOutput_Disabled ,                    // (cmp_cr1_output)           Comparator output pin source - Disabled
      CmpHysteresis_Level_2 ,                 // (cmp_cr0_hystctr)          Comparator hard block hysteresis control - Level 2
      CmpEvent_OnEither ,                     // (cmp_scr_interrupt)        Action on transition - Either edge
      CmpDacEnable_Enabled ,                  // (cmp_daccr_dacen)          DAC Enable - Enabled
      CmpDacrefSel_Vdd ,                      // (cmp_daccr_vrsel)          DAC Reference Voltage Select - Vin2 (Vdd)
      CmpDacLevel(Cmp::MAXIMUM_DAC_VALUE/2),  // (cmp_daccr_vosel)          DAC level

      CmpPositiveInput::plusPin,
      CmpNegativeInput::minusPin,
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
