/*
 * newlib_stubs.c
 *
 *  Created on: 2 Nov 2010
 *      Author: nanoage.co.uk
 */
#include <errno.h>
#include <stdint.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <sys/unistd.h>

#undef errno
extern int errno;

/**
 * Overridden by actual routine if present
 */
__attribute__((__weak__))
void uart_txChar(int ch) {
   (void)ch;
}

/**
 * Overridden by actual routine if present
 */
__attribute__((__weak__))
int uart_rxChar(void) {
   return 0;
}

/**
 *  environ
 *
 *  A pointer to a list of environment variables and their values.
 *  For a minimal environment, this empty list is adequate:
 */
char *__env[1] = { 0 };
char **environ = __env;

/*
 *  close
 *
 *  Close file
 */
int _close(int file __attribute__((unused))) {
   return -1;
}
int close(int file) __attribute__ ((unused, alias ("_close")));

/*
 *  execve
 *
 *  Transfer control to a new process. Minimal implementation (for a system without processes):
 */
int _execve(char *name __attribute__((unused)), char **argv __attribute__((unused)), char **env __attribute__((unused))) {
   errno = ENOMEM;
   return -1;
}

/**
 *  fork
 *
 *  Create a new process. Minimal implementation (for a system without processes):
 */

int _fork() {
   errno = EAGAIN;
   return -1;
}

/*
 *  fstat
 *
 *  Status of an open file. For consistency with other minimal implementations in these examples,
 *   all files are regarded as character special devices.
 *   The `sys/stat.h' header file required is distributed in the `include' subdirectory for this C library.
 */
int _fstat(int file __attribute__((unused)), struct stat *st) {
   st->st_mode = S_IFCHR;
   return 0;
}
int fstat(int file, struct stat *st) __attribute__ ((unused, alias ("_fstat")));

/**
 *  getpid
 *
 *  Process-ID; this is sometimes used to generate strings unlikely to conflict with other processes. Minimal implementation, for a system without processes:
 */
int _getpid() {
   return 1;
}

/**
 *  isatty
 *
 *  Query whether output stream is a terminal. For consistency with the other minimal implementations,
 */
int _isatty(int file) {
   switch (file){
   case STDOUT_FILENO:
   case STDERR_FILENO:
   case STDIN_FILENO:
      return 1;
   default:
      //errno = ENOTTY;
      errno = EBADF;
      return 0;
   }
}

int isatty(int fil) __attribute__ ((unused, alias ("_isatty")));

/*
 *  kill
 *
 *  Send a signal. Minimal implementation:
 */
int _kill(int pid __attribute__((unused)), int sig __attribute__((unused))) {
   errno = EINVAL;
   return (-1);
}

/*
 *  link
 *
 *   Establish a new name for an existing file. Minimal implementation:
 */

int _link(char *old __attribute__((unused)), char *new __attribute__((unused))) {
   errno = EMLINK;
   return -1;
}

/** 
 *  lseek
 *
 *  Set position in a file. Minimal implementation:
 */
off_t lseek(int file __attribute__((unused)), off_t ptr __attribute__((unused)), int dir __attribute__((unused))) {
   return 0;
}

/*
 * Used by sbrk
 */
static caddr_t heap_end = NULL;

/**
 *  sbrk
 *
 *   Increase program data space.
 *   Malloc and related functions depend on this
 */
void *sbrk(ptrdiff_t incr) {
   extern char __HeapBottom; /* Defined by the linker */
   extern char __HeapLimit;  /* Defined by the linker */
   caddr_t prev_heap_end;
   caddr_t next_heap_end;

   if (heap_end == NULL) {
      /* First allocation */
      heap_end = &__HeapBottom;
   }
   prev_heap_end = heap_end;
   // Round top to 2^3 boundary
   next_heap_end = (caddr_t)(((int)prev_heap_end + incr + 7) & ~7);
   if (next_heap_end > &__HeapLimit) {
      /* Heap and stack collision */
      __asm__("halt");
      return NULL;
   }
   heap_end = next_heap_end;
   return prev_heap_end;
}

/**
 * read
 *
 * Reads characters from a file.
 * 'libc' subroutines will use this system routine for input from all files, including STDIN
 * Blocks until len characters are read or a '\n' is encountered
 *
 * @param file - File to read from (not used - assumed UART=STDIN)
 * @param ptr  - Pointer to buffer for characters
 * @param len  - Maximum number of characters to read
 *
 * @return -1 on error or the number of characters read
 */
_ssize_t read( int file __attribute__((unused)), void *ptr, size_t len) {
   if (file != STDIN_FILENO) {
      errno = EBADF;
      return -1;
   }
   char *lptr = (char *)ptr;
   unsigned done=0; // Characters read
	if(len == 0) {
	   return 0;
	}
   int ch;
   do {
      ch = uart_rxChar();
      *lptr++ = ch;
   } while ((++done<len) && (ch != '\n'));
   return done;
}

/**
 * stat
 *
 * Status of a file (by name). Minimal implementation.
 *
 */
int _stat(const char *filepath __attribute__((unused)), struct stat *st) {
   st->st_mode = S_IFCHR;
   return 0;
}

/**
 * times
 * Timing information for current process. Minimal implementation:
 */
clock_t _times(struct tms *buf __attribute__((unused))) {
   return -1;
}

/**
 * unlink
 *
 * Remove a file's directory entry. Minimal implementation:
 */
int _unlink(char *name __attribute__((unused))) {
   errno = ENOENT;
   return -1;
}

/**
 *  wait
 *
 *  Wait for a child process. Minimal implementation:
 */
int _wait(int *status __attribute__((unused))) {
   errno = ECHILD;
   return -1;
}

/*
 *  write
 *
 *  Write a character to a file. `libc' subroutines will use this system routine for output to all files, including stdout
 *
 *  @return -1 on error or number of bytes sent
 */
_ssize_t write(int file, const void *ptr, size_t len) {
   const char *lptr = (const char *)ptr;
   switch (file) {
   case STDOUT_FILENO: /* stdout */
   case STDERR_FILENO: /* stderr */
      for (unsigned n = 0; n < len; n++) {
         if (*lptr == '\n') {
            uart_txChar('\r');
         }
         uart_txChar(*lptr++);
      }
      break;
   default:
      errno = EBADF;
      return -1;
   }
   return len;
}


/**
 * exit
 *
 * Exit process
 *
 * @param rc - Return code from process
 */
void _exit(int rc __attribute__((unused))) {
   while (1) {
      __asm__("halt");
   }
}

