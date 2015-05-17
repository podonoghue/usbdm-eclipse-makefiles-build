/*! \file
   \brief Entry points for USBDM library

   \verbatim
   USBDM interface library
   Copyright (C) 2008  Peter O'Donoghue

   Based on
      Opensource BDM  - interface library

   which is based on
      TBDML interface library by
      Copyright (C) 2005  Daniel Malik

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
\endverbatim

\verbatim
 Change History
+======================================================================================================
| 10 Mar 2015 | Added initilisatin checks                                           - pgo V4.10.6.260
| 10 Feb 2015 | Logging changes                                                     - pgo V4.10.6.260
| 20 Jan 2015 | Added USBDM_SetLogFile() and USBDM_GetLogFile()                     - pgo V4.10.6.250
|  1 Dec 2014 | Fixed format in printf()s                                           - pgo V4.10.6.230
| 12 Nov 2014 | Added armDisconnect() to allow reset behaviour to be restored       - pgo V4.10.6.230
| 12 Nov 2014 | Refactored armConnect()                                             - pgo V4.10.6.230
| 12 Oct 2014 | Added automatic alignment correction to memory (FIX_ALIGNMENT)      - pgo V4.10.6.210
| 25 Apr 2014 | Added check for Power sense option in Power-on sequence             - pgo V4.10.6.140
| 23 Mar 2014 | Changes to handling pendingResetRelease                             - pgo V4.10.6.130
| 01 Mar 2014 | Removed MCF51AC256 CSR.VBD hack                                     - pgo V4.10.6.120
| 16 Mar 2013 | Added default frequency to getDefaultExtendedOptions()              - pgo V4.10.4
| 27 Dec 2012 | Added Reset rise checks to reset code                               - pgo V4.10.4
|  1 Dec 2012 | Changed Logg                                                        - pgo V4.10.4
| 30 Nov 2012 | Extended timeout for USBDM_ControlPins()                            - pgo V4.10.4
| 30 Oct 2012 | Added MS_Fast report                                                - pgo V4.10.4
| 17 Oct 2012 | USBDM_SetTarget() now only does POR if actual TVdd change and       - pgo V4.10.3
|             |   leaves RESET asserted for ARM targets until end of Connect()      -
| 23 Sep 2012 | USBDM_ControlInterface() now filters value by target type           - pgo V4.10.2
| 17 Sep 2012 | USBDM_GetVersion() check for invalid ICP.HW version                 - pgo V4.10.1
|  7 Aug 2012 | USBDM_ControlInterface() now uses USBDM_ControlPins()               - pgo V4.10.0
| 20 May 2012 | Extended firmware version information                                     V4.9.5
| 16 May 2012 | Corrected possible buffer overrun in USBDM_JTAG_ExecuteSequence()   - pgo V4.9.5
|  4 May 2012 | Unified error code handling                                         - pgo V4.9.5
|  4 Apr 2012 | Added RESET_DEFAULT option to targetReset()                         - pgo V4.9.4
| 27 Mar 2012 | Implemented USBDM_SetExtendedOptions() etc                          - pgo V4.9.4
| 30 Jan 2012 | Changes to USBDM_Read/WriteMemory() for HCS12 Global access         - pgo V4.9
| 26 Jan 2012 | Changes to USBDM_SetSpeed() to pass 0 speed to BDM                  - pgo V4.9
| 10 Dec 2011 | Changed so VDD not enabled unless target type set first             - pgo V4.8
| 12 Jul 2011 | Added call to USBDM_SetSpeed() for CFVx USBDM_SetTargetType()       - pgo
| 07 Jul 2011 | Changes to reset & connection for all targets                       - pgo
| 24 Nov 2010 | Fixed stupid non-static static buffers!                             - pgo
| 24 Sep 2010 | Moved useOnlyEp0 code to updateBdmInfo()                            - pgo
|    Jul 2010 | Extensive changed for V4                                            - pgo
| 21 May 2010 | Cleaned up some undefined behaviour for zero size JTAG ops          - pgo
| 16 Apr 2010 | Change RS08 flash handling for V3 USBDMithConfig()                  - pgo
| 17 Feb 2010 | Added check for T_OFF in SetTargetTypeWithConfig()                  - pgo
|  1 Aug 2009 | Change to USBDM + wrappers for TBDML, OSBDM & TBLCF                 - pgo
|  1 Jan 2009 | Changed to common file for TBDML, OSBDM & TBLCF dlls                - pgo
| 27 Dec 2008 | Added extendedConnect() to target_sync()                            - pgo
+======================================================================================================
\endverbatim
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "UsbdmSystem.h"
#include "Version.h"
#include "Common.h"
#include "USBDM_API.h"
#include "USBDM_API_Private.h"
#include "low_level_usb.h"
#include "Names.h"
#include "TargetDefines.h"
#include "armInterface.h"

#ifdef WIN32
#include "ICP.h"
#include <windows.h>
#endif

#define FIX_ALIGNMENT  // Enable autofix for alignment on readMemory() & writeMemory()

#define JTAG_HEADER_SIZE (5) // Number of bytes to reserved for BDM header in JTAG Commands

//! Internal state USBDM library
static const BDMState_t defaultBDMState = {
      false,           // initialised;          - Indicates if the library has been initialised
      false,           // powerCycleRetryAbort; - Disable connection retries
      true,            // useOnlyEp0;           - JB16 BDM only use EP0
      T_OFF,           // targetType;           - Target connected to BDM
      BDM_INACTIVE};   // activityFlag;         - Indicates the BDM has been asked to do something interesting
CPP_DLL_LOCAL
BDMState_t bdmState = defaultBDMState;

//! Structure describing characteristics of currently open BDM
static const USBDM_bdmInformation_t defaultBdmInfo =
                   {sizeof(USBDM_bdmInformation_t), 0, 0, 0, 0, BDM_CAP_NONE, 100, 100};
CPP_DLL_LOCAL
USBDM_bdmInformation_t bdmInfo = defaultBdmInfo;

CPP_DLL_LOCAL
bool bdmInfoValid = false;

CPP_DLL_LOCAL
bool pendingResetRelease = false;

//! Options for BDM
static const USBDM_ExtendedOptions_t defaultBdmOptions = {
      sizeof(USBDM_ExtendedOptions_t), // size
      T_OFF,               // targetType;             - Target type
      BDM_TARGET_VDD_OFF,  // targetVdd;              - Target Vdd (off, 3.3V or 5V)
      false,               // cycleVddOnReset;        - Cycle target Power  when resetting
      false,               // cycleVddOnConnect;      - Cycle target Power if connection problems)
      false,               // leaveTargetPowered;     - Leave target power on exit
      AUTOCONNECT_ALWAYS,  // autoReconnect;          - Automatically re-connect to target (for speed change)
      true,                // guessSpeed;             - Guess speed for target w/o ACKN
      CS_DEFAULT,          // bdmClockSource;         - Use alternative BDM clock source in target
      false,               // useResetSignal;         - Whether to use RESET signal on BDM interface
      false,               // maskInterrupts;         - Whether to mask interrupts when  stepping
      0,                   // interfaceSpeed;         - JTAG/CFVx/DSC only (kHz), 0 => selected by connection type
      false,               // usePSTSignals           - CFVx only
      500,                 // powerOffDuration        - How long to remove power
      200,                 // powerOnRecoveryInterval - How long to wait after power enabled
      100,                 // resetDuration           - How long to assert reset
      100,                 // resetReleaseInterval    - How long to wait after reset release to release other signals
      100,                 // resetRecoveryInterval   - How long to wait after reset sequence complete
};
CPP_DLL_LOCAL
USBDM_ExtendedOptions_t bdmOptions = defaultBdmOptions;

// The following option reduces the rate of polling of the BDM by the codewarrior
// software.  On the HCS12 version this was interfering with my USB mouse!
// It shouldn't impact on the responsiveness of the software (much!)
#define USB_THROTTLE (0) //!< Control throttling of USB use (0 => not throttled)

#define MESSAGE_HEADER_SIZE (8) //!< Size of header for target memory read/write

//! Buffer for USB I/O messages
static unsigned char usb_data[MAX_PACKET_SIZE+1]; //!< Buffer for USB I/O messages

static USBDM_ErrorCode updateBdmInfo(void);

//=============================================================================
//=============================================================================
//=============================================================================

//! Initialises USB interface
//!
//! This must be done before any other operations.
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => USB Error - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_Init(void) {
   UsbdmSystem::Log::openLogFile("usbdm.log", "USBDM Low level intrerface");
//   log.enableTimestamping();

   LOGGING_E;

   bdmState = defaultBDMState;

   USBDM_ErrorCode rc = bdm_usb_init();

   bdmState.initialised = (rc == BDM_RC_OK);

   bdmInfoValid = false;
   bdmInfo      = defaultBdmInfo;

   return rc;
}

//! Clean up
//!
//! This must be called after all USBDM operations are finished
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => USB Error - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_Exit(void) {
   LOGGING_E;
   USBDM_ErrorCode rc = bdm_usb_exit();

   log.closeLogFile();

   bdmState.initialised = false;

   return rc;
}

//! Get version of the library
//!
//! @return version number (e.g. V4.9.5 => 0x40905)
//!
//! @note Prior to V4.9.5 an 8-bit version number (2 BCD digits, major-minor) was returned\n
//!       This shouldn't be a problem as still monotonic
//!
USBDM_API
unsigned int USBDM_DLLVersion(void) {
   LOGGING_Q;
   log.print("=> V%d.%d.%d\n",
         USBDM_VERSION_MAJOR,
         USBDM_VERSION_MINOR,
         USBDM_VERSION_MICRO);
   return ((USBDM_VERSION_MAJOR<<16)+
           (USBDM_VERSION_MINOR<<8)+
           (USBDM_VERSION_MICRO));
}

//! Get version string for library
//!
//! @return ptr to static ASCII string
//!
USBDM_API
const char *USBDM_DLLVersionString(void) {
   return (USBDM_VERSION_STRING);
}

//! Gets string describing a USBDM error code
//!
//! @param errorCode - error code returned from USBDM API routine.
//!
//! @return - ptr to static string describing the error.
//!
USBDM_API
const char *USBDM_GetErrorString(USBDM_ErrorCode errorCode) {
const char *errMsg;
   LOGGING_Q;
   errMsg = getErrorName(errorCode);
   log.print("%d => \'%s\'\n", errorCode, errMsg);
   return errMsg;
}

//=============================================================================
//=============================================================================
//=============================================================================
// USBDM Device handling

//! Find USBDM Devices \n
//! This function creates an internal list of USBDM devices.  The list is held until
//! USBDM_ReleaseDevices() is called. \n
//! USBDM_FindDevices() must be done before any device may be opened.
//!
//! @param deviceCount Number of BDM devices found
//!
//! @return \n
//!     BDM_RC_OK                => OK \n
//!     BDM_RC_NO_USBDM_DEVICE   => No devices found.
//!     other                    => other Error - see \ref USBDM_ErrorCode
//!
//! @note deviceCount == 0 on any error so may be used w/o checking rc
//! @note The device list is held until USBDM_ReleaseDevices() is called
//!
USBDM_API
USBDM_ErrorCode USBDM_FindDevices(unsigned int *deviceCount) {
   LOGGING_Q;
   *deviceCount = 0;

   if (!bdmState.initialised) {
      return BDM_RC_NOT_INITIALISED;
   }

   USBDM_ErrorCode rc = bdm_usb_findDevices(deviceCount); // look for USBDM devices on all USB busses
   log.print("USB initialised, found %d device(s)\n", *deviceCount);
   return rc;
}

//! Release USBDM Device list
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => USB Error - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_ReleaseDevices(void) {
   LOGGING_Q;
   log.print("\n");
   return bdm_usb_releaseDevices();
}

//! Obtain serial number of the currently opened BDM
//!
//! @param deviceSerialNumber  Updated to point to UTF-16LE serial number
//!
//! @return \n
//!    == BDM_RC_OK (0)     => Success\n
//!    == BDM_RC_USB_ERROR  => USB failure
//!
//! @note deviceDescription points at a statically allocated buffer - do not free
//!
USBDM_API
USBDM_ErrorCode USBDM_GetBDMSerialNumber(const char **deviceSerialNumber) {
   if (!bdmState.initialised) {
      return BDM_RC_NOT_INITIALISED;
   }

   LOGGING_Q;
   static char buffer[100];
   *deviceSerialNumber = buffer+2;// Skip over length/DT_STRING bytes

   //ToDo - assumes serial number is string descr. #3 - should check device descriptor.
   USBDM_ErrorCode rc = bdm_usb_getStringDescriptor(3, buffer, sizeof(buffer));
//   if (rc == BDM_RC_OK) {
//      log.print("=> s=%ls\n", *deviceSerialNumber);
//   }
   return rc;
}

//! Obtain description of the currently opened BDM
//!
//! @param deviceDescription  Updated to point to UTF-16LE device description
//!
//! @return \n
//!    == BDM_RC_OK (0)     => Success\n
//!    == BDM_RC_USB_ERROR  => USB failure
//!
//! @note deviceDescription points at a statically allocated buffer - do not free
//!
USBDM_API
USBDM_ErrorCode USBDM_GetBDMDescription(const char **deviceDescription) {
   if (!bdmState.initialised) {
      return BDM_RC_NOT_INITIALISED;
   }

   LOGGING_Q;
   static char buffer[100];
   *deviceDescription = buffer+2;// Skip over length/DT_STRING bytes

   //ToDo - assumes description is string descr. #2 - should check device descriptor.
   USBDM_ErrorCode rc = bdm_usb_getStringDescriptor(2, buffer, sizeof(buffer));
//   if (rc == BDM_RC_OK) {
//      log.print("=> s=%ls\n", *deviceDescription);
//   }
   return rc;
}

//! Opens a device
//!
//! @param deviceNo Number (0..N) of device to open.
//! A device must be open before any communication with the device can take place.
//!
//! @note The range of device numbers must be obtained from USBDM_FindDevices() before
//! calling this function.
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_Open(unsigned char deviceNo) {
   LOGGING_Q;

   if (!bdmState.initialised) {
      return BDM_RC_NOT_INITIALISED;
   }

   // Set conservative transfer size
   bdmInfo.commandBufferSize = DEFAULT_PACKET_SIZE;

   USBDM_ErrorCode rc = BDM_RC_OK;

   log.print("Trying to open device #%d\n", deviceNo);
   rc = bdm_usb_open(deviceNo);
   if (rc != BDM_RC_OK) {
      log.print("Failed - rc = %s\n", USBDM_GetErrorString(rc));
      return rc;
   }
   // Get information about the currently open BDM, fatal if unsuccessful
   rc = updateBdmInfo();
   if (rc != BDM_RC_OK) {
      USBDM_Close();
      return rc;
   }
   log.print("\n"
         "         BDM S/W version = %d.%d.%d, H/W version (from BDM) = %1X.%X\n"
         "         ICP S/W version = %1X.%1X,   H/W version (from ICP) = %1X.%X\n",
         (bdmInfo.BDMsoftwareVersion>>16)&0xFF,(bdmInfo.BDMsoftwareVersion>>8)&0xFF,bdmInfo.BDMsoftwareVersion&0xFF,
         (bdmInfo.BDMhardwareVersion >> 6) & 0x03,
         bdmInfo.BDMhardwareVersion & 0x3F,
         (bdmInfo.ICPsoftwareVersion >> 4) & 0x0F,
         bdmInfo.ICPsoftwareVersion & 0x0F,
         (bdmInfo.ICPhardwareVersion >> 6) & 0x03,
         bdmInfo.ICPhardwareVersion & 0x3F
         );
   bdmOptions = defaultBdmOptions;
   return (rc);
}

//! Closes currently open device
//!
//! @return \n
//!     BDM_RC_OK => OK
//!
USBDM_API
USBDM_ErrorCode USBDM_Close(void) {
//   uint8_t debugCommand[2] = {sizeof(debugCommand),BDM_DBG_TESTALTSPEED};
   LOGGING_Q;

   log.print("Trying to close the device\n");

   if ((bdmOptions.targetType == T_ARM_SWD) || (bdmOptions.targetType == T_ARM_JTAG)) {
      log.print("Doing armDisconnect()\n");
      armDisconnect(bdmState.targetType);
   }
   if (bdmState.targetType != T_OFF) { // USBDM on ?
      // Tell the BDM that we're finished (power down)
      log.print("Telling BDM to close (poweroff)\n");
      USBDM_SetTargetType(T_OFF);
   }
   bdm_usb_close();

   bdmInfoValid = false;
   bdmInfo      = defaultBdmInfo;

   return BDM_RC_OK;
}

//! Gets BDM software version and type of hardware
//!
//! @param version Version numbers (4 bytes)
//!  - USBDM software version              \n
//!  - USBDM hardware type                 \n
//!  - ICP software version                \n
//!  - ICP hardware type                   \n
//!  USBDM & ICP hardware versions should always agree
//!
//! @return \n
//!     BDM_RC_OK   => OK \n
//!     other       => Error code - see \ref USBDM_ErrorCode
//!
//! @note - This command is directed to EP0 and is also allowed in ICP mode
//!
//! @deprecated: use USBDM_GetBdmInformation()
//!
USBDM_API
USBDM_ErrorCode USBDM_GetVersion(USBDM_Version_t *version) {
   LOGGING_Q;

   if (!bdmState.initialised) {
      return BDM_RC_NOT_INITIALISED;
   }

   USBDM_ErrorCode rc;
   static const USBDM_Version_t defaultVersion = {0,0,0,0};
   unsigned rxSize;

   usb_data[0] = 10;                // receive 5 bytes
   usb_data[1] = CMD_USBDM_GET_VER; // command
   usb_data[3] = 1;
   usb_data[4] = 0;
   usb_data[5] = 0;
   rc = bdm_usb_recv_ep0(usb_data, &rxSize); // USB EP0
   if (rc != BDM_RC_OK) {
      *version = defaultVersion;
   }
   else {
      *version = *((USBDM_Version_t *)(usb_data+1));
   }
   if (version->bdmSoftwareVersion == 0xFF) {
      // In ICP mode - check if valid ICP hardware version
      if ((version->icpHardwareVersion ==  0x00) &&
          (version->bdmHardwareVersion != 0x00)) {
    	  version->icpHardwareVersion = version->bdmHardwareVersion;
          log.print("USBDM_GetVersion() => Invalid ICP_HW Version, using BDM_HW Version\n");
      }
   }
   log.print("=> BDM_SW=%2X, BDM_HW=%2X, ICP_SW=%2X, ICP_HW=%2X\n",
         version->bdmSoftwareVersion, version->bdmHardwareVersion,
         version->icpSoftwareVersion, version->icpHardwareVersion);
   return rc;
}

#define VERSION_NUM(w,x,y) (((w)<<16)+((x)<<8)+(y))

//! \brief Obtains the Capability vector from the BDM interface
//!
//! @param capabilities : ptr to where to return capability vector see \ref HardwareCapabilities_t
//! @return \n
//!     BDM_RC_OK                 => OK \n
//!     BDM_RC_WRONG_BDM_REVISION => BDM firmware/library are incompatible \n
//!     other                     => Error code - see \ref USBDM_ErrorCode
//!
//! @note Uses cached information from when the BDM was opened.
//! @note Can be used to check BDM firmware/library compatibility
//!
USBDM_API
USBDM_ErrorCode USBDM_GetCapabilities(HardwareCapabilities_t *capabilities) {
   LOGGING_Q;

   if (!bdmState.initialised) {
      return BDM_RC_NOT_INITIALISED;
   }

   if (!bdmInfoValid) {
      return BDM_RC_DEVICE_NOT_OPEN;
   }
   // This library is incompatible with BDM versions < 4.9.5
   if (bdmInfo.BDMsoftwareVersion < VERSION_NUM(4,9,5)) {
      *capabilities = BDM_CAP_NONE;
      log.print("=> Incompatible BDM Firmware Version 0x%06X!\n", bdmInfo.BDMsoftwareVersion);
      return BDM_RC_WRONG_BDM_REVISION;
   }
   *capabilities = bdmInfo.capabilities;
   log.print("=> %s\n", getCapabilityName(bdmInfo.capabilities));
   return BDM_RC_OK;
}

//! \brief Updates information about the currently open BDM interface by polling the device
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
static USBDM_ErrorCode updateBdmInfo(void) {
   USBDM_ErrorCode rc;
   USBDM_Version_t USBDMVersion;
   LOGGING_Q;

   // Set safe defaults
   bdmInfo             = defaultBdmInfo;
   bdmInfoValid        = false;
   bdmState.useOnlyEp0 = true;

   rc = USBDM_GetVersion(&USBDMVersion);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   bdmInfo.BDMsoftwareVersion = ((USBDMVersion.bdmSoftwareVersion&0xF0)<<12)+((USBDMVersion.bdmSoftwareVersion&0x0F)<<8);
   bdmInfo.BDMhardwareVersion = USBDMVersion.bdmHardwareVersion;
   bdmInfo.ICPsoftwareVersion = USBDMVersion.icpSoftwareVersion;
   bdmInfo.ICPhardwareVersion = USBDMVersion.icpHardwareVersion;

   // Use EP0 for JB16 version hardware
   bdmState.useOnlyEp0   = ((USBDMVersion.icpHardwareVersion & 0xC0) == 0);
   log.print("=> useOnlyEp0 = %s\n", bdmState.useOnlyEp0?"True":"False");

   if (USBDMVersion.bdmSoftwareVersion == 0xFF) {
      // In ICP mode - use defaults
      bdmInfoValid = true;
      return BDM_RC_OK;
   }
   unsigned rxSize = 8; // expect up to 8 bytes
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_GET_CAPABILITIES;
   rc = bdm_usb_transaction(2, &rxSize, usb_data);
   if (rc != BDM_RC_OK) {
      log.print("Failed!\n");
      return rc;
   }
//   log.print("updateBdmInfo() raw=>0x%2.2X-0x%2.2X%2.2X\n",
//         usb_data[0], usb_data[1], usb_data[2]);
   // BDM_CAP_HCS08 & BDM_CAP_CFV1 are inverted for backwards compatibility
   bdmInfo.capabilities = (HardwareCapabilities_t)(((usb_data[1]<<8)+usb_data[2])^(BDM_CAP_HCS08|BDM_CAP_CFV1));
   log.print("=> CAPABILITIES = 0x%2.2X (%s)\n",
         bdmInfo.capabilities, getCapabilityName(bdmInfo.capabilities));
   if (rxSize >= 5) {
      // Newer BDMs report command buffer size
      unsigned bufferSize = (usb_data[3]<<8) + usb_data[4];
      log.print("=> BDM command buffer size = %d bytes\n", bufferSize);
      if (bufferSize>MAX_PACKET_SIZE)
         bufferSize = MAX_PACKET_SIZE;
      bdmInfo.commandBufferSize = bufferSize;
      bdmInfo.jtagBufferSize    = bufferSize-JTAG_HEADER_SIZE;
   }
   if (rxSize >= 8) {
      // Newer BDMs report extended software version
      bdmInfo.BDMsoftwareVersion = (usb_data[5]<<16)+(usb_data[6]<<8)+usb_data[7];
      log.print("=> Software version = %d.%d.%d\n", usb_data[5], usb_data[6], usb_data[7]);
   }
   bdmInfoValid = true;
   return rc;
}

//! \brief Obtains information about the currently open BDM interface
//!
//! @param info ptr to structure to contain the information
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
//! @note The size element of info should be initialised before call.
//! @note Uses cached information from when the BDM was opened.
//!
USBDM_API
USBDM_ErrorCode USBDM_GetBdmInformation(USBDM_bdmInformation_t *info) {
   LOGGING_Q;

   log.print("\n"
         "         bdmInfo.capabilities       = %s\n"
         "         bdmInfo.commandBufferSize  = %d\n"
         "         bdmInfo.jtagBufferSize     = %d\n"
         "         bdmInfo.BDMhardwareVersion = %d.%d\n"
         "         bdmInfo.BDMsoftwareVersion = %d.%d.%d\n"
         "         bdmInfo.ICPhardwareVersion = %d.%d\n"
         "         bdmInfo.ICPsoftwareVersion = %d.%d\n",
         getCapabilityName(bdmInfo.capabilities),
         bdmInfo.commandBufferSize,
         bdmInfo.jtagBufferSize,
         (bdmInfo.BDMhardwareVersion>>6),(bdmInfo.BDMhardwareVersion&0x3F),
         (bdmInfo.BDMsoftwareVersion>>16),((bdmInfo.BDMsoftwareVersion>>8)&0xFF),(bdmInfo.BDMsoftwareVersion&0xFF),
         (bdmInfo.ICPhardwareVersion>>6),(bdmInfo.ICPhardwareVersion&0x3F),
         (bdmInfo.ICPsoftwareVersion>>4),(bdmInfo.ICPsoftwareVersion&0x0F)
        );

   unsigned size = info->size;

   if (size > sizeof(USBDM_bdmInformation_t)) {
      size = sizeof(USBDM_bdmInformation_t); // Must be a later version!
   }
   if (size == 0) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   if (!bdmInfoValid) {
      return BDM_RC_DEVICE_NOT_OPEN;
   }
   // Copy subset of structure that is common.
   memcpy(info, &bdmInfo, size);
   info->size = size; // Actual size returned

   return BDM_RC_OK;
}

//! \brief Transmits BDM options to BDM interface
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
static USBDM_ErrorCode sendBdmOptions(void) {
   LOGGING_E;
   bdmState.activityFlag = BDM_ACTIVE;

   int index = 0;
   usb_data[index++] = 0;
   usb_data[index++] = CMD_USBDM_SET_OPTIONS;
   usb_data[index++] = (uint8_t)  bdmOptions.targetVdd;
   usb_data[index++] = (uint8_t)  bdmOptions.cycleVddOnReset;
   usb_data[index++] = (uint8_t)  bdmOptions.cycleVddOnConnect;
   usb_data[index++] = (uint8_t)  bdmOptions.leaveTargetPowered;
   usb_data[index++] = (uint8_t)  bdmOptions.autoReconnect;
   usb_data[index++] = (uint8_t)  bdmOptions.guessSpeed;
   usb_data[index++] = (uint8_t)  bdmOptions.bdmClockSource;
   usb_data[index++] = (uint8_t)  bdmOptions.useResetSignal;

   return bdm_usb_transaction(index, 1, usb_data);
}

//! Adapts the bdm options to the specified target
//!
//! @param bdmOptions - The options to modify
//!
static void adaptBdmOptions(USBDM_ExtendedOptions_t *bdmOptions) {

   switch (bdmOptions->targetType) {
   case T_HC12:
   case T_S12Z:
      bdmOptions->useResetSignal = true;
      bdmOptions->usePSTSignals  = false;
      break;
   case T_ARM_SWD:
      if (bdmOptions->interfaceFrequency == 0) {
         bdmOptions->interfaceFrequency = 12000; // kHz
      }
      bdmOptions->guessSpeed         = false;
      bdmOptions->useResetSignal     = true;
      bdmOptions->usePSTSignals  = false;
      break;
   case T_ARM:
   case T_ARM_JTAG:
      if (bdmOptions->interfaceFrequency == 0) {
         bdmOptions->interfaceFrequency = 2000; // kHz
      }
      bdmOptions->guessSpeed         = false;
      bdmOptions->useResetSignal     = true;
      bdmOptions->usePSTSignals  = false;
      break;
   case T_CFVx:
   case T_MC56F80xx:
   case T_EZFLASH:
   case T_JTAG:
      if (bdmOptions->interfaceFrequency == 0) {
         bdmOptions->interfaceFrequency = 2000; // kHz
      }
      bdmOptions->guessSpeed     = false;
      bdmOptions->useResetSignal = true;
      bdmOptions->usePSTSignals  = false;
      break;
   default:
   case T_RS08:
   case T_HCS08:
   case T_CFV1:
      bdmOptions->guessSpeed     = false;
      bdmOptions->usePSTSignals  = false;
      break;
   }
}

//! Set BDM interface options
//!
//! @param newBdmOptions : Options to pass to BDM interface
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
//! @deprecated - Use USBDM_SetExtendedOptions()
//!
USBDM_API
USBDM_ErrorCode USBDM_SetOptions(BDM_Options_t *newBdmOptions) {
   LOGGING_Q;

   // Copy subset of options
   bdmOptions = defaultBdmOptions;
   bdmOptions.targetType         =                     bdmState.targetType;

   bdmOptions.targetVdd          = (TargetVddSelect_t) newBdmOptions->targetVdd;
   bdmOptions.cycleVddOnReset    =              (bool) newBdmOptions->cycleVddOnReset;
   bdmOptions.cycleVddOnConnect  =              (bool) newBdmOptions->cycleVddOnConnect;
   bdmOptions.leaveTargetPowered =              (bool) newBdmOptions->leaveTargetPowered;
   bdmOptions.autoReconnect      =     (AutoConnect_t) newBdmOptions->autoReconnect;
   bdmOptions.guessSpeed         =              (bool) newBdmOptions->guessSpeed;
   bdmOptions.bdmClockSource     =     (ClkSwValues_t) newBdmOptions->useAltBDMClock;
   bdmOptions.useResetSignal     =              (bool) newBdmOptions->useResetSignal;
   bdmOptions.maskInterrupts     =              (bool) newBdmOptions->maskInterrupts;
   // No longer used                            (bool) newBdmOptions->manuallyCycleVdd;
   bdmOptions.interfaceFrequency =                     newBdmOptions->interfaceSpeed;
   bdmOptions.usePSTSignals      =              (bool) newBdmOptions->usePSTSignals;

   adaptBdmOptions(&bdmOptions);

   log.print("=>\n");
   printBdmOptions(&bdmOptions);

   return sendBdmOptions();
}

//! Get default (target specific) BDM interface options
//!
//! @param bdmOptions : Current options from BDM interface\n
//!                        Note - bdmOptions.size must be initialised \n
//!                             - bdmOptions.targetType may be set (and is preserved)
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
//! @note newBdmOptions.targetType should be set if called before USBDM_SetTarget()
//!
USBDM_API
USBDM_ErrorCode USBDM_GetDefaultExtendedOptions(USBDM_ExtendedOptions_t *bdmOptions) {
   LOGGING_E;
   unsigned size           = bdmOptions->size;
   TargetType_t targetType = bdmOptions->targetType;

   // Only copy subset of known options
   if (size > sizeof(USBDM_ExtendedOptions_t)) {
      size = sizeof(USBDM_ExtendedOptions_t);
   }
   if (size == 0) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   USBDM_ExtendedOptions_t defaultOptions = defaultBdmOptions;

   // Adapt the default options to the target type
   defaultOptions.targetType = targetType;
   defaultOptions.size       = size;
   adaptBdmOptions(&defaultOptions);
   memcpy(bdmOptions, &defaultOptions, size);

//   log.print("\n");
//   printBdmOptions(&defaultOptions);

   return BDM_RC_OK;
}

/*!  Set BDM interface options
 *
 *   @param newBdmOptions : Options to pass to BDM interface\n
 *
 *   @return \n
 *       BDM_RC_OK => OK \n
 *       other     => Error code - see \ref USBDM_ErrorCode
 *
 *   @note - size field must be initialised
 *   @note - targetType field is treated as a hint i.e. is does NOT set the target type.
 *           If target type is already set then it is ignored.
 */
