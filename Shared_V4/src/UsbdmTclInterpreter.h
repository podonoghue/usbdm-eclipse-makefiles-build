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

/**
 * Class representing the USBDM TCL interpreter
 */
class UsbdmTclInterpreter {

public:
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
    * Get result from last evaluation of a TCL script
    *
    *  @return string representing the result
    */
   virtual const char *getTclResult() = 0;
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
    * Set BDM interface to use
    *
    *  @param bdmInterface    BDM Interface to use
    *  @param redirectStdOut  Whether to redirect stdout to a log file
    *
    *  @return
    *      BDM_RC_OK    => OK \n
    *      other        => Error code - see \ref USBDM_ErrorCode
    */
   virtual void setBdmInterface(BdmInterfacePtr bdmInterface, bool redirectStdOut) = 0;

   virtual ~UsbdmTclInterpreter() {};

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

protected:
   UsbdmTclInterpreter(bool doInit=false) {};
};

typedef std::tr1::shared_ptr<UsbdmTclInterpreter> UsbdmTclInterperPtr;

#endif /* USBDM_TCL_INTERPRETER_H_ */
