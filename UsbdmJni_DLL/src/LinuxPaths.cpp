/*
 * LinuxPaths.cpp
 *
 *  Created on: 04/02/2013
 *      Author: pgo
 */

#include <stdlib.h>
#include "Common.h"
#include "UsbdmPaths.h"

static std::string getEnvVar( std::string const & key )
{
    char * val = getenv( key.c_str() );
    return val == NULL ? std::string("") : std::string(val);
}

//! Obtain the path of the resource directory (read only)
//!
//! @param applicationDirectory - String to return path
//!
//! @return error code -n true => success \n
//!                    - false => failure
//!
bool getUsbdmResourcePath(std::string &path) {

   path = USBDM_INSTALL_DIRECTORY "/share/usbdm/";
   return true;
}

//! Obtain the path of the application directory (read only)
//!
//! @param applicationDirectory - String to return path
//!
//! @return error code - true => success \n
//!                    - false => failure
//!
bool getUsbdmApplicationPath(std::string &path) {

   path = USBDM_INSTALL_DIRECTORY "/bin/";
   return true;
}

//! Obtain the path of the configuration directory
//!
//! @param applicationDirectory - String to return path
//!
//! @return error code - true => success \n
//!                    - false => failure
//!
//! @note The configuration directory will be created if it doesn't aleady exist.
//!
bool getUsbdmDataPath(std::string &path) {

   std::string home = getEnvVar("HOME");
   path = home + "/.usbdm/";
   return true;
}



