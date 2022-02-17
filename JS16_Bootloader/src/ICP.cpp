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

/*==================================================================================
 * Common ICP routines
 *=================================================================================*/

static int lastCommand = 0x00; //! Last command issued - used for error checking

static USBDM_ErrorCode getResult(void);

// Based on Freescale Application Note AN3958
enum {                    // Command       BmRequest bRequest wValue         wIndex       wLength       Data
   ICP_PROGRAM    = 0x61, // Program       $40       $61      Start Address  End Address  Data Length   Data
   ICP_MASS_ERASE = 0x63, // Mass Erase    $40       $63      $0000          $0000        $0000         N/A
   ICP_ERASE      = 0x64, // Erase Block   $40       $62      Start Address  End Address  $0000
   ICP_REBOOT     = 0x68, // Verify Row    $40       $68      $0000          $0000        $0000         N/A
   ICP_CRC_CHECK  = 0x69, // Verify Row    $40       $69      $0000          $0000        $0000         N/A
   ICP_GET_RESULT = 0x6F, // Get Result    $C0       $6F      $0000          $0000        $0001         Result $01 => success
};

/**
 *  ICP mode - reboot
 *
 *  The BDM does a normal reset
 *
 *  Used in ICP mode to reset to normal (BDM) mode.
 *
 *  @note Communication is lost.  \n
 *        The BDM will do the usual flash validity checks before entering BDM mode.
 */
void ICP_Reboot(void) {
   LOGGING_E;

   lastCommand = ICP_REBOOT;

   USBDM_ErrorCode rc = (USBDM_ErrorCode)bdm_usb_raw_send_ep0(ICP_REBOOT, 0, 0, 0, 0);
   if (rc != BDM_RC_OK) {
      log.print("Failed bdm_usb_raw_send_ep0()\n");
      return;
   }
}

/**
 *  ICP mode - program BDM Flash memory
 *
 *  @param addr    Memory address (32-bit)
 *  @param count   Number of bytes to program
 *  @param data    Pointer to buffer containing data
 *
 *  @return BDM_RC_OK  => success \n
 *  @return Error code => \ref USBDM_ErrorCode
 */
