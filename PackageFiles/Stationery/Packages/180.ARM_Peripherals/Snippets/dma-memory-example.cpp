/**
 ============================================================================
 * @file    dma-memory-example.cpp (180.ARM_Peripherals/Snippets/)
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
 * Select irqHandlers option (Class Method - Software ...)
 */
#include "hardware.h"
#include "dma.h"

#include "stdlib.h"
#include "string.h"

using namespace USBDM;

// Used to indicate complete transfer
static volatile bool complete;

/**
 * DMA complete callback
 *
 * Sets flag to indicate sequence complete.
 */
static void dmaCallback(DmaChannelNum dmaChannelNum, uint32_t) {
   Dma0::clearInterruptRequest(dmaChannelNum);
   complete = true;
}

/**
 * DMA Memory-to-memory transfer
 *
 * @param[in]  source         Source location
 * @param[out] destination    Destination location
 * @param[in]  size           Number of bytes to transfer - must be multiple of sizeof(uint32_t)
 */
static ErrorCode dmaTransfer(uint32_t *source, uint32_t *destination, int size) {

   usbdm_assert(size%sizeof(uint32_t) == 0, "Size must be a multiple of sizeof(uint32_t)");

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
    * |..............................|               - ATTR_SMOD, ATTR_DMOD Modulo
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
   static DmaTcd tcd (
      { // DmaInfo source
      /* Source address         */ uint32_t(source),               // Source array
      /* Source offset          */ int32_t(sizeof(*source)),       // Source address advances source element size for each transfer
      /* Source size            */ dmaSize(*source),               // 32-bit read from source address
      /* Last source adjustment */ -size,                          // Reset Source address to start of array on completion
      /* Source modulo          */ DmaModulo_Disabled,             // Disabled
      },
      { // DmaInfo destination
      /* Destination address    */ uint32_t(destination),          // Start of array for result
      /* Destination offset     */ int32_t(sizeof(*destination)),  // Destination address advances destination element size for each transfer
      /* Destination size       */ dmaSize(*destination),          // 32-bit write to destination address
      /* Last dest. adjustment  */ -size,                          // Reset destination address to start of array on completion
      /* Destination modulo     */ DmaModulo_Disabled,             // Disabled
      },

      /* Minor loop byte count  */ dmaNBytes(size),         // Total transfer in one minor-loop
      /* Major loop count       */ dmaCiter(1),             // Single (1) software transfer

      { // DmaTcdCsr control
      DmaStopOnComplete_Enabled ,  // Clear request on complete - ERQ bit is cleared
      DmaIntMajor_Enabled ,        // Interrupt when major counter completes
      DmaStart_Immediate,          // Channel Start immediate (rather than by external request)
      }
   );

   // Sequence not complete yet
   complete = false;

   // Set callback (Interrupts are enabled in TCD)
   Dma0::setCallback(dmaChannelNum, dmaCallback);
   Dma0::enableNvicInterrupts(dmaChannelNum, NvicPriority_Normal);

   // Configure the transfer
   Dma0::configureTransfer(dmaChannelNum, tcd);

   while (!complete) {
      __asm__("nop");
   }

   Dma0::freeChannel(dmaChannelNum);

   return E_NO_ERROR;
}

constexpr int DataSize = 2*((1<<10)/sizeof(uint32_t));  // 3KiB
uint32_t source[DataSize];
uint32_t destination[DataSize];

#define PRINT_BUFFER

void doTestTransfer() {

   for(uint32_t *p=source; p<(source+DataSize); p++) {
      *p = (uint32_t)rand();
   }
   IoFormat format;

#ifdef PRINT_BUFFER
   console.getFormat(format);
   format.setIntegerFormat(8, Padding_LeadingZeroes, Radix_16);
   console.setFormat(format);
   console.writeln("Source buffer contents");
   console.writeArray(source, sizeof(source)/sizeof(source[0]));
#endif

   console.writeln("\nStarting Transfer");
   ErrorCode rc = dmaTransfer(source, destination, sizeof(source));
   console.writeln("Completed Transfer rc = ", getErrorMessage(rc));

#ifdef PRINT_BUFFER
   if (rc == E_NO_ERROR) {
      console.writeln("Destination buffer contents");
      console.writeArray(destination, sizeof(destination)/sizeof(destination[0]));

      if (memcmp(source,destination,sizeof(source)) == 0) {
         console.writeln("\nContents verify passed");
      }
      else {
         console.writeln("\nContents verify failed");
      }
   }
#endif
}

int main() {
   console.writeln("Starting");

   // Enable DMAC with default settings
   Dma0::configure();

   while(true) {
      doTestTransfer();
   }

   return 0;
}
