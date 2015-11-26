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

/*
 * Default port information
 */
#ifndef FIXED_PORT_CLOCK_REG
#define FIXED_PORT_CLOCK_REG SCGC5
#endif

#ifndef PORTA_CLOCK_MASK
#ifdef SIM_SCGC5_PORTA_MASK
#define PORTA_CLOCK_MASK   SIM_SCGC5_PORTA_MASK
#endif
#ifdef SIM_SCGC5_PORTB_MASK
#define PORTB_CLOCK_MASK   SIM_SCGC5_PORTB_MASK
#endif
#ifdef SIM_SCGC5_PORTC_MASK
#define PORTC_CLOCK_MASK   SIM_SCGC5_PORTC_MASK
#endif
#ifdef SIM_SCGC5_PORTD_MASK
#define PORTD_CLOCK_MASK   SIM_SCGC5_PORTD_MASK
#endif
#ifdef SIM_SCGC5_PORTE_MASK
#define PORTE_CLOCK_MASK   SIM_SCGC5_PORTE_MASK
#endif
#ifdef SIM_SCGC5_PORTF_MASK
#define PORTF_CLOCK_MASK   SIM_SCGC5_PORTF_MASK
#endif
#endif

#ifndef FIXED_GPIO_FN
#define FIXED_GPIO_FN   (1)
#endif

#ifndef FIXED_ADC_FN
#define FIXED_ADC_FN    (0)
#endif

namespace USBDM {

/**
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
 * @tparam clockMask       Mask for SIM clock register associated with this PCR
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
    */
   void setPCR(uint32_t pcrValue=defaultPcrValue) const  {
      if (pcrReg != 0) {
         enableClock();
         *reinterpret_cast<volatile uint32_t *>(pcrReg) = pcrValue;
      }
   }
   /**
    * Enable clock to port
    */
   void enableClock() const {
      SIM->FIXED_PORT_CLOCK_REG |= clockMask;
   }
   /**
    * Disable clock to port
    */
   void disableClock() const {
      SIM->FIXED_PORT_CLOCK_REG &= ~clockMask;
   }
};

/**
 * @addtogroup DigitalIO_Group Digital Input/Output
 * @{
 */

/**
 * Non-Template class to hold constants
 */
class DigitalIO {
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
};
/**
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
 * @endcode
 *
 * @tparam clockMask     Mask for SIM clock register associated with this GPIO
 * @tparam port          PORT hardware associated with this GPIO (for PCR access)
 * @tparam gpio          GPIO hardware
 * @tparam bitNum        Bit number in the port
 */
