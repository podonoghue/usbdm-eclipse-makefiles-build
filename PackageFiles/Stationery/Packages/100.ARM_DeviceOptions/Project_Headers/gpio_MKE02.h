/*
 ============================================================================
 * @file gpio.cpp
 *
 *  Created on: 19/10/2019
 *      Author: podonoghue
 ============================================================================
 */
#ifndef HEADERS_GPIO_H
#define HEADERS_GPIO_H

#include <stdint.h>
#include "derivative.h"

namespace USBDM {

enum Polarity {
   ActiveHigh = true,
   ActiveLow  = false,
};

/**
 * Pin Filter using LPO clock
 */
enum PinFilterLpo {
   PinFilterLpo_Div1   = PORT_IOFLT_FLTDIV3(0b000), //!< LPO clock divided by 1
   PinFilterLpo_Div2   = PORT_IOFLT_FLTDIV3(0b001), //!< LPO clock divided by 2
   PinFilterLpo_Div4   = PORT_IOFLT_FLTDIV3(0b010), //!< LPO clock divided by 4
   PinFilterLpo_Div8   = PORT_IOFLT_FLTDIV3(0b011), //!< LPO clock divided by 8
   PinFilterLpo_Div16  = PORT_IOFLT_FLTDIV3(0b100), //!< LPO clock divided by 16
   PinFilterLpo_Div32  = PORT_IOFLT_FLTDIV3(0b101), //!< LPO clock divided by 32
   PinFilterLpo_Div64  = PORT_IOFLT_FLTDIV3(0b110), //!< LPO clock divided by 64
   PinFilterLpo_Div128 = PORT_IOFLT_FLTDIV3(0b111), //!< LPO clock divided by 128
};

/**
 * Pin Filter using slow bus clock
 */
enum PinFilterBusSlow {
   PinFilterBusSlow_Div32     = PORT_IOFLT_FLTDIV2(0b000), //!< Bus clock divided by 32
   PinFilterBusSlow_Div64     = PORT_IOFLT_FLTDIV2(0b001), //!< Bus clock divided by 64
   PinFilterBusSlow_Div128    = PORT_IOFLT_FLTDIV2(0b010), //!< Bus clock divided by 128
   PinFilterBusSlow_Div256    = PORT_IOFLT_FLTDIV2(0b011), //!< Bus clock divided by 256
   PinFilterBusSlow_Div512    = PORT_IOFLT_FLTDIV2(0b100), //!< Bus clock divided by 512
   PinFilterBusSlow_Div1024   = PORT_IOFLT_FLTDIV2(0b101), //!< Bus clock divided by 1024
   PinFilterBusSlow_Div2048   = PORT_IOFLT_FLTDIV2(0b110), //!< Bus clock divided by 2048
   PinFilterBusSlow_Div4096   = PORT_IOFLT_FLTDIV2(0b111), //!< Bus clock divided by 4096
};

/**
 * Pin Filter using fast bus clock
 */
enum PinFilterBusFast {
   PinFilterBusFast_Div2  = PORT_IOFLT_FLTDIV1(0), //!< Bus clock divided by 2
   PinFilterBusFast_Div4  = PORT_IOFLT_FLTDIV1(1), //!< Bus clock divided by 4
   PinFilterBusFast_Div8  = PORT_IOFLT_FLTDIV1(2), //!< Bus clock divided by 8
   PinFilterBusFast_Div16 = PORT_IOFLT_FLTDIV1(3), //!< Bus clock divided by 16
};

/**
 * Pin filter clock source
 */
enum PinFilterSel {
   PinFilterSel_None        = 0b00, //!< No filter
   PinFilterSel_BusFast_Lpo = 0b01, //!< Fast bus clock switching to LPO in Stop mode
   PinFilterSel_BusSlow_Lpo = 0b10, //!< Slow bus clock switching to LPO in Stop mode
   PinFilterSel_Lpo         = 0b11, //!< LPO in all modes
};

class PinFilters {

public:

   /**
    * Sets the division factors for the three selectable pin filters.
    * These filters are used by GPIOs and various other pin functions
    *
    * @param pinFilterBusFast    Filter derived from Bus clock /2, ... /16
    * @param pinFilterBusSlow    Filter derived from Bus clock /32, ... /4096
    * @param pinFilterLpo        Filter derived from LPO clock /1, ... /128
    */
   static void setFilterDividers(
         PinFilterBusFast pinFilterBusFast,
         PinFilterBusSlow pinFilterBusSlow,
         PinFilterLpo     pinFilterLpo) {

      PORT->IOFLT = (PORT->IOFLT & ~(PORT_IOFLT_FLTDIV1_MASK|PORT_IOFLT_FLTDIV2_MASK|PORT_IOFLT_FLTDIV3_MASK)) |
            pinFilterBusFast|pinFilterBusSlow|pinFilterLpo;
   }

   /**
    * Set pin filter for NMI
    *
    * @param pinFilterSel Filter selection
    */
   static void setNmiFilter(PinFilterSel pinFilterSel) {
      PORT->IOFLT = (PORT->IOFLT & ~PORT_IOFLT_FLTNMI_MASK) | PORT_IOFLT_FLTNMI(pinFilterSel);
   }

   /**
    * Set pin filter for RESET
    *
    * @param pinFilterSel Filter selection
    */
   static void setResetFilter(PinFilterSel pinFilterSel) {
      PORT->IOFLT = (PORT->IOFLT & ~PORT_IOFLT_FLTRST_MASK) | PORT_IOFLT_FLTRST(pinFilterSel);
   }

   /**
    * Set pin filter for KBI0
    *
    * @param pinFilterSel Filter selection
    */
   static void setKbi0Filter(PinFilterSel pinFilterSel) {
      PORT->IOFLT = (PORT->IOFLT & ~PORT_IOFLT_FLTKBI0_MASK) | PORT_IOFLT_FLTKBI0(pinFilterSel);
   }

   /**
    * Set pin filter for KBI1
    *
    * @param pinFilterSel Filter selection
    */
   static void setKbi1Filter(PinFilterSel pinFilterSel) {
      PORT->IOFLT = (PORT->IOFLT & ~PORT_IOFLT_FLTKBI1_MASK) | PORT_IOFLT_FLTKBI1(pinFilterSel);
   }

}; // PinFilter

class PortInfoEntry {
public:
   uint8_t  highDriveEnabledBits;   //!< Mask indicating bits with high drive available
   uint32_t highDriveEnableMask1;   //!< PORT_HDRVE mask for right-most bit
   uint32_t highDriveEnableMask2;   //!< PORT_HDRVE mask for left-most bit

   constexpr PortInfoEntry(
         uint8_t  highDriveEnabledBits,
         uint32_t highDriveEnableMask1,
         uint32_t highDriveEnableMask2) :
                        highDriveEnabledBits(highDriveEnabledBits),
                        highDriveEnableMask1(highDriveEnableMask1),
                        highDriveEnableMask2(highDriveEnableMask2)
   {}
};

class PortInfo {
public:
   static constexpr uint32_t LowPinPresent  = 0b11111111111111111111111111111111; // PTA,B,C,D
   static constexpr uint32_t HighPinPresent = 0b11000111000011111111111111111111; // PTE,F,G,H

   static constexpr PortInfoEntry HighDrive[] = {
         {0b00000000,      0b00000000,             0b00000000},           // A
         {(1<<4)|(1<<5),   PORT_HDRVE_PTB4_MASK,   PORT_HDRVE_PTB5_MASK}, // B
         {0b00000000,      0b00000000,             0b00000000},           // C
         {(1<<0)|(1<<1),   PORT_HDRVE_PTD0_MASK,   PORT_HDRVE_PTD1_MASK}, // D
         {(1<<0)|(1<<1),   PORT_HDRVE_PTE0_MASK,   PORT_HDRVE_PTE1_MASK}, // E
         {0b00000000,      0b00000000,             0b00000000},           // F
         {0b00000000,      0b00000000,             0b00000000},           // G
         {(1<<0)|(1<<1),   PORT_HDRVE_PTH0_MASK,   PORT_HDRVE_PTH1_MASK}, // H
   };
};

template <unsigned bitNum, Polarity polarity>
class Gpio {

public:
   static constexpr uint32_t WIDE_BIT_NUM    = bitNum&0b11111;
   static constexpr uint32_t WIDE_BIT_MASK   = 1<<WIDE_BIT_NUM;
   static constexpr uint32_t FILTER_BIT_NUM  = bitNum>>2;
   static constexpr uint32_t FILTER_BIT_MASK = 0b11<<FILTER_BIT_NUM;
   static constexpr uint32_t BIT_NUM         = bitNum&0b111;
   static constexpr uint32_t BIT_MASK        = 1<<BIT_NUM;

