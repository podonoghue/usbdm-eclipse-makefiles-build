/*! \file
    \brief Base SingletonPluginFactory for Linux

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

#ifndef SRC_SINGLETONPLUGINFACTORY_LINUX_H_
#define SRC_SINGLETONPLUGINFACTORY_LINUX_H_

#include <dlfcn.h>
#include <memory>

#include "UsbdmSystem.h"
#include "MyException.h"

/**
 * Factory base class
 */
template <class T>
class SingletonPluginFactory {

#define MODULE_HANDLE void *
#define STD__LINKAGE

protected:
   static std::shared_ptr<T> (*STD__LINKAGE getSingletonInstance)();
   static std::string dllName;
   static MODULE_HANDLE     moduleHandle;
   static int instanceCount;

   SingletonPluginFactory() {};
   ~SingletonPluginFactory() {};

protected:
   /**
    * Destructor to delete plug-in interface object
    *
    * @param p object to delete
    */
   static void deleter(T *p) {
      LOGGING;
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
   static std::shared_ptr<T> createPlugin(std::string dllName, std::string entryPoint="createSingletonPluginInstance") {
      LOGGING;
      if (getSingletonInstance == 0) {
         loadClass(dllName.c_str(), entryPoint.c_str());
      }
      std::shared_ptr<T> ptr = getSingletonInstance();
      log.print("Use count = %ld\n", ptr.use_count());
      return ptr;
   }

   /**
    * Load plugin class
    */
   static void loadClass(const char *moduleName, const char *createInstanceFunctioName);
   /**
    * Unload plug-in class
    */
   static void unloadClass();

public:
   static void printSystemErrorMessage() {
      UsbdmSystem::Log::print("System Error: %s\n", dlerror());
   }
};

template <class T> MODULE_HANDLE SingletonPluginFactory<T>::moduleHandle = 0;
template <class T> std::shared_ptr<T> (*STD__LINKAGE SingletonPluginFactory<T>::getSingletonInstance)() = 0;

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
void SingletonPluginFactory<T>::loadClass(const char *moduleName, const char *createInstanceFunctioName) {
   LOGGING;

   if (moduleHandle != NULL) {
      log.print("Module \'%s\' already loaded\n", moduleName);
      throw MyException("Module already loaded\n");
   }

#ifdef HACK_PATH_FOR_TESTING
   string extendedPath = "./";
   extendedPath.append(moduleName);

   moduleHandle = dlopen(extendedPath.c_str(), RTLD_LAZY);
#endif

   if (moduleHandle == nullptr) {
      moduleHandle = dlopen(moduleName, RTLD_LAZY);
   }
   if (moduleHandle == NULL) {
      log.print("Module \'%s\' failed to load! Retrying...\n", moduleName);
      SingletonPluginFactory::printSystemErrorMessage();


      string extendedPath = UsbdmSystem::getApplicationPath(moduleName);
      log.print("Trying extended search path \'%s\'\n", extendedPath.c_str());

      moduleHandle = dlopen(extendedPath.c_str(), RTLD_LAZY);

      if (moduleHandle == NULL) {
         log.error("Module \'%s\' failed to load!!!\n", moduleName);
         SingletonPluginFactory::printSystemErrorMessage();
         throw MyException(std::string("Module \'").append(moduleName).append("\' failed to load\n"));
      }
   }
   log.print("Module \'%s\' loaded @0x%p, handle cached @%p\n", moduleName, moduleHandle, &moduleHandle);

   getSingletonInstance  = (std::shared_ptr<T> (*STD__LINKAGE)())dlsym(moduleHandle, createInstanceFunctioName);
   if (getSingletonInstance == 0) {
      char buff[1000];
      snprintf(buff, sizeof(buff), "Entry point \'%s\' not found in module \'%s\'\n", createInstanceFunctioName, moduleName);
      throw MyException(std::string(buff));
   }
   //   log.print("Entry point \'%s\' found @0x%p\n", createInstanceFunctioName, getSingletonInstance);
}

/**
 * Unload an instance of a class from a Library
 */
template <class T>
void SingletonPluginFactory<T>::unloadClass() {
   LOGGING;
   log.print("Unloading module @0x%p, cached @%p\n", moduleHandle, &moduleHandle);
   if (dlclose(moduleHandle) != 0) {
      log.print("Unloading module at @0x%p failed\n", moduleHandle);
      SingletonPluginFactory::printSystemErrorMessage();
      // Ignore error as can't throw in destructor
   }
   log.print("Unloading module @0x%p done\n", moduleHandle);
   moduleHandle = 0;
   getSingletonInstance = 0;
}

#endif /* SRC_SINGLETONPLUGINFACTORY_LINUX_H_ */
