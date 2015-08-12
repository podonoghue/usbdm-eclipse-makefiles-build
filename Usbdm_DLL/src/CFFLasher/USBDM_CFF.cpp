/*! \file
   USBDM_CFF.cpp

   \brief Entry points for USBDM_CFF library

   \verbatim
   USBDM interface DLL
   Copyright (C) 2008  Peter O'Donoghue

   Based on
      Opensource BDM  - interface DLL

   which is based on
      TBDML interface DLL by
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
+===========================================================================================
|  1 Dec 2014 | Fixed format in printf()s                                     - pgo 4.10.6.230
| 17 Mar 2012 | Implemented some missing functions _ta(),_bkpt(),             - pgo - V4.9.3
+===========================================================================================
\endverbatim
*/

#include "Common.h"
#include "UsbdmSystem.h"
#include "USBDM_API.h"
#include "USBDM_API_Private.h"
#include "USBDM_CFF.h"
#include "low_level_usb.h"

static bool initDone = false;

extern USBDM_ExtendedOptions_t bdmOptions;

CFF_API int bdm_close_device(void) {
   LOGGING_E;
   USBDM_Close();
   initDone = false;
   return 0;
}

CFF_API int bdm_configure(void) {
   LOGGING_E;
   unsigned deviceCount;
   if (USBDM_Init() != BDM_RC_OK) {
      return 1;
   }
   if (USBDM_FindDevices(&deviceCount) != BDM_RC_OK) {
      return 1;
   }
   if (USBDM_Open(0) != BDM_RC_OK) {
      return 1;
   }
   initDone = true;
   return 0;
}

CFF_API int bdm_init_device(void) {
   LOGGING_E;
   TargetType_t targetType = T_CFVx;

   if (!initDone) {
      bdm_configure();
   }

   // Set up sensible defaults since we can't change this
   USBDM_ExtendedOptions_t bdmOptions = {sizeof(USBDM_ExtendedOptions_t)};
   bdmOptions.targetType         = targetType;
   USBDM_GetDefaultExtendedOptions(&bdmOptions);
   bdmOptions.targetVdd          = BDM_TARGET_VDD_3V3;
   bdmOptions.autoReconnect      = AUTOCONNECT_STATUS;
   bdmOptions.guessSpeed         = FALSE;
   bdmOptions.cycleVddOnConnect  = FALSE;
   bdmOptions.cycleVddOnReset    = FALSE;
   bdmOptions.leaveTargetPowered = FALSE;
   bdmOptions.bdmClockSource     = CS_DEFAULT;
   bdmOptions.useResetSignal     = TRUE;
   bdmOptions.usePSTSignals      = FALSE;

   if (USBDM_SetExtendedOptions(&bdmOptions) != BDM_RC_OK) {
      return 0;
   }
   if (USBDM_SetTargetType(targetType) != BDM_RC_OK) {
      return 0;
   }
   if (USBDM_Connect() != BDM_RC_OK) {
      return 0;
   }
   return 1;
}

CFF_API int bdm_reset(void) {
   LOGGING_E;
   if (USBDM_TargetReset((TargetMode_t)(RESET_SPECIAL|RESET_HARDWARE)) != BDM_RC_OK) {
      return 0;
   }
   if (USBDM_Connect() != BDM_RC_OK) {
      return 0;
   }
   return 1;
}
CFF_API int bdm_force_bdm(void) {
   LOGGING_E;
   if (USBDM_TargetReset((TargetMode_t)(RESET_SPECIAL|RESET_HARDWARE)) != BDM_RC_OK) {
      return 0;
   }
   if (USBDM_TargetHalt() != BDM_RC_OK) {
      return 0;
   }
   return 1;
}
CFF_API int bdm_go(void) {
   LOGGING_E;
   if (USBDM_TargetGo() != BDM_RC_OK) {
      return 0;
   }
   return 1;
}
CFF_API int bdm_test_for_halt(void) {
   LOGGING_E;

   USBDMStatus_t USBDMStatus;
   USBDM_GetBDMStatus(&USBDMStatus);

   if (bdmOptions.usePSTSignals) {
      // Check processor state using PST signals
      if (USBDMStatus.halt_state == TARGET_HALTED) {
         return 1;
      }
      else {
         return 0;
      }
   }
   else {
      // Probe D0 register - if fail assume processor running!
      unsigned long int dummy;
      if (USBDM_ReadReg(CFVx_RegD0, &dummy) == BDM_RC_OK) {
         return 1;
      }
      else {
         return 0;
      }
   }
}
CFF_API int bdm_write_dreg(int regNo, unsigned long value) {
   LOGGING_E;
   USBDM_WriteReg(CFVx_RegD0+regNo, value);
   return 1;
}
CFF_API int bdm_read_dreg(int regNo) {
   LOGGING_E;
   unsigned long temp;

   USBDM_ReadReg(CFVx_RegD0+regNo, &temp);
   log.print("CFF-bdm_read_dreg(%d) => 0x%08lX\n", regNo, temp);
   return temp;
}
CFF_API int bdm_read_areg(int regNo) {
   LOGGING_E;
   unsigned long temp;

   USBDM_ReadReg(CFVx_RegA0+regNo, &temp);
   log.print("CFF-bdm_read_dreg(%d) => 0x%08lX\n", regNo, temp);
   return temp;
}
CFF_API int bdm_write_areg(int regNo, unsigned long value) {
   LOGGING_Q;
   log.print(" - %d, 0x%08lX\n", regNo, value);
   USBDM_WriteReg(CFVx_RegA0+regNo, value);
   return 1;
}
CFF_API int bdm_wcreg(int regNo, unsigned long value) {
   LOGGING_Q;
   log.print("- 0x%04X, 0x%08lX\n", regNo, value);
   USBDM_WriteCReg(regNo, value);
   return 0;
}
CFF_API int bdm_rcreg(int regNo) {
   LOGGING_Q;
   unsigned long temp;
   USBDM_ReadCReg(CFVx_RegD0+regNo, &temp);
   log.print("(%04X) => 0x%08lX\n", regNo, temp);
   return temp;
}
CFF_API int bdm_rdmreg(int regNo) {
   LOGGING_Q;
   unsigned long temp = 0;
   USBDM_ReadDReg(HCS08_DRegBKPT+regNo, &temp);
   log.print("(%04X) => 0x%08lX - dummy\n", regNo, temp);
   return temp;
}
CFF_API int bdm_wdmreg(int regNo, unsigned long value) {
   LOGGING_Q;
   log.print("(0x%04X, 0x%08lX)\n", regNo, value);
   USBDM_WriteDReg(regNo, value);
   return 0;
}

