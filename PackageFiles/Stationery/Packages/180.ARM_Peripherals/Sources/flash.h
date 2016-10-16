/*
 * flexRam.h
 *
 *  Created on: 21 Sep 2016
 *      Author: podonoghue
 */

#ifndef SOURCES_FLASH_H_
#define SOURCES_FLASH_H_

#include <assert.h>
#include "derivative.h"
#include "delay.h"

namespace USBDM {

// Error codes
typedef enum {
   FLASH_ERR_OK                = (0),
   FLASH_ERR_LOCKED            = (1),  // Flash is still locked
   FLASH_ERR_ILLEGAL_PARAMS    = (2),  // Parameters illegal
   FLASH_ERR_PROG_FAILED       = (3),  // STM - Programming operation failed - general
   FLASH_ERR_PROG_WPROT        = (4),  // STM - Programming operation failed - write protected
   FLASH_ERR_VERIFY_FAILED     = (5),  // Verify failed
   FLASH_ERR_ERASE_FAILED      = (6),  // Erase or Blank Check failed
   FLASH_ERR_TRAP              = (7),  // Program trapped (illegal instruction/location etc.)
   FLASH_ERR_PROG_ACCERR       = (8),  // Kinetis/CFVx - Programming operation failed - ACCERR
   FLASH_ERR_PROG_FPVIOL       = (9),  // Kinetis/CFVx - Programming operation failed - FPVIOL
   FLASH_ERR_PROG_MGSTAT0      = (10), // Kinetis - Programming operation failed - MGSTAT0
   FLASH_ERR_CLKDIV            = (11), // CFVx - Clock divider not set
   FLASH_ERR_ILLEGAL_SECURITY  = (12), // Kinetis/CFV1+ - Illegal value for security location
   FLASH_ERR_UNKNOWN           = (13), // Unspecified error
   FLASH_ERR_PROG_RDCOLERR     = (14), // Read Collision
   FLASH_ERR_NEW_EEPROM        = (15), // Indicates EEPROM has just bee partitioned and need initialisation
} FlashDriverError_t;

class Flash {

protected:

   /**
    * Constructor\n
    * Typically this method would be overridden in a derived class
    * to do the initialisation of the flash and non-volatile variables.
    * Alternatively, the startup code may call the static methods directly.
    */
   Flash() {
      static int singletonFlag = false;
      assert (!singletonFlag);
      singletonFlag = true;
   }

   /** Selects EEPROM size */
   enum EepromSel {
      eeprom32Bytes,
      eeprom64Bytes,
      eeprom128Bytes,
      eeprom256Bytes,
      eeprom512Bytes,
      eeprom1KBytes,
      eeprom2KBytes,
   };

   //#define KINETIS_32K_FLEXRAM
#define KINETIS_64K_FLEXRAM

#if defined(KINETIS_32K_FLEXRAM)
   /** Selects division of FlexNVM between flash and EEPROM backing storage */
   enum PartitionSel {
      partition_flash32K_eeprom0K,
      partition_flash24K_eeprom8K,
      partition_flash16K_eeprom16K,
      partition_flash8K_eeprom24K,
      partition_flash0K_eeprom32K,
      partition_flash0K_eeprom_all = partition_flash0K_eeprom32K,
   };
   /** Selects division two regions of EEPROM (if supported on device) */
   enum PartitionSplit {
      partition_default=0x30, //! Single partition
   };
#elif defined(KINETIS_64K_FLEXRAM)
   /** Selects division of FlexNVM between flash and EEPROM backing storage */
   enum PartitionSel {
      partition_flash64K_eeprom0K,
      partition_flash32K_eeprom32K,
      partition_flash0K_eeprom64K,
      partition_flash0K_eeprom_all = partition_flash0K_eeprom64K,
   };
   /** Selects division two regions of EEPROM (if supported on device) */
   enum PartitionSplit {
      partition_A1_B7 = 0x00,             //! A=1/8, B=7/8
      partition_A2_B6 = 0x10,             //! A=2/8=1/4, B=6/8=3/4
      partition_A4_B4 = 0x30,             //! A=4/8=1/2, B=4/8=1/2
      partition_A1_B3 = partition_A2_B6,  //! A=2/8=1/4, B=6/8=3/4
      partition_A1_B1 = partition_A4_B4,  //! A=2/8=1/4, B=6/8=3/4
      partition_default=partition_A4_B4,  //! Equal partitions
   };
#endif

