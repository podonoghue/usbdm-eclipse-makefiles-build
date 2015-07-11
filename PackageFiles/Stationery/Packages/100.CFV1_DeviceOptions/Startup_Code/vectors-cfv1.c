/*
 *  Vectors.c
 *
 *  Generic vectors and security for Coldfire V1
 *
 *  Created on: 07/12/2012
 *      Author: podonoghue
 */
#include <stdint.h>
#include "derivative.h"

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

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

/*
<h> Flash security value (NV_FTFA_FSEC)
   <o0> Backdoor Key Security Access Enable (FSEC.KEYEN)
      <i> Controls use of Backdoor Key access to unsecure device
      <0=> 0: Access disabled
      <1=> 1: Access disabled (preferred disabled value)
      <2=> 2: Access enabled
      <3=> 3: Access disabled
   <o1> Mass Erase Enable Bits (FSEC.MEEN)
      <i> Controls mass erase capability of the flash memory module.
      <i> Only relevant when FSEC.SEC is set to secure.
      <0=> 0: Mass erase enabled
      <1=> 1: Mass erase enabled
      <2=> 2: Mass erase disabled
      <3=> 3: Mass erase enabled
   <o2> Freescale Failure Analysis Access (FSEC.FSLACC)
      <i> Controls access to the flash memory contents during returned part failure analysis
      <0=> 0: Factory access granted
      <1=> 1: Factory access denied
      <2=> 2: Factory access denied
      <3=> 3: Factory access granted
   <o3> Flash Security (FSEC.SEC)
      <i> Defines the security state of the MCU. 
      <i> In the secure state, the MCU limits access to flash memory module resources. 
      <i> If the flash memory module is unsecured using backdoor key access, SEC is forced to 10b.
      <0=> 0: Secured
      <1=> 1: Secured
      <2=> 2: Unsecured
      <3=> 3: Secured
</h>
*/
#define FSEC_VALUE ((3<<NV_FSEC_KEYEN_SHIFT)|(3<<NV_FSEC_MEEN_SHIFT)|(3<<NV_FSEC_FSLACC_SHIFT)|(2<<NV_FSEC_SEC_SHIFT))
#if ((FSEC_VALUE&NV_FSEC_MEEN_MASK) == (2<<NV_FSEC_MEEN_SHIFT)) && ((FSEC_VALUE&NV_FSEC_SEC_MASK) != (2<<NV_FSEC_SEC_SHIFT))
// Change to warning if your really, really want to do this!
#error "The security values selected will prevent the device from being unsecured using external methods"
#endif

/*
Control extended Boot features on these devices
<h> Flash boot options (NV_FTFA_FOPT)
   <q0.2> NMI pin control (FOPT.NMI_DIS)
      <i> Enables or disables the NMI function
      <0=> NMI interrupts are always blocked.
      <1=> NMI_b interrupts default to enabled
   <q0.1> EZPORT pin control (FOPT.EZPORT_DIS)
      <i> Enables or disables EzPort function
      <i> Disabling EZPORT function avoids inadvertent resets into EzPort mode 
      <i> if the EZP_CS/NMI pin is used for its NMI function 
      <0=> EZP_CSn pin is disabled on reset
      <1=> EZP_CSn pin is enabled on reset
   <q0.0> Low power boot control (FOPT.LPBOOT)
      <i> Controls the reset value of SIM_CLKDIV1.OUTDIVx (clock dividers)
      <i> Allows power consumption during reset to be reduced
      <0=> CLKDIV1,2 = /8, CLKDIV3,4 = /16
      <1=> CLKDIV1,2 = /1, CLKDIV3,4 = /2
</h>
 */
#define FOPT_VALUE (0x7|0xF8)

__attribute__ ((section(".security_information")))
const SecurityInfo securityInfo = {
    /* backdoor */ {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
    /* fprot    */ {0xFF,0xFF,0xFF,0xFF,},
    /* fdprot   */ 0xFF,
    /* feprot   */ 0xFF,
    /* fopt     */ FOPT_VALUE,
    /* fsec     */ FSEC_VALUE,
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

#define WEAK_DEFAULT_HANDLER __attribute__ ((__weak__, alias("Default_Handler")))


/**
 * Default handler for interrupts
 *
 * Most of the vector table is initialised to point at this handler.
 *
 * If you end up here it probably means:
 *   - You have accidently enabled an interrupt source in a peripheral
 *   - Enabled the wrong interrupt source
 *   - Failed to install or create a handler for an interrupt you intended using e.g. mis-spelled the name.
 *     Compare your handler (C function) name to that used in the vector table.
 *
 */
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

