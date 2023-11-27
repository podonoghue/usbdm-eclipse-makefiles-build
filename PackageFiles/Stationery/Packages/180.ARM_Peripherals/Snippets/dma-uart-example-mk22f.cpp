/**
 ============================================================================
 * @file    dma-uart-example-mk22f.cpp (180.ARM_Peripherals/Snippets)
 * @brief   DMA example using UART and PIT throttling
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
/**
 * This example uses DMA to transfer characters from a string to the UART for transmission.
 * The speed of transmission is throttled by the use of PIT triggering the DMA channel (DmaMux).
 * The transmission is made continuous by setting up the TCD appropriately:
 * - Not clearing the DREQ on transfer complete
 * - Arranging SLAST to return the transfer addresses to starting value after each major-loop.
 *
 * This example requires interrupts to be enabled in the USBDM configuration for the following:
 * - DMA
 *
 * The LED should be assigned to a suitable GPIO
 *
 * It may also be necessary to adjust DMA_SLOT for the console UART.
 *    DmaSlot_UART0_Transmit => DmaSlot_UART?_Transmit
 *
 * If the console uses a LPUART then other changes are necessary:
 *    DmaSlot_UART0_Transmit => DmaSlot_LPUART?_Transmit
 *    UartDma_TxHoldingEmpty => LpuartDma_TxHoldingEmpty
 *    console.uart->D        => console.lpuart->DATA
 */
#include "hardware.h"
#include "dma.h"
#include "dmamux.h"
#include "pit.h"
#include "smc.h"
#include "mcg.h"

using namespace USBDM;

// Slot number to use (must agree with console UART)
static constexpr DmamuxSlot DMA_SLOT = DmamuxSlot_UART1_Transmit;

// Used to indicate complete transfer
static volatile bool complete;

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
static DmaTcd tcd (
   { // DmaInfo source
   /* Source address                 */ uint32_t(message),             // Source array
   /* Source offset                  */ int32_t(sizeof(message[0])),   // Source address advances 1 element for each request
   /* Source size                    */ dmaSize(message[0]),           // 8-bit read from source address
   /* Last source adjustment         */ -int(sizeof(message)),         // Reset source address to start of array on completion
   /* Source modulo                  */ DmaModulo_Disabled,            // Disabled
   },
   { // DmaInfo destination
   /* Destination address            */ console.uartD,                 // Destination is UART data register
   /* Destination offset             */ 0,                             // Destination address doesn't change
   /* Destination size               */ DmaSize_8bit,                  // 8-bit write to destination address
   /* Last destination adjustment    */ 0,                             // Destination address doesn't change
   /* Destination modulo             */ DmaModulo_Disabled,            // Disabled
   },

   /* Minor loop byte count          */ dmaNBytes(sizeof(message[0])), // Total transfer in one minor-loop
   /* Major loop count               */ dmaCiter(sizeofArray(message)),      // Transfer entire buffer

   { // DmaTcdCsr control
   /* Start channel                  */ DmaStart_Hardware,             // Don't start (triggered by hardware)
   /* Disable Req. on major complete */ DmaStopOnComplete_Disabled,    // Don't clear hardware request when major loop completed
   /* Interrupt on major complete    */ DmaIntMajor_Enabled,           // Generate interrupt on completion of Major-loop
   /* Interrupt on half complete     */ DmaIntHalf_Disabled,           // No interrupt
   /* Bandwidth (speed) Control      */ DmaSpeed_NoStalls              // Full speed
   }
);

/**
 * DMA complete callback
 *
 * Sets flag to indicate sequence complete.
 */
static void dmaCallback(DmaChannelNum channel, uint32_t) {
   // Clear status
   Dma0::clearInterruptRequest(channel);
   // Stop UART requests
   console.setTransmitEmptyAction(UartTxEmptyAction_None);
   // Flag complete to main-line
   complete = true;
}

/**
 * Configure DMA from Memory-to-UART
 *
 * @param dmaChannel  Pre-allocated DMA channel to use.
 */
static void configureDma(DmaChannelNum dmaChannel) {

   // Sequence not complete yet
   complete = false;

   // Enable DMAC
   // Note: These settings affect all DMA channels
   static constexpr DmaBasicInfo::DmaConfig dmaConfigValue = {
      DmaActionOnError_Halt , // DMA halt on error - Transfer halts on any error
      DmaContinuousLink_Disabled , // Continuous Link mode - Continuous Link disabled
      DmaMinorLoopMapping_Disabled , // Minor loop mapping - Mapping disabled
      DmaArbitration_Fixed , // Channel Arbitration - Fixed (within group)
      DmaInDebug_Halt,  // Operation in Debug mode - Halt in debug
   };
   Dma0::configure(dmaConfigValue);

   // Set callback (Interrupts are enabled in TCD)
   Dma0::setCallback(dmaChannel, dmaCallback);
   Dma0::enableNvicInterrupts(dmaChannel, NvicPriority_Normal);
   Dma0::enableNvicErrorInterrupt(NvicPriority_Normal);

   // Connect DMA channel to UART but throttle by PIT Channel N (matches DMA channel N)
   static const Dmamux0::Init dmaMuxInit[1] = {
      {
      dmaChannel,
      DmamuxMode_Throttled , // DMA Channel Mode - Request directly routed
      DMA_SLOT,  // Mapping of DMA slot to DMA channel - SPI0 Receive
      }
   };
   Dmamux0::configure(dmaMuxInit);
   Dmamux0::defaultConfigure();

   // Configure the transfer
   Dma0::configureTransfer(dmaChannel, tcd);

   // Enable hardware requests
   Dma0::enableRequests(dmaChannel);

#ifdef DMA_EARS_EDREQ_0_MASK
   // Enable asynchronous requests (if available)
   Dma0::enableAsynchronousRequests(dmaChannel);
#endif

   // Enable channel interrupt requests
   Dma0::enableErrorInterrupts(dmaChannel);
}

