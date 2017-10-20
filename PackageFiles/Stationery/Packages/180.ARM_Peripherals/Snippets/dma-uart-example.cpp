/**
 ============================================================================
 * @file    dma-uart-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   DMA example using UART and PIT throttling
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
/**
 * This example uses DMA to transfer characters from a string to the UART for transmission.
 * The speed of transmission is throttled by the use of PIT triggering on the DMA channel (DmaMux).
 * The transmission is made continuous by setting up the TCD appropriately:
 * - Not clearing the DREQ on transfer complete
 * - Arranging SLAST to return the transfer addresses to starting value after each major-loop.
 *
 * This example requires interrupts to be enabled in the USBDM configuration for the following:
 * - DMA error
 * - DMA channel
 * - PIT channel
 */
#include "hardware.h"
#include "dma.h"
#include "pit.h"

using namespace USBDM;

// Connection - change as required
using Led         = GpioA<2, ActiveLow>;  // = Blue LED

// PIT channel used for throttling
using TimerChannel = PitChannel<1>;

// DMA channel number to use (must agree with PIT channel used)
static constexpr DmaChannelNum DMA_CHANNEL = DmaChannelNum_1;

// Used to indicate complete transfer
volatile bool complete;

/**
 * DMA complete callback
 *
 * Sets flag to indicate sequence complete.
 */
static void dmaCallback() {
   complete = true;
}

/**
 * DMA error call back
 *
 * @param errorFlags Channel error information (DMA_ES)
 */
void dmaErrorCallbackFunction(uint32_t errorFlags) {
   console.write("DMA error DMA_ES = 0x").writeln(errorFlags, Radix_16);
   __BKPT();
}

static const char message[]=
      "=================================\n\r"
      " Hello world from DMA controller \n\r"
      "=================================\n\r";

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
 * Structure to define a DMA transfer
 */
static const DmaTcd tcd {
   /* uint32_t  SADDR  Source address        */ (uint32_t)(message),                    // Source array
   /* uint16_t  SOFF   SADDR offset          */ sizeof(message[0]),                     // SADDR advances 1 byte for each request
   /* uint16_t  ATTR   Transfer attributes   */ dmaSSize(message[0])|                   // 8-bit read from SADDR
   /*                                        */ dmaDSize(message[0]),                   // 8-bit write to DADDR
   /* uint32_t  NBYTES Minor loop byte count */ 1*sizeof(message[0]),                   // Total transfer in one minor-loop
   /* uint32_t  SLAST  Last SADDR adjustment */ -sizeof(message),                       // Reset SADDR to start of array on completion
   /* uint32_t  DADDR  Destination address   */ (uint32_t)(&console.uart->D),           // Destination is UART data register
   /* uint16_t  DOFF   DADDR offset          */ 0,                                      // DADDR doesn't change
   /* uint16_t  CITER  Major loop count      */ DMA_CITER_ELINKNO_ELINK(0)|             // No ELINK
   /*                                        */ ((sizeof(message))/sizeof(message[0])), // Transfer entire buffer
   /* uint32_t  DLAST  Last DADDR adjustment */ 0,                                      // DADDR doesn't change
   /* uint16_t  CSR    Control and Status    */ DMA_CSR_INTMAJOR(1)|                    // Generate interrupt on completion of Major-loop
   /*                                        */ DMA_CSR_DREQ(0)|                        // Don't clear hardware request when complete major loop (non-stop)
   /*                                        */ DMA_CSR_START(0),                       // Don't start (triggered by hardware)
};

/**
 * Configure DMA from Memory-to-UART
 */
static void configureDma() {

   // Sequence not complete yet
   complete = false;

   // Enable DMAC with default settings
   Dma0::configure();

   // Set callback (Interrupts are enabled in TCD)
   Dma0::setCallback(DMA_CHANNEL, dmaCallback);
   Dma0::setErrorCallback(dmaErrorCallbackFunction);
   Dma0::enableNvicInterrupts(DMA_CHANNEL);
   Dma0::enableNvicErrorInterrupt();

   // Connect DMA channel to UART but throttle by PIT Channel 1 (matches DMA channel 1)
   DmaMux0::configure(DMA_CHANNEL, DmaSlot_UART0_Transmit, DmaMuxEnable_Triggered);

   // Configure the transfer
   Dma0::configureTransfer(DMA_CHANNEL, tcd);

   // Enable hardware requests
   Dma0::enableRequests(DMA_CHANNEL);

   // Enable channel interrupt requests
   Dma0::enableErrorInterrupts(DMA_CHANNEL);
}

/**
 * PIT callback
 *
 * Used for debug timing checks.
 * LED toggles on each PIT event
 */
static void pitCallback() {
   Led::toggle();
}

/*
 * Configure the PIT
 * - Generates regular events. Each event is used to throttle the UART Tx.
 */
static void configurePit() {
   // Configure base PIT
   Pit::configure(PitDebugMode_Stop);

   TimerChannel::setCallback(pitCallback);
   // Configure channel
   TimerChannel::configure(100*ms, PitChannelIrq_Enable);
}

int main() {

   console.writeln("Starting");

   Led::setOutput();

   // Set up DMA transfer from memory -> UART
   configureDma();
   configurePit();

   // Start the UART DMA requests
   console.enableDma(UartDma_TxHoldingEmpty);

   // Wait for completion of 1 Major-loop = 1 message
   while (!complete) {
      __asm__("nop");
   }

   // Stop the UART DMA requests
   console.enableDma(UartDma_TxHoldingEmpty, false);

   console.writeln("Done 1st message");
   wait(4000*ms);

   // Start the UART DMA requests again
   console.writeln("More coming....");
   console.enableDma(UartDma_TxHoldingEmpty);

   for(;;) {
      __asm__("wfi");
   }
   return 0;
}
