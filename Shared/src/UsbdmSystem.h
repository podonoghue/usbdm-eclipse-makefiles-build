/** \file
    \brief Header file for UsbdmSystem

    \verbatim
    Copyright (C) 2015  Peter O'Donoghue

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Change History
   +====================================================================
   |    May 2015 | Created
   +====================================================================
    \endverbatim
*/

#ifndef SRC_USBDMSYSTEM_H_
#define SRC_USBDMSYSTEM_H_

#if !defined(CPP_DLL_LOCAL)
   #ifdef _WIN32
      //! Functions exported from a library
      #define CPP_DLL_EXPORT __declspec(dllexport)
      //! Functions imported from a library
      #define CPP_DLL_IMPORT __declspec(dllimport)
      //! Functions local to a library
      #define CPP_DLL_LOCAL
   #else
      //! Functions exported from a library
      #define CPP_DLL_EXPORT __attribute__ ((visibility ("default")))
      //! Functions imported from a library
      #define CPP_DLL_IMPORT __attribute__ ((visibility ("default")))
      //! Functions local to a library
      #define CPP_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
   #endif
#endif

#if defined(COMPILE_USBDM_SYSTEM_DLL)
// Buiding Library
#define USBDM_SYSTEM_DECLSPEC CPP_DLL_EXPORT
// Incorprating library directly
#elif defined(LINK_USBDM_SYSTEM_DLL)
//! Link to routines directly
#define USBDM_SYSTEM_DECLSPEC CPP_DLL_LOCAL
#else
// Dynamically linking to library
#define USBDM_SYSTEM_DECLSPEC CPP_DLL_IMPORT
#endif

#include <stdint.h>
#include <string>
#include <atomic>

/**
 * System routines: Logging, paths
 */
class USBDM_SYSTEM_DECLSPEC UsbdmSystem {

private:

   /**
    * Private constructor
    */
   UsbdmSystem() {}
   virtual ~UsbdmSystem() = 0;

public:
   /**
    * Obtain the path of a file within the application directory
    *
    * @param path to append to directory
    *
    * @return path or NULL if failed
    */
   static std::string getApplicationPath(const std::string &path);
   /**
    * Obtain the path of a file within the resource directory
    *
    * @param path to append to directory
    *
    * @return path or NULL if failed
    */
   static std::string getResourcePath(const std::string &path);
   /**
    * Obtain the path of a file within the configuration directory
    * This is a per-user read/write directory for configurations
    *
    * @param path to append to directory
    *
    * @return path or NULL if failed
    *
    * @note The configuration directory will be created if it doesn't already exist.
    */
   static std::string getConfigurationPath(const std::string &path);
   /**
    * Open a file within the application directory - read-only
    *
    * @param path to append to directory
    *
    * @return directory or NULL if failed
    */
   static FILE *openApplicationFile(const std::string &path);
   /**
    * Open a file within the resource directory - read-only
    *
    * @param path to append to directory
    *
    * @return directory or NULL if failed
    */
   static FILE *openResourceFile(const std::string &path);
   /**
    * Open a file within the configuration directory - read-write
    * This is a per-user read/write directory for configurations
    *
    * @param path  Path to append to configuration directory
    * @param mode  Mode to open file in
    *
    * @return directory or NULL if failed
    */
   static FILE *openConfigurationFile(const std::string &path, const std::string &mode);
   /**
    * Check if a file exists
    *
    * @param path - Path to file
    *
    * @return true/false
    */
   static bool fileExists(const std::string &path);
   /**
    * Obtain the path of a file within the same directory as the module
    * (Used on windows only)
    *
    * @param path to append to directory
    *
    * @return directory or NULL if failed
    */
   static std::string getModulePath(const std::string &path);
   /**
    *  Sleep for given number of milliseconds (or longer!)
    *
    *  @param milliSeconds - number of milliseconds to sleep
    */
   static void milliSleep(int milliSeconds);

   /**
    * Gets string describing a USBDM error code
    *
    * @param errorCode - error code returned from USBDM API routine.
    *
    * @return - ptr to static string describing the error.
    */
   static const char *getErrorString(unsigned errorCode);

   /**
    * Options for UsbdmSystem::Log::printDump
    */
   enum {
        BYTE_ADDRESS    = (0<<0),  //!< Addresses identify a byte in memory
        WORD_ADDRESS    = (1<<0),  //!< Addresses identify a word in memory
        BYTE_DISPLAY    = (0<<2),  //!< Display as bytes (8-bits)
        WORD_DISPLAY    = (1<<2),  //!< Display as words (16-bits)
        LONG_DISPLAY    = (2<<2),  //!< Display as longs (32-bits)
        DBIG_ENDIAN     = (0<<4),  //!< Big-endian order
        DLITTLE_ENDIAN  = (1<<4),  //!< Little-endian order
      };

#if defined(LOG)
   class USBDM_SYSTEM_DECLSPEC Log {
   private:
      /**
       * This class is not intended to be copied
       */
      Log(const Log&) = delete;
      Log(Log&&) = delete;

