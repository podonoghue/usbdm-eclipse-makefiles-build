/*! \file
    \brief Provides device data

    DeviceData.cpp

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
   -====================================================================================================
   | 20 Jan 2015 | Added HCS08sbdfrAddress filed etc.                                  - pgo 4.12.1.10
   | 20 Jan 2015 | Added isWritableMemory()                                            - pgo 4.10.6.250
   |  1 Dec 2014 | Fixed format in printf()s                                           - pgo 4.10.6.230
   | 12 Dec 2014 | Started changes for Kinetis clock trimming                          - pgo 4.10.6.220
   | 29 Aug 2014 | Changes to SDID wildcards                                           - pgo 4.10.6.190
   | 12 Jul 2014 | Added getCommonFlashProgram(), changed getFlashProgram()            - pgo V4.10.6.170
   | 12 Jul 2014 | Added extra SDID handling getSDIDs()                                - pgo V4.10.6.170
   | 12 Aug 2011 | Changed device directory to avoid need for installation when testing- pgo
   | 15 June     | Changed to std::tr1::shared_ptr (from boost)                        - pgo
   +====================================================================================================
   \endverbatim
*/
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>      // for std::setw

#include "DeviceXmlParser.h"
#include "Names.h"
#include "Common.h"
#include "UsbdmSystem.h"
#include "DeviceData.h"
#include "TargetDefines.h"

using namespace std;

static int aToi(char ch) {
   if ((ch >= '0') && (ch <= '9'))
      return ch -'0';
   else if ((ch >= 'a') && (ch <= 'f'))
      return ch -'a' + 10;
   else if ((ch >= 'A') && (ch <= 'F'))
      return ch -'A' + 10;
   else
      return -1;
}

static inline char tohex(uint8_t value) {
   static const char table[] = "0123456789ABCDEF";
   return table[value&0x0F];
}

/*
 * ============================================================================================
 */
class EnumValuePair {
private:
   int                 value;
   const std::string   name;

public:
   int               getValue() const { return value; };
   const std::string getName()  const { return name; };
   EnumValuePair(int value, const std::string &name)
       : value(value), name(name) {
   }
};

/*
 * ============================================================================================
 */
const std::string TclScript::toString() const {
   return std::string(
         "TCL Script\n"
         "============================================================================" +
         script +
         "============================================================================\n");
}
const std::string TclScript::getScript() const {
   return script;
}

/*
 * ============================================================================================
 */

const std::string RegisterDescription::toString() const {
   return std::string(
         "Register Description\n"
         "============================================================================" +
         description +
         "============================================================================\n");
}
const std::string RegisterDescription::getDescription() const {
   return description;
}

unsigned RegisterDescription::getLastRegisterIndex() const {
   return lastRegisterIndex;
}
/*
 * ============================================================================================
 */

const std::string FlashProgram::toString() const {
   return std::string(
         "flashProgram\n"
         "=========================================================================" +
         flashProgram +
         "=========================================================================\n");
}
const std::string FlashProgram::getFlashProgram() const {
   return flashProgram;
}

/*
 * ============================================================================================
 */

const std::string SecurityDescription::toString() const {
   return std::string("SecurityDescription ==") + securityDescription + "==";
}

const std::string SecurityDescription::getSecurityDescription() const {
   return securityDescription;
}

void SecurityDescription::setSecurityDescription(std::string s) {
   securityDescription = s;
}

/*
 * ============================================================================================
 */
//
//const std::string GnuInfoList::toString() const {
//   return std::string("GnuInfoList");
//}

/*
 * ============================================================================================
 */

   /**
    * Create checksum information
    *
    *  @param startAddress Address of start of checksum range
    *  @param endAddress   Address of end of checksum range
    *  @param valueAddress Address of location to store checksum value
    *  @param type         Type of checksum
    */
ChecksumInfo::ChecksumInfo(uint32_t startAddress, uint32_t endAddress, uint32_t locationAddress, ChecksumType type)
   : startAddress(startAddress), endAddress(endAddress), locationAddress(locationAddress), type(type) {
   }

   /**
    * Copy constructor
    *
    * @param other Other to copy
    */
ChecksumInfo::ChecksumInfo(const ChecksumInfo& other)
   : startAddress(other.startAddress), endAddress(other.endAddress), locationAddress(other.locationAddress), type(other.type) {
}
/**
 * Returns a description as a string
 *
 * @return Readable string representing the checksum
 */
const std::string ChecksumInfo::toString() const {
   static const char *typeNames[] = {"twoComplementSum"};
   return std::string("ChecksumInfo - ") + typeNames[type];
}
/**
 * Get security values as array of uint8_t
 *
 * @return constant array
 */
USBDM_ErrorCode ChecksumInfo::updateChecksum(FlashImagePtr flashImage) const {
   LOGGING;

   uint32_t checksum = 0;
   for (uint32_t index=startAddress; index<endAddress; index+=4) {
      uint32_t value = 0;
      value    += flashImage->getValue(index+0);
      value    += flashImage->getValue(index+1)<<8;
      value    += flashImage->getValue(index+2)<<16;
      value    += flashImage->getValue(index+3)<<24;
      checksum += value;
   }
   checksum = -checksum;
   log.print("Setting checksum @0x%08X = 0x%08X\n", locationAddress, checksum);
   flashImage->setValue(locationAddress+0, checksum);
   flashImage->setValue(locationAddress+1, checksum>>8);
   flashImage->setValue(locationAddress+2, checksum>>16);
   flashImage->setValue(locationAddress+3, checksum>>24);

   return BDM_RC_OK;
}
/**
 * Get location of checksum information
 *
 * @return size
 */
unsigned ChecksumInfo::getlocation() const {
   return locationAddress;
}
/**
 * Get size of checksum information
 *
 * @return size
 */
unsigned ChecksumInfo::getSize() const {
   return endAddress - startAddress + 1;
}

/*
 * ============================================================================================
 */
SecurityInfo::SecurityInfo(int size, SecType mode, std::string securityInfo)
: size(size), mode(mode), securityInfo(securityInfo) {
   //       Logging::print("SecurityInfo(%d, %d, %s)\n", size, mode, (const char *)securityInfo.c_str());
   if (size == 0) {
      // Auto size security
      this->size = securityInfo.size()/2;
   }
   else if (this->securityInfo.size()/2 != this->size) {
      throw MyException("Security value does not have correct length");
   }
}

SecurityInfo::SecurityInfo(const SecurityInfo& other)
   : size(other.size), mode(other.mode), securityInfo(other.securityInfo) {
}

const std::string SecurityInfo::toString() const {
   static const char *modeNames[] = {"unsecure", "secure", "custom"};
   return std::string("SecurityInfo - ") + modeNames[mode] + " ==" + securityInfo + "==";
}

std::string SecurityInfo::getSecurityInfo() const {
   return securityInfo;
}

void SecurityInfo::setSecurityInfo(const std::string &securityInfo) {
   this->securityInfo = securityInfo;
}

const uint8_t *SecurityInfo::getData() const {
   unsigned       cSub = 0;
   static uint8_t data[100];
   if (size > sizeof(data)) {
      throw MyException("Security field too large in SecurityInfo::getData()");
   }
   for (unsigned sub=0; sub<size; sub++) {
      // Skip non-numeric leading chars
      while ((aToi(securityInfo[cSub]) < 0) && (cSub < securityInfo.length())) {
         cSub++;
      }
      data[sub]  = aToi(securityInfo[cSub++])<<4;
      data[sub] += aToi(securityInfo[cSub++]);
   }
   return data;
}

void SecurityInfo::setData(unsigned size, uint8_t *data) {
   securityInfo.clear();
   for (unsigned sub=0; sub<size; sub++) {
      char value[2];
      value[0] = tohex(data[sub]>>4);
      value[1] = tohex(data[sub]);
      securityInfo.append(value);
   }
}

