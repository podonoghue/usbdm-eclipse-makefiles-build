/*
 * WinPaths.cpp
 *
 *  Created on: 31/01/2013
 *      Author: PODonoghue
 */

#include <string>

#ifdef WIN32
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501      //!< Required for later system calls.
#endif
#include <windows.h>
#include <shlobj.h>

#ifndef KEY_WOW64_32KEY
#define KEY_WOW64_32KEY 0x0200
#endif

//! Name of directory to create in %APPDATA% for usbdm settings
#define CONFIGURATION_DIRECTORY_NAME "usbdm"
#define CONFIG_WITH_SLASHES "/" CONFIGURATION_DIRECTORY_NAME "/"

LONG GetDWORDRegKey(HKEY hKey, const std::string &strValueName, DWORD &nValue, DWORD nDefaultValue)
{
    nValue = nDefaultValue;
    DWORD dwBufferSize(sizeof(DWORD));
    DWORD nResult(0);
    LONG nError = ::RegQueryValueExA(hKey,
        strValueName.c_str(),
        0,
        NULL,
        reinterpret_cast<LPBYTE>(&nResult),
        &dwBufferSize);
    if (ERROR_SUCCESS == nError) {
        nValue = nResult;
    }
    return nError;
}

LONG GetBoolRegKey(HKEY hKey, const std::string &strValueName, bool &bValue, bool bDefaultValue)
{
    DWORD nDefValue((bDefaultValue) ? 1 : 0);
    DWORD nResult(nDefValue);
    LONG nError = GetDWORDRegKey(hKey, strValueName.c_str(), nResult, nDefValue);
    if (ERROR_SUCCESS == nError) {
        bValue = (nResult != 0) ? true : false;
    }
    return nError;
}


LONG GetStringRegKey(HKEY hKey, const std::string &strValueName, std::string &strValue, const std::string &strDefaultValue)
{
    strValue = strDefaultValue;
    char szBuffer[512];
    DWORD dwBufferSize = sizeof(szBuffer);
    ULONG nError;
    nError = RegQueryValueExA(hKey, strValueName.c_str(), 0, NULL, (LPBYTE)szBuffer, &dwBufferSize);
    if (ERROR_SUCCESS == nError) {
        strValue = szBuffer;
    }
    return nError;
}

//! Obtain the path of the application directory (read only)
//!
//! @param applicationDirectory - String to return path
//!
//! @return error code - true => success \n
//!                    - false => failure
//!
bool getUsbdmApplicationPath(std::string &applicationDirectory) {
   HKEY hKey;
   LONG lRes = RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\pgo\\USBDM", 0, KEY_READ|KEY_WOW64_32KEY, &hKey);
   if (lRes != ERROR_SUCCESS) {
      return false;
   }
   lRes = GetStringRegKey(hKey, "InstallationDirectory", applicationDirectory, "bad");
   if (lRes != ERROR_SUCCESS) {
      return false;
   }
   return true;
}

//! Obtain the path of the resource directory (read only)
//!
//! @param applicationDirectory - String to return path
//!
//! @return error code -n true => success \n
//!                    - false => failure
//!
bool getUsbdmResourcePath(std::string &path) {

   return getUsbdmApplicationPath(path);
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
bool getUsbdmDataPath(std::string &applicationDirectory) {
   static char configFilePath[MAX_PATH];

   memset(configFilePath, '\0', MAX_PATH);
   // Obtain local app folder
   if (SHGetFolderPath(NULL,
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
   if ((GetFileAttributes(configFilePath) == INVALID_FILE_ATTRIBUTES) &&
         (SHCreateDirectoryEx( NULL, configFilePath, NULL ) != S_OK)) {
      return false;
   }
   applicationDirectory = configFilePath;

   return true;
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
