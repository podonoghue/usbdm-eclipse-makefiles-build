/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main.cpp)
 * @brief   Basic C++ demo using GPIO class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
/**
 * This example uses DMA interrupts.
 *
 * It is necessary to enable these in Configure.usbdmProject
 * under the "Peripheral Parameters"->DMA tab.
 * Select irqHandlerChannel1 and irqErrorHandler option (Class Method - Software ...)
 */
#include "hardware.h"
#include "dma.h"

using namespace USBDM;

static volatile bool complete;

/**
 * DMA complete callback
 *
 * Sets flag to indicate sequence complete.
 */
void dmaCallback() {
   complete = true;
}

/**
 * DMA Memory-to-memory transfer
 *
 * @param[in]  source         Source location
 * @param[in]  size           Number of bytes to transfer - must be multiple of uint32_t size
 * @param[out] destination    Destination location
 */
static void dmaTransfer(uint32_t *source, uint32_t size, uint32_t *destination) {

   assert(size%sizeof(uint32_t) == 0);

   // DMA channel number to use
   static constexpr DmaChannelNum DMA_CHANNEL = DmaChannelNum_1;

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
      /* uint32_t  SADDR  Source address        */ (uint32_t)(source),         // Source array
      /* uint16_t  SOFF   SADDR offset          */ sizeof(*source),            // SADDR advances by source data size for each request
      /* uint16_t  ATTR   Transfer attributes   */ dmaSize(*source,            // 32-bit read from SADDR
      /*                                        */         *destination),      // 32-bit write to DADDR
      /* uint32_t  NBYTES Minor loop byte count */ size,                       // Total transfer in one minor-loop
      /* uint32_t  SLAST  Last SADDR adjustment */ -size,                      // Reset SADDR to start of array on completion
      /* uint32_t  DADDR  Destination address   */ (uint32_t)(destination),    // Array for result
      /* uint16_t  DOFF   DADDR offset          */ sizeof(*destination),       // DADDR advances by destination data size for each request
      /* uint16_t  CITER  Major loop count      */ DMA_CITER_ELINKNO_ELINK(0)| // No ELINK
      /*                                        */ DMA_CITER_ELINKNO_CITER(1), // Single (1) software transfer
      /* uint32_t  DLAST  Last DADDR adjustment */ -size,                      // Reset DADDR to start of array on completion
      /* uint16_t  CSR    Control and Status    */ DMA_CSR_INTMAJOR(1)|        // Generate interrupt on completion of Major-loop
      /*                                        */ DMA_CSR_START(1)
   };

   // Sequence not complete yet
   complete = false;

   // Enable DMAC with default settings
   Dma0::configure();

   // Set callback (Interrupts are enabled in TCD)
   Dma0::setCallback(DMA_CHANNEL, dmaCallback);
   Dma0::enableNvicInterrupts(DMA_CHANNEL);

   // Configure the transfer
   Dma0::configureTransfer(DMA_CHANNEL, tcd);

   while (!complete) {
      __asm__("nop");
   }
}

int main() {
   console.writeln("Starting");

   uint32_t source[20]      = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
   uint32_t destination[20] = {0};

   console.writeln("Original buffer contents");
   for (unsigned index=0; index<(sizeof(destination)/sizeof(destination[0])); index++) {
      console.write(index).write(": , ch2=").writeln(destination[index]);
   }

   console.writeln("Starting Transfer");
   dmaTransfer(source, sizeof(source), destination);
   console.writeln("Completed Transfer");

   console.writeln("Final buffer contents");
   for (unsigned index=0; index<(sizeof(destination)/sizeof(destination[0])); index++) {
      console.write(index).write(": , ch2=").writeln(destination[index]);
   }

   for(;;) {
      __asm__("nop");
   }
   return 0;
}
