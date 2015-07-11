/*! \file
    \brief Header file for BdmInformation

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
   | 16 May 2015 | Created
   +====================================================================
    \endverbatim
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