   /**
    * Launch & wait for Flash command to complete
    */
   static void executeFlashCommand_asm();

   /**
    * Launch & wait for Flash command to complete
    */
   static FlashDriverError_t executeFlashCommand();

   /**
    * Read Flash Resource (IFR etc)
    * This command reads 4 bytes from the selected flash resource
    *
    * @param resourceSelectCode 00 => IFR, 01 => Version ID
    * @param address            Address in IFR etc, A23=0 => Program flash, A23=1 => Data flash
    * @param data               Buffer for data returned
    *
    * @return Error code, 0 => no error
    */
   static FlashDriverError_t readFlashResource(uint8_t resourceSelectCode, uint32_t address, uint8_t *data);

   /**
    * Program EEPROM Data Size Code and FlexNVM Partition Code
    *
    * See device reference manual for the meaning of the following parameters
    *
    * @param eeprom     EEPROM Data Size value
    * @param partition  FlexNVM Partition value
    *
    * @return Error code, 0 => no error
    */
   static FlashDriverError_t partitionFlash(uint8_t eeprom, uint8_t partition);

   /**
    * Initialise the EEPROM
    *
    * This function should be called before the first access to variables located in the eeprom.
    *
    * @param eeprom     EEPROM Data Size choice
    * @param partition  FlexNVM Partition choice (defaults to all EEPROM backing store)
    * @param split      Split between A/B Flash portions (if supported by target)
    *
    * @return
    *       FLASH_ERR_OK         => EEPROM previous configured - no action required\n
    *       FLASH_ERR_NEW_EEPROM => EEPROM has just been partitioned - contents are 0xFF, initialisation required\n
    *
    * @note This routine will only partition EEPROM when first executed after the device has been programmed.
    */
   static FlashDriverError_t initialiseEeprom(EepromSel eeprom, PartitionSel partition=partition_flash0K_eeprom_all, PartitionSplit split=partition_default);

public:

   /**
    * Checks if the flexRAM has been configured\n
    * Will wait for flash ready as necessary
    *
    * @return true if configured
    */
   static bool isFlexRamConfigured() {

      return waitForFlashReady() && (FTFL->FCNFG&FTFL_FCNFG_EEERDY_MASK);

      //   printf("FTFL->FCNFG = 0x%02X\n", FTFL->FCNFG);
      //   printf("FTFL->FCNFG.FTFL_FCNFG_RAMRDY = %s\n", FTFL->FCNFG&FTFL_FCNFG_RAMRDY_MASK?"true":"false");
      //   printf("FTFL->FCNFG.FTFL_FCNFG_EEERDY = %s\n", FTFL->FCNFG&FTFL_FCNFG_EEERDY_MASK?"true":"false");

      //   uint8_t result[4];
      //   FlashDriverError_t rc = readFlashResource(0, DATA_ADDRESS_FLAG|0xFC, result);
      //   if (rc != 0) {
      ////      printf("IFR read failed, rc=%d\n", rc);
      //      return false;
      //   }
      //   uint8_t flexNvmPartitionSize = result[0];
      //   uint8_t eepromDatSetSize     = result[1];

      //   printf("FlexNVM partition code = 0x%02X\n", flexNvmPartitionSize);
      //   printf("EEPROM data set size   = 0x%02X\n", eepromDatSetSize);

      //      return (FTFL->FCNFG&FTFL_FCNFG_EEERDY_MASK);
   }

