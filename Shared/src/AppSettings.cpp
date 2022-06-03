/*! \file
    \brief Provides persistent application settings

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
   -============================================================================
   |             |                                                         - pgo
   +============================================================================
   \endverbatim
*/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>

#include "Common.h"
#include "UsbdmSystem.h"
#include "AppSettings.h"

using namespace std;

// Quick hack until std::filesystem::path is more readily available??
static bool isRelativePath(string path) {

   bool isRelative = false;
//   std::filesystem::path path(filePath);
//   if (path.is_relative()) {

#ifdef __linux__
   isRelative = path.at(0) != '/';
#else
   isRelative = PathIsRelativeA(path.c_str());
#endif
   return isRelative;
}

/*!
 *  Get settings filename
 *
 *  @param rootFilename - Start of filename to use,
 *                        may be empty in which case a default will be used.
 *                        A suffix is added to identify the target type.
 *  @param targetType  - Target type used to select suffix
 *
 *  @return string representing the filename
 */
string AppSettings::getSettingsFilename(const string &rootFilename, TargetType_t targetType) {

   string filename(rootFilename);
   if (filename.empty()) {
#ifdef FLASH_PROGRAMMER
      filename = "FlashProgrammer_";
#else
      filename = "TargetSettings_";
#endif
   }
   switch (targetType) {
      case T_S12Z:         filename += "S12Z.cfg";      break;
      case T_HC12:         filename += "HC12.cfg";      break;
      case T_HCS08:        filename += "HCS08.cfg";     break;
      case T_RS08:         filename += "RS08.cfg";      break;
      case T_CFV1:         filename += "CFV1.cfg";      break;
      case T_CFVx:         filename += "CFVx.cfg";      break;
      case T_JTAG:         filename += "JTAG.cfg";      break;
      case T_MC56F80xx :   filename += "MC56F80xx.cfg"; break;
      case T_ARM_JTAG:     filename += "ARM_JTAg.cfg";  break;
      case T_ARM_SWD:      filename += "ARM_SWD.cfg";   break;
      case T_ARM:          filename += "ARM.cfg";       break;
      case T_NONE:         filename += ".cfg";          break;
      default:             filename += "generic.cfg";   break;
   }
   return filename;
}

/*!
 *  Write settings to file
 *
 *  @param fp      - open file to write to
 *  @param comment - string to add as comment line in file.
 */
void AppSettings::writeToFile(FILE *fp, const string &comment) const {
   fprintf(fp, "# %s\n\n", comment.c_str()); fflush(fp);

   map<string,Value*>::const_iterator it;
   for (it=fMap.begin(); it != fMap.end(); it++ ) {
      switch (it->second->getType()) {
         case intType:
            fprintf(fp, "%s %d,%d\n", it->first.c_str(), it->second->getType(), it->second->getIntValue());
            fflush(fp);
            break;
         case stringType:
            fprintf(fp, "%s %d,%s\n", it->first.c_str(), it->second->getType(), it->second->getStringValue().c_str());
            fflush(fp);
            break;
         default:
            fflush(fp);
            break;
      }
   }
}

/*!
 *  Open file from Application configuration directory
 */
FILE *AppSettings::openFile(string filePath, const char *attributes) const {
   LOGGING_Q;

   std::string resolvedFilePath;
   if (isRelativePath(filePath)) {
      // Assume configuration directory
      resolvedFilePath = UsbdmSystem::getConfigurationPath(filePath);
   }
   else {
      // Use as-is
      resolvedFilePath = filePath;
   }
   if (resolvedFilePath.length() == 0) {
      return NULL;
   }
   log.print("- Path = %s\n", (const char *)resolvedFilePath.c_str());
   return fopen(resolvedFilePath.c_str(), attributes);
}

/*!
 * Write settings to file in %APPDATA% system directory
 */
bool AppSettings::save() const {
   LOGGING;
   FILE *fp = openFile(fFilePath, "wt");
   if (fp== NULL) {
      log.error("- Failed to open Settings File for writing: File = \'%s\'\n", fFilePath.c_str());
      return false;
   }
   writeToFile(fp, fDescription.c_str());
   fclose(fp);
   return true;
}

/*!
 *  Write settings to log file for debugging
 */
void AppSettings::printToLog() const {
   UsbdmSystem::Log::print("=============================================================\n");
   UsbdmSystem::Log::print("filename = \'%s\'\n", fFilePath.c_str());
   map<string,Value*>::const_iterator it;
   for (it=fMap.begin(); it != fMap.end(); it++) {
      switch (it->second->getType()) {
         case intType:
            UsbdmSystem::Log::print("%s => %d, %d\n", it->first.c_str(), it->second->getType(), it->second->getIntValue());
            break;
         case stringType:
            UsbdmSystem::Log::print("%s => %d, '%s'\n", it->first.c_str(), it->second->getType(), it->second->getStringValue().c_str());
            break;
         default:
            UsbdmSystem::Log::print("Unknown attribute type\n");
            break;
      }
   }
   UsbdmSystem::Log::print("=============================================================\n");
}

/*!
 *  Load settings from file
 *
 *  @param fp  - open file to read from
 */
void AppSettings::loadFromFile(FILE *fp) {
   LOGGING_Q;
   char lineBuff[200];
   char *optionName;
   char *optionString;
   char *cptr;
   long int optionInt;
   long int optionType;
   char *cp;
   int lineNo = 0;

   while (fgets(lineBuff, sizeof(lineBuff), fp) != NULL) {
      lineNo++;
//         log.print("original: %s", lineBuff);
      // Remove comments
      cp = strchr(lineBuff, '#');
      if (cp != NULL)
         *cp = '\0';
      // Remove eol
      cp = strchr(lineBuff, '\n');
      if (cp != NULL)
         *cp = '\0';
      cp = strchr(lineBuff, '\r');
      if (cp != NULL)
         *cp = '\0';
      // Discard empty lines (white space only)
      cp = lineBuff;
      while (*cp == ' ')
         cp++;
      if (*cp == '\0')
         continue;

//      log.print("comment stripped: \'%s\'\n", lineBuff);
      optionName = strtok(lineBuff, " =");
      cptr       = strtok(NULL, ", ");
      optionType = atoi(cptr);
      optionString = strtok(NULL, "");
      switch (optionType) {
         case intType:
            optionInt = atoi(optionString);
            addValue(string(optionName), optionInt);
            break;
         case stringType:
            addValue(string(optionName), optionString);
            break;
      }
   }
}

/*!
 *  Load settings from file
 */
bool AppSettings::load() {
   LOGGING_Q;
   FILE *fp = openFile(fFilePath, "rt");
   if (fp== NULL) {
      log.error("AppSettings::loadFromAppDirFile() - Failed to open Settings File for reading: File = \'%s\'\n",
            fFilePath.c_str());
      return false;
   }
   loadFromFile(fp);
   fclose(fp);

//   printToLog();
   return true;
}
