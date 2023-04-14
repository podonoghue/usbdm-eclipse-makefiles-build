/** \file
    \brief Factory for FlashProgrammer

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
   |    May 2015 | Created
   +====================================================================
    \endverbatim
*/
#ifndef SRC_FLASHPROGRAMMERFACTORY_H_
#define SRC_FLASHPROGRAMMERFACTORY_H_

#include "PluginFactory.h"
#include "FlashProgrammer.h"

/**
 * Factory class for programmers
 */
class FlashProgrammerFactory : PluginFactory<FlashProgrammer> {
public:
   // ToDo : This class assumes that the programmers are loaded sequentially as it confuses different programmer DLLs

   /**
    * Creates a flash programmer for the given interface
    *
    * @param bdmInterface Interface the programmer is to use
    */
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
         default:
            log.error("Illegal target\n");
            throw MyException("Target not supported");
      }
      fp->setTargetInterface(bdmInterface);
      return fp;
   }

protected:
   FlashProgrammerFactory() {};
   ~FlashProgrammerFactory() {};
};

#endif /* SRC_FLASHPROGRAMMERFACTORY_H_ */
