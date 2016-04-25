/**
 * @file     tpm.h
 * @brief    GPIO Pin routines
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */
#ifndef HEADER_TPM_H
#define HEADER_TPM_H

#include <stddef.h>
#include <assert.h>
#include "derivative.h"
#include "bme.h"

/*
 * Default port information
 */

#ifndef TPM0_CLOCK_MASK
#ifdef SIM_SCGC6_TPM0_MASK
#define TPM0_CLOCK_MASK SIM_SCGC6_TPM0_MASK
#define TPM0_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC6_TPM1_MASK
#define TPM1_CLOCK_MASK SIM_SCGC6_TPM1_MASK
#define TPM1_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC6_TPM2_MASK
#define TPM2_CLOCK_MASK SIM_SCGC6_TPM2_MASK
#define TPM2_CLOCK_REG  SCGC6
#elif defined SIM_SCGC3_TPM2_MASK
#define TPM2_CLOCK_MASK SIM_SCGC3_TPM2_MASK
#define TPM2_CLOCK_REG  SCGC3
#endif
#ifdef SIM_SCGC6_TPM3_MASK
#define TPM3_CLOCK_MASK SIM_SCGC6_TPM3_MASK
#define TPM3_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC3_TPM3_MASK
#define TPM3_CLOCK_MASK SIM_SCGC3_TPM3_MASK
#define TPM3_CLOCK_REG  SCGC3
#endif
#ifdef SIM_SCGC3_TPM3_MASKC
#define TPM3_CLOCK_MASK SIM_SCGC3_TPM3_MASKC
#define TPM3_CLOCK_REG  SCGC3
#endif
#endif

namespace USBDM {

/**
 * @addtogroup TPM_Group TPM, PWM, Input capture and Output compare
 * @brief Pins used for PWM, Input capture and Output compare
 * @{
 */
/**
 * Controls basic operation of PWM/Input capture
 */
enum Tmr_ChannelMode {
   //! Capture rising edge
   tmr_inputCaptureRisingEdge  = TPM_CnSC_MS(0)|TPM_CnSC_ELS(1),
   //! Capture falling edge
   tmr_inputCaptureFallingEdge = TPM_CnSC_MS(0)|TPM_CnSC_ELS(2),
   //! Capture both rising and falling edges
   tmr_inputCaptureEitherEdge  = TPM_CnSC_MS(0)|TPM_CnSC_ELS(3),
   //! Output compare operation
   tmr_outputCompare           = TPM_CnSC_MS(1),
   //! Toggle pin on output compare
   tmr_outputCompareToggle     = TPM_CnSC_MS(1)|TPM_CnSC_ELS(1),
   //! Clear pin on output compare
   tmr_outputCompareClear      = TPM_CnSC_MS(1)|TPM_CnSC_ELS(2),
   //! Set pin on output compare
   tmr_outputCompareSet        = TPM_CnSC_MS(1)|TPM_CnSC_ELS(3),
   //! PWM with high-true pulses
   tmr_pwmHighTruePulses       = TPM_CnSC_MS(2)|TPM_CnSC_ELS(2),
   //! PWM with low-true pulses
   tmr_pwmLowTruePulses        = TPM_CnSC_MS(2)|TPM_CnSC_ELS(1),
};

/**
 * Control alignment of PWM function
 */
enum Tmr_Mode {
   //! Left-aligned PWM - also used for input capture and output compare modes
   tmr_leftAlign   = 0,
   //! Centre-aligned PWM
   tmr_centreAlign = TPM_SC_CPWMS_MASK,
} ;

/**
 * Type definition for TPM interrupt call back
 */
typedef void (*TPMCallbackFunction)(void);

/**
 * Base class representing an TPM
 *
 * Example
 * @code
 * // Instantiate the tmr (for TPM0)
 * const USBDM::TmrBase_T<TPM0_Info)> Tpm0;
 *
 * // Initialise PWM with initial period and alignment
 * Tpm0::initialise(200, USBDM::tmr_leftAlign);
 *
 * // Change timer period
 * Tpm0::setPeriod(500);
 * @endcode
 *
 * @tparam Info  Class describing TPM hardware instance
 */
template<class Info>
class TmrBase_T {
protected:
   static constexpr volatile TPM_Type* tmr      = reinterpret_cast<volatile TPM_Type*>(Info::basePtr);
   static constexpr volatile uint32_t *clockReg = reinterpret_cast<volatile uint32_t*>(Info::clockReg);

public:
   /**
    * Configure Timer operation
    *
    * @param period  Period in us
    * @param mode    Mode of operation see @ref Tmr_Mode
    *
    * @note Assumes prescale has been chosen as a appropriate value. Rudimentary range checking.
    */
   static void initialise(int period /* us */, Tmr_Mode mode=tmr_leftAlign) {
      // Configure pins
      Info::initPCRs();

      // Enable clock to timer
      *clockReg |= Info::clockMask;

      __DMB();

      // Common registers
      tmr->CNT     = 0;
      if (mode == tmr_centreAlign) {
         // Centre aligned PWM with CPWMS not selected
         tmr->SC   = Info::scValue|TPM_SC_CPWMS_MASK;
      }
      else {
         // Left aligned PWM without CPWMS selected
         tmr->SC   = Info::scValue;
      }
      setPeriod(period);
   }

