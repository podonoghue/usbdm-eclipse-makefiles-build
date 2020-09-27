/** \file
    \brief Provides Debug logging facilities

    Log.cpp

    \verbatim
    Turbo BDM Light - message log
    Copyright (C) 2005  Daniel Malik

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
    \endverbatim

    \verbatim
   Change History
   +=========================================================================================
   | 20 May 2015 | Added milliSleep                                           - pgo 4.11.2.30
   |  1 Dec 2014 | Added format information for logging print()s              - pgo 4.10.6.230
   |  1 Dec 2012 | Changed logging extensively                                - pgo - V4.10.4
   | 16 Nov 2009 | Relocated log file directory for Vista.                    - pgo
   |  5 Nov 2009 | Completed restructure for V1                               - pgo
   | 22 May 2009 | Added Speed options for CFVx & JTAG targets                - pgo
   |  3 Apr 2009 | Re-enabled connection retry on successful connect          - pgo
   | 30 Mar 2009 | Changed timing of reset/bkgd release in extendedConnect()  - pgo
   | 27 Dec 2008 | Added extendedConnect() and associated changes             - pgo
   +=========================================================================================
   \endverbatim
 */

#include <time.h>
#include <sys/time.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#ifdef __unix__
#include <time.h>
#include <errno.h>
#else
#include <windows.h>
#endif
#include <sys/stat.h>

#include "UsbdmSystem.h"
#include "Version.h"

#ifdef UNICODE
#undef UNICODE
#endif

/* Open a file within the application directory - read-only
 *
 * @param path to append to directory
 *
 * @return directory or NULL if failed
 */
FILE *UsbdmSystem::openApplicationFile(const std::string &path) {
   std::string fullPath = getApplicationPath(path);
   FILE *fp = fopen(fullPath.c_str(), "rt");
   if (fp == NULL) {
      // Try module directory
      fullPath = getModulePath(path);
      fp = fopen(fullPath.c_str(), "rt");
   }
   return fp;
}

/* Open a file within the resource directory - read-only
 *
 * @param path to append to directory
 *
 * @return directory or NULL if failed
 */
FILE *UsbdmSystem::openResourceFile(const std::string &path) {
   std::string fullPath = getResourcePath(path);
   FILE *fp = fopen(fullPath.c_str(), "rt");
   if (fp == NULL) {
      // Try module directory
      fullPath = getModulePath(path);
      fp = fopen(fullPath.c_str(), "rt");
   }
   return fp;
}

/* Open a file within the configuration directory - read-write
 * This is a per-user read/write directory for configurations
 *
 * @param path to append to directory
 *
 * @return directory or NULL if failed
 */
FILE *UsbdmSystem::openConfigurationFile(const std::string &path, const std::string &mode) {
   std::string fullPath = getConfigurationPath(path);
   return fopen(fullPath.c_str(), mode.c_str());
}

/**
 * Checks if a file exists
 */
bool UsbdmSystem::fileExists(const std::string &path) {
   struct stat buffer;
   return (stat(path.c_str(), &buffer) == 0);
}

/*
 *  Sleep for given number of milliseconds (or longer!)
 *
 *  @param milliSeconds - number of milliseconds to sleep
 */
void UsbdmSystem::milliSleep(int milliSeconds) {
#ifdef __unix__
   int rc;
   struct timespec sleepStruct;
   sleepStruct.tv_sec  = milliSeconds/1000;
   sleepStruct.tv_nsec = (milliSeconds%1000)*1000000L;
   do {
      rc = nanosleep(&sleepStruct, &sleepStruct);
   } while ((rc < 0) && (errno == EINTR));
#elif defined(_WIN32)
   Sleep(milliSeconds);
#else
#error "Don't know how to sleep!"
#endif
}

#ifdef LOG

#define ADDRESS_SIZE_MASK    (3<<0)
#define DISPLAY_SIZE_MASK    (3<<2)

const char                  *UsbdmSystem::Log::currentName     = NULL;      //!< Name of current function
FILE                        *UsbdmSystem::Log::logFile         = NULL;      //!< File handle for logging file
int                          UsbdmSystem::Log::indent          = 0;         //!< Indent level for listing
int                          UsbdmSystem::Log::currentLogLevel = 100;       //!< Level below which to log messages
bool                         UsbdmSystem::Log::loggingEnabled  = true;      //!< Log on/off
UsbdmSystem::Log::Timestamp  UsbdmSystem::Log::timestampMode   = relative;  //!< Time-stamp messages

/** \brief Get current time in milliseconds
 *
 *  @return time value
 */
double UsbdmSystem::Log::getCurrentTime(void) {
   struct timespec   now;

   if (clock_gettime(CLOCK_REALTIME, &now) < 0) {
      UsbdmSystem::Log::print(" UsbdmSystem::Log::getCurrentTime() - clock_gettime() failed!\n");
      return 1.0;
   }
   return now.tv_sec*1000.0 + (now.tv_nsec/1000000.0);
}