CFF_API int bdm_fillb(unsigned long address, unsigned char *data, unsigned long byteCount) {
   LOGGING_Q;
   log.print("(0x%08lX,0x%08lX,%p)\n", address, byteCount, data);
   USBDM_WriteMemory(1, byteCount, address, data);
   return 0;
}
CFF_API int bdm_fillw(unsigned long address, unsigned char *data, unsigned long byteCount) {
   LOGGING_Q;
   log.print("(0x%08lX,0x%08lX,%p)\n", address, byteCount, data);
   USBDM_WriteMemory(2, byteCount, address, data);
   return 0;
}
CFF_API int bdm_filll(unsigned long address, unsigned char *data, unsigned long byteCount) {
   LOGGING_Q;
   log.print("(0x%08lX,0x%08lX,%p)\n", address, byteCount, data);
   USBDM_WriteMemory(4, byteCount, address, data);
   return 0;
}

CFF_API int bdm_dumpb(unsigned long address, unsigned char *data, unsigned long byteCount) {
   LOGGING_Q;
   log.print("CFF-bdm_dumpb(0x%08lX,0x%08lX,%p)\n", address, byteCount, data);
   USBDM_ReadMemory(1, byteCount, address, data);
   return 0;
}
CFF_API int bdm_dumpw(unsigned long address, unsigned char *data, unsigned long byteCount) {
   LOGGING_Q;
   log.print("CFF-bdm_dumpw(0x%08lX,0x%08lX,%p)\n", address, byteCount, data);
   USBDM_ReadMemory(2, byteCount, address, data);
   return 0;
}
CFF_API int bdm_dumpl(unsigned long address, unsigned char *data, unsigned long byteCount) {
   LOGGING_Q;
   log.print("CFF-bdm_dumpl(0x%08lX,0x%08lX,%p)\n", address, byteCount, data);
   USBDM_ReadMemory(4, byteCount, address, data);
   return 0;
}
CFF_API int bdm_nop(void) {
   LOGGING_Q;
   log.print("- ignored\n");
   return 0;
}
CFF_API int bdm_ta(void) {
   LOGGING_E;
   USBDM_ControlPins(PIN_TA_LOW, 0);
   UsbdmSystem::milliSleep(500 /* ms */);
   USBDM_ControlPins(PIN_RELEASE, 0);
   return 0;
}
CFF_API int bdm_bkpt(void) {
   LOGGING_E;
   USBDM_ControlPins(PIN_BKPT_LOW, 0);
   UsbdmSystem::milliSleep(500 /* ms */);
   USBDM_ControlPins(PIN_RELEASE, 0);
   return 0;
}
CFF_API int bdm_write_byte(unsigned long address, unsigned long value) {
   LOGGING_Q;
   log.print("(0x%08lX, 0x%08lX)\n", address, value);
   uint8_t data;
   data = value;
   USBDM_WriteMemory(1, 1, address, &data);
   return 0;
}
CFF_API int bdm_write_word(unsigned long address, unsigned long value) {
   LOGGING_Q;
   log.print("(0x%08lX, 0x%08lX)\n", address, value);
   uint8_t data[2];
   data[0] = value>>8;
   data[1] = value;
   USBDM_WriteMemory(2, 2, address, data);
   return 0;
}
CFF_API int bdm_write_long(unsigned long address, unsigned long value) {
   LOGGING_Q;
   log.print("(0x%08lX, 0x%08lX)\n", address, value);
   uint8_t data[4];
   data[0] = value>>24;
   data[1] = value>>16;
   data[2] = value>>8;
   data[3] = value;
   USBDM_WriteMemory(4, 4, address, data);
   return 0;
}
CFF_API int bdm_read_byte(unsigned long address) {
   LOGGING_E;
   uint8_t data;
   USBDM_ReadMemory(1, 1, address, &data);
   return data;
}
CFF_API int bdm_read_word(unsigned long address) {
   LOGGING;
   uint8_t data[2];
   unsigned long value;
   USBDM_ReadMemory(2, 2, address, data);
   value = (data[0]<<8)+data[1];
   log.print("CFF-bdm_read_word()\n");
   return value;
}
CFF_API int bdm_read_long(unsigned long address) {
   LOGGING;
   uint8_t data[4];
   unsigned long value;
   USBDM_ReadMemory(4, 4, address, data);
   value = (data[0]<<24)+(data[1]<<16)+(data[2]<<8)+data[3];
   log.print("CFF-bdm_read_long(0x%08lX) = > 0x%08lX\n", address, value);
   return value;
}

//======================================================
CFF_API int bdm_load_bin(void) {
   LOGGING_Q;
   log.print("- not implemented\n");
   return 0;
}
CFF_API int bdm_load_srec(void) {
   LOGGING_Q;
   log.print("- not implemented\n");
   return 0;
}
