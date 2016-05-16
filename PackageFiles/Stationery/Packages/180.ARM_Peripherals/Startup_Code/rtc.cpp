/*
 * rtc.c
 *
 *  Created on: 21/09/2013
 *      Author: podonoghue
 */

#include <sys/time.h>
#include "derivative.h"
#include "utilities.h"
#include "clock_configure.h"
#include "rtc.h"

#ifdef USBDM_RTC_IS_DEFINED

/*
 * To support time.h functions
 *
 * @param tp
 * @param tzp
 */
extern "C"
int _gettimeofday(struct timeval *tp, void *tzp) {
   (void)tzp;
   tp->tv_sec  = USBDM::Rtc::getTime();
   tp->tv_usec = 0;
   return 0;
}

/*
 * To support time.h functions
 *
 * @param tp
 * @param tzp
 */
extern "C"
int settimeofday(const struct timeval *tp, const struct timezone *tzp) {
   (void)tzp;
   // Start RTC
   USBDM::Rtc::enable();
   USBDM::Rtc::setTime(tp->tv_sec);
   return 0;
}

#endif
