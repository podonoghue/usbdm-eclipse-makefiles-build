/*
 ============================================================================
 * @file    pit-adc-dma-example.cpp (180.ARM_Peripherals/Snippets/)
 * @brief   PIT trigger ADC triggers DMA
 *
 *  Created on: 10/7/2017
 *      Author: podonoghue
 ============================================================================
 */
#include <string.h> // memset()
#include "hardware.h"
#include "pit.h"
#include "dma.h"
#include "adc.h"

using namespace USBDM;

// Connection - change as required
using Led          = RGB_Green;     //GpioA<2,  ActiveLow>;
using Pwm          = Timer_D7;      //Ftm0::Channel<0>;
using MyAdcChannel = Analogue_A0;   //Adc0::Channel<AdcChannelNum_3>
using MyTmrChannel = Pit::Channel<0>;

// DMA channel number to use
static constexpr DmaChannelNum DMA_CHANNEL = DmaChannelNum_1;
static constexpr Dma0IrqNum    DMA_IRQNUM  = Dma0IrqNum_Ch1;

/**
 * This example used the PIT to trigger 100 ADC conversions @1ms interval.
 * Each conversion result is captured by the DMAC and transferred to memory.
 *
 * +------------+     +-----------+     +----------+     +----------+
 * |            |     |           |     |          |     |          |
 * |    PIT     | ==> |    ADC    | ==> |   DMAC   | ==> |  Memory  |
 * |            |     |           |     |          |     |          |
 * +------------+     +-----------+     +----------+     +----------+
 *
 * Requires:
 *  DMAx_IRQHandler
 *  PITx_IRQHandler
 *  ADCx_IRQHandler
 *
 *  Use external link from PWM (FTM) output to ADC channel input for changing input to acquire
 */

/**
 * Configure the ADC
 * - Triggered by the PIT
 * - Results retrieved by the DMAC
 */
static void configureAdc() {

   // Configure ADC + channel
   static const MyAdcChannel::Owner::Init adcInit {
      AdcResolution_16bit_se,       // Resolution
      AdcAveraging_16,              // Set averaging to reduce noise
      AdcTrigger_Hardware,          // Use hardware trigger
      AdcPretrigger_0,              // Set up pretriggerA to use given channel with interrupt
      MyAdcChannel::CHANNEL,
      AdcAction_None,
      AdcDma_Enabled,               // Use DMA for results
      AdcClockSource_Asynch,        // Use async (internal) clock
   };
   MyAdcChannel::Owner::configure(adcInit);

   // Connect channel to pin
   MyAdcChannel::setInput();

   // Connect ADC trigger 0 (SCA) to PIT channel 0
   // Note ADC trigger number and Pit channel must agree with definitions
   static const SimInfo::AdcHardwareTriggerInit adcTriggerInit {
      SimAdc0TriggerMode_Alt_PreTrigger_0, SimAdc0TriggerSrc_PitCh0
   };
   SimInfo::configure(adcTriggerInit);

   // Check for errors so far
   checkError();
}

// Flag to indicate transfer complete
bool complete;

/**
 * DMA complete callback
 *
 * Sets flag to indicate sequence complete.
 * Stops PIT generating events
 * Clears DMA IRQ
 */
void dmaCallback() {

   // Assume individual channel call-backs so no need to check IRQ source

   // Clear status
   Dma0::clearInterruptRequest(DMA_CHANNEL);

   // Clear LED for debug
   Led::off();

   // Flag complete to main-line
   complete = true;
}

static std::array<uint16_t, 100> buffer  = {1,2,3,4,5,6,7,8,9};

/**
 * Configure the DMA
 * - Triggered by the ADC
 * - Transfers results from the ADC to memory buffer
 */
