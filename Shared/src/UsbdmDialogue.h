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

#include "UsbdmDialogueSkeleton.h"

#include "BdmInterface.h"
#include "FlashProgrammerFactory.h"
#include "DeviceInterface.h"
#include "FlashImageFactory.h"
#include "USBDM_API.h"

class UsbdmDialogue: public UsbdmDialogueSkeleton {

private:
   class SecurityInfoEntry {

   public:
      SecurityInfoPtr       ptr;
      SecurityInfoConstPtr  resetValue;

      SecurityInfoEntry() {
         LOGGING_Q;
//         log.print("ptr.use_count()        = %ld\n", ptr.use_count());
//         log.print("resetValue.use_count() = %ld\n", resetValue.use_count());
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
      HAS_OPTIONAL_RESET      = 1<<1,  // Hardware reset may be used optionally (e.g. HCS08)
      HAS_USE_PST             = 1<<2,  // PST signal may be used optionally (only CFVx)
      HAS_GUESS_SPEED         = 1<<3,  // Connection speed may need to be optionally 'guessed'
      HAS_CLK_SW              = 1<<4,  // ALT & BUS clock options are available
      HAS_MASK_INTERRUPTS     = 1<<5,  // Option to mask interrupts when stepping is available
      HAS_SELECT_SPEED        = 1<<6,  // Connection speed may be selected

      // Target
      HAS_TRIM                = 1<<8,  // Device trim is supported
      HAS_VLLS_RESET_CAPTURE  = 1<<10, // VLLS Reset capture
      HAS_MASS_ERASE          = 1<<11, // Device supports mass erase
      HAS_SELECTIVE_ERASE     = 1<<12, // Device supports selective erase
      HAS_PROBE_SECURED       = 1<<13, // Device ID may be read from secured device
      HAS_NVM_EEEPROM         = 1<<14, // Device has EEEPROM through NV
      HAS_SECURITY_FILE       = 1<<15, // Security options
      HAS_RESET_CHOICES       = 1<<16, // Reset has multiple methods (e.g. kinetis)
      HAS_SOUNDS              = 1<<17, // Sounds option
      HAS_LINEAR_IMAGE        = 1<<18, // Force image to be linear even though only paged address programming supported

      // Mode of dialogue
      IS_GDB_SERVER           = 1<<29, // GDB Server dialogue (GDB Port options)
      IS_GDI_DIALOGUE         = 1<<30, // GDI dialogue (??)
      IS_PROGRAMMER           = 1<<31, // Programmer dialogue (Load File + Program options)
   };

   static const uint32_t targetPropertyFlags[];

//   virtual void OnClose( wxCloseEvent&  event ) override;
//   virtual void OnOkClick( wxCommandEvent&  event ) override;

   // Handlers for Interface page
   virtual void OnBdmSelectComboSelected( wxCommandEvent&  event ) override;
   virtual void OnRefreshBDMClick( wxCommandEvent&  event ) override;
   virtual void OnVddSelectBoxSelected( wxCommandEvent&  event ) override;
   virtual void OnCycleVddOnResetCheckboxClick( wxCommandEvent&  event ) override;
   virtual void OnCycleTargetVddOnConnectionCheckboxClick( wxCommandEvent&  event ) override;
   virtual void OnLeaveTargetOnCheckboxClick( wxCommandEvent&  event ) override;
   virtual void OnAutoConnectStrategyComboSelected( wxCommandEvent&  event ) override;
   virtual void OnUseResetCheckboxClick( wxCommandEvent&  event ) override;
   virtual void OnUseUsePstSignalCheckboxClick( wxCommandEvent&  event ) override;
   virtual void OnGuessSpeedCheckboxClick( wxCommandEvent&  event ) override;
   virtual void OnMaskInterruptsWhenSteppingCheckboxClick( wxCommandEvent&  event ) override;
   virtual void OnCatchVllsResetCheckboxClick( wxCommandEvent&  event ) override;
   virtual void OnConnectionTimeoutTextTextUpdated( wxCommandEvent&  event ) override;
   virtual void OnInterfaceSpeedSelectComboSelected( wxCommandEvent&  event ) override;
   virtual void OnBdmClockSelectRadioboxSelected( wxCommandEvent&  event ) override;

