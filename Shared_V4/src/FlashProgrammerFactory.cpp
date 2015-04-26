/*
 * FlashProgrammerFactory.cpp
 *
 *  Created on: 24 Mar 2015
 *      Author: podonoghue
 */

#include "UsbdmSystem.h"
#include "MyException.h"
#include "FlashProgrammerFactory.h"
#include "PluginFactory.h"

// ToDo : This class assumes that the programmers are loaded sequentially as it confuses different programmer DLLs

#if defined(LOG)

FlashProgrammerPtr FlashProgrammerFactory::createFlashProgrammer(BdmInterfacePtr bdmInterface) {
   LOGGING_Q;
   FlashProgrammerPtr fp;
   switch(bdmInterface->getBdmOptions().targetType) {
      case T_ARM       : fp = PluginFactory<FlashProgrammer>::createPlugin("usbdm-programmer-arm-debug.4.dll");   break;
      case T_CFV1      : fp = PluginFactory<FlashProgrammer>::createPlugin("usbdm-programmer-cfv1-debug.4.dll");  break;
      case T_CFVx      : fp = PluginFactory<FlashProgrammer>::createPlugin("usbdm-programmer-cfvx-debug.4.dll");  break;
      case T_HCS08     : fp = PluginFactory<FlashProgrammer>::createPlugin("usbdm-programmer-hcs08-debug.4.dll"); break;
      case T_HCS12     : fp = PluginFactory<FlashProgrammer>::createPlugin("usbdm-programmer-hcs12-debug.4.dll"); break;
      case T_MC56F80xx : fp = PluginFactory<FlashProgrammer>::createPlugin("usbdm-programmer-dsc-debug.4.dll");  break;
      case T_RS08      : fp = PluginFactory<FlashProgrammer>::createPlugin("usbdm-programmer-rs08-debug.4.dll");  break;
      case T_S12Z      : fp = PluginFactory<FlashProgrammer>::createPlugin("usbdm-programmer-s12z-debug.4.dll");  break;
      default: throw MyException("Target not supported");
   }
   fp->setTargetInterface(bdmInterface);
   return fp;
}

#else

FlashProgrammerPtr FlashProgrammerFactory::createFlashProgrammer(BdmInterfacePtr bdmInterface) {
   LOGGING_Q;
   FlashProgrammerPtr fp;
   switch(bdmInterface->getBdmOptions().targetType) {
      case T_ARM       : fp = PluginFactory<FlashProgrammer>::createPlugin("usbdm-programmer-arm.4.dll");    break;
      case T_CFV1      : fp = PluginFactory<FlashProgrammer>::createPlugin("usbdm-programmer-cfv1.4.dll");   break;
      case T_CFVx      : fp = PluginFactory<FlashProgrammer>::createPlugin("usbdm-programmer-cfvx.4.dll");   break;
      case T_HCS08     : fp = PluginFactory<FlashProgrammer>::createPlugin("usbdm-programmer-hcs08.4.dll");  break;
      case T_HCS12     : fp = PluginFactory<FlashProgrammer>::createPlugin("usbdm-programmer-hcs12.4.dll");  break;
      case T_MC56F80xx : fp = PluginFactory<FlashProgrammer>::createPlugin("usbdm-programmer-dsc.4.dll");  break;
      case T_RS08      : fp = PluginFactory<FlashProgrammer>::createPlugin("usbdm-programmer-rs08.4.dll");   break;
      case T_S12Z      : fp = PluginFactory<FlashProgrammer>::createPlugin("usbdm-programmer-s12z.4.dll");   break;
      default: throw MyException("Target not supported");
   }
   fp->setTargetInterface(bdmInterface);
   return fp;
}

#endif
