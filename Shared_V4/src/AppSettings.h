/*
 * AppSettings.h
 *
 *  Created on: 01/03/2010
 *      Author: podonoghue
 */
#ifndef APPSETTINGS_HPP_
#define APPSETTINGS_HPP_

#include <tr1/memory>
#include <map>
#include "USBDM_API.h"
#include "UsbdmSystem.h"

class AppSettings {

private:
   enum ValueType {intType, stringType};
   //! Class to encapsulate the attribute & type
   class Value {
      private:
         ValueType   type;
         int         intValue;
         std::string stringValue;
      public:
         //! Create a integer attribute
         //!
         //! @param value - value to create
         Value(int value) {
            intValue = value;
            type     = intType;
         }
         //! Create a string attribute
         //!
         //! @param value - value to create
         Value(const std::string &value) :
            intValue(0)
         {
            stringValue = value;
            type        = stringType;
         }
         //! Create a string attribute
         //!
         //! @param value - value to create
         Value(const char *value) :
            intValue(0)
         {
            if (value == NULL)
               value = " ";
            stringValue = std::string(value);
            type        = stringType;
         }
         //! Obtain the integer value
         //!
         int getIntValue() const {
            return intValue;
         }
         //! Obtain the string value
         //!
         const std::string &getStringValue() const {
            return stringValue;
         }
         //! Obtain the type of the attribute
         //!
         ValueType getType() const {
            return type;
         }
   };

   std::map<std::string,Value *>  mymap;          //!< Container for key/attribute pairs
   std::string                    fileName;       //!< Path to load/save settings from
   std::string                    description;    //!< Description of settings

   void loadFromFile(FILE *fp);
   void writeToFile(FILE *fp, const std::string &comment) const;

   static std::string getSettingsFilename(const std::string &rootFilename, TargetType_t targetType);

public:
   //! Add a integer attribute
   //!
   //! @param key - key to use to save/retrieve the attribute
   //! @param value - value to save
   void addValue(std::string const &key, int value) {
      mymap[key] = new Value(value);
   }
   //! Add a string attribute
   //!
   //! @param key   - key to use to save the attribute
   //! @param value - value to save
   void addValue(std::string const &key, std::string const &value) {
      mymap[key] = new Value(value);
   }
   //! Add a string attribute
   //!
   //! @param key   - key to use to save the attribute
   //! @param value - value to save
   void addValue(std::string const &key, const char *value) {
      mymap[key] = new Value(value);
   }
   //! Retrieve an integer attribute
   //!
   //! @param key      - key to use to retrieve the attribute
   //! @param defValue - default value to use if not found
   int getValue(std::string const &key, int defValue) const {
      std::map<std::string,Value *>::const_iterator it;
      it = mymap.find(key);
      if (it != mymap.end())
         return it->second->getIntValue();
      else
         return defValue;
   }
   //! Retrieve an string attribute
   //!
   //! @param key      - key to use to retrieve the attribute
   //! @param defValue - default value to use if not found
   std::string getValue(std::string const &key, std::string const &defValue) const {
      std::map<std::string,Value *>::const_iterator it;
      it = mymap.find(key);
      if (it != mymap.end())
         return it->second->getStringValue();
      else
         return defValue;
   }

   bool load();
   bool save() const;

   void printToLog() const;

   AppSettings(std::string baseFilename, TargetType_t targetType, std::string description) :
      fileName(getSettingsFilename(baseFilename, targetType)),
      description(description)  {
      LOGGING_Q;
      log.print("baseFilename = %s\n", (const char *)getSettingsFilename(baseFilename, targetType).c_str());
   }

   AppSettings(std::string filename, std::string description) :
      fileName(filename),
      description(description)  {
      LOGGING_Q;
      log.print("baseFilename = %s\n", (const char *)filename.c_str());
   }
};

typedef std::tr1::shared_ptr<AppSettings> AppSettingsPtr;

#endif /* APPSETTINGS_HPP_ */
