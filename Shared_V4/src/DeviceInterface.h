/*! \file
    \brief Header file for DeviceInterface

    \verbatim
    Copyright (C) 2015  Peter O'Donoghue

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

    Change History
   +====================================================================
   | 27 Feb 2010 | Created
   +====================================================================
    \endverbatim
*/

#ifndef BDM_DEVICEINTERFACE_H
#define BDM_DEVICEINTERFACE_H

#include <tr1/memory>

#include "USBDM_API.h"
#include "UsbdmSystem.h"
#include "DeviceData.h"
#include "AppSettings.h"
#include "BdmInterface.h"

/**
 *  Class representing a device within the device database
 */
class DeviceInterface {

public:
   /**
    * Get device database
    *
    * @return Smart pointer to device database
    */
   DeviceDataBasePtr  getDeviceDatabase()              { return deviceDatabase; }
   /**
    * Get reference to current device in device database
    *
    * @return Smart pointer to current device
    */
   DeviceDataPtr&     getCurrentDevice()               { return currentDevice; }
   /**
    * Get index of device in database
    *
    * @return index of currently selected device
    */
   int                getCurrentDeviceIndex()          { return currentDeviceIndex; }

   /**
    *  Create interface
    */
   DeviceInterface(TargetType_t targetType);
   virtual ~DeviceInterface();

   /**
    * Load device database
    *
    * @return error code
    */
   virtual USBDM_ErrorCode loadDeviceDatabase(void);
   /**
    * Select device in database by index
    *
    * @param deviceIndex Index to select device
    */
   virtual USBDM_ErrorCode setCurrentDeviceByIndex(int deviceIndex);
   /**
    * Select device in database by name
    *
    * @param name Name of device to select
    */
   virtual USBDM_ErrorCode setCurrentDeviceByName(std::string name);
   /**
    * Load settings
    *
    *  @param settings Settings object to load settings from
    */
   virtual void loadSettings(const AppSettings &settings);
   /**
    *  Save settings
    *
    *  @param settings Settings object to save settings to
    */
   virtual void saveSettings(AppSettings &settings);

private:
   TargetType_t       targetType;
   DeviceDataBasePtr  deviceDatabase;                  //!< Database of available devices
   DeviceDataPtr      currentDevice;                   //!< Currently selected device
   int                currentDeviceIndex;              //!< Index of current device
};

typedef std::tr1::shared_ptr<DeviceInterface> DeviceInterfacePtr;

#endif /* BDM_DEVICEINTERFACE_H */
