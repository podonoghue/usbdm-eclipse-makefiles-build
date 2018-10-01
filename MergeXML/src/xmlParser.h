/*
 * xmlParser.h
 *
 *  Created on: 22/12/2010
 *      Author: podonoghue
 */

#ifndef XMLPARSER_H_
#define XMLPARSER_H_

#include <wx/wx.h>
#include <wx/string.h>

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMComment.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/sax/HandlerBase.hpp>

#include "helper-classes.h"

class XmlParser {

private:
   DualString attr_merge_actions;

   xercesc::ErrorHandler*    errHandler;

   xercesc::XercesDOMParser* mergeParser;
   xercesc::DOMDocument*     mergeDocument;

   xercesc::XercesDOMParser* patchParser;
   xercesc::DOMDocument*     patchDocument;
   static bool      verbose;
   bool  mergeDone;

private:
   XmlParser() :
      attr_merge_actions("merge-actions"),

      errHandler(NULL),

      mergeParser(NULL),
      mergeDocument(NULL),

      patchParser(NULL),
      patchDocument(NULL)
   {
      mergeDone = false;
   }

   ~XmlParser() {
//      cerr << "~XmlParser()\n";
      delete mergeParser;
      delete patchParser;
      delete errHandler;
   }

private:
   typedef enum {scan, insert, replace, mergeAttrs} Actions;

   int modifyNewProjectWizardXML(xercesc::DOMElement *el);
   int modifyWizardUIXML(xercesc::DOMElement *el);
   int modifyWizardUIXMLPage(xercesc::DOMElement *el);
   int modifyWizardUIXMLCondition(xercesc::DOMNode *el);
   int addLaunchSetting( xercesc::DOMElement *el,
                         const char *conditionId,
                         const char *configurationId,
                         const char *name,
                         const char *projectType);
   int addLaunchSettings(xercesc::DOMElement *el);
   int addLaunchSettingsRefs(xercesc::DOMElement *el);
   int addLaunchSettingsRef( xercesc::DOMElement *configuration,
                             const char *id);
   int addcheckBoxItem(xercesc::DOMElement *uiElement, const char *id );

   void  load(xercesc::XercesDOMParser* &parser, xercesc::DOMDocument* &document, const char* xmlFile);
   int   mergePatchfile();
   int   loadSourcefile(const char *sourcePath);
   int   loadPatchfile(const char *patchPath);
   int   commit(const char* xmlFile);
   bool  mergeNodes(xercesc::DOMElement *mergeEl, xercesc::DOMElement *patchEl);
   bool  nodesMatch(xercesc::DOMElement *mergeEl, xercesc::DOMElement *patchEl);
   void  processAttributes(xercesc::DOMElement *mergeEl, xercesc::DOMElement *patchEl);
   Actions getAction(xercesc::DOMElement *mergeEl);
   xercesc::DOMElement *removeActionAttributes(xercesc::DOMElement *patchEl);
   xercesc::DOMComment *getCommentNode(xercesc::DOMElement *element);

public:
   static int addUsbdmWizard(const wxString& sourcePath, const wxString& patchPath);
};

#endif /* XMLPARSER_H_ */
