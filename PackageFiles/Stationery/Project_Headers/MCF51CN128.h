/* Based on CPU DB MCF51CN128_80, version 3.00.031 (RegistersPrg V2.32) */
/*
** ###################################################################
**     Filename  : mcf51cn128.h
**     Processor : MCF51CN128CLK
**     FileFormat: V2.32
**     DataSheet : MCF51CN128RM Rev. 4 January 2009
**     Compiler  : CodeWarrior compiler
**     Date/Time : 5.10.2010, 14:37
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**      - 26.02.2009, V3.00.0:
**              - Updated width and address of INTC_ORMR register: 8-bit -> 16-bit, 0xFFFF_FFCD -> 0xFFFF_FFCC.
**              -   REASON: RM update(from Rev. 2, 8/2008 to Rev.4, January 2009).
**
**     File-Format-Revisions:
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

#ifndef _MCF51CN128_H
#define _MCF51CN128_H

/*lint -save  -e950 -esym(960,18.4) -e46 -esym(961,19.7) Disable MISRA rule (1.1,18.4,6.4,19.7) checking. */
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
  #pragma pack(1)
#elif defined(__GNUC__)
   #pragma pack(push,1)
#else
  #error Not supported compiler type
#endif

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
#define VectorNumber_Vtpm1ch0           67U
#define VectorNumber_Vtpm1ch1           68U
#define VectorNumber_Vtpm1ch2           69U
#define VectorNumber_Vtpm1ovf           70U
#define VectorNumber_Vmtim1             71U
#define VectorNumber_Vtpm2ch0           72U
#define VectorNumber_Vtpm2ch1           73U
#define VectorNumber_Vtpm2ch2           74U
#define VectorNumber_Vtpm2ovf           75U
#define VectorNumber_Vspi1              76U
#define VectorNumber_Vspi2              77U
#define VectorNumber_Vmtim2             78U
#define VectorNumber_Vsci1err           79U
#define VectorNumber_Vsci1rx            80U
#define VectorNumber_Vsci1tx            81U
#define VectorNumber_Vsci2err           82U
#define VectorNumber_Vsci2rx            83U
#define VectorNumber_Vsci2tx            84U
#define VectorNumber_Vsci3or            85U
#define VectorNumber_Vfectxf            86U
#define VectorNumber_Vfecrxf            87U
#define VectorNumber_Vfecother          88U
#define VectorNumber_Vfechberr          89U
#define VectorNumber_Vfecbabr           90U
#define VectorNumber_Vfecbabt           91U
#define VectorNumber_Vfecgra            92U
#define VectorNumber_Vfectxb            93U
#define VectorNumber_Vfecrxb            94U
#define VectorNumber_Vfecmii            95U
#define VectorNumber_Vfeceberr          96U
#define VectorNumber_Vfeclc             97U
#define VectorNumber_Vfecrl             98U
#define VectorNumber_Vfecun             99U
#define VectorNumber_Vsci3err           100U
#define VectorNumber_Vsci3rx            101U
#define VectorNumber_Vsci3tx            102U
#define VectorNumber_VL7swi             103U
#define VectorNumber_VL6swi             104U
#define VectorNumber_VL5swi             105U
#define VectorNumber_VL4swi             106U
#define VectorNumber_VL3swi             107U
#define VectorNumber_VL2swi             108U
#define VectorNumber_VL1swi             109U
#define VectorNumber_Viic1              110U
#define VectorNumber_Viic2              111U
#define VectorNumber_Vadc               112U
#define VectorNumber_Vkeyboard          113U
#define VectorNumber_Vrtc               114U

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
#define Vtpm1ch0                        0x010CU
#define Vtpm1ch1                        0x0110U
#define Vtpm1ch2                        0x0114U
#define Vtpm1ovf                        0x0118U
#define Vmtim1                          0x011CU
#define Vtpm2ch0                        0x0120U
#define Vtpm2ch1                        0x0124U
#define Vtpm2ch2                        0x0128U
#define Vtpm2ovf                        0x012CU
#define Vspi1                           0x0130U
#define Vspi2                           0x0134U
#define Vmtim2                          0x0138U
#define Vsci1err                        0x013CU
#define Vsci1rx                         0x0140U
#define Vsci1tx                         0x0144U
#define Vsci2err                        0x0148U
#define Vsci2rx                         0x014CU
#define Vsci2tx                         0x0150U
#define Vsci3or                         0x0154U
#define Vfectxf                         0x0158U
#define Vfecrxf                         0x015CU
#define Vfecother                       0x0160U
#define Vfechberr                       0x0164U
#define Vfecbabr                        0x0168U
#define Vfecbabt                        0x016CU
#define Vfecgra                         0x0170U
#define Vfectxb                         0x0174U
#define Vfecrxb                         0x0178U
#define Vfecmii                         0x017CU
#define Vfeceberr                       0x0180U
#define Vfeclc                          0x0184U
#define Vfecrl                          0x0188U
#define Vfecun                          0x018CU
#define Vsci3err                        0x0190U
#define Vsci3rx                         0x0194U
#define Vsci3tx                         0x0198U
#define VL7swi                          0x019CU
#define VL6swi                          0x01A0U
#define VL5swi                          0x01A4U
#define VL4swi                          0x01A8U
#define VL3swi                          0x01ACU
#define VL2swi                          0x01B0U
#define VL1swi                          0x01B4U
#define Viic1                           0x01B8U
#define Viic2                           0x01BCU
#define Vadc                            0x01C0U
#define Vkeyboard                       0x01C4U
#define Vrtc                            0x01C8U

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


/*** PTAPE - Port A Pull Enable Register; 0xFFFF8008 ***/
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
#define _PTAPE (*(volatile PTAPESTR *)0xFFFF8008)
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


/*** PTASE - Port A Slew Rate Enable Register; 0xFFFF8009 ***/
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
#define _PTASE (*(volatile PTASESTR *)0xFFFF8009)
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


/*** PTADS - Port A Drive Strength Selection Register; 0xFFFF800A ***/
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
#define _PTADS (*(volatile PTADSSTR *)0xFFFF800A)
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


/*** PTAIFE - Port A Input Filter Enable Register; 0xFFFF800B ***/
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
#define _PTAIFE (*(volatile PTAIFESTR *)0xFFFF800B)
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


/*** PTBD - Port B Data Register; 0xFFFF8010 ***/
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
#define _PTBD (*(volatile PTBDSTR *)0xFFFF8010)
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


/*** PTBDD - Port B Data Direction Register; 0xFFFF8011 ***/
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
#define _PTBDD (*(volatile PTBDDSTR *)0xFFFF8011)
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


/*** PTBPE - Port B Pull Enable Register; 0xFFFF8018 ***/
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
#define _PTBPE (*(volatile PTBPESTR *)0xFFFF8018)
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


/*** PTBSE - Port B Slew Rate Enable Register; 0xFFFF8019 ***/
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
#define _PTBSE (*(volatile PTBSESTR *)0xFFFF8019)
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


/*** PTBDS - Port B Drive Strength Selection Register; 0xFFFF801A ***/
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
#define _PTBDS (*(volatile PTBDSSTR *)0xFFFF801A)
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


/*** PTBIFE - Port B Input Filter Enable Register; 0xFFFF801B ***/
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
#define _PTBIFE (*(volatile PTBIFESTR *)0xFFFF801B)
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


/*** PTCD - Port C Data Register; 0xFFFF8020 ***/
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
#define _PTCD (*(volatile PTCDSTR *)0xFFFF8020)
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


/*** PTCDD - Port C Data Direction Register; 0xFFFF8021 ***/
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
#define _PTCDD (*(volatile PTCDDSTR *)0xFFFF8021)
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


/*** PTCPE - Port C Pull Enable Register; 0xFFFF8028 ***/
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
#define _PTCPE (*(volatile PTCPESTR *)0xFFFF8028)
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


/*** PTCSE - Port C Slew Rate Enable Register; 0xFFFF8029 ***/
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
#define _PTCSE (*(volatile PTCSESTR *)0xFFFF8029)
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


/*** PTCDS - Port C Drive Strength Selection Register; 0xFFFF802A ***/
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
#define _PTCDS (*(volatile PTCDSSTR *)0xFFFF802A)
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


/*** PTCIFE - Port C Input Filter Enable Register; 0xFFFF802B ***/
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
#define _PTCIFE (*(volatile PTCIFESTR *)0xFFFF802B)
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


/*** PTDD - Port D Data Register; 0xFFFF8030 ***/
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
#define _PTDD (*(volatile PTDDSTR *)0xFFFF8030)
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


/*** PTDDD - Port D Data Direction Register; 0xFFFF8031 ***/
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
#define _PTDDD (*(volatile PTDDDSTR *)0xFFFF8031)
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


/*** PTDPE - Port D Pull Enable Register; 0xFFFF8038 ***/
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
#define _PTDPE (*(volatile PTDPESTR *)0xFFFF8038)
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


/*** PTDSE - Port D Slew Rate Enable Register; 0xFFFF8039 ***/
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
#define _PTDSE (*(volatile PTDSESTR *)0xFFFF8039)
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


/*** PTDDS - Port D Drive Strength Selection Register; 0xFFFF803A ***/
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
#define _PTDDS (*(volatile PTDDSSTR *)0xFFFF803A)
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


/*** PTDIFE - Port D Input Filter Enable Register; 0xFFFF803B ***/
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
#define _PTDIFE (*(volatile PTDIFESTR *)0xFFFF803B)
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


/*** PTED - Port E Data Register; 0xFFFF8040 ***/
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
#define _PTED (*(volatile PTEDSTR *)0xFFFF8040)
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


/*** PTEDD - Port E Data Direction Register; 0xFFFF8041 ***/
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
#define _PTEDD (*(volatile PTEDDSTR *)0xFFFF8041)
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


/*** PTEPE - Port E Pull Enable Register; 0xFFFF8048 ***/
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
#define _PTEPE (*(volatile PTEPESTR *)0xFFFF8048)
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


/*** PTESE - Port E Slew Rate Enable Register; 0xFFFF8049 ***/
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
#define _PTESE (*(volatile PTESESTR *)0xFFFF8049)
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


/*** PTEDS - Port E Drive Strength Selection Register; 0xFFFF804A ***/
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
#define _PTEDS (*(volatile PTEDSSTR *)0xFFFF804A)
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


/*** PTEIFE - Port E Input Filter Enable Register; 0xFFFF804B ***/
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
#define _PTEIFE (*(volatile PTEIFESTR *)0xFFFF804B)
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


/*** KBI2SC - KBI2 Status and Control Register; 0xFFFF804C ***/
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
} KBI2SCSTR;
#define _KBI2SC (*(volatile KBI2SCSTR *)0xFFFF804C)
#define KBI2SC                          _KBI2SC.Byte
#define KBI2SC_KBIMOD                   _KBI2SC.Bits.KBIMOD
#define KBI2SC_KBIE                     _KBI2SC.Bits.KBIE
#define KBI2SC_KBACK                    _KBI2SC.Bits.KBACK
#define KBI2SC_KBF                      _KBI2SC.Bits.KBF

#define KBI2SC_KBIMOD_MASK              1U
#define KBI2SC_KBIE_MASK                2U
#define KBI2SC_KBACK_MASK               4U
#define KBI2SC_KBF_MASK                 8U


/*** KBI2PE - KBI2 Pin Enable Register; 0xFFFF804D ***/
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
} KBI2PESTR;
#define _KBI2PE (*(volatile KBI2PESTR *)0xFFFF804D)
#define KBI2PE                          _KBI2PE.Byte
#define KBI2PE_KBIPE0                   _KBI2PE.Bits.KBIPE0
#define KBI2PE_KBIPE1                   _KBI2PE.Bits.KBIPE1
#define KBI2PE_KBIPE2                   _KBI2PE.Bits.KBIPE2
#define KBI2PE_KBIPE3                   _KBI2PE.Bits.KBIPE3
#define KBI2PE_KBIPE4                   _KBI2PE.Bits.KBIPE4
#define KBI2PE_KBIPE5                   _KBI2PE.Bits.KBIPE5
#define KBI2PE_KBIPE6                   _KBI2PE.Bits.KBIPE6
#define KBI2PE_KBIPE7                   _KBI2PE.Bits.KBIPE7

#define KBI2PE_KBIPE0_MASK              1U
#define KBI2PE_KBIPE1_MASK              2U
#define KBI2PE_KBIPE2_MASK              4U
#define KBI2PE_KBIPE3_MASK              8U
#define KBI2PE_KBIPE4_MASK              16U
#define KBI2PE_KBIPE5_MASK              32U
#define KBI2PE_KBIPE6_MASK              64U
#define KBI2PE_KBIPE7_MASK              128U


/*** KBI2ES - KBI2 Edge Select Register; 0xFFFF804E ***/
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
} KBI2ESSTR;
#define _KBI2ES (*(volatile KBI2ESSTR *)0xFFFF804E)
#define KBI2ES                          _KBI2ES.Byte
#define KBI2ES_KBEDG0                   _KBI2ES.Bits.KBEDG0
#define KBI2ES_KBEDG1                   _KBI2ES.Bits.KBEDG1
#define KBI2ES_KBEDG2                   _KBI2ES.Bits.KBEDG2
#define KBI2ES_KBEDG3                   _KBI2ES.Bits.KBEDG3
#define KBI2ES_KBEDG4                   _KBI2ES.Bits.KBEDG4
#define KBI2ES_KBEDG5                   _KBI2ES.Bits.KBEDG5
#define KBI2ES_KBEDG6                   _KBI2ES.Bits.KBEDG6
#define KBI2ES_KBEDG7                   _KBI2ES.Bits.KBEDG7

#define KBI2ES_KBEDG0_MASK              1U
#define KBI2ES_KBEDG1_MASK              2U
#define KBI2ES_KBEDG2_MASK              4U
#define KBI2ES_KBEDG3_MASK              8U
#define KBI2ES_KBEDG4_MASK              16U
#define KBI2ES_KBEDG5_MASK              32U
#define KBI2ES_KBEDG6_MASK              64U
#define KBI2ES_KBEDG7_MASK              128U


/*** PTFD - Port F Data Register; 0xFFFF8050 ***/
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
#define _PTFD (*(volatile PTFDSTR *)0xFFFF8050)
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


/*** PTFDD - Port F Data Direction Register; 0xFFFF8051 ***/
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
#define _PTFDD (*(volatile PTFDDSTR *)0xFFFF8051)
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


/*** PTFPE - Port F Pull Enable Register; 0xFFFF8058 ***/
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
#define _PTFPE (*(volatile PTFPESTR *)0xFFFF8058)
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


/*** PTFSE - Port F Slew Rate Enable Register; 0xFFFF8059 ***/
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
#define _PTFSE (*(volatile PTFSESTR *)0xFFFF8059)
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


/*** PTFDS - Port F Drive Strength Selection Register; 0xFFFF805A ***/
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
#define _PTFDS (*(volatile PTFDSSTR *)0xFFFF805A)
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


/*** PTFIFE - Port F Input Filter Enable Register; 0xFFFF805B ***/
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
#define _PTFIFE (*(volatile PTFIFESTR *)0xFFFF805B)
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


/*** PTGD - Port G Data Register; 0xFFFF8060 ***/
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
#define _PTGD (*(volatile PTGDSTR *)0xFFFF8060)
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


/*** PTGDD - Port G Data Direction Register; 0xFFFF8061 ***/
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
#define _PTGDD (*(volatile PTGDDSTR *)0xFFFF8061)
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


/*** PTGPE - Port G Pull Enable Register; 0xFFFF8068 ***/
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
#define _PTGPE (*(volatile PTGPESTR *)0xFFFF8068)
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


/*** PTGSE - Port G Slew Rate Enable Register; 0xFFFF8069 ***/
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
#define _PTGSE (*(volatile PTGSESTR *)0xFFFF8069)
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


/*** PTGDS - Port G Drive Strength Selection Register; 0xFFFF806A ***/
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
#define _PTGDS (*(volatile PTGDSSTR *)0xFFFF806A)
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


/*** PTGIFE - Port G Input Filter Enable Register; 0xFFFF806B ***/
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
#define _PTGIFE (*(volatile PTGIFESTR *)0xFFFF806B)
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


/*** KBI1SC - KBI1 Status and Control Register; 0xFFFF806C ***/
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
#define _KBI1SC (*(volatile KBI1SCSTR *)0xFFFF806C)
#define KBI1SC                          _KBI1SC.Byte
#define KBI1SC_KBIMOD                   _KBI1SC.Bits.KBIMOD
#define KBI1SC_KBIE                     _KBI1SC.Bits.KBIE
#define KBI1SC_KBACK                    _KBI1SC.Bits.KBACK
#define KBI1SC_KBF                      _KBI1SC.Bits.KBF

#define KBI1SC_KBIMOD_MASK              1U
#define KBI1SC_KBIE_MASK                2U
#define KBI1SC_KBACK_MASK               4U
#define KBI1SC_KBF_MASK                 8U


/*** KBI1PE - KBI1 Pin Enable Register; 0xFFFF806D ***/
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
#define _KBI1PE (*(volatile KBI1PESTR *)0xFFFF806D)
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


/*** KBI1ES - KBI1 Edge Select Register; 0xFFFF806E ***/
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
#define _KBI1ES (*(volatile KBI1ESSTR *)0xFFFF806E)
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


/*** PTHD - Port H Data Register; 0xFFFF8070 ***/
typedef union {
  byte Byte;
  struct {
    byte PTHD0       :1;                                       /* Port H Data Register Bit 0 */
    byte PTHD1       :1;                                       /* Port H Data Register Bit 1 */
    byte PTHD2       :1;                                       /* Port H Data Register Bit 2 */
    byte PTHD3       :1;                                       /* Port H Data Register Bit 3 */
    byte PTHD4       :1;                                       /* Port H Data Register Bit 4 */
    byte PTHD5       :1;                                       /* Port H Data Register Bit 5 */
    byte PTHD6       :1;                                       /* Port H Data Register Bit 6 */
    byte PTHD7       :1;                                       /* Port H Data Register Bit 7 */
  } Bits;
} PTHDSTR;
#define _PTHD (*(volatile PTHDSTR *)0xFFFF8070)
#define PTHD                            _PTHD.Byte
#define PTHD_PTHD0                      _PTHD.Bits.PTHD0
#define PTHD_PTHD1                      _PTHD.Bits.PTHD1
#define PTHD_PTHD2                      _PTHD.Bits.PTHD2
#define PTHD_PTHD3                      _PTHD.Bits.PTHD3
#define PTHD_PTHD4                      _PTHD.Bits.PTHD4
#define PTHD_PTHD5                      _PTHD.Bits.PTHD5
#define PTHD_PTHD6                      _PTHD.Bits.PTHD6
#define PTHD_PTHD7                      _PTHD.Bits.PTHD7

#define PTHD_PTHD0_MASK                 1U
#define PTHD_PTHD1_MASK                 2U
#define PTHD_PTHD2_MASK                 4U
#define PTHD_PTHD3_MASK                 8U
#define PTHD_PTHD4_MASK                 16U
#define PTHD_PTHD5_MASK                 32U
#define PTHD_PTHD6_MASK                 64U
#define PTHD_PTHD7_MASK                 128U


/*** PTHDD - Port H Data Direction Register; 0xFFFF8071 ***/
typedef union {
  byte Byte;
  struct {
    byte PTHDD0      :1;                                       /* Data Direction for Port H Bit 0 */
    byte PTHDD1      :1;                                       /* Data Direction for Port H Bit 1 */
    byte PTHDD2      :1;                                       /* Data Direction for Port H Bit 2 */
    byte PTHDD3      :1;                                       /* Data Direction for Port H Bit 3 */
    byte PTHDD4      :1;                                       /* Data Direction for Port H Bit 4 */
    byte PTHDD5      :1;                                       /* Data Direction for Port H Bit 5 */
    byte PTHDD6      :1;                                       /* Data Direction for Port H Bit 6 */
    byte PTHDD7      :1;                                       /* Data Direction for Port H Bit 7 */
  } Bits;
} PTHDDSTR;
#define _PTHDD (*(volatile PTHDDSTR *)0xFFFF8071)
#define PTHDD                           _PTHDD.Byte
#define PTHDD_PTHDD0                    _PTHDD.Bits.PTHDD0
#define PTHDD_PTHDD1                    _PTHDD.Bits.PTHDD1
#define PTHDD_PTHDD2                    _PTHDD.Bits.PTHDD2
#define PTHDD_PTHDD3                    _PTHDD.Bits.PTHDD3
#define PTHDD_PTHDD4                    _PTHDD.Bits.PTHDD4
#define PTHDD_PTHDD5                    _PTHDD.Bits.PTHDD5
#define PTHDD_PTHDD6                    _PTHDD.Bits.PTHDD6
#define PTHDD_PTHDD7                    _PTHDD.Bits.PTHDD7

#define PTHDD_PTHDD0_MASK               1U
#define PTHDD_PTHDD1_MASK               2U
#define PTHDD_PTHDD2_MASK               4U
#define PTHDD_PTHDD3_MASK               8U
#define PTHDD_PTHDD4_MASK               16U
#define PTHDD_PTHDD5_MASK               32U
#define PTHDD_PTHDD6_MASK               64U
#define PTHDD_PTHDD7_MASK               128U


/*** PTHPE - Port H Pull Enable Register; 0xFFFF8078 ***/
typedef union {
  byte Byte;
  struct {
    byte PTHPE0      :1;                                       /* Internal Pull Enable for Port H Bit 0 */
    byte PTHPE1      :1;                                       /* Internal Pull Enable for Port H Bit 1 */
    byte PTHPE2      :1;                                       /* Internal Pull Enable for Port H Bit 2 */
    byte PTHPE3      :1;                                       /* Internal Pull Enable for Port H Bit 3 */
    byte PTHPE4      :1;                                       /* Internal Pull Enable for Port H Bit 4 */
    byte PTHPE5      :1;                                       /* Internal Pull Enable for Port H Bit 5 */
    byte PTHPE6      :1;                                       /* Internal Pull Enable for Port H Bit 6 */
    byte PTHPE7      :1;                                       /* Internal Pull Enable for Port H Bit 7 */
  } Bits;
} PTHPESTR;
#define _PTHPE (*(volatile PTHPESTR *)0xFFFF8078)
#define PTHPE                           _PTHPE.Byte
#define PTHPE_PTHPE0                    _PTHPE.Bits.PTHPE0
#define PTHPE_PTHPE1                    _PTHPE.Bits.PTHPE1
#define PTHPE_PTHPE2                    _PTHPE.Bits.PTHPE2
#define PTHPE_PTHPE3                    _PTHPE.Bits.PTHPE3
#define PTHPE_PTHPE4                    _PTHPE.Bits.PTHPE4
#define PTHPE_PTHPE5                    _PTHPE.Bits.PTHPE5
#define PTHPE_PTHPE6                    _PTHPE.Bits.PTHPE6
#define PTHPE_PTHPE7                    _PTHPE.Bits.PTHPE7

#define PTHPE_PTHPE0_MASK               1U
#define PTHPE_PTHPE1_MASK               2U
#define PTHPE_PTHPE2_MASK               4U
#define PTHPE_PTHPE3_MASK               8U
#define PTHPE_PTHPE4_MASK               16U
#define PTHPE_PTHPE5_MASK               32U
#define PTHPE_PTHPE6_MASK               64U
#define PTHPE_PTHPE7_MASK               128U


/*** PTHSE - Port H Slew Rate Enable Register; 0xFFFF8079 ***/
typedef union {
  byte Byte;
  struct {
    byte PTHSE0      :1;                                       /* Output Slew Rate Enable for Port H Bit 0 */
    byte PTHSE1      :1;                                       /* Output Slew Rate Enable for Port H Bit 1 */
    byte PTHSE2      :1;                                       /* Output Slew Rate Enable for Port H Bit 2 */
    byte PTHSE3      :1;                                       /* Output Slew Rate Enable for Port H Bit 3 */
    byte PTHSE4      :1;                                       /* Output Slew Rate Enable for Port H Bit 4 */
    byte PTHSE5      :1;                                       /* Output Slew Rate Enable for Port H Bit 5 */
    byte PTHSE6      :1;                                       /* Output Slew Rate Enable for Port H Bit 6 */
    byte PTHSE7      :1;                                       /* Output Slew Rate Enable for Port H Bit 7 */
  } Bits;
} PTHSESTR;
#define _PTHSE (*(volatile PTHSESTR *)0xFFFF8079)
#define PTHSE                           _PTHSE.Byte
#define PTHSE_PTHSE0                    _PTHSE.Bits.PTHSE0
#define PTHSE_PTHSE1                    _PTHSE.Bits.PTHSE1
#define PTHSE_PTHSE2                    _PTHSE.Bits.PTHSE2
#define PTHSE_PTHSE3                    _PTHSE.Bits.PTHSE3
#define PTHSE_PTHSE4                    _PTHSE.Bits.PTHSE4
#define PTHSE_PTHSE5                    _PTHSE.Bits.PTHSE5
#define PTHSE_PTHSE6                    _PTHSE.Bits.PTHSE6
#define PTHSE_PTHSE7                    _PTHSE.Bits.PTHSE7

#define PTHSE_PTHSE0_MASK               1U
#define PTHSE_PTHSE1_MASK               2U
#define PTHSE_PTHSE2_MASK               4U
#define PTHSE_PTHSE3_MASK               8U
#define PTHSE_PTHSE4_MASK               16U
#define PTHSE_PTHSE5_MASK               32U
#define PTHSE_PTHSE6_MASK               64U
#define PTHSE_PTHSE7_MASK               128U


/*** PTHDS - Port H Drive Strength Selection Register; 0xFFFF807A ***/
typedef union {
  byte Byte;
  struct {
    byte PTHDS0      :1;                                       /* Output Drive Strength Selection for Port H Bit 0 */
    byte PTHDS1      :1;                                       /* Output Drive Strength Selection for Port H Bit 1 */
    byte PTHDS2      :1;                                       /* Output Drive Strength Selection for Port H Bit 2 */
    byte PTHDS3      :1;                                       /* Output Drive Strength Selection for Port H Bit 3 */
    byte PTHDS4      :1;                                       /* Output Drive Strength Selection for Port H Bit 4 */
    byte PTHDS5      :1;                                       /* Output Drive Strength Selection for Port H Bit 5 */
    byte PTHDS6      :1;                                       /* Output Drive Strength Selection for Port H Bit 6 */
    byte PTHDS7      :1;                                       /* Output Drive Strength Selection for Port H Bit 7 */
  } Bits;
} PTHDSSTR;
#define _PTHDS (*(volatile PTHDSSTR *)0xFFFF807A)
#define PTHDS                           _PTHDS.Byte
#define PTHDS_PTHDS0                    _PTHDS.Bits.PTHDS0
#define PTHDS_PTHDS1                    _PTHDS.Bits.PTHDS1
#define PTHDS_PTHDS2                    _PTHDS.Bits.PTHDS2
#define PTHDS_PTHDS3                    _PTHDS.Bits.PTHDS3
#define PTHDS_PTHDS4                    _PTHDS.Bits.PTHDS4
#define PTHDS_PTHDS5                    _PTHDS.Bits.PTHDS5
#define PTHDS_PTHDS6                    _PTHDS.Bits.PTHDS6
#define PTHDS_PTHDS7                    _PTHDS.Bits.PTHDS7

#define PTHDS_PTHDS0_MASK               1U
#define PTHDS_PTHDS1_MASK               2U
#define PTHDS_PTHDS2_MASK               4U
#define PTHDS_PTHDS3_MASK               8U
#define PTHDS_PTHDS4_MASK               16U
#define PTHDS_PTHDS5_MASK               32U
#define PTHDS_PTHDS6_MASK               64U
#define PTHDS_PTHDS7_MASK               128U


/*** PTHIFE - Port H Input Filter Enable Register; 0xFFFF807B ***/
typedef union {
  byte Byte;
  struct {
    byte PTHIFE0     :1;                                       /* Port H Input Filter Enable Bit 0 */
    byte PTHIFE1     :1;                                       /* Port H Input Filter Enable Bit 1 */
    byte PTHIFE2     :1;                                       /* Port H Input Filter Enable Bit 2 */
    byte PTHIFE3     :1;                                       /* Port H Input Filter Enable Bit 3 */
    byte PTHIFE4     :1;                                       /* Port H Input Filter Enable Bit 4 */
    byte PTHIFE5     :1;                                       /* Port H Input Filter Enable Bit 5 */
    byte PTHIFE6     :1;                                       /* Port H Input Filter Enable Bit 6 */
    byte PTHIFE7     :1;                                       /* Port H Input Filter Enable Bit 7 */
  } Bits;
} PTHIFESTR;
#define _PTHIFE (*(volatile PTHIFESTR *)0xFFFF807B)
#define PTHIFE                          _PTHIFE.Byte
#define PTHIFE_PTHIFE0                  _PTHIFE.Bits.PTHIFE0
#define PTHIFE_PTHIFE1                  _PTHIFE.Bits.PTHIFE1
#define PTHIFE_PTHIFE2                  _PTHIFE.Bits.PTHIFE2
#define PTHIFE_PTHIFE3                  _PTHIFE.Bits.PTHIFE3
#define PTHIFE_PTHIFE4                  _PTHIFE.Bits.PTHIFE4
#define PTHIFE_PTHIFE5                  _PTHIFE.Bits.PTHIFE5
#define PTHIFE_PTHIFE6                  _PTHIFE.Bits.PTHIFE6
#define PTHIFE_PTHIFE7                  _PTHIFE.Bits.PTHIFE7

#define PTHIFE_PTHIFE0_MASK             1U
#define PTHIFE_PTHIFE1_MASK             2U
#define PTHIFE_PTHIFE2_MASK             4U
#define PTHIFE_PTHIFE3_MASK             8U
#define PTHIFE_PTHIFE4_MASK             16U
#define PTHIFE_PTHIFE5_MASK             32U
#define PTHIFE_PTHIFE6_MASK             64U
#define PTHIFE_PTHIFE7_MASK             128U


