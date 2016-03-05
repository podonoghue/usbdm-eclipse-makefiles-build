/**
 * @file     gpio_defs.h (from gpio_defs-MKM.h)
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
 * @addtogroup PeripheralPinTables Peripheral Pin Tables
 * @brief Provides information about pins used by a peripheral
 * @{
 */
/**
 * Struct for Pin Control Register information\n
 * Information required to configure the PCR for a particular function
 */
struct PcrInfo {
   uint32_t clockMask;   //!< Clock mask for PORT
   uint32_t pcrAddress;  //!< PCR register array address
   uint32_t gpioAddress; //!< Address of GPIO hardware associated with pin
   uint8_t  gpioBit;     //!< Bit number of pin in GPIO
   uint8_t  muxValue;    //!< PCR multiplexor value to select this function
};

/**
 * @}
 ** PeripheralPinTables
 */

/**
 * @addtogroup PeripheralPinTables Peripheral Pin Tables
 * @brief Provides information about pins used by a peripheral
 * @{
 */

/**
 * Default PCR setting for pins (excluding multiplexor value)
 * High drive strength + Pull-up
 */
static constexpr uint32_t    DEFAULT_PCR      = (PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
/**
 * PCR multiplexor value for digital function
 */
static constexpr uint32_t    GPIO_PORT_FN     = PORT_PCR_MUX(FIXED_GPIO_FN);
/**
 * Default PCR value for pins used as GPIO (including multiplexor value)
 */
static constexpr uint32_t    GPIO_DEFAULT_PCR = DEFAULT_PCR|GPIO_PORT_FN;

#ifndef PORT_PCR_ODE_MASK
/**
 * Some devices don't have ODE function on pin
 * The open-drain mode is automatically selected when I2C function is selected for the pin
 */
#define PORT_PCR_ODE_MASK 0
#endif
/**
 * Default PCR setting for I2C pins (excluding multiplexor value)
 * High drive strength + Pull-up + Open-drain (if available)
 */
static constexpr uint32_t  I2C_DEFAULT_PCR = DEFAULT_PCR|PORT_PCR_ODE_MASK;

/**
 * @brief Template representing a Pin Control Register (PCR)
 *
 * Code examples:
 * @code
 * // Create PCR type
 * Pcr_T<PORTC_CLOCK_MASK, PORTC_BasePtr, 3> PortC_3;
 *
 * // Configure PCR
 * PortC_3.setPCR(PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_MUX(3));
 *
 * // Disable clock to associated PORT
 * pcr.disableClock();
 *
 * // Alternatively the PCR may be manipulated directly
 * Pcr_T<PORTC_CLOCK_MASK, PORTC_BasePtr, 3>.setPCR(PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_MUX(3));
 * @endcode
 *
 * @tparam clockMask       Mask for SIM clock register associated with this PCR
 * @tparam pcrAddress      PORT to be manipulated e.g. PORTA (PCR array)
 * @tparam bitNum          Bit number e.g. 3
 * @tparam defPcrValue     Default value for PCR
 */
template<uint32_t clockMask, uint32_t pcrAddress, uint32_t bitNum, uint32_t defPcrValue=DEFAULT_PCR>
class Pcr_T {

private:
   // Pointer to PCR register for pin
   static constexpr volatile uint32_t *pcrReg = reinterpret_cast<volatile uint32_t *>(pcrAddress+offsetof(PORT_Type,PCR[bitNum]));

public:
   /**
    * Set pin PCR value\n
    * The clock to the port will be enabled before changing the PCR
    *
    * @param pcrValue PCR value made up of PORT_PCR_x masks
    */
   static void setPCR(uint32_t pcrValue=defPcrValue) {
      if (pcrReg != 0) {
         enableClock();
         *pcrReg = pcrValue;
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
 * @brief Template representing a Pin Control Register (PCR)\n
 * Makes use of a configuration class
 *
 * Code examples:
 * @code
 * // Create PCR type
 * Pcr_T<spiInfo, 3> SpiMOSI;
 *
 * // Configure PCR
 * SpiMOSI.setPCR(PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_MUX(3));
 *
 * // Disable clock to associated PORT
 * SpiMOSI.disableClock();
 *
 * // Alternatively the PCR may be manipulated directly
 * Pcr_T<PORTC_CLOCK_MASK, PORTC_BasePtr, 3>.setPCR(PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
 * @endcode
 *
 * @tparam info          Configuration class
 * @tparam index         Index of pin in configuration table
 * @tparam pcrValue      Default value for PCR excluding mux value
 */
template<class info, uint8_t index, uint32_t pcrValue=info::pcrValue> using PcrTable_T =
      Pcr_T<info::info[index].clockMask, info::info[index].pcrAddress, info::info[index].gpioBit, PORT_PCR_MUX(info::info[index].muxValue)|pcrValue>;

/**
 * @brief Template function to set a PCR to the default value
 *
 * @tparam  Last PCR to modify
 */
template<typename Last>
void processPcrs() {
   Last::setPCR();
}
/**
 * @brief Template function to set a collection of PCRs to the default value
 *
 * @tparam  Pcr1 PCR to modify
 * @tparam  Pcr2 PCR to modify
 * @tparam  Rest Remaining PCRs to modify
 */
template<typename Pcr1, typename  Pcr2, typename  ... Rest>
void processPcrs() {
   processPcrs<Pcr1>();
   processPcrs<Pcr2, Rest...>();
}
/**
 * @brief Template function to set a PCR to a given value
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
 * @brief Template function to set a collection of PCRs to a given value
 *
 * @param pcrValue PCR value to set
 *
 * @tparam  Pcr1 PCR to modify
 * @tparam  Pcr2 PCR to modify
 * @tparam  Rest Remaining PCRs to modify
 */
template<typename Pcr1, typename  Pcr2, typename  ... Rest>
void processPcrs(uint32_t pcrValue) {
   processPcrs<Pcr1>(pcrValue);
   processPcrs<Pcr2, Rest...>(pcrValue);
}

/**
 * @}
 ** PeripheralPinTables
 */

/**
 * @addtogroup DigitalIO_Group Digital Input/Output
 * @{
 */

/**
 * @brief Template representing a pin with Digital I/O capability
 *
 * <b>Example</b>
 * @code
 * // Instantiate
 * USBDM::Gpio_T<SIM_SCGC5_PORTA_SHIFT, PORTA_BasePtr, 3, GPIOA_BasePtr> pta3;
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
 * @tparam Pcr             PCR associated with this GPIO
 * @tparam bitNum          Bit number in the PORT associated with this GPIO
 * @tparam defPcrValue     Default value for PCR including mux value
 */
template<class Pcr, const uint32_t gpioAddress, const uint32_t bitNum, uint32_t defPcrValue>
class GpioBase_T {

public:

   static constexpr volatile GPIO_Type *gpio = reinterpret_cast<volatile GPIO_Type *>(gpioAddress);

public:
   /**
    * Set pin as digital output
    *
    * @param pcrValue PCR value to use in configuring port (excluding mux fn)
    */
   static void setOutput(uint32_t pcrValue=defPcrValue) {
      bmeOr(gpio->PDDR, 1<<bitNum);
      Pcr::setPCR((pcrValue&~PORT_PCR_MUX_MASK)|(defPcrValue&PORT_PCR_MUX_MASK));
//      gpio->PDDR |= (1<<bitNum);
   }
   /**
    * Set pin as digital input
    *
    * @param pcrValue PCR value to use in configuring port (excluding mux fn)
    */
   static void setInput(uint32_t pcrValue=defPcrValue) {
      bmeAnd(gpio->PDDR, ~(1<<bitNum));
      Pcr::setPCR((pcrValue&~PORT_PCR_MUX_MASK)|(defPcrValue&PORT_PCR_MUX_MASK));
//      gpio->PDDR &= ~(1<<bitNum);
   }
   /**
    * Toggle pin
    */
   static void toggle() {
      gpio->PDOR ^= (1<<bitNum);
   }
   /**
    * Set pin high
    */
   static void set() {
      gpio->PDOR |= (1<<bitNum);
   }
   /**
    * Set pin low
    */
   static void clear() {
      gpio->PDOR &= ~(1<<bitNum);
   }
   /**
    * Set pin high
    */
   static void high() {
      set();
   }
   /**
    * Set pin low
    */
   static void low() {
      clear();
   }
   /**
    * Write boolean value to digital output
    *
    * @param value true/false value
    */
   static void write(bool value) {
      bmeInsert(gpio->PDOR, bitNum, 1, (value!=0));
   }
   /**
    * Read pin value
    * Note: this reads the PDIR not the PDOR
    *
    * @return true/false reflecting pin value
    */
   static bool read() {
      return bmeExtract(gpio->PDIR, bitNum, 1);
   }
   /**
    * Read value being driven to pin if output
    * Note: this reads the PDOR not the PDIR
    *
    * @return true/false reflecting value in output register
    */
   static bool readState() {
      return bmeExtract(gpio->PDOR, bitNum, 1);
   }
};

/**
 * Create GPIO from GpioInfo class
 *
 * @tparam Info            Gpio information class
 * @tparam bitNum          Bit number in the PORT associated with this GPIO
 * @tparam defPcrValue     Default value for PCR including multiplexor value
 */
template<class Info, const uint32_t bitNum, uint32_t defPcrValue=Info::pcrValue>
using  Gpio_T = GpioBase_T<Pcr_T<Info::clockMask, Info::pcrAddress, bitNum, defPcrValue>, Info::gpioAddress, bitNum, defPcrValue>;

/**
 * Create GPIO from Peripheral Info class
 *
 * @tparam Info            Peripheral information class
 * @tparam bitNum          Signal number to index the info table
 * @tparam defPcrValue     Default value for PCR excluding multiplexor value
 */
template<class Info, const uint32_t bitNum, uint32_t defPcrValue=Info::pcrValue>
using  GpioTable_T =
   GpioBase_T<
   Pcr_T<Info::info[bitNum].clockMask, Info::info[bitNum].pcrAddress, bitNum, defPcrValue>,
   Info::info[bitNum].gpioAddress,
   bitNum,
   (defPcrValue&~PORT_PCR_MUX_MASK)|PORT_PCR_MUX(Info::info[bitNum].muxValue)>;

/**
 * @brief Template representing a field within a port
 *
 * <b>Example</b>
 * @code
 * // Instantiate object representing Port A 6 down to 3
 * Field_T<GpioAInfo, 6, 3> pta6_3;
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
 * @tparam Info           Class describing the GPIO and PORT
 * @tparam left           Bit number of leftmost bit in GPIO (inclusive)
 * @tparam right          Bit number of rightmost bit in GPIO (inclusive)
 * @tparam defPcrValue    Default value for PCR including multiplexor value
 */
template<class Info, const uint32_t left, const uint32_t right, uint32_t defPcrValue=Info::pcrValue>
class Field_T {

private:
   static constexpr volatile GPIO_Type *gpio = reinterpret_cast<volatile GPIO_Type *>(Info::gpioAddress);
   static constexpr volatile PORT_Type *port = reinterpret_cast<volatile PORT_Type *>(Info::pcrAddress);
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
//      SIM->FIXED_PORT_CLOCK_REG |= Info::portClockMask;
      bmeOr(SIM->FIXED_PORT_CLOCK_REG, Info::portClockMask);

      // Include the if's as I expect one branch to be removed by optimisation unless the field spans the boundary
      if ((MASK&0xFFFFUL) != 0) {
         port->GPCLR = PORT_GPCLR_GPWE(MASK)|(pcrValue&~PORT_PCR_MUX_MASK)|(defPcrValue&PORT_PCR_MUX_MASK);
      }
      if ((MASK&~0xFFFFUL) != 0) {
         port->GPCHR = PORT_GPCHR_GPWE(MASK>>16)|(pcrValue&~PORT_PCR_MUX_MASK)|(defPcrValue&PORT_PCR_MUX_MASK);
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
      bmeOr(gpio->PDDR, MASK);
//      gpio->PDDR |= MASK;
   }
   /**
    * Set pin as digital input
    *
    * @param pcrValue PCR value to use in configuring port (excluding mux fn)
    */
   static void setInput(uint32_t pcrValue=defPcrValue) {
      setPCRs(pcrValue);
      bmeAnd(gpio->PDDR, ~MASK);
//      gpio->PDDR &= ~MASK;
   }
   /**
    * Set individual pin directions
    *
    * @param mask Mask for pin directions (1=>out, 0=>in)
    */
   static void setDirection(uint32_t mask) {
      gpio->PDDR = (gpio->PDDR&~MASK)|(mask<<right)&MASK;
   }
   /**
    * Set bits in field
    *
    * @param mask Mask to apply to the field (1 => set bit, 0 => unchanged)
    */
   static void bitSet(const uint32_t mask) {
      gpio->PDOR |= (mask<<right)&MASK;
   }
   /**
    * Clear bits in field
    *
    * @param mask Mask to apply to the field (1 => clear bit, 0 => unchanged)
    */
   static void bitClear(const uint32_t mask) {
      gpio->PDOR &= ~((mask<<right)&MASK);
   }
   /**
    * Read field
    *
    * @return value from field
    */
   static uint32_t read() {
      return bmeExtract(gpio->PDIR, right, left-right+1);
//      return ((gpio->PDIR) & MASK)>>right;
   }
   /**
    * Write field
    *
    * @param value to insert as field
    */
   static void write(uint32_t value) {
      bmeInsert(gpio->PDOR, right, left-right+1, value);
//      uint32_t preserved = (gpio->PDIR) & ~MASK;
//      (gpio->PDOR) = preserved | ((value<<right)&MASK);
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
 * Template class representing a pin with Analogue Input capability\n
 * Uses a information structure to describe the ADC
 *
 * Example
 * @code
 *  // Instantiate ADC channel adc0_se8
 *  const Adc_T<adc0Info, 8> adc0_se8;
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
 * @tparam info            Table of information describing ADC
 * @tparam adcChannel      ADC channel
 */
template<class info, uint8_t adcChannel>
class Adc_T {

private:
   static constexpr volatile ADC_Type *adc      = reinterpret_cast<volatile ADC_Type *>(info::basePtr);
   static constexpr volatile uint32_t *clockReg = reinterpret_cast<volatile uint32_t *>(info::clockReg);

public:
   using Pcr = PcrTable_T<info, adcChannel>;

   /**
    * Set port pin as analogue input
    *
    * @param mode Mode for converter (currently only resolution)
    *
    * @note This initialises the ADC
    */
   static void setMode(uint32_t mode = resolution_16bit_se) {
      // Enable clock to ADC
      *clockReg  |= info::clockMask;

      // Set up ADC pin
      Pcr::setPCR(ADC_PORT_FN);

      // Configure ADC for software triggered conversion
      adc->CFG1 = ADC_CFG1_ADIV(1)|mode|ADC_CFG1_ADLSMP_MASK|ADC_CFG1_ADICLK(0);
      adc->SC2  = 0;
      adc->CFG2 = ADC_CFG2_ADLSTS(0)|ADC_CFG2_MUXSEL_MASK; // Choose 'b' channels
   }
   /**
    * Initiates a conversion and waits for it to complete
    *
    * @return - the result of the conversion
    */
   static int readAnalogue() {
      // Trigger conversion
      adc->SC1[0] = ADC_SC1_ADCH(adcChannel);

      while ((adc->SC1[0]&ADC_SC1_COCO_MASK) == 0) {
         __asm__("nop");
      }
      return (int)adc->R[0];
   };
};

/**
 * @}
 */

} // End namespace USBDM

#endif /* HEADER_GPIO_DEFS_H */

