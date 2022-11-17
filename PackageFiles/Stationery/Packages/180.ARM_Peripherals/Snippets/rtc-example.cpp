/**
 ============================================================================
 * @file   rtc-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief  Real Time CLock (RTC) Example
 * @date   12 Jul 2018
 * Author podonoghue
 ============================================================================
 */
 /*
 * This example uses RTC interrupts.
 * Uses an LED for debug timing check.
 *
 * Note - Requires RTC interrupt handlers to be installed.
 ============================================================================
 */
#include <time.h>
#include "hardware.h"
#include "rtc.h"
#include "smc.h"

using namespace USBDM;

/**
 * Real Time Clock Example
 */
// LED connection - change as required
using Led = GpioA<2,ActiveLow>;

void reportTime(const char *msg, time_t rawtime) {
   char buffer[80];
   struct tm * timeinfo;
   timeinfo = localtime(&rawtime);
   strftime(buffer, sizeof(buffer), "%F %r : ", timeinfo);
   console.write(buffer).writeln(msg).flushOutput();
}

/**
 * Callback alarm handler from RTC Alarm
 *
 *  @param[in]  timeSinceEpoch - Alarm time as time since the epoch in seconds
 */
void alarmHandler(uint32_t timeSinceEpoch) {
   // Set repeat callback for 5 seconds from last alarm
   Rtc::setAlarmTime(timeSinceEpoch+5);
   reportTime("Alarm !!!!!!", timeSinceEpoch);
}

/**
 * Callback seconds handler from RTC Alarm
 *
 *  @param[in]  timeSinceEpoch - Time since the epoch in seconds
 */
void secondsHandler(uint32_t timeSinceEpoch) {
   Led::toggle();
   reportTime("Tick", timeSinceEpoch);
}

int main() {
   console.writeln("Starting").flushOutput();

   // Enable RTC - done by startup code
//   Rtc::initialise();

   // Set callbacks
   Rtc::setSecondsCallback(secondsHandler);
   Rtc::enableSecondsInterrupts();

   Rtc::setAlarmCallback(alarmHandler);
   Rtc::setAlarmTime(Rtc::getTime()+5);
   Rtc::enableAlarmInterrupts();
   Rtc::enableNvicInterrupts(NvicPriority_Normal);

   Smc::enableAllPowerModes();

   Led::setOutput();
   for(;;) {
      // Sleep between events
      Smc::enterPowerMode(SmcPowerMode_NormalSTOP);
      time_t rawtime;
      time (&rawtime);
      reportTime("Woke", rawtime);
   }
   return 0;
}