const char *UsbdmSystem::Log::getTimeStamp(void) {
   static double loggingStartTime = -1.0;
   static double lastTimestamp    = -1;
   static char buff[20];

   if (loggingStartTime < 0.0) {
      loggingStartTime = getCurrentTime();
      lastTimestamp    = loggingStartTime;
   }
   double timestamp;
   switch (timestampMode) {
      case none        :
         timestamp = loggingStartTime;
         break;
      case relative    :
         timestamp = getCurrentTime() - loggingStartTime;
         break;
      case incremental :
         timestamp = getCurrentTime() - lastTimestamp;
         break;
   }
   lastTimestamp = getCurrentTime();
   if (timestamp<.001) {
      timestamp = 0;
   }
   snprintf(buff, sizeof(buff), "/* %7.2f */ ", timestamp);
   return buff;
}

/**  \brief Object to allow logging the execution of a function
 *
 *  @param name Name of the function to use in messages
 *  @param when Whether to log entry/exit etc of this function
 */
UsbdmSystem::Log::Log(const char *name, When when) : when(when) {
   indent++;
   lastName      = currentName;
   lastLogLevel  = currentLogLevel;
   currentName   = name;

   if ((when==entry)||(when==both)) {
      print("Entry ===============\n");
   }
}
/**  \brief Record exit from a function
 *
 */
UsbdmSystem::Log::~Log(){
   currentLogLevel = lastLogLevel;
   if ((when==exit)||(when==both)) {
      print("Exit ================\n");
   }
   currentName     = lastName;
   indent--;
}

/**  \brief Open log file
 *
 *  @param logFileName - Name of log file
 *  @param description - Description written to log file
 *
 *  @note logging is enabled and timestamp disabled
 */
void UsbdmSystem::Log::openLogFile(const char *logFileName, const char *description){

   if (logFile != NULL) {
      fclose(logFile);
   }

   logFile = NULL;
   std::string logName(logFileName);
   std::string dataPath = UsbdmSystem::getConfigurationPath(logName);

   if (dataPath.size() > 0) {
      logFile = fopen(dataPath.c_str(), "wt");
   }

#ifdef _WIN32
   if (logFile == NULL) {
      logFile = fopen("C:\\usbdm.log", "wt");
   }
#endif

   indent = 0;
   currentName = NULL;
   if (logFile == NULL) {
      return;
   }
   loggingEnabled     = true;
   timestampMode      = incremental;
   getTimeStamp();

   fprintf(logFile, "%s - %s, Compiled on %s, %s.\n",
         description, USBDM_VERSION_STRING, __DATE__,__TIME__);

   time_t time_now;
   time(&time_now);
   fprintf(logFile,
         "/*\n"
         " * Log file created on: %s"
         " * ==============================================\n"
         " */\n", ctime(&time_now));
   fflush(logFile);
}

/**
 * Set logging handle
 *
 * @param newLogFile file handle to set
 */
void  UsbdmSystem::Log::setLogFileHandle(FILE *newLogFile) {
   logFile = newLogFile;
}

/**
 * Get logging handle
 *
 * @return file handle
 */
FILE* UsbdmSystem::Log::getLogFileHandle(void) {
   return logFile;
}

/** \brief Turns logging on or off
 *
 *  @param value - true/false => on/off logging
 */
void UsbdmSystem::Log::enableLogging(bool value) {
   loggingEnabled = value;
}

/**  \brief Set logging level relative to current level
 *
 *  @param level - level to log below \n
 *         A 0 value suppresses logging below the current level.
 */
void UsbdmSystem::Log::setLoggingLevel(int level) {
   currentLogLevel = indent + level;
}
/**  \brief Get logging level relative to current level
 *
 */
int UsbdmSystem::Log::getLoggingLevel() {
   return indent - currentLogLevel;
}
/** \brief Sets timestamping mode
 *
 *  @param mode - mode of timestamping
 */
void UsbdmSystem::Log::enableTimestamp(UsbdmSystem::Log::Timestamp mode) {
   timestampMode = mode;
}
/**  \brief Close the log file
 *
 */
void UsbdmSystem::Log::closeLogFile() {
   if (logFile == NULL) {
      return;
   }
   time_t time_now;
   time(&time_now);

   loggingEnabled = true;
   fprintf(logFile,
         "\n==========================================\n"
         "End of log file: %s\r", ctime(&time_now));
   loggingEnabled = false;

   fclose(logFile);
   logFile = NULL;
}
/** \brief Provides a print function which prints data into a log file.
 *
 *  @param format Format and parameters as for printf()
 */
void UsbdmSystem::Log::printq(const char *format, ...) {
   va_list list;
   if ((logFile == NULL) || (!loggingEnabled) || (indent > currentLogLevel)) {
      return;
   }
   if (format == NULL) {
      format = "printq() - Error - empty format string!\n";
   }
   va_start(list, format);
   vfprintf(logFile, format, list);
   va_end(list);
   fflush(logFile);
}

