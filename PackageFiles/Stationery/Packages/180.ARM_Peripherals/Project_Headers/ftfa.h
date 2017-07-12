/**
 * @file    ftfa.h (180.ARM_Peripherals/Project_Headers/ftfa.h)
 * @brief   Flash support for FTFA
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
 * @addtogroup FTFA_Group FTFA, Flash Memory Module
 * @brief Abstraction for Flash Memory Module
 * @{
 */

// Error codes
enum FlashDriverError_t {
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
};

/**
 * Class representing Flash interface
 */
class Flash : public FtfaInfo {

protected:

   /**
    * Constructor
    */
   Flash() {
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
    * @param[in]  resourceSelectCode 00 => IFR, 01 => Version ID
    * @param[in]  address            Address in IFR etc, A23=0 => Program flash, A23=1 => Data flash
    * @param[out] data               Buffer for data returned
    *
    * @return Error code, 0 => no error
    */
   static FlashDriverError_t readFlashResource(uint8_t resourceSelectCode, uint32_t address, uint8_t *data);

public:

   /**
    * Wait until flash is ready.\n
    * Any flash operations will have completed.
    *
    * @return true => OK, false => timeout
    */
   static bool waitForFlashReady() {
      for(int timeout=0; timeout<100000; timeout++) {
         if ((FTFA->FSTAT&FTFA_FSTAT_CCIF_MASK) != 0) {
            return true;
         }
      }
      return false;
   }

private:
   /**
    * Program a phrase to Flash memory
    *
    * @param[in]  data       Location of data to program
    * @param[out] address    Memory address to program - must be phrase boundary
    *
    * @return Error code
    */
   static FlashDriverError_t programPhrase(const uint8_t *data, uint8_t *address);

   /**
    * Erase sector of Flash memory
    *
    * @param[in]  address    Memory address to erase - must be sector boundary
    *
    * @return Error code
    */
   static FlashDriverError_t eraseSector(uint8_t *address);

public:
   /**
    * Program a range of bytes to Flash memory
    *
    * @param[in]  data       Location of data to program
    * @param[out] address    Memory address to program - must be phrase boundary
    * @param[in]  size       Size of range (in bytes) to program - must be multiple of phrase size
    *
    * @return Error code
    */
   static FlashDriverError_t programRange(const uint8_t *data, uint8_t *address, uint32_t size);

   /**
    * Erase a range of Flash memory
    *
    * @param[out] address    Memory address to start erasing - must be sector boundary
    * @param[in]  size       Size of range (in bytes) to erase - must be multiple of sector size
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
 * @}
 */

} // namespace USBDM

#endif /* SOURCES_FLASH_H_ */