template<uint32_t portClockMask, uint32_t port, uint32_t gpio, const uint32_t bitNum> class DigitalIOT : public DigitalIO {

private:
   PCRInit<portClockMask, port+offsetof(PORT_Type,PCR[bitNum]), GPIO_DEFAULT_PCR> pcr; //!< PCR information

public:
   DigitalIOT() {}

   /**
    * Toggle pin
    */
   void toggle() const {
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PTOR = (1<<bitNum);
   }
   /**
    * Set pin high
    */
   void set() const {
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PSOR = (1<<bitNum);
   }
   /**
    * Set pin low
    */
   void clear() const {
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PCOR = (1<<bitNum);
   }
   /**
    * Set pin as digital output
    *
    * @param pcrValue PCR value to use in configuring port
    */
   void setDigitalOutput(uint32_t pcrValue=GPIO_DEFAULT_PCR) const  {
      pcr.setPCR(pcrValue);
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PDDR |= (1<<bitNum);
   }
   /**
    * Set pin as digital input
    *
    * @param pcrValue PCR value to use in configuring port
    */
   void setDigitalInput(uint32_t pcrValue=GPIO_DEFAULT_PCR) const  {
      pcr.setPCR(pcrValue);
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PDDR &= ~(1<<bitNum);
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
      return ( reinterpret_cast<volatile GPIO_Type *>(gpio)->PDIR & (1<<bitNum));
   }
};
#ifdef PORTA_CLOCK_MASK
/**
 * @brief Convenience template for GPIOA bits. See @ref DigitalIO
 *
 * <b>Declaration example</b>
 * @code
 * // Instantiate for bit 4 of port
 * GpioE<4> pte12
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<int bitNum> using GpioA = DigitalIOT<PORTA_CLOCK_MASK, PORTA_BasePtr, GPIOA_BasePtr, bitNum>;
#endif
#ifdef PORTB_CLOCK_MASK
/**
 * @brief Convenience template for GPIOB bits. See @ref DigitalIOT
 *
 * <b>Declaration example</b>
 * @code
 * // Instantiate for bit 4 of port
 * GpioE<4> pte12
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<int bitNum> using GpioB = DigitalIOT<PORTB_CLOCK_MASK, PORTB_BasePtr, GPIOB_BasePtr, bitNum>;
#endif
#ifdef PORTC_CLOCK_MASK
/**
 * @brief Convenience template for GPIOC bits. See @ref DigitalIOT
 *
 * <b>Declaration example</b>
 * @code
 * // Instantiate for bit 4 of port
 * GpioE<4> pte12
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<int bitNum> using GpioC = DigitalIOT<PORTC_CLOCK_MASK, PORTC_BasePtr, GPIOC_BasePtr, bitNum>;
#endif
#ifdef PORTD_CLOCK_MASK
/**
 * @brief Convenience template for GPIOD bits. See @ref DigitalIOT
 *
 * <b>Declaration example</b>
 * @code
 * // Instantiate for bit 4 of port
 * GpioE<4> pte12
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<int bitNum> using GpioD = DigitalIOT<PORTD_CLOCK_MASK, PORTD_BasePtr, GPIOD_BasePtr, bitNum>;
#endif
#ifdef PORTE_CLOCK_MASK
/**
 * @brief Convenience template for GPIOE bits. See @ref DigitalIOT
 *
 * <b>Declaration example</b>
 * @code
 * // Instantiate for bit 4 of port
 * GpioE<4> pte12
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<int bitNum> using GpioE = DigitalIOT<PORTE_CLOCK_MASK, PORTE_BasePtr, GPIOE_BasePtr, bitNum>;
#endif
#ifdef PORTF_CLOCK_MASK
/**
 * @brief Convenience template for GPIOF bits. See @ref DigitalIOT
 *
 * <b>Declaration example</b>
 * @code
 * // Instantiate for bit 4 of port
 * GpioE<4> pte12
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<int bitNum> using GpioF = DigitalIOT<PORTF_CLOCK_MASK, PORTF_BasePtr, GPIOF_BasePtr, bitNum>;
#endif

/**
 * @brief Template representing a field with a port
 *
 * <b>Example</b>
 * @code
 * // Set as digital output
 * FieldIO.setDigitalOutput();
 *
 * // Write value to field
 * FieldIO.write(0x53);
 *
 * // Clear all of field
 * FieldIO.bitClear();
 *
 * // Clear lower two bits of field
 * FieldIO.bitClear(0x3);
 *
 * // Set lower two bits of field
 * FieldIO.bitSet(0x3);
 * @endcode
 *
 * @tparam clockMask      Mask for SIM clock register associated with this GPIO
 * @tparam port           PORT hardware associated with this GPIO (for PCR access)
 * @tparam gpio           GPIO hardware
 * @tparam left           Bit number of leftmost bit in port (inclusive)
 * @tparam right          Bit number of rightmost bit in port (inclusive)
 */
