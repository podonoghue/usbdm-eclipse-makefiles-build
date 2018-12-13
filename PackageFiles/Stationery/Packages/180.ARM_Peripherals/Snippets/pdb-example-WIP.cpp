/**
 ============================================================================
 * @file   pdb-example-WIP.cpp (180.ARM_Peripherals/Snippets/)
 * @brief  Basic C++ Programmable Delay Block (PDB) Example
 *
 *  Created on: 10/7/2017
 *      Author: podonoghue
 ============================================================================
 */
/*
 * This example uses PDB software trigger to schedule an ADC conversion
 * Uses an LED for debug timing check.
 *
 * Note - Requires ADC and PDB interrupt handlers to be installed.
 */
#include "hardware.h"
#include "pit.h"
#include "pdb.h"
#include "lptmr.h"
#include "dma.h"

using namespace USBDM;

// Connection - change as required
using Led         = GpioA<2, ActiveLow>;  // = PTA2 = D9 = Blue LED
using Lptmr       = Lptmr0;
using Pdb         = Pdb0;
using Ftm         = Ftm0;
using FtmChannel  = Ftm0Channel<7>;       // = PTD7 = D22
using Adc         = Adc0;
using AdcChannelA = Adc0Channel<0>;
using AdcChannelB = Adc0Channel<3>;

#if 0
void lptmrCallback() {
   //   Led::toggle();
   Led::clear();
   Led::set();
   Led::clear();
}

void configureLptmr() {

   // Enable LPTMR in time counting mode
   Lptmr::setTimeCountingMode(LptmrResetOn_Compare);
   // Set clock source
   Lptmr::setClock(LptmrClockSel_Erclk32, LptmrPrescale_1024);
   // Set period of timer event
   Lptmr::setPeriod(PERIOD);

   // Set callback
   Lptmr::setCallback(lptmrCallback);
   Lptmr::enableInterrupts();
}
#endif

static void ftmCallback(uint8_t) {
   Led::clear();
}

static constexpr float PERIOD        = 10*ms;
static constexpr float HIGH_TIME     =  5*ms;
static constexpr float SAMPLE_DELAY  = 10*us;

static void configureFtm() {

   Ftm::configure(FtmMode_LeftAlign);

   Ftm::enable();
   Ftm::setClockSource(FtmClockSource_System);
   Ftm::setMode(FtmMode_LeftAlign);
   Ftm::setPeriod(PERIOD);
   Ftm::enableExternalTrigger(FtmExternalTrigger_init);
   Ftm::setChannelCallback(ftmCallback);

   FtmChannel::setDriveStrength(PinDriveStrength_High);
   FtmChannel::configure(FtmChMode_PwmHighTruePulses, FtmChannelAction_Irq);
   FtmChannel::setHighTime(HIGH_TIME);
   Ftm::enableNvicInterrupts();
   //   FtmChannel::enableInterrupts();

   // Check if configuration failed
   USBDM::checkError();
}

static int      resultIndex=0;
static uint32_t results[2];

/**
 * Handler for PDB sequence error
 */
static void pdbErrorCallback() {
#ifdef DEBUG_BUILD
   __BKPT();
#endif

   Pdb::clearErrorFlags(0);
   Pdb::clearErrorFlags(1);
}

/**
 * Handler for usual PDB interrupt
 */
static void pdbCallback() {
   resultIndex = 0;
   Led::clear();
}

static void configurePdb() {

   // Note: Can work in timer ticks and avoid floating point if desired
   //   Pdb::setClock(PdbPrescale_128, PdbMultiplier_10);
   //   Pdb::setModulo(1000);
   //   Pdb::setInterruptDelayInTicks(1000);
   //   Pdb::setPretriggersInTicks(0, PdbPretrigger0_Delayed, 450, PdbPretrigger1_Delayed, 550);

   Pdb::enable();
   // Trigger from FTM
   Pdb::setTriggerSource(PdbTrigger_Ftm0);
   // Set call-backs
   Pdb::setErrorCallback(pdbErrorCallback);
   Pdb::setCallback(pdbCallback);
   // Interrupts during sequence or error
   Pdb::setActions(PdbAction_Interrupt, PdbErrorInterrupt_Enabled);

   // Set period a bit longer than FTM period
   Pdb::setPeriod(PERIOD+1*ms);
   // Generate interrupt at end of sequence
   Pdb::setInterruptDelay(PERIOD);
   // Take ADC samples before and after FTM edge
   Pdb::configureAdcPretrigger(0, 0, PdbPretrigger_Delayed, HIGH_TIME-SAMPLE_DELAY);
   Pdb::configureAdcPretrigger(0, 1, PdbPretrigger_Delayed, HIGH_TIME+SAMPLE_DELAY);
   // Update registers
   Pdb::configureRegisterLoad(PdbLoadMode_Immediate);

   Pdb::enableNvicInterrupts();

   //   Pdb::softwareTrigger();

   //   while (!Pdb::isRegisterLoadComplete()) {
   //      __asm__("nop");
   //   }
}

/**
 * Used for debug timing checks
 */
void adcCallback(uint32_t value, int channel) {
   Led::set();
   //   results[resultIndex++] = value;
   if (channel == AdcChannelA::CHANNEL) {
      results[0] = value;
   }
   else if (channel == AdcChannelB::CHANNEL) {
      results[1] = value;
   }
   Led::toggle();
}

