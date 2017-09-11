/*
 ============================================================================
 * @file    ftm-oc-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Demo using Ftm class to implement a basic Output Compare system
 *
 *  An FTM output generates a square wave with 100ms period
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

// Timer channel for output - change as required
using TimerChannel = Ftm0Channel<7>;

// Half-period for timer in ticks
// This variable is shared with the interrupt routine
static volatile uint16_t timerHalfPeriod;

// Waveform period to generate
static const float WAVEFORM_PERIOD = 100*ms;

/**
 * Interrupt handler for Timer interrupts
 * This sets the next interrupt/pin toggle for a half-period from the last event
 *
 * @param[in] status Flags indicating interrupt source channel(s)
 */
static void ftmCallback(uint8_t status) {

   // Check channel
   if (status & TimerChannel::CHANNEL_MASK) {
      // Note: The pin is toggled directly by hardware
      // Re-trigger at last interrupt time + timerHalfPeriod
      TimerChannel::setDeltaEventTime(timerHalfPeriod);
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
   Timer::setMeasurementPeriod(1.1*WAVEFORM_PERIOD/2.0);

   // Calculate half-period in timer ticks
   // Must be done after timer clock configuration (above)
   timerHalfPeriod = Timer::convertSecondsToTicks(WAVEFORM_PERIOD/2.0);

   // Set callback function
   Timer::setChannelCallback(ftmCallback);

   // Enable interrupts for entire timer
   Timer::enableNvicInterrupts();

   // Configure pin associated with channel
   TimerChannel::setOutput(
         PinDriveStrength_High,
         PinDriveMode_PushPull,
         PinSlewRate_Slow);
   // or change individual attributes
   //  TimerChannel::setDriveStrength(PinDriveStrength_High);
   //  TimerChannel::setDriveMode(PinDriveMode_PushPull);

   // Trigger 1st interrupt at now+100
   TimerChannel::setRelativeEventTime(100);

   // Configure the channel
   TimerChannel::configure(
         FtmChMode_OutputCompareToggle, //  Output Compare with pin toggle
         FtmChannelIrq_Enable);         //  + interrupts on events

   // Check if configuration failed
   USBDM::checkError();

   for(;;) {
      __asm__("wfi");
   }
   return 0;
}