   static_assert(
         ((bitNum<32) && (PortInfo::LowPinPresent&WIDE_BIT_MASK)) ||
         ((bitNum>=32) && (PortInfo::HighPinPresent&WIDE_BIT_MASK)), "Port pin not present in this device");
   static_assert((bitNum<32)  || (PortInfo::HighPinPresent&WIDE_BIT_MASK),"Port pin not present in this device");

   /**
    * Enable pull-up on pin
    */
   static void enablePullUp() {
      if constexpr (bitNum>32) {
         PORT->PUEH |= WIDE_BIT_MASK;
      }
      else {
         PORT->PUEL |= WIDE_BIT_MASK;
      }
   }

   /**
    * Disable pull-up on pin
    */
   static void disablePullUp() {
      if constexpr (bitNum>32) {
         PORT->PUEH &= ~WIDE_BIT_MASK;
      }
      else {
         PORT->PUEL &= ~WIDE_BIT_MASK;
      }
   }

   /**
    * Set pin filter clock source
    *
    * @param pinFilterSel
    *
    * @note Affects the entire port (8-bits)
    */
   static void setFilter(PinFilterSel pinFilterSel) {
      PORT->IOFLT = (PORT->IOFLT & ~FILTER_BIT_MASK) | (pinFilterSel<<FILTER_BIT_NUM);
   }

   /**
    * Enable high drive on the pin
    *
    * @note Not all pins support this option
    */
   static void enableHighDrive() {
      static constexpr unsigned INFO_INDEX = (bitNum>>3);
      static_assert(BIT_MASK&PortInfo::HighDrive[INFO_INDEX].highDriveEnabledBits, "High drive not available on this port pin");

      if constexpr (
            (BIT_MASK&PortInfo::HighDrive[INFO_INDEX].highDriveEnabledBits) >
      (~BIT_MASK&PortInfo::HighDrive[INFO_INDEX].highDriveEnabledBits)) {
         PORT->HDRVE |= PortInfo::HighDrive[INFO_INDEX].highDriveEnableMask2;
      }
      else {
         PORT->HDRVE |= PortInfo::HighDrive[INFO_INDEX].highDriveEnableMask1;
      }
   }

   /**
    * Disable high drive on the pin
    *
    * @note Not all pins support this option
    */
   static void disableHighDrive() {
      static constexpr unsigned INFO_INDEX = (bitNum>>3);
      static_assert(BIT_MASK&PortInfo::HighDrive[INFO_INDEX].highDriveEnabledBits, "High drive not available on this port pin");

      if constexpr (
            (BIT_MASK&PortInfo::HighDrive[INFO_INDEX].highDriveEnabledBits) >
      (~BIT_MASK&PortInfo::HighDrive[INFO_INDEX].highDriveEnabledBits)) {
         PORT->HDRVE &= ~PortInfo::HighDrive[INFO_INDEX].highDriveEnableMask2;
      }
      else {
         PORT->HDRVE ^= ~PortInfo::HighDrive[INFO_INDEX].highDriveEnableMask1;
      }
   }

   /**
    * Set pin as digital output
    *
    * @note Does not affect other pin settings
    */
   static void setOut() {
      // Make pin an output
      if constexpr (bitNum<=32) {
         GPIOA->PDDR |= WIDE_BIT_MASK;
      }
      else {
         GPIOB->PDDR |= WIDE_BIT_MASK;
      }
   }

