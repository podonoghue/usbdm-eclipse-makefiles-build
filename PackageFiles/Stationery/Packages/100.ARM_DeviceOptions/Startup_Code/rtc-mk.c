/*
 * rtc.c
 *
 *  Created on: 21/09/2013
 *      Author: podonoghue
 */

#include <sys/time.h>
#include "derivative.h"
#include "clock_configure.h"
#include "rtc.h"

#ifdef RTC_BASE_PTR

/**
 * Initialise the Real Time Clock (RTC)
 */
void rtc_initialise(void) {
   // Enable clock to RTC interface
   SIM->SCGC6 |= SIM_SCGC6_RTC_MASK;

//   SIM_SOPT2 |= SIM_SOPT2_RTCCLKOUTSEL_MASK;    // RTC_CLKOUT = 32kHz
//   PORTE_PCR0 = PORT_PCR_MUX(7);                // Enable RTC_CLKOUT

   if ((RTC->SR&RTC_SR_TIF_MASK) != 0) {
      // RTC is not running or invalid - re-initialise

      // Software reset RTC
      RTC->CR  = RTC_CR_SWR_MASK;
      RTC->CR  = 0;

#if defined(MCU_MK20D5) || (SYSTEM_ERCLK32K_CLOCK == SYSTEM_OSC32KCLK_CLOCK)
   // Enable oscillator
   // Note - on KL25 this will disable the standard oscillator
   RTC->CR  = RTC_CR_OSCE_MASK|RTC_CR_SC8P_MASK|RTC_CR_UM_MASK;

   // Wait startup time
   int i;
   for (i=0; i<100000; i++) {
      __asm("nop");
   }
#endif
      // Set current time
      RTC->TSR = 1379453899;  // A bit closer to today!
      RTC->SR  = RTC_SR_TCE_MASK;
   }
}

/*
 * Sets the system RTC time
 *
 *  @param timeSinceEpoch - time since the epoch in seconds
 */
void rtc_setTime(uint32_t timeSinceEpoch) {
   RTC->SR  = 0;
   RTC->TSR = timeSinceEpoch;
   RTC->SR  = RTC_SR_TCE_MASK;
}

/**
 *  Get current alarm time
 *
 *  @return alarm time as 32-bit number
 */
uint32_t rtc_getTime(void) {
   return RTC->TSR;
}

/**
 *  Get current alarm time
 *
 *  @return alarm time as 32-bit number
 */
uint32_t rtc_getAlarmTime(void) {
   return RTC->TAR;
}

/**
 *  Set current alarm time
 *
 *  @param timeSinceEpoch - Alarm time in seconds relative to the epoch
 */
void rtc_setAlarmTime(uint timeSinceEpoch) {
   RTC->TAR = timeSinceEpoch;
}

#ifndef RTC_USES_NAKED_HANDLERS

//! Pointer to RTC callback function
static RTCCallbackFunction secondsCallbackFunction = NULL;

/**
 *   Sets RTC seconds interrupt callback
 *
 *   @param callback - Callback function to be executed on RTC seconds interrupt
 */
RTCCallbackFunction rtc_setSecondsCallback(RTCCallbackFunction callback) {
   RTCCallbackFunction temp = callback;

   secondsCallbackFunction = callback;

   // Enable clock to RTC interface
   SIM->SCGC6 |= SIM_SCGC6_RTC_MASK;
   if (callback != NULL) {
      // Enable interrupts from RTC
      RTC->IER   |= RTC_IER_TSIE_MASK;
      NVIC_EnableIRQ(RTC_Seconds_IRQn);
   }
   else {
      // Disable interrupts from RTC
      RTC->IER   &= ~RTC_IER_TSIE_MASK;
      NVIC_DisableIRQ(RTC_Seconds_IRQn);
   }
   return temp;
}

/**
 *   RTC Seconds ISR
 *
 *   Calls RTC seconds callback
 */
void RTC_Seconds_IRQHandler(void) {
   if (secondsCallbackFunction != NULL) {
      secondsCallbackFunction();
   }
}

//! Pointer to RTC callback function
static RTCCallbackFunction alarmCallbackFunction = NULL;

/**
 *   Sets RTC alarm interrupt callback
 *
 *   @param callback - Callback function to be executed on RTC alarm interrupt
 *   @param time     - Time to set alarm for (time since the epoch in seconds)
 */
RTCCallbackFunction rtc_setAlarmCallback(RTCCallbackFunction callback, uint32_t time) {
   RTCCallbackFunction temp = callback;

   alarmCallbackFunction = callback;

   // Enable clock to RTC interface
   SIM->SCGC6 |= SIM_SCGC6_RTC_MASK;
   if (callback != NULL) {
      // Set alarm time
      RTC->TAR   = time;
      // Enable interrupts from RTC alarm
      RTC->IER   |= RTC_IER_TAIE_MASK;
      NVIC_EnableIRQ(RTC_IRQn);
   }
   else {
      // Disable interrupts from RTC alarm
      RTC->IER   &= ~RTC_IER_TAIE_MASK;
      NVIC_DisableIRQ(RTC_IRQn);
   }
   return temp;
}

/**
 *   RTC Alarm ISR.
 *
 *   Calls RTC alarm callback
 */
void RTC_IRQHandler(void) {
   if (alarmCallbackFunction != NULL) {
      alarmCallbackFunction();
   }
   if ((RTC->SR&RTC_SR_TAF_MASK) != 0) {
      // Clear alarm
      RTC->TAR   = 0;
   }
   // Disable interrupts from RTC alarm
   //   RTC->IER   &= ~RTC_IER_TAIE_MASK;
}

#endif // RTC_USES_NAKED_HANDLERS

/*
 *   To support time.h functions
 *
 *   @param tp
 *   @param tzp
 */
int _gettimeofday(struct timeval *tp, void *tzp) {
   (void)tzp;
   if (((SIM->SCGC6 & SIM_SCGC6_RTC_MASK) == 0) ||
       ((RTC->SR&RTC_SR_TIF_MASK) != 0) ) {
      tp->tv_sec  = -1;
   }
   else {
      tp->tv_sec  = RTC->TSR;
   }
   tp->tv_usec = 0;
   return 0;
}

/*
 *   To support time.h functions
 *
 *   @param tp
 *   @param tzp
 */
int settimeofday(const struct timeval *tp, const struct timezone *tzp) {
   (void)tzp;
   // Start RTC
   rtc_initialise();
   setRealTimeValue(tp->tv_sec);
   return 0;
}
#endif
