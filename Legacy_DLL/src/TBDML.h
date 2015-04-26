/*! \file
    \brief Header file for OSBDM routines

*/
#ifndef TBDML_H_
#define TBDML_H_

#include "USBDM_API.h"

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

#ifdef LEGACY_DLL_EXPORTS
   //! These definitions are used when OSBDM_API is being exported (creating DLL)
   #define TBDML_API      EXTERN_C DLL_EXPORT
   #define OSBDM_API      EXTERN_C DLL_EXPORT
#else
   //! These definitions are used when OSBDM_API is being imported (linking against DLL)
   #define TBDML_API      EXTERN_C DLL_IMPORT
   #define OSBDM_API      EXTERN_C DLL_IMPORT
#endif
//==================================================

//! (HCS12/HCS08/RS08/Coldfire V1)  State of BDM Communication
typedef struct {
   AcknMode_t         ackn_state;       //!< Supports ACKN ?
   ResetMode_t        reset_state;      //!< Target reset recently ?
   SpeedMode_t        connection_state; //!< Connection status & speed determination method
} bdm_status_t;

//! Target microcontroller registers (HCS12, HCS08/RS08)
typedef union {
   //! HCS12 Registers
	struct {
		unsigned int pc;  //!< Program counter
		unsigned int sp;  //!< Stack Pointer
		unsigned int ix;  //!< Index register X
		unsigned int iy;  //!< Index register Y
		unsigned int d;   //!< D accumulator (A:B)
		unsigned int ccr; //!< Condition code register
	} hc12;
	//! HCS08 Registers (also used for RS08)
	struct {
		unsigned int pc;  //!< Program Counter (HCS08), CCR+PC (RS08)
		unsigned int sp;  //!< Stack Pointer (HCS08), Shadow PC (RS08)
		unsigned int hx;  //!< H:X index register (HCS08 only)
		unsigned int a;   //!< Accumulator (HCS08 + RS08)
		unsigned int ccr; //!< Condition code register (HCS08 only)
	} hcs08;
} registers_t;

#if defined __cplusplus
    extern "C" {
#endif

TBDML_API unsigned char  _tbdml_bdm_sts(bdm_status_t *bdm_status);            /* fills user supplied structure with actual state of BDM communication channel, returns 0 on success and non-zero on failure */
TBDML_API void           _tbdml_close(void);                                  /* closes currently open device */
TBDML_API unsigned int   _tbdml_dll_version(void);                            /* returns DLL version in BCD */
TBDML_API unsigned char  _tbdml_get_last_sts(void);                           /* returns status of the last command: 0 on success and non-zero on failure */
TBDML_API float          _tbdml_get_speed(void);                              /* returns crystal frequency of the target in MHz */
TBDML_API unsigned int   _tbdml_get_version(void);                            /* returns version of HW (MSB) and SW (LSB) of the interface in BCD format */
TBDML_API unsigned char  _tbdml_init(void);						                  /* initialises USB and returns number of devices found */
TBDML_API unsigned char  _tbdml_open(unsigned char device_no);                /* opens a device with given number (0...), returns 0 on success and 1 on error */
TBDML_API unsigned char  _tbdml_read_bd(unsigned int address);                /* reads one byte from debug memory map */
TBDML_API void           _tbdml_read_block(unsigned int address, unsigned int count, unsigned char *data); /* reads block from memory, data is returned to the user supplied buffer */
TBDML_API unsigned char  _tbdml_read_byte(unsigned int address);              /* reads one byte from memory */
TBDML_API unsigned char  _tbdml_read_regs(registers_t *registers);            /* reads contents of core registers, returns 0 on success and non-zero on failure */
TBDML_API unsigned int   _tbdml_read_word(unsigned int address);              /* reads one word from memory (address must be aligned) */
TBDML_API unsigned char  _tbdml_set_speed(float crystal_frequency);           /* sets the communication speed, parameter is crystal frequency in MHz, returns 0 on success and non-zero on failure */
TBDML_API unsigned char  _tbdml_set_target_type(TargetType_t target_type);   /* sets target MCU type, returns 0 on success and non-zero on failure */
TBDML_API unsigned char  _tbdml_target_go(void);                              /* starts target execution from current PC address, returns 0 on success and non-zero on failure */
TBDML_API unsigned char  _tbdml_target_halt(void);                            /* brings the target into active background mode, returns 0 on success and non-zero on failure */
TBDML_API unsigned char  _tbdml_target_reset(TargetMode_t target_mode);      /* resets the target to normal or special mode, returns 0 on success and non-zero on failure */
TBDML_API unsigned char  _tbdml_target_step(void); 				               /* steps over a single target instruction, returns 0 on success and non-zero on failure */
TBDML_API unsigned char  _tbdml_target_sync(void); 				               /* measures BDM frequency of the target using the SYNC feature and connects to it, returns 0 on success and non-zero on failure */
TBDML_API unsigned char  _tbdml_write_bd(unsigned int address, unsigned char data); /* writes one byte to BDM memory map */
TBDML_API void           _tbdml_write_block(unsigned int address, unsigned int count, unsigned char *data); /* writes block to memory */
TBDML_API void           _tbdml_write_byte(unsigned int address, unsigned char data); /* writes one byte to memory */
TBDML_API void           _tbdml_write_reg_ccr(unsigned int value);            /* writes CCR */
TBDML_API void           _tbdml_write_reg_d(unsigned int value);              /* writes B:A (HC12) or A (HCS08) */
TBDML_API void           _tbdml_write_reg_pc(unsigned int value); 		      /* writes PC */
TBDML_API void           _tbdml_write_reg_sp(unsigned int value); 		      /* writes SP */
TBDML_API void           _tbdml_write_reg_x(unsigned int value);	 	         /* writes H:X (HCS08) or IX (HC12) */
TBDML_API void           _tbdml_write_reg_y(unsigned int value); 		         /* writes IY (HC12 only) */
TBDML_API void           _tbdml_write_word(unsigned int address, unsigned int data); /* writes one word to memory (address must be aligned) */

#if defined __cplusplus
    }
#endif

#endif // TBDML_H_