USBDM_ErrorCode ICP_Program(
      unsigned int         addr,
      unsigned int         count,
      unsigned char       *data,
      ProgressDialoguePtr  progressCallback) {

   LOGGING_Q;

   unsigned int dataSize; // Bytes to program this row
   USBDM_ErrorCode rc;
   unsigned int temp;
   int doBlock;
   unsigned int doneCount     = 0;

   lastCommand = ICP_PROGRAM;

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
         doBlock = (data[temp] != 0xFF);
         if (doBlock) {
            break;
         }
      }
      if (doBlock) { // Only program non-Blank blocks
         log.print("Programming icp-block %4.4X-%4.4X\n", addr, addr+dataSize-1);
         log.printDump(data, dataSize, addr);

         rc =  (USBDM_ErrorCode)bdm_usb_raw_send_ep0(
               ICP_PROGRAM,     // bRequest
               addr,            // wValue  = Start address
               addr+dataSize-1, // wIndex  = End address
               dataSize,        // wLength = # bytes
               data,            // Data to program
               20 /* ms */);
         if (rc != BDM_RC_OK) {
            log.print("Failed bdm_usb_raw_send_ep0()\n");
            return rc;
         }
         // Wait 5ms before we try to get the result to ensure that the
         // operation won't still be in progress the first time getResult()
         // polls the device. This avoids an extra 100ms retry timeout that
         // getResult() would otherwise add.
         // The delay was increased to 5 ms as there seems to be some timing problem
         // on fast machines.
         UsbdmSystem::milliSleep(5);
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

/**
 *  ICP mode - erase BDM Flash memory
 *
 *  @param addr    32-bit memory address
 *  @param count   number of bytes to erase
 *
 *
 *  @return BDM_RC_OK  => success \n
 *  @return Error code => \ref USBDM_ErrorCode
 *
 *  @note Flash memory alignment requirements should be taken into account.  The
 *  range erased should be a multiple of the Flash erase block size.
 */
USBDM_ErrorCode ICP_MassErase(ProgressDialoguePtr progressCallback) {

   LOGGING;
   USBDM_ErrorCode rc;

   lastCommand = ICP_MASS_ERASE;

   // It appears that the Mass erase is completed BEFORE sending the ACK for this packet
   // This is the reason for the large timeout
   // Mass erase ~200ms from data sheet
   rc = (USBDM_ErrorCode)bdm_usb_raw_send_ep0(ICP_MASS_ERASE, 0, 0, 0, 0, 1000 /* ms */);
   if (rc != BDM_RC_OK) {
      log.print("Failed bdm_usb_raw_send_ep0()\n");
      return rc;
   }
   rc = getResult();
   if (rc != BDM_RC_OK) {
      log.print("Failed icp_get_result() rc = %d, (%s)\n", rc,
            UsbdmSystem::getErrorString(rc));
      return rc;
   }
   return BDM_RC_OK;
}

/**
 *  ICP mode - get result of last ICP command
 *
 *
 *  @return BDM_RC_OK  => success \n
 *  @return Error code => \ref USBDM_ErrorCode
 */
static USBDM_ErrorCode getResult(void) {
   LOGGING_Q;

   unsigned char buff[1] = {0x00};
   USBDM_ErrorCode rc;

   int retry = 5;
   do {
      rc = bdm_usb_raw_recv_ep0(ICP_GET_RESULT, 0, 0, sizeof(buff), buff, 20 /* ms */);
      if ((rc == BDM_RC_OK) && (buff[0] != 0x01)) {
         // Error response from JS16
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

/* =============================================================================
 * =============================================================================
 * ============================================================================*/

bool initialised = false;

/**
 * Initialises USB interface
 *
 *  This must be done before any other operations.
 *
 *  @return BDM_RC_OK  => success \n
 *  @return Error code => \ref USBDM_ErrorCode
 */
USBDM_ErrorCode ICP_Init(void) {
   LOGGING;

   USBDM_ErrorCode rc = bdm_usb_init();

   initialised = (rc == BDM_RC_OK);

   return rc;
}

/**  Clean up
 *
 *  This must be called after all USBDM operations are finished
 *
 *  @return BDM_RC_OK  => success \n
 *  @return Error code => \ref USBDM_ErrorCode
 */
USBDM_ErrorCode ICP_Exit(void) {
   LOGGING_E;

   USBDM_ErrorCode rc = bdm_usb_exit();

   initialised = false;

   return rc;
}

/* =============================================================================
 * USBDM Device handling
 * ============================================================================*/

/**
 *  Find USBDM Devices
 *
 *  This function creates an internal list of USBDM devices.  The list is held until
 *  ICP_ReleaseDevices() is called. \n
 *  ICP_FindDevices() must be done before any device may be opened.
 *
 *  @param deviceCount Number of BDM devices found
 *
 *  @return BDM_RC_OK              => success \n
 *  @return BDM_RC_NO_ICP_DEVICE   => No devices found.
 *  @return Error code             => \ref USBDM_ErrorCode
 *
 *  @note deviceCount == 0 on any error so may be used w/o checking rc
 *  @note The device list is held until ICP_ReleaseDevices() is called
 */
USBDM_ErrorCode ICP_FindDevices(unsigned int *deviceCount) {
   LOGGING_E;

   USBDM_ErrorCode rc;

   *deviceCount = 0;
   static const UsbId usbIds[] = {
         {JS16_BOOT_VID, JS16_BOOT_PID},
         {0,0}
   };
   // look for USBDM devices on all USB busses
   rc = bdm_usb_findDevices(deviceCount, usbIds);
   log.print("ICP_FindDevices(): USB initialised, found %d device(s)\n", *deviceCount);
   return rc;
}

/**
 *  Release USBDM Device list
 *
 *  @return BDM_RC_OK              => success \n
 *  @return Error code             => \ref USBDM_ErrorCode
 */

USBDM_ErrorCode ICP_ReleaseDevices(void) {
   LOGGING_E;

   return bdm_usb_releaseDevices();
}

/**
 *   Opens a device
 *
 *  @param deviceNo Number (0..N) of device to open.
 *  A device must be open before any communication with the device can take place.
 *
 *  @note The range of device numbers must be obtained from ICP_FindDevices() before
 *  calling this function.
 *
 *  @return BDM_RC_OK              => success \n
 *  @return Error code             => \ref USBDM_ErrorCode
 */
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

/**
 *  Closes currently open device
 *
 *  @return BDM_RC_OK              => success \n
 */
USBDM_ErrorCode ICP_Close(void) {
   LOGGING_Q;
   //   uint8_t debugCommand[2] = {sizeof(debugCommand),BDM_DBG_TESTALTSPEED};

   log.print("ICP_Close(): Trying to close the device\n");
   return BDM_RC_OK;
}

