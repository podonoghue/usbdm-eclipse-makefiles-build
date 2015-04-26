/*
 * TimeIntervalValidator.h
 *
 *  Created on: 13/12/2012
 *      Author: podonoghue
 */

#ifndef TIMEINTERVALVALIDATOR_H_
#define TIMEINTERVALVALIDATOR_H_

#include <wx/msgdlg.h>
#include <wx/validate.h>

class TimeIntervalValidator : public wxTextValidator {
   const char *name;
   unsigned   *value;
   unsigned    minValue, maxValue;

public:
   TimeIntervalValidator(const char *name, unsigned *value, unsigned minValue, unsigned maxValue) :
      wxTextValidator(wxFILTER_DIGITS, NULL),
      name(name),
      value(value),
      minValue(minValue),
      maxValue(maxValue) {
//      print("TimeIntervalValidator()\n");
   }
public:
   NumberTextEditCtrl *GetWindow() const {
      return static_cast<NumberTextEditCtrl *>(wxValidator::GetWindow());
   }
   bool Validate(wxWindow *parent) {
//      print("TimeIntervalValidator::Validate()\n");
      unsigned value = GetWindow()->GetDecimalValue();
      bool isOK = ((value>=minValue)&&(value<=maxValue));
      if(!isOK) {
         wxString msg = wxString::Format(_("Field \'%s\' is invalid\n"
                                           "Permitted range [%d to %d]"),
                                            name, minValue, maxValue);
         wxMessageBox(msg,_("Input field invalid"), wxOK, parent);
      }
      return isOK;
   }
   bool TransferToWindow() {
//      print("TimeIntervalValidator::TransferToWindow()\n");
      if (*value<minValue) {
         *value = minValue;
      }
      if (*value>maxValue) {
         *value = maxValue;
      }
      GetWindow()->SetDecimalValue(*value);
      return true;
   }
   bool TransferFromWindow() {
//      print("TimeIntervalValidator::TransferFromWindow()\n");
      if (!Validate(NULL)) {
         return false;
      }
      *value = GetWindow()->GetDecimalValue();
      return true;
   }
   //! @param name  Assumed to be a statically allocated string and is used by reference
   //! @param value Value to set
   void setObject(const char *name, unsigned *value) {
      this->name  = name;
      this->value = value;
   }
   void setMin(unsigned _minValue) {
      minValue = _minValue;
   }
   void setMax(unsigned _maxValue) {
      maxValue = _maxValue;
   }
   wxObject *Clone(void) const {
//      print("Clone()\n");
      return new TimeIntervalValidator(this->name, this->value, this->minValue, this->maxValue);
   }
};

#endif /* TIMEINTERVALVALIDATOR_H_ */
