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
#include "hwdesc.h"

//==================================================================================
// Common ICP routines
//==================================================================================

static int lastCommand = 0x00; //! Last command issued - used for error checking

static ICP_ErrorType getResult(void);

// Based on Freescale App Note: AN2399
enum {                      // Command       BmRequest bRequest wValue         wIndex       wLength       Data
   ICP_PROGRAM_ROW = 0x81,  // Program Row   $40       $81      Start Address  End Address  Data Length   Data
   ICP_ERASE_BLOCK = 0x82,  // Erase Block   $40       $82      Start Address  End Address  $0000         —
   ICP_MASS_ERASE  = 0x83,  // Mass Erase    $40       $83      $0000          $0000        $0000         —
   ICP_VERIFY_ROW  = 0x87,  // Verify Row    $40       $87      Start Address  End Address  Data Length  Data
   ICP_GET_RESULT  = 0x8F,  // Get Result    $C0       $8F      Start Address  End Address  $01          Result

   ICP_REBOOT      = 14,  // USBDM function
};

//====================================================================
//! ICP mode - program BDM Flash memory
//!
//! @param addr    32-bit memory address
//! @param count   number of bytes to program
//! @param data    Pointer to buffer containing data
//!
//! @return
//!      - == RC_OK => success \n
//!      - != RC_OK => fail, see \ref ICP_ErrorType
//!
ICP_ErrorType ICP_Program(unsigned int   addr,
                          unsigned int   count,
                          unsigned char *data) {
   LOGGING_Q;

   unsigned int dataSize; // Bytes to program this row
   ICP_ErrorType rc;
   unsigned int temp;
   int doBlock;
   unsigned int doneCount     = 0;

   lastCommand = ICP_PROGRAM_ROW;

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
         log.printDump(data, dataSize, addr);

         rc =  (ICP_ErrorType)bdm_usb_raw_send_ep0(ICP_PROGRAM_ROW, // bRequest
                                                   addr,            // wValue  = Start address
                                                   addr+dataSize-1, // wIndex  = End address
                                                   dataSize,        // wLength = # bytes
                                                   data);           // Data to program
         if (rc != RC_OK) {
            log.print("ICP_Program() - Failed bdm_usb_raw_send_ep0()\n");
            return rc;
         }
         milliSleep(20);
         rc = getResult();
         if (rc != RC_OK) {
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
   return RC_OK;
}

//====================================================================
//! ICP mode - erase BDM Flash memory
//!
//! @param addr    32-bit memory address
//! @param count   number of bytes to erase
//!
//! @return
//!      - == RC_OK => success \n
//!      - != RC_OK => fail, see \ref ICP_ErrorType
//!
//! @note Flash memory alignment requirements should be taken into account.  The
//! range erased should be a multiple of the Flash erase block size.
//!
ICP_ErrorType ICP_MassErase() {
   LOGGING;
   ICP_ErrorType rc;

   lastCommand = ICP_MASS_ERASE;

   rc = (ICP_ErrorType)bdm_usb_raw_send_ep0(ICP_MASS_ERASE, 0, 0, 0, 0);
   if (rc != RC_OK) {
      log.print("ICP_MassErase() - Failed bdm_usb_raw_send_ep0()\n");
      return rc;
   }
   milliSleep(20000);
   rc = getResult();
   if (rc != RC_OK) {
      log.print("ICP_MassErase() - Failed icp_get_result() rc = %d, (%s)\n", rc,
            ICP_GetErrorName(rc));
      return rc;
   }
   return RC_OK;
}

//====================================================================
//! ICP mode - get result of last ICP command
//!
//! @return
//!      - == RC_OK => success \n
//!      - != RC_OK => fail, see \ref ICP_ErrorType
//!
static ICP_ErrorType getResult(void) {
   LOGGING_Q;

   unsigned char buff[1] = {0x00};
   ICP_ErrorType rc;

   int retry = 5;
   do {
      rc = bdm_usb_raw_recv_ep0(ICP_GET_RESULT, 0, 0, sizeof(buff), buff);
      if ((rc == RC_OK) && (buff[0] == 0x01)) {
         break;
      }
      if (retry > 0) {
         log.print("getResult() Failed (rc=%d, value=0x%2.2X) - retry\n", rc, buff[0]);
      }
      milliSleep(100);
   } while (retry-- > 0);

   if (buff[0] != 0x01) {
      log.print("result = 0x%2.2X\n", buff[0]);
      rc = ICP_RC_COMMAND_FAILED;
   }
   if (rc != RC_OK) {
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
//!     RC_OK => OK \n
//!     other     => USB Error - see \ref ICP_ErrorType
//!

bool initialised = false;

ICP_ErrorType ICP_Init(void) {
   LOGGING;

   ICP_ErrorType rc = bdm_usb_init();

   initialised = (rc == RC_OK);

   return rc;
}

//! Clean up
//!
//! This must be called after all USBDM operations are finished
//!
//! @return \n
//!     RC_OK => OK \n
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
//!     RC_OK                => OK \n
//!     BDM_RC_NO_ICP_DEVICE   => No devices found.
//!     other                    => other Error - see \ref ICP_ErrorType
//!
//! @note deviceCount == 0 on any error so may be used w/o checking rc
//! @note The device list is held until ICP_ReleaseDevices() is called
//!

ICP_ErrorType ICP_FindUsbdmDevices(unsigned int *deviceCount) {
   LOGGING;

   ICP_ErrorType rc;

   *deviceCount = 0;
   rc = bdm_usb_findDevices(deviceCount, USBDM_VID, USBDM_PID);
   if (deviceCount == 0) {
      rc = bdm_usb_findDevices(deviceCount, TBDML_VID, TBDML_PID);
   }
   if (deviceCount == 0) {
      rc = bdm_usb_findDevices(deviceCount, OSBDM_VID, OSBDM_PID);
   }
   if (deviceCount == 0) {
      rc = bdm_usb_findDevices(deviceCount, TBLCF_VID, TBLCF_PID);
   }
   if (rc == ICP_RC_NO_JS16_DEVICE) {
      rc = ICP_RC_NO_USBDM__DEVICE;
   }
   log.print("ICP_FindDevices(): USB initialised, found %d device(s)\n", *deviceCount);
   return rc;
}

//! Find USBDM Devices \n
//! This function creates an internal list of USBDM devices.  The list is held until
//! ICP_ReleaseDevices() is called. \n
//! ICP_FindDevices() must be done before any device may be opened.
//!
//! @param deviceCount Number of BDM devices found
//!
//! @return \n
//!     RC_OK                => OK \n
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
   rc = bdm_usb_findDevices(deviceCount, JB16_BOOT_VID, JB16_BOOT_PID); // look for USBDM devices on all USB busses
   log.print("ICP_FindDevices(): USB initialised, found %d device(s)\n", *deviceCount);
   return rc;
}

//! Release USBDM Device list
//!
//! @return \n
//!     RC_OK => OK \n
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
//!     RC_OK => OK \n
//!     other     => Error code - see \ref ICP_ErrorType
//!

ICP_ErrorType ICP_Open(unsigned char deviceNo) {
   LOGGING_Q;

   ICP_ErrorType rc = RC_OK;

   log.print("ICP_Open(): Trying to open device #%d\n", deviceNo);
   rc = bdm_usb_open(deviceNo);
   if (rc != RC_OK) {
      log.print("ICP_Open(): Failed - rc = %s\n", ICP_GetErrorName(rc));
   }
   return rc;
}

//! Closes currently open device
//!
//! @return \n
//!     RC_OK => OK
//!

ICP_ErrorType ICP_Close(void) {
   LOGGING_Q;
//   uint8_t debugCommand[2] = {sizeof(debugCommand),BDM_DBG_TESTALTSPEED};

   log.print("ICP_Close(): Trying to close the device\n");
   return RC_OK;
}


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
   LOGGING;
//   static const unsigned char message[] = { 5, CMD_USBDM_ICP_BOOT, 'B', 'O', 'O', 'T' };

   bdm_usb_raw_send_ep0(ICP_REBOOT,     // bRequest
                        ('0'<<8)|'B',   // wValue
                        ('T'<<8)|'0',   // wIndex
                        0,              // wLength
                        0);             // Data to program

   milliSleep(1000);
}
