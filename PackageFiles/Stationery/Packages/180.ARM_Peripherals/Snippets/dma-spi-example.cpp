/**
 ============================================================================
 * @file    dma-spi-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   DMA example using SPI
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
/**
 * This example uses DMA to transfer data from a buffer to the SPI for transmission.
 * At the same time another DMA channel is used to transfer receive data from the SPI to a buffer.
 * The transmission is not continuous but may be restarted without setting up the TCD again:
 * - Clears the DREQ on transfer complete
 * - Arranging SLAST/DLAST to return the transfer addresses to starting value after each major-loop.
 */
#include <string.h>
#include "hardware.h"
#include "dma.h"
#include "spi.h"

using namespace USBDM;

// Connection - change as required
using Led = GpioC<3, ActiveLow>;  // = PTA2 = D9 = Blue LED

// SPI to use
Spi0 spi;

// Which SPI PCS signal to assert
static constexpr SpiPeripheralSelect spiSelect = SpiPeripheralSelect_2;

// DMA channel numbers
static constexpr DmaChannelNum DMA_TX_CHANNEL = DmaChannelNum_0;
static constexpr DmaChannelNum DMA_RX_CHANNEL = DmaChannelNum_1;

// Used to indicate complete transfer
static volatile bool complete;

/**
 * DMA complete callback
 *
 * Sets flag to indicate sequence complete.
 */
static void dmaCallback() {
   complete = true;
}

static constexpr uint32_t PUSH_BASE =
      SPI_PUSHR_CONT(1)|
      SPI_PUSHR_CTAS(0)|
      SPI_PUSHR_EOQ(0)|
      SPI_PUSHR_CTCNT(0)|
      spiSelect;

const uint32_t txBuffer[]= {
      PUSH_BASE|SPI_PUSHR_TXDATA(1)|SPI_PUSHR_CTCNT(0),
      PUSH_BASE|SPI_PUSHR_TXDATA(2),
      PUSH_BASE|SPI_PUSHR_TXDATA(3),
      PUSH_BASE|SPI_PUSHR_TXDATA(4),
      PUSH_BASE|SPI_PUSHR_TXDATA(5),
      PUSH_BASE|SPI_PUSHR_TXDATA(6),
      PUSH_BASE|SPI_PUSHR_TXDATA(7),
      PUSH_BASE|SPI_PUSHR_TXDATA(8),
      PUSH_BASE|SPI_PUSHR_TXDATA(9),
      PUSH_BASE|SPI_PUSHR_TXDATA(10),
      PUSH_BASE|SPI_PUSHR_TXDATA(11),
      PUSH_BASE|SPI_PUSHR_TXDATA(12),
      PUSH_BASE|SPI_PUSHR_TXDATA(13),
      (PUSH_BASE|SPI_PUSHR_TXDATA(14))&~SPI_PUSHR_CONT(1),
};

static uint8_t rxBuffer[sizeof(txBuffer)/sizeof(txBuffer[0])];
static const uint8_t rxTestBuffer[sizeof(txBuffer)/sizeof(txBuffer[0])] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};

/**
 * Configure DMA from Memory-to-UART
 */