/*** PTJD - Port J Data Register; 0xFFFF8080 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJD0       :1;                                       /* Port J Data Register Bit 0 */
    byte PTJD1       :1;                                       /* Port J Data Register Bit 1 */
    byte PTJD2       :1;                                       /* Port J Data Register Bit 2 */
    byte PTJD3       :1;                                       /* Port J Data Register Bit 3 */
    byte PTJD4       :1;                                       /* Port J Data Register Bit 4 */
    byte PTJD5       :1;                                       /* Port J Data Register Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTJD :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTJDSTR;
#define _PTJD (*(volatile PTJDSTR *)0xFFFF8080)
#define PTJD                            _PTJD.Byte
#define PTJD_PTJD0                      _PTJD.Bits.PTJD0
#define PTJD_PTJD1                      _PTJD.Bits.PTJD1
#define PTJD_PTJD2                      _PTJD.Bits.PTJD2
#define PTJD_PTJD3                      _PTJD.Bits.PTJD3
#define PTJD_PTJD4                      _PTJD.Bits.PTJD4
#define PTJD_PTJD5                      _PTJD.Bits.PTJD5
#define PTJD_PTJD                       _PTJD.MergedBits.grpPTJD

#define PTJD_PTJD0_MASK                 1U
#define PTJD_PTJD1_MASK                 2U
#define PTJD_PTJD2_MASK                 4U
#define PTJD_PTJD3_MASK                 8U
#define PTJD_PTJD4_MASK                 16U
#define PTJD_PTJD5_MASK                 32U
#define PTJD_PTJD_MASK                  63U
#define PTJD_PTJD_BITNUM                0U


/*** PTJDD - Port J Data Direction Register; 0xFFFF8081 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJDD0      :1;                                       /* Data Direction for Port J Bit 0 */
    byte PTJDD1      :1;                                       /* Data Direction for Port J Bit 1 */
    byte PTJDD2      :1;                                       /* Data Direction for Port J Bit 2 */
    byte PTJDD3      :1;                                       /* Data Direction for Port J Bit 3 */
    byte PTJDD4      :1;                                       /* Data Direction for Port J Bit 4 */
    byte PTJDD5      :1;                                       /* Data Direction for Port J Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTJDD :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTJDDSTR;
#define _PTJDD (*(volatile PTJDDSTR *)0xFFFF8081)
#define PTJDD                           _PTJDD.Byte
#define PTJDD_PTJDD0                    _PTJDD.Bits.PTJDD0
#define PTJDD_PTJDD1                    _PTJDD.Bits.PTJDD1
#define PTJDD_PTJDD2                    _PTJDD.Bits.PTJDD2
#define PTJDD_PTJDD3                    _PTJDD.Bits.PTJDD3
#define PTJDD_PTJDD4                    _PTJDD.Bits.PTJDD4
#define PTJDD_PTJDD5                    _PTJDD.Bits.PTJDD5
#define PTJDD_PTJDD                     _PTJDD.MergedBits.grpPTJDD

#define PTJDD_PTJDD0_MASK               1U
#define PTJDD_PTJDD1_MASK               2U
#define PTJDD_PTJDD2_MASK               4U
#define PTJDD_PTJDD3_MASK               8U
#define PTJDD_PTJDD4_MASK               16U
#define PTJDD_PTJDD5_MASK               32U
#define PTJDD_PTJDD_MASK                63U
#define PTJDD_PTJDD_BITNUM              0U


/*** PTJPE - Port J Pull Enable Register; 0xFFFF8088 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJPE0      :1;                                       /* Internal Pull Enable for Port J Bit 0 */
    byte PTJPE1      :1;                                       /* Internal Pull Enable for Port J Bit 1 */
    byte PTJPE2      :1;                                       /* Internal Pull Enable for Port J Bit 2 */
    byte PTJPE3      :1;                                       /* Internal Pull Enable for Port J Bit 3 */
    byte PTJPE4      :1;                                       /* Internal Pull Enable for Port J Bit 4 */
    byte PTJPE5      :1;                                       /* Internal Pull Enable for Port J Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTJPE :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTJPESTR;
#define _PTJPE (*(volatile PTJPESTR *)0xFFFF8088)
#define PTJPE                           _PTJPE.Byte
#define PTJPE_PTJPE0                    _PTJPE.Bits.PTJPE0
#define PTJPE_PTJPE1                    _PTJPE.Bits.PTJPE1
#define PTJPE_PTJPE2                    _PTJPE.Bits.PTJPE2
#define PTJPE_PTJPE3                    _PTJPE.Bits.PTJPE3
#define PTJPE_PTJPE4                    _PTJPE.Bits.PTJPE4
#define PTJPE_PTJPE5                    _PTJPE.Bits.PTJPE5
#define PTJPE_PTJPE                     _PTJPE.MergedBits.grpPTJPE

#define PTJPE_PTJPE0_MASK               1U
#define PTJPE_PTJPE1_MASK               2U
#define PTJPE_PTJPE2_MASK               4U
#define PTJPE_PTJPE3_MASK               8U
#define PTJPE_PTJPE4_MASK               16U
#define PTJPE_PTJPE5_MASK               32U
#define PTJPE_PTJPE_MASK                63U
#define PTJPE_PTJPE_BITNUM              0U


/*** PTJSE - Port J Slew Rate Enable Register; 0xFFFF8089 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJSE0      :1;                                       /* Output Slew Rate Enable for Port J Bit 0 */
    byte PTJSE1      :1;                                       /* Output Slew Rate Enable for Port J Bit 1 */
    byte PTJSE2      :1;                                       /* Output Slew Rate Enable for Port J Bit 2 */
    byte PTJSE3      :1;                                       /* Output Slew Rate Enable for Port J Bit 3 */
    byte PTJSE4      :1;                                       /* Output Slew Rate Enable for Port J Bit 4 */
    byte PTJSE5      :1;                                       /* Output Slew Rate Enable for Port J Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTJSE :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTJSESTR;
#define _PTJSE (*(volatile PTJSESTR *)0xFFFF8089)
#define PTJSE                           _PTJSE.Byte
#define PTJSE_PTJSE0                    _PTJSE.Bits.PTJSE0
#define PTJSE_PTJSE1                    _PTJSE.Bits.PTJSE1
#define PTJSE_PTJSE2                    _PTJSE.Bits.PTJSE2
#define PTJSE_PTJSE3                    _PTJSE.Bits.PTJSE3
#define PTJSE_PTJSE4                    _PTJSE.Bits.PTJSE4
#define PTJSE_PTJSE5                    _PTJSE.Bits.PTJSE5
#define PTJSE_PTJSE                     _PTJSE.MergedBits.grpPTJSE

#define PTJSE_PTJSE0_MASK               1U
#define PTJSE_PTJSE1_MASK               2U
#define PTJSE_PTJSE2_MASK               4U
#define PTJSE_PTJSE3_MASK               8U
#define PTJSE_PTJSE4_MASK               16U
#define PTJSE_PTJSE5_MASK               32U
#define PTJSE_PTJSE_MASK                63U
#define PTJSE_PTJSE_BITNUM              0U


/*** PTJDS - Port J Drive Strength Selection Register; 0xFFFF808A ***/
typedef union {
  byte Byte;
  struct {
    byte PTJDS0      :1;                                       /* Output Drive Strength Selection for Port J Bit 0 */
    byte PTJDS1      :1;                                       /* Output Drive Strength Selection for Port J Bit 1 */
    byte PTJDS2      :1;                                       /* Output Drive Strength Selection for Port J Bit 2 */
    byte PTJDS3      :1;                                       /* Output Drive Strength Selection for Port J Bit 3 */
    byte PTJDS4      :1;                                       /* Output Drive Strength Selection for Port J Bit 4 */
    byte PTJDS5      :1;                                       /* Output Drive Strength Selection for Port J Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTJDS :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTJDSSTR;
#define _PTJDS (*(volatile PTJDSSTR *)0xFFFF808A)
#define PTJDS                           _PTJDS.Byte
#define PTJDS_PTJDS0                    _PTJDS.Bits.PTJDS0
#define PTJDS_PTJDS1                    _PTJDS.Bits.PTJDS1
#define PTJDS_PTJDS2                    _PTJDS.Bits.PTJDS2
#define PTJDS_PTJDS3                    _PTJDS.Bits.PTJDS3
#define PTJDS_PTJDS4                    _PTJDS.Bits.PTJDS4
#define PTJDS_PTJDS5                    _PTJDS.Bits.PTJDS5
#define PTJDS_PTJDS                     _PTJDS.MergedBits.grpPTJDS

#define PTJDS_PTJDS0_MASK               1U
#define PTJDS_PTJDS1_MASK               2U
#define PTJDS_PTJDS2_MASK               4U
#define PTJDS_PTJDS3_MASK               8U
#define PTJDS_PTJDS4_MASK               16U
#define PTJDS_PTJDS5_MASK               32U
#define PTJDS_PTJDS_MASK                63U
#define PTJDS_PTJDS_BITNUM              0U


/*** PTJIFE - Port J Input Filter Enable Register; 0xFFFF808B ***/
typedef union {
  byte Byte;
  struct {
    byte PTJIFE0     :1;                                       /* Port J Input Filter Enable Bit 0 */
    byte PTJIFE1     :1;                                       /* Port J Input Filter Enable Bit 1 */
    byte PTJIFE2     :1;                                       /* Port J Input Filter Enable Bit 2 */
    byte PTJIFE3     :1;                                       /* Port J Input Filter Enable Bit 3 */
    byte PTJIFE4     :1;                                       /* Port J Input Filter Enable Bit 4 */
    byte PTJIFE5     :1;                                       /* Port J Input Filter Enable Bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTJIFE :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTJIFESTR;
#define _PTJIFE (*(volatile PTJIFESTR *)0xFFFF808B)
#define PTJIFE                          _PTJIFE.Byte
#define PTJIFE_PTJIFE0                  _PTJIFE.Bits.PTJIFE0
#define PTJIFE_PTJIFE1                  _PTJIFE.Bits.PTJIFE1
#define PTJIFE_PTJIFE2                  _PTJIFE.Bits.PTJIFE2
#define PTJIFE_PTJIFE3                  _PTJIFE.Bits.PTJIFE3
#define PTJIFE_PTJIFE4                  _PTJIFE.Bits.PTJIFE4
#define PTJIFE_PTJIFE5                  _PTJIFE.Bits.PTJIFE5
#define PTJIFE_PTJIFE                   _PTJIFE.MergedBits.grpPTJIFE

#define PTJIFE_PTJIFE0_MASK             1U
#define PTJIFE_PTJIFE1_MASK             2U
#define PTJIFE_PTJIFE2_MASK             4U
#define PTJIFE_PTJIFE3_MASK             8U
#define PTJIFE_PTJIFE4_MASK             16U
#define PTJIFE_PTJIFE5_MASK             32U
#define PTJIFE_PTJIFE_MASK              63U
#define PTJIFE_PTJIFE_BITNUM            0U


/*** PTAPF1 - Port A Routing Register 1; 0xFFFF80C0 ***/
typedef union {
  byte Byte;
  struct {
    byte A40         :1;                                       /* Port PTA4 Pin Mux Controls, bit 0 */
    byte A41         :1;                                       /* Port PTA4 Pin Mux Controls, bit 1 */
    byte A50         :1;                                       /* Port PTA5 Pin Mux Controls, bit 0 */
    byte A51         :1;                                       /* Port PTA5 Pin Mux Controls, bit 1 */
    byte A60         :1;                                       /* Port PTA6 Pin Mux Controls, bit 0 */
    byte A61         :1;                                       /* Port PTA6 Pin Mux Controls, bit 1 */
    byte A70         :1;                                       /* Port PTA7 Pin Mux Controls, bit 0 */
    byte A71         :1;                                       /* Port PTA7 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpA4   :2;
    byte grpA5   :2;
    byte grpA6   :2;
    byte grpA7   :2;
  } MergedBits;
} PTAPF1STR;
#define _PTAPF1 (*(volatile PTAPF1STR *)0xFFFF80C0)
#define PTAPF1                          _PTAPF1.Byte
#define PTAPF1_A40                      _PTAPF1.Bits.A40
#define PTAPF1_A41                      _PTAPF1.Bits.A41
#define PTAPF1_A50                      _PTAPF1.Bits.A50
#define PTAPF1_A51                      _PTAPF1.Bits.A51
#define PTAPF1_A60                      _PTAPF1.Bits.A60
#define PTAPF1_A61                      _PTAPF1.Bits.A61
#define PTAPF1_A70                      _PTAPF1.Bits.A70
#define PTAPF1_A71                      _PTAPF1.Bits.A71
#define PTAPF1_A4                       _PTAPF1.MergedBits.grpA4
#define PTAPF1_A5                       _PTAPF1.MergedBits.grpA5
#define PTAPF1_A6                       _PTAPF1.MergedBits.grpA6
#define PTAPF1_A7                       _PTAPF1.MergedBits.grpA7

#define PTAPF1_A40_MASK                 1U
#define PTAPF1_A41_MASK                 2U
#define PTAPF1_A50_MASK                 4U
#define PTAPF1_A51_MASK                 8U
#define PTAPF1_A60_MASK                 16U
#define PTAPF1_A61_MASK                 32U
#define PTAPF1_A70_MASK                 64U
#define PTAPF1_A71_MASK                 128U
#define PTAPF1_A4_MASK                  3U
#define PTAPF1_A4_BITNUM                0U
#define PTAPF1_A5_MASK                  12U
#define PTAPF1_A5_BITNUM                2U
#define PTAPF1_A6_MASK                  48U
#define PTAPF1_A6_BITNUM                4U
#define PTAPF1_A7_MASK                  192U
#define PTAPF1_A7_BITNUM                6U


/*** PTAPF2 - Port A Routing Register 2; 0xFFFF80C1 ***/
typedef union {
  byte Byte;
  struct {
    byte A00         :1;                                       /* Port PTA0 Pin Mux Controls, bit 0 */
    byte A01         :1;                                       /* Port PTA0 Pin Mux Controls, bit 1 */
    byte A10         :1;                                       /* Port PTA1 Pin Mux Controls, bit 0 */
    byte A11         :1;                                       /* Port PTA1 Pin Mux Controls, bit 1 */
    byte A20         :1;                                       /* Port PTA2 Pin Mux Controls, bit 0 */
    byte A21         :1;                                       /* Port PTA2 Pin Mux Controls, bit 1 */
    byte A30         :1;                                       /* Port PTA3 Pin Mux Controls, bit 0 */
    byte A31         :1;                                       /* Port PTA3 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpA0   :2;
    byte grpA1   :2;
    byte grpA2   :2;
    byte grpA3   :2;
  } MergedBits;
} PTAPF2STR;
#define _PTAPF2 (*(volatile PTAPF2STR *)0xFFFF80C1)
#define PTAPF2                          _PTAPF2.Byte
#define PTAPF2_A00                      _PTAPF2.Bits.A00
#define PTAPF2_A01                      _PTAPF2.Bits.A01
#define PTAPF2_A10                      _PTAPF2.Bits.A10
#define PTAPF2_A11                      _PTAPF2.Bits.A11
#define PTAPF2_A20                      _PTAPF2.Bits.A20
#define PTAPF2_A21                      _PTAPF2.Bits.A21
#define PTAPF2_A30                      _PTAPF2.Bits.A30
#define PTAPF2_A31                      _PTAPF2.Bits.A31
#define PTAPF2_A0                       _PTAPF2.MergedBits.grpA0
#define PTAPF2_A1                       _PTAPF2.MergedBits.grpA1
#define PTAPF2_A2                       _PTAPF2.MergedBits.grpA2
#define PTAPF2_A3                       _PTAPF2.MergedBits.grpA3

#define PTAPF2_A00_MASK                 1U
#define PTAPF2_A01_MASK                 2U
#define PTAPF2_A10_MASK                 4U
#define PTAPF2_A11_MASK                 8U
#define PTAPF2_A20_MASK                 16U
#define PTAPF2_A21_MASK                 32U
#define PTAPF2_A30_MASK                 64U
#define PTAPF2_A31_MASK                 128U
#define PTAPF2_A0_MASK                  3U
#define PTAPF2_A0_BITNUM                0U
#define PTAPF2_A1_MASK                  12U
#define PTAPF2_A1_BITNUM                2U
#define PTAPF2_A2_MASK                  48U
#define PTAPF2_A2_BITNUM                4U
#define PTAPF2_A3_MASK                  192U
#define PTAPF2_A3_BITNUM                6U


/*** PTBPF1 - Port B Routing Register 1; 0xFFFF80C2 ***/
typedef union {
  byte Byte;
  struct {
    byte B40         :1;                                       /* Port PTB4 Pin Mux Controls, bit 0 */
    byte B41         :1;                                       /* Port PTB4 Pin Mux Controls, bit 1 */
    byte B50         :1;                                       /* Port PTB5 Pin Mux Controls, bit 0 */
    byte B51         :1;                                       /* Port PTB5 Pin Mux Controls, bit 1 */
    byte B60         :1;                                       /* Port PTB6 Pin Mux Controls, bit 0 */
    byte B61         :1;                                       /* Port PTB6 Pin Mux Controls, bit 1 */
    byte B70         :1;                                       /* Port PTB7 Pin Mux Controls, bit 0 */
    byte B71         :1;                                       /* Port PTB7 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpB4   :2;
    byte grpB5   :2;
    byte grpB6   :2;
    byte grpB7   :2;
  } MergedBits;
} PTBPF1STR;
#define _PTBPF1 (*(volatile PTBPF1STR *)0xFFFF80C2)
#define PTBPF1                          _PTBPF1.Byte
#define PTBPF1_B40                      _PTBPF1.Bits.B40
#define PTBPF1_B41                      _PTBPF1.Bits.B41
#define PTBPF1_B50                      _PTBPF1.Bits.B50
#define PTBPF1_B51                      _PTBPF1.Bits.B51
#define PTBPF1_B60                      _PTBPF1.Bits.B60
#define PTBPF1_B61                      _PTBPF1.Bits.B61
#define PTBPF1_B70                      _PTBPF1.Bits.B70
#define PTBPF1_B71                      _PTBPF1.Bits.B71
#define PTBPF1_B4                       _PTBPF1.MergedBits.grpB4
#define PTBPF1_B5                       _PTBPF1.MergedBits.grpB5
#define PTBPF1_B6                       _PTBPF1.MergedBits.grpB6
#define PTBPF1_B7                       _PTBPF1.MergedBits.grpB7

#define PTBPF1_B40_MASK                 1U
#define PTBPF1_B41_MASK                 2U
#define PTBPF1_B50_MASK                 4U
#define PTBPF1_B51_MASK                 8U
#define PTBPF1_B60_MASK                 16U
#define PTBPF1_B61_MASK                 32U
#define PTBPF1_B70_MASK                 64U
#define PTBPF1_B71_MASK                 128U
#define PTBPF1_B4_MASK                  3U
#define PTBPF1_B4_BITNUM                0U
#define PTBPF1_B5_MASK                  12U
#define PTBPF1_B5_BITNUM                2U
#define PTBPF1_B6_MASK                  48U
#define PTBPF1_B6_BITNUM                4U
#define PTBPF1_B7_MASK                  192U
#define PTBPF1_B7_BITNUM                6U


/*** PTBPF2 - Port B Routing Register 2; 0xFFFF80C3 ***/
typedef union {
  byte Byte;
  struct {
    byte B00         :1;                                       /* Port PTB0 Pin Mux Controls, bit 0 */
    byte B01         :1;                                       /* Port PTB0 Pin Mux Controls, bit 1 */
    byte B10         :1;                                       /* Port PTB1 Pin Mux Controls, bit 0 */
    byte B11         :1;                                       /* Port PTB1 Pin Mux Controls, bit 1 */
    byte B20         :1;                                       /* Port PTB2 Pin Mux Controls, bit 0 */
    byte B21         :1;                                       /* Port PTB2 Pin Mux Controls, bit 1 */
    byte B30         :1;                                       /* Port PTB3 Pin Mux Controls, bit 0 */
    byte B31         :1;                                       /* Port PTB3 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpB0   :2;
    byte grpB1   :2;
    byte grpB2   :2;
    byte grpB3   :2;
  } MergedBits;
} PTBPF2STR;
#define _PTBPF2 (*(volatile PTBPF2STR *)0xFFFF80C3)
#define PTBPF2                          _PTBPF2.Byte
#define PTBPF2_B00                      _PTBPF2.Bits.B00
#define PTBPF2_B01                      _PTBPF2.Bits.B01
#define PTBPF2_B10                      _PTBPF2.Bits.B10
#define PTBPF2_B11                      _PTBPF2.Bits.B11
#define PTBPF2_B20                      _PTBPF2.Bits.B20
#define PTBPF2_B21                      _PTBPF2.Bits.B21
#define PTBPF2_B30                      _PTBPF2.Bits.B30
#define PTBPF2_B31                      _PTBPF2.Bits.B31
#define PTBPF2_B0                       _PTBPF2.MergedBits.grpB0
#define PTBPF2_B1                       _PTBPF2.MergedBits.grpB1
#define PTBPF2_B2                       _PTBPF2.MergedBits.grpB2
#define PTBPF2_B3                       _PTBPF2.MergedBits.grpB3

#define PTBPF2_B00_MASK                 1U
#define PTBPF2_B01_MASK                 2U
#define PTBPF2_B10_MASK                 4U
#define PTBPF2_B11_MASK                 8U
#define PTBPF2_B20_MASK                 16U
#define PTBPF2_B21_MASK                 32U
#define PTBPF2_B30_MASK                 64U
#define PTBPF2_B31_MASK                 128U
#define PTBPF2_B0_MASK                  3U
#define PTBPF2_B0_BITNUM                0U
#define PTBPF2_B1_MASK                  12U
#define PTBPF2_B1_BITNUM                2U
#define PTBPF2_B2_MASK                  48U
#define PTBPF2_B2_BITNUM                4U
#define PTBPF2_B3_MASK                  192U
#define PTBPF2_B3_BITNUM                6U


/*** PTCPF1 - Port C Routing Register 1; 0xFFFF80C4 ***/
typedef union {
  byte Byte;
  struct {
    byte C40         :1;                                       /* Port PTC4 Pin Mux Controls, bit 0 */
    byte C41         :1;                                       /* Port PTC4 Pin Mux Controls, bit 1 */
    byte C50         :1;                                       /* Port PTC5 Pin Mux Controls, bit 0 */
    byte C51         :1;                                       /* Port PTC5 Pin Mux Controls, bit 1 */
    byte C60         :1;                                       /* Port PTC6 Pin Mux Controls, bit 0 */
    byte C61         :1;                                       /* Port PTC6 Pin Mux Controls, bit 1 */
    byte C70         :1;                                       /* Port PTC7 Pin Mux Controls, bit 0 */
    byte C71         :1;                                       /* Port PTC7 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpC4   :2;
    byte grpC5   :2;
    byte grpC6   :2;
    byte grpC7   :2;
  } MergedBits;
} PTCPF1STR;
#define _PTCPF1 (*(volatile PTCPF1STR *)0xFFFF80C4)
#define PTCPF1                          _PTCPF1.Byte
#define PTCPF1_C40                      _PTCPF1.Bits.C40
#define PTCPF1_C41                      _PTCPF1.Bits.C41
#define PTCPF1_C50                      _PTCPF1.Bits.C50
#define PTCPF1_C51                      _PTCPF1.Bits.C51
#define PTCPF1_C60                      _PTCPF1.Bits.C60
#define PTCPF1_C61                      _PTCPF1.Bits.C61
#define PTCPF1_C70                      _PTCPF1.Bits.C70
#define PTCPF1_C71                      _PTCPF1.Bits.C71
#define PTCPF1_C4                       _PTCPF1.MergedBits.grpC4
#define PTCPF1_C5                       _PTCPF1.MergedBits.grpC5
#define PTCPF1_C6                       _PTCPF1.MergedBits.grpC6
#define PTCPF1_C7                       _PTCPF1.MergedBits.grpC7

#define PTCPF1_C40_MASK                 1U
#define PTCPF1_C41_MASK                 2U
#define PTCPF1_C50_MASK                 4U
#define PTCPF1_C51_MASK                 8U
#define PTCPF1_C60_MASK                 16U
#define PTCPF1_C61_MASK                 32U
#define PTCPF1_C70_MASK                 64U
#define PTCPF1_C71_MASK                 128U
#define PTCPF1_C4_MASK                  3U
#define PTCPF1_C4_BITNUM                0U
#define PTCPF1_C5_MASK                  12U
#define PTCPF1_C5_BITNUM                2U
#define PTCPF1_C6_MASK                  48U
#define PTCPF1_C6_BITNUM                4U
#define PTCPF1_C7_MASK                  192U
#define PTCPF1_C7_BITNUM                6U


/*** PTCPF2 - Port C Routing Register 2; 0xFFFF80C5 ***/
typedef union {
  byte Byte;
  struct {
    byte C00         :1;                                       /* Port PTC0 Pin Mux Controls, bit 0 */
    byte C01         :1;                                       /* Port PTC0 Pin Mux Controls, bit 1 */
    byte C10         :1;                                       /* Port PTC1 Pin Mux Controls, bit 0 */
    byte C11         :1;                                       /* Port PTC1 Pin Mux Controls, bit 1 */
    byte C20         :1;                                       /* Port PTC2 Pin Mux Controls, bit 0 */
    byte C21         :1;                                       /* Port PTC2 Pin Mux Controls, bit 1 */
    byte C30         :1;                                       /* Port PTC3 Pin Mux Controls, bit 0 */
    byte C31         :1;                                       /* Port PTC3 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpC0   :2;
    byte grpC1   :2;
    byte grpC2   :2;
    byte grpC3   :2;
  } MergedBits;
} PTCPF2STR;
#define _PTCPF2 (*(volatile PTCPF2STR *)0xFFFF80C5)
#define PTCPF2                          _PTCPF2.Byte
#define PTCPF2_C00                      _PTCPF2.Bits.C00
#define PTCPF2_C01                      _PTCPF2.Bits.C01
#define PTCPF2_C10                      _PTCPF2.Bits.C10
#define PTCPF2_C11                      _PTCPF2.Bits.C11
#define PTCPF2_C20                      _PTCPF2.Bits.C20
#define PTCPF2_C21                      _PTCPF2.Bits.C21
#define PTCPF2_C30                      _PTCPF2.Bits.C30
#define PTCPF2_C31                      _PTCPF2.Bits.C31
#define PTCPF2_C0                       _PTCPF2.MergedBits.grpC0
#define PTCPF2_C1                       _PTCPF2.MergedBits.grpC1
#define PTCPF2_C2                       _PTCPF2.MergedBits.grpC2
#define PTCPF2_C3                       _PTCPF2.MergedBits.grpC3

#define PTCPF2_C00_MASK                 1U
#define PTCPF2_C01_MASK                 2U
#define PTCPF2_C10_MASK                 4U
#define PTCPF2_C11_MASK                 8U
#define PTCPF2_C20_MASK                 16U
#define PTCPF2_C21_MASK                 32U
#define PTCPF2_C30_MASK                 64U
#define PTCPF2_C31_MASK                 128U
#define PTCPF2_C0_MASK                  3U
#define PTCPF2_C0_BITNUM                0U
#define PTCPF2_C1_MASK                  12U
#define PTCPF2_C1_BITNUM                2U
#define PTCPF2_C2_MASK                  48U
#define PTCPF2_C2_BITNUM                4U
#define PTCPF2_C3_MASK                  192U
#define PTCPF2_C3_BITNUM                6U


/*** PTDPF1 - Port D Routing Register 1; 0xFFFF80C6 ***/
typedef union {
  byte Byte;
  struct {
    byte D40         :1;                                       /* Port PTD4 Pin Mux Controls, bit 0 */
    byte D41         :1;                                       /* Port PTD4 Pin Mux Controls, bit 1 */
    byte D50         :1;                                       /* Port PTD5 Pin Mux Controls, bit 0 */
    byte D51         :1;                                       /* Port PTD5 Pin Mux Controls, bit 1 */
    byte D60         :1;                                       /* Port PTD6 Pin Mux Controls, bit 0 */
    byte D61         :1;                                       /* Port PTD6 Pin Mux Controls, bit 1 */
    byte D70         :1;                                       /* Port PTD7 Pin Mux Controls, bit 0 */
    byte D71         :1;                                       /* Port PTD7 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpD4   :2;
    byte grpD5   :2;
    byte grpD6   :2;
    byte grpD7   :2;
  } MergedBits;
} PTDPF1STR;
#define _PTDPF1 (*(volatile PTDPF1STR *)0xFFFF80C6)
#define PTDPF1                          _PTDPF1.Byte
#define PTDPF1_D40                      _PTDPF1.Bits.D40
#define PTDPF1_D41                      _PTDPF1.Bits.D41
#define PTDPF1_D50                      _PTDPF1.Bits.D50
#define PTDPF1_D51                      _PTDPF1.Bits.D51
#define PTDPF1_D60                      _PTDPF1.Bits.D60
#define PTDPF1_D61                      _PTDPF1.Bits.D61
#define PTDPF1_D70                      _PTDPF1.Bits.D70
#define PTDPF1_D71                      _PTDPF1.Bits.D71
#define PTDPF1_D4                       _PTDPF1.MergedBits.grpD4
#define PTDPF1_D5                       _PTDPF1.MergedBits.grpD5
#define PTDPF1_D6                       _PTDPF1.MergedBits.grpD6
#define PTDPF1_D7                       _PTDPF1.MergedBits.grpD7

#define PTDPF1_D40_MASK                 1U
#define PTDPF1_D41_MASK                 2U
#define PTDPF1_D50_MASK                 4U
#define PTDPF1_D51_MASK                 8U
#define PTDPF1_D60_MASK                 16U
#define PTDPF1_D61_MASK                 32U
#define PTDPF1_D70_MASK                 64U
#define PTDPF1_D71_MASK                 128U
#define PTDPF1_D4_MASK                  3U
#define PTDPF1_D4_BITNUM                0U
#define PTDPF1_D5_MASK                  12U
#define PTDPF1_D5_BITNUM                2U
#define PTDPF1_D6_MASK                  48U
#define PTDPF1_D6_BITNUM                4U
#define PTDPF1_D7_MASK                  192U
#define PTDPF1_D7_BITNUM                6U


/*** PTDPF2 - Port D Routing Register 2; 0xFFFF80C7 ***/
typedef union {
  byte Byte;
  struct {
    byte D00         :1;                                       /* Port PTD0 Pin Mux Controls, bit 0 */
    byte D01         :1;                                       /* Port PTD0 Pin Mux Controls, bit 1 */
    byte D10         :1;                                       /* Port PTD1 Pin Mux Controls, bit 0 */
    byte D11         :1;                                       /* Port PTD1 Pin Mux Controls, bit 1 */
    byte D20         :1;                                       /* Port PTD2 Pin Mux Controls, bit 0 */
    byte D21         :1;                                       /* Port PTD2 Pin Mux Controls, bit 1 */
    byte D30         :1;                                       /* Port PTD3 Pin Mux Controls, bit 0 */
    byte D31         :1;                                       /* Port PTD3 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpD0   :2;
    byte grpD1   :2;
    byte grpD2   :2;
    byte grpD3   :2;
  } MergedBits;
} PTDPF2STR;
#define _PTDPF2 (*(volatile PTDPF2STR *)0xFFFF80C7)
#define PTDPF2                          _PTDPF2.Byte
#define PTDPF2_D00                      _PTDPF2.Bits.D00
#define PTDPF2_D01                      _PTDPF2.Bits.D01
#define PTDPF2_D10                      _PTDPF2.Bits.D10
#define PTDPF2_D11                      _PTDPF2.Bits.D11
#define PTDPF2_D20                      _PTDPF2.Bits.D20
#define PTDPF2_D21                      _PTDPF2.Bits.D21
#define PTDPF2_D30                      _PTDPF2.Bits.D30
#define PTDPF2_D31                      _PTDPF2.Bits.D31
#define PTDPF2_D0                       _PTDPF2.MergedBits.grpD0
#define PTDPF2_D1                       _PTDPF2.MergedBits.grpD1
#define PTDPF2_D2                       _PTDPF2.MergedBits.grpD2
#define PTDPF2_D3                       _PTDPF2.MergedBits.grpD3

#define PTDPF2_D00_MASK                 1U
#define PTDPF2_D01_MASK                 2U
#define PTDPF2_D10_MASK                 4U
#define PTDPF2_D11_MASK                 8U
#define PTDPF2_D20_MASK                 16U
#define PTDPF2_D21_MASK                 32U
#define PTDPF2_D30_MASK                 64U
#define PTDPF2_D31_MASK                 128U
#define PTDPF2_D0_MASK                  3U
#define PTDPF2_D0_BITNUM                0U
#define PTDPF2_D1_MASK                  12U
#define PTDPF2_D1_BITNUM                2U
#define PTDPF2_D2_MASK                  48U
#define PTDPF2_D2_BITNUM                4U
#define PTDPF2_D3_MASK                  192U
#define PTDPF2_D3_BITNUM                6U


/*** PTEPF1 - Port E Routing Register 1; 0xFFFF80C8 ***/
typedef union {
  byte Byte;
  struct {
    byte E40         :1;                                       /* Port PTE4 Pin Mux Controls, bit 0 */
    byte E41         :1;                                       /* Port PTE4 Pin Mux Controls, bit 1 */
    byte E50         :1;                                       /* Port PTE5 Pin Mux Controls, bit 0 */
    byte E51         :1;                                       /* Port PTE5 Pin Mux Controls, bit 1 */
    byte E60         :1;                                       /* Port PTE6 Pin Mux Controls, bit 0 */
    byte E61         :1;                                       /* Port PTE6 Pin Mux Controls, bit 1 */
    byte E70         :1;                                       /* Port PTE7 Pin Mux Controls, bit 0 */
    byte E71         :1;                                       /* Port PTE7 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpE4   :2;
    byte grpE5   :2;
    byte grpE6   :2;
    byte grpE7   :2;
  } MergedBits;
} PTEPF1STR;
#define _PTEPF1 (*(volatile PTEPF1STR *)0xFFFF80C8)
#define PTEPF1                          _PTEPF1.Byte
#define PTEPF1_E40                      _PTEPF1.Bits.E40
#define PTEPF1_E41                      _PTEPF1.Bits.E41
#define PTEPF1_E50                      _PTEPF1.Bits.E50
#define PTEPF1_E51                      _PTEPF1.Bits.E51
#define PTEPF1_E60                      _PTEPF1.Bits.E60
#define PTEPF1_E61                      _PTEPF1.Bits.E61
#define PTEPF1_E70                      _PTEPF1.Bits.E70
#define PTEPF1_E71                      _PTEPF1.Bits.E71
#define PTEPF1_E4                       _PTEPF1.MergedBits.grpE4
#define PTEPF1_E5                       _PTEPF1.MergedBits.grpE5
#define PTEPF1_E6                       _PTEPF1.MergedBits.grpE6
#define PTEPF1_E7                       _PTEPF1.MergedBits.grpE7

#define PTEPF1_E40_MASK                 1U
#define PTEPF1_E41_MASK                 2U
#define PTEPF1_E50_MASK                 4U
#define PTEPF1_E51_MASK                 8U
#define PTEPF1_E60_MASK                 16U
#define PTEPF1_E61_MASK                 32U
#define PTEPF1_E70_MASK                 64U
#define PTEPF1_E71_MASK                 128U
#define PTEPF1_E4_MASK                  3U
#define PTEPF1_E4_BITNUM                0U
#define PTEPF1_E5_MASK                  12U
#define PTEPF1_E5_BITNUM                2U
#define PTEPF1_E6_MASK                  48U
#define PTEPF1_E6_BITNUM                4U
#define PTEPF1_E7_MASK                  192U
#define PTEPF1_E7_BITNUM                6U


/*** PTEPF2 - Port E Routing Register 2; 0xFFFF80C9 ***/
typedef union {
  byte Byte;
  struct {
    byte E00         :1;                                       /* Port PTE0 Pin Mux Controls, bit 0 */
    byte E01         :1;                                       /* Port PTE0 Pin Mux Controls, bit 1 */
    byte E10         :1;                                       /* Port PTE1 Pin Mux Controls, bit 0 */
    byte E11         :1;                                       /* Port PTE1 Pin Mux Controls, bit 1 */
    byte E20         :1;                                       /* Port PTE2 Pin Mux Controls, bit 0 */
    byte E21         :1;                                       /* Port PTE2 Pin Mux Controls, bit 1 */
    byte E30         :1;                                       /* Port PTE3 Pin Mux Controls, bit 0 */
    byte E31         :1;                                       /* Port PTE3 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpE0   :2;
    byte grpE1   :2;
    byte grpE2   :2;
    byte grpE3   :2;
  } MergedBits;
} PTEPF2STR;
#define _PTEPF2 (*(volatile PTEPF2STR *)0xFFFF80C9)
#define PTEPF2                          _PTEPF2.Byte
#define PTEPF2_E00                      _PTEPF2.Bits.E00
#define PTEPF2_E01                      _PTEPF2.Bits.E01
#define PTEPF2_E10                      _PTEPF2.Bits.E10
#define PTEPF2_E11                      _PTEPF2.Bits.E11
#define PTEPF2_E20                      _PTEPF2.Bits.E20
#define PTEPF2_E21                      _PTEPF2.Bits.E21
#define PTEPF2_E30                      _PTEPF2.Bits.E30
#define PTEPF2_E31                      _PTEPF2.Bits.E31
#define PTEPF2_E0                       _PTEPF2.MergedBits.grpE0
#define PTEPF2_E1                       _PTEPF2.MergedBits.grpE1
#define PTEPF2_E2                       _PTEPF2.MergedBits.grpE2
#define PTEPF2_E3                       _PTEPF2.MergedBits.grpE3

#define PTEPF2_E00_MASK                 1U
#define PTEPF2_E01_MASK                 2U
#define PTEPF2_E10_MASK                 4U
#define PTEPF2_E11_MASK                 8U
#define PTEPF2_E20_MASK                 16U
#define PTEPF2_E21_MASK                 32U
#define PTEPF2_E30_MASK                 64U
#define PTEPF2_E31_MASK                 128U
#define PTEPF2_E0_MASK                  3U
#define PTEPF2_E0_BITNUM                0U
#define PTEPF2_E1_MASK                  12U
#define PTEPF2_E1_BITNUM                2U
#define PTEPF2_E2_MASK                  48U
#define PTEPF2_E2_BITNUM                4U
#define PTEPF2_E3_MASK                  192U
#define PTEPF2_E3_BITNUM                6U


/*** PTFPF1 - Port F Routing Register 1; 0xFFFF80CA ***/
typedef union {
  byte Byte;
  struct {
    byte F40         :1;                                       /* Port PTF4 Pin Mux Controls, bit 0 */
    byte F41         :1;                                       /* Port PTF4 Pin Mux Controls, bit 1 */
    byte F50         :1;                                       /* Port PTF5 Pin Mux Controls, bit 0 */
    byte F51         :1;                                       /* Port PTF5 Pin Mux Controls, bit 1 */
    byte F60         :1;                                       /* Port PTF6 Pin Mux Controls, bit 0 */
    byte F61         :1;                                       /* Port PTF6 Pin Mux Controls, bit 1 */
    byte F70         :1;                                       /* Port PTF7 Pin Mux Controls, bit 0 */
    byte F71         :1;                                       /* Port PTF7 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpF4   :2;
    byte grpF5   :2;
    byte grpF6   :2;
    byte grpF7   :2;
  } MergedBits;
} PTFPF1STR;
#define _PTFPF1 (*(volatile PTFPF1STR *)0xFFFF80CA)
#define PTFPF1                          _PTFPF1.Byte
#define PTFPF1_F40                      _PTFPF1.Bits.F40
#define PTFPF1_F41                      _PTFPF1.Bits.F41
#define PTFPF1_F50                      _PTFPF1.Bits.F50
#define PTFPF1_F51                      _PTFPF1.Bits.F51
#define PTFPF1_F60                      _PTFPF1.Bits.F60
#define PTFPF1_F61                      _PTFPF1.Bits.F61
#define PTFPF1_F70                      _PTFPF1.Bits.F70
#define PTFPF1_F71                      _PTFPF1.Bits.F71
#define PTFPF1_F4                       _PTFPF1.MergedBits.grpF4
#define PTFPF1_F5                       _PTFPF1.MergedBits.grpF5
#define PTFPF1_F6                       _PTFPF1.MergedBits.grpF6
#define PTFPF1_F7                       _PTFPF1.MergedBits.grpF7

#define PTFPF1_F40_MASK                 1U
#define PTFPF1_F41_MASK                 2U
#define PTFPF1_F50_MASK                 4U
#define PTFPF1_F51_MASK                 8U
#define PTFPF1_F60_MASK                 16U
#define PTFPF1_F61_MASK                 32U
#define PTFPF1_F70_MASK                 64U
#define PTFPF1_F71_MASK                 128U
#define PTFPF1_F4_MASK                  3U
#define PTFPF1_F4_BITNUM                0U
#define PTFPF1_F5_MASK                  12U
#define PTFPF1_F5_BITNUM                2U
#define PTFPF1_F6_MASK                  48U
#define PTFPF1_F6_BITNUM                4U
#define PTFPF1_F7_MASK                  192U
#define PTFPF1_F7_BITNUM                6U


/*** PTFPF2 - Port F Routing Register 2; 0xFFFF80CB ***/
typedef union {
  byte Byte;
  struct {
    byte F00         :1;                                       /* Port PTF0 Pin Mux Controls, bit 0 */
    byte F01         :1;                                       /* Port PTF0 Pin Mux Controls, bit 1 */
    byte F10         :1;                                       /* Port PTF1 Pin Mux Controls, bit 0 */
    byte F11         :1;                                       /* Port PTF1 Pin Mux Controls, bit 1 */
    byte F20         :1;                                       /* Port PTF2 Pin Mux Controls, bit 0 */
    byte F21         :1;                                       /* Port PTF2 Pin Mux Controls, bit 1 */
    byte F30         :1;                                       /* Port PTF3 Pin Mux Controls, bit 0 */
    byte F31         :1;                                       /* Port PTF3 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpF0   :2;
    byte grpF1   :2;
    byte grpF2   :2;
    byte grpF3   :2;
  } MergedBits;
} PTFPF2STR;
#define _PTFPF2 (*(volatile PTFPF2STR *)0xFFFF80CB)
#define PTFPF2                          _PTFPF2.Byte
#define PTFPF2_F00                      _PTFPF2.Bits.F00
#define PTFPF2_F01                      _PTFPF2.Bits.F01
#define PTFPF2_F10                      _PTFPF2.Bits.F10
#define PTFPF2_F11                      _PTFPF2.Bits.F11
#define PTFPF2_F20                      _PTFPF2.Bits.F20
#define PTFPF2_F21                      _PTFPF2.Bits.F21
#define PTFPF2_F30                      _PTFPF2.Bits.F30
#define PTFPF2_F31                      _PTFPF2.Bits.F31
#define PTFPF2_F0                       _PTFPF2.MergedBits.grpF0
#define PTFPF2_F1                       _PTFPF2.MergedBits.grpF1
#define PTFPF2_F2                       _PTFPF2.MergedBits.grpF2
#define PTFPF2_F3                       _PTFPF2.MergedBits.grpF3

#define PTFPF2_F00_MASK                 1U
#define PTFPF2_F01_MASK                 2U
#define PTFPF2_F10_MASK                 4U
#define PTFPF2_F11_MASK                 8U
#define PTFPF2_F20_MASK                 16U
#define PTFPF2_F21_MASK                 32U
#define PTFPF2_F30_MASK                 64U
#define PTFPF2_F31_MASK                 128U
#define PTFPF2_F0_MASK                  3U
#define PTFPF2_F0_BITNUM                0U
#define PTFPF2_F1_MASK                  12U
#define PTFPF2_F1_BITNUM                2U
#define PTFPF2_F2_MASK                  48U
#define PTFPF2_F2_BITNUM                4U
#define PTFPF2_F3_MASK                  192U
#define PTFPF2_F3_BITNUM                6U


/*** PTGPF1 - Port G Routing Register 1; 0xFFFF80CC ***/
typedef union {
  byte Byte;
  struct {
    byte G40         :1;                                       /* Port PTG4 Pin Mux Controls, bit 0 */
    byte G41         :1;                                       /* Port PTG4 Pin Mux Controls, bit 1 */
    byte G50         :1;                                       /* Port PTG5 Pin Mux Controls, bit 0 */
    byte G51         :1;                                       /* Port PTG5 Pin Mux Controls, bit 1 */
    byte G60         :1;                                       /* Port PTG6 Pin Mux Controls, bit 0 */
    byte G61         :1;                                       /* Port PTG6 Pin Mux Controls, bit 1 */
    byte G70         :1;                                       /* Port PTG7 Pin Mux Controls, bit 0 */
    byte G71         :1;                                       /* Port PTG7 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpG4   :2;
    byte grpG5   :2;
    byte grpG6   :2;
    byte grpG7   :2;
  } MergedBits;
} PTGPF1STR;
#define _PTGPF1 (*(volatile PTGPF1STR *)0xFFFF80CC)
#define PTGPF1                          _PTGPF1.Byte
#define PTGPF1_G40                      _PTGPF1.Bits.G40
#define PTGPF1_G41                      _PTGPF1.Bits.G41
#define PTGPF1_G50                      _PTGPF1.Bits.G50
#define PTGPF1_G51                      _PTGPF1.Bits.G51
#define PTGPF1_G60                      _PTGPF1.Bits.G60
#define PTGPF1_G61                      _PTGPF1.Bits.G61
#define PTGPF1_G70                      _PTGPF1.Bits.G70
#define PTGPF1_G71                      _PTGPF1.Bits.G71
#define PTGPF1_G4                       _PTGPF1.MergedBits.grpG4
#define PTGPF1_G5                       _PTGPF1.MergedBits.grpG5
#define PTGPF1_G6                       _PTGPF1.MergedBits.grpG6
#define PTGPF1_G7                       _PTGPF1.MergedBits.grpG7

#define PTGPF1_G40_MASK                 1U
#define PTGPF1_G41_MASK                 2U
#define PTGPF1_G50_MASK                 4U
#define PTGPF1_G51_MASK                 8U
#define PTGPF1_G60_MASK                 16U
#define PTGPF1_G61_MASK                 32U
#define PTGPF1_G70_MASK                 64U
#define PTGPF1_G71_MASK                 128U
#define PTGPF1_G4_MASK                  3U
#define PTGPF1_G4_BITNUM                0U
#define PTGPF1_G5_MASK                  12U
#define PTGPF1_G5_BITNUM                2U
#define PTGPF1_G6_MASK                  48U
#define PTGPF1_G6_BITNUM                4U
#define PTGPF1_G7_MASK                  192U
#define PTGPF1_G7_BITNUM                6U


/*** PTGPF2 - Port G Routing Register 2; 0xFFFF80CD ***/
typedef union {
  byte Byte;
  struct {
    byte G00         :1;                                       /* Port PTG0 Pin Mux Controls, bit 0 */
    byte G01         :1;                                       /* Port PTG0 Pin Mux Controls, bit 1 */
    byte G10         :1;                                       /* Port PTG1 Pin Mux Controls, bit 0 */
    byte G11         :1;                                       /* Port PTG1 Pin Mux Controls, bit 1 */
    byte G20         :1;                                       /* Port PTG2 Pin Mux Controls, bit 0 */
    byte G21         :1;                                       /* Port PTG2 Pin Mux Controls, bit 1 */
    byte G30         :1;                                       /* Port PTG3 Pin Mux Controls, bit 0 */
    byte G31         :1;                                       /* Port PTG3 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpG0   :2;
    byte grpG1   :2;
    byte grpG2   :2;
    byte grpG3   :2;
  } MergedBits;
} PTGPF2STR;
#define _PTGPF2 (*(volatile PTGPF2STR *)0xFFFF80CD)
#define PTGPF2                          _PTGPF2.Byte
#define PTGPF2_G00                      _PTGPF2.Bits.G00
#define PTGPF2_G01                      _PTGPF2.Bits.G01
#define PTGPF2_G10                      _PTGPF2.Bits.G10
#define PTGPF2_G11                      _PTGPF2.Bits.G11
#define PTGPF2_G20                      _PTGPF2.Bits.G20
#define PTGPF2_G21                      _PTGPF2.Bits.G21
#define PTGPF2_G30                      _PTGPF2.Bits.G30
#define PTGPF2_G31                      _PTGPF2.Bits.G31
#define PTGPF2_G0                       _PTGPF2.MergedBits.grpG0
#define PTGPF2_G1                       _PTGPF2.MergedBits.grpG1
#define PTGPF2_G2                       _PTGPF2.MergedBits.grpG2
#define PTGPF2_G3                       _PTGPF2.MergedBits.grpG3

#define PTGPF2_G00_MASK                 1U
#define PTGPF2_G01_MASK                 2U
#define PTGPF2_G10_MASK                 4U
#define PTGPF2_G11_MASK                 8U
#define PTGPF2_G20_MASK                 16U
#define PTGPF2_G21_MASK                 32U
#define PTGPF2_G30_MASK                 64U
#define PTGPF2_G31_MASK                 128U
#define PTGPF2_G0_MASK                  3U
#define PTGPF2_G0_BITNUM                0U
#define PTGPF2_G1_MASK                  12U
#define PTGPF2_G1_BITNUM                2U
#define PTGPF2_G2_MASK                  48U
#define PTGPF2_G2_BITNUM                4U
#define PTGPF2_G3_MASK                  192U
#define PTGPF2_G3_BITNUM                6U


/*** PTHPF1 - Port H Routing Register 1; 0xFFFF80CE ***/
typedef union {
  byte Byte;
  struct {
    byte H40         :1;                                       /* Port PTH4 Pin Mux Controls, bit 0 */
    byte H41         :1;                                       /* Port PTH4 Pin Mux Controls, bit 1 */
    byte H50         :1;                                       /* Port PTH5 Pin Mux Controls, bit 0 */
    byte H51         :1;                                       /* Port PTH5 Pin Mux Controls, bit 1 */
    byte H60         :1;                                       /* Port PTH6 Pin Mux Controls, bit 0 */
    byte H61         :1;                                       /* Port PTH6 Pin Mux Controls, bit 1 */
    byte H70         :1;                                       /* Port PTH7 Pin Mux Controls, bit 0 */
    byte H71         :1;                                       /* Port PTH7 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpH4   :2;
    byte grpH5   :2;
    byte grpH6   :2;
    byte grpH7   :2;
  } MergedBits;
} PTHPF1STR;
#define _PTHPF1 (*(volatile PTHPF1STR *)0xFFFF80CE)
#define PTHPF1                          _PTHPF1.Byte
#define PTHPF1_H40                      _PTHPF1.Bits.H40
#define PTHPF1_H41                      _PTHPF1.Bits.H41
#define PTHPF1_H50                      _PTHPF1.Bits.H50
#define PTHPF1_H51                      _PTHPF1.Bits.H51
#define PTHPF1_H60                      _PTHPF1.Bits.H60
#define PTHPF1_H61                      _PTHPF1.Bits.H61
#define PTHPF1_H70                      _PTHPF1.Bits.H70
#define PTHPF1_H71                      _PTHPF1.Bits.H71
#define PTHPF1_H4                       _PTHPF1.MergedBits.grpH4
#define PTHPF1_H5                       _PTHPF1.MergedBits.grpH5
#define PTHPF1_H6                       _PTHPF1.MergedBits.grpH6
#define PTHPF1_H7                       _PTHPF1.MergedBits.grpH7

#define PTHPF1_H40_MASK                 1U
#define PTHPF1_H41_MASK                 2U
#define PTHPF1_H50_MASK                 4U
#define PTHPF1_H51_MASK                 8U
#define PTHPF1_H60_MASK                 16U
#define PTHPF1_H61_MASK                 32U
#define PTHPF1_H70_MASK                 64U
#define PTHPF1_H71_MASK                 128U
#define PTHPF1_H4_MASK                  3U
#define PTHPF1_H4_BITNUM                0U
#define PTHPF1_H5_MASK                  12U
#define PTHPF1_H5_BITNUM                2U
#define PTHPF1_H6_MASK                  48U
#define PTHPF1_H6_BITNUM                4U
#define PTHPF1_H7_MASK                  192U
#define PTHPF1_H7_BITNUM                6U


/*** PTHPF2 - Port H Routing Register 2; 0xFFFF80CF ***/
typedef union {
  byte Byte;
  struct {
    byte H00         :1;                                       /* Port PTH0 Pin Mux Controls, bit 0 */
    byte H01         :1;                                       /* Port PTH0 Pin Mux Controls, bit 1 */
    byte H10         :1;                                       /* Port PTH1 Pin Mux Controls, bit 0 */
    byte H11         :1;                                       /* Port PTH1 Pin Mux Controls, bit 1 */
    byte H20         :1;                                       /* Port PTH2 Pin Mux Controls, bit 0 */
    byte H21         :1;                                       /* Port PTH2 Pin Mux Controls, bit 1 */
    byte H30         :1;                                       /* Port PTH3 Pin Mux Controls, bit 0 */
    byte H31         :1;                                       /* Port PTH3 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpH0   :2;
    byte grpH1   :2;
    byte grpH2   :2;
    byte grpH3   :2;
  } MergedBits;
} PTHPF2STR;
#define _PTHPF2 (*(volatile PTHPF2STR *)0xFFFF80CF)
#define PTHPF2                          _PTHPF2.Byte
#define PTHPF2_H00                      _PTHPF2.Bits.H00
#define PTHPF2_H01                      _PTHPF2.Bits.H01
#define PTHPF2_H10                      _PTHPF2.Bits.H10
#define PTHPF2_H11                      _PTHPF2.Bits.H11
#define PTHPF2_H20                      _PTHPF2.Bits.H20
#define PTHPF2_H21                      _PTHPF2.Bits.H21
#define PTHPF2_H30                      _PTHPF2.Bits.H30
#define PTHPF2_H31                      _PTHPF2.Bits.H31
#define PTHPF2_H0                       _PTHPF2.MergedBits.grpH0
#define PTHPF2_H1                       _PTHPF2.MergedBits.grpH1
#define PTHPF2_H2                       _PTHPF2.MergedBits.grpH2
#define PTHPF2_H3                       _PTHPF2.MergedBits.grpH3

#define PTHPF2_H00_MASK                 1U
#define PTHPF2_H01_MASK                 2U
#define PTHPF2_H10_MASK                 4U
#define PTHPF2_H11_MASK                 8U
#define PTHPF2_H20_MASK                 16U
#define PTHPF2_H21_MASK                 32U
#define PTHPF2_H30_MASK                 64U
#define PTHPF2_H31_MASK                 128U
#define PTHPF2_H0_MASK                  3U
#define PTHPF2_H0_BITNUM                0U
#define PTHPF2_H1_MASK                  12U
#define PTHPF2_H1_BITNUM                2U
#define PTHPF2_H2_MASK                  48U
#define PTHPF2_H2_BITNUM                4U
#define PTHPF2_H3_MASK                  192U
#define PTHPF2_H3_BITNUM                6U


/*** PTJPF1 - Port J Routing Register 1; 0xFFFF80D0 ***/
typedef union {
  byte Byte;
  struct {
    byte J40         :1;                                       /* Port PTJ4 Pin Mux Controls, bit 0 */
    byte J41         :1;                                       /* Port PTJ4 Pin Mux Controls, bit 1 */
    byte J50         :1;                                       /* Port PTJ5 Pin Mux Controls, bit 0 */
    byte J51         :1;                                       /* Port PTJ5 Pin Mux Controls, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpJ4   :2;
    byte grpJ5   :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTJPF1STR;
#define _PTJPF1 (*(volatile PTJPF1STR *)0xFFFF80D0)
#define PTJPF1                          _PTJPF1.Byte
#define PTJPF1_J40                      _PTJPF1.Bits.J40
#define PTJPF1_J41                      _PTJPF1.Bits.J41
#define PTJPF1_J50                      _PTJPF1.Bits.J50
#define PTJPF1_J51                      _PTJPF1.Bits.J51
#define PTJPF1_J4                       _PTJPF1.MergedBits.grpJ4
#define PTJPF1_J5                       _PTJPF1.MergedBits.grpJ5

#define PTJPF1_J40_MASK                 1U
#define PTJPF1_J41_MASK                 2U
#define PTJPF1_J50_MASK                 4U
#define PTJPF1_J51_MASK                 8U
#define PTJPF1_J4_MASK                  3U
#define PTJPF1_J4_BITNUM                0U
#define PTJPF1_J5_MASK                  12U
#define PTJPF1_J5_BITNUM                2U


/*** PTJPF2 - Port J Routing Register 2; 0xFFFF80D1 ***/
typedef union {
  byte Byte;
  struct {
    byte J00         :1;                                       /* Port PTJ0 Pin Mux Controls, bit 0 */
    byte J01         :1;                                       /* Port PTJ0 Pin Mux Controls, bit 1 */
    byte J10         :1;                                       /* Port PTJ1 Pin Mux Controls, bit 0 */
    byte J11         :1;                                       /* Port PTJ1 Pin Mux Controls, bit 1 */
    byte J20         :1;                                       /* Port PTJ2 Pin Mux Controls, bit 0 */
    byte J21         :1;                                       /* Port PTJ2 Pin Mux Controls, bit 1 */
    byte J30         :1;                                       /* Port PTJ3 Pin Mux Controls, bit 0 */
    byte J31         :1;                                       /* Port PTJ3 Pin Mux Controls, bit 1 */
  } Bits;
  struct {
    byte grpJ0   :2;
    byte grpJ1   :2;
    byte grpJ2   :2;
    byte grpJ3   :2;
  } MergedBits;
} PTJPF2STR;
#define _PTJPF2 (*(volatile PTJPF2STR *)0xFFFF80D1)
#define PTJPF2                          _PTJPF2.Byte
#define PTJPF2_J00                      _PTJPF2.Bits.J00
#define PTJPF2_J01                      _PTJPF2.Bits.J01
#define PTJPF2_J10                      _PTJPF2.Bits.J10
#define PTJPF2_J11                      _PTJPF2.Bits.J11
#define PTJPF2_J20                      _PTJPF2.Bits.J20
#define PTJPF2_J21                      _PTJPF2.Bits.J21
#define PTJPF2_J30                      _PTJPF2.Bits.J30
#define PTJPF2_J31                      _PTJPF2.Bits.J31
#define PTJPF2_J0                       _PTJPF2.MergedBits.grpJ0
#define PTJPF2_J1                       _PTJPF2.MergedBits.grpJ1
#define PTJPF2_J2                       _PTJPF2.MergedBits.grpJ2
#define PTJPF2_J3                       _PTJPF2.MergedBits.grpJ3

#define PTJPF2_J00_MASK                 1U
#define PTJPF2_J01_MASK                 2U
#define PTJPF2_J10_MASK                 4U
#define PTJPF2_J11_MASK                 8U
#define PTJPF2_J20_MASK                 16U
#define PTJPF2_J21_MASK                 32U
#define PTJPF2_J30_MASK                 64U
#define PTJPF2_J31_MASK                 128U
#define PTJPF2_J0_MASK                  3U
#define PTJPF2_J0_BITNUM                0U
#define PTJPF2_J1_MASK                  12U
#define PTJPF2_J1_BITNUM                2U
#define PTJPF2_J2_MASK                  48U
#define PTJPF2_J2_BITNUM                4U
#define PTJPF2_J3_MASK                  192U
#define PTJPF2_J3_BITNUM                6U


/*** IRQSC - Interrupt request status and control register; 0xFFFF80E0 ***/
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
#define _IRQSC (*(volatile IRQSCSTR *)0xFFFF80E0)
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


/*** SRS - System Reset Status Register; 0xFFFF8100 ***/
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
#define _SRS (*(volatile SRSSTR *)0xFFFF8100)
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


/*** SOPT1 - System Options Register 1; 0xFFFF8101 ***/
typedef union {
  byte Byte;
  struct {
    byte COPW        :1;                                       /* COP Window Mode */
    byte COPCLKS     :1;                                       /* COP Watchdog Clock Select */
    byte COPT0       :1;                                       /* COP Watchdog Timeout, bit 0 */
    byte COPT1       :1;                                       /* COP Watchdog Timeout, bit 1 */
    byte WAITE       :1;                                       /* WAIT Mode Enable */
    byte STOPE       :1;                                       /* Stop Mode Enable */
    byte SL          :1;                                       /* Security Level */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpCOPT :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SOPT1STR;
#define _SOPT1 (*(volatile SOPT1STR *)0xFFFF8101)
#define SOPT1                           _SOPT1.Byte
#define SOPT1_COPW                      _SOPT1.Bits.COPW
#define SOPT1_COPCLKS                   _SOPT1.Bits.COPCLKS
#define SOPT1_COPT0                     _SOPT1.Bits.COPT0
#define SOPT1_COPT1                     _SOPT1.Bits.COPT1
#define SOPT1_WAITE                     _SOPT1.Bits.WAITE
#define SOPT1_STOPE                     _SOPT1.Bits.STOPE
#define SOPT1_SL                        _SOPT1.Bits.SL
#define SOPT1_COPT                      _SOPT1.MergedBits.grpCOPT

#define SOPT1_COPW_MASK                 1U
#define SOPT1_COPCLKS_MASK              2U
#define SOPT1_COPT0_MASK                4U
#define SOPT1_COPT1_MASK                8U
#define SOPT1_WAITE_MASK                16U
#define SOPT1_STOPE_MASK                32U
#define SOPT1_SL_MASK                   64U
#define SOPT1_COPT_MASK                 12U
#define SOPT1_COPT_BITNUM               2U


/*** SOPT3 - SIM Options Register 3; 0xFFFF8103 ***/
typedef union {
  byte Byte;
  struct {
    byte PCS0        :1;                                       /* Phy Clock Select, bit 0 */
    byte PCS1        :1;                                       /* Phy Clock Select, bit 1 */
    byte CS0         :1;                                       /* CLKOUT Select, bit 0 */
    byte CS1         :1;                                       /* CLKOUT Select, bit 1 */
    byte CS2         :1;                                       /* CLKOUT Select, bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPCS  :2;
    byte grpCS   :3;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SOPT3STR;
#define _SOPT3 (*(volatile SOPT3STR *)0xFFFF8103)
#define SOPT3                           _SOPT3.Byte
#define SOPT3_PCS0                      _SOPT3.Bits.PCS0
#define SOPT3_PCS1                      _SOPT3.Bits.PCS1
#define SOPT3_CS0                       _SOPT3.Bits.CS0
#define SOPT3_CS1                       _SOPT3.Bits.CS1
#define SOPT3_CS2                       _SOPT3.Bits.CS2
#define SOPT3_PCS                       _SOPT3.MergedBits.grpPCS
#define SOPT3_CS                        _SOPT3.MergedBits.grpCS

#define SOPT3_PCS0_MASK                 1U
#define SOPT3_PCS1_MASK                 2U
#define SOPT3_CS0_MASK                  4U
#define SOPT3_CS1_MASK                  8U
#define SOPT3_CS2_MASK                  16U
#define SOPT3_PCS_MASK                  3U
#define SOPT3_PCS_BITNUM                0U
#define SOPT3_CS_MASK                   28U
#define SOPT3_CS_BITNUM                 2U


/*** SDID - System Device Identification Register; 0xFFFF8106 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SDIDH - System Device Identification Register High; 0xFFFF8106 ***/
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       /* Part Identification Number, bit 8 */
        byte ID9         :1;                                       /* Part Identification Number, bit 9 */
        byte ID10        :1;                                       /* Part Identification Number, bit 10 */
        byte ID11        :1;                                       /* Part Identification Number, bit 11 */
        byte REV0        :1;                                       /* Revision Number, bit 0 */
        byte REV1        :1;                                       /* Revision Number, bit 1 */
        byte REV2        :1;                                       /* Revision Number, bit 2 */
        byte REV3        :1;                                       /* Revision Number, bit 3 */
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
    

    /*** SDIDL - System Device Identification Register Low; 0xFFFF8107 ***/
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
    word REV0        :1;                                       /* Revision Number */
    word REV1        :1;                                       /* Revision Number, bit 1 */
    word REV2        :1;                                       /* Revision Number, bit 2 */
    word REV3        :1;                                       /* Revision Number, bit 3 */
  } Bits;
  struct {
    word grpID   :12;
    word grpREV  :4;
  } MergedBits;
} SDIDSTR;
#define _SDID (*(volatile SDIDSTR *)0xFFFF8106)
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


/*** SCGC1 - System Clock Gating Control 1 Register; 0xFFFF8108 ***/
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
    byte MTIM1       :1;                                       /* MTIM1 Clock Gate Control */
  } Bits;
  struct {
    byte grpSCI_1 :2;
    byte grpIIC_1 :2;
    byte         :1;
    byte grpTPM_1 :2;
    byte grpMTIM_1 :1;
  } MergedBits;
} SCGC1STR;
#define _SCGC1 (*(volatile SCGC1STR *)0xFFFF8108)
#define SCGC1                           _SCGC1.Byte
#define SCGC1_SCI1                      _SCGC1.Bits.SCI1
#define SCGC1_SCI2                      _SCGC1.Bits.SCI2
#define SCGC1_IIC1                      _SCGC1.Bits.IIC1
#define SCGC1_IIC2                      _SCGC1.Bits.IIC2
#define SCGC1_ADC                       _SCGC1.Bits.ADC
#define SCGC1_TPM1                      _SCGC1.Bits.TPM1
#define SCGC1_TPM2                      _SCGC1.Bits.TPM2
#define SCGC1_MTIM1                     _SCGC1.Bits.MTIM1
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
#define SCGC1_MTIM1_MASK                128U
#define SCGC1_SCI_1_MASK                3U
#define SCGC1_SCI_1_BITNUM              0U
#define SCGC1_IIC_1_MASK                12U
#define SCGC1_IIC_1_BITNUM              2U
#define SCGC1_TPM_1_MASK                96U
#define SCGC1_TPM_1_BITNUM              5U


/*** SCGC2 - System Clock Gating Control 2 Register; 0xFFFF8109 ***/
typedef union {
  byte Byte;
  struct {
    byte SPI1        :1;                                       /* SPI1 Clock Gate Control */
    byte SPI2        :1;                                       /* SPI2 Clock Gate Control */
    byte RTC         :1;                                       /* RTC Clock Gate Control */
    byte KBI1        :1;                                       /* KBI1 Clock Gate Control */
    byte KBI2        :1;                                       /* KBI2 Clock Gate Control */
    byte IRQ         :1;                                       /* IRQ Clock Gate Control */
    byte FTSR        :1;                                       /* FTSR Clock Gate Control */
    byte SCI3        :1;                                       /* SCI3 Clock Gate Control */
  } Bits;
  struct {
    byte grpSPI_1 :2;
    byte         :1;
    byte grpKBI_1 :2;
    byte         :1;
    byte         :1;
    byte grpSCI_3 :1;
  } MergedBits;
} SCGC2STR;
#define _SCGC2 (*(volatile SCGC2STR *)0xFFFF8109)
#define SCGC2                           _SCGC2.Byte
#define SCGC2_SPI1                      _SCGC2.Bits.SPI1
#define SCGC2_SPI2                      _SCGC2.Bits.SPI2
#define SCGC2_RTC                       _SCGC2.Bits.RTC
#define SCGC2_KBI1                      _SCGC2.Bits.KBI1
#define SCGC2_KBI2                      _SCGC2.Bits.KBI2
#define SCGC2_IRQ                       _SCGC2.Bits.IRQ
#define SCGC2_FTSR                      _SCGC2.Bits.FTSR
#define SCGC2_SCI3                      _SCGC2.Bits.SCI3
#define SCGC2_SPI_1                     _SCGC2.MergedBits.grpSPI_1
#define SCGC2_KBI_1                     _SCGC2.MergedBits.grpKBI_1
#define SCGC2_SPI                       SCGC2_SPI_1
#define SCGC2_KBI                       SCGC2_KBI_1

#define SCGC2_SPI1_MASK                 1U
#define SCGC2_SPI2_MASK                 2U
#define SCGC2_RTC_MASK                  4U
#define SCGC2_KBI1_MASK                 8U
#define SCGC2_KBI2_MASK                 16U
#define SCGC2_IRQ_MASK                  32U
#define SCGC2_FTSR_MASK                 64U
#define SCGC2_SCI3_MASK                 128U
#define SCGC2_SPI_1_MASK                3U
#define SCGC2_SPI_1_BITNUM              0U
#define SCGC2_KBI_1_MASK                24U
#define SCGC2_KBI_1_BITNUM              3U


/*** SCGC3 - System Clock Gating Control 3 Register; 0xFFFF810A ***/
typedef union {
  byte Byte;
  struct {
    byte PTA         :1;                                       /* PTA Clock Gate Control */
    byte PTB         :1;                                       /* PTB Clock Gate Control */
    byte PTC         :1;                                       /* PTC Clock Gate Control */
    byte PTD         :1;                                       /* PTD Clock Gate Control */
    byte PTE         :1;                                       /* PTE Clock Gate Control */
    byte PTF         :1;                                       /* PTF Clock Gate Control */
    byte PTG         :1;                                       /* PTG Clock Gate Control */
    byte PTH         :1;                                       /* PTH Clock Gate Control */
  } Bits;
} SCGC3STR;
#define _SCGC3 (*(volatile SCGC3STR *)0xFFFF810A)
#define SCGC3                           _SCGC3.Byte
#define SCGC3_PTA                       _SCGC3.Bits.PTA
#define SCGC3_PTB                       _SCGC3.Bits.PTB
#define SCGC3_PTC                       _SCGC3.Bits.PTC
#define SCGC3_PTD                       _SCGC3.Bits.PTD
#define SCGC3_PTE                       _SCGC3.Bits.PTE
#define SCGC3_PTF                       _SCGC3.Bits.PTF
#define SCGC3_PTG                       _SCGC3.Bits.PTG
#define SCGC3_PTH                       _SCGC3.Bits.PTH

#define SCGC3_PTA_MASK                  1U
#define SCGC3_PTB_MASK                  2U
#define SCGC3_PTC_MASK                  4U
#define SCGC3_PTD_MASK                  8U
#define SCGC3_PTE_MASK                  16U
#define SCGC3_PTF_MASK                  32U
#define SCGC3_PTG_MASK                  64U
#define SCGC3_PTH_MASK                  128U


/*** SCGC4 - System Clock Gating Control 4 Register; 0xFFFF810B ***/
typedef union {
  byte Byte;
  struct {
    byte PTJ         :1;                                       /* PTJ Clock Gate Control */
    byte FEC         :1;                                       /* FEC Clock Gate Control */
    byte MB          :1;                                       /* MiniBus Clock Gate Control */
    byte MC          :1;                                       /* Port Mux Control */
    byte MTIM2       :1;                                       /* MTIM2 Clock Gate Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SCGC4STR;
#define _SCGC4 (*(volatile SCGC4STR *)0xFFFF810B)
#define SCGC4                           _SCGC4.Byte
#define SCGC4_PTJ                       _SCGC4.Bits.PTJ
#define SCGC4_FEC                       _SCGC4.Bits.FEC
#define SCGC4_MB                        _SCGC4.Bits.MB
#define SCGC4_MC                        _SCGC4.Bits.MC
#define SCGC4_MTIM2                     _SCGC4.Bits.MTIM2

#define SCGC4_PTJ_MASK                  1U
#define SCGC4_FEC_MASK                  2U
#define SCGC4_MB_MASK                   4U
#define SCGC4_MC_MASK                   8U
#define SCGC4_MTIM2_MASK                16U


/*** SIMIPS - SIM Internal Peripheral Select Register; 0xFFFF810C ***/
typedef union {
  byte Byte;
  struct {
    byte MTIM1       :1;                                       /* MTIM1 External Clock Select */
    byte MTIM2       :1;                                       /* MTIM2 External Clock Selec */
    byte TPM1        :1;                                       /* TPM1 External Clock Select */
    byte TPM2        :1;                                       /* TPM2 External Clock Select */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpMTIM_1 :2;
    byte grpTPM_1 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SIMIPSSTR;
#define _SIMIPS (*(volatile SIMIPSSTR *)0xFFFF810C)
#define SIMIPS                          _SIMIPS.Byte
#define SIMIPS_MTIM1                    _SIMIPS.Bits.MTIM1
#define SIMIPS_MTIM2                    _SIMIPS.Bits.MTIM2
#define SIMIPS_TPM1                     _SIMIPS.Bits.TPM1
#define SIMIPS_TPM2                     _SIMIPS.Bits.TPM2
#define SIMIPS_MTIM_1                   _SIMIPS.MergedBits.grpMTIM_1
#define SIMIPS_TPM_1                    _SIMIPS.MergedBits.grpTPM_1
#define SIMIPS_MTIM                     SIMIPS_MTIM_1
#define SIMIPS_TPM                      SIMIPS_TPM_1

#define SIMIPS_MTIM1_MASK               1U
#define SIMIPS_MTIM2_MASK               2U
#define SIMIPS_TPM1_MASK                4U
#define SIMIPS_TPM2_MASK                8U
#define SIMIPS_MTIM_1_MASK              3U
#define SIMIPS_MTIM_1_BITNUM            0U
#define SIMIPS_TPM_1_MASK               12U
#define SIMIPS_TPM_1_BITNUM             2U


/*** SPMSC1 - System Power Management Status and Control 1 Register; 0xFFFF8120 ***/
typedef union {
  byte Byte;
  struct {
    byte BGBE        :1;                                       /* Bandgap Buffer Enable */
    byte             :1; 
    byte LVDE        :1;                                       /* Low-Voltage Detect Enable */
    byte LVDSE       :1;                                       /* Low-Voltage Detect Stop Enable */
    byte LVDRE       :1;                                       /* Low-Voltage Detect Reset Enable */
    byte LVDIE       :1;                                       /* Low-Voltage Detect Interrupt Enable */
    byte LVDACK      :1;                                       /* Low-Voltage Detect Acknowledge */
    byte LVDF        :1;                                       /* Low-Voltage Detect Flag */
  } Bits;
} SPMSC1STR;
#define _SPMSC1 (*(volatile SPMSC1STR *)0xFFFF8120)
#define SPMSC1                          _SPMSC1.Byte
#define SPMSC1_BGBE                     _SPMSC1.Bits.BGBE
#define SPMSC1_LVDE                     _SPMSC1.Bits.LVDE
#define SPMSC1_LVDSE                    _SPMSC1.Bits.LVDSE
#define SPMSC1_LVDRE                    _SPMSC1.Bits.LVDRE
#define SPMSC1_LVDIE                    _SPMSC1.Bits.LVDIE
#define SPMSC1_LVDACK                   _SPMSC1.Bits.LVDACK
#define SPMSC1_LVDF                     _SPMSC1.Bits.LVDF

#define SPMSC1_BGBE_MASK                1U
#define SPMSC1_LVDE_MASK                4U
#define SPMSC1_LVDSE_MASK               8U
#define SPMSC1_LVDRE_MASK               16U
#define SPMSC1_LVDIE_MASK               32U
#define SPMSC1_LVDACK_MASK              64U
#define SPMSC1_LVDF_MASK                128U


/*** SPMSC2 - System Power Management Status and Control 2 Register; 0xFFFF8121 ***/
typedef union {
  byte Byte;
  struct {
    byte PPDC        :1;                                       /* Partial Power Down Control */
    byte PPDE        :1;                                       /* Partial Power-Down Enable */
    byte PPDACK      :1;                                       /* Partial Power Down Acknowledge */
    byte PPDF        :1;                                       /* Partial Power Down Flag */
    byte             :1; 
    byte LPWUI       :1;                                       /* Low Power Wake Up on Interrupt */
    byte LPRS        :1;                                       /* Low Power Regulator Status */
    byte LPR         :1;                                       /* Low Power Regulator Control */
  } Bits;
} SPMSC2STR;
#define _SPMSC2 (*(volatile SPMSC2STR *)0xFFFF8121)
#define SPMSC2                          _SPMSC2.Byte
#define SPMSC2_PPDC                     _SPMSC2.Bits.PPDC
#define SPMSC2_PPDE                     _SPMSC2.Bits.PPDE
#define SPMSC2_PPDACK                   _SPMSC2.Bits.PPDACK
#define SPMSC2_PPDF                     _SPMSC2.Bits.PPDF
#define SPMSC2_LPWUI                    _SPMSC2.Bits.LPWUI
#define SPMSC2_LPRS                     _SPMSC2.Bits.LPRS
#define SPMSC2_LPR                      _SPMSC2.Bits.LPR

#define SPMSC2_PPDC_MASK                1U
#define SPMSC2_PPDE_MASK                2U
#define SPMSC2_PPDACK_MASK              4U
#define SPMSC2_PPDF_MASK                8U
#define SPMSC2_LPWUI_MASK               32U
#define SPMSC2_LPRS_MASK                64U
#define SPMSC2_LPR_MASK                 128U


/*** SPMSC3 - System Power Management Status and Control 3 Register; 0xFFFF8123 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LVWIE       :1;                                       /* Low-Voltage Warning Interrupt Enable */
    byte LVWV        :1;                                       /* Low-Voltage Warning Voltage Select */
    byte LVDV        :1;                                       /* Low-Voltage Detect Voltage Select */
    byte LVWACK      :1;                                       /* Low-Voltage Warning Acknowledge */
    byte LVWF        :1;                                       /* Low-Voltage Warning Flag */
  } Bits;
} SPMSC3STR;
#define _SPMSC3 (*(volatile SPMSC3STR *)0xFFFF8123)
#define SPMSC3                          _SPMSC3.Byte
#define SPMSC3_LVWIE                    _SPMSC3.Bits.LVWIE
#define SPMSC3_LVWV                     _SPMSC3.Bits.LVWV
#define SPMSC3_LVDV                     _SPMSC3.Bits.LVDV
#define SPMSC3_LVWACK                   _SPMSC3.Bits.LVWACK
#define SPMSC3_LVWF                     _SPMSC3.Bits.LVWF

#define SPMSC3_LVWIE_MASK               8U
#define SPMSC3_LVWV_MASK                16U
#define SPMSC3_LVDV_MASK                32U
#define SPMSC3_LVWACK_MASK              64U
#define SPMSC3_LVWF_MASK                128U


/*** ADCSC1 - Status and Control Register 1; 0xFFFF8140 ***/
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
#define _ADCSC1 (*(volatile ADCSC1STR *)0xFFFF8140)
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


/*** ADCSC2 - Status and Control Register 2; 0xFFFF8141 ***/
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
#define _ADCSC2 (*(volatile ADCSC2STR *)0xFFFF8141)
#define ADCSC2                          _ADCSC2.Byte
#define ADCSC2_ACFGT                    _ADCSC2.Bits.ACFGT
#define ADCSC2_ACFE                     _ADCSC2.Bits.ACFE
#define ADCSC2_ADTRG                    _ADCSC2.Bits.ADTRG
#define ADCSC2_ADACT                    _ADCSC2.Bits.ADACT

#define ADCSC2_ACFGT_MASK               16U
#define ADCSC2_ACFE_MASK                32U
#define ADCSC2_ADTRG_MASK               64U
#define ADCSC2_ADACT_MASK               128U


/*** ADCR - Data Result Register; 0xFFFF8142 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCRH - Data Result High Register; 0xFFFF8142 ***/
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
    

    /*** ADCRL - Data Result Low Register; 0xFFFF8143 ***/
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
#define _ADCR (*(volatile ADCRSTR *)0xFFFF8142)
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


/*** ADCCV - Compare Value Register; 0xFFFF8144 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCCVH - Compare Value High Register; 0xFFFF8144 ***/
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
    

    /*** ADCCVL - Compare Value Low Register; 0xFFFF8145 ***/
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
#define _ADCCV (*(volatile ADCCVSTR *)0xFFFF8144)
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


/*** ADCCFG - Configuration Register; 0xFFFF8146 ***/
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
#define _ADCCFG (*(volatile ADCCFGSTR *)0xFFFF8146)
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


/*** SCI1BD - SCI1 Baud Rate Register; 0xFFFF8160 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI1BDH - SCI1 Baud Rate Register High; 0xFFFF8160 ***/
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
    

    /*** SCI1BDL - SCI1 Baud Rate Register Low; 0xFFFF8161 ***/
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
#define _SCI1BD (*(volatile SCI1BDSTR *)0xFFFF8160)
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


/*** SCI1C1 - SCI1 Control Register 1; 0xFFFF8162 ***/
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
#define _SCI1C1 (*(volatile SCI1C1STR *)0xFFFF8162)
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


/*** SCI1C2 - SCI1 Control Register 2; 0xFFFF8163 ***/
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
#define _SCI1C2 (*(volatile SCI1C2STR *)0xFFFF8163)
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


/*** SCI1S1 - SCI1 Status Register 1; 0xFFFF8164 ***/
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
#define _SCI1S1 (*(volatile SCI1S1STR *)0xFFFF8164)
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


/*** SCI1S2 - SCI1 Status Register 2; 0xFFFF8165 ***/
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
#define _SCI1S2 (*(volatile SCI1S2STR *)0xFFFF8165)
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


/*** SCI1C3 - SCI1 Control Register 3; 0xFFFF8166 ***/
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
#define _SCI1C3 (*(volatile SCI1C3STR *)0xFFFF8166)
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


/*** SCI1D - SCI1 Data Register; 0xFFFF8167 ***/
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
#define _SCI1D (*(volatile SCI1DSTR *)0xFFFF8167)
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


/*** SCI2BD - SCI2 Baud Rate Register; 0xFFFF8180 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI2BDH - SCI2 Baud Rate Register High; 0xFFFF8180 ***/
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
    

    /*** SCI2BDL - SCI2 Baud Rate Register Low; 0xFFFF8181 ***/
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
#define _SCI2BD (*(volatile SCI2BDSTR *)0xFFFF8180)
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


/*** SCI2C1 - SCI2 Control Register 1; 0xFFFF8182 ***/
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
#define _SCI2C1 (*(volatile SCI2C1STR *)0xFFFF8182)
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


/*** SCI2C2 - SCI2 Control Register 2; 0xFFFF8183 ***/
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
#define _SCI2C2 (*(volatile SCI2C2STR *)0xFFFF8183)
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


/*** SCI2S1 - SCI2 Status Register 1; 0xFFFF8184 ***/
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
#define _SCI2S1 (*(volatile SCI2S1STR *)0xFFFF8184)
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


/*** SCI2S2 - SCI2 Status Register 2; 0xFFFF8185 ***/
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
#define _SCI2S2 (*(volatile SCI2S2STR *)0xFFFF8185)
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


/*** SCI2C3 - SCI2 Control Register 3; 0xFFFF8186 ***/
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
#define _SCI2C3 (*(volatile SCI2C3STR *)0xFFFF8186)
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


/*** SCI2D - SCI2 Data Register; 0xFFFF8187 ***/
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
#define _SCI2D (*(volatile SCI2DSTR *)0xFFFF8187)
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


/*** SCI3BD - SCI3 Baud Rate Register; 0xFFFF81A0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI3BDH - SCI3 Baud Rate Register High; 0xFFFF81A0 ***/
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
    } SCI3BDHSTR;
    #define SCI3BDH                     _SCI3BD.Overlap_STR.SCI3BDHSTR.Byte
    #define SCI3BDH_SBR8                _SCI3BD.Overlap_STR.SCI3BDHSTR.Bits.SBR8
    #define SCI3BDH_SBR9                _SCI3BD.Overlap_STR.SCI3BDHSTR.Bits.SBR9
    #define SCI3BDH_SBR10               _SCI3BD.Overlap_STR.SCI3BDHSTR.Bits.SBR10
    #define SCI3BDH_SBR11               _SCI3BD.Overlap_STR.SCI3BDHSTR.Bits.SBR11
    #define SCI3BDH_SBR12               _SCI3BD.Overlap_STR.SCI3BDHSTR.Bits.SBR12
    #define SCI3BDH_RXEDGIE             _SCI3BD.Overlap_STR.SCI3BDHSTR.Bits.RXEDGIE
    #define SCI3BDH_LBKDIE              _SCI3BD.Overlap_STR.SCI3BDHSTR.Bits.LBKDIE
    #define SCI3BDH_SBR_8               _SCI3BD.Overlap_STR.SCI3BDHSTR.MergedBits.grpSBR_8
    #define SCI3BDH_SBR                 SCI3BDH_SBR_8
    
    #define SCI3BDH_SBR8_MASK           1U
    #define SCI3BDH_SBR9_MASK           2U
    #define SCI3BDH_SBR10_MASK          4U
    #define SCI3BDH_SBR11_MASK          8U
    #define SCI3BDH_SBR12_MASK          16U
    #define SCI3BDH_RXEDGIE_MASK        64U
    #define SCI3BDH_LBKDIE_MASK         128U
    #define SCI3BDH_SBR_8_MASK          31U
    #define SCI3BDH_SBR_8_BITNUM        0U
    

    /*** SCI3BDL - SCI3 Baud Rate Register Low; 0xFFFF81A1 ***/
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
    } SCI3BDLSTR;
    #define SCI3BDL                     _SCI3BD.Overlap_STR.SCI3BDLSTR.Byte
    #define SCI3BDL_SBR0                _SCI3BD.Overlap_STR.SCI3BDLSTR.Bits.SBR0
    #define SCI3BDL_SBR1                _SCI3BD.Overlap_STR.SCI3BDLSTR.Bits.SBR1
    #define SCI3BDL_SBR2                _SCI3BD.Overlap_STR.SCI3BDLSTR.Bits.SBR2
    #define SCI3BDL_SBR3                _SCI3BD.Overlap_STR.SCI3BDLSTR.Bits.SBR3
    #define SCI3BDL_SBR4                _SCI3BD.Overlap_STR.SCI3BDLSTR.Bits.SBR4
    #define SCI3BDL_SBR5                _SCI3BD.Overlap_STR.SCI3BDLSTR.Bits.SBR5
    #define SCI3BDL_SBR6                _SCI3BD.Overlap_STR.SCI3BDLSTR.Bits.SBR6
    #define SCI3BDL_SBR7                _SCI3BD.Overlap_STR.SCI3BDLSTR.Bits.SBR7
    
    #define SCI3BDL_SBR0_MASK           1U
    #define SCI3BDL_SBR1_MASK           2U
    #define SCI3BDL_SBR2_MASK           4U
    #define SCI3BDL_SBR3_MASK           8U
    #define SCI3BDL_SBR4_MASK           16U
    #define SCI3BDL_SBR5_MASK           32U
    #define SCI3BDL_SBR6_MASK           64U
    #define SCI3BDL_SBR7_MASK           128U
    
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
} SCI3BDSTR;
#define _SCI3BD (*(volatile SCI3BDSTR *)0xFFFF81A0)
#define SCI3BD                          _SCI3BD.Word
#define SCI3BD_SBR0                     _SCI3BD.Bits.SBR0
#define SCI3BD_SBR1                     _SCI3BD.Bits.SBR1
#define SCI3BD_SBR2                     _SCI3BD.Bits.SBR2
#define SCI3BD_SBR3                     _SCI3BD.Bits.SBR3
#define SCI3BD_SBR4                     _SCI3BD.Bits.SBR4
#define SCI3BD_SBR5                     _SCI3BD.Bits.SBR5
#define SCI3BD_SBR6                     _SCI3BD.Bits.SBR6
#define SCI3BD_SBR7                     _SCI3BD.Bits.SBR7
#define SCI3BD_SBR8                     _SCI3BD.Bits.SBR8
#define SCI3BD_SBR9                     _SCI3BD.Bits.SBR9
#define SCI3BD_SBR10                    _SCI3BD.Bits.SBR10
#define SCI3BD_SBR11                    _SCI3BD.Bits.SBR11
#define SCI3BD_SBR12                    _SCI3BD.Bits.SBR12
#define SCI3BD_RXEDGIE                  _SCI3BD.Bits.RXEDGIE
#define SCI3BD_LBKDIE                   _SCI3BD.Bits.LBKDIE
#define SCI3BD_SBR                      _SCI3BD.MergedBits.grpSBR

#define SCI3BD_SBR0_MASK                1U
#define SCI3BD_SBR1_MASK                2U
#define SCI3BD_SBR2_MASK                4U
#define SCI3BD_SBR3_MASK                8U
#define SCI3BD_SBR4_MASK                16U
#define SCI3BD_SBR5_MASK                32U
#define SCI3BD_SBR6_MASK                64U
#define SCI3BD_SBR7_MASK                128U
#define SCI3BD_SBR8_MASK                256U
#define SCI3BD_SBR9_MASK                512U
#define SCI3BD_SBR10_MASK               1024U
#define SCI3BD_SBR11_MASK               2048U
#define SCI3BD_SBR12_MASK               4096U
#define SCI3BD_RXEDGIE_MASK             16384U
#define SCI3BD_LBKDIE_MASK              32768U
#define SCI3BD_SBR_MASK                 8191U
#define SCI3BD_SBR_BITNUM               0U


/*** SCI3C1 - SCI3 Control Register 1; 0xFFFF81A2 ***/
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
} SCI3C1STR;
#define _SCI3C1 (*(volatile SCI3C1STR *)0xFFFF81A2)
#define SCI3C1                          _SCI3C1.Byte
#define SCI3C1_PT                       _SCI3C1.Bits.PT
#define SCI3C1_PE                       _SCI3C1.Bits.PE
#define SCI3C1_ILT                      _SCI3C1.Bits.ILT
#define SCI3C1_WAKE                     _SCI3C1.Bits.WAKE
#define SCI3C1_M                        _SCI3C1.Bits.M
#define SCI3C1_RSRC                     _SCI3C1.Bits.RSRC
#define SCI3C1_SCISWAI                  _SCI3C1.Bits.SCISWAI
#define SCI3C1_LOOPS                    _SCI3C1.Bits.LOOPS

#define SCI3C1_PT_MASK                  1U
#define SCI3C1_PE_MASK                  2U
#define SCI3C1_ILT_MASK                 4U
#define SCI3C1_WAKE_MASK                8U
#define SCI3C1_M_MASK                   16U
#define SCI3C1_RSRC_MASK                32U
#define SCI3C1_SCISWAI_MASK             64U
#define SCI3C1_LOOPS_MASK               128U


/*** SCI3C2 - SCI3 Control Register 2; 0xFFFF81A3 ***/
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
} SCI3C2STR;
#define _SCI3C2 (*(volatile SCI3C2STR *)0xFFFF81A3)
#define SCI3C2                          _SCI3C2.Byte
#define SCI3C2_SBK                      _SCI3C2.Bits.SBK
#define SCI3C2_RWU                      _SCI3C2.Bits.RWU
#define SCI3C2_RE                       _SCI3C2.Bits.RE
#define SCI3C2_TE                       _SCI3C2.Bits.TE
#define SCI3C2_ILIE                     _SCI3C2.Bits.ILIE
#define SCI3C2_RIE                      _SCI3C2.Bits.RIE
#define SCI3C2_TCIE                     _SCI3C2.Bits.TCIE
#define SCI3C2_TIE                      _SCI3C2.Bits.TIE

#define SCI3C2_SBK_MASK                 1U
#define SCI3C2_RWU_MASK                 2U
#define SCI3C2_RE_MASK                  4U
#define SCI3C2_TE_MASK                  8U
#define SCI3C2_ILIE_MASK                16U
#define SCI3C2_RIE_MASK                 32U
#define SCI3C2_TCIE_MASK                64U
#define SCI3C2_TIE_MASK                 128U


/*** SCI3S1 - SCI3 Status Register 1; 0xFFFF81A4 ***/
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
} SCI3S1STR;
#define _SCI3S1 (*(volatile SCI3S1STR *)0xFFFF81A4)
#define SCI3S1                          _SCI3S1.Byte
#define SCI3S1_PF                       _SCI3S1.Bits.PF
#define SCI3S1_FE                       _SCI3S1.Bits.FE
#define SCI3S1_NF                       _SCI3S1.Bits.NF
#define SCI3S1_OR                       _SCI3S1.Bits.OR
#define SCI3S1_IDLE                     _SCI3S1.Bits.IDLE
#define SCI3S1_RDRF                     _SCI3S1.Bits.RDRF
#define SCI3S1_TC                       _SCI3S1.Bits.TC
#define SCI3S1_TDRE                     _SCI3S1.Bits.TDRE

#define SCI3S1_PF_MASK                  1U
#define SCI3S1_FE_MASK                  2U
#define SCI3S1_NF_MASK                  4U
#define SCI3S1_OR_MASK                  8U
#define SCI3S1_IDLE_MASK                16U
#define SCI3S1_RDRF_MASK                32U
#define SCI3S1_TC_MASK                  64U
#define SCI3S1_TDRE_MASK                128U


/*** SCI3S2 - SCI3 Status Register 2; 0xFFFF81A5 ***/
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
} SCI3S2STR;
#define _SCI3S2 (*(volatile SCI3S2STR *)0xFFFF81A5)
#define SCI3S2                          _SCI3S2.Byte
#define SCI3S2_RAF                      _SCI3S2.Bits.RAF
#define SCI3S2_LBKDE                    _SCI3S2.Bits.LBKDE
#define SCI3S2_BRK13                    _SCI3S2.Bits.BRK13
#define SCI3S2_RWUID                    _SCI3S2.Bits.RWUID
#define SCI3S2_RXINV                    _SCI3S2.Bits.RXINV
#define SCI3S2_RXEDGIF                  _SCI3S2.Bits.RXEDGIF
#define SCI3S2_LBKDIF                   _SCI3S2.Bits.LBKDIF

#define SCI3S2_RAF_MASK                 1U
#define SCI3S2_LBKDE_MASK               2U
#define SCI3S2_BRK13_MASK               4U
#define SCI3S2_RWUID_MASK               8U
#define SCI3S2_RXINV_MASK               16U
#define SCI3S2_RXEDGIF_MASK             64U
#define SCI3S2_LBKDIF_MASK              128U


/*** SCI3C3 - SCI3 Control Register 3; 0xFFFF81A6 ***/
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
} SCI3C3STR;
#define _SCI3C3 (*(volatile SCI3C3STR *)0xFFFF81A6)
#define SCI3C3                          _SCI3C3.Byte
#define SCI3C3_PEIE                     _SCI3C3.Bits.PEIE
#define SCI3C3_FEIE                     _SCI3C3.Bits.FEIE
#define SCI3C3_NEIE                     _SCI3C3.Bits.NEIE
#define SCI3C3_ORIE                     _SCI3C3.Bits.ORIE
#define SCI3C3_TXINV                    _SCI3C3.Bits.TXINV
#define SCI3C3_TXDIR                    _SCI3C3.Bits.TXDIR
#define SCI3C3_T8                       _SCI3C3.Bits.T8
#define SCI3C3_R8                       _SCI3C3.Bits.R8

#define SCI3C3_PEIE_MASK                1U
#define SCI3C3_FEIE_MASK                2U
#define SCI3C3_NEIE_MASK                4U
#define SCI3C3_ORIE_MASK                8U
#define SCI3C3_TXINV_MASK               16U
#define SCI3C3_TXDIR_MASK               32U
#define SCI3C3_T8_MASK                  64U
#define SCI3C3_R8_MASK                  128U


/*** SCI3D - SCI3 Data Register; 0xFFFF81A7 ***/
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
} SCI3DSTR;
#define _SCI3D (*(volatile SCI3DSTR *)0xFFFF81A7)
#define SCI3D                           _SCI3D.Byte
#define SCI3D_R0_T0                     _SCI3D.Bits.R0_T0
#define SCI3D_R1_T1                     _SCI3D.Bits.R1_T1
#define SCI3D_R2_T2                     _SCI3D.Bits.R2_T2
#define SCI3D_R3_T3                     _SCI3D.Bits.R3_T3
#define SCI3D_R4_T4                     _SCI3D.Bits.R4_T4
#define SCI3D_R5_T5                     _SCI3D.Bits.R5_T5
#define SCI3D_R6_T6                     _SCI3D.Bits.R6_T6
#define SCI3D_R7_T7                     _SCI3D.Bits.R7_T7

#define SCI3D_R0_T0_MASK                1U
#define SCI3D_R1_T1_MASK                2U
#define SCI3D_R2_T2_MASK                4U
#define SCI3D_R3_T3_MASK                8U
#define SCI3D_R4_T4_MASK                16U
#define SCI3D_R5_T5_MASK                32U
#define SCI3D_R6_T6_MASK                64U
#define SCI3D_R7_T7_MASK                128U


/*** SPI1C1 - SPI1 Control Register 1; 0xFFFF81C0 ***/
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
#define _SPI1C1 (*(volatile SPI1C1STR *)0xFFFF81C0)
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


/*** SPI1C2 - SPI1 Control Register 2; 0xFFFF81C1 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI Pin Control 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional Mode Output Enable */
    byte MODFEN      :1;                                       /* Master Mode-Fault Function Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SPI1C2STR;
#define _SPI1C2 (*(volatile SPI1C2STR *)0xFFFF81C1)
#define SPI1C2                          _SPI1C2.Byte
#define SPI1C2_SPC0                     _SPI1C2.Bits.SPC0
#define SPI1C2_SPISWAI                  _SPI1C2.Bits.SPISWAI
#define SPI1C2_BIDIROE                  _SPI1C2.Bits.BIDIROE
#define SPI1C2_MODFEN                   _SPI1C2.Bits.MODFEN

#define SPI1C2_SPC0_MASK                1U
#define SPI1C2_SPISWAI_MASK             2U
#define SPI1C2_BIDIROE_MASK             8U
#define SPI1C2_MODFEN_MASK              16U


/*** SPI1BR - SPI1 Baud Rate Register; 0xFFFF81C2 ***/
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
#define _SPI1BR (*(volatile SPI1BRSTR *)0xFFFF81C2)
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


/*** SPI1S - SPI1 Status Register; 0xFFFF81C3 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Master Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Buffer Empty Flag */
    byte             :1; 
    byte SPRF        :1;                                       /* SPI Read Buffer Full Flag */
  } Bits;
} SPI1SSTR;
#define _SPI1S (*(volatile SPI1SSTR *)0xFFFF81C3)
#define SPI1S                           _SPI1S.Byte
#define SPI1S_MODF                      _SPI1S.Bits.MODF
#define SPI1S_SPTEF                     _SPI1S.Bits.SPTEF
#define SPI1S_SPRF                      _SPI1S.Bits.SPRF

#define SPI1S_MODF_MASK                 16U
#define SPI1S_SPTEF_MASK                32U
#define SPI1S_SPRF_MASK                 128U


/*** SPI1D - SPI1 Data Register; 0xFFFF81C5 ***/
typedef union {
  byte Byte;
} SPI1DSTR;
#define _SPI1D (*(volatile SPI1DSTR *)0xFFFF81C5)
#define SPI1D                           _SPI1D.Byte


/*** SPI2C1 - SPI2 Control Register 1; 0xFFFF81E0 ***/
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
#define _SPI2C1 (*(volatile SPI2C1STR *)0xFFFF81E0)
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


/*** SPI2C2 - SPI2 Control Register 2; 0xFFFF81E1 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI Pin Control 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional Mode Output Enable */
    byte MODFEN      :1;                                       /* Master Mode-Fault Function Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SPI2C2STR;
#define _SPI2C2 (*(volatile SPI2C2STR *)0xFFFF81E1)
#define SPI2C2                          _SPI2C2.Byte
#define SPI2C2_SPC0                     _SPI2C2.Bits.SPC0
#define SPI2C2_SPISWAI                  _SPI2C2.Bits.SPISWAI
#define SPI2C2_BIDIROE                  _SPI2C2.Bits.BIDIROE
#define SPI2C2_MODFEN                   _SPI2C2.Bits.MODFEN

#define SPI2C2_SPC0_MASK                1U
#define SPI2C2_SPISWAI_MASK             2U
#define SPI2C2_BIDIROE_MASK             8U
#define SPI2C2_MODFEN_MASK              16U


/*** SPI2BR - SPI2 Baud Rate Register; 0xFFFF81E2 ***/
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
#define _SPI2BR (*(volatile SPI2BRSTR *)0xFFFF81E2)
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


/*** SPI2S - SPI2 Status Register; 0xFFFF81E3 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Master Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Buffer Empty Flag */
    byte             :1; 
    byte SPRF        :1;                                       /* SPI Read Buffer Full Flag */
  } Bits;
} SPI2SSTR;
#define _SPI2S (*(volatile SPI2SSTR *)0xFFFF81E3)
#define SPI2S                           _SPI2S.Byte
#define SPI2S_MODF                      _SPI2S.Bits.MODF
#define SPI2S_SPTEF                     _SPI2S.Bits.SPTEF
#define SPI2S_SPRF                      _SPI2S.Bits.SPRF

#define SPI2S_MODF_MASK                 16U
#define SPI2S_SPTEF_MASK                32U
#define SPI2S_SPRF_MASK                 128U


/*** SPI2D - SPI2 Data Register; 0xFFFF81E5 ***/
typedef union {
  byte Byte;
} SPI2DSTR;
#define _SPI2D (*(volatile SPI2DSTR *)0xFFFF81E5)
#define SPI2D                           _SPI2D.Byte


/*** IIC1A1 - IIC Address Register; 0xFFFF8200 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** IIC1A1 - IIC Address Register; Several registers at the same address ***/
    union {
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
        byte     :1;
        byte grpAD_1 :7;
      } MergedBits;
    } IIC1A1STR;
    #define IIC1A1                      _IIC1A1.Byte
    #define IIC1A1_AD1                  _IIC1A1.SameAddr_STR.IIC1A1STR.Bits.AD1
    #define IIC1A1_AD2                  _IIC1A1.SameAddr_STR.IIC1A1STR.Bits.AD2
    #define IIC1A1_AD3                  _IIC1A1.SameAddr_STR.IIC1A1STR.Bits.AD3
    #define IIC1A1_AD4                  _IIC1A1.SameAddr_STR.IIC1A1STR.Bits.AD4
    #define IIC1A1_AD5                  _IIC1A1.SameAddr_STR.IIC1A1STR.Bits.AD5
    #define IIC1A1_AD6                  _IIC1A1.SameAddr_STR.IIC1A1STR.Bits.AD6
    #define IIC1A1_AD7                  _IIC1A1.SameAddr_STR.IIC1A1STR.Bits.AD7
    #define IIC1A1_AD_1                 _IIC1A1.SameAddr_STR.IIC1A1STR.MergedBits.grpAD_1
    #define IIC1A1_AD                   IIC1A1_AD_1
    
    #define IIC1A1_AD1_MASK             2U
    #define IIC1A1_AD2_MASK             4U
    #define IIC1A1_AD3_MASK             8U
    #define IIC1A1_AD4_MASK             16U
    #define IIC1A1_AD5_MASK             32U
    #define IIC1A1_AD6_MASK             64U
    #define IIC1A1_AD7_MASK             128U
    #define IIC1A1_AD_1_MASK            254U
    #define IIC1A1_AD_1_BITNUM          1U
    
    /*** IIC1A - IIC Address Register; Several registers at the same address ***/
    union {
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
        byte     :1;
        byte grpAD_1 :7;
      } MergedBits;
    } IIC1ASTR;
    #define IIC1A                       _IIC1A1.Byte
    #define IIC1A_AD1                   _IIC1A1.SameAddr_STR.IIC1ASTR.Bits.AD1
    #define IIC1A_AD2                   _IIC1A1.SameAddr_STR.IIC1ASTR.Bits.AD2
    #define IIC1A_AD3                   _IIC1A1.SameAddr_STR.IIC1ASTR.Bits.AD3
    #define IIC1A_AD4                   _IIC1A1.SameAddr_STR.IIC1ASTR.Bits.AD4
    #define IIC1A_AD5                   _IIC1A1.SameAddr_STR.IIC1ASTR.Bits.AD5
    #define IIC1A_AD6                   _IIC1A1.SameAddr_STR.IIC1ASTR.Bits.AD6
    #define IIC1A_AD7                   _IIC1A1.SameAddr_STR.IIC1ASTR.Bits.AD7
    #define IIC1A_AD_1                  _IIC1A1.SameAddr_STR.IIC1ASTR.MergedBits.grpAD_1
    #define IIC1A_AD                    IIC1A_AD_1
    
    #define IIC1A_AD1_MASK              2U
    #define IIC1A_AD2_MASK              4U
    #define IIC1A_AD3_MASK              8U
    #define IIC1A_AD4_MASK              16U
    #define IIC1A_AD5_MASK              32U
    #define IIC1A_AD6_MASK              64U
    #define IIC1A_AD7_MASK              128U
    #define IIC1A_AD_1_MASK             254U
    #define IIC1A_AD_1_BITNUM           1U
    
  } SameAddr_STR; /*Several registers at the same address */

} IIC1A1STR;
#define _IIC1A1 (*(volatile IIC1A1STR *)0xFFFF8200)


/*** IIC1F - IIC Frequency Divider Register; 0xFFFF8201 ***/
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
#define _IIC1F (*(volatile IIC1FSTR *)0xFFFF8201)
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


/*** IIC1C1 - IIC Control Register 1; 0xFFFF8202 ***/
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
#define _IIC1C1 (*(volatile IIC1C1STR *)0xFFFF8202)


/*** IIC1S - IIC Status Register; 0xFFFF8203 ***/
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
#define _IIC1S (*(volatile IIC1SSTR *)0xFFFF8203)
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


/*** IIC1D - IIC Data I/O Register; 0xFFFF8204 ***/
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
#define _IIC1D (*(volatile IIC1DSTR *)0xFFFF8204)
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


/*** IIC1C2 - IIC Control Register 2; 0xFFFF8205 ***/
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
#define _IIC1C2 (*(volatile IIC1C2STR *)0xFFFF8205)
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


/*** IIC1SMB - SMBus Control and Status Register; 0xFFFF8206 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte SHTF        :1;                                       /* SCL High Timeout Flag */
    byte SLTF        :1;                                       /* SCL Low Timeout Flag */
    byte TCKSEL      :1;                                       /* Time Out Counter Clock Select */
    byte SIICAEN     :1;                                       /* Second IIC Address Enable */
    byte ALERTEN     :1;                                       /* SMBus Alert Response Address Enable */
    byte FACK        :1;                                       /* Fast NACK/ACK enable */
  } Bits;
} IIC1SMBSTR;
#define _IIC1SMB (*(volatile IIC1SMBSTR *)0xFFFF8206)
#define IIC1SMB                         _IIC1SMB.Byte
#define IIC1SMB_SHTF                    _IIC1SMB.Bits.SHTF
#define IIC1SMB_SLTF                    _IIC1SMB.Bits.SLTF
#define IIC1SMB_TCKSEL                  _IIC1SMB.Bits.TCKSEL
#define IIC1SMB_SIICAEN                 _IIC1SMB.Bits.SIICAEN
#define IIC1SMB_ALERTEN                 _IIC1SMB.Bits.ALERTEN
#define IIC1SMB_FACK                    _IIC1SMB.Bits.FACK

#define IIC1SMB_SHTF_MASK               4U
#define IIC1SMB_SLTF_MASK               8U
#define IIC1SMB_TCKSEL_MASK             16U
#define IIC1SMB_SIICAEN_MASK            32U
#define IIC1SMB_ALERTEN_MASK            64U
#define IIC1SMB_FACK_MASK               128U


/*** IIC1A2 - IIC Address Register 2; 0xFFFF8207 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte SAD1        :1;                                       /* SMBus Address Bit 1 */
    byte SAD2        :1;                                       /* SMBus Address Bit 2 */
    byte SAD3        :1;                                       /* SMBus Address Bit 3 */
    byte SAD4        :1;                                       /* SMBus Address Bit 4 */
    byte SAD5        :1;                                       /* SMBus Address Bit 5 */
    byte SAD6        :1;                                       /* SMBus Address Bit 6 */
    byte SAD7        :1;                                       /* SMBus Address Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpSAD_1 :7;
  } MergedBits;
} IIC1A2STR;
#define _IIC1A2 (*(volatile IIC1A2STR *)0xFFFF8207)
#define IIC1A2                          _IIC1A2.Byte
#define IIC1A2_SAD1                     _IIC1A2.Bits.SAD1
#define IIC1A2_SAD2                     _IIC1A2.Bits.SAD2
#define IIC1A2_SAD3                     _IIC1A2.Bits.SAD3
#define IIC1A2_SAD4                     _IIC1A2.Bits.SAD4
#define IIC1A2_SAD5                     _IIC1A2.Bits.SAD5
#define IIC1A2_SAD6                     _IIC1A2.Bits.SAD6
#define IIC1A2_SAD7                     _IIC1A2.Bits.SAD7
#define IIC1A2_SAD_1                    _IIC1A2.MergedBits.grpSAD_1
#define IIC1A2_SAD                      IIC1A2_SAD_1

#define IIC1A2_SAD1_MASK                2U
#define IIC1A2_SAD2_MASK                4U
#define IIC1A2_SAD3_MASK                8U
#define IIC1A2_SAD4_MASK                16U
#define IIC1A2_SAD5_MASK                32U
#define IIC1A2_SAD6_MASK                64U
#define IIC1A2_SAD7_MASK                128U
#define IIC1A2_SAD_1_MASK               254U
#define IIC1A2_SAD_1_BITNUM             1U


/*** IIC1SLT - IIC SCL Low Time Out register; 0xFFFF8208 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** IIC1SLTH - IIC SCL Low Time Out register - High byte; 0xFFFF8208 ***/
    union {
      byte Byte;
      struct {
        byte SSLT8       :1;                                       /* SCL Low Time Out Bit 8 */
        byte SSLT9       :1;                                       /* SCL Low Time Out Bit 9 */
        byte SSLT10      :1;                                       /* SCL Low Time Out Bit 10 */
        byte SSLT11      :1;                                       /* SCL Low Time Out Bit 11 */
        byte SSLT12      :1;                                       /* SCL Low Time Out Bit 12 */
        byte SSLT13      :1;                                       /* SCL Low Time Out Bit 13 */
        byte SSLT14      :1;                                       /* SCL Low Time Out Bit 14 */
        byte SSLT15      :1;                                       /* SCL Low Time Out Bit 15 */
      } Bits;
    } IIC1SLTHSTR;
    #define IIC1SLTH                    _IIC1SLT.Overlap_STR.IIC1SLTHSTR.Byte
    #define IIC1SLTH_SSLT8              _IIC1SLT.Overlap_STR.IIC1SLTHSTR.Bits.SSLT8
    #define IIC1SLTH_SSLT9              _IIC1SLT.Overlap_STR.IIC1SLTHSTR.Bits.SSLT9
    #define IIC1SLTH_SSLT10             _IIC1SLT.Overlap_STR.IIC1SLTHSTR.Bits.SSLT10
    #define IIC1SLTH_SSLT11             _IIC1SLT.Overlap_STR.IIC1SLTHSTR.Bits.SSLT11
    #define IIC1SLTH_SSLT12             _IIC1SLT.Overlap_STR.IIC1SLTHSTR.Bits.SSLT12
    #define IIC1SLTH_SSLT13             _IIC1SLT.Overlap_STR.IIC1SLTHSTR.Bits.SSLT13
    #define IIC1SLTH_SSLT14             _IIC1SLT.Overlap_STR.IIC1SLTHSTR.Bits.SSLT14
    #define IIC1SLTH_SSLT15             _IIC1SLT.Overlap_STR.IIC1SLTHSTR.Bits.SSLT15
    
    #define IIC1SLTH_SSLT8_MASK         1U
    #define IIC1SLTH_SSLT9_MASK         2U
    #define IIC1SLTH_SSLT10_MASK        4U
    #define IIC1SLTH_SSLT11_MASK        8U
    #define IIC1SLTH_SSLT12_MASK        16U
    #define IIC1SLTH_SSLT13_MASK        32U
    #define IIC1SLTH_SSLT14_MASK        64U
    #define IIC1SLTH_SSLT15_MASK        128U
    

    /*** IIC1SLTL - IIC SCL Low Time Out register - Low byte; 0xFFFF8209 ***/
    union {
      byte Byte;
      struct {
        byte SSLT0       :1;                                       /* SCL Low Time Out Bits, bit 0 */
        byte SSLT1       :1;                                       /* SCL Low Time Out Bits, bit 1 */
        byte SSLT2       :1;                                       /* SCL Low Time Out Bits, bit 2 */
        byte SSLT3       :1;                                       /* SCL Low Time Out Bits, bit 3 */
        byte SSLT4       :1;                                       /* SCL Low Time Out Bits, bit 4 */
        byte SSLT5       :1;                                       /* SCL Low Time Out Bits, bit 5 */
        byte SSLT6       :1;                                       /* SCL Low Time Out Bits, bit 6 */
        byte SSLT7       :1;                                       /* SCL Low Time Out Bits, bit 7 */
      } Bits;
    } IIC1SLTLSTR;
    #define IIC1SLTL                    _IIC1SLT.Overlap_STR.IIC1SLTLSTR.Byte
    #define IIC1SLTL_SSLT0              _IIC1SLT.Overlap_STR.IIC1SLTLSTR.Bits.SSLT0
    #define IIC1SLTL_SSLT1              _IIC1SLT.Overlap_STR.IIC1SLTLSTR.Bits.SSLT1
    #define IIC1SLTL_SSLT2              _IIC1SLT.Overlap_STR.IIC1SLTLSTR.Bits.SSLT2
    #define IIC1SLTL_SSLT3              _IIC1SLT.Overlap_STR.IIC1SLTLSTR.Bits.SSLT3
    #define IIC1SLTL_SSLT4              _IIC1SLT.Overlap_STR.IIC1SLTLSTR.Bits.SSLT4
    #define IIC1SLTL_SSLT5              _IIC1SLT.Overlap_STR.IIC1SLTLSTR.Bits.SSLT5
    #define IIC1SLTL_SSLT6              _IIC1SLT.Overlap_STR.IIC1SLTLSTR.Bits.SSLT6
    #define IIC1SLTL_SSLT7              _IIC1SLT.Overlap_STR.IIC1SLTLSTR.Bits.SSLT7
    
    #define IIC1SLTL_SSLT0_MASK         1U
    #define IIC1SLTL_SSLT1_MASK         2U
    #define IIC1SLTL_SSLT2_MASK         4U
    #define IIC1SLTL_SSLT3_MASK         8U
    #define IIC1SLTL_SSLT4_MASK         16U
    #define IIC1SLTL_SSLT5_MASK         32U
    #define IIC1SLTL_SSLT6_MASK         64U
    #define IIC1SLTL_SSLT7_MASK         128U
    
  } Overlap_STR;

  struct {
    word SSLT0       :1;                                       /* SCL Low Time Out Bits, bit 0 */
    word SSLT1       :1;                                       /* SCL Low Time Out Bits, bit 1 */
    word SSLT2       :1;                                       /* SCL Low Time Out Bits, bit 2 */
    word SSLT3       :1;                                       /* SCL Low Time Out Bits, bit 3 */
    word SSLT4       :1;                                       /* SCL Low Time Out Bits, bit 4 */
    word SSLT5       :1;                                       /* SCL Low Time Out Bits, bit 5 */
    word SSLT6       :1;                                       /* SCL Low Time Out Bits, bit 6 */
    word SSLT7       :1;                                       /* SCL Low Time Out Bits, bit 7 */
    word SSLT8       :1;                                       /* SCL Low Time Out Bits, bit 8 */
    word SSLT9       :1;                                       /* SCL Low Time Out Bits, bit 9 */
    word SSLT10      :1;                                       /* SCL Low Time Out Bits, bit 10 */
    word SSLT11      :1;                                       /* SCL Low Time Out Bits, bit 11 */
    word SSLT12      :1;                                       /* SCL Low Time Out Bits, bit 12 */
    word SSLT13      :1;                                       /* SCL Low Time Out Bits, bit 13 */
    word SSLT14      :1;                                       /* SCL Low Time Out Bits, bit 14 */
    word SSLT15      :1;                                       /* SCL Low Time Out Bits, bit 15 */
  } Bits;
} IIC1SLTSTR;
#define _IIC1SLT (*(volatile IIC1SLTSTR *)0xFFFF8208)
#define IIC1SLT                         _IIC1SLT.Word
#define IIC1SLT_SSLT0                   _IIC1SLT.Bits.SSLT0
#define IIC1SLT_SSLT1                   _IIC1SLT.Bits.SSLT1
#define IIC1SLT_SSLT2                   _IIC1SLT.Bits.SSLT2
#define IIC1SLT_SSLT3                   _IIC1SLT.Bits.SSLT3
#define IIC1SLT_SSLT4                   _IIC1SLT.Bits.SSLT4
#define IIC1SLT_SSLT5                   _IIC1SLT.Bits.SSLT5
#define IIC1SLT_SSLT6                   _IIC1SLT.Bits.SSLT6
#define IIC1SLT_SSLT7                   _IIC1SLT.Bits.SSLT7
#define IIC1SLT_SSLT8                   _IIC1SLT.Bits.SSLT8
#define IIC1SLT_SSLT9                   _IIC1SLT.Bits.SSLT9
#define IIC1SLT_SSLT10                  _IIC1SLT.Bits.SSLT10
#define IIC1SLT_SSLT11                  _IIC1SLT.Bits.SSLT11
#define IIC1SLT_SSLT12                  _IIC1SLT.Bits.SSLT12
#define IIC1SLT_SSLT13                  _IIC1SLT.Bits.SSLT13
#define IIC1SLT_SSLT14                  _IIC1SLT.Bits.SSLT14
#define IIC1SLT_SSLT15                  _IIC1SLT.Bits.SSLT15

#define IIC1SLT_SSLT0_MASK              1U
#define IIC1SLT_SSLT1_MASK              2U
#define IIC1SLT_SSLT2_MASK              4U
#define IIC1SLT_SSLT3_MASK              8U
#define IIC1SLT_SSLT4_MASK              16U
#define IIC1SLT_SSLT5_MASK              32U
#define IIC1SLT_SSLT6_MASK              64U
#define IIC1SLT_SSLT7_MASK              128U
#define IIC1SLT_SSLT8_MASK              256U
#define IIC1SLT_SSLT9_MASK              512U
#define IIC1SLT_SSLT10_MASK             1024U
#define IIC1SLT_SSLT11_MASK             2048U
#define IIC1SLT_SSLT12_MASK             4096U
#define IIC1SLT_SSLT13_MASK             8192U
#define IIC1SLT_SSLT14_MASK             16384U
#define IIC1SLT_SSLT15_MASK             32768U


/*** IIC1FLT - IIC Filter register; 0xFFFF820A ***/
typedef union {
  byte Byte;
  struct {
    byte FLT0        :1;                                       /* Filter value bit 0 */
    byte FLT1        :1;                                       /* Filter value bit 1 */
    byte FLT2        :1;                                       /* Filter value bit 2 */
    byte FLT3        :1;                                       /* Filter value bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFLT  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} IIC1FLTSTR;
#define _IIC1FLT (*(volatile IIC1FLTSTR *)0xFFFF820A)
#define IIC1FLT                         _IIC1FLT.Byte
#define IIC1FLT_FLT0                    _IIC1FLT.Bits.FLT0
#define IIC1FLT_FLT1                    _IIC1FLT.Bits.FLT1
#define IIC1FLT_FLT2                    _IIC1FLT.Bits.FLT2
#define IIC1FLT_FLT3                    _IIC1FLT.Bits.FLT3
#define IIC1FLT_FLT                     _IIC1FLT.MergedBits.grpFLT

#define IIC1FLT_FLT0_MASK               1U
#define IIC1FLT_FLT1_MASK               2U
#define IIC1FLT_FLT2_MASK               4U
#define IIC1FLT_FLT3_MASK               8U
#define IIC1FLT_FLT_MASK                15U
#define IIC1FLT_FLT_BITNUM              0U


/*** IIC2A1 - IIC Address Register; 0xFFFF8220 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** IIC2A1 - IIC Address Register; Several registers at the same address ***/
    union {
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
        byte     :1;
        byte grpAD_1 :7;
      } MergedBits;
    } IIC2A1STR;
    #define IIC2A1                      _IIC2A1.Byte
    #define IIC2A1_AD1                  _IIC2A1.SameAddr_STR.IIC2A1STR.Bits.AD1
    #define IIC2A1_AD2                  _IIC2A1.SameAddr_STR.IIC2A1STR.Bits.AD2
    #define IIC2A1_AD3                  _IIC2A1.SameAddr_STR.IIC2A1STR.Bits.AD3
    #define IIC2A1_AD4                  _IIC2A1.SameAddr_STR.IIC2A1STR.Bits.AD4
    #define IIC2A1_AD5                  _IIC2A1.SameAddr_STR.IIC2A1STR.Bits.AD5
    #define IIC2A1_AD6                  _IIC2A1.SameAddr_STR.IIC2A1STR.Bits.AD6
    #define IIC2A1_AD7                  _IIC2A1.SameAddr_STR.IIC2A1STR.Bits.AD7
    #define IIC2A1_AD_1                 _IIC2A1.SameAddr_STR.IIC2A1STR.MergedBits.grpAD_1
    #define IIC2A1_AD                   IIC2A1_AD_1
    
    #define IIC2A1_AD1_MASK             2U
    #define IIC2A1_AD2_MASK             4U
    #define IIC2A1_AD3_MASK             8U
    #define IIC2A1_AD4_MASK             16U
    #define IIC2A1_AD5_MASK             32U
    #define IIC2A1_AD6_MASK             64U
    #define IIC2A1_AD7_MASK             128U
    #define IIC2A1_AD_1_MASK            254U
    #define IIC2A1_AD_1_BITNUM          1U
    
    /*** IIC2A - IIC Address Register; Several registers at the same address ***/
    union {
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
        byte     :1;
        byte grpAD_1 :7;
      } MergedBits;
    } IIC2ASTR;
    #define IIC2A                       _IIC2A1.Byte
    #define IIC2A_AD1                   _IIC2A1.SameAddr_STR.IIC2ASTR.Bits.AD1
    #define IIC2A_AD2                   _IIC2A1.SameAddr_STR.IIC2ASTR.Bits.AD2
    #define IIC2A_AD3                   _IIC2A1.SameAddr_STR.IIC2ASTR.Bits.AD3
    #define IIC2A_AD4                   _IIC2A1.SameAddr_STR.IIC2ASTR.Bits.AD4
    #define IIC2A_AD5                   _IIC2A1.SameAddr_STR.IIC2ASTR.Bits.AD5
    #define IIC2A_AD6                   _IIC2A1.SameAddr_STR.IIC2ASTR.Bits.AD6
    #define IIC2A_AD7                   _IIC2A1.SameAddr_STR.IIC2ASTR.Bits.AD7
    #define IIC2A_AD_1                  _IIC2A1.SameAddr_STR.IIC2ASTR.MergedBits.grpAD_1
    #define IIC2A_AD                    IIC2A_AD_1
    
    #define IIC2A_AD1_MASK              2U
    #define IIC2A_AD2_MASK              4U
    #define IIC2A_AD3_MASK              8U
    #define IIC2A_AD4_MASK              16U
    #define IIC2A_AD5_MASK              32U
    #define IIC2A_AD6_MASK              64U
    #define IIC2A_AD7_MASK              128U
    #define IIC2A_AD_1_MASK             254U
    #define IIC2A_AD_1_BITNUM           1U
    
  } SameAddr_STR; /*Several registers at the same address */

} IIC2A1STR;
#define _IIC2A1 (*(volatile IIC2A1STR *)0xFFFF8220)


/*** IIC2F - IIC Frequency Divider Register; 0xFFFF8221 ***/
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
#define _IIC2F (*(volatile IIC2FSTR *)0xFFFF8221)
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


/*** IIC2C1 - IIC Control Register 1; 0xFFFF8222 ***/
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
#define _IIC2C1 (*(volatile IIC2C1STR *)0xFFFF8222)


/*** IIC2S - IIC Status Register; 0xFFFF8223 ***/
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
#define _IIC2S (*(volatile IIC2SSTR *)0xFFFF8223)
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


/*** IIC2D - IIC Data I/O Register; 0xFFFF8224 ***/
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
#define _IIC2D (*(volatile IIC2DSTR *)0xFFFF8224)
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


/*** IIC2C2 - IIC Control Register 2; 0xFFFF8225 ***/
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
#define _IIC2C2 (*(volatile IIC2C2STR *)0xFFFF8225)
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


/*** IIC2SMB - SMBus Control and Status Register; 0xFFFF8226 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte SHTF        :1;                                       /* SCL High Timeout Flag */
    byte SLTF        :1;                                       /* SCL Low Timeout Flag */
    byte TCKSEL      :1;                                       /* Time Out Counter Clock Select */
    byte SIICAEN     :1;                                       /* Second IIC Address Enable */
    byte ALERTEN     :1;                                       /* SMBus Alert Response Address Enable */
    byte FACK        :1;                                       /* Fast NACK/ACK enable */
  } Bits;
} IIC2SMBSTR;
#define _IIC2SMB (*(volatile IIC2SMBSTR *)0xFFFF8226)
#define IIC2SMB                         _IIC2SMB.Byte
#define IIC2SMB_SHTF                    _IIC2SMB.Bits.SHTF
#define IIC2SMB_SLTF                    _IIC2SMB.Bits.SLTF
#define IIC2SMB_TCKSEL                  _IIC2SMB.Bits.TCKSEL
#define IIC2SMB_SIICAEN                 _IIC2SMB.Bits.SIICAEN
#define IIC2SMB_ALERTEN                 _IIC2SMB.Bits.ALERTEN
#define IIC2SMB_FACK                    _IIC2SMB.Bits.FACK

#define IIC2SMB_SHTF_MASK               4U
#define IIC2SMB_SLTF_MASK               8U
#define IIC2SMB_TCKSEL_MASK             16U
#define IIC2SMB_SIICAEN_MASK            32U
#define IIC2SMB_ALERTEN_MASK            64U
#define IIC2SMB_FACK_MASK               128U


/*** IIC2A2 - IIC Address Register 2; 0xFFFF8227 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte SAD1        :1;                                       /* SMBus Address Bit 1 */
    byte SAD2        :1;                                       /* SMBus Address Bit 2 */
    byte SAD3        :1;                                       /* SMBus Address Bit 3 */
    byte SAD4        :1;                                       /* SMBus Address Bit 4 */
    byte SAD5        :1;                                       /* SMBus Address Bit 5 */
    byte SAD6        :1;                                       /* SMBus Address Bit 6 */
    byte SAD7        :1;                                       /* SMBus Address Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpSAD_1 :7;
  } MergedBits;
} IIC2A2STR;
#define _IIC2A2 (*(volatile IIC2A2STR *)0xFFFF8227)
#define IIC2A2                          _IIC2A2.Byte
#define IIC2A2_SAD1                     _IIC2A2.Bits.SAD1
#define IIC2A2_SAD2                     _IIC2A2.Bits.SAD2
#define IIC2A2_SAD3                     _IIC2A2.Bits.SAD3
#define IIC2A2_SAD4                     _IIC2A2.Bits.SAD4
#define IIC2A2_SAD5                     _IIC2A2.Bits.SAD5
#define IIC2A2_SAD6                     _IIC2A2.Bits.SAD6
#define IIC2A2_SAD7                     _IIC2A2.Bits.SAD7
#define IIC2A2_SAD_1                    _IIC2A2.MergedBits.grpSAD_1
#define IIC2A2_SAD                      IIC2A2_SAD_1

#define IIC2A2_SAD1_MASK                2U
#define IIC2A2_SAD2_MASK                4U
#define IIC2A2_SAD3_MASK                8U
#define IIC2A2_SAD4_MASK                16U
#define IIC2A2_SAD5_MASK                32U
#define IIC2A2_SAD6_MASK                64U
#define IIC2A2_SAD7_MASK                128U
#define IIC2A2_SAD_1_MASK               254U
#define IIC2A2_SAD_1_BITNUM             1U


/*** IIC2SLT - IIC SCL Low Time Out register; 0xFFFF8228 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** IIC2SLTH - IIC SCL Low Time Out register - High byte; 0xFFFF8228 ***/
    union {
      byte Byte;
      struct {
        byte SSLT8       :1;                                       /* SCL Low Time Out Bit 8 */
        byte SSLT9       :1;                                       /* SCL Low Time Out Bit 9 */
        byte SSLT10      :1;                                       /* SCL Low Time Out Bit 10 */
        byte SSLT11      :1;                                       /* SCL Low Time Out Bit 11 */
        byte SSLT12      :1;                                       /* SCL Low Time Out Bit 12 */
        byte SSLT13      :1;                                       /* SCL Low Time Out Bit 13 */
        byte SSLT14      :1;                                       /* SCL Low Time Out Bit 14 */
        byte SSLT15      :1;                                       /* SCL Low Time Out Bit 15 */
      } Bits;
    } IIC2SLTHSTR;
    #define IIC2SLTH                    _IIC2SLT.Overlap_STR.IIC2SLTHSTR.Byte
    #define IIC2SLTH_SSLT8              _IIC2SLT.Overlap_STR.IIC2SLTHSTR.Bits.SSLT8
    #define IIC2SLTH_SSLT9              _IIC2SLT.Overlap_STR.IIC2SLTHSTR.Bits.SSLT9
    #define IIC2SLTH_SSLT10             _IIC2SLT.Overlap_STR.IIC2SLTHSTR.Bits.SSLT10
    #define IIC2SLTH_SSLT11             _IIC2SLT.Overlap_STR.IIC2SLTHSTR.Bits.SSLT11
    #define IIC2SLTH_SSLT12             _IIC2SLT.Overlap_STR.IIC2SLTHSTR.Bits.SSLT12
    #define IIC2SLTH_SSLT13             _IIC2SLT.Overlap_STR.IIC2SLTHSTR.Bits.SSLT13
    #define IIC2SLTH_SSLT14             _IIC2SLT.Overlap_STR.IIC2SLTHSTR.Bits.SSLT14
    #define IIC2SLTH_SSLT15             _IIC2SLT.Overlap_STR.IIC2SLTHSTR.Bits.SSLT15
    
    #define IIC2SLTH_SSLT8_MASK         1U
    #define IIC2SLTH_SSLT9_MASK         2U
    #define IIC2SLTH_SSLT10_MASK        4U
    #define IIC2SLTH_SSLT11_MASK        8U
    #define IIC2SLTH_SSLT12_MASK        16U
    #define IIC2SLTH_SSLT13_MASK        32U
    #define IIC2SLTH_SSLT14_MASK        64U
    #define IIC2SLTH_SSLT15_MASK        128U
    

    /*** IIC2SLTL - IIC SCL Low Time Out register - Low byte; 0xFFFF8229 ***/
    union {
      byte Byte;
      struct {
        byte SSLT0       :1;                                       /* SCL Low Time Out Bits, bit 0 */
        byte SSLT1       :1;                                       /* SCL Low Time Out Bits, bit 1 */
        byte SSLT2       :1;                                       /* SCL Low Time Out Bits, bit 2 */
        byte SSLT3       :1;                                       /* SCL Low Time Out Bits, bit 3 */
        byte SSLT4       :1;                                       /* SCL Low Time Out Bits, bit 4 */
        byte SSLT5       :1;                                       /* SCL Low Time Out Bits, bit 5 */
        byte SSLT6       :1;                                       /* SCL Low Time Out Bits, bit 6 */
        byte SSLT7       :1;                                       /* SCL Low Time Out Bits, bit 7 */
      } Bits;
    } IIC2SLTLSTR;
    #define IIC2SLTL                    _IIC2SLT.Overlap_STR.IIC2SLTLSTR.Byte
    #define IIC2SLTL_SSLT0              _IIC2SLT.Overlap_STR.IIC2SLTLSTR.Bits.SSLT0
    #define IIC2SLTL_SSLT1              _IIC2SLT.Overlap_STR.IIC2SLTLSTR.Bits.SSLT1
    #define IIC2SLTL_SSLT2              _IIC2SLT.Overlap_STR.IIC2SLTLSTR.Bits.SSLT2
    #define IIC2SLTL_SSLT3              _IIC2SLT.Overlap_STR.IIC2SLTLSTR.Bits.SSLT3
    #define IIC2SLTL_SSLT4              _IIC2SLT.Overlap_STR.IIC2SLTLSTR.Bits.SSLT4
    #define IIC2SLTL_SSLT5              _IIC2SLT.Overlap_STR.IIC2SLTLSTR.Bits.SSLT5
    #define IIC2SLTL_SSLT6              _IIC2SLT.Overlap_STR.IIC2SLTLSTR.Bits.SSLT6
    #define IIC2SLTL_SSLT7              _IIC2SLT.Overlap_STR.IIC2SLTLSTR.Bits.SSLT7
    
    #define IIC2SLTL_SSLT0_MASK         1U
    #define IIC2SLTL_SSLT1_MASK         2U
    #define IIC2SLTL_SSLT2_MASK         4U
    #define IIC2SLTL_SSLT3_MASK         8U
    #define IIC2SLTL_SSLT4_MASK         16U
    #define IIC2SLTL_SSLT5_MASK         32U
    #define IIC2SLTL_SSLT6_MASK         64U
    #define IIC2SLTL_SSLT7_MASK         128U
    
  } Overlap_STR;

  struct {
    word SSLT0       :1;                                       /* SCL Low Time Out Bits, bit 0 */
    word SSLT1       :1;                                       /* SCL Low Time Out Bits, bit 1 */
    word SSLT2       :1;                                       /* SCL Low Time Out Bits, bit 2 */
    word SSLT3       :1;                                       /* SCL Low Time Out Bits, bit 3 */
    word SSLT4       :1;                                       /* SCL Low Time Out Bits, bit 4 */
    word SSLT5       :1;                                       /* SCL Low Time Out Bits, bit 5 */
    word SSLT6       :1;                                       /* SCL Low Time Out Bits, bit 6 */
    word SSLT7       :1;                                       /* SCL Low Time Out Bits, bit 7 */
    word SSLT8       :1;                                       /* SCL Low Time Out Bits, bit 8 */
    word SSLT9       :1;                                       /* SCL Low Time Out Bits, bit 9 */
    word SSLT10      :1;                                       /* SCL Low Time Out Bits, bit 10 */
    word SSLT11      :1;                                       /* SCL Low Time Out Bits, bit 11 */
    word SSLT12      :1;                                       /* SCL Low Time Out Bits, bit 12 */
    word SSLT13      :1;                                       /* SCL Low Time Out Bits, bit 13 */
    word SSLT14      :1;                                       /* SCL Low Time Out Bits, bit 14 */
    word SSLT15      :1;                                       /* SCL Low Time Out Bits, bit 15 */
  } Bits;
} IIC2SLTSTR;
#define _IIC2SLT (*(volatile IIC2SLTSTR *)0xFFFF8228)
#define IIC2SLT                         _IIC2SLT.Word
#define IIC2SLT_SSLT0                   _IIC2SLT.Bits.SSLT0
#define IIC2SLT_SSLT1                   _IIC2SLT.Bits.SSLT1
#define IIC2SLT_SSLT2                   _IIC2SLT.Bits.SSLT2
#define IIC2SLT_SSLT3                   _IIC2SLT.Bits.SSLT3
#define IIC2SLT_SSLT4                   _IIC2SLT.Bits.SSLT4
#define IIC2SLT_SSLT5                   _IIC2SLT.Bits.SSLT5
#define IIC2SLT_SSLT6                   _IIC2SLT.Bits.SSLT6
#define IIC2SLT_SSLT7                   _IIC2SLT.Bits.SSLT7
#define IIC2SLT_SSLT8                   _IIC2SLT.Bits.SSLT8
#define IIC2SLT_SSLT9                   _IIC2SLT.Bits.SSLT9
#define IIC2SLT_SSLT10                  _IIC2SLT.Bits.SSLT10
#define IIC2SLT_SSLT11                  _IIC2SLT.Bits.SSLT11
#define IIC2SLT_SSLT12                  _IIC2SLT.Bits.SSLT12
#define IIC2SLT_SSLT13                  _IIC2SLT.Bits.SSLT13
#define IIC2SLT_SSLT14                  _IIC2SLT.Bits.SSLT14
#define IIC2SLT_SSLT15                  _IIC2SLT.Bits.SSLT15

#define IIC2SLT_SSLT0_MASK              1U
#define IIC2SLT_SSLT1_MASK              2U
#define IIC2SLT_SSLT2_MASK              4U
#define IIC2SLT_SSLT3_MASK              8U
#define IIC2SLT_SSLT4_MASK              16U
#define IIC2SLT_SSLT5_MASK              32U
#define IIC2SLT_SSLT6_MASK              64U
#define IIC2SLT_SSLT7_MASK              128U
#define IIC2SLT_SSLT8_MASK              256U
#define IIC2SLT_SSLT9_MASK              512U
#define IIC2SLT_SSLT10_MASK             1024U
#define IIC2SLT_SSLT11_MASK             2048U
#define IIC2SLT_SSLT12_MASK             4096U
#define IIC2SLT_SSLT13_MASK             8192U
#define IIC2SLT_SSLT14_MASK             16384U
#define IIC2SLT_SSLT15_MASK             32768U


/*** IIC2FLT - IIC Filter register; 0xFFFF822A ***/
typedef union {
  byte Byte;
  struct {
    byte FLT0        :1;                                       /* Filter value bit 0 */
    byte FLT1        :1;                                       /* Filter value bit 1 */
    byte FLT2        :1;                                       /* Filter value bit 2 */
    byte FLT3        :1;                                       /* Filter value bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFLT  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} IIC2FLTSTR;
#define _IIC2FLT (*(volatile IIC2FLTSTR *)0xFFFF822A)
#define IIC2FLT                         _IIC2FLT.Byte
#define IIC2FLT_FLT0                    _IIC2FLT.Bits.FLT0
#define IIC2FLT_FLT1                    _IIC2FLT.Bits.FLT1
#define IIC2FLT_FLT2                    _IIC2FLT.Bits.FLT2
#define IIC2FLT_FLT3                    _IIC2FLT.Bits.FLT3
#define IIC2FLT_FLT                     _IIC2FLT.MergedBits.grpFLT

#define IIC2FLT_FLT0_MASK               1U
#define IIC2FLT_FLT1_MASK               2U
#define IIC2FLT_FLT2_MASK               4U
#define IIC2FLT_FLT3_MASK               8U
#define IIC2FLT_FLT_MASK                15U
#define IIC2FLT_FLT_BITNUM              0U


/*** MCGC1 - MCG Control Register 1; 0xFFFF8240 ***/
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
#define _MCGC1 (*(volatile MCGC1STR *)0xFFFF8240)
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


/*** MCGC2 - MCG Control Register 2; 0xFFFF8241 ***/
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
#define _MCGC2 (*(volatile MCGC2STR *)0xFFFF8241)
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


/*** MCGTRM - MCG Trim Register; 0xFFFF8242 ***/
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
#define _MCGTRM (*(volatile MCGTRMSTR *)0xFFFF8242)
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


/*** MCGSC - MCG Status and Control Register; 0xFFFF8243 ***/
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
#define _MCGSC (*(volatile MCGSCSTR *)0xFFFF8243)
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


/*** MCGC3 - MCG Control Register 3; 0xFFFF8244 ***/
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
#define _MCGC3 (*(volatile MCGC3STR *)0xFFFF8244)
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


/*** MCGC4 - MCG Control Register 4; 0xFFFF8245 ***/
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
#define _MCGC4 (*(volatile MCGC4STR *)0xFFFF8245)
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


/*** TPM1SC - TPM1 Status and Control Register; 0xFFFF8260 ***/
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
#define _TPM1SC (*(volatile TPM1SCSTR *)0xFFFF8260)
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


/*** TPM1CNT - TPM1 Timer Counter Register; 0xFFFF8261 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1CNTH - TPM1 Timer Counter Register High; 0xFFFF8261 ***/
    union {
      byte Byte;
    } TPM1CNTHSTR;
    #define TPM1CNTH                    _TPM1CNT.Overlap_STR.TPM1CNTHSTR.Byte
    

    /*** TPM1CNTL - TPM1 Timer Counter Register Low; 0xFFFF8262 ***/
    union {
      byte Byte;
    } TPM1CNTLSTR;
    #define TPM1CNTL                    _TPM1CNT.Overlap_STR.TPM1CNTLSTR.Byte
    
  } Overlap_STR;

} TPM1CNTSTR;
#define _TPM1CNT (*(volatile TPM1CNTSTR *)0xFFFF8261)
#define TPM1CNT                         _TPM1CNT.Word


/*** TPM1MOD - TPM1 Timer Counter Modulo Register; 0xFFFF8263 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1MODH - TPM1 Timer Counter Modulo Register High; 0xFFFF8263 ***/
    union {
      byte Byte;
    } TPM1MODHSTR;
    #define TPM1MODH                    _TPM1MOD.Overlap_STR.TPM1MODHSTR.Byte
    

    /*** TPM1MODL - TPM1 Timer Counter Modulo Register Low; 0xFFFF8264 ***/
    union {
      byte Byte;
    } TPM1MODLSTR;
    #define TPM1MODL                    _TPM1MOD.Overlap_STR.TPM1MODLSTR.Byte
    
  } Overlap_STR;

} TPM1MODSTR;
#define _TPM1MOD (*(volatile TPM1MODSTR *)0xFFFF8263)
#define TPM1MOD                         _TPM1MOD.Word


/*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register; 0xFFFF8265 ***/
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
#define _TPM1C0SC (*(volatile TPM1C0SCSTR *)0xFFFF8265)
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


/*** TPM1C0V - TPM1 Timer Channel 0 Value Register; 0xFFFF8266 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High; 0xFFFF8266 ***/
    union {
      byte Byte;
    } TPM1C0VHSTR;
    #define TPM1C0VH                    _TPM1C0V.Overlap_STR.TPM1C0VHSTR.Byte
    

    /*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low; 0xFFFF8267 ***/
    union {
      byte Byte;
    } TPM1C0VLSTR;
    #define TPM1C0VL                    _TPM1C0V.Overlap_STR.TPM1C0VLSTR.Byte
    
  } Overlap_STR;

} TPM1C0VSTR;
#define _TPM1C0V (*(volatile TPM1C0VSTR *)0xFFFF8266)
#define TPM1C0V                         _TPM1C0V.Word


/*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register; 0xFFFF8268 ***/
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
#define _TPM1C1SC (*(volatile TPM1C1SCSTR *)0xFFFF8268)
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


/*** TPM1C1V - TPM1 Timer Channel 1 Value Register; 0xFFFF8269 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High; 0xFFFF8269 ***/
    union {
      byte Byte;
    } TPM1C1VHSTR;
    #define TPM1C1VH                    _TPM1C1V.Overlap_STR.TPM1C1VHSTR.Byte
    

    /*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low; 0xFFFF826A ***/
    union {
      byte Byte;
    } TPM1C1VLSTR;
    #define TPM1C1VL                    _TPM1C1V.Overlap_STR.TPM1C1VLSTR.Byte
    
  } Overlap_STR;

} TPM1C1VSTR;
#define _TPM1C1V (*(volatile TPM1C1VSTR *)0xFFFF8269)
#define TPM1C1V                         _TPM1C1V.Word


/*** TPM1C2SC - TPM1 Timer Channel 2 Status and Control Register; 0xFFFF826B ***/
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
#define _TPM1C2SC (*(volatile TPM1C2SCSTR *)0xFFFF826B)
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


/*** TPM1C2V - TPM1 Timer Channel 2 Value Register; 0xFFFF826C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C2VH - TPM1 Timer Channel 2 Value Register High; 0xFFFF826C ***/
    union {
      byte Byte;
    } TPM1C2VHSTR;
    #define TPM1C2VH                    _TPM1C2V.Overlap_STR.TPM1C2VHSTR.Byte
    

    /*** TPM1C2VL - TPM1 Timer Channel 2 Value Register Low; 0xFFFF826D ***/
    union {
      byte Byte;
    } TPM1C2VLSTR;
    #define TPM1C2VL                    _TPM1C2V.Overlap_STR.TPM1C2VLSTR.Byte
    
  } Overlap_STR;

} TPM1C2VSTR;
#define _TPM1C2V (*(volatile TPM1C2VSTR *)0xFFFF826C)
#define TPM1C2V                         _TPM1C2V.Word


/*** TPM2SC - TPM2 Status and Control Register; 0xFFFF8280 ***/
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
#define _TPM2SC (*(volatile TPM2SCSTR *)0xFFFF8280)
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


/*** TPM2CNT - TPM2 Timer Counter Register; 0xFFFF8281 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2CNTH - TPM2 Timer Counter Register High; 0xFFFF8281 ***/
    union {
      byte Byte;
    } TPM2CNTHSTR;
    #define TPM2CNTH                    _TPM2CNT.Overlap_STR.TPM2CNTHSTR.Byte
    

    /*** TPM2CNTL - TPM2 Timer Counter Register Low; 0xFFFF8282 ***/
    union {
      byte Byte;
    } TPM2CNTLSTR;
    #define TPM2CNTL                    _TPM2CNT.Overlap_STR.TPM2CNTLSTR.Byte
    
  } Overlap_STR;

} TPM2CNTSTR;
#define _TPM2CNT (*(volatile TPM2CNTSTR *)0xFFFF8281)
#define TPM2CNT                         _TPM2CNT.Word


/*** TPM2MOD - TPM2 Timer Counter Modulo Register; 0xFFFF8283 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2MODH - TPM2 Timer Counter Modulo Register High; 0xFFFF8283 ***/
    union {
      byte Byte;
    } TPM2MODHSTR;
    #define TPM2MODH                    _TPM2MOD.Overlap_STR.TPM2MODHSTR.Byte
    

    /*** TPM2MODL - TPM2 Timer Counter Modulo Register Low; 0xFFFF8284 ***/
    union {
      byte Byte;
    } TPM2MODLSTR;
    #define TPM2MODL                    _TPM2MOD.Overlap_STR.TPM2MODLSTR.Byte
    
  } Overlap_STR;

} TPM2MODSTR;
#define _TPM2MOD (*(volatile TPM2MODSTR *)0xFFFF8283)
#define TPM2MOD                         _TPM2MOD.Word


/*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register; 0xFFFF8285 ***/
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
#define _TPM2C0SC (*(volatile TPM2C0SCSTR *)0xFFFF8285)
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


/*** TPM2C0V - TPM2 Timer Channel 0 Value Register; 0xFFFF8286 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High; 0xFFFF8286 ***/
    union {
      byte Byte;
    } TPM2C0VHSTR;
    #define TPM2C0VH                    _TPM2C0V.Overlap_STR.TPM2C0VHSTR.Byte
    

    /*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low; 0xFFFF8287 ***/
    union {
      byte Byte;
    } TPM2C0VLSTR;
    #define TPM2C0VL                    _TPM2C0V.Overlap_STR.TPM2C0VLSTR.Byte
    
  } Overlap_STR;

} TPM2C0VSTR;
#define _TPM2C0V (*(volatile TPM2C0VSTR *)0xFFFF8286)
#define TPM2C0V                         _TPM2C0V.Word


