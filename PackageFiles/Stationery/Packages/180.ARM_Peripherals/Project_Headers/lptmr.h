/**
 * @file     lptmr.h
 * @brief    Low power timer interface
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */
#ifndef INCLUDE_USBDM_LPTMR_H_
#define INCLUDE_USBDM_LPTMR_H_

#include "derivative.h"
#include "system.h"
#include "pin_mapping.h"

namespace USBDM {

/**
 * @addtogroup LPTMR_Group LPTMR, Low Power Timer
 * @brief Abstraction for Low Power Timer
 * @{
 */

/**
 * Type definition for LPTMR interrupt call back
 */
typedef void (*LPTMRCallbackFunction)(void);

/**
 * @brief Template class representing a Low Power Timer
 */
template<class Info>
class Lptmr_T {

protected:
   /** Callback function for ISR */
   static LPTMRCallbackFunction callback;

public:
   /**
    * Set callback for ISR
    *
    * @param callback The function to call from stub ISR
    */
   static void setCallback(LPTMRCallbackFunction theCallback) {
      callback = theCallback;
   }

   /**
    * PIT interrupt handler. \n
    * Calls PIT0 callback
    */
   static void irqHandler() {
      // Clear interrupt flag
      lptmr->CSR |= LPTMR_CSR_TCF_MASK;

      if (callback != 0) {
         callback();
      }
   }

protected:
   /** Pointer to hardware */
   static constexpr volatile LPTMR_Type *lptmr     = reinterpret_cast<volatile LPTMR_Type *>(Info::basePtr);

   /* Pointer to clock register */
   static constexpr volatile uint32_t   *clockReg  = reinterpret_cast<volatile uint32_t *>(Info::clockReg);

public:
   /**
    * Enable LPTMR\n
    * Includes initialising any pins used
    */
   static void enable() {
      // Configure pins
      Info::initPCRs();

      // Enable clock
      *clockReg |= Info::clockMask;
      __DMB();

      // Disable timer
      lptmr->CSR  = Info::CSR;
      // PCS 0,1,2,3 => MCGIRCLK, LPO, ERCLK32K, OSCERCLK
      lptmr->PSR  = Info::PSR;
      // Interval/Compare value
      lptmr->CMR  = Info::PERIOD;
      // Enable timer
      lptmr->CSR |= LPTMR_CSR_TEN_MASK;

      if (Info::CSR & LPTMR_CSR_TIE_MASK) {
         // Enable timer interrupts
         NVIC_EnableIRQ(Info::irqNums[0]);

         // Set priority level
         NVIC_SetPriority(Info::irqNums[0], Info::irqLevel);
      }
      }

   /**
    *  Configure the LPTMR
    *
    *  @param interval  Interval for the timer in timer ticks
    *  @param csr       Control Status Register
    *  @param psr       Prescale Register
    */
   static void configure(uint16_t interval, uint32_t csr=Info::CSR|LPTMR_CSR_TIE_MASK, uint32_t psr=Info::PSR) {
      // Disable timer
      lptmr->CSR  = csr;
      // PCS 0,1,2,3 => MCGIRCLK, LPO, ERCLK32K, OSCERCLK
      lptmr->PSR  = psr;
      // Interval/Compare value
      lptmr->CMR  = interval;
      // Enable timer
      lptmr->CSR |= LPTMR_CSR_TEN_MASK;

      if (csr & LPTMR_CSR_TIE_MASK) {
         // Enable timer interrupts
         NVIC_EnableIRQ(Info::irqNums[0]);

         // Set priority level
         NVIC_SetPriority(Info::irqNums[0], Info::irqLevel);
      }
   }
   /**
    *   Disable the LPTMR
    */
   static void finalise(void) {
      // Disable timer
      lptmr->CSR = 0;
      NVIC_DisableIRQ(Info::irqNums[0]);
      *clockReg &= ~Info::clockMask;
   }
};

template<class Info> LPTMRCallbackFunction Lptmr_T<Info>::callback = 0;

#ifdef LPTMR0
/**
 * @brief Class representing LPTMR0
 *
 * <b>Example</b>
 * @code
 *
 * // LPTMR callback
 * void flash(void) {
 *    RED_LED::toggle();
 * }
 *
 * ...
 *
 * // Configure LPTMR
 * Lptmr0::configure(1000);
 *
 * // This handler is set programmatically
 * Lptmr0::setCallback(flash);
 *
 * @endcode
 */
using Lptmr0 = Lptmr_T<Lptmr0Info>;
#endif

/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_LPTMR_H_ */
