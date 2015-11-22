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
#include "pin_mapping.h"

#if DO_INLINE_GPIO != 0
#define OPTIONAL_INLINE __attribute__((always_inline))
#else
#define OPTIONAL_INLINE
#endif


/*!
 * @brief struct representing a PCR register
 *
 * <b>Example</b>
 * @code
 * // Set pin to boolean value
 * pcr.enableClock();
 * pcr.setPCR(GPIO_DEFAULT_PCR);
 *
 * @endcode
 */
struct PCRInit {
   volatile uint32_t   *pcrReg;     //!< Pointer to PCR for pin
   const    uint32_t    clockMask;  //!< Mask for clock bit in SIM_SCGC

   /**
    * Set pin PCR value
    *
    * @param pcrValue PCR value made up of PORT_PCR_ masks
    */
   void setPCR(uint32_t pcrValue) const  {
      if (pcrReg != 0) {
         enableClock();
         *pcrReg = pcrValue;
      }
   }
   /**
    * Enable clock to port
    */
   void enableClock() const {
      FIXED_PORT_CLOCK_REG |= clockMask;
   }
   /**
    * Enable clock to port
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
 * @brief struct representing a pin with Digital I/O capability
 *
 * <b>Example</b>
 * @code
 * // Set as digital output
 * DigitalIO_A3.setDigitalOutput();
 * // Set pin high
 * DigitalIO_A3.set();
 * // Set pin low
 * DigitalIO_A3.clear();
 * // Toggle pin
 * DigitalIO_A3.toggle();
 * // Set pin to boolean value
 * DigitalIO_A3.write(true);
 * // Set pin to boolean value
 * DigitalIO_A3.write(false);
 *
 * @endcode
 */
struct DigitalIO {
   const    PCRInit     pcr;        //!< PCR information
   volatile GPIO_Type  *gpio;       //!< Pointer to hardware registers
   const    uint32_t    bitMask;    //!< Bit-mask to use when manipulating individual bit

