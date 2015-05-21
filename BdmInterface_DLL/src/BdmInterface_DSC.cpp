/*
 * BdmInterfaceDSC.cpp
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#include "BdmInterface_DSC.h"
#include "USBDM_DSC_API.h"

#include "UsbdmWxConstants.h"
#include "Utils.h"
#include "PluginHelper.h"

using namespace UsbdmWxConstants;

BdmInterface_DSC::BdmInterface_DSC() : BdmInterfaceCommon(T_MC56F80xx) {
   DSC_SetLogFile(UsbdmSystem::Log::getLogFileHandle());
}

BdmInterface_DSC::~BdmInterface_DSC() {
   DSC_SetLogFile(0);
}

//! Connects to Target (DSC only)
//!
//! @note If there are connection problems, the user may be prompted to cycle
//!       the target power on some targets.
//!
//! @param usbdmStatus Current status of the BDM, may be NULL if not needed.
//! @param retryMode   How hard to retry \n
//!     The following are silent retries: \n
//!       retryNever      - give up after basic attempt, target state not affected \n
//!      +retryByReset    - quietly retry after hardware reset (if supported by target and allows debug entry). May be combined with others. \n
//!       retryNotPartial - give up quietly if device may be secured (BDM_RC_SECURED or BDM_RC_BDM_EN_FAILED) \n
//!     The following is interactive:\n
//!       retryAlways     - retry with dialogue prompt to user \n
//!
//! @return \n
//!     BDM_RC_OK => OK \n
//!     other     => Error code - see \ref USBDM_ErrorCode
//!
USBDM_ErrorCode BdmInterface_DSC::targetConnectWithRetry(USBDMStatus_t *usbdmStatus, RetryMode retryMode) {
   LOGGING;
   log.print("%s\n", getConnectionRetryName(retryMode));

   USBDM_ErrorCode rc;
   USBDMStatus_t status;

#if 0
   rc = bdmInterface->getBDMStatus(&USBDMStatus);
   if (rc != BDM_RC_OK) {
      break;
   }
   if (retryMode & BdmInterface::retryWithInit) {
      dscInformation.size = sizeof(dscInfo_t);
      rc = DSC_GetInfo(&dscInformation);
      if (rc != BDM_RC_OK) {
         break;
      }
      rc = DSC_Initialise();
      if (rc != BDM_RC_OK) {
         break;
      }
   }
   rc = bdmInterface->connect();
   if (rc != BDM_RC_OK) {
      if (retryMode&BdmInterface::retryByReset) {
         bdmInterface->reset((TargetMode_t)(RESET_SPECIAL|RESET_DEFAULT));
      }
      rc = bdmInterface->connect(); // retry
   }
   if (rc != BDM_RC_OK) {
      break;
   }
#endif

   rc = getBDMStatus(&status);
   if (usbdmStatus != NULL) {
      *usbdmStatus = status;
   }
   if (rc != BDM_RC_OK) {
      log.error("getBDMStatus() failed\n");
      return rc; // Fatal error
   }
   //=========================================================
   //  Basic connect
   rc = DSC_Connect();
   if (rc == BDM_RC_OK) {
      if (!extendedRetry)
         log.print("Enabling Extended Retry\n");
      extendedRetry = true;
      return rc;
   }
   // Quietly retry once
   rc = DSC_Connect();
   if (rc == BDM_RC_OK) {
      if (!extendedRetry)
         log.print("Enabling Extended Retry\n");
      extendedRetry = true;
      return rc;
   }
   //===============================================
   // Connection has at least partially failed

   // Don't retry at all - silently fail
   if ((retryMode&retryMask) == retryNever) {
      log.error("Failed - No retries, rc = %s\n", USBDM_GetErrorString(rc));
      return rc;
   }

   // Inform user of error and prompt for retry
   if (extendedRetry) {
      // Update target status
      getBDMStatus(&status);
      // Connection failure - retry
      int getYesNo;
      do {
         string message;
         long style = (long)(YES_NO|YES_DEFAULT|ICON_QUESTION);
         log.error("Retry, reason = %s\n", USBDM_GetErrorString(rc));
         if (bdmOptions.targetType == T_CFVx) {
            USBDM_ControlPins(PIN_BKPT_LOW|PIN_RESET_LOW); // Set BKPT & RESET low
         }
         else if (bdmOptions.targetType == T_ARM) {
            USBDM_ControlPins(PIN_RESET_LOW); // Set RESET low
         }
         else {
            USBDM_ControlPins(PIN_BKGD_LOW|PIN_RESET_LOW); // Set BKGD & RESET low
         }
         if (retryMode&retryByPower) {
            // Try power cycle first
            USBDM_SetTargetVdd(BDM_TARGET_VDD_DISABLE);
            milliSleep(bdmOptions.powerOffDuration);
            USBDM_SetTargetVdd(BDM_TARGET_VDD_ENABLE);
            milliSleep(bdmOptions.powerOnRecoveryInterval);
            rc = retryConnection(usbdmStatus);
            if (rc == BDM_RC_OK) {
               break;
            }
         }
         // Check for 'interesting cases'
         if (status.power_state == BDM_TARGET_VDD_NONE) {
            message = "Target Vdd supply interrupted.\n\n"
                  "Please restore power to the target.\n\n"
                  "Retry connection?";
         }
         else if (status.reset_recent == RESET_DETECTED) {
            message = "Target RESET detected (watchdog?).\n\n"
                  "Please cycle power to the target.\n\n"
                  "Retry connection?";
         }
         else if (bdmOptions.cycleVddOnConnect) {
            // Target may require power cycle for guaranteed connection
            message = "Connection with the target has failed.\n\n"
                  "Target power has been cycled.\n\n"
                  "Retry connection?";
            }
         else {
            message = "Connection with the target has failed.\n\n"
                  "Please cycle power to the target.\n\n"
                  "Retry connection?";
         }
         getYesNo = callback(message,
                                "USBDM - Target Connection Failure",
                                style
                                );
         rc = retryConnection(usbdmStatus);
      } while ((rc != BDM_RC_OK) && (getYesNo == YES));
   }
   if (rc != BDM_RC_OK) {
      log.error("Failed, (disabling Extended Retry)\n");
   }
   // Only enable re-try if successful to prevent nagging
   extendedRetry = (rc == BDM_RC_OK);
   return rc;
}

USBDM_ErrorCode BdmInterface_DSC::reset(TargetMode_t mode) {
   return DSC_TargetReset(mode);
}

USBDM_ErrorCode BdmInterface_DSC::connect() {
   return DSC_Connect();
}

USBDM_ErrorCode BdmInterface_DSC::halt() {
   return DSC_TargetHalt();
}

USBDM_ErrorCode BdmInterface_DSC::go() {
   return DSC_TargetGo();
}

USBDM_ErrorCode BdmInterface_DSC::step() {
   return DSC_TargetStep();
}

USBDM_ErrorCode BdmInterface_DSC::writeReg(unsigned int reg, unsigned long value) {
   return DSC_WriteRegister(reg, value);
}

USBDM_ErrorCode BdmInterface_DSC::readReg(unsigned int reg, unsigned long *value) {
   return DSC_ReadRegister(reg, value);
}

USBDM_ErrorCode BdmInterface_DSC::readMemory(unsigned memorySpace, unsigned byteCount, unsigned address, unsigned char *data) {
   switch(memorySpace&MS_SIZE) {
   case MS_Byte:
      break;
   case MS_Word:
   case MS_Long:
      // Convert byte => word address
      if ((address & 0x01) != 0) {
         UsbdmSystem::Log::error("Illegal word address 0x%X\n", address);
         throw new MyException("Illegal word address");
      }
      address /= 2;
      break;
   }
   return DSC_ReadMemory(memorySpace, byteCount, address, data);
}

USBDM_ErrorCode BdmInterface_DSC::writeMemory(unsigned memorySpace, unsigned byteCount, unsigned address, unsigned const char *data) {
   switch(memorySpace&MS_SIZE) {
   case MS_Byte:
      break;
   case MS_Word:
   case MS_Long:
      // Convert byte => word address
      if ((address & 0x01) != 0) {
         UsbdmSystem::Log::error("Illegal word address 0x%X\n", address);
         throw new MyException("Illegal word address");
      }
      address /= 2;
      break;
   }
   return DSC_WriteMemory(memorySpace, byteCount, address, data);
}

USBDM_ErrorCode BdmInterface_DSC::writePC(unsigned long regValue) {
   return DSC_WriteRegister(DSC_RegPC, regValue);
}

USBDM_ErrorCode BdmInterface_DSC::readPC(unsigned long *regValue) {
   return DSC_ReadRegister(DSC_RegPC, regValue);
}

USBDM_ErrorCode BdmInterface_DSC::getIdcode(unsigned int *regValue) {
   return DSC_GetIdcode(regValue);
}

USBDM_ErrorCode BdmInterface_DSC::getStatus(unsigned int *status) {
   OnceStatus_t onceStatus;
   USBDM_ErrorCode rc = DSC_GetStatus(&onceStatus);
   *status = onceStatus;
   return rc;
}

/*
 * Create the plugin instance
 */
extern "C"
size_t CPP_DLL_EXPORT createPluginInstance(void *pp) {
   return TcreatePluginInstance<BdmInterface_DSC>(pp);
}
