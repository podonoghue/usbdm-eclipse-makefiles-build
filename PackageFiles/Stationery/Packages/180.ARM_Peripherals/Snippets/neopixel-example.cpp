/**
 ============================================================================
 * @file    neopixel-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief   Demo using Ftm class to implement a basic driver for a neopixel
 *
 *  Created on: 3/7/2017
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "dma.h"

using namespace USBDM;

/**
 * This example uses DMA interrupts.
 *
 * It is necessary to enable these in Configure.usbdmProject
 * under the "Peripheral Parameters"->DMA0 tab.
 * Select irqHandlingMethod option (Class Method - Software ...)
 */

/** GPIO driving pixel data */
using Pixel = GpioDField<1,0>;

/**
 * FTM Timer being used - change as required
 */
using Timer = Ftm0;

// Timer channels
// These are used to trigger DMA transfers to the PORT registers
using HighChannel = Timer::Channel<1>; //!< PSOR - Sets pin high
using DataChannel = Timer::Channel<2>; //!< PCOR - Set pin low/unchanged according to data
using LowChannel  = Timer::Channel<3>; //!< PCOR - Sets pin low

/** Used to indicate transfer has completed */
static volatile bool complete;

/**
 * DMA complete callback.
 *
 * Sets flag to indicate sequence complete.\n
 * Disables timer channels.
 */
static void dmaCallback(DmaChannelNum channel) {
   Dma0::clearInterruptRequest(channel);
   HighChannel::configure(FtmChMode_Disabled);
   DataChannel::configure(FtmChMode_Disabled);
   LowChannel::configure(FtmChMode_Disabled);
   complete = true;
}

/** Number of strings of pixels. */
//static constexpr unsigned PIXEL_WIDTH  = 1;

/** Number of pixels in a string. */
static constexpr unsigned PIXEL_LENGTH = 2;

/** Number of bits required per pixel. */
static constexpr unsigned PIXEL_BIT_LENGTH = 24;

/**
 * Transmit Data
 */
static uint8_t pixelBuffer[PIXEL_LENGTH*PIXEL_BIT_LENGTH] = {0};

/**
 * Unpack RGB pixel data into format for transmission
 *
 * @param pixelMask  Bit mask for the GPIO driving the pixel string.
 * @param pixelData  Array of RGB data for pixels in string.
 */
void unpackPixels(uint8_t pixelMask, uint32_t pixelData[PIXEL_LENGTH]) {
   uint8_t *pixelBufferPtr = pixelBuffer;
   for (unsigned pixel=0; pixel<PIXEL_LENGTH; pixel++) {
      uint32_t data = pixelData[pixel];

      // Shuffle data RGB => GRB
      data = ((data<<8)&0xFF0000)|((data>>8)&0x00FF00)|(data&0xFF);

      // Unpack into transmission format
      // GGGGGGGGRRRRRRRRBBBBBBBB => bit position in byte
      for (unsigned bitMask=(1<<(PIXEL_BIT_LENGTH-1)); bitMask != 0; bitMask>>=1) {
         if (data & bitMask) {
            *pixelBufferPtr++ |= pixelMask;
         }
         else {
            *pixelBufferPtr++ &= ~pixelMask;
         }
      }
   }
}

/**
 * Configure DMA from Memory-to-GPIO
 */
