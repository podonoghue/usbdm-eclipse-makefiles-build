/*
 ============================================================================
 * @file    pit-adc-dma-example.cpp (180.ARM_Peripherals/Snippets/)
 * @brief   PIT trigger ADC triggers DMA
 *
 *  Created on: 10/7/2017
 *      Author: podonoghue
 ============================================================================
 */
#include <string.h> // memset()
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "pit.h"
#include "pdb.h"
#include "lptmr.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"

using namespace USBDM;

// Connection - change as required
using Led         = GpioA<2, ActiveLow>;  // PTA2 = D9 = Blue LED
using Pwm         = Ftm0Channel<2>;       // PTC3 = D6 = FTM0.2
using Adc         = Adc0;
using AdcChannel  = Adc0Channel<0>;
using Tmr_Channel = PitChannel<0>;

/**
 * This example used the PIT to trigger 100 ADC conversions @1ms interval.
 * Each conversion result is captured by the DMAC and transferred to memory.
 *
 * +------------+     +-----------+     +-----------+     +----------+
 * |            |     |           |     |           |     |          |
 * |    PIT     | ==> |    ADC    | ==> |    DMA    | ==> |  Memory  |
 * |            |     |           |     |           |     |          |
 * +------------+     +-----------+     +-----------+     +----------+
 *
 * Requires:
 *  DMAx_IRQHandler
 *  PITx_IRQHandler
 *
 *  Use loop-back from (PTC3 = D6 = FTM0.2) to (ADC0 = A10)
 */

/**
 * Configure the ADC
 * - Triggered by the PIT
 * - Results retrieved by the DMAC
 */
static void configureAdc() {

   // Enable and configure ADC with mostly default settings
   Adc::configure(AdcResolution_16bit_se);

   // Calibrate before use
   Adc::calibrate();

   // Configure the ADC to use hardware with trigger 0 + interrupts + DMA
   AdcChannel::enableHardwareConversion(AdcPretrigger_0, AdcInterrupt_Disabled, AdcDma_Enabled);

   // Connect ADC trigger 0 to PIT
   SimInfo::setAdc0Triggers(SimAdc0AltTrigger_PreTrigger_0, SimAdc0Trigger_PitCh0);

   // Check for errors so far
   checkError();
}

// Flag to indicate transfer complete
bool complete;

/**
 * DMA complete callback
 *
 * Sets flag to indicate sequence complete.
 * Stops PIT generating events
 */
void dmaCallback() {
   // Clear LED for debug
   Led::off();
   Tmr_Channel::disable();
   complete = true;
}

uint16_t buffer[100] = {1,2,3,4,5,6,7,8,9};

/**
 * Configure the DMA
 * - Triggered by the ADC
 * - Transfers results from the ADC to memory buffer
 */
