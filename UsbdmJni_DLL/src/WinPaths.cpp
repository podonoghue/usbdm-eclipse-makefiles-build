/*
 * WinPaths.cpp
 *
 *  Created on: 31/01/2013
 *      Author: PODonoghue
 */

#include <string>

#ifdef WIN32

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600      //!< Required for later system calls.
#endif
#include <windows.h>
#include <shlobj.h>

#ifndef KEY_WOW64_32KEY
#define KEY_WOW64_32KEY 0x0200
#endif

//! Name of directory to create in %APPDATA% for usbdm settings
#define CONFIGURATION_DIRECTORY_NAME "usbdm"
#define CONFIG_WITH_SLASHES "/" CONFIGURATION_DIRECTORY_NAME "/"

/*!
 * Get registry value as string
 *
 * @param hKey             - Registry Key from call to RegOpenKeyExA()
 * @param strValueName     - Value name
 * @param strValue         - Return value
 * @param strDefaultValue  - Default value returned if key not found
 *
 * @return error code
 */
static LONG GetStringRegKey(HKEY hKey, const std::string &strValueName, std::string &strValue, const std::string &strDefaultValue)
{
    strValue = strDefaultValue;
    char szBuffer[512];
    memset(szBuffer, 0, sizeof(szBuffer));
    DWORD dwBufferSize = sizeof(szBuffer) - 1;
    LONG nError = RegQueryValueExA(hKey, strValueName.c_str(), 0, NULL, (LPBYTE)szBuffer, &dwBufferSize);
    if (ERROR_SUCCESS == nError) {
        strValue = szBuffer;
    }
    return nError;
}

/* Obtain the path of the application directory
 *
 * @param path - Path found
 *
 * @return false if failed
 */
bool getUsbdmApplicationPath(std::string &path) {
   HKEY hKey;
   if ((RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\pgo\\USBDM", 0, KEY_READ|KEY_WOW64_32KEY, &hKey) != ERROR_SUCCESS) ||
       (GetStringRegKey(hKey, "InstallationDirectory", path, "") != ERROR_SUCCESS)) {
      return false;
   }
   return true;
}

/* Obtain the path of the resource directory
 *
 * @param path - Path found
 *
 * @return false if failed
 */
bool getUsbdmResourcePath(std::string &path) {
   return getUsbdmApplicationPath(path);
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
   static char configFilePath[MAX_PATH];

   memset(configFilePath, '\0', MAX_PATH);
   // Obtain local app folder
   if (SHGetFolderPathA(NULL,
         CSIDL_APPDATA|CSIDL_FLAG_CREATE,
         NULL,
         0,
         configFilePath) != S_OK) {
      return false;
   }
   // Append application directory name
   if (strlen(configFilePath)+sizeof(CONFIG_WITH_SLASHES) >= MAX_PATH) {
      return false;
   }
   strcat(configFilePath, CONFIG_WITH_SLASHES);

   // Check if folder exists or can be created
   if ((GetFileAttributesA(configFilePath) == INVALID_FILE_ATTRIBUTES) &&
         (SHCreateDirectoryExA( NULL, configFilePath, NULL ) != S_OK)) {
      return false;
   }
   path = std::string(configFilePath);
   return true;
}

#endif