static void initialiseDma(DmaChannelNum dmaSetChannel, DmaChannelNum dmaDataChannel, DmaChannelNum dmaClearChannel) {

/** Mask corresponding to above GPIO */
static const uint32_t bitmask = Pixel::MASK;

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
    * |..............................|               - ATTR_SMOD, ATTR_DMOD Modulo of the transfer
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
    */

   /**
    * Structure to define the Pin setting DMA transfer
    */
   static constexpr DmaTcd setTCD {
      /* uint32_t  SADDR       Source address              */ (uint32_t)(&bitmask),            // Source = Fixed bit-mask
      /* uint16_t  SOFF        SADDR offset                */ 0,                               // SADDR doesn't advance
      /* DmaSize   DSIZE       Destination size            */ dmaSize(bitmask),                // 32-bit write to SADDR
      /* DmaModulo DMOD        Destination modulo          */ DmaModulo_Disabled,              // No modulo
      /* DmaSize   SSIZE       Source size                 */ dmaSize(bitmask),                // 32-bit read from DADDR
      /* DmaModulo SMOD        Source modulo               */ DmaModulo_Disabled,              // No modulo
      /* uint32_t  NBYTES      Minor loop byte count       */ sizeof(bitmask),                 // Total transfer in one minor-loop
      /* uint32_t  SLAST       Last SADDR adjustment       */ 0,                               // SADDR doesn't change
      /* uint32_t  DADDR       Destination address         */ Pixel::gpioPSOR(),               // Destination is GPIO.PSOR register
      /* uint16_t  DOFF        DADDR offset                */ 0,                               // DADDR doesn't change
      /* uint16_t  CITER       Major loop count            */ DMA_CITER_ELINKNO_ELINK(0)|      // No ELINK
      /*                                                   */ ((sizeof(pixelBuffer))/
                                                                sizeof(pixelBuffer[0])),       // Transfer count matches entire pixelBuffer
      /* uint32_t  DLAST       Last DADDR adjustment       */ 0,                               // DADDR doesn't change
      /* bool      START       Channel Start               */ false,                           // Don't start (triggered by hardware)
      /* bool      INTMAJOR    Interrupt on major complete */ false,                           // Disabled
      /* bool      INTHALF     Interrupt on half complete  */ false,                           // Disabled
      /* bool      DREQ        Disable Request             */ true,                            // Clear hardware request when complete major loop
      /* bool      ESG         Enable Scatter/Gather       */ false,                           // Disabled
      /* bool      MAJORELINK  Enable channel linking      */ false,                           // Disabled
      /* bool      ACTIVE      Channel Active              */ false,
      /* bool      DONE        Channel Done                */ false,
      /* unsigned  MAJORLINKCH Link Channel Number         */ 0,                               // N/A
      /* DmaSpeed  BWC         Bandwidth (speed) Control   */ DmaSpeed_NoStalls,               // Full speed
   };

   /**
    * Structure to define the Pin data DMA transfer
    */
   static constexpr DmaTcd dataTCD {
      /* uint32_t  SADDR       Source address              */ (uint32_t)(pixelBuffer),         // Source = Fixed bit-mask
      /* uint16_t  SOFF        SADDR offset                */ sizeof(pixelBuffer[0]),          // SADDR advances
      /* DmaSize   DSIZE       Destination size            */ dmaSize(pixelBuffer[0]),         // 32-bit write to SADDR
      /* DmaModulo DMOD        Destination modulo          */ DmaModulo_Disabled,              // No modulo
      /* DmaSize   SSIZE       Source size                 */ dmaSize(pixelBuffer[0]),         // 32-bit read from DADDR
      /* DmaModulo SMOD        Source modulo               */ DmaModulo_Disabled,              // No modulo
      /* uint32_t  NBYTES      Minor loop byte count       */ sizeof(pixelBuffer[0]),          // Total transfer in one minor-loop
      /* uint32_t  SLAST       Last SADDR adjustment       */ -sizeof(pixelBuffer),            // Reset SADDR back to start of buffer
      /* uint32_t  DADDR       Destination address         */ Pixel::gpioPCOR(),               // Destination is GPIO.PCOR register
      /* uint16_t  DOFF        DADDR offset                */ 0,                               // DADDR doesn't change
      /* uint16_t  CITER       Major loop count            */ DMA_CITER_ELINKNO_ELINK(0)|      // No ELINK
      /*                                                   */ ((sizeof(pixelBuffer))/
                                                                sizeof(pixelBuffer[0])),       // Transfer count matches entire pixelBuffer
      /* uint32_t  DLAST       Last DADDR adjustment       */ 0,                               // DADDR doesn't change
      /* bool      START       Channel Start               */ false,                           // Don't start (triggered by hardware)
      /* bool      INTMAJOR    Interrupt on major complete */ false,                           // Disabled
      /* bool      INTHALF     Interrupt on half complete  */ false,                           // Disabled
      /* bool      DREQ        Disable Request             */ true,                            // Clear hardware request when complete major loop
      /* bool      ESG         Enable Scatter/Gather       */ false,                           // Disabled
      /* bool      MAJORELINK  Enable channel linking      */ false,                           // Disabled
      /* bool      ACTIVE      Channel Active              */ false,
      /* bool      DONE        Channel Done                */ false,
      /* unsigned  MAJORLINKCH Link Channel Number         */ 0,                               // N/A
      /* DmaSpeed  BWC         Bandwidth (speed) Control   */ DmaSpeed_NoStalls,               // Full speed
   };

   /**
    * Structure to define the Pin clearing DMA transfer
    */
   static constexpr DmaTcd clearTCD {
      /* uint32_t  SADDR       Source address              */ (uint32_t)(&bitmask),            // Source = Fixed bit-mask
      /* uint16_t  SOFF        SADDR offset                */ 0,                               // SADDR doesn't advance
      /* DmaSize   DSIZE       Destination size            */ dmaSize(bitmask),                // 32-bit write to SADDR
      /* DmaModulo DMOD        Destination modulo          */ DmaModulo_Disabled,              // No modulo
      /* DmaSize   SSIZE       Source size                 */ dmaSize(bitmask),                // 32-bit read from DADDR
      /* DmaModulo SMOD        Source modulo               */ DmaModulo_Disabled,              // No modulo
      /* uint32_t  NBYTES      Minor loop byte count       */ sizeof(bitmask),                 // Total transfer in one minor-loop
      /* uint32_t  SLAST       Last SADDR adjustment       */ 0,                               // SADDR doesn't change
      /* uint32_t  DADDR       Destination address         */ Pixel::gpioPCOR(),               // Destination is GPIO.PCOR register
      /* uint16_t  DOFF        DADDR offset                */ 0,                               // DADDR doesn't change
      /* uint16_t  CITER       Major loop count            */ DMA_CITER_ELINKNO_ELINK(0)|      // No ELINK
      /*                                                   */ ((sizeof(pixelBuffer))/
                                                                sizeof(pixelBuffer[0])),       // Transfer count matches entire pixelBuffer
      /* uint32_t  DLAST       Last DADDR adjustment       */ 0,                               // DADDR doesn't change
      /* bool      START       Channel Start               */ false,                           // Don't start (triggered by hardware)
      /* bool      INTMAJOR    Interrupt on major complete */ true,                            // Generate interrupt on completion of Major-loop
      /* bool      INTHALF     Interrupt on half complete  */ false,                           // Disabled
      /* bool      DREQ        Disable Request             */ true,                            // Clear hardware request when complete major loop
      /* bool      ESG         Enable Scatter/Gather       */ false,                           // Disabled
      /* bool      MAJORELINK  Enable channel linking      */ false,                           // Disabled
      /* bool      ACTIVE      Channel Active              */ false,
      /* bool      DONE        Channel Done                */ false,
      /* unsigned  MAJORLINKCH Link Channel Number         */ 0,                               // N/A
      /* DmaSpeed  BWC         Bandwidth (speed) Control   */ DmaSpeed_NoStalls,               // Full speed
   };

   // Enable DMAC with default settings
   Dma0::configure();

   // Set callback (Interrupts are enabled in TCD)
   Dma0::setCallback(dmaClearChannel, dmaCallback);
   Dma0::enableNvicInterrupts(dmaClearChannel);

   // Connect DMA channels FTM
   DmaMux0::configure(dmaSetChannel,   Dma0Slot_FTM0_Ch1, DmaMuxEnable_Continuous);
   DmaMux0::configure(dmaDataChannel,  Dma0Slot_FTM0_Ch2, DmaMuxEnable_Continuous);
   DmaMux0::configure(dmaClearChannel, Dma0Slot_FTM0_Ch3, DmaMuxEnable_Continuous);

   // Configure the DMA transfers
   Dma0::configureTransfer(dmaSetChannel,   setTCD);
   Dma0::configureTransfer(dmaDataChannel,  dataTCD);
   Dma0::configureTransfer(dmaClearChannel, clearTCD);

   // Check if configuration failed
   checkError();
}

