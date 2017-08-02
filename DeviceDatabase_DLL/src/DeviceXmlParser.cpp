/*! \file
    \brief Parses device XML files

    DeviceXmlParser.cpp

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
   -=============================================================================================
   | 20 Jan 2015 | Added <sbdfrAddress> parsing etc.                            - pgo 4.12.1.10
   |  1 Dec 2014 | Fixed format in printf()s                                    - pgo 4.10.6.230
   | 12 Jul 2014 | Added getCommonFlashProgram(), changed getFlashProgram() etc - pgo V4.10.6.170
   | 12 Jul 2014 | Changed alias handling to be better defined                  - pgo 4.10.6.170
   |    Jan 2014 | Added <projectActions> and removed obsolete elements         - pgo 4.10.6
   |  6 Jul 2013 | Added Register description parsing                           - pgo 4.10.6
   |        2013 | Added GNU information parsing (incomplete)                   - pgo 4.10.4?
   |  6 Oct 2012 | Fixed default SDID etc                                       - pgo 4.10.2
   |    Aug 2011 | Added I/O memory type                                        - pgo
   |    Aug 2011 | Removed Boost                                                - pgo
   |    Apr 2011 | Added TCL scripts etc                                        - pgo
   +=============================================================================================
   \endverbatim
*/

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <typeinfo>
#include <string>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include <map>
#include <memory>

#pragma GCC visibility push(default)

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/sax/HandlerBase.hpp>

#pragma GCC visibility pop

using namespace std;

XERCES_CPP_NAMESPACE_USE

#include "Common.h"
#include "DeviceXmlParser.h"
#include "DeviceData.h"
#include "Names.h"

#include "UsbdmSystem.h"
#include "Utils.h"

char DeviceXmlParser::currentDeviceName[] = "Doing preamble";

static void strUpper(char *s) {
   if (s == NULL) {
      return;
   }
   while (*s != '\0') {
      int ch = ::toupper(*s);
      *s++ = ch;
   }
}

void DeviceXmlParser::setCurrentName(const char *name) {
   strncpy(currentDeviceName, name, sizeof(currentDeviceName));
   currentDeviceName[sizeof(currentDeviceName)-1] = '\0';
   strUpper(currentDeviceName);
}

#if 0
//! Convert a single digit to an integer
//!
//! @param s    - character to convert
//! @param base - base to use - either 8, 10 or 16
//!
//! @return <0  => invalid digit
//!         >=0 => converted digit
//!
uint8_t getDigit(char s, int base) {
   int digit = s-'0';
   if ((s>=0) && (s<=base)) {
      return digit;
   }
   if (base <= 10) {
      return -1;
   }
   digit -= 10;
   if ((s>=0) && (s<=base)) {
      return digit;
   }
   return -1;
}

//! Convert string to long integer
//!
//! @param start = ptr to string to convert
//! @param end   = updated to point to char following valid string (may be NULL)
//! @param value = value read
//!
//! @return true  => OK \n
//!         false => failed
//!
//! @note Accepts decimal, octal with '0' prefix or hex with '0x' prefix \n
//!                        '_' may be used to space number e.g. 0x1000_0000
//!
bool strToULong(const char *s, char **end, long *returnValue) {
   uint32_t value = 0;
   int base = 10;
   *returnValue = 0;
   while (isspace(*s)) {
      s++;
   }
   if (*s == '_') {
      // Don't allow '_' as first character of number
      return false;
   }
   if (*s == '0') {
      s++;
      base = 8;
      if ((s=='x')||(s=='X')) {
         s++;
         base = 16;
      }
   }
   char *startOfNum = s;
   do {
      if (*s == '_') {
         // Ignore '_'
         continue;
      }
      int digit = getDigit(*s);
      if (digit < 0) {
         break;
      }
      s++;
      value = base*value + digit;
   } while (1);
   if (startOfNum == s) {
      // No digits
      return false;
   }
   if (end != NULL) {
      // Record end of number (immediately following character)
      end = s;
   }
   else {
      // If end is not used then check if at end of string
      // Skip trailing spaces
      while (isspace(*end_t)) {
         end_t++;
      }
      if (*end_t != '\0') {
         UsbdmSystem::Log::print("strToULong() - Unexpected chars following number (%s)\n", start);
         return false;
      }
   }
   // if accepted chars its a valid number
   return true;
}
#else
//! Convert string to long integer
//!
//! @param start = ptr to string to convert
//! @param end   = updated to point to char following valid string (may be NULL)
//! @param value = value read
//!
//! @return true => OK \n
//!         false => failed
//!
//! @note Accepts decimal, octal with '0' prefix or hex with '0x' prefix
//!
bool strToULong(const char *start, char **end, long *value) {
   char *end_t;
   long scaleFactor = 1;
   long bias        = 0;

//   while (isspace(*start)) {
//      start++;
//   }
   if (strncasecmp(start, "w:", 2) == 0) {
      scaleFactor  = 2;
      start       += 2;
      bias         = *value;
      *value       = 0;
   }
   errno = 0;
   unsigned long value_t = strtoul(start, &end_t, 0);

//   log.print("strToULong() - s=\'%s\', e='%s', val=%ld(0x%lX)\n", start, end_t, value_t, value_t);
   if (errno != 0) { // no String found
      UsbdmSystem::Log::error("strToULong() - errno != 0 - No number found\n");
      return false;
   }
   if (end_t == start) { // no String found
      UsbdmSystem::Log::error("strToULong() - end_t == start - No number found\n");
      return false;
   }
   if ((ULONG_MAX == value_t) && (ERANGE == errno)) { // too large
      UsbdmSystem::Log::error("strToULong() - Number too large\n");
     return false;
   }
   if (end != NULL) {
      *end = end_t;
   }
   else {
      // If end is not used then check if at end of string
      // Skip trailing spaces
      while (isspace(*end_t)) {
         end_t++;
      }
      if (*end_t != '\0') {
         UsbdmSystem::Log::error("strToULong() - Unexpected chars following number (%s)\n", start);
         return false;
      }
   }
   *value = value_t*scaleFactor + bias;
   return true;
}
#endif

//! Convert string to long integer.
//!
//! @param start = ptr to string to convert
//! @param end   = updated to point to char following valid string (may be NULL)
//! @param value = value read
//!
//! @return true => OK \n
//!         false => failed
//!
//! @note Accepts decimal, octal with '0' prefix or hex with '0x' prefix
//! @note Value may have K or M suffix to indicate kilobytes(2^10) or megabytes(2^20) \n
//!       e.g. '1M' '0x1000 K' etc
//!
bool strSizeToULong(const char *start, char **end, long *value) {
   char *end_t;
   long scaleFactor = 1;
   if (strncasecmp(start, "w:", 2) == 0) {
      scaleFactor  = 2;
      start       += 2;
   }
   bool success = strToULong(start, &end_t, value);
   if (!success) {
      return false;
   }
   if (end != NULL) {
      *end = end_t;
   }
   // Skip trailing spaces
   while (isspace(*end_t)) {
      end_t++;
   }
   if ((*end_t == 'k') || (*end_t == 'K')) {
      *value <<= 10;
      ++end_t;
      if (end != NULL)
         *end = end_t;
   }
   if ((*end_t == 'm') || (*end_t == 'M')) {
      *value <<= 20;
      ++end_t;
      if (end != NULL)
         *end = end_t;
   }
   if (end == NULL) {
      // If end is not used then check if at end of string
      // Skip trailing spaces
      while (isspace(*end_t)) {
         end_t++;
      }
      if (*end_t != '\0') {
         UsbdmSystem::Log::print("strToULong() - Unexpected chars following number\n");
         return false;
      }
   }
   *value *= scaleFactor;
   return true;
}

//! Simple utility class for traversing XML document
//!
class DOMChildIterator {

private:
   DOMNodeList *elementList;
   int          index;
   DOMElement  *currentElement;

public:
   /**
    * Iterator for child nodes of document having the given tag name
    */
   DOMChildIterator(DOMDocument *document, const char *tagName) {
      elementList    = document->getElementsByTagName(DualString(tagName).asXMLString());
      index          = 0;
      findElement(0);
   };

   /**
    * Iterator for child nodes of element
    */
   DOMChildIterator(DOMElement *element) {
      elementList    = element->getChildNodes();
      index          = 0;
      findElement(0);
   };

   /**
    * Iterator for child nodes of element having the given tag name
    */
   DOMChildIterator(DOMElement *element, const char *tagName) {
      elementList    = element->getElementsByTagName(DualString(tagName).asXMLString());
      index          = 0;
      findElement(0);
   };

private:
   void findElement(unsigned index) {
      currentElement = NULL;
      while ((elementList != NULL) && (index < elementList->getLength())) {
         DOMNode *node = elementList->item(index);
         if (node == NULL) {
            // Should be impossible
            throw MyException("DOMChildIterator::findElement() - elementList->item(i) failed");
         }
//         log.print("DOMChildIterator::setIndex() examining <%s> node\n", DualString(node->getNodeName()).asCString());
         if (node->getNodeType() == DOMNode::ELEMENT_NODE) {
//            log.print("DOMChildIterator::findElement() Element node type (from)  = %s\n", typeid(node).name());
//            log.print("DOMChildIterator::findElement() Element node type (to)    = %s\n", typeid(DOMElement *).name());
//            DOMElement *el = dynamic_cast< DOMElement* >( node );
            DOMElement *el = static_cast< DOMElement* >( node );
//            if (el == NULL) {
//               // Should be impossible
//               throw MyException("DOMChildIterator::findElement() - casting failed");
//            }
//            log.print("DOMChildIterator::findElement() Element node type (after) = %s\n", typeid(el).name());
            currentElement = el;
            this->index = index;
            break;
         }
//         else {
//            log.print("DOMChildIterator::findElement() Non-element node type = %s\n", typeid(node).name());
//         }
         index++;
      }
   }

public:
   DOMElement *getCurrentElement() {
      return currentElement;
   }

public:
   DOMElement *advanceElement() {
      findElement(index+1);
      return currentElement;
   }
};