/*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register; 0xFFFF8288 ***/
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
#define _TPM2C1SC (*(volatile TPM2C1SCSTR *)0xFFFF8288)
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


/*** TPM2C1V - TPM2 Timer Channel 1 Value Register; 0xFFFF8289 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High; 0xFFFF8289 ***/
    union {
      byte Byte;
    } TPM2C1VHSTR;
    #define TPM2C1VH                    _TPM2C1V.Overlap_STR.TPM2C1VHSTR.Byte
    

    /*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low; 0xFFFF828A ***/
    union {
      byte Byte;
    } TPM2C1VLSTR;
    #define TPM2C1VL                    _TPM2C1V.Overlap_STR.TPM2C1VLSTR.Byte
    
  } Overlap_STR;

} TPM2C1VSTR;
#define _TPM2C1V (*(volatile TPM2C1VSTR *)0xFFFF8289)
#define TPM2C1V                         _TPM2C1V.Word


/*** TPM2C2SC - TPM2 Timer Channel 2 Status and Control Register; 0xFFFF828B ***/
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
} TPM2C2SCSTR;
#define _TPM2C2SC (*(volatile TPM2C2SCSTR *)0xFFFF828B)
#define TPM2C2SC                        _TPM2C2SC.Byte
#define TPM2C2SC_ELS2A                  _TPM2C2SC.Bits.ELS2A
#define TPM2C2SC_ELS2B                  _TPM2C2SC.Bits.ELS2B
#define TPM2C2SC_MS2A                   _TPM2C2SC.Bits.MS2A
#define TPM2C2SC_MS2B                   _TPM2C2SC.Bits.MS2B
#define TPM2C2SC_CH2IE                  _TPM2C2SC.Bits.CH2IE
#define TPM2C2SC_CH2F                   _TPM2C2SC.Bits.CH2F
#define TPM2C2SC_ELS2x                  _TPM2C2SC.MergedBits.grpELS2x
#define TPM2C2SC_MS2x                   _TPM2C2SC.MergedBits.grpMS2x

