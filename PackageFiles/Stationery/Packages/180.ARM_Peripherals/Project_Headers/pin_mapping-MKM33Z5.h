/**
 * @file      pin_mapping.h (derived from pin_mapping-MKM33Z5.h)
 * @version   1.1.0
 * @brief     Pin declarations for MKM33Z5
 */

#ifndef PIN_MAPPING_H_
#define PIN_MAPPING_H_

#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

//================================
// Validators
// <validate=net.sourceforge.usbdm.annotationEditor.validators.PinMappingValidator>

// Inline port functions
//
//   <q> Force inline port functions 
//   <i> Forces some small GPIO functions to be inlined
//   <i> This increases speed but may also increase code size
//     <0=> Disabled
//     <1=> Enabled
#define DO_INLINE_GPIO       0

// Pin mapping Options
//
//   <q> Map pins 
//   <i> Selects whether pin mappings are done when individual
//   <i> peripherals are configured or during reset initialisation.
//   <i> This will also cause unselected peripherals to be unavailable.
//     <0=> Pins mapped on demand
//     <1=> Pin mapping on reset  - unselected peripherals unavailable
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
//   <o> EXTAL32K [EXTAL32K]<name=EXTAL32K_SIG_SEL><constant>
//   <i> EXTAL32K has no pin-mapping hardware
//     <-3=> EXTAL32K (fixed)<selection=EXTAL32K_PIN_SEL,EXTAL32K>
#define EXTAL32K_SIG_SEL     -3

// Signal mapping for SDADM0 pin
//   <o> SDADM0 [SDADM0]<name=SDADM0_SIG_SEL><constant>
//   <i> SDADM0 has no pin-mapping hardware
//     <-3=> SDADM0 (fixed)<selection=SDADM0_PIN_SEL,SDADM0>
#define SDADM0_SIG_SEL       -3

// Signal mapping for SDADM1 pin
//   <o> SDADM1 [SDADM1]<name=SDADM1_SIG_SEL><constant>
//   <i> SDADM1 has no pin-mapping hardware
//     <-3=> SDADM1 (fixed)<selection=SDADM1_PIN_SEL,SDADM1>
#define SDADM1_SIG_SEL       -3

// Signal mapping for SDADM2 pin
//   <o> SDADM2 [SDADM2/CMP1P3]<name=SDADM2_SIG_SEL><constant>
//   <i> SDADM2 has no pin-mapping hardware
//     <-3=> SDADM2/CMP1P3 (fixed)<selection=SDADM2_PIN_SEL,SDADM2><selection=CMP1P3_PIN_SEL,SDADM2>
#define SDADM2_SIG_SEL       -3

// Signal mapping for SDADM3 pin
//   <o> SDADM3 [SDADM3/CMP1P5]<name=SDADM3_SIG_SEL><constant>
//   <i> SDADM3 has no pin-mapping hardware
//     <-3=> SDADM3/CMP1P5 (fixed)<selection=SDADM3_PIN_SEL,SDADM3><selection=CMP1P5_PIN_SEL,SDADM3>
#define SDADM3_SIG_SEL       -3

// Signal mapping for SDADP0 pin
//   <o> SDADP0 [SDADP0]<name=SDADP0_SIG_SEL><constant>
//   <i> SDADP0 has no pin-mapping hardware
//     <-3=> SDADP0 (fixed)<selection=SDADP0_PIN_SEL,SDADP0>
#define SDADP0_SIG_SEL       -3

// Signal mapping for SDADP1 pin
//   <o> SDADP1 [SDADP1]<name=SDADP1_SIG_SEL><constant>
//   <i> SDADP1 has no pin-mapping hardware
//     <-3=> SDADP1 (fixed)<selection=SDADP1_PIN_SEL,SDADP1>
#define SDADP1_SIG_SEL       -3

// Signal mapping for SDADP2 pin
//   <o> SDADP2 [SDADP2/CMP1P2]<name=SDADP2_SIG_SEL><constant>
//   <i> SDADP2 has no pin-mapping hardware
//     <-3=> SDADP2/CMP1P2 (fixed)<selection=SDADP2_PIN_SEL,SDADP2><selection=CMP1P2_PIN_SEL,SDADP2>
#define SDADP2_SIG_SEL       -3

// Signal mapping for SDADP3 pin
//   <o> SDADP3 [SDADP3/CMP1P4]<name=SDADP3_SIG_SEL><constant>
//   <i> SDADP3 has no pin-mapping hardware
//     <-3=> SDADP3/CMP1P4 (fixed)<selection=SDADP3_PIN_SEL,SDADP3><selection=CMP1P4_PIN_SEL,SDADP3>
#define SDADP3_SIG_SEL       -3

// Signal mapping for XTAL32K pin
//   <o> XTAL32K [XTAL32K]<name=XTAL32K_SIG_SEL><constant>
//   <i> XTAL32K has no pin-mapping hardware
//     <-3=> XTAL32K (fixed)<selection=XTAL32K_PIN_SEL,XTAL32K>
#define XTAL32K_SIG_SEL      -3

// </h>

// <h> Port A Pins

// Signal mapping for PTA0 pin
//   <o> PTA0 (Alias:LED_RED) [LCD23, GPIOA_0]<name=PTA0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA0 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD23<selection=LCD23_PIN_SEL,PTA0 (Alias:LED_RED)>
//     <1=> GPIOA_0<selection=GPIOA_0_PIN_SEL,PTA0 (Alias:LED_RED)>
//     <1=> Default
#define PTA0_SIG_SEL         1

// Signal mapping for PTA1 pin
//   <o> PTA1 (Alias:LED_GREEN) [LCD24, GPIOA_1]<name=PTA1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA1 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD24<selection=LCD24_PIN_SEL,PTA1 (Alias:LED_GREEN)>
//     <1=> GPIOA_1<selection=GPIOA_1_PIN_SEL,PTA1 (Alias:LED_GREEN)>
//     <1=> Default
#define PTA1_SIG_SEL         1

// Signal mapping for PTA2 pin
//   <o> PTA2 [LCD25, GPIOA_2]<name=PTA2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA2 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD25<selection=LCD25_PIN_SEL,PTA2>
//     <1=> GPIOA_2<selection=GPIOA_2_PIN_SEL,PTA2>
//     <-2=> Default
#define PTA2_SIG_SEL         -2

// Signal mapping for PTA3 pin
//   <o> PTA3 [LCD26, GPIOA_3]<name=PTA3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA3 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD26<selection=LCD26_PIN_SEL,PTA3>
//     <1=> GPIOA_3<selection=GPIOA_3_PIN_SEL,PTA3>
//     <-2=> Default
#define PTA3_SIG_SEL         -2

// Signal mapping for PTA4 pin
//   <o> PTA4 [LCD27, GPIOA_4, LLWU_P15, NMI_B]<name=PTA4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA4 pin
//     <-2=> NMI_B (reset default)<selection=NMI_B_PIN_SEL,PTA4 (reset default)>
//     <0=> LCD27<selection=LCD27_PIN_SEL,PTA4>
//     <1=> GPIOA_4<selection=GPIOA_4_PIN_SEL,PTA4>
//     <2=> LLWU_P15<selection=LLWU_P15_PIN_SEL,PTA4>
//     <7=> NMI_B<selection=NMI_B_PIN_SEL,PTA4>
//     <-2=> Default
#define PTA4_SIG_SEL         -2

// Signal mapping for PTA5 pin
//   <o> PTA5 [LCD28, GPIOA_5, CMP0OUT]<name=PTA5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA5 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD28<selection=LCD28_PIN_SEL,PTA5>
//     <1=> GPIOA_5<selection=GPIOA_5_PIN_SEL,PTA5>
//     <2=> CMP0OUT<selection=CMP0OUT_PIN_SEL,PTA5>
//     <-2=> Default
#define PTA5_SIG_SEL         -2

// Signal mapping for PTA6 pin
//   <o> PTA6 [LCD29, GPIOA_6, PXBAR_IN0, LLWU_P14]<name=PTA6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA6 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD29<selection=LCD29_PIN_SEL,PTA6>
//     <1=> GPIOA_6<selection=GPIOA_6_PIN_SEL,PTA6>
//     <2=> PXBAR_IN0<selection=PXBAR_IN0_PIN_SEL,PTA6>
//     <3=> LLWU_P14<selection=LLWU_P14_PIN_SEL,PTA6>
//     <-2=> Default
#define PTA6_SIG_SEL         -2

// Signal mapping for PTA7 pin
//   <o> PTA7 [LCD30, GPIOA_7, PXBAR_OUT0]<name=PTA7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA7 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD30<selection=LCD30_PIN_SEL,PTA7>
//     <1=> GPIOA_7<selection=GPIOA_7_PIN_SEL,PTA7>
//     <2=> PXBAR_OUT0<selection=PXBAR_OUT0_PIN_SEL,PTA7>
//     <-2=> Default
#define PTA7_SIG_SEL         -2

// </h>

// <h> Port B Pins

// Signal mapping for PTB0 pin
//   <o> PTB0 [LCD31, GPIOB_0]<name=PTB0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB0 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD31<selection=LCD31_PIN_SEL,PTB0>
//     <1=> GPIOB_0<selection=GPIOB_0_PIN_SEL,PTB0>
//     <-2=> Default
#define PTB0_SIG_SEL         -2

// Signal mapping for PTB1 pin
//   <o> PTB1 [LCD32, GPIOB_1]<name=PTB1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB1 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD32<selection=LCD32_PIN_SEL,PTB1>
//     <1=> GPIOB_1<selection=GPIOB_1_PIN_SEL,PTB1>
//     <-2=> Default
#define PTB1_SIG_SEL         -2

// Signal mapping for PTB2 pin
//   <o> PTB2 [LCD33, GPIOB_2]<name=PTB2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB2 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD33<selection=LCD33_PIN_SEL,PTB2>
//     <1=> GPIOB_2<selection=GPIOB_2_PIN_SEL,PTB2>
//     <-2=> Default
#define PTB2_SIG_SEL         -2

// Signal mapping for PTB3 pin
//   <o> PTB3 [LCD34, GPIOB_3]<name=PTB3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB3 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD34<selection=LCD34_PIN_SEL,PTB3>
//     <1=> GPIOB_3<selection=GPIOB_3_PIN_SEL,PTB3>
//     <-2=> Default
#define PTB3_SIG_SEL         -2

// Signal mapping for PTB4 pin
//   <o> PTB4 [LCD35, GPIOB_4]<name=PTB4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB4 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD35<selection=LCD35_PIN_SEL,PTB4>
//     <1=> GPIOB_4<selection=GPIOB_4_PIN_SEL,PTB4>
//     <-2=> Default
#define PTB4_SIG_SEL         -2

// Signal mapping for PTB5 pin
//   <o> PTB5 [LCD36, GPIOB_5]<name=PTB5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB5 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD36<selection=LCD36_PIN_SEL,PTB5>
//     <1=> GPIOB_5<selection=GPIOB_5_PIN_SEL,PTB5>
//     <-2=> Default
#define PTB5_SIG_SEL         -2

// Signal mapping for PTB6 pin
//   <o> PTB6 [LCD37/CMP1P0, GPIOB_6]<name=PTB6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB6 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD37/CMP1P0<selection=LCD37_PIN_SEL,PTB6><selection=CMP1P0_PIN_SEL,PTB6>
//     <1=> GPIOB_6<selection=GPIOB_6_PIN_SEL,PTB6>
//     <-2=> Default
#define PTB6_SIG_SEL         -2

// Signal mapping for PTB7 pin
//   <o> PTB7 [LCD38, GPIOB_7, AFE_CLK]<name=PTB7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB7 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD38<selection=LCD38_PIN_SEL,PTB7>
//     <1=> GPIOB_7<selection=GPIOB_7_PIN_SEL,PTB7>
//     <2=> AFE_CLK<selection=AFE_CLK_PIN_SEL,PTB7>
//     <-2=> Default
#define PTB7_SIG_SEL         -2

// </h>

// <h> Port C Pins

// Signal mapping for PTC0 pin
//   <o> PTC0 [LCD39, GPIOC_0, SCI3_RTS, PXBAR_IN1]<name=PTC0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC0 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD39<selection=LCD39_PIN_SEL,PTC0>
//     <1=> GPIOC_0<selection=GPIOC_0_PIN_SEL,PTC0>
//     <2=> SCI3_RTS<selection=SCI3_RTS_PIN_SEL,PTC0>
//     <3=> PXBAR_IN1<selection=PXBAR_IN1_PIN_SEL,PTC0>
//     <-2=> Default
#define PTC0_SIG_SEL         -2

// Signal mapping for PTC1 pin
//   <o> PTC1 [LCD40/CMP1P1, GPIOC_1, SCI3_CTS]<name=PTC1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC1 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD40/CMP1P1<selection=LCD40_PIN_SEL,PTC1><selection=CMP1P1_PIN_SEL,PTC1>
//     <1=> GPIOC_1<selection=GPIOC_1_PIN_SEL,PTC1>
//     <2=> SCI3_CTS<selection=SCI3_CTS_PIN_SEL,PTC1>
//     <-2=> Default
#define PTC1_SIG_SEL         -2

// Signal mapping for PTC2 pin
//   <o> PTC2 [LCD41, GPIOC_2, SCI3_TxD, PXBAR_OUT1]<name=PTC2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC2 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD41<selection=LCD41_PIN_SEL,PTC2>
//     <1=> GPIOC_2<selection=GPIOC_2_PIN_SEL,PTC2>
//     <2=> SCI3_TxD<selection=SCI3_TxD_PIN_SEL,PTC2>
//     <3=> PXBAR_OUT1<selection=PXBAR_OUT1_PIN_SEL,PTC2>
//     <-2=> Default
#define PTC2_SIG_SEL         -2

// Signal mapping for PTC3 pin
//   <o> PTC3 [LCD42/CMP0P3, GPIOC_3, SCI3_RxD, LLWU_P13]<name=PTC3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC3 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD42/CMP0P3<selection=LCD42_PIN_SEL,PTC3><selection=CMP0P3_PIN_SEL,PTC3>
//     <1=> GPIOC_3<selection=GPIOC_3_PIN_SEL,PTC3>
//     <2=> SCI3_RxD<selection=SCI3_RxD_PIN_SEL,PTC3>
//     <3=> LLWU_P13<selection=LLWU_P13_PIN_SEL,PTC3>
//     <-2=> Default
#define PTC3_SIG_SEL         -2

// Signal mapping for PTC4 pin
//   <o> PTC4 [LCD43, GPIOC_4]<name=PTC4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC4 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD43<selection=LCD43_PIN_SEL,PTC4>
//     <1=> GPIOC_4<selection=GPIOC_4_PIN_SEL,PTC4>
//     <-2=> Default
#define PTC4_SIG_SEL         -2

// Signal mapping for PTC5 pin
//   <o> PTC5 [ADC0_SE0, GPIOC_5, SCI0_RTS, LLWU_P12]<name=PTC5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC5 pin
//     <-2=> Disabled (reset default)
//     <0=> ADC0_SE0<selection=ADC0_SE0_PIN_SEL,PTC5>
//     <1=> GPIOC_5<selection=GPIOC_5_PIN_SEL,PTC5>
//     <2=> SCI0_RTS<selection=SCI0_RTS_PIN_SEL,PTC5>
//     <3=> LLWU_P12<selection=LLWU_P12_PIN_SEL,PTC5>
//     <-2=> Default
#define PTC5_SIG_SEL         -2

// Signal mapping for PTC6 pin
//   <o> PTC6 [ADC0_SE1, GPIOC_6, SCI0_CTS, QT1]<name=PTC6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC6 pin
//     <-2=> Disabled (reset default)
//     <0=> ADC0_SE1<selection=ADC0_SE1_PIN_SEL,PTC6>
//     <1=> GPIOC_6<selection=GPIOC_6_PIN_SEL,PTC6>
//     <2=> SCI0_CTS<selection=SCI0_CTS_PIN_SEL,PTC6>
//     <3=> QT1<selection=QT1_PIN_SEL,PTC6>
//     <-2=> Default
#define PTC6_SIG_SEL         -2

// Signal mapping for PTC7 pin
//   <o> PTC7 [ADC0_SE2, GPIOC_7, SCI0_TxD, PXBAR_OUT2]<name=PTC7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC7 pin
//     <-2=> Disabled (reset default)
//     <0=> ADC0_SE2<selection=ADC0_SE2_PIN_SEL,PTC7>
//     <1=> GPIOC_7<selection=GPIOC_7_PIN_SEL,PTC7>
//     <2=> SCI0_TxD<selection=SCI0_TxD_PIN_SEL,PTC7>
//     <3=> PXBAR_OUT2<selection=PXBAR_OUT2_PIN_SEL,PTC7>
//     <-2=> Default
#define PTC7_SIG_SEL         -2

// </h>

// <h> Port D Pins

// Signal mapping for PTD0 pin
//   <o> PTD0 [CMP0P0, GPIOD_0, SCI0_RxD, PXBAR_IN2, LLWU_P11]<name=PTD0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD0 pin
//     <-2=> Disabled (reset default)
//     <0=> CMP0P0<selection=CMP0P0_PIN_SEL,PTD0>
//     <1=> GPIOD_0<selection=GPIOD_0_PIN_SEL,PTD0>
//     <2=> SCI0_RxD<selection=SCI0_RxD_PIN_SEL,PTD0>
//     <3=> PXBAR_IN2<selection=PXBAR_IN2_PIN_SEL,PTD0>
//     <4=> LLWU_P11<selection=LLWU_P11_PIN_SEL,PTD0>
//     <-2=> Default
#define PTD0_SIG_SEL         -2

// Signal mapping for PTD1 pin
//   <o> PTD1 (Alias:LED_BLUE) [GPIOD_1, SCI1_TxD, SPI0_SS_B, PXBAR_OUT3, QT3]<name=PTD1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD1 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_1<selection=GPIOD_1_PIN_SEL,PTD1 (Alias:LED_BLUE)>
//     <2=> SCI1_TxD<selection=SCI1_TxD_PIN_SEL,PTD1 (Alias:LED_BLUE)>
//     <3=> SPI0_SS_B<selection=SPI0_SS_B_PIN_SEL,PTD1 (Alias:LED_BLUE)>
//     <4=> PXBAR_OUT3<selection=PXBAR_OUT3_PIN_SEL,PTD1 (Alias:LED_BLUE)>
//     <5=> QT3<selection=QT3_PIN_SEL,PTD1 (Alias:LED_BLUE)>
//     <1=> Default
#define PTD1_SIG_SEL         1

// Signal mapping for PTD2 pin
//   <o> PTD2 [CMP0P1, GPIOD_2, SCI1_RxD, SPI0_SCK, PXBAR_IN3, LLWU_P10]<name=PTD2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD2 pin
//     <-2=> Disabled (reset default)
//     <0=> CMP0P1<selection=CMP0P1_PIN_SEL,PTD2>
//     <1=> GPIOD_2<selection=GPIOD_2_PIN_SEL,PTD2>
//     <2=> SCI1_RxD<selection=SCI1_RxD_PIN_SEL,PTD2>
//     <3=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTD2>
//     <4=> PXBAR_IN3<selection=PXBAR_IN3_PIN_SEL,PTD2>
//     <5=> LLWU_P10<selection=LLWU_P10_PIN_SEL,PTD2>
//     <-2=> Default
#define PTD2_SIG_SEL         -2

// Signal mapping for PTD3 pin
//   <o> PTD3 [GPIOD_3, SCI1_CTS, SPI0_MOSI]<name=PTD3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD3 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_3<selection=GPIOD_3_PIN_SEL,PTD3>
//     <2=> SCI1_CTS<selection=SCI1_CTS_PIN_SEL,PTD3>
//     <3=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTD3>
//     <-2=> Default
#define PTD3_SIG_SEL         -2

// Signal mapping for PTD4 pin
//   <o> PTD4 [ADC0_SE3, GPIOD_4, SCI1_RTS, SPI0_MISO, LLWU_P9]<name=PTD4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD4 pin
//     <-2=> Disabled (reset default)
//     <0=> ADC0_SE3<selection=ADC0_SE3_PIN_SEL,PTD4>
//     <1=> GPIOD_4<selection=GPIOD_4_PIN_SEL,PTD4>
//     <2=> SCI1_RTS<selection=SCI1_RTS_PIN_SEL,PTD4>
//     <3=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTD4>
//     <4=> LLWU_P9<selection=LLWU_P9_PIN_SEL,PTD4>
//     <-2=> Default
#define PTD4_SIG_SEL         -2

// Signal mapping for PTD5 pin
//   <o> PTD5 [ADC0_SE4, GPIOD_5, LPTMR_ALT2, QT0, SCI3_CTS]<name=PTD5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD5 pin
//     <-2=> Disabled (reset default)
//     <0=> ADC0_SE4<selection=ADC0_SE4_PIN_SEL,PTD5>
//     <1=> GPIOD_5<selection=GPIOD_5_PIN_SEL,PTD5>
//     <2=> LPTMR_ALT2<selection=LPTMR_ALT2_PIN_SEL,PTD5>
//     <3=> QT0<selection=QT0_PIN_SEL,PTD5>
//     <4=> SCI3_CTS<selection=SCI3_CTS_PIN_SEL,PTD5>
//     <-2=> Default
#define PTD5_SIG_SEL         -2

// Signal mapping for PTD6 pin
//   <o> PTD6 [ADC0_SE5, GPIOD_6, LPTMR_ALT1, CMP1OUT, SCI3_RTS, LLWU_P8]<name=PTD6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD6 pin
//     <-2=> Disabled (reset default)
//     <0=> ADC0_SE5<selection=ADC0_SE5_PIN_SEL,PTD6>
//     <1=> GPIOD_6<selection=GPIOD_6_PIN_SEL,PTD6>
//     <2=> LPTMR_ALT1<selection=LPTMR_ALT1_PIN_SEL,PTD6>
//     <3=> CMP1OUT<selection=CMP1OUT_PIN_SEL,PTD6>
//     <4=> SCI3_RTS<selection=SCI3_RTS_PIN_SEL,PTD6>
//     <5=> LLWU_P8<selection=LLWU_P8_PIN_SEL,PTD6>
//     <-2=> Default
#define PTD6_SIG_SEL         -2

// Signal mapping for PTD7 pin
//   <o> PTD7 [CMP0P4, GPIOD_7, I2C0_SCL, PXBAR_IN4, SCI3_RxD, LLWU_P7]<name=PTD7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD7 pin
//     <-2=> Disabled (reset default)
//     <0=> CMP0P4<selection=CMP0P4_PIN_SEL,PTD7>
//     <1=> GPIOD_7<selection=GPIOD_7_PIN_SEL,PTD7>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTD7>
//     <3=> PXBAR_IN4<selection=PXBAR_IN4_PIN_SEL,PTD7>
//     <4=> SCI3_RxD<selection=SCI3_RxD_PIN_SEL,PTD7>
//     <5=> LLWU_P7<selection=LLWU_P7_PIN_SEL,PTD7>
//     <-2=> Default
#define PTD7_SIG_SEL         -2

