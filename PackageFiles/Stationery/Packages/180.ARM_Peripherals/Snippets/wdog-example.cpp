/**
 ============================================================================
 * @file    wdog-example.cpp
 * @brief   Basic C++ demo using WDOG class
 *
 *  Created on: 5 Jul 2018
 *      Author: podonoghue
 ============================================================================
 */

#include "hardware.h"
#include "wdog.h"

using namespace USBDM;

using Led = GpioA<2, ActiveLow>;

/**
 * WDOG call-back.
 *
 * Executes when WDOG times-out before actual reset
 */
void callback() {
   Led::off();
   console.writeln("Watchdog Handler!!!");

   for(;;){
      // Wait here until reset
      __asm__("bkpt");
   }
}

int main(){
   console.writeln("\nPress enter to stop watchdog refresh and cause timeout");

   Led::setOutput(PinDriveStrength_High);

   // Unlock before changing settings
   Wdog::writeUnlock(WdogUnlock1, WdogUnlock2);

   // Configure
   Wdog::configure(
         WdogEnable_Enabled,
         WdogClock_Lpo,
         WdogWindow_Disabled,
         WdogInterrupt_Enabled,
         WdogAllowUpdate_Enabled,
         WdogEnableInDebug_Disabled,
         WdogEnableInStop_Disabled,
         WdogEnableInWait_Disabled);

   // Maximum time-out ~5s (LPO ~1kHz)
   Wdog::setPrescaler(1);
   Wdog::setTimeout(5000);

   // No window
   Wdog::setWindow(0);

   // Set up interrupt handling
   Wdog::setCallback(callback);
   Wdog::enableNvicInterrupts();
   Wdog::enableInterrupt();

   // Watch for key-press while servicing watchdog
   while (console.peek()<0) {
      // Flash LED
      Led::toggle();
      waitMS(200);

      // This is not a sensible way to service a watchdog!
      Wdog::writeRefresh(WdogRefresh1, WdogRefresh2);
   }

   console.write("Waiting for watchdog timeout");
   for(;;) {
      // Flash LED
      Led::toggle();
      waitMS(500);
      console.write('.');
	   // INTFLG doesn't set for some reason and the handler doesn't run.
      // console.write("INTFLG = ").writeln((WDOG->STCTRLL&WDOG_STCTRLL_INTFLG_MASK) != 0);
   }

   return 0;
}
