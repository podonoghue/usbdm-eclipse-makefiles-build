/*
 * SecurityValidator.h
 *
 *  Created on: 13/12/2012
 *      Author: podonoghue
 *
 * History
 * =================================================================================================
 * 14/01/2013 - Changed to only require wxWidgets 2.8                                         4.10.4
 * =================================================================================================
 */

#ifndef SECURITYVALIDATOR_H_
#define SECURITYVALIDATOR_H_

#include <string.h>
#include <wx/validate.h>
#include <wx/valtext.h>

#include "DeviceData.h"

class SecurityValidator : public wxTextValidator {
   bool              enabled;                //! Controls if validation is done
   SecurityInfoPtr   securityInfoPtr;        //! Security information to maintain & use
   wxArrayString     acceptedCharacters;

public:
   SecurityValidator(SecurityInfoPtr securityInfoPtr) :
      wxTextValidator(wxFILTER_INCLUDE_CHAR_LIST, NULL),
      enabled(false),
      securityInfoPtr(securityInfoPtr){
      LOGGING_E;
      init();
      SetIncludes(acceptedCharacters);
   }
   SecurityValidator(const SecurityValidator &other) :
      wxTextValidator(wxFILTER_INCLUDE_CHAR_LIST, NULL),
      enabled(other.enabled),
      securityInfoPtr(other.securityInfoPtr) {
      LOGGING_E;
      init();
      SetIncludes(acceptedCharacters);
   }

private:
   void init(void) {
      if (acceptedCharacters.IsEmpty()) {
         acceptedCharacters.Add(_("0"));
         acceptedCharacters.Add(_("1"));
         acceptedCharacters.Add(_("2"));
         acceptedCharacters.Add(_("3"));
         acceptedCharacters.Add(_("4"));
         acceptedCharacters.Add(_("5"));
         acceptedCharacters.Add(_("6"));
         acceptedCharacters.Add(_("7"));
         acceptedCharacters.Add(_("8"));
         acceptedCharacters.Add(_("9"));
         acceptedCharacters.Add(_("A"));
         acceptedCharacters.Add(_("B"));
         acceptedCharacters.Add(_("C"));
         acceptedCharacters.Add(_("D"));
         acceptedCharacters.Add(_("E"));
         acceptedCharacters.Add(_("F"));
         acceptedCharacters.Add(_("a"));
         acceptedCharacters.Add(_("b"));
         acceptedCharacters.Add(_("c"));
         acceptedCharacters.Add(_("d"));
         acceptedCharacters.Add(_("e"));
         acceptedCharacters.Add(_("f"));
      }
   }

public:
   wxTextCtrl *GetWindow() const {
      wxTextCtrl *win = dynamic_cast<wxTextCtrl *>(wxValidator::GetWindow());
      if (win == NULL) {
         throw MyException("SecurityValidator::GetWindow() - window must be associated first");
      }
      return win;
   }

   //! Get value from associated text control
   //!
   //! @return value from control as zero-padded string
   //!
   const std::string getHexValues() {
      LOGGING;
      wxTextCtrl *win = GetWindow();
      int len = win->GetValue().length(); // in characters
      if (securityInfoPtr == NULL) {
         throw MyException("getHexValues() - securityInfoPtr == NULL!");
      }
      int size = securityInfoPtr->getSize(); // size in bytes
      if (len>(2*size)) {
         len = 2*size;
      }
      char buf[2*size+1];
      memset(buf, '0', sizeof(buf));
      memcpy(buf, (const char*)win->GetValue().mb_str(wxConvUTF8), len );
      buf[2*size] = '\0';
      log.print("Size = %d, Value = \'%s\'\n", size, buf);
      return  std::string(buf);
   }

   //! @param value Value to set
   void setObject(SecurityInfoPtr securityInfoPtr) {
      this->securityInfoPtr = securityInfoPtr;
      wxTextCtrl *win = GetWindow();
      if (securityInfoPtr != NULL) {
         win->SetMaxLength(2*securityInfoPtr->getSize());
      }
   }

   wxObject *Clone(void) const {
      LOGGING_E;
      return new SecurityValidator(*this);
   }

   //! Enable or disable validation
   //!
   //! @param enabled  true to enable validation
   //!
   void enable(bool enabled) {
      LOGGING_E;
      this->enabled = enabled;
   }
};

#endif /* SECURITYVALIDATOR_H_ */
