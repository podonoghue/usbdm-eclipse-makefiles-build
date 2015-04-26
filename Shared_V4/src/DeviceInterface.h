/*
 * Shared.cpp
 *
 *  Created on: 18/12/2012
 *      Author: PODonoghue
 */

#ifndef BDM_DEVICEINTERFACE_H
#define BDM_DEVICEINTERFACE_H

#include <tr1/memory>

#include "USBDM_API.h"
#include "UsbdmSystem.h"
#include "DeviceData.h"
#include "AppSettings.h"
#include "BdmInterface.h"

class DeviceInterface {

public:
   DeviceDataBasePtr  getDeviceDatabase()              { return deviceDatabase; }
   DeviceDataPtr&     getCurrentDevice()               { return currentDevice; }
   int                getCurrentDeviceIndex()          { return currentDeviceIndex; }

   DeviceInterface(TargetType_t targetType);
   virtual ~DeviceInterface();

   virtual USBDM_ErrorCode loadDeviceDatabase(void);
   virtual USBDM_ErrorCode setCurrentDeviceByIndex(int deviceIndex);
   virtual USBDM_ErrorCode setCurrentDeviceByName(std::string name);
   virtual void loadSettings(const AppSettings &settings);
   virtual void saveSettings(AppSettings &settings);
private:
   TargetType_t       targetType;
   DeviceDataBasePtr  deviceDatabase;                  //!< Database of available devices
   DeviceDataPtr      currentDevice;                   //!< Currently selected device
   int                currentDeviceIndex;              //!< Index of current device
};

typedef std::tr1::shared_ptr<DeviceInterface> DeviceInterfacePtr;

#endif /* BDM_DEVICEINTERFACE_H */