   /**
    * Default PCR setting for pins (excluding multiplexor value)
    * High drive strength + Pull-up
    */
   static const uint32_t    DEFAULT_PCR      = (PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
   /**
    * PCR multiplexor value for analogue function
    */
   static const uint32_t    GPIO_ANALOGUE_FN = PORT_PCR_MUX(FIXED_ADC_FN);
   /**
    * PCR multiplexor value for digital function
    */
   static const uint32_t    GPIO_PORT_FN     = PORT_PCR_MUX(FIXED_GPIO_FN);
   /**
    * Default PCR value for pins used as GPIO (including multiplexor value)
    */
   static const uint32_t    GPIO_DEFAULT_PCR = DEFAULT_PCR|GPIO_PORT_FN;

   /**
    * Toggle pin
    */
   void toggle() const OPTIONAL_INLINE {
      gpio->PTOR = bitMask;
   }
   /**
    * Set pin high
    */
   void set() const OPTIONAL_INLINE {
      gpio->PSOR = bitMask;
   }
   /**
    * Set pin low
    */
   void clear() const OPTIONAL_INLINE {
      gpio->PCOR = bitMask;
   }
   /**
    * Set pin as digital output
    *
    * @param pcrValue PCR value to use in configuring port
    */
   void setDigitalOutput(uint32_t pcrValue=GPIO_DEFAULT_PCR) const  {
      pcr.setPCR(pcrValue);
      gpio->PDDR |= bitMask;
   }
   /**
    * Set pin as digital input
    *
    * @param pcrValue PCR value to use in configuring port
    */
   void setDigitalInput(uint32_t pcrValue=GPIO_DEFAULT_PCR) const  {
      pcr.setPCR(pcrValue);
      gpio->PDDR &= ~bitMask;
   }
   /**
    * Write boolean value to digital output
    *
    * @param value high/low value
    */
   void write(bool value) const OPTIONAL_INLINE {
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
   bool read() const OPTIONAL_INLINE {
      return (gpio->PDIR & bitMask);
   }
};

/**
 * @}
 */

/**
 * @addtogroup AnalogueIO_Group Analogue Input
 * @{
 */

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
struct AnalogueIO {
   const    PCRInit     pcr;        //!< Associated PCR
   volatile ADC_Type   *adc;        //!< ADC Hardware pointer
   volatile uint32_t   *simscgc;    //!< Associated SIM_SCGC register
   const    uint32_t    clockMask;  //!< Mask for clock bit in SIM_SCGC
   const    uint8_t     adcChannel; //!< ADC channel
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
   /**
    * Set port pin as analogue input
    *
    * @param mode Mode for converter (currently only resolution)
    *
    * @note This initialises the ADC
    */
   void setAnalogueInput(uint32_t mode = resolution_16bit_se) const {
      pcr.setPCR(DigitalIO::GPIO_ANALOGUE_FN);
      initialiseADC(mode);
   }
   /**
    * Initiates a conversion and waits for it to complete
    *
    * @return - the result of the conversion
    */
   int readAnalogue() const {

      // Trigger conversion
      adc->SC1[0] = ADC_SC1_ADCH(adcChannel);

      while ((adc->SC1[0]&ADC_SC1_COCO_MASK) == 0) {
         __asm__("nop");
      }
      return (int)adc->R[0];
   };
private:
   /**
    * Initialise ADC before first use
    */
   void initialiseADC(uint32_t mode) const {
      // Enable clock to ADC
      *simscgc  |= clockMask;

      // Configure ADC for software triggered conversion
      adc->CFG1 = ADC_CFG1_ADIV(1)|mode|ADC_CFG1_ADLSMP_MASK|ADC_CFG1_ADICLK(0);
      adc->SC2  = 0;
      adc->CFG2 = ADC_CFG2_ADLSTS(0)|ADC_CFG2_MUXSEL_MASK; // Choose 'b' channels
   }
};

/**
 * @}
 */

/**
 * @addtogroup PwmIO_Group PWM, Input capture, Output compare
 * @{
 */

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
struct PwmIO {
   /**
    * Controls basic operation of PWM/Input capture
    */
   typedef enum  {
      //! Capture rising edge
      ftm_inputCaptureRisingEdge  = FTM_CnSC_ELSA_MASK,
      //! Capture falling edge
      ftm_inputCaptureFallingEdge = FTM_CnSC_ELSB_MASK,
      //! Capture both rising and falling edges
      ftm_inputCaptureEitherEdge  = FTM_CnSC_ELSB_MASK|FTM_CnSC_ELSA_MASK,
      //! Output compare operation
      ftm_outputCompare           = FTM_CnSC_MSA_MASK,
      //! Toggle pin on output compare
      ftm_outputCompareToggle     = FTM_CnSC_MSA_MASK|FTM_CnSC_ELSA_MASK,
      //! Clear pin on output compare
      ftm_outputCompareClear      = FTM_CnSC_MSA_MASK|FTM_CnSC_ELSB_MASK,
      //! Set pin on output compare
      ftm_outputCompareSet        = FTM_CnSC_MSA_MASK|FTM_CnSC_ELSB_MASK|FTM_CnSC_ELSA_MASK,
      //! PWM with high-true pulses
      ftm_pwmHighTruePulses       = FTM_CnSC_MSB_MASK|FTM_CnSC_ELSB_MASK,
      //! PWM with low-true pulses
      ftm_pwmLowTruePulses        = FTM_CnSC_MSB_MASK|FTM_CnSC_ELSA_MASK,
   } Ftm_Mode;

   /**
    * Control alignment of PWM function
    */
   typedef enum {
      //! Left-aligned
      ftm_leftAlign   = 0,
      //! Centre-aligned
      ftm_centreAlign = FTM_SC_CPWMS_MASK,
   } Pwm_Mode;

   const    PCRInit     pcr;        //!< Digital I/O
   volatile FTM_Type   *ftm;        //!< FTM hardware pointer
   const    uint8_t     ftmChannel; //!< FTM channel number
   const    uint32_t    portMux;    //!< Port multiplexor value for PWM operation
   volatile uint32_t   *simscgc;    //!< Associated SIM_SCGC register
   const    uint32_t    clockMask;  //!< Mask for clock bit in SIM_SCGC
   const    uint32_t    scValue;    //!< FTM->SC base value (clock selection & divider)

   /**
    * Configure PWM operation
    *
    * @param period  Period in timer ticks
    * @param mode    Mode of operation see @ref Pwm_Mode
    */
   void setPwmOutput(int period /* ticks */, Pwm_Mode mode) const {
      pcr.setPCR(portMux|DigitalIO::DEFAULT_PCR);

      // Enable clock to timer
      *simscgc  |= clockMask;

      // Common registers
      ftm->SC      = FTM_SC_CLKS(0); // Disable FTM so register changes are immediate
      ftm->CNTIN   = 0;
      ftm->CNT     = 0;
      if (mode == ftm_centreAlign) {
         ftm->MOD     = period/2;
         // Centre aligned PWM with CPWMS not selected
         ftm->SC      = scValue|FTM_SC_CPWMS_MASK;
      }
      else {
         ftm->MOD     = period-1;
         // Left aligned PWM without CPWMS selected
         ftm->SC      = scValue;
      }
   }
   /**
    * Set PWM duty cycle
    *
    * @param dutyCycle Duty-cycle as percentage
    */
   void setDutyCycle(int dutyCycle) const {
      ftm->CONTROLS[ftmChannel].CnSC = ftm_pwmHighTruePulses;

      if (ftm->SC&FTM_SC_CPWMS_MASK) {
         ftm->CONTROLS[ftmChannel].CnV  = (dutyCycle*ftm->MOD)/100;
      }
      else {
         ftm->CONTROLS[ftmChannel].CnV  = (dutyCycle*(ftm->MOD+1))/100;
      }
   }
   /**
    * Set PWM period
    *
    * @param period Period in timer ticks
    */
   void setPeriod(int period) const {
      // Common registers
      ftm->SC      = FTM_SC_CLKS(0); // Disable FTM so register changes are immediate
      if ((ftm->SC&FTM_SC_CPWMS_MASK) != 0) {
         ftm->MOD     = period/2;
         // Centre aligned PWM with CPWMS not selected
         ftm->SC      = scValue|FTM_SC_CPWMS_MASK;
      }
      else {
         ftm->MOD     = period-1;
         // Left aligned PWM without CPWMS selected
         ftm->SC      = scValue;
      }
   }
};

/**
 * @}
 */

#endif /* HEADER_GPIO_DEFS_H */
