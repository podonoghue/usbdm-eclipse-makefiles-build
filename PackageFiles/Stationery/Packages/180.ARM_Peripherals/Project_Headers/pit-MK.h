/**
 * @file      pit.h (derived from pit-MK.h)
 *
 * @brief    Abstraction layer for PIT interface
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */

#ifndef INCLUDE_USBDM_PIT_H_
#define INCLUDE_USBDM_PIT_H_

#include "derivative.h"
#include "system.h"
#include "hardware.h"

namespace USBDM {

/**
 * @addtogroup PIT_Group PIT, Programmable Interrupt Timer
 * @brief Abstraction for Programmable Interrupt Timer
 * @{
 */
#if PIT_USES_NAKED_HANDLER == 0
/**
 * Type definition for PIT interrupt call back
 */
typedef void (*PITCallbackFunction)(void);
#endif

/*!
 * @brief struct representing a Programmable Interrupt  Timer
 *
 * <b>Example</b>
 * @code
 *
 * @endcode
 */
template<class Info>
class Pit_T {

   friend void ::PIT0_IRQHandler(void);
   friend void ::PIT1_IRQHandler(void);
   friend void ::PIT2_IRQHandler(void);
   friend void ::PIT3_IRQHandler(void);

protected:
   /** Default TCTRL value for Timer channel */
   static constexpr uint32_t PIT_TCTRL_DEFAULT_VALUE = (PIT_TCTRL_TEN_MASK|PIT_TCTRL_TIE_MASK);

#if PIT_USES_NAKED_HANDLER == 0
   /*! Callback functions for ISRs */
   static PITCallbackFunction callback[Info::irqCount];

public:
   /**
    * Set callback for ISR
    *
    * @param channel  The PIT channel to modify
    * @param callback The function to call from stub ISR
    */
   static void setCallback(int channel, PITCallbackFunction callback) {
      Pit_T::callback[channel] = callback;
   }
#endif

protected:
   /** Pointer to hardware */
   static constexpr volatile PIT_Type *pit       = reinterpret_cast<volatile PIT_Type*>(Info::basePtr);

   /* Pointer to clock register */
   static constexpr volatile uint32_t *clockReg  = reinterpret_cast<volatile uint32_t*>(Info::clockReg);

public:
   /**
    *  Configure the PIT
    *
    *  @param mcr       Module Control Register
    */
   static void configure(uint32_t mcr=Info::mcrValue) {
      // Enable clock
      *clockReg |= Info::clockMask;

      // Enable timer
      pit->MCR = mcr;
   }
   /**
    *   Disable the PIT channel
    */
   static void finalise(uint8_t channel) {
      *clockReg &= ~Info::clockMask;
   }
   /**
    *  Configure the PIT channel
    *
    *  @param channel   Channel to configure
    *  @param interval  Interval in timer ticks (usually bus clock period)
    *  @param tctrl     Timer Control Register value
    */
   static void configureChannel(const uint8_t channel, uint32_t interval, uint32_t tctrl=PIT_TCTRL_DEFAULT_VALUE) {

      pit->CHANNEL[channel].LDVAL = interval;
      pit->CHANNEL[channel].TCTRL = tctrl;
      pit->CHANNEL[channel].TFLG  = PIT_TFLG_TIF_MASK;

      if (tctrl & PIT_TCTRL_TIE_MASK) {
         // Enable timer interrupts
         NVIC_EnableIRQ((IRQn_Type)(Info::irqNums[0]+channel));

         // Set arbitrary priority level
         NVIC_SetPriority((IRQn_Type)(Info::irqNums[0]+channel), Info::irqLevel);
      }
   }
   /**
    *   Disable the PIT channel
    */
   static void finaliseChannel(uint8_t channel) {

      // Disable timer channel
      pit->CHANNEL[channel].TCTRL = 0;

      // Enable timer interrupts
      NVIC_DisableIRQ((IRQn_Type)(Info::irqNums[0]+channel));
   }
   /**
    *  Use a PIT channel to implement a busy-wait delay
    *
    *  @param channel   Channel to use
    *  @param interval  Interval to wait in timer ticks (usually bus clock period)
    *
    *  @note Function doesn't return until interval has expired
    */
   static void delay(uint8_t channel, uint32_t interval) {
      configureChannel(channel, interval, PIT_TCTRL_TEN_MASK);
      while (pit->CHANNEL[channel].TFLG == 0) {
         __NOP();
      }
      configureChannel(channel, 0, 0);
   }
};

#ifdef PIT
/**
 * @brief class representing the PIT
 */
using Pit = Pit_T<PitInfo>;
#endif

/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_PIT_H_ */
