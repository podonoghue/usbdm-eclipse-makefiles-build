/*
 ============================================================================
 * @file    ftm-oc-example.cpp
 * @brief   Demo using Ftm class to implement a basic Output Compare system
 *
 *  Created on: 3/7/2017
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"

using namespace USBDM;

// Timer LED connection - change as required
/**
 * This example uses FTM interrupts.
 *
 * It is necessary enable these in Configure.usbdmProject under the "Peripheral Parameters"->FTM tab
 * Select irqHandlerInstalled option.
 */

// Timer channel being used - change as required
using Timer = $(demo.cpp.pwm.led1:Ftm0Channel<7>);

// Half-period for timer
static volatile uint16_t timerHalfPeriod;

/**
 * Interrupt handler for Timer interrupts
 * This sets the next interrupt/pin toggle for a half-period from the last event
 *
 * @param[in] status Flags indicating interrupt source channel(s)
 */
static void ftmCallback(uint8_t status) {

   // Check channel
   if (status & Timer::CHANNEL_MASK) {
      // Note: The pin is toggled directly by hardware
      // Re-trigger at last interrupt time + timerHalfPeriod
      Timer::setDeltaEventTime(timerHalfPeriod);
   }
}

int main() {
   printf("Starting\n");
   /**
    * FTM channel set as Output compare with pin Toggle mode and using a callback function
    */
   // Configure base FTM (affects all channels)
   Timer::Ftm::configure(FtmMode_LeftAlign);

   // Pin high-drive
   Timer::setDriveStrength(PinDriveStrength_High);

   // Set callback function
   Timer::setChannelCallback(ftmCallback);
   // Configure the channel in Output Compare mode with Pin toggle
   Timer::configure(FtmChMode_OutputCompareToggle);
   // Set IC/OC measurement period to accommodate at least 100ms (maximum period)
   Timer::setMeasurementPeriod(110*ms);

   // Calculate half-period in timer ticks
   // Must be done after timer clock configuration
   timerHalfPeriod = Timer::convertSecondsToTicks(100*ms);

   // Trigger 1st interrupt at now+100
   Timer::setRelativeEventTime(100);

   // Enable interrupts for entire timer
   Timer::enableNvicInterrupts();
   // Enable interrupts from the channel
   Timer::enableInterrupts();

   // Check if configuration failed
   USBDM::checkError();

   for(;;) {
   }
   return 0;
}

