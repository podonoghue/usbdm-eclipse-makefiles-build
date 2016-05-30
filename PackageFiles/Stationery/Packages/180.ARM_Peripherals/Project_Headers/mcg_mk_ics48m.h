/**
 * @file      mcg.h (derived from mcg_mk_ics48m.h)
 *
 * @brief    Abstraction layer for MCG interface
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */

#ifndef INCLUDE_USBDM_MCG_H_
#define INCLUDE_USBDM_MCG_H_

#include "derivative.h"
#include "system.h"
#include "hardware.h"

namespace USBDM {

/**
 * @addtogroup MCG_Group MCG, Multipurpose Clock Generator
 * @brief Abstraction for Multipurpose Clock Generator
 * @{
 */
/**
 * Type definition for MCG interrupt call back
 */
typedef void (*MCGCallbackFunction)(void);

/**
 * @brief Class representing the MCG
 *
 * <b>Example</b>
 * @code
 *    Mcg::initialise();
 * @endcode
 */
class Mcg {

   /** Callback function for ISR */
   static MCGCallbackFunction callback;

   /** Pointer to hardware */
   static constexpr volatile MCG_Type *mcg = reinterpret_cast<volatile MCG_Type*>(McgInfo::basePtr);

   /**
    * Transition from current clock mode to mode given
    *
    * @param to Clock mode to transition to
    */
   static int clockTransition(McgInfo::ClockMode to);

   /**
    * Do default clock gating
    */
   static void doClockGating();

   /**
    * Update SystemCoreClock variable
    *
    * Updates the SystemCoreClock variable with current core Clock retrieved from CPU registers.
    */
   static void SystemCoreClockUpdate(void);

public:
   /**
    * MCG interrupt handler -  Calls MCG callback
    */
   static void irqHandler() {
      if (callback != 0) {
         callback();
      }
   }

   /**
    * Set callback for ISR
    *
    * @param channel  The MCG channel to modify
    * @param callback The function to call from stub ISR
    */
   static void setCallback(MCGCallbackFunction callback) {
      Mcg::callback = callback;
   }

   /** Current clock mode (FEI out of reset) */
   static McgInfo::ClockMode currentClockMode;

   /**
    *  Configure the MCG for given mode
    *
    *  @param mcr       Module Control Register
    */
   static void configure(McgInfo::ClockMode clockMode=McgInfo::clockMode ) {
      clockTransition(clockMode);
   }

   /**
    *   Disable the MCG channel
    */
   static void finalise() {
      clockTransition(McgInfo::ClockMode_FEI);
   }

   /**
    * Switch to/from high speed run mode
    * Changes the CPU clock frequency/1, and bus clock frequency /2
    * If the clock is set up for 120 MHz this will be the highest performance possible.
    *
    * This routine assumes that the clock preferences have been set up for the usual RUN mode and only
    * the Core clock divider needs to be changed.
    *
    * @param enable True to switch to HSRUN mode
    */
   static void hsRunMode(bool enable);

   /**
    * Sets up the clock out of RESET
    */
   static void initialise(void);
};

/**
 * @}
 */

} // End namespace USBDM

#endif /* INCLUDE_USBDM_MCG_H_ */
