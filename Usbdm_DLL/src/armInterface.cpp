/*! \file
   \brief Entry points for USBDM library

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
+==================================================================================================
| 27 Jul 2015 | Reset special+hardware now sets target halt in case of failure      - pgo 4.11.1.70
| 27 Jul 2015 | bdmoptions now controls software/hardware reset method              - pgo 4.11.1.70
| 10 Feb 2015 | Changes to MDM-AP, DHCSR and DEMCR handing etc                      - pgo 4.10.6.260
|  1 Dec 2014 | Fixed format in printf()s                                           - pgo 4.10.6.230
| 12 Nov 2014 | Added armDisconnect() to allow reset behaviour to be restored       - pgo - V4.10.6.220
| 12 Nov 2014 | Refactored armConnect()                                             - pgo - V4.10.6.220
| 23 Mar 2014 | Changes to handling pendingResetRelease                             - pgo - V4.10.6.220
| 27 Dec 2012 | Added Reset rise checks to reset code                               - pgo - V4.10.4
|  1 Dec 2012 | Changed logging                                                     - pgo - V4.10.4
| 18 Nov 2012 | resetARM() now connects with reset pin asserted for H/W reset       - pgo - V4.10.4
| 17 Oct 2012 | targetDebugEnable() now sets halt-on-reset in DEMCR to capture POR  - pgo - V4.10.3
| 18 Aug 2012 | Created                                                             - pgo - V4.10.0
+==================================================================================================
\endverbatim
*/
#include <stdio.h>
#include "UsbdmSystem.h"
#include "Version.h"
#include "Common.h"
#include "Utils.h"
#include "USBDM_API.h"
#include "USBDM_API_Private.h"
#include "Names.h"
#include "TargetDefines.h"
#include "ArmDefinitions.h"
#include "armInterface.h"
#include "JTAGSequence.h"

extern USBDM_ExtendedOptions_t bdmOptions;

#define DHCSR (0xE000EDF0) // RW Debug Halting Control and Status Register
#define DCSR  (0xE000EDF4) // WO Debug Core Selector Register
#define DCDR  (0xE000EDF8) // RW Debug Core Data Register
#define DEMCR (0xE000EDFC) // RW Debug Exception and Monitor Control Register
#define DFSR  (0xE000ED30) // Debug Fault Status Register
#define AIRCR (0xE000ED0C) // Application Interrupt and Reset Control Register

//
#define JTAG16(x) (((x)>>8)&0xFF),((x)&0xFF)

// ARM JTAG Commands
#define ARM_JTAG_MASTER_IR_LENGTH   (4)     // IR length for commands below

#define JTAG_IDCODE_LENGTH          (32)
#define JTAG_IDCODE_COMMAND         (0x00)  // Device ID Code Register (IDCODE) reg
#define JTAG_EZPORT_IDCODE_LENGTH   (32)
#define JTAG_EZPORT_IDCODE_COMMAND  (0x01)  // EZPORT reg
#define JTAG_DP_ABORT_SEL_LENGTH    (35)
#define JTAG_DP_ABORT_SEL_COMMAND   (0x08)  // JTAG-DP Abort Register (ABORT)
#define JTAG_DP_DPACC_SEL_LENGTH    (35)
#define JTAG_DP_DPACC_SEL_COMMAND   (0x0A)  // JTAG-DP DP Access Register (DPACC)
#define JTAG_DP_APACC_SEL_LENGTH    (35)
#define JTAG_DP_APACC_SEL_COMMAND   (0x0B)  // JTAG-DP AP Access Register (APACC)
#define JTAG_ARM_IDCODE_LENGTH      (32)
#define JTAG_ARM_IDCODE_COMMAND     (0x0E)  // ARM Device ID Code Register (IDCODE)
#define JTAG_BYPASS_LENGTH          (1)
#define JTAG_BYPASS_COMMAND         (~0x00) // BYPASS reg

DLL_LOCAL USBDM_ErrorCode resetDebugInterface(void);

/**  Information describing the debug Interface */
static struct ARM_DebugInformation {
   // Details from AHB-AP
   uint8_t          componentClass;               //!< Component class
   uint32_t         debugBaseaddr;                //!< Base address of Debug ROM
   unsigned         size4Kb;                      //!< Size of Debug ROM
   bool             MDM_AP_present;               //!< Indicates if target has Kinetis MDM-AP
   // Memory interface capabilities
   bool             memAccessLimitsChecked;       //!< Have they been checked?
   bool             byteAccessSupported;          //!< Byte/Halfword access supported?
   uint32_t         memAPConfig;                  //!< Memory CFG register contents
} armDebugInformation = {
      0x0,
      0x0,
      0,
      false,
      false,
      false,
      0x0,
};

