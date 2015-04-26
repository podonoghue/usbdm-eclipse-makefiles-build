/*
 * LinuxPaths.cpp
 *
 *  Created on: 04/02/2013
 *      Author: pgo
 */

#include <stdlib.h>

//#include "Common.h"
#include "UsbdmSystem.h"

#define USBDM_INSTALL_DIRECTORY "/usr"

//! Functions local to a library
#define DLL_LOCAL  __attribute__ ((visibility ("hidden")))

std::string getEnvVar(std::string const & key)
{
    char * val = getenv( key.c_str() );
    return val == NULL ? std::string("") : std::string(val);
}

/* Obtain the path of the resource directory (read only)
 *
 *
 * @param path to append to directory
 *
 * @return directory or NULL if failed
 */
std::string UsbdmSystem::getResourcePath(std::string &path) {

   std::string res(USBDM_INSTALL_DIRECTORY "/share/usbdm/");
   return res.append(path);
}

/* Obtain the path of the application directory (read only)
 *
 * @param path to append to directory
 *
 * @return directory or NULL if failed
 */
std::string UsbdmSystem::getApplicationPath(std::string &path) {

   std::string res(USBDM_INSTALL_DIRECTORY "/bin/");
   return res.append(path);
}

/* Obtain the path of the configuration directory
 *
 * @param path to append to directory
 *
 * @return directory or NULL if failed
 * @note The configuration directory will be created if it doesn't aleady exist.
 */
std::string UsbdmSystem::getDataPath(std::string &path) {

   std::string res = getEnvVar("HOME").append("/.usbdm/");
   return res.append(path);
}