void SecurityInfo::setMode(SecType mode) {
   this->mode = mode;
}

unsigned SecurityInfo::getSize() const {
    return size;
}

SecurityInfo::SecType SecurityInfo::getMode() const {
    return mode;
}

/*
 * ============================================================================================
 */
 const std::string SecurityEntry::toString() const {
    return std::string("SecurityEntry - \n") +
           "=========================================================================\n" +
           "description =" + ((securityDescription==NULL)?std::string("null"):securityDescription->toString()) + "\n" +
           "unsecured   =" + ((unsecureInformation==NULL)?std::string("null"):unsecureInformation->toString()) + "\n" +
           "secured     =" + ((secureInformation==NULL)?std::string("null"):secureInformation->toString()) + "\n" +
           "custom      =" + ((customSecureInformation==NULL)?std::string("null"):customSecureInformation->toString()) + "\n" +
           "=========================================================================\n";
 }

 SecurityDescriptionConstPtr SecurityEntry::getSecurityDescription() const {
    return securityDescription;
 }

 SecurityInfoConstPtr SecurityEntry::getUnsecureInformation() const {
    return unsecureInformation;
 }

 SecurityInfoConstPtr SecurityEntry::getSecureInformation() const {
    return secureInformation;
 }

 SecurityInfoConstPtr SecurityEntry::getCustomSecureInformation() const {
    return customSecureInformation;
 }

 SecurityDescriptionPtr SecurityEntry::getSecurityDescription() {
    return securityDescription;
 }

 SecurityInfoPtr SecurityEntry::getUnsecureInformation() {
    return unsecureInformation;
 }

 SecurityInfoPtr SecurityEntry::getSecureInformation() {
    return secureInformation;
 }

 SecurityInfoPtr SecurityEntry::getCustomSecureInformation() {
    return customSecureInformation;
 }

 void SecurityEntry::setCustomSecureInformation(SecurityInfoPtr ptr) {
    customSecureInformation = ptr;
 }

/*
 * ============================================================================================
 */
 FlexNVMInfo::EeepromSizeValue::EeepromSizeValue(std::string description, uint8_t value, unsigned size)
   : description(description), value(value), size(size) {
 }

FlexNVMInfo::FlexNvmPartitionValue::FlexNvmPartitionValue(std::string description, uint8_t value, unsigned backingStore)
   : description(description), value(value), backingStore(backingStore) {
}

const std::string FlexNVMInfo::toString() const {
  return std::string("FlexNVMInfo - \n");
}

//! Returns list of permitted EEEPROM values for use in partition command
//!
//! @return vector of permitted values
//!
const std::vector<FlexNVMInfo::EeepromSizeValue> &FlexNVMInfo::getEeepromSizeValues() const {
  return eeepromSizeValues;
}

//! Returns list of permitted Partition values for use in partition command
//!
//! @return vector of permitted values
//!
const std::vector<FlexNVMInfo::FlexNvmPartitionValue> &FlexNVMInfo::getFlexNvmPartitionValues() const {
  return flexNvmPartitionValues;
}

//! Adds a permitted EEEPROM values for use in partition command
//!
//! @param eeepromSizeValue - Description of value
//!
void FlexNVMInfo::addEeepromSizeValues(const EeepromSizeValue &eeepromSizeValue) {
   this->eeepromSizeValues.push_back(eeepromSizeValue);
}

//! Adds a permitted Partition values for use in partition command
//!
//! @param flexNvmPartitionValue  - Description of value
//!
void FlexNVMInfo::addFlexNvmPartitionValues(const FlexNvmPartitionValue &flexNvmPartitionValue) {
   this->flexNvmPartitionValues.push_back(flexNvmPartitionValue);
}

//! Return minimum required ration between backing store in EEPROM and EEEPROM
//!
//! @return ratio e.g. 16 => EEPROM size >= 16* EEEPROM size
//!
unsigned FlexNVMInfo::getBackingRatio() const {
    return backingRatio;
}

void FlexNVMInfo::setBackingRatio(unsigned  backingRatio) {
    this->backingRatio = backingRatio;
}

/*
 * ============================================================================================
 */

//! Find the index of the memory range containing the given address
//!
//! @param address - address to look for
//!
//! @return range index or -1 if not found
//!
//! @note - Uses cache
//!
int MemoryRegion::findMemoryRangeIndex(uint32_t address) const {
   if (type == MemInvalid)
      return -1;
   // Check cached address
   if ((lastIndexUsed < memoryRanges.size()) &&
       (memoryRanges[lastIndexUsed].start <= address) && (address <= memoryRanges[lastIndexUsed].end)) {
      return lastIndexUsed;
   }
   // Look through all memory ranges
   for (lastIndexUsed=0; lastIndexUsed<memoryRanges.size(); lastIndexUsed++) {
      if ((memoryRanges[lastIndexUsed].start <= address) && (address <= memoryRanges[lastIndexUsed].end)) {
         return lastIndexUsed;
      }
   }
//      // clear cache
//      lastIndexUsed = 1000;
   return -1;
}

//! Add a memory range to this memory region
//!
//! @param startAddress - start address (inclusive)
//! @param endAddress   - end address (inclusive)
//! @param pageNo       - page number (if used)
//!
void MemoryRegion::addRange (uint32_t startAddress, uint32_t endAddress, uint16_t pageNo) {
// print("addRange(0x%6X, 0x%6X, 0x%2X)\n", startAddress, endAddress, pageNo);
   if (memoryRanges.size() == memoryRanges.capacity()) {
      unsigned newCapacity = 2*memoryRanges.capacity();
      if (newCapacity < 8) {
         newCapacity = 8;
      }
//    print("addRange() - resizing %d=>%d\n", memoryRanges.capacity(), newCapacity);
      memoryRanges.reserve(newCapacity);
   }
   if (pageAddress == 0) {
      // Non-paged memory
      pageNo = NoPageNo;
   }
   else if (pageNo == DefaultPageNo) {
      // Page no is usually just the 8-bit address
      pageNo = (startAddress>>16)&0xFF;
   }
   MemoryRange memoryRangeE = {startAddress, endAddress, pageNo};
   memoryRanges.push_back(memoryRangeE);
}

//! Check if an address is within this memory region
//! @param address - address to check
//!
//! @return true/false result
//!
bool MemoryRegion::contains(uint32_t address) const {
   return findMemoryRangeIndex(address) >= 0;
}

//! Find the last contiguous address relative to the address
//!
//! @param address        Start address to check
//! @param lastContinuous The end address of the largest contiguous memory range including address
//! @param memorySpace    Memory space to check
//!
//! @return true  = start address is within memory
//!         false = start address is not within memory
//!
bool MemoryRegion::findLastContiguous(uint32_t address, uint32_t *lastContinuous, MemorySpace_t memorySpace) const {
   *lastContinuous = address;
   if (!isCompatibleType(memorySpace)) {
      return false;
   }
   int index = findMemoryRangeIndex(address);
   if (index<0) {
      // Start address not within region
      return false;
   }
   *lastContinuous = memoryRanges[index].end;
   return true;
}

//! Get page number for address
//! @param address - address to check
//!
//! @return MemoryRegion::NoPageNo if not paged/within memory
//!
uint16_t MemoryRegion::getPageNo(uint32_t address) const {
   if (!contains(address))
      return MemoryRegion::NoPageNo;
   return memoryRanges[lastIndexUsed].pageNo;
}

//! Obtain string describing the memory type
//!
//! @param memoryType - Memory type
//!
//! @return - ptr to static string describing type
//!
const char *MemoryRegion::getMemoryTypeName(MemType_t memoryType) {
   static const char *names[] = {
            "Invalid",
            "RAM",
            "EEPROM",
            "FLASH",
            "FlexNVM",
            "FlexRAM",
            "ROM",
            "IO",
            "PFlash",
            "DFlash",
            "XRAM",
            "PRAM",
            "XROM",
            "PROM",
   };
   if((unsigned )((memoryType)) >= (sizeof (names) / sizeof (names[0])))
      memoryType = (MemType_t)((0));
   return names[memoryType];
}

