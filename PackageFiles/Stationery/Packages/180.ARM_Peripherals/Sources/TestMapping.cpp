/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main.cpp)
 * @brief   Basic C++ demo using GPIO class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "system.h"
#include "derivative.h"
#include "hardware.h"

/**
 * See more examples in Snippets directory
 *
 * Using a adcFixedPin channel
 *  using adcChannel = USBDM::Adc0Channel<6>;
 *  adcChannel::enable();
 *  adcChannel::setResolution(USBDM::AdcResolution_16bit_se);
 *  adcChannel::setAveraging(USBDM::averaging_32);
 *  int value = adcChannel::readAnalogue();
 * 
 * Using a timer channel
 *  using ftmChannel = USBDM::Ftm0Channel<0>;
 *  ftmChannel::configure(1000, USBDM::ftm_leftAlign);
 *  ftmChannel::setDutyCycle(25);
 */

// LED connection - change as required
using Led   = USBDM::GpioA<2, USBDM::ActiveLow>;

using pin = USBDM::gpio_D0;

using adcFixedPin     = USBDM::Adc0Channel<0>;
using adcDiffFixedPin = USBDM::Adc0DiffChannel<0>;
using adcMappedPin    = USBDM::Adc0Channel<6>;
using adcUnMappedPin  = USBDM::Adc0Channel<4>;
using adcInvalidPin   = USBDM::Adc0Channel<1>;

using gpioPinOK1 = USBDM::GpioB<0>;
using gpioPinOK2 = USBDM::GpioB<31>;
using gpioIllegalPin1 = USBDM::GpioB<-1>;
using gpioIllegalPin2 = USBDM::GpioB<32>;

int main() {
   printf("Starting\n");
   pin::setInput(USBDM::PinPull_Up, USBDM::PinAction_None, USBDM::PinFilter_Passive);
   Led::setOutput();

   adcFixedPin::enable();
   using adcFixedPinPcr = USBDM::PcrTable_T<USBDM::Adc0Info,0>;
   adcFixedPinPcr::setPCR(USBDM::PinPull_Up);

   adcMappedPin::enable();
   using adcMappedPinPcr = USBDM::PcrTable_T<USBDM::Adc0Info,6>;
   adcMappedPinPcr::setPCR(USBDM::PinPull_Up);

   adcFixedPin::startConversion();
   adcDiffFixedPin::startConversion();

//   adcUnMappedPin::enable();
//   using adcUnMappedPinPcr = USBDM::PcrTable_T<USBDM::Adc0Info,4>;
//   adcUnMappedPinPcr::setPCR(USBDM::PinPull_Up);

//   adcInvalidPin::enable();
//   using adcInvalidPin = USBDM::PcrTable_T<USBDM::Adc0Info,1>;
//   adcInvalidPin::setPCR(USBDM::PinPull_Up);

   gpioPinOK1::setOutput(USBDM::PinPull_Down);
   gpioPinOK2::setOutput(USBDM::PinPull_Down);
//   gpioIllegalPin1::setOutput(USBDM::PinPull_Down);
//   gpioIllegalPin2::setOutput(USBDM::PinPull_Down);

   for(;;) {
      USBDM::waitMS(10);
      bool value = pin::read();
      Led::write(value);
      printf("Pin = %d\n", value);
   }
   return 0;
}