   // Handlers for Target page
   virtual void OnLoadFileButtonClick( wxCommandEvent&  event ) override;
   virtual void OnLinearImageCheckboxClick( wxCommandEvent&  event ) override;
   virtual void OnIncrementalFileLoadCheckboxClick( wxCommandEvent&  event ) override;
   virtual void OnAutoFileReloadCheckboxClick( wxCommandEvent&  event ) override;
   virtual void OnDeviceTypeChoiceSelected( wxCommandEvent&  event ) override;
   virtual void OnFilterByChipIdCheckboxClick( wxCommandEvent&  event ) override;
   virtual void OnDetectChipButtonClick( wxCommandEvent&  event ) override;
   virtual void OnNonvolatileAddressTextTextUpdated( wxCommandEvent&  event ) override;
   virtual void OnTrimFrequencyTextTextUpdated( wxCommandEvent&  event ) override;
   virtual void OnTrimFrequencyCheckboxClick( wxCommandEvent& event ) override;
   virtual void OnBusFrequencyTextTextUpdated( wxCommandEvent& event ) override;
   virtual void OnSecurityRadioboxSelected( wxCommandEvent& event ) override;
   virtual void OnMassEraseButtonClick( wxCommandEvent& event ) override;
   virtual void OnUnlockButtonClick( wxCommandEvent& event ) override;
   virtual void OnSoundCheckboxClick( wxCommandEvent& event ) override;
   virtual void OnGdbServerPortNumberTextUpdated( wxCommandEvent& event ) override;
   virtual void OnGdbTtyPortNumberTextUpdated( wxCommandEvent& event ) override;
   virtual void OnProgramFlashButtonClick( wxCommandEvent& event ) override;
   virtual void OnVerifyFlashButtonClick( wxCommandEvent& event ) override;
   virtual void OnLoadAndGoButtonClick( wxCommandEvent& event ) override;

   // Handlers for Advanced page
   virtual void OnEeepromSizeChoiceSelected( wxCommandEvent& event ) override;
   virtual void OnFlexNvmPartionChoiceSelected( wxCommandEvent& event ) override;
   virtual void OnSecurityMemoryRegionChoiceSelected( wxCommandEvent& event ) override;
   virtual void OnResetCustomValueClick( wxCommandEvent& event ) override;
   virtual void OnSecurityEditUpdate(wxCommandEvent& event) override;
   virtual void OnSecurityCheckboxClick( wxCommandEvent& event ) override;
   virtual void OnPowerOffDurationText( wxCommandEvent& event ) override;
   virtual void OnPowerOnDurationText( wxCommandEvent& event ) override;
   virtual void OnResetDurationText( wxCommandEvent& event ) override;
   virtual void OnResetReleaseIntervalText( wxCommandEvent& event ) override;
   virtual void OnResetRecoveryIntervalText( wxCommandEvent& event ) override;
   virtual void OnClose( wxCloseEvent& event ) override;
   virtual void onCloseButton( wxCommandEvent& event ) override;
   virtual void OnKeepChangesClick( wxCommandEvent& event );
   virtual void OnDiscardChangesClick( wxCommandEvent& event );

   static USBDM_ErrorCode progressCallBack(USBDM_ErrorCode status, int percent, const char *message);

   /**
    * Get properties of target type
    *
    * @return Bit-mask describing properties
    */
   virtual uint32_t        getTargetProperties(TargetType_t targetType);
   void                    failBeep();

   virtual void            Init();
   bool                    setDialogueValuesToDefault();
   bool                    TransferDataToWindow();
   bool                    TransferDataFromWindow();

   void                    hideUnusedControls();
   void                    addValidators();

   std::string             update();

   DeviceData::EraseMethod getCurrentEraseSelection();
   void                    setCurrentEraseSelection(DeviceData::EraseMethod eraseMethod);
   DeviceData::ResetMethod getCurrentResetSelection();
   void                    setCurrentResetSelection(DeviceData::ResetMethod eraseMethod);

   // Interface
   void                    populateBDMChoices(void);
   void                    populateInterfaceSpeeds();
   void                    populateConnectionStrategyControl();
   const wxString   &      bdmGetDllVersion(void);
   void                    updateFilterDescription();
   void                    findBDMs(void);

   // Target
   void                    populateDeviceDropDown();
   void                    populateEraseControl();
   void                    populateResetControl();
   const wxString          makeDeviceName(const wxString& targetName);
   USBDM_ErrorCode         massEraseTarget();
   void                    reportError(USBDM_ErrorCode rc);

