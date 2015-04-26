/* Based on CPU DB MCF51JM128_80, version 3.00.067 (RegistersPrg V2.32) */
/*
** ###################################################################
**     Filename  : mcf51jm128.h
**     Processor : MCF51JM128VLK
**     FileFormat: V2.32
**     DataSheet : MCF51JM128RM Rev. 2 6/2009
**     Compiler  : CodeWarrior compiler
**     Date/Time : 5.10.2010, 14:38
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**      - 05.02.2008, V3.00.0:
**              - Removed bit SPI2C3[INTCLR], removed register SPI2CI, removed bits OTG_CTRL[VBUS_DSCHG, VBUS_CHG, VBUS_ON].
**              -   REASON: Bug-fix (issue #5763 in Issue Manager).
**      - 22.08.2008, V3.00.1:
**              - Added definition of the 32-bit registers CANTIDR(0x000018B0), CANRIDR(0x000018A0).
**              -   REASON: Bug-fix (#6328 in Issue Manager).
**      - 11.09.2008, V3.00.2:
**              - Renamed bits SDIDH[REV8:11] -> SDIDH[REV0:3].
**              -   REASON: Bug-fix(#6579 in Issue Manager).
**      - 7.11.2008, V3.00.3:
**              - Corrected definition of depreciated symbols.
**              -   REASON: Bug-fix (#6592 in Issue Manager).
**      - 6.08.2009, V3.00.4:
**              - Bits REV0-REV7 merged to REV[0:7] group.
**              -   REASON: Access to individual bits is useless (#7539 in Issue Manager).
**      - 5.11.2009, V3.00.5:
**              - Added REQN5 bit to INTC_PL6P{7,6} register.
**              -   REASON: Changes in the RM (from Rev. 1 to Rev. 2).
**      - 23.06.2010, V3.00.6:
**              - Corrected position of DPDOWN,DMDOWN bits in the OTGPIN register.
**
**     File-Format-Revisions:
**      - 06.08.2007, V2.19 :
**               - CPUDB revisions generated ahead of the file-format revisions.
**      - 11.09.2007, V2.20 :
**               - Added comment about initialization of unbonded pins.
**      - 02.01.2008, V2.21 :
**               - pragma push/pack replaced by pragma options align, issue #5608
**      - 13.02.2008, V2.22 :
**               - ASM header files: fixed too long lines and pseudo-instructions format (leading dot)
**      - 20.02.2008, V2.23 :
**               - Changes have not affected this file (because they are related to another family)
**      - 03.07.2008, V2.24 :
**               - Added support for bits with name starting with number (like "1HZ")
**      - 28.11.2008, V2.25 :
**               - StandBy RAM array declaration for ANSI-C added
**      - 1.12.2008, V2.26 :
**               - Duplication of bit (or bit-group) name with register name is not marked as a problem, if register is internal only and it is not displayed in I/O map.
**      - 17.3.2009, V2.27 :
**               - Merged bit-group is not generated, if the name matches with another bit name in the register
**      - 6.4.2009, V2.28 :
**               - Fixed generation of merged bits for bit-groups with a digit at the end, if group-name is defined in CPUDB
**      - 3.8.2009, V2.29 :
**               - If there is just one bits group matching register name, single bits are not generated
**      - 10.9.2009, V2.30 :
**               - Fixed generation of registers arrays.
**      - 15.10.2009, V2.31 :
**               - Changes have not affected this file (because they are related to another family)
**      - 18.05.2010, V2.32 :
**               - MISRA compliance: U/UL suffixes added to all numbers (_MASK,_BITNUM and addresses)
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user's reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/
#if !defined(MCU_mcf51jm128)  /* Check if memory map has not been already included */
#define MCU_mcf51jm128

/*lint -save  -e950 -esym(960,18.4) -e46 -esym(961,19.7) Disable MISRA rule (1.1,18.4,6.4,19.7) checking. */
/*lint -save  -e621 Disable MISRA rule (5.1) checking. */
/* Types definition */
typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned long dword;

/* Watchdog reset macro */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() (void)(SRS = 0x55U, SRS = 0xAAU)
#endif
#endif /* __RESET_WATCHDOG */

#pragma pack(push,1)

/**************** interrupt vector numbers ****************/
#define VectorNumber_INITSP             0U
#define VectorNumber_INITPC             1U
#define VectorNumber_Vaccerr            2U
#define VectorNumber_Vadderr            3U
#define VectorNumber_Viinstr            4U
#define VectorNumber_VReserved5         5U
#define VectorNumber_VReserved6         6U
#define VectorNumber_VReserved7         7U
#define VectorNumber_Vprviol            8U
#define VectorNumber_Vtrace             9U
#define VectorNumber_Vunilaop           10U
#define VectorNumber_Vunilfop           11U
#define VectorNumber_Vdbgi              12U
#define VectorNumber_VReserved13        13U
#define VectorNumber_Vferror            14U
#define VectorNumber_VReserved15        15U
#define VectorNumber_VReserved16        16U
#define VectorNumber_VReserved17        17U
#define VectorNumber_VReserved18        18U
#define VectorNumber_VReserved19        19U
#define VectorNumber_VReserved20        20U
#define VectorNumber_VReserved21        21U
#define VectorNumber_VReserved22        22U
#define VectorNumber_VReserved23        23U
#define VectorNumber_Vspuri             24U
#define VectorNumber_VReserved25        25U
#define VectorNumber_VReserved26        26U
#define VectorNumber_VReserved27        27U
#define VectorNumber_VReserved28        28U
#define VectorNumber_VReserved29        29U
#define VectorNumber_VReserved30        30U
#define VectorNumber_VReserved31        31U
#define VectorNumber_Vtrap0             32U
#define VectorNumber_Vtrap1             33U
#define VectorNumber_Vtrap2             34U
#define VectorNumber_Vtrap3             35U
#define VectorNumber_Vtrap4             36U
#define VectorNumber_Vtrap5             37U
#define VectorNumber_Vtrap6             38U
#define VectorNumber_Vtrap7             39U
#define VectorNumber_Vtrap8             40U
#define VectorNumber_Vtrap9             41U
#define VectorNumber_Vtrap10            42U
#define VectorNumber_Vtrap11            43U
#define VectorNumber_Vtrap12            44U
#define VectorNumber_Vtrap13            45U
#define VectorNumber_Vtrap14            46U
#define VectorNumber_Vtrap15            47U
#define VectorNumber_VReserved48        48U
#define VectorNumber_VReserved49        49U
#define VectorNumber_VReserved50        50U
#define VectorNumber_VReserved51        51U
#define VectorNumber_VReserved52        52U
#define VectorNumber_VReserved53        53U
#define VectorNumber_VReserved54        54U
#define VectorNumber_VReserved55        55U
#define VectorNumber_VReserved56        56U
#define VectorNumber_VReserved57        57U
#define VectorNumber_VReserved58        58U
#define VectorNumber_VReserved59        59U
#define VectorNumber_VReserved60        60U
#define VectorNumber_Vunsinstr          61U
#define VectorNumber_VReserved62        62U
#define VectorNumber_VReserved63        63U
#define VectorNumber_Virq               64U
#define VectorNumber_Vlvd               65U
#define VectorNumber_Vlol               66U
#define VectorNumber_Vspi1              67U
#define VectorNumber_Vspi2              68U
#define VectorNumber_Vusb               69U
#define VectorNumber_VReserved70        70U
#define VectorNumber_Vtpm1ch0           71U
#define VectorNumber_Vtpm1ch1           72U
#define VectorNumber_Vtpm1ch2           73U
#define VectorNumber_Vtpm1ch3           74U
#define VectorNumber_Vtpm1ch4           75U
#define VectorNumber_Vtpm1ch5           76U
#define VectorNumber_Vtpm1ovf           77U
#define VectorNumber_Vtpm2ch0           78U
#define VectorNumber_Vtpm2ch1           79U
#define VectorNumber_Vtpm2ovf           80U
#define VectorNumber_Vsci1err           81U
#define VectorNumber_Vsci1rx            82U
#define VectorNumber_Vsci1tx            83U
#define VectorNumber_Vsci2err           84U
#define VectorNumber_Vsci2rx            85U
#define VectorNumber_Vsci2tx            86U
#define VectorNumber_Vkeyboard          87U
#define VectorNumber_Vadc               88U
#define VectorNumber_Vacmpx             89U
#define VectorNumber_Viic1x             90U
#define VectorNumber_Vrtc               91U
#define VectorNumber_Viic2x             92U
#define VectorNumber_Vcmt               93U
#define VectorNumber_Vcanwu             94U
#define VectorNumber_Vcanerr            95U
#define VectorNumber_Vcanrx             96U
#define VectorNumber_Vcantx             97U
#define VectorNumber_Vrnga              98U
#define VectorNumber_VReserved99        99U
#define VectorNumber_VReserved100       100U
#define VectorNumber_VReserved101       101U
#define VectorNumber_VReserved102       102U
#define VectorNumber_VReserved103       103U
#define VectorNumber_VL7swi             104U
#define VectorNumber_VL6swi             105U
#define VectorNumber_VL5swi             106U
#define VectorNumber_VL4swi             107U
#define VectorNumber_VL3swi             108U
#define VectorNumber_VL2swi             109U
#define VectorNumber_VL1swi             110U

/**************** interrupt vector table ****************/
#define INITSP                          0x0000U
#define INITPC                          0x0004U
#define Vaccerr                         0x0008U
#define Vadderr                         0x000CU
#define Viinstr                         0x0010U
#define VReserved5                      0x0014U
#define VReserved6                      0x0018U
#define VReserved7                      0x001CU
#define Vprviol                         0x0020U
#define Vtrace                          0x0024U
#define Vunilaop                        0x0028U
#define Vunilfop                        0x002CU
#define Vdbgi                           0x0030U
#define VReserved13                     0x0034U
#define Vferror                         0x0038U
#define VReserved15                     0x003CU
#define VReserved16                     0x0040U
#define VReserved17                     0x0044U
#define VReserved18                     0x0048U
#define VReserved19                     0x004CU
#define VReserved20                     0x0050U
#define VReserved21                     0x0054U
#define VReserved22                     0x0058U
#define VReserved23                     0x005CU
#define Vspuri                          0x0060U
#define VReserved25                     0x0064U
#define VReserved26                     0x0068U
#define VReserved27                     0x006CU
#define VReserved28                     0x0070U
#define VReserved29                     0x0074U
#define VReserved30                     0x0078U
#define VReserved31                     0x007CU
#define Vtrap0                          0x0080U
#define Vtrap1                          0x0084U
#define Vtrap2                          0x0088U
#define Vtrap3                          0x008CU
#define Vtrap4                          0x0090U
#define Vtrap5                          0x0094U
#define Vtrap6                          0x0098U
#define Vtrap7                          0x009CU
#define Vtrap8                          0x00A0U
#define Vtrap9                          0x00A4U
#define Vtrap10                         0x00A8U
#define Vtrap11                         0x00ACU
#define Vtrap12                         0x00B0U
#define Vtrap13                         0x00B4U
#define Vtrap14                         0x00B8U
#define Vtrap15                         0x00BCU
#define VReserved48                     0x00C0U
#define VReserved49                     0x00C4U
#define VReserved50                     0x00C8U
#define VReserved51                     0x00CCU
#define VReserved52                     0x00D0U
#define VReserved53                     0x00D4U
#define VReserved54                     0x00D8U
#define VReserved55                     0x00DCU
#define VReserved56                     0x00E0U
#define VReserved57                     0x00E4U
#define VReserved58                     0x00E8U
#define VReserved59                     0x00ECU
#define VReserved60                     0x00F0U
#define Vunsinstr                       0x00F4U
#define VReserved62                     0x00F8U
#define VReserved63                     0x00FCU
#define Virq                            0x0100U
#define Vlvd                            0x0104U
#define Vlol                            0x0108U
#define Vspi1                           0x010CU
#define Vspi2                           0x0110U
#define Vusb                            0x0114U
#define VReserved70                     0x0118U
#define Vtpm1ch0                        0x011CU
#define Vtpm1ch1                        0x0120U
#define Vtpm1ch2                        0x0124U
#define Vtpm1ch3                        0x0128U
#define Vtpm1ch4                        0x012CU
#define Vtpm1ch5                        0x0130U
#define Vtpm1ovf                        0x0134U
#define Vtpm2ch0                        0x0138U
#define Vtpm2ch1                        0x013CU
#define Vtpm2ovf                        0x0140U
#define Vsci1err                        0x0144U
#define Vsci1rx                         0x0148U
#define Vsci1tx                         0x014CU
#define Vsci2err                        0x0150U
#define Vsci2rx                         0x0154U
#define Vsci2tx                         0x0158U
#define Vkeyboard                       0x015CU
#define Vadc                            0x0160U
#define Vacmpx                          0x0164U
#define Viic1x                          0x0168U
#define Vrtc                            0x016CU
#define Viic2x                          0x0170U
#define Vcmt                            0x0174U
#define Vcanwu                          0x0178U
#define Vcanerr                         0x017CU
#define Vcanrx                          0x0180U
#define Vcantx                          0x0184U
#define Vrnga                           0x0188U
#define VReserved99                     0x018CU
#define VReserved100                    0x0190U
#define VReserved101                    0x0194U
#define VReserved102                    0x0198U
#define VReserved103                    0x019CU
#define VL7swi                          0x01A0U
#define VL6swi                          0x01A4U
#define VL5swi                          0x01A8U
#define VL4swi                          0x01ACU
#define VL3swi                          0x01B0U
#define VL2swi                          0x01B4U
#define VL1swi                          0x01B8U

/**************** registers I/O map ****************/

/*** NVFTRIM - Nonvolatile MCG Fine Trim; 0x000003FE ***/
typedef union {
  byte Byte;
  struct {
    byte FTRIM       :1;                                       /* MCG Fine Trim */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NVFTRIMSTR;
/* Tip for register initialization in the user code:  const byte NVFTRIM_INIT @0x000003FE = <NVFTRIM_INITVAL>; */
#define _NVFTRIM (*(const NVFTRIMSTR *)0x000003FE)
#define NVFTRIM                         _NVFTRIM.Byte
#define NVFTRIM_FTRIM                   _NVFTRIM.Bits.FTRIM

#define NVFTRIM_FTRIM_MASK              1U


/*** NVMCGTRM - Nonvolatile MCG Trim Register; 0x000003FF ***/
typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       /* MCG Trim Setting, bit 0 */
    byte TRIM1       :1;                                       /* MCG Trim Setting, bit 1 */
    byte TRIM2       :1;                                       /* MCG Trim Setting, bit 2 */
    byte TRIM3       :1;                                       /* MCG Trim Setting, bit 3 */
    byte TRIM4       :1;                                       /* MCG Trim Setting, bit 4 */
    byte TRIM5       :1;                                       /* MCG Trim Setting, bit 5 */
    byte TRIM6       :1;                                       /* MCG Trim Setting, bit 6 */
    byte TRIM7       :1;                                       /* MCG Trim Setting, bit 7 */
  } Bits;
} NVMCGTRMSTR;
/* Tip for register initialization in the user code:  const byte NVMCGTRM_INIT @0x000003FF = <NVMCGTRM_INITVAL>; */
#define _NVMCGTRM (*(const NVMCGTRMSTR *)0x000003FF)
#define NVMCGTRM                        _NVMCGTRM.Byte
#define NVMCGTRM_TRIM0                  _NVMCGTRM.Bits.TRIM0
#define NVMCGTRM_TRIM1                  _NVMCGTRM.Bits.TRIM1
#define NVMCGTRM_TRIM2                  _NVMCGTRM.Bits.TRIM2
#define NVMCGTRM_TRIM3                  _NVMCGTRM.Bits.TRIM3
#define NVMCGTRM_TRIM4                  _NVMCGTRM.Bits.TRIM4
#define NVMCGTRM_TRIM5                  _NVMCGTRM.Bits.TRIM5
#define NVMCGTRM_TRIM6                  _NVMCGTRM.Bits.TRIM6
#define NVMCGTRM_TRIM7                  _NVMCGTRM.Bits.TRIM7

#define NVMCGTRM_TRIM0_MASK             1U
#define NVMCGTRM_TRIM1_MASK             2U
#define NVMCGTRM_TRIM2_MASK             4U
#define NVMCGTRM_TRIM3_MASK             8U
#define NVMCGTRM_TRIM4_MASK             16U
#define NVMCGTRM_TRIM5_MASK             32U
#define NVMCGTRM_TRIM6_MASK             64U
#define NVMCGTRM_TRIM7_MASK             128U


/*** NVBACKKEY0 - Backdoor Comparison Key 0; 0x00000400 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 7 */
  } Bits;
} NVBACKKEY0STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT @0x00000400 = <NVBACKKEY0_INITVAL>; */
#define _NVBACKKEY0 (*(const NVBACKKEY0STR *)0x00000400)
#define NVBACKKEY0                      _NVBACKKEY0.Byte
#define NVBACKKEY0_KEY0                 _NVBACKKEY0.Bits.KEY0
#define NVBACKKEY0_KEY1                 _NVBACKKEY0.Bits.KEY1
#define NVBACKKEY0_KEY2                 _NVBACKKEY0.Bits.KEY2
#define NVBACKKEY0_KEY3                 _NVBACKKEY0.Bits.KEY3
#define NVBACKKEY0_KEY4                 _NVBACKKEY0.Bits.KEY4
#define NVBACKKEY0_KEY5                 _NVBACKKEY0.Bits.KEY5
#define NVBACKKEY0_KEY6                 _NVBACKKEY0.Bits.KEY6
#define NVBACKKEY0_KEY7                 _NVBACKKEY0.Bits.KEY7
/* NVBACKKEY_ARR: Access 8 NVBACKKEYx registers in an array */
#define NVBACKKEY_ARR                   ((volatile byte *) &NVBACKKEY0)

#define NVBACKKEY0_KEY0_MASK            1U
#define NVBACKKEY0_KEY1_MASK            2U
#define NVBACKKEY0_KEY2_MASK            4U
#define NVBACKKEY0_KEY3_MASK            8U
#define NVBACKKEY0_KEY4_MASK            16U
#define NVBACKKEY0_KEY5_MASK            32U
#define NVBACKKEY0_KEY6_MASK            64U
#define NVBACKKEY0_KEY7_MASK            128U


/*** NVBACKKEY1 - Backdoor Comparison Key 1; 0x00000401 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 7 */
  } Bits;
} NVBACKKEY1STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT @0x00000401 = <NVBACKKEY1_INITVAL>; */
#define _NVBACKKEY1 (*(const NVBACKKEY1STR *)0x00000401)
#define NVBACKKEY1                      _NVBACKKEY1.Byte
#define NVBACKKEY1_KEY0                 _NVBACKKEY1.Bits.KEY0
#define NVBACKKEY1_KEY1                 _NVBACKKEY1.Bits.KEY1
#define NVBACKKEY1_KEY2                 _NVBACKKEY1.Bits.KEY2
#define NVBACKKEY1_KEY3                 _NVBACKKEY1.Bits.KEY3
#define NVBACKKEY1_KEY4                 _NVBACKKEY1.Bits.KEY4
#define NVBACKKEY1_KEY5                 _NVBACKKEY1.Bits.KEY5
#define NVBACKKEY1_KEY6                 _NVBACKKEY1.Bits.KEY6
#define NVBACKKEY1_KEY7                 _NVBACKKEY1.Bits.KEY7

#define NVBACKKEY1_KEY0_MASK            1U
#define NVBACKKEY1_KEY1_MASK            2U
#define NVBACKKEY1_KEY2_MASK            4U
#define NVBACKKEY1_KEY3_MASK            8U
#define NVBACKKEY1_KEY4_MASK            16U
#define NVBACKKEY1_KEY5_MASK            32U
#define NVBACKKEY1_KEY6_MASK            64U
#define NVBACKKEY1_KEY7_MASK            128U


/*** NVBACKKEY2 - Backdoor Comparison Key 2; 0x00000402 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 7 */
  } Bits;
} NVBACKKEY2STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT @0x00000402 = <NVBACKKEY2_INITVAL>; */
#define _NVBACKKEY2 (*(const NVBACKKEY2STR *)0x00000402)
#define NVBACKKEY2                      _NVBACKKEY2.Byte
#define NVBACKKEY2_KEY0                 _NVBACKKEY2.Bits.KEY0
#define NVBACKKEY2_KEY1                 _NVBACKKEY2.Bits.KEY1
#define NVBACKKEY2_KEY2                 _NVBACKKEY2.Bits.KEY2
#define NVBACKKEY2_KEY3                 _NVBACKKEY2.Bits.KEY3
#define NVBACKKEY2_KEY4                 _NVBACKKEY2.Bits.KEY4
#define NVBACKKEY2_KEY5                 _NVBACKKEY2.Bits.KEY5
#define NVBACKKEY2_KEY6                 _NVBACKKEY2.Bits.KEY6
#define NVBACKKEY2_KEY7                 _NVBACKKEY2.Bits.KEY7

#define NVBACKKEY2_KEY0_MASK            1U
#define NVBACKKEY2_KEY1_MASK            2U
#define NVBACKKEY2_KEY2_MASK            4U
#define NVBACKKEY2_KEY3_MASK            8U
#define NVBACKKEY2_KEY4_MASK            16U
#define NVBACKKEY2_KEY5_MASK            32U
#define NVBACKKEY2_KEY6_MASK            64U
#define NVBACKKEY2_KEY7_MASK            128U


/*** NVBACKKEY3 - Backdoor Comparison Key 3; 0x00000403 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 7 */
  } Bits;
} NVBACKKEY3STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT @0x00000403 = <NVBACKKEY3_INITVAL>; */
#define _NVBACKKEY3 (*(const NVBACKKEY3STR *)0x00000403)
#define NVBACKKEY3                      _NVBACKKEY3.Byte
#define NVBACKKEY3_KEY0                 _NVBACKKEY3.Bits.KEY0
#define NVBACKKEY3_KEY1                 _NVBACKKEY3.Bits.KEY1
#define NVBACKKEY3_KEY2                 _NVBACKKEY3.Bits.KEY2
#define NVBACKKEY3_KEY3                 _NVBACKKEY3.Bits.KEY3
#define NVBACKKEY3_KEY4                 _NVBACKKEY3.Bits.KEY4
#define NVBACKKEY3_KEY5                 _NVBACKKEY3.Bits.KEY5
#define NVBACKKEY3_KEY6                 _NVBACKKEY3.Bits.KEY6
#define NVBACKKEY3_KEY7                 _NVBACKKEY3.Bits.KEY7

#define NVBACKKEY3_KEY0_MASK            1U
#define NVBACKKEY3_KEY1_MASK            2U
#define NVBACKKEY3_KEY2_MASK            4U
#define NVBACKKEY3_KEY3_MASK            8U
#define NVBACKKEY3_KEY4_MASK            16U
#define NVBACKKEY3_KEY5_MASK            32U
#define NVBACKKEY3_KEY6_MASK            64U
#define NVBACKKEY3_KEY7_MASK            128U


/*** NVBACKKEY4 - Backdoor Comparison Key 4; 0x00000404 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 7 */
  } Bits;
} NVBACKKEY4STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT @0x00000404 = <NVBACKKEY4_INITVAL>; */
#define _NVBACKKEY4 (*(const NVBACKKEY4STR *)0x00000404)
#define NVBACKKEY4                      _NVBACKKEY4.Byte
#define NVBACKKEY4_KEY0                 _NVBACKKEY4.Bits.KEY0
#define NVBACKKEY4_KEY1                 _NVBACKKEY4.Bits.KEY1
#define NVBACKKEY4_KEY2                 _NVBACKKEY4.Bits.KEY2
#define NVBACKKEY4_KEY3                 _NVBACKKEY4.Bits.KEY3
#define NVBACKKEY4_KEY4                 _NVBACKKEY4.Bits.KEY4
#define NVBACKKEY4_KEY5                 _NVBACKKEY4.Bits.KEY5
#define NVBACKKEY4_KEY6                 _NVBACKKEY4.Bits.KEY6
#define NVBACKKEY4_KEY7                 _NVBACKKEY4.Bits.KEY7

#define NVBACKKEY4_KEY0_MASK            1U
#define NVBACKKEY4_KEY1_MASK            2U
#define NVBACKKEY4_KEY2_MASK            4U
#define NVBACKKEY4_KEY3_MASK            8U
#define NVBACKKEY4_KEY4_MASK            16U
#define NVBACKKEY4_KEY5_MASK            32U
#define NVBACKKEY4_KEY6_MASK            64U
#define NVBACKKEY4_KEY7_MASK            128U


/*** NVBACKKEY5 - Backdoor Comparison Key 5; 0x00000405 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 7 */
  } Bits;
} NVBACKKEY5STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT @0x00000405 = <NVBACKKEY5_INITVAL>; */
#define _NVBACKKEY5 (*(const NVBACKKEY5STR *)0x00000405)
#define NVBACKKEY5                      _NVBACKKEY5.Byte
#define NVBACKKEY5_KEY0                 _NVBACKKEY5.Bits.KEY0
#define NVBACKKEY5_KEY1                 _NVBACKKEY5.Bits.KEY1
#define NVBACKKEY5_KEY2                 _NVBACKKEY5.Bits.KEY2
#define NVBACKKEY5_KEY3                 _NVBACKKEY5.Bits.KEY3
#define NVBACKKEY5_KEY4                 _NVBACKKEY5.Bits.KEY4
#define NVBACKKEY5_KEY5                 _NVBACKKEY5.Bits.KEY5
#define NVBACKKEY5_KEY6                 _NVBACKKEY5.Bits.KEY6
#define NVBACKKEY5_KEY7                 _NVBACKKEY5.Bits.KEY7

#define NVBACKKEY5_KEY0_MASK            1U
#define NVBACKKEY5_KEY1_MASK            2U
#define NVBACKKEY5_KEY2_MASK            4U
#define NVBACKKEY5_KEY3_MASK            8U
#define NVBACKKEY5_KEY4_MASK            16U
#define NVBACKKEY5_KEY5_MASK            32U
#define NVBACKKEY5_KEY6_MASK            64U
#define NVBACKKEY5_KEY7_MASK            128U


/*** NVBACKKEY6 - Backdoor Comparison Key 6; 0x00000406 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 7 */
  } Bits;
} NVBACKKEY6STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT @0x00000406 = <NVBACKKEY6_INITVAL>; */
#define _NVBACKKEY6 (*(const NVBACKKEY6STR *)0x00000406)
#define NVBACKKEY6                      _NVBACKKEY6.Byte
#define NVBACKKEY6_KEY0                 _NVBACKKEY6.Bits.KEY0
#define NVBACKKEY6_KEY1                 _NVBACKKEY6.Bits.KEY1
#define NVBACKKEY6_KEY2                 _NVBACKKEY6.Bits.KEY2
#define NVBACKKEY6_KEY3                 _NVBACKKEY6.Bits.KEY3
#define NVBACKKEY6_KEY4                 _NVBACKKEY6.Bits.KEY4
#define NVBACKKEY6_KEY5                 _NVBACKKEY6.Bits.KEY5
#define NVBACKKEY6_KEY6                 _NVBACKKEY6.Bits.KEY6
#define NVBACKKEY6_KEY7                 _NVBACKKEY6.Bits.KEY7

#define NVBACKKEY6_KEY0_MASK            1U
#define NVBACKKEY6_KEY1_MASK            2U
#define NVBACKKEY6_KEY2_MASK            4U
#define NVBACKKEY6_KEY3_MASK            8U
#define NVBACKKEY6_KEY4_MASK            16U
#define NVBACKKEY6_KEY5_MASK            32U
#define NVBACKKEY6_KEY6_MASK            64U
#define NVBACKKEY6_KEY7_MASK            128U


/*** NVBACKKEY7 - Backdoor Comparison Key 7; 0x00000407 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 7 */
  } Bits;
} NVBACKKEY7STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT @0x00000407 = <NVBACKKEY7_INITVAL>; */
#define _NVBACKKEY7 (*(const NVBACKKEY7STR *)0x00000407)
#define NVBACKKEY7                      _NVBACKKEY7.Byte
#define NVBACKKEY7_KEY0                 _NVBACKKEY7.Bits.KEY0
#define NVBACKKEY7_KEY1                 _NVBACKKEY7.Bits.KEY1
#define NVBACKKEY7_KEY2                 _NVBACKKEY7.Bits.KEY2
#define NVBACKKEY7_KEY3                 _NVBACKKEY7.Bits.KEY3
#define NVBACKKEY7_KEY4                 _NVBACKKEY7.Bits.KEY4
#define NVBACKKEY7_KEY5                 _NVBACKKEY7.Bits.KEY5
#define NVBACKKEY7_KEY6                 _NVBACKKEY7.Bits.KEY6
#define NVBACKKEY7_KEY7                 _NVBACKKEY7.Bits.KEY7

#define NVBACKKEY7_KEY0_MASK            1U
#define NVBACKKEY7_KEY1_MASK            2U
#define NVBACKKEY7_KEY2_MASK            4U
#define NVBACKKEY7_KEY3_MASK            8U
#define NVBACKKEY7_KEY4_MASK            16U
#define NVBACKKEY7_KEY5_MASK            32U
#define NVBACKKEY7_KEY6_MASK            64U
#define NVBACKKEY7_KEY7_MASK            128U


/*** NVPROT - Nonvolatile Flash Protection Register; 0x0000040D ***/
typedef union {
  byte Byte;
  struct {
    byte FPOPEN      :1;                                       /* Flash Protection Open */
    byte FPS0        :1;                                       /* Flash Protection Size, bit 0 */
    byte FPS1        :1;                                       /* Flash Protection Size, bit 1 */
    byte FPS2        :1;                                       /* Flash Protection Size, bit 2 */
    byte FPS3        :1;                                       /* Flash Protection Size, bit 3 */
    byte FPS4        :1;                                       /* Flash Protection Size, bit 4 */
    byte FPS5        :1;                                       /* Flash Protection Size, bit 5 */
    byte FPS6        :1;                                       /* Flash Protection Size, bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS  :7;
  } MergedBits;
} NVPROTSTR;
/* Tip for register initialization in the user code:  const byte NVPROT_INIT @0x0000040D = <NVPROT_INITVAL>; */
#define _NVPROT (*(const NVPROTSTR *)0x0000040D)
#define NVPROT                          _NVPROT.Byte
#define NVPROT_FPOPEN                   _NVPROT.Bits.FPOPEN
#define NVPROT_FPS0                     _NVPROT.Bits.FPS0
#define NVPROT_FPS1                     _NVPROT.Bits.FPS1
#define NVPROT_FPS2                     _NVPROT.Bits.FPS2
#define NVPROT_FPS3                     _NVPROT.Bits.FPS3
#define NVPROT_FPS4                     _NVPROT.Bits.FPS4
#define NVPROT_FPS5                     _NVPROT.Bits.FPS5
#define NVPROT_FPS6                     _NVPROT.Bits.FPS6
#define NVPROT_FPS                      _NVPROT.MergedBits.grpFPS

#define NVPROT_FPOPEN_MASK              1U
#define NVPROT_FPS0_MASK                2U
#define NVPROT_FPS1_MASK                4U
#define NVPROT_FPS2_MASK                8U
#define NVPROT_FPS3_MASK                16U
#define NVPROT_FPS4_MASK                32U
#define NVPROT_FPS5_MASK                64U
#define NVPROT_FPS6_MASK                128U
#define NVPROT_FPS_MASK                 254U
#define NVPROT_FPS_BITNUM               1U


/*** NVOPT - Nonvolatile Flash Options Register; 0x0000040F ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpKEYEN :2;
  } MergedBits;
} NVOPTSTR;
/* Tip for register initialization in the user code:  const byte NVOPT_INIT @0x0000040F = <NVOPT_INITVAL>; */
#define _NVOPT (*(const NVOPTSTR *)0x0000040F)
#define NVOPT                           _NVOPT.Byte
#define NVOPT_SEC0                      _NVOPT.Bits.SEC0
#define NVOPT_SEC1                      _NVOPT.Bits.SEC1
#define NVOPT_KEYEN0                    _NVOPT.Bits.KEYEN0
#define NVOPT_KEYEN1                    _NVOPT.Bits.KEYEN1
#define NVOPT_SEC                       _NVOPT.MergedBits.grpSEC
#define NVOPT_KEYEN                     _NVOPT.MergedBits.grpKEYEN

#define NVOPT_SEC0_MASK                 1U
#define NVOPT_SEC1_MASK                 2U
#define NVOPT_KEYEN0_MASK               64U
#define NVOPT_KEYEN1_MASK               128U
#define NVOPT_SEC_MASK                  3U
#define NVOPT_SEC_BITNUM                0U
#define NVOPT_KEYEN_MASK                192U
#define NVOPT_KEYEN_BITNUM              6U


/*** RGPIO_DIR - RGPIO Data Direction Register; 0x00C00000 ***/
typedef union {
  word Word;
  struct {
    word DIR0        :1;                                       /* RGPIO data direction bit 0 */
    word DIR1        :1;                                       /* RGPIO data direction bit 1 */
    word DIR2        :1;                                       /* RGPIO data direction bit 2 */
    word DIR3        :1;                                       /* RGPIO data direction bit 3 */
    word DIR4        :1;                                       /* RGPIO data direction bit 4 */
    word DIR5        :1;                                       /* RGPIO data direction bit 5 */
    word DIR6        :1;                                       /* RGPIO data direction bit 6 */
    word DIR7        :1;                                       /* RGPIO data direction bit 7 */
    word DIR8        :1;                                       /* RGPIO data direction bit 8 */
    word DIR9        :1;                                       /* RGPIO data direction bit 9 */
    word DIR10       :1;                                       /* RGPIO data direction bit 10 */
    word DIR11       :1;                                       /* RGPIO data direction bit 11 */
    word DIR12       :1;                                       /* RGPIO data direction bit 12 */
    word DIR13       :1;                                       /* RGPIO data direction bit 13 */
    word DIR14       :1;                                       /* RGPIO data direction bit 14 */
    word DIR15       :1;                                       /* RGPIO data direction bit 15 */
  } Bits;
} RGPIO_DIRSTR;
#define _RGPIO_DIR (*(volatile RGPIO_DIRSTR *)0x00C00000)
#define RGPIO_DIR                       _RGPIO_DIR.Word
#define RGPIO_DIR_DIR0                  _RGPIO_DIR.Bits.DIR0
#define RGPIO_DIR_DIR1                  _RGPIO_DIR.Bits.DIR1
#define RGPIO_DIR_DIR2                  _RGPIO_DIR.Bits.DIR2
#define RGPIO_DIR_DIR3                  _RGPIO_DIR.Bits.DIR3
#define RGPIO_DIR_DIR4                  _RGPIO_DIR.Bits.DIR4
#define RGPIO_DIR_DIR5                  _RGPIO_DIR.Bits.DIR5
#define RGPIO_DIR_DIR6                  _RGPIO_DIR.Bits.DIR6
#define RGPIO_DIR_DIR7                  _RGPIO_DIR.Bits.DIR7
#define RGPIO_DIR_DIR8                  _RGPIO_DIR.Bits.DIR8
#define RGPIO_DIR_DIR9                  _RGPIO_DIR.Bits.DIR9
#define RGPIO_DIR_DIR10                 _RGPIO_DIR.Bits.DIR10
#define RGPIO_DIR_DIR11                 _RGPIO_DIR.Bits.DIR11
#define RGPIO_DIR_DIR12                 _RGPIO_DIR.Bits.DIR12
#define RGPIO_DIR_DIR13                 _RGPIO_DIR.Bits.DIR13
#define RGPIO_DIR_DIR14                 _RGPIO_DIR.Bits.DIR14
#define RGPIO_DIR_DIR15                 _RGPIO_DIR.Bits.DIR15

#define RGPIO_DIR_DIR0_MASK             1U
#define RGPIO_DIR_DIR1_MASK             2U
#define RGPIO_DIR_DIR2_MASK             4U
#define RGPIO_DIR_DIR3_MASK             8U
#define RGPIO_DIR_DIR4_MASK             16U
#define RGPIO_DIR_DIR5_MASK             32U
#define RGPIO_DIR_DIR6_MASK             64U
#define RGPIO_DIR_DIR7_MASK             128U
#define RGPIO_DIR_DIR8_MASK             256U
#define RGPIO_DIR_DIR9_MASK             512U
#define RGPIO_DIR_DIR10_MASK            1024U
#define RGPIO_DIR_DIR11_MASK            2048U
#define RGPIO_DIR_DIR12_MASK            4096U
#define RGPIO_DIR_DIR13_MASK            8192U
#define RGPIO_DIR_DIR14_MASK            16384U
#define RGPIO_DIR_DIR15_MASK            32768U


/*** RGPIO_DATA - RGPIO Data Register; 0x00C00002 ***/
typedef union {
  word Word;
  struct {
    word DATA0       :1;                                       /* RGPIO data bit 0 */
    word DATA1       :1;                                       /* RGPIO data bit 1 */
    word DATA2       :1;                                       /* RGPIO data bit 2 */
    word DATA3       :1;                                       /* RGPIO data bit 3 */
    word DATA4       :1;                                       /* RGPIO data bit 4 */
    word DATA5       :1;                                       /* RGPIO data bit 5 */
    word DATA6       :1;                                       /* RGPIO data bit 6 */
    word DATA7       :1;                                       /* RGPIO data bit 7 */
    word DATA8       :1;                                       /* RGPIO data bit 8 */
    word DATA9       :1;                                       /* RGPIO data bit 9 */
    word DATA10      :1;                                       /* RGPIO data bit 10 */
    word DATA11      :1;                                       /* RGPIO data bit 11 */
    word DATA12      :1;                                       /* RGPIO data bit 12 */
    word DATA13      :1;                                       /* RGPIO data bit 13 */
    word DATA14      :1;                                       /* RGPIO data bit 14 */
    word DATA15      :1;                                       /* RGPIO data bit 15 */
  } Bits;
} RGPIO_DATASTR;
#define _RGPIO_DATA (*(volatile RGPIO_DATASTR *)0x00C00002)
#define RGPIO_DATA                      _RGPIO_DATA.Word
#define RGPIO_DATA_DATA0                _RGPIO_DATA.Bits.DATA0
#define RGPIO_DATA_DATA1                _RGPIO_DATA.Bits.DATA1
#define RGPIO_DATA_DATA2                _RGPIO_DATA.Bits.DATA2
#define RGPIO_DATA_DATA3                _RGPIO_DATA.Bits.DATA3
#define RGPIO_DATA_DATA4                _RGPIO_DATA.Bits.DATA4
#define RGPIO_DATA_DATA5                _RGPIO_DATA.Bits.DATA5
#define RGPIO_DATA_DATA6                _RGPIO_DATA.Bits.DATA6
#define RGPIO_DATA_DATA7                _RGPIO_DATA.Bits.DATA7
#define RGPIO_DATA_DATA8                _RGPIO_DATA.Bits.DATA8
#define RGPIO_DATA_DATA9                _RGPIO_DATA.Bits.DATA9
#define RGPIO_DATA_DATA10               _RGPIO_DATA.Bits.DATA10
#define RGPIO_DATA_DATA11               _RGPIO_DATA.Bits.DATA11
#define RGPIO_DATA_DATA12               _RGPIO_DATA.Bits.DATA12
#define RGPIO_DATA_DATA13               _RGPIO_DATA.Bits.DATA13
#define RGPIO_DATA_DATA14               _RGPIO_DATA.Bits.DATA14
#define RGPIO_DATA_DATA15               _RGPIO_DATA.Bits.DATA15

#define RGPIO_DATA_DATA0_MASK           1U
#define RGPIO_DATA_DATA1_MASK           2U
#define RGPIO_DATA_DATA2_MASK           4U
#define RGPIO_DATA_DATA3_MASK           8U
#define RGPIO_DATA_DATA4_MASK           16U
#define RGPIO_DATA_DATA5_MASK           32U
#define RGPIO_DATA_DATA6_MASK           64U
#define RGPIO_DATA_DATA7_MASK           128U
#define RGPIO_DATA_DATA8_MASK           256U
#define RGPIO_DATA_DATA9_MASK           512U
#define RGPIO_DATA_DATA10_MASK          1024U
#define RGPIO_DATA_DATA11_MASK          2048U
#define RGPIO_DATA_DATA12_MASK          4096U
#define RGPIO_DATA_DATA13_MASK          8192U
#define RGPIO_DATA_DATA14_MASK          16384U
#define RGPIO_DATA_DATA15_MASK          32768U


/*** RGPIO_ENB - RGPIO Pin Enable Register; 0x00C00004 ***/
typedef union {
  word Word;
  struct {
    word ENB0        :1;                                       /* RGPIO enable bit 0 */
    word ENB1        :1;                                       /* RGPIO enable bit 1 */
    word ENB2        :1;                                       /* RGPIO enable bit 2 */
    word ENB3        :1;                                       /* RGPIO enable bit 3 */
    word ENB4        :1;                                       /* RGPIO enable bit 4 */
    word ENB5        :1;                                       /* RGPIO enable bit 5 */
    word ENB6        :1;                                       /* RGPIO enable bit 6 */
    word ENB7        :1;                                       /* RGPIO enable bit 7 */
    word ENB8        :1;                                       /* RGPIO enable bit 8 */
    word ENB9        :1;                                       /* RGPIO enable bit 9 */
    word ENB10       :1;                                       /* RGPIO enable bit 10 */
    word ENB11       :1;                                       /* RGPIO enable bit 11 */
    word ENB12       :1;                                       /* RGPIO enable bit 12 */
    word ENB13       :1;                                       /* RGPIO enable bit 13 */
    word ENB14       :1;                                       /* RGPIO enable bit 14 */
    word ENB15       :1;                                       /* RGPIO enable bit 15 */
  } Bits;
} RGPIO_ENBSTR;
#define _RGPIO_ENB (*(volatile RGPIO_ENBSTR *)0x00C00004)
#define RGPIO_ENB                       _RGPIO_ENB.Word
#define RGPIO_ENB_ENB0                  _RGPIO_ENB.Bits.ENB0
#define RGPIO_ENB_ENB1                  _RGPIO_ENB.Bits.ENB1
#define RGPIO_ENB_ENB2                  _RGPIO_ENB.Bits.ENB2
#define RGPIO_ENB_ENB3                  _RGPIO_ENB.Bits.ENB3
#define RGPIO_ENB_ENB4                  _RGPIO_ENB.Bits.ENB4
#define RGPIO_ENB_ENB5                  _RGPIO_ENB.Bits.ENB5
#define RGPIO_ENB_ENB6                  _RGPIO_ENB.Bits.ENB6
#define RGPIO_ENB_ENB7                  _RGPIO_ENB.Bits.ENB7
#define RGPIO_ENB_ENB8                  _RGPIO_ENB.Bits.ENB8
#define RGPIO_ENB_ENB9                  _RGPIO_ENB.Bits.ENB9
#define RGPIO_ENB_ENB10                 _RGPIO_ENB.Bits.ENB10
#define RGPIO_ENB_ENB11                 _RGPIO_ENB.Bits.ENB11
#define RGPIO_ENB_ENB12                 _RGPIO_ENB.Bits.ENB12
#define RGPIO_ENB_ENB13                 _RGPIO_ENB.Bits.ENB13
#define RGPIO_ENB_ENB14                 _RGPIO_ENB.Bits.ENB14
#define RGPIO_ENB_ENB15                 _RGPIO_ENB.Bits.ENB15

#define RGPIO_ENB_ENB0_MASK             1U
#define RGPIO_ENB_ENB1_MASK             2U
#define RGPIO_ENB_ENB2_MASK             4U
#define RGPIO_ENB_ENB3_MASK             8U
#define RGPIO_ENB_ENB4_MASK             16U
#define RGPIO_ENB_ENB5_MASK             32U
#define RGPIO_ENB_ENB6_MASK             64U
#define RGPIO_ENB_ENB7_MASK             128U
#define RGPIO_ENB_ENB8_MASK             256U
#define RGPIO_ENB_ENB9_MASK             512U
#define RGPIO_ENB_ENB10_MASK            1024U
#define RGPIO_ENB_ENB11_MASK            2048U
#define RGPIO_ENB_ENB12_MASK            4096U
#define RGPIO_ENB_ENB13_MASK            8192U
#define RGPIO_ENB_ENB14_MASK            16384U
#define RGPIO_ENB_ENB15_MASK            32768U


/*** RGPIO_CLR - RGPIO Clear Data Register; 0x00C00006 ***/
typedef union {
  word Word;
  struct {
    word CLR0        :1;                                       /* RGPIO clear data bit 0 */
    word CLR1        :1;                                       /* RGPIO clear data bit 1 */
    word CLR2        :1;                                       /* RGPIO clear data bit 2 */
    word CLR3        :1;                                       /* RGPIO clear data bit 3 */
    word CLR4        :1;                                       /* RGPIO clear data bit 4 */
    word CLR5        :1;                                       /* RGPIO clear data bit 5 */
    word CLR6        :1;                                       /* RGPIO clear data bit 6 */
    word CLR7        :1;                                       /* RGPIO clear data bit 7 */
    word CLR8        :1;                                       /* RGPIO clear data bit 8 */
    word CLR9        :1;                                       /* RGPIO clear data bit 9 */
    word CLR10       :1;                                       /* RGPIO clear data bit 10 */
    word CLR11       :1;                                       /* RGPIO clear data bit 11 */
    word CLR12       :1;                                       /* RGPIO clear data bit 12 */
    word CLR13       :1;                                       /* RGPIO clear data bit 13 */
    word CLR14       :1;                                       /* RGPIO clear data bit 14 */
    word CLR15       :1;                                       /* RGPIO clear data bit 15 */
  } Bits;
} RGPIO_CLRSTR;
#define _RGPIO_CLR (*(volatile RGPIO_CLRSTR *)0x00C00006)
#define RGPIO_CLR                       _RGPIO_CLR.Word
#define RGPIO_CLR_CLR0                  _RGPIO_CLR.Bits.CLR0
#define RGPIO_CLR_CLR1                  _RGPIO_CLR.Bits.CLR1
#define RGPIO_CLR_CLR2                  _RGPIO_CLR.Bits.CLR2
#define RGPIO_CLR_CLR3                  _RGPIO_CLR.Bits.CLR3
#define RGPIO_CLR_CLR4                  _RGPIO_CLR.Bits.CLR4
#define RGPIO_CLR_CLR5                  _RGPIO_CLR.Bits.CLR5
#define RGPIO_CLR_CLR6                  _RGPIO_CLR.Bits.CLR6
#define RGPIO_CLR_CLR7                  _RGPIO_CLR.Bits.CLR7
#define RGPIO_CLR_CLR8                  _RGPIO_CLR.Bits.CLR8
#define RGPIO_CLR_CLR9                  _RGPIO_CLR.Bits.CLR9
#define RGPIO_CLR_CLR10                 _RGPIO_CLR.Bits.CLR10
#define RGPIO_CLR_CLR11                 _RGPIO_CLR.Bits.CLR11
#define RGPIO_CLR_CLR12                 _RGPIO_CLR.Bits.CLR12
#define RGPIO_CLR_CLR13                 _RGPIO_CLR.Bits.CLR13
#define RGPIO_CLR_CLR14                 _RGPIO_CLR.Bits.CLR14
#define RGPIO_CLR_CLR15                 _RGPIO_CLR.Bits.CLR15

#define RGPIO_CLR_CLR0_MASK             1U
#define RGPIO_CLR_CLR1_MASK             2U
#define RGPIO_CLR_CLR2_MASK             4U
#define RGPIO_CLR_CLR3_MASK             8U
#define RGPIO_CLR_CLR4_MASK             16U
#define RGPIO_CLR_CLR5_MASK             32U
#define RGPIO_CLR_CLR6_MASK             64U
#define RGPIO_CLR_CLR7_MASK             128U
#define RGPIO_CLR_CLR8_MASK             256U
#define RGPIO_CLR_CLR9_MASK             512U
#define RGPIO_CLR_CLR10_MASK            1024U
#define RGPIO_CLR_CLR11_MASK            2048U
#define RGPIO_CLR_CLR12_MASK            4096U
#define RGPIO_CLR_CLR13_MASK            8192U
#define RGPIO_CLR_CLR14_MASK            16384U
#define RGPIO_CLR_CLR15_MASK            32768U


/*** RGPIO_SET - RGPIO Set Data Register; 0x00C0000A ***/
typedef union {
  word Word;
  struct {
    word SET0        :1;                                       /* RGPIO set data bit 0 */
    word SET1        :1;                                       /* RGPIO set data bit 1 */
    word SET2        :1;                                       /* RGPIO set data bit 2 */
    word SET3        :1;                                       /* RGPIO set data bit 3 */
    word SET4        :1;                                       /* RGPIO set data bit 4 */
    word SET5        :1;                                       /* RGPIO set data bit 5 */
    word SET6        :1;                                       /* RGPIO set data bit 6 */
    word SET7        :1;                                       /* RGPIO set data bit 7 */
    word SET8        :1;                                       /* RGPIO set data bit 8 */
    word SET9        :1;                                       /* RGPIO set data bit 9 */
    word SET10       :1;                                       /* RGPIO set data bit 10 */
    word SET11       :1;                                       /* RGPIO set data bit 11 */
    word SET12       :1;                                       /* RGPIO set data bit 12 */
    word SET13       :1;                                       /* RGPIO set data bit 13 */
    word SET14       :1;                                       /* RGPIO set data bit 14 */
    word SET15       :1;                                       /* RGPIO set data bit 15 */
  } Bits;
} RGPIO_SETSTR;
#define _RGPIO_SET (*(volatile RGPIO_SETSTR *)0x00C0000A)
#define RGPIO_SET                       _RGPIO_SET.Word
#define RGPIO_SET_SET0                  _RGPIO_SET.Bits.SET0
#define RGPIO_SET_SET1                  _RGPIO_SET.Bits.SET1
#define RGPIO_SET_SET2                  _RGPIO_SET.Bits.SET2
#define RGPIO_SET_SET3                  _RGPIO_SET.Bits.SET3
#define RGPIO_SET_SET4                  _RGPIO_SET.Bits.SET4
#define RGPIO_SET_SET5                  _RGPIO_SET.Bits.SET5
#define RGPIO_SET_SET6                  _RGPIO_SET.Bits.SET6
#define RGPIO_SET_SET7                  _RGPIO_SET.Bits.SET7
#define RGPIO_SET_SET8                  _RGPIO_SET.Bits.SET8
#define RGPIO_SET_SET9                  _RGPIO_SET.Bits.SET9
#define RGPIO_SET_SET10                 _RGPIO_SET.Bits.SET10
#define RGPIO_SET_SET11                 _RGPIO_SET.Bits.SET11
#define RGPIO_SET_SET12                 _RGPIO_SET.Bits.SET12
#define RGPIO_SET_SET13                 _RGPIO_SET.Bits.SET13
#define RGPIO_SET_SET14                 _RGPIO_SET.Bits.SET14
#define RGPIO_SET_SET15                 _RGPIO_SET.Bits.SET15

#define RGPIO_SET_SET0_MASK             1U
#define RGPIO_SET_SET1_MASK             2U
#define RGPIO_SET_SET2_MASK             4U
#define RGPIO_SET_SET3_MASK             8U
#define RGPIO_SET_SET4_MASK             16U
#define RGPIO_SET_SET5_MASK             32U
#define RGPIO_SET_SET6_MASK             64U
#define RGPIO_SET_SET7_MASK             128U
#define RGPIO_SET_SET8_MASK             256U
#define RGPIO_SET_SET9_MASK             512U
#define RGPIO_SET_SET10_MASK            1024U
#define RGPIO_SET_SET11_MASK            2048U
#define RGPIO_SET_SET12_MASK            4096U
#define RGPIO_SET_SET13_MASK            8192U
#define RGPIO_SET_SET14_MASK            16384U
#define RGPIO_SET_SET15_MASK            32768U


/*** RGPIO_TOG - RGPIO Toggle Data Register; 0x00C0000E ***/
typedef union {
  word Word;
  struct {
    word TOG0        :1;                                       /* RGPIO toggle data bit 0 */
    word TOG1        :1;                                       /* RGPIO toggle data bit 1 */
    word TOG2        :1;                                       /* RGPIO toggle data bit 2 */
    word TOG3        :1;                                       /* RGPIO toggle data bit 3 */
    word TOG4        :1;                                       /* RGPIO toggle data bit 4 */
    word TOG5        :1;                                       /* RGPIO toggle data bit 5 */
    word TOG6        :1;                                       /* RGPIO toggle data bit 6 */
    word TOG7        :1;                                       /* RGPIO toggle data bit 7 */
    word TOG8        :1;                                       /* RGPIO toggle data bit 8 */
    word TOG9        :1;                                       /* RGPIO toggle data bit 9 */
    word TOG10       :1;                                       /* RGPIO toggle data bit 10 */
    word TOG11       :1;                                       /* RGPIO toggle data bit 11 */
    word TOG12       :1;                                       /* RGPIO toggle data bit 12 */
    word TOG13       :1;                                       /* RGPIO toggle data bit 13 */
    word TOG14       :1;                                       /* RGPIO toggle data bit 14 */
    word TOG15       :1;                                       /* RGPIO toggle data bit 15 */
  } Bits;
} RGPIO_TOGSTR;
#define _RGPIO_TOG (*(volatile RGPIO_TOGSTR *)0x00C0000E)
#define RGPIO_TOG                       _RGPIO_TOG.Word
#define RGPIO_TOG_TOG0                  _RGPIO_TOG.Bits.TOG0
#define RGPIO_TOG_TOG1                  _RGPIO_TOG.Bits.TOG1
#define RGPIO_TOG_TOG2                  _RGPIO_TOG.Bits.TOG2
#define RGPIO_TOG_TOG3                  _RGPIO_TOG.Bits.TOG3
#define RGPIO_TOG_TOG4                  _RGPIO_TOG.Bits.TOG4
#define RGPIO_TOG_TOG5                  _RGPIO_TOG.Bits.TOG5
#define RGPIO_TOG_TOG6                  _RGPIO_TOG.Bits.TOG6
#define RGPIO_TOG_TOG7                  _RGPIO_TOG.Bits.TOG7
#define RGPIO_TOG_TOG8                  _RGPIO_TOG.Bits.TOG8
#define RGPIO_TOG_TOG9                  _RGPIO_TOG.Bits.TOG9
#define RGPIO_TOG_TOG10                 _RGPIO_TOG.Bits.TOG10
#define RGPIO_TOG_TOG11                 _RGPIO_TOG.Bits.TOG11
#define RGPIO_TOG_TOG12                 _RGPIO_TOG.Bits.TOG12
#define RGPIO_TOG_TOG13                 _RGPIO_TOG.Bits.TOG13
#define RGPIO_TOG_TOG14                 _RGPIO_TOG.Bits.TOG14
#define RGPIO_TOG_TOG15                 _RGPIO_TOG.Bits.TOG15

#define RGPIO_TOG_TOG0_MASK             1U
#define RGPIO_TOG_TOG1_MASK             2U
#define RGPIO_TOG_TOG2_MASK             4U
#define RGPIO_TOG_TOG3_MASK             8U
#define RGPIO_TOG_TOG4_MASK             16U
#define RGPIO_TOG_TOG5_MASK             32U
#define RGPIO_TOG_TOG6_MASK             64U
#define RGPIO_TOG_TOG7_MASK             128U
#define RGPIO_TOG_TOG8_MASK             256U
#define RGPIO_TOG_TOG9_MASK             512U
#define RGPIO_TOG_TOG10_MASK            1024U
#define RGPIO_TOG_TOG11_MASK            2048U
#define RGPIO_TOG_TOG12_MASK            4096U
#define RGPIO_TOG_TOG13_MASK            8192U
#define RGPIO_TOG_TOG14_MASK            16384U
#define RGPIO_TOG_TOG15_MASK            32768U


/*** PTAD - Port A Data Register; 0xFFFF8000 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAD0       :1;                                       /* Port A Data Register Bit 0 */
    byte PTAD1       :1;                                       /* Port A Data Register Bit 1 */
    byte PTAD2       :1;                                       /* Port A Data Register Bit 2 */
    byte PTAD3       :1;                                       /* Port A Data Register Bit 3 */
    byte PTAD4       :1;                                       /* Port A Data Register Bit 4 */
    byte PTAD5       :1;                                       /* Port A Data Register Bit 5 */
    byte PTAD6       :1;                                       /* Port A Data Register Bit 6 */
    byte PTAD7       :1;                                       /* Port A Data Register Bit 7 */
  } Bits;
} PTADSTR;
#define _PTAD (*(volatile PTADSTR *)0xFFFF8000)
#define PTAD                            _PTAD.Byte
#define PTAD_PTAD0                      _PTAD.Bits.PTAD0
#define PTAD_PTAD1                      _PTAD.Bits.PTAD1
#define PTAD_PTAD2                      _PTAD.Bits.PTAD2
#define PTAD_PTAD3                      _PTAD.Bits.PTAD3
#define PTAD_PTAD4                      _PTAD.Bits.PTAD4
#define PTAD_PTAD5                      _PTAD.Bits.PTAD5
#define PTAD_PTAD6                      _PTAD.Bits.PTAD6
#define PTAD_PTAD7                      _PTAD.Bits.PTAD7

#define PTAD_PTAD0_MASK                 1U
#define PTAD_PTAD1_MASK                 2U
#define PTAD_PTAD2_MASK                 4U
#define PTAD_PTAD3_MASK                 8U
#define PTAD_PTAD4_MASK                 16U
#define PTAD_PTAD5_MASK                 32U
#define PTAD_PTAD6_MASK                 64U
#define PTAD_PTAD7_MASK                 128U


/*** PTADD - Port A Data Direction Register; 0xFFFF8001 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADD0      :1;                                       /* Data Direction for Port A Bit 0 */
    byte PTADD1      :1;                                       /* Data Direction for Port A Bit 1 */
    byte PTADD2      :1;                                       /* Data Direction for Port A Bit 2 */
    byte PTADD3      :1;                                       /* Data Direction for Port A Bit 3 */
    byte PTADD4      :1;                                       /* Data Direction for Port A Bit 4 */
    byte PTADD5      :1;                                       /* Data Direction for Port A Bit 5 */
    byte PTADD6      :1;                                       /* Data Direction for Port A Bit 6 */
    byte PTADD7      :1;                                       /* Data Direction for Port A Bit 7 */
  } Bits;
} PTADDSTR;
#define _PTADD (*(volatile PTADDSTR *)0xFFFF8001)
#define PTADD                           _PTADD.Byte
#define PTADD_PTADD0                    _PTADD.Bits.PTADD0
#define PTADD_PTADD1                    _PTADD.Bits.PTADD1
#define PTADD_PTADD2                    _PTADD.Bits.PTADD2
#define PTADD_PTADD3                    _PTADD.Bits.PTADD3
#define PTADD_PTADD4                    _PTADD.Bits.PTADD4
#define PTADD_PTADD5                    _PTADD.Bits.PTADD5
#define PTADD_PTADD6                    _PTADD.Bits.PTADD6
#define PTADD_PTADD7                    _PTADD.Bits.PTADD7

#define PTADD_PTADD0_MASK               1U
#define PTADD_PTADD1_MASK               2U
#define PTADD_PTADD2_MASK               4U
#define PTADD_PTADD3_MASK               8U
#define PTADD_PTADD4_MASK               16U
#define PTADD_PTADD5_MASK               32U
#define PTADD_PTADD6_MASK               64U
#define PTADD_PTADD7_MASK               128U


/*** PTBD - Port B Data Register; 0xFFFF8002 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBD0       :1;                                       /* Port B Data Register Bit 0 */
    byte PTBD1       :1;                                       /* Port B Data Register Bit 1 */
    byte PTBD2       :1;                                       /* Port B Data Register Bit 2 */
    byte PTBD3       :1;                                       /* Port B Data Register Bit 3 */
    byte PTBD4       :1;                                       /* Port B Data Register Bit 4 */
    byte PTBD5       :1;                                       /* Port B Data Register Bit 5 */
    byte PTBD6       :1;                                       /* Port B Data Register Bit 6 */
    byte PTBD7       :1;                                       /* Port B Data Register Bit 7 */
  } Bits;
} PTBDSTR;
#define _PTBD (*(volatile PTBDSTR *)0xFFFF8002)
#define PTBD                            _PTBD.Byte
#define PTBD_PTBD0                      _PTBD.Bits.PTBD0
#define PTBD_PTBD1                      _PTBD.Bits.PTBD1
#define PTBD_PTBD2                      _PTBD.Bits.PTBD2
#define PTBD_PTBD3                      _PTBD.Bits.PTBD3
#define PTBD_PTBD4                      _PTBD.Bits.PTBD4
#define PTBD_PTBD5                      _PTBD.Bits.PTBD5
#define PTBD_PTBD6                      _PTBD.Bits.PTBD6
#define PTBD_PTBD7                      _PTBD.Bits.PTBD7

#define PTBD_PTBD0_MASK                 1U
#define PTBD_PTBD1_MASK                 2U
#define PTBD_PTBD2_MASK                 4U
#define PTBD_PTBD3_MASK                 8U
#define PTBD_PTBD4_MASK                 16U
#define PTBD_PTBD5_MASK                 32U
#define PTBD_PTBD6_MASK                 64U
#define PTBD_PTBD7_MASK                 128U


/*** PTBDD - Port B Data Direction Register; 0xFFFF8003 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDD0      :1;                                       /* Data Direction for Port B Bit 0 */
    byte PTBDD1      :1;                                       /* Data Direction for Port B Bit 1 */
    byte PTBDD2      :1;                                       /* Data Direction for Port B Bit 2 */
    byte PTBDD3      :1;                                       /* Data Direction for Port B Bit 3 */
    byte PTBDD4      :1;                                       /* Data Direction for Port B Bit 4 */
    byte PTBDD5      :1;                                       /* Data Direction for Port B Bit 5 */
    byte PTBDD6      :1;                                       /* Data Direction for Port B Bit 6 */
    byte PTBDD7      :1;                                       /* Data Direction for Port B Bit 7 */
  } Bits;
} PTBDDSTR;
#define _PTBDD (*(volatile PTBDDSTR *)0xFFFF8003)
#define PTBDD                           _PTBDD.Byte
#define PTBDD_PTBDD0                    _PTBDD.Bits.PTBDD0
#define PTBDD_PTBDD1                    _PTBDD.Bits.PTBDD1
#define PTBDD_PTBDD2                    _PTBDD.Bits.PTBDD2
#define PTBDD_PTBDD3                    _PTBDD.Bits.PTBDD3
#define PTBDD_PTBDD4                    _PTBDD.Bits.PTBDD4
#define PTBDD_PTBDD5                    _PTBDD.Bits.PTBDD5
#define PTBDD_PTBDD6                    _PTBDD.Bits.PTBDD6
#define PTBDD_PTBDD7                    _PTBDD.Bits.PTBDD7

#define PTBDD_PTBDD0_MASK               1U
#define PTBDD_PTBDD1_MASK               2U
#define PTBDD_PTBDD2_MASK               4U
#define PTBDD_PTBDD3_MASK               8U
#define PTBDD_PTBDD4_MASK               16U
#define PTBDD_PTBDD5_MASK               32U
#define PTBDD_PTBDD6_MASK               64U
#define PTBDD_PTBDD7_MASK               128U


/*** PTCD - Port C Data Register; 0xFFFF8004 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCD0       :1;                                       /* Port C Data Register Bit 0 */
    byte PTCD1       :1;                                       /* Port C Data Register Bit 1 */
    byte PTCD2       :1;                                       /* Port C Data Register Bit 2 */
    byte PTCD3       :1;                                       /* Port C Data Register Bit 3 */
    byte PTCD4       :1;                                       /* Port C Data Register Bit 4 */
    byte PTCD5       :1;                                       /* Port C Data Register Bit 5 */
    byte PTCD6       :1;                                       /* Port C Data Register Bit 6 */
    byte PTCD7       :1;                                       /* Port C Data Register Bit 7 */
  } Bits;
} PTCDSTR;
#define _PTCD (*(volatile PTCDSTR *)0xFFFF8004)
#define PTCD                            _PTCD.Byte
#define PTCD_PTCD0                      _PTCD.Bits.PTCD0
#define PTCD_PTCD1                      _PTCD.Bits.PTCD1
#define PTCD_PTCD2                      _PTCD.Bits.PTCD2
#define PTCD_PTCD3                      _PTCD.Bits.PTCD3
#define PTCD_PTCD4                      _PTCD.Bits.PTCD4
#define PTCD_PTCD5                      _PTCD.Bits.PTCD5
#define PTCD_PTCD6                      _PTCD.Bits.PTCD6
#define PTCD_PTCD7                      _PTCD.Bits.PTCD7

#define PTCD_PTCD0_MASK                 1U
#define PTCD_PTCD1_MASK                 2U
#define PTCD_PTCD2_MASK                 4U
#define PTCD_PTCD3_MASK                 8U
#define PTCD_PTCD4_MASK                 16U
#define PTCD_PTCD5_MASK                 32U
#define PTCD_PTCD6_MASK                 64U
#define PTCD_PTCD7_MASK                 128U


/*** PTCDD - Port C Data Direction Register; 0xFFFF8005 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCDD0      :1;                                       /* Data Direction for Port C Bit 0 */
    byte PTCDD1      :1;                                       /* Data Direction for Port C Bit 1 */
    byte PTCDD2      :1;                                       /* Data Direction for Port C Bit 2 */
    byte PTCDD3      :1;                                       /* Data Direction for Port C Bit 3 */
    byte PTCDD4      :1;                                       /* Data Direction for Port C Bit 4 */
    byte PTCDD5      :1;                                       /* Data Direction for Port C Bit 5 */
    byte PTCDD6      :1;                                       /* Data Direction for Port C Bit 6 */
    byte PTCDD7      :1;                                       /* Data Direction for Port C Bit 7 */
  } Bits;
} PTCDDSTR;
#define _PTCDD (*(volatile PTCDDSTR *)0xFFFF8005)
#define PTCDD                           _PTCDD.Byte
#define PTCDD_PTCDD0                    _PTCDD.Bits.PTCDD0
#define PTCDD_PTCDD1                    _PTCDD.Bits.PTCDD1
#define PTCDD_PTCDD2                    _PTCDD.Bits.PTCDD2
#define PTCDD_PTCDD3                    _PTCDD.Bits.PTCDD3
#define PTCDD_PTCDD4                    _PTCDD.Bits.PTCDD4
#define PTCDD_PTCDD5                    _PTCDD.Bits.PTCDD5
#define PTCDD_PTCDD6                    _PTCDD.Bits.PTCDD6
#define PTCDD_PTCDD7                    _PTCDD.Bits.PTCDD7

#define PTCDD_PTCDD0_MASK               1U
#define PTCDD_PTCDD1_MASK               2U
#define PTCDD_PTCDD2_MASK               4U
#define PTCDD_PTCDD3_MASK               8U
#define PTCDD_PTCDD4_MASK               16U
#define PTCDD_PTCDD5_MASK               32U
#define PTCDD_PTCDD6_MASK               64U
#define PTCDD_PTCDD7_MASK               128U


/*** PTDD - Port D Data Register; 0xFFFF8006 ***/
typedef union {
  byte Byte;
  struct {
    byte PTDD0       :1;                                       /* Port D Data Register Bit 0 */
    byte PTDD1       :1;                                       /* Port D Data Register Bit 1 */
    byte PTDD2       :1;                                       /* Port D Data Register Bit 2 */
    byte PTDD3       :1;                                       /* Port D Data Register Bit 3 */
    byte PTDD4       :1;                                       /* Port D Data Register Bit 4 */
    byte PTDD5       :1;                                       /* Port D Data Register Bit 5 */
    byte PTDD6       :1;                                       /* Port D Data Register Bit 6 */
    byte PTDD7       :1;                                       /* Port D Data Register Bit 7 */
  } Bits;
} PTDDSTR;
#define _PTDD (*(volatile PTDDSTR *)0xFFFF8006)
#define PTDD                            _PTDD.Byte
#define PTDD_PTDD0                      _PTDD.Bits.PTDD0
#define PTDD_PTDD1                      _PTDD.Bits.PTDD1
#define PTDD_PTDD2                      _PTDD.Bits.PTDD2
#define PTDD_PTDD3                      _PTDD.Bits.PTDD3
#define PTDD_PTDD4                      _PTDD.Bits.PTDD4
#define PTDD_PTDD5                      _PTDD.Bits.PTDD5
#define PTDD_PTDD6                      _PTDD.Bits.PTDD6
#define PTDD_PTDD7                      _PTDD.Bits.PTDD7

#define PTDD_PTDD0_MASK                 1U
#define PTDD_PTDD1_MASK                 2U
#define PTDD_PTDD2_MASK                 4U
#define PTDD_PTDD3_MASK                 8U
#define PTDD_PTDD4_MASK                 16U
#define PTDD_PTDD5_MASK                 32U
#define PTDD_PTDD6_MASK                 64U
#define PTDD_PTDD7_MASK                 128U


/*** PTDDD - Port D Data Direction Register; 0xFFFF8007 ***/
typedef union {
  byte Byte;
  struct {
    byte PTDDD0      :1;                                       /* Data Direction for Port D Bit 0 */
    byte PTDDD1      :1;                                       /* Data Direction for Port D Bit 1 */
    byte PTDDD2      :1;                                       /* Data Direction for Port D Bit 2 */
    byte PTDDD3      :1;                                       /* Data Direction for Port D Bit 3 */
    byte PTDDD4      :1;                                       /* Data Direction for Port D Bit 4 */
    byte PTDDD5      :1;                                       /* Data Direction for Port D Bit 5 */
    byte PTDDD6      :1;                                       /* Data Direction for Port D Bit 6 */
    byte PTDDD7      :1;                                       /* Data Direction for Port D Bit 7 */
  } Bits;
} PTDDDSTR;
#define _PTDDD (*(volatile PTDDDSTR *)0xFFFF8007)
#define PTDDD                           _PTDDD.Byte
#define PTDDD_PTDDD0                    _PTDDD.Bits.PTDDD0
#define PTDDD_PTDDD1                    _PTDDD.Bits.PTDDD1
#define PTDDD_PTDDD2                    _PTDDD.Bits.PTDDD2
#define PTDDD_PTDDD3                    _PTDDD.Bits.PTDDD3
#define PTDDD_PTDDD4                    _PTDDD.Bits.PTDDD4
#define PTDDD_PTDDD5                    _PTDDD.Bits.PTDDD5
#define PTDDD_PTDDD6                    _PTDDD.Bits.PTDDD6
#define PTDDD_PTDDD7                    _PTDDD.Bits.PTDDD7

#define PTDDD_PTDDD0_MASK               1U
#define PTDDD_PTDDD1_MASK               2U
#define PTDDD_PTDDD2_MASK               4U
#define PTDDD_PTDDD3_MASK               8U
#define PTDDD_PTDDD4_MASK               16U
#define PTDDD_PTDDD5_MASK               32U
#define PTDDD_PTDDD6_MASK               64U
#define PTDDD_PTDDD7_MASK               128U


/*** PTED - Port E Data Register; 0xFFFF8008 ***/
typedef union {
  byte Byte;
  struct {
    byte PTED0       :1;                                       /* Port E Data Register Bit 0 */
    byte PTED1       :1;                                       /* Port E Data Register Bit 1 */
    byte PTED2       :1;                                       /* Port E Data Register Bit 2 */
    byte PTED3       :1;                                       /* Port E Data Register Bit 3 */
    byte PTED4       :1;                                       /* Port E Data Register Bit 4 */
    byte PTED5       :1;                                       /* Port E Data Register Bit 5 */
    byte PTED6       :1;                                       /* Port E Data Register Bit 6 */
    byte PTED7       :1;                                       /* Port E Data Register Bit 7 */
  } Bits;
} PTEDSTR;
#define _PTED (*(volatile PTEDSTR *)0xFFFF8008)
#define PTED                            _PTED.Byte
#define PTED_PTED0                      _PTED.Bits.PTED0
#define PTED_PTED1                      _PTED.Bits.PTED1
#define PTED_PTED2                      _PTED.Bits.PTED2
#define PTED_PTED3                      _PTED.Bits.PTED3
#define PTED_PTED4                      _PTED.Bits.PTED4
#define PTED_PTED5                      _PTED.Bits.PTED5
#define PTED_PTED6                      _PTED.Bits.PTED6
#define PTED_PTED7                      _PTED.Bits.PTED7

#define PTED_PTED0_MASK                 1U
#define PTED_PTED1_MASK                 2U
#define PTED_PTED2_MASK                 4U
#define PTED_PTED3_MASK                 8U
#define PTED_PTED4_MASK                 16U
#define PTED_PTED5_MASK                 32U
#define PTED_PTED6_MASK                 64U
#define PTED_PTED7_MASK                 128U


/*** PTEDD - Port E Data Direction Register; 0xFFFF8009 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEDD0      :1;                                       /* Data Direction for Port E Bit 0 */
    byte PTEDD1      :1;                                       /* Data Direction for Port E Bit 1 */
    byte PTEDD2      :1;                                       /* Data Direction for Port E Bit 2 */
    byte PTEDD3      :1;                                       /* Data Direction for Port E Bit 3 */
    byte PTEDD4      :1;                                       /* Data Direction for Port E Bit 4 */
    byte PTEDD5      :1;                                       /* Data Direction for Port E Bit 5 */
    byte PTEDD6      :1;                                       /* Data Direction for Port E Bit 6 */
    byte PTEDD7      :1;                                       /* Data Direction for Port E Bit 7 */
  } Bits;
} PTEDDSTR;
#define _PTEDD (*(volatile PTEDDSTR *)0xFFFF8009)
#define PTEDD                           _PTEDD.Byte
#define PTEDD_PTEDD0                    _PTEDD.Bits.PTEDD0
#define PTEDD_PTEDD1                    _PTEDD.Bits.PTEDD1
#define PTEDD_PTEDD2                    _PTEDD.Bits.PTEDD2
#define PTEDD_PTEDD3                    _PTEDD.Bits.PTEDD3
#define PTEDD_PTEDD4                    _PTEDD.Bits.PTEDD4
#define PTEDD_PTEDD5                    _PTEDD.Bits.PTEDD5
#define PTEDD_PTEDD6                    _PTEDD.Bits.PTEDD6
#define PTEDD_PTEDD7                    _PTEDD.Bits.PTEDD7

#define PTEDD_PTEDD0_MASK               1U
#define PTEDD_PTEDD1_MASK               2U
#define PTEDD_PTEDD2_MASK               4U
#define PTEDD_PTEDD3_MASK               8U
#define PTEDD_PTEDD4_MASK               16U
#define PTEDD_PTEDD5_MASK               32U
#define PTEDD_PTEDD6_MASK               64U
#define PTEDD_PTEDD7_MASK               128U


/*** PTFD - Port F Data Register; 0xFFFF800A ***/
typedef union {
  byte Byte;
  struct {
    byte PTFD0       :1;                                       /* Port F Data Register Bit 0 */
    byte PTFD1       :1;                                       /* Port F Data Register Bit 1 */
    byte PTFD2       :1;                                       /* Port F Data Register Bit 2 */
    byte PTFD3       :1;                                       /* Port F Data Register Bit 3 */
    byte PTFD4       :1;                                       /* Port F Data Register Bit 4 */
    byte PTFD5       :1;                                       /* Port F Data Register Bit 5 */
    byte PTFD6       :1;                                       /* Port F Data Register Bit 6 */
    byte PTFD7       :1;                                       /* Port F Data Register Bit 7 */
  } Bits;
} PTFDSTR;
#define _PTFD (*(volatile PTFDSTR *)0xFFFF800A)
#define PTFD                            _PTFD.Byte
#define PTFD_PTFD0                      _PTFD.Bits.PTFD0
#define PTFD_PTFD1                      _PTFD.Bits.PTFD1
#define PTFD_PTFD2                      _PTFD.Bits.PTFD2
#define PTFD_PTFD3                      _PTFD.Bits.PTFD3
#define PTFD_PTFD4                      _PTFD.Bits.PTFD4
#define PTFD_PTFD5                      _PTFD.Bits.PTFD5
#define PTFD_PTFD6                      _PTFD.Bits.PTFD6
#define PTFD_PTFD7                      _PTFD.Bits.PTFD7

#define PTFD_PTFD0_MASK                 1U
#define PTFD_PTFD1_MASK                 2U
#define PTFD_PTFD2_MASK                 4U
#define PTFD_PTFD3_MASK                 8U
#define PTFD_PTFD4_MASK                 16U
#define PTFD_PTFD5_MASK                 32U
#define PTFD_PTFD6_MASK                 64U
#define PTFD_PTFD7_MASK                 128U


/*** PTFDD - Port F Data Direction Register; 0xFFFF800B ***/
typedef union {
  byte Byte;
  struct {
    byte PTFDD0      :1;                                       /* Data Direction for Port F Bit 0 */
    byte PTFDD1      :1;                                       /* Data Direction for Port F Bit 1 */
    byte PTFDD2      :1;                                       /* Data Direction for Port F Bit 2 */
    byte PTFDD3      :1;                                       /* Data Direction for Port F Bit 3 */
    byte PTFDD4      :1;                                       /* Data Direction for Port F Bit 4 */
    byte PTFDD5      :1;                                       /* Data Direction for Port F Bit 5 */
    byte PTFDD6      :1;                                       /* Data Direction for Port F Bit 6 */
    byte PTFDD7      :1;                                       /* Data Direction for Port F Bit 7 */
  } Bits;
} PTFDDSTR;
#define _PTFDD (*(volatile PTFDDSTR *)0xFFFF800B)
#define PTFDD                           _PTFDD.Byte
#define PTFDD_PTFDD0                    _PTFDD.Bits.PTFDD0
#define PTFDD_PTFDD1                    _PTFDD.Bits.PTFDD1
#define PTFDD_PTFDD2                    _PTFDD.Bits.PTFDD2
#define PTFDD_PTFDD3                    _PTFDD.Bits.PTFDD3
#define PTFDD_PTFDD4                    _PTFDD.Bits.PTFDD4
#define PTFDD_PTFDD5                    _PTFDD.Bits.PTFDD5
#define PTFDD_PTFDD6                    _PTFDD.Bits.PTFDD6
#define PTFDD_PTFDD7                    _PTFDD.Bits.PTFDD7

#define PTFDD_PTFDD0_MASK               1U
#define PTFDD_PTFDD1_MASK               2U
#define PTFDD_PTFDD2_MASK               4U
#define PTFDD_PTFDD3_MASK               8U
#define PTFDD_PTFDD4_MASK               16U
#define PTFDD_PTFDD5_MASK               32U
#define PTFDD_PTFDD6_MASK               64U
#define PTFDD_PTFDD7_MASK               128U


/*** PTGD - Port G Data Register; 0xFFFF800C ***/
typedef union {
  byte Byte;
  struct {
    byte PTGD0       :1;                                       /* Port G Data Register Bit 0 */
    byte PTGD1       :1;                                       /* Port G Data Register Bit 1 */
    byte PTGD2       :1;                                       /* Port G Data Register Bit 2 */
    byte PTGD3       :1;                                       /* Port G Data Register Bit 3 */
    byte PTGD4       :1;                                       /* Port G Data Register Bit 4 */
    byte PTGD5       :1;                                       /* Port G Data Register Bit 5 */
    byte PTGD6       :1;                                       /* Port G Data Register Bit 6 */
    byte PTGD7       :1;                                       /* Port G Data Register Bit 7 */
  } Bits;
} PTGDSTR;
#define _PTGD (*(volatile PTGDSTR *)0xFFFF800C)
#define PTGD                            _PTGD.Byte
#define PTGD_PTGD0                      _PTGD.Bits.PTGD0
#define PTGD_PTGD1                      _PTGD.Bits.PTGD1
#define PTGD_PTGD2                      _PTGD.Bits.PTGD2
#define PTGD_PTGD3                      _PTGD.Bits.PTGD3
#define PTGD_PTGD4                      _PTGD.Bits.PTGD4
#define PTGD_PTGD5                      _PTGD.Bits.PTGD5
#define PTGD_PTGD6                      _PTGD.Bits.PTGD6
#define PTGD_PTGD7                      _PTGD.Bits.PTGD7

#define PTGD_PTGD0_MASK                 1U
#define PTGD_PTGD1_MASK                 2U
#define PTGD_PTGD2_MASK                 4U
#define PTGD_PTGD3_MASK                 8U
#define PTGD_PTGD4_MASK                 16U
#define PTGD_PTGD5_MASK                 32U
#define PTGD_PTGD6_MASK                 64U
#define PTGD_PTGD7_MASK                 128U


/*** PTGDD - Port G Data Direction Register; 0xFFFF800D ***/
typedef union {
  byte Byte;
  struct {
    byte PTGDD0      :1;                                       /* Data Direction for Port G Bit 0 */
    byte PTGDD1      :1;                                       /* Data Direction for Port G Bit 1 */
    byte PTGDD2      :1;                                       /* Data Direction for Port G Bit 2 */
    byte PTGDD3      :1;                                       /* Data Direction for Port G Bit 3 */
    byte PTGDD4      :1;                                       /* Data Direction for Port G Bit 4 */
    byte PTGDD5      :1;                                       /* Data Direction for Port G Bit 5 */
    byte PTGDD6      :1;                                       /* Data Direction for Port G Bit 6 */
    byte PTGDD7      :1;                                       /* Data Direction for Port G Bit 7 */
  } Bits;
} PTGDDSTR;
#define _PTGDD (*(volatile PTGDDSTR *)0xFFFF800D)
#define PTGDD                           _PTGDD.Byte
#define PTGDD_PTGDD0                    _PTGDD.Bits.PTGDD0
#define PTGDD_PTGDD1                    _PTGDD.Bits.PTGDD1
#define PTGDD_PTGDD2                    _PTGDD.Bits.PTGDD2
#define PTGDD_PTGDD3                    _PTGDD.Bits.PTGDD3
#define PTGDD_PTGDD4                    _PTGDD.Bits.PTGDD4
#define PTGDD_PTGDD5                    _PTGDD.Bits.PTGDD5
#define PTGDD_PTGDD6                    _PTGDD.Bits.PTGDD6
#define PTGDD_PTGDD7                    _PTGDD.Bits.PTGDD7

#define PTGDD_PTGDD0_MASK               1U
#define PTGDD_PTGDD1_MASK               2U
#define PTGDD_PTGDD2_MASK               4U
#define PTGDD_PTGDD3_MASK               8U
#define PTGDD_PTGDD4_MASK               16U
#define PTGDD_PTGDD5_MASK               32U
#define PTGDD_PTGDD6_MASK               64U
#define PTGDD_PTGDD7_MASK               128U


/*** ACMPSC - ACMP Status and Control Register; 0xFFFF800E ***/
typedef union {
  byte Byte;
  struct {
    byte ACMOD0      :1;                                       /* Analog Comparator Mode Bit 0 */
    byte ACMOD1      :1;                                       /* Analog Comparator Mode Bit 1 */
    byte ACOPE       :1;                                       /* Analog Comparator Output Pin Enable */
    byte ACO         :1;                                       /* Analog Comparator Output */
    byte ACIE        :1;                                       /* Analog Comparator Interrupt Enable */
    byte ACF         :1;                                       /* Analog Comparator Flag */
    byte ACBGS       :1;                                       /* Analog Comparator Bandgap Select */
    byte ACME        :1;                                       /* Analog Comparator Module Enable */
  } Bits;
  struct {
    byte grpACMOD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ACMPSCSTR;
#define _ACMPSC (*(volatile ACMPSCSTR *)0xFFFF800E)
#define ACMPSC                          _ACMPSC.Byte
#define ACMPSC_ACMOD0                   _ACMPSC.Bits.ACMOD0
#define ACMPSC_ACMOD1                   _ACMPSC.Bits.ACMOD1
#define ACMPSC_ACOPE                    _ACMPSC.Bits.ACOPE
#define ACMPSC_ACO                      _ACMPSC.Bits.ACO
#define ACMPSC_ACIE                     _ACMPSC.Bits.ACIE
#define ACMPSC_ACF                      _ACMPSC.Bits.ACF
#define ACMPSC_ACBGS                    _ACMPSC.Bits.ACBGS
#define ACMPSC_ACME                     _ACMPSC.Bits.ACME
#define ACMPSC_ACMOD                    _ACMPSC.MergedBits.grpACMOD

#define ACMPSC_ACMOD0_MASK              1U
#define ACMPSC_ACMOD1_MASK              2U
#define ACMPSC_ACOPE_MASK               4U
#define ACMPSC_ACO_MASK                 8U
#define ACMPSC_ACIE_MASK                16U
#define ACMPSC_ACF_MASK                 32U
#define ACMPSC_ACBGS_MASK               64U
#define ACMPSC_ACME_MASK                128U
#define ACMPSC_ACMOD_MASK               3U
#define ACMPSC_ACMOD_BITNUM             0U


/*** ADCSC1 - Status and Control Register 1; 0xFFFF8010 ***/
typedef union {
  byte Byte;
  struct {
    byte ADCH0       :1;                                       /* Input Channel Select Bit 0 */
    byte ADCH1       :1;                                       /* Input Channel Select Bit 1 */
    byte ADCH2       :1;                                       /* Input Channel Select Bit 2 */
    byte ADCH3       :1;                                       /* Input Channel Select Bit 3 */
    byte ADCH4       :1;                                       /* Input Channel Select Bit 4 */
    byte ADCO        :1;                                       /* Continuous Conversion Enable - ADCO is used to enable continuous conversions */
    byte AIEN        :1;                                       /* Interrupt Enable - AIEN is used to enable conversion complete interrupts. When COCO becomes set while AIEN is high, an interrupt is asserted */
    byte COCO        :1;                                       /* Conversion Complete Flag */
  } Bits;
  struct {
    byte grpADCH :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCSC1STR;
#define _ADCSC1 (*(volatile ADCSC1STR *)0xFFFF8010)
#define ADCSC1                          _ADCSC1.Byte
#define ADCSC1_ADCH0                    _ADCSC1.Bits.ADCH0
#define ADCSC1_ADCH1                    _ADCSC1.Bits.ADCH1
#define ADCSC1_ADCH2                    _ADCSC1.Bits.ADCH2
#define ADCSC1_ADCH3                    _ADCSC1.Bits.ADCH3
#define ADCSC1_ADCH4                    _ADCSC1.Bits.ADCH4
#define ADCSC1_ADCO                     _ADCSC1.Bits.ADCO
#define ADCSC1_AIEN                     _ADCSC1.Bits.AIEN
#define ADCSC1_COCO                     _ADCSC1.Bits.COCO
#define ADCSC1_ADCH                     _ADCSC1.MergedBits.grpADCH

#define ADCSC1_ADCH0_MASK               1U
#define ADCSC1_ADCH1_MASK               2U
#define ADCSC1_ADCH2_MASK               4U
#define ADCSC1_ADCH3_MASK               8U
#define ADCSC1_ADCH4_MASK               16U
#define ADCSC1_ADCO_MASK                32U
#define ADCSC1_AIEN_MASK                64U
#define ADCSC1_COCO_MASK                128U
#define ADCSC1_ADCH_MASK                31U
#define ADCSC1_ADCH_BITNUM              0U


/*** ADCSC2 - Status and Control Register 2; 0xFFFF8011 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ACFGT       :1;                                       /* Compare Function Greater Than Enable */
    byte ACFE        :1;                                       /* Compare Function Enable - ACFE is used to enable the compare function */
    byte ADTRG       :1;                                       /* Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating a conversion */
    byte ADACT       :1;                                       /* Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a conversion is initiated and cleared when a conversion is completed or aborted */
  } Bits;
} ADCSC2STR;
#define _ADCSC2 (*(volatile ADCSC2STR *)0xFFFF8011)
#define ADCSC2                          _ADCSC2.Byte
#define ADCSC2_ACFGT                    _ADCSC2.Bits.ACFGT
#define ADCSC2_ACFE                     _ADCSC2.Bits.ACFE
#define ADCSC2_ADTRG                    _ADCSC2.Bits.ADTRG
#define ADCSC2_ADACT                    _ADCSC2.Bits.ADACT

#define ADCSC2_ACFGT_MASK               16U
#define ADCSC2_ACFE_MASK                32U
#define ADCSC2_ADTRG_MASK               64U
#define ADCSC2_ADACT_MASK               128U


/*** ADCR - Data Result Register; 0xFFFF8012 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCRH - Data Result High Register; 0xFFFF8012 ***/
    union {
      byte Byte;
      struct {
        byte ADR8        :1;                                       /* ADC Result Data Bit 8 */
        byte ADR9        :1;                                       /* ADC Result Data Bit 9 */
        byte ADR10       :1;                                       /* ADC Result Data Bit 10 */
        byte ADR11       :1;                                       /* ADC Result Data Bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpADR_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ADCRHSTR;
    #define ADCRH                       _ADCR.Overlap_STR.ADCRHSTR.Byte
    #define ADCRH_ADR8                  _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR8
    #define ADCRH_ADR9                  _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR9
    #define ADCRH_ADR10                 _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR10
    #define ADCRH_ADR11                 _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR11
    #define ADCRH_ADR_8                 _ADCR.Overlap_STR.ADCRHSTR.MergedBits.grpADR_8
    #define ADCRH_ADR                   ADCRH_ADR_8
    
    #define ADCRH_ADR8_MASK             1U
    #define ADCRH_ADR9_MASK             2U
    #define ADCRH_ADR10_MASK            4U
    #define ADCRH_ADR11_MASK            8U
    #define ADCRH_ADR_8_MASK            15U
    #define ADCRH_ADR_8_BITNUM          0U
    

    /*** ADCRL - Data Result Low Register; 0xFFFF8013 ***/
    union {
      byte Byte;
      struct {
        byte ADR0        :1;                                       /* ADC Result Data Bit 0 */
        byte ADR1        :1;                                       /* ADC Result Data Bit 1 */
        byte ADR2        :1;                                       /* ADC Result Data Bit 2 */
        byte ADR3        :1;                                       /* ADC Result Data Bit 3 */
        byte ADR4        :1;                                       /* ADC Result Data Bit 4 */
        byte ADR5        :1;                                       /* ADC Result Data Bit 5 */
        byte ADR6        :1;                                       /* ADC Result Data Bit 6 */
        byte ADR7        :1;                                       /* ADC Result Data Bit 7 */
      } Bits;
    } ADCRLSTR;
    #define ADCRL                       _ADCR.Overlap_STR.ADCRLSTR.Byte
    #define ADCRL_ADR0                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR0
    #define ADCRL_ADR1                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR1
    #define ADCRL_ADR2                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR2
    #define ADCRL_ADR3                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR3
    #define ADCRL_ADR4                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR4
    #define ADCRL_ADR5                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR5
    #define ADCRL_ADR6                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR6
    #define ADCRL_ADR7                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR7
    
    #define ADCRL_ADR0_MASK             1U
    #define ADCRL_ADR1_MASK             2U
    #define ADCRL_ADR2_MASK             4U
    #define ADCRL_ADR3_MASK             8U
    #define ADCRL_ADR4_MASK             16U
    #define ADCRL_ADR5_MASK             32U
    #define ADCRL_ADR6_MASK             64U
    #define ADCRL_ADR7_MASK             128U
    
  } Overlap_STR;

  struct {
    word ADR0        :1;                                       /* ADC Result Data Bit 0 */
    word ADR1        :1;                                       /* ADC Result Data Bit 1 */
    word ADR2        :1;                                       /* ADC Result Data Bit 2 */
    word ADR3        :1;                                       /* ADC Result Data Bit 3 */
    word ADR4        :1;                                       /* ADC Result Data Bit 4 */
    word ADR5        :1;                                       /* ADC Result Data Bit 5 */
    word ADR6        :1;                                       /* ADC Result Data Bit 6 */
    word ADR7        :1;                                       /* ADC Result Data Bit 7 */
    word ADR8        :1;                                       /* ADC Result Data Bit 8 */
    word ADR9        :1;                                       /* ADC Result Data Bit 9 */
    word ADR10       :1;                                       /* ADC Result Data Bit 10 */
    word ADR11       :1;                                       /* ADC Result Data Bit 11 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpADR  :12;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ADCRSTR;
#define _ADCR (*(volatile ADCRSTR *)0xFFFF8012)
#define ADCR                            _ADCR.Word
#define ADCR_ADR0                       _ADCR.Bits.ADR0
#define ADCR_ADR1                       _ADCR.Bits.ADR1
#define ADCR_ADR2                       _ADCR.Bits.ADR2
#define ADCR_ADR3                       _ADCR.Bits.ADR3
#define ADCR_ADR4                       _ADCR.Bits.ADR4
#define ADCR_ADR5                       _ADCR.Bits.ADR5
#define ADCR_ADR6                       _ADCR.Bits.ADR6
#define ADCR_ADR7                       _ADCR.Bits.ADR7
#define ADCR_ADR8                       _ADCR.Bits.ADR8
#define ADCR_ADR9                       _ADCR.Bits.ADR9
#define ADCR_ADR10                      _ADCR.Bits.ADR10
#define ADCR_ADR11                      _ADCR.Bits.ADR11
#define ADCR_ADR                        _ADCR.MergedBits.grpADR

#define ADCR_ADR0_MASK                  1U
#define ADCR_ADR1_MASK                  2U
#define ADCR_ADR2_MASK                  4U
#define ADCR_ADR3_MASK                  8U
#define ADCR_ADR4_MASK                  16U
#define ADCR_ADR5_MASK                  32U
#define ADCR_ADR6_MASK                  64U
#define ADCR_ADR7_MASK                  128U
#define ADCR_ADR8_MASK                  256U
#define ADCR_ADR9_MASK                  512U
#define ADCR_ADR10_MASK                 1024U
#define ADCR_ADR11_MASK                 2048U
#define ADCR_ADR_MASK                   4095U
#define ADCR_ADR_BITNUM                 0U


/*** ADCCV - Compare Value Register; 0xFFFF8014 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCCVH - Compare Value High Register; 0xFFFF8014 ***/
    union {
      byte Byte;
      struct {
        byte ADCV8       :1;                                       /* Compare Function Value 8 */
        byte ADCV9       :1;                                       /* Compare Function Value 9 */
        byte ADCV10      :1;                                       /* Compare Function Value 10 */
        byte ADCV11      :1;                                       /* Compare Function Value 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpADCV_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ADCCVHSTR;
    #define ADCCVH                      _ADCCV.Overlap_STR.ADCCVHSTR.Byte
    #define ADCCVH_ADCV8                _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV8
    #define ADCCVH_ADCV9                _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV9
    #define ADCCVH_ADCV10               _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV10
    #define ADCCVH_ADCV11               _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV11
    #define ADCCVH_ADCV_8               _ADCCV.Overlap_STR.ADCCVHSTR.MergedBits.grpADCV_8
    #define ADCCVH_ADCV                 ADCCVH_ADCV_8
    
    #define ADCCVH_ADCV8_MASK           1U
    #define ADCCVH_ADCV9_MASK           2U
    #define ADCCVH_ADCV10_MASK          4U
    #define ADCCVH_ADCV11_MASK          8U
    #define ADCCVH_ADCV_8_MASK          15U
    #define ADCCVH_ADCV_8_BITNUM        0U
    

    /*** ADCCVL - Compare Value Low Register; 0xFFFF8015 ***/
    union {
      byte Byte;
      struct {
        byte ADCV0       :1;                                       /* Compare Function Value 0 */
        byte ADCV1       :1;                                       /* Compare Function Value 1 */
        byte ADCV2       :1;                                       /* Compare Function Value 2 */
        byte ADCV3       :1;                                       /* Compare Function Value 3 */
        byte ADCV4       :1;                                       /* Compare Function Value 4 */
        byte ADCV5       :1;                                       /* Compare Function Value 5 */
        byte ADCV6       :1;                                       /* Compare Function Value 6 */
        byte ADCV7       :1;                                       /* Compare Function Value 7 */
      } Bits;
    } ADCCVLSTR;
    #define ADCCVL                      _ADCCV.Overlap_STR.ADCCVLSTR.Byte
    #define ADCCVL_ADCV0                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV0
    #define ADCCVL_ADCV1                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV1
    #define ADCCVL_ADCV2                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV2
    #define ADCCVL_ADCV3                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV3
    #define ADCCVL_ADCV4                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV4
    #define ADCCVL_ADCV5                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV5
    #define ADCCVL_ADCV6                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV6
    #define ADCCVL_ADCV7                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV7
    
    #define ADCCVL_ADCV0_MASK           1U
    #define ADCCVL_ADCV1_MASK           2U
    #define ADCCVL_ADCV2_MASK           4U
    #define ADCCVL_ADCV3_MASK           8U
    #define ADCCVL_ADCV4_MASK           16U
    #define ADCCVL_ADCV5_MASK           32U
    #define ADCCVL_ADCV6_MASK           64U
    #define ADCCVL_ADCV7_MASK           128U
    
  } Overlap_STR;

  struct {
    word ADCV0       :1;                                       /* Compare Function Value 0 */
    word ADCV1       :1;                                       /* Compare Function Value 1 */
    word ADCV2       :1;                                       /* Compare Function Value 2 */
    word ADCV3       :1;                                       /* Compare Function Value 3 */
    word ADCV4       :1;                                       /* Compare Function Value 4 */
    word ADCV5       :1;                                       /* Compare Function Value 5 */
    word ADCV6       :1;                                       /* Compare Function Value 6 */
    word ADCV7       :1;                                       /* Compare Function Value 7 */
    word ADCV8       :1;                                       /* Compare Function Value 8 */
    word ADCV9       :1;                                       /* Compare Function Value 9 */
    word ADCV10      :1;                                       /* Compare Function Value 10 */
    word ADCV11      :1;                                       /* Compare Function Value 11 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpADCV :12;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ADCCVSTR;
#define _ADCCV (*(volatile ADCCVSTR *)0xFFFF8014)
#define ADCCV                           _ADCCV.Word
#define ADCCV_ADCV0                     _ADCCV.Bits.ADCV0
#define ADCCV_ADCV1                     _ADCCV.Bits.ADCV1
#define ADCCV_ADCV2                     _ADCCV.Bits.ADCV2
#define ADCCV_ADCV3                     _ADCCV.Bits.ADCV3
#define ADCCV_ADCV4                     _ADCCV.Bits.ADCV4
#define ADCCV_ADCV5                     _ADCCV.Bits.ADCV5
#define ADCCV_ADCV6                     _ADCCV.Bits.ADCV6
#define ADCCV_ADCV7                     _ADCCV.Bits.ADCV7
#define ADCCV_ADCV8                     _ADCCV.Bits.ADCV8
#define ADCCV_ADCV9                     _ADCCV.Bits.ADCV9
#define ADCCV_ADCV10                    _ADCCV.Bits.ADCV10
#define ADCCV_ADCV11                    _ADCCV.Bits.ADCV11
#define ADCCV_ADCV                      _ADCCV.MergedBits.grpADCV

#define ADCCV_ADCV0_MASK                1U
#define ADCCV_ADCV1_MASK                2U
#define ADCCV_ADCV2_MASK                4U
#define ADCCV_ADCV3_MASK                8U
#define ADCCV_ADCV4_MASK                16U
#define ADCCV_ADCV5_MASK                32U
#define ADCCV_ADCV6_MASK                64U
#define ADCCV_ADCV7_MASK                128U
#define ADCCV_ADCV8_MASK                256U
#define ADCCV_ADCV9_MASK                512U
#define ADCCV_ADCV10_MASK               1024U
#define ADCCV_ADCV11_MASK               2048U
#define ADCCV_ADCV_MASK                 4095U
#define ADCCV_ADCV_BITNUM               0U


/*** ADCCFG - Configuration Register; 0xFFFF8016 ***/
typedef union {
  byte Byte;
  struct {
    byte ADICLK0     :1;                                       /* Input Clock Select Bit 0 */
    byte ADICLK1     :1;                                       /* Input Clock Select Bit 1 */
    byte MODE0       :1;                                       /* Conversion Mode Selection Bit 0 */
    byte MODE1       :1;                                       /* Conversion Mode Selection Bit 1 */
    byte ADLSMP      :1;                                       /* Long Sample Time Configuration */
    byte ADIV0       :1;                                       /* Clock Divide Select Bit 0 */
    byte ADIV1       :1;                                       /* Clock Divide Select Bit 1 */
    byte ADLPC       :1;                                       /* Low Power Configuration */
  } Bits;
  struct {
    byte grpADICLK :2;
    byte grpMODE :2;
    byte         :1;
    byte grpADIV :2;
    byte         :1;
  } MergedBits;
} ADCCFGSTR;
#define _ADCCFG (*(volatile ADCCFGSTR *)0xFFFF8016)
#define ADCCFG                          _ADCCFG.Byte
#define ADCCFG_ADICLK0                  _ADCCFG.Bits.ADICLK0
#define ADCCFG_ADICLK1                  _ADCCFG.Bits.ADICLK1
#define ADCCFG_MODE0                    _ADCCFG.Bits.MODE0
#define ADCCFG_MODE1                    _ADCCFG.Bits.MODE1
#define ADCCFG_ADLSMP                   _ADCCFG.Bits.ADLSMP
#define ADCCFG_ADIV0                    _ADCCFG.Bits.ADIV0
#define ADCCFG_ADIV1                    _ADCCFG.Bits.ADIV1
#define ADCCFG_ADLPC                    _ADCCFG.Bits.ADLPC
#define ADCCFG_ADICLK                   _ADCCFG.MergedBits.grpADICLK
#define ADCCFG_MODE                     _ADCCFG.MergedBits.grpMODE
#define ADCCFG_ADIV                     _ADCCFG.MergedBits.grpADIV

#define ADCCFG_ADICLK0_MASK             1U
#define ADCCFG_ADICLK1_MASK             2U
#define ADCCFG_MODE0_MASK               4U
#define ADCCFG_MODE1_MASK               8U
#define ADCCFG_ADLSMP_MASK              16U
#define ADCCFG_ADIV0_MASK               32U
#define ADCCFG_ADIV1_MASK               64U
#define ADCCFG_ADLPC_MASK               128U
#define ADCCFG_ADICLK_MASK              3U
#define ADCCFG_ADICLK_BITNUM            0U
#define ADCCFG_MODE_MASK                12U
#define ADCCFG_MODE_BITNUM              2U
#define ADCCFG_ADIV_MASK                96U
#define ADCCFG_ADIV_BITNUM              5U


/*** APCTL1 - Pin Control 1 Register; 0xFFFF8017 ***/
typedef union {
  byte Byte;
  struct {
    byte ADPC0       :1;                                       /* ADC Pin Control 0 - ADPC0 is used to control the pin associated with channel AD0 */
    byte ADPC1       :1;                                       /* ADC Pin Control 1 - ADPC1 is used to control the pin associated with channel AD1 */
    byte ADPC2       :1;                                       /* ADC Pin Control 2 - ADPC2 is used to control the pin associated with channel AD2 */
    byte ADPC3       :1;                                       /* ADC Pin Control 3 - ADPC3 is used to control the pin associated with channel AD3 */
    byte ADPC4       :1;                                       /* ADC Pin Control 4 - ADPC4 is used to control the pin associated with channel AD4 */
    byte ADPC5       :1;                                       /* ADC Pin Control 5 - ADPC5 is used to control the pin associated with channel AD5 */
    byte ADPC6       :1;                                       /* ADC Pin Control 6 - ADPC6 is used to control the pin associated with channel AD6 */
    byte ADPC7       :1;                                       /* ADC Pin Control 7 - ADPC7 is used to control the pin associated with channel AD7 */
  } Bits;
} APCTL1STR;
#define _APCTL1 (*(volatile APCTL1STR *)0xFFFF8017)
#define APCTL1                          _APCTL1.Byte
#define APCTL1_ADPC0                    _APCTL1.Bits.ADPC0
#define APCTL1_ADPC1                    _APCTL1.Bits.ADPC1
#define APCTL1_ADPC2                    _APCTL1.Bits.ADPC2
#define APCTL1_ADPC3                    _APCTL1.Bits.ADPC3
#define APCTL1_ADPC4                    _APCTL1.Bits.ADPC4
#define APCTL1_ADPC5                    _APCTL1.Bits.ADPC5
#define APCTL1_ADPC6                    _APCTL1.Bits.ADPC6
#define APCTL1_ADPC7                    _APCTL1.Bits.ADPC7

#define APCTL1_ADPC0_MASK               1U
#define APCTL1_ADPC1_MASK               2U
#define APCTL1_ADPC2_MASK               4U
#define APCTL1_ADPC3_MASK               8U
#define APCTL1_ADPC4_MASK               16U
#define APCTL1_ADPC5_MASK               32U
#define APCTL1_ADPC6_MASK               64U
#define APCTL1_ADPC7_MASK               128U


/*** APCTL2 - Pin Control 2 Register; 0xFFFF8018 ***/
typedef union {
  byte Byte;
  struct {
    byte ADPC8       :1;                                       /* ADC Pin Control 8 - ADPC8 is used to control the pin associated with channel AD8 */
    byte ADPC9       :1;                                       /* ADC Pin Control 9 - ADPC9 is used to control the pin associated with channel AD9 */
    byte ADPC10      :1;                                       /* ADC Pin Control 10 - ADPC10 is used to control the pin associated with channel AD10 */
    byte ADPC11      :1;                                       /* ADC Pin Control 11 - ADPC11 is used to control the pin associated with channel AD11 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpADPC_8 :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} APCTL2STR;
#define _APCTL2 (*(volatile APCTL2STR *)0xFFFF8018)
#define APCTL2                          _APCTL2.Byte
#define APCTL2_ADPC8                    _APCTL2.Bits.ADPC8
#define APCTL2_ADPC9                    _APCTL2.Bits.ADPC9
#define APCTL2_ADPC10                   _APCTL2.Bits.ADPC10
#define APCTL2_ADPC11                   _APCTL2.Bits.ADPC11
#define APCTL2_ADPC_8                   _APCTL2.MergedBits.grpADPC_8
#define APCTL2_ADPC                     APCTL2_ADPC_8

#define APCTL2_ADPC8_MASK               1U
#define APCTL2_ADPC9_MASK               2U
#define APCTL2_ADPC10_MASK              4U
#define APCTL2_ADPC11_MASK              8U
#define APCTL2_ADPC_8_MASK              15U
#define APCTL2_ADPC_8_BITNUM            0U


/*** IRQSC - Interrupt request status and control register; 0xFFFF801B ***/
typedef union {
  byte Byte;
  struct {
    byte IRQMOD      :1;                                       /* IRQ Detection Mode */
    byte IRQIE       :1;                                       /* IRQ Interrupt Enable */
    byte IRQACK      :1;                                       /* IRQ Acknowledge */
    byte IRQF        :1;                                       /* IRQ Flag */
    byte IRQPE       :1;                                       /* IRQ Pin Enable */
    byte IRQEDG      :1;                                       /* IRQ Edge Select */
    byte IRQPDD      :1;                                       /* IRQ Pull Device Disable */
    byte             :1; 
  } Bits;
} IRQSCSTR;
#define _IRQSC (*(volatile IRQSCSTR *)0xFFFF801B)
#define IRQSC                           _IRQSC.Byte
#define IRQSC_IRQMOD                    _IRQSC.Bits.IRQMOD
#define IRQSC_IRQIE                     _IRQSC.Bits.IRQIE
#define IRQSC_IRQACK                    _IRQSC.Bits.IRQACK
#define IRQSC_IRQF                      _IRQSC.Bits.IRQF
#define IRQSC_IRQPE                     _IRQSC.Bits.IRQPE
#define IRQSC_IRQEDG                    _IRQSC.Bits.IRQEDG
#define IRQSC_IRQPDD                    _IRQSC.Bits.IRQPDD

#define IRQSC_IRQMOD_MASK               1U
#define IRQSC_IRQIE_MASK                2U
#define IRQSC_IRQACK_MASK               4U
#define IRQSC_IRQF_MASK                 8U
#define IRQSC_IRQPE_MASK                16U
#define IRQSC_IRQEDG_MASK               32U
#define IRQSC_IRQPDD_MASK               64U


/*** KBI1SC - KBI1 Status and Control Register; 0xFFFF801C ***/
typedef union {
  byte Byte;
  struct {
    byte KBIMOD      :1;                                       /* Keyboard Detection Mode */
    byte KBIE        :1;                                       /* Keyboard Interrupt Enable */
    byte KBACK       :1;                                       /* Keyboard Interrupt Acknowledge */
    byte KBF         :1;                                       /* Keyboard Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} KBI1SCSTR;
#define _KBI1SC (*(volatile KBI1SCSTR *)0xFFFF801C)
#define KBI1SC                          _KBI1SC.Byte
#define KBI1SC_KBIMOD                   _KBI1SC.Bits.KBIMOD
#define KBI1SC_KBIE                     _KBI1SC.Bits.KBIE
#define KBI1SC_KBACK                    _KBI1SC.Bits.KBACK
#define KBI1SC_KBF                      _KBI1SC.Bits.KBF

#define KBI1SC_KBIMOD_MASK              1U
#define KBI1SC_KBIE_MASK                2U
#define KBI1SC_KBACK_MASK               4U
#define KBI1SC_KBF_MASK                 8U


/*** KBI1PE - KBI1 Pin Enable Register; 0xFFFF801D ***/
typedef union {
  byte Byte;
  struct {
    byte KBIPE0      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 0 */
    byte KBIPE1      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 1 */
    byte KBIPE2      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 2 */
    byte KBIPE3      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 3 */
    byte KBIPE4      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 4 */
    byte KBIPE5      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 5 */
    byte KBIPE6      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 6 */
    byte KBIPE7      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 7 */
  } Bits;
} KBI1PESTR;
#define _KBI1PE (*(volatile KBI1PESTR *)0xFFFF801D)
#define KBI1PE                          _KBI1PE.Byte
#define KBI1PE_KBIPE0                   _KBI1PE.Bits.KBIPE0
#define KBI1PE_KBIPE1                   _KBI1PE.Bits.KBIPE1
#define KBI1PE_KBIPE2                   _KBI1PE.Bits.KBIPE2
#define KBI1PE_KBIPE3                   _KBI1PE.Bits.KBIPE3
#define KBI1PE_KBIPE4                   _KBI1PE.Bits.KBIPE4
#define KBI1PE_KBIPE5                   _KBI1PE.Bits.KBIPE5
#define KBI1PE_KBIPE6                   _KBI1PE.Bits.KBIPE6
#define KBI1PE_KBIPE7                   _KBI1PE.Bits.KBIPE7

#define KBI1PE_KBIPE0_MASK              1U
#define KBI1PE_KBIPE1_MASK              2U
#define KBI1PE_KBIPE2_MASK              4U
#define KBI1PE_KBIPE3_MASK              8U
#define KBI1PE_KBIPE4_MASK              16U
#define KBI1PE_KBIPE5_MASK              32U
#define KBI1PE_KBIPE6_MASK              64U
#define KBI1PE_KBIPE7_MASK              128U


/*** KBI1ES - KBI1 Edge Select Register; 0xFFFF801E ***/
typedef union {
  byte Byte;
  struct {
    byte KBEDG0      :1;                                       /* Keyboard Edge Select Bit 0 */
    byte KBEDG1      :1;                                       /* Keyboard Edge Select Bit 1 */
    byte KBEDG2      :1;                                       /* Keyboard Edge Select Bit 2 */
    byte KBEDG3      :1;                                       /* Keyboard Edge Select Bit 3 */
    byte KBEDG4      :1;                                       /* Keyboard Edge Select Bit 4 */
    byte KBEDG5      :1;                                       /* Keyboard Edge Select Bit 5 */
    byte KBEDG6      :1;                                       /* Keyboard Edge Select Bit 6 */
    byte KBEDG7      :1;                                       /* Keyboard Edge Select Bit 7 */
  } Bits;
} KBI1ESSTR;
#define _KBI1ES (*(volatile KBI1ESSTR *)0xFFFF801E)
#define KBI1ES                          _KBI1ES.Byte
#define KBI1ES_KBEDG0                   _KBI1ES.Bits.KBEDG0
#define KBI1ES_KBEDG1                   _KBI1ES.Bits.KBEDG1
#define KBI1ES_KBEDG2                   _KBI1ES.Bits.KBEDG2
#define KBI1ES_KBEDG3                   _KBI1ES.Bits.KBEDG3
#define KBI1ES_KBEDG4                   _KBI1ES.Bits.KBEDG4
#define KBI1ES_KBEDG5                   _KBI1ES.Bits.KBEDG5
#define KBI1ES_KBEDG6                   _KBI1ES.Bits.KBEDG6
#define KBI1ES_KBEDG7                   _KBI1ES.Bits.KBEDG7

#define KBI1ES_KBEDG0_MASK              1U
#define KBI1ES_KBEDG1_MASK              2U
#define KBI1ES_KBEDG2_MASK              4U
#define KBI1ES_KBEDG3_MASK              8U
#define KBI1ES_KBEDG4_MASK              16U
#define KBI1ES_KBEDG5_MASK              32U
#define KBI1ES_KBEDG6_MASK              64U
#define KBI1ES_KBEDG7_MASK              128U


/*** TPM1SC - TPM1 Status and Control Register; 0xFFFF8020 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1SCSTR;
#define _TPM1SC (*(volatile TPM1SCSTR *)0xFFFF8020)
#define TPM1SC                          _TPM1SC.Byte
#define TPM1SC_PS0                      _TPM1SC.Bits.PS0
#define TPM1SC_PS1                      _TPM1SC.Bits.PS1
#define TPM1SC_PS2                      _TPM1SC.Bits.PS2
#define TPM1SC_CLKSA                    _TPM1SC.Bits.CLKSA
#define TPM1SC_CLKSB                    _TPM1SC.Bits.CLKSB
#define TPM1SC_CPWMS                    _TPM1SC.Bits.CPWMS
#define TPM1SC_TOIE                     _TPM1SC.Bits.TOIE
#define TPM1SC_TOF                      _TPM1SC.Bits.TOF
#define TPM1SC_PS                       _TPM1SC.MergedBits.grpPS
#define TPM1SC_CLKSx                    _TPM1SC.MergedBits.grpCLKSx

#define TPM1SC_PS0_MASK                 1U
#define TPM1SC_PS1_MASK                 2U
#define TPM1SC_PS2_MASK                 4U
#define TPM1SC_CLKSA_MASK               8U
#define TPM1SC_CLKSB_MASK               16U
#define TPM1SC_CPWMS_MASK               32U
#define TPM1SC_TOIE_MASK                64U
#define TPM1SC_TOF_MASK                 128U
#define TPM1SC_PS_MASK                  7U
#define TPM1SC_PS_BITNUM                0U
#define TPM1SC_CLKSx_MASK               24U
#define TPM1SC_CLKSx_BITNUM             3U


/*** TPM1CNT - TPM1 Timer Counter Register; 0xFFFF8021 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1CNTH - TPM1 Timer Counter Register High; 0xFFFF8021 ***/
    union {
      byte Byte;
    } TPM1CNTHSTR;
    #define TPM1CNTH                    _TPM1CNT.Overlap_STR.TPM1CNTHSTR.Byte
    

    /*** TPM1CNTL - TPM1 Timer Counter Register Low; 0xFFFF8022 ***/
    union {
      byte Byte;
    } TPM1CNTLSTR;
    #define TPM1CNTL                    _TPM1CNT.Overlap_STR.TPM1CNTLSTR.Byte
    
  } Overlap_STR;

} TPM1CNTSTR;
#define _TPM1CNT (*(volatile TPM1CNTSTR *)0xFFFF8021)
#define TPM1CNT                         _TPM1CNT.Word


/*** TPM1MOD - TPM1 Timer Counter Modulo Register; 0xFFFF8023 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1MODH - TPM1 Timer Counter Modulo Register High; 0xFFFF8023 ***/
    union {
      byte Byte;
    } TPM1MODHSTR;
    #define TPM1MODH                    _TPM1MOD.Overlap_STR.TPM1MODHSTR.Byte
    

    /*** TPM1MODL - TPM1 Timer Counter Modulo Register Low; 0xFFFF8024 ***/
    union {
      byte Byte;
    } TPM1MODLSTR;
    #define TPM1MODL                    _TPM1MOD.Overlap_STR.TPM1MODLSTR.Byte
    
  } Overlap_STR;

} TPM1MODSTR;
#define _TPM1MOD (*(volatile TPM1MODSTR *)0xFFFF8023)
#define TPM1MOD                         _TPM1MOD.Word


/*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register; 0xFFFF8025 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C0SCSTR;
#define _TPM1C0SC (*(volatile TPM1C0SCSTR *)0xFFFF8025)
#define TPM1C0SC                        _TPM1C0SC.Byte
#define TPM1C0SC_ELS0A                  _TPM1C0SC.Bits.ELS0A
#define TPM1C0SC_ELS0B                  _TPM1C0SC.Bits.ELS0B
#define TPM1C0SC_MS0A                   _TPM1C0SC.Bits.MS0A
#define TPM1C0SC_MS0B                   _TPM1C0SC.Bits.MS0B
#define TPM1C0SC_CH0IE                  _TPM1C0SC.Bits.CH0IE
#define TPM1C0SC_CH0F                   _TPM1C0SC.Bits.CH0F
#define TPM1C0SC_ELS0x                  _TPM1C0SC.MergedBits.grpELS0x
#define TPM1C0SC_MS0x                   _TPM1C0SC.MergedBits.grpMS0x

#define TPM1C0SC_ELS0A_MASK             4U
#define TPM1C0SC_ELS0B_MASK             8U
#define TPM1C0SC_MS0A_MASK              16U
#define TPM1C0SC_MS0B_MASK              32U
#define TPM1C0SC_CH0IE_MASK             64U
#define TPM1C0SC_CH0F_MASK              128U
#define TPM1C0SC_ELS0x_MASK             12U
#define TPM1C0SC_ELS0x_BITNUM           2U
#define TPM1C0SC_MS0x_MASK              48U
#define TPM1C0SC_MS0x_BITNUM            4U


/*** TPM1C0V - TPM1 Timer Channel 0 Value Register; 0xFFFF8026 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High; 0xFFFF8026 ***/
    union {
      byte Byte;
    } TPM1C0VHSTR;
    #define TPM1C0VH                    _TPM1C0V.Overlap_STR.TPM1C0VHSTR.Byte
    

    /*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low; 0xFFFF8027 ***/
    union {
      byte Byte;
    } TPM1C0VLSTR;
    #define TPM1C0VL                    _TPM1C0V.Overlap_STR.TPM1C0VLSTR.Byte
    
  } Overlap_STR;

} TPM1C0VSTR;
#define _TPM1C0V (*(volatile TPM1C0VSTR *)0xFFFF8026)
#define TPM1C0V                         _TPM1C0V.Word


/*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register; 0xFFFF8028 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for TPM Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for TPM Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C1SCSTR;
#define _TPM1C1SC (*(volatile TPM1C1SCSTR *)0xFFFF8028)
#define TPM1C1SC                        _TPM1C1SC.Byte
#define TPM1C1SC_ELS1A                  _TPM1C1SC.Bits.ELS1A
#define TPM1C1SC_ELS1B                  _TPM1C1SC.Bits.ELS1B
#define TPM1C1SC_MS1A                   _TPM1C1SC.Bits.MS1A
#define TPM1C1SC_MS1B                   _TPM1C1SC.Bits.MS1B
#define TPM1C1SC_CH1IE                  _TPM1C1SC.Bits.CH1IE
#define TPM1C1SC_CH1F                   _TPM1C1SC.Bits.CH1F
#define TPM1C1SC_ELS1x                  _TPM1C1SC.MergedBits.grpELS1x
#define TPM1C1SC_MS1x                   _TPM1C1SC.MergedBits.grpMS1x

#define TPM1C1SC_ELS1A_MASK             4U
#define TPM1C1SC_ELS1B_MASK             8U
#define TPM1C1SC_MS1A_MASK              16U
#define TPM1C1SC_MS1B_MASK              32U
#define TPM1C1SC_CH1IE_MASK             64U
#define TPM1C1SC_CH1F_MASK              128U
#define TPM1C1SC_ELS1x_MASK             12U
#define TPM1C1SC_ELS1x_BITNUM           2U
#define TPM1C1SC_MS1x_MASK              48U
#define TPM1C1SC_MS1x_BITNUM            4U


/*** TPM1C1V - TPM1 Timer Channel 1 Value Register; 0xFFFF8029 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High; 0xFFFF8029 ***/
    union {
      byte Byte;
    } TPM1C1VHSTR;
    #define TPM1C1VH                    _TPM1C1V.Overlap_STR.TPM1C1VHSTR.Byte
    

    /*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low; 0xFFFF802A ***/
    union {
      byte Byte;
    } TPM1C1VLSTR;
    #define TPM1C1VL                    _TPM1C1V.Overlap_STR.TPM1C1VLSTR.Byte
    
  } Overlap_STR;

} TPM1C1VSTR;
#define _TPM1C1V (*(volatile TPM1C1VSTR *)0xFFFF8029)
#define TPM1C1V                         _TPM1C1V.Word


/*** TPM1C2SC - TPM1 Timer Channel 2 Status and Control Register; 0xFFFF802B ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS2A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS2B       :1;                                       /* Edge/Level Select Bit B */
    byte MS2A        :1;                                       /* Mode Select A for TPM Channel 2 */
    byte MS2B        :1;                                       /* Mode Select B for TPM Channel 2 */
    byte CH2IE       :1;                                       /* Channel 2 Interrupt Enable */
    byte CH2F        :1;                                       /* Channel 2 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS2x :2;
    byte grpMS2x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C2SCSTR;
#define _TPM1C2SC (*(volatile TPM1C2SCSTR *)0xFFFF802B)
#define TPM1C2SC                        _TPM1C2SC.Byte
#define TPM1C2SC_ELS2A                  _TPM1C2SC.Bits.ELS2A
#define TPM1C2SC_ELS2B                  _TPM1C2SC.Bits.ELS2B
#define TPM1C2SC_MS2A                   _TPM1C2SC.Bits.MS2A
#define TPM1C2SC_MS2B                   _TPM1C2SC.Bits.MS2B
#define TPM1C2SC_CH2IE                  _TPM1C2SC.Bits.CH2IE
#define TPM1C2SC_CH2F                   _TPM1C2SC.Bits.CH2F
#define TPM1C2SC_ELS2x                  _TPM1C2SC.MergedBits.grpELS2x
#define TPM1C2SC_MS2x                   _TPM1C2SC.MergedBits.grpMS2x

#define TPM1C2SC_ELS2A_MASK             4U
#define TPM1C2SC_ELS2B_MASK             8U
#define TPM1C2SC_MS2A_MASK              16U
#define TPM1C2SC_MS2B_MASK              32U
#define TPM1C2SC_CH2IE_MASK             64U
#define TPM1C2SC_CH2F_MASK              128U
#define TPM1C2SC_ELS2x_MASK             12U
#define TPM1C2SC_ELS2x_BITNUM           2U
#define TPM1C2SC_MS2x_MASK              48U
#define TPM1C2SC_MS2x_BITNUM            4U


/*** TPM1C2V - TPM1 Timer Channel 2 Value Register; 0xFFFF802C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C2VH - TPM1 Timer Channel 2 Value Register High; 0xFFFF802C ***/
    union {
      byte Byte;
    } TPM1C2VHSTR;
    #define TPM1C2VH                    _TPM1C2V.Overlap_STR.TPM1C2VHSTR.Byte
    

    /*** TPM1C2VL - TPM1 Timer Channel 2 Value Register Low; 0xFFFF802D ***/
    union {
      byte Byte;
    } TPM1C2VLSTR;
    #define TPM1C2VL                    _TPM1C2V.Overlap_STR.TPM1C2VLSTR.Byte
    
  } Overlap_STR;

} TPM1C2VSTR;
#define _TPM1C2V (*(volatile TPM1C2VSTR *)0xFFFF802C)
#define TPM1C2V                         _TPM1C2V.Word


/*** TPM1C3SC - TPM1 Timer Channel 3 Status and Control Register; 0xFFFF802E ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS3A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS3B       :1;                                       /* Edge/Level Select Bit B */
    byte MS3A        :1;                                       /* Mode Select A for TPM Channel 3 */
    byte MS3B        :1;                                       /* Mode Select B for TPM Channel 3 */
    byte CH3IE       :1;                                       /* Channel 3 Interrupt Enable */
    byte CH3F        :1;                                       /* Channel 3 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS3x :2;
    byte grpMS3x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C3SCSTR;
#define _TPM1C3SC (*(volatile TPM1C3SCSTR *)0xFFFF802E)
#define TPM1C3SC                        _TPM1C3SC.Byte
#define TPM1C3SC_ELS3A                  _TPM1C3SC.Bits.ELS3A
#define TPM1C3SC_ELS3B                  _TPM1C3SC.Bits.ELS3B
#define TPM1C3SC_MS3A                   _TPM1C3SC.Bits.MS3A
#define TPM1C3SC_MS3B                   _TPM1C3SC.Bits.MS3B
#define TPM1C3SC_CH3IE                  _TPM1C3SC.Bits.CH3IE
#define TPM1C3SC_CH3F                   _TPM1C3SC.Bits.CH3F
#define TPM1C3SC_ELS3x                  _TPM1C3SC.MergedBits.grpELS3x
#define TPM1C3SC_MS3x                   _TPM1C3SC.MergedBits.grpMS3x

#define TPM1C3SC_ELS3A_MASK             4U
#define TPM1C3SC_ELS3B_MASK             8U
#define TPM1C3SC_MS3A_MASK              16U
#define TPM1C3SC_MS3B_MASK              32U
#define TPM1C3SC_CH3IE_MASK             64U
#define TPM1C3SC_CH3F_MASK              128U
#define TPM1C3SC_ELS3x_MASK             12U
#define TPM1C3SC_ELS3x_BITNUM           2U
#define TPM1C3SC_MS3x_MASK              48U
#define TPM1C3SC_MS3x_BITNUM            4U


/*** TPM1C3V - TPM1 Timer Channel 3 Value Register; 0xFFFF802F ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C3VH - TPM1 Timer Channel 3 Value Register High; 0xFFFF802F ***/
    union {
      byte Byte;
    } TPM1C3VHSTR;
    #define TPM1C3VH                    _TPM1C3V.Overlap_STR.TPM1C3VHSTR.Byte
    

    /*** TPM1C3VL - TPM1 Timer Channel 3 Value Register Low; 0xFFFF8030 ***/
    union {
      byte Byte;
    } TPM1C3VLSTR;
    #define TPM1C3VL                    _TPM1C3V.Overlap_STR.TPM1C3VLSTR.Byte
    
  } Overlap_STR;

} TPM1C3VSTR;
#define _TPM1C3V (*(volatile TPM1C3VSTR *)0xFFFF802F)
#define TPM1C3V                         _TPM1C3V.Word


/*** TPM1C4SC - TPM1 Timer Channel 4 Status and Control Register; 0xFFFF8031 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS4A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS4B       :1;                                       /* Edge/Level Select Bit B */
    byte MS4A        :1;                                       /* Mode Select A for TPM Channel 4 */
    byte MS4B        :1;                                       /* Mode Select B for TPM Channel 4 */
    byte CH4IE       :1;                                       /* Channel 4 Interrupt Enable */
    byte CH4F        :1;                                       /* Channel 4 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS4x :2;
    byte grpMS4x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C4SCSTR;
#define _TPM1C4SC (*(volatile TPM1C4SCSTR *)0xFFFF8031)
#define TPM1C4SC                        _TPM1C4SC.Byte
#define TPM1C4SC_ELS4A                  _TPM1C4SC.Bits.ELS4A
#define TPM1C4SC_ELS4B                  _TPM1C4SC.Bits.ELS4B
#define TPM1C4SC_MS4A                   _TPM1C4SC.Bits.MS4A
#define TPM1C4SC_MS4B                   _TPM1C4SC.Bits.MS4B
#define TPM1C4SC_CH4IE                  _TPM1C4SC.Bits.CH4IE
#define TPM1C4SC_CH4F                   _TPM1C4SC.Bits.CH4F
#define TPM1C4SC_ELS4x                  _TPM1C4SC.MergedBits.grpELS4x
#define TPM1C4SC_MS4x                   _TPM1C4SC.MergedBits.grpMS4x

#define TPM1C4SC_ELS4A_MASK             4U
#define TPM1C4SC_ELS4B_MASK             8U
#define TPM1C4SC_MS4A_MASK              16U
#define TPM1C4SC_MS4B_MASK              32U
#define TPM1C4SC_CH4IE_MASK             64U
#define TPM1C4SC_CH4F_MASK              128U
#define TPM1C4SC_ELS4x_MASK             12U
#define TPM1C4SC_ELS4x_BITNUM           2U
#define TPM1C4SC_MS4x_MASK              48U
#define TPM1C4SC_MS4x_BITNUM            4U


/*** TPM1C4V - TPM1 Timer Channel 4 Value Register; 0xFFFF8032 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C4VH - TPM1 Timer Channel 4 Value Register High; 0xFFFF8032 ***/
    union {
      byte Byte;
    } TPM1C4VHSTR;
    #define TPM1C4VH                    _TPM1C4V.Overlap_STR.TPM1C4VHSTR.Byte
    

    /*** TPM1C4VL - TPM1 Timer Channel 4 Value Register Low; 0xFFFF8033 ***/
    union {
      byte Byte;
    } TPM1C4VLSTR;
    #define TPM1C4VL                    _TPM1C4V.Overlap_STR.TPM1C4VLSTR.Byte
    
  } Overlap_STR;

} TPM1C4VSTR;
#define _TPM1C4V (*(volatile TPM1C4VSTR *)0xFFFF8032)
#define TPM1C4V                         _TPM1C4V.Word


/*** TPM1C5SC - TPM1 Timer Channel 5 Status and Control Register; 0xFFFF8034 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS5A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS5B       :1;                                       /* Edge/Level Select Bit B */
    byte MS5A        :1;                                       /* Mode Select A for TPM Channel 5 */
    byte MS5B        :1;                                       /* Mode Select B for TPM Channel 5 */
    byte CH5IE       :1;                                       /* Channel 5 Interrupt Enable */
    byte CH5F        :1;                                       /* Channel 5 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS5x :2;
    byte grpMS5x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C5SCSTR;
#define _TPM1C5SC (*(volatile TPM1C5SCSTR *)0xFFFF8034)
#define TPM1C5SC                        _TPM1C5SC.Byte
#define TPM1C5SC_ELS5A                  _TPM1C5SC.Bits.ELS5A
#define TPM1C5SC_ELS5B                  _TPM1C5SC.Bits.ELS5B
#define TPM1C5SC_MS5A                   _TPM1C5SC.Bits.MS5A
#define TPM1C5SC_MS5B                   _TPM1C5SC.Bits.MS5B
#define TPM1C5SC_CH5IE                  _TPM1C5SC.Bits.CH5IE
#define TPM1C5SC_CH5F                   _TPM1C5SC.Bits.CH5F
#define TPM1C5SC_ELS5x                  _TPM1C5SC.MergedBits.grpELS5x
#define TPM1C5SC_MS5x                   _TPM1C5SC.MergedBits.grpMS5x

#define TPM1C5SC_ELS5A_MASK             4U
#define TPM1C5SC_ELS5B_MASK             8U
#define TPM1C5SC_MS5A_MASK              16U
#define TPM1C5SC_MS5B_MASK              32U
#define TPM1C5SC_CH5IE_MASK             64U
#define TPM1C5SC_CH5F_MASK              128U
#define TPM1C5SC_ELS5x_MASK             12U
#define TPM1C5SC_ELS5x_BITNUM           2U
#define TPM1C5SC_MS5x_MASK              48U
#define TPM1C5SC_MS5x_BITNUM            4U


/*** TPM1C5V - TPM1 Timer Channel 5 Value Register; 0xFFFF8035 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C5VH - TPM1 Timer Channel 5 Value Register High; 0xFFFF8035 ***/
    union {
      byte Byte;
    } TPM1C5VHSTR;
    #define TPM1C5VH                    _TPM1C5V.Overlap_STR.TPM1C5VHSTR.Byte
    

    /*** TPM1C5VL - TPM1 Timer Channel 5 Value Register Low; 0xFFFF8036 ***/
    union {
      byte Byte;
    } TPM1C5VLSTR;
    #define TPM1C5VL                    _TPM1C5V.Overlap_STR.TPM1C5VLSTR.Byte
    
  } Overlap_STR;

} TPM1C5VSTR;
#define _TPM1C5V (*(volatile TPM1C5VSTR *)0xFFFF8035)
#define TPM1C5V                         _TPM1C5V.Word


/*** SCI1BD - SCI1 Baud Rate Register; 0xFFFF8038 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI1BDH - SCI1 Baud Rate Register High; 0xFFFF8038 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
        byte SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
        byte SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
        byte SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
        byte SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
        byte             :1; 
        byte RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
        byte LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI1BDHSTR;
    #define SCI1BDH                     _SCI1BD.Overlap_STR.SCI1BDHSTR.Byte
    #define SCI1BDH_SBR8                _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR8
    #define SCI1BDH_SBR9                _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR9
    #define SCI1BDH_SBR10               _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR10
    #define SCI1BDH_SBR11               _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR11
    #define SCI1BDH_SBR12               _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR12
    #define SCI1BDH_RXEDGIE             _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.RXEDGIE
    #define SCI1BDH_LBKDIE              _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.LBKDIE
    #define SCI1BDH_SBR_8               _SCI1BD.Overlap_STR.SCI1BDHSTR.MergedBits.grpSBR_8
    #define SCI1BDH_SBR                 SCI1BDH_SBR_8
    
    #define SCI1BDH_SBR8_MASK           1U
    #define SCI1BDH_SBR9_MASK           2U
    #define SCI1BDH_SBR10_MASK          4U
    #define SCI1BDH_SBR11_MASK          8U
    #define SCI1BDH_SBR12_MASK          16U
    #define SCI1BDH_RXEDGIE_MASK        64U
    #define SCI1BDH_LBKDIE_MASK         128U
    #define SCI1BDH_SBR_8_MASK          31U
    #define SCI1BDH_SBR_8_BITNUM        0U
    

    /*** SCI1BDL - SCI1 Baud Rate Register Low; 0xFFFF8039 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
        byte SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
        byte SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
        byte SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
      } Bits;
    } SCI1BDLSTR;
    #define SCI1BDL                     _SCI1BD.Overlap_STR.SCI1BDLSTR.Byte
    #define SCI1BDL_SBR0                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR0
    #define SCI1BDL_SBR1                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR1
    #define SCI1BDL_SBR2                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR2
    #define SCI1BDL_SBR3                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR3
    #define SCI1BDL_SBR4                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR4
    #define SCI1BDL_SBR5                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR5
    #define SCI1BDL_SBR6                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR6
    #define SCI1BDL_SBR7                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR7
    
    #define SCI1BDL_SBR0_MASK           1U
    #define SCI1BDL_SBR1_MASK           2U
    #define SCI1BDL_SBR2_MASK           4U
    #define SCI1BDL_SBR3_MASK           8U
    #define SCI1BDL_SBR4_MASK           16U
    #define SCI1BDL_SBR5_MASK           32U
    #define SCI1BDL_SBR6_MASK           64U
    #define SCI1BDL_SBR7_MASK           128U
    
  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
    word SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
    word SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
    word SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
    word SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
    word SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
    word SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
    word SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
    word SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
    word SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
    word SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
    word SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
    word SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
    word             :1; 
    word RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
    word LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
  } Bits;
  struct {
    word grpSBR  :13;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} SCI1BDSTR;
#define _SCI1BD (*(volatile SCI1BDSTR *)0xFFFF8038)
#define SCI1BD                          _SCI1BD.Word
#define SCI1BD_SBR0                     _SCI1BD.Bits.SBR0
#define SCI1BD_SBR1                     _SCI1BD.Bits.SBR1
#define SCI1BD_SBR2                     _SCI1BD.Bits.SBR2
#define SCI1BD_SBR3                     _SCI1BD.Bits.SBR3
#define SCI1BD_SBR4                     _SCI1BD.Bits.SBR4
#define SCI1BD_SBR5                     _SCI1BD.Bits.SBR5
#define SCI1BD_SBR6                     _SCI1BD.Bits.SBR6
#define SCI1BD_SBR7                     _SCI1BD.Bits.SBR7
#define SCI1BD_SBR8                     _SCI1BD.Bits.SBR8
#define SCI1BD_SBR9                     _SCI1BD.Bits.SBR9
#define SCI1BD_SBR10                    _SCI1BD.Bits.SBR10
#define SCI1BD_SBR11                    _SCI1BD.Bits.SBR11
#define SCI1BD_SBR12                    _SCI1BD.Bits.SBR12
#define SCI1BD_RXEDGIE                  _SCI1BD.Bits.RXEDGIE
#define SCI1BD_LBKDIE                   _SCI1BD.Bits.LBKDIE
#define SCI1BD_SBR                      _SCI1BD.MergedBits.grpSBR

#define SCI1BD_SBR0_MASK                1U
#define SCI1BD_SBR1_MASK                2U
#define SCI1BD_SBR2_MASK                4U
#define SCI1BD_SBR3_MASK                8U
#define SCI1BD_SBR4_MASK                16U
#define SCI1BD_SBR5_MASK                32U
#define SCI1BD_SBR6_MASK                64U
#define SCI1BD_SBR7_MASK                128U
#define SCI1BD_SBR8_MASK                256U
#define SCI1BD_SBR9_MASK                512U
#define SCI1BD_SBR10_MASK               1024U
#define SCI1BD_SBR11_MASK               2048U
#define SCI1BD_SBR12_MASK               4096U
#define SCI1BD_RXEDGIE_MASK             16384U
#define SCI1BD_LBKDIE_MASK              32768U
#define SCI1BD_SBR_MASK                 8191U
#define SCI1BD_SBR_BITNUM               0U


/*** SCI1C1 - SCI1 Control Register 1; 0xFFFF803A ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type */
    byte PE          :1;                                       /* Parity Enable */
    byte ILT         :1;                                       /* Idle Line Type Select */
    byte WAKE        :1;                                       /* Receiver Wakeup Method Select */
    byte M           :1;                                       /* 9-Bit or 8-Bit Mode Select */
    byte RSRC        :1;                                       /* Receiver Source Select */
    byte SCISWAI     :1;                                       /* SCI Stops in Wait Mode */
    byte LOOPS       :1;                                       /* Loop Mode Select */
  } Bits;
} SCI1C1STR;
#define _SCI1C1 (*(volatile SCI1C1STR *)0xFFFF803A)
#define SCI1C1                          _SCI1C1.Byte
#define SCI1C1_PT                       _SCI1C1.Bits.PT
#define SCI1C1_PE                       _SCI1C1.Bits.PE
#define SCI1C1_ILT                      _SCI1C1.Bits.ILT
#define SCI1C1_WAKE                     _SCI1C1.Bits.WAKE
#define SCI1C1_M                        _SCI1C1.Bits.M
#define SCI1C1_RSRC                     _SCI1C1.Bits.RSRC
#define SCI1C1_SCISWAI                  _SCI1C1.Bits.SCISWAI
#define SCI1C1_LOOPS                    _SCI1C1.Bits.LOOPS

#define SCI1C1_PT_MASK                  1U
#define SCI1C1_PE_MASK                  2U
#define SCI1C1_ILT_MASK                 4U
#define SCI1C1_WAKE_MASK                8U
#define SCI1C1_M_MASK                   16U
#define SCI1C1_RSRC_MASK                32U
#define SCI1C1_SCISWAI_MASK             64U
#define SCI1C1_LOOPS_MASK               128U


/*** SCI1C2 - SCI1 Control Register 2; 0xFFFF803B ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break */
    byte RWU         :1;                                       /* Receiver Wakeup Control */
    byte RE          :1;                                       /* Receiver Enable */
    byte TE          :1;                                       /* Transmitter Enable */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable (for IDLE) */
    byte RIE         :1;                                       /* Receiver Interrupt Enable (for RDRF) */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable (for TC) */
    byte TIE         :1;                                       /* Transmit Interrupt Enable (for TDRE) */
  } Bits;
} SCI1C2STR;
#define _SCI1C2 (*(volatile SCI1C2STR *)0xFFFF803B)
#define SCI1C2                          _SCI1C2.Byte
#define SCI1C2_SBK                      _SCI1C2.Bits.SBK
#define SCI1C2_RWU                      _SCI1C2.Bits.RWU
#define SCI1C2_RE                       _SCI1C2.Bits.RE
#define SCI1C2_TE                       _SCI1C2.Bits.TE
#define SCI1C2_ILIE                     _SCI1C2.Bits.ILIE
#define SCI1C2_RIE                      _SCI1C2.Bits.RIE
#define SCI1C2_TCIE                     _SCI1C2.Bits.TCIE
#define SCI1C2_TIE                      _SCI1C2.Bits.TIE

#define SCI1C2_SBK_MASK                 1U
#define SCI1C2_RWU_MASK                 2U
#define SCI1C2_RE_MASK                  4U
#define SCI1C2_TE_MASK                  8U
#define SCI1C2_ILIE_MASK                16U
#define SCI1C2_RIE_MASK                 32U
#define SCI1C2_TCIE_MASK                64U
#define SCI1C2_TIE_MASK                 128U


/*** SCI1S1 - SCI1 Status Register 1; 0xFFFF803C ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Receiver Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmission Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI1S1STR;
#define _SCI1S1 (*(volatile SCI1S1STR *)0xFFFF803C)
#define SCI1S1                          _SCI1S1.Byte
#define SCI1S1_PF                       _SCI1S1.Bits.PF
#define SCI1S1_FE                       _SCI1S1.Bits.FE
#define SCI1S1_NF                       _SCI1S1.Bits.NF
#define SCI1S1_OR                       _SCI1S1.Bits.OR
#define SCI1S1_IDLE                     _SCI1S1.Bits.IDLE
#define SCI1S1_RDRF                     _SCI1S1.Bits.RDRF
#define SCI1S1_TC                       _SCI1S1.Bits.TC
#define SCI1S1_TDRE                     _SCI1S1.Bits.TDRE

#define SCI1S1_PF_MASK                  1U
#define SCI1S1_FE_MASK                  2U
#define SCI1S1_NF_MASK                  4U
#define SCI1S1_OR_MASK                  8U
#define SCI1S1_IDLE_MASK                16U
#define SCI1S1_RDRF_MASK                32U
#define SCI1S1_TC_MASK                  64U
#define SCI1S1_TDRE_MASK                128U


/*** SCI1S2 - SCI1 Status Register 2; 0xFFFF803D ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte LBKDE       :1;                                       /* LIN Break Detection Enable */
    byte BRK13       :1;                                       /* Break Character Generation Length */
    byte RWUID       :1;                                       /* Receive Wake Up Idle Detect */
    byte RXINV       :1;                                       /* Receive Data Inversion */
    byte             :1; 
    byte RXEDGIF     :1;                                       /* RxD Pin Active Edge Interrupt Flag */
    byte LBKDIF      :1;                                       /* LIN Break Detect Interrupt Flag */
  } Bits;
} SCI1S2STR;
#define _SCI1S2 (*(volatile SCI1S2STR *)0xFFFF803D)
#define SCI1S2                          _SCI1S2.Byte
#define SCI1S2_RAF                      _SCI1S2.Bits.RAF
#define SCI1S2_LBKDE                    _SCI1S2.Bits.LBKDE
#define SCI1S2_BRK13                    _SCI1S2.Bits.BRK13
#define SCI1S2_RWUID                    _SCI1S2.Bits.RWUID
#define SCI1S2_RXINV                    _SCI1S2.Bits.RXINV
#define SCI1S2_RXEDGIF                  _SCI1S2.Bits.RXEDGIF
#define SCI1S2_LBKDIF                   _SCI1S2.Bits.LBKDIF

#define SCI1S2_RAF_MASK                 1U
#define SCI1S2_LBKDE_MASK               2U
#define SCI1S2_BRK13_MASK               4U
#define SCI1S2_RWUID_MASK               8U
#define SCI1S2_RXINV_MASK               16U
#define SCI1S2_RXEDGIF_MASK             64U
#define SCI1S2_LBKDIF_MASK              128U


/*** SCI1C3 - SCI1 Control Register 3; 0xFFFF803E ***/
typedef union {
  byte Byte;
  struct {
    byte PEIE        :1;                                       /* Parity Error Interrupt Enable */
    byte FEIE        :1;                                       /* Framing Error Interrupt Enable */
    byte NEIE        :1;                                       /* Noise Error Interrupt Enable */
    byte ORIE        :1;                                       /* Overrun Interrupt Enable */
    byte TXINV       :1;                                       /* Transmit Data Inversion */
    byte TXDIR       :1;                                       /* TxD Pin Direction in Single-Wire Mode */
    byte T8          :1;                                       /* Ninth Data Bit for Transmitter */
    byte R8          :1;                                       /* Ninth Data Bit for Receiver */
  } Bits;
} SCI1C3STR;
#define _SCI1C3 (*(volatile SCI1C3STR *)0xFFFF803E)
#define SCI1C3                          _SCI1C3.Byte
#define SCI1C3_PEIE                     _SCI1C3.Bits.PEIE
#define SCI1C3_FEIE                     _SCI1C3.Bits.FEIE
#define SCI1C3_NEIE                     _SCI1C3.Bits.NEIE
#define SCI1C3_ORIE                     _SCI1C3.Bits.ORIE
#define SCI1C3_TXINV                    _SCI1C3.Bits.TXINV
#define SCI1C3_TXDIR                    _SCI1C3.Bits.TXDIR
#define SCI1C3_T8                       _SCI1C3.Bits.T8
#define SCI1C3_R8                       _SCI1C3.Bits.R8

#define SCI1C3_PEIE_MASK                1U
#define SCI1C3_FEIE_MASK                2U
#define SCI1C3_NEIE_MASK                4U
#define SCI1C3_ORIE_MASK                8U
#define SCI1C3_TXINV_MASK               16U
#define SCI1C3_TXDIR_MASK               32U
#define SCI1C3_T8_MASK                  64U
#define SCI1C3_R8_MASK                  128U


/*** SCI1D - SCI1 Data Register; 0xFFFF803F ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Receive/Transmit Data Bit 0 */
    byte R1_T1       :1;                                       /* Receive/Transmit Data Bit 1 */
    byte R2_T2       :1;                                       /* Receive/Transmit Data Bit 2 */
    byte R3_T3       :1;                                       /* Receive/Transmit Data Bit 3 */
    byte R4_T4       :1;                                       /* Receive/Transmit Data Bit 4 */
    byte R5_T5       :1;                                       /* Receive/Transmit Data Bit 5 */
    byte R6_T6       :1;                                       /* Receive/Transmit Data Bit 6 */
    byte R7_T7       :1;                                       /* Receive/Transmit Data Bit 7 */
  } Bits;
} SCI1DSTR;
#define _SCI1D (*(volatile SCI1DSTR *)0xFFFF803F)
#define SCI1D                           _SCI1D.Byte
#define SCI1D_R0_T0                     _SCI1D.Bits.R0_T0
#define SCI1D_R1_T1                     _SCI1D.Bits.R1_T1
#define SCI1D_R2_T2                     _SCI1D.Bits.R2_T2
#define SCI1D_R3_T3                     _SCI1D.Bits.R3_T3
#define SCI1D_R4_T4                     _SCI1D.Bits.R4_T4
#define SCI1D_R5_T5                     _SCI1D.Bits.R5_T5
#define SCI1D_R6_T6                     _SCI1D.Bits.R6_T6
#define SCI1D_R7_T7                     _SCI1D.Bits.R7_T7

#define SCI1D_R0_T0_MASK                1U
#define SCI1D_R1_T1_MASK                2U
#define SCI1D_R2_T2_MASK                4U
#define SCI1D_R3_T3_MASK                8U
#define SCI1D_R4_T4_MASK                16U
#define SCI1D_R5_T5_MASK                32U
#define SCI1D_R6_T6_MASK                64U
#define SCI1D_R7_T7_MASK                128U


/*** SCI2BD - SCI2 Baud Rate Register; 0xFFFF8040 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI2BDH - SCI2 Baud Rate Register High; 0xFFFF8040 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
        byte SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
        byte SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
        byte SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
        byte SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
        byte             :1; 
        byte RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
        byte LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI2BDHSTR;
    #define SCI2BDH                     _SCI2BD.Overlap_STR.SCI2BDHSTR.Byte
    #define SCI2BDH_SBR8                _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR8
    #define SCI2BDH_SBR9                _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR9
    #define SCI2BDH_SBR10               _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR10
    #define SCI2BDH_SBR11               _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR11
    #define SCI2BDH_SBR12               _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR12
    #define SCI2BDH_RXEDGIE             _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.RXEDGIE
    #define SCI2BDH_LBKDIE              _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.LBKDIE
    #define SCI2BDH_SBR_8               _SCI2BD.Overlap_STR.SCI2BDHSTR.MergedBits.grpSBR_8
    #define SCI2BDH_SBR                 SCI2BDH_SBR_8
    
    #define SCI2BDH_SBR8_MASK           1U
    #define SCI2BDH_SBR9_MASK           2U
    #define SCI2BDH_SBR10_MASK          4U
    #define SCI2BDH_SBR11_MASK          8U
    #define SCI2BDH_SBR12_MASK          16U
    #define SCI2BDH_RXEDGIE_MASK        64U
    #define SCI2BDH_LBKDIE_MASK         128U
    #define SCI2BDH_SBR_8_MASK          31U
    #define SCI2BDH_SBR_8_BITNUM        0U
    

    /*** SCI2BDL - SCI2 Baud Rate Register Low; 0xFFFF8041 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
        byte SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
        byte SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
        byte SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
      } Bits;
    } SCI2BDLSTR;
    #define SCI2BDL                     _SCI2BD.Overlap_STR.SCI2BDLSTR.Byte
    #define SCI2BDL_SBR0                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR0
    #define SCI2BDL_SBR1                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR1
    #define SCI2BDL_SBR2                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR2
    #define SCI2BDL_SBR3                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR3
    #define SCI2BDL_SBR4                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR4
    #define SCI2BDL_SBR5                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR5
    #define SCI2BDL_SBR6                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR6
    #define SCI2BDL_SBR7                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR7
    
    #define SCI2BDL_SBR0_MASK           1U
    #define SCI2BDL_SBR1_MASK           2U
    #define SCI2BDL_SBR2_MASK           4U
    #define SCI2BDL_SBR3_MASK           8U
    #define SCI2BDL_SBR4_MASK           16U
    #define SCI2BDL_SBR5_MASK           32U
    #define SCI2BDL_SBR6_MASK           64U
    #define SCI2BDL_SBR7_MASK           128U
    
  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
    word SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
    word SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
    word SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
    word SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
    word SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
    word SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
    word SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
    word SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
    word SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
    word SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
    word SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
    word SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
    word             :1; 
    word RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
    word LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
  } Bits;
  struct {
    word grpSBR  :13;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} SCI2BDSTR;
#define _SCI2BD (*(volatile SCI2BDSTR *)0xFFFF8040)
#define SCI2BD                          _SCI2BD.Word
#define SCI2BD_SBR0                     _SCI2BD.Bits.SBR0
#define SCI2BD_SBR1                     _SCI2BD.Bits.SBR1
#define SCI2BD_SBR2                     _SCI2BD.Bits.SBR2
#define SCI2BD_SBR3                     _SCI2BD.Bits.SBR3
#define SCI2BD_SBR4                     _SCI2BD.Bits.SBR4
#define SCI2BD_SBR5                     _SCI2BD.Bits.SBR5
#define SCI2BD_SBR6                     _SCI2BD.Bits.SBR6
#define SCI2BD_SBR7                     _SCI2BD.Bits.SBR7
#define SCI2BD_SBR8                     _SCI2BD.Bits.SBR8
#define SCI2BD_SBR9                     _SCI2BD.Bits.SBR9
#define SCI2BD_SBR10                    _SCI2BD.Bits.SBR10
#define SCI2BD_SBR11                    _SCI2BD.Bits.SBR11
#define SCI2BD_SBR12                    _SCI2BD.Bits.SBR12
#define SCI2BD_RXEDGIE                  _SCI2BD.Bits.RXEDGIE
#define SCI2BD_LBKDIE                   _SCI2BD.Bits.LBKDIE
#define SCI2BD_SBR                      _SCI2BD.MergedBits.grpSBR

#define SCI2BD_SBR0_MASK                1U
#define SCI2BD_SBR1_MASK                2U
#define SCI2BD_SBR2_MASK                4U
#define SCI2BD_SBR3_MASK                8U
#define SCI2BD_SBR4_MASK                16U
#define SCI2BD_SBR5_MASK                32U
#define SCI2BD_SBR6_MASK                64U
#define SCI2BD_SBR7_MASK                128U
#define SCI2BD_SBR8_MASK                256U
#define SCI2BD_SBR9_MASK                512U
#define SCI2BD_SBR10_MASK               1024U
#define SCI2BD_SBR11_MASK               2048U
#define SCI2BD_SBR12_MASK               4096U
#define SCI2BD_RXEDGIE_MASK             16384U
#define SCI2BD_LBKDIE_MASK              32768U
#define SCI2BD_SBR_MASK                 8191U
#define SCI2BD_SBR_BITNUM               0U


/*** SCI2C1 - SCI2 Control Register 1; 0xFFFF8042 ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type */
    byte PE          :1;                                       /* Parity Enable */
    byte ILT         :1;                                       /* Idle Line Type Select */
    byte WAKE        :1;                                       /* Receiver Wakeup Method Select */
    byte M           :1;                                       /* 9-Bit or 8-Bit Mode Select */
    byte RSRC        :1;                                       /* Receiver Source Select */
    byte SCISWAI     :1;                                       /* SCI Stops in Wait Mode */
    byte LOOPS       :1;                                       /* Loop Mode Select */
  } Bits;
} SCI2C1STR;
#define _SCI2C1 (*(volatile SCI2C1STR *)0xFFFF8042)
#define SCI2C1                          _SCI2C1.Byte
#define SCI2C1_PT                       _SCI2C1.Bits.PT
#define SCI2C1_PE                       _SCI2C1.Bits.PE
#define SCI2C1_ILT                      _SCI2C1.Bits.ILT
#define SCI2C1_WAKE                     _SCI2C1.Bits.WAKE
#define SCI2C1_M                        _SCI2C1.Bits.M
#define SCI2C1_RSRC                     _SCI2C1.Bits.RSRC
#define SCI2C1_SCISWAI                  _SCI2C1.Bits.SCISWAI
#define SCI2C1_LOOPS                    _SCI2C1.Bits.LOOPS

#define SCI2C1_PT_MASK                  1U
#define SCI2C1_PE_MASK                  2U
#define SCI2C1_ILT_MASK                 4U
#define SCI2C1_WAKE_MASK                8U
#define SCI2C1_M_MASK                   16U
#define SCI2C1_RSRC_MASK                32U
#define SCI2C1_SCISWAI_MASK             64U
#define SCI2C1_LOOPS_MASK               128U


/*** SCI2C2 - SCI2 Control Register 2; 0xFFFF8043 ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break */
    byte RWU         :1;                                       /* Receiver Wakeup Control */
    byte RE          :1;                                       /* Receiver Enable */
    byte TE          :1;                                       /* Transmitter Enable */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable (for IDLE) */
    byte RIE         :1;                                       /* Receiver Interrupt Enable (for RDRF) */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable (for TC) */
    byte TIE         :1;                                       /* Transmit Interrupt Enable (for TDRE) */
  } Bits;
} SCI2C2STR;
#define _SCI2C2 (*(volatile SCI2C2STR *)0xFFFF8043)
#define SCI2C2                          _SCI2C2.Byte
#define SCI2C2_SBK                      _SCI2C2.Bits.SBK
#define SCI2C2_RWU                      _SCI2C2.Bits.RWU
#define SCI2C2_RE                       _SCI2C2.Bits.RE
#define SCI2C2_TE                       _SCI2C2.Bits.TE
#define SCI2C2_ILIE                     _SCI2C2.Bits.ILIE
#define SCI2C2_RIE                      _SCI2C2.Bits.RIE
#define SCI2C2_TCIE                     _SCI2C2.Bits.TCIE
#define SCI2C2_TIE                      _SCI2C2.Bits.TIE

#define SCI2C2_SBK_MASK                 1U
#define SCI2C2_RWU_MASK                 2U
#define SCI2C2_RE_MASK                  4U
#define SCI2C2_TE_MASK                  8U
#define SCI2C2_ILIE_MASK                16U
#define SCI2C2_RIE_MASK                 32U
#define SCI2C2_TCIE_MASK                64U
#define SCI2C2_TIE_MASK                 128U


/*** SCI2S1 - SCI2 Status Register 1; 0xFFFF8044 ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Receiver Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmission Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI2S1STR;
#define _SCI2S1 (*(volatile SCI2S1STR *)0xFFFF8044)
#define SCI2S1                          _SCI2S1.Byte
#define SCI2S1_PF                       _SCI2S1.Bits.PF
#define SCI2S1_FE                       _SCI2S1.Bits.FE
#define SCI2S1_NF                       _SCI2S1.Bits.NF
#define SCI2S1_OR                       _SCI2S1.Bits.OR
#define SCI2S1_IDLE                     _SCI2S1.Bits.IDLE
#define SCI2S1_RDRF                     _SCI2S1.Bits.RDRF
#define SCI2S1_TC                       _SCI2S1.Bits.TC
#define SCI2S1_TDRE                     _SCI2S1.Bits.TDRE

#define SCI2S1_PF_MASK                  1U
#define SCI2S1_FE_MASK                  2U
#define SCI2S1_NF_MASK                  4U
#define SCI2S1_OR_MASK                  8U
#define SCI2S1_IDLE_MASK                16U
#define SCI2S1_RDRF_MASK                32U
#define SCI2S1_TC_MASK                  64U
#define SCI2S1_TDRE_MASK                128U


/*** SCI2S2 - SCI2 Status Register 2; 0xFFFF8045 ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte LBKDE       :1;                                       /* LIN Break Detection Enable */
    byte BRK13       :1;                                       /* Break Character Generation Length */
    byte RWUID       :1;                                       /* Receive Wake Up Idle Detect */
    byte RXINV       :1;                                       /* Receive Data Inversion */
    byte             :1; 
    byte RXEDGIF     :1;                                       /* RxD Pin Active Edge Interrupt Flag */
    byte LBKDIF      :1;                                       /* LIN Break Detect Interrupt Flag */
  } Bits;
} SCI2S2STR;
#define _SCI2S2 (*(volatile SCI2S2STR *)0xFFFF8045)
#define SCI2S2                          _SCI2S2.Byte
#define SCI2S2_RAF                      _SCI2S2.Bits.RAF
#define SCI2S2_LBKDE                    _SCI2S2.Bits.LBKDE
#define SCI2S2_BRK13                    _SCI2S2.Bits.BRK13
#define SCI2S2_RWUID                    _SCI2S2.Bits.RWUID
#define SCI2S2_RXINV                    _SCI2S2.Bits.RXINV
#define SCI2S2_RXEDGIF                  _SCI2S2.Bits.RXEDGIF
#define SCI2S2_LBKDIF                   _SCI2S2.Bits.LBKDIF

#define SCI2S2_RAF_MASK                 1U
#define SCI2S2_LBKDE_MASK               2U
#define SCI2S2_BRK13_MASK               4U
#define SCI2S2_RWUID_MASK               8U
#define SCI2S2_RXINV_MASK               16U
#define SCI2S2_RXEDGIF_MASK             64U
#define SCI2S2_LBKDIF_MASK              128U


/*** SCI2C3 - SCI2 Control Register 3; 0xFFFF8046 ***/
typedef union {
  byte Byte;
  struct {
    byte PEIE        :1;                                       /* Parity Error Interrupt Enable */
    byte FEIE        :1;                                       /* Framing Error Interrupt Enable */
    byte NEIE        :1;                                       /* Noise Error Interrupt Enable */
    byte ORIE        :1;                                       /* Overrun Interrupt Enable */
    byte TXINV       :1;                                       /* Transmit Data Inversion */
    byte TXDIR       :1;                                       /* TxD Pin Direction in Single-Wire Mode */
    byte T8          :1;                                       /* Ninth Data Bit for Transmitter */
    byte R8          :1;                                       /* Ninth Data Bit for Receiver */
  } Bits;
} SCI2C3STR;
#define _SCI2C3 (*(volatile SCI2C3STR *)0xFFFF8046)
#define SCI2C3                          _SCI2C3.Byte
#define SCI2C3_PEIE                     _SCI2C3.Bits.PEIE
#define SCI2C3_FEIE                     _SCI2C3.Bits.FEIE
#define SCI2C3_NEIE                     _SCI2C3.Bits.NEIE
#define SCI2C3_ORIE                     _SCI2C3.Bits.ORIE
#define SCI2C3_TXINV                    _SCI2C3.Bits.TXINV
#define SCI2C3_TXDIR                    _SCI2C3.Bits.TXDIR
#define SCI2C3_T8                       _SCI2C3.Bits.T8
#define SCI2C3_R8                       _SCI2C3.Bits.R8

#define SCI2C3_PEIE_MASK                1U
#define SCI2C3_FEIE_MASK                2U
#define SCI2C3_NEIE_MASK                4U
#define SCI2C3_ORIE_MASK                8U
#define SCI2C3_TXINV_MASK               16U
#define SCI2C3_TXDIR_MASK               32U
#define SCI2C3_T8_MASK                  64U
#define SCI2C3_R8_MASK                  128U


/*** SCI2D - SCI2 Data Register; 0xFFFF8047 ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Receive/Transmit Data Bit 0 */
    byte R1_T1       :1;                                       /* Receive/Transmit Data Bit 1 */
    byte R2_T2       :1;                                       /* Receive/Transmit Data Bit 2 */
    byte R3_T3       :1;                                       /* Receive/Transmit Data Bit 3 */
    byte R4_T4       :1;                                       /* Receive/Transmit Data Bit 4 */
    byte R5_T5       :1;                                       /* Receive/Transmit Data Bit 5 */
    byte R6_T6       :1;                                       /* Receive/Transmit Data Bit 6 */
    byte R7_T7       :1;                                       /* Receive/Transmit Data Bit 7 */
  } Bits;
} SCI2DSTR;
#define _SCI2D (*(volatile SCI2DSTR *)0xFFFF8047)
#define SCI2D                           _SCI2D.Byte
#define SCI2D_R0_T0                     _SCI2D.Bits.R0_T0
#define SCI2D_R1_T1                     _SCI2D.Bits.R1_T1
#define SCI2D_R2_T2                     _SCI2D.Bits.R2_T2
#define SCI2D_R3_T3                     _SCI2D.Bits.R3_T3
#define SCI2D_R4_T4                     _SCI2D.Bits.R4_T4
#define SCI2D_R5_T5                     _SCI2D.Bits.R5_T5
#define SCI2D_R6_T6                     _SCI2D.Bits.R6_T6
#define SCI2D_R7_T7                     _SCI2D.Bits.R7_T7

#define SCI2D_R0_T0_MASK                1U
#define SCI2D_R1_T1_MASK                2U
#define SCI2D_R2_T2_MASK                4U
#define SCI2D_R3_T3_MASK                8U
#define SCI2D_R4_T4_MASK                16U
#define SCI2D_R5_T5_MASK                32U
#define SCI2D_R6_T6_MASK                64U
#define SCI2D_R7_T7_MASK                128U


/*** MCGC1 - MCG Control Register 1; 0xFFFF8048 ***/
typedef union {
  byte Byte;
  struct {
    byte IREFSTEN    :1;                                       /* Internal Reference Stop Enable */
    byte IRCLKEN     :1;                                       /* Internal Reference Clock Enable */
    byte IREFS       :1;                                       /* Internal Reference Select */
    byte RDIV0       :1;                                       /* Reference Divider, bit 0 */
    byte RDIV1       :1;                                       /* Reference Divider, bit 1 */
    byte RDIV2       :1;                                       /* Reference Divider, bit 2 */
    byte CLKS0       :1;                                       /* Clock Source Select, bit 0 */
    byte CLKS1       :1;                                       /* Clock Source Select, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRDIV :3;
    byte grpCLKS :2;
  } MergedBits;
} MCGC1STR;
#define _MCGC1 (*(volatile MCGC1STR *)0xFFFF8048)
#define MCGC1                           _MCGC1.Byte
#define MCGC1_IREFSTEN                  _MCGC1.Bits.IREFSTEN
#define MCGC1_IRCLKEN                   _MCGC1.Bits.IRCLKEN
#define MCGC1_IREFS                     _MCGC1.Bits.IREFS
#define MCGC1_RDIV0                     _MCGC1.Bits.RDIV0
#define MCGC1_RDIV1                     _MCGC1.Bits.RDIV1
#define MCGC1_RDIV2                     _MCGC1.Bits.RDIV2
#define MCGC1_CLKS0                     _MCGC1.Bits.CLKS0
#define MCGC1_CLKS1                     _MCGC1.Bits.CLKS1
#define MCGC1_RDIV                      _MCGC1.MergedBits.grpRDIV
#define MCGC1_CLKS                      _MCGC1.MergedBits.grpCLKS

#define MCGC1_IREFSTEN_MASK             1U
#define MCGC1_IRCLKEN_MASK              2U
#define MCGC1_IREFS_MASK                4U
#define MCGC1_RDIV0_MASK                8U
#define MCGC1_RDIV1_MASK                16U
#define MCGC1_RDIV2_MASK                32U
#define MCGC1_CLKS0_MASK                64U
#define MCGC1_CLKS1_MASK                128U
#define MCGC1_RDIV_MASK                 56U
#define MCGC1_RDIV_BITNUM               3U
#define MCGC1_CLKS_MASK                 192U
#define MCGC1_CLKS_BITNUM               6U


/*** MCGC2 - MCG Control Register 2; 0xFFFF8049 ***/
typedef union {
  byte Byte;
  struct {
    byte EREFSTEN    :1;                                       /* External Reference Stop Enable */
    byte ERCLKEN     :1;                                       /* External Reference Enable */
    byte EREFS       :1;                                       /* External Reference Select */
    byte LP          :1;                                       /* Low Power Select */
    byte HGO         :1;                                       /* High Gain Oscillator Select */
    byte RANGE       :1;                                       /* Frequency Range Select */
    byte BDIV0       :1;                                       /* Bus Frequency Divider, bit 0 */
    byte BDIV1       :1;                                       /* Bus Frequency Divider, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpBDIV :2;
  } MergedBits;
} MCGC2STR;
#define _MCGC2 (*(volatile MCGC2STR *)0xFFFF8049)
#define MCGC2                           _MCGC2.Byte
#define MCGC2_EREFSTEN                  _MCGC2.Bits.EREFSTEN
#define MCGC2_ERCLKEN                   _MCGC2.Bits.ERCLKEN
#define MCGC2_EREFS                     _MCGC2.Bits.EREFS
#define MCGC2_LP                        _MCGC2.Bits.LP
#define MCGC2_HGO                       _MCGC2.Bits.HGO
#define MCGC2_RANGE                     _MCGC2.Bits.RANGE
#define MCGC2_BDIV0                     _MCGC2.Bits.BDIV0
#define MCGC2_BDIV1                     _MCGC2.Bits.BDIV1
#define MCGC2_BDIV                      _MCGC2.MergedBits.grpBDIV

#define MCGC2_EREFSTEN_MASK             1U
#define MCGC2_ERCLKEN_MASK              2U
#define MCGC2_EREFS_MASK                4U
#define MCGC2_LP_MASK                   8U
#define MCGC2_HGO_MASK                  16U
#define MCGC2_RANGE_MASK                32U
#define MCGC2_BDIV0_MASK                64U
#define MCGC2_BDIV1_MASK                128U
#define MCGC2_BDIV_MASK                 192U
#define MCGC2_BDIV_BITNUM               6U


/*** MCGTRM - MCG Trim Register; 0xFFFF804A ***/
typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       /* MCG Trim Setting, bit 0 */
    byte TRIM1       :1;                                       /* MCG Trim Setting, bit 1 */
    byte TRIM2       :1;                                       /* MCG Trim Setting, bit 2 */
    byte TRIM3       :1;                                       /* MCG Trim Setting, bit 3 */
    byte TRIM4       :1;                                       /* MCG Trim Setting, bit 4 */
    byte TRIM5       :1;                                       /* MCG Trim Setting, bit 5 */
    byte TRIM6       :1;                                       /* MCG Trim Setting, bit 6 */
    byte TRIM7       :1;                                       /* MCG Trim Setting, bit 7 */
  } Bits;
} MCGTRMSTR;
#define _MCGTRM (*(volatile MCGTRMSTR *)0xFFFF804A)
#define MCGTRM                          _MCGTRM.Byte
#define MCGTRM_TRIM0                    _MCGTRM.Bits.TRIM0
#define MCGTRM_TRIM1                    _MCGTRM.Bits.TRIM1
#define MCGTRM_TRIM2                    _MCGTRM.Bits.TRIM2
#define MCGTRM_TRIM3                    _MCGTRM.Bits.TRIM3
#define MCGTRM_TRIM4                    _MCGTRM.Bits.TRIM4
#define MCGTRM_TRIM5                    _MCGTRM.Bits.TRIM5
#define MCGTRM_TRIM6                    _MCGTRM.Bits.TRIM6
#define MCGTRM_TRIM7                    _MCGTRM.Bits.TRIM7

#define MCGTRM_TRIM0_MASK               1U
#define MCGTRM_TRIM1_MASK               2U
#define MCGTRM_TRIM2_MASK               4U
#define MCGTRM_TRIM3_MASK               8U
#define MCGTRM_TRIM4_MASK               16U
#define MCGTRM_TRIM5_MASK               32U
#define MCGTRM_TRIM6_MASK               64U
#define MCGTRM_TRIM7_MASK               128U


/*** MCGSC - MCG Status and Control Register; 0xFFFF804B ***/
typedef union {
  byte Byte;
  struct {
    byte FTRIM       :1;                                       /* MCG Fine Trim */
    byte OSCINIT     :1;                                       /* OSC Initialization */
    byte CLKST0      :1;                                       /* Clock Mode Status, bit 0 */
    byte CLKST1      :1;                                       /* Clock Mode Status, bit 1 */
    byte IREFST      :1;                                       /* Internal Reference Status */
    byte PLLST       :1;                                       /* PLL Select Status */
    byte LOCK        :1;                                       /* Lock Status */
    byte LOLS        :1;                                       /* Loss of Lock Status */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpCLKST :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MCGSCSTR;
#define _MCGSC (*(volatile MCGSCSTR *)0xFFFF804B)
#define MCGSC                           _MCGSC.Byte
#define MCGSC_FTRIM                     _MCGSC.Bits.FTRIM
#define MCGSC_OSCINIT                   _MCGSC.Bits.OSCINIT
#define MCGSC_CLKST0                    _MCGSC.Bits.CLKST0
#define MCGSC_CLKST1                    _MCGSC.Bits.CLKST1
#define MCGSC_IREFST                    _MCGSC.Bits.IREFST
#define MCGSC_PLLST                     _MCGSC.Bits.PLLST
#define MCGSC_LOCK                      _MCGSC.Bits.LOCK
#define MCGSC_LOLS                      _MCGSC.Bits.LOLS
#define MCGSC_CLKST                     _MCGSC.MergedBits.grpCLKST

#define MCGSC_FTRIM_MASK                1U
#define MCGSC_OSCINIT_MASK              2U
#define MCGSC_CLKST0_MASK               4U
#define MCGSC_CLKST1_MASK               8U
#define MCGSC_IREFST_MASK               16U
#define MCGSC_PLLST_MASK                32U
#define MCGSC_LOCK_MASK                 64U
#define MCGSC_LOLS_MASK                 128U
#define MCGSC_CLKST_MASK                12U
#define MCGSC_CLKST_BITNUM              2U


/*** MCGC3 - MCG Control Register 3; 0xFFFF804C ***/
typedef union {
  byte Byte;
  struct {
    byte VDIV0       :1;                                       /* VCO Divider, bit 0 */
    byte VDIV1       :1;                                       /* VCO Divider, bit 1 */
    byte VDIV2       :1;                                       /* VCO Divider, bit 2 */
    byte VDIV3       :1;                                       /* VCO Divider, bit 3 */
    byte DIV32       :1;                                       /* Divide-by-32 Enable */
    byte CME         :1;                                       /* Clock Monitor Enable */
    byte PLLS        :1;                                       /* PLL Select */
    byte LOLIE       :1;                                       /* Loss of Lock Interrupt Enable */
  } Bits;
  struct {
    byte grpVDIV :4;
    byte grpDIV_32 :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MCGC3STR;
#define _MCGC3 (*(volatile MCGC3STR *)0xFFFF804C)
#define MCGC3                           _MCGC3.Byte
#define MCGC3_VDIV0                     _MCGC3.Bits.VDIV0
#define MCGC3_VDIV1                     _MCGC3.Bits.VDIV1
#define MCGC3_VDIV2                     _MCGC3.Bits.VDIV2
#define MCGC3_VDIV3                     _MCGC3.Bits.VDIV3
#define MCGC3_DIV32                     _MCGC3.Bits.DIV32
#define MCGC3_CME                       _MCGC3.Bits.CME
#define MCGC3_PLLS                      _MCGC3.Bits.PLLS
#define MCGC3_LOLIE                     _MCGC3.Bits.LOLIE
#define MCGC3_VDIV                      _MCGC3.MergedBits.grpVDIV

#define MCGC3_VDIV0_MASK                1U
#define MCGC3_VDIV1_MASK                2U
#define MCGC3_VDIV2_MASK                4U
#define MCGC3_VDIV3_MASK                8U
#define MCGC3_DIV32_MASK                16U
#define MCGC3_CME_MASK                  32U
#define MCGC3_PLLS_MASK                 64U
#define MCGC3_LOLIE_MASK                128U
#define MCGC3_VDIV_MASK                 15U
#define MCGC3_VDIV_BITNUM               0U


/*** MCGC4 - MCG Control Register 4; 0xFFFF804D ***/
typedef union {
  byte Byte;
  struct {
    byte DRST_DRS0   :1;                                       /* DCO Range Status / DCO Range Select, bit 0 */
    byte DRST_DRS1   :1;                                       /* DCO Range Status / DCO Range Select, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DMX32       :1;                                       /* DCO Maximum frequency with 32.768 kHz reference */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDRST_DRS :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpDMX_32 :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MCGC4STR;
#define _MCGC4 (*(volatile MCGC4STR *)0xFFFF804D)
#define MCGC4                           _MCGC4.Byte
#define MCGC4_DRST_DRS0                 _MCGC4.Bits.DRST_DRS0
#define MCGC4_DRST_DRS1                 _MCGC4.Bits.DRST_DRS1
#define MCGC4_DMX32                     _MCGC4.Bits.DMX32
#define MCGC4_DRST_DRS                  _MCGC4.MergedBits.grpDRST_DRS

#define MCGC4_DRST_DRS0_MASK            1U
#define MCGC4_DRST_DRS1_MASK            2U
#define MCGC4_DMX32_MASK                32U
#define MCGC4_DRST_DRS_MASK             3U
#define MCGC4_DRST_DRS_BITNUM           0U


/*** SPI1C1 - SPI1 Control Register 1; 0xFFFF8050 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* LSB First (Shifter Direction) */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* Clock Phase */
    byte CPOL        :1;                                       /* Clock Polarity */
    byte MSTR        :1;                                       /* Master/Slave Mode Select */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable */
    byte SPIE        :1;                                       /* SPI Interrupt Enable (for SPRF and MODF) */
  } Bits;
} SPI1C1STR;
#define _SPI1C1 (*(volatile SPI1C1STR *)0xFFFF8050)
#define SPI1C1                          _SPI1C1.Byte
#define SPI1C1_LSBFE                    _SPI1C1.Bits.LSBFE
#define SPI1C1_SSOE                     _SPI1C1.Bits.SSOE
#define SPI1C1_CPHA                     _SPI1C1.Bits.CPHA
#define SPI1C1_CPOL                     _SPI1C1.Bits.CPOL
#define SPI1C1_MSTR                     _SPI1C1.Bits.MSTR
#define SPI1C1_SPTIE                    _SPI1C1.Bits.SPTIE
#define SPI1C1_SPE                      _SPI1C1.Bits.SPE
#define SPI1C1_SPIE                     _SPI1C1.Bits.SPIE

#define SPI1C1_LSBFE_MASK               1U
#define SPI1C1_SSOE_MASK                2U
#define SPI1C1_CPHA_MASK                4U
#define SPI1C1_CPOL_MASK                8U
#define SPI1C1_MSTR_MASK                16U
#define SPI1C1_SPTIE_MASK               32U
#define SPI1C1_SPE_MASK                 64U
#define SPI1C1_SPIE_MASK                128U


/*** SPI1C2 - SPI1 Control Register 2; 0xFFFF8051 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI Pin Control 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional Mode Output Enable */
    byte MODFEN      :1;                                       /* Master Mode-Fault Function Enable */
    byte             :1; 
    byte SPIMODE     :1;                                       /* SPI 8- or 16-bit Mode Select */
    byte SPMIE       :1;                                       /* SPI Match Interrupt Enable */
  } Bits;
} SPI1C2STR;
#define _SPI1C2 (*(volatile SPI1C2STR *)0xFFFF8051)
#define SPI1C2                          _SPI1C2.Byte
#define SPI1C2_SPC0                     _SPI1C2.Bits.SPC0
#define SPI1C2_SPISWAI                  _SPI1C2.Bits.SPISWAI
#define SPI1C2_BIDIROE                  _SPI1C2.Bits.BIDIROE
#define SPI1C2_MODFEN                   _SPI1C2.Bits.MODFEN
#define SPI1C2_SPIMODE                  _SPI1C2.Bits.SPIMODE
#define SPI1C2_SPMIE                    _SPI1C2.Bits.SPMIE

#define SPI1C2_SPC0_MASK                1U
#define SPI1C2_SPISWAI_MASK             2U
#define SPI1C2_BIDIROE_MASK             8U
#define SPI1C2_MODFEN_MASK              16U
#define SPI1C2_SPIMODE_MASK             64U
#define SPI1C2_SPMIE_MASK               128U


/*** SPI1BR - SPI1 Baud Rate Register; 0xFFFF8052 ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Divisor Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Divisor Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Divisor Bit 2 */
    byte             :1; 
    byte SPPR0       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPI1BRSTR;
#define _SPI1BR (*(volatile SPI1BRSTR *)0xFFFF8052)
#define SPI1BR                          _SPI1BR.Byte
#define SPI1BR_SPR0                     _SPI1BR.Bits.SPR0
#define SPI1BR_SPR1                     _SPI1BR.Bits.SPR1
#define SPI1BR_SPR2                     _SPI1BR.Bits.SPR2
#define SPI1BR_SPPR0                    _SPI1BR.Bits.SPPR0
#define SPI1BR_SPPR1                    _SPI1BR.Bits.SPPR1
#define SPI1BR_SPPR2                    _SPI1BR.Bits.SPPR2
#define SPI1BR_SPR                      _SPI1BR.MergedBits.grpSPR
#define SPI1BR_SPPR                     _SPI1BR.MergedBits.grpSPPR

#define SPI1BR_SPR0_MASK                1U
#define SPI1BR_SPR1_MASK                2U
#define SPI1BR_SPR2_MASK                4U
#define SPI1BR_SPPR0_MASK               16U
#define SPI1BR_SPPR1_MASK               32U
#define SPI1BR_SPPR2_MASK               64U
#define SPI1BR_SPR_MASK                 7U
#define SPI1BR_SPR_BITNUM               0U
#define SPI1BR_SPPR_MASK                112U
#define SPI1BR_SPPR_BITNUM              4U


/*** SPI1S - SPI1 Status Register; 0xFFFF8053 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Master Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Buffer Empty Flag */
    byte SPMF        :1;                                       /* SPI Match Flag */
    byte SPRF        :1;                                       /* SPI Read Buffer Full Flag */
  } Bits;
} SPI1SSTR;
#define _SPI1S (*(volatile SPI1SSTR *)0xFFFF8053)
#define SPI1S                           _SPI1S.Byte
#define SPI1S_MODF                      _SPI1S.Bits.MODF
#define SPI1S_SPTEF                     _SPI1S.Bits.SPTEF
#define SPI1S_SPMF                      _SPI1S.Bits.SPMF
#define SPI1S_SPRF                      _SPI1S.Bits.SPRF

#define SPI1S_MODF_MASK                 16U
#define SPI1S_SPTEF_MASK                32U
#define SPI1S_SPMF_MASK                 64U
#define SPI1S_SPRF_MASK                 128U


/*** SPI1D16 - SPI1 Data Register; 0xFFFF8054 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPI1DH - SPI1 Data Register High; 0xFFFF8054 ***/
    union {
      byte Byte;
    } SPI1DHSTR;
    #define SPI1DH                      _SPI1D16.Overlap_STR.SPI1DHSTR.Byte
    

    /*** SPI1DL - SPI1 Data Register Low; 0xFFFF8055 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SPI1DL - SPI1 Data Register Low; Several registers at the same address ***/
        #define SPI1DL                  _SPI1D16.Overlap_STR.SPI1DLSTR.Byte
        
        /*** SPI1D - SPI1 Data Register Low; Several registers at the same address ***/
        union {
          struct {
            byte Bit0        :1;                                       /* SPI Data Bit 0 */
            byte Bit1        :1;                                       /* SPI Data Bit 1 */
            byte Bit2        :1;                                       /* SPI Data Bit 2 */
            byte Bit3        :1;                                       /* SPI Data Bit 3 */
            byte Bit4        :1;                                       /* SPI Data Bit 4 */
            byte Bit5        :1;                                       /* SPI Data Bit 5 */
            byte Bit6        :1;                                       /* SPI Data Bit 6 */
            byte Bit7        :1;                                       /* SPI Data Bit 7 */
          } Bits;
        } SPI1DSTR;
        #define SPI1D                   _SPI1D16.Overlap_STR.SPI1DLSTR.Byte
        #define SPI1D_Bit0              _SPI1D16.Overlap_STR.SPI1DLSTR.SameAddr_STR.SPI1DSTR.Bits.Bit0
        #define SPI1D_Bit1              _SPI1D16.Overlap_STR.SPI1DLSTR.SameAddr_STR.SPI1DSTR.Bits.Bit1
        #define SPI1D_Bit2              _SPI1D16.Overlap_STR.SPI1DLSTR.SameAddr_STR.SPI1DSTR.Bits.Bit2
        #define SPI1D_Bit3              _SPI1D16.Overlap_STR.SPI1DLSTR.SameAddr_STR.SPI1DSTR.Bits.Bit3
        #define SPI1D_Bit4              _SPI1D16.Overlap_STR.SPI1DLSTR.SameAddr_STR.SPI1DSTR.Bits.Bit4
        #define SPI1D_Bit5              _SPI1D16.Overlap_STR.SPI1DLSTR.SameAddr_STR.SPI1DSTR.Bits.Bit5
        #define SPI1D_Bit6              _SPI1D16.Overlap_STR.SPI1DLSTR.SameAddr_STR.SPI1DSTR.Bits.Bit6
        #define SPI1D_Bit7              _SPI1D16.Overlap_STR.SPI1DLSTR.SameAddr_STR.SPI1DSTR.Bits.Bit7
        
        #define SPI1D_Bit0_MASK         1U
        #define SPI1D_Bit1_MASK         2U
        #define SPI1D_Bit2_MASK         4U
        #define SPI1D_Bit3_MASK         8U
        #define SPI1D_Bit4_MASK         16U
        #define SPI1D_Bit5_MASK         32U
        #define SPI1D_Bit6_MASK         64U
        #define SPI1D_Bit7_MASK         128U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SPI1DLSTR;
    
  } Overlap_STR;

} SPI1D16STR;
#define _SPI1D16 (*(volatile SPI1D16STR *)0xFFFF8054)
#define SPI1D16                         _SPI1D16.Word


/*** SPI1M - SPI1 Match Register; 0xFFFF8056 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPI1MH - SPI1 Match Register High; 0xFFFF8056 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* SPI Match Value Bit 8 */
        byte Bit9        :1;                                       /* SPI Match Value Bit 9 */
        byte Bit10       :1;                                       /* SPI Match Value Bit 10 */
        byte Bit11       :1;                                       /* SPI Match Value Bit 11 */
        byte Bit12       :1;                                       /* SPI Match Value Bit 12 */
        byte Bit13       :1;                                       /* SPI Match Value Bit 13 */
        byte Bit14       :1;                                       /* SPI Match Value Bit 14 */
        byte Bit15       :1;                                       /* SPI Match Value Bit 15 */
      } Bits;
    } SPI1MHSTR;
    #define SPI1MH                      _SPI1M.Overlap_STR.SPI1MHSTR.Byte
    #define SPI1MH_Bit8                 _SPI1M.Overlap_STR.SPI1MHSTR.Bits.Bit8
    #define SPI1MH_Bit9                 _SPI1M.Overlap_STR.SPI1MHSTR.Bits.Bit9
    #define SPI1MH_Bit10                _SPI1M.Overlap_STR.SPI1MHSTR.Bits.Bit10
    #define SPI1MH_Bit11                _SPI1M.Overlap_STR.SPI1MHSTR.Bits.Bit11
    #define SPI1MH_Bit12                _SPI1M.Overlap_STR.SPI1MHSTR.Bits.Bit12
    #define SPI1MH_Bit13                _SPI1M.Overlap_STR.SPI1MHSTR.Bits.Bit13
    #define SPI1MH_Bit14                _SPI1M.Overlap_STR.SPI1MHSTR.Bits.Bit14
    #define SPI1MH_Bit15                _SPI1M.Overlap_STR.SPI1MHSTR.Bits.Bit15
    
    #define SPI1MH_Bit8_MASK            1U
    #define SPI1MH_Bit9_MASK            2U
    #define SPI1MH_Bit10_MASK           4U
    #define SPI1MH_Bit11_MASK           8U
    #define SPI1MH_Bit12_MASK           16U
    #define SPI1MH_Bit13_MASK           32U
    #define SPI1MH_Bit14_MASK           64U
    #define SPI1MH_Bit15_MASK           128U
    

    /*** SPI1ML - SPI1 Match Register Low; 0xFFFF8057 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* SPI Match Value Bit 0 */
        byte Bit1        :1;                                       /* SPI Match Value Bit 1 */
        byte Bit2        :1;                                       /* SPI Match Value Bit 2 */
        byte Bit3        :1;                                       /* SPI Match Value Bit 3 */
        byte Bit4        :1;                                       /* SPI Match Value Bit 4 */
        byte Bit5        :1;                                       /* SPI Match Value Bit 5 */
        byte Bit6        :1;                                       /* SPI Match Value Bit 6 */
        byte Bit7        :1;                                       /* SPI Match Value Bit 7 */
      } Bits;
    } SPI1MLSTR;
    #define SPI1ML                      _SPI1M.Overlap_STR.SPI1MLSTR.Byte
    #define SPI1ML_Bit0                 _SPI1M.Overlap_STR.SPI1MLSTR.Bits.Bit0
    #define SPI1ML_Bit1                 _SPI1M.Overlap_STR.SPI1MLSTR.Bits.Bit1
    #define SPI1ML_Bit2                 _SPI1M.Overlap_STR.SPI1MLSTR.Bits.Bit2
    #define SPI1ML_Bit3                 _SPI1M.Overlap_STR.SPI1MLSTR.Bits.Bit3
    #define SPI1ML_Bit4                 _SPI1M.Overlap_STR.SPI1MLSTR.Bits.Bit4
    #define SPI1ML_Bit5                 _SPI1M.Overlap_STR.SPI1MLSTR.Bits.Bit5
    #define SPI1ML_Bit6                 _SPI1M.Overlap_STR.SPI1MLSTR.Bits.Bit6
    #define SPI1ML_Bit7                 _SPI1M.Overlap_STR.SPI1MLSTR.Bits.Bit7
    
    #define SPI1ML_Bit0_MASK            1U
    #define SPI1ML_Bit1_MASK            2U
    #define SPI1ML_Bit2_MASK            4U
    #define SPI1ML_Bit3_MASK            8U
    #define SPI1ML_Bit4_MASK            16U
    #define SPI1ML_Bit5_MASK            32U
    #define SPI1ML_Bit6_MASK            64U
    #define SPI1ML_Bit7_MASK            128U
    
  } Overlap_STR;

  struct {
    word Bit0        :1;                                       /* SPI Match Value Bit 0 */
    word Bit1        :1;                                       /* SPI Match Value Bit 1 */
    word Bit2        :1;                                       /* SPI Match Value Bit 2 */
    word Bit3        :1;                                       /* SPI Match Value Bit 3 */
    word Bit4        :1;                                       /* SPI Match Value Bit 4 */
    word Bit5        :1;                                       /* SPI Match Value Bit 5 */
    word Bit6        :1;                                       /* SPI Match Value Bit 6 */
    word Bit7        :1;                                       /* SPI Match Value Bit 7 */
    word Bit8        :1;                                       /* SPI Match Value Bit 8 */
    word Bit9        :1;                                       /* SPI Match Value Bit 9 */
    word Bit10       :1;                                       /* SPI Match Value Bit 10 */
    word Bit11       :1;                                       /* SPI Match Value Bit 11 */
    word Bit12       :1;                                       /* SPI Match Value Bit 12 */
    word Bit13       :1;                                       /* SPI Match Value Bit 13 */
    word Bit14       :1;                                       /* SPI Match Value Bit 14 */
    word Bit15       :1;                                       /* SPI Match Value Bit 15 */
  } Bits;
} SPI1MSTR;
#define _SPI1M (*(volatile SPI1MSTR *)0xFFFF8056)
#define SPI1M                           _SPI1M.Word
#define SPI1M_Bit0                      _SPI1M.Bits.Bit0
#define SPI1M_Bit1                      _SPI1M.Bits.Bit1
#define SPI1M_Bit2                      _SPI1M.Bits.Bit2
#define SPI1M_Bit3                      _SPI1M.Bits.Bit3
#define SPI1M_Bit4                      _SPI1M.Bits.Bit4
#define SPI1M_Bit5                      _SPI1M.Bits.Bit5
#define SPI1M_Bit6                      _SPI1M.Bits.Bit6
#define SPI1M_Bit7                      _SPI1M.Bits.Bit7
#define SPI1M_Bit8                      _SPI1M.Bits.Bit8
#define SPI1M_Bit9                      _SPI1M.Bits.Bit9
#define SPI1M_Bit10                     _SPI1M.Bits.Bit10
#define SPI1M_Bit11                     _SPI1M.Bits.Bit11
#define SPI1M_Bit12                     _SPI1M.Bits.Bit12
#define SPI1M_Bit13                     _SPI1M.Bits.Bit13
#define SPI1M_Bit14                     _SPI1M.Bits.Bit14
#define SPI1M_Bit15                     _SPI1M.Bits.Bit15

#define SPI1M_Bit0_MASK                 1U
#define SPI1M_Bit1_MASK                 2U
#define SPI1M_Bit2_MASK                 4U
#define SPI1M_Bit3_MASK                 8U
#define SPI1M_Bit4_MASK                 16U
#define SPI1M_Bit5_MASK                 32U
#define SPI1M_Bit6_MASK                 64U
#define SPI1M_Bit7_MASK                 128U
#define SPI1M_Bit8_MASK                 256U
#define SPI1M_Bit9_MASK                 512U
#define SPI1M_Bit10_MASK                1024U
#define SPI1M_Bit11_MASK                2048U
#define SPI1M_Bit12_MASK                4096U
#define SPI1M_Bit13_MASK                8192U
#define SPI1M_Bit14_MASK                16384U
#define SPI1M_Bit15_MASK                32768U


/*** IIC1A - IIC Address Register; 0xFFFF8058 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte AD1         :1;                                       /* Slave Address Bit 1 */
    byte AD2         :1;                                       /* Slave Address Bit 2 */
    byte AD3         :1;                                       /* Slave Address Bit 3 */
    byte AD4         :1;                                       /* Slave Address Bit 4 */
    byte AD5         :1;                                       /* Slave Address Bit 5 */
    byte AD6         :1;                                       /* Slave Address Bit 6 */
    byte AD7         :1;                                       /* Slave Address Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpAD_1 :7;
  } MergedBits;
} IIC1ASTR;
#define _IIC1A (*(volatile IIC1ASTR *)0xFFFF8058)
#define IIC1A                           _IIC1A.Byte
#define IIC1A_AD1                       _IIC1A.Bits.AD1
#define IIC1A_AD2                       _IIC1A.Bits.AD2
#define IIC1A_AD3                       _IIC1A.Bits.AD3
#define IIC1A_AD4                       _IIC1A.Bits.AD4
#define IIC1A_AD5                       _IIC1A.Bits.AD5
#define IIC1A_AD6                       _IIC1A.Bits.AD6
#define IIC1A_AD7                       _IIC1A.Bits.AD7
#define IIC1A_AD_1                      _IIC1A.MergedBits.grpAD_1
#define IIC1A_AD                        IIC1A_AD_1

#define IIC1A_AD1_MASK                  2U
#define IIC1A_AD2_MASK                  4U
#define IIC1A_AD3_MASK                  8U
#define IIC1A_AD4_MASK                  16U
#define IIC1A_AD5_MASK                  32U
#define IIC1A_AD6_MASK                  64U
#define IIC1A_AD7_MASK                  128U
#define IIC1A_AD_1_MASK                 254U
#define IIC1A_AD_1_BITNUM               1U


/*** IIC1F - IIC Frequency Divider Register; 0xFFFF8059 ***/
typedef union {
  byte Byte;
  struct {
    byte ICR0        :1;                                       /* IIC Clock Rate Bit 0 */
    byte ICR1        :1;                                       /* IIC Clock Rate Bit 1 */
    byte ICR2        :1;                                       /* IIC Clock Rate Bit 2 */
    byte ICR3        :1;                                       /* IIC Clock Rate Bit 3 */
    byte ICR4        :1;                                       /* IIC Clock Rate Bit 4 */
    byte ICR5        :1;                                       /* IIC Clock Rate Bit 5 */
    byte MULT0       :1;                                       /* Multiplier Factor Bit 0 */
    byte MULT1       :1;                                       /* Multiplier Factor Bit 1 */
  } Bits;
  struct {
    byte grpICR  :6;
    byte grpMULT :2;
  } MergedBits;
} IIC1FSTR;
#define _IIC1F (*(volatile IIC1FSTR *)0xFFFF8059)
#define IIC1F                           _IIC1F.Byte
#define IIC1F_ICR0                      _IIC1F.Bits.ICR0
#define IIC1F_ICR1                      _IIC1F.Bits.ICR1
#define IIC1F_ICR2                      _IIC1F.Bits.ICR2
#define IIC1F_ICR3                      _IIC1F.Bits.ICR3
#define IIC1F_ICR4                      _IIC1F.Bits.ICR4
#define IIC1F_ICR5                      _IIC1F.Bits.ICR5
#define IIC1F_MULT0                     _IIC1F.Bits.MULT0
#define IIC1F_MULT1                     _IIC1F.Bits.MULT1
#define IIC1F_ICR                       _IIC1F.MergedBits.grpICR
#define IIC1F_MULT                      _IIC1F.MergedBits.grpMULT

#define IIC1F_ICR0_MASK                 1U
#define IIC1F_ICR1_MASK                 2U
#define IIC1F_ICR2_MASK                 4U
#define IIC1F_ICR3_MASK                 8U
#define IIC1F_ICR4_MASK                 16U
#define IIC1F_ICR5_MASK                 32U
#define IIC1F_MULT0_MASK                64U
#define IIC1F_MULT1_MASK                128U
#define IIC1F_ICR_MASK                  63U
#define IIC1F_ICR_BITNUM                0U
#define IIC1F_MULT_MASK                 192U
#define IIC1F_MULT_BITNUM               6U


/*** IIC1C1 - IIC Control Register 1; 0xFFFF805A ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** IIC1C1 - IIC Control Register 1; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte             :1; 
        byte RSTA        :1;                                       /* Repeat START */
        byte TXAK        :1;                                       /* Transmit Acknowledge Enable */
        byte TX          :1;                                       /* Transmit Mode Select */
        byte MST         :1;                                       /* Master Mode Select */
        byte IICIE       :1;                                       /* IIC Interrupt Enable */
        byte IICEN       :1;                                       /* IIC Enable */
      } Bits;
    } IIC1C1STR;
    #define IIC1C1                      _IIC1C1.Byte
    #define IIC1C1_RSTA                 _IIC1C1.SameAddr_STR.IIC1C1STR.Bits.RSTA
    #define IIC1C1_TXAK                 _IIC1C1.SameAddr_STR.IIC1C1STR.Bits.TXAK
    #define IIC1C1_TX                   _IIC1C1.SameAddr_STR.IIC1C1STR.Bits.TX
    #define IIC1C1_MST                  _IIC1C1.SameAddr_STR.IIC1C1STR.Bits.MST
    #define IIC1C1_IICIE                _IIC1C1.SameAddr_STR.IIC1C1STR.Bits.IICIE
    #define IIC1C1_IICEN                _IIC1C1.SameAddr_STR.IIC1C1STR.Bits.IICEN
    
    #define IIC1C1_RSTA_MASK            4U
    #define IIC1C1_TXAK_MASK            8U
    #define IIC1C1_TX_MASK              16U
    #define IIC1C1_MST_MASK             32U
    #define IIC1C1_IICIE_MASK           64U
    #define IIC1C1_IICEN_MASK           128U
    
    /*** IIC1C - IIC Control Register; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte             :1; 
        byte RSTA        :1;                                       /* Repeat START */
        byte TXAK        :1;                                       /* Transmit Acknowledge Enable */
        byte TX          :1;                                       /* Transmit Mode Select */
        byte MST         :1;                                       /* Master Mode Select */
        byte IICIE       :1;                                       /* IIC Interrupt Enable */
        byte IICEN       :1;                                       /* IIC Enable */
      } Bits;
    } IIC1CSTR;
    #define IIC1C                       _IIC1C1.Byte
    #define IIC1C_RSTA                  _IIC1C1.SameAddr_STR.IIC1CSTR.Bits.RSTA
    #define IIC1C_TXAK                  _IIC1C1.SameAddr_STR.IIC1CSTR.Bits.TXAK
    #define IIC1C_TX                    _IIC1C1.SameAddr_STR.IIC1CSTR.Bits.TX
    #define IIC1C_MST                   _IIC1C1.SameAddr_STR.IIC1CSTR.Bits.MST
    #define IIC1C_IICIE                 _IIC1C1.SameAddr_STR.IIC1CSTR.Bits.IICIE
    #define IIC1C_IICEN                 _IIC1C1.SameAddr_STR.IIC1CSTR.Bits.IICEN
    
    #define IIC1C_RSTA_MASK             4U
    #define IIC1C_TXAK_MASK             8U
    #define IIC1C_TX_MASK               16U
    #define IIC1C_MST_MASK              32U
    #define IIC1C_IICIE_MASK            64U
    #define IIC1C_IICEN_MASK            128U
    
  } SameAddr_STR; /*Several registers at the same address */

} IIC1C1STR;
#define _IIC1C1 (*(volatile IIC1C1STR *)0xFFFF805A)


/*** IIC1S - IIC Status Register; 0xFFFF805B ***/
typedef union {
  byte Byte;
  struct {
    byte RXAK        :1;                                       /* Receive Acknowledge */
    byte IICIF       :1;                                       /* IIC Interrupt Flag */
    byte SRW         :1;                                       /* Slave Read/Write */
    byte             :1; 
    byte ARBL        :1;                                       /* Arbitration Lost */
    byte BUSY        :1;                                       /* Bus Busy */
    byte IAAS        :1;                                       /* Addressed as a Slave */
    byte TCF         :1;                                       /* Transfer Complete Flag */
  } Bits;
} IIC1SSTR;
#define _IIC1S (*(volatile IIC1SSTR *)0xFFFF805B)
#define IIC1S                           _IIC1S.Byte
#define IIC1S_RXAK                      _IIC1S.Bits.RXAK
#define IIC1S_IICIF                     _IIC1S.Bits.IICIF
#define IIC1S_SRW                       _IIC1S.Bits.SRW
#define IIC1S_ARBL                      _IIC1S.Bits.ARBL
#define IIC1S_BUSY                      _IIC1S.Bits.BUSY
#define IIC1S_IAAS                      _IIC1S.Bits.IAAS
#define IIC1S_TCF                       _IIC1S.Bits.TCF

#define IIC1S_RXAK_MASK                 1U
#define IIC1S_IICIF_MASK                2U
#define IIC1S_SRW_MASK                  4U
#define IIC1S_ARBL_MASK                 16U
#define IIC1S_BUSY_MASK                 32U
#define IIC1S_IAAS_MASK                 64U
#define IIC1S_TCF_MASK                  128U


/*** IIC1D - IIC Data I/O Register; 0xFFFF805C ***/
typedef union {
  byte Byte;
  struct {
    byte DATA0       :1;                                       /* IIC Data Bit 0 */
    byte DATA1       :1;                                       /* IIC Data Bit 1 */
    byte DATA2       :1;                                       /* IIC Data Bit 2 */
    byte DATA3       :1;                                       /* IIC Data Bit 3 */
    byte DATA4       :1;                                       /* IIC Data Bit 4 */
    byte DATA5       :1;                                       /* IIC Data Bit 5 */
    byte DATA6       :1;                                       /* IIC Data Bit 6 */
    byte DATA7       :1;                                       /* IIC Data Bit 7 */
  } Bits;
} IIC1DSTR;
#define _IIC1D (*(volatile IIC1DSTR *)0xFFFF805C)
#define IIC1D                           _IIC1D.Byte
#define IIC1D_DATA0                     _IIC1D.Bits.DATA0
#define IIC1D_DATA1                     _IIC1D.Bits.DATA1
#define IIC1D_DATA2                     _IIC1D.Bits.DATA2
#define IIC1D_DATA3                     _IIC1D.Bits.DATA3
#define IIC1D_DATA4                     _IIC1D.Bits.DATA4
#define IIC1D_DATA5                     _IIC1D.Bits.DATA5
#define IIC1D_DATA6                     _IIC1D.Bits.DATA6
#define IIC1D_DATA7                     _IIC1D.Bits.DATA7

#define IIC1D_DATA0_MASK                1U
#define IIC1D_DATA1_MASK                2U
#define IIC1D_DATA2_MASK                4U
#define IIC1D_DATA3_MASK                8U
#define IIC1D_DATA4_MASK                16U
#define IIC1D_DATA5_MASK                32U
#define IIC1D_DATA6_MASK                64U
#define IIC1D_DATA7_MASK                128U


/*** IIC1C2 - IIC Control Register 2; 0xFFFF805D ***/
typedef union {
  byte Byte;
  struct {
    byte AD8         :1;                                       /* Slave Address Bit 8 */
    byte AD9         :1;                                       /* Slave Address Bit 9 */
    byte AD10        :1;                                       /* Slave Address Bit 10 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ADEXT       :1;                                       /* Address Extension */
    byte GCAEN       :1;                                       /* General Call Address Enable */
  } Bits;
  struct {
    byte grpAD_8 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} IIC1C2STR;
#define _IIC1C2 (*(volatile IIC1C2STR *)0xFFFF805D)
#define IIC1C2                          _IIC1C2.Byte
#define IIC1C2_AD8                      _IIC1C2.Bits.AD8
#define IIC1C2_AD9                      _IIC1C2.Bits.AD9
#define IIC1C2_AD10                     _IIC1C2.Bits.AD10
#define IIC1C2_ADEXT                    _IIC1C2.Bits.ADEXT
#define IIC1C2_GCAEN                    _IIC1C2.Bits.GCAEN
#define IIC1C2_AD_8                     _IIC1C2.MergedBits.grpAD_8
#define IIC1C2_AD                       IIC1C2_AD_8

#define IIC1C2_AD8_MASK                 1U
#define IIC1C2_AD9_MASK                 2U
#define IIC1C2_AD10_MASK                4U
#define IIC1C2_ADEXT_MASK               64U
#define IIC1C2_GCAEN_MASK               128U
#define IIC1C2_AD_8_MASK                7U
#define IIC1C2_AD_8_BITNUM              0U


/*** TPM2SC - TPM2 Status and Control Register; 0xFFFF8060 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2SCSTR;
#define _TPM2SC (*(volatile TPM2SCSTR *)0xFFFF8060)
#define TPM2SC                          _TPM2SC.Byte
#define TPM2SC_PS0                      _TPM2SC.Bits.PS0
#define TPM2SC_PS1                      _TPM2SC.Bits.PS1
#define TPM2SC_PS2                      _TPM2SC.Bits.PS2
#define TPM2SC_CLKSA                    _TPM2SC.Bits.CLKSA
#define TPM2SC_CLKSB                    _TPM2SC.Bits.CLKSB
#define TPM2SC_CPWMS                    _TPM2SC.Bits.CPWMS
#define TPM2SC_TOIE                     _TPM2SC.Bits.TOIE
#define TPM2SC_TOF                      _TPM2SC.Bits.TOF
#define TPM2SC_PS                       _TPM2SC.MergedBits.grpPS
#define TPM2SC_CLKSx                    _TPM2SC.MergedBits.grpCLKSx

#define TPM2SC_PS0_MASK                 1U
#define TPM2SC_PS1_MASK                 2U
#define TPM2SC_PS2_MASK                 4U
#define TPM2SC_CLKSA_MASK               8U
#define TPM2SC_CLKSB_MASK               16U
#define TPM2SC_CPWMS_MASK               32U
#define TPM2SC_TOIE_MASK                64U
#define TPM2SC_TOF_MASK                 128U
#define TPM2SC_PS_MASK                  7U
#define TPM2SC_PS_BITNUM                0U
#define TPM2SC_CLKSx_MASK               24U
#define TPM2SC_CLKSx_BITNUM             3U


/*** TPM2CNT - TPM2 Timer Counter Register; 0xFFFF8061 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2CNTH - TPM2 Timer Counter Register High; 0xFFFF8061 ***/
    union {
      byte Byte;
    } TPM2CNTHSTR;
    #define TPM2CNTH                    _TPM2CNT.Overlap_STR.TPM2CNTHSTR.Byte
    

    /*** TPM2CNTL - TPM2 Timer Counter Register Low; 0xFFFF8062 ***/
    union {
      byte Byte;
    } TPM2CNTLSTR;
    #define TPM2CNTL                    _TPM2CNT.Overlap_STR.TPM2CNTLSTR.Byte
    
  } Overlap_STR;

} TPM2CNTSTR;
#define _TPM2CNT (*(volatile TPM2CNTSTR *)0xFFFF8061)
#define TPM2CNT                         _TPM2CNT.Word


/*** TPM2MOD - TPM2 Timer Counter Modulo Register; 0xFFFF8063 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2MODH - TPM2 Timer Counter Modulo Register High; 0xFFFF8063 ***/
    union {
      byte Byte;
    } TPM2MODHSTR;
    #define TPM2MODH                    _TPM2MOD.Overlap_STR.TPM2MODHSTR.Byte
    

    /*** TPM2MODL - TPM2 Timer Counter Modulo Register Low; 0xFFFF8064 ***/
    union {
      byte Byte;
    } TPM2MODLSTR;
    #define TPM2MODL                    _TPM2MOD.Overlap_STR.TPM2MODLSTR.Byte
    
  } Overlap_STR;

} TPM2MODSTR;
#define _TPM2MOD (*(volatile TPM2MODSTR *)0xFFFF8063)
#define TPM2MOD                         _TPM2MOD.Word


/*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register; 0xFFFF8065 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2C0SCSTR;
#define _TPM2C0SC (*(volatile TPM2C0SCSTR *)0xFFFF8065)
#define TPM2C0SC                        _TPM2C0SC.Byte
#define TPM2C0SC_ELS0A                  _TPM2C0SC.Bits.ELS0A
#define TPM2C0SC_ELS0B                  _TPM2C0SC.Bits.ELS0B
#define TPM2C0SC_MS0A                   _TPM2C0SC.Bits.MS0A
#define TPM2C0SC_MS0B                   _TPM2C0SC.Bits.MS0B
#define TPM2C0SC_CH0IE                  _TPM2C0SC.Bits.CH0IE
#define TPM2C0SC_CH0F                   _TPM2C0SC.Bits.CH0F
#define TPM2C0SC_ELS0x                  _TPM2C0SC.MergedBits.grpELS0x
#define TPM2C0SC_MS0x                   _TPM2C0SC.MergedBits.grpMS0x

#define TPM2C0SC_ELS0A_MASK             4U
#define TPM2C0SC_ELS0B_MASK             8U
#define TPM2C0SC_MS0A_MASK              16U
#define TPM2C0SC_MS0B_MASK              32U
#define TPM2C0SC_CH0IE_MASK             64U
#define TPM2C0SC_CH0F_MASK              128U
#define TPM2C0SC_ELS0x_MASK             12U
#define TPM2C0SC_ELS0x_BITNUM           2U
#define TPM2C0SC_MS0x_MASK              48U
#define TPM2C0SC_MS0x_BITNUM            4U


/*** TPM2C0V - TPM2 Timer Channel 0 Value Register; 0xFFFF8066 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High; 0xFFFF8066 ***/
    union {
      byte Byte;
    } TPM2C0VHSTR;
    #define TPM2C0VH                    _TPM2C0V.Overlap_STR.TPM2C0VHSTR.Byte
    

    /*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low; 0xFFFF8067 ***/
    union {
      byte Byte;
    } TPM2C0VLSTR;
    #define TPM2C0VL                    _TPM2C0V.Overlap_STR.TPM2C0VLSTR.Byte
    
  } Overlap_STR;

} TPM2C0VSTR;
#define _TPM2C0V (*(volatile TPM2C0VSTR *)0xFFFF8066)
#define TPM2C0V                         _TPM2C0V.Word


/*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register; 0xFFFF8068 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for TPM Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for TPM Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2C1SCSTR;
#define _TPM2C1SC (*(volatile TPM2C1SCSTR *)0xFFFF8068)
#define TPM2C1SC                        _TPM2C1SC.Byte
#define TPM2C1SC_ELS1A                  _TPM2C1SC.Bits.ELS1A
#define TPM2C1SC_ELS1B                  _TPM2C1SC.Bits.ELS1B
#define TPM2C1SC_MS1A                   _TPM2C1SC.Bits.MS1A
#define TPM2C1SC_MS1B                   _TPM2C1SC.Bits.MS1B
#define TPM2C1SC_CH1IE                  _TPM2C1SC.Bits.CH1IE
#define TPM2C1SC_CH1F                   _TPM2C1SC.Bits.CH1F
#define TPM2C1SC_ELS1x                  _TPM2C1SC.MergedBits.grpELS1x
#define TPM2C1SC_MS1x                   _TPM2C1SC.MergedBits.grpMS1x

#define TPM2C1SC_ELS1A_MASK             4U
#define TPM2C1SC_ELS1B_MASK             8U
#define TPM2C1SC_MS1A_MASK              16U
#define TPM2C1SC_MS1B_MASK              32U
#define TPM2C1SC_CH1IE_MASK             64U
#define TPM2C1SC_CH1F_MASK              128U
#define TPM2C1SC_ELS1x_MASK             12U
#define TPM2C1SC_ELS1x_BITNUM           2U
#define TPM2C1SC_MS1x_MASK              48U
#define TPM2C1SC_MS1x_BITNUM            4U


/*** TPM2C1V - TPM2 Timer Channel 1 Value Register; 0xFFFF8069 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High; 0xFFFF8069 ***/
    union {
      byte Byte;
    } TPM2C1VHSTR;
    #define TPM2C1VH                    _TPM2C1V.Overlap_STR.TPM2C1VHSTR.Byte
    

    /*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low; 0xFFFF806A ***/
    union {
      byte Byte;
    } TPM2C1VLSTR;
    #define TPM2C1VL                    _TPM2C1V.Overlap_STR.TPM2C1VLSTR.Byte
    
  } Overlap_STR;

} TPM2C1VSTR;
#define _TPM2C1V (*(volatile TPM2C1VSTR *)0xFFFF8069)
#define TPM2C1V                         _TPM2C1V.Word


/*** RTCSC - RTC Status and Control Register; 0xFFFF806C ***/
typedef union {
  byte Byte;
  struct {
    byte RTCPS0      :1;                                       /* Real-Time Clock Prescaler Select, bit 0 */
    byte RTCPS1      :1;                                       /* Real-Time Clock Prescaler Select, bit 1 */
    byte RTCPS2      :1;                                       /* Real-Time Clock Prescaler Select, bit 2 */
    byte RTCPS3      :1;                                       /* Real-Time Clock Prescaler Select, bit 3 */
    byte RTIE        :1;                                       /* Real-Time Interrupt Enable */
    byte RTCLKS0     :1;                                       /* Real-Time Clock Source Select, bit 0 */
    byte RTCLKS1     :1;                                       /* Real-Time Clock Source Select, bit 1 */
    byte RTIF        :1;                                       /* Real-Time Interrupt Flag */
  } Bits;
  struct {
    byte grpRTCPS :4;
    byte         :1;
    byte grpRTCLKS :2;
    byte         :1;
  } MergedBits;
} RTCSCSTR;
#define _RTCSC (*(volatile RTCSCSTR *)0xFFFF806C)
#define RTCSC                           _RTCSC.Byte
#define RTCSC_RTCPS0                    _RTCSC.Bits.RTCPS0
#define RTCSC_RTCPS1                    _RTCSC.Bits.RTCPS1
#define RTCSC_RTCPS2                    _RTCSC.Bits.RTCPS2
#define RTCSC_RTCPS3                    _RTCSC.Bits.RTCPS3
#define RTCSC_RTIE                      _RTCSC.Bits.RTIE
#define RTCSC_RTCLKS0                   _RTCSC.Bits.RTCLKS0
#define RTCSC_RTCLKS1                   _RTCSC.Bits.RTCLKS1
#define RTCSC_RTIF                      _RTCSC.Bits.RTIF
#define RTCSC_RTCPS                     _RTCSC.MergedBits.grpRTCPS
#define RTCSC_RTCLKS                    _RTCSC.MergedBits.grpRTCLKS

#define RTCSC_RTCPS0_MASK               1U
#define RTCSC_RTCPS1_MASK               2U
#define RTCSC_RTCPS2_MASK               4U
#define RTCSC_RTCPS3_MASK               8U
#define RTCSC_RTIE_MASK                 16U
#define RTCSC_RTCLKS0_MASK              32U
#define RTCSC_RTCLKS1_MASK              64U
#define RTCSC_RTIF_MASK                 128U
#define RTCSC_RTCPS_MASK                15U
#define RTCSC_RTCPS_BITNUM              0U
#define RTCSC_RTCLKS_MASK               96U
#define RTCSC_RTCLKS_BITNUM             5U


/*** RTCCNT - RTC Counter Register; 0xFFFF806D ***/
typedef union {
  byte Byte;
} RTCCNTSTR;
#define _RTCCNT (*(volatile RTCCNTSTR *)0xFFFF806D)
#define RTCCNT                          _RTCCNT.Byte


/*** RTCMOD - RTC Modulo Register; 0xFFFF806E ***/
typedef union {
  byte Byte;
} RTCMODSTR;
#define _RTCMOD (*(volatile RTCMODSTR *)0xFFFF806E)
#define RTCMOD                          _RTCMOD.Byte


/*** SPI2C1 - SPI2 Control Register 1; 0xFFFF8070 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* LSB First (Shifter Direction) */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* Clock Phase */
    byte CPOL        :1;                                       /* Clock Polarity */
    byte MSTR        :1;                                       /* Master/Slave Mode Select */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable */
    byte SPIE        :1;                                       /* SPI Interrupt Enable (for SPRF and MODF) */
  } Bits;
} SPI2C1STR;
#define _SPI2C1 (*(volatile SPI2C1STR *)0xFFFF8070)
#define SPI2C1                          _SPI2C1.Byte
#define SPI2C1_LSBFE                    _SPI2C1.Bits.LSBFE
#define SPI2C1_SSOE                     _SPI2C1.Bits.SSOE
#define SPI2C1_CPHA                     _SPI2C1.Bits.CPHA
#define SPI2C1_CPOL                     _SPI2C1.Bits.CPOL
#define SPI2C1_MSTR                     _SPI2C1.Bits.MSTR
#define SPI2C1_SPTIE                    _SPI2C1.Bits.SPTIE
#define SPI2C1_SPE                      _SPI2C1.Bits.SPE
#define SPI2C1_SPIE                     _SPI2C1.Bits.SPIE

#define SPI2C1_LSBFE_MASK               1U
#define SPI2C1_SSOE_MASK                2U
#define SPI2C1_CPHA_MASK                4U
#define SPI2C1_CPOL_MASK                8U
#define SPI2C1_MSTR_MASK                16U
#define SPI2C1_SPTIE_MASK               32U
#define SPI2C1_SPE_MASK                 64U
#define SPI2C1_SPIE_MASK                128U


/*** SPI2C2 - SPI2 Control Register 2; 0xFFFF8071 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI Pin Control 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional Mode Output Enable */
    byte MODFEN      :1;                                       /* Master Mode-Fault Function Enable */
    byte             :1; 
    byte SPIMODE     :1;                                       /* SPI 8- or 16-bit Mode Select */
    byte SPMIE       :1;                                       /* SPI Match Interrupt Enable */
  } Bits;
} SPI2C2STR;
#define _SPI2C2 (*(volatile SPI2C2STR *)0xFFFF8071)
#define SPI2C2                          _SPI2C2.Byte
#define SPI2C2_SPC0                     _SPI2C2.Bits.SPC0
#define SPI2C2_SPISWAI                  _SPI2C2.Bits.SPISWAI
#define SPI2C2_BIDIROE                  _SPI2C2.Bits.BIDIROE
#define SPI2C2_MODFEN                   _SPI2C2.Bits.MODFEN
#define SPI2C2_SPIMODE                  _SPI2C2.Bits.SPIMODE
#define SPI2C2_SPMIE                    _SPI2C2.Bits.SPMIE

#define SPI2C2_SPC0_MASK                1U
#define SPI2C2_SPISWAI_MASK             2U
#define SPI2C2_BIDIROE_MASK             8U
#define SPI2C2_MODFEN_MASK              16U
#define SPI2C2_SPIMODE_MASK             64U
#define SPI2C2_SPMIE_MASK               128U


/*** SPI2BR - SPI2 Baud Rate Register; 0xFFFF8072 ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Divisor Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Divisor Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Divisor Bit 2 */
    byte             :1; 
    byte SPPR0       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPI2BRSTR;
#define _SPI2BR (*(volatile SPI2BRSTR *)0xFFFF8072)
#define SPI2BR                          _SPI2BR.Byte
#define SPI2BR_SPR0                     _SPI2BR.Bits.SPR0
#define SPI2BR_SPR1                     _SPI2BR.Bits.SPR1
#define SPI2BR_SPR2                     _SPI2BR.Bits.SPR2
#define SPI2BR_SPPR0                    _SPI2BR.Bits.SPPR0
#define SPI2BR_SPPR1                    _SPI2BR.Bits.SPPR1
#define SPI2BR_SPPR2                    _SPI2BR.Bits.SPPR2
#define SPI2BR_SPR                      _SPI2BR.MergedBits.grpSPR
#define SPI2BR_SPPR                     _SPI2BR.MergedBits.grpSPPR

#define SPI2BR_SPR0_MASK                1U
#define SPI2BR_SPR1_MASK                2U
#define SPI2BR_SPR2_MASK                4U
#define SPI2BR_SPPR0_MASK               16U
#define SPI2BR_SPPR1_MASK               32U
#define SPI2BR_SPPR2_MASK               64U
#define SPI2BR_SPR_MASK                 7U
#define SPI2BR_SPR_BITNUM               0U
#define SPI2BR_SPPR_MASK                112U
#define SPI2BR_SPPR_BITNUM              4U


/*** SPI2S - SPI2 Status Register; 0xFFFF8073 ***/
typedef union {
  byte Byte;
  struct {
    byte RFIFOEF     :1;                                       /* SPI Read FIFO Empty Flag */
    byte TXFULLF     :1;                                       /* SPI Transmit FIFO Full Flag */
    byte TNEAREF     :1;                                       /* SPI Transmit FIFO Nearly Empty Flag */
    byte RNFULLF     :1;                                       /* SPI Receive FIFO Nearly Full Flag */
    byte MODF        :1;                                       /* Master Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Buffer Empty Flag */
    byte SPMF        :1;                                       /* SPI Match Flag */
    byte SPRF        :1;                                       /* SPI Read Buffer Full Flag */
  } Bits;
} SPI2SSTR;
#define _SPI2S (*(volatile SPI2SSTR *)0xFFFF8073)
#define SPI2S                           _SPI2S.Byte
#define SPI2S_RFIFOEF                   _SPI2S.Bits.RFIFOEF
#define SPI2S_TXFULLF                   _SPI2S.Bits.TXFULLF
#define SPI2S_TNEAREF                   _SPI2S.Bits.TNEAREF
#define SPI2S_RNFULLF                   _SPI2S.Bits.RNFULLF
#define SPI2S_MODF                      _SPI2S.Bits.MODF
#define SPI2S_SPTEF                     _SPI2S.Bits.SPTEF
#define SPI2S_SPMF                      _SPI2S.Bits.SPMF
#define SPI2S_SPRF                      _SPI2S.Bits.SPRF

#define SPI2S_RFIFOEF_MASK              1U
#define SPI2S_TXFULLF_MASK              2U
#define SPI2S_TNEAREF_MASK              4U
#define SPI2S_RNFULLF_MASK              8U
#define SPI2S_MODF_MASK                 16U
#define SPI2S_SPTEF_MASK                32U
#define SPI2S_SPMF_MASK                 64U
#define SPI2S_SPRF_MASK                 128U


/*** SPI2D16 - SPI2 Data Register; 0xFFFF8074 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPI2DH - SPI2 Data Register High; 0xFFFF8074 ***/
    union {
      byte Byte;
    } SPI2DHSTR;
    #define SPI2DH                      _SPI2D16.Overlap_STR.SPI2DHSTR.Byte
    

    /*** SPI2DL - SPI2 Data Register Low; 0xFFFF8075 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SPI2DL - SPI2 Data Register Low; Several registers at the same address ***/
        #define SPI2DL                  _SPI2D16.Overlap_STR.SPI2DLSTR.Byte
        
        /*** SPI2D - SPI2 Data Register Low; Several registers at the same address ***/
        union {
          struct {
            byte Bit0        :1;                                       /* SPI Data Bit 0 */
            byte Bit1        :1;                                       /* SPI Data Bit 1 */
            byte Bit2        :1;                                       /* SPI Data Bit 2 */
            byte Bit3        :1;                                       /* SPI Data Bit 3 */
            byte Bit4        :1;                                       /* SPI Data Bit 4 */
            byte Bit5        :1;                                       /* SPI Data Bit 5 */
            byte Bit6        :1;                                       /* SPI Data Bit 6 */
            byte Bit7        :1;                                       /* SPI Data Bit 7 */
          } Bits;
        } SPI2DSTR;
        #define SPI2D                   _SPI2D16.Overlap_STR.SPI2DLSTR.Byte
        #define SPI2D_Bit0              _SPI2D16.Overlap_STR.SPI2DLSTR.SameAddr_STR.SPI2DSTR.Bits.Bit0
        #define SPI2D_Bit1              _SPI2D16.Overlap_STR.SPI2DLSTR.SameAddr_STR.SPI2DSTR.Bits.Bit1
        #define SPI2D_Bit2              _SPI2D16.Overlap_STR.SPI2DLSTR.SameAddr_STR.SPI2DSTR.Bits.Bit2
        #define SPI2D_Bit3              _SPI2D16.Overlap_STR.SPI2DLSTR.SameAddr_STR.SPI2DSTR.Bits.Bit3
        #define SPI2D_Bit4              _SPI2D16.Overlap_STR.SPI2DLSTR.SameAddr_STR.SPI2DSTR.Bits.Bit4
        #define SPI2D_Bit5              _SPI2D16.Overlap_STR.SPI2DLSTR.SameAddr_STR.SPI2DSTR.Bits.Bit5
        #define SPI2D_Bit6              _SPI2D16.Overlap_STR.SPI2DLSTR.SameAddr_STR.SPI2DSTR.Bits.Bit6
        #define SPI2D_Bit7              _SPI2D16.Overlap_STR.SPI2DLSTR.SameAddr_STR.SPI2DSTR.Bits.Bit7
        
        #define SPI2D_Bit0_MASK         1U
        #define SPI2D_Bit1_MASK         2U
        #define SPI2D_Bit2_MASK         4U
        #define SPI2D_Bit3_MASK         8U
        #define SPI2D_Bit4_MASK         16U
        #define SPI2D_Bit5_MASK         32U
        #define SPI2D_Bit6_MASK         64U
        #define SPI2D_Bit7_MASK         128U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SPI2DLSTR;
    
  } Overlap_STR;

} SPI2D16STR;
#define _SPI2D16 (*(volatile SPI2D16STR *)0xFFFF8074)
#define SPI2D16                         _SPI2D16.Word


/*** SPI2M - SPI2 Match Register; 0xFFFF8076 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPI2MH - SPI2 Match Register High; 0xFFFF8076 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* SPI Match Value Bit 8 */
        byte Bit9        :1;                                       /* SPI Match Value Bit 9 */
        byte Bit10       :1;                                       /* SPI Match Value Bit 10 */
        byte Bit11       :1;                                       /* SPI Match Value Bit 11 */
        byte Bit12       :1;                                       /* SPI Match Value Bit 12 */
        byte Bit13       :1;                                       /* SPI Match Value Bit 13 */
        byte Bit14       :1;                                       /* SPI Match Value Bit 14 */
        byte Bit15       :1;                                       /* SPI Match Value Bit 15 */
      } Bits;
    } SPI2MHSTR;
    #define SPI2MH                      _SPI2M.Overlap_STR.SPI2MHSTR.Byte
    #define SPI2MH_Bit8                 _SPI2M.Overlap_STR.SPI2MHSTR.Bits.Bit8
    #define SPI2MH_Bit9                 _SPI2M.Overlap_STR.SPI2MHSTR.Bits.Bit9
    #define SPI2MH_Bit10                _SPI2M.Overlap_STR.SPI2MHSTR.Bits.Bit10
    #define SPI2MH_Bit11                _SPI2M.Overlap_STR.SPI2MHSTR.Bits.Bit11
    #define SPI2MH_Bit12                _SPI2M.Overlap_STR.SPI2MHSTR.Bits.Bit12
    #define SPI2MH_Bit13                _SPI2M.Overlap_STR.SPI2MHSTR.Bits.Bit13
    #define SPI2MH_Bit14                _SPI2M.Overlap_STR.SPI2MHSTR.Bits.Bit14
    #define SPI2MH_Bit15                _SPI2M.Overlap_STR.SPI2MHSTR.Bits.Bit15
    
    #define SPI2MH_Bit8_MASK            1U
    #define SPI2MH_Bit9_MASK            2U
    #define SPI2MH_Bit10_MASK           4U
    #define SPI2MH_Bit11_MASK           8U
    #define SPI2MH_Bit12_MASK           16U
    #define SPI2MH_Bit13_MASK           32U
    #define SPI2MH_Bit14_MASK           64U
    #define SPI2MH_Bit15_MASK           128U
    

    /*** SPI2ML - SPI2 Match Register Low; 0xFFFF8077 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* SPI Match Value Bit 0 */
        byte Bit1        :1;                                       /* SPI Match Value Bit 1 */
        byte Bit2        :1;                                       /* SPI Match Value Bit 2 */
        byte Bit3        :1;                                       /* SPI Match Value Bit 3 */
        byte Bit4        :1;                                       /* SPI Match Value Bit 4 */
        byte Bit5        :1;                                       /* SPI Match Value Bit 5 */
        byte Bit6        :1;                                       /* SPI Match Value Bit 6 */
        byte Bit7        :1;                                       /* SPI Match Value Bit 7 */
      } Bits;
    } SPI2MLSTR;
    #define SPI2ML                      _SPI2M.Overlap_STR.SPI2MLSTR.Byte
    #define SPI2ML_Bit0                 _SPI2M.Overlap_STR.SPI2MLSTR.Bits.Bit0
    #define SPI2ML_Bit1                 _SPI2M.Overlap_STR.SPI2MLSTR.Bits.Bit1
    #define SPI2ML_Bit2                 _SPI2M.Overlap_STR.SPI2MLSTR.Bits.Bit2
    #define SPI2ML_Bit3                 _SPI2M.Overlap_STR.SPI2MLSTR.Bits.Bit3
    #define SPI2ML_Bit4                 _SPI2M.Overlap_STR.SPI2MLSTR.Bits.Bit4
    #define SPI2ML_Bit5                 _SPI2M.Overlap_STR.SPI2MLSTR.Bits.Bit5
    #define SPI2ML_Bit6                 _SPI2M.Overlap_STR.SPI2MLSTR.Bits.Bit6
    #define SPI2ML_Bit7                 _SPI2M.Overlap_STR.SPI2MLSTR.Bits.Bit7
    
    #define SPI2ML_Bit0_MASK            1U
    #define SPI2ML_Bit1_MASK            2U
    #define SPI2ML_Bit2_MASK            4U
    #define SPI2ML_Bit3_MASK            8U
    #define SPI2ML_Bit4_MASK            16U
    #define SPI2ML_Bit5_MASK            32U
    #define SPI2ML_Bit6_MASK            64U
    #define SPI2ML_Bit7_MASK            128U
    
  } Overlap_STR;

  struct {
    word Bit0        :1;                                       /* SPI Match Value Bit 0 */
    word Bit1        :1;                                       /* SPI Match Value Bit 1 */
    word Bit2        :1;                                       /* SPI Match Value Bit 2 */
    word Bit3        :1;                                       /* SPI Match Value Bit 3 */
    word Bit4        :1;                                       /* SPI Match Value Bit 4 */
    word Bit5        :1;                                       /* SPI Match Value Bit 5 */
    word Bit6        :1;                                       /* SPI Match Value Bit 6 */
    word Bit7        :1;                                       /* SPI Match Value Bit 7 */
    word Bit8        :1;                                       /* SPI Match Value Bit 8 */
    word Bit9        :1;                                       /* SPI Match Value Bit 9 */
    word Bit10       :1;                                       /* SPI Match Value Bit 10 */
    word Bit11       :1;                                       /* SPI Match Value Bit 11 */
    word Bit12       :1;                                       /* SPI Match Value Bit 12 */
    word Bit13       :1;                                       /* SPI Match Value Bit 13 */
    word Bit14       :1;                                       /* SPI Match Value Bit 14 */
    word Bit15       :1;                                       /* SPI Match Value Bit 15 */
  } Bits;
} SPI2MSTR;
#define _SPI2M (*(volatile SPI2MSTR *)0xFFFF8076)
#define SPI2M                           _SPI2M.Word
#define SPI2M_Bit0                      _SPI2M.Bits.Bit0
#define SPI2M_Bit1                      _SPI2M.Bits.Bit1
#define SPI2M_Bit2                      _SPI2M.Bits.Bit2
#define SPI2M_Bit3                      _SPI2M.Bits.Bit3
#define SPI2M_Bit4                      _SPI2M.Bits.Bit4
#define SPI2M_Bit5                      _SPI2M.Bits.Bit5
#define SPI2M_Bit6                      _SPI2M.Bits.Bit6
#define SPI2M_Bit7                      _SPI2M.Bits.Bit7
#define SPI2M_Bit8                      _SPI2M.Bits.Bit8
#define SPI2M_Bit9                      _SPI2M.Bits.Bit9
#define SPI2M_Bit10                     _SPI2M.Bits.Bit10
#define SPI2M_Bit11                     _SPI2M.Bits.Bit11
#define SPI2M_Bit12                     _SPI2M.Bits.Bit12
#define SPI2M_Bit13                     _SPI2M.Bits.Bit13
#define SPI2M_Bit14                     _SPI2M.Bits.Bit14
#define SPI2M_Bit15                     _SPI2M.Bits.Bit15

#define SPI2M_Bit0_MASK                 1U
#define SPI2M_Bit1_MASK                 2U
#define SPI2M_Bit2_MASK                 4U
#define SPI2M_Bit3_MASK                 8U
#define SPI2M_Bit4_MASK                 16U
#define SPI2M_Bit5_MASK                 32U
#define SPI2M_Bit6_MASK                 64U
#define SPI2M_Bit7_MASK                 128U
#define SPI2M_Bit8_MASK                 256U
#define SPI2M_Bit9_MASK                 512U
#define SPI2M_Bit10_MASK                1024U
#define SPI2M_Bit11_MASK                2048U
#define SPI2M_Bit12_MASK                4096U
#define SPI2M_Bit13_MASK                8192U
#define SPI2M_Bit14_MASK                16384U
#define SPI2M_Bit15_MASK                32768U


/*** SPI2C3 - SPI2 Control Register 3; 0xFFFF8078 ***/
typedef union {
  byte Byte;
  struct {
    byte FIFOMODE    :1;                                       /* SPI FIFO Mode Enable */
    byte RNFULLIEN   :1;                                       /* Receive FIFO Nearly Full Interrupt Enable. This is an additional interrupt on the SPI and will only interrupt the CPU if SPIE in the SPIxC1 register is also set. This bit is ignored and has no function if FIFOMODE=0 */
    byte TNEARIEN    :1;                                       /* Transmit FIFO Nearly Empty Interrupt Enable. This is an additional interrupt on the SPI and will only interrupt the CPU if SPTIE in the <br/>SPIxC1 register is also set. This bit is ignored and has no function if FIFOMODE=0 */
    byte             :1; 
    byte RNFULLF_MARK :1;                                      /* Receive FIFO Nearly Full Water Mark - This bit selects the mark for which RNFULLF flag is asserted */
    byte TNEAREF_MARK :1;                                      /* Transmit FIFO Nearly Empty Water Mark - This bit selects the mark after which TNEAREF flag is asserted */
    byte             :1; 
    byte             :1; 
  } Bits;
} SPI2C3STR;
#define _SPI2C3 (*(volatile SPI2C3STR *)0xFFFF8078)
#define SPI2C3                          _SPI2C3.Byte
#define SPI2C3_FIFOMODE                 _SPI2C3.Bits.FIFOMODE
#define SPI2C3_RNFULLIEN                _SPI2C3.Bits.RNFULLIEN
#define SPI2C3_TNEARIEN                 _SPI2C3.Bits.TNEARIEN
#define SPI2C3_RNFULLF_MARK             _SPI2C3.Bits.RNFULLF_MARK
#define SPI2C3_TNEAREF_MARK             _SPI2C3.Bits.TNEAREF_MARK

#define SPI2C3_FIFOMODE_MASK            1U
#define SPI2C3_RNFULLIEN_MASK           2U
#define SPI2C3_TNEARIEN_MASK            4U
#define SPI2C3_RNFULLF_MARK_MASK        16U
#define SPI2C3_TNEAREF_MARK_MASK        32U


/*** SRS - System Reset Status Register; 0xFFFF9800 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LVD         :1;                                       /* Low Voltage Detect */
    byte LOC         :1;                                       /* Loss-of-Clock Reset */
    byte ILAD        :1;                                       /* Illegal Address */
    byte ILOP        :1;                                       /* Illegal Opcode */
    byte COP         :1;                                       /* Computer Operating Properly (COP) Watchdog */
    byte PIN         :1;                                       /* External Reset Pin */
    byte POR         :1;                                       /* Power-On Reset */
  } Bits;
} SRSSTR;
#define _SRS (*(volatile SRSSTR *)0xFFFF9800)
#define SRS                             _SRS.Byte
#define SRS_LVD                         _SRS.Bits.LVD
#define SRS_LOC                         _SRS.Bits.LOC
#define SRS_ILAD                        _SRS.Bits.ILAD
#define SRS_ILOP                        _SRS.Bits.ILOP
#define SRS_COP                         _SRS.Bits.COP
#define SRS_PIN                         _SRS.Bits.PIN
#define SRS_POR                         _SRS.Bits.POR

#define SRS_LVD_MASK                    2U
#define SRS_LOC_MASK                    4U
#define SRS_ILAD_MASK                   8U
#define SRS_ILOP_MASK                   16U
#define SRS_COP_MASK                    32U
#define SRS_PIN_MASK                    64U
#define SRS_POR_MASK                    128U


/*** SOPT1 - System Options Register 1; 0xFFFF9802 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte WAITE       :1;                                       /* WAIT Mode Enable */
    byte STOPE       :1;                                       /* Stop Mode Enable */
    byte COPT0       :1;                                       /* COP Watchdog Timeout, bit 0 */
    byte COPT1       :1;                                       /* COP Watchdog Timeout, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpCOPT :2;
  } MergedBits;
} SOPT1STR;
#define _SOPT1 (*(volatile SOPT1STR *)0xFFFF9802)
#define SOPT1                           _SOPT1.Byte
#define SOPT1_WAITE                     _SOPT1.Bits.WAITE
#define SOPT1_STOPE                     _SOPT1.Bits.STOPE
#define SOPT1_COPT0                     _SOPT1.Bits.COPT0
#define SOPT1_COPT1                     _SOPT1.Bits.COPT1
#define SOPT1_COPT                      _SOPT1.MergedBits.grpCOPT

#define SOPT1_WAITE_MASK                16U
#define SOPT1_STOPE_MASK                32U
#define SOPT1_COPT0_MASK                64U
#define SOPT1_COPT1_MASK                128U
#define SOPT1_COPT_MASK                 192U
#define SOPT1_COPT_BITNUM               6U


/*** SOPT2 - System Options Register 2; 0xFFFF9803 ***/
typedef union {
  byte Byte;
  struct {
    byte ACIC        :1;                                       /* Analog Comparator to Input Capture Enable */
    byte SPI2FE      :1;                                       /* SPI2 Ports Input Filter Enable */
    byte SPI1FE      :1;                                       /* SPI1 Ports Input Filter Enable */
    byte CMT_CLK_SEL :1;                                       /* CMT Clock Select */
    byte CLKOUT_EN   :1;                                       /* Clock Output Enable */
    byte USB_BIGEND  :1;                                       /* USB Big Endian */
    byte COPW        :1;                                       /* COP Window */
    byte COPCLKS     :1;                                       /* COP Watchdog Clock Select */
  } Bits;
} SOPT2STR;
#define _SOPT2 (*(volatile SOPT2STR *)0xFFFF9803)
#define SOPT2                           _SOPT2.Byte
#define SOPT2_ACIC                      _SOPT2.Bits.ACIC
#define SOPT2_SPI2FE                    _SOPT2.Bits.SPI2FE
#define SOPT2_SPI1FE                    _SOPT2.Bits.SPI1FE
#define SOPT2_CMT_CLK_SEL               _SOPT2.Bits.CMT_CLK_SEL
#define SOPT2_CLKOUT_EN                 _SOPT2.Bits.CLKOUT_EN
#define SOPT2_USB_BIGEND                _SOPT2.Bits.USB_BIGEND
#define SOPT2_COPW                      _SOPT2.Bits.COPW
#define SOPT2_COPCLKS                   _SOPT2.Bits.COPCLKS

#define SOPT2_ACIC_MASK                 1U
#define SOPT2_SPI2FE_MASK               2U
#define SOPT2_SPI1FE_MASK               4U
#define SOPT2_CMT_CLK_SEL_MASK          8U
#define SOPT2_CLKOUT_EN_MASK            16U
#define SOPT2_USB_BIGEND_MASK           32U
#define SOPT2_COPW_MASK                 64U
#define SOPT2_COPCLKS_MASK              128U


/*** SDID - System Device Identification Register; 0xFFFF9806 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SDIDH - System Device Identification Register High; 0xFFFF9806 ***/
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       /* Part Identification Number, bit 8 */
        byte ID9         :1;                                       /* Part Identification Number, bit 9 */
        byte ID10        :1;                                       /* Part Identification Number, bit 10 */
        byte ID11        :1;                                       /* Part Identification Number, bit 11 */
        byte REV0        :1;                                       /* Revision number bit 0 */
        byte REV1        :1;                                       /* Revision number bit 1 */
        byte REV2        :1;                                       /* Revision number bit 2 */
        byte REV3        :1;                                       /* Revision number bit 3 */
      } Bits;
      struct {
        byte grpID_8 :4;
        byte grpREV :4;
      } MergedBits;
    } SDIDHSTR;
    #define SDIDH                       _SDID.Overlap_STR.SDIDHSTR.Byte
    #define SDIDH_ID8                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID8
    #define SDIDH_ID9                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID9
    #define SDIDH_ID10                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID10
    #define SDIDH_ID11                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID11
    #define SDIDH_REV0                  _SDID.Overlap_STR.SDIDHSTR.Bits.REV0
    #define SDIDH_REV1                  _SDID.Overlap_STR.SDIDHSTR.Bits.REV1
    #define SDIDH_REV2                  _SDID.Overlap_STR.SDIDHSTR.Bits.REV2
    #define SDIDH_REV3                  _SDID.Overlap_STR.SDIDHSTR.Bits.REV3
    #define SDIDH_ID_8                  _SDID.Overlap_STR.SDIDHSTR.MergedBits.grpID_8
    #define SDIDH_REV                   _SDID.Overlap_STR.SDIDHSTR.MergedBits.grpREV
    #define SDIDH_ID                    SDIDH_ID_8
    
    #define SDIDH_ID8_MASK              1U
    #define SDIDH_ID9_MASK              2U
    #define SDIDH_ID10_MASK             4U
    #define SDIDH_ID11_MASK             8U
    #define SDIDH_REV0_MASK             16U
    #define SDIDH_REV1_MASK             32U
    #define SDIDH_REV2_MASK             64U
    #define SDIDH_REV3_MASK             128U
    #define SDIDH_ID_8_MASK             15U
    #define SDIDH_ID_8_BITNUM           0U
    #define SDIDH_REV_MASK              240U
    #define SDIDH_REV_BITNUM            4U
    

    /*** SDIDL - System Device Identification Register Low; 0xFFFF9807 ***/
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       /* Part Identification Number, bit 0 */
        byte ID1         :1;                                       /* Part Identification Number, bit 1 */
        byte ID2         :1;                                       /* Part Identification Number, bit 2 */
        byte ID3         :1;                                       /* Part Identification Number, bit 3 */
        byte ID4         :1;                                       /* Part Identification Number, bit 4 */
        byte ID5         :1;                                       /* Part Identification Number, bit 5 */
        byte ID6         :1;                                       /* Part Identification Number, bit 6 */
        byte ID7         :1;                                       /* Part Identification Number, bit 7 */
      } Bits;
    } SDIDLSTR;
    #define SDIDL                       _SDID.Overlap_STR.SDIDLSTR.Byte
    #define SDIDL_ID0                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID0
    #define SDIDL_ID1                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID1
    #define SDIDL_ID2                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID2
    #define SDIDL_ID3                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID3
    #define SDIDL_ID4                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID4
    #define SDIDL_ID5                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID5
    #define SDIDL_ID6                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID6
    #define SDIDL_ID7                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID7
    
    #define SDIDL_ID0_MASK              1U
    #define SDIDL_ID1_MASK              2U
    #define SDIDL_ID2_MASK              4U
    #define SDIDL_ID3_MASK              8U
    #define SDIDL_ID4_MASK              16U
    #define SDIDL_ID5_MASK              32U
    #define SDIDL_ID6_MASK              64U
    #define SDIDL_ID7_MASK              128U
    
  } Overlap_STR;

  struct {
    word ID0         :1;                                       /* Part Identification Number, bit 0 */
    word ID1         :1;                                       /* Part Identification Number, bit 1 */
    word ID2         :1;                                       /* Part Identification Number, bit 2 */
    word ID3         :1;                                       /* Part Identification Number, bit 3 */
    word ID4         :1;                                       /* Part Identification Number, bit 4 */
    word ID5         :1;                                       /* Part Identification Number, bit 5 */
    word ID6         :1;                                       /* Part Identification Number, bit 6 */
    word ID7         :1;                                       /* Part Identification Number, bit 7 */
    word ID8         :1;                                       /* Part Identification Number, bit 8 */
    word ID9         :1;                                       /* Part Identification Number, bit 9 */
    word ID10        :1;                                       /* Part Identification Number, bit 10 */
    word ID11        :1;                                       /* Part Identification Number, bit 11 */
    word REV0        :1;                                       /* Revision number bit 0 */
    word REV1        :1;                                       /* Revision number bit 1 */
    word REV2        :1;                                       /* Revision number bit 2 */
    word REV3        :1;                                       /* Revision number bit 3 */
  } Bits;
  struct {
    word grpID   :12;
    word grpREV  :4;
  } MergedBits;
} SDIDSTR;
#define _SDID (*(volatile SDIDSTR *)0xFFFF9806)
#define SDID                            _SDID.Word
#define SDID_ID0                        _SDID.Bits.ID0
#define SDID_ID1                        _SDID.Bits.ID1
#define SDID_ID2                        _SDID.Bits.ID2
#define SDID_ID3                        _SDID.Bits.ID3
#define SDID_ID4                        _SDID.Bits.ID4
#define SDID_ID5                        _SDID.Bits.ID5
#define SDID_ID6                        _SDID.Bits.ID6
#define SDID_ID7                        _SDID.Bits.ID7
#define SDID_ID8                        _SDID.Bits.ID8
#define SDID_ID9                        _SDID.Bits.ID9
#define SDID_ID10                       _SDID.Bits.ID10
#define SDID_ID11                       _SDID.Bits.ID11
#define SDID_REV0                       _SDID.Bits.REV0
#define SDID_REV1                       _SDID.Bits.REV1
#define SDID_REV2                       _SDID.Bits.REV2
#define SDID_REV3                       _SDID.Bits.REV3
#define SDID_ID                         _SDID.MergedBits.grpID
#define SDID_REV                        _SDID.MergedBits.grpREV

#define SDID_ID0_MASK                   1U
#define SDID_ID1_MASK                   2U
#define SDID_ID2_MASK                   4U
#define SDID_ID3_MASK                   8U
#define SDID_ID4_MASK                   16U
#define SDID_ID5_MASK                   32U
#define SDID_ID6_MASK                   64U
#define SDID_ID7_MASK                   128U
#define SDID_ID8_MASK                   256U
#define SDID_ID9_MASK                   512U
#define SDID_ID10_MASK                  1024U
#define SDID_ID11_MASK                  2048U
#define SDID_REV0_MASK                  4096U
#define SDID_REV1_MASK                  8192U
#define SDID_REV2_MASK                  16384U
#define SDID_REV3_MASK                  32768U
#define SDID_ID_MASK                    4095U
#define SDID_ID_BITNUM                  0U
#define SDID_REV_MASK                   61440U
#define SDID_REV_BITNUM                 12U


/*** SPMSC1 - System Power Management Status and Control 1 Register; 0xFFFF9809 ***/
typedef union {
  byte Byte;
  struct {
    byte BGBE        :1;                                       /* Bandgap Buffer Enable */
    byte             :1; 
    byte LVDE        :1;                                       /* Low-Voltage Detect Enable */
    byte LVDSE       :1;                                       /* Low-Voltage Detect Stop Enable */
    byte LVDRE       :1;                                       /* Low-Voltage Detect Reset Enable */
    byte LVWIE       :1;                                       /* Low-Voltage Warning Interrupt Enable */
    byte LVWACK      :1;                                       /* Low-Voltage Warning Acknowledge */
    byte LVWF        :1;                                       /* Low-Voltage Warning status */
  } Bits;
} SPMSC1STR;
#define _SPMSC1 (*(volatile SPMSC1STR *)0xFFFF9809)
#define SPMSC1                          _SPMSC1.Byte
#define SPMSC1_BGBE                     _SPMSC1.Bits.BGBE
#define SPMSC1_LVDE                     _SPMSC1.Bits.LVDE
#define SPMSC1_LVDSE                    _SPMSC1.Bits.LVDSE
#define SPMSC1_LVDRE                    _SPMSC1.Bits.LVDRE
#define SPMSC1_LVWIE                    _SPMSC1.Bits.LVWIE
#define SPMSC1_LVWACK                   _SPMSC1.Bits.LVWACK
#define SPMSC1_LVWF                     _SPMSC1.Bits.LVWF

#define SPMSC1_BGBE_MASK                1U
#define SPMSC1_LVDE_MASK                4U
#define SPMSC1_LVDSE_MASK               8U
#define SPMSC1_LVDRE_MASK               16U
#define SPMSC1_LVWIE_MASK               32U
#define SPMSC1_LVWACK_MASK              64U
#define SPMSC1_LVWF_MASK                128U


/*** SPMSC2 - System Power Management Status and Control 2 Register; 0xFFFF980A ***/
typedef union {
  byte Byte;
  struct {
    byte PPDC        :1;                                       /* Partial Power Down Control */
    byte             :1; 
    byte PPDACK      :1;                                       /* Partial Power Down Acknowledge */
    byte PPDF        :1;                                       /* Partial Power Down Flag */
    byte LVWV        :1;                                       /* Low-Voltage Warning Voltage Select */
    byte LVDV        :1;                                       /* Low-Voltage Detect Voltage Select */
    byte             :1; 
    byte             :1; 
  } Bits;
} SPMSC2STR;
#define _SPMSC2 (*(volatile SPMSC2STR *)0xFFFF980A)
#define SPMSC2                          _SPMSC2.Byte
#define SPMSC2_PPDC                     _SPMSC2.Bits.PPDC
#define SPMSC2_PPDACK                   _SPMSC2.Bits.PPDACK
#define SPMSC2_PPDF                     _SPMSC2.Bits.PPDF
#define SPMSC2_LVWV                     _SPMSC2.Bits.LVWV
#define SPMSC2_LVDV                     _SPMSC2.Bits.LVDV

#define SPMSC2_PPDC_MASK                1U
#define SPMSC2_PPDACK_MASK              4U
#define SPMSC2_PPDF_MASK                8U
#define SPMSC2_LVWV_MASK                16U
#define SPMSC2_LVDV_MASK                32U


/*** SCGC1 - System Clock Gating Control 1 Register; 0xFFFF980B ***/
typedef union {
  byte Byte;
  struct {
    byte SCI1        :1;                                       /* SCI1 Clock Gate Control */
    byte SCI2        :1;                                       /* SCI2 Clock Gate Control */
    byte IIC1        :1;                                       /* IIC1 Clock Gate Control */
    byte IIC2        :1;                                       /* IIC2 Clock Gate Control */
    byte ADC         :1;                                       /* ADC Clock Gate Control */
    byte TPM1        :1;                                       /* TPM1 Clock Gate Control */
    byte TPM2        :1;                                       /* TPM2 Clock Gate Control */
    byte CMT         :1;                                       /* CMT Clock Gate Control */
  } Bits;
  struct {
    byte grpSCI_1 :2;
    byte grpIIC_1 :2;
    byte         :1;
    byte grpTPM_1 :2;
    byte         :1;
  } MergedBits;
} SCGC1STR;
#define _SCGC1 (*(volatile SCGC1STR *)0xFFFF980B)
#define SCGC1                           _SCGC1.Byte
#define SCGC1_SCI1                      _SCGC1.Bits.SCI1
#define SCGC1_SCI2                      _SCGC1.Bits.SCI2
#define SCGC1_IIC1                      _SCGC1.Bits.IIC1
#define SCGC1_IIC2                      _SCGC1.Bits.IIC2
#define SCGC1_ADC                       _SCGC1.Bits.ADC
#define SCGC1_TPM1                      _SCGC1.Bits.TPM1
#define SCGC1_TPM2                      _SCGC1.Bits.TPM2
#define SCGC1_CMT                       _SCGC1.Bits.CMT
#define SCGC1_SCI_1                     _SCGC1.MergedBits.grpSCI_1
#define SCGC1_IIC_1                     _SCGC1.MergedBits.grpIIC_1
#define SCGC1_TPM_1                     _SCGC1.MergedBits.grpTPM_1
#define SCGC1_SCI                       SCGC1_SCI_1
#define SCGC1_IIC                       SCGC1_IIC_1
#define SCGC1_TPM                       SCGC1_TPM_1

#define SCGC1_SCI1_MASK                 1U
#define SCGC1_SCI2_MASK                 2U
#define SCGC1_IIC1_MASK                 4U
#define SCGC1_IIC2_MASK                 8U
#define SCGC1_ADC_MASK                  16U
#define SCGC1_TPM1_MASK                 32U
#define SCGC1_TPM2_MASK                 64U
#define SCGC1_CMT_MASK                  128U
#define SCGC1_SCI_1_MASK                3U
#define SCGC1_SCI_1_BITNUM              0U
#define SCGC1_IIC_1_MASK                12U
#define SCGC1_IIC_1_BITNUM              2U
#define SCGC1_TPM_1_MASK                96U
#define SCGC1_TPM_1_BITNUM              5U


/*** SCGC2 - System Clock Gating Control 2 Register; 0xFFFF980C ***/
typedef union {
  byte Byte;
  struct {
    byte SPI1        :1;                                       /* SPI1 Clock Gate Control */
    byte SPI2        :1;                                       /* SPI2 Clock Gate Control */
    byte RTC         :1;                                       /* RTC Clock Gate Control */
    byte ACMP        :1;                                       /* ACMP Clock Gate Control */
    byte KBI         :1;                                       /* KBI Clock Gate Control */
    byte IRQ         :1;                                       /* IRQ Clock Gate Control */
    byte FLS         :1;                                       /* FLASH Register Clock Gate Control */
    byte USB         :1;                                       /* USB Clock Gate Control */
  } Bits;
  struct {
    byte grpSPI_1 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SCGC2STR;
#define _SCGC2 (*(volatile SCGC2STR *)0xFFFF980C)
#define SCGC2                           _SCGC2.Byte
#define SCGC2_SPI1                      _SCGC2.Bits.SPI1
#define SCGC2_SPI2                      _SCGC2.Bits.SPI2
#define SCGC2_RTC                       _SCGC2.Bits.RTC
#define SCGC2_ACMP                      _SCGC2.Bits.ACMP
#define SCGC2_KBI                       _SCGC2.Bits.KBI
#define SCGC2_IRQ                       _SCGC2.Bits.IRQ
#define SCGC2_FLS                       _SCGC2.Bits.FLS
#define SCGC2_USB                       _SCGC2.Bits.USB
#define SCGC2_SPI_1                     _SCGC2.MergedBits.grpSPI_1
#define SCGC2_SPI                       SCGC2_SPI_1

#define SCGC2_SPI1_MASK                 1U
#define SCGC2_SPI2_MASK                 2U
#define SCGC2_RTC_MASK                  4U
#define SCGC2_ACMP_MASK                 8U
#define SCGC2_KBI_MASK                  16U
#define SCGC2_IRQ_MASK                  32U
#define SCGC2_FLS_MASK                  64U
#define SCGC2_USB_MASK                  128U
#define SCGC2_SPI_1_MASK                3U
#define SCGC2_SPI_1_BITNUM              0U


/*** SCGC3 - System Clock Gating Control 3 Register; 0xFFFF980D ***/
typedef union {
  byte Byte;
  struct {
    byte RNGA        :1;                                       /* RNGA Clock Gate Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SCGC3STR;
#define _SCGC3 (*(volatile SCGC3STR *)0xFFFF980D)
#define SCGC3                           _SCGC3.Byte
#define SCGC3_RNGA                      _SCGC3.Bits.RNGA

#define SCGC3_RNGA_MASK                 1U


/*** SOPT3 - System Options 3 Register; 0xFFFF980E ***/
typedef union {
  byte Byte;
  struct {
    byte CMT_PAD     :1;                                       /* CMT pad drive strength */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SOPT3STR;
#define _SOPT3 (*(volatile SOPT3STR *)0xFFFF980E)
#define SOPT3                           _SOPT3.Byte
#define SOPT3_CMT_PAD                   _SOPT3.Bits.CMT_PAD

#define SOPT3_CMT_PAD_MASK              1U


/*** SOPT4 - System Options 4 Register; 0xFFFF980F ***/
typedef union {
  byte Byte;
  struct {
    byte PMC_LVD_TRIM0 :1;                                     /* PMC LVD TRIM, bit 0 */
    byte PMC_LVD_TRIM1 :1;                                     /* PMC LVD TRIM, bit 1 */
    byte PMC_LVD_TRIM2 :1;                                     /* PMC LVD TRIM, bit 2 */
    byte PMC_LVD_TRIM3 :1;                                     /* PMC LVD TRIM, bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPMC_LVD_TRIM :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SOPT4STR;
#define _SOPT4 (*(volatile SOPT4STR *)0xFFFF980F)
#define SOPT4                           _SOPT4.Byte
#define SOPT4_PMC_LVD_TRIM0             _SOPT4.Bits.PMC_LVD_TRIM0
#define SOPT4_PMC_LVD_TRIM1             _SOPT4.Bits.PMC_LVD_TRIM1
#define SOPT4_PMC_LVD_TRIM2             _SOPT4.Bits.PMC_LVD_TRIM2
#define SOPT4_PMC_LVD_TRIM3             _SOPT4.Bits.PMC_LVD_TRIM3
#define SOPT4_PMC_LVD_TRIM              _SOPT4.MergedBits.grpPMC_LVD_TRIM

#define SOPT4_PMC_LVD_TRIM0_MASK        1U
#define SOPT4_PMC_LVD_TRIM1_MASK        2U
#define SOPT4_PMC_LVD_TRIM2_MASK        4U
#define SOPT4_PMC_LVD_TRIM3_MASK        8U
#define SOPT4_PMC_LVD_TRIM_MASK         15U
#define SOPT4_PMC_LVD_TRIM_BITNUM       0U


/*** FCDIV - FLASH Clock Divider Register; 0xFFFF9820 ***/
typedef union {
  byte Byte;
  struct {
    byte FDIV0       :1;                                       /* Divisor for FLASH Clock Divider, bit 0 */
    byte FDIV1       :1;                                       /* Divisor for FLASH Clock Divider, bit 1 */
    byte FDIV2       :1;                                       /* Divisor for FLASH Clock Divider, bit 2 */
    byte FDIV3       :1;                                       /* Divisor for FLASH Clock Divider, bit 3 */
    byte FDIV4       :1;                                       /* Divisor for FLASH Clock Divider, bit 4 */
    byte FDIV5       :1;                                       /* Divisor for FLASH Clock Divider, bit 5 */
    byte PRDIV8      :1;                                       /* Prescale (Divide) FLASH Clock by 8 */
    byte FDIVLD      :1;                                       /* Divisor Loaded Status Flag */
  } Bits;
  struct {
    byte grpFDIV :6;
    byte grpPRDIV_8 :1;
    byte         :1;
  } MergedBits;
} FCDIVSTR;
#define _FCDIV (*(volatile FCDIVSTR *)0xFFFF9820)
#define FCDIV                           _FCDIV.Byte
#define FCDIV_FDIV0                     _FCDIV.Bits.FDIV0
#define FCDIV_FDIV1                     _FCDIV.Bits.FDIV1
#define FCDIV_FDIV2                     _FCDIV.Bits.FDIV2
#define FCDIV_FDIV3                     _FCDIV.Bits.FDIV3
#define FCDIV_FDIV4                     _FCDIV.Bits.FDIV4
#define FCDIV_FDIV5                     _FCDIV.Bits.FDIV5
#define FCDIV_PRDIV8                    _FCDIV.Bits.PRDIV8
#define FCDIV_FDIVLD                    _FCDIV.Bits.FDIVLD
#define FCDIV_FDIV                      _FCDIV.MergedBits.grpFDIV

#define FCDIV_FDIV0_MASK                1U
#define FCDIV_FDIV1_MASK                2U
#define FCDIV_FDIV2_MASK                4U
#define FCDIV_FDIV3_MASK                8U
#define FCDIV_FDIV4_MASK                16U
#define FCDIV_FDIV5_MASK                32U
#define FCDIV_PRDIV8_MASK               64U
#define FCDIV_FDIVLD_MASK               128U
#define FCDIV_FDIV_MASK                 63U
#define FCDIV_FDIV_BITNUM               0U


/*** FOPT - Flash Options Register; 0xFFFF9821 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpKEYEN :2;
  } MergedBits;
} FOPTSTR;
#define _FOPT (*(volatile FOPTSTR *)0xFFFF9821)
#define FOPT                            _FOPT.Byte
#define FOPT_SEC0                       _FOPT.Bits.SEC0
#define FOPT_SEC1                       _FOPT.Bits.SEC1
#define FOPT_KEYEN0                     _FOPT.Bits.KEYEN0
#define FOPT_KEYEN1                     _FOPT.Bits.KEYEN1
#define FOPT_SEC                        _FOPT.MergedBits.grpSEC
#define FOPT_KEYEN                      _FOPT.MergedBits.grpKEYEN

#define FOPT_SEC0_MASK                  1U
#define FOPT_SEC1_MASK                  2U
#define FOPT_KEYEN0_MASK                64U
#define FOPT_KEYEN1_MASK                128U
#define FOPT_SEC_MASK                   3U
#define FOPT_SEC_BITNUM                 0U
#define FOPT_KEYEN_MASK                 192U
#define FOPT_KEYEN_BITNUM               6U


/*** FCNFG - Flash Configuration Register; 0xFFFF9823 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYACC      :1;                                       /* Enable Security Key Writing */
    byte             :1; 
    byte             :1; 
  } Bits;
} FCNFGSTR;
#define _FCNFG (*(volatile FCNFGSTR *)0xFFFF9823)
#define FCNFG                           _FCNFG.Byte
#define FCNFG_KEYACC                    _FCNFG.Bits.KEYACC

#define FCNFG_KEYACC_MASK               32U


/*** FPROT - Flash Protection Register; 0xFFFF9824 ***/
typedef union {
  byte Byte;
  struct {
    byte FPOPEN      :1;                                       /* Flash Protection Open */
    byte FPS0        :1;                                       /* Flash Protection Size, bit 0 */
    byte FPS1        :1;                                       /* Flash Protection Size, bit 1 */
    byte FPS2        :1;                                       /* Flash Protection Size, bit 2 */
    byte FPS3        :1;                                       /* Flash Protection Size, bit 3 */
    byte FPS4        :1;                                       /* Flash Protection Size, bit 4 */
    byte FPS5        :1;                                       /* Flash Protection Size, bit 5 */
    byte FPS6        :1;                                       /* Flash Protection Size, bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS  :7;
  } MergedBits;
} FPROTSTR;
#define _FPROT (*(volatile FPROTSTR *)0xFFFF9824)
#define FPROT                           _FPROT.Byte
#define FPROT_FPOPEN                    _FPROT.Bits.FPOPEN
#define FPROT_FPS0                      _FPROT.Bits.FPS0
#define FPROT_FPS1                      _FPROT.Bits.FPS1
#define FPROT_FPS2                      _FPROT.Bits.FPS2
#define FPROT_FPS3                      _FPROT.Bits.FPS3
#define FPROT_FPS4                      _FPROT.Bits.FPS4
#define FPROT_FPS5                      _FPROT.Bits.FPS5
#define FPROT_FPS6                      _FPROT.Bits.FPS6
#define FPROT_FPS                       _FPROT.MergedBits.grpFPS

#define FPROT_FPOPEN_MASK               1U
#define FPROT_FPS0_MASK                 2U
#define FPROT_FPS1_MASK                 4U
#define FPROT_FPS2_MASK                 8U
#define FPROT_FPS3_MASK                 16U
#define FPROT_FPS4_MASK                 32U
#define FPROT_FPS5_MASK                 64U
#define FPROT_FPS6_MASK                 128U
#define FPROT_FPS_MASK                  254U
#define FPROT_FPS_BITNUM                1U


/*** FSTAT - Flash Status Register; 0xFFFF9825 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte FBLANK      :1;                                       /* FLASH Flag Indicating the Erase Verify Operation Status */
    byte             :1; 
    byte FACCERR     :1;                                       /* FLASH Access Error Flag */
    byte FPVIOL      :1;                                       /* FLASH Protection Violation Flag */
    byte FCCF        :1;                                       /* FLASH Command Complete Interrupt Flag */
    byte FCBEF       :1;                                       /* FLASH Command Buffer Empty Flag */
  } Bits;
} FSTATSTR;
#define _FSTAT (*(volatile FSTATSTR *)0xFFFF9825)
#define FSTAT                           _FSTAT.Byte
#define FSTAT_FBLANK                    _FSTAT.Bits.FBLANK
#define FSTAT_FACCERR                   _FSTAT.Bits.FACCERR
#define FSTAT_FPVIOL                    _FSTAT.Bits.FPVIOL
#define FSTAT_FCCF                      _FSTAT.Bits.FCCF
#define FSTAT_FCBEF                     _FSTAT.Bits.FCBEF

#define FSTAT_FBLANK_MASK               4U
#define FSTAT_FACCERR_MASK              16U
#define FSTAT_FPVIOL_MASK               32U
#define FSTAT_FCCF_MASK                 64U
#define FSTAT_FCBEF_MASK                128U


/*** FCMD - Flash Command Register; 0xFFFF9826 ***/
typedef union {
  byte Byte;
  struct {
    byte FCMD0       :1;                                       /* Flash Command, bit 0 */
    byte FCMD1       :1;                                       /* Flash Command, bit 1 */
    byte FCMD2       :1;                                       /* Flash Command, bit 2 */
    byte FCMD3       :1;                                       /* Flash Command, bit 3 */
    byte FCMD4       :1;                                       /* Flash Command, bit 4 */
    byte FCMD5       :1;                                       /* Flash Command, bit 5 */
    byte FCMD6       :1;                                       /* Flash Command, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpFCMD :7;
    byte         :1;
  } MergedBits;
} FCMDSTR;
#define _FCMD (*(volatile FCMDSTR *)0xFFFF9826)
#define FCMD                            _FCMD.Byte
#define FCMD_FCMD0                      _FCMD.Bits.FCMD0
#define FCMD_FCMD1                      _FCMD.Bits.FCMD1
#define FCMD_FCMD2                      _FCMD.Bits.FCMD2
#define FCMD_FCMD3                      _FCMD.Bits.FCMD3
#define FCMD_FCMD4                      _FCMD.Bits.FCMD4
#define FCMD_FCMD5                      _FCMD.Bits.FCMD5
#define FCMD_FCMD6                      _FCMD.Bits.FCMD6
#define FCMD_FCMD                       _FCMD.MergedBits.grpFCMD

#define FCMD_FCMD0_MASK                 1U
#define FCMD_FCMD1_MASK                 2U
#define FCMD_FCMD2_MASK                 4U
#define FCMD_FCMD3_MASK                 8U
#define FCMD_FCMD4_MASK                 16U
#define FCMD_FCMD5_MASK                 32U
#define FCMD_FCMD6_MASK                 64U
#define FCMD_FCMD_MASK                  127U
#define FCMD_FCMD_BITNUM                0U


/*** IIC2A - IIC Address Register; 0xFFFF9838 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte AD1         :1;                                       /* Slave Address Bit 1 */
    byte AD2         :1;                                       /* Slave Address Bit 2 */
    byte AD3         :1;                                       /* Slave Address Bit 3 */
    byte AD4         :1;                                       /* Slave Address Bit 4 */
    byte AD5         :1;                                       /* Slave Address Bit 5 */
    byte AD6         :1;                                       /* Slave Address Bit 6 */
    byte AD7         :1;                                       /* Slave Address Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpAD_1 :7;
  } MergedBits;
} IIC2ASTR;
#define _IIC2A (*(volatile IIC2ASTR *)0xFFFF9838)
#define IIC2A                           _IIC2A.Byte
#define IIC2A_AD1                       _IIC2A.Bits.AD1
#define IIC2A_AD2                       _IIC2A.Bits.AD2
#define IIC2A_AD3                       _IIC2A.Bits.AD3
#define IIC2A_AD4                       _IIC2A.Bits.AD4
#define IIC2A_AD5                       _IIC2A.Bits.AD5
#define IIC2A_AD6                       _IIC2A.Bits.AD6
#define IIC2A_AD7                       _IIC2A.Bits.AD7
#define IIC2A_AD_1                      _IIC2A.MergedBits.grpAD_1
#define IIC2A_AD                        IIC2A_AD_1

#define IIC2A_AD1_MASK                  2U
#define IIC2A_AD2_MASK                  4U
#define IIC2A_AD3_MASK                  8U
#define IIC2A_AD4_MASK                  16U
#define IIC2A_AD5_MASK                  32U
#define IIC2A_AD6_MASK                  64U
#define IIC2A_AD7_MASK                  128U
#define IIC2A_AD_1_MASK                 254U
#define IIC2A_AD_1_BITNUM               1U


/*** IIC2F - IIC Frequency Divider Register; 0xFFFF9839 ***/
typedef union {
  byte Byte;
  struct {
    byte ICR0        :1;                                       /* IIC Clock Rate Bit 0 */
    byte ICR1        :1;                                       /* IIC Clock Rate Bit 1 */
    byte ICR2        :1;                                       /* IIC Clock Rate Bit 2 */
    byte ICR3        :1;                                       /* IIC Clock Rate Bit 3 */
    byte ICR4        :1;                                       /* IIC Clock Rate Bit 4 */
    byte ICR5        :1;                                       /* IIC Clock Rate Bit 5 */
    byte MULT0       :1;                                       /* Multiplier Factor Bit 0 */
    byte MULT1       :1;                                       /* Multiplier Factor Bit 1 */
  } Bits;
  struct {
    byte grpICR  :6;
    byte grpMULT :2;
  } MergedBits;
} IIC2FSTR;
#define _IIC2F (*(volatile IIC2FSTR *)0xFFFF9839)
#define IIC2F                           _IIC2F.Byte
#define IIC2F_ICR0                      _IIC2F.Bits.ICR0
#define IIC2F_ICR1                      _IIC2F.Bits.ICR1
#define IIC2F_ICR2                      _IIC2F.Bits.ICR2
#define IIC2F_ICR3                      _IIC2F.Bits.ICR3
#define IIC2F_ICR4                      _IIC2F.Bits.ICR4
#define IIC2F_ICR5                      _IIC2F.Bits.ICR5
#define IIC2F_MULT0                     _IIC2F.Bits.MULT0
#define IIC2F_MULT1                     _IIC2F.Bits.MULT1
#define IIC2F_ICR                       _IIC2F.MergedBits.grpICR
#define IIC2F_MULT                      _IIC2F.MergedBits.grpMULT

#define IIC2F_ICR0_MASK                 1U
#define IIC2F_ICR1_MASK                 2U
#define IIC2F_ICR2_MASK                 4U
#define IIC2F_ICR3_MASK                 8U
#define IIC2F_ICR4_MASK                 16U
#define IIC2F_ICR5_MASK                 32U
#define IIC2F_MULT0_MASK                64U
#define IIC2F_MULT1_MASK                128U
#define IIC2F_ICR_MASK                  63U
#define IIC2F_ICR_BITNUM                0U
#define IIC2F_MULT_MASK                 192U
#define IIC2F_MULT_BITNUM               6U


/*** IIC2C1 - IIC Control Register 1; 0xFFFF983A ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** IIC2C1 - IIC Control Register 1; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte             :1; 
        byte RSTA        :1;                                       /* Repeat START */
        byte TXAK        :1;                                       /* Transmit Acknowledge Enable */
        byte TX          :1;                                       /* Transmit Mode Select */
        byte MST         :1;                                       /* Master Mode Select */
        byte IICIE       :1;                                       /* IIC Interrupt Enable */
        byte IICEN       :1;                                       /* IIC Enable */
      } Bits;
    } IIC2C1STR;
    #define IIC2C1                      _IIC2C1.Byte
    #define IIC2C1_RSTA                 _IIC2C1.SameAddr_STR.IIC2C1STR.Bits.RSTA
    #define IIC2C1_TXAK                 _IIC2C1.SameAddr_STR.IIC2C1STR.Bits.TXAK
    #define IIC2C1_TX                   _IIC2C1.SameAddr_STR.IIC2C1STR.Bits.TX
    #define IIC2C1_MST                  _IIC2C1.SameAddr_STR.IIC2C1STR.Bits.MST
    #define IIC2C1_IICIE                _IIC2C1.SameAddr_STR.IIC2C1STR.Bits.IICIE
    #define IIC2C1_IICEN                _IIC2C1.SameAddr_STR.IIC2C1STR.Bits.IICEN
    
    #define IIC2C1_RSTA_MASK            4U
    #define IIC2C1_TXAK_MASK            8U
    #define IIC2C1_TX_MASK              16U
    #define IIC2C1_MST_MASK             32U
    #define IIC2C1_IICIE_MASK           64U
    #define IIC2C1_IICEN_MASK           128U
    
    /*** IIC2C - IIC Control Register; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte             :1; 
        byte RSTA        :1;                                       /* Repeat START */
        byte TXAK        :1;                                       /* Transmit Acknowledge Enable */
        byte TX          :1;                                       /* Transmit Mode Select */
        byte MST         :1;                                       /* Master Mode Select */
        byte IICIE       :1;                                       /* IIC Interrupt Enable */
        byte IICEN       :1;                                       /* IIC Enable */
      } Bits;
    } IIC2CSTR;
    #define IIC2C                       _IIC2C1.Byte
    #define IIC2C_RSTA                  _IIC2C1.SameAddr_STR.IIC2CSTR.Bits.RSTA
    #define IIC2C_TXAK                  _IIC2C1.SameAddr_STR.IIC2CSTR.Bits.TXAK
    #define IIC2C_TX                    _IIC2C1.SameAddr_STR.IIC2CSTR.Bits.TX
    #define IIC2C_MST                   _IIC2C1.SameAddr_STR.IIC2CSTR.Bits.MST
    #define IIC2C_IICIE                 _IIC2C1.SameAddr_STR.IIC2CSTR.Bits.IICIE
    #define IIC2C_IICEN                 _IIC2C1.SameAddr_STR.IIC2CSTR.Bits.IICEN
    
    #define IIC2C_RSTA_MASK             4U
    #define IIC2C_TXAK_MASK             8U
    #define IIC2C_TX_MASK               16U
    #define IIC2C_MST_MASK              32U
    #define IIC2C_IICIE_MASK            64U
    #define IIC2C_IICEN_MASK            128U
    
  } SameAddr_STR; /*Several registers at the same address */

} IIC2C1STR;
#define _IIC2C1 (*(volatile IIC2C1STR *)0xFFFF983A)


/*** IIC2S - IIC Status Register; 0xFFFF983B ***/
typedef union {
  byte Byte;
  struct {
    byte RXAK        :1;                                       /* Receive Acknowledge */
    byte IICIF       :1;                                       /* IIC Interrupt Flag */
    byte SRW         :1;                                       /* Slave Read/Write */
    byte             :1; 
    byte ARBL        :1;                                       /* Arbitration Lost */
    byte BUSY        :1;                                       /* Bus Busy */
    byte IAAS        :1;                                       /* Addressed as a Slave */
    byte TCF         :1;                                       /* Transfer Complete Flag */
  } Bits;
} IIC2SSTR;
#define _IIC2S (*(volatile IIC2SSTR *)0xFFFF983B)
#define IIC2S                           _IIC2S.Byte
#define IIC2S_RXAK                      _IIC2S.Bits.RXAK
#define IIC2S_IICIF                     _IIC2S.Bits.IICIF
#define IIC2S_SRW                       _IIC2S.Bits.SRW
#define IIC2S_ARBL                      _IIC2S.Bits.ARBL
#define IIC2S_BUSY                      _IIC2S.Bits.BUSY
#define IIC2S_IAAS                      _IIC2S.Bits.IAAS
#define IIC2S_TCF                       _IIC2S.Bits.TCF

#define IIC2S_RXAK_MASK                 1U
#define IIC2S_IICIF_MASK                2U
#define IIC2S_SRW_MASK                  4U
#define IIC2S_ARBL_MASK                 16U
#define IIC2S_BUSY_MASK                 32U
#define IIC2S_IAAS_MASK                 64U
#define IIC2S_TCF_MASK                  128U


/*** IIC2D - IIC Data I/O Register; 0xFFFF983C ***/
typedef union {
  byte Byte;
  struct {
    byte DATA0       :1;                                       /* IIC Data Bit 0 */
    byte DATA1       :1;                                       /* IIC Data Bit 1 */
    byte DATA2       :1;                                       /* IIC Data Bit 2 */
    byte DATA3       :1;                                       /* IIC Data Bit 3 */
    byte DATA4       :1;                                       /* IIC Data Bit 4 */
    byte DATA5       :1;                                       /* IIC Data Bit 5 */
    byte DATA6       :1;                                       /* IIC Data Bit 6 */
    byte DATA7       :1;                                       /* IIC Data Bit 7 */
  } Bits;
} IIC2DSTR;
#define _IIC2D (*(volatile IIC2DSTR *)0xFFFF983C)
#define IIC2D                           _IIC2D.Byte
#define IIC2D_DATA0                     _IIC2D.Bits.DATA0
#define IIC2D_DATA1                     _IIC2D.Bits.DATA1
#define IIC2D_DATA2                     _IIC2D.Bits.DATA2
#define IIC2D_DATA3                     _IIC2D.Bits.DATA3
#define IIC2D_DATA4                     _IIC2D.Bits.DATA4
#define IIC2D_DATA5                     _IIC2D.Bits.DATA5
#define IIC2D_DATA6                     _IIC2D.Bits.DATA6
#define IIC2D_DATA7                     _IIC2D.Bits.DATA7

#define IIC2D_DATA0_MASK                1U
#define IIC2D_DATA1_MASK                2U
#define IIC2D_DATA2_MASK                4U
#define IIC2D_DATA3_MASK                8U
#define IIC2D_DATA4_MASK                16U
#define IIC2D_DATA5_MASK                32U
#define IIC2D_DATA6_MASK                64U
#define IIC2D_DATA7_MASK                128U


/*** IIC2C2 - IIC Control Register 2; 0xFFFF983D ***/
typedef union {
  byte Byte;
  struct {
    byte AD8         :1;                                       /* Slave Address Bit 8 */
    byte AD9         :1;                                       /* Slave Address Bit 9 */
    byte AD10        :1;                                       /* Slave Address Bit 10 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ADEXT       :1;                                       /* Address Extension */
    byte GCAEN       :1;                                       /* General Call Address Enable */
  } Bits;
  struct {
    byte grpAD_8 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} IIC2C2STR;
#define _IIC2C2 (*(volatile IIC2C2STR *)0xFFFF983D)
#define IIC2C2                          _IIC2C2.Byte
#define IIC2C2_AD8                      _IIC2C2.Bits.AD8
#define IIC2C2_AD9                      _IIC2C2.Bits.AD9
#define IIC2C2_AD10                     _IIC2C2.Bits.AD10
#define IIC2C2_ADEXT                    _IIC2C2.Bits.ADEXT
#define IIC2C2_GCAEN                    _IIC2C2.Bits.GCAEN
#define IIC2C2_AD_8                     _IIC2C2.MergedBits.grpAD_8
#define IIC2C2_AD                       IIC2C2_AD_8

#define IIC2C2_AD8_MASK                 1U
#define IIC2C2_AD9_MASK                 2U
#define IIC2C2_AD10_MASK                4U
#define IIC2C2_ADEXT_MASK               64U
#define IIC2C2_GCAEN_MASK               128U
#define IIC2C2_AD_8_MASK                7U
#define IIC2C2_AD_8_BITNUM              0U


/*** PTAPE - Port A Pull Enable Register; 0xFFFF9840 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAPE0      :1;                                       /* Internal Pull Enable for Port A Bit 0 */
    byte PTAPE1      :1;                                       /* Internal Pull Enable for Port A Bit 1 */
    byte PTAPE2      :1;                                       /* Internal Pull Enable for Port A Bit 2 */
    byte PTAPE3      :1;                                       /* Internal Pull Enable for Port A Bit 3 */
    byte PTAPE4      :1;                                       /* Internal Pull Enable for Port A Bit 4 */
    byte PTAPE5      :1;                                       /* Internal Pull Enable for Port A Bit 5 */
    byte PTAPE6      :1;                                       /* Internal Pull Enable for Port A Bit 6 */
    byte PTAPE7      :1;                                       /* Internal Pull Enable for Port A Bit 7 */
  } Bits;
} PTAPESTR;
#define _PTAPE (*(volatile PTAPESTR *)0xFFFF9840)
#define PTAPE                           _PTAPE.Byte
#define PTAPE_PTAPE0                    _PTAPE.Bits.PTAPE0
#define PTAPE_PTAPE1                    _PTAPE.Bits.PTAPE1
#define PTAPE_PTAPE2                    _PTAPE.Bits.PTAPE2
#define PTAPE_PTAPE3                    _PTAPE.Bits.PTAPE3
#define PTAPE_PTAPE4                    _PTAPE.Bits.PTAPE4
#define PTAPE_PTAPE5                    _PTAPE.Bits.PTAPE5
#define PTAPE_PTAPE6                    _PTAPE.Bits.PTAPE6
#define PTAPE_PTAPE7                    _PTAPE.Bits.PTAPE7

#define PTAPE_PTAPE0_MASK               1U
#define PTAPE_PTAPE1_MASK               2U
#define PTAPE_PTAPE2_MASK               4U
#define PTAPE_PTAPE3_MASK               8U
#define PTAPE_PTAPE4_MASK               16U
#define PTAPE_PTAPE5_MASK               32U
#define PTAPE_PTAPE6_MASK               64U
#define PTAPE_PTAPE7_MASK               128U


/*** PTASE - Port A Slew Rate Enable Register; 0xFFFF9841 ***/
typedef union {
  byte Byte;
  struct {
    byte PTASE0      :1;                                       /* Output Slew Rate Enable for Port A Bit 0 */
    byte PTASE1      :1;                                       /* Output Slew Rate Enable for Port A Bit 1 */
    byte PTASE2      :1;                                       /* Output Slew Rate Enable for Port A Bit 2 */
    byte PTASE3      :1;                                       /* Output Slew Rate Enable for Port A Bit 3 */
    byte PTASE4      :1;                                       /* Output Slew Rate Enable for Port A Bit 4 */
    byte PTASE5      :1;                                       /* Output Slew Rate Enable for Port A Bit 5 */
    byte PTASE6      :1;                                       /* Output Slew Rate Enable for Port A Bit 6 */
    byte PTASE7      :1;                                       /* Output Slew Rate Enable for Port A Bit 7 */
  } Bits;
} PTASESTR;
#define _PTASE (*(volatile PTASESTR *)0xFFFF9841)
#define PTASE                           _PTASE.Byte
#define PTASE_PTASE0                    _PTASE.Bits.PTASE0
#define PTASE_PTASE1                    _PTASE.Bits.PTASE1
#define PTASE_PTASE2                    _PTASE.Bits.PTASE2
#define PTASE_PTASE3                    _PTASE.Bits.PTASE3
#define PTASE_PTASE4                    _PTASE.Bits.PTASE4
#define PTASE_PTASE5                    _PTASE.Bits.PTASE5
#define PTASE_PTASE6                    _PTASE.Bits.PTASE6
#define PTASE_PTASE7                    _PTASE.Bits.PTASE7

#define PTASE_PTASE0_MASK               1U
#define PTASE_PTASE1_MASK               2U
#define PTASE_PTASE2_MASK               4U
#define PTASE_PTASE3_MASK               8U
#define PTASE_PTASE4_MASK               16U
#define PTASE_PTASE5_MASK               32U
#define PTASE_PTASE6_MASK               64U
#define PTASE_PTASE7_MASK               128U


/*** PTADS - Port A Drive Strength Selection Register; 0xFFFF9842 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADS0      :1;                                       /* Output Drive Strength Selection for Port A Bit 0 */
    byte PTADS1      :1;                                       /* Output Drive Strength Selection for Port A Bit 1 */
    byte PTADS2      :1;                                       /* Output Drive Strength Selection for Port A Bit 2 */
    byte PTADS3      :1;                                       /* Output Drive Strength Selection for Port A Bit 3 */
    byte PTADS4      :1;                                       /* Output Drive Strength Selection for Port A Bit 4 */
    byte PTADS5      :1;                                       /* Output Drive Strength Selection for Port A Bit 5 */
    byte PTADS6      :1;                                       /* Output Drive Strength Selection for Port A Bit 6 */
    byte PTADS7      :1;                                       /* Output Drive Strength Selection for Port A Bit 7 */
  } Bits;
} PTADSSTR;
#define _PTADS (*(volatile PTADSSTR *)0xFFFF9842)
#define PTADS                           _PTADS.Byte
#define PTADS_PTADS0                    _PTADS.Bits.PTADS0
#define PTADS_PTADS1                    _PTADS.Bits.PTADS1
#define PTADS_PTADS2                    _PTADS.Bits.PTADS2
#define PTADS_PTADS3                    _PTADS.Bits.PTADS3
#define PTADS_PTADS4                    _PTADS.Bits.PTADS4
#define PTADS_PTADS5                    _PTADS.Bits.PTADS5
#define PTADS_PTADS6                    _PTADS.Bits.PTADS6
#define PTADS_PTADS7                    _PTADS.Bits.PTADS7

#define PTADS_PTADS0_MASK               1U
#define PTADS_PTADS1_MASK               2U
#define PTADS_PTADS2_MASK               4U
#define PTADS_PTADS3_MASK               8U
#define PTADS_PTADS4_MASK               16U
#define PTADS_PTADS5_MASK               32U
#define PTADS_PTADS6_MASK               64U
#define PTADS_PTADS7_MASK               128U


/*** PTAIFE - Port A Input Filter Enable Register; 0xFFFF9843 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAIFE0     :1;                                       /* Port A Input Filter Enable Bit 0 */
    byte PTAIFE1     :1;                                       /* Port A Input Filter Enable Bit 1 */
    byte PTAIFE2     :1;                                       /* Port A Input Filter Enable Bit 2 */
    byte PTAIFE3     :1;                                       /* Port A Input Filter Enable Bit 3 */
    byte PTAIFE4     :1;                                       /* Port A Input Filter Enable Bit 4 */
    byte PTAIFE5     :1;                                       /* Port A Input Filter Enable Bit 5 */
    byte PTAIFE6     :1;                                       /* Port A Input Filter Enable Bit 6 */
    byte PTAIFE7     :1;                                       /* Port A Input Filter Enable Bit 7 */
  } Bits;
} PTAIFESTR;
#define _PTAIFE (*(volatile PTAIFESTR *)0xFFFF9843)
#define PTAIFE                          _PTAIFE.Byte
#define PTAIFE_PTAIFE0                  _PTAIFE.Bits.PTAIFE0
#define PTAIFE_PTAIFE1                  _PTAIFE.Bits.PTAIFE1
#define PTAIFE_PTAIFE2                  _PTAIFE.Bits.PTAIFE2
#define PTAIFE_PTAIFE3                  _PTAIFE.Bits.PTAIFE3
#define PTAIFE_PTAIFE4                  _PTAIFE.Bits.PTAIFE4
#define PTAIFE_PTAIFE5                  _PTAIFE.Bits.PTAIFE5
#define PTAIFE_PTAIFE6                  _PTAIFE.Bits.PTAIFE6
#define PTAIFE_PTAIFE7                  _PTAIFE.Bits.PTAIFE7

#define PTAIFE_PTAIFE0_MASK             1U
#define PTAIFE_PTAIFE1_MASK             2U
#define PTAIFE_PTAIFE2_MASK             4U
#define PTAIFE_PTAIFE3_MASK             8U
#define PTAIFE_PTAIFE4_MASK             16U
#define PTAIFE_PTAIFE5_MASK             32U
#define PTAIFE_PTAIFE6_MASK             64U
#define PTAIFE_PTAIFE7_MASK             128U


/*** PTBPE - Port B Pull Enable Register; 0xFFFF9844 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBPE0      :1;                                       /* Internal Pull Enable for Port B Bit 0 */
    byte PTBPE1      :1;                                       /* Internal Pull Enable for Port B Bit 1 */
    byte PTBPE2      :1;                                       /* Internal Pull Enable for Port B Bit 2 */
    byte PTBPE3      :1;                                       /* Internal Pull Enable for Port B Bit 3 */
    byte PTBPE4      :1;                                       /* Internal Pull Enable for Port B Bit 4 */
    byte PTBPE5      :1;                                       /* Internal Pull Enable for Port B Bit 5 */
    byte PTBPE6      :1;                                       /* Internal Pull Enable for Port B Bit 6 */
    byte PTBPE7      :1;                                       /* Internal Pull Enable for Port B Bit 7 */
  } Bits;
} PTBPESTR;
#define _PTBPE (*(volatile PTBPESTR *)0xFFFF9844)
#define PTBPE                           _PTBPE.Byte
#define PTBPE_PTBPE0                    _PTBPE.Bits.PTBPE0
#define PTBPE_PTBPE1                    _PTBPE.Bits.PTBPE1
#define PTBPE_PTBPE2                    _PTBPE.Bits.PTBPE2
#define PTBPE_PTBPE3                    _PTBPE.Bits.PTBPE3
#define PTBPE_PTBPE4                    _PTBPE.Bits.PTBPE4
#define PTBPE_PTBPE5                    _PTBPE.Bits.PTBPE5
#define PTBPE_PTBPE6                    _PTBPE.Bits.PTBPE6
#define PTBPE_PTBPE7                    _PTBPE.Bits.PTBPE7

#define PTBPE_PTBPE0_MASK               1U
#define PTBPE_PTBPE1_MASK               2U
#define PTBPE_PTBPE2_MASK               4U
#define PTBPE_PTBPE3_MASK               8U
#define PTBPE_PTBPE4_MASK               16U
#define PTBPE_PTBPE5_MASK               32U
#define PTBPE_PTBPE6_MASK               64U
#define PTBPE_PTBPE7_MASK               128U


/*** PTBSE - Port B Slew Rate Enable Register; 0xFFFF9845 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBSE0      :1;                                       /* Output Slew Rate Enable for Port B Bit 0 */
    byte PTBSE1      :1;                                       /* Output Slew Rate Enable for Port B Bit 1 */
    byte PTBSE2      :1;                                       /* Output Slew Rate Enable for Port B Bit 2 */
    byte PTBSE3      :1;                                       /* Output Slew Rate Enable for Port B Bit 3 */
    byte PTBSE4      :1;                                       /* Output Slew Rate Enable for Port B Bit 4 */
    byte PTBSE5      :1;                                       /* Output Slew Rate Enable for Port B Bit 5 */
    byte PTBSE6      :1;                                       /* Output Slew Rate Enable for Port B Bit 6 */
    byte PTBSE7      :1;                                       /* Output Slew Rate Enable for Port B Bit 7 */
  } Bits;
} PTBSESTR;
#define _PTBSE (*(volatile PTBSESTR *)0xFFFF9845)
#define PTBSE                           _PTBSE.Byte
#define PTBSE_PTBSE0                    _PTBSE.Bits.PTBSE0
#define PTBSE_PTBSE1                    _PTBSE.Bits.PTBSE1
#define PTBSE_PTBSE2                    _PTBSE.Bits.PTBSE2
#define PTBSE_PTBSE3                    _PTBSE.Bits.PTBSE3
#define PTBSE_PTBSE4                    _PTBSE.Bits.PTBSE4
#define PTBSE_PTBSE5                    _PTBSE.Bits.PTBSE5
#define PTBSE_PTBSE6                    _PTBSE.Bits.PTBSE6
#define PTBSE_PTBSE7                    _PTBSE.Bits.PTBSE7

#define PTBSE_PTBSE0_MASK               1U
#define PTBSE_PTBSE1_MASK               2U
#define PTBSE_PTBSE2_MASK               4U
#define PTBSE_PTBSE3_MASK               8U
#define PTBSE_PTBSE4_MASK               16U
#define PTBSE_PTBSE5_MASK               32U
#define PTBSE_PTBSE6_MASK               64U
#define PTBSE_PTBSE7_MASK               128U


/*** PTBDS - Port B Drive Strength Selection Register; 0xFFFF9846 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDS0      :1;                                       /* Output Drive Strength Selection for Port B Bit 0 */
    byte PTBDS1      :1;                                       /* Output Drive Strength Selection for Port B Bit 1 */
    byte PTBDS2      :1;                                       /* Output Drive Strength Selection for Port B Bit 2 */
    byte PTBDS3      :1;                                       /* Output Drive Strength Selection for Port B Bit 3 */
    byte PTBDS4      :1;                                       /* Output Drive Strength Selection for Port B Bit 4 */
    byte PTBDS5      :1;                                       /* Output Drive Strength Selection for Port B Bit 5 */
    byte PTBDS6      :1;                                       /* Output Drive Strength Selection for Port B Bit 6 */
    byte PTBDS7      :1;                                       /* Output Drive Strength Selection for Port B Bit 7 */
  } Bits;
} PTBDSSTR;
#define _PTBDS (*(volatile PTBDSSTR *)0xFFFF9846)
#define PTBDS                           _PTBDS.Byte
#define PTBDS_PTBDS0                    _PTBDS.Bits.PTBDS0
#define PTBDS_PTBDS1                    _PTBDS.Bits.PTBDS1
#define PTBDS_PTBDS2                    _PTBDS.Bits.PTBDS2
#define PTBDS_PTBDS3                    _PTBDS.Bits.PTBDS3
#define PTBDS_PTBDS4                    _PTBDS.Bits.PTBDS4
#define PTBDS_PTBDS5                    _PTBDS.Bits.PTBDS5
#define PTBDS_PTBDS6                    _PTBDS.Bits.PTBDS6
#define PTBDS_PTBDS7                    _PTBDS.Bits.PTBDS7

#define PTBDS_PTBDS0_MASK               1U
#define PTBDS_PTBDS1_MASK               2U
#define PTBDS_PTBDS2_MASK               4U
#define PTBDS_PTBDS3_MASK               8U
#define PTBDS_PTBDS4_MASK               16U
#define PTBDS_PTBDS5_MASK               32U
#define PTBDS_PTBDS6_MASK               64U
#define PTBDS_PTBDS7_MASK               128U


/*** PTBIFE - Port B Input Filter Enable Register; 0xFFFF9847 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBIFE0     :1;                                       /* Port B Input Filter Enable Bit 0 */
    byte PTBIFE1     :1;                                       /* Port B Input Filter Enable Bit 1 */
    byte PTBIFE2     :1;                                       /* Port B Input Filter Enable Bit 2 */
    byte PTBIFE3     :1;                                       /* Port B Input Filter Enable Bit 3 */
    byte PTBIFE4     :1;                                       /* Port B Input Filter Enable Bit 4 */
    byte PTBIFE5     :1;                                       /* Port B Input Filter Enable Bit 5 */
    byte PTBIFE6     :1;                                       /* Port B Input Filter Enable Bit 6 */
    byte PTBIFE7     :1;                                       /* Port B Input Filter Enable Bit 7 */
  } Bits;
} PTBIFESTR;
#define _PTBIFE (*(volatile PTBIFESTR *)0xFFFF9847)
#define PTBIFE                          _PTBIFE.Byte
#define PTBIFE_PTBIFE0                  _PTBIFE.Bits.PTBIFE0
#define PTBIFE_PTBIFE1                  _PTBIFE.Bits.PTBIFE1
#define PTBIFE_PTBIFE2                  _PTBIFE.Bits.PTBIFE2
#define PTBIFE_PTBIFE3                  _PTBIFE.Bits.PTBIFE3
#define PTBIFE_PTBIFE4                  _PTBIFE.Bits.PTBIFE4
#define PTBIFE_PTBIFE5                  _PTBIFE.Bits.PTBIFE5
#define PTBIFE_PTBIFE6                  _PTBIFE.Bits.PTBIFE6
#define PTBIFE_PTBIFE7                  _PTBIFE.Bits.PTBIFE7

#define PTBIFE_PTBIFE0_MASK             1U
#define PTBIFE_PTBIFE1_MASK             2U
#define PTBIFE_PTBIFE2_MASK             4U
#define PTBIFE_PTBIFE3_MASK             8U
#define PTBIFE_PTBIFE4_MASK             16U
#define PTBIFE_PTBIFE5_MASK             32U
#define PTBIFE_PTBIFE6_MASK             64U
#define PTBIFE_PTBIFE7_MASK             128U


/*** PTCPE - Port C Pull Enable Register; 0xFFFF9848 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCPE0      :1;                                       /* Internal Pull Enable for Port C Bit 0 */
    byte PTCPE1      :1;                                       /* Internal Pull Enable for Port C Bit 1 */
    byte PTCPE2      :1;                                       /* Internal Pull Enable for Port C Bit 2 */
    byte PTCPE3      :1;                                       /* Internal Pull Enable for Port C Bit 3 */
    byte PTCPE4      :1;                                       /* Internal Pull Enable for Port C Bit 4 */
    byte PTCPE5      :1;                                       /* Internal Pull Enable for Port C Bit 5 */
    byte PTCPE6      :1;                                       /* Internal Pull Enable for Port C Bit 6 */
    byte PTCPE7      :1;                                       /* Internal Pull Enable for Port C Bit 7 */
  } Bits;
} PTCPESTR;
#define _PTCPE (*(volatile PTCPESTR *)0xFFFF9848)
#define PTCPE                           _PTCPE.Byte
#define PTCPE_PTCPE0                    _PTCPE.Bits.PTCPE0
#define PTCPE_PTCPE1                    _PTCPE.Bits.PTCPE1
#define PTCPE_PTCPE2                    _PTCPE.Bits.PTCPE2
#define PTCPE_PTCPE3                    _PTCPE.Bits.PTCPE3
#define PTCPE_PTCPE4                    _PTCPE.Bits.PTCPE4
#define PTCPE_PTCPE5                    _PTCPE.Bits.PTCPE5
#define PTCPE_PTCPE6                    _PTCPE.Bits.PTCPE6
#define PTCPE_PTCPE7                    _PTCPE.Bits.PTCPE7

#define PTCPE_PTCPE0_MASK               1U
#define PTCPE_PTCPE1_MASK               2U
#define PTCPE_PTCPE2_MASK               4U
#define PTCPE_PTCPE3_MASK               8U
#define PTCPE_PTCPE4_MASK               16U
#define PTCPE_PTCPE5_MASK               32U
#define PTCPE_PTCPE6_MASK               64U
#define PTCPE_PTCPE7_MASK               128U


/*** PTCSE - Port C Slew Rate Enable Register; 0xFFFF9849 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCSE0      :1;                                       /* Output Slew Rate Enable for Port C Bit 0 */
    byte PTCSE1      :1;                                       /* Output Slew Rate Enable for Port C Bit 1 */
    byte PTCSE2      :1;                                       /* Output Slew Rate Enable for Port C Bit 2 */
    byte PTCSE3      :1;                                       /* Output Slew Rate Enable for Port C Bit 3 */
    byte PTCSE4      :1;                                       /* Output Slew Rate Enable for Port C Bit 4 */
    byte PTCSE5      :1;                                       /* Output Slew Rate Enable for Port C Bit 5 */
    byte PTCSE6      :1;                                       /* Output Slew Rate Enable for Port C Bit 6 */
    byte PTCSE7      :1;                                       /* Output Slew Rate Enable for Port C Bit 7 */
  } Bits;
} PTCSESTR;
#define _PTCSE (*(volatile PTCSESTR *)0xFFFF9849)
#define PTCSE                           _PTCSE.Byte
#define PTCSE_PTCSE0                    _PTCSE.Bits.PTCSE0
#define PTCSE_PTCSE1                    _PTCSE.Bits.PTCSE1
#define PTCSE_PTCSE2                    _PTCSE.Bits.PTCSE2
#define PTCSE_PTCSE3                    _PTCSE.Bits.PTCSE3
#define PTCSE_PTCSE4                    _PTCSE.Bits.PTCSE4
#define PTCSE_PTCSE5                    _PTCSE.Bits.PTCSE5
#define PTCSE_PTCSE6                    _PTCSE.Bits.PTCSE6
#define PTCSE_PTCSE7                    _PTCSE.Bits.PTCSE7

#define PTCSE_PTCSE0_MASK               1U
#define PTCSE_PTCSE1_MASK               2U
#define PTCSE_PTCSE2_MASK               4U
#define PTCSE_PTCSE3_MASK               8U
#define PTCSE_PTCSE4_MASK               16U
#define PTCSE_PTCSE5_MASK               32U
#define PTCSE_PTCSE6_MASK               64U
#define PTCSE_PTCSE7_MASK               128U


/*** PTCDS - Port C Drive Strength Selection Register; 0xFFFF984A ***/
typedef union {
  byte Byte;
  struct {
    byte PTCDS0      :1;                                       /* Output Drive Strength Selection for Port C Bit 0 */
    byte PTCDS1      :1;                                       /* Output Drive Strength Selection for Port C Bit 1 */
    byte PTCDS2      :1;                                       /* Output Drive Strength Selection for Port C Bit 2 */
    byte PTCDS3      :1;                                       /* Output Drive Strength Selection for Port C Bit 3 */
    byte PTCDS4      :1;                                       /* Output Drive Strength Selection for Port C Bit 4 */
    byte PTCDS5      :1;                                       /* Output Drive Strength Selection for Port C Bit 5 */
    byte PTCDS6      :1;                                       /* Output Drive Strength Selection for Port C Bit 6 */
    byte PTCDS7      :1;                                       /* Output Drive Strength Selection for Port C Bit 7 */
  } Bits;
} PTCDSSTR;
#define _PTCDS (*(volatile PTCDSSTR *)0xFFFF984A)
#define PTCDS                           _PTCDS.Byte
#define PTCDS_PTCDS0                    _PTCDS.Bits.PTCDS0
#define PTCDS_PTCDS1                    _PTCDS.Bits.PTCDS1
#define PTCDS_PTCDS2                    _PTCDS.Bits.PTCDS2
#define PTCDS_PTCDS3                    _PTCDS.Bits.PTCDS3
#define PTCDS_PTCDS4                    _PTCDS.Bits.PTCDS4
#define PTCDS_PTCDS5                    _PTCDS.Bits.PTCDS5
#define PTCDS_PTCDS6                    _PTCDS.Bits.PTCDS6
#define PTCDS_PTCDS7                    _PTCDS.Bits.PTCDS7

#define PTCDS_PTCDS0_MASK               1U
#define PTCDS_PTCDS1_MASK               2U
#define PTCDS_PTCDS2_MASK               4U
#define PTCDS_PTCDS3_MASK               8U
#define PTCDS_PTCDS4_MASK               16U
#define PTCDS_PTCDS5_MASK               32U
#define PTCDS_PTCDS6_MASK               64U
#define PTCDS_PTCDS7_MASK               128U


/*** PTCIFE - Port C Input Filter Enable Register; 0xFFFF984B ***/
typedef union {
  byte Byte;
  struct {
    byte PTCIFE0     :1;                                       /* Port C Input Filter Enable Bit 0 */
    byte PTCIFE1     :1;                                       /* Port C Input Filter Enable Bit 1 */
    byte PTCIFE2     :1;                                       /* Port C Input Filter Enable Bit 2 */
    byte PTCIFE3     :1;                                       /* Port C Input Filter Enable Bit 3 */
    byte PTCIFE4     :1;                                       /* Port C Input Filter Enable Bit 4 */
    byte PTCIFE5     :1;                                       /* Port C Input Filter Enable Bit 5 */
    byte PTCIFE6     :1;                                       /* Port C Input Filter Enable Bit 6 */
    byte PTCIFE7     :1;                                       /* Port C Input Filter Enable Bit 7 */
  } Bits;
} PTCIFESTR;
#define _PTCIFE (*(volatile PTCIFESTR *)0xFFFF984B)
#define PTCIFE                          _PTCIFE.Byte
#define PTCIFE_PTCIFE0                  _PTCIFE.Bits.PTCIFE0
#define PTCIFE_PTCIFE1                  _PTCIFE.Bits.PTCIFE1
#define PTCIFE_PTCIFE2                  _PTCIFE.Bits.PTCIFE2
#define PTCIFE_PTCIFE3                  _PTCIFE.Bits.PTCIFE3
#define PTCIFE_PTCIFE4                  _PTCIFE.Bits.PTCIFE4
#define PTCIFE_PTCIFE5                  _PTCIFE.Bits.PTCIFE5
#define PTCIFE_PTCIFE6                  _PTCIFE.Bits.PTCIFE6
#define PTCIFE_PTCIFE7                  _PTCIFE.Bits.PTCIFE7

#define PTCIFE_PTCIFE0_MASK             1U
#define PTCIFE_PTCIFE1_MASK             2U
#define PTCIFE_PTCIFE2_MASK             4U
#define PTCIFE_PTCIFE3_MASK             8U
#define PTCIFE_PTCIFE4_MASK             16U
#define PTCIFE_PTCIFE5_MASK             32U
#define PTCIFE_PTCIFE6_MASK             64U
#define PTCIFE_PTCIFE7_MASK             128U


/*** PTDPE - Port D Pull Enable Register; 0xFFFF984C ***/
typedef union {
  byte Byte;
  struct {
    byte PTDPE0      :1;                                       /* Internal Pull Enable for Port D Bit 0 */
    byte PTDPE1      :1;                                       /* Internal Pull Enable for Port D Bit 1 */
    byte PTDPE2      :1;                                       /* Internal Pull Enable for Port D Bit 2 */
    byte PTDPE3      :1;                                       /* Internal Pull Enable for Port D Bit 3 */
    byte PTDPE4      :1;                                       /* Internal Pull Enable for Port D Bit 4 */
    byte PTDPE5      :1;                                       /* Internal Pull Enable for Port D Bit 5 */
    byte PTDPE6      :1;                                       /* Internal Pull Enable for Port D Bit 6 */
    byte PTDPE7      :1;                                       /* Internal Pull Enable for Port D Bit 7 */
  } Bits;
} PTDPESTR;
#define _PTDPE (*(volatile PTDPESTR *)0xFFFF984C)
#define PTDPE                           _PTDPE.Byte
#define PTDPE_PTDPE0                    _PTDPE.Bits.PTDPE0
#define PTDPE_PTDPE1                    _PTDPE.Bits.PTDPE1
#define PTDPE_PTDPE2                    _PTDPE.Bits.PTDPE2
#define PTDPE_PTDPE3                    _PTDPE.Bits.PTDPE3
#define PTDPE_PTDPE4                    _PTDPE.Bits.PTDPE4
#define PTDPE_PTDPE5                    _PTDPE.Bits.PTDPE5
#define PTDPE_PTDPE6                    _PTDPE.Bits.PTDPE6
#define PTDPE_PTDPE7                    _PTDPE.Bits.PTDPE7

#define PTDPE_PTDPE0_MASK               1U
#define PTDPE_PTDPE1_MASK               2U
#define PTDPE_PTDPE2_MASK               4U
#define PTDPE_PTDPE3_MASK               8U
#define PTDPE_PTDPE4_MASK               16U
#define PTDPE_PTDPE5_MASK               32U
#define PTDPE_PTDPE6_MASK               64U
#define PTDPE_PTDPE7_MASK               128U


/*** PTDSE - Port D Slew Rate Enable Register; 0xFFFF984D ***/
typedef union {
  byte Byte;
  struct {
    byte PTDSE0      :1;                                       /* Output Slew Rate Enable for Port D Bit 0 */
    byte PTDSE1      :1;                                       /* Output Slew Rate Enable for Port D Bit 1 */
    byte PTDSE2      :1;                                       /* Output Slew Rate Enable for Port D Bit 2 */
    byte PTDSE3      :1;                                       /* Output Slew Rate Enable for Port D Bit 3 */
    byte PTDSE4      :1;                                       /* Output Slew Rate Enable for Port D Bit 4 */
    byte PTDSE5      :1;                                       /* Output Slew Rate Enable for Port D Bit 5 */
    byte PTDSE6      :1;                                       /* Output Slew Rate Enable for Port D Bit 6 */
    byte PTDSE7      :1;                                       /* Output Slew Rate Enable for Port D Bit 7 */
  } Bits;
} PTDSESTR;
#define _PTDSE (*(volatile PTDSESTR *)0xFFFF984D)
#define PTDSE                           _PTDSE.Byte
#define PTDSE_PTDSE0                    _PTDSE.Bits.PTDSE0
#define PTDSE_PTDSE1                    _PTDSE.Bits.PTDSE1
#define PTDSE_PTDSE2                    _PTDSE.Bits.PTDSE2
#define PTDSE_PTDSE3                    _PTDSE.Bits.PTDSE3
#define PTDSE_PTDSE4                    _PTDSE.Bits.PTDSE4
#define PTDSE_PTDSE5                    _PTDSE.Bits.PTDSE5
#define PTDSE_PTDSE6                    _PTDSE.Bits.PTDSE6
#define PTDSE_PTDSE7                    _PTDSE.Bits.PTDSE7

#define PTDSE_PTDSE0_MASK               1U
#define PTDSE_PTDSE1_MASK               2U
#define PTDSE_PTDSE2_MASK               4U
#define PTDSE_PTDSE3_MASK               8U
#define PTDSE_PTDSE4_MASK               16U
#define PTDSE_PTDSE5_MASK               32U
#define PTDSE_PTDSE6_MASK               64U
#define PTDSE_PTDSE7_MASK               128U


/*** PTDDS - Port D Drive Strength Selection Register; 0xFFFF984E ***/
typedef union {
  byte Byte;
  struct {
    byte PTDDS0      :1;                                       /* Output Drive Strength Selection for Port D Bit 0 */
    byte PTDDS1      :1;                                       /* Output Drive Strength Selection for Port D Bit 1 */
    byte PTDDS2      :1;                                       /* Output Drive Strength Selection for Port D Bit 2 */
    byte PTDDS3      :1;                                       /* Output Drive Strength Selection for Port D Bit 3 */
    byte PTDDS4      :1;                                       /* Output Drive Strength Selection for Port D Bit 4 */
    byte PTDDS5      :1;                                       /* Output Drive Strength Selection for Port D Bit 5 */
    byte PTDDS6      :1;                                       /* Output Drive Strength Selection for Port D Bit 6 */
    byte PTDDS7      :1;                                       /* Output Drive Strength Selection for Port D Bit 7 */
  } Bits;
} PTDDSSTR;
#define _PTDDS (*(volatile PTDDSSTR *)0xFFFF984E)
#define PTDDS                           _PTDDS.Byte
#define PTDDS_PTDDS0                    _PTDDS.Bits.PTDDS0
#define PTDDS_PTDDS1                    _PTDDS.Bits.PTDDS1
#define PTDDS_PTDDS2                    _PTDDS.Bits.PTDDS2
#define PTDDS_PTDDS3                    _PTDDS.Bits.PTDDS3
#define PTDDS_PTDDS4                    _PTDDS.Bits.PTDDS4
#define PTDDS_PTDDS5                    _PTDDS.Bits.PTDDS5
#define PTDDS_PTDDS6                    _PTDDS.Bits.PTDDS6
#define PTDDS_PTDDS7                    _PTDDS.Bits.PTDDS7

#define PTDDS_PTDDS0_MASK               1U
#define PTDDS_PTDDS1_MASK               2U
#define PTDDS_PTDDS2_MASK               4U
#define PTDDS_PTDDS3_MASK               8U
#define PTDDS_PTDDS4_MASK               16U
#define PTDDS_PTDDS5_MASK               32U
#define PTDDS_PTDDS6_MASK               64U
#define PTDDS_PTDDS7_MASK               128U


/*** PTDIFE - Port D Input Filter Enable Register; 0xFFFF984F ***/
typedef union {
  byte Byte;
  struct {
    byte PTDIFE0     :1;                                       /* Port D Input Filter Enable Bit 0 */
    byte PTDIFE1     :1;                                       /* Port D Input Filter Enable Bit 1 */
    byte PTDIFE2     :1;                                       /* Port D Input Filter Enable Bit 2 */
    byte PTDIFE3     :1;                                       /* Port D Input Filter Enable Bit 3 */
    byte PTDIFE4     :1;                                       /* Port D Input Filter Enable Bit 4 */
    byte PTDIFE5     :1;                                       /* Port D Input Filter Enable Bit 5 */
    byte PTDIFE6     :1;                                       /* Port D Input Filter Enable Bit 6 */
    byte PTDIFE7     :1;                                       /* Port D Input Filter Enable Bit 7 */
  } Bits;
} PTDIFESTR;
#define _PTDIFE (*(volatile PTDIFESTR *)0xFFFF984F)
#define PTDIFE                          _PTDIFE.Byte
#define PTDIFE_PTDIFE0                  _PTDIFE.Bits.PTDIFE0
#define PTDIFE_PTDIFE1                  _PTDIFE.Bits.PTDIFE1
#define PTDIFE_PTDIFE2                  _PTDIFE.Bits.PTDIFE2
#define PTDIFE_PTDIFE3                  _PTDIFE.Bits.PTDIFE3
#define PTDIFE_PTDIFE4                  _PTDIFE.Bits.PTDIFE4
#define PTDIFE_PTDIFE5                  _PTDIFE.Bits.PTDIFE5
#define PTDIFE_PTDIFE6                  _PTDIFE.Bits.PTDIFE6
#define PTDIFE_PTDIFE7                  _PTDIFE.Bits.PTDIFE7

#define PTDIFE_PTDIFE0_MASK             1U
#define PTDIFE_PTDIFE1_MASK             2U
#define PTDIFE_PTDIFE2_MASK             4U
#define PTDIFE_PTDIFE3_MASK             8U
#define PTDIFE_PTDIFE4_MASK             16U
#define PTDIFE_PTDIFE5_MASK             32U
#define PTDIFE_PTDIFE6_MASK             64U
#define PTDIFE_PTDIFE7_MASK             128U


/*** PTEPE - Port E Pull Enable Register; 0xFFFF9850 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEPE0      :1;                                       /* Internal Pull Enable for Port E Bit 0 */
    byte PTEPE1      :1;                                       /* Internal Pull Enable for Port E Bit 1 */
    byte PTEPE2      :1;                                       /* Internal Pull Enable for Port E Bit 2 */
    byte PTEPE3      :1;                                       /* Internal Pull Enable for Port E Bit 3 */
    byte PTEPE4      :1;                                       /* Internal Pull Enable for Port E Bit 4 */
    byte PTEPE5      :1;                                       /* Internal Pull Enable for Port E Bit 5 */
    byte PTEPE6      :1;                                       /* Internal Pull Enable for Port E Bit 6 */
    byte PTEPE7      :1;                                       /* Internal Pull Enable for Port E Bit 7 */
  } Bits;
} PTEPESTR;
#define _PTEPE (*(volatile PTEPESTR *)0xFFFF9850)
#define PTEPE                           _PTEPE.Byte
#define PTEPE_PTEPE0                    _PTEPE.Bits.PTEPE0
#define PTEPE_PTEPE1                    _PTEPE.Bits.PTEPE1
#define PTEPE_PTEPE2                    _PTEPE.Bits.PTEPE2
#define PTEPE_PTEPE3                    _PTEPE.Bits.PTEPE3
#define PTEPE_PTEPE4                    _PTEPE.Bits.PTEPE4
#define PTEPE_PTEPE5                    _PTEPE.Bits.PTEPE5
#define PTEPE_PTEPE6                    _PTEPE.Bits.PTEPE6
#define PTEPE_PTEPE7                    _PTEPE.Bits.PTEPE7

#define PTEPE_PTEPE0_MASK               1U
#define PTEPE_PTEPE1_MASK               2U
#define PTEPE_PTEPE2_MASK               4U
#define PTEPE_PTEPE3_MASK               8U
#define PTEPE_PTEPE4_MASK               16U
#define PTEPE_PTEPE5_MASK               32U
#define PTEPE_PTEPE6_MASK               64U
#define PTEPE_PTEPE7_MASK               128U


/*** PTESE - Port E Slew Rate Enable Register; 0xFFFF9851 ***/
typedef union {
  byte Byte;
  struct {
    byte PTESE0      :1;                                       /* Output Slew Rate Enable for Port E Bit 0 */
    byte PTESE1      :1;                                       /* Output Slew Rate Enable for Port E Bit 1 */
    byte PTESE2      :1;                                       /* Output Slew Rate Enable for Port E Bit 2 */
    byte PTESE3      :1;                                       /* Output Slew Rate Enable for Port E Bit 3 */
    byte PTESE4      :1;                                       /* Output Slew Rate Enable for Port E Bit 4 */
    byte PTESE5      :1;                                       /* Output Slew Rate Enable for Port E Bit 5 */
    byte PTESE6      :1;                                       /* Output Slew Rate Enable for Port E Bit 6 */
    byte PTESE7      :1;                                       /* Output Slew Rate Enable for Port E Bit 7 */
  } Bits;
} PTESESTR;
#define _PTESE (*(volatile PTESESTR *)0xFFFF9851)
#define PTESE                           _PTESE.Byte
#define PTESE_PTESE0                    _PTESE.Bits.PTESE0
#define PTESE_PTESE1                    _PTESE.Bits.PTESE1
#define PTESE_PTESE2                    _PTESE.Bits.PTESE2
#define PTESE_PTESE3                    _PTESE.Bits.PTESE3
#define PTESE_PTESE4                    _PTESE.Bits.PTESE4
#define PTESE_PTESE5                    _PTESE.Bits.PTESE5
#define PTESE_PTESE6                    _PTESE.Bits.PTESE6
#define PTESE_PTESE7                    _PTESE.Bits.PTESE7

#define PTESE_PTESE0_MASK               1U
#define PTESE_PTESE1_MASK               2U
#define PTESE_PTESE2_MASK               4U
#define PTESE_PTESE3_MASK               8U
#define PTESE_PTESE4_MASK               16U
#define PTESE_PTESE5_MASK               32U
#define PTESE_PTESE6_MASK               64U
#define PTESE_PTESE7_MASK               128U


/*** PTEDS - Port E Drive Strength Selection Register; 0xFFFF9852 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEDS0      :1;                                       /* Output Drive Strength Selection for Port E Bit 0 */
    byte PTEDS1      :1;                                       /* Output Drive Strength Selection for Port E Bit 1 */
    byte PTEDS2      :1;                                       /* Output Drive Strength Selection for Port E Bit 2 */
    byte PTEDS3      :1;                                       /* Output Drive Strength Selection for Port E Bit 3 */
    byte PTEDS4      :1;                                       /* Output Drive Strength Selection for Port E Bit 4 */
    byte PTEDS5      :1;                                       /* Output Drive Strength Selection for Port E Bit 5 */
    byte PTEDS6      :1;                                       /* Output Drive Strength Selection for Port E Bit 6 */
    byte PTEDS7      :1;                                       /* Output Drive Strength Selection for Port E Bit 7 */
  } Bits;
} PTEDSSTR;
#define _PTEDS (*(volatile PTEDSSTR *)0xFFFF9852)
#define PTEDS                           _PTEDS.Byte
#define PTEDS_PTEDS0                    _PTEDS.Bits.PTEDS0
#define PTEDS_PTEDS1                    _PTEDS.Bits.PTEDS1
#define PTEDS_PTEDS2                    _PTEDS.Bits.PTEDS2
#define PTEDS_PTEDS3                    _PTEDS.Bits.PTEDS3
#define PTEDS_PTEDS4                    _PTEDS.Bits.PTEDS4
#define PTEDS_PTEDS5                    _PTEDS.Bits.PTEDS5
#define PTEDS_PTEDS6                    _PTEDS.Bits.PTEDS6
#define PTEDS_PTEDS7                    _PTEDS.Bits.PTEDS7

#define PTEDS_PTEDS0_MASK               1U
#define PTEDS_PTEDS1_MASK               2U
#define PTEDS_PTEDS2_MASK               4U
#define PTEDS_PTEDS3_MASK               8U
#define PTEDS_PTEDS4_MASK               16U
#define PTEDS_PTEDS5_MASK               32U
#define PTEDS_PTEDS6_MASK               64U
#define PTEDS_PTEDS7_MASK               128U


/*** PTEIFE - Port E Input Filter Enable Register; 0xFFFF9853 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEIFE0     :1;                                       /* Port E Input Filter Enable Bit 0 */
    byte PTEIFE1     :1;                                       /* Port E Input Filter Enable Bit 1 */
    byte PTEIFE2     :1;                                       /* Port E Input Filter Enable Bit 2 */
    byte PTEIFE3     :1;                                       /* Port E Input Filter Enable Bit 3 */
    byte PTEIFE4     :1;                                       /* Port E Input Filter Enable Bit 4 */
    byte PTEIFE5     :1;                                       /* Port E Input Filter Enable Bit 5 */
    byte PTEIFE6     :1;                                       /* Port E Input Filter Enable Bit 6 */
    byte PTEIFE7     :1;                                       /* Port E Input Filter Enable Bit 7 */
  } Bits;
} PTEIFESTR;
#define _PTEIFE (*(volatile PTEIFESTR *)0xFFFF9853)
#define PTEIFE                          _PTEIFE.Byte
#define PTEIFE_PTEIFE0                  _PTEIFE.Bits.PTEIFE0
#define PTEIFE_PTEIFE1                  _PTEIFE.Bits.PTEIFE1
#define PTEIFE_PTEIFE2                  _PTEIFE.Bits.PTEIFE2
#define PTEIFE_PTEIFE3                  _PTEIFE.Bits.PTEIFE3
#define PTEIFE_PTEIFE4                  _PTEIFE.Bits.PTEIFE4
#define PTEIFE_PTEIFE5                  _PTEIFE.Bits.PTEIFE5
#define PTEIFE_PTEIFE6                  _PTEIFE.Bits.PTEIFE6
#define PTEIFE_PTEIFE7                  _PTEIFE.Bits.PTEIFE7

#define PTEIFE_PTEIFE0_MASK             1U
#define PTEIFE_PTEIFE1_MASK             2U
#define PTEIFE_PTEIFE2_MASK             4U
#define PTEIFE_PTEIFE3_MASK             8U
#define PTEIFE_PTEIFE4_MASK             16U
#define PTEIFE_PTEIFE5_MASK             32U
#define PTEIFE_PTEIFE6_MASK             64U
#define PTEIFE_PTEIFE7_MASK             128U


/*** PTFPE - Port F Pull Enable Register; 0xFFFF9854 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFPE0      :1;                                       /* Internal Pull Enable for Port F Bit 0 */
    byte PTFPE1      :1;                                       /* Internal Pull Enable for Port F Bit 1 */
    byte PTFPE2      :1;                                       /* Internal Pull Enable for Port F Bit 2 */
    byte PTFPE3      :1;                                       /* Internal Pull Enable for Port F Bit 3 */
    byte PTFPE4      :1;                                       /* Internal Pull Enable for Port F Bit 4 */
    byte PTFPE5      :1;                                       /* Internal Pull Enable for Port F Bit 5 */
    byte PTFPE6      :1;                                       /* Internal Pull Enable for Port F Bit 6 */
    byte PTFPE7      :1;                                       /* Internal Pull Enable for Port F Bit 7 */
  } Bits;
} PTFPESTR;
#define _PTFPE (*(volatile PTFPESTR *)0xFFFF9854)
#define PTFPE                           _PTFPE.Byte
#define PTFPE_PTFPE0                    _PTFPE.Bits.PTFPE0
#define PTFPE_PTFPE1                    _PTFPE.Bits.PTFPE1
#define PTFPE_PTFPE2                    _PTFPE.Bits.PTFPE2
#define PTFPE_PTFPE3                    _PTFPE.Bits.PTFPE3
#define PTFPE_PTFPE4                    _PTFPE.Bits.PTFPE4
#define PTFPE_PTFPE5                    _PTFPE.Bits.PTFPE5
#define PTFPE_PTFPE6                    _PTFPE.Bits.PTFPE6
#define PTFPE_PTFPE7                    _PTFPE.Bits.PTFPE7

#define PTFPE_PTFPE0_MASK               1U
#define PTFPE_PTFPE1_MASK               2U
#define PTFPE_PTFPE2_MASK               4U
#define PTFPE_PTFPE3_MASK               8U
#define PTFPE_PTFPE4_MASK               16U
#define PTFPE_PTFPE5_MASK               32U
#define PTFPE_PTFPE6_MASK               64U
#define PTFPE_PTFPE7_MASK               128U


/*** PTFSE - Port F Slew Rate Enable Register; 0xFFFF9855 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFSE0      :1;                                       /* Output Slew Rate Enable for Port F Bit 0 */
    byte PTFSE1      :1;                                       /* Output Slew Rate Enable for Port F Bit 1 */
    byte PTFSE2      :1;                                       /* Output Slew Rate Enable for Port F Bit 2 */
    byte PTFSE3      :1;                                       /* Output Slew Rate Enable for Port F Bit 3 */
    byte PTFSE4      :1;                                       /* Output Slew Rate Enable for Port F Bit 4 */
    byte PTFSE5      :1;                                       /* Output Slew Rate Enable for Port F Bit 5 */
    byte PTFSE6      :1;                                       /* Output Slew Rate Enable for Port F Bit 6 */
    byte PTFSE7      :1;                                       /* Output Slew Rate Enable for Port F Bit 7 */
  } Bits;
} PTFSESTR;
#define _PTFSE (*(volatile PTFSESTR *)0xFFFF9855)
#define PTFSE                           _PTFSE.Byte
#define PTFSE_PTFSE0                    _PTFSE.Bits.PTFSE0
#define PTFSE_PTFSE1                    _PTFSE.Bits.PTFSE1
#define PTFSE_PTFSE2                    _PTFSE.Bits.PTFSE2
#define PTFSE_PTFSE3                    _PTFSE.Bits.PTFSE3
#define PTFSE_PTFSE4                    _PTFSE.Bits.PTFSE4
#define PTFSE_PTFSE5                    _PTFSE.Bits.PTFSE5
#define PTFSE_PTFSE6                    _PTFSE.Bits.PTFSE6
#define PTFSE_PTFSE7                    _PTFSE.Bits.PTFSE7

#define PTFSE_PTFSE0_MASK               1U
#define PTFSE_PTFSE1_MASK               2U
#define PTFSE_PTFSE2_MASK               4U
#define PTFSE_PTFSE3_MASK               8U
#define PTFSE_PTFSE4_MASK               16U
#define PTFSE_PTFSE5_MASK               32U
#define PTFSE_PTFSE6_MASK               64U
#define PTFSE_PTFSE7_MASK               128U


/*** PTFDS - Port F Drive Strength Selection Register; 0xFFFF9856 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFDS0      :1;                                       /* Output Drive Strength Selection for Port F Bit 0 */
    byte PTFDS1      :1;                                       /* Output Drive Strength Selection for Port F Bit 1 */
    byte PTFDS2      :1;                                       /* Output Drive Strength Selection for Port F Bit 2 */
    byte PTFDS3      :1;                                       /* Output Drive Strength Selection for Port F Bit 3 */
    byte PTFDS4      :1;                                       /* Output Drive Strength Selection for Port F Bit 4 */
    byte PTFDS5      :1;                                       /* Output Drive Strength Selection for Port F Bit 5 */
    byte PTFDS6      :1;                                       /* Output Drive Strength Selection for Port F Bit 6 */
    byte PTFDS7      :1;                                       /* Output Drive Strength Selection for Port F Bit 7 */
  } Bits;
} PTFDSSTR;
#define _PTFDS (*(volatile PTFDSSTR *)0xFFFF9856)
#define PTFDS                           _PTFDS.Byte
#define PTFDS_PTFDS0                    _PTFDS.Bits.PTFDS0
#define PTFDS_PTFDS1                    _PTFDS.Bits.PTFDS1
#define PTFDS_PTFDS2                    _PTFDS.Bits.PTFDS2
#define PTFDS_PTFDS3                    _PTFDS.Bits.PTFDS3
#define PTFDS_PTFDS4                    _PTFDS.Bits.PTFDS4
#define PTFDS_PTFDS5                    _PTFDS.Bits.PTFDS5
#define PTFDS_PTFDS6                    _PTFDS.Bits.PTFDS6
#define PTFDS_PTFDS7                    _PTFDS.Bits.PTFDS7

#define PTFDS_PTFDS0_MASK               1U
#define PTFDS_PTFDS1_MASK               2U
#define PTFDS_PTFDS2_MASK               4U
#define PTFDS_PTFDS3_MASK               8U
#define PTFDS_PTFDS4_MASK               16U
#define PTFDS_PTFDS5_MASK               32U
#define PTFDS_PTFDS6_MASK               64U
#define PTFDS_PTFDS7_MASK               128U


/*** PTFIFE - Port F Input Filter Enable Register; 0xFFFF9857 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFIFE0     :1;                                       /* Port F Input Filter Enable Bit 0 */
    byte PTFIFE1     :1;                                       /* Port F Input Filter Enable Bit 1 */
    byte PTFIFE2     :1;                                       /* Port F Input Filter Enable Bit 2 */
    byte PTFIFE3     :1;                                       /* Port F Input Filter Enable Bit 3 */
    byte PTFIFE4     :1;                                       /* Port F Input Filter Enable Bit 4 */
    byte PTFIFE5     :1;                                       /* Port F Input Filter Enable Bit 5 */
    byte PTFIFE6     :1;                                       /* Port F Input Filter Enable Bit 6 */
    byte PTFIFE7     :1;                                       /* Port F Input Filter Enable Bit 7 */
  } Bits;
} PTFIFESTR;
#define _PTFIFE (*(volatile PTFIFESTR *)0xFFFF9857)
#define PTFIFE                          _PTFIFE.Byte
#define PTFIFE_PTFIFE0                  _PTFIFE.Bits.PTFIFE0
#define PTFIFE_PTFIFE1                  _PTFIFE.Bits.PTFIFE1
#define PTFIFE_PTFIFE2                  _PTFIFE.Bits.PTFIFE2
#define PTFIFE_PTFIFE3                  _PTFIFE.Bits.PTFIFE3
#define PTFIFE_PTFIFE4                  _PTFIFE.Bits.PTFIFE4
#define PTFIFE_PTFIFE5                  _PTFIFE.Bits.PTFIFE5
#define PTFIFE_PTFIFE6                  _PTFIFE.Bits.PTFIFE6
#define PTFIFE_PTFIFE7                  _PTFIFE.Bits.PTFIFE7

#define PTFIFE_PTFIFE0_MASK             1U
#define PTFIFE_PTFIFE1_MASK             2U
#define PTFIFE_PTFIFE2_MASK             4U
#define PTFIFE_PTFIFE3_MASK             8U
#define PTFIFE_PTFIFE4_MASK             16U
#define PTFIFE_PTFIFE5_MASK             32U
#define PTFIFE_PTFIFE6_MASK             64U
#define PTFIFE_PTFIFE7_MASK             128U


/*** PTGPE - Port G Pull Enable Register; 0xFFFF9858 ***/
typedef union {
  byte Byte;
  struct {
    byte PTGPE0      :1;                                       /* Internal Pull Enable for Port G Bit 0 */
    byte PTGPE1      :1;                                       /* Internal Pull Enable for Port G Bit 1 */
    byte PTGPE2      :1;                                       /* Internal Pull Enable for Port G Bit 2 */
    byte PTGPE3      :1;                                       /* Internal Pull Enable for Port G Bit 3 */
    byte PTGPE4      :1;                                       /* Internal Pull Enable for Port G Bit 4 */
    byte PTGPE5      :1;                                       /* Internal Pull Enable for Port G Bit 5 */
    byte PTGPE6      :1;                                       /* Internal Pull Enable for Port G Bit 6 */
    byte PTGPE7      :1;                                       /* Internal Pull Enable for Port G Bit 7 */
  } Bits;
} PTGPESTR;
#define _PTGPE (*(volatile PTGPESTR *)0xFFFF9858)
#define PTGPE                           _PTGPE.Byte
#define PTGPE_PTGPE0                    _PTGPE.Bits.PTGPE0
#define PTGPE_PTGPE1                    _PTGPE.Bits.PTGPE1
#define PTGPE_PTGPE2                    _PTGPE.Bits.PTGPE2
#define PTGPE_PTGPE3                    _PTGPE.Bits.PTGPE3
#define PTGPE_PTGPE4                    _PTGPE.Bits.PTGPE4
#define PTGPE_PTGPE5                    _PTGPE.Bits.PTGPE5
#define PTGPE_PTGPE6                    _PTGPE.Bits.PTGPE6
#define PTGPE_PTGPE7                    _PTGPE.Bits.PTGPE7

#define PTGPE_PTGPE0_MASK               1U
#define PTGPE_PTGPE1_MASK               2U
#define PTGPE_PTGPE2_MASK               4U
#define PTGPE_PTGPE3_MASK               8U
#define PTGPE_PTGPE4_MASK               16U
#define PTGPE_PTGPE5_MASK               32U
#define PTGPE_PTGPE6_MASK               64U
#define PTGPE_PTGPE7_MASK               128U


/*** PTGSE - Port G Slew Rate Enable Register; 0xFFFF9859 ***/
typedef union {
  byte Byte;
  struct {
    byte PTGSE0      :1;                                       /* Output Slew Rate Enable for Port G Bit 0 */
    byte PTGSE1      :1;                                       /* Output Slew Rate Enable for Port G Bit 1 */
    byte PTGSE2      :1;                                       /* Output Slew Rate Enable for Port G Bit 2 */
    byte PTGSE3      :1;                                       /* Output Slew Rate Enable for Port G Bit 3 */
    byte PTGSE4      :1;                                       /* Output Slew Rate Enable for Port G Bit 4 */
    byte PTGSE5      :1;                                       /* Output Slew Rate Enable for Port G Bit 5 */
    byte PTGSE6      :1;                                       /* Output Slew Rate Enable for Port G Bit 6 */
    byte PTGSE7      :1;                                       /* Output Slew Rate Enable for Port G Bit 7 */
  } Bits;
} PTGSESTR;
#define _PTGSE (*(volatile PTGSESTR *)0xFFFF9859)
#define PTGSE                           _PTGSE.Byte
#define PTGSE_PTGSE0                    _PTGSE.Bits.PTGSE0
#define PTGSE_PTGSE1                    _PTGSE.Bits.PTGSE1
#define PTGSE_PTGSE2                    _PTGSE.Bits.PTGSE2
#define PTGSE_PTGSE3                    _PTGSE.Bits.PTGSE3
#define PTGSE_PTGSE4                    _PTGSE.Bits.PTGSE4
#define PTGSE_PTGSE5                    _PTGSE.Bits.PTGSE5
#define PTGSE_PTGSE6                    _PTGSE.Bits.PTGSE6
#define PTGSE_PTGSE7                    _PTGSE.Bits.PTGSE7

#define PTGSE_PTGSE0_MASK               1U
#define PTGSE_PTGSE1_MASK               2U
#define PTGSE_PTGSE2_MASK               4U
#define PTGSE_PTGSE3_MASK               8U
#define PTGSE_PTGSE4_MASK               16U
#define PTGSE_PTGSE5_MASK               32U
#define PTGSE_PTGSE6_MASK               64U
#define PTGSE_PTGSE7_MASK               128U


/*** PTGDS - Port G Drive Strength Selection Register; 0xFFFF985A ***/
typedef union {
  byte Byte;
  struct {
    byte PTGDS0      :1;                                       /* Output Drive Strength Selection for Port G Bit 0 */
    byte PTGDS1      :1;                                       /* Output Drive Strength Selection for Port G Bit 1 */
    byte PTGDS2      :1;                                       /* Output Drive Strength Selection for Port G Bit 2 */
    byte PTGDS3      :1;                                       /* Output Drive Strength Selection for Port G Bit 3 */
    byte PTGDS4      :1;                                       /* Output Drive Strength Selection for Port G Bit 4 */
    byte PTGDS5      :1;                                       /* Output Drive Strength Selection for Port G Bit 5 */
    byte PTGDS6      :1;                                       /* Output Drive Strength Selection for Port G Bit 6 */
    byte PTGDS7      :1;                                       /* Output Drive Strength Selection for Port G Bit 7 */
  } Bits;
} PTGDSSTR;
#define _PTGDS (*(volatile PTGDSSTR *)0xFFFF985A)
#define PTGDS                           _PTGDS.Byte
#define PTGDS_PTGDS0                    _PTGDS.Bits.PTGDS0
#define PTGDS_PTGDS1                    _PTGDS.Bits.PTGDS1
#define PTGDS_PTGDS2                    _PTGDS.Bits.PTGDS2
#define PTGDS_PTGDS3                    _PTGDS.Bits.PTGDS3
#define PTGDS_PTGDS4                    _PTGDS.Bits.PTGDS4
#define PTGDS_PTGDS5                    _PTGDS.Bits.PTGDS5
#define PTGDS_PTGDS6                    _PTGDS.Bits.PTGDS6
#define PTGDS_PTGDS7                    _PTGDS.Bits.PTGDS7

#define PTGDS_PTGDS0_MASK               1U
#define PTGDS_PTGDS1_MASK               2U
#define PTGDS_PTGDS2_MASK               4U
#define PTGDS_PTGDS3_MASK               8U
#define PTGDS_PTGDS4_MASK               16U
#define PTGDS_PTGDS5_MASK               32U
#define PTGDS_PTGDS6_MASK               64U
#define PTGDS_PTGDS7_MASK               128U


/*** PTGIFE - Port G Input Filter Enable Register; 0xFFFF985B ***/
typedef union {
  byte Byte;
  struct {
    byte PTGIFE0     :1;                                       /* Port G Input Filter Enable Bit 0 */
    byte PTGIFE1     :1;                                       /* Port G Input Filter Enable Bit 1 */
    byte PTGIFE2     :1;                                       /* Port G Input Filter Enable Bit 2 */
    byte PTGIFE3     :1;                                       /* Port G Input Filter Enable Bit 3 */
    byte PTGIFE4     :1;                                       /* Port G Input Filter Enable Bit 4 */
    byte PTGIFE5     :1;                                       /* Port G Input Filter Enable Bit 5 */
    byte PTGIFE6     :1;                                       /* Port G Input Filter Enable Bit 6 */
    byte PTGIFE7     :1;                                       /* Port G Input Filter Enable Bit 7 */
  } Bits;
} PTGIFESTR;
#define _PTGIFE (*(volatile PTGIFESTR *)0xFFFF985B)
#define PTGIFE                          _PTGIFE.Byte
#define PTGIFE_PTGIFE0                  _PTGIFE.Bits.PTGIFE0
#define PTGIFE_PTGIFE1                  _PTGIFE.Bits.PTGIFE1
#define PTGIFE_PTGIFE2                  _PTGIFE.Bits.PTGIFE2
#define PTGIFE_PTGIFE3                  _PTGIFE.Bits.PTGIFE3
#define PTGIFE_PTGIFE4                  _PTGIFE.Bits.PTGIFE4
#define PTGIFE_PTGIFE5                  _PTGIFE.Bits.PTGIFE5
#define PTGIFE_PTGIFE6                  _PTGIFE.Bits.PTGIFE6
#define PTGIFE_PTGIFE7                  _PTGIFE.Bits.PTGIFE7

#define PTGIFE_PTGIFE0_MASK             1U
#define PTGIFE_PTGIFE1_MASK             2U
#define PTGIFE_PTGIFE2_MASK             4U
#define PTGIFE_PTGIFE3_MASK             8U
#define PTGIFE_PTGIFE4_MASK             16U
#define PTGIFE_PTGIFE5_MASK             32U
#define PTGIFE_PTGIFE6_MASK             64U
#define PTGIFE_PTGIFE7_MASK             128U


/*** PTHPE - Port H Pull Enable Register; 0xFFFF985C ***/
typedef union {
  byte Byte;
  struct {
    byte PTHPE0      :1;                                       /* Internal Pull Enable for Port H Bit 0 */
    byte PTHPE1      :1;                                       /* Internal Pull Enable for Port H Bit 1 */
    byte PTHPE2      :1;                                       /* Internal Pull Enable for Port H Bit 2 */
    byte PTHPE3      :1;                                       /* Internal Pull Enable for Port H Bit 3 */
    byte PTHPE4      :1;                                       /* Internal Pull Enable for Port H Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTHPE :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTHPESTR;
#define _PTHPE (*(volatile PTHPESTR *)0xFFFF985C)
#define PTHPE                           _PTHPE.Byte
#define PTHPE_PTHPE0                    _PTHPE.Bits.PTHPE0
#define PTHPE_PTHPE1                    _PTHPE.Bits.PTHPE1
#define PTHPE_PTHPE2                    _PTHPE.Bits.PTHPE2
#define PTHPE_PTHPE3                    _PTHPE.Bits.PTHPE3
#define PTHPE_PTHPE4                    _PTHPE.Bits.PTHPE4
#define PTHPE_PTHPE                     _PTHPE.MergedBits.grpPTHPE

#define PTHPE_PTHPE0_MASK               1U
#define PTHPE_PTHPE1_MASK               2U
#define PTHPE_PTHPE2_MASK               4U
#define PTHPE_PTHPE3_MASK               8U
#define PTHPE_PTHPE4_MASK               16U
#define PTHPE_PTHPE_MASK                31U
#define PTHPE_PTHPE_BITNUM              0U


/*** PTHSE - Port H Slew Rate Enable Register; 0xFFFF985D ***/
typedef union {
  byte Byte;
  struct {
    byte PTHSE0      :1;                                       /* Output Slew Rate Enable for Port H Bit 0 */
    byte PTHSE1      :1;                                       /* Output Slew Rate Enable for Port H Bit 1 */
    byte PTHSE2      :1;                                       /* Output Slew Rate Enable for Port H Bit 2 */
    byte PTHSE3      :1;                                       /* Output Slew Rate Enable for Port H Bit 3 */
    byte PTHSE4      :1;                                       /* Output Slew Rate Enable for Port H Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTHSE :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTHSESTR;
#define _PTHSE (*(volatile PTHSESTR *)0xFFFF985D)
#define PTHSE                           _PTHSE.Byte
#define PTHSE_PTHSE0                    _PTHSE.Bits.PTHSE0
#define PTHSE_PTHSE1                    _PTHSE.Bits.PTHSE1
#define PTHSE_PTHSE2                    _PTHSE.Bits.PTHSE2
#define PTHSE_PTHSE3                    _PTHSE.Bits.PTHSE3
#define PTHSE_PTHSE4                    _PTHSE.Bits.PTHSE4
#define PTHSE_PTHSE                     _PTHSE.MergedBits.grpPTHSE

#define PTHSE_PTHSE0_MASK               1U
#define PTHSE_PTHSE1_MASK               2U
#define PTHSE_PTHSE2_MASK               4U
#define PTHSE_PTHSE3_MASK               8U
#define PTHSE_PTHSE4_MASK               16U
#define PTHSE_PTHSE_MASK                31U
#define PTHSE_PTHSE_BITNUM              0U


/*** PTHDS - Port H Drive Strength Selection Register; 0xFFFF985E ***/
typedef union {
  byte Byte;
  struct {
    byte PTHDS0      :1;                                       /* Output Drive Strength Selection for Port H Bit 0 */
    byte PTHDS1      :1;                                       /* Output Drive Strength Selection for Port H Bit 1 */
    byte PTHDS2      :1;                                       /* Output Drive Strength Selection for Port H Bit 2 */
    byte PTHDS3      :1;                                       /* Output Drive Strength Selection for Port H Bit 3 */
    byte PTHDS4      :1;                                       /* Output Drive Strength Selection for Port H Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTHDS :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTHDSSTR;
#define _PTHDS (*(volatile PTHDSSTR *)0xFFFF985E)
#define PTHDS                           _PTHDS.Byte
#define PTHDS_PTHDS0                    _PTHDS.Bits.PTHDS0
#define PTHDS_PTHDS1                    _PTHDS.Bits.PTHDS1
#define PTHDS_PTHDS2                    _PTHDS.Bits.PTHDS2
#define PTHDS_PTHDS3                    _PTHDS.Bits.PTHDS3
#define PTHDS_PTHDS4                    _PTHDS.Bits.PTHDS4
#define PTHDS_PTHDS                     _PTHDS.MergedBits.grpPTHDS

#define PTHDS_PTHDS0_MASK               1U
#define PTHDS_PTHDS1_MASK               2U
#define PTHDS_PTHDS2_MASK               4U
#define PTHDS_PTHDS3_MASK               8U
#define PTHDS_PTHDS4_MASK               16U
#define PTHDS_PTHDS_MASK                31U
#define PTHDS_PTHDS_BITNUM              0U


/*** PTHIFE - Port H Input Filter Enable Register; 0xFFFF985F ***/
typedef union {
  byte Byte;
  struct {
    byte PTHIFE0     :1;                                       /* Port H Input Filter Enable Bit 0 */
    byte PTHIFE1     :1;                                       /* Port H Input Filter Enable Bit 1 */
    byte PTHIFE2     :1;                                       /* Port H Input Filter Enable Bit 2 */
    byte PTHIFE3     :1;                                       /* Port H Input Filter Enable Bit 3 */
    byte PTHIFE4     :1;                                       /* Port H Input Filter Enable Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTHIFE :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTHIFESTR;
#define _PTHIFE (*(volatile PTHIFESTR *)0xFFFF985F)
#define PTHIFE                          _PTHIFE.Byte
#define PTHIFE_PTHIFE0                  _PTHIFE.Bits.PTHIFE0
#define PTHIFE_PTHIFE1                  _PTHIFE.Bits.PTHIFE1
#define PTHIFE_PTHIFE2                  _PTHIFE.Bits.PTHIFE2
#define PTHIFE_PTHIFE3                  _PTHIFE.Bits.PTHIFE3
#define PTHIFE_PTHIFE4                  _PTHIFE.Bits.PTHIFE4
#define PTHIFE_PTHIFE                   _PTHIFE.MergedBits.grpPTHIFE

#define PTHIFE_PTHIFE0_MASK             1U
#define PTHIFE_PTHIFE1_MASK             2U
#define PTHIFE_PTHIFE2_MASK             4U
#define PTHIFE_PTHIFE3_MASK             8U
#define PTHIFE_PTHIFE4_MASK             16U
#define PTHIFE_PTHIFE_MASK              31U
#define PTHIFE_PTHIFE_BITNUM            0U


/*** PTJPE - Port J Pull Enable Register; 0xFFFF9860 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJPE0      :1;                                       /* Internal Pull Enable for Port J Bit 0 */
    byte PTJPE1      :1;                                       /* Internal Pull Enable for Port J Bit 1 */
    byte PTJPE2      :1;                                       /* Internal Pull Enable for Port J Bit 2 */
    byte PTJPE3      :1;                                       /* Internal Pull Enable for Port J Bit 3 */
    byte PTJPE4      :1;                                       /* Internal Pull Enable for Port J Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTJPE :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTJPESTR;
#define _PTJPE (*(volatile PTJPESTR *)0xFFFF9860)
#define PTJPE                           _PTJPE.Byte
#define PTJPE_PTJPE0                    _PTJPE.Bits.PTJPE0
#define PTJPE_PTJPE1                    _PTJPE.Bits.PTJPE1
#define PTJPE_PTJPE2                    _PTJPE.Bits.PTJPE2
#define PTJPE_PTJPE3                    _PTJPE.Bits.PTJPE3
#define PTJPE_PTJPE4                    _PTJPE.Bits.PTJPE4
#define PTJPE_PTJPE                     _PTJPE.MergedBits.grpPTJPE

#define PTJPE_PTJPE0_MASK               1U
#define PTJPE_PTJPE1_MASK               2U
#define PTJPE_PTJPE2_MASK               4U
#define PTJPE_PTJPE3_MASK               8U
#define PTJPE_PTJPE4_MASK               16U
#define PTJPE_PTJPE_MASK                31U
#define PTJPE_PTJPE_BITNUM              0U


/*** PTJSE - Port J Slew Rate Enable Register; 0xFFFF9861 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJSE0      :1;                                       /* Output Slew Rate Enable for Port J Bit 0 */
    byte PTJSE1      :1;                                       /* Output Slew Rate Enable for Port J Bit 1 */
    byte PTJSE2      :1;                                       /* Output Slew Rate Enable for Port J Bit 2 */
    byte PTJSE3      :1;                                       /* Output Slew Rate Enable for Port J Bit 3 */
    byte PTJSE4      :1;                                       /* Output Slew Rate Enable for Port J Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTJSE :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTJSESTR;
#define _PTJSE (*(volatile PTJSESTR *)0xFFFF9861)
#define PTJSE                           _PTJSE.Byte
#define PTJSE_PTJSE0                    _PTJSE.Bits.PTJSE0
#define PTJSE_PTJSE1                    _PTJSE.Bits.PTJSE1
#define PTJSE_PTJSE2                    _PTJSE.Bits.PTJSE2
#define PTJSE_PTJSE3                    _PTJSE.Bits.PTJSE3
#define PTJSE_PTJSE4                    _PTJSE.Bits.PTJSE4
#define PTJSE_PTJSE                     _PTJSE.MergedBits.grpPTJSE

#define PTJSE_PTJSE0_MASK               1U
#define PTJSE_PTJSE1_MASK               2U
#define PTJSE_PTJSE2_MASK               4U
#define PTJSE_PTJSE3_MASK               8U
#define PTJSE_PTJSE4_MASK               16U
#define PTJSE_PTJSE_MASK                31U
#define PTJSE_PTJSE_BITNUM              0U


/*** PTJDS - Port J Drive Strength Selection Register; 0xFFFF9862 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJDS0      :1;                                       /* Output Drive Strength Selection for Port J Bit 0 */
    byte PTJDS1      :1;                                       /* Output Drive Strength Selection for Port J Bit 1 */
    byte PTJDS2      :1;                                       /* Output Drive Strength Selection for Port J Bit 2 */
    byte PTJDS3      :1;                                       /* Output Drive Strength Selection for Port J Bit 3 */
    byte PTJDS4      :1;                                       /* Output Drive Strength Selection for Port J Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTJDS :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTJDSSTR;
#define _PTJDS (*(volatile PTJDSSTR *)0xFFFF9862)
#define PTJDS                           _PTJDS.Byte
#define PTJDS_PTJDS0                    _PTJDS.Bits.PTJDS0
#define PTJDS_PTJDS1                    _PTJDS.Bits.PTJDS1
#define PTJDS_PTJDS2                    _PTJDS.Bits.PTJDS2
#define PTJDS_PTJDS3                    _PTJDS.Bits.PTJDS3
#define PTJDS_PTJDS4                    _PTJDS.Bits.PTJDS4
#define PTJDS_PTJDS                     _PTJDS.MergedBits.grpPTJDS

#define PTJDS_PTJDS0_MASK               1U
#define PTJDS_PTJDS1_MASK               2U
#define PTJDS_PTJDS2_MASK               4U
#define PTJDS_PTJDS3_MASK               8U
#define PTJDS_PTJDS4_MASK               16U
#define PTJDS_PTJDS_MASK                31U
#define PTJDS_PTJDS_BITNUM              0U


/*** PTJIFE - Port J Input Filter Enable Register; 0xFFFF9863 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJIFE0     :1;                                       /* Port J Input Filter Enable Bit 0 */
    byte PTJIFE1     :1;                                       /* Port J Input Filter Enable Bit 1 */
    byte PTJIFE2     :1;                                       /* Port J Input Filter Enable Bit 2 */
    byte PTJIFE3     :1;                                       /* Port J Input Filter Enable Bit 3 */
    byte PTJIFE4     :1;                                       /* Port J Input Filter Enable Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTJIFE :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTJIFESTR;
#define _PTJIFE (*(volatile PTJIFESTR *)0xFFFF9863)
#define PTJIFE                          _PTJIFE.Byte
#define PTJIFE_PTJIFE0                  _PTJIFE.Bits.PTJIFE0
#define PTJIFE_PTJIFE1                  _PTJIFE.Bits.PTJIFE1
#define PTJIFE_PTJIFE2                  _PTJIFE.Bits.PTJIFE2
#define PTJIFE_PTJIFE3                  _PTJIFE.Bits.PTJIFE3
#define PTJIFE_PTJIFE4                  _PTJIFE.Bits.PTJIFE4
#define PTJIFE_PTJIFE                   _PTJIFE.MergedBits.grpPTJIFE

#define PTJIFE_PTJIFE0_MASK             1U
#define PTJIFE_PTJIFE1_MASK             2U
#define PTJIFE_PTJIFE2_MASK             4U
#define PTJIFE_PTJIFE3_MASK             8U
#define PTJIFE_PTJIFE4_MASK             16U
#define PTJIFE_PTJIFE_MASK              31U
#define PTJIFE_PTJIFE_BITNUM            0U


/*** CMTCG1 - Carrier Generator Data Register 1; 0xFFFF9868 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CMTCGH1 - CMT Carrier Generator Data Register 1 High Byte; 0xFFFF9868 ***/
    union {
      byte Byte;
    } CMTCGH1STR;
    #define CMTCGH1                     _CMTCG1.Overlap_STR.CMTCGH1STR.Byte
    

    /*** CMTCGL1 - CMT Carrier Generator Data Register 1 Low Byte; 0xFFFF9869 ***/
    union {
      byte Byte;
    } CMTCGL1STR;
    #define CMTCGL1                     _CMTCG1.Overlap_STR.CMTCGL1STR.Byte
    
  } Overlap_STR;

  struct {
    word PL0         :1;                                       /* Primary Carrier Low Time Data Value Bit 0 */
    word PL1         :1;                                       /* Primary Carrier Low Time Data Value Bit 1 */
    word PL2         :1;                                       /* Primary Carrier Low Time Data Value Bit 2 */
    word PL3         :1;                                       /* Primary Carrier Low Time Data Value Bit 3 */
    word PL4         :1;                                       /* Primary Carrier Low Time Data Value Bit 4 */
    word PL5         :1;                                       /* Primary Carrier Low Time Data Value Bit 5 */
    word PL6         :1;                                       /* Primary Carrier Low Time Data Value Bit 6 */
    word PL7         :1;                                       /* Primary Carrier Low Time Data Value Bit 0 */
    word PH0         :1;                                       /* Primary Carrier High Time Data Value Bit 0 */
    word PH1         :1;                                       /* Primary Carrier High Time Data Value Bit 1 */
    word PH2         :1;                                       /* Primary Carrier High Time Data Value Bit 2 */
    word PH3         :1;                                       /* Primary Carrier High Time Data Value Bit 3 */
    word PH4         :1;                                       /* Primary Carrier High Time Data Value Bit 4 */
    word PH5         :1;                                       /* Primary Carrier High Time Data Value Bit 5 */
    word PH6         :1;                                       /* Primary Carrier High Time Data Value Bit 6 */
    word PH7         :1;                                       /* Primary Carrier High Time Data Value Bit 7 */
  } Bits;
  struct {
    word grpPL   :8;
    word grpPH   :8;
  } MergedBits;
} CMTCG1STR;
#define _CMTCG1 (*(volatile CMTCG1STR *)0xFFFF9868)
#define CMTCG1                          _CMTCG1.Word
#define CMTCG1_PL0                      _CMTCG1.Bits.PL0
#define CMTCG1_PL1                      _CMTCG1.Bits.PL1
#define CMTCG1_PL2                      _CMTCG1.Bits.PL2
#define CMTCG1_PL3                      _CMTCG1.Bits.PL3
#define CMTCG1_PL4                      _CMTCG1.Bits.PL4
#define CMTCG1_PL5                      _CMTCG1.Bits.PL5
#define CMTCG1_PL6                      _CMTCG1.Bits.PL6
#define CMTCG1_PL7                      _CMTCG1.Bits.PL7
#define CMTCG1_PH0                      _CMTCG1.Bits.PH0
#define CMTCG1_PH1                      _CMTCG1.Bits.PH1
#define CMTCG1_PH2                      _CMTCG1.Bits.PH2
#define CMTCG1_PH3                      _CMTCG1.Bits.PH3
#define CMTCG1_PH4                      _CMTCG1.Bits.PH4
#define CMTCG1_PH5                      _CMTCG1.Bits.PH5
#define CMTCG1_PH6                      _CMTCG1.Bits.PH6
#define CMTCG1_PH7                      _CMTCG1.Bits.PH7
#define CMTCG1_PL                       _CMTCG1.MergedBits.grpPL
#define CMTCG1_PH                       _CMTCG1.MergedBits.grpPH

#define CMTCG1_PL0_MASK                 1U
#define CMTCG1_PL1_MASK                 2U
#define CMTCG1_PL2_MASK                 4U
#define CMTCG1_PL3_MASK                 8U
#define CMTCG1_PL4_MASK                 16U
#define CMTCG1_PL5_MASK                 32U
#define CMTCG1_PL6_MASK                 64U
#define CMTCG1_PL7_MASK                 128U
#define CMTCG1_PH0_MASK                 256U
#define CMTCG1_PH1_MASK                 512U
#define CMTCG1_PH2_MASK                 1024U
#define CMTCG1_PH3_MASK                 2048U
#define CMTCG1_PH4_MASK                 4096U
#define CMTCG1_PH5_MASK                 8192U
#define CMTCG1_PH6_MASK                 16384U
#define CMTCG1_PH7_MASK                 32768U
#define CMTCG1_PL_MASK                  255U
#define CMTCG1_PL_BITNUM                0U
#define CMTCG1_PH_MASK                  65280U
#define CMTCG1_PH_BITNUM                8U


/*** CMTCG2 - Carrier Generator Data Register 2; 0xFFFF986A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CMTCGH2 - CMT Carrier Generator Data Register 2 High Byte; 0xFFFF986A ***/
    union {
      byte Byte;
    } CMTCGH2STR;
    #define CMTCGH2                     _CMTCG2.Overlap_STR.CMTCGH2STR.Byte
    

    /*** CMTCGL2 - CMT Carrier Generator Data Register 2 Low Byte; 0xFFFF986B ***/
    union {
      byte Byte;
    } CMTCGL2STR;
    #define CMTCGL2                     _CMTCG2.Overlap_STR.CMTCGL2STR.Byte
    
  } Overlap_STR;

  struct {
    word SL0         :1;                                       /* Secondary Carrier Low Time Data Value Bit 0 */
    word SL1         :1;                                       /* Secondary Carrier Low Time Data Value Bit 1 */
    word SL2         :1;                                       /* Secondary Carrier Low Time Data Value Bit 2 */
    word SL3         :1;                                       /* Secondary Carrier Low Time Data Value Bit 3 */
    word SL4         :1;                                       /* Secondary Carrier Low Time Data Value Bit 4 */
    word SL5         :1;                                       /* Secondary Carrier Low Time Data Value Bit 5 */
    word SL6         :1;                                       /* Secondary Carrier Low Time Data Value Bit 6 */
    word SL7         :1;                                       /* Secondary Carrier Low Time Data Value Bit 7 */
    word SH0         :1;                                       /* Secondary Carrier High Time Data Value Bit 0 */
    word SH1         :1;                                       /* Secondary Carrier High Time Data Value Bit 1 */
    word SH2         :1;                                       /* Secondary Carrier High Time Data Value Bit 2 */
    word SH3         :1;                                       /* Secondary Carrier High Time Data Value Bit 3 */
    word SH4         :1;                                       /* Secondary Carrier High Time Data Value Bit 4 */
    word SH5         :1;                                       /* Secondary Carrier High Time Data Value Bit 5 */
    word SH6         :1;                                       /* Secondary Carrier High Time Data Value Bit 6 */
    word SH7         :1;                                       /* Secondary Carrier High Time Data Value Bit 7 */
  } Bits;
  struct {
    word grpSL   :8;
    word grpSH   :8;
  } MergedBits;
} CMTCG2STR;
#define _CMTCG2 (*(volatile CMTCG2STR *)0xFFFF986A)
#define CMTCG2                          _CMTCG2.Word
#define CMTCG2_SL0                      _CMTCG2.Bits.SL0
#define CMTCG2_SL1                      _CMTCG2.Bits.SL1
#define CMTCG2_SL2                      _CMTCG2.Bits.SL2
#define CMTCG2_SL3                      _CMTCG2.Bits.SL3
#define CMTCG2_SL4                      _CMTCG2.Bits.SL4
#define CMTCG2_SL5                      _CMTCG2.Bits.SL5
#define CMTCG2_SL6                      _CMTCG2.Bits.SL6
#define CMTCG2_SL7                      _CMTCG2.Bits.SL7
#define CMTCG2_SH0                      _CMTCG2.Bits.SH0
#define CMTCG2_SH1                      _CMTCG2.Bits.SH1
#define CMTCG2_SH2                      _CMTCG2.Bits.SH2
#define CMTCG2_SH3                      _CMTCG2.Bits.SH3
#define CMTCG2_SH4                      _CMTCG2.Bits.SH4
#define CMTCG2_SH5                      _CMTCG2.Bits.SH5
#define CMTCG2_SH6                      _CMTCG2.Bits.SH6
#define CMTCG2_SH7                      _CMTCG2.Bits.SH7
#define CMTCG2_SL                       _CMTCG2.MergedBits.grpSL
#define CMTCG2_SH                       _CMTCG2.MergedBits.grpSH

#define CMTCG2_SL0_MASK                 1U
#define CMTCG2_SL1_MASK                 2U
#define CMTCG2_SL2_MASK                 4U
#define CMTCG2_SL3_MASK                 8U
#define CMTCG2_SL4_MASK                 16U
#define CMTCG2_SL5_MASK                 32U
#define CMTCG2_SL6_MASK                 64U
#define CMTCG2_SL7_MASK                 128U
#define CMTCG2_SH0_MASK                 256U
#define CMTCG2_SH1_MASK                 512U
#define CMTCG2_SH2_MASK                 1024U
#define CMTCG2_SH3_MASK                 2048U
#define CMTCG2_SH4_MASK                 4096U
#define CMTCG2_SH5_MASK                 8192U
#define CMTCG2_SH6_MASK                 16384U
#define CMTCG2_SH7_MASK                 32768U
#define CMTCG2_SL_MASK                  255U
#define CMTCG2_SL_BITNUM                0U
#define CMTCG2_SH_MASK                  65280U
#define CMTCG2_SH_BITNUM                8U


/*** CMTOC - CMT Output Control Register; 0xFFFF986C ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte IROPEN      :1;                                       /* IRO pin enable */
    byte CMTPOL      :1;                                       /* CMT output polarity */
    byte IROL        :1;                                       /* IRO latch control */
  } Bits;
} CMTOCSTR;
#define _CMTOC (*(volatile CMTOCSTR *)0xFFFF986C)
#define CMTOC                           _CMTOC.Byte
#define CMTOC_IROPEN                    _CMTOC.Bits.IROPEN
#define CMTOC_CMTPOL                    _CMTOC.Bits.CMTPOL
#define CMTOC_IROL                      _CMTOC.Bits.IROL

#define CMTOC_IROPEN_MASK               32U
#define CMTOC_CMTPOL_MASK               64U
#define CMTOC_IROL_MASK                 128U


/*** CMTMSC - CMT Modulator Status and Control Register; 0xFFFF986D ***/
typedef union {
  byte Byte;
  struct {
    byte MCGEN       :1;                                       /* Modulator and Carrier Generator Enable */
    byte EOCIE       :1;                                       /* End of Cycle Interrupt Enable */
    byte FSK         :1;                                       /* FSK Mode Select */
    byte BASE        :1;                                       /* Baseband Mode Enable */
    byte EXSPC       :1;                                       /* Extended Space Enable */
    byte CMTDIV0     :1;                                       /* CMT Clock Divide Prescaler Bit 0 */
    byte CMTDIV1     :1;                                       /* CMT Clock Divide Prescaler Bit 1 */
    byte EOCF        :1;                                       /* End of Cycle Status Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpCMTDIV :2;
    byte         :1;
  } MergedBits;
} CMTMSCSTR;
#define _CMTMSC (*(volatile CMTMSCSTR *)0xFFFF986D)
#define CMTMSC                          _CMTMSC.Byte
#define CMTMSC_MCGEN                    _CMTMSC.Bits.MCGEN
#define CMTMSC_EOCIE                    _CMTMSC.Bits.EOCIE
#define CMTMSC_FSK                      _CMTMSC.Bits.FSK
#define CMTMSC_BASE                     _CMTMSC.Bits.BASE
#define CMTMSC_EXSPC                    _CMTMSC.Bits.EXSPC
#define CMTMSC_CMTDIV0                  _CMTMSC.Bits.CMTDIV0
#define CMTMSC_CMTDIV1                  _CMTMSC.Bits.CMTDIV1
#define CMTMSC_EOCF                     _CMTMSC.Bits.EOCF
#define CMTMSC_CMTDIV                   _CMTMSC.MergedBits.grpCMTDIV

#define CMTMSC_MCGEN_MASK               1U
#define CMTMSC_EOCIE_MASK               2U
#define CMTMSC_FSK_MASK                 4U
#define CMTMSC_BASE_MASK                8U
#define CMTMSC_EXSPC_MASK               16U
#define CMTMSC_CMTDIV0_MASK             32U
#define CMTMSC_CMTDIV1_MASK             64U
#define CMTMSC_EOCF_MASK                128U
#define CMTMSC_CMTDIV_MASK              96U
#define CMTMSC_CMTDIV_BITNUM            5U


/*** CMTCMD12 - CMT Modulator Data Register 12; 0xFFFF986E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CMTCMD1 - CMT Modulator Data Register 1; 0xFFFF986E ***/
    union {
      byte Byte;
    } CMTCMD1STR;
    #define CMTCMD1                     _CMTCMD12.Overlap_STR.CMTCMD1STR.Byte
    

    /*** CMTCMD2 - CMT Modulator Data Register 2; 0xFFFF986F ***/
    union {
      byte Byte;
      struct {
        byte MB0         :1;                                       /* Data Value Bit 0 */
        byte MB1         :1;                                       /* Data Value Bit 1 */
        byte MB2         :1;                                       /* Data Value Bit 2 */
        byte MB3         :1;                                       /* Data Value Bit 3 */
        byte MB4         :1;                                       /* Data Value Bit 4 */
        byte MB5         :1;                                       /* Data Value Bit 5 */
        byte MB6         :1;                                       /* Data Value Bit 6 */
        byte MB7         :1;                                       /* Data Value Bit 7 */
      } Bits;
    } CMTCMD2STR;
    #define CMTCMD2                     _CMTCMD12.Overlap_STR.CMTCMD2STR.Byte
    #define CMTCMD2_MB0                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB0
    #define CMTCMD2_MB1                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB1
    #define CMTCMD2_MB2                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB2
    #define CMTCMD2_MB3                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB3
    #define CMTCMD2_MB4                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB4
    #define CMTCMD2_MB5                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB5
    #define CMTCMD2_MB6                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB6
    #define CMTCMD2_MB7                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB7
    
    #define CMTCMD2_MB0_MASK            1U
    #define CMTCMD2_MB1_MASK            2U
    #define CMTCMD2_MB2_MASK            4U
    #define CMTCMD2_MB3_MASK            8U
    #define CMTCMD2_MB4_MASK            16U
    #define CMTCMD2_MB5_MASK            32U
    #define CMTCMD2_MB6_MASK            64U
    #define CMTCMD2_MB7_MASK            128U
    
  } Overlap_STR;

  struct {
    word MB0         :1;                                       /* Data Value Bit 0 */
    word MB1         :1;                                       /* Data Value Bit 1 */
    word MB2         :1;                                       /* Data Value Bit 2 */
    word MB3         :1;                                       /* Data Value Bit 3 */
    word MB4         :1;                                       /* Data Value Bit 4 */
    word MB5         :1;                                       /* Data Value Bit 5 */
    word MB6         :1;                                       /* Data Value Bit 6 */
    word MB7         :1;                                       /* Data Value Bit 7 */
    word MB8         :1;                                       /* Data Value Bit 8 */
    word MB9         :1;                                       /* Data Value Bit 9 */
    word MB10        :1;                                       /* Data Value Bit 10 */
    word MB11        :1;                                       /* Data Value Bit 11 */
    word MB12        :1;                                       /* Data Value Bit 12 */
    word MB13        :1;                                       /* Data Value Bit 13 */
    word MB14        :1;                                       /* Data Value Bit 14 */
    word MB15        :1;                                       /* Data Value Bit 15 */
  } Bits;
} CMTCMD12STR;
#define _CMTCMD12 (*(volatile CMTCMD12STR *)0xFFFF986E)
#define CMTCMD12                        _CMTCMD12.Word
#define CMTCMD12_MB0                    _CMTCMD12.Bits.MB0
#define CMTCMD12_MB1                    _CMTCMD12.Bits.MB1
#define CMTCMD12_MB2                    _CMTCMD12.Bits.MB2
#define CMTCMD12_MB3                    _CMTCMD12.Bits.MB3
#define CMTCMD12_MB4                    _CMTCMD12.Bits.MB4
#define CMTCMD12_MB5                    _CMTCMD12.Bits.MB5
#define CMTCMD12_MB6                    _CMTCMD12.Bits.MB6
#define CMTCMD12_MB7                    _CMTCMD12.Bits.MB7
#define CMTCMD12_MB8                    _CMTCMD12.Bits.MB8
#define CMTCMD12_MB9                    _CMTCMD12.Bits.MB9
#define CMTCMD12_MB10                   _CMTCMD12.Bits.MB10
#define CMTCMD12_MB11                   _CMTCMD12.Bits.MB11
#define CMTCMD12_MB12                   _CMTCMD12.Bits.MB12
#define CMTCMD12_MB13                   _CMTCMD12.Bits.MB13
#define CMTCMD12_MB14                   _CMTCMD12.Bits.MB14
#define CMTCMD12_MB15                   _CMTCMD12.Bits.MB15

#define CMTCMD12_MB0_MASK               1U
#define CMTCMD12_MB1_MASK               2U
#define CMTCMD12_MB2_MASK               4U
#define CMTCMD12_MB3_MASK               8U
#define CMTCMD12_MB4_MASK               16U
#define CMTCMD12_MB5_MASK               32U
#define CMTCMD12_MB6_MASK               64U
#define CMTCMD12_MB7_MASK               128U
#define CMTCMD12_MB8_MASK               256U
#define CMTCMD12_MB9_MASK               512U
#define CMTCMD12_MB10_MASK              1024U
#define CMTCMD12_MB11_MASK              2048U
#define CMTCMD12_MB12_MASK              4096U
#define CMTCMD12_MB13_MASK              8192U
#define CMTCMD12_MB14_MASK              16384U
#define CMTCMD12_MB15_MASK              32768U


/*** CMTCMD34 - CMT Modulator Data Register 34; 0xFFFF9870 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CMTCMD3 - CMT Modulator Data Register 3; 0xFFFF9870 ***/
    union {
      byte Byte;
    } CMTCMD3STR;
    #define CMTCMD3                     _CMTCMD34.Overlap_STR.CMTCMD3STR.Byte
    

    /*** CMTCMD4 - CMT Modulator Data Register 4; 0xFFFF9871 ***/
    union {
      byte Byte;
      struct {
        byte SB0         :1;                                       /* Data Value Bit 0 */
        byte SB1         :1;                                       /* Data Value Bit 1 */
        byte SB2         :1;                                       /* Data Value Bit 2 */
        byte SB3         :1;                                       /* Data Value Bit 3 */
        byte SB4         :1;                                       /* Data Value Bit 4 */
        byte SB5         :1;                                       /* Data Value Bit 5 */
        byte SB6         :1;                                       /* Data Value Bit 6 */
        byte SB7         :1;                                       /* Data Value Bit 7 */
      } Bits;
    } CMTCMD4STR;
    #define CMTCMD4                     _CMTCMD34.Overlap_STR.CMTCMD4STR.Byte
    #define CMTCMD4_SB0                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB0
    #define CMTCMD4_SB1                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB1
    #define CMTCMD4_SB2                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB2
    #define CMTCMD4_SB3                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB3
    #define CMTCMD4_SB4                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB4
    #define CMTCMD4_SB5                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB5
    #define CMTCMD4_SB6                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB6
    #define CMTCMD4_SB7                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB7
    
    #define CMTCMD4_SB0_MASK            1U
    #define CMTCMD4_SB1_MASK            2U
    #define CMTCMD4_SB2_MASK            4U
    #define CMTCMD4_SB3_MASK            8U
    #define CMTCMD4_SB4_MASK            16U
    #define CMTCMD4_SB5_MASK            32U
    #define CMTCMD4_SB6_MASK            64U
    #define CMTCMD4_SB7_MASK            128U
    
  } Overlap_STR;

  struct {
    word SB0         :1;                                       /* Data Value Bit 0 */
    word SB1         :1;                                       /* Data Value Bit 1 */
    word SB2         :1;                                       /* Data Value Bit 2 */
    word SB3         :1;                                       /* Data Value Bit 3 */
    word SB4         :1;                                       /* Data Value Bit 4 */
    word SB5         :1;                                       /* Data Value Bit 5 */
    word SB6         :1;                                       /* Data Value Bit 6 */
    word SB7         :1;                                       /* Data Value Bit 7 */
    word SB8         :1;                                       /* Data Value Bit 8 */
    word SB9         :1;                                       /* Data Value Bit 9 */
    word SB10        :1;                                       /* Data Value Bit 10 */
    word SB11        :1;                                       /* Data Value Bit 11 */
    word SB12        :1;                                       /* Data Value Bit 12 */
    word SB13        :1;                                       /* Data Value Bit 13 */
    word SB14        :1;                                       /* Data Value Bit 14 */
    word SB15        :1;                                       /* Data Value Bit 15 */
  } Bits;
} CMTCMD34STR;
#define _CMTCMD34 (*(volatile CMTCMD34STR *)0xFFFF9870)
#define CMTCMD34                        _CMTCMD34.Word
#define CMTCMD34_SB0                    _CMTCMD34.Bits.SB0
#define CMTCMD34_SB1                    _CMTCMD34.Bits.SB1
#define CMTCMD34_SB2                    _CMTCMD34.Bits.SB2
#define CMTCMD34_SB3                    _CMTCMD34.Bits.SB3
#define CMTCMD34_SB4                    _CMTCMD34.Bits.SB4
#define CMTCMD34_SB5                    _CMTCMD34.Bits.SB5
#define CMTCMD34_SB6                    _CMTCMD34.Bits.SB6
#define CMTCMD34_SB7                    _CMTCMD34.Bits.SB7
#define CMTCMD34_SB8                    _CMTCMD34.Bits.SB8
#define CMTCMD34_SB9                    _CMTCMD34.Bits.SB9
#define CMTCMD34_SB10                   _CMTCMD34.Bits.SB10
#define CMTCMD34_SB11                   _CMTCMD34.Bits.SB11
#define CMTCMD34_SB12                   _CMTCMD34.Bits.SB12
#define CMTCMD34_SB13                   _CMTCMD34.Bits.SB13
#define CMTCMD34_SB14                   _CMTCMD34.Bits.SB14
#define CMTCMD34_SB15                   _CMTCMD34.Bits.SB15

#define CMTCMD34_SB0_MASK               1U
#define CMTCMD34_SB1_MASK               2U
#define CMTCMD34_SB2_MASK               4U
#define CMTCMD34_SB3_MASK               8U
#define CMTCMD34_SB4_MASK               16U
#define CMTCMD34_SB5_MASK               32U
#define CMTCMD34_SB6_MASK               64U
#define CMTCMD34_SB7_MASK               128U
#define CMTCMD34_SB8_MASK               256U
#define CMTCMD34_SB9_MASK               512U
#define CMTCMD34_SB10_MASK              1024U
#define CMTCMD34_SB11_MASK              2048U
#define CMTCMD34_SB12_MASK              4096U
#define CMTCMD34_SB13_MASK              8192U
#define CMTCMD34_SB14_MASK              16384U
#define CMTCMD34_SB15_MASK              32768U


/*** PTHD - Port H Data Register; 0xFFFF9874 ***/
typedef union {
  byte Byte;
  struct {
    byte PTHD0       :1;                                       /* Port H Data Register Bit 0 */
    byte PTHD1       :1;                                       /* Port H Data Register Bit 1 */
    byte PTHD2       :1;                                       /* Port H Data Register Bit 2 */
    byte PTHD3       :1;                                       /* Port H Data Register Bit 3 */
    byte PTHD4       :1;                                       /* Port H Data Register Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTHD :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTHDSTR;
#define _PTHD (*(volatile PTHDSTR *)0xFFFF9874)
#define PTHD                            _PTHD.Byte
#define PTHD_PTHD0                      _PTHD.Bits.PTHD0
#define PTHD_PTHD1                      _PTHD.Bits.PTHD1
#define PTHD_PTHD2                      _PTHD.Bits.PTHD2
#define PTHD_PTHD3                      _PTHD.Bits.PTHD3
#define PTHD_PTHD4                      _PTHD.Bits.PTHD4
#define PTHD_PTHD                       _PTHD.MergedBits.grpPTHD

#define PTHD_PTHD0_MASK                 1U
#define PTHD_PTHD1_MASK                 2U
#define PTHD_PTHD2_MASK                 4U
#define PTHD_PTHD3_MASK                 8U
#define PTHD_PTHD4_MASK                 16U
#define PTHD_PTHD_MASK                  31U
#define PTHD_PTHD_BITNUM                0U


/*** PTHDD - Port H Data Direction Register; 0xFFFF9875 ***/
typedef union {
  byte Byte;
  struct {
    byte PTHDD0      :1;                                       /* Data Direction for Port H Bit 0 */
    byte PTHDD1      :1;                                       /* Data Direction for Port H Bit 1 */
    byte PTHDD2      :1;                                       /* Data Direction for Port H Bit 2 */
    byte PTHDD3      :1;                                       /* Data Direction for Port H Bit 3 */
    byte PTHDD4      :1;                                       /* Data Direction for Port H Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTHDD :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTHDDSTR;
#define _PTHDD (*(volatile PTHDDSTR *)0xFFFF9875)
#define PTHDD                           _PTHDD.Byte
#define PTHDD_PTHDD0                    _PTHDD.Bits.PTHDD0
#define PTHDD_PTHDD1                    _PTHDD.Bits.PTHDD1
#define PTHDD_PTHDD2                    _PTHDD.Bits.PTHDD2
#define PTHDD_PTHDD3                    _PTHDD.Bits.PTHDD3
#define PTHDD_PTHDD4                    _PTHDD.Bits.PTHDD4
#define PTHDD_PTHDD                     _PTHDD.MergedBits.grpPTHDD

#define PTHDD_PTHDD0_MASK               1U
#define PTHDD_PTHDD1_MASK               2U
#define PTHDD_PTHDD2_MASK               4U
#define PTHDD_PTHDD3_MASK               8U
#define PTHDD_PTHDD4_MASK               16U
#define PTHDD_PTHDD_MASK                31U
#define PTHDD_PTHDD_BITNUM              0U


/*** PTJD - Port J Data Register; 0xFFFF9876 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJD0       :1;                                       /* Port J Data Register Bit 0 */
    byte PTJD1       :1;                                       /* Port J Data Register Bit 1 */
    byte PTJD2       :1;                                       /* Port J Data Register Bit 2 */
    byte PTJD3       :1;                                       /* Port J Data Register Bit 3 */
    byte PTJD4       :1;                                       /* Port J Data Register Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTJD :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTJDSTR;
#define _PTJD (*(volatile PTJDSTR *)0xFFFF9876)
#define PTJD                            _PTJD.Byte
#define PTJD_PTJD0                      _PTJD.Bits.PTJD0
#define PTJD_PTJD1                      _PTJD.Bits.PTJD1
#define PTJD_PTJD2                      _PTJD.Bits.PTJD2
#define PTJD_PTJD3                      _PTJD.Bits.PTJD3
#define PTJD_PTJD4                      _PTJD.Bits.PTJD4
#define PTJD_PTJD                       _PTJD.MergedBits.grpPTJD

#define PTJD_PTJD0_MASK                 1U
#define PTJD_PTJD1_MASK                 2U
#define PTJD_PTJD2_MASK                 4U
#define PTJD_PTJD3_MASK                 8U
#define PTJD_PTJD4_MASK                 16U
#define PTJD_PTJD_MASK                  31U
#define PTJD_PTJD_BITNUM                0U


/*** PTJDD - Port J Data Direction Register; 0xFFFF9877 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJDD0      :1;                                       /* Data Direction for Port J Bit 0 */
    byte PTJDD1      :1;                                       /* Data Direction for Port J Bit 1 */
    byte PTJDD2      :1;                                       /* Data Direction for Port J Bit 2 */
    byte PTJDD3      :1;                                       /* Data Direction for Port J Bit 3 */
    byte PTJDD4      :1;                                       /* Data Direction for Port J Bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTJDD :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTJDDSTR;
#define _PTJDD (*(volatile PTJDDSTR *)0xFFFF9877)
#define PTJDD                           _PTJDD.Byte
#define PTJDD_PTJDD0                    _PTJDD.Bits.PTJDD0
#define PTJDD_PTJDD1                    _PTJDD.Bits.PTJDD1
#define PTJDD_PTJDD2                    _PTJDD.Bits.PTJDD2
#define PTJDD_PTJDD3                    _PTJDD.Bits.PTJDD3
#define PTJDD_PTJDD4                    _PTJDD.Bits.PTJDD4
#define PTJDD_PTJDD                     _PTJDD.MergedBits.grpPTJDD

#define PTJDD_PTJDD0_MASK               1U
#define PTJDD_PTJDD1_MASK               2U
#define PTJDD_PTJDD2_MASK               4U
#define PTJDD_PTJDD3_MASK               8U
#define PTJDD_PTJDD4_MASK               16U
#define PTJDD_PTJDD_MASK                31U
#define PTJDD_PTJDD_BITNUM              0U


/*** CANCTL0 - MSCAN Control 0 Register; 0xFFFF9880 ***/
typedef union {
  byte Byte;
  struct {
    byte INITRQ      :1;                                       /* Initialization Mode Request */
    byte SLPRQ       :1;                                       /* Sleep Mode Request */
    byte WUPE        :1;                                       /* Wake-Up Enable */
    byte TIME        :1;                                       /* Timer Enable */
    byte SYNCH       :1;                                       /* Synchronized Status */
    byte CSWAI       :1;                                       /* CAN Stops in Wait Mode */
    byte RXACT       :1;                                       /* Receiver Active Status */
    byte RXFRM       :1;                                       /* Received Frame Flag */
  } Bits;
} CANCTL0STR;
#define _CANCTL0 (*(volatile CANCTL0STR *)0xFFFF9880)
#define CANCTL0                         _CANCTL0.Byte
#define CANCTL0_INITRQ                  _CANCTL0.Bits.INITRQ
#define CANCTL0_SLPRQ                   _CANCTL0.Bits.SLPRQ
#define CANCTL0_WUPE                    _CANCTL0.Bits.WUPE
#define CANCTL0_TIME                    _CANCTL0.Bits.TIME
#define CANCTL0_SYNCH                   _CANCTL0.Bits.SYNCH
#define CANCTL0_CSWAI                   _CANCTL0.Bits.CSWAI
#define CANCTL0_RXACT                   _CANCTL0.Bits.RXACT
#define CANCTL0_RXFRM                   _CANCTL0.Bits.RXFRM
/* CANCTL_ARR: Access 2 CANCTLx registers in an array */
#define CANCTL_ARR                      ((volatile byte *) &CANCTL0)

#define CANCTL0_INITRQ_MASK             1U
#define CANCTL0_SLPRQ_MASK              2U
#define CANCTL0_WUPE_MASK               4U
#define CANCTL0_TIME_MASK               8U
#define CANCTL0_SYNCH_MASK              16U
#define CANCTL0_CSWAI_MASK              32U
#define CANCTL0_RXACT_MASK              64U
#define CANCTL0_RXFRM_MASK              128U


/*** CANCTL1 - MSCAN Control 1 Register; 0xFFFF9881 ***/
typedef union {
  byte Byte;
  struct {
    byte INITAK      :1;                                       /* Initialization Mode Acknowledge */
    byte SLPAK       :1;                                       /* Sleep Mode Acknowledge */
    byte WUPM        :1;                                       /* Wake-Up Mode */
    byte BORM        :1;                                       /* Bus-Off Recovery Mode */
    byte LISTEN      :1;                                       /* Listen Only Mode */
    byte LOOPB       :1;                                       /* Loop Back Self Test Mode */
    byte CLKSRC      :1;                                       /* MSCAN Clock Source */
    byte CANE        :1;                                       /* MSCAN Enable */
  } Bits;
} CANCTL1STR;
#define _CANCTL1 (*(volatile CANCTL1STR *)0xFFFF9881)
#define CANCTL1                         _CANCTL1.Byte
#define CANCTL1_INITAK                  _CANCTL1.Bits.INITAK
#define CANCTL1_SLPAK                   _CANCTL1.Bits.SLPAK
#define CANCTL1_WUPM                    _CANCTL1.Bits.WUPM
#define CANCTL1_BORM                    _CANCTL1.Bits.BORM
#define CANCTL1_LISTEN                  _CANCTL1.Bits.LISTEN
#define CANCTL1_LOOPB                   _CANCTL1.Bits.LOOPB
#define CANCTL1_CLKSRC                  _CANCTL1.Bits.CLKSRC
#define CANCTL1_CANE                    _CANCTL1.Bits.CANE

#define CANCTL1_INITAK_MASK             1U
#define CANCTL1_SLPAK_MASK              2U
#define CANCTL1_WUPM_MASK               4U
#define CANCTL1_BORM_MASK               8U
#define CANCTL1_LISTEN_MASK             16U
#define CANCTL1_LOOPB_MASK              32U
#define CANCTL1_CLKSRC_MASK             64U
#define CANCTL1_CANE_MASK               128U


/*** CANBTR0 - MSCAN Bus Timing Register 0; 0xFFFF9882 ***/
typedef union {
  byte Byte;
  struct {
    byte BRP0        :1;                                       /* Baud Rate Prescaler 0 */
    byte BRP1        :1;                                       /* Baud Rate Prescaler 1 */
    byte BRP2        :1;                                       /* Baud Rate Prescaler 2 */
    byte BRP3        :1;                                       /* Baud Rate Prescaler 3 */
    byte BRP4        :1;                                       /* Baud Rate Prescaler 4 */
    byte BRP5        :1;                                       /* Baud Rate Prescaler 5 */
    byte SJW0        :1;                                       /* Synchronization Jump Width 0 */
    byte SJW1        :1;                                       /* Synchronization Jump Width 1 */
  } Bits;
  struct {
    byte grpBRP  :6;
    byte grpSJW  :2;
  } MergedBits;
} CANBTR0STR;
#define _CANBTR0 (*(volatile CANBTR0STR *)0xFFFF9882)
#define CANBTR0                         _CANBTR0.Byte
#define CANBTR0_BRP0                    _CANBTR0.Bits.BRP0
#define CANBTR0_BRP1                    _CANBTR0.Bits.BRP1
#define CANBTR0_BRP2                    _CANBTR0.Bits.BRP2
#define CANBTR0_BRP3                    _CANBTR0.Bits.BRP3
#define CANBTR0_BRP4                    _CANBTR0.Bits.BRP4
#define CANBTR0_BRP5                    _CANBTR0.Bits.BRP5
#define CANBTR0_SJW0                    _CANBTR0.Bits.SJW0
#define CANBTR0_SJW1                    _CANBTR0.Bits.SJW1
/* CANBTR_ARR: Access 2 CANBTRx registers in an array */
#define CANBTR_ARR                      ((volatile byte *) &CANBTR0)
#define CANBTR0_BRP                     _CANBTR0.MergedBits.grpBRP
#define CANBTR0_SJW                     _CANBTR0.MergedBits.grpSJW

#define CANBTR0_BRP0_MASK               1U
#define CANBTR0_BRP1_MASK               2U
#define CANBTR0_BRP2_MASK               4U
#define CANBTR0_BRP3_MASK               8U
#define CANBTR0_BRP4_MASK               16U
#define CANBTR0_BRP5_MASK               32U
#define CANBTR0_SJW0_MASK               64U
#define CANBTR0_SJW1_MASK               128U
#define CANBTR0_BRP_MASK                63U
#define CANBTR0_BRP_BITNUM              0U
#define CANBTR0_SJW_MASK                192U
#define CANBTR0_SJW_BITNUM              6U


/*** CANBTR1 - MSCAN Bus Timing Register 1; 0xFFFF9883 ***/
typedef union {
  byte Byte;
  struct {
    byte TSEG10      :1;                                       /* Time Segment 10 */
    byte TSEG11      :1;                                       /* Time Segment 11 */
    byte TSEG12      :1;                                       /* Time Segment 12 */
    byte TSEG13      :1;                                       /* Time Segment 13 */
    byte TSEG20      :1;                                       /* Time Segment 20 */
    byte TSEG21      :1;                                       /* Time Segment 21 */
    byte TSEG22      :1;                                       /* Time Segment 22 */
    byte SAMP        :1;                                       /* Sampling */
  } Bits;
  struct {
    byte grpTSEG_10 :4;
    byte grpTSEG_20 :3;
    byte         :1;
  } MergedBits;
} CANBTR1STR;
#define _CANBTR1 (*(volatile CANBTR1STR *)0xFFFF9883)
#define CANBTR1                         _CANBTR1.Byte
#define CANBTR1_TSEG10                  _CANBTR1.Bits.TSEG10
#define CANBTR1_TSEG11                  _CANBTR1.Bits.TSEG11
#define CANBTR1_TSEG12                  _CANBTR1.Bits.TSEG12
#define CANBTR1_TSEG13                  _CANBTR1.Bits.TSEG13
#define CANBTR1_TSEG20                  _CANBTR1.Bits.TSEG20
#define CANBTR1_TSEG21                  _CANBTR1.Bits.TSEG21
#define CANBTR1_TSEG22                  _CANBTR1.Bits.TSEG22
#define CANBTR1_SAMP                    _CANBTR1.Bits.SAMP
#define CANBTR1_TSEG_10                 _CANBTR1.MergedBits.grpTSEG_10
#define CANBTR1_TSEG_20                 _CANBTR1.MergedBits.grpTSEG_20
#define CANBTR1_TSEG                    CANBTR1_TSEG_10

#define CANBTR1_TSEG10_MASK             1U
#define CANBTR1_TSEG11_MASK             2U
#define CANBTR1_TSEG12_MASK             4U
#define CANBTR1_TSEG13_MASK             8U
#define CANBTR1_TSEG20_MASK             16U
#define CANBTR1_TSEG21_MASK             32U
#define CANBTR1_TSEG22_MASK             64U
#define CANBTR1_SAMP_MASK               128U
#define CANBTR1_TSEG_10_MASK            15U
#define CANBTR1_TSEG_10_BITNUM          0U
#define CANBTR1_TSEG_20_MASK            112U
#define CANBTR1_TSEG_20_BITNUM          4U


/*** CANRFLG - MSCAN Receiver Flag Register; 0xFFFF9884 ***/
typedef union {
  byte Byte;
  struct {
    byte RXF         :1;                                       /* Receive Buffer Full */
    byte OVRIF       :1;                                       /* Overrun Interrupt Flag */
    byte TSTAT0      :1;                                       /* Transmitter Status Bit 0 */
    byte TSTAT1      :1;                                       /* Transmitter Status Bit 1 */
    byte RSTAT0      :1;                                       /* Receiver Status Bit 0 */
    byte RSTAT1      :1;                                       /* Receiver Status Bit 1 */
    byte CSCIF       :1;                                       /* CAN Status Change Interrupt Flag */
    byte WUPIF       :1;                                       /* Wake-up Interrupt Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTSTAT :2;
    byte grpRSTAT :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRFLGSTR;
#define _CANRFLG (*(volatile CANRFLGSTR *)0xFFFF9884)
#define CANRFLG                         _CANRFLG.Byte
#define CANRFLG_RXF                     _CANRFLG.Bits.RXF
#define CANRFLG_OVRIF                   _CANRFLG.Bits.OVRIF
#define CANRFLG_TSTAT0                  _CANRFLG.Bits.TSTAT0
#define CANRFLG_TSTAT1                  _CANRFLG.Bits.TSTAT1
#define CANRFLG_RSTAT0                  _CANRFLG.Bits.RSTAT0
#define CANRFLG_RSTAT1                  _CANRFLG.Bits.RSTAT1
#define CANRFLG_CSCIF                   _CANRFLG.Bits.CSCIF
#define CANRFLG_WUPIF                   _CANRFLG.Bits.WUPIF
#define CANRFLG_TSTAT                   _CANRFLG.MergedBits.grpTSTAT
#define CANRFLG_RSTAT                   _CANRFLG.MergedBits.grpRSTAT

#define CANRFLG_RXF_MASK                1U
#define CANRFLG_OVRIF_MASK              2U
#define CANRFLG_TSTAT0_MASK             4U
#define CANRFLG_TSTAT1_MASK             8U
#define CANRFLG_RSTAT0_MASK             16U
#define CANRFLG_RSTAT1_MASK             32U
#define CANRFLG_CSCIF_MASK              64U
#define CANRFLG_WUPIF_MASK              128U
#define CANRFLG_TSTAT_MASK              12U
#define CANRFLG_TSTAT_BITNUM            2U
#define CANRFLG_RSTAT_MASK              48U
#define CANRFLG_RSTAT_BITNUM            4U


/*** CANRIER - MSCAN Receiver Interrupt Enable Register; 0xFFFF9885 ***/
typedef union {
  byte Byte;
  struct {
    byte RXFIE       :1;                                       /* Receiver Full Interrupt Enable */
    byte OVRIE       :1;                                       /* Overrun Interrupt Enable */
    byte TSTATE0     :1;                                       /* Transmitter Status Change Enable 0 */
    byte TSTATE1     :1;                                       /* Transmitter Status Change Enable 1 */
    byte RSTATE0     :1;                                       /* Receiver Status Change Enable 0 */
    byte RSTATE1     :1;                                       /* Receiver Status Change Enable 1 */
    byte CSCIE       :1;                                       /* CAN Status Change Interrupt Enable */
    byte WUPIE       :1;                                       /* Wake-up Interrupt Enable */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTSTATE :2;
    byte grpRSTATE :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRIERSTR;
#define _CANRIER (*(volatile CANRIERSTR *)0xFFFF9885)
#define CANRIER                         _CANRIER.Byte
#define CANRIER_RXFIE                   _CANRIER.Bits.RXFIE
#define CANRIER_OVRIE                   _CANRIER.Bits.OVRIE
#define CANRIER_TSTATE0                 _CANRIER.Bits.TSTATE0
#define CANRIER_TSTATE1                 _CANRIER.Bits.TSTATE1
#define CANRIER_RSTATE0                 _CANRIER.Bits.RSTATE0
#define CANRIER_RSTATE1                 _CANRIER.Bits.RSTATE1
#define CANRIER_CSCIE                   _CANRIER.Bits.CSCIE
#define CANRIER_WUPIE                   _CANRIER.Bits.WUPIE
#define CANRIER_TSTATE                  _CANRIER.MergedBits.grpTSTATE
#define CANRIER_RSTATE                  _CANRIER.MergedBits.grpRSTATE

#define CANRIER_RXFIE_MASK              1U
#define CANRIER_OVRIE_MASK              2U
#define CANRIER_TSTATE0_MASK            4U
#define CANRIER_TSTATE1_MASK            8U
#define CANRIER_RSTATE0_MASK            16U
#define CANRIER_RSTATE1_MASK            32U
#define CANRIER_CSCIE_MASK              64U
#define CANRIER_WUPIE_MASK              128U
#define CANRIER_TSTATE_MASK             12U
#define CANRIER_TSTATE_BITNUM           2U
#define CANRIER_RSTATE_MASK             48U
#define CANRIER_RSTATE_BITNUM           4U


/*** CANTFLG - MSCAN Transmitter Flag Register; 0xFFFF9886 ***/
typedef union {
  byte Byte;
  struct {
    byte TXE0        :1;                                       /* Transmitter Buffer Empty 0 */
    byte TXE1        :1;                                       /* Transmitter Buffer Empty 1 */
    byte TXE2        :1;                                       /* Transmitter Buffer Empty 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTXE  :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTFLGSTR;
#define _CANTFLG (*(volatile CANTFLGSTR *)0xFFFF9886)
#define CANTFLG                         _CANTFLG.Byte
#define CANTFLG_TXE0                    _CANTFLG.Bits.TXE0
#define CANTFLG_TXE1                    _CANTFLG.Bits.TXE1
#define CANTFLG_TXE2                    _CANTFLG.Bits.TXE2
#define CANTFLG_TXE                     _CANTFLG.MergedBits.grpTXE

#define CANTFLG_TXE0_MASK               1U
#define CANTFLG_TXE1_MASK               2U
#define CANTFLG_TXE2_MASK               4U
#define CANTFLG_TXE_MASK                7U
#define CANTFLG_TXE_BITNUM              0U


/*** CANTIER - MSCAN Transmitter Interrupt Enable Register; 0xFFFF9887 ***/
typedef union {
  byte Byte;
  struct {
    byte TXEIE0      :1;                                       /* Transmitter Empty Interrupt Enable 0 */
    byte TXEIE1      :1;                                       /* Transmitter Empty Interrupt Enable 1 */
    byte TXEIE2      :1;                                       /* Transmitter Empty Interrupt Enable 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTXEIE :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTIERSTR;
#define _CANTIER (*(volatile CANTIERSTR *)0xFFFF9887)
#define CANTIER                         _CANTIER.Byte
#define CANTIER_TXEIE0                  _CANTIER.Bits.TXEIE0
#define CANTIER_TXEIE1                  _CANTIER.Bits.TXEIE1
#define CANTIER_TXEIE2                  _CANTIER.Bits.TXEIE2
#define CANTIER_TXEIE                   _CANTIER.MergedBits.grpTXEIE

#define CANTIER_TXEIE0_MASK             1U
#define CANTIER_TXEIE1_MASK             2U
#define CANTIER_TXEIE2_MASK             4U
#define CANTIER_TXEIE_MASK              7U
#define CANTIER_TXEIE_BITNUM            0U


/*** CANTARQ - MSCAN Transmitter Message Abort Request; 0xFFFF9888 ***/
typedef union {
  byte Byte;
  struct {
    byte ABTRQ0      :1;                                       /* Abort Request 0 */
    byte ABTRQ1      :1;                                       /* Abort Request 1 */
    byte ABTRQ2      :1;                                       /* Abort Request 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpABTRQ :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTARQSTR;
#define _CANTARQ (*(volatile CANTARQSTR *)0xFFFF9888)
#define CANTARQ                         _CANTARQ.Byte
#define CANTARQ_ABTRQ0                  _CANTARQ.Bits.ABTRQ0
#define CANTARQ_ABTRQ1                  _CANTARQ.Bits.ABTRQ1
#define CANTARQ_ABTRQ2                  _CANTARQ.Bits.ABTRQ2
#define CANTARQ_ABTRQ                   _CANTARQ.MergedBits.grpABTRQ

#define CANTARQ_ABTRQ0_MASK             1U
#define CANTARQ_ABTRQ1_MASK             2U
#define CANTARQ_ABTRQ2_MASK             4U
#define CANTARQ_ABTRQ_MASK              7U
#define CANTARQ_ABTRQ_BITNUM            0U


/*** CANTAAK - MSCAN Transmitter Message Abort Acknowledge; 0xFFFF9889 ***/
typedef union {
  byte Byte;
  struct {
    byte ABTAK0      :1;                                       /* Abort Acknowledge 0 */
    byte ABTAK1      :1;                                       /* Abort Acknowledge 1 */
    byte ABTAK2      :1;                                       /* Abort Acknowledge 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpABTAK :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTAAKSTR;
#define _CANTAAK (*(volatile CANTAAKSTR *)0xFFFF9889)
#define CANTAAK                         _CANTAAK.Byte
#define CANTAAK_ABTAK0                  _CANTAAK.Bits.ABTAK0
#define CANTAAK_ABTAK1                  _CANTAAK.Bits.ABTAK1
#define CANTAAK_ABTAK2                  _CANTAAK.Bits.ABTAK2
#define CANTAAK_ABTAK                   _CANTAAK.MergedBits.grpABTAK

#define CANTAAK_ABTAK0_MASK             1U
#define CANTAAK_ABTAK1_MASK             2U
#define CANTAAK_ABTAK2_MASK             4U
#define CANTAAK_ABTAK_MASK              7U
#define CANTAAK_ABTAK_BITNUM            0U


/*** CANTBSEL - MSCAN Transmit Buffer Selection; 0xFFFF988A ***/
typedef union {
  byte Byte;
  struct {
    byte TX0         :1;                                       /* Transmit Buffer Select 0 */
    byte TX1         :1;                                       /* Transmit Buffer Select 1 */
    byte TX2         :1;                                       /* Transmit Buffer Select 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTX   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTBSELSTR;
#define _CANTBSEL (*(volatile CANTBSELSTR *)0xFFFF988A)
#define CANTBSEL                        _CANTBSEL.Byte
#define CANTBSEL_TX0                    _CANTBSEL.Bits.TX0
#define CANTBSEL_TX1                    _CANTBSEL.Bits.TX1
#define CANTBSEL_TX2                    _CANTBSEL.Bits.TX2
#define CANTBSEL_TX                     _CANTBSEL.MergedBits.grpTX

#define CANTBSEL_TX0_MASK               1U
#define CANTBSEL_TX1_MASK               2U
#define CANTBSEL_TX2_MASK               4U
#define CANTBSEL_TX_MASK                7U
#define CANTBSEL_TX_BITNUM              0U


/*** CANIDAC - MSCAN Identifier Acceptance Control Register; 0xFFFF988B ***/
typedef union {
  byte Byte;
  struct {
    byte IDHIT0      :1;                                       /* Identifier Acceptance Hit Indicator 0 */
    byte IDHIT1      :1;                                       /* Identifier Acceptance Hit Indicator 1 */
    byte IDHIT2      :1;                                       /* Identifier Acceptance Hit Indicator 2 */
    byte             :1; 
    byte IDAM0       :1;                                       /* Identifier Acceptance Mode 0 */
    byte IDAM1       :1;                                       /* Identifier Acceptance Mode 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpIDHIT :3;
    byte         :1;
    byte grpIDAM :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANIDACSTR;
#define _CANIDAC (*(volatile CANIDACSTR *)0xFFFF988B)
#define CANIDAC                         _CANIDAC.Byte
#define CANIDAC_IDHIT0                  _CANIDAC.Bits.IDHIT0
#define CANIDAC_IDHIT1                  _CANIDAC.Bits.IDHIT1
#define CANIDAC_IDHIT2                  _CANIDAC.Bits.IDHIT2
#define CANIDAC_IDAM0                   _CANIDAC.Bits.IDAM0
#define CANIDAC_IDAM1                   _CANIDAC.Bits.IDAM1
#define CANIDAC_IDHIT                   _CANIDAC.MergedBits.grpIDHIT
#define CANIDAC_IDAM                    _CANIDAC.MergedBits.grpIDAM

#define CANIDAC_IDHIT0_MASK             1U
#define CANIDAC_IDHIT1_MASK             2U
#define CANIDAC_IDHIT2_MASK             4U
#define CANIDAC_IDAM0_MASK              16U
#define CANIDAC_IDAM1_MASK              32U
#define CANIDAC_IDHIT_MASK              7U
#define CANIDAC_IDHIT_BITNUM            0U
#define CANIDAC_IDAM_MASK               48U
#define CANIDAC_IDAM_BITNUM             4U


/*** CANMISC - MSCAN Miscellaneous Register; 0xFFFF988D ***/
typedef union {
  byte Byte;
  struct {
    byte BOHOLD      :1;                                       /* Bus-off State Hold Until User Request - If BORM is set */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CANMISCSTR;
#define _CANMISC (*(volatile CANMISCSTR *)0xFFFF988D)
#define CANMISC                         _CANMISC.Byte
#define CANMISC_BOHOLD                  _CANMISC.Bits.BOHOLD

#define CANMISC_BOHOLD_MASK             1U


/*** CANRXERR - MSCAN Receive Error Counter Register; 0xFFFF988E ***/
typedef union {
  byte Byte;
  struct {
    byte RXERR0      :1;                                       /* Bit 0 */
    byte RXERR1      :1;                                       /* Bit 1 */
    byte RXERR2      :1;                                       /* Bit 2 */
    byte RXERR3      :1;                                       /* Bit 3 */
    byte RXERR4      :1;                                       /* Bit 4 */
    byte RXERR5      :1;                                       /* Bit 5 */
    byte RXERR6      :1;                                       /* Bit 6 */
    byte RXERR7      :1;                                       /* Bit 7 */
  } Bits;
} CANRXERRSTR;
#define _CANRXERR (*(volatile CANRXERRSTR *)0xFFFF988E)
#define CANRXERR                        _CANRXERR.Byte
#define CANRXERR_RXERR0                 _CANRXERR.Bits.RXERR0
#define CANRXERR_RXERR1                 _CANRXERR.Bits.RXERR1
#define CANRXERR_RXERR2                 _CANRXERR.Bits.RXERR2
#define CANRXERR_RXERR3                 _CANRXERR.Bits.RXERR3
#define CANRXERR_RXERR4                 _CANRXERR.Bits.RXERR4
#define CANRXERR_RXERR5                 _CANRXERR.Bits.RXERR5
#define CANRXERR_RXERR6                 _CANRXERR.Bits.RXERR6
#define CANRXERR_RXERR7                 _CANRXERR.Bits.RXERR7

#define CANRXERR_RXERR0_MASK            1U
#define CANRXERR_RXERR1_MASK            2U
#define CANRXERR_RXERR2_MASK            4U
#define CANRXERR_RXERR3_MASK            8U
#define CANRXERR_RXERR4_MASK            16U
#define CANRXERR_RXERR5_MASK            32U
#define CANRXERR_RXERR6_MASK            64U
#define CANRXERR_RXERR7_MASK            128U


/*** CANTXERR - MSCAN Transmit Error Counter Register; 0xFFFF988F ***/
typedef union {
  byte Byte;
  struct {
    byte TXERR0      :1;                                       /* Bit 0 */
    byte TXERR1      :1;                                       /* Bit 1 */
    byte TXERR2      :1;                                       /* Bit 2 */
    byte TXERR3      :1;                                       /* Bit 3 */
    byte TXERR4      :1;                                       /* Bit 4 */
    byte TXERR5      :1;                                       /* Bit 5 */
    byte TXERR6      :1;                                       /* Bit 6 */
    byte TXERR7      :1;                                       /* Bit 7 */
  } Bits;
} CANTXERRSTR;
#define _CANTXERR (*(volatile CANTXERRSTR *)0xFFFF988F)
#define CANTXERR                        _CANTXERR.Byte
#define CANTXERR_TXERR0                 _CANTXERR.Bits.TXERR0
#define CANTXERR_TXERR1                 _CANTXERR.Bits.TXERR1
#define CANTXERR_TXERR2                 _CANTXERR.Bits.TXERR2
#define CANTXERR_TXERR3                 _CANTXERR.Bits.TXERR3
#define CANTXERR_TXERR4                 _CANTXERR.Bits.TXERR4
#define CANTXERR_TXERR5                 _CANTXERR.Bits.TXERR5
#define CANTXERR_TXERR6                 _CANTXERR.Bits.TXERR6
#define CANTXERR_TXERR7                 _CANTXERR.Bits.TXERR7

#define CANTXERR_TXERR0_MASK            1U
#define CANTXERR_TXERR1_MASK            2U
#define CANTXERR_TXERR2_MASK            4U
#define CANTXERR_TXERR3_MASK            8U
#define CANTXERR_TXERR4_MASK            16U
#define CANTXERR_TXERR5_MASK            32U
#define CANTXERR_TXERR6_MASK            64U
#define CANTXERR_TXERR7_MASK            128U


/*** CANIDAR0 - MSCAN Identifier Acceptance Register 0; 0xFFFF9890 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR0STR;
#define _CANIDAR0 (*(volatile CANIDAR0STR *)0xFFFF9890)
#define CANIDAR0                        _CANIDAR0.Byte
#define CANIDAR0_AC0                    _CANIDAR0.Bits.AC0
#define CANIDAR0_AC1                    _CANIDAR0.Bits.AC1
#define CANIDAR0_AC2                    _CANIDAR0.Bits.AC2
#define CANIDAR0_AC3                    _CANIDAR0.Bits.AC3
#define CANIDAR0_AC4                    _CANIDAR0.Bits.AC4
#define CANIDAR0_AC5                    _CANIDAR0.Bits.AC5
#define CANIDAR0_AC6                    _CANIDAR0.Bits.AC6
#define CANIDAR0_AC7                    _CANIDAR0.Bits.AC7
/* CANIDAR_ARR: Access 4 CANIDARx registers in an array */
#define CANIDAR_ARR                     ((volatile byte *) &CANIDAR0)

#define CANIDAR0_AC0_MASK               1U
#define CANIDAR0_AC1_MASK               2U
#define CANIDAR0_AC2_MASK               4U
#define CANIDAR0_AC3_MASK               8U
#define CANIDAR0_AC4_MASK               16U
#define CANIDAR0_AC5_MASK               32U
#define CANIDAR0_AC6_MASK               64U
#define CANIDAR0_AC7_MASK               128U


/*** CANIDAR1 - MSCAN Identifier Acceptance Register 1; 0xFFFF9891 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR1STR;
#define _CANIDAR1 (*(volatile CANIDAR1STR *)0xFFFF9891)
#define CANIDAR1                        _CANIDAR1.Byte
#define CANIDAR1_AC0                    _CANIDAR1.Bits.AC0
#define CANIDAR1_AC1                    _CANIDAR1.Bits.AC1
#define CANIDAR1_AC2                    _CANIDAR1.Bits.AC2
#define CANIDAR1_AC3                    _CANIDAR1.Bits.AC3
#define CANIDAR1_AC4                    _CANIDAR1.Bits.AC4
#define CANIDAR1_AC5                    _CANIDAR1.Bits.AC5
#define CANIDAR1_AC6                    _CANIDAR1.Bits.AC6
#define CANIDAR1_AC7                    _CANIDAR1.Bits.AC7

#define CANIDAR1_AC0_MASK               1U
#define CANIDAR1_AC1_MASK               2U
#define CANIDAR1_AC2_MASK               4U
#define CANIDAR1_AC3_MASK               8U
#define CANIDAR1_AC4_MASK               16U
#define CANIDAR1_AC5_MASK               32U
#define CANIDAR1_AC6_MASK               64U
#define CANIDAR1_AC7_MASK               128U


/*** CANIDAR2 - MSCAN Identifier Acceptance Register 2; 0xFFFF9892 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR2STR;
#define _CANIDAR2 (*(volatile CANIDAR2STR *)0xFFFF9892)
#define CANIDAR2                        _CANIDAR2.Byte
#define CANIDAR2_AC0                    _CANIDAR2.Bits.AC0
#define CANIDAR2_AC1                    _CANIDAR2.Bits.AC1
#define CANIDAR2_AC2                    _CANIDAR2.Bits.AC2
#define CANIDAR2_AC3                    _CANIDAR2.Bits.AC3
#define CANIDAR2_AC4                    _CANIDAR2.Bits.AC4
#define CANIDAR2_AC5                    _CANIDAR2.Bits.AC5
#define CANIDAR2_AC6                    _CANIDAR2.Bits.AC6
#define CANIDAR2_AC7                    _CANIDAR2.Bits.AC7

#define CANIDAR2_AC0_MASK               1U
#define CANIDAR2_AC1_MASK               2U
#define CANIDAR2_AC2_MASK               4U
#define CANIDAR2_AC3_MASK               8U
#define CANIDAR2_AC4_MASK               16U
#define CANIDAR2_AC5_MASK               32U
#define CANIDAR2_AC6_MASK               64U
#define CANIDAR2_AC7_MASK               128U


/*** CANIDAR3 - MSCAN Identifier Acceptance Register 3; 0xFFFF9893 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR3STR;
#define _CANIDAR3 (*(volatile CANIDAR3STR *)0xFFFF9893)
#define CANIDAR3                        _CANIDAR3.Byte
#define CANIDAR3_AC0                    _CANIDAR3.Bits.AC0
#define CANIDAR3_AC1                    _CANIDAR3.Bits.AC1
#define CANIDAR3_AC2                    _CANIDAR3.Bits.AC2
#define CANIDAR3_AC3                    _CANIDAR3.Bits.AC3
#define CANIDAR3_AC4                    _CANIDAR3.Bits.AC4
#define CANIDAR3_AC5                    _CANIDAR3.Bits.AC5
#define CANIDAR3_AC6                    _CANIDAR3.Bits.AC6
#define CANIDAR3_AC7                    _CANIDAR3.Bits.AC7

#define CANIDAR3_AC0_MASK               1U
#define CANIDAR3_AC1_MASK               2U
#define CANIDAR3_AC2_MASK               4U
#define CANIDAR3_AC3_MASK               8U
#define CANIDAR3_AC4_MASK               16U
#define CANIDAR3_AC5_MASK               32U
#define CANIDAR3_AC6_MASK               64U
#define CANIDAR3_AC7_MASK               128U


/*** CANIDMR0 - MSCAN Identifier Mask Register 0; 0xFFFF9894 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR0STR;
#define _CANIDMR0 (*(volatile CANIDMR0STR *)0xFFFF9894)
#define CANIDMR0                        _CANIDMR0.Byte
#define CANIDMR0_AM0                    _CANIDMR0.Bits.AM0
#define CANIDMR0_AM1                    _CANIDMR0.Bits.AM1
#define CANIDMR0_AM2                    _CANIDMR0.Bits.AM2
#define CANIDMR0_AM3                    _CANIDMR0.Bits.AM3
#define CANIDMR0_AM4                    _CANIDMR0.Bits.AM4
#define CANIDMR0_AM5                    _CANIDMR0.Bits.AM5
#define CANIDMR0_AM6                    _CANIDMR0.Bits.AM6
#define CANIDMR0_AM7                    _CANIDMR0.Bits.AM7
/* CANIDMR_ARR: Access 4 CANIDMRx registers in an array */
#define CANIDMR_ARR                     ((volatile byte *) &CANIDMR0)

#define CANIDMR0_AM0_MASK               1U
#define CANIDMR0_AM1_MASK               2U
#define CANIDMR0_AM2_MASK               4U
#define CANIDMR0_AM3_MASK               8U
#define CANIDMR0_AM4_MASK               16U
#define CANIDMR0_AM5_MASK               32U
#define CANIDMR0_AM6_MASK               64U
#define CANIDMR0_AM7_MASK               128U


/*** CANIDMR1 - MSCAN Identifier Mask Register 1; 0xFFFF9895 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR1STR;
#define _CANIDMR1 (*(volatile CANIDMR1STR *)0xFFFF9895)
#define CANIDMR1                        _CANIDMR1.Byte
#define CANIDMR1_AM0                    _CANIDMR1.Bits.AM0
#define CANIDMR1_AM1                    _CANIDMR1.Bits.AM1
#define CANIDMR1_AM2                    _CANIDMR1.Bits.AM2
#define CANIDMR1_AM3                    _CANIDMR1.Bits.AM3
#define CANIDMR1_AM4                    _CANIDMR1.Bits.AM4
#define CANIDMR1_AM5                    _CANIDMR1.Bits.AM5
#define CANIDMR1_AM6                    _CANIDMR1.Bits.AM6
#define CANIDMR1_AM7                    _CANIDMR1.Bits.AM7

#define CANIDMR1_AM0_MASK               1U
#define CANIDMR1_AM1_MASK               2U
#define CANIDMR1_AM2_MASK               4U
#define CANIDMR1_AM3_MASK               8U
#define CANIDMR1_AM4_MASK               16U
#define CANIDMR1_AM5_MASK               32U
#define CANIDMR1_AM6_MASK               64U
#define CANIDMR1_AM7_MASK               128U


/*** CANIDMR2 - MSCAN Identifier Mask Register 2; 0xFFFF9896 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR2STR;
#define _CANIDMR2 (*(volatile CANIDMR2STR *)0xFFFF9896)
#define CANIDMR2                        _CANIDMR2.Byte
#define CANIDMR2_AM0                    _CANIDMR2.Bits.AM0
#define CANIDMR2_AM1                    _CANIDMR2.Bits.AM1
#define CANIDMR2_AM2                    _CANIDMR2.Bits.AM2
#define CANIDMR2_AM3                    _CANIDMR2.Bits.AM3
#define CANIDMR2_AM4                    _CANIDMR2.Bits.AM4
#define CANIDMR2_AM5                    _CANIDMR2.Bits.AM5
#define CANIDMR2_AM6                    _CANIDMR2.Bits.AM6
#define CANIDMR2_AM7                    _CANIDMR2.Bits.AM7

#define CANIDMR2_AM0_MASK               1U
#define CANIDMR2_AM1_MASK               2U
#define CANIDMR2_AM2_MASK               4U
#define CANIDMR2_AM3_MASK               8U
#define CANIDMR2_AM4_MASK               16U
#define CANIDMR2_AM5_MASK               32U
#define CANIDMR2_AM6_MASK               64U
#define CANIDMR2_AM7_MASK               128U


/*** CANIDMR3 - MSCAN Identifier Mask Register 3; 0xFFFF9897 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR3STR;
#define _CANIDMR3 (*(volatile CANIDMR3STR *)0xFFFF9897)
#define CANIDMR3                        _CANIDMR3.Byte
#define CANIDMR3_AM0                    _CANIDMR3.Bits.AM0
#define CANIDMR3_AM1                    _CANIDMR3.Bits.AM1
#define CANIDMR3_AM2                    _CANIDMR3.Bits.AM2
#define CANIDMR3_AM3                    _CANIDMR3.Bits.AM3
#define CANIDMR3_AM4                    _CANIDMR3.Bits.AM4
#define CANIDMR3_AM5                    _CANIDMR3.Bits.AM5
#define CANIDMR3_AM6                    _CANIDMR3.Bits.AM6
#define CANIDMR3_AM7                    _CANIDMR3.Bits.AM7

#define CANIDMR3_AM0_MASK               1U
#define CANIDMR3_AM1_MASK               2U
#define CANIDMR3_AM2_MASK               4U
#define CANIDMR3_AM3_MASK               8U
#define CANIDMR3_AM4_MASK               16U
#define CANIDMR3_AM5_MASK               32U
#define CANIDMR3_AM6_MASK               64U
#define CANIDMR3_AM7_MASK               128U


/*** CANIDAR4 - MSCAN Identifier Acceptance Register 4; 0xFFFF9898 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR4STR;
#define _CANIDAR4 (*(volatile CANIDAR4STR *)0xFFFF9898)
#define CANIDAR4                        _CANIDAR4.Byte
#define CANIDAR4_AC0                    _CANIDAR4.Bits.AC0
#define CANIDAR4_AC1                    _CANIDAR4.Bits.AC1
#define CANIDAR4_AC2                    _CANIDAR4.Bits.AC2
#define CANIDAR4_AC3                    _CANIDAR4.Bits.AC3
#define CANIDAR4_AC4                    _CANIDAR4.Bits.AC4
#define CANIDAR4_AC5                    _CANIDAR4.Bits.AC5
#define CANIDAR4_AC6                    _CANIDAR4.Bits.AC6
#define CANIDAR4_AC7                    _CANIDAR4.Bits.AC7

#define CANIDAR4_AC0_MASK               1U
#define CANIDAR4_AC1_MASK               2U
#define CANIDAR4_AC2_MASK               4U
#define CANIDAR4_AC3_MASK               8U
#define CANIDAR4_AC4_MASK               16U
#define CANIDAR4_AC5_MASK               32U
#define CANIDAR4_AC6_MASK               64U
#define CANIDAR4_AC7_MASK               128U


/*** CANIDAR5 - MSCAN Identifier Acceptance Register 5; 0xFFFF9899 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR5STR;
#define _CANIDAR5 (*(volatile CANIDAR5STR *)0xFFFF9899)
#define CANIDAR5                        _CANIDAR5.Byte
#define CANIDAR5_AC0                    _CANIDAR5.Bits.AC0
#define CANIDAR5_AC1                    _CANIDAR5.Bits.AC1
#define CANIDAR5_AC2                    _CANIDAR5.Bits.AC2
#define CANIDAR5_AC3                    _CANIDAR5.Bits.AC3
#define CANIDAR5_AC4                    _CANIDAR5.Bits.AC4
#define CANIDAR5_AC5                    _CANIDAR5.Bits.AC5
#define CANIDAR5_AC6                    _CANIDAR5.Bits.AC6
#define CANIDAR5_AC7                    _CANIDAR5.Bits.AC7

#define CANIDAR5_AC0_MASK               1U
#define CANIDAR5_AC1_MASK               2U
#define CANIDAR5_AC2_MASK               4U
#define CANIDAR5_AC3_MASK               8U
#define CANIDAR5_AC4_MASK               16U
#define CANIDAR5_AC5_MASK               32U
#define CANIDAR5_AC6_MASK               64U
#define CANIDAR5_AC7_MASK               128U


/*** CANIDAR6 - MSCAN Identifier Acceptance Register 6; 0xFFFF989A ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR6STR;
#define _CANIDAR6 (*(volatile CANIDAR6STR *)0xFFFF989A)
#define CANIDAR6                        _CANIDAR6.Byte
#define CANIDAR6_AC0                    _CANIDAR6.Bits.AC0
#define CANIDAR6_AC1                    _CANIDAR6.Bits.AC1
#define CANIDAR6_AC2                    _CANIDAR6.Bits.AC2
#define CANIDAR6_AC3                    _CANIDAR6.Bits.AC3
#define CANIDAR6_AC4                    _CANIDAR6.Bits.AC4
#define CANIDAR6_AC5                    _CANIDAR6.Bits.AC5
#define CANIDAR6_AC6                    _CANIDAR6.Bits.AC6
#define CANIDAR6_AC7                    _CANIDAR6.Bits.AC7

#define CANIDAR6_AC0_MASK               1U
#define CANIDAR6_AC1_MASK               2U
#define CANIDAR6_AC2_MASK               4U
#define CANIDAR6_AC3_MASK               8U
#define CANIDAR6_AC4_MASK               16U
#define CANIDAR6_AC5_MASK               32U
#define CANIDAR6_AC6_MASK               64U
#define CANIDAR6_AC7_MASK               128U


/*** CANIDAR7 - MSCAN Identifier Acceptance Register 7; 0xFFFF989B ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR7STR;
#define _CANIDAR7 (*(volatile CANIDAR7STR *)0xFFFF989B)
#define CANIDAR7                        _CANIDAR7.Byte
#define CANIDAR7_AC0                    _CANIDAR7.Bits.AC0
#define CANIDAR7_AC1                    _CANIDAR7.Bits.AC1
#define CANIDAR7_AC2                    _CANIDAR7.Bits.AC2
#define CANIDAR7_AC3                    _CANIDAR7.Bits.AC3
#define CANIDAR7_AC4                    _CANIDAR7.Bits.AC4
#define CANIDAR7_AC5                    _CANIDAR7.Bits.AC5
#define CANIDAR7_AC6                    _CANIDAR7.Bits.AC6
#define CANIDAR7_AC7                    _CANIDAR7.Bits.AC7

#define CANIDAR7_AC0_MASK               1U
#define CANIDAR7_AC1_MASK               2U
#define CANIDAR7_AC2_MASK               4U
#define CANIDAR7_AC3_MASK               8U
#define CANIDAR7_AC4_MASK               16U
#define CANIDAR7_AC5_MASK               32U
#define CANIDAR7_AC6_MASK               64U
#define CANIDAR7_AC7_MASK               128U


/*** CANIDMR4 - MSCAN Identifier Mask Register 4; 0xFFFF989C ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR4STR;
#define _CANIDMR4 (*(volatile CANIDMR4STR *)0xFFFF989C)
#define CANIDMR4                        _CANIDMR4.Byte
#define CANIDMR4_AM0                    _CANIDMR4.Bits.AM0
#define CANIDMR4_AM1                    _CANIDMR4.Bits.AM1
#define CANIDMR4_AM2                    _CANIDMR4.Bits.AM2
#define CANIDMR4_AM3                    _CANIDMR4.Bits.AM3
#define CANIDMR4_AM4                    _CANIDMR4.Bits.AM4
#define CANIDMR4_AM5                    _CANIDMR4.Bits.AM5
#define CANIDMR4_AM6                    _CANIDMR4.Bits.AM6
#define CANIDMR4_AM7                    _CANIDMR4.Bits.AM7

#define CANIDMR4_AM0_MASK               1U
#define CANIDMR4_AM1_MASK               2U
#define CANIDMR4_AM2_MASK               4U
#define CANIDMR4_AM3_MASK               8U
#define CANIDMR4_AM4_MASK               16U
#define CANIDMR4_AM5_MASK               32U
#define CANIDMR4_AM6_MASK               64U
#define CANIDMR4_AM7_MASK               128U


/*** CANIDMR5 - MSCAN Identifier Mask Register 5; 0xFFFF989D ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR5STR;
#define _CANIDMR5 (*(volatile CANIDMR5STR *)0xFFFF989D)
#define CANIDMR5                        _CANIDMR5.Byte
#define CANIDMR5_AM0                    _CANIDMR5.Bits.AM0
#define CANIDMR5_AM1                    _CANIDMR5.Bits.AM1
#define CANIDMR5_AM2                    _CANIDMR5.Bits.AM2
#define CANIDMR5_AM3                    _CANIDMR5.Bits.AM3
#define CANIDMR5_AM4                    _CANIDMR5.Bits.AM4
#define CANIDMR5_AM5                    _CANIDMR5.Bits.AM5
#define CANIDMR5_AM6                    _CANIDMR5.Bits.AM6
#define CANIDMR5_AM7                    _CANIDMR5.Bits.AM7

#define CANIDMR5_AM0_MASK               1U
#define CANIDMR5_AM1_MASK               2U
#define CANIDMR5_AM2_MASK               4U
#define CANIDMR5_AM3_MASK               8U
#define CANIDMR5_AM4_MASK               16U
#define CANIDMR5_AM5_MASK               32U
#define CANIDMR5_AM6_MASK               64U
#define CANIDMR5_AM7_MASK               128U


/*** CANIDMR6 - MSCAN Identifier Mask Register 6; 0xFFFF989E ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR6STR;
#define _CANIDMR6 (*(volatile CANIDMR6STR *)0xFFFF989E)
#define CANIDMR6                        _CANIDMR6.Byte
#define CANIDMR6_AM0                    _CANIDMR6.Bits.AM0
#define CANIDMR6_AM1                    _CANIDMR6.Bits.AM1
#define CANIDMR6_AM2                    _CANIDMR6.Bits.AM2
#define CANIDMR6_AM3                    _CANIDMR6.Bits.AM3
#define CANIDMR6_AM4                    _CANIDMR6.Bits.AM4
#define CANIDMR6_AM5                    _CANIDMR6.Bits.AM5
#define CANIDMR6_AM6                    _CANIDMR6.Bits.AM6
#define CANIDMR6_AM7                    _CANIDMR6.Bits.AM7

#define CANIDMR6_AM0_MASK               1U
#define CANIDMR6_AM1_MASK               2U
#define CANIDMR6_AM2_MASK               4U
#define CANIDMR6_AM3_MASK               8U
#define CANIDMR6_AM4_MASK               16U
#define CANIDMR6_AM5_MASK               32U
#define CANIDMR6_AM6_MASK               64U
#define CANIDMR6_AM7_MASK               128U


/*** CANIDMR7 - MSCAN Identifier Mask Register 7; 0xFFFF989F ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR7STR;
#define _CANIDMR7 (*(volatile CANIDMR7STR *)0xFFFF989F)
#define CANIDMR7                        _CANIDMR7.Byte
#define CANIDMR7_AM0                    _CANIDMR7.Bits.AM0
#define CANIDMR7_AM1                    _CANIDMR7.Bits.AM1
#define CANIDMR7_AM2                    _CANIDMR7.Bits.AM2
#define CANIDMR7_AM3                    _CANIDMR7.Bits.AM3
#define CANIDMR7_AM4                    _CANIDMR7.Bits.AM4
#define CANIDMR7_AM5                    _CANIDMR7.Bits.AM5
#define CANIDMR7_AM6                    _CANIDMR7.Bits.AM6
#define CANIDMR7_AM7                    _CANIDMR7.Bits.AM7

#define CANIDMR7_AM0_MASK               1U
#define CANIDMR7_AM1_MASK               2U
#define CANIDMR7_AM2_MASK               4U
#define CANIDMR7_AM3_MASK               8U
#define CANIDMR7_AM4_MASK               16U
#define CANIDMR7_AM5_MASK               32U
#define CANIDMR7_AM6_MASK               64U
#define CANIDMR7_AM7_MASK               128U


/*** CANRIDR - MSCAN 0 Receive Identifier Register; 0xFFFF98A0 ***/
typedef union {
  dword Dword;
   /* Overlapped registers: */
  struct {
    /*** CANRIDR0 - MSCAN 0 Receive Identifier Register 0; 0xFFFF98A0 ***/
    union {
      byte Byte;
      struct {
        byte ID21        :1;                                       /* Extended format identifier Bit 21 */
        byte ID22        :1;                                       /* Extended format identifier Bit 22 */
        byte ID23        :1;                                       /* Extended format identifier Bit 23 */
        byte ID24        :1;                                       /* Extended format identifier Bit 24 */
        byte ID25        :1;                                       /* Extended format identifier Bit 25 */
        byte ID26        :1;                                       /* Extended format identifier Bit 26 */
        byte ID27        :1;                                       /* Extended format identifier Bit 27 */
        byte ID28        :1;                                       /* Extended format identifier Bit 28 */
      } Bits;
    } CANRIDR0STR;
    #define CANRIDR0                    _CANRIDR.Overlap_STR.CANRIDR0STR.Byte
    #define CANRIDR0_ID21               _CANRIDR.Overlap_STR.CANRIDR0STR.Bits.ID21
    #define CANRIDR0_ID22               _CANRIDR.Overlap_STR.CANRIDR0STR.Bits.ID22
    #define CANRIDR0_ID23               _CANRIDR.Overlap_STR.CANRIDR0STR.Bits.ID23
    #define CANRIDR0_ID24               _CANRIDR.Overlap_STR.CANRIDR0STR.Bits.ID24
    #define CANRIDR0_ID25               _CANRIDR.Overlap_STR.CANRIDR0STR.Bits.ID25
    #define CANRIDR0_ID26               _CANRIDR.Overlap_STR.CANRIDR0STR.Bits.ID26
    #define CANRIDR0_ID27               _CANRIDR.Overlap_STR.CANRIDR0STR.Bits.ID27
    #define CANRIDR0_ID28               _CANRIDR.Overlap_STR.CANRIDR0STR.Bits.ID28
    /* CANRIDR_ARR: Access 4 CANRIDRx registers in an array */
    #define CANRIDR_ARR                 ((volatile byte *) &CANRIDR0)
    
    #define CANRIDR0_ID21_MASK          1U
    #define CANRIDR0_ID22_MASK          2U
    #define CANRIDR0_ID23_MASK          4U
    #define CANRIDR0_ID24_MASK          8U
    #define CANRIDR0_ID25_MASK          16U
    #define CANRIDR0_ID26_MASK          32U
    #define CANRIDR0_ID27_MASK          64U
    #define CANRIDR0_ID28_MASK          128U
    

    /*** CANRIDR1 - MSCAN 0 Receive Identifier Register 1; 0xFFFF98A1 ***/
    union {
      byte Byte;
      struct {
        byte ID15        :1;                                       /* Extended format identifier Bit 15 */
        byte ID16        :1;                                       /* Extended format identifier Bit 16 */
        byte ID17        :1;                                       /* Extended format identifier Bit 17 */
        byte IDE         :1;                                       /* ID Extended */
        byte SRR         :1;                                       /* Substitute Remote Request */
        byte ID18        :1;                                       /* Extended format identifier Bit 18 */
        byte ID19        :1;                                       /* Extended format identifier Bit 19 */
        byte ID20        :1;                                       /* Extended format identifier Bit 20 */
      } Bits;
      struct {
        byte grpID_15 :3;
        byte     :1;
        byte     :1;
        byte grpID_18 :3;
      } MergedBits;
    } CANRIDR1STR;
    #define CANRIDR1                    _CANRIDR.Overlap_STR.CANRIDR1STR.Byte
    #define CANRIDR1_ID15               _CANRIDR.Overlap_STR.CANRIDR1STR.Bits.ID15
    #define CANRIDR1_ID16               _CANRIDR.Overlap_STR.CANRIDR1STR.Bits.ID16
    #define CANRIDR1_ID17               _CANRIDR.Overlap_STR.CANRIDR1STR.Bits.ID17
    #define CANRIDR1_IDE                _CANRIDR.Overlap_STR.CANRIDR1STR.Bits.IDE
    #define CANRIDR1_SRR                _CANRIDR.Overlap_STR.CANRIDR1STR.Bits.SRR
    #define CANRIDR1_ID18               _CANRIDR.Overlap_STR.CANRIDR1STR.Bits.ID18
    #define CANRIDR1_ID19               _CANRIDR.Overlap_STR.CANRIDR1STR.Bits.ID19
    #define CANRIDR1_ID20               _CANRIDR.Overlap_STR.CANRIDR1STR.Bits.ID20
    #define CANRIDR1_ID_15              _CANRIDR.Overlap_STR.CANRIDR1STR.MergedBits.grpID_15
    #define CANRIDR1_ID_18              _CANRIDR.Overlap_STR.CANRIDR1STR.MergedBits.grpID_18
    #define CANRIDR1_ID                 CANRIDR1_ID_15
    
    #define CANRIDR1_ID15_MASK          1U
    #define CANRIDR1_ID16_MASK          2U
    #define CANRIDR1_ID17_MASK          4U
    #define CANRIDR1_IDE_MASK           8U
    #define CANRIDR1_SRR_MASK           16U
    #define CANRIDR1_ID18_MASK          32U
    #define CANRIDR1_ID19_MASK          64U
    #define CANRIDR1_ID20_MASK          128U
    #define CANRIDR1_ID_15_MASK         7U
    #define CANRIDR1_ID_15_BITNUM       0U
    #define CANRIDR1_ID_18_MASK         224U
    #define CANRIDR1_ID_18_BITNUM       5U
    

    /*** CANRIDR2 - MSCAN 0 Receive Identifier Register 2; 0xFFFF98A2 ***/
    union {
      byte Byte;
      struct {
        byte ID7         :1;                                       /* Extended format identifier Bit 7 */
        byte ID8         :1;                                       /* Extended format identifier Bit 8 */
        byte ID9         :1;                                       /* Extended format identifier Bit 9 */
        byte ID10        :1;                                       /* Extended format identifier Bit 10 */
        byte ID11        :1;                                       /* Extended format identifier Bit 11 */
        byte ID12        :1;                                       /* Extended format identifier Bit 12 */
        byte ID13        :1;                                       /* Extended format identifier Bit 13 */
        byte ID14        :1;                                       /* Extended format identifier Bit 14 */
      } Bits;
    } CANRIDR2STR;
    #define CANRIDR2                    _CANRIDR.Overlap_STR.CANRIDR2STR.Byte
    #define CANRIDR2_ID7                _CANRIDR.Overlap_STR.CANRIDR2STR.Bits.ID7
    #define CANRIDR2_ID8                _CANRIDR.Overlap_STR.CANRIDR2STR.Bits.ID8
    #define CANRIDR2_ID9                _CANRIDR.Overlap_STR.CANRIDR2STR.Bits.ID9
    #define CANRIDR2_ID10               _CANRIDR.Overlap_STR.CANRIDR2STR.Bits.ID10
    #define CANRIDR2_ID11               _CANRIDR.Overlap_STR.CANRIDR2STR.Bits.ID11
    #define CANRIDR2_ID12               _CANRIDR.Overlap_STR.CANRIDR2STR.Bits.ID12
    #define CANRIDR2_ID13               _CANRIDR.Overlap_STR.CANRIDR2STR.Bits.ID13
    #define CANRIDR2_ID14               _CANRIDR.Overlap_STR.CANRIDR2STR.Bits.ID14
    
    #define CANRIDR2_ID7_MASK           1U
    #define CANRIDR2_ID8_MASK           2U
    #define CANRIDR2_ID9_MASK           4U
    #define CANRIDR2_ID10_MASK          8U
    #define CANRIDR2_ID11_MASK          16U
    #define CANRIDR2_ID12_MASK          32U
    #define CANRIDR2_ID13_MASK          64U
    #define CANRIDR2_ID14_MASK          128U
    

    /*** CANRIDR3 - MSCAN 0 Receive Identifier Register 3; 0xFFFF98A3 ***/
    union {
      byte Byte;
      struct {
        byte RTR         :1;                                       /* Remote Transmission Request */
        byte ID0         :1;                                       /* Extended format identifier Bit 0 */
        byte ID1         :1;                                       /* Extended format identifier Bit 1 */
        byte ID2         :1;                                       /* Extended format identifier Bit 2 */
        byte ID3         :1;                                       /* Extended format identifier Bit 3 */
        byte ID4         :1;                                       /* Extended format identifier Bit 4 */
        byte ID5         :1;                                       /* Extended format identifier Bit 5 */
        byte ID6         :1;                                       /* Extended format identifier Bit 6 */
      } Bits;
      struct {
        byte     :1;
        byte grpID :7;
      } MergedBits;
    } CANRIDR3STR;
    #define CANRIDR3                    _CANRIDR.Overlap_STR.CANRIDR3STR.Byte
    #define CANRIDR3_RTR                _CANRIDR.Overlap_STR.CANRIDR3STR.Bits.RTR
    #define CANRIDR3_ID0                _CANRIDR.Overlap_STR.CANRIDR3STR.Bits.ID0
    #define CANRIDR3_ID1                _CANRIDR.Overlap_STR.CANRIDR3STR.Bits.ID1
    #define CANRIDR3_ID2                _CANRIDR.Overlap_STR.CANRIDR3STR.Bits.ID2
    #define CANRIDR3_ID3                _CANRIDR.Overlap_STR.CANRIDR3STR.Bits.ID3
    #define CANRIDR3_ID4                _CANRIDR.Overlap_STR.CANRIDR3STR.Bits.ID4
    #define CANRIDR3_ID5                _CANRIDR.Overlap_STR.CANRIDR3STR.Bits.ID5
    #define CANRIDR3_ID6                _CANRIDR.Overlap_STR.CANRIDR3STR.Bits.ID6
    #define CANRIDR3_ID                 _CANRIDR.Overlap_STR.CANRIDR3STR.MergedBits.grpID
    
    #define CANRIDR3_RTR_MASK           1U
    #define CANRIDR3_ID0_MASK           2U
    #define CANRIDR3_ID1_MASK           4U
    #define CANRIDR3_ID2_MASK           8U
    #define CANRIDR3_ID3_MASK           16U
    #define CANRIDR3_ID4_MASK           32U
    #define CANRIDR3_ID5_MASK           64U
    #define CANRIDR3_ID6_MASK           128U
    #define CANRIDR3_ID_MASK            254U
    #define CANRIDR3_ID_BITNUM          1U
    
  } Overlap_STR;

  struct {
    dword RTR        :1;                                       /* Remote Transmission Request */
    dword ID0        :1;                                       /* Extended format identifier Bit 0 */
    dword ID1        :1;                                       /* Extended format identifier Bit 1 */
    dword ID2        :1;                                       /* Extended format identifier Bit 2 */
    dword ID3        :1;                                       /* Extended format identifier Bit 3 */
    dword ID4        :1;                                       /* Extended format identifier Bit 4 */
    dword ID5        :1;                                       /* Extended format identifier Bit 5 */
    dword ID6        :1;                                       /* Extended format identifier Bit 6 */
    dword ID7        :1;                                       /* Extended format identifier Bit 7 */
    dword ID8        :1;                                       /* Extended format identifier Bit 8 */
    dword ID9        :1;                                       /* Extended format identifier Bit 9 */
    dword ID10       :1;                                       /* Extended format identifier Bit 10 */
    dword ID11       :1;                                       /* Extended format identifier Bit 11 */
    dword ID12       :1;                                       /* Extended format identifier Bit 12 */
    dword ID13       :1;                                       /* Extended format identifier Bit 13 */
    dword ID14       :1;                                       /* Extended format identifier Bit 14 */
    dword ID15       :1;                                       /* Extended format identifier Bit 15 */
    dword ID16       :1;                                       /* Extended format identifier Bit 16 */
    dword ID17       :1;                                       /* Extended format identifier Bit 17 */
    dword IDE        :1;                                       /* ID Extended */
    dword SRR        :1;                                       /* Substitute Remote Request */
    dword ID18       :1;                                       /* Extended format identifier Bit 18 */
    dword ID19       :1;                                       /* Extended format identifier Bit 19 */
    dword ID20       :1;                                       /* Extended format identifier Bit 20 */
    dword ID21       :1;                                       /* Extended format identifier Bit 21 */
    dword ID22       :1;                                       /* Extended format identifier Bit 22 */
    dword ID23       :1;                                       /* Extended format identifier Bit 23 */
    dword ID24       :1;                                       /* Extended format identifier Bit 24 */
    dword ID25       :1;                                       /* Extended format identifier Bit 25 */
    dword ID26       :1;                                       /* Extended format identifier Bit 26 */
    dword ID27       :1;                                       /* Extended format identifier Bit 27 */
    dword ID28       :1;                                       /* Extended format identifier Bit 28 */
  } Bits;
  struct {
    dword        :1;
    dword grpID  :18;
    dword        :1;
    dword        :1;
    dword grpID_18 :11;
  } MergedBits;
} CANRIDRSTR;
#define _CANRIDR (*(volatile CANRIDRSTR *)0xFFFF98A0)
#define CANRIDR                         _CANRIDR.Dword
#define CANRIDR_RTR                     _CANRIDR.Bits.RTR
#define CANRIDR_ID0                     _CANRIDR.Bits.ID0
#define CANRIDR_ID1                     _CANRIDR.Bits.ID1
#define CANRIDR_ID2                     _CANRIDR.Bits.ID2
#define CANRIDR_ID3                     _CANRIDR.Bits.ID3
#define CANRIDR_ID4                     _CANRIDR.Bits.ID4
#define CANRIDR_ID5                     _CANRIDR.Bits.ID5
#define CANRIDR_ID6                     _CANRIDR.Bits.ID6
#define CANRIDR_ID7                     _CANRIDR.Bits.ID7
#define CANRIDR_ID8                     _CANRIDR.Bits.ID8
#define CANRIDR_ID9                     _CANRIDR.Bits.ID9
#define CANRIDR_ID10                    _CANRIDR.Bits.ID10
#define CANRIDR_ID11                    _CANRIDR.Bits.ID11
#define CANRIDR_ID12                    _CANRIDR.Bits.ID12
#define CANRIDR_ID13                    _CANRIDR.Bits.ID13
#define CANRIDR_ID14                    _CANRIDR.Bits.ID14
#define CANRIDR_ID15                    _CANRIDR.Bits.ID15
#define CANRIDR_ID16                    _CANRIDR.Bits.ID16
#define CANRIDR_ID17                    _CANRIDR.Bits.ID17
#define CANRIDR_IDE                     _CANRIDR.Bits.IDE
#define CANRIDR_SRR                     _CANRIDR.Bits.SRR
#define CANRIDR_ID18                    _CANRIDR.Bits.ID18
#define CANRIDR_ID19                    _CANRIDR.Bits.ID19
#define CANRIDR_ID20                    _CANRIDR.Bits.ID20
#define CANRIDR_ID21                    _CANRIDR.Bits.ID21
#define CANRIDR_ID22                    _CANRIDR.Bits.ID22
#define CANRIDR_ID23                    _CANRIDR.Bits.ID23
#define CANRIDR_ID24                    _CANRIDR.Bits.ID24
#define CANRIDR_ID25                    _CANRIDR.Bits.ID25
#define CANRIDR_ID26                    _CANRIDR.Bits.ID26
#define CANRIDR_ID27                    _CANRIDR.Bits.ID27
#define CANRIDR_ID28                    _CANRIDR.Bits.ID28
#define CANRIDR_ID                      _CANRIDR.MergedBits.grpID
#define CANRIDR_ID_18                   _CANRIDR.MergedBits.grpID_18

#define CANRIDR_RTR_MASK                1UL
#define CANRIDR_ID0_MASK                2UL
#define CANRIDR_ID1_MASK                4UL
#define CANRIDR_ID2_MASK                8UL
#define CANRIDR_ID3_MASK                16UL
#define CANRIDR_ID4_MASK                32UL
#define CANRIDR_ID5_MASK                64UL
#define CANRIDR_ID6_MASK                128UL
#define CANRIDR_ID7_MASK                256UL
#define CANRIDR_ID8_MASK                512UL
#define CANRIDR_ID9_MASK                1024UL
#define CANRIDR_ID10_MASK               2048UL
#define CANRIDR_ID11_MASK               4096UL
#define CANRIDR_ID12_MASK               8192UL
#define CANRIDR_ID13_MASK               16384UL
#define CANRIDR_ID14_MASK               32768UL
#define CANRIDR_ID15_MASK               65536UL
#define CANRIDR_ID16_MASK               131072UL
#define CANRIDR_ID17_MASK               262144UL
#define CANRIDR_IDE_MASK                524288UL
#define CANRIDR_SRR_MASK                1048576UL
#define CANRIDR_ID18_MASK               2097152UL
#define CANRIDR_ID19_MASK               4194304UL
#define CANRIDR_ID20_MASK               8388608UL
#define CANRIDR_ID21_MASK               16777216UL
#define CANRIDR_ID22_MASK               33554432UL
#define CANRIDR_ID23_MASK               67108864UL
#define CANRIDR_ID24_MASK               134217728UL
#define CANRIDR_ID25_MASK               268435456UL
#define CANRIDR_ID26_MASK               536870912UL
#define CANRIDR_ID27_MASK               1073741824UL
#define CANRIDR_ID28_MASK               2147483648UL
#define CANRIDR_ID_MASK                 524286U
#define CANRIDR_ID_BITNUM               1U
#define CANRIDR_ID_18_MASK              4292870144U
#define CANRIDR_ID_18_BITNUM            21U


/*** CANRDSR0 - MSCAN Receive Data Segment Register 0; 0xFFFF98A4 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRDSR0STR;
#define _CANRDSR0 (*(volatile CANRDSR0STR *)0xFFFF98A4)
#define CANRDSR0                        _CANRDSR0.Byte
#define CANRDSR0_DB0                    _CANRDSR0.Bits.DB0
#define CANRDSR0_DB1                    _CANRDSR0.Bits.DB1
#define CANRDSR0_DB2                    _CANRDSR0.Bits.DB2
#define CANRDSR0_DB3                    _CANRDSR0.Bits.DB3
#define CANRDSR0_DB4                    _CANRDSR0.Bits.DB4
#define CANRDSR0_DB5                    _CANRDSR0.Bits.DB5
#define CANRDSR0_DB6                    _CANRDSR0.Bits.DB6
#define CANRDSR0_DB7                    _CANRDSR0.Bits.DB7
/* CANRDSR_ARR: Access 8 CANRDSRx registers in an array */
#define CANRDSR_ARR                     ((volatile byte *) &CANRDSR0)

#define CANRDSR0_DB0_MASK               1U
#define CANRDSR0_DB1_MASK               2U
#define CANRDSR0_DB2_MASK               4U
#define CANRDSR0_DB3_MASK               8U
#define CANRDSR0_DB4_MASK               16U
#define CANRDSR0_DB5_MASK               32U
#define CANRDSR0_DB6_MASK               64U
#define CANRDSR0_DB7_MASK               128U


/*** CANRDSR1 - MSCAN Receive Data Segment Register 1; 0xFFFF98A5 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRDSR1STR;
#define _CANRDSR1 (*(volatile CANRDSR1STR *)0xFFFF98A5)
#define CANRDSR1                        _CANRDSR1.Byte
#define CANRDSR1_DB0                    _CANRDSR1.Bits.DB0
#define CANRDSR1_DB1                    _CANRDSR1.Bits.DB1
#define CANRDSR1_DB2                    _CANRDSR1.Bits.DB2
#define CANRDSR1_DB3                    _CANRDSR1.Bits.DB3
#define CANRDSR1_DB4                    _CANRDSR1.Bits.DB4
#define CANRDSR1_DB5                    _CANRDSR1.Bits.DB5
#define CANRDSR1_DB6                    _CANRDSR1.Bits.DB6
#define CANRDSR1_DB7                    _CANRDSR1.Bits.DB7

#define CANRDSR1_DB0_MASK               1U
#define CANRDSR1_DB1_MASK               2U
#define CANRDSR1_DB2_MASK               4U
#define CANRDSR1_DB3_MASK               8U
#define CANRDSR1_DB4_MASK               16U
#define CANRDSR1_DB5_MASK               32U
#define CANRDSR1_DB6_MASK               64U
#define CANRDSR1_DB7_MASK               128U


/*** CANRDSR2 - MSCAN Receive Data Segment Register 2; 0xFFFF98A6 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRDSR2STR;
#define _CANRDSR2 (*(volatile CANRDSR2STR *)0xFFFF98A6)
#define CANRDSR2                        _CANRDSR2.Byte
#define CANRDSR2_DB0                    _CANRDSR2.Bits.DB0
#define CANRDSR2_DB1                    _CANRDSR2.Bits.DB1
#define CANRDSR2_DB2                    _CANRDSR2.Bits.DB2
#define CANRDSR2_DB3                    _CANRDSR2.Bits.DB3
#define CANRDSR2_DB4                    _CANRDSR2.Bits.DB4
#define CANRDSR2_DB5                    _CANRDSR2.Bits.DB5
#define CANRDSR2_DB6                    _CANRDSR2.Bits.DB6
#define CANRDSR2_DB7                    _CANRDSR2.Bits.DB7

#define CANRDSR2_DB0_MASK               1U
#define CANRDSR2_DB1_MASK               2U
#define CANRDSR2_DB2_MASK               4U
#define CANRDSR2_DB3_MASK               8U
#define CANRDSR2_DB4_MASK               16U
#define CANRDSR2_DB5_MASK               32U
#define CANRDSR2_DB6_MASK               64U
#define CANRDSR2_DB7_MASK               128U


/*** CANRDSR3 - MSCAN Receive Data Segment Register 3; 0xFFFF98A7 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRDSR3STR;
#define _CANRDSR3 (*(volatile CANRDSR3STR *)0xFFFF98A7)
#define CANRDSR3                        _CANRDSR3.Byte
#define CANRDSR3_DB0                    _CANRDSR3.Bits.DB0
#define CANRDSR3_DB1                    _CANRDSR3.Bits.DB1
#define CANRDSR3_DB2                    _CANRDSR3.Bits.DB2
#define CANRDSR3_DB3                    _CANRDSR3.Bits.DB3
#define CANRDSR3_DB4                    _CANRDSR3.Bits.DB4
#define CANRDSR3_DB5                    _CANRDSR3.Bits.DB5
#define CANRDSR3_DB6                    _CANRDSR3.Bits.DB6
#define CANRDSR3_DB7                    _CANRDSR3.Bits.DB7

#define CANRDSR3_DB0_MASK               1U
#define CANRDSR3_DB1_MASK               2U
#define CANRDSR3_DB2_MASK               4U
#define CANRDSR3_DB3_MASK               8U
#define CANRDSR3_DB4_MASK               16U
#define CANRDSR3_DB5_MASK               32U
#define CANRDSR3_DB6_MASK               64U
#define CANRDSR3_DB7_MASK               128U


/*** CANRDSR4 - MSCAN Receive Data Segment Register 4; 0xFFFF98A8 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRDSR4STR;
#define _CANRDSR4 (*(volatile CANRDSR4STR *)0xFFFF98A8)
#define CANRDSR4                        _CANRDSR4.Byte
#define CANRDSR4_DB0                    _CANRDSR4.Bits.DB0
#define CANRDSR4_DB1                    _CANRDSR4.Bits.DB1
#define CANRDSR4_DB2                    _CANRDSR4.Bits.DB2
#define CANRDSR4_DB3                    _CANRDSR4.Bits.DB3
#define CANRDSR4_DB4                    _CANRDSR4.Bits.DB4
#define CANRDSR4_DB5                    _CANRDSR4.Bits.DB5
#define CANRDSR4_DB6                    _CANRDSR4.Bits.DB6
#define CANRDSR4_DB7                    _CANRDSR4.Bits.DB7

#define CANRDSR4_DB0_MASK               1U
#define CANRDSR4_DB1_MASK               2U
#define CANRDSR4_DB2_MASK               4U
#define CANRDSR4_DB3_MASK               8U
#define CANRDSR4_DB4_MASK               16U
#define CANRDSR4_DB5_MASK               32U
#define CANRDSR4_DB6_MASK               64U
#define CANRDSR4_DB7_MASK               128U


/*** CANRDSR5 - MSCAN Receive Data Segment Register 5; 0xFFFF98A9 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRDSR5STR;
#define _CANRDSR5 (*(volatile CANRDSR5STR *)0xFFFF98A9)
#define CANRDSR5                        _CANRDSR5.Byte
#define CANRDSR5_DB0                    _CANRDSR5.Bits.DB0
#define CANRDSR5_DB1                    _CANRDSR5.Bits.DB1
#define CANRDSR5_DB2                    _CANRDSR5.Bits.DB2
#define CANRDSR5_DB3                    _CANRDSR5.Bits.DB3
#define CANRDSR5_DB4                    _CANRDSR5.Bits.DB4
#define CANRDSR5_DB5                    _CANRDSR5.Bits.DB5
#define CANRDSR5_DB6                    _CANRDSR5.Bits.DB6
#define CANRDSR5_DB7                    _CANRDSR5.Bits.DB7

#define CANRDSR5_DB0_MASK               1U
#define CANRDSR5_DB1_MASK               2U
#define CANRDSR5_DB2_MASK               4U
#define CANRDSR5_DB3_MASK               8U
#define CANRDSR5_DB4_MASK               16U
#define CANRDSR5_DB5_MASK               32U
#define CANRDSR5_DB6_MASK               64U
#define CANRDSR5_DB7_MASK               128U


/*** CANRDSR6 - MSCAN Receive Data Segment Register 6; 0xFFFF98AA ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRDSR6STR;
#define _CANRDSR6 (*(volatile CANRDSR6STR *)0xFFFF98AA)
#define CANRDSR6                        _CANRDSR6.Byte
#define CANRDSR6_DB0                    _CANRDSR6.Bits.DB0
#define CANRDSR6_DB1                    _CANRDSR6.Bits.DB1
#define CANRDSR6_DB2                    _CANRDSR6.Bits.DB2
#define CANRDSR6_DB3                    _CANRDSR6.Bits.DB3
#define CANRDSR6_DB4                    _CANRDSR6.Bits.DB4
#define CANRDSR6_DB5                    _CANRDSR6.Bits.DB5
#define CANRDSR6_DB6                    _CANRDSR6.Bits.DB6
#define CANRDSR6_DB7                    _CANRDSR6.Bits.DB7

#define CANRDSR6_DB0_MASK               1U
#define CANRDSR6_DB1_MASK               2U
#define CANRDSR6_DB2_MASK               4U
#define CANRDSR6_DB3_MASK               8U
#define CANRDSR6_DB4_MASK               16U
#define CANRDSR6_DB5_MASK               32U
#define CANRDSR6_DB6_MASK               64U
#define CANRDSR6_DB7_MASK               128U


/*** CANRDSR7 - MSCAN Receive Data Segment Register 7; 0xFFFF98AB ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRDSR7STR;
#define _CANRDSR7 (*(volatile CANRDSR7STR *)0xFFFF98AB)
#define CANRDSR7                        _CANRDSR7.Byte
#define CANRDSR7_DB0                    _CANRDSR7.Bits.DB0
#define CANRDSR7_DB1                    _CANRDSR7.Bits.DB1
#define CANRDSR7_DB2                    _CANRDSR7.Bits.DB2
#define CANRDSR7_DB3                    _CANRDSR7.Bits.DB3
#define CANRDSR7_DB4                    _CANRDSR7.Bits.DB4
#define CANRDSR7_DB5                    _CANRDSR7.Bits.DB5
#define CANRDSR7_DB6                    _CANRDSR7.Bits.DB6
#define CANRDSR7_DB7                    _CANRDSR7.Bits.DB7

#define CANRDSR7_DB0_MASK               1U
#define CANRDSR7_DB1_MASK               2U
#define CANRDSR7_DB2_MASK               4U
#define CANRDSR7_DB3_MASK               8U
#define CANRDSR7_DB4_MASK               16U
#define CANRDSR7_DB5_MASK               32U
#define CANRDSR7_DB6_MASK               64U
#define CANRDSR7_DB7_MASK               128U


/*** CANRDLR - MSCAN Receive Data Length Register; 0xFFFF98AC ***/
typedef union {
  byte Byte;
  struct {
    byte DLC0        :1;                                       /* Data Length Code Bit 0 */
    byte DLC1        :1;                                       /* Data Length Code Bit 1 */
    byte DLC2        :1;                                       /* Data Length Code Bit 2 */
    byte DLC3        :1;                                       /* Data Length Code Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDLC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRDLRSTR;
#define _CANRDLR (*(volatile CANRDLRSTR *)0xFFFF98AC)
#define CANRDLR                         _CANRDLR.Byte
#define CANRDLR_DLC0                    _CANRDLR.Bits.DLC0
#define CANRDLR_DLC1                    _CANRDLR.Bits.DLC1
#define CANRDLR_DLC2                    _CANRDLR.Bits.DLC2
#define CANRDLR_DLC3                    _CANRDLR.Bits.DLC3
#define CANRDLR_DLC                     _CANRDLR.MergedBits.grpDLC

#define CANRDLR_DLC0_MASK               1U
#define CANRDLR_DLC1_MASK               2U
#define CANRDLR_DLC2_MASK               4U
#define CANRDLR_DLC3_MASK               8U
#define CANRDLR_DLC_MASK                15U
#define CANRDLR_DLC_BITNUM              0U


/*** CANRTSR - MSCAN Receive Time Stamp Register; 0xFFFF98AE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CANRTSRH - MSCAN Receive Time Stamp Register High; 0xFFFF98AE ***/
    union {
      byte Byte;
      struct {
        byte TSR8        :1;                                       /* Time Stamp Bit 8 */
        byte TSR9        :1;                                       /* Time Stamp Bit 9 */
        byte TSR10       :1;                                       /* Time Stamp Bit 10 */
        byte TSR11       :1;                                       /* Time Stamp Bit 11 */
        byte TSR12       :1;                                       /* Time Stamp Bit 12 */
        byte TSR13       :1;                                       /* Time Stamp Bit 13 */
        byte TSR14       :1;                                       /* Time Stamp Bit 14 */
        byte TSR15       :1;                                       /* Time Stamp Bit 15 */
      } Bits;
    } CANRTSRHSTR;
    #define CANRTSRH                    _CANRTSR.Overlap_STR.CANRTSRHSTR.Byte
    #define CANRTSRH_TSR8               _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR8
    #define CANRTSRH_TSR9               _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR9
    #define CANRTSRH_TSR10              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR10
    #define CANRTSRH_TSR11              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR11
    #define CANRTSRH_TSR12              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR12
    #define CANRTSRH_TSR13              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR13
    #define CANRTSRH_TSR14              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR14
    #define CANRTSRH_TSR15              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR15
    
    #define CANRTSRH_TSR8_MASK          1U
    #define CANRTSRH_TSR9_MASK          2U
    #define CANRTSRH_TSR10_MASK         4U
    #define CANRTSRH_TSR11_MASK         8U
    #define CANRTSRH_TSR12_MASK         16U
    #define CANRTSRH_TSR13_MASK         32U
    #define CANRTSRH_TSR14_MASK         64U
    #define CANRTSRH_TSR15_MASK         128U
    

    /*** CANRTSRL - MSCAN Receive Time Stamp Register Low; 0xFFFF98AF ***/
    union {
      byte Byte;
      struct {
        byte TSR0        :1;                                       /* Time Stamp Bit 0 */
        byte TSR1        :1;                                       /* Time Stamp Bit 1 */
        byte TSR2        :1;                                       /* Time Stamp Bit 2 */
        byte TSR3        :1;                                       /* Time Stamp Bit 3 */
        byte TSR4        :1;                                       /* Time Stamp Bit 4 */
        byte TSR5        :1;                                       /* Time Stamp Bit 5 */
        byte TSR6        :1;                                       /* Time Stamp Bit 6 */
        byte TSR7        :1;                                       /* Time Stamp Bit 7 */
      } Bits;
    } CANRTSRLSTR;
    #define CANRTSRL                    _CANRTSR.Overlap_STR.CANRTSRLSTR.Byte
    #define CANRTSRL_TSR0               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR0
    #define CANRTSRL_TSR1               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR1
    #define CANRTSRL_TSR2               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR2
    #define CANRTSRL_TSR3               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR3
    #define CANRTSRL_TSR4               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR4
    #define CANRTSRL_TSR5               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR5
    #define CANRTSRL_TSR6               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR6
    #define CANRTSRL_TSR7               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR7
    
    #define CANRTSRL_TSR0_MASK          1U
    #define CANRTSRL_TSR1_MASK          2U
    #define CANRTSRL_TSR2_MASK          4U
    #define CANRTSRL_TSR3_MASK          8U
    #define CANRTSRL_TSR4_MASK          16U
    #define CANRTSRL_TSR5_MASK          32U
    #define CANRTSRL_TSR6_MASK          64U
    #define CANRTSRL_TSR7_MASK          128U
    
  } Overlap_STR;

  struct {
    word TSR0        :1;                                       /* Time Stamp Bit 0 */
    word TSR1        :1;                                       /* Time Stamp Bit 1 */
    word TSR2        :1;                                       /* Time Stamp Bit 2 */
    word TSR3        :1;                                       /* Time Stamp Bit 3 */
    word TSR4        :1;                                       /* Time Stamp Bit 4 */
    word TSR5        :1;                                       /* Time Stamp Bit 5 */
    word TSR6        :1;                                       /* Time Stamp Bit 6 */
    word TSR7        :1;                                       /* Time Stamp Bit 7 */
    word TSR8        :1;                                       /* Time Stamp Bit 8 */
    word TSR9        :1;                                       /* Time Stamp Bit 9 */
    word TSR10       :1;                                       /* Time Stamp Bit 10 */
    word TSR11       :1;                                       /* Time Stamp Bit 11 */
    word TSR12       :1;                                       /* Time Stamp Bit 12 */
    word TSR13       :1;                                       /* Time Stamp Bit 13 */
    word TSR14       :1;                                       /* Time Stamp Bit 14 */
    word TSR15       :1;                                       /* Time Stamp Bit 15 */
  } Bits;
} CANRTSRSTR;
#define _CANRTSR (*(volatile CANRTSRSTR *)0xFFFF98AE)
#define CANRTSR                         _CANRTSR.Word
#define CANRTSR_TSR0                    _CANRTSR.Bits.TSR0
#define CANRTSR_TSR1                    _CANRTSR.Bits.TSR1
#define CANRTSR_TSR2                    _CANRTSR.Bits.TSR2
#define CANRTSR_TSR3                    _CANRTSR.Bits.TSR3
#define CANRTSR_TSR4                    _CANRTSR.Bits.TSR4
#define CANRTSR_TSR5                    _CANRTSR.Bits.TSR5
#define CANRTSR_TSR6                    _CANRTSR.Bits.TSR6
#define CANRTSR_TSR7                    _CANRTSR.Bits.TSR7
#define CANRTSR_TSR8                    _CANRTSR.Bits.TSR8
#define CANRTSR_TSR9                    _CANRTSR.Bits.TSR9
#define CANRTSR_TSR10                   _CANRTSR.Bits.TSR10
#define CANRTSR_TSR11                   _CANRTSR.Bits.TSR11
#define CANRTSR_TSR12                   _CANRTSR.Bits.TSR12
#define CANRTSR_TSR13                   _CANRTSR.Bits.TSR13
#define CANRTSR_TSR14                   _CANRTSR.Bits.TSR14
#define CANRTSR_TSR15                   _CANRTSR.Bits.TSR15

#define CANRTSR_TSR0_MASK               1U
#define CANRTSR_TSR1_MASK               2U
#define CANRTSR_TSR2_MASK               4U
#define CANRTSR_TSR3_MASK               8U
#define CANRTSR_TSR4_MASK               16U
#define CANRTSR_TSR5_MASK               32U
#define CANRTSR_TSR6_MASK               64U
#define CANRTSR_TSR7_MASK               128U
#define CANRTSR_TSR8_MASK               256U
#define CANRTSR_TSR9_MASK               512U
#define CANRTSR_TSR10_MASK              1024U
#define CANRTSR_TSR11_MASK              2048U
#define CANRTSR_TSR12_MASK              4096U
#define CANRTSR_TSR13_MASK              8192U
#define CANRTSR_TSR14_MASK              16384U
#define CANRTSR_TSR15_MASK              32768U


/*** CANTIDR - MSCAN 0 Transmit Identifier Register; 0xFFFF98B0 ***/
typedef union {
  dword Dword;
   /* Overlapped registers: */
  struct {
    /*** CANTIDR0 - MSCAN 0 Transmit Identifier Register 0; 0xFFFF98B0 ***/
    union {
      byte Byte;
      struct {
        byte ID21        :1;                                       /* Extended format identifier Bit 21 */
        byte ID22        :1;                                       /* Extended format identifier Bit 22 */
        byte ID23        :1;                                       /* Extended format identifier Bit 23 */
        byte ID24        :1;                                       /* Extended format identifier Bit 24 */
        byte ID25        :1;                                       /* Extended format identifier Bit 25 */
        byte ID26        :1;                                       /* Extended format identifier Bit 26 */
        byte ID27        :1;                                       /* Extended format identifier Bit 27 */
        byte ID28        :1;                                       /* Extended format identifier Bit 28 */
      } Bits;
    } CANTIDR0STR;
    #define CANTIDR0                    _CANTIDR.Overlap_STR.CANTIDR0STR.Byte
    #define CANTIDR0_ID21               _CANTIDR.Overlap_STR.CANTIDR0STR.Bits.ID21
    #define CANTIDR0_ID22               _CANTIDR.Overlap_STR.CANTIDR0STR.Bits.ID22
    #define CANTIDR0_ID23               _CANTIDR.Overlap_STR.CANTIDR0STR.Bits.ID23
    #define CANTIDR0_ID24               _CANTIDR.Overlap_STR.CANTIDR0STR.Bits.ID24
    #define CANTIDR0_ID25               _CANTIDR.Overlap_STR.CANTIDR0STR.Bits.ID25
    #define CANTIDR0_ID26               _CANTIDR.Overlap_STR.CANTIDR0STR.Bits.ID26
    #define CANTIDR0_ID27               _CANTIDR.Overlap_STR.CANTIDR0STR.Bits.ID27
    #define CANTIDR0_ID28               _CANTIDR.Overlap_STR.CANTIDR0STR.Bits.ID28
    /* CANTIDR_ARR: Access 4 CANTIDRx registers in an array */
    #define CANTIDR_ARR                 ((volatile byte *) &CANTIDR0)
    
    #define CANTIDR0_ID21_MASK          1U
    #define CANTIDR0_ID22_MASK          2U
    #define CANTIDR0_ID23_MASK          4U
    #define CANTIDR0_ID24_MASK          8U
    #define CANTIDR0_ID25_MASK          16U
    #define CANTIDR0_ID26_MASK          32U
    #define CANTIDR0_ID27_MASK          64U
    #define CANTIDR0_ID28_MASK          128U
    

    /*** CANTIDR1 - MSCAN 0 Transmit Identifier Register 1; 0xFFFF98B1 ***/
    union {
      byte Byte;
      struct {
        byte ID15        :1;                                       /* Extended format identifier Bit 15 */
        byte ID16        :1;                                       /* Extended format identifier Bit 16 */
        byte ID17        :1;                                       /* Extended format identifier Bit 17 */
        byte IDE         :1;                                       /* ID Extended */
        byte SRR         :1;                                       /* Substitute Remote Request */
        byte ID18        :1;                                       /* Extended format identifier Bit 18 */
        byte ID19        :1;                                       /* Extended format identifier Bit 19 */
        byte ID20        :1;                                       /* Extended format identifier Bit 20 */
      } Bits;
      struct {
        byte grpID_15 :3;
        byte     :1;
        byte     :1;
        byte grpID_18 :3;
      } MergedBits;
    } CANTIDR1STR;
    #define CANTIDR1                    _CANTIDR.Overlap_STR.CANTIDR1STR.Byte
    #define CANTIDR1_ID15               _CANTIDR.Overlap_STR.CANTIDR1STR.Bits.ID15
    #define CANTIDR1_ID16               _CANTIDR.Overlap_STR.CANTIDR1STR.Bits.ID16
    #define CANTIDR1_ID17               _CANTIDR.Overlap_STR.CANTIDR1STR.Bits.ID17
    #define CANTIDR1_IDE                _CANTIDR.Overlap_STR.CANTIDR1STR.Bits.IDE
    #define CANTIDR1_SRR                _CANTIDR.Overlap_STR.CANTIDR1STR.Bits.SRR
    #define CANTIDR1_ID18               _CANTIDR.Overlap_STR.CANTIDR1STR.Bits.ID18
    #define CANTIDR1_ID19               _CANTIDR.Overlap_STR.CANTIDR1STR.Bits.ID19
    #define CANTIDR1_ID20               _CANTIDR.Overlap_STR.CANTIDR1STR.Bits.ID20
    #define CANTIDR1_ID_15              _CANTIDR.Overlap_STR.CANTIDR1STR.MergedBits.grpID_15
    #define CANTIDR1_ID_18              _CANTIDR.Overlap_STR.CANTIDR1STR.MergedBits.grpID_18
    #define CANTIDR1_ID                 CANTIDR1_ID_15
    
    #define CANTIDR1_ID15_MASK          1U
    #define CANTIDR1_ID16_MASK          2U
    #define CANTIDR1_ID17_MASK          4U
    #define CANTIDR1_IDE_MASK           8U
    #define CANTIDR1_SRR_MASK           16U
    #define CANTIDR1_ID18_MASK          32U
    #define CANTIDR1_ID19_MASK          64U
    #define CANTIDR1_ID20_MASK          128U
    #define CANTIDR1_ID_15_MASK         7U
    #define CANTIDR1_ID_15_BITNUM       0U
    #define CANTIDR1_ID_18_MASK         224U
    #define CANTIDR1_ID_18_BITNUM       5U
    

    /*** CANTIDR2 - MSCAN 0 Transmit Identifier Register 2; 0xFFFF98B2 ***/
    union {
      byte Byte;
      struct {
        byte ID7         :1;                                       /* Extended format identifier Bit 7 */
        byte ID8         :1;                                       /* Extended format identifier Bit 8 */
        byte ID9         :1;                                       /* Extended format identifier Bit 9 */
        byte ID10        :1;                                       /* Extended format identifier Bit 10 */
        byte ID11        :1;                                       /* Extended format identifier Bit 11 */
        byte ID12        :1;                                       /* Extended format identifier Bit 12 */
        byte ID13        :1;                                       /* Extended format identifier Bit 13 */
        byte ID14        :1;                                       /* Extended format identifier Bit 14 */
      } Bits;
    } CANTIDR2STR;
    #define CANTIDR2                    _CANTIDR.Overlap_STR.CANTIDR2STR.Byte
    #define CANTIDR2_ID7                _CANTIDR.Overlap_STR.CANTIDR2STR.Bits.ID7
    #define CANTIDR2_ID8                _CANTIDR.Overlap_STR.CANTIDR2STR.Bits.ID8
    #define CANTIDR2_ID9                _CANTIDR.Overlap_STR.CANTIDR2STR.Bits.ID9
    #define CANTIDR2_ID10               _CANTIDR.Overlap_STR.CANTIDR2STR.Bits.ID10
    #define CANTIDR2_ID11               _CANTIDR.Overlap_STR.CANTIDR2STR.Bits.ID11
    #define CANTIDR2_ID12               _CANTIDR.Overlap_STR.CANTIDR2STR.Bits.ID12
    #define CANTIDR2_ID13               _CANTIDR.Overlap_STR.CANTIDR2STR.Bits.ID13
    #define CANTIDR2_ID14               _CANTIDR.Overlap_STR.CANTIDR2STR.Bits.ID14
    
    #define CANTIDR2_ID7_MASK           1U
    #define CANTIDR2_ID8_MASK           2U
    #define CANTIDR2_ID9_MASK           4U
    #define CANTIDR2_ID10_MASK          8U
    #define CANTIDR2_ID11_MASK          16U
    #define CANTIDR2_ID12_MASK          32U
    #define CANTIDR2_ID13_MASK          64U
    #define CANTIDR2_ID14_MASK          128U
    

    /*** CANTIDR3 - MSCAN 0 Transmit Identifier Register 3; 0xFFFF98B3 ***/
    union {
      byte Byte;
      struct {
        byte RTR         :1;                                       /* Remote Transmission Request */
        byte ID0         :1;                                       /* Extended format identifier Bit 0 */
        byte ID1         :1;                                       /* Extended format identifier Bit 1 */
        byte ID2         :1;                                       /* Extended format identifier Bit 2 */
        byte ID3         :1;                                       /* Extended format identifier Bit 3 */
        byte ID4         :1;                                       /* Extended format identifier Bit 4 */
        byte ID5         :1;                                       /* Extended format identifier Bit 5 */
        byte ID6         :1;                                       /* Extended format identifier Bit 6 */
      } Bits;
      struct {
        byte     :1;
        byte grpID :7;
      } MergedBits;
    } CANTIDR3STR;
    #define CANTIDR3                    _CANTIDR.Overlap_STR.CANTIDR3STR.Byte
    #define CANTIDR3_RTR                _CANTIDR.Overlap_STR.CANTIDR3STR.Bits.RTR
    #define CANTIDR3_ID0                _CANTIDR.Overlap_STR.CANTIDR3STR.Bits.ID0
    #define CANTIDR3_ID1                _CANTIDR.Overlap_STR.CANTIDR3STR.Bits.ID1
    #define CANTIDR3_ID2                _CANTIDR.Overlap_STR.CANTIDR3STR.Bits.ID2
    #define CANTIDR3_ID3                _CANTIDR.Overlap_STR.CANTIDR3STR.Bits.ID3
    #define CANTIDR3_ID4                _CANTIDR.Overlap_STR.CANTIDR3STR.Bits.ID4
    #define CANTIDR3_ID5                _CANTIDR.Overlap_STR.CANTIDR3STR.Bits.ID5
    #define CANTIDR3_ID6                _CANTIDR.Overlap_STR.CANTIDR3STR.Bits.ID6
    #define CANTIDR3_ID                 _CANTIDR.Overlap_STR.CANTIDR3STR.MergedBits.grpID
    
    #define CANTIDR3_RTR_MASK           1U
    #define CANTIDR3_ID0_MASK           2U
    #define CANTIDR3_ID1_MASK           4U
    #define CANTIDR3_ID2_MASK           8U
    #define CANTIDR3_ID3_MASK           16U
    #define CANTIDR3_ID4_MASK           32U
    #define CANTIDR3_ID5_MASK           64U
    #define CANTIDR3_ID6_MASK           128U
    #define CANTIDR3_ID_MASK            254U
    #define CANTIDR3_ID_BITNUM          1U
    
  } Overlap_STR;

  struct {
    dword RTR        :1;                                       /* Remote Transmission Request */
    dword ID0        :1;                                       /* Extended format identifier Bit 0 */
    dword ID1        :1;                                       /* Extended format identifier Bit 1 */
    dword ID2        :1;                                       /* Extended format identifier Bit 2 */
    dword ID3        :1;                                       /* Extended format identifier Bit 3 */
    dword ID4        :1;                                       /* Extended format identifier Bit 4 */
    dword ID5        :1;                                       /* Extended format identifier Bit 5 */
    dword ID6        :1;                                       /* Extended format identifier Bit 6 */
    dword ID7        :1;                                       /* Extended format identifier Bit 7 */
    dword ID8        :1;                                       /* Extended format identifier Bit 8 */
    dword ID9        :1;                                       /* Extended format identifier Bit 9 */
    dword ID10       :1;                                       /* Extended format identifier Bit 10 */
    dword ID11       :1;                                       /* Extended format identifier Bit 11 */
    dword ID12       :1;                                       /* Extended format identifier Bit 12 */
    dword ID13       :1;                                       /* Extended format identifier Bit 13 */
    dword ID14       :1;                                       /* Extended format identifier Bit 14 */
    dword ID15       :1;                                       /* Extended format identifier Bit 15 */
    dword ID16       :1;                                       /* Extended format identifier Bit 16 */
    dword ID17       :1;                                       /* Extended format identifier Bit 17 */
    dword IDE        :1;                                       /* ID Extended */
    dword SRR        :1;                                       /* Substitute Remote Request */
    dword ID18       :1;                                       /* Extended format identifier Bit 18 */
    dword ID19       :1;                                       /* Extended format identifier Bit 19 */
    dword ID20       :1;                                       /* Extended format identifier Bit 20 */
    dword ID21       :1;                                       /* Extended format identifier Bit 21 */
    dword ID22       :1;                                       /* Extended format identifier Bit 22 */
    dword ID23       :1;                                       /* Extended format identifier Bit 23 */
    dword ID24       :1;                                       /* Extended format identifier Bit 24 */
    dword ID25       :1;                                       /* Extended format identifier Bit 25 */
    dword ID26       :1;                                       /* Extended format identifier Bit 26 */
    dword ID27       :1;                                       /* Extended format identifier Bit 27 */
    dword ID28       :1;                                       /* Extended format identifier Bit 28 */
  } Bits;
  struct {
    dword        :1;
    dword grpID  :18;
    dword        :1;
    dword        :1;
    dword grpID_18 :11;
  } MergedBits;
} CANTIDRSTR;
#define _CANTIDR (*(volatile CANTIDRSTR *)0xFFFF98B0)
#define CANTIDR                         _CANTIDR.Dword
#define CANTIDR_RTR                     _CANTIDR.Bits.RTR
#define CANTIDR_ID0                     _CANTIDR.Bits.ID0
#define CANTIDR_ID1                     _CANTIDR.Bits.ID1
#define CANTIDR_ID2                     _CANTIDR.Bits.ID2
#define CANTIDR_ID3                     _CANTIDR.Bits.ID3
#define CANTIDR_ID4                     _CANTIDR.Bits.ID4
#define CANTIDR_ID5                     _CANTIDR.Bits.ID5
#define CANTIDR_ID6                     _CANTIDR.Bits.ID6
#define CANTIDR_ID7                     _CANTIDR.Bits.ID7
#define CANTIDR_ID8                     _CANTIDR.Bits.ID8
#define CANTIDR_ID9                     _CANTIDR.Bits.ID9
#define CANTIDR_ID10                    _CANTIDR.Bits.ID10
#define CANTIDR_ID11                    _CANTIDR.Bits.ID11
#define CANTIDR_ID12                    _CANTIDR.Bits.ID12
#define CANTIDR_ID13                    _CANTIDR.Bits.ID13
#define CANTIDR_ID14                    _CANTIDR.Bits.ID14
#define CANTIDR_ID15                    _CANTIDR.Bits.ID15
#define CANTIDR_ID16                    _CANTIDR.Bits.ID16
#define CANTIDR_ID17                    _CANTIDR.Bits.ID17
#define CANTIDR_IDE                     _CANTIDR.Bits.IDE
#define CANTIDR_SRR                     _CANTIDR.Bits.SRR
#define CANTIDR_ID18                    _CANTIDR.Bits.ID18
#define CANTIDR_ID19                    _CANTIDR.Bits.ID19
#define CANTIDR_ID20                    _CANTIDR.Bits.ID20
#define CANTIDR_ID21                    _CANTIDR.Bits.ID21
#define CANTIDR_ID22                    _CANTIDR.Bits.ID22
#define CANTIDR_ID23                    _CANTIDR.Bits.ID23
#define CANTIDR_ID24                    _CANTIDR.Bits.ID24
#define CANTIDR_ID25                    _CANTIDR.Bits.ID25
#define CANTIDR_ID26                    _CANTIDR.Bits.ID26
#define CANTIDR_ID27                    _CANTIDR.Bits.ID27
#define CANTIDR_ID28                    _CANTIDR.Bits.ID28
#define CANTIDR_ID                      _CANTIDR.MergedBits.grpID
#define CANTIDR_ID_18                   _CANTIDR.MergedBits.grpID_18

#define CANTIDR_RTR_MASK                1UL
#define CANTIDR_ID0_MASK                2UL
#define CANTIDR_ID1_MASK                4UL
#define CANTIDR_ID2_MASK                8UL
#define CANTIDR_ID3_MASK                16UL
#define CANTIDR_ID4_MASK                32UL
#define CANTIDR_ID5_MASK                64UL
#define CANTIDR_ID6_MASK                128UL
#define CANTIDR_ID7_MASK                256UL
#define CANTIDR_ID8_MASK                512UL
#define CANTIDR_ID9_MASK                1024UL
#define CANTIDR_ID10_MASK               2048UL
#define CANTIDR_ID11_MASK               4096UL
#define CANTIDR_ID12_MASK               8192UL
#define CANTIDR_ID13_MASK               16384UL
#define CANTIDR_ID14_MASK               32768UL
#define CANTIDR_ID15_MASK               65536UL
#define CANTIDR_ID16_MASK               131072UL
#define CANTIDR_ID17_MASK               262144UL
#define CANTIDR_IDE_MASK                524288UL
#define CANTIDR_SRR_MASK                1048576UL
#define CANTIDR_ID18_MASK               2097152UL
#define CANTIDR_ID19_MASK               4194304UL
#define CANTIDR_ID20_MASK               8388608UL
#define CANTIDR_ID21_MASK               16777216UL
#define CANTIDR_ID22_MASK               33554432UL
#define CANTIDR_ID23_MASK               67108864UL
#define CANTIDR_ID24_MASK               134217728UL
#define CANTIDR_ID25_MASK               268435456UL
#define CANTIDR_ID26_MASK               536870912UL
#define CANTIDR_ID27_MASK               1073741824UL
#define CANTIDR_ID28_MASK               2147483648UL
#define CANTIDR_ID_MASK                 524286U
#define CANTIDR_ID_BITNUM               1U
#define CANTIDR_ID_18_MASK              4292870144U
#define CANTIDR_ID_18_BITNUM            21U


/*** CANTDSR0 - MSCAN Transmit Data Segment Register 0; 0xFFFF98B4 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTDSR0STR;
#define _CANTDSR0 (*(volatile CANTDSR0STR *)0xFFFF98B4)
#define CANTDSR0                        _CANTDSR0.Byte
#define CANTDSR0_DB0                    _CANTDSR0.Bits.DB0
#define CANTDSR0_DB1                    _CANTDSR0.Bits.DB1
#define CANTDSR0_DB2                    _CANTDSR0.Bits.DB2
#define CANTDSR0_DB3                    _CANTDSR0.Bits.DB3
#define CANTDSR0_DB4                    _CANTDSR0.Bits.DB4
#define CANTDSR0_DB5                    _CANTDSR0.Bits.DB5
#define CANTDSR0_DB6                    _CANTDSR0.Bits.DB6
#define CANTDSR0_DB7                    _CANTDSR0.Bits.DB7
/* CANTDSR_ARR: Access 8 CANTDSRx registers in an array */
#define CANTDSR_ARR                     ((volatile byte *) &CANTDSR0)

#define CANTDSR0_DB0_MASK               1U
#define CANTDSR0_DB1_MASK               2U
#define CANTDSR0_DB2_MASK               4U
#define CANTDSR0_DB3_MASK               8U
#define CANTDSR0_DB4_MASK               16U
#define CANTDSR0_DB5_MASK               32U
#define CANTDSR0_DB6_MASK               64U
#define CANTDSR0_DB7_MASK               128U


/*** CANTDSR1 - MSCAN Transmit Data Segment Register 1; 0xFFFF98B5 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTDSR1STR;
#define _CANTDSR1 (*(volatile CANTDSR1STR *)0xFFFF98B5)
#define CANTDSR1                        _CANTDSR1.Byte
#define CANTDSR1_DB0                    _CANTDSR1.Bits.DB0
#define CANTDSR1_DB1                    _CANTDSR1.Bits.DB1
#define CANTDSR1_DB2                    _CANTDSR1.Bits.DB2
#define CANTDSR1_DB3                    _CANTDSR1.Bits.DB3
#define CANTDSR1_DB4                    _CANTDSR1.Bits.DB4
#define CANTDSR1_DB5                    _CANTDSR1.Bits.DB5
#define CANTDSR1_DB6                    _CANTDSR1.Bits.DB6
#define CANTDSR1_DB7                    _CANTDSR1.Bits.DB7

#define CANTDSR1_DB0_MASK               1U
#define CANTDSR1_DB1_MASK               2U
#define CANTDSR1_DB2_MASK               4U
#define CANTDSR1_DB3_MASK               8U
#define CANTDSR1_DB4_MASK               16U
#define CANTDSR1_DB5_MASK               32U
#define CANTDSR1_DB6_MASK               64U
#define CANTDSR1_DB7_MASK               128U


/*** CANTDSR2 - MSCAN Transmit Data Segment Register 2; 0xFFFF98B6 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTDSR2STR;
#define _CANTDSR2 (*(volatile CANTDSR2STR *)0xFFFF98B6)
#define CANTDSR2                        _CANTDSR2.Byte
#define CANTDSR2_DB0                    _CANTDSR2.Bits.DB0
#define CANTDSR2_DB1                    _CANTDSR2.Bits.DB1
#define CANTDSR2_DB2                    _CANTDSR2.Bits.DB2
#define CANTDSR2_DB3                    _CANTDSR2.Bits.DB3
#define CANTDSR2_DB4                    _CANTDSR2.Bits.DB4
#define CANTDSR2_DB5                    _CANTDSR2.Bits.DB5
#define CANTDSR2_DB6                    _CANTDSR2.Bits.DB6
#define CANTDSR2_DB7                    _CANTDSR2.Bits.DB7

#define CANTDSR2_DB0_MASK               1U
#define CANTDSR2_DB1_MASK               2U
#define CANTDSR2_DB2_MASK               4U
#define CANTDSR2_DB3_MASK               8U
#define CANTDSR2_DB4_MASK               16U
#define CANTDSR2_DB5_MASK               32U
#define CANTDSR2_DB6_MASK               64U
#define CANTDSR2_DB7_MASK               128U


/*** CANTDSR3 - MSCAN Transmit Data Segment Register 3; 0xFFFF98B7 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTDSR3STR;
#define _CANTDSR3 (*(volatile CANTDSR3STR *)0xFFFF98B7)
#define CANTDSR3                        _CANTDSR3.Byte
#define CANTDSR3_DB0                    _CANTDSR3.Bits.DB0
#define CANTDSR3_DB1                    _CANTDSR3.Bits.DB1
#define CANTDSR3_DB2                    _CANTDSR3.Bits.DB2
#define CANTDSR3_DB3                    _CANTDSR3.Bits.DB3
#define CANTDSR3_DB4                    _CANTDSR3.Bits.DB4
#define CANTDSR3_DB5                    _CANTDSR3.Bits.DB5
#define CANTDSR3_DB6                    _CANTDSR3.Bits.DB6
#define CANTDSR3_DB7                    _CANTDSR3.Bits.DB7

#define CANTDSR3_DB0_MASK               1U
#define CANTDSR3_DB1_MASK               2U
#define CANTDSR3_DB2_MASK               4U
#define CANTDSR3_DB3_MASK               8U
#define CANTDSR3_DB4_MASK               16U
#define CANTDSR3_DB5_MASK               32U
#define CANTDSR3_DB6_MASK               64U
#define CANTDSR3_DB7_MASK               128U


/*** CANTDSR4 - MSCAN Transmit Data Segment Register 4; 0xFFFF98B8 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTDSR4STR;
#define _CANTDSR4 (*(volatile CANTDSR4STR *)0xFFFF98B8)
#define CANTDSR4                        _CANTDSR4.Byte
#define CANTDSR4_DB0                    _CANTDSR4.Bits.DB0
#define CANTDSR4_DB1                    _CANTDSR4.Bits.DB1
#define CANTDSR4_DB2                    _CANTDSR4.Bits.DB2
#define CANTDSR4_DB3                    _CANTDSR4.Bits.DB3
#define CANTDSR4_DB4                    _CANTDSR4.Bits.DB4
#define CANTDSR4_DB5                    _CANTDSR4.Bits.DB5
#define CANTDSR4_DB6                    _CANTDSR4.Bits.DB6
#define CANTDSR4_DB7                    _CANTDSR4.Bits.DB7

#define CANTDSR4_DB0_MASK               1U
#define CANTDSR4_DB1_MASK               2U
#define CANTDSR4_DB2_MASK               4U
#define CANTDSR4_DB3_MASK               8U
#define CANTDSR4_DB4_MASK               16U
#define CANTDSR4_DB5_MASK               32U
#define CANTDSR4_DB6_MASK               64U
#define CANTDSR4_DB7_MASK               128U


/*** CANTDSR5 - MSCAN Transmit Data Segment Register 5; 0xFFFF98B9 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTDSR5STR;
#define _CANTDSR5 (*(volatile CANTDSR5STR *)0xFFFF98B9)
#define CANTDSR5                        _CANTDSR5.Byte
#define CANTDSR5_DB0                    _CANTDSR5.Bits.DB0
#define CANTDSR5_DB1                    _CANTDSR5.Bits.DB1
#define CANTDSR5_DB2                    _CANTDSR5.Bits.DB2
#define CANTDSR5_DB3                    _CANTDSR5.Bits.DB3
#define CANTDSR5_DB4                    _CANTDSR5.Bits.DB4
#define CANTDSR5_DB5                    _CANTDSR5.Bits.DB5
#define CANTDSR5_DB6                    _CANTDSR5.Bits.DB6
#define CANTDSR5_DB7                    _CANTDSR5.Bits.DB7

#define CANTDSR5_DB0_MASK               1U
#define CANTDSR5_DB1_MASK               2U
#define CANTDSR5_DB2_MASK               4U
#define CANTDSR5_DB3_MASK               8U
#define CANTDSR5_DB4_MASK               16U
#define CANTDSR5_DB5_MASK               32U
#define CANTDSR5_DB6_MASK               64U
#define CANTDSR5_DB7_MASK               128U


/*** CANTDSR6 - MSCAN Transmit Data Segment Register 6; 0xFFFF98BA ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTDSR6STR;
#define _CANTDSR6 (*(volatile CANTDSR6STR *)0xFFFF98BA)
#define CANTDSR6                        _CANTDSR6.Byte
#define CANTDSR6_DB0                    _CANTDSR6.Bits.DB0
#define CANTDSR6_DB1                    _CANTDSR6.Bits.DB1
#define CANTDSR6_DB2                    _CANTDSR6.Bits.DB2
#define CANTDSR6_DB3                    _CANTDSR6.Bits.DB3
#define CANTDSR6_DB4                    _CANTDSR6.Bits.DB4
#define CANTDSR6_DB5                    _CANTDSR6.Bits.DB5
#define CANTDSR6_DB6                    _CANTDSR6.Bits.DB6
#define CANTDSR6_DB7                    _CANTDSR6.Bits.DB7

#define CANTDSR6_DB0_MASK               1U
#define CANTDSR6_DB1_MASK               2U
#define CANTDSR6_DB2_MASK               4U
#define CANTDSR6_DB3_MASK               8U
#define CANTDSR6_DB4_MASK               16U
#define CANTDSR6_DB5_MASK               32U
#define CANTDSR6_DB6_MASK               64U
#define CANTDSR6_DB7_MASK               128U


/*** CANTDSR7 - MSCAN Transmit Data Segment Register 7; 0xFFFF98BB ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTDSR7STR;
#define _CANTDSR7 (*(volatile CANTDSR7STR *)0xFFFF98BB)
#define CANTDSR7                        _CANTDSR7.Byte
#define CANTDSR7_DB0                    _CANTDSR7.Bits.DB0
#define CANTDSR7_DB1                    _CANTDSR7.Bits.DB1
#define CANTDSR7_DB2                    _CANTDSR7.Bits.DB2
#define CANTDSR7_DB3                    _CANTDSR7.Bits.DB3
#define CANTDSR7_DB4                    _CANTDSR7.Bits.DB4
#define CANTDSR7_DB5                    _CANTDSR7.Bits.DB5
#define CANTDSR7_DB6                    _CANTDSR7.Bits.DB6
#define CANTDSR7_DB7                    _CANTDSR7.Bits.DB7

#define CANTDSR7_DB0_MASK               1U
#define CANTDSR7_DB1_MASK               2U
#define CANTDSR7_DB2_MASK               4U
#define CANTDSR7_DB3_MASK               8U
#define CANTDSR7_DB4_MASK               16U
#define CANTDSR7_DB5_MASK               32U
#define CANTDSR7_DB6_MASK               64U
#define CANTDSR7_DB7_MASK               128U


/*** CANTDLR - MSCAN Transmit Data Length Register; 0xFFFF98BC ***/
typedef union {
  byte Byte;
  struct {
    byte DLC0        :1;                                       /* Data Length Code Bit 0 */
    byte DLC1        :1;                                       /* Data Length Code Bit 1 */
    byte DLC2        :1;                                       /* Data Length Code Bit 2 */
    byte DLC3        :1;                                       /* Data Length Code Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDLC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTDLRSTR;
#define _CANTDLR (*(volatile CANTDLRSTR *)0xFFFF98BC)
#define CANTDLR                         _CANTDLR.Byte
#define CANTDLR_DLC0                    _CANTDLR.Bits.DLC0
#define CANTDLR_DLC1                    _CANTDLR.Bits.DLC1
#define CANTDLR_DLC2                    _CANTDLR.Bits.DLC2
#define CANTDLR_DLC3                    _CANTDLR.Bits.DLC3
#define CANTDLR_DLC                     _CANTDLR.MergedBits.grpDLC

#define CANTDLR_DLC0_MASK               1U
#define CANTDLR_DLC1_MASK               2U
#define CANTDLR_DLC2_MASK               4U
#define CANTDLR_DLC3_MASK               8U
#define CANTDLR_DLC_MASK                15U
#define CANTDLR_DLC_BITNUM              0U


/*** CANTTBPR - MSCAN Transmit Buffer Priority; 0xFFFF98BD ***/
typedef union {
  byte Byte;
  struct {
    byte PRIO0       :1;                                       /* Transmit Buffer Priority Bit 0 */
    byte PRIO1       :1;                                       /* Transmit Buffer Priority Bit 1 */
    byte PRIO2       :1;                                       /* Transmit Buffer Priority Bit 2 */
    byte PRIO3       :1;                                       /* Transmit Buffer Priority Bit 3 */
    byte PRIO4       :1;                                       /* Transmit Buffer Priority Bit 4 */
    byte PRIO5       :1;                                       /* Transmit Buffer Priority Bit 5 */
    byte PRIO6       :1;                                       /* Transmit Buffer Priority Bit 6 */
    byte PRIO7       :1;                                       /* Transmit Buffer Priority Bit 7 */
  } Bits;
} CANTTBPRSTR;
#define _CANTTBPR (*(volatile CANTTBPRSTR *)0xFFFF98BD)
#define CANTTBPR                        _CANTTBPR.Byte
#define CANTTBPR_PRIO0                  _CANTTBPR.Bits.PRIO0
#define CANTTBPR_PRIO1                  _CANTTBPR.Bits.PRIO1
#define CANTTBPR_PRIO2                  _CANTTBPR.Bits.PRIO2
#define CANTTBPR_PRIO3                  _CANTTBPR.Bits.PRIO3
#define CANTTBPR_PRIO4                  _CANTTBPR.Bits.PRIO4
#define CANTTBPR_PRIO5                  _CANTTBPR.Bits.PRIO5
#define CANTTBPR_PRIO6                  _CANTTBPR.Bits.PRIO6
#define CANTTBPR_PRIO7                  _CANTTBPR.Bits.PRIO7

#define CANTTBPR_PRIO0_MASK             1U
#define CANTTBPR_PRIO1_MASK             2U
#define CANTTBPR_PRIO2_MASK             4U
#define CANTTBPR_PRIO3_MASK             8U
#define CANTTBPR_PRIO4_MASK             16U
#define CANTTBPR_PRIO5_MASK             32U
#define CANTTBPR_PRIO6_MASK             64U
#define CANTTBPR_PRIO7_MASK             128U


/*** CANTTSR - MSCAN Transmit Time Stamp Register; 0xFFFF98BE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CANTTSRH - MSCAN Transmit Time Stamp Register High; 0xFFFF98BE ***/
    union {
      byte Byte;
      struct {
        byte TSR8        :1;                                       /* Time Stamp Bit 8 */
        byte TSR9        :1;                                       /* Time Stamp Bit 9 */
        byte TSR10       :1;                                       /* Time Stamp Bit 10 */
        byte TSR11       :1;                                       /* Time Stamp Bit 11 */
        byte TSR12       :1;                                       /* Time Stamp Bit 12 */
        byte TSR13       :1;                                       /* Time Stamp Bit 13 */
        byte TSR14       :1;                                       /* Time Stamp Bit 14 */
        byte TSR15       :1;                                       /* Time Stamp Bit 15 */
      } Bits;
    } CANTTSRHSTR;
    #define CANTTSRH                    _CANTTSR.Overlap_STR.CANTTSRHSTR.Byte
    #define CANTTSRH_TSR8               _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR8
    #define CANTTSRH_TSR9               _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR9
    #define CANTTSRH_TSR10              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR10
    #define CANTTSRH_TSR11              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR11
    #define CANTTSRH_TSR12              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR12
    #define CANTTSRH_TSR13              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR13
    #define CANTTSRH_TSR14              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR14
    #define CANTTSRH_TSR15              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR15
    
    #define CANTTSRH_TSR8_MASK          1U
    #define CANTTSRH_TSR9_MASK          2U
    #define CANTTSRH_TSR10_MASK         4U
    #define CANTTSRH_TSR11_MASK         8U
    #define CANTTSRH_TSR12_MASK         16U
    #define CANTTSRH_TSR13_MASK         32U
    #define CANTTSRH_TSR14_MASK         64U
    #define CANTTSRH_TSR15_MASK         128U
    

    /*** CANTTSRL - MSCAN Transmit Time Stamp Register Low; 0xFFFF98BF ***/
    union {
      byte Byte;
      struct {
        byte TSR0        :1;                                       /* Time Stamp Bit 0 */
        byte TSR1        :1;                                       /* Time Stamp Bit 1 */
        byte TSR2        :1;                                       /* Time Stamp Bit 2 */
        byte TSR3        :1;                                       /* Time Stamp Bit 3 */
        byte TSR4        :1;                                       /* Time Stamp Bit 4 */
        byte TSR5        :1;                                       /* Time Stamp Bit 5 */
        byte TSR6        :1;                                       /* Time Stamp Bit 6 */
        byte TSR7        :1;                                       /* Time Stamp Bit 7 */
      } Bits;
    } CANTTSRLSTR;
    #define CANTTSRL                    _CANTTSR.Overlap_STR.CANTTSRLSTR.Byte
    #define CANTTSRL_TSR0               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR0
    #define CANTTSRL_TSR1               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR1
    #define CANTTSRL_TSR2               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR2
    #define CANTTSRL_TSR3               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR3
    #define CANTTSRL_TSR4               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR4
    #define CANTTSRL_TSR5               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR5
    #define CANTTSRL_TSR6               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR6
    #define CANTTSRL_TSR7               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR7
    
    #define CANTTSRL_TSR0_MASK          1U
    #define CANTTSRL_TSR1_MASK          2U
    #define CANTTSRL_TSR2_MASK          4U
    #define CANTTSRL_TSR3_MASK          8U
    #define CANTTSRL_TSR4_MASK          16U
    #define CANTTSRL_TSR5_MASK          32U
    #define CANTTSRL_TSR6_MASK          64U
    #define CANTTSRL_TSR7_MASK          128U
    
  } Overlap_STR;

  struct {
    word TSR0        :1;                                       /* Time Stamp Bit 0 */
    word TSR1        :1;                                       /* Time Stamp Bit 1 */
    word TSR2        :1;                                       /* Time Stamp Bit 2 */
    word TSR3        :1;                                       /* Time Stamp Bit 3 */
    word TSR4        :1;                                       /* Time Stamp Bit 4 */
    word TSR5        :1;                                       /* Time Stamp Bit 5 */
    word TSR6        :1;                                       /* Time Stamp Bit 6 */
    word TSR7        :1;                                       /* Time Stamp Bit 7 */
    word TSR8        :1;                                       /* Time Stamp Bit 8 */
    word TSR9        :1;                                       /* Time Stamp Bit 9 */
    word TSR10       :1;                                       /* Time Stamp Bit 10 */
    word TSR11       :1;                                       /* Time Stamp Bit 11 */
    word TSR12       :1;                                       /* Time Stamp Bit 12 */
    word TSR13       :1;                                       /* Time Stamp Bit 13 */
    word TSR14       :1;                                       /* Time Stamp Bit 14 */
    word TSR15       :1;                                       /* Time Stamp Bit 15 */
  } Bits;
} CANTTSRSTR;
#define _CANTTSR (*(volatile CANTTSRSTR *)0xFFFF98BE)
#define CANTTSR                         _CANTTSR.Word
#define CANTTSR_TSR0                    _CANTTSR.Bits.TSR0
#define CANTTSR_TSR1                    _CANTTSR.Bits.TSR1
#define CANTTSR_TSR2                    _CANTTSR.Bits.TSR2
#define CANTTSR_TSR3                    _CANTTSR.Bits.TSR3
#define CANTTSR_TSR4                    _CANTTSR.Bits.TSR4
#define CANTTSR_TSR5                    _CANTTSR.Bits.TSR5
#define CANTTSR_TSR6                    _CANTTSR.Bits.TSR6
#define CANTTSR_TSR7                    _CANTTSR.Bits.TSR7
#define CANTTSR_TSR8                    _CANTTSR.Bits.TSR8
#define CANTTSR_TSR9                    _CANTTSR.Bits.TSR9
#define CANTTSR_TSR10                   _CANTTSR.Bits.TSR10
#define CANTTSR_TSR11                   _CANTTSR.Bits.TSR11
#define CANTTSR_TSR12                   _CANTTSR.Bits.TSR12
#define CANTTSR_TSR13                   _CANTTSR.Bits.TSR13
#define CANTTSR_TSR14                   _CANTTSR.Bits.TSR14
#define CANTTSR_TSR15                   _CANTTSR.Bits.TSR15

#define CANTTSR_TSR0_MASK               1U
#define CANTTSR_TSR1_MASK               2U
#define CANTTSR_TSR2_MASK               4U
#define CANTTSR_TSR3_MASK               8U
#define CANTTSR_TSR4_MASK               16U
#define CANTTSR_TSR5_MASK               32U
#define CANTTSR_TSR6_MASK               64U
#define CANTTSR_TSR7_MASK               128U
#define CANTTSR_TSR8_MASK               256U
#define CANTTSR_TSR9_MASK               512U
#define CANTTSR_TSR10_MASK              1024U
#define CANTTSR_TSR11_MASK              2048U
#define CANTTSR_TSR12_MASK              4096U
#define CANTTSR_TSR13_MASK              8192U
#define CANTTSR_TSR14_MASK              16384U
#define CANTTSR_TSR15_MASK              32768U


/*** RNGCR - Control Register; 0xFFFF98C0 ***/
typedef union {
  dword Dword;
  struct {
    dword GO         :1;                                       /* Output register random data loading control */
    dword HA         :1;                                       /* High Assurance */
    dword IM         :1;                                       /* Interrupt Mask */
    dword CI         :1;                                       /* Clear interrupt */
    dword SLM        :1;                                       /* Sleep mode control bit */
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
  } Bits;
} RNGCRSTR;
#define _RNGCR (*(volatile RNGCRSTR *)0xFFFF98C0)
#define RNGCR                           _RNGCR.Dword
#define RNGCR_GO                        _RNGCR.Bits.GO
#define RNGCR_HA                        _RNGCR.Bits.HA
#define RNGCR_IM                        _RNGCR.Bits.IM
#define RNGCR_CI                        _RNGCR.Bits.CI
#define RNGCR_SLM                       _RNGCR.Bits.SLM

#define RNGCR_GO_MASK                   1UL
#define RNGCR_HA_MASK                   2UL
#define RNGCR_IM_MASK                   4UL
#define RNGCR_CI_MASK                   8UL
#define RNGCR_SLM_MASK                  16UL


/*** RNGSR - Status Register; 0xFFFF98C4 ***/
typedef union {
  dword Dword;
  struct {
    dword SV         :1;                                       /* Security Violation */
    dword LRS        :1;                                       /* Last Read Status */
    dword OUF        :1;                                       /* Output Register Underflow */
    dword EI         :1;                                       /* Error Interrupt */
    dword SLP        :1;                                       /* Sleep */
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword ORL0       :1;                                       /* Output Register Level, bit 0 */
    dword ORL1       :1;                                       /* Output Register Level, bit 1 */
    dword ORL2       :1;                                       /* Output Register Level, bit 2 */
    dword ORL3       :1;                                       /* Output Register Level, bit 3 */
    dword ORL4       :1;                                       /* Output Register Level, bit 4 */
    dword ORL5       :1;                                       /* Output Register Level, bit 5 */
    dword ORL6       :1;                                       /* Output Register Level, bit 6 */
    dword ORL7       :1;                                       /* Output Register Level, bit 7 */
    dword ORS0       :1;                                       /* Output Register Size, bit 0 */
    dword ORS1       :1;                                       /* Output Register Size, bit 1 */
    dword ORS2       :1;                                       /* Output Register Size, bit 2 */
    dword ORS3       :1;                                       /* Output Register Size, bit 3 */
    dword ORS4       :1;                                       /* Output Register Size, bit 4 */
    dword ORS5       :1;                                       /* Output Register Size, bit 5 */
    dword ORS6       :1;                                       /* Output Register Size, bit 6 */
    dword ORS7       :1;                                       /* Output Register Size, bit 7 */
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword OD         :1;                                       /* Oscillator clocks verification */
  } Bits;
  struct {
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword grpORL :8;
    dword grpORS :8;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
  } MergedBits;
} RNGSRSTR;
#define _RNGSR (*(volatile RNGSRSTR *)0xFFFF98C4)
#define RNGSR                           _RNGSR.Dword
#define RNGSR_SV                        _RNGSR.Bits.SV
#define RNGSR_LRS                       _RNGSR.Bits.LRS
#define RNGSR_OUF                       _RNGSR.Bits.OUF
#define RNGSR_EI                        _RNGSR.Bits.EI
#define RNGSR_SLP                       _RNGSR.Bits.SLP
#define RNGSR_ORL0                      _RNGSR.Bits.ORL0
#define RNGSR_ORL1                      _RNGSR.Bits.ORL1
#define RNGSR_ORL2                      _RNGSR.Bits.ORL2
#define RNGSR_ORL3                      _RNGSR.Bits.ORL3
#define RNGSR_ORL4                      _RNGSR.Bits.ORL4
#define RNGSR_ORL5                      _RNGSR.Bits.ORL5
#define RNGSR_ORL6                      _RNGSR.Bits.ORL6
#define RNGSR_ORL7                      _RNGSR.Bits.ORL7
#define RNGSR_ORS0                      _RNGSR.Bits.ORS0
#define RNGSR_ORS1                      _RNGSR.Bits.ORS1
#define RNGSR_ORS2                      _RNGSR.Bits.ORS2
#define RNGSR_ORS3                      _RNGSR.Bits.ORS3
#define RNGSR_ORS4                      _RNGSR.Bits.ORS4
#define RNGSR_ORS5                      _RNGSR.Bits.ORS5
#define RNGSR_ORS6                      _RNGSR.Bits.ORS6
#define RNGSR_ORS7                      _RNGSR.Bits.ORS7
#define RNGSR_OD                        _RNGSR.Bits.OD
#define RNGSR_ORL                       _RNGSR.MergedBits.grpORL
#define RNGSR_ORS                       _RNGSR.MergedBits.grpORS

#define RNGSR_SV_MASK                   1UL
#define RNGSR_LRS_MASK                  2UL
#define RNGSR_OUF_MASK                  4UL
#define RNGSR_EI_MASK                   8UL
#define RNGSR_SLP_MASK                  16UL
#define RNGSR_ORL0_MASK                 256UL
#define RNGSR_ORL1_MASK                 512UL
#define RNGSR_ORL2_MASK                 1024UL
#define RNGSR_ORL3_MASK                 2048UL
#define RNGSR_ORL4_MASK                 4096UL
#define RNGSR_ORL5_MASK                 8192UL
#define RNGSR_ORL6_MASK                 16384UL
#define RNGSR_ORL7_MASK                 32768UL
#define RNGSR_ORS0_MASK                 65536UL
#define RNGSR_ORS1_MASK                 131072UL
#define RNGSR_ORS2_MASK                 262144UL
#define RNGSR_ORS3_MASK                 524288UL
#define RNGSR_ORS4_MASK                 1048576UL
#define RNGSR_ORS5_MASK                 2097152UL
#define RNGSR_ORS6_MASK                 4194304UL
#define RNGSR_ORS7_MASK                 8388608UL
#define RNGSR_OD_MASK                   2147483648UL
#define RNGSR_ORL_MASK                  65280U
#define RNGSR_ORL_BITNUM                8U
#define RNGSR_ORS_MASK                  16711680U
#define RNGSR_ORS_BITNUM                16U


/*** RNGER - Entropy Register; 0xFFFF98C8 ***/
typedef union {
  dword Dword;
  struct {
    dword ENT0       :1;                                       /* External Entropy, bit 0 */
    dword ENT1       :1;                                       /* External Entropy, bit 1 */
    dword ENT2       :1;                                       /* External Entropy, bit 2 */
    dword ENT3       :1;                                       /* External Entropy, bit 3 */
    dword ENT4       :1;                                       /* External Entropy, bit 4 */
    dword ENT5       :1;                                       /* External Entropy, bit 5 */
    dword ENT6       :1;                                       /* External Entropy, bit 6 */
    dword ENT7       :1;                                       /* External Entropy, bit 7 */
    dword ENT8       :1;                                       /* External Entropy, bit 8 */
    dword ENT9       :1;                                       /* External Entropy, bit 9 */
    dword ENT10      :1;                                       /* External Entropy, bit 10 */
    dword ENT11      :1;                                       /* External Entropy, bit 11 */
    dword ENT12      :1;                                       /* External Entropy, bit 12 */
    dword ENT13      :1;                                       /* External Entropy, bit 13 */
    dword ENT14      :1;                                       /* External Entropy, bit 14 */
    dword ENT15      :1;                                       /* External Entropy, bit 15 */
    dword ENT16      :1;                                       /* External Entropy, bit 16 */
    dword ENT17      :1;                                       /* External Entropy, bit 17 */
    dword ENT18      :1;                                       /* External Entropy, bit 18 */
    dword ENT19      :1;                                       /* External Entropy, bit 19 */
    dword ENT20      :1;                                       /* External Entropy, bit 20 */
    dword ENT21      :1;                                       /* External Entropy, bit 21 */
    dword ENT22      :1;                                       /* External Entropy, bit 22 */
    dword ENT23      :1;                                       /* External Entropy, bit 23 */
    dword ENT24      :1;                                       /* External Entropy, bit 24 */
    dword ENT25      :1;                                       /* External Entropy, bit 25 */
    dword ENT26      :1;                                       /* External Entropy, bit 26 */
    dword ENT27      :1;                                       /* External Entropy, bit 27 */
    dword ENT28      :1;                                       /* External Entropy, bit 28 */
    dword ENT29      :1;                                       /* External Entropy, bit 29 */
    dword ENT30      :1;                                       /* External Entropy, bit 30 */
    dword ENT31      :1;                                       /* External Entropy, bit 31 */
  } Bits;
} RNGERSTR;
#define _RNGER (*(volatile RNGERSTR *)0xFFFF98C8)
#define RNGER                           _RNGER.Dword
#define RNGER_ENT0                      _RNGER.Bits.ENT0
#define RNGER_ENT1                      _RNGER.Bits.ENT1
#define RNGER_ENT2                      _RNGER.Bits.ENT2
#define RNGER_ENT3                      _RNGER.Bits.ENT3
#define RNGER_ENT4                      _RNGER.Bits.ENT4
#define RNGER_ENT5                      _RNGER.Bits.ENT5
#define RNGER_ENT6                      _RNGER.Bits.ENT6
#define RNGER_ENT7                      _RNGER.Bits.ENT7
#define RNGER_ENT8                      _RNGER.Bits.ENT8
#define RNGER_ENT9                      _RNGER.Bits.ENT9
#define RNGER_ENT10                     _RNGER.Bits.ENT10
#define RNGER_ENT11                     _RNGER.Bits.ENT11
#define RNGER_ENT12                     _RNGER.Bits.ENT12
#define RNGER_ENT13                     _RNGER.Bits.ENT13
#define RNGER_ENT14                     _RNGER.Bits.ENT14
#define RNGER_ENT15                     _RNGER.Bits.ENT15
#define RNGER_ENT16                     _RNGER.Bits.ENT16
#define RNGER_ENT17                     _RNGER.Bits.ENT17
#define RNGER_ENT18                     _RNGER.Bits.ENT18
#define RNGER_ENT19                     _RNGER.Bits.ENT19
#define RNGER_ENT20                     _RNGER.Bits.ENT20
#define RNGER_ENT21                     _RNGER.Bits.ENT21
#define RNGER_ENT22                     _RNGER.Bits.ENT22
#define RNGER_ENT23                     _RNGER.Bits.ENT23
#define RNGER_ENT24                     _RNGER.Bits.ENT24
#define RNGER_ENT25                     _RNGER.Bits.ENT25
#define RNGER_ENT26                     _RNGER.Bits.ENT26
#define RNGER_ENT27                     _RNGER.Bits.ENT27
#define RNGER_ENT28                     _RNGER.Bits.ENT28
#define RNGER_ENT29                     _RNGER.Bits.ENT29
#define RNGER_ENT30                     _RNGER.Bits.ENT30
#define RNGER_ENT31                     _RNGER.Bits.ENT31

#define RNGER_ENT0_MASK                 1UL
#define RNGER_ENT1_MASK                 2UL
#define RNGER_ENT2_MASK                 4UL
#define RNGER_ENT3_MASK                 8UL
#define RNGER_ENT4_MASK                 16UL
#define RNGER_ENT5_MASK                 32UL
#define RNGER_ENT6_MASK                 64UL
#define RNGER_ENT7_MASK                 128UL
#define RNGER_ENT8_MASK                 256UL
#define RNGER_ENT9_MASK                 512UL
#define RNGER_ENT10_MASK                1024UL
#define RNGER_ENT11_MASK                2048UL
#define RNGER_ENT12_MASK                4096UL
#define RNGER_ENT13_MASK                8192UL
#define RNGER_ENT14_MASK                16384UL
#define RNGER_ENT15_MASK                32768UL
#define RNGER_ENT16_MASK                65536UL
#define RNGER_ENT17_MASK                131072UL
#define RNGER_ENT18_MASK                262144UL
#define RNGER_ENT19_MASK                524288UL
#define RNGER_ENT20_MASK                1048576UL
#define RNGER_ENT21_MASK                2097152UL
#define RNGER_ENT22_MASK                4194304UL
#define RNGER_ENT23_MASK                8388608UL
#define RNGER_ENT24_MASK                16777216UL
#define RNGER_ENT25_MASK                33554432UL
#define RNGER_ENT26_MASK                67108864UL
#define RNGER_ENT27_MASK                134217728UL
#define RNGER_ENT28_MASK                268435456UL
#define RNGER_ENT29_MASK                536870912UL
#define RNGER_ENT30_MASK                1073741824UL
#define RNGER_ENT31_MASK                2147483648UL


/*** RNGOUT - Output Register; 0xFFFF98CC ***/
typedef union {
  dword Dword;
  struct {
    dword RANDOM_OUTPUT0 :1;                                   /* Random Output, bit 0 */
    dword RANDOM_OUTPUT1 :1;                                   /* Random Output, bit 1 */
    dword RANDOM_OUTPUT2 :1;                                   /* Random Output, bit 2 */
    dword RANDOM_OUTPUT3 :1;                                   /* Random Output, bit 3 */
    dword RANDOM_OUTPUT4 :1;                                   /* Random Output, bit 4 */
    dword RANDOM_OUTPUT5 :1;                                   /* Random Output, bit 5 */
    dword RANDOM_OUTPUT6 :1;                                   /* Random Output, bit 6 */
    dword RANDOM_OUTPUT7 :1;                                   /* Random Output, bit 7 */
    dword RANDOM_OUTPUT8 :1;                                   /* Random Output, bit 8 */
    dword RANDOM_OUTPUT9 :1;                                   /* Random Output, bit 9 */
    dword RANDOM_OUTPUT10 :1;                                  /* Random Output, bit 10 */
    dword RANDOM_OUTPUT11 :1;                                  /* Random Output, bit 11 */
    dword RANDOM_OUTPUT12 :1;                                  /* Random Output, bit 12 */
    dword RANDOM_OUTPUT13 :1;                                  /* Random Output, bit 13 */
    dword RANDOM_OUTPUT14 :1;                                  /* Random Output, bit 14 */
    dword RANDOM_OUTPUT15 :1;                                  /* Random Output, bit 15 */
    dword RANDOM_OUTPUT16 :1;                                  /* Random Output, bit 16 */
    dword RANDOM_OUTPUT17 :1;                                  /* Random Output, bit 17 */
    dword RANDOM_OUTPUT18 :1;                                  /* Random Output, bit 18 */
    dword RANDOM_OUTPUT19 :1;                                  /* Random Output, bit 19 */
    dword RANDOM_OUTPUT20 :1;                                  /* Random Output, bit 20 */
    dword RANDOM_OUTPUT21 :1;                                  /* Random Output, bit 21 */
    dword RANDOM_OUTPUT22 :1;                                  /* Random Output, bit 22 */
    dword RANDOM_OUTPUT23 :1;                                  /* Random Output, bit 23 */
    dword RANDOM_OUTPUT24 :1;                                  /* Random Output, bit 24 */
    dword RANDOM_OUTPUT25 :1;                                  /* Random Output, bit 25 */
    dword RANDOM_OUTPUT26 :1;                                  /* Random Output, bit 26 */
    dword RANDOM_OUTPUT27 :1;                                  /* Random Output, bit 27 */
    dword RANDOM_OUTPUT28 :1;                                  /* Random Output, bit 28 */
    dword RANDOM_OUTPUT29 :1;                                  /* Random Output, bit 29 */
    dword RANDOM_OUTPUT30 :1;                                  /* Random Output, bit 30 */
    dword RANDOM_OUTPUT31 :1;                                  /* Random Output, bit 31 */
  } Bits;
} RNGOUTSTR;
#define _RNGOUT (*(volatile RNGOUTSTR *)0xFFFF98CC)
#define RNGOUT                          _RNGOUT.Dword
#define RNGOUT_RANDOM_OUTPUT0           _RNGOUT.Bits.RANDOM_OUTPUT0
#define RNGOUT_RANDOM_OUTPUT1           _RNGOUT.Bits.RANDOM_OUTPUT1
#define RNGOUT_RANDOM_OUTPUT2           _RNGOUT.Bits.RANDOM_OUTPUT2
#define RNGOUT_RANDOM_OUTPUT3           _RNGOUT.Bits.RANDOM_OUTPUT3
#define RNGOUT_RANDOM_OUTPUT4           _RNGOUT.Bits.RANDOM_OUTPUT4
#define RNGOUT_RANDOM_OUTPUT5           _RNGOUT.Bits.RANDOM_OUTPUT5
#define RNGOUT_RANDOM_OUTPUT6           _RNGOUT.Bits.RANDOM_OUTPUT6
#define RNGOUT_RANDOM_OUTPUT7           _RNGOUT.Bits.RANDOM_OUTPUT7
#define RNGOUT_RANDOM_OUTPUT8           _RNGOUT.Bits.RANDOM_OUTPUT8
#define RNGOUT_RANDOM_OUTPUT9           _RNGOUT.Bits.RANDOM_OUTPUT9
#define RNGOUT_RANDOM_OUTPUT10          _RNGOUT.Bits.RANDOM_OUTPUT10
#define RNGOUT_RANDOM_OUTPUT11          _RNGOUT.Bits.RANDOM_OUTPUT11
#define RNGOUT_RANDOM_OUTPUT12          _RNGOUT.Bits.RANDOM_OUTPUT12
#define RNGOUT_RANDOM_OUTPUT13          _RNGOUT.Bits.RANDOM_OUTPUT13
#define RNGOUT_RANDOM_OUTPUT14          _RNGOUT.Bits.RANDOM_OUTPUT14
#define RNGOUT_RANDOM_OUTPUT15          _RNGOUT.Bits.RANDOM_OUTPUT15
#define RNGOUT_RANDOM_OUTPUT16          _RNGOUT.Bits.RANDOM_OUTPUT16
#define RNGOUT_RANDOM_OUTPUT17          _RNGOUT.Bits.RANDOM_OUTPUT17
#define RNGOUT_RANDOM_OUTPUT18          _RNGOUT.Bits.RANDOM_OUTPUT18
#define RNGOUT_RANDOM_OUTPUT19          _RNGOUT.Bits.RANDOM_OUTPUT19
#define RNGOUT_RANDOM_OUTPUT20          _RNGOUT.Bits.RANDOM_OUTPUT20
#define RNGOUT_RANDOM_OUTPUT21          _RNGOUT.Bits.RANDOM_OUTPUT21
#define RNGOUT_RANDOM_OUTPUT22          _RNGOUT.Bits.RANDOM_OUTPUT22
#define RNGOUT_RANDOM_OUTPUT23          _RNGOUT.Bits.RANDOM_OUTPUT23
#define RNGOUT_RANDOM_OUTPUT24          _RNGOUT.Bits.RANDOM_OUTPUT24
#define RNGOUT_RANDOM_OUTPUT25          _RNGOUT.Bits.RANDOM_OUTPUT25
#define RNGOUT_RANDOM_OUTPUT26          _RNGOUT.Bits.RANDOM_OUTPUT26
#define RNGOUT_RANDOM_OUTPUT27          _RNGOUT.Bits.RANDOM_OUTPUT27
#define RNGOUT_RANDOM_OUTPUT28          _RNGOUT.Bits.RANDOM_OUTPUT28
#define RNGOUT_RANDOM_OUTPUT29          _RNGOUT.Bits.RANDOM_OUTPUT29
#define RNGOUT_RANDOM_OUTPUT30          _RNGOUT.Bits.RANDOM_OUTPUT30
#define RNGOUT_RANDOM_OUTPUT31          _RNGOUT.Bits.RANDOM_OUTPUT31

#define RNGOUT_RANDOM_OUTPUT0_MASK      1UL
#define RNGOUT_RANDOM_OUTPUT1_MASK      2UL
#define RNGOUT_RANDOM_OUTPUT2_MASK      4UL
#define RNGOUT_RANDOM_OUTPUT3_MASK      8UL
#define RNGOUT_RANDOM_OUTPUT4_MASK      16UL
#define RNGOUT_RANDOM_OUTPUT5_MASK      32UL
#define RNGOUT_RANDOM_OUTPUT6_MASK      64UL
#define RNGOUT_RANDOM_OUTPUT7_MASK      128UL
#define RNGOUT_RANDOM_OUTPUT8_MASK      256UL
#define RNGOUT_RANDOM_OUTPUT9_MASK      512UL
#define RNGOUT_RANDOM_OUTPUT10_MASK     1024UL
#define RNGOUT_RANDOM_OUTPUT11_MASK     2048UL
#define RNGOUT_RANDOM_OUTPUT12_MASK     4096UL
#define RNGOUT_RANDOM_OUTPUT13_MASK     8192UL
#define RNGOUT_RANDOM_OUTPUT14_MASK     16384UL
#define RNGOUT_RANDOM_OUTPUT15_MASK     32768UL
#define RNGOUT_RANDOM_OUTPUT16_MASK     65536UL
#define RNGOUT_RANDOM_OUTPUT17_MASK     131072UL
#define RNGOUT_RANDOM_OUTPUT18_MASK     262144UL
#define RNGOUT_RANDOM_OUTPUT19_MASK     524288UL
#define RNGOUT_RANDOM_OUTPUT20_MASK     1048576UL
#define RNGOUT_RANDOM_OUTPUT21_MASK     2097152UL
#define RNGOUT_RANDOM_OUTPUT22_MASK     4194304UL
#define RNGOUT_RANDOM_OUTPUT23_MASK     8388608UL
#define RNGOUT_RANDOM_OUTPUT24_MASK     16777216UL
#define RNGOUT_RANDOM_OUTPUT25_MASK     33554432UL
#define RNGOUT_RANDOM_OUTPUT26_MASK     67108864UL
#define RNGOUT_RANDOM_OUTPUT27_MASK     134217728UL
#define RNGOUT_RANDOM_OUTPUT28_MASK     268435456UL
#define RNGOUT_RANDOM_OUTPUT29_MASK     536870912UL
#define RNGOUT_RANDOM_OUTPUT30_MASK     1073741824UL
#define RNGOUT_RANDOM_OUTPUT31_MASK     2147483648UL


/*** PER_ID - Peripherial ID Register; 0xFFFF9A00 ***/
typedef union {
  byte Byte;
  struct {
    byte ID0         :1;                                       /* Peripheral identification bits. These bits will always read 0x04 (00_0100), bit 0 */
    byte ID1         :1;                                       /* Peripheral identification bits. These bits will always read 0x04 (00_0100), bit 1 */
    byte ID2         :1;                                       /* Peripheral identification bits. These bits will always read 0x04 (00_0100), bit 2 */
    byte ID3         :1;                                       /* Peripheral identification bits. These bits will always read 0x04 (00_0100), bit 3 */
    byte ID4         :1;                                       /* Peripheral identification bits. These bits will always read 0x04 (00_0100), bit 4 */
    byte ID5         :1;                                       /* Peripheral identification bits. These bits will always read 0x04 (00_0100), bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpID   :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PER_IDSTR;
#define _PER_ID (*(volatile PER_IDSTR *)0xFFFF9A00)
#define PER_ID                          _PER_ID.Byte
#define PER_ID_ID0                      _PER_ID.Bits.ID0
#define PER_ID_ID1                      _PER_ID.Bits.ID1
#define PER_ID_ID2                      _PER_ID.Bits.ID2
#define PER_ID_ID3                      _PER_ID.Bits.ID3
#define PER_ID_ID4                      _PER_ID.Bits.ID4
#define PER_ID_ID5                      _PER_ID.Bits.ID5
#define PER_ID_ID                       _PER_ID.MergedBits.grpID

#define PER_ID_ID0_MASK                 1U
#define PER_ID_ID1_MASK                 2U
#define PER_ID_ID2_MASK                 4U
#define PER_ID_ID3_MASK                 8U
#define PER_ID_ID4_MASK                 16U
#define PER_ID_ID5_MASK                 32U
#define PER_ID_ID_MASK                  63U
#define PER_ID_ID_BITNUM                0U


/*** ID_COMP - Peripheral ID Complement Register; 0xFFFF9A04 ***/
typedef union {
  byte Byte;
  struct {
    byte NID0        :1;                                       /* Ones complement of peripheral identification bits, bit 0 */
    byte NID1        :1;                                       /* Ones complement of peripheral identification bits, bit 1 */
    byte NID2        :1;                                       /* Ones complement of peripheral identification bits, bit 2 */
    byte NID3        :1;                                       /* Ones complement of peripheral identification bits, bit 3 */
    byte NID4        :1;                                       /* Ones complement of peripheral identification bits, bit 4 */
    byte NID5        :1;                                       /* Ones complement of peripheral identification bits, bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpNID  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} ID_COMPSTR;
#define _ID_COMP (*(volatile ID_COMPSTR *)0xFFFF9A04)
#define ID_COMP                         _ID_COMP.Byte
#define ID_COMP_NID0                    _ID_COMP.Bits.NID0
#define ID_COMP_NID1                    _ID_COMP.Bits.NID1
#define ID_COMP_NID2                    _ID_COMP.Bits.NID2
#define ID_COMP_NID3                    _ID_COMP.Bits.NID3
#define ID_COMP_NID4                    _ID_COMP.Bits.NID4
#define ID_COMP_NID5                    _ID_COMP.Bits.NID5
#define ID_COMP_NID                     _ID_COMP.MergedBits.grpNID

#define ID_COMP_NID0_MASK               1U
#define ID_COMP_NID1_MASK               2U
#define ID_COMP_NID2_MASK               4U
#define ID_COMP_NID3_MASK               8U
#define ID_COMP_NID4_MASK               16U
#define ID_COMP_NID5_MASK               32U
#define ID_COMP_NID_MASK                63U
#define ID_COMP_NID_BITNUM              0U


/*** REV - Peripheral Revision Register; 0xFFFF9A08 ***/
typedef union {
  byte Byte;
} REVSTR;
#define _REV (*(volatile REVSTR *)0xFFFF9A08)
#define REV                             _REV.Byte


/*** ADD_INFO - Peripheral Additional Info Register; 0xFFFF9A0C ***/
typedef union {
  byte Byte;
  struct {
    byte IEHOST      :1;                                       /* This bit will be set if host mode is enabled */
    byte             :1; 
    byte             :1; 
    byte IRQ_NUM0    :1;                                       /* Assigned Interrupt Request Number, bit 0 */
    byte IRQ_NUM1    :1;                                       /* Assigned Interrupt Request Number, bit 1 */
    byte IRQ_NUM2    :1;                                       /* Assigned Interrupt Request Number, bit 2 */
    byte IRQ_NUM3    :1;                                       /* Assigned Interrupt Request Number, bit 3 */
    byte IRQ_NUM4    :1;                                       /* Assigned Interrupt Request Number, bit 4 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpIRQ_NUM :5;
  } MergedBits;
} ADD_INFOSTR;
#define _ADD_INFO (*(volatile ADD_INFOSTR *)0xFFFF9A0C)
#define ADD_INFO                        _ADD_INFO.Byte
#define ADD_INFO_IEHOST                 _ADD_INFO.Bits.IEHOST
#define ADD_INFO_IRQ_NUM0               _ADD_INFO.Bits.IRQ_NUM0
#define ADD_INFO_IRQ_NUM1               _ADD_INFO.Bits.IRQ_NUM1
#define ADD_INFO_IRQ_NUM2               _ADD_INFO.Bits.IRQ_NUM2
#define ADD_INFO_IRQ_NUM3               _ADD_INFO.Bits.IRQ_NUM3
#define ADD_INFO_IRQ_NUM4               _ADD_INFO.Bits.IRQ_NUM4
#define ADD_INFO_IRQ_NUM                _ADD_INFO.MergedBits.grpIRQ_NUM

#define ADD_INFO_IEHOST_MASK            1U
#define ADD_INFO_IRQ_NUM0_MASK          8U
#define ADD_INFO_IRQ_NUM1_MASK          16U
#define ADD_INFO_IRQ_NUM2_MASK          32U
#define ADD_INFO_IRQ_NUM3_MASK          64U
#define ADD_INFO_IRQ_NUM4_MASK          128U
#define ADD_INFO_IRQ_NUM_MASK           248U
#define ADD_INFO_IRQ_NUM_BITNUM         3U


/*** OTG_INT_STAT - OTG Interrupt Status Register; 0xFFFF9A10 ***/
typedef union {
  byte Byte;
  struct {
    byte A_VBUS_CHG  :1;                                       /* This bit is set when a change in VBUS is detected on an &quot;A&quot; device */
    byte             :1; 
    byte B_SESS_CHG  :1;                                       /* This bit is set when a change in VBUS is detected on a &quot;B&quot; device */
    byte SESS_VLD_CHG :1;                                      /* This bit is set when a change in VBUS is detected indicating a session valid or a session no longer valid */
    byte             :1; 
    byte LINE_STATE_CHG :1;                                    /* This bit is set when the USB line state changes. The interrupt associated with this bit can be used to detect Reset, Resume, Connect, and Data Line Pulse signals */
    byte ONE_MSEC    :1;                                       /* This bit is set when the 1 millisecond timer expires. This bit stays asserted until clered by software. The interrupt must be serviced every millisecond to avoid losing 1msec counts */
    byte ID_CHG      :1;                                       /* This bit is set when a change in the ID Signal from the USB connector is sensed */
  } Bits;
} OTG_INT_STATSTR;
#define _OTG_INT_STAT (*(volatile OTG_INT_STATSTR *)0xFFFF9A10)
#define OTG_INT_STAT                    _OTG_INT_STAT.Byte
#define OTG_INT_STAT_A_VBUS_CHG         _OTG_INT_STAT.Bits.A_VBUS_CHG
#define OTG_INT_STAT_B_SESS_CHG         _OTG_INT_STAT.Bits.B_SESS_CHG
#define OTG_INT_STAT_SESS_VLD_CHG       _OTG_INT_STAT.Bits.SESS_VLD_CHG
#define OTG_INT_STAT_LINE_STATE_CHG     _OTG_INT_STAT.Bits.LINE_STATE_CHG
#define OTG_INT_STAT_ONE_MSEC           _OTG_INT_STAT.Bits.ONE_MSEC
#define OTG_INT_STAT_ID_CHG             _OTG_INT_STAT.Bits.ID_CHG

#define OTG_INT_STAT_A_VBUS_CHG_MASK    1U
#define OTG_INT_STAT_B_SESS_CHG_MASK    4U
#define OTG_INT_STAT_SESS_VLD_CHG_MASK  8U
#define OTG_INT_STAT_LINE_STATE_CHG_MASK 32U
#define OTG_INT_STAT_ONE_MSEC_MASK      64U
#define OTG_INT_STAT_ID_CHG_MASK        128U


/*** OTG_INT_EN - OTG Interrupt Control Register; 0xFFFF9A14 ***/
typedef union {
  byte Byte;
  struct {
    byte A_VBUS_EN   :1;                                       /* &quot;A&quot; VBUS Valid interrupt enable */
    byte             :1; 
    byte B_SESS_EN   :1;                                       /* &quot;B&quot; Session END interrupt enable */
    byte SESS_VLD_EN :1;                                       /* Session valid interrupt enable */
    byte             :1; 
    byte LINE_STATE_EN :1;                                     /* Line State change interrupt enable */
    byte ONE_MSEC_EN :1;                                       /* 1 millisecond interrupt enable */
    byte ID_EN       :1;                                       /* ID interrupt enable */
  } Bits;
} OTG_INT_ENSTR;
#define _OTG_INT_EN (*(volatile OTG_INT_ENSTR *)0xFFFF9A14)
#define OTG_INT_EN                      _OTG_INT_EN.Byte
#define OTG_INT_EN_A_VBUS_EN            _OTG_INT_EN.Bits.A_VBUS_EN
#define OTG_INT_EN_B_SESS_EN            _OTG_INT_EN.Bits.B_SESS_EN
#define OTG_INT_EN_SESS_VLD_EN          _OTG_INT_EN.Bits.SESS_VLD_EN
#define OTG_INT_EN_LINE_STATE_EN        _OTG_INT_EN.Bits.LINE_STATE_EN
#define OTG_INT_EN_ONE_MSEC_EN          _OTG_INT_EN.Bits.ONE_MSEC_EN
#define OTG_INT_EN_ID_EN                _OTG_INT_EN.Bits.ID_EN

#define OTG_INT_EN_A_VBUS_EN_MASK       1U
#define OTG_INT_EN_B_SESS_EN_MASK       4U
#define OTG_INT_EN_SESS_VLD_EN_MASK     8U
#define OTG_INT_EN_LINE_STATE_EN_MASK   32U
#define OTG_INT_EN_ONE_MSEC_EN_MASK     64U
#define OTG_INT_EN_ID_EN_MASK           128U


/*** OTG_STAT - Interrupt Status Register; 0xFFFF9A18 ***/
typedef union {
  byte Byte;
  struct {
    byte A_VBUS_VLD  :1;                                       /* &quot;A&quot; VBUS Valid */
    byte             :1; 
    byte B_SESS_END  :1;                                       /* &quot;B&quot; Session END */
    byte SESS_VLD    :1;                                       /* Session Valid */
    byte             :1; 
    byte LINE_STATE_STABLE :1;                                 /* This bit indicates that the internal signals which control the LINE_STATE_CHG bit (bit 5) of the OTG_INT_STAT register have been stable for at least 1 millisecond */
    byte ONE_MSEC_EN :1;                                       /* This bit is reserved for the 1msec count, but it is not useful to software */
    byte ID          :1;                                       /* Indicates the current state of the ID pin on the USB connector */
  } Bits;
} OTG_STATSTR;
#define _OTG_STAT (*(volatile OTG_STATSTR *)0xFFFF9A18)
#define OTG_STAT                        _OTG_STAT.Byte
#define OTG_STAT_A_VBUS_VLD             _OTG_STAT.Bits.A_VBUS_VLD
#define OTG_STAT_B_SESS_END             _OTG_STAT.Bits.B_SESS_END
#define OTG_STAT_SESS_VLD               _OTG_STAT.Bits.SESS_VLD
#define OTG_STAT_LINE_STATE_STABLE      _OTG_STAT.Bits.LINE_STATE_STABLE
#define OTG_STAT_ONE_MSEC_EN            _OTG_STAT.Bits.ONE_MSEC_EN
#define OTG_STAT_ID                     _OTG_STAT.Bits.ID

#define OTG_STAT_A_VBUS_VLD_MASK        1U
#define OTG_STAT_B_SESS_END_MASK        4U
#define OTG_STAT_SESS_VLD_MASK          8U
#define OTG_STAT_LINE_STATE_STABLE_MASK 32U
#define OTG_STAT_ONE_MSEC_EN_MASK       64U
#define OTG_STAT_ID_MASK                128U


/*** OTG_CTRL - OTG Control Register; 0xFFFF9A1C ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte OTG_EN      :1;                                       /* On-The-Go pull-up/pull-down resistor enable */
    byte             :1; 
    byte DM_LOW      :1;                                       /* D- Data Line pull-down resistor enable. This bit should always be enabled together with bit 5 (DP_LOW) */
    byte DP_LOW      :1;                                       /* D+ Data Line pull-down resistor enable. This bit should always be enabled together with bit 4 (DM_LOW) */
    byte             :1; 
    byte DP_HIGH     :1;                                       /* D+ Data Line pull-up resistor enable */
  } Bits;
} OTG_CTRLSTR;
#define _OTG_CTRL (*(volatile OTG_CTRLSTR *)0xFFFF9A1C)
#define OTG_CTRL                        _OTG_CTRL.Byte
#define OTG_CTRL_OTG_EN                 _OTG_CTRL.Bits.OTG_EN
#define OTG_CTRL_DM_LOW                 _OTG_CTRL.Bits.DM_LOW
#define OTG_CTRL_DP_LOW                 _OTG_CTRL.Bits.DP_LOW
#define OTG_CTRL_DP_HIGH                _OTG_CTRL.Bits.DP_HIGH

#define OTG_CTRL_OTG_EN_MASK            4U
#define OTG_CTRL_DM_LOW_MASK            16U
#define OTG_CTRL_DP_LOW_MASK            32U
#define OTG_CTRL_DP_HIGH_MASK           128U


/*** INT_STAT - Interrupt Status Register; 0xFFFF9A80 ***/
typedef union {
  byte Byte;
  struct {
    byte USB_RST     :1;                                       /* This bit is set when the USB Module has decoded a valid USB reset */
    byte ERROR       :1;                                       /* This bit is set when any of the error conditions within the ERR_STAT register occur. The ColdFire core must then read the ERR_STAT register to determine the source of the error */
    byte SOF_TOK     :1;                                       /* This bit is set when the USB Module receives a Start Of Frame (SOF) token. In Host mode this bit is set when the SOF threshold is reached, so that software can prepare for the next SOF */
    byte TOK_DNE     :1;                                       /* This bit is set when the current token being processed has completed */
    byte SLEEP       :1;                                       /* This bit is set when the USB Module detects a constant idle on the USB bus for 3 milliseconds. The sleep timer is reset by activity on the USB bus */
    byte RESUME      :1;                                       /* This bit is set depending upon the DP/DM signals, and can be used to signal remote wake-up signaling on the USB bus. When not in suspend mode this interrupt should be disabled */
    byte ATTACH      :1;                                       /* Attach Interrupt. This bit is set when the USB Module detects an attach of a USB device. This signal is only valid if HOST_MODE_EN is true. This interrupt signifies that a peripheral is now present and must be configured */
    byte STALL       :1;                                       /* Stall Interrupt. In Target mode this bit is asserted when a STALL handshake is sent by the SIE. In Host mode this bit is set when the USB Module detects a STALL acknowledge during the handshake phase of a USB transaction */
  } Bits;
} INT_STATSTR;
#define _INT_STAT (*(volatile INT_STATSTR *)0xFFFF9A80)
#define INT_STAT                        _INT_STAT.Byte
#define INT_STAT_USB_RST                _INT_STAT.Bits.USB_RST
#define INT_STAT_ERROR                  _INT_STAT.Bits.ERROR
#define INT_STAT_SOF_TOK                _INT_STAT.Bits.SOF_TOK
#define INT_STAT_TOK_DNE                _INT_STAT.Bits.TOK_DNE
#define INT_STAT_SLEEP                  _INT_STAT.Bits.SLEEP
#define INT_STAT_RESUME                 _INT_STAT.Bits.RESUME
#define INT_STAT_ATTACH                 _INT_STAT.Bits.ATTACH
#define INT_STAT_STALL                  _INT_STAT.Bits.STALL

#define INT_STAT_USB_RST_MASK           1U
#define INT_STAT_ERROR_MASK             2U
#define INT_STAT_SOF_TOK_MASK           4U
#define INT_STAT_TOK_DNE_MASK           8U
#define INT_STAT_SLEEP_MASK             16U
#define INT_STAT_RESUME_MASK            32U
#define INT_STAT_ATTACH_MASK            64U
#define INT_STAT_STALL_MASK             128U


/*** INT_ENB - Interrupt Enable Register; 0xFFFF9A84 ***/
typedef union {
  byte Byte;
  struct {
    byte USB_RST_EN  :1;                                       /* USB_RST Interrupt Enable */
    byte ERROR_EN    :1;                                       /* ERROR Interrupt Enable */
    byte SOF_TOK_EN  :1;                                       /* SOF_TOK Interrupt Enable */
    byte TOK_DNE_EN  :1;                                       /* TOK_DNE Interrupt Enable */
    byte SLEEP_EN    :1;                                       /* SLEEP Interrupt Enable */
    byte RESUME_EN   :1;                                       /* RESUME Interrupt Enable */
    byte ATTACH_EN   :1;                                       /* ATTACH Interrupt Enable */
    byte STALL_EN    :1;                                       /* STALL Interrupt Enable */
  } Bits;
} INT_ENBSTR;
#define _INT_ENB (*(volatile INT_ENBSTR *)0xFFFF9A84)
#define INT_ENB                         _INT_ENB.Byte
#define INT_ENB_USB_RST_EN              _INT_ENB.Bits.USB_RST_EN
#define INT_ENB_ERROR_EN                _INT_ENB.Bits.ERROR_EN
#define INT_ENB_SOF_TOK_EN              _INT_ENB.Bits.SOF_TOK_EN
#define INT_ENB_TOK_DNE_EN              _INT_ENB.Bits.TOK_DNE_EN
#define INT_ENB_SLEEP_EN                _INT_ENB.Bits.SLEEP_EN
#define INT_ENB_RESUME_EN               _INT_ENB.Bits.RESUME_EN
#define INT_ENB_ATTACH_EN               _INT_ENB.Bits.ATTACH_EN
#define INT_ENB_STALL_EN                _INT_ENB.Bits.STALL_EN

#define INT_ENB_USB_RST_EN_MASK         1U
#define INT_ENB_ERROR_EN_MASK           2U
#define INT_ENB_SOF_TOK_EN_MASK         4U
#define INT_ENB_TOK_DNE_EN_MASK         8U
#define INT_ENB_SLEEP_EN_MASK           16U
#define INT_ENB_RESUME_EN_MASK          32U
#define INT_ENB_ATTACH_EN_MASK          64U
#define INT_ENB_STALL_EN_MASK           128U


/*** ERR_STAT - Error Interrupt Status Register; 0xFFFF9A88 ***/
typedef union {
  byte Byte;
  struct {
    byte PID_ERR     :1;                                       /* This bit is set when the PID check field fails */
    byte CRC5_EOF    :1;                                       /* When the USB Module is operating in Peripheral mode (HOST_MODE_EN=0) this interrupt will detect CRC5 errors in the token packets generated by the host. When the USB Module is operating in Host mode (HOST_MODE_EN=1) this interupt will detect End Of Frame (EOF) error conditions */
    byte CRC16       :1;                                       /* This bit is set when a data packet is rejected due to a CRC16 error */
    byte DFN8        :1;                                       /* This bit is set if the dta field received was not 8 bits in length. USB Specification 1.0 requires that data fields be an integral number of bytes. If the data field was not an integral number of bytes this bit will be set */
    byte BTO_ERR     :1;                                       /* This bit is set when a bus turnaround timeout error occurs */
    byte DMA_ERR     :1;                                       /* This bit is set if the USB Module has requested a DMA access to read a new BDT but has not been given the bus before it needs to receive or transmit data */
    byte             :1; 
    byte BTS_ERR     :1;                                       /* This bit is set when a bit stuff error is detected. If set the corresponding packet will be rejected due to the error */
  } Bits;
} ERR_STATSTR;
#define _ERR_STAT (*(volatile ERR_STATSTR *)0xFFFF9A88)
#define ERR_STAT                        _ERR_STAT.Byte
#define ERR_STAT_PID_ERR                _ERR_STAT.Bits.PID_ERR
#define ERR_STAT_CRC5_EOF               _ERR_STAT.Bits.CRC5_EOF
#define ERR_STAT_CRC16                  _ERR_STAT.Bits.CRC16
#define ERR_STAT_DFN8                   _ERR_STAT.Bits.DFN8
#define ERR_STAT_BTO_ERR                _ERR_STAT.Bits.BTO_ERR
#define ERR_STAT_DMA_ERR                _ERR_STAT.Bits.DMA_ERR
#define ERR_STAT_BTS_ERR                _ERR_STAT.Bits.BTS_ERR

#define ERR_STAT_PID_ERR_MASK           1U
#define ERR_STAT_CRC5_EOF_MASK          2U
#define ERR_STAT_CRC16_MASK             4U
#define ERR_STAT_DFN8_MASK              8U
#define ERR_STAT_BTO_ERR_MASK           16U
#define ERR_STAT_DMA_ERR_MASK           32U
#define ERR_STAT_BTS_ERR_MASK           128U


/*** ERR_ENB - Error Interrupt Enable Register; 0xFFFF9A8C ***/
typedef union {
  byte Byte;
  struct {
    byte PID_ERR_EN  :1;                                       /* PID_ERR Interrupt Enable */
    byte CRC5_EOF_EN :1;                                       /* CRC5/EOF Interrupt Enable */
    byte CRC16_EN    :1;                                       /* CRC16 Interrupt Enable */
    byte DFN8_EN     :1;                                       /* DFN8 Interrupt Enable */
    byte BTO_ERR_EN  :1;                                       /* BTO_ERR Interrupt Enable */
    byte DMA_ERR_EN  :1;                                       /* DMA_ERR Interrupt Enable */
    byte             :1; 
    byte BTS_ERR_EN  :1;                                       /* BTS_ERR Interrupt Enable */
  } Bits;
} ERR_ENBSTR;
#define _ERR_ENB (*(volatile ERR_ENBSTR *)0xFFFF9A8C)
#define ERR_ENB                         _ERR_ENB.Byte
#define ERR_ENB_PID_ERR_EN              _ERR_ENB.Bits.PID_ERR_EN
#define ERR_ENB_CRC5_EOF_EN             _ERR_ENB.Bits.CRC5_EOF_EN
#define ERR_ENB_CRC16_EN                _ERR_ENB.Bits.CRC16_EN
#define ERR_ENB_DFN8_EN                 _ERR_ENB.Bits.DFN8_EN
#define ERR_ENB_BTO_ERR_EN              _ERR_ENB.Bits.BTO_ERR_EN
#define ERR_ENB_DMA_ERR_EN              _ERR_ENB.Bits.DMA_ERR_EN
#define ERR_ENB_BTS_ERR_EN              _ERR_ENB.Bits.BTS_ERR_EN

#define ERR_ENB_PID_ERR_EN_MASK         1U
#define ERR_ENB_CRC5_EOF_EN_MASK        2U
#define ERR_ENB_CRC16_EN_MASK           4U
#define ERR_ENB_DFN8_EN_MASK            8U
#define ERR_ENB_BTO_ERR_EN_MASK         16U
#define ERR_ENB_DMA_ERR_EN_MASK         32U
#define ERR_ENB_BTS_ERR_EN_MASK         128U


/*** STAT - Status Register; 0xFFFF9A90 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ODD         :1;                                       /* This bit is set if the last Buffer Descriptor updated was in the odd bank of the BDT */
    byte TX          :1;                                       /* Transmit Indicator */
    byte ENDP0       :1;                                       /* ENDP field, bit 0 */
    byte ENDP1       :1;                                       /* ENDP field, bit 1 */
    byte ENDP2       :1;                                       /* ENDP field, bit 2 */
    byte ENDP3       :1;                                       /* ENDP field, bit 3 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpENDP :4;
  } MergedBits;
} STATSTR;
#define _STAT (*(volatile STATSTR *)0xFFFF9A90)
#define STAT                            _STAT.Byte
#define STAT_ODD                        _STAT.Bits.ODD
#define STAT_TX                         _STAT.Bits.TX
#define STAT_ENDP0                      _STAT.Bits.ENDP0
#define STAT_ENDP1                      _STAT.Bits.ENDP1
#define STAT_ENDP2                      _STAT.Bits.ENDP2
#define STAT_ENDP3                      _STAT.Bits.ENDP3
#define STAT_ENDP                       _STAT.MergedBits.grpENDP

#define STAT_ODD_MASK                   4U
#define STAT_TX_MASK                    8U
#define STAT_ENDP0_MASK                 16U
#define STAT_ENDP1_MASK                 32U
#define STAT_ENDP2_MASK                 64U
#define STAT_ENDP3_MASK                 128U
#define STAT_ENDP_MASK                  240U
#define STAT_ENDP_BITNUM                4U


/*** CTL - Control Register; 0xFFFF9A94 ***/
typedef union {
  byte Byte;
  struct {
    byte USB_EN_SOF_EN :1;                                     /* USB Enable. Setting this bit causes the SIE to reset all of its ODD bits to the BDTs. Thus, setting this bit will reset much of the logic in the SIE. when host mode is enabled clearing this bit will cause the SIE to stop sending SOF tokens */
    byte ODD_RST     :1;                                       /* Setting this bit to 1 will reset all the BDT ODD ping/pong bits to 0, which then specifies the EVEN BDT bank */
    byte RESUME      :1;                                       /* When set to 1 this bit enables the USB Module to execute resume signaling */
    byte HOST_MODE_EN :1;                                      /* When set to 1, this bit enables the USB Module to operate in Host mode. In Host mode the USB Module will perform USB transactions under the programmed control of the host processor */
    byte RESET       :1;                                       /* Setting this bit enables the USB Module to generate USB reset signaling */
    byte TXSUSPEND_TOKENBUSY :1;                               /* When the USB Module is in Host mode TOKEN_BUSY is set when the USB Module is busy executing a USB token and no more token commands should be written to the Token Register. In Target mode TXD_SUSPEND is set when the SIE has disabled packet transmission and reception */
    byte SE0         :1;                                       /* Live USB Single Ended Zero signal */
    byte JSTATE      :1;                                       /* Live USB differential receiver JSTATE signal. The polarity of this signal is affected bythe current state of LS_EN */
  } Bits;
} CTLSTR;
#define _CTL (*(volatile CTLSTR *)0xFFFF9A94)
#define CTL                             _CTL.Byte
#define CTL_USB_EN_SOF_EN               _CTL.Bits.USB_EN_SOF_EN
#define CTL_ODD_RST                     _CTL.Bits.ODD_RST
#define CTL_RESUME                      _CTL.Bits.RESUME
#define CTL_HOST_MODE_EN                _CTL.Bits.HOST_MODE_EN
#define CTL_RESET                       _CTL.Bits.RESET
#define CTL_TXSUSPEND_TOKENBUSY         _CTL.Bits.TXSUSPEND_TOKENBUSY
#define CTL_SE0                         _CTL.Bits.SE0
#define CTL_JSTATE                      _CTL.Bits.JSTATE

#define CTL_USB_EN_SOF_EN_MASK          1U
#define CTL_ODD_RST_MASK                2U
#define CTL_RESUME_MASK                 4U
#define CTL_HOST_MODE_EN_MASK           8U
#define CTL_RESET_MASK                  16U
#define CTL_TXSUSPEND_TOKENBUSY_MASK    32U
#define CTL_SE0_MASK                    64U
#define CTL_JSTATE_MASK                 128U


/*** ADDR - Address Register; 0xFFFF9A98 ***/
typedef union {
  byte Byte;
  struct {
    byte ADDR0       :1;                                       /* USB address. This 7-bit value defines the USB address that the USB Module will decode in peripheral mode, or transmit when in host mode, bit 0 */
    byte ADDR1       :1;                                       /* USB address. This 7-bit value defines the USB address that the USB Module will decode in peripheral mode, or transmit when in host mode, bit 1 */
    byte ADDR2       :1;                                       /* USB address. This 7-bit value defines the USB address that the USB Module will decode in peripheral mode, or transmit when in host mode, bit 2 */
    byte ADDR3       :1;                                       /* USB address. This 7-bit value defines the USB address that the USB Module will decode in peripheral mode, or transmit when in host mode, bit 3 */
    byte ADDR4       :1;                                       /* USB address. This 7-bit value defines the USB address that the USB Module will decode in peripheral mode, or transmit when in host mode, bit 4 */
    byte ADDR5       :1;                                       /* USB address. This 7-bit value defines the USB address that the USB Module will decode in peripheral mode, or transmit when in host mode, bit 5 */
    byte ADDR6       :1;                                       /* USB address. This 7-bit value defines the USB address that the USB Module will decode in peripheral mode, or transmit when in host mode, bit 6 */
    byte LS_EN       :1;                                       /* Low Speed Enable bit. This bit uniforms the USB Module that the next token command written to the token register must be performed at low speed. This will enable the USB Module to perform the necessary preamble required for low-speed data transmissions */
  } Bits;
  struct {
    byte grpADDR :7;
    byte         :1;
  } MergedBits;
} ADDRSTR;
#define _ADDR (*(volatile ADDRSTR *)0xFFFF9A98)
#define ADDR                            _ADDR.Byte
#define ADDR_ADDR0                      _ADDR.Bits.ADDR0
#define ADDR_ADDR1                      _ADDR.Bits.ADDR1
#define ADDR_ADDR2                      _ADDR.Bits.ADDR2
#define ADDR_ADDR3                      _ADDR.Bits.ADDR3
#define ADDR_ADDR4                      _ADDR.Bits.ADDR4
#define ADDR_ADDR5                      _ADDR.Bits.ADDR5
#define ADDR_ADDR6                      _ADDR.Bits.ADDR6
#define ADDR_LS_EN                      _ADDR.Bits.LS_EN
#define ADDR_ADDR                       _ADDR.MergedBits.grpADDR

#define ADDR_ADDR0_MASK                 1U
#define ADDR_ADDR1_MASK                 2U
#define ADDR_ADDR2_MASK                 4U
#define ADDR_ADDR3_MASK                 8U
#define ADDR_ADDR4_MASK                 16U
#define ADDR_ADDR5_MASK                 32U
#define ADDR_ADDR6_MASK                 64U
#define ADDR_LS_EN_MASK                 128U
#define ADDR_ADDR_MASK                  127U
#define ADDR_ADDR_BITNUM                0U


/*** BDT_PAGE_01 - BDT Page Register 1; 0xFFFF9A9C ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte BDT_BA9     :1;                                       /* BDT base address bit 9 */
    byte BDT_BA10    :1;                                       /* BDT base address bit 10 */
    byte BDT_BA11    :1;                                       /* BDT base address bit 11 */
    byte BDT_BA12    :1;                                       /* BDT base address bit 12 */
    byte BDT_BA13    :1;                                       /* BDT base address bit 13 */
    byte BDT_BA14    :1;                                       /* BDT base address bit 14 */
    byte BDT_BA15    :1;                                       /* BDT base address bit 15 */
  } Bits;
  struct {
    byte         :1;
    byte grpBDT_BA_9 :7;
  } MergedBits;
} BDT_PAGE_01STR;
#define _BDT_PAGE_01 (*(volatile BDT_PAGE_01STR *)0xFFFF9A9C)
#define BDT_PAGE_01                     _BDT_PAGE_01.Byte
#define BDT_PAGE_01_BDT_BA9             _BDT_PAGE_01.Bits.BDT_BA9
#define BDT_PAGE_01_BDT_BA10            _BDT_PAGE_01.Bits.BDT_BA10
#define BDT_PAGE_01_BDT_BA11            _BDT_PAGE_01.Bits.BDT_BA11
#define BDT_PAGE_01_BDT_BA12            _BDT_PAGE_01.Bits.BDT_BA12
#define BDT_PAGE_01_BDT_BA13            _BDT_PAGE_01.Bits.BDT_BA13
#define BDT_PAGE_01_BDT_BA14            _BDT_PAGE_01.Bits.BDT_BA14
#define BDT_PAGE_01_BDT_BA15            _BDT_PAGE_01.Bits.BDT_BA15
#define BDT_PAGE_01_BDT_BA_9            _BDT_PAGE_01.MergedBits.grpBDT_BA_9
#define BDT_PAGE_01_BDT_BA              BDT_PAGE_01_BDT_BA_9

#define BDT_PAGE_01_BDT_BA9_MASK        2U
#define BDT_PAGE_01_BDT_BA10_MASK       4U
#define BDT_PAGE_01_BDT_BA11_MASK       8U
#define BDT_PAGE_01_BDT_BA12_MASK       16U
#define BDT_PAGE_01_BDT_BA13_MASK       32U
#define BDT_PAGE_01_BDT_BA14_MASK       64U
#define BDT_PAGE_01_BDT_BA15_MASK       128U
#define BDT_PAGE_01_BDT_BA_9_MASK       254U
#define BDT_PAGE_01_BDT_BA_9_BITNUM     1U


/*** FRM_NUML - Frame Number Register Low; 0xFFFF9AA0 ***/
typedef union {
  byte Byte;
  struct {
    byte FRM0        :1;                                       /* Frame number bit 0 */
    byte FRM1        :1;                                       /* Frame number bit 1 */
    byte FRM2        :1;                                       /* Frame number bit 2 */
    byte FRM3        :1;                                       /* Frame number bit 3 */
    byte FRM4        :1;                                       /* Frame number bit 4 */
    byte FRM5        :1;                                       /* Frame number bit 5 */
    byte FRM6        :1;                                       /* Frame number bit 6 */
    byte FRM7        :1;                                       /* Frame number bit 7 */
  } Bits;
} FRM_NUMLSTR;
#define _FRM_NUML (*(volatile FRM_NUMLSTR *)0xFFFF9AA0)
#define FRM_NUML                        _FRM_NUML.Byte
#define FRM_NUML_FRM0                   _FRM_NUML.Bits.FRM0
#define FRM_NUML_FRM1                   _FRM_NUML.Bits.FRM1
#define FRM_NUML_FRM2                   _FRM_NUML.Bits.FRM2
#define FRM_NUML_FRM3                   _FRM_NUML.Bits.FRM3
#define FRM_NUML_FRM4                   _FRM_NUML.Bits.FRM4
#define FRM_NUML_FRM5                   _FRM_NUML.Bits.FRM5
#define FRM_NUML_FRM6                   _FRM_NUML.Bits.FRM6
#define FRM_NUML_FRM7                   _FRM_NUML.Bits.FRM7

#define FRM_NUML_FRM0_MASK              1U
#define FRM_NUML_FRM1_MASK              2U
#define FRM_NUML_FRM2_MASK              4U
#define FRM_NUML_FRM3_MASK              8U
#define FRM_NUML_FRM4_MASK              16U
#define FRM_NUML_FRM5_MASK              32U
#define FRM_NUML_FRM6_MASK              64U
#define FRM_NUML_FRM7_MASK              128U


/*** FRM_NUMH - Frame Number Register High; 0xFFFF9AA4 ***/
typedef union {
  byte Byte;
  struct {
    byte FRM8        :1;                                       /* Frame number bit 8 */
    byte FRM9        :1;                                       /* Frame number bit 9 */
    byte FRM10       :1;                                       /* Frame number bit 10 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFRM_8 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FRM_NUMHSTR;
#define _FRM_NUMH (*(volatile FRM_NUMHSTR *)0xFFFF9AA4)
#define FRM_NUMH                        _FRM_NUMH.Byte
#define FRM_NUMH_FRM8                   _FRM_NUMH.Bits.FRM8
#define FRM_NUMH_FRM9                   _FRM_NUMH.Bits.FRM9
#define FRM_NUMH_FRM10                  _FRM_NUMH.Bits.FRM10
#define FRM_NUMH_FRM_8                  _FRM_NUMH.MergedBits.grpFRM_8
#define FRM_NUMH_FRM                    FRM_NUMH_FRM_8

#define FRM_NUMH_FRM8_MASK              1U
#define FRM_NUMH_FRM9_MASK              2U
#define FRM_NUMH_FRM10_MASK             4U
#define FRM_NUMH_FRM_8_MASK             7U
#define FRM_NUMH_FRM_8_BITNUM           0U


/*** TOKEN - Token Register; 0xFFFF9AA8 ***/
typedef union {
  byte Byte;
  struct {
    byte TOKEN_ENDPT0 :1;                                      /* Endpoint address for the token command, bit 0 */
    byte TOKEN_ENDPT1 :1;                                      /* Endpoint address for the token command, bit 1 */
    byte TOKEN_ENDPT2 :1;                                      /* Endpoint address for the token command, bit 2 */
    byte TOKEN_ENDPT3 :1;                                      /* Endpoint address for the token command, bit 3 */
    byte TOKEN_PID0  :1;                                       /* Token type, bit 0 */
    byte TOKEN_PID1  :1;                                       /* Token type, bit 1 */
    byte TOKEN_PID2  :1;                                       /* Token type, bit 2 */
    byte TOKEN_PID3  :1;                                       /* Token type, bit 3 */
  } Bits;
  struct {
    byte grpTOKEN_ENDPT :4;
    byte grpTOKEN_PID :4;
  } MergedBits;
} TOKENSTR;
#define _TOKEN (*(volatile TOKENSTR *)0xFFFF9AA8)
#define TOKEN                           _TOKEN.Byte
#define TOKEN_TOKEN_ENDPT0              _TOKEN.Bits.TOKEN_ENDPT0
#define TOKEN_TOKEN_ENDPT1              _TOKEN.Bits.TOKEN_ENDPT1
#define TOKEN_TOKEN_ENDPT2              _TOKEN.Bits.TOKEN_ENDPT2
#define TOKEN_TOKEN_ENDPT3              _TOKEN.Bits.TOKEN_ENDPT3
#define TOKEN_TOKEN_PID0                _TOKEN.Bits.TOKEN_PID0
#define TOKEN_TOKEN_PID1                _TOKEN.Bits.TOKEN_PID1
#define TOKEN_TOKEN_PID2                _TOKEN.Bits.TOKEN_PID2
#define TOKEN_TOKEN_PID3                _TOKEN.Bits.TOKEN_PID3
#define TOKEN_TOKEN_ENDPT               _TOKEN.MergedBits.grpTOKEN_ENDPT
#define TOKEN_TOKEN_PID                 _TOKEN.MergedBits.grpTOKEN_PID

#define TOKEN_TOKEN_ENDPT0_MASK         1U
#define TOKEN_TOKEN_ENDPT1_MASK         2U
#define TOKEN_TOKEN_ENDPT2_MASK         4U
#define TOKEN_TOKEN_ENDPT3_MASK         8U
#define TOKEN_TOKEN_PID0_MASK           16U
#define TOKEN_TOKEN_PID1_MASK           32U
#define TOKEN_TOKEN_PID2_MASK           64U
#define TOKEN_TOKEN_PID3_MASK           128U
#define TOKEN_TOKEN_ENDPT_MASK          15U
#define TOKEN_TOKEN_ENDPT_BITNUM        0U
#define TOKEN_TOKEN_PID_MASK            240U
#define TOKEN_TOKEN_PID_BITNUM          4U


/*** SOF_THLD - SOF Threshold Register; 0xFFFF9AAC ***/
typedef union {
  byte Byte;
  struct {
    byte CNT0        :1;                                       /* SOF count threshold, bit 0 */
    byte CNT1        :1;                                       /* SOF count threshold, bit 1 */
    byte CNT2        :1;                                       /* SOF count threshold, bit 2 */
    byte CNT3        :1;                                       /* SOF count threshold, bit 3 */
    byte CNT4        :1;                                       /* SOF count threshold, bit 4 */
    byte CNT5        :1;                                       /* SOF count threshold, bit 5 */
    byte CNT6        :1;                                       /* SOF count threshold, bit 6 */
    byte CNT7        :1;                                       /* SOF count threshold, bit 7 */
  } Bits;
} SOF_THLDSTR;
#define _SOF_THLD (*(volatile SOF_THLDSTR *)0xFFFF9AAC)
#define SOF_THLD                        _SOF_THLD.Byte
#define SOF_THLD_CNT0                   _SOF_THLD.Bits.CNT0
#define SOF_THLD_CNT1                   _SOF_THLD.Bits.CNT1
#define SOF_THLD_CNT2                   _SOF_THLD.Bits.CNT2
#define SOF_THLD_CNT3                   _SOF_THLD.Bits.CNT3
#define SOF_THLD_CNT4                   _SOF_THLD.Bits.CNT4
#define SOF_THLD_CNT5                   _SOF_THLD.Bits.CNT5
#define SOF_THLD_CNT6                   _SOF_THLD.Bits.CNT6
#define SOF_THLD_CNT7                   _SOF_THLD.Bits.CNT7

#define SOF_THLD_CNT0_MASK              1U
#define SOF_THLD_CNT1_MASK              2U
#define SOF_THLD_CNT2_MASK              4U
#define SOF_THLD_CNT3_MASK              8U
#define SOF_THLD_CNT4_MASK              16U
#define SOF_THLD_CNT5_MASK              32U
#define SOF_THLD_CNT6_MASK              64U
#define SOF_THLD_CNT7_MASK              128U


/*** BDT_PAGE_02 - BDT Page Register 2; 0xFFFF9AB0 ***/
typedef union {
  byte Byte;
  struct {
    byte BDT_BA16    :1;                                       /* BDT base address bit 16 */
    byte BDT_BA17    :1;                                       /* BDT base address bit 17 */
    byte BDT_BA18    :1;                                       /* BDT base address bit 18 */
    byte BDT_BA19    :1;                                       /* BDT base address bit 19 */
    byte BDT_BA20    :1;                                       /* BDT base address bit 20 */
    byte BDT_BA21    :1;                                       /* BDT base address bit 21 */
    byte BDT_BA22    :1;                                       /* BDT base address bit 22 */
    byte BDT_BA23    :1;                                       /* BDT base address bit 23 */
  } Bits;
} BDT_PAGE_02STR;
#define _BDT_PAGE_02 (*(volatile BDT_PAGE_02STR *)0xFFFF9AB0)
#define BDT_PAGE_02                     _BDT_PAGE_02.Byte
#define BDT_PAGE_02_BDT_BA16            _BDT_PAGE_02.Bits.BDT_BA16
#define BDT_PAGE_02_BDT_BA17            _BDT_PAGE_02.Bits.BDT_BA17
#define BDT_PAGE_02_BDT_BA18            _BDT_PAGE_02.Bits.BDT_BA18
#define BDT_PAGE_02_BDT_BA19            _BDT_PAGE_02.Bits.BDT_BA19
#define BDT_PAGE_02_BDT_BA20            _BDT_PAGE_02.Bits.BDT_BA20
#define BDT_PAGE_02_BDT_BA21            _BDT_PAGE_02.Bits.BDT_BA21
#define BDT_PAGE_02_BDT_BA22            _BDT_PAGE_02.Bits.BDT_BA22
#define BDT_PAGE_02_BDT_BA23            _BDT_PAGE_02.Bits.BDT_BA23

#define BDT_PAGE_02_BDT_BA16_MASK       1U
#define BDT_PAGE_02_BDT_BA17_MASK       2U
#define BDT_PAGE_02_BDT_BA18_MASK       4U
#define BDT_PAGE_02_BDT_BA19_MASK       8U
#define BDT_PAGE_02_BDT_BA20_MASK       16U
#define BDT_PAGE_02_BDT_BA21_MASK       32U
#define BDT_PAGE_02_BDT_BA22_MASK       64U
#define BDT_PAGE_02_BDT_BA23_MASK       128U


/*** BDT_PAGE_03 - BDT Page Register 3; 0xFFFF9AB4 ***/
typedef union {
  byte Byte;
  struct {
    byte BDT_BA24    :1;                                       /* BDT base address bit 24 */
    byte BDT_BA25    :1;                                       /* BDT base address bit 25 */
    byte BDT_BA26    :1;                                       /* BDT base address bit 26 */
    byte BDT_BA27    :1;                                       /* BDT base address bit 27 */
    byte BDT_BA28    :1;                                       /* BDT base address bit 28 */
    byte BDT_BA29    :1;                                       /* BDT base address bit 29 */
    byte BDT_BA30    :1;                                       /* BDT base address bit 30 */
    byte BDT_BA31    :1;                                       /* BDT base address bit 31 */
  } Bits;
} BDT_PAGE_03STR;
#define _BDT_PAGE_03 (*(volatile BDT_PAGE_03STR *)0xFFFF9AB4)
#define BDT_PAGE_03                     _BDT_PAGE_03.Byte
#define BDT_PAGE_03_BDT_BA24            _BDT_PAGE_03.Bits.BDT_BA24
#define BDT_PAGE_03_BDT_BA25            _BDT_PAGE_03.Bits.BDT_BA25
#define BDT_PAGE_03_BDT_BA26            _BDT_PAGE_03.Bits.BDT_BA26
#define BDT_PAGE_03_BDT_BA27            _BDT_PAGE_03.Bits.BDT_BA27
#define BDT_PAGE_03_BDT_BA28            _BDT_PAGE_03.Bits.BDT_BA28
#define BDT_PAGE_03_BDT_BA29            _BDT_PAGE_03.Bits.BDT_BA29
#define BDT_PAGE_03_BDT_BA30            _BDT_PAGE_03.Bits.BDT_BA30
#define BDT_PAGE_03_BDT_BA31            _BDT_PAGE_03.Bits.BDT_BA31

#define BDT_PAGE_03_BDT_BA24_MASK       1U
#define BDT_PAGE_03_BDT_BA25_MASK       2U
#define BDT_PAGE_03_BDT_BA26_MASK       4U
#define BDT_PAGE_03_BDT_BA27_MASK       8U
#define BDT_PAGE_03_BDT_BA28_MASK       16U
#define BDT_PAGE_03_BDT_BA29_MASK       32U
#define BDT_PAGE_03_BDT_BA30_MASK       64U
#define BDT_PAGE_03_BDT_BA31_MASK       128U


/*** ENDPT0 - Endpoint Control Register 0; 0xFFFF9AC0 ***/
typedef union {
  byte Byte;
  struct {
    byte EP_HSHK     :1;                                       /* When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous */
    byte EP_STALL    :1;                                       /* When set this bit indicates that the endpoint is stalled */
    byte EP_TX_EN    :1;                                       /* This bit, when set, enables the endpoint for TX transfers */
    byte EP_RX_EN    :1;                                       /* This bit, when set, enables the endpoint for RX transfers */
    byte EP_CTL_DIS  :1;                                       /* This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set */
    byte             :1; 
    byte RETRY_DIS   :1;                                       /* This is a Host mode only bit and is only present in the control register for endpoint 0 (ENDPT0) */
    byte HOST_WO_HUB :1;                                       /* This is a Host mode only bit and is only present in the control register for endpoint 0 (ENDPT0) */
  } Bits;
} ENDPT0STR;
#define _ENDPT0 (*(volatile ENDPT0STR *)0xFFFF9AC0)
#define ENDPT0                          _ENDPT0.Byte
#define ENDPT0_EP_HSHK                  _ENDPT0.Bits.EP_HSHK
#define ENDPT0_EP_STALL                 _ENDPT0.Bits.EP_STALL
#define ENDPT0_EP_TX_EN                 _ENDPT0.Bits.EP_TX_EN
#define ENDPT0_EP_RX_EN                 _ENDPT0.Bits.EP_RX_EN
#define ENDPT0_EP_CTL_DIS               _ENDPT0.Bits.EP_CTL_DIS
#define ENDPT0_RETRY_DIS                _ENDPT0.Bits.RETRY_DIS
#define ENDPT0_HOST_WO_HUB              _ENDPT0.Bits.HOST_WO_HUB

#define ENDPT0_EP_HSHK_MASK             1U
#define ENDPT0_EP_STALL_MASK            2U
#define ENDPT0_EP_TX_EN_MASK            4U
#define ENDPT0_EP_RX_EN_MASK            8U
#define ENDPT0_EP_CTL_DIS_MASK          16U
#define ENDPT0_RETRY_DIS_MASK           64U
#define ENDPT0_HOST_WO_HUB_MASK         128U


/*** ENDPT1 - Endpoint Control Register 1; 0xFFFF9AC4 ***/
typedef union {
  byte Byte;
  struct {
    byte EP_HSHK     :1;                                       /* When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous */
    byte EP_STALL    :1;                                       /* When set this bit indicates that the endpoint is stalled */
    byte EP_TX_EN    :1;                                       /* This bit, when set, enables the endpoint for TX transfers */
    byte EP_RX_EN    :1;                                       /* This bit, when set, enables the endpoint for RX transfers */
    byte EP_CTL_DIS  :1;                                       /* This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set */
    byte             :1; 
    byte RETRY_DIS   :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
    byte HOST_WO_HUB :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
  } Bits;
} ENDPT1STR;
#define _ENDPT1 (*(volatile ENDPT1STR *)0xFFFF9AC4)
#define ENDPT1                          _ENDPT1.Byte
#define ENDPT1_EP_HSHK                  _ENDPT1.Bits.EP_HSHK
#define ENDPT1_EP_STALL                 _ENDPT1.Bits.EP_STALL
#define ENDPT1_EP_TX_EN                 _ENDPT1.Bits.EP_TX_EN
#define ENDPT1_EP_RX_EN                 _ENDPT1.Bits.EP_RX_EN
#define ENDPT1_EP_CTL_DIS               _ENDPT1.Bits.EP_CTL_DIS
#define ENDPT1_RETRY_DIS                _ENDPT1.Bits.RETRY_DIS
#define ENDPT1_HOST_WO_HUB              _ENDPT1.Bits.HOST_WO_HUB

#define ENDPT1_EP_HSHK_MASK             1U
#define ENDPT1_EP_STALL_MASK            2U
#define ENDPT1_EP_TX_EN_MASK            4U
#define ENDPT1_EP_RX_EN_MASK            8U
#define ENDPT1_EP_CTL_DIS_MASK          16U
#define ENDPT1_RETRY_DIS_MASK           64U
#define ENDPT1_HOST_WO_HUB_MASK         128U


/*** ENDPT2 - Endpoint Control Register 2; 0xFFFF9AC8 ***/
typedef union {
  byte Byte;
  struct {
    byte EP_HSHK     :1;                                       /* When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous */
    byte EP_STALL    :1;                                       /* When set this bit indicates that the endpoint is stalled */
    byte EP_TX_EN    :1;                                       /* This bit, when set, enables the endpoint for TX transfers */
    byte EP_RX_EN    :1;                                       /* This bit, when set, enables the endpoint for RX transfers */
    byte EP_CTL_DIS  :1;                                       /* This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set */
    byte             :1; 
    byte RETRY_DIS   :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
    byte HOST_WO_HUB :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
  } Bits;
} ENDPT2STR;
#define _ENDPT2 (*(volatile ENDPT2STR *)0xFFFF9AC8)
#define ENDPT2                          _ENDPT2.Byte
#define ENDPT2_EP_HSHK                  _ENDPT2.Bits.EP_HSHK
#define ENDPT2_EP_STALL                 _ENDPT2.Bits.EP_STALL
#define ENDPT2_EP_TX_EN                 _ENDPT2.Bits.EP_TX_EN
#define ENDPT2_EP_RX_EN                 _ENDPT2.Bits.EP_RX_EN
#define ENDPT2_EP_CTL_DIS               _ENDPT2.Bits.EP_CTL_DIS
#define ENDPT2_RETRY_DIS                _ENDPT2.Bits.RETRY_DIS
#define ENDPT2_HOST_WO_HUB              _ENDPT2.Bits.HOST_WO_HUB

#define ENDPT2_EP_HSHK_MASK             1U
#define ENDPT2_EP_STALL_MASK            2U
#define ENDPT2_EP_TX_EN_MASK            4U
#define ENDPT2_EP_RX_EN_MASK            8U
#define ENDPT2_EP_CTL_DIS_MASK          16U
#define ENDPT2_RETRY_DIS_MASK           64U
#define ENDPT2_HOST_WO_HUB_MASK         128U


/*** ENDPT3 - Endpoint Control Register 3; 0xFFFF9ACC ***/
typedef union {
  byte Byte;
  struct {
    byte EP_HSHK     :1;                                       /* When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous */
    byte EP_STALL    :1;                                       /* When set this bit indicates that the endpoint is stalled */
    byte EP_TX_EN    :1;                                       /* This bit, when set, enables the endpoint for TX transfers */
    byte EP_RX_EN    :1;                                       /* This bit, when set, enables the endpoint for RX transfers */
    byte EP_CTL_DIS  :1;                                       /* This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set */
    byte             :1; 
    byte RETRY_DIS   :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
    byte HOST_WO_HUB :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
  } Bits;
} ENDPT3STR;
#define _ENDPT3 (*(volatile ENDPT3STR *)0xFFFF9ACC)
#define ENDPT3                          _ENDPT3.Byte
#define ENDPT3_EP_HSHK                  _ENDPT3.Bits.EP_HSHK
#define ENDPT3_EP_STALL                 _ENDPT3.Bits.EP_STALL
#define ENDPT3_EP_TX_EN                 _ENDPT3.Bits.EP_TX_EN
#define ENDPT3_EP_RX_EN                 _ENDPT3.Bits.EP_RX_EN
#define ENDPT3_EP_CTL_DIS               _ENDPT3.Bits.EP_CTL_DIS
#define ENDPT3_RETRY_DIS                _ENDPT3.Bits.RETRY_DIS
#define ENDPT3_HOST_WO_HUB              _ENDPT3.Bits.HOST_WO_HUB

#define ENDPT3_EP_HSHK_MASK             1U
#define ENDPT3_EP_STALL_MASK            2U
#define ENDPT3_EP_TX_EN_MASK            4U
#define ENDPT3_EP_RX_EN_MASK            8U
#define ENDPT3_EP_CTL_DIS_MASK          16U
#define ENDPT3_RETRY_DIS_MASK           64U
#define ENDPT3_HOST_WO_HUB_MASK         128U


/*** ENDPT4 - Endpoint Control Register 4; 0xFFFF9AD0 ***/
typedef union {
  byte Byte;
  struct {
    byte EP_HSHK     :1;                                       /* When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous */
    byte EP_STALL    :1;                                       /* When set this bit indicates that the endpoint is stalled */
    byte EP_TX_EN    :1;                                       /* This bit, when set, enables the endpoint for TX transfers */
    byte EP_RX_EN    :1;                                       /* This bit, when set, enables the endpoint for RX transfers */
    byte EP_CTL_DIS  :1;                                       /* This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set */
    byte             :1; 
    byte RETRY_DIS   :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
    byte HOST_WO_HUB :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
  } Bits;
} ENDPT4STR;
#define _ENDPT4 (*(volatile ENDPT4STR *)0xFFFF9AD0)
#define ENDPT4                          _ENDPT4.Byte
#define ENDPT4_EP_HSHK                  _ENDPT4.Bits.EP_HSHK
#define ENDPT4_EP_STALL                 _ENDPT4.Bits.EP_STALL
#define ENDPT4_EP_TX_EN                 _ENDPT4.Bits.EP_TX_EN
#define ENDPT4_EP_RX_EN                 _ENDPT4.Bits.EP_RX_EN
#define ENDPT4_EP_CTL_DIS               _ENDPT4.Bits.EP_CTL_DIS
#define ENDPT4_RETRY_DIS                _ENDPT4.Bits.RETRY_DIS
#define ENDPT4_HOST_WO_HUB              _ENDPT4.Bits.HOST_WO_HUB

#define ENDPT4_EP_HSHK_MASK             1U
#define ENDPT4_EP_STALL_MASK            2U
#define ENDPT4_EP_TX_EN_MASK            4U
#define ENDPT4_EP_RX_EN_MASK            8U
#define ENDPT4_EP_CTL_DIS_MASK          16U
#define ENDPT4_RETRY_DIS_MASK           64U
#define ENDPT4_HOST_WO_HUB_MASK         128U


/*** ENDPT5 - Endpoint Control Register 5; 0xFFFF9AD4 ***/
typedef union {
  byte Byte;
  struct {
    byte EP_HSHK     :1;                                       /* When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous */
    byte EP_STALL    :1;                                       /* When set this bit indicates that the endpoint is stalled */
    byte EP_TX_EN    :1;                                       /* This bit, when set, enables the endpoint for TX transfers */
    byte EP_RX_EN    :1;                                       /* This bit, when set, enables the endpoint for RX transfers */
    byte EP_CTL_DIS  :1;                                       /* This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set */
    byte             :1; 
    byte RETRY_DIS   :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
    byte HOST_WO_HUB :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
  } Bits;
} ENDPT5STR;
#define _ENDPT5 (*(volatile ENDPT5STR *)0xFFFF9AD4)
#define ENDPT5                          _ENDPT5.Byte
#define ENDPT5_EP_HSHK                  _ENDPT5.Bits.EP_HSHK
#define ENDPT5_EP_STALL                 _ENDPT5.Bits.EP_STALL
#define ENDPT5_EP_TX_EN                 _ENDPT5.Bits.EP_TX_EN
#define ENDPT5_EP_RX_EN                 _ENDPT5.Bits.EP_RX_EN
#define ENDPT5_EP_CTL_DIS               _ENDPT5.Bits.EP_CTL_DIS
#define ENDPT5_RETRY_DIS                _ENDPT5.Bits.RETRY_DIS
#define ENDPT5_HOST_WO_HUB              _ENDPT5.Bits.HOST_WO_HUB

#define ENDPT5_EP_HSHK_MASK             1U
#define ENDPT5_EP_STALL_MASK            2U
#define ENDPT5_EP_TX_EN_MASK            4U
#define ENDPT5_EP_RX_EN_MASK            8U
#define ENDPT5_EP_CTL_DIS_MASK          16U
#define ENDPT5_RETRY_DIS_MASK           64U
#define ENDPT5_HOST_WO_HUB_MASK         128U


/*** ENDPT6 - Endpoint Control Register 6; 0xFFFF9AD8 ***/
typedef union {
  byte Byte;
  struct {
    byte EP_HSHK     :1;                                       /* When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous */
    byte EP_STALL    :1;                                       /* When set this bit indicates that the endpoint is stalled */
    byte EP_TX_EN    :1;                                       /* This bit, when set, enables the endpoint for TX transfers */
    byte EP_RX_EN    :1;                                       /* This bit, when set, enables the endpoint for RX transfers */
    byte EP_CTL_DIS  :1;                                       /* This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set */
    byte             :1; 
    byte RETRY_DIS   :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
    byte HOST_WO_HUB :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
  } Bits;
} ENDPT6STR;
#define _ENDPT6 (*(volatile ENDPT6STR *)0xFFFF9AD8)
#define ENDPT6                          _ENDPT6.Byte
#define ENDPT6_EP_HSHK                  _ENDPT6.Bits.EP_HSHK
#define ENDPT6_EP_STALL                 _ENDPT6.Bits.EP_STALL
#define ENDPT6_EP_TX_EN                 _ENDPT6.Bits.EP_TX_EN
#define ENDPT6_EP_RX_EN                 _ENDPT6.Bits.EP_RX_EN
#define ENDPT6_EP_CTL_DIS               _ENDPT6.Bits.EP_CTL_DIS
#define ENDPT6_RETRY_DIS                _ENDPT6.Bits.RETRY_DIS
#define ENDPT6_HOST_WO_HUB              _ENDPT6.Bits.HOST_WO_HUB

#define ENDPT6_EP_HSHK_MASK             1U
#define ENDPT6_EP_STALL_MASK            2U
#define ENDPT6_EP_TX_EN_MASK            4U
#define ENDPT6_EP_RX_EN_MASK            8U
#define ENDPT6_EP_CTL_DIS_MASK          16U
#define ENDPT6_RETRY_DIS_MASK           64U
#define ENDPT6_HOST_WO_HUB_MASK         128U


/*** ENDPT7 - Endpoint Control Register 7; 0xFFFF9ADC ***/
typedef union {
  byte Byte;
  struct {
    byte EP_HSHK     :1;                                       /* When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous */
    byte EP_STALL    :1;                                       /* When set this bit indicates that the endpoint is stalled */
    byte EP_TX_EN    :1;                                       /* This bit, when set, enables the endpoint for TX transfers */
    byte EP_RX_EN    :1;                                       /* This bit, when set, enables the endpoint for RX transfers */
    byte EP_CTL_DIS  :1;                                       /* This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set */
    byte             :1; 
    byte RETRY_DIS   :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
    byte HOST_WO_HUB :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
  } Bits;
} ENDPT7STR;
#define _ENDPT7 (*(volatile ENDPT7STR *)0xFFFF9ADC)
#define ENDPT7                          _ENDPT7.Byte
#define ENDPT7_EP_HSHK                  _ENDPT7.Bits.EP_HSHK
#define ENDPT7_EP_STALL                 _ENDPT7.Bits.EP_STALL
#define ENDPT7_EP_TX_EN                 _ENDPT7.Bits.EP_TX_EN
#define ENDPT7_EP_RX_EN                 _ENDPT7.Bits.EP_RX_EN
#define ENDPT7_EP_CTL_DIS               _ENDPT7.Bits.EP_CTL_DIS
#define ENDPT7_RETRY_DIS                _ENDPT7.Bits.RETRY_DIS
#define ENDPT7_HOST_WO_HUB              _ENDPT7.Bits.HOST_WO_HUB

#define ENDPT7_EP_HSHK_MASK             1U
#define ENDPT7_EP_STALL_MASK            2U
#define ENDPT7_EP_TX_EN_MASK            4U
#define ENDPT7_EP_RX_EN_MASK            8U
#define ENDPT7_EP_CTL_DIS_MASK          16U
#define ENDPT7_RETRY_DIS_MASK           64U
#define ENDPT7_HOST_WO_HUB_MASK         128U


/*** ENDPT8 - Endpoint Control Register 8; 0xFFFF9AE0 ***/
typedef union {
  byte Byte;
  struct {
    byte EP_HSHK     :1;                                       /* When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous */
    byte EP_STALL    :1;                                       /* When set this bit indicates that the endpoint is stalled */
    byte EP_TX_EN    :1;                                       /* This bit, when set, enables the endpoint for TX transfers */
    byte EP_RX_EN    :1;                                       /* This bit, when set, enables the endpoint for RX transfers */
    byte EP_CTL_DIS  :1;                                       /* This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set */
    byte             :1; 
    byte RETRY_DIS   :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
    byte HOST_WO_HUB :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
  } Bits;
} ENDPT8STR;
#define _ENDPT8 (*(volatile ENDPT8STR *)0xFFFF9AE0)
#define ENDPT8                          _ENDPT8.Byte
#define ENDPT8_EP_HSHK                  _ENDPT8.Bits.EP_HSHK
#define ENDPT8_EP_STALL                 _ENDPT8.Bits.EP_STALL
#define ENDPT8_EP_TX_EN                 _ENDPT8.Bits.EP_TX_EN
#define ENDPT8_EP_RX_EN                 _ENDPT8.Bits.EP_RX_EN
#define ENDPT8_EP_CTL_DIS               _ENDPT8.Bits.EP_CTL_DIS
#define ENDPT8_RETRY_DIS                _ENDPT8.Bits.RETRY_DIS
#define ENDPT8_HOST_WO_HUB              _ENDPT8.Bits.HOST_WO_HUB

#define ENDPT8_EP_HSHK_MASK             1U
#define ENDPT8_EP_STALL_MASK            2U
#define ENDPT8_EP_TX_EN_MASK            4U
#define ENDPT8_EP_RX_EN_MASK            8U
#define ENDPT8_EP_CTL_DIS_MASK          16U
#define ENDPT8_RETRY_DIS_MASK           64U
#define ENDPT8_HOST_WO_HUB_MASK         128U


/*** ENDPT9 - Endpoint Control Register 9; 0xFFFF9AE4 ***/
typedef union {
  byte Byte;
  struct {
    byte EP_HSHK     :1;                                       /* When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous */
    byte EP_STALL    :1;                                       /* When set this bit indicates that the endpoint is stalled */
    byte EP_TX_EN    :1;                                       /* This bit, when set, enables the endpoint for TX transfers */
    byte EP_RX_EN    :1;                                       /* This bit, when set, enables the endpoint for RX transfers */
    byte EP_CTL_DIS  :1;                                       /* This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set */
    byte             :1; 
    byte RETRY_DIS   :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
    byte HOST_WO_HUB :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
  } Bits;
} ENDPT9STR;
#define _ENDPT9 (*(volatile ENDPT9STR *)0xFFFF9AE4)
#define ENDPT9                          _ENDPT9.Byte
#define ENDPT9_EP_HSHK                  _ENDPT9.Bits.EP_HSHK
#define ENDPT9_EP_STALL                 _ENDPT9.Bits.EP_STALL
#define ENDPT9_EP_TX_EN                 _ENDPT9.Bits.EP_TX_EN
#define ENDPT9_EP_RX_EN                 _ENDPT9.Bits.EP_RX_EN
#define ENDPT9_EP_CTL_DIS               _ENDPT9.Bits.EP_CTL_DIS
#define ENDPT9_RETRY_DIS                _ENDPT9.Bits.RETRY_DIS
#define ENDPT9_HOST_WO_HUB              _ENDPT9.Bits.HOST_WO_HUB

#define ENDPT9_EP_HSHK_MASK             1U
#define ENDPT9_EP_STALL_MASK            2U
#define ENDPT9_EP_TX_EN_MASK            4U
#define ENDPT9_EP_RX_EN_MASK            8U
#define ENDPT9_EP_CTL_DIS_MASK          16U
#define ENDPT9_RETRY_DIS_MASK           64U
#define ENDPT9_HOST_WO_HUB_MASK         128U


/*** ENDPT10 - Endpoint Control Register 10; 0xFFFF9AE8 ***/
typedef union {
  byte Byte;
  struct {
    byte EP_HSHK     :1;                                       /* When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous */
    byte EP_STALL    :1;                                       /* When set this bit indicates that the endpoint is stalled */
    byte EP_TX_EN    :1;                                       /* This bit, when set, enables the endpoint for TX transfers */
    byte EP_RX_EN    :1;                                       /* This bit, when set, enables the endpoint for RX transfers */
    byte EP_CTL_DIS  :1;                                       /* This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set */
    byte             :1; 
    byte RETRY_DIS   :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
    byte HOST_WO_HUB :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
  } Bits;
} ENDPT10STR;
#define _ENDPT10 (*(volatile ENDPT10STR *)0xFFFF9AE8)
#define ENDPT10                         _ENDPT10.Byte
#define ENDPT10_EP_HSHK                 _ENDPT10.Bits.EP_HSHK
#define ENDPT10_EP_STALL                _ENDPT10.Bits.EP_STALL
#define ENDPT10_EP_TX_EN                _ENDPT10.Bits.EP_TX_EN
#define ENDPT10_EP_RX_EN                _ENDPT10.Bits.EP_RX_EN
#define ENDPT10_EP_CTL_DIS              _ENDPT10.Bits.EP_CTL_DIS
#define ENDPT10_RETRY_DIS               _ENDPT10.Bits.RETRY_DIS
#define ENDPT10_HOST_WO_HUB             _ENDPT10.Bits.HOST_WO_HUB

#define ENDPT10_EP_HSHK_MASK            1U
#define ENDPT10_EP_STALL_MASK           2U
#define ENDPT10_EP_TX_EN_MASK           4U
#define ENDPT10_EP_RX_EN_MASK           8U
#define ENDPT10_EP_CTL_DIS_MASK         16U
#define ENDPT10_RETRY_DIS_MASK          64U
#define ENDPT10_HOST_WO_HUB_MASK        128U


/*** ENDPT11 - Endpoint Control Register 11; 0xFFFF9AEC ***/
typedef union {
  byte Byte;
  struct {
    byte EP_HSHK     :1;                                       /* When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous */
    byte EP_STALL    :1;                                       /* When set this bit indicates that the endpoint is stalled */
    byte EP_TX_EN    :1;                                       /* This bit, when set, enables the endpoint for TX transfers */
    byte EP_RX_EN    :1;                                       /* This bit, when set, enables the endpoint for RX transfers */
    byte EP_CTL_DIS  :1;                                       /* This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set */
    byte             :1; 
    byte RETRY_DIS   :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
    byte HOST_WO_HUB :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
  } Bits;
} ENDPT11STR;
#define _ENDPT11 (*(volatile ENDPT11STR *)0xFFFF9AEC)
#define ENDPT11                         _ENDPT11.Byte
#define ENDPT11_EP_HSHK                 _ENDPT11.Bits.EP_HSHK
#define ENDPT11_EP_STALL                _ENDPT11.Bits.EP_STALL
#define ENDPT11_EP_TX_EN                _ENDPT11.Bits.EP_TX_EN
#define ENDPT11_EP_RX_EN                _ENDPT11.Bits.EP_RX_EN
#define ENDPT11_EP_CTL_DIS              _ENDPT11.Bits.EP_CTL_DIS
#define ENDPT11_RETRY_DIS               _ENDPT11.Bits.RETRY_DIS
#define ENDPT11_HOST_WO_HUB             _ENDPT11.Bits.HOST_WO_HUB

#define ENDPT11_EP_HSHK_MASK            1U
#define ENDPT11_EP_STALL_MASK           2U
#define ENDPT11_EP_TX_EN_MASK           4U
#define ENDPT11_EP_RX_EN_MASK           8U
#define ENDPT11_EP_CTL_DIS_MASK         16U
#define ENDPT11_RETRY_DIS_MASK          64U
#define ENDPT11_HOST_WO_HUB_MASK        128U


/*** ENDPT12 - Endpoint Control Register 12; 0xFFFF9AF0 ***/
typedef union {
  byte Byte;
  struct {
    byte EP_HSHK     :1;                                       /* When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous */
    byte EP_STALL    :1;                                       /* When set this bit indicates that the endpoint is stalled */
    byte EP_TX_EN    :1;                                       /* This bit, when set, enables the endpoint for TX transfers */
    byte EP_RX_EN    :1;                                       /* This bit, when set, enables the endpoint for RX transfers */
    byte EP_CTL_DIS  :1;                                       /* This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set */
    byte             :1; 
    byte RETRY_DIS   :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
    byte HOST_WO_HUB :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
  } Bits;
} ENDPT12STR;
#define _ENDPT12 (*(volatile ENDPT12STR *)0xFFFF9AF0)
#define ENDPT12                         _ENDPT12.Byte
#define ENDPT12_EP_HSHK                 _ENDPT12.Bits.EP_HSHK
#define ENDPT12_EP_STALL                _ENDPT12.Bits.EP_STALL
#define ENDPT12_EP_TX_EN                _ENDPT12.Bits.EP_TX_EN
#define ENDPT12_EP_RX_EN                _ENDPT12.Bits.EP_RX_EN
#define ENDPT12_EP_CTL_DIS              _ENDPT12.Bits.EP_CTL_DIS
#define ENDPT12_RETRY_DIS               _ENDPT12.Bits.RETRY_DIS
#define ENDPT12_HOST_WO_HUB             _ENDPT12.Bits.HOST_WO_HUB

#define ENDPT12_EP_HSHK_MASK            1U
#define ENDPT12_EP_STALL_MASK           2U
#define ENDPT12_EP_TX_EN_MASK           4U
#define ENDPT12_EP_RX_EN_MASK           8U
#define ENDPT12_EP_CTL_DIS_MASK         16U
#define ENDPT12_RETRY_DIS_MASK          64U
#define ENDPT12_HOST_WO_HUB_MASK        128U


/*** ENDPT13 - Endpoint Control Register 13; 0xFFFF9AF4 ***/
typedef union {
  byte Byte;
  struct {
    byte EP_HSHK     :1;                                       /* When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous */
    byte EP_STALL    :1;                                       /* When set this bit indicates that the endpoint is stalled */
    byte EP_TX_EN    :1;                                       /* This bit, when set, enables the endpoint for TX transfers */
    byte EP_RX_EN    :1;                                       /* This bit, when set, enables the endpoint for RX transfers */
    byte EP_CTL_DIS  :1;                                       /* This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set */
    byte             :1; 
    byte RETRY_DIS   :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
    byte HOST_WO_HUB :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
  } Bits;
} ENDPT13STR;
#define _ENDPT13 (*(volatile ENDPT13STR *)0xFFFF9AF4)
#define ENDPT13                         _ENDPT13.Byte
#define ENDPT13_EP_HSHK                 _ENDPT13.Bits.EP_HSHK
#define ENDPT13_EP_STALL                _ENDPT13.Bits.EP_STALL
#define ENDPT13_EP_TX_EN                _ENDPT13.Bits.EP_TX_EN
#define ENDPT13_EP_RX_EN                _ENDPT13.Bits.EP_RX_EN
#define ENDPT13_EP_CTL_DIS              _ENDPT13.Bits.EP_CTL_DIS
#define ENDPT13_RETRY_DIS               _ENDPT13.Bits.RETRY_DIS
#define ENDPT13_HOST_WO_HUB             _ENDPT13.Bits.HOST_WO_HUB

#define ENDPT13_EP_HSHK_MASK            1U
#define ENDPT13_EP_STALL_MASK           2U
#define ENDPT13_EP_TX_EN_MASK           4U
#define ENDPT13_EP_RX_EN_MASK           8U
#define ENDPT13_EP_CTL_DIS_MASK         16U
#define ENDPT13_RETRY_DIS_MASK          64U
#define ENDPT13_HOST_WO_HUB_MASK        128U


/*** ENDPT14 - Endpoint Control Register 14; 0xFFFF9AF8 ***/
typedef union {
  byte Byte;
  struct {
    byte EP_HSHK     :1;                                       /* When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous */
    byte EP_STALL    :1;                                       /* When set this bit indicates that the endpoint is stalled */
    byte EP_TX_EN    :1;                                       /* This bit, when set, enables the endpoint for TX transfers */
    byte EP_RX_EN    :1;                                       /* This bit, when set, enables the endpoint for RX transfers */
    byte EP_CTL_DIS  :1;                                       /* This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set */
    byte             :1; 
    byte RETRY_DIS   :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
    byte HOST_WO_HUB :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
  } Bits;
} ENDPT14STR;
#define _ENDPT14 (*(volatile ENDPT14STR *)0xFFFF9AF8)
#define ENDPT14                         _ENDPT14.Byte
#define ENDPT14_EP_HSHK                 _ENDPT14.Bits.EP_HSHK
#define ENDPT14_EP_STALL                _ENDPT14.Bits.EP_STALL
#define ENDPT14_EP_TX_EN                _ENDPT14.Bits.EP_TX_EN
#define ENDPT14_EP_RX_EN                _ENDPT14.Bits.EP_RX_EN
#define ENDPT14_EP_CTL_DIS              _ENDPT14.Bits.EP_CTL_DIS
#define ENDPT14_RETRY_DIS               _ENDPT14.Bits.RETRY_DIS
#define ENDPT14_HOST_WO_HUB             _ENDPT14.Bits.HOST_WO_HUB

#define ENDPT14_EP_HSHK_MASK            1U
#define ENDPT14_EP_STALL_MASK           2U
#define ENDPT14_EP_TX_EN_MASK           4U
#define ENDPT14_EP_RX_EN_MASK           8U
#define ENDPT14_EP_CTL_DIS_MASK         16U
#define ENDPT14_RETRY_DIS_MASK          64U
#define ENDPT14_HOST_WO_HUB_MASK        128U


/*** ENDPT15 - Endpoint Control Register 15; 0xFFFF9AFC ***/
typedef union {
  byte Byte;
  struct {
    byte EP_HSHK     :1;                                       /* When set this bet enables an endpoint to perform handshaking during a transaction to this endpoint. This bit will generally be set unless the endpoint is Isochronous */
    byte EP_STALL    :1;                                       /* When set this bit indicates that the endpoint is stalled */
    byte EP_TX_EN    :1;                                       /* This bit, when set, enables the endpoint for TX transfers */
    byte EP_RX_EN    :1;                                       /* This bit, when set, enables the endpoint for RX transfers */
    byte EP_CTL_DIS  :1;                                       /* This bit, when set, disables control (SETUP) transfers. When cleared, control transfers are enabled. This applies if and only if the EP_RX_EN and EP_TX_EN bits are also set */
    byte             :1; 
    byte RETRY_DIS   :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
    byte HOST_WO_HUB :1;                                       /* Not available. Present only in endpoint 0 control register (ENDPT0) */
  } Bits;
} ENDPT15STR;
#define _ENDPT15 (*(volatile ENDPT15STR *)0xFFFF9AFC)
#define ENDPT15                         _ENDPT15.Byte
#define ENDPT15_EP_HSHK                 _ENDPT15.Bits.EP_HSHK
#define ENDPT15_EP_STALL                _ENDPT15.Bits.EP_STALL
#define ENDPT15_EP_TX_EN                _ENDPT15.Bits.EP_TX_EN
#define ENDPT15_EP_RX_EN                _ENDPT15.Bits.EP_RX_EN
#define ENDPT15_EP_CTL_DIS              _ENDPT15.Bits.EP_CTL_DIS
#define ENDPT15_RETRY_DIS               _ENDPT15.Bits.RETRY_DIS
#define ENDPT15_HOST_WO_HUB             _ENDPT15.Bits.HOST_WO_HUB

#define ENDPT15_EP_HSHK_MASK            1U
#define ENDPT15_EP_STALL_MASK           2U
#define ENDPT15_EP_TX_EN_MASK           4U
#define ENDPT15_EP_RX_EN_MASK           8U
#define ENDPT15_EP_CTL_DIS_MASK         16U
#define ENDPT15_RETRY_DIS_MASK          64U
#define ENDPT15_HOST_WO_HUB_MASK        128U


/*** USB_CTRL - USB Control Register; 0xFFFF9B00 ***/
typedef union {
  byte Byte;
  struct {
    byte CLK_SRC0    :1;                                       /* Determines the clock source for the USB 48 MHZ clock, bit 0 */
    byte CLK_SRC1    :1;                                       /* Determines the clock source for the USB 48 MHZ clock, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PDE         :1;                                       /* Enables the non-functional weak pulldowns on the USB transceiver */
    byte SUSP        :1;                                       /* Places the USB transceiver into the suspend state */
  } Bits;
  struct {
    byte grpCLK_SRC :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} USB_CTRLSTR;
#define _USB_CTRL (*(volatile USB_CTRLSTR *)0xFFFF9B00)
#define USB_CTRL                        _USB_CTRL.Byte
#define USB_CTRL_CLK_SRC0               _USB_CTRL.Bits.CLK_SRC0
#define USB_CTRL_CLK_SRC1               _USB_CTRL.Bits.CLK_SRC1
#define USB_CTRL_PDE                    _USB_CTRL.Bits.PDE
#define USB_CTRL_SUSP                   _USB_CTRL.Bits.SUSP
#define USB_CTRL_CLK_SRC                _USB_CTRL.MergedBits.grpCLK_SRC

#define USB_CTRL_CLK_SRC0_MASK          1U
#define USB_CTRL_CLK_SRC1_MASK          2U
#define USB_CTRL_PDE_MASK               64U
#define USB_CTRL_SUSP_MASK              128U
#define USB_CTRL_CLK_SRC_MASK           3U
#define USB_CTRL_CLK_SRC_BITNUM         0U


/*** USB_OTG_OBSERVE - USB OTG Observe Register; 0xFFFF9B04 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DM_PD       :1;                                       /* Provides observability of the D- Pull Down signal output from the USB OTG module. Useful when interfacing to an external OTG control module via a serial interface */
    byte             :1; 
    byte DP_PD       :1;                                       /* Provides observability of the D+ Pull Down signal output from the USB OTG module. Useful when interfacing to an external OTG control module via a serial interface */
    byte DP_PU       :1;                                       /* Provides observability of the D+ Pull Up signal output from the USB OTG module. This bit is useful when interfacing to anexternal OTG control module via a serial interface. Useful when interfacing to an external OTG control module via a serial interface */
  } Bits;
} USB_OTG_OBSERVESTR;
#define _USB_OTG_OBSERVE (*(volatile USB_OTG_OBSERVESTR *)0xFFFF9B04)
#define USB_OTG_OBSERVE                 _USB_OTG_OBSERVE.Byte
#define USB_OTG_OBSERVE_DM_PD           _USB_OTG_OBSERVE.Bits.DM_PD
#define USB_OTG_OBSERVE_DP_PD           _USB_OTG_OBSERVE.Bits.DP_PD
#define USB_OTG_OBSERVE_DP_PU           _USB_OTG_OBSERVE.Bits.DP_PU

#define USB_OTG_OBSERVE_DM_PD_MASK      16U
#define USB_OTG_OBSERVE_DP_PD_MASK      64U
#define USB_OTG_OBSERVE_DP_PU_MASK      128U


/*** USB_OTG_CONTROL - USB OTG Control Register; 0xFFFF9B08 ***/
typedef union {
  byte Byte;
  struct {
    byte SESSEND     :1;                                       /* Provides observability of the Session End signal output from the USB OTG module. Useful when interfacing to an external OTG control module via a serial interface */
    byte SESSVLD     :1;                                       /* Provides observability of the Session Valid signal output from the USB OTG module. Useful when interfacing to an external OTG control module via a serial interface */
    byte VBUSVLD     :1;                                       /* Provides control of the VBUS Valid signal into the USB OTG module if a pin has not been configured for this function. Useful when interfacing to an external OTG control module via a serial interface */
    byte ID          :1;                                       /* Provides control of the USB ID signal into the USB OTG module if a pin has not been configured for this function. Useful when interfacing to an external OTG control module via a serial interface */
    byte DPPULLUP_NONOTG :1;                                   /* Provides control of the DP PULLUP in the USB OTG module, if USB is configured in non-OTG device mode */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} USB_OTG_CONTROLSTR;
#define _USB_OTG_CONTROL (*(volatile USB_OTG_CONTROLSTR *)0xFFFF9B08)
#define USB_OTG_CONTROL                 _USB_OTG_CONTROL.Byte
#define USB_OTG_CONTROL_SESSEND         _USB_OTG_CONTROL.Bits.SESSEND
#define USB_OTG_CONTROL_SESSVLD         _USB_OTG_CONTROL.Bits.SESSVLD
#define USB_OTG_CONTROL_VBUSVLD         _USB_OTG_CONTROL.Bits.VBUSVLD
#define USB_OTG_CONTROL_ID              _USB_OTG_CONTROL.Bits.ID
#define USB_OTG_CONTROL_DPPULLUP_NONOTG _USB_OTG_CONTROL.Bits.DPPULLUP_NONOTG

#define USB_OTG_CONTROL_SESSEND_MASK    1U
#define USB_OTG_CONTROL_SESSVLD_MASK    2U
#define USB_OTG_CONTROL_VBUSVLD_MASK    4U
#define USB_OTG_CONTROL_ID_MASK         8U
#define USB_OTG_CONTROL_DPPULLUP_NONOTG_MASK 16U


/*** USBTRC0 - USB Transceiver and Regulator Control Register 0; 0xFFFF9B0C ***/
typedef union {
  byte Byte;
  struct {
    byte USB_RESUME_INT :1;                                    /* USB Asynchronous Interrupt */
    byte             :1; 
    byte USBVREN     :1;                                       /* USB voltage regulator enable */
    byte             :1; 
    byte             :1; 
    byte USBRESMEN   :1;                                       /* Allows the USB module to send an asynchronous wakeup event upon detection of resume signaling on the USB bus */
    byte USBPU       :1;                                       /* Pull-up resistor on the USBDP line */
    byte USBRESET    :1;                                       /* Generates a hard reset to the USB module */
  } Bits;
} USBTRC0STR;
#define _USBTRC0 (*(volatile USBTRC0STR *)0xFFFF9B0C)
#define USBTRC0                         _USBTRC0.Byte
#define USBTRC0_USB_RESUME_INT          _USBTRC0.Bits.USB_RESUME_INT
#define USBTRC0_USBVREN                 _USBTRC0.Bits.USBVREN
#define USBTRC0_USBRESMEN               _USBTRC0.Bits.USBRESMEN
#define USBTRC0_USBPU                   _USBTRC0.Bits.USBPU
#define USBTRC0_USBRESET                _USBTRC0.Bits.USBRESET

#define USBTRC0_USB_RESUME_INT_MASK     1U
#define USBTRC0_USBVREN_MASK            4U
#define USBTRC0_USBRESMEN_MASK          32U
#define USBTRC0_USBPU_MASK              64U
#define USBTRC0_USBRESET_MASK           128U


/*** OTGPIN - USB OTG Pin Control Register; 0xFFFF9B10 ***/
typedef union {
  byte Byte;
  struct {
    byte SESSVLD     :1;                                       /* Session Valid Pin Enable */
    byte SESSEND     :1;                                       /* Session End Pin Enable */
    byte VBUSVLD     :1;                                       /* Valid Pin Enable */
    byte PULLUP      :1;                                       /* Pull-up Pin Enable */
    byte DMDOWN      :1;                                       /* DMDOWN Pin Enable */
    byte DPDOWN      :1;                                       /* DPDOWN Pin Enable */
    byte USBID       :1;                                       /* USB_ID Pin Enable */
    byte             :1; 
  } Bits;
} OTGPINSTR;
#define _OTGPIN (*(volatile OTGPINSTR *)0xFFFF9B10)
#define OTGPIN                          _OTGPIN.Byte
#define OTGPIN_SESSVLD                  _OTGPIN.Bits.SESSVLD
#define OTGPIN_SESSEND                  _OTGPIN.Bits.SESSEND
#define OTGPIN_VBUSVLD                  _OTGPIN.Bits.VBUSVLD
#define OTGPIN_PULLUP                   _OTGPIN.Bits.PULLUP
#define OTGPIN_DMDOWN                   _OTGPIN.Bits.DMDOWN
#define OTGPIN_DPDOWN                   _OTGPIN.Bits.DPDOWN
#define OTGPIN_USBID                    _OTGPIN.Bits.USBID

#define OTGPIN_SESSVLD_MASK             1U
#define OTGPIN_SESSEND_MASK             2U
#define OTGPIN_VBUSVLD_MASK             4U
#define OTGPIN_PULLUP_MASK              8U
#define OTGPIN_DMDOWN_MASK              16U
#define OTGPIN_DPDOWN_MASK              32U
#define OTGPIN_USBID_MASK               64U


/*** INTC_FRC - INTC Force Interrupt Register; 0xFFFFFFD0 ***/
typedef union {
  byte Byte;
  struct {
    byte LVL7        :1;                                       /* Force Level 7 interrupt */
    byte LVL6        :1;                                       /* Force Level 6 interrupt */
    byte LVL5        :1;                                       /* Force Level 5 interrupt */
    byte LVL4        :1;                                       /* Force Level 4 interrupt */
    byte LVL3        :1;                                       /* Force Level 3 interrupt */
    byte LVL2        :1;                                       /* Force Level 2 interrupt */
    byte LVL1        :1;                                       /* Force Level 1 interrupt */
    byte             :1; 
  } Bits;
} INTC_FRCSTR;
#define _INTC_FRC (*(volatile INTC_FRCSTR *)0xFFFFFFD0)
#define INTC_FRC                        _INTC_FRC.Byte
#define INTC_FRC_LVL7                   _INTC_FRC.Bits.LVL7
#define INTC_FRC_LVL6                   _INTC_FRC.Bits.LVL6
#define INTC_FRC_LVL5                   _INTC_FRC.Bits.LVL5
#define INTC_FRC_LVL4                   _INTC_FRC.Bits.LVL4
#define INTC_FRC_LVL3                   _INTC_FRC.Bits.LVL3
#define INTC_FRC_LVL2                   _INTC_FRC.Bits.LVL2
#define INTC_FRC_LVL1                   _INTC_FRC.Bits.LVL1

#define INTC_FRC_LVL7_MASK              1U
#define INTC_FRC_LVL6_MASK              2U
#define INTC_FRC_LVL5_MASK              4U
#define INTC_FRC_LVL4_MASK              8U
#define INTC_FRC_LVL3_MASK              16U
#define INTC_FRC_LVL2_MASK              32U
#define INTC_FRC_LVL1_MASK              64U


/*** INTC_PL6P7 - INTC Programmable Level 6, Priority 7 Register; 0xFFFFFFD8 ***/
typedef union {
  byte Byte;
  struct {
    byte REQN0       :1;                                       /* Request number, bit 0 */
    byte REQN1       :1;                                       /* Request number, bit 1 */
    byte REQN2       :1;                                       /* Request number, bit 2 */
    byte REQN3       :1;                                       /* Request number, bit 3 */
    byte REQN4       :1;                                       /* Request number, bit 4 */
    byte REQN5       :1;                                       /* Request number, bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpREQN :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} INTC_PL6P7STR;
#define _INTC_PL6P7 (*(volatile INTC_PL6P7STR *)0xFFFFFFD8)
#define INTC_PL6P7                      _INTC_PL6P7.Byte
#define INTC_PL6P7_REQN0                _INTC_PL6P7.Bits.REQN0
#define INTC_PL6P7_REQN1                _INTC_PL6P7.Bits.REQN1
#define INTC_PL6P7_REQN2                _INTC_PL6P7.Bits.REQN2
#define INTC_PL6P7_REQN3                _INTC_PL6P7.Bits.REQN3
#define INTC_PL6P7_REQN4                _INTC_PL6P7.Bits.REQN4
#define INTC_PL6P7_REQN5                _INTC_PL6P7.Bits.REQN5
#define INTC_PL6P7_REQN                 _INTC_PL6P7.MergedBits.grpREQN

#define INTC_PL6P7_REQN0_MASK           1U
#define INTC_PL6P7_REQN1_MASK           2U
#define INTC_PL6P7_REQN2_MASK           4U
#define INTC_PL6P7_REQN3_MASK           8U
#define INTC_PL6P7_REQN4_MASK           16U
#define INTC_PL6P7_REQN5_MASK           32U
#define INTC_PL6P7_REQN_MASK            63U
#define INTC_PL6P7_REQN_BITNUM          0U


/*** INTC_PL6P6 - INTC Programmable Level 6, Priority 6 Register; 0xFFFFFFD9 ***/
typedef union {
  byte Byte;
  struct {
    byte REQN0       :1;                                       /* Request number, bit 0 */
    byte REQN1       :1;                                       /* Request number, bit 1 */
    byte REQN2       :1;                                       /* Request number, bit 2 */
    byte REQN3       :1;                                       /* Request number, bit 3 */
    byte REQN4       :1;                                       /* Request number, bit 4 */
    byte REQN5       :1;                                       /* Request number, bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpREQN :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} INTC_PL6P6STR;
#define _INTC_PL6P6 (*(volatile INTC_PL6P6STR *)0xFFFFFFD9)
#define INTC_PL6P6                      _INTC_PL6P6.Byte
#define INTC_PL6P6_REQN0                _INTC_PL6P6.Bits.REQN0
#define INTC_PL6P6_REQN1                _INTC_PL6P6.Bits.REQN1
#define INTC_PL6P6_REQN2                _INTC_PL6P6.Bits.REQN2
#define INTC_PL6P6_REQN3                _INTC_PL6P6.Bits.REQN3
#define INTC_PL6P6_REQN4                _INTC_PL6P6.Bits.REQN4
#define INTC_PL6P6_REQN5                _INTC_PL6P6.Bits.REQN5
#define INTC_PL6P6_REQN                 _INTC_PL6P6.MergedBits.grpREQN

#define INTC_PL6P6_REQN0_MASK           1U
#define INTC_PL6P6_REQN1_MASK           2U
#define INTC_PL6P6_REQN2_MASK           4U
#define INTC_PL6P6_REQN3_MASK           8U
#define INTC_PL6P6_REQN4_MASK           16U
#define INTC_PL6P6_REQN5_MASK           32U
#define INTC_PL6P6_REQN_MASK            63U
#define INTC_PL6P6_REQN_BITNUM          0U


/*** INTC_WCR - INTC Wake-up Control Register; 0xFFFFFFDB ***/
typedef union {
  byte Byte;
  struct {
    byte MASK0       :1;                                       /* Interrupt mask level, bit 0 */
    byte MASK1       :1;                                       /* Interrupt mask level, bit 1 */
    byte MASK2       :1;                                       /* Interrupt mask level, bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ENB         :1;                                       /* Enable */
  } Bits;
  struct {
    byte grpMASK :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} INTC_WCRSTR;
#define _INTC_WCR (*(volatile INTC_WCRSTR *)0xFFFFFFDB)
#define INTC_WCR                        _INTC_WCR.Byte
#define INTC_WCR_MASK0                  _INTC_WCR.Bits.MASK0
#define INTC_WCR_MASK1                  _INTC_WCR.Bits.MASK1
#define INTC_WCR_MASK2                  _INTC_WCR.Bits.MASK2
#define INTC_WCR_ENB                    _INTC_WCR.Bits.ENB
#define INTC_WCR_MASK                   _INTC_WCR.MergedBits.grpMASK

#define INTC_WCR_MASK0_MASK             1U
#define INTC_WCR_MASK1_MASK             2U
#define INTC_WCR_MASK2_MASK             4U
#define INTC_WCR_ENB_MASK               128U
#define INTC_WCR_MASK_MASK              7U
#define INTC_WCR_MASK_BITNUM            0U


/*** INTC_SFRC - INTC Set Interrupt Force Register; 0xFFFFFFDE ***/
typedef union {
  byte Byte;
  struct {
    byte SET0        :1;                                       /* Sets corresponding bits in the INTC_FRC register, bit 0 */
    byte SET1        :1;                                       /* Sets corresponding bits in the INTC_FRC register, bit 1 */
    byte SET2        :1;                                       /* Sets corresponding bits in the INTC_FRC register, bit 2 */
    byte SET3        :1;                                       /* Sets corresponding bits in the INTC_FRC register, bit 3 */
    byte SET4        :1;                                       /* Sets corresponding bits in the INTC_FRC register, bit 4 */
    byte SET5        :1;                                       /* Sets corresponding bits in the INTC_FRC register, bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpSET  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} INTC_SFRCSTR;
#define _INTC_SFRC (*(volatile INTC_SFRCSTR *)0xFFFFFFDE)
#define INTC_SFRC                       _INTC_SFRC.Byte
#define INTC_SFRC_SET0                  _INTC_SFRC.Bits.SET0
#define INTC_SFRC_SET1                  _INTC_SFRC.Bits.SET1
#define INTC_SFRC_SET2                  _INTC_SFRC.Bits.SET2
#define INTC_SFRC_SET3                  _INTC_SFRC.Bits.SET3
#define INTC_SFRC_SET4                  _INTC_SFRC.Bits.SET4
#define INTC_SFRC_SET5                  _INTC_SFRC.Bits.SET5
#define INTC_SFRC_SET                   _INTC_SFRC.MergedBits.grpSET

#define INTC_SFRC_SET0_MASK             1U
#define INTC_SFRC_SET1_MASK             2U
#define INTC_SFRC_SET2_MASK             4U
#define INTC_SFRC_SET3_MASK             8U
#define INTC_SFRC_SET4_MASK             16U
#define INTC_SFRC_SET5_MASK             32U
#define INTC_SFRC_SET_MASK              63U
#define INTC_SFRC_SET_BITNUM            0U


/*** INTC_CFRC - INTC Clear Interrupt Force Register; 0xFFFFFFDF ***/
typedef union {
  byte Byte;
  struct {
    byte CLR0        :1;                                       /* Clears corresponding bits in the INTC_FRC register, bit 0 */
    byte CLR1        :1;                                       /* Clears corresponding bits in the INTC_FRC register, bit 1 */
    byte CLR2        :1;                                       /* Clears corresponding bits in the INTC_FRC register, bit 2 */
    byte CLR3        :1;                                       /* Clears corresponding bits in the INTC_FRC register, bit 3 */
    byte CLR4        :1;                                       /* Clears corresponding bits in the INTC_FRC register, bit 4 */
    byte CLR5        :1;                                       /* Clears corresponding bits in the INTC_FRC register, bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCLR  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} INTC_CFRCSTR;
#define _INTC_CFRC (*(volatile INTC_CFRCSTR *)0xFFFFFFDF)
#define INTC_CFRC                       _INTC_CFRC.Byte
#define INTC_CFRC_CLR0                  _INTC_CFRC.Bits.CLR0
#define INTC_CFRC_CLR1                  _INTC_CFRC.Bits.CLR1
#define INTC_CFRC_CLR2                  _INTC_CFRC.Bits.CLR2
#define INTC_CFRC_CLR3                  _INTC_CFRC.Bits.CLR3
#define INTC_CFRC_CLR4                  _INTC_CFRC.Bits.CLR4
#define INTC_CFRC_CLR5                  _INTC_CFRC.Bits.CLR5
#define INTC_CFRC_CLR                   _INTC_CFRC.MergedBits.grpCLR

#define INTC_CFRC_CLR0_MASK             1U
#define INTC_CFRC_CLR1_MASK             2U
#define INTC_CFRC_CLR2_MASK             4U
#define INTC_CFRC_CLR3_MASK             8U
#define INTC_CFRC_CLR4_MASK             16U
#define INTC_CFRC_CLR5_MASK             32U
#define INTC_CFRC_CLR_MASK              63U
#define INTC_CFRC_CLR_BITNUM            0U


/*** INTC_SWIACK - INTC Software IACK Register; 0xFFFFFFE0 ***/
typedef union {
  byte Byte;
  struct {
    byte VECN0       :1;                                       /* Vector number, bit 0 */
    byte VECN1       :1;                                       /* Vector number, bit 1 */
    byte VECN2       :1;                                       /* Vector number, bit 2 */
    byte VECN3       :1;                                       /* Vector number, bit 3 */
    byte VECN4       :1;                                       /* Vector number, bit 4 */
    byte VECN5       :1;                                       /* Vector number, bit 5 */
    byte VECN6       :1;                                       /* Vector number, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpVECN :7;
    byte         :1;
  } MergedBits;
} INTC_SWIACKSTR;
#define _INTC_SWIACK (*(volatile INTC_SWIACKSTR *)0xFFFFFFE0)
#define INTC_SWIACK                     _INTC_SWIACK.Byte
#define INTC_SWIACK_VECN0               _INTC_SWIACK.Bits.VECN0
#define INTC_SWIACK_VECN1               _INTC_SWIACK.Bits.VECN1
#define INTC_SWIACK_VECN2               _INTC_SWIACK.Bits.VECN2
#define INTC_SWIACK_VECN3               _INTC_SWIACK.Bits.VECN3
#define INTC_SWIACK_VECN4               _INTC_SWIACK.Bits.VECN4
#define INTC_SWIACK_VECN5               _INTC_SWIACK.Bits.VECN5
#define INTC_SWIACK_VECN6               _INTC_SWIACK.Bits.VECN6
#define INTC_SWIACK_VECN                _INTC_SWIACK.MergedBits.grpVECN

#define INTC_SWIACK_VECN0_MASK          1U
#define INTC_SWIACK_VECN1_MASK          2U
#define INTC_SWIACK_VECN2_MASK          4U
#define INTC_SWIACK_VECN3_MASK          8U
#define INTC_SWIACK_VECN4_MASK          16U
#define INTC_SWIACK_VECN5_MASK          32U
#define INTC_SWIACK_VECN6_MASK          64U
#define INTC_SWIACK_VECN_MASK           127U
#define INTC_SWIACK_VECN_BITNUM         0U


/*** INTC_LVL1IACK - INTC Level 1 IACK Register; 0xFFFFFFE4 ***/
typedef union {
  byte Byte;
  struct {
    byte VECN0       :1;                                       /* Vector number, bit 0 */
    byte VECN1       :1;                                       /* Vector number, bit 1 */
    byte VECN2       :1;                                       /* Vector number, bit 2 */
    byte VECN3       :1;                                       /* Vector number, bit 3 */
    byte VECN4       :1;                                       /* Vector number, bit 4 */
    byte VECN5       :1;                                       /* Vector number, bit 5 */
    byte VECN6       :1;                                       /* Vector number, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpVECN :7;
    byte         :1;
  } MergedBits;
} INTC_LVL1IACKSTR;
#define _INTC_LVL1IACK (*(volatile INTC_LVL1IACKSTR *)0xFFFFFFE4)
#define INTC_LVL1IACK                   _INTC_LVL1IACK.Byte
#define INTC_LVL1IACK_VECN0             _INTC_LVL1IACK.Bits.VECN0
#define INTC_LVL1IACK_VECN1             _INTC_LVL1IACK.Bits.VECN1
#define INTC_LVL1IACK_VECN2             _INTC_LVL1IACK.Bits.VECN2
#define INTC_LVL1IACK_VECN3             _INTC_LVL1IACK.Bits.VECN3
#define INTC_LVL1IACK_VECN4             _INTC_LVL1IACK.Bits.VECN4
#define INTC_LVL1IACK_VECN5             _INTC_LVL1IACK.Bits.VECN5
#define INTC_LVL1IACK_VECN6             _INTC_LVL1IACK.Bits.VECN6
#define INTC_LVL1IACK_VECN              _INTC_LVL1IACK.MergedBits.grpVECN

#define INTC_LVL1IACK_VECN0_MASK        1U
#define INTC_LVL1IACK_VECN1_MASK        2U
#define INTC_LVL1IACK_VECN2_MASK        4U
#define INTC_LVL1IACK_VECN3_MASK        8U
#define INTC_LVL1IACK_VECN4_MASK        16U
#define INTC_LVL1IACK_VECN5_MASK        32U
#define INTC_LVL1IACK_VECN6_MASK        64U
#define INTC_LVL1IACK_VECN_MASK         127U
#define INTC_LVL1IACK_VECN_BITNUM       0U


/*** INTC_LVL2IACK - INTC Level 2 IACK Register; 0xFFFFFFE8 ***/
typedef union {
  byte Byte;
  struct {
    byte VECN0       :1;                                       /* Vector number, bit 0 */
    byte VECN1       :1;                                       /* Vector number, bit 1 */
    byte VECN2       :1;                                       /* Vector number, bit 2 */
    byte VECN3       :1;                                       /* Vector number, bit 3 */
    byte VECN4       :1;                                       /* Vector number, bit 4 */
    byte VECN5       :1;                                       /* Vector number, bit 5 */
    byte VECN6       :1;                                       /* Vector number, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpVECN :7;
    byte         :1;
  } MergedBits;
} INTC_LVL2IACKSTR;
#define _INTC_LVL2IACK (*(volatile INTC_LVL2IACKSTR *)0xFFFFFFE8)
#define INTC_LVL2IACK                   _INTC_LVL2IACK.Byte
#define INTC_LVL2IACK_VECN0             _INTC_LVL2IACK.Bits.VECN0
#define INTC_LVL2IACK_VECN1             _INTC_LVL2IACK.Bits.VECN1
#define INTC_LVL2IACK_VECN2             _INTC_LVL2IACK.Bits.VECN2
#define INTC_LVL2IACK_VECN3             _INTC_LVL2IACK.Bits.VECN3
#define INTC_LVL2IACK_VECN4             _INTC_LVL2IACK.Bits.VECN4
#define INTC_LVL2IACK_VECN5             _INTC_LVL2IACK.Bits.VECN5
#define INTC_LVL2IACK_VECN6             _INTC_LVL2IACK.Bits.VECN6
#define INTC_LVL2IACK_VECN              _INTC_LVL2IACK.MergedBits.grpVECN

#define INTC_LVL2IACK_VECN0_MASK        1U
#define INTC_LVL2IACK_VECN1_MASK        2U
#define INTC_LVL2IACK_VECN2_MASK        4U
#define INTC_LVL2IACK_VECN3_MASK        8U
#define INTC_LVL2IACK_VECN4_MASK        16U
#define INTC_LVL2IACK_VECN5_MASK        32U
#define INTC_LVL2IACK_VECN6_MASK        64U
#define INTC_LVL2IACK_VECN_MASK         127U
#define INTC_LVL2IACK_VECN_BITNUM       0U


/*** INTC_LVL3IACK - INTC Level 3 IACK Register; 0xFFFFFFEC ***/
typedef union {
  byte Byte;
  struct {
    byte VECN0       :1;                                       /* Vector number, bit 0 */
    byte VECN1       :1;                                       /* Vector number, bit 1 */
    byte VECN2       :1;                                       /* Vector number, bit 2 */
    byte VECN3       :1;                                       /* Vector number, bit 3 */
    byte VECN4       :1;                                       /* Vector number, bit 4 */
    byte VECN5       :1;                                       /* Vector number, bit 5 */
    byte VECN6       :1;                                       /* Vector number, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpVECN :7;
    byte         :1;
  } MergedBits;
} INTC_LVL3IACKSTR;
#define _INTC_LVL3IACK (*(volatile INTC_LVL3IACKSTR *)0xFFFFFFEC)
#define INTC_LVL3IACK                   _INTC_LVL3IACK.Byte
#define INTC_LVL3IACK_VECN0             _INTC_LVL3IACK.Bits.VECN0
#define INTC_LVL3IACK_VECN1             _INTC_LVL3IACK.Bits.VECN1
#define INTC_LVL3IACK_VECN2             _INTC_LVL3IACK.Bits.VECN2
#define INTC_LVL3IACK_VECN3             _INTC_LVL3IACK.Bits.VECN3
#define INTC_LVL3IACK_VECN4             _INTC_LVL3IACK.Bits.VECN4
#define INTC_LVL3IACK_VECN5             _INTC_LVL3IACK.Bits.VECN5
#define INTC_LVL3IACK_VECN6             _INTC_LVL3IACK.Bits.VECN6
#define INTC_LVL3IACK_VECN              _INTC_LVL3IACK.MergedBits.grpVECN

#define INTC_LVL3IACK_VECN0_MASK        1U
#define INTC_LVL3IACK_VECN1_MASK        2U
#define INTC_LVL3IACK_VECN2_MASK        4U
#define INTC_LVL3IACK_VECN3_MASK        8U
#define INTC_LVL3IACK_VECN4_MASK        16U
#define INTC_LVL3IACK_VECN5_MASK        32U
#define INTC_LVL3IACK_VECN6_MASK        64U
#define INTC_LVL3IACK_VECN_MASK         127U
#define INTC_LVL3IACK_VECN_BITNUM       0U


/*** INTC_LVL4IACK - INTC Level 4 IACK Register; 0xFFFFFFF0 ***/
typedef union {
  byte Byte;
  struct {
    byte VECN0       :1;                                       /* Vector number, bit 0 */
    byte VECN1       :1;                                       /* Vector number, bit 1 */
    byte VECN2       :1;                                       /* Vector number, bit 2 */
    byte VECN3       :1;                                       /* Vector number, bit 3 */
    byte VECN4       :1;                                       /* Vector number, bit 4 */
    byte VECN5       :1;                                       /* Vector number, bit 5 */
    byte VECN6       :1;                                       /* Vector number, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpVECN :7;
    byte         :1;
  } MergedBits;
} INTC_LVL4IACKSTR;
#define _INTC_LVL4IACK (*(volatile INTC_LVL4IACKSTR *)0xFFFFFFF0)
#define INTC_LVL4IACK                   _INTC_LVL4IACK.Byte
#define INTC_LVL4IACK_VECN0             _INTC_LVL4IACK.Bits.VECN0
#define INTC_LVL4IACK_VECN1             _INTC_LVL4IACK.Bits.VECN1
#define INTC_LVL4IACK_VECN2             _INTC_LVL4IACK.Bits.VECN2
#define INTC_LVL4IACK_VECN3             _INTC_LVL4IACK.Bits.VECN3
#define INTC_LVL4IACK_VECN4             _INTC_LVL4IACK.Bits.VECN4
#define INTC_LVL4IACK_VECN5             _INTC_LVL4IACK.Bits.VECN5
#define INTC_LVL4IACK_VECN6             _INTC_LVL4IACK.Bits.VECN6
#define INTC_LVL4IACK_VECN              _INTC_LVL4IACK.MergedBits.grpVECN

#define INTC_LVL4IACK_VECN0_MASK        1U
#define INTC_LVL4IACK_VECN1_MASK        2U
#define INTC_LVL4IACK_VECN2_MASK        4U
#define INTC_LVL4IACK_VECN3_MASK        8U
#define INTC_LVL4IACK_VECN4_MASK        16U
#define INTC_LVL4IACK_VECN5_MASK        32U
#define INTC_LVL4IACK_VECN6_MASK        64U
#define INTC_LVL4IACK_VECN_MASK         127U
#define INTC_LVL4IACK_VECN_BITNUM       0U


/*** INTC_LVL5IACK - INTC Level 5 IACK Register; 0xFFFFFFF4 ***/
typedef union {
  byte Byte;
  struct {
    byte VECN0       :1;                                       /* Vector number, bit 0 */
    byte VECN1       :1;                                       /* Vector number, bit 1 */
    byte VECN2       :1;                                       /* Vector number, bit 2 */
    byte VECN3       :1;                                       /* Vector number, bit 3 */
    byte VECN4       :1;                                       /* Vector number, bit 4 */
    byte VECN5       :1;                                       /* Vector number, bit 5 */
    byte VECN6       :1;                                       /* Vector number, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpVECN :7;
    byte         :1;
  } MergedBits;
} INTC_LVL5IACKSTR;
#define _INTC_LVL5IACK (*(volatile INTC_LVL5IACKSTR *)0xFFFFFFF4)
#define INTC_LVL5IACK                   _INTC_LVL5IACK.Byte
#define INTC_LVL5IACK_VECN0             _INTC_LVL5IACK.Bits.VECN0
#define INTC_LVL5IACK_VECN1             _INTC_LVL5IACK.Bits.VECN1
#define INTC_LVL5IACK_VECN2             _INTC_LVL5IACK.Bits.VECN2
#define INTC_LVL5IACK_VECN3             _INTC_LVL5IACK.Bits.VECN3
#define INTC_LVL5IACK_VECN4             _INTC_LVL5IACK.Bits.VECN4
#define INTC_LVL5IACK_VECN5             _INTC_LVL5IACK.Bits.VECN5
#define INTC_LVL5IACK_VECN6             _INTC_LVL5IACK.Bits.VECN6
#define INTC_LVL5IACK_VECN              _INTC_LVL5IACK.MergedBits.grpVECN

#define INTC_LVL5IACK_VECN0_MASK        1U
#define INTC_LVL5IACK_VECN1_MASK        2U
#define INTC_LVL5IACK_VECN2_MASK        4U
#define INTC_LVL5IACK_VECN3_MASK        8U
#define INTC_LVL5IACK_VECN4_MASK        16U
#define INTC_LVL5IACK_VECN5_MASK        32U
#define INTC_LVL5IACK_VECN6_MASK        64U
#define INTC_LVL5IACK_VECN_MASK         127U
#define INTC_LVL5IACK_VECN_BITNUM       0U


/*** INTC_LVL6IACK - INTC Level 6 IACK Register; 0xFFFFFFF8 ***/
typedef union {
  byte Byte;
  struct {
    byte VECN0       :1;                                       /* Vector number, bit 0 */
    byte VECN1       :1;                                       /* Vector number, bit 1 */
    byte VECN2       :1;                                       /* Vector number, bit 2 */
    byte VECN3       :1;                                       /* Vector number, bit 3 */
    byte VECN4       :1;                                       /* Vector number, bit 4 */
    byte VECN5       :1;                                       /* Vector number, bit 5 */
    byte VECN6       :1;                                       /* Vector number, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpVECN :7;
    byte         :1;
  } MergedBits;
} INTC_LVL6IACKSTR;
#define _INTC_LVL6IACK (*(volatile INTC_LVL6IACKSTR *)0xFFFFFFF8)
#define INTC_LVL6IACK                   _INTC_LVL6IACK.Byte
#define INTC_LVL6IACK_VECN0             _INTC_LVL6IACK.Bits.VECN0
#define INTC_LVL6IACK_VECN1             _INTC_LVL6IACK.Bits.VECN1
#define INTC_LVL6IACK_VECN2             _INTC_LVL6IACK.Bits.VECN2
#define INTC_LVL6IACK_VECN3             _INTC_LVL6IACK.Bits.VECN3
#define INTC_LVL6IACK_VECN4             _INTC_LVL6IACK.Bits.VECN4
#define INTC_LVL6IACK_VECN5             _INTC_LVL6IACK.Bits.VECN5
#define INTC_LVL6IACK_VECN6             _INTC_LVL6IACK.Bits.VECN6
#define INTC_LVL6IACK_VECN              _INTC_LVL6IACK.MergedBits.grpVECN

#define INTC_LVL6IACK_VECN0_MASK        1U
#define INTC_LVL6IACK_VECN1_MASK        2U
#define INTC_LVL6IACK_VECN2_MASK        4U
#define INTC_LVL6IACK_VECN3_MASK        8U
#define INTC_LVL6IACK_VECN4_MASK        16U
#define INTC_LVL6IACK_VECN5_MASK        32U
#define INTC_LVL6IACK_VECN6_MASK        64U
#define INTC_LVL6IACK_VECN_MASK         127U
#define INTC_LVL6IACK_VECN_BITNUM       0U


/*** INTC_LVL7IACK - INTC Level 7 IACK Register; 0xFFFFFFFC ***/
typedef union {
  byte Byte;
  struct {
    byte VECN0       :1;                                       /* Vector number, bit 0 */
    byte VECN1       :1;                                       /* Vector number, bit 1 */
    byte VECN2       :1;                                       /* Vector number, bit 2 */
    byte VECN3       :1;                                       /* Vector number, bit 3 */
    byte VECN4       :1;                                       /* Vector number, bit 4 */
    byte VECN5       :1;                                       /* Vector number, bit 5 */
    byte VECN6       :1;                                       /* Vector number, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpVECN :7;
    byte         :1;
  } MergedBits;
} INTC_LVL7IACKSTR;
#define _INTC_LVL7IACK (*(volatile INTC_LVL7IACKSTR *)0xFFFFFFFC)
#define INTC_LVL7IACK                   _INTC_LVL7IACK.Byte
#define INTC_LVL7IACK_VECN0             _INTC_LVL7IACK.Bits.VECN0
#define INTC_LVL7IACK_VECN1             _INTC_LVL7IACK.Bits.VECN1
#define INTC_LVL7IACK_VECN2             _INTC_LVL7IACK.Bits.VECN2
#define INTC_LVL7IACK_VECN3             _INTC_LVL7IACK.Bits.VECN3
#define INTC_LVL7IACK_VECN4             _INTC_LVL7IACK.Bits.VECN4
#define INTC_LVL7IACK_VECN5             _INTC_LVL7IACK.Bits.VECN5
#define INTC_LVL7IACK_VECN6             _INTC_LVL7IACK.Bits.VECN6
#define INTC_LVL7IACK_VECN              _INTC_LVL7IACK.MergedBits.grpVECN

#define INTC_LVL7IACK_VECN0_MASK        1U
#define INTC_LVL7IACK_VECN1_MASK        2U
#define INTC_LVL7IACK_VECN2_MASK        4U
#define INTC_LVL7IACK_VECN3_MASK        8U
#define INTC_LVL7IACK_VECN4_MASK        16U
#define INTC_LVL7IACK_VECN5_MASK        32U
#define INTC_LVL7IACK_VECN6_MASK        64U
#define INTC_LVL7IACK_VECN_MASK         127U
#define INTC_LVL7IACK_VECN_BITNUM       0U



/* Flash commands */
#define mBlank                          0x05
#define mBurstProg                      0x25
#define mByteProg                       0x20
#define mMassErase                      0x41
#define mPageErase                      0x40

#pragma pack(pop)

#endif
/*lint -restore Enable MISRA rule (5.1) checking. */
/*lint -restore  +esym(961,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */
