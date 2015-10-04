/**
 * @file     gpio_defs.h (from gpio_defs-MKE.h)
 * @brief    GPIO Pin routines
 *
 * @version  V4.11.1.70
 * @date     18 June 2015
 */
#ifndef HEADER_GPIO_DEFS_H
#define HEADER_GPIO_DEFS_H

#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

// Inline port functions
//   <q> Force inline port functions
//   <i> This option forces some small GPIO functions to be inlined
//   <i> This increases speed but may also increase code size
//     <0=> Disabled
//     <1=> Enabled
#define DO_INLINE   0

#if DO_INLINE != 0
#define OPTIONAL_INLINE __attribute__((always_inline))
#else
#define OPTIONAL_INLINE
#endif

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
   volatile GPIO_Type    *gpio;       //!< Pointer to hardware registers
   const    uint32_t      bitMask;    //!< Bit-mask to use when manipulating individual bit

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
   void setDigitalOutput() const  {
      gpio->PDDR |= bitMask;
   }
   /**
    * Set pin as digital input
    *
    * @param pcrValue PCR value to use in configuring port
    */
   void setDigitalInput() const  {
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
 * @}
 */

#endif /* HEADER_GPIO_DEFS_H */
