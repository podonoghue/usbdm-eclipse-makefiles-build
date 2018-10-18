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
#include "dma.h"

using namespace USBDM;

// Hardware connections - change as required
using Led         = GpioA<2, ActiveLow>;  // = PTA2 = Arduino D9 = Blue LED
using Adc         = Adc0;
using AdcChannel  = Adc0Channel<14>; // = PTC0 = Arduino A0
using PITChannel  = PitChannel<0>;

// Sample rate for ADC
constexpr float SAMPLE_RATE = 1*ms;

/**
 * This example uses the PIT to trigger 100 ADC conversions @1ms interval.
 * Each conversion result is captured by the DMAC and transferred to memory.
 *
 * +------------+     +-----------+     +-----------+     +----------+
 * |            |     |           |     |           |     |          |
 * |    PIT     | ==> |    ADC    | ==> |    DMA    | ==> |  Memory  |
 * |            |     |           |     |           |     |          |
 * +------------+     +-----------+     +-----------+     +----------+
 *
 * Requires use of interrupts for PIT (for debug) and DMA.
 */

/**
 * Configure the ADC
 * - Triggered directly by the PIT
 * - Results retrieved by the DMAC
 */
static void configureAdc() {

   // Enable and configure ADC
   Adc::configure(AdcResolution_16bit_se);

   // Calibrate before use
   Adc::calibrate();

   // Average across 4 samples
   Adc::setAveraging(AdcAveraging_4);

   // Map pin to ADC
   AdcChannel::setInput();

   // Configure the ADC hardware trigger 0 for no interrupts + DMA
   AdcChannel::enableHardwareConversion(AdcPretrigger_0, AdcInterrupt_Disabled, AdcDma_Enabled);

   // Connect ADC trigger A to PIT
   SimInfo::setAdc0Triggers(SimAdc0AltTrigger_PreTrigger_0, SimAdc0Trigger_PitCh0);

   // Check for errors so far
   checkError();
}

// Flag to indicate transfer complete
volatile bool complete;

/**
 * DMA complete callback
 *
 * Sets flag to indicate sequence complete.
 */
static void dmaCallback(DmaChannelNum channel) {
   Dma0::clearInterruptRequest(channel);

   // Clear LED for debug
   Led::off();
   complete = true;
}

// Buffer for data
uint16_t buffer[100] = {1,2,3,4,5,6,7,8,9};

/**
 * Configure the DMA
 * - Triggered by the ADC
 * - Transfers results from the ADC to memory buffer
 *
 * @return E_NO_ERROR    Success
 * @return E_NO_RESOURCE Unable to allocate DMA channel
 */
static void configureDma(DmaChannelNum dmaChannelNum) {

   usbdm_assert(dmaChannelNum != DmaChannelNum_None, "Illegal DMA channel");

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
    * |..............................|               - ATTR_SMOD, ATTR_DMOD Modulo
    * | |                          | |
    * | +--------------------------+ |            The number of reads and writes done will depend on NBYTES, SSIZE and DSIZE
    * | +--------------------------+ |<-DMA Req.  For example: NBYTES=12, SSIZE=16-bits, DSIZE=32-bits => 6 reads, 3 writes
    * | | Minor Loop               | |            NBYTES must be an even multiple of SSIZE and DSIZE in bytes.
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
   static const DmaTcd tcd (
      /* Source address                 */ (uint32_t)(Adc::adcR(0)),      // Read from ADC result register
      /* Source offset                  */ 0,                             // Source address does not change
      /* Source size                    */ dmaSize(buffer[0]),            // Size of read from ADC matches buffer element size
      /* Source modulo                  */ DmaModulo_Disabled,            // Disabled
      /* Last source adjustment         */ 0,                             // No adjustment as SADDR was unchanged

      /* Destination address            */ (uint32_t)(buffer),            // Write results to buffer
      /* Destination offset             */ sizeof(buffer[0]),             // Destination address advances 2 bytes for each request
      /* Destination size               */ dmaSize(buffer[0]),            // 16-bit write to buffer
      /* Destination modulo             */ DmaModulo_Disabled,            // Disabled
      /* Last destination adjustment    */ -sizeof(buffer),               // Reset destination to start of buffer on completion

      /* Minor loop byte count          */ dmaNBytes(sizeof(buffer[0])),  // 2-bytes for each ADC DMA request
      /* Major loop count               */ dmaCiter(sizeof(buffer)/       // Total Number of requests to do
	   /*                                */          sizeof(buffer[0])),
      /* Channel Start                  */ false,                         // Don't start (triggered by hardware = ADC)
      /* Disable Req. on major complete */ true,                          // Clear hardware request when complete major loop
      /* Interrupt on major complete    */ true,                          // Generate interrupt on completion of major-loop
      /* Interrupt on half complete     */ false,                         // No interrupt
      /* Bandwidth (speed) Control      */ DmaSpeed_NoStalls              // Full speed
   );

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
}

/**
 * Start DMA transaction
 *
 * @param dmaChannelNum Channel to start
 */
void startDma(DmaChannelNum dmaChannelNum) {
   // Sequence not complete yet
   complete = false;

   // Enable requests from the channel
   Dma0::enableRequests(dmaChannelNum);
}

/**
 * PIT callback
 *
 * Used for debug timing checks.
 * LED toggles on each PIT event while DMA underway
 */
void pitCallback() {
   if (!complete) {
      Led::toggle();
   }
}

/**
 * Configure the PIT
 *
 * - Generates regular events. Each event is used to initiate an ADC conversions.
 */
void configurePit() {
   // Configure base PIT
   Pit::configure(PitDebugMode_Stop);

   PITChannel::setCallback(pitCallback);

   // Configure channel
   PITChannel::configure(SAMPLE_RATE, PitChannelIrq_Enabled);
   PITChannel::enableNvicInterrupts();
}

/**
 * Test hardware conversions
 */
void testHardwareConversions() {
   configureAdc();

   // Allocate DMA channel to use
   const DmaChannelNum dmaChannelNum = Dma0::allocateChannel();
   if (dmaChannelNum == DmaChannelNum_None) {
      console.writeln("Failed to allocate DMA channel");
	  checkError();
   }

   configureDma(dmaChannelNum);
   configurePit();

   for(;;) {
      console.writeln("Starting Transfer");
      startDma(dmaChannelNum);
      while (!complete) {
         __asm__("nop");
      }
      console.writeln("Completed Transfer");
      console.writeArray(buffer, sizeof(buffer)/sizeof(buffer[0]));
      waitMS(1000);
   }
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
