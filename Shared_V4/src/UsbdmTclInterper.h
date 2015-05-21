/*! \file
    \brief Header file for usbdmTcl.cpp

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

#ifndef USBDMTCLINTERPRETER_H_
#define USBDMTCLINTERPRETER_H_

#include <stdbool.h>
#include "USBDM_API.h"
#include "BdmInterface.h"

class UsbdmTclInterper {

public:
   virtual USBDM_ErrorCode evalTclScript(const char *script) = 0;
   virtual const char *getTclResult() = 0;
   virtual int main(int argc, char *argv[]) = 0;
   virtual ~UsbdmTclInterper() {};
   virtual void setBdmInterface(BdmInterfacePtr bdmInterface, bool redirectStdOut) = 0;

protected:
   UsbdmTclInterper(bool doInit=false) {};
};

typedef std::tr1::shared_ptr<UsbdmTclInterper> UsbdmTclInterperPtr;

#endif /* USBDMTCLINTERPRETER_H_ */
