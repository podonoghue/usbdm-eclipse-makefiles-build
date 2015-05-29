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
#include "AppSettings.h"

class MemoryDumpDialogue : public MemoryDumpDialogueSkeleton {

protected:
  TargetType_t    targetType;
  FlashImagePtr   flashImage;
  BdmInterfacePtr bdmInterface;
  AppSettingsPtr  appSettings;

  virtual void OnTargetTypeRadioBox( wxCommandEvent& event );
  virtual void OnSaveToFileButton( wxCommandEvent& event );
  virtual void OnReadMemoryButtonClick( wxCommandEvent& event );

  USBDM_ErrorCode readMemoryBlocks();
  void clearStatus();
  void writeStatus(const char *format, ...) __attribute__ ((format (printf, 2, 3)));

  void loadSettings();
  void saveSettings();

  wxString      currentDirectory;
  wxString      currentFilename;

public:
   MemoryDumpDialogue(wxWindow* parent, AppSettingsPtr appSettings);
   virtual ~MemoryDumpDialogue();
   virtual int  ShowModal();
};

#endif /* SRC_MEMORYDUMPDIALOGUE_H_ */
