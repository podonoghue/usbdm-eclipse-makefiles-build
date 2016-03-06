/**
 * @file      pin_mapping.h (derived from pin_mapping-MKM33Z5.h)
 * @version   1.2.0
 * @brief     Pin declarations for MKM33Z5, generated from MKM33Z5.csv
 *            Devices   [MKM33Z64xxx5, MKM33Z128xxx5]
 *            Reference [MKMxxZxxCxx5RM]
 */

#ifndef PROJECT_HEADERS_PIN_MAPPING_H_
#define PROJECT_HEADERS_PIN_MAPPING_H_

#include <stddef.h>
#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

//================================
// Validators
// <validate=net.sourceforge.usbdm.annotationEditor.validators.PinMappingValidator>

// Pin mapping Options
//
//   <q> Map pins 
//   <i> Selects whether pin mappings are done when individual
//   <i> peripherals are configured or during reset initialisation.
//     <0=> Pins mapped on demand
//     <1=> Pin mapping on reset
#define DO_MAP_PINS_ON_RESET 0

// Pin peripheral signal mapping
//   <e> Mapping by Pin <name=MAP_BY_PIN>
//   <i> This allows the mapping of peripheral functions to pins
//   <i> to be controlled by individual pin
//     <0=> Disabled
//     <1=> Enabled
#define MAP_BY_PIN_ENABLED   1

// <h> Miscellaneous Pins

// Signal mapping for EXTAL32K pin
//   <o>    EXTAL32K (Alias:p26)<name=EXTAL32K_SIG_SEL><constant>
//   <i>    EXTAL32K has no pin-mapping hardware
//   <info> EXTAL32K
//     <-3=> EXTAL32K (fixed)<selection=EXTAL32K_PIN_SEL,EXTAL32K (Alias:p26)>
#define EXTAL32K_SIG_SEL     -3

// Signal mapping for SDADM0 pin
//   <o>    SDADM0 (Alias:p34)<name=SDADM0_SIG_SEL><constant>
//   <i>    SDADM0 has no pin-mapping hardware
//   <info> SDADM0
//     <-3=> SDADM0 (fixed)<selection=SDADM0_PIN_SEL,SDADM0 (Alias:p34)>
#define SDADM0_SIG_SEL       -3

// Signal mapping for SDADM1 pin
//   <o>    SDADM1 (Alias:p36)<name=SDADM1_SIG_SEL><constant>
//   <i>    SDADM1 has no pin-mapping hardware
//   <info> SDADM1
//     <-3=> SDADM1 (fixed)<selection=SDADM1_PIN_SEL,SDADM1 (Alias:p36)>
#define SDADM1_SIG_SEL       -3

// Signal mapping for SDADM2 pin
//   <o>    SDADM2 (Alias:p40)<name=SDADM2_SIG_SEL><constant>
//   <i>    SDADM2 has no pin-mapping hardware
//   <info> SDADM2/CMP1P3
//     <-3=> SDADM2/CMP1P3 (fixed)<selection=SDADM2_PIN_SEL,SDADM2 (Alias:p40)><selection=CMP1P3_PIN_SEL,SDADM2 (Alias:p40)>
#define SDADM2_SIG_SEL       -3

// Signal mapping for SDADM3 pin
//   <o>    SDADM3 (Alias:p43)<name=SDADM3_SIG_SEL><constant>
//   <i>    SDADM3 has no pin-mapping hardware
//   <info> SDADM3/CMP1P5
//     <-3=> SDADM3/CMP1P5 (fixed)<selection=SDADM3_PIN_SEL,SDADM3 (Alias:p43)><selection=CMP1P5_PIN_SEL,SDADM3 (Alias:p43)>
#define SDADM3_SIG_SEL       -3

// Signal mapping for SDADP0 pin
//   <o>    SDADP0 (Alias:p33)<name=SDADP0_SIG_SEL><constant>
//   <i>    SDADP0 has no pin-mapping hardware
//   <info> SDADP0
//     <-3=> SDADP0 (fixed)<selection=SDADP0_PIN_SEL,SDADP0 (Alias:p33)>
#define SDADP0_SIG_SEL       -3

// Signal mapping for SDADP1 pin
//   <o>    SDADP1 (Alias:p35)<name=SDADP1_SIG_SEL><constant>
//   <i>    SDADP1 has no pin-mapping hardware
//   <info> SDADP1
//     <-3=> SDADP1 (fixed)<selection=SDADP1_PIN_SEL,SDADP1 (Alias:p35)>
#define SDADP1_SIG_SEL       -3

// Signal mapping for SDADP2 pin
//   <o>    SDADP2 (Alias:p39)<name=SDADP2_SIG_SEL><constant>
//   <i>    SDADP2 has no pin-mapping hardware
//   <info> SDADP2/CMP1P2
//     <-3=> SDADP2/CMP1P2 (fixed)<selection=SDADP2_PIN_SEL,SDADP2 (Alias:p39)><selection=CMP1P2_PIN_SEL,SDADP2 (Alias:p39)>
#define SDADP2_SIG_SEL       -3

// Signal mapping for SDADP3 pin
//   <o>    SDADP3 (Alias:p42)<name=SDADP3_SIG_SEL><constant>
//   <i>    SDADP3 has no pin-mapping hardware
//   <info> SDADP3/CMP1P4
//     <-3=> SDADP3/CMP1P4 (fixed)<selection=SDADP3_PIN_SEL,SDADP3 (Alias:p42)><selection=CMP1P4_PIN_SEL,SDADP3 (Alias:p42)>
#define SDADP3_SIG_SEL       -3

// Signal mapping for XTAL32K pin
//   <o>    XTAL32K (Alias:p25)<name=XTAL32K_SIG_SEL><constant>
//   <i>    XTAL32K has no pin-mapping hardware
//   <info> XTAL32K
//     <-3=> XTAL32K (fixed)<selection=XTAL32K_PIN_SEL,XTAL32K (Alias:p25)>
#define XTAL32K_SIG_SEL      -3

// </h>

// <h> Port A Pins

// Signal mapping for PTA0 pin
//   <o>    PTA0 (Alias:p1)<name=PTA0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA0 pin
//   <info> LCD23, GPIOA_0
//     <-2=> Disabled (reset default)
//     <0=> LCD23<selection=LCD23_PIN_SEL,PTA0 (Alias:p1)>
//     <1=> GPIOA_0<selection=GPIOA_0_PIN_SEL,PTA0 (Alias:p1)>
//     <1=> Default
#define PTA0_SIG_SEL         1

// Signal mapping for PTA1 pin
//   <o>    PTA1 (Alias:p2)<name=PTA1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA1 pin
//   <info> LCD24, GPIOA_1
//     <-2=> Disabled (reset default)
//     <0=> LCD24<selection=LCD24_PIN_SEL,PTA1 (Alias:p2)>
//     <1=> GPIOA_1<selection=GPIOA_1_PIN_SEL,PTA1 (Alias:p2)>
//     <1=> Default
#define PTA1_SIG_SEL         1

// Signal mapping for PTA2 pin
//   <o>    PTA2 (Alias:p3)<name=PTA2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA2 pin
//   <info> LCD25, GPIOA_2
//     <-2=> Disabled (reset default)
//     <0=> LCD25<selection=LCD25_PIN_SEL,PTA2 (Alias:p3)>
//     <1=> GPIOA_2<selection=GPIOA_2_PIN_SEL,PTA2 (Alias:p3)>
//     <-2=> Default
#define PTA2_SIG_SEL         -2

// Signal mapping for PTA3 pin
//   <o>    PTA3 (Alias:p4)<name=PTA3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA3 pin
//   <info> LCD26, GPIOA_3
//     <-2=> Disabled (reset default)
//     <0=> LCD26<selection=LCD26_PIN_SEL,PTA3 (Alias:p4)>
//     <1=> GPIOA_3<selection=GPIOA_3_PIN_SEL,PTA3 (Alias:p4)>
//     <-2=> Default
#define PTA3_SIG_SEL         -2

// Signal mapping for PTA4 pin
//   <o>    PTA4 (Alias:p5)<name=PTA4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA4 pin
//   <info> LCD27, GPIOA_4, LLWU_P15, NMI_B
//     <-2=> NMI_B (reset default)<selection=NMI_B_PIN_SEL,PTA4 (Alias:p5) (reset default)>
//     <0=> LCD27<selection=LCD27_PIN_SEL,PTA4 (Alias:p5)>
//     <1=> GPIOA_4<selection=GPIOA_4_PIN_SEL,PTA4 (Alias:p5)>
//     <2=> LLWU_P15<selection=LLWU_P15_PIN_SEL,PTA4 (Alias:p5)>
//     <7=> NMI_B<selection=NMI_B_PIN_SEL,PTA4 (Alias:p5)>
//     <-2=> Default
#define PTA4_SIG_SEL         -2

// Signal mapping for PTA5 pin
//   <o>    PTA5 (Alias:p6)<name=PTA5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA5 pin
//   <info> LCD28, GPIOA_5, CMP0OUT
//     <-2=> Disabled (reset default)
//     <0=> LCD28<selection=LCD28_PIN_SEL,PTA5 (Alias:p6)>
//     <1=> GPIOA_5<selection=GPIOA_5_PIN_SEL,PTA5 (Alias:p6)>
//     <2=> CMP0OUT<selection=CMP0OUT_PIN_SEL,PTA5 (Alias:p6)>
//     <-2=> Default
#define PTA5_SIG_SEL         -2

// Signal mapping for PTA6 pin
//   <o>    PTA6 (Alias:p7)<name=PTA6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA6 pin
//   <info> LCD29, GPIOA_6, PXBAR_IN0, LLWU_P14
//     <-2=> Disabled (reset default)
//     <0=> LCD29<selection=LCD29_PIN_SEL,PTA6 (Alias:p7)>
//     <1=> GPIOA_6<selection=GPIOA_6_PIN_SEL,PTA6 (Alias:p7)>
//     <2=> PXBAR_IN0<selection=PXBAR_IN0_PIN_SEL,PTA6 (Alias:p7)>
//     <3=> LLWU_P14<selection=LLWU_P14_PIN_SEL,PTA6 (Alias:p7)>
//     <-2=> Default
#define PTA6_SIG_SEL         -2

// Signal mapping for PTA7 pin
//   <o>    PTA7 (Alias:p8)<name=PTA7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA7 pin
//   <info> LCD30, GPIOA_7, PXBAR_OUT0
//     <-2=> Disabled (reset default)
//     <0=> LCD30<selection=LCD30_PIN_SEL,PTA7 (Alias:p8)>
//     <1=> GPIOA_7<selection=GPIOA_7_PIN_SEL,PTA7 (Alias:p8)>
//     <2=> PXBAR_OUT0<selection=PXBAR_OUT0_PIN_SEL,PTA7 (Alias:p8)>
//     <-2=> Default
#define PTA7_SIG_SEL         -2

// </h>

// <h> Port B Pins

// Signal mapping for PTB0 pin
//   <o>    PTB0 (Alias:p9)<name=PTB0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB0 pin
//   <info> LCD31, GPIOB_0
//     <-2=> Disabled (reset default)
//     <0=> LCD31<selection=LCD31_PIN_SEL,PTB0 (Alias:p9)>
//     <1=> GPIOB_0<selection=GPIOB_0_PIN_SEL,PTB0 (Alias:p9)>
//     <-2=> Default
#define PTB0_SIG_SEL         -2

// Signal mapping for PTB1 pin
//   <o>    PTB1 (Alias:p12)<name=PTB1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB1 pin
//   <info> LCD32, GPIOB_1
//     <-2=> Disabled (reset default)
//     <0=> LCD32<selection=LCD32_PIN_SEL,PTB1 (Alias:p12)>
//     <1=> GPIOB_1<selection=GPIOB_1_PIN_SEL,PTB1 (Alias:p12)>
//     <-2=> Default
#define PTB1_SIG_SEL         -2

// Signal mapping for PTB2 pin
//   <o>    PTB2 (Alias:p13)<name=PTB2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB2 pin
//   <info> LCD33, GPIOB_2
//     <-2=> Disabled (reset default)
//     <0=> LCD33<selection=LCD33_PIN_SEL,PTB2 (Alias:p13)>
//     <1=> GPIOB_2<selection=GPIOB_2_PIN_SEL,PTB2 (Alias:p13)>
//     <-2=> Default
#define PTB2_SIG_SEL         -2

// Signal mapping for PTB3 pin
//   <o>    PTB3 (Alias:p14)<name=PTB3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB3 pin
//   <info> LCD34, GPIOB_3
//     <-2=> Disabled (reset default)
//     <0=> LCD34<selection=LCD34_PIN_SEL,PTB3 (Alias:p14)>
//     <1=> GPIOB_3<selection=GPIOB_3_PIN_SEL,PTB3 (Alias:p14)>
//     <-2=> Default
#define PTB3_SIG_SEL         -2

// Signal mapping for PTB4 pin
//   <o>    PTB4 (Alias:p15)<name=PTB4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB4 pin
//   <info> LCD35, GPIOB_4
//     <-2=> Disabled (reset default)
//     <0=> LCD35<selection=LCD35_PIN_SEL,PTB4 (Alias:p15)>
//     <1=> GPIOB_4<selection=GPIOB_4_PIN_SEL,PTB4 (Alias:p15)>
//     <-2=> Default
#define PTB4_SIG_SEL         -2

// Signal mapping for PTB5 pin
//   <o>    PTB5 (Alias:p16)<name=PTB5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB5 pin
//   <info> LCD36, GPIOB_5
//     <-2=> Disabled (reset default)
//     <0=> LCD36<selection=LCD36_PIN_SEL,PTB5 (Alias:p16)>
//     <1=> GPIOB_5<selection=GPIOB_5_PIN_SEL,PTB5 (Alias:p16)>
//     <-2=> Default
#define PTB5_SIG_SEL         -2

// Signal mapping for PTB6 pin
//   <o>    PTB6 (Alias:p17)<name=PTB6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB6 pin
//   <info> LCD37/CMP1P0, GPIOB_6
//     <-2=> Disabled (reset default)
//     <0=> LCD37/CMP1P0<selection=LCD37_PIN_SEL,PTB6 (Alias:p17)><selection=CMP1P0_PIN_SEL,PTB6 (Alias:p17)>
//     <1=> GPIOB_6<selection=GPIOB_6_PIN_SEL,PTB6 (Alias:p17)>
//     <-2=> Default
#define PTB6_SIG_SEL         -2

// Signal mapping for PTB7 pin
//   <o>    PTB7 (Alias:p18)<name=PTB7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB7 pin
//   <info> LCD38, GPIOB_7, AFE_CLK
//     <-2=> Disabled (reset default)
//     <0=> LCD38<selection=LCD38_PIN_SEL,PTB7 (Alias:p18)>
//     <1=> GPIOB_7<selection=GPIOB_7_PIN_SEL,PTB7 (Alias:p18)>
//     <2=> AFE_CLK<selection=AFE_CLK_PIN_SEL,PTB7 (Alias:p18)>
//     <-2=> Default
#define PTB7_SIG_SEL         -2

// </h>

// <h> Port C Pins

// Signal mapping for PTC0 pin
//   <o>    PTC0 (Alias:p19)<name=PTC0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC0 pin
//   <info> LCD39, GPIOC_0, SCI3_RTS, PXBAR_IN1
//     <-2=> Disabled (reset default)
//     <0=> LCD39<selection=LCD39_PIN_SEL,PTC0 (Alias:p19)>
//     <1=> GPIOC_0<selection=GPIOC_0_PIN_SEL,PTC0 (Alias:p19)>
//     <2=> SCI3_RTS<selection=SCI3_RTS_PIN_SEL,PTC0 (Alias:p19)>
//     <3=> PXBAR_IN1<selection=PXBAR_IN1_PIN_SEL,PTC0 (Alias:p19)>
//     <-2=> Default
#define PTC0_SIG_SEL         -2

// Signal mapping for PTC1 pin
//   <o>    PTC1 (Alias:p20)<name=PTC1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC1 pin
//   <info> LCD40/CMP1P1, GPIOC_1, SCI3_CTS
//     <-2=> Disabled (reset default)
//     <0=> LCD40/CMP1P1<selection=LCD40_PIN_SEL,PTC1 (Alias:p20)><selection=CMP1P1_PIN_SEL,PTC1 (Alias:p20)>
//     <1=> GPIOC_1<selection=GPIOC_1_PIN_SEL,PTC1 (Alias:p20)>
//     <2=> SCI3_CTS<selection=SCI3_CTS_PIN_SEL,PTC1 (Alias:p20)>
//     <-2=> Default
#define PTC1_SIG_SEL         -2

// Signal mapping for PTC2 pin
//   <o>    PTC2 (Alias:p21)<name=PTC2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC2 pin
//   <info> LCD41, GPIOC_2, SCI3_TxD, PXBAR_OUT1
//     <-2=> Disabled (reset default)
//     <0=> LCD41<selection=LCD41_PIN_SEL,PTC2 (Alias:p21)>
//     <1=> GPIOC_2<selection=GPIOC_2_PIN_SEL,PTC2 (Alias:p21)>
//     <2=> SCI3_TxD<selection=SCI3_TxD_PIN_SEL,PTC2 (Alias:p21)>
//     <3=> PXBAR_OUT1<selection=PXBAR_OUT1_PIN_SEL,PTC2 (Alias:p21)>
//     <-2=> Default
#define PTC2_SIG_SEL         -2

// Signal mapping for PTC3 pin
//   <o>    PTC3 (Alias:p22)<name=PTC3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC3 pin
//   <info> LCD42/CMP0P3, GPIOC_3, SCI3_RxD, LLWU_P13
//     <-2=> Disabled (reset default)
//     <0=> LCD42/CMP0P3<selection=LCD42_PIN_SEL,PTC3 (Alias:p22)><selection=CMP0P3_PIN_SEL,PTC3 (Alias:p22)>
//     <1=> GPIOC_3<selection=GPIOC_3_PIN_SEL,PTC3 (Alias:p22)>
//     <2=> SCI3_RxD<selection=SCI3_RxD_PIN_SEL,PTC3 (Alias:p22)>
//     <3=> LLWU_P13<selection=LLWU_P13_PIN_SEL,PTC3 (Alias:p22)>
//     <-2=> Default
#define PTC3_SIG_SEL         -2

// Signal mapping for PTC4 pin
//   <o>    PTC4 (Alias:p23)<name=PTC4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC4 pin
//   <info> LCD43, GPIOC_4
//     <-2=> Disabled (reset default)
//     <0=> LCD43<selection=LCD43_PIN_SEL,PTC4 (Alias:p23)>
//     <1=> GPIOC_4<selection=GPIOC_4_PIN_SEL,PTC4 (Alias:p23)>
//     <-2=> Default
#define PTC4_SIG_SEL         -2

// Signal mapping for PTC5 pin
//   <o>    PTC5 (Alias:p44)<name=PTC5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC5 pin
//   <info> ADC0_SE0, GPIOC_5, SCI0_RTS, LLWU_P12
//     <-2=> Disabled (reset default)
//     <0=> ADC0_SE0<selection=ADC0_SE0_PIN_SEL,PTC5 (Alias:p44)>
//     <1=> GPIOC_5<selection=GPIOC_5_PIN_SEL,PTC5 (Alias:p44)>
//     <2=> SCI0_RTS<selection=SCI0_RTS_PIN_SEL,PTC5 (Alias:p44)>
//     <3=> LLWU_P12<selection=LLWU_P12_PIN_SEL,PTC5 (Alias:p44)>
//     <-2=> Default
#define PTC5_SIG_SEL         -2

// Signal mapping for PTC6 pin
//   <o>    PTC6 (Alias:p45)<name=PTC6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC6 pin
//   <info> ADC0_SE1, GPIOC_6, SCI0_CTS, QT1
//     <-2=> Disabled (reset default)
//     <0=> ADC0_SE1<selection=ADC0_SE1_PIN_SEL,PTC6 (Alias:p45)>
//     <1=> GPIOC_6<selection=GPIOC_6_PIN_SEL,PTC6 (Alias:p45)>
//     <2=> SCI0_CTS<selection=SCI0_CTS_PIN_SEL,PTC6 (Alias:p45)>
//     <3=> QT1<selection=QT1_PIN_SEL,PTC6 (Alias:p45)>
//     <-2=> Default
#define PTC6_SIG_SEL         -2

// Signal mapping for PTC7 pin
//   <o>    PTC7 (Alias:p46)<name=PTC7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC7 pin
//   <info> ADC0_SE2, GPIOC_7, SCI0_TxD, PXBAR_OUT2
//     <-2=> Disabled (reset default)
//     <0=> ADC0_SE2<selection=ADC0_SE2_PIN_SEL,PTC7 (Alias:p46)>
//     <1=> GPIOC_7<selection=GPIOC_7_PIN_SEL,PTC7 (Alias:p46)>
//     <2=> SCI0_TxD<selection=SCI0_TxD_PIN_SEL,PTC7 (Alias:p46)>
//     <3=> PXBAR_OUT2<selection=PXBAR_OUT2_PIN_SEL,PTC7 (Alias:p46)>
//     <-2=> Default
#define PTC7_SIG_SEL         -2

// </h>

// <h> Port D Pins

// Signal mapping for PTD0 pin
//   <o>    PTD0 (Alias:p47)<name=PTD0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD0 pin
//   <info> CMP0P0, GPIOD_0, SCI0_RxD, PXBAR_IN2, LLWU_P11
//     <-2=> Disabled (reset default)
//     <0=> CMP0P0<selection=CMP0P0_PIN_SEL,PTD0 (Alias:p47)>
//     <1=> GPIOD_0<selection=GPIOD_0_PIN_SEL,PTD0 (Alias:p47)>
//     <2=> SCI0_RxD<selection=SCI0_RxD_PIN_SEL,PTD0 (Alias:p47)>
//     <3=> PXBAR_IN2<selection=PXBAR_IN2_PIN_SEL,PTD0 (Alias:p47)>
//     <4=> LLWU_P11<selection=LLWU_P11_PIN_SEL,PTD0 (Alias:p47)>
//     <-2=> Default
#define PTD0_SIG_SEL         -2

// Signal mapping for PTD1 pin
//   <o>    PTD1 (Alias:p48)<name=PTD1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD1 pin
//   <info> GPIOD_1, SCI1_TxD, SPI0_SS_B, PXBAR_OUT3, QT3
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_1<selection=GPIOD_1_PIN_SEL,PTD1 (Alias:p48)>
//     <2=> SCI1_TxD<selection=SCI1_TxD_PIN_SEL,PTD1 (Alias:p48)>
//     <3=> SPI0_SS_B<selection=SPI0_SS_B_PIN_SEL,PTD1 (Alias:p48)>
//     <4=> PXBAR_OUT3<selection=PXBAR_OUT3_PIN_SEL,PTD1 (Alias:p48)>
//     <5=> QT3<selection=QT3_PIN_SEL,PTD1 (Alias:p48)>
//     <1=> Default
#define PTD1_SIG_SEL         1

// Signal mapping for PTD2 pin
//   <o>    PTD2 (Alias:p49)<name=PTD2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD2 pin
//   <info> CMP0P1, GPIOD_2, SCI1_RxD, SPI0_SCK, PXBAR_IN3, LLWU_P10
//     <-2=> Disabled (reset default)
//     <0=> CMP0P1<selection=CMP0P1_PIN_SEL,PTD2 (Alias:p49)>
//     <1=> GPIOD_2<selection=GPIOD_2_PIN_SEL,PTD2 (Alias:p49)>
//     <2=> SCI1_RxD<selection=SCI1_RxD_PIN_SEL,PTD2 (Alias:p49)>
//     <3=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTD2 (Alias:p49)>
//     <4=> PXBAR_IN3<selection=PXBAR_IN3_PIN_SEL,PTD2 (Alias:p49)>
//     <5=> LLWU_P10<selection=LLWU_P10_PIN_SEL,PTD2 (Alias:p49)>
//     <-2=> Default
#define PTD2_SIG_SEL         -2

