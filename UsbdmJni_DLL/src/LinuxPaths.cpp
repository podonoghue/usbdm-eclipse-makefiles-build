/*
 * LinuxPaths.cpp
 *
 *  Created on: 04/02/2013
 *      Author: pgo
 */

#include <stdlib.h>
#ifndef WIN32

#include "Common.h"
#include "UsbdmPaths.h"

/*!
 * Get environment variable as string
 *
 * @param key              - Registry Environment variable name
 *
 * @return Return value
 */
static std::string getEnvVar( std::string const & key )
{
    char * val = getenv( key.c_str() );
    return val == NULL ? std::string("") : std::string(val);
}

/* Obtain the path of the application directory
 *
 * @param path - Path found
 *
 * @return false if failed
 */
bool getUsbdmApplicationPath(std::string &path) {

   path = USBDM_INSTALL_DIRECTORY "/bin/";
   return true;
}

/* Obtain the path of the resource directory
 *
 * @param path - Path found
 *
 * @return false if failed
 */
bool getUsbdmResourcePath(std::string &path) {

   path = USBDM_INSTALL_DIRECTORY "/share/usbdm/";
   return true;
}

/* Obtain the path of the configuration directory
 *
 * @param path - Path found
 *
 * @return false if failed
 *
 * @note The configuration directory will be created if it doesn't already exist.
 */
bool getUsbdmDataPath(std::string &path) {

   std::string home = getEnvVar("HOME");
   path = home + "/.usbdm/";
   return true;
}

#endif