//! Get name of memory type
//!
const char *MemoryRegion::getMemoryTypeName(void) const { return getMemoryTypeName(type); }

//! Indicates if a programmable type e.g Flash, eeprom etc.
//!
//! @param memoryType - Memory type
//!
//! @return - true/false result
//!
bool MemoryRegion::isProgrammableMemory(MemType_t memoryType) {
   switch (memoryType) {
      case MemEEPROM  :
      case MemFLASH   :
      case MemFlexNVM :
      case MemPFlash  :
      case MemDFlash  :
      case MemXROM    :
      case MemPROM    :
         return true;
         break;
      default :
         return false;
   }
}

//! Indicates if the memory region is of a programmable type e.g Flash, eeprom etc.
//!
//! @return - true/false result
//!
bool MemoryRegion::isProgrammableMemory() const {
   return isProgrammableMemory(type);
}

//! Indicates if a simple writable type e.g RAM etc.
//!
//! @param memoryType - Memory type
//!
//! @return - true/false result
//!
bool MemoryRegion::isWritableMemory(MemType_t memoryType) {
   switch (memoryType) {
      case MemFlexRAM  :
      case MemRAM      :
      case MemXRAM     :
      case MemPRAM     :
         return true;
         break;
      default :
         return false;
   }
}

//! Indicates if the memory region is of a programmable type e.g Flash, eeprom etc.
//!
//! @return - true/false result
//!
bool MemoryRegion::isWritableMemory() const {
   return isWritableMemory(type);
}

//! Get security address (Flash location)
//!
uint32_t MemoryRegion::getSecurityAddress() const {
   LOGGING_Q;
   log.print(" A = 0x%08X\n", securityAddress);
   return securityAddress;
}

// Only available on Flash & EEPROM
uint32_t    MemoryRegion::getFCLKDIVAddress() const {
   return getRegisterAddress() + 0x0;
}

uint32_t    MemoryRegion::getFSECAddress() const {
   return getRegisterAddress() + 0x1;
}

uint32_t    MemoryRegion::getFTSTMODAddress() const {
   return getRegisterAddress() + 0x1;
}

uint32_t    MemoryRegion::getFCNFGAddress() const {
   return getRegisterAddress() + 0x3;
}

uint32_t    MemoryRegion::getFPROTAddress() const {
   return getRegisterAddress() + 0x4;
}

uint32_t    MemoryRegion::getFSTATAddress() const {
   return getRegisterAddress() + 0x5;
}

uint32_t    MemoryRegion::getFCMDAddress() const {
   return getRegisterAddress() + 0x6;
}

uint32_t    MemoryRegion::getFADDRAddress() const {
   return getRegisterAddress() + 0x8;
}

uint32_t    MemoryRegion::getFDATAAddress() const {
   return getRegisterAddress() + 0xA;
}

uint32_t    MemoryRegion::getDummyAddress() const {
   return memoryRanges[0].end & 0xFFFFFFF0;
}

uint32_t    MemoryRegion::getSectorSize() const {
   return sectorSize;
}

AddressType MemoryRegion::getAddressType() const {
   return addressType;
}

// Get memory region data alignment (1,2,4 etc)
uint32_t     MemoryRegion::getAlignment() const {
   return alignment;
}

uint32_t    MemoryRegion::getFOPTAddress() const {
   return getRegisterAddress();
}
uint32_t    MemoryRegion::getFLCRAddress() const {
   return getRegisterAddress() + 1;
}

bool MemoryRegion::valid() const {
   return type != MemInvalid;
}

void MemoryRegion::setSecurityAddress(uint32_t address) {
   LOGGING_E;
   securityAddress = address;
   log.print(" A = 0x%08X\n", securityAddress);
}

MemType_t MemoryRegion::getMemoryType() const {
   return type;
}

//! Indicates if a memory type is compatible with a memory space e.g. MemPROM lies in MS_Program
//!
//! @param memoryType  - Memory type
//! @param memorySpace - Memory space
//!
//! @return - true/false result
//!
bool MemoryRegion::isCompatibleType(MemType_t memoryType, MemorySpace_t memorySpace) {
   switch(memorySpace&MS_SPACE) {
      default         : return true;
      case MS_Program : return ((memoryType == MemPRAM) || (memoryType == MemPROM));
      case MS_Data    : return ((memoryType == MemXRAM) || (memoryType == MemXROM));
   }
}

bool MemoryRegion::isCompatibleType(MemorySpace_t memorySpace) const {
   return isCompatibleType(type, memorySpace);
}

uint32_t  MemoryRegion::getPageAddress() const {
   return pageAddress;
}

uint32_t  MemoryRegion::getRegisterAddress() const {
   return registerAddress;
}

const MemoryRegion::MemoryRange *MemoryRegion::getMemoryRange(unsigned index) const {
   if (index >= memoryRanges.size())
      return NULL;
   return &memoryRanges[index];
}

const MemoryRegion::MemoryRange *MemoryRegion::getMemoryRangeFor(uint32_t address) const {
   int index = findMemoryRangeIndex(address);
   if (index<0)
      return NULL;
   return &memoryRanges[index];
}

const FlashProgramConstPtr MemoryRegion::getFlashprogram() const {
   return flashProgram;
}

const SecurityDescriptionConstPtr MemoryRegion::getSecurityDescription() const {
   return securityInformation->getSecurityDescription();
}

const ChecksumInfoPtr MemoryRegion::getChecksumInfo() const {
   return checksumInfo;
}

void MemoryRegion::setChecksumInfo(const ChecksumInfoPtr value) {
   checksumInfo = value;
}

const SecurityInfoConstPtr MemoryRegion::getSecureInfo() const {
   return securityInformation->getSecureInformation();
}

const SecurityInfoConstPtr MemoryRegion::getUnsecureInfo() const {
   return securityInformation->getUnsecureInformation();
}

const SecurityInfoConstPtr MemoryRegion::getCustomSecureInfo() const {
   return securityInformation->getCustomSecureInformation();
}

void MemoryRegion::setFlashProgram(FlashProgramConstPtr program) {
   flashProgram = program;
}
void MemoryRegion::setAddressType(AddressType type) {
   addressType = type;
}

void MemoryRegion::setSecurityEntry(SecurityEntryPtr info) {
   securityInformation = info;
}

void MemoryRegion::setflexNVMInfo(FlexNVMInfoConstPtr info) {
   flexNVMInfo = info;
}

SecurityEntryConstPtr   MemoryRegion::getSecurityEntry() const {
   return securityInformation;
}

SecurityEntryPtr        MemoryRegion::getSecurityEntry() {
   return securityInformation;
}

FlexNVMInfoConstPtr     MemoryRegion::getflexNVMInfo() const {
   return flexNVMInfo;
}

/*
 * ============================================================================================
 */

//! Get readable names for erase options
const char *DeviceData::getEraseOptionName(EraseOptions option) {
   switch (option) {
   case eraseNone      : return "EraseNone";
   case eraseMass      : return "EraseMass";
   case eraseAll       : return "EraseAll";
   case eraseSelective : return "EraseSelective";
   default :             return "Illegal erase option";
   }
}

//! Structure to hold FlexNVM information
class FlexNVMParameters {
public:
   FlexNVMParameters() :
      eeepromSize(0xFF),
      partionValue(0xFF) {
   }
   uint8_t eeepromSize;
   uint8_t partionValue;
};

const std::string DeviceData::getTargetName() const {
   return targetName;
}

const std::string DeviceData::getAliasName() const {
   return aliasName;
}

bool DeviceData::isHidden() const {
   return hidden;
}

