/*
 * rtc.h
 *
 *  Created on: 25/10/2013
 *      Author: podonoghue
 */

#ifndef RTC_H_
#define RTC_H_

#include "pin_mapping.h"

namespace USBDM {

/**
 * Type definition for ADC interrupt call back
 *
 *  @param timeSinceEpoch - Time since the epoch in seconds
 */
typedef void (*RTCCallbackFunction)(uint32_t timeSinceEpoch);

template <class Info>
class RtcBase_T {

protected:
   static constexpr volatile RTC_Type *rtc      = reinterpret_cast<volatile RTC_Type *>(Info::basePtr);
   static constexpr volatile uint32_t *clockReg = reinterpret_cast<volatile uint32_t *>(Info::clockReg);

public:
   /**
    * Initialise rtc to default settings\n
    * Configures all  rtc pins
    */
   static void initialise() {

      // Configure pins
      Info::initPCRs();

      // Enable clock to RTC interface
      // (RTC used its own clock internally)
      *clockReg  |= Info::clockMask;
      __DMB();

      if ((rtc->SR&RTC_SR_TIF_MASK) != 0) {
         // rtc is not running or invalid - re-initialise

         // Software reset RTC
         rtc->CR  = RTC_CR_SWR_MASK;
         rtc->CR  = 0;

#if defined(MCU_MK20D5) || (SYSTEM_ERCLK32K_CLOCK == SYSTEM_OSC32KCLK_CLOCK)
         // Enable oscillator
         // Note - on KL25 this will disable the standard oscillator
         rtc->CR  = RTC_CR_OSCE_MASK|RTC_CR_SC8P_MASK|RTC_CR_UM_MASK;

         // Wait startup time
         int i;
         for (i=0; i<100000; i++) {
            __asm__("nop");
         }
#endif
         // Set current time
         rtc->TSR = 1379453899;  // A bit closer to today!
         rtc->SR  = RTC_SR_TCE_MASK;
      }

      if (Info::irqHandlerInstalled) {
         // Enable timer interrupts
         NVIC_EnableIRQ(Info::irqNums[0]);

         // Set priority level
         NVIC_SetPriority(Info::irqNums[0], Info::irqLevel);
      }
   }
   /*
    * Sets the system rtc time
    *
    *  @param timeSinceEpoch - time since the epoch in seconds
    */
   static void setTime(uint32_t timeSinceEpoch) {
      rtc->SR  = 0;
      rtc->TSR = timeSinceEpoch;
      rtc->SR  = RTC_SR_TCE_MASK;
   }

   /**
    *  Get current alarm time
    *
    *  @return alarm time as 32-bit number
    */
   static uint32_t getTime(void) {
      return rtc->TSR;
   }

   /**
    *  Get current alarm time
    *
    *  @return alarm time as 32-bit number
    */
   uint32_t getAlarmTime(void) {
      return rtc->TAR;
   }

   /**
    *  Set alarm time
    *
    *  @param timeSinceEpoch - Alarm time in seconds relative to the epoch
    */
   static void rtc_setAlarmTime(uint32_t timeSinceEpoch) {
      rtc->TAR = timeSinceEpoch;
   }

};

/**
 * Template class to provide ADC callback
 */
template<class Info>
class RtcIrq_T : public RtcBase_T<Info> {

protected:
   /** Callback function for ISR */
   static RTCCallbackFunction callback;

public:
   /**
    * IRQ handler
    */
   static void irqHandler(void) {
      if (callback != 0) {
         callback(RtcBase_T<Info>::rtc->TSR);
      }
      if ((RtcBase_T<Info>::rtc->SR&RTC_SR_TAF_MASK) != 0) {
         // Clear alarm
         RtcBase_T<Info>::rtc->TAR   = 0;
      }
   }

   /**
    * Set Callback function
    *
    *   @param theCallback - Callback function to be executed on RTC alarm interrupt
    *   @param time        - Time to set alarm for (time since the epoch in seconds)
    */
   static void setCallback(RTCCallbackFunction theCallback, uint32_t time) {
      callback = theCallback;
      if (callback != NULL) {
         // Set alarm time
         RtcBase_T<Info>::rtc->TAR   = time;
         // Enable interrupts from RTC alarm
         RTC->IER   |= RTC_IER_TAIE_MASK;
         NVIC_EnableIRQ(Info::irqNums[0]);
      }
      else {
         // Disable interrupts from RTC alarm
         RTC->IER   &= ~RTC_IER_TAIE_MASK;
         NVIC_DisableIRQ(Info::irqNums[0]);
      }
   }
};

template<class Info> RTCCallbackFunction RtcIrq_T<Info>::callback = 0;

#ifdef USBDM_RTC_IS_DEFINED
/**
 * Class representing RTC
 */
using Rtc = RtcIrq_T<RtcInfo>;

#endif

} // End namespace USBDM

#endif /* RTC_H_ */