template<uint32_t portClockMask, uint32_t port, uint32_t gpio, const uint32_t left, const uint32_t right> class FieldIO {
private:
   /**
    * Utility function to set multiple PCRs using GPCLR & GPCHR
    */
   void setPCRs() const {
      // Include the if's as I expect one branch to be removed by optimisation unless the field spans the boundary
      if ((MASK&0xFFFFUL) != 0) {
         reinterpret_cast<volatile PORT_Type*>(port)->GPCLR = PORT_GPCLR_GPWE(MASK)|DEFAULT_PCR;
      }
      if ((MASK&~0xFFFFUL) != 0) {
         reinterpret_cast<volatile PORT_Type*>(port)->GPCHR = PORT_GPCHR_GPWE(MASK>>16)|DEFAULT_PCR;
      }
   }
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
   /**
    * Mask for the bits being manipulated
    */
   static const uint32_t    MASK = ((1<<(left-right+1))-1)<<right;

   FieldIO() {}

   /**
    * Set bits in field
    *
    * @param mask Mask to apply to the field (1 => set bit, 0 => unchanged)
    */
   void bitSet(const uint32_t mask) const {
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PSOR = (mask<<right)&MASK;
   }
   /**
    * Clear bits in field
    *
    * @param mask Mask to apply to the field (1 => clear bit, 0 => unchanged)
    */
   void bitClear(const uint32_t mask=((uint32_t)-1)) const {
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PCOR = (mask<<right)&MASK;
   }
   /**
    * Set pin as digital output
    *
    * @param pcrValue PCR value to use in configuring port
    */
   void setDigitalOutput(uint32_t pcrValue=GPIO_DEFAULT_PCR) const  {
      SIM->FIXED_PORT_CLOCK_REG |= portClockMask;
      setPCRs();
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PDDR |= MASK;
   }
   /**
    * Set pin as digital input
    *
    * @param pcrValue PCR value to use in configuring port
    */
   void setDigitalInput(uint32_t pcrValue=GPIO_DEFAULT_PCR) const  {
      SIM->FIXED_PORT_CLOCK_REG |= portClockMask;
      setPCRs();
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PDDR &= ~MASK;
   }
   /**
    * Read field
    *
    * @return value from field
    */
   uint32_t read() const {
      return ((reinterpret_cast<volatile GPIO_Type *>(gpio)->PDIR) & MASK)>>right;
   }
   /**
    * Write field
    *
    * @param value to insert as field
    */
   void write(uint32_t value) const {
      uint32_t preserved = (reinterpret_cast<volatile GPIO_Type *>(gpio)->PDIR) & ~MASK;
      (reinterpret_cast<volatile GPIO_Type *>(gpio)->PDOR) = preserved | ((value<<right)&MASK);
   }
};
#ifdef PORTA_CLOCK_MASK
/**
 * @brief Convenience template for GPIOA fields. See @ref FieldIO
 *
 * <b>Declaration example</b>
 * @code
 * // Instantiate for bit 12 down to 4 of port
 * GpioBField<12,4> ptb12_4
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioAField = FieldIO<PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr, left, right>;
#endif
#ifdef PORTB_CLOCK_MASK
/**
 * @brief Convenience template for GPIOB fields. See @ref FieldIO
 *
 * <b>Declaration example</b>
 * @code
 * // Instantiate for bit 12 down to 4 of port
 * GpioBField<12,4> ptb12_4
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioBField = FieldIO<PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr, left, right>;
#endif
#ifdef PORTC_CLOCK_MASK
/**
 * @brief Convenience template for GPIOC fields. See @ref FieldIO
 *
 * <b>Declaration example</b>
 * @code
 * // Instantiate for bit 12 down to 4 of port
 * GpioBField<12,4> ptb12_4
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioCField = FieldIO<PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr, left, right>;
#endif
#ifdef PORTD_CLOCK_MASK
/**
 * @brief Convenience template for GPIOD fields. See @ref FieldIO
 *
 * <b>Declaration example</b>
 * @code
 * // Instantiate for bit 12 down to 4 of port
 * GpioBField<12,4> ptb12_4
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioDField = FieldIO<PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr, left, right>;
#endif
#ifdef PORTE_CLOCK_MASK
/**
 * @brief Convenience template for GPIOE fields. See @ref FieldIO
 *
 * <b>Declaration example</b>
 * @code
 * // Instantiate for bit 12 down to 4 of port
 * GpioBField<12,4> ptb12_4
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioEField = FieldIO<PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr, left, right>;
#endif
#ifdef PORTF_CLOCK_MASK
/**
 * @brief Convenience template for GPIOF fields. See @ref FieldIO
 *
 * <b>Declaration example</b>
 * @code
 * // Instantiate for bit 12 down to 4 of port
 * GpioBField<12,4> ptb12_4
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioFField = FieldIO<PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr, left, right>;
#endif

/**
 * @}
 */