uint32_t DeviceData::getRamStart() const {
   return ramStart;
}

uint32_t DeviceData::getRamEnd() const {
   return ramEnd;
}

ClockTypes_t DeviceData::getClockType() const {
   return clockType;
}

uint32_t DeviceData::getClockAddress() const {
   return clockAddress;
}

uint32_t DeviceData::getClockTrimNVAddress() const {
   return clockTrimNVAddress;
}

unsigned long DeviceData::getClockTrimFreq() /*Hz*/ const {
   return clockTrimFreq;
}

unsigned long DeviceData::getConnectionFreq() /*Hz*/ const {
   return connectionFreq;
}

SecurityOptions_t DeviceData::getSecurity() const {
   return security;
}

DeviceData::EraseOptions DeviceData::getEraseOption() const {
   return eraseOption;
}

uint32_t DeviceData::getWatchdogAddress() const {
   return watchdogAddress;
}

uint32_t DeviceData::getSDIDAddress() const {
   return SDIDAddress;
}

unsigned int DeviceData::getBDMtoBUSFactor() const {
   return BDMtoBUSFactor;
}

FlashProgramConstPtr DeviceData::getCommonFlashProgram() const {
   return commonFlashProgram;
}

TclScriptConstPtr DeviceData::getFlashScripts() const {
   return flashScripts;
}

FlexNVMInfoConstPtr DeviceData::getflexNVMInfo() const {
   return flexNVMInfo;
}

DeviceData::FlexNVMParameters DeviceData::getFlexNVMParameters() const {
   return flexNVMParameters;
}

const std::vector<TargetSDID>& DeviceData::getTargetSDIDs() const {
   return targetSDIDs;
}

bool DeviceData::isAlias(void) const {
   return !aliasName.empty();
}

RegisterDescriptionConstPtr DeviceData::getRegisterDescription() const {
   return registerDescription;
}

MemoryRegionConstPtr DeviceData::getMemoryRegion(unsigned index) const {
   if (index >= memoryRegions.size()) {
      return MemoryRegionPtr();
   }
   return memoryRegions[index];
}

MemoryRegionPtr DeviceData::getMemoryRegion(unsigned index) {
   if (index >= memoryRegions.size()) {
      return MemoryRegionPtr();
   }
   return memoryRegions[index];
}

uint32_t DeviceData::getDefaultHCS08sbdfrAddress() {
   return HCS08_SBDFR_DEFAULT;
}

uint32_t DeviceData::getHCS08sbdfrAddress() const {
   return hcs08sbdfrAddress;
}

void DeviceData::setHCS08sbdfrAddress(uint32_t address) {
   hcs08sbdfrAddress = address;
}

//! Determines the memory region containing an address in given memory space
//!
//! @param address     - The address to check
//! @param memorySpace - Memory space to check (MS_None, MS_Program, MS_Data)
//!
//! @return shared_ptr for Memory region found (or NULL if none found)
//!
MemoryRegionConstPtr DeviceData::getMemoryRegionFor(uint32_t address, MemorySpace_t memorySpace) const {
   // Check cached location to avoid searching in many cases
   if ((lastMemoryRegionUsed != NULL) &&
        lastMemoryRegionUsed->isCompatibleType(memorySpace) &&
        lastMemoryRegionUsed->contains(address)
        ) {
      return lastMemoryRegionUsed;
   }
   for (int index=0; ; index++) {
      lastMemoryRegionUsed = getMemoryRegion(index);
      if (lastMemoryRegionUsed == NULL) {
         break;
      }
      if (lastMemoryRegionUsed->isCompatibleType(memorySpace) &&
          lastMemoryRegionUsed->contains(address) ) {
         return lastMemoryRegionUsed;
      }
   }
   return MemoryRegionPtr();
}

const std::vector<TargetSDID> DeviceData::getSDIDs() const {
   return targetSDIDs;
}

TargetSDID DeviceData::getSDID(unsigned index) const {
   if (index >= targetSDIDs.size()) {
      return TargetSDID(-1,-1);
   }
   return targetSDIDs[index];
}

void  DeviceData::addSDID(uint32_t mask, uint32_t value) {
   targetSDIDs.push_back(TargetSDID(mask, value));
}

void DeviceData::addMemoryRegion(MemoryRegionPtr pMemoryRegion) {
   memoryRegions.push_back(pMemoryRegion);
   if (((pMemoryRegion->getMemoryType() == MemRAM)||
        (pMemoryRegion->getMemoryType() == MemXRAM)) && (ramStart == 0)) {
      // Set default RAM range to first added RAM memory region
      const MemoryRegion::MemoryRange *mr = pMemoryRegion->getMemoryRange(0);
      ramStart = mr->start;
      ramEnd   = mr->end;
   }
   if (pMemoryRegion->getMemoryType() == MemFlexNVM) {
      // Copy FlexInfo from memory region to device - Only one FlexNVM in device allowed
      if (getflexNVMInfo() != NULL) {
         throw MyException("Multiple MemFlexNVM regions in device");
      }
      setflexNVMInfo(pMemoryRegion->getflexNVMInfo());
   }
}

void DeviceData::setTargetName(const std::string &name) {
   targetName = name;
}

void DeviceData::setAliasName(const std::string &name) {
   aliasName = name;
}

void DeviceData::setHidden(bool value) {
   hidden = value;
}

void DeviceData::setRamStart(uint32_t addr)  {
   ramStart = addr;
}

void DeviceData::setRamEnd(uint32_t addr) {
   ramEnd = addr;
}

void DeviceData::setClockType(ClockTypes_t type) {
   clockType = type;
}

void DeviceData::setClockAddress(uint32_t addr) {
   clockAddress = addr;
}

void DeviceData::setClockTrimNVAddress(uint32_t addr) {
   clockTrimNVAddress = addr;
}

void DeviceData::setClockTrimFreq(unsigned long hertz) /*Hz*/   {
   clockTrimFreq = hertz;
}

void DeviceData::setConnectionFreq(unsigned long hertz /*Hz*/)  {
   connectionFreq = hertz;
}

void DeviceData::setSecurity(SecurityOptions_t option)  {
   security = option;
}

void DeviceData::setEraseOption(EraseOptions option) {
   eraseOption = option;
}

void DeviceData::setWatchdogAddress(uint32_t addr)   {
   watchdogAddress = addr;
}

void DeviceData::setSDIDAddress(uint32_t addr) {
   SDIDAddress = addr;
}

void DeviceData::setFlashScripts(TclScriptConstPtr script){
   flashScripts = script;
}

void DeviceData::setCommonFlashProgram(FlashProgramConstPtr program) {
   commonFlashProgram = program;
}

void DeviceData::setflexNVMInfo(FlexNVMInfoConstPtr info) {
   flexNVMInfo = info;
}

void DeviceData::setFlexNVMParameters(const FlexNVMParameters &param) {
   flexNVMParameters = param;
}

void DeviceData::setTargetSDIDs(const std::vector<TargetSDID> &list) {
   targetSDIDs = list;
}

void DeviceData::setRegisterDescription(RegisterDescriptionConstPtr desc)  {
   registerDescription = desc; }

static string emptyString("");

/**
 *  Allows meaningful printing of memory ranges
 */
std::ostream& operator<<(std::ostream& s, const MemoryRegion mr) {
   s << setiosflags (ios_base::showbase | ios_base::hex);
   s << mr.getMemoryTypeName(mr.type) <<  "[";
   for (unsigned rangeIndex=0; rangeIndex<mr.memoryRanges.size(); rangeIndex++) {
      s << mr.memoryRanges[rangeIndex].start << "..." << mr.memoryRanges[rangeIndex].end;
      if (rangeIndex+1<mr.memoryRanges.size())
         s << ',';
   }
   if (mr.registerAddress != 0)
      s << ", reg=" << mr.registerAddress;
   if (mr.pageAddress != 0)
      s << ", pp=" << mr.pageAddress;
   s << "]";
   s << resetiosflags (ios_base::showbase | ios_base::uppercase | ios_base::hex);
   return s;
}

