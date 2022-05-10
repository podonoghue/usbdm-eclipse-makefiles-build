/*! \file PluginFactory_Windows.h
    \brief Base PluginFactory for Windows

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
   |   6 Apr 2015 | Created
   +====================================================================
    \endverbatim
 */

#ifndef SRC_PLUGINFACTORY_WIN32_H_
#define SRC_PLUGINFACTORY_WIN32_H_

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif

#include <windows.h>
#include <memory>
#include <stdio.h>

#include "UsbdmSystem.h"
#include "MyException.h"

/**
 * Factory base class
 */
template <class T>
class PluginFactory {

#define MODULE_HANDLE HINSTANCE
#define STD__LINKAGE  __attribute__((__stdcall__))

protected:
   static std::string   dllName;
   static MODULE_HANDLE moduleHandle;
   static int           instanceCount;
   static size_t        (* STD__LINKAGE newInstance)(T*, ...);

   PluginFactory() {};
   ~PluginFactory() {};

protected:
   /**
    * Destructor to delete plug-in interface object
    *
    * @param p object to delete
    */
   static void deleter(T *p) {
      LOGGING_Q;
      log.print("Calling destructor\n");
      p->~T();
      log.print("Deallocating storage @%p\n", p);
      ::operator delete(p);
      if (--instanceCount == 0) {
         unloadClass();
      }
   }

   /**
    * Create plug-in from library
    *
    * @param dllName    String identifying the library to load
    * @param entryPoint String describing the entry point of the loaded library
    *
    * @return Smart pointer to object implementing the plug-in interface
    */
   static std::shared_ptr<T> createPlugin(std::string newDllName, std::string entryPoint="createPluginInstance") {
      LOGGING;
      if ((newInstance != 0) && (newDllName != dllName)) {
         // Different BDM interface type
         unloadClass();
      }
      if (newInstance == 0) {
         loadClass(newDllName.c_str(), entryPoint.c_str());
         dllName = newDllName;
      }
      //      log.print("Getting size\n");
      size_t classSize = (*newInstance)(0);
      //      log.print("Calling new\n");
      T* p = static_cast<T*>(::operator new(classSize));
      log.print("Allocated storage @%p, size = %lu\n", p, (long unsigned)classSize);
      //      log.print("Calling placement constructor\n");
      (*newInstance)(p);
      std::shared_ptr<T> pp(p, deleter);
      instanceCount++;
      return pp;
   }

protected:
   /**
    * Load plugin class
    */
   static void loadClass(const char *moduleName, const char *createInstanceFunctioName);
   /**
    * Unload plug-in class
    */
   static void unloadClass();

   static void printSystemErrorMessage() {
      char buffer[200];
      long dw = (long)GetLastError();

      if (!FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, 0, dw, 0, buffer, sizeof(buffer)-1, 0 )) {
         UsbdmSystem::Log::print("Failed to convert system error code %ld\n", dw);
         return;
      }
      UsbdmSystem::Log::print("System Error: %s", buffer);
   }
};

template <class T> std::string   PluginFactory<T>::dllName;
template <class T> MODULE_HANDLE PluginFactory<T>::moduleHandle = 0;
template <class T> size_t (*STD__LINKAGE PluginFactory<T>::newInstance)(T*, ...) = 0;
template <class T> int  PluginFactory<T>::instanceCount = 0;

using namespace std;

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
   LOGGING;

   if (moduleHandle != NULL) {
      log.print("Module \'%s\' already loaded\n", moduleName);
      throw MyException("Module already loaded\n");
   }

   // Load using default library path (executable directory)
   moduleHandle = LoadLibraryA(moduleName);

   if (moduleHandle == NULL) {
      log.error("Module \'%s\' failed to load using default path! Retrying...\n", moduleName);
      printSystemErrorMessage();

      // Try to find module in application directory
      string extendedPath = UsbdmSystem::getApplicationPath(moduleName);

      size_t pos = extendedPath.rfind("\\");
      if (pos != string::npos) {
         extendedPath = extendedPath.substr(0, pos);
      }
      log.error("Trying in application directory \'%s\'\n", extendedPath.c_str());
      SetDllDirectoryA(extendedPath.c_str());
      moduleHandle = LoadLibraryA(moduleName);
      SetDllDirectoryA((const char *)0);

      if (moduleHandle == NULL) {
         log.error("Module \'%s\' failed to load\n", moduleName);
         printSystemErrorMessage();
         throw MyException(std::string("Module \'").append(moduleName).append("\' failed to load (Windows)\n"));
      }
   }
   log.print("Module \'%s\' loaded @0x%p, handle cached @%p\n", moduleName, moduleHandle, &moduleHandle);
   char executableName[MAX_PATH];
   if (GetModuleFileNameA(moduleHandle, executableName, sizeof(executableName)) > 0) {
      log.print("Module path = %s\n", executableName);
   }
   newInstance = (size_t (STD__LINKAGE *)(T*, ...))GetProcAddress(moduleHandle, createInstanceFunctioName);
   if (newInstance == 0) {
      log.print("Entry point \'%s\' not found in module \'%s\'\n", createInstanceFunctioName, moduleName);
      throw MyException("Entry point not found in module");
   }
   //   log.print("Entry point \'%s\' found @0x%p\n", createInstanceFunctioName, newInstance);
}

/**
 * Unload an instance of a class from a Library
 */
template <class T>
void PluginFactory<T>::unloadClass() {
   LOGGING_Q;
   //   log.print("Unloading module @0x%p, cached @%p\n", moduleHandle, &moduleHandle);
   if (FreeLibrary(moduleHandle) == 0) {
      log.print("Unloading module at @0x%p failed\n", moduleHandle);
      printSystemErrorMessage();
      // Ignore error as can't throw in destructor
   }
   log.print("Unloading module @0x%p done\n", moduleHandle);
   moduleHandle = 0;
   newInstance = 0;
}

#endif /* SRC_PLUGINFACTORY_WIN32_H_ */
