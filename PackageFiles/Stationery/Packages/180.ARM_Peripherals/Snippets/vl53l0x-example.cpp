/*
 ============================================================================
 * @file   vl53l0x-example.cpp (180.ARM_Peripherals/Snippets)
 * @brief  Basic C++ demo of using vl53l0x interface
 *
 * Lightly modified from https://github.com/pololu/vl53l0x-arduino
 ============================================================================
 */
#include <vl53l0x.h>
#include "hardware.h"

// Allow access to USBDM methods without USBDM:: prefix
using namespace USBDM;

I2c0 i2c{};

VL53L0X rangeFinder(i2c);

// LED connection - change as required
using Led   = GpioA<2,ActiveLow>;

/*
 * This example shows how to use continuous mode to take
 * range measurements with the VL53L0X. It is based on
 * vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.
 * The range readings are in units of mm.
 */

void setup() {
   rangeFinder.init();
   rangeFinder.setTimeout(500);

   // Start continuous back-to-back mode (take readings as
   // fast as possible).  To use continuous timed mode
   // instead, provide a desired inter-measurement period in
   // ms (e.g. sensor.startContinuous(100)).
   rangeFinder.startContinuous();
}

int main() {
   console.writeln("Starting\n");

   Led::setOutput();

   setup();

   for(;;) {
      console.writeln(rangeFinder.readRangeContinuousMillimetres());
      if (rangeFinder.timeoutOccurred()) {
         console.writeln(" TIMEOUT");
      }
      Led::toggle();
   }
}
