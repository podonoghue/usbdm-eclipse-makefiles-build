/**
 * @file     gpio_defs.h (from gpio_defs-MK.h)
 * @brief    GPIO Pin routines
 *
 * @version  V4.11.1.70
 * @date     18 June 2015
 */
#ifndef HEADER_GPIO_DEFS_H
#define HEADER_GPIO_DEFS_H

#include <stddef.h>
#include "derivative.h"
#include "bme.h"
#include "pin_mapping.h"

/*
 * Default port information
 */
#ifndef FIXED_PORT_CLOCK_REG
#define FIXED_PORT_CLOCK_REG SCGC5
#endif

#ifndef FIXED_GPIO_FN
#define FIXED_GPIO_FN   (1)
#endif

#ifndef FIXED_ADC_FN
#define FIXED_ADC_FN    (0)
#endif

#ifndef PORTA_CLOCK_MASK
#ifdef SIM_SCGC5_PORTA_MASK
#define PORTA_CLOCK_MASK  SIM_SCGC5_PORTA_MASK
#define PORTA_CLOCK_REG   SCGC5
#endif
#ifdef SIM_SCGC5_PORTB_MASK
#define PORTB_CLOCK_MASK  SIM_SCGC5_PORTB_MASK
#define PORTB_CLOCK_REG   SCGC5
#endif
#ifdef SIM_SCGC5_PORTC_MASK
#define PORTC_CLOCK_MASK  SIM_SCGC5_PORTC_MASK
#define PORTC_CLOCK_REG   SCGC5
#endif
#ifdef SIM_SCGC5_PORTD_MASK
#define PORTD_CLOCK_MASK  SIM_SCGC5_PORTD_MASK
#define PORTD_CLOCK_REG   SCGC5
#endif
#ifdef SIM_SCGC5_PORTE_MASK
#define PORTE_CLOCK_MASK  SIM_SCGC5_PORTE_MASK
#define PORTE_CLOCK_REG   SCGC5
#endif
#ifdef SIM_SCGC5_PORTF_MASK
#define PORTF_CLOCK_MASK  SIM_SCGC5_PORTF_MASK
#define PORTF_CLOCK_REG   SCGC5
#endif
#endif

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

#ifndef ADC0_CLOCK_MASK
#ifdef SIM_SCGC6_ADC0_MASK
#define ADC0_CLOCK_MASK SIM_SCGC6_ADC0_MASK
#define ADC0_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC3_ADC1_MASK
#define ADC1_CLOCK_MASK SIM_SCGC3_ADC1_MASK
#define ADC1_CLOCK_REG  SCGC3
#endif
#ifdef SIM_SCGC6_ADC1_MASK
#define ADC1_CLOCK_MASK SIM_SCGC6_ADC1_MASK
#define ADC1_CLOCK_REG  SCGC6
#endif
#ifdef SIM_SCGC6_ADC2_MASK
#define ADC2_CLOCK_MASK SIM_SCGC6_ADC2_MASK
#define ADC2_CLOCK_REG  SCGC6
#endif
#endif

