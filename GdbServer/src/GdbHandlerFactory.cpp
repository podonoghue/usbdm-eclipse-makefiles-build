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
      TargetType_t               targetType,
      GdbInOut                  *gdbInOut,
      BdmInterfacePtr            bdmInterface,
      DeviceInterfacePtr         deviceInterface,
      GdbHandler::GdbCallback    gdbCallBackPtr,
      IGdbTty                   *tty) {
   switch(targetType) {
      case T_ARM   : return GdbHandlerPtr(createARMGdbHandler(gdbInOut, bdmInterface, deviceInterface, gdbCallBackPtr, tty));
      case T_CFV1  : return GdbHandlerPtr(createCFV1GdbHandler(gdbInOut, bdmInterface, deviceInterface, gdbCallBackPtr, tty));
      case T_CFVx  : return GdbHandlerPtr(createCFVxGdbHandler(gdbInOut, bdmInterface, deviceInterface, gdbCallBackPtr, tty));
      default: throw new MyException("Target not supported");
   }
}
