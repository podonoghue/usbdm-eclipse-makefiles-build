/*
 * FlashProgrammerDialogue.h
 *
 *  Created on: 07/07/2010
 *      Author: pgo
 */

#ifndef NUMBERCONTROL_H_
#define NUMBERCONTROL_H_

#include <wx/wx.h>

class NumberTextEditCtrl : public wxTextCtrl {
public:

   NumberTextEditCtrl(wxWindow            *parent,
                      wxWindowID           id         = wxID_ANY,
                      const wxString      &value      = wxEmptyString,
                      const wxPoint       &pos        = wxDefaultPosition,
                      const wxSize        &size       = wxDefaultSize,
                      long int             style      = 0,
                      const wxValidator   &validator  = wxDefaultValidator,
                      const wxString      &name       = wxEmptyString) :
         wxTextCtrl(parent, id, value, pos, size, style, validator, name) {
      }

   NumberTextEditCtrl() :
         wxTextCtrl() {
      }

   void SetHexValue(unsigned int value) {
      wxString buff;
      buff.Printf(_("%X"), value);
      wxTextCtrl::ChangeValue(buff);
   }
   void SetDecimalValue(unsigned int value) {
      wxString buff;
      buff.Printf(_("%d"), value);
      wxTextCtrl::ChangeValue(buff);
   }
   void SetDoubleValue(float value) {
      wxString buff;
      buff.Printf(_("%.2f"), value);
      wxTextCtrl::ChangeValue(buff);
   }
   unsigned int GetHexValue() {
      wxString textValue = GetValue();
      long value = 0;
      textValue.ToLong(&value, 16);
      return value;
   }
   unsigned int GetDecimalValue() {
      wxString textValue = GetValue();
      long value = 0;
      textValue.ToLong(&value, 10);
      return value;
   }
   unsigned int GetDecimalValue(int low, int nominal, int high) {
      wxString textValue = GetValue();
      long value = 0;
      textValue.ToLong(&value, 10);
      if ((value < low) || (value>high))
         value = nominal;
      return value;
   }
   double GetDoubleValue() {
      wxString textValue = GetValue();
      double value;
      textValue.ToDouble(&value);
      return value;
   }
};

#endif /* NUMBERCONTROL_H_ */
