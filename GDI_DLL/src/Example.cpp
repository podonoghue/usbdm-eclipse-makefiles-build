/*
 * Example.cpp
 *
 *  Created on: 8 Apr 2015
 *      Author: podonoghue
 */

#include "UsbdmSystem.h"
#include "GDI.h"
#include <stdio.h>
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
   printf("Opening log file\n");
   OpenLog openLog;
   LOGGING;

   printf("Opening GDI\n");
   DiGdiOpen(0, 0, 0, 0, 0);
   printf("Initialising GDI\n");
   DiGdiInitIO(0);
   printf("Closing GDI\n");
   DiGdiClose(true);

   return 0;
}

