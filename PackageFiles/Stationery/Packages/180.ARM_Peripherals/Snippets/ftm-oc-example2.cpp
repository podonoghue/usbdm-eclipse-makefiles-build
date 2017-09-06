/*
 ============================================================================
 * @file    ftm-oc-example.cpp
 * @brief   Demo using Ftm class to implement a basic Output Compare system
 *
 *  An FTM output generates a rectangular waveform with 50ms low /100ms high
 *
 *  Created on: 3/7/2017
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"

using namespace USBDM;

/**
 * This example uses FTM interrupts.
 *
 * It is necessary enable these in Configure.usbdmProject under the "Peripheral Parameters"->FTM tab
 * Select irqHandlingMethod option (Class Method - Software ...)
 */

// Timer being used - change as required
// Could also access as TimerChannel::Ftm
using Timer = Ftm0;

// Timer channel being used - change as required
using TimerChannel = Ftm0Channel<7>;

// Waveform for timer (in ticks)
static volatile uint16_t waveformHighTime;
static volatile uint16_t waveformLowTime;

// Waveform to generate
static const float WAVEFORM_HIGH_TIME = 100*ms;
static const float WAVEFORM_LOW_TIME  = 50*ms;

#define max(a,b) ((a>b)?a:b)

/**
 * Interrupt handler for Timer interrupts
 * This sets the next interrupt/pin toggle for a half-period from the last event
 *
 * @param[in] status Flags indicating interrupt source channel(s)
 */
static void ftmCallback(uint8_t status) {
static bool odd = true;

   // Check channel
   if (status & TimerChannel::CHANNEL_MASK) {
      // Note: The pin is toggled directly by hardware
      if (odd) {
         // Configure the channel in Output Compare mode with Pin clear
//         TimerChannel::setMode(FtmChMode_OutputCompareClear);
         TimerChannel::configure(FtmChMode_OutputCompareClear, FtmChannelIrq_Enable);
         // Re-trigger at last interrupt time + waveformHighTime
         // Note - must do this after configuring channel
         TimerChannel::setDeltaEventTime(waveformHighTime);
      }
      else {
         // Configure the channel in Output Compare mode with Pin set
//         TimerChannel::setMode(FtmChMode_OutputCompareSet);
         TimerChannel::configure(FtmChMode_OutputCompareSet, FtmChannelIrq_Enable);
         // Re-trigger at last interrupt time + waveformLowTime
         // Note - must do this after configuring channel
         TimerChannel::setDeltaEventTime(waveformLowTime);
      }
	  // Alternate odd-even
      odd = !odd; 
   }
}

int main() {

   /**
    * FTM channel set as Output compare with pin Toggle mode and using a callback function
    */
   // Configure base FTM (affects all channels)
   Timer::configure(
         FtmMode_LeftAlign,      // Left-aligned is required for OC/IC
         FtmClockSource_System,  // Bus clock usually
         FtmPrescale_1);         // The prescaler will be re-calculated later

   // Set IC/OC measurement period to accommodate maximum period + 10%
   // This adjusts the prescaler value but does not change the clock source
   Timer::setMeasurementPeriod(1.1*max(WAVEFORM_HIGH_TIME, WAVEFORM_LOW_TIME));

   // Calculate half-period in timer ticks
   // Must be done after timer clock configuration (above)
   waveformHighTime = Timer::convertSecondsToTicks(WAVEFORM_HIGH_TIME);
   waveformLowTime  = Timer::convertSecondsToTicks(WAVEFORM_LOW_TIME);

   // Set callback function
   Timer::setChannelCallback(ftmCallback);

   // Enable interrupts for entire timer
   Timer::enableNvicInterrupts();

   // Configure pin associated with channel
   TimerChannel::setDriveStrength(PinDriveStrength_High);
   TimerChannel::setDriveMode(PinDriveMode_PushPull);

   // Trigger 1st interrupt at now+100
   TimerChannel::setRelativeEventTime(100);

   // Configure the channel
   TimerChannel::configure(
         FtmChMode_OutputCompareSet, //  Output Compare with pin set
         FtmChannelIrq_Enable);      //  + interrupts on events

   // Check if configuration failed
   USBDM::checkError();

   for(;;) {
      __asm__("wfi");
   }
   return 0;
}

