/*
 * FlashProgrammer.h
 *
 *  Created on: 14 Mar 2015
 *      Author: podonoghue
 */

#ifndef _FLASHPROGRAMER_H_
#define _FLASHPROGRAMER_H_

#include <tr1/memory>

#include "Common.h"
#include "DeviceData.h"
#include "FlashImage.h"
#include "BdmInterface.h"

#if !defined(CPP_DLL_LOCAL)
   //! Functions exported from a library
   #define CPP_DLL_EXPORT __declspec(dllexport)
   //! Functions local to a library
   #define CPP_DLL_LOCAL // __attribute__ ((visibility ("hidden")))
   //! Functions imported from a library
   #define CPP_DLL_IMPORT __declspec(dllimport)
#endif

#if defined(COMPILE_FLASHPROGRAMMER_DLL)
   //! Create Library
#define USBDM_FLASHPROGRAMMER_DECLSPEC CPP_DLL_EXPORT
#elif defined(LINK_FLASHPROGRAMMER_DLL)
   //! Link to routines directly
#define USBDM_FLASHPROGRAMMER_DECLSPEC CPP_DLL_LOCAL
#else
   //! Link against Library
#define USBDM_FLASHPROGRAMMER_DECLSPEC CPP_DLL_IMPORT
#endif

class USBDM_FLASHPROGRAMMER_DECLSPEC FlashProgrammer {

public:
   enum FlashOperation {OpNone, OpSelectiveErase, OpBlockErase, OpBlankCheck, OpProgram, OpVerify, OpWriteRam, OpPartitionFlexNVM, OpTiming};

   typedef USBDM_ErrorCode (*CallBackT)(USBDM_ErrorCode status, int percent, const char *message);

   virtual ~FlashProgrammer() {}

   virtual USBDM_ErrorCode setDeviceData(const DeviceData &device) = 0;
   virtual DeviceData*     getDeviceData() = 0;
   virtual USBDM_ErrorCode setTargetInterface(BdmInterfacePtr bdmInterface) = 0;

   virtual USBDM_ErrorCode checkTargetUnSecured() = 0;
   virtual USBDM_ErrorCode massEraseTarget() = 0;
   virtual USBDM_ErrorCode programFlash(FlashImagePtr flashImage, CallBackT progressCallBack=NULL, bool doRamWrites=false) = 0;
   virtual USBDM_ErrorCode verifyFlash(FlashImagePtr flashImage, CallBackT progressCallBack=NULL) = 0;
   virtual USBDM_ErrorCode readTargetChipId(uint32_t *targetSDID) = 0;
   virtual USBDM_ErrorCode confirmSDID(void) = 0;
   virtual USBDM_ErrorCode getCalculatedTrimValue(uint16_t &value) = 0;
   virtual USBDM_ErrorCode resetAndConnectTarget(void) = 0;

protected:
   FlashProgrammer() {};
};

typedef std::tr1::shared_ptr<FlashProgrammer> FlashProgrammerPtr;

#endif // _FLASHPROGRAMER_H_