// </h>

// <h> Port E Pins

// Signal mapping for PTE0 pin
//   <o> PTE0 [GPIOE_0, I2C0_SDA, PXBAR_OUT4, SCI3_TxD, CLKOUT]<name=PTE0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE0 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_0<selection=GPIOE_0_PIN_SEL,PTE0>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTE0>
//     <3=> PXBAR_OUT4<selection=PXBAR_OUT4_PIN_SEL,PTE0>
//     <4=> SCI3_TxD<selection=SCI3_TxD_PIN_SEL,PTE0>
//     <5=> CLKOUT<selection=CLKOUT_PIN_SEL,PTE0>
//     <-2=> Default
#define PTE0_SIG_SEL         -2

// Signal mapping for PTE1 pin
//   <o> PTE1 [GPIOE_1, RESET_B]<name=PTE1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE1 pin
//     <-2=> RESET_B (reset default)<selection=RESET_B_PIN_SEL,PTE1 (reset default)>
//     <1=> GPIOE_1<selection=GPIOE_1_PIN_SEL,PTE1>
//     <7=> RESET_B<selection=RESET_B_PIN_SEL,PTE1>
//     <-2=> Default
#define PTE1_SIG_SEL         -2

// Signal mapping for PTE2 pin
//   <o> PTE2 [EXTAL1, GPIOE_2, EWM_IN, PXBAR_IN6, I2C1_SDA]<name=PTE2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE2 pin
//     <-2=> EXTAL1 (reset default)<selection=EXTAL1_PIN_SEL,PTE2 (reset default)>
//     <0=> EXTAL1<selection=EXTAL1_PIN_SEL,PTE2>
//     <1=> GPIOE_2<selection=GPIOE_2_PIN_SEL,PTE2>
//     <2=> EWM_IN<selection=EWM_IN_PIN_SEL,PTE2>
//     <3=> PXBAR_IN6<selection=PXBAR_IN6_PIN_SEL,PTE2>
//     <4=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTE2>
//     <-2=> Default
#define PTE2_SIG_SEL         -2

// Signal mapping for PTE3 pin
//   <o> PTE3 [XTAL1, GPIOE_3, EWM_OUT, AFE_CLK, I2C1_SCL]<name=PTE3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE3 pin
//     <-2=> XTAL1 (reset default)<selection=XTAL1_PIN_SEL,PTE3 (reset default)>
//     <0=> XTAL1<selection=XTAL1_PIN_SEL,PTE3>
//     <1=> GPIOE_3<selection=GPIOE_3_PIN_SEL,PTE3>
//     <2=> EWM_OUT<selection=EWM_OUT_PIN_SEL,PTE3>
//     <3=> AFE_CLK<selection=AFE_CLK_PIN_SEL,PTE3>
//     <4=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTE3>
//     <-2=> Default
#define PTE3_SIG_SEL         -2

// Signal mapping for PTE4 pin
//   <o> PTE4 [GPIOE_4, LPTMR_ALT0, SCI2_CTS, EWM_IN]<name=PTE4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE4 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_4<selection=GPIOE_4_PIN_SEL,PTE4>
//     <2=> LPTMR_ALT0<selection=LPTMR_ALT0_PIN_SEL,PTE4>
//     <3=> SCI2_CTS<selection=SCI2_CTS_PIN_SEL,PTE4>
//     <4=> EWM_IN<selection=EWM_IN_PIN_SEL,PTE4>
//     <-2=> Default
#define PTE4_SIG_SEL         -2

// Signal mapping for PTE5 pin
//   <o> PTE5 [GPIOE_5, QT3, SCI2_RTS, EWM_OUT, LLWU_P6]<name=PTE5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE5 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_5<selection=GPIOE_5_PIN_SEL,PTE5>
//     <2=> QT3<selection=QT3_PIN_SEL,PTE5>
//     <3=> SCI2_RTS<selection=SCI2_RTS_PIN_SEL,PTE5>
//     <4=> EWM_OUT<selection=EWM_OUT_PIN_SEL,PTE5>
//     <5=> LLWU_P6<selection=LLWU_P6_PIN_SEL,PTE5>
//     <-2=> Default
#define PTE5_SIG_SEL         -2

// Signal mapping for PTE6 pin
//   <o> PTE6 [CMP0P2, GPIOE_6, PXBAR_IN5, SCI2_RxD, LLWU_P5, I2C0_SCL, SWD_IO]<name=PTE6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE6 pin
//     <-2=> SWD_IO (reset default)<selection=SWD_IO_PIN_SEL,PTE6 (reset default)>
//     <0=> CMP0P2<selection=CMP0P2_PIN_SEL,PTE6>
//     <1=> GPIOE_6<selection=GPIOE_6_PIN_SEL,PTE6>
//     <2=> PXBAR_IN5<selection=PXBAR_IN5_PIN_SEL,PTE6>
//     <3=> SCI2_RxD<selection=SCI2_RxD_PIN_SEL,PTE6>
//     <4=> LLWU_P5<selection=LLWU_P5_PIN_SEL,PTE6>
//     <5=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTE6>
//     <7=> SWD_IO<selection=SWD_IO_PIN_SEL,PTE6>
//     <-2=> Default
#define PTE6_SIG_SEL         -2

// Signal mapping for PTE7 pin
//   <o> PTE7 [ADC0_SE6, GPIOE_7, PXBAR_OUT5, SCI2_TxD, I2C0_SDA, SWD_CLK]<name=PTE7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE7 pin
//     <-2=> SWD_CLK (reset default)<selection=SWD_CLK_PIN_SEL,PTE7 (reset default)>
//     <0=> ADC0_SE6<selection=ADC0_SE6_PIN_SEL,PTE7>
//     <1=> GPIOE_7<selection=GPIOE_7_PIN_SEL,PTE7>
//     <2=> PXBAR_OUT5<selection=PXBAR_OUT5_PIN_SEL,PTE7>
//     <3=> SCI2_TxD<selection=SCI2_TxD_PIN_SEL,PTE7>
//     <5=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTE7>
//     <7=> SWD_CLK<selection=SWD_CLK_PIN_SEL,PTE7>
//     <-2=> Default
#define PTE7_SIG_SEL         -2

// </h>

// <h> Port F Pins

// Signal mapping for PTF0 pin
//   <o> PTF0 [ADC0_SE7, GPIOF_0, RTCCLKOUT, QT2, CMP0OUT, LLWU_P4]<name=PTF0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTF0 pin
//     <-2=> Disabled (reset default)
//     <0=> ADC0_SE7<selection=ADC0_SE7_PIN_SEL,PTF0>
//     <1=> GPIOF_0<selection=GPIOF_0_PIN_SEL,PTF0>
//     <2=> RTCCLKOUT<selection=RTCCLKOUT_PIN_SEL,PTF0>
//     <3=> QT2<selection=QT2_PIN_SEL,PTF0>
//     <4=> CMP0OUT<selection=CMP0OUT_PIN_SEL,PTF0>
//     <5=> LLWU_P4<selection=LLWU_P4_PIN_SEL,PTF0>
//     <-2=> Default
#define PTF0_SIG_SEL         -2

// Signal mapping for PTF1 pin
//   <o> PTF1 [LCD0/ADC0_SE8, GPIOF_1, QT0, PXBAR_OUT6]<name=PTF1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTF1 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD0/ADC0_SE8<selection=LCD0_PIN_SEL,PTF1><selection=ADC0_SE8_PIN_SEL,PTF1>
//     <1=> GPIOF_1<selection=GPIOF_1_PIN_SEL,PTF1>
//     <2=> QT0<selection=QT0_PIN_SEL,PTF1>
//     <3=> PXBAR_OUT6<selection=PXBAR_OUT6_PIN_SEL,PTF1>
//     <-2=> Default
#define PTF1_SIG_SEL         -2

// Signal mapping for PTF2 pin
//   <o> PTF2 [LCD1/ADC0_SE9, GPIOF_2, CMP1OUT, RTCCLKOUT]<name=PTF2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTF2 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD1/ADC0_SE9<selection=LCD1_PIN_SEL,PTF2><selection=ADC0_SE9_PIN_SEL,PTF2>
//     <1=> GPIOF_2<selection=GPIOF_2_PIN_SEL,PTF2>
//     <2=> CMP1OUT<selection=CMP1OUT_PIN_SEL,PTF2>
//     <3=> RTCCLKOUT<selection=RTCCLKOUT_PIN_SEL,PTF2>
//     <-2=> Default
#define PTF2_SIG_SEL         -2

// Signal mapping for PTF3 pin
//   <o> PTF3 [LCD2, GPIOF_3, SPI1_SS_B, LPTMR_ALT1, SCI0_RxD]<name=PTF3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTF3 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD2<selection=LCD2_PIN_SEL,PTF3>
//     <1=> GPIOF_3<selection=GPIOF_3_PIN_SEL,PTF3>
//     <2=> SPI1_SS_B<selection=SPI1_SS_B_PIN_SEL,PTF3>
//     <3=> LPTMR_ALT1<selection=LPTMR_ALT1_PIN_SEL,PTF3>
//     <4=> SCI0_RxD<selection=SCI0_RxD_PIN_SEL,PTF3>
//     <-2=> Default
#define PTF3_SIG_SEL         -2

// Signal mapping for PTF4 pin
//   <o> PTF4 [LCD3, GPIOF_4, SPI1_SCK, LPTMR_ALT0, SCI0_TxD]<name=PTF4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTF4 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD3<selection=LCD3_PIN_SEL,PTF4>
//     <1=> GPIOF_4<selection=GPIOF_4_PIN_SEL,PTF4>
//     <2=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTF4>
//     <3=> LPTMR_ALT0<selection=LPTMR_ALT0_PIN_SEL,PTF4>
//     <4=> SCI0_TxD<selection=SCI0_TxD_PIN_SEL,PTF4>
//     <-2=> Default
#define PTF4_SIG_SEL         -2

// Signal mapping for PTF5 pin
//   <o> PTF5 [LCD4, GPIOF_5, SPI1_MISO, I2C1_SCL]<name=PTF5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTF5 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD4<selection=LCD4_PIN_SEL,PTF5>
//     <1=> GPIOF_5<selection=GPIOF_5_PIN_SEL,PTF5>
//     <2=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTF5>
//     <3=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTF5>
//     <-2=> Default
#define PTF5_SIG_SEL         -2

// Signal mapping for PTF6 pin
//   <o> PTF6 [LCD5, GPIOF_6, SPI1_MOSI, I2C1_SDA, LLWU_P3]<name=PTF6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTF6 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD5<selection=LCD5_PIN_SEL,PTF6>
//     <1=> GPIOF_6<selection=GPIOF_6_PIN_SEL,PTF6>
//     <2=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTF6>
//     <3=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTF6>
//     <4=> LLWU_P3<selection=LLWU_P3_PIN_SEL,PTF6>
//     <-2=> Default
#define PTF6_SIG_SEL         -2

// Signal mapping for PTF7 pin
//   <o> PTF7 [LCD6, GPIOF_7, QT2, CLKOUT]<name=PTF7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTF7 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD6<selection=LCD6_PIN_SEL,PTF7>
//     <1=> GPIOF_7<selection=GPIOF_7_PIN_SEL,PTF7>
//     <2=> QT2<selection=QT2_PIN_SEL,PTF7>
//     <3=> CLKOUT<selection=CLKOUT_PIN_SEL,PTF7>
//     <-2=> Default
#define PTF7_SIG_SEL         -2

// </h>

// <h> Port G Pins

// Signal mapping for PTG0 pin
//   <o> PTG0 [LCD7, GPIOG_0, QT1, LPTMR_ALT2]<name=PTG0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTG0 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD7<selection=LCD7_PIN_SEL,PTG0>
//     <1=> GPIOG_0<selection=GPIOG_0_PIN_SEL,PTG0>
//     <2=> QT1<selection=QT1_PIN_SEL,PTG0>
//     <3=> LPTMR_ALT2<selection=LPTMR_ALT2_PIN_SEL,PTG0>
//     <-2=> Default
#define PTG0_SIG_SEL         -2

// Signal mapping for PTG1 pin
//   <o> PTG1 [LCD8/ADC0_SE10, GPIOG_1, LLWU_P2, LPTMR_ALT0]<name=PTG1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTG1 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD8/ADC0_SE10<selection=LCD8_PIN_SEL,PTG1><selection=ADC0_SE10_PIN_SEL,PTG1>
//     <1=> GPIOG_1<selection=GPIOG_1_PIN_SEL,PTG1>
//     <2=> LLWU_P2<selection=LLWU_P2_PIN_SEL,PTG1>
//     <3=> LPTMR_ALT0<selection=LPTMR_ALT0_PIN_SEL,PTG1>
//     <-2=> Default
#define PTG1_SIG_SEL         -2

// Signal mapping for PTG2 pin
//   <o> PTG2 [LCD9/ADC0_SE11, GPIOG_2, SPI0_SS_B, LLWU_P1]<name=PTG2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTG2 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD9/ADC0_SE11<selection=LCD9_PIN_SEL,PTG2><selection=ADC0_SE11_PIN_SEL,PTG2>
//     <1=> GPIOG_2<selection=GPIOG_2_PIN_SEL,PTG2>
//     <2=> SPI0_SS_B<selection=SPI0_SS_B_PIN_SEL,PTG2>
//     <3=> LLWU_P1<selection=LLWU_P1_PIN_SEL,PTG2>
//     <-2=> Default
#define PTG2_SIG_SEL         -2

// Signal mapping for PTG3 pin
//   <o> PTG3 [LCD10, GPIOG_3, SPI0_SCK, I2C0_SCL]<name=PTG3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTG3 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD10<selection=LCD10_PIN_SEL,PTG3>
//     <1=> GPIOG_3<selection=GPIOG_3_PIN_SEL,PTG3>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTG3>
//     <3=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTG3>
//     <-2=> Default
#define PTG3_SIG_SEL         -2

// Signal mapping for PTG4 pin
//   <o> PTG4 [LCD11, GPIOG_4, SPI0_MOSI, I2C0_SDA]<name=PTG4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTG4 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD11<selection=LCD11_PIN_SEL,PTG4>
//     <1=> GPIOG_4<selection=GPIOG_4_PIN_SEL,PTG4>
//     <2=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTG4>
//     <3=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTG4>
//     <-2=> Default
#define PTG4_SIG_SEL         -2

// Signal mapping for PTG5 pin
//   <o> PTG5 [LCD12, GPIOG_5, SPI0_MISO, LPTMR_ALT1]<name=PTG5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTG5 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD12<selection=LCD12_PIN_SEL,PTG5>
//     <1=> GPIOG_5<selection=GPIOG_5_PIN_SEL,PTG5>
//     <2=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTG5>
//     <3=> LPTMR_ALT1<selection=LPTMR_ALT1_PIN_SEL,PTG5>
//     <-2=> Default
#define PTG5_SIG_SEL         -2

// Signal mapping for PTG6 pin
//   <o> PTG6 [LCD13, GPIOG_6, LLWU_P0, LPTMR_ALT2]<name=PTG6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTG6 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD13<selection=LCD13_PIN_SEL,PTG6>
//     <1=> GPIOG_6<selection=GPIOG_6_PIN_SEL,PTG6>
//     <2=> LLWU_P0<selection=LLWU_P0_PIN_SEL,PTG6>
//     <3=> LPTMR_ALT2<selection=LPTMR_ALT2_PIN_SEL,PTG6>
//     <-2=> Default
#define PTG6_SIG_SEL         -2

// Signal mapping for PTG7 pin
//   <o> PTG7 [LCD14, GPIOG_7]<name=PTG7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTG7 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD14<selection=LCD14_PIN_SEL,PTG7>
//     <1=> GPIOG_7<selection=GPIOG_7_PIN_SEL,PTG7>
//     <-2=> Default
#define PTG7_SIG_SEL         -2

// </h>

// <h> Port H Pins

// Signal mapping for PTH0 pin
//   <o> PTH0 [LCD15, GPIOH_0]<name=PTH0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTH0 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD15<selection=LCD15_PIN_SEL,PTH0>
//     <1=> GPIOH_0<selection=GPIOH_0_PIN_SEL,PTH0>
//     <-2=> Default
#define PTH0_SIG_SEL         -2

// Signal mapping for PTH1 pin
//   <o> PTH1 [LCD16, GPIOH_1]<name=PTH1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTH1 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD16<selection=LCD16_PIN_SEL,PTH1>
//     <1=> GPIOH_1<selection=GPIOH_1_PIN_SEL,PTH1>
//     <-2=> Default
#define PTH1_SIG_SEL         -2

// Signal mapping for PTH2 pin
//   <o> PTH2 [LCD17, GPIOH_2]<name=PTH2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTH2 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD17<selection=LCD17_PIN_SEL,PTH2>
//     <1=> GPIOH_2<selection=GPIOH_2_PIN_SEL,PTH2>
//     <-2=> Default
#define PTH2_SIG_SEL         -2

// Signal mapping for PTH3 pin
//   <o> PTH3 [LCD18, GPIOH_3]<name=PTH3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTH3 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD18<selection=LCD18_PIN_SEL,PTH3>
//     <1=> GPIOH_3<selection=GPIOH_3_PIN_SEL,PTH3>
//     <-2=> Default
#define PTH3_SIG_SEL         -2

// Signal mapping for PTH4 pin
//   <o> PTH4 [LCD19, GPIOH_4]<name=PTH4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTH4 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD19<selection=LCD19_PIN_SEL,PTH4>
//     <1=> GPIOH_4<selection=GPIOH_4_PIN_SEL,PTH4>
//     <-2=> Default
#define PTH4_SIG_SEL         -2

// Signal mapping for PTH5 pin
//   <o> PTH5 [LCD20, GPIOH_5]<name=PTH5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTH5 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD20<selection=LCD20_PIN_SEL,PTH5>
//     <1=> GPIOH_5<selection=GPIOH_5_PIN_SEL,PTH5>
//     <-2=> Default
#define PTH5_SIG_SEL         -2

// Signal mapping for PTH6 pin
//   <o> PTH6 [GPIOH_6, SCI1_CTS, SPI1_SS_B, PXBAR_IN7]<name=PTH6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTH6 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOH_6<selection=GPIOH_6_PIN_SEL,PTH6>
//     <2=> SCI1_CTS<selection=SCI1_CTS_PIN_SEL,PTH6>
//     <3=> SPI1_SS_B<selection=SPI1_SS_B_PIN_SEL,PTH6>
//     <4=> PXBAR_IN7<selection=PXBAR_IN7_PIN_SEL,PTH6>
//     <-2=> Default
#define PTH6_SIG_SEL         -2

// Signal mapping for PTH7 pin
//   <o> PTH7 [GPIOH_7, SCI1_RTS, SPI1_SCK, PXBAR_OUT7]<name=PTH7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTH7 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOH_7<selection=GPIOH_7_PIN_SEL,PTH7>
//     <2=> SCI1_RTS<selection=SCI1_RTS_PIN_SEL,PTH7>
//     <3=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTH7>
//     <4=> PXBAR_OUT7<selection=PXBAR_OUT7_PIN_SEL,PTH7>
//     <-2=> Default
#define PTH7_SIG_SEL         -2

// </h>

// <h> Port I Pins

// Signal mapping for PTI0 pin
//   <o> PTI0 [CMP0P5, GPIOI_0, SCI1_RxD, PXBAR_IN8, SPI1_MISO, SPI1_MOSI]<name=PTI0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTI0 pin
//     <-2=> Disabled (reset default)
//     <0=> CMP0P5<selection=CMP0P5_PIN_SEL,PTI0>
//     <1=> GPIOI_0<selection=GPIOI_0_PIN_SEL,PTI0>
//     <2=> SCI1_RxD<selection=SCI1_RxD_PIN_SEL,PTI0>
//     <3=> PXBAR_IN8<selection=PXBAR_IN8_PIN_SEL,PTI0>
//     <4=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTI0>
//     <5=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTI0>
//     <-2=> Default
#define PTI0_SIG_SEL         -2

// Signal mapping for PTI1 pin
//   <o> PTI1 [GPIOI_1, SCI1_TxD, PXBAR_OUT8, SPI1_MOSI, SPI1_MISO]<name=PTI1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTI1 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOI_1<selection=GPIOI_1_PIN_SEL,PTI1>
//     <2=> SCI1_TxD<selection=SCI1_TxD_PIN_SEL,PTI1>
//     <3=> PXBAR_OUT8<selection=PXBAR_OUT8_PIN_SEL,PTI1>
//     <4=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTI1>
//     <5=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTI1>
//     <-2=> Default
#define PTI1_SIG_SEL         -2

// Signal mapping for PTI2 pin
//   <o> PTI2 [LCD21, GPIOI_2]<name=PTI2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTI2 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD21<selection=LCD21_PIN_SEL,PTI2>
//     <1=> GPIOI_2<selection=GPIOI_2_PIN_SEL,PTI2>
//     <-2=> Default
#define PTI2_SIG_SEL         -2

// Signal mapping for PTI3 pin
//   <o> PTI3 [LCD22, GPIOI_3]<name=PTI3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTI3 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD22<selection=LCD22_PIN_SEL,PTI3>
//     <1=> GPIOI_3<selection=GPIOI_3_PIN_SEL,PTI3>
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
//   <o> LCD0 [PTF1]<name=LCD0_PIN_SEL>
//   <i> Shows which pin LCD0 is mapped to
//     <0=> Disabled
//     <1=> PTF1<selection=PTF1_SIG_SEL,LCD0/ADC0_SE8>
//     <0=> Default
#define LCD0_PIN_SEL         0
#if LCD0_PIN_SEL == 1
#define LCD0_GPIO            digitalIO_PTF1
#define LCD0_FN              0
#endif

// Pin Mapping for LCD1 signal
//   <o> LCD1 [PTF2]<name=LCD1_PIN_SEL>
//   <i> Shows which pin LCD1 is mapped to
//     <0=> Disabled
//     <1=> PTF2<selection=PTF2_SIG_SEL,LCD1/ADC0_SE9>
//     <0=> Default
#define LCD1_PIN_SEL         0
#if LCD1_PIN_SEL == 1
#define LCD1_GPIO            digitalIO_PTF2
#define LCD1_FN              0
#endif

// Pin Mapping for LCD2 signal
//   <o> LCD2 [PTF3]<name=LCD2_PIN_SEL>
//   <i> Shows which pin LCD2 is mapped to
//     <0=> Disabled
//     <1=> PTF3<selection=PTF3_SIG_SEL,LCD2>
//     <0=> Default
#define LCD2_PIN_SEL         0
#if LCD2_PIN_SEL == 1
#define LCD2_GPIO            digitalIO_PTF3
#define LCD2_FN              0
#endif

