/*! \file
    \brief Some common shared definitions.
*/
#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdint.h>

//! Used for manipulating Little/Big-Endian longwords (32 bits)
//!
typedef union {
    uint32_t longword;          //!< Treat as native 32-bit value
    uint8_t  bytes[4];          //!< Treat as array of bytes
    } U32u;

//! Used for manipulating Little/Big-Endian words (16 bits)
//!
typedef union {
    uint8_t  bytes[2];                //!< Treat as array of bytes
    uint16_t word;                    //!< Treat as native 16-bit value
    struct {uint8_t lo; uint8_t hi;} le;   //!< Little-endian order
    struct {uint8_t hi; uint8_t lo;} be;   //!< Big-endian order
    } U16u;

#ifndef TRUE
#define TRUE (1)
#define FALSE (0)
#endif

// The following are used control conditional compilation
#define HC12      0     //!< - HC12 or HCS12 target
#define HCS08     1     //!< - HCS08 target
#define RS08      2     //!< - RS08 target
#define CFV1      3     //!< - Coldfire Version 1 target
#define CFVx      4     //!< - Coldfire Version 2,3,4 target
#define JTAG      5     //!< - JTAG target - TAP is set to \b RUN-TEST/IDLE
#define EZFLASH   6     //!< - EzPort Flash interface (SPI?)
#define MC56F80xx 7     //!< - JTAG target with MC56F80xx optimised subroutines
#define ARM       8     //!< - Kinetis - either JTAG or SWD
#define S12Z      11    //!< - S12Z target
#define MPC56xx   15    //!< - JTAG target with MPC56xx optimised subroutines

#define OFF       0xFF  //!< - Turn off interface (no target)

#define DEVICE_DATABASE_DIRECTORY "DeviceData"

#ifndef WIN32
#define USBDM_INSTALL_DIRECTORY "/usr"
#endif
#endif /*COMMON_H_*/
