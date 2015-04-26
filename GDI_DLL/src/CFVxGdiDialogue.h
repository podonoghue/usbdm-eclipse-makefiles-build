/*
 * GdiDialogue.h
 *
 *  Created on: 25 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_CFVXGDIDIALOGUE_H_
#define SRC_CFVXGDIDIALOGUE_H_

#include "GdiDialogue.h"

class CFVxGdiDialogue: public GdiDialogue {

protected:
   virtual uint32_t getTargetProperties(TargetType_t targetType);
   virtual void OnOkClick( wxCommandEvent& event );

public:
   CFVxGdiDialogue(wxWindow* parent, BdmInterfacePtr bdmInterface);
   virtual ~CFVxGdiDialogue();

   USBDM_ErrorCode execute(AppSettings *appSettings);
};

#endif /* SRC_CFVXGDIDIALOGUE_H_ */
