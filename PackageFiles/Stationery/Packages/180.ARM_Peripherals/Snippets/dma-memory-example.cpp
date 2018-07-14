/**
 ============================================================================
 * @file    dma-memory-example.cpp (180.ARM_Peripherals/Sources/)
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
static void dmaCallback(DmaChannelNum channel) {
   Dma0::clearInterruptRequest(channel);
   complete = true;
}

/**
 * DMA Memory-to-memory transfer
 *
 * @param[in]  source         Source location
 * @param[out] destination    Destination location
 * @param[in]  size           Number of bytes to transfer - must be multiple of uint32_t size
 */
static ErrorCode dmaTransfer(uint32_t *source, uint32_t *destination, uint32_t size) {

   usbdm_assert(size%sizeof(uint32_t) == 0, "size must be a multiple of sizeof(uint32_t)");

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
      /* uint32_t  SADDR         Source address              */ (uint32_t)(source),         // Source array
      /* uint16_t  SOFF          Source offset               */ sizeof(*source),            // SADDR advances source element size for each transfer
      /* DmaSize   DSIZE:3       Destination size            */ dmaSize(*destination),      // 32-bit write to DADDR
      /* DmaModulo DMOD:5        Destination modulo          */ DmaModulo_Disabled,
      /* DmaSize   SSIZE:3       Source size                 */ dmaSize(*source),           // 32-bit read from SADDR
      /* DmaModulo SMOD:5        Source modulo               */ DmaModulo_Disabled,
      /* uint32_t  NBYTES        Minor loop byte count       */ size,                       // Total transfer in one minor-loop
      /* uint32_t  SLAST         Last source adjustment      */ -size,                      // Reset SADDR to start of array on completion
      /* uint32_t  DADDR         Destination address         */ (uint32_t)(destination),    // Start of array for result
      /* uint16_t  DOFF          Destination offset          */ sizeof(*destination),       // DADDR advances destination element size for each transfer
      /* uint16_t  CITER         Major loop count            */ DMA_CITER_ELINKNO_ELINK(0)| // No ELINK
      /*                                                     */ DMA_CITER_ELINKNO_CITER(1), // Single (1) software transfer
      /* uint32_t  DLAST:1        Last DADDR adjustment      */ -size,                      // Reset DADDR to start of array on completion
      /* bool      START:1       Channel Start               */ true,                       // Software start
      /* bool      INTMAJOR:1    Interrupt on major complete */ true,                       // Generate interrupt on completion of Major-loop
      /* bool      INTHALF:1     Interrupt on half complete  */ false,
      /* bool      DREQ:1        Disable Request             */ false,                      // Don't clear hardware request when complete major loop
      /* bool      ESG:1         Enable Scatter/Gather       */ false,
      /* bool      MAJORELINK:1  Enable channel linking      */ false,
      /* bool      ACTIVE:1      Channel Active              */ false,
      /* bool      DONE:1        Channel Done                */ false,
      /* unsigned  MAJORLINKCH:4 Link Channel Number         */ 0,
      /* DmaSpeed  BWC:2         Bandwidth (speed) Control   */ DmaSpeed_NoStalls,
   };

   // Sequence not complete yet
   complete = false;

   // Enable DMAC with default settings
   Dma0::configure();

   // Set callback (Interrupts are enabled in TCD)
   Dma0::setCallback(dmaChannelNum, dmaCallback);
   Dma0::enableNvicInterrupts(dmaChannelNum);

   // Configure the transfer
   Dma0::configureTransfer(dmaChannelNum, tcd);

   while (!complete) {
      __asm__("nop");
   }
   return E_NO_ERROR;
}

constexpr int DataSize = 4*((1<<10)/sizeof(uint32_t));  // 4KiB
uint32_t source[DataSize];
uint32_t destination[DataSize];

int main() {
   console.writeln("Starting");

#if 0
   // For testing channel allocation
   for(;;) {
      DmaChannelNum ch = Dma0::allocateChannel();
      if (ch == DmaChannelNum_None) {
         break;
      }
      console.write("Channel allocated = ").writeln(ch);
   }
#endif

   for(uint32_t *p=source; p<(source+DataSize); p++) {
      *p = (uint32_t)rand();
   }
   console.writeln("Source buffer contents");
   console.writeArray(source, sizeof(source)/sizeof(source[0]));

   console.writeln("Starting Transfer");
   ErrorCode rc = dmaTransfer(source, destination, sizeof(source));
   console.write("Completed Transfer rc = ").writeln(getErrorMessage(rc));

   if (rc == E_NO_ERROR) {
      console.writeln("Destination buffer contents");
      console.writeArray(destination, sizeof(destination)/sizeof(destination[0]));

      if (memcmp(source,destination,sizeof(source)) == 0) {
         console.writeln("Contents verify passed");
      }
      else {
         console.writeln("Contents verify failed");
      }
   }

   for(;;) {
      __asm__("nop");
   }
   return 0;
}
