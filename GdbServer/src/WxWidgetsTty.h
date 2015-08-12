/*
 * WxWidgetsTty.h
 *
 *  Created on: 18 Jul 2015
 *      Author: podonoghue
 */

#ifndef SRC_WXWIDGETSTTY_H_
#define SRC_WXWIDGETSTTY_H_

#include "IGdbTty.h"
#include <wx/textctrl.h>

class WxWidgetsTty: public IGdbTty {
protected:
   wxTextCtrl* statusTextControl;
   wxTextCtrl* entryTextControl;

public:
   WxWidgetsTty(wxTextCtrl* statusTextControl, wxTextCtrl* entryTextControl)
      : statusTextControl(statusTextControl), entryTextControl(entryTextControl) {
      entryTextControl->Disable();
   }

   virtual ~WxWidgetsTty() {
   }

   void putChar(int ch) {
      statusTextControl->AppendText((char)ch);
   }
   void puts(char *s) {
      statusTextControl->AppendText(wxString(s, wxConvUTF8));
   }
   int getChar() {
//      entryTextControl->Enable();
//      entryTextControl->Clear();
      return EOF;
   }
   int gets(char s[], int len) {
//      entryTextControl->Enable();
//      entryTextControl->Clear();
//      entryTextControl->SetFocus();
      s[0] = '\0';
      return 0;
   }

};

#endif /* SRC_WXWIDGETSTTY_H_ */
