/*
 ================================================================================
 * @file    ftm-oc-example3.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Demo using Ftm class to implement a basic Output Compare system
 *
 *  An FTM output generates a square wave with 100ms period
 *  This example uses FTM without interrupts - not really a recommended approach.
 *
 *  Created on: 3/7/2017
 *      Author: podonoghue
 ================================================================================
 */
#include "hardware.h"

using namespace USBDM;

/**
 * This example uses FTM without interrupts.
 */

// LED to flash
using Led = GpioA<2, ActiveLow>;

// Timer being used - change as required
// Could also access as TimerChannel::Ftm
using Timer = Ftm0;

// Timer channel being used - change as required
using TimerChannel = Ftm0Channel<7>;

// Half-period for timer (in ticks)
static volatile uint16_t timerHalfPeriod;

// Waveform period to generate
static const float WAVEFORM_PERIOD = 100*ms;

#define max(a,b) ((a>b)?a:b)

int main() {

   // Configure base FTM (affects all channels)
   Timer::configure(
         FtmMode_LeftAlign,      // Left-aligned is required for OC/IC
         FtmClockSource_System,  // Bus clock usually
         FtmPrescale_1);         // The prescaler will be re-calculated later

   // Set IC/OC measurement period to longest required interval + 10%
   // This adjusts the prescaler value but does not change the clock source
   Timer::setMeasurementPeriod(1.1*WAVEFORM_PERIOD/2);

   // Configure channel
   TimerChannel::configure(
         FtmChMode_OutputCompare, // O/C but no pin
         FtmChannelIrq_Disable);  // No interrupts

   // Check if configuration failed
   USBDM::checkError();

   // Calculate half-period in ticks
   timerHalfPeriod = Timer::convertSecondsToTicks(WAVEFORM_PERIOD/2);

   Led::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);

   TimerChannel::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);

   for (;;) {
      // Set event
      TimerChannel::setEventTime(timerHalfPeriod);

      while (!TimerChannel::getAndClearInterruptFlag()) {
         __asm__("nop");
      }
      Led::toggle();
   }
   return 0;
}