// Signal mapping for PTD3 pin
//   <o>    PTD3 (Alias:p50)<name=PTD3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD3 pin
//   <info> GPIOD_3, SCI1_CTS, SPI0_MOSI
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_3<selection=GPIOD_3_PIN_SEL,PTD3 (Alias:p50)>
//     <2=> SCI1_CTS<selection=SCI1_CTS_PIN_SEL,PTD3 (Alias:p50)>
//     <3=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTD3 (Alias:p50)>
//     <-2=> Default
#define PTD3_SIG_SEL         -2

// Signal mapping for PTD4 pin
//   <o>    PTD4 (Alias:p51)<name=PTD4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD4 pin
//   <info> ADC0_SE3, GPIOD_4, SCI1_RTS, SPI0_MISO, LLWU_P9
//     <-2=> Disabled (reset default)
//     <0=> ADC0_SE3<selection=ADC0_SE3_PIN_SEL,PTD4 (Alias:p51)>
//     <1=> GPIOD_4<selection=GPIOD_4_PIN_SEL,PTD4 (Alias:p51)>
//     <2=> SCI1_RTS<selection=SCI1_RTS_PIN_SEL,PTD4 (Alias:p51)>
//     <3=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTD4 (Alias:p51)>
//     <4=> LLWU_P9<selection=LLWU_P9_PIN_SEL,PTD4 (Alias:p51)>
//     <-2=> Default
#define PTD4_SIG_SEL         -2

// Signal mapping for PTD5 pin
//   <o>    PTD5 (Alias:p52)<name=PTD5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD5 pin
//   <info> ADC0_SE4, GPIOD_5, LPTMR_ALT2, QT0, SCI3_CTS
//     <-2=> Disabled (reset default)
//     <0=> ADC0_SE4<selection=ADC0_SE4_PIN_SEL,PTD5 (Alias:p52)>
//     <1=> GPIOD_5<selection=GPIOD_5_PIN_SEL,PTD5 (Alias:p52)>
//     <2=> LPTMR_ALT2<selection=LPTMR_ALT2_PIN_SEL,PTD5 (Alias:p52)>
//     <3=> QT0<selection=QT0_PIN_SEL,PTD5 (Alias:p52)>
//     <4=> SCI3_CTS<selection=SCI3_CTS_PIN_SEL,PTD5 (Alias:p52)>
//     <-2=> Default
#define PTD5_SIG_SEL         -2

// Signal mapping for PTD6 pin
//   <o>    PTD6 (Alias:p53)<name=PTD6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD6 pin
//   <info> ADC0_SE5, GPIOD_6, LPTMR_ALT1, CMP1OUT, SCI3_RTS, LLWU_P8
//     <-2=> Disabled (reset default)
//     <0=> ADC0_SE5<selection=ADC0_SE5_PIN_SEL,PTD6 (Alias:p53)>
//     <1=> GPIOD_6<selection=GPIOD_6_PIN_SEL,PTD6 (Alias:p53)>
//     <2=> LPTMR_ALT1<selection=LPTMR_ALT1_PIN_SEL,PTD6 (Alias:p53)>
//     <3=> CMP1OUT<selection=CMP1OUT_PIN_SEL,PTD6 (Alias:p53)>
//     <4=> SCI3_RTS<selection=SCI3_RTS_PIN_SEL,PTD6 (Alias:p53)>
//     <5=> LLWU_P8<selection=LLWU_P8_PIN_SEL,PTD6 (Alias:p53)>
//     <-2=> Default
#define PTD6_SIG_SEL         -2

// Signal mapping for PTD7 pin
//   <o>    PTD7 (Alias:p54)<name=PTD7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD7 pin
//   <info> CMP0P4, GPIOD_7, I2C0_SCL, PXBAR_IN4, SCI3_RxD, LLWU_P7
//     <-2=> Disabled (reset default)
//     <0=> CMP0P4<selection=CMP0P4_PIN_SEL,PTD7 (Alias:p54)>
//     <1=> GPIOD_7<selection=GPIOD_7_PIN_SEL,PTD7 (Alias:p54)>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTD7 (Alias:p54)>
//     <3=> PXBAR_IN4<selection=PXBAR_IN4_PIN_SEL,PTD7 (Alias:p54)>
//     <4=> SCI3_RxD<selection=SCI3_RxD_PIN_SEL,PTD7 (Alias:p54)>
//     <5=> LLWU_P7<selection=LLWU_P7_PIN_SEL,PTD7 (Alias:p54)>
//     <-2=> Default
#define PTD7_SIG_SEL         -2

// </h>

// <h> Port E Pins

// Signal mapping for PTE0 pin
//   <o>    PTE0 (Alias:p55)<name=PTE0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE0 pin
//   <info> GPIOE_0, I2C0_SDA, PXBAR_OUT4, SCI3_TxD, CLKOUT
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_0<selection=GPIOE_0_PIN_SEL,PTE0 (Alias:p55)>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTE0 (Alias:p55)>
//     <3=> PXBAR_OUT4<selection=PXBAR_OUT4_PIN_SEL,PTE0 (Alias:p55)>
//     <4=> SCI3_TxD<selection=SCI3_TxD_PIN_SEL,PTE0 (Alias:p55)>
//     <5=> CLKOUT<selection=CLKOUT_PIN_SEL,PTE0 (Alias:p55)>
//     <-2=> Default
#define PTE0_SIG_SEL         -2

// Signal mapping for PTE1 pin
//   <o>    PTE1 (Alias:p56)<name=PTE1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE1 pin
//   <info> GPIOE_1, RESET_B
//     <-2=> RESET_B (reset default)<selection=RESET_B_PIN_SEL,PTE1 (Alias:p56) (reset default)>
//     <1=> GPIOE_1<selection=GPIOE_1_PIN_SEL,PTE1 (Alias:p56)>
//     <7=> RESET_B<selection=RESET_B_PIN_SEL,PTE1 (Alias:p56)>
//     <-2=> Default
#define PTE1_SIG_SEL         -2

// Signal mapping for PTE2 pin
//   <o>    PTE2 (Alias:p57)<name=PTE2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE2 pin
//   <info> EXTAL1, GPIOE_2, EWM_IN, PXBAR_IN6, I2C1_SDA
//     <-2=> EXTAL1 (reset default)<selection=EXTAL1_PIN_SEL,PTE2 (Alias:p57) (reset default)>
//     <0=> EXTAL1<selection=EXTAL1_PIN_SEL,PTE2 (Alias:p57)>
//     <1=> GPIOE_2<selection=GPIOE_2_PIN_SEL,PTE2 (Alias:p57)>
//     <2=> EWM_IN<selection=EWM_IN_PIN_SEL,PTE2 (Alias:p57)>
//     <3=> PXBAR_IN6<selection=PXBAR_IN6_PIN_SEL,PTE2 (Alias:p57)>
//     <4=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTE2 (Alias:p57)>
//     <-2=> Default
#define PTE2_SIG_SEL         -2

// Signal mapping for PTE3 pin
//   <o>    PTE3 (Alias:p58)<name=PTE3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE3 pin
//   <info> XTAL1, GPIOE_3, EWM_OUT, AFE_CLK, I2C1_SCL
//     <-2=> XTAL1 (reset default)<selection=XTAL1_PIN_SEL,PTE3 (Alias:p58) (reset default)>
//     <0=> XTAL1<selection=XTAL1_PIN_SEL,PTE3 (Alias:p58)>
//     <1=> GPIOE_3<selection=GPIOE_3_PIN_SEL,PTE3 (Alias:p58)>
//     <2=> EWM_OUT<selection=EWM_OUT_PIN_SEL,PTE3 (Alias:p58)>
//     <3=> AFE_CLK<selection=AFE_CLK_PIN_SEL,PTE3 (Alias:p58)>
//     <4=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTE3 (Alias:p58)>
//     <-2=> Default
#define PTE3_SIG_SEL         -2

// Signal mapping for PTE4 pin
//   <o>    PTE4 (Alias:p63)<name=PTE4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE4 pin
//   <info> GPIOE_4, LPTMR_ALT0, SCI2_CTS, EWM_IN
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_4<selection=GPIOE_4_PIN_SEL,PTE4 (Alias:p63)>
//     <2=> LPTMR_ALT0<selection=LPTMR_ALT0_PIN_SEL,PTE4 (Alias:p63)>
//     <3=> SCI2_CTS<selection=SCI2_CTS_PIN_SEL,PTE4 (Alias:p63)>
//     <4=> EWM_IN<selection=EWM_IN_PIN_SEL,PTE4 (Alias:p63)>
//     <-2=> Default
#define PTE4_SIG_SEL         -2

// Signal mapping for PTE5 pin
//   <o>    PTE5 (Alias:p64)<name=PTE5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE5 pin
//   <info> GPIOE_5, QT3, SCI2_RTS, EWM_OUT, LLWU_P6
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_5<selection=GPIOE_5_PIN_SEL,PTE5 (Alias:p64)>
//     <2=> QT3<selection=QT3_PIN_SEL,PTE5 (Alias:p64)>
//     <3=> SCI2_RTS<selection=SCI2_RTS_PIN_SEL,PTE5 (Alias:p64)>
//     <4=> EWM_OUT<selection=EWM_OUT_PIN_SEL,PTE5 (Alias:p64)>
//     <5=> LLWU_P6<selection=LLWU_P6_PIN_SEL,PTE5 (Alias:p64)>
//     <-2=> Default
#define PTE5_SIG_SEL         -2

// Signal mapping for PTE6 pin
//   <o>    PTE6 (Alias:p65)<name=PTE6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE6 pin
//   <info> CMP0P2, GPIOE_6, PXBAR_IN5, SCI2_RxD, LLWU_P5, I2C0_SCL, SWD_IO
//     <-2=> SWD_IO (reset default)<selection=SWD_IO_PIN_SEL,PTE6 (Alias:p65) (reset default)>
//     <0=> CMP0P2<selection=CMP0P2_PIN_SEL,PTE6 (Alias:p65)>
//     <1=> GPIOE_6<selection=GPIOE_6_PIN_SEL,PTE6 (Alias:p65)>
//     <2=> PXBAR_IN5<selection=PXBAR_IN5_PIN_SEL,PTE6 (Alias:p65)>
//     <3=> SCI2_RxD<selection=SCI2_RxD_PIN_SEL,PTE6 (Alias:p65)>
//     <4=> LLWU_P5<selection=LLWU_P5_PIN_SEL,PTE6 (Alias:p65)>
//     <5=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTE6 (Alias:p65)>
//     <7=> SWD_IO<selection=SWD_IO_PIN_SEL,PTE6 (Alias:p65)>
//     <-2=> Default
#define PTE6_SIG_SEL         -2

// Signal mapping for PTE7 pin
//   <o>    PTE7 (Alias:p66)<name=PTE7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE7 pin
//   <info> ADC0_SE6, GPIOE_7, PXBAR_OUT5, SCI2_TxD, I2C0_SDA, SWD_CLK
//     <-2=> SWD_CLK (reset default)<selection=SWD_CLK_PIN_SEL,PTE7 (Alias:p66) (reset default)>
//     <0=> ADC0_SE6<selection=ADC0_SE6_PIN_SEL,PTE7 (Alias:p66)>
//     <1=> GPIOE_7<selection=GPIOE_7_PIN_SEL,PTE7 (Alias:p66)>
//     <2=> PXBAR_OUT5<selection=PXBAR_OUT5_PIN_SEL,PTE7 (Alias:p66)>
//     <3=> SCI2_TxD<selection=SCI2_TxD_PIN_SEL,PTE7 (Alias:p66)>
//     <5=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTE7 (Alias:p66)>
//     <7=> SWD_CLK<selection=SWD_CLK_PIN_SEL,PTE7 (Alias:p66)>
//     <-2=> Default
#define PTE7_SIG_SEL         -2

// </h>

// <h> Port F Pins

// Signal mapping for PTF0 pin
//   <o>    PTF0 (Alias:p67)<name=PTF0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTF0 pin
//   <info> ADC0_SE7, GPIOF_0, RTCCLKOUT, QT2, CMP0OUT, LLWU_P4
//     <-2=> Disabled (reset default)
//     <0=> ADC0_SE7<selection=ADC0_SE7_PIN_SEL,PTF0 (Alias:p67)>
//     <1=> GPIOF_0<selection=GPIOF_0_PIN_SEL,PTF0 (Alias:p67)>
//     <2=> RTCCLKOUT<selection=RTCCLKOUT_PIN_SEL,PTF0 (Alias:p67)>
//     <3=> QT2<selection=QT2_PIN_SEL,PTF0 (Alias:p67)>
//     <4=> CMP0OUT<selection=CMP0OUT_PIN_SEL,PTF0 (Alias:p67)>
//     <5=> LLWU_P4<selection=LLWU_P4_PIN_SEL,PTF0 (Alias:p67)>
//     <-2=> Default
#define PTF0_SIG_SEL         -2

// Signal mapping for PTF1 pin
//   <o>    PTF1 (Alias:p68)<name=PTF1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTF1 pin
//   <info> LCD0/ADC0_SE8, GPIOF_1, QT0, PXBAR_OUT6
//     <-2=> Disabled (reset default)
//     <0=> LCD0/ADC0_SE8<selection=LCD0_PIN_SEL,PTF1 (Alias:p68)><selection=ADC0_SE8_PIN_SEL,PTF1 (Alias:p68)>
//     <1=> GPIOF_1<selection=GPIOF_1_PIN_SEL,PTF1 (Alias:p68)>
//     <2=> QT0<selection=QT0_PIN_SEL,PTF1 (Alias:p68)>
//     <3=> PXBAR_OUT6<selection=PXBAR_OUT6_PIN_SEL,PTF1 (Alias:p68)>
//     <-2=> Default
#define PTF1_SIG_SEL         -2

// Signal mapping for PTF2 pin
//   <o>    PTF2 (Alias:p69)<name=PTF2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTF2 pin
//   <info> LCD1/ADC0_SE9, GPIOF_2, CMP1OUT, RTCCLKOUT
//     <-2=> Disabled (reset default)
//     <0=> LCD1/ADC0_SE9<selection=LCD1_PIN_SEL,PTF2 (Alias:p69)><selection=ADC0_SE9_PIN_SEL,PTF2 (Alias:p69)>
//     <1=> GPIOF_2<selection=GPIOF_2_PIN_SEL,PTF2 (Alias:p69)>
//     <2=> CMP1OUT<selection=CMP1OUT_PIN_SEL,PTF2 (Alias:p69)>
//     <3=> RTCCLKOUT<selection=RTCCLKOUT_PIN_SEL,PTF2 (Alias:p69)>
//     <-2=> Default
#define PTF2_SIG_SEL         -2

// Signal mapping for PTF3 pin
//   <o>    PTF3 (Alias:p70)<name=PTF3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTF3 pin
//   <info> LCD2, GPIOF_3, SPI1_SS_B, LPTMR_ALT1, SCI0_RxD
//     <-2=> Disabled (reset default)
//     <0=> LCD2<selection=LCD2_PIN_SEL,PTF3 (Alias:p70)>
//     <1=> GPIOF_3<selection=GPIOF_3_PIN_SEL,PTF3 (Alias:p70)>
//     <2=> SPI1_SS_B<selection=SPI1_SS_B_PIN_SEL,PTF3 (Alias:p70)>
//     <3=> LPTMR_ALT1<selection=LPTMR_ALT1_PIN_SEL,PTF3 (Alias:p70)>
//     <4=> SCI0_RxD<selection=SCI0_RxD_PIN_SEL,PTF3 (Alias:p70)>
//     <-2=> Default
#define PTF3_SIG_SEL         -2

// Signal mapping for PTF4 pin
//   <o>    PTF4 (Alias:p71)<name=PTF4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTF4 pin
//   <info> LCD3, GPIOF_4, SPI1_SCK, LPTMR_ALT0, SCI0_TxD
//     <-2=> Disabled (reset default)
//     <0=> LCD3<selection=LCD3_PIN_SEL,PTF4 (Alias:p71)>
//     <1=> GPIOF_4<selection=GPIOF_4_PIN_SEL,PTF4 (Alias:p71)>
//     <2=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTF4 (Alias:p71)>
//     <3=> LPTMR_ALT0<selection=LPTMR_ALT0_PIN_SEL,PTF4 (Alias:p71)>
//     <4=> SCI0_TxD<selection=SCI0_TxD_PIN_SEL,PTF4 (Alias:p71)>
//     <-2=> Default
#define PTF4_SIG_SEL         -2

// Signal mapping for PTF5 pin
//   <o>    PTF5 (Alias:p72)<name=PTF5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTF5 pin
//   <info> LCD4, GPIOF_5, SPI1_MISO, I2C1_SCL
//     <-2=> Disabled (reset default)
//     <0=> LCD4<selection=LCD4_PIN_SEL,PTF5 (Alias:p72)>
//     <1=> GPIOF_5<selection=GPIOF_5_PIN_SEL,PTF5 (Alias:p72)>
//     <2=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTF5 (Alias:p72)>
//     <3=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTF5 (Alias:p72)>
//     <-2=> Default
#define PTF5_SIG_SEL         -2

// Signal mapping for PTF6 pin
//   <o>    PTF6 (Alias:p73)<name=PTF6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTF6 pin
//   <info> LCD5, GPIOF_6, SPI1_MOSI, I2C1_SDA, LLWU_P3
//     <-2=> Disabled (reset default)
//     <0=> LCD5<selection=LCD5_PIN_SEL,PTF6 (Alias:p73)>
//     <1=> GPIOF_6<selection=GPIOF_6_PIN_SEL,PTF6 (Alias:p73)>
//     <2=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTF6 (Alias:p73)>
//     <3=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTF6 (Alias:p73)>
//     <4=> LLWU_P3<selection=LLWU_P3_PIN_SEL,PTF6 (Alias:p73)>
//     <-2=> Default
#define PTF6_SIG_SEL         -2

// Signal mapping for PTF7 pin
//   <o>    PTF7 (Alias:p74)<name=PTF7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTF7 pin
//   <info> LCD6, GPIOF_7, QT2, CLKOUT
//     <-2=> Disabled (reset default)
//     <0=> LCD6<selection=LCD6_PIN_SEL,PTF7 (Alias:p74)>
//     <1=> GPIOF_7<selection=GPIOF_7_PIN_SEL,PTF7 (Alias:p74)>
//     <2=> QT2<selection=QT2_PIN_SEL,PTF7 (Alias:p74)>
//     <3=> CLKOUT<selection=CLKOUT_PIN_SEL,PTF7 (Alias:p74)>
//     <-2=> Default
#define PTF7_SIG_SEL         -2

// </h>

// <h> Port G Pins

// Signal mapping for PTG0 pin
//   <o>    PTG0 (Alias:p75)<name=PTG0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTG0 pin
//   <info> LCD7, GPIOG_0, QT1, LPTMR_ALT2
//     <-2=> Disabled (reset default)
//     <0=> LCD7<selection=LCD7_PIN_SEL,PTG0 (Alias:p75)>
//     <1=> GPIOG_0<selection=GPIOG_0_PIN_SEL,PTG0 (Alias:p75)>
//     <2=> QT1<selection=QT1_PIN_SEL,PTG0 (Alias:p75)>
//     <3=> LPTMR_ALT2<selection=LPTMR_ALT2_PIN_SEL,PTG0 (Alias:p75)>
//     <-2=> Default
#define PTG0_SIG_SEL         -2

// Signal mapping for PTG1 pin
//   <o>    PTG1 (Alias:p76)<name=PTG1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTG1 pin
//   <info> LCD8/ADC0_SE10, GPIOG_1, LLWU_P2, LPTMR_ALT0
//     <-2=> Disabled (reset default)
//     <0=> LCD8/ADC0_SE10<selection=LCD8_PIN_SEL,PTG1 (Alias:p76)><selection=ADC0_SE10_PIN_SEL,PTG1 (Alias:p76)>
//     <1=> GPIOG_1<selection=GPIOG_1_PIN_SEL,PTG1 (Alias:p76)>
//     <2=> LLWU_P2<selection=LLWU_P2_PIN_SEL,PTG1 (Alias:p76)>
//     <3=> LPTMR_ALT0<selection=LPTMR_ALT0_PIN_SEL,PTG1 (Alias:p76)>
//     <-2=> Default
#define PTG1_SIG_SEL         -2

// Signal mapping for PTG2 pin
//   <o>    PTG2 (Alias:p77)<name=PTG2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTG2 pin
//   <info> LCD9/ADC0_SE11, GPIOG_2, SPI0_SS_B, LLWU_P1
//     <-2=> Disabled (reset default)
//     <0=> LCD9/ADC0_SE11<selection=LCD9_PIN_SEL,PTG2 (Alias:p77)><selection=ADC0_SE11_PIN_SEL,PTG2 (Alias:p77)>
//     <1=> GPIOG_2<selection=GPIOG_2_PIN_SEL,PTG2 (Alias:p77)>
//     <2=> SPI0_SS_B<selection=SPI0_SS_B_PIN_SEL,PTG2 (Alias:p77)>
//     <3=> LLWU_P1<selection=LLWU_P1_PIN_SEL,PTG2 (Alias:p77)>
//     <-2=> Default
#define PTG2_SIG_SEL         -2

// Signal mapping for PTG3 pin
//   <o>    PTG3 (Alias:p78)<name=PTG3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTG3 pin
//   <info> LCD10, GPIOG_3, SPI0_SCK, I2C0_SCL
//     <-2=> Disabled (reset default)
//     <0=> LCD10<selection=LCD10_PIN_SEL,PTG3 (Alias:p78)>
//     <1=> GPIOG_3<selection=GPIOG_3_PIN_SEL,PTG3 (Alias:p78)>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTG3 (Alias:p78)>
//     <3=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTG3 (Alias:p78)>
//     <-2=> Default
#define PTG3_SIG_SEL         -2

// Signal mapping for PTG4 pin
//   <o>    PTG4 (Alias:p79)<name=PTG4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTG4 pin
//   <info> LCD11, GPIOG_4, SPI0_MOSI, I2C0_SDA
//     <-2=> Disabled (reset default)
//     <0=> LCD11<selection=LCD11_PIN_SEL,PTG4 (Alias:p79)>
//     <1=> GPIOG_4<selection=GPIOG_4_PIN_SEL,PTG4 (Alias:p79)>
//     <2=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTG4 (Alias:p79)>
//     <3=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTG4 (Alias:p79)>
//     <-2=> Default
#define PTG4_SIG_SEL         -2

// Signal mapping for PTG5 pin
//   <o>    PTG5 (Alias:p80)<name=PTG5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTG5 pin
//   <info> LCD12, GPIOG_5, SPI0_MISO, LPTMR_ALT1
//     <-2=> Disabled (reset default)
//     <0=> LCD12<selection=LCD12_PIN_SEL,PTG5 (Alias:p80)>
//     <1=> GPIOG_5<selection=GPIOG_5_PIN_SEL,PTG5 (Alias:p80)>
//     <2=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTG5 (Alias:p80)>
//     <3=> LPTMR_ALT1<selection=LPTMR_ALT1_PIN_SEL,PTG5 (Alias:p80)>
//     <-2=> Default
#define PTG5_SIG_SEL         -2

// Signal mapping for PTG6 pin
//   <o>    PTG6 (Alias:p81)<name=PTG6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTG6 pin
//   <info> LCD13, GPIOG_6, LLWU_P0, LPTMR_ALT2
//     <-2=> Disabled (reset default)
//     <0=> LCD13<selection=LCD13_PIN_SEL,PTG6 (Alias:p81)>
//     <1=> GPIOG_6<selection=GPIOG_6_PIN_SEL,PTG6 (Alias:p81)>
//     <2=> LLWU_P0<selection=LLWU_P0_PIN_SEL,PTG6 (Alias:p81)>
//     <3=> LPTMR_ALT2<selection=LPTMR_ALT2_PIN_SEL,PTG6 (Alias:p81)>
//     <-2=> Default
#define PTG6_SIG_SEL         -2

