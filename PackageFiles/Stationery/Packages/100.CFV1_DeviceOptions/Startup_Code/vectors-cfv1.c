/*
 *  Vectors.c
 *
 *  Generic vectors and security for Coldfire V1
 *
 *  Created on: 07/12/2012
 *      Author: podonoghue
 */
#include <stdint.h>

#define DEVICE_FAMILY_$(targetDeviceFamily)

/*
 * Security information
 */
#if defined(DEVICE_FAMILY_CFV1Plus)
typedef struct {
    uint8_t   backdoorKey[8];
    uint8_t   fprot[4];
    uint8_t   fdprot;
    uint8_t   feprot;
    uint8_t   fopt;
    uint8_t   fsec;
} SecurityInfo;

__attribute__ ((section(".security_information")))
const SecurityInfo securityInfo = {
    /* backdoor */ {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
    /* fprot    */ {0xFF,0xFF,0xFF,0xFF,},
    /* fdprot   */ 0xFF,
    /* feprot   */ 0xFF,
    /* fopt     */ 0xFF,
    /* fsec     */ 0xFE,  /* KEYEN=3,MEEN=3,FSLACC=3,SEC=2 */
};
#elif defined(DEVICE_FAMILY_CFV1)
typedef struct {
    uint8_t  backdoorKey[8];
    uint8_t  res1[5];
    uint8_t  nvprot;
    uint8_t  res2;
    uint8_t  nvopt;
} SecurityInfo;

__attribute__ ((section(".cs3.security_information")))
const SecurityInfo securityInfo = {
    /* backdoor */ {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
    /* res1     */ {0xFF,0xFF,0xFF,0xFF,0xFF,},
    /* nvprot   */ 0xFF,
    /* res2     */ 0xFF,
    /* nvopt    */ 0xFF,
};
#else
#error "Device family not set"
#endif

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
