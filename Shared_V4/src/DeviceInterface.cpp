/*
 * Shared.cpp
 *
 *  Created on: 05/07/2013
 *      Author: Peter
 */

#include "DeviceData.h"
#include "Names.h"

using namespace std;

#include "DeviceInterface.h"

/*!
 *  Load device database
 */
USBDM_ErrorCode DeviceInterface::loadDeviceDatabase(void) {
   USBDM_ErrorCode rc = BDM_RC_OK;
   if (deviceDatabase == NULL) {
      deviceDatabase.reset(new DeviceDataBase(targetType));
   }
   DeviceDataConstPtr defaultDevice = deviceDatabase->getDefaultDevice();
   currentDevice = defaultDevice->shallowCopy();
   currentDeviceIndex = 0;
   return rc;
}

#define settingsKey "DeviceInterface"

const string deviceNameKey(              settingsKey ".deviceName");
const string setClockTrimFreqKey(        settingsKey ".clockTrimFrequency");
const string clockTrimNVAddressKey(      settingsKey ".clockTrimNVAddress");
const string securityKey(                settingsKey ".security");
const string targetBusFrequencyKey(      settingsKey ".targetBusFrequency");
const string eraseMethodKey(             settingsKey ".eraseMethod");
const string resetMethodKey(             settingsKey ".resetMethod");

/*!  Select current device by device index
 *
 *   @param deviceIndex - Index into device database of desired device
 *
 *   @return true  => device is made the current device \n
 *           false => index out of range, device is set to the 1st device (index 0)
 */
USBDM_ErrorCode DeviceInterface::setCurrentDeviceByIndex(int newDeviceIndex) {
   LOGGING_Q;

//   log.print("newDeviceIndex = %d\n", newDeviceIndex);
   USBDM_ErrorCode rc = BDM_RC_OK;
   if ((newDeviceIndex < 0) || ((unsigned)newDeviceIndex >= deviceDatabase->getNumDevice())) {
      log.print("Index out of range (%d)\n", newDeviceIndex);
      newDeviceIndex = 0;
      rc = BDM_RC_UNKNOWN_DEVICE;
   }
   currentDevice = (*deviceDatabase)[newDeviceIndex].shallowCopy();
   if (currentDevice->isAlias()) {
      // Keep device name & SDIDs but update device details from real device
      string aliasedName                        = currentDevice->getTargetName();
      const std::vector<TargetSDID> targetSDIDs = currentDevice->getTargetSDIDs();
      currentDevice = deviceDatabase->findDeviceFromName(aliasedName)->shallowCopy();
      log.print("devIndex=%d, aliased(%s) => %s\n",
                     newDeviceIndex, (const char *)aliasedName.c_str(), (const char *)currentDevice->getTargetName().c_str());
      currentDevice->setTargetName(aliasedName);
      currentDevice->setTargetSDIDs(targetSDIDs);
   }
   currentDeviceIndex = newDeviceIndex;
   return rc;
}

/*!  Select current device by device name
 *
 *   @param deviceName - Name of desired device
 *
 *   @return true  => device is made the current device \n
 *           false => device not found, device is set to the default device
 */
USBDM_ErrorCode DeviceInterface::setCurrentDeviceByName(string deviceName) {
   LOGGING_Q;
   USBDM_ErrorCode rc = BDM_RC_OK;

   log.print("Device = \'%s\'\n", deviceName.c_str());
   int newDeviceIndex = deviceDatabase->findDeviceIndexFromName(deviceName);
   if (newDeviceIndex < 0) {
      log.print("Device not found (%s)\n", deviceName.c_str());
      newDeviceIndex = 0;
      rc = BDM_RC_UNKNOWN_DEVICE;
   }
   setCurrentDeviceByIndex(newDeviceIndex);
   return rc;
}

/**
 * @param targetType Type of target, affects options shown
 */
DeviceInterface::DeviceInterface(TargetType_t targetType) : targetType(targetType) {

   LOGGING_Q;
   log.print("Target Type = %s\n", getTargetTypeName(targetType));

   deviceDatabase.reset();
   currentDeviceIndex   = 0;
   loadDeviceDatabase();
   currentDevice->setSecurity(SEC_SMART);
}

DeviceInterface::~DeviceInterface() {
   LOGGING_E;
   deviceDatabase.reset();
}

/*!  Load settings from object
 *
 *  @param  settings Settings object
 */
void DeviceInterface::loadSettings(const AppSettings &settings) {
   LOGGING_E;

   // Load previous device description (fixed device data)
   setCurrentDeviceByName(settings.getValue(deviceNameKey, ""));

   // Load the trim information (mutable device data)
   currentDevice->setClockTrimFreq(                          settings.getValue(setClockTrimFreqKey,    0));
   currentDevice->setClockTrimNVAddress(                     settings.getValue(clockTrimNVAddressKey,  currentDevice->getClockTrimNVAddress()));
   SecurityOptions_t securityOption =  (SecurityOptions_t)   settings.getValue(securityKey,            currentDevice->getSecurity());
   if (securityOption == SEC_CUSTOM) {
      securityOption = SEC_UNSECURED;
   }
   currentDevice->setSecurity(securityOption);
   currentDevice->setConnectionFreq(                         settings.getValue(targetBusFrequencyKey,  0));

   currentDevice->setEraseMethod( (DeviceData::EraseMethods) settings.getValue(eraseMethodKey, currentDevice->getEraseMethod()));
   currentDevice->setResetMethod( (DeviceData::ResetMethods) settings.getValue(resetMethodKey, currentDevice->getResetMethod()));
}

/*!  Save settings to object
 *
 *  @param  settings Settings object
 */
void DeviceInterface::saveSettings(AppSettings &settings) {
   LOGGING_E;

   // Save device name
   settings.addValue(deviceNameKey,                currentDevice->getTargetName());

   // Save non-device fixed settings
   if (currentDevice->getClockTrimFreq() != 0) {
      settings.addValue(setClockTrimFreqKey,       currentDevice->getClockTrimFreq());
      settings.addValue(clockTrimNVAddressKey,     currentDevice->getClockTrimNVAddress());
   }
   SecurityOptions_t securityOption = currentDevice->getSecurity();
   if (securityOption == SEC_CUSTOM) {
      securityOption = SEC_UNSECURED;
   }
   settings.addValue(securityKey,                  securityOption);
   settings.addValue(targetBusFrequencyKey,        currentDevice->getConnectionFreq());

   settings.addValue(eraseMethodKey,          (int)currentDevice->getEraseMethod());
   settings.addValue(resetMethodKey,          (int)currentDevice->getResetMethod());

}
