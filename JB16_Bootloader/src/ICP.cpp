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
#include "USBDM_API.h"
#include "low_level_usb.h"
#include "UsbdmSystem.h"
#include "Common.h"
#include "ICP.h"
#include "Names.h"
#include "hwdesc.h"
#include "ProgressDialogueFactory.h"

//==================================================================================
// Common ICP routines
//==================================================================================

static int lastCommand = 0x00; //! Last command issued - used for error checking

static USBDM_ErrorCode getResult(void);

// Based on Freescale Application Note AN2399
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
//!      - == BDM_RC_OK => success \n
//!      - != BDM_RC_OK => fail, see \ref USBDM_ErrorCode
//!
USBDM_ErrorCode ICP_Program(unsigned int   addr,
                          unsigned int   count,
                          unsigned char *data,
                          ProgressDialoguePtr progressCallback) {
   LOGGING_Q;

   unsigned int dataSize; // Bytes to program this row
   USBDM_ErrorCode rc;
   unsigned int temp;
   int doBlock;
   unsigned int doneCount     = 0;

   lastCommand = ICP_PROGRAM_ROW;

   log.print("Programming [%8.8X-%8.8X]\n", addr, addr+count-1);

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
         log.print("Programming block %4.4X-%4.4X\n", addr, addr+dataSize-1);
         log.printDump(data, dataSize, addr);

         rc =  (USBDM_ErrorCode)bdm_usb_raw_send_ep0(ICP_PROGRAM_ROW, // bRequest
                                                   addr,            // wValue  = Start address
                                                   addr+dataSize-1, // wIndex  = End address
                                                   dataSize,        // wLength = # bytes
                                                   data,            // Data to program
                                                   200 /* ms */);
         if (rc != BDM_RC_OK) {
            log.print("Failed bdm_usb_raw_send_ep0()\n");
            return rc;
         }
         // Wait for Programming to complete < 5ms for JB16
         UsbdmSystem::milliSleep(10);
         rc = getResult();
         if (rc != BDM_RC_OK) {
            log.print("Failed icp_get_result() rc = %d\n", rc);
            return rc;
         }
         progressCallback->incrementalUpdate(dataSize);
      }
      else {
         log.print("Skipping block    %4.4X-%4.4X\n", addr, addr+dataSize-1);
      }
      data      += dataSize; // update location in buffer
      addr      += dataSize; // update address
      count     -= dataSize; // update count
      doneCount += dataSize;
   }
   return BDM_RC_OK;
}

//====================================================================
//! ICP mode - erase BDM Flash memory
//!
//! @param addr    32-bit memory address
//! @param count   number of bytes to erase
//!
//! @return
//!      - == BDM_RC_OK => success \n
//!      - != BDM_RC_OK => fail, see \ref USBDM_ErrorCode
//!
//! @note Flash memory alignment requirements should be taken into account.  The
//! range erased should be a multiple of the Flash erase block size.
//!
USBDM_ErrorCode ICP_MassErase(ProgressDialoguePtr progressCallback) {
   LOGGING;
   USBDM_ErrorCode rc;

   lastCommand = ICP_MASS_ERASE;

   // It appears that the Mass erase is completed AFTER sending the ACK for this packet
   rc = (USBDM_ErrorCode)bdm_usb_raw_send_ep0(ICP_MASS_ERASE, 0, 0, 0, 0, 1000 /* ms */);
   if (rc != BDM_RC_OK) {
      log.print("Failed bdm_usb_raw_send_ep0()\n");
      return rc;
   }
   // This is the reason for the large timeout
   // Mass erase ~200ms from JB16 data sheet
   for (int i=0; i<100; i++) {
      UsbdmSystem::milliSleep(3);
      progressCallback->percentageUpdate(i);
   }
   rc = getResult();
   if (rc != BDM_RC_OK) {
      log.print("Failed icp_get_result() rc = %d, (%s)\n", rc,
            UsbdmSystem::getErrorString(rc));
      return rc;
   }
   return BDM_RC_OK;
}

