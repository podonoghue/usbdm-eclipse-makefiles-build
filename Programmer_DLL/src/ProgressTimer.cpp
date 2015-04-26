/*
 * ProgressTimer.cpp
 *
 *  Created on: 19/02/2012
 *      Author: pgo
 */
#include <sys/time.h>
#include <time.h>
#include "ProgressTimer.h"
#include "UsbdmSystem.h"

//! Create timer
//!
//! @param progressCallBack - Call back used to post messages
//! @param maximum          - Maximum cumulative value for progress
//!
ProgressTimer::ProgressTimer(CallBackT progressCallBack, unsigned maximum)
   : progressCallBack(progressCallBack),
     maximumBytes(maximum),
     message(NULL),
     lastBytesDone(0),
     bytesDone(0)
{
   gettimeofday(&timeCreation, NULL);
   timeStart = timeCreation;
}

//! Restart timer from 0
//!
//! @param message - Message to post, May be NULL to indicate no change.
//!
USBDM_ErrorCode ProgressTimer::restart(const char *message) {
   USBDM_ErrorCode rc = PROGRAMMING_RC_OK;

   lastBytesDone = 0;
   bytesDone     = 0;
   if (gettimeofday(&timeStart, NULL) != 0) {
      UsbdmSystem::Log::print("ProgressTimer::Timer::restart() - gettimeofday() failed!\n");
      return PROGRAMMING_RC_ERROR_INTERNAL_CHECK_FAILED;
   }
   if (message != NULL) {
      this->message = message;
   }
   if (progressCallBack != NULL) {
      rc = progressCallBack(PROGRAMMING_RC_OK, 0, this->message);
   }
//   UsbdmSystem::Log::print("ProgressTimer::Timer::restart() - \'%s\'\n", message);
   return rc;
}

//! Post progress message
//!
//! @param progress - How many bytes of progress since last call
//! @param message  - Message to post, May be NULL to indicate no change.
//!
USBDM_ErrorCode ProgressTimer::progress(int progress, const char *message) {
   USBDM_ErrorCode rc = PROGRAMMING_RC_OK;
   if (message != NULL) {
      this->message = message;
   }
   bytesDone += progress;
   int percent = 0;
   if (maximumBytes > 0) {
      percent = ((100UL*bytesDone)/maximumBytes);
   }
   double kBytesPerSec = 0;
   double elapsed = elapsedTime();
   if ((elapsed > 0) && (bytesDone > 0)) {
      kBytesPerSec = bytesDone/(1024*elapsed);
   }
   if (this->message == NULL) {
      this->message = "";
   }
   char messageBuffer[200];
   snprintf(messageBuffer, sizeof(messageBuffer), "%s (%2.2f kBytes/sec)", this->message, kBytesPerSec);
   if ((progressCallBack != NULL)/* && (progress != 0)*/) {
      if (bytesDone>0) {
         rc = progressCallBack(PROGRAMMING_RC_OK, percent, messageBuffer);
      }
      else {
         rc = progressCallBack(PROGRAMMING_RC_OK, percent, this->message);
      }
   }
//   UsbdmSystem::Log::print("ProgressTimer::Timer::progress() - \'%s\', Time = %3.2f, Progress done = %d(+%d) (%d%%)\n",
//         messageBuffer, elapsed, bytesDone, progress, percent);
   return rc;
}

//! @return - elapsed time in seconds since creation or restart()
//!
double ProgressTimer::elapsedTime(void) {
   struct timeval now;
   if (gettimeofday(&now, NULL) != 0) {
      UsbdmSystem::Log::print("ProgressTimer::Timer::elapsedTime() - gettimeofday() failed!\n");
      return 1.0;
   }
   return (now.tv_sec-timeStart.tv_sec) + ((now.tv_usec-timeStart.tv_usec)/1000000.0);
}

//! @return - total time in seconds since creation
//!
double ProgressTimer::totalTime(void) {
   struct timeval now;
   if (gettimeofday(&now, NULL) != 0) {
      UsbdmSystem::Log::print("ProgressTimer::Timer::elapsedTime() - gettimeofday() failed!\n");
      return 1.0;
   }
   return (now.tv_sec-timeCreation.tv_sec) + ((now.tv_usec-timeCreation.tv_usec)/1000000.0);
}