/** Additional bits to set when writing to DP_CONTROL/STAT register */
static const uint32_t dpControlStatBaseValue = CSYSPWRUPREQ|CDBGPWRUPREQ;


USBDM_ErrorCode targetDebugEnable();

/** Reads a word from ARM target memory
 *
 *  @note Breaks transfers on 2**10 boundary as TAR may not increment across this boundary
 *
 *  @param address  - 32-bit starting address (aligned)
 *  @param data     - pointer to buffer for word
 *
 *  @return error code
 */
static USBDM_ErrorCode armReadMemoryWord(unsigned long address, unsigned long *data) {
   LOGGING_Q;

   log.setLoggingLevel(0);
   uint8_t buff[4];
   USBDM_ErrorCode rc = USBDM_ReadMemory(4, 4, address, buff);
   *data = (buff[0])+(buff[1]<<8)+(buff[2]<<16)+(buff[3]<<24);
   switch(address) {
   case DEMCR:
      log.print("Memory[0x%08lX (DEMCR)] => 0x%08lX (%s)\n", address, *data, getDEMCRName(*data));
      break;
   case DHCSR:
      log.print("Memory[0x%08lX (DHCSR)] => 0x%08lX (%s)\n", address, *data, getDHCSRName(*data));
      break;
   case DBGMCU_CR:
      log.print("Memory[0x%08lX (STM.DBGMCU_CR)] => 0x%08lX\n", address, *data);
      break;
   default:
      log.print("Memory[0x%08lX] => 0x%08lX\n", address, *data);
      break;
   }
   return rc;
}

/** Writes a word to ARM target memory
 *
 *  @note Assumes aligned address
 *  @note Breaks transfers on 2**10 boundary as TAR may not increment across this boundary
 *
 *  @param address - 32-bit address
 *  @param data    - ptr to buffer containing words
 *
 *  @return error code
 */
static USBDM_ErrorCode armWriteMemoryWord(unsigned long address, unsigned long data) {
   LOGGING_Q;

   log.setLoggingLevel(0);
   uint8_t buff[4] = {(uint8_t)data, (uint8_t)(data>>8), (uint8_t)(data>>16), (uint8_t)(data>>24)};
   USBDM_ErrorCode rc = USBDM_WriteMemory(4, 4, address, buff);
   switch(address) {
   case DEMCR:
      log.print("Memory[0x%08lX (DEMCR)] <= 0x%08lX (%s)\n", address, data, getDEMCRName(data));
      break;
   case DHCSR:
      log.print("Memory[0x%08lX (DHCSR)] <= 0x%08lX (%s)\n", address, data, getDHCSRName(data));
      break;
   case DBGMCU_CR:
      log.print("Memory[0x%08lX (STM.DBGMCU_CR)] <= 0x%08lX\n", address, data);
      break;
   default:
      log.print("Memory[0x%08lX] <= 0x%08lX\n", address, data);
      break;
   }
   return rc;
}

/** Reset ARM-SWD target
 *
 *  @param target_mode - Reset mode \n
 *         RESET_SPECIAL/RESET_NORMAL
 */
static USBDM_ErrorCode armSoftwareReset(TargetMode_t resetMode) {
   LOGGING_Q;
   USBDM_ErrorCode rc;
   resetMode      = (TargetMode_t)(resetMode&RESET_MODE_MASK);

   // Make sure any pending hardware reset is released first
   USBDM_ControlPins(PIN_RESET_3STATE);
   UsbdmSystem::milliSleep(bdmOptions.resetRecoveryInterval);

   unsigned long demcrValue = 0;
   if (resetMode==RESET_SPECIAL) {
      log.print("Doing +Special reset\n");
      // Set catch on reset vector fetch
      demcrValue = DEMCR_VC_CORERESET;
   }
   unsigned long dhcsrValue = DHCSR_DBGKEY|DHCSR_C_DEBUGEN; //DHCSR_C_HALT

   unsigned long dbgValue   = (DBGMCU_IWDG_STOP|DBGMCU_WWDG_STOP);

   log.print("\n");

   // This may be unreliable if the target is in a reset loop

   // Try to disable watch-dog
   if (!armDebugInformation.MDM_AP_present) {
      log.print("Attempting to disable ST Watchdog\n");
      armWriteMemoryWord(DBGMCU_CR, dbgValue);
   }
   // DEMCR
   rc = armWriteMemoryWord(DEMCR, demcrValue);
   if (rc != BDM_RC_OK) {
      // Try again
      rc = armWriteMemoryWord(DEMCR, demcrValue);
   }
   if (rc != BDM_RC_OK) {
      return rc;
   }
   // DHCSR
   rc = armWriteMemoryWord(DHCSR, dhcsrValue);
   if (rc != BDM_RC_OK) {
      // Try again
      rc = armWriteMemoryWord(DHCSR, dhcsrValue);
   }
   if (rc != BDM_RC_OK) {
      return rc;
   }
   // Request system reset via AIRCR
   unsigned int aiscrValue = AIRCR_VECTKEY|AIRCR_SYSRESETREQ;
   rc = armWriteMemoryWord(AIRCR, aiscrValue);
   return rc;
}