// Pin Mapping for LCD3 signal
//   <o> LCD3 [PTF4]<name=LCD3_PIN_SEL>
//   <i> Shows which pin LCD3 is mapped to
//     <0=> Disabled
//     <1=> PTF4<selection=PTF4_SIG_SEL,LCD3>
//     <0=> Default
#define LCD3_PIN_SEL         0
#if LCD3_PIN_SEL == 1
#define LCD3_GPIO            digitalIO_PTF4
#define LCD3_FN              0
#endif

// Pin Mapping for LCD4 signal
//   <o> LCD4 [PTF5]<name=LCD4_PIN_SEL>
//   <i> Shows which pin LCD4 is mapped to
//     <0=> Disabled
//     <1=> PTF5<selection=PTF5_SIG_SEL,LCD4>
//     <0=> Default
#define LCD4_PIN_SEL         0
#if LCD4_PIN_SEL == 1
#define LCD4_GPIO            digitalIO_PTF5
#define LCD4_FN              0
#endif

// Pin Mapping for LCD5 signal
//   <o> LCD5 [PTF6]<name=LCD5_PIN_SEL>
//   <i> Shows which pin LCD5 is mapped to
//     <0=> Disabled
//     <1=> PTF6<selection=PTF6_SIG_SEL,LCD5>
//     <0=> Default
#define LCD5_PIN_SEL         0
#if LCD5_PIN_SEL == 1
#define LCD5_GPIO            digitalIO_PTF6
#define LCD5_FN              0
#endif

// Pin Mapping for LCD6 signal
//   <o> LCD6 [PTF7]<name=LCD6_PIN_SEL>
//   <i> Shows which pin LCD6 is mapped to
//     <0=> Disabled
//     <1=> PTF7<selection=PTF7_SIG_SEL,LCD6>
//     <0=> Default
#define LCD6_PIN_SEL         0
#if LCD6_PIN_SEL == 1
#define LCD6_GPIO            digitalIO_PTF7
#define LCD6_FN              0
#endif

// Pin Mapping for LCD7 signal
//   <o> LCD7 [PTG0]<name=LCD7_PIN_SEL>
//   <i> Shows which pin LCD7 is mapped to
//     <0=> Disabled
//     <1=> PTG0<selection=PTG0_SIG_SEL,LCD7>
//     <0=> Default
#define LCD7_PIN_SEL         0
#if LCD7_PIN_SEL == 1
#define LCD7_GPIO            digitalIO_PTG0
#define LCD7_FN              0
#endif

// Pin Mapping for LCD8 signal
//   <o> LCD8 [PTG1]<name=LCD8_PIN_SEL>
//   <i> Shows which pin LCD8 is mapped to
//     <0=> Disabled
//     <1=> PTG1<selection=PTG1_SIG_SEL,LCD8/ADC0_SE10>
//     <0=> Default
#define LCD8_PIN_SEL         0
#if LCD8_PIN_SEL == 1
#define LCD8_GPIO            digitalIO_PTG1
#define LCD8_FN              0
#endif

// Pin Mapping for LCD9 signal
//   <o> LCD9 [PTG2]<name=LCD9_PIN_SEL>
//   <i> Shows which pin LCD9 is mapped to
//     <0=> Disabled
//     <1=> PTG2<selection=PTG2_SIG_SEL,LCD9/ADC0_SE11>
//     <0=> Default
#define LCD9_PIN_SEL         0
#if LCD9_PIN_SEL == 1
#define LCD9_GPIO            digitalIO_PTG2
#define LCD9_FN              0
#endif

// Pin Mapping for LCD10 signal
//   <o> LCD10 [PTG3]<name=LCD10_PIN_SEL>
//   <i> Shows which pin LCD10 is mapped to
//     <0=> Disabled
//     <1=> PTG3<selection=PTG3_SIG_SEL,LCD10>
//     <0=> Default
#define LCD10_PIN_SEL        0
#if LCD10_PIN_SEL == 1
#define LCD10_GPIO           digitalIO_PTG3
#define LCD10_FN             0
#endif

// Pin Mapping for LCD11 signal
//   <o> LCD11 [PTG4]<name=LCD11_PIN_SEL>
//   <i> Shows which pin LCD11 is mapped to
//     <0=> Disabled
//     <1=> PTG4<selection=PTG4_SIG_SEL,LCD11>
//     <0=> Default
#define LCD11_PIN_SEL        0
#if LCD11_PIN_SEL == 1
#define LCD11_GPIO           digitalIO_PTG4
#define LCD11_FN             0
#endif

// Pin Mapping for LCD12 signal
//   <o> LCD12 [PTG5]<name=LCD12_PIN_SEL>
//   <i> Shows which pin LCD12 is mapped to
//     <0=> Disabled
//     <1=> PTG5<selection=PTG5_SIG_SEL,LCD12>
//     <0=> Default
#define LCD12_PIN_SEL        0
#if LCD12_PIN_SEL == 1
#define LCD12_GPIO           digitalIO_PTG5
#define LCD12_FN             0
#endif

// Pin Mapping for LCD13 signal
//   <o> LCD13 [PTG6]<name=LCD13_PIN_SEL>
//   <i> Shows which pin LCD13 is mapped to
//     <0=> Disabled
//     <1=> PTG6<selection=PTG6_SIG_SEL,LCD13>
//     <0=> Default
#define LCD13_PIN_SEL        0
#if LCD13_PIN_SEL == 1
#define LCD13_GPIO           digitalIO_PTG6
#define LCD13_FN             0
#endif

// Pin Mapping for LCD14 signal
//   <o> LCD14 [PTG7]<name=LCD14_PIN_SEL>
//   <i> Shows which pin LCD14 is mapped to
//     <0=> Disabled
//     <1=> PTG7<selection=PTG7_SIG_SEL,LCD14>
//     <0=> Default
#define LCD14_PIN_SEL        0
#if LCD14_PIN_SEL == 1
#define LCD14_GPIO           digitalIO_PTG7
#define LCD14_FN             0
#endif

// Pin Mapping for LCD15 signal
//   <o> LCD15 [PTH0]<name=LCD15_PIN_SEL>
//   <i> Shows which pin LCD15 is mapped to
//     <0=> Disabled
//     <1=> PTH0<selection=PTH0_SIG_SEL,LCD15>
//     <0=> Default
#define LCD15_PIN_SEL        0
#if LCD15_PIN_SEL == 1
#define LCD15_GPIO           digitalIO_PTH0
#define LCD15_FN             0
#endif

// Pin Mapping for LCD16 signal
//   <o> LCD16 [PTH1]<name=LCD16_PIN_SEL>
//   <i> Shows which pin LCD16 is mapped to
//     <0=> Disabled
//     <1=> PTH1<selection=PTH1_SIG_SEL,LCD16>
//     <0=> Default
#define LCD16_PIN_SEL        0
#if LCD16_PIN_SEL == 1
#define LCD16_GPIO           digitalIO_PTH1
#define LCD16_FN             0
#endif

// Pin Mapping for LCD17 signal
//   <o> LCD17 [PTH2]<name=LCD17_PIN_SEL>
//   <i> Shows which pin LCD17 is mapped to
//     <0=> Disabled
//     <1=> PTH2<selection=PTH2_SIG_SEL,LCD17>
//     <0=> Default
#define LCD17_PIN_SEL        0
#if LCD17_PIN_SEL == 1
#define LCD17_GPIO           digitalIO_PTH2
#define LCD17_FN             0
#endif

// Pin Mapping for LCD18 signal
//   <o> LCD18 [PTH3]<name=LCD18_PIN_SEL>
//   <i> Shows which pin LCD18 is mapped to
//     <0=> Disabled
//     <1=> PTH3<selection=PTH3_SIG_SEL,LCD18>
//     <0=> Default
#define LCD18_PIN_SEL        0
#if LCD18_PIN_SEL == 1
#define LCD18_GPIO           digitalIO_PTH3
#define LCD18_FN             0
#endif

// Pin Mapping for LCD19 signal
//   <o> LCD19 [PTH4]<name=LCD19_PIN_SEL>
//   <i> Shows which pin LCD19 is mapped to
//     <0=> Disabled
//     <1=> PTH4<selection=PTH4_SIG_SEL,LCD19>
//     <0=> Default
#define LCD19_PIN_SEL        0
#if LCD19_PIN_SEL == 1
#define LCD19_GPIO           digitalIO_PTH4
#define LCD19_FN             0
#endif

// Pin Mapping for LCD20 signal
//   <o> LCD20 [PTH5]<name=LCD20_PIN_SEL>
//   <i> Shows which pin LCD20 is mapped to
//     <0=> Disabled
//     <1=> PTH5<selection=PTH5_SIG_SEL,LCD20>
//     <0=> Default
#define LCD20_PIN_SEL        0
#if LCD20_PIN_SEL == 1
#define LCD20_GPIO           digitalIO_PTH5
#define LCD20_FN             0
#endif

// Pin Mapping for LCD21 signal
//   <o> LCD21 [PTI2]<name=LCD21_PIN_SEL>
//   <i> Shows which pin LCD21 is mapped to
//     <0=> Disabled
//     <1=> PTI2<selection=PTI2_SIG_SEL,LCD21>
//     <0=> Default
#define LCD21_PIN_SEL        0
#if LCD21_PIN_SEL == 1
#define LCD21_GPIO           digitalIO_PTI2
#define LCD21_FN             0
#endif

// Pin Mapping for LCD22 signal
//   <o> LCD22 [PTI3]<name=LCD22_PIN_SEL>
//   <i> Shows which pin LCD22 is mapped to
//     <0=> Disabled
//     <1=> PTI3<selection=PTI3_SIG_SEL,LCD22>
//     <0=> Default
#define LCD22_PIN_SEL        0
#if LCD22_PIN_SEL == 1
#define LCD22_GPIO           digitalIO_PTI3
#define LCD22_FN             0
#endif

// Pin Mapping for LCD23 signal
//   <o> LCD23 [PTA0]<name=LCD23_PIN_SEL>
//   <i> Shows which pin LCD23 is mapped to
//     <0=> Disabled
//     <1=> PTA0 (Alias:LED_RED)<selection=PTA0_SIG_SEL,LCD23>
//     <0=> Default
#define LCD23_PIN_SEL        0
#if LCD23_PIN_SEL == 1
#define LCD23_GPIO           digitalIO_PTA0
#define LCD23_FN             0
#endif

// Pin Mapping for LCD24 signal
//   <o> LCD24 [PTA1]<name=LCD24_PIN_SEL>
//   <i> Shows which pin LCD24 is mapped to
//     <0=> Disabled
//     <1=> PTA1 (Alias:LED_GREEN)<selection=PTA1_SIG_SEL,LCD24>
//     <0=> Default
#define LCD24_PIN_SEL        0
#if LCD24_PIN_SEL == 1
#define LCD24_GPIO           digitalIO_PTA1
#define LCD24_FN             0
#endif

// Pin Mapping for LCD25 signal
//   <o> LCD25 [PTA2]<name=LCD25_PIN_SEL>
//   <i> Shows which pin LCD25 is mapped to
//     <0=> Disabled
//     <1=> PTA2<selection=PTA2_SIG_SEL,LCD25>
//     <0=> Default
#define LCD25_PIN_SEL        0
#if LCD25_PIN_SEL == 1
#define LCD25_GPIO           digitalIO_PTA2
#define LCD25_FN             0
#endif

// Pin Mapping for LCD26 signal
//   <o> LCD26 [PTA3]<name=LCD26_PIN_SEL>
//   <i> Shows which pin LCD26 is mapped to
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,LCD26>
//     <0=> Default
#define LCD26_PIN_SEL        0
#if LCD26_PIN_SEL == 1
#define LCD26_GPIO           digitalIO_PTA3
#define LCD26_FN             0
#endif

// Pin Mapping for LCD27 signal
//   <o> LCD27 [PTA4]<name=LCD27_PIN_SEL>
//   <i> Shows which pin LCD27 is mapped to
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,LCD27>
//     <0=> Default
#define LCD27_PIN_SEL        0
#if LCD27_PIN_SEL == 1
#define LCD27_GPIO           digitalIO_PTA4
#define LCD27_FN             0
#endif

// Pin Mapping for LCD28 signal
//   <o> LCD28 [PTA5]<name=LCD28_PIN_SEL>
//   <i> Shows which pin LCD28 is mapped to
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,LCD28>
//     <0=> Default
#define LCD28_PIN_SEL        0
#if LCD28_PIN_SEL == 1
#define LCD28_GPIO           digitalIO_PTA5
#define LCD28_FN             0
#endif

// Pin Mapping for LCD29 signal
//   <o> LCD29 [PTA6]<name=LCD29_PIN_SEL>
//   <i> Shows which pin LCD29 is mapped to
//     <0=> Disabled
//     <1=> PTA6<selection=PTA6_SIG_SEL,LCD29>
//     <0=> Default
#define LCD29_PIN_SEL        0
#if LCD29_PIN_SEL == 1
#define LCD29_GPIO           digitalIO_PTA6
#define LCD29_FN             0
#endif

// Pin Mapping for LCD30 signal
//   <o> LCD30 [PTA7]<name=LCD30_PIN_SEL>
//   <i> Shows which pin LCD30 is mapped to
//     <0=> Disabled
//     <1=> PTA7<selection=PTA7_SIG_SEL,LCD30>
//     <0=> Default
#define LCD30_PIN_SEL        0
#if LCD30_PIN_SEL == 1
#define LCD30_GPIO           digitalIO_PTA7
#define LCD30_FN             0
#endif

// Pin Mapping for LCD31 signal
//   <o> LCD31 [PTB0]<name=LCD31_PIN_SEL>
//   <i> Shows which pin LCD31 is mapped to
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,LCD31>
//     <0=> Default
#define LCD31_PIN_SEL        0
#if LCD31_PIN_SEL == 1
#define LCD31_GPIO           digitalIO_PTB0
#define LCD31_FN             0
#endif

// Pin Mapping for LCD32 signal
//   <o> LCD32 [PTB1]<name=LCD32_PIN_SEL>
//   <i> Shows which pin LCD32 is mapped to
//     <0=> Disabled
//     <1=> PTB1<selection=PTB1_SIG_SEL,LCD32>
//     <0=> Default
#define LCD32_PIN_SEL        0
#if LCD32_PIN_SEL == 1
#define LCD32_GPIO           digitalIO_PTB1
#define LCD32_FN             0
#endif

// Pin Mapping for LCD33 signal
//   <o> LCD33 [PTB2]<name=LCD33_PIN_SEL>
//   <i> Shows which pin LCD33 is mapped to
//     <0=> Disabled
//     <1=> PTB2<selection=PTB2_SIG_SEL,LCD33>
//     <0=> Default
#define LCD33_PIN_SEL        0
#if LCD33_PIN_SEL == 1
#define LCD33_GPIO           digitalIO_PTB2
#define LCD33_FN             0
#endif

// Pin Mapping for LCD34 signal
//   <o> LCD34 [PTB3]<name=LCD34_PIN_SEL>
//   <i> Shows which pin LCD34 is mapped to
//     <0=> Disabled
//     <1=> PTB3<selection=PTB3_SIG_SEL,LCD34>
//     <0=> Default
#define LCD34_PIN_SEL        0
#if LCD34_PIN_SEL == 1
#define LCD34_GPIO           digitalIO_PTB3
#define LCD34_FN             0
#endif

// Pin Mapping for LCD35 signal
//   <o> LCD35 [PTB4]<name=LCD35_PIN_SEL>
//   <i> Shows which pin LCD35 is mapped to
//     <0=> Disabled
//     <1=> PTB4<selection=PTB4_SIG_SEL,LCD35>
//     <0=> Default
#define LCD35_PIN_SEL        0
#if LCD35_PIN_SEL == 1
#define LCD35_GPIO           digitalIO_PTB4
#define LCD35_FN             0
#endif

// Pin Mapping for LCD36 signal
//   <o> LCD36 [PTB5]<name=LCD36_PIN_SEL>
//   <i> Shows which pin LCD36 is mapped to
//     <0=> Disabled
//     <1=> PTB5<selection=PTB5_SIG_SEL,LCD36>
//     <0=> Default
#define LCD36_PIN_SEL        0
#if LCD36_PIN_SEL == 1
#define LCD36_GPIO           digitalIO_PTB5
#define LCD36_FN             0
#endif

// Pin Mapping for LCD37 signal
//   <o> LCD37 [PTB6]<name=LCD37_PIN_SEL>
//   <i> Shows which pin LCD37 is mapped to
//     <0=> Disabled
//     <1=> PTB6<selection=PTB6_SIG_SEL,LCD37/CMP1P0>
//     <0=> Default
#define LCD37_PIN_SEL        0
#if LCD37_PIN_SEL == 1
#define LCD37_GPIO           digitalIO_PTB6
#define LCD37_FN             0
#endif

// Pin Mapping for LCD38 signal
//   <o> LCD38 [PTB7]<name=LCD38_PIN_SEL>
//   <i> Shows which pin LCD38 is mapped to
//     <0=> Disabled
//     <1=> PTB7<selection=PTB7_SIG_SEL,LCD38>
//     <0=> Default
#define LCD38_PIN_SEL        0
#if LCD38_PIN_SEL == 1
#define LCD38_GPIO           digitalIO_PTB7
#define LCD38_FN             0
#endif

// Pin Mapping for LCD39 signal
//   <o> LCD39 [PTC0]<name=LCD39_PIN_SEL>
//   <i> Shows which pin LCD39 is mapped to
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,LCD39>
//     <0=> Default
#define LCD39_PIN_SEL        0
#if LCD39_PIN_SEL == 1
#define LCD39_GPIO           digitalIO_PTC0
#define LCD39_FN             0
#endif

// Pin Mapping for LCD40 signal
//   <o> LCD40 [PTC1]<name=LCD40_PIN_SEL>
//   <i> Shows which pin LCD40 is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,LCD40/CMP1P1>
//     <0=> Default
#define LCD40_PIN_SEL        0
#if LCD40_PIN_SEL == 1
#define LCD40_GPIO           digitalIO_PTC1
#define LCD40_FN             0
#endif

// Pin Mapping for LCD41 signal
//   <o> LCD41 [PTC2]<name=LCD41_PIN_SEL>
//   <i> Shows which pin LCD41 is mapped to
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,LCD41>
//     <0=> Default
#define LCD41_PIN_SEL        0
#if LCD41_PIN_SEL == 1
#define LCD41_GPIO           digitalIO_PTC2
#define LCD41_FN             0
#endif

// Pin Mapping for LCD42 signal
//   <o> LCD42 [PTC3]<name=LCD42_PIN_SEL>
//   <i> Shows which pin LCD42 is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,LCD42/CMP0P3>
//     <0=> Default
#define LCD42_PIN_SEL        0
#if LCD42_PIN_SEL == 1
#define LCD42_GPIO           digitalIO_PTC3
#define LCD42_FN             0
#endif

// Pin Mapping for LCD43 signal
//   <o> LCD43 [PTC4]<name=LCD43_PIN_SEL>
//   <i> Shows which pin LCD43 is mapped to
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,LCD43>
//     <0=> Default
#define LCD43_PIN_SEL        0
#if LCD43_PIN_SEL == 1
#define LCD43_GPIO           digitalIO_PTC4
#define LCD43_FN             0
#endif

// </h>

// <h> Analogue to Digital (ADC0)

// Pin Mapping for ADC0_SE0 signal
//   <o> ADC0_SE0 [PTC5]<name=ADC0_SE0_PIN_SEL>
//   <i> Shows which pin ADC0_SE0 is mapped to
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,ADC0_SE0>
//     <0=> Default
#define ADC0_SE0_PIN_SEL     0
#if ADC0_SE0_PIN_SEL == 1
#define ADC0_SE0_GPIO        digitalIO_PTC5
#define ADC0_SE0_FN          0
#endif

// Pin Mapping for ADC0_SE1 signal
//   <o> ADC0_SE1 [PTC6]<name=ADC0_SE1_PIN_SEL>
//   <i> Shows which pin ADC0_SE1 is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,ADC0_SE1>
//     <0=> Default
#define ADC0_SE1_PIN_SEL     0
#if ADC0_SE1_PIN_SEL == 1
#define ADC0_SE1_GPIO        digitalIO_PTC6
#define ADC0_SE1_FN          0
#endif

// Pin Mapping for ADC0_SE2 signal
//   <o> ADC0_SE2 [PTC7]<name=ADC0_SE2_PIN_SEL>
//   <i> Shows which pin ADC0_SE2 is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,ADC0_SE2>
//     <0=> Default
#define ADC0_SE2_PIN_SEL     0
#if ADC0_SE2_PIN_SEL == 1
#define ADC0_SE2_GPIO        digitalIO_PTC7
#define ADC0_SE2_FN          0
#endif

// Pin Mapping for ADC0_SE3 signal
//   <o> ADC0_SE3 [PTD4]<name=ADC0_SE3_PIN_SEL>
//   <i> Shows which pin ADC0_SE3 is mapped to
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,ADC0_SE3>
//     <0=> Default
#define ADC0_SE3_PIN_SEL     0
#if ADC0_SE3_PIN_SEL == 1
#define ADC0_SE3_GPIO        digitalIO_PTD4
#define ADC0_SE3_FN          0
#endif

// Pin Mapping for ADC0_SE4 signal
//   <o> ADC0_SE4 [PTD5]<name=ADC0_SE4_PIN_SEL>
//   <i> Shows which pin ADC0_SE4 is mapped to
//     <0=> Disabled
//     <1=> PTD5<selection=PTD5_SIG_SEL,ADC0_SE4>
//     <0=> Default
#define ADC0_SE4_PIN_SEL     0
#if ADC0_SE4_PIN_SEL == 1
#define ADC0_SE4_GPIO        digitalIO_PTD5
#define ADC0_SE4_FN          0
#endif

// Pin Mapping for ADC0_SE5 signal
//   <o> ADC0_SE5 [PTD6]<name=ADC0_SE5_PIN_SEL>
//   <i> Shows which pin ADC0_SE5 is mapped to
//     <0=> Disabled
//     <1=> PTD6<selection=PTD6_SIG_SEL,ADC0_SE5>
//     <0=> Default
#define ADC0_SE5_PIN_SEL     0
#if ADC0_SE5_PIN_SEL == 1
#define ADC0_SE5_GPIO        digitalIO_PTD6
#define ADC0_SE5_FN          0
#endif

// Pin Mapping for ADC0_SE6 signal
//   <o> ADC0_SE6 [PTE7]<name=ADC0_SE6_PIN_SEL>
//   <i> Shows which pin ADC0_SE6 is mapped to
//     <0=> Disabled
//     <1=> PTE7<selection=PTE7_SIG_SEL,ADC0_SE6>
//     <0=> Default
#define ADC0_SE6_PIN_SEL     0
#if ADC0_SE6_PIN_SEL == 1
#define ADC0_SE6_GPIO        digitalIO_PTE7
#define ADC0_SE6_FN          0
#endif

