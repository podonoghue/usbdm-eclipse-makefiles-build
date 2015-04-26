/*! \file
    \brief Header file for USBDM_DSC_API.c

    \verbatim
    Copyright (C) 2010  Peter O'Donoghue

    Based on material from OSBDM-JM60 Target Interface Software Package
    Copyright (C) 2009  Freescale

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
   |    May 2010 | Created
   +====================================================================
    \endverbatim
 */
#ifndef USBDM_DSC_API_H_
#define USBDM_DSC_API_H_

#include <stdint.h>

//==================================================
#if defined __cplusplus
#define EXTERN_C  extern "C"
#else
#define EXTERN_C
#endif

#if defined(_WIN32) && !defined (WINAPI)
   #define WINAPI __attribute__((__stdcall__))
#endif

#if defined(_WIN32) && !defined(DLL_LOCAL)
   // Functions exported from a library
   #define DLL_EXPORT WINAPI __declspec(dllexport)

   // Functions imported from a library
   #define DLL_IMPORT WINAPI __declspec(dllimport)

   // Functions local to a library
   #define DLL_LOCAL
#endif

#if !defined(DLL_LOCAL)
   // Functions exported from a library
   #define DLL_EXPORT __attribute__ ((visibility ("default")))
   // Functions imported from a library
   #define DLL_IMPORT __attribute__ ((visibility ("default")))

   // Functions local to a library
   #define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#endif

#ifdef USBDMDSC_DLL_EXPORTS
   //! These definitions are used when USBDM_DSC_API is being exported (creating DLL)
   #define USBDM_DSC_API      EXTERN_C DLL_EXPORT
#else
   //! These definitions are used when USBDM_DSC_API is being imported (linking against DLL)
   #define USBDM_DSC_API      EXTERN_C DLL_IMPORT
#endif
//==================================================

#if defined __cplusplus
extern "C" {
#endif

typedef enum {
   executeMode,
   stopMode,
   externalAccessMode,
   debugMode,
   unknownMode,
} OnceStatus_t;

typedef struct {
   unsigned size;                //! Size of this structure
   unsigned maxMemoryWriteSize;  //!< Maximum bytes for DSC_WriteMemory()
   unsigned maxMemoryReadSize;   //!< Maximum bytes for DSC_ReadMemory()
} dscInfo_t ;

//! Obtain information about the interface
//!
//! @param dscInfo structure to populate
//!
//! @note the size entry in info must be set before the call
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_GetInfo(dscInfo_t *dscInfo);

//! Initialises DSC Interface
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_Initialise(void);

//! Obtain size of given register in bits
//!
//! @param regNo - The register number
//!
//! @return - size of the register in bits
//!
unsigned getRegisterSize(DSC_Registers_t regNo);

//! Converts OnceStatus_t to a string for debug
//!
#if 1//defined (USBDMDSC_DLL_EXPORTS) // !defined(TARGET) || (TARGET != MC56F80xx)
USBDM_DSC_API
#endif
const char *DSC_GetOnceStatusName(OnceStatus_t status);

//! Converts EONCE Status register value to a string for debug
//!
const char *DSC_GetOSCRText(uint32_t value);

#define TARGET_STATUS_EXECUTE   (0x01)
#define TARGET_STATUS_STOP      (0x05)
#define TARGET_STATUS_EX_ACCESS (0x09)
#define TARGET_STATUS_DEBUG     (0x0D)

//! Enable ONCE in JTAG chain & Obtain status
//!
//! @param status - Target status from JTAG command
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_GetStatus(OnceStatus_t *status);

//! Connect to target
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_GetIdcode(uint32_t *idcode);

//! Connect to target
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_Connect(void);

//! Reset Target
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_TargetReset(TargetMode_t targetMode);

//! Start Target execution at current PC
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_TargetGo(void);

//! Execute 1 instruction from current PC
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_TargetStep(void);

//! Execute N instruction from current PC
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_TargetStepN(unsigned n);

//! Halts target execution
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_TargetHalt(void);

//================================================================================
//! Read X/P memory via ONCE & target execution
//!
//! @param memorySpace - Memory space & size of memory accesses 1/2/4 bytes
//! @param byteCount   - Number of bytes to read (must be a multiple of elementSize)
//! @param address     - Memory address
//! @param data        - Where to obtain the data
//!
//! @note If memory space size is word or long size then address is DSC word address
//! @note If memory space size is byte size then address is DSC byte pointer address
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_ReadMemory(unsigned int  memorySpace,
                               unsigned int  byteCount,
                               unsigned int  address,
                               unsigned char *data);

//================================================================================
//! Write X/P memory via ONCE & target execution
//!
//! @param memorySpace - Memory space & size of memory accesses 1/2/4 bytes
//! @param byteCount   - Number of bytes to read (must be a multiple of elementSize)
//! @param address     - Memory address
//! @param data        - Where to obtain the data
//!
//! @note If memory space size is word or long size then address is DSC word address
//! @note If memory space size is byte size then address is DSC byte pointer address
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_WriteMemory(unsigned int         memorySpace,
                                unsigned int         byteCount,
                                unsigned int         address,
                                const unsigned char *data);

//! Read Register
//!
//! @param regNo     - Register number
//! @param regValue  - Value from register
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_ReadRegister(unsigned int regNo, unsigned long *regValue);

//! Write Register
//!
//! @param regNo     - Register number
//! @param regValue  - Value for register
//!
//! @note Assumes Core TAP is active & in RUN-TEST/IDLE
//! @note Leaves Core TAP in RUN-TEST/IDLE
//!
USBDM_DSC_API
USBDM_ErrorCode DSC_WriteRegister(unsigned int regNo, unsigned long regValue);

//! Set log file for messages
//!
USBDM_DSC_API
void DSC_SetLogFile(FILE *fp);

//! Get current log file for messages
//!
USBDM_DSC_API
FILE *DSC_GetLogFile(void);

#if defined __cplusplus
}
#endif

#endif /* USBDM_DSC_API_H_ */
