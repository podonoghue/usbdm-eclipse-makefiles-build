/*! \file
    \brief Base PluginFactory

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
#define DLL_NAME(x) "lib" x "-debug.so.4"
#else
#define DLL_NAME(x) "lib" x ".so.4"
#endif
#endif

#ifdef _WIN32
#include "PluginFactory_WIN32.h"
#else
#include "PluginFactory_Linux.h"
#endif

#endif /* SOURCE_PLUGINFACTORY_H_ */
