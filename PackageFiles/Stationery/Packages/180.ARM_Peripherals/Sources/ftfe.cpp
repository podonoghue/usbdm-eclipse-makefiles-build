/**
 * @file    ftfe.cpp (180.ARM_Peripherals/Sources/ftfe.cpp)
 * @brief   Flash support code
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 */
#include <string.h>

#include "system.h"
#include "derivative.h"
#include "ftfe.h"

namespace USBDM {

// Flash commands
//static constexpr uint8_t  F_RD1BLK      =  0x00;
//static constexpr uint8_t  F_RD1SEC      =  0x01;
//static constexpr uint8_t  F_PGMCHK      =  0x02;
static constexpr uint8_t  F_RDRSRC      =  0x03;
static constexpr uint8_t  F_PGM8        =  0x07;
//static constexpr uint8_t  F_ERSBLK      =  0x08;
static constexpr uint8_t  F_ERSSCR      =  0x09;
//static constexpr uint8_t  F_PGMSEC      =  0x0B;
//static constexpr uint8_t  F_RD1ALL      =  0x40;
//static constexpr uint8_t  F_RDONCE      =  0x41;
//static constexpr uint8_t  F_PGMONCE     =  0x43;
static constexpr uint8_t  F_ERSALL      =  0x44;
//static constexpr uint8_t  F_VFYKEY      =  0x45;
static constexpr uint8_t  F_PGMPART     =  0x80;
//static constexpr uint8_t  F_SETRAM      =  0x81;

/** A23 == 0 => indicates PROGRAM flash */
//static constexpr uint32_t PROGRAM_ADDRESS_FLAG = (0<<23);

/** A23 == 1 => indicates DATA flash */
static constexpr uint32_t DATA_ADDRESS_FLAG    = (1<<23);

__attribute__((section(".ram_functions")))
__attribute__((long_call))
__attribute__((noinline))
/**
 * Launch & wait for Flash command to complete
 *
 * @note This routine is executed from RAM
 */
void Flash::executeFlashCommand_ram() {
   // Clear error flags
   flashController->FSTAT = FTFE_FSTAT_RDCOLERR_MASK|FTFE_FSTAT_ACCERR_MASK|FTFE_FSTAT_FPVIOL_MASK;
   // Start command
   flashController->FSTAT = FTFE_FSTAT_CCIF_MASK;
   do {
   } while ((flashController->FSTAT & FTFE_FSTAT_CCIF_MASK) == 0);
}

/**
 * Launch & wait for Flash command to complete
 */
FlashDriverError_t Flash::executeFlashCommand() {

   if (!isFlashAvailable()) {
      return FLASH_ERR_NOT_AVAILABLE;
   }

   {
      CriticalSection cs;
      executeFlashCommand_ram();
   }
   // Handle any errors
   uint8_t status = flashController->FSTAT;
   if ((status & FTFE_FSTAT_FPVIOL_MASK ) != 0) {
      return FLASH_ERR_PROG_FPVIOL;
   }
   if ((status & FTFE_FSTAT_ACCERR_MASK ) != 0) {
      return FLASH_ERR_PROG_ACCERR;
   }
   if ((status & FTFE_FSTAT_MGSTAT0_MASK ) != 0) {
      return FLASH_ERR_PROG_MGSTAT0;
   }
   if ((status & FTFE_FSTAT_RDCOLERR_MASK ) != 0) {
      return FLASH_ERR_PROG_RDCOLERR;
   }
   return FLASH_ERR_OK;
}

/**
 * Read Flash Resource (IFR etc).
 * This command reads 4 bytes from the selected flash resource
 *
 * @param[in]  resourceSelectCode 00 => IFR, 01 => Version ID
 * @param[in]  address            Address in IFR etc, A23=0 => Program flash, A23=1 => Data flash
 * @param[out] data               Buffer for data returned
 *
 * @return Error code, 0 => no error
 */
FlashDriverError_t Flash::readFlashResource(uint8_t resourceSelectCode, uint32_t address, uint8_t *data) {
   flashController->FCCOB0 = F_RDRSRC;
   flashController->FCCOB1 = address>>16;
   flashController->FCCOB2 = address>>8;
   flashController->FCCOB3 = address;
   flashController->FCCOB8 = resourceSelectCode;
   FlashDriverError_t rc = executeFlashCommand();
   if (rc != FLASH_ERR_OK) {
      return rc;
   }
   data[0] = flashController->FCCOB4;
   data[1] = flashController->FCCOB5;
   data[2] = flashController->FCCOB6;
   data[3] = flashController->FCCOB7;

   return FLASH_ERR_OK;
}

/**
 * Program EEPROM Data Size Code and FlexNVM Partition Code
 *
 * See device reference manual for the meaning of the following parameters
 *
 * @param[in]  eeprom     EEPROM Data Size value
 * @param[in]  partition  FlexNVM Partition value
 *
 * @return Error code, 0 => no error
 */
FlashDriverError_t Flash::partitionFlash(uint8_t eeprom, uint8_t partition) {
   flashController->FCCOB0 = F_PGMPART;
   flashController->FCCOB1 = 0x00;
   flashController->FCCOB2 = 0x00;
   flashController->FCCOB3 = 0x00;
   flashController->FCCOB4 = eeprom;
   flashController->FCCOB5 = partition;
   FlashDriverError_t rc = executeFlashCommand();
   if (rc != FLASH_ERR_OK) {
      USBDM::setErrorCode(E_FLASH_INIT_FAILED);
   }
   return rc;
}

/**
 * Program phrase to Flash memory
 *
 * @param[in]  data       Location of data to program
 * @param[out] address    Memory address to program - must be phrase boundary
 *
 * @return Error code
 */
FlashDriverError_t Flash::programPhrase(const uint8_t *data, uint8_t *address) {
   flashController->FCCOB0 = F_PGM8;
   flashController->FCCOB1 = (uint8_t)(((uint32_t)address)>>16);
   flashController->FCCOB2 = (uint8_t)(((uint32_t)address)>>8);
   flashController->FCCOB3 = (uint8_t)(((uint32_t)address));
   flashController->FCCOB7 = *data++;
   flashController->FCCOB6 = *data++;
   flashController->FCCOB5 = *data++;
   flashController->FCCOB4 = *data++;
   flashController->FCCOBB = *data++;
   flashController->FCCOBA = *data++;
   flashController->FCCOB9 = *data++;
   flashController->FCCOB8 = *data++;
   return executeFlashCommand();
}

/**
 * Program a range of bytes to Flash memory
 *
 * @param[in]  data       Location of data to program
 * @param[out] address    Memory address to program - must be phrase boundary
 * @param[in]  size       Size of range (in bytes) to program - must be multiple of phrase size
 *
 * @return Error code
 */
FlashDriverError_t Flash::programRange(const uint8_t *data, uint8_t *address, uint32_t size) {
   unsigned phraseSize;
   if ((uint32_t)address >= 0x10000000) {
      // DFLASH
      address = (uint8_t*)((uint32_t)address | DATA_ADDRESS_FLAG);
      phraseSize = dataFlashPhraseSize;
   }
   else {
      // PFLASH
      phraseSize = programFlashPhraseSize;
   }
   usbdm_assert((((uint32_t)address)&(phraseSize-1)) == 0, "Address not on Flash boundary");
   usbdm_assert((size&(phraseSize-1)) == 0, "Size is not multiple of Flash phrase size");

   while (size>0) {
      FlashDriverError_t rc = programPhrase(data, address);
      if (rc != FLASH_ERR_OK) {
         return rc;
      }
      data    += phraseSize;
      address += phraseSize;
      size    -= phraseSize;
   }
   return FLASH_ERR_OK;
}

/**
 * Erase sector of Flash memory.
 *
 * @param[in]  address    Memory address to erase - must be sector boundary
 *
 * @return Error code
 */
FlashDriverError_t Flash::eraseSector(uint8_t *address) {
   flashController->FCCOB0 = F_ERSSCR;
   flashController->FCCOB1 = (uint8_t)(((uint32_t)address)>>16);
   flashController->FCCOB2 = (uint8_t)(((uint32_t)address)>>8);
   flashController->FCCOB3 = (uint8_t)(((uint32_t)address));
   return executeFlashCommand();
}

/**
 * Erase a range of Flash memory.
 *
 * @param[in]  address    Memory address to start erasing - must be sector boundary
 * @param[in]  size       Size of range (in bytes) to erase - must be multiple of sector size
 *
 * @return Error code
 */
FlashDriverError_t Flash::eraseRange(uint8_t *address, uint32_t size) {
   unsigned sectorSize;
   if ((uint32_t)address >= 0x10000000) {
      // DFLASH
      address = (uint8_t*)((uint32_t)address | DATA_ADDRESS_FLAG);
      sectorSize = dataFlashSectorSize;
   }
   else {
      // PFLASH
      sectorSize = programFlashSectorSize;
   }
   usbdm_assert((((uint32_t)address)&(sectorSize-1)) == 0, "Address not on Flash boundary");
   usbdm_assert((size&(sectorSize-1)) == 0, "Size is not multiple of Flash phrase size");

   while (size>0) {
      FlashDriverError_t rc = eraseSector(address);
      if (rc != FLASH_ERR_OK) {
         return rc;
      }
      address += sectorSize;
      size    -= sectorSize;
   }
   return FLASH_ERR_OK;
}

/**
 * Mass erase entire Flash memory
 */
void Flash::eraseAll() {
   flashController->FCCOB0 = F_ERSALL;
   FlashDriverError_t rc = executeFlashCommand();
   (void)rc;
   // Don't expect it to get here as flash is erased!!!!
   for(;;) {
      __asm__("nop");
   }
}

}