   public:
      enum When      {neither, entry, exit, both, forced};
      enum Timestamp {none, relative, incremental };

      struct LogState {
         const  char *  name;
         unsigned       indent;
         unsigned       level;
         bool           forced;
         bool           enabled;
      };

   private:
      static FILE *                     logFile;
      static Timestamp                  timestampMode;
      static LogState                   logState;

      When     when;
      LogState lastLogState;

      /** \brief Provides a print function which prints data into a log file.
       *
       * @param format        Format as for printf()
       * @param list          Argument list as for printf()
       * @param bdoPrefix     True to print time-stamp etc. at start of line
       */
      static void    doPrint(bool doPrefix, const char *format, va_list list);

   public:
      /**  \brief Object to allow logging the execution of a function
       *
       *  @param name Name of the function to use in messages
       *  @param when Whether to log entry/exit etc of this function
       */
      Log(const char *name, When when=both);
      /**
       * Destructor
       */
      ~Log();

      /**  \brief Open log file
       *
       *  @param logFileName - Name of log file
       *  @param description - Description written to log file
       *
       *  @note logging is enabled and timestamp disabled
       */
      static void    openLogFile(const char *logFileName, const char *description="");
      /**  \brief Close the log file
       *
       */
      static void    closeLogFile();
      /** \brief Turns logging on or off
       *
       *  @param value - true/false => on/off logging
       *
       *  @note This change is discarded on exit from the enclosing function.
       */
      static void    enableLogging(bool value = true);
      /** \brief Sets timestamping mode
       *
       *  @param mode - mode of timestamping
       */
      static void    enableTimestamp(Timestamp mode = incremental);
      /**  \brief Set logging level relative to current level
       *
       *  @param level - level to log below \n
       *         A 0 value suppresses logging below the current level.
       */
      static void    setLoggingLevel(int level);
      /**  \brief Get logging level relative to current level
       *
       */
      static int     getLoggingLevel();
      /** \brief Get current time in milliseconds
       *
       *  @return time value
       */
      static double  getCurrentTime();
      /**
       * Get timestamp string.
       * @note This is a pointer to a static location.
       */
      static const char   *getTimeStamp();
      /** \brief Provides a print function which prints data into a log file.
       *
       *  @param format Format and parameters as for printf()
       */
      static void    error(const char *format, ...)   __attribute__ ((format (printf, 1, 2)));
      /** \brief Provides a print function which prints data into a log file. No time stamp.
       *
       *  @param format Format and parameters as for printf()
       */
      static void    errorq(const char *format, ...)   __attribute__ ((format (printf, 1, 2)));
      /** \brief Provides a print function which prints data into a log file.
       *
       *  @param format Format and parameters as for printf()
       */
      static void    warning(const char *format, ...) __attribute__ ((format (printf, 1, 2)));
      /** \brief Provides a print function which prints data into a log file. No time stamp.
       *
       *  @param format Format and parameters as for printf()
       */
      static void    warningq(const char *format, ...) __attribute__ ((format (printf, 1, 2)));
      /** \brief Provides a print function which prints data into a log file.
       *
       *  @param format Format and parameters as for printf()
       */
      static void    print(const char *format, ...)   __attribute__ ((format (printf, 1, 2)));
      /** \brief Provides a print function which prints data into a log file. No time stamp.
       *
       *  @param format Format and parameters as for printf()
       */
      static void    printq(const char *format, ...)  __attribute__ ((format (printf, 1, 2)));
      /** \brief Print a formatted dump of binary data in Hex
       *
       * @param data         Pointer to data to print
       * @param size         Number of bytes to print
       * @param startAddress Address to display against values
       * @param organisation Size of data & address increment
       */
      static void    printDump(const uint8_t *data,
                               unsigned int size,
                               unsigned int startAddress=0x0000,
                               unsigned int organization=BYTE_ADDRESS|BYTE_DISPLAY);
      /**
       * Set logging handle
       *
       * @param newLogFile file handle to set
       */
      static void    setLogFileHandle(FILE *logFile);
      /**
       * Get logging handle
       *
       * @return file handle
       */
      static FILE*   getLogFileHandle();
   };

#define LOGGING_F UsbdmSystem::Log log(__PRETTY_FUNCTION__, UsbdmSystem::Log::forced)
#define LOGGING_Q UsbdmSystem::Log log(__PRETTY_FUNCTION__, UsbdmSystem::Log::neither)
#define LOGGING_E UsbdmSystem::Log log(__PRETTY_FUNCTION__, UsbdmSystem::Log::entry)
#define LOGGING_X UsbdmSystem::Log log(__PRETTY_FUNCTION__, UsbdmSystem::Log::exit)
#define LOGGING   UsbdmSystem::Log log(__PRETTY_FUNCTION__, UsbdmSystem::Log::both)
#define LOGGING_NONAME   UsbdmSystem::Log log("", UsbdmSystem::Log::neither)

#else // !defined(LOG)
   /**
    * Class providing logging features
    */
public:
   class USBDM_SYSTEM_DECLSPEC Log {
   private:
      /**
       * This class is not intended to be copied
       */
      Log(const Log&) = delete;
      Log(Log&&) = delete;

