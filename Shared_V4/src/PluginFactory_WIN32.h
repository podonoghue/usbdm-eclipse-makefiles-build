/*
 * FlashProgrammerFactory_WIN32.h
 *
 *  Created on: 24 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_PLUGINFACTORY_WIN32_H_
#define SRC_PLUGINFACTORY_WIN32_H_

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif

#include <windows.h>
#include <tr1/memory>

#include "UsbdmSystem.h"
#include "MyException.h"

template <class T>
class PluginFactory {

protected:
   static std::string dllName;
   static int (*__attribute__((__stdcall__)) newInstance)(...);
   static int instanceCount;
   static HINSTANCE moduleHandle;

   PluginFactory() {};
   ~PluginFactory() {};

public:

   static std::tr1::shared_ptr<T> createPlugin(std::string dllName, std::string entryPoint="createPluginInstance") {
      LOGGING_Q;
      if (newInstance == 0) {
         loadClass(dllName.c_str(), entryPoint.c_str());
      }
      std::tr1::shared_ptr<T> pp((T*)(*newInstance)(), deleter);
      instanceCount++;
      return pp;
   }

protected:
   static void deleter(T *p) {
      LOGGING_E;
      delete p;
      if (--instanceCount == 0) {
         unloadClass();
      }
   }
   static void loadClass(const char *moduleName, const char *createInstanceFunctioName);
   static void unloadClass();
};

template <class T> HINSTANCE PluginFactory<T>::moduleHandle = 0;
template <class T> int (*__attribute__((__stdcall__))PluginFactory<T>::newInstance)(...) = 0;
template <class T> int  PluginFactory<T>::instanceCount = 0;

using namespace std;

static void printSystemErrorMessage() {
   char buffer[200];
   long dw = (long)GetLastError();

   if (!FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, 0, dw, 0, buffer, sizeof(buffer)-1, 0 )) {
       UsbdmSystem::Log::print("Failed to convert system error code %ld\n", dw);
       return;
   }
   UsbdmSystem::Log::print("System Error: %s", buffer);
}

/**
 * Load an instance of a class from a Library
 *
 * @param moduleName                Name of module (Library) to load
 * @param createInstanceFunctioName Name of function to call to create instance
 *
 * Note: Searches USBDM Application directory if necessary
 */
template <class T>
void PluginFactory<T>::loadClass(const char *moduleName, const char *createInstanceFunctioName) {
   LOGGING_Q;

   if (moduleHandle != NULL) {
      log.print("Module \'%s\' already loaded\n", moduleName);
      throw MyException("Module already loaded\n");
   }

   moduleHandle = LoadLibraryA((LPCSTR)moduleName);

   if (moduleHandle == NULL) {
//      log.print("Module \'%s\' failed to load\n", moduleName);
//      printSystemErrorMessage();

      string extendedPath = UsbdmSystem::getApplicationPath("");
//      log.print("Trying extended search path \'%s\'\n", extendedPath.c_str());
      SetDllDirectoryA(UsbdmSystem::getApplicationPath("").c_str());

      moduleHandle = LoadLibraryA((LPCSTR)moduleName);
      SetDllDirectoryA(0);

      if (moduleHandle == NULL) {
         log.error("Module \'%s\' failed to load\n", moduleName);
         printSystemErrorMessage();
         throw MyException("Module failed to load\n");
      }
   }

   log.print("Module \'%s\' loaded @0x%p\n", moduleName, moduleHandle);

   newInstance  = (int (__attribute__((__stdcall__)) *)(...))GetProcAddress(moduleHandle, createInstanceFunctioName);
   if (newInstance == 0) {
      throw MyException("Entry point not found in module\n");
   }

   log.print("Entry point \'%s\' found @0x%p\n", createInstanceFunctioName, newInstance);
}

/**
 * Unload an instance of a class from a Library
 */
template <class T>
void PluginFactory<T>::unloadClass() {
   LOGGING_Q;
   log.print("Unloading module from @0x%p\n", moduleHandle);
   if (FreeLibrary(moduleHandle) == 0) {
      printSystemErrorMessage();
      // Ignore error as can't throw in destructor
   }
   moduleHandle = 0;
   newInstance = 0;
}

#endif /* SRC_PLUGINFACTORY_WIN32_H_ */
