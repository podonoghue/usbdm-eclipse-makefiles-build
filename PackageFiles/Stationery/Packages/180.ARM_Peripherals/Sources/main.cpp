/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals/Sources/main.cpp)
 * @brief   Basic C++ demo using GPIO class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"

/**
 * See more examples in Snippets directory
 *
 * Using a ADC channel
 *  using adcChannel = USBDM::Adc0Channel<6>;
 *  adcChannel::enable();
 *  adcChannel::setResolution(USBDM::resolution_16bit_se);
 *  adcChannel::setAveraging(USBDM::averaging_32);
 *  int value = adcChannel::readAnalogue();
 * 
 * Using a timer channel
 *  using ftmChannel = USBDM::Ftm0Channel<0>;
 *  ftmChannel::configure(1000, USBDM::ftm_leftAlign);
 *  ftmChannel::setDutyCycle(25);
 */

// LED connection - change as required
using Led   = $(demo.cpp.led:USBDM::GpioB<3>);

int main() {
//   printf("Starting\n");

//   printf("SystemBusClock  = %ld\n", SystemBusClock);
//   printf("SystemCoreClock = %ld\n", SystemCoreClock);

   Led::setOutput();
   for(;;) {
      Led::toggle();
      USBDM::waitMS(100);
//      printf("Tick\n");
   }
   return 0;
}