namespace USBDM {

/**
 * @brief Template representing a PCR register
 *
 * @details
 * @code
 * // Configure PCR
 * pcr.setPCR(PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_MUX(3));
 *
 * // Disable clock to associated PORT
 * pcr.disableClock();
 * @endcode
 *
 * @tparam clockMask       Mask for SIM clock register associated with this PCR
 * @tparam pcrReg          PCR to be manipulated
 * @tparam defPcrValue     Default value for PCR
 */
template<uint32_t clockMask, uint32_t pcrReg, uint32_t defPcrValue> class Pcr_T {

public:
   /**
    * Set pin PCR value\n
    * The clock to the port will be enabled before changing the PCR
    *
    * @param pcrValue PCR value made up of PORT_PCR_ masks
    */
   static void setPCR(uint32_t pcrValue=defPcrValue) {
      if (pcrReg != 0) {
         enableClock();
         *reinterpret_cast<volatile uint32_t *>(pcrReg) = pcrValue;
      }
   }
   /**
    * Enable clock to port
    */
   static void enableClock() {
      bmeOr(SIM->FIXED_PORT_CLOCK_REG, clockMask);
//      SIM->FIXED_PORT_CLOCK_REG |= clockMask;
   }
   /**
    * Disable clock to port
    */
   static void disableClock() {
      bmeAnd(SIM->FIXED_PORT_CLOCK_REG, ~clockMask);
//      SIM->FIXED_PORT_CLOCK_REG &= ~clockMask;
   }
};

/**
 * @addtogroup DigitalIO_Group Digital Input/Output
 * @{
 */

/**
 * Default PCR setting for pins (excluding multiplexor value)
 * High drive strength + Pull-up
 */
static constexpr uint32_t    DEFAULT_PCR      = (PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
/**
 * PCR multiplexor value for digital function
 */
static constexpr uint32_t    GPIO_PORT_FN     = PORT_PCR_MUX(FIXED_GPIO_FN);
/**
 * Default PCR value for pins used as GPIO (including multiplexor value)
 */
static constexpr uint32_t    GPIO_DEFAULT_PCR = DEFAULT_PCR|GPIO_PORT_FN;

#ifndef PORT_PCR_ODE_MASK
// Some devices don't have ODE function on pin
// The open-drain mode is automatically selected when I2C function is selected for the pin
#define PORT_PCR_ODE_MASK 0
#endif
/**
 * Default PCR setting for I2C pins (excluding multiplexor value)
 * High drive strength + Pull-up + Opendrain (if available)
 */
static constexpr uint32_t  I2C_DEFAULT_PCR = DEFAULT_PCR|PORT_PCR_ODE_MASK;

/**
 * @brief Template representing a pin with Digital I/O capability
 *
 * <b>Example</b>
 * @code
 * // Instantiate
 * USBDM::Gpio_T<SIM_SCGC5_PORTA_SHIFT, PORTA_BasePtr, GPIOA_BasePtr, 3> pta3;
 *
 * // Set as digital output
 * pta3.setOutput();
 *
 * // Set pin high
 * pta3.set();
 *
 * // Set pin low
 * pta3.clear();
 *
 * // Toggle pin
 * pta3.toggle();
 *
 * // Set pin to boolean value
 * pta3.write(true);
 *
 * // Set pin to boolean value
 * pta3.write(false);
 *
 * // Set as digital input
 * pta3.setInput();
 *
 * // Read pin as boolean value
 * bool x = pta3.read();
 *
 * @endcode
 *
 * @tparam portClockMask   Mask for SIM clock register associated with this GPIO
 * @tparam port            PORT hardware associated with this GPIO (for PCR access)
 * @tparam defPcrValue     Default value for PCR including mux value
 * @tparam gpio            GPIO hardware
 * @tparam bitNum          Bit number in the port
 */
template<uint32_t portClockMask, uint32_t pcrReg, uint32_t defPcrValue, uint32_t gpio, const uint32_t bitNum> class Gpio_T {

public:
   using Pcr = Pcr_T<portClockMask, pcrReg, defPcrValue>; //!< PCR information

public:
   /**
    * Set pin as digital output
    *
    * @param pcrValue PCR value to use in configuring port (excluding mux fn)
    */
   static void setOutput(uint32_t pcrValue=defPcrValue) {
      Pcr::setPCR((pcrValue&~PORT_PCR_MUX_MASK)|(defPcrValue&PORT_PCR_MUX_MASK));
      bmeOr(reinterpret_cast<volatile GPIO_Type *>(gpio)->PDDR, 1<<bitNum);
//      reinterpret_cast<volatile GPIO_Type *>(gpio)->PDDR |= (1<<bitNum);
   }
   /**
    * Set pin as digital input
    *
    * @param pcrValue PCR value to use in configuring port (excluding mux fn)
    */
   static void setInput(uint32_t pcrValue=defPcrValue) {
      Pcr::setPCR((pcrValue&~PORT_PCR_MUX_MASK)|(defPcrValue&PORT_PCR_MUX_MASK));
      bmeAnd(reinterpret_cast<volatile GPIO_Type *>(gpio)->PDDR, ~(1<<bitNum));
//      reinterpret_cast<volatile GPIO_Type *>(gpio)->PDDR &= ~(1<<bitNum);
   }
   /**
    * Toggle pin
    */
   static void toggle() {
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PTOR = (1<<bitNum);
   }
   /**
    * Set pin high
    */
   static void set() {
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PSOR = (1<<bitNum);
   }
   /**
    * Set pin low
    */
   static void clear() {
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PCOR = (1<<bitNum);
   }
   /**
    * Write boolean value to digital output
    *
    * @param value true/false value
    */
   static void write(bool value) {
      bmeInsert(reinterpret_cast<volatile GPIO_Type *>(gpio)->PDOR, bitNum, 1, (value!=0));
   }
   /**
    * Read digital input as boolean
    *
    * @return true/false reflecting pin value
    */
   static bool read() {
      return bmeExtract(reinterpret_cast<volatile GPIO_Type *>(gpio)->PDIR, bitNum, 1);
   }
};
#ifdef PORTA_CLOCK_MASK
/**
 * @brief Convenience template for GPIOA bits. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 3 of port
 * GpioA<3> pta3
 *
 * // Set as digital output
 * pta3.setOutput();
 *
 * // Set pin high
 * pta3.set();
 *
 * // Set pin low
 * pta3.clear();
 *
 * // Toggle pin
 * pta3.toggle();
 *
 * // Set pin to boolean value
 * pta3.write(true);
 *
 * // Set pin to boolean value
 * pta3.write(false);
 *
 * // Set as digital input
 * pta3.setInput();
 *
 * // Read pin as boolean value
 * bool x = pta3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<int bitNum> using GpioA = Gpio_T<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[bitNum]), GPIO_DEFAULT_PCR, GPIOA_BasePtr, bitNum>;
#endif
#ifdef PORTB_CLOCK_MASK
/**
 * @brief Convenience template for GPIOB bits. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 3 of port
 * GpioB<3> ptb3
 *
 * // Set as digital output
 * ptb3.setOutput();
 *
 * // Set pin high
 * ptb3.set();
 *
 * // Set pin low
 * ptb3.clear();
 *
 * // Toggle pin
 * ptb3.toggle();
 *
 * // Set pin to boolean value
 * ptb3.write(true);
 *
 * // Set pin to boolean value
 * ptb3.write(false);
 *
 * // Set as digital input
 * ptb3.setInput();
 *
 * // Read pin as boolean value
 * bool x = ptb3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<int bitNum> using GpioB = Gpio_T<PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[bitNum]), GPIO_DEFAULT_PCR, GPIOB_BasePtr, bitNum>;
#endif
#ifdef PORTC_CLOCK_MASK
/**
 * @brief Convenience template for GPIOC bits. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 4 of port
 * GpioC<3> ptc3
 *
 * // Set as digital output
 * ptc3.setOutput();
 *
 * // Set pin high
 * ptc3.set();
 *
 * // Set pin low
 * ptc3.clear();
 *
 * // Toggle pin
 * ptc3.toggle();
 *
 * // Set pin to boolean value
 * ptc3.write(true);
 *
 * // Set pin to boolean value
 * ptc3.write(false);
 *
 * // Set as digital input
 * ptc3.setInput();
 *
 * // Read pin as boolean value
 * bool x = ptc3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<int bitNum> using GpioC = Gpio_T<PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[bitNum]), GPIO_DEFAULT_PCR, GPIOC_BasePtr, bitNum>;
#endif
#ifdef PORTD_CLOCK_MASK
/**
 * @brief Convenience template for GPIOD bits. See @ref Gpio_T
 *
 * @code
 * <b>Usage</b>
 * // Instantiate for bit 4 of port
 * GpioD<3> ptd3
 *
 * // Set as digital output
 * ptd3.setOutput();
 *
 * // Set pin high
 * ptd3.set();
 *
 * // Set pin low
 * ptd3.clear();
 *
 * // Toggle pin
 * ptd3.toggle();
 *
 * // Set pin to boolean value
 * ptd3.write(true);
 *
 * // Set pin to boolean value
 * ptd3.write(false);
 *
 * // Set as digital input
 * ptd3.setInput();
 *
 * // Read pin as boolean value
 * bool x = ptd3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<int bitNum> using GpioD = Gpio_T<PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[bitNum]), GPIO_DEFAULT_PCR, GPIOD_BasePtr, bitNum>;
#endif
#ifdef PORTE_CLOCK_MASK
/**
 * @brief Convenience template for GPIOE bits. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 4 of port
 * GpioE<3> pte3
 *
 * // Set as digital output
 * pte3.setOutput();
 *
 * // Set pin high
 * pte3.set();
 *
 * // Set pin low
 * pte3.clear();
 *
 * // Toggle pin
 * pte3.toggle();
 *
 * // Set pin to boolean value
 * pte3.write(true);
 *
 * // Set pin to boolean value
 * pte3.write(false);
 *
 * // Set as digital input
 * pte3.setInput();
 *
 * // Read pin as boolean value
 * bool x = pte3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<int bitNum> using GpioE = Gpio_T<PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[bitNum]), GPIO_DEFAULT_PCR, GPIOE_BasePtr, bitNum>;
#endif
#ifdef PORTF_CLOCK_MASK
/**
 * @brief Convenience template for GPIOF bits. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 4 of port
 * GpioF<3> ptf3
 *
 * // Set as digital output
 * ptf3.setOutput();
 *
 * // Set pin high
 * ptf3.set();
 *
 * // Set pin low
 * ptf3.clear();
 *
 * // Toggle pin
 * ptf3.toggle();
 *
 * // Set pin to boolean value
 * ptf3.write(true);
 *
 * // Set pin to boolean value
 * ptf3.write(false);
 *
 * // Set as digital input
 * ptf3.setInput();
 *
 * // Read pin as boolean value
 * bool x = ptf3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<int bitNum> using GpioF = Gpio_T<PORTF_CLOCK_MASK, PORTF_BasePtr+offsetof(PORT_Type,PCR[bitNum]), GPIO_DEFAULT_PCR, GPIOF_BasePtr, bitNum>;
#endif
/**
 * @brief Template representing a field with a port
 *
 * <b>Example</b>
 * @code
 * // Instantiate object representing Port A 6 down to 3
 * Field_T<PORTA_CLOCK_MASK, PORTA_BasePtr, GPIOA_BasePtr, 6, 3> pta6_3;
 *
 * // Set as digital output
 * pta6_3.setOutput();
 *
 * // Write value to field
 * pta6_3.write(0x53);
 *
 * // Clear all of field
 * pta6_3.bitClear();
 *
 * // Clear lower two bits of field
 * pta6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * pta6_3.bitSet(0x3);
 *
 * // Set as digital input
 * pta6_3.setInput();
 *
 * // Read pin as int value
 * int x = pta6_3.read();
 * @endcode
 *
 * @tparam clockMask      Mask for SIM clock register associated with this GPIO
 * @tparam port           PORT hardware associated with this GPIO (for PCR access)
 * @tparam defPcrValue    Default value for PCR including mux value
 * @tparam gpio           GPIO hardware
 * @tparam left           Bit number of leftmost bit in port (inclusive)
 * @tparam right          Bit number of rightmost bit in port (inclusive)
 */
template<uint32_t portClockMask, uint32_t port, uint32_t defPcrValue, uint32_t gpio, const uint32_t left, const uint32_t right> class Field_T {
private:
   /**
    * Mask for the bits being manipulated
    */
   static constexpr uint32_t    MASK = ((1<<(left-right+1))-1)<<right;
   /**
    * Utility function to set multiple PCRs using GPCLR & GPCHR
    *
    * @param pcrValue PCR value to use in configuring port (excluding mux fn)
    */
   static void setPCRs(uint32_t pcrValue) {
      // Enable clock to GPCLR & GPCHR
//      SIM->FIXED_PORT_CLOCK_REG |= portClockMask;
      bmeOr(SIM->FIXED_PORT_CLOCK_REG, portClockMask);

      // Include the if's as I expect one branch to be removed by optimisation unless the field spans the boundary
      if ((MASK&0xFFFFUL) != 0) {
         reinterpret_cast<volatile PORT_Type*>(port)->GPCLR = PORT_GPCLR_GPWE(MASK)|(pcrValue&~PORT_PCR_MUX_MASK)|(defPcrValue&PORT_PCR_MUX_MASK);
      }
      if ((MASK&~0xFFFFUL) != 0) {
         reinterpret_cast<volatile PORT_Type*>(port)->GPCHR = PORT_GPCHR_GPWE(MASK>>16)|(pcrValue&~PORT_PCR_MUX_MASK)|(defPcrValue&PORT_PCR_MUX_MASK);
      }
   }
public:
   /**
    * Set pin as digital output
    *
    * @param pcrValue PCR value to use in configuring port (excluding mux fn)
    */
   static void setOutput(uint32_t pcrValue=defPcrValue) {
      setPCRs(pcrValue);
      bmeOr(reinterpret_cast<volatile GPIO_Type *>(gpio)->PDDR, MASK);
//      reinterpret_cast<volatile GPIO_Type *>(gpio)->PDDR |= MASK;
   }
   /**
    * Set pin as digital input
    *
    * @param pcrValue PCR value to use in configuring port (excluding mux fn)
    */
   static void setInput(uint32_t pcrValue=defPcrValue) {
      setPCRs(pcrValue);
      bmeAnd(reinterpret_cast<volatile GPIO_Type *>(gpio)->PDDR, ~MASK);
//      reinterpret_cast<volatile GPIO_Type *>(gpio)->PDDR &= ~MASK;
   }
   /**
    * Set bits in field
    *
    * @param mask Mask to apply to the field (1 => set bit, 0 => unchanged)
    */
   static void bitSet(const uint32_t mask) {
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PSOR = (mask<<right)&MASK;
   }
   /**
    * Clear bits in field
    *
    * @param mask Mask to apply to the field (1 => clear bit, 0 => unchanged)
    */
   static void bitClear(const uint32_t mask) {
      reinterpret_cast<volatile GPIO_Type *>(gpio)->PCOR = (mask<<right)&MASK;
   }
   /**
    * Read field
    *
    * @return value from field
    */
   static uint32_t read() {
      return bmeExtract(reinterpret_cast<volatile GPIO_Type *>(gpio)->PDIR, right, left-right+1);
//      return ((reinterpret_cast<volatile GPIO_Type *>(gpio)->PDIR) & MASK)>>right;
   }
   /**
    * Write field
    *
    * @param value to insert as field
    */
   static void write(uint32_t value) {
      bmeInsert(reinterpret_cast<volatile GPIO_Type *>(gpio)->PDOR, right, left-right+1, value);
//      uint32_t preserved = (reinterpret_cast<volatile GPIO_Type *>(gpio)->PDIR) & ~MASK;
//      (reinterpret_cast<volatile GPIO_Type *>(gpio)->PDOR) = preserved | ((value<<right)&MASK);
   }
};
#ifdef PORTA_CLOCK_MASK
/**
 * @brief Convenience template for GPIOA fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of port
 * GpioAField<6,3> ptb12_4
 *
 * // Set as digital output
 * pta6_3.setOutput();
 *
 * // Write value to field
 * pta6_3.write(0x53);
 *
 * // Clear all of field
 * pta6_3.bitClear();
 *
 * // Clear lower two bits of field
 * pta6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * pta6_3.bitSet(0x3);
 *
 * // Set as digital input
 * pta6_3.setInput();
 *
 * // Read pin as int value
 * int x = pta6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioAField = Field_T<PORTA_CLOCK_MASK, PORTA_BasePtr, GPIO_DEFAULT_PCR, GPIOA_BasePtr, left, right>;
#endif
#ifdef PORTB_CLOCK_MASK
/**
 * @brief Convenience template for GPIOB fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of port
 * GpioBField<6,3> ptb12_4
 *
 * // Set as digital output
 * ptb6_3.setOutput();
 *
 * // Write value to field
 * ptb6_3.write(0x53);
 *
 * // Clear all of field
 * ptb6_3.bitClear();
 *
 * // Clear lower two bits of field
 * ptb6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * ptb6_3.bitSet(0x3);
 *
 * // Set as digital input
 * ptb6_3.setInput();
 *
 * // Read pin as int value
 * int x = ptb6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioBField = Field_T<PORTB_CLOCK_MASK, PORTB_BasePtr, GPIO_DEFAULT_PCR, GPIOB_BasePtr, left, right>;
#endif
#ifdef PORTC_CLOCK_MASK
/**
 * @brief Convenience template for GPIOC fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of port
 * GpioCField<6,3> ptc12_4
 *
 * // Set as digital output
 * ptc6_3.setOutput();
 *
 * // Write value to field
 * ptc6_3.write(0x53);
 *
 * // Clear all of field
 * ptc6_3.bitClear();
 *
 * // Clear lower two bits of field
 * ptc6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * ptc6_3.bitSet(0x3);
 *
 * // Set as digital input
 * ptc6_3.setInput();
 *
 * // Read pin as int value
 * int x = ptc6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioCField = Field_T<PORTC_CLOCK_MASK, PORTC_BasePtr, GPIO_DEFAULT_PCR, GPIOC_BasePtr, left, right>;
#endif
#ifdef PORTD_CLOCK_MASK
/**
 * @brief Convenience template for GPIOD fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of port
 * GpioDField<6,3> ptd12_4
 *
 * // Set as digital output
 * ptd6_3.setOutput();
 *
 * // Write value to field
 * ptd6_3.write(0x53);
 *
 * // Clear all of field
 * ptd6_3.bitClear();
 *
 * // Clear lower two bits of field
 * ptd6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * ptd6_3.bitSet(0x3);
 *
 * // Set as digital input
 * ptd6_3.setInput();
 *
 * // Read pin as int value
 * int x = ptd6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioDField = Field_T<PORTD_CLOCK_MASK, PORTD_BasePtr, GPIO_DEFAULT_PCR, GPIOD_BasePtr, left, right>;
#endif
#ifdef PORTE_CLOCK_MASK
/**
 * @brief Convenience template for GPIOE fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of port
 * GpioEField<6,3> pte12_4
 *
 * // Set as digital output
 * pte6_3.setOutput();
 *
 * // Write value to field
 * pte6_3.write(0x53);
 *
 * // Clear all of field
 * pte6_3.bitClear();
 *
 * // Clear lower two bits of field
 * pte6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * pte6_3.bitSet(0x3);
 *
 * // Set as digital input
 * pte6_3.setInput();
 *
 * // Read pin as int value
 * int x = pte6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioEField = Field_T<PORTE_CLOCK_MASK, PORTE_BasePtr, GPIO_DEFAULT_PCR, GPIOE_BasePtr, left, right>;
#endif
#ifdef PORTF_CLOCK_MASK
/**
 * @brief Convenience template for GPIOF fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of port
 * GpioFField<6,3> ptf6_3
 *
 * // Set as digital output
 * ptf6_3.setOutput();
 *
 * // Write value to field
 * ptf6_3.write(0x53);
 *
 * // Clear all of field
 * ptf6_3.bitClear();
 *
 * // Clear lower two bits of field
 * ptf6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * ptf6_3.bitSet(0x3);
 *
 * // Set as digital input
 * ptf6_3.setInput();
 *
 * // Read pin as int value
 * int x = ptf6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioFField = Field_T<PORTF_CLOCK_MASK, PORTF_BasePtr, PORTF_GPIO_FN,  GPIOF_BasePtr, left, right>;
#endif

/**
 * @}
 */

/**
 * @addtogroup AnalogueIO_Group Analogue Input
 * @{
 */

/**
 * PCR multiplexor value for analogue function
 */
static constexpr uint32_t    ADC_PORT_FN = PORT_PCR_MUX(FIXED_ADC_FN);
/**
 * Default PCR value for pins used as GPIO (including multiplexor value)
 */
static constexpr uint32_t    ADC_DEFAULT_PCR = ADC_PORT_FN;

/**
 * ADC Resolutions for use with AnalogueIO::setMode()
 */
enum Adc_Resolution {
   resolution_8bit_se    = ADC_CFG1_MODE(0),
   resolution_10bit_se   = ADC_CFG1_MODE(2),
   resolution_12bit_se   = ADC_CFG1_MODE(1),
   resolution_16bit_se   = ADC_CFG1_MODE(3),
   resolution_9bit_diff  = ADC_CFG1_MODE(0),
   resolution_11bit_diff = ADC_CFG1_MODE(2),
   resolution_12bit_diff = ADC_CFG1_MODE(1),
   resolution_16bit_diff = ADC_CFG1_MODE(3),
};

/**
 * Templated class representing a pin with Analogue Input capability
 *
 * Example
 * @code
 *  // Instantiate ADC (Assumes adc0_se8 is mapped to PORTB.0)
 *  const Adc_T<PORTB_CLOCK_MASK,
 *                   PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),
 *                   ADC0_BasePtr,
 *                   SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG),
 *                   ADC0_CLOCK_MASK, 8> adc0_se8;
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
template<uint32_t portClockMask, uint32_t pcrReg, uint32_t adc, uint32_t adcClockReg, uint32_t adcClockMask, uint8_t adcChannel> class Adc_T {
public:
   using Pcr = Pcr_T<portClockMask, pcrReg, PORT_PCR_MUX(ADC_PORT_FN)|DEFAULT_PCR>; //!< PCR information

   /**
    * Set port pin as analogue input
    *
    * @param mode Mode for converter (currently only resolution)
    *
    * @note This initialises the ADC
    */
   static void setMode(uint32_t mode = resolution_16bit_se) {
      // Enable clock to ADC
      *reinterpret_cast<volatile uint32_t*>(adcClockReg)  |= adcClockMask;
      Pcr::setPCR(ADC_PORT_FN);

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
   static int readAnalogue() {
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
 * Controls basic operation of PWM/Input capture
 */
enum Tmr_ChannelMode {
   //! Capture rising edge
   tpm_inputCaptureRisingEdge  = TPM_CnSC_MS(0)|TPM_CnSC_ELS(1),
   //! Capture falling edge
   tpm_inputCaptureFallingEdge = TPM_CnSC_MS(0)|TPM_CnSC_ELS(2),
   //! Capture both rising and falling edges
   tpm_inputCaptureEitherEdge  = TPM_CnSC_MS(0)|TPM_CnSC_ELS(3),
   //! Output compare operation
   tpm_outputCompare           = TPM_CnSC_MS(1),
   //! Toggle pin on output compare
   tpm_outputCompareToggle     = TPM_CnSC_MS(1)|TPM_CnSC_ELS(1),
   //! Clear pin on output compare
   tpm_outputCompareClear      = TPM_CnSC_MS(1)|TPM_CnSC_ELS(2),
   //! Set pin on output compare
   tpm_outputCompareSet        = TPM_CnSC_MS(1)|TPM_CnSC_ELS(3),
   //! PWM with high-true pulses
   tpm_pwmHighTruePulses       = TPM_CnSC_MS(2)|TPM_CnSC_ELS(2),
   //! PWM with low-true pulses
   tpm_pwmLowTruePulses        = TPM_CnSC_MS(2)|TPM_CnSC_ELS(1),
} ;

/**
 * Control alignment of PWM function
 */
enum Tmr_Mode {
   //! Left-aligned PWM - also used for input capture and output compare modes
   tpm_leftAlign   = 0,
   //! Centre-aligned PWM
   tpm_centreAlign = TPM_SC_CPWMS_MASK,
} ;

/**
 * Templated class representing the common functions of an TPM
 *
 * Example
 * @code
 * // Instantiate the tpm (for FTM0)
 * const USBDM::TpmBase_T<TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK> Ftm0;
 *
 * // Initialise PWM with initial period and alignment
 * tpm0.setMode(200, USBDM::tpm_leftAlign);
 *
 * // Change period (in ticks)
 * tpm0.setPeriod(500);
 * @endcode
 *
 * @tparam tpm           TPM hardware
 * @tparam tpmClockReg   SIM Clock register for TPM
 * @tparam tpmClockMask  Mask for TPM clock register
 */
template<uint32_t tpm, uint32_t tpmClockReg, uint32_t tpmClockMask, uint16_t scValue> class TpmBase_T {
public:

   /**
    * Configure Timer operation
    *
    * @param period  Period in timer ticks
    * @param mode    Mode of operation see @ref Tmr_Mode
    */
   static void setMode(int period /* ticks */, Tmr_Mode mode=tpm_leftAlign) {

      // Enable clock to timer
      *reinterpret_cast<volatile uint32_t*>(tpmClockReg) |= tpmClockMask;

      // Common registers
      reinterpret_cast<volatile TPM_Type*>(tpm)->SC      = TPM_SC_CMOD(0); // Disable FTM so register changes are immediate
      reinterpret_cast<volatile TPM_Type*>(tpm)->CNT     = 0;
      if (mode == tpm_centreAlign) {
         reinterpret_cast<volatile TPM_Type*>(tpm)->MOD  = period/2;
         // Centre aligned PWM with CPWMS not selected
         reinterpret_cast<volatile TPM_Type*>(tpm)->SC   = scValue|TPM_SC_CPWMS_MASK;
      }
      else {
         reinterpret_cast<volatile TPM_Type*>(tpm)->MOD  = period-1;
         // Left aligned PWM without CPWMS selected
         reinterpret_cast<volatile TPM_Type*>(tpm)->SC   = scValue;
      }
   }

   /**
    * Set period
    *
    * @param period Period in timer ticks
    */
   static void setPeriod(int period) {
      // Common registers
      reinterpret_cast<volatile TPM_Type*>(tpm)->SC = TPM_SC_PS(0); // Disable FTM so register changes are immediate

      if ((reinterpret_cast<volatile TPM_Type*>(tpm)->SC&TPM_SC_CPWMS_MASK) != 0) {
         reinterpret_cast<volatile TPM_Type*>(tpm)->MOD = period/2;
         // Centre aligned PWM with CPWMS not selected
         reinterpret_cast<volatile TPM_Type*>(tpm)->SC  = scValue|TPM_SC_CPWMS_MASK;
      }
      else {
         reinterpret_cast<volatile TPM_Type*>(tpm)->MOD = period-1;
         // Left aligned PWM without CPWMS selected
         reinterpret_cast<volatile TPM_Type*>(tpm)->SC  = scValue;
      }
   }
};

/**
 * Templated class representing a pin with PWM capability
 *
 * Example
 * @code
 * // Instantiate the tpm channel (for FTM0 CH6)
 * const USBDM::Ftm0<PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),   3,  6>   tpm0_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * tpm0_ch6.setPwmOutput(200, PwmIO::tpm_leftAlign);
 *
 * // Change period (in ticks)
 * tpm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * tpm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam portClockMask Mask for clock register for PORT associated with this TPM
 * @tparam pcrReg        PCR for the PORT pin associated with this TPM
 * @tparam tpmMuxFn      PCR multiplexer selection to map pin to TPM
 * @tparam tpm           TPM hardware
 * @tparam tpmClockReg   SIM Clock register for TPM
 * @tparam tpmClockMask  Mask for TPM clock register
 * @tparam tpmChannel    TPM channel
 */
template<uint32_t portClockMask, uint32_t pcrReg, uint32_t tpmMuxFn, uint32_t tpm, uint32_t tpmClockReg, uint32_t tpmClockMask, uint16_t scValue, uint32_t tpmChannel> class Tpm_T :
      public TpmBase_T<tpm, tpmClockReg, tpmClockMask, scValue> {

public:
   using Pcr = Pcr_T<portClockMask, pcrReg, PORT_PCR_MUX(tpmMuxFn)|DEFAULT_PCR>;   //!< PCR information

   /**
    * Set PWM duty cycle
    *
    * @param dutyCycle Duty-cycle as percentage
    */
   static void setDutyCycle(int dutyCycle) {
      reinterpret_cast<volatile TPM_Type*>(tpm)->CONTROLS[tpmChannel].CnSC = tpm_pwmHighTruePulses;

      if (reinterpret_cast<volatile TPM_Type*>(tpm)->SC&TPM_SC_CPWMS_MASK) {
         reinterpret_cast<volatile TPM_Type*>(tpm)->CONTROLS[tpmChannel].CnV  = (dutyCycle*reinterpret_cast<volatile TPM_Type*>(tpm)->MOD)/100;
      }
      else {
         reinterpret_cast<volatile TPM_Type*>(tpm)->CONTROLS[tpmChannel].CnV  = (dutyCycle*(reinterpret_cast<volatile TPM_Type*>(tpm)->MOD+1))/100;
      }
   }
};

/**
 * @}
 */

/**
 * @brief Get Clock mask for the Port associated with a peripheral channel.
 * Looks up value in peripheral specific table
 *
 * @param channel Channel e.g. FTM0_CH3 => 3, ADC2_Ch1 => 1
 * @param info    Table of PCR information for peripheral (constexpr array)
 *
 * @return clock mask e.g. SIM_SCGC5_PORTA_MASK (as a number)
 */
constexpr uint32_t getPortClockMask(unsigned channel, const PcrInfo info[]) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdiv-by-zero"
   return (channel<=32)?info[channel].clockMask:(1/0);
#pragma GCC diagnostic pop
}
/**
 * @brief Get address of PCR for the Port associated with a peripheral channel.
 * Looks up value in peripheral specific table
 *
 * @param channel Channel e.g. FTM0_CH3 => 3, ADC2_Ch1 => 1
 * @param info    Table of PCR information for peripheral (constexpr array)
 *
 * @return PCR address (e.g. PORTC_BasePtr+offsetof(PORT_Type,PCR[2]))
 */
constexpr uint32_t getPcrReg(unsigned channel, const PcrInfo info[]) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdiv-by-zero"
   return (channel<=32)?info[channel].pcrAddress:(1/0);
#pragma GCC diagnostic pop
}
/**
 * @brief Get PCR mux value to map a peripheral channel to the port pin.
 * Looks up value in peripheral specific table
 *
 * @param channel Channel e.g. FTM0_CH3 => 3, ADC2_Ch1 => 1
 * @param info    Table of PCR information for peripheral (constexpr array)
 *
 * @return  Mux value [0..15]
 */
constexpr uint32_t getPcrMux(unsigned channel, const PcrInfo info[]) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdiv-by-zero"
   return (channel<=32)?info[channel].muxValue:(1/0);
#pragma GCC diagnostic pop
}
/**
 * @brief Get address of GPIO associated with peripheral pin
 * Looks up value in peripheral specific table
 *
 * @param channel Channel/Pin e.g. FTM0_CH3 => 3, ADC2_Ch1 => 1
 * @param info    Table of PCR information for peripheral (constexpr array)
 *
 * @return GPIO address e.g. GPIOC_BasePtr
 */
constexpr uint32_t getGpioAddress(unsigned channel, const PcrInfo info[]) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdiv-by-zero"
   return (channel<=32)?info[channel].gpioAddress:(1/0);
#pragma GCC diagnostic pop
}
/**
 * @brief Get GPIO bit number associated with a peripheral channel.
 * Looks up value in peripheral specific table
 *
 * @param channel Channel e.g. FTM0_CH3 => 3, ADC2_Ch1 => 1
 * @param info    Table of PCR information for peripheral (constexpr array)
 *
 * @return  Bit number of GPIO bit
 */