   void                    setDeviceIndex(int newDeviceIndex);
   USBDM_ErrorCode         autoDetectTargetDevice(void);
   USBDM_ErrorCode         loadHexFile( wxString hexFilename,
                                        bool clearBuffer,
                                        FlashImage::SrecMode srecMode=FlashImage::SrecMode::noConversion);
   USBDM_ErrorCode         checkFileChange(void);
   USBDM_ErrorCode         programFlash(bool loadAndGo = false);
   USBDM_ErrorCode         verifyFlash(void);
   USBDM_ErrorCode         hcs12Check(void);

   USBDM_ErrorCode         vddCheck(DeviceDataPtr device);

   // Advanced
   void                    populateEeepromControl();
   void                    populatePartitionControl();
   void                    populateSecurityControl();

   int                     findEeepromSizeIndex(unsigned eepromSize);
   int                     findPartitionControlIndex(unsigned backingStoreSize);
   void                    updateFlashNVM();
   wxString                parseSecurityValue();
   void                    updateSecurityDescription();
   void                    updateSecurity();

   BdmInterfacePtr               bdmInterface;                       //!< Interface to the BDM
   DeviceInterfacePtr            deviceInterface;                    //!< Device interface

   std::vector<BdmInformation>   connectedBDMs;                      //!< Table of connected BDMs
   wxString                      bdmIdentification;                  //!< ID of current BDM
   int                           bdmDeviceNum;                       //!< Index of current BDM in BDM table and drop-down
   uint32_t                      targetProperties;                   //!< Properties describing target devices type

   bool                          deviceChanged;                      //!< Indicates an update is required due to a device change
   bool                          doFilterByChipId;                   //!< For dialogue handling - Filter by SDID
   std::map<uint32_t,uint32_t>   filterChipIds;                      //!< The SDIDs being filtered by
   bool                          incrementalLoad;                    //!< Don't clear buffer when loading a file
   FlashImage::SrecMode          forcelinearToPagedImage;            //!< How to handle SRC files
   bool                          autoFileLoad;                       //!< Auto load changed files before programming
   DeviceData::EraseMethod       initialEraseMethod;                 //!< Initial erase setting loaded
   DeviceData::ResetMethod       initialResetMethod;                 //!< Initial reset setting loaded
   bool                          fileLoaded;                         //!< Flag indicating Hex file loaded
   bool                          doTrim;                             //!< Trim target clock (if possible)
   bool                          needManualFrequencySet;             //!< Connection speed has been manually set
   bool                          sound;                              //!< Sound on/off
   time_t                        fileLoadTime;                       //!< Time last file was loaded
   wxString                      lastFileLoaded;                     //!< Path to last file loaded
   wxString                      cumulativeFilesLoaded;              //!< Names of files loaded
   HardwareCapabilities_t        bdmCapabilities;                    //!< Capabilities of the connected BDM
   FlashProgrammerPtr            flashprogrammer;                    //!< Flash programmer
   FlashImagePtr                 flashImage;                         //!< Memory Image loaded from S1S9 files.
   wxSound                      *beep;

   static wxProgressDialog      *progressDialogue;                   //!< Progress dialogue while programming
   static const std::string      settingsKey;                        //!< Key used for saving settings

   // Advanced Panel
   int                           eeepromSizeChoice;                  //!< Choice for eeepromSizeChoice control & index for eeepromSizeValues[]
   int                           flexNvmPartitionIndex;              //!< Index for flexNvmPartitionValues[]

   static const int              maxSecurityNum = 4;                 //!<
   SecurityInfoEntry             customSecurityInfo[maxSecurityNum]; //!< Custom security information (if any) for each memory region
   unsigned                      customSecurityIndex;                //!< Index for current customSecurityInfo[]

   SecurityInfoConstPtr          securityInfoPtr;                    //!< Security information for the current memory region
   SecurityDescriptionConstPtr   securityDescriptionPtr;             //!< How to parse security value
   SecurityOptions_t             lastSecurityOption;                 //!< Last security option before selecting custom

   wxString                      currentDirectory;                   //!< Current directory for file

   USBDM_ErrorCode               modalReturnValue = BDM_RC_FAIL;     //!< Value to return from showModal()

protected:
   AppSettings &appSettings;

public:
   UsbdmDialogue(
         wxWindow            *parent,
         const wxString      &title,
         BdmInterfacePtr      bdmInterface,
         DeviceInterfacePtr   deviceInterface,
         AppSettings         &appSettings);
   virtual ~UsbdmDialogue();

   void loadSettings();
   void saveSettings();
   USBDM_ErrorCode execute();
   USBDM_ErrorCode execute(wxString const &hexFilename);

};

#endif
