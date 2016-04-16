/**
 * @file      lptmr.h
 * @version   1.0.0
 * @brief     Low Power Timer
 */

#ifndef INCLUDE_USBDM_LPTMR_H_
#define INCLUDE_USBDM_LPTMR_H_

#include "derivative.h"
#include "system.h"
#include "hardware.h"

namespace USBDM {

/**
 * @addtogroup LPTMR, LPTMR_Group Low Power Timer
 * @brief Abstraction for Low Power Timer
 * @{
 */

#if LPTMR_USES_NAKED_HANDLER == 0
/**
 * Type definition for LPTMR interrupt call back
 */
typedef void (*LPTMRCallbackFunction)(void);
#endif

/*!
 * @brief struct representing a Low Power Timer
 *
 * <b>Example</b>
 * @code
 *
 * @endcode
 */
template<class Info>
class Lptmr_T {

   friend void ::LPTMR0_IRQHandler(void);

#if LPTMR_USES_NAKED_HANDLER == 0
protected:
   /*! Callback function for ISR */
   static LPTMRCallbackFunction callback;

public:
   /**
    * Set callback for ISR
    *
    * @param callback The function to call from stub ISR
    */
   static void setCallback(LPTMRCallbackFunction callback) {
      Lptmr_T<Info>::callback = callback;
   }
#endif

protected:
   /** Pointer to hardware */
   static constexpr volatile LPTMR_Type *lptmr     = reinterpret_cast<volatile LPTMR_Type *>(Info::basePtr);

   /* Pointer to clock register */
   static constexpr volatile uint32_t   *clockReg  = reinterpret_cast<volatile uint32_t *>(Info::clockReg);

public:
   /**
    *  Configure the LPTMR
    *
    *  @param interval  Interval for the timer in timer ticks
    *  @param csr       Control Status Register
    *  @param psr       Prescale Register
    */
   static void configure(uint16_t interval, uint32_t csr=Info::csrValue|LPTMR_CSR_TIE_MASK, uint32_t psr=Info::psrValue) {

      // Configure pins
      Info::initPCRs();

      // Enable clock
      *clockReg |= Info::clockMask;

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

#ifdef LPTMR0
/**
 * @brief class representing LPTMR_0
 */
using Lptmr0 = Lptmr_T<Lptmr0Info>;

#endif

/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_LPTMR_H_ */
