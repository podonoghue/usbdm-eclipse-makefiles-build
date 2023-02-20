/**
 ============================================================================
 * @file    tpm-oc-init-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Demo using Tpm class to implement a basic Output Compare system
 *
 *  This example assumes two TPMs
 *  - TpmShared with channel TpmSharedChannel
 *    This TPM configuration should have Interrupts supported + Shared call-back
 *  - TpmIndividual with channel TpmIndividualChannel
 *    This TPM configuration should have Interrupts supported + Individual call-backs
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

static const TpmShared::Init tpmSharedInit {
   TpmMode_LeftAligned ,         // Alignment and whether interval or free-running mode - LeftAligned
   TpmOverflowAction_Interrupt , // Action on Counter overflow - Interrupt
   NvicPriority_Normal ,         // IRQ level for this peripheral - Normal
   TpmClockSource_SystemTpmClock ,  // Clock Source - System clock
   TpmPrescale_DivBy1 ,          // Clock prescaler - Divide by 1
   40000_ticks,                  // End value for counter

   timerCallback,                // Overflow call-back
   timerChannelCallback,         // Shared channel call-back
};

static const TpmShared::ChannelInit tpmSharedChannelInit {
   TpmSharedChannel::CHANNEL,

   TpmChannelMode_OutputCompareToggle , // Channel Mode - OC Toggle
   TpmChannelAction_Interrupt ,         // Action on Channel Event - Interrupt
   10000_ticks,                         // Output Compare Event time in ticks
};

static const TpmIndividual::Init tpmIndividualInit {
   TpmMode_LeftAligned ,         // Alignment and whether interval or free-running mode - Left aligned
   TpmOverflowAction_Interrupt , // Action on Counter overflow - Interrupt
   NvicPriority_Normal ,         // IRQ level for this peripheral - Normal
   TpmClockSource_SystemTpmClock ,  // Clock Source - System clock
   TpmPrescale_DivBy1 ,          // Clock prescaler - Divide by 1
   40000_ticks,                  // End value for counter

   timerCallback,                // Overflow call-back
};

static const TpmIndividualChannel::ChannelInit tpmIndividualChannelInit {
   TpmIndividualChannel::CHANNEL,

   TpmChannelMode_OutputCompareToggle , // Channel Mode - Disabled
   TpmChannelAction_Interrupt ,         // Action on Channel Event - No action
   20000_ticks,                         // Output Compare Event time in ticks

   timerChannelCallback,                // Individual channel call-back
};

int main() {
   console.writeln("\nStarting");

   TpmShared::configure(tpmSharedInit);
   TpmSharedChannel::configure(tpmSharedChannelInit);

   TpmIndividual::configure(tpmIndividualInit);
   TpmIndividualChannel::configure(tpmIndividualChannelInit);

   for(int count = 0;;count++) {
      Led::toggle();
      waitMS(100);
      console.writeln(count, ": Tick...");
   }
   return 0;
}