//! XML parser for device files
//!
DeviceXmlParser::DeviceXmlParser(TargetType_t targetType, DeviceDataBase *deviceDataBase)
   :
   targetType(targetType),
   tag_deviceList("deviceList"),
   tag_device("device"),
   tag_eraseMethod("eraseMethod"),
   tag_eraseMethodRef("eraseMethodRef"),
   tag_eraseMethods("eraseMethods"),
   tag_eraseMethodsRef("eraseMethodsRef"),
   tag_clock("clock"),
   tag_memory("memory"),
   tag_memoryRef("memoryRef"),
   tag_memoryRange("memoryRange"),
   tag_sdid("sdid"),
   tag_sdidMask("sdidMask"),
   tag_sbdfrAddress("sbdfrAddress"),
   tag_sdidAddress("sdidAddress"),
   tag_soptAddress("soptAddress"),
   tag_securityAddress("securityAddress"),
   tag_copctlAddress("copctlAddress"),
   tag_note("note"),
   tag_tclScriptRef("tclScriptRef"),
   tag_sharedInformation("sharedInformation"),
   tag_tclScript("tclScript"),
   tag_preSequence("preSequence"),
   tag_postSequence("postSequence"),
   tag_flashScripts("flashScripts"),
   tag_flashProgram("flashProgram"),
   tag_flashProgramRef("flashProgramRef"),
   tag_securityEntry("securityEntry"),
   tag_securityEntryRef("securityEntryRef"),
   tag_securityDescription("securityDescription"),
   tag_securityDescriptionRef("securityDescriptionRef"),
   tag_securityInfo("securityInfo"),
   tag_securityInfoRef("securityInfoRef"),
   tag_checksumEntry("checksumEntry"),
   tag_checksumEntryRef("checksumEntryRef"),
   tag_flexNvmInfo("flexNVMInfo"),
   tag_flexNvmInfoRef("flexNVMInfoRef"),
   tag_eeepromEntry("eeepromEntry"),
   tag_partitionEntry("partitionEntry"),
   tag_projectActionList("projectActionList"),
   tag_projectActionListRef("projectActionListRef"),
   tag_registerDescription("registerDescription"),
   tag_registerDescriptionRef("registerDescriptionRef"),
   tag_resetMethod("resetMethod"),
   tag_resetMethodRef("resetMethodRef"),
   tag_resetMethods("resetMethods"),
   tag_resetMethodsRef("resetMethodsRef"),

   attr_name("name"),
   attr_isDefault("isDefault"),
   attr_alias("alias"),
   attr_hidden("hidden"),
   attr_family("family"),
   attr_subFamily("subFamily"),
   attr_speed("speed"),
   attr_type("type"),
   attr_subType("subType"),
   attr_start("start"),
   attr_middle("middle"),
   attr_end("end"),
   attr_location("location"),
   attr_size("size"),
   attr_pageNo("pageNo"),
   attr_pageStart("pageStart"),
   attr_pageEnd("pageEnd"),
   attr_pageReset("pageReset"),
   attr_pages("pages"),
   attr_pageAddress("pageAddress"),
   attr_registerAddress("registerAddress"),
   attr_securityAddress("securityAddress"),
   attr_sectorSize("sectorSize"),
   attr_value("value"),
   attr_id("id"),
   attr_ref("ref"),
   attr_addressMode("addressMode"),
   attr_description("description"),
   attr_eeeSize("eeeSize"),
   attr_eeSize("eeSize"),
   attr_alignment("alignment"),
   attr_path("path"),
   attr_count("count"),
   attr_mask("mask"),
   attr_method("method"),

   isDefault(false),
   deviceDataBase(deviceDataBase),

   parser(NULL),
   errHandler(NULL),
   document(NULL) {
//   log.print("DeviceXmlParser::DeviceXmlParser()\n");
}

DeviceXmlParser::~DeviceXmlParser() {
   // Don't delete document as owned by parser!
//   log.print("DeviceXmlParser::~DeviceXmlParser()\n");
   delete parser;
   delete errHandler;
}

//! Load a device XML file as xerces document
//!
//! @param xmlFile - Device XML file to load
//!
//! @throws MyException() - on any error
//!
void DeviceXmlParser::loadFile(const string &xmlFile) {
   LOGGING;

   // Convert simple path to crude URI
   char fixedName[xmlFile.size()+100] = "file:///";
   char *cp = fixedName + strlen(fixedName);
   for (unsigned index=0; index<xmlFile.size(); index++) {
      if (xmlFile[index] == ' ') {
         *cp++ = '%';
         *cp++ = '2';
         *cp++ = '0';
      }
      else if (xmlFile[index] == '\\') {
         *cp++ = '/';
      }
      else {
         *cp++ = xmlFile[index];
      }
   }
   *cp++ = '\0';

   parser = new XercesDOMParser();
   parser->setDoNamespaces( true );
   parser->setDoSchema( false ) ;
   parser->setLoadExternalDTD( false ) ;
   parser->setValidationScheme(XercesDOMParser::Val_Auto);
   parser->setValidationSchemaFullChecking(false);
   parser->setDoXInclude(true);

   log.print("Path = \'%s\'\n", fixedName);
   try {
//      log.print("#1\n");
      errHandler = new HandlerBase();
//      log.print("#2\n");
      parser->setErrorHandler(errHandler);
//      log.print("#3\n");
      parser->parse(fixedName);
//      log.print("#4\n");
      document = parser->getDocument();
//      log.print("#5\n");
   }
   catch (SAXException const &e) {
      DualString s(e.getMessage());
      log.error("SAXException:%s\n", s.asCString());
   }
   catch (XMLException const &e) {
      DualString s(e.getMessage());
      log.error("XMLException:%s\n", s.asCString());
   }
   catch (DOMException const &e) {
      DualString s(e.getMessage());
      log.error("DOMException:%s\n", s.asCString());
   }
   catch (...) {
      log.error("Unknown XERCES-C error");
   }
   if (document == NULL) {
      throw MyException("- Unable to create document or load/parse file");
   }
}

// Create a TCL script from XML element
TclScriptPtr DeviceXmlParser::parseTCLScript(DOMElement *xmlTclScript) {
   LOGGING;
   // Type of node (must be a TCL script)
   DualString sTag (xmlTclScript->getTagName());
   if (!XMLString::equals(sTag.asXMLString(), tag_tclScript.asXMLString())) {
      throw MyException(string(" Unexpected tag = ")+sTag.asCString());
   }
   DualString text(xmlTclScript->getTextContent());
   TclScriptPtr tclScriptPtr(new TclScript(text.asCString()));
   if (xmlTclScript->hasAttribute(attr_id.asXMLString())) {
      DualString sId(xmlTclScript->getAttribute(attr_id.asXMLString()));
      deviceDataBase->addSharedData(string(sId.asCString()), tclScriptPtr);
//      log.print("Inserted shared TclScript item ID=%s\n", sId.asCString());
   }
   return tclScriptPtr;
}

// Create a Register description from an XML element
RegisterDescriptionPtr DeviceXmlParser::parseRegisterDescription(DOMElement *xmlRegisterDescription) {
   LOGGING;

   // Type of node (must be a RegisterDescription node)
   DualString sTag (xmlRegisterDescription->getTagName());
   if (!XMLString::equals(sTag.asXMLString(), tag_registerDescription.asXMLString())) {
      throw MyException(string("Unexpected tag = ")+sTag.asCString());
   }

   long count = 0;
   DualString sCount(xmlRegisterDescription->getAttribute(attr_count.asXMLString()));
   if (!strToULong(sCount.asCString(), NULL, &count)) {
      throw MyException(string("Illegal register count = ")+sCount.asCString());
   }

   if (count == 0) {
      // Discard empty set
      return RegisterDescriptionPtr();
   }
   DualString text(xmlRegisterDescription->getTextContent());

   RegisterDescriptionPtr registerDescriptionPtr(new RegisterDescription(text.asCString(), count-1));

   if (xmlRegisterDescription->hasAttribute(attr_id.asXMLString())) {
      DualString sId(xmlRegisterDescription->getAttribute(attr_id.asXMLString()));
      deviceDataBase->addSharedData(string(sId.asCString()), registerDescriptionPtr);
//      log.print("Inserted shared RegisterDescription item ID=%s\n", sId.asCString());
   }
   return registerDescriptionPtr;
}

//! Create a flashProgram from XML element
//!
FlashProgramPtr DeviceXmlParser::parseFlashProgram(DOMElement *xmlFlashProgram) {
   LOGGING;

   // Type of node (must be a flashProgram)
   DualString sTag (xmlFlashProgram->getTagName());
   if (!XMLString::equals(sTag.asXMLString(), tag_flashProgram.asXMLString())) {
      throw MyException(string("Unexpected tag = ")+sTag.asCString());
   }
   DualString text(xmlFlashProgram->getTextContent());
   FlashProgramPtr flashProgramPtr(new FlashProgram(text.asCString()));
   if (xmlFlashProgram->hasAttribute(attr_id.asXMLString())) {
      DualString sId(xmlFlashProgram->getAttribute(attr_id.asXMLString()));
      deviceDataBase->addSharedData(string(sId.asCString()), flashProgramPtr);
//      log.print("Inserted shared FlashProgram item ID=%s\n", sId.asCString());
   }
   return flashProgramPtr;
}

//! Create security information from node
//!
ChecksumInfoPtr DeviceXmlParser::parseChecksumInfo(DOMElement *currentProperty) {
   LOGGING;

   // Type of node (must be a flashProgram)
   DualString sTag (currentProperty->getTagName());
   if (!XMLString::equals(sTag.asXMLString(), tag_checksumEntry.asXMLString())) {
      throw MyException(string("DeviceXmlParser::parseSecurityInfo() - Unexpected tag = ")+sTag.asCString());
   }
   ChecksumInfo::ChecksumType type;
   DualString sType(currentProperty->getAttribute(attr_type.asXMLString()));
   if (strcmp(sType.asCString(), "twoComplementWordSum")==0) {
      type = ChecksumInfo::ChecksumType::twoComplementByteSum;
   }
   else {
      throw MyException(string("DeviceXmlParser::parseChecksumInfo() - Illegal type in checksumEntry = ")+sType.asCString());
   }
   DualString sStartAddress(currentProperty->getAttribute(attr_start.asXMLString()));
   DualString sEndAddress(currentProperty->getAttribute(attr_end.asXMLString()));
   DualString sLocationAddress(currentProperty->getAttribute(attr_location.asXMLString()));

   long startAddress, endAddress, locationAddress;

   if (!strToULong(sStartAddress.asCString(),    NULL, &startAddress) ||
       !strToULong(sEndAddress.asCString(),      NULL, &endAddress) ||
       !strToULong(sLocationAddress.asCString(), NULL, &locationAddress)) {
      throw MyException("DeviceXmlParser::parseFlashMemoryDetails() - Illegal start/end/location field in checksumEntry");
   }

   ChecksumInfoPtr checksumInfoPtr(new ChecksumInfo(startAddress, endAddress, locationAddress, type));
   log.print("DeviceXmlParser::parseChecksumInfo(): %s\n", (const char *)checksumInfoPtr->toString().c_str());

   if (currentProperty->hasAttribute(attr_id.asXMLString())) {
      DualString sId(currentProperty->getAttribute(attr_id.asXMLString()));
      deviceDataBase->addSharedData(string(sId.asCString()), checksumInfoPtr);
//      log.print("DeviceXmlParser::parseSecurityInfo(): Inserted shared SecurityInfo item ID=%s\n", sId.asCString());
   }
   return checksumInfoPtr;
}

