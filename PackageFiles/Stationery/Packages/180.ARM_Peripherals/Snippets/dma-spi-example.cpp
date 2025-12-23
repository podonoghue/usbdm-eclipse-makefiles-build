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
 *
 * This example requires DMA and SPI interrupts.
 *
 * It is necessary to enable these in Configure.usbdmProject
 * under the "Peripheral Parameters"->DMA0 and "Peripheral Parameters"->SPI tabs
 * Select irqHandlingMethod option (Class Method - Software ...)
 *
 * Define:
 * SpiPeripheralSelect_TestPcs  SPI PCS signal to use
 *
 */
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "hardware.h"
#include "dma.h"
#include "spi.h"

using namespace USBDM;

// Connection - change as required
using Led = RGB_Green;

static const Spi0::Init spiConfig {

   // Common setting that are seldom changed

//   NvicPriority_Normal ,             // (irqLevel)                 IRQ priority level - Normal
//   spiCallback,                      // (handlerName)              User declared event handler

   SpiMasterSlave_Master ,                // (spi_mcr_mstr)             Master or Slave operation - Operate as Master
   SpiContinuousClock_Disable ,           // (spi_mcr_cont_scke)        Continuous SCK Enable - Clock during transfers only
   SpiFreeze_Enabled ,                    // (spi_mcr_frz)              Controls SPI operation while in debug mode - Suspend in debug
   SpiModifiedTiming_Normal ,             // (spi_mcr_mtfe)             Modified Timing Format - Normal Timing
   SpiRxOverflowHandling_Ignore ,         // (spi_mcr_rooe)             Handling of Rx Overflow Data - Ignore incoming
   SpiPcsActiveLow_Pcs0,                  // (spi_mcr_pcsis)            Polarity for PCS signals
   SpiDoze_Enabled ,                      // (spi_mcr_doze)             Enables Doze mode (when processor is waiting?) - Suspend in doze
   SpiClock_Enabled ,                     // (spi_mcr_mdis)             Module Disable - Enabled
   SpiEnableFifo_Both ,                   // (spi_mcr_dis_fifox)        Enable selected FIFOs - Enable Rx & Tx FIFOs
   SpiClearFifo_Both ,                    // (spi_mcr_clr_fifox)        Clear selected FIFOs - FIFOs not affected
   SpiHalt_StartTransfers ,               // (spi_mcr_halt)             Halt - Start transfers
   SpiPcsActiveLow(SpiPeripheralSelect_TestPcs) ,
   SpiTxCompleteAction_None ,             // (spi_rser_tcf_re)          Tx complete action - Interrupt on completion
   SpiEndOfQueueAction_Interrupt ,        // (spi_rser_eoqf_re)         EOQ action - Interrupt on end of queue
   SpiTxFifoUnderflowAction_Interrupt ,   // (spi_rser_tfuf_re)         TxFIFO Underflow action - Interrupt on underflow
   SpiTxFifoAction_Dma ,                  // (spi_rser_txfifo)          Transmit FIFO Fill Request action - DMA
   SpiRxFifoOverflowAction_None ,         // (spi_rser_rfof_re)         RxFIFO Overflow action - Interrupt on overflow
   SpiRxFifoAction_None,                  // (spi_rser_rxfifo)          Receive FIFO Drain Request action - DMA
};

// Shared SPI to use
Spi0 spi(spiConfig);

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
 * | |   SADDR += SOFF          | |             - SLAST Adjustment applied to SADDR at the end of each major loop
 * | |   DADDR += DOFF          | |             - DLAST Adjustment applied to DADDR at the end of each major loop
 * | | Total transfer is NBYTES | |             - CITER Major loop counter - counts how many completed major loops
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
static const DmaTcd tcdSkeleton = {
      DmaInfo {
         /* Source address                 */ 0U,                            //* Source array
         /* Source offset                  */ sizeof(uint32_t),              // Source address advances 1 element for each request
         /* Source size                    */ DmaSize_32bit,                 // 32-bit read from source address
         /* Last source adjustment         */ 0,                             // Reset source address - not used
         /* Source modulo                  */ DmaModulo_Disabled,            // Disabled
      },

      DmaInfo {
         /* Destination address            */ Spi0::spiPUSHR,                // Destination is SPI PUSHR register
         /* Destination offset             */ 0,                             // Destination address doesn't change
         /* Destination size               */ dmaSize(spi.spi->PUSHR),       // 32-bit write to destination address
         /* Last destination adjustment    */ 0,                             // Destination address doesn't change
         /* Destination modulo             */ DmaModulo_Disabled,            // Disabled
      },

      /* Minor loop byte count             */ dmaNBytes(sizeof(uint32_t)), // Total transfer in one minor-loop
      /* Major loop count                  */ 0,                           // *Transfer size - dynamic

      DmaTcdCsr {

      /* Start channel                  */ DmaStart_Hardware,             // Don't start (triggered by hardware)
      /* Disable Req. on major complete */ DmaStopOnComplete_Enabled,     // Clear hardware request when major loop completed
      /* Interrupt on major complete    */ DmaIntMajor_Enabled,           // Generate interrupt on completion of Major-loop
      /* Interrupt on half complete     */ DmaIntHalf_Disabled,           // No interrupt
      /* Bandwidth (speed) Control      */ DmaSpeed_NoStalls,             // Full speed
      /* Channel Linking                */ DmaMajorLink_Disabled,         // No linking
      /* Scatter/Gather                 */ DmaScatterGather_Disabled,     // No scatter-gather
      },
};

