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

#ifndef FTM0_CLOCK_MASK
#ifdef SIM_SCGC6_FTM0_MASK
#define FTM0_CLOCK_MASK SIM_SCGC6_FTM0_MASK
#define FTM0_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC6_FTM1_MASK
#define FTM1_CLOCK_MASK SIM_SCGC6_FTM1_MASK
#define FTM1_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC6_FTM2_MASK
#define FTM2_CLOCK_MASK SIM_SCGC6_FTM2_MASK
#define FTM2_CLOCK_REG  SCGC6
#elif defined SIM_SCGC3_FTM2_MASK
#define FTM2_CLOCK_MASK SIM_SCGC3_FTM2_MASK
#define FTM2_CLOCK_REG  SCGC3
#endif
#ifdef SIM_SCGC6_FTM3_MASK
#define FTM3_CLOCK_MASK SIM_SCGC6_FTM3_MASK
#define FTM3_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC3_FTM3_MASK
#define FTM3_CLOCK_MASK SIM_SCGC3_FTM3_MASK
#define FTM3_CLOCK_REG  SCGC3
#endif
#ifdef SIM_SCGC3_FTM3_MASKC
#define FTM3_CLOCK_MASK SIM_SCGC3_FTM3_MASKC
#define FTM3_CLOCK_REG  SCGC3
#endif
#endif

namespace USBDM {

/**
 * @addtogroup PwmIO_Group PWM, Input capture, Output compare
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
 * Template class representing the functions controlling the shared hardware of an TPM
 *
 * Example
 * @code
 * // Instantiate the tmr (for TPM0)
 * const USBDM::Tmr<TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, TPM0_SC> Tmr0;
 *
 * // Initialise PWM with initial period and alignment
 * tmr0.setMode(200, USBDM::tmr_leftAlign);
 *
 * // Change period (in ticks)
 * tmr0.setPeriod(500);
 * @endcode
 *
 * @tparam tmrBase       TPM hardware
 * @tparam tmrClockReg   SIM Clock register for TPM
 * @tparam tmrClockMask  Mask for TPM clock register
 * @tparam scValue       Value for TPM->SC register
 */
template<uint32_t tmrBase, uint32_t tmrClockReg, uint32_t tmrClockMask, uint16_t scValue>
class Tmr {
protected:
   static constexpr volatile TPM_Type* tmr      = reinterpret_cast<volatile TPM_Type*>(tmrBase);
   static constexpr volatile uint32_t *clockReg = reinterpret_cast<volatile uint32_t*>(tmrClockReg);

public:
   /**
    * Configure Timer operation
    *
    * @param period  Period in us
    * @param mode    Mode of operation see @ref Tmr_Mode
    *
    * @note Assumes prescale has been chosen as a appropriate value. Rudimentary range checking.
    */
   static void setMode(int period /* us */, Tmr_Mode mode=tmr_leftAlign) {

      // Enable clock to timer
      *clockReg |= tmrClockMask;

      // Common registers
      tmr->CNT     = 0;
      if (mode == tmr_centreAlign) {
         // Centre aligned PWM with CPWMS not selected
         tmr->SC   = scValue|TPM_SC_CPWMS_MASK;
      }
      else {
         // Left aligned PWM without CPWMS selected
         tmr->SC   = scValue;
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

      // Disable FTM so register changes are immediate
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
         tmr->SC  = scValue|TPM_SC_CPWMS_MASK;
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
         tmr->SC  = scValue;
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
};

/**
 * Template class representing a pin with PWM capability\n
 * Makes use of an auxiliary class having channel specific information
 *
 * Example
 * @code
 * // Instantiate the tmr channel (for FTM0 CH6, auxiliary table tmr0Table)
 *
 * const USBDM::TmrBase_T<ftm0Info, 6> tmr0_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * tmr0_ch6.setMode(200, PwmIO::tmr_leftAlign);
 *
 * // Change period (in ticks)
 * tmr0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * tmr0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam info            Table providing pin specific information for the FTM
 * @tparam tmrChannel      FTM channel
 * @tparam pcrValue        Default value for PCR including mux value
 */
template<class info, uint32_t tmrChannel, uint32_t pcrValue=info::pcrValue>
class TmrBase_T : public Tmr<info::basePtr, info::clockReg, info::clockMask, info::scValue> {

#ifdef DEBUG_BUILD
   static_assert((tmrChannel<info::NUM_SIGNALS), "TmrBase_T: Non-existent timer channel - Modify Configure.usbdmProject");
   static_assert((tmrChannel>=info::NUM_SIGNALS)||(info::info[tmrChannel].gpioBit != UNMAPPED_PCR), "TmrBase_T: FTM channel is not mapped to a pin - Modify Configure.usbdmProject");
   static_assert((tmrChannel>=info::NUM_SIGNALS)||(info::info[tmrChannel].gpioBit != INVALID_PCR),  "TmrBase_T: FTM channel doesn't exist in this device/package");
   static_assert((tmrChannel>=info::NUM_SIGNALS)||(info::info[tmrChannel].gpioBit == UNMAPPED_PCR)||(info::info[tmrChannel].gpioBit == INVALID_PCR)||(info::info[tmrChannel].gpioBit >= 0),
         "TmrBase_T: Illegal FTM channel");
#endif

private:
   static constexpr volatile TPM_Type *tmr = reinterpret_cast<volatile TPM_Type *>(info::basePtr);

public:
   using Pcr = PcrTable_T<info, (tmrChannel>=info::NUM_SIGNALS)?0:tmrChannel, pcrValue>;

   /**
    * Configure Timer operation
    *
    * @param period  Period in us
    * @param mode    Mode of operation see @ref Tmr_Mode
    */
   static void setMode(int period /* us */, Tmr_Mode mode=tmr_leftAlign) {
      Tmr<info::basePtr, info::clockReg, info::clockMask, info::scValue>::setMode(period, mode);

      // Set up pin
      Pcr::setPCR();
   }
   /**
    * Set PWM duty cycle
    *
    * @param dutyCycle Duty-cycle as percentage
    */
   static void setDutyCycle(int dutyCycle) {
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
 * @}
 */
 
} // End namespace USBDM

#endif /* HEADER_TPM_H */

