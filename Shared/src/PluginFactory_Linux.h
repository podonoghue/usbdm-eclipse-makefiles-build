/*! \file PluginFactory_Linux
    \brief Base PluginFactory for Linux

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

#ifndef SRC_PLUGINFACTORY_LINUX_H_
#define SRC_PLUGINFACTORY_LINUX_H_

#include <dlfcn.h>
#include <memory>
#include <stdio.h>

#include "ModuleInfo.h"
#include "UsbdmSystem.h"
#include "MyException.h"

/**
 * Factory base class
 */
template <class T>
class PluginFactory {

private:
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
    * Load an instance of a class from a Library
    *
    * @param moduleName  Name of module (Library) to load
    *
    * Note: Searches USBDM Application directory if necessary
    */
   static auto loadClass(const char *moduleName) {
      LOGGING;

      // Load using default library path (executable directory)
      auto moduleHandle = dlopen(moduleName, RTLD_LAZY);

      if (moduleHandle == nullptr) {
         log.error("Module \'%s\' failed to load! Retrying...\n", moduleName);
         printSystemErrorMessage();

         // Try to find module in application directory
         std::string extendedPath = UsbdmSystem::getApplicationPath(moduleName);

         if (extendedPath.size() != 0) {
            log.error("Trying extended search path \'%s\'\n", extendedPath.c_str());

            moduleHandle = dlopen(extendedPath.c_str(), RTLD_LAZY);
         }
         if (moduleHandle == nullptr) {
            log.error("Module \'%s\' failed to load!!!\n", moduleName);
            printSystemErrorMessage();
            throw MyException(std::string("Module \'").append(moduleName).append("\' failed to load (Linux)\n"));
         }
         log.error("Module \'%s\' loaded from application directory\n", moduleName);
      }
      log.print("Module \'%s\' /* loaded @0x%p, handle cached @%p */\n", moduleName, moduleHandle, &moduleHandle);

      return moduleHandle;
   }

   /**
    * Unload plug-in class
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
   }

   static void printSystemErrorMessage() {
      UsbdmSystem::Log::print("System Error: %s\n", dlerror());
   }

protected:
   PluginFactory() {};
   ~PluginFactory() {};

   /**
    * Create plug-in from library
    *
    * @param newDllName  String identifying the library to load
    * @param entryPoint  String describing the entry point of the loaded library
    *
    * @return Smart pointer to object implementing the plug-in interface
    */
   static std::shared_ptr<T> createPlugin(std::string newDllName, std::string entryPoint="createPluginInstance") {
      LOGGING;

      auto moduleHandle = loadClass(newDllName.c_str());

      auto *newInstance  = (size_t (STD__LINKAGE *)(T*, ...))dlsym(moduleHandle, entryPoint.c_str());
      if (newInstance == 0) {
         char buff[1000];
         snprintf(buff, sizeof(buff), "Entry point \'%s\' not found in module \'%s\'\n", entryPoint.c_str(), newDllName.c_str());
         throw MyException(std::string(buff));
      }
//         log.print("Entry point \'%s\' found @0x%p\n", entryPoint.c_str(), getSingletonInstance);

      //      log.print("Getting size\n");
      size_t classSize = (*newInstance)(0);

      //      log.print("Calling new\n");
      T* p = static_cast<T*>(::operator new(classSize));
      log.print("Allocated storage /* @%p, size = %lu */\n", p, (long unsigned)classSize);

      //      log.print("Calling placement constructor\n");
      (*newInstance)(p);

      ModuleInfo &moduleInfo = p->getModuleInfo();
      moduleInfo.instanceCount++;
      moduleInfo.moduleHandle = moduleHandle;

      std::shared_ptr<T> pp(p, deleter);
      return pp;
   }

};

#endif /* SRC_PLUGINFACTORY_LINUX_H_ */
