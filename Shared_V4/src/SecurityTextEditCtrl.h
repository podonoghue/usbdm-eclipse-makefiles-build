/*
 * FlashProgrammerDialogue.h
 *
 *  Created on: 07/07/2010
 *      Author: pgo
 */

#ifndef SECURITYCONTROL_H_
#define SECURITYCONTROL_H_

#include <string>
#include <wx/wx.h>

#include "UsbdmSystem.h"

class SecurityTextEditCtrl : public wxTextCtrl {
private:
   virtual void SetMaxLength(unsigned long len) {
      wxTextCtrl::SetMaxLength(len);
   }
   unsigned fWidth;  // Width in bytes

public:

   SecurityTextEditCtrl(wxWindow         *parent,
                      wxWindowID          id          = wxID_ANY,
                      const wxString      &value      = wxEmptyString,
                      const wxPoint       &pos        = wxDefaultPosition,
                      const wxSize        &size       = wxDefaultSize,
                      long int             style      = 0,
                      const wxValidator   &validator  = wxDefaultValidator,
                      const wxString      &name       = wxEmptyString) :
         wxTextCtrl(parent, id, value, pos, size, style, validator, name),
         fWidth(16) {
      wxTextCtrl::SetMaxLength(32);
   }

   SecurityTextEditCtrl() :
         wxTextCtrl(),
         fWidth(16) {
      wxTextCtrl::SetMaxLength(32);
   }

   /**!
    * Set width in bytes
    *
    * @param width Width in bytes of security field
    */
   void setWidth(int width) {
      LOGGING_Q;
      log.print("width (in bytes) = %d\n" , width);
      fWidth = width;
      SetMaxLength(2*width);
   }

   /*!
    * Set maximum width in characters of text entry
    */
   void SetSecurityValue(std::string value) {
      wxString buff;
      buff.Printf(_("%X"), value);
      wxTextCtrl::ChangeValue(buff);
   }

   //!
   //! @return value from control as zero-padded on the right string
   //!
   const std::string getHexValues() {
      char buf[2*fWidth+1];
      memset(buf, '0', sizeof(buf));

      wxString value = GetValue();
      unsigned len   = value.length();
      if (len>(sizeof(buf)-1)) {
         // Discard if too long (should be impossible)
         len = sizeof(buf)-1;
      }
      memcpy(buf, (const char *)GetValue().mb_str(wxConvUTF8), len );
      buf[len]           = '0';  // Remove string termination
      buf[sizeof(buf)-1] = '\0'; // Make sure entire string is terminated

      UsbdmSystem::Log::print("Size = %d, Value = \'%s\'\n", fWidth, buf);
      return  std::string(buf);
   }
};

#endif /* SECURITYCONTROL_H_ */
