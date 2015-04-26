/////////////////////////////////////////////////////////////////////////////
// Name:        bootloaderdialogue.h
// Purpose:
// Author:      Peter O'Donoghue
// Modified by:
// Created:     Tue 06 Jul 2010 09:57:47 EST
// RCS-ID:
// Copyright:   GPL License
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _BOOTLOADERDIALOGUE_H_
#define _BOOTLOADERDIALOGUE_H_

/*!
 * Includes
 */
#include <wx/wx.h>
#include "Common.h"
#include "AppSettings.h"
#include "NumberTextEditCtrl.h"
#include "USBDM_API.h"

/*!
 * Control identifiers
 */
#define SYMBOL_BOOTLOADERDIALOGUE_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_BOOTLOADERDIALOGUE_TITLE _("USBDM Firmware Updater")
#define SYMBOL_BOOTLOADERDIALOGUE_IDNAME ID_BOOTLOADERDIALOGUE
#define SYMBOL_BOOTLOADERDIALOGUE_SIZE wxSize(500, 350)
#define SYMBOL_BOOTLOADERDIALOGUE_POSITION wxDefaultPosition

//! Struct used to contain information about the files converted
//!
typedef struct {
   uint16_t   firstAddr;           //!< first non-0xFF address
   uint16_t   lastAddr;            //!< last non-0xFF address
   uint16_t   protectAddr;         //!< deduced start of protected area
   uint8_t    hardwareVersion;     //!< hardware version of this image (from ICP)
   uint8_t    softwareVersion;     //!< software version of this image (from ICP)
   uint16_t   flashStart;          //!< start of user flash area (from ICP)
   uint16_t   userDetectICP;       //!< address of userDetectICP() routine in flash
   char      *sourceFilename;      //!< name of file loaded
   uint8_t    flashImage[0x10000]; //!< buffer for Flash image
   bool       serialNumberPresent; //!< indicates if the flash image supports serial numbers
   wxString   serialNumber;        //!< serial number (if any)
} FlashImageData;

//!  Structure to contain ICP needed information in TARGET memory!
//!
typedef struct {
   uint8_t   serialNumber[39];  //!< Serial number of devices
   uint8_t   terminator;        //!< Guaranteed zero terminator for serialNumber
   uint16_t  flashStart;        //!< Start of Flash image
   uint8_t   hardwareVersion;   //!< Hardware version number from Flash image
   uint8_t   softwareVersion;   //!< Software version number from Flash image
   uint16_t  userDetectICP;     //!< Address of userDetectICP() routine in Flash
} ICP_dataType;

/*!
 * bootloaderDialogue class declaration
 */
class bootloaderDialogue : public wxDialog
{
    DECLARE_DYNAMIC_CLASS( bootloaderDialogue )
    DECLARE_EVENT_TABLE()

private:
    // Controls
    wxButton                 *loadSourceButtonControl;
    wxStaticText             *filenameStaticTextControl;
    wxTextCtrl               *serialNumberTextControl;
    wxButton                 *readSerialNumberButtonControl;
    wxStaticText             *fileInformationStaticTextControl;
    wxStaticText             *statusStaticTextControl;
    wxButton                 *programFlashButtonControl;
    wxButton                 *verifyButtonControl;
    wxButton                 *exitButtonControl;
    wxCheckBox               *autoSequenceControl;
    wxCheckBox               *autoSelectFileControl;
    NumberTextEditCtrl       *autoSequenceTextControl;

    static wxProgressDialog  *progressDialogue;
    FlashImageData            flashImageDescription;
    wxString                  errMessage;
    ICP_dataType              ICP_data;
    wxString                  serialNumber;
    wxString                  serialNumberPrefix;
    wxString                  filename;

    bool                      autoSequence;
    int                       autoSequenceNumber;
    bool                      autoUpdateBdm;
    bool                      fileLoaded;

    int    loadS1S9File(const wxString &filepath);
    int    loadS1S9File(FILE *fp);
    void   setSerialNumber(const wxString &serialNumber);
    bool   consistencyCheck(unsigned int protectAddress);
    int    doFirmware(int  updateFirmware);
    bool   getICPData(void);
    void   dumpFile();
    int    readBdmSerialNumber(const char **bdmDescription);
    int    readBdmInformation(USBDM_bdmInformation_t *info);
    int    loadUpdateInformation();
    int    doAutoUpdate();
    int    readSerialNumber(void);

    int    openSingleDevice(void);
    void   serialNumberToTextControl(void);
    void   textControlToSerialNumber(void);
    void   parseSerialNumber(const wxString &serialNumber, wxString &serialNumberPrefix);

    void   updateControls(void);


public:
    enum {
       ID_BOOTLOADERDIALOGUE  = 10000,
       ID_FILE_LOAD_BUTTON,
       ID_PROGRAM_FLASH_BUTTON,
       ID_VERIFY_FLASH_BUTTON,
       ID_EXIT_BUTTON,
       ID_SERIALNUM_TEXTCTRL,
       ID_READ_SERIAL_NUM_BUTTON,
       ID_AUTO_SEQUENCE_CHECKBOX,
       ID_AUTO_SEQUENCE_TEXTCTRL,
       ID_AUTO_SELECT_FILE_CHECKBOX,
    };

    static ICP_ErrorCode_t icpProgressCallBack(ICP_ErrorCode_t status, unsigned int percent);
    static ICP_ErrorCode_t icpPulseCallBack(ICP_ErrorCode_t status);

    /// Constructors
    bootloaderDialogue();
    bootloaderDialogue( wxWindow* parent,
                         wxWindowID id = SYMBOL_BOOTLOADERDIALOGUE_IDNAME,
                         const wxString& caption = SYMBOL_BOOTLOADERDIALOGUE_TITLE,
                         const wxPoint& pos = SYMBOL_BOOTLOADERDIALOGUE_POSITION,
                         const wxSize& size = SYMBOL_BOOTLOADERDIALOGUE_SIZE,
                         long style = SYMBOL_BOOTLOADERDIALOGUE_STYLE );

    /// Destructor
    ~bootloaderDialogue();

    /// Creation
    bool Create( wxWindow* parent,
                 wxWindowID id = SYMBOL_BOOTLOADERDIALOGUE_IDNAME,
                 const wxString& caption = SYMBOL_BOOTLOADERDIALOGUE_TITLE,
                 const wxPoint& pos = SYMBOL_BOOTLOADERDIALOGUE_POSITION,
                 const wxSize& size = SYMBOL_BOOTLOADERDIALOGUE_SIZE,
                 long style = SYMBOL_BOOTLOADERDIALOGUE_STYLE );

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_FILE_LOAD_BUTTON
    void OnFileLoadButtonClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_PROGRAM_FLASH_BUTTON
    void OnProgramFlashButtonClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_VERIFY_FLASH_BUTTON
    void OnVerifyFlashButtonClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_EXIT_BUTTON
    void OnExitButtonClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL
    void OnSerialnumTextctrlTextUpdated( wxCommandEvent& event );

    ///  wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
    void OnReadSerialNumButtonClick( wxCommandEvent& event );

    ///  wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
    void OnAutoSequenceCheckboxClick( wxCommandEvent& event );

    ///  wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
    void OnAutoUpdateBdmCheckboxClick( wxCommandEvent& event );

    void OnAutoSequenceTextControlTextUpdated( wxCommandEvent& event );

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );

    /// Should we show tooltips?
    static bool ShowToolTips();

    void   loadSettings(const AppSettings &settings);
    void   saveSettings(AppSettings &settings);
    void   setAutoLoad(bool value);
};

#endif
    // _BOOTLOADERDIALOGUE_H_