/*
 * FTM       Set       Clear/None     Clear
 * Channels  (1)          (2)          (3)
 *            |            |            |
 *            V            V            V
 *            +------------+                         +--
 *    0 =>    |  T0_HIGH   |       T0_LOW            |
 *          --+            +-------------------------+
 *            +-------------------------+            +--
 *    1 =>    |       T1_HIGH           |  T1_LOW    |
 *          --+                         +------------+
 *            |<-------------- Period -------------->|
 */
static constexpr float T0_HIGH = 500*us;
static constexpr float T1_HIGH = 700*us;
static constexpr float PERIOD  = 1200*us;

/**
 * Start transfer
 */
static void startTransfer(DmaChannelNum dmaSetChannel, DmaChannelNum dmaDataChannel, DmaChannelNum dmaClearChannel) {
   // Sequence not complete yet
   complete = false;

   uint32_t dmaChannelMask = (1<<dmaSetChannel)|(1<<dmaDataChannel)|(1<<dmaClearChannel);
   uint32_t ftmChannelMask = HighChannel::CHANNEL_MASK|DataChannel::CHANNEL_MASK|LowChannel::CHANNEL_MASK;

   // Clear FTM timer count and channel flags
   Ftm0::resetTime();
   Ftm0::clearSelectedInterruptFlags(ftmChannelMask);

   // Configure the channels
   HighChannel::configure(FtmChMode_OutputCompareToggle, FtmChannelAction_Dma);
   DataChannel::configure(FtmChMode_OutputCompare, FtmChannelAction_Dma);
   LowChannel::configure(FtmChMode_OutputCompare, FtmChannelAction_Dma);

   // Enable timer hardware requests
   Dma0::enableMultipleRequests(dmaChannelMask);
}

