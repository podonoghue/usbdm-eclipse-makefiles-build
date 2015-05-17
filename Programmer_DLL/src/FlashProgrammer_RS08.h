/*
 * FlashProgrammer_HCS08.h
 *
 *  Created on: 22 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_FLASHPROGRAMMER_RS08_H_
#define SRC_FLASHPROGRAMMER_RS08_H_

#include <stdint.h>
#include <string>

#include "FlashProgrammerCommon.h"

class USBDM_FLASHPROGRAMMER_DECLSPEC FlashProgrammer_RS08 : public FlashProgrammerCommon {

public:
   FlashProgrammer_RS08();
   virtual ~FlashProgrammer_RS08();

protected:
   // Error codes return from the flash driver
   enum FlashDriverError_t {
        FLASH_ERR_OK                = (0),  //!< No error
        FLASH_ERR_LOCKED            = (1),  //!< Flash is still locked
        FLASH_ERR_ILLEGAL_PARAMS    = (2),  //!< Parameters illegal
        FLASH_ERR_PROG_FAILED       = (3),  //!< STM - Programming operation failed - general
        FLASH_ERR_PROG_WPROT        = (4),  //!< STM - Programming operation failed - write protected
        FLASH_ERR_VERIFY_FAILED     = (5),  //!< Verify failed
        FLASH_ERR_ERASE_FAILED      = (6),  //!< Erase or Blank Check failed
        FLASH_ERR_TRAP              = (7),  //!< Program trapped (illegal instruction/location etc.)
        FLASH_ERR_PROG_ACCERR       = (8),  //!< Kinetis/CFVx - Programming operation failed - ACCERR
        FLASH_ERR_PROG_FPVIOL       = (9),  //!< Kinetis/CFVx - Programming operation failed - FPVIOL
        FLASH_ERR_PROG_MGSTAT0      = (10), //!< Kinetis - Programming operation failed - MGSTAT0
        FLASH_ERR_CLKDIV            = (11), //!< CFVx - Clock divider not set
        FLASH_ERR_ILLEGAL_SECURITY  = (12), //!< Kinetis - Illegal value for security location
        FLASH_ERR_UNKNOWN           = (13), //!< Unspecified error
        FLASH_ERR_TIMEOUT           = (14), //!< Timeout waiting for completion
   };

   enum AddressModifiers {
      ADDRESS_DATA   = 1UL<<31,  //!< DATA (X:) memory (DSC)
      ADDRESS_LINEAR = 1UL<<31,  //!< Linear address (HCS12)
      ADDRESS_EEPROM = 1UL<<30,  //!< EEPROM
      ADDRESS_A23    = 1UL<<23,  //!< A23 bit for Flex/DataFlash on ARM/CFV1+
   };

   bool                    initTargetDone;               //!< Indicates initTarget() has been done.
   MemoryRegionConstPtr    flashMemoryRegionPtr;
   uint32_t                targetBusFrequency;           //! kHz
   bool                    doRamWrites;                  //!< Write RAM region of image to target (after programming)
   bool                    securityNeedsSelectiveErase;  //!< Indicates security area needs to be selectively erased

   USBDM_ErrorCode initialiseTargetFlash();
   USBDM_ErrorCode initialiseTarget();
   void            deleteSecurityAreas(void);
   USBDM_ErrorCode recordSecurityArea(const uint32_t address, const int size, const uint8_t *data);
   void            restoreSecurityAreas(FlashImagePtr flashImage);
   USBDM_ErrorCode setFlashSecurity(FlashImagePtr flashImage, MemoryRegionConstPtr flashRegion);
   USBDM_ErrorCode setFlashSecurity(FlashImagePtr flashImage);
   USBDM_ErrorCode blankCheckTarget();
   USBDM_ErrorCode blindUnsecure();
   USBDM_ErrorCode doFlashCommand(uint8_t command);
   USBDM_ErrorCode calculateFlashDelay(uint8_t *delayValue);
   USBDM_ErrorCode writeFlashBlock( unsigned int byteCount, unsigned int address, unsigned const char *data, uint8_t delayValue);
   USBDM_ErrorCode programBlock(FlashImagePtr flashImageDescription, unsigned int blockSize, uint32_t flashAddress);
   USBDM_ErrorCode doReadbackVerify(FlashImagePtr flashImage);
   USBDM_ErrorCode doVerify(FlashImagePtr flashImage);
   USBDM_ErrorCode blankCheckBlock(FlashImagePtr flashImageDescription, unsigned int blockSize, unsigned int flashAddress);
   void 		   RS08_doFixups(uint8_t buffer[]);
   USBDM_ErrorCode loadAndStartExecutingTargetProgram();
   USBDM_ErrorCode setPPAGE(uint32_t address);
   USBDM_ErrorCode dummyTrimLocations(FlashImagePtr flashImageDescription);
   USBDM_ErrorCode bulkEraseMemoryRegion(MemoryRegionPtr memoryRegion);

public:
   USBDM_ErrorCode setDeviceData(const DeviceData &theParameters);
   DeviceData*     getDeviceData() { return &parameters; }
   USBDM_ErrorCode checkTargetUnSecured();
   USBDM_ErrorCode massEraseTarget();
   USBDM_ErrorCode programFlash(FlashImagePtr flashImage, CallBackT progressCallBack=0, bool doRamWrites=false);
   USBDM_ErrorCode verifyFlash(FlashImagePtr flashImage, CallBackT progressCallBack=0);
   USBDM_ErrorCode readTargetChipId(uint32_t *targetSDID);
   USBDM_ErrorCode confirmSDID(void);

   USBDM_ErrorCode getCalculatedTrimValue(uint16_t &value) {
      value = parameters.getClockTrimValue();
      return PROGRAMMING_RC_OK;
   }
   USBDM_ErrorCode resetAndConnectTarget(void);
};

#endif // SRC_FLASHPROGRAMMER_RS08_H_