//! Create security information from node
//!
SecurityInfoPtr DeviceXmlParser::parseSecurityInfo(DOMElement *currentProperty) {
   LOGGING;

   // Type of node (must be a flashProgram)
   DualString sTag (currentProperty->getTagName());
   if (!XMLString::equals(sTag.asXMLString(), tag_securityInfo.asXMLString())) {
      throw MyException(string("DeviceXmlParser::parseSecurityInfo() - Unexpected tag = ")+sTag.asCString());
   }
   long size = 0;
   DualString sSize(currentProperty->getAttribute(attr_size.asXMLString()));
   if (!strToULong(sSize.asCString(), NULL, &size)) {
      throw MyException(string("DeviceXmlParser::parseSecurityInfo() - Illegal size in securityInfo = ")+sSize.asCString());
   }
   SecurityInfo::SecType type;
   DualString sType(currentProperty->getAttribute(attr_type.asXMLString()));
   if (strcmp(sType.asCString(), "unsecure")==0) {
      type = SecurityInfo::unsecure;
   }
   else if (strcmp(sType.asCString(), "secure")==0) {
      type = SecurityInfo::secure;
   }
   else if (strcmp(sType.asCString(), "custom")==0) {
      type = SecurityInfo::custom;
   }
   else {
      throw MyException(string("DeviceXmlParser::parseSecurityInfo() - Illegal type in securityInfo = ")+sType.asCString());
   }
   DualString text(currentProperty->getTextContent());
   SecurityInfoPtr securityInfoPtr(new SecurityInfo(size, type, filter(text.asCString(), "0123456789abcdefABCDEF")));
//   log.print("DeviceXmlParser::parseSecurityInfo():\n");
//   log.print(securityInfo->toString().c_str());
   if (currentProperty->hasAttribute(attr_id.asXMLString())) {
      DualString sId(currentProperty->getAttribute(attr_id.asXMLString()));
      deviceDataBase->addSharedData(string(sId.asCString()), securityInfoPtr);
//      log.print("DeviceXmlParser::parseSecurityInfo(): Inserted shared SecurityInfo item ID=%s\n", sId.asCString());
   }
   return securityInfoPtr;
}

//! Create security element from node
//!<securityEntry id="Kinetis-default-security">
//!   <securityDescription>
//!      ...
//!   </securityDescription>
//!   <securityInfo size="16" type="off" id="Kinetis-security-off">
//!      ...
//!   </securityInfo>
//!   <securityInfo size="16" type="on" id="Kinetis-security-on">
//!      ...
//!   </securityInfo>
//!</securityEntry>
SecurityEntryPtr DeviceXmlParser::parseSecurityEntry(DOMElement *currentProperty) {
   LOGGING;

   // Type of node (must be a flashProgram)
   DualString sTag (currentProperty->getTagName());
   if (!XMLString::equals(sTag.asXMLString(), tag_securityEntry.asXMLString())) {
      throw MyException(string("DeviceXmlParser::parseSecurityEntry() - Unexpected tag = ")+sTag.asCString());
   }
   // Iterator for the contents of <sharedInformation> section
   // Each is a shared element
   DOMChildIterator securityEntryChildIt(currentProperty);

   SecurityDescriptionPtr securityDescriptionPtr;
   SecurityInfoPtr        secureInfoPtr;
   SecurityInfoPtr        unsecureInfoPtr;
   SecurityInfoPtr        customSecureInfoPtr;
   // Process each element of <securityEntry>
   for (;
         securityEntryChildIt.getCurrentElement() != NULL;
         securityEntryChildIt.advanceElement()) {
      // Handle to <sharedInformation> element
      DOMElement *securityEntryChild = securityEntryChildIt.getCurrentElement();
      // Type of element
      DualString sTag (securityEntryChild->getTagName());
      if (XMLString::equals(sTag.asXMLString(), tag_securityDescription.asXMLString())) {
         // Parse <securityDescription>
         securityDescriptionPtr = parseSecurityDescription(securityEntryChild);
      }
      else if (XMLString::equals(sTag.asXMLString(), tag_securityInfo.asXMLString())) {
         // Parse <securityInfoPtr>
         SecurityInfoPtr securityInfoPtr = parseSecurityInfo(securityEntryChild);
         if (securityInfoPtr->getMode() == SecurityInfo::secure) {
            secureInfoPtr = securityInfoPtr;
         }
         else if (securityInfoPtr->getMode() == SecurityInfo::unsecure) {
            unsecureInfoPtr = securityInfoPtr;
         }
         else {
            customSecureInfoPtr = securityInfoPtr;
         }
      }
      else {
         throw MyException(string("DeviceXmlParser::parseSecurityEntry() - Unexpected Tag = ")+sTag.asCString());
      }
   }
   SecurityEntryPtr securityEntryPtr(new SecurityEntry(securityDescriptionPtr,unsecureInfoPtr,secureInfoPtr));
   if (customSecureInfoPtr != NULL) {
      securityEntryPtr->setCustomSecureInformation(customSecureInfoPtr);
   }
   if (currentProperty->hasAttribute(attr_id.asXMLString())) {
      // ID for element - this allows the element to be accessed as shared data
      DualString sId(currentProperty->getAttribute(attr_id.asXMLString()));
      deviceDataBase->addSharedData(string(sId.asCString()), securityEntryPtr);
//      log.print("Inserted shared SecurityEntry item ID=%s\n", sId.asCString());
   }
   return securityEntryPtr;
}

//! Create security information from node
//!
SecurityDescriptionPtr DeviceXmlParser::parseSecurityDescription(DOMElement *currentProperty) {
   LOGGING;

//   LOGGING;
   // Type of node (must be a flashProgram)
   DualString sTag (currentProperty->getTagName());
   if (!XMLString::equals(sTag.asXMLString(), tag_securityDescription.asXMLString())) {
      throw MyException(string("DeviceXmlParser::parseSecurityDescription() - Unexpected tag = ")+sTag.asCString());
   }
   DualString text(currentProperty->getTextContent());
   // Discard leading white space
   const char *p = text.asCString();
   while ((*p == ' ')||(*p == '\t')||(*p == '\n')||(*p == '\r')) {
      p++;
   }
   SecurityDescriptionPtr securityDescriptionPtr(new SecurityDescription(p));
//   log.print(securityDescriptionPtr->toString().c_str());
   // ID for element - this allows the element to be accessed as shared data
   if (currentProperty->hasAttribute(attr_id.asXMLString())) {
      DualString sId(currentProperty->getAttribute(attr_id.asXMLString()));
      deviceDataBase->addSharedData(string(sId.asCString()), securityDescriptionPtr);
//      log.print("DeviceXmlParser::parseSecurityEntry(): Inserted shared SecurityDescription item ID=%s\n", sId.asCString());
   }
   return securityDescriptionPtr;
}

//! Create shared elements from document
//!
void DeviceXmlParser::parseSharedXML(void) {
   LOGGING;

   setCurrentName("Shared Data");

   // Iterator for all the <sharedInformation> sections
   DOMChildIterator sharedIt(document, tag_sharedInformation.asCString());
   // Process each <sharedInformation> section (usually only one)
   for (;
         sharedIt.getCurrentElement() != NULL;
         sharedIt.advanceElement()) {
      // Point to <sharedInformation> section
      DOMElement *shareInformationIt(sharedIt.getCurrentElement());

      // Iterator for the contents of <sharedInformation> section
      // Each is a shared element
      DOMChildIterator sharedInformationElementIt(shareInformationIt);
      // Process each element of <sharedInformation>
      for (;
            sharedInformationElementIt.getCurrentElement() != NULL;
            sharedInformationElementIt.advanceElement()) {
         // Handle to <sharedInformation> element
         DOMElement *sharedInformationElement = sharedInformationElementIt.getCurrentElement();
         // ID for element - this allows the element to be accessed
         if (!sharedInformationElement->hasAttribute(attr_id.asXMLString())) {
            throw MyException(string("DeviceXmlParser::parseSharedXML() - Shared data requires ID attribute"));
         }
         DualString sId(sharedInformationElement->getAttribute(attr_id.asXMLString()));
         // Type of element
         DualString sTag (sharedInformationElement->getTagName());
         if (XMLString::equals(sTag.asXMLString(), tag_tclScript.asXMLString())) {
            // Parse <tclScript>
            parseTCLScript(sharedInformationElement);
         }
         else if (XMLString::equals(sTag.asXMLString(), tag_registerDescription.asXMLString())) {
            // Parse <registerDescription>
            parseRegisterDescription(sharedInformationElement);
         }
         else if (XMLString::equals(sTag.asXMLString(), tag_flashProgram.asXMLString())) {
            // Parse <flashProgram>
            parseFlashProgram(sharedInformationElement);
         }
         else if (XMLString::equals(sTag.asXMLString(), tag_securityEntry.asXMLString())) {
            // Parse <securityEntry>
            parseSecurityEntry(sharedInformationElement);
         }
         else if (XMLString::equals(sTag.asXMLString(), tag_securityDescription.asXMLString())) {
            // Parse <securityDescription>
            parseSecurityDescription(sharedInformationElement);
         }
         else if (XMLString::equals(sTag.asXMLString(), tag_securityInfo.asXMLString())) {
            // Parse <securityInfo>
            parseSecurityInfo(sharedInformationElement);
         }
         else if (XMLString::equals(sTag.asXMLString(), tag_checksumEntry.asXMLString())) {
            // Parse <securityInfo>
            parseChecksumInfo(sharedInformationElement);
         }
         else if (XMLString::equals(sTag.asXMLString(), tag_flexNvmInfo.asXMLString())) {
            // Parse <flexNVMInfo>
            deviceDataBase->addSharedData(string(sId.asCString()), parseFlexNVMInfo(sharedInformationElement));
         }
         else if (XMLString::equals(sTag.asXMLString(), tag_memory.asXMLString())) {
            // Parse <memory>
            deviceDataBase->addSharedData(string(sId.asCString()), parseMemory(sharedInformationElement));
         }
         else if (XMLString::equals(sTag.asXMLString(), tag_resetMethods.asXMLString())) {
            // Parse <resetMethods>
            deviceDataBase->addSharedData(string(sId.asCString()), parseResetMethods(sharedInformationElement));
         }
         else if (XMLString::equals(sTag.asXMLString(), tag_eraseMethods.asXMLString())) {
            // Parse <eraseMethods>
            deviceDataBase->addSharedData(string(sId.asCString()), parseEraseMethods(sharedInformationElement));
         }
         else if (XMLString::equals(sTag.asXMLString(), tag_projectActionList.asXMLString())) {
            // Parse <projectActionList>
         }
         else {
            throw MyException(string("DeviceXmlParser::parseSharedXML() - Unexpected Tag = ")+sTag.asCString());
         }
      }
   }
}

