/**
 ============================================================================
 * @file  pit-example3.cpp (180.ARM_Peripherals/Snippets/pit-example3-MK.cpp)
 * @brief Programmable Interrupt Timer (PIT) Example
 *
 * Programmable Interrupt Timer (PIT) Example
 *
 * Demonstrates PIT call-back
 *
 * @author   podonoghue
============================================================================
 */
#include "hardware.h"
#include "pit.h"
#include "smc.h"

using namespace USBDM;

/**
 * This example uses PIT interrupts.
 *
 * It is necessary to enable these in Configure.usbdmProject
 * under the "Peripheral Parameters"->PIT tab.
 * Select irqHandlingMethod option
 *
 * Assumes RGB Led has been pre-defined
 */

// Connection mapping - change as required
using Timer        = Pit;

int main() {

   static constexpr PcrInit ledSettings {
      PinDriveStrength_High,
      PinDriveMode_PushPull,
      PinSlewRate_Slow
   };
   RGB_Blue::setOutput(ledSettings);
   RGB_Green::setOutput(ledSettings);
   RGB_Red::setOutput(ledSettings);

   static constexpr Timer_100ms::ChannelInit pitSettings[] = {
      {
      PitChannelNum_0,
      PitChannelEnable_Enabled ,    // (pit_tctrl_ten]) Timer Channel Enable
      PitChannelAction_Interrupt ,  // (pit_tctrl_tie]) Action on timer event
      1_s ,                         // (pit_ldval_tsv]) Reload value
      NvicPriority_Normal,          // (irqLevel_Ch0)   IRQ priority level
      RGB_Blue::toggle,
      },
      {
      PitChannelNum_1,
      PitChannelEnable_Enabled ,    // (pit_tctrl_ten) Timer Channel Enable
      PitChannelAction_Interrupt ,  // (pit_tctrl_tie) Action on timer event
      2_s ,                         // (pit_ldval_tsv) Reload value
      NvicPriority_Normal,          // (irqLevel_Ch1)  IRQ priority level
      RGB_Red::toggle,
      },
      {
      PitChannelNum_2,
      PitChannelEnable_Enabled ,    // (pit_tctrl_ten) Timer Channel Enable
      PitChannelAction_Interrupt ,  // (pit_tctrl_tie) Action on timer event
      4_s ,                         // (pit_ldval_tsv) Reload value
      NvicPriority_Normal,          // (irqLevel_Ch1)  IRQ priority level
      RGB_Green::toggle,
      },
   };

   Timer::configure(pitSettings);

   for(;;) {
      // Sleep between events
      Smc::enterWaitMode();
   }
   return 0;
}
