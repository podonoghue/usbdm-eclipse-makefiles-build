/*
 * PluginFactory.h
 *
 *  Created on: 9 Apr 2015
 *      Author: podonoghue
 */

#ifndef SOURCE_PLUGINFACTORY_H_
#define SOURCE_PLUGINFACTORY_H_

#ifndef WIN32
#define USBDM_INSTALL_DIRECTORY "/usr"
#endif

#ifdef WIN32
#ifdef LOG
#define DLL_NAME(x) x "-debug.4.dll"
#else
#define DLL_NAME(x) x ".4.dll"
#endif
#else
#ifdef LOG
#define DLL_NAME(x) "lib" x "-debug.4.so"
#else
#define DLL_NAME(x) "lib" x ".4.so"
#endif
#endif

#ifdef _WIN32
#include "PluginFactory_WIN32.h"
#else
#include "PluginFactory_Linux.h"
#endif

#endif /* SOURCE_PLUGINFACTORY_H_ */
