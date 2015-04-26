/*! \file
    \brief Header file for USBDM_AUX.cpp

*/
#ifndef _BDMINFORMATION_H_
#define _BDMINFORMATION_H_

#include <string>
#include <vector>
#include "USBDM_API.h"

//! Information about a BDM
class BdmInformation {
private:
   unsigned                deviceNumber;
   std::string             serialNumber;
   std::string             description;
   USBDM_ErrorCode         suitable;
   USBDM_bdmInformation_t  info;

public:
   BdmInformation(unsigned deviceNumber, std::string serialNumber, std::string   description ) :
         deviceNumber(deviceNumber),
         serialNumber(serialNumber),
         description(description),
         suitable(BDM_RC_FAIL)   {

      info.size              = sizeof(USBDM_bdmInformation_t);
      info.capabilities      = BDM_CAP_NONE;
      info.commandBufferSize = 0;
      info.jtagBufferSize    = 0;
   }
   BdmInformation() :
      deviceNumber(-1),
      serialNumber("No serial"),
      description("No description"),
      suitable(BDM_RC_FAIL)  {

      info.size              = sizeof(USBDM_bdmInformation_t);
      info.capabilities      = BDM_CAP_NONE;
      info.commandBufferSize = 0;
      info.jtagBufferSize    = 0;
   }
   void setDescription(const std::string& description)   { this->description = description; }
   void setDeviceNumber(unsigned deviceNumber)           { this->deviceNumber = deviceNumber; }
   void setInfo(const USBDM_bdmInformation_t& info)      { this->info = info; }
   void setSerialNumber(const std::string& serialNumber) { this->serialNumber = serialNumber; }
   void setSuitable(USBDM_ErrorCode suitable)            { this->suitable = suitable; }
   
   const std::string&            getDescription() const  { return description; }
   unsigned                      getDeviceNumber() const { return deviceNumber; }
   const USBDM_bdmInformation_t& getInfo() const         { return info; }
   const std::string&            getSerialNumber() const { return serialNumber; }
   USBDM_ErrorCode               getSuitable() const     { return suitable; }
   bool                          isSuitable() const      { return suitable == BDM_RC_OK; }

   bool                          isNullDevice() const    { return deviceNumber < 0; }
};

#endif //_BDMINFORMATION_H_
