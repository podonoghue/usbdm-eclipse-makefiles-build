/*! \file
    \brief Header file for UsbdmTclInterpreter

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
   |   6 Apr 2011 | Created
   +====================================================================
    \endverbatim
*/

#ifndef USBDM_TCL_INTERPRETER_H_
#define USBDM_TCL_INTERPRETER_H_

#include <stdbool.h>
#include "USBDM_API.h"
#include "BdmInterface.h"
#include "DeviceData.h"
#include "ModuleInfo.h"

/**
 * Class representing the USBDM TCL interpreter
 */
class UsbdmTclInterpreter {

public:
   enum TclLinkVarType {
      TclLinkVar_int       = 1,    // TCL_LINK_INT,
      TclLinkVar_double    = 2,    // TCL_LINK_DOUBLE,
      TclLinkVar_boolean   = 3,    // TCL_LINK_BOOLEAN,
      TclLinkVar_string    = 4,    // TCL_LINK_STRING,
      TclLinkVar_wideInt   = 5,    // TCL_LINK_WIDE_INT,
   };

   enum TclSetVarFlag {
      TclSetVar_global       = 1, // TCL_GLOBAL_ONLY,
      TclSetVar_namespace    = 2, // TCL_NAMESPACE_ONLY,
   };

   /**
    * Get reference to module specific information
    */
   virtual ModuleInfo      &getModuleInfo() const = 0;

   /**
    * Destructor
    */
   virtual ~UsbdmTclInterpreter() {
   };
   /**
    * TCL mainline for stand-alone interpreter
    *
    * @param argc
    * @param argv
    *
    * @return value from main
    */
   virtual int main(int argc, char *argv[]) = 0;

   /**
    * Evaluate a TCL script
    *
    * @param script Script to evaluate
    *
    *  @return
    *      BDM_RC_OK    => OK \n
    *      other        => Error code - see \ref USBDM_ErrorCode
    */
   virtual USBDM_ErrorCode evalTclScript(const char *script) = 0;
   /**
    * Evaluates a TCL script
    *
    * @param script String containing the script to evaluate in the interpreter
    * @param result Result returned from script
    *
    *  @return
    *      BDM_RC_OK    => OK \n
    *      other        => Error code - see \ref USBDM_ErrorCode
    */
   virtual USBDM_ErrorCode  evalTclScript(const char *script, int &result) = 0;

   /**
    * Get result from last evaluation of a TCL script
    *
    *  @return string representing the result
    */
   virtual const char *getTclResult() = 0;

   /**
    * Set BDM interface to use
    *
    *  @param bdmInterface    BDM Interface to use
    *  @param redirectStdOut  Whether to redirect stdout to a log file
    *
    *  @return
    *      BDM_RC_OK    => OK \n
    *      other        => Error code - see \ref USBDM_ErrorCode
    */
   virtual USBDM_ErrorCode setBdmInterface(BdmInterfacePtr bdmInterface, bool redirectStdOut) = 0;

   /**
    * Add device parameters to TCL interpreter
    *
    * @param device       Device to use to obtain settings
    *
    * @return BDM_RC_OK  on success
    * @return Error code on failure
    */
   virtual USBDM_ErrorCode setDeviceParameters(DeviceDataConstPtr device) = 0;

   /**
    * Indicates if this is the single interactive interpreter
    */
   virtual bool isInteractive(void) {
      return false;
   }

   /**
    * Sets this interpreter as the single interactive interpreter
    */
   virtual void setInteractive(bool isInteractive = true) = 0;

   /**
    * Link C variable to TCL variable
    *
    * @param varName    // TCL Name of variable
    * @param addr       // Address of global C variable
    * @param type       // Type of C variable
    * @param readOnly   // True => readonly
    */
   virtual void linkVariable(const char *varName, void *addr, TclLinkVarType type, bool readOnly=true) = 0;

   /**
    * Unlink C variable from TCL variable
    *
    * @param varName    // TCL Name of variable
    */
   virtual void unLinkVariable(const char *varName) = 0;

   /**
    * Set TCL variable
    *
    * @param varName    // TCL Name of variable
    * @param value      // Value to set
    * @param flags      // Flags affect namespace of variable
    */
   virtual void setVariable(const char *varName, const char *value, TclSetVarFlag flags = TclSetVar_global) = 0;

   /**
    * Set TCL variable
    *
    * @param varName    // TCL Name of variable
    * @param value      // Value to set
    * @param flags      // Flags affect namespace of variable
    */
   virtual void setVariable(const char *varName, int value, TclSetVarFlag flags = TclSetVar_global) = 0;

   /**
    * Unset TCL variable
    *
    * @param varName    // TCL Name of variable
    * @param flags      // Flags affect namespace of variable
    */
   virtual void unSetVariable(const char *varName, TclSetVarFlag flags=TclSetVar_global) = 0;

protected:
   UsbdmTclInterpreter(bool doInit=false) {(void)doInit; };
};

typedef std::shared_ptr<UsbdmTclInterpreter> UsbdmTclInterperPtr;

#endif /* USBDM_TCL_INTERPRETER_H_ */