USBDM_API
USBDM_ErrorCode USBDM_SetExtendedOptions(const USBDM_ExtendedOptions_t *newBdmOptions) {
   LOGGING;
#ifdef LOG
//   log.print("=> proposed (%p), sizeof = %d, sizeof=%d\n", newBdmOptions, sizeof (*newBdmOptions), sizeof(USBDM_ExtendedOptions_t));
//   log.print("=> sizeof (size)= %d\n",                sizeof (newBdmOptions->size));
//   log.print("=> sizeof (targetType)= %d\n",          sizeof (newBdmOptions->targetType));
//   log.print("=> sizeof (targetVdd)= %d\n",           sizeof (newBdmOptions->targetVdd));
//   log.print("=> sizeof (cycleVddOnReset)= %d\n",     sizeof (newBdmOptions->cycleVddOnReset));
//   log.print("=> sizeof (leaveTargetPowered)= %d\n",  sizeof (newBdmOptions->leaveTargetPowered));
//   log.print("=> sizeof (autoReconnect)= %d\n",       sizeof (newBdmOptions->autoReconnect));
//   log.print("=> offset (size)= %d\n",                ((int)&newBdmOptions->size)-((int)newBdmOptions));
//   log.print("=> offset (targetType)= %d\n",          ((int)&newBdmOptions->targetType)-((int)newBdmOptions));
//   log.print("=> offset (targetVdd)= %d\n",           ((int)&newBdmOptions->targetVdd)-((int)newBdmOptions));
//   log.print("=> offset (cycleVddOnReset)= %d\n",     ((int)&newBdmOptions->cycleVddOnReset)-((int)newBdmOptions));
//   log.print("=> offset (leaveTargetPowered)= %d\n",  ((int)&newBdmOptions->leaveTargetPowered)-((int)newBdmOptions));
//   log.print("=> offset (autoReconnect)= %d\n",       ((int)&newBdmOptions->autoReconnect)-((int)newBdmOptions));

   log.print("=> proposed => \n");
   printBdmOptions(newBdmOptions);
#endif
   // Validate some options
   USBDM_ErrorCode rc = BDM_RC_OK;
   if (newBdmOptions->size > sizeof(USBDM_ExtendedOptions_t)) {
      rc =  BDM_RC_ILLEGAL_PARAMS;
   }
   if (newBdmOptions->size == 0) {
      rc =  BDM_RC_ILLEGAL_PARAMS;
   }
   if ((newBdmOptions->targetType > T_LAST) && (newBdmOptions->targetType != T_OFF)) {
      rc =  BDM_RC_ILLEGAL_PARAMS;
   }
   if (newBdmOptions->targetVdd > BDM_TARGET_VDD_5V) {
      rc =  BDM_RC_ILLEGAL_PARAMS;
   }
   if ((newBdmOptions->powerOffDuration<100) || (newBdmOptions->powerOffDuration>10000)) {
      rc =  BDM_RC_ILLEGAL_PARAMS;
   }
   if ((newBdmOptions->powerOnRecoveryInterval<100) || (newBdmOptions->powerOnRecoveryInterval>10000)) {
      rc =  BDM_RC_ILLEGAL_PARAMS;
   }
   if ((newBdmOptions->resetDuration<100) || (newBdmOptions->resetDuration>10000)) {
      rc =  BDM_RC_ILLEGAL_PARAMS;
   }
   if ((newBdmOptions->resetReleaseInterval<10) || (newBdmOptions->resetReleaseInterval>10000)) {
      rc =  BDM_RC_ILLEGAL_PARAMS;
   }
   if ((newBdmOptions->resetRecoveryInterval<10) || (newBdmOptions->resetRecoveryInterval>10000)) {
      rc =  BDM_RC_ILLEGAL_PARAMS;
   }
   if (rc != BDM_RC_OK) {
      log.print(" - ERROR - rc = %s\n", USBDM_GetErrorString(rc));
      return rc;
   }
   // Save current target type (as may already be set)
   TargetType_t currentTargetType   = bdmOptions.targetType;
   bdmOptions = defaultBdmOptions;
   memcpy(&bdmOptions, newBdmOptions, newBdmOptions->size);
   if ( currentTargetType != T_OFF) {
      // Override hint with currently set target type
      // before adapting to target
      bdmOptions.targetType = currentTargetType;
   }
   adaptBdmOptions(&bdmOptions);
   // Restore current target type
   bdmOptions.targetType = currentTargetType;

   log.print("=> accepted\n");
   printBdmOptions(&bdmOptions);

   return sendBdmOptions();
}

