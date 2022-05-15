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
#include "ModuleInfo.h"

/**
 * Factory base class
 */
template <class T>
class SingletonPluginFactory {

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
      LOGGING_Q;
      ModuleInfo moduleInfo = p->getModuleInfo();

      log.print("Calling destructor\n");
      p->~T();

      log.print("Deallocating storage @%p\n", p);
      ::operator delete(p);

      if (--moduleInfo.instanceCount == 0) {
         unloadClass(moduleInfo.moduleHandle);
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
   static std::shared_ptr<T> createPlugin(std::string newDllName, std::string entryPoint="createSingletonPluginInstance") {
      LOGGING;
      if (getSingletonInstance == 0) {
         loadClass(newDllName.c_str(), entryPoint.c_str());
      }
      std::shared_ptr<T> ptr = getSingletonInstance();
      log.print("Use count = %ld\n", ptr.use_count());
      return ptr;
   }

protected:
   /**
    * Load an instance of a class from a Library
    *
    * @param moduleName  Name of module (Library) to load
    *
    * Note: Searches USBDM Application directory if necessary
    */
   static void loadClass(const char *moduleName, const char *createInstanceFunctioName) {
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
      if (moduleHandle == nullptr) {
         log.print("Module \'%s\' failed to load! Retrying...\n", moduleName);
         SingletonPluginFactory::printSystemErrorMessage();

         // Try to find module in application directory
         std::string extendedPath = UsbdmSystem::getApplicationPath(moduleName);

         if (extendedPath.size() != 0) {
            log.error("Trying extended search path \'%s\'\n", extendedPath.c_str());

            moduleHandle = dlopen(extendedPath.c_str(), RTLD_LAZY);
         }
      }
      if (moduleHandle == NULL) {
         log.error("Module \'%s\' failed to load!!!\n", moduleName);
         printSystemErrorMessage();
         throw MyException(std::string("Module \'").append(moduleName).append("\' failed to load (Linux)\n"));
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
   static void unloadClass(MODULE_HANDLE moduleHandle) {
      LOGGING_Q;
      log.print("Unloading module @0x%p, cached @%p\n", moduleHandle, &moduleHandle);
      if (dlclose(moduleHandle) != 0) {
         log.print("Unloading module at @0x%p failed\n", moduleHandle);
         printSystemErrorMessage();
         // Ignore error as can't throw in destructor
      }
      log.print("Unloading module @0x%p done\n", moduleHandle);
      moduleHandle = 0;
      getSingletonInstance = 0;
   }

public:
   static void printSystemErrorMessage() {
      UsbdmSystem::Log::print("System Error: %s\n", dlerror());
   }
};

template <class T> MODULE_HANDLE SingletonPluginFactory<T>::moduleHandle = 0;
template <class T> std::shared_ptr<T> (*STD__LINKAGE SingletonPluginFactory<T>::getSingletonInstance)() = 0;

#endif /* SRC_SINGLETONPLUGINFACTORY_LINUX_H_ */
