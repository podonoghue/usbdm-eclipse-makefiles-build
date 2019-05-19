/**
 ============================================================================
 * @file   usbdcd-example.cpp (180.ARM_Peripherals/Snippets)
 * @date   12 Jul 2018
 * @author podonoghue
 * @brief  USBDCD Example code
 ============================================================================
 */

#include "hardware.h"
#include "usbdcd.h"

using namespace USBDM;

void callback() {
   UsbdcdStatus status = Usbdcd::getStatus();
   Usbdcd::clearInterrupt();
   if (status.timeout) {
      console.writeln("Timeout");
   }
   else if (status.error) {
      console.writeln("Error");
   }
   else {
      switch (status.usbdcdSeqStatus) {
         case UsbdcdSeqStatus_Idle:
            console.writeln("Idle");
            break;
         case UsbdcdSeqStatus_PinsDetected:
            console.writeln("PinsDetected");
            break;
         case UsbdcdSeqStatus_PortDetected:
            console.writeln("PortDetected");
            break;
         case UsbdcdSeqStatus_TypeDetected:
            console.writeln("TypeDetected");
            break;
      }
   }
}

int main() {
   console.writeln("Starting");

   Usbdcd::configure();
   Usbdcd::setCallback(callback);
   Usbdcd::enableInterrupt();
   Usbdcd::enableNvicInterrupts(NvicPriority_Normal);

   Usbdcd::startDetection();

   for(;;) {
      __asm__("nop");
   }
   return 0;
}

