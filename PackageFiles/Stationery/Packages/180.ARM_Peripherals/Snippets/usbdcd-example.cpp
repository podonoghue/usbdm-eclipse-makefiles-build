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

bool detectionComplete = false;

using RedLed   = GpioC<3, ActiveLow>;
using GreenLed = GpioD<4, ActiveLow>;
using BlueLed  = GpioA<2, ActiveLow>;

using VBusDetect = GpioB<0>;

/**
 * Call-back from USBDCD
 */
void usbdcdCallback() {
   UsbdcdStatus status = Usbdcd0::getStatus();
   Usbdcd0::clearInterrupt();

   if (status.usbdcdSeqStatus == UsbdcdSeqStatus_PinsDetected) {
      // Enable USB D+ PUP
      Usb0Info::usb().CONTROL |= USB_CONTROL_DPPULLUPNONOTG_MASK;
      RedLed::on();
   }
   else if (status.usbdcdSeqStatus == UsbdcdSeqStatus_PortDetected) {
      // Enable USB D+ PUP
      Usb0Info::usb().CONTROL |= USB_CONTROL_DPPULLUPNONOTG_MASK;
      GreenLed::on();
   }
   if (!status.active || status.error || status.timeout) {
      detectionComplete = true;
      Usbdcd0::enableInterrupt(false);
      BlueLed::on();
   }
}

/**
 * Report USBDCD status to console
 *
 * @param status Status value from USBDCD
 */
void report(UsbdcdStatus status) {
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
      switch (status.usbdcdSeqResult) {
         case UsbdcdSeqResult_Unknown:
            console.writeln(" - Unknown");
            break;
         case UsbdcdSeqResult_StandardHost:
            console.writeln(" - StandardHost");
            break;
         case UsbdcdSeqResult_DedicatedCharger:
            console.writeln(" - DedicatedCharger");
            break;
         case UsbdcdSeqResult_ChargingPort:
            console.writeln(" - ChargingPort");
            break;
      }
   }
}

/**
 * GPIO call-back used for VBus detection
 *
 * @param status Interrupt status from GPIO (PCR.ISFR)
 */
void vBusCallback(uint32_t status) {
   if (status & VBusDetect::MASK) {
      // Start detection after VBus detected
      Usbdcd0::configure();
      Usbdcd0::setCallback(usbdcdCallback);
      Usbdcd0::enableInterrupt();
      Usbdcd0::enableNvicInterrupts(NvicPriority_Normal);
      Usbdcd0::startDetection();
   }
}

int main() {
//   console.writeln("Starting");

   RedLed::setOutput(PinDriveStrength_High);
   GreenLed::setOutput(PinDriveStrength_High);
   BlueLed::setOutput(PinDriveStrength_High);

   // Set up VBus detection
   VBusDetect::setInput(PinPull_Down, PinAction_IrqRising, PinFilter_Passive);
   VBusDetect::setCallback(vBusCallback);
   VBusDetect::enableNvicInterrupts(NvicPriority_Normal);

   // Enable clock to USB0
   Usb0Info::enableClock();

   // Reset USB0
   Usb0Info::usb().USBTRC0 |= USB_USBTRC0_USBRESET_MASK;
   while(Usb0Info::usb().USBTRC0 & USB_USBTRC0_USBRESET_MASK) {
      __asm__("nop");
   }
   Usb0Info::usb().ISTAT = USB_ISTAT_USBRST_MASK;

   // Enable USB Reset Interrupt
   // This would usually be done as part of the USB configuration
   Usb0Info::usb().USBCTRL  = 0x00;
   Usb0Info::usb().USBTRC0 |= 0x40; // Magic Bit!!!
   Usb0Info::usb().CTL     |= USB_CTL_USBENSOFEN_MASK;

   while(!detectionComplete) {
      __asm__("nop");
   }
   report(Usbdcd0::getStatus());
   for(;;) {
      __asm__("nop");
   }
   return 0;
}