// Pin Mapping for ADC0_SE7 signal
//   <o> ADC0_SE7 [PTF0]<name=ADC0_SE7_PIN_SEL>
//   <i> Shows which pin ADC0_SE7 is mapped to
//     <0=> Disabled
//     <1=> PTF0<selection=PTF0_SIG_SEL,ADC0_SE7>
//     <0=> Default
#define ADC0_SE7_PIN_SEL     0
#if ADC0_SE7_PIN_SEL == 1
#define ADC0_SE7_GPIO        digitalIO_PTF0
#define ADC0_SE7_FN          0
#endif

// Pin Mapping for ADC0_SE8 signal
//   <o> ADC0_SE8 [PTF1]<name=ADC0_SE8_PIN_SEL>
//   <i> Shows which pin ADC0_SE8 is mapped to
//     <0=> Disabled
//     <1=> PTF1<selection=PTF1_SIG_SEL,LCD0/ADC0_SE8>
//     <0=> Default
#define ADC0_SE8_PIN_SEL     0
#if ADC0_SE8_PIN_SEL == 1
#define ADC0_SE8_GPIO        digitalIO_PTF1
#define ADC0_SE8_FN          0
#endif

// Pin Mapping for ADC0_SE9 signal
//   <o> ADC0_SE9 [PTF2]<name=ADC0_SE9_PIN_SEL>
//   <i> Shows which pin ADC0_SE9 is mapped to
//     <0=> Disabled
//     <1=> PTF2<selection=PTF2_SIG_SEL,LCD1/ADC0_SE9>
//     <0=> Default
#define ADC0_SE9_PIN_SEL     0
#if ADC0_SE9_PIN_SEL == 1
#define ADC0_SE9_GPIO        digitalIO_PTF2
#define ADC0_SE9_FN          0
#endif

// Pin Mapping for ADC0_SE10 signal
//   <o> ADC0_SE10 [PTG1]<name=ADC0_SE10_PIN_SEL>
//   <i> Shows which pin ADC0_SE10 is mapped to
//     <0=> Disabled
//     <1=> PTG1<selection=PTG1_SIG_SEL,LCD8/ADC0_SE10>
//     <0=> Default
#define ADC0_SE10_PIN_SEL    0
#if ADC0_SE10_PIN_SEL == 1
#define ADC0_SE10_GPIO       digitalIO_PTG1
#define ADC0_SE10_FN         0
#endif

// Pin Mapping for ADC0_SE11 signal
//   <o> ADC0_SE11 [PTG2]<name=ADC0_SE11_PIN_SEL>
//   <i> Shows which pin ADC0_SE11 is mapped to
//     <0=> Disabled
//     <1=> PTG2<selection=PTG2_SIG_SEL,LCD9/ADC0_SE11>
//     <0=> Default
#define ADC0_SE11_PIN_SEL    0
#if ADC0_SE11_PIN_SEL == 1
#define ADC0_SE11_GPIO       digitalIO_PTG2
#define ADC0_SE11_FN         0
#endif

// </h>

// <h> Clock and Timing

// Pin Mapping for AFE_CLK signal
//   <o> AFE_CLK [PTB7, PTE3]<name=AFE_CLK_PIN_SEL>
//   <i> Shows which pin AFE_CLK is mapped to
//     <0=> Disabled
//     <1=> PTB7<selection=PTB7_SIG_SEL,AFE_CLK>
//     <2=> PTE3<selection=PTE3_SIG_SEL,AFE_CLK>
//     <0=> Default
#define AFE_CLK_PIN_SEL      0
#if AFE_CLK_PIN_SEL == 1
#define AFE_CLK_GPIO         digitalIO_PTB7
#define AFE_CLK_FN           2
#elif AFE_CLK_PIN_SEL == 2
#define AFE_CLK_GPIO         digitalIO_PTE3
#define AFE_CLK_FN           3
#endif

// Pin Mapping for CLKOUT signal
//   <o> CLKOUT [PTF7, PTE0]<name=CLKOUT_PIN_SEL>
//   <i> Shows which pin CLKOUT is mapped to
//     <0=> Disabled
//     <1=> PTF7<selection=PTF7_SIG_SEL,CLKOUT>
//     <2=> PTE0<selection=PTE0_SIG_SEL,CLKOUT>
//     <0=> Default
#define CLKOUT_PIN_SEL       0
#if CLKOUT_PIN_SEL == 1
#define CLKOUT_GPIO          digitalIO_PTF7
#define CLKOUT_FN            3
#elif CLKOUT_PIN_SEL == 2
#define CLKOUT_GPIO          digitalIO_PTE0
#define CLKOUT_FN            5
#endif

// Pin Mapping for EXTAL1 signal
//   <o> EXTAL1 [PTE2]<name=EXTAL1_PIN_SEL>
//   <i> Shows which pin EXTAL1 is mapped to
//     <0=> Disabled
//     <1=> PTE2 (reset default)<selection=PTE2_SIG_SEL,EXTAL1 (reset default)>
//     <2=> PTE2<selection=PTE2_SIG_SEL,EXTAL1>
//     <1=> Default
#define EXTAL1_PIN_SEL       1
#if EXTAL1_PIN_SEL == 2
#define EXTAL1_GPIO          digitalIO_PTE2
#define EXTAL1_FN            0
#endif

// Pin Mapping for EXTAL32K signal
//   <o> EXTAL32K [EXTAL32K]<name=EXTAL32K_PIN_SEL><constant>
//   <i> Shows which pin EXTAL32K is mapped to
//     <0=> EXTAL32K<selection=EXTAL32K_SIG_SEL,EXTAL32K>
//     <0=> Default
#define EXTAL32K_PIN_SEL     0
#define EXTAL32K_GPIO        0
#define EXTAL32K_FN          0

// Pin Mapping for RTCCLKOUT signal
//   <o> RTCCLKOUT [PTF0, PTF2]<name=RTCCLKOUT_PIN_SEL>
//   <i> Shows which pin RTCCLKOUT is mapped to
//     <0=> Disabled
//     <1=> PTF0<selection=PTF0_SIG_SEL,RTCCLKOUT>
//     <2=> PTF2<selection=PTF2_SIG_SEL,RTCCLKOUT>
//     <0=> Default
#define RTCCLKOUT_PIN_SEL    0
#if RTCCLKOUT_PIN_SEL == 1
#define RTCCLKOUT_GPIO       digitalIO_PTF0
#define RTCCLKOUT_FN         2
#elif RTCCLKOUT_PIN_SEL == 2
#define RTCCLKOUT_GPIO       digitalIO_PTF2
#define RTCCLKOUT_FN         3
#endif

// Pin Mapping for XTAL1 signal
//   <o> XTAL1 [PTE3]<name=XTAL1_PIN_SEL>
//   <i> Shows which pin XTAL1 is mapped to
//     <0=> Disabled
//     <1=> PTE3 (reset default)<selection=PTE3_SIG_SEL,XTAL1 (reset default)>
//     <2=> PTE3<selection=PTE3_SIG_SEL,XTAL1>
//     <1=> Default
#define XTAL1_PIN_SEL        1
#if XTAL1_PIN_SEL == 2
#define XTAL1_GPIO           digitalIO_PTE3
#define XTAL1_FN             0
#endif

// Pin Mapping for XTAL32K signal
//   <o> XTAL32K [XTAL32K]<name=XTAL32K_PIN_SEL><constant>
//   <i> Shows which pin XTAL32K is mapped to
//     <0=> XTAL32K<selection=XTAL32K_SIG_SEL,XTAL32K>
//     <0=> Default
#define XTAL32K_PIN_SEL      0
#define XTAL32K_GPIO         0
#define XTAL32K_FN           0

// </h>

// <h> Analogue Comparator (CMP0)

// Pin Mapping for CMP0OUT signal
//   <o> CMP0OUT [PTA5, PTF0]<name=CMP0OUT_PIN_SEL>
//   <i> Shows which pin CMP0OUT is mapped to
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,CMP0OUT>
//     <2=> PTF0<selection=PTF0_SIG_SEL,CMP0OUT>
//     <0=> Default
#define CMP0OUT_PIN_SEL      0
#if CMP0OUT_PIN_SEL == 1
#define CMP0OUT_GPIO         digitalIO_PTA5
#define CMP0OUT_FN           2
#elif CMP0OUT_PIN_SEL == 2
#define CMP0OUT_GPIO         digitalIO_PTF0
#define CMP0OUT_FN           4
#endif

// Pin Mapping for CMP0P0 signal
//   <o> CMP0P0 [PTD0]<name=CMP0P0_PIN_SEL>
//   <i> Shows which pin CMP0P0 is mapped to
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,CMP0P0>
//     <0=> Default
#define CMP0P0_PIN_SEL       0
#if CMP0P0_PIN_SEL == 1
#define CMP0P0_GPIO          digitalIO_PTD0
#define CMP0P0_FN            0
#endif

// Pin Mapping for CMP0P1 signal
//   <o> CMP0P1 [PTD2]<name=CMP0P1_PIN_SEL>
//   <i> Shows which pin CMP0P1 is mapped to
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,CMP0P1>
//     <0=> Default
#define CMP0P1_PIN_SEL       0
#if CMP0P1_PIN_SEL == 1
#define CMP0P1_GPIO          digitalIO_PTD2
#define CMP0P1_FN            0
#endif

// Pin Mapping for CMP0P2 signal
//   <o> CMP0P2 [PTE6]<name=CMP0P2_PIN_SEL>
//   <i> Shows which pin CMP0P2 is mapped to
//     <0=> Disabled
//     <1=> PTE6<selection=PTE6_SIG_SEL,CMP0P2>
//     <0=> Default
#define CMP0P2_PIN_SEL       0
#if CMP0P2_PIN_SEL == 1
#define CMP0P2_GPIO          digitalIO_PTE6
#define CMP0P2_FN            0
#endif

// Pin Mapping for CMP0P3 signal
//   <o> CMP0P3 [PTC3]<name=CMP0P3_PIN_SEL>
//   <i> Shows which pin CMP0P3 is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,LCD42/CMP0P3>
//     <0=> Default
#define CMP0P3_PIN_SEL       0
#if CMP0P3_PIN_SEL == 1
#define CMP0P3_GPIO          digitalIO_PTC3
#define CMP0P3_FN            0
#endif

// Pin Mapping for CMP0P4 signal
//   <o> CMP0P4 [PTD7]<name=CMP0P4_PIN_SEL>
//   <i> Shows which pin CMP0P4 is mapped to
//     <0=> Disabled
//     <1=> PTD7<selection=PTD7_SIG_SEL,CMP0P4>
//     <0=> Default
#define CMP0P4_PIN_SEL       0
#if CMP0P4_PIN_SEL == 1
#define CMP0P4_GPIO          digitalIO_PTD7
#define CMP0P4_FN            0
#endif

// Pin Mapping for CMP0P5 signal
//   <o> CMP0P5 [PTI0]<name=CMP0P5_PIN_SEL>
//   <i> Shows which pin CMP0P5 is mapped to
//     <0=> Disabled
//     <1=> PTI0<selection=PTI0_SIG_SEL,CMP0P5>
//     <0=> Default
#define CMP0P5_PIN_SEL       0
#if CMP0P5_PIN_SEL == 1
#define CMP0P5_GPIO          digitalIO_PTI0
#define CMP0P5_FN            0
#endif

// </h>

// <h> Analogue Comparator (CMP1)

// Pin Mapping for CMP1OUT signal
//   <o> CMP1OUT [PTF2, PTD6]<name=CMP1OUT_PIN_SEL>
//   <i> Shows which pin CMP1OUT is mapped to
//     <0=> Disabled
//     <1=> PTF2<selection=PTF2_SIG_SEL,CMP1OUT>
//     <2=> PTD6<selection=PTD6_SIG_SEL,CMP1OUT>
//     <0=> Default
#define CMP1OUT_PIN_SEL      0
#if CMP1OUT_PIN_SEL == 1
#define CMP1OUT_GPIO         digitalIO_PTF2
#define CMP1OUT_FN           2
#elif CMP1OUT_PIN_SEL == 2
#define CMP1OUT_GPIO         digitalIO_PTD6
#define CMP1OUT_FN           3
#endif

// Pin Mapping for CMP1P0 signal
//   <o> CMP1P0 [PTB6]<name=CMP1P0_PIN_SEL>
//   <i> Shows which pin CMP1P0 is mapped to
//     <0=> Disabled
//     <1=> PTB6<selection=PTB6_SIG_SEL,LCD37/CMP1P0>
//     <0=> Default
#define CMP1P0_PIN_SEL       0
#if CMP1P0_PIN_SEL == 1
#define CMP1P0_GPIO          digitalIO_PTB6
#define CMP1P0_FN            0
#endif

// Pin Mapping for CMP1P1 signal
//   <o> CMP1P1 [PTC1]<name=CMP1P1_PIN_SEL>
//   <i> Shows which pin CMP1P1 is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,LCD40/CMP1P1>
//     <0=> Default
#define CMP1P1_PIN_SEL       0
#if CMP1P1_PIN_SEL == 1
#define CMP1P1_GPIO          digitalIO_PTC1
#define CMP1P1_FN            0
#endif

// Pin Mapping for CMP1P2 signal
//   <o> CMP1P2 [SDADP2]<name=CMP1P2_PIN_SEL><constant>
//   <i> Shows which pin CMP1P2 is mapped to
//     <0=> SDADP2<selection=SDADP2_SIG_SEL,SDADP2/CMP1P2>
//     <0=> Default
#define CMP1P2_PIN_SEL       0
#define CMP1P2_GPIO          0
#define CMP1P2_FN            0

// Pin Mapping for CMP1P3 signal
//   <o> CMP1P3 [SDADM2]<name=CMP1P3_PIN_SEL><constant>
//   <i> Shows which pin CMP1P3 is mapped to
//     <0=> SDADM2<selection=SDADM2_SIG_SEL,SDADM2/CMP1P3>
//     <0=> Default
#define CMP1P3_PIN_SEL       0
#define CMP1P3_GPIO          0
#define CMP1P3_FN            0

// Pin Mapping for CMP1P4 signal
//   <o> CMP1P4 [SDADP3]<name=CMP1P4_PIN_SEL><constant>
//   <i> Shows which pin CMP1P4 is mapped to
//     <0=> SDADP3<selection=SDADP3_SIG_SEL,SDADP3/CMP1P4>
//     <0=> Default
#define CMP1P4_PIN_SEL       0
#define CMP1P4_GPIO          0
#define CMP1P4_FN            0

// Pin Mapping for CMP1P5 signal
//   <o> CMP1P5 [SDADM3]<name=CMP1P5_PIN_SEL><constant>
//   <i> Shows which pin CMP1P5 is mapped to
//     <0=> SDADM3<selection=SDADM3_SIG_SEL,SDADM3/CMP1P5>
//     <0=> Default
#define CMP1P5_PIN_SEL       0
#define CMP1P5_GPIO          0
#define CMP1P5_FN            0

// </h>

// <h> External Watchdog Monitor (EWM)

// Pin Mapping for EWM_IN signal
//   <o> EWM_IN [PTE2, PTE4]<name=EWM_IN_PIN_SEL>
//   <i> Shows which pin EWM_IN is mapped to
//     <0=> Disabled
//     <1=> PTE2<selection=PTE2_SIG_SEL,EWM_IN>
//     <2=> PTE4<selection=PTE4_SIG_SEL,EWM_IN>
//     <0=> Default
#define EWM_IN_PIN_SEL       0
#if EWM_IN_PIN_SEL == 1
#define EWM_IN_GPIO          digitalIO_PTE2
#define EWM_IN_FN            2
#elif EWM_IN_PIN_SEL == 2
#define EWM_IN_GPIO          digitalIO_PTE4
#define EWM_IN_FN            4
#endif

// Pin Mapping for EWM_OUT signal
//   <o> EWM_OUT [PTE3, PTE5]<name=EWM_OUT_PIN_SEL>
//   <i> Shows which pin EWM_OUT is mapped to
//     <0=> Disabled
//     <1=> PTE3<selection=PTE3_SIG_SEL,EWM_OUT>
//     <2=> PTE5<selection=PTE5_SIG_SEL,EWM_OUT>
//     <0=> Default
#define EWM_OUT_PIN_SEL      0
#if EWM_OUT_PIN_SEL == 1
#define EWM_OUT_GPIO         digitalIO_PTE3
#define EWM_OUT_FN           2
#elif EWM_OUT_PIN_SEL == 2
#define EWM_OUT_GPIO         digitalIO_PTE5
#define EWM_OUT_FN           4
#endif

// </h>

// <h> General Purpose I/O (GPIOA)

// Pin Mapping for GPIOA_0 signal
//   <o> GPIOA_0 [PTA0]<name=GPIOA_0_PIN_SEL>
//   <i> Shows which pin GPIOA_0 is mapped to
//     <0=> Disabled
//     <1=> PTA0 (Alias:LED_RED)<selection=PTA0_SIG_SEL,GPIOA_0>
//     <1=> Default
#define GPIOA_0_PIN_SEL      1
#if GPIOA_0_PIN_SEL == 1
#define GPIOA_0_GPIO         digitalIO_PTA0
#define GPIOA_0_FN           1
#endif

// Pin Mapping for GPIOA_1 signal
//   <o> GPIOA_1 [PTA1]<name=GPIOA_1_PIN_SEL>
//   <i> Shows which pin GPIOA_1 is mapped to
//     <0=> Disabled
//     <1=> PTA1 (Alias:LED_GREEN)<selection=PTA1_SIG_SEL,GPIOA_1>
//     <1=> Default
#define GPIOA_1_PIN_SEL      1
#if GPIOA_1_PIN_SEL == 1
#define GPIOA_1_GPIO         digitalIO_PTA1
#define GPIOA_1_FN           1
#endif

// Pin Mapping for GPIOA_2 signal
//   <o> GPIOA_2 [PTA2]<name=GPIOA_2_PIN_SEL>
//   <i> Shows which pin GPIOA_2 is mapped to
//     <0=> Disabled
//     <1=> PTA2<selection=PTA2_SIG_SEL,GPIOA_2>
//     <0=> Default
#define GPIOA_2_PIN_SEL      0
#if GPIOA_2_PIN_SEL == 1
#define GPIOA_2_GPIO         digitalIO_PTA2
#define GPIOA_2_FN           1
#endif

// Pin Mapping for GPIOA_3 signal
//   <o> GPIOA_3 [PTA3]<name=GPIOA_3_PIN_SEL>
//   <i> Shows which pin GPIOA_3 is mapped to
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,GPIOA_3>
//     <0=> Default
#define GPIOA_3_PIN_SEL      0
#if GPIOA_3_PIN_SEL == 1
#define GPIOA_3_GPIO         digitalIO_PTA3
#define GPIOA_3_FN           1
#endif

// Pin Mapping for GPIOA_4 signal
//   <o> GPIOA_4 [PTA4]<name=GPIOA_4_PIN_SEL>
//   <i> Shows which pin GPIOA_4 is mapped to
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,GPIOA_4>
//     <0=> Default
#define GPIOA_4_PIN_SEL      0
#if GPIOA_4_PIN_SEL == 1
#define GPIOA_4_GPIO         digitalIO_PTA4
#define GPIOA_4_FN           1
#endif

// Pin Mapping for GPIOA_5 signal
//   <o> GPIOA_5 [PTA5]<name=GPIOA_5_PIN_SEL>
//   <i> Shows which pin GPIOA_5 is mapped to
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,GPIOA_5>
//     <0=> Default
#define GPIOA_5_PIN_SEL      0
#if GPIOA_5_PIN_SEL == 1
#define GPIOA_5_GPIO         digitalIO_PTA5
#define GPIOA_5_FN           1
#endif

// Pin Mapping for GPIOA_6 signal
//   <o> GPIOA_6 [PTA6]<name=GPIOA_6_PIN_SEL>
//   <i> Shows which pin GPIOA_6 is mapped to
//     <0=> Disabled
//     <1=> PTA6<selection=PTA6_SIG_SEL,GPIOA_6>
//     <0=> Default
#define GPIOA_6_PIN_SEL      0
#if GPIOA_6_PIN_SEL == 1
#define GPIOA_6_GPIO         digitalIO_PTA6
#define GPIOA_6_FN           1
#endif

// Pin Mapping for GPIOA_7 signal
//   <o> GPIOA_7 [PTA7]<name=GPIOA_7_PIN_SEL>
//   <i> Shows which pin GPIOA_7 is mapped to
//     <0=> Disabled
//     <1=> PTA7<selection=PTA7_SIG_SEL,GPIOA_7>
//     <0=> Default
#define GPIOA_7_PIN_SEL      0
#if GPIOA_7_PIN_SEL == 1
#define GPIOA_7_GPIO         digitalIO_PTA7
#define GPIOA_7_FN           1
#endif

// </h>

// <h> General Purpose I/O (GPIOB)

// Pin Mapping for GPIOB_0 signal
//   <o> GPIOB_0 [PTB0]<name=GPIOB_0_PIN_SEL>
//   <i> Shows which pin GPIOB_0 is mapped to
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,GPIOB_0>
//     <0=> Default
#define GPIOB_0_PIN_SEL      0
#if GPIOB_0_PIN_SEL == 1
#define GPIOB_0_GPIO         digitalIO_PTB0
#define GPIOB_0_FN           1
#endif

// Pin Mapping for GPIOB_1 signal
//   <o> GPIOB_1 [PTB1]<name=GPIOB_1_PIN_SEL>
//   <i> Shows which pin GPIOB_1 is mapped to
//     <0=> Disabled
//     <1=> PTB1<selection=PTB1_SIG_SEL,GPIOB_1>
//     <0=> Default
#define GPIOB_1_PIN_SEL      0
#if GPIOB_1_PIN_SEL == 1
#define GPIOB_1_GPIO         digitalIO_PTB1
#define GPIOB_1_FN           1
#endif

// Pin Mapping for GPIOB_2 signal
//   <o> GPIOB_2 [PTB2]<name=GPIOB_2_PIN_SEL>
//   <i> Shows which pin GPIOB_2 is mapped to
//     <0=> Disabled
//     <1=> PTB2<selection=PTB2_SIG_SEL,GPIOB_2>
//     <0=> Default
#define GPIOB_2_PIN_SEL      0
#if GPIOB_2_PIN_SEL == 1
#define GPIOB_2_GPIO         digitalIO_PTB2
#define GPIOB_2_FN           1
#endif

