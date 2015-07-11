/*! \file
    \brief Implementation of UsbdmSystem for Windows

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

#include "UsbdmSystem.h"

//! Name of directory to create in %APPDATA% for usbdm settings
#define CONFIGURATION_DIRECTORY_NAME "usbdm"
#define CONFIG_WITH_SLASHES "/" CONFIGURATION_DIRECTORY_NAME "/"

/*
 * @param hKey
 */
//static LONG GetDWORDRegKey(HKEY hKey, const std::string &strValueName, DWORD &nValue, DWORD nDefaultValue)
//{
//    nValue = nDefaultValue;
//    DWORD dwBufferSize(sizeof(DWORD));
//    DWORD nResult(0);
//    LONG nError = ::RegQueryValueExA(hKey,
//        strValueName.c_str(),
//        0,
//        NULL,
//        reinterpret_cast<LPBYTE>(&nResult),
//        &dwBufferSize);
//    if (ERROR_SUCCESS == nError) {
//        nValue = nResult;
//    }
//    return nError;
//}

//static LONG GetBoolRegKey(HKEY hKey, const std::string &strValueName, bool &bValue, bool bDefaultValue)
//{
//    DWORD nDefValue((bDefaultValue) ? 1 : 0);
//    DWORD nResult(nDefValue);
//    LONG nError = GetDWORDRegKey(hKey, strValueName.c_str(), nResult, nDefValue);
//    if (ERROR_SUCCESS == nError) {
//        bValue = (nResult != 0) ? true : false;
//    }
//    return nError;
//}

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

/* Obtain the path of a file within the same directory as the module
 *
 * @param path to append to directory
 *
 * @return directory or NULL if failed
 */
std::string UsbdmSystem::getModulePath(const std::string &path) {
   static char buff[MAX_PATH];
   if (GetModuleFileNameA(NULL, buff, sizeof(buff)) == 0) {
      return std::string();
   }
   char *p = strrchr(buff, '\\');
   if (p != 0) {
      *(p+1) = '\0';
   }
   return std::string(buff).append(path);
}

/* Obtain the path of a file within the application directory
 *
 * @param path to append to directory
 *
 * @return directory or NULL if failed
 */
std::string USBDM_SYSTEM_DECLSPEC UsbdmSystem::getApplicationPath(const std::string &path) {
   LOGGING_Q;

   // Try relative to module
   std::string fullPath = getModulePath(path);
   if (!fileExists(fullPath)) {
      std::string applicationDirectory("");
      HKEY hKey;
      if ((RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\pgo\\USBDM", 0, KEY_READ|KEY_WOW64_32KEY, &hKey) != ERROR_SUCCESS) ||
            (GetStringRegKey(hKey, "InstallationDirectory", applicationDirectory, "") != ERROR_SUCCESS)) {
         log.print("Failed to get USBDM path from registry\n");
      }
      fullPath = applicationDirectory.append(path);
   }
   return fullPath;
}

/* Obtain the path of a file within the resource directory
 *
 * @param path to append to directory
 *
 * @return directory or NULL if failed
 */
std::string USBDM_SYSTEM_DECLSPEC UsbdmSystem::getResourcePath(const std::string &path) {
   return getApplicationPath(path);
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
   static char configFilePath[MAX_PATH];

   memset(configFilePath, '\0', MAX_PATH);
   // Obtain local app folder
   if (SHGetFolderPathA(NULL,
         CSIDL_APPDATA|CSIDL_FLAG_CREATE,
         NULL,
         0,
         configFilePath) != S_OK) {
      log.print("Failed to get path for \'%s\'", (const char *)path.c_str());
      return std::string();
   }
   // Append application directory name
   if (strlen(configFilePath)+sizeof(CONFIG_WITH_SLASHES) >= MAX_PATH) {
      log.print("Path too long for \'%s\'", (const char *)path.c_str());
      return std::string();
   }
   strcat(configFilePath, CONFIG_WITH_SLASHES);

   // Check if folder exists or can be created
   if ((GetFileAttributesA(configFilePath) == INVALID_FILE_ATTRIBUTES) &&
         (SHCreateDirectoryExA( NULL, configFilePath, NULL ) != S_OK)) {
      log.print("Folder invalid/failed creation \'%s\'", (const char *)path.c_str());
      return std::string();
   }
   return std::string(configFilePath).append(path);
}


//void tryit(void) {
//   HKEY hKey;
//   LONG lRes = RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\pgo", 0, KEY_READ|KEY_WOW64_32KEY, &hKey);
//   bool bExistsAndSuccess (lRes == ERROR_SUCCESS);
//   bool bDoesNotExistsSpecifically (lRes == ERROR_FILE_NOT_FOUND);
//   std::string strValueOfBinDir;
//   std::string strKeyDefaultValue;
//   GetStringRegKey(hKey, "BinDir", strValueOfBinDir, "bad");
//   GetStringRegKey(hKey, "", strKeyDefaultValue, "bad");
//}


#endif
