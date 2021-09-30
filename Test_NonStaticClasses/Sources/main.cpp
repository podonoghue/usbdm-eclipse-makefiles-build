/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main.cpp)
 * @brief   Basic C++ demo
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "hardware.h"
#include "cmp.h"
#include "crc.h"
#include "dac.h"
#include "dma.h"
#include "ewm.h"
#include "llwu.h"
#include "lptmr.h"
#include "lpuart.h"
#include "pdb.h"
#include "pit.h"
#include "pmc.h"
#include "rcm.h"
#include "rnga.h"
#include "rtc.h"
#include "smc.h"
//#include "usb.h"
#include "vref.h"
#include "wdog.h"


// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

using Led  = GpioD<5,ActiveLow>;
static const Led  led;

using Leds = GpioAField<2,1, ActiveLow>;
static const Leds leds;

using Adc             = Adc0;
using AdcChannelX     = Adc::Channel<0>;
using AdcDiffChannelX = Adc::DiffChannel<0>;

static const AdcChannelX       adcChannel;
static const AdcDiffChannelX   adcDiffChannel;

using Cmp = Cmp0;
using Crc = Crc0;
using Dac = Dac0;

using TimerChannel = Pit::Channel<3>;
const TimerChannel timerChannel;

void doGpio(const Gpio &gpio, const GpioField &gpioField) {
   gpio.toggle();
   gpio.setIn();
   gpio.setOut();
   gpioField.bitToggle(0b11);
   gpioField.setIn();
   gpioField.setOut();
   gpioField.setDirection(0b10);
}

void doAdc(const AdcChannel &adcChannel, const AdcDiffChannel &adcDiffChannel) {
   adcChannel.readAnalogue();
   adcDiffChannel.readAnalogue();
   adcChannel.startConversion(AdcInterrupt_Disabled);
   adcChannel.enableHardwareConversion(AdcPretrigger_0, AdcInterrupt_Disabled);
   adcChannel.enableHardwareConversion(AdcPretrigger_0, AdcInterrupt_Disabled, AdcDma_Disabled);
   adcDiffChannel.startConversion(AdcInterrupt_Disabled);
   adcDiffChannel.enableHardwareConversion(AdcPretrigger_0, AdcInterrupt_Disabled);
   adcDiffChannel.enableHardwareConversion(AdcPretrigger_0, AdcInterrupt_Disabled, AdcDma_Disabled);
}

void doPit(const Pit::PitChannel &timerChannel) {
   timerChannel.configure(0.3, PitChannelIrq_Enabled);
   auto cb = []() {
      console.writeln("Callback");
   };
   timerChannel.setCallback(cb);
   timerChannel.enableNvicInterrupts(NvicPriority_Normal);
}

using Adc = Adc0;

int main() {
   console.writeln("Starting\n");
   console.write("SystemCoreClock   = ").writeln(SystemCoreClock);
   console.write("SystemBusClock    = ").writeln(SystemBusClock);
   console.write("&(led)            = ").writeln(&(led));
   console.write("&(leds)           = ").writeln(&(leds));
   console.write("&(adcChannel)     = ").writeln(&(adcChannel));
   console.write("&(adcDiffChannel) = ").writeln(&(adcDiffChannel));

   led.setOutput();
   leds.setOutput();

   Adc::configure(AdcResolution_12bit_se);
   AdcChannelX::setInput();

   Pit::configureIfNeeded();
   timerChannel.configure(1.315, PitChannelIrq_Disabled);

   doGpio(led, leds);
   doAdc(adcChannel, adcDiffChannel);
   doPit(timerChannel);

   adcChannel.disablePin();
   Ftm0::Channel<3>::disablePin();

   for(int count = 0;;count++) {
      led.toggle();
      led.setIn();
      led.setOut();
      leds.bitSet(0b10);
      leds.setIn();
      leds.setOut();
      leds.setDirection(0b10);

      waitMS(100);
      CriticalSection cs;
      console.write(count).writeln(": Tick...");
   }
   led.disablePin();
   leds.disablePins();

   return 0;
}
