/*
 ================================================================================
 * @file    ftm-ic-example.cpp
 * @brief   Demo using Ftm class to implement a basic Input Capture system
 *
 * An FTM input channel is used to measure the period of a waveform.
 * This example uses floating point calculations.
 *
 *  Created on: 3/7/2017
 *      Author: podonoghue
 ================================================================================
 */
#include "hardware.h"

using namespace USBDM;
/**
 * This example uses FTM interrupts.
 *
 * It is necessary to enable these in Configure.usbdmProject
 * under the "Peripheral Parameters"->FTM tab.
 * Select irqHandlingMethod option (Class Method - Software ...)
 */
// Timer being used - change as required
// Could also access as TimerChannel::Ftm
using Timer = Ftm0;

// Timer channel for measurement - change as required
using TimerChannel = Ftm0Channel<7>;

// Period between input edges in ticks
// This variable is shared with the interrupt routine
static volatile uint16_t periodInTicks = 0;

// Maximum measurement time
static const float MEASUREMENT_TIME = 100*ms;

using Debug = GpioA<12>;

/**
 * Interrupt handler for Timer interrupts
 * This calculates the time between events (rising edges)
 *
 * @param[in] status Flags indicating interrupt source channel(s)
 */
static void ftmCallback(uint8_t status) {
   static uint16_t lastEventTime;

   Debug::set();
   // Check channel
   if (status & TimerChannel::CHANNEL_MASK) {
      uint16_t currentEventTime = TimerChannel::getEventTime();
      periodInTicks = currentEventTime-lastEventTime;
      lastEventTime = currentEventTime;
   }
   Debug::clear();
}

int main() {
   console.writeln("Starting");

   Debug::setOutput(PinDriveStrength_High);

   /**
    * FTM channel set as Input Capture using a callback function
    */
   // Configure base FTM (affects all channels)
   Timer::configure(
         FtmMode_LeftAlign,      // Left-aligned is required for OC/IC
         FtmClockSource_System,  // Bus clock usually
         FtmPrescale_1);         // The prescaler will be re-calculated later

   // Set IC/OC measurement period to accommodate maximum measurement + 10%
   // This adjusts the prescaler value but does not change the clock source
   Timer::setMeasurementPeriod(1.1*MEASUREMENT_TIME);

   // Set callback function
   Timer::setChannelCallback(ftmCallback);

   // Enable interrupts for entire timer
   Timer::enableNvicInterrupts();

   // Configure pin associated with channel
   TimerChannel::setInput(
         PinPull_None,
         PinIrq_None,
         PinFilter_Passive);
   // or change individual attributes
   //  TimerChannel::setPullDevice(PinPull_Up);
   //  TimerChannel::setFilter(PinFilter_Passive);

   // Configure the channel in Input Capture mode
   TimerChannel::configure(
         FtmChMode_InputCaptureRisingEdge,
         FtmChannelIrq_Enable,
         FtmChannelDma_Disable);

   // Enable interrupts from the channel
   TimerChannel::enableInterrupts();

   // Check if configuration failed
   USBDM::checkError();

   for(;;) {
      uint16_t tPeriodInTicks;
      // Access shared data in protected fashion
      // Not necessary on Cortex-M4 as reading a simple variable like this is atomic.
      disableInterrupts();
      tPeriodInTicks = periodInTicks;
      enableInterrupts();
      int intervalInMilliseconds = (int)(1000*TimerChannel::convertTicksToSeconds(tPeriodInTicks));
      console.write("Period = ").write(intervalInMilliseconds).writeln(" ms");
   }
   return 0;
}

