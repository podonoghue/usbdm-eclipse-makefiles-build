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

public:
   static UsbdmTclInterperPtr createUsbdmTclInterper(BdmInterfacePtr bdmInterface) {
      LOGGING;
      UsbdmTclInterperPtr pp = createPlugin(DLL_NAME("usbdm-tcl"), "createPluginInstance");
      pp->setBdmInterface(bdmInterface, true);
      return pp;
   }

   static UsbdmTclInterperPtr createInteractiveTclInterper(BdmInterfacePtr bdmInterface) {
      LOGGING;
      UsbdmTclInterperPtr pp = createPlugin(DLL_NAME("usbdm-tcl"), "createInteractivePluginInstance");
      pp->setBdmInterface(bdmInterface, false);
      return pp;
   }

   public:
      UsbdmTclInterperFactory();
      virtual ~UsbdmTclInterperFactory();
   };

#endif /* SRC_UsbdmTclInterperFACTORY_H_ */
