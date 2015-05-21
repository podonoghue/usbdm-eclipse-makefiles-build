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
#include "USBDM_API_Private.h"
#include "UsbdmSystem.h"
#include "Version.h"
#include "Common.h"
#include "ICP.h"
#include "Names.h"

//==================================================================================
// Common ICP routines
//==================================================================================

static ICP_ErrorCode_t getResult(void);

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


static icpCallBackT icpCallBack = NULL;

//====================================================================
//! ICP mode - Set ICP Callback function
//!
//! @param icpCallBackT    callback function used to indicate progress
//!
//! @return
//!      - == ICP_RC_OK => success \n
//!
//! @note The callback is cleared after each ICP operation completes
//!
USBDM_API void USBDM_ICP_SetCallback(icpCallBackT icpCallBack_) {
   LOGGING_Q;
   log.print("icpCallBack_ = %p\n", icpCallBack_);
   icpCallBack = icpCallBack_;
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
//!      - != ICP_RC_OK => fail, see \ref ICP_ErrorCode_t
//!
USBDM_API ICP_ErrorCode_t USBDM_ICP_Program(unsigned int  addr,
                                            unsigned int  count,
                                            unsigned char *data) {
   LOGGING_Q;
   unsigned int dataSize; // Bytes to program this row
   ICP_ErrorCode_t rc;
   unsigned int temp;
   int doBlock;
   unsigned int doneCount     = 0;
   unsigned int originalCount = count;

   log.print("Programming [%8.8X-%8.8X]\n", addr, addr+count-1);

   // Have to program within a row in each iteration
   // so there are size and alignment issues.
   while (count > 0) {
      int percentage = (100*doneCount/originalCount);
      if (icpCallBack != NULL) {
         icpCallBack(ICP_RC_OK, percentage);
      }
      // Bytes to end of current row
      dataSize = ICP_MAX_DATA_SIZE - (addr & (ICP_MAX_DATA_SIZE - 1));
      if (dataSize > count) { // Take down to number actually remaining
         dataSize = count;
      }
      // Check if empty block (all 0xFF)
      doBlock = FALSE;
      for (temp = 0; temp < dataSize; temp++) {
         doBlock = doBlock || (data[temp] != 0xFF);
      }
      if (doBlock) { // Only program non-Blank blocks
//         print("USBDM_ICP_Program() - Programming block %4.4X-%4.4X\n", addr, addr+dataSize-1);
         log.printDump(data, dataSize);

         rc =  (ICP_ErrorCode_t)bdm_usb_raw_send_ep0(ICP_PROGRAM_ROW,
                                                     addr & 0xFFFF, // LSB address
                                                     addr >> 16, // MSB address
                                                     dataSize, data);
         if (rc != ICP_RC_OK) {
            log.print("Failed bdm_usb_raw_send_ep0()\n");
            return rc;
         }
         milliSleep(20);
         rc = getResult();

         if (rc != ICP_RC_OK) {
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
   if (icpCallBack != NULL) {
      icpCallBack(ICP_RC_OK, 100);
   }
   icpCallBack = NULL;
   return ICP_RC_OK;
}

//====================================================================
//! ICP mode - verify BDM Flash memory
//!
//! @param addr    32-bit memory address
//! @param count   number of bytes to verify
//! @param data    Pointer to buffer containing data
//!
//! @return
//!      - == ICP_RC_OK => success \n
//!      - != ICP_RC_OK => fail, see \ref ICP_ErrorCode_t
//!
USBDM_API ICP_ErrorCode_t USBDM_ICP_Verify(unsigned int  addr,
                                           unsigned int  count,
                                           unsigned char *data) {
   LOGGING_Q;
   unsigned int dataSize;
   ICP_ErrorCode_t rc;
   unsigned int doneCount     = 0;
   unsigned int originalCount = count;

   log.print("Verifying [%8.8X-%8.8X]\n", addr, addr+count-1);

   // Can verify MaxDataSize bytes at a time
   // Doesn't have alignment issues
   while (count > 0) {
      int percentage = (100*doneCount/originalCount);
      if (icpCallBack != NULL) {
//         print("USBDM_ICP_Verify() - calling icpCallBack(ICP_RC_OK, %d)\n", percentage);
         icpCallBack(ICP_RC_OK, percentage);
      }
//      else {
//         print("USBDM_ICP_Verify() - not calling icpCallBack(ICP_RC_OK, %d)\n", percentage);
//      }
      dataSize = count;
      if (dataSize > ICP_MAX_DATA_SIZE) {
         dataSize = ICP_MAX_DATA_SIZE;
      }
//      print("USBDM_ICP_Verify() - Verifying block %4.4X-%4.4X\n", addr, addr+dataSize-1);
      log.printDump(data, dataSize);

      rc =  (ICP_ErrorCode_t)bdm_usb_raw_send_ep0(ICP_VERIFY_ROW,
                                                  addr & 0xFFFF, // LSB address
                                                  addr >> 16, // MSB address
                                                  dataSize, data);
      if (rc != ICP_RC_OK) {
         // Quietly try again
         log.print("Retry\n");
         rc =  (ICP_ErrorCode_t)bdm_usb_raw_send_ep0(ICP_VERIFY_ROW,
                                                     addr & 0xFFFF, // LSB address
                                                     addr >> 16, // MSB address
                                                     dataSize, data);
      }
      if (rc != ICP_RC_OK) {
         log.print("Failed bdm_usb_raw_send_ep0()\n");
         return rc;
      }
      // A bit of a hack - delay to allow verify to complete
      milliSleep(20);
      rc = getResult();
      if (rc != ICP_RC_OK) {
         log.print("Failed icp_get_result() rc = %d, (%s)\n", rc,
               getICPErrorName(rc));
         return rc;
      }
      data      += dataSize; // update location in buffer
      addr      += dataSize; // update address
      count     -= dataSize; // update count
      doneCount += dataSize;
   }
   if (icpCallBack != NULL) {
      icpCallBack(ICP_RC_OK, 100);
   }
   icpCallBack = NULL;
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
//!      - != ICP_RC_OK => fail, see \ref ICP_ErrorCode_t
//!
//! @note Flash memory alignment requirements should be taken into account.  The
//! range erased should be a multiple of the Flash erase block size.
//!
USBDM_API ICP_ErrorCode_t USBDM_ICP_Erase(unsigned int addr,
                                          unsigned int count) {
   LOGGING_Q;
   unsigned int blockSize;
   unsigned int sectorSize = ICP_JM60_BLOCKSIZE;
   ICP_ErrorCode_t rc;
   unsigned int doneCount     = 0;
   unsigned int originalCount = count;

   log.print("Erasing [%8.8X-%8.8X]\n", addr, addr+count-1);
   USBDM_Version_t version;

   if ((USBDM_GetVersion(&version) == BDM_RC_OK) && ((version.icpHardwareVersion & 0xC0) == 0x40)) {
      sectorSize = ICP_ARM_BLOCKSIZE;
   }

   // Flash memory is organised in blocks
   // Only an entire block can be erased at a time
   while (count > 0) {
      int percentage = (100*doneCount/originalCount);
      if (icpCallBack != NULL) {
         icpCallBack(ICP_RC_OK, percentage);
      }
      blockSize = count;
      if (blockSize > sectorSize)
         blockSize = sectorSize;

//      print("USBDM_ICP_Erase() - Erasing block %8.8X-%8.8X\n", addr, addr+blockSize-1);
      rc = (ICP_ErrorCode_t)bdm_usb_raw_send_ep0(ICP_ERASE_PAGE,
                                                 addr & 0xFFFF, // LSB address
                                                 addr >> 16,    // MSB address
                                                 0,
                                                 NULL);
      if (rc != ICP_RC_OK) {
         log.print("Failed bdm_usb_raw_send_ep0()\n");
         return rc;
      }
      rc = getResult();

      if (rc != ICP_RC_OK) {
         log.print("Failed icp_get_result() rc = %d, (%s)\n", rc,
                         getICPErrorName(rc));
         return rc;
      }
      addr      += blockSize; // update address
      count     -= blockSize; // update count
      doneCount += blockSize;
   }
   if (icpCallBack != NULL) {
      icpCallBack(ICP_RC_OK, 100);
   }
   icpCallBack = NULL;
   return ICP_RC_OK;
}

//====================================================================
//! ICP mode - get result of last ICP command
//!
//! @return
//!      - == ICP_RC_OK => success \n
//!      - != ICP_RC_OK => fail, see \ref ICP_ErrorCode_t
//!
static ICP_ErrorCode_t getResult(void) {
   LOGGING;
   unsigned char buff[10];
   int rc;

   int retry = 5;
   do {
      rc = bdm_usb_raw_recv_ep0(ICP_GET_RESULT, 0, 0, sizeof(buff), buff);
      if ((rc != BDM_RC_OK) && (retry-- > 0))
         log.print("Failed (rc=%d) - retry\n", rc);
   } while ((rc != ICP_RC_OK) && (retry-- > 0));

   if (rc != ICP_RC_OK) {
      log.print("Failed\n");
   }
   return (ICP_ErrorCode_t) rc;
}
