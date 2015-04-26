/*
 * UsbdmScript.cpp
 *
 *  Created on: 17 Apr 2015
 *      Author: podonoghue
 */

#include "UsbdmTclInterpreterFactory.h"

/*
 * ===========================================================
 */
#ifdef INTERACTIVE

class OpenLog {
public:
   OpenLog() {
      UsbdmSystem::Log::openLogFile("UsbdmScript.log", "USBDM TCL Interpreter");
      UsbdmSystem::Log::setLoggingLevel(100);
   }
   ~OpenLog() {
//      UsbdmSystem::Log::closeLogFile();
   }
};

/*
 * ===========================================================
 */

int main(int argc, char *argv[]) {
   OpenLog ol;

   UsbdmTclInterperPtr ti = UsbdmTclInterperFactory::createUsbdmTclInterper();
   ti->main(argc, argv);
}
#endif