/**
 * @addtogroup AnalogueIO_Group Analogue Input
 * @{
 */

/**
 * Non-Template class to hold constants
 */
class AnalogueIO {
protected:
   AnalogueIO() {}

public:
   /**
    * PCR multiplexor value for analogue function
    */
   static const uint32_t    GPIO_ANALOGUE_FN = PORT_PCR_MUX(FIXED_ADC_FN);

   enum ADC_Resolution{
      resolution_8bit_se    = ADC_CFG1_MODE(0),
      resolution_10bit_se   = ADC_CFG1_MODE(2),
      resolution_12bit_se   = ADC_CFG1_MODE(1),
      resolution_16bit_se   = ADC_CFG1_MODE(3),
      resolution_9bit_diff  = ADC_CFG1_MODE(0),
      resolution_11bit_diff = ADC_CFG1_MODE(2),
      resolution_12bit_diff = ADC_CFG1_MODE(1),
      resolution_16bit_diff = ADC_CFG1_MODE(3),
   };
};

/**
 * Templated class representing a pin with Analogue Input capability
 *
 * Example
 * @code
 *  // Instantiate ADC (Assumes adc0_se8 is mapped to PORTB.0)
 *  const AnalogueIOT<PORTB_CLOCK_MASK,
 *                    PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),
 *                    ADC0_BasePtr,
 *                    SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),
 *                    ADC0_CLOCK_MASK, 8> adc0_se8;
 *
 *  // Initialise ADC
 *  adc0_se8.initialiseADC();
 *
 *  // Set as analogue input
 *  adc0_se8.setAnalogueInput();
 *
 *  // Read input
 *  uint16_t value = adc0_se8.readAnalogue();
 *  @endcode
 *
 * @tparam portClockMask Mask for clock register for PORT associated with this ADC
 * @tparam pcrReg        PCR for the PORT pin associated with this ADC
 * @tparam adc           ADC hardware
 * @tparam adcClockReg   SIM Clock register for ADC
 * @tparam adcClockMask  Mask for ADC clock register
 * @tparam adcChannel    ADC channel
 */
template<uint32_t portClockMask, uint32_t pcrReg, uint32_t adc, uint32_t adcClockReg, uint32_t adcClockMask, uint8_t adcChannel> class AnalogueIOT : public AnalogueIO {
public:
   PCRInit<portClockMask, pcrReg, GPIO_ANALOGUE_FN> pcr; //!< PCR information

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
      pcr.setPCR(GPIO_ANALOGUE_FN);

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

#ifdef ADC0_CLOCK_MASK
/**
 * Convenience templated class representing a pin with Analogue Input capability
 *
 * Example
 * @code
 *  // Instantiate ADC (Assumes adc0_se8 is mapped to PORTB.0)
 *  const adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]), 8> adc0_se8;
 *
 *  // Initialise ADC
 *  adc0_se8.initialiseADC();
 *
 *  // Set as analogue input
 *  adc0_se8.setAnalogueInput();
 *
 *  // Read input
 *  uint16_t value = adc0_se8.readAnalogue();
 *  @endcode
 *
 * @tparam portClockMask Mask for clock register for PORT associated with this ADC
 * @tparam pcrReg        PCR for the PORT pin associated with this ADC
 * @tparam adcChannel    ADC channel
 */
template<uint32_t portClockMask, uint32_t pcrReg, uint8_t adcChannel> using Adc0 =
      AnalogueIOT<portClockMask, pcrReg, ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG), ADC0_CLOCK_MASK, adcChannel>;
