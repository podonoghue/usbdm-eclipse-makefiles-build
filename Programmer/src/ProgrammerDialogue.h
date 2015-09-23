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
   virtual uint32_t getTargetProperties(TargetType_t targetType);
   virtual void OnOkClick( wxCommandEvent& event );
//   virtual void OnCloseHandler( wxCloseEvent& event );

public:
   ProgrammerDialogue(wxWindow* parent, BdmInterfacePtr bdmInterface, DeviceInterfacePtr deviceInterface);
   virtual ~ProgrammerDialogue();

   bool setUpAndShow(wxString const &hexFilename=wxEmptyString);
};

#endif /* SRC_PROGRAMMERDIALOGUE_H_ */