//! Get BDM interface options
//!
//! @param currentBdmOptions : Current options from BDM interface\n
//!                            Note - currentBdmOptions.size must be initialised
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_GetExtendedOptions(USBDM_ExtendedOptions_t *currentBdmOptions) {
   unsigned size = currentBdmOptions->size;
   LOGGING_Q;

   // Copy subset of known options
   if (size > sizeof(USBDM_ExtendedOptions_t)) {
      size = sizeof(USBDM_ExtendedOptions_t);
   }
   if (size == 0) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   memcpy(currentBdmOptions, &bdmOptions, size);
   currentBdmOptions->size = size;

   log.print("=>\n");
   printBdmOptions(&bdmOptions);

   return BDM_RC_OK;
}

//! Sets Target Vdd voltage
//!
//! @param targetVdd => control value for Vdd
//!
//! @return \n
//!     BDM_RC_OK     => OK \n
//!     else          => Various errors
//!
//! @note
//! - BDM_TARGET_VDD_ENABLE & BDM_TARGET_VDD_DISABLE should be used to enable and disable Vdd
//! - BDM_TARGET_VDD_OFF, BDM_TARGET_VDD_3V3 & BDM_TARGET_VDD_5V should be used to set the required Vdd.
//! - It is expected that the USBDM_SetTargetVdd() will be used to set the initial Vdd before calling
//!   USBDM_SetTarget() so that the appropriate power on sequence may be used.
//!
USBDM_API
USBDM_ErrorCode  USBDM_SetTargetVdd(TargetVddSelect_t targetVdd) {
   USBDM_ErrorCode rc;
   LOGGING_Q;

   log.print("%s\n", getVoltageSelectName(targetVdd));

   switch (targetVdd) {
   case BDM_TARGET_VDD_ENABLE:
      // Set to last level
      targetVdd = bdmOptions.targetVdd;
      armInitialiseDone     = false;
      break;
   case BDM_TARGET_VDD_DISABLE:
      // Change to off but do not change last level
      targetVdd = BDM_TARGET_VDD_OFF;
      armInitialiseDone     = false;
      break;
   case BDM_TARGET_VDD_OFF:
      armInitialiseDone     = false;
      break;
   default:
      // Record new level
      bdmOptions.targetVdd = targetVdd;
      break;
   }
   if (!bdmOptions.leaveTargetPowered && (bdmState.targetType == T_OFF)) {
      // Force Vdd off
      // Vdd will be enabled by setTargetType()
      targetVdd = BDM_TARGET_VDD_OFF;
   }
   log.print("actual=%s\n", getVoltageSelectName(targetVdd));
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_SET_VDD;
   usb_data[2] = targetVdd>>8;  // 16-bit big-endian value
   usb_data[3] = targetVdd;
   rc = bdm_usb_transaction(4, 1, usb_data, 1000);
   return rc;
}

//! Sets Target programming voltage
//!
//! @param targetVpp => control value for Vpp
//!
//! @note Before enabling target Vpp it is necessary to do the following: \n
//! - Target device must be set to T_RS08 \n
//! - Target Vdd must be present (internally or externally) \n
//! - The Target Vpp must be first set to BDM_TARGET_VPP_STANDBY then BDM_TARGET_VPP_ON \n
//! The above is checked by the BDM firmware
//!
//! @return \n
//!     BDM_RC_OK     => OK \n
//!     else          => Various errors
//!
USBDM_API
USBDM_ErrorCode  USBDM_SetTargetVpp(TargetVppSelect_t targetVpp) {
   USBDMStatus_t   USBDMStatus;
   USBDM_ErrorCode rc;
   LOGGING_Q;

   log.print("%s\n", getVppSelectName(targetVpp));

   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_SET_VPP;
   usb_data[2] = targetVpp;
   rc = bdm_usb_transaction(3, 1, usb_data);
   (void)USBDM_GetBDMStatus(&USBDMStatus); // Debug
   return rc;
}

//! Directly manipulate interface levels
//!
//! @param control       => mask indicating interface levels see \ref InterfaceLevelMasks_t
//! @param duration_10us => time (in 10us ticks) to assert level
//!                         (0 = indefinite)
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
//! @note - Only partially implemented in BDM firmware
//! @deprecated - use \ref USBDM_ControlPins()
//!
USBDM_API
USBDM_ErrorCode USBDM_ControlInterface(unsigned char duration_10us, unsigned int  control) {
   unsigned int controlValue = 0;
   LOGGING_Q;

   log.print("0x%X(%s), %d us\n", control, getControlLevelName((InterfaceLevelMasks_t)control), duration_10us);

   if (control == (unsigned int )SI_DISABLE) {
      return USBDM_ControlPins(PIN_RELEASE);
   }
   else {
      switch(control & SI_RESET) {
      case SI_RESET_LOW:    controlValue |= PIN_RESET_LOW;    break;
      case SI_RESET_3STATE: controlValue |= PIN_RESET_3STATE; break;
      }
      switch (bdmOptions.targetType) {
      case T_RS08:
      case T_HCS08:
      case T_HCS12:
      case T_S12Z:
      case T_CFV1:
         switch(control & SI_BKGD) {
         case SI_BKGD_LOW:    controlValue |= PIN_BKGD_LOW;    break;
         case SI_BKGD_HIGH:   controlValue |= PIN_BKGD_HIGH;   break;
         case SI_BKGD_3STATE: controlValue |= PIN_BKGD_3STATE; break;
         }
         break;
      case T_CFVx:
         switch(control & SI_BKGD) {
         case SI_BKGD_LOW:    controlValue |= PIN_BKGD_LOW;    break;
         case SI_BKGD_HIGH:   controlValue |= PIN_BKGD_HIGH;   break;
         case SI_BKGD_3STATE: controlValue |= PIN_BKGD_3STATE; break;
         }
         switch(control & SI_TA) {
         case SI_TA_LOW:    controlValue |= PIN_TA_LOW;    break;
         case SI_TA_3STATE: controlValue |= PIN_TA_3STATE; break;
         }
         break;
         case T_JTAG:
         case T_ARM_JTAG:
         case T_MC56F80xx:
            switch(control & SI_TRST) {
            case SI_TRST_LOW:    controlValue |= PIN_TRST_LOW;    break;
            case SI_TRST_3STATE: controlValue |= PIN_TRST_3STATE; break;
            }
            break;
         default:
            break;
      }
      USBDM_ErrorCode rc = USBDM_ControlPins(controlValue);
      if ((rc != BDM_RC_OK) || (duration_10us == 0)) {
         return rc;
      }
      milliSleep(1); // use 1 ms
      return USBDM_ControlPins(PIN_RELEASE);
   }
}

/*!
 * Send Custom BDM command
 *
 * @param txSize
 * @param rxSize
 * @param data
 */
USBDM_API
USBDM_ErrorCode USBDM_BDMCommand(unsigned int txSize, unsigned int rxSize, unsigned char data[]) {
   LOGGING;

   if (txSize > MAX_PACKET_SIZE-10) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   if (rxSize > MAX_PACKET_SIZE-10) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   log.print("s=%d, d=0x%02X, 0x%02X, \n", txSize, data[0], data[1]);
   usb_data[0] = 0;
   usb_data[1] = CMD_CUSTOM_COMMAND;
   memcpy(usb_data+2, data, txSize);

   USBDM_ErrorCode rc = bdm_usb_transaction(txSize+2, rxSize, usb_data);
   return rc;
}

//! Directly manipulate interface levels
//!
//! @param control       => mask indicating interface levels see \ref PinLevelMasks_t
//! @param status        => values on pins after action (not yet implemented). May be NULL.
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_ControlPins(unsigned int control, unsigned int *status) {
   LOGGING_Q;

   bdmState.activityFlag = BDM_ACTIVE;

   log.print("0x%X(%s)\n", control, getPinLevelName((PinLevelMasks_t)control));
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_CONTROL_PINS;
   usb_data[2] = (uint8_t)(control>>8);
   usb_data[3] = (uint8_t)control;

   USBDM_ErrorCode rc = bdm_usb_transaction(4, 3, usb_data);
   if ((rc == BDM_RC_OK) && (status != NULL)) {
      *status = (usb_data[1]<<8) + usb_data[2];
   }
   if (pendingResetRelease && ((control&PIN_RESET) != PIN_RESET_NC)) {
      // Manually set reset level - clear pending release
      pendingResetRelease = false;
      log.print("Clearing pending RESET release\n");
   }
   return rc;
}

//=============================================================================
//=============================================================================
//=============================================================================
// Target handling

//! Sets target MCU type
//! If the BDM has target power control then it will also:
//!   - Turn on target power
//!   - Halt the target if power has been newly applied (in special mode if appropriate)
//!   - ARM targets have hardware reset still active to avoid power-on lockups or COP timeouts
//!
//! @param target_type type of target
//!
//! @return 0 => Success,\n !=0 => Fail
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_SetTargetType(TargetType_t targetType) {
   USBDM_ErrorCode rc = BDM_RC_OK;
   LOGGING_Q;

   log.print("%s\n", getTargetTypeName(targetType));

   // Get capabilities to force check firmware version check.
   HardwareCapabilities_t capabilities;
   rc = USBDM_GetCapabilities(&capabilities);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   bdmState.activityFlag = BDM_ACTIVE;
   bdmState.targetType   = T_OFF;
   pendingResetRelease   = false;
   armInitialiseDone     = false;

   if (targetType == T_ARM) {
      // Convert to either T_ARM_SWD or T_ARM_JTAG as supported
      // Prefer T_ARM_SWD
      if (capabilities&BDM_CAP_ARM_SWD) {
         targetType = T_ARM_SWD;
      }
      else if (capabilities&BDM_CAP_ARM_JTAG) {
         targetType = T_ARM_JTAG;
      }
      else {
         return BDM_RC_UNKNOWN_TARGET;
      }
      log.print("Adapted = %s\n", getTargetTypeName(targetType));
   }
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_SET_TARGET;
   usb_data[2] = targetType;
   rc = bdm_usb_transaction(3, 1, usb_data, 1000);

   if (rc != BDM_RC_OK) {
      log.print("Error, rc= %s\n", getErrorName(rc));
      USBDM_SetTargetVdd(BDM_TARGET_VDD_DISABLE);
      milliSleep(bdmOptions.powerOnRecoveryInterval);
      bdmState.targetType = T_OFF;
      return rc;
   }
   bdmState.targetType = targetType;

   if (targetType == T_OFF) {
      if (!bdmOptions.leaveTargetPowered) {
         rc = USBDM_SetTargetVdd(BDM_TARGET_VDD_DISABLE);
         milliSleep(bdmOptions.powerOnRecoveryInterval);
      }
      return rc;
   }
   bdmOptions.targetType = targetType;
   switch (targetType) {
   case T_ARM_JTAG:
   case T_ARM_SWD:
   case T_CFVx:
   case T_MC56F80xx:
   case T_EZFLASH:
   case T_JTAG:
      if (bdmOptions.interfaceFrequency == 0) {
         bdmOptions.interfaceFrequency = 500; // kHz default
      }
      USBDM_SetSpeed(bdmOptions.interfaceFrequency);
      break;
   default:
      break;
   }
   if ((bdmInfo.capabilities & BDM_CAP_VDDCONTROL) == 0) {
      return rc;
   }
   //=====================================================================
   // BDM has target power control - enable power & do POR as appropriate

   // Get target power state
   USBDMStatus_t bdmStatus;
   rc = USBDM_GetBDMStatus(&bdmStatus);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   if (bdmOptions.targetVdd == BDM_TARGET_VDD_OFF) {
      // Just turn off power
      return USBDM_SetTargetVdd(BDM_TARGET_VDD_OFF);
   }
   if ((bdmStatus.power_state == BDM_TARGET_VDD_INT) ||
       ( ((bdmInfo.capabilities & BDM_CAP_VDDSENSE) != 0) && (bdmStatus.power_state == BDM_TARGET_VDD_EXT))) {
      // Target already powered - don't do POR
      log.print("Target already powered - no POR\n");
      return BDM_RC_OK;
   }
   // Do power on sequence into special mode if possible
   log.print("Doing Power-on-reset\n");
   switch (targetType) {
      case T_S12Z:
      case T_HC12:
         // Specific power/pin sequence to enter BKGD mode
         USBDM_ControlPins(PIN_RESET_LOW|PIN_BKGD_LOW);
         rc = USBDM_SetTargetVdd(BDM_TARGET_VDD_ENABLE);
         milliSleep(bdmOptions.powerOnRecoveryInterval);
         USBDM_ControlPins(PIN_RESET_3STATE);
         milliSleep(bdmOptions.resetReleaseInterval);
         USBDM_ControlPins(PIN_RELEASE);
         milliSleep(bdmOptions.resetRecoveryInterval);
         break;
      case T_RS08:
      case T_HCS08:
      case T_CFV1:
         // Specific power/pin sequence to enter BKGD mode
         if (bdmOptions.useResetSignal) {
            USBDM_ControlPins(PIN_RESET_LOW|PIN_BKGD_LOW);
         }
         else {
            USBDM_ControlPins(PIN_BKGD_LOW);
         }
         rc = USBDM_SetTargetVdd(BDM_TARGET_VDD_ENABLE);
         milliSleep(bdmOptions.powerOnRecoveryInterval);
         if (bdmOptions.useResetSignal) {
            USBDM_ControlPins(PIN_RESET_3STATE);
            milliSleep(bdmOptions.resetReleaseInterval);
         }
         USBDM_ControlPins(PIN_RELEASE);
         milliSleep(bdmOptions.resetRecoveryInterval);
         break;
      case T_CFVx:
         // Specific power/pin sequence to enter BKGD mode
         USBDM_ControlPins(PIN_RESET_LOW|PIN_BKPT_LOW);
         rc = USBDM_SetTargetVdd(BDM_TARGET_VDD_ENABLE);
         milliSleep(bdmOptions.powerOnRecoveryInterval);
         USBDM_ControlPins(PIN_RESET_3STATE);
         milliSleep(bdmOptions.resetReleaseInterval);
         USBDM_ControlPins(PIN_RELEASE);
         milliSleep(bdmOptions.resetRecoveryInterval);
         break;
      case T_ARM_JTAG:
      case T_ARM_SWD:
         // To prevent watch-dog problems leave target in hardware RESET
         // The target will enter debug mode on 1st USBDM_Connect()
         USBDM_ControlPins(PIN_RESET_LOW);
         pendingResetRelease = true;
         log.print("ARM - Setting pending reset release\n");
         rc = USBDM_SetTargetVdd(BDM_TARGET_VDD_ENABLE);
         milliSleep(bdmOptions.powerOnRecoveryInterval);
         break;
      case T_MC56F80xx:
      case T_EZFLASH:
      case T_JTAG:
         rc = USBDM_SetTargetVdd(BDM_TARGET_VDD_ENABLE);
         milliSleep(bdmOptions.powerOnRecoveryInterval);
         break;
      default:
         log.print("Illegal target type\n");
         break;
   }
   return rc;
}

