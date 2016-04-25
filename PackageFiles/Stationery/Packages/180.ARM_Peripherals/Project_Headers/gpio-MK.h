/**
 * @file     gpio.h (from gpio_defs-MK.h)
 * @brief    GPIO interface
 *
 * @version  V4.12.1.80
 * @date     13 April 2016
 */
#ifndef HEADER_GPIO_H
#define HEADER_GPIO_H

#include <stddef.h>
#include <assert.h>
#include "derivative.h"
#include "bitband.h"

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

namespace USBDM {

/** Indicates the function has a fixed mapping to a pin */
constexpr   int8_t FIXED_NO_PCR         = 0x00;

/** Indicates the function doesn't exist */
constexpr   int8_t INVALID_PCR          = 0xA5;

/** Indicates the function is not currently mapped to a pin */
constexpr   int8_t UNMAPPED_PCR         = 0xA4;

/**
 * @addtogroup PeripheralPinTables Peripheral Information Classes
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
   int8_t   gpioBit;     //!< Bit number of pin in GPIO
   uint32_t pcrValue;    //!< PCR value including MUX value to select this function
};

/**
 * @}
 ** PeripheralPinTables
 */

/**
 * @addtogroup PeripheralPinTables Peripheral Information Classes
 * @brief Provides information about pins used by a peripheral
 * @{
 */

/**
 * Default PCR setting for pins (excluding multiplexor value)
 * High drive strength + Pull-up
 */
static constexpr uint32_t    DEFAULT_PCR      = (PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
/**
 * Default PCR value for pins used as GPIO (including multiplexor value)
 */
static constexpr uint32_t    GPIO_DEFAULT_PCR = DEFAULT_PCR|PORT_PCR_MUX(FIXED_GPIO_FN);

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
 * @tparam defPcrValue     Default value for PCR (including MUX value)
 */
template<uint32_t clockMask, uint32_t pcrAddress, int32_t bitNum, uint32_t defPcrValue>
class Pcr_T {

private:

#ifdef DEBUG_BUILD
   static_assert((bitNum != UNMAPPED_PCR), "Pcr_T: Signal is not mapped to a pin - Modify Configure.usbdm");
   static_assert((bitNum != INVALID_PCR),  "Pcr_T: Non-existent signal");
   static_assert((bitNum == UNMAPPED_PCR)||(bitNum == INVALID_PCR)||(bitNum >= 0), "Pcr_T: Illegal bit number");
#endif

public:
   /**
    * Set pin PCR value\n
    * The clock to the port will be enabled before changing the PCR
    *
    * @param pcrValue PCR value made up of PORT_PCR_x masks including MUX value
    */
   static void setPCR(uint32_t pcrValue=defPcrValue) {
      if ((pcrAddress != 0) && (bitNum >= 0)) {
         enableClock();

         // Pointer to PCR register for pin
         constexpr volatile uint32_t *pcrReg = reinterpret_cast<volatile uint32_t *>(pcrAddress+offsetof(PORT_Type,PCR[bitNum]));
         *pcrReg = pcrValue;
      }
   }
   /**
    * Set pin PCR.MUX value\n
    * Assumes clock to the port has already been enabled\n
    * Other PCR bits are taken from default value in template
    *
    * @param muxValue PCR MUX value [0..7]
    */
   static void setMUX(uint32_t muxValue) {
      if ((pcrAddress != 0) && (bitNum >= 0)) {
         // Pointer to PCR register for pin
         constexpr volatile uint32_t *pcrReg = reinterpret_cast<volatile uint32_t *>(pcrAddress+offsetof(PORT_Type,PCR[bitNum]));
         *pcrReg = (defPcrValue&~PORT_PCR_MUX_MASK)|PORT_PCR_MUX(muxValue);
      }
   }
   /**
    * Enable clock to port
    */
   static void enableClock() {
//      bitbandSet(SIM->FIXED_PORT_CLOCK_REG, clockBit);
      SIM->FIXED_PORT_CLOCK_REG |= clockMask;
      __DMB();
   }
   /**
    * Disable clock to port
    */
   static void disableClock() {
//      bitbandClear(SIM->FIXED_PORT_CLOCK_REG, clockBit);
      SIM->FIXED_PORT_CLOCK_REG &= ~clockMask;
   }
};

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
 * @addtogroup GPIO_Group GPIO, Digital Input/Output
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
 * @tparam clockMask       Clock mask for PORT (PCR register array) associated with GPIO
 * @tparam pcrAddress      Address of PORT (PCR register array) associated with GPIO
 * @tparam gpioAddress     GPIO hardware address
 * @tparam bitNum          Bit number within PORT/GPIO
 * @tparam defPcrValue     Default value for PCR including MUX value
 */
template<uint32_t clockMask, uint32_t pcrAddress, uint32_t gpioAddress, uint32_t bitNum, uint32_t defPcrValue>
class GpioBase_T {

public:
   using Pcr = Pcr_T<clockMask, pcrAddress, bitNum, defPcrValue>;

   static constexpr volatile GPIO_Type *gpio = reinterpret_cast<volatile GPIO_Type *>(gpioAddress);

   /**
    * Set pin as digital output
    *
    * @param pcrValue PCR value to use in configuring port (excluding MUX value)
    */
   static void setOutput(uint32_t pcrValue=defPcrValue) {
      bitbandSet(gpio->PDDR, bitNum);
      Pcr::setPCR((pcrValue&~PORT_PCR_MUX_MASK)|(defPcrValue&PORT_PCR_MUX_MASK));
//      gpio->PDDR |= (1<<bitNum);
   }
   /**
    * Set pin as digital input
    *
    * @param pcrValue PCR value to use in configuring port (excluding MUX value)
    */
   static void setInput(uint32_t pcrValue=defPcrValue) {
      bitbandClear(gpio->PDDR, bitNum);
      Pcr::setPCR((pcrValue&~PORT_PCR_MUX_MASK)|(defPcrValue&PORT_PCR_MUX_MASK));
//      gpio->PDDR &= ~(1<<bitNum);
   }
   /**
    * Toggle pin
    */
   static void toggle() {
      gpio->PTOR = (1<<bitNum);
   }
   /**
    * Set pin high
    */
   static void set() {
      gpio->PSOR = (1<<bitNum);
   }
   /**
    * Set pin low
    */
   static void clear() {
      gpio->PCOR = (1<<bitNum);
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
      if (value) {
         set();
      }
      else {
         clear();
      }
   }
   /**
    * Read pin value
    * Note: this reads the PDIR not the PDOR
    *
    * @return true/false reflecting pin value
    */
   static bool read() {
      return (gpio->PDIR & (1<<bitNum));
   }
   /**
    * Read value being driven to pin if output
    * Note: this reads the PDOR not the PDIR
    *
    * @return true/false reflecting value in output register
    */
   static bool readState() {
      return (gpio->PDOR & (1<<bitNum));
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
 * Pcr_T<spiInfo, 3>::setPCR(PORT_PCR_DSE_MASK|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK);
 * @endcode
 *
 * @tparam info          Configuration class
 * @tparam index         Index of pin in configuration table
 */
template<class Info, uint8_t index> using PcrTable_T =
      Pcr_T<Info::info[index].clockMask, Info::info[index].pcrAddress, Info::info[index].gpioBit, Info::info[index].pcrValue>;

/**
 * Create GPIO from GpioInfo class
 *
 * @tparam Info            Gpio information class
 * @tparam bitNum          Bit number within PORT/GPIO
 * @tparam defPcrValue     Default value for PCR including MUX value
 */
template<class Info, const uint32_t bitNum, uint32_t defPcrValue=Info::pcrValue>
using  Gpio_T = GpioBase_T<Info::clockMask, Info::pcrAddress, Info::gpioAddress, bitNum, defPcrValue>;

/**
 * Create GPIO from Peripheral Info class
 *
 * @tparam Info            Peripheral information class
 * @tparam index           Index of signal within the info table
 * @tparam defPcrValue     Default value for PCR including MUX value
 */
template<class Info, const uint32_t index, uint32_t defPcrValue=Info::pcrValue>
using  GpioTable_T = GpioBase_T<Info::info[index].clockMask, Info::info[index].pcrAddress, Info::info[index].gpioAddress, Info::info[index].gpioBit, defPcrValue>;

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
      SIM->FIXED_PORT_CLOCK_REG |= Info::portClockMask;

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
      gpio->PDDR |= MASK;
   }
   /**
    * Set pin as digital input
    *
    * @param pcrValue PCR value to use in configuring port (excluding mux fn)
    */
   static void setInput(uint32_t pcrValue=defPcrValue) {
      setPCRs(pcrValue);
      gpio->PDDR &= ~MASK;
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
      gpio->PSOR = (mask<<right)&MASK;
   }
   /**
    * Clear bits in field
    *
    * @param mask Mask to apply to the field (1 => clear bit, 0 => unchanged)
    */
   static void bitClear(const uint32_t mask) {
      gpio->PCOR = (mask<<right)&MASK;
   }
   /**
    * Read field
    *
    * @return value from field
    */
   static uint32_t read() {
      return ((gpio->PDIR) & MASK)>>right;
   }
   /**
    * Write field
    *
    * @param value to insert as field
    */
   static void write(uint32_t value) {
      (gpio->PDOR) = (gpio->PDOR) & ~MASK | ((value<<right)&MASK);
   }
};

/**
 * @}
 */

} // End namespace USBDM

#endif /* HEADER_GPIO_H */

