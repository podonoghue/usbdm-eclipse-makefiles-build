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

class ConsoleProgressDialogue : public ProgressDialogue {
private:
   uint32_t          maximum;
   uint32_t          cumulative;
   int               currentPercent;
   int               previousPercent;
   std::string       updateMessage;
   bool              verbose;
   bool              outputEnabled;

   void calculatePercent(int value) {
      cumulative = value;
      double percentage = (100.0*value)/maximum;
      currentPercent = (int)round(percentage);
      if (currentPercent >= 100) {
         currentPercent = 99;
      }
   }

   bool update(std::string message, bool newUpdateEntry){
	   if(newUpdateEntry){
		   if(previousPercent != -1 && !updateMessage.empty()){
			   fprintf(stdout, "%s complete\n", updateMessage.c_str()); //last update is completed
		   }
	       previousPercent = -1;
	       updateMessage = message;
	       if(!updateMessage.empty()){
	    	   fprintf(stdout, "%s\n", updateMessage.c_str());
	       }
	   }
	   else{
		   if(!message.empty()){
			   updateMessage = message;
		   }

		   if(previousPercent != currentPercent && !updateMessage.empty()){
			   fprintf(stdout, "%d%%: %s\n", currentPercent, updateMessage.c_str());
		   }
	   }
	   previousPercent = currentPercent;
	   return true;
   }

public:
   ConsoleProgressDialogue(uint32_t maximum, bool verbose, bool enableOutput):
	   maximum(maximum), cumulative(0),
	   currentPercent(0), previousPercent(-1),
	   verbose(verbose), outputEnabled(enableOutput)
    {
//      LOGGING;
    }
   ~ConsoleProgressDialogue() {}

   bool pulse(std::string message=""){
	   if(outputEnabled && !message.empty()){
		   fprintf(stdout, "%s\n", message.c_str());
	   }
	   return true;
   }

   bool update(int amount, std::string message=""){
	   if(!outputEnabled){
	   	  return true;
	   }
	   if(!verbose){
	      if(!message.empty()){ // print any non-empty message and return
	         fprintf(stdout, "%s\n", message.c_str());
	      }
	      return true;
	   }
	   calculatePercent(amount);
	   return update(message, true);
   }

   bool incrementalUpdate(int relativeAmount, std::string message=""){
	   if(!verbose || !outputEnabled){
		   return true;
	   }
	   calculatePercent(cumulative + relativeAmount);
	   return update(message, false);
   }

   bool percentageUpdate(int percent, std::string message=""){
	   if(!outputEnabled){
		   return true;
	   }
	   if(!verbose){
		   if(percent == 0 && !message.empty()){
			   fprintf(stdout, "%s\n", message.c_str());
		   }
		   return true;
	   }
	   this->currentPercent = percent;
	   updateMessage = message.empty() ? updateMessage : message;
	   if(previousPercent != currentPercent){
		  fprintf(stdout, "%d%%: %s\n", currentPercent, updateMessage.c_str());
	   }
	   previousPercent = currentPercent;
	   return true;
   }

   void setRange(int maximum){this->maximum = maximum;}

   void close(){
	   if(!verbose || !outputEnabled){
		   return;
	   }
	   if(!updateMessage.empty()){
		   fprintf(stdout, "%s complete\n", updateMessage.c_str());
	   }
   }
};

ProgressDialoguePtr ProgressDialogueFactory::create(std::string title, uint32_t maximum, void *owner) {
   return ProgressDialoguePtr(new ProgressCallbackImp(title, maximum, (wxWindow*)owner));
}

ProgressDialoguePtr ProgressDialogueFactory::create(uint32_t maximum, bool verbose, bool enableOutput){
	return ProgressDialoguePtr(new ConsoleProgressDialogue(maximum, verbose, enableOutput));
}
