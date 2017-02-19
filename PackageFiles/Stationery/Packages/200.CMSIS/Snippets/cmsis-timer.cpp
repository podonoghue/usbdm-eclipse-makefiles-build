/*----------------------------------------------------------------------------
 * RTX example program - Timer
 *
 * Based on examples at https://developer.mbed.org/handbook/CMSIS-RTOS
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

#include "cmsis_os.h"                   // CMSIS RTX
#include "hardware.h"                   // Hardware interface

// Directly access USBDM routines
using namespace USBDM;

/*
 * LEDs to use
 */
using Led1 = $(demo.cpp.red.led:USBDM::GpioB<0>);
using Led2 = $(demo.cpp.green.led:USBDM::GpioB<1>);
using Led3 = $(demo.cpp.blue.led:USBDM::GpioB<2>);

template<class Led>
void T_blink(void const *) {
   Led::toggle();
}

osTimerDef(blink_0, T_blink<Led1>);
osTimerDef(blink_1, T_blink<Led2>);
osTimerDef(blink_2, T_blink<Led3>);

int main(void) {
   Led1::setOutput();
   Led2::setOutput();
   Led3::setOutput();

   osTimerId timer_0 = osTimerCreate(osTimer(blink_0), osTimerPeriodic, nullptr);
   setAndCheckCmsisErrorCode((timer_0 != nullptr)?osOK:osErrorOS);

   osTimerId timer_1 = osTimerCreate(osTimer(blink_1), osTimerPeriodic, nullptr);
   setAndCheckCmsisErrorCode((timer_1 != nullptr)?osOK:osErrorOS);

   osTimerId timer_2 = osTimerCreate(osTimer(blink_2), osTimerPeriodic, nullptr);
   setAndCheckCmsisErrorCode((timer_2 != nullptr)?osOK:osErrorOS);

   setAndCheckCmsisErrorCode(osTimerStart(timer_0, 2000));
   setAndCheckCmsisErrorCode(osTimerStart(timer_1, 1000));
   setAndCheckCmsisErrorCode(osTimerStart(timer_2,  500));

   osDelay(osWaitForever);
}

