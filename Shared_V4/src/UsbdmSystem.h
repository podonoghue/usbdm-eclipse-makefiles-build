/*
 * UsbdmSystem.h
 *
 *  Created on: 12 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_USBDMSYSTEM_H_
#define SRC_USBDMSYSTEM_H_

#if !defined(CPP_DLL_LOCAL)
   //! Functions exported from a library
   #define CPP_DLL_EXPORT __declspec(dllexport)
   //! Functions imported from a library
   #define CPP_DLL_IMPORT __declspec(dllimport)

   //! Functions local to a library
   #define CPP_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#endif

#if defined(COMPILE_USBDM_SYSTEM_DLL)
#define USBDM_SYSTEM_DECLSPEC CPP_DLL_EXPORT
#elif defined(LINK_USBDM_SYSTEM_DLL)
#define USBDM_SYSTEM_DECLSPEC
#else
#define USBDM_SYSTEM_DECLSPEC CPP_DLL_IMPORT
#endif

#include <stdint.h>
#include <string>

class USBDM_SYSTEM_DECLSPEC UsbdmSystem {

private:
   UsbdmSystem() {}
   virtual ~UsbdmSystem() = 0;

public:
   static std::string getApplicationPath(const std::string &path);
   static std::string getResourcePath(const std::string &path);
   static std::string getDataPath(const std::string &path);

   static FILE *openApplicationFile(const std::string &path);
   static FILE *openResourceFile(const std::string &path);
   static FILE *openDataFile(const std::string &path, const std::string &mode);

   static bool fileExists(const std::string &path);
   static std::string getModulePath(const std::string &path);

   enum {
        BYTE_ADDRESS    = (0<<0),  // Addresses identify a byte in memory
        WORD_ADDRESS    = (1<<0),  // Addresses identify a word in memory
        BYTE_DISPLAY    = (0<<2),  // Display as bytes (8-bits)
        WORD_DISPLAY    = (1<<2),  // Display as words (16-bits)
        LONG_DISPLAY    = (2<<2),  // Display as longs (32-bits)
        DBIG_ENDIAN     = (0<<4),
        DLITTLE_ENDIAN  = (1<<4),
      };

#ifdef LOG
   class Log {
   public:
      enum When      {neither, entry, exit, both};
      enum Timestamp {none, relative, incremental };

   private:
      static FILE       *logFile;
      static bool        loggingEnabled;
      static Timestamp   timestampMode;
      static int         indent;
      static int         currentLogLevel;
      static const char *currentName;
      const  char       *lastName;
      int                lastLogLevel;
      When               when;

   public:
      Log(const char *name, When when=both);
      ~Log();

      static void    openLogFile(const char *logFileName, const char *description="");
      static void    closeLogFile();
      static void    enableLogging(bool value = true);
      static void    enableTimestamp(Timestamp mode = incremental);
      static void    setLoggingLevel(int level);
      static int     getLoggingLevel();
      static double  getCurrentTime();
      static double  getTimeStamp();
      static void    error(const char *format, ...)   __attribute__ ((format (printf, 1, 2)));
      static void    warning(const char *format, ...) __attribute__ ((format (printf, 1, 2)));
      static void    print(const char *format, ...)   __attribute__ ((format (printf, 1, 2)));
      static void    printq(const char *format, ...)  __attribute__ ((format (printf, 1, 2)));
      static void    printDump(const uint8_t *data,
                               unsigned int size,
                               unsigned int startAddress=0x0000,
                               unsigned int organization=BYTE_ADDRESS|BYTE_DISPLAY);
      static void setLogFileHandle(FILE *logFile);
      static FILE*   getLogFileHandle();
   };

#define LOGGING_Q UsbdmSystem::Log log(__PRETTY_FUNCTION__, UsbdmSystem::Log::neither)
#define LOGGING_E UsbdmSystem::Log log(__PRETTY_FUNCTION__, UsbdmSystem::Log::entry)
#define LOGGING_X UsbdmSystem::Log log(__PRETTY_FUNCTION__, UsbdmSystem::Log::exit)
#define LOGGING   UsbdmSystem::Log log(__PRETTY_FUNCTION__, UsbdmSystem::Log::both)

#else
   class USBDM_SYSTEM_DECLSPEC Log {
   public:
      enum When {neither, entry, exit, both};
      Log(const char *name, When when=both) {};
      Log() {};
      ~Log() {};
      static void openLogFile(const char *logFileName, const char *description="") {}
      static void closeLogFile() {}
      static void enableLogging(bool value) {}
      static void setLoggingLevel(int level) {}
      static int  getLoggingLevel() { return 0; }
      static void error(const char *format, ...) {}
      static void print(const char *format, ...) {}
      static void warning(const char *format, ...) {}
      static void printq(const char *format, ...) {}
      static void printDump(const uint8_t *data,
                            unsigned int size,
                            unsigned int startAddress=0x0000,
                            unsigned int organization=BYTE_ADDRESS|BYTE_DISPLAY) {}
      static FILE* getLogFileHandle() { return (FILE*)0; }
      static void setLogFileHandle(FILE *logFile) {}
      static void enableTimestamping(bool enable=true) {}
   };

   #define LOGGING_Q UsbdmSystem::Log log
   #define LOGGING_E UsbdmSystem::Log log
   #define LOGGING_X UsbdmSystem::Log log
   #define LOGGING   UsbdmSystem::Log log
#endif

};

#endif /* SRC_USBDMSYSTEM_H_ */