// Signal mapping for PTG7 pin
//   <o>    PTG7 (Alias:p82)<name=PTG7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTG7 pin
//   <info> LCD14, GPIOG_7
//     <-2=> Disabled (reset default)
//     <0=> LCD14<selection=LCD14_PIN_SEL,PTG7 (Alias:p82)>
//     <1=> GPIOG_7<selection=GPIOG_7_PIN_SEL,PTG7 (Alias:p82)>
//     <-2=> Default
#define PTG7_SIG_SEL         -2

// </h>

// <h> Port H Pins

// Signal mapping for PTH0 pin
//   <o>    PTH0 (Alias:p83)<name=PTH0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTH0 pin
//   <info> LCD15, GPIOH_0
//     <-2=> Disabled (reset default)
//     <0=> LCD15<selection=LCD15_PIN_SEL,PTH0 (Alias:p83)>
//     <1=> GPIOH_0<selection=GPIOH_0_PIN_SEL,PTH0 (Alias:p83)>
//     <-2=> Default
#define PTH0_SIG_SEL         -2

// Signal mapping for PTH1 pin
//   <o>    PTH1 (Alias:p84)<name=PTH1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTH1 pin
//   <info> LCD16, GPIOH_1
//     <-2=> Disabled (reset default)
//     <0=> LCD16<selection=LCD16_PIN_SEL,PTH1 (Alias:p84)>
//     <1=> GPIOH_1<selection=GPIOH_1_PIN_SEL,PTH1 (Alias:p84)>
//     <-2=> Default
#define PTH1_SIG_SEL         -2

// Signal mapping for PTH2 pin
//   <o>    PTH2 (Alias:p85)<name=PTH2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTH2 pin
//   <info> LCD17, GPIOH_2
//     <-2=> Disabled (reset default)
//     <0=> LCD17<selection=LCD17_PIN_SEL,PTH2 (Alias:p85)>
//     <1=> GPIOH_2<selection=GPIOH_2_PIN_SEL,PTH2 (Alias:p85)>
//     <-2=> Default
#define PTH2_SIG_SEL         -2

// Signal mapping for PTH3 pin
//   <o>    PTH3 (Alias:p86)<name=PTH3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTH3 pin
//   <info> LCD18, GPIOH_3
//     <-2=> Disabled (reset default)
//     <0=> LCD18<selection=LCD18_PIN_SEL,PTH3 (Alias:p86)>
//     <1=> GPIOH_3<selection=GPIOH_3_PIN_SEL,PTH3 (Alias:p86)>
//     <-2=> Default
#define PTH3_SIG_SEL         -2

// Signal mapping for PTH4 pin
//   <o>    PTH4 (Alias:p87)<name=PTH4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTH4 pin
//   <info> LCD19, GPIOH_4
//     <-2=> Disabled (reset default)
//     <0=> LCD19<selection=LCD19_PIN_SEL,PTH4 (Alias:p87)>
//     <1=> GPIOH_4<selection=GPIOH_4_PIN_SEL,PTH4 (Alias:p87)>
//     <-2=> Default
#define PTH4_SIG_SEL         -2

// Signal mapping for PTH5 pin
//   <o>    PTH5 (Alias:p88)<name=PTH5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTH5 pin
//   <info> LCD20, GPIOH_5
//     <-2=> Disabled (reset default)
//     <0=> LCD20<selection=LCD20_PIN_SEL,PTH5 (Alias:p88)>
//     <1=> GPIOH_5<selection=GPIOH_5_PIN_SEL,PTH5 (Alias:p88)>
//     <-2=> Default
#define PTH5_SIG_SEL         -2

// Signal mapping for PTH6 pin
//   <o>    PTH6 (Alias:p89)<name=PTH6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTH6 pin
//   <info> GPIOH_6, SCI1_CTS, SPI1_SS_B, PXBAR_IN7
//     <-2=> Disabled (reset default)
//     <1=> GPIOH_6<selection=GPIOH_6_PIN_SEL,PTH6 (Alias:p89)>
//     <2=> SCI1_CTS<selection=SCI1_CTS_PIN_SEL,PTH6 (Alias:p89)>
//     <3=> SPI1_SS_B<selection=SPI1_SS_B_PIN_SEL,PTH6 (Alias:p89)>
//     <4=> PXBAR_IN7<selection=PXBAR_IN7_PIN_SEL,PTH6 (Alias:p89)>
//     <-2=> Default
#define PTH6_SIG_SEL         -2

// Signal mapping for PTH7 pin
//   <o>    PTH7 (Alias:p90)<name=PTH7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTH7 pin
//   <info> GPIOH_7, SCI1_RTS, SPI1_SCK, PXBAR_OUT7
//     <-2=> Disabled (reset default)
//     <1=> GPIOH_7<selection=GPIOH_7_PIN_SEL,PTH7 (Alias:p90)>
//     <2=> SCI1_RTS<selection=SCI1_RTS_PIN_SEL,PTH7 (Alias:p90)>
//     <3=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTH7 (Alias:p90)>
//     <4=> PXBAR_OUT7<selection=PXBAR_OUT7_PIN_SEL,PTH7 (Alias:p90)>
//     <-2=> Default
#define PTH7_SIG_SEL         -2

// </h>

// <h> Port I Pins

// Signal mapping for PTI0 pin
//   <o>    PTI0 (Alias:p91)<name=PTI0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTI0 pin
//   <info> CMP0P5, GPIOI_0, SCI1_RxD, PXBAR_IN8, SPI1_MISO, SPI1_MOSI
//     <-2=> Disabled (reset default)
//     <0=> CMP0P5<selection=CMP0P5_PIN_SEL,PTI0 (Alias:p91)>
//     <1=> GPIOI_0<selection=GPIOI_0_PIN_SEL,PTI0 (Alias:p91)>
//     <2=> SCI1_RxD<selection=SCI1_RxD_PIN_SEL,PTI0 (Alias:p91)>
//     <3=> PXBAR_IN8<selection=PXBAR_IN8_PIN_SEL,PTI0 (Alias:p91)>
//     <4=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTI0 (Alias:p91)>
//     <5=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTI0 (Alias:p91)>
//     <-2=> Default
#define PTI0_SIG_SEL         -2

// Signal mapping for PTI1 pin
//   <o>    PTI1 (Alias:p92)<name=PTI1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTI1 pin
//   <info> GPIOI_1, SCI1_TxD, PXBAR_OUT8, SPI1_MOSI, SPI1_MISO
//     <-2=> Disabled (reset default)
//     <1=> GPIOI_1<selection=GPIOI_1_PIN_SEL,PTI1 (Alias:p92)>
//     <2=> SCI1_TxD<selection=SCI1_TxD_PIN_SEL,PTI1 (Alias:p92)>
//     <3=> PXBAR_OUT8<selection=PXBAR_OUT8_PIN_SEL,PTI1 (Alias:p92)>
//     <4=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTI1 (Alias:p92)>
//     <5=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTI1 (Alias:p92)>
//     <-2=> Default
#define PTI1_SIG_SEL         -2

// Signal mapping for PTI2 pin
//   <o>    PTI2 (Alias:p93)<name=PTI2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTI2 pin
//   <info> LCD21, GPIOI_2
//     <-2=> Disabled (reset default)
//     <0=> LCD21<selection=LCD21_PIN_SEL,PTI2 (Alias:p93)>
//     <1=> GPIOI_2<selection=GPIOI_2_PIN_SEL,PTI2 (Alias:p93)>
//     <-2=> Default
#define PTI2_SIG_SEL         -2

// Signal mapping for PTI3 pin
//   <o>    PTI3 (Alias:p94)<name=PTI3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTI3 pin
//   <info> LCD22, GPIOI_3
//     <-2=> Disabled (reset default)
//     <0=> LCD22<selection=LCD22_PIN_SEL,PTI3 (Alias:p94)>
//     <1=> GPIOI_3<selection=GPIOI_3_PIN_SEL,PTI3 (Alias:p94)>
//     <-2=> Default
#define PTI3_SIG_SEL         -2

// </h>

// </e>

// Pin peripheral signal mapping
//   <e> Mapping by Peripheral Function <name=MAP_BY_FUNCTION><constant>
//   <i> This allows the mapping of peripheral functions to pins
//   <i> to be controlled by peripheral function.
//   <i> This option is active when Mapping by Pin is disabled
//     <0=> Disabled
//     <1=> Enabled
#define MAP_BY_FUNCTION_ENABLED 0

// <h> Miscellaneous

// Pin Mapping for LCD0 signal
//   <o>    LCD0<name=LCD0_PIN_SEL>
//   <i>    Shows which pin LCD0 is mapped to
//   <info>  [PTF1]
//     <0=> Disabled
//     <1=> PTF1 (Alias:p68)<selection=PTF1_SIG_SEL,LCD0/ADC0_SE8>
//     <0=> Default
#define LCD0_PIN_SEL         0

// Pin Mapping for LCD1 signal
//   <o>    LCD1<name=LCD1_PIN_SEL>
//   <i>    Shows which pin LCD1 is mapped to
//   <info>  [PTF2]
//     <0=> Disabled
//     <1=> PTF2 (Alias:p69)<selection=PTF2_SIG_SEL,LCD1/ADC0_SE9>
//     <0=> Default
#define LCD1_PIN_SEL         0

// Pin Mapping for LCD2 signal
//   <o>    LCD2<name=LCD2_PIN_SEL>
//   <i>    Shows which pin LCD2 is mapped to
//   <info>  [PTF3]
//     <0=> Disabled
//     <1=> PTF3 (Alias:p70)<selection=PTF3_SIG_SEL,LCD2>
//     <0=> Default
#define LCD2_PIN_SEL         0

// Pin Mapping for LCD3 signal
//   <o>    LCD3<name=LCD3_PIN_SEL>
//   <i>    Shows which pin LCD3 is mapped to
//   <info>  [PTF4]
//     <0=> Disabled
//     <1=> PTF4 (Alias:p71)<selection=PTF4_SIG_SEL,LCD3>
//     <0=> Default
#define LCD3_PIN_SEL         0

// Pin Mapping for LCD4 signal
//   <o>    LCD4<name=LCD4_PIN_SEL>
//   <i>    Shows which pin LCD4 is mapped to
//   <info>  [PTF5]
//     <0=> Disabled
//     <1=> PTF5 (Alias:p72)<selection=PTF5_SIG_SEL,LCD4>
//     <0=> Default
#define LCD4_PIN_SEL         0

// Pin Mapping for LCD5 signal
//   <o>    LCD5<name=LCD5_PIN_SEL>
//   <i>    Shows which pin LCD5 is mapped to
//   <info>  [PTF6]
//     <0=> Disabled
//     <1=> PTF6 (Alias:p73)<selection=PTF6_SIG_SEL,LCD5>
//     <0=> Default
#define LCD5_PIN_SEL         0

// Pin Mapping for LCD6 signal
//   <o>    LCD6<name=LCD6_PIN_SEL>
//   <i>    Shows which pin LCD6 is mapped to
//   <info>  [PTF7]
//     <0=> Disabled
//     <1=> PTF7 (Alias:p74)<selection=PTF7_SIG_SEL,LCD6>
//     <0=> Default
#define LCD6_PIN_SEL         0

// Pin Mapping for LCD7 signal
//   <o>    LCD7<name=LCD7_PIN_SEL>
//   <i>    Shows which pin LCD7 is mapped to
//   <info>  [PTG0]
//     <0=> Disabled
//     <1=> PTG0 (Alias:p75)<selection=PTG0_SIG_SEL,LCD7>
//     <0=> Default
#define LCD7_PIN_SEL         0

// Pin Mapping for LCD8 signal
//   <o>    LCD8<name=LCD8_PIN_SEL>
//   <i>    Shows which pin LCD8 is mapped to
//   <info>  [PTG1]
//     <0=> Disabled
//     <1=> PTG1 (Alias:p76)<selection=PTG1_SIG_SEL,LCD8/ADC0_SE10>
//     <0=> Default
#define LCD8_PIN_SEL         0

// Pin Mapping for LCD9 signal
//   <o>    LCD9<name=LCD9_PIN_SEL>
//   <i>    Shows which pin LCD9 is mapped to
//   <info>  [PTG2]
//     <0=> Disabled
//     <1=> PTG2 (Alias:p77)<selection=PTG2_SIG_SEL,LCD9/ADC0_SE11>
//     <0=> Default
#define LCD9_PIN_SEL         0

// Pin Mapping for LCD10 signal
//   <o>    LCD10<name=LCD10_PIN_SEL>
//   <i>    Shows which pin LCD10 is mapped to
//   <info>  [PTG3]
//     <0=> Disabled
//     <1=> PTG3 (Alias:p78)<selection=PTG3_SIG_SEL,LCD10>
//     <0=> Default
#define LCD10_PIN_SEL        0

// Pin Mapping for LCD11 signal
//   <o>    LCD11<name=LCD11_PIN_SEL>
//   <i>    Shows which pin LCD11 is mapped to
//   <info>  [PTG4]
//     <0=> Disabled
//     <1=> PTG4 (Alias:p79)<selection=PTG4_SIG_SEL,LCD11>
//     <0=> Default
#define LCD11_PIN_SEL        0

// Pin Mapping for LCD12 signal
//   <o>    LCD12<name=LCD12_PIN_SEL>
//   <i>    Shows which pin LCD12 is mapped to
//   <info>  [PTG5]
//     <0=> Disabled
//     <1=> PTG5 (Alias:p80)<selection=PTG5_SIG_SEL,LCD12>
//     <0=> Default
#define LCD12_PIN_SEL        0

// Pin Mapping for LCD13 signal
//   <o>    LCD13<name=LCD13_PIN_SEL>
//   <i>    Shows which pin LCD13 is mapped to
//   <info>  [PTG6]
//     <0=> Disabled
//     <1=> PTG6 (Alias:p81)<selection=PTG6_SIG_SEL,LCD13>
//     <0=> Default
#define LCD13_PIN_SEL        0

// Pin Mapping for LCD14 signal
//   <o>    LCD14<name=LCD14_PIN_SEL>
//   <i>    Shows which pin LCD14 is mapped to
//   <info>  [PTG7]
//     <0=> Disabled
//     <1=> PTG7 (Alias:p82)<selection=PTG7_SIG_SEL,LCD14>
//     <0=> Default
#define LCD14_PIN_SEL        0

// Pin Mapping for LCD15 signal
//   <o>    LCD15<name=LCD15_PIN_SEL>
//   <i>    Shows which pin LCD15 is mapped to
//   <info>  [PTH0]
//     <0=> Disabled
//     <1=> PTH0 (Alias:p83)<selection=PTH0_SIG_SEL,LCD15>
//     <0=> Default
#define LCD15_PIN_SEL        0

// Pin Mapping for LCD16 signal
//   <o>    LCD16<name=LCD16_PIN_SEL>
//   <i>    Shows which pin LCD16 is mapped to
//   <info>  [PTH1]
//     <0=> Disabled
//     <1=> PTH1 (Alias:p84)<selection=PTH1_SIG_SEL,LCD16>
//     <0=> Default
#define LCD16_PIN_SEL        0

// Pin Mapping for LCD17 signal
//   <o>    LCD17<name=LCD17_PIN_SEL>
//   <i>    Shows which pin LCD17 is mapped to
//   <info>  [PTH2]
//     <0=> Disabled
//     <1=> PTH2 (Alias:p85)<selection=PTH2_SIG_SEL,LCD17>
//     <0=> Default
#define LCD17_PIN_SEL        0

// Pin Mapping for LCD18 signal
//   <o>    LCD18<name=LCD18_PIN_SEL>
//   <i>    Shows which pin LCD18 is mapped to
//   <info>  [PTH3]
//     <0=> Disabled
//     <1=> PTH3 (Alias:p86)<selection=PTH3_SIG_SEL,LCD18>
//     <0=> Default
#define LCD18_PIN_SEL        0

// Pin Mapping for LCD19 signal
//   <o>    LCD19<name=LCD19_PIN_SEL>
//   <i>    Shows which pin LCD19 is mapped to
//   <info>  [PTH4]
//     <0=> Disabled
//     <1=> PTH4 (Alias:p87)<selection=PTH4_SIG_SEL,LCD19>
//     <0=> Default
#define LCD19_PIN_SEL        0

// Pin Mapping for LCD20 signal
//   <o>    LCD20<name=LCD20_PIN_SEL>
//   <i>    Shows which pin LCD20 is mapped to
//   <info>  [PTH5]
//     <0=> Disabled
//     <1=> PTH5 (Alias:p88)<selection=PTH5_SIG_SEL,LCD20>
//     <0=> Default
#define LCD20_PIN_SEL        0

// Pin Mapping for LCD21 signal
//   <o>    LCD21<name=LCD21_PIN_SEL>
//   <i>    Shows which pin LCD21 is mapped to
//   <info>  [PTI2]
//     <0=> Disabled
//     <1=> PTI2 (Alias:p93)<selection=PTI2_SIG_SEL,LCD21>
//     <0=> Default
#define LCD21_PIN_SEL        0

// Pin Mapping for LCD22 signal
//   <o>    LCD22<name=LCD22_PIN_SEL>
//   <i>    Shows which pin LCD22 is mapped to
//   <info>  [PTI3]
//     <0=> Disabled
//     <1=> PTI3 (Alias:p94)<selection=PTI3_SIG_SEL,LCD22>
//     <0=> Default
#define LCD22_PIN_SEL        0

// Pin Mapping for LCD23 signal
//   <o>    LCD23<name=LCD23_PIN_SEL>
//   <i>    Shows which pin LCD23 is mapped to
//   <info>  [PTA0]
//     <0=> Disabled
//     <1=> PTA0 (Alias:p1)<selection=PTA0_SIG_SEL,LCD23>
//     <0=> Default
#define LCD23_PIN_SEL        0

// Pin Mapping for LCD24 signal
//   <o>    LCD24<name=LCD24_PIN_SEL>
//   <i>    Shows which pin LCD24 is mapped to
//   <info>  [PTA1]
//     <0=> Disabled
//     <1=> PTA1 (Alias:p2)<selection=PTA1_SIG_SEL,LCD24>
//     <0=> Default
#define LCD24_PIN_SEL        0

// Pin Mapping for LCD25 signal
//   <o>    LCD25<name=LCD25_PIN_SEL>
//   <i>    Shows which pin LCD25 is mapped to
//   <info>  [PTA2]
//     <0=> Disabled
//     <1=> PTA2 (Alias:p3)<selection=PTA2_SIG_SEL,LCD25>
//     <0=> Default
#define LCD25_PIN_SEL        0

// Pin Mapping for LCD26 signal
//   <o>    LCD26<name=LCD26_PIN_SEL>
//   <i>    Shows which pin LCD26 is mapped to
//   <info>  [PTA3]
//     <0=> Disabled
//     <1=> PTA3 (Alias:p4)<selection=PTA3_SIG_SEL,LCD26>
//     <0=> Default
#define LCD26_PIN_SEL        0

// Pin Mapping for LCD27 signal
//   <o>    LCD27<name=LCD27_PIN_SEL>
//   <i>    Shows which pin LCD27 is mapped to
//   <info>  [PTA4]
//     <0=> Disabled
//     <1=> PTA4 (Alias:p5)<selection=PTA4_SIG_SEL,LCD27>
//     <0=> Default
#define LCD27_PIN_SEL        0

// Pin Mapping for LCD28 signal
//   <o>    LCD28<name=LCD28_PIN_SEL>
//   <i>    Shows which pin LCD28 is mapped to
//   <info>  [PTA5]
//     <0=> Disabled
//     <1=> PTA5 (Alias:p6)<selection=PTA5_SIG_SEL,LCD28>
//     <0=> Default
#define LCD28_PIN_SEL        0

// Pin Mapping for LCD29 signal
//   <o>    LCD29<name=LCD29_PIN_SEL>
//   <i>    Shows which pin LCD29 is mapped to
//   <info>  [PTA6]
//     <0=> Disabled
//     <1=> PTA6 (Alias:p7)<selection=PTA6_SIG_SEL,LCD29>
//     <0=> Default
#define LCD29_PIN_SEL        0

// Pin Mapping for LCD30 signal
//   <o>    LCD30<name=LCD30_PIN_SEL>
//   <i>    Shows which pin LCD30 is mapped to
//   <info>  [PTA7]
//     <0=> Disabled
//     <1=> PTA7 (Alias:p8)<selection=PTA7_SIG_SEL,LCD30>
//     <0=> Default
#define LCD30_PIN_SEL        0

// Pin Mapping for LCD31 signal
//   <o>    LCD31<name=LCD31_PIN_SEL>
//   <i>    Shows which pin LCD31 is mapped to
//   <info>  [PTB0]
//     <0=> Disabled
//     <1=> PTB0 (Alias:p9)<selection=PTB0_SIG_SEL,LCD31>
//     <0=> Default
#define LCD31_PIN_SEL        0

// Pin Mapping for LCD32 signal
//   <o>    LCD32<name=LCD32_PIN_SEL>
//   <i>    Shows which pin LCD32 is mapped to
//   <info>  [PTB1]
//     <0=> Disabled
//     <1=> PTB1 (Alias:p12)<selection=PTB1_SIG_SEL,LCD32>
//     <0=> Default
#define LCD32_PIN_SEL        0

// Pin Mapping for LCD33 signal
//   <o>    LCD33<name=LCD33_PIN_SEL>
//   <i>    Shows which pin LCD33 is mapped to
//   <info>  [PTB2]
//     <0=> Disabled
//     <1=> PTB2 (Alias:p13)<selection=PTB2_SIG_SEL,LCD33>
//     <0=> Default
#define LCD33_PIN_SEL        0

// Pin Mapping for LCD34 signal
//   <o>    LCD34<name=LCD34_PIN_SEL>
//   <i>    Shows which pin LCD34 is mapped to
//   <info>  [PTB3]
//     <0=> Disabled
//     <1=> PTB3 (Alias:p14)<selection=PTB3_SIG_SEL,LCD34>
//     <0=> Default
#define LCD34_PIN_SEL        0

// Pin Mapping for LCD35 signal
//   <o>    LCD35<name=LCD35_PIN_SEL>
//   <i>    Shows which pin LCD35 is mapped to
//   <info>  [PTB4]
//     <0=> Disabled
//     <1=> PTB4 (Alias:p15)<selection=PTB4_SIG_SEL,LCD35>
//     <0=> Default
#define LCD35_PIN_SEL        0

// Pin Mapping for LCD36 signal
//   <o>    LCD36<name=LCD36_PIN_SEL>
//   <i>    Shows which pin LCD36 is mapped to
//   <info>  [PTB5]
//     <0=> Disabled
//     <1=> PTB5 (Alias:p16)<selection=PTB5_SIG_SEL,LCD36>
//     <0=> Default
#define LCD36_PIN_SEL        0

// Pin Mapping for LCD37 signal
//   <o>    LCD37<name=LCD37_PIN_SEL>
//   <i>    Shows which pin LCD37 is mapped to
//   <info>  [PTB6]
//     <0=> Disabled
//     <1=> PTB6 (Alias:p17)<selection=PTB6_SIG_SEL,LCD37/CMP1P0>
//     <0=> Default
#define LCD37_PIN_SEL        0

// Pin Mapping for LCD38 signal
//   <o>    LCD38<name=LCD38_PIN_SEL>
//   <i>    Shows which pin LCD38 is mapped to
//   <info>  [PTB7]
//     <0=> Disabled
//     <1=> PTB7 (Alias:p18)<selection=PTB7_SIG_SEL,LCD38>
//     <0=> Default
#define LCD38_PIN_SEL        0

// Pin Mapping for LCD39 signal
//   <o>    LCD39<name=LCD39_PIN_SEL>
//   <i>    Shows which pin LCD39 is mapped to
//   <info>  [PTC0]
//     <0=> Disabled
//     <1=> PTC0 (Alias:p19)<selection=PTC0_SIG_SEL,LCD39>
//     <0=> Default
#define LCD39_PIN_SEL        0

// Pin Mapping for LCD40 signal
//   <o>    LCD40<name=LCD40_PIN_SEL>
//   <i>    Shows which pin LCD40 is mapped to
//   <info>  [PTC1]
//     <0=> Disabled
//     <1=> PTC1 (Alias:p20)<selection=PTC1_SIG_SEL,LCD40/CMP1P1>
//     <0=> Default
#define LCD40_PIN_SEL        0

