/*
 * FlashProgrammer_ARM.h
 *
 *  Created on: 22 Mar 2015
 *      Author: podonoghue
 */

#ifndef SOURCE_FLASHPROGRAMMER_ARM_H_
#define SOURCE_FLASHPROGRAMMER_ARM_H_

#include <stdint.h>
#include <string>

#include "FlashProgrammerCommon.h"

class FlashProgrammer_ARM : public FlashProgrammerCommon {

public:
   FlashProgrammer_ARM();
   virtual ~FlashProgrammer_ARM();

   virtual ModuleInfo      &getModuleInfo() const override { return moduleInfo; }

protected:

   static ModuleInfo moduleInfo;

   //! Describes the flash programming code (created from loaded flash routines)
   struct TargetProgramInfo {
      uint32_t         entry;                   //!< Address of entry routine (for currently loaded routine)
      uint32_t         headerAddress;           //!< Address where to load data image (including header)
      uint32_t         dataOffset;              //!< Offset to data buffer within image
      uint32_t         maxDataSize;             //!< Maximum data buffer size
      uint32_t         capabilities;            //!< Capabilities of routine
      uint16_t         calibFrequency;          //!< Frequency (kHz) used for calibFactor
      uint32_t         calibFactor;             //!< Calibration factor for speed determination
      bool             smallProgram;            //!< Indicates small version of flash code being used
      bool             usePagedAddresses;       //!< Set up paged addressing information
      uint32_t         programOperation;        //!< either DO_PROGRAM_RANGE or DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE
   };

   //! Information for the flash operation to be done
   struct FlashOperationInfo {
      uint8_t          operation;               //!< Controls actions of routine
      uint32_t         controller;              //!< Address of flash controller
      uint32_t         pageAddress;             //!< Address of PPAGE or EPAGE register
      uint32_t         flashAddress;            //!< Memory flashAddress being programmed/erased (may include pageNo etc)
      uint32_t         dataSize;                //!< Size of data to program/verify
      uint16_t         sectorSize;              //!< Sector size
      uint32_t         targetBusFrequency;      //!< Measured target bus frequency (kHz)
      uint32_t         alignment;               //!< Flash programming alignment (1,2,4,8,16,32 bytes)
      uint32_t         flexNVMPartition;        //!< Value for partitioning FlexNVM
   };

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

   //! Structure for MCGCG parameters
   struct MK_MCG_ClockParameters_t {
      uint8_t  mcgC1;
      uint8_t  mcgC2;
      uint8_t  mcgC3;
      uint8_t  mcgTrim;
      uint8_t  mcgSC;
      uint8_t  mcgCT;
   } ;
   union ClockParameters {
      MK_MCG_ClockParameters_t mcg;
   } ;

   bool                    initTargetDone;               //!< Indicates initTarget() has been done.
   TargetProgramInfo       targetProgramInfo;            //!< Describes loaded flash code
   FlashOperationInfo      flashOperationInfo;           //!< Describes flash operation

   FlashOperation          currentFlashOperation;        //!< Current operation loaded
   uint32_t                currentFlashAlignment;        //!< Alignment applicable to flash operation
   bool                    doRamWrites;                  //!< Write RAM region of image to target (after programming)
   bool                    securityNeedsSelectiveErase;  //!< Indicates security area needs to be selectively erased

