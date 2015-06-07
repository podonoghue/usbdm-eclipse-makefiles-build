/*
 * ProgressCallback.cpp
 *
 *  Created on: 4 Jun 2015
 *      Author: podonoghue
 */

#include <wx/progdlg.h>

#include "ProgressDialogueFactory.h"
#include "UsbdmSystem.h"

class ProgressCallbackImp : public ProgressDialogue {
private:
   uint32_t          maximum;
   uint32_t          cumulative;
   int               percent;
   wxProgressDialog  progressDialogue;

   void calculatePercent(int value) {
      cumulative = value;
      double percentage = (100.0*value)/maximum;
      percent = (int)round(percentage);
      if (percent >= 100) {
         percent = 99;
      }
   }

public:
   ProgressCallbackImp(std::string title, uint32_t maximum, wxWindow *owner = 0) : maximum (maximum), cumulative(0), percent(0),
   progressDialogue(title, _(""), 100, owner, wxPD_APP_MODAL|wxPD_ELAPSED_TIME)
   {
//      LOGGING;
   }
   ~ProgressCallbackImp() {
      LOGGING;
      close();
   }

   bool pulse(std::string message="") {
//      LOGGING;
      return progressDialogue.Pulse(message);
   }
   bool update(int amount, std::string message="") {
//      LOGGING;
      calculatePercent(amount);
//      log.print("cumulativeBytes = %d/%d\n", cumulative, maximum);
      return progressDialogue.Update(percent, message);
   }

   bool incrementalUpdate(int relativeAmount, std::string message="") {
      return update(cumulative + relativeAmount, message);
   }

   bool percentageUpdate(int percent, std::string message="") {
      this->percent = percent;
      return progressDialogue.Update(percent, message);
   }
   void setRange(int maximum) {
      this->maximum = maximum;
   }
   void close() {
//      LOGGING;
      progressDialogue.Show(false);
      progressDialogue.Close();
   }
};

ProgressDialoguePtr ProgressDialogueFactory::create(std::string title, uint32_t maximum, void *owner) {
   return ProgressDialoguePtr(new ProgressCallbackImp(title, maximum, (wxWindow*)owner));
}