   /**
    * Wait until flash is ready.\n
    * Any flash operations will have completed.
    *
    * @return true => OK, false => timeout
    */
   static bool waitForFlashReady() {
      static auto func = [] () { return (FTFL->FSTAT&FTFL_FSTAT_CCIF_MASK) != 0; };
      if (func()) {
         // Common case - avoid overhead of timeout code
         return true;
      }
      // Wait for flash ready
      // Wait for a maximum of 2000 ms
      return USBDM::waitMS(2000, func);
   }

};
/**
 * Class to wrap a scalar variable allocated within the FlexRam area\n
 * Size is limited to 1, 2 or 4 bytes.
 *
 * Writing to the variable triggers an EEPROM update.\n
 * Ensures updates are completed before return.
 *
 * @tparam T Scalar type for variable
 */
template <typename T>
class Nonvolatile {

   static_assert((sizeof(T) == 1)||(sizeof(T) == 2)||(sizeof(T) == 4), "T must be 1,2 or 4 bytes in size");

private:
   /** Data value in FlexRAM */
   T data;

public:
   /**
    * Assign to underlying type
    *
    * This adds a wait for the Flash to be updated
    */
   void operator=(const T &data ) {
      this->data = data;
      Flash::waitForFlashReady();
   }
   /**
    * Assign to underlying type
    *
    * This adds a wait for the Flash to be updated
    */
   void operator+=(const T &incr ) {
      this->data += incr;
      Flash::waitForFlashReady();
   }
   /**
    * Assign to underlying type
    *
    * This adds a wait for the Flash to be updated
    */
   void operator-=(const T &incr ) {
      this->data -= incr;
      Flash::waitForFlashReady();
   }
   /**
    * Return the underlying object - read-only!
    */
   operator T() const {
      return data;
   }
};

/**
 * Class to wrap an array of scalar variables allocated to the FlexRam area
 *
 * Element size is limited to 1, 2 or 4 bytes.
 *
 * Writing to an element triggers an EEPROM update.\n
 * Ensures updates are completed before return.
 *
 * @tparam T         Scalar type for element
 * @tparam dimension Dimension of array
 */
template <typename T, int dimension>
class NonvolatileArray {

   static_assert((sizeof(T) == 1)||(sizeof(T) == 2)||(sizeof(T) == 4), "T must be 1,2 or 4 bytes in size");

private:
   using TArray = const T[dimension];
   using TPtr   = const T(*);

   /** Array of elements in FlexRAM */
   T data[dimension];

public:
   /**
    * Assign to underlying array
    *
    * This adds a wait for the Flash to be updated after each element is assigned
    */
   void operator=(const TArray &other ) {
      for (int index=0; index<dimension; index++) {
         data[index] = other[index];
         Flash::waitForFlashReady();
      }
   }

   /**
    * Assign to underlying array
    *
    * This adds a wait for the Flash to be updated after each element is assigned
    */
   void copyTo(T *other) const {
      for (int index=0; index<dimension; index++) {
         other[index] = data[index];
      }
   }

   /**
    * Return a reference to the underlying array element - read-only!
    */
   const T operator [](int i) {
      return data[i];
   }

   /**
    * Return a pointer to the underlying array - read-only!
    */
   operator TPtr() const {
      return data;
   }

   /**
    * Set an element of the array to the value provided
    *
    * @param index Array index of element to change
    * @param value Value to initialise array elements to
    */
   void set(int index, T value) {
      data[index] = value;
      Flash::waitForFlashReady();
   }
   /**
    * Set all elements of the array to the value provided
    *
    * @param value Value to initialise array elements to
    */
   void set(T value) {
      for (int index=0; index<dimension; index++) {
         data[index] = value;
         Flash::waitForFlashReady();
      }
   }
};

} // namespace USBDM

#endif /* SOURCES_FLASH_H_ */
