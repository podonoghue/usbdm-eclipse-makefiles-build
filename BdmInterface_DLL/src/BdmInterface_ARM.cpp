/*
 * BdmInterfaceARM.cpp
 *
 *  Created on: 13 Apr 2015
 *      Author: podonoghue
 */

#include "BdmInterface_ARM.h"
#include "PluginHelper.h"

BdmInterface_ARM::BdmInterface_ARM() : BdmInterfaceCommon(T_ARM) {
}

BdmInterface_ARM::~BdmInterface_ARM() {
}

USBDM_ErrorCode BdmInterface_ARM::targetConnectWithRetry(USBDMStatus_t *usbdmStatus, RetryMode retryMode) {
   LOGGING;
   USBDM_ErrorCode rc = connect();
   if (rc != BDM_RC_OK) {
      log.print("Doing 1st retry\n");
      rc = connect(); // retry
      if ((rc != BDM_RC_OK) && ((retryMode&BdmInterface::retryByReset) != 0)) {
         log.print("Doing retry under reset\n");
         controlPins(PIN_RESET_LOW);
         rc = connect(); // retry
      }
   }
   return rc;
}

USBDM_ErrorCode BdmInterface_ARM::writePC(unsigned long regValue) {
   return USBDM_WriteReg(ARM_RegPC, regValue);
}

USBDM_ErrorCode BdmInterface_ARM::readPC(unsigned long *regValue) {
   return USBDM_ReadReg(ARM_RegPC, regValue);
}

/*
 * Create the plugin instance
 */
extern "C"
size_t CPP_DLL_EXPORT createPluginInstance(void *pp) {
   return TcreatePluginInstance<BdmInterface_ARM>(pp);
}
