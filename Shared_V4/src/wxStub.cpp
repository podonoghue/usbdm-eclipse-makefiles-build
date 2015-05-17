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

// The Eclipse parser is confused by the wxWidgets definitions of _WIN32 etc
#if defined(__unix__) && defined (WIN32)
#undef WIN32
#endif
#if defined(__unix__) && defined (_WIN32)
#undef _WIN32
#endif

#if !defined(CPP_DLL_LOCAL)
   #ifdef _WIN32
      //! Functions exported from a library
      #define CPP_DLL_EXPORT __declspec(dllexport)
      //! Functions imported from a library
      #define CPP_DLL_IMPORT __declspec(dllimport)
      //! Functions local to a library
      #define CPP_DLL_LOCAL  __attribute__
   #else
      //! Functions exported from a library
      #define CPP_DLL_EXPORT __attribute__ ((visibility ("default")))
      //! Functions imported from a library
      #define CPP_DLL_IMPORT __attribute__ ((visibility ("default")))
      //! Functions local to a library
      #define CPP_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
   #endif
#endif

#include "UsbdmSystem.h"

//===================================================================

#ifndef MINIMAL_APP
#define MINIMAL_APP MinimalApp
#endif

class CPP_DLL_EXPORT MINIMAL_APP : public  wxApp {

   DECLARE_CLASS( MINIMAL_APP )

public:
   MINIMAL_APP() : wxApp() {
      LOGGING_E;
      UsbdmSystem::Log::print("MINIMAL_APP()\n");
      fprintf(stderr, "wxPluginApp()");
   }

   ~MINIMAL_APP(){
      LOGGING_E;
   }
   void hello() {
      LOGGING;
   }
//#ifdef __unix__
//   bool Yield(bool onlyIfNeeded = false) {
//      UsbdmSystem::Log::print("Doing Yield()\n");
//      return false;
//   }
//#endif
};

IMPLEMENT_APP_NO_MAIN( MINIMAL_APP )
IMPLEMENT_CLASS( MINIMAL_APP, wxApp )

static bool wxInitializationDone = false;

bool __attribute__ ((constructor)) wx_dll_open(void) {
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

bool  __attribute__ ((destructor)) wx_dll_close(void) {
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

#ifdef WIN32
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