/** Reset ARM-SWD target using Freescale Kinetis specific features
 *
 *  @param target_mode - Reset mode \n
 *         RESET_SPECIAL/RESET_NORMAL
 */
static USBDM_ErrorCode kinetisSoftwareReset(TargetMode_t resetMode) {
   LOGGING;
   USBDM_ErrorCode rc;

   rc = targetDebugEnable();
   if (rc != BDM_RC_OK) {
      return rc;
   }
   resetMode   = (TargetMode_t)(resetMode&RESET_MODE_MASK);

   log.print("Using Freescale MDM-AP\n");

   unsigned long mdm_ap_control;

   rc = USBDM_ReadCReg(ARM_CRegMDM_AP_Control, &mdm_ap_control);
   if (rc != BDM_RC_OK) {
      log.error("Checking Freescale MDM-AP.Control - failed read, rc = %d (%s)\n", rc, USBDM_GetErrorString(rc));
      mdm_ap_control = 0;
   }

   // Apply MDM-AP reset
   mdm_ap_control |= MDM_AP_Control_Debug_Request|MDM_AP_Control_System_Reset_Request;
   rc = USBDM_WriteCReg(ARM_CRegMDM_AP_Control, mdm_ap_control);

   // Release any hardware reset - ignore errors as reset will remain low
   log.error("Ignore BDM_RC_RESET_TIMEOUT_RISE as reset held low by target\n");
   (void)USBDM_ControlPins(PIN_RESET_3STATE);

   //   resetDebugInterface();

   // Set up reset capture or not
   unsigned long demcrValue = 0;
   if (resetMode==RESET_SPECIAL) {
      log.print("Doing +Special reset\n");
      // Set catch on reset vector fetch
      demcrValue = DEMCR_VC_CORERESET;
   }
   rc = armWriteMemoryWord(DEMCR, demcrValue);

   // For debug
   armReadMemoryWord(DEMCR, &demcrValue);

   UsbdmSystem::milliSleep(bdmOptions.resetDuration);

   // Release MDM-AP software reset
   mdm_ap_control &= ~(MDM_AP_Control_Debug_Request|MDM_AP_Control_System_Reset_Request);
   USBDM_ErrorCode rc2 = USBDM_WriteCReg(ARM_CRegMDM_AP_Control, mdm_ap_control);
   UsbdmSystem::milliSleep(bdmOptions.resetReleaseInterval);
   UsbdmSystem::milliSleep(bdmOptions.resetRecoveryInterval);
   if (rc2 != BDM_RC_OK) {
      return rc2;
   }

   if (rc == BDM_RC_ARM_ACCESS_ERROR) {
      // May indicate the device is secured
      unsigned long  mdmApStatus;
      rc2 = USBDM_ReadCReg(ARM_CRegMDM_AP_Status, &mdmApStatus);
      if ((rc2 == BDM_RC_OK) && ((mdmApStatus & MDM_AP_Status_System_Security) != 0)) {
         log.error("Checking Freescale MDM-AP - device is secured\n");
         return BDM_RC_SECURED;
      }
      return BDM_RC_ARM_ACCESS_ERROR;
   }
   return rc;
}

/*
 * Request reset of the ARM debug interface
 */
DLL_LOCAL
USBDM_ErrorCode resetDebugInterface(void) {
   USBDM_ErrorCode rc;

   rc = USBDM_WriteDReg(ARM_DRegCONTROL, dpControlStatBaseValue|CDBGSTREQ);
   int timeout = 5;
   unsigned long pollValue;
   do {
      USBDM_ReadDReg(ARM_DRegCONTROL, &pollValue);
//      UsbdmSystem::milliSleep(50);
   } while(((pollValue & CDBGSTACK) == 0)  && (--timeout >0));

   rc = USBDM_WriteDReg(ARM_DRegCONTROL, dpControlStatBaseValue);
   timeout = 5;
   do {
      USBDM_ReadDReg(ARM_DRegCONTROL, &pollValue);
//      UsbdmSystem::milliSleep(50);
   } while(((pollValue & CDBGSTACK) != 0)  && (--timeout >0));

   return rc;
}

