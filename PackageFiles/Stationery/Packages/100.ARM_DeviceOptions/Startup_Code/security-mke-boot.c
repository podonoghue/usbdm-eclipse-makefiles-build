/*
 *  @file security.c
 *  Derived from  security-mke-boot.c
 *
 *  Security and NV options for flash with boot options
 *  Reference KE1xFP100M168SF0RM, KE1xZP100M72SF0RM
 *  Created on: 20/5/2017
 *  Devices: KE1xZ, KE1xF
 */
#include <stdint.h>
#include <string.h>
#include "derivative.h"

/*
 * Security information structure in flash memory
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
  <h> Flash Configuration - Security and Protection
     <i> 16-byte flash configuration field that stores default protection settings (loaded on reset)
     <i> and security information that allows the MCU to restrict access to the Flash module.
  </h>
*/
/*
   <h> Program Flash Region Protect
      <i> Each program flash region can be protected from program and erase operation by clearing the associated PROT bit.
      <i> Each bit protects a 1/32 region of the program flash memory.
      <info>NV_FPROT0-3
      <q.0>   FPROT3.0 <0=>protected  <1=>unprotected   <info>lowest 1/32 block or 1K min
      <q.1>   FPROT3.1 <0=>protected  <1=>unprotected
      <q.2>   FPROT3.2 <0=>protected  <1=>unprotected
      <q.3>   FPROT3.3 <0=>protected  <1=>unprotected
      <q.4>   FPROT3.4 <0=>protected  <1=>unprotected
      <q.5>   FPROT3.5 <0=>protected  <1=>unprotected
      <q.6>   FPROT3.6 <0=>protected  <1=>unprotected
      <q.7>   FPROT3.7 <0=>protected  <1=>unprotected
      <q.8>   FPROT2.0 <0=>protected  <1=>unprotected
      <q.9>   FPROT2.1 <0=>protected  <1=>unprotected
      <q.10>  FPROT2.2 <0=>protected  <1=>unprotected
      <q.11>  FPROT2.3 <0=>protected  <1=>unprotected
      <q.12>  FPROT2.4 <0=>protected  <1=>unprotected
      <q.13>  FPROT2.5 <0=>protected  <1=>unprotected
      <q.14>  FPROT2.6 <0=>protected  <1=>unprotected
      <q.15>  FPROT2.7 <0=>protected  <1=>unprotected
      <q.16>  FPROT1.0 <0=>protected  <1=>unprotected
      <q.17>  FPROT1.1 <0=>protected  <1=>unprotected
      <q.18>  FPROT1.2 <0=>protected  <1=>unprotected
      <q.19>  FPROT1.3 <0=>protected  <1=>unprotected
      <q.20>  FPROT1.4 <0=>protected  <1=>unprotected
      <q.21>  FPROT1.5 <0=>protected  <1=>unprotected
      <q.22>  FPROT1.6 <0=>protected  <1=>unprotected
      <q.23>  FPROT1.7 <0=>protected  <1=>unprotected
      <q.24>  FPROT0.0 <0=>protected  <1=>unprotected
      <q.25>  FPROT0.1 <0=>protected  <1=>unprotected
      <q.26>  FPROT0.2 <0=>protected  <1=>unprotected
      <q.27>  FPROT0.3 <0=>protected  <1=>unprotected
      <q.28>  FPROT0.4 <0=>protected  <1=>unprotected
      <q.29>  FPROT0.5 <0=>protected  <1=>unprotected
      <q.30>  FPROT0.6 <0=>protected  <1=>unprotected
      <q.31>  FPROT0.7 <0=>protected  <1=>unprotected   <info> highest 1/32 block or 1K min
   </h>
*/
#define FPROT_VALUE 0xFFFFFFFF
/*
   <h> EEPROM Region Protect
      <i> Each bit protects a 1/8 region of the EEPROM memory.
      <i> (FlexNVM devices only)
      <info>NV_FEPROT
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
   <h> Data Flash Region Protect
      <i> Each bit protects a 1/8 region of the flash memory.
      <i> (Device with Data flash only)
      <info>NV_FDPROT
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
<h> Flash security value
   <info>NV_FSEC
   <o0> Backdoor Key Security Access Enable
      <i> Controls use of Backdoor Key access to unsecure device
      <info>KEYEN
      <2=> 2: Access enabled
      <3=> 3: Access disabled
   <o1> Mass Erase Enable Bits
      <i> Controls mass erase capability of the flash memory module.
      <i> Only relevant when FSEC.SEC is set to secure.
      <info>MEEN
      <2=> 2: Mass erase disabled
      <3=> 3: Mass erase enabled
   <o2> Freescale Failure Analysis Access
      <i> Controls access to the flash memory contents during returned part failure analysis
      <info>FSLACC
      <2=> 2: Factory access denied
      <3=> 3: Factory access granted
   <o3> Flash Security
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
<h> Flash boot options
   <info>NV_FOPT
   <e0> Boot ROM Options
      <i> Only available on devices with internal ROM
      <0=> Options Disabled
      <1=> Options Enabled
   <o1> Boot Source Selection
      <i> These bits select the boot sources
      <info>BOOTSRC_SEL
      <0=> 0: Boot from Flash with BOOTCFG0/NMI pin high or Boot from ROM with BOOTCFG0/NMI pin low
      <64=> 1: Boot from Flash
      <128=> 2: Boot from ROM
      <192=> 3: Boot from ROM
   <q2.1> External pin selects boot options
      <i> Note: RESET pin must be enabled if BOOTCFG0 is used.
	  <info>BOOTPIN_OPT
      <0=> Boot from ROM if BOOTCFG0 (NMI pin) asserted.
      <1=> Boot source controlled by BOOTSRC_SEL
   </e>

   <q2.3> RESET pin control
      <i> Enables or disables the RESET pin dedicated operation
	  <info>RESET_PIN_CFG
      <0=> Disabled (available as port pin)
      <1=> Enabled (PUP, open-drain, filtered)
   <q2.2> NMI pin control
      <i> Enables or disables the NMI function
      <info>NMI_DIS
      <0=> NMI interrupts are always blocked.
      <1=> NMI interrupts default to enabled
   <q2.0> Low power boot control
      <i> Controls the reset value of clock divider of IRC48M to feed the core clock.
      <i> Larger divide value selections produce lower average power consumption
      <i> during POR and reset sequencing and after reset exit.
      <i> The recovery times are also extended.
      <info>LPBOOT
      <0=> Low-power boot: Core and system clock divider (DIVCORE) is 0x1 (divide by 2).
      <1=> Normal boot: Core and system clock divider (DIVCORE) is 0x0 (divide by 1).
</h>
 */
