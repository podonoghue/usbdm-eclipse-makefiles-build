/*
 * PluginFactory.h
 *
 *  Created on: 9 Apr 2015
 *      Author: podonoghue
 */

#ifndef SOURCE_PLUGINFACTORY_H_
#define SOURCE_PLUGINFACTORY_H_

#ifdef _WIN32
#include "PluginFactory_WIN32.h"
#else
#error "No support for this OS"
#endif

#endif /* SOURCE_PLUGINFACTORY_H_ */