//! Execute debug command (various, see DebugSubCommands)
//!
//! @param usb_data - Command for BDM
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_Debug(unsigned char *usb_data) {
   unsigned int actualRxSize;
   LOGGING_Q;

   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_DEBUG;
   uint8_t command = usb_data[2];
   log.print("%s => 0x%2.2X, 0x%2.2X\n", getDebugCommandName(command), usb_data[3], usb_data[4]);
   USBDM_ErrorCode rc = bdm_usb_transaction(20, 20, usb_data, 1000, &actualRxSize);
   log.print("%s <= rc=%s, 0x%2.2X, 0x%2.2X, 0x%2.2X, 0x%2.2X\n",
                  getDebugCommandName(command), USBDM_GetErrorString(rc), usb_data[1], usb_data[2], usb_data[3], usb_data[4]);
   return rc;
}

//! Get status of the last command
//!
//! @return \n
//!     BDM_RC_OK          => OK \n
//!     BDM_RC_USB_ERROR   => USB failure \n
//!     other              => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_GetCommandStatus(void) {
   USBDM_ErrorCode rc;
   LOGGING_Q;

   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_GET_COMMAND_RESPONSE;
   rc = bdm_usb_transaction(2, 1, usb_data);
   log.print("=>%s\n", getErrorName(rc));

   return rc;
}

//! Fills user supplied structure with state of BDM communication channel
//!
//! @param USBDMStatus Pointer to structure to receive status, see \ref USBDMStatus_t
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_GetBDMStatus(USBDMStatus_t *USBDMStatus) {
   LOGGING_Q;

   unsigned          BDMStatus       = 0;
   USBDM_ErrorCode   rc;

   USBDMStatus->target_type = bdmState.targetType;

   // Poll the BDM
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_GET_BDM_STATUS;
   rc = bdm_usb_transaction(2, 3, usb_data);
   if (rc == BDM_RC_OK) {
      BDMStatus = (usb_data[1]<<8)+usb_data[2];
   }
   USBDMStatus->ackn_state   = (BDMStatus&S_ACKN)?ACKN:WAIT;
   USBDMStatus->reset_state  = (BDMStatus&S_RESET_STATE)?RSTO_INACTIVE:RSTO_ACTIVE; // Active LOW!
   USBDMStatus->reset_recent = (BDMStatus&S_RESET_DETECT)?RESET_DETECTED:NO_RESET_ACTIVITY;
   USBDMStatus->halt_state   = (BDMStatus&S_HALT)?TARGET_HALTED:TARGET_RUNNING;

   switch(BDMStatus&S_POWER_MASK) {
      case S_POWER_NONE : // Target has no power
         USBDMStatus->power_state = BDM_TARGET_VDD_NONE;      break;
      case S_POWER_EXT : // Target has external power
         USBDMStatus->power_state = BDM_TARGET_VDD_EXT;       break;
      case S_POWER_INT  : // Target has internal power
         USBDMStatus->power_state = BDM_TARGET_VDD_INT;       break;
      case S_POWER_ERR : // Target power error (internal but overload)
         USBDMStatus->power_state = BDM_TARGET_VDD_ERR;       break;
   };
   switch(BDMStatus&S_COMM_MASK) {
      case S_NOT_CONNECTED : // No connection with target
         USBDMStatus->connection_state = SPEED_NO_INFO;       break;
      case S_SYNC_DONE     : // Speed from BDM SYNC
         USBDMStatus->connection_state = SPEED_SYNC;          break;
      case S_GUESS_DONE    : // Speed guessed
         USBDMStatus->connection_state = SPEED_GUESSED;       break;
      case S_USER_DONE     : // Speed given by user
         USBDMStatus->connection_state = SPEED_USER_SUPPLIED; break;
   };
   switch(BDMStatus&S_VPP_MASK) {
      case S_VPP_OFF : // Programming Voltage off
         USBDMStatus->flash_state = BDM_TARGET_VPP_OFF;      break;
      case S_VPP_ON     : // Programming Voltage on
         USBDMStatus->flash_state = BDM_TARGET_VPP_ON;       break;
      case S_VPP_STANDBY : // Programming Voltage standby
         USBDMStatus->flash_state = BDM_TARGET_VPP_STANDBY;  break;
      case S_VPP_ERR    : // Error
         USBDMStatus->flash_state = BDM_TARGET_VPP_ERROR;    break;
   };
   log.print("=> %s\n", getBDMStatusName(USBDMStatus));
   return rc;
}

//! Connects to Target.
//!
//! This will cause the BDM module to attempt to connect to the Target.
//! In most cases the BDM module will automatically determine the connection
//! speed and successfully connect.  If unsuccessful, it may be necessary
//! to manually set the speed using set_speed().
//!
//! @return \n
//!     BDM_RC_OK  => OK \n
//!     other      => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_Connect(void) {
USBDM_ErrorCode rc;
   LOGGING;
   log.setLoggingLevel(10); // Always log connect sequence
   bdmState.activityFlag = BDM_ACTIVE;
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_CONNECT;
   rc = bdm_usb_transaction(2, 1, usb_data, 100);
   if (rc != BDM_RC_OK) {
      log.print("Basic connect failed, rc = %d\n", rc);
      return rc;
   }
   if ((bdmOptions.targetType == T_ARM_SWD) || (bdmOptions.targetType == T_ARM_JTAG)) {
      rc = armConnect(bdmOptions.targetType);
      // Don't retry if secured as it will upset detection
      if ((rc != BDM_RC_OK) && (rc != BDM_RC_SECURED)) {
         rc = armConnect(bdmOptions.targetType);
      }
      if (rc != BDM_RC_OK) {
         log.print("ARM connect, rc = %d\n", rc);
      }
   }
   if (pendingResetRelease) {
      // Release pending reset
      log.print("Releasing pending reset and waiting %d ms\n", bdmOptions.resetRecoveryInterval);
      pendingResetRelease = false;
      USBDM_ControlPins(PIN_RESET_3STATE);
      milliSleep(bdmOptions.resetRecoveryInterval);
   }
   return rc;
}

//! Sets the BDM communication speed.
//!
//! @param frequency => BDM Communication speed in kHz \n
//! - T_CFVx, T_JTAG, T_MC56F80xx : JTAG clock frequency \n
//! - RS08, HCS08, HCS12, CFV1    : BDM interface frequency \n
//!    Usually equal to the CPU Bus frequency. \n
//!    May be unrelated to bus speed if alternative BDM clock is in use. \n
//!    Once a speed is set then automatic speed determination (by sync etc)
//!    is disabled.  Automatic operation is restored by setting a speed of zero. \n
//!
//! @return \n
//!     BDM_RC_OK  => OK \n
//!     other      => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_SetSpeed( unsigned long frequency) {
   unsigned int value;
   LOGGING_Q;

   bdmState.activityFlag = BDM_ACTIVE;

   log.print("BDM Clk = %lukHz\n", frequency);

   switch (bdmState.targetType) {
      case T_HC12 :
      case T_S12Z :
      case T_HCS08 :
      case T_RS08 :
      case T_CFV1 :
         if (frequency == 0) {
            // A sync value of 0 restores automatic speed determination
            value = 0;
         }
         else {
         // BDM command value is length of SYNC pulse in 60MHz ticks
         // The SYNC pulse is 128 BDM clock cycles
         value = (60000UL * 128) / frequency;
         }
         break;
      case T_CFVx :
      case T_JTAG :
      case T_MC56F80xx:
      case T_ARM_JTAG:
      case T_ARM_SWD:
         // BDM command value is frequency in kHz. Should be less than 1/5 target clk
         bdmOptions.interfaceFrequency = frequency;
         value = frequency;
         break;
      default :
         return BDM_RC_ILLEGAL_COMMAND;
   }
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_SET_SPEED;
   usb_data[2] = (uint8_t)(value>>8);
   usb_data[3] = (uint8_t)value;
   return bdm_usb_transaction(4, 1, usb_data);
}

//! Get the BDM communication speed in kHz
//!
//! @param frequency => BDM Communication speed in kHz
//!
//! @return \n
//!     BDM_RC_OK  => OK \n
//!     other      => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_GetSpeed(unsigned long *frequency /* kHz */) {
   USBDM_ErrorCode rc;
   uint16_t value;
   LOGGING_Q;

   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_GET_SPEED;
   rc = bdm_usb_transaction(2, 3, usb_data);
   value = (usb_data[1]<<8)+usb_data[2];
   if ((rc != BDM_RC_OK)||(value == 0)) {
      *frequency = 1001; // default to safe 1MHz on error
   }
   else {
      switch (bdmState.targetType) {
      case T_HC12 :
      case T_S12Z :
      case T_HCS08 :
      case T_RS08 :
      case T_CFV1 :
         // BDM return value is length of SYNC pulse in 60MHz ticks
         // The SYNC pulse is 128 BDM clock cycles
         *frequency = (60000UL * 128) / value;
         break;
      case T_CFVx :
      case T_JTAG :
      case T_MC56F80xx:
      case T_ARM_JTAG:
      case T_ARM_SWD:
         // BDM command value is frequency in kHz. Should be less than 1/5 target clk
         *frequency = value;
         break;
      default :
         rc = BDM_RC_ILLEGAL_COMMAND;
         break;
      }
   }
   log.print("BDM Clk = %lu kHz\n", *frequency);
   return rc;
}

//! Get the BDM communication speed in Hz
//!
//! @param frequency => BDM Communication speed in Hz
//!
//! @return \n
//!     BDM_RC_OK  => OK \n
//!     other      => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_GetSpeedHz(unsigned long *frequency /* Hz */) {
   USBDM_ErrorCode rc;
   uint16_t value;
   LOGGING_Q;

   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_GET_SPEED;
   rc = bdm_usb_transaction(2, 3, usb_data);
   value = (usb_data[1]<<8)+usb_data[2];
   if ((rc != BDM_RC_OK)||(value == 0)) {
      *frequency = 8000000; // default to safe 8MHz on error
   }
   else {
      // BDM command value is length of SYNC pulse in 60MHz ticks
      // The SYNC pulse is 128 BDM clock cycles
      *frequency = (60000000UL/value) * 128;
   }
   log.print("Ticks = %d, BDM Clk = %lu Hz\n", value, *frequency);
   return rc;
}

//! Reads Target Status register byte
//!
//! @param BDMStatusReg => status register value read. \n
//! The register read depends on target:
//!  - HCS12   = BDMSTS, BDM Status register \n
//!  - HCS08   = BDCSCR, BDM Status & Control register \n
//!  - RS08    = BDCSCR, BDM Status & Control register \n
//!  - CFV1    = XCSR[31..24], Extended Configuration/Status Register \n
//!  - CFVx    = CSR, Configuration/Status Register (CSR)
//!
//! @return \n
//!     BDM_RC_OK  => OK \n
//!     other      => Error code - see \ref USBDM_ErrorCode
//!
//! @note \n
//!    The BDM may resynchronize/reconnect with the target before doing this read.
//!
USBDM_API
USBDM_ErrorCode USBDM_ReadStatusReg(unsigned long *BDMStatusReg) {
   USBDM_ErrorCode rc;
   static          int  pollCount          = 0;
   static          int  pollInterval       = 0;
   static unsigned long lastBDMStatusReg   = -1;
   LOGGING_Q;

   (void)pollCount;
   (void)lastBDMStatusReg;

#ifdef LOG
   int dummy              = FALSE;
#endif

   if ((bdmState.activityFlag&BDM_STATUSREG) != 0) {
      // Reset polling info
      pollCount      = 0;
      pollInterval   = 0;
      bdmState.activityFlag = (BDMActivityState_t) (bdmState.activityFlag & ~BDM_STATUSREG);
   }
#if USB_THROTTLE != 0
   if (++pollCount < pollInterval) {
      // Dummy the return value - don't poll BDM
      Sleep(10);
      *BDMStatusReg = lastBDMStatusReg;
      rc = BDM_RC_OK;
      dummy = TRUE;
   }
   else
#endif
   {
      // Actually poll the BDM
      usb_data[0] = 0;
      usb_data[1] = CMD_USBDM_READ_STATUS_REG;
      rc = bdm_usb_transaction(2, 5, usb_data);
      if (rc == BDM_RC_OK)
         *BDMStatusReg = (usb_data[1]<<24) +
                         (usb_data[2]<<16) +
                         (usb_data[3]<<8)  +
                         (usb_data[4]);
      else
         *BDMStatusReg = 0x00;
      if (pollInterval < 16) // increase polling interval
         pollInterval++;
      pollCount = 0;
   }
#ifdef LOG
   if (lastBDMStatusReg != *BDMStatusReg) {
      // Only report when changing
      const char *dummyString = dummy?"- dummy":"";

      log.print("Changed => 0x%lX = %s %s\n",
            *BDMStatusReg,
            getStatusRegName(bdmState.targetType,*BDMStatusReg),
            dummyString);
   }
   else {
      log.print("=> 0x%lX = %s\n",
            *BDMStatusReg,
            getStatusRegName(bdmState.targetType,*BDMStatusReg));
   }
#endif // LOG
   lastBDMStatusReg = *BDMStatusReg;
   return rc;
}

//! Write Target Control Register byte
//!
//! @param value => value to write
//! The register written depends on target:
//!  - HCS12 = BDMSTS, BDM Status register \n
//!  - HCS08 = BDCSCR, BDM Status & Control register \n
//!  - RS08  = BDCSCR, BDM Status & Control register \n
//!  - CFV1  = XCSR[31..24], Extended Configuration/Status Register \n
//!  - CFVx  not supported (Access CSR through writeControlReg())
//!
//! @return \n
//!     BDM_RC_OK  => OK \n
//!     other      => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_WriteControlReg(unsigned int value) {
   LOGGING_Q;

   bdmState.activityFlag = BDM_ACTIVE;

   log.print("reg=%s\n", getStatusRegName(bdmState.targetType, value));
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_WRITE_CONTROL_REG;
   usb_data[2] = 0;     // 32-bit BE
   usb_data[3] = 0;
   usb_data[4] = 0;
   usb_data[5] = (uint8_t)value;
   return bdm_usb_transaction(6, 1, usb_data);
}

//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
// Target run control

//!
//! Reset sequence for RS08/HCS08/HCS12/CFV1
//!
//! @param target_mode - Reset method \n
//!         RESET_DEFAULT/RESET_POWER/RESET_HARDWARE/RESET_SOFTWARE \n
//!        +RESET_SPECIAL/RESET_NORMAL
//!
static USBDM_ErrorCode resetHCS(TargetMode_t targetMode) {
   LOGGING_Q;
   USBDM_ErrorCode rc;
   TargetMode_t resetMethod = (TargetMode_t)(targetMode&RESET_METHOD_MASK);
   TargetMode_t resetMode   = (TargetMode_t)(targetMode&RESET_MODE_MASK);
   log.print("mode=%s\n", getTargetModeName((TargetMode_t)(resetMethod|resetMode)));
   if (resetMethod == RESET_DEFAULT) {
      if ((bdmOptions.targetType == T_HCS12) || (bdmOptions.targetType == T_S12Z)) {
         resetMethod = RESET_HARDWARE;
      }
      else {
         resetMethod = RESET_SOFTWARE;
      }
      log.print("modified=(%s)\n", getTargetModeName((TargetMode_t)(resetMethod|resetMode)));
   }
   if (resetMethod == RESET_POWER) {
      log.print("Power reset\n");
      rc = USBDM_SetTargetVdd(BDM_TARGET_VDD_DISABLE);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      milliSleep(bdmOptions.powerOffDuration);
      // Note - BKGD may have been set low by the
      // Vdd transition (auto connect interrupt code)
      if (resetMode == RESET_SPECIAL) {
         USBDM_ControlPins(PIN_RESET_LOW|PIN_BKGD_LOW);
      }
      else {
         USBDM_ControlPins(PIN_RESET_LOW|PIN_BKGD_3STATE);
      }
      rc = USBDM_SetTargetVdd(BDM_TARGET_VDD_ENABLE);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      milliSleep(bdmOptions.powerOnRecoveryInterval);
      USBDM_ControlPins(PIN_RESET_3STATE);
      milliSleep(bdmOptions.resetReleaseInterval);
      // Check for reset rise
      rc = USBDM_ControlPins(PIN_RESET_3STATE);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      USBDM_ControlPins(PIN_RELEASE);
      milliSleep(bdmOptions.resetRecoveryInterval);
      return BDM_RC_OK;
   }
   if (resetMethod == RESET_HARDWARE) {
      log.print("Hardware reset\n");
      if (resetMode == RESET_SPECIAL) {
         USBDM_ControlPins(PIN_RESET_LOW|PIN_BKGD_LOW);
      }
      else {
         USBDM_ControlPins(PIN_RESET_LOW|PIN_BKGD_3STATE);
      }
      milliSleep(bdmOptions.resetDuration);
      USBDM_ControlPins(PIN_RESET_3STATE);
      milliSleep(bdmOptions.resetReleaseInterval);
      // Check for reset rise
      rc = USBDM_ControlPins(PIN_RESET_3STATE);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      USBDM_ControlPins(PIN_RELEASE);
      milliSleep(bdmOptions.resetRecoveryInterval);
      return BDM_RC_OK;
   }
   // RESET_SOFTWARE must be done by BDM
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_TARGET_RESET;
   usb_data[2] = (resetMethod|resetMode);
   rc = bdm_usb_transaction(3, 1, usb_data);
   milliSleep(bdmOptions.resetRecoveryInterval);
   return rc;
}

