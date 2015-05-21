/*
 * BdmInterfaceFactory.h
 *
 *  Created on: 11 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_BDMINTERFACEFACTORY_H_
#define SRC_BDMINTERFACEFACTORY_H_

#include "PluginFactory.h"
#include "BdmInterface.h"
#include "PluginFactory.h"

class BdmInterfaceFactory : PluginFactory<BdmInterface> {

public:
   // ToDo : This class assumes that the interfaces are loaded sequentially as it confuses different interface DLLs

   /**!
    * Create an instance of a BDM interface
    *
    * targetType - Type of target
    * callback   - Callback to use on error conditions.  May be null to use internal wxWidgets Dialogue
    */
   static BdmInterfacePtr createInterface(TargetType_t targetType, BdmInterface::Callback callback=0) {
      BdmInterfacePtr p;
      switch(targetType) {
         case T_OFF       : p = createPlugin(DLL_NAME("usbdm-interface-arm"), "createDefaultPluginInstance");   break;
         case T_ARM       : p = createPlugin(DLL_NAME("usbdm-interface-arm"));   break;
         case T_CFV1      : p = createPlugin(DLL_NAME("usbdm-interface-cfv1"));  break;
         case T_CFVx      : p = createPlugin(DLL_NAME("usbdm-interface-cfvx"));  break;
         case T_HCS08     : p = createPlugin(DLL_NAME("usbdm-interface-hcs08")); break;
         case T_HCS12     : p = createPlugin(DLL_NAME("usbdm-interface-hcs12")); break;
         case T_JTAG      : p = createPlugin(DLL_NAME("usbdm-interface-jtag"));  break;
         case T_RS08      : p = createPlugin(DLL_NAME("usbdm-interface-rs08"));  break;
         case T_S12Z      : p = createPlugin(DLL_NAME("usbdm-interface-s12z"));  break;
         case T_MC56F80xx : p = createPlugin(DLL_NAME("usbdm-interface-dsc"));   break;
         default:
            UsbdmSystem::Log::error("Target not supported\n");
            return p;
      }
      p->setCallback(callback);
      return p;
   }

public:
   BdmInterfaceFactory() {};
   virtual ~BdmInterfaceFactory() {};
};

#endif /* SRC_BDMINTERFACEFACTORY_H_ */
