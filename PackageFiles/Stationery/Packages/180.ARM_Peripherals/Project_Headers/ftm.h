/**
 * @file     ftm.h
 * @brief    GPIO Pin routines
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */
#ifndef HEADER_FTM_H
#define HEADER_FTM_H

#include <stddef.h>
#include <assert.h>
#include "derivative.h"
#include "bitband.h"

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
 * @addtogroup FTM_Group FTM, PWM, Input capture and Output compare
 * @brief Pins used for PWM, Input capture and Output compare
 * @{
 */
/**
 * Controls basic operation of PWM/Input capture
 */
enum Tmr_ChannelMode {
   //! Capture rising edge
   tmr_inputCaptureRisingEdge  = FTM_CnSC_MS(0)|FTM_CnSC_ELS(1),
   //! Capture falling edge
   tmr_inputCaptureFallingEdge = FTM_CnSC_MS(0)|FTM_CnSC_ELS(2),
   //! Capture both rising and falling edges
   tmr_inputCaptureEitherEdge  = FTM_CnSC_MS(0)|FTM_CnSC_ELS(3),
   //! Output compare operation
   tmr_outputCompare           = FTM_CnSC_MS(1),
   //! Toggle pin on output compare
   tmr_outputCompareToggle     = FTM_CnSC_MS(1)|FTM_CnSC_ELS(1),
   //! Clear pin on output compare
   tmr_outputCompareClear      = FTM_CnSC_MS(1)|FTM_CnSC_ELS(2),
   //! Set pin on output compare
   tmr_outputCompareSet        = FTM_CnSC_MS(1)|FTM_CnSC_ELS(3),
   //! PWM with high-true pulses
   tmr_pwmHighTruePulses       = FTM_CnSC_MS(2)|FTM_CnSC_ELS(2),
   //! PWM with low-true pulses
   tmr_pwmLowTruePulses        = FTM_CnSC_MS(2)|FTM_CnSC_ELS(1),
   //! Dual edge input capture one shot - CHn configuration
   tmr_dualEdgeCaptureOneShotRisingEdge     = FTM_CnSC_MS(0)|FTM_CnSC_ELS(1),
   //! Dual edge input capture continuous - CHn configuration
   tmr_dualEdgeCaptureContinuousRisingEdge  = FTM_CnSC_MS(1)|FTM_CnSC_ELS(1),
   //! Dual edge input capture one shot - CHn configuration
   tmr_dualEdgeCaptureOneShotFallingEdge     = FTM_CnSC_MS(0)|FTM_CnSC_ELS(2),
   //! Dual edge input capture continuous - CHn configuration
   tmr_dualEdgeCaptureContinuousFallingEdge  = FTM_CnSC_MS(1)|FTM_CnSC_ELS(2),
};

/**
 * Control alignment of PWM function
 */
enum Tmr_Mode {
   //! Left-aligned PWM - also used for input capture and output compare modes
   tmr_leftAlign   = 0,
   //! Centre-aligned PWM
   tmr_centreAlign = FTM_SC_CPWMS_MASK,
   //! Dummy value for Quadrature encoder
   tmr_quadrature  = 0,
} ;

/**
 * Type definition for LPTMR interrupt call back
 */
typedef void (*FTMCallbackFunction)(void);

/**
 * Base class representing an FTM
 *
 * Example
 * @code
 * // Instantiate the tmr (for FTM0)
 * const USBDM::TmrBase_T<FTM0_Info)> Ftm0;
 *
 * // Initialise PWM with initial period and alignment
 * Ftm0::setMode(200, USBDM::tmr_leftAlign);
 *
 * // Change timer period
 * Ftm0::setPeriod(500);
 * @endcode
 *
 * @tparam Info  Class describing FTM hardware instance
 */
template<class Info>
class TmrBase_T {

protected:
   static constexpr volatile FTM_Type* tmr      = reinterpret_cast<volatile FTM_Type*>(Info::basePtr);
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
   static void setMode(int period /* us */, Tmr_Mode mode=tmr_leftAlign) {
      // Configure pins
      Info::initPCRs();

      // Enable clock to timer
      *clockReg |= Info::clockMask;

      __DMB();

      // Common registers
      tmr->CNTIN   = 0;
      tmr->CNT     = 0;
      if (mode == tmr_centreAlign) {
         // Centre aligned PWM with CPWMS not selected
         tmr->SC   = Info::scValue|FTM_SC_CPWMS_MASK;
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
      bool centreAlign = (tmr->SC&FTM_SC_CPWMS_MASK) != 0;

      // Calculate period
      uint32_t tickRate = SystemBusClock/(1<<(tmr->SC&FTM_SC_PS_MASK));
      uint64_t period = ((uint64_t)per*tickRate)/1000000;

      // Disable FTM so register changes are immediate
      tmr->SC      = FTM_SC_CLKS(0);

      if (centreAlign) {
#ifdef DEBUG_BUILD
      if (period > 2*0xFFFFUL) {
         // Attempt to set too long a period
         __BKPT();
      }
#endif
         tmr->MOD = (uint32_t)(period/2);
         // Centre aligned PWM with CPWMS not selected
         tmr->SC  = Info::scValue|FTM_SC_CPWMS_MASK;
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
      uint32_t tickRate = SystemBusClock/(1<<(tmr->SC&FTM_SC_PS_MASK));
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
      uint32_t tickRate = SystemBusClock/(1<<(tmr->SC&FTM_SC_PS_MASK));
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
    *  Enables fault detection input
    *
    *  @tparam inputNum       Number of fault input to enable (0..3)
    *  @param  polarity       Polarity of fault input (true => active high))
    *  @param  filterEnable   Whether to enable filtering on the fault input
    *  @param  filterDelay    Delay used by the filter (1..15)
    *
    *  NOTE - the filter delay is shared by all inputs
    */
   template<uint8_t inputNum>
   static void enableFault(bool polarity=true, bool filterEnable=false, uint32_t filterDelay=FTM_FLTCTRL_FFVAL_MASK) {

#ifdef DEBUG_BUILD
   static_assert((inputNum<Info::InfoFAULT::NUM_SIGNALS), "Tmr_T: Illegal fault channel");
   static_assert((inputNum>=Info::InfoFAULT::NUM_SIGNALS)||(Info::InfoFAULT::info[inputNum].gpioBit != UNMAPPED_PCR), "Tmr_T: Fault signal is not mapped to a pin - Modify Configure.usbdm");
   static_assert((inputNum>=Info::InfoFAULT::NUM_SIGNALS)||(Info::InfoFAULT::info[inputNum].gpioBit != INVALID_PCR),  "Tmr_T: Non-existent signal used for fault input");
   static_assert((inputNum>=Info::InfoFAULT::NUM_SIGNALS)||(Info::InfoFAULT::info[inputNum].gpioBit == UNMAPPED_PCR)||(Info::InfoFAULT::info[inputNum].gpioBit == INVALID_PCR)||(Info::InfoFAULT::info[inputNum].gpioBit >= 0), "Pcr_T: Illegal signal used for fault");
#endif

      PcrTable_T<typename Info::InfoFAULT, inputNum>::setPCR();

      if (polarity) {
         // Set active high
         TmrBase_T<Info>::tmr->FLTPOL &= ~(1<<inputNum);
      }
      else {
         // Set active low
         TmrBase_T<Info>::tmr->FLTPOL |= (1<<inputNum);
      }
      if (filterEnable) {
         // Enable filter & set filter delay
         TmrBase_T<Info>::tmr->FLTCTRL = ((TmrBase_T<Info>::tmr->FLTCTRL) & ~(FTM_FLTCTRL_FFVAL_MASK)) | (1<<(inputNum+FTM_FLTCTRL_FFLTR0EN_SHIFT)) | FTM_FLTCTRL_FFVAL(filterDelay);
      }
      else {
         // Disable filter
         TmrBase_T<Info>::tmr->FLTCTRL &= ~(1<<(inputNum+FTM_FLTCTRL_FFLTR0EN_SHIFT));
      }
      // Enable fault input
      TmrBase_T<Info>::tmr->FLTCTRL |= (1<<inputNum);
   }

   /**
    *  Disables fault detection input
    *
    *  @tparam inputNum        Number of fault input to enable (0..3)
    */
   template<int inputNum>
   static void disableFault() {
      static_assert(inputNum<=4, "Illegal fault channel");

      // Enable fault on channel
      TmrBase_T<Info>::tmr->FLTCTRL &= ~(1<<inputNum);
   }

   /**
    * Set PWM duty cycle
    *
    * @param dutyCycle  Duty-cycle as percentage
    * @param tmrChannel Timer channel
    */
   static void setDutyCycle(int dutyCycle, int tmrChannel) {
      tmr->CONTROLS[tmrChannel].CnSC = tmr_pwmHighTruePulses;

      if (tmr->SC&FTM_SC_CPWMS_MASK) {
         tmr->CONTROLS[tmrChannel].CnV  = (dutyCycle*tmr->MOD)/100;
      }
      else {
         tmr->CONTROLS[tmrChannel].CnV  = (dutyCycle*(tmr->MOD+1))/100;
      }
   }
};

/**
 * Template class to provide FTM callback
 */
template<class Info>
class FtmIrq_T : public TmrBase_T<Info> {

protected:
   /** Callback function for ISR */
   static FTMCallbackFunction callback;

public:
   /**
    * IRQ handler
    */
   static void irqHandler() {
      if (callback != 0) {
         callback();
      }
   }

   /**
    * Set callback function
    *
    * @param callback Callback function to execute on interrupt
    */
   void setCallback(FTMCallbackFunction callback) {
      FtmIrq_T::callback = callback;
   }
};

template<class Info> FTMCallbackFunction FtmIrq_T<Info>::callback = 0;

#ifdef USBDM_FTM0_IS_DEFINED
/**
 * Template class representing a FTM0 timer channel
 *
 * Example
 * @code
 * // Instantiate the timer channel (for FTM0 channel 6)
 * using Ftm0_ch6 = USBDM::Ftm0Channel<6>;
 *
 * // Initialise PWM with initial period and alignment
 * Ftm0_ch6.setMode(200, PwmIO::tmr_leftAlign);
 *
 * // Change period (in ticks)
 * Ftm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * Ftm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam tmrChannel FTM timer channel
 */
template <int tmrChannel>
class Ftm0Channel : public TmrBase_T<Ftm0Info>, CheckSignal<Ftm0Info, tmrChannel> {

public:
   /**
    * Set PWM duty cycle
    *
    * @param dutyCycle  Duty-cycle as percentage
    */
   static void setDutyCycle(int dutyCycle) {
      TmrBase_T::setDutyCycle(dutyCycle, tmrChannel);
   }
};
/**
 * Class representing FTM0Ftm0Info::Ftm0Info
 */
using Ftm0 = FtmIrq_T<Ftm0Info>;
#endif

#ifdef USBDM_FTM1_IS_DEFINED
/**
 * Template class representing a FTM1 timer channel
 *
 * Refer @ref Ftm0Channel
 *
 * @tparam tmrChannel FTM timer channel
 */
template <int tmrChannel>
class Ftm1Channel : public TmrBase_T<Ftm1Info>, CheckSignal<Ftm1Info, tmrChannel> {
public:
   static void setDutyCycle(int dutyCycle) {
      TmrBase_T::setDutyCycle(dutyCycle, tmrChannel);
   }
};

/**
 * Class representing FTM1
 */
using Ftm1 = FtmIrq_T<Ftm1Info>;
#endif

#ifdef USBDM_FTM2_IS_DEFINED
/**
 * Template class representing a FTM2 timer channel
 *
 * Refer @ref Ftm0Channel
 *
 * @tparam tmrChannel FTM timer channel
 */
template <int tmrChannel>
class Ftm2Channel : public TmrBase_T<Ftm2Info>, CheckSignal<Ftm2Info, tmrChannel> {
public:
   static void setDutyCycle(int dutyCycle) {
      TmrBase_T::setDutyCycle(dutyCycle, tmrChannel);
   }
};

/**
 * Class representing FTM2
 */
using Ftm2 = FtmIrq_T<Ftm2Info>;
#endif

#ifdef USBDM_FTM3_IS_DEFINED
/**
 * Template class representing a FTM3 timer channel
 *
 * Refer @ref Ftm0Channel
 *
 * @tparam tmrChannel FTM timer channel
 */
template <int tmrChannel>
class Ftm3Channel : public TmrBase_T<Ftm3Info>, CheckSignal<Ftm3Info, tmrChannel> {
public:
   static void setDutyCycle(int dutyCycle) {
      TmrBase_T::setDutyCycle(dutyCycle, tmrChannel);
   }
};

/**
 * Class representing FTM0
 */
using Ftm3 = FtmIrq_T<Ftm3Info>;
#endif

/**
 * Template class representing a FTM configured as a Quadrature encoder
 *
 * @tparam info      Information class for FTM
 *
 * @code
 *  QuadEncoder_T<Ftm0Info> encoder0;
 *
 *  for(;;) {
 *     printf("Position = %d\n", encoder.getPosition());
 *  }
 * @endcode
 */
template <class Info>
class QuadEncoder_T : public TmrBase_T<Info> {

#ifdef DEBUG_BUILD
   static_assert(Info::InfoQUAD::info[0].gpioBit != UNMAPPED_PCR, "Tmr_T: FTM PHA is not mapped to a pin - Modify Configure.usbdm");
   static_assert(Info::InfoQUAD::info[1].gpioBit != UNMAPPED_PCR, "Tmr_T: FTM PHB is not mapped to a pin - Modify Configure.usbdm");
#endif

private:
   static constexpr volatile FTM_Type *ftm = reinterpret_cast<volatile FTM_Type *>(Info::basePtr);

public:
   static void enable() {
      Info::InfoQUAD::initPCRs();

      TmrBase_T<Info>::initialise(0, tmr_quadrature);

      ftm->QDCTRL =
            FTM_QDCTRL_QUADEN_MASK|      // Enable Quadrature encoder
            FTM_QDCTRL_QUADMODE_MASK|    // Count mode
            FTM_QDCTRL_PHAFLTREN_MASK|   // Phase A filter
            FTM_QDCTRL_PHBFLTREN_MASK;   // Phase B filter
      ftm->CONF   = FTM_CONF_BDMMODE(3);
      ftm->FILTER = FTM_FILTER_CH0FVAL(3)|FTM_FILTER_CH1FVAL(3);
   }
   /**
    * Reset position to zero
    */
   static void resetPosition() {
      ftm->CNT = 0;
   }
   /**
    * Get Quadrature encoder position
    */
   static uint16_t getPosition() {
      return ftm->CNT;
   }
};

/**
 * @}
 */
 
} // End namespace USBDM

#endif /* HEADER_FTM_H */

