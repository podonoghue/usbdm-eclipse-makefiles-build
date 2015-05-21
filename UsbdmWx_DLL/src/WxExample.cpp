/*
 * Example.cpp
 *
 *  Created on: 11 Apr 2015
 *      Author: podonoghue
 */

#include "WxPluginFactory.h"

#include <wx/app.h>

using namespace UsbdmWxConstants;

class OpenLog {
public:
   OpenLog() {
      UsbdmSystem::Log::openLogFile("ExampleApp.log", "Example Application");
      UsbdmSystem::Log::setLoggingLevel(100);
   }
   ~OpenLog() {
      UsbdmSystem::Log::closeLogFile();
   }
};

int main() {
   fprintf(stderr, "Starting\n");
   OpenLog openLog;
   LOGGING;
   fprintf(stderr, "After\n");

   log.print("wxTheApp  = %p\n", wxTheApp);

   log.print("Loading plug-in\n");
   WxPluginPtr p = WxPluginFactory::createWxPlugin();

   log.print("wxTheApp  = %p\n", wxTheApp);

   log.print("Calling display @0x%p\n", p.get());
   p->display("hello", "there", YES_NO|NO_DEFAULT);

   p->display("bye", "bye", YES_NO|NO_DEFAULT);

   p.reset();
   p = WxPluginFactory::createWxPlugin();

   log.print("Calling display @0x%p\n", p.get());
   p->display("hello", "there", YES_NO|NO_DEFAULT);

   p->display("bye", "bye", YES_NO|NO_DEFAULT);
   return 0;
}