   USBDM_ErrorCode initialiseTargetFlash();
   USBDM_ErrorCode initialiseTarget();
   USBDM_ErrorCode setFlashSecurity(FlashImagePtr flashImage, MemoryRegionConstPtr flashRegion);
   USBDM_ErrorCode setFlashSecurity(FlashImagePtr flashImage);
   USBDM_ErrorCode setFlashChecksum(FlashImagePtr flashImage, MemoryRegionConstPtr flashRegion);
   USBDM_ErrorCode setFlashChecksum(FlashImagePtr flashImage);
   USBDM_ErrorCode trimTargetClock(uint32_t trimAddress, unsigned long  targetBusFrequency, uint16_t *returnTrimValue,
                                   unsigned long *measuredBusFrequency, int do9BitTrim) {
      UsbdmSystem::Log::error("Clock trimming not supported\n");
      return  PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   USBDM_ErrorCode trimMCG_Clock(MK_MCG_ClockParameters_t *clockParameters);
   USBDM_ErrorCode configureMCG_Clock(unsigned long *busFrequency, MK_MCG_ClockParameters_t *clockParameters);
   USBDM_ErrorCode configureTargetClock(unsigned long *busFrequency)  {
      UsbdmSystem::Log::error("Clock configuration not supported\n");
      return  PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   USBDM_ErrorCode configureExternal_Clock(unsigned long *busFrequency)  {
      UsbdmSystem::Log::error("Clock configuration not supported\n");
      return  PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   USBDM_ErrorCode dummyTrimLocations(FlashImagePtr flashImage)  {
      UsbdmSystem::Log::error("Clock trimming not supported\n");
      return  PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   };
   USBDM_ErrorCode eraseFlash(void);
   USBDM_ErrorCode convertTargetErrorCode(FlashDriverError_t rc);
   USBDM_ErrorCode initSmallTargetBuffer(uint8_t *buffer);
   USBDM_ErrorCode initLargeTargetBuffer(uint8_t *buffer);
   USBDM_ErrorCode executeTargetProgram(uint8_t *buffer=0, uint32_t size=0);
   USBDM_ErrorCode determineTargetSpeed(void);
   USBDM_ErrorCode doFlashBlock(FlashImagePtr flashImage, unsigned int blockSize, uint32_t &flashAddress, FlashOperation flashOperation);
   USBDM_ErrorCode selectiveEraseFlashSecurity(void);
   USBDM_ErrorCode doTargetVerify(FlashImagePtr flashImage);
   USBDM_ErrorCode doReadbackVerify(FlashImagePtr flashImage);
   USBDM_ErrorCode doImageCheck(FlashImagePtr flashImage);
   USBDM_ErrorCode applyFlashOperation(FlashImagePtr flashImage, FlashOperation flashOperation);
   USBDM_ErrorCode doVerify(FlashImagePtr flashImage);
   USBDM_ErrorCode doSelectiveErase(FlashImagePtr flashImage);
   USBDM_ErrorCode doProgram(FlashImagePtr flashImage);
   USBDM_ErrorCode doBlankCheck(FlashImagePtr flashImage);
   USBDM_ErrorCode doWriteRam(FlashImagePtr flashImage);
   USBDM_ErrorCode loadTargetProgram(FlashOperation flashOperation);
   USBDM_ErrorCode loadTargetProgram(MemoryRegionConstPtr memoryRegionPtr, FlashOperation flashOperation);
   USBDM_ErrorCode loadTargetProgram(FlashProgramConstPtr flashProgram, FlashOperation flashOperation);
   USBDM_ErrorCode loadSmallTargetProgram(uint8_t *buffer, uint32_t loadAddress, uint32_t size,
         FlashProgramConstPtr flashProgram, FlashOperation flashOperation);
   USBDM_ErrorCode loadLargeTargetProgram(uint8_t *buffer, uint32_t loadAddress, uint32_t size,
         FlashProgramConstPtr flashProgram, FlashOperation flashOperation);
   USBDM_ErrorCode partitionFlexNVM(void);

public:
   static const char *getProgramActionNames(unsigned int actions);
   static const char *getProgramCapabilityNames(unsigned int actions);

   virtual USBDM_ErrorCode checkTargetUnSecured() override;
   virtual USBDM_ErrorCode massEraseTarget(bool resetTarget) override;
   virtual USBDM_ErrorCode programFlash(FlashImagePtr flashImage, CallBackT progressCallBack=0, bool doRamWrites=false) override;
   virtual USBDM_ErrorCode verifyFlash(FlashImagePtr flashImage, CallBackT progressCallBack=0) override;
   virtual USBDM_ErrorCode readTargetChipId(uint32_t *targetSDID, bool doinit=false) override;
   virtual USBDM_ErrorCode confirmSDID(void) override;
   virtual USBDM_ErrorCode resetAndConnectTarget(void) override;
};

#endif /* SOURCE_FLASHPROGRAMMER_ARM_H_ */