#define TPM2C2SC_ELS2A_MASK             4U
#define TPM2C2SC_ELS2B_MASK             8U
#define TPM2C2SC_MS2A_MASK              16U
#define TPM2C2SC_MS2B_MASK              32U
#define TPM2C2SC_CH2IE_MASK             64U
#define TPM2C2SC_CH2F_MASK              128U
#define TPM2C2SC_ELS2x_MASK             12U
#define TPM2C2SC_ELS2x_BITNUM           2U
#define TPM2C2SC_MS2x_MASK              48U
#define TPM2C2SC_MS2x_BITNUM            4U


/*** TPM2C2V - TPM2 Timer Channel 2 Value Register; 0xFFFF828C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2C2VH - TPM2 Timer Channel 2 Value Register High; 0xFFFF828C ***/
    union {
      byte Byte;
    } TPM2C2VHSTR;
    #define TPM2C2VH                    _TPM2C2V.Overlap_STR.TPM2C2VHSTR.Byte
    

    /*** TPM2C2VL - TPM2 Timer Channel 2 Value Register Low; 0xFFFF828D ***/
    union {
      byte Byte;
    } TPM2C2VLSTR;
    #define TPM2C2VL                    _TPM2C2V.Overlap_STR.TPM2C2VLSTR.Byte
    
  } Overlap_STR;

} TPM2C2VSTR;
#define _TPM2C2V (*(volatile TPM2C2VSTR *)0xFFFF828C)
#define TPM2C2V                         _TPM2C2V.Word