//! Create list of reset methods from node
//!
//! @param element - Present position in XML parse
//!
//! @return == 0 - success\n
//!         != 0 - fail
//!
EraseMethodsPtr DeviceXmlParser::parseEraseMethods(DOMElement *element) {
   LOGGING;

   EraseMethods *methods = new EraseMethods;

   // Iterator for <resetMethod method=... /> children
   DOMChildIterator resetMethodIt(element);
   DOMElement *sequenceElement = resetMethodIt.getCurrentElement();
   if (sequenceElement == NULL) {
      // No <resetMethod> children
      throw MyException(string("DeviceXmlParser::parseEraseMethods() - expected <eraseMethod>"));
   }
   else {
      for (;
            resetMethodIt.getCurrentElement() != NULL;
            resetMethodIt.advanceElement()) {

         // <resetMethod>
         DeviceData::EraseMethod option = DeviceData::EraseMethod::eraseNone;

         DOMElement *eraseElement = resetMethodIt.getCurrentElement();

         DualString value1(eraseElement->getTagName());
         log.print("DeviceXmlParser::parseEraseMethods getTagName=\'%s\'\n", (const char *)value1.asCString());

         if (eraseElement->hasAttribute(attr_method.asXMLString())) {
            DualString sType(eraseElement->getAttribute(attr_method.asXMLString()));
            struct {
               const char               *name;
               DeviceData::EraseMethod  type;
            } names[] = {
                  { "Selective", DeviceData::EraseMethod::eraseSelective, },
                  { "All",       DeviceData::EraseMethod::eraseAll, },
                  { "Mass",      DeviceData::EraseMethod::eraseMass, },
                  { "None",      DeviceData::EraseMethod::eraseNone, },
            };
            for (unsigned index=0; index<(sizeof(names)/sizeof(names[0])); index++) {
               if (strcasecmp(names[index].name, sType.asCString()) == 0) {
                  option = names[index].type;
               }
            }
         }
         if (option == DeviceData::EraseMethod::eraseNone) {
            throw MyException(string("DeviceXmlParser::parseEraseMethods() - <eraseMethod> Missing/invalid method attribute "));
         }
         DualString value(eraseElement->getAttribute(attr_isDefault.asXMLString()));
         if (XMLString::equals(value.asCString(), "true")) {
            methods->addDefaultMethod(option);
         }
         else {
            methods->addMethod(option);
         }
         methods->addMethod(option);
      }
   }
   return EraseMethodsPtr(methods);
}

//! Create list of reset methods from node <resetMethod>
//!
//! @param element - Present position in XML parse
//!
//! @return == 0 - success\n
//!         != 0 - fail
//!
ResetMethodsPtr DeviceXmlParser::parseResetMethods(DOMElement *element) {
   LOGGING;

   ResetMethods methods();

   // Iterator for <resetMethod method=... /> children
   DOMChildIterator sequenceElementIt(element);
   DOMElement *sequenceElement = sequenceElementIt.getCurrentElement();

   ResetMethods *options = new ResetMethods;

   if (sequenceElement == NULL) {
      // No <resetMethod> children
      throw MyException(string("DeviceXmlParser::parseResetMethods() - expected <resetMethod>"));
   }
   else {
      DOMChildIterator resetMethodIt(element, tag_resetMethod.asCString());
      for (;
            resetMethodIt.getCurrentElement() != NULL;
            resetMethodIt.advanceElement()) {

         DOMElement *resetElement = resetMethodIt.getCurrentElement();
         DeviceData::ResetMethod option = DeviceData::ResetMethod::resetNone;

         if (resetElement->hasAttribute(attr_method.asXMLString())) {
            DualString sType(resetElement->getAttribute(attr_method.asXMLString()));
            struct {
               const char               *name;
               DeviceData::ResetMethod  type;
            } names[] = {
                  { "hardware",  DeviceData::ResetMethod::resetHardware, },
                  { "software",  DeviceData::ResetMethod::resetSoftware, },
                  { "vendor",    DeviceData::ResetMethod::resetVendor, },
            };
            for (unsigned index=0; index<(sizeof(names)/sizeof(names[0])); index++) {
               if (strcasecmp(names[index].name, sType.asCString()) == 0) {
                  option = names[index].type;
               }
            }
         }
         if (option == DeviceData::ResetMethod::resetNone) {
            throw MyException(string("DeviceXmlParser::parseResetMethods() - <resetMethod> Missing/invalid method attribute "));
         }
         DualString value(resetElement->getAttribute(attr_isDefault.asXMLString()));
         if (XMLString::equals(value.asCString(), "true")) {
            options->addDefaultMethod(option);
         }
         else {
            options->addMethod(option);
         }
      }
   }
   return ResetMethodsPtr(options);
}

TclScriptConstPtr DeviceXmlParser::parseSequence(DOMElement *sequence) {
   // Iterator for <preSequence/postSequence/unsecureSequence> children
   DOMChildIterator sequenceElementIt(sequence);
   DOMElement *sequenceElement = sequenceElementIt.getCurrentElement();
   if (sequenceElement == NULL) {
      // No <preSequence/postSequence> children
      throw MyException(string("DeviceXmlParser::parseSequence() - empty <preSequence/postSequence> = "));
   }
   else {
      // Process each <tclStriptRef> child (should be only one)
      DualString sequenceTag(sequenceElement->getTagName());
      if (XMLString::equals(sequenceTag.asXMLString(), tag_tclScriptRef.asXMLString())) {
         // <tclScriptRef>
         DualString sRef(sequenceElement->getAttribute(attr_ref.asXMLString()));
         return deviceDataBase->getTclScript(sRef.asCString());
      }
      else if (XMLString::equals(sequenceTag.asXMLString(), tag_tclScript.asXMLString())) {
         // <tclScript>
         return parseTCLScript(sequenceElement);
      }
      else {
         throw MyException(string("DeviceXmlParser::parseSequence() - Unexpected Tag = ")+sequenceTag.asCString());
      }
   }
}

FlexNVMInfo::EeepromSizeValue DeviceXmlParser::parseEeepromEntry(DOMElement *eeepromElement) {
   long eeeSize;
   long value;
   DualString sDescription(eeepromElement->getAttribute(attr_description.asXMLString()));
   DualString sEeeSize(eeepromElement->getAttribute(attr_eeeSize.asXMLString()));
   DualString sValue(eeepromElement->getAttribute(attr_value.asXMLString()));
   if ((strlen(sDescription.asCString()) == 0) ||
       !strSizeToULong(sEeeSize.asCString(), NULL, &eeeSize) ||
       !strToULong(sValue.asCString(), NULL, &value)) {
      throw MyException("DeviceXmlParser::parseEeepromEntry() - Illegal description/eeeSize/value attributes");
   }
   return (FlexNVMInfo::EeepromSizeValue(sDescription.asCString(), value, eeeSize));
}

FlexNVMInfo::FlexNvmPartitionValue DeviceXmlParser::parsePartitionEntry(DOMElement *partitionElement) {
   long eeSize;
   long value;
   DualString sDescription(partitionElement->getAttribute(attr_description.asXMLString()));
   DualString sEeSize(partitionElement->getAttribute(attr_eeSize.asXMLString()));
   DualString sValue(partitionElement->getAttribute(attr_value.asXMLString()));
   if ((strlen(sDescription.asCString()) == 0) ||
       !strSizeToULong(sEeSize.asCString(), NULL, &eeSize) ||
       !strToULong(sValue.asCString(), NULL, &value)) {
      throw MyException("DeviceXmlParser::parsePartitionEntry() - Illegal description/eeeSize/value attributes");
   }
   return (FlexNVMInfo::FlexNvmPartitionValue(sDescription.asCString(), value, eeSize));
}

//! Create flexNVMInfo description from flexNVMInfo node
//!
//! @param flexNVMInfoElement - Present position in XML parse
//!
//! @return FlexNVMInfo node created
//!
FlexNVMInfoPtr DeviceXmlParser::parseFlexNVMInfo(DOMElement *flexNVMInfoElement) {
   LOGGING;

   static unsigned defaultBackingRatio = 16;

   FlexNVMInfoPtr pFlexNVMInfoPtr(new FlexNVMInfo(defaultBackingRatio));
   DOMChildIterator eeepromEntryIt(flexNVMInfoElement, tag_eeepromEntry.asCString());
   for (;
         eeepromEntryIt.getCurrentElement() != NULL;
         eeepromEntryIt.advanceElement()) {
      // <eeepromEntry>
      FlexNVMInfo::EeepromSizeValue eeepromSizeValue = parseEeepromEntry(eeepromEntryIt.getCurrentElement());
      pFlexNVMInfoPtr->addEeepromSizeValues(eeepromSizeValue);
   }
   DOMChildIterator partitionEntryIt(flexNVMInfoElement, tag_partitionEntry.asCString());
   for (;
         partitionEntryIt.getCurrentElement() != NULL;
         partitionEntryIt.advanceElement()) {
      // <partitionEntry>
      FlexNVMInfo::FlexNvmPartitionValue flexNvmPartitionValue = parsePartitionEntry(partitionEntryIt.getCurrentElement());
      pFlexNVMInfoPtr->addFlexNvmPartitionValues(flexNvmPartitionValue);
   }
   if (flexNVMInfoElement->hasAttribute(attr_id.asXMLString())) {
      DualString sId(flexNVMInfoElement->getAttribute(attr_id.asXMLString()));
      deviceDataBase->addSharedData(string(sId.asCString()), pFlexNVMInfoPtr);
//      log.print("Inserted shared FlashProgram item ID=%s\n", sId.asCString());
   }
   return pFlexNVMInfoPtr;
}

//! Create memory description from node for flash 'type' memory
//!
//! @param currentProperty    Present position in XML parse
//! @param memoryType         Memory type being processed
//! @param defaultSectorSize  Default sector size (if none specified)
//! @param defaultAlignment   Default alignment (if none specified)
//!
//! @return == 0 - success\n
//!         != 0 - fail
//!
MemoryRegionPtr DeviceXmlParser::parseFlashMemoryDetails(DOMElement *currentProperty, MemType_t memoryType, uint32_t &defaultSectorSize, uint8_t &defaultAlignment) {
   LOGGING;
   long ppageAddress    = 0;
   long registerAddress = 0;
   long securityAddress = 0;
   DualString sPpageAddress(currentProperty->getAttribute(attr_pageAddress.asXMLString()));
   DualString sRegisterAddress(currentProperty->getAttribute(attr_registerAddress.asXMLString()));
   DualString sSecurityAddress(currentProperty->getAttribute(attr_securityAddress.asXMLString()));
   if (!strToULong(sPpageAddress.asCString(),    NULL, &ppageAddress) ||
       !strToULong(sRegisterAddress.asCString(), NULL, &registerAddress) ||
       !strToULong(sSecurityAddress.asCString(), NULL, &securityAddress)) {
      throw MyException("DeviceXmlParser::parseFlashMemoryDetails() - Illegal PPAGE/Register/Security field in Flash");
   }
   long sectorSize      = defaultSectorSize;
   if (currentProperty->hasAttribute(attr_sectorSize.asXMLString())) {
      DualString sSectorSize(currentProperty->getAttribute(attr_sectorSize.asXMLString()));
      if (!strToULong(sSectorSize.asCString(), NULL, &sectorSize)) {
         throw MyException(string("DeviceXmlParser::parseFlashMemoryDetails() - Illegal sectorSize in Flash - ")+sSectorSize.asCString());
      }
      if (isDefault) {
//         log.print("Setting default %s sector size 0x%04lX\n",
//               MemoryRegion::getMemoryTypeName(memoryType), sectorSize);
         defaultSectorSize = sectorSize;
      }
   }
   static AddressType defaultAddressMode = AddrPaged;
   AddressType        addressMode        = defaultAddressMode;
   if (currentProperty->hasAttribute(attr_addressMode.asXMLString())) {
      DualString sAddressMode(currentProperty->getAttribute(attr_addressMode.asXMLString()));
      if (XMLString::equals(sAddressMode.asXMLString(), DualString("linear").asXMLString())) {
         addressMode = AddrLinear;
      }
      else if (XMLString::equals(sAddressMode.asXMLString(), DualString("paged").asXMLString())) {
         addressMode = AddrPaged;
      }
      else {
         throw MyException(string("DeviceXmlParser::parseFlashMemoryDetails() - Illegal addressMode in Flash - ")+sAddressMode.asCString());
      }
      if (isDefault) {
//         log.print("Setting default address mode = %s\n",
//               addressMode==AddrLinear?"linear":"paged");
         defaultAddressMode = addressMode;
      }
   }
   uint32_t alignment = defaultAlignment;
   if (currentProperty->hasAttribute(attr_alignment.asXMLString())) {
      DualString sAlignment(currentProperty->getAttribute(attr_alignment.asXMLString()));
      long temp;
      if (!strToULong(sAlignment.asCString(), NULL, &temp) ||
          ((temp != 1) && (temp != 2) && (temp != 4) && (temp != 8) && (temp != 16) && (temp != 32) && (temp != 64) && (temp != 128) && (temp != 256))) {
         throw MyException(string("DeviceXmlParser::parseFlashMemoryDetails() - Illegal alignment ")+sAlignment.asCString());
      }
      alignment = (uint32_t) temp;
      if (isDefault) {
//         log.print("Setting default %s alignment = %d\n",
//               MemoryRegion::getMemoryTypeName(memoryType), alignment);
         defaultAlignment = alignment;
      }
   }
   MemoryRegionPtr memoryRegionPtr(new MemoryRegion(memoryType, registerAddress, ppageAddress, securityAddress, sectorSize, alignment));
   memoryRegionPtr->setAddressType(addressMode);
   return memoryRegionPtr;
}

//! Create memory description from node
//!
//! @param currentProperty - Present position in XML parse
//!
//! @return == 0 - success\n
//!         != 0 - fail
//!
MemoryRegionPtr DeviceXmlParser::parseMemory(DOMElement *currentProperty) {
   LOGGING;

   // <memory>
   DualString sMemoryType(currentProperty->getAttribute(attr_type.asXMLString()));
   MemoryRegionPtr memoryRegionPtr;

   if (XMLString::equals(sMemoryType.asXMLString(), DualString("eeprom").asXMLString())) {
      // <eeprom>
      static uint32_t defaultFlashSectorSize = 0;
      static uint8_t  defaultAlignment = 1;
      memoryRegionPtr = parseFlashMemoryDetails(currentProperty, MemEEPROM, defaultFlashSectorSize, defaultAlignment);
   }
   else if (XMLString::equals(sMemoryType.asXMLString(), DualString("flash").asXMLString())) {
      // <flash>
      static uint32_t defaultFlashSectorSize = 0;
      static uint8_t  defaultAlignment = 1;
      memoryRegionPtr = parseFlashMemoryDetails(currentProperty, MemFLASH, defaultFlashSectorSize, defaultAlignment);
   }
   else if (XMLString::equals(sMemoryType.asXMLString(), DualString("pFlash").asXMLString())) {
      // <flash>
      static uint32_t defaultFlashSectorSize = 0;
      static uint8_t  defaultAlignment = 1;
      memoryRegionPtr = parseFlashMemoryDetails(currentProperty, MemPFlash, defaultFlashSectorSize, defaultAlignment);
   }
   else if (XMLString::equals(sMemoryType.asXMLString(), DualString("dFlash").asXMLString())) {
      // <flash>
      static uint32_t defaultFlashSectorSize = 0;
      static uint8_t  defaultAlignment = 1;
      memoryRegionPtr = parseFlashMemoryDetails(currentProperty, MemDFlash, defaultFlashSectorSize, defaultAlignment);
   }
   else if (XMLString::equals(sMemoryType.asXMLString(), DualString("pROM").asXMLString())) {
      // <prom>
      static uint32_t defaultFlashSectorSize = 0;
      static uint8_t  defaultAlignment = 1;
      memoryRegionPtr = parseFlashMemoryDetails(currentProperty, MemPROM, defaultFlashSectorSize, defaultAlignment);
   }
   else if (XMLString::equals(sMemoryType.asXMLString(), DualString("xROM").asXMLString())) {
      // <xrom>
      static uint32_t defaultFlashSectorSize = 0;
      static uint8_t  defaultAlignment = 1;
      memoryRegionPtr = parseFlashMemoryDetails(currentProperty, MemXROM, defaultFlashSectorSize, defaultAlignment);
   }
   else if (XMLString::equals(sMemoryType.asXMLString(), DualString("flexNVM").asXMLString())) {
      // <flexNVM>
      static uint32_t defaultFlashSectorSize = 0;
      static uint8_t  defaultAlignment = 1;
      memoryRegionPtr = parseFlashMemoryDetails(currentProperty, MemFlexNVM, defaultFlashSectorSize, defaultAlignment);
   }
   else if (XMLString::equals(sMemoryType.asXMLString(), DualString("ram").asXMLString())) {
      // <ram>
      memoryRegionPtr = MemoryRegionPtr(new MemoryRegion(MemRAM));
   }
   else if (XMLString::equals(sMemoryType.asXMLString(), DualString("rom").asXMLString())) {
      // <rom>
      memoryRegionPtr = MemoryRegionPtr(new MemoryRegion(MemROM));
   }
   else if (XMLString::equals(sMemoryType.asXMLString(), DualString("flexRAM").asXMLString())) {
      // <ram>
      memoryRegionPtr = MemoryRegionPtr(new MemoryRegion(MemFlexRAM));
   }
   else if (XMLString::equals(sMemoryType.asXMLString(), DualString("io").asXMLString())) {
      // <io>
      memoryRegionPtr = MemoryRegionPtr(new MemoryRegion(MemIO));
   }
   else if (XMLString::equals(sMemoryType.asXMLString(), DualString("pRAM").asXMLString())) {
      // <pram>
      memoryRegionPtr = MemoryRegionPtr(new MemoryRegion(MemPRAM));
   }
   else if (XMLString::equals(sMemoryType.asXMLString(), DualString("xRAM").asXMLString())) {
      // <xram>
      memoryRegionPtr = MemoryRegionPtr(new MemoryRegion(MemXRAM));
   }
   else {
      throw MyException(string("DeviceXmlParser::parseDeviceXML() - invalid memory range type ")+sMemoryType.asCString());
   }
   DOMChildIterator flashProgramIt(currentProperty, tag_flashProgram.asCString());
   if (flashProgramIt.getCurrentElement() != NULL) {
      // <flashProgram>
      memoryRegionPtr->setFlashProgram(parseFlashProgram(flashProgramIt.getCurrentElement()));
   }
   DOMChildIterator flashProgramRefIt(currentProperty, tag_flashProgramRef.asCString());
   if (flashProgramRefIt.getCurrentElement() != NULL) {
      // <flashProgramRef>
      DualString sRef(flashProgramRefIt.getCurrentElement()->getAttribute(attr_ref.asXMLString()));
      memoryRegionPtr->setFlashProgram(deviceDataBase->getFlashProgram(sRef.asCString()));
   }
   DOMChildIterator securityEntryIt(currentProperty, tag_securityEntry.asCString());
   if (securityEntryIt.getCurrentElement() != NULL) {
      // <securityEntry>
      SecurityEntryPtr securityEntryPtr = parseSecurityEntry(securityEntryIt.getCurrentElement());
//      log.print("Flash entry description(%s)\n", securityEntryPtr->toString().c_str());
      memoryRegionPtr->setSecurityEntry(securityEntryPtr);
   }
   DOMChildIterator securityEntryRefIt(currentProperty, tag_securityEntryRef.asCString());
   if (securityEntryRefIt.getCurrentElement() != NULL) {
      // <securityEntryRef>
      DualString sRef(securityEntryRefIt.getCurrentElement()->getAttribute(attr_ref.asXMLString()));
      SecurityEntryPtr securityEntryPtr(deviceDataBase->getSecurityEntry(sRef.asCString()));
      memoryRegionPtr->setSecurityEntry(securityEntryPtr);
   }

   DOMChildIterator checksumEntryIt(currentProperty, tag_checksumEntry.asCString());
   if (checksumEntryIt.getCurrentElement() != NULL) {
      // <checksumEntry>
      ChecksumInfoPtr checksumInfoPtr = parseChecksumInfo(checksumEntryIt.getCurrentElement());
//      log.print("Flash entry description(%s)\n", checksumInfoPtr->toString().c_str());
      memoryRegionPtr->setChecksumInfo(checksumInfoPtr);
   }
   DOMChildIterator checksumEntryRefIt(currentProperty, tag_checksumEntryRef.asCString());
   if (checksumEntryRefIt.getCurrentElement() != NULL) {
      // <checksumEntryRef>
      DualString sRef(checksumEntryRefIt.getCurrentElement()->getAttribute(attr_ref.asXMLString()));
      ChecksumInfoPtr checksumInfoPtr(deviceDataBase->getChecksumEntry(sRef.asCString()));
      memoryRegionPtr->setChecksumInfo(checksumInfoPtr);
   }

   DOMChildIterator flexNvmInfoIt(currentProperty, tag_flexNvmInfo.asCString());
   if (flexNvmInfoIt.getCurrentElement() != NULL) {
      // <flexNVMInfo>
      memoryRegionPtr->setflexNVMInfo(parseFlexNVMInfo(flexNvmInfoIt.getCurrentElement()));
   }
   DOMChildIterator flexNvmInfoRefIt(currentProperty, tag_flexNvmInfoRef.asCString());
   if (flexNvmInfoRefIt.getCurrentElement() != NULL) {
      // <flexNvmInfoRef>
      DualString sRef(flexNvmInfoRefIt.getCurrentElement()->getAttribute(attr_ref.asXMLString()));
      memoryRegionPtr->setflexNVMInfo(deviceDataBase->getFlexNVMInfo(sRef.asCString()));
   }
   DOMChildIterator memoryRangeIt(currentProperty, tag_memoryRange.asCString());
   for (;
         memoryRangeIt.getCurrentElement() != NULL;
         memoryRangeIt.advanceElement()) {
      // <memoryRange>

      //====================================================
      // Memory addresses
      //
      bool startGiven  = memoryRangeIt.getCurrentElement()->hasAttribute(attr_start.asXMLString());
      bool middleGiven = memoryRangeIt.getCurrentElement()->hasAttribute(attr_middle.asXMLString());
      bool endGiven    = memoryRangeIt.getCurrentElement()->hasAttribute(attr_end.asXMLString());
      bool sizeGiven   = memoryRangeIt.getCurrentElement()->hasAttribute(attr_size.asXMLString());

      DualString sMemoryStartAddress(memoryRangeIt.getCurrentElement()->getAttribute(attr_start.asXMLString()));
      DualString sMemoryMiddleAddress(memoryRangeIt.getCurrentElement()->getAttribute(attr_middle.asXMLString()));
      DualString sMemoryEndAddress(memoryRangeIt.getCurrentElement()->getAttribute(attr_end.asXMLString()));
      DualString sMemorySize(memoryRangeIt.getCurrentElement()->getAttribute(attr_size.asXMLString()));

      long memoryStartAddress  = 0;
      long memoryMiddleAddress = 0;
      long memoryEndAddress    = 1; // Bias for rounding is word address
      long memorySize          = 0;

      bool addressOK = true;
      if (startGiven && endGiven) {
         addressOK = strToULong(sMemoryStartAddress.asCString(), NULL, &memoryStartAddress) &&
               strToULong(sMemoryEndAddress.asCString(), NULL, &memoryEndAddress) &&
               !middleGiven && !sizeGiven && (memoryStartAddress <= memoryEndAddress);
      }
      else if (startGiven && sizeGiven) {
         addressOK = strToULong(sMemoryStartAddress.asCString(), NULL, &memoryStartAddress) &&
               strSizeToULong(sMemorySize.asCString(), NULL, &memorySize) &&
               !middleGiven && !endGiven && (memorySize > 0);
         memoryEndAddress = memoryStartAddress + memorySize - 1;
      }
      else if (middleGiven && sizeGiven) {
         addressOK = strToULong(sMemoryMiddleAddress.asCString(), NULL, &memoryMiddleAddress) &&
               strSizeToULong(sMemorySize.asCString(), NULL, &memorySize) &&
               (memorySize >= 2) && ((memorySize & 0x01) == 0);
         memoryStartAddress = memoryMiddleAddress - (memorySize/2);
         memoryEndAddress   = memoryMiddleAddress + (memorySize/2)-1;
      }
      else if (endGiven && sizeGiven) {
         addressOK = strToULong(sMemoryEndAddress.asCString(), NULL, &memoryEndAddress) &&
               strSizeToULong(sMemorySize.asCString(), NULL, &memorySize) &&
               !startGiven && !middleGiven && (memorySize > 0);
         memoryStartAddress = memoryEndAddress - (memorySize - 1);
      }
      if (!addressOK) {
         log.print("memoryRangeIt() startGiven=%s, middleGiven=%s, endGiven=%s, sizeGiven=%s, \n",
               startGiven?"Y":"N", middleGiven?"Y":"N", endGiven?"Y":"N", sizeGiven?"Y":"N");
         log.print("memoryRangeIt() memoryStartAddress=0x%lX, memoryMiddleAddress=0x%lX, memoryEndAddress=0x%lX, memorySize=0x%lX, \n",
               memoryStartAddress, memoryMiddleAddress, memoryEndAddress, memorySize);
         throw MyException("memoryRangeIt() - Illegal memory start/middle/end/size in memory region list");
      }
      //====================================================
      // Page numbers
      //
      bool pageResetGiven =  memoryRangeIt.getCurrentElement()->hasAttribute(attr_pageReset.asXMLString());
      bool pageNoGiven    =  memoryRangeIt.getCurrentElement()->hasAttribute(attr_pageNo.asXMLString());
      bool pageStartGiven =  memoryRangeIt.getCurrentElement()->hasAttribute(attr_pageStart.asXMLString());
      bool pageEndGiven   =  memoryRangeIt.getCurrentElement()->hasAttribute(attr_pageEnd.asXMLString());
      bool pagesGiven     =  memoryRangeIt.getCurrentElement()->hasAttribute(attr_pages.asXMLString());

      DualString sPageReset(memoryRangeIt.getCurrentElement()->getAttribute(attr_pageReset.asXMLString()));
      DualString sPageNo(memoryRangeIt.getCurrentElement()->getAttribute(attr_pageNo.asXMLString()));
      DualString sPageStart(memoryRangeIt.getCurrentElement()->getAttribute(attr_pageStart.asXMLString()));
      DualString sPageEnd(memoryRangeIt.getCurrentElement()->getAttribute(attr_pageEnd.asXMLString()));
      DualString sPages(memoryRangeIt.getCurrentElement()->getAttribute(attr_pages.asXMLString()));

      long pageStart = 0;
      long pageEnd   = 0;
      long pages     = 0;
      bool pageOK    = true;
      // If paged, assume page size is memory range
      const long pageSize = memoryEndAddress - memoryStartAddress +1;

      if (!pageNoGiven && !pageStartGiven && !pageEndGiven && !pagesGiven && !pageResetGiven) {
         memoryRegionPtr->addRange(memoryStartAddress, memoryEndAddress);
         continue;
      }
      else if (pageNoGiven) {
         pageOK = pageOK &&
               strToULong(sPageNo.asCString(), NULL, &pageStart) &&
               !pageStartGiven && !pageEndGiven && !pagesGiven && !pageResetGiven;
         if (pageOK) {
            memoryRegionPtr->addRange(memoryStartAddress, memoryEndAddress, pageStart);
            continue;
         }
      }
      else if (pageStartGiven && pageEndGiven) {
         pageOK = pageOK &&
               strToULong(sPageStart.asCString(), NULL, &pageStart) &&
               strToULong(sPageEnd.asCString(), NULL, &pageEnd) &&
               !pagesGiven;
         pages = pageEnd - pageStart + 1;
//         log.print("Start/End, pageOK=%s\n", pageOK?"True":"False");
      }
      else if (pageStartGiven && pagesGiven) {
         pageOK = pageOK &&
               strToULong(sPageStart.asCString(), NULL, &pageStart) &&
               strSizeToULong(sPages.asCString(), NULL, &pages) &&
               !pageEndGiven;
         if (pages >= 1024) {
            // Assume size of paged area rather than number of pages
            pageOK = pageOK && ((pages % pageSize) == 0);
            pages /= pageSize;
         }
         pageEnd = pageStart + pages - 1;
//         log.print("Start/Pages, pageOK=%s\n", pageOK?"True":"False");
      }
      else if (pageEndGiven && pagesGiven) {
         pageOK = pageOK &&
               strToULong(sPageEnd.asCString(), NULL, &pageEnd) &&
               strSizeToULong(sPages.asCString(), NULL, &pages) &&
               !pageStartGiven;
         if (pages >= 1024) {
            // Assume size of paged area rather than number of pages
            pageOK = pageOK && ((pages % pageSize) == 0);
            pages /= pageSize;
         }
         pageStart = pageEnd - pages + 1;
//         log.print("End/Pages, pageOK=%s\n", pageOK?"True":"False");
      }
      long pageReset;
      if (pageResetGiven) {
         pageOK = pageOK && strToULong(sPageReset.asCString(), NULL, &pageReset) && (pageReset >= pageStart) && (pageReset <= pageEnd);
         if (pageOK) {
            // This page is visible on reset (from reset PPAGE value)
            if (pageReset == 0) {
               // Ignore reset page zero since it will created as part of set anyway
               pageResetGiven = false;
            }
            else {
               memoryRegionPtr->addRange(memoryStartAddress, memoryEndAddress, pageReset);
//            log.print("Adding reset page (0x%06X, 0x%06X, P:0x%02X) pageOK=%s\n",
//                  memoryStartAddress, memoryEndAddress, pageReset, pageOK?"True":"False");
            }
         }
      }
      if (!pageOK ||
          ((pageStart < 0) || (pageStart > 0xFF)) ||
          ((pageEnd < 0)   || (pageEnd > 0xFF)) ||
          (pageResetGiven && (pageStart <= 0x00) && ( 0x00 <= pageEnd)) ) {
         log.error("memoryRangeIt() pageStartGiven=%s, pagesGiven=%s, pageEndGiven=%s, pageNoGiven=%s, pageResetGiven=%s \n",
               pageStartGiven?"Y":"N", pagesGiven?"Y":"N", pageEndGiven?"Y":"N", pageNoGiven?"Y":"N", pageResetGiven?"Y":"N");
         log.error("memoryRangeIt() pageStart=0x%06lX, pages=0x%06lX, pageEnd=0x%06lX\n",
               pageStart, pages, pageEnd);
         throw MyException("memoryRangeIt() - Illegal memory pageStart/pages/pageEnd/pageNo/pageReset in memory region list");
      }
      for (int pageNo = pageStart; pageNo <= pageEnd; pageNo++) {
         // These pages use default page no from 24-bit address
         uint32_t pageValue = (pageNo<<16) & 0xFF0000;
         uint32_t start = memoryStartAddress|pageValue;
         uint32_t end   = memoryEndAddress|pageValue;
         memoryRegionPtr->addRange(start, end);
//         log.print("Adding page (0x%06X, 0x%06X)\n", start, end);
      }
      //      log.print("DeviceXmlParser::parseMemory((): Current device = %s, 0x%02X:[0x%06X, 0x%06X]\n", currentDeviceName, pageNo, memoryStartAddress, memoryEndAddress);
   }
   if ((memoryRegionPtr->getSecurityAddress() != 0) && (memoryRegionPtr->getSecurityEntry() == NULL)) {
      throw MyException("memoryRangeIt() - Security address without security region in memory region list");
   }
   return memoryRegionPtr;
}

/*!
 *    Create device description from node
 *
 *  <!ELEMENT device ((sdid*|
 *                     (clock?,
 *                      (memory|memoryRef)+,
 *                      (soptAddress|copctlAddress)?,
 *                      sdidAddress?,
 *                      sdidMask?,
 *                      sdid+,
 *                      sbdfrAddress?,
 *                      (eraseMethod+)?,
 *                      flashScripts?,
 *                      (tclScript|tclScriptRef)?,
 *                      (flashProgram|flashProgramRef)?,
 *                      flashProgramData?,
 *                      (flexNVMInfo|flexNVMInfoRef)?,
 *                      (projectActionList|projectActionListRef)*,
 *                      (registerDescription|registerDescriptionRef)?
 *                      )
 *                     ),
 *                    note*)>
 *
 *  @param deviceEl - Present position in XML parse
 *  @return == 0 - success\n
 *          != 0 - fail
 */
DeviceDataPtr DeviceXmlParser::parseDevice(DOMElement *deviceEl) {
   LOGGING;

   // Default device characteristics
   // These are initialized from the default device (if any) in the XML
   static TclScriptConstPtr            defaultTCLScript;
   static RegisterDescriptionConstPtr  defaultRegisterDescription;
   static FlashProgramConstPtr         defFlashProgram;
   static FlexNVMInfoConstPtr          defaultFlexNVMInfo;

   static uint32_t defWatchdogAddress = 0;
   static uint32_t defSDIDAddress     = 0;
   static uint32_t defSDIDMask        = 0;
   static uint32_t defSbdfrAddress    = DeviceData::getDefaultHCS08sbdfrAddress();
   static bool     initDone = false;

   static ResetMethodsConstPtr defaultResetMethods;
   static EraseMethodsConstPtr defaultEraseMethods;

   if (!initDone) {
      initDone = true;
      if (targetType == T_HCS08) {
         defWatchdogAddress = 0x1802;
         defSDIDAddress     = 0x1806;
         defSDIDMask        = 0xFFF;
      }
      else if (targetType == T_RS08) {
         defWatchdogAddress = 0x00000000;
         defSDIDAddress     = 0x00000000;
         defSDIDMask        = 0xFFF;
      }
      else if (targetType == T_CFV1) {
         defWatchdogAddress = 0x00000000;
         defSDIDAddress     = 0x00000000;
         defSDIDMask        = 0xFFF;
      }
      else if (targetType == T_CFVx) {
         defWatchdogAddress = 0x00000000;
         defSDIDAddress     = 0x4011000A;
         defSDIDMask        = 0xFFC0;
      }
      else if ((targetType == T_HCS12) || (targetType == T_S12Z)) {
         defWatchdogAddress = 0x003C;
         defSDIDAddress     = 0x001A;  // actually partid;
         defSDIDMask        = 0xFFFF;
      }
      else if (targetType == T_ARM) {
         defWatchdogAddress = 0x00000000;
         defSDIDAddress     = 0x00000000;
         defSDIDMask        = 0xFFFFFFFF;
      }
      else if (targetType == T_MC56F80xx) {
         defWatchdogAddress = 0x00000000;
         defSDIDAddress     = 0x00000000;
         defSDIDMask        = 0xFFFFFFFF; // SDID Not used
      }
   }

   static uint32_t         currentSDIDMask  = defSDIDMask; // SDID mask to apply to current SDIDs

   // Create new device
   DeviceDataPtr itDev = DeviceDataPtr(new DeviceData(targetType));

   // Set default values
   itDev->setWatchdogAddress(defWatchdogAddress);

   itDev->setFlashScripts(defaultTCLScript);
   itDev->setRegisterDescription(defaultRegisterDescription);
   itDev->setSDIDAddress(defSDIDAddress);
   itDev->setHCS08sbdfrAddress(defSbdfrAddress);

   itDev->setEraseMethods(defaultEraseMethods);
   itDev->setResetMethods(defaultResetMethods);

   DOMChildIterator propertyIt(deviceEl);
   for (;
         propertyIt.getCurrentElement() != NULL;
         propertyIt.advanceElement()) {

      DOMElement *currentProperty = propertyIt.getCurrentElement();
      DualString propertyTag(currentProperty->getTagName());
      if (XMLString::equals(propertyTag.asXMLString(), tag_note.asXMLString())) {
         // <note>
         //            DualString sNoteText(currentProperty->getTextContent());
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_clock.asXMLString())) {
         // <clock>
         DualString sClockType(currentProperty->getAttribute(attr_type.asXMLString()));
         DualString sClockRegisterAddress(currentProperty->getAttribute(attr_registerAddress.asXMLString()));
         long clockRegisterAddress;
         if (!strToULong(sClockRegisterAddress.asCString(), NULL, &clockRegisterAddress)) {
            throw MyException("DeviceXmlParser::parseDevice() - Illegal Clock register address");
         }
         itDev->setClockType(ClockTypes::getClockType(sClockType.asCString()));
         itDev->setClockAddress(clockRegisterAddress);
         itDev->setClockTrimNVAddress(itDev->getDefaultClockTrimNVAddress());
         itDev->setClockTrimFreq(itDev->getDefaultClockTrimFreq());
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_memory.asXMLString())) {
         // <memory>
         itDev->addMemoryRegion(parseMemory(currentProperty));
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_memoryRef.asXMLString())) {
         // <memoryRef>
         DualString sRef(currentProperty->getAttribute(attr_ref.asXMLString()));
         itDev->addMemoryRegion(deviceDataBase->getMemoryRegion(sRef.asCString()));
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_sdid.asXMLString())) {
         // <sdid value="vv" mask="mm">
         long sdidValue;
         long sdidMask = currentSDIDMask;
         if (currentProperty->hasAttribute(attr_mask.asXMLString())) {
            DualString sSdidMask(currentProperty->getAttribute(attr_mask.asXMLString()));
            if (!strToULong(sSdidMask.asCString(), NULL, &sdidMask)) {
               throw MyException(string("DeviceXmlParser::parseDevice() - Illegal SDID mask ")+sSdidMask.asCString());
            }
         }
         DualString sSdidValue(currentProperty->getAttribute(attr_value.asXMLString()));
         if (!strToULong(sSdidValue.asCString(), NULL, &sdidValue)) {
            throw MyException(string("DeviceXmlParser::parseDevice() - Illegal SDID address ")+sSdidValue.asCString());
         }
         itDev->addSDID(sdidMask, sdidValue);
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_sdidAddress.asXMLString())) {
         // <sdidAddress>
         DualString sSdidAddress(currentProperty->getAttribute(attr_value.asXMLString()));
         long sdidAddress;
         if (!strToULong(sSdidAddress.asCString(), NULL, &sdidAddress)) {
            throw MyException(string("DeviceXmlParser::parseDevice() - Illegal Clock SDID value ")+sSdidAddress.asCString());
         }
         itDev->setSDIDAddress(sdidAddress);
         if (isDefault) {
            //            log.warning("Setting default SDID Address 0x%08lX \n", sdidAddress);
            defSDIDAddress = sdidAddress;
         }
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_sbdfrAddress.asXMLString())) {
         // <sbdfrAddress>
         DualString sSbdfrAddress(currentProperty->getAttribute(attr_value.asXMLString()));
         long sbdfrAddress;
         if (!strToULong(sSbdfrAddress.asCString(), NULL, &sbdfrAddress)) {
            throw MyException(string("DeviceXmlParser::parseDevice() - Illegal sbdfrAddress ")+sSbdfrAddress.asCString());
         }
         itDev->setHCS08sbdfrAddress(sbdfrAddress);
         if (isDefault) {
            //            log.warning("Setting default SDID mask 0x%08lX \n", sdidMask);
            defSbdfrAddress = sbdfrAddress;
         }
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_sdidMask.asXMLString())) {
         // <sdidMask>
         DualString sSdidMask(currentProperty->getAttribute(attr_value.asXMLString()));
         long sdidMask;
         if (!strToULong(sSdidMask.asCString(), NULL, &sdidMask)) {
            throw MyException(string("DeviceXmlParser::parseDevice() - Illegal SDID mask ")+sSdidMask.asCString());
         }
         currentSDIDMask = sdidMask;
         if (isDefault) {
            //            log.warning("Setting default SDID mask 0x%08lX \n", sdidMask);
            defSDIDMask = sdidMask;
         }
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_copctlAddress.asXMLString())) {
         // <copctlAddress>
         DualString sCopctlAddress(currentProperty->getAttribute(attr_value.asXMLString()));
         long copctlAddress=0;
         if (!strToULong(sCopctlAddress.asCString(), NULL, &copctlAddress)) {
            throw MyException("DeviceXmlParser::parseDevice() - Illegal COPCTL address");
         }
         itDev->setWatchdogAddress(copctlAddress);
         if (isDefault)
            //            log.warning("Setting default WatchdogAddress Address 0x%06lX \n", copctlAddress);
            defWatchdogAddress = copctlAddress;
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_soptAddress.asXMLString())) {
         // <soptAddress>
         DualString sSoptAddress(currentProperty->getAttribute(attr_value.asXMLString()));
         long soptAddress = 0x00;
         if (!strToULong(sSoptAddress.asCString(), NULL, &soptAddress)) {
            throw MyException(string("DeviceXmlParser::parseDevice() - Illegal SPOT address ")+sSoptAddress.asCString());
         }
         itDev->setWatchdogAddress(soptAddress);
         if (isDefault) {
            //            log.warning("Setting default WatchdogAddress Address 0x%08lX \n", soptAddress);
            defWatchdogAddress = soptAddress;
         }
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_tclScript.asXMLString())) {
         // <tclScript>
         itDev->setFlashScripts(parseTCLScript(currentProperty));
         if (isDefault) {
            defaultTCLScript = itDev->getFlashScripts();
         }
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_tclScriptRef.asXMLString())) {
         // <tclScriptRef>
         DualString sRef(currentProperty->getAttribute(attr_ref.asXMLString()));
         itDev->setFlashScripts(deviceDataBase->getTclScript(sRef.asCString()));
         if (isDefault) {
            //            log.print("Setting default flash script \"%s\" \n", sRef.asCString());
            defaultTCLScript = itDev->getFlashScripts();
         }
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_registerDescription.asXMLString())) {
         // <RegisterDescription>
         itDev->setRegisterDescription(parseRegisterDescription(currentProperty));
         if (isDefault) {
            defaultRegisterDescription = itDev->getRegisterDescription();
         }
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_registerDescriptionRef.asXMLString())) {
         // <RegisterDescriptionRef>
         DualString sRef(currentProperty->getAttribute(attr_ref.asXMLString()));
         itDev->setRegisterDescription(deviceDataBase->getRegisterDescription(sRef.asCString()));
         if (isDefault) {
            //            log.print("Setting default register description \"%s\" \n", sRef.asCString());
            defaultRegisterDescription = itDev->getRegisterDescription();
         }
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_flashScripts.asXMLString())) {
         // <flashScripts>
         itDev->setFlashScripts(parseSequence(currentProperty));
         if (isDefault) {
            //            log.print("Setting default flash script (non-shared)\n");
            defaultTCLScript = itDev->getFlashScripts();
         }
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_flashProgram.asXMLString())) {
         // <flashProgram>
         itDev->setCommonFlashProgram(parseFlashProgram(currentProperty));
         if (isDefault) {
            //            log.print("Setting default flash program (non-shared)\n");
            defFlashProgram = itDev->getCommonFlashProgram();
         }
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_flashProgramRef.asXMLString())) {
         // <flashProgramRef>
         DualString sRef(currentProperty->getAttribute(attr_ref.asXMLString()));
         itDev->setCommonFlashProgram(deviceDataBase->getFlashProgram(sRef.asCString()));
         if (isDefault) {
            //            log.print("Setting default flash program: \"%s\" \n", sRef.asCString());
            defFlashProgram = itDev->getCommonFlashProgram();
         }
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_flexNvmInfo.asXMLString())) {
         // <flexNVMInfo>
         itDev->setflexNVMInfo(parseFlexNVMInfo(currentProperty));
         if (isDefault) {
            //            log.print("Setting default flexNVMInfo (non-shared)\n");
            defaultFlexNVMInfo = itDev->getflexNVMInfo();
         }
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_flexNvmInfoRef.asXMLString())) {
         // <flexNvmInfoRef>
         DualString sRef(currentProperty->getAttribute(attr_ref.asXMLString()));
         itDev->setflexNVMInfo(deviceDataBase->getFlexNVMInfo(sRef.asCString()));
         if (isDefault) {
            //            log.print("Setting default flexNVMInfo (non-shared)\n");
            defaultFlexNVMInfo = itDev->getflexNVMInfo();
         }
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_resetMethods.asXMLString())) {
         // <flashProgram>
         itDev->setResetMethods(parseResetMethods(currentProperty));
         if (isDefault) {
            //            log.print("Setting default resetMethods (non-shared)\n");
            defaultResetMethods = itDev->getResetMethods();
         }
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_resetMethodsRef.asXMLString())) {
         // <flashProgramRef>
         DualString sRef(currentProperty->getAttribute(attr_ref.asXMLString()));
         itDev->setResetMethods(deviceDataBase->getResetMethods(sRef.asCString()));
         if (isDefault) {
            //            log.print("Setting default resetMethods (non-shared)\n");
            defaultResetMethods = itDev->getResetMethods();
         }
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_eraseMethods.asXMLString())) {
         // <eraseMethods>
         itDev->setEraseMethods(parseEraseMethods(currentProperty));
         if (isDefault) {
            //            log.print("Setting default eraseMethods (non-shared)\n");
            defaultEraseMethods = itDev->getEraseMethods();
         }
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_eraseMethodsRef.asXMLString())) {
         // <eraseMethodsRef>
         DualString sRef(currentProperty->getAttribute(attr_ref.asXMLString()));
         itDev->setEraseMethods(deviceDataBase->getEraseMethods(sRef.asCString()));
         if (isDefault) {
            //            log.print("Setting default eraseMethods (non-shared)\n");
            defaultEraseMethods = itDev->getEraseMethods();
         }
      }
      else {
         throw MyException(string("DeviceXmlParser::parseDevice() - Unknown tag - ")+propertyTag.asCString());
      }
   }
   if (!itDev->getFlashProgram()) {
      // Set default flash program if none available from device
      //      log.error("WARNING: Setting default programming code for %s\n", currentDeviceName);
      itDev->setCommonFlashProgram(defFlashProgram);
   }
   return itDev;
}

