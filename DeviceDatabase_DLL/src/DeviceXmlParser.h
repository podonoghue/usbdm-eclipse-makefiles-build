/*
 * xmlParser.h
 *
 *  Created on: 22/12/2010
 *      Author: podonoghue
 */

#ifndef XMLPARSER_H_
#define XMLPARSER_H_

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <string>

#include "DualString.h"
#include "DeviceData.h"

class DeviceXmlParser {

private:
   TargetType_t targetType;

   DualString   tag_deviceList;
   DualString   tag_device;
   DualString   tag_clock;
   DualString   tag_memory;
   DualString   tag_memoryRef;
   DualString   tag_memoryRange;
   DualString   tag_sdid;
   DualString   tag_sdidMask;
   DualString   tag_sdidAddress;
   DualString   tag_soptAddress;
   DualString   tag_securityAddress; // NVOPT, NVSEC
   DualString   tag_copctlAddress;
   DualString   tag_note;
   DualString   tag_tclScriptRef;
   DualString   tag_sharedInformation;
   DualString   tag_tclScript;
   DualString   tag_preSequence;
   DualString   tag_postSequence;
   DualString   tag_flashScripts;
   DualString   tag_flashProgram;
   DualString   tag_flashProgramRef;
   DualString   tag_securityEntry;
   DualString   tag_securityEntryRef;
   DualString   tag_securityDescription;
   DualString   tag_securityDescriptionRef;
   DualString   tag_securityInfo;
   DualString   tag_securityInfoRef;
   DualString   tag_flexNvmInfo;
   DualString   tag_flexNvmInfoRef;
   DualString   tag_eeepromEntry;
   DualString   tag_partitionEntry;
   DualString   tag_projectActionList;
   DualString   tag_projectActionListRef;
   DualString   tag_registerDescription;
   DualString   tag_registerDescriptionRef;

   DualString   attr_name;
   DualString   attr_isDefault;
   DualString   attr_alias;
   DualString   attr_hidden;
   DualString   attr_family;
   DualString   attr_subFamily;
   DualString   attr_speed;
   DualString   attr_type;
   DualString   attr_subType;
   DualString   attr_start;
   DualString   attr_middle;
   DualString   attr_end;
   DualString   attr_size;
   DualString   attr_pageNo;
   DualString   attr_pageStart;
   DualString   attr_pageEnd;
   DualString   attr_pageReset;
   DualString   attr_pages;
   DualString   attr_pageAddress;
   DualString   attr_registerAddress;
   DualString   attr_securityAddress;
   DualString   attr_sectorSize;
   DualString   attr_value;
   DualString   attr_id;
   DualString   attr_ref;
   DualString   attr_addressMode;
   DualString   attr_description;
   DualString   attr_eeeSize;
   DualString   attr_eeSize;
   DualString   attr_alignment;
   DualString   attr_path;
   DualString   attr_count;
   DualString   attr_mask;

   static char  currentDeviceName[100];

   bool         isDefault; // Indicates that the current device is the default device

   DeviceDataBase *deviceDataBase;

   xercesc::XercesDOMParser* parser;
   xercesc::ErrorHandler*    errHandler;
   xercesc::DOMDocument*     document;

private:
   RegisterDescriptionPtr             parseRegisterDescription(xercesc::DOMElement *xmlRegisterDescription);
   TclScriptPtr                       parseTCLScript(xercesc::DOMElement *xmlTclScript);
   FlashProgramPtr                    parseFlashProgram(xercesc::DOMElement *xmlFlashProgram);
   void                               parseSharedXML(void);
   void                               parseDeviceXML(void);
   DeviceDataPtr                      parseDevice(xercesc::DOMElement *deviceEl);
   DeviceDataPtr                      parseAlias(xercesc::DOMElement *deviceEl);
   TclScriptConstPtr                  parseSequence(xercesc::DOMElement *sequence);
   MemoryRegionPtr                    parseMemory(xercesc::DOMElement *currentProperty);
   MemoryRegionPtr                    parseFlashMemoryDetails(xercesc::DOMElement *currentProperty, MemType_t memoryType, uint32_t &defaultSectorSize, uint8_t &defaultAlignment);
   SecurityEntryPtr                   parseSecurityEntry(xercesc::DOMElement *currentProperty);
   SecurityDescriptionPtr             parseSecurityDescription(xercesc::DOMElement *currentProperty);
   SecurityInfoPtr                    parseSecurityInfo(xercesc::DOMElement *currentProperty);
   //   void  parseActionSequence(xercesc::DOMElement *sharedRoot, std::map<const string, SharedInformationItem> &shareInformation);
   FlexNVMInfoPtr                     parseFlexNVMInfo(xercesc::DOMElement *flexNVMInfoElement);
   FlexNVMInfo::EeepromSizeValue      parseEeepromEntry(xercesc::DOMElement *eeepromElement);
   FlexNVMInfo::FlexNvmPartitionValue parsePartitionEntry(xercesc::DOMElement *partitionElement);
//   GnuInfoPtr                         parseGnuInfo(xercesc::DOMElement *currentProperty);
//   GnuInfoListPtr                     parseGnuInfoList(xercesc::DOMElement *currentProperty);

   void          loadFile(const std::string &xmlFile);

   DeviceXmlParser(TargetType_t targetType, DeviceDataBase *deviceDataBase);
   void setCurrentName(const char *name);

public:
   static void loadDeviceData(TargetType_t targetType, const std::string &deviceFilePath, DeviceDataBase *deviceDataBase);
   ~DeviceXmlParser(void);
};

#endif /* XMLPARSER_H_ */