// Pin Mapping for LCD41 signal
//   <o>    LCD41<name=LCD41_PIN_SEL>
//   <i>    Shows which pin LCD41 is mapped to
//   <info>  [PTC2]
//     <0=> Disabled
//     <1=> PTC2 (Alias:p21)<selection=PTC2_SIG_SEL,LCD41>
//     <0=> Default
#define LCD41_PIN_SEL        0

// Pin Mapping for LCD42 signal
//   <o>    LCD42<name=LCD42_PIN_SEL>
//   <i>    Shows which pin LCD42 is mapped to
//   <info>  [PTC3]
//     <0=> Disabled
//     <1=> PTC3 (Alias:p22)<selection=PTC3_SIG_SEL,LCD42/CMP0P3>
//     <0=> Default
#define LCD42_PIN_SEL        0

// Pin Mapping for LCD43 signal
//   <o>    LCD43<name=LCD43_PIN_SEL>
//   <i>    Shows which pin LCD43 is mapped to
//   <info>  [PTC4]
//     <0=> Disabled
//     <1=> PTC4 (Alias:p23)<selection=PTC4_SIG_SEL,LCD43>
//     <0=> Default
#define LCD43_PIN_SEL        0

// </h>

// <h> Analogue to Digital (ADC0)

// Pin Mapping for ADC0_SE0 signal
//   <o>    ADC0_SE0<name=ADC0_SE0_PIN_SEL>
//   <i>    Shows which pin ADC0_SE0 is mapped to
//   <info>  [PTC5]
//     <0=> Disabled
//     <1=> PTC5 (Alias:p44)<selection=PTC5_SIG_SEL,ADC0_SE0>
//     <0=> Default
#define ADC0_SE0_PIN_SEL     0

// Pin Mapping for ADC0_SE1 signal
//   <o>    ADC0_SE1<name=ADC0_SE1_PIN_SEL>
//   <i>    Shows which pin ADC0_SE1 is mapped to
//   <info>  [PTC6]
//     <0=> Disabled
//     <1=> PTC6 (Alias:p45)<selection=PTC6_SIG_SEL,ADC0_SE1>
//     <0=> Default
#define ADC0_SE1_PIN_SEL     0

// Pin Mapping for ADC0_SE2 signal
//   <o>    ADC0_SE2<name=ADC0_SE2_PIN_SEL>
//   <i>    Shows which pin ADC0_SE2 is mapped to
//   <info>  [PTC7]
//     <0=> Disabled
//     <1=> PTC7 (Alias:p46)<selection=PTC7_SIG_SEL,ADC0_SE2>
//     <0=> Default
#define ADC0_SE2_PIN_SEL     0

// Pin Mapping for ADC0_SE3 signal
//   <o>    ADC0_SE3<name=ADC0_SE3_PIN_SEL>
//   <i>    Shows which pin ADC0_SE3 is mapped to
//   <info>  [PTD4]
//     <0=> Disabled
//     <1=> PTD4 (Alias:p51)<selection=PTD4_SIG_SEL,ADC0_SE3>
//     <0=> Default
#define ADC0_SE3_PIN_SEL     0

// Pin Mapping for ADC0_SE4 signal
//   <o>    ADC0_SE4<name=ADC0_SE4_PIN_SEL>
//   <i>    Shows which pin ADC0_SE4 is mapped to
//   <info>  [PTD5]
//     <0=> Disabled
//     <1=> PTD5 (Alias:p52)<selection=PTD5_SIG_SEL,ADC0_SE4>
//     <0=> Default
#define ADC0_SE4_PIN_SEL     0

// Pin Mapping for ADC0_SE5 signal
//   <o>    ADC0_SE5<name=ADC0_SE5_PIN_SEL>
//   <i>    Shows which pin ADC0_SE5 is mapped to
//   <info>  [PTD6]
//     <0=> Disabled
//     <1=> PTD6 (Alias:p53)<selection=PTD6_SIG_SEL,ADC0_SE5>
//     <0=> Default
#define ADC0_SE5_PIN_SEL     0

// Pin Mapping for ADC0_SE6 signal
//   <o>    ADC0_SE6<name=ADC0_SE6_PIN_SEL>
//   <i>    Shows which pin ADC0_SE6 is mapped to
//   <info>  [PTE7]
//     <0=> Disabled
//     <1=> PTE7 (Alias:p66)<selection=PTE7_SIG_SEL,ADC0_SE6>
//     <0=> Default
#define ADC0_SE6_PIN_SEL     0

// Pin Mapping for ADC0_SE7 signal
//   <o>    ADC0_SE7<name=ADC0_SE7_PIN_SEL>
//   <i>    Shows which pin ADC0_SE7 is mapped to
//   <info>  [PTF0]
//     <0=> Disabled
//     <1=> PTF0 (Alias:p67)<selection=PTF0_SIG_SEL,ADC0_SE7>
//     <0=> Default
#define ADC0_SE7_PIN_SEL     0

// Pin Mapping for ADC0_SE8 signal
//   <o>    ADC0_SE8<name=ADC0_SE8_PIN_SEL>
//   <i>    Shows which pin ADC0_SE8 is mapped to
//   <info>  [PTF1]
//     <0=> Disabled
//     <1=> PTF1 (Alias:p68)<selection=PTF1_SIG_SEL,LCD0/ADC0_SE8>
//     <0=> Default
#define ADC0_SE8_PIN_SEL     0

// Pin Mapping for ADC0_SE9 signal
//   <o>    ADC0_SE9<name=ADC0_SE9_PIN_SEL>
//   <i>    Shows which pin ADC0_SE9 is mapped to
//   <info>  [PTF2]
//     <0=> Disabled
//     <1=> PTF2 (Alias:p69)<selection=PTF2_SIG_SEL,LCD1/ADC0_SE9>
//     <0=> Default
#define ADC0_SE9_PIN_SEL     0

// Pin Mapping for ADC0_SE10 signal
//   <o>    ADC0_SE10<name=ADC0_SE10_PIN_SEL>
//   <i>    Shows which pin ADC0_SE10 is mapped to
//   <info>  [PTG1]
//     <0=> Disabled
//     <1=> PTG1 (Alias:p76)<selection=PTG1_SIG_SEL,LCD8/ADC0_SE10>
//     <0=> Default
#define ADC0_SE10_PIN_SEL    0

// Pin Mapping for ADC0_SE11 signal
//   <o>    ADC0_SE11<name=ADC0_SE11_PIN_SEL>
//   <i>    Shows which pin ADC0_SE11 is mapped to
//   <info>  [PTG2]
//     <0=> Disabled
//     <1=> PTG2 (Alias:p77)<selection=PTG2_SIG_SEL,LCD9/ADC0_SE11>
//     <0=> Default
#define ADC0_SE11_PIN_SEL    0

// </h>

// <h> Clock and Timing

// Pin Mapping for AFE_CLK signal
//   <o>    AFE_CLK<name=AFE_CLK_PIN_SEL>
//   <i>    Shows which pin AFE_CLK is mapped to
//   <info>  [PTB7, PTE3]
//     <0=> Disabled
//     <1=> PTB7 (Alias:p18)<selection=PTB7_SIG_SEL,AFE_CLK>
//     <2=> PTE3 (Alias:p58)<selection=PTE3_SIG_SEL,AFE_CLK>
//     <0=> Default
#define AFE_CLK_PIN_SEL      0

// Pin Mapping for CLKOUT signal
//   <o>    CLKOUT<name=CLKOUT_PIN_SEL>
//   <i>    Shows which pin CLKOUT is mapped to
//   <info>  [PTF7, PTE0]
//     <0=> Disabled
//     <1=> PTF7 (Alias:p74)<selection=PTF7_SIG_SEL,CLKOUT>
//     <2=> PTE0 (Alias:p55)<selection=PTE0_SIG_SEL,CLKOUT>
//     <0=> Default
#define CLKOUT_PIN_SEL       0

// Pin Mapping for EXTAL1 signal
//   <o>    EXTAL1<name=EXTAL1_PIN_SEL>
//   <i>    Shows which pin EXTAL1 is mapped to
//   <info>  [PTE2]
//     <0=> Disabled
//     <1=> PTE2 (Alias:p57) (reset default)<selection=PTE2_SIG_SEL,EXTAL1 (reset default)>
//     <2=> PTE2 (Alias:p57)<selection=PTE2_SIG_SEL,EXTAL1>
//     <1=> Default
#define EXTAL1_PIN_SEL       1

// Pin Mapping for EXTAL32K signal
//   <o>    EXTAL32K<name=EXTAL32K_PIN_SEL><constant>
//   <i>    Shows which pin EXTAL32K is mapped to
//   <info>  [EXTAL32K]
//     <0=> EXTAL32K (Alias:p26)<selection=EXTAL32K_SIG_SEL,EXTAL32K>
//     <0=> Default
#define EXTAL32K_PIN_SEL     0

// Pin Mapping for RTCCLKOUT signal
//   <o>    RTCCLKOUT<name=RTCCLKOUT_PIN_SEL>
//   <i>    Shows which pin RTCCLKOUT is mapped to
//   <info>  [PTF0, PTF2]
//     <0=> Disabled
//     <1=> PTF0 (Alias:p67)<selection=PTF0_SIG_SEL,RTCCLKOUT>
//     <2=> PTF2 (Alias:p69)<selection=PTF2_SIG_SEL,RTCCLKOUT>
//     <0=> Default
#define RTCCLKOUT_PIN_SEL    0

// Pin Mapping for XTAL1 signal
//   <o>    XTAL1<name=XTAL1_PIN_SEL>
//   <i>    Shows which pin XTAL1 is mapped to
//   <info>  [PTE3]
//     <0=> Disabled
//     <1=> PTE3 (Alias:p58) (reset default)<selection=PTE3_SIG_SEL,XTAL1 (reset default)>
//     <2=> PTE3 (Alias:p58)<selection=PTE3_SIG_SEL,XTAL1>
//     <1=> Default
#define XTAL1_PIN_SEL        1

// Pin Mapping for XTAL32K signal
//   <o>    XTAL32K<name=XTAL32K_PIN_SEL><constant>
//   <i>    Shows which pin XTAL32K is mapped to
//   <info>  [XTAL32K]
//     <0=> XTAL32K (Alias:p25)<selection=XTAL32K_SIG_SEL,XTAL32K>
//     <0=> Default
#define XTAL32K_PIN_SEL      0

// </h>

// <h> Analogue Comparator (CMP0)

// Pin Mapping for CMP0OUT signal
//   <o>    CMP0OUT<name=CMP0OUT_PIN_SEL>
//   <i>    Shows which pin CMP0OUT is mapped to
//   <info>  [PTA5, PTF0]
//     <0=> Disabled
//     <1=> PTA5 (Alias:p6)<selection=PTA5_SIG_SEL,CMP0OUT>
//     <2=> PTF0 (Alias:p67)<selection=PTF0_SIG_SEL,CMP0OUT>
//     <0=> Default
#define CMP0OUT_PIN_SEL      0

// Pin Mapping for CMP0P0 signal
//   <o>    CMP0P0<name=CMP0P0_PIN_SEL>
//   <i>    Shows which pin CMP0P0 is mapped to
//   <info>  [PTD0]
//     <0=> Disabled
//     <1=> PTD0 (Alias:p47)<selection=PTD0_SIG_SEL,CMP0P0>
//     <0=> Default
#define CMP0P0_PIN_SEL       0

// Pin Mapping for CMP0P1 signal
//   <o>    CMP0P1<name=CMP0P1_PIN_SEL>
//   <i>    Shows which pin CMP0P1 is mapped to
//   <info>  [PTD2]
//     <0=> Disabled
//     <1=> PTD2 (Alias:p49)<selection=PTD2_SIG_SEL,CMP0P1>
//     <0=> Default
#define CMP0P1_PIN_SEL       0

// Pin Mapping for CMP0P2 signal
//   <o>    CMP0P2<name=CMP0P2_PIN_SEL>
//   <i>    Shows which pin CMP0P2 is mapped to
//   <info>  [PTE6]
//     <0=> Disabled
//     <1=> PTE6 (Alias:p65)<selection=PTE6_SIG_SEL,CMP0P2>
//     <0=> Default
#define CMP0P2_PIN_SEL       0

// Pin Mapping for CMP0P3 signal
//   <o>    CMP0P3<name=CMP0P3_PIN_SEL>
//   <i>    Shows which pin CMP0P3 is mapped to
//   <info>  [PTC3]
//     <0=> Disabled
//     <1=> PTC3 (Alias:p22)<selection=PTC3_SIG_SEL,LCD42/CMP0P3>
//     <0=> Default
#define CMP0P3_PIN_SEL       0

// Pin Mapping for CMP0P4 signal
//   <o>    CMP0P4<name=CMP0P4_PIN_SEL>
//   <i>    Shows which pin CMP0P4 is mapped to
//   <info>  [PTD7]
//     <0=> Disabled
//     <1=> PTD7 (Alias:p54)<selection=PTD7_SIG_SEL,CMP0P4>
//     <0=> Default
#define CMP0P4_PIN_SEL       0

// Pin Mapping for CMP0P5 signal
//   <o>    CMP0P5<name=CMP0P5_PIN_SEL>
//   <i>    Shows which pin CMP0P5 is mapped to
//   <info>  [PTI0]
//     <0=> Disabled
//     <1=> PTI0 (Alias:p91)<selection=PTI0_SIG_SEL,CMP0P5>
//     <0=> Default
#define CMP0P5_PIN_SEL       0

// </h>

// <h> Analogue Comparator (CMP1)

// Pin Mapping for CMP1OUT signal
//   <o>    CMP1OUT<name=CMP1OUT_PIN_SEL>
//   <i>    Shows which pin CMP1OUT is mapped to
//   <info>  [PTF2, PTD6]
//     <0=> Disabled
//     <1=> PTF2 (Alias:p69)<selection=PTF2_SIG_SEL,CMP1OUT>
//     <2=> PTD6 (Alias:p53)<selection=PTD6_SIG_SEL,CMP1OUT>
//     <0=> Default
#define CMP1OUT_PIN_SEL      0

// Pin Mapping for CMP1P0 signal
//   <o>    CMP1P0<name=CMP1P0_PIN_SEL>
//   <i>    Shows which pin CMP1P0 is mapped to
//   <info>  [PTB6]
//     <0=> Disabled
//     <1=> PTB6 (Alias:p17)<selection=PTB6_SIG_SEL,LCD37/CMP1P0>
//     <0=> Default
#define CMP1P0_PIN_SEL       0

// Pin Mapping for CMP1P1 signal
//   <o>    CMP1P1<name=CMP1P1_PIN_SEL>
//   <i>    Shows which pin CMP1P1 is mapped to
//   <info>  [PTC1]
//     <0=> Disabled
//     <1=> PTC1 (Alias:p20)<selection=PTC1_SIG_SEL,LCD40/CMP1P1>
//     <0=> Default
#define CMP1P1_PIN_SEL       0

// Pin Mapping for CMP1P2 signal
//   <o>    CMP1P2<name=CMP1P2_PIN_SEL><constant>
//   <i>    Shows which pin CMP1P2 is mapped to
//   <info>  [SDADP2]
//     <0=> SDADP2 (Alias:p39)<selection=SDADP2_SIG_SEL,SDADP2/CMP1P2>
//     <0=> Default
#define CMP1P2_PIN_SEL       0

// Pin Mapping for CMP1P3 signal
//   <o>    CMP1P3<name=CMP1P3_PIN_SEL><constant>
//   <i>    Shows which pin CMP1P3 is mapped to
//   <info>  [SDADM2]
//     <0=> SDADM2 (Alias:p40)<selection=SDADM2_SIG_SEL,SDADM2/CMP1P3>
//     <0=> Default
#define CMP1P3_PIN_SEL       0

// Pin Mapping for CMP1P4 signal
//   <o>    CMP1P4<name=CMP1P4_PIN_SEL><constant>
//   <i>    Shows which pin CMP1P4 is mapped to
//   <info>  [SDADP3]
//     <0=> SDADP3 (Alias:p42)<selection=SDADP3_SIG_SEL,SDADP3/CMP1P4>
//     <0=> Default
#define CMP1P4_PIN_SEL       0

// Pin Mapping for CMP1P5 signal
//   <o>    CMP1P5<name=CMP1P5_PIN_SEL><constant>
//   <i>    Shows which pin CMP1P5 is mapped to
//   <info>  [SDADM3]
//     <0=> SDADM3 (Alias:p43)<selection=SDADM3_SIG_SEL,SDADM3/CMP1P5>
//     <0=> Default
#define CMP1P5_PIN_SEL       0

// </h>

// <h> External Watchdog Monitor (EWM)

// Pin Mapping for EWM_IN signal
//   <o>    EWM_IN<name=EWM_IN_PIN_SEL>
//   <i>    Shows which pin EWM_IN is mapped to
//   <info>  [PTE2, PTE4]
//     <0=> Disabled
//     <1=> PTE2 (Alias:p57)<selection=PTE2_SIG_SEL,EWM_IN>
//     <2=> PTE4 (Alias:p63)<selection=PTE4_SIG_SEL,EWM_IN>
//     <0=> Default
#define EWM_IN_PIN_SEL       0

// Pin Mapping for EWM_OUT signal
//   <o>    EWM_OUT<name=EWM_OUT_PIN_SEL>
//   <i>    Shows which pin EWM_OUT is mapped to
//   <info>  [PTE3, PTE5]
//     <0=> Disabled
//     <1=> PTE3 (Alias:p58)<selection=PTE3_SIG_SEL,EWM_OUT>
//     <2=> PTE5 (Alias:p64)<selection=PTE5_SIG_SEL,EWM_OUT>
//     <0=> Default
#define EWM_OUT_PIN_SEL      0

// </h>

// <h> General Purpose I/O (GPIOA)

// Pin Mapping for GPIOA_0 signal
//   <o>    GPIOA_0<name=GPIOA_0_PIN_SEL>
//   <i>    Shows which pin GPIOA_0 is mapped to
//   <info>  [PTA0]
//     <0=> Disabled
//     <1=> PTA0 (Alias:p1)<selection=PTA0_SIG_SEL,GPIOA_0>
//     <1=> Default
#define GPIOA_0_PIN_SEL      1

// Pin Mapping for GPIOA_1 signal
//   <o>    GPIOA_1<name=GPIOA_1_PIN_SEL>
//   <i>    Shows which pin GPIOA_1 is mapped to
//   <info>  [PTA1]
//     <0=> Disabled
//     <1=> PTA1 (Alias:p2)<selection=PTA1_SIG_SEL,GPIOA_1>
//     <1=> Default
#define GPIOA_1_PIN_SEL      1

// Pin Mapping for GPIOA_2 signal
//   <o>    GPIOA_2<name=GPIOA_2_PIN_SEL>
//   <i>    Shows which pin GPIOA_2 is mapped to
//   <info>  [PTA2]
//     <0=> Disabled
//     <1=> PTA2 (Alias:p3)<selection=PTA2_SIG_SEL,GPIOA_2>
//     <0=> Default
#define GPIOA_2_PIN_SEL      0

// Pin Mapping for GPIOA_3 signal
//   <o>    GPIOA_3<name=GPIOA_3_PIN_SEL>
//   <i>    Shows which pin GPIOA_3 is mapped to
//   <info>  [PTA3]
//     <0=> Disabled
//     <1=> PTA3 (Alias:p4)<selection=PTA3_SIG_SEL,GPIOA_3>
//     <0=> Default
#define GPIOA_3_PIN_SEL      0

// Pin Mapping for GPIOA_4 signal
//   <o>    GPIOA_4<name=GPIOA_4_PIN_SEL>
//   <i>    Shows which pin GPIOA_4 is mapped to
//   <info>  [PTA4]
//     <0=> Disabled
//     <1=> PTA4 (Alias:p5)<selection=PTA4_SIG_SEL,GPIOA_4>
//     <0=> Default
#define GPIOA_4_PIN_SEL      0

// Pin Mapping for GPIOA_5 signal
//   <o>    GPIOA_5<name=GPIOA_5_PIN_SEL>
//   <i>    Shows which pin GPIOA_5 is mapped to
//   <info>  [PTA5]
//     <0=> Disabled
//     <1=> PTA5 (Alias:p6)<selection=PTA5_SIG_SEL,GPIOA_5>
//     <0=> Default
#define GPIOA_5_PIN_SEL      0

// Pin Mapping for GPIOA_6 signal
//   <o>    GPIOA_6<name=GPIOA_6_PIN_SEL>
//   <i>    Shows which pin GPIOA_6 is mapped to
//   <info>  [PTA6]
//     <0=> Disabled
//     <1=> PTA6 (Alias:p7)<selection=PTA6_SIG_SEL,GPIOA_6>
//     <0=> Default
#define GPIOA_6_PIN_SEL      0

// Pin Mapping for GPIOA_7 signal
//   <o>    GPIOA_7<name=GPIOA_7_PIN_SEL>
//   <i>    Shows which pin GPIOA_7 is mapped to
//   <info>  [PTA7]
//     <0=> Disabled
//     <1=> PTA7 (Alias:p8)<selection=PTA7_SIG_SEL,GPIOA_7>
//     <0=> Default
#define GPIOA_7_PIN_SEL      0

// </h>

// <h> General Purpose I/O (GPIOB)

// Pin Mapping for GPIOB_0 signal
//   <o>    GPIOB_0<name=GPIOB_0_PIN_SEL>
//   <i>    Shows which pin GPIOB_0 is mapped to
//   <info>  [PTB0]
//     <0=> Disabled
//     <1=> PTB0 (Alias:p9)<selection=PTB0_SIG_SEL,GPIOB_0>
//     <0=> Default
#define GPIOB_0_PIN_SEL      0

// Pin Mapping for GPIOB_1 signal
//   <o>    GPIOB_1<name=GPIOB_1_PIN_SEL>
//   <i>    Shows which pin GPIOB_1 is mapped to
//   <info>  [PTB1]
//     <0=> Disabled
//     <1=> PTB1 (Alias:p12)<selection=PTB1_SIG_SEL,GPIOB_1>
//     <0=> Default
#define GPIOB_1_PIN_SEL      0

// Pin Mapping for GPIOB_2 signal
//   <o>    GPIOB_2<name=GPIOB_2_PIN_SEL>
//   <i>    Shows which pin GPIOB_2 is mapped to
//   <info>  [PTB2]
//     <0=> Disabled
//     <1=> PTB2 (Alias:p13)<selection=PTB2_SIG_SEL,GPIOB_2>
//     <0=> Default
#define GPIOB_2_PIN_SEL      0

// Pin Mapping for GPIOB_3 signal
//   <o>    GPIOB_3<name=GPIOB_3_PIN_SEL>
//   <i>    Shows which pin GPIOB_3 is mapped to
//   <info>  [PTB3]
//     <0=> Disabled
//     <1=> PTB3 (Alias:p14)<selection=PTB3_SIG_SEL,GPIOB_3>
//     <0=> Default
#define GPIOB_3_PIN_SEL      0

// Pin Mapping for GPIOB_4 signal
//   <o>    GPIOB_4<name=GPIOB_4_PIN_SEL>
//   <i>    Shows which pin GPIOB_4 is mapped to
//   <info>  [PTB4]
//     <0=> Disabled
//     <1=> PTB4 (Alias:p15)<selection=PTB4_SIG_SEL,GPIOB_4>
//     <0=> Default
#define GPIOB_4_PIN_SEL      0

// Pin Mapping for GPIOB_5 signal
//   <o>    GPIOB_5<name=GPIOB_5_PIN_SEL>
//   <i>    Shows which pin GPIOB_5 is mapped to
//   <info>  [PTB5]
//     <0=> Disabled
//     <1=> PTB5 (Alias:p16)<selection=PTB5_SIG_SEL,GPIOB_5>
//     <0=> Default
#define GPIOB_5_PIN_SEL      0

