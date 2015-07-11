/*! \file
    \brief Plugin Helper Template functions for plug-in implementation

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
