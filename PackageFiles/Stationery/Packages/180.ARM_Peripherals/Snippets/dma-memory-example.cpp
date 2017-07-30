/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main.cpp)
 * @brief   Basic C++ demo using GPIO class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "pit.h"
#include "pdb.h"
#include "lptmr.h"
#include "dma.h"

using namespace USBDM;

bool complete;

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
 * @param[in]  size           Number of bytes to transfer - must be multiple of 4
 * @param[out] destination    Destination location
 */
static void dmaTransfer(void *source, uint32_t size, void *destination) {

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
      /* uint32_t  SADDR  Source address        */ (uint32_t)(source),               // Source array
      /* uint16_t  SOFF   SADDR offset          */ 4,                                // SADDR advances 4 bytes for each request
      /* uint16_t  ATTR   Transfer attributes   */ DMA_ATTR_SSIZE(DmaSize_32bit)|    // 32-bit read from SADDR
      /*                                        */ DMA_ATTR_DSIZE(DmaSize_32bit),    // 32-bit write to DADDR
      /* uint32_t  NBYTES Minor loop byte count */ size,                             // Total transfer in one minor-loop
      /* uint32_t  SLAST  Last SADDR adjustment */ -size,                            // Reset SADDR to start of array on completion
      /* uint32_t  DADDR  Destination address   */ (uint32_t)(destination),          // Start of array for result
      /* uint16_t  DOFF   DADDR offset          */ 4,                                // DADDR advances 4 bytes for each request
      /* uint16_t  CITER  Major loop count      */ DMA_CITER_ELINKNO_ELINK(0)|       // No ELINK
      /*                                        */ 1,                                // 1 (software) request
      /* uint32_t  DLAST  Last DADDR adjustment */ -size,                            // Reset DADDR to start of array on completion
      /* uint16_t  CSR    Control and Status    */ DMA_CSR_INTMAJOR(1)|              // Generate interrupt on completion of Major-loop
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
   printf("Starting\n");

   uint32_t source[20]      = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
   uint32_t destination[20] = {0};

   printf("Original buffer contents\n");
   for (unsigned index=0; index<(sizeof(destination)/sizeof(destination[0])); index++) {
      printf("%4d: , ch2=%6lu\n", index, destination[index]);
   }

   printf("Starting Transfer\n");
   dmaTransfer(source, sizeof(source), destination);
   printf("Completed Transfer\n");

   printf("Final buffer contents\n");
   for (unsigned index=0; index<(sizeof(destination)/sizeof(destination[0])); index++) {
      printf("%4d: , ch2=%6lu\n", index, destination[index]);
   }

   for(;;) {
      __asm__("nop");
   }
   return 0;
}
