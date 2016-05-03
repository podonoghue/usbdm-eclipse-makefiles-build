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
enum Ftm_ChannelMode {
   //! Capture rising edge
   ftm_inputCaptureRisingEdge  = FTM_CnSC_MS(0)|FTM_CnSC_ELS(1),
   //! Capture falling edge
   ftm_inputCaptureFallingEdge = FTM_CnSC_MS(0)|FTM_CnSC_ELS(2),
   //! Capture both rising and falling edges
   ftm_inputCaptureEitherEdge  = FTM_CnSC_MS(0)|FTM_CnSC_ELS(3),
   //! Output compare operation
   ftm_outputCompare           = FTM_CnSC_MS(1),
   //! Toggle pin on output compare
   ftm_outputCompareToggle     = FTM_CnSC_MS(1)|FTM_CnSC_ELS(1),
   //! Clear pin on output compare
   ftm_outputCompareClear      = FTM_CnSC_MS(1)|FTM_CnSC_ELS(2),
   //! Set pin on output compare
   ftm_outputCompareSet        = FTM_CnSC_MS(1)|FTM_CnSC_ELS(3),
   //! PWM with high-true pulses
   ftm_pwmHighTruePulses       = FTM_CnSC_MS(2)|FTM_CnSC_ELS(2),
   //! PWM with low-true pulses
   ftm_pwmLowTruePulses        = FTM_CnSC_MS(2)|FTM_CnSC_ELS(1),
   //! Dual edge input capture one shot - CHn configuration
   ftm_dualEdgeCaptureOneShotRisingEdge     = FTM_CnSC_MS(0)|FTM_CnSC_ELS(1),
   //! Dual edge input capture continuous - CHn configuration
   ftm_dualEdgeCaptureContinuousRisingEdge  = FTM_CnSC_MS(1)|FTM_CnSC_ELS(1),
   //! Dual edge input capture one shot - CHn configuration
   ftm_dualEdgeCaptureOneShotFallingEdge     = FTM_CnSC_MS(0)|FTM_CnSC_ELS(2),
   //! Dual edge input capture continuous - CHn configuration
   ftm_dualEdgeCaptureContinuousFallingEdge  = FTM_CnSC_MS(1)|FTM_CnSC_ELS(2),
};

/**
 * Control alignment of PWM function
 */
enum Ftm_Mode {
   //! Left-aligned PWM - also used for input capture and output compare modes
   ftm_leftAlign   = 0,
   //! Centre-aligned PWM
   ftm_centreAlign = FTM_SC_CPWMS_MASK,
   //! Dummy value for Quadrature encoder
   ftm_quadrature  = 0,
} ;

/**
 * Type definition for FTM interrupt call back
 */
typedef void (*FTMCallbackFunction)(void);

/**
 * Base class representing an FTM
 *
 * Example
 * @code
 * // Instantiate the tmr (for FTM0)
 * const USBDM::FtmBase_T<FTM0_Info)> Ftm0;
 *
 * // Initialise PWM with initial period and alignment
 * Ftm0::setMode(200, USBDM::ftm_leftAlign);
 *
 * // Change timer period
 * Ftm0::setPeriod(500);
 * @endcode
 *
 * @tparam Info  Class describing FTM hardware instance
 */
template<class Info>
class FtmBase_T {

protected:
   static constexpr volatile FTM_Type* tmr      = reinterpret_cast<volatile FTM_Type*>(Info::basePtr);
   static constexpr volatile uint32_t *clockReg = reinterpret_cast<volatile uint32_t*>(Info::clockReg);

public:
   /**
    * Enable with default settings\n
    * Includes configuring all pins
    */
   static void enable() {
      // Configure pins
      Info::initPCRs();

      // Enable clock to timer
      *clockReg |= Info::clockMask;

      __DMB();

      // Common registers
      tmr->CNTIN   = 0;
      tmr->CNT     = 0;
      tmr->MOD     = Info::PERIOD;
      tmr->SC      = Info::SC;

      if (Info::SC & FTM_SC_TOIE_MASK) {
         // Enable interrupts
         NVIC_EnableIRQ(Info::irqNums[0]);

         // Set priority level
         NVIC_SetPriority(Info::irqNums[0], Info::irqLevel);
      }
   }