static void initialiseFtm() {
   /**
    * FTM set up for as required for Output Compare
    */
   // Configure base FTM (affects all channels)
   Timer::configure(
         FtmMode_LeftAlign,      // Left-aligned is required for OC/IC
         FtmClockSource_System); // Disabled clock initially during setup

   // Set period
   // This adjusts the prescaler and modulo values but does not change the clock source
   Timer::setPeriod(PERIOD, true);

//   // Configure pins associated with channels
   HighChannel::setOutput();
//   DataChannel::setOutput();
//   LowChannel::setOutput();

   // Configure the channels - no DMA
   HighChannel::configure(FtmChMode_OutputCompare, FtmChannelAction_None);
   DataChannel::configure(FtmChMode_OutputCompare, FtmChannelAction_None);
   LowChannel::configure(FtmChMode_OutputCompare, FtmChannelAction_None);

   // Set channel event times
   uint32_t offset = Timer::convertSecondsToTicks(100*us);
   HighChannel::setEventTime(offset);
   DataChannel::setEventTime(offset+Timer::convertSecondsToTicks(T0_HIGH));
   LowChannel::setEventTime(offset+Timer::convertSecondsToTicks(T1_HIGH));

   // Check if configuration failed
   checkError();
}

/**
 * Initialise the GPIO pins driving the Neopixel
 */
void initialisePins() {
   Pixel::setOutput(PinDriveStrength_High);
}

/**
 * Demonstration main-line
 *
 * @return Not used.
 */
int main() {

   console.write("gpioBase    = ").writeln(Pixel::gpioBase(), Radix_16);
   console.write("gpioPSOR    = ").writeln(Pixel::gpioPSOR(), Radix_16);
   console.write("portBase    = ").writeln(Pixel::portBase(), Radix_16);
   console.write("portPCRs(3) = ").writeln(Pixel::portPCR(3), Radix_16);
   console.write("portGPCHR   = ").writeln(Pixel::portGPCHR(), Radix_16);

   initialisePins();

   initialiseFtm();

   initialiseDma(DmaChannelNum_0, DmaChannelNum_1, DmaChannelNum_2);

   uint32_t pixel0Data[PIXEL_LENGTH] = { 0x341256, 0x221133, };
   unpackPixels(Pixel::mask(0), pixel0Data);

   uint32_t pixel1Data[PIXEL_LENGTH] = { 0xFF00FF, 0x00FF00, };
   unpackPixels(Pixel::mask(1), pixel1Data);

   // Wait here forever
   for(;;) {
      console.writeln("Starting Transfer");

      // Start transfer
      startTransfer(DmaChannelNum_0, DmaChannelNum_1, DmaChannelNum_2);

      // Wait for completion of 1 Major-loop = 1 pixelBuffer
      while (!complete) {
         __asm__("nop");
      }
      console.writeln("Transfer complete");

      waitMS(100);
   }
   return 0;
}