/*
 *  Reset sequence for ARM-SWD or ARM-JTAG
 *
 *  @param target_mode - Reset method & mode \n
 *          RESET_DEFAULT/RESET_POWER/RESET_HARDWARE \n
 *         +RESET_SPECIAL/RESET_NORMAL
 */
DLL_LOCAL
USBDM_ErrorCode resetARM(TargetMode_t targetMode) {
   LOGGING;
   USBDM_ErrorCode rc = BDM_RC_OK;
   TargetMode_t resetMethod = (TargetMode_t)(targetMode&RESET_METHOD_MASK);
   TargetMode_t resetMode   = (TargetMode_t)(targetMode&RESET_MODE_MASK);
   log.print("%s\n", getTargetModeName((TargetMode_t)(resetMethod|resetMode)));
   if (resetMethod == RESET_DEFAULT) {
      if (bdmOptions.useResetSignal) {
         resetMethod = RESET_HARDWARE;
      }
      else {
         resetMethod = RESET_SOFTWARE;
      }
      log.print("modified=(%s)\n", getTargetModeName((TargetMode_t)(resetMethod|resetMode)));
   }
#ifdef LOG
   {
      unsigned long dhcsrValue;
      USBDM_ErrorCode rc2 = armReadMemoryWord(DHCSR, &dhcsrValue);
      if (rc2 == BDM_RC_OK) {
         log.print("Target is %s before reset\n", (dhcsrValue&(DHCSR_S_HALT|DHCSR_S_LOCKUP))?"Halted":"Running");
      }
   }
#endif

   unsigned long dhcsrValue = DHCSR_DBGKEY|DHCSR_C_DEBUGEN; //DHCSR_C_HALT
   unsigned long dbgValue   = (DBGMCU_IWDG_STOP|DBGMCU_WWDG_STOP);

   unsigned long demcrValue = 0;
   if (resetMode==RESET_SPECIAL) {
      log.print("Doing +Special reset\n");
      // Set catch on reset vector fetch
      demcrValue = DEMCR_VC_CORERESET|DEMCR_TRCENA;
      dhcsrValue |= DHCSR_C_HALT;
   }
   switch (resetMethod) {
      case RESET_ALL:
      case RESET_HARDWARE :
         // Force hardware reset
         log.print("Doing Hardware reset\n");
         USBDM_ControlPins(PIN_RESET_LOW);
         resetDebugInterface();
         do {
            // Connect with reset asserted
            // Reset requires a target connection to write target registers
            rc = USBDM_Connect();
            if (rc != BDM_RC_OK) {
               log.error("Connect failed\n");
               continue;
            }
// ToDo - add STM code
//      if (armDebugInformation.subType==TARGET_STM32F10x) {
//         // Disable watch-dog while Reset is asserted (as per STM recommendation)
//         log.print("   SWD_TargetReset()- Attempting to disable Watch-dog\n");
//         armWriteMemoryWord(DBGMCU_CR, &dbgValue);
//      }
            // DEMCR
            rc = armWriteMemoryWord(DEMCR, demcrValue);
            if (rc != BDM_RC_OK) {
               log.error("DEMCR write failed\n");
               continue;
            }
            armReadMemoryWord(DEMCR, &demcrValue);
            // DHCSR
            rc = armWriteMemoryWord(DHCSR, dhcsrValue);
            if (rc != BDM_RC_OK) {
               log.error("DHCSR write failed\n");
               continue;
            }
            UsbdmSystem::milliSleep(bdmOptions.resetDuration);
            if (!armDebugInformation.MDM_AP_present) {
               // Not Kinetis
               log.print("armSoftwareReset()- Attempting to disable ST Watchdog\n");
               armWriteMemoryWord(DBGMCU_CR, dbgValue);
            }
         } while (0);
         // Release hardware reset
         USBDM_ControlPins(PIN_RELEASE);
         UsbdmSystem::milliSleep(bdmOptions.resetRecoveryInterval);
         // Check reset rise
         rc = USBDM_ControlPins(PIN_RESET_3STATE);
         break;
      case RESET_SOFTWARE:
         log.print("Doing Software reset\n");
         // Do software (local) reset via ARM debug function
         if (armDebugInformation.MDM_AP_present) {
            kinetisSoftwareReset(targetMode);
         }
         else {
            // Default ARM software reset code
            armSoftwareReset(targetMode);
         }
         break;
      default:
         log.error("Illegal options\n");
         rc = BDM_RC_ILLEGAL_PARAMS;
         break;
   }
#ifdef LOG
   {
      unsigned long dhcsrValue;
      USBDM_ErrorCode rc2 = armReadMemoryWord(DHCSR, &dhcsrValue);
      if (rc2 == BDM_RC_OK) {
         log.print("Target is %s after reset\n", (dhcsrValue&(DHCSR_S_HALT|DHCSR_S_LOCKUP))?"Halted":"Running");
      }
   }
#endif
   return rc;
}