/*** MTIM1SC - MTIM Clock Configuration Register; 0xFFFF82A0 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TSTP        :1;                                       /* MTIM Counter Stop */
    byte TRST        :1;                                       /* MTIM Counter Reset */
    byte TOIE        :1;                                       /* MTIM Overflow Interrupt Enable */
    byte TOF         :1;                                       /* MTIM Overflow Flag */
  } Bits;
} MTIM1SCSTR;
#define _MTIM1SC (*(volatile MTIM1SCSTR *)0xFFFF82A0)
#define MTIM1SC                         _MTIM1SC.Byte
#define MTIM1SC_TSTP                    _MTIM1SC.Bits.TSTP
#define MTIM1SC_TRST                    _MTIM1SC.Bits.TRST
#define MTIM1SC_TOIE                    _MTIM1SC.Bits.TOIE
#define MTIM1SC_TOF                     _MTIM1SC.Bits.TOF

#define MTIM1SC_TSTP_MASK               16U
#define MTIM1SC_TRST_MASK               32U
#define MTIM1SC_TOIE_MASK               64U
#define MTIM1SC_TOF_MASK                128U


/*** MTIM1CLK - MTIM Clock Configuration Register; 0xFFFF82A1 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Clock source Prescaler Bit 0 */
    byte PS1         :1;                                       /* Clock source Prescaler Bit 1 */
    byte PS2         :1;                                       /* Clock source Prescaler Bit 2 */
    byte PS3         :1;                                       /* Clock source Prescaler Bit 3 */
    byte CLKS0       :1;                                       /* Clock source Select Bit 0 */
    byte CLKS1       :1;                                       /* Clock source Select Bit 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPS   :4;
    byte grpCLKS :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} MTIM1CLKSTR;
#define _MTIM1CLK (*(volatile MTIM1CLKSTR *)0xFFFF82A1)
#define MTIM1CLK                        _MTIM1CLK.Byte
#define MTIM1CLK_PS0                    _MTIM1CLK.Bits.PS0
#define MTIM1CLK_PS1                    _MTIM1CLK.Bits.PS1
#define MTIM1CLK_PS2                    _MTIM1CLK.Bits.PS2
#define MTIM1CLK_PS3                    _MTIM1CLK.Bits.PS3
#define MTIM1CLK_CLKS0                  _MTIM1CLK.Bits.CLKS0
#define MTIM1CLK_CLKS1                  _MTIM1CLK.Bits.CLKS1
#define MTIM1CLK_PS                     _MTIM1CLK.MergedBits.grpPS
#define MTIM1CLK_CLKS                   _MTIM1CLK.MergedBits.grpCLKS

#define MTIM1CLK_PS0_MASK               1U
#define MTIM1CLK_PS1_MASK               2U
#define MTIM1CLK_PS2_MASK               4U
#define MTIM1CLK_PS3_MASK               8U
#define MTIM1CLK_CLKS0_MASK             16U
#define MTIM1CLK_CLKS1_MASK             32U
#define MTIM1CLK_PS_MASK                15U
#define MTIM1CLK_PS_BITNUM              0U
#define MTIM1CLK_CLKS_MASK              48U
#define MTIM1CLK_CLKS_BITNUM            4U


/*** MTIM1CNT - MTIM Counter Register; 0xFFFF82A2 ***/
typedef union {
  byte Byte;
} MTIM1CNTSTR;
#define _MTIM1CNT (*(volatile MTIM1CNTSTR *)0xFFFF82A2)
#define MTIM1CNT                        _MTIM1CNT.Byte


/*** MTIM1MOD - MTIM Modulo Register; 0xFFFF82A3 ***/
typedef union {
  byte Byte;
} MTIM1MODSTR;
#define _MTIM1MOD (*(volatile MTIM1MODSTR *)0xFFFF82A3)
#define MTIM1MOD                        _MTIM1MOD.Byte


/*** RTCSC - RTC Status and Control Register; 0xFFFF82C0 ***/
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
#define _RTCSC (*(volatile RTCSCSTR *)0xFFFF82C0)
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


/*** RTCCNT - RTC Counter Register; 0xFFFF82C1 ***/
typedef union {
  byte Byte;
} RTCCNTSTR;
#define _RTCCNT (*(volatile RTCCNTSTR *)0xFFFF82C1)
#define RTCCNT                          _RTCCNT.Byte


/*** RTCMOD - RTC Modulo Register; 0xFFFF82C2 ***/
typedef union {
  byte Byte;
} RTCMODSTR;
#define _RTCMOD (*(volatile RTCMODSTR *)0xFFFF82C2)
#define RTCMOD                          _RTCMOD.Byte


/*** FCDIV - FLASH Clock Divider Register; 0xFFFF82E0 ***/
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
#define _FCDIV (*(volatile FCDIVSTR *)0xFFFF82E0)
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


/*** FOPT - Flash Options Register; 0xFFFF82E1 ***/
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
#define _FOPT (*(volatile FOPTSTR *)0xFFFF82E1)
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


/*** FCNFG - Flash Configuration Register; 0xFFFF82E3 ***/
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
#define _FCNFG (*(volatile FCNFGSTR *)0xFFFF82E3)
#define FCNFG                           _FCNFG.Byte
#define FCNFG_KEYACC                    _FCNFG.Bits.KEYACC

#define FCNFG_KEYACC_MASK               32U


/*** FPROT - Flash Protection Register; 0xFFFF82E4 ***/
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
#define _FPROT (*(volatile FPROTSTR *)0xFFFF82E4)
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


/*** FSTAT - Flash Status Register; 0xFFFF82E5 ***/
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
#define _FSTAT (*(volatile FSTATSTR *)0xFFFF82E5)
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


/*** FCMD - Flash Command Register; 0xFFFF82E6 ***/
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
#define _FCMD (*(volatile FCMDSTR *)0xFFFF82E6)
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


/*** MTIM2SC - MTIM Clock Configuration Register; 0xFFFF8300 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TSTP        :1;                                       /* MTIM Counter Stop */
    byte TRST        :1;                                       /* MTIM Counter Reset */
    byte TOIE        :1;                                       /* MTIM Overflow Interrupt Enable */
    byte TOF         :1;                                       /* MTIM Overflow Flag */
  } Bits;
} MTIM2SCSTR;
#define _MTIM2SC (*(volatile MTIM2SCSTR *)0xFFFF8300)
#define MTIM2SC                         _MTIM2SC.Byte
#define MTIM2SC_TSTP                    _MTIM2SC.Bits.TSTP
#define MTIM2SC_TRST                    _MTIM2SC.Bits.TRST
#define MTIM2SC_TOIE                    _MTIM2SC.Bits.TOIE
#define MTIM2SC_TOF                     _MTIM2SC.Bits.TOF

#define MTIM2SC_TSTP_MASK               16U
#define MTIM2SC_TRST_MASK               32U
#define MTIM2SC_TOIE_MASK               64U
#define MTIM2SC_TOF_MASK                128U


/*** MTIM2CLK - MTIM Clock Configuration Register; 0xFFFF8301 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Clock source Prescaler Bit 0 */
    byte PS1         :1;                                       /* Clock source Prescaler Bit 1 */
    byte PS2         :1;                                       /* Clock source Prescaler Bit 2 */
    byte PS3         :1;                                       /* Clock source Prescaler Bit 3 */
    byte CLKS0       :1;                                       /* Clock source Select Bit 0 */
    byte CLKS1       :1;                                       /* Clock source Select Bit 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPS   :4;
    byte grpCLKS :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} MTIM2CLKSTR;
#define _MTIM2CLK (*(volatile MTIM2CLKSTR *)0xFFFF8301)
#define MTIM2CLK                        _MTIM2CLK.Byte
#define MTIM2CLK_PS0                    _MTIM2CLK.Bits.PS0
#define MTIM2CLK_PS1                    _MTIM2CLK.Bits.PS1
#define MTIM2CLK_PS2                    _MTIM2CLK.Bits.PS2
#define MTIM2CLK_PS3                    _MTIM2CLK.Bits.PS3
#define MTIM2CLK_CLKS0                  _MTIM2CLK.Bits.CLKS0
#define MTIM2CLK_CLKS1                  _MTIM2CLK.Bits.CLKS1
#define MTIM2CLK_PS                     _MTIM2CLK.MergedBits.grpPS
#define MTIM2CLK_CLKS                   _MTIM2CLK.MergedBits.grpCLKS

#define MTIM2CLK_PS0_MASK               1U
#define MTIM2CLK_PS1_MASK               2U
#define MTIM2CLK_PS2_MASK               4U
#define MTIM2CLK_PS3_MASK               8U
#define MTIM2CLK_CLKS0_MASK             16U
#define MTIM2CLK_CLKS1_MASK             32U
#define MTIM2CLK_PS_MASK                15U
#define MTIM2CLK_PS_BITNUM              0U
#define MTIM2CLK_CLKS_MASK              48U
#define MTIM2CLK_CLKS_BITNUM            4U


/*** MTIM2CNT - MTIM Counter Register; 0xFFFF8302 ***/
typedef union {
  byte Byte;
} MTIM2CNTSTR;
#define _MTIM2CNT (*(volatile MTIM2CNTSTR *)0xFFFF8302)
#define MTIM2CNT                        _MTIM2CNT.Byte


/*** MTIM2MOD - MTIM Modulo Register; 0xFFFF8303 ***/
typedef union {
  byte Byte;
} MTIM2MODSTR;
#define _MTIM2MOD (*(volatile MTIM2MODSTR *)0xFFFF8303)
#define MTIM2MOD                        _MTIM2MOD.Byte


/*** EIR - Ethernet Interrupt Event Register; 0xFFFFE004 ***/
typedef union {
  dword Dword;
  struct {
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
    dword UN         :1;                                       /* Transmit FIFO underrun. This bit indicates that the transmit FIFO became empty before the complete frame was transmitted. A bad CRC is appended to the frame fragment and the remainder of the frame is discarded */
    dword RL         :1;                                       /* Collision retry limit. This bit indicates that a collision occurred on each of 16 successive attempts to transmit the frame. The frame is discarded without being transmitted and transmission of the next frame will commence. Can only occur in half duplex mode */
    dword LC         :1;                                       /* Late collison. This bit indicates that a collision occurred beyond the collision window (slot time) in half duplex mode. The frame is truncated with a bad CRC and the remainder of the frame is discarded */
    dword EBERR      :1;                                       /* Ethernet bus error. This bit indicates that a system bus error occurred when a DMA transaction was underway. When the EBERR bit is set, ECR[ETHER_EN] will be cleared, halting frame processing by the FEC. When this occurs software will need to insure that the FIFO controller and DMA are also soft reset */
    dword MII        :1;                                       /* MII interrupt. This bit indicates that the MII has completed the data transfer requested */
    dword RXB        :1;                                       /* Receive buffer interrupt. This bit indicates that a receive buffer descriptor has been updated that was not the last in the frame */
    dword RXF        :1;                                       /* Receive frame interrupt. This bit indicates that a frame has been received and that the last corresponding buffer descriptor has been updated */
    dword TXB        :1;                                       /* Transmit buffer interrupt. This bit indicates that a transmit buffer descriptor has been updated */
    dword TXF        :1;                                       /* Transmit frame interrupt. This bit indicates that a frame has been transmitted and that the last corresponding buffer descriptor has been updated */
    dword GRA        :1;                                       /* Graceful stop complete. This interrupt will be asserted for one of three reasons. Graceful stop means that the transmitter is put into a pause state after completion of the frame currently being transmitted. <br/>1) A graceful stop, which was initiated by the setting of the TCR[GTS] bit is now complete. <br/>2) A graceful stop, which was initiated by the setting of the TCR[TFC_PAUSE] bit is now complete. <br/>3) A graceful stop, which was initiated by the reception of a valid full duplex flow control &quot;pause&quot; frame is now complete */
    dword BABT       :1;                                       /* Babbling transmit error. This bit indicates that the transmitted frame length has exceeded RCR[MAX_FL] bytes. This condition is usually caused by a frame that is too long being placed into the transmit data buffer(s). Truncation does not occur */
    dword BABR       :1;                                       /* Babbling receive error. This bit indicates a frame was received with length in excess of RCR[MAX_FL] bytes */
    dword HBERR      :1;                                       /* Heartbeat error. This interrupt indicates that HBC is set in the TCR register and that the COL input was not asserted within the Heartbeat window following a transmission */
  } Bits;
} EIRSTR;
#define _EIR (*(volatile EIRSTR *)0xFFFFE004)
#define EIR                             _EIR.Dword
#define EIR_UN                          _EIR.Bits.UN
#define EIR_RL                          _EIR.Bits.RL
#define EIR_LC                          _EIR.Bits.LC
#define EIR_EBERR                       _EIR.Bits.EBERR
#define EIR_MII                         _EIR.Bits.MII
#define EIR_RXB                         _EIR.Bits.RXB
#define EIR_RXF                         _EIR.Bits.RXF
#define EIR_TXB                         _EIR.Bits.TXB
#define EIR_TXF                         _EIR.Bits.TXF
#define EIR_GRA                         _EIR.Bits.GRA
#define EIR_BABT                        _EIR.Bits.BABT
#define EIR_BABR                        _EIR.Bits.BABR
#define EIR_HBERR                       _EIR.Bits.HBERR

#define EIR_UN_MASK                     524288UL
#define EIR_RL_MASK                     1048576UL
#define EIR_LC_MASK                     2097152UL
#define EIR_EBERR_MASK                  4194304UL
#define EIR_MII_MASK                    8388608UL
#define EIR_RXB_MASK                    16777216UL
#define EIR_RXF_MASK                    33554432UL
#define EIR_TXB_MASK                    67108864UL
#define EIR_TXF_MASK                    134217728UL
#define EIR_GRA_MASK                    268435456UL
#define EIR_BABT_MASK                   536870912UL
#define EIR_BABR_MASK                   1073741824UL
#define EIR_HBERR_MASK                  2147483648UL


/*** EIMR - Interrupt Mask Register; 0xFFFFE008 ***/
typedef union {
  dword Dword;
  struct {
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
    dword UN         :1;                                       /* Transmit FIFO underrun interrupt mask */
    dword RL         :1;                                       /* Collision retry limit interrupt mask */
    dword LC         :1;                                       /* Late collison interrupt mask */
    dword EBERR      :1;                                       /* Ethernet bus error interrupt mask */
    dword MII        :1;                                       /* MII interrupt interrupt mask */
    dword RXB        :1;                                       /* Receive buffer interrupt mask */
    dword RXF        :1;                                       /* Receive frame interrupt mask */
    dword TXB        :1;                                       /* Transmit buffer interrupt mask */
    dword TXF        :1;                                       /* Transmit frame interrupt mask */
    dword GRA        :1;                                       /* Graceful stop complete interrupt mask */
    dword BABT       :1;                                       /* Babbling transmit error interrupt mask */
    dword BABR       :1;                                       /* Babbling receive error interrupt mask */
    dword HBERR      :1;                                       /* Heartbeat error interrupt mask */
  } Bits;
} EIMRSTR;
#define _EIMR (*(volatile EIMRSTR *)0xFFFFE008)
#define EIMR                            _EIMR.Dword
#define EIMR_UN                         _EIMR.Bits.UN
#define EIMR_RL                         _EIMR.Bits.RL
#define EIMR_LC                         _EIMR.Bits.LC
#define EIMR_EBERR                      _EIMR.Bits.EBERR
#define EIMR_MII                        _EIMR.Bits.MII
#define EIMR_RXB                        _EIMR.Bits.RXB
#define EIMR_RXF                        _EIMR.Bits.RXF
#define EIMR_TXB                        _EIMR.Bits.TXB
#define EIMR_TXF                        _EIMR.Bits.TXF
#define EIMR_GRA                        _EIMR.Bits.GRA
#define EIMR_BABT                       _EIMR.Bits.BABT
#define EIMR_BABR                       _EIMR.Bits.BABR
#define EIMR_HBERR                      _EIMR.Bits.HBERR

#define EIMR_UN_MASK                    524288UL
#define EIMR_RL_MASK                    1048576UL
#define EIMR_LC_MASK                    2097152UL
#define EIMR_EBERR_MASK                 4194304UL
#define EIMR_MII_MASK                   8388608UL
#define EIMR_RXB_MASK                   16777216UL
#define EIMR_RXF_MASK                   33554432UL
#define EIMR_TXB_MASK                   67108864UL
#define EIMR_TXF_MASK                   134217728UL
#define EIMR_GRA_MASK                   268435456UL
#define EIMR_BABT_MASK                  536870912UL
#define EIMR_BABR_MASK                  1073741824UL
#define EIMR_HBERR_MASK                 2147483648UL


/*** RDAR - Receive Descriptor Active Register; 0xFFFFE010 ***/
typedef union {
  dword Dword;
  struct {
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
    dword RDAR_bit   :1;                                       /* Set to one when this register is written, regardless of the value written. Cleared by the FEC device whenever no additional &quot;empty&quot; descriptors remain in the receive ring. Also cleared when ECR[ETHER_EN] is cleared */ /*Warning: bit name is duplicated with register name*/
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
  } Bits;
} RDARSTR;
#define _RDAR (*(volatile RDARSTR *)0xFFFFE010)
#define RDAR                            _RDAR.Dword
#define RDAR_RDAR                       _RDAR.Bits.RDAR_bit

