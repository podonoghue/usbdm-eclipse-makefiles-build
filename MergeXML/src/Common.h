/*! \file
    \brief Some common shared defintions.
*/
#ifndef _COMMON_H_
#define _COMMON_H_

typedef unsigned char      U8;   //!< unsigned 8-bit value
typedef unsigned short     U16;  //!< unsigned 16-bit value
typedef unsigned long int  U32;  //!< unsigned 32-bit value
typedef signed   char      S8;   //!< signed 8-bit value
typedef signed   short     S16;  //!< signed 16-bit value
typedef signed   long int  S32;  //!< signed 32-bit value

/*! \brief Used for manipulating Little/Big-Endian longwords (32 bits) */ 
typedef union {
    U32 longword; //!< Treat as BigEndian 32-bit value
    U8  bytes[4]; //!< Treat as array of bytes
    } U32u;
    
/*! \brief Used for manipulating Little/Big-Endian words (16 bits) */ 
typedef union {
    U8  bytes[2]; //!< Treat as array of bytes
    struct {U8 lo; U8 hi;} le; //!< Little-endian order
    struct {U8 hi; U8 lo;} be; //!< Big-endian order
    U16 word;     //!< Treat as BigEndian 16-bit value
    } U16u;

#endif /*COMMON_H_*/