//! Mappings for Clock types
const EnumValuePair ClockTypes::clockNames[] = {
   EnumValuePair(  CLKEXT,       ("External") ),
   EnumValuePair(  S08ICGV1,     ("S08ICGV1") ),
   EnumValuePair(  S08ICGV2,     ("S08ICGV2") ),
   EnumValuePair(  S08ICGV3,     ("S08ICGV3") ),
   EnumValuePair(  S08ICGV4,     ("S08ICGV4") ),
   EnumValuePair(  S08ICSV1,     ("S08ICSV1") ),
   EnumValuePair(  S08ICSV2,     ("S08ICSV2") ),
   EnumValuePair(  S08ICSV2x512, ("S08ICSV2x512") ),
   EnumValuePair(  S08ICSV3,     ("S08ICSV3") ),
   EnumValuePair(  S08ICSV4,     ("S08ICSV4") ),
   EnumValuePair(  S08MCGV1,     ("S08MCGV1") ),
   EnumValuePair(  S08MCGV2,     ("S08MCGV2") ),
   EnumValuePair(  S08MCGV3,     ("S08MCGV3") ),
   EnumValuePair(  RS08ICSOSCV1, ("RS08ICSOSCV1") ),
   EnumValuePair(  RS08ICSV1,    ("RS08ICSV1") ),
   EnumValuePair(  MKMCGV1,      ("MCG_MK") ),
   EnumValuePair(  CLKINVALID,   ("Invalid") ),
   EnumValuePair(  0,              ""),
};

DeviceDataPtr DeviceData::shallowCopy() const {
   DeviceData *copy = new DeviceData(targetType, targetName);
   *copy = *this;
   return DeviceDataPtr(copy);
}

/**
 *  Returns the default non-volatile flash location for the clock trim value
 *
 * @param  clockType - clock type being queried
 *
 * @return Address of clock trim location(s)
 */
uint32_t DeviceData::getDefaultClockTrimNVAddress(ClockTypes_t clockType) const {
   if (targetType == T_RS08) {
    return 0x3FFA;
   }
   else if (targetType == T_CFV1) {
      return 0x3FE;
   }
   else if (targetType == T_HCS08) {
      switch (clockType) {
         case S08ICGV1 :
         case S08ICGV2 :
         case S08ICGV3 :
         case S08ICGV4 :      return 0xFFBE;

         case S08ICSV1 :
         case S08ICSV2 :
         case S08ICSV2x512 :
         case S08ICSV3 :
         case RS08ICSOSCV1 :
         case RS08ICSV1 :     return 0xFFAE;

         case S08ICSV4 :      return 0xFF6E;

         case S08MCGV1 :
         case S08MCGV2 :
         case S08MCGV3 :      return 0xFFAE;

         case CLKINVALID :
         case CLKEXT :
         default :            return 0U;
      }
   }
   else if (targetType == T_ARM) {
      return 0x03FE;
   }
   return 0;
}

/**
 *  Returns the default non-volatile flash location for the clock trim value
 *
 * @return Address of clock trim location(s) for the current clock type
 */
uint32_t DeviceData::getDefaultClockTrimNVAddress()  const {
   return getDefaultClockTrimNVAddress(clockType);
}

/**
 *  Returns the default (nominal) trim frequency for the given clock
 *
 * @return clock trim frequency in Hz.
 */
uint32_t DeviceData::getDefaultClockTrimFreq(ClockTypes_t clockType) const {
   switch (clockType) {
   case S08ICGV1 :
   case S08ICGV2 :
   case S08ICGV3 :
   case S08ICGV4 :
      return 243000UL;
   case S08ICSV1 :
   case S08ICSV2 :
   case S08ICSV2x512 :
   case S08ICSV3 :
   case S08ICSV4 :
   case RS08ICSOSCV1 :
   case RS08ICSV1 :
      return 31250UL;
   case S08MCGV1 :
   case S08MCGV2 :
   case S08MCGV3 :
      return 31250UL;
   case MKMCGV1 :
      return 31250UL;
   case CLKINVALID :
   case CLKEXT :
   default :
      return 0U;
   }
}

/**
 *  Returns the default (nominal) trim frequency for the currently selected clock
 *
 * @return clock trim frequency in Hz.
 */
uint32_t DeviceData::getDefaultClockTrimFreq()  const {
   return getDefaultClockTrimFreq(clockType);
}

/*!
 * Gets the 'default' flash program
 * This will either be the common one set or the one from the first memory region found
 * to contain one.
 *
 * @return reference to flash program.
 */
FlashProgramConstPtr DeviceData::getFlashProgram() const {
   if (commonFlashProgram) {
      // Common program set - return it
      return commonFlashProgram;
   }
   // Find the 1st memory region with a program set
   FlashProgramConstPtr flashProgram;
   for (int index=0; ; index++) {
      MemoryRegionConstPtr memoryRegionPtr = getMemoryRegion(index);
      if (memoryRegionPtr == NULL) {
         break;
      }
      flashProgram = memoryRegionPtr->getFlashprogram();
      if (flashProgram != NULL) {
         break;
      }
   }
   return flashProgram;
}

/**
 *  Returns the default clock register address
 *
 * @return clock register address
 */
uint32_t DeviceData::getDefaultClockAddress(ClockTypes_t clockType) const {
   if (targetType == T_CFV1) {
      return 0xFF8048; // There really isn't a sensible default
   }
   else if (targetType == T_RS08) {
      return 0x0238;   // There really isn't a sensible default
   }
   else if (targetType == T_HCS08) {
      switch (clockType) {
         case S08ICGV1 :
         case S08ICGV2 :
         case S08ICGV3 :
         case S08ICGV4 :
         case S08MCGV1 :
         case S08MCGV2 :
         case S08MCGV3 :
            return 0x0048;

         case S08ICSV1 :
         case S08ICSV2x512 :
            return 0x0038;

         case S08ICSV2 :
            return 0x0048;

         case S08ICSV3 :
            return 0x0038;

         case RS08ICSOSCV1 :
            return 0x023C;

         case RS08ICSV1 :
         case CLKINVALID :
         case CLKEXT :
         default :
            return 0U;
      }
   }
   else if (targetType == T_HCS08) {
      return  MKMCGV1;
   }
   return 0U;
}

/**
 *  Returns the default (nominal) trim frequency for the currently selected clock
 *
 *  @return clock trim frequency in Hz.
 */
uint32_t DeviceData::getDefaultClockAddress()  const {
   return getDefaultClockAddress(clockType);
}

 /**
  *  Determines the clock type from a string description
  */
ClockTypes_t ClockTypes::getClockType(const std::string &typeName) {
   LOGGING_Q;
   int sub;

   for (sub=0; !clockNames[sub].getName().empty(); sub++) {
      if (clockNames[sub].getName().compare(typeName) == 0) {
         return (ClockTypes_t) clockNames[sub].getValue();
      }
   }
   log.print("Error: invalid clock type '%s'\n", typeName.c_str());
   return CLKINVALID;
}

/**
 *  Determines the clock type from a string description
 */
ClockTypes_t ClockTypes::getClockType(const char *_typeName) {
   string typeName(_typeName);
   return getClockType(typeName);
}

int ClockTypes::getClockIndex(const std::string &typeName) {
   return (int)getClockType(typeName);
}

int ClockTypes::getClockIndex(ClockTypes_t clockType) {
   return (int)clockType;
}

/**
 *  Determines the clock name from a clock type
 *
 * @param clockType Clocktype to map to name
 *
 * @return string describing the clock
 */
const string ClockTypes::getClockName(ClockTypes_t clockType) {
   LOGGING_Q;
   int sub;

   for (sub=0; !clockNames[sub].getName().empty(); sub++) {
      if (clockNames[sub].getValue() == clockType)
         return clockNames[sub].getName();
   }
   log.print("Error: invalid clock type %d\n", clockType);
   return emptyString;
}

/**
 *  Checks if the SDID is used by the device
 *
 * @param desiredSDID  The SDID to check against
 * @param acceptZero   Accept a zero SDID
 *
 * @return true/false result of check
 */
bool DeviceData::isThisDevice(uint32_t  desiredSDID, bool acceptZero) const {
   LOGGING_Q;
   unsigned int index;

   if (targetType == T_ARM) {
      // Some Kinetis devices don't have the SDID programmed correctly
      if ((acceptZero) && (desiredSDID == 0x000000FF)) {
         log.print("Matching %10s as blank SDID\n", getTargetName().c_str());
         return true;
      }
   }

   // Use mask=0 to indicate wild-card
   if ((targetSDIDs.size() == 0)||(targetSDIDs[0].mask == 0)) {
      // 0x0000 or empty may match all
      if (acceptZero) {
         log.print("Matching %10s with Wild-card - %s\n", getTargetName().c_str(), acceptZero?"True":"False");
      }
      return acceptZero;
   }
   for (index=0; index<targetSDIDs.size(); index++) {
//      log.print("Comparing 0x%08X with (V=0x%08X, M=0x%08X)\n",
//                     desiredSDID, targetSDIDs[index].value, targetSDIDs[index].mask);
      if (((targetSDIDs[index].value^desiredSDID)&targetSDIDs[index].mask) == 0x0000) {
         log.print("Matched %10s 0x%08X with (V=0x%08X, M=0x%08X)\n",
                        getTargetName().c_str(), desiredSDID, targetSDIDs[index].value, targetSDIDs[index].mask);
         return true;
      }
   }
   return false;
}

/**
 *  Checks if any of the SDIDs provided are used by the device
 *
 * @param desiredSDIDs map<SDIDaddress,SDID> to check against
 * @param acceptZero   Accept a zero SDID
 *
 * @return true/false result of check
 */
bool DeviceData::isThisDevice(std::map<uint32_t,uint32_t> desiredSDIDs, bool acceptZero) const {
   LOGGING_Q;
   map<uint32_t,uint32_t>::iterator sdidEntry;

   // Use mask=0 to indicate wild-card
   if ((targetSDIDs.size() == 0)||(targetSDIDs[0].mask == 0)) {
      // 0x0000 or empty may match all
      if (acceptZero) {
         log.print("Matching %10s with Wild-card - %s\n", getTargetName().c_str(), acceptZero?"True":"False");
      }
      return acceptZero;
   }
   for (sdidEntry = desiredSDIDs.begin();
        sdidEntry != desiredSDIDs.end();
        sdidEntry++) {
      if ((SDIDAddress == sdidEntry->first) && isThisDevice(sdidEntry->second, acceptZero ))
         return true;
      }
   return false;
}

/**
 *  Determines the memory type for an address
 *
 * @param address     - The address to check
 * @param memorySpace - Memory space to check (MS_None, MS_Program, MS_Data)
 *
 * @return Memory type of region (or MemInvalid if no information available)
 */
MemType_t DeviceData::getMemoryType(uint32_t address, MemorySpace_t memorySpace) {
   MemoryRegionConstPtr memoryRegion = getMemoryRegionFor(address, memorySpace);
   if (memoryRegion != NULL) {
      return memoryRegion->getMemoryType();
   }
   return MemInvalid;
}

/**
 *  Sets the security of all memory regions to a custom value
 *
 * @param securityValue - custom value to use
 */
void DeviceData::setCustomSecurity(const std::string &securityValue) {
   LOGGING_E;
   security = SEC_CUSTOM;
   int index = 0;
   MemoryRegionPtr memoryRegionPtr = getMemoryRegion(index);
   while (memoryRegionPtr != NULL) {
      const MemoryRegion::MemoryRange *memoryRange = memoryRegionPtr->getMemoryRange(0);
      if (memoryRange == NULL) {
         throw(MyException("DeviceData::setCustomSecurity() - empty memory range!"));
      }
      SecurityEntryPtr securityEntry = memoryRegionPtr->getSecurityEntry();
      if (securityEntry != NULL) {
         log.print("securityEntry = %p, use_count = %ld, securityInfo = %s\n", &*securityEntry, securityEntry.use_count(), (const char *)securityEntry->toString().c_str());
         securityEntry->setCustomSecureInformation(SecurityInfoPtr(new SecurityInfo(0, SecurityInfo::custom, securityValue)));
         SecurityInfoPtr getCustomSecureInformation = securityEntry->getCustomSecureInformation();
//         log.print("getCustomSecureInformation = %p, use_count = %d, size = %d, securityInfo = %s\n", &*getCustomSecureInformation, getCustomSecureInformation.use_count(), getCustomSecureInformation->getSize(), (const char *)getCustomSecureInformation->toString().c_str());
      }
      memoryRegionPtr = getMemoryRegion(++index);
   }
}

/**
 *  Determines the page number for an address
 *
 * @param address - The address to check
 *
 * @return page number (PPAGE value) or  MemoryRegion::NoPageNo if not paged/found
 */
uint16_t DeviceData::getPageNo(uint32_t address) {
   // Check cached location to avoid searching in most cases
   if ((lastMemoryRegionUsed != NULL) && lastMemoryRegionUsed->contains(address))
      return lastMemoryRegionUsed->getPageNo(address);

   for (int index=0; ; index++) {
      lastMemoryRegionUsed = getMemoryRegion(index);
      if (lastMemoryRegionUsed == NULL)
         break;
      if (lastMemoryRegionUsed->contains(address))
         return lastMemoryRegionUsed->getPageNo(address);
   }
   return MemoryRegion::NoPageNo;
}

/*
 * ============================================================================================
 */

const DeviceData &DeviceDataBase::operator[](unsigned index) const {
   if (index > deviceData.size()) {
      throw MyException("DeviceDataBase::operator[] - illegal index");
   }
   return *deviceData[index];
};

std::vector<DeviceDataPtr>::const_iterator DeviceDataBase::begin() const {
   return static_cast<std::vector<DeviceDataPtr>::const_iterator>(deviceData.begin());
}

std::vector<DeviceDataPtr>::const_iterator DeviceDataBase::end() const {
   return static_cast<std::vector<DeviceDataPtr>::const_iterator>(deviceData.end());
}

DeviceDataPtr DeviceDataBase::getDefaultDevice() {
   return defaultDevice;
}

unsigned DeviceDataBase::getNumDevice() const {
   return this->deviceData.size();
}

void DeviceDataBase::setDefaultDevice(DeviceDataPtr defaultDevice) {
   this->defaultDevice = defaultDevice;
}

DeviceDataPtr DeviceDataBase::addDevice(DeviceDataPtr device) {
   std::vector<DeviceDataPtr>::iterator itDev = deviceData.insert(deviceData.end(), device);
   return *itDev;
}

SharedInformationItemPtr DeviceDataBase::addSharedData(std::string key, SharedInformationItemPtr pSharedData) {
   sharedInformation.insert(std::pair<const std::string, SharedInformationItemPtr>(key, pSharedData));
   return pSharedData;
}

SharedInformationItemPtr DeviceDataBase::addSharedData(std::string key, SharedInformationItem *sharedData) {
   SharedInformationItemPtr pSharedData(sharedData);
   sharedInformation.insert(std::pair<const std::string, SharedInformationItemPtr>(key, pSharedData));
   return pSharedData;
}

SharedInformationItemPtr DeviceDataBase::getSharedData(std::string key) const {
   std::map<const std::string, SharedInformationItemPtr>::const_iterator it = sharedInformation.find(key);
   if (it == sharedInformation.end()) {
      throw MyException(std::string("DeviceDataBase::getSharedData() - Unable to find reference - ")+key);
   }
   return it->second;
}

