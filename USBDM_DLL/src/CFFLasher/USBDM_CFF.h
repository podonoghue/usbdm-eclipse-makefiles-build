/*! \file
    \brief Header file for USBDM_CFF.c

*/
#ifndef USBDM_CFF_H_
#define USBDM_CFF_H_

#ifndef WINAPI
#define WINAPI __attribute__((__stdcall__)) //!< -
#endif

//==================================================
#if defined __cplusplus
#define EXTERN_C  extern "C"
#else
#define EXTERN_C
#endif

#if defined(_WIN32) && !defined (WINAPI)
   #define WINAPI __attribute__((__stdcall__))
#endif

#if defined(_WIN32) && !defined(DLL_LOCAL)
   // Functions exported from a library
   #define DLL_EXPORT WINAPI __declspec(dllexport)

   // Functions imported from a library
   #define DLL_IMPORT WINAPI __declspec(dllimport)

   // Functions local to a library
   #define DLL_LOCAL
#endif

#if !defined(DLL_LOCAL)
   // Functions exported from a library
   #define DLL_EXPORT __attribute__ ((visibility ("default")))
   // Functions imported from a library
   #define DLL_IMPORT __attribute__ ((visibility ("default")))

   // Functions local to a library
   #define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#endif

#ifdef USBDM_DLL_EXPORTS
   //! These definitions are used when USBDM_API is being exported (creating DLL)
   #define CFF_API        EXTERN_C DLL_EXPORT
#else
   //! These definitions are used when USBDM_API is being imported (linking against DLL)
   #define CFF_API      EXTERN_C DLL_IMPORT
#endif
//==================================================

#if defined __cplusplus
    extern "C" {
#endif

#if defined __cplusplus
    }
#endif


#endif /* USBDM_CFF_H_ */
