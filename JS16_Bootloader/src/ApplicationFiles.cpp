/*! \file
    \brief Provides Access to Application files

    ApplicationFiles.cpp

    \verbatim
    USBDM
    Copyright (C) 2009  Peter O'Donoghue

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
    \endverbatim

    \verbatim
   Change History
   -================================================================================
   | 16 Nov 2009 | Changes to allow wxWidgets dependencies to be localised    - pgo
   +-------------+------------------------------------------------------------------
   | 16 Nov 2009 | Created                                                    - pgo
   +================================================================================
   \endverbatim
 */
#include <stdio.h>
#include <sys/stat.h>
#include "ICP.h"

#ifdef useWxWidgets
#include <wx/wx.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#ifdef _WIN32
#include <wx/msw/registry.h>
#endif
#else
#include "wxPlugin.h"
#endif
#include "UsbdmSystem.h"
#include "Common.h"
#include "ApplicationFiles.h"

using namespace std;

#ifdef _WIN32
string getInstallationDir(void) {
#ifdef useWxWidgets
   wxString path;
   wxRegKey key(wxRegKey::HKLM, "Software\\pgo\\USBDM");
   if (key.Exists() && key.QueryValue("InstallationDirectory", path))
      return string(path.c_str());
   return string();
#else
   char buff[1000];
   getInstallationDir(buff, sizeof(buff));
   return string(buff);
#endif
}
#endif

string getDataDir(void) {
#ifdef useWxWidgets
   return string(wxStandardPaths::Get().GetDataDir().ToAscii());
#else
   char buff[1000];
   getDataDir(buff, sizeof(buff));
   return string(buff);
#endif
}

string getUserDataDir(void) {
#ifdef useWxWidgets
   return string(wxStandardPaths::Get().GetUserDataDir().ToAscii());
#else
   char buff[1000];
   getUserDataDir(buff, sizeof(buff));
   return string(buff);
#endif
}

#ifdef useWxWidgets
char getPathSeparator(void) {
   return (char)(wxFileName::GetPathSeparator());
}
#endif

#ifdef _WIN32
bool fileExists(string filePath) {
   DWORD attrib = GetFileAttributesA(filePath.c_str());
   UsbdmSystem::Log::print("fileExists(%s) => attr=%lX\n", filePath.c_str(), attrib);
   return  (attrib != INVALID_FILE_ATTRIBUTES) &&
          ((attrib & FILE_ATTRIBUTE_DIRECTORY) == 0);
}

bool dirExists(string filePath) {
   DWORD attrib = GetFileAttributesA(filePath.c_str());
   return  (attrib != INVALID_FILE_ATTRIBUTES) &&
          ((attrib & FILE_ATTRIBUTE_DIRECTORY) != 0);
}
#else
bool fileExists(string strFilename) {
   struct stat stFileInfo;
   int intStat;

   // Attempt to get the file attributes
   intStat = stat(strFilename.c_str(),&stFileInfo);
   return ((intStat == 0) && S_ISREG(stFileInfo.st_mode));
}

bool dirExists(string filePath) {
   struct stat stFileInfo;
   int intStat;

   // Attempt to get the file attributes
   intStat = stat(filePath.c_str(),&stFileInfo);
   return ((intStat == 0) && S_ISDIR(stFileInfo.st_mode));
}
#endif