const DmaChannelNum dmaChannel = DmaChannelNum_0;

volatile bool complete = false;

/**
 * DMA complete callback
 *
 * Sets flag to indicate sequence complete.
 */
static void dmaCallback() {
   // Clear status
   Dma0::clearInterruptRequest(dmaChannel);

   console.writeln("DMA complete");

   // Stop SPI requests
   spi.endTransaction();

   // Flag complete to main-line
   complete = true;
}

static void spiCallback() {
   console.writeln("SPI complete");
}

/**
 * DMA error call back
 *
 * @param errorFlags Channel error information (DMA_ES)
 */
void dmaErrorCallbackFunction() {
   uint32_t errorFlags = Dma0::getLastError();
   console.WRITELN("DMA error DMA_ES = 0b", errorFlags, Radix_2);
   usbdm_assert(false, "DMA error");
}

void doSpiTransfer() {

   // Sequence not complete yet
   complete = false;

   spi.setFifoAction(SpiTxFifoAction_None, SpiRxFifoAction_None);

   // Configuration for DMAC
   static constexpr DmaConfig dmaConfiguration = {
      DmaActionOnError_Halt ,        // DMA halt on error       - Transfer halts on any error
      DmaContinuousLink_Disabled ,   // Continuous Link mode    - Continuous Link disabled
      DmaMinorLoopMapping_Disabled , // Minor loop mapping      - Mapping disabled
      DmaArbitration_Fixed ,         // Channel Arbitration     - Fixed (within group)
      DmaInDebug_Halt,               // Operation in Debug mode - Halt in debug
   };

   // Enable DMAC
   // Note: These settings affect all DMA channels
   Dma0::configure(dmaConfiguration);

   // Set callbacks (Interrupts are enabled in TCD)
   Dma0::setCallback(Dma0::IrqNum_Ch0, dmaCallback);
   Dma0::setCallback(Dma0::IrqNum_Error, dmaErrorCallbackFunction);
   Dma0::enableNvicInterrupts(Dma0::IrqNum_Ch0, NvicPriority_Normal);
   Dma0::enableNvicInterrupts(Dma0::IrqNum_Error, NvicPriority_Normal);

   static const Dmamux0::Init dmamux0Init {
      DmaChannelNum_0,
      DmamuxSlot_SPI0_Transmit,   // Mapping of DMA slot to DMA channel - TPM0 Channel 2
      DmamuxMode_Continuous ,     // DMA Channel Enable - Channel enabled
   };
   // Connect DMA channel to UART but throttle by PIT Channel N (matches DMA channel N)
   Dmamux0::enable();
   Dmamux0::configure(dmamux0Init);

   static const uint32_t spiData[] = {
         SpiSelectMode_Continuous|SpiCtar_Dma|SpiPeripheralSelect_TestPcs|SPI_PUSHR_TXDATA(0xaaaa)|SpiCountAction_Clear,
         SpiSelectMode_Continuous|SpiCtar_Dma|SpiPeripheralSelect_TestPcs|SPI_PUSHR_TXDATA(0xbbbb),
         SpiSelectMode_Continuous|SpiCtar_Dma|SpiPeripheralSelect_TestPcs|SPI_PUSHR_TXDATA(0xcccc),
         SpiSelectMode_Continuous|SpiCtar_Dma|SpiPeripheralSelect_TestPcs|SPI_PUSHR_TXDATA(0xdddd),
         SpiSelectMode_Continuous|SpiCtar_Dma|SpiPeripheralSelect_TestPcs|SPI_PUSHR_TXDATA(0xeeee),
         SpiSelectMode_Idle      |SpiCtar_Dma|SpiPeripheralSelect_TestPcs|SPI_PUSHR_TXDATA(0xffff)|SpiEndOfQueue_Assert,
   };

   // Set up TCD from skeleton and modify dynamic values
   DmaTcd tcd{tcdSkeleton};
   // Source address
   tcd.SADDR = uint32_t(spiData);
   // Source size
   tcd.CITER = dmaCiter(sizeof(spiData)/sizeof(spiData[0]));

   // Configure the transfer
   Dma0::configureTransfer(dmaChannel, tcd);

   // Enable hardware requests
   Dma0::enableRequest(dmaChannel);

   // Enable channel interrupt requests
   Dma0::enableErrorInterrupts(dmaChannel);

   waitMS(10);
   // Communication settings
   static constexpr Spi0::SerialInit serialInitValue {
      5_MHz ,                // (speed[0])                 Speed of interface
      SpiMode_0 ,            // (spi_ctar_mode[0])         Mode - Mode 0: CPOL=0, CPHA=0
      SpiFrameSize_16_bits,  // (spi_ctar_fmsz[0])         SPI Frame sizes - 8 bits/transfer
      SpiBitOrder_MsbFirst,  // (spi_ctar_lsbfe[0])        Transmission order - MSB sent first
   };

   // SPI Configuration to send data bytes
   const Spi::SpiCalculatedConfiguration dataConfiguration(
         spi.calculateConfiguration(serialInitValue, SpiPeripheralSelect_TestPcs, SpiPeripheralSelectMode_Transaction, SpiCtarSelect_1)
         );
   spi.setCallback(spiCallback);

   spi.setFifoAction(SpiTxFifoAction_Dma, SpiRxFifoAction_Dma);
   spi.startTransaction(dataConfiguration);
   spi.clearStatusFlags();

   while (!complete) {
   }
}

int main() {
   console.writeln("Starting");

   for(;;) {
      doSpiTransfer();
      waitMS(200);
   }

   return 0;
}
