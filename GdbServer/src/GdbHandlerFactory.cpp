/*
 * GdbHandlerFactory.cpp
 *
 *  Created on: 24 Mar 2015
 *      Author: podonoghue
 */

#include "MyException.h"
#include "GdbHandlerFactory.h"

#include "GdbHandler_ARM.h"
#include "GdbHandler_CFV1.h"
#include "GdbHandler_CFVx.h"

GdbHandlerPtr GdbHandlerFactory::createGdbHandler(
      TargetType_t                  targetType,
      GdbHandler::GdbHandlerOwner  &owner,
      GdbInOut                     *gdbInOut,
      BdmInterfacePtr               bdmInterface,
      DeviceInterfacePtr            deviceInterface,
      IGdbTty                       *tty) {
   switch(targetType) {
      case T_ARM   : return GdbHandlerPtr(createARMGdbHandler(owner, gdbInOut, bdmInterface, deviceInterface, tty));
      case T_CFV1  : return GdbHandlerPtr(createCFV1GdbHandler(owner, gdbInOut, bdmInterface, deviceInterface, tty));
      case T_CFVx  : return GdbHandlerPtr(createCFVxGdbHandler(owner, gdbInOut, bdmInterface, deviceInterface, tty));
      default: throw new MyException("Target not supported");
   }
}
