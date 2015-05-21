/*
 * PluginHelper.h
 *
 *  Created on: 21 May 2015
 *      Author: podonoghue
 */

#ifndef SOURCE_PLUGINHELPER_H_
#define SOURCE_PLUGINHELPER_H_

#include "UsbdmSystem.h"

template<typename T>
size_t TcreatePluginInstance(void *pp) {
   LOGGING;
   if (pp != NULL) {
      log.print("Creating instance\n");
      new (pp) T();
   }
   else {
      log.print("Returning size %d\n", sizeof(T));
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
      log.print("Returning size %d\n", sizeof(T));
   }
   return sizeof(T);
}

#endif /* SOURCE_PLUGINHELPER_H_ */
