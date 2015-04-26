/*
 *  Vectors.c
 *
 *  Generic vectors and security for Coldfire Vx
 *
 *  Created on: 07/12/2012
 *      Author: podonoghue
 */
#include <stdint.h>

#define $(targetDeviceSubFamily)

/*
 * Security information
 */
typedef struct {
    uint8_t   backdoorKey[8];
    uint32_t  cfmprot;
    uint32_t  cfmsacc;
    uint32_t  cfmdacc;
    uint32_t  cfmsec;
} SecurityInfo;

__attribute__ ((section(".security_information")))
const SecurityInfo securityInfo = {
    /* backdoor */ {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    /* cfmprot  */ 0x00000000,
    /* cfmsacc  */ 0x00000000,
    /* cfmdacc  */ 0x00000000,
    /* cfmsec   */ 0x00000000,  /* KEYEN=0,SEC=0x0000 (SEC=0x4AC8 protects device) */
};

/*
 * Vector table related
 */
typedef void( *const intfunc )( void );

#define WEAK_DEFAULT_HANDLER __attribute__ ((weak, alias("Default_Handler")))

 __attribute__((__interrupt__))
void Default_Handler(void) {
   while (1) {
      __asm__("halt");
   }
}

void __HardReset(void) __attribute__((__interrupt__));
extern uint32_t __StackTop;

/*
 * Each vector is assigned an unique name.  This is then 'weakly' assigned to the
 * default handler.
 * To install a handler, create a function with the name shown and it will override
 * the weak default.
 */
$(cVectorTable)