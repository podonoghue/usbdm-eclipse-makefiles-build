/*! \file
    \brief Header file for UsbdmSystemLinux.cpp

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
   |    May 2015 | Added automatic creation of $HOME/.usbdm directory
   |    May 2015 | Created
   +====================================================================
    \endverbatim
*/


#ifndef WIN32
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "UsbdmSystem.h"
#include "Common.h"

//! Functions local to a library
#define DLL_LOCAL  __attribute__ ((visibility ("hidden")))

std::string getEnvVar(const std::string & key)
{
    char * val = getenv( key.c_str() );
    return (val == 0) ? std::string("") : std::string(val);
}

/* Obtain the path of a file within the same directory as the module
 * NOTE IMPLEMENTED ON LINUX
 * @param path to append to directory
 *
 * @return directory or NULL if failed
 */
std::string UsbdmSystem::getModulePath(const std::string &path) {
   return path;
}

/* Obtain the path of a file within the application directory
 *
 * @param path to append to directory
 *
 * @return directory or NULL if failed
 */
std::string USBDM_SYSTEM_DECLSPEC UsbdmSystem::getApplicationPath(const std::string &path) {
   LOGGING_Q;

   std::string res(USBDM_INSTALL_DIRECTORY "/bin/");
   return res.append(path);
}

/* Obtain the path of a file within the resource directory
 *
 * @param path to append to directory
 *
 * @return directory or NULL if failed
 */
std::string USBDM_SYSTEM_DECLSPEC UsbdmSystem::getResourcePath(const std::string &path) {

   std::string res(USBDM_INSTALL_DIRECTORY "/share/usbdm/");
   return res.append(path);
}

/* Obtain the path of a file within the configuration directory
 * This is a per-user read/write directory for configurations
 *
 * @param path to append to directory
 *
 * @return directory or NULL if failed
 *
 * @note The configuration directory will be created if it doesn't already exist.
 */
std::string USBDM_SYSTEM_DECLSPEC UsbdmSystem::getConfigurationPath(const std::string &path) {
   LOGGING_Q;

   std::string res = getEnvVar("HOME").append("/.usbdm/");
   if (!fileExists(res)) {
      mkdir(res.c_str(), S_IRWXU);
   }
   return res.append(path);
}

#endif
