/////////////////////////////////////////////////////////////////////////////
// Name:        hcs12unsecure.h
// Purpose:
// Author:      Peter O'Donoghue
// Modified by:
// Created:     31/08/2010 16:21:42
// RCS-ID:
// Copyright:   GPL License
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef HCS12UNSECURE_H_
#define HCS12UNSECURE_H_
#include "wx/wx.h"
#include "wx/frame.h"
#include "wx/dialog.h"
#include "wx/spinctrl.h"

/*!
 * HCS12Unsecure class declaration
 */
class HCS12Unsecure: public wxDialog
{
    DECLARE_CLASS( HCS12Unsecure )
    DECLARE_EVENT_TABLE()

private:
    bool     hasEEPROM;
    unsigned busFrequency;  // kHz

    USBDM_ErrorCode bulkEraseMemory();
    USBDM_ErrorCode initialiseTargetFlash();
    USBDM_ErrorCode programSecurityLocation();
    bool Create(wxWindow* parent);
    // Initialises member variables
    void Init();

    // Creates the controls and sizers
    void CreateControls();

    // wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_BUS_FREQ_SPINCTRL
    void OnBusFreqSpinctrlUpdated( wxSpinEvent& event );

    // wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_EEPROM_CHECKBOX
    void OnEepromCheckboxClick( wxCommandEvent& event );


public:
    // Constructors
    HCS12Unsecure(bool     hasEEPROM    = false,
                  unsigned busFrequency = 8000 /*kHz*/) :
        hasEEPROM(hasEEPROM),
        busFrequency(busFrequency) {

        Init();
    }
    // Destructor
    ~HCS12Unsecure();

    static USBDM_ErrorCode unsecureHCS12Target();

    // Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    // Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );

    /// Should we show tooltips?
    static bool ShowToolTips();

    wxSpinCtrl* busFrequencySpinControl;
    wxCheckBox* eepromCheckBoxControl;

    /// Control identifiers
    enum {
        ID_HCS12UNSECURE      = 10000,
        ID_BUS_FREQ_SPINCTRL,
        ID_EEPROM_CHECKBOX,
    };

};

#endif    // HCS12UNSECURE_H_
