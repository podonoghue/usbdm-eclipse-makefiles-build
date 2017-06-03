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
#include <algorithm>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "delay.h"
#include "tsi.h"

using namespace USBDM;

// LED connection - change as required
using led1 = USBDM::gpio_LED_RED;
using led2 = USBDM::gpio_LED_BLUE;

// TSI channels to use
constexpr uint32_t channelA = 11;
constexpr uint32_t channelB = 12;

int main() {

   printf("SystemBusClock  = %ld\n", USBDM::SystemBusClock);
   printf("SystemCoreClock = %ld\n", USBDM::SystemCoreClock);

   Tsi0::enable();

//   Tsi0::setCallback(tsiCallback);
//   Tsi0::enableErrorInterrupts();
//   Tsi0::enableTsiInterrupts();

   uint16_t chAMin, chAMax, chAThreshold, chBMin, chBMax, chBThreshold;
   led1::setOutput();
   led2::setOutput();

   // Wait for fist successful conversion
   while (Tsi0::startScanAndWait() != E_NO_ERROR) {
   }
   // Start min/max at first measurement
   chAMin = chAMax = Tsi0::getCount(channelA);
   chBMin = chBMax = Tsi0::getCount(channelB);

   for(;;) {
      waitMS(100);
      if (Tsi0::startScanAndWait() != E_NO_ERROR) {
         printf("Res: Failed measurement\n");
      }
      else {
         // Read two active channels
         uint16_t chA = Tsi0::getCount(channelA);
         uint16_t chB = Tsi0::getCount(channelB);

         // Adjust min/max
         chAMin = std::min(chA, chAMin);
         chAMax = std::max(chA, chAMax);
         chBMin = std::min(chB, chBMin);
         chBMax = std::max(chB, chBMax);

         // Update thresholds
         chAThreshold = (chAMin+chAMax)/2;
         chBThreshold = (chBMin+chBMax)/2;

         // Values are compared to thresholds
         bool chAOn = chA>chAThreshold;
         bool chBOn = chB>chBThreshold;

         // Update LEDs
         led1::write(!chAOn);
         led2::write(!chBOn);

         // Report values
         printf("chA=%s chB=%s\n", (chAOn)?"On ":"Off", (chBOn)?"On ":"Off");
      }
   }
   return 0;
}