/*
 * Read information that describes the APs present
 */
static USBDM_ErrorCode armCheckAPs(void) {
   LOGGING_Q;
   USBDM_ErrorCode rc;
   unsigned long dataIn;

   log.print("\n");

   // Check if Kinetis MDM-AP is present
   rc = USBDM_ReadCReg(ARM_CRegMDM_AP_Ident, &dataIn);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   armDebugInformation.MDM_AP_present = ((dataIn & 0xFFFFFF00)== 0x001C0000);
   if (armDebugInformation.MDM_AP_present) {
      log.print("MDM-AP (Kinetis) found (Id=0x%08lX)\n", dataIn);
   }
   // Check if ARM AMBA-AHB-AP present
   rc = USBDM_ReadCReg(ARM_CRegAHB_AP_Id, &dataIn);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   if ((dataIn&0x0FFF000F)!= 0x04770001) {
      log.print("AMBA-AHB-AP not found (Id=0x%08lX)!\n", dataIn);
      return BDM_RC_ARM_ACCESS_ERROR;
   }
   log.print("AMBA-AHB-AP found (Id=0x%08lX)\n", dataIn);
   // Save the AHB_AP_CFG register
   rc = USBDM_ReadCReg(ARM_CRegAHB_AP_CFG, &dataIn);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   armDebugInformation.memAPConfig = dataIn;
   bool bigEndian = (dataIn&AHB_AP_CFG_BIGENDIAN)!=0;
   log.print("AHB_AP.CFG => 0x%08lX, %s\n", dataIn, bigEndian?"BigEndian":"LittleEndian");

   // Get Debug base address
   rc = USBDM_ReadCReg(ARM_CRegAHB_AP_Base, &dataIn);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   log.print("AHB_AP.Base => 0x%08lX\n", dataIn);
   armDebugInformation.debugBaseaddr = dataIn & 0xFFFFF000;

   return BDM_RC_OK;
}
#if 0
 *  Read Information that describes the debug interface
 *
static USBDM_ErrorCode armReadDebugInformation(void) {
   LOGGING_Q;
   USBDM_ErrorCode rc;

   log.print("   armReadDebugInformation()\n");

   // Read ID registers
   unsigned long buffer[4];
   for (int index=0; index<4; index++) {
      rc = armReadMemoryWord(armDebugInformation.debugBaseaddr+0xFF0+4*index, buffer+index);
      if (rc != BDM_RC_OK) {
         return rc;
      }
   }
   uint32_t id;
   id  = (buffer[0x0]&0xFF);
   id += (buffer[0x1]&0xFF)<<8;
   id += (buffer[0x2]&0xFF)<<16;
   id += (buffer[0x3]&0xFF)<<24;

   log.print("   armReadDebugInformation(): ID => 0x%08X\n", id);
   if ((id & 0xFFFF0FFF) != 0xB105000D) {
      log.error("   armReadDebugInformation(): ID invalid\n");
   }
   armDebugInformation.componentClass = (id>>12)&0xF;
   log.print("   armReadDebugInformation(): component class => 0x%X\n", armDebugInformation.componentClass);

   // Read Peripheral ID0 register
   rc = armReadMemoryWord(armDebugInformation.debugBaseaddr+0xFD0, buffer);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   id  = (buffer[0x0]>>4)&0xFF;
   armDebugInformation.size4Kb = 1<<id;
   log.print("   armReadDebugInformation(): 4Kb size => %d\n", armDebugInformation.size4Kb);
   return BDM_RC_OK;
}
#endif

DLL_LOCAL
bool armInitialiseDone = false;

/*
 * Check for target power
 */
static USBDM_ErrorCode checkTargetPower(void) {
   LOGGING;
   USBDM_ErrorCode rc = BDM_RC_OK;

   // Check for target power
   USBDMStatus_t status;
   rc = USBDM_GetBDMStatus(&status);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   if ((status.power_state != BDM_TARGET_VDD_EXT)&&(status.power_state != BDM_TARGET_VDD_INT)) {
      return BDM_RC_VDD_NOT_PRESENT;
   }
   return BDM_RC_OK;
}

/*
 *   Enable the Debug power
 */
