/**
 * @file pit-example3-MK.cpp
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "pit.h"

using namespace USBDM;

/**
 * Programmable Interrupt Timer (PIT) Example
 *
 * Demonstrates PIT call-back
 *
 * Toggles LED
 */

// Connection mapping - change as required
using Led = USBDM::GpioC<3, ActiveLow>;

/*
 * This callback is set programmatically
 */
void flashGreen(void) {
   Led::toggle();
}

int main() {
   Led::setOutput(PinDriveStrength_High);

   // Do default configure
   Pit::configure();

   // Set handler for channel 1 programmatically
   Pit::setCallback(1, flashGreen);

   // Flash LED @ 1Hz
   Pit::configureChannelInTicks(1, ::SystemBusClock);

   // Enable interrupts on the channel
   Pit::enableInterrupts(1);

   // Check for errors so far
   checkError();

   for(;;) {
      __asm__("nop");
   }
}
