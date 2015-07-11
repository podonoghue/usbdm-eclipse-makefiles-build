/*! \file
    \brief Factory for BdmInterface

    \verbatim
    Copyright (C) 2015  Peter O'Donoghue

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Change History
   +====================================================================
   | 16 May 2015 | Created
   +====================================================================
    \endverbatim
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
