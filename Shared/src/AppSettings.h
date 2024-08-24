/** \file
    \brief Header file for AppSettings

    \verbatim
    Copyright (C) 2010  Peter O'Donoghue

    Based on material from OSBDM-JM60 Target Interface Software Package
    Copyright (C) 2009  Freescale

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
   |    May 2015 | Created
   +====================================================================
    \endverbatim
*/
#ifndef APPSETTINGS_HPP_
#define APPSETTINGS_HPP_

#include <memory>
#include <map>
#include "USBDM_API.h"
#include "UsbdmSystem.h"

/**
 * Used to save and load persistent application settings
 */
class AppSettings {

private:
   enum ValueType {intType, stringType};
   /**
    * Class to encapsulate the attribute & type
    */
   class Value {
      private:
         ValueType   type;
         int         intValue;
         std::string stringValue;

      public:
         /**
          * Create a integer attribute
          *
          * @param value - value to create
          */
         Value(int value) : stringValue("") {
            intValue    = value;
            type        = intType;
         }
         /**
          * Create a string attribute
          *
          * @param value - value to create
          */
         Value(const std::string &value) :
            intValue(0) {

            stringValue = value;
            type        = stringType;
         }
         /**
          * Create a string attribute
          *
          * @param value - value to create
          *
          */
         Value(const char *value) :
            intValue(0)
         {
            if (value == NULL)
               value = " ";
            stringValue = std::string(value);
            type        = stringType;
         }
         /**
          * Obtain the integer value
          */
         int getIntValue() const {
            return intValue;
         }
         /**
          * Obtain the string value
          */
         const std::string &getStringValue() const {
            return stringValue;
         }
         /**
          * Obtain the type of the attribute
          */
         ValueType getType() const {
            return type;
         }
   };

   std::map<std::string,Value *>  fMap;            //!< Container for key/attribute pairs
   std::string                    fFilePath;       //!< Path to load/save settings from
   std::string                    fDescription;    //!< Description of settings

   void loadFromFile(FILE *fp);
   void writeToFile(FILE *fp, const std::string &comment) const;
   FILE *openFile(std::string filePath, const char *attributes) const;

   static std::string getSettingsFilename(const std::string &rootFilename, TargetType_t targetType);

public:
   /**
    * Add a integer attribute
    *
    * @param key - key to use to save/retrieve the attribute
    * @param value - value to save
    */
   void addValue(std::string const &key, int value) {
      fMap[key] = new Value(value);
   }
   /**
    * Add a string attribute
    *
    * @param key   - key to use to save the attribute
    * @param value - value to save
    */
   void addValue(std::string const &key, std::string const &value) {
      fMap[key] = new Value(value);
   }
   /**
    * Add a string attribute
    *
    * @param key   - key to use to save the attribute
    * @param value - value to save
    */
   void addValue(std::string const &key, const char *value) {
      fMap[key] = new Value(value);
   }
   /**
    * Retrieve an integer attribute
    *
    * @param key      - key to use to retrieve the attribute
    * @param defValue - default value to use if not found
    */
   int getValue(std::string const &key, int defValue) const {
      std::map<std::string,Value *>::const_iterator it;
      it = fMap.find(key);
      if (it != fMap.end())
         return it->second->getIntValue();
      else
         return defValue;
   }
   /**
    * Retrieve an string attribute
    *
    * @param key      - key to use to retrieve the attribute
    * @param defValue - default value to use if not found
    */
   std::string getValue(std::string const &key, std::string const &defValue) const {
      std::map<std::string,Value *>::const_iterator it;
      it = fMap.find(key);
      if (it != fMap.end())
         return it->second->getStringValue();
      else
         return defValue;
   }
   /**
    *  Load settings from file
    */
   bool load();
   /**
    * Write settings to file in %APPDATA% system directory
    */
   bool save() const;
   /**
    * Print contents to log file
    */
   void printToLog() const;

   /**
    * @param basename     Base name for settings file in settings directory.
    * @param targetType   Target type used in creating file name
    * @param description  Description added to settings file
    */
   AppSettings(std::string basename, TargetType_t targetType, std::string description) :
      fFilePath(getSettingsFilename(basename, targetType)),
      fDescription(description)  {
      LOGGING_Q;
      log.print("filepath = %s\n", (const char *)getSettingsFilename(basename, targetType).c_str());
   }

   /**
    * Used to set the filepath use for persistence
    *
    * @param basename     Base name for settings file in settings directory.
    * @param targetType   Target type used in creating file name
    */
   void setFilepath(std::string basename, TargetType_t targetType) {
      fFilePath = getSettingsFilename(basename, targetType);
   }

   /**
    * @param filepath     Path for settings file. If not absolute then settings directory is used.
    * @param description  Description added to settings file
    */
   AppSettings(std::string filepath, std::string description) :
      fFilePath(filepath),
      fDescription(description)  {
      LOGGING_Q;
      log.print("filepath = %s\n", (const char *)filepath.c_str());
   }

   AppSettings(const AppSettings &other) :
      fMap(other.fMap),
      fFilePath(other.fFilePath),
      fDescription(other.fDescription)
   {
   }

   AppSettings & operator=(const AppSettings &other) {
      if (&other != this) {
         fMap           = other.fMap;
         fFilePath      = other.fFilePath;
         fDescription   = other.fDescription;
      }
      return *this;
   }
};

typedef std::shared_ptr<AppSettings> AppSettingsPtr;

#endif /* APPSETTINGS_HPP_ */