ChecksumInfoPtr DeviceDataBase::getChecksumEntry(std::string key) {
   ChecksumInfoPtr ptr(std::tr1::dynamic_pointer_cast<ChecksumInfo>(getSharedData(key)));
   if (ptr == NULL) {
      throw MyException(std::string("DeviceDataBase::getChecksumEntry() - Reference has wrong type - ")+key);
   }
   return ptr;
}

SecurityEntryPtr DeviceDataBase::getSecurityEntry(std::string key) {
   SecurityEntryPtr ptr(std::tr1::dynamic_pointer_cast<SecurityEntry>(getSharedData(key)));
   if (ptr == NULL) {
      throw MyException(std::string("DeviceDataBase::getSecurityEntry() - Reference has wrong type - ")+key);
   }
   return ptr;
}

SecurityDescriptionPtr DeviceDataBase::getSecurityDescription(std::string key) {
   SecurityDescriptionPtr ptr(std::tr1::dynamic_pointer_cast<SecurityDescription>(getSharedData(key)));
   if (ptr == NULL) {
      throw MyException(std::string("DeviceDataBase::getSecurityEntry() - Reference has wrong type - ")+key);
   }
   return ptr;
}

SecurityInfoConstPtr DeviceDataBase::getSecurityInfo(std::string key) const {
   SecurityInfoPtr ptr(std::tr1::dynamic_pointer_cast<SecurityInfo>(getSharedData(key)));
   if (ptr == NULL) {
      throw MyException(std::string("DeviceDataBase::getSecurityEntry() - Reference has wrong type - ")+key);
   }
   return ptr;
}

MemoryRegionPtr DeviceDataBase::getMemoryRegion(std::string key) {
   MemoryRegionPtr ptr(std::tr1::dynamic_pointer_cast<MemoryRegion>(getSharedData(key)));
   if (ptr == NULL) {
      throw MyException(std::string("DeviceDataBase::getSecurityEntry() - Reference has wrong type - ")+key);
   }
   return ptr;
}

TclScriptConstPtr DeviceDataBase::getTclScript(std::string key) const {
   TclScriptPtr ptr(std::tr1::dynamic_pointer_cast<TclScript>(getSharedData(key)));
   if (ptr == NULL) {
      throw MyException(std::string("DeviceDataBase::getSecurityEntry() - Reference has wrong type - ")+key);
   }
   return ptr;
}

RegisterDescriptionConstPtr DeviceDataBase::getRegisterDescription(std::string key) const {
   RegisterDescriptionConstPtr ptr(std::tr1::dynamic_pointer_cast<RegisterDescription>(getSharedData(key)));
   if (ptr == NULL) {
      throw MyException(std::string("DeviceDataBase::getRegisterDescription() - Reference has wrong type - ")+key);
   }
   return ptr;
}

FlashProgramConstPtr DeviceDataBase::getFlashProgram(std::string key) const {
   FlashProgramPtr ptr(std::tr1::dynamic_pointer_cast<FlashProgram>(getSharedData(key)));
   if (ptr == NULL) {
      throw MyException(std::string("DeviceDataBase::getSecurityEntry() - Reference has wrong type - ")+key);
   }
   return ptr;
}

FlexNVMInfoConstPtr DeviceDataBase::getFlexNVMInfo(std::string key) const {
   FlexNVMInfoPtr ptr(std::tr1::dynamic_pointer_cast<FlexNVMInfo>(getSharedData(key)));
   if (ptr == NULL) {
      throw MyException(std::string("DeviceDataBase::getSecurityEntry() - Reference has wrong type - ")+key);
   }
   return ptr;
}

/** Searches the known devices for a device with given name
 *
 * @param targetName - Name of device
 *
 * @returns entry found or NULL if no suitable device found
 *
 * @note - If the device is an alias then it will return the true device
 */
DeviceDataConstPtr DeviceDataBase::findDeviceFromName(const string &targetName) const {
   LOGGING_Q;
   static int recursionCheck = 0;
//   log.print("findDeviceFromName(%s)\n", (const char *)targetName.c_str());

   if (recursionCheck++>5) {
      throw MyException("Recursion limit in DeviceDataBase::findDeviceFromName");
   }
//   // Note - Assumes ASCII string
//   char buff[50];
//   strncpy(buff, targetName.c_str(), sizeof(buff));
//   buff[sizeof(buff)-1] = '\0';
//   strUpper(buff);

   DeviceDataConstPtr theDevice;
   vector<DeviceDataPtr>::const_iterator it;
   for (it = deviceData.begin(); it != deviceData.end(); it++) {
      if (strcasecmp((*it)->getTargetName().c_str(), targetName.c_str()) == 0) {
         theDevice = static_cast<DeviceDataConstPtr>(*it);
//         log.print("findDeviceFromName(%s) found %s%s\n",
//                        (const char *)targetName.c_str(), (const char *)(theDevice->getTargetName().c_str()), theDevice->isAlias()?"(alias)":"");
         if (theDevice->isAlias()) {
            theDevice = findDeviceFromName(theDevice->getAliasName());
         }
         break;
      }
   }
   recursionCheck--;
   if (theDevice == NULL) {
      log.print("findDeviceFromName(%s) => Device not found\n", (const char *)targetName.c_str());
   }
   return theDevice;
}

/** Searches the known devices for a device with given name
 *
 * @param targetName - Name of device
 *
 * @returns index or -1 if not found
 */
int DeviceDataBase::findDeviceIndexFromName(const string &targetName) const {
   LOGGING_Q;

   vector<DeviceDataPtr>::const_iterator it;
   for (it = deviceData.begin(); it != deviceData.end(); it++) {
      if (strcasecmp((*it)->getTargetName().c_str(), targetName.c_str()) == 0) {
         return it - deviceData.begin();
      }
   }
   log.print("findDeviceIndexFromName(%s) => Device not found\n", targetName.c_str());
   return -1;
}

/**
 * \brief Loads the known devices list from the configuration file.
 */
void DeviceDataBase::loadDeviceData() {
   LOGGING_Q;
   string deviceFile;
   try {
      switch(targetType) {
         case T_HCS08 :     deviceFile = DEVICE_DATABASE_DIRECTORY "/hcs08_devices.xml";  break;
         case T_RS08 :      deviceFile = DEVICE_DATABASE_DIRECTORY "/rs08_devices.xml";   break;
         case T_CFV1 :      deviceFile = DEVICE_DATABASE_DIRECTORY "/cfv1_devices.xml";   break;
         case T_HC12 :      deviceFile = DEVICE_DATABASE_DIRECTORY "/hcs12_devices.xml";  break;
         case T_S12Z :      deviceFile = DEVICE_DATABASE_DIRECTORY "/s12z_devices.xml";   break;
         case T_CFVx :      deviceFile = DEVICE_DATABASE_DIRECTORY "/cfvx_devices.xml";   break;
         case T_ARM :
         case T_ARM_SWD :
         case T_ARM_JTAG :  deviceFile = DEVICE_DATABASE_DIRECTORY "/arm_devices.xml";    break;
         case T_MC56F80xx : deviceFile = DEVICE_DATABASE_DIRECTORY "/dsc_devices.xml";    break;
         default:
            log.print("Unknown target type\n");
            throw MyException("DeviceDataBase::loadDeviceData() - illegal target type");
      }
      string deviceFilePath = UsbdmSystem::getResourcePath(deviceFile);
      log.print("Device File = \'%s\'\n", (const char *)deviceFilePath.c_str());
      if (deviceFilePath.empty()) {
         throw MyException("DeviceDataBase::loadDeviceData() - failed to find device database file");
      }
      DeviceXmlParser::loadDeviceData(targetType, deviceFilePath, this);
   }
   catch (MyException &exception) {
      log.print(" - Exception \'%s\'\n", exception.what());
      deviceData.clear();
   }
   catch (...) {
      log.print(" - Unknown exception\n");
      deviceData.clear();
   }
   if ((getDefaultDevice() == NULL) || (deviceData.size() == 0)) {
      // Create dummy default device
      setDefaultDevice(DeviceDataPtr(new DeviceData(targetType, "Database Error")));
      addDevice(getDefaultDevice());
   }
#if defined(LOG) && 0
   listDevices();
#endif
//   log.print(" - %lu devices loaded\n", (unsigned long)deviceData.size());
}

