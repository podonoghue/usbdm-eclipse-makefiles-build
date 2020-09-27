/*! \file
    \brief Version information
*/

//! Program version
#define VERSION_MAJOR  1       //!< DLL Major version #
#define VERSION_MINOR  0       //!< DLL Minor version #
#define VERSION_MICRO  0       //!< DLL Micro version #
#define VERSION_NANO   0       //!< DLL Nano version #

#ifdef LOG
#define VERSION_STRING "1.0.0-Debug" //!< Version as string
#else
#define VERSION_STRING "1.0.0."       //!< Version as string
#endif
