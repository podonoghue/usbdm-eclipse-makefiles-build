/*
 * BdmInterfaceFactory.h
 *
 *  Created on: 11 Apr 2015
 *      Author: podonoghue
 */


#include "UsbdmSystem.h"
#include "MyException.h"
#include "BdmInterfaceFactory.h"
#include "PluginFactory.h"

// ToDo : This class assumes that the interfaces are loaded sequentially as it confuses different interface DLLs

#if defined(LOG)

BdmInterfacePtr BdmInterfaceFactory::createInterface(TargetType_t targetType, BdmInterface::Callback callback) {
   BdmInterfacePtr p;
   switch(targetType) {
      case T_OFF       : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-arm-debug.4.dll", "createDefaultPluginInstance");   break;
      case T_ARM       : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-arm-debug.4.dll");   break;
      case T_CFV1      : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-cfv1-debug.4.dll");  break;
      case T_CFVx      : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-cfvx-debug.4.dll");  break;
      case T_HCS08     : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-hcs08-debug.4.dll"); break;
      case T_HCS12     : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-hcs12-debug.4.dll"); break;
      case T_JTAG      : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-jtag-debug.4.dll");  break;
      case T_RS08      : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-rs08-debug.4.dll");  break;
      case T_S12Z      : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-s12z-debug.4.dll");  break;
      case T_MC56F80xx : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-dsc-debug.4.dll");   break;
      default:
         UsbdmSystem::Log::error("Target not supported\n");
         return p;
   }
   p->setCallback(callback);
   return p;
}
#else

BdmInterfacePtr BdmInterfaceFactory::createInterface(TargetType_t targetType, BdmInterface::Callback callback) {
   BdmInterfacePtr p;
   switch(targetType) {
      case T_OFF       : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-arm.4.dll", "createDefaultPluginInstance");   break;
      case T_ARM       : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-arm.4.dll");   break;
      case T_CFV1      : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-cfv1.4.dll");  break;
      case T_CFVx      : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-cfvx.4.dll");  break;
      case T_HCS08     : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-hcs08.4.dll"); break;
      case T_HCS12     : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-hcs12.4.dll"); break;
      case T_JTAG      : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-jtag.4.dll");  break;
      case T_RS08      : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-rs08.4.dll");  break;
      case T_S12Z      : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-s12z.4.dll");  break;
      case T_MC56F80xx : p = PluginFactory<BdmInterface>::createPlugin("usbdm-interface-dsc.4.dll");   break;
      default:
         UsbdmSystem::Log::error("Target not supported\n");
         return p;
   }
   p->setCallback(callback);
   return p;
}
#endif