/*!
 *    Create device description from alias node
 *
 *   !ELEMENT device ((sdid*),
 *                    note*)>
 *
 *  @param deviceEl - Present position in XML parse
 *  @return == 0 - success\n
 *          != 0 - fail
 */
DeviceDataPtr DeviceXmlParser::parseAlias(DOMElement *deviceEl) {
   LOGGING;

   // Create new device
   DeviceDataPtr device(new DeviceData(targetType));

   // Get real device name. Note - Assumes ASCII string
   DualString aliasValue(deviceEl->getAttribute(attr_alias.asXMLString()));
   char buff[50];
   strncpy(buff, aliasValue.asCString(), sizeof(buff));
   buff[sizeof(buff)-1] = '\0';
   strUpper(buff);
   if (strlen(buff) == 0) {
      throw MyException(string("DeviceXmlParser::parseAlias() - Alias name missing or invalid"));
   }

   DeviceDataPtr baseDevice = deviceDataBase->findMutableDeviceFromName(buff);
   if (baseDevice == nullptr) {
      throw MyException(string("DeviceXmlParser::parseAlias() - Alias refers to non-existent device"));
   }

   long currentSDIDMask = 0;

   DOMChildIterator propertyIt(deviceEl);
   for (;
         propertyIt.getCurrentElement() != NULL;
         propertyIt.advanceElement()) {

      DOMElement *currentProperty = propertyIt.getCurrentElement();
      DualString propertyTag(currentProperty->getTagName());
      if (XMLString::equals(propertyTag.asXMLString(), tag_note.asXMLString())) {
         // <note>
         //            DualString sNoteText(currentProperty->getTextContent());
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_sdidMask.asXMLString())) {
         // <sdidMask value="vvv">
         DualString sSdidMask(currentProperty->getAttribute(attr_value.asXMLString()));
         long sdidMask;
         if (!strToULong(sSdidMask.asCString(), NULL, &sdidMask)) {
            throw MyException(string("DeviceXmlParser::parseAlias() - Illegal SDID mask ")+sSdidMask.asCString());
         }
         currentSDIDMask = sdidMask;
      }
      else if (XMLString::equals(propertyTag.asXMLString(), tag_sdid.asXMLString())) {
         // <sdid value="vv" mask="mm">
         long sdidValue;
         long sdidMask = currentSDIDMask;
         if (currentProperty->hasAttribute(attr_mask.asXMLString())) {
            DualString sSdidMask(currentProperty->getAttribute(attr_mask.asXMLString()));
            if (!strToULong(sSdidMask.asCString(), NULL, &sdidMask)) {
               throw MyException(string("DeviceXmlParser::parseDevice() - Illegal SDID mask ")+sSdidMask.asCString());
            }
         }
         DualString sSdidValue(currentProperty->getAttribute(attr_value.asXMLString()));
         if (!strToULong(sSdidValue.asCString(), NULL, &sdidValue)) {
            throw MyException(string("DeviceXmlParser::parseDevice() - Illegal SDID address ")+sSdidValue.asCString());
         }
         device->addSDID(sdidMask, sdidValue);
         // Add to base device so it is accepted by programmer etc
         baseDevice->addAliasSDID(sdidMask, sdidValue);
      }
//      else if (XMLString::equals(propertyTag.asXMLString(), tag_sdidAddress.asXMLString())) {
//         // <sdidAddress>
//         DualString sSdidAddress(currentProperty->getAttribute(attr_value.asXMLString()));
//         long sdidAddress;
//         if (!strToULong(sSdidAddress.asCString(), NULL, &sdidAddress)) {
//            throw MyException(string("DeviceXmlParser::parseAlias() - Illegal Clock SDID value ")+sSdidAddress.asCString());
//         }
//         device->setSDIDAddress(sdidAddress);
//      }
      else {
         throw MyException(string("DeviceXmlParser::parseAlias() - Unknown tag - ")+propertyTag.asCString());
      }
   }
   device->setBaseDevice(baseDevice);

   // Note is OK to share data from base device as alias has a smart pointer to base device
   if (deviceEl->hasAttribute(attr_hidden.asXMLString())) {
      device->setHidden();
   }
   // Inherit SDID information from base device if none given
   if (device->getSDIDs().empty()) {
      device->setTargetSDIDs(baseDevice->getSDIDs());
   }
   if (device->getSDIDAddress() == 0x0) {
      device->setSDIDAddress(baseDevice->getSDIDAddress());
   }
   return device;
}

