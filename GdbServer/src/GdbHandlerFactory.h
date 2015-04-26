/*
 * GdbHandlerFactory.h
 *
 *  Created on: 24 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_GDBHANDLERFACTORY_H_
#define SRC_GDBHANDLERFACTORY_H_

#include "GdbHandler.h"
#include "DeviceInterface.h"

class GdbHandlerFactory {
public:
   static GdbHandlerPtr createGdbHandler(TargetType_t targetType, GdbInOut *gdbInOut, BdmInterfacePtr bdmInterface, DeviceInterfacePtr deviceInterface, GdbHandler::GdbCallback gdbCallBackPtr);

protected:
   GdbHandlerFactory() {};
   ~GdbHandlerFactory() {};
};

#endif /* SRC_GDBHANDLERFACTORY_H_ */