// Pin Mapping for GPIOB_6 signal
//   <o>    GPIOB_6<name=GPIOB_6_PIN_SEL>
//   <i>    Shows which pin GPIOB_6 is mapped to
//   <info>  [PTB6]
//     <0=> Disabled
//     <1=> PTB6 (Alias:p17)<selection=PTB6_SIG_SEL,GPIOB_6>
//     <0=> Default
#define GPIOB_6_PIN_SEL      0

// Pin Mapping for GPIOB_7 signal
//   <o>    GPIOB_7<name=GPIOB_7_PIN_SEL>
//   <i>    Shows which pin GPIOB_7 is mapped to
//   <info>  [PTB7]
//     <0=> Disabled
//     <1=> PTB7 (Alias:p18)<selection=PTB7_SIG_SEL,GPIOB_7>
//     <0=> Default
#define GPIOB_7_PIN_SEL      0

// </h>

// <h> General Purpose I/O (GPIOC)

// Pin Mapping for GPIOC_0 signal
//   <o>    GPIOC_0<name=GPIOC_0_PIN_SEL>
//   <i>    Shows which pin GPIOC_0 is mapped to
//   <info>  [PTC0]
//     <0=> Disabled
//     <1=> PTC0 (Alias:p19)<selection=PTC0_SIG_SEL,GPIOC_0>
//     <0=> Default
#define GPIOC_0_PIN_SEL      0

// Pin Mapping for GPIOC_1 signal
//   <o>    GPIOC_1<name=GPIOC_1_PIN_SEL>
//   <i>    Shows which pin GPIOC_1 is mapped to
//   <info>  [PTC1]
//     <0=> Disabled
//     <1=> PTC1 (Alias:p20)<selection=PTC1_SIG_SEL,GPIOC_1>
//     <0=> Default
#define GPIOC_1_PIN_SEL      0

// Pin Mapping for GPIOC_2 signal
//   <o>    GPIOC_2<name=GPIOC_2_PIN_SEL>
//   <i>    Shows which pin GPIOC_2 is mapped to
//   <info>  [PTC2]
//     <0=> Disabled
//     <1=> PTC2 (Alias:p21)<selection=PTC2_SIG_SEL,GPIOC_2>
//     <0=> Default
#define GPIOC_2_PIN_SEL      0

// Pin Mapping for GPIOC_3 signal
//   <o>    GPIOC_3<name=GPIOC_3_PIN_SEL>
//   <i>    Shows which pin GPIOC_3 is mapped to
//   <info>  [PTC3]
//     <0=> Disabled
//     <1=> PTC3 (Alias:p22)<selection=PTC3_SIG_SEL,GPIOC_3>
//     <0=> Default
#define GPIOC_3_PIN_SEL      0

// Pin Mapping for GPIOC_4 signal
//   <o>    GPIOC_4<name=GPIOC_4_PIN_SEL>
//   <i>    Shows which pin GPIOC_4 is mapped to
//   <info>  [PTC4]
//     <0=> Disabled
//     <1=> PTC4 (Alias:p23)<selection=PTC4_SIG_SEL,GPIOC_4>
//     <0=> Default
#define GPIOC_4_PIN_SEL      0

// Pin Mapping for GPIOC_5 signal
//   <o>    GPIOC_5<name=GPIOC_5_PIN_SEL>
//   <i>    Shows which pin GPIOC_5 is mapped to
//   <info>  [PTC5]
//     <0=> Disabled
//     <1=> PTC5 (Alias:p44)<selection=PTC5_SIG_SEL,GPIOC_5>
//     <0=> Default
#define GPIOC_5_PIN_SEL      0

// Pin Mapping for GPIOC_6 signal
//   <o>    GPIOC_6<name=GPIOC_6_PIN_SEL>
//   <i>    Shows which pin GPIOC_6 is mapped to
//   <info>  [PTC6]
//     <0=> Disabled
//     <1=> PTC6 (Alias:p45)<selection=PTC6_SIG_SEL,GPIOC_6>
//     <0=> Default
#define GPIOC_6_PIN_SEL      0

// Pin Mapping for GPIOC_7 signal
//   <o>    GPIOC_7<name=GPIOC_7_PIN_SEL>
//   <i>    Shows which pin GPIOC_7 is mapped to
//   <info>  [PTC7]
//     <0=> Disabled
//     <1=> PTC7 (Alias:p46)<selection=PTC7_SIG_SEL,GPIOC_7>
//     <0=> Default
#define GPIOC_7_PIN_SEL      0

// </h>

// <h> General Purpose I/O (GPIOD)

// Pin Mapping for GPIOD_0 signal
//   <o>    GPIOD_0<name=GPIOD_0_PIN_SEL>
//   <i>    Shows which pin GPIOD_0 is mapped to
//   <info>  [PTD0]
//     <0=> Disabled
//     <1=> PTD0 (Alias:p47)<selection=PTD0_SIG_SEL,GPIOD_0>
//     <0=> Default
#define GPIOD_0_PIN_SEL      0

// Pin Mapping for GPIOD_1 signal
//   <o>    GPIOD_1<name=GPIOD_1_PIN_SEL>
//   <i>    Shows which pin GPIOD_1 is mapped to
//   <info>  [PTD1]
//     <0=> Disabled
//     <1=> PTD1 (Alias:p48)<selection=PTD1_SIG_SEL,GPIOD_1>
//     <1=> Default
#define GPIOD_1_PIN_SEL      1

// Pin Mapping for GPIOD_2 signal
//   <o>    GPIOD_2<name=GPIOD_2_PIN_SEL>
//   <i>    Shows which pin GPIOD_2 is mapped to
//   <info>  [PTD2]
//     <0=> Disabled
//     <1=> PTD2 (Alias:p49)<selection=PTD2_SIG_SEL,GPIOD_2>
//     <0=> Default
#define GPIOD_2_PIN_SEL      0

// Pin Mapping for GPIOD_3 signal
//   <o>    GPIOD_3<name=GPIOD_3_PIN_SEL>
//   <i>    Shows which pin GPIOD_3 is mapped to
//   <info>  [PTD3]
//     <0=> Disabled
//     <1=> PTD3 (Alias:p50)<selection=PTD3_SIG_SEL,GPIOD_3>
//     <0=> Default
#define GPIOD_3_PIN_SEL      0

// Pin Mapping for GPIOD_4 signal
//   <o>    GPIOD_4<name=GPIOD_4_PIN_SEL>
//   <i>    Shows which pin GPIOD_4 is mapped to
//   <info>  [PTD4]
//     <0=> Disabled
//     <1=> PTD4 (Alias:p51)<selection=PTD4_SIG_SEL,GPIOD_4>
//     <0=> Default
#define GPIOD_4_PIN_SEL      0

// Pin Mapping for GPIOD_5 signal
//   <o>    GPIOD_5<name=GPIOD_5_PIN_SEL>
//   <i>    Shows which pin GPIOD_5 is mapped to
//   <info>  [PTD5]
//     <0=> Disabled
//     <1=> PTD5 (Alias:p52)<selection=PTD5_SIG_SEL,GPIOD_5>
//     <0=> Default
#define GPIOD_5_PIN_SEL      0

// Pin Mapping for GPIOD_6 signal
//   <o>    GPIOD_6<name=GPIOD_6_PIN_SEL>
//   <i>    Shows which pin GPIOD_6 is mapped to
//   <info>  [PTD6]
//     <0=> Disabled
//     <1=> PTD6 (Alias:p53)<selection=PTD6_SIG_SEL,GPIOD_6>
//     <0=> Default
#define GPIOD_6_PIN_SEL      0

// Pin Mapping for GPIOD_7 signal
//   <o>    GPIOD_7<name=GPIOD_7_PIN_SEL>
//   <i>    Shows which pin GPIOD_7 is mapped to
//   <info>  [PTD7]
//     <0=> Disabled
//     <1=> PTD7 (Alias:p54)<selection=PTD7_SIG_SEL,GPIOD_7>
//     <0=> Default
#define GPIOD_7_PIN_SEL      0

// </h>

// <h> General Purpose I/O (GPIOE)

// Pin Mapping for GPIOE_0 signal
//   <o>    GPIOE_0<name=GPIOE_0_PIN_SEL>
//   <i>    Shows which pin GPIOE_0 is mapped to
//   <info>  [PTE0]
//     <0=> Disabled
//     <1=> PTE0 (Alias:p55)<selection=PTE0_SIG_SEL,GPIOE_0>
//     <0=> Default
#define GPIOE_0_PIN_SEL      0

// Pin Mapping for GPIOE_1 signal
//   <o>    GPIOE_1<name=GPIOE_1_PIN_SEL>
//   <i>    Shows which pin GPIOE_1 is mapped to
//   <info>  [PTE1]
//     <0=> Disabled
//     <1=> PTE1 (Alias:p56)<selection=PTE1_SIG_SEL,GPIOE_1>
//     <0=> Default
#define GPIOE_1_PIN_SEL      0

// Pin Mapping for GPIOE_2 signal
//   <o>    GPIOE_2<name=GPIOE_2_PIN_SEL>
//   <i>    Shows which pin GPIOE_2 is mapped to
//   <info>  [PTE2]
//     <0=> Disabled
//     <1=> PTE2 (Alias:p57)<selection=PTE2_SIG_SEL,GPIOE_2>
//     <0=> Default
#define GPIOE_2_PIN_SEL      0

// Pin Mapping for GPIOE_3 signal
//   <o>    GPIOE_3<name=GPIOE_3_PIN_SEL>
//   <i>    Shows which pin GPIOE_3 is mapped to
//   <info>  [PTE3]
//     <0=> Disabled
//     <1=> PTE3 (Alias:p58)<selection=PTE3_SIG_SEL,GPIOE_3>
//     <0=> Default
#define GPIOE_3_PIN_SEL      0

// Pin Mapping for GPIOE_4 signal
//   <o>    GPIOE_4<name=GPIOE_4_PIN_SEL>
//   <i>    Shows which pin GPIOE_4 is mapped to
//   <info>  [PTE4]
//     <0=> Disabled
//     <1=> PTE4 (Alias:p63)<selection=PTE4_SIG_SEL,GPIOE_4>
//     <0=> Default
#define GPIOE_4_PIN_SEL      0

// Pin Mapping for GPIOE_5 signal
//   <o>    GPIOE_5<name=GPIOE_5_PIN_SEL>
//   <i>    Shows which pin GPIOE_5 is mapped to
//   <info>  [PTE5]
//     <0=> Disabled
//     <1=> PTE5 (Alias:p64)<selection=PTE5_SIG_SEL,GPIOE_5>
//     <0=> Default
#define GPIOE_5_PIN_SEL      0

// Pin Mapping for GPIOE_6 signal
//   <o>    GPIOE_6<name=GPIOE_6_PIN_SEL>
//   <i>    Shows which pin GPIOE_6 is mapped to
//   <info>  [PTE6]
//     <0=> Disabled
//     <1=> PTE6 (Alias:p65)<selection=PTE6_SIG_SEL,GPIOE_6>
//     <0=> Default
#define GPIOE_6_PIN_SEL      0

// Pin Mapping for GPIOE_7 signal
//   <o>    GPIOE_7<name=GPIOE_7_PIN_SEL>
//   <i>    Shows which pin GPIOE_7 is mapped to
//   <info>  [PTE7]
//     <0=> Disabled
//     <1=> PTE7 (Alias:p66)<selection=PTE7_SIG_SEL,GPIOE_7>
//     <0=> Default
#define GPIOE_7_PIN_SEL      0

// </h>

// <h> General Purpose I/O (GPIOF)

// Pin Mapping for GPIOF_0 signal
//   <o>    GPIOF_0<name=GPIOF_0_PIN_SEL>
//   <i>    Shows which pin GPIOF_0 is mapped to
//   <info>  [PTF0]
//     <0=> Disabled
//     <1=> PTF0 (Alias:p67)<selection=PTF0_SIG_SEL,GPIOF_0>
//     <0=> Default
#define GPIOF_0_PIN_SEL      0

// Pin Mapping for GPIOF_1 signal
//   <o>    GPIOF_1<name=GPIOF_1_PIN_SEL>
//   <i>    Shows which pin GPIOF_1 is mapped to
//   <info>  [PTF1]
//     <0=> Disabled
//     <1=> PTF1 (Alias:p68)<selection=PTF1_SIG_SEL,GPIOF_1>
//     <0=> Default
#define GPIOF_1_PIN_SEL      0

// Pin Mapping for GPIOF_2 signal
//   <o>    GPIOF_2<name=GPIOF_2_PIN_SEL>
//   <i>    Shows which pin GPIOF_2 is mapped to
//   <info>  [PTF2]
//     <0=> Disabled
//     <1=> PTF2 (Alias:p69)<selection=PTF2_SIG_SEL,GPIOF_2>
//     <0=> Default
#define GPIOF_2_PIN_SEL      0

// Pin Mapping for GPIOF_3 signal
//   <o>    GPIOF_3<name=GPIOF_3_PIN_SEL>
//   <i>    Shows which pin GPIOF_3 is mapped to
//   <info>  [PTF3]
//     <0=> Disabled
//     <1=> PTF3 (Alias:p70)<selection=PTF3_SIG_SEL,GPIOF_3>
//     <0=> Default
#define GPIOF_3_PIN_SEL      0

// Pin Mapping for GPIOF_4 signal
//   <o>    GPIOF_4<name=GPIOF_4_PIN_SEL>
//   <i>    Shows which pin GPIOF_4 is mapped to
//   <info>  [PTF4]
//     <0=> Disabled
//     <1=> PTF4 (Alias:p71)<selection=PTF4_SIG_SEL,GPIOF_4>
//     <0=> Default
#define GPIOF_4_PIN_SEL      0

// Pin Mapping for GPIOF_5 signal
//   <o>    GPIOF_5<name=GPIOF_5_PIN_SEL>
//   <i>    Shows which pin GPIOF_5 is mapped to
//   <info>  [PTF5]
//     <0=> Disabled
//     <1=> PTF5 (Alias:p72)<selection=PTF5_SIG_SEL,GPIOF_5>
//     <0=> Default
#define GPIOF_5_PIN_SEL      0

// Pin Mapping for GPIOF_6 signal
//   <o>    GPIOF_6<name=GPIOF_6_PIN_SEL>
//   <i>    Shows which pin GPIOF_6 is mapped to
//   <info>  [PTF6]
//     <0=> Disabled
//     <1=> PTF6 (Alias:p73)<selection=PTF6_SIG_SEL,GPIOF_6>
//     <0=> Default
#define GPIOF_6_PIN_SEL      0

// Pin Mapping for GPIOF_7 signal
//   <o>    GPIOF_7<name=GPIOF_7_PIN_SEL>
//   <i>    Shows which pin GPIOF_7 is mapped to
//   <info>  [PTF7]
//     <0=> Disabled
//     <1=> PTF7 (Alias:p74)<selection=PTF7_SIG_SEL,GPIOF_7>
//     <0=> Default
#define GPIOF_7_PIN_SEL      0

// </h>

// <h> General Purpose I/O (GPIOG)

// Pin Mapping for GPIOG_0 signal
//   <o>    GPIOG_0<name=GPIOG_0_PIN_SEL>
//   <i>    Shows which pin GPIOG_0 is mapped to
//   <info>  [PTG0]
//     <0=> Disabled
//     <1=> PTG0 (Alias:p75)<selection=PTG0_SIG_SEL,GPIOG_0>
//     <0=> Default
#define GPIOG_0_PIN_SEL      0

// Pin Mapping for GPIOG_1 signal
//   <o>    GPIOG_1<name=GPIOG_1_PIN_SEL>
//   <i>    Shows which pin GPIOG_1 is mapped to
//   <info>  [PTG1]
//     <0=> Disabled
//     <1=> PTG1 (Alias:p76)<selection=PTG1_SIG_SEL,GPIOG_1>
//     <0=> Default
#define GPIOG_1_PIN_SEL      0

// Pin Mapping for GPIOG_2 signal
//   <o>    GPIOG_2<name=GPIOG_2_PIN_SEL>
//   <i>    Shows which pin GPIOG_2 is mapped to
//   <info>  [PTG2]
//     <0=> Disabled
//     <1=> PTG2 (Alias:p77)<selection=PTG2_SIG_SEL,GPIOG_2>
//     <0=> Default
#define GPIOG_2_PIN_SEL      0

// Pin Mapping for GPIOG_3 signal
//   <o>    GPIOG_3<name=GPIOG_3_PIN_SEL>
//   <i>    Shows which pin GPIOG_3 is mapped to
//   <info>  [PTG3]
//     <0=> Disabled
//     <1=> PTG3 (Alias:p78)<selection=PTG3_SIG_SEL,GPIOG_3>
//     <0=> Default
#define GPIOG_3_PIN_SEL      0

// Pin Mapping for GPIOG_4 signal
//   <o>    GPIOG_4<name=GPIOG_4_PIN_SEL>
//   <i>    Shows which pin GPIOG_4 is mapped to
//   <info>  [PTG4]
//     <0=> Disabled
//     <1=> PTG4 (Alias:p79)<selection=PTG4_SIG_SEL,GPIOG_4>
//     <0=> Default
#define GPIOG_4_PIN_SEL      0

// Pin Mapping for GPIOG_5 signal
//   <o>    GPIOG_5<name=GPIOG_5_PIN_SEL>
//   <i>    Shows which pin GPIOG_5 is mapped to
//   <info>  [PTG5]
//     <0=> Disabled
//     <1=> PTG5 (Alias:p80)<selection=PTG5_SIG_SEL,GPIOG_5>
//     <0=> Default
#define GPIOG_5_PIN_SEL      0

// Pin Mapping for GPIOG_6 signal
//   <o>    GPIOG_6<name=GPIOG_6_PIN_SEL>
//   <i>    Shows which pin GPIOG_6 is mapped to
//   <info>  [PTG6]
//     <0=> Disabled
//     <1=> PTG6 (Alias:p81)<selection=PTG6_SIG_SEL,GPIOG_6>
//     <0=> Default
#define GPIOG_6_PIN_SEL      0

// Pin Mapping for GPIOG_7 signal
//   <o>    GPIOG_7<name=GPIOG_7_PIN_SEL>
//   <i>    Shows which pin GPIOG_7 is mapped to
//   <info>  [PTG7]
//     <0=> Disabled
//     <1=> PTG7 (Alias:p82)<selection=PTG7_SIG_SEL,GPIOG_7>
//     <0=> Default
#define GPIOG_7_PIN_SEL      0

// </h>

// <h> General Purpose I/O (GPIOH)

// Pin Mapping for GPIOH_0 signal
//   <o>    GPIOH_0<name=GPIOH_0_PIN_SEL>
//   <i>    Shows which pin GPIOH_0 is mapped to
//   <info>  [PTH0]
//     <0=> Disabled
//     <1=> PTH0 (Alias:p83)<selection=PTH0_SIG_SEL,GPIOH_0>
//     <0=> Default
#define GPIOH_0_PIN_SEL      0

// Pin Mapping for GPIOH_1 signal
//   <o>    GPIOH_1<name=GPIOH_1_PIN_SEL>
//   <i>    Shows which pin GPIOH_1 is mapped to
//   <info>  [PTH1]
//     <0=> Disabled
//     <1=> PTH1 (Alias:p84)<selection=PTH1_SIG_SEL,GPIOH_1>
//     <0=> Default
#define GPIOH_1_PIN_SEL      0

// Pin Mapping for GPIOH_2 signal
//   <o>    GPIOH_2<name=GPIOH_2_PIN_SEL>
//   <i>    Shows which pin GPIOH_2 is mapped to
//   <info>  [PTH2]
//     <0=> Disabled
//     <1=> PTH2 (Alias:p85)<selection=PTH2_SIG_SEL,GPIOH_2>
//     <0=> Default
#define GPIOH_2_PIN_SEL      0

// Pin Mapping for GPIOH_3 signal
//   <o>    GPIOH_3<name=GPIOH_3_PIN_SEL>
//   <i>    Shows which pin GPIOH_3 is mapped to
//   <info>  [PTH3]
//     <0=> Disabled
//     <1=> PTH3 (Alias:p86)<selection=PTH3_SIG_SEL,GPIOH_3>
//     <0=> Default
#define GPIOH_3_PIN_SEL      0

// Pin Mapping for GPIOH_4 signal
//   <o>    GPIOH_4<name=GPIOH_4_PIN_SEL>
//   <i>    Shows which pin GPIOH_4 is mapped to
//   <info>  [PTH4]
//     <0=> Disabled
//     <1=> PTH4 (Alias:p87)<selection=PTH4_SIG_SEL,GPIOH_4>
//     <0=> Default
#define GPIOH_4_PIN_SEL      0

// Pin Mapping for GPIOH_5 signal
//   <o>    GPIOH_5<name=GPIOH_5_PIN_SEL>
//   <i>    Shows which pin GPIOH_5 is mapped to
//   <info>  [PTH5]
//     <0=> Disabled
//     <1=> PTH5 (Alias:p88)<selection=PTH5_SIG_SEL,GPIOH_5>
//     <0=> Default
#define GPIOH_5_PIN_SEL      0

// Pin Mapping for GPIOH_6 signal
//   <o>    GPIOH_6<name=GPIOH_6_PIN_SEL>
//   <i>    Shows which pin GPIOH_6 is mapped to
//   <info>  [PTH6]
//     <0=> Disabled
//     <1=> PTH6 (Alias:p89)<selection=PTH6_SIG_SEL,GPIOH_6>
//     <0=> Default
#define GPIOH_6_PIN_SEL      0

// Pin Mapping for GPIOH_7 signal
//   <o>    GPIOH_7<name=GPIOH_7_PIN_SEL>
//   <i>    Shows which pin GPIOH_7 is mapped to
//   <info>  [PTH7]
//     <0=> Disabled
//     <1=> PTH7 (Alias:p90)<selection=PTH7_SIG_SEL,GPIOH_7>
//     <0=> Default
#define GPIOH_7_PIN_SEL      0

// </h>

// <h> General Purpose I/O (GPIOI)

// Pin Mapping for GPIOI_0 signal
//   <o>    GPIOI_0<name=GPIOI_0_PIN_SEL>
//   <i>    Shows which pin GPIOI_0 is mapped to
//   <info>  [PTI0]
//     <0=> Disabled
//     <1=> PTI0 (Alias:p91)<selection=PTI0_SIG_SEL,GPIOI_0>
//     <0=> Default
#define GPIOI_0_PIN_SEL      0

// Pin Mapping for GPIOI_1 signal
//   <o>    GPIOI_1<name=GPIOI_1_PIN_SEL>
//   <i>    Shows which pin GPIOI_1 is mapped to
//   <info>  [PTI1]
//     <0=> Disabled
//     <1=> PTI1 (Alias:p92)<selection=PTI1_SIG_SEL,GPIOI_1>
//     <0=> Default
#define GPIOI_1_PIN_SEL      0

// Pin Mapping for GPIOI_2 signal
//   <o>    GPIOI_2<name=GPIOI_2_PIN_SEL>
//   <i>    Shows which pin GPIOI_2 is mapped to
//   <info>  [PTI2]
//     <0=> Disabled
//     <1=> PTI2 (Alias:p93)<selection=PTI2_SIG_SEL,GPIOI_2>
//     <0=> Default
#define GPIOI_2_PIN_SEL      0

// Pin Mapping for GPIOI_3 signal
//   <o>    GPIOI_3<name=GPIOI_3_PIN_SEL>
//   <i>    Shows which pin GPIOI_3 is mapped to
//   <info>  [PTI3]
//     <0=> Disabled
//     <1=> PTI3 (Alias:p94)<selection=PTI3_SIG_SEL,GPIOI_3>
//     <0=> Default
#define GPIOI_3_PIN_SEL      0

// </h>

// <h> Inter-Integrated Circuit (I2C0)

// Pin Mapping for I2C0_SCL signal
//   <o>    I2C0_SCL<name=I2C0_SCL_PIN_SEL>
//   <i>    Shows which pin I2C0_SCL is mapped to
//   <info>  [PTD7, PTG3, PTE6]
//     <0=> Disabled
//     <1=> PTD7 (Alias:p54)<selection=PTD7_SIG_SEL,I2C0_SCL>
//     <2=> PTG3 (Alias:p78)<selection=PTG3_SIG_SEL,I2C0_SCL>
//     <3=> PTE6 (Alias:p65)<selection=PTE6_SIG_SEL,I2C0_SCL>
//     <0=> Default
#define I2C0_SCL_PIN_SEL     0

