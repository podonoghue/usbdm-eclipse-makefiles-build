/**
 ============================================================================
 * @file    nonvolatile-example.cpp  (180.ARM_Peripherals/Snippets/)
 * @brief   Basic C++ demo of non-volatile (flexRAM) template class
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
/*
 * This example shows how to create a non-volatile variable located in the
 * FlexRAM region of memory and backed by non-volatile storage in the Flash.
 * The variable counts the number of times the chip has been power-on-reset.
 *
 * Note:
 * If run from a debug launch then the non-volatile memory will not
 * actually be used.  The FlexRAM will be treated as simple RAM, initialised
 * as if this was the first boot after programming.
 * This is done to prevent wear to the flash when debugging
 *
 * Only Release versions of the software will actually use non-volatile storage
 * and operate correctly i.e. the FlexRAM will be backed by Flash storage
 *
 */
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "delay.h"
#include "flash.h"
#ifdef USBDM_RCM_IS_DEFINED
#include "rcm.h"
#endif
using namespace USBDM;

/**
 * Non-volatile variable to count how many times the device has booted.
 * This must be placed in FlexRAM section.
 */
__attribute__ ((section(".flexRAM")))
Nonvolatile<int> bootCount_nv;

/**
 * A derived class similar to this should be created to do the following:
 * - Wait for initialisation of the FlexRAM from the Flash backing store - Flash();
 * - Configure and partition the flash on the first reset after programming the device - initialiseEeprom().
 * - Do once-only initialisation of non-volatile variables when the above occurs.
 */
class NvInit : public Flash {
public:
   NvInit() : Flash() {

      // Initialise the non-volatile system and configure if necessary
      volatile FlashDriverError_t rc = initialiseEeprom<EepromSel_2KBytes, PartitionSel_flash0K_eeprom32K, SplitSel_disabled>();

      if (rc == FLASH_ERR_NEW_EEPROM) {
         // This is the first reset after programming the device
         // Initialise the non-volatile variables as necessary
         // If not initialised they will have an initial value of 0xFF
         bootCount_nv = 0;
         console.writeln("Initialising NV variables");
      }
      else {
         usbdm_assert(rc != FLASH_ERR_OK, "FlexNVM initialisation error");
         console.writeln("Not initialising NV variables");
      }
   }
};

int main() {
   // Initialise non-volatile storage
   NvInit nvinit;

#ifdef USBDM_RCM_IS_DEFINED
   // Only count power-on resets
   if ((Rcm::getResetSource() & RcmSource_Por) != 0) {
      bootCount_nv = bootCount_nv + 1;
      console.write("Starting, power-on boot count = ").writeln((int)bootCount_nv);
   }
#else
   // Count all resets if RCM is not available
   bootCount_nv = bootCount_nv + 1;
   console.write("Starting, boot count = ").writeln((int)bootCount_nv);
#endif

   for(;;) {
   }
   return 0;
}
