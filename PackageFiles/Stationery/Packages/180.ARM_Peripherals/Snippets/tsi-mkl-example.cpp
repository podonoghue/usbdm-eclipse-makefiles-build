/*
 ============================================================================
 * @file    tsi-mkl-example.cpp (180.ARM_Peripherals)
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
using led2 = USBDM::gpio_LED_GREEN;

// Button connections
// Threshold value have to be determined experimentally for each button
using button1 = Tsi0Channel< 9, 1650>;
using button2 = Tsi0Channel<10, 1650>;

/**
 * This routine calculates usable thresholds for the two buttons
 * based upon the measured extreme values.
 *
 * It assumes the other TSI settings are reasonable for use.
 */
void calculateThresholds() {
   led1::setOutput();
   led2::setOutput();

   Tsi0::enable();

   uint16_t b1Min, b1Max, b1Threshold, b2Min, b2Max, b2Threshold;

   // Wait for fist successful conversion
   while (button1::startScanAndWait() != E_NO_ERROR) {
   }
   b1Min = b1Max = Tsi0::getCount();
   while (button2::startScanAndWait() != E_NO_ERROR) {
   }
   b2Min = b2Max = Tsi0::getCount();

   for(;;) {
      waitMS(100);
      uint16_t b1,b2;
      if (button1::startScanAndWait() != E_NO_ERROR) {
         printf("Ch9 Res: Failed measurement\n");
         continue;
      }
      else {
         b1 = button1::getCount();
         if (b1<b1Min) {
            b1Min = b1;
         }
         if (b1>b1Max) {
            b1Max = b1;
         }
         b1Threshold = (b1Min+b1Max)/2;
         led1::write((b1<=b1Threshold));
      }
      if (button2::startScanAndWait() != E_NO_ERROR) {
         printf("Ch10 Res: Failed measurement\n");
         continue;
      }
      else {
         b2 = button2::getCount();
         if (b2<b2Min) {
            b2Min = b2;
         }
         if (b2>b2Max) {
            b2Max = b2;
         }
         b2Threshold = (b2Min+b2Max)/2;
         led2::write((b2<=b1Threshold));
      }
      printf("b1=%d b2=%d\n", b1Threshold, b2Threshold);
//      printf("b1=%d b2=%d\n", b1, b2);
//      printf("b1=%s b2=%s\n", (b1>b1Threshold)?"On ":"Off", (b2>b2Threshold)?"On ":"Off");
   }
}

/**
 * Poll the touch are as two buttons
 * LEDs reflect the button values
 */
void pollButtons() {
   led1::setOutput();
   led2::setOutput();

   Tsi0::enable();

   for(;;) {
      bool b1Res = button1::poll();
      bool b2Res = button2::poll();

      led1::write(!b1Res);
      led2::write(!b2Res);

      printf("b1=%s b2=%s\n", b1Res?"On ":"Off", b2Res?"On ":"Off");
   }
}

int main() {

   printf("SystemBusClock  = %ld\n", USBDM::SystemBusClock);
   printf("SystemCoreClock = %ld\n", USBDM::SystemCoreClock);

//   calculateThresholds();
   pollButtons();
}
