/*
 * GdbServerDialogue.h
 *
 *  Created on: 25 Mar 2015
 *      Author: podonoghue
 */

#ifndef GDBSERVER_SRC_GDBSERVERDIALOGUE_H_
#define GDBSERVER_SRC_GDBSERVERDIALOGUE_H_

#include "UsbdmDialogue.h"
#include "wx/utils.h"

class GdbServerDialogue: public UsbdmDialogue {

protected:
   virtual uint32_t getTargetProperties(TargetType_t targetType) override;

public:
   GdbServerDialogue(
         wxWindow            *parent,
         BdmInterfacePtr      bdmInterface,
         DeviceInterfacePtr   deviceInterface,
         AppSettings         &appSettings);
   virtual ~GdbServerDialogue();
};

#endif /* GDBSERVER_SRC_GDBSERVERDIALOGUE_H_ */
