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
#include "ProgressDialogueFactory.h"

class MemoryDumpDialogue : public MemoryDumpDialogueSkeleton {

protected:
  TargetType_t                targetType;
  FlashImagePtr               flashImage;
  BdmInterfacePtr             bdmInterface;
  AppSettingsPtr              appSettings;
  std::vector<BdmInformation> connectedBDMs;       //!< Table of connected BDMs
  int                         bdmDeviceNum;        //!< Index of current BDM in BDM table and drop-down
  wxString                    bdmIdentification;   //!< ID of current BDM
  HardwareCapabilities_t      bdmCapabilities;     //!< Capabilities of the connected BDM

  virtual void OnTargetTypeRadioBoxSelect( wxCommandEvent& event );
  virtual void OnBdmSelectComboSelected( wxCommandEvent& event );
  virtual void OnRefreshBDMClick( wxCommandEvent& event );
  virtual void OnTargetVddControlClick( wxCommandEvent& event );
  virtual void OnSaveToFileButton( wxCommandEvent& event );
  virtual void OnReadMemoryButtonClick( wxCommandEvent& event );
  virtual void OnKeepEmptySRECsCheckboxClick( wxCommandEvent& event );
  virtual void OnInterfaceSpeedSelectComboSelected( wxCommandEvent& event );
  virtual void onLinearAddressingClick( wxCommandEvent& event );
  virtual void populateBDMChoices();
  virtual void populateInterfaceSpeeds();
  virtual void update();


  void setTargetType(TargetType_t targetType);
  TargetType_t getTargetType();
  void setVdd(TargetVddSelect_t targetVdd);
  TargetVddSelect_t getVdd();
  void setInterfaceSpeed(signed speed);
  unsigned getInterfaceSpeed();

  USBDM_ErrorCode readMemoryBlocks(ProgressDialoguePtr progress);

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
