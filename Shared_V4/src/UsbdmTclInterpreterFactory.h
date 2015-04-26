/*
 * UsbdmTclInterperFactory.h
 *
 *  Created on: 11 Apr 2015
 *      Author: podonoghue
 */

#ifndef SRC_UsbdmTclInterperFACTORY_H_
#define SRC_UsbdmTclInterperFACTORY_H_

#include "PluginFactory.h"
#include "UsbdmTclInterper.h"

class UsbdmTclInterperFactory: public PluginFactory<UsbdmTclInterper> {
private:
   static UsbdmTclInterperPtr createPlugin(std::string dllName) { return UsbdmTclInterperPtr(); }

public:
   static UsbdmTclInterperPtr createUsbdmTclInterper(BdmInterfacePtr bdmInterface) {
      LOGGING;
      if (newInstance == 0) {
#ifdef LOG
         loadClass("usbdm-tcl-debug.4.dll", "createPluginInstance");
#else
         loadClass("usbdm-tcl.4.dll", "createPluginInstance");
#endif
      }
      void *p =  ((void * (__attribute__((__stdcall__)) *)(BdmInterfacePtr)) newInstance)(bdmInterface);
      UsbdmTclInterperPtr pp((UsbdmTclInterper *)p);
      instanceCount++;
      return pp;
   }

   static UsbdmTclInterperPtr createUsbdmTclInterper() {
      LOGGING;
      if (newInstance == 0) {
#ifdef LOG
         loadClass("usbdm-tcl-debug.4.dll", "createScriptPluginInstance");
#else
         loadClass("usbdm-tcl.4.dll", "createScriptPluginInstance");
#endif
      }
      void *p =  ((void * (__attribute__((__stdcall__)) *)()) newInstance)();
      UsbdmTclInterperPtr pp((UsbdmTclInterper *)p);
      instanceCount++;
      return pp;
   }

public:
   UsbdmTclInterperFactory();
   virtual ~UsbdmTclInterperFactory();
};

#endif /* SRC_UsbdmTclInterperFACTORY_H_ */
