/*
 * DeviceTclInterface.h
 *
 *  Created on: 30Apr.,2017
 *      Author: podonoghue
 */

#ifndef SOURCE_DEVICETCLINTERFACE_H_
#define SOURCE_DEVICETCLINTERFACE_H_

#include "UsbdmTclInterpreterFactory.h"
#include "DeviceData.h"
#include "BdmInterface.h"

class DeviceTclInterface {
private:
   UsbdmTclInterperPtr     tclInterpreter;           //!< TCL interpreter

public:
   /**
    * Create TCL interpreter and initialise with device script
    */
   DeviceTclInterface(BdmInterfacePtr bdmInterface, DeviceDataPtr deviceData) {
      LOGGING_Q;
      tclInterpreter = UsbdmTclInterperFactory::createUsbdmTclInterpreter(bdmInterface);
      USBDM_ErrorCode rc = tclInterpreter->evalTclScript(deviceData->getFlashScripts()->getScript().c_str());
      if (rc != BDM_RC_OK) {
         log.error("Failed - rc = %d (%s)\n", rc, bdmInterface->getErrorString(rc));
      }
   }

   USBDM_ErrorCode runTclCommand(const char *command) const {
      if (tclInterpreter == nullptr) {
         return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
      }
      return tclInterpreter->evalTclScript(command);
   }

   USBDM_ErrorCode initTarget() const {
      return runTclCommand("initTarget");
   }

   UsbdmTclInterperPtr getTclInterper() const {
      return tclInterpreter;
   }
};

typedef std::tr1::shared_ptr<DeviceTclInterface> DeviceTclInterfacePtr;

#endif /* SOURCE_DEVICETCLINTERFACE_H_ */