#define RDAR_RDAR_MASK                  16777216UL


/*** TDAR - Transmit Descriptor Active Register; 0xFFFFE014 ***/
typedef union {
  dword Dword;
  struct {
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
    dword TDAR_bit   :1;                                       /* Set to one when this register is written, regardless of the value written. Cleared by the FEC device whenever no additional ready descriptors remain in the transmit ring. Also cleared when ECR[ETHER_EN] is cleared */ /*Warning: bit name is duplicated with register name*/
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
  } Bits;
} TDARSTR;
#define _TDAR (*(volatile TDARSTR *)0xFFFFE014)
#define TDAR                            _TDAR.Dword
#define TDAR_TDAR                       _TDAR.Bits.TDAR_bit

#define TDAR_TDAR_MASK                  16777216UL


/*** ECR -  Ethernet Control Register; 0xFFFFE024 ***/
typedef union {
  dword Dword;
  struct {
    dword RESET      :1;                                       /* When this bit is set, the equivalent of a hardware reset is performed but it is local to the FEC. ETHER_EN is cleared and all other FEC registers take their reset values. Also, any transmission/reception currently in progress is abruptly aborted. This bit is automatically cleared by hardware during the reset sequence. The reset sequence takes approximately 8 clock cycles after RESET is written with a 1 */
    dword ETHER_EN   :1;                                       /* When this bit is set, the FEC is enabled, and reception and transmission are possible. When this bit is cleared, reception is immediately stopped and transmission is stopped after a bad CRC is appended to any currently transmitted frame. The buffer descriptor(s) for an aborted transmit frame are not updated after clearing this bit. When ETHER_EN is deasserted, the DMA, buffer descriptor, and FIFO control logic are reset, including the buffer descriptor and FIFO pointers. The ETHER_EN bit is altered by hardware under the following conditions: <br/>- ECR[RESET] is set by software, in which case ETHER_EN will be cleared <br/>- an error condition causes the EIR[EBERR] bit to set, in which case ETHER_EN will be cleared */
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
    dword            :1; 
    dword            :1; 
    dword            :1; 
  } Bits;
} ECRSTR;
#define _ECR (*(volatile ECRSTR *)0xFFFFE024)
#define ECR                             _ECR.Dword
#define ECR_RESET                       _ECR.Bits.RESET
#define ECR_ETHER_EN                    _ECR.Bits.ETHER_EN

#define ECR_RESET_MASK                  1UL
#define ECR_ETHER_EN_MASK               2UL


/*** MMFR - MII Management Frame Register; 0xFFFFE040 ***/
typedef union {
  dword Dword;
  struct {
    dword DATA0      :1;                                       /* Management frame data. This is the field for data to be written to or read from the PHY register, bit 0 */
    dword DATA1      :1;                                       /* Management frame data. This is the field for data to be written to or read from the PHY register, bit 1 */
    dword DATA2      :1;                                       /* Management frame data. This is the field for data to be written to or read from the PHY register, bit 2 */
    dword DATA3      :1;                                       /* Management frame data. This is the field for data to be written to or read from the PHY register, bit 3 */
    dword DATA4      :1;                                       /* Management frame data. This is the field for data to be written to or read from the PHY register, bit 4 */
    dword DATA5      :1;                                       /* Management frame data. This is the field for data to be written to or read from the PHY register, bit 5 */
    dword DATA6      :1;                                       /* Management frame data. This is the field for data to be written to or read from the PHY register, bit 6 */
    dword DATA7      :1;                                       /* Management frame data. This is the field for data to be written to or read from the PHY register, bit 7 */
    dword DATA8      :1;                                       /* Management frame data. This is the field for data to be written to or read from the PHY register, bit 8 */
    dword DATA9      :1;                                       /* Management frame data. This is the field for data to be written to or read from the PHY register, bit 9 */
    dword DATA10     :1;                                       /* Management frame data. This is the field for data to be written to or read from the PHY register, bit 10 */
    dword DATA11     :1;                                       /* Management frame data. This is the field for data to be written to or read from the PHY register, bit 11 */
    dword DATA12     :1;                                       /* Management frame data. This is the field for data to be written to or read from the PHY register, bit 12 */
    dword DATA13     :1;                                       /* Management frame data. This is the field for data to be written to or read from the PHY register, bit 13 */
    dword DATA14     :1;                                       /* Management frame data. This is the field for data to be written to or read from the PHY register, bit 14 */
    dword DATA15     :1;                                       /* Management frame data. This is the field for data to be written to or read from the PHY register, bit 15 */
    dword TA0        :1;                                       /* Turn around. This field must be programmed to 0b10 to generate a valid MII management frame, bit 0 */
    dword TA1        :1;                                       /* Turn around. This field must be programmed to 0b10 to generate a valid MII management frame, bit 1 */
    dword RA0        :1;                                       /* Register address. This field specifies one of up to 32 registers within the specified PHY device, bit 0 */
    dword RA1        :1;                                       /* Register address. This field specifies one of up to 32 registers within the specified PHY device, bit 1 */
    dword RA2        :1;                                       /* Register address. This field specifies one of up to 32 registers within the specified PHY device, bit 2 */
    dword RA3        :1;                                       /* Register address. This field specifies one of up to 32 registers within the specified PHY device, bit 3 */
    dword RA4        :1;                                       /* Register address. This field specifies one of up to 32 registers within the specified PHY device, bit 4 */
    dword PA0        :1;                                       /* PHY address. This field specifies one of up to 32 attached PHY devices, bit 0 */
    dword PA1        :1;                                       /* PHY address. This field specifies one of up to 32 attached PHY devices, bit 1 */
    dword PA2        :1;                                       /* PHY address. This field specifies one of up to 32 attached PHY devices, bit 2 */
    dword PA3        :1;                                       /* PHY address. This field specifies one of up to 32 attached PHY devices, bit 3 */
    dword PA4        :1;                                       /* PHY address. This field specifies one of up to 32 attached PHY devices, bit 4 */
    dword OP0        :1;                                       /* Operation code. This field must be programmed to 0b10 (read) or 0b01 (write) to generate a valid MII management frame. A value of 0b11 will produce &quot;read&quot; frame operation while a value of 0b00 will produce &quot;write&quot; frame operation, but these frames will not be MII compliant, bit 0 */
    dword OP1        :1;                                       /* Operation code. This field must be programmed to 0b10 (read) or 0b01 (write) to generate a valid MII management frame. A value of 0b11 will produce &quot;read&quot; frame operation while a value of 0b00 will produce &quot;write&quot; frame operation, but these frames will not be MII compliant, bit 1 */
    dword ST0        :1;                                       /* Start of frame delimiter. These bits must be programmed to 0b01 for a valid MII management frame, bit 0 */
    dword ST1        :1;                                       /* Start of frame delimiter. These bits must be programmed to 0b01 for a valid MII management frame, bit 1 */
  } Bits;
  struct {
    dword grpDATA :16;
    dword grpTA  :2;
    dword grpRA  :5;
    dword grpPA  :5;
    dword grpOP  :2;
    dword grpST  :2;
  } MergedBits;
} MMFRSTR;
#define _MMFR (*(volatile MMFRSTR *)0xFFFFE040)
#define MMFR                            _MMFR.Dword
#define MMFR_DATA0                      _MMFR.Bits.DATA0
#define MMFR_DATA1                      _MMFR.Bits.DATA1
#define MMFR_DATA2                      _MMFR.Bits.DATA2
#define MMFR_DATA3                      _MMFR.Bits.DATA3
#define MMFR_DATA4                      _MMFR.Bits.DATA4
#define MMFR_DATA5                      _MMFR.Bits.DATA5
#define MMFR_DATA6                      _MMFR.Bits.DATA6
#define MMFR_DATA7                      _MMFR.Bits.DATA7
#define MMFR_DATA8                      _MMFR.Bits.DATA8
#define MMFR_DATA9                      _MMFR.Bits.DATA9
#define MMFR_DATA10                     _MMFR.Bits.DATA10
#define MMFR_DATA11                     _MMFR.Bits.DATA11
#define MMFR_DATA12                     _MMFR.Bits.DATA12
#define MMFR_DATA13                     _MMFR.Bits.DATA13
#define MMFR_DATA14                     _MMFR.Bits.DATA14
#define MMFR_DATA15                     _MMFR.Bits.DATA15
#define MMFR_TA0                        _MMFR.Bits.TA0
#define MMFR_TA1                        _MMFR.Bits.TA1
#define MMFR_RA0                        _MMFR.Bits.RA0
#define MMFR_RA1                        _MMFR.Bits.RA1
#define MMFR_RA2                        _MMFR.Bits.RA2
#define MMFR_RA3                        _MMFR.Bits.RA3
#define MMFR_RA4                        _MMFR.Bits.RA4
#define MMFR_PA0                        _MMFR.Bits.PA0
#define MMFR_PA1                        _MMFR.Bits.PA1
#define MMFR_PA2                        _MMFR.Bits.PA2
#define MMFR_PA3                        _MMFR.Bits.PA3
#define MMFR_PA4                        _MMFR.Bits.PA4
#define MMFR_OP0                        _MMFR.Bits.OP0
#define MMFR_OP1                        _MMFR.Bits.OP1
#define MMFR_ST0                        _MMFR.Bits.ST0
#define MMFR_ST1                        _MMFR.Bits.ST1
#define MMFR_DATA                       _MMFR.MergedBits.grpDATA
#define MMFR_TA                         _MMFR.MergedBits.grpTA
#define MMFR_RA                         _MMFR.MergedBits.grpRA
#define MMFR_PA                         _MMFR.MergedBits.grpPA
#define MMFR_OP                         _MMFR.MergedBits.grpOP
#define MMFR_ST                         _MMFR.MergedBits.grpST

#define MMFR_DATA0_MASK                 1UL
#define MMFR_DATA1_MASK                 2UL
#define MMFR_DATA2_MASK                 4UL
#define MMFR_DATA3_MASK                 8UL
#define MMFR_DATA4_MASK                 16UL
#define MMFR_DATA5_MASK                 32UL
#define MMFR_DATA6_MASK                 64UL
#define MMFR_DATA7_MASK                 128UL
#define MMFR_DATA8_MASK                 256UL
#define MMFR_DATA9_MASK                 512UL
#define MMFR_DATA10_MASK                1024UL
#define MMFR_DATA11_MASK                2048UL
#define MMFR_DATA12_MASK                4096UL
#define MMFR_DATA13_MASK                8192UL
#define MMFR_DATA14_MASK                16384UL
#define MMFR_DATA15_MASK                32768UL
#define MMFR_TA0_MASK                   65536UL
#define MMFR_TA1_MASK                   131072UL
#define MMFR_RA0_MASK                   262144UL
#define MMFR_RA1_MASK                   524288UL
#define MMFR_RA2_MASK                   1048576UL
#define MMFR_RA3_MASK                   2097152UL
#define MMFR_RA4_MASK                   4194304UL
#define MMFR_PA0_MASK                   8388608UL
#define MMFR_PA1_MASK                   16777216UL
#define MMFR_PA2_MASK                   33554432UL
#define MMFR_PA3_MASK                   67108864UL
#define MMFR_PA4_MASK                   134217728UL
#define MMFR_OP0_MASK                   268435456UL
#define MMFR_OP1_MASK                   536870912UL
#define MMFR_ST0_MASK                   1073741824UL
#define MMFR_ST1_MASK                   2147483648UL
#define MMFR_DATA_MASK                  65535U
#define MMFR_DATA_BITNUM                0U
#define MMFR_TA_MASK                    196608U
#define MMFR_TA_BITNUM                  16U
#define MMFR_RA_MASK                    8126464U
#define MMFR_RA_BITNUM                  18U
#define MMFR_PA_MASK                    260046848U
#define MMFR_PA_BITNUM                  23U
#define MMFR_OP_MASK                    805306368U
#define MMFR_OP_BITNUM                  28U
#define MMFR_ST_MASK                    3221225472U
#define MMFR_ST_BITNUM                  30U