/**
 * Configure the ADC
 * - Triggered by the PDB
 * - Results retrieved by the DMAC
 */
static void configureAdc() {

   // Enable and configure ADC
   Adc::configure(AdcResolution_16bit_se);

   // Calibrate before use
   Adc::calibrate();

   Adc::setCallback(adcCallback);
   Adc::enableNvicInterrupts();

   // Configure the ADC to use hardware with trigger 0 & 1 + interrupts
   AdcChannelA::enableHardwareConversion(AdcPretrigger_0, AdcInterrupt_Enabled);
   AdcChannelB::enableHardwareConversion(AdcPretrigger_1, AdcInterrupt_Enabled);

   // Connect ADC trigger A to usual PDB
   SimInfo::setAdc0Triggers(SimAdc0TriggerMode_Pdb);

   // Check for errors so far
   checkError();
}

// Flag to indicate transfer complete
bool complete;

/**
 * DMA complete callback
 *
 * Sets flag to indicate sequence complete.
 */
void dmaCallback(DmaChannelNum) {
   // Clear LED for debug
   Led::off();
   Pdb::disable();
   complete = true;
}

uint8_t sourceData[] = {1,2,3,4,5,6,7};
uint8_t destinationData[2*sizeof(sourceData)/sizeof(sourceData[0])];

/**
 * Configure the DMA
 * - Triggered by the ADC
 * - Transfers results from the ADC to memory buffer
 */
static void configureDma() {

   // DMA channel number to use
   static constexpr DmaChannelNum DMA_CHANNEL = DmaChannelNum_1;

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
    *    - ATTR_SMOD, ATTR_DMOD Modulo --TODO
    *
    * The following are used by the major loop
    *  - SLAST Adjustment applied to SADDR after each major loop - can be used to reset the SADDR for next major loop
    *  - DLAST Adjustment applied to DADDR after each major loop - can be used to reset the DADDR for next major loop
    *  - CITER Major loop counter - counts major loops
    */
   static const DmaTcd tcd (
      /* Source address              */ Adc::adcR(0),                       // ADC result register
      /* Source offset               */ 0,                                  // SADDR does not change
	  /* Source size                 */ DmaSize_16bit,                      // 16-bit read from ADR->R (ignores MSBs)
	  /* Source modulo               */ DmaModulo_Disabled,
      /* Source last adjustment      */ 0,                                  // No adjustment as SADDR was unchanged

      /* Destination address         */ (uint32_t)(&results),               // Start of array for result
      /* Destination offset          */ sizeof(results[0]),                 // DADDR advances 2 bytes for each request
	  /* Destination size            */ DmaSize_16bit,                      // 16-bit read from ADR->R (ignores MSBs)
      /* Destination modulo          */ DmaModulo_Disabled,                      // 16-bit write to array
      /* Destination last adjustment */ -(int)sizeof(results),                   // Reset DADDR to start of array on completion

      /* Minor loop byte count       */ 2,                                  // 2-bytes for each ADC DMA request
      /* Major loop count            */ sizeof(results)/sizeof(results[0]), // Number of requests to do

	  /* Start Channel               */ false,
	  /* Disable req. on complete    */ true,                               // Stop transfer on completion of Major-loop
	  /* Interrupt On Complete 	     */ true                                // Generate interrupt on completion of Major-loop
   );

   // Configure the transfer
   DmaMux0::disable(DMA_CHANNEL);
   DmaMux0::configure(DMA_CHANNEL, Dma0Slot_ADC0, DmaMuxEnable_Continuous);
   Dma0::configureTransfer(DMA_CHANNEL, tcd);

//   Dma0::waitUntilComplete(DMA_CHANNEL);
   Dma0::enableNvicInterrupts(DMA_CHANNEL);
   Dma0::setCallback(DMA_CHANNEL, dmaCallback);


//   DmaMux0::configure(DMA_CHANNEL, DmaMux0::DmaSlot_AlwaysEnabled0, DmaMuxEnable_Continuous);
//   DmaMux0::configure(DMA_CHANNEL, DmaMux0::DmaSlot_AlwaysEnabled0, DmaMuxEnable_Disabled);
//   DmaMux0::configure(DMA_CHANNEL, DmaMux0::DmaSlot_AlwaysEnabled0, DmaMuxEnable_triggered);
//   DmaMux0::disable(DMA_CHANNEL);
//   DmaMux0::configure(15, DmaMux0::DmaSlot_AlwaysEnabled0, DmaMuxEnable_continuous);


//   DmaChannel_T::configure(DMA_CHANNEL,2,&info);
//   DmaChannel_T::enableRequests(DMA_CHANNEL, Dmamux0Info::DMA0_SLOT_FTM0_Ch_0, DmaMuxEnable_continuous);
//   DmaChannel_T::waitUntilComplete(DMA_CHANNEL);
}

int main() {
   printf("Starting\n");

   Led::setOutput();

   configureAdc();
//   configureFtm();
   //   configureLptmr();
//   configurePdb();
   configureDma();

   for(;;) {
      printf("ch1=%6lu, ch2=%6lu\n", results[0], results[1]);
      __asm__("nop");
      //      __WFI();
   }
   return 0;
}