static void configureDma() {

   // DMA channel number to use
   static constexpr DmaChannelNum DMA_CHANNEL = DmaChannelNum_1;

   /*
    * Structure to define a DMA transfer
    *
    * Each DMA request trigger causes a minor-loop transfer sequence.
    * The minor loops are counted in the major-loop.
    *
    * The following are used during a minor loop:
    *  - SADDR Source address
    *  - SOFF  Adjustment applied to SADDR after each transfer
    *  - DADDR Destination address
    *  - DOFF  Adjustment applied to DADDR after each transfer
    *  - NBYTES Number of bytes to transfer
    *  - Attributes
    *    - ATTR_SSIZE, ATTR_DSIZE Source and destination transfer sizes
    *    - ATTR_SMOD, ATTR_DMOD Modulo --TODO
    *
    * The following are used by the major loop
    *  - SLAST Adjustment applied to SADDR after each major loop - can be used to reset the SADDR for next major loop
    *  - DLAST Adjustment applied to DADDR after each major loop - can be used to reset the DADDR for next major loop
    *  - CITER Major loop counter - counts major loops
    */
   static const DmaTcd tcd {
      /* uint32_t  SADDR  Source address        */ (uint32_t)(Adc::adc().R),          // ADC result register
      /* uint16_t  SOFF   SADDR offset          */ 0,                                // SADDR does not change
      /* uint16_t  ATTR   Transfer attributes   */ DMA_ATTR_SSIZE(DmaSize_16bit)|    // 16-bit read from ADR->R (ignores MSBs)
      /*                                        */ DMA_ATTR_DSIZE(DmaSize_16bit),    // 16-bit write to array
      /* uint32_t  NBYTES Minor loop byte count */ sizeof(buffer[0]),                // 2-bytes for each ADC DMA request
      /* uint32_t  SLAST  Last SADDR adjustment */ 0,                                // No adjustment as SADDR was unchanged
      /* uint32_t  DADDR  Destination address   */ (uint32_t)(&buffer),              // Start of array for result
      /* uint16_t  DOFF   DADDR offset          */ sizeof(buffer[0]),                // DADDR advances 2 bytes for each request
      /* uint16_t  CITER  Major loop count      */ DMA_CITER_ELINKNO_ELINK(0)|       // No ELINK
      /*                                        */ sizeof(buffer)/sizeof(buffer[0]), // Number of requests to do
      /* uint32_t  DLAST  Last DADDR adjustment */ -sizeof(buffer),                  // Reset DADDR to start of array on completion
      /* uint16_t  CSR    Control and Status    */ DMA_CSR_INTMAJOR(1)|              // Generate interrupt on completion of Major-loop
      /*                                        */ DMA_CSR_DREQ(1),                  // Stop transfer on completion of Major-loop
   };

   // Sequence not complete yet
   complete = false;

   // Enable DMAC with default settings
   Dma0::configure();

   // Set callback for end of transfer
   Dma0::setCallback(DMA_CHANNEL, dmaCallback);

   // Enable interrupts in NVIC
   Dma0::enableNvicInterrupts(DMA_CHANNEL);

   // Configure the transfer
   Dma0::configureTransfer(DMA_CHANNEL, tcd);

   // Enable requests from the channel
   Dma0::enableRequests(DMA_CHANNEL);

   // DMA triggered by ADC requests
   DmaMux0::configure(DMA_CHANNEL, Dma0Slot_ADC0, DmaMuxEnable_Continuous);

   // Check for errors so far
   checkError();
}

/**
 * PIT callback
 *
 * Used for debug timing checks.
 * LED toggles on each PIT event
 */
void pitCallback() {
   Led::toggle();
}

/*
 * Configure the PIT
 * - Generates regular events at 1ms interval. Each event is used to initiate an ADC conversions.
 */
void configurePit() {
   // Configure base PIT
   Pit::configure(PitDebugMode_Stop);

   Tmr_Channel::setCallback(pitCallback);

   // Configure channel
   Tmr_Channel::configure(1*ms, PitChannelIrq_Enabled);
   Tmr_Channel::enableNvicInterrupts();

   // Check for errors so far
   checkError();
}

/**
 * Configures a timer as a 10ms Square wave output to
 * use as measurement input for the ADC.
 */
void createWaveform() {
   Pwm::Ftm::enable();
   Pwm::Ftm::configure(FtmMode_LeftAlign);
   Pwm::configure(FtmChMode_PwmHighTruePulses);
   Pwm::setPeriod(10*ms);
   Pwm::setDutyCycle(50*percent);
}

/**
 * Do 100 ADC conversions @1ms interval into memory buffer
 */
void testHardwareConversions() {
   // Clear buffer initially
   memset(buffer, 0, sizeof(buffer));

   configureAdc();
   configureDma();
   configurePit();

   while (!complete) {
      __asm__("nop");
   }

   console.writeln("Completed Transfer\nResults:");
   console.setPadding(Padding_LeadingSpaces).setWidth(5);
   for (unsigned index=0; index<(sizeof(buffer)/sizeof(buffer[0]));) {
      console.write(index).write(": ");
      for (int row=0; row<10; row++, index++) {
         console.write(buffer[index]).write(", ");
      }
      console.writeln();
   }
   console.reset();
}

int main() {
   console.writeln("\n\nStarting");

   // Debug LED
   Led::setOutput();

   createWaveform();
   testHardwareConversions();

   for(;;) {
      __asm__("nop");
   }
   return 0;
}
