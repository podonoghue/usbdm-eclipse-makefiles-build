/*
 * ProgrammerDialogue.h
 *
 *  Created on: 25 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_PROGRAMMERDIALOGUE_H_
#define SRC_PROGRAMMERDIALOGUE_H_

#include "UsbdmDialogue.h"

class ProgrammerDialogue : public UsbdmDialogue {

protected:
   virtual uint32_t getTargetProperties(TargetType_t targetType) override;

public:
   ProgrammerDialogue(
         wxWindow            *parent,
         const char          *title,
         BdmInterfacePtr      bdmInterface,
         DeviceInterfacePtr   deviceInterface,
         AppSettings         &appSettings);
   virtual ~ProgrammerDialogue();
};

#endif /* SRC_PROGRAMMERDIALOGUE_H_ */
