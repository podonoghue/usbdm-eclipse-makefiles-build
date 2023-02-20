/**
 ============================================================================
 * @file    ftm-oc-init-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Demo using Ftm class to implement a basic Output Compare system
 *
 *  This example assumes two FTMs
 *  - FtmShared with channel FtmSharedChannel
 *    This FTM configuration should have Interrupts supported + Shared call-back
 *  - FtmIndividual with channel FtmIndividualChannel
 *    This FTM configuration should have Interrupts supported + Individual call-backs
 *
 *  The configuration uses const initialisation structures in Flash.
 *
 *  Created on: 10/2/2023
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "mcg.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

/**
 * See more examples in Snippets directory
 */

// LED connection - change as required
using Led   = RGB_Red;

void timerChannelCallback(uint8_t) {
   __asm__("nop");
}

void timerCallback() {
   __asm__("nop");
}

static const FtmShared::Init ftmSharedInit {
   FtmMode_LeftAligned ,         // Alignment and whether interval or free-running mode - LeftAligned
   FtmOverflowAction_Interrupt , // Action on Counter overflow - Interrupt
   NvicPriority_Normal ,         // IRQ level for this peripheral - Normal
   FtmClockSource_SystemClock ,  // Clock Source - System clock
   FtmPrescale_DivBy1 ,          // Clock prescaler - Divide by 1
   0_ticks ,                     // Start value for counter
   40000_ticks,                  // End value for counter

   timerCallback,                // Overflow call-back
   timerChannelCallback,         // Shared channel call-back
};

static const FtmShared::ChannelInit ftmSharedChannelInit {
   FtmSharedChannel::CHANNEL,

   FtmChannelMode_OutputCompareToggle , // Channel Mode - OC Toggle
   FtmChannelAction_Interrupt ,         // Action on Channel Event - Interrupt
   10000_ticks,                         // Output Compare Event time in ticks
};

static const FtmIndividual::Init ftmIndividualInit {
   FtmMode_LeftAligned ,         // Alignment and whether interval or free-running mode - Left aligned
   FtmOverflowAction_Interrupt , // Action on Counter overflow - Interrupt
   NvicPriority_Normal ,         // IRQ level for this peripheral - Normal
   FtmClockSource_SystemClock ,  // Clock Source - System clock
   FtmPrescale_DivBy1 ,          // Clock prescaler - Divide by 1
   0_ticks ,                     // Start value for counter
   40000_ticks,                  // End value for counter

   timerCallback,                // Overflow call-back
};

static const FtmIndividualChannel::ChannelInit ftmIndividualChannelInit {
   FtmIndividualChannel::CHANNEL,

   FtmChannelMode_OutputCompareToggle , // Channel Mode - Disabled
   FtmChannelAction_Interrupt ,         // Action on Channel Event - No action
   20000_ticks,                         // Output Compare Event time in ticks

   timerChannelCallback,                // Individual channel call-back
};

int main() {
   console.writeln("\nStarting");

   FtmShared::configure(ftmSharedInit);
   FtmSharedChannel::configure(ftmSharedChannelInit);

   FtmIndividual::configure(ftmIndividualInit);
   FtmIndividualChannel::configure(ftmIndividualChannelInit);

   for(int count = 0;;count++) {
      Led::toggle();
      waitMS(100);
      console.writeln(count, ": Tick...");
   }
   return 0;
}
