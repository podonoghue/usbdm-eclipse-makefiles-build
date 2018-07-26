/**
 ============================================================================
 * @file   rtc-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief  Real Time CLock (RTC) Example
 * @date   12 Jul 2018
 * @author podonoghue
 ============================================================================
 */
 /*
 * This example uses RTC interrupts.
 * Uses an LED for debug timing check.
 *
 * Note - Requires RTC interrupt handlers to be installed.
 ============================================================================
 */
#include <ctime>
#include "hardware.h"
#include "rtc.h"

using namespace USBDM;

/**
 * Real Time Clock Example
 */
// LED connection - change as required
using Led = GpioA<2,ActiveLow>;

/**
 * Callback handler from RTC Alarm
 */
void handler(uint32_t timeSinceEpoch) {
   // Set repeat callback for 5 seconds from now
   Rtc::setAlarmTime(timeSinceEpoch+4);
   Led::toggle();
}

int main() {
   console.writeln("Starting");

   // Enable RTC - done by startup code
//   Rtc::initialise();

   // Set initial callback
   Rtc::setAlarmCallback(handler);
   Rtc::setAlarmTime(Rtc::getTime()+5);
   Rtc::enableAlarmInterrupts();
   Rtc::enableNvicInterrupts();

   Led::setOutput();
   for(;;) {
      time_t rawtime;
      struct tm * timeinfo;
      char buffer[80];

      time (&rawtime);
      timeinfo = localtime(&rawtime);
      strftime(buffer, sizeof(buffer), "%d-%m-%Y %I:%M:%S", timeinfo);
      console.writeln(buffer);
      __WFE();
   }
   return 0;
}
