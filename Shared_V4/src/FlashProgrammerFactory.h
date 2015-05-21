/*
 * FlashProgrammerFactory.h
 *
 *  Created on: 24 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_FLASHPROGRAMMERFACTORY_H_
#define SRC_FLASHPROGRAMMERFACTORY_H_

#include "PluginFactory.h"
#include "FlashProgrammer.h"

class FlashProgrammerFactory : PluginFactory<FlashProgrammer> {
public:
   // ToDo : This class assumes that the programmers are loaded sequentially as it confuses different programmer DLLs

   static FlashProgrammerPtr createFlashProgrammer(BdmInterfacePtr bdmInterface) {
      LOGGING_Q;
      FlashProgrammerPtr fp;
      switch(bdmInterface->getBdmOptions().targetType) {
         case T_ARM       : fp = createPlugin(DLL_NAME("usbdm-programmer-arm"));   break;
         case T_CFV1      : fp = createPlugin(DLL_NAME("usbdm-programmer-cfv1"));  break;
         case T_CFVx      : fp = createPlugin(DLL_NAME("usbdm-programmer-cfvx"));  break;
         case T_HCS08     : fp = createPlugin(DLL_NAME("usbdm-programmer-hcs08")); break;
         case T_HCS12     : fp = createPlugin(DLL_NAME("usbdm-programmer-hcs12")); break;
         case T_MC56F80xx : fp = createPlugin(DLL_NAME("usbdm-programmer-dsc"));   break;
         case T_RS08      : fp = createPlugin(DLL_NAME("usbdm-programmer-rs08"));  break;
         case T_S12Z      : fp = createPlugin(DLL_NAME("usbdm-programmer-s12z"));  break;
         default: throw MyException("Target not supported");
      }
      fp->setTargetInterface(bdmInterface);
      return fp;
   }

protected:
   FlashProgrammerFactory() {};
   ~FlashProgrammerFactory() {};
};

#endif /* SRC_FLASHPROGRAMMERFACTORY_H_ */
