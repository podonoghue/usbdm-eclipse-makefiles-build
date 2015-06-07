/*
 * MetrowerksInterface.h
 *
 *  Created on: 20/11/2010
 *      Author: podonoghue
 */

#ifndef METROWERKSINTERFACE_H_
#define METROWERKSINTERFACE_H_

#include "GDI.h"

#include <string.h>

#include "BdmInterface.h"
#include "DeviceData.h"

class DeviceData;

DiReturnT getAttribute(const char *key, int *value, int defaultValue);
USBDM_ErrorCode getDeviceData(TargetType_t targetType, DeviceDataPtr &deviceData);
USBDM_ErrorCode loadSettings(BdmInterfacePtr bdmInterface);

// Unused
DiReturnT mtwksDisplayLine(const char *format, ...);

/*! \brief Informs Codewarrior of MEE ID
 *
 *  @param dnExecId ID to use
 */
DiReturnT mtwksSetMEE(DiUInt32T dnExecId);

void setCallback( DiCallbackT dcCallbackType, CallbackF Callback );

USBDM_ErrorCode loadNames(std::string &deviceName, std::string &projectPath);

#endif // METROWERKSINTERFACE_H_