   /**
    * Configure Timer operation\n
    * Used to change configuration after enabling interface
    *
    * @param period  Period in us
    * @param mode    Mode of operation see @ref Ftm_Mode
    *
    * @note Assumes prescale has been chosen as a appropriate value. Rudimentary range checking.
    */
   static void configure(int period /* us */, Ftm_Mode mode=ftm_leftAlign) {

      tmr->SC      = mode;
      if (mode == ftm_centreAlign) {
         // Centre aligned PWM with CPWMS not selected
         tmr->SC   = Info::SC|FTM_SC_CPWMS_MASK;
      }
      else {
         // Left aligned PWM without CPWMS selected
         tmr->SC   = Info::SC;
      }
      setPeriod(period);

      if (tmr->SC & FTM_SC_TOIE_MASK) {
         // Enable interrupts
         NVIC_EnableIRQ(Info::irqNums[0]);

         // Set priority level
         NVIC_SetPriority(Info::irqNums[0], Info::irqLevel);
      }
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
      tmr->SC = FTM_SC_CLKS(0);

      if (centreAlign) {
#ifdef DEBUG_BUILD
      if (period > 2*0xFFFFUL) {
         // Attempt to set too long a period
         __BKPT();
      }
#endif
         tmr->MOD = (uint32_t)(period/2);
         // Centre aligned PWM with CPWMS not selected
         tmr->SC  = Info::SC|FTM_SC_CPWMS_MASK;
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
         tmr->SC  = Info::SC;
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
public:
   template<uint8_t inputNum>
   static void enableFault(bool polarity=true, bool filterEnable=false, uint32_t filterDelay=FTM_FLTCTRL_FFVAL_MASK) {

#ifdef DEBUG_BUILD
   static_assert((inputNum<Info::InfoFAULT::NUM_SIGNALS), "FtmBase_T: Illegal fault channel");
   static_assert((inputNum>=Info::InfoFAULT::NUM_SIGNALS)||(Info::InfoFAULT::info[inputNum].gpioBit != UNMAPPED_PCR), "FtmBase_T: Fault signal is not mapped to a pin - Modify Configure.usbdm");
   static_assert((inputNum>=Info::InfoFAULT::NUM_SIGNALS)||(Info::InfoFAULT::info[inputNum].gpioBit != INVALID_PCR),  "FtmBase_T: Non-existent signal used for fault input");
   static_assert((inputNum>=Info::InfoFAULT::NUM_SIGNALS)||(Info::InfoFAULT::info[inputNum].gpioBit == UNMAPPED_PCR)||(Info::InfoFAULT::info[inputNum].gpioBit == INVALID_PCR)||(Info::InfoFAULT::info[inputNum].gpioBit >= 0), "Pcr_T: Illegal signal used for fault");
#endif

      PcrTable_T<typename Info::InfoFAULT, inputNum>::setPCR();

      if (polarity) {
         // Set active high
         tmr->FLTPOL &= ~(1<<inputNum);
      }
      else {
         // Set active low
         tmr->FLTPOL |= (1<<inputNum);
      }
      if (filterEnable) {
         // Enable filter & set filter delay
         tmr->FLTCTRL = ((tmr->FLTCTRL) & ~(FTM_FLTCTRL_FFVAL_MASK)) | (1<<(inputNum+FTM_FLTCTRL_FFLTR0EN_SHIFT)) | FTM_FLTCTRL_FFVAL(filterDelay);
      }
      else {
         // Disable filter
         tmr->FLTCTRL &= ~(1<<(inputNum+FTM_FLTCTRL_FFLTR0EN_SHIFT));
      }
      // Enable fault input
      tmr->FLTCTRL |= (1<<inputNum);
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
      tmr->FLTCTRL &= ~(1<<inputNum);
   }

   /**
    * Set PWM duty cycle
    *
    * @param dutyCycle  Duty-cycle as percentage
    * @param channel Timer channel
    */
   static void setDutyCycle(int dutyCycle, int channel) {
      tmr->CONTROLS[channel].CnSC = ftm_pwmHighTruePulses;

      if (tmr->SC&FTM_SC_CPWMS_MASK) {
         tmr->CONTROLS[channel].CnV  = (dutyCycle*tmr->MOD)/100;
      }
      else {
         tmr->CONTROLS[channel].CnV  = (dutyCycle*(tmr->MOD+1))/100;
      }
   }
};

/**
 * Template class to provide FTM callback
 */
template<class Info>
class FtmIrq_T : public FtmBase_T<Info> {

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
	  // Clear interrupt
      FtmBase_T<Info>::tmr->SC &= ~FTM_SC_TOF_MASK;
   }

   /**
    * Set callback function
    *
    * @param callback Callback function to execute on interrupt
    */
   static void setCallback(FTMCallbackFunction theCallback) {
      callback = theCallback;
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
 * Ftm0_ch6.setMode(200, PwmIO::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * Ftm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * Ftm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam channel FTM timer channel
 */
template <int channel>
class Ftm0Channel : public FtmBase_T<Ftm0Info>, CheckSignal<Ftm0Info, channel> {

public:
   /**
    * Set PWM duty cycle
    *
    * @param dutyCycle  Duty-cycle as percentage
    */
   static void setDutyCycle(int dutyCycle) {
      FtmBase_T::setDutyCycle(dutyCycle, channel);
   }
};
/**
 * Class representing FTM0
 */
using Ftm0 = FtmIrq_T<Ftm0Info>;
#endif

#ifdef USBDM_FTM1_IS_DEFINED
/**
 * Template class representing a FTM1 timer channel
 *
 * Refer @ref Ftm0Channel
 *
 * @tparam channel FTM timer channel
 */
template <int channel>
class Ftm1Channel : public FtmBase_T<Ftm1Info>, CheckSignal<Ftm1Info, channel> {
public:
   static void setDutyCycle(int dutyCycle) {
      FtmBase_T::setDutyCycle(dutyCycle, channel);
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
 * @tparam channel FTM timer channel
 */
template <int channel>
class Ftm2Channel : public FtmBase_T<Ftm2Info>, CheckSignal<Ftm2Info, channel> {
public:
   static void setDutyCycle(int dutyCycle) {
      FtmBase_T::setDutyCycle(dutyCycle, channel);
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
 * @tparam channel FTM timer channel
 */
template <int channel>
class Ftm3Channel : public FtmBase_T<Ftm3Info>, CheckSignal<Ftm3Info, channel> {
public:
   static void setDutyCycle(int dutyCycle) {
      FtmBase_T::setDutyCycle(dutyCycle, channel);
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
class QuadEncoder_T : public FtmBase_T<Info> {

#ifdef DEBUG_BUILD
   static_assert(Info::InfoQUAD::info[0].gpioBit != UNMAPPED_PCR, "QuadEncoder_T: FTM PHA is not mapped to a pin - Modify Configure.usbdm");
   static_assert(Info::InfoQUAD::info[1].gpioBit != UNMAPPED_PCR, "QuadEncoder_T: FTM PHB is not mapped to a pin - Modify Configure.usbdm");
#endif

private:
   static constexpr volatile FTM_Type *ftm = reinterpret_cast<volatile FTM_Type *>(Info::basePtr);

public:
   static void enable() {
      Info::InfoQUAD::initPCRs();

      FtmBase_T<Info>::initialise(0, ftm_quadrature);

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

