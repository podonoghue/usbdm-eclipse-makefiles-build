/** \file
    \brief Version information
*/

//! Program versions e.g. Flash programmers
#define USBDM_VERSION_MAJOR  4       //!< DLL Major version #
#define USBDM_VERSION_MINOR  12      //!< DLL Minor version #
#define USBDM_VERSION_MICRO  1       //!< DLL Micro version #
#define USBDM_VERSION_NANO   210      //!< DLL Nano version #

#ifdef LOG
#define USBDM_VERSION_STRING "4.12.1.210-Debug" //!< Version as string
#else
#define USBDM_VERSION_STRING "4.12.1.210"       //!< Version as string
#endif

//! The version of the GDI standard implemented
#define USBDM_GDI_INTERFACE_VERSION (0x126)

//! Name of directory to create in %APPDATA% for usbdm settings
#define CONFIGURATION_DIRECTORY_NAME "usbdm"

//----------------------------------------------------------------------------
// Revision History
//-----------+----------------------------------------------------------------
//    Aug 17 | 4.12.1.210 Build                                          - pgo
//-----------+----------------------------------------------------------------
//    Jul 17 | 4.12.1.190 Build                                          - pgo
//-----------+----------------------------------------------------------------
//    Jun 17 | 4.12.1.180 Build                                          - pgo
//-----------+----------------------------------------------------------------
//
