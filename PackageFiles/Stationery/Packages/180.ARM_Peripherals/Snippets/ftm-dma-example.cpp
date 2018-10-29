/**
 ============================================================================
 * @file ftm-dma-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   FTM example using DMA
 *
 *  Created on: 19 Jun 2018
 *      Author: podonoghue
 ============================================================================
 */
#include <algorithm>    // std::max
#include "hardware.h"
#include "dma.h"

using namespace USBDM;

// LED
using Led = GpioC<3,ActiveLow>;

// Timer being used - change as required
using Timer = Ftm0;

// Timer channel being used - change as required
using TimerChannel = Timer::Channel<7>;

// Slot number to use (must agree with FTM channel used)
static constexpr DmaSlot DMA_SLOT = Dma0Slot_FTM0_Ch0+TimerChannel::CHANNEL;

// Waveform to generate
static uint32_t data[4]= {};

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
static constexpr DmaTcd tcd (
   /* Source address                 */ (uint32_t)(data),         // Source array
   /* Source offset                  */ sizeof(data[0]),          // Source advances element size for each transfer
   /* Source size                    */ dmaSize(data[0]),         // Match source element size
   /* Source modulo                  */ DmaModulo_Disabled,       // No modulo
   /* Last source adjustment         */ -(int)sizeof(data),       // Reset Source address to start of array on completion

   /* Destination address            */ TimerChannel::ftmCnV(),   // Write to FTM count register
   /* Destination offset             */ 0,                        // Fixed destination
   /* Destination size               */ DmaSize_32bit,            // 32-bit write to destination address
   /* Destination modulo             */ DmaModulo_Disabled,       // Disabled
   /* Last destination adjustment    */ 0,                        // No adjustment as address unchanged

   /* Minor loop byte count          */ dmaNBytes(sizeof(data[0])),               // Transfer one entry in minor-loop
   /* Major loop count               */ dmaCiter((sizeof(data))/sizeof(data[0])), // Transfer entire table in major loop

   /* Start channel                  */ false,                   // Don't start (triggered by hardware)
   /* Disable Req. on major complete */ false,                   // Don't clear hardware request when major loop completed
   /* Interrupt on major complete    */ true,                    // Generate interrupt on completion of major-loop
   /* Interrupt on half complete     */ false,                   // No interrupt
   /* Bandwidth (speed) Control      */ DmaSpeed_NoStalls        // Full speed
);

/**
 * DMA complete callback
 *
 * Sets flag to indicate sequence complete.
 */
static void dmaCallback(DmaChannelNum dmaChannelNum) {
   Dma0::clearInterruptRequest(dmaChannelNum);
   Led::toggle();
}

/**
 * DMA error call back
 *
 * @param errorFlags Channel error information (DMA_ES)
 */
void dmaErrorCallbackFunction(uint32_t errorFlags) {
   console.write("DMA error DMA_ES = 0b").writeln(errorFlags, Radix_2);
   __BKPT();
}

/**
 * Configure DMA from Memory-to-UART
 *
 * @param dmaChannel
 */
static void configureDmaChannel() {

   // Allocate DMA channel
   DmaChannelNum dmaChannel = Dma0::allocateChannel();

   // Set callback (Interrupts are enabled in TCD)
   Dma0::setCallback(dmaChannel, dmaCallback);
   Dma0::enableNvicInterrupts(dmaChannel);

   // Connect DMA channel to UART but throttle by PIT Channel 1 (matches DMA channel 1)
   DmaMux0::configure(dmaChannel, DMA_SLOT, DmaMuxEnable_Continuous);

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
 * Enable DMAC and install error handler
 */
void configureDma() {
   Dma0::configure(
         DmaOnError_Halt,
         DmaMinorLoopMapping_Disabled,
         DmaContinuousLink_Disabled);

   Dma0::setErrorCallback(dmaErrorCallbackFunction);
   Dma0::enableNvicErrorInterrupt();
}

/**
 * 500 ms period
 * Toggle events at 100, 101, 250 and 300 us using DMA
 *
 *                100  101              250       300            500 us
 *  ----------------+  +-----------------+         +-----------------
 *                  |  |                 |         |
 *                  +--+                 +---------+
 *                  1 us      149 us         50 us       200 + 100 us
 */
void configureTimer() {
   // Configure base FTM (affects all channels)
   Timer::configure(
         FtmMode_LeftAlign,      // Left-aligned is required for OC/IC
         FtmClockSource_System); // Bus clock usually

   Timer::setPeriod(500*us);

   // Calculate waveform times in timer ticks
   data[0] = Timer::convertSecondsToTicks(100*us);
   data[1] = Timer::convertSecondsToTicks(101*us);
   data[2] = Timer::convertSecondsToTicks(250*us);
   data[3] = Timer::convertSecondsToTicks(300*us);

   // Enable interrupts for entire timer
   Timer::enableNvicInterrupts();

   // Pin high-drive
   TimerChannel::setOutput(PinDriveStrength_High);

   // Restart counter
   Timer::resetTime();

   // Trigger 1st DMA at last event in table
   TimerChannel::setEventTime(data[3]);

   // Configure the channel
   TimerChannel::configure(
         FtmChMode_OutputCompareToggle, //  Output Compare with pin toggle
         FtmChannelAction_Dma);         //  + DMA on events
}

int main() {

   configureDma();

   configureDmaChannel();

   configureTimer();

   Led::setOutput(PinDriveStrength_High);

   Led::on();

   // Check if configuration failed
   USBDM::checkError();

   for(;;) {
      __asm__("wfi");
   }
}