static void initDma() {

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
   static const DmaTcd txTcd {
      /* uint32_t  SADDR  Source address        */ (uint32_t)(txBuffer),                     // Source array
      /* uint16_t  SOFF   SADDR offset          */ sizeof(txBuffer[0]),                      // SADDR advances 1 element for each request
      /* uint16_t  ATTR   Transfer attributes   */ dmaSSize(txBuffer[0])|                    // Read size for SADDR
      /*                                        */ dmaDSize(spi.SPI->PUSHR),                 // Write size for DADDR
      /* uint32_t  NBYTES Minor loop byte count */ sizeof(txBuffer[0]),                      // Total transfer in one minor-loop
      /* uint32_t  SLAST  Last SADDR adjustment */ -sizeof(txBuffer),                        // Reset SADDR to start of array on completion
      /* uint32_t  DADDR  Destination address   */ (uint32_t)(&spi.SPI->PUSHR),              // Destination is SPI PUSH data register
      /* uint16_t  DOFF   DADDR offset          */ 0,                                        // DADDR doesn't change
      /* uint16_t  CITER  Major loop count      */ DMA_CITER_ELINKNO_ELINK(0)|               // No ELINK
      /*                                        */ ((sizeof(txBuffer))/sizeof(txBuffer[0])), // Transfer entire txBuffer
      /* uint32_t  DLAST  Last DADDR adjustment */ 0,                                        // DADDR doesn't change
      /* uint16_t  CSR    Control and Status    */ DMA_CSR_INTMAJOR(0)|                      // Generate interrupt on completion of Major-loop
      /*                                        */ DMA_CSR_DREQ(1)|                          // Clear hardware request when complete major loop (non-stop)
      /*                                        */ DMA_CSR_START(0),                         // Don't start (triggered by hardware)
   };

   static const DmaTcd rxTcd {
      /* uint32_t  SADDR  Source address        */ (uint32_t)(&spi.SPI->POPR),               // Source is SPI POPR data register
      /* uint16_t  SOFF   SADDR offset          */ 0,                                        // SADDR adoesn't change
      /* uint16_t  ATTR   Transfer attributes   */ dmaSSize(rxBuffer[0])|                    // Read size for SADDR (read 1 byte, discards 3)
      /*                                        */ dmaDSize(rxBuffer[0]),                    // Write size to DADDR
      /* uint32_t  NBYTES Minor loop byte count */ sizeof(rxBuffer[0]),                      // Total transfer in one minor-loop
      /* uint32_t  SLAST  Last SADDR adjustment */ 0,                                        // SADDR doesn't change
      /* uint32_t  DADDR  Destination address   */ (uint32_t)(rxBuffer),                     // Destination array
      /* uint16_t  DOFF   DADDR offset          */ sizeof(rxBuffer[0]),                      // DADDR advances 1 element for each request
      /* uint16_t  CITER  Major loop count      */ DMA_CITER_ELINKNO_ELINK(0)|               // No ELINK
      /*                                        */ ((sizeof(rxBuffer))/sizeof(rxBuffer[0])), // Transfer entire txBuffer
      /* uint32_t  DLAST  Last DADDR adjustment */ -sizeof(rxBuffer),                        // Reset DADDR to start of array on completion
      /* uint16_t  CSR    Control and Status    */ DMA_CSR_INTMAJOR(1)|                      // Generate interrupt on completion of Major-loop
      /*                                        */ DMA_CSR_DREQ(1)|                          // Clear hardware request when complete major loop (non-stop)
      /*                                        */ DMA_CSR_START(0),                         // Don't start (triggered by hardware)
   };

   // Sequence not complete yet
   complete = false;

   // Enable DMAC with default settings
   Dma0::configure();

   // Set callback (Interrupts are enabled in TCD)
   Dma0::setCallback(DMA_TX_CHANNEL, dmaCallback);
   Dma0::enableNvicInterrupts(DMA_TX_CHANNEL);

   // Set callback (Interrupts are enabled in TCD)
   Dma0::setCallback(DMA_RX_CHANNEL, dmaCallback);
   Dma0::enableNvicInterrupts(DMA_RX_CHANNEL);

   // Connect DMA channel to SPI Tx
   DmaMux0::configure(DMA_TX_CHANNEL, DmaSlot_SPI0_Transmit, DmaMuxEnable_Continuous);

   // Connect DMA channel to SPI Rx
   DmaMux0::configure(DMA_RX_CHANNEL, DmaSlot_SPI0_Receive, DmaMuxEnable_Continuous);

   // Configure the Tx transfer
   Dma0::configureTransfer(DMA_TX_CHANNEL, txTcd);

   // Configure the Rx transfer
   Dma0::configureTransfer(DMA_RX_CHANNEL, rxTcd);
}

/**
 * SPI callback
 *
 * Used for debug timing checks.
 * LED toggles on each SPI event
 *
 * @param status Interrupt status value from SPI->SR
 */
static void spiCallback(uint32_t) {
   Led::toggle();
}

/**
 * Configure SPI
 */
static void configureSpi() {
   spi.setSpeed(24000000);
   spi.setPeripheralSelect(spiSelect, ActiveLow, SpiSelectMode_Idle);
   spi.setCallback(spiCallback);
   spi.configureInterrupts(
         SpiTxCompleteInterrupt_Enabled,
         SpiEndOfQueueInterrupt_Enable,
         SpiFifoUnderflowInterrupt_Enabled,
         SpiFifoOverflowInterrupt_Enabled);
   spi.configureFifoRequests(SpiFifoTxRequest_Dma, SpiFifoRxRequest_Dma);
}

/**
 * Start transfer
 */
static void startTransfer() {
   complete = false;

   spi.getStatus();
   spi.enableTransfer();

   // Enable Rx hardware requests
   Dma0::enableRequests(DMA_RX_CHANNEL);

   // Enable Tx hardware requests
   Dma0::enableRequests(DMA_TX_CHANNEL);
}

int main() {
   console.writeln("Starting");

   Led::setOutput();

   // Set up DMA transfer from memory -> SPI
   initDma();
   configureSpi();

   for(;;) {
      // Start transfer
      startTransfer();

      // Wait for completion of 1 Major-loop = 1 txBuffer
      while (!complete) {
         __asm__("nop");
      }
      // Check expected Rx data
      if (memcmp(rxBuffer, rxTestBuffer, sizeof(rxBuffer)) != 0) {
         console.writeln("Failed Verify\n");
         __BKPT();
      }
   }
   return 0;
}
