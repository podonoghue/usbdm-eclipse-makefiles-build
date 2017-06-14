/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals)
 * @brief   Basic C++ demo using GPIO class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include <algorithm>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "delay.h"
#include "max30102.h"

// LED connection - change as required
using RedLed    = USBDM::gpio_LED_RED;
using BlueLed   = USBDM::gpio_LED_BLUE;
using GreenLed  = USBDM::gpio_LED_GREEN;

using IrqPin    = USBDM::GpioD<5>;

USBDM::I2c0 i2c;
USBDM::MAX30102 spo2Sensor(i2c);

using Strobe = USBDM::GpioE<1>;

static uint32_t redLed, irLed;

int main() {
   using namespace USBDM;

   printf("Starting\n");

   RedLed::setOutput();
   BlueLed::setOutput();
   GreenLed::setOutput();
   RedLed::high();
   BlueLed::high();
   GreenLed::high();

   spo2Sensor.reset();
   spo2Sensor.init();

   Strobe::setOutput();

//   uint32_t min,max;
//
//   spo2Sensor.readLeds(redLed, irLed);
//   min = redLed;
//   max = redLed;

   static auto callback = [](uint32_t status) {
      (void)status;
      spo2Sensor.readLeds(redLed, irLed);
   };

   IrqPin::setInput(pcrValue(PinPullUp, PinDriveLow, PinOpenCollector, PinIrqFalling));
   IrqPin::setCallback(callback);
   IrqPin::setIrq(PinIrqFalling);
   IrqPin::enableNvicInterrupts();

   for(;;) {
      printf("Temp = %f\n", spo2Sensor.getTempMeasurement());
//      __asm__("nop");
//      // Wait for IRQ
//      while (IrqPin::isHigh()) {
//         __asm__("nop");
//      }
//      spo2Sensor.readLeds(redLed, irLed);
////      printf("red=%ld, ir=%ld\n", redLed, irLed);
//
//      // Leaky min, max
//      min = (101*min)/100;
//      max = (99*min)/100;
//      min = std::min(min,redLed);
//      max = std::max(max,redLed);
//      uint32_t threshold=(min+max)/2;
//      RedLed::write(redLed>threshold);
   }
   return 0;
}
