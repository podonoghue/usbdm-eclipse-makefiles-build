/**
 * @file    ftfa.cpp (180.ARM_Peripherals/Sources/ftfa.cpp)
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
#include "ftfa.h"

namespace USBDM {

// Flash commands
//static constexpr uint8_t  F_RD1BLK      =  0x00;
//static constexpr uint8_t  F_RD1SEC      =  0x01;
//static constexpr uint8_t  F_PGMCHK      =  0x02;
static constexpr uint8_t  F_RDRSRC      =  0x03;
static constexpr uint8_t  F_PGM4        =  0x06;
//static constexpr uint8_t  F_ERSBLK      =  0x08;
static constexpr uint8_t  F_ERSSCR      =  0x09;
//static constexpr uint8_t  F_PGMSEC      =  0x0B;
//static constexpr uint8_t  F_RD1ALL      =  0x40;
//static constexpr uint8_t  F_RDONCE      =  0x41;
//static constexpr uint8_t  F_PGMONCE     =  0x43;
static constexpr uint8_t  F_ERSALL      =  0x44;
//static constexpr uint8_t  F_VFYKEY      =  0x45;
//static constexpr uint8_t  F_PGMPART     =  0x80;
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
         "    .equ   FTFA_FSTAT,0x40020000        \n"
         "    .equ   FTFA_FSTAT_ERROR_MASK,0x70   \n" // = FTFA_FSTAT_RDCOLERR_MASK|FTFA_FSTAT_ACCERR_MASK|FTFA_FSTAT_FPVIOL_MASK
         "    .equ   FTFA_FSTAT_CCIF_MASK,0x80    \n"

         "     ldr   r1,=FTFA_FSTAT               \n" // Point R1 @FTFA_FSTAT

         "     movs  r2,#FTFA_FSTAT_ERROR_MASK    \n" // Clear previous errors
         "     strb  r2,[r1,#0]                   \n" // FTFA_FSTAT = FTFA_FSTAT_ERROR_MASK

         "     movs  r2,#FTFA_FSTAT_CCIF_MASK     \n" // Start command
         "     strb  r2,[r1,#0]                   \n" // FTFA_FSTAT = FTFA_FSTAT_CCIF_MASK

         "loop:                                   \n"
         "     ldrb  r3,[r1,#0]                   \n" // Wait for completion
#if (__CORTEX_M == 4)
         "     ands  r3,r2                        \n" // while ((FTFA->FSTAT & FTFA_FSTAT_CCIF_MASK) == 0) {
#else
         "     and   r3,r2                        \n" // while ((FTFA->FSTAT & FTFA_FSTAT_CCIF_MASK) == 0) {
#endif
         "     beq   loop                         \n" // }

         ::: "r1", "r2", "r3"
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
   if ((FTFA->FSTAT & FTFA_FSTAT_FPVIOL_MASK ) != 0) {
      return FLASH_ERR_PROG_FPVIOL;
   }
   if ((FTFA->FSTAT & FTFA_FSTAT_ACCERR_MASK ) != 0) {
      return FLASH_ERR_PROG_ACCERR;
   }
   if ((FTFA->FSTAT & FTFA_FSTAT_MGSTAT0_MASK ) != 0) {
      return FLASH_ERR_PROG_MGSTAT0;
   }
   if ((FTFA->FSTAT & FTFA_FSTAT_RDCOLERR_MASK ) != 0) {
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
   FTFA->FCCOB0 = F_RDRSRC;
   FTFA->FCCOB1 = address>>16;
   FTFA->FCCOB2 = address>>8;
   FTFA->FCCOB3 = address;
   FTFA->FCCOB8 = resourceSelectCode;
   FlashDriverError_t rc = executeFlashCommand();
   if (rc != FLASH_ERR_OK) {
      return rc;
   }
   data[0] = FTFA->FCCOB4;
   data[1] = FTFA->FCCOB5;
   data[2] = FTFA->FCCOB6;
   data[3] = FTFA->FCCOB7;

   return FLASH_ERR_OK;
}

/**
 * Program phrase to Flash memory
 *
 * @param data       Location of data to program
 * @param address    Memory address to program - must be phrase boundary
 *
 * @return Error code
 */
FlashDriverError_t Flash::programPhrase(const uint8_t *data, uint8_t *address) {
   FTFA->FCCOB0 = F_PGM4;
   FTFA->FCCOB1 = (uint8_t)(((uint32_t)address)>>16);
   FTFA->FCCOB2 = (uint8_t)(((uint32_t)address)>>8);
   FTFA->FCCOB3 = (uint8_t)(((uint32_t)address));
   FTFA->FCCOB7 = *data++;
   FTFA->FCCOB6 = *data++;
   FTFA->FCCOB5 = *data++;
   FTFA->FCCOB4 = *data++;
   FlashDriverError_t rc = executeFlashCommand();
   return rc;
}

/**
 * Program a range of bytes to Flash memory
 *
 * @param data       Location of data to program
 * @param address    Memory address to program - must be phrase boundary
 * @param size       Size of range (in bytes) to program - must be multiple of phrase size
 *
 * @return Error code
 */
FlashDriverError_t Flash::programRange(const uint8_t *data, uint8_t *address, uint32_t size) {
   assert((((uint32_t)address)&(programFlashPhraseSize-1)) == 0);
   assert((size&(programFlashPhraseSize-1)) == 0);

   while (size>0) {
      FlashDriverError_t rc = programPhrase(data, address);
      if (rc != FLASH_ERR_OK) {
         return rc;
      }
      data    += programFlashPhraseSize;
      address += programFlashPhraseSize;
      size    -= programFlashPhraseSize;
   }
   return FLASH_ERR_OK;
}

/**
 * Erase sector in Flash memory
 *
 * @param address    Memory address to erase - must be phrase boundary
 *
 * @return Error code
 */
FlashDriverError_t Flash::eraseSector(uint8_t *address) {
   FTFA->FCCOB0 = F_ERSSCR;
   FTFA->FCCOB1 = (uint8_t)(((uint32_t)address)>>16);
   FTFA->FCCOB2 = (uint8_t)(((uint32_t)address)>>8);
   FTFA->FCCOB3 = (uint8_t)(((uint32_t)address));
   FlashDriverError_t rc = executeFlashCommand();
   return rc;
}

/**
 * Program a range of bytes to Flash memory
 *
 * @param address    Memory address to start erasing - must be sector boundary
 * @param size       Size of range (in bytes) to erase - must be multiple of sector size
 *
 * @return Error code
 */
FlashDriverError_t Flash::eraseRange(uint8_t *address, uint32_t size) {
   assert((((uint32_t)address)&(programFlashSectorSize-1)) == 0);
   assert((size&(programFlashSectorSize-1)) == 0);

   while (size>0) {
      FlashDriverError_t rc = eraseSector(address);
      if (rc != FLASH_ERR_OK) {
         return rc;
      }
      address += programFlashSectorSize;
      size    -= programFlashSectorSize;
   }
   return FLASH_ERR_OK;
}

/**
 * Mass erase entire Flash memory
 */
void Flash::eraseAll() {
   FTFA->FCCOB0 = F_ERSALL;
   FlashDriverError_t rc = executeFlashCommand();
   (void)rc;
   // Don't expect it to get here as flash is erased!!!!
   for(;;) {
      __asm__("nop");
   }
}

}
