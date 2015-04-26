/* CS3 start_c routine.
 *
 * Copyright (c) 2006, 2007 CodeSourcery Inc
 *
 * The authors hereby grant permission to use, copy, modify, distribute,
 * and license this software and its documentation for any purpose, provided
 * that existing copyright notices are retained in all copies and that this
 * notice is included verbatim in any distributions. No written agreement,
 * license, or royalty fee is required for any of the authorized uses.
 * Modifications to this software may be copyrighted by their authors
 * and need not follow the licensing terms described here, provided that
 * the new terms are clearly indicated on the first page of each file where
 * they apply.
 */

#include "cs3.h"

extern void __libc_init_array (void);

extern int main (int, char **, char **);

extern void exit (int) __attribute__ ((noreturn, weak));

/* The number of arguments to main.  */
extern int __cs3_argc __attribute ((weak));
/* The arguments to main.  This is not declared as:

     char __cs3_argv[]

   because some systems may want to initialize __CS3_ARGV to point to
   the stack or heap, if that is where arguments can be found.  */
extern char **__cs3_argv __attribute ((weak));

extern void __attribute ((noreturn)) __cs3_premain (void);

/* The memory initialization must go in a distinguished section so it
 * can be placed in ROM in profiles that load from ROM but execute normal
 * .text from RAM.
 * On ARM it is also important that we do not call main directly from
 * code that runs in ROM in such a profile, because there needs to be an
 * implicit marker inserted to prevent stack unwinding past that point.
 */
extern void sysInit(void);

void  __attribute ((noreturn, section(".text.cs3.init")))
__cs3_start_c (void)
{
   unsigned regions = __cs3_region_num;
   const struct __cs3_region *rptr = __cs3_regions;

   /* Call sysInit early as otherwise watch-dog may timeout */
   sysInit();

   /* Initialize memory */
   for (regions = __cs3_region_num, rptr = __cs3_regions; regions--; rptr++)
   {
      long long *src = (long long *)rptr->init;
      long long *dst = (long long *)rptr->data;
      unsigned limit = rptr->init_size;
      unsigned count;

      if (src != dst)
         for (count = 0; count != limit; count += sizeof (long long))
            *dst++ = *src++;
      else
         dst = (long long *)((char *)dst + limit);
      limit = rptr->zero_size;
      for (count = 0; count != limit; count += sizeof (long long))
         *dst++ = 0;
   }

   /* Now we can execute regular code from RAM.  */
   __cs3_premain ();
}

void __attribute ((noreturn))
__cs3_premain (void)
{
   int exit_code;
   int argc;
   char **argv;

   /* Run initializers.  */
   __libc_init_array ();

   /* If a command line is available, pass it to "main".  */
   argc = &__cs3_argc ? __cs3_argc : 0;
   argv = &__cs3_argv ? __cs3_argv : NULL;

   exit_code = main (argc, argv, NULL);
   if (exit)
      exit (exit_code);
   /* If exit is NULL, make sure we don't return. */
   for (;;)
      continue;
}
