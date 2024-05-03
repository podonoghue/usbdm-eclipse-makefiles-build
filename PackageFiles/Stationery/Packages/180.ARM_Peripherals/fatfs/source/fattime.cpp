/*
 * fattime.cpp
 *
 * Requires enabled RTC code
 */
#include <time.h>
#include "ff.h"      /* Declarations of FatFs API */

/**
 * Called to get the current time for FatFs
 * From example provided with FatFs.
 *
 * @ref http://elm-chan.org/fsw/ff/doc/fattime.html
 *
 * @return Current local as bit-fields packed into a DWORD value.
 */
DWORD get_fattime (void) {
   time_t t;
   struct tm *stm;

   t = time(0);
   stm = localtime(&t);

   return (DWORD)(stm->tm_year - 80) << 25 |
         (DWORD)(stm->tm_mon + 1) << 21 |
         (DWORD)stm->tm_mday << 16 |
         (DWORD)stm->tm_hour << 11 |
         (DWORD)stm->tm_min << 5 |
         (DWORD)stm->tm_sec >> 1;
}
