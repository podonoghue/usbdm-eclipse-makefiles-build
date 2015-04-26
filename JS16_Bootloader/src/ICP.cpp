/*! \file
 \brief ICP code for JS16, JM60 or UF32

 \verbatim
 Opensource BDM  - interface DLL
 Based on TBDML interface DLL by
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
 +==============================================================================
 |  1 Aug 2009 | Moved ICP routines from interface_dll                     - pgo
 | 21 Oct 2008 | Increased size of address in ICP commands                 - pgo
 | 20 Oct 2008 | Fixed size of SET_BOOT command                            - pgo
 +==============================================================================
 \endverbatim
 */
#include <stdio.h>
#include "low_level_usb.h"
#include "UsbdmSystem.h"
#include "Common.h"
#include "ICP.h"
#include "Names.h"

//==================================================================================
// Common ICP routines
//==================================================================================

static int lastCommand = 0x00; //! Last command issued - used for error checking

static ICP_ErrorType getResult(void);

enum {
   ICP_PROGRAM    = 0x61,
   ICP_MASS_ERASE = 0x63,
   ICP_ERASE      = 0x64,
   ICP_REBOOT     = 0x68,
   ICP_CRC_CHECK  = 0x40,
   ICP_GET_RESULT = 0x6F,
};

//====================================================================
//! ICP mode - reboot
//!
//! The BDM does a normal reset
//!
//! Used in ICP mode to reset to normal (BDM) mode.
//! @note Communication is lost.  \n
//!       The BDM will do the usual flash validity checks before entering BDM mode.
//!
void ICP_Reboot(void) {
   LOGGING_E;

   lastCommand = ICP_REBOOT;

   ICP_ErrorType rc = (ICP_ErrorType)bdm_usb_raw_send_ep0(ICP_REBOOT, 0, 0, 0, 0);
   if (rc != ICP_RC_OK) {
      log.print("ICP_Program() - Failed bdm_usb_raw_send_ep0()\n");
      return;
   }
}

//====================================================================
//! ICP mode - program BDM Flash memory
//!
//! @param addr    32-bit memory address
//! @param count   number of bytes to program
//! @param data    Pointer to buffer containing data
//!
//! @return
//!      - == ICP_RC_OK => success \n
//!      - != ICP_RC_OK => fail, see \ref ICP_ErrorType
//!
ICP_ErrorType ICP_Program(unsigned int  addr,
                          unsigned int  count,
                          unsigned char *data) {
   LOGGING_E;

   unsigned int dataSize; // Bytes to program this row
   ICP_ErrorType rc;
   unsigned int temp;
   int doBlock;
   unsigned int doneCount     = 0;

   lastCommand = ICP_PROGRAM;

   log.print("ICP_Program() - Programming [%8.8X-%8.8X]\n", addr, addr+count-1);

   // Have to program within a row in each iteration
   // so there are size and alignment issues.
   while (count > 0) {
      // Bytes to end of current row
      dataSize = ICP_MAX_DATA_SIZE - (addr & (ICP_MAX_DATA_SIZE - 1));
      if (dataSize > count) { // Take down to number actually remaining
         dataSize = count;
      }
      // Check if empty block (all 0xFF)
      doBlock = false;
      for (temp = 0; temp < dataSize; temp++) {
         doBlock = doBlock || (data[temp] != 0xFF);
      }
      if (doBlock) { // Only program non-Blank blocks
         log.print("ICP_Program() - Programming block %4.4X-%4.4X\n", addr, addr+dataSize-1);
         log.printDump(data, dataSize);

         rc =  (ICP_ErrorType)bdm_usb_raw_send_ep0(ICP_PROGRAM,     // bRequest
                                                   addr,            // wValue  = Start address
                                                   addr+dataSize-1, // wIndex  = End address
                                                   dataSize,        // wLength = # bytes
                                                   data);           // Data to program
         if (rc != ICP_RC_OK) {
            log.print("ICP_Program() - Failed bdm_usb_raw_send_ep0()\n");
            return rc;
         }
         milliSleep(20);
         rc = getResult();
         if (rc != ICP_RC_OK) {
            log.print("ICP_Program() - Failed icp_get_result() rc = %d\n", rc);
            return rc;
         }
      }
      else {
         log.print("ICP_Program() - Skipping block    %4.4X-%4.4X\n", addr, addr+dataSize-1);
      }
      data      += dataSize; // update location in buffer
      addr      += dataSize; // update address
      count     -= dataSize; // update count
      doneCount += dataSize;
   }
   return ICP_RC_OK;
}

//====================================================================
//! ICP mode - erase BDM Flash memory
//!
//! @param addr    32-bit memory address
//! @param count   number of bytes to erase
//!
//! @return
//!      - == ICP_RC_OK => success \n
//!      - != ICP_RC_OK => fail, see \ref ICP_ErrorType
//!
//! @note Flash memory alignment requirements should be taken into account.  The
//! range erased should be a multiple of the Flash erase block size.
//!
ICP_ErrorType ICP_MassErase() {
   LOGGING_E;
   ICP_ErrorType rc;

   lastCommand = ICP_MASS_ERASE;

   rc = (ICP_ErrorType)bdm_usb_raw_send_ep0(ICP_MASS_ERASE,0, 0, 0, 0);
   if (rc != ICP_RC_OK) {
      log.print("ICP_MassErase() - Failed bdm_usb_raw_send_ep0()\n");
      return rc;
   }
   rc = getResult();
   if (rc != ICP_RC_OK) {
      log.print("ICP_MassErase() - Failed icp_get_result() rc = %d, (%s)\n", rc,
            ICP_GetErrorName(rc));
      return rc;
   }
   return ICP_RC_OK;
}

//====================================================================
//! ICP mode - get result of last ICP command
//!
//! @return
//!      - == ICP_RC_OK => success \n
//!      - != ICP_RC_OK => fail, see \ref ICP_ErrorType
//!
static ICP_ErrorType getResult(void) {
   LOGGING_Q;

   unsigned char buff[1] = {0x00};
   ICP_ErrorType rc;

   int retry = 5;
   do {
      rc = bdm_usb_raw_recv_ep0(ICP_GET_RESULT, 0, 0, sizeof(buff), buff);
      if ((rc != ICP_RC_OK) && (retry-- > 0))
         log.print("getResult() Failed (rc=%d) - retry\n", rc);
   } while ((rc != ICP_RC_OK) && (retry-- > 0));

//   switch (lastCommand) {
//   case ICP_PROGRAM :   expectedResponse = 0x01;
//   case ICP_MASS_ERASE:
//   case ICP_REBOOT:
//   case ICP_CRC_CHECK:
//   case ICP_ERASE:
//      break;
//   }
   if (buff[0] != 0x01) {
      rc = ICP_RC_COMMAND_FAILED;
   }
   if (rc != ICP_RC_OK) {
      log.print("getResult() Failed\n");
   }
   return rc;
}

//=============================================================================
//=============================================================================
//=============================================================================

//! Initialises USB interface
//!
//! This must be done before any other operations.
//!
//! @return \n
//!     ICP_RC_OK => OK \n
//!     other     => USB Error - see \ref ICP_ErrorType
//!

bool initialised = false;

ICP_ErrorType ICP_Init(void) {
   LOGGING_E;

   ICP_ErrorType rc = bdm_usb_init();

   initialised = (rc == ICP_RC_OK);

   return rc;
}

//! Clean up
//!
//! This must be called after all USBDM operations are finished
//!
//! @return \n
//!     ICP_RC_OK => OK \n
//!     other     => USB Error - see \ref ICP_ErrorType
//!

ICP_ErrorType ICP_Exit(void) {
   LOGGING_E;

   ICP_ErrorType rc = bdm_usb_exit();

   initialised = false;

   return rc;
}

//=============================================================================
//=============================================================================
//=============================================================================
// USBDM Device handling

//! Find USBDM Devices \n
//! This function creates an internal list of USBDM devices.  The list is held until
//! ICP_ReleaseDevices() is called. \n
//! ICP_FindDevices() must be done before any device may be opened.
//!
//! @param deviceCount Number of BDM devices found
//!
//! @return \n
//!     ICP_RC_OK                => OK \n
//!     BDM_RC_NO_ICP_DEVICE   => No devices found.
//!     other                    => other Error - see \ref ICP_ErrorType
//!
//! @note deviceCount == 0 on any error so may be used w/o checking rc
//! @note The device list is held until ICP_ReleaseDevices() is called
//!

ICP_ErrorType ICP_FindDevices(unsigned int *deviceCount) {
   LOGGING_E;

   ICP_ErrorType rc;

   *deviceCount = 0;
   rc = bdm_usb_findDevices(deviceCount); // look for USBDM devices on all USB busses
   log.print("ICP_FindDevices(): Usb initialised, found %d device(s)\n", *deviceCount);
   return rc;
}

//! Release USBDM Device list
//!
//! @return \n
//!     ICP_RC_OK => OK \n
//!     other     => USB Error - see \ref ICP_ErrorType
//!

ICP_ErrorType ICP_ReleaseDevices(void) {
   LOGGING_E;

   return bdm_usb_releaseDevices();
}

//! Opens a device
//!
//! @param deviceNo Number (0..N) of device to open.
//! A device must be open before any communication with the device can take place.
//!
//! @note The range of device numbers must be obtained from ICP_FindDevices() before
//! calling this function.
//!
//! @return \n
//!     ICP_RC_OK => OK \n
//!     other     => Error code - see \ref ICP_ErrorType
//!

ICP_ErrorType ICP_Open(unsigned char deviceNo) {
   LOGGING_Q;

   ICP_ErrorType rc = ICP_RC_OK;

   log.print("ICP_Open(): Trying to open device #%d\n", deviceNo);
   rc = bdm_usb_open(deviceNo);
   if (rc != ICP_RC_OK) {
      log.print("ICP_Open(): Failed - rc = %s\n", ICP_GetErrorName(rc));
   }
   return rc;
}

//! Closes currently open device
//!
//! @return \n
//!     ICP_RC_OK => OK
//!

ICP_ErrorType ICP_Close(void) {
   LOGGING_Q;
//   uint8_t debugCommand[2] = {sizeof(debugCommand),BDM_DBG_TESTALTSPEED};

   log.print("ICP_Close(): Trying to close the device\n");
   return ICP_RC_OK;
}

