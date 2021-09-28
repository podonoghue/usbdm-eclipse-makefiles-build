/*
 * GdbHandlerFactory.h
 *
 *  Created on: 24 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_GDBHANDLERFACTORY_H_
#define SRC_GDBHANDLERFACTORY_H_

#include "IGdbTty.h"
#include "GdbHandler.h"
#include "DeviceInterface.h"

class GdbHandlerFactory {
public:
   static GdbHandlerPtr createGdbHandler(
         TargetType_t                  targetType,
         GdbHandler::GdbHandlerOwner  &owner,
         GdbInOut                     *gdbInOut,
         BdmInterfacePtr               bdmInterface,
         DeviceInterfacePtr            deviceInterface,
         IGdbTty                       *tty);

protected:
   GdbHandlerFactory() {};
   ~GdbHandlerFactory() {};
};

#endif /* SRC_GDBHANDLERFACTORY_H_ */
