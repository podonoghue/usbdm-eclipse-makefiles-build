/*
 * MemoryDumpDialogue.h
 *
 *  Created on: 25 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_MEMORYDUMPDIALOGUE_H_
#define SRC_MEMORYDUMPDIALOGUE_H_

#include <stdint.h>
#include <stdio.h>

#include "USBDM_API.h"
#include "FlashImageFactory.h"
#include "BdmInterfaceFactory.h"

#include "MemoryDumpDialogueSkeleton.h"

class MemoryDumpDialogue : public MemoryDumpDialogueSkeleton {

protected:
  TargetType_t    targetType;
  FlashImagePtr   flashImage;
  BdmInterfacePtr bdmInterface;

  virtual void OnTargetTypeRadioBox( wxCommandEvent& event );
  virtual void OnSaveToFileButton( wxCommandEvent& event );
  virtual void OnReadMemoryButtonClick( wxCommandEvent& event );

  USBDM_ErrorCode readMemoryBlock(uint32_t address, uint32_t size);
  void writeStatus(const char *format, ...) __attribute__ ((format (printf, 2, 3)));
  void dumpSrec(FILE *, uint8_t *buffer, uint32_t address, unsigned size);
  void dump(FILE *file, uint8_t *buffer, uint32_t address, unsigned size);

  wxString      currentDirectory;

public:
   MemoryDumpDialogue(wxWindow* parent);
   virtual ~MemoryDumpDialogue();
};

#endif /* SRC_MEMORYDUMPDIALOGUE_H_ */
