/////////////////////////////////////////////////////////////////////////////
// Name:        hcs12unsecure.cpp
// Purpose:
// Author:      Peter O'Donoghue
// Modified by:
// Created:     31/08/2010 16:21:42
// RCS-ID:
// Copyright:   GPL License
// Licence:
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "wx/dialog.h"
#include "wx/spinctrl.h"
#include "wx/event.h"
#endif

#include "Common.h"
#include "USBDM_API.h"
#include "TargetDefines.h"
#include "hcs12UnsecureDialogue.h"
#include "UsbdmSystem.h"

/*
 * HCS12Unsecure type definition
 */
IMPLEMENT_CLASS( HCS12Unsecure, wxDialog )

/*
 * HCS12Unsecure event table definition
 */
BEGIN_EVENT_TABLE( HCS12Unsecure, wxDialog )
    EVT_SPINCTRL( ID_BUS_FREQ_SPINCTRL, HCS12Unsecure::OnBusFreqSpinctrlUpdated )
    EVT_CHECKBOX( ID_EEPROM_CHECKBOX,   HCS12Unsecure::OnEepromCheckboxClick    )
END_EVENT_TABLE()

/*
 * HCS12Unsecure creator
 */
bool HCS12Unsecure::Create( wxWindow* parent) {

   SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
   wxDialog::Create( parent, ID_HCS12UNSECURE, _("HCS12 Unsecure"), wxDefaultPosition, wxSize(400, 300), wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL);
   CreateControls();
   if (GetSizer()) {
       GetSizer()->SetSizeHints(this);
   }
   Centre();
   return true;
}

/*
 * HCS12Unsecure destructor
 */
HCS12Unsecure::~HCS12Unsecure() {
}

/*
 * Member initialisation
 */
void HCS12Unsecure::Init() {
    busFrequencySpinControl = NULL;
    eepromCheckBoxControl   = NULL;
}

/*
 * Control creation for HCS12Unsecure
 */
