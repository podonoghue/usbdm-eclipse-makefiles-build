/*
 * ProgressCallback.h
 *
 *  Created on: 4 Jun 2015
 *      Author: podonoghue
 */

#ifndef SRC_PROGRESSCALLBACKFACTORY_H_
#define SRC_PROGRESSCALLBACKFACTORY_H_

#include <memory>
#include <string.h>

#include "USBDM_API.h"

class ProgressDialogue {
protected:
   ProgressDialogue() {}

public:
   virtual ~ProgressDialogue() {}
   /**
    * Pulse the progress display
    *
    * @param message - optional new message to display
    */
   virtual bool pulse(std::string message="") = 0;
   /**
    * Update the progress display
    *
    * @param amount  - absolute progress level to set as a fraction of total
    * @param message - optional new message to display
    */
   virtual bool update(int amount, std::string message="") = 0;
   /**
    * Update the progress display
    *
    * @param amount  - relative progress level as a fraction of total
    * @param message - optional new message to display
    */
   virtual bool incrementalUpdate(int relativeAmount, std::string message="") = 0;
   /**
    * Update the progress display
    *
    * @param amount  - absolute progress level to set as a percentage
    * @param message - optional new message to display
    */
   virtual bool percentageUpdate(int percent, std::string message="") = 0;
   /**
    * Sets the maximum value of the progress indicator range
    *
    * @param maximum  - maximum value
    */
   virtual void setRange(int maximum) = 0;
   /**
    * Close the dialogue
    */
   virtual void close() = 0;
};

typedef std::shared_ptr<ProgressDialogue> ProgressDialoguePtr;

class ProgressDialogueFactory {
public:
   static ProgressDialoguePtr create(std::string title, uint32_t maximum, void *owner=0);
   static ProgressDialoguePtr create(uint32_t maximum, bool verbose, bool enableOutput = true);
};

#endif /* SRC_PROGRESSCALLBACKFACTORY_H_ */
