/*
 * ModuleInfo.h
 *
 *  Created on: 11 May 2022
 *      Author: peter
 */

#ifndef SOURCE_MODULEINFO_H_
#define SOURCE_MODULEINFO_H_

#ifndef linux
#include <minwindef.h>
using MODULE_HANDLE = HINSTANCE;
#define STD__LINKAGE  __attribute__((__stdcall__))
#else
using MODULE_HANDLE = void *;
#define STD__LINKAGE
#endif

class ModuleInfo {

public:
   unsigned       instanceCount;
   MODULE_HANDLE  moduleHandle;

   constexpr ModuleInfo() : instanceCount(0), moduleHandle((MODULE_HANDLE)0) {}
};
#endif /* SOURCE_MODULEINFO_H_ */
