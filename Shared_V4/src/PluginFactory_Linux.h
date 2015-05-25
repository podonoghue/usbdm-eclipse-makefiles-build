/*
 * FlashProgrammerFactory_WIN32.h
 *
 *  Created on: 24 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_PLUGINFACTORY_WIN32_H_
#define SRC_PLUGINFACTORY_WIN32_H_

#include <dlfcn.h>
#include <tr1/memory>

#include "UsbdmSystem.h"
#include "MyException.h"

template <class T>
class PluginFactory {

protected:
   static std::string dllName;
   static size_t ((* newInstance)(...));
   static int instanceCount;
   static void *moduleHandle;
   static std::tr1::shared_ptr<T> dummy;

   PluginFactory() {};
   ~PluginFactory() {};

protected:
   static std::tr1::shared_ptr<T> createPlugin(std::string dllName, std::string entryPoint="createPluginInstance") {
      LOGGING;
      if (newInstance == 0) {
         loadClass(dllName.c_str(), entryPoint.c_str());
      }
      log.print("Getting size\n");
      size_t classSize = (*newInstance)(0);
      log.print("Calling new\n");
      void *p = ::operator new(classSize);
      log.print("Allocated storage @%p, size = %ld\n", p, (long)classSize);
      log.print("Calling placement constructor\n");
      (*newInstance)(p);
      std::tr1::shared_ptr<T> pp((T*)p, deleter);
      instanceCount++;
      return pp;
   }

protected:
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
   static void loadClass(const char *moduleName, const char *createInstanceFunctioName);
   static void unloadClass();
};

template <class T> void * PluginFactory<T>::moduleHandle = 0;
template <class T> size_t (*PluginFactory<T>::newInstance)(...) = 0;
template <class T> int  PluginFactory<T>::instanceCount = 0;
//template <class T> std::tr1::shared_ptr<WxPlugin> PluginFactory<T>::dummy;
template <class T> std::tr1::shared_ptr<T> PluginFactory<T>::dummy;

using namespace std;

static void printSystemErrorMessage() {
   UsbdmSystem::Log::print("System Error: %s\n", dlerror());
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

   moduleHandle = dlopen(moduleName, RTLD_LAZY);

   if (moduleHandle == NULL) {
      log.print("Module \'%s\' failed to load, retrying...\n", moduleName);
      printSystemErrorMessage();

      string extendedPath = UsbdmSystem::getApplicationPath(createInstanceFunctioName);
      log.print("Trying extended search path \'%s\'\n", extendedPath.c_str());

      moduleHandle = dlopen(extendedPath.c_str(), RTLD_LAZY);

      if (moduleHandle == NULL) {
         log.error("Module \'%s\' failed to load\n", moduleName);
         printSystemErrorMessage();
         throw MyException("Module failed to load\n");
      }
   }
   log.print("Module \'%s\' loaded @0x%p\n", moduleName, moduleHandle);

   newInstance  = (size_t (*)(...))dlsym(moduleHandle, createInstanceFunctioName);
   if (newInstance == 0) {
      char buff[1000];
      snprintf(buff, sizeof(buff), "Entry point \'%s\' not found in module \'%s\'\n", createInstanceFunctioName, moduleName);
      throw MyException(std::string(buff));
   }
   log.print("Entry point \'%s\' found @0x%p\n", createInstanceFunctioName, newInstance);
}

/**
 * Unload an instance of a class from a Library
 */
template <class T>
void PluginFactory<T>::unloadClass() {
   LOGGING;
   log.print("Unloading module @0x%p\n", moduleHandle);
   if (dlclose(moduleHandle) != 0) {
      log.print("Unloading module at @0x%p failed\n", moduleHandle);
      printSystemErrorMessage();
      // Ignore error as can't throw in destructor
   }
   log.print("Unloading module @0x%p done\n", moduleHandle);
   moduleHandle = 0;
   newInstance = 0;
}

#endif /* SRC_PLUGINFACTORY_WIN32_H_ */