//! Opens configuration file
//!
//! @param filename   - Name of file (without path)
//! @param attributes - Attributes to use when opening the file.
//!                     This should be one of "r", "w", "rt" or "wt"
//!
//! @return file handle or NULL on error
//!
//! @note Attempts to open readonly files from two locations:
//! - Application directory (where the .exe is)
//! - Application data directory (e.g. %APPDATA%/usbdm, $HOME/.usbdm)
//! Files opened for writing only use the last directory.
//!
FILE *openApplicationFile(const string &filename, const string &attributes) {

   string configFilePath;
   FILE *configFile = NULL;

   // Try the Executable directory for readonly files
   if (attributes[0] == 'r') {
      configFilePath = getDataDir();
      if (!configFilePath.empty()) {
         // Append filename
         configFilePath += getPathSeparator() + filename;
         // Open the file
         configFile = fopen(configFilePath.c_str(), attributes.c_str());
      }
   }
#ifdef _WIN32
   // Try the Path indicated by registry key if necessary
   if ((attributes[0] == 'r') && (configFile == NULL )) {
      configFilePath = getInstallationDir();
      // fprintf(stderr, "openApplicationFile() - \"%s\"\n", (const char *)configFilePath.ToAscii());
      if (!configFilePath.empty()) {
         // Append filename
         configFilePath += filename;
         // Open the file
         configFile = fopen(configFilePath.c_str(), attributes.c_str());
      }
   }
#endif
   // Try the Application Data directory if necessary
   if (configFile == NULL ) {
      configFilePath = getUserDataDir();
      // fprintf(stderr, "openApplicationFile() - \"%s\"\n", (const char *)configFilePath.ToAscii());
      if (!configFilePath.empty()) {
         if (!dirExists(configFilePath)) {
            // Doesn't exist - create it
#ifdef _WIN32
            mkdir(configFilePath.c_str());
#else
            mkdir(configFilePath.c_str(), S_IRWXU|S_IRWXG|S_IRWXO);
#endif			
         }
         // Append filename
         configFilePath += getPathSeparator() + filename;

         // Open the file
         configFile = fopen(configFilePath.c_str(), attributes.c_str());
      }
   }
   if (configFile != NULL) {
      UsbdmSystem::Log::print("openApplicationFile() - Opened \'%s\'\n", configFilePath.c_str());
   }
   return configFile;
}

//! Check for existence of a configuration file
//!
//! @param filename   - Name of file (without path)
//! @param attributes - Attributes to use when opening the file.
//!                     This should be one of "r", "w", "rt" or "wt"
//!
//! @return ICP_RC_OK if file exists
//!
//! @note Attempts to locate the file in  two locations:
//! - Application data directory (e.g. %APPDATA%/usbdm, $HOME/.usbdm)
//! - Application directory (where the .exe is)
//!
int checkExistsApplicationFile(const string &filename, const string &attributes) {

   string configFilePath;

   // Try the Executable directory for readonly files
   if (attributes[0] == 'r') {
      configFilePath = getDataDir() + getPathSeparator() + filename;
      if (fileExists(configFilePath))
         return ICP_RC_OK;
   }
#ifdef _WIN32
   // Try the Path indicated by registry key if necessary
   if (attributes[0] == 'r') {
      configFilePath = getInstallationDir();
      // fprintf(stderr, "openApplicationFile() - \"%s\"\n", (const char *)configFilePath.ToAscii());
      if (!configFilePath.empty()) {
         // Append filename
         configFilePath += filename;
         if (fileExists(configFilePath))
            return ICP_RC_OK;
      }
   }
#endif
   // Try the Application Data directory
   configFilePath = getUserDataDir() + getPathSeparator() + filename;;
   if (fileExists(configFilePath))
      return ICP_RC_OK;

   return ICP_RC_FILE_NOT_FOUND;
}

//! Returns the path to a configuration file
//!
//! @param filename   - Name of file (without path)
//! @param attributes - Attributes to use when opening the file.
//!                     This should be one of "r", "w", "rt" or "wt"
//!
//! @return ICP_RC_OK if file exists
//!
//! @note Attempts to locate the file in  two locations:
//! - Application data directory (e.g. %APPDATA%/usbdm, $HOME/.usbdm)
//! - Application directory (where the .exe is)
//!
string getApplicationFilePath(const string &filename, const string &attributes) {

   string configFilePath;

   // Try the Executable directory for readonly files
   if (attributes[0] == 'r') {
      configFilePath = getDataDir() + getPathSeparator() + filename;
      UsbdmSystem::Log::print("getApplicationFilePath() - trying %s\n", configFilePath.c_str());
      if (fileExists(configFilePath))
         return configFilePath;
   }
#ifdef _WIN32
   // Try the Path indicated by registry key if necessary
   if (attributes[0] == 'r') {
      configFilePath = getInstallationDir()+ filename;
      UsbdmSystem::Log::print("getApplicationFilePath() - trying %s\n", configFilePath.c_str());
      if (fileExists(configFilePath))
         return configFilePath;
   }
#endif
   // Try the Application Data directory
   configFilePath = getUserDataDir() + getPathSeparator() + filename;;
   UsbdmSystem::Log::print("getApplicationFilePath() - trying %s\n", configFilePath.c_str());
   if (fileExists(configFilePath))
      return configFilePath;

   return string();
}