   public:
      enum When {neither, entry, exit, both};

      /**
       * Minimum constructor
       */
      Log() {};
      /**
       * Minimum destructor
       */
      ~Log() {};
      /**  \brief Open log file
       *
       *  @param logFileName - Name of log file
       *  @param description - Description written to log file
       *
       *  @note logging is enabled and timestamp disabled
       */
      static void openLogFile(const char *logFileName, const char *description="") {(void)logFileName; (void)description; }
      /**  \brief Close the log file
       *
       */
      static void closeLogFile() {}
      /** \brief Turns logging on or off
       *
       *  @param value - true/false => on/off logging
       *
       *  @note This change is discarded on exit from the enclosing function.
       */
      static void enableLogging(bool value) {(void)value;}
      /**  \brief Set logging level relative to current level
       *
       *  @param level - level to log below \n
       *         A 0 value suppresses logging below the current level.
       */
      static void setLoggingLevel(int level) {(void)level;}
      /**  \brief Get logging level relative to current level
       *
       */
      static int  getLoggingLevel() { return 0; }
      /** \brief Provides a print function which prints data into a log file.
       *
       *  @param format Format and parameters as for printf()
       */
      static void error(const char *format, ...) {(void)format;}
      /** \brief Provides a print function which prints data into a log file.
       *
       *  @param format Format and parameters as for printf()
       */
      static void errorq(const char *format, ...) {(void)format;}
      /** \brief Provides a print function which prints data into a log file. No time stamp.
       *
       *  @param format Format and parameters as for printf()
       */
      static void print(const char *format, ...) {(void)format;}
      /** \brief Provides a print function which prints data into a log file.
       *
       *  @param format Format and parameters as for printf()
       */
      static void warning(const char *format, ...) {(void)format;}
      /** \brief Provides a print function which prints data into a log file. No time stamp.
       *
       *  @param format Format and parameters as for printf()
       */
      static void warningq(const char *format, ...) {(void)format;}
      /** \brief Provides a print function which prints data into a log file. No time stamp.
       *
       *  @param format Format and parameters as for printf()
       */
      static void printq(const char *format, ...) {(void)format;}
      /** \brief Print a formatted dump of binary data in Hex
       *
       * @param data         Pointer to data to print
       * @param size         Number of bytes to print
       * @param startAddress Address to display against values
       * @param organisation Size of data & address increment
       */
      static void printDump(const uint8_t *data,
                            unsigned int size,
                            unsigned int startAddress=0x0000,
                            unsigned int organization=BYTE_ADDRESS|BYTE_DISPLAY) {(void)data;(void)size;(void)startAddress;(void)organization;}
      /**
       * Get logging handle
       *
       * @return file handle
       */
      static FILE* getLogFileHandle() { return (FILE*)0; }
      /**
       * Set logging handle
       *
       * @param newLogFile file handle to set
       */
      static void setLogFileHandle(FILE *logFile) {(void)logFile;}
      /** \brief Sets timestamping mode
       *
       *  @param mode - mode of timestamping
       */
      static void enableTimestamping(bool enable=true) {(void)enable;}
   };
   //! Force logging in function
   #define LOGGING_F UsbdmSystem::Log log
   //! Enable logging in function
   #define LOGGING_Q UsbdmSystem::Log log
   //! Enable logging in function & log entry
   #define LOGGING_E UsbdmSystem::Log log
   //! Enable logging in function & log exit
   #define LOGGING_X UsbdmSystem::Log log
   //! Enable logging in function & log entry and exit
   #define LOGGING   UsbdmSystem::Log log
   //! Enable logging in function & suppress function name
   #define LOGGING_NONAME   UsbdmSystem::Log log

#endif

};

#if __cplusplus >= 201103L
#include <chrono>

class TimeIt {

private:
   std::chrono::time_point<std::chrono::system_clock> start;
   const char *label;

public:
   /**
    * Time an interval and report on log
    *
    * @param label Label to use to identify timing in log.  Must exist for timing interval since not copied.
    */
   TimeIt(const char* label) : label(label) {
      LOGGING_Q;

      start = std::chrono::system_clock::now();
      log.print("%s ===================\n", label);
   }

   ~TimeIt() {
      LOGGING_Q;

      std::chrono::time_point<std::chrono::system_clock> end;
      end = std::chrono::system_clock::now();

      std::chrono::duration<double> elapsed_seconds = end - start;

      log.print("          %s =================== %f s\n", label, elapsed_seconds.count());
   }

};
#endif /* __cplusplus > */

#endif /* SRC_USBDMSYSTEM_H_ */