/*** MSCR - MII Speed Control Register; 0xFFFFE044 ***/
typedef union {
  dword Dword;
  struct {
    dword            :1; 
    dword MII_SPEED0 :1;                                       /* MII_SPEED controls the frequency of the MII management interface clock (EMDC) relative to system clock. A value of 0 in this field will &quot;turn off&quot; the EMDC and leave it in low voltage state. Any non-zero value will result in the EMDC frequency of 1/(MII_SPEED*2) of the system clock frequency, bit 0 */
    dword MII_SPEED1 :1;                                       /* MII_SPEED controls the frequency of the MII management interface clock (EMDC) relative to system clock. A value of 0 in this field will &quot;turn off&quot; the EMDC and leave it in low voltage state. Any non-zero value will result in the EMDC frequency of 1/(MII_SPEED*2) of the system clock frequency, bit 1 */
    dword MII_SPEED2 :1;                                       /* MII_SPEED controls the frequency of the MII management interface clock (EMDC) relative to system clock. A value of 0 in this field will &quot;turn off&quot; the EMDC and leave it in low voltage state. Any non-zero value will result in the EMDC frequency of 1/(MII_SPEED*2) of the system clock frequency, bit 2 */
    dword MII_SPEED3 :1;                                       /* MII_SPEED controls the frequency of the MII management interface clock (EMDC) relative to system clock. A value of 0 in this field will &quot;turn off&quot; the EMDC and leave it in low voltage state. Any non-zero value will result in the EMDC frequency of 1/(MII_SPEED*2) of the system clock frequency, bit 3 */
    dword MII_SPEED4 :1;                                       /* MII_SPEED controls the frequency of the MII management interface clock (EMDC) relative to system clock. A value of 0 in this field will &quot;turn off&quot; the EMDC and leave it in low voltage state. Any non-zero value will result in the EMDC frequency of 1/(MII_SPEED*2) of the system clock frequency, bit 4 */
    dword MII_SPEED5 :1;                                       /* MII_SPEED controls the frequency of the MII management interface clock (EMDC) relative to system clock. A value of 0 in this field will &quot;turn off&quot; the EMDC and leave it in low voltage state. Any non-zero value will result in the EMDC frequency of 1/(MII_SPEED*2) of the system clock frequency, bit 5 */
    dword DIS_PRE    :1;                                       /* Asserting this bit will cause preamble (32 1's) not to be prepended to the MII management frame. The MII standard allows the preamble to be dropped if the attached PHY device(s) does not require it */
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
  struct {
    dword        :1;
    dword grpMII_SPEED :6;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
  } MergedBits;
} MSCRSTR;
#define _MSCR (*(volatile MSCRSTR *)0xFFFFE044)
#define MSCR                            _MSCR.Dword
#define MSCR_MII_SPEED0                 _MSCR.Bits.MII_SPEED0
#define MSCR_MII_SPEED1                 _MSCR.Bits.MII_SPEED1
#define MSCR_MII_SPEED2                 _MSCR.Bits.MII_SPEED2
#define MSCR_MII_SPEED3                 _MSCR.Bits.MII_SPEED3
#define MSCR_MII_SPEED4                 _MSCR.Bits.MII_SPEED4
#define MSCR_MII_SPEED5                 _MSCR.Bits.MII_SPEED5
#define MSCR_DIS_PRE                    _MSCR.Bits.DIS_PRE
#define MSCR_MII_SPEED                  _MSCR.MergedBits.grpMII_SPEED

#define MSCR_MII_SPEED0_MASK            2UL
#define MSCR_MII_SPEED1_MASK            4UL
#define MSCR_MII_SPEED2_MASK            8UL
#define MSCR_MII_SPEED3_MASK            16UL
#define MSCR_MII_SPEED4_MASK            32UL
#define MSCR_MII_SPEED5_MASK            64UL
#define MSCR_DIS_PRE_MASK               128UL
#define MSCR_MII_SPEED_MASK             126U
#define MSCR_MII_SPEED_BITNUM           1U


/*** RCR - Receive Control Register; 0xFFFFE084 ***/
typedef union {
  dword Dword;
  struct {
    dword LOOP       :1;                                       /* Internal loopback. If set, transmitted frames are looped back internal to the device and the transmit output signals are not asserted. The system clock is substituted for the ETXCLK when LOOP is asserted. DRT must be set to zero when asserting LOOP */
    dword DRT        :1;                                       /* Disable receive on transmit */
    dword MII_MODE   :1;                                       /* Media independent interface mode. Selects the external interface mode for both transmit and receive blocks */
    dword PROM       :1;                                       /* Promiscuous mode. All frames are accepted regardless of address matching */
    dword BC_REJ     :1;                                       /* Broadcast frame reject. If asserted, frames with DA (destination address) = FF_FF_FF_FF_FF_FF will be rejected unless the PROM bit is set. If both BC_REJ and PROM = 1, then frames with broadcast DA will be accepted and the M (MISS) bit will be set in the receive buffer descriptor */
    dword FCE        :1;                                       /* Flow control enable. If asserted, the receiver will detect PAUSE frames. Upon PAUSE frame detection, the transmitter will stop transmitting data frames for a given duration */
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
    dword MAX_FL0    :1;                                       /* Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BABR interrupt to occur and will set the LG bit in the end of frame receive buffer descriptor. The recommended default value to be programmed by the user is 1518 or 1522 (if VLAN Tags are supported), bit 0 */
    dword MAX_FL1    :1;                                       /* Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BABR interrupt to occur and will set the LG bit in the end of frame receive buffer descriptor. The recommended default value to be programmed by the user is 1518 or 1522 (if VLAN Tags are supported), bit 1 */
    dword MAX_FL2    :1;                                       /* Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BABR interrupt to occur and will set the LG bit in the end of frame receive buffer descriptor. The recommended default value to be programmed by the user is 1518 or 1522 (if VLAN Tags are supported), bit 2 */
    dword MAX_FL3    :1;                                       /* Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BABR interrupt to occur and will set the LG bit in the end of frame receive buffer descriptor. The recommended default value to be programmed by the user is 1518 or 1522 (if VLAN Tags are supported), bit 3 */
    dword MAX_FL4    :1;                                       /* Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BABR interrupt to occur and will set the LG bit in the end of frame receive buffer descriptor. The recommended default value to be programmed by the user is 1518 or 1522 (if VLAN Tags are supported), bit 4 */
    dword MAX_FL5    :1;                                       /* Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BABR interrupt to occur and will set the LG bit in the end of frame receive buffer descriptor. The recommended default value to be programmed by the user is 1518 or 1522 (if VLAN Tags are supported), bit 5 */
    dword MAX_FL6    :1;                                       /* Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BABR interrupt to occur and will set the LG bit in the end of frame receive buffer descriptor. The recommended default value to be programmed by the user is 1518 or 1522 (if VLAN Tags are supported), bit 6 */
    dword MAX_FL7    :1;                                       /* Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BABR interrupt to occur and will set the LG bit in the end of frame receive buffer descriptor. The recommended default value to be programmed by the user is 1518 or 1522 (if VLAN Tags are supported), bit 7 */
    dword MAX_FL8    :1;                                       /* Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BABR interrupt to occur and will set the LG bit in the end of frame receive buffer descriptor. The recommended default value to be programmed by the user is 1518 or 1522 (if VLAN Tags are supported), bit 8 */
    dword MAX_FL9    :1;                                       /* Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BABR interrupt to occur and will set the LG bit in the end of frame receive buffer descriptor. The recommended default value to be programmed by the user is 1518 or 1522 (if VLAN Tags are supported), bit 9 */
    dword MAX_FL10   :1;                                       /* Maximum frame length. Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL will cause the BABT interrupt to occur. Receive Frames longer than MAX_FL will cause the BABR interrupt to occur and will set the LG bit in the end of frame receive buffer descriptor. The recommended default value to be programmed by the user is 1518 or 1522 (if VLAN Tags are supported), bit 10 */
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
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
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword grpMAX_FL :11;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
  } MergedBits;
} RCRSTR;
#define _RCR (*(volatile RCRSTR *)0xFFFFE084)
#define RCR                             _RCR.Dword
#define RCR_LOOP                        _RCR.Bits.LOOP
#define RCR_DRT                         _RCR.Bits.DRT
#define RCR_MII_MODE                    _RCR.Bits.MII_MODE
#define RCR_PROM                        _RCR.Bits.PROM
#define RCR_BC_REJ                      _RCR.Bits.BC_REJ
#define RCR_FCE                         _RCR.Bits.FCE
#define RCR_MAX_FL0                     _RCR.Bits.MAX_FL0
#define RCR_MAX_FL1                     _RCR.Bits.MAX_FL1
#define RCR_MAX_FL2                     _RCR.Bits.MAX_FL2
#define RCR_MAX_FL3                     _RCR.Bits.MAX_FL3
#define RCR_MAX_FL4                     _RCR.Bits.MAX_FL4
#define RCR_MAX_FL5                     _RCR.Bits.MAX_FL5
#define RCR_MAX_FL6                     _RCR.Bits.MAX_FL6
#define RCR_MAX_FL7                     _RCR.Bits.MAX_FL7
#define RCR_MAX_FL8                     _RCR.Bits.MAX_FL8
#define RCR_MAX_FL9                     _RCR.Bits.MAX_FL9
#define RCR_MAX_FL10                    _RCR.Bits.MAX_FL10
#define RCR_MAX_FL                      _RCR.MergedBits.grpMAX_FL

#define RCR_LOOP_MASK                   1UL
#define RCR_DRT_MASK                    2UL
#define RCR_MII_MODE_MASK               4UL
#define RCR_PROM_MASK                   8UL
#define RCR_BC_REJ_MASK                 16UL
#define RCR_FCE_MASK                    32UL
#define RCR_MAX_FL0_MASK                65536UL
#define RCR_MAX_FL1_MASK                131072UL
#define RCR_MAX_FL2_MASK                262144UL
#define RCR_MAX_FL3_MASK                524288UL
#define RCR_MAX_FL4_MASK                1048576UL
#define RCR_MAX_FL5_MASK                2097152UL
#define RCR_MAX_FL6_MASK                4194304UL
#define RCR_MAX_FL7_MASK                8388608UL
#define RCR_MAX_FL8_MASK                16777216UL
#define RCR_MAX_FL9_MASK                33554432UL
#define RCR_MAX_FL10_MASK               67108864UL
#define RCR_MAX_FL_MASK                 134152192U
#define RCR_MAX_FL_BITNUM               16U


/*** TCR - Transmit Control Register; 0xFFFFE0C4 ***/
typedef union {
  dword Dword;
  struct {
    dword GTS        :1;                                       /* Graceful transmit stop. When this bit is set, the MAC will stop transmission after any frame that is currently being transmitted is complete and the GRA interrupt in the EIR register will be asserted. If frame transmission is not currently underway, the GRA interrupt will be asserted immediately. Once transmission has completed, a &quot;restart&quot; can be accomplished by clearing the GTS bit. The next frame in the transmit FIFO will then be transmitted. If an early collision occurs during transmission when GTS = 1, transmission will stop after the collision. The frame will be transmitted again once GTS is cleared. Note that there may be old frames in the transmit FIFO that will be transmitted when GTS is reasserted. To avoid this deassert ECR[ETHER_EN] following the GRA interrupt */
    dword HBC        :1;                                       /* Heartbeat control. If set, the heartbeat check is performed following end of transmission and the HB bit in the status register will be set if the collision input does not assert within the heartbeat window. This bit should only be modified when ETHER_EN is deasserted */
    dword FDEN       :1;                                       /* Full duplex enable. If set, frames are transmitted independent of carrier sense and collision inputs. This bit should only be modified when ETHER_EN is deasserted */
    dword TFC_PAUSE  :1;                                       /* Transmit frame control pause. Transmits a PAUSE frame when asserted. When this bit is set, the MAC will stop transmission of data frames after the current transmission is complete. At this time, the GRA interrupt in the EIR register will be asserted. With transmission of data frames stopped, the MAC will transmit a MAC Control PAUSE frame. Next, the MAC will clear the TFC_PAUSE bit and resume transmitting data frames. Note that if the transmitter is paused due to user assertion of GTS or reception of a PAUSE frame, the MAC may still transmit a MAC Control PAUSE frame */
    dword RFC_PAUSE  :1;                                       /* Receive frame control pause. This read-only status bit will be asserted when a full duplex flow control pause frame has been received and the transmitter is paused for the duration defined in this pause frame. This bit will automatically clear when the pause duration is complete */
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
} TCRSTR;
#define _TCR (*(volatile TCRSTR *)0xFFFFE0C4)
#define TCR                             _TCR.Dword
#define TCR_GTS                         _TCR.Bits.GTS
#define TCR_HBC                         _TCR.Bits.HBC
#define TCR_FDEN                        _TCR.Bits.FDEN
#define TCR_TFC_PAUSE                   _TCR.Bits.TFC_PAUSE
#define TCR_RFC_PAUSE                   _TCR.Bits.RFC_PAUSE

#define TCR_GTS_MASK                    1UL
#define TCR_HBC_MASK                    2UL
#define TCR_FDEN_MASK                   4UL
#define TCR_TFC_PAUSE_MASK              8UL
#define TCR_RFC_PAUSE_MASK              16UL


/*** PALR - Physical Address Low Register; 0xFFFFE0E4 ***/
typedef union {
  dword Dword;
  struct {
    dword PADDR10    :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 0 */
    dword PADDR11    :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 1 */
    dword PADDR12    :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 2 */
    dword PADDR13    :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 3 */
    dword PADDR14    :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 4 */
    dword PADDR15    :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 5 */
    dword PADDR16    :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 6 */
    dword PADDR17    :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 7 */
    dword PADDR18    :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 8 */
    dword PADDR19    :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 9 */
    dword PADDR110   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 10 */
    dword PADDR111   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 11 */
    dword PADDR112   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 12 */
    dword PADDR113   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 13 */
    dword PADDR114   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 14 */
    dword PADDR115   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 15 */
    dword PADDR116   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 16 */
    dword PADDR117   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 17 */
    dword PADDR118   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 18 */
    dword PADDR119   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 19 */
    dword PADDR120   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 20 */
    dword PADDR121   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 21 */
    dword PADDR122   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 22 */
    dword PADDR123   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 23 */
    dword PADDR124   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 24 */
    dword PADDR125   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 25 */
    dword PADDR126   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 26 */
    dword PADDR127   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 27 */
    dword PADDR128   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 28 */
    dword PADDR129   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 29 */
    dword PADDR130   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 30 */
    dword PADDR131   :1;                                       /* Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8) and 3 (bits 7:0) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 31 */
  } Bits;
} PALRSTR;
#define _PALR (*(volatile PALRSTR *)0xFFFFE0E4)
#define PALR                            _PALR.Dword
#define PALR_PADDR10                    _PALR.Bits.PADDR10
#define PALR_PADDR11                    _PALR.Bits.PADDR11
#define PALR_PADDR12                    _PALR.Bits.PADDR12
#define PALR_PADDR13                    _PALR.Bits.PADDR13
#define PALR_PADDR14                    _PALR.Bits.PADDR14
#define PALR_PADDR15                    _PALR.Bits.PADDR15
#define PALR_PADDR16                    _PALR.Bits.PADDR16
#define PALR_PADDR17                    _PALR.Bits.PADDR17
#define PALR_PADDR18                    _PALR.Bits.PADDR18
#define PALR_PADDR19                    _PALR.Bits.PADDR19
#define PALR_PADDR110                   _PALR.Bits.PADDR110
#define PALR_PADDR111                   _PALR.Bits.PADDR111
#define PALR_PADDR112                   _PALR.Bits.PADDR112
#define PALR_PADDR113                   _PALR.Bits.PADDR113
#define PALR_PADDR114                   _PALR.Bits.PADDR114
#define PALR_PADDR115                   _PALR.Bits.PADDR115
#define PALR_PADDR116                   _PALR.Bits.PADDR116
#define PALR_PADDR117                   _PALR.Bits.PADDR117
#define PALR_PADDR118                   _PALR.Bits.PADDR118
#define PALR_PADDR119                   _PALR.Bits.PADDR119
#define PALR_PADDR120                   _PALR.Bits.PADDR120
#define PALR_PADDR121                   _PALR.Bits.PADDR121
#define PALR_PADDR122                   _PALR.Bits.PADDR122
#define PALR_PADDR123                   _PALR.Bits.PADDR123
#define PALR_PADDR124                   _PALR.Bits.PADDR124
#define PALR_PADDR125                   _PALR.Bits.PADDR125
#define PALR_PADDR126                   _PALR.Bits.PADDR126
#define PALR_PADDR127                   _PALR.Bits.PADDR127
#define PALR_PADDR128                   _PALR.Bits.PADDR128
#define PALR_PADDR129                   _PALR.Bits.PADDR129
#define PALR_PADDR130                   _PALR.Bits.PADDR130
#define PALR_PADDR131                   _PALR.Bits.PADDR131

#define PALR_PADDR10_MASK               1UL
#define PALR_PADDR11_MASK               2UL
#define PALR_PADDR12_MASK               4UL
#define PALR_PADDR13_MASK               8UL
#define PALR_PADDR14_MASK               16UL
#define PALR_PADDR15_MASK               32UL
#define PALR_PADDR16_MASK               64UL
#define PALR_PADDR17_MASK               128UL
#define PALR_PADDR18_MASK               256UL
#define PALR_PADDR19_MASK               512UL
#define PALR_PADDR110_MASK              1024UL
#define PALR_PADDR111_MASK              2048UL
#define PALR_PADDR112_MASK              4096UL
#define PALR_PADDR113_MASK              8192UL
#define PALR_PADDR114_MASK              16384UL
#define PALR_PADDR115_MASK              32768UL
#define PALR_PADDR116_MASK              65536UL
#define PALR_PADDR117_MASK              131072UL
#define PALR_PADDR118_MASK              262144UL
#define PALR_PADDR119_MASK              524288UL
#define PALR_PADDR120_MASK              1048576UL
#define PALR_PADDR121_MASK              2097152UL
#define PALR_PADDR122_MASK              4194304UL
#define PALR_PADDR123_MASK              8388608UL
#define PALR_PADDR124_MASK              16777216UL
#define PALR_PADDR125_MASK              33554432UL
#define PALR_PADDR126_MASK              67108864UL
#define PALR_PADDR127_MASK              134217728UL
#define PALR_PADDR128_MASK              268435456UL
#define PALR_PADDR129_MASK              536870912UL
#define PALR_PADDR130_MASK              1073741824UL
#define PALR_PADDR131_MASK              2147483648UL


/*** PAUR - Physical Address High Register; 0xFFFFE0E8 ***/
typedef union {
  dword Dword;
  struct {
    dword TYPE0      :1;                                       /* Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 0 */
    dword TYPE1      :1;                                       /* Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 1 */
    dword TYPE2      :1;                                       /* Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 2 */
    dword TYPE3      :1;                                       /* Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 3 */
    dword TYPE4      :1;                                       /* Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 4 */
    dword TYPE5      :1;                                       /* Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 5 */
    dword TYPE6      :1;                                       /* Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 6 */
    dword TYPE7      :1;                                       /* Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 7 */
    dword TYPE8      :1;                                       /* Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 8 */
    dword TYPE9      :1;                                       /* Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 9 */
    dword TYPE10     :1;                                       /* Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 10 */
    dword TYPE11     :1;                                       /* Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 11 */
    dword TYPE12     :1;                                       /* Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 12 */
    dword TYPE13     :1;                                       /* Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 13 */
    dword TYPE14     :1;                                       /* Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 14 */
    dword TYPE15     :1;                                       /* Type field in PAUSE frames. These 16-bits are a constant value of 0x8808, bit 15 */
    dword PADDR20    :1;                                       /* Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 0 */
    dword PADDR21    :1;                                       /* Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 1 */
    dword PADDR22    :1;                                       /* Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 2 */
    dword PADDR23    :1;                                       /* Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 3 */
    dword PADDR24    :1;                                       /* Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 4 */
    dword PADDR25    :1;                                       /* Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 5 */
    dword PADDR26    :1;                                       /* Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 6 */
    dword PADDR27    :1;                                       /* Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 7 */
    dword PADDR28    :1;                                       /* Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 8 */
    dword PADDR29    :1;                                       /* Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 9 */
    dword PADDR210   :1;                                       /* Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 10 */
    dword PADDR211   :1;                                       /* Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 11 */
    dword PADDR212   :1;                                       /* Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 12 */
    dword PADDR213   :1;                                       /* Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 13 */
    dword PADDR214   :1;                                       /* Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 14 */
    dword PADDR215   :1;                                       /* Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address to be used for exact match, and the Source Address field in PAUSE frames, bit 15 */
  } Bits;
  struct {
    dword grpTYPE :16;
    dword grpPADDR2 :16;
  } MergedBits;
} PAURSTR;
#define _PAUR (*(volatile PAURSTR *)0xFFFFE0E8)
#define PAUR                            _PAUR.Dword
#define PAUR_TYPE0                      _PAUR.Bits.TYPE0
#define PAUR_TYPE1                      _PAUR.Bits.TYPE1
#define PAUR_TYPE2                      _PAUR.Bits.TYPE2
#define PAUR_TYPE3                      _PAUR.Bits.TYPE3
#define PAUR_TYPE4                      _PAUR.Bits.TYPE4
#define PAUR_TYPE5                      _PAUR.Bits.TYPE5
#define PAUR_TYPE6                      _PAUR.Bits.TYPE6
#define PAUR_TYPE7                      _PAUR.Bits.TYPE7
#define PAUR_TYPE8                      _PAUR.Bits.TYPE8
#define PAUR_TYPE9                      _PAUR.Bits.TYPE9
#define PAUR_TYPE10                     _PAUR.Bits.TYPE10
#define PAUR_TYPE11                     _PAUR.Bits.TYPE11
#define PAUR_TYPE12                     _PAUR.Bits.TYPE12
#define PAUR_TYPE13                     _PAUR.Bits.TYPE13
#define PAUR_TYPE14                     _PAUR.Bits.TYPE14
#define PAUR_TYPE15                     _PAUR.Bits.TYPE15
#define PAUR_PADDR20                    _PAUR.Bits.PADDR20
#define PAUR_PADDR21                    _PAUR.Bits.PADDR21
#define PAUR_PADDR22                    _PAUR.Bits.PADDR22
#define PAUR_PADDR23                    _PAUR.Bits.PADDR23
#define PAUR_PADDR24                    _PAUR.Bits.PADDR24
#define PAUR_PADDR25                    _PAUR.Bits.PADDR25
#define PAUR_PADDR26                    _PAUR.Bits.PADDR26
#define PAUR_PADDR27                    _PAUR.Bits.PADDR27
#define PAUR_PADDR28                    _PAUR.Bits.PADDR28
#define PAUR_PADDR29                    _PAUR.Bits.PADDR29
#define PAUR_PADDR210                   _PAUR.Bits.PADDR210
#define PAUR_PADDR211                   _PAUR.Bits.PADDR211
#define PAUR_PADDR212                   _PAUR.Bits.PADDR212
#define PAUR_PADDR213                   _PAUR.Bits.PADDR213
#define PAUR_PADDR214                   _PAUR.Bits.PADDR214
#define PAUR_PADDR215                   _PAUR.Bits.PADDR215
#define PAUR_TYPE                       _PAUR.MergedBits.grpTYPE
#define PAUR_PADDR2                     _PAUR.MergedBits.grpPADDR2

#define PAUR_TYPE0_MASK                 1UL
#define PAUR_TYPE1_MASK                 2UL
#define PAUR_TYPE2_MASK                 4UL
#define PAUR_TYPE3_MASK                 8UL
#define PAUR_TYPE4_MASK                 16UL
#define PAUR_TYPE5_MASK                 32UL
#define PAUR_TYPE6_MASK                 64UL
#define PAUR_TYPE7_MASK                 128UL
#define PAUR_TYPE8_MASK                 256UL
#define PAUR_TYPE9_MASK                 512UL
#define PAUR_TYPE10_MASK                1024UL
#define PAUR_TYPE11_MASK                2048UL
#define PAUR_TYPE12_MASK                4096UL
#define PAUR_TYPE13_MASK                8192UL
#define PAUR_TYPE14_MASK                16384UL
#define PAUR_TYPE15_MASK                32768UL
#define PAUR_PADDR20_MASK               65536UL
#define PAUR_PADDR21_MASK               131072UL
#define PAUR_PADDR22_MASK               262144UL
#define PAUR_PADDR23_MASK               524288UL
#define PAUR_PADDR24_MASK               1048576UL
#define PAUR_PADDR25_MASK               2097152UL
#define PAUR_PADDR26_MASK               4194304UL
#define PAUR_PADDR27_MASK               8388608UL
#define PAUR_PADDR28_MASK               16777216UL
#define PAUR_PADDR29_MASK               33554432UL
#define PAUR_PADDR210_MASK              67108864UL
#define PAUR_PADDR211_MASK              134217728UL
#define PAUR_PADDR212_MASK              268435456UL
#define PAUR_PADDR213_MASK              536870912UL
#define PAUR_PADDR214_MASK              1073741824UL
#define PAUR_PADDR215_MASK              2147483648UL
#define PAUR_TYPE_MASK                  65535U
#define PAUR_TYPE_BITNUM                0U
#define PAUR_PADDR2_MASK                4294901760U
#define PAUR_PADDR2_BITNUM              16U


/*** OPD - Opcode/Pause Duration Register; 0xFFFFE0EC ***/
typedef union {
  dword Dword;
  struct {
    dword PAUSE_DUR0 :1;                                       /* Pause Duration field used in PAUSE frames, bit 0 */
    dword PAUSE_DUR1 :1;                                       /* Pause Duration field used in PAUSE frames, bit 1 */
    dword PAUSE_DUR2 :1;                                       /* Pause Duration field used in PAUSE frames, bit 2 */
    dword PAUSE_DUR3 :1;                                       /* Pause Duration field used in PAUSE frames, bit 3 */
    dword PAUSE_DUR4 :1;                                       /* Pause Duration field used in PAUSE frames, bit 4 */
    dword PAUSE_DUR5 :1;                                       /* Pause Duration field used in PAUSE frames, bit 5 */
    dword PAUSE_DUR6 :1;                                       /* Pause Duration field used in PAUSE frames, bit 6 */
    dword PAUSE_DUR7 :1;                                       /* Pause Duration field used in PAUSE frames, bit 7 */
    dword PAUSE_DUR8 :1;                                       /* Pause Duration field used in PAUSE frames, bit 8 */
    dword PAUSE_DUR9 :1;                                       /* Pause Duration field used in PAUSE frames, bit 9 */
    dword PAUSE_DUR10 :1;                                      /* Pause Duration field used in PAUSE frames, bit 10 */
    dword PAUSE_DUR11 :1;                                      /* Pause Duration field used in PAUSE frames, bit 11 */
    dword PAUSE_DUR12 :1;                                      /* Pause Duration field used in PAUSE frames, bit 12 */
    dword PAUSE_DUR13 :1;                                      /* Pause Duration field used in PAUSE frames, bit 13 */
    dword PAUSE_DUR14 :1;                                      /* Pause Duration field used in PAUSE frames, bit 14 */
    dword PAUSE_DUR15 :1;                                      /* Pause Duration field used in PAUSE frames, bit 15 */
    dword OPCODE0    :1;                                       /* Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 0 */
    dword OPCODE1    :1;                                       /* Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 1 */
    dword OPCODE2    :1;                                       /* Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 2 */
    dword OPCODE3    :1;                                       /* Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 3 */
    dword OPCODE4    :1;                                       /* Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 4 */
    dword OPCODE5    :1;                                       /* Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 5 */
    dword OPCODE6    :1;                                       /* Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 6 */
    dword OPCODE7    :1;                                       /* Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 7 */
    dword OPCODE8    :1;                                       /* Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 8 */
    dword OPCODE9    :1;                                       /* Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 9 */
    dword OPCODE10   :1;                                       /* Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 10 */
    dword OPCODE11   :1;                                       /* Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 11 */
    dword OPCODE12   :1;                                       /* Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 12 */
    dword OPCODE13   :1;                                       /* Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 13 */
    dword OPCODE14   :1;                                       /* Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 14 */
    dword OPCODE15   :1;                                       /* Opcode field used in PAUSE frames. These bits are a constant, 0x0001, bit 15 */
  } Bits;
  struct {
    dword grpPAUSE_DUR :16;
    dword grpOPCODE :16;
  } MergedBits;
} OPDSTR;
#define _OPD (*(volatile OPDSTR *)0xFFFFE0EC)
#define OPD                             _OPD.Dword
#define OPD_PAUSE_DUR0                  _OPD.Bits.PAUSE_DUR0
#define OPD_PAUSE_DUR1                  _OPD.Bits.PAUSE_DUR1
#define OPD_PAUSE_DUR2                  _OPD.Bits.PAUSE_DUR2
#define OPD_PAUSE_DUR3                  _OPD.Bits.PAUSE_DUR3
#define OPD_PAUSE_DUR4                  _OPD.Bits.PAUSE_DUR4
#define OPD_PAUSE_DUR5                  _OPD.Bits.PAUSE_DUR5
#define OPD_PAUSE_DUR6                  _OPD.Bits.PAUSE_DUR6
#define OPD_PAUSE_DUR7                  _OPD.Bits.PAUSE_DUR7
#define OPD_PAUSE_DUR8                  _OPD.Bits.PAUSE_DUR8
#define OPD_PAUSE_DUR9                  _OPD.Bits.PAUSE_DUR9
#define OPD_PAUSE_DUR10                 _OPD.Bits.PAUSE_DUR10
#define OPD_PAUSE_DUR11                 _OPD.Bits.PAUSE_DUR11
#define OPD_PAUSE_DUR12                 _OPD.Bits.PAUSE_DUR12
#define OPD_PAUSE_DUR13                 _OPD.Bits.PAUSE_DUR13
#define OPD_PAUSE_DUR14                 _OPD.Bits.PAUSE_DUR14
#define OPD_PAUSE_DUR15                 _OPD.Bits.PAUSE_DUR15
#define OPD_OPCODE0                     _OPD.Bits.OPCODE0
#define OPD_OPCODE1                     _OPD.Bits.OPCODE1
#define OPD_OPCODE2                     _OPD.Bits.OPCODE2
#define OPD_OPCODE3                     _OPD.Bits.OPCODE3
#define OPD_OPCODE4                     _OPD.Bits.OPCODE4
#define OPD_OPCODE5                     _OPD.Bits.OPCODE5
#define OPD_OPCODE6                     _OPD.Bits.OPCODE6
#define OPD_OPCODE7                     _OPD.Bits.OPCODE7
#define OPD_OPCODE8                     _OPD.Bits.OPCODE8
#define OPD_OPCODE9                     _OPD.Bits.OPCODE9
#define OPD_OPCODE10                    _OPD.Bits.OPCODE10
#define OPD_OPCODE11                    _OPD.Bits.OPCODE11
#define OPD_OPCODE12                    _OPD.Bits.OPCODE12
#define OPD_OPCODE13                    _OPD.Bits.OPCODE13
#define OPD_OPCODE14                    _OPD.Bits.OPCODE14
#define OPD_OPCODE15                    _OPD.Bits.OPCODE15
#define OPD_PAUSE_DUR                   _OPD.MergedBits.grpPAUSE_DUR
#define OPD_OPCODE                      _OPD.MergedBits.grpOPCODE

#define OPD_PAUSE_DUR0_MASK             1UL
#define OPD_PAUSE_DUR1_MASK             2UL
#define OPD_PAUSE_DUR2_MASK             4UL
#define OPD_PAUSE_DUR3_MASK             8UL
#define OPD_PAUSE_DUR4_MASK             16UL
#define OPD_PAUSE_DUR5_MASK             32UL
#define OPD_PAUSE_DUR6_MASK             64UL
#define OPD_PAUSE_DUR7_MASK             128UL
#define OPD_PAUSE_DUR8_MASK             256UL
#define OPD_PAUSE_DUR9_MASK             512UL
#define OPD_PAUSE_DUR10_MASK            1024UL
#define OPD_PAUSE_DUR11_MASK            2048UL
#define OPD_PAUSE_DUR12_MASK            4096UL
#define OPD_PAUSE_DUR13_MASK            8192UL
#define OPD_PAUSE_DUR14_MASK            16384UL
#define OPD_PAUSE_DUR15_MASK            32768UL
#define OPD_OPCODE0_MASK                65536UL
#define OPD_OPCODE1_MASK                131072UL
#define OPD_OPCODE2_MASK                262144UL
#define OPD_OPCODE3_MASK                524288UL
#define OPD_OPCODE4_MASK                1048576UL
#define OPD_OPCODE5_MASK                2097152UL
#define OPD_OPCODE6_MASK                4194304UL
#define OPD_OPCODE7_MASK                8388608UL
#define OPD_OPCODE8_MASK                16777216UL
#define OPD_OPCODE9_MASK                33554432UL
#define OPD_OPCODE10_MASK               67108864UL
#define OPD_OPCODE11_MASK               134217728UL
#define OPD_OPCODE12_MASK               268435456UL
#define OPD_OPCODE13_MASK               536870912UL
#define OPD_OPCODE14_MASK               1073741824UL
#define OPD_OPCODE15_MASK               2147483648UL
#define OPD_PAUSE_DUR_MASK              65535U
#define OPD_PAUSE_DUR_BITNUM            0U
#define OPD_OPCODE_MASK                 4294901760U
#define OPD_OPCODE_BITNUM               16U


/*** IAUR - Descriptor Individual Upper Address Register; 0xFFFFE118 ***/
typedef union {
  dword Dword;
  struct {
    dword IADDR10    :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 0 */
    dword IADDR11    :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 1 */
    dword IADDR12    :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 2 */
    dword IADDR13    :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 3 */
    dword IADDR14    :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 4 */
    dword IADDR15    :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 5 */
    dword IADDR16    :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 6 */
    dword IADDR17    :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 7 */
    dword IADDR18    :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 8 */
    dword IADDR19    :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 9 */
    dword IADDR110   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 10 */
    dword IADDR111   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 11 */
    dword IADDR112   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 12 */
    dword IADDR113   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 13 */
    dword IADDR114   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 14 */
    dword IADDR115   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 15 */
    dword IADDR116   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 16 */
    dword IADDR117   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 17 */
    dword IADDR118   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 18 */
    dword IADDR119   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 19 */
    dword IADDR120   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 20 */
    dword IADDR121   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 21 */
    dword IADDR122   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 22 */
    dword IADDR123   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 23 */
    dword IADDR124   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 24 */
    dword IADDR125   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 25 */
    dword IADDR126   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 26 */
    dword IADDR127   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 27 */
    dword IADDR128   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 28 */
    dword IADDR129   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 29 */
    dword IADDR130   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 30 */
    dword IADDR131   :1;                                       /* The upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32, bit 31 */
  } Bits;
} IAURSTR;
#define _IAUR (*(volatile IAURSTR *)0xFFFFE118)
#define IAUR                            _IAUR.Dword
#define IAUR_IADDR10                    _IAUR.Bits.IADDR10
#define IAUR_IADDR11                    _IAUR.Bits.IADDR11
#define IAUR_IADDR12                    _IAUR.Bits.IADDR12
#define IAUR_IADDR13                    _IAUR.Bits.IADDR13
#define IAUR_IADDR14                    _IAUR.Bits.IADDR14
#define IAUR_IADDR15                    _IAUR.Bits.IADDR15
#define IAUR_IADDR16                    _IAUR.Bits.IADDR16
#define IAUR_IADDR17                    _IAUR.Bits.IADDR17
#define IAUR_IADDR18                    _IAUR.Bits.IADDR18
#define IAUR_IADDR19                    _IAUR.Bits.IADDR19
#define IAUR_IADDR110                   _IAUR.Bits.IADDR110
#define IAUR_IADDR111                   _IAUR.Bits.IADDR111
#define IAUR_IADDR112                   _IAUR.Bits.IADDR112
#define IAUR_IADDR113                   _IAUR.Bits.IADDR113
#define IAUR_IADDR114                   _IAUR.Bits.IADDR114
#define IAUR_IADDR115                   _IAUR.Bits.IADDR115
#define IAUR_IADDR116                   _IAUR.Bits.IADDR116
#define IAUR_IADDR117                   _IAUR.Bits.IADDR117
#define IAUR_IADDR118                   _IAUR.Bits.IADDR118
#define IAUR_IADDR119                   _IAUR.Bits.IADDR119
#define IAUR_IADDR120                   _IAUR.Bits.IADDR120
#define IAUR_IADDR121                   _IAUR.Bits.IADDR121
#define IAUR_IADDR122                   _IAUR.Bits.IADDR122
#define IAUR_IADDR123                   _IAUR.Bits.IADDR123
#define IAUR_IADDR124                   _IAUR.Bits.IADDR124
#define IAUR_IADDR125                   _IAUR.Bits.IADDR125
#define IAUR_IADDR126                   _IAUR.Bits.IADDR126
#define IAUR_IADDR127                   _IAUR.Bits.IADDR127
#define IAUR_IADDR128                   _IAUR.Bits.IADDR128
#define IAUR_IADDR129                   _IAUR.Bits.IADDR129
#define IAUR_IADDR130                   _IAUR.Bits.IADDR130
#define IAUR_IADDR131                   _IAUR.Bits.IADDR131

#define IAUR_IADDR10_MASK               1UL
#define IAUR_IADDR11_MASK               2UL
#define IAUR_IADDR12_MASK               4UL
#define IAUR_IADDR13_MASK               8UL
#define IAUR_IADDR14_MASK               16UL
#define IAUR_IADDR15_MASK               32UL
#define IAUR_IADDR16_MASK               64UL
#define IAUR_IADDR17_MASK               128UL
#define IAUR_IADDR18_MASK               256UL
#define IAUR_IADDR19_MASK               512UL
#define IAUR_IADDR110_MASK              1024UL
#define IAUR_IADDR111_MASK              2048UL
#define IAUR_IADDR112_MASK              4096UL
#define IAUR_IADDR113_MASK              8192UL
#define IAUR_IADDR114_MASK              16384UL
#define IAUR_IADDR115_MASK              32768UL
#define IAUR_IADDR116_MASK              65536UL
#define IAUR_IADDR117_MASK              131072UL
#define IAUR_IADDR118_MASK              262144UL
#define IAUR_IADDR119_MASK              524288UL
#define IAUR_IADDR120_MASK              1048576UL
#define IAUR_IADDR121_MASK              2097152UL
#define IAUR_IADDR122_MASK              4194304UL
#define IAUR_IADDR123_MASK              8388608UL
#define IAUR_IADDR124_MASK              16777216UL
#define IAUR_IADDR125_MASK              33554432UL
#define IAUR_IADDR126_MASK              67108864UL
#define IAUR_IADDR127_MASK              134217728UL
#define IAUR_IADDR128_MASK              268435456UL
#define IAUR_IADDR129_MASK              536870912UL
#define IAUR_IADDR130_MASK              1073741824UL
#define IAUR_IADDR131_MASK              2147483648UL


/*** IALR - Descriptor Individual Lower Address Register; 0xFFFFE11C ***/
typedef union {
  dword Dword;
  struct {
    dword IADDR20    :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 0 */
    dword IADDR21    :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 1 */
    dword IADDR22    :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 2 */
    dword IADDR23    :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 3 */
    dword IADDR24    :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 4 */
    dword IADDR25    :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 5 */
    dword IADDR26    :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 6 */
    dword IADDR27    :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 7 */
    dword IADDR28    :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 8 */
    dword IADDR29    :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 9 */
    dword IADDR210   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 10 */
    dword IADDR211   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 11 */
    dword IADDR212   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 12 */
    dword IADDR213   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 13 */
    dword IADDR214   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 14 */
    dword IADDR215   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 15 */
    dword IADDR216   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 16 */
    dword IADDR217   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 17 */
    dword IADDR218   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 18 */
    dword IADDR219   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 19 */
    dword IADDR220   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 20 */
    dword IADDR221   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 21 */
    dword IADDR222   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 22 */
    dword IADDR223   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 23 */
    dword IADDR224   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 24 */
    dword IADDR225   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 25 */
    dword IADDR226   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 26 */
    dword IADDR227   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 27 */
    dword IADDR228   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 28 */
    dword IADDR229   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 29 */
    dword IADDR230   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 30 */
    dword IADDR231   :1;                                       /* The lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0, bit 31 */
  } Bits;
} IALRSTR;
#define _IALR (*(volatile IALRSTR *)0xFFFFE11C)
#define IALR                            _IALR.Dword
#define IALR_IADDR20                    _IALR.Bits.IADDR20
#define IALR_IADDR21                    _IALR.Bits.IADDR21
#define IALR_IADDR22                    _IALR.Bits.IADDR22
#define IALR_IADDR23                    _IALR.Bits.IADDR23
#define IALR_IADDR24                    _IALR.Bits.IADDR24
#define IALR_IADDR25                    _IALR.Bits.IADDR25
#define IALR_IADDR26                    _IALR.Bits.IADDR26
#define IALR_IADDR27                    _IALR.Bits.IADDR27
#define IALR_IADDR28                    _IALR.Bits.IADDR28
#define IALR_IADDR29                    _IALR.Bits.IADDR29
#define IALR_IADDR210                   _IALR.Bits.IADDR210
#define IALR_IADDR211                   _IALR.Bits.IADDR211
#define IALR_IADDR212                   _IALR.Bits.IADDR212
#define IALR_IADDR213                   _IALR.Bits.IADDR213
#define IALR_IADDR214                   _IALR.Bits.IADDR214
#define IALR_IADDR215                   _IALR.Bits.IADDR215
#define IALR_IADDR216                   _IALR.Bits.IADDR216
#define IALR_IADDR217                   _IALR.Bits.IADDR217
#define IALR_IADDR218                   _IALR.Bits.IADDR218
#define IALR_IADDR219                   _IALR.Bits.IADDR219
#define IALR_IADDR220                   _IALR.Bits.IADDR220
#define IALR_IADDR221                   _IALR.Bits.IADDR221
#define IALR_IADDR222                   _IALR.Bits.IADDR222
#define IALR_IADDR223                   _IALR.Bits.IADDR223
#define IALR_IADDR224                   _IALR.Bits.IADDR224
#define IALR_IADDR225                   _IALR.Bits.IADDR225
#define IALR_IADDR226                   _IALR.Bits.IADDR226
#define IALR_IADDR227                   _IALR.Bits.IADDR227
#define IALR_IADDR228                   _IALR.Bits.IADDR228
#define IALR_IADDR229                   _IALR.Bits.IADDR229
#define IALR_IADDR230                   _IALR.Bits.IADDR230
#define IALR_IADDR231                   _IALR.Bits.IADDR231

#define IALR_IADDR20_MASK               1UL
#define IALR_IADDR21_MASK               2UL
#define IALR_IADDR22_MASK               4UL
#define IALR_IADDR23_MASK               8UL
#define IALR_IADDR24_MASK               16UL
#define IALR_IADDR25_MASK               32UL
#define IALR_IADDR26_MASK               64UL
#define IALR_IADDR27_MASK               128UL
#define IALR_IADDR28_MASK               256UL
#define IALR_IADDR29_MASK               512UL
#define IALR_IADDR210_MASK              1024UL
#define IALR_IADDR211_MASK              2048UL
#define IALR_IADDR212_MASK              4096UL
#define IALR_IADDR213_MASK              8192UL
#define IALR_IADDR214_MASK              16384UL
#define IALR_IADDR215_MASK              32768UL
#define IALR_IADDR216_MASK              65536UL
#define IALR_IADDR217_MASK              131072UL
#define IALR_IADDR218_MASK              262144UL
#define IALR_IADDR219_MASK              524288UL
#define IALR_IADDR220_MASK              1048576UL
#define IALR_IADDR221_MASK              2097152UL
#define IALR_IADDR222_MASK              4194304UL
#define IALR_IADDR223_MASK              8388608UL
#define IALR_IADDR224_MASK              16777216UL
#define IALR_IADDR225_MASK              33554432UL
#define IALR_IADDR226_MASK              67108864UL
#define IALR_IADDR227_MASK              134217728UL
#define IALR_IADDR228_MASK              268435456UL
#define IALR_IADDR229_MASK              536870912UL
#define IALR_IADDR230_MASK              1073741824UL
#define IALR_IADDR231_MASK              2147483648UL


/*** GAUR - Descriptor Group Upper Address Register; 0xFFFFE120 ***/
typedef union {
  dword Dword;
  struct {
    dword GADDR10    :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 0 */
    dword GADDR11    :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 1 */
    dword GADDR12    :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 2 */
    dword GADDR13    :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 3 */
    dword GADDR14    :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 4 */
    dword GADDR15    :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 5 */
    dword GADDR16    :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 6 */
    dword GADDR17    :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 7 */
    dword GADDR18    :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 8 */
    dword GADDR19    :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 9 */
    dword GADDR110   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 10 */
    dword GADDR111   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 11 */
    dword GADDR112   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 12 */
    dword GADDR113   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 13 */
    dword GADDR114   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 14 */
    dword GADDR115   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 15 */
    dword GADDR116   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 16 */
    dword GADDR117   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 17 */
    dword GADDR118   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 18 */
    dword GADDR119   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 19 */
    dword GADDR120   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 20 */
    dword GADDR121   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 21 */
    dword GADDR122   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 22 */
    dword GADDR123   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 23 */
    dword GADDR124   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 24 */
    dword GADDR125   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 25 */
    dword GADDR126   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 26 */
    dword GADDR127   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 27 */
    dword GADDR128   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 28 */
    dword GADDR129   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 29 */
    dword GADDR130   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 30 */
    dword GADDR131   :1;                                       /* The GADDR1 register contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32, bit 31 */
  } Bits;
} GAURSTR;
#define _GAUR (*(volatile GAURSTR *)0xFFFFE120)
#define GAUR                            _GAUR.Dword
#define GAUR_GADDR10                    _GAUR.Bits.GADDR10
#define GAUR_GADDR11                    _GAUR.Bits.GADDR11
#define GAUR_GADDR12                    _GAUR.Bits.GADDR12
#define GAUR_GADDR13                    _GAUR.Bits.GADDR13
#define GAUR_GADDR14                    _GAUR.Bits.GADDR14
#define GAUR_GADDR15                    _GAUR.Bits.GADDR15
#define GAUR_GADDR16                    _GAUR.Bits.GADDR16
#define GAUR_GADDR17                    _GAUR.Bits.GADDR17
#define GAUR_GADDR18                    _GAUR.Bits.GADDR18
#define GAUR_GADDR19                    _GAUR.Bits.GADDR19
#define GAUR_GADDR110                   _GAUR.Bits.GADDR110
#define GAUR_GADDR111                   _GAUR.Bits.GADDR111
#define GAUR_GADDR112                   _GAUR.Bits.GADDR112
#define GAUR_GADDR113                   _GAUR.Bits.GADDR113
#define GAUR_GADDR114                   _GAUR.Bits.GADDR114
#define GAUR_GADDR115                   _GAUR.Bits.GADDR115
#define GAUR_GADDR116                   _GAUR.Bits.GADDR116
#define GAUR_GADDR117                   _GAUR.Bits.GADDR117
#define GAUR_GADDR118                   _GAUR.Bits.GADDR118
#define GAUR_GADDR119                   _GAUR.Bits.GADDR119
#define GAUR_GADDR120                   _GAUR.Bits.GADDR120
#define GAUR_GADDR121                   _GAUR.Bits.GADDR121
#define GAUR_GADDR122                   _GAUR.Bits.GADDR122
#define GAUR_GADDR123                   _GAUR.Bits.GADDR123
#define GAUR_GADDR124                   _GAUR.Bits.GADDR124
#define GAUR_GADDR125                   _GAUR.Bits.GADDR125
#define GAUR_GADDR126                   _GAUR.Bits.GADDR126
#define GAUR_GADDR127                   _GAUR.Bits.GADDR127
#define GAUR_GADDR128                   _GAUR.Bits.GADDR128
#define GAUR_GADDR129                   _GAUR.Bits.GADDR129
#define GAUR_GADDR130                   _GAUR.Bits.GADDR130
#define GAUR_GADDR131                   _GAUR.Bits.GADDR131

#define GAUR_GADDR10_MASK               1UL
#define GAUR_GADDR11_MASK               2UL
#define GAUR_GADDR12_MASK               4UL
#define GAUR_GADDR13_MASK               8UL
#define GAUR_GADDR14_MASK               16UL
#define GAUR_GADDR15_MASK               32UL
#define GAUR_GADDR16_MASK               64UL
#define GAUR_GADDR17_MASK               128UL
#define GAUR_GADDR18_MASK               256UL
#define GAUR_GADDR19_MASK               512UL
#define GAUR_GADDR110_MASK              1024UL
#define GAUR_GADDR111_MASK              2048UL
#define GAUR_GADDR112_MASK              4096UL
#define GAUR_GADDR113_MASK              8192UL
#define GAUR_GADDR114_MASK              16384UL
#define GAUR_GADDR115_MASK              32768UL
#define GAUR_GADDR116_MASK              65536UL
#define GAUR_GADDR117_MASK              131072UL
#define GAUR_GADDR118_MASK              262144UL
#define GAUR_GADDR119_MASK              524288UL
#define GAUR_GADDR120_MASK              1048576UL
#define GAUR_GADDR121_MASK              2097152UL
#define GAUR_GADDR122_MASK              4194304UL
#define GAUR_GADDR123_MASK              8388608UL
#define GAUR_GADDR124_MASK              16777216UL
#define GAUR_GADDR125_MASK              33554432UL
#define GAUR_GADDR126_MASK              67108864UL
#define GAUR_GADDR127_MASK              134217728UL
#define GAUR_GADDR128_MASK              268435456UL
#define GAUR_GADDR129_MASK              536870912UL
#define GAUR_GADDR130_MASK              1073741824UL
#define GAUR_GADDR131_MASK              2147483648UL


/*** GALR - Descriptor Group Lower Address Register; 0xFFFFE124 ***/
typedef union {
  dword Dword;
  struct {
    dword GADDR20    :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 0 */
    dword GADDR21    :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 1 */
    dword GADDR22    :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 2 */
    dword GADDR23    :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 3 */
    dword GADDR24    :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 4 */
    dword GADDR25    :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 5 */
    dword GADDR26    :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 6 */
    dword GADDR27    :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 7 */
    dword GADDR28    :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 8 */
    dword GADDR29    :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 9 */
    dword GADDR210   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 10 */
    dword GADDR211   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 11 */
    dword GADDR212   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 12 */
    dword GADDR213   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 13 */
    dword GADDR214   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 14 */
    dword GADDR215   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 15 */
    dword GADDR216   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 16 */
    dword GADDR217   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 17 */
    dword GADDR218   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 18 */
    dword GADDR219   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 19 */
    dword GADDR220   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 20 */
    dword GADDR221   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 21 */
    dword GADDR222   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 22 */
    dword GADDR223   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 23 */
    dword GADDR224   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 24 */
    dword GADDR225   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 25 */
    dword GADDR226   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 26 */
    dword GADDR227   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 27 */
    dword GADDR228   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 28 */
    dword GADDR229   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 29 */
    dword GADDR230   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 30 */
    dword GADDR231   :1;                                       /* The GADDR2 register contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0, bit 31 */
  } Bits;
} GALRSTR;
#define _GALR (*(volatile GALRSTR *)0xFFFFE124)
#define GALR                            _GALR.Dword
#define GALR_GADDR20                    _GALR.Bits.GADDR20
#define GALR_GADDR21                    _GALR.Bits.GADDR21
#define GALR_GADDR22                    _GALR.Bits.GADDR22
#define GALR_GADDR23                    _GALR.Bits.GADDR23
#define GALR_GADDR24                    _GALR.Bits.GADDR24
#define GALR_GADDR25                    _GALR.Bits.GADDR25
#define GALR_GADDR26                    _GALR.Bits.GADDR26
#define GALR_GADDR27                    _GALR.Bits.GADDR27
#define GALR_GADDR28                    _GALR.Bits.GADDR28
#define GALR_GADDR29                    _GALR.Bits.GADDR29
#define GALR_GADDR210                   _GALR.Bits.GADDR210
#define GALR_GADDR211                   _GALR.Bits.GADDR211
#define GALR_GADDR212                   _GALR.Bits.GADDR212
#define GALR_GADDR213                   _GALR.Bits.GADDR213
#define GALR_GADDR214                   _GALR.Bits.GADDR214
#define GALR_GADDR215                   _GALR.Bits.GADDR215
#define GALR_GADDR216                   _GALR.Bits.GADDR216
#define GALR_GADDR217                   _GALR.Bits.GADDR217
#define GALR_GADDR218                   _GALR.Bits.GADDR218
#define GALR_GADDR219                   _GALR.Bits.GADDR219
#define GALR_GADDR220                   _GALR.Bits.GADDR220
#define GALR_GADDR221                   _GALR.Bits.GADDR221
#define GALR_GADDR222                   _GALR.Bits.GADDR222
#define GALR_GADDR223                   _GALR.Bits.GADDR223
#define GALR_GADDR224                   _GALR.Bits.GADDR224
#define GALR_GADDR225                   _GALR.Bits.GADDR225
#define GALR_GADDR226                   _GALR.Bits.GADDR226
#define GALR_GADDR227                   _GALR.Bits.GADDR227
#define GALR_GADDR228                   _GALR.Bits.GADDR228
#define GALR_GADDR229                   _GALR.Bits.GADDR229
#define GALR_GADDR230                   _GALR.Bits.GADDR230
#define GALR_GADDR231                   _GALR.Bits.GADDR231

#define GALR_GADDR20_MASK               1UL
#define GALR_GADDR21_MASK               2UL
#define GALR_GADDR22_MASK               4UL
#define GALR_GADDR23_MASK               8UL
#define GALR_GADDR24_MASK               16UL
#define GALR_GADDR25_MASK               32UL
#define GALR_GADDR26_MASK               64UL
#define GALR_GADDR27_MASK               128UL
#define GALR_GADDR28_MASK               256UL
#define GALR_GADDR29_MASK               512UL
#define GALR_GADDR210_MASK              1024UL
#define GALR_GADDR211_MASK              2048UL
#define GALR_GADDR212_MASK              4096UL
#define GALR_GADDR213_MASK              8192UL
#define GALR_GADDR214_MASK              16384UL
#define GALR_GADDR215_MASK              32768UL
#define GALR_GADDR216_MASK              65536UL
#define GALR_GADDR217_MASK              131072UL
#define GALR_GADDR218_MASK              262144UL
#define GALR_GADDR219_MASK              524288UL
#define GALR_GADDR220_MASK              1048576UL
#define GALR_GADDR221_MASK              2097152UL
#define GALR_GADDR222_MASK              4194304UL
#define GALR_GADDR223_MASK              8388608UL
#define GALR_GADDR224_MASK              16777216UL
#define GALR_GADDR225_MASK              33554432UL
#define GALR_GADDR226_MASK              67108864UL
#define GALR_GADDR227_MASK              134217728UL
#define GALR_GADDR228_MASK              268435456UL
#define GALR_GADDR229_MASK              536870912UL
#define GALR_GADDR230_MASK              1073741824UL
#define GALR_GADDR231_MASK              2147483648UL


/*** TFWR - FIFO Transmit FIFO Watermark Register; 0xFFFFE144 ***/
typedef union {
  dword Dword;
  struct {
    dword TFWR0      :1;                                       /* Number of bytes written to transmit FIFO before transmission of a frame begins, bit 0 */
    dword TFWR1      :1;                                       /* Number of bytes written to transmit FIFO before transmission of a frame begins, bit 1 */
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
    dword            :1; 
    dword            :1; 
    dword            :1; 
  } Bits;
  struct {
    dword grpTFWR :2;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
  } MergedBits;
} TFWRSTR;
#define _TFWR (*(volatile TFWRSTR *)0xFFFFE144)
#define TFWR                            _TFWR.Dword
#define TFWR_TFWR0                      _TFWR.Bits.TFWR0
#define TFWR_TFWR1                      _TFWR.Bits.TFWR1
#define TFWR_TFWR                       _TFWR.MergedBits.grpTFWR

#define TFWR_TFWR0_MASK                 1UL
#define TFWR_TFWR1_MASK                 2UL
#define TFWR_TFWR_MASK                  3U
#define TFWR_TFWR_BITNUM                0U


/*** FRBR - FIFO Receive Bound Register; 0xFFFFE14C ***/
typedef union {
  dword Dword;
  struct {
    dword            :1; 
    dword            :1; 
    dword R_BOUND0   :1;                                       /* Read-only. Highest valid FIFO RAM address, bit 0 */
    dword R_BOUND1   :1;                                       /* Read-only. Highest valid FIFO RAM address, bit 1 */
    dword R_BOUND2   :1;                                       /* Read-only. Highest valid FIFO RAM address, bit 2 */
    dword R_BOUND3   :1;                                       /* Read-only. Highest valid FIFO RAM address, bit 3 */
    dword R_BOUND4   :1;                                       /* Read-only. Highest valid FIFO RAM address, bit 4 */
    dword R_BOUND5   :1;                                       /* Read-only. Highest valid FIFO RAM address, bit 5 */
    dword R_BOUND6   :1;                                       /* Read-only. Highest valid FIFO RAM address, bit 6 */
    dword R_BOUND7   :1;                                       /* Read-only. Highest valid FIFO RAM address, bit 7 */
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
  struct {
    dword        :1;
    dword        :1;
    dword grpR_BOUND :8;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
  } MergedBits;
} FRBRSTR;
#define _FRBR (*(volatile FRBRSTR *)0xFFFFE14C)
#define FRBR                            _FRBR.Dword
#define FRBR_R_BOUND0                   _FRBR.Bits.R_BOUND0
#define FRBR_R_BOUND1                   _FRBR.Bits.R_BOUND1
#define FRBR_R_BOUND2                   _FRBR.Bits.R_BOUND2
#define FRBR_R_BOUND3                   _FRBR.Bits.R_BOUND3
#define FRBR_R_BOUND4                   _FRBR.Bits.R_BOUND4
#define FRBR_R_BOUND5                   _FRBR.Bits.R_BOUND5
#define FRBR_R_BOUND6                   _FRBR.Bits.R_BOUND6
#define FRBR_R_BOUND7                   _FRBR.Bits.R_BOUND7
#define FRBR_R_BOUND                    _FRBR.MergedBits.grpR_BOUND

#define FRBR_R_BOUND0_MASK              4UL
#define FRBR_R_BOUND1_MASK              8UL
#define FRBR_R_BOUND2_MASK              16UL
#define FRBR_R_BOUND3_MASK              32UL
#define FRBR_R_BOUND4_MASK              64UL
#define FRBR_R_BOUND5_MASK              128UL
#define FRBR_R_BOUND6_MASK              256UL
#define FRBR_R_BOUND7_MASK              512UL
#define FRBR_R_BOUND_MASK               1020U
#define FRBR_R_BOUND_BITNUM             2U


/*** FRSR - FIFO Receive Start Register; 0xFFFFE150 ***/
typedef union {
  dword Dword;
  struct {
    dword            :1; 
    dword            :1; 
    dword R_FSTART0  :1;                                       /* Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs, bit 0 */
    dword R_FSTART1  :1;                                       /* Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs, bit 1 */
    dword R_FSTART2  :1;                                       /* Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs, bit 2 */
    dword R_FSTART3  :1;                                       /* Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs, bit 3 */
    dword R_FSTART4  :1;                                       /* Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs, bit 4 */
    dword R_FSTART5  :1;                                       /* Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs, bit 5 */
    dword R_FSTART6  :1;                                       /* Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs, bit 6 */
    dword R_FSTART7  :1;                                       /* Address of first receive FIFO location. Acts as delimiter between receive and transmit FIFOs, bit 7 */
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
  struct {
    dword        :1;
    dword        :1;
    dword grpR_FSTART :8;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
  } MergedBits;
} FRSRSTR;
#define _FRSR (*(volatile FRSRSTR *)0xFFFFE150)
#define FRSR                            _FRSR.Dword
#define FRSR_R_FSTART0                  _FRSR.Bits.R_FSTART0
#define FRSR_R_FSTART1                  _FRSR.Bits.R_FSTART1
#define FRSR_R_FSTART2                  _FRSR.Bits.R_FSTART2
#define FRSR_R_FSTART3                  _FRSR.Bits.R_FSTART3
#define FRSR_R_FSTART4                  _FRSR.Bits.R_FSTART4
#define FRSR_R_FSTART5                  _FRSR.Bits.R_FSTART5
#define FRSR_R_FSTART6                  _FRSR.Bits.R_FSTART6
#define FRSR_R_FSTART7                  _FRSR.Bits.R_FSTART7
#define FRSR_R_FSTART                   _FRSR.MergedBits.grpR_FSTART

#define FRSR_R_FSTART0_MASK             4UL
#define FRSR_R_FSTART1_MASK             8UL
#define FRSR_R_FSTART2_MASK             16UL
#define FRSR_R_FSTART3_MASK             32UL
#define FRSR_R_FSTART4_MASK             64UL
#define FRSR_R_FSTART5_MASK             128UL
#define FRSR_R_FSTART6_MASK             256UL
#define FRSR_R_FSTART7_MASK             512UL
#define FRSR_R_FSTART_MASK              1020U
#define FRSR_R_FSTART_BITNUM            2U


/*** ERDSR - Receive Descriptor Ring Start Register; 0xFFFFE180 ***/
typedef union {
  dword Dword;
  struct {
    dword            :1; 
    dword            :1; 
    dword R_DES_START0 :1;                                     /* Pointer to start of receive buffer descriptor queue, bit 0 */
    dword R_DES_START1 :1;                                     /* Pointer to start of receive buffer descriptor queue, bit 1 */
    dword R_DES_START2 :1;                                     /* Pointer to start of receive buffer descriptor queue, bit 2 */
    dword R_DES_START3 :1;                                     /* Pointer to start of receive buffer descriptor queue, bit 3 */
    dword R_DES_START4 :1;                                     /* Pointer to start of receive buffer descriptor queue, bit 4 */
    dword R_DES_START5 :1;                                     /* Pointer to start of receive buffer descriptor queue, bit 5 */
    dword R_DES_START6 :1;                                     /* Pointer to start of receive buffer descriptor queue, bit 6 */
    dword R_DES_START7 :1;                                     /* Pointer to start of receive buffer descriptor queue, bit 7 */
    dword R_DES_START8 :1;                                     /* Pointer to start of receive buffer descriptor queue, bit 8 */
    dword R_DES_START9 :1;                                     /* Pointer to start of receive buffer descriptor queue, bit 9 */
    dword R_DES_START10 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 10 */
    dword R_DES_START11 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 11 */
    dword R_DES_START12 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 12 */
    dword R_DES_START13 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 13 */
    dword R_DES_START14 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 14 */
    dword R_DES_START15 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 15 */
    dword R_DES_START16 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 16 */
    dword R_DES_START17 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 17 */
    dword R_DES_START18 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 18 */
    dword R_DES_START19 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 19 */
    dword R_DES_START20 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 20 */
    dword R_DES_START21 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 21 */
    dword R_DES_START22 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 22 */
    dword R_DES_START23 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 23 */
    dword R_DES_START24 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 24 */
    dword R_DES_START25 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 25 */
    dword R_DES_START26 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 26 */
    dword R_DES_START27 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 27 */
    dword R_DES_START28 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 28 */
    dword R_DES_START29 :1;                                    /* Pointer to start of receive buffer descriptor queue, bit 29 */
  } Bits;
  struct {
    dword        :1;
    dword        :1;
    dword grpR_DES_START :30;
  } MergedBits;
} ERDSRSTR;
#define _ERDSR (*(volatile ERDSRSTR *)0xFFFFE180)
#define ERDSR                           _ERDSR.Dword
#define ERDSR_R_DES_START0              _ERDSR.Bits.R_DES_START0
#define ERDSR_R_DES_START1              _ERDSR.Bits.R_DES_START1
#define ERDSR_R_DES_START2              _ERDSR.Bits.R_DES_START2
#define ERDSR_R_DES_START3              _ERDSR.Bits.R_DES_START3
#define ERDSR_R_DES_START4              _ERDSR.Bits.R_DES_START4
#define ERDSR_R_DES_START5              _ERDSR.Bits.R_DES_START5
#define ERDSR_R_DES_START6              _ERDSR.Bits.R_DES_START6
#define ERDSR_R_DES_START7              _ERDSR.Bits.R_DES_START7
#define ERDSR_R_DES_START8              _ERDSR.Bits.R_DES_START8
#define ERDSR_R_DES_START9              _ERDSR.Bits.R_DES_START9
#define ERDSR_R_DES_START10             _ERDSR.Bits.R_DES_START10
#define ERDSR_R_DES_START11             _ERDSR.Bits.R_DES_START11
#define ERDSR_R_DES_START12             _ERDSR.Bits.R_DES_START12
#define ERDSR_R_DES_START13             _ERDSR.Bits.R_DES_START13
#define ERDSR_R_DES_START14             _ERDSR.Bits.R_DES_START14
#define ERDSR_R_DES_START15             _ERDSR.Bits.R_DES_START15
#define ERDSR_R_DES_START16             _ERDSR.Bits.R_DES_START16
#define ERDSR_R_DES_START17             _ERDSR.Bits.R_DES_START17
#define ERDSR_R_DES_START18             _ERDSR.Bits.R_DES_START18
#define ERDSR_R_DES_START19             _ERDSR.Bits.R_DES_START19
#define ERDSR_R_DES_START20             _ERDSR.Bits.R_DES_START20
#define ERDSR_R_DES_START21             _ERDSR.Bits.R_DES_START21
#define ERDSR_R_DES_START22             _ERDSR.Bits.R_DES_START22
#define ERDSR_R_DES_START23             _ERDSR.Bits.R_DES_START23
#define ERDSR_R_DES_START24             _ERDSR.Bits.R_DES_START24
#define ERDSR_R_DES_START25             _ERDSR.Bits.R_DES_START25
#define ERDSR_R_DES_START26             _ERDSR.Bits.R_DES_START26
#define ERDSR_R_DES_START27             _ERDSR.Bits.R_DES_START27
#define ERDSR_R_DES_START28             _ERDSR.Bits.R_DES_START28
#define ERDSR_R_DES_START29             _ERDSR.Bits.R_DES_START29
#define ERDSR_R_DES_START               _ERDSR.MergedBits.grpR_DES_START

#define ERDSR_R_DES_START0_MASK         4UL
#define ERDSR_R_DES_START1_MASK         8UL
#define ERDSR_R_DES_START2_MASK         16UL
#define ERDSR_R_DES_START3_MASK         32UL
#define ERDSR_R_DES_START4_MASK         64UL
#define ERDSR_R_DES_START5_MASK         128UL
#define ERDSR_R_DES_START6_MASK         256UL
#define ERDSR_R_DES_START7_MASK         512UL
#define ERDSR_R_DES_START8_MASK         1024UL
#define ERDSR_R_DES_START9_MASK         2048UL
#define ERDSR_R_DES_START10_MASK        4096UL
#define ERDSR_R_DES_START11_MASK        8192UL
#define ERDSR_R_DES_START12_MASK        16384UL
#define ERDSR_R_DES_START13_MASK        32768UL
#define ERDSR_R_DES_START14_MASK        65536UL
#define ERDSR_R_DES_START15_MASK        131072UL
#define ERDSR_R_DES_START16_MASK        262144UL
#define ERDSR_R_DES_START17_MASK        524288UL
#define ERDSR_R_DES_START18_MASK        1048576UL
#define ERDSR_R_DES_START19_MASK        2097152UL
#define ERDSR_R_DES_START20_MASK        4194304UL
#define ERDSR_R_DES_START21_MASK        8388608UL
#define ERDSR_R_DES_START22_MASK        16777216UL
#define ERDSR_R_DES_START23_MASK        33554432UL
#define ERDSR_R_DES_START24_MASK        67108864UL
#define ERDSR_R_DES_START25_MASK        134217728UL
#define ERDSR_R_DES_START26_MASK        268435456UL
#define ERDSR_R_DES_START27_MASK        536870912UL
#define ERDSR_R_DES_START28_MASK        1073741824UL
#define ERDSR_R_DES_START29_MASK        2147483648UL
#define ERDSR_R_DES_START_MASK          4294967292U
#define ERDSR_R_DES_START_BITNUM        2U


/*** ETSDR - Transmit Buffer Descriptor Ring Start Register; 0xFFFFE184 ***/
typedef union {
  dword Dword;
  struct {
    dword            :1; 
    dword            :1; 
    dword X_DES_START0 :1;                                     /* Pointer to start of transmit buffer descriptor queue, bit 0 */
    dword X_DES_START1 :1;                                     /* Pointer to start of transmit buffer descriptor queue, bit 1 */
    dword X_DES_START2 :1;                                     /* Pointer to start of transmit buffer descriptor queue, bit 2 */
    dword X_DES_START3 :1;                                     /* Pointer to start of transmit buffer descriptor queue, bit 3 */
    dword X_DES_START4 :1;                                     /* Pointer to start of transmit buffer descriptor queue, bit 4 */
    dword X_DES_START5 :1;                                     /* Pointer to start of transmit buffer descriptor queue, bit 5 */
    dword X_DES_START6 :1;                                     /* Pointer to start of transmit buffer descriptor queue, bit 6 */
    dword X_DES_START7 :1;                                     /* Pointer to start of transmit buffer descriptor queue, bit 7 */
    dword X_DES_START8 :1;                                     /* Pointer to start of transmit buffer descriptor queue, bit 8 */
    dword X_DES_START9 :1;                                     /* Pointer to start of transmit buffer descriptor queue, bit 9 */
    dword X_DES_START10 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 10 */
    dword X_DES_START11 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 11 */
    dword X_DES_START12 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 12 */
    dword X_DES_START13 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 13 */
    dword X_DES_START14 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 14 */
    dword X_DES_START15 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 15 */
    dword X_DES_START16 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 16 */
    dword X_DES_START17 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 17 */
    dword X_DES_START18 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 18 */
    dword X_DES_START19 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 19 */
    dword X_DES_START20 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 20 */
    dword X_DES_START21 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 21 */
    dword X_DES_START22 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 22 */
    dword X_DES_START23 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 23 */
    dword X_DES_START24 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 24 */
    dword X_DES_START25 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 25 */
    dword X_DES_START26 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 26 */
    dword X_DES_START27 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 27 */
    dword X_DES_START28 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 28 */
    dword X_DES_START29 :1;                                    /* Pointer to start of transmit buffer descriptor queue, bit 29 */
  } Bits;
  struct {
    dword        :1;
    dword        :1;
    dword grpX_DES_START :30;
  } MergedBits;
} ETSDRSTR;
#define _ETSDR (*(volatile ETSDRSTR *)0xFFFFE184)
#define ETSDR                           _ETSDR.Dword
#define ETSDR_X_DES_START0              _ETSDR.Bits.X_DES_START0
#define ETSDR_X_DES_START1              _ETSDR.Bits.X_DES_START1
#define ETSDR_X_DES_START2              _ETSDR.Bits.X_DES_START2
#define ETSDR_X_DES_START3              _ETSDR.Bits.X_DES_START3
#define ETSDR_X_DES_START4              _ETSDR.Bits.X_DES_START4
#define ETSDR_X_DES_START5              _ETSDR.Bits.X_DES_START5
#define ETSDR_X_DES_START6              _ETSDR.Bits.X_DES_START6
#define ETSDR_X_DES_START7              _ETSDR.Bits.X_DES_START7
#define ETSDR_X_DES_START8              _ETSDR.Bits.X_DES_START8
#define ETSDR_X_DES_START9              _ETSDR.Bits.X_DES_START9
#define ETSDR_X_DES_START10             _ETSDR.Bits.X_DES_START10
#define ETSDR_X_DES_START11             _ETSDR.Bits.X_DES_START11
#define ETSDR_X_DES_START12             _ETSDR.Bits.X_DES_START12
#define ETSDR_X_DES_START13             _ETSDR.Bits.X_DES_START13
#define ETSDR_X_DES_START14             _ETSDR.Bits.X_DES_START14
#define ETSDR_X_DES_START15             _ETSDR.Bits.X_DES_START15
#define ETSDR_X_DES_START16             _ETSDR.Bits.X_DES_START16
#define ETSDR_X_DES_START17             _ETSDR.Bits.X_DES_START17
#define ETSDR_X_DES_START18             _ETSDR.Bits.X_DES_START18
#define ETSDR_X_DES_START19             _ETSDR.Bits.X_DES_START19
#define ETSDR_X_DES_START20             _ETSDR.Bits.X_DES_START20
#define ETSDR_X_DES_START21             _ETSDR.Bits.X_DES_START21
#define ETSDR_X_DES_START22             _ETSDR.Bits.X_DES_START22
#define ETSDR_X_DES_START23             _ETSDR.Bits.X_DES_START23
#define ETSDR_X_DES_START24             _ETSDR.Bits.X_DES_START24
#define ETSDR_X_DES_START25             _ETSDR.Bits.X_DES_START25
#define ETSDR_X_DES_START26             _ETSDR.Bits.X_DES_START26
#define ETSDR_X_DES_START27             _ETSDR.Bits.X_DES_START27
#define ETSDR_X_DES_START28             _ETSDR.Bits.X_DES_START28
#define ETSDR_X_DES_START29             _ETSDR.Bits.X_DES_START29
#define ETSDR_X_DES_START               _ETSDR.MergedBits.grpX_DES_START

#define ETSDR_X_DES_START0_MASK         4UL
#define ETSDR_X_DES_START1_MASK         8UL
#define ETSDR_X_DES_START2_MASK         16UL
#define ETSDR_X_DES_START3_MASK         32UL
#define ETSDR_X_DES_START4_MASK         64UL
#define ETSDR_X_DES_START5_MASK         128UL
#define ETSDR_X_DES_START6_MASK         256UL
#define ETSDR_X_DES_START7_MASK         512UL
#define ETSDR_X_DES_START8_MASK         1024UL
#define ETSDR_X_DES_START9_MASK         2048UL
#define ETSDR_X_DES_START10_MASK        4096UL
#define ETSDR_X_DES_START11_MASK        8192UL
#define ETSDR_X_DES_START12_MASK        16384UL
#define ETSDR_X_DES_START13_MASK        32768UL
#define ETSDR_X_DES_START14_MASK        65536UL
#define ETSDR_X_DES_START15_MASK        131072UL
#define ETSDR_X_DES_START16_MASK        262144UL
#define ETSDR_X_DES_START17_MASK        524288UL
#define ETSDR_X_DES_START18_MASK        1048576UL
#define ETSDR_X_DES_START19_MASK        2097152UL
#define ETSDR_X_DES_START20_MASK        4194304UL
#define ETSDR_X_DES_START21_MASK        8388608UL
#define ETSDR_X_DES_START22_MASK        16777216UL
#define ETSDR_X_DES_START23_MASK        33554432UL
#define ETSDR_X_DES_START24_MASK        67108864UL
#define ETSDR_X_DES_START25_MASK        134217728UL
#define ETSDR_X_DES_START26_MASK        268435456UL
#define ETSDR_X_DES_START27_MASK        536870912UL
#define ETSDR_X_DES_START28_MASK        1073741824UL
#define ETSDR_X_DES_START29_MASK        2147483648UL
#define ETSDR_X_DES_START_MASK          4294967292U
#define ETSDR_X_DES_START_BITNUM        2U


/*** EMRBR - Receive Buffer Size Register; 0xFFFFE188 ***/
typedef union {
  dword Dword;
  struct {
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword R_BUF_SIZE0 :1;                                      /* Receive buffer size, bit 0 */
    dword R_BUF_SIZE1 :1;                                      /* Receive buffer size, bit 1 */
    dword R_BUF_SIZE2 :1;                                      /* Receive buffer size, bit 2 */
    dword R_BUF_SIZE3 :1;                                      /* Receive buffer size, bit 3 */
    dword R_BUF_SIZE4 :1;                                      /* Receive buffer size, bit 4 */
    dword R_BUF_SIZE5 :1;                                      /* Receive buffer size, bit 5 */
    dword R_BUF_SIZE6 :1;                                      /* Receive buffer size, bit 6 */
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
  struct {
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword grpR_BUF_SIZE :7;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
  } MergedBits;
} EMRBRSTR;
#define _EMRBR (*(volatile EMRBRSTR *)0xFFFFE188)
#define EMRBR                           _EMRBR.Dword
#define EMRBR_R_BUF_SIZE0               _EMRBR.Bits.R_BUF_SIZE0
#define EMRBR_R_BUF_SIZE1               _EMRBR.Bits.R_BUF_SIZE1
#define EMRBR_R_BUF_SIZE2               _EMRBR.Bits.R_BUF_SIZE2
#define EMRBR_R_BUF_SIZE3               _EMRBR.Bits.R_BUF_SIZE3
#define EMRBR_R_BUF_SIZE4               _EMRBR.Bits.R_BUF_SIZE4
#define EMRBR_R_BUF_SIZE5               _EMRBR.Bits.R_BUF_SIZE5
#define EMRBR_R_BUF_SIZE6               _EMRBR.Bits.R_BUF_SIZE6
#define EMRBR_R_BUF_SIZE                _EMRBR.MergedBits.grpR_BUF_SIZE

#define EMRBR_R_BUF_SIZE0_MASK          16UL
#define EMRBR_R_BUF_SIZE1_MASK          32UL
#define EMRBR_R_BUF_SIZE2_MASK          64UL
#define EMRBR_R_BUF_SIZE3_MASK          128UL
#define EMRBR_R_BUF_SIZE4_MASK          256UL
#define EMRBR_R_BUF_SIZE5_MASK          512UL
#define EMRBR_R_BUF_SIZE6_MASK          1024UL
#define EMRBR_R_BUF_SIZE_MASK           2032U
#define EMRBR_R_BUF_SIZE_BITNUM         4U


/*** CSAR0 - Chip Select Address Register 0; 0xFFFFE800 ***/
typedef union {
  dword Dword;
  struct {
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
    dword BA0        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 0 */
    dword BA1        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 1 */
    dword BA2        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 2 */
    dword BA3        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 3 */
    dword BA4        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 4 */
    dword BA5        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 5 */
    dword BA6        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 6 */
    dword BA7        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 7 */
    dword BA8        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 8 */
    dword BA9        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 9 */
    dword BA10       :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 10 */
    dword BA11       :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 11 */
    dword BA12       :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 12 */
    dword BA13       :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 13 */
    dword BA14       :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 14 */
    dword BA15       :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS0. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 15 */
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
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword grpBA  :16;
  } MergedBits;
} CSAR0STR;
#define _CSAR0 (*(volatile CSAR0STR *)0xFFFFE800)
#define CSAR0                           _CSAR0.Dword
#define CSAR0_BA0                       _CSAR0.Bits.BA0
#define CSAR0_BA1                       _CSAR0.Bits.BA1
#define CSAR0_BA2                       _CSAR0.Bits.BA2
#define CSAR0_BA3                       _CSAR0.Bits.BA3
#define CSAR0_BA4                       _CSAR0.Bits.BA4
#define CSAR0_BA5                       _CSAR0.Bits.BA5
#define CSAR0_BA6                       _CSAR0.Bits.BA6
#define CSAR0_BA7                       _CSAR0.Bits.BA7
#define CSAR0_BA8                       _CSAR0.Bits.BA8
#define CSAR0_BA9                       _CSAR0.Bits.BA9
#define CSAR0_BA10                      _CSAR0.Bits.BA10
#define CSAR0_BA11                      _CSAR0.Bits.BA11
#define CSAR0_BA12                      _CSAR0.Bits.BA12
#define CSAR0_BA13                      _CSAR0.Bits.BA13
#define CSAR0_BA14                      _CSAR0.Bits.BA14
#define CSAR0_BA15                      _CSAR0.Bits.BA15
#define CSAR0_BA                        _CSAR0.MergedBits.grpBA

#define CSAR0_BA0_MASK                  65536UL
#define CSAR0_BA1_MASK                  131072UL
#define CSAR0_BA2_MASK                  262144UL
#define CSAR0_BA3_MASK                  524288UL
#define CSAR0_BA4_MASK                  1048576UL
#define CSAR0_BA5_MASK                  2097152UL
#define CSAR0_BA6_MASK                  4194304UL
#define CSAR0_BA7_MASK                  8388608UL
#define CSAR0_BA8_MASK                  16777216UL
#define CSAR0_BA9_MASK                  33554432UL
#define CSAR0_BA10_MASK                 67108864UL
#define CSAR0_BA11_MASK                 134217728UL
#define CSAR0_BA12_MASK                 268435456UL
#define CSAR0_BA13_MASK                 536870912UL
#define CSAR0_BA14_MASK                 1073741824UL
#define CSAR0_BA15_MASK                 2147483648UL
#define CSAR0_BA_MASK                   4294901760U
#define CSAR0_BA_BITNUM                 16U


/*** CSMR0 - Chip Select Mask Register 0; 0xFFFFE804 ***/
typedef union {
  dword Dword;
  struct {
    dword V          :1;                                       /* Valid bit. Indicates whether the corresponding CSAR, CSMR, and CSCR contents are valid. Programmed chip selects do not assert until V is set (except for CS0, which acts as the global chip select). Reset clears each CSMRn[V] */
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword WP         :1;                                       /* Write protect. Controls write accesses to the address range in the corresponding CSAR. Attempting to write to the range of addresses for which CSAR0[WP] = 1 results in the appropriate chip select not being selected. No exception occurs */
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword BAM0       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 0 */
    dword BAM1       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 1 */
    dword BAM2       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 2 */
    dword BAM3       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 3 */
    dword BAM4       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 4 */
    dword BAM5       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 5 */
    dword BAM6       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 6 */
    dword BAM7       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 7 */
    dword BAM8       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 8 */
    dword BAM9       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 9 */
    dword BAM10      :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 10 */
    dword BAM11      :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 11 */
    dword BAM12      :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 12 */
    dword BAM13      :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 13 */
    dword BAM14      :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 14 */
    dword BAM15      :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 15 */
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
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword grpBAM :16;
  } MergedBits;
} CSMR0STR;
#define _CSMR0 (*(volatile CSMR0STR *)0xFFFFE804)
#define CSMR0                           _CSMR0.Dword
#define CSMR0_V                         _CSMR0.Bits.V
#define CSMR0_WP                        _CSMR0.Bits.WP
#define CSMR0_BAM0                      _CSMR0.Bits.BAM0
#define CSMR0_BAM1                      _CSMR0.Bits.BAM1
#define CSMR0_BAM2                      _CSMR0.Bits.BAM2
#define CSMR0_BAM3                      _CSMR0.Bits.BAM3
#define CSMR0_BAM4                      _CSMR0.Bits.BAM4
#define CSMR0_BAM5                      _CSMR0.Bits.BAM5
#define CSMR0_BAM6                      _CSMR0.Bits.BAM6
#define CSMR0_BAM7                      _CSMR0.Bits.BAM7
#define CSMR0_BAM8                      _CSMR0.Bits.BAM8
#define CSMR0_BAM9                      _CSMR0.Bits.BAM9
#define CSMR0_BAM10                     _CSMR0.Bits.BAM10
#define CSMR0_BAM11                     _CSMR0.Bits.BAM11
#define CSMR0_BAM12                     _CSMR0.Bits.BAM12
#define CSMR0_BAM13                     _CSMR0.Bits.BAM13
#define CSMR0_BAM14                     _CSMR0.Bits.BAM14
#define CSMR0_BAM15                     _CSMR0.Bits.BAM15
#define CSMR0_BAM                       _CSMR0.MergedBits.grpBAM

#define CSMR0_V_MASK                    1UL
#define CSMR0_WP_MASK                   256UL
#define CSMR0_BAM0_MASK                 65536UL
#define CSMR0_BAM1_MASK                 131072UL
#define CSMR0_BAM2_MASK                 262144UL
#define CSMR0_BAM3_MASK                 524288UL
#define CSMR0_BAM4_MASK                 1048576UL
#define CSMR0_BAM5_MASK                 2097152UL
#define CSMR0_BAM6_MASK                 4194304UL
#define CSMR0_BAM7_MASK                 8388608UL
#define CSMR0_BAM8_MASK                 16777216UL
#define CSMR0_BAM9_MASK                 33554432UL
#define CSMR0_BAM10_MASK                67108864UL
#define CSMR0_BAM11_MASK                134217728UL
#define CSMR0_BAM12_MASK                268435456UL
#define CSMR0_BAM13_MASK                536870912UL
#define CSMR0_BAM14_MASK                1073741824UL
#define CSMR0_BAM15_MASK                2147483648UL
#define CSMR0_BAM_MASK                  4294901760U
#define CSMR0_BAM_BITNUM                16U


/*** CSCR0 - Chip Select Control Register 0; 0xFFFFE808 ***/
typedef union {
  dword Dword;
  struct {
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword PS0        :1;                                       /* Port size. Specifies the width of the data associated with each chip select. It determines where data is driven during write cycles and where data is sampled during read cycles, bit 0 */
    dword PS1        :1;                                       /* Port size. Specifies the width of the data associated with each chip select. It determines where data is driven during write cycles and where data is sampled during read cycles, bit 1 */
    dword AA         :1;                                       /* Auto-acknowledge enable. Determines the assertion of the internal transfer acknowledge for accesses specified by the chip select address. Note that if AA = 1 for a corresponding CSn and the external system asserts an external TA before the wait-state countdown asserts the internal TA, the cycle is terminated. Burst cycles increment the address bus between each internal termination */
    dword MUX        :1;                                       /* Multiplexed mode */
    dword WS0        :1;                                       /* Wait states. The number of wait states inserted after FB_CSn asserts and before an internal transfer acknowledge<br/>is generated (WS = 0 inserts zero wait states, WS = 0x3F inserts 63 wait states), bit 0 */
    dword WS1        :1;                                       /* Wait states. The number of wait states inserted after FB_CSn asserts and before an internal transfer acknowledge<br/>is generated (WS = 0 inserts zero wait states, WS = 0x3F inserts 63 wait states), bit 1 */
    dword WS2        :1;                                       /* Wait states. The number of wait states inserted after FB_CSn asserts and before an internal transfer acknowledge<br/>is generated (WS = 0 inserts zero wait states, WS = 0x3F inserts 63 wait states), bit 2 */
    dword WS3        :1;                                       /* Wait states. The number of wait states inserted after FB_CSn asserts and before an internal transfer acknowledge<br/>is generated (WS = 0 inserts zero wait states, WS = 0x3F inserts 63 wait states), bit 3 */
    dword WS4        :1;                                       /* Wait states. The number of wait states inserted after FB_CSn asserts and before an internal transfer acknowledge<br/>is generated (WS = 0 inserts zero wait states, WS = 0x3F inserts 63 wait states), bit 4 */
    dword WS5        :1;                                       /* Wait states. The number of wait states inserted after FB_CSn asserts and before an internal transfer acknowledge<br/>is generated (WS = 0 inserts zero wait states, WS = 0x3F inserts 63 wait states), bit 5 */
    dword WRAH0      :1;                                       /* Write address hold or deselect, bit 0 */
    dword WRAH1      :1;                                       /* Write address hold or deselect, bit 1 */
    dword RDAH0      :1;                                       /* Read address hold or deselect, bit 0 */
    dword RDAH1      :1;                                       /* Read address hold or deselect, bit 1 */
    dword ASET0      :1;                                       /* Address setup, bit 0 */
    dword ASET1      :1;                                       /* Address setup, bit 1 */
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
  struct {
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword grpPS  :2;
    dword grpAx  :1;
    dword        :1;
    dword grpWS  :6;
    dword grpWRAH :2;
    dword grpRDAH :2;
    dword grpASET :2;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
  } MergedBits;
} CSCR0STR;
#define _CSCR0 (*(volatile CSCR0STR *)0xFFFFE808)
#define CSCR0                           _CSCR0.Dword
#define CSCR0_PS0                       _CSCR0.Bits.PS0
#define CSCR0_PS1                       _CSCR0.Bits.PS1
#define CSCR0_AA                        _CSCR0.Bits.AA
#define CSCR0_MUX                       _CSCR0.Bits.MUX
#define CSCR0_WS0                       _CSCR0.Bits.WS0
#define CSCR0_WS1                       _CSCR0.Bits.WS1
#define CSCR0_WS2                       _CSCR0.Bits.WS2
#define CSCR0_WS3                       _CSCR0.Bits.WS3
#define CSCR0_WS4                       _CSCR0.Bits.WS4
#define CSCR0_WS5                       _CSCR0.Bits.WS5
#define CSCR0_WRAH0                     _CSCR0.Bits.WRAH0
#define CSCR0_WRAH1                     _CSCR0.Bits.WRAH1
#define CSCR0_RDAH0                     _CSCR0.Bits.RDAH0
#define CSCR0_RDAH1                     _CSCR0.Bits.RDAH1
#define CSCR0_ASET0                     _CSCR0.Bits.ASET0
#define CSCR0_ASET1                     _CSCR0.Bits.ASET1
#define CSCR0_PS                        _CSCR0.MergedBits.grpPS
#define CSCR0_WS                        _CSCR0.MergedBits.grpWS
#define CSCR0_WRAH                      _CSCR0.MergedBits.grpWRAH
#define CSCR0_RDAH                      _CSCR0.MergedBits.grpRDAH
#define CSCR0_ASET                      _CSCR0.MergedBits.grpASET

#define CSCR0_PS0_MASK                  64UL
#define CSCR0_PS1_MASK                  128UL
#define CSCR0_AA_MASK                   256UL
#define CSCR0_MUX_MASK                  512UL
#define CSCR0_WS0_MASK                  1024UL
#define CSCR0_WS1_MASK                  2048UL
#define CSCR0_WS2_MASK                  4096UL
#define CSCR0_WS3_MASK                  8192UL
#define CSCR0_WS4_MASK                  16384UL
#define CSCR0_WS5_MASK                  32768UL
#define CSCR0_WRAH0_MASK                65536UL
#define CSCR0_WRAH1_MASK                131072UL
#define CSCR0_RDAH0_MASK                262144UL
#define CSCR0_RDAH1_MASK                524288UL
#define CSCR0_ASET0_MASK                1048576UL
#define CSCR0_ASET1_MASK                2097152UL
#define CSCR0_PS_MASK                   192U
#define CSCR0_PS_BITNUM                 6U
#define CSCR0_WS_MASK                   64512U
#define CSCR0_WS_BITNUM                 10U
#define CSCR0_WRAH_MASK                 196608U
#define CSCR0_WRAH_BITNUM               16U
#define CSCR0_RDAH_MASK                 786432U
#define CSCR0_RDAH_BITNUM               18U
#define CSCR0_ASET_MASK                 3145728U
#define CSCR0_ASET_BITNUM               20U


/*** CSAR1 - Chip Select Address Register 1; 0xFFFFE80C ***/
typedef union {
  dword Dword;
  struct {
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
    dword BA0        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 0 */
    dword BA1        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 1 */
    dword BA2        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 2 */
    dword BA3        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 3 */
    dword BA4        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 4 */
    dword BA5        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 5 */
    dword BA6        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 6 */
    dword BA7        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 7 */
    dword BA8        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 8 */
    dword BA9        :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 9 */
    dword BA10       :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 10 */
    dword BA11       :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 11 */
    dword BA12       :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 12 */
    dword BA13       :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 13 */
    dword BA14       :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 14 */
    dword BA15       :1;                                       /* Base address. Defines the base address for memory dedicated to chip select CS1. BA is compared to bits 31-16 on the internal address bus to determine if chip select memory is being accessed, bit 15 */
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
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword grpBA  :16;
  } MergedBits;
} CSAR1STR;
#define _CSAR1 (*(volatile CSAR1STR *)0xFFFFE80C)
#define CSAR1                           _CSAR1.Dword
#define CSAR1_BA0                       _CSAR1.Bits.BA0
#define CSAR1_BA1                       _CSAR1.Bits.BA1
#define CSAR1_BA2                       _CSAR1.Bits.BA2
#define CSAR1_BA3                       _CSAR1.Bits.BA3
#define CSAR1_BA4                       _CSAR1.Bits.BA4
#define CSAR1_BA5                       _CSAR1.Bits.BA5
#define CSAR1_BA6                       _CSAR1.Bits.BA6
#define CSAR1_BA7                       _CSAR1.Bits.BA7
#define CSAR1_BA8                       _CSAR1.Bits.BA8
#define CSAR1_BA9                       _CSAR1.Bits.BA9
#define CSAR1_BA10                      _CSAR1.Bits.BA10
#define CSAR1_BA11                      _CSAR1.Bits.BA11
#define CSAR1_BA12                      _CSAR1.Bits.BA12
#define CSAR1_BA13                      _CSAR1.Bits.BA13
#define CSAR1_BA14                      _CSAR1.Bits.BA14
#define CSAR1_BA15                      _CSAR1.Bits.BA15
#define CSAR1_BA                        _CSAR1.MergedBits.grpBA

#define CSAR1_BA0_MASK                  65536UL
#define CSAR1_BA1_MASK                  131072UL
#define CSAR1_BA2_MASK                  262144UL
#define CSAR1_BA3_MASK                  524288UL
#define CSAR1_BA4_MASK                  1048576UL
#define CSAR1_BA5_MASK                  2097152UL
#define CSAR1_BA6_MASK                  4194304UL
#define CSAR1_BA7_MASK                  8388608UL
#define CSAR1_BA8_MASK                  16777216UL
#define CSAR1_BA9_MASK                  33554432UL
#define CSAR1_BA10_MASK                 67108864UL
#define CSAR1_BA11_MASK                 134217728UL
#define CSAR1_BA12_MASK                 268435456UL
#define CSAR1_BA13_MASK                 536870912UL
#define CSAR1_BA14_MASK                 1073741824UL
#define CSAR1_BA15_MASK                 2147483648UL
#define CSAR1_BA_MASK                   4294901760U
#define CSAR1_BA_BITNUM                 16U


/*** CSMR1 - Chip Select Mask Register 1; 0xFFFFE810 ***/
typedef union {
  dword Dword;
  struct {
    dword V          :1;                                       /* Valid bit. Indicates whether the corresponding CSAR, CSMR, and CSCR contents are valid. Programmed chip selects do not assert until V is set. Reset clears each CSMRn[V] */
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword WP         :1;                                       /* Write protect. Controls write accesses to the address range in the corresponding CSAR. Attempting to write to the range of addresses for which CSAR0[WP] = 1 results  results in a bus error termination of the internal cycle and no external <br/>cycle */
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword BAM0       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 0 */
    dword BAM1       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 1 */
    dword BAM2       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 2 */
    dword BAM3       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 3 */
    dword BAM4       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 4 */
    dword BAM5       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 5 */
    dword BAM6       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 6 */
    dword BAM7       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 7 */
    dword BAM8       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 8 */
    dword BAM9       :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 9 */
    dword BAM10      :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 10 */
    dword BAM11      :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 11 */
    dword BAM12      :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 12 */
    dword BAM13      :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 13 */
    dword BAM14      :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 14 */
    dword BAM15      :1;                                       /* Base address mask. Defines the chip select block by masking address bits. Setting a BAM bit causes the corresponding CSAR bit to be ignored in the decode, bit 15 */
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
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword grpBAM :16;
  } MergedBits;
} CSMR1STR;
#define _CSMR1 (*(volatile CSMR1STR *)0xFFFFE810)
#define CSMR1                           _CSMR1.Dword
#define CSMR1_V                         _CSMR1.Bits.V
#define CSMR1_WP                        _CSMR1.Bits.WP
#define CSMR1_BAM0                      _CSMR1.Bits.BAM0
#define CSMR1_BAM1                      _CSMR1.Bits.BAM1
#define CSMR1_BAM2                      _CSMR1.Bits.BAM2
#define CSMR1_BAM3                      _CSMR1.Bits.BAM3
#define CSMR1_BAM4                      _CSMR1.Bits.BAM4
#define CSMR1_BAM5                      _CSMR1.Bits.BAM5
#define CSMR1_BAM6                      _CSMR1.Bits.BAM6
#define CSMR1_BAM7                      _CSMR1.Bits.BAM7
#define CSMR1_BAM8                      _CSMR1.Bits.BAM8
#define CSMR1_BAM9                      _CSMR1.Bits.BAM9
#define CSMR1_BAM10                     _CSMR1.Bits.BAM10
#define CSMR1_BAM11                     _CSMR1.Bits.BAM11
#define CSMR1_BAM12                     _CSMR1.Bits.BAM12
#define CSMR1_BAM13                     _CSMR1.Bits.BAM13
#define CSMR1_BAM14                     _CSMR1.Bits.BAM14
#define CSMR1_BAM15                     _CSMR1.Bits.BAM15
#define CSMR1_BAM                       _CSMR1.MergedBits.grpBAM

#define CSMR1_V_MASK                    1UL
#define CSMR1_WP_MASK                   256UL
#define CSMR1_BAM0_MASK                 65536UL
#define CSMR1_BAM1_MASK                 131072UL
#define CSMR1_BAM2_MASK                 262144UL
#define CSMR1_BAM3_MASK                 524288UL
#define CSMR1_BAM4_MASK                 1048576UL
#define CSMR1_BAM5_MASK                 2097152UL
#define CSMR1_BAM6_MASK                 4194304UL
#define CSMR1_BAM7_MASK                 8388608UL
#define CSMR1_BAM8_MASK                 16777216UL
#define CSMR1_BAM9_MASK                 33554432UL
#define CSMR1_BAM10_MASK                67108864UL
#define CSMR1_BAM11_MASK                134217728UL
#define CSMR1_BAM12_MASK                268435456UL
#define CSMR1_BAM13_MASK                536870912UL
#define CSMR1_BAM14_MASK                1073741824UL
#define CSMR1_BAM15_MASK                2147483648UL
#define CSMR1_BAM_MASK                  4294901760U
#define CSMR1_BAM_BITNUM                16U


/*** CSCR1 - Chip Select Control Register 1; 0xFFFFE814 ***/
typedef union {
  dword Dword;
  struct {
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword            :1; 
    dword PS0        :1;                                       /* Port size. Specifies the width of the data associated with each chip select. It determines where data is driven during write cycles and where data is sampled during read cycles, bit 0 */
    dword PS1        :1;                                       /* Port size. Specifies the width of the data associated with each chip select. It determines where data is driven during write cycles and where data is sampled during read cycles, bit 1 */
    dword AA         :1;                                       /* Auto-acknowledge enable. Determines the assertion of the internal transfer acknowledge for accesses specified by the chip select address. Note that if AA = 1 for a corresponding CSn and the external system asserts an external TA before the wait-state countdown asserts the internal TA, the cycle is terminated. Burst cycles increment the address bus between each internal termination */
    dword MUX        :1;                                       /* Multiplexed mode */
    dword WS0        :1;                                       /* Wait states. The number of wait states inserted after FB_CSn asserts and before an internal transfer acknowledge<br/>is generated (WS = 0 inserts zero wait states, WS = 0x3F inserts 63 wait states), bit 0 */
    dword WS1        :1;                                       /* Wait states. The number of wait states inserted after FB_CSn asserts and before an internal transfer acknowledge<br/>is generated (WS = 0 inserts zero wait states, WS = 0x3F inserts 63 wait states), bit 1 */
    dword WS2        :1;                                       /* Wait states. The number of wait states inserted after FB_CSn asserts and before an internal transfer acknowledge<br/>is generated (WS = 0 inserts zero wait states, WS = 0x3F inserts 63 wait states), bit 2 */
    dword WS3        :1;                                       /* Wait states. The number of wait states inserted after FB_CSn asserts and before an internal transfer acknowledge<br/>is generated (WS = 0 inserts zero wait states, WS = 0x3F inserts 63 wait states), bit 3 */
    dword WS4        :1;                                       /* Wait states. The number of wait states inserted after FB_CSn asserts and before an internal transfer acknowledge<br/>is generated (WS = 0 inserts zero wait states, WS = 0x3F inserts 63 wait states), bit 4 */
    dword WS5        :1;                                       /* Wait states. The number of wait states inserted after FB_CSn asserts and before an internal transfer acknowledge<br/>is generated (WS = 0 inserts zero wait states, WS = 0x3F inserts 63 wait states), bit 5 */
    dword WRAH0      :1;                                       /* Write address hold or deselect, bit 0 */
    dword WRAH1      :1;                                       /* Write address hold or deselect, bit 1 */
    dword RDAH0      :1;                                       /* Read address hold or deselect, bit 0 */
    dword RDAH1      :1;                                       /* Read address hold or deselect, bit 1 */
    dword ASET0      :1;                                       /* Address setup, bit 0 */
    dword ASET1      :1;                                       /* Address setup, bit 1 */
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
  struct {
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword grpPS  :2;
    dword grpAx  :1;
    dword        :1;
    dword grpWS  :6;
    dword grpWRAH :2;
    dword grpRDAH :2;
    dword grpASET :2;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
    dword        :1;
  } MergedBits;
} CSCR1STR;
#define _CSCR1 (*(volatile CSCR1STR *)0xFFFFE814)
#define CSCR1                           _CSCR1.Dword
#define CSCR1_PS0                       _CSCR1.Bits.PS0
#define CSCR1_PS1                       _CSCR1.Bits.PS1
#define CSCR1_AA                        _CSCR1.Bits.AA
#define CSCR1_MUX                       _CSCR1.Bits.MUX
#define CSCR1_WS0                       _CSCR1.Bits.WS0
#define CSCR1_WS1                       _CSCR1.Bits.WS1
#define CSCR1_WS2                       _CSCR1.Bits.WS2
#define CSCR1_WS3                       _CSCR1.Bits.WS3
#define CSCR1_WS4                       _CSCR1.Bits.WS4
#define CSCR1_WS5                       _CSCR1.Bits.WS5
#define CSCR1_WRAH0                     _CSCR1.Bits.WRAH0
#define CSCR1_WRAH1                     _CSCR1.Bits.WRAH1
#define CSCR1_RDAH0                     _CSCR1.Bits.RDAH0
#define CSCR1_RDAH1                     _CSCR1.Bits.RDAH1
#define CSCR1_ASET0                     _CSCR1.Bits.ASET0
#define CSCR1_ASET1                     _CSCR1.Bits.ASET1
#define CSCR1_PS                        _CSCR1.MergedBits.grpPS
#define CSCR1_WS                        _CSCR1.MergedBits.grpWS
#define CSCR1_WRAH                      _CSCR1.MergedBits.grpWRAH
#define CSCR1_RDAH                      _CSCR1.MergedBits.grpRDAH
#define CSCR1_ASET                      _CSCR1.MergedBits.grpASET

#define CSCR1_PS0_MASK                  64UL
#define CSCR1_PS1_MASK                  128UL
#define CSCR1_AA_MASK                   256UL
#define CSCR1_MUX_MASK                  512UL
#define CSCR1_WS0_MASK                  1024UL
#define CSCR1_WS1_MASK                  2048UL
#define CSCR1_WS2_MASK                  4096UL
#define CSCR1_WS3_MASK                  8192UL
#define CSCR1_WS4_MASK                  16384UL
#define CSCR1_WS5_MASK                  32768UL
#define CSCR1_WRAH0_MASK                65536UL
#define CSCR1_WRAH1_MASK                131072UL
#define CSCR1_RDAH0_MASK                262144UL
#define CSCR1_RDAH1_MASK                524288UL
#define CSCR1_ASET0_MASK                1048576UL
#define CSCR1_ASET1_MASK                2097152UL
#define CSCR1_PS_MASK                   192U
#define CSCR1_PS_BITNUM                 6U
#define CSCR1_WS_MASK                   64512U
#define CSCR1_WS_BITNUM                 10U
#define CSCR1_WRAH_MASK                 196608U
#define CSCR1_WRAH_BITNUM               16U
#define CSCR1_RDAH_MASK                 786432U
#define CSCR1_RDAH_BITNUM               18U
#define CSCR1_ASET_MASK                 3145728U
#define CSCR1_ASET_BITNUM               20U


/*** INTC_ORMR - INTC OR Mask Register; 0xFFFFFFCC ***/
typedef union {
  word Word;
  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word SCI3DO      :1;                                       /* Disable (mask) SCI3_OR interrupt request */
    word             :1; 
    word             :1; 
    word FECDO       :1;                                       /* Disable (mask) FEC_Other interrupt request */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} INTC_ORMRSTR;
#define _INTC_ORMR (*(volatile INTC_ORMRSTR *)0xFFFFFFCC)
#define INTC_ORMR                       _INTC_ORMR.Word
#define INTC_ORMR_SCI3DO                _INTC_ORMR.Bits.SCI3DO
#define INTC_ORMR_FECDO                 _INTC_ORMR.Bits.FECDO

#define INTC_ORMR_SCI3DO_MASK           32U
#define INTC_ORMR_FECDO_MASK            256U


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


/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/
/* --------------------------------------------------------------------------- */
/* The following symbols were removed, because they were invalid or irrelevant */
/* --------------------------------------------------------------------------- */



/* **** 7.4.2009 9:04:13 */

#define PTAPF1_A                         This_symb_has_been_depreciated
#define PTAPF2_A                         This_symb_has_been_depreciated
#define PTBPF1_B                         This_symb_has_been_depreciated
#define PTBPF2_B                         This_symb_has_been_depreciated
#define PTCPF1_C                         This_symb_has_been_depreciated
#define PTCPF2_C                         This_symb_has_been_depreciated
#define PTDPF1_D                         This_symb_has_been_depreciated
#define PTDPF2_D                         This_symb_has_been_depreciated
#define PTEPF1_E                         This_symb_has_been_depreciated
#define PTEPF2_E                         This_symb_has_been_depreciated
#define PTFPF1_F                         This_symb_has_been_depreciated
#define PTFPF2_F                         This_symb_has_been_depreciated
#define PTGPF1_G                         This_symb_has_been_depreciated
#define PTGPF2_G                         This_symb_has_been_depreciated
#define PTHPF1_H                         This_symb_has_been_depreciated
#define PTHPF2_H                         This_symb_has_been_depreciated
#define PTJPF1_J                         This_symb_has_been_depreciated
#define PTJPF2_J                         This_symb_has_been_depreciated
#define PAUR_PADDR2_10                   This_symb_has_been_depreciated
#define PAUR_PADDR                       This_symb_has_been_depreciated
#define PAUR_PADDR2_10_MASK              This_symb_has_been_depreciated
#define PAUR_PADDR2_10_BITNUM            This_symb_has_been_depreciated

#if defined(__CWCC__)
  #pragma pop
#elif defined(__GNUC__)
   #pragma pack(pop)
#else
  #error Not supported compiler type
#endif

#endif
/*lint -restore  +esym(961,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */
