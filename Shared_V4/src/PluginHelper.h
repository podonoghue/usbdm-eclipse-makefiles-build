/*
 * PluginHelper.h
 *
 *  Created on: 21 May 2015
 *      Author: podonoghue
 */

#ifndef SOURCE_PLUGINHELPER_H_
#define SOURCE_PLUGINHELPER_H_

#include "UsbdmSystem.h"

#if !defined(CPP_DLL_LOCAL)
   #ifdef _WIN32
      //! Functions exported from a library
      #define CPP_DLL_EXPORT __declspec(dllexport)
      //! Functions imported from a library
      #define CPP_DLL_IMPORT __declspec(dllimport)
      //! Functions local to a library
      #define CPP_DLL_LOCAL
   #else
      //! Functions exported from a library
      #define CPP_DLL_EXPORT __attribute__ ((visibility ("default")))
      //! Functions imported from a library
      #define CPP_DLL_IMPORT __attribute__ ((visibility ("default")))
      //! Functions local to a library
      #define CPP_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
   #endif
#endif

template<typename T>
size_t TcreatePluginInstance(void *pp) {
   LOGGING;
   if (pp != NULL) {
      log.print("Creating instance\n");
      new (pp) T();
   }
   else {
      log.print("Returning size %ld\n", (long)sizeof(T));
   }
   return sizeof(T);
}

template<typename T, typename A>
size_t TcreatePluginInstance(void *pp, A arg) {
   LOGGING;
   if (pp != NULL) {
      log.print("Creating instance\n");
      new (pp) T(arg);
   }
   else {
      log.print("Returning size %ld\n", (long)sizeof(T));
   }
   return sizeof(T);
}

#endif /* SOURCE_PLUGINHELPER_H_ */