static USBDM_ErrorCode debugPowerUp(void) {
   LOGGING_Q;
   USBDM_ErrorCode rc = BDM_RC_OK;
   unsigned long dataIn;

   // Power on and wait for power-up ACKs
   int retry = 20;
   do {
      // Power up system & debug interface
      rc = USBDM_WriteDReg(ARM_DRegCONTROL, dpControlStatBaseValue);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      rc = USBDM_ReadDReg(ARM_DRegSTATUS, &dataIn);
      log.print("DP_ControlStatus= 0x%08lX\n", dataIn);
      if (rc != BDM_RC_OK) {
         return rc;
      }
      if ((dataIn & (CSYSPWRUPACK|CDBGPWRUPACK)) == (unsigned long)(CSYSPWRUPACK|CDBGPWRUPACK)) {
         break;
      }
      UsbdmSystem::milliSleep(20);
   } while(retry-- > 0);
   if ((dataIn & (CSYSPWRUPACK|CDBGPWRUPACK)) != (unsigned long)(CSYSPWRUPACK|CDBGPWRUPACK)) {
      return BDM_RC_ARM_PWR_UP_FAIL;
   }
   log.print("System & Debug PWR-UP OK\n");
   return rc;
}

/*
 *  Initialise ARM-SWD interface
 *
 *  @note Assumes low-level SWD connection has been done
 */
static USBDM_ErrorCode armSwdInitialise() {
   LOGGING_Q;
   USBDM_ErrorCode rc = BDM_RC_OK;

   log.print("\n");

   armInitialiseDone = false;

   rc = checkTargetPower();
   if (rc != BDM_RC_OK) {
      return rc;
   }
   rc = debugPowerUp();
   if (rc != BDM_RC_OK) {
      return rc;
   }
   rc = armCheckAPs();
   if (rc != BDM_RC_OK) {
      return rc;
   }
   armInitialiseDone = true;
   return BDM_RC_OK;
}

/*! Enables the target debug interface
 *    DHCSR.C_DEBUGEN = 1
 *
 *  No changes are made if C_DEBUGEN already set, otherwise assumed first write since reset
 *    DHCSR.C_MASKINTS=0, DHCSR.C_STEP=0 - As undefined out of reset
 *    DEMCR.VC_CORERESET=1               - To capture resets
 *
 * @note Assumes low-level SWD connection has been done
 */
DLL_LOCAL
USBDM_ErrorCode targetDebugEnable() {
   LOGGING;

   if (armDebugInformation.MDM_AP_present) {
      // Check if Secured Kinetis device
      unsigned long mdm_ap_status;
      USBDM_ErrorCode rc = USBDM_ReadCReg(ARM_CRegMDM_AP_Status, &mdm_ap_status);
      if (rc != BDM_RC_OK) {
         log.error("Checking Freescale MDM-AP.Status - failed read\n");
         return rc;
      }
      if ((mdm_ap_status & MDM_AP_Status_System_Security) != 0) {
         log.error("Checking Freescale MDM-AP.Status - device is secured\n");
         return BDM_RC_SECURED;
      }
   }
   USBDM_ErrorCode rc;
   int retry = 4;
   do {
      unsigned long dhcsrValue;
      rc = armReadMemoryWord(DHCSR, &dhcsrValue);
      if (rc != BDM_RC_OK) {
         log.error("DHCSR read failed\n");
         continue;
      }
      log.print("Initial DHCSR value = %s(0x%08lX)\n", getDHCSRName(dhcsrValue), dhcsrValue);
      if ((dhcsrValue&DHCSR_C_DEBUGEN) != 0) {
         log.print("Debug Enable already set\n");
         break;
      }
      // Assume 1st connect since power-on => DHCSR.C_MASKINTS, DHCSR.C_STEP & DHCSR.C_HALT are not defined

      // Leave target halted initially
      dhcsrValue &= ~DHCSR_C_MASKINTS;  // Don't mask ints
      dhcsrValue &= ~DHCSR_C_STEP;      // Don't step
      dhcsrValue &= ~DHCSR_C_HALT;      // Don't halt
      dhcsrValue |=  DHCSR_C_DEBUGEN;   // Enable debug

      rc = armWriteMemoryWord(DHCSR, (dhcsrValue&~DHCSR_DBGKEY_MASK)|DHCSR_DBGKEY);
      if (rc != BDM_RC_OK) {
         log.error("DHCSR write failed\n");
         continue;
      }
      unsigned long dhcsrCheckValue;
      if (rc == BDM_RC_OK) {
         rc = armReadMemoryWord(DHCSR, &dhcsrCheckValue);
         if (rc != BDM_RC_OK) {
            log.error("DHCSR read failed\n");
            continue;
         }
         log.print("Final DHCSR value = %s(0x%08lX)\n", getDHCSRName(dhcsrCheckValue), dhcsrCheckValue);
      }
      if ((dhcsrCheckValue&DHCSR_C_DEBUGEN) == 0) {
         log.error("Debug enable failed\n");
         continue;
      }
      log.print("Debug Enable complete\n");

      // Set halt on reset
      unsigned long demcrValue;
      armReadMemoryWord(DEMCR, &demcrValue);
      if ((demcrValue & DEMCR_VC_CORERESET) == 0) {
         log.print("Setting halt on core reset\n");
         demcrValue |= DEMCR_VC_CORERESET;
         armWriteMemoryWord(DEMCR, demcrValue);
      }
      break;
   } while (--retry >0);
   if (retry == 0) {
      return BDM_RC_BDM_EN_FAILED;
   }
   return BDM_RC_OK;
}

