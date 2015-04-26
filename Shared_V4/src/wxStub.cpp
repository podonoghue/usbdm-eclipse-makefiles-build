/*
 * wxStub.cpp
 *
 *  DLL code to create wxApp stub for DLLs using wxWidgets
 *  Needed for applications that don't use wxWidgets as main application
 *
 *  Created on: 8 Apr 2015
 *      Author: podonoghue
 */

#include <wx/app.h>
#include "UsbdmSystem.h"

//===================================================================

#ifndef MINIMAL_APP
#define MINIMAL_APP MinimalApp
#endif

class MINIMAL_APP : public  wxApp {

   DECLARE_CLASS( MINIMAL_APP )

public:
   MINIMAL_APP() : wxApp() {
      LOGGING_E;
   }

   ~MINIMAL_APP(){
      LOGGING_E;
   }
   void hello() {
      LOGGING;
   }
};

IMPLEMENT_APP_NO_MAIN( MINIMAL_APP )
IMPLEMENT_CLASS( MINIMAL_APP, wxApp )

static bool wxInitializationDone = false;

static bool wx_dll_open(void) {
   LOGGING;

   int argc = 1;
   char  arg0[] = "usbdm";
   char *argv[]={arg0, NULL};

   if (wxTheApp == NULL) {
      wxInitializationDone = wxEntryStart(argc, argv);
      log.print("Created wxTheApp = %p\n", wxTheApp);
      log.print("AppName = %s\n", (const char *)wxTheApp->GetAppName().c_str());
      if (wxInitializationDone) {
         log.print("wxEntryStart() successful\n");
      }
      else {
         log.print("wxEntryStart() failed\n");
         return false;
      }
   }
   else {
      log.print("wxTheApp already exists - not created\n");
   }
   log.print("wxTheApp  = %p\n", wxTheApp);
   return true;
}

static bool wx_dll_close(void) {
   LOGGING_E;

   if (wxInitializationDone) {
      log.print("Doing wxEntryCleanup()\n");
      wxEntryCleanup();
      log.print("Done wxEntryCleanup()\n");
   }
   else {
      log.print("Skipped wxEntryCleanup()\n");
   }

   return true;
}

#ifdef _WIN32
#include <windef.h>

extern "C" WINAPI __declspec(dllexport)
BOOL DllMain(HINSTANCE hDLLInst, DWORD fdwReason, LPVOID lpvReserved) {
   switch (fdwReason) {
      case DLL_PROCESS_ATTACH:
         UsbdmSystem::Log::print("wxStub::DLL_PROCESS_ATTACH @0x%p\n", hDLLInst);
         wx_dll_open();
         break;
      case DLL_PROCESS_DETACH:
         UsbdmSystem::Log::print("wxStub::DLL_PROCESS_DETACH @0x%p\n", hDLLInst);
         wx_dll_close();
         break;
      case DLL_THREAD_ATTACH:
         UsbdmSystem::Log::print("wxStub::DLL_THREAD_ATTACH @0x%p\n", hDLLInst);
         break;
      case DLL_THREAD_DETACH:
         UsbdmSystem::Log::print("wxStub::DLL_THREAD_DETACH @0x%p\n", hDLLInst);
         break;
   }
   return TRUE;
}
#endif