static void configureDma() {

   /*
    * Structure to define a DMA transfer
    *
    * Each DMA request trigger causes a minor-loop transfer sequence.
    * The minor loops are counted in the major-loop.
    *
    * The following are used during a minor loop:
    *  - SADDR Source address
    *  - SOFF  Adjustment applied to SADDR after each transfer
    *  - DADDR Destination address
    *  - DOFF  Adjustment applied to DADDR after each transfer
    *  - NBYTES Number of bytes to transfer
    *  - Attributes
    *    - ATTR_SSIZE, ATTR_DSIZE Source and destination transfer sizes
    *    - ATTR_SMOD, ATTR_DMOD Modulo
    *
    * The following are used by the major loop
    *  - SLAST Adjustment applied to SADDR after each major loop - can be used to reset the SADDR for next major loop
    *  - DLAST Adjustment applied to DADDR after each major loop - can be used to reset the DADDR for next major loop
    *  - CITER Major loop counter - counts major loops
    */
   /**
    * Structure to define the Transmit DMA transfer
    */
   static const DmaTcd tcd {
      DmaInfo {
      /* Source address                 */ MyAdcChannel::Owner::adcR(0),   // ADC result register
      /* Source offset                  */ 0,                              // SADDR does not change
      /* Source size                    */ dmaSize(buffer[0]),             // 16-bit read from ADR->R (ignores MSBs) must match buffer
      /* Last source adjustment         */ 0,                              // No adjustment as SADDR is unchanged
      /* Source modulo                  */ DmaModulo_Disabled,             // Disabled
      },
      DmaInfo {
      /* Destination address            */ uint32_t(&buffer),              // Start of array for result
      /* Destination offset             */ sizeof(buffer[0]),              // DADDR advances size of element for each request
      /* Destination size               */ dmaSize(buffer[0]),             // 16-bit write to array
      /* Last destination adjustment    */ -int(sizeof(buffer)),           // Reset DADDR to start of array on completion
      /* Destination modulo             */ DmaModulo_Disabled,             // Disabled
      },
      /* Minor loop byte count          */ dmaNBytes(sizeof(buffer[0])),   // 2-bytes for each ADC DMA request
      /* Major loop count               */ dmaCiter(buffer.size()),        // Number of requests to do for entire buffer
      DmaTcdCsr {
      /* Disable Req. on major complete */ DmaStopOnComplete_Enabled,      // Clear hardware request when major loop completed
      /* Interrupt on major complete    */ DmaIntMajor_Enabled,            // Interrupt on completion
      /* Start channel                  */ DmaStart_Hardware,              // Don't start (triggered by hardware)
      },
   };

   // Sequence not complete yet
   complete = false;

   // Enable DMAC with default settings
   Dma0::defaultConfigure();

   // Set callback for end of transfer
   Dma0::setCallback(DMA_IRQNUM, dmaCallback);

   // Enable interrupts in NVIC
   Dma0::enableNvicInterrupts(DMA_IRQNUM);

   // Configure the transfer
   Dma0::configureTransfer(DMA_CHANNEL, tcd);

   // DMA triggered by ADC requests (continuous = whenever ADC wants)
   Dmamux0::configure(DMA_CHANNEL, Dma0Slot_ADC0, DmamuxMode_Continuous);

   // Check for errors so far
   checkError();
}

/**
 * PIT callback
 *
 * Used for debug timing checks.
 * LED toggles on each PIT event
 */
void pitCallback() {
   Led::toggle();
}

/*
 * Configure the PIT
 * - Generates regular events at 1ms interval. Each event is used to initiate an ADC conversions.
 */
void configurePit() {
   // Configure base PIT
   Pit::defaultConfigure();

   // Configure channel
   static constexpr MyTmrChannel::ChannelInit channelInit {
      PitChannelEnable_Enabled , // (pit_tctrl_ten[0]) Timer Channel Enable - Channel enabled
      PitChannelAction_Interrupt , // (pit_tctrl_tie[0]) Action on timer event - Interrupt
      1_ms , // (pit_ldval_tsv[0]) Reload value channel 0
      NvicPriority_Normal,  // (irqLevel_Ch0) IRQ priority level for Ch0 - Normal
      pitCallback,
      };
   MyTmrChannel::configure(channelInit);
   MyTmrChannel::enableNvicInterrupts(NvicPriority_Normal);

   // Check for errors so far
   checkError();
}

/**
 * Configures a timer as a 10ms Square wave output to
 * use as measurement input for the ADC.
 */
void createWaveform() {

   static const Pwm::OwningFtm::Init init {
      FtmCountMode_LeftAligned ,    // (ftm_sc_cpwms) Counting mode - Left-aligned (count up)
      FtmClockSource_SystemClock ,  // (ftm_sc_clks) Clock Source - System clock
      10.0_ms ,                     // (ftm_deadtime_dtval) Dead-time Value
   };
   Pwm::OwningFtm::configure(init);
   Pwm::OwningFtm::ChannelInit channelInit {
      FtmChannelMode_PwmHighTruePulses ,           // (ftm_cnsc_mode_independent[0]) Channel Mode - Pwm High-true Pulses (Edge/Centre)
      FtmChannelAction_None ,                      // (ftm_cnsc_action_independent[0]) Action on Channel Event - No action
      Pwm::OwningFtm::convertSecondsToTicks(5_ms), // (ftm_cnv_independent[0]) Output Compare Event time in ticks
      FtmInputFilter_Disabled,                     // (ftm_filter_fval_independent[0]) Channel Input Filter - Filter Disabled
   };
   Pwm::configure(channelInit);
   Pwm::setOutput();
}

/**
 * Do 100 ADC conversions @1ms interval into memory buffer
 */
void setupTransfers() {
   // Clear buffer initially
   buffer.fill(0xA5);

   configureDma();
   configureAdc();
   configurePit();
}

/**
 * Do 100 ADC conversions @1ms interval into memory buffer
 */
void testHardwareConversions() {

   complete = false;

   // Enable DMA requests from the channel
   Dma0::enableRequest(DMA_CHANNEL);

   while (!complete) {
      __asm__("nop");
   }

   console.writeln("Completed Transfer\nResults:");
   static const IntegerFormat format {
      Padding_LeadingSpaces,
      Width_5,
   };

   console.setFormat(format);
   for (unsigned index=0; index<(sizeof(buffer)/sizeof(buffer[0]));) {
      console.write(index).write(": ");
      for (int row=0; row<10; row++, index++) {
         console.write(buffer[index]).write(", ");
      }
      console.writeln();
   }
   console.resetIntegerFormat();
}

int main() {
   console.writeln("\n\nStarting");

   // Debug LED
   Led::setOutput();

   createWaveform();

   setupTransfers();

   for(;;) {
      waitMS(500);
      testHardwareConversions();
   }
   return 0;
}
