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
#include <string.h>

#include "USBDM_API.h"
#include "low_level_usb.h"
#include "USBDM_API_Private.h"
#include "UsbdmSystem.h"
#include "Version.h"
#include "Common.h"
#include "ICP.h"
#include "Names.h"
#include "ProgressDialogueFactory.h"

//==================================================================================
// Common ICP routines
//==================================================================================

static USBDM_ErrorCode getResult(void);

//====================================================================
//! Set BDM for ICP mode & immediately reboots
//!
//! The BDM resets in ICP mode after this command
//! @note Communication is lost.
//!
USBDM_API void USBDM_RebootToICP(void) {
   LOGGING;
   static const unsigned char message[] = { 5, CMD_USBDM_ICP_BOOT, 'B', 'O', 'O', 'T' };
   (void) bdm_usb_send_ep0(message); // USB transfer may be incomplete
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
USBDM_API void USBDM_ICP_Reboot(void) {
   LOGGING;
   uint8_t message[] = { 2, ICP_REBOOT };

   (void) bdm_usb_send_ep0(message); // USB transfer may be incomplete
}

class DummyCallback : public ProgressDialogue {
public:
   DummyCallback() {};
   virtual ~DummyCallback() {};
   virtual bool pulse(std::string) { return true; }
   virtual bool update(int amount, std::string message="") { return true; }
   virtual bool incrementalUpdate(int relativeAmount, std::string message="") { return true; }
   virtual bool percentageUpdate(int percent, std::string message="") { return true; }
   virtual void setRange(int maximum) {};
   virtual void close() {}
};

DummyCallback dummyCallback;

static ProgressDialogue *icpCallBack = &dummyCallback;

//====================================================================
//! ICP mode - Set ICP Callback function
//!
//! @param icpCallBackT    callback function used to indicate progress
//!
//! @return
//!      - == BDM_RC_OK => success \n
//!
//! @note The callback should be cleared after each ICP operation completes
//!
USBDM_API void USBDM_ICP_SetCallback(ProgressDialogue *icp_CallBack) {
   LOGGING_Q;
   log.print("icpCallBack_ = %p\n", icp_CallBack);
   if (icp_CallBack == 0) {
      icp_CallBack = &dummyCallback;
   }
   icpCallBack = icp_CallBack;
}

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
USBDM_API USBDM_ErrorCode USBDM_ICP_Program(unsigned int  addr,
                                            unsigned int  count,
                                            unsigned char *data) {
   LOGGING;
   unsigned int dataSize; // Bytes to program this row
   USBDM_ErrorCode rc;
   unsigned int temp;
   int doBlock;
   unsigned int doneCount     = 0;

   log.print("Programming [%8.8X-%8.8X]\n", addr, addr+count-1);

   // Have to program within a row in each iteration
   // so there are size and alignment issues.
   while (count > 0) {
      // Bytes to end of current row
      dataSize = ICP_MAX_DATA_SIZE - (addr & (ICP_MAX_DATA_SIZE - 1));
      if (dataSize > count) { // Take down to number actually remaining
         dataSize = count;
      }
      icpCallBack->incrementalUpdate(dataSize);
      // Check if empty block (all 0xFF)
      doBlock = false;
      for (temp = 0; temp < dataSize; temp++) {
         doBlock = doBlock || (data[temp] != 0xFF);
      }
      if (doBlock) { // Only program non-Blank blocks
//         print("USBDM_ICP_Program() - Programming block %4.4X-%4.4X\n", addr, addr+dataSize-1);
         log.printDump(data, dataSize, addr);

         rc =  (USBDM_ErrorCode)bdm_usb_raw_send_ep0(ICP_PROGRAM_ROW,
                                                     addr & 0xFFFF, // LSB address
                                                     addr >> 16, // MSB address
                                                     dataSize, data);
         if (rc != BDM_RC_OK) {
            log.print("Failed bdm_usb_raw_send_ep0()\n");
            return rc;
         }
         UsbdmSystem::milliSleep(20);
         rc = getResult();

         if (rc != BDM_RC_OK) {
            log.print("Failed icp_get_result() rc = %d\n", rc);
            return rc;
         }
      }
//      else {
//         print("USBDM_ICP_Program() - Skipping block    %4.4X-%4.4X\n", addr, addr+dataSize-1);
//      }
      data      += dataSize; // update location in buffer
      addr      += dataSize; // update address
      count     -= dataSize; // update count
      doneCount += dataSize;
   }
   return BDM_RC_OK;
}

//====================================================================
//! ICP mode - verify BDM Flash memory
//!
//! @param addr    32-bit memory address
//! @param count   number of bytes to verify
//! @param data    Pointer to buffer containing data
//!
//! @return
//!      - == BDM_RC_OK => success \n
//!      - != BDM_RC_OK => fail, see \ref USBDM_ErrorCode
//!
USBDM_API USBDM_ErrorCode USBDM_ICP_Verify(unsigned int  addr,
                                           unsigned int  count,
                                           unsigned char *data) {
   LOGGING_Q;
   unsigned int dataSize;
   USBDM_ErrorCode rc;
   unsigned int doneCount     = 0;

   log.print("Verifying [%8.8X-%8.8X]\n", addr, addr+count-1);

   // Can verify MaxDataSize bytes at a time
   // Doesn't have alignment issues
   while (count > 0) {
      dataSize = count;
      if (dataSize > ICP_MAX_DATA_SIZE) {
         dataSize = ICP_MAX_DATA_SIZE;
      }
//      print("USBDM_ICP_Verify() - Verifying block %4.4X-%4.4X\n", addr, addr+dataSize-1);
      log.printDump(data, dataSize);

      rc =  (USBDM_ErrorCode)bdm_usb_raw_send_ep0(ICP_VERIFY_ROW,
                                                  addr & 0xFFFF, // LSB address
                                                  addr >> 16, // MSB address
                                                  dataSize, data);
      icpCallBack->incrementalUpdate(dataSize);
      if (rc != BDM_RC_OK) {
         // Quietly try again
         log.print("Retry\n");
         rc =  (USBDM_ErrorCode)bdm_usb_raw_send_ep0(ICP_VERIFY_ROW,
                                                     addr & 0xFFFF, // LSB address
                                                     addr >> 16, // MSB address
                                                     dataSize, data);
      }
      if (rc != BDM_RC_OK) {
         log.print("Failed bdm_usb_raw_send_ep0()\n");
         return rc;
      }
      // A bit of a hack - delay to allow verify to complete
      UsbdmSystem::milliSleep(20);
      rc = getResult();
      if (rc != BDM_RC_OK) {
         log.print("Failed icp_get_result() rc = %d, (%s)\n", rc,
               getICPErrorName(rc));
         return rc;
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
USBDM_API USBDM_ErrorCode USBDM_ICP_Erase(unsigned int addr,
                                          unsigned int count) {
   LOGGING;
   unsigned int blockSize;
   unsigned int sectorSize = ICP_JM60_BLOCKSIZE;
   USBDM_ErrorCode rc;
   unsigned int doneCount     = 0;

   log.print("Erasing [%8.8X-%8.8X]\n", addr, addr+count-1);
   USBDM_Version_t version;

   if ((USBDM_GetVersion(&version) == BDM_RC_OK) && ((version.icpHardwareVersion & 0xC0) == 0x40)) {
      sectorSize = ICP_ARM_BLOCKSIZE;
   }

   // Flash memory is organised in blocks
   // Only an entire block can be erased at a time
   while (count > 0) {
      blockSize = count;
      if (blockSize > sectorSize) {
         blockSize = sectorSize;
      }
//      print("USBDM_ICP_Erase() - Erasing block %8.8X-%8.8X\n", addr, addr+blockSize-1);
      rc = (USBDM_ErrorCode)bdm_usb_raw_send_ep0(ICP_ERASE_PAGE,
                                                 addr & 0xFFFF, // LSB address
                                                 addr >> 16,    // MSB address
                                                 0,
                                                 NULL);
      icpCallBack->incrementalUpdate(blockSize);
      if (rc != BDM_RC_OK) {
         log.print("Failed bdm_usb_raw_send_ep0()\n");
         return rc;
      }
      rc = getResult();

      if (rc != BDM_RC_OK) {
         log.print("Failed icp_get_result() rc = %d, (%s)\n", rc,
                         getICPErrorName(rc));
         return rc;
      }
      addr      += blockSize; // update address
      count     -= blockSize; // update count
      doneCount += blockSize;
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
   LOGGING;
   unsigned char buff[10];
   USBDM_ErrorCode rc;

   int retry = 5;
   do {
      rc = bdm_usb_raw_recv_ep0(ICP_GET_RESULT, 0, 0, sizeof(buff), buff);
      if ((rc != BDM_RC_OK) && (retry > 0)) {
         log.error("Failed (rc=%s) - retry\n", UsbdmSystem::getErrorString(rc));
      }
   } while ((rc != BDM_RC_OK) && (retry-- > 0));

   if (rc == BDM_RC_OK) {
      // USB operation OK - get USBDM error code from response
      rc = (USBDM_ErrorCode)buff[0];
   }
   if (rc != BDM_RC_OK) {
      log.error("Failed (rc=%s)\n", UsbdmSystem::getErrorString(rc));
   }
   return rc;
}
