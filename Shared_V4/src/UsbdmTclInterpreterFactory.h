/*! \file
    \brief Factory for UsbdmTclInterpreter

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
   |   6 Apr 2015 | Created
   +====================================================================
    \endverbatim
*/

#ifndef SRC_USBDM_TCL_INTERPRETER_FACTORY_H_
#define SRC_USBDM_TCL_INTERPRETER_FACTORY_H_

#include "PluginFactory.h"
#include "UsbdmTclInterpreter.h"

/**
 * Factory for creating USBDM TCL interpreters
 * This uses a plug-in approach to loading the required module
 */
class UsbdmTclInterperFactory : public PluginFactory<UsbdmTclInterpreter> {

public:
   /**
    * Create a TCL interpreter for running scripts
    *
    * @param bdmInterface Interface to use to communicate with target
    *
    * @return The interpreter created
    */
   static UsbdmTclInterperPtr createUsbdmTclInterpreter(BdmInterfacePtr bdmInterface) {
      LOGGING;
      UsbdmTclInterperPtr interpreter = createPlugin(DLL_NAME("usbdm-tcl"), "createPluginInstance");
      interpreter->setBdmInterface(bdmInterface, true);
      return interpreter;
   }

   /**
    * Create the TCL interpreter for interactive use (singleton)
    *
    * @param bdmInterface Interface to use to communicate with target
    *
    * @return The interpreter created
    */
   static UsbdmTclInterperPtr createInteractiveUsbdmTclInterpreter(BdmInterfacePtr bdmInterface) {
      LOGGING;
      UsbdmTclInterperPtr interpreter = createPlugin(DLL_NAME("usbdm-tcl"), "createPluginInstance");
      interpreter->setBdmInterface(bdmInterface, false);
      interpreter->setInteractive();
      return interpreter;
   }

private:

   UsbdmTclInterperFactory();
   virtual ~UsbdmTclInterperFactory() {};
   };

//UsbdmTclInterperPtr UsbdmTclInterperFactory::interactiveInterpreter;

#endif /* SRC_USBDM_TCL_INTERPRETER_FACTORY_H_ */