constexpr uint32_t getGpioBit(unsigned channel, const PcrInfo info[]) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdiv-by-zero"
   return (channel<=32)?info[channel].gpioBit:(1/0);
#pragma GCC diagnostic pop
}
/**
 * @brief Templated function to set a PCR to the default value
 *
 * @tparam  Last PCR to modify
 */
template<typename Last>
void processPcrs() {
   Last::setPCR();
}

/**
 * @brief Templated function to set a collection of PCRs to the default value
 *
 * @tparam  Pcr1 PCR to modify
 * @tparam  Pcr2 PCR to modify
 * @tparam  Rest remaining PCRs to modify
 */
template<typename Pcr1, typename  Pcr2, typename  ... Rest>
void processPcrs() {
   processPcrs<Pcr1>();
   processPcrs<Pcr2, Rest...>();
}
/**
 * @brief Templated function to set a PCR to the default value
 *
 * @param   pcrValue PCR value to set
 *
 * @tparam  Last PCR to modify
 */
template<typename Last>
void processPcrs(uint32_t pcrValue) {
   Last::setPCR(pcrValue);
}

/**
 * @brief Templated function to set a collection of PCRs to the default value
 *
 * @param pcrValue PCR value to set
 *
 * @tparam  Pcr1 PCR to modify
 * @tparam  Pcr2 PCR to modify
 * @tparam  Rest remaining PCRs to modify
 */
template<typename Pcr1, typename  Pcr2, typename  ... Rest>
void processPcrs(uint32_t pcrValue) {
   processPcrs<Pcr1>(pcrValue);
   processPcrs<Pcr2, Rest...>(pcrValue);
}

} // End namespace USBDM

#endif /* HEADER_GPIO_DEFS_H */
