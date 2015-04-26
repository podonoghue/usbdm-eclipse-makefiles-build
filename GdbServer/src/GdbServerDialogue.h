/*
 * GdbServerDialogue.h
 *
 *  Created on: 25 Mar 2015
 *      Author: podonoghue
 */

#ifndef GDBSERVER_SRC_GDBSERVERDIALOGUE_H_
#define GDBSERVER_SRC_GDBSERVERDIALOGUE_H_

#include "UsbdmDialogue.h"

class GdbServerDialogue: public UsbdmDialogue {
protected:
   virtual uint32_t  getTargetProperties(TargetType_t targetType);
   virtual void      OnKeepChangesClick( wxCommandEvent& event );
   virtual void      OnDiscardChangesClick( wxCommandEvent& event );

public:
   GdbServerDialogue(wxWindow* parent, BdmInterfacePtr bdmInterface, DeviceInterfacePtr deviceInterface);
   virtual ~GdbServerDialogue();

   USBDM_ErrorCode execute(AppSettingsPtr appSettings, bool reloadSettings=true);
};

#endif /* GDBSERVER_SRC_GDBSERVERDIALOGUE_H_ */