   /**
    * Make pin an output
    */
   static void setOutput() {
      // Set initial level before enabling pin drive
      setInactive();
      // Make pin an output
      setOut();
      // Allow pin to be read directly
      if constexpr (bitNum<=32) {
         GPIOA->PIDR &= ~WIDE_BIT_MASK;
      }
      else {
         GPIOB->PIDR &= ~WIDE_BIT_MASK;
      }
   }

   /**
    * Set pin as digital input
    *
    * @note Does not affect other pin settings
    */
   static void setIn() {
      if constexpr (bitNum<=32) {
         GPIOA->PDDR &= ~WIDE_BIT_MASK;
      }
      else {
         GPIOB->PDDR &= ~WIDE_BIT_MASK;
      }
   }
   /**
    * Make pin an input
    */
   static void setInput() {
      // Make pin an input
      setIn();
      // Allow pin to be read directly
      if constexpr (bitNum<=32) {
         GPIOA->PIDR &= ~WIDE_BIT_MASK;
      }
      else {
         GPIOB->PIDR &= ~WIDE_BIT_MASK;
      }
   }

   /**
    * Set pin. Pin will be high if configured as an output.
    *
    * @note Polarity _is_ _not_ significant
    * @note Don't use this method unless dealing with very low-level I/O
    */
   static void high() {
      if constexpr (bitNum<=32) {
         GPIOA->PSOR = WIDE_BIT_MASK;
      }
      else {
         GPIOB->PSOR = WIDE_BIT_MASK;
      }
   }
   /**
    * Clear pin. Pin will be low if configured as an output.
    *
    * @note Polarity _is_ _not_ significant
    * @note Don't use this method unless dealing with very low-level I/O
    */
   static void low() {
      if constexpr (bitNum<=32) {
         GPIOA->PCOR = WIDE_BIT_MASK;
      }
      else {
         GPIOB->PCOR = WIDE_BIT_MASK;
      }
   }

   /**
    * Set pin. Pin will be high if configured as an output.
    *
    * @note Polarity _is_ _not_ significant
    * @note Don't use this method unless dealing with very low-level I/O
    */
   static void set() {
      if constexpr (bitNum<=32) {
         GPIOA->PSOR = WIDE_BIT_MASK;
      }
      else {
         GPIOB->PSOR = WIDE_BIT_MASK;
      }
   }

   /**
    * Clear pin. Pin will be low if configured as an output.
    *
    * @note Polarity _is_ _not_ significant
    * @note Don't use this method unless dealing with very low-level I/O
    */
   static void clear() {
      if constexpr (bitNum<=32) {
         GPIOA->PCOR = WIDE_BIT_MASK;
      }
      else {
         GPIOB->PCOR = WIDE_BIT_MASK;
      }
   }

   /**
    * Toggle pin (if output)
    */
   static void togggle() {
      if constexpr (bitNum<=32) {
         GPIOA->PTOR = WIDE_BIT_MASK;
      }
      else {
         GPIOB->PTOR = WIDE_BIT_MASK;
      }
   }

   /**
    * Set pin to active level (if configured as output)
    *
    * @note Polarity _is_ significant
    */
   static void setActive() {
      if constexpr (polarity) {
         set();
      }
      else {
         clear();
      }
   }

   /**
    * Set pin to inactive level (if configured as output)
    *
    * @note Polarity _is_ significant
    */
   static void setInactive() {
      if constexpr (polarity) {
         clear();
      }
      else {
         set();
      }
   }

   /**
    * Set pin to active level (if configured as output).
    * Convenience method for setActive()
    *
    * @note Polarity _is_ significant
    */
   static void __attribute__((always_inline)) on() {
      setActive();
   }

   /**
    * Set pin to inactive level (if configured as output).
    * Convenience method for setInactive()
    *
    * @note Polarity _is_ significant
    */
   static void __attribute__((always_inline)) off() {
      setInactive();
   }

   /**
    * Write boolean value to pin (if configured as output)
    *
    * @param[in] value true/false value
    *
    * @note Polarity _is_ significant
    */
   static void write(bool value) {
      if (value) {
         setActive();
      }
      else {
         setInactive();
      }
   }

