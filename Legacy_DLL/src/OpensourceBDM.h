/*! \file
    \brief Header file for OSBDM routines
*/
#ifndef OPENSOURCEBDM_H_
#define OPENSOURCEBDM_H_

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

OSBDM_API unsigned char  _opensourcebdm_bdm_sts(bdm_status_t *bdm_status);           /* fills user supplied structure with actual state of BDM communication channel, returns 0 on success and non-zero on failure */
OSBDM_API void           _opensourcebdm_close(void);                                 /* closes currently open device */
OSBDM_API unsigned int   _opensourcebdm_dll_version(void);                           /* returns DLL version in BCD */
OSBDM_API unsigned char  _opensourcebdm_get_last_sts(void);                          /* returns status of the last command: 0 on success and non-zero on failure */
OSBDM_API float          _opensourcebdm_get_speed(void);                             /* returns crystal frequency of the target in MHz */
OSBDM_API unsigned int   _opensourcebdm_get_version(void);                           /* returns version of HW (MSB) and SW (LSB) of the interface in BCD format */
OSBDM_API unsigned char  _opensourcebdm_init(void);						                /* initialises USB and returns number of devices found */
OSBDM_API void           _opensourcebdm_mem_dlend(void);
OSBDM_API void           _opensourcebdm_mem_dlstart(void);
OSBDM_API unsigned char  _opensourcebdm_open(unsigned char device_no); 	             /* opens a device with given number (0...), returns 0 on success and 1 on error */
OSBDM_API unsigned int   _opensourcebdm_read_bkpt(void);
OSBDM_API void           _opensourcebdm_read_block(unsigned int address, unsigned int count, unsigned char *data); /* reads block from memory, data is returned to the user supplied buffer */
OSBDM_API unsigned char  _opensourcebdm_read_byte(unsigned int address);             /* reads one byte from memory */
OSBDM_API unsigned int   _opensourcebdm_read_creg(unsigned char regNo);
OSBDM_API unsigned int   _opensourcebdm_read_csr2_byte(void);
OSBDM_API unsigned int   _opensourcebdm_read_csr3_byte(void);
OSBDM_API unsigned int   _opensourcebdm_read_dreg(unsigned char regNo);
OSBDM_API bool           _opensourcebdm_read_mem(unsigned int addr,      unsigned int size,
                                                 unsigned int memSpace,  unsigned char *data);
OSBDM_API unsigned int   _opensourcebdm_read_reg(unsigned char regNo);
OSBDM_API unsigned char  _opensourcebdm_read_regs(registers_t *registers);           /* reads contents of core registers, returns 0 on success and non-zero on failure */
OSBDM_API unsigned char  _opensourcebdm_read_status(void);
OSBDM_API unsigned int   _opensourcebdm_read_xcsr_byte(void);
OSBDM_API unsigned char  _opensourcebdm_set_derivative_type(unsigned char derivative);
OSBDM_API unsigned char  _opensourcebdm_set_speed(float crystal_frequency);          /* sets the communication speed, parameter is crystal frequency in MHz, returns 0 on success and non-zero on failure */
OSBDM_API unsigned char  _opensourcebdm_set_target_type(TargetType_t target_type);  /* sets target MCU type, returns 0 on success and non-zero on failure */
OSBDM_API unsigned char  _opensourcebdm_target_go(void);                             /* starts target execution from current PC address, returns 0 on success and non-zero on failure */
OSBDM_API unsigned char  _opensourcebdm_target_halt(void);                           /* brings the target into active background mode, returns 0 on success and non-zero on failure */
OSBDM_API unsigned char  _opensourcebdm_target_readyfor_datald(void);
OSBDM_API unsigned char  _opensourcebdm_target_reset(TargetMode_t target_mode);     /* resets the target to normal or special mode, returns 0 on success and non-zero on failure */
OSBDM_API unsigned char  _opensourcebdm_target_step(void); 				                /* steps over a single target instruction, returns 0 on success and non-zero on failure */
OSBDM_API unsigned char  _opensourcebdm_target_sync(void); 				                /* measures BDM frequency of the target using the SYNC feature and connects to it, returns 0 on success and non-zero on failure */
OSBDM_API void           _opensourcebdm_write_bkpt(unsigned int value);
OSBDM_API void           _opensourcebdm_write_block(unsigned int address, unsigned int count, unsigned char *data); /* writes block to memory */
OSBDM_API void           _opensourcebdm_write_byte(unsigned int address, unsigned char data);                       /* writes one byte to memory */
OSBDM_API void           _opensourcebdm_write_control(unsigned char value);
OSBDM_API void           _opensourcebdm_write_creg(unsigned char regNo,  unsigned int value);
OSBDM_API void           _opensourcebdm_write_csr2_byte(unsigned char value);
OSBDM_API void           _opensourcebdm_write_csr3_byte(unsigned char value);
OSBDM_API void           _opensourcebdm_write_dreg(unsigned char regNo,  unsigned int value);
OSBDM_API bool           _opensourcebdm_write_mem(unsigned int addr,     unsigned int count,
                                                  unsigned int memSpace, unsigned char *data);
OSBDM_API void           _opensourcebdm_write_reg(unsigned char regNo,   unsigned int value);
OSBDM_API void           _opensourcebdm_write_reg_ccr(unsigned int value);             /* writes CCR */
OSBDM_API void           _opensourcebdm_write_reg_d(unsigned int value);               /* writes B:A (HC12) or A (HCS08) */
OSBDM_API void           _opensourcebdm_write_reg_pc(unsigned int value);              /* writes PC */
OSBDM_API void           _opensourcebdm_write_reg_sp(unsigned int value);              /* writes SP */
OSBDM_API void           _opensourcebdm_write_reg_x(unsigned int value);               /* writes H:X (HCS08) or IX (HC12) */
OSBDM_API void           _opensourcebdm_write_xcsr_byte(unsigned char value);

#if defined __cplusplus
    }
#endif


#endif // OPENSOURCEBDM_H_
