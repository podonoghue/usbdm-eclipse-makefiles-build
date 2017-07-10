/*
 ================================================================================
 * @file    ftm-ic-example.cpp
 * @brief   Demo using Ftm class to implement a basic Input Capture system
 *
 * This example uses floating point calculations and required printf() %f support
 *
 *  Created on: 3/7/2017
 *      Author: podonoghue
 ================================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"

using namespace USBDM;

/**
 * This example requires use of floating point in printf().
 * If this option was not selected in the new project wizard then
 * it is necessary to change the library options.
 *
 * Right-click on project and open Properties
 *
 * Select [C/C++ Build->Settings] on left of [Tool Settings] tab
 * Select [ARM C++ Linker->General] in middle panel
 * Turn on [Support %f format in printf]
 *
 * It will be necessary to clean and re-build the project.
 */

// Timer channel for measurement - change as required
using Timer = $(demo.cpp.pwm.led1:Ftm0Channel<7>);

// Period between events
// This variable is shared with the interrupt routine
static volatile uint16_t periodInTicks = 0;

//using Debug = gpio_D0;

/**
 * Interrupt handler for Tone interrupts
 * This sets the next interrupt/pin toggle for a half-period from the last event
 *
 * @param[in] status Flags indicating interrupt source channel(s)
 */
static void ftmCallback(uint8_t status) {
   static volatile uint16_t lastEventTime;

//   Debug::set();
   // Check channel
   if (status & Timer::CHANNEL_MASK) {
      uint16_t currentEventTime = Timer::getEventTime();
      periodInTicks = currentEventTime-lastEventTime;
      lastEventTime = currentEventTime;
   }
//   Debug::clear();
}

/**
 * This example uses floating point calculations and required printf() %f support
 */
int main() {
   printf("Starting\n");
//   Debug::setOutput(PinDriveStrength_High);

   /**
    * FTM channel set as Input Capture using a callback function
    */
   // Pin filtering (if available)
   Timer::setFilter(PinFilter_Passive);

   // Set callback function
   Timer::setChannelCallback(ftmCallback);
   // Enable the channel (and owning FTM) in Input Capture mode
   Timer::enable(FtmInputCaptureRisingEdge);
   // Set IC/OC measurement period to accommodate at least 100ms (maximum period)
   Timer::setMeasurementPeriod(100*ms);
   // Enable interrupts from the channel
   Timer::enableChannelInterrupts();
   // Enable interrupts for entire timer
   Timer::enableNvicInterrupts();

   // Check if configuration failed
   USBDM::checkError();

   for(;;) {
      uint16_t tPeriodInTicks;
      // Access shared data in protected fashion
      // Not necessary on Cortex-M4 as reading a simple variable like this is atomic.
      disableInterrupts();
      tPeriodInTicks = periodInTicks;
      enableInterrupts();
      printf("Period = %6.1f ms\n", 1000*Timer::convertTicksToSeconds((float)tPeriodInTicks));
   }
   return 0;
}