//!
//! Reset sequence for CFVx
//!
//! @param target_mode - Reset method \n
//!         RESET_DEFAULT/RESET_POWER/RESET_HARDWARE \n
//!        +RESET_SPECIAL/RESET_NORMAL
//!
static USBDM_ErrorCode resetCFVx(TargetMode_t targetMode) {
   LOGGING_Q;
   USBDM_ErrorCode rc;
   TargetMode_t resetMethod = (TargetMode_t)(targetMode&RESET_METHOD_MASK);
   TargetMode_t resetMode   = (TargetMode_t)(targetMode&RESET_MODE_MASK);
   log.print("mode=%s\n", getTargetModeName((TargetMode_t)(resetMethod|resetMode)));
   if (resetMethod == RESET_DEFAULT) {
      resetMethod = RESET_HARDWARE;
      log.print("modified=(%s)\n", getTargetModeName((TargetMode_t)(resetMethod|resetMode)));
   }
   if (resetMethod == RESET_POWER) {
      USBDM_SetTargetVdd(BDM_TARGET_VDD_DISABLE);
      milliSleep(bdmOptions.powerOffDuration);
      if (resetMode == RESET_SPECIAL) {
         USBDM_ControlPins(PIN_RESET_LOW|PIN_BKPT_LOW);
      }
      else {
         USBDM_ControlPins(PIN_RESET_LOW|PIN_BKPT_3STATE);
      }
      USBDM_SetTargetVdd(BDM_TARGET_VDD_ENABLE);
      milliSleep(bdmOptions.powerOnRecoveryInterval);
      USBDM_ControlPins(PIN_RESET_3STATE);
      milliSleep(bdmOptions.resetReleaseInterval);
      // Check for reset rise
      rc = USBDM_ControlPins(PIN_RESET_3STATE);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      USBDM_ControlPins(PIN_RELEASE);
      milliSleep(bdmOptions.resetRecoveryInterval);
      return BDM_RC_OK;
   }
   if (resetMethod == RESET_HARDWARE) {
      if (resetMode == RESET_SPECIAL) {
         USBDM_ControlPins(PIN_RESET_LOW|PIN_BKPT_LOW);
      }
      else {
         USBDM_ControlPins(PIN_RESET_LOW|PIN_BKPT_3STATE);
      }
      milliSleep(bdmOptions.resetDuration);
      USBDM_ControlPins(PIN_RESET_3STATE);
      milliSleep(bdmOptions.resetReleaseInterval);
      // Check for reset rise
      rc = USBDM_ControlPins(PIN_RESET_3STATE);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      USBDM_ControlPins(PIN_RELEASE);
      milliSleep(bdmOptions.resetRecoveryInterval);
      return BDM_RC_OK;
   }
   return BDM_RC_ILLEGAL_PARAMS;
}

//!
//! Reset sequence for Other targets
//!
//! @param target_mode - Reset method \n
//!                         RESET_POWER/RESET_HARDWARE
//!
static USBDM_ErrorCode resetOther(TargetMode_t targetMode) {
   LOGGING_Q;
   USBDM_ErrorCode rc;
   TargetMode_t resetMethod = (TargetMode_t)(targetMode&RESET_METHOD_MASK);
   TargetMode_t resetMode   = (TargetMode_t)(targetMode&RESET_MODE_MASK);
   log.print("mode=%s\n", getTargetModeName((TargetMode_t)(resetMethod|resetMode)));
   if (resetMethod == RESET_DEFAULT) {
      resetMethod = RESET_HARDWARE;
      log.print("Modified=(%s)\n", getTargetModeName((TargetMode_t)(resetMethod|resetMode)));
   }
   if (resetMethod == RESET_POWER) {
      USBDM_SetTargetVdd(BDM_TARGET_VDD_DISABLE);
      milliSleep(bdmOptions.resetDuration);
      USBDM_ControlPins(PIN_RESET_LOW);
      USBDM_SetTargetVdd(BDM_TARGET_VDD_ENABLE);
      milliSleep(bdmOptions.resetReleaseInterval);
      USBDM_ControlPins(PIN_RELEASE);
      milliSleep(bdmOptions.resetRecoveryInterval);
      // Check for reset rise
      rc = USBDM_ControlPins(PIN_RESET_3STATE);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      return BDM_RC_OK;
   }
   if (resetMethod == RESET_HARDWARE) {
      USBDM_ControlPins(PIN_RESET_LOW);
      milliSleep(bdmOptions.resetDuration);
      USBDM_ControlPins(PIN_RELEASE);
      milliSleep(bdmOptions.resetRecoveryInterval);
      // Check for reset rise
      rc = USBDM_ControlPins(PIN_RESET_3STATE);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      return BDM_RC_OK;
   }
   return BDM_RC_ILLEGAL_PARAMS;
}

//! Resets the target to normal or special mode
//!
//! @param target_mode see
//!
//! @return \n
//!     BDM_RC_OK   => OK \n
//!     other       => Error code - see \ref USBDM_ErrorCode
//!
//! @note V4.4 onwards - Communication with the target may be lost.  It is necessary to use
//! USBDM_Connect() to re-connect.  This is no longer done automatically
//! as it may interfere with security checking if attempted too soon after reset.
//!
USBDM_API
USBDM_ErrorCode USBDM_TargetReset(TargetMode_t target_mode) {
   LOGGING;
   USBDM_ErrorCode rc;
   bdmState.activityFlag = BDM_ACTIVE;
   log.print("mode=%s\n", getTargetModeName(target_mode));

   switch (bdmState.targetType) {
   case T_HC12:
   case T_S12Z:
   case T_HCS08:
   case T_RS08:
   case T_CFV1:
      return resetHCS(target_mode);
   case T_CFVx:
      return resetCFVx(target_mode);
   case T_ARM_SWD:
   case T_ARM_JTAG:
      rc = resetARM(target_mode);
      if (pendingResetRelease) {
         // Clear pending reset
         log.print("Clearing pending reset flag\n");
         pendingResetRelease = false;
      }
      return rc;
   default:
      return resetOther(target_mode);
   }
}

//! Steps over a single target instruction
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_TargetStep(void) {
   LOGGING_E;

   bdmState.activityFlag = BDM_ACTIVE;

   usb_data[0] = 1;  // receive up to 1 byte
   usb_data[1] = CMD_USBDM_TARGET_STEP;
   return bdm_usb_transaction(2, 1, usb_data);
}

//! Starts target execution from current PC address
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_TargetGo(void) {
   LOGGING_E;

   bdmState.activityFlag = BDM_ACTIVE;

   usb_data[0] = 1;  // receive up to 1 byte
   usb_data[1] = CMD_USBDM_TARGET_GO;
   return bdm_usb_transaction(2, 1, usb_data);
}

//! Brings the target into active background mode.  The target will be halted.
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_TargetHalt(void) {
   LOGGING_E;

   bdmState.activityFlag = BDM_ACTIVE;

   usb_data[0] = 1;  // receive up to 1 byte
   usb_data[1] = CMD_USBDM_TARGET_HALT;
   return bdm_usb_transaction(2, 1, usb_data);
}

//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
// Target register Read/Write

//! Write Target Core register
//!
//! @param regNo    Register #
//!  - HCS12     = D,X,Y,SP,PC see \ref HCS12_Registers_t          \n
//!  - HCS08     = A,HX,SP,CCR,PC see \ref HCS08_Registers_t       \n
//!  - RS08      = CCR_PC,SPC,A see \ref RS08_Registers_t          \n
//!  - CFV1      = Core register space D0-D7, A0-A7 see \ref CFV1_Registers_t  \n
//!  - CFVx      = Core register space D0-D7, A0-A7 see \ref CFVx_Registers_t
//!  - JTAG_SWD  = ARM Core Registers see \ref ARM_Registers_t
//!  - JTAG_ARM  = ARM Core Registers see \ref ARM_Registers_t
//! @param regValue 8/16/32-bit value
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_WriteReg(unsigned int regNo, unsigned long regValue) {
   LOGGING_Q;

#ifdef LOG
   log.print("reg=%s(%d), 0x%lX\n",
         getRegName( bdmState.targetType, regNo ), regNo, regValue);
#endif

   bdmState.activityFlag = BDM_ACTIVE;

   // Reading HCS12 CCR from value saved in BDM address space!
   if ((bdmState.targetType == T_HC12) && (regNo == HCS12_RegCCR)) {
      return USBDM_WriteDReg(HCS12_DRegCCR, regValue);
   }
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_WRITE_REG;
   usb_data[2] = (uint8_t)(regNo>>8);
   usb_data[3] = (uint8_t)(regNo);
   usb_data[4] = (uint8_t)(regValue>>24);
   usb_data[5] = (uint8_t)(regValue>>16);
   usb_data[6] = (uint8_t)(regValue>>8);
   usb_data[7] = (uint8_t)(regValue);

   return bdm_usb_transaction(8, 1, usb_data);
}

//! Read Target Core register
//!
//! @param regNo    Register #
//!  - HCS12     = D,X,Y,SP,PC see \ref HCS12_Registers_t          \n
//!  - HCS08     = A,HX,SP,CCR,PC see \ref HCS08_Registers_t       \n
//!  - RS08      = CCR_PC,SPC,A see \ref RS08_Registers_t          \n
//!  - CFV1      = Core register space D0-D7, A0-A7, PSTBASE+n, see \ref CFV1_Registers_t  \n
//!  - CFVx      = Core register space D0-D7, A0-A7 see \ref CFVx_Registers_t
//!  - JTAG_SWD  = ARM Core Registers see \ref ARM_Registers_t
//!  - JTAG_ARM  = ARM Core Registers see \ref ARM_Registers_t
//! @param regValue 8/16/32-bit value
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
//! @note HCS12_RegCCR is accessed through \ref USBDM_ReadDReg()
//!
USBDM_API
USBDM_ErrorCode USBDM_ReadReg(unsigned int regNo, unsigned long *regValue) {
   LOGGING_Q;
   USBDM_ErrorCode rc;

//   bdmState.activityFlag = BDM_ACTIVE;

//   log.print("USBDM_readReg(%d)\n", regNo);

   // Read HCS12 CCR from value saved in BDM address space!
   if ((bdmState.targetType == T_HC12) && (regNo == HCS12_RegCCR)) {
      return USBDM_ReadDReg(HCS12_DRegCCR, regValue);
   }
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_READ_REG;
   usb_data[2] = (uint8_t)(regNo>>8);
   usb_data[3] = (uint8_t)(regNo);

   rc = bdm_usb_transaction(4, 5, usb_data);

   if (rc != BDM_RC_OK) {
      log.print("Failed - ID#=%X\n", regNo);
      *regValue = 0xDEADBEEFU;
   }
   else {
      *regValue = (usb_data[1]<<24) +
                  (usb_data[2]<<16) +
                  (usb_data[3]<<8)  +
                  (usb_data[4]);
   }
#ifdef LOG
   log.print("reg=%s => 0x%lX\n",
         getRegName( bdmState.targetType, regNo ), *regValue);
#endif

return rc;
}

//! Read Multiple Core registers
//!
//! @param regValueBuffer Values in Target byte order??
//! @param startRegIndex     Register index (inclusive) to start reading at
//! @param endRegIndex       Register index (inclusive) to stop reading at
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
//! @note The indexes mentioned above are magic numbers indexing an arbitrary table.\n
//!       Use only the predefined values provided in the USBDM_API.h  /ref ARM_RegisterIndex_t, /ref CFV1_RegisterIndex_t, /ref CFVx_RegisterIndex_t
//!
USBDM_API
USBDM_ErrorCode USBDM_ReadMultipleRegs(unsigned char regValueBuffer[], unsigned int startRegIndex, unsigned int endRegIndex) {
   LOGGING;
   USBDM_ErrorCode rc;

   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_READ_ALL_REGS;
   usb_data[2] = 0;
   usb_data[3] = (uint8_t)startRegIndex;
   usb_data[4] = (uint8_t)endRegIndex;

   int size = 4*(endRegIndex-startRegIndex+1); // # of data bytes to receive

   rc = bdm_usb_transaction(5, size+1, usb_data, 100);
   if (rc != BDM_RC_OK) {
      log.print("Failed - ID#=%X\n", size);
      memset(regValueBuffer, 0xAA, size);
   }
   else {
      memcpy(regValueBuffer, usb_data+1, size);
   }
#ifdef LOG
//   log.print("reg=%s => 0x%X\n",
//         getRegName( bdmState.targetType, regNo ), *regValue);
   log.print("reg=[#%d..#%d] =>\n", startRegIndex, endRegIndex);
   log.printDump(regValueBuffer, size);
#endif

return rc;
}

//! Write Target Control register
//!
//! @param regNo    Register #
//!    - HCS12     = not used \n
//!    - HCS08     = not used \n
//!    - RS08      = not used \n
//!    - CFV1      = Control register space, see \ref CFV1_CRegisters_t\n
//!    - CFVx      = Control register space, see \ref CFVx_CRegisters_t
//!    - JTAG_SWD  = AP memory space see \ref ARM_CRegisters_t
//!    - JTAG_ARM  = AP memory space see \ref ARM_CRegisters_t
//!
//! @param regValue 8/16/32-bit value
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_WriteCReg(unsigned int regNo, unsigned long regValue) {
   LOGGING_Q;

   bdmState.activityFlag = BDM_ACTIVE;

#ifdef LOG
   switch (bdmState.targetType) {
      case T_CFV1 :
         log.print("reg=%s(0x%X), 0x%lX\n",
               getCFV1ControlRegName(regNo), regNo, regValue);
         break;
      case T_CFVx :
         log.print("reg=%s(0x%X), 0x%lX\n",
               getCFVxControlRegName(regNo), regNo, regValue);
         break;
      case T_ARM_SWD :
      case T_ARM_JTAG :
         switch (regNo) {
         case ARM_CRegMDM_AP_Status:
            log.print("reg=MDM-AP.Status,  %s(0x%08lX)\n", getMDM_APStatusName((uint32_t)regValue), regValue);
            break;
         case ARM_CRegMDM_AP_Control:
            log.print("reg=MDM-AP.Control, %s(0x%08lX)\n", getMDM_APControlName((uint32_t)regValue),regValue);
            break;
         default:
            log.print("reg=%s(0x%X), 0x%08lX)\n", getARMControlRegName(regNo), regNo, regValue);
            break;
         }
         break;
      default :
         log.print("Failed - Unknown mode, register(0x%4X) = 0x%lX\n",
               regNo, regValue);
         break;
   };
#endif

   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_WRITE_CREG;
   if ((bdmState.targetType == T_ARM_SWD)||(bdmState.targetType == T_ARM_JTAG)) {
      // Register number is 'compressed into 2 bytes'
      usb_data[2] = (uint8_t)(regNo>>24);
   }
   else {
      usb_data[2] = (uint8_t)(regNo>>8);
   }
   usb_data[3] = (uint8_t)(regNo);
   usb_data[4] = (uint8_t)(regValue>>24);
   usb_data[5] = (uint8_t)(regValue>>16);
   usb_data[6] = (uint8_t)(regValue>>8);
   usb_data[7] = (uint8_t)(regValue);
   return bdm_usb_transaction(8, 1, usb_data);
}

