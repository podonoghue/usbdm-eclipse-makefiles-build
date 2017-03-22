/**
 * @file    flash.cpp
 * @brief   Flash support code
 *
 *  Created on: 10/1/2016
 *      Author: podonoghue
 */
#include <stdio.h>
#include <string.h>

#include "system.h"
#include "derivative.h"
#include "hardware.h"
#include "delay.h"

#include "Flash.h"

namespace USBDM {

// Flash commands
//static constexpr uint8_t  F_RD1BLK      =  0x00;
//static constexpr uint8_t  F_RD1SEC      =  0x01;
//static constexpr uint8_t  F_PGMCHK      =  0x02;
static constexpr uint8_t  F_RDRSRC      =  0x03;
//static constexpr uint8_t  F_PGM4        =  0x06;
//static constexpr uint8_t  F_ERSBLK      =  0x08;
//static constexpr uint8_t  F_ERSSCR      =  0x09;
//static constexpr uint8_t  F_PGMSEC      =  0x0B;
//static constexpr uint8_t  F_RD1ALL      =  0x40;
//static constexpr uint8_t  F_RDONCE      =  0x41;
//static constexpr uint8_t  F_PGMONCE     =  0x43;
//static constexpr uint8_t  F_ERSALL      =  0x44;
//static constexpr uint8_t  F_VFYKEY      =  0x45;
static constexpr uint8_t  F_PGMPART     =  0x80;
//static constexpr uint8_t  F_SETRAM      =  0x81;

/** A23 == 0 => indicates PROGRAM flash */
//static constexpr uint32_t PROGRAM_ADDRESS_FLAG = (0<<23);

/** A23 == 1 => indicates DATA flash */
//static constexpr uint32_t DATA_ADDRESS_FLAG    = (1<<23);

/**
 * Launch & wait for Flash command to complete
 *
 * @note This routine is copied to the stack (RAM) for execution
 */
void Flash::executeFlashCommand_asm() {
   __asm__ volatile (
         "    .equ   FTFL_FSTAT,0x40020000        \n"
         "    .equ   FTFL_FSTAT_ERROR_MASK,0x70   \n" // = FTFL_FSTAT_RDCOLERR_MASK|FTFL_FSTAT_ACCERR_MASK|FTFL_FSTAT_FPVIOL_MASK
         "    .equ   FTFL_FSTAT_CCIF_MASK,0x80    \n"

         "     movw  r1,#FTFL_FSTAT&0xFFFF        \n" // Point R1 @FTFL_FSTAT
         "     movt  r1,#FTFL_FSTAT/65536         \n"

         "     movw  r2,#FTFL_FSTAT_ERROR_MASK    \n" // Clear previous errors
         "     strb  r2,[r1,#0]                   \n" // FTFL_FSTAT = FTFL_FSTAT_ERROR_MASK

         "     movw  r2,#FTFL_FSTAT_CCIF_MASK     \n" // Start command
         "     strb  r2,[r1,#0]                   \n" // FTFL_FSTAT = FTFL_FSTAT_CCIF_MASK

         "loop:                                   \n"
         "     ldrb  r2,[r1,#0]                   \n" // Wait for completion
         "     ands  r2,r2,#FTFL_FSTAT_CCIF_MASK  \n" // while ((FTFL->FSTAT & FTFL_FSTAT_CCIF_MASK) == 0) {
         "     beq   loop                         \n" // }

         ::: "r1", "r2"
   );
}

/**
 * Launch & wait for Flash command to complete
 *
 * @note This routine must be placed in ROM immediately following executeFlashCommand_asm()
 */
FlashDriverError_t Flash::executeFlashCommand() {
   uint8_t space[50]; // Space for RAM copy of executeFlashCommand_asm()
   FlashDriverError_t (*fp)() = (FlashDriverError_t (*)())((uint32_t)space|1);

   volatile uint32_t source     = (uint32_t)executeFlashCommand_asm&~1;
   volatile uint32_t source_end = (uint32_t)executeFlashCommand&~1;
   volatile uint32_t size       = source_end-source;

   assert(size<sizeof(space));

   // Copy routine to RAM (stack)
   memcpy(space, (uint8_t*)(source), size);

   // Call executeFlashCommand_asm() on the stack with interrupts disabled
   disableInterrupts();
   (*fp)();
   enableInterrupts();

   // Handle any errors
   if ((FTFL->FSTAT & FTFL_FSTAT_FPVIOL_MASK ) != 0) {
      return FLASH_ERR_PROG_FPVIOL;
   }
   if ((FTFL->FSTAT & FTFL_FSTAT_ACCERR_MASK ) != 0) {
      return FLASH_ERR_PROG_ACCERR;
   }
   if ((FTFL->FSTAT & FTFL_FSTAT_MGSTAT0_MASK ) != 0) {
      return FLASH_ERR_PROG_MGSTAT0;
   }
   if ((FTFL->FSTAT & FTFL_FSTAT_RDCOLERR_MASK ) != 0) {
      return FLASH_ERR_PROG_RDCOLERR;
   }
   return FLASH_ERR_OK;
}

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
FlashDriverError_t Flash::readFlashResource(uint8_t resourceSelectCode, uint32_t address, uint8_t *data) {
   FTFL->FCCOB0 = F_RDRSRC;
   FTFL->FCCOB1 = address>>16;
   FTFL->FCCOB2 = address>>8;
   FTFL->FCCOB3 = address;
   FTFL->FCCOB8 = resourceSelectCode;
   FlashDriverError_t rc = executeFlashCommand();
   if (rc != FLASH_ERR_OK) {
      return rc;
   }
   data[0] = FTFL->FCCOB4;
   data[1] = FTFL->FCCOB5;
   data[2] = FTFL->FCCOB6;
   data[3] = FTFL->FCCOB7;

   return FLASH_ERR_OK;
}

struct EepromSizes {
   const uint16_t size;    // EEPROM size
   const uint8_t  value;   // Value to select size
};

static const EepromSizes eepromSizes[] = {
      // Size  Value
      {  32,   0x09, },
      {  64,   0x08, },
      {  128,  0x07, },
      {  256,  0x06, },
      {  512,  0x05, },
      {  1024, 0x04, },
      {  2048, 0x03, },
      {  4096, 0x02, }, // Only for 64K FlexNVM devices
};

struct PartitionInformation {
   const uint32_t flashSize;     //! Remaining data flash
   const uint32_t eeepromSize;   //! Flash allocated to EEPROM backing store
   const uint8_t  value;         //! Partition value
};

#if defined(KINETIS_32K_FLEXRAM)
static const PartitionInformation partitionInformation[] {
      // Flash   Backing   Value
      { 32*1024, 0*1024 ,  0xFF},
      { 24*1024, 8*1024 ,  0x01},
      { 16*1024, 16*1024,  0x0A},
      { 8*1024,  24*1024,  0x09},
      { 0*1024,  32*1024,  0x08},
};
#elif defined(KINETIS_64K_FLEXRAM)
static const PartitionInformation partitionInformation[] {
      // Flash   Backing   Value
      { 64*1024, 0*1024 ,  0xFF},
      { 32*1024, 32*1024 , 0x09},
      { 0*1024,  64*1024,  0x08},
};
#endif

/** Minimum ratio for EEPROM to Flash backing storage */
constexpr unsigned MINIMUM_BACKING_RATIO = 16;

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
FlashDriverError_t Flash::partitionFlash(uint8_t eeprom, uint8_t partition) {
   FTFL->FCCOB0 = F_PGMPART;
   FTFL->FCCOB1 = 0x00;
   FTFL->FCCOB2 = 0x00;
   FTFL->FCCOB3 = 0x00;
   FTFL->FCCOB4 = eeprom;
   FTFL->FCCOB5 = partition;
   FlashDriverError_t rc = executeFlashCommand();
   if (rc != FLASH_ERR_OK) {
      USBDM::setErrorCode(E_FLASH_INIT_FAILED);
   }
   return rc;
}

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
FlashDriverError_t Flash::initialiseEeprom(EepromSel eeprom, PartitionSel partition, PartitionSplit split) {
//   printf("initialiseEeprom(eeprom=%d bytes, eeprom backing=%ldK, residual flash=%ldK)\n",
//         eepromSizes[eeprom].size, partitionInformation[partition].eeepromSize>>10, partitionInformation[partition].flashSize>>10);
   if (isFlexRamConfigured()) {
      return FLASH_ERR_OK;
   }
   if ((eepromSizes[eeprom].size*MINIMUM_BACKING_RATIO)>(partitionInformation[partition].eeepromSize)) {
      printf("Backing ratio (Flash/EEPROM) is too small\n");
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
   // For debug initialise FlexRam every time (no actual writes to flash)
   (void) eeprom;
   (void) partition;
   (void) split;
   // Indicate pretend EEPROM needs initialisation - this is not an error
   return FLASH_ERR_NEW_EEPROM;
#endif
}

}
