/**
 * @file    ftfl.h (180.ARM_Peripherals/Project_Headers/ftfl.h)
 * @brief   Flash support for FTFL
 *
 *  Created on: 21 Sep 2016
 *      Author: podonoghue
 */

#ifndef SOURCES_FLASH_H_
#define SOURCES_FLASH_H_

#include <assert.h>
#include "derivative.h"
#include "hardware.h"
#include "delay.h"

namespace USBDM {
/**
 * @addtogroup FLASH_Group FTFL, Flash interface
 * @brief Flash interface
 * @{
 */

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

/**
 * Class representing Flash interface
 */
class Flash : public FtflInfo {

protected:

   /** Minimum ratio for EEPROM to Flash backing storage */
   static constexpr unsigned MINIMUM_BACKING_RATIO = 16;

   /**
    * Constructor\n
    * Typically this method would be overridden in a derived class
    * to do the initialisation of the flash and non-volatile variables.
    * Alternatively, the startup code may call the static methods directly.
    */
   Flash() {
      static int singletonFlag __attribute__((unused)) = false;
      assert (!singletonFlag);
      singletonFlag = true;
      waitForFlashReady();
   }

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
    * @tparam eeprom     EEPROM Data Size choice
    * @tparam partition  FlexNVM Partition choice (defaults to all EEPROM backing store)
    * @tparam split      Split between A/B Flash portions (if supported by target)
    *
    * @return FLASH_ERR_OK         => EEPROM previous configured - no action required
    * @return FLASH_ERR_NEW_EEPROM => EEPROM has just been partitioned - contents are 0xFF, initialisation required
    *
    * @note This routine will only partition EEPROM when first executed after the device has been programmed.
    */
   template<EepromSel eeprom=eepromSel, PartitionSel partition=partitionSel, PartitionSplit split=partitionSplit>
   static FlashDriverError_t initialiseEeprom () {

   //   printf("initialiseEeprom(eeprom=%d bytes, eeprom backing=%ldK, residual flash=%ldK)\n",
   //         eepromSizes[eeprom].size, partitionInformation[partition].eeepromSize>>10, partitionInformation[partition].flashSize>>10);

      if (isFlexRamConfigured()) {
         return FLASH_ERR_OK;
      }
      if ((eepromSizes[eeprom].size*MINIMUM_BACKING_RATIO)>(partitionInformation[partition].eeepromSize)) {
//         printf("Backing ratio (Flash/EEPROM) is too small\n");
         USBDM::setErrorCode(E_FLASH_INIT_FAILED);
         return FLASH_ERR_ILLEGAL_PARAMS;
      }
   #if defined(RELEASE_BUILD)
      // EEPROM only available in release build
      FlashDriverError_t rc = partitionFlash(eepromSizes[eeprom].value|split, partitionInformation[partition].value);
      if (rc != 0) {
         //      printf("Partitioning Flash failed\n");
         return rc;
      }
      // Indicate EEPROM needs initialisation - this is not an error
      return FLASH_ERR_NEW_EEPROM;
   #else
      (void) eeprom;
      (void) partition;
      (void) split;

      // For debug, initialise FlexRam every time (no actual writes to flash)

      // Initialisation pretend EEPROM on every reset
      // This return code is not an error
      return FLASH_ERR_NEW_EEPROM;
   #endif
   }

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
      for(int timeout=0; timeout<100000; timeout++) {
         if ((FTFL->FSTAT&FTFL_FSTAT_CCIF_MASK) != 0) {
            return true;
         }
      }
      return false;
   }

private:
   /**
    * Program a phrase to Flash memory
    *
    * @param data       Location of data to program
    * @param address    Memory address to program - must be phrase boundary
    *
    * @return Error code
    */
   static FlashDriverError_t programPhrase(const uint8_t *data, uint8_t *address);

   /**
    * Erase sector of Flash memory
    *
    * @param address    Memory address to erase - must be sector boundary
    *
    * @return Error code
    */
   static FlashDriverError_t eraseSector(uint8_t *address);

public:
   /**
    * Program a range of bytes to Flash memory
    *
    * @param data       Location of data to program
    * @param address    Memory address to program - must be phrase boundary
    * @param size       Size of range (in bytes) to program - must be multiple of phrase size
    *
    * @return Error code
    */
   static FlashDriverError_t programRange(const uint8_t *data, uint8_t *address, uint32_t size);