/**
 * Configure the PIT
 * - Generates regular events which throttles the DMA -> UART Tx.
 *
 * @param pitChannel  PIT channel being used.  Must be associated with DMA channel.
 */
static void configurePit(PitChannelNum pitChannel) {
   // Configure base PIT
   const Pit::Init pitInitValue = {
      PitOperation_Enabled , // Module Disable - PIT enabled
      PitDebugMode_StopInDebug,  // Freeze in Debug - Timers stop in Debug
   };
   Pit::configure(pitInitValue);

   // Configure channel for delay with interrupts
   const Pit::ChannelInit pitChannelInitValues[] = {
      {
      pitChannel,
      PitChannelEnable_Enabled , // Timer Channel Enable - Channel enabled
      PitChannelIrq_Enabled ,    // Timer Interrupt Enable - Interrupts are enabled
      40_ms,                     // Reload value in seconds for channel
      },
   };
   Pit::configure(pitChannelInitValues);
}

/**
 * Example clock change call-back class
 * This just makes sure the console is kept up to date
 */
class MyClockChangeCallback : public ClockChangeCallback {
public:
   virtual void beforeClockChange() {
      // Wait for pending writes to complete
      console.flushOutput();
   }
   virtual void afterClockChange() {
      // Fix baud rate after clock change
      console_setBaudRate(defaultBaudRate);
   }
};

// Call-back to fix baud rate in clock change
MyClockChangeCallback clockChangeCallback;

int main() {

   console.writeln("\nStarting\n").flushOutput();

   // Allow entry to other RUN modes
   Smc::enableAllPowerModes();

   // Set callback to fix baud rate changes
   Mcg::addClockChangeCallback(clockChangeCallback);

   // DMA channel number to use (determines which PIT channel used)
   static const DmaChannelNum dmaChannel = Dma0::allocatePeriodicChannel();
   if (dmaChannel == DmaChannelNum_None) {
      console.writeln("Failed to allocate DMA channel, rc= ", E_NO_RESOURCE);
      __asm__("bkpt");
   }
   console.writeln("Allocated DMA channel  #", dmaChannel);

   // Set up throttled DMA transfer from memory -> UART
   configureDma(dmaChannel);

   // Get Pit channel associated with DMA channel
   PitChannelNum pitChannel = Pit::allocateDmaAssociatedChannel(dmaChannel);
   if (pitChannel == PitChannelNum_None) {
      console.writeln("Failed to allocate PIT channel, rc= ", E_NO_RESOURCE);
      __asm__("bkpt");
   }
   console.writeln("Allocated PIT channel  #", pitChannel);
   configurePit(pitChannel);

   // Start the UART DMA requests
   console.writeln("Doing 1 DMA transfer while in RUN").flushOutput();
   console.setTransmitEmptyAction(UartTxEmptyAction_Dma);

   // Wait for completion of 1 Major-loop = 1 message
   while (!complete) {
      __asm__("nop");
   }
   console.writeln("Done 1st transfer");
   waitMS(500);

   // RUN->VLPR
   Smc::enterRunMode(ClockConfig_VLPR_BLPI_4MHz);
   console.write("Changed to VLPR mode, ").flushOutput();

   // Re-configure PIT as bus clock may have changed
   configurePit(pitChannel);

   // Start the UART DMA requests again
   complete = false;
   console.writeln("\nDoing DMA while in VLPR....").flushOutput();
   console.setTransmitEmptyAction(UartTxEmptyAction_Dma);

   // Wait for completion of 1 Major-loop = 1 message
   while (!complete) {
      __asm__("nop");
   }
   console.writeln("Done 2nd transfer");
   waitMS(500);

   console.writeln("\nDoing DMA while sleeping....").flushOutput();

   for(;;) {
      // Enable UART Tx DMA requests
      console.setTransmitEmptyAction(UartTxEmptyAction_Dma);

      ErrorCode rc = Smc::enterPowerMode(SmcPowerMode_VLPW);
      if (rc != E_NO_ERROR) {
         console.setTransmitEmptyAction(UartTxEmptyAction_None);
         console.writeln("Failed to change power mode, rc = ", getErrorMessage(rc));
         __asm__("bkpt");
      }
      // Will wake up after each complete transfer due to DMA complete interrupt
      console.writeln("Woke up at end of DMA!").flushOutput();
   }

   return 0;
}