//! Create device list from device nodes
//!
//!   !ELEMENT device ((sdid*|
//!                     (clock?,
//!                      (memory|memoryRef)+,
//!                      (soptAddress|copctlAddress)?,
//!                      sdidAddress?,
//!                      sdidMask?,
//!                      sdid+,
//!                      flashScripts?,
//!                      (tclScript|tclScriptRef)?,
//!                      (flashProgram|flashProgramRef)?,
//!                      flashProgramData?,
//!                      (flexNVMInfo|flexNVMInfoRef)?,
//!                      (projectActionList|projectActionListRef)*,
//!                      (registerDescription|registerDescriptionRef)?
//!                      )
//!                     ),
//!                    note*)>
//!       <!ATTLIST device name ID #REQUIRED>
//!       <!ATTLIST device alias IDREF #IMPLIED>
//!       <!ATTLIST device family (RS08|HCS08|HCS08Plus|HCS12|CFV1|CFV1Plus|CFV2|CFV3|CFV4|ARM|DSC|CortexM0|CortexM3|CortexM3F|CortexM4|CortexM4F) #IMPLIED>
//!       <!ATTLIST device isDefault (true) #IMPLIED>
//!       <!ATTLIST device speed CDATA #IMPLIED>
//!       <!ATTLIST device subfamily CDATA #IMPLIED>
//!       <!ATTLIST device hidden (true) #IMPLIED>
//!
//! @return == 0 - success\n
//!         != 0 - fail
//!
void DeviceXmlParser::parseDeviceXML(void) {
   LOGGING;

   DOMChildIterator deviceIt(document, tag_device.asCString());
   if (deviceIt.getCurrentElement() == NULL) {
      throw MyException("DeviceXmlParser::parseDeviceXML() - Device file has no device tag");
   }
   // Process each <device> node
   for (;
         deviceIt.getCurrentElement() != NULL;
         deviceIt.advanceElement()) {

      isDefault = false; // Assume non-default device

      DOMElement *deviceEl = deviceIt.getCurrentElement();

      // Process <device> element attributes

#if defined FAMILY
#define MAKE_STRING(x) #x

      DualString familyValue(deviceEl->getAttribute(attr_family.asXMLString()));
      if (strcmp(FAMILY,familyValue.asCString()) != 0) {
//         log.print("Discarding %s not matching %s\n", (const char *)familyValue.asCString(), FAMILY);
         continue;
      }
#endif

      // Get device name. Note - Assumes ASCII string
      DualString targetName(deviceEl->getAttribute(attr_name.asXMLString()));
      setCurrentName(targetName.asCString());
      if (strlen(currentDeviceName) == 0) {
         throw MyException(string("DeviceXmlParser::parseDeviceXML() - Device name missing or invalid"));
      }
//      log.print("Parsing Device %s\n", targetName.asCString());
      if (deviceEl->hasAttribute(attr_alias.asXMLString())) {
         // Alias device
         DeviceDataPtr device = parseAlias(deviceEl);
         device->setTargetName(currentDeviceName);
         log.print("Adding Alias Device %s\n", targetName.asCString());
         deviceDataBase->addDevice(device);
      }
      else {
         // Real device
         if (deviceEl->hasAttribute(attr_isDefault.asXMLString())) {
            DualString value(deviceEl->getAttribute(attr_isDefault.asXMLString()));
            isDefault = XMLString::equals(value.asCString(), "true");
         }
         DualString subFamilyValue(deviceEl->getAttribute(attr_subFamily.asXMLString()));
         DualString speedValue(deviceEl->getAttribute(attr_speed.asXMLString()));
         DeviceDataPtr device = parseDevice(deviceEl);
         device->setTargetName(currentDeviceName);
         if (deviceEl->hasAttribute(attr_hidden.asXMLString())) {
            device->setHidden();
         }
         // Allow default devices without name - they are discarded
         if (isDefault) {
            // Discard default devices
            log.print("Discarding Device %s\n", targetName.asCString());
         }
         else {
            // Add general device
            log.print("Adding Device %s\n", targetName.asCString());
            deviceDataBase->addDevice(device);
         }
      }
   }
}

//! Load device file into device list
//!
//! @param deviceFilePath     - Path to XML file to load from
//! @param deviceDataBase   - Device database to update
//!
//! @return == 0 => success\n
//!         != 0 => fail
//!
void DeviceXmlParser::loadDeviceData(TargetType_t targetType, const std::string &deviceFilePath, DeviceDataBase *deviceDataBase) {
   LOGGING;
   log.setLoggingLevel(0); // Don't log below this level
   try {
      xercesc::XMLPlatformUtils::Initialize();
   }
   catch (...) {
      throw MyException("DeviceXmlParser::loadDeviceData((): Exception in XMLPlatformUtils::Initialize()");
   }
   std::shared_ptr<DeviceXmlParser> deviceXmlParser(new DeviceXmlParser(targetType, deviceDataBase));
   try {
      try {
         // Load the XML
         log.error("Loading XML file\n");
         deviceXmlParser->loadFile(deviceFilePath);
         // Parse shared information
         log.error("Parsing Shared XML\n");
         deviceXmlParser->parseSharedXML();
         // Parse device information
         log.error("Parsing Device XML\n");
         deviceXmlParser->parseDeviceXML();
      }
      catch (std::runtime_error &exception) {
         throw MyException(string(exception.what())+"\n   Current Device = "+deviceXmlParser->currentDeviceName);
      }
   }
   catch (MyException &exception) {
//      XMLPlatformUtils::Terminate();
      throw exception;
   }
   catch (...) {
      log.error("Unknown Exception\n");
//      XMLPlatformUtils::Terminate();
      // Translate other exceptions
      throw MyException("DeviceXmlParser::loadDeviceData() - Exception in loadFile(), parseSharedXML() or parseDeviceXML()\n");
   }
   //TODO - causes crash on function exit, allocation?
//   XMLPlatformUtils::Terminate();
}
