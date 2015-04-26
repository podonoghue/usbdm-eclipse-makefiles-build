/*
 * Example.cpp
 *
 *  Created on: 8 Apr 2015
 *      Author: podonoghue
 */

#include "UsbdmSystem.h"
#include "GDI.h"

using namespace std;

class OpenLog {
public:
   OpenLog() {
      UsbdmSystem::Log::openLogFile("ExampleApp.log", "Example Application");
      UsbdmSystem::Log::setLoggingLevel(100);
   }
   ~OpenLog() {
//      UsbdmSystem::Log::closeLogFile();
   }
};

int main(void) {
   OpenLog openLog;
   LOGGING;

   DiGdiOpen(0, 0, 0, 0, 0);
   DiGdiInitIO(0);
   DiGdiClose(true);

   return 0;
}

