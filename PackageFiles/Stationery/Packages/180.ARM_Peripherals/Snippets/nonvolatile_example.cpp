/*
 ============================================================================
 * @file    nonvolatile_example.cpp (180.ARM_Peripherals)
 * @brief   Basic C++ demo of non-volatile (flexRAM) template class
 *
 * This example shows how to create a non-volatile variable located in the
 * FlexRAM region of memory and backed by non-volatile storage in the Flash.
 * The variable counts the number of times the chip has been (power-on) reset.
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
 *  Created on: 10/1/2016
 *      Author: podonoghue
 ============================================================================
 */
#include <stdio.h>
#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "delay.h"
#include "flash.h"

/** Non-volatile variable to count how many times the device has booted */
__attribute__ ((section(".flexRAM")))
USBDM::Nonvolatile<int> bootCount_nv;

/**
 * A class similar to this should be created to do the following:
 * - Configure and partition the flash on the first reset after programming the device.
 * - Do once-only initialisation of non-volatile variables when the above occurs.
 * - Initialise the FlexRAM from the Flash backing store
 */
class NvInit : public USBDM::Flash {
public:
   NvInit() : Flash() {
      // Initialise the non-volatile system and configure if necessary
      volatile int rc = initialiseEeprom();
      if (rc == USBDM::FLASH_ERR_NEW_EEPROM) {
         // This is the first reset after programming the device
         // Initialise the non-volatile variables as necessary
         // If not initialised they will have an initial value of 0xFF
         bootCount_nv = 0;
      }
      else if (rc != USBDM::FLASH_ERR_OK) {
         // You can trap errors here or check in main
         printf("FlexNVM initialisation error");
         __BKPT();
      }
   }
};

int main() {
   // Initialise non-volatile storage
   NvInit nvinit;

#ifdef RCM_SRS0_POR_MASK
   if ((RCM->SRS0 & RCM_SRS0_POR_MASK) != 0) {
      // Only count power-on resets
      bootCount_nv = bootCount_nv + 1;
   }
#else
   // Count all resets if SRS not available
   bootCount_nv = bootCount_nv + 1;
#endif

   printf("Starting, boot count = %d\n", (int)bootCount_nv);
   for(;;) {
   }
   return 0;
}
