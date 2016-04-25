/*
 *  @file Vectors.c
 *  Derived from  Vectors-mkl.c
 *
 *  Generic vectors and security for Kinetis MKLxx
 *
 *  Created on: 07/12/2012
 *      Author: podonoghue
 */
#include <stdint.h>
#include <string.h>
#include "derivative.h"

/*
 * Security information
 */
typedef struct {
    uint8_t  backdoorKey[8];
    uint32_t fprot;
    uint8_t  fsec;
    uint8_t  fopt;
    uint8_t  feprot;
    uint8_t  fdprot;
} SecurityInfo;

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------
/*
  <h> Flash Configuration
  <i> 16-byte flash configuration field that stores default protection settings (loaded on reset)
  <i> and security information that allows the MCU to restrict access to the FTFL module.
  
  <h> Backdoor Comparison Key
  <i> The Verify Backdoor Access Key command releases security if user-supplied keys
  <i> matches the Backdoor Comparison Key bytes
    <o0>  Backdoor Comparison Key 0.  <0x0-0xFF>
    <o1>  Backdoor Comparison Key 1.  <0x0-0xFF>
    <o2>  Backdoor Comparison Key 2.  <0x0-0xFF>
    <o3>  Backdoor Comparison Key 3.  <0x0-0xFF>
    <o4>  Backdoor Comparison Key 4.  <0x0-0xFF>
    <o5>  Backdoor Comparison Key 5.  <0x0-0xFF>
    <o6>  Backdoor Comparison Key 6.  <0x0-0xFF>
    <o7>  Backdoor Comparison Key 7.  <0x0-0xFF>
  </h>
 */
#define BACKDOOR_VALUE {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, }
/*
   <h> Program Flash Region Protect (NV_FPROT0-3)
      <i> Each program flash region can be protected from program and erase operation by clearing the associated PROT bit.
      <i> Each bit protects a 1/32 region of the program flash memory.
	   <q.31>   FPROT0.0	<0=>protected  <1=>unprotected   <info>lowest 1/32 block
	   <q.30>   FPROT0.1	<0=>protected  <1=>unprotected
	   <q.29>   FPROT0.2	<0=>protected  <1=>unprotected
	   <q.28>   FPROT0.3	<0=>protected  <1=>unprotected
	   <q.27>   FPROT0.4	<0=>protected  <1=>unprotected
	   <q.26>   FPROT0.5	<0=>protected  <1=>unprotected
	   <q.25>   FPROT0.6	<0=>protected  <1=>unprotected
	   <q.24>   FPROT0.7	<0=>protected  <1=>unprotected
	   <q.23>   FPROT1.0	<0=>protected  <1=>unprotected
	   <q.22>   FPROT1.1	<0=>protected  <1=>unprotected
	   <q.21>   FPROT1.2	<0=>protected  <1=>unprotected
	   <q.20>   FPROT1.3	<0=>protected  <1=>unprotected
	   <q.19>   FPROT1.4	<0=>protected  <1=>unprotected
	   <q.18>   FPROT1.5	<0=>protected  <1=>unprotected
	   <q.17>   FPROT1.6	<0=>protected  <1=>unprotected
	   <q.16>   FPROT1.7	<0=>protected  <1=>unprotected
	   <q.15>   FPROT2.0	<0=>protected  <1=>unprotected
	   <q.14>   FPROT2.1	<0=>protected  <1=>unprotected
	   <q.13>   FPROT2.2	<0=>protected  <1=>unprotected
	   <q.12>   FPROT2.3	<0=>protected  <1=>unprotected
	   <q.11>   FPROT2.4	<0=>protected  <1=>unprotected
	   <q.10>   FPROT2.5	<0=>protected  <1=>unprotected
	   <q.9>    FPROT2.6	<0=>protected  <1=>unprotected
	   <q.8>    FPROT2.7	<0=>protected  <1=>unprotected
	   <q.7>    FPROT3.0	<0=>protected  <1=>unprotected
	   <q.6>    FPROT3.1	<0=>protected  <1=>unprotected
	   <q.5>    FPROT3.2	<0=>protected  <1=>unprotected
	   <q.4>    FPROT3.3	<0=>protected  <1=>unprotected
	   <q.3>    FPROT3.4	<0=>protected  <1=>unprotected
	   <q.2>    FPROT3.5	<0=>protected  <1=>unprotected
	   <q.1>    FPROT3.6	<0=>protected  <1=>unprotected
	   <q.0>    FPROT3.7	<0=>protected  <1=>unprotected   <info> highest 1/32 block
   </h>
*/
#define FPROT_VALUE 0xFFFFFFFF
/*
   <h> EEPROM Region Protect (NV_FEPROT)
      <i> Each bit protects a 1/8 region of the EEPROM memory.
      <i> (FlexNVM devices only)
      <q.0>   FEPROT.0	<0=>protected  <1=>unprotected   <info> lowest 1/8 block
      <q.1>   FEPROT.1  <0=>protected  <1=>unprotected
      <q.2>   FEPROT.2  <0=>protected  <1=>unprotected
      <q.3>   FEPROT.3  <0=>protected  <1=>unprotected
      <q.4>   FEPROT.4  <0=>protected  <1=>unprotected
      <q.5>   FEPROT.5  <0=>protected  <1=>unprotected
      <q.6>   FEPROT.6  <0=>protected  <1=>unprotected
      <q.7>   FEPROT.7	<0=>protected  <1=>unprotected   <info> highest 1/8 block
   </h>
*/
#define FEPROT_VALUE 0xFF
/*
   <h> Data Flash Region Protect (NV_FDPROT)
      <i> Each bit protects a 1/8 region of the data flash memory.
      <i> (Device with Data flash only)
      <q.0>   FDPROT.0	<0=>protected  <1=>unprotected   <info> lowest 1/8 block
      <q.1>   FDPROT.1  <0=>protected  <1=>unprotected
      <q.2>   FDPROT.2  <0=>protected  <1=>unprotected
      <q.3>   FDPROT.3  <0=>protected  <1=>unprotected
      <q.4>   FDPROT.4  <0=>protected  <1=>unprotected
      <q.5>   FDPROT.5  <0=>protected  <1=>unprotected
      <q.6>   FDPROT.6  <0=>protected  <1=>unprotected
      <q.7>   FDPROT.7	<0=>protected  <1=>unprotected   <info> highest 1/8 block
   </h>
*/
#define FDPROT_VALUE 0xFF

/*
<h> Flash security value (NV_FSEC)
   <o0> Backdoor Key Security Access Enable (FSEC.KEYEN)
      <i> Controls use of Backdoor Key access to unsecure device
      <info>KEYEN
      <2=> 2: Access enabled
      <3=> 3: Access disabled
   <o1> Mass Erase Enable Bits (FSEC.MEEN)
      <i> Controls mass erase capability of the flash memory module.
      <i> Only relevant when FSEC.SEC is set to secure.
      <info>MEEN
      <2=> 2: Mass erase disabled
      <3=> 3: Mass erase enabled
   <o2> Freescale Failure Analysis Access (FSEC.FSLACC)
      <i> Controls access to the flash memory contents during returned part failure analysis
      <info>FSLACC
      <2=> 2: Factory access denied
      <3=> 3: Factory access granted
   <o3> Flash Security (FSEC.SEC)
      <i> Defines the security state of the MCU. 
      <i> In the secure state, the MCU limits access to flash memory module resources. 
      <i> If the flash memory module is unsecured using backdoor key access, SEC is forced to 10b.
      <info>SEC
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
<h> Flash boot options (NV_FOPT)
   <e0> Boot ROM Options
      <i> Only available on devices with internal ROM
      <i> Currently: KL03,KL17,KL27,KL43
      <0=> Disabled
      <1=> Enabled
   <o1> Boot Source Selection (FOPT.BOOTSRC_SEL)
      <i> These bits select the boot sources if FOPT.BOOTPIN_OPT = 1
	  <info>BOOTSRC_SEL
      <0=> 0: Boot from Flash
      <64=> 1: Reserved
      <128=> 2: Boot from ROM
      <192=> 3: Boot from ROM
   <q2.1> External pin selects boot options (FOPT.BOOTPIN_OPT)
      <i> Note: RESET pin must be enabled if BOOTCFG0 is used.
	  <info>BOOTPIN_OPT
      <0=> Boot from ROM if BOOTCFG0 (NMI pin) asserted. 
      <1=> Boot source controlled by BOOTSRC_SEL
   </e>

   <q2.5> Flash initialisation speed (FOPT.FAST_INIT)
      <i> Selects initialization speed on POR, VLLSx, and system reset.
	  <info>FAST_INIT
      <0=> Slower (reduced average power)
      <1=> Faster (higher average power)
   <q2.3> RESET pin control (FOPT.RESET_PIN_CFG)
      <i> Enables or disables the RESET pin dedicated operation
	  <info>RESET_PIN_CFG
      <0=> Disabled (available as port pin)
      <1=> Enabled (PUP, open-drain, filtered)
   <q2.2> NMI pin control (FOPT.NMI_DIS)
      <i> Enables or disables the NMI function
      <info>NMI_DIS
      <0=> NMI interrupts are always blocked.
      <1=> NMI interrupts default to enabled
   <o3> Low power boot control (FOPT.LPBOOT)
      <i> Controls the reset value of SIM_CLKDIV1.OUTDIV1 (clock divider) and
      <i> SMC_PMCTRL.RUNM (processor run mode)
      <i> Note: VLPR is only used on KL03,KL17,KL27,KL43
	  <info>LPBOOT
      <0=> OUTDIV1 = /8, RUNM = VLPR
      <1=> OUTDIV1 = /4, RUNM = VLPR
      <16=> OUTDIV1 = /2, RUNM = RUN
      <17=> OUTDIV1 = /1, RUNM = RUN
</h>
 */
#define BOOT_ENABLE  (1)
#define FOPT_BOOTSRC (0x0)
#define FOPT_MISC    (0x2E)
#define FOPT_LPBOOT  (0x11)