// Pin Mapping for I2C0_SDA signal
//   <o>    I2C0_SDA<name=I2C0_SDA_PIN_SEL>
//   <i>    Shows which pin I2C0_SDA is mapped to
//   <info>  [PTE0, PTG4, PTE7]
//     <0=> Disabled
//     <1=> PTE0 (Alias:p55)<selection=PTE0_SIG_SEL,I2C0_SDA>
//     <2=> PTG4 (Alias:p79)<selection=PTG4_SIG_SEL,I2C0_SDA>
//     <3=> PTE7 (Alias:p66)<selection=PTE7_SIG_SEL,I2C0_SDA>
//     <0=> Default
#define I2C0_SDA_PIN_SEL     0

// </h>

// <h> Inter-Integrated Circuit (I2C1)

// Pin Mapping for I2C1_SDA signal
//   <o>    I2C1_SDA<name=I2C1_SDA_PIN_SEL>
//   <i>    Shows which pin I2C1_SDA is mapped to
//   <info>  [PTF6, PTE2]
//     <0=> Disabled
//     <1=> PTF6 (Alias:p73)<selection=PTF6_SIG_SEL,I2C1_SDA>
//     <2=> PTE2 (Alias:p57)<selection=PTE2_SIG_SEL,I2C1_SDA>
//     <0=> Default
#define I2C1_SDA_PIN_SEL     0

// Pin Mapping for I2C1_SCL signal
//   <o>    I2C1_SCL<name=I2C1_SCL_PIN_SEL>
//   <i>    Shows which pin I2C1_SCL is mapped to
//   <info>  [PTF5, PTE3]
//     <0=> Disabled
//     <1=> PTF5 (Alias:p72)<selection=PTF5_SIG_SEL,I2C1_SCL>
//     <2=> PTE3 (Alias:p58)<selection=PTE3_SIG_SEL,I2C1_SCL>
//     <0=> Default
#define I2C1_SCL_PIN_SEL     0

// </h>

// <h> Low-Leakage Wake-up Unit (LLWU)

// Pin Mapping for LLWU_P0 signal
//   <o>    LLWU_P0<name=LLWU_P0_PIN_SEL>
//   <i>    Shows which pin LLWU_P0 is mapped to
//   <info>  [PTG6]
//     <0=> Disabled
//     <1=> PTG6 (Alias:p81)<selection=PTG6_SIG_SEL,LLWU_P0>
//     <0=> Default
#define LLWU_P0_PIN_SEL      0

// Pin Mapping for LLWU_P1 signal
//   <o>    LLWU_P1<name=LLWU_P1_PIN_SEL>
//   <i>    Shows which pin LLWU_P1 is mapped to
//   <info>  [PTG2]
//     <0=> Disabled
//     <1=> PTG2 (Alias:p77)<selection=PTG2_SIG_SEL,LLWU_P1>
//     <0=> Default
#define LLWU_P1_PIN_SEL      0

// Pin Mapping for LLWU_P2 signal
//   <o>    LLWU_P2<name=LLWU_P2_PIN_SEL>
//   <i>    Shows which pin LLWU_P2 is mapped to
//   <info>  [PTG1]
//     <0=> Disabled
//     <1=> PTG1 (Alias:p76)<selection=PTG1_SIG_SEL,LLWU_P2>
//     <0=> Default
#define LLWU_P2_PIN_SEL      0

// Pin Mapping for LLWU_P3 signal
//   <o>    LLWU_P3<name=LLWU_P3_PIN_SEL>
//   <i>    Shows which pin LLWU_P3 is mapped to
//   <info>  [PTF6]
//     <0=> Disabled
//     <1=> PTF6 (Alias:p73)<selection=PTF6_SIG_SEL,LLWU_P3>
//     <0=> Default
#define LLWU_P3_PIN_SEL      0

// Pin Mapping for LLWU_P4 signal
//   <o>    LLWU_P4<name=LLWU_P4_PIN_SEL>
//   <i>    Shows which pin LLWU_P4 is mapped to
//   <info>  [PTF0]
//     <0=> Disabled
//     <1=> PTF0 (Alias:p67)<selection=PTF0_SIG_SEL,LLWU_P4>
//     <0=> Default
#define LLWU_P4_PIN_SEL      0

// Pin Mapping for LLWU_P5 signal
//   <o>    LLWU_P5<name=LLWU_P5_PIN_SEL>
//   <i>    Shows which pin LLWU_P5 is mapped to
//   <info>  [PTE6]
//     <0=> Disabled
//     <1=> PTE6 (Alias:p65)<selection=PTE6_SIG_SEL,LLWU_P5>
//     <0=> Default
#define LLWU_P5_PIN_SEL      0

// Pin Mapping for LLWU_P6 signal
//   <o>    LLWU_P6<name=LLWU_P6_PIN_SEL>
//   <i>    Shows which pin LLWU_P6 is mapped to
//   <info>  [PTE5]
//     <0=> Disabled
//     <1=> PTE5 (Alias:p64)<selection=PTE5_SIG_SEL,LLWU_P6>
//     <0=> Default
#define LLWU_P6_PIN_SEL      0

// Pin Mapping for LLWU_P7 signal
//   <o>    LLWU_P7<name=LLWU_P7_PIN_SEL>
//   <i>    Shows which pin LLWU_P7 is mapped to
//   <info>  [PTD7]
//     <0=> Disabled
//     <1=> PTD7 (Alias:p54)<selection=PTD7_SIG_SEL,LLWU_P7>
//     <0=> Default
#define LLWU_P7_PIN_SEL      0

// Pin Mapping for LLWU_P8 signal
//   <o>    LLWU_P8<name=LLWU_P8_PIN_SEL>
//   <i>    Shows which pin LLWU_P8 is mapped to
//   <info>  [PTD6]
//     <0=> Disabled
//     <1=> PTD6 (Alias:p53)<selection=PTD6_SIG_SEL,LLWU_P8>
//     <0=> Default
#define LLWU_P8_PIN_SEL      0

// Pin Mapping for LLWU_P9 signal
//   <o>    LLWU_P9<name=LLWU_P9_PIN_SEL>
//   <i>    Shows which pin LLWU_P9 is mapped to
//   <info>  [PTD4]
//     <0=> Disabled
//     <1=> PTD4 (Alias:p51)<selection=PTD4_SIG_SEL,LLWU_P9>
//     <0=> Default
#define LLWU_P9_PIN_SEL      0

// Pin Mapping for LLWU_P10 signal
//   <o>    LLWU_P10<name=LLWU_P10_PIN_SEL>
//   <i>    Shows which pin LLWU_P10 is mapped to
//   <info>  [PTD2]
//     <0=> Disabled
//     <1=> PTD2 (Alias:p49)<selection=PTD2_SIG_SEL,LLWU_P10>
//     <0=> Default
#define LLWU_P10_PIN_SEL     0

// Pin Mapping for LLWU_P11 signal
//   <o>    LLWU_P11<name=LLWU_P11_PIN_SEL>
//   <i>    Shows which pin LLWU_P11 is mapped to
//   <info>  [PTD0]
//     <0=> Disabled
//     <1=> PTD0 (Alias:p47)<selection=PTD0_SIG_SEL,LLWU_P11>
//     <0=> Default
#define LLWU_P11_PIN_SEL     0

// Pin Mapping for LLWU_P12 signal
//   <o>    LLWU_P12<name=LLWU_P12_PIN_SEL>
//   <i>    Shows which pin LLWU_P12 is mapped to
//   <info>  [PTC5]
//     <0=> Disabled
//     <1=> PTC5 (Alias:p44)<selection=PTC5_SIG_SEL,LLWU_P12>
//     <0=> Default
#define LLWU_P12_PIN_SEL     0

// Pin Mapping for LLWU_P13 signal
//   <o>    LLWU_P13<name=LLWU_P13_PIN_SEL>
//   <i>    Shows which pin LLWU_P13 is mapped to
//   <info>  [PTC3]
//     <0=> Disabled
//     <1=> PTC3 (Alias:p22)<selection=PTC3_SIG_SEL,LLWU_P13>
//     <0=> Default
#define LLWU_P13_PIN_SEL     0

// Pin Mapping for LLWU_P14 signal
//   <o>    LLWU_P14<name=LLWU_P14_PIN_SEL>
//   <i>    Shows which pin LLWU_P14 is mapped to
//   <info>  [PTA6]
//     <0=> Disabled
//     <1=> PTA6 (Alias:p7)<selection=PTA6_SIG_SEL,LLWU_P14>
//     <0=> Default
#define LLWU_P14_PIN_SEL     0

// Pin Mapping for LLWU_P15 signal
//   <o>    LLWU_P15<name=LLWU_P15_PIN_SEL>
//   <i>    Shows which pin LLWU_P15 is mapped to
//   <info>  [PTA4]
//     <0=> Disabled
//     <1=> PTA4 (Alias:p5)<selection=PTA4_SIG_SEL,LLWU_P15>
//     <0=> Default
#define LLWU_P15_PIN_SEL     0

// </h>

// <h> Low Power Timer (LPTMR)

// Pin Mapping for LPTMR_ALT0 signal
//   <o>    LPTMR_ALT0<name=LPTMR_ALT0_PIN_SEL>
//   <i>    Shows which pin LPTMR_ALT0 is mapped to
//   <info>  [PTE4, PTF4, PTG1]
//     <0=> Disabled
//     <1=> PTE4 (Alias:p63)<selection=PTE4_SIG_SEL,LPTMR_ALT0>
//     <2=> PTF4 (Alias:p71)<selection=PTF4_SIG_SEL,LPTMR_ALT0>
//     <3=> PTG1 (Alias:p76)<selection=PTG1_SIG_SEL,LPTMR_ALT0>
//     <0=> Default
#define LPTMR_ALT0_PIN_SEL   0

// Pin Mapping for LPTMR_ALT1 signal
//   <o>    LPTMR_ALT1<name=LPTMR_ALT1_PIN_SEL>
//   <i>    Shows which pin LPTMR_ALT1 is mapped to
//   <info>  [PTD6, PTF3, PTG5]
//     <0=> Disabled
//     <1=> PTD6 (Alias:p53)<selection=PTD6_SIG_SEL,LPTMR_ALT1>
//     <2=> PTF3 (Alias:p70)<selection=PTF3_SIG_SEL,LPTMR_ALT1>
//     <3=> PTG5 (Alias:p80)<selection=PTG5_SIG_SEL,LPTMR_ALT1>
//     <0=> Default
#define LPTMR_ALT1_PIN_SEL   0

// Pin Mapping for LPTMR_ALT2 signal
//   <o>    LPTMR_ALT2<name=LPTMR_ALT2_PIN_SEL>
//   <i>    Shows which pin LPTMR_ALT2 is mapped to
//   <info>  [PTD5, PTG0, PTG6]
//     <0=> Disabled
//     <1=> PTD5 (Alias:p52)<selection=PTD5_SIG_SEL,LPTMR_ALT2>
//     <2=> PTG0 (Alias:p75)<selection=PTG0_SIG_SEL,LPTMR_ALT2>
//     <3=> PTG6 (Alias:p81)<selection=PTG6_SIG_SEL,LPTMR_ALT2>
//     <0=> Default
#define LPTMR_ALT2_PIN_SEL   0

// </h>

// <h> Debug and Control

// Pin Mapping for NMI_B signal
//   <o>    NMI_B<name=NMI_B_PIN_SEL>
//   <i>    Shows which pin NMI_B is mapped to
//   <info>  [PTA4]
//     <0=> Disabled
//     <1=> PTA4 (Alias:p5) (reset default)<selection=PTA4_SIG_SEL,NMI_B (reset default)>
//     <2=> PTA4 (Alias:p5)<selection=PTA4_SIG_SEL,NMI_B>
//     <1=> Default
#define NMI_B_PIN_SEL        1

// Pin Mapping for RESET_B signal
//   <o>    RESET_B<name=RESET_B_PIN_SEL>
//   <i>    Shows which pin RESET_B is mapped to
//   <info>  [PTE1]
//     <0=> Disabled
//     <1=> PTE1 (Alias:p56) (reset default)<selection=PTE1_SIG_SEL,RESET_B (reset default)>
//     <2=> PTE1 (Alias:p56)<selection=PTE1_SIG_SEL,RESET_B>
//     <1=> Default
#define RESET_B_PIN_SEL      1

// Pin Mapping for SWD_CLK signal
//   <o>    SWD_CLK<name=SWD_CLK_PIN_SEL>
//   <i>    Shows which pin SWD_CLK is mapped to
//   <info>  [PTE7]
//     <0=> Disabled
//     <1=> PTE7 (Alias:p66) (reset default)<selection=PTE7_SIG_SEL,SWD_CLK (reset default)>
//     <2=> PTE7 (Alias:p66)<selection=PTE7_SIG_SEL,SWD_CLK>
//     <1=> Default
#define SWD_CLK_PIN_SEL      1

// Pin Mapping for SWD_IO signal
//   <o>    SWD_IO<name=SWD_IO_PIN_SEL>
//   <i>    Shows which pin SWD_IO is mapped to
//   <info>  [PTE6]
//     <0=> Disabled
//     <1=> PTE6 (Alias:p65) (reset default)<selection=PTE6_SIG_SEL,SWD_IO (reset default)>
//     <2=> PTE6 (Alias:p65)<selection=PTE6_SIG_SEL,SWD_IO>
//     <1=> Default
#define SWD_IO_PIN_SEL       1

// </h>

// <h> (PXBAR)

// Pin Mapping for PXBAR_IN0 signal
//   <o>    PXBAR_IN0<name=PXBAR_IN0_PIN_SEL>
//   <i>    Shows which pin PXBAR_IN0 is mapped to
//   <info>  [PTA6]
//     <0=> Disabled
//     <1=> PTA6 (Alias:p7)<selection=PTA6_SIG_SEL,PXBAR_IN0>
//     <0=> Default
#define PXBAR_IN0_PIN_SEL    0

// Pin Mapping for PXBAR_IN1 signal
//   <o>    PXBAR_IN1<name=PXBAR_IN1_PIN_SEL>
//   <i>    Shows which pin PXBAR_IN1 is mapped to
//   <info>  [PTC0]
//     <0=> Disabled
//     <1=> PTC0 (Alias:p19)<selection=PTC0_SIG_SEL,PXBAR_IN1>
//     <0=> Default
#define PXBAR_IN1_PIN_SEL    0

// Pin Mapping for PXBAR_IN2 signal
//   <o>    PXBAR_IN2<name=PXBAR_IN2_PIN_SEL>
//   <i>    Shows which pin PXBAR_IN2 is mapped to
//   <info>  [PTD0]
//     <0=> Disabled
//     <1=> PTD0 (Alias:p47)<selection=PTD0_SIG_SEL,PXBAR_IN2>
//     <0=> Default
#define PXBAR_IN2_PIN_SEL    0

// Pin Mapping for PXBAR_IN3 signal
//   <o>    PXBAR_IN3<name=PXBAR_IN3_PIN_SEL>
//   <i>    Shows which pin PXBAR_IN3 is mapped to
//   <info>  [PTD2]
//     <0=> Disabled
//     <1=> PTD2 (Alias:p49)<selection=PTD2_SIG_SEL,PXBAR_IN3>
//     <0=> Default
#define PXBAR_IN3_PIN_SEL    0

// Pin Mapping for PXBAR_IN4 signal
//   <o>    PXBAR_IN4<name=PXBAR_IN4_PIN_SEL>
//   <i>    Shows which pin PXBAR_IN4 is mapped to
//   <info>  [PTD7]
//     <0=> Disabled
//     <1=> PTD7 (Alias:p54)<selection=PTD7_SIG_SEL,PXBAR_IN4>
//     <0=> Default
#define PXBAR_IN4_PIN_SEL    0

// Pin Mapping for PXBAR_IN5 signal
//   <o>    PXBAR_IN5<name=PXBAR_IN5_PIN_SEL>
//   <i>    Shows which pin PXBAR_IN5 is mapped to
//   <info>  [PTE6]
//     <0=> Disabled
//     <1=> PTE6 (Alias:p65)<selection=PTE6_SIG_SEL,PXBAR_IN5>
//     <0=> Default
#define PXBAR_IN5_PIN_SEL    0

// Pin Mapping for PXBAR_IN6 signal
//   <o>    PXBAR_IN6<name=PXBAR_IN6_PIN_SEL>
//   <i>    Shows which pin PXBAR_IN6 is mapped to
//   <info>  [PTE2]
//     <0=> Disabled
//     <1=> PTE2 (Alias:p57)<selection=PTE2_SIG_SEL,PXBAR_IN6>
//     <0=> Default
#define PXBAR_IN6_PIN_SEL    0

// Pin Mapping for PXBAR_IN7 signal
//   <o>    PXBAR_IN7<name=PXBAR_IN7_PIN_SEL>
//   <i>    Shows which pin PXBAR_IN7 is mapped to
//   <info>  [PTH6]
//     <0=> Disabled
//     <1=> PTH6 (Alias:p89)<selection=PTH6_SIG_SEL,PXBAR_IN7>
//     <0=> Default
#define PXBAR_IN7_PIN_SEL    0

// Pin Mapping for PXBAR_IN8 signal
//   <o>    PXBAR_IN8<name=PXBAR_IN8_PIN_SEL>
//   <i>    Shows which pin PXBAR_IN8 is mapped to
//   <info>  [PTI0]
//     <0=> Disabled
//     <1=> PTI0 (Alias:p91)<selection=PTI0_SIG_SEL,PXBAR_IN8>
//     <0=> Default
#define PXBAR_IN8_PIN_SEL    0

// Pin Mapping for PXBAR_OUT0 signal
//   <o>    PXBAR_OUT0<name=PXBAR_OUT0_PIN_SEL>
//   <i>    Shows which pin PXBAR_OUT0 is mapped to
//   <info>  [PTA7]
//     <0=> Disabled
//     <1=> PTA7 (Alias:p8)<selection=PTA7_SIG_SEL,PXBAR_OUT0>
//     <0=> Default
#define PXBAR_OUT0_PIN_SEL   0

// Pin Mapping for PXBAR_OUT1 signal
//   <o>    PXBAR_OUT1<name=PXBAR_OUT1_PIN_SEL>
//   <i>    Shows which pin PXBAR_OUT1 is mapped to
//   <info>  [PTC2]
//     <0=> Disabled
//     <1=> PTC2 (Alias:p21)<selection=PTC2_SIG_SEL,PXBAR_OUT1>
//     <0=> Default
#define PXBAR_OUT1_PIN_SEL   0

// Pin Mapping for PXBAR_OUT2 signal
//   <o>    PXBAR_OUT2<name=PXBAR_OUT2_PIN_SEL>
//   <i>    Shows which pin PXBAR_OUT2 is mapped to
//   <info>  [PTC7]
//     <0=> Disabled
//     <1=> PTC7 (Alias:p46)<selection=PTC7_SIG_SEL,PXBAR_OUT2>
//     <0=> Default
#define PXBAR_OUT2_PIN_SEL   0

// Pin Mapping for PXBAR_OUT3 signal
//   <o>    PXBAR_OUT3<name=PXBAR_OUT3_PIN_SEL>
//   <i>    Shows which pin PXBAR_OUT3 is mapped to
//   <info>  [PTD1]
//     <0=> Disabled
//     <1=> PTD1 (Alias:p48)<selection=PTD1_SIG_SEL,PXBAR_OUT3>
//     <0=> Default
#define PXBAR_OUT3_PIN_SEL   0

// Pin Mapping for PXBAR_OUT4 signal
//   <o>    PXBAR_OUT4<name=PXBAR_OUT4_PIN_SEL>
//   <i>    Shows which pin PXBAR_OUT4 is mapped to
//   <info>  [PTE0]
//     <0=> Disabled
//     <1=> PTE0 (Alias:p55)<selection=PTE0_SIG_SEL,PXBAR_OUT4>
//     <0=> Default
#define PXBAR_OUT4_PIN_SEL   0

// Pin Mapping for PXBAR_OUT5 signal
//   <o>    PXBAR_OUT5<name=PXBAR_OUT5_PIN_SEL>
//   <i>    Shows which pin PXBAR_OUT5 is mapped to
//   <info>  [PTE7]
//     <0=> Disabled
//     <1=> PTE7 (Alias:p66)<selection=PTE7_SIG_SEL,PXBAR_OUT5>
//     <0=> Default
#define PXBAR_OUT5_PIN_SEL   0

// Pin Mapping for PXBAR_OUT6 signal
//   <o>    PXBAR_OUT6<name=PXBAR_OUT6_PIN_SEL>
//   <i>    Shows which pin PXBAR_OUT6 is mapped to
//   <info>  [PTF1]
//     <0=> Disabled
//     <1=> PTF1 (Alias:p68)<selection=PTF1_SIG_SEL,PXBAR_OUT6>
//     <0=> Default
#define PXBAR_OUT6_PIN_SEL   0

// Pin Mapping for PXBAR_OUT7 signal
//   <o>    PXBAR_OUT7<name=PXBAR_OUT7_PIN_SEL>
//   <i>    Shows which pin PXBAR_OUT7 is mapped to
//   <info>  [PTH7]
//     <0=> Disabled
//     <1=> PTH7 (Alias:p90)<selection=PTH7_SIG_SEL,PXBAR_OUT7>
//     <0=> Default
#define PXBAR_OUT7_PIN_SEL   0

// Pin Mapping for PXBAR_OUT8 signal
//   <o>    PXBAR_OUT8<name=PXBAR_OUT8_PIN_SEL>
//   <i>    Shows which pin PXBAR_OUT8 is mapped to
//   <info>  [PTI1]
//     <0=> Disabled
//     <1=> PTI1 (Alias:p92)<selection=PTI1_SIG_SEL,PXBAR_OUT8>
//     <0=> Default
#define PXBAR_OUT8_PIN_SEL   0

// </h>

// <h> (QT)

// Pin Mapping for QT0 signal
//   <o>    QT0<name=QT0_PIN_SEL>
//   <i>    Shows which pin QT0 is mapped to
//   <info>  [PTF1, PTD5]
//     <0=> Disabled
//     <1=> PTF1 (Alias:p68)<selection=PTF1_SIG_SEL,QT0>
//     <2=> PTD5 (Alias:p52)<selection=PTD5_SIG_SEL,QT0>
//     <0=> Default
#define QT0_PIN_SEL          0

// Pin Mapping for QT1 signal
//   <o>    QT1<name=QT1_PIN_SEL>
//   <i>    Shows which pin QT1 is mapped to
//   <info>  [PTG0, PTC6]
//     <0=> Disabled
//     <1=> PTG0 (Alias:p75)<selection=PTG0_SIG_SEL,QT1>
//     <2=> PTC6 (Alias:p45)<selection=PTC6_SIG_SEL,QT1>
//     <0=> Default
#define QT1_PIN_SEL          0

// Pin Mapping for QT2 signal
//   <o>    QT2<name=QT2_PIN_SEL>
//   <i>    Shows which pin QT2 is mapped to
//   <info>  [PTF7, PTF0]
//     <0=> Disabled
//     <1=> PTF7 (Alias:p74)<selection=PTF7_SIG_SEL,QT2>
//     <2=> PTF0 (Alias:p67)<selection=PTF0_SIG_SEL,QT2>
//     <0=> Default
#define QT2_PIN_SEL          0

// Pin Mapping for QT3 signal
//   <o>    QT3<name=QT3_PIN_SEL>
//   <i>    Shows which pin QT3 is mapped to
//   <info>  [PTE5, PTD1]
//     <0=> Disabled
//     <1=> PTE5 (Alias:p64)<selection=PTE5_SIG_SEL,QT3>
//     <2=> PTD1 (Alias:p48)<selection=PTD1_SIG_SEL,QT3>
//     <0=> Default
#define QT3_PIN_SEL          0

// </h>

// <h> Serial Communication Interface (SCI0)