//! Read Target Control register
//!
//! @param regNo    Register # or address
//!    - HCS12     = not used \n
//!    - HCS08     = not used \n
//!    - RS08      = not used \n
//!    - CFV1      = Control register space, see \ref CFV1_CRegisters_t\n
//!    - CFVx      = Control register space, see \ref CFVx_CRegisters_t \n
//!    - JTAG_SWD  = AP memory space see \ref ARM_CRegisters_t
//!    - JTAG_ARM  = AP memory space see \ref ARM_CRegisters_t
//!
//! @param regValue 8/16/32-bit value
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_ReadCReg(unsigned int regNo, unsigned long *regValue) {
   LOGGING_Q;
   USBDM_ErrorCode rc;

//   bdmState.activityFlag = BDM_ACTIVE;

   *regValue = 0xAAAA;

   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_READ_CREG;
   if ((bdmState.targetType == T_ARM_SWD)||(bdmState.targetType == T_ARM_JTAG)) {
      // Register number is 'compressed into 2 bytes'
      usb_data[2] = (uint8_t)(regNo>>24);
   }
   else {
      usb_data[2] = (uint8_t)(regNo>>8);
   }
   usb_data[3] = (uint8_t)(regNo);

   rc = bdm_usb_transaction(4, 5, usb_data);

   if (rc != BDM_RC_OK) {
      log.print("Failed - reg=0x%X\n", regNo);
      *regValue = 0x0U;
   }
   else {
      *regValue = (usb_data[1]<<24) +
                  (usb_data[2]<<16) +
                  (usb_data[3]<<8)  +
                  (usb_data[4]);
   }
#ifdef LOG
   switch (bdmState.targetType) {
      case T_CFV1 :
         log.print("reg=%s(0x%X), 0x%lX\n", getCFV1ControlRegName(regNo), regNo, *regValue);
         break;
      case T_CFVx :
         log.print("reg=%s(0x%X), 0x%lX\n", getCFVxControlRegName(regNo), regNo, *regValue);
         break;
      case T_ARM_SWD :
      case T_ARM_JTAG :
         switch (regNo) {
         case ARM_CRegMDM_AP_Status:
            log.print("reg=MDM-AP.Status,  %s(0x%08lX)\n", getMDM_APStatusName(*regValue), *regValue);
            break;
         case ARM_CRegMDM_AP_Control:
            log.print("reg=MDM-AP.Control, %s(0x%08lX)\n", getMDM_APControlName(*regValue),*regValue);
            break;
         default:
            log.print("reg=%s(0x%X), 0x%08lX\n", getARMControlRegName(regNo), regNo, *regValue);
            break;
         }
         break;
      default :
         log.print("Failed - Unknown mode, register(0x%4X) = 0x%lX\n", regNo, *regValue);
         break;
   };
#endif
   return rc;
}
//! Write Target Debug register
//!
//! @param regNo    Register #
//!   - HCS12     = BD memory space, see \ref HCS12_DRegisters_t   \n
//!   - HCS08     = BKPT register, see \ref HCS08_DRegisters_t   \n
//!   - RS08      = BKPT register, see \ref RS08_DRegisters_t   \n
//!   - CFV1      = Debug register space, see \ref CFV1_DRegisters_t\n
//!   - CFVx      = Debug register space, see \ref CFVx_DRegisters_t
//!   - JTAG_SWD  = DP/AP Registers see \ref ARM_DRegisters_t
//!   - JTAG_ARM  = DP/AP Registers see \ref ARM_DRegisters_t
//! @param regValue 8/16/32-bit value
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_WriteDReg(unsigned int regNo, unsigned long regValue) {
   LOGGING_Q;

   bdmState.activityFlag = BDM_ACTIVE;
#ifdef LOG
   switch (bdmState.targetType) {
      case T_HC12 :
         log.print("%s(0x%X) <= 0x%lX\n",
               getHCS12DebugRegName(regNo), regNo, regValue);
         break;
      case T_HCS08 :
         log.print("BKPT <= 0x%lX\n", regValue);
         break;
      case T_RS08 :
         log.print("BKPT <= 0x%lX\n", regValue);
         break;
      case T_CFV1 :
         log.print("%s(0x%X) <= 0x%lX\n",
               getCFV1DebugRegName(regNo), regNo, regValue);
         break;
      case T_CFVx :
         log.print("%s(0x%X) <= 0x%lX\n",
               getCFVxDebugRegName(regNo), regNo, regValue);
         break;
      case T_ARM_SWD :
      case T_ARM_JTAG :
         if (regNo == ARM_DRegCONTROL) {
            log.print("reg=%s(0x%X) <= %s)\n", getSWDDebugRegName(regNo), regNo, getARM_CTRL_STATUSRName(regValue));
         }
         else {
            log.print("%s(0x%X) <= 0x%lX\n", getSWDDebugRegName(regNo), regNo, regValue);
         }
         break;
      default :
         log.print("Unknown mode, register(0x%4X) <= 0x%lX\n",
               regNo, regValue);
         break;
   };
#endif

//   if ((bdmState.targetType == T_CFV1) && (regNo == CFV1_DRegCSR)) {
//      // MCF51AC Hack
//      log.print("Setting CSR.VBD bit CSR=%08X\n", regValue);
//      regValue |= CFV1_CSR_VBD;
//   }
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_WRITE_DREG;
   usb_data[2] = (uint8_t)(regNo>>8);
   usb_data[3] = (uint8_t)(regNo);
   usb_data[4] = (uint8_t)(regValue>>24);
   usb_data[5] = (uint8_t)(regValue>>16);
   usb_data[6] = (uint8_t)(regValue>>8);
   usb_data[7] = (uint8_t)(regValue);
   return bdm_usb_transaction(8, 1, usb_data);
}

//! Read Target Debug register
//!
//! @param regNo    Register #
//!   - HCS12     = BD memory space, see \ref HCS12_DRegisters_t   \n
//!   - HCS08     = BKPT register, see \ref HCS08_DRegisters_t   \n
//!   - RS08      = BKPT register, see \ref RS08_DRegisters_t   \n
//!   - CFV1      = Debug register space, see \ref CFV1_DRegisters_t\n
//!   - CFVx      = Debug register space, see \ref CFVx_DRegisters_t
//!   - JTAG_SWD  = DP/AP Registers see \ref ARM_DRegisters_t
//!   - JTAG_ARM  = DP/AP Registers see \ref ARM_DRegisters_t
//! @param regValue 8/16/32-bit value
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_ReadDReg(unsigned int regNo, unsigned long *regValue) {
   LOGGING_Q;
   USBDM_ErrorCode rc;

//   bdmState.activityFlag = BDM_ACTIVE;
//   log.print("USBDM_readDReg(0x%X, 0x%X)\n", regNo, regValue);
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_READ_DREG;
   usb_data[2] = (uint8_t)(regNo>>8);
   usb_data[3] = (uint8_t)(regNo);
   rc = bdm_usb_transaction(4, 5, usb_data);
   if (rc != BDM_RC_OK) {
      log.print("Failed - reg = 0x%X\n", regNo);
      *regValue = 0x0U;
   }
   else {
      *regValue = (usb_data[1]<<24) +
                  (usb_data[2]<<16) +
                  (usb_data[3]<<8)  +
                  (usb_data[4]);
   }
#ifdef LOG
   switch (bdmState.targetType) {
      case T_HC12 :
         log.print("%s(0x%X) => 0x%lX\n",
               getHCS12DebugRegName(regNo), regNo, *regValue);
         break;
      case T_HCS08 :
         log.print("BKPT => 0x%lX\n", *regValue);
         break;
      case T_RS08 :
         log.print("BKPT => 0x%lX\n", *regValue);
         break;
      case T_CFV1 :
         log.print("%s(0x%X) => 0x%lX\n",
                  getCFV1DebugRegName(regNo), regNo, *regValue);
         break;
      case T_CFVx :
         log.print("%s(0x%X) => 0x%lX=>%s\n",
                  getCFVxDebugRegName(regNo), regNo, *regValue,
                  getCFVx_CSR_Name(*regValue));
         break;
      case T_ARM_SWD :
      case T_ARM_JTAG :
         if (regNo == ARM_DRegCONTROL) {
            log.print("reg=%s(0x%X) => %s)\n", getSWDDebugRegName(regNo), regNo, getARM_CTRL_STATUSRName(*regValue));
         }
         else {
            log.print("%s(0x%X) => 0x%lX\n", getSWDDebugRegName(regNo), regNo, *regValue);
         }
         break;
      default :
         log.print("Failed - Unknown mode, register(0x%4X) => 0x%lX\n",
               regNo, *regValue);
         break;
   };
#endif
   return rc;
}

//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
//  Memory read write


//=======================================================================
//! Assemble a memory read/write message header into the usb data buffer
//!
//! @param command     = Target command
//! @param memorySpace = Memory space & size of data elements (1/2/4)
//! @param count       = Count of bytes to transfer
//! @param address     = Memory address
//! \verbatim
//! +---+----------------------------------+ \n
//! | 0 |   uint8_t: --------              | \n
//! +---+----------------------------------+ \n
//! | 1 |   uint8_t: command               | \n
//! +---+----------------------------------+ \n
//! | 2 |   uint8_t: memorySpace (1/2/4)   | \n
//! +---+----------------------------------+ \n
//! | 3 |   uint8_t: count                 | \n
//! +---+----------------------------------+ \n
//! | 4 |                                  | \n
//! +---+-                                -+ \n
//! | 5 |                                  | \n
//! +---+-  uint32_t: address             -+ \n
//! | 6 |   (BigEndian)                    | \n
//! +---+-                                -+ \n
//! | 7 |                                  | \n
//! +---+----------------------------------+ \n
//! | 8 |                                  | \n
//! +---+-  uint8_t[]: Data               -+ \n
//! ~   ~                                  ~ \n
//! +---+----------------------------------+ \n
//! \endverbatim
static void assembleMessageHeader(uint8_t command,
                                  uint8_t memorySpace,
                                  uint8_t count,
                                  uint32_t address) {
   U32u temp;
   usb_data[0] = 0;
   usb_data[1] = command;
   usb_data[2] = memorySpace; // or size
   usb_data[3] = count;
   temp.longword = address;
   usb_data[4] = temp.bytes[3]; // LittleEndian -> BigEndian
   usb_data[5] = temp.bytes[2];
   usb_data[6] = temp.bytes[1];
   usb_data[7] = temp.bytes[0];

#if MESSAGE_HEADER_SIZE != 8
#error "MESSAGE_HEADER_SIZE IS INCORRECT"
#endif
}

//=======================================================================
//! Write data to target memory
//!
//! @param memorySpace = Size of data elements (1/2/4 bytes)
//! @param byteCount   = Number of _bytes_ to transfer
//! @param address     = Memory address
//! @param data        = Ptr to block of data to write
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_WriteMemory( unsigned int        memorySpace,
                                   unsigned int        byteCount,
                                   unsigned int        address,
                                   unsigned const char *data) {
   LOGGING_Q;
   if (log.getLoggingLevel()>=0) {
      // Turn off Logg below this level
      log.setLoggingLevel(0);
   }
   unsigned blockSize;
   unsigned elementSize = memorySpace&MS_SIZE;
   USBDM_ErrorCode rc, stickyRc=BDM_RC_OK;

   // Make multiple of 4, allow for header
   const unsigned int MaxDataSize = (bdmInfo.commandBufferSize-MESSAGE_HEADER_SIZE)&~0x03;

   bdmState.activityFlag = BDM_ACTIVE;

   log.print("elementSize=%d, count=0x%X(%d), addr=[%s0x%06X..0x%06X]\n",
         elementSize, byteCount, byteCount, getMemSpaceAbbreviatedName((MemorySpace_t)memorySpace), address, address+byteCount-1);

   log.printDump(data, byteCount, address);

#ifdef FIX_ALIGNMENT
   // Check size alignment
   bool unaligned = false;
   switch (elementSize) {
      case 1: unaligned = false;                // No alignment requirement
         break;
      case 2: unaligned = ((byteCount&1) != 0); // Multiple of 2
         break;
      case 4: unaligned = ((byteCount&3) != 0); // Multiple of 4
         break;
      default: unaligned = 1;                   // Impossible
         break;
   }
   if (unaligned) {
      log.error("Failed - alignment (size of transfer) error\n");
      return BDM_RC_ILLEGAL_PARAMS;
   }
   // Check address alignment & adjust memory space
   switch (elementSize) {
      default:
      case 1:   // No alignment requirement
         break;
      case 2:   // Multiple of 2
         if ((address&1) != 0) {
            // Change to byte transfer
            unaligned = true;
            memorySpace = (memorySpace&~MS_SIZE)|1;
         }
         break;
      case 4:   // Multiple of 4
         if ((address&1) != 0) {
            // Change to byte transfer
            unaligned = true;
            memorySpace = (memorySpace&~MS_SIZE)|1;
         }
         else if ((address&2) != 0) {
            // Change to word transfer
            unaligned = true;
            memorySpace = (memorySpace&~MS_SIZE)|2;
         }
         break;
   }
   if (unaligned) {
      log.print("Alignment error - adjusted memory space size\n");
   }
#else
   bool unaligned = false;
   // Check address & size alignment
   switch (elementSize) {
      case 1:  unaligned = 0;               // No alignment requirement
         break;
      case 2:  unaligned = ((address&1) != 0) || ((byteCount&1) != 0); // Multiple of 2
         break;
      case 4:  unaligned = ((address&3) != 0) || ((byteCount&3) != 0); // Multiple of 4
         break;
      default: unaligned = 1;               // No alignment requirement
         break;
   }
   if (unaligned) {
      log.print("Failed - alignment error\n");
      return BDM_RC_ILLEGAL_PARAMS;
   }
#endif
//   log.printDump(data, count);

   while (byteCount>0) {
      blockSize = byteCount;
      if (blockSize > MaxDataSize) {
         blockSize = MaxDataSize;
      }
      if ((bdmState.targetType == T_HC12) && ((memorySpace&MS_SPACE) == MS_Global)) {
         // Make sure HCS12 Global access doesn't cross page boundary
         uint32_t nextPageBoundary = (address + 0x10000UL)&~0xFFFFUL;
         if ((address+blockSize-1) >= nextPageBoundary) {
            log.print("Access split due to Global boundary, A=0x%X, B=0x%X\n", address, nextPageBoundary);
            blockSize = nextPageBoundary-address;
         }
      }
      if ((bdmState.targetType == T_ARM_SWD)||(bdmState.targetType == T_ARM_JTAG)) {
         // Make sure ARM memory access doesn't cross 2^10 boundary as limitation of MDM-AP
         uint32_t nextPageBoundary = (address + (1UL<<10))&~((1UL<<10)-1);
         if ((address+blockSize-1) >= nextPageBoundary) {
            log.print("Access split due to crossing 2^10 boundary, A=0x%X, B=0x%X\n", address, nextPageBoundary);
            blockSize = nextPageBoundary-address;
         }
      }
      assembleMessageHeader( CMD_USBDM_WRITE_MEM, // Command
                             memorySpace,         // Size of data element
                             blockSize,           // # of elements to Tx,
                             address              // Memory address
                            );
//      log.print("  USBDM_WriteMemory-pkt(addr=0x%8X, blocksize=%6d, memorySpace=%2d)\n",
//            address, blockSize, memorySpace);
      //log.printDump(data, blockSize);
      memcpy(usb_data+MESSAGE_HEADER_SIZE, data, blockSize);
      rc = bdm_usb_transaction(blockSize+MESSAGE_HEADER_SIZE, 1, usb_data, 100);
      if ((rc == BDM_RC_USB_RETRY_OK)) {
         stickyRc = BDM_RC_USB_RETRY_OK;
      }
      if ((rc != BDM_RC_OK) && (rc != BDM_RC_USB_RETRY_OK)) {
         return rc;
      }
      data        += blockSize;   // update location in buffer
      address     += blockSize;   // update memory address
      byteCount   -= blockSize;   // update count
   }
   return stickyRc;
}

//=======================================================================
//! Read data from target memory
//!
//! @param elementSize = Size of data (1/2/4 bytes)
//! @param byteCount   = Number of bytes to transfer
//! @param address     = Memory address
//! @param data        = Where to place data
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_ReadMemory( unsigned int  memorySpace,
                                  unsigned int  byteCount,
                                  unsigned int  address,
                                  unsigned char *data) {
   LOGGING_Q;
   if (log.getLoggingLevel()>=0) {
      // Turn off Log below this level
      log.setLoggingLevel(0);
   }
   USBDM_ErrorCode rc, stickyRc = BDM_RC_OK;
   unsigned int   blockSize;
   unsigned int   originalCount   = byteCount;
   unsigned char *originalData    = data;
   unsigned int   originalAddress = address;
   unsigned int   elementSize     = memorySpace&MS_SIZE;

   // Make multiple of 4, Allow for status byte
   const unsigned int MaxDataSize = (bdmInfo.commandBufferSize-1)&~0x03;

   bdmState.activityFlag = BDM_ACTIVE;

   log.print("elementSize=%d, count=0x%X(%d), addr=[%s0x%06X..0x%06X]\n",
          elementSize, byteCount, byteCount, getMemSpaceAbbreviatedName((MemorySpace_t)memorySpace), address, address+byteCount-1);

   #ifdef FIX_ALIGNMENT
   // Check size alignment
   bool unaligned = false;
   switch (elementSize) {
      case 1: unaligned = false;                // No alignment requirement
         break;
      case 2: unaligned = ((byteCount&1) != 0); // Multiple of 2
         break;
      case 4: unaligned = ((byteCount&3) != 0); // Multiple of 4
         break;
      default: unaligned = 1;                   // Impossible
         break;
   }
   if (unaligned) {
      log.error("Failed - alignment (size of transfer) error\n");
      return BDM_RC_ILLEGAL_PARAMS;
   }
   // Check address alignment & adjust memory space
   switch (elementSize) {
      default:
      case 1:   // No alignment requirement
         break;
      case 2:   // Multiple of 2
         if ((address&1) != 0) {
            // Change to byte transfer
            unaligned = true;
            memorySpace = (memorySpace&~MS_SIZE)|1;
         }
         break;
      case 4:   // Multiple of 4
         if ((address&1) != 0) {
            // Change to byte transfer
            unaligned = true;
            memorySpace = (memorySpace&~MS_SIZE)|1;
         }
         else if ((address&2) != 0) {
            // Change to word transfer
            unaligned = true;
            memorySpace = (memorySpace&~MS_SIZE)|2;
         }
         break;
   }
   if (unaligned) {
      log.print("Alignment error - adjusted memory space size\n");
   }
#else
   // Check address and size alignment
   bool unaligned;
   switch (elementSize) {
      case 1: unaligned = 0;               // No alignment requirement
         break;
      case 2: unaligned = ((address&1) != 0) || ((byteCount&1) != 0); // Multiple of 2
         break;
      case 4: unaligned = ((address&3) != 0) || ((byteCount&3) != 0); // Multiple of 4
         break;
      default: unaligned = 1;               // No alignment requirement
         break;
   }
   if (unaligned) {
      log.error("Failed - alignment error\n");
      return BDM_RC_ILLEGAL_PARAMS;
   }
#endif
   while (byteCount>0) {
      blockSize = byteCount;
      if (blockSize > MaxDataSize) {
         blockSize = MaxDataSize;
      }
      if ((bdmState.targetType == T_HC12) && ((memorySpace&MS_SPACE) == MS_Global)) {
         log.print("Global Access 0x%6X\n", address);
         // Make sure HCS12 Global access doesn't cross page boundary
         uint32_t nextPageBoundary = (address + 0x10000UL)&~0xFFFFUL;
         if ((address+blockSize-1) >= nextPageBoundary) {
            log.print("Access split due to Global boundary, A=0x%X, B=0x%X\n", address, nextPageBoundary);
            blockSize = nextPageBoundary-address;
         }
      }
      if ((bdmState.targetType == T_ARM_SWD) || (bdmState.targetType == T_ARM_JTAG)) {
         // Make sure ARM memory access doesn't cross 2^10 boundary as limitation of MDM-AP
         uint32_t nextPageBoundary = (address + (1UL<<10))&~((1UL<<10)-1);
         if ((address+blockSize-1) >= nextPageBoundary) {
            log.print("Access split due to crossing 2^10 boundary, A=0x%X, B=0x%X\n", address, nextPageBoundary);
            blockSize = nextPageBoundary-address;
         }
      }
      assembleMessageHeader( CMD_USBDM_READ_MEM, // Command
                             memorySpace,        // Size of data element
                             blockSize,          // # of bytes to Rx,
                             address             // Memory address
                            );
//      log.print("  USBDM_ReadMemory-pkt(addr=0x%8X, blocksize=%3d, memorySpace=%2d)\n",
//            address, blockSize, memorySpace);
      rc = bdm_usb_transaction(MESSAGE_HEADER_SIZE, blockSize+1, usb_data, 100);
      if ((rc == BDM_RC_USB_RETRY_OK)) {
         stickyRc = BDM_RC_USB_RETRY_OK;
      }
      if ((rc != BDM_RC_OK) && (rc != BDM_RC_USB_RETRY_OK)) {
         return rc;
      }
      memcpy(data, usb_data+1, blockSize);
      //log.printDump(data, blockSize);

      data        += blockSize;   // update destination in buffer
      address     += blockSize;   // update address
      byteCount   -= blockSize;   // update count
   }
   log.printDump(originalData, originalCount, originalAddress);

   return stickyRc;
}

#if 0

//! (RS08) Prepare for RS08 Flash programming
//!
//!  This routine does the following:
//!   - Resets the target
//!   - Re-connects
//!   - Checks that the target SDID is correct for the target selected.
//!   - Disables the COP on the target
//!   - Downloads the Flash programming code into the direct memory of
//!     the RS08 target and then verifies this by reading it back.
//!   - Starts the target program execution (program will be idle).
//!   - Instructs the BDM to enable the Flash programming voltage
//!
//!  USBDM_RS08WriteFlash() may now be be used to program blocks of data
//!     to the RS08 Flash.
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_RS08FlashProgramPreamble(void) {
   LOGGING_Q;
   uint8_t buff[200];
   int rc;
   uint16_t SDIDValue;
   //const unsigned int defaultTrimFrequency = 4000; // kHz
   //const unsigned int defaultTrimValue     = 256;

   bdmState.activityFlag = BDM_ACTIVE;

   log.print("USBDM_RS08FlashProgramPreamble()\n");

   bdmState.flashState = FLASH_Idle; // Assume fail!

   // Check if RS08 derivative is set
   if (RS08_FlashInfo == NULL) {
      log.print("USBDM_RS08FlashProgramPreamble() - Flash parameters not set\n");
      return BDM_RC_ILLEGAL_PARAMS;
   }
   rc = USBDM_TargetReset(RESET_SOFTWARE|RESET_SPECIAL);
   if (rc != BDM_RC_OK) {
      log.print("USBDM_RS08FlashProgramPreamble() - Failed Reset\n");
      return rc;
   }
   // Make sure we have a target connection
   rc = USBDM_Connect();
   if (rc != BDM_RC_OK) {
      log.print("USBDM_RS08FlashProgramPreamble() - Failed Connect\n");
      return rc;
   }
   // Check the target System Device IDentification register
   rc = USBDM_ReadMemory(1, 2, RS08_FlashInfo->SDIDAddress, buff );
   if (rc != BDM_RC_OK)
      return rc;
   SDIDValue = ((buff[0]<<8)+buff[1]) & 0x0FFF;
   if (SDIDValue != RS08_FlashInfo->SDIDValue) {
      MessageBox( NULL,          // HWND hWnd,
                  "The RS08 Derivative selected does not appear to agree with the target device connected.\n\n"
                  "To protect the device, VPP will NOT be enabled and the device will NOT be programmed.\n\n"
                  "Please restart the debugger.",
                  "Wrong RS08 Derivative",
                  MB_ICONERROR|MB_DEFBUTTON1|MB_TASKMODAL|MB_SETFOREGROUND
                  );
      log.print("USBDM_RS08FlashProgramPreamble() - wrong SDID, expected %4X, found %4X\n",
            RS08_FlashInfo->SDIDValue,
            SDIDValue);
      return BDM_RC_ILLEGAL_PARAMS;
   }
   // Disable Target COP
   uint8_t SOPTValue = RS08_SOPT_BKGDPE;
   rc = USBDM_WriteMemory(1, 1, RS08_FlashInfo->SOPTAddress, &SOPTValue);
   if (rc != BDM_RC_OK)
      return rc;

   // Write Flash programming code to Target memory
   rc = USBDM_WriteMemory(1,
                          RS08_FlashInfo->programLength,
                          RS08_FlashInfo->directRamStart,
                          RS08_FlashInfo->program );
   if (rc != BDM_RC_OK)
      return rc;

   // Read back to verify
   rc = USBDM_ReadMemory(1,
                         RS08_FlashInfo->programLength,
                         RS08_FlashInfo->directRamStart,
                         buff );
   if (rc != BDM_RC_OK)
      return rc;

   // Verify correctly loaded
   if (memcmp(buff,
              RS08_FlashInfo->program,
              RS08_FlashInfo->programLength) != 0) {
      log.print("USBDM_RS08FlashProgramPreamble() - program load verify failed\n");
      return BDM_RC_FAIL;
   }
   // Start flash code on target
   rc = USBDM_WriteReg(RS08_RegCCR_PC, RS08_FlashInfo->directRamStart);
   if (rc != BDM_RC_OK)
      return rc;

   rc = USBDM_TargetGo();
   if (rc != BDM_RC_OK)
      return rc;

   return USBDM_SetTargetVpp(BDM_TARGET_VPP_ON);
}

//! (RS08) Check status of RS08 Flash programming
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_RS08FlashStatus(void) {
   LOGGING_Q;
   int rc;
   USBDMStatus_t      USBDMStatus;

   bdmState.activityFlag = BDM_ACTIVE;

   log.print("USBDM_RS08FlashStatus()\n");

   if (bdmState.flashState != FLASH_Ready)
      return BDM_RC_WRONG_PROGRAMMING_MODE;

   rc = USBDM_GetBDMStatus(&USBDMStatus);
   if (rc != BDM_RC_OK)
      return rc;

   if (USBDMStatus.flash_state != FLASH_Ready)
      return BDM_RC_WRONG_PROGRAMMING_MODE;

   return BDM_RC_OK;
}

//! (RS08) Tidy up after Flash programming
//!
//! - Restore/program clock trim value
//! - Vpp off
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_RS08FlashProgramPostamble(void){
   LOGGING_Q;
   USBDMStatus_t   USBDMStatus;
   USBDM_ErrorCode rc;

   bdmState.activityFlag = BDM_ACTIVE;

   log.print("USBDM_RS08FlashProgramPostamble()\n");

   (void) USBDM_GetBDMStatus(&USBDMStatus);

#if 0
   // Don't try to restore Trim in error situation
   if ((savedTrimValue != 0) &&
       (RS08_FlashInfo != NULL) &&
       (bdmState.flashState == FLASH_Ready)) {
      // Retrieve the clock trim value from the RS08 Flash
      // This value may have been programmed as part of the user code image
      rc = USBDM_ReadMemory(1, 2, RS_TRIM_FLASH, buff );
      if ((rc == BDM_RC_OK) && (buff[0] == 0xFF) && (buff[1] == 0xFF)) {
         // Current Flash trim is unprogrammed

         // Program the trim value to Flash
         // Note: BDM is still in Flash programming mode!
         buff[0] = (uint8_t)(savedTrimValue>>1);
         buff[1] = (uint8_t)(savedTrimValue&0x01);
         USBDM_WriteMemory(1, 2, RS_TRIM_FLASH, buff );

         // Read back to verify
         rc = USBDM_ReadMemory(1, 2, RS_TRIM_FLASH, buff+2 );
         if ((rc != BDM_RC_OK) || (buff[0] != buff[2]) || (buff[1] != buff[3])) {
            log.print("USBDM_RS08FlashProgramPostamble() - Failed Trim programming\n");
         }
      }
   }
#endif

   bdmState.flashState = FLASH_Idle;

   // Turn off Flash programming
   rc = USBDM_SetTargetVpp(BDM_TARGET_VPP_OFF);
   return rc;
}

//=============================================================================
//! Calculate delay value for Flash programming. \n
//! See flash program for calculation method.
//!
//! @param delayValue  = Delay value passed to target program
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_ErrorCode USBDM_RS08CalculateFlashDelay(uint8_t *delayValue) {
   LOGGING_Q;
   unsigned long bdmFrequency;
   double busFrequency;
   USBDM_ErrorCode rc;

   rc = USBDM_GetSpeedHz(&bdmFrequency);
   if (rc != BDM_RC_OK)
      return rc;

   busFrequency = bdmFrequency;
   *delayValue = round(((busFrequency*30E-6)-30-10)/4);

   log.print("USBDM_RS08CalculateFlashDelay() => %d\n", *delayValue);
   return BDM_RC_OK;
}

//==================================================================================
//! Write data to RS08 Flash memory - (within a single page of Flash, & buffer size)
//!
//! @param byteCount   = Number of bytes to transfer
//! @param address     = Memory address
//! @param data        = Ptr to block of data to write
//! @param delayValue  = Delay value for target program
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
static
USBDM_ErrorCode USBDM_RS08WriteFlashBlock( unsigned int        byteCount,
                                          unsigned int        address,
                                          unsigned const char *data,
                                          uint8_t                  delayValue) {
   LOGGING_Q;
   int rc;
   uint8_t flashCommand[14]  = {0x00};
   uint8_t flashStatus;
//   const uint32_t PTADAddress  = 0x10;
//   const uint8_t  zero    = 0x00;
//   const uint8_t  allOnes = 0xFF;

   log.print("USBDM_RS08WriteFlashBlock(count=0x%X(%d), addr=[0x%06X..0x%06X])\n",
         byteCount, byteCount, address, address+byteCount-1);

   bdmState.activityFlag = BDM_ACTIVE;

   if (bdmState.flashState != FLASH_Ready) {
      return BDM_RC_WRONG_PROGRAMMING_MODE;
   }

   // 0000     FLCRAddress       dc.b     HIGH_6_13(FLCR)                 ; Page # for FLCR Reg
   // 0001     Buffer            dc.b     $11,$22,$33,$44,$55,$66,$77,$88 ; Buffer for data to program (<= 8 bytes)
   // 0009     DestinationAddr   dc.b     MAP_ADDR_6(Destination)         ; Address in Paging Window for destination
   // 000A     DestinationPage   dc.b     HIGH_6_13(Destination)          ; Page for destination
   // 000B     DelayValue        dc.b     22                              ; Delay value (4MHz=>N=22, 8MHz=>N=44)
   // 000C     SourceAddr        dc.b     Buffer                          ; Address in Zero Page buffer for source
   // 000D     ByteCount         dc.b     BufferSize                      ; # of byte to write <page & buffer size

   // Set up data to write
   flashCommand[0x0] = RS08_PAGENO(RS08_FlashInfo->FLCRAddress);
   if (byteCount<=8) {
      // Use tiny buffer
      int sub;
      for(sub=1; sub<=byteCount; sub++) {
         flashCommand[sub] = *data++;
      }
   }
   flashCommand[0x9] = RS08_WIN_ADDR(address);
   flashCommand[0xA] = RS08_PAGENO(address);
   flashCommand[0xB] = delayValue;
   flashCommand[0xC] = 1; // default to tiny buffer
   flashCommand[0xD] = byteCount;

   // If any of the following fail disable flash voltage
   do {
      // Transfer data to flash programming code
//      USBDM_WriteMemory(1, 1, PTADAddress,  &allOnes);
      if (byteCount>8) {
         // Using large buffer
         rc = USBDM_WriteMemory(1,
                                byteCount,
                                RS08_FlashInfo->directRamStart+
                                   RS08_FlashInfo->programLength,
                                data);
         if (rc != BDM_RC_OK)
            break;
         // Set buffer address
         flashCommand[0xC] = RS08_FlashInfo->directRamStart+
                                RS08_FlashInfo->programLength;
      }
//      USBDM_WriteMemory(1, 1, PTADAddress,  &zero);
      // Write command data - triggers flash write
      rc = USBDM_WriteMemory(1, sizeof(flashCommand), 0, flashCommand);
//      USBDM_WriteMemory(1, 1, PTADAddress,  &zero);
      if (rc != BDM_RC_OK)
         break;

      // Poll for completion - should be complete on 1st poll!
      int timeOut = 4;
      do {
         rc = USBDM_ReadMemory(1, sizeof(flashStatus), 0xD, &flashStatus);
      } while ((rc == BDM_RC_OK) && (flashStatus != 0) && (timeOut-->0) );

      if (rc != BDM_RC_OK)
         break;

      // Check status
      if (flashStatus != 0) {
         rc = BDM_RC_FAIL;
         break;
      }
   } while (FALSE);

   if (rc != BDM_RC_OK) {
      // Kill flash voltage on any error
      USBDM_RS08FlashProgramPostamble();
      return rc;
   }
   return BDM_RC_OK;
}