/** \brief Provides a print function which prints data into a log file.
 *
 *  @param format Format and parameters as for printf()
 */
void UsbdmSystem::Log::print(const char *format, ...)  {
   va_list list;
   if ((logFile == NULL) || (!loggingEnabled) || (indent > currentLogLevel)) {
      return;
   }
   if (format == NULL) {
      format = "print() - Error - empty format string!\n";
   }
   if (timestampMode != none) {
      fprintf(logFile, "%s", getTimeStamp());
   }
   fprintf(logFile, "%*s", 3*indent, "");
   if (currentName!=NULL) {
      fprintf(logFile, "%s: ", currentName);
   }
   va_start(list, format);
   vfprintf(logFile, format, list);
   va_end(list);
   fflush(logFile);
}

/** \brief Provides a print function which prints data into a log file.
 *
 *  @param format Format and parameters as for printf()
 */
void UsbdmSystem::Log::error(const char *format, ...)  {
   va_list list;
   if (logFile == NULL) {
      return;
   }
   if (format == NULL) {
      format = "error() - Error - empty format string!\n";
   }
   if (timestampMode != none) {
      fprintf(logFile, "%s", getTimeStamp());
   }
   fprintf(logFile, "%*s", 3*indent, "");
   if (currentName!=NULL) {
      fprintf(logFile, "%s: ", currentName);
   }
   va_start(list, format);
   vfprintf(logFile, format, list);
   va_end(list);
   fflush(logFile);
}
/** \brief Provides a print function which prints data into a log file.
 *
 *  @param format Format and parameters as for printf()
 */
void UsbdmSystem::Log::warning(const char *format, ...) {
   va_list list;
   if (logFile == NULL) {
      return;
   }
   if (format == NULL) {
      format = "error() - Error - empty format string!\n";
   }
   if (timestampMode != none) {
      fprintf(logFile, "%s", getTimeStamp());
   }
   fprintf(logFile, "%*s", 3*indent, "");
   if (currentName!=NULL) {
      fprintf(logFile, "%s: ", currentName);
   }
   va_start(list, format);
   vfprintf(logFile, format, list);
   va_end(list);
   fflush(logFile);
}
/** \brief Print a formatted dump of binary data in Hex
 *
 * @param data         Pointer to data to print
 * @param size         Number of bytes to print
 * @param startAddress Address to display against values
 * @param organisation Size of data & address increment
 */
void UsbdmSystem::Log::printDump(const uint8_t *data,
      unsigned int size,
      unsigned int startAddress,
      unsigned int organization) {
   const char  *prefix       = "";
   unsigned int addressShift = 0;
   unsigned int elementSize  = 1;
   unsigned int address      = startAddress;
   bool         littleEndian = (organization & DLITTLE_ENDIAN)!= 0;

   if ((logFile == NULL) || (!loggingEnabled) || (indent > currentLogLevel)) {
      return;
   }
   switch (organization&DISPLAY_SIZE_MASK){
      case BYTE_DISPLAY:
         elementSize  = 1;
         break;
      case WORD_DISPLAY:
         elementSize  = 2;
         break;
      case LONG_DISPLAY:
         elementSize  = 4;
         break;
   }
   switch (organization&ADDRESS_SIZE_MASK){
      case BYTE_ADDRESS:
         address = startAddress;
         addressShift = 0;
         break;
      case WORD_ADDRESS:
         address      = startAddress<<1;
         prefix = "W:";
         addressShift = 1;
         break;
   }
   //      print("org=%x, sz=%d, es=%d, as=%d\n", organization, size, elementSize, addressShift);
   int eolFlag = true;
   while(size>0) {
      if (eolFlag) {
         eolFlag = false;
         if (timestampMode) {
            fprintf(logFile, "%s", getTimeStamp());
         }
         fprintf(logFile, "%*s", 3*indent, "");
         fprintf(logFile,"   %s%8.8X:", prefix, address>>addressShift);
      }
      unsigned char dataTemp[4];
      unsigned int sub;
      for(sub=0; (sub<elementSize) && (size>0); sub++) {
         dataTemp[sub] = *data++;
         address++;
         size--;
         if ((address&0xF) == 0)
            eolFlag = true;
      }
      unsigned int indx;
      if (littleEndian) {
         indx=sub-1;
         do {
            fprintf(logFile, "%02X", dataTemp[indx]);
         } while (indx-- > 0) ;
      }
      else {
         for(indx=0; indx<sub; indx++) {
            fprintf(logFile, "%02X", dataTemp[indx]);
         }
      }
      fprintf(logFile," ");
      if (eolFlag)
         fprintf(logFile,"\n");
   }
   if (!eolFlag)
      fprintf(logFile,"\n");
   fflush(logFile);
}

#endif // LOG