void HCS12Unsecure::CreateControls() {
    HCS12Unsecure* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxStaticText* itemStaticText3 = new wxStaticText( itemDialog1, wxID_STATIC, _("To unsecure the target it is necessary to know some \n"
                                                                                  "information about the target characteristics:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemStaticText3, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 10);

    wxStaticBox* itemStaticBoxSizer4Static = new wxStaticBox(itemDialog1, wxID_ANY, wxEmptyString);
    wxStaticBoxSizer* itemStaticBoxSizer4 = new wxStaticBoxSizer(itemStaticBoxSizer4Static, wxVERTICAL);
    itemBoxSizer2->Add(itemStaticBoxSizer4, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText5 = new wxStaticText( itemDialog1, wxID_STATIC, _("The target bus frequency.\nThis will be the external crystal frequency/2.\nThe value shown is an estimate and may be inaccurate.\n"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer4->Add(itemStaticText5, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer4->Add(itemBoxSizer6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText7 = new wxStaticText( itemDialog1, wxID_STATIC, _("Bus Frequency"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer6->Add(itemStaticText7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    busFrequencySpinControl = new wxSpinCtrl( itemDialog1, ID_BUS_FREQ_SPINCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100000, busFrequency );
    itemBoxSizer6->Add(busFrequencySpinControl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText9 = new wxStaticText( itemDialog1, wxID_STATIC, _("kHz"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer6->Add(itemStaticText9, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer10Static = new wxStaticBox(itemDialog1, wxID_ANY, wxEmptyString);
    wxStaticBoxSizer* itemStaticBoxSizer10 = new wxStaticBoxSizer(itemStaticBoxSizer10Static, wxVERTICAL);
    itemBoxSizer2->Add(itemStaticBoxSizer10, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText11 = new wxStaticText( itemDialog1, wxID_STATIC, _("Whether the target has EEPROM in addition to Flash memory.\n"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer10->Add(itemStaticText11, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 10);

    eepromCheckBoxControl = new wxCheckBox( itemDialog1, ID_EEPROM_CHECKBOX, _("EEPROM Present"), wxDefaultPosition, wxDefaultSize, 0 );
    eepromCheckBoxControl->SetValue(hasEEPROM);
    itemStaticBoxSizer10->Add(eepromCheckBoxControl, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer13, 0, wxGROW|wxALL, 5);

    wxButton* itemButton14 = new wxButton( itemDialog1, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer13->Add(itemButton14, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemBoxSizer13->Add(5, 5, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton16 = new wxButton( itemDialog1, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer13->Add(itemButton16, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);
}

/*
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_BUS_FREQ_SPINCTRL
 */
void HCS12Unsecure::OnBusFreqSpinctrlUpdated( wxSpinEvent& event ) {

   busFrequency = event.GetPosition();
}

/*
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_EEPROM_CHECKBOX
 */
void HCS12Unsecure::OnEepromCheckboxClick( wxCommandEvent& event ) {

   hasEEPROM = event.IsChecked();
}

/*
 * Should we show tooltips?
 */
bool HCS12Unsecure::ShowToolTips() {
    return true;
}

/*
 * Get bitmap resources
 */
wxBitmap HCS12Unsecure::GetBitmapResource( const wxString& name ) {
    wxUnusedVar(name);
    return wxNullBitmap;
}

/*
 * Get icon resources
 */
wxIcon HCS12Unsecure::GetIconResource( const wxString& name ) {
    wxUnusedVar(name);
    return wxNullIcon;
}

//==============================================================================
//==============================================================================
//==============================================================================
//==============================================================================
class HCS12DeviceData {
private:
   static const uint32_t flashControl=0x0100;
   static const uint32_t eepromControl=0x0110;

public:
   static int getBDMtoBUSFactor()        { return 1; }
   static uint32_t getNVSECAddress()          { return 0xFF0F; }
   static uint32_t getCOPCTL()                { return 0x003C; }

   static uint32_t getFCLKDIVAddress()        { return flashControl+0x0; }
   static uint32_t getFSECAddress()           { return flashControl+0x1; }
   static uint32_t getFTSTMODAddress()        { return flashControl+0x2; }
   static uint32_t getFCNFGAddress()          { return flashControl+0x3; }
   static uint32_t getFPROTAddress()          { return flashControl+0x4; }
   static uint32_t getFSTATAddress()          { return flashControl+0x5; }
   static uint32_t getFCMDAddress()           { return flashControl+0x6; }
   static uint32_t getFADDRAddress()          { return flashControl+0x8; }
   static uint32_t getFDATAAddress()          { return flashControl+0xA; }
   static uint32_t getECLKDIVAddress()        { return eepromControl+0x0; }
   static uint32_t getEPROTAddress()          { return eepromControl+0x4; }
   static uint32_t getESTATAddress()          { return eepromControl+0x5; }
   static uint32_t getECMDAddress()           { return eepromControl+0x6; }
   static uint32_t getEADDRAddress()          { return eepromControl+0x8; }
   static uint32_t getEDATAAddress()          { return eepromControl+0xA; }
};

// Flash commands
//static const uint8_t mBlank      = 0x05; //!< Blank check
static const uint8_t mWordProg   = 0x20; //!< Byte program
//static const uint8_t mBurstProg  = 0x25; //!< Burst program
static const uint8_t mMassErase  = 0x41; //!< Mass erase
//static const uint8_t mPageErase  = 0x40; //!< Page erase

static const uint8_t  HCS12_clearFlashErrors  = 0x32;    // PVIOL|ACCERR|FAIL
//static const uint8_t  clearFlashErrors  = 0x30;    // FPVIOL|FACCERR
static const uint8_t  startFlashCommand = 0x80;    // FCBEF
//static const uint8_t  dummyFlashValue[] = {0xFF,0xFF,0xFF,0xFF};  // Dummy value for flash write
//static const uint32_t dummyFlashAddress = 0xFF80U; // Any address in flash

// EEPROM Control
//static const uint16_t HCS12_MEMSIZE_Address = 0x001C; //!< Address of Memory Size register
//static const uint16_t HCS12_PPAGE_Address   = 0x0030; //!< Program Page register
//static const uint16_t HCS12_EPAGE_Address   = 0x0017; //!< Program Page register
static const uint8_t  HCS12_FTSTMOD_WRALL   = 0x10;   //!< FTSTMOD_WRALL bit mask

#define SOPT_BKGDPE_MASK         (1<<1)          // BKGD pin enable in SOPT(1)
#define FCLKDIV_FDIVLD           (1<<7)
#define ECLKDIV_EDIVLD           (1<<7)

static const uint8_t  COPCTL_value   = 0x00;  // Value to initialise COPCTL - disable COP

//! Calculates Flash clock frequency from bus frequency & FCDIV value
//!
//! This equations applies to all the HCS12 devices I've checked.
//!
//! @param clockFreq : Target clock frequency
//! @param fcDiv     : Clock divider value
//!
//! @return Flash clock frequency
//!
static unsigned long calculateFlashFrequency(unsigned long clockFreq,
                                             uint8_t            fcDiv
                                           ) {
int PRDIV8 = (fcDiv&(1<<6)); // CLKDIV bit in clock division register
int CLKDIV = (fcDiv&0x3F);   // Clock division factor

   if ((fcDiv & 0x80)!= 0) // bit 7 must be zero
      return 0;

   return (PRDIV8?(clockFreq/8):clockFreq)/(CLKDIV+1);
}

//! \brief Searches for the 'best' Flash clock divider register value
//!
//! Best in this case means the value resulting in the clock nearest to the
//! middle of the permitted range.
//!
//! @param clkFreq   : Target clock frequency (kHz)
//! @param fMin      : Minimum permitted Flash clock frequency (kHz)
//! @param fMax      : Maximum permitted Flash clock frequency (kHz)
//!
//! @return  'Best' Clock divider value (0xFF on error)
//!
static uint8_t findFlashDividerValue(unsigned long fbus,
                                unsigned long fMin,
                                unsigned long fMax) {
int cfmclkd;            // Clock divider value
unsigned long fclk;     // Flash clock freq.
unsigned long fBest;
int returnValue = 0xFF;

//   log.print( "fMin = %ld, fMax = %ld\n", fMin, fMax);

   // Programming not possible if busFreq < 1 MHz
   if (fbus < 1000)
      return 0xFF;

   returnValue = 0xFF;
   fBest = fMin-1;

   for (cfmclkd = 0; cfmclkd<128; cfmclkd++) {
      fclk = calculateFlashFrequency(2*fbus, cfmclkd);
      if ((fclk>=fMin) && (fclk<=fMax) &&
          (((1/(float)fclk)+(1/(float)fbus)) > 5.0E-6)) { // Possible value?
         // Check if better than last found value
           if (fclk > fBest) {
              returnValue = cfmclkd;
              fBest       = fclk;
//              log.print("cfmclkd=0x%2.2x => F=%8lu +\n", cfmclkd, fclk );
           }
//           else
//              log.print("cfmclkd=0x%2.2x => F=%8lu -\n", cfmclkd, fclk );
      }
   }

//   if (returnValue>=0)
//      log.print("BusFreq=%8ld, Fmin=%8ld, Fmax=%8ld, F=%8ld, cfmclkd=0x%2.2x\n",
//              clkFreq, fMin, fMax, calculateFlashFrequency(clkFreq, returnValue), returnValue );
//   else
//      log.print("BusFreq=%8ld, Fmin=%8ld, Fmax=%8ld, Failed\n", clkFreq, fMin, fMax );
//
//   log.print("FCDIV Value = %d (0x%2.2X), Flash freq = %u kHz\n",
//                   returnValue, returnValue, (unsigned int)calculateFlashFrequency(clkFreq, returnValue));

   return returnValue;
}

static    uint8_t  fcdivValue;

//! \brief Sets the FCLKDIV/ECLKDIV register value based on
//! the BDM communication speed.
//!
//! Prepares the target for Flash and eeprom operations. \n
//! - Unprotects flash & eeprom [FPROT/EPROT registers]
//! - Set Flash clock divider [FCLKDIV/ECLKDIV registers] based busFrequency
//! - Clear flash & eeprom errors [FSTAT/ESTAT registers]
//! - Unprotects flash (FPROT)
//! - Set Flash clock divider (FCDIV)
//! - Disable COP
//!
//! @return error code, see \ref FlashError_t
//!
//! @note Assumes target has been reset & connected
//!
USBDM_ErrorCode HCS12Unsecure::initialiseTargetFlash() {
   LOGGING_E;

   uint8_t  fcdivCheckValue;
   static const unsigned char allOnes   = 0xFF;
   static const unsigned char allZeroes = 0x00;
   USBDM_ErrorCode rc;

   // Determine the FCLKDIV/ECLKDIV value
   //=========================================

   // Set user supplied speed
   rc = USBDM_SetSpeed(busFrequency);
   if ((rc != BDM_RC_OK) && (rc != BDM_RC_BDM_EN_FAILED))
      return rc;

   // Calculate the required FCDIV value
   fcdivValue = findFlashDividerValue((long)round(busFrequency), 150, 200);

   log.print("HCS12Unsecure::initialiseTargetFlash(): fBus = %ld kHz, FCDIV=0x%2.2X (%d)\n",
                   (long)round(busFrequency/1000.0), fcdivValue, fcdivValue);

   if (fcdivValue == 0xFF)
      return BDM_RC_UNKNOWN_SPEED;

   // Disable COP
   if (USBDM_WriteMemory(1, 1, HCS12DeviceData::getCOPCTL(), &COPCTL_value) != BDM_RC_OK)
      return BDM_RC_FAIL;

   //   fcdivValue  |= 0x80;

   // Unprotect the Flash
   if (USBDM_WriteMemory(1,1,HCS12DeviceData::getFPROTAddress(),&allOnes) != BDM_RC_OK)
      return BDM_RC_FAIL;

   // Clear any Flash errors (set FTSTMOD_WALL so all banks are affected)
   if (USBDM_WriteMemory(1, 1, HCS12DeviceData::getFTSTMODAddress(), &HCS12_FTSTMOD_WRALL) != BDM_RC_OK)
      return BDM_RC_FAIL;
   if (USBDM_WriteMemory(1,1,HCS12DeviceData::getFSTATAddress(),&HCS12_clearFlashErrors) != BDM_RC_OK)
      return BDM_RC_FAIL;
   if (USBDM_WriteMemory(1, 1, HCS12DeviceData::getFTSTMODAddress(), &allZeroes) != BDM_RC_OK)
      return BDM_RC_FAIL;

   // Set FCLKDIV value & verify
   if (USBDM_WriteMemory(1,1,HCS12DeviceData::getFCLKDIVAddress(),&fcdivValue) != BDM_RC_OK)
      return BDM_RC_FAIL;
   if (USBDM_ReadMemory(1,1,HCS12DeviceData::getFCLKDIVAddress(),&fcdivCheckValue) != BDM_RC_OK)
      return BDM_RC_FAIL;
   if (fcdivCheckValue != (fcdivValue|FCLKDIV_FDIVLD))
      return BDM_RC_FAIL;


   if (hasEEPROM) {
      // Set up the eeprom
      //====================================

      // Assume errors here mean there isn't actually any EEPROM
      // Unprotect the eeprom
      if (USBDM_WriteMemory(1,1,HCS12DeviceData::getEPROTAddress(),&allOnes) != BDM_RC_OK)
         hasEEPROM = false;

      // Clear any eeprom errors
      if (USBDM_WriteMemory(1,1,HCS12DeviceData::getESTATAddress(),&HCS12_clearFlashErrors) != BDM_RC_OK)
         hasEEPROM = false;

      // Set ECLKDIV value & verify
      if (USBDM_WriteMemory(1,1,HCS12DeviceData::getECLKDIVAddress(),&fcdivValue) != BDM_RC_OK)
         hasEEPROM = false;
      if (USBDM_ReadMemory(1,1,HCS12DeviceData::getECLKDIVAddress(),&fcdivCheckValue) != BDM_RC_OK)
         hasEEPROM = false;
      if (fcdivCheckValue != (fcdivValue|ECLKDIV_EDIVLD))
         hasEEPROM = false;
   }
   return BDM_RC_OK;
}

//! \brief Does Bulk Erase of Target Flash.
//!
//! @return error code, see \ref FlashError_t
//!
//! @note The target is not reset so current security state persists after erase.
//!
USBDM_ErrorCode HCS12Unsecure::bulkEraseMemory() {
   LOGGING_E;

   const uint8_t allOnes        = 0xFF;
   const uint8_t allZeroes      = 0x00;
   uint8_t dummyFlashAddress[]  = {0xFF, 0xFE};
   uint8_t dummyEepromAddress[] = {0x0C, 0x00};
   uint8_t dummyFlashData[]     = {0xFF, 0xFF};
   int timeout;
   uint8_t statValue;
   USBDM_ErrorCode rc;

   // Erase chip
   //=============================

   // Set up flash & eeprom
   rc = initialiseTargetFlash();
   if (rc != BDM_RC_OK) {
      log.print("initialiseTargetFlash() failed, reason=%s\n",  USBDM_GetErrorString(rc));
      return rc;
   }

   log.print("Bulk erasing target Flash...\n");
   // Apply Bulk Erase operation to all Flash banks
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFPROTAddress(),   &allOnes);
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFSTATAddress(),   &HCS12_clearFlashErrors);
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFTSTMODAddress(), &allZeroes);
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFSTATAddress(),   &HCS12_clearFlashErrors);
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFTSTMODAddress(), &HCS12_FTSTMOD_WRALL);
   USBDM_WriteMemory(2, 2, HCS12DeviceData::getFADDRAddress(),   dummyFlashAddress);
   USBDM_WriteMemory(2, 2, HCS12DeviceData::getFDATAAddress(),   dummyFlashData);
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFCMDAddress(),    &mMassErase);
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFSTATAddress(),   &startFlashCommand);

   // Wait for flash command to complete
   timeout = 10;
   do {
      // Mass erase should take ~100ms
      wxMilliSleep(100);
      if (USBDM_ReadMemory(1,1,HCS12DeviceData::getFSTATAddress(),&statValue) != BDM_RC_OK)
         return BDM_RC_FAIL;
      if (timeout-- == 0)
         return BDM_RC_FAIL;
   } while ((statValue & 0xC0) != 0xC0);

   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFTSTMODAddress(), &allZeroes);

   if (hasEEPROM) {
      log.print("Bulk erasing target EEPROM...\n");
      // Apply Bulk Erase operation to EEPROM
      USBDM_WriteMemory(1, 1, HCS12DeviceData::getEPROTAddress(),   &allOnes);
      USBDM_WriteMemory(1, 1, HCS12DeviceData::getESTATAddress(),   &HCS12_clearFlashErrors);
      USBDM_WriteMemory(2, 2, HCS12DeviceData::getEADDRAddress(),   dummyEepromAddress);
      USBDM_WriteMemory(2, 2, HCS12DeviceData::getEDATAAddress(),   dummyFlashData);
      USBDM_WriteMemory(1, 1, HCS12DeviceData::getECMDAddress(),    &mMassErase);
      USBDM_WriteMemory(1, 1, HCS12DeviceData::getESTATAddress(),   &startFlashCommand);

      // Wait for flash command to complete
      timeout = 10;
      do {
         // Mass erase should take ~100ms
         wxMilliSleep(100);
         if (USBDM_ReadMemory(1,1,HCS12DeviceData::getESTATAddress(),&statValue) != BDM_RC_OK)
            return BDM_RC_FAIL;
         if (timeout-- == 0)
            return BDM_RC_FAIL;
      } while ((statValue & 0xC0) != 0xC0);
   }
   USBDM_TargetReset((TargetMode_t)(RESET_HARDWARE|RESET_SPECIAL));

   unsigned long usbdmStatus;
   USBDM_ReadStatusReg(&usbdmStatus);

   if ((usbdmStatus & HC12_BDMSTS_UNSEC) != 0) {
      log.print("Bulk erasing target memory...Complete\n");
      return BDM_RC_OK;
   }
   else {
      log.print("Bulk erasing target memory...Failed!\n");
      return BDM_RC_FAIL;
   }
}

USBDM_ErrorCode HCS12Unsecure::programSecurityLocation() {
   LOGGING_E;

   uint8_t unsecureFlashValue[] = {0xFF, 0xFE};
   const uint8_t allOnes   = 0xFF;
   const uint8_t allZeroes = 0x00;
   int timeout;
   uint8_t statValue;
   uint8_t Hex_02 = 0x02;
   uint8_t Hex_30 = 0x30;

   // Unsecure Chip - re-programming flash NVSEC
   log.print( "unsecuring target\n");

   USBDM_WriteMemory(1, 1, HCS12DeviceData::getCOPCTL(), &COPCTL_value);
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFTSTMODAddress(), &allZeroes);
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFSTATAddress(),   &Hex_02);
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFCLKDIVAddress(), &fcdivValue);
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFCLKDIVAddress(), &fcdivValue);
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFPROTAddress(),   &allOnes);
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFSTATAddress(),   &Hex_30);
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFTSTMODAddress(), &allZeroes);
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFSTATAddress(),   &Hex_02);
   USBDM_WriteMemory(2, 2, HCS12DeviceData::getNVSECAddress()-1, unsecureFlashValue);
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFCMDAddress(),    &mWordProg);
   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFSTATAddress(),   &startFlashCommand);


   // Program non-volatile Flash security location
//   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFPROTAddress(),   &allOnes);
//   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFSTATAddress(),   &HCS12_clearFlashErrors);
//   USBDM_WriteMemory(2, 2, HCS12DeviceData::getNVSECAddress()-1, unsecureFlashValue);
//   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFCMDAddress(),    &mWordProg);
//   USBDM_WriteMemory(1, 1, HCS12DeviceData::getFSTATAddress(),   &startFlashCommand);
   // Wait for flash command to complete
   timeout = 10;
   do {
      // Programming should take ???
      wxMilliSleep(100);
      if (USBDM_ReadMemory(1,1,HCS12DeviceData::getFSTATAddress(),&statValue) != BDM_RC_OK)
         return BDM_RC_FAIL;
      if (timeout-- == 0)
         return BDM_RC_FAIL;
   } while ((statValue & 0xC0) != 0xC0);
   return BDM_RC_OK;
}


// Too hard - details depend on target too much
//
USBDM_ErrorCode HCS12Unsecure::unsecureHCS12Target(void) {
   LOGGING_E;

   unsigned long speed;
   USBDMStatus_t usbdmStatus;

   USBDM_GetBDMStatus(&usbdmStatus);
   USBDM_GetSpeed(&speed);

   // Confirm speed
   HCS12Unsecure dialogue(false, speed);
   dialogue.Create(NULL);
   int getCancelOK = dialogue.ShowModal();

   if (getCancelOK != wxID_OK)
      return BDM_RC_FAIL;
   USBDM_SetSpeed(speed);
   dialogue.bulkEraseMemory();
   unsigned long bdmscr;
   USBDM_ReadStatusReg(&bdmscr); // for debug = UNSEC should be set
   dialogue.programSecurityLocation();
//   closeLogFile();

   return BDM_RC_OK;
}