void DeviceDataBase::listDevices() const {
   UsbdmSystem::Log log("", UsbdmSystem::Log::neither);

   vector<DeviceDataPtr>::const_iterator it;
   int lineCount = 0;
   try {
      for (it = deviceData.begin(); it != deviceData.end(); it++) {
         DeviceDataConstPtr deviceData = (*it);
         if (deviceData == NULL) {
            UsbdmSystem::Log::print("Null device pointer\n");
            continue;
         }
         bool aliased = deviceData->isAlias();
         if (aliased) {
            string name = deviceData->getTargetName();
            deviceData = findDeviceFromName(name);
            if (deviceData == NULL) {
               UsbdmSystem::Log::print("%-14s - Failed to find alias\n", name.c_str());
               continue;
            }
            UsbdmSystem::Log::print("%-14s ==> %-14s\n", name.c_str(), deviceData->getTargetName().c_str());
            continue;
         }
         if (lineCount == 0) {
            UsbdmSystem::Log::print("\n");
            UsbdmSystem::Log::print("#                       RAM               Clock   Clock    NVTRIM     Trim                                             \n");
            UsbdmSystem::Log::print("# Target           Start    End           Name    Addr     Addr       Freq. SDIDA    SDIDM    SDID    Scripts? FlashP? \n");
            UsbdmSystem::Log::print("#======================================================================================================================\n");
         }

         UsbdmSystem::Log::print("%-17s %08X %08X %13s %08X %08X %6.2f %08X %08X %08X %4s %4s\n",
               deviceData->getTargetName().c_str(),
               deviceData->getRamStart(), deviceData->getRamEnd(),
               ClockTypes::getClockName(deviceData->getClockType()).c_str(),
               deviceData->getClockAddress(),
               deviceData->getClockTrimNVAddress(),
               deviceData->getClockTrimFreq()/1000.0,
               deviceData->getSDIDAddress(),
               deviceData->getSDID().mask,
               deviceData->getSDID().value,
               deviceData->getFlashScripts()?"Y":"N",
               deviceData->getCommonFlashProgram()?"Y":"N"
         );
#if 0
         for (int regionNum=0; deviceData->getMemoryRegion(regionNum) != NULL; regionNum++) {
            MemoryRegionConstPtr reg=deviceData->getMemoryRegion(regionNum);
            UsbdmSystem::Log::print("      %10s: ", reg->getMemoryTypeName());
            if (reg->getFlashprogram())
               UsbdmSystem::Log::printq("FP=Yes, ");
            else
               UsbdmSystem::Log::printq("        ");
            UsbdmSystem::Log::printq("SS=%6d ", reg->getSectorSize());
            for(unsigned index=0; ; index++) {
  const MemoryRegion::MemoryRange *memoryRange = reg->getMemoryRange(index);
               if (memoryRange == NULL) {
                  break;
               }
               UsbdmSystem::Log::printq("(0x%08X,0x%08X", memoryRange->start, memoryRange->end);
               if ((memoryRange->pageNo != MemoryRegion::DefaultPageNo) &&
                   (memoryRange->pageNo != MemoryRegion::NoPageNo) &&
                   (memoryRange->pageNo != ((memoryRange->start>>16)&0xFF))){
                  UsbdmSystem::Log::printq(",P=0x%02X)", memoryRange->pageNo);
               }
               else {
                  UsbdmSystem::Log::printq(")");
               }
            }
            UsbdmSystem::Log::print("\n");
         }
         UsbdmSystem::Log::print("\n");
#endif
         lineCount = (lineCount+1)%40;
      }
   } catch (...) {

   }
#if 0
   UsbdmSystem::Log::print("================================================\n"
         "Shared data, #elements = %d\n", sharedInformation.size());
   map<const string, SharedInformationItemPtr>::iterator mapIt;
   for (mapIt = sharedInformation.begin(); mapIt != sharedInformation.end(); mapIt++) {
      std::map<const std::string, SharedInformationItem> sharedInformation;
      const string &key   = mapIt->first;
//      const TclScript *item     = dynamic_cast<const TclScript *> (mapIt->second);
      UsbdmSystem::Log::print("key = %s\n", key.c_str());
//      if (item == NULL) {
//         UsbdmSystem::Log::print("Failed cast\n");
//      }
//      else {
//         UsbdmSystem::Log::print("%s", item->toString().c_str());
//      }
   }
   UsbdmSystem::Log::print("================================================\n");
#endif
}

DeviceDataBase::~DeviceDataBase() {
   LOGGING_E;
   sharedInformation.clear();
   deviceData.clear();
}

DeviceData::DeviceData(
         TargetType_t         targetType,
         const std::string   &targetName
           ) : targetType(targetType),
               targetName(targetName),
               aliasName(""),
               hidden(false),
               ramStart(0),
               ramEnd(0),
               clockType(CLKINVALID),
               clockAddress(0),
               clockTrimNVAddress(0),
               clockTrimFreq(0),
               connectionFreqGiven(false),
               connectionFreq(0),
               watchdogAddress(0),
               SDIDAddress(0),
               security(SEC_DEFAULT),
               eraseOption(eraseAll),
               hcs08sbdfrAddress(HCS08_SBDFR_DEFAULT) {

   flexNVMParameters.eeepromSize  = 0xFF;
   flexNVMParameters.partionValue = 0xFF;
}

//=============================================================================================

const string DeviceData::toString() const {
   char buff[100];

   std::stringstream stream;
   stream << "targetName            = " << this->targetName          << endl;
   stream << "SDIDAddress           = " << (snprintf(buff, sizeof(buff), "0x%08X",     this->SDIDAddress),               buff) << endl;
   stream << "clockAddress          = " << (snprintf(buff, sizeof(buff), "0x%08X",     this->clockAddress),              buff) << endl;
   stream << "clockTrimFreq         = " << (snprintf(buff, sizeof(buff), "0x%ld kHz",  this->clockTrimFreq),             buff) << endl;
   stream << "clockDefaultTrimFreq  = " << (snprintf(buff, sizeof(buff), "0x%d kHz",   this->getDefaultClockTrimFreq()), buff) << endl;
   stream << "clockTrimNVAddress    = " << (snprintf(buff, sizeof(buff), "0x%08X",     this->clockTrimNVAddress),        buff) << endl;
//   stream << "clockTrimValue        = " << (snprintf(buff, sizeof(buff), "0x%d",       this->clockTrimValue),            buff) << endl;
   stream << "connectionFreq        = " << (snprintf(buff, sizeof(buff), "0x%ld",      this->connectionFreq),            buff) << endl;
   stream << "security              = " << getSecurityName(this->security)                                                     << endl;
   stream << "clockType             = " << this->clockType                                                                     << endl;
   stream << "eraseOption           = " << this->eraseOption                                                                   << endl;

   for(int index = 0;;index++) {
      MemoryRegionConstPtr memoryRegionPtr = getMemoryRegion(index);
      if (memoryRegionPtr == NULL) {
         // Finished
         break;
      }
      SecurityEntryConstPtr securityEntry = memoryRegionPtr->getSecurityEntry();
      if (securityEntry != NULL) {
         stream << "memory type           = " << memoryRegionPtr->getMemoryTypeName() << endl;
         stream << securityEntry->toString().c_str() << endl;
      }
   }
   return stream.str();
}
