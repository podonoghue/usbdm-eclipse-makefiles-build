/**
 * @file     gpio_defs.h (from gpio_defs-MK.h)
 * @brief    GPIO Pin routines
 *
 * @version  V4.11.1.70
 * @date     18 June 2015
 */
#ifndef HEADER_GPIO_DEFS_H
#define HEADER_GPIO_DEFS_H

#include "derivative.h"
#include "utilities.h"
#include "pin_mapping.h"

namespace USBDM {

/*!
 * @brief Template representing a PCR register
 *
 * @details
 * @code
 * // Enable clock to associated PORT
 * pcr.enableClock();
 *
 * // Configure PCR
 * pcr.setPCR(PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_MUX(3));
 * @endcode
 *
 * @tparam clockMask       Mask for clock register for port associated with this PCR
 * @tparam pcrReg          PCR to be manipulated
 * @tparam defaultPcrValue Default value for PCR
 */
template<uint32_t clockMask, uint32_t pcrReg, uint32_t defaultPcrValue> class PCRInit {
public:
   /**
    * Set pin PCR value\n
    * The clock to the port will be enabled before changing the PCR
    *
    * @param pcrValue PCR value made up of PORT_PCR_ masks
    *
    */
   void setPCR(uint32_t pcrValue= defaultPcrValue) const  {
      if (pcrReg != 0) {
         enableClock();
         *reinterpret_cast<volatile uint32_t *>(pcrReg) = pcrValue;
      }
   }
   /**
    * Enable clock to port
    */
   void enableClock() const {
      FIXED_PORT_CLOCK_REG |= clockMask;
   }
   /**
    * Disable clock to port
    */
   void disableClock() const {
      FIXED_PORT_CLOCK_REG &= ~clockMask;
   }
};

/**
 * @addtogroup DigitalIO_Group Digital Input/Output
 * @{
 */

/*!
 * @brief Template representing a pin with Digital I/O capability
 *
 * <b>Example</b>
 * @code
 * // Set as digital output
 * DigitalIO_A3.setDigitalOutput();
 *
 * // Set pin high
 * DigitalIO_A3.set();
 *
 * // Set pin low
 * DigitalIO_A3.clear();
 *
 * // Toggle pin
 * DigitalIO_A3.toggle();
 *
 * // Set pin to boolean value
 * DigitalIO_A3.write(true);
 *
 * // Set pin to boolean value
 * DigitalIO_A3.write(false);
 *
 * @endcode
 */
template<uint32_t portClockMask, uint32_t pcrReg, uint32_t gpio, const uint32_t bitMask> class DigitalIO {
public:
   /**
    * Default PCR setting for pins (excluding multiplexor value)
    * High drive strength + Pull-up
    */
   static const uint32_t    DEFAULT_PCR      = (PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
   /**
    * PCR multiplexor value for digital function
    */
   static const uint32_t    GPIO_PORT_FN     = PORT_PCR_MUX(FIXED_GPIO_FN);
   /**
    * Default PCR value for pins used as GPIO (including multiplexor value)
    */
   static const uint32_t    GPIO_DEFAULT_PCR = DEFAULT_PCR|GPIO_PORT_FN;

   PCRInit<portClockMask, pcrReg, GPIO_DEFAULT_PCR> pcr; //!< PCR information

   DigitalIO() {}

   /**
    * Toggle pin
    */
   void toggle() const {
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PTOR = bitMask;
   }
   /**
    * Set pin high
    */
   void set() const {
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PSOR = bitMask;
   }
   /**
    * Set pin low
    */
   void clear() const {
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PCOR = bitMask;
   }
   /**
    * Set pin as digital output
    *
    * @param pcrValue PCR value to use in configuring port
    */
   void setDigitalOutput(uint32_t pcrValue=GPIO_DEFAULT_PCR) const  {
      pcr.setPCR(pcrValue);
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PDDR |= bitMask;
   }
   /**
    * Set pin as digital input
    *
    * @param pcrValue PCR value to use in configuring port
    */
   void setDigitalInput(uint32_t pcrValue=GPIO_DEFAULT_PCR) const  {
      pcr.setPCR(pcrValue);
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PDDR &= ~bitMask;
   }
   /**
    * Write boolean value to digital output
    *
    * @param value high/low value
    */
   void write(bool value) const {
      if (value) {
         set();
      }
      else {
         clear();
      }
   }
   /**
    * Read digital input as boolean
    *
    * @return true/false reflecting pin value
    */
   bool read() const {
      return ( reinterpret_cast<volatile GPIO_Type *>(gpio)->PDIR & bitMask);
   }
};

/**
 * @}
 */

/**
 * @addtogroup AnalogueIO_Group Analogue Input
 * @{
 */

class AnalogueIO {
protected:
   AnalogueIO() {}

public:
   /**
    * PCR multiplexor value for analogue function
    */
   static const uint32_t    GPIO_ANALOGUE_FN = PORT_PCR_MUX(FIXED_ADC_FN);

   enum {
      resolution_8bit_se    = ADC_CFG1_MODE(0),
      resolution_10bit_se   = ADC_CFG1_MODE(2),
      resolution_12bit_se   = ADC_CFG1_MODE(1),
      resolution_16bit_se   = ADC_CFG1_MODE(3),
      resolution_9bit_diff  = ADC_CFG1_MODE(0),
      resolution_11bit_diff = ADC_CFG1_MODE(2),
      resolution_12bit_diff = ADC_CFG1_MODE(1),
      resolution_16bit_diff = ADC_CFG1_MODE(3),
   } ADC_Resolution;
};

/**
 * Class representing a pin with Analogue Input capability
 *
 * Example
 * @code
 *  // Initialise ADC
 *  AnalogueIO_A2.initialiseADC();
 *  // Set as analogue input
 *  AnalogueIO_A2.setAnalogueInput();
 *  // Read input
 *  uint16_t value = AnalogueIO_A2.readAnalogue();
 *  @endcode
 */
template<uint32_t portClockMask, uint32_t pcrReg, uint32_t adc, uint32_t adcClockReg, uint32_t adcClockMask, uint8_t adcChannel> class AnalogueIOT : AnalogueIO {
public:
   PCRInit<portClockMask, pcrReg, PORT_PCR_MUX(FIXED_ADC_FN)> pcr; //!< PCR information

   AnalogueIOT() {}

   /**
    * Set port pin as analogue input
    *
    * @param mode Mode for converter (currently only resolution)
    *
    * @note This initialises the ADC
    */
   void setMode(uint32_t mode = resolution_16bit_se) const {
      // Enable clock to ADC
      *reinterpret_cast<volatile uint32_t*>(adcClockReg)  |= adcClockMask;
      pcr.setPCR(PORT_PCR_MUX(FIXED_ADC_FN));

      // Configure ADC for software triggered conversion
      reinterpret_cast<volatile ADC_Type*>(adc)->CFG1 = ADC_CFG1_ADIV(1)|mode|ADC_CFG1_ADLSMP_MASK|ADC_CFG1_ADICLK(0);
      reinterpret_cast<volatile ADC_Type*>(adc)->SC2  = 0;
      reinterpret_cast<volatile ADC_Type*>(adc)->CFG2 = ADC_CFG2_ADLSTS(0)|ADC_CFG2_MUXSEL_MASK; // Choose 'b' channels
   }
   /**
    * Initiates a conversion and waits for it to complete
    *
    * @return - the result of the conversion
    */
   int readAnalogue() const {

      // Trigger conversion
      reinterpret_cast<volatile ADC_Type*>(adc)->SC1[0] = ADC_SC1_ADCH(adcChannel);

      while ((reinterpret_cast<volatile ADC_Type*>(adc)->SC1[0]&ADC_SC1_COCO_MASK) == 0) {
         __asm__("nop");
      }
      return (int)reinterpret_cast<volatile ADC_Type*>(adc)->R[0];
   };
};
/**
 * @}
 */

/**
 * @addtogroup PwmIO_Group PWM, Input capture, Output compare
 * @{
 */
/**
 * Base class for PWM
 */
struct PwmIO {
protected:
   PwmIO() {}

public:
   /**
    * Controls basic operation of PWM/Input capture
    */
   typedef enum  {
      //! Capture rising edge
      ftm_inputCaptureRisingEdge  = TPM_CnSC_ELSA_MASK,
      //! Capture falling edge
      ftm_inputCaptureFallingEdge = TPM_CnSC_ELSB_MASK,
      //! Capture both rising and falling edges
      ftm_inputCaptureEitherEdge  = TPM_CnSC_ELSB_MASK|TPM_CnSC_ELSA_MASK,
      //! Output compare operation
      ftm_outputCompare           = TPM_CnSC_MSA_MASK,
      //! Toggle pin on output compare
      ftm_outputCompareToggle     = TPM_CnSC_MSA_MASK|TPM_CnSC_ELSA_MASK,
      //! Clear pin on output compare
      ftm_outputCompareClear      = TPM_CnSC_MSA_MASK|TPM_CnSC_ELSB_MASK,
      //! Set pin on output compare
      ftm_outputCompareSet        = TPM_CnSC_MSA_MASK|TPM_CnSC_ELSB_MASK|TPM_CnSC_ELSA_MASK,
      //! PWM with high-true pulses
      ftm_pwmHighTruePulses       = TPM_CnSC_MSB_MASK|TPM_CnSC_ELSB_MASK,
      //! PWM with low-true pulses
      ftm_pwmLowTruePulses        = TPM_CnSC_MSB_MASK|TPM_CnSC_ELSA_MASK,
   } Ftm_Mode;

   /**
    * Control alignment of PWM function
    */
   typedef enum {
      //! Left-aligned
      ftm_leftAlign   = 0,
      //! Centre-aligned
      ftm_centreAlign = TPM_SC_CPWMS_MASK,
   } Pwm_Mode;
   /**
    * Default PCR setting for pins (excluding multiplexor value)
    * High drive strength + Pull-up
    */
   static const uint32_t    DEFAULT_PCR      = (PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
};

/**
 * Class representing a pin with PWM capability
 *
 * Example
 * @code
 * // Initialise PWM with initial period and alignment
 * pwmIO_D5.setPwmOutput(200, PwmIO::ftm_leftAlign);
 * // Change period (in ticks)
 * pwmIO_D5.setPeriod(500);
 * // Change duty cycle (in percent)
 * pwmIO_D5.setDutyCycle(45);
 * @endcode
 */
template<uint32_t portClockMask, uint32_t pcrReg, uint32_t ftm, uint32_t ftmClockReg, uint32_t ftmClockMask, uint8_t ftmChannel, uint32_t ftmMuxFn> class PwmIOT : PwmIO {
public:
   PCRInit<portClockMask, pcrReg, PORT_PCR_MUX(FIXED_ADC_FN)> pcr; //!< PCR information
   static const uint32_t scValue = FTM_SC_CLKS(1)|FTM_SC_PS(0);    //!< FTM->SC base value (clock selection & divider)

   PwmIOT() {}

   /**
    * Configure PWM operation
    *
    * @param period  Period in timer ticks
    * @param mode    Mode of operation see @ref Pwm_Mode
    */
   void setPwmOutput(int period /* ticks */, Pwm_Mode mode=ftm_centreAlign) const {
      pcr.setPCR(PORT_PCR_MUX(ftmMuxFn)|DEFAULT_PCR);

      // Enable clock to timer
      *reinterpret_cast<uint32_t*>(ftmClockMask) |= ftmClockMask;

      // Common registers
      reinterpret_cast<volatile FTM_Type*>(ftm)->SC      = TPM_SC_PS(0); // Disable FTM so register changes are immediate
      reinterpret_cast<volatile FTM_Type*>(ftm)->CNT     = 0;
      if (mode == ftm_centreAlign) {
         reinterpret_cast<volatile FTM_Type*>(ftm)->MOD     = period/2;
         // Centre aligned PWM with CPWMS not selected
         reinterpret_cast<volatile FTM_Type*>(ftm)->SC      = scValue|TPM_SC_CPWMS_MASK;
      }
      else {
         reinterpret_cast<volatile FTM_Type*>(ftm)->MOD     = period-1;
         // Left aligned PWM without CPWMS selected
         reinterpret_cast<volatile FTM_Type*>(ftm)->SC      = scValue;
      }
   }

   /**
    * Set PWM duty cycle
    *
    * @param dutyCycle Duty-cycle as percentage
    */
   void setDutyCycle(int dutyCycle) const {
      reinterpret_cast<volatile FTM_Type*>(ftm)->CONTROLS[ftmChannel].CnSC = ftm_pwmHighTruePulses;

      if (reinterpret_cast<volatile FTM_Type*>(ftm)->SC&FTM_SC_CPWMS_MASK) {
         reinterpret_cast<volatile FTM_Type*>(ftm)->CONTROLS[ftmChannel].CnV  = (dutyCycle*reinterpret_cast<volatile FTM_Type*>(ftm)->MOD)/100;
      }
      else {
         reinterpret_cast<volatile FTM_Type*>(ftm)->CONTROLS[ftmChannel].CnV  = (dutyCycle*(reinterpret_cast<volatile FTM_Type*>(ftm)->MOD+1))/100;
      }
   }
   /**
    * Set PWM period
    *
    * @param period Period in timer ticks
    */
   void setPeriod(int period) const {
      // Common registers
      reinterpret_cast<volatile FTM_Type   *>(ftm)->SC      = TPM_SC_PS(0); // Disable FTM so register changes are immediate
      if ((reinterpret_cast<volatile FTM_Type   *>(ftm)->SC&TPM_SC_CPWMS_MASK) != 0) {
         reinterpret_cast<volatile FTM_Type   *>(ftm)->MOD     = period/2;
         // Centre aligned PWM with CPWMS not selected
         reinterpret_cast<volatile FTM_Type   *>(ftm)->SC      = scValue|TPM_SC_CPWMS_MASK;
      }
      else {
         reinterpret_cast<volatile FTM_Type   *>(ftm)->MOD     = period-1;
         // Left aligned PWM without CPWMS selected
         reinterpret_cast<volatile FTM_Type   *>(ftm)->SC      = scValue;
      }
   }
};

/**
 * @}
 */

#endif /* HEADER_GPIO_DEFS_H */
