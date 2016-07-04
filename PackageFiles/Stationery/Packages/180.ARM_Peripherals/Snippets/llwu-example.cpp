/*
 ========================================================================================
 * @file    llwu-example.cpp (180.ARM_Peripherals)
 * @brief   Basic C++ demo using LLWU class - very incomplete
 *
 * @note To use this demonstration the Console baud rate needs to be reduced to 9600 baud
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ========================================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "delay.h"
#include "console.h"

#include "mcg.h"
#include "llwu.h"
#include "smc.h"
#include "uart.h"

// LED connection - change as required
using Led   = USBDM::GpioC<3>;

void llwuCallback() {
   __asm__("nop");
}

using namespace USBDM;

/**
 * Low power clock setting
 */
McgInfo::ClockInfo vlprClockInfo = {
      //! Clock Mode
      McgInfo::ClockMode_BLPI,

      //! Mode flags
      0,

      //! Control Register 1
      MCG_C1_FRDIV(0)   | // FRDIV    FLL External Reference Divider
      MCG_C1_IRCLKEN(1) | // IRCLEN   Internal Reference Clock Enable
      MCG_C1_IREFSTEN(0), // IREFSTEN Internal Reference Stop Enable

      //! Control Register 2
      MCG_C2_LOCRE0(0) | // LOLRE0  Loss of Clock Reset Enable
      MCG_C2_RANGE0(1) | // RANGE   Frequency Range Select
      MCG_C2_HGO0(0)   | // HGO     High Gain Oscillator Select
      MCG_C2_EREFS0(1) | // EREFS   External Reference Select
      MCG_C2_IRCS(1),    // IRCS    Internal Reference Clock Select

      //! Control Register 4
      MCG_C4_DMX32(0)     | // DMX32    DCO lock range
      MCG_C4_DRST_DRS(0),   // DRST_DRS DCO Range Select

      //! Control Register 5
      MCG_C5_PLLCLKEN0(0)  | // PLLCLKEN0 PLL Clock Enable
      MCG_C5_PLLSTEN0(0)   | // PLLSTEN0  PLL Stop Enable
      MCG_C5_PRDIV0(0),     // PRDIV0    PLL External Reference Divider

      //! Control Register 6
      MCG_C6_LOLIE0(0) | // LOLIE0 Loss of Lock interrupt Enable
      MCG_C6_CME0(0)   | // CME0   Clock Monitor Enable
      MCG_C6_VDIV0(0),   // VDIV0  PLL VCO Divider

      //! Status and Control Register
      MCG_SC_FCRDIV(0), // FCRDIV Internal Clock Reference Divider

      //! Control Register 7
      MCG_C7_OSCSEL(0), // OSCSEL MCG OSC Clock Select

      //! Control Register 8
      MCG_C8_LOCRE1(0) | // LOCRE1 RTC Loss of Clock Reset Enable
      MCG_C8_LOLRE(0)  | // LOLRE  PLL Loss of Lock Reset Enable
      MCG_C8_CME1(0),    // CME1   Clock Monitor Enable 1
};


int main() {
   console_setBaudRate(9600);

   printf("Starting\n");

   printf("Core freq = %ld\n", ::SystemCoreClock);

   USBDM::Llwu::initialise();
   USBDM::Llwu::setCallback(llwuCallback);

   USBDM::Smc::initialise();

   Led::setOutput();

   for (;;) {
      Led::toggle();

      USBDM::Mcg::clockTransition(vlprClockInfo);
      console_setBaudRate(9600);
      USBDM::Smc::enterPowerMode(Smc::runm_vlpr);
      printf("LP Core freq = %ld\n", ::SystemCoreClock);
      printf("mode = %d\n", Smc::getPowerMode());
      USBDM::waitMS(1000);

      USBDM::Smc::enterPowerMode(Smc::runm_run);
      USBDM::Mcg::clockTransition(USBDM::McgInfo::clockInfo[0]);
      console_setBaudRate(9600);
      printf("LP Core freq = %ld\n", ::SystemCoreClock);
      printf("mode = %d\n", Smc::getPowerMode());
      USBDM::waitMS(1000);
   }
   return 0;
}
