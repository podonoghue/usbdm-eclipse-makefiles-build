/** \file
    \brief Header file for FlashProgrammer

    \verbatim
    Copyright (C) 2015  Peter O'Donoghue

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Change History
   +====================================================================
   |    May 2015 | Created
   +====================================================================
   \endverbatim
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

/**
 * Class representing interface for Flash Programmers
 */
class USBDM_FLASHPROGRAMMER_DECLSPEC FlashProgrammer {

public:
   /**
    * Different flash operations
    */
   enum FlashOperation {OpNone, OpSelectiveErase, OpBlockErase, OpBlankCheck, OpProgram, OpVerify, OpWriteRam, OpPartitionFlexNVM, OpTiming};

   /**
    * Callback from flash programmer
    */
   typedef USBDM_ErrorCode (*CallBackT)(USBDM_ErrorCode status, int percent, const char *message);

   virtual ~FlashProgrammer() {}

   /**
    * Set data for device being programmed
    *
    * @param device Device data
    *
    * @return error code
    */
   virtual USBDM_ErrorCode    setDeviceData(const DeviceDataConstPtr device) = 0;
   /**
    * Get data for current set device
    *
    * @return Pointer to device data
    */
   virtual DeviceDataConstPtr getDeviceData() = 0;
   /**
    * Set target interface to use
    *
    * @param bdmInterface BDM interface
    *
    * @return error code
    */
   virtual USBDM_ErrorCode    setTargetInterface(BdmInterfacePtr bdmInterface) = 0;
   /**
    * Check if target is unsecured
    *
    * @return error code
    */
   virtual USBDM_ErrorCode    checkTargetUnSecured() = 0;
   /**
    * Mass erase target
    *
    * @return error code
    */
   virtual USBDM_ErrorCode    massEraseTarget() = 0;
   /**
    * Mass erase target
    *
    * @return error code
    */
   virtual USBDM_ErrorCode    programFlash(FlashImagePtr flashImage, CallBackT progressCallBack=NULL, bool doRamWrites=false) = 0;
   /**
    * Mass erase target
    *
    * @return error code
    */
   virtual USBDM_ErrorCode    verifyFlash(FlashImagePtr flashImage, CallBackT progressCallBack=NULL) = 0;
   /**
    * Mass erase target
    *
    * @return error code
    */
   virtual USBDM_ErrorCode    readTargetChipId(uint32_t *targetSDID, bool doinit=false) = 0;
   /**
    * Confirms target SDID corresponds with target set
    *
    * @return error code
    */
   virtual USBDM_ErrorCode    confirmSDID(void) = 0;
   /**
    * Reset and connect to target
    *
    * @return error code
    */
   virtual USBDM_ErrorCode    resetAndConnectTarget(void) = 0;
   /**
    * Get calculates clock trim valueS
    *
    * @return trim value
    */
   virtual uint16_t           getCalculatedTrimValue() = 0;

protected:
   FlashProgrammer() {};
};

typedef std::tr1::shared_ptr<FlashProgrammer> FlashProgrammerPtr;

#endif // _FLASHPROGRAMER_H_