   /**
    * Checks if pin is high
    *
    * @return true/false reflecting value on pin
    *
    * @note This reads the PDIR
    * @note Polarity _is_ _not_ significant
    */
   static bool isHigh() {
      if constexpr (bitNum<=32) {
         return (GPIOA->PDIR & WIDE_BIT_MASK) != 0;
      }
      else {
         return (GPIOB->PDIR & WIDE_BIT_MASK) != 0;
      }
   }

   /**
    * Checks if pin is low
    *
    * @return true/false reflecting value on pin
    *
    * @note This reads the PDIR
    * @note Polarity _is_ _not_ significant
    */
   static bool isLow() {
      if constexpr (bitNum<=32) {
         return (GPIOA->PDIR & WIDE_BIT_MASK) == 0;
      }
      else {
         return (GPIOB->PDIR & WIDE_BIT_MASK) == 0;
      }
   }

   /**
    * Read pin value
    *
    * @return true/false reflecting pin value.
    *
    * @note This reads the PDIR
    * @note Polarity _is_ significant
    */
   static bool read() {
      if constexpr (polarity) {
         return isHigh();
      }
      else {
         return isLow();
      }
   }
   /**
    * Read pin value and return true if active level.
    * Equivalent to read()
    *
    * @return true/false reflecting if pin is active.
    *
    * @note This reads the PDIR
    * @note Polarity _is_ significant
    */
   static bool __attribute__((always_inline)) isActive() {
      return read();
   }
   /**
    * Read pin value and return true if inactive level
    * Equivalent to !read()
    *
    * @return true/false reflecting if pin is inactive.
    *
    * @note This reads the PDIR
    * @note Polarity _is_ significant
    */
   static bool __attribute__((always_inline)) isInactive() {
      return !read();
   }
   /**
    * Read pin value and return true if active level.\n
    * Convenience method equivalent to isActive()
    *
    * @return true/false reflecting if pin is active.
    *
    * @note This reads the PDIR
    * @note Polarity _is_ significant
    */
   static bool __attribute__((always_inline)) isPressed() {
      return isActive();
   }
   /**
    * Read pin value and return true if inactive level.\n
    * Convenience method equivalent to isInactive()
    *
    * @return true/false reflecting if pin is inactive.
    *
    * @note This reads the PDIR
    * @note Polarity _is_ significant
    */
   static bool __attribute__((always_inline)) isReleased() {
      return isInactive();
   }
   /**
    * Read value being driven to pin (if configured as output)
    *
    * @return true/false reflecting value in output register.
    *
    * @note This reads the PDOR
    * @note Polarity _is_ significant
    */
   static bool readState() {

      bool value;

      if constexpr (bitNum<=32) {
         value = (GPIOA->PDOR & WIDE_BIT_MASK) != 0;
      }
      else {
         value = (GPIOB->PDOR & WIDE_BIT_MASK) != 0;
      }
      if constexpr (polarity) {
         return value;
      }
      else {
         return !value;
      }
   }
};

template <unsigned bitNum, Polarity polarity=ActiveHigh>
using GpioA = Gpio<0+bitNum, polarity>;

template <unsigned bitNum, Polarity polarity=ActiveHigh>
using GpioB = Gpio<8+bitNum, polarity>;

template <unsigned bitNum, Polarity polarity=ActiveHigh>
using GpioC = Gpio<16+bitNum, polarity>;

template <unsigned bitNum, Polarity polarity=ActiveHigh>
using GpioD = Gpio<24+bitNum, polarity>;

template <unsigned bitNum, Polarity polarity=ActiveHigh>
using GpioE = Gpio<32+bitNum, polarity>;

template <unsigned bitNum, Polarity polarity=ActiveHigh>
using GpioF = Gpio<40+bitNum, polarity>;

template <unsigned bitNum, Polarity polarity=ActiveHigh>
using GpioG = Gpio<48+bitNum, polarity>;

template <unsigned bitNum, Polarity polarity=ActiveHigh>
using GpioH = Gpio<56+bitNum, polarity>;

} // namespace USBDM

#endif // HEADERS_GPIO_H

