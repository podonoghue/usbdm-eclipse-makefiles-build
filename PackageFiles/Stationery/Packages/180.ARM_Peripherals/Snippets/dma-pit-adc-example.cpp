/**
 ============================================================================
 * @file    dma-pit-adc-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   PIT trigger ADC triggers DMA
 *
 *  Created on: 10/7/2017
 *      Author: podonoghue
 ============================================================================
 */
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "pit.h"
#include "pdb.h"
#include "lptmr.h"
#include "dma.h"

using namespace USBDM;

// Connection - change as required
using Led         = GpioA<2, ActiveLow>;  // = PTA2 = D9 = Blue LED
using Adc         = Adc0;
using AdcChannel  = Adc0Channel<0>;
using PITChannel  = PitChannel<0>;

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
 */

/**
 * Configure the ADC
 * - Triggered by the PIT
 * - Results retrieved by the DMAC
 */
static void configureAdc() {

   // Enable and configure ADC
   Adc::configure(AdcResolution_16bit_se);

   // Calibrate before use
   Adc::calibrate();

   // Configure the ADC to use hardware with trigger A + interrupts + DMA
   AdcChannel::enableHardwareConversion(AdcPretrigger_0, AdcInterrupt_disable, AdcDma_Enable);

   // Connect ADC trigger A to PIT
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
 */
static void dmaCallback() {
   // Clear LED for debug
   Led::off();
   PITChannel::disable();
   complete = true;
}

uint16_t buffer[100] = {1,2,3,4,5,6,7,8,9};

/**
 * Configure the DMA
 * - Triggered by the ADC
 * - Transfers results from the ADC to memory buffer
 */
static ErrorCode configureDma() {

   // DMA channel number to use
   const DmaChannelNum dmaChannelNum = Dma0::allocateChannel();

   if (dmaChannelNum == DmaChannelNum_None) {
      return E_NO_RESOURCE;
   }
   /**
    * @verbatim
    * +------------------------------+            Simple DMA mode (MLNO = Minor Loop Mapping Disabled)
    * | Major Loop =                 |            ==================================================
    * |    CITER x Minor Loop        |
    * |                              |            Each DMA request triggers a minor-loop transfer sequence.
    * | +--------------------------+ |<-DMA Req.  The minor loops are counted in the major-loop.
    * | | Minor Loop               | |
    * | | Each transfer            | |            The following are used during a minor loop:
    * | |   SADDR->DADDR           | |             - SADDR Source address
    * | |   SADDR += SOFF          | |             - SOFF  Adjustment applied to SADDR after each transfer
    * | |   DADDR += DOFF          | |             - DADDR Destination address
    * | | Total transfer is NBYTES | |             - DOFF  Adjustment applied to DADDR after each transfer
    * | +--------------------------+ |             - NBYTES Number of bytes to transfer
    * | +--------------------------+ |<-DMA Req.   - Attributes
    * | | Minor Loop               | |               - ATTR_SSIZE, ATTR_DSIZE Source and destination transfer sizes
    * |..............................|               - ATTR_SMOD, ATTR_DMOD Modulo --TODO
    * | |                          | |
    * | +--------------------------+ |             The number of reads and writes done will depend on NBYTES, SSIZE and DSIZE
    * | +--------------------------+ |<-DMA Req.   For example: NBYTES=12, SSIZE=16-bits, DSIZE=32-bits => 6 reads, 3 writes
    * | | Minor Loop               | |             NBYTES must be an even multiple of SSIZE and DSIZE in bytes.
    * | | Each transfer            | |
    * | |   SADDR->DADDR           | |            The following are used by the major loop
    * | |   SADDR += SOFF          | |             - SLAST Adjustment applied to SADDR after major loop
    * | |   DADDR += DOFF          | |             - DLAST Adjustment applied to DADDR after major loop
    * | | Total transfer is NBYTES | |             - CITER Major loop counter - counts how many minor loops
    * | +--------------------------+ |
    * |                              |            SLAST and DLAST may be used to reset the addresses to the initial value or
    * | At end of Major Loop         |            link to the next transfer.
    * |    SADDR += SLAST            |            The total transferred for the entire sequence is CITER x NBYTES.
    * |    DADDR += DLAST            |
    * |                              |            Important options in the CSR:
    * | Total transfer =             |              - DMA_CSR_INTMAJOR = Generate interrupt at end of Major-loop
    * |    CITER*NBYTES              |              - DMA_CSR_DREQ     = Clear hardware request at end of Major-loop
    * +------------------------------+              - DMA_CSR_START    = Start transfer. Used for software transfers. Automatically cleared.
    * @endverbatim
    *
    * Structure to define the DMA transfer
    */
   static const DmaTcd tcd {
      /* uint32_t  SADDR  Source address        */ (uint32_t)(ADC0->R),              // ADC result register
      /* uint16_t  SOFF   SADDR offset          */ 0,                                // SADDR does not change
      /* uint16_t  ATTR   Transfer attributes   */ DMA_ATTR_SSIZE(DmaSize_16bit)|    // 16-bit read from ADR->R (ignores MSBs)
      /*                                        */ DMA_ATTR_DSIZE(DmaSize_16bit),    // 16-bit write to array
      /* uint32_t  NBYTES Minor loop byte count */ 2,                                // 2-bytes for each ADC DMA request
      /* uint32_t  SLAST  Last SADDR adjustment */ 0,                                // No adjustment as SADDR was unchanged
      /* uint32_t  DADDR  Destination address   */ (uint32_t)(&buffer),              // Start of array for result
      /* uint16_t  DOFF   DADDR offset          */ sizeof(buffer[0]),                // DADDR advances 2 bytes for each request
      /* uint16_t  CITER  Major loop count      */ DMA_CITER_ELINKNO_ELINK(0)|       // No ELINK
      /*                                        */ sizeof(buffer)/sizeof(buffer[0]), // Number of requests to do
      /* uint32_t  DLAST  Last DADDR adjustment */ -sizeof(buffer),                  // Reset DADDR to start of array on completion
      /* uint16_t  CSR    Control and Status    */ DMA_CSR_INTMAJOR(1)|              // Generate interrupt on completion of Major-loop
      /*                                        */ DMA_CSR_DREQ(1)|                  // Clear hardware request when complete major loop (non-stop)
      /*                                        */ DMA_CSR_START(0),                 // Don't start
   };

   // Sequence not complete yet
   complete = false;

   // Enable DMAC with default settings
   Dma0::configure();

   // Set callback (Interrupts are enabled in TCD)
   Dma0::setCallback(dmaChannelNum, dmaCallback);
   Dma0::enableNvicInterrupts(dmaChannelNum);

   // DMA triggered by ADC requests
   DmaMux0::configure(dmaChannelNum, Dma0Slot_ADC0, DmaMuxEnable_Continuous);

   // Configure the transfer
   Dma0::configureTransfer(dmaChannelNum, tcd);

   // Enable requests from the channel
   Dma0::enableRequests(dmaChannelNum);

   return E_NO_ERROR;
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
 * - Generates regular events. Each event is used to initiate an ADC conversions.
 */
void configurePit() {
   // Configure base PIT
   Pit::configure(PitDebugMode_Stop);

   PITChannel::setCallback(pitCallback);
   // Configure channel
   PITChannel::configure(1*ms, PitChannelIrq_Enable);
}

void testHardwareConversions() {
   configureAdc();
   configureDma();
   configurePit();

   while (!complete) {
      __asm__("nop");
   }

   console.writeln("Completed Transfer");
   console.writeArray(buffer, sizeof(buffer)/sizeof(buffer[0]));
}

int main() {
   console.writeln("Starting");

   Led::setOutput();

   testHardwareConversions();

   for(;;) {
      __asm__("nop");
   }
   return 0;
}