   /**
    * Set period
    *
    * @param per Period in us
    *
    * @note Assumes prescale has been chosen as a appropriate value. Rudimentary range checking.
    */
   static void setPeriod(int per) {

      // Check if CPWMS is set (affects period)
      bool centreAlign = (tmr->SC&TPM_SC_CPWMS_MASK) != 0;

      // Calculate period
      uint32_t tickRate = SystemBusClock/(1<<(tmr->SC&TPM_SC_PS_MASK));
      uint64_t period = ((uint64_t)per*tickRate)/1000000;

      // Disable TPM so register changes are immediate
      tmr->SC = TPM_SC_PS(0);

      if (centreAlign) {
#ifdef DEBUG_BUILD
      if (period > 2*0xFFFFUL) {
         // Attempt to set too long a period
         __BKPT();
      }
#endif
         tmr->MOD = (uint32_t)(period/2);
         // Centre aligned PWM with CPWMS not selected
         tmr->SC  = Info::scValue|TPM_SC_CPWMS_MASK;
      }
      else {
#ifdef DEBUG_BUILD
      if (period > 0x10000UL) {
         // Attempt to set too long a period
         __BKPT();
      }
#endif
         tmr->MOD = (uint32_t)(period-1);
         // Left aligned PWM without CPWMS selected
         tmr->SC  = Info::scValue;
      }
   }
   /**
    * Converts a time in microseconds to number of ticks
    *
    * @param time Time in microseconds
    * @return Time in ticks
    *
    * @note Assumes prescale has been chosen as a appropriate value. Rudimentary range checking.
    */
   static uint32_t convertMicrosecondsToTicks(int time) {

      // Calculate period
      uint32_t tickRate = SystemBusClock/(1<<(tmr->SC&TPM_SC_PS_MASK));
      uint64_t rv       = ((uint64_t)time*tickRate)/1000000;
#ifdef DEBUG_BUILD
      assert(rv > 0xFFFFUL);
      if (rv > 0xFFFFUL) {
         // Attempt to set too long a period
         __BKPT();
      }
#endif
      return rv;
   }
   /**
    * Converts ticks to time in microseconds
    *
    * @param time Time in ticks
    * @return Time in microseconds
    *
    * @note Assumes prescale has been chosen as a appropriate value. Rudimentary range checking.
    */
   static uint32_t convertTicksToMicroseconds(int time) {

      // Calculate period
      uint32_t tickRate = SystemBusClock/(1<<(tmr->SC&TPM_SC_PS_MASK));
      uint64_t rv       = ((uint64_t)time*1000000)/tickRate;
#ifdef DEBUG_BUILD
      if (rv > 0xFFFFUL) {
         // Attempt to set too long a period
         __BKPT();
      }
#endif
      return rv;
   }
   /**
    * Set PWM duty cycle
    *
    * @param dutyCycle  Duty-cycle as percentage
    * @param tmrChannel Timer channel
    */
   static void setDutyCycle(int dutyCycle, int tmrChannel) {
      tmr->CONTROLS[tmrChannel].CnSC = tmr_pwmHighTruePulses;

      if (tmr->SC&TPM_SC_CPWMS_MASK) {
         tmr->CONTROLS[tmrChannel].CnV  = (dutyCycle*tmr->MOD)/100;
      }
      else {
         tmr->CONTROLS[tmrChannel].CnV  = (dutyCycle*(tmr->MOD+1))/100;
      }
   }
};

/**
 * Template class to provide TPM callback
 */
template<class Info>
class TpmIrq_T : public TmrBase_T<Info> {

protected:
   /** Callback function for ISR */
   static TPMCallbackFunction callback;

public:
   /**
    * IRQ handler
    */
   static void irqHandler() {
      if (callback != 0) {
         callback();
      }
   }
};

template<class Info> TPMCallbackFunction TpmIrq_T<Info>::callback = 0;

#ifdef USBDM_TPM0_IS_DEFINED
/**
 * Template class representing a TPM0 timer channel
 *
 * Example
 * @code
 * // Instantiate the timer channel (for TPM0 channel 6)
 *
 * using ftm0_ch6 = USBDM::Tpm0Channel<6>;
 *
 * // Initialise PWM with initial period and alignment
 * ftm0_ch6.initialise(200, PwmIO::tmr_leftAlign);
 *
 * // Change period (in ticks)
 * ftm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * ftm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam tmrChannel TPM timer channel
 */
template <int tmrChannel>
class Tpm0Channel : public TmrBase_T<Tpm0Info> {
public:
   static void setDutyCycle(int dutyCycle) {
      TmrBase_T::setDutyCycle(dutyCycle, tmrChannel);
   }
};
/**
 * Class representing TPM0
 */
using Tpm0 = TpmIrq_T<Tpm0Info>;
#endif

#ifdef USBDM_TPM1_IS_DEFINED
/**
 * Template class representing a TPM1 timer channel
 *
 * Refer @ref Tpm0Channel
 *
 * @tparam tmrChannel TPM timer channel
 */
template <int tmrChannel>
class Tpm1Channel : public TmrBase_T<Tpm1Info> {
public:
   static void setDutyCycle(int dutyCycle) {
      TmrBase_T::setDutyCycle(dutyCycle, tmrChannel);
   }
};

/**
 * Class representing TPM1
 */
using Tpm1 = TpmIrq_T<Tpm1Info>;
#endif

#ifdef USBDM_TPM2_IS_DEFINED
/**
 * Template class representing a TPM2 timer channel
 *
 * Refer @ref Tpm0Channel
 *
 * @tparam tmrChannel TPM timer channel
 */
template <int tmrChannel>
class Tpm2Channel : public TmrBase_T<Tpm2Info> {
public:
   static void setDutyCycle(int dutyCycle) {
      TmrBase_T::setDutyCycle(dutyCycle, tmrChannel);
   }
};

/**
 * Class representing TPM2
 */
using Tpm2 = TpmIrq_T<Tpm2Info>;
#endif

#ifdef USBDM_TPM3_IS_DEFINED
/**
 * Template class representing a TPM3 timer channel
 *
 * Refer @ref Tpm0Channel
 *
 * @tparam tmrChannel TPM timer channel
 */
template <int tmrChannel>
class Tpm3Channel : public TmrBase_T<Tpm3Info> {
public:
   static void setDutyCycle(int dutyCycle) {
      TmrBase_T::setDutyCycle(dutyCycle, tmrChannel);
   }
};

/**
 * Class representing TPM0
 */
using Tpm3 = TpmIrq_T<Tpm3Info>;
#endif

/**
 * @}
 */
 
} // End namespace USBDM

#endif /* HEADER_TPM_H */

