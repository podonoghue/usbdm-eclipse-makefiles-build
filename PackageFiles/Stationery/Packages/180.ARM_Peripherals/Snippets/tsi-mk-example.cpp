/*
 ============================================================================
 * @file    tsi-mk-example.cpp (180.ARM_Peripherals)
 * @brief   Basic C++ demo using TSI class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "delay.h"
#include "tsi.h"

using namespace USBDM;

// LED connection - change as required

using led1 = USBDM::gpio_LED_RED;
using led2 = USBDM::gpio_LED_BLUE;

int main() {

   printf("SystemBusClock  = %ld\n", USBDM::SystemBusClock);
   printf("SystemCoreClock = %ld\n", USBDM::SystemCoreClock);

   Tsi0::enable();

//   Tsi0::setCallback(tsiCallback);
//   Tsi0::enableErrorInterrupts();
//   Tsi0::enableTsiInterrupts();


   uint16_t ch11Min, ch11Max, ch11Threshold, ch12Min, ch12Max, ch12Threshold;
   led1::setOutput();
   led2::setOutput();

   // Wait for fist successful conversion
   while (Tsi0::startScanAndWait() != E_NO_ERROR) {
   }
   ch11Min = ch11Max = Tsi0::getCount(11);
   ch12Min = ch12Max = Tsi0::getCount(12);

   for(;;) {
      waitMS(100);
      if (Tsi0::startScanAndWait() != E_NO_ERROR) {
         printf("Res: Failed measurement\n");
      }
      else {
         uint16_t ch11 = Tsi0::getCount(11);
         uint16_t ch12 = Tsi0::getCount(12);
         if (ch11<ch11Min) {
            ch11Min = ch11;
         }
         if (ch11>ch11Max) {
            ch11Max = ch11;
         }
         if (ch12<ch12Min) {
            ch12Min = ch12;
         }
         if (ch12>ch12Max) {
            ch12Max = ch12;
         }
         ch11Threshold = (ch11Min+ch11Max)/2;
         ch12Threshold = (ch12Min+ch12Max)/2;
         led1::write((ch11<=ch11Threshold));
         led2::write((ch12<=ch11Threshold));
         printf("ch11=%s ch12=%s\n", (ch11>ch11Threshold)?"On ":"Off", (ch12>ch12Threshold)?"On ":"Off");
      }
   }
   return 0;
}