#if defined(NV_FOPT_BOOTSRC_SEL) && BOOT_ENABLE
#define FOPT_VALUE (FOPT_BOOTSRC|FOPT_MISC|FOPT_LPBOOT)
#else
#define FOPT_VALUE (0xC2|FOPT_MISC|FOPT_LPBOOT)
#endif

__attribute__ ((section(".security_information")))
extern const SecurityInfo securityInfo = {
    /* backdoor */ BACKDOOR_VALUE,
    /* fprot    */ FPROT_VALUE,
    /* fsec     */ FSEC_VALUE,
    /* fopt     */ FOPT_VALUE,
    /* feprot   */ FEPROT_VALUE,
    /* fdprot   */ FDPROT_VALUE,
};

#if defined(NV_FOPT_BOOTPIN_OPT_MASK)
/*
 * Security information
 */
typedef struct {
    char     magic[4];           // Magic number indicating valid configuration - 'kcfg'
    uint8_t  reserved[12];       // Reserved
    uint8_t  enabledPeripherals; // 0:LPUART, 1:I2C, 2:SPI, 4:USB
    uint8_t  i2cAddress;         // If not 0xFF, used as the 7-bit I2C slave address.
    uint16_t peripheralTimeout;  // Timeout in milliseconds for active peripheral detection
    uint16_t usbVid;             // Sets the USB Vendor ID reported by the device during enumeration.
    uint16_t usbPid;             // Sets the USB Product ID reported by the device during enumeration.
    uint32_t usbStringsPointer;  // Sets the USB Strings reported by the device during enumeration.
    uint8_t  clockFlags;         // See Table 13-4, clockFlags Configuration Field
    uint8_t  clockDivider;       // Divider to use for core and bus clocks when in high speed mode
} BootloaderConfiguration;

__attribute__ ((section(".bootloader_configuration")))
const BootloaderConfiguration bootloaderConfiguration = {
    /* magic               */ "kcfg",
    /* reserved            */ {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },
    /* enabledPeripherals  */ 0xFF, /* all peripherals */
    /* i2cAddress          */ 0x11,
    /* peripheralTimeout   */ 1000, /* ms */
    /* usbVid              */ 0,
    /* usbPid              */ 0,
    /* usbStringsPointer   */ 0,
    /* clockFlags          */ 0,
    /* clockDivider        */ 0,    /* 0 => high-speed 48MHz */
};
#endif

/*
 * Vector table related
 */
typedef void( *const intfunc )( void );

#define WEAK_DEFAULT_HANDLER __attribute__ ((__weak__, alias("Default_Handler")))

#ifndef SCB_ICSR
#define SCB_ICSR (*(volatile uint32_t*)(0xE000ED04))
#endif

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
 * You can check 'vectorNum' below to determine the interrupt source.  Look this up in the vector table below.
 */
__attribute__((__interrupt__))
void Default_Handler(void) {

   __attribute__((unused))
   volatile uint32_t vectorNum = (SCB_ICSR&SCB_ICSR_VECTACTIVE_Msk)>>SCB_ICSR_VECTACTIVE_Pos;

   while (1) {
      __BKPT(0);
   }
}

typedef struct {
   unsigned int r0;
   unsigned int r1;
   unsigned int r2;
   unsigned int r3;
   unsigned int r12;
   void       (*lr)();
   void       (*pc)();
   unsigned int psr;
} ExceptionFrame;

/*  Low-level exception handler
 *
 *  Interface from asm to C.
 *  Passes address of exception handler to C-level handler
 *
 *  See http://www.freertos.org/Debugging-Hard-Faults-On-Cortex-M-Microcontrollers.html
 */
__attribute__((__naked__, __weak__, __interrupt__))
void HardFault_Handler(void) {
   /*
    * Determines the active stack pointer and loads it into r0
    * This is used as the 1st argument to _HardFault_Handler(volatile ExceptionFrame *exceptionFrame)
    * and allows access to the saved processor state.
    * Other registers are unchanged and available in the usual register view
    */
   __asm__ volatile (
          "       mov r0,lr                                     \n"
          "       mov r1,#4                                     \n"
          "       and r0,r1                                     \n"
          "       bne skip1                                     \n"
          "       mrs r0,msp                                    \n"
          "       b   skip2                                     \n"
          "skip1:                                               \n"
          "       mrs r0,psp                                    \n"
          "skip2:                                               \n"
          "       nop                                           \n"
          "       ldr r2, handler_addr_const                    \n"
          "       bx r2                                         \n"
          "       handler_addr_const: .word _HardFault_Handler  \n"
      );
}

/******************************************************************************/
/* Hard fault handler in C with stack frame location as input parameter
 *
 * Assumed exception frame without floating-point storage
 *
 * @param exceptionFrame address of exception frame
 *
 * If you end up here you have probably done one of the following:
 *   - Accessed illegal/unimplemented memory e.g. gone off the end of an array
 *   - Accessed a disabled peripheral - Check you have enabled the clock
 *   - Accessed unaligned memory - unlikely I guess
 *
 */
__attribute__((__naked__))
void _HardFault_Handler(volatile ExceptionFrame *exceptionFrame __attribute__((__unused__))) {
   while (1) {
      // Stop here for debugger
      __BKPT(0);
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

