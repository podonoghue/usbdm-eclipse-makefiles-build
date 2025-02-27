/**
 * @file     lpspi.h (180.ARM_Peripherals/Project_Headers/lpspi.h)
 * @brief    LPSPI interface
 */

#ifndef HEADER_LPSPI_H
#define HEADER_LPSPI_H

/*
 * *****************************
 * *** DO NOT EDIT THIS FILE ***
 * *****************************
 *
 * This file is generated automatically.
 * Any manual changes will be lost.
 */
#include <stdint.h>
#include "derivative.h"
#include "pin_mapping.h"
#ifdef __CMSIS_RTOS
#include "cmsis.h"
#endif

$(/LPSPI/prototypes:// $/LPSPI/prototypes not found)

namespace USBDM {

/**
 * @addtogroup LPSPI_Group LPSPI, Serial Peripheral Interface
 * @brief Abstraction for Serial Peripheral Interface
 * @{
 */
$(/LPSPI/peripheral_h_definition:// $/LPIT/peripheral_h_definition not found)
/**
 * Type definition for interrupt call back
 * @param status Interrupt status value from SPI->SR
 */
typedef void (*LpspiCallbackFunction)();

/**
 * Virtual Base class for LPSPI interface
 */
class Lpspi {

public:

protected:
   /** Callback to catch unhandled interrupt */
   static void unhandledCallback() {
      // Not considered an error as may be using polling
   }

   volatile LPSPI_Type  *lpspi;               //!< LPSPI hardware instance

   /**
    * Construct LPSPI interface
    *
    * @param[in]  lpspi     Base address of LPSPI hardware
    */
   Lpspi(volatile LPSPI_Type *lpspi) : lpspi(lpspi) {
   }

   /**
    * Destructor
    */
   ~Lpspi() {}
};

template<class Info> class LpspiBase_T : public Lpspi {

public:
   // Handle on LPSPI hardware
   static constexpr volatile LPSPI_Type *LPSPI = Info::lpspi;

   // LPSPI SCL (clock) Pin
   using sclGpio = GpioTable_T<Info, 0, USBDM::ActiveLow>; // Inactive is high

   // LPSPI SDA (data) Pin
   using sdaGpio = GpioTable_T<Info, 1, USBDM::ActiveHigh>;

   /** Used by ISR to obtain handle of object */
   static Lpspi *thisPtr;

   /** Callback function for ISR */
   static LpspiCallbackFunction sCallback;

public:
   $(/LPSPI/classInfo: // No class Info found)

   /**
    * Construct LPSPI interface
    *
    * @param[in]  bps        Tx/Rx rate
    */
   LpspiBase_T(unsigned bps=400000) : Lpspi(&Info::lpspi()) {
   }

   /**
    * Destructor
    */
   virtual ~LpspiBase_T() {}

   /**
    * Set channel Callback function\n
    * This callback is executed when the LPSPI state machine returns to the IDLE state
    * at the end of a transaction.
    *
    * @param[in] callback Callback function to execute on interrupt.\n
    *                     Use nullptr to remove callback.
    */
   static __attribute__((always_inline)) void setCallback(LpspiCallbackFunction callback) {
      static_assert(Info::irqHandlerInstalled, "LPSPI not configured for interrupts");
      if (callback == nullptr) {
         callback = Lpspi::unhandledCallback;
      }
      sCallback = callback;
   }

   static void irqHandler() {
      sCallback();
   }
};

template<class Info> LpspiCallbackFunction LpspiBase_T<Info>::sCallback = Lpspi::unhandledCallback;

/** Used by ISR to obtain handle of object */
template<class Info> Lpspi *LpspiBase_T<Info>::thisPtr = 0;

#if defined(USBDM_LPSPI0_IS_DEFINED)
/**
 * @brief Class representing the LPSPI0 interface
 *
 * <b>Example</b>\n
 * Refer @ref LpspiBase_T
 */
using Lpspi0 = LpspiBase_T<Lpspi0Info>;
$(/LPSPI0/Declarations:   // No declarations Found)
#endif

#if defined(USBDM_LPSPI1_IS_DEFINED)
/**
 * @brief Class representing the LPSPI1 interface
 *
 * <b>Example</b>
 * Refer @ref LpspiBase_T
 */
using Lpspi1 = LpspiBase_T<Lpspi1Info>;
$(/LPSPI1/Declarations:   // No declarations Found)
#endif

#if defined(USBDM_LPSPI2_IS_DEFINED)
/**
 * @brief Class representing the LPSPI2 interface
 *
 * <b>Example</b>
 * Refer @ref LpspiBase_T
 */
using Lpspi2 = LpspiBase_T<Lpspi2Info>;
$(/LPSPI2/Declarations:   // No declarations Found)
#endif

/**
 * End LPSPI_Group
 * @}
 */

} // End namespace USBDM

#endif /* HEADER_LPSPI_H */