#endif
#ifdef ADC1_CLOCK_MASK
/**
 * Convenience templated class representing a pin with Analogue Input capability
 *
 * Example
 * @code
 *  // Instantiate ADC (Assumes adc0_se8 is mapped to PORTB.0)
 *  const adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]), 8> adc0_se8;
 *
 *  // Initialise ADC
 *  adc0_se8.initialiseADC();
 *
 *  // Set as analogue input
 *  adc0_se8.setAnalogueInput();
 *
 *  // Read input
 *  uint16_t value = adc0_se8.readAnalogue();
 *  @endcode
 *
 * @tparam portClockMask Mask for clock register for pin associated with this ADC
 * @tparam pcrReg        PCR for the pin associated with this ADC
 * @tparam adcChannel    ADC channel
 */
template<uint32_t portClockMask, uint32_t pcrReg, uint8_t adcChannel> using Adc1 =
      AnalogueIOT<portClockMask, pcrReg, ADC1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC1_CLOCK_REG), ADC1_CLOCK_MASK, adcChannel>;
#endif
#ifdef ADC2_CLOCK_MASK
/**
 * Convenience templated class representing a pin with Analogue Input capability
 *
 * Example
 * @code
 *  // Instantiate ADC (Assumes adc0_se8 is mapped to PORTB.0)
 *  const adc0<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]), 8> adc0_se8;
 *
 *  // Initialise ADC
 *  adc0_se8.initialiseADC();
 *
 *  // Set as analogue input
 *  adc0_se8.setAnalogueInput();
 *
 *  // Read input
 *  uint16_t value = adc0_se8.readAnalogue();
 *  @endcode
 *
 * @tparam portClockMask Mask for clock register for pin associated with this ADC
 * @tparam pcrReg        PCR for the pin associated with this ADC
 * @tparam adcChannel    ADC channel
 */
template<uint32_t portClockMask, uint32_t pcrReg, uint8_t adcChannel> using Adc2 =
      AnalogueIOT<portClockMask, pcrReg, ADC2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC2_CLOCK_REG), ADC2_CLOCK_MASK, adcChannel>;
#endif

/**
 * @}
 */

/**
 * @addtogroup PwmIO_Group PWM, Input capture, Output compare
 * @{
 */
/**
 * Non-Template base class for PWM to hold constants
 */
