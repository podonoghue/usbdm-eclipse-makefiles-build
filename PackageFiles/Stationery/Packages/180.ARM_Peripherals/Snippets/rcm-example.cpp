/**
 ============================================================================
 * @file   rcm-example.cpp (180.ARM_Peripherals/Snippets)
 * @date   12 Jul 2018
 * @author podonoghue
 * @brief  USBDCD Example code
 ============================================================================
 */

#include "hardware.h"
#include "rcm.h"

using namespace USBDM;

int main() {
   console.writeln("Starting");

   console.write("Reset source = ").write(Rcm::getResetSource(), Radix_16).write(" = ").writeln(Rcm::getResetSourceDescription());

   Rcm::configure(
         RcmResetPinRunWaitFilter_BusCLock,
         RcmResetPinStopFilter_LowPowerOscillator,
         20);

   for(;;) {
      __asm__("nop");
   }
   return 0;
}