/*
 *  Connect to ARM-SWD Target
 *
 *  @note Assumes low-level SWD connection has been done
 */
static USBDM_ErrorCode armSwdConnect() {
   LOGGING;
   USBDM_ErrorCode rc;
   if (!armInitialiseDone) {
      USBDM_ErrorCode rc = armSwdInitialise();
      if (rc != BDM_RC_OK) {
         return rc;
      }
   }
   rc = targetDebugEnable();
   if ((rc != BDM_RC_OK) && (rc != BDM_RC_SECURED)) {
      // Retry on failure unless because secured
      rc = armSwdInitialise();
      if (rc != BDM_RC_OK) {
         return rc;
      }
      rc = targetDebugEnable();
   }
   return rc;
}

// ARM JTAG Commands
#define ARM_JTAG_MASTER_IR_LENGTH   (4)     // IR length for commands below

/** Read IDCODE from JTAG TAP
 *
 *  @param idCode   - 32-bit IDCODE returned from TAP
 *  @param resetTAP - Optionally resets the TAP to RUN-TEST/IDLE before reading IDCODE
 *                    This will enable the MASTER TAP!
 *
 *  @note - resetTAP=true will enable the Master TAP & disable the Code TAP
 *  @note - Leaves Core TAP in RUN-TEST/IDLE
 */
static USBDM_ErrorCode readIDCODE(uint32_t *idCode, uint8_t command, uint8_t length, bool resetTAP) {
   LOGGING_E;
   // Sequence using readIdcode command to read IDCODE
   uint8_t readCoreIdCodeSequence[] = {
      JTAG_MOVE_IR_SCAN,                              // Write IDCODE command to IR
      JTAG_SET_EXIT_SHIFT_DR,
      JTAG_SHIFT_OUT_Q(ARM_JTAG_MASTER_IR_LENGTH), command,
      JTAG_SET_EXIT_IDLE,                             // Read IDCODE from DR
      JTAG_SHIFT_IN_Q(length),
      JTAG_END
   };
   // Sequence using Test-Logic-Reset to read IDCODE
   uint8_t readCoreIdCodeByResetSequence[] = {
      JTAG_TEST_LOGIC_RESET,     // Reset TAP (loads IDCODE)
      JTAG_MOVE_DR_SCAN,         // Move to scan DR reg
      JTAG_SET_EXIT_IDLE,        // Exit to idle afterwards
      JTAG_SHIFT_IN_Q(length),   // Read IDCODE from DR
      JTAG_END
   };
   JTAG32 idcode(0,32);
   USBDM_ErrorCode rc;
   if (resetTAP) {
      rc = executeJTAGSequence(sizeof(readCoreIdCodeByResetSequence), readCoreIdCodeByResetSequence,
                               4, idcode.getData(32));
   }
   else {
      rc = executeJTAGSequence(sizeof(readCoreIdCodeSequence), readCoreIdCodeSequence,
                               4, idcode.getData(32));
   }
   if (rc != BDM_RC_OK) {
      log.error("Failed, reason = %s\n", USBDM_GetErrorString(rc));
      return rc;
   }
   *idCode = idcode;
   return rc;
}

/*
 *  Initialise ARM-JTAG Target
 */