   /**
    * Erase a range of Flash memory
    *
    * @param address    Memory address to start erasing - must be sector boundary
    * @param size       Size of range (in bytes) to erase - must be multiple of sector size
    *
    * @return Error code
    */
   static FlashDriverError_t eraseRange(uint8_t *address, uint32_t size);
   /**
    * Mass erase entire Flash memory
    */
   static void eraseAll();
};

/**
 * Class to wrap a scalar variable allocated within the FlexRam area\n
 * Size is limited to 1, 2 or 4 bytes.
 *
 * Writing to the variable triggers an EEPROM update.\n
 * Ensures updates are completed before return.
 *
 * @tparam T Scalar type for variable
 *
 * @note Instances should be placed in FlexRAM segment e.g.\n
 * @code
 * __attribute__ ((section(".flexRAM")))
 * USBDM::Nonvolatile<char> a_nonvolatile_char;
 * @endcode
 */
template <typename T>
class Nonvolatile {

   static_assert((sizeof(T) == 1)||(sizeof(T) == 2)||(sizeof(T) == 4), "T must be 1,2 or 4 bytes in size");

private:
   /**
    * Data value in FlexRAM
    *
    * FlexRAM required data to be aligned according to its size.\n
    * Be careful how you order variables otherwise space will be wasted
    */
   __attribute__ ((aligned (sizeof(T))))
   T data;

public:
   /**
    * Assign to underlying type\n
    * This adds a wait for the Flash to be updated
    *
    * @param data The data to assign
    */
   void operator=(const Nonvolatile &data ) {
      this->data = data;
      Flash::waitForFlashReady();
   }
   /**
    * Assign to underlying type\n
    * This adds a wait for the Flash to be updated
    *
    * @param data The data to assign
    */
   void operator=(const T &data ) {
      this->data = data;
      Flash::waitForFlashReady();
   }
   /**
    * Increment underlying type\n
    * This adds a wait for the Flash to be updated
    *
    * @param change The amount to increment
    */
   void operator+=(const Nonvolatile &change ) {
      this->data += change;
      Flash::waitForFlashReady();
   }
   /**
    * Increment underlying type\n
    * This adds a wait for the Flash to be updated
    *
    * @param change The amount to increment
    */
   void operator+=(const T &change ) {
      this->data += change;
      Flash::waitForFlashReady();
   }
   /**
    * Decrement underlying type\n
    * This adds a wait for the Flash to be updated
    *
    * @param change The amount to increment
    */
   void operator-=(const Nonvolatile &change ) {
      this->data -= change;
      Flash::waitForFlashReady();
   }
   /**
    * Decrement underlying type\n
    * This adds a wait for the Flash to be updated
    *
    * @param change The amount to increment
    */
   void operator-=(const T &change ) {
      this->data -= change;
      Flash::waitForFlashReady();
   }
   /**
    * Return the underlying object - read-only!
    */
   operator T() const {
      Flash::waitForFlashReady();
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
 *
 * @note Instances should be placed in FlexRAM segment e.g.\n
 * @code
 * __attribute__ ((section(".flexRAM")))
 * USBDM::NonvolatileArray<20, int> a_nonvolatile_array_of_ints;
 * @endcode
 */
template <typename T, int dimension>
class NonvolatileArray {

   static_assert((sizeof(T) == 1)||(sizeof(T) == 2)||(sizeof(T) == 4), "T must be 1, 2 or 4 bytes in size");

private:
   using TArray = T[dimension];
   using TPtr   = const T(*);

   /** Array of elements in FlexRAM
    *
    *  FlexRAM required data to be aligned according to its size.\n
    *  Be careful how you order variables otherwise space will be wasted
    */
   __attribute__ ((aligned (sizeof(T))))
   T data[dimension];

public:
   /**
    * Assign to underlying array
    *
    * @param other TArray to assign from
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
    * @param other NonvolatileArray to assign from
    *
    * This adds a wait for the Flash to be updated after each element is assigned
    */
   void operator=(const NonvolatileArray &other ) {
      for (int index=0; index<dimension; index++) {
         data[index] = other[index];
         Flash::waitForFlashReady();
      }
   }

   /**
    * Assign to underlying array
    *
    * @param other NonvolatileArray to assign to
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
    *
    * @param index Index of element to return
    *
    * @return Reference to underlying array
    */
   const T operator [](int index) {
      return data[index];
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
/**
 * @}
 */

} // namespace USBDM

#endif /* SOURCES_FLASH_H_ */
