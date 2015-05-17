/*
 * LinuxPaths.cpp
 *
 *  Created on: 04/02/2013
 *      Author: pgo
 */

#ifndef WIN32
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

std::string UsbdmSystem::getModulePath(const std::string &path) {
   return path;
}

bool UsbdmSystem::fileExists(const std::string &path) {
   struct stat buffer;
   return (stat(path.c_str(), &buffer) == 0);
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

/* Obtain the path of the configuration directory
 *
 * @param path to append to directory
 *
 * @return directory or NULL if failed
 *
 * @note The configuration directory will be created if it doesn't already exist.
 */
std::string USBDM_SYSTEM_DECLSPEC UsbdmSystem::getDataPath(const std::string &path) {
   LOGGING_Q;

   std::string res = getEnvVar("HOME").append("/.usbdm/");
   return res.append(path);
}

#endif
