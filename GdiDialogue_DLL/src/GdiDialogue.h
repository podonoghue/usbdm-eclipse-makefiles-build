/*
 * FlashProgrammer.h
 *
 *  Created on: 8 Mar 2015
 *      Author: podonoghue
 */

#ifndef USBDM_DIALOGUE_H_
#define USBDM_DIALOGUE_H_

#include <wx/sound.h>
#include <wx/progdlg.h>

#include <vector>

#include "GdiDialogueSkeleton.h"

#include "AppSettings.h"
#include "BdmInterface.h"
#include "FlashProgrammerFactory.h"
#include "FlashImageFactory.h"
#include "USBDM_API.h"

class GdiDialogue : public GdiDialogueSkeleton {

private:
   class SecurityInfoEntry {
   public:
      SecurityInfoPtr       ptr;
      SecurityInfoConstPtr  resetValue;

      SecurityInfoEntry() {
         LOGGING_E;
         log.print("ptr.use_count()        = %ld\n", ptr.use_count());
         log.print("resetValue.use_count() = %ld\n", resetValue.use_count());
      }

      void resetToDefault() {
         ptr.reset(new SecurityInfo(*resetValue));
      }
   };

protected:
   //! Bit masks describing target properties appearing on dialogue
   enum {
      HAS_NONE                = 0,

      // Interface
      HAS_OPTIONAL_RESET      = 1<<1,  // Reset may be used optionally
      HAS_USE_PST             = 1<<2,  // PST signal may be used optionally (only CFVx)
      HAS_GUESS_SPEED         = 1<<3,  // Speed for mass erase may need to be optionally 'guessed'
      HAS_CLK_SW              = 1<<4,  // ALT & BUS clock options are available
      HAS_MASK_INTERRUPTS     = 1<<5,  // Option to mask interrupts when stepping is available
      HAS_SELECT_SPEED        = 1<<6,  // Connection speed may be selected

      // Target
      HAS_TRIM                = 1<<8,  // Device trim is supported
      HAS_BUS_FREQ            = 1<<9,  // Selection of Bus frequency for device without sync
      HAS_VLLS_RESET_CAPTURE  = 1<<10, // VLLS Reset capture
      HAS_MASS_ERASE          = 1<<11, // Device supports mass erase
      HAS_SELECTIVE_ERASE     = 1<<12, // Device supports selective erase
      HAS_PROBE_SECURED       = 1<<13, // Device ID may be read from secured device
      HAS_NVM_EEEPROM         = 1<<14, // Device has EEEPROM through NV
      HAS_SECURITY_FILE       = 1<<15, // Security options

      // Mode of dialogue
      IS_GDB_SERVER           = 1<<29, // GDB Server dialogue (GDB Port options)
      IS_GDI_DIALOGUE         = 1<<30, // GDI dialogue (??)
      IS_PROGRAMMER           = 1<<31, // Programmer dialogue (Load File + Program options)
   };

   static const uint32_t targetPropertyFlags[];

   // Handler for dialogue
   virtual void OnClose( wxCloseEvent& event );

   // Handlers for Interface page
   virtual void OnBdmSelectComboSelected( wxCommandEvent& event );
   virtual void OnRefreshBDMClick( wxCommandEvent& event );
   virtual void OnVddSelectBoxSelected( wxCommandEvent& event );
   virtual void OnCycleVddOnResetCheckboxClick( wxCommandEvent& event );
   virtual void OnCycleTargetVddOnConnectionCheckboxClick( wxCommandEvent& event );
   virtual void OnLeaveTargetOnCheckboxClick( wxCommandEvent& event );
   virtual void OnReconnectCheckboxClick( wxCommandEvent& event );
   virtual void OnUseResetCheckboxClick( wxCommandEvent& event );
   virtual void OnUseUsePstSignalCheckboxClick( wxCommandEvent& event );
   virtual void OnGuessSpeedCheckboxClick( wxCommandEvent& event );
   virtual void OnMaskInterruptsWhenSteppingCheckboxClick( wxCommandEvent& event );
   virtual void OnCatchVllsResetCheckboxClick( wxCommandEvent& event );
   virtual void OnConnectionTimeoutTextTextUpdated( wxCommandEvent& event );
   virtual void OnInterfaceSpeedSelectComboSelected( wxCommandEvent& event );
   virtual void OnBdmClockSelectRadioboxSelected( wxCommandEvent& event );

   // Handlers for Advanced page
   virtual void OnPowerOffDurationText( wxCommandEvent& event );
   virtual void OnPowerOnDurationText( wxCommandEvent& event );
   virtual void OnResetDurationText( wxCommandEvent& event );
   virtual void OnResetReleaseIntervalText( wxCommandEvent& event );
   virtual void OnResetRecoveryIntervalText( wxCommandEvent& event );

   virtual void OnDontShowAgainControlClick( wxCommandEvent& event );

   virtual void OnCancelClick( wxCommandEvent& event );
   virtual void OnOpenBdmClick( wxCommandEvent& event );

   static USBDM_ErrorCode progressCallBack(USBDM_ErrorCode status, int percent, const char *message);

   virtual uint32_t  getTargetProperties(TargetType_t targetType);

   virtual void      Init();
   bool              setDialogueValuesToDefault();
   bool              TransferDataToWindow();
   bool              TransferDataFromWindow();

   void              hideUnusedControls();
   void              addValidators();

   std::string       update();

   // Interface
   void              populateBDMChoices(void);
   void              populateInterfaceSpeeds();
   const wxString   &bdmGetDllVersion(void);

   void              findBDMs(void);

   BdmInterfacePtr               bdmInterface;
   std::vector<BdmInformation>   connectedBDMs;                      //!< Table of connected BDMs
   wxString                      bdmIdentification;                  //!< ID of current BDM
   int                           bdmDeviceNum;                       //!< Index of current BDM
   uint32_t                      targetProperties;                   //!< Properties describing target devices type
   bool                          dontShowDialogue;                   //!< Don't show dialogue in future

   HardwareCapabilities_t        bdmCapabilities;                    //!< Capabilities of the connected BDM

   static const std::string      settingsKey;                        //!< Key used for saving settings

public:
   GdiDialogue(wxWindow* parent, BdmInterfacePtr bdmInterface);
   virtual ~GdiDialogue();

   void loadSettings(const AppSettings &appSettings);
   void saveSettings(AppSettings &appSettings);

   USBDM_ErrorCode execute(AppSettingsPtr appSettings, bool forceDisplay=false);
};

#endif