//=======================================================================
//! Write data to RS08 Flash memory
//! The data is subdivided based upon buffer size and Flash alignment
//!
//! @param elementSize = Size of data elements (=1 byte)
//! @param byteCount   = Number of _bytes_ to transfer
//! @param address     = Memory address
//! @param data        = Ptr to block of data to write
//!
//! @return error code \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_RS08WriteFlash( unsigned int        elementSize,
                                      unsigned int        byteCount,
                                      unsigned int        address,
                                      unsigned const char *data) {
   LOGGING_Q;
   USBDM_ErrorCode rc;
   int bufferSize;
   int bufferAddress;
   int blockSize;
   uint8_t delayValue;

   const uint32_t PTADAddress  = 0x10;
   const uint32_t PTADDAddress = 0x11;
   const uint8_t  zero    = 0x00;
   const uint8_t  allOnes = 0xFF;

   log.print("USBDM_RS08WriteFlash(count=0x%X(%d), addr=[0x%06X..0x%06X])\n",
         byteCount, byteCount, address, address+byteCount-1);

   if (elementSize != 1)
      return BDM_RC_ILLEGAL_PARAMS;

   // Check if ready for programming
   if (bdmState.flashState != FLASH_Ready) {
      return BDM_RC_WRONG_PROGRAMMING_MODE;
   }

   USBDM_WriteMemory(1, 1, PTADDAddress, &allOnes);
   USBDM_WriteMemory(1, 1, PTADAddress,  &zero);
   USBDM_WriteMemory(1, 1, PTADAddress,  &allOnes);

   rc = USBDM_RS08CalculateFlashDelay(&delayValue);
   if (rc != BDM_RC_OK)
      return rc;

   // Initially assume buffer directly follows program in direct memory
   bufferAddress = RS08_FlashInfo->directRamStart +
                   RS08_FlashInfo->programLength;

   // Calculate available space
   bufferSize = RS08_FlashInfo->directRamEnd - bufferAddress + 1;

   if (bufferSize <= 8) {
      // Use small buffer in Tiny RAM
      bufferSize    = 8;
      bufferAddress = 1;
   }
   // Limit buffer to a single flash page
   if (bufferSize>64)
      bufferSize = 64;

   do {
      // Data block must lie within a single Flash page
      blockSize = RS08_FLASH_PAGE_SIZE - (address%RS08_FLASH_PAGE_SIZE); // max # of bytes remaining in this page
      // Has to fit in buffer
      if (blockSize>bufferSize)
         blockSize = bufferSize;
      // Can't write more than we have left
      if (blockSize>byteCount)
         blockSize = byteCount;

      // Write block to flash
      rc = USBDM_RS08WriteFlashBlock(blockSize, address, data, delayValue);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      // Advance to next block of data
      byteCount -= blockSize;
      address   += blockSize;
      data      += blockSize;
   } while (byteCount > 0);
   USBDM_WriteMemory(1, 1, PTADAddress,  &zero);

   return BDM_RC_OK;
}

//! \brief Does Bulk Erase of Target Flash.
//!
//! @return error code, see \ref FlashError_t
//!
USBDM_API
USBDM_ErrorCode USBDM_RS08BulkEraseFlash() {
   LOGGING_Q;
   static const uint8_t FLCR_MASS_Value      = FLCR_MASS;
   static const uint8_t FLCR_HVEN_Value      = FLCR_HVEN;
   static const uint8_t FLCR_MASS_HVEN_Value = FLCR_HVEN|FLCR_MASS;
   static const uint8_t zero = 0;
   USBDM_ErrorCode rc;

   log.print("Bulk erasing target memory...\n");

   // Check if RS08 derivative is set
   if (RS08_FlashInfo == NULL) {
      log.print("USBDM_RS08FlashProgramPreamble() - Flash parameters not set\n");
      return BDM_RC_ILLEGAL_PARAMS;
   }

   rc = USBDM_SetTargetVpp(BDM_TARGET_VPP_ON);
   if (rc != BDM_RC_OK)
      return rc;

   //rc = USBDM_RS08FlashProgramCommence();
   rc = USBDM_WriteMemory(1, 1, RS08_FlashInfo->FLCRAddress, &FLCR_MASS_Value);
   Sleep(1);
   rc = USBDM_WriteMemory(1, 1, 0x3800, &zero);
   Sleep(1);
   rc = USBDM_WriteMemory(1, 1, RS08_FlashInfo->FLCRAddress, &FLCR_MASS_HVEN_Value);

   Sleep(510 /* ms */); // Mass erase requires >500 ms

   rc = USBDM_WriteMemory(1, 1, RS08_FlashInfo->FLCRAddress, &FLCR_HVEN_Value);
   Sleep(1);
   rc = USBDM_WriteMemory(1, 1, RS08_FlashInfo->FLCRAddress, &zero);

   return USBDM_SetTargetVpp(BDM_TARGET_VPP_OFF);
}
#endif

//*****************************************************************************
//*****************************************************************************
//*****************************************************************************
// JTAG Entry points
//

//! JTAG - Moves the TAP to \b TEST-LOGIC-RESET state
//! TMS=11111, TDI=00000 or similar
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
//! @note This uses the CMD_USBDM_JTAG_GOTORESET to move the TAP, it does
//!       not use TRST.
//!
USBDM_API
USBDM_ErrorCode USBDM_JTAG_Reset(void) {
   LOGGING_Q;
   log.print("USBDM_JTAG_Reset()\n");
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_JTAG_GOTORESET;
   return bdm_usb_transaction(2, 1, usb_data);
}

//! JTAG - move the TAP to \b SHIFT-DR or \b SHIFT-IR state
//! SHIFT_DR => TMS=100,  TDI=0 (Actually TMS=0000_0100)
//! SHIFT_IR => TMS=1100, TDI=0 (Actually TMS=0000_1100)
//!
//! @param mode Action, ref \ref JTAG_ExitActions_t \n
//!      - SHIFT_DR - Enter SHIFT-DR \n
//!      - SHIFT_IR - Enter SHIFT-IR \n
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
//! @note - Requires the tap to be initially in \b TEST-LOGIC-RESET or \b RUN-TEST/IDLE
//!
USBDM_API
USBDM_ErrorCode USBDM_JTAG_SelectShift(unsigned char mode) {
   LOGGING_Q;

   log.print("USBDM_JTAG_SelectShift(SHIFT-%cR)\n",mode?'I':'D');
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_JTAG_GOTOSHIFT;
   usb_data[2] = mode;
   return bdm_usb_transaction(3, 1, usb_data);
}

//! JTAG - write data to JTAG shift register
//! STAY_SHIFT    => TMS=Nx0,       TDI=NxData
//! EXIT_SHIFT_DR => TMS=Nx0,11100  TDI=NxData,00000
//! EXIT_SHIFT_IR => TMS=Nx0,111100 TDI=NxData,000000
//! EXIT_IDLE     => TMS=Nx0,10     TDI=NxData,00
//!
//!  @param exit action after shift, see \ref JTAG_ExitActions_t \n
//!      - JTAG_STAY_SHIFT    - Remain in SHIFT-DR or SHIFT-IR \n
//!      - JTAG_EXIT_IDLE     - Exit SHIFT-XX to RUN-TEST/IDLE
//!      - JTAG_EXIT_SHIFT_DR - Exit SHIFT-XX & enter SHIFT-DR w/o crossing RUN-TEST/IDLE
//!      - JTAG_EXIT_SHIFT_IR - Exit SHIFT-XX & enter SHIFT-IR w/o crossing RUN-TEST/IDLE
//!
//!  @param bitCount 8-bit count of \b bits to shift in. [>0]\n
//!                  It is not possible to do 0 bits.
//!  @param buffer Pointer to data buffer.  The data is shifted in LSB (last byte) first,
//!                unused bits (if any) are in the MSB (first) byte;
//!  @note Requires the tap to be in \b SHIFT-DR or \b SHIFT-IR state.
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_JTAG_Write(unsigned char       bitCount,
                                 unsigned char       exit,
                                 const unsigned char *buffer) {
#if JTAG_HEADER_SIZE < 4
#error "JTAG_HEADER_SIZE is too small"
#endif

   LOGGING_Q;
   unsigned byteSize = (bitCount>>3)+((bitCount&0x07)!=0);

   if ((bitCount == 0) || (byteSize>bdmInfo.jtagBufferSize)) {
      log.print("USBDM_JTAG_Write(): Illegal operands\n");
      return BDM_RC_ILLEGAL_PARAMS;
   }
   log.print("USBDM_JTAG_Write(): %d bits (%s)\n", bitCount, getExitAction(exit));
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_JTAG_WRITE;
   usb_data[2] = exit;
   usb_data[3] = bitCount;
   memcpy(usb_data+4, buffer, byteSize);
   log.printDump(usb_data+4, byteSize);
   return bdm_usb_transaction(byteSize+4, 1, usb_data, 100);
}

//! JTAG - read data from JTAG shift register
//! SHIFT_DR => TMS=Nx0, TDI=0, TDO=NxData (captured)
//!
//!  @param exit action after shift, see \ref JTAG_ExitActions_t \n
//!      - JTAG_STAY_SHIFT    - Remain in SHIFT-DR or SHIFT-IR \n
//!      - JTAG_EXIT_IDLE     - Exit SHIFT-XX to RUN-TEST/IDLE
//!      - JTAG_EXIT_SHIFT_DR - Exit SHIFT-XX & enter SHIFT-DR w/o crossing RUN-TEST/IDLE
//!      - JTAG_EXIT_SHIFT_IR - Exit SHIFT-XX & enter SHIFT-IR w/o crossing RUN-TEST/IDLE
//!      - +JTAG_WRITE_0      - Write 0's when reading - combined with one of above
//!      - +JTAG_WRITE_1      - Write 1's when reading - combined with one of above
//!
//!  @param bitCount 8-bit count of \b bits to shift in. [>0]\n
//!                  It is not possible to do 0 bits.
//!  @param buffer Pointer to buffer for data read out of the device (first bit in LSB of the last byte in the buffer)
//!  @note Requires the tap to be in \b SHIFT-DR or \b SHIFT-IR state.
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_JTAG_Read( unsigned char bitCount,
                                 unsigned char exit,
                                 unsigned char *buffer) {
#if JTAG_HEADER_SIZE < 4
#error "JTAG_HEADER_SIZE is too small"
#endif

   LOGGING_Q;
   USBDM_ErrorCode rc;
   unsigned byteSize = (bitCount>>3)+((bitCount&0x07)!=0);

   if ((bitCount == 0) || (byteSize>bdmInfo.jtagBufferSize)){
      log.print("USBDM_JTAG_Read(): Illegal operands\n");
      return BDM_RC_ILLEGAL_PARAMS;
   }
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_JTAG_READ;
   usb_data[2] = exit;
   usb_data[3] = bitCount;
   rc = bdm_usb_transaction(4, byteSize+1, usb_data, 100);
   if (rc != BDM_RC_OK) {
      log.print("USBDM_JTAG_Read(): %d bits (%s) - Failed\n", bitCount, getExitAction(exit));
   }
   else {
      log.print("USBDM_JTAG_Read(): %d bits (%s)\n", bitCount, getExitAction(exit));
      memcpy(buffer, usb_data+1, byteSize);
      log.printDump(usb_data+1, byteSize);
   }
   return rc;
}

//! JTAG - read data from JTAG shift register
//! SHIFT_DR => TMS=Nx0, TDI=0, TDO=NxData (captured)
//!
//!  @param exit action after shift, see \ref JTAG_ExitActions_t \n
//!      - JTAG_STAY_SHIFT    - Remain in SHIFT-DR or SHIFT-IR \n
//!      - JTAG_EXIT_IDLE     - Exit SHIFT-XX to RUN-TEST/IDLE
//!      - JTAG_EXIT_SHIFT_DR - Exit SHIFT-XX & enter SHIFT-DR w/o crossing RUN-TEST/IDLE
//!      - JTAG_EXIT_SHIFT_IR - Exit SHIFT-XX & enter SHIFT-IR w/o crossing RUN-TEST/IDLE
//!      - +JTAG_WRITE_0      - Write 0's when reading - combined with one of above
//!      - +JTAG_WRITE_1      - Write 1's when reading - combined with one of above
//!
//!  @param bitCount 8-bit count of \b bits to shift in. [>0]\n
//!                  It is not possible to do 0 bits.
//!  @param inBuffer  Pointer to buffer for data written to the device (first bit in LSB of the last byte in the buffer)
//!  @param outBuffer Pointer to buffer for data read out of the device (first bit in LSB of the last byte in the buffer)
//!  @note Requires the tap to be in \b SHIFT-DR or \b SHIFT-IR state.
//!  @note inbuffer and outbuffer may be the same location
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_JTAG_ReadWrite( unsigned char bitCount,
                                      unsigned char exit,
                                      const unsigned char *outBuffer,
                                      unsigned char *inBuffer) {
#if JTAG_HEADER_SIZE < 4
#error "JTAG_HEADER_SIZE is too small"
#endif

   LOGGING_Q;
   USBDM_ErrorCode rc;
   unsigned byteSize = (bitCount>>3)+((bitCount&0x07)!=0);

   if ((bitCount == 0) || (byteSize>bdmInfo.jtagBufferSize)){
      log.print("USBDM_JTAG_ReadWrite(): Illegal operands\n");
      return BDM_RC_ILLEGAL_PARAMS;
   }
   log.print("USBDM_JTAG_ReadWrite(): %d bits (%s)\n", bitCount, getExitAction(exit));
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_JTAG_READ_WRITE;
   usb_data[2] = exit;
   usb_data[3] = bitCount;
   memcpy(usb_data+4, outBuffer, byteSize);
   log.print("OutBuffer = \n");
   log.printDump(usb_data+4, byteSize);
   rc = bdm_usb_transaction(byteSize+4, byteSize+1, usb_data, 100);
   if (rc != BDM_RC_OK) {
      log.print("USBDM_JTAG_ReadWrite(): %d bits (%s) - Failed\n", bitCount, getExitAction(exit));
   }
   else {
      memcpy(inBuffer, usb_data+1, byteSize);
      log.print("InBuffer = \n");
      log.printDump(usb_data+1, byteSize);
   }
   return rc;
}

//! Execute JTAG Sequence
//!  @param length   - JTAG sequence length.
//!  @param sequence - Pointer to sequence.
//!  @param inLength - Expected length of input data
//!  @param inBuffer - Returned values
//!
//! @return \n
//!     BDM_RC_OK    => OK \n
//!     other        => Error code - see \ref USBDM_ErrorCode
//!
USBDM_API
USBDM_ErrorCode USBDM_JTAG_ExecuteSequence(unsigned char       length,
                                           const unsigned char *sequence,
                                           unsigned char       inLength,
                                           unsigned char       *inBuffer) {
#if JTAG_HEADER_SIZE < 4
#error "JTAG_HEADER_SIZE is too small"
#endif

   LOGGING_Q;
   USBDM_ErrorCode rc;

   log.print("USBDM_JTAG_ExecuteSequence(seqLength=%d, inLength=%d)\n", length, inLength);

   if (length>bdmInfo.jtagBufferSize) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   if (inLength>bdmInfo.commandBufferSize-1) {
      return BDM_RC_ILLEGAL_PARAMS;
   }
   usb_data[0] = 0;
   usb_data[1] = CMD_USBDM_JTAG_EXECUTE_SEQUENCE;
   usb_data[2] = inLength;
   usb_data[3] = length;
   memcpy(usb_data+4, sequence, length);

   log.print("OutBuffer = \n");
   log.printDump(usb_data+4, length);
   unsigned rxSize;
   rc = bdm_usb_transaction(length+4, inLength+1, usb_data, 1000, &rxSize);
   if ((unsigned)(inLength+1) != rxSize) {
      log.print("USBDM_JTAG_ExecuteSequence() - Unexpected response size (exp=%d, rcvd=%d\n",
            inLength+1, rxSize);
      // Truncate if smaller
      if (inLength >= rxSize-1) {
         inLength = rxSize-1;
      }
   }
   if (rc != BDM_RC_OK) {
      log.print("USBDM_JTAG_ExecuteSequence() - Failed\n");
   }
   else if (inLength>0) {
      memcpy(inBuffer, usb_data+1, inLength);
      log.print("InBuffer = \n");
      log.printDump(usb_data+1, inLength);
   }
   return rc;
}

//====================================================================================================
//====================================================================================================
//====================================================================================================

//! Set log file for messages
//!
USBDM_API
void USBDM_SetLogFile(FILE *fp) {
   UsbdmSystem::Log::setLogFileHandle(fp);
}

//! Get current log file for messages
//!
USBDM_API
FILE *USBDM_GetLogFile(void) {
   return UsbdmSystem::Log::getLogFileHandle();
}

//====================================================================================================
//====================================================================================================
//====================================================================================================

extern "C"
void
#ifdef __unix__
__attribute__ ((constructor))
#endif
usbdm_dll_initialize(void) {
//   fprintf(stderr, "usbdm_dll_initialize()\n");
}

extern "C"
void
#ifdef __unix__
__attribute__ ((destructor))
#endif
usbdm_dll_uninitialize(void) {
//   fprintf(stderr, "usbdm_dll_uninitialize()\n");
   bdm_usb_exit(); // Just in case BDM hasn't been closed etc.
}

#if defined(USBDM_DLL_EXPORTS) && defined(WIN32)
BOOL WINAPI DllMain(HINSTANCE hDLLInst,
                    DWORD    fdwReason,
                    LPVOID   lpvReserved) {

   switch (fdwReason) {
      case DLL_PROCESS_ATTACH:
		   usbdm_dll_initialize();
         break;
      case DLL_PROCESS_DETACH:
         usbdm_dll_uninitialize();
         break;
      case DLL_THREAD_ATTACH:
         //dll_initialize(_hDLLInst);
         break;
      case DLL_THREAD_DETACH:
         //dll_uninitialize();
         break;
   }
   return TRUE;
}
#endif
