/*! \file
    \brief Some common shared defintions.
*/
#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdint.h>

typedef uint8_t   U8;   //!< unsigned 8-bit value
typedef uint16_t  U16;  //!< unsigned 16-bit value
typedef uint32_t  U32;  //!< unsigned 32-bit value
typedef int8_t    S8;   //!< signed 8-bit value
typedef int16_t   S16;  //!< signed 16-bit value
typedef int32_t   S32;  //!< signed 32-bit value

//! Used for manipulating Little/Big-Endian longwords (32 bits)
//!
typedef union {
    U32 longword;          //!< Treat as native 32-bit value
    U8  bytes[4];          //!< Treat as array of bytes
    } U32u;

//! Used for manipulating Little/Big-Endian words (16 bits)
//!
typedef union {
    U8  bytes[2];                //!< Treat as array of bytes
    U16 word;                    //!< Treat as native 16-bit value
    struct {U8 lo; U8 hi;} le;   //!< Little-endian order
    struct {U8 hi; U8 lo;} be;   //!< Big-endian order
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
#define OFF       0xFF  //!< - Turn off interface (no target)

#endif /*COMMON_H_*/