class PwmIO {
protected:
   PwmIO() {}

public:
   /**
    * Controls basic operation of PWM/Input capture
    */
   enum Ftm_Mode {
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
   } ;
   /**
    * Control alignment of PWM function
    */
   enum Pwm_Mode {
      //! Left-aligned
      ftm_leftAlign   = 0,
      //! Centre-aligned
      ftm_centreAlign = FTM_SC_CPWMS_MASK,
   } ;
   /**
    * Default PCR setting for pins (excluding multiplexor value)
    * High drive strength + Pull-up
    */
   static const uint32_t DEFAULT_PCR = (PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
};

/**
 * Templated class representing a pin with PWM capability
 *
 * Example
 * @code
 * // Instantiate the ftm channel (for FTM0 CH6)
 * const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  6>   ftm0_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * ftm0_ch6.setPwmOutput(200, PwmIO::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * ftm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * ftm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam portClockMask Mask for clock register for PORT associated with this FTM
 * @tparam pcrReg        PCR for the PORT pin associated with this FTM
 * @tparam ftmMuxFn      PCR multiplexer selection to map pin to FTM
 * @tparam ftm           ADC hardware
 * @tparam ftmClockReg   SIM Clock register for ADC
 * @tparam ftmClockMask  Mask for ADC clock register
 * @tparam ftmChannel    ADC channel
 */
template<uint32_t portClockMask, uint32_t pcrReg, uint32_t ftmMuxFn, uint32_t ftm, uint32_t ftmClockReg, uint32_t ftmClockMask, uint32_t ftmChannel> class PwmIOT : public PwmIO {
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
      *reinterpret_cast<volatile uint32_t*>(ftmClockReg) |= ftmClockMask;

      // Common registers
      reinterpret_cast<volatile FTM_Type*>(ftm)->SC      = FTM_SC_CLKS(0); // Disable FTM so register changes are immediate
      reinterpret_cast<volatile FTM_Type*>(ftm)->CNTIN   = 0;
      reinterpret_cast<volatile FTM_Type*>(ftm)->CNT     = 0;
      if (mode == ftm_centreAlign) {
         reinterpret_cast<volatile FTM_Type*>(ftm)->MOD  = period/2;
         // Centre aligned PWM with CPWMS not selected
         reinterpret_cast<volatile FTM_Type*>(ftm)->SC   = scValue|FTM_SC_CPWMS_MASK;
      }
      else {
         reinterpret_cast<volatile FTM_Type*>(ftm)->MOD  = period-1;
         // Left aligned PWM without CPWMS selected
         reinterpret_cast<volatile FTM_Type*>(ftm)->SC   = scValue;
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
      reinterpret_cast<volatile FTM_Type*>(ftm)->SC = FTM_SC_CLKS(0); // Disable FTM so register changes are immediate

      if ((reinterpret_cast<volatile FTM_Type*>(ftm)->SC&FTM_SC_CPWMS_MASK) != 0) {
         reinterpret_cast<volatile FTM_Type*>(ftm)->MOD = period/2;
         // Centre aligned PWM with CPWMS not selected
         reinterpret_cast<volatile FTM_Type*>(ftm)->SC  = scValue|FTM_SC_CPWMS_MASK;
      }
      else {
         reinterpret_cast<volatile FTM_Type*>(ftm)->MOD = period-1;
         // Left aligned PWM without CPWMS selected
         reinterpret_cast<volatile FTM_Type*>(ftm)->SC  = scValue;
      }
   }
};

/**
 * Convenience templated class representing a pin with PWM capability
 *
 * Example
 * @code
 * // Instantiate the ftm channel (for FTM0 CH6)
 * const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  6>   ftm0_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * ftm0_ch6.setPwmOutput(200, PwmIO::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * ftm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * ftm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam portClockMask Mask for clock register for PORT associated with this FTM
 * @tparam pcrReg        PCR for the PORT pin associated with this FTM
 * @tparam ftmMuxFn      PCR multiplexer selection to map pin to FTM
 * @tparam ftmChannel    ADC channel
 */
template<uint32_t portClockMask, uint32_t pcrReg, uint32_t ftmMuxFn, uint32_t ftmChannel> using Ftm0 =
      PwmIOT<portClockMask, pcrReg, ftmMuxFn, FTM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM0_CLOCK_REG), FTM0_CLOCK_MASK, ftmChannel>;

/**
 * Convenience templated class representing a pin with PWM capability
 *
 * Example
 * @code
 * // Instantiate the ftm channel (for FTM0 CH6)
 * const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  6>   ftm0_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * ftm0_ch6.setPwmOutput(200, PwmIO::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * ftm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * ftm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam portClockMask Mask for clock register for PORT associated with this FTM
 * @tparam pcrReg        PCR for the PORT pin associated with this FTM
 * @tparam ftmMuxFn      PCR multiplexer selection to map pin to FTM
 * @tparam ftmChannel    ADC channel
 */
template<uint32_t portClockMask, uint32_t pcrReg, uint32_t ftmMuxFn, uint32_t ftmChannel> using Ftm1 =
      PwmIOT<portClockMask, pcrReg, ftmMuxFn, FTM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, FTM1_CLOCK_REG), FTM1_CLOCK_MASK, ftmChannel>;

/**
 * @}
 */

} // End namespace USBDM

#endif /* HEADER_GPIO_DEFS_H */