// Pin Mapping for SCI0_CTS signal
//   <o>    SCI0_CTS<name=SCI0_CTS_PIN_SEL>
//   <i>    Shows which pin SCI0_CTS is mapped to
//   <info>  [PTC6]
//     <0=> Disabled
//     <1=> PTC6 (Alias:p45)<selection=PTC6_SIG_SEL,SCI0_CTS>
//     <0=> Default
#define SCI0_CTS_PIN_SEL     0

// Pin Mapping for SCI0_RTS signal
//   <o>    SCI0_RTS<name=SCI0_RTS_PIN_SEL>
//   <i>    Shows which pin SCI0_RTS is mapped to
//   <info>  [PTC5]
//     <0=> Disabled
//     <1=> PTC5 (Alias:p44)<selection=PTC5_SIG_SEL,SCI0_RTS>
//     <0=> Default
#define SCI0_RTS_PIN_SEL     0

// Pin Mapping for SCI0_RxD signal
//   <o>    SCI0_RxD<name=SCI0_RxD_PIN_SEL>
//   <i>    Shows which pin SCI0_RxD is mapped to
//   <info>  [PTD0, PTF3]
//     <0=> Disabled
//     <1=> PTD0 (Alias:p47)<selection=PTD0_SIG_SEL,SCI0_RxD>
//     <2=> PTF3 (Alias:p70)<selection=PTF3_SIG_SEL,SCI0_RxD>
//     <0=> Default
#define SCI0_RxD_PIN_SEL     0

// Pin Mapping for SCI0_TxD signal
//   <o>    SCI0_TxD<name=SCI0_TxD_PIN_SEL>
//   <i>    Shows which pin SCI0_TxD is mapped to
//   <info>  [PTC7, PTF4]
//     <0=> Disabled
//     <1=> PTC7 (Alias:p46)<selection=PTC7_SIG_SEL,SCI0_TxD>
//     <2=> PTF4 (Alias:p71)<selection=PTF4_SIG_SEL,SCI0_TxD>
//     <0=> Default
#define SCI0_TxD_PIN_SEL     0

// </h>

// <h> Serial Communication Interface (SCI1)

// Pin Mapping for SCI1_CTS signal
//   <o>    SCI1_CTS<name=SCI1_CTS_PIN_SEL>
//   <i>    Shows which pin SCI1_CTS is mapped to
//   <info>  [PTD3, PTH6]
//     <0=> Disabled
//     <1=> PTD3 (Alias:p50)<selection=PTD3_SIG_SEL,SCI1_CTS>
//     <2=> PTH6 (Alias:p89)<selection=PTH6_SIG_SEL,SCI1_CTS>
//     <0=> Default
#define SCI1_CTS_PIN_SEL     0

// Pin Mapping for SCI1_RTS signal
//   <o>    SCI1_RTS<name=SCI1_RTS_PIN_SEL>
//   <i>    Shows which pin SCI1_RTS is mapped to
//   <info>  [PTD4, PTH7]
//     <0=> Disabled
//     <1=> PTD4 (Alias:p51)<selection=PTD4_SIG_SEL,SCI1_RTS>
//     <2=> PTH7 (Alias:p90)<selection=PTH7_SIG_SEL,SCI1_RTS>
//     <0=> Default
#define SCI1_RTS_PIN_SEL     0

// Pin Mapping for SCI1_RxD signal
//   <o>    SCI1_RxD<name=SCI1_RxD_PIN_SEL>
//   <i>    Shows which pin SCI1_RxD is mapped to
//   <info>  [PTD2, PTI0]
//     <0=> Disabled
//     <1=> PTD2 (Alias:p49)<selection=PTD2_SIG_SEL,SCI1_RxD>
//     <2=> PTI0 (Alias:p91)<selection=PTI0_SIG_SEL,SCI1_RxD>
//     <0=> Default
#define SCI1_RxD_PIN_SEL     0

// Pin Mapping for SCI1_TxD signal
//   <o>    SCI1_TxD<name=SCI1_TxD_PIN_SEL>
//   <i>    Shows which pin SCI1_TxD is mapped to
//   <info>  [PTD1, PTI1]
//     <0=> Disabled
//     <1=> PTD1 (Alias:p48)<selection=PTD1_SIG_SEL,SCI1_TxD>
//     <2=> PTI1 (Alias:p92)<selection=PTI1_SIG_SEL,SCI1_TxD>
//     <0=> Default
#define SCI1_TxD_PIN_SEL     0

// </h>

// <h> Serial Communication Interface (SCI2)

// Pin Mapping for SCI2_CTS signal
//   <o>    SCI2_CTS<name=SCI2_CTS_PIN_SEL>
//   <i>    Shows which pin SCI2_CTS is mapped to
//   <info>  [PTE4]
//     <0=> Disabled
//     <1=> PTE4 (Alias:p63)<selection=PTE4_SIG_SEL,SCI2_CTS>
//     <0=> Default
#define SCI2_CTS_PIN_SEL     0

// Pin Mapping for SCI2_RTS signal
//   <o>    SCI2_RTS<name=SCI2_RTS_PIN_SEL>
//   <i>    Shows which pin SCI2_RTS is mapped to
//   <info>  [PTE5]
//     <0=> Disabled
//     <1=> PTE5 (Alias:p64)<selection=PTE5_SIG_SEL,SCI2_RTS>
//     <0=> Default
#define SCI2_RTS_PIN_SEL     0

// Pin Mapping for SCI2_RxD signal
//   <o>    SCI2_RxD<name=SCI2_RxD_PIN_SEL>
//   <i>    Shows which pin SCI2_RxD is mapped to
//   <info>  [PTE6]
//     <0=> Disabled
//     <1=> PTE6 (Alias:p65)<selection=PTE6_SIG_SEL,SCI2_RxD>
//     <0=> Default
#define SCI2_RxD_PIN_SEL     0

// Pin Mapping for SCI2_TxD signal
//   <o>    SCI2_TxD<name=SCI2_TxD_PIN_SEL>
//   <i>    Shows which pin SCI2_TxD is mapped to
//   <info>  [PTE7]
//     <0=> Disabled
//     <1=> PTE7 (Alias:p66)<selection=PTE7_SIG_SEL,SCI2_TxD>
//     <0=> Default
#define SCI2_TxD_PIN_SEL     0

// </h>

// <h> Serial Communication Interface (SCI3)

// Pin Mapping for SCI3_CTS signal
//   <o>    SCI3_CTS<name=SCI3_CTS_PIN_SEL>
//   <i>    Shows which pin SCI3_CTS is mapped to
//   <info>  [PTC1, PTD5]
//     <0=> Disabled
//     <1=> PTC1 (Alias:p20)<selection=PTC1_SIG_SEL,SCI3_CTS>
//     <2=> PTD5 (Alias:p52)<selection=PTD5_SIG_SEL,SCI3_CTS>
//     <0=> Default
#define SCI3_CTS_PIN_SEL     0

// Pin Mapping for SCI3_RTS signal
//   <o>    SCI3_RTS<name=SCI3_RTS_PIN_SEL>
//   <i>    Shows which pin SCI3_RTS is mapped to
//   <info>  [PTC0, PTD6]
//     <0=> Disabled
//     <1=> PTC0 (Alias:p19)<selection=PTC0_SIG_SEL,SCI3_RTS>
//     <2=> PTD6 (Alias:p53)<selection=PTD6_SIG_SEL,SCI3_RTS>
//     <0=> Default
#define SCI3_RTS_PIN_SEL     0

// Pin Mapping for SCI3_RxD signal
//   <o>    SCI3_RxD<name=SCI3_RxD_PIN_SEL>
//   <i>    Shows which pin SCI3_RxD is mapped to
//   <info>  [PTC3, PTD7]
//     <0=> Disabled
//     <1=> PTC3 (Alias:p22)<selection=PTC3_SIG_SEL,SCI3_RxD>
//     <2=> PTD7 (Alias:p54)<selection=PTD7_SIG_SEL,SCI3_RxD>
//     <0=> Default
#define SCI3_RxD_PIN_SEL     0

// Pin Mapping for SCI3_TxD signal
//   <o>    SCI3_TxD<name=SCI3_TxD_PIN_SEL>
//   <i>    Shows which pin SCI3_TxD is mapped to
//   <info>  [PTC2, PTE0]
//     <0=> Disabled
//     <1=> PTC2 (Alias:p21)<selection=PTC2_SIG_SEL,SCI3_TxD>
//     <2=> PTE0 (Alias:p55)<selection=PTE0_SIG_SEL,SCI3_TxD>
//     <0=> Default
#define SCI3_TxD_PIN_SEL     0

// </h>

// <h> Sigma-delta ADC (SDAD)

// Pin Mapping for SDADM0 signal
//   <o>    SDADM0<name=SDADM0_PIN_SEL><constant>
//   <i>    Shows which pin SDADM0 is mapped to
//   <info>  [SDADM0]
//     <0=> SDADM0 (Alias:p34)<selection=SDADM0_SIG_SEL,SDADM0>
//     <0=> Default
#define SDADM0_PIN_SEL       0

// Pin Mapping for SDADM1 signal
//   <o>    SDADM1<name=SDADM1_PIN_SEL><constant>
//   <i>    Shows which pin SDADM1 is mapped to
//   <info>  [SDADM1]
//     <0=> SDADM1 (Alias:p36)<selection=SDADM1_SIG_SEL,SDADM1>
//     <0=> Default
#define SDADM1_PIN_SEL       0

// Pin Mapping for SDADM2 signal
//   <o>    SDADM2<name=SDADM2_PIN_SEL><constant>
//   <i>    Shows which pin SDADM2 is mapped to
//   <info>  [SDADM2]
//     <0=> SDADM2 (Alias:p40)<selection=SDADM2_SIG_SEL,SDADM2/CMP1P3>
//     <0=> Default
#define SDADM2_PIN_SEL       0

// Pin Mapping for SDADM3 signal
//   <o>    SDADM3<name=SDADM3_PIN_SEL><constant>
//   <i>    Shows which pin SDADM3 is mapped to
//   <info>  [SDADM3]
//     <0=> SDADM3 (Alias:p43)<selection=SDADM3_SIG_SEL,SDADM3/CMP1P5>
//     <0=> Default
#define SDADM3_PIN_SEL       0

// Pin Mapping for SDADP0 signal
//   <o>    SDADP0<name=SDADP0_PIN_SEL><constant>
//   <i>    Shows which pin SDADP0 is mapped to
//   <info>  [SDADP0]
//     <0=> SDADP0 (Alias:p33)<selection=SDADP0_SIG_SEL,SDADP0>
//     <0=> Default
#define SDADP0_PIN_SEL       0

// Pin Mapping for SDADP1 signal
//   <o>    SDADP1<name=SDADP1_PIN_SEL><constant>
//   <i>    Shows which pin SDADP1 is mapped to
//   <info>  [SDADP1]
//     <0=> SDADP1 (Alias:p35)<selection=SDADP1_SIG_SEL,SDADP1>
//     <0=> Default
#define SDADP1_PIN_SEL       0

// Pin Mapping for SDADP2 signal
//   <o>    SDADP2<name=SDADP2_PIN_SEL><constant>
//   <i>    Shows which pin SDADP2 is mapped to
//   <info>  [SDADP2]
//     <0=> SDADP2 (Alias:p39)<selection=SDADP2_SIG_SEL,SDADP2/CMP1P2>
//     <0=> Default
#define SDADP2_PIN_SEL       0

// Pin Mapping for SDADP3 signal
//   <o>    SDADP3<name=SDADP3_PIN_SEL><constant>
//   <i>    Shows which pin SDADP3 is mapped to
//   <info>  [SDADP3]
//     <0=> SDADP3 (Alias:p42)<selection=SDADP3_SIG_SEL,SDADP3/CMP1P4>
//     <0=> Default
#define SDADP3_PIN_SEL       0

// </h>

// <h> Serial Peripheral Interface (SPI0)

// Pin Mapping for SPI0_MISO signal
//   <o>    SPI0_MISO<name=SPI0_MISO_PIN_SEL>
//   <i>    Shows which pin SPI0_MISO is mapped to
//   <info>  [PTG5, PTD4]
//     <0=> Disabled
//     <1=> PTG5 (Alias:p80)<selection=PTG5_SIG_SEL,SPI0_MISO>
//     <2=> PTD4 (Alias:p51)<selection=PTD4_SIG_SEL,SPI0_MISO>
//     <0=> Default
#define SPI0_MISO_PIN_SEL    0

// Pin Mapping for SPI0_MOSI signal
//   <o>    SPI0_MOSI<name=SPI0_MOSI_PIN_SEL>
//   <i>    Shows which pin SPI0_MOSI is mapped to
//   <info>  [PTG4, PTD3]
//     <0=> Disabled
//     <1=> PTG4 (Alias:p79)<selection=PTG4_SIG_SEL,SPI0_MOSI>
//     <2=> PTD3 (Alias:p50)<selection=PTD3_SIG_SEL,SPI0_MOSI>
//     <0=> Default
#define SPI0_MOSI_PIN_SEL    0

// Pin Mapping for SPI0_SCK signal
//   <o>    SPI0_SCK<name=SPI0_SCK_PIN_SEL>
//   <i>    Shows which pin SPI0_SCK is mapped to
//   <info>  [PTG3, PTD2]
//     <0=> Disabled
//     <1=> PTG3 (Alias:p78)<selection=PTG3_SIG_SEL,SPI0_SCK>
//     <2=> PTD2 (Alias:p49)<selection=PTD2_SIG_SEL,SPI0_SCK>
//     <0=> Default
#define SPI0_SCK_PIN_SEL     0

// Pin Mapping for SPI0_SS_B signal
//   <o>    SPI0_SS_B<name=SPI0_SS_B_PIN_SEL>
//   <i>    Shows which pin SPI0_SS_B is mapped to
//   <info>  [PTG2, PTD1]
//     <0=> Disabled
//     <1=> PTG2 (Alias:p77)<selection=PTG2_SIG_SEL,SPI0_SS_B>
//     <2=> PTD1 (Alias:p48)<selection=PTD1_SIG_SEL,SPI0_SS_B>
//     <0=> Default
#define SPI0_SS_B_PIN_SEL    0

// </h>

// <h> Serial Peripheral Interface (SPI1)

// Pin Mapping for SPI1_MISO signal
//   <o>    SPI1_MISO<name=SPI1_MISO_PIN_SEL>
//   <i>    Shows which pin SPI1_MISO is mapped to
//   <info>  [PTF5, PTI0, PTI1]
//     <0=> Disabled
//     <1=> PTF5 (Alias:p72)<selection=PTF5_SIG_SEL,SPI1_MISO>
//     <2=> PTI0 (Alias:p91)<selection=PTI0_SIG_SEL,SPI1_MISO>
//     <3=> PTI1 (Alias:p92)<selection=PTI1_SIG_SEL,SPI1_MISO>
//     <0=> Default
#define SPI1_MISO_PIN_SEL    0

// Pin Mapping for SPI1_MOSI signal
//   <o>    SPI1_MOSI<name=SPI1_MOSI_PIN_SEL>
//   <i>    Shows which pin SPI1_MOSI is mapped to
//   <info>  [PTF6, PTI1, PTI0]
//     <0=> Disabled
//     <1=> PTF6 (Alias:p73)<selection=PTF6_SIG_SEL,SPI1_MOSI>
//     <2=> PTI1 (Alias:p92)<selection=PTI1_SIG_SEL,SPI1_MOSI>
//     <3=> PTI0 (Alias:p91)<selection=PTI0_SIG_SEL,SPI1_MOSI>
//     <0=> Default
#define SPI1_MOSI_PIN_SEL    0

// Pin Mapping for SPI1_SCK signal
//   <o>    SPI1_SCK<name=SPI1_SCK_PIN_SEL>
//   <i>    Shows which pin SPI1_SCK is mapped to
//   <info>  [PTF4, PTH7]
//     <0=> Disabled
//     <1=> PTF4 (Alias:p71)<selection=PTF4_SIG_SEL,SPI1_SCK>
//     <2=> PTH7 (Alias:p90)<selection=PTH7_SIG_SEL,SPI1_SCK>
//     <0=> Default
#define SPI1_SCK_PIN_SEL     0

// Pin Mapping for SPI1_SS_B signal
//   <o>    SPI1_SS_B<name=SPI1_SS_B_PIN_SEL>
//   <i>    Shows which pin SPI1_SS_B is mapped to
//   <info>  [PTF3, PTH6]
//     <0=> Disabled
//     <1=> PTF3 (Alias:p70)<selection=PTF3_SIG_SEL,SPI1_SS_B>
//     <2=> PTH6 (Alias:p89)<selection=PTH6_SIG_SEL,SPI1_SS_B>
//     <0=> Default
#define SPI1_SS_B_PIN_SEL    0

// </h>

// </e>

//-------- <<< end of configuration section >>> -----------------  

/*
 * Common Mux settings for PCR
 */
#undef FIXED_ADC_FN            
#undef FIXED_GPIO_FN           
#undef FIXED_PORT_CLOCK_REG    
#define FIXED_ADC_FN             0                    // Fixed ADC Multiplexing value
#define FIXED_GPIO_FN            1                    // Fixed GPIO Multiplexing value
#define FIXED_PORT_CLOCK_REG     SCGC5                // Fixed PORT Clock

/*
 * Peripheral clock macros
 */
#define PORT_CLOCK_REG       SCGC5

namespace USBDM {

/*
 * Peripheral Pin Tables
 */
/**
 * @addtogroup PeripheralPinTables Peripheral Information Classes
 * @brief Provides instance specific information about a peripheral
 * @{
 */
/**
 * Peripheral information for Digital Input/Output
 */
class GpioAInfo {
public:
   //! PORT Hardware base pointer
   static constexpr uint32_t pcrAddress   = PORTA_BasePtr;

   //! GPIO Hardware base pointer
   static constexpr uint32_t gpioAddress   = GPIOA_BasePtr;

   //! Value for PCR (including MUX value)
   static constexpr uint32_t pcrValue  = GPIO_DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC5_PORTA_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC5);

};

/**
 * Peripheral information for Digital Input/Output
 */
class GpioBInfo {
public:
   //! PORT Hardware base pointer
   static constexpr uint32_t pcrAddress   = PORTB_BasePtr;

   //! GPIO Hardware base pointer
   static constexpr uint32_t gpioAddress   = GPIOB_BasePtr;

   //! Value for PCR (including MUX value)
   static constexpr uint32_t pcrValue  = GPIO_DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC5_PORTB_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC5);

};

/**
 * Peripheral information for Digital Input/Output
 */
class GpioCInfo {
public:
   //! PORT Hardware base pointer
   static constexpr uint32_t pcrAddress   = PORTC_BasePtr;

   //! GPIO Hardware base pointer
   static constexpr uint32_t gpioAddress   = GPIOC_BasePtr;

   //! Value for PCR (including MUX value)
   static constexpr uint32_t pcrValue  = GPIO_DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC5_PORTC_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC5);

};

/**
 * Peripheral information for Digital Input/Output
 */
class GpioDInfo {
public:
   //! PORT Hardware base pointer
   static constexpr uint32_t pcrAddress   = PORTD_BasePtr;

   //! GPIO Hardware base pointer
   static constexpr uint32_t gpioAddress   = GPIOD_BasePtr;

   //! Value for PCR (including MUX value)
   static constexpr uint32_t pcrValue  = GPIO_DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC5_PORTD_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC5);

};

/**
 * Peripheral information for Digital Input/Output
 */
class GpioEInfo {
public:
   //! PORT Hardware base pointer
   static constexpr uint32_t pcrAddress   = PORTE_BasePtr;

   //! GPIO Hardware base pointer
   static constexpr uint32_t gpioAddress   = GPIOE_BasePtr;

   //! Value for PCR (including MUX value)
   static constexpr uint32_t pcrValue  = GPIO_DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC5_PORTE_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC5);

};

/**
 * Peripheral information for Digital Input/Output
 */
class GpioFInfo {
public:
   //! PORT Hardware base pointer
   static constexpr uint32_t pcrAddress   = PORTF_BasePtr;

   //! GPIO Hardware base pointer
   static constexpr uint32_t gpioAddress   = GPIOF_BasePtr;

   //! Value for PCR (including MUX value)
   static constexpr uint32_t pcrValue  = GPIO_DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC5_PORTF_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC5);

};

/**
 * Peripheral information for Digital Input/Output
 */
class GpioGInfo {
public:
   //! PORT Hardware base pointer
   static constexpr uint32_t pcrAddress   = PORTG_BasePtr;

   //! GPIO Hardware base pointer
   static constexpr uint32_t gpioAddress   = GPIOG_BasePtr;

   //! Value for PCR (including MUX value)
   static constexpr uint32_t pcrValue  = GPIO_DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC5_PORTG_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC5);

};

/**
 * Peripheral information for Analogue Input
 */
class Adc0Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = ADC0_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC6_ADC_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC6);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (ADC0_SE0_PIN_SEL == 1)
         /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  5,  0 },
#else
         /*  0 */  { 0 },
#endif
#if (ADC0_SE1_PIN_SEL == 1)
         /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  6,  0 },
#else
         /*  1 */  { 0 },
#endif
#if (ADC0_SE2_PIN_SEL == 1)
         /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  7,  0 },
#else
         /*  2 */  { 0 },
#endif
#if (ADC0_SE3_PIN_SEL == 1)
         /*  3 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  4,  0 },
#else
         /*  3 */  { 0 },
#endif
#if (ADC0_SE4_PIN_SEL == 1)
         /*  4 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  5,  0 },
#else
         /*  4 */  { 0 },
#endif
#if (ADC0_SE5_PIN_SEL == 1)
         /*  5 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  6,  0 },
#else
         /*  5 */  { 0 },
#endif
#if (ADC0_SE6_PIN_SEL == 1)
         /*  6 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  7,  0 },
#else
         /*  6 */  { 0 },
#endif
#if (ADC0_SE7_PIN_SEL == 1)
         /*  7 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  0,  0 },
#else
         /*  7 */  { 0 },
#endif
#if (ADC0_SE8_PIN_SEL == 1)
         /*  8 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  1,  0 },
#else
         /*  8 */  { 0 },
#endif
#if (ADC0_SE9_PIN_SEL == 1)
         /*  9 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  2,  0 },
#else
         /*  9 */  { 0 },
#endif
#if (ADC0_SE10_PIN_SEL == 1)
         /* 10 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  1,  0 },
#else
         /* 10 */  { 0 },
#endif
#if (ADC0_SE11_PIN_SEL == 1)
         /* 11 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  2,  0 },
#else
         /* 11 */  { 0 },
#endif
   };
};

/**
 * Peripheral information for Analogue Input
 */
class Adc0aInfo {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = ADC0_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC6_ADC_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC6);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

};

/**
 * Peripheral information for CMP, Analogue Comparator
 */
class Cmp0Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = CMP0_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC4_CMP0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC4);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

};

/**
 * Peripheral information for CMP, Analogue Comparator
 */
class Cmp1Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = CMP1_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC4_CMP1_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC4);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

};

/**
 * Peripheral information for Direct Memory Access (DMA)
 */
class DmaMux0Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = DMAMUX0_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC6_DMAMUX0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC6);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

};

/**
 * Peripheral information for I2C, Inter-Integrated-Circuit Interface
 */
class I2c0Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = I2C0_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = I2C_DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC4_I2C0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC4);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (I2C0_SCL_PIN_SEL == 1)
         /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  7,  2 },
#elif (I2C0_SCL_PIN_SEL == 2)
         /*  0 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  3,  3 },
#elif (I2C0_SCL_PIN_SEL == 3)
         /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  6,  5 },
#else
         /*  0 */  { 0 },
#endif
#if (I2C0_SDA_PIN_SEL == 1)
         /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  0,  2 },
#elif (I2C0_SDA_PIN_SEL == 2)
         /*  1 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  4,  3 },
#elif (I2C0_SDA_PIN_SEL == 3)
         /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  7,  5 },
#else
         /*  1 */  { 0 },
#endif
   };
};

/**
 * Peripheral information for I2C, Inter-Integrated-Circuit Interface
 */