// Pin Mapping for GPIOB_3 signal
//   <o> GPIOB_3 [PTB3]<name=GPIOB_3_PIN_SEL>
//   <i> Shows which pin GPIOB_3 is mapped to
//     <0=> Disabled
//     <1=> PTB3<selection=PTB3_SIG_SEL,GPIOB_3>
//     <0=> Default
#define GPIOB_3_PIN_SEL      0
#if GPIOB_3_PIN_SEL == 1
#define GPIOB_3_GPIO         digitalIO_PTB3
#define GPIOB_3_FN           1
#endif

// Pin Mapping for GPIOB_4 signal
//   <o> GPIOB_4 [PTB4]<name=GPIOB_4_PIN_SEL>
//   <i> Shows which pin GPIOB_4 is mapped to
//     <0=> Disabled
//     <1=> PTB4<selection=PTB4_SIG_SEL,GPIOB_4>
//     <0=> Default
#define GPIOB_4_PIN_SEL      0
#if GPIOB_4_PIN_SEL == 1
#define GPIOB_4_GPIO         digitalIO_PTB4
#define GPIOB_4_FN           1
#endif

// Pin Mapping for GPIOB_5 signal
//   <o> GPIOB_5 [PTB5]<name=GPIOB_5_PIN_SEL>
//   <i> Shows which pin GPIOB_5 is mapped to
//     <0=> Disabled
//     <1=> PTB5<selection=PTB5_SIG_SEL,GPIOB_5>
//     <0=> Default
#define GPIOB_5_PIN_SEL      0
#if GPIOB_5_PIN_SEL == 1
#define GPIOB_5_GPIO         digitalIO_PTB5
#define GPIOB_5_FN           1
#endif

// Pin Mapping for GPIOB_6 signal
//   <o> GPIOB_6 [PTB6]<name=GPIOB_6_PIN_SEL>
//   <i> Shows which pin GPIOB_6 is mapped to
//     <0=> Disabled
//     <1=> PTB6<selection=PTB6_SIG_SEL,GPIOB_6>
//     <0=> Default
#define GPIOB_6_PIN_SEL      0
#if GPIOB_6_PIN_SEL == 1
#define GPIOB_6_GPIO         digitalIO_PTB6
#define GPIOB_6_FN           1
#endif

// Pin Mapping for GPIOB_7 signal
//   <o> GPIOB_7 [PTB7]<name=GPIOB_7_PIN_SEL>
//   <i> Shows which pin GPIOB_7 is mapped to
//     <0=> Disabled
//     <1=> PTB7<selection=PTB7_SIG_SEL,GPIOB_7>
//     <0=> Default
#define GPIOB_7_PIN_SEL      0
#if GPIOB_7_PIN_SEL == 1
#define GPIOB_7_GPIO         digitalIO_PTB7
#define GPIOB_7_FN           1
#endif

// </h>

// <h> General Purpose I/O (GPIOC)

// Pin Mapping for GPIOC_0 signal
//   <o> GPIOC_0 [PTC0]<name=GPIOC_0_PIN_SEL>
//   <i> Shows which pin GPIOC_0 is mapped to
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,GPIOC_0>
//     <0=> Default
#define GPIOC_0_PIN_SEL      0
#if GPIOC_0_PIN_SEL == 1
#define GPIOC_0_GPIO         digitalIO_PTC0
#define GPIOC_0_FN           1
#endif

// Pin Mapping for GPIOC_1 signal
//   <o> GPIOC_1 [PTC1]<name=GPIOC_1_PIN_SEL>
//   <i> Shows which pin GPIOC_1 is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,GPIOC_1>
//     <0=> Default
#define GPIOC_1_PIN_SEL      0
#if GPIOC_1_PIN_SEL == 1
#define GPIOC_1_GPIO         digitalIO_PTC1
#define GPIOC_1_FN           1
#endif

// Pin Mapping for GPIOC_2 signal
//   <o> GPIOC_2 [PTC2]<name=GPIOC_2_PIN_SEL>
//   <i> Shows which pin GPIOC_2 is mapped to
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,GPIOC_2>
//     <0=> Default
#define GPIOC_2_PIN_SEL      0
#if GPIOC_2_PIN_SEL == 1
#define GPIOC_2_GPIO         digitalIO_PTC2
#define GPIOC_2_FN           1
#endif

// Pin Mapping for GPIOC_3 signal
//   <o> GPIOC_3 [PTC3]<name=GPIOC_3_PIN_SEL>
//   <i> Shows which pin GPIOC_3 is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,GPIOC_3>
//     <0=> Default
#define GPIOC_3_PIN_SEL      0
#if GPIOC_3_PIN_SEL == 1
#define GPIOC_3_GPIO         digitalIO_PTC3
#define GPIOC_3_FN           1
#endif

// Pin Mapping for GPIOC_4 signal
//   <o> GPIOC_4 [PTC4]<name=GPIOC_4_PIN_SEL>
//   <i> Shows which pin GPIOC_4 is mapped to
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,GPIOC_4>
//     <0=> Default
#define GPIOC_4_PIN_SEL      0
#if GPIOC_4_PIN_SEL == 1
#define GPIOC_4_GPIO         digitalIO_PTC4
#define GPIOC_4_FN           1
#endif

// Pin Mapping for GPIOC_5 signal
//   <o> GPIOC_5 [PTC5]<name=GPIOC_5_PIN_SEL>
//   <i> Shows which pin GPIOC_5 is mapped to
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,GPIOC_5>
//     <0=> Default
#define GPIOC_5_PIN_SEL      0
#if GPIOC_5_PIN_SEL == 1
#define GPIOC_5_GPIO         digitalIO_PTC5
#define GPIOC_5_FN           1
#endif

// Pin Mapping for GPIOC_6 signal
//   <o> GPIOC_6 [PTC6]<name=GPIOC_6_PIN_SEL>
//   <i> Shows which pin GPIOC_6 is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,GPIOC_6>
//     <0=> Default
#define GPIOC_6_PIN_SEL      0
#if GPIOC_6_PIN_SEL == 1
#define GPIOC_6_GPIO         digitalIO_PTC6
#define GPIOC_6_FN           1
#endif

// Pin Mapping for GPIOC_7 signal
//   <o> GPIOC_7 [PTC7]<name=GPIOC_7_PIN_SEL>
//   <i> Shows which pin GPIOC_7 is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,GPIOC_7>
//     <0=> Default
#define GPIOC_7_PIN_SEL      0
#if GPIOC_7_PIN_SEL == 1
#define GPIOC_7_GPIO         digitalIO_PTC7
#define GPIOC_7_FN           1
#endif

// </h>

// <h> General Purpose I/O (GPIOD)

// Pin Mapping for GPIOD_0 signal
//   <o> GPIOD_0 [PTD0]<name=GPIOD_0_PIN_SEL>
//   <i> Shows which pin GPIOD_0 is mapped to
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,GPIOD_0>
//     <0=> Default
#define GPIOD_0_PIN_SEL      0
#if GPIOD_0_PIN_SEL == 1
#define GPIOD_0_GPIO         digitalIO_PTD0
#define GPIOD_0_FN           1
#endif

// Pin Mapping for GPIOD_1 signal
//   <o> GPIOD_1 [PTD1]<name=GPIOD_1_PIN_SEL>
//   <i> Shows which pin GPIOD_1 is mapped to
//     <0=> Disabled
//     <1=> PTD1 (Alias:LED_BLUE)<selection=PTD1_SIG_SEL,GPIOD_1>
//     <1=> Default
#define GPIOD_1_PIN_SEL      1
#if GPIOD_1_PIN_SEL == 1
#define GPIOD_1_GPIO         digitalIO_PTD1
#define GPIOD_1_FN           1
#endif

// Pin Mapping for GPIOD_2 signal
//   <o> GPIOD_2 [PTD2]<name=GPIOD_2_PIN_SEL>
//   <i> Shows which pin GPIOD_2 is mapped to
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,GPIOD_2>
//     <0=> Default
#define GPIOD_2_PIN_SEL      0
#if GPIOD_2_PIN_SEL == 1
#define GPIOD_2_GPIO         digitalIO_PTD2
#define GPIOD_2_FN           1
#endif

// Pin Mapping for GPIOD_3 signal
//   <o> GPIOD_3 [PTD3]<name=GPIOD_3_PIN_SEL>
//   <i> Shows which pin GPIOD_3 is mapped to
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,GPIOD_3>
//     <0=> Default
#define GPIOD_3_PIN_SEL      0
#if GPIOD_3_PIN_SEL == 1
#define GPIOD_3_GPIO         digitalIO_PTD3
#define GPIOD_3_FN           1
#endif

// Pin Mapping for GPIOD_4 signal
//   <o> GPIOD_4 [PTD4]<name=GPIOD_4_PIN_SEL>
//   <i> Shows which pin GPIOD_4 is mapped to
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,GPIOD_4>
//     <0=> Default
#define GPIOD_4_PIN_SEL      0
#if GPIOD_4_PIN_SEL == 1
#define GPIOD_4_GPIO         digitalIO_PTD4
#define GPIOD_4_FN           1
#endif

// Pin Mapping for GPIOD_5 signal
//   <o> GPIOD_5 [PTD5]<name=GPIOD_5_PIN_SEL>
//   <i> Shows which pin GPIOD_5 is mapped to
//     <0=> Disabled
//     <1=> PTD5<selection=PTD5_SIG_SEL,GPIOD_5>
//     <0=> Default
#define GPIOD_5_PIN_SEL      0
#if GPIOD_5_PIN_SEL == 1
#define GPIOD_5_GPIO         digitalIO_PTD5
#define GPIOD_5_FN           1
#endif

// Pin Mapping for GPIOD_6 signal
//   <o> GPIOD_6 [PTD6]<name=GPIOD_6_PIN_SEL>
//   <i> Shows which pin GPIOD_6 is mapped to
//     <0=> Disabled
//     <1=> PTD6<selection=PTD6_SIG_SEL,GPIOD_6>
//     <0=> Default
#define GPIOD_6_PIN_SEL      0
#if GPIOD_6_PIN_SEL == 1
#define GPIOD_6_GPIO         digitalIO_PTD6
#define GPIOD_6_FN           1
#endif

// Pin Mapping for GPIOD_7 signal
//   <o> GPIOD_7 [PTD7]<name=GPIOD_7_PIN_SEL>
//   <i> Shows which pin GPIOD_7 is mapped to
//     <0=> Disabled
//     <1=> PTD7<selection=PTD7_SIG_SEL,GPIOD_7>
//     <0=> Default
#define GPIOD_7_PIN_SEL      0
#if GPIOD_7_PIN_SEL == 1
#define GPIOD_7_GPIO         digitalIO_PTD7
#define GPIOD_7_FN           1
#endif

// </h>

// <h> General Purpose I/O (GPIOE)

// Pin Mapping for GPIOE_0 signal
//   <o> GPIOE_0 [PTE0]<name=GPIOE_0_PIN_SEL>
//   <i> Shows which pin GPIOE_0 is mapped to
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,GPIOE_0>
//     <0=> Default
#define GPIOE_0_PIN_SEL      0
#if GPIOE_0_PIN_SEL == 1
#define GPIOE_0_GPIO         digitalIO_PTE0
#define GPIOE_0_FN           1
#endif

// Pin Mapping for GPIOE_1 signal
//   <o> GPIOE_1 [PTE1]<name=GPIOE_1_PIN_SEL>
//   <i> Shows which pin GPIOE_1 is mapped to
//     <0=> Disabled
//     <1=> PTE1<selection=PTE1_SIG_SEL,GPIOE_1>
//     <0=> Default
#define GPIOE_1_PIN_SEL      0
#if GPIOE_1_PIN_SEL == 1
#define GPIOE_1_GPIO         digitalIO_PTE1
#define GPIOE_1_FN           1
#endif

// Pin Mapping for GPIOE_2 signal
//   <o> GPIOE_2 [PTE2]<name=GPIOE_2_PIN_SEL>
//   <i> Shows which pin GPIOE_2 is mapped to
//     <0=> Disabled
//     <1=> PTE2<selection=PTE2_SIG_SEL,GPIOE_2>
//     <0=> Default
#define GPIOE_2_PIN_SEL      0
#if GPIOE_2_PIN_SEL == 1
#define GPIOE_2_GPIO         digitalIO_PTE2
#define GPIOE_2_FN           1
#endif

// Pin Mapping for GPIOE_3 signal
//   <o> GPIOE_3 [PTE3]<name=GPIOE_3_PIN_SEL>
//   <i> Shows which pin GPIOE_3 is mapped to
//     <0=> Disabled
//     <1=> PTE3<selection=PTE3_SIG_SEL,GPIOE_3>
//     <0=> Default
#define GPIOE_3_PIN_SEL      0
#if GPIOE_3_PIN_SEL == 1
#define GPIOE_3_GPIO         digitalIO_PTE3
#define GPIOE_3_FN           1
#endif

// Pin Mapping for GPIOE_4 signal
//   <o> GPIOE_4 [PTE4]<name=GPIOE_4_PIN_SEL>
//   <i> Shows which pin GPIOE_4 is mapped to
//     <0=> Disabled
//     <1=> PTE4<selection=PTE4_SIG_SEL,GPIOE_4>
//     <0=> Default
#define GPIOE_4_PIN_SEL      0
#if GPIOE_4_PIN_SEL == 1
#define GPIOE_4_GPIO         digitalIO_PTE4
#define GPIOE_4_FN           1
#endif

// Pin Mapping for GPIOE_5 signal
//   <o> GPIOE_5 [PTE5]<name=GPIOE_5_PIN_SEL>
//   <i> Shows which pin GPIOE_5 is mapped to
//     <0=> Disabled
//     <1=> PTE5<selection=PTE5_SIG_SEL,GPIOE_5>
//     <0=> Default
#define GPIOE_5_PIN_SEL      0
#if GPIOE_5_PIN_SEL == 1
#define GPIOE_5_GPIO         digitalIO_PTE5
#define GPIOE_5_FN           1
#endif

// Pin Mapping for GPIOE_6 signal
//   <o> GPIOE_6 [PTE6]<name=GPIOE_6_PIN_SEL>
//   <i> Shows which pin GPIOE_6 is mapped to
//     <0=> Disabled
//     <1=> PTE6<selection=PTE6_SIG_SEL,GPIOE_6>
//     <0=> Default
#define GPIOE_6_PIN_SEL      0
#if GPIOE_6_PIN_SEL == 1
#define GPIOE_6_GPIO         digitalIO_PTE6
#define GPIOE_6_FN           1
#endif

// Pin Mapping for GPIOE_7 signal
//   <o> GPIOE_7 [PTE7]<name=GPIOE_7_PIN_SEL>
//   <i> Shows which pin GPIOE_7 is mapped to
//     <0=> Disabled
//     <1=> PTE7<selection=PTE7_SIG_SEL,GPIOE_7>
//     <0=> Default
#define GPIOE_7_PIN_SEL      0
#if GPIOE_7_PIN_SEL == 1
#define GPIOE_7_GPIO         digitalIO_PTE7
#define GPIOE_7_FN           1
#endif

// </h>

// <h> General Purpose I/O (GPIOF)

// Pin Mapping for GPIOF_0 signal
//   <o> GPIOF_0 [PTF0]<name=GPIOF_0_PIN_SEL>
//   <i> Shows which pin GPIOF_0 is mapped to
//     <0=> Disabled
//     <1=> PTF0<selection=PTF0_SIG_SEL,GPIOF_0>
//     <0=> Default
#define GPIOF_0_PIN_SEL      0
#if GPIOF_0_PIN_SEL == 1
#define GPIOF_0_GPIO         digitalIO_PTF0
#define GPIOF_0_FN           1
#endif

// Pin Mapping for GPIOF_1 signal
//   <o> GPIOF_1 [PTF1]<name=GPIOF_1_PIN_SEL>
//   <i> Shows which pin GPIOF_1 is mapped to
//     <0=> Disabled
//     <1=> PTF1<selection=PTF1_SIG_SEL,GPIOF_1>
//     <0=> Default
#define GPIOF_1_PIN_SEL      0
#if GPIOF_1_PIN_SEL == 1
#define GPIOF_1_GPIO         digitalIO_PTF1
#define GPIOF_1_FN           1
#endif

// Pin Mapping for GPIOF_2 signal
//   <o> GPIOF_2 [PTF2]<name=GPIOF_2_PIN_SEL>
//   <i> Shows which pin GPIOF_2 is mapped to
//     <0=> Disabled
//     <1=> PTF2<selection=PTF2_SIG_SEL,GPIOF_2>
//     <0=> Default
#define GPIOF_2_PIN_SEL      0
#if GPIOF_2_PIN_SEL == 1
#define GPIOF_2_GPIO         digitalIO_PTF2
#define GPIOF_2_FN           1
#endif

// Pin Mapping for GPIOF_3 signal
//   <o> GPIOF_3 [PTF3]<name=GPIOF_3_PIN_SEL>
//   <i> Shows which pin GPIOF_3 is mapped to
//     <0=> Disabled
//     <1=> PTF3<selection=PTF3_SIG_SEL,GPIOF_3>
//     <0=> Default
#define GPIOF_3_PIN_SEL      0
#if GPIOF_3_PIN_SEL == 1
#define GPIOF_3_GPIO         digitalIO_PTF3
#define GPIOF_3_FN           1
#endif

// Pin Mapping for GPIOF_4 signal
//   <o> GPIOF_4 [PTF4]<name=GPIOF_4_PIN_SEL>
//   <i> Shows which pin GPIOF_4 is mapped to
//     <0=> Disabled
//     <1=> PTF4<selection=PTF4_SIG_SEL,GPIOF_4>
//     <0=> Default
#define GPIOF_4_PIN_SEL      0
#if GPIOF_4_PIN_SEL == 1
#define GPIOF_4_GPIO         digitalIO_PTF4
#define GPIOF_4_FN           1
#endif

// Pin Mapping for GPIOF_5 signal
//   <o> GPIOF_5 [PTF5]<name=GPIOF_5_PIN_SEL>
//   <i> Shows which pin GPIOF_5 is mapped to
//     <0=> Disabled
//     <1=> PTF5<selection=PTF5_SIG_SEL,GPIOF_5>
//     <0=> Default
#define GPIOF_5_PIN_SEL      0
#if GPIOF_5_PIN_SEL == 1
#define GPIOF_5_GPIO         digitalIO_PTF5
#define GPIOF_5_FN           1
#endif

// Pin Mapping for GPIOF_6 signal
//   <o> GPIOF_6 [PTF6]<name=GPIOF_6_PIN_SEL>
//   <i> Shows which pin GPIOF_6 is mapped to
//     <0=> Disabled
//     <1=> PTF6<selection=PTF6_SIG_SEL,GPIOF_6>
//     <0=> Default
#define GPIOF_6_PIN_SEL      0
#if GPIOF_6_PIN_SEL == 1
#define GPIOF_6_GPIO         digitalIO_PTF6
#define GPIOF_6_FN           1
#endif

// Pin Mapping for GPIOF_7 signal
//   <o> GPIOF_7 [PTF7]<name=GPIOF_7_PIN_SEL>
//   <i> Shows which pin GPIOF_7 is mapped to
//     <0=> Disabled
//     <1=> PTF7<selection=PTF7_SIG_SEL,GPIOF_7>
//     <0=> Default
#define GPIOF_7_PIN_SEL      0
#if GPIOF_7_PIN_SEL == 1
#define GPIOF_7_GPIO         digitalIO_PTF7
#define GPIOF_7_FN           1
#endif

// </h>

// <h> General Purpose I/O (GPIOG)

// Pin Mapping for GPIOG_0 signal
//   <o> GPIOG_0 [PTG0]<name=GPIOG_0_PIN_SEL>
//   <i> Shows which pin GPIOG_0 is mapped to
//     <0=> Disabled
//     <1=> PTG0<selection=PTG0_SIG_SEL,GPIOG_0>
//     <0=> Default
#define GPIOG_0_PIN_SEL      0
#if GPIOG_0_PIN_SEL == 1
#define GPIOG_0_GPIO         digitalIO_PTG0
#define GPIOG_0_FN           1
#endif

// Pin Mapping for GPIOG_1 signal
//   <o> GPIOG_1 [PTG1]<name=GPIOG_1_PIN_SEL>
//   <i> Shows which pin GPIOG_1 is mapped to
//     <0=> Disabled
//     <1=> PTG1<selection=PTG1_SIG_SEL,GPIOG_1>
//     <0=> Default
#define GPIOG_1_PIN_SEL      0
#if GPIOG_1_PIN_SEL == 1
#define GPIOG_1_GPIO         digitalIO_PTG1
#define GPIOG_1_FN           1
#endif

// Pin Mapping for GPIOG_2 signal
//   <o> GPIOG_2 [PTG2]<name=GPIOG_2_PIN_SEL>
//   <i> Shows which pin GPIOG_2 is mapped to
//     <0=> Disabled
//     <1=> PTG2<selection=PTG2_SIG_SEL,GPIOG_2>
//     <0=> Default
#define GPIOG_2_PIN_SEL      0
#if GPIOG_2_PIN_SEL == 1
#define GPIOG_2_GPIO         digitalIO_PTG2
#define GPIOG_2_FN           1
#endif

// Pin Mapping for GPIOG_3 signal
//   <o> GPIOG_3 [PTG3]<name=GPIOG_3_PIN_SEL>
//   <i> Shows which pin GPIOG_3 is mapped to
//     <0=> Disabled
//     <1=> PTG3<selection=PTG3_SIG_SEL,GPIOG_3>
//     <0=> Default
#define GPIOG_3_PIN_SEL      0
#if GPIOG_3_PIN_SEL == 1
#define GPIOG_3_GPIO         digitalIO_PTG3
#define GPIOG_3_FN           1
#endif

// Pin Mapping for GPIOG_4 signal
//   <o> GPIOG_4 [PTG4]<name=GPIOG_4_PIN_SEL>
//   <i> Shows which pin GPIOG_4 is mapped to
//     <0=> Disabled
//     <1=> PTG4<selection=PTG4_SIG_SEL,GPIOG_4>
//     <0=> Default
#define GPIOG_4_PIN_SEL      0
#if GPIOG_4_PIN_SEL == 1
#define GPIOG_4_GPIO         digitalIO_PTG4
#define GPIOG_4_FN           1
#endif

// Pin Mapping for GPIOG_5 signal
//   <o> GPIOG_5 [PTG5]<name=GPIOG_5_PIN_SEL>
//   <i> Shows which pin GPIOG_5 is mapped to
//     <0=> Disabled
//     <1=> PTG5<selection=PTG5_SIG_SEL,GPIOG_5>
//     <0=> Default
#define GPIOG_5_PIN_SEL      0
#if GPIOG_5_PIN_SEL == 1
#define GPIOG_5_GPIO         digitalIO_PTG5
#define GPIOG_5_FN           1
#endif

// Pin Mapping for GPIOG_6 signal
//   <o> GPIOG_6 [PTG6]<name=GPIOG_6_PIN_SEL>
//   <i> Shows which pin GPIOG_6 is mapped to
//     <0=> Disabled
//     <1=> PTG6<selection=PTG6_SIG_SEL,GPIOG_6>
//     <0=> Default
#define GPIOG_6_PIN_SEL      0
#if GPIOG_6_PIN_SEL == 1
#define GPIOG_6_GPIO         digitalIO_PTG6
#define GPIOG_6_FN           1
#endif

// Pin Mapping for GPIOG_7 signal
//   <o> GPIOG_7 [PTG7]<name=GPIOG_7_PIN_SEL>
//   <i> Shows which pin GPIOG_7 is mapped to
//     <0=> Disabled
//     <1=> PTG7<selection=PTG7_SIG_SEL,GPIOG_7>
//     <0=> Default
#define GPIOG_7_PIN_SEL      0
#if GPIOG_7_PIN_SEL == 1
#define GPIOG_7_GPIO         digitalIO_PTG7
#define GPIOG_7_FN           1
#endif

// </h>

// <h> General Purpose I/O (GPIOH)

// Pin Mapping for GPIOH_0 signal
//   <o> GPIOH_0 [PTH0]<name=GPIOH_0_PIN_SEL>
//   <i> Shows which pin GPIOH_0 is mapped to
//     <0=> Disabled
//     <1=> PTH0<selection=PTH0_SIG_SEL,GPIOH_0>
//     <0=> Default
#define GPIOH_0_PIN_SEL      0
#if GPIOH_0_PIN_SEL == 1
#define GPIOH_0_GPIO         digitalIO_PTH0
#define GPIOH_0_FN           1
#endif

// Pin Mapping for GPIOH_1 signal
//   <o> GPIOH_1 [PTH1]<name=GPIOH_1_PIN_SEL>
//   <i> Shows which pin GPIOH_1 is mapped to
//     <0=> Disabled
//     <1=> PTH1<selection=PTH1_SIG_SEL,GPIOH_1>
//     <0=> Default
#define GPIOH_1_PIN_SEL      0
#if GPIOH_1_PIN_SEL == 1
#define GPIOH_1_GPIO         digitalIO_PTH1
#define GPIOH_1_FN           1
#endif

// Pin Mapping for GPIOH_2 signal
//   <o> GPIOH_2 [PTH2]<name=GPIOH_2_PIN_SEL>
//   <i> Shows which pin GPIOH_2 is mapped to
//     <0=> Disabled
//     <1=> PTH2<selection=PTH2_SIG_SEL,GPIOH_2>
//     <0=> Default
#define GPIOH_2_PIN_SEL      0
#if GPIOH_2_PIN_SEL == 1
#define GPIOH_2_GPIO         digitalIO_PTH2
#define GPIOH_2_FN           1
#endif

// Pin Mapping for GPIOH_3 signal
//   <o> GPIOH_3 [PTH3]<name=GPIOH_3_PIN_SEL>
//   <i> Shows which pin GPIOH_3 is mapped to
//     <0=> Disabled
//     <1=> PTH3<selection=PTH3_SIG_SEL,GPIOH_3>
//     <0=> Default
#define GPIOH_3_PIN_SEL      0
#if GPIOH_3_PIN_SEL == 1
#define GPIOH_3_GPIO         digitalIO_PTH3
#define GPIOH_3_FN           1
#endif

// Pin Mapping for GPIOH_4 signal
//   <o> GPIOH_4 [PTH4]<name=GPIOH_4_PIN_SEL>
//   <i> Shows which pin GPIOH_4 is mapped to
//     <0=> Disabled
//     <1=> PTH4<selection=PTH4_SIG_SEL,GPIOH_4>
//     <0=> Default
#define GPIOH_4_PIN_SEL      0
#if GPIOH_4_PIN_SEL == 1
#define GPIOH_4_GPIO         digitalIO_PTH4
#define GPIOH_4_FN           1
#endif

// Pin Mapping for GPIOH_5 signal
//   <o> GPIOH_5 [PTH5]<name=GPIOH_5_PIN_SEL>
//   <i> Shows which pin GPIOH_5 is mapped to
//     <0=> Disabled
//     <1=> PTH5<selection=PTH5_SIG_SEL,GPIOH_5>
//     <0=> Default
#define GPIOH_5_PIN_SEL      0
#if GPIOH_5_PIN_SEL == 1
#define GPIOH_5_GPIO         digitalIO_PTH5
#define GPIOH_5_FN           1
#endif

// Pin Mapping for GPIOH_6 signal
//   <o> GPIOH_6 [PTH6]<name=GPIOH_6_PIN_SEL>
//   <i> Shows which pin GPIOH_6 is mapped to
//     <0=> Disabled
//     <1=> PTH6<selection=PTH6_SIG_SEL,GPIOH_6>
//     <0=> Default
#define GPIOH_6_PIN_SEL      0
#if GPIOH_6_PIN_SEL == 1
#define GPIOH_6_GPIO         digitalIO_PTH6
#define GPIOH_6_FN           1
#endif

// Pin Mapping for GPIOH_7 signal
//   <o> GPIOH_7 [PTH7]<name=GPIOH_7_PIN_SEL>
//   <i> Shows which pin GPIOH_7 is mapped to
//     <0=> Disabled
//     <1=> PTH7<selection=PTH7_SIG_SEL,GPIOH_7>
//     <0=> Default
#define GPIOH_7_PIN_SEL      0
#if GPIOH_7_PIN_SEL == 1
#define GPIOH_7_GPIO         digitalIO_PTH7
#define GPIOH_7_FN           1
#endif

// </h>

// <h> General Purpose I/O (GPIOI)

// Pin Mapping for GPIOI_0 signal
//   <o> GPIOI_0 [PTI0]<name=GPIOI_0_PIN_SEL>
//   <i> Shows which pin GPIOI_0 is mapped to
//     <0=> Disabled
//     <1=> PTI0<selection=PTI0_SIG_SEL,GPIOI_0>
//     <0=> Default
#define GPIOI_0_PIN_SEL      0
#if GPIOI_0_PIN_SEL == 1
#define GPIOI_0_GPIO         digitalIO_PTI0
#define GPIOI_0_FN           1
#endif

// Pin Mapping for GPIOI_1 signal
//   <o> GPIOI_1 [PTI1]<name=GPIOI_1_PIN_SEL>
//   <i> Shows which pin GPIOI_1 is mapped to
//     <0=> Disabled
//     <1=> PTI1<selection=PTI1_SIG_SEL,GPIOI_1>
//     <0=> Default
#define GPIOI_1_PIN_SEL      0
#if GPIOI_1_PIN_SEL == 1
#define GPIOI_1_GPIO         digitalIO_PTI1
#define GPIOI_1_FN           1
#endif

// Pin Mapping for GPIOI_2 signal
//   <o> GPIOI_2 [PTI2]<name=GPIOI_2_PIN_SEL>
//   <i> Shows which pin GPIOI_2 is mapped to
//     <0=> Disabled
//     <1=> PTI2<selection=PTI2_SIG_SEL,GPIOI_2>
//     <0=> Default
#define GPIOI_2_PIN_SEL      0
#if GPIOI_2_PIN_SEL == 1
#define GPIOI_2_GPIO         digitalIO_PTI2
#define GPIOI_2_FN           1
#endif

// Pin Mapping for GPIOI_3 signal
//   <o> GPIOI_3 [PTI3]<name=GPIOI_3_PIN_SEL>
//   <i> Shows which pin GPIOI_3 is mapped to
//     <0=> Disabled
//     <1=> PTI3<selection=PTI3_SIG_SEL,GPIOI_3>
//     <0=> Default
#define GPIOI_3_PIN_SEL      0
#if GPIOI_3_PIN_SEL == 1
#define GPIOI_3_GPIO         digitalIO_PTI3
#define GPIOI_3_FN           1
#endif

// </h>

// <h> Inter-Integrated Circuit (I2C0)

// Pin Mapping for I2C0_SCL signal
//   <o> I2C0_SCL [PTD7, PTG3, PTE6]<name=I2C0_SCL_PIN_SEL>
//   <i> Shows which pin I2C0_SCL is mapped to
//     <0=> Disabled
//     <1=> PTD7<selection=PTD7_SIG_SEL,I2C0_SCL>
//     <2=> PTG3<selection=PTG3_SIG_SEL,I2C0_SCL>
//     <3=> PTE6<selection=PTE6_SIG_SEL,I2C0_SCL>
//     <0=> Default
#define I2C0_SCL_PIN_SEL     0
#if I2C0_SCL_PIN_SEL == 1
#define I2C0_SCL_GPIO        digitalIO_PTD7
#define I2C0_SCL_FN          2
#elif I2C0_SCL_PIN_SEL == 2
#define I2C0_SCL_GPIO        digitalIO_PTG3
#define I2C0_SCL_FN          3
#elif I2C0_SCL_PIN_SEL == 3
#define I2C0_SCL_GPIO        digitalIO_PTE6
#define I2C0_SCL_FN          5
#endif

// Pin Mapping for I2C0_SDA signal
//   <o> I2C0_SDA [PTE0, PTG4, PTE7]<name=I2C0_SDA_PIN_SEL>
//   <i> Shows which pin I2C0_SDA is mapped to
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,I2C0_SDA>
//     <2=> PTG4<selection=PTG4_SIG_SEL,I2C0_SDA>
//     <3=> PTE7<selection=PTE7_SIG_SEL,I2C0_SDA>
//     <0=> Default
#define I2C0_SDA_PIN_SEL     0
#if I2C0_SDA_PIN_SEL == 1
#define I2C0_SDA_GPIO        digitalIO_PTE0
#define I2C0_SDA_FN          2
#elif I2C0_SDA_PIN_SEL == 2
#define I2C0_SDA_GPIO        digitalIO_PTG4
#define I2C0_SDA_FN          3
#elif I2C0_SDA_PIN_SEL == 3
#define I2C0_SDA_GPIO        digitalIO_PTE7
#define I2C0_SDA_FN          5
#endif

// </h>

// <h> Inter-Integrated Circuit (I2C1)

// Pin Mapping for I2C1_SDA signal
//   <o> I2C1_SDA [PTF6, PTE2]<name=I2C1_SDA_PIN_SEL>
//   <i> Shows which pin I2C1_SDA is mapped to
//     <0=> Disabled
//     <1=> PTF6<selection=PTF6_SIG_SEL,I2C1_SDA>
//     <2=> PTE2<selection=PTE2_SIG_SEL,I2C1_SDA>
//     <0=> Default
#define I2C1_SDA_PIN_SEL     0
#if I2C1_SDA_PIN_SEL == 1
#define I2C1_SDA_GPIO        digitalIO_PTF6
#define I2C1_SDA_FN          3
#elif I2C1_SDA_PIN_SEL == 2
#define I2C1_SDA_GPIO        digitalIO_PTE2
#define I2C1_SDA_FN          4
#endif

// Pin Mapping for I2C1_SCL signal
//   <o> I2C1_SCL [PTF5, PTE3]<name=I2C1_SCL_PIN_SEL>
//   <i> Shows which pin I2C1_SCL is mapped to
//     <0=> Disabled
//     <1=> PTF5<selection=PTF5_SIG_SEL,I2C1_SCL>
//     <2=> PTE3<selection=PTE3_SIG_SEL,I2C1_SCL>
//     <0=> Default
#define I2C1_SCL_PIN_SEL     0
#if I2C1_SCL_PIN_SEL == 1
#define I2C1_SCL_GPIO        digitalIO_PTF5
#define I2C1_SCL_FN          3
#elif I2C1_SCL_PIN_SEL == 2
#define I2C1_SCL_GPIO        digitalIO_PTE3
#define I2C1_SCL_FN          4
#endif

// </h>

// <h> Low-Leakage Wake-up Unit (LLWU)

// Pin Mapping for LLWU_P0 signal
//   <o> LLWU_P0 [PTG6]<name=LLWU_P0_PIN_SEL>
//   <i> Shows which pin LLWU_P0 is mapped to
//     <0=> Disabled
//     <1=> PTG6<selection=PTG6_SIG_SEL,LLWU_P0>
//     <0=> Default
#define LLWU_P0_PIN_SEL      0
#if LLWU_P0_PIN_SEL == 1
#define LLWU_P0_GPIO         digitalIO_PTG6
#define LLWU_P0_FN           2
#endif

// Pin Mapping for LLWU_P1 signal
//   <o> LLWU_P1 [PTG2]<name=LLWU_P1_PIN_SEL>
//   <i> Shows which pin LLWU_P1 is mapped to
//     <0=> Disabled
//     <1=> PTG2<selection=PTG2_SIG_SEL,LLWU_P1>
//     <0=> Default
#define LLWU_P1_PIN_SEL      0
#if LLWU_P1_PIN_SEL == 1
#define LLWU_P1_GPIO         digitalIO_PTG2
#define LLWU_P1_FN           3
#endif

// Pin Mapping for LLWU_P2 signal
//   <o> LLWU_P2 [PTG1]<name=LLWU_P2_PIN_SEL>
//   <i> Shows which pin LLWU_P2 is mapped to
//     <0=> Disabled
//     <1=> PTG1<selection=PTG1_SIG_SEL,LLWU_P2>
//     <0=> Default
#define LLWU_P2_PIN_SEL      0
#if LLWU_P2_PIN_SEL == 1
#define LLWU_P2_GPIO         digitalIO_PTG1
#define LLWU_P2_FN           2
#endif

// Pin Mapping for LLWU_P3 signal
//   <o> LLWU_P3 [PTF6]<name=LLWU_P3_PIN_SEL>
//   <i> Shows which pin LLWU_P3 is mapped to
//     <0=> Disabled
//     <1=> PTF6<selection=PTF6_SIG_SEL,LLWU_P3>
//     <0=> Default
#define LLWU_P3_PIN_SEL      0
#if LLWU_P3_PIN_SEL == 1
#define LLWU_P3_GPIO         digitalIO_PTF6
#define LLWU_P3_FN           4
#endif

// Pin Mapping for LLWU_P4 signal
//   <o> LLWU_P4 [PTF0]<name=LLWU_P4_PIN_SEL>
//   <i> Shows which pin LLWU_P4 is mapped to
//     <0=> Disabled
//     <1=> PTF0<selection=PTF0_SIG_SEL,LLWU_P4>
//     <0=> Default
#define LLWU_P4_PIN_SEL      0
#if LLWU_P4_PIN_SEL == 1
#define LLWU_P4_GPIO         digitalIO_PTF0
#define LLWU_P4_FN           5
#endif

// Pin Mapping for LLWU_P5 signal
//   <o> LLWU_P5 [PTE6]<name=LLWU_P5_PIN_SEL>
//   <i> Shows which pin LLWU_P5 is mapped to
//     <0=> Disabled
//     <1=> PTE6<selection=PTE6_SIG_SEL,LLWU_P5>
//     <0=> Default
#define LLWU_P5_PIN_SEL      0
#if LLWU_P5_PIN_SEL == 1
#define LLWU_P5_GPIO         digitalIO_PTE6
#define LLWU_P5_FN           4
#endif

// Pin Mapping for LLWU_P6 signal
//   <o> LLWU_P6 [PTE5]<name=LLWU_P6_PIN_SEL>
//   <i> Shows which pin LLWU_P6 is mapped to
//     <0=> Disabled
//     <1=> PTE5<selection=PTE5_SIG_SEL,LLWU_P6>
//     <0=> Default
#define LLWU_P6_PIN_SEL      0
#if LLWU_P6_PIN_SEL == 1
#define LLWU_P6_GPIO         digitalIO_PTE5
#define LLWU_P6_FN           5
#endif

// Pin Mapping for LLWU_P7 signal
//   <o> LLWU_P7 [PTD7]<name=LLWU_P7_PIN_SEL>
//   <i> Shows which pin LLWU_P7 is mapped to
//     <0=> Disabled
//     <1=> PTD7<selection=PTD7_SIG_SEL,LLWU_P7>
//     <0=> Default
#define LLWU_P7_PIN_SEL      0
#if LLWU_P7_PIN_SEL == 1
#define LLWU_P7_GPIO         digitalIO_PTD7
#define LLWU_P7_FN           5
#endif

// Pin Mapping for LLWU_P8 signal
//   <o> LLWU_P8 [PTD6]<name=LLWU_P8_PIN_SEL>
//   <i> Shows which pin LLWU_P8 is mapped to
//     <0=> Disabled
//     <1=> PTD6<selection=PTD6_SIG_SEL,LLWU_P8>
//     <0=> Default
#define LLWU_P8_PIN_SEL      0
#if LLWU_P8_PIN_SEL == 1
#define LLWU_P8_GPIO         digitalIO_PTD6
#define LLWU_P8_FN           5
#endif

// Pin Mapping for LLWU_P9 signal
//   <o> LLWU_P9 [PTD4]<name=LLWU_P9_PIN_SEL>
//   <i> Shows which pin LLWU_P9 is mapped to
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,LLWU_P9>
//     <0=> Default
#define LLWU_P9_PIN_SEL      0
#if LLWU_P9_PIN_SEL == 1
#define LLWU_P9_GPIO         digitalIO_PTD4
#define LLWU_P9_FN           4
#endif

// Pin Mapping for LLWU_P10 signal
//   <o> LLWU_P10 [PTD2]<name=LLWU_P10_PIN_SEL>
//   <i> Shows which pin LLWU_P10 is mapped to
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,LLWU_P10>
//     <0=> Default
#define LLWU_P10_PIN_SEL     0
#if LLWU_P10_PIN_SEL == 1
#define LLWU_P10_GPIO        digitalIO_PTD2
#define LLWU_P10_FN          5
#endif

// Pin Mapping for LLWU_P11 signal
//   <o> LLWU_P11 [PTD0]<name=LLWU_P11_PIN_SEL>
//   <i> Shows which pin LLWU_P11 is mapped to
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,LLWU_P11>
//     <0=> Default
#define LLWU_P11_PIN_SEL     0
#if LLWU_P11_PIN_SEL == 1
#define LLWU_P11_GPIO        digitalIO_PTD0
#define LLWU_P11_FN          4
#endif

// Pin Mapping for LLWU_P12 signal
//   <o> LLWU_P12 [PTC5]<name=LLWU_P12_PIN_SEL>
//   <i> Shows which pin LLWU_P12 is mapped to
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,LLWU_P12>
//     <0=> Default
#define LLWU_P12_PIN_SEL     0
#if LLWU_P12_PIN_SEL == 1
#define LLWU_P12_GPIO        digitalIO_PTC5
#define LLWU_P12_FN          3
#endif

// Pin Mapping for LLWU_P13 signal
//   <o> LLWU_P13 [PTC3]<name=LLWU_P13_PIN_SEL>
//   <i> Shows which pin LLWU_P13 is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,LLWU_P13>
//     <0=> Default
#define LLWU_P13_PIN_SEL     0
#if LLWU_P13_PIN_SEL == 1
#define LLWU_P13_GPIO        digitalIO_PTC3
#define LLWU_P13_FN          3
#endif

// Pin Mapping for LLWU_P14 signal
//   <o> LLWU_P14 [PTA6]<name=LLWU_P14_PIN_SEL>
//   <i> Shows which pin LLWU_P14 is mapped to
//     <0=> Disabled
//     <1=> PTA6<selection=PTA6_SIG_SEL,LLWU_P14>
//     <0=> Default
#define LLWU_P14_PIN_SEL     0
#if LLWU_P14_PIN_SEL == 1
#define LLWU_P14_GPIO        digitalIO_PTA6
#define LLWU_P14_FN          3
#endif

// Pin Mapping for LLWU_P15 signal
//   <o> LLWU_P15 [PTA4]<name=LLWU_P15_PIN_SEL>
//   <i> Shows which pin LLWU_P15 is mapped to
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,LLWU_P15>
//     <0=> Default
#define LLWU_P15_PIN_SEL     0
#if LLWU_P15_PIN_SEL == 1
#define LLWU_P15_GPIO        digitalIO_PTA4
#define LLWU_P15_FN          2
#endif

// </h>

// <h> Low Power Timer (LPTMR)

// Pin Mapping for LPTMR_ALT0 signal
//   <o> LPTMR_ALT0 [PTE4, PTF4, PTG1]<name=LPTMR_ALT0_PIN_SEL>
//   <i> Shows which pin LPTMR_ALT0 is mapped to
//     <0=> Disabled
//     <1=> PTE4<selection=PTE4_SIG_SEL,LPTMR_ALT0>
//     <2=> PTF4<selection=PTF4_SIG_SEL,LPTMR_ALT0>
//     <3=> PTG1<selection=PTG1_SIG_SEL,LPTMR_ALT0>
//     <0=> Default
#define LPTMR_ALT0_PIN_SEL   0
#if LPTMR_ALT0_PIN_SEL == 1
#define LPTMR_ALT0_GPIO      digitalIO_PTE4
#define LPTMR_ALT0_FN        2
#elif LPTMR_ALT0_PIN_SEL == 2
#define LPTMR_ALT0_GPIO      digitalIO_PTF4
#define LPTMR_ALT0_FN        3
#elif LPTMR_ALT0_PIN_SEL == 3
#define LPTMR_ALT0_GPIO      digitalIO_PTG1
#define LPTMR_ALT0_FN        3
#endif

// Pin Mapping for LPTMR_ALT1 signal
//   <o> LPTMR_ALT1 [PTD6, PTF3, PTG5]<name=LPTMR_ALT1_PIN_SEL>
//   <i> Shows which pin LPTMR_ALT1 is mapped to
//     <0=> Disabled
//     <1=> PTD6<selection=PTD6_SIG_SEL,LPTMR_ALT1>
//     <2=> PTF3<selection=PTF3_SIG_SEL,LPTMR_ALT1>
//     <3=> PTG5<selection=PTG5_SIG_SEL,LPTMR_ALT1>
//     <0=> Default
#define LPTMR_ALT1_PIN_SEL   0
#if LPTMR_ALT1_PIN_SEL == 1
#define LPTMR_ALT1_GPIO      digitalIO_PTD6
#define LPTMR_ALT1_FN        2
#elif LPTMR_ALT1_PIN_SEL == 2
#define LPTMR_ALT1_GPIO      digitalIO_PTF3
#define LPTMR_ALT1_FN        3
#elif LPTMR_ALT1_PIN_SEL == 3
#define LPTMR_ALT1_GPIO      digitalIO_PTG5
#define LPTMR_ALT1_FN        3
#endif

// Pin Mapping for LPTMR_ALT2 signal
//   <o> LPTMR_ALT2 [PTD5, PTG0, PTG6]<name=LPTMR_ALT2_PIN_SEL>
//   <i> Shows which pin LPTMR_ALT2 is mapped to
//     <0=> Disabled
//     <1=> PTD5<selection=PTD5_SIG_SEL,LPTMR_ALT2>
//     <2=> PTG0<selection=PTG0_SIG_SEL,LPTMR_ALT2>
//     <3=> PTG6<selection=PTG6_SIG_SEL,LPTMR_ALT2>
//     <0=> Default
#define LPTMR_ALT2_PIN_SEL   0
#if LPTMR_ALT2_PIN_SEL == 1
#define LPTMR_ALT2_GPIO      digitalIO_PTD5
#define LPTMR_ALT2_FN        2
#elif LPTMR_ALT2_PIN_SEL == 2
#define LPTMR_ALT2_GPIO      digitalIO_PTG0
#define LPTMR_ALT2_FN        3
#elif LPTMR_ALT2_PIN_SEL == 3
#define LPTMR_ALT2_GPIO      digitalIO_PTG6
#define LPTMR_ALT2_FN        3
#endif

// </h>

// <h> Debug and Control

// Pin Mapping for NMI_B signal
//   <o> NMI_B [PTA4]<name=NMI_B_PIN_SEL>
//   <i> Shows which pin NMI_B is mapped to
//     <0=> Disabled
//     <1=> PTA4 (reset default)<selection=PTA4_SIG_SEL,NMI_B (reset default)>
//     <2=> PTA4<selection=PTA4_SIG_SEL,NMI_B>
//     <1=> Default
#define NMI_B_PIN_SEL        1
#if NMI_B_PIN_SEL == 2
#define NMI_B_GPIO           digitalIO_PTA4
#define NMI_B_FN             7
#endif

// Pin Mapping for RESET_B signal
//   <o> RESET_B [PTE1]<name=RESET_B_PIN_SEL>
//   <i> Shows which pin RESET_B is mapped to
//     <0=> Disabled
//     <1=> PTE1 (reset default)<selection=PTE1_SIG_SEL,RESET_B (reset default)>
//     <2=> PTE1<selection=PTE1_SIG_SEL,RESET_B>
//     <1=> Default
#define RESET_B_PIN_SEL      1
#if RESET_B_PIN_SEL == 2
#define RESET_B_GPIO         digitalIO_PTE1
#define RESET_B_FN           7
#endif

// Pin Mapping for SWD_CLK signal
//   <o> SWD_CLK [PTE7]<name=SWD_CLK_PIN_SEL>
//   <i> Shows which pin SWD_CLK is mapped to
//     <0=> Disabled
//     <1=> PTE7 (reset default)<selection=PTE7_SIG_SEL,SWD_CLK (reset default)>
//     <2=> PTE7<selection=PTE7_SIG_SEL,SWD_CLK>
//     <1=> Default
#define SWD_CLK_PIN_SEL      1
#if SWD_CLK_PIN_SEL == 2
#define SWD_CLK_GPIO         digitalIO_PTE7
#define SWD_CLK_FN           7
#endif

// Pin Mapping for SWD_IO signal
//   <o> SWD_IO [PTE6]<name=SWD_IO_PIN_SEL>
//   <i> Shows which pin SWD_IO is mapped to
//     <0=> Disabled
//     <1=> PTE6 (reset default)<selection=PTE6_SIG_SEL,SWD_IO (reset default)>
//     <2=> PTE6<selection=PTE6_SIG_SEL,SWD_IO>
//     <1=> Default
#define SWD_IO_PIN_SEL       1
#if SWD_IO_PIN_SEL == 2
#define SWD_IO_GPIO          digitalIO_PTE6
#define SWD_IO_FN            7
#endif

// </h>

// <h> (PXBAR)

// Pin Mapping for PXBAR_IN0 signal
//   <o> PXBAR_IN0 [PTA6]<name=PXBAR_IN0_PIN_SEL>
//   <i> Shows which pin PXBAR_IN0 is mapped to
//     <0=> Disabled
//     <1=> PTA6<selection=PTA6_SIG_SEL,PXBAR_IN0>
//     <0=> Default
#define PXBAR_IN0_PIN_SEL    0
#if PXBAR_IN0_PIN_SEL == 1
#define PXBAR_IN0_GPIO       digitalIO_PTA6
#define PXBAR_IN0_FN         2
#endif

// Pin Mapping for PXBAR_IN1 signal
//   <o> PXBAR_IN1 [PTC0]<name=PXBAR_IN1_PIN_SEL>
//   <i> Shows which pin PXBAR_IN1 is mapped to
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,PXBAR_IN1>
//     <0=> Default
#define PXBAR_IN1_PIN_SEL    0
#if PXBAR_IN1_PIN_SEL == 1
#define PXBAR_IN1_GPIO       digitalIO_PTC0
#define PXBAR_IN1_FN         3
#endif

// Pin Mapping for PXBAR_IN2 signal
//   <o> PXBAR_IN2 [PTD0]<name=PXBAR_IN2_PIN_SEL>
//   <i> Shows which pin PXBAR_IN2 is mapped to
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,PXBAR_IN2>
//     <0=> Default
#define PXBAR_IN2_PIN_SEL    0
#if PXBAR_IN2_PIN_SEL == 1
#define PXBAR_IN2_GPIO       digitalIO_PTD0
#define PXBAR_IN2_FN         3
#endif

// Pin Mapping for PXBAR_IN3 signal
//   <o> PXBAR_IN3 [PTD2]<name=PXBAR_IN3_PIN_SEL>
//   <i> Shows which pin PXBAR_IN3 is mapped to
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,PXBAR_IN3>
//     <0=> Default
#define PXBAR_IN3_PIN_SEL    0
#if PXBAR_IN3_PIN_SEL == 1
#define PXBAR_IN3_GPIO       digitalIO_PTD2
#define PXBAR_IN3_FN         4
#endif

// Pin Mapping for PXBAR_IN4 signal
//   <o> PXBAR_IN4 [PTD7]<name=PXBAR_IN4_PIN_SEL>
//   <i> Shows which pin PXBAR_IN4 is mapped to
//     <0=> Disabled
//     <1=> PTD7<selection=PTD7_SIG_SEL,PXBAR_IN4>
//     <0=> Default
#define PXBAR_IN4_PIN_SEL    0
#if PXBAR_IN4_PIN_SEL == 1
#define PXBAR_IN4_GPIO       digitalIO_PTD7
#define PXBAR_IN4_FN         3
#endif

// Pin Mapping for PXBAR_IN5 signal
//   <o> PXBAR_IN5 [PTE6]<name=PXBAR_IN5_PIN_SEL>
//   <i> Shows which pin PXBAR_IN5 is mapped to
//     <0=> Disabled
//     <1=> PTE6<selection=PTE6_SIG_SEL,PXBAR_IN5>
//     <0=> Default
#define PXBAR_IN5_PIN_SEL    0
#if PXBAR_IN5_PIN_SEL == 1
#define PXBAR_IN5_GPIO       digitalIO_PTE6
#define PXBAR_IN5_FN         2
#endif

// Pin Mapping for PXBAR_IN6 signal
//   <o> PXBAR_IN6 [PTE2]<name=PXBAR_IN6_PIN_SEL>
//   <i> Shows which pin PXBAR_IN6 is mapped to
//     <0=> Disabled
//     <1=> PTE2<selection=PTE2_SIG_SEL,PXBAR_IN6>
//     <0=> Default
#define PXBAR_IN6_PIN_SEL    0
#if PXBAR_IN6_PIN_SEL == 1
#define PXBAR_IN6_GPIO       digitalIO_PTE2
#define PXBAR_IN6_FN         3
#endif

// Pin Mapping for PXBAR_IN7 signal
//   <o> PXBAR_IN7 [PTH6]<name=PXBAR_IN7_PIN_SEL>
//   <i> Shows which pin PXBAR_IN7 is mapped to
//     <0=> Disabled
//     <1=> PTH6<selection=PTH6_SIG_SEL,PXBAR_IN7>
//     <0=> Default
#define PXBAR_IN7_PIN_SEL    0
#if PXBAR_IN7_PIN_SEL == 1
#define PXBAR_IN7_GPIO       digitalIO_PTH6
#define PXBAR_IN7_FN         4
#endif

// Pin Mapping for PXBAR_IN8 signal
//   <o> PXBAR_IN8 [PTI0]<name=PXBAR_IN8_PIN_SEL>
//   <i> Shows which pin PXBAR_IN8 is mapped to
//     <0=> Disabled
//     <1=> PTI0<selection=PTI0_SIG_SEL,PXBAR_IN8>
//     <0=> Default
#define PXBAR_IN8_PIN_SEL    0
#if PXBAR_IN8_PIN_SEL == 1
#define PXBAR_IN8_GPIO       digitalIO_PTI0
#define PXBAR_IN8_FN         3
#endif

// Pin Mapping for PXBAR_OUT0 signal
//   <o> PXBAR_OUT0 [PTA7]<name=PXBAR_OUT0_PIN_SEL>
//   <i> Shows which pin PXBAR_OUT0 is mapped to
//     <0=> Disabled
//     <1=> PTA7<selection=PTA7_SIG_SEL,PXBAR_OUT0>
//     <0=> Default
#define PXBAR_OUT0_PIN_SEL   0
#if PXBAR_OUT0_PIN_SEL == 1
#define PXBAR_OUT0_GPIO      digitalIO_PTA7
#define PXBAR_OUT0_FN        2
#endif

// Pin Mapping for PXBAR_OUT1 signal
//   <o> PXBAR_OUT1 [PTC2]<name=PXBAR_OUT1_PIN_SEL>
//   <i> Shows which pin PXBAR_OUT1 is mapped to
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,PXBAR_OUT1>
//     <0=> Default
#define PXBAR_OUT1_PIN_SEL   0
#if PXBAR_OUT1_PIN_SEL == 1
#define PXBAR_OUT1_GPIO      digitalIO_PTC2
#define PXBAR_OUT1_FN        3
#endif

// Pin Mapping for PXBAR_OUT2 signal
//   <o> PXBAR_OUT2 [PTC7]<name=PXBAR_OUT2_PIN_SEL>
//   <i> Shows which pin PXBAR_OUT2 is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,PXBAR_OUT2>
//     <0=> Default
#define PXBAR_OUT2_PIN_SEL   0
#if PXBAR_OUT2_PIN_SEL == 1
#define PXBAR_OUT2_GPIO      digitalIO_PTC7
#define PXBAR_OUT2_FN        3
#endif

// Pin Mapping for PXBAR_OUT3 signal
//   <o> PXBAR_OUT3 [PTD1]<name=PXBAR_OUT3_PIN_SEL>
//   <i> Shows which pin PXBAR_OUT3 is mapped to
//     <0=> Disabled
//     <1=> PTD1 (Alias:LED_BLUE)<selection=PTD1_SIG_SEL,PXBAR_OUT3>
//     <0=> Default
#define PXBAR_OUT3_PIN_SEL   0
#if PXBAR_OUT3_PIN_SEL == 1
#define PXBAR_OUT3_GPIO      digitalIO_PTD1
#define PXBAR_OUT3_FN        4
#endif

// Pin Mapping for PXBAR_OUT4 signal
//   <o> PXBAR_OUT4 [PTE0]<name=PXBAR_OUT4_PIN_SEL>
//   <i> Shows which pin PXBAR_OUT4 is mapped to
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,PXBAR_OUT4>
//     <0=> Default
#define PXBAR_OUT4_PIN_SEL   0
#if PXBAR_OUT4_PIN_SEL == 1
#define PXBAR_OUT4_GPIO      digitalIO_PTE0
#define PXBAR_OUT4_FN        3
#endif

// Pin Mapping for PXBAR_OUT5 signal
//   <o> PXBAR_OUT5 [PTE7]<name=PXBAR_OUT5_PIN_SEL>
//   <i> Shows which pin PXBAR_OUT5 is mapped to
//     <0=> Disabled
//     <1=> PTE7<selection=PTE7_SIG_SEL,PXBAR_OUT5>
//     <0=> Default
#define PXBAR_OUT5_PIN_SEL   0
#if PXBAR_OUT5_PIN_SEL == 1
#define PXBAR_OUT5_GPIO      digitalIO_PTE7
#define PXBAR_OUT5_FN        2
#endif

// Pin Mapping for PXBAR_OUT6 signal
//   <o> PXBAR_OUT6 [PTF1]<name=PXBAR_OUT6_PIN_SEL>
//   <i> Shows which pin PXBAR_OUT6 is mapped to
//     <0=> Disabled
//     <1=> PTF1<selection=PTF1_SIG_SEL,PXBAR_OUT6>
//     <0=> Default
#define PXBAR_OUT6_PIN_SEL   0
#if PXBAR_OUT6_PIN_SEL == 1
#define PXBAR_OUT6_GPIO      digitalIO_PTF1
#define PXBAR_OUT6_FN        3
#endif

// Pin Mapping for PXBAR_OUT7 signal
//   <o> PXBAR_OUT7 [PTH7]<name=PXBAR_OUT7_PIN_SEL>
//   <i> Shows which pin PXBAR_OUT7 is mapped to
//     <0=> Disabled
//     <1=> PTH7<selection=PTH7_SIG_SEL,PXBAR_OUT7>
//     <0=> Default
#define PXBAR_OUT7_PIN_SEL   0
#if PXBAR_OUT7_PIN_SEL == 1
#define PXBAR_OUT7_GPIO      digitalIO_PTH7
#define PXBAR_OUT7_FN        4
#endif

// Pin Mapping for PXBAR_OUT8 signal
//   <o> PXBAR_OUT8 [PTI1]<name=PXBAR_OUT8_PIN_SEL>
//   <i> Shows which pin PXBAR_OUT8 is mapped to
//     <0=> Disabled
//     <1=> PTI1<selection=PTI1_SIG_SEL,PXBAR_OUT8>
//     <0=> Default
#define PXBAR_OUT8_PIN_SEL   0
#if PXBAR_OUT8_PIN_SEL == 1
#define PXBAR_OUT8_GPIO      digitalIO_PTI1
#define PXBAR_OUT8_FN        3
#endif

// </h>

// <h> (QT)

// Pin Mapping for QT0 signal
//   <o> QT0 [PTF1, PTD5]<name=QT0_PIN_SEL>
//   <i> Shows which pin QT0 is mapped to
//     <0=> Disabled
//     <1=> PTF1<selection=PTF1_SIG_SEL,QT0>
//     <2=> PTD5<selection=PTD5_SIG_SEL,QT0>
//     <0=> Default
#define QT0_PIN_SEL          0
#if QT0_PIN_SEL == 1
#define QT0_GPIO             digitalIO_PTF1
#define QT0_FN               2
#elif QT0_PIN_SEL == 2
#define QT0_GPIO             digitalIO_PTD5
#define QT0_FN               3
#endif

// Pin Mapping for QT1 signal
//   <o> QT1 [PTG0, PTC6]<name=QT1_PIN_SEL>
//   <i> Shows which pin QT1 is mapped to
//     <0=> Disabled
//     <1=> PTG0<selection=PTG0_SIG_SEL,QT1>
//     <2=> PTC6<selection=PTC6_SIG_SEL,QT1>
//     <0=> Default
#define QT1_PIN_SEL          0
#if QT1_PIN_SEL == 1
#define QT1_GPIO             digitalIO_PTG0
#define QT1_FN               2
#elif QT1_PIN_SEL == 2
#define QT1_GPIO             digitalIO_PTC6
#define QT1_FN               3
#endif

// Pin Mapping for QT2 signal
//   <o> QT2 [PTF7, PTF0]<name=QT2_PIN_SEL>
//   <i> Shows which pin QT2 is mapped to
//     <0=> Disabled
//     <1=> PTF7<selection=PTF7_SIG_SEL,QT2>
//     <2=> PTF0<selection=PTF0_SIG_SEL,QT2>
//     <0=> Default
#define QT2_PIN_SEL          0
#if QT2_PIN_SEL == 1
#define QT2_GPIO             digitalIO_PTF7
#define QT2_FN               2
#elif QT2_PIN_SEL == 2
#define QT2_GPIO             digitalIO_PTF0
#define QT2_FN               3
#endif

// Pin Mapping for QT3 signal
//   <o> QT3 [PTE5, PTD1]<name=QT3_PIN_SEL>
//   <i> Shows which pin QT3 is mapped to
//     <0=> Disabled
//     <1=> PTE5<selection=PTE5_SIG_SEL,QT3>
//     <2=> PTD1 (Alias:LED_BLUE)<selection=PTD1_SIG_SEL,QT3>
//     <0=> Default
#define QT3_PIN_SEL          0
#if QT3_PIN_SEL == 1
#define QT3_GPIO             digitalIO_PTE5
#define QT3_FN               2
#elif QT3_PIN_SEL == 2
#define QT3_GPIO             digitalIO_PTD1
#define QT3_FN               5
#endif

// </h>

// <h> Serial Communication Interface (SCI0)

// Pin Mapping for SCI0_CTS signal
//   <o> SCI0_CTS [PTC6]<name=SCI0_CTS_PIN_SEL>
//   <i> Shows which pin SCI0_CTS is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,SCI0_CTS>
//     <0=> Default
#define SCI0_CTS_PIN_SEL     0
#if SCI0_CTS_PIN_SEL == 1
#define SCI0_CTS_GPIO        digitalIO_PTC6
#define SCI0_CTS_FN          2
#endif

// Pin Mapping for SCI0_RTS signal
//   <o> SCI0_RTS [PTC5]<name=SCI0_RTS_PIN_SEL>
//   <i> Shows which pin SCI0_RTS is mapped to
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,SCI0_RTS>
//     <0=> Default
#define SCI0_RTS_PIN_SEL     0
#if SCI0_RTS_PIN_SEL == 1
#define SCI0_RTS_GPIO        digitalIO_PTC5
#define SCI0_RTS_FN          2
#endif

// Pin Mapping for SCI0_RxD signal
//   <o> SCI0_RxD [PTD0, PTF3]<name=SCI0_RxD_PIN_SEL>
//   <i> Shows which pin SCI0_RxD is mapped to
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,SCI0_RxD>
//     <2=> PTF3<selection=PTF3_SIG_SEL,SCI0_RxD>
//     <0=> Default
#define SCI0_RxD_PIN_SEL     0
#if SCI0_RxD_PIN_SEL == 1
#define SCI0_RxD_GPIO        digitalIO_PTD0
#define SCI0_RxD_FN          2
#elif SCI0_RxD_PIN_SEL == 2
#define SCI0_RxD_GPIO        digitalIO_PTF3
#define SCI0_RxD_FN          4
#endif

// Pin Mapping for SCI0_TxD signal
//   <o> SCI0_TxD [PTC7, PTF4]<name=SCI0_TxD_PIN_SEL>
//   <i> Shows which pin SCI0_TxD is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,SCI0_TxD>
//     <2=> PTF4<selection=PTF4_SIG_SEL,SCI0_TxD>
//     <0=> Default
#define SCI0_TxD_PIN_SEL     0
#if SCI0_TxD_PIN_SEL == 1
#define SCI0_TxD_GPIO        digitalIO_PTC7
#define SCI0_TxD_FN          2
#elif SCI0_TxD_PIN_SEL == 2
#define SCI0_TxD_GPIO        digitalIO_PTF4
#define SCI0_TxD_FN          4
#endif

// </h>

// <h> Serial Communication Interface (SCI1)

// Pin Mapping for SCI1_CTS signal
//   <o> SCI1_CTS [PTD3, PTH6]<name=SCI1_CTS_PIN_SEL>
//   <i> Shows which pin SCI1_CTS is mapped to
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,SCI1_CTS>
//     <2=> PTH6<selection=PTH6_SIG_SEL,SCI1_CTS>
//     <0=> Default
#define SCI1_CTS_PIN_SEL     0
#if SCI1_CTS_PIN_SEL == 1
#define SCI1_CTS_GPIO        digitalIO_PTD3
#define SCI1_CTS_FN          2
#elif SCI1_CTS_PIN_SEL == 2
#define SCI1_CTS_GPIO        digitalIO_PTH6
#define SCI1_CTS_FN          2
#endif

// Pin Mapping for SCI1_RTS signal
//   <o> SCI1_RTS [PTD4, PTH7]<name=SCI1_RTS_PIN_SEL>
//   <i> Shows which pin SCI1_RTS is mapped to
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,SCI1_RTS>
//     <2=> PTH7<selection=PTH7_SIG_SEL,SCI1_RTS>
//     <0=> Default
#define SCI1_RTS_PIN_SEL     0
#if SCI1_RTS_PIN_SEL == 1
#define SCI1_RTS_GPIO        digitalIO_PTD4
#define SCI1_RTS_FN          2
#elif SCI1_RTS_PIN_SEL == 2
#define SCI1_RTS_GPIO        digitalIO_PTH7
#define SCI1_RTS_FN          2
#endif

// Pin Mapping for SCI1_RxD signal
//   <o> SCI1_RxD [PTD2, PTI0]<name=SCI1_RxD_PIN_SEL>
//   <i> Shows which pin SCI1_RxD is mapped to
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,SCI1_RxD>
//     <2=> PTI0<selection=PTI0_SIG_SEL,SCI1_RxD>
//     <0=> Default
#define SCI1_RxD_PIN_SEL     0
#if SCI1_RxD_PIN_SEL == 1
#define SCI1_RxD_GPIO        digitalIO_PTD2
#define SCI1_RxD_FN          2
#elif SCI1_RxD_PIN_SEL == 2
#define SCI1_RxD_GPIO        digitalIO_PTI0
#define SCI1_RxD_FN          2
#endif

// Pin Mapping for SCI1_TxD signal
//   <o> SCI1_TxD [PTD1, PTI1]<name=SCI1_TxD_PIN_SEL>
//   <i> Shows which pin SCI1_TxD is mapped to
//     <0=> Disabled
//     <1=> PTD1 (Alias:LED_BLUE)<selection=PTD1_SIG_SEL,SCI1_TxD>
//     <2=> PTI1<selection=PTI1_SIG_SEL,SCI1_TxD>
//     <0=> Default
#define SCI1_TxD_PIN_SEL     0
#if SCI1_TxD_PIN_SEL == 1
#define SCI1_TxD_GPIO        digitalIO_PTD1
#define SCI1_TxD_FN          2
#elif SCI1_TxD_PIN_SEL == 2
#define SCI1_TxD_GPIO        digitalIO_PTI1
#define SCI1_TxD_FN          2
#endif

// </h>

// <h> Serial Communication Interface (SCI2)

// Pin Mapping for SCI2_CTS signal
//   <o> SCI2_CTS [PTE4]<name=SCI2_CTS_PIN_SEL>
//   <i> Shows which pin SCI2_CTS is mapped to
//     <0=> Disabled
//     <1=> PTE4<selection=PTE4_SIG_SEL,SCI2_CTS>
//     <0=> Default
#define SCI2_CTS_PIN_SEL     0
#if SCI2_CTS_PIN_SEL == 1
#define SCI2_CTS_GPIO        digitalIO_PTE4
#define SCI2_CTS_FN          3
#endif

// Pin Mapping for SCI2_RTS signal
//   <o> SCI2_RTS [PTE5]<name=SCI2_RTS_PIN_SEL>
//   <i> Shows which pin SCI2_RTS is mapped to
//     <0=> Disabled
//     <1=> PTE5<selection=PTE5_SIG_SEL,SCI2_RTS>
//     <0=> Default
#define SCI2_RTS_PIN_SEL     0
#if SCI2_RTS_PIN_SEL == 1
#define SCI2_RTS_GPIO        digitalIO_PTE5
#define SCI2_RTS_FN          3
#endif

// Pin Mapping for SCI2_RxD signal
//   <o> SCI2_RxD [PTE6]<name=SCI2_RxD_PIN_SEL>
//   <i> Shows which pin SCI2_RxD is mapped to
//     <0=> Disabled
//     <1=> PTE6<selection=PTE6_SIG_SEL,SCI2_RxD>
//     <0=> Default
#define SCI2_RxD_PIN_SEL     0
#if SCI2_RxD_PIN_SEL == 1
#define SCI2_RxD_GPIO        digitalIO_PTE6
#define SCI2_RxD_FN          3
#endif

// Pin Mapping for SCI2_TxD signal
//   <o> SCI2_TxD [PTE7]<name=SCI2_TxD_PIN_SEL>
//   <i> Shows which pin SCI2_TxD is mapped to
//     <0=> Disabled
//     <1=> PTE7<selection=PTE7_SIG_SEL,SCI2_TxD>
//     <0=> Default
#define SCI2_TxD_PIN_SEL     0
#if SCI2_TxD_PIN_SEL == 1
#define SCI2_TxD_GPIO        digitalIO_PTE7
#define SCI2_TxD_FN          3
#endif

// </h>

// <h> Serial Communication Interface (SCI3)

// Pin Mapping for SCI3_CTS signal
//   <o> SCI3_CTS [PTC1, PTD5]<name=SCI3_CTS_PIN_SEL>
//   <i> Shows which pin SCI3_CTS is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,SCI3_CTS>
//     <2=> PTD5<selection=PTD5_SIG_SEL,SCI3_CTS>
//     <0=> Default
#define SCI3_CTS_PIN_SEL     0
#if SCI3_CTS_PIN_SEL == 1
#define SCI3_CTS_GPIO        digitalIO_PTC1
#define SCI3_CTS_FN          2
#elif SCI3_CTS_PIN_SEL == 2
#define SCI3_CTS_GPIO        digitalIO_PTD5
#define SCI3_CTS_FN          4
#endif

// Pin Mapping for SCI3_RTS signal
//   <o> SCI3_RTS [PTC0, PTD6]<name=SCI3_RTS_PIN_SEL>
//   <i> Shows which pin SCI3_RTS is mapped to
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,SCI3_RTS>
//     <2=> PTD6<selection=PTD6_SIG_SEL,SCI3_RTS>
//     <0=> Default
#define SCI3_RTS_PIN_SEL     0
#if SCI3_RTS_PIN_SEL == 1
#define SCI3_RTS_GPIO        digitalIO_PTC0
#define SCI3_RTS_FN          2
#elif SCI3_RTS_PIN_SEL == 2
#define SCI3_RTS_GPIO        digitalIO_PTD6
#define SCI3_RTS_FN          4
#endif

// Pin Mapping for SCI3_RxD signal
//   <o> SCI3_RxD [PTC3, PTD7]<name=SCI3_RxD_PIN_SEL>
//   <i> Shows which pin SCI3_RxD is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,SCI3_RxD>
//     <2=> PTD7<selection=PTD7_SIG_SEL,SCI3_RxD>
//     <0=> Default
#define SCI3_RxD_PIN_SEL     0
#if SCI3_RxD_PIN_SEL == 1
#define SCI3_RxD_GPIO        digitalIO_PTC3
#define SCI3_RxD_FN          2
#elif SCI3_RxD_PIN_SEL == 2
#define SCI3_RxD_GPIO        digitalIO_PTD7
#define SCI3_RxD_FN          4
#endif

// Pin Mapping for SCI3_TxD signal
//   <o> SCI3_TxD [PTC2, PTE0]<name=SCI3_TxD_PIN_SEL>
//   <i> Shows which pin SCI3_TxD is mapped to
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,SCI3_TxD>
//     <2=> PTE0<selection=PTE0_SIG_SEL,SCI3_TxD>
//     <0=> Default
#define SCI3_TxD_PIN_SEL     0
#if SCI3_TxD_PIN_SEL == 1
#define SCI3_TxD_GPIO        digitalIO_PTC2
#define SCI3_TxD_FN          2
#elif SCI3_TxD_PIN_SEL == 2
#define SCI3_TxD_GPIO        digitalIO_PTE0
#define SCI3_TxD_FN          4
#endif

// </h>

// <h> Sigma-delta ADC (SDAD)

// Pin Mapping for SDADM0 signal
//   <o> SDADM0 [SDADM0]<name=SDADM0_PIN_SEL><constant>
//   <i> Shows which pin SDADM0 is mapped to
//     <0=> SDADM0<selection=SDADM0_SIG_SEL,SDADM0>
//     <0=> Default
#define SDADM0_PIN_SEL       0
#define SDADM0_GPIO          0
#define SDADM0_FN            0

// Pin Mapping for SDADM1 signal
//   <o> SDADM1 [SDADM1]<name=SDADM1_PIN_SEL><constant>
//   <i> Shows which pin SDADM1 is mapped to
//     <0=> SDADM1<selection=SDADM1_SIG_SEL,SDADM1>
//     <0=> Default
#define SDADM1_PIN_SEL       0
#define SDADM1_GPIO          0
#define SDADM1_FN            0

// Pin Mapping for SDADM2 signal
//   <o> SDADM2 [SDADM2]<name=SDADM2_PIN_SEL><constant>
//   <i> Shows which pin SDADM2 is mapped to
//     <0=> SDADM2<selection=SDADM2_SIG_SEL,SDADM2/CMP1P3>
//     <0=> Default
#define SDADM2_PIN_SEL       0
#define SDADM2_GPIO          0
#define SDADM2_FN            0

// Pin Mapping for SDADM3 signal
//   <o> SDADM3 [SDADM3]<name=SDADM3_PIN_SEL><constant>
//   <i> Shows which pin SDADM3 is mapped to
//     <0=> SDADM3<selection=SDADM3_SIG_SEL,SDADM3/CMP1P5>
//     <0=> Default
#define SDADM3_PIN_SEL       0
#define SDADM3_GPIO          0
#define SDADM3_FN            0

// Pin Mapping for SDADP0 signal
//   <o> SDADP0 [SDADP0]<name=SDADP0_PIN_SEL><constant>
//   <i> Shows which pin SDADP0 is mapped to
//     <0=> SDADP0<selection=SDADP0_SIG_SEL,SDADP0>
//     <0=> Default
#define SDADP0_PIN_SEL       0
#define SDADP0_GPIO          0
#define SDADP0_FN            0

// Pin Mapping for SDADP1 signal
//   <o> SDADP1 [SDADP1]<name=SDADP1_PIN_SEL><constant>
//   <i> Shows which pin SDADP1 is mapped to
//     <0=> SDADP1<selection=SDADP1_SIG_SEL,SDADP1>
//     <0=> Default
#define SDADP1_PIN_SEL       0
#define SDADP1_GPIO          0
#define SDADP1_FN            0

// Pin Mapping for SDADP2 signal
//   <o> SDADP2 [SDADP2]<name=SDADP2_PIN_SEL><constant>
//   <i> Shows which pin SDADP2 is mapped to
//     <0=> SDADP2<selection=SDADP2_SIG_SEL,SDADP2/CMP1P2>
//     <0=> Default
#define SDADP2_PIN_SEL       0
#define SDADP2_GPIO          0
#define SDADP2_FN            0

// Pin Mapping for SDADP3 signal
//   <o> SDADP3 [SDADP3]<name=SDADP3_PIN_SEL><constant>
//   <i> Shows which pin SDADP3 is mapped to
//     <0=> SDADP3<selection=SDADP3_SIG_SEL,SDADP3/CMP1P4>
//     <0=> Default
#define SDADP3_PIN_SEL       0
#define SDADP3_GPIO          0
#define SDADP3_FN            0

// </h>

// <h> Serial Peripheral Interface (SPI0)

// Pin Mapping for SPI0_MISO signal
//   <o> SPI0_MISO [PTG5, PTD4]<name=SPI0_MISO_PIN_SEL>
//   <i> Shows which pin SPI0_MISO is mapped to
//     <0=> Disabled
//     <1=> PTG5<selection=PTG5_SIG_SEL,SPI0_MISO>
//     <2=> PTD4<selection=PTD4_SIG_SEL,SPI0_MISO>
//     <0=> Default
#define SPI0_MISO_PIN_SEL    0
#if SPI0_MISO_PIN_SEL == 1
#define SPI0_MISO_GPIO       digitalIO_PTG5
#define SPI0_MISO_FN         2
#elif SPI0_MISO_PIN_SEL == 2
#define SPI0_MISO_GPIO       digitalIO_PTD4
#define SPI0_MISO_FN         3
#endif

// Pin Mapping for SPI0_MOSI signal
//   <o> SPI0_MOSI [PTG4, PTD3]<name=SPI0_MOSI_PIN_SEL>
//   <i> Shows which pin SPI0_MOSI is mapped to
//     <0=> Disabled
//     <1=> PTG4<selection=PTG4_SIG_SEL,SPI0_MOSI>
//     <2=> PTD3<selection=PTD3_SIG_SEL,SPI0_MOSI>
//     <0=> Default
#define SPI0_MOSI_PIN_SEL    0
#if SPI0_MOSI_PIN_SEL == 1
#define SPI0_MOSI_GPIO       digitalIO_PTG4
#define SPI0_MOSI_FN         2
#elif SPI0_MOSI_PIN_SEL == 2
#define SPI0_MOSI_GPIO       digitalIO_PTD3
#define SPI0_MOSI_FN         3
#endif

// Pin Mapping for SPI0_SCK signal
//   <o> SPI0_SCK [PTG3, PTD2]<name=SPI0_SCK_PIN_SEL>
//   <i> Shows which pin SPI0_SCK is mapped to
//     <0=> Disabled
//     <1=> PTG3<selection=PTG3_SIG_SEL,SPI0_SCK>
//     <2=> PTD2<selection=PTD2_SIG_SEL,SPI0_SCK>
//     <0=> Default
#define SPI0_SCK_PIN_SEL     0
#if SPI0_SCK_PIN_SEL == 1
#define SPI0_SCK_GPIO        digitalIO_PTG3
#define SPI0_SCK_FN          2
#elif SPI0_SCK_PIN_SEL == 2
#define SPI0_SCK_GPIO        digitalIO_PTD2
#define SPI0_SCK_FN          3
#endif

// Pin Mapping for SPI0_SS_B signal
//   <o> SPI0_SS_B [PTG2, PTD1]<name=SPI0_SS_B_PIN_SEL>
//   <i> Shows which pin SPI0_SS_B is mapped to
//     <0=> Disabled
//     <1=> PTG2<selection=PTG2_SIG_SEL,SPI0_SS_B>
//     <2=> PTD1 (Alias:LED_BLUE)<selection=PTD1_SIG_SEL,SPI0_SS_B>
//     <0=> Default
#define SPI0_SS_B_PIN_SEL    0
#if SPI0_SS_B_PIN_SEL == 1
#define SPI0_SS_B_GPIO       digitalIO_PTG2
#define SPI0_SS_B_FN         2
#elif SPI0_SS_B_PIN_SEL == 2
#define SPI0_SS_B_GPIO       digitalIO_PTD1
#define SPI0_SS_B_FN         3
#endif

// </h>

// <h> Serial Peripheral Interface (SPI1)

// Pin Mapping for SPI1_MISO signal
//   <o> SPI1_MISO [PTF5, PTI0, PTI1]<name=SPI1_MISO_PIN_SEL>
//   <i> Shows which pin SPI1_MISO is mapped to
//     <0=> Disabled
//     <1=> PTF5<selection=PTF5_SIG_SEL,SPI1_MISO>
//     <2=> PTI0<selection=PTI0_SIG_SEL,SPI1_MISO>
//     <3=> PTI1<selection=PTI1_SIG_SEL,SPI1_MISO>
//     <0=> Default
#define SPI1_MISO_PIN_SEL    0
#if SPI1_MISO_PIN_SEL == 1
#define SPI1_MISO_GPIO       digitalIO_PTF5
#define SPI1_MISO_FN         2
#elif SPI1_MISO_PIN_SEL == 2
#define SPI1_MISO_GPIO       digitalIO_PTI0
#define SPI1_MISO_FN         4
#elif SPI1_MISO_PIN_SEL == 3
#define SPI1_MISO_GPIO       digitalIO_PTI1
#define SPI1_MISO_FN         5
#endif

// Pin Mapping for SPI1_MOSI signal
//   <o> SPI1_MOSI [PTF6, PTI1, PTI0]<name=SPI1_MOSI_PIN_SEL>
//   <i> Shows which pin SPI1_MOSI is mapped to
//     <0=> Disabled
//     <1=> PTF6<selection=PTF6_SIG_SEL,SPI1_MOSI>
//     <2=> PTI1<selection=PTI1_SIG_SEL,SPI1_MOSI>
//     <3=> PTI0<selection=PTI0_SIG_SEL,SPI1_MOSI>
//     <0=> Default
#define SPI1_MOSI_PIN_SEL    0
#if SPI1_MOSI_PIN_SEL == 1
#define SPI1_MOSI_GPIO       digitalIO_PTF6
#define SPI1_MOSI_FN         2
#elif SPI1_MOSI_PIN_SEL == 2
#define SPI1_MOSI_GPIO       digitalIO_PTI1
#define SPI1_MOSI_FN         4
#elif SPI1_MOSI_PIN_SEL == 3
#define SPI1_MOSI_GPIO       digitalIO_PTI0
#define SPI1_MOSI_FN         5
#endif

// Pin Mapping for SPI1_SCK signal
//   <o> SPI1_SCK [PTF4, PTH7]<name=SPI1_SCK_PIN_SEL>
//   <i> Shows which pin SPI1_SCK is mapped to
//     <0=> Disabled
//     <1=> PTF4<selection=PTF4_SIG_SEL,SPI1_SCK>
//     <2=> PTH7<selection=PTH7_SIG_SEL,SPI1_SCK>
//     <0=> Default
#define SPI1_SCK_PIN_SEL     0
#if SPI1_SCK_PIN_SEL == 1
#define SPI1_SCK_GPIO        digitalIO_PTF4
#define SPI1_SCK_FN          2
#elif SPI1_SCK_PIN_SEL == 2
#define SPI1_SCK_GPIO        digitalIO_PTH7
#define SPI1_SCK_FN          3
#endif

// Pin Mapping for SPI1_SS_B signal
//   <o> SPI1_SS_B [PTF3, PTH6]<name=SPI1_SS_B_PIN_SEL>
//   <i> Shows which pin SPI1_SS_B is mapped to
//     <0=> Disabled
//     <1=> PTF3<selection=PTF3_SIG_SEL,SPI1_SS_B>
//     <2=> PTH6<selection=PTH6_SIG_SEL,SPI1_SS_B>
//     <0=> Default
#define SPI1_SS_B_PIN_SEL    0
#if SPI1_SS_B_PIN_SEL == 1
#define SPI1_SS_B_GPIO       digitalIO_PTF3
#define SPI1_SS_B_FN         2
#elif SPI1_SS_B_PIN_SEL == 2
#define SPI1_SS_B_GPIO       digitalIO_PTH6
#define SPI1_SS_B_FN         3
#endif

// </h>

// </e>

//-------- <<< end of configuration section >>> -----------------  

#define FIXED_ADC_FN             0                    // Fixed ADC Multiplexing value
#define FIXED_GPIO_FN            1                    // Fixed GPIO Multiplexing value
#define FIXED_PORT_CLOCK_REG     SCGC5                // Fixed PORT Clock
#define ADC0_CLOCK_REG       SCGC6
#define ADC0_CLOCK_MASK      SIM_SCGC6_ADC_MASK
#define AFE_CLOCK_REG        SCGC6
#define AFE_CLOCK_MASK       SIM_SCGC6_AFE_MASK
#define CMP0_CLOCK_REG       SCGC4
#define CMP0_CLOCK_MASK      SIM_SCGC4_CMP0_MASK
#define CMP1_CLOCK_REG       SCGC4
#define CMP1_CLOCK_MASK      SIM_SCGC4_CMP1_MASK
#define CRC_CLOCK_REG        SCGC6
#define CRC_CLOCK_MASK       SIM_SCGC6_CRC_MASK
#define DMA_CLOCK_REG        SCGC7
#define DMA_CLOCK_MASK       SIM_SCGC7_DMA_MASK
#define DMAMUX0_CLOCK_REG    SCGC6
#define DMAMUX0_CLOCK_MASK   SIM_SCGC6_DMAMUX0_MASK
#define DMAMUX1_CLOCK_REG    SCGC6
#define DMAMUX1_CLOCK_MASK   SIM_SCGC6_DMAMUX1_MASK
#define DMAMUX2_CLOCK_REG    SCGC6
#define DMAMUX2_CLOCK_MASK   SIM_SCGC6_DMAMUX2_MASK
#define DMAMUX3_CLOCK_REG    SCGC6
#define DMAMUX3_CLOCK_MASK   SIM_SCGC6_DMAMUX3_MASK
#define EWM_CLOCK_REG        SCGC4
#define EWM_CLOCK_MASK       SIM_SCGC4_EWM_MASK
#define I2C0_CLOCK_REG       SCGC4
#define I2C0_CLOCK_MASK      SIM_SCGC4_I2C0_MASK
#define I2C1_CLOCK_REG       SCGC4
#define I2C1_CLOCK_MASK      SIM_SCGC4_I2C1_MASK
#define IRTC_CLOCK_REG       SCGC5
#define IRTC_CLOCK_MASK      SIM_SCGC5_IRTC_MASK
#define IRTCREGFILE_CLOCK_REG SCGC5
#define IRTCREGFILE_CLOCK_MASK SIM_SCGC5_IRTCREGFILE_MASK
#define LPTMR0_CLOCK_REG     SCGC6
#define LPTMR0_CLOCK_MASK    SIM_SCGC6_LPTMR_MASK
#define MCG_CLOCK_REG        SCGC4
#define MCG_CLOCK_MASK       SIM_SCGC4_MCG_MASK
#define MPU_CLOCK_REG        SCGC7
#define MPU_CLOCK_MASK       SIM_SCGC7_MPU_MASK
#define OSC_CLOCK_REG        SCGC4
#define OSC_CLOCK_MASK       SIM_SCGC4_OSC_MASK
#define PIT0_CLOCK_REG       SCGC6
#define PIT0_CLOCK_MASK      SIM_SCGC6_PIT0_MASK
#define PIT1_CLOCK_REG       SCGC6
#define PIT1_CLOCK_MASK      SIM_SCGC6_PIT1_MASK
#define PORTA_CLOCK_REG      SCGC5
#define PORTA_CLOCK_MASK     SIM_SCGC5_PORTA_MASK
#define PORTB_CLOCK_REG      SCGC5
#define PORTB_CLOCK_MASK     SIM_SCGC5_PORTB_MASK
#define PORTC_CLOCK_REG      SCGC5
#define PORTC_CLOCK_MASK     SIM_SCGC5_PORTC_MASK
#define PORTD_CLOCK_REG      SCGC5
#define PORTD_CLOCK_MASK     SIM_SCGC5_PORTD_MASK
#define PORTE_CLOCK_REG      SCGC5
#define PORTE_CLOCK_MASK     SIM_SCGC5_PORTE_MASK
#define PORTF_CLOCK_REG      SCGC5
#define PORTF_CLOCK_MASK     SIM_SCGC5_PORTF_MASK
#define PORTG_CLOCK_REG      SCGC5
#define PORTG_CLOCK_MASK     SIM_SCGC5_PORTG_MASK
#define PORTH_CLOCK_REG      SCGC5
#define PORTH_CLOCK_MASK     SIM_SCGC5_PORTH_MASK
#define PORTI_CLOCK_REG      SCGC5
#define PORTI_CLOCK_MASK     SIM_SCGC5_PORTI_MASK
#define RNGA_CLOCK_REG       SCGC6
#define RNGA_CLOCK_MASK      SIM_SCGC6_RNGA_MASK
#define SIM_HP_CLOCK_REG     SCGC6
#define SIM_HP_CLOCK_MASK    SIM_SCGC6_SIM_HP_MASK
#define SIM_LP_CLOCK_REG     SCGC6
#define SIM_LP_CLOCK_MASK    SIM_SCGC6_SIM_LP_MASK
#define SLCD_CLOCK_REG       SCGC5
#define SLCD_CLOCK_MASK      SIM_SCGC5_SLCD_MASK
#define SPI0_CLOCK_REG       SCGC4
#define SPI0_CLOCK_MASK      SIM_SCGC4_SPI0_MASK
#define SPI1_CLOCK_REG       SCGC4
#define SPI1_CLOCK_MASK      SIM_SCGC4_SPI1_MASK
#define TMR0_CLOCK_REG       SCGC5
#define TMR0_CLOCK_MASK      SIM_SCGC5_TMR0_MASK
#define TMR1_CLOCK_REG       SCGC5
#define TMR1_CLOCK_MASK      SIM_SCGC5_TMR1_MASK
#define TMR2_CLOCK_REG       SCGC5
#define TMR2_CLOCK_MASK      SIM_SCGC5_TMR2_MASK
#define TMR3_CLOCK_REG       SCGC5
#define TMR3_CLOCK_MASK      SIM_SCGC5_TMR3_MASK
#define UART0_CLOCK_REG      SCGC4
#define UART0_CLOCK_MASK     SIM_SCGC4_UART0_MASK
#define UART1_CLOCK_REG      SCGC4
#define UART1_CLOCK_MASK     SIM_SCGC4_UART1_MASK
#define UART2_CLOCK_REG      SCGC4
#define UART2_CLOCK_MASK     SIM_SCGC4_UART2_MASK
#define UART3_CLOCK_REG      SCGC4
#define UART3_CLOCK_MASK     SIM_SCGC4_UART3_MASK
#define VREF_CLOCK_REG       SCGC4
#define VREF_CLOCK_MASK      SIM_SCGC4_VREF_MASK
#define WDOG_CLOCK_REG       SCGC5
#define WDOG_CLOCK_MASK      SIM_SCGC5_WDOG_MASK
#define XBAR_CLOCK_REG       SCGC5
#define XBAR_CLOCK_MASK      SIM_SCGC5_XBAR_MASK
#define PORT_CLOCK_REG       SCGC5


#endif /* PIN_MAPPING_H_ */