#define BOOT_ENABLE    (1)      // e0
#define FOPT_BOOTSRC   (0x0)   // o1
#define FOPT_MISC      (0xF)    // q2
#define FOPT_RESERVED  (0x30)   // Bits not controlled by above
#define FOPT_BOOT_OFF  (0xC2)   // Value to use when (BOOT_ENABLE=0)

#if defined(NV_FOPT_BOOTSRC_SEL) && BOOT_ENABLE
#define FOPT_VALUE (FOPT_RESERVED|FOPT_BOOTSRC|FOPT_MISC)
#else
#define FOPT_VALUE (FOPT_RESERVED|FOPT_BOOT_OFF|FOPT_MISC)
#endif

/*
  <h> Backdoor Comparison Key
  <i> The Verify Backdoor Access Key command releases security if user-supplied keys
  <i> matches the Backdoor Comparison Key bytes
  <info>NV_BACKDOOR
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
#define BACKDOOR_VALUE { 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, }

__attribute__ ((section(".security_information")))
const SecurityInfo securityInfo = {
    /* backdoor */ BACKDOOR_VALUE,
    /* fprot    */ FPROT_VALUE,
    /* fsec     */ FSEC_VALUE,
    /* fopt     */ FOPT_VALUE,
    /* feprot   */ FEPROT_VALUE,
    /* fdprot   */ FDPROT_VALUE,
};

#if defined(NV_FOPT_BOOTPIN_OPT_MASK)
/*
 * Bootloader Configuration Area
 * Not all of this structure is applicable to all devices.
 */
typedef struct {
    char     tag[4];                 // Magic number indicating valid configuration - 'kcfg'
    uint32_t crcStartAddress;        // Start address for application image CRC check.
    uint32_t crcByteCount;           // Byte count for application image CRC check.
    uint32_t crcExpectedValue;       // Expected CRC value for application CRC check.
    uint8_t  enabledPeripherals;     // 0:LPUART, 1:I2C, 2:SPI, 4:USB
    uint8_t  i2cAddress;             // If not 0xFF, used as the 7-bit I2C slave address.
    uint16_t peripheralTimeout;      // Timeout in milliseconds for active peripheral detection
    uint16_t usbVid;                 // Sets the USB Vendor ID reported by the device during enumeration.
    uint16_t usbPid;                 // Sets the USB Product ID reported by the device during enumeration.
    uint32_t usbStringsPointer;      // Sets the USB Strings reported by the device during enumeration.
    uint8_t  clockFlags;             // See Table 13-4, clockFlags Configuration Field
    uint8_t  clockDivider;           // Divider to use for core and bus clocks when in high speed mode
    uint8_t  bootFlags;              // Bit0: 0=>Quad SPI Flash or internal flash, 1 => communication boot-loader
    uint8_t  padbyte;
    uint8_t  reserved[4];
    uint32_t keyblobDataPointer;     // A pointer to the keyblob data in memory.
    uint8_t  reserved1[8];
    uint32_t qspiConfigBlockPointer; // A pointer to the QSPI config block in internal flash array.
    uint8_t  reserved2[12];
} BootloaderConfiguration;

__attribute__ ((section(".bootloader_configuration")))
const BootloaderConfiguration bootloaderConfiguration = {
    /* tag[4];                */ {0xFF, 0xFF, 0xFF, 0xFF, }, //"kcfg" to activate,
    /* crcStartAddress;       */ 0xFFFFFFFF,
    /* crcByteCount;          */ 0xFFFFFFFF,
    /* crcExpectedValue;      */ 0xFFFFFFFF,
    /* enabledPeripherals;    */ 0xFF,
    /* i2cAddress;            */ 0xFF,
    /* peripheralTimeout;     */ 0xFFFF,
    /* usbVid;                */ 0xFFFF,
    /* usbPid;                */ 0xFFFF,
    /* usbStringsPointer;     */ 0xFFFFFFFF,
    /* clockFlags;            */ 0xFF,
    /* clockDivider;          */ 0xFF,
    /* bootFlags;             */ 0xFF,
    /* padbyte;               */ 0xFF,
    /* reserved[4];           */ {0xFF, 0xFF, 0xFF, 0xFF, },
    /* keyblobDataPointer;    */ 0xFFFFFFFF,
    /* reserved[8];           */ {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, },
    /* qspiConfigBlockPointer */ 0xFFFFFFFF,
    /* reserved[12];          */ {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, },
};
#endif