static USBDM_ErrorCode armJtagInitialise() {
   LOGGING;
   USBDM_ErrorCode rc = BDM_RC_OK;

   armInitialiseDone = false;
   rc = checkTargetPower();
   if (rc != BDM_RC_OK) {
      return rc;
   }
   // Some manufacturer's recommend doing setup with RESET active
   //   USBDM_ControlPins(PIN_RESET_LOW);

   // Read IDCODE by JTAG_RESET
   uint32_t hardwareIdcode;
   rc = readIDCODE(&hardwareIdcode, 0, JTAG_ARM_IDCODE_LENGTH, true);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   log.print("CHIP IDCODE by JTAG_RESET = 0x%08X\n", hardwareIdcode);
   if ((hardwareIdcode == 0xFFFFFFFF)||(hardwareIdcode == 0x00000000)) {
      log.error("   armJtagInitialise() CHIP IDCODE Invalid - no device?\n");
      return BDM_RC_NO_CONNECTION;
   }
   if (hardwareIdcode == ARM_Cortex_M3_IDCODE) {
      log.print("Detected ARM-Cortex3, Assuming STM chip - setting TDR=1/TIR=5\n");
      // Assume single STM32F100 for the moment
      const uint8_t sequence[] = {
            JTAG_SET_PADDING,  // #4x16-bit values - sets HDR HIR TDR TIR
            JTAG16(0), // HDR=0, No devices downstream
            JTAG16(0), // HIR=0
            JTAG16(1), // TDR=1, One device upstream with DR bypass length = 1-bit
            JTAG16(5), // TIR=5  One device upstream with IR length = 5-bits
            JTAG_END,
      };
      rc = executeJTAGSequence(sizeof(sequence), sequence, 0, NULL, true);
      if (rc != BDM_RC_OK) {
         return rc;
      }
   }
   // Try reading ARM_IDCODE using IDCODE command to check chain setup
   uint32_t idcode;
   rc = readIDCODE(&idcode, JTAG_ARM_IDCODE_COMMAND, JTAG_ARM_IDCODE_LENGTH, false);
   if (rc != BDM_RC_OK) {
      return rc;
   }
   log.print("ARM IDCODE  = 0x%08X\n", idcode);
   if (hardwareIdcode != idcode) {
      log.error("   armJtagInitialise() - IDCODEs do not agree\n");
   }
   if (idcode == ARM_Cortex_M3_IDCODE) {
      log.print("   ARM Core = ARM_Cortex_M3\n");
   }
   else if (idcode == ARM_Cortex_M4_IDCODE) {
      log.print("   ARM Core = ARM_Cortex_M4\n");
      // Read device IDCODE (Freescale only)
      rc = readIDCODE(&idcode, JTAG_IDCODE_COMMAND, JTAG_IDCODE_LENGTH, false);
      if (rc != BDM_RC_OK)
         return rc;
      log.print("JTAG IDCODE  = 0x%08X\n", idcode);
   }
   else {
      log.error("Unrecognised device\n");
      return BDM_RC_UNKNOWN_DEVICE;
   }
   rc = debugPowerUp();
   if (rc != BDM_RC_OK) {
      return rc;
   }
   rc = armCheckAPs();
   if (rc != BDM_RC_OK) {
      return rc;
   }
//   rc = armReadDebugInformation();
//   if (rc != BDM_RC_OK) {
//      return rc;
//   }
   armInitialiseDone = true;
   return BDM_RC_OK;
}

/*
 *  Connect to ARM-SWD Target
 *
 *  @note Assumes low-level SWD connection has been done
 */
DLL_LOCAL
USBDM_ErrorCode armJtagConnect() {
   LOGGING;
   USBDM_ErrorCode rc;
   log.print("Pending reset = %s\n", pendingResetRelease?"T":"F");
   if (!armInitialiseDone) {
      USBDM_ErrorCode rc = armJtagInitialise();
      if (rc != BDM_RC_OK) {
         return rc;
      }
   }
   rc = targetDebugEnable();
   if ((rc != BDM_RC_OK) && (rc != BDM_RC_SECURED)) {
      // Retry on failure unless because secured
      rc = armJtagInitialise();
      if (rc != BDM_RC_OK) {
         return rc;
      }
      rc = targetDebugEnable();
   }
   return rc;
}

/*
 *  Connect to ARM Target
 *
 *  @note Assumes low-level SWD connection has been done
 */
DLL_LOCAL
USBDM_ErrorCode armConnect(TargetType_t targetType) {
   USBDM_ErrorCode rc;

   switch(targetType) {
   case T_ARM_JTAG:
      rc = armJtagConnect();
      break;
   case T_ARM_SWD:
      rc = armSwdConnect();
      break;
   default:
      // Ignore
      rc = BDM_RC_ILLEGAL_PARAMS;
      break;
   }
   return rc;
}

/*
 *  Disconnect from ARM Target
 *
 *  @note Ignores errors
 */
DLL_LOCAL
USBDM_ErrorCode armDisconnect(TargetType_t targetType) {
   if (armInitialiseDone) {
      // Clear reset captures (ignore errors)
      armWriteMemoryWord(DEMCR, 0);
      // Disabled as immediately start target execution which I think is undesirable.
//      armWriteMemoryWord(DHCSR, DHCSR_DBGKEY);
   }
   armInitialiseDone = false;
   return BDM_RC_OK;
}

