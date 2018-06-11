/*
 ============================================================================
 * @file    main.cpp (180.ARM_Peripherals)
 * @brief   Basic C++ demo using GPIO class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "delay.h"
#include "tsi.h"
#include "pdb.h"
#include "vref.h"
#include "cmp.h"
#include "tsi.h"
#include "llwu.h"
#include "lptmr.h"
#include "mcg.h"
#include "pdb.h"
#include "pit.h"
#include "rtc.h"
#include "uart.h"
#include "usb.h"

/**
 * See more examples in Snippets directory
 *
 * Using a ADC channel
 *  using adcChannel = USBDM::Adc0Channel<6>;
 *  adcChannel::setMode(USBDM::AdcResolution_16bit_se);
 *  int value = adcChannel::readAnalogue();
 * Using a timer channel
 *  using ftmChannel = USBDM::Ftm0Channel<0>;
 *  ftmChannel::configure(1000, USBDM::ftm_leftAlign);
 *  ftmChannel::setDutyCycle(25);
 *
 */

void adcCallback(uint32_t value) {
   (void) value;
}

void cmpCallback(int status) {
   (void)status;
}

void ftmToiCallback() {
}

void ftmCallback(int status) {
   (void)status;
}

void llwuCallback() {
}

void lptrmCallback() {
}

void mcgCallback() {
}

void pdbCallback() {
}

void pitCallback() {
}

void rtcCallback(uint32_t timeSinceEpoch) {
   (void) timeSinceEpoch;
}

void tsiCallback(uint8_t status) {
   (void)status;
}

void uartCallback(uint8_t status) {
   (void)status;
}

void usbCallback(uint8_t status) {
   (void)status;
}

// LED connection - change as required
using Led   = USBDM::GpioC<3>;

int main() {
   USBDM::mapAllPins();

//   console.writeln("Starting");

//   console.write("SystemBusClock  = ").writeln(::SystemBusClock);
//   console.write("SystemCoreClock = ").writeln(::SystemCoreClock);

   USBDM::Adc0::enable();
   USBDM::Adc0::setCallback(adcCallback);

   USBDM::Cmp0::enable();
   USBDM::Cmp0::setCallback(cmpCallback);
   USBDM::Cmp0::enableRisingEdgeInterrupts();
   USBDM::Cmp0::enableFallingEdgeInterrupts();

   USBDM::Ftm0::enable();
   USBDM::Ftm0::setToiCallback(ftmToiCallback);
   USBDM::Ftm0::setChannelCallback(ftmCallback);
   USBDM::Ftm0::enableToiInterrupts();
   USBDM::Ftm0Channel<1>::enableChannelInterrupts();

   USBDM::Llwu::enable();
   USBDM::Llwu::setCallback(llwuCallback);

   USBDM::Lptmr0::enable();
   USBDM::Lptmr0::setCallback(lptrmCallback);

   USBDM::Mcg::setCallback(mcgCallback);

   USBDM::Pdb0::enable();
   USBDM::Pdb0::setCallback(pdbCallback);
   USBDM::Pdb0::enableErrorInterrupts();
   USBDM::Pdb0::enableSequenceInterrupts();

   USBDM::Pit::enable();
   USBDM::Pit::setCallback(0, pdbCallback);
   USBDM::Pit::enableInterrupts(0);
   USBDM::Pit::setCallback(1, pdbCallback);
   USBDM::Pit::enableInterrupts(0);
   USBDM::Pit::setCallback(2, pdbCallback);
   USBDM::Pit::enableInterrupts(0);
   USBDM::Pit::setCallback(3, pdbCallback);
   USBDM::Pit::enableInterrupts(0);

   USBDM::Rtc::setCallback(rtcCallback, USBDM::Rtc::getTime()+1000);
   USBDM::Rtc::enableInterrupts();

   USBDM::Tsi0::enable();
   USBDM::Tsi0::setCallback(tsiCallback);
   USBDM::Tsi0::enableErrorInterrupts();
   USBDM::Tsi0::enableTsiInterrupts();

   USBDM::Uart1 *uart = new USBDM::Uart1();
   uart->setBaudRate(100);
   uart->setCallback(uartCallback);

   USBDM::Usb0::enable();
   USBDM::Usb0::enableInterrupts();
   USBDM::Usb0::setCallback(usbCallback);

   USBDM::Vref::enable();

   Led::setOutput();
   for(;;) {
      Led::toggle();
      USBDM::waitMS(100);
//      console.writeln("Tick");
   }
   return 0;
}