class I2c1Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = I2C1_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = I2C_DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC4_I2C1_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC4);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (I2C1_SCL_PIN_SEL == 1)
         /*  0 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  5,  3 },
#elif (I2C1_SCL_PIN_SEL == 2)
         /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  3,  4 },
#else
         /*  0 */  { 0 },
#endif
#if (I2C1_SDA_PIN_SEL == 1)
         /*  1 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  6,  3 },
#elif (I2C1_SDA_PIN_SEL == 2)
         /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  2,  4 },
#else
         /*  1 */  { 0 },
#endif
   };
};

/**
 * Peripheral information for Abstraction for Low Power Timer
 */
class Lptmr0Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = LPTMR0_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC6_LPTMR_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC6);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

};

/**
 * Peripheral information for LLWU, Low-leakage Wake-up Unit
 */
class LlwuInfo {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = LLWU_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (LLWU_P0_PIN_SEL == 1)
         /*  0 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  6,  2 },
#else
         /*  0 */  { 0 },
#endif
#if (LLWU_P1_PIN_SEL == 1)
         /*  1 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  2,  3 },
#else
         /*  1 */  { 0 },
#endif
#if (LLWU_P2_PIN_SEL == 1)
         /*  2 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  1,  2 },
#else
         /*  2 */  { 0 },
#endif
#if (LLWU_P3_PIN_SEL == 1)
         /*  3 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  6,  4 },
#else
         /*  3 */  { 0 },
#endif
#if (LLWU_P4_PIN_SEL == 1)
         /*  4 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  0,  5 },
#else
         /*  4 */  { 0 },
#endif
#if (LLWU_P5_PIN_SEL == 1)
         /*  5 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  6,  4 },
#else
         /*  5 */  { 0 },
#endif
#if (LLWU_P6_PIN_SEL == 1)
         /*  6 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  5,  5 },
#else
         /*  6 */  { 0 },
#endif
#if (LLWU_P7_PIN_SEL == 1)
         /*  7 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  7,  5 },
#else
         /*  7 */  { 0 },
#endif
#if (LLWU_P8_PIN_SEL == 1)
         /*  8 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  6,  5 },
#else
         /*  8 */  { 0 },
#endif
#if (LLWU_P9_PIN_SEL == 1)
         /*  9 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  4,  4 },
#else
         /*  9 */  { 0 },
#endif
#if (LLWU_P10_PIN_SEL == 1)
         /* 10 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  2,  5 },
#else
         /* 10 */  { 0 },
#endif
#if (LLWU_P11_PIN_SEL == 1)
         /* 11 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  0,  4 },
#else
         /* 11 */  { 0 },
#endif
#if (LLWU_P12_PIN_SEL == 1)
         /* 12 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  5,  3 },
#else
         /* 12 */  { 0 },
#endif
#if (LLWU_P13_PIN_SEL == 1)
         /* 13 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  3,  3 },
#else
         /* 13 */  { 0 },
#endif
#if (LLWU_P14_PIN_SEL == 1)
         /* 14 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  6,  3 },
#else
         /* 14 */  { 0 },
#endif
#if (LLWU_P15_PIN_SEL == 1)
         /* 15 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  4,  2 },
#else
         /* 15 */  { 0 },
#endif
   };
};

/**
 * Peripheral information for SPI, Serial Peripheral Interface
 */
class Spi0Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = SPI0_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC4_SPI0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC4);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (SPI0_SCK_PIN_SEL == 1)
         /*  0 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  3,  2 },
#elif (SPI0_SCK_PIN_SEL == 2)
         /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  2,  3 },
#else
         /*  0 */  { 0 },
#endif
#if (SPI0_MISO_PIN_SEL == 1)
         /*  1 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  5,  2 },
#elif (SPI0_MISO_PIN_SEL == 2)
         /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  4,  3 },
#else
         /*  1 */  { 0 },
#endif
#if (SPI0_MOSI_PIN_SEL == 1)
         /*  2 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  4,  2 },
#elif (SPI0_MOSI_PIN_SEL == 2)
         /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  3,  3 },
#else
         /*  2 */  { 0 },
#endif
   };
};

using Spi0_PCS0 = USBDM::PcrTable_T<USBDM::Spi0Info, 3>;
using Spi0_PCS1 = USBDM::PcrTable_T<USBDM::Spi0Info, 4>;
using Spi0_PCS2 = USBDM::PcrTable_T<USBDM::Spi0Info, 5>;
using Spi0_PCS3 = USBDM::PcrTable_T<USBDM::Spi0Info, 6>;
using Spi0_PCS4 = USBDM::PcrTable_T<USBDM::Spi0Info, 7>;
using Spi0_PCS5 = USBDM::PcrTable_T<USBDM::Spi0Info, 8>;
/**
 * Peripheral information for SPI, Serial Peripheral Interface
 */
class Spi1Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = SPI1_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC4_SPI1_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC4);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (SPI1_SCK_PIN_SEL == 1)
         /*  0 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  4,  2 },
#elif (SPI1_SCK_PIN_SEL == 2)
         /*  0 */  { PORTH_CLOCK_MASK, PORTH_BasePtr,  GPIOH_BasePtr,  7,  3 },
#else
         /*  0 */  { 0 },
#endif
#if (SPI1_MISO_PIN_SEL == 1)
         /*  1 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  5,  2 },
#elif (SPI1_MISO_PIN_SEL == 2)
         /*  1 */  { PORTI_CLOCK_MASK, PORTI_BasePtr,  GPIOI_BasePtr,  0,  4 },
#elif (SPI1_MISO_PIN_SEL == 3)
         /*  1 */  { PORTI_CLOCK_MASK, PORTI_BasePtr,  GPIOI_BasePtr,  1,  5 },
#else
         /*  1 */  { 0 },
#endif
#if (SPI1_MOSI_PIN_SEL == 1)
         /*  2 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  6,  2 },
#elif (SPI1_MOSI_PIN_SEL == 2)
         /*  2 */  { PORTI_CLOCK_MASK, PORTI_BasePtr,  GPIOI_BasePtr,  1,  4 },
#elif (SPI1_MOSI_PIN_SEL == 3)
         /*  2 */  { PORTI_CLOCK_MASK, PORTI_BasePtr,  GPIOI_BasePtr,  0,  5 },
#else
         /*  2 */  { 0 },
#endif
   };
};

using Spi1_PCS0 = USBDM::PcrTable_T<USBDM::Spi1Info, 3>;
using Spi1_PCS1 = USBDM::PcrTable_T<USBDM::Spi1Info, 4>;
using Spi1_PCS2 = USBDM::PcrTable_T<USBDM::Spi1Info, 5>;
using Spi1_PCS3 = USBDM::PcrTable_T<USBDM::Spi1Info, 6>;
using Spi1_PCS4 = USBDM::PcrTable_T<USBDM::Spi1Info, 7>;
using Spi1_PCS5 = USBDM::PcrTable_T<USBDM::Spi1Info, 8>;
/**
 * Peripheral information for UART, Universal Asynchonous Receiver/Transmitter
 */
class Uart0Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = UART0_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC4_UART0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC4);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

};

/**
 * Peripheral information for UART, Universal Asynchonous Receiver/Transmitter
 */
class Uart1Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = UART1_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC4_UART1_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC4);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

};

/**
 * Peripheral information for UART, Universal Asynchonous Receiver/Transmitter
 */
class Uart2Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = UART2_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC4_UART2_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC4);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

};

/**
 * Peripheral information for UART, Universal Asynchonous Receiver/Transmitter
 */
class Uart3Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = UART3_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC4_UART3_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC4);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

};

/**
 * Peripheral information for VREF Voltage Reference
 */
class VrefInfo {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = VREF_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC4_VREF_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC4);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

};

/**
 * @}
 ** PeripheralPinTables
 */

} // End namespace USBDM

#include "gpio_defs.h"

namespace USBDM {

/**
 * @addtogroup DigitalIO_Group Digital Input/Output
 * @brief Allows use of port pins as simple digital inputs or outputs
 * @{
 */
/**
 * @brief Convenience template for GpioA. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 3 of GpioA
 * GpioA<3> GpioA3
 *
 * // Set as digital output
 * GpioA3.setOutput();
 *
 * // Set pin high
 * GpioA3.set();
 *
 * // Set pin low
 * GpioA3.clear();
 *
 * // Toggle pin
 * GpioA3.toggle();
 *
 * // Set pin to boolean value
 * GpioA3.write(true);
 *
 * // Set pin to boolean value
 * GpioA3.write(false);
 *
 * // Set as digital input
 * GpioA3.setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioA3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<uint8_t bitNum> using GpioA = Gpio_T<GpioAInfo, bitNum>;

/**
 * @brief Convenience template for GpioA fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of GpioA
 * GpioAField<6,3> GpioA6_3
 *
 * // Set as digital output
 * GpioA6_3.setOutput();
 *
 * // Write value to field
 * GpioA6_3.write(0x53);
 *
 * // Clear all of field
 * GpioA6_3.bitClear();
 *
 * // Clear lower two bits of field
 * GpioA6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioA6_3.bitSet(0x3);
 *
 * // Set as digital input
 * GpioA6_3.setInput();
 *
 * // Read pin as int value
 * int x = GpioA6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioAField = Field_T<GpioAInfo, left, right>;

using gpio_p1              = const USBDM::GpioA<0>;
using gpio_p2              = const USBDM::GpioA<1>;
using gpio_p3              = const USBDM::GpioA<2>;
using gpio_p4              = const USBDM::GpioA<3>;
using gpio_p5              = const USBDM::GpioA<4>;
using gpio_p6              = const USBDM::GpioA<5>;
using gpio_p7              = const USBDM::GpioA<6>;
using gpio_p8              = const USBDM::GpioA<7>;
/**
 * @}
 */
/**
 * @addtogroup DigitalIO_Group Digital Input/Output
 * @brief Allows use of port pins as simple digital inputs or outputs
 * @{
 */
/**
 * @brief Convenience template for GpioB. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 3 of GpioB
 * GpioB<3> GpioB3
 *
 * // Set as digital output
 * GpioB3.setOutput();
 *
 * // Set pin high
 * GpioB3.set();
 *
 * // Set pin low
 * GpioB3.clear();
 *
 * // Toggle pin
 * GpioB3.toggle();
 *
 * // Set pin to boolean value
 * GpioB3.write(true);
 *
 * // Set pin to boolean value
 * GpioB3.write(false);
 *
 * // Set as digital input
 * GpioB3.setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioB3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<uint8_t bitNum> using GpioB = Gpio_T<GpioBInfo, bitNum>;

/**
 * @brief Convenience template for GpioB fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of GpioB
 * GpioBField<6,3> GpioB6_3
 *
 * // Set as digital output
 * GpioB6_3.setOutput();
 *
 * // Write value to field
 * GpioB6_3.write(0x53);
 *
 * // Clear all of field
 * GpioB6_3.bitClear();
 *
 * // Clear lower two bits of field
 * GpioB6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioB6_3.bitSet(0x3);
 *
 * // Set as digital input
 * GpioB6_3.setInput();
 *
 * // Read pin as int value
 * int x = GpioB6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioBField = Field_T<GpioBInfo, left, right>;

using gpio_p9              = const USBDM::GpioB<0>;
using gpio_p12             = const USBDM::GpioB<1>;
using gpio_p13             = const USBDM::GpioB<2>;
using gpio_p14             = const USBDM::GpioB<3>;
using gpio_p15             = const USBDM::GpioB<4>;
using gpio_p16             = const USBDM::GpioB<5>;
using gpio_p17             = const USBDM::GpioB<6>;
using gpio_p18             = const USBDM::GpioB<7>;
/**
 * @}
 */
/**
 * @addtogroup DigitalIO_Group Digital Input/Output
 * @brief Allows use of port pins as simple digital inputs or outputs
 * @{
 */
/**
 * @brief Convenience template for GpioC. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 3 of GpioC
 * GpioC<3> GpioC3
 *
 * // Set as digital output
 * GpioC3.setOutput();
 *
 * // Set pin high
 * GpioC3.set();
 *
 * // Set pin low
 * GpioC3.clear();
 *
 * // Toggle pin
 * GpioC3.toggle();
 *
 * // Set pin to boolean value
 * GpioC3.write(true);
 *
 * // Set pin to boolean value
 * GpioC3.write(false);
 *
 * // Set as digital input
 * GpioC3.setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioC3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<uint8_t bitNum> using GpioC = Gpio_T<GpioCInfo, bitNum>;

/**
 * @brief Convenience template for GpioC fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of GpioC
 * GpioCField<6,3> GpioC6_3
 *
 * // Set as digital output
 * GpioC6_3.setOutput();
 *
 * // Write value to field
 * GpioC6_3.write(0x53);
 *
 * // Clear all of field
 * GpioC6_3.bitClear();
 *
 * // Clear lower two bits of field
 * GpioC6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioC6_3.bitSet(0x3);
 *
 * // Set as digital input
 * GpioC6_3.setInput();
 *
 * // Read pin as int value
 * int x = GpioC6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioCField = Field_T<GpioCInfo, left, right>;

using gpio_p19             = const USBDM::GpioC<0>;
using gpio_p20             = const USBDM::GpioC<1>;
using gpio_p21             = const USBDM::GpioC<2>;
using gpio_p22             = const USBDM::GpioC<3>;
using gpio_p23             = const USBDM::GpioC<4>;
using gpio_p44             = const USBDM::GpioC<5>;
using gpio_p45             = const USBDM::GpioC<6>;
using gpio_p46             = const USBDM::GpioC<7>;
/**
 * @}
 */
/**
 * @addtogroup DigitalIO_Group Digital Input/Output
 * @brief Allows use of port pins as simple digital inputs or outputs
 * @{
 */
/**
 * @brief Convenience template for GpioD. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 3 of GpioD
 * GpioD<3> GpioD3
 *
 * // Set as digital output
 * GpioD3.setOutput();
 *
 * // Set pin high
 * GpioD3.set();
 *
 * // Set pin low
 * GpioD3.clear();
 *
 * // Toggle pin
 * GpioD3.toggle();
 *
 * // Set pin to boolean value
 * GpioD3.write(true);
 *
 * // Set pin to boolean value
 * GpioD3.write(false);
 *
 * // Set as digital input
 * GpioD3.setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioD3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<uint8_t bitNum> using GpioD = Gpio_T<GpioDInfo, bitNum>;

/**
 * @brief Convenience template for GpioD fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of GpioD
 * GpioDField<6,3> GpioD6_3
 *
 * // Set as digital output
 * GpioD6_3.setOutput();
 *
 * // Write value to field
 * GpioD6_3.write(0x53);
 *
 * // Clear all of field
 * GpioD6_3.bitClear();
 *
 * // Clear lower two bits of field
 * GpioD6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioD6_3.bitSet(0x3);
 *
 * // Set as digital input
 * GpioD6_3.setInput();
 *
 * // Read pin as int value
 * int x = GpioD6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioDField = Field_T<GpioDInfo, left, right>;

using gpio_p47             = const USBDM::GpioD<0>;
using gpio_p48             = const USBDM::GpioD<1>;
using gpio_p49             = const USBDM::GpioD<2>;
using gpio_p50             = const USBDM::GpioD<3>;
using gpio_p51             = const USBDM::GpioD<4>;
using gpio_p52             = const USBDM::GpioD<5>;
using gpio_p53             = const USBDM::GpioD<6>;
using gpio_p54             = const USBDM::GpioD<7>;
/**
 * @}
 */
/**
 * @addtogroup DigitalIO_Group Digital Input/Output
 * @brief Allows use of port pins as simple digital inputs or outputs
 * @{
 */
/**
 * @brief Convenience template for GpioE. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 3 of GpioE
 * GpioE<3> GpioE3
 *
 * // Set as digital output
 * GpioE3.setOutput();
 *
 * // Set pin high
 * GpioE3.set();
 *
 * // Set pin low
 * GpioE3.clear();
 *
 * // Toggle pin
 * GpioE3.toggle();
 *
 * // Set pin to boolean value
 * GpioE3.write(true);
 *
 * // Set pin to boolean value
 * GpioE3.write(false);
 *
 * // Set as digital input
 * GpioE3.setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioE3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<uint8_t bitNum> using GpioE = Gpio_T<GpioEInfo, bitNum>;

/**
 * @brief Convenience template for GpioE fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of GpioE
 * GpioEField<6,3> GpioE6_3
 *
 * // Set as digital output
 * GpioE6_3.setOutput();
 *
 * // Write value to field
 * GpioE6_3.write(0x53);
 *
 * // Clear all of field
 * GpioE6_3.bitClear();
 *
 * // Clear lower two bits of field
 * GpioE6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioE6_3.bitSet(0x3);
 *
 * // Set as digital input
 * GpioE6_3.setInput();
 *
 * // Read pin as int value
 * int x = GpioE6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioEField = Field_T<GpioEInfo, left, right>;

using gpio_p55             = const USBDM::GpioE<0>;
using gpio_p56             = const USBDM::GpioE<1>;
using gpio_p57             = const USBDM::GpioE<2>;
using gpio_p58             = const USBDM::GpioE<3>;
using gpio_p63             = const USBDM::GpioE<4>;
using gpio_p64             = const USBDM::GpioE<5>;
using gpio_p65             = const USBDM::GpioE<6>;
using gpio_p66             = const USBDM::GpioE<7>;
/**
 * @}
 */
/**
 * @addtogroup DigitalIO_Group Digital Input/Output
 * @brief Allows use of port pins as simple digital inputs or outputs
 * @{
 */
/**
 * @brief Convenience template for GpioF. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 3 of GpioF
 * GpioF<3> GpioF3
 *
 * // Set as digital output
 * GpioF3.setOutput();
 *
 * // Set pin high
 * GpioF3.set();
 *
 * // Set pin low
 * GpioF3.clear();
 *
 * // Toggle pin
 * GpioF3.toggle();
 *
 * // Set pin to boolean value
 * GpioF3.write(true);
 *
 * // Set pin to boolean value
 * GpioF3.write(false);
 *
 * // Set as digital input
 * GpioF3.setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioF3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<uint8_t bitNum> using GpioF = Gpio_T<GpioFInfo, bitNum>;

/**
 * @brief Convenience template for GpioF fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of GpioF
 * GpioFField<6,3> GpioF6_3
 *
 * // Set as digital output
 * GpioF6_3.setOutput();
 *
 * // Write value to field
 * GpioF6_3.write(0x53);
 *
 * // Clear all of field
 * GpioF6_3.bitClear();
 *
 * // Clear lower two bits of field
 * GpioF6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioF6_3.bitSet(0x3);
 *
 * // Set as digital input
 * GpioF6_3.setInput();
 *
 * // Read pin as int value
 * int x = GpioF6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioFField = Field_T<GpioFInfo, left, right>;

using gpio_p67             = const USBDM::GpioF<0>;
using gpio_p68             = const USBDM::GpioF<1>;
using gpio_p69             = const USBDM::GpioF<2>;
using gpio_p70             = const USBDM::GpioF<3>;
using gpio_p71             = const USBDM::GpioF<4>;
using gpio_p72             = const USBDM::GpioF<5>;
using gpio_p73             = const USBDM::GpioF<6>;
using gpio_p74             = const USBDM::GpioF<7>;
/**
 * @}
 */
/**
 * @addtogroup DigitalIO_Group Digital Input/Output
 * @brief Allows use of port pins as simple digital inputs or outputs
 * @{
 */
/**
 * @brief Convenience template for GpioG. See @ref Gpio_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 3 of GpioG
 * GpioG<3> GpioG3
 *
 * // Set as digital output
 * GpioG3.setOutput();
 *
 * // Set pin high
 * GpioG3.set();
 *
 * // Set pin low
 * GpioG3.clear();
 *
 * // Toggle pin
 * GpioG3.toggle();
 *
 * // Set pin to boolean value
 * GpioG3.write(true);
 *
 * // Set pin to boolean value
 * GpioG3.write(false);
 *
 * // Set as digital input
 * GpioG3.setInput();
 *
 * // Read pin as boolean value
 * bool x = GpioG3.read();
 * @endcode
 *
 * @tparam bitNum        Bit number in the port
 */
template<uint8_t bitNum> using GpioG = Gpio_T<GpioGInfo, bitNum>;

/**
 * @brief Convenience template for GpioG fields. See @ref Field_T
 *
 * <b>Usage</b>
 * @code
 * // Instantiate for bit 6 down to 3 of GpioG
 * GpioGField<6,3> GpioG6_3
 *
 * // Set as digital output
 * GpioG6_3.setOutput();
 *
 * // Write value to field
 * GpioG6_3.write(0x53);
 *
 * // Clear all of field
 * GpioG6_3.bitClear();
 *
 * // Clear lower two bits of field
 * GpioG6_3.bitClear(0x3);
 *
 * // Set lower two bits of field
 * GpioG6_3.bitSet(0x3);
 *
 * // Set as digital input
 * GpioG6_3.setInput();
 *
 * // Read pin as int value
 * int x = GpioG6_3.read();
 * @endcode
 *
 * @tparam left          Bit number of leftmost bit in port (inclusive)
 * @tparam right         Bit number of rightmost bit in port (inclusive)
 */
template<int left, int right> using GpioGField = Field_T<GpioGInfo, left, right>;

using gpio_p75             = const USBDM::GpioG<0>;
using gpio_p76             = const USBDM::GpioG<1>;
using gpio_p77             = const USBDM::GpioG<2>;
using gpio_p78             = const USBDM::GpioG<3>;
using gpio_p79             = const USBDM::GpioG<4>;
using gpio_p80             = const USBDM::GpioG<5>;
using gpio_p81             = const USBDM::GpioG<6>;
using gpio_p82             = const USBDM::GpioG<7>;
/**
 * @}
 */
/**
 * @addtogroup AnalogueIO_Group Analogue Input
 * @brief Allows use of port pins as analogue inputs
 * @{
 */
/**
 * Convenience templated class representing an ADC
 *
 * Example
 * @code
 *  // Instantiate ADC0 single-ended channel #8
 *  const adc0<8> adc0_se8;
 *
 *  // Initialise ADC
 *  adc0_se8.initialiseADC(USBDM::resolution_12bit_se);
 *
 *  // Set as analogue input
 *  adc0_se8.setAnalogueInput();
 *
 *  // Read input
 *  uint16_t value = adc0_se8.readAnalogue();
 *  @endcode
 *
 * @tparam adcChannel    ADC channel
 */
template<uint8_t channel> using Adc0 = Adc_T<Adc0Info, channel>;

#if (PTC5_SIG_SEL == 0)
using adc_p44              = const USBDM::Adc0<0>;
#endif
#if (PTC6_SIG_SEL == 0)
using adc_p45              = const USBDM::Adc0<1>;
#endif
#if (PTC7_SIG_SEL == 0)
using adc_p46              = const USBDM::Adc0<2>;
#endif
#if (PTD4_SIG_SEL == 0)
using adc_p51              = const USBDM::Adc0<3>;
#endif
#if (PTD5_SIG_SEL == 0)
using adc_p52              = const USBDM::Adc0<4>;
#endif
#if (PTD6_SIG_SEL == 0)
using adc_p53              = const USBDM::Adc0<5>;
#endif
#if (PTE7_SIG_SEL == 0)
using adc_p66              = const USBDM::Adc0<6>;
#endif
#if (PTF0_SIG_SEL == 0)
using adc_p67              = const USBDM::Adc0<7>;
#endif
#if (PTF1_SIG_SEL == 0)
using adc_p68              = const USBDM::Adc0<8>;
#endif
#if (PTF2_SIG_SEL == 0)
using adc_p69              = const USBDM::Adc0<9>;
#endif
#if (PTG1_SIG_SEL == 0)
using adc_p76              = const USBDM::Adc0<10>;
#endif
#if (PTG2_SIG_SEL == 0)
using adc_p77              = const USBDM::Adc0<11>;
#endif
/**
 * @}
 */
#if (DO_MAP_PINS_ON_RESET>0)
/**
 * Used to configure pin-mapping before 1st use of peripherals
 */
extern void usbdm_PinMapping();
#endif

} // End namespace USBDM

#endif /* PIN_MAPPING_H_ */