//====================================================================
//! ICP mode - get result of last ICP command
//!
//! @return
//!      - == BDM_RC_OK => success \n
//!      - != BDM_RC_OK => fail, see \ref USBDM_ErrorCode
//!
static USBDM_ErrorCode getResult(void) {
   LOGGING_Q;

   unsigned char buff[1] = {0x00};
   USBDM_ErrorCode rc;

   int retry = 5;
   do {
      rc = bdm_usb_raw_recv_ep0(ICP_GET_RESULT, 0, 0, sizeof(buff), buff, 200 /* ms */);
      if ((rc == BDM_RC_OK) && (buff[0] != 0x01)) {
         // Error response from JB16
         log.error("ICP result = 0x%2.2X\n", buff[0]);
         rc = BDM_RC_FAIL;
         break;
      }
      if (rc == BDM_RC_OK) {
         // OK - done
         break;
      }
      if (retry > 0) {
         // Continue waiting from USB response
         log.print("Failed (rc=%d, value=0x%2.2X) - retry\n", rc, buff[0]);
      }
      UsbdmSystem::milliSleep(100);
   } while (retry-- > 0);

   if (rc != BDM_RC_OK) {
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
//!     BDM_RC_OK => OK \n
//!     other     => USB Error - see \ref USBDM_ErrorCode
//!

bool initialised = false;

USBDM_ErrorCode ICP_Init(void) {
   LOGGING;

   USBDM_ErrorCode rc = bdm_usb_init();

   initialised = (rc == BDM_RC_OK);

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

USBDM_ErrorCode ICP_Exit(void) {
   LOGGING_E;

   USBDM_ErrorCode rc = bdm_usb_exit();

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
//!     BDM_RC_OK                => OK \n
//!     BDM_RC_NO_ICP_DEVICE   => No devices found.
//!     other                    => other Error - see \ref USBDM_ErrorCode
//!
//! @note deviceCount == 0 on any error so may be used w/o checking rc
//! @note The device list is held until ICP_ReleaseDevices() is called
//!

USBDM_ErrorCode ICP_FindUsbdmDevices(unsigned int *deviceCount) {
   LOGGING;

   USBDM_ErrorCode rc;

   static const UsbId usbIds[] = {
         {USBDM_VID, USBDM_PID},
         {TBDML_VID, TBDML_PID},
         {OSBDM_VID, OSBDM_PID},
         {TBLCF_VID, TBLCF_PID},
         {0,0}
   };
   rc = bdm_usb_findDevices(deviceCount, usbIds);
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
//!     BDM_RC_OK                => OK \n
//!     BDM_RC_NO_ICP_DEVICE   => No devices found.
//!     other                    => other Error - see \ref USBDM_ErrorCode
//!
//! @note deviceCount == 0 on any error so may be used w/o checking rc
//! @note The device list is held until ICP_ReleaseDevices() is called
//!

USBDM_ErrorCode ICP_FindDevices(unsigned int *deviceCount) {
   LOGGING_E;

   USBDM_ErrorCode rc;

   *deviceCount = 0;
   static const UsbId usbIds[] = {
         {JB16_BOOT_VID, JB16_BOOT_PID},
         {0,0}
   };
   rc = bdm_usb_findDevices(deviceCount, usbIds); // look for USBDM devices on all USB busses
   log.print("ICP_FindDevices(): USB initialised, found %d device(s)\n", *deviceCount);
   return rc;
}

//! Release USBDM Device list
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => USB Error - see \ref USBDM_ErrorCode
//!

USBDM_ErrorCode ICP_ReleaseDevices(void) {
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
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!

USBDM_ErrorCode ICP_Open(unsigned char deviceNo) {
   LOGGING_Q;

   USBDM_ErrorCode rc = BDM_RC_OK;

   log.print("ICP_Open(): Trying to open device #%d\n", deviceNo);
   rc = bdm_usb_open(deviceNo);
   if (rc != BDM_RC_OK) {
      log.print("ICP_Open(): Failed - rc = %s\n", UsbdmSystem::getErrorString(rc));
   }
   return rc;
}

//! Closes currently open device
//!
//! @return \n
//!     BDM_RC_OK => OK
//!

USBDM_ErrorCode ICP_Close(void) {
   LOGGING_Q;
//   uint8_t debugCommand[2] = {sizeof(debugCommand),BDM_DBG_TESTALTSPEED};

   log.print("ICP_Close(): Trying to close the device\n");
   return BDM_RC_OK;
}


//====================================================================
//! Reboot to ICP mode
//!
//! The USBDM BDM does a reset to ICP mode
//!
//! @note Communication is lost.  \n
//!
void ICP_Reboot(void) {
   LOGGING;
//   static const unsigned char message[] = { 5, CMD_USBDM_ICP_BOOT, 'B', 'O', 'O', 'T' };

   bdm_usb_raw_send_ep0(ICP_REBOOT,     // bRequest
                        ('0'<<8)|'B',   // wValue
                        ('T'<<8)|'0',   // wIndex
                        0,              // wLength
                        0);             // Data to program

   UsbdmSystem::milliSleep(1000);
}
