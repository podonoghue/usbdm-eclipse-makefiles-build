/*
 ============================================================================
 * @file    rtc-example.cpp
 * @brief   Basic C++ demo using USBDM::Rtc class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include <ctime>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "delay.h"
#include "rtc.h"

/**
 * Real Time Clock Example
 */
// LED connection - change as required
using Led = $(demo.cpp.led:USBDM::GpioA<2,USBDM::ActiveLow>);

/**
 * Callback handler from RTC Alarm
 */
void handler(uint32_t timeSinceEpoch) {
   // Set repeat callback for 5 seconds from now
   USBDM::Rtc::setAlarm(timeSinceEpoch+4);
   Led::toggle();
}

int main() {
   printf("Starting\n");

   printf("SystemBusClock  = %lu\n", SystemBusClock);
   printf("SystemCoreClock = %lu\n", SystemCoreClock);

   // Enable RTC - done by startup code
//   USBDM::Rtc::initialise();

   // Set initial callback
   USBDM::Rtc::setCallback(handler);
   USBDM::Rtc::setAlarm(USBDM::Rtc::getTime()+5);
   USBDM::Rtc::enableAlarmInterrupts();

   Led::setOutput();
   for(;;) {
      time_t rawtime;
      struct tm * timeinfo;
      char buffer[80];

      time (&rawtime);
      timeinfo = localtime(&rawtime);
      strftime(buffer, sizeof(buffer), "%d-%m-%Y %I:%M:%S\n", timeinfo);
      printf(buffer);
      __WFE();
   }
   return 0;
}
