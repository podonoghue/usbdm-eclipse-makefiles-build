/**
 * @file      pin_mapping.h (derived from pin_mapping-MKE06Z4.h)
 * @version   1.1.0
 * @brief     Pin declarations for MKE06Z4
 */

#ifndef PIN_MAPPING_H_
#define PIN_MAPPING_H_

#include <stddef.h>
#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

//================================
// Validators
// <validate=net.sourceforge.usbdm.annotationEditor.validators.PinMappingValidator>

// <h> Clock settings for FTM0

// FTM0_SC.CLKS ================================
//
//   <o> FTM0_SC.CLKS Clock source
//   <i> Selects the clock source for the FTM0 module. [FTM0_SC.CLKS]
//     <0=> Disabled
//     <1=> System clock
//     <2=> Fixed frequency clock
//     <3=> External clock
//     <1=> Default
// FTM0_SC.PS ================================
//
//   <o1> FTM0_SC.PS Clock prescaler
//   <i> Selects the prescaler for the FTM0 module. [FTM0_SC.PS]
//     <0=> Divide by 1
//     <1=> Divide by 2
//     <2=> Divide by 4
//     <3=> Divide by 8
//     <4=> Divide by 16
//     <5=> Divide by 32
//     <6=> Divide by 64
//     <7=> Divide by 128
//     <0=> Default
namespace USBDM {

constexpr uint16_t FTM0_SC = (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0));
}

// </h>

// <h> Clock settings for FTM1

// FTM1_SC.CLKS ================================
//
//   <o> FTM1_SC.CLKS Clock source
//   <i> Selects the clock source for the FTM1 module. [FTM1_SC.CLKS]
//     <0=> Disabled
//     <1=> System clock
//     <2=> Fixed frequency clock
//     <3=> External clock
//     <1=> Default
// FTM1_SC.PS ================================
//
//   <o1> FTM1_SC.PS Clock prescaler
//   <i> Selects the prescaler for the FTM1 module. [FTM1_SC.PS]
//     <0=> Divide by 1
//     <1=> Divide by 2
//     <2=> Divide by 4
//     <3=> Divide by 8
//     <4=> Divide by 16
//     <5=> Divide by 32
//     <6=> Divide by 64
//     <7=> Divide by 128
//     <0=> Default
namespace USBDM {

constexpr uint16_t FTM1_SC = (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0));
}

// </h>

// <h> Clock settings for FTM2

// FTM2_SC.CLKS ================================
//
//   <o> FTM2_SC.CLKS Clock source
//   <i> Selects the clock source for the FTM2 module. [FTM2_SC.CLKS]
//     <0=> Disabled
//     <1=> System clock
//     <2=> Fixed frequency clock
//     <3=> External clock
//     <1=> Default
// FTM2_SC.PS ================================
//
//   <o1> FTM2_SC.PS Clock prescaler
//   <i> Selects the prescaler for the FTM2 module. [FTM2_SC.PS]
//     <0=> Divide by 1
//     <1=> Divide by 2
//     <2=> Divide by 4
//     <3=> Divide by 8
//     <4=> Divide by 16
//     <5=> Divide by 32
//     <6=> Divide by 64
//     <7=> Divide by 128
//     <0=> Default
namespace USBDM {

constexpr uint16_t FTM2_SC = (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0));
}

// </h>

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

// <h> Port A Pins

// Signal mapping for PTA0 pin
//   <o> PTA0 [GPIOA_0, KBI0_P0, FTM0_CH0, I2C0_4WSCLOUT, ACMP0_IN0, ADC0_SE0]<name=PTA0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA0 pin
//     <-2=> ADC0_SE0 (reset default)<selection=ADC0_SE0_PIN_SEL,PTA0 (reset default)>
//     <0=> GPIOA_0<selection=GPIOA_0_PIN_SEL,PTA0>
//     <1=> KBI0_P0<selection=KBI0_P0_PIN_SEL,PTA0>
//     <2=> FTM0_CH0<selection=FTM0_CH0_PIN_SEL,PTA0>
//     <3=> I2C0_4WSCLOUT<selection=I2C0_4WSCLOUT_PIN_SEL,PTA0>
//     <4=> ACMP0_IN0<selection=ACMP0_IN0_PIN_SEL,PTA0>
//     <5=> ADC0_SE0<selection=ADC0_SE0_PIN_SEL,PTA0>
//     <-2=> Default
#define PTA0_SIG_SEL         -2

// Signal mapping for PTA1 pin
//   <o> PTA1 [GPIOA_1, KBI0_P1, FTM0_CH1, I2C0_4WSDAOUT, ACMP0_IN1, ADC0_SE1]<name=PTA1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA1 pin
//     <-2=> ADC0_SE1 (reset default)<selection=ADC0_SE1_PIN_SEL,PTA1 (reset default)>
//     <0=> GPIOA_1<selection=GPIOA_1_PIN_SEL,PTA1>
//     <1=> KBI0_P1<selection=KBI0_P1_PIN_SEL,PTA1>
//     <2=> FTM0_CH1<selection=FTM0_CH1_PIN_SEL,PTA1>
//     <3=> I2C0_4WSDAOUT<selection=I2C0_4WSDAOUT_PIN_SEL,PTA1>
//     <4=> ACMP0_IN1<selection=ACMP0_IN1_PIN_SEL,PTA1>
//     <5=> ADC0_SE1<selection=ADC0_SE1_PIN_SEL,PTA1>
//     <-2=> Default
#define PTA1_SIG_SEL         -2

// Signal mapping for PTA2 pin
//   <o> PTA2 [GPIOA_2, KBI0_P2, UART0_RX, I2C0_SDA]<name=PTA2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA2 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_2<selection=GPIOA_2_PIN_SEL,PTA2>
//     <1=> KBI0_P2<selection=KBI0_P2_PIN_SEL,PTA2>
//     <2=> UART0_RX<selection=UART0_RX_PIN_SEL,PTA2>
//     <3=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTA2>
//     <-2=> Default
#define PTA2_SIG_SEL         -2

// Signal mapping for PTA3 pin
//   <o> PTA3 [GPIOA_3, KBI0_P3, UART0_TX, I2C0_SCL]<name=PTA3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA3 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_3<selection=GPIOA_3_PIN_SEL,PTA3>
//     <1=> KBI0_P3<selection=KBI0_P3_PIN_SEL,PTA3>
//     <2=> UART0_TX<selection=UART0_TX_PIN_SEL,PTA3>
//     <3=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTA3>
//     <-2=> Default
#define PTA3_SIG_SEL         -2

// Signal mapping for PTA4 pin
//   <o> PTA4 [GPIOA_4, KBI0_P4, ACMP0_OUT, SWD_DIO]<name=PTA4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA4 pin
//     <-2=> SWD_DIO (reset default)<selection=SWD_DIO_PIN_SEL,PTA4 (reset default)>
//     <0=> GPIOA_4<selection=GPIOA_4_PIN_SEL,PTA4>
//     <1=> KBI0_P4<selection=KBI0_P4_PIN_SEL,PTA4>
//     <3=> ACMP0_OUT<selection=ACMP0_OUT_PIN_SEL,PTA4>
//     <4=> SWD_DIO<selection=SWD_DIO_PIN_SEL,PTA4>
//     <-2=> Default
#define PTA4_SIG_SEL         -2

// Signal mapping for PTA5 pin
//   <o> PTA5 [GPIOA_5, KBI0_P5, IRQ, TCLK0, RESET_b]<name=PTA5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA5 pin
//     <-2=> RESET_b (reset default)<selection=RESET_b_PIN_SEL,PTA5 (reset default)>
//     <0=> GPIOA_5<selection=GPIOA_5_PIN_SEL,PTA5>
//     <1=> KBI0_P5<selection=KBI0_P5_PIN_SEL,PTA5>
//     <2=> IRQ<selection=IRQ_PIN_SEL,PTA5>
//     <3=> TCLK0<selection=TCLK0_PIN_SEL,PTA5>
//     <4=> RESET_b<selection=RESET_b_PIN_SEL,PTA5>
//     <-2=> Default
#define PTA5_SIG_SEL         -2

// Signal mapping for PTA6 pin
//   <o> PTA6 [GPIOA_6, KBI0_P6, FTM2_FLT1, ACMP1_IN0, ADC0_SE2]<name=PTA6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA6 pin
//     <-2=> ADC0_SE2 (reset default)<selection=ADC0_SE2_PIN_SEL,PTA6 (reset default)>
//     <0=> GPIOA_6<selection=GPIOA_6_PIN_SEL,PTA6>
//     <1=> KBI0_P6<selection=KBI0_P6_PIN_SEL,PTA6>
//     <2=> FTM2_FLT1<selection=FTM2_FLT1_PIN_SEL,PTA6>
//     <3=> ACMP1_IN0<selection=ACMP1_IN0_PIN_SEL,PTA6>
//     <4=> ADC0_SE2<selection=ADC0_SE2_PIN_SEL,PTA6>
//     <-2=> Default
#define PTA6_SIG_SEL         -2

// Signal mapping for PTA7 pin
//   <o> PTA7 [GPIOA_7, KBI0_P7, FTM2_FLT2, ACMP1_IN1, ADC0_SE3]<name=PTA7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA7 pin
//     <-2=> ADC0_SE3 (reset default)<selection=ADC0_SE3_PIN_SEL,PTA7 (reset default)>
//     <0=> GPIOA_7<selection=GPIOA_7_PIN_SEL,PTA7>
//     <1=> KBI0_P7<selection=KBI0_P7_PIN_SEL,PTA7>
//     <2=> FTM2_FLT2<selection=FTM2_FLT2_PIN_SEL,PTA7>
//     <3=> ACMP1_IN1<selection=ACMP1_IN1_PIN_SEL,PTA7>
//     <4=> ADC0_SE3<selection=ADC0_SE3_PIN_SEL,PTA7>
//     <-2=> Default
#define PTA7_SIG_SEL         -2

// </h>

// <h> Port B Pins

// Signal mapping for PTB0 pin
//   <o> PTB0 [GPIOA_8, KBI0_P8, UART0_RX, PWT_IN1, ADC0_SE4]<name=PTB0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB0 pin
//     <-2=> ADC0_SE4 (reset default)<selection=ADC0_SE4_PIN_SEL,PTB0 (reset default)>
//     <0=> GPIOA_8<selection=GPIOA_8_PIN_SEL,PTB0>
//     <1=> KBI0_P8<selection=KBI0_P8_PIN_SEL,PTB0>
//     <2=> UART0_RX<selection=UART0_RX_PIN_SEL,PTB0>
//     <3=> PWT_IN1<selection=PWT_IN1_PIN_SEL,PTB0>
//     <4=> ADC0_SE4<selection=ADC0_SE4_PIN_SEL,PTB0>
//     <-2=> Default
#define PTB0_SIG_SEL         -2

// Signal mapping for PTB1 pin
//   <o> PTB1 [GPIOA_9, KBI0_P9, UART0_TX, ADC0_SE5]<name=PTB1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB1 pin
//     <-2=> ADC0_SE5 (reset default)<selection=ADC0_SE5_PIN_SEL,PTB1 (reset default)>
//     <0=> GPIOA_9<selection=GPIOA_9_PIN_SEL,PTB1>
//     <1=> KBI0_P9<selection=KBI0_P9_PIN_SEL,PTB1>
//     <2=> UART0_TX<selection=UART0_TX_PIN_SEL,PTB1>
//     <4=> ADC0_SE5<selection=ADC0_SE5_PIN_SEL,PTB1>
//     <-2=> Default
#define PTB1_SIG_SEL         -2

// Signal mapping for PTB2 pin
//   <o> PTB2 [GPIOA_10, KBI0_P10, SPI0_SCK, FTM0_CH0, ADC0_SE6]<name=PTB2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB2 pin
//     <-2=> ADC0_SE6 (reset default)<selection=ADC0_SE6_PIN_SEL,PTB2 (reset default)>
//     <0=> GPIOA_10<selection=GPIOA_10_PIN_SEL,PTB2>
//     <1=> KBI0_P10<selection=KBI0_P10_PIN_SEL,PTB2>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTB2>
//     <3=> FTM0_CH0<selection=FTM0_CH0_PIN_SEL,PTB2>
//     <4=> ADC0_SE6<selection=ADC0_SE6_PIN_SEL,PTB2>
//     <-2=> Default
#define PTB2_SIG_SEL         -2

// Signal mapping for PTB3 pin
//   <o> PTB3 [GPIOA_11, KBI0_P11, SPI0_MOSI, FTM0_CH1, ADC0_SE7]<name=PTB3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB3 pin
//     <-2=> ADC0_SE7 (reset default)<selection=ADC0_SE7_PIN_SEL,PTB3 (reset default)>
//     <0=> GPIOA_11<selection=GPIOA_11_PIN_SEL,PTB3>
//     <1=> KBI0_P11<selection=KBI0_P11_PIN_SEL,PTB3>
//     <2=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTB3>
//     <3=> FTM0_CH1<selection=FTM0_CH1_PIN_SEL,PTB3>
//     <4=> ADC0_SE7<selection=ADC0_SE7_PIN_SEL,PTB3>
//     <-2=> Default
#define PTB3_SIG_SEL         -2

// Signal mapping for PTB4 pin
//   <o> PTB4 [GPIOA_12, KBI0_P12, FTM2_CH4, SPI0_MISO, ACMP1_IN2, NMI_b]<name=PTB4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB4 pin
//     <-2=> NMI_b (reset default)<selection=NMI_b_PIN_SEL,PTB4 (reset default)>
//     <0=> GPIOA_12<selection=GPIOA_12_PIN_SEL,PTB4>
//     <1=> KBI0_P12<selection=KBI0_P12_PIN_SEL,PTB4>
//     <2=> FTM2_CH4<selection=FTM2_CH4_PIN_SEL,PTB4>
//     <3=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTB4>
//     <4=> ACMP1_IN2<selection=ACMP1_IN2_PIN_SEL,PTB4>
//     <5=> NMI_b<selection=NMI_b_PIN_SEL,PTB4>
//     <-2=> Default
#define PTB4_SIG_SEL         -2

// Signal mapping for PTB5 pin
//   <o> PTB5 [GPIOA_13, KBI0_P13, FTM2_CH5, SPI0_PCS, ACMP1_OUT]<name=PTB5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB5 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_13<selection=GPIOA_13_PIN_SEL,PTB5>
//     <1=> KBI0_P13<selection=KBI0_P13_PIN_SEL,PTB5>
//     <2=> FTM2_CH5<selection=FTM2_CH5_PIN_SEL,PTB5>
//     <3=> SPI0_PCS<selection=SPI0_PCS_PIN_SEL,PTB5>
//     <4=> ACMP1_OUT<selection=ACMP1_OUT_PIN_SEL,PTB5>
//     <-2=> Default
#define PTB5_SIG_SEL         -2

// Signal mapping for PTB6 pin
//   <o> PTB6 [GPIOA_14, KBI0_P14, I2C0_SDA, XTAL]<name=PTB6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB6 pin
//     <-2=> XTAL (reset default)<selection=XTAL_PIN_SEL,PTB6 (reset default)>
//     <0=> GPIOA_14<selection=GPIOA_14_PIN_SEL,PTB6>
//     <1=> KBI0_P14<selection=KBI0_P14_PIN_SEL,PTB6>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTB6>
//     <6=> XTAL<selection=XTAL_PIN_SEL,PTB6>
//     <-2=> Default
#define PTB6_SIG_SEL         -2

// Signal mapping for PTB7 pin
//   <o> PTB7 [GPIOA_15, KBI0_P15, I2C0_SCL, EXTAL]<name=PTB7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB7 pin
//     <-2=> EXTAL (reset default)<selection=EXTAL_PIN_SEL,PTB7 (reset default)>
//     <0=> GPIOA_15<selection=GPIOA_15_PIN_SEL,PTB7>
//     <1=> KBI0_P15<selection=KBI0_P15_PIN_SEL,PTB7>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTB7>
//     <6=> EXTAL<selection=EXTAL_PIN_SEL,PTB7>
//     <-2=> Default
#define PTB7_SIG_SEL         -2

// </h>

// <h> Port C Pins

// Signal mapping for PTC0 pin
//   <o> PTC0 [GPIOA_16, KBI0_P16, FTM2_CH0, ADC0_SE8]<name=PTC0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC0 pin
//     <-2=> ADC0_SE8 (reset default)<selection=ADC0_SE8_PIN_SEL,PTC0 (reset default)>
//     <0=> GPIOA_16<selection=GPIOA_16_PIN_SEL,PTC0>
//     <1=> KBI0_P16<selection=KBI0_P16_PIN_SEL,PTC0>
//     <2=> FTM2_CH0<selection=FTM2_CH0_PIN_SEL,PTC0>
//     <4=> ADC0_SE8<selection=ADC0_SE8_PIN_SEL,PTC0>
//     <-2=> Default
#define PTC0_SIG_SEL         -2

// Signal mapping for PTC1 pin
//   <o> PTC1 [GPIOA_17, KBI0_P17, FTM2_CH1, ADC0_SE9]<name=PTC1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC1 pin
//     <-2=> ADC0_SE9 (reset default)<selection=ADC0_SE9_PIN_SEL,PTC1 (reset default)>
//     <0=> GPIOA_17<selection=GPIOA_17_PIN_SEL,PTC1>
//     <1=> KBI0_P17<selection=KBI0_P17_PIN_SEL,PTC1>
//     <2=> FTM2_CH1<selection=FTM2_CH1_PIN_SEL,PTC1>
//     <4=> ADC0_SE9<selection=ADC0_SE9_PIN_SEL,PTC1>
//     <-2=> Default
#define PTC1_SIG_SEL         -2

// Signal mapping for PTC2 pin
//   <o> PTC2 [GPIOA_18, KBI0_P18, FTM2_CH2, ADC0_SE10]<name=PTC2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC2 pin
//     <-2=> ADC0_SE10 (reset default)<selection=ADC0_SE10_PIN_SEL,PTC2 (reset default)>
//     <0=> GPIOA_18<selection=GPIOA_18_PIN_SEL,PTC2>
//     <1=> KBI0_P18<selection=KBI0_P18_PIN_SEL,PTC2>
//     <2=> FTM2_CH2<selection=FTM2_CH2_PIN_SEL,PTC2>
//     <4=> ADC0_SE10<selection=ADC0_SE10_PIN_SEL,PTC2>
//     <-2=> Default
#define PTC2_SIG_SEL         -2

// Signal mapping for PTC3 pin
//   <o> PTC3 [GPIOA_19, KBI0_P19, FTM2_CH3, ADC0_SE11]<name=PTC3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC3 pin
//     <-2=> ADC0_SE11 (reset default)<selection=ADC0_SE11_PIN_SEL,PTC3 (reset default)>
//     <0=> GPIOA_19<selection=GPIOA_19_PIN_SEL,PTC3>
//     <1=> KBI0_P19<selection=KBI0_P19_PIN_SEL,PTC3>
//     <2=> FTM2_CH3<selection=FTM2_CH3_PIN_SEL,PTC3>
//     <4=> ADC0_SE11<selection=ADC0_SE11_PIN_SEL,PTC3>
//     <-2=> Default
#define PTC3_SIG_SEL         -2

// Signal mapping for PTC4 pin
//   <o> PTC4 [GPIOA_20, KBI0_P20, RTC_CLKOUT, FTM1_CH0, ACMP0_IN2, SWD_CLK]<name=PTC4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC4 pin
//     <-2=> SWD_CLK (reset default)<selection=SWD_CLK_PIN_SEL,PTC4 (reset default)>
//     <0=> GPIOA_20<selection=GPIOA_20_PIN_SEL,PTC4>
//     <1=> KBI0_P20<selection=KBI0_P20_PIN_SEL,PTC4>
//     <2=> RTC_CLKOUT<selection=RTC_CLKOUT_PIN_SEL,PTC4>
//     <3=> FTM1_CH0<selection=FTM1_CH0_PIN_SEL,PTC4>
//     <4=> ACMP0_IN2<selection=ACMP0_IN2_PIN_SEL,PTC4>
//     <5=> SWD_CLK<selection=SWD_CLK_PIN_SEL,PTC4>
//     <-2=> Default
#define PTC4_SIG_SEL         -2

// Signal mapping for PTC5 pin
//   <o> PTC5 [GPIOA_21, KBI0_P21, FTM1_CH1, RTC_CLKOUT]<name=PTC5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC5 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_21<selection=GPIOA_21_PIN_SEL,PTC5>
//     <1=> KBI0_P21<selection=KBI0_P21_PIN_SEL,PTC5>
//     <3=> FTM1_CH1<selection=FTM1_CH1_PIN_SEL,PTC5>
//     <5=> RTC_CLKOUT<selection=RTC_CLKOUT_PIN_SEL,PTC5>
//     <-2=> Default
#define PTC5_SIG_SEL         -2

// Signal mapping for PTC6 pin
//   <o> PTC6 [GPIOA_22, KBI0_P22, UART1_RX, CAN0_RX]<name=PTC6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC6 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_22<selection=GPIOA_22_PIN_SEL,PTC6>
//     <1=> KBI0_P22<selection=KBI0_P22_PIN_SEL,PTC6>
//     <2=> UART1_RX<selection=UART1_RX_PIN_SEL,PTC6>
//     <5=> CAN0_RX<selection=CAN0_RX_PIN_SEL,PTC6>
//     <-2=> Default
#define PTC6_SIG_SEL         -2

// Signal mapping for PTC7 pin
//   <o> PTC7 [GPIOA_23, KBI0_P23, UART1_TX, CAN0_TX]<name=PTC7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC7 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_23<selection=GPIOA_23_PIN_SEL,PTC7>
//     <1=> KBI0_P23<selection=KBI0_P23_PIN_SEL,PTC7>
//     <2=> UART1_TX<selection=UART1_TX_PIN_SEL,PTC7>
//     <5=> CAN0_TX<selection=CAN0_TX_PIN_SEL,PTC7>
//     <-2=> Default
#define PTC7_SIG_SEL         -2

// </h>

// <h> Port D Pins

// Signal mapping for PTD0 pin
//   <o> PTD0 [GPIOA_24, KBI0_P24, FTM2_CH2, SPI1_SCK]<name=PTD0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD0 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_24<selection=GPIOA_24_PIN_SEL,PTD0>
//     <1=> KBI0_P24<selection=KBI0_P24_PIN_SEL,PTD0>
//     <2=> FTM2_CH2<selection=FTM2_CH2_PIN_SEL,PTD0>
//     <3=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTD0>
//     <-2=> Default
#define PTD0_SIG_SEL         -2

// Signal mapping for PTD1 pin
//   <o> PTD1 [GPIOA_25, KBI0_P25, FTM2_CH3, SPI1_MOSI]<name=PTD1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD1 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_25<selection=GPIOA_25_PIN_SEL,PTD1>
//     <1=> KBI0_P25<selection=KBI0_P25_PIN_SEL,PTD1>
//     <2=> FTM2_CH3<selection=FTM2_CH3_PIN_SEL,PTD1>
//     <3=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTD1>
//     <-2=> Default
#define PTD1_SIG_SEL         -2

// Signal mapping for PTD2 pin
//   <o> PTD2 [GPIOA_26, KBI0_P26, SPI1_MISO]<name=PTD2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD2 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_26<selection=GPIOA_26_PIN_SEL,PTD2>
//     <1=> KBI0_P26<selection=KBI0_P26_PIN_SEL,PTD2>
//     <2=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTD2>
//     <-2=> Default
#define PTD2_SIG_SEL         -2

// Signal mapping for PTD3 pin
//   <o> PTD3 [GPIOA_27, KBI0_P27, SPI1_PCS]<name=PTD3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD3 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_27<selection=GPIOA_27_PIN_SEL,PTD3>
//     <1=> KBI0_P27<selection=KBI0_P27_PIN_SEL,PTD3>
//     <2=> SPI1_PCS<selection=SPI1_PCS_PIN_SEL,PTD3>
//     <-2=> Default
#define PTD3_SIG_SEL         -2

// Signal mapping for PTD4 pin
//   <o> PTD4 [GPIOA_28, KBI0_P28]<name=PTD4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD4 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_28<selection=GPIOA_28_PIN_SEL,PTD4>
//     <1=> KBI0_P28<selection=KBI0_P28_PIN_SEL,PTD4>
//     <-2=> Default
#define PTD4_SIG_SEL         -2

// Signal mapping for PTD5 pin
//   <o> PTD5 [GPIOA_29, KBI0_P29, PWT_IN0]<name=PTD5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD5 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_29<selection=GPIOA_29_PIN_SEL,PTD5>
//     <1=> KBI0_P29<selection=KBI0_P29_PIN_SEL,PTD5>
//     <2=> PWT_IN0<selection=PWT_IN0_PIN_SEL,PTD5>
//     <-2=> Default
#define PTD5_SIG_SEL         -2

// Signal mapping for PTD6 pin
//   <o> PTD6 [GPIOA_30, KBI0_P30, UART2_RX]<name=PTD6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD6 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_30<selection=GPIOA_30_PIN_SEL,PTD6>
//     <1=> KBI0_P30<selection=KBI0_P30_PIN_SEL,PTD6>
//     <2=> UART2_RX<selection=UART2_RX_PIN_SEL,PTD6>
//     <-2=> Default
#define PTD6_SIG_SEL         -2

// Signal mapping for PTD7 pin
//   <o> PTD7 [GPIOA_31, KBI0_P31, UART2_TX]<name=PTD7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD7 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_31<selection=GPIOA_31_PIN_SEL,PTD7>
//     <1=> KBI0_P31<selection=KBI0_P31_PIN_SEL,PTD7>
//     <2=> UART2_TX<selection=UART2_TX_PIN_SEL,PTD7>
//     <-2=> Default
#define PTD7_SIG_SEL         -2

// </h>

// <h> Port E Pins

// Signal mapping for PTE0 pin
//   <o> PTE0 [GPIOB_0, KBI1_P0, SPI0_SCK, TCLK1, I2C1_SDA]<name=PTE0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE0 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_0<selection=GPIOB_0_PIN_SEL,PTE0>
//     <1=> KBI1_P0<selection=KBI1_P0_PIN_SEL,PTE0>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTE0>
//     <3=> TCLK1<selection=TCLK1_PIN_SEL,PTE0>
//     <4=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTE0>
//     <-2=> Default
#define PTE0_SIG_SEL         -2

// Signal mapping for PTE1 pin
//   <o> PTE1 [GPIOB_1, KBI1_P1, SPI0_MOSI, I2C1_SCL]<name=PTE1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE1 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_1<selection=GPIOB_1_PIN_SEL,PTE1>
//     <1=> KBI1_P1<selection=KBI1_P1_PIN_SEL,PTE1>
//     <2=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTE1>
//     <4=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTE1>
//     <-2=> Default
#define PTE1_SIG_SEL         -2

// Signal mapping for PTE2 pin
//   <o> PTE2 [GPIOB_2, KBI1_P2, SPI0_MISO, PWT_IN0]<name=PTE2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE2 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_2<selection=GPIOB_2_PIN_SEL,PTE2>
//     <1=> KBI1_P2<selection=KBI1_P2_PIN_SEL,PTE2>
//     <2=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTE2>
//     <3=> PWT_IN0<selection=PWT_IN0_PIN_SEL,PTE2>
//     <-2=> Default
#define PTE2_SIG_SEL         -2

// Signal mapping for PTE3 pin
//   <o> PTE3 [GPIOB_3, KBI1_P3, SPI0_PCS]<name=PTE3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE3 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_3<selection=GPIOB_3_PIN_SEL,PTE3>
//     <1=> KBI1_P3<selection=KBI1_P3_PIN_SEL,PTE3>
//     <2=> SPI0_PCS<selection=SPI0_PCS_PIN_SEL,PTE3>
//     <-2=> Default
#define PTE3_SIG_SEL         -2

// Signal mapping for PTE4 pin
//   <o> PTE4 [GPIOB_4, KBI1_P4]<name=PTE4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE4 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_4<selection=GPIOB_4_PIN_SEL,PTE4>
//     <1=> KBI1_P4<selection=KBI1_P4_PIN_SEL,PTE4>
//     <-2=> Default
#define PTE4_SIG_SEL         -2

// Signal mapping for PTE5 pin
//   <o> PTE5 [GPIOB_5, KBI1_P5]<name=PTE5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE5 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_5<selection=GPIOB_5_PIN_SEL,PTE5>
//     <1=> KBI1_P5<selection=KBI1_P5_PIN_SEL,PTE5>
//     <-2=> Default
#define PTE5_SIG_SEL         -2

// Signal mapping for PTE6 pin
//   <o> PTE6 [GPIOB_6, KBI1_P6]<name=PTE6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE6 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_6<selection=GPIOB_6_PIN_SEL,PTE6>
//     <1=> KBI1_P6<selection=KBI1_P6_PIN_SEL,PTE6>
//     <-2=> Default
#define PTE6_SIG_SEL         -2

// Signal mapping for PTE7 pin
//   <o> PTE7 [GPIOB_7, KBI1_P7, TCLK2, FTM1_CH1, CAN0_TX]<name=PTE7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE7 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_7<selection=GPIOB_7_PIN_SEL,PTE7>
//     <1=> KBI1_P7<selection=KBI1_P7_PIN_SEL,PTE7>
//     <2=> TCLK2<selection=TCLK2_PIN_SEL,PTE7>
//     <4=> FTM1_CH1<selection=FTM1_CH1_PIN_SEL,PTE7>
//     <5=> CAN0_TX<selection=CAN0_TX_PIN_SEL,PTE7>
//     <-2=> Default
#define PTE7_SIG_SEL         -2

// </h>

// <h> Port F Pins

// Signal mapping for PTF0 pin
//   <o> PTF0 [GPIOB_8, KBI1_P8, FTM2_CH0]<name=PTF0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTF0 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_8<selection=GPIOB_8_PIN_SEL,PTF0>
//     <1=> KBI1_P8<selection=KBI1_P8_PIN_SEL,PTF0>
//     <2=> FTM2_CH0<selection=FTM2_CH0_PIN_SEL,PTF0>
//     <-2=> Default
#define PTF0_SIG_SEL         -2

// Signal mapping for PTF1 pin
//   <o> PTF1 [GPIOB_9, KBI1_P9, FTM2_CH1]<name=PTF1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTF1 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_9<selection=GPIOB_9_PIN_SEL,PTF1>
//     <1=> KBI1_P9<selection=KBI1_P9_PIN_SEL,PTF1>
//     <2=> FTM2_CH1<selection=FTM2_CH1_PIN_SEL,PTF1>
//     <-2=> Default
#define PTF1_SIG_SEL         -2

// Signal mapping for PTF2 pin
//   <o> PTF2 [GPIOB_10, KBI1_P10, UART1_RX]<name=PTF2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTF2 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_10<selection=GPIOB_10_PIN_SEL,PTF2>
//     <1=> KBI1_P10<selection=KBI1_P10_PIN_SEL,PTF2>
//     <2=> UART1_RX<selection=UART1_RX_PIN_SEL,PTF2>
//     <-2=> Default
#define PTF2_SIG_SEL         -2

// Signal mapping for PTF3 pin
//   <o> PTF3 [GPIOB_11, KBI1_P11, UART1_TX]<name=PTF3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTF3 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_11<selection=GPIOB_11_PIN_SEL,PTF3>
//     <1=> KBI1_P11<selection=KBI1_P11_PIN_SEL,PTF3>
//     <2=> UART1_TX<selection=UART1_TX_PIN_SEL,PTF3>
//     <-2=> Default
#define PTF3_SIG_SEL         -2

// Signal mapping for PTF4 pin
//   <o> PTF4 [GPIOB_12, KBI1_P12, ADC0_SE12]<name=PTF4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTF4 pin
//     <-2=> ADC0_SE12 (reset default)<selection=ADC0_SE12_PIN_SEL,PTF4 (reset default)>
//     <0=> GPIOB_12<selection=GPIOB_12_PIN_SEL,PTF4>
//     <1=> KBI1_P12<selection=KBI1_P12_PIN_SEL,PTF4>
//     <4=> ADC0_SE12<selection=ADC0_SE12_PIN_SEL,PTF4>
//     <-2=> Default
#define PTF4_SIG_SEL         -2

// Signal mapping for PTF5 pin
//   <o> PTF5 [GPIOB_13, KBI1_P13, ADC0_SE13]<name=PTF5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTF5 pin
//     <-2=> ADC0_SE13 (reset default)<selection=ADC0_SE13_PIN_SEL,PTF5 (reset default)>
//     <0=> GPIOB_13<selection=GPIOB_13_PIN_SEL,PTF5>
//     <1=> KBI1_P13<selection=KBI1_P13_PIN_SEL,PTF5>
//     <4=> ADC0_SE13<selection=ADC0_SE13_PIN_SEL,PTF5>
//     <-2=> Default
#define PTF5_SIG_SEL         -2

// Signal mapping for PTF6 pin
//   <o> PTF6 [GPIOB_14, KBI1_P14, ADC0_SE14]<name=PTF6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTF6 pin
//     <-2=> ADC0_SE14 (reset default)<selection=ADC0_SE14_PIN_SEL,PTF6 (reset default)>
//     <0=> GPIOB_14<selection=GPIOB_14_PIN_SEL,PTF6>
//     <1=> KBI1_P14<selection=KBI1_P14_PIN_SEL,PTF6>
//     <4=> ADC0_SE14<selection=ADC0_SE14_PIN_SEL,PTF6>
//     <-2=> Default
#define PTF6_SIG_SEL         -2

// Signal mapping for PTF7 pin
//   <o> PTF7 [GPIOB_15, KBI1_P15, ADC0_SE15]<name=PTF7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTF7 pin
//     <-2=> ADC0_SE15 (reset default)<selection=ADC0_SE15_PIN_SEL,PTF7 (reset default)>
//     <0=> GPIOB_15<selection=GPIOB_15_PIN_SEL,PTF7>
//     <1=> KBI1_P15<selection=KBI1_P15_PIN_SEL,PTF7>
//     <4=> ADC0_SE15<selection=ADC0_SE15_PIN_SEL,PTF7>
//     <-2=> Default
#define PTF7_SIG_SEL         -2

// </h>

// <h> Port G Pins

// Signal mapping for PTG0 pin
//   <o> PTG0 [GPIOB_16, KBI1_P16]<name=PTG0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTG0 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_16<selection=GPIOB_16_PIN_SEL,PTG0>
//     <1=> KBI1_P16<selection=KBI1_P16_PIN_SEL,PTG0>
//     <-2=> Default
#define PTG0_SIG_SEL         -2

// Signal mapping for PTG1 pin
//   <o> PTG1 [GPIOB_17, KBI1_P17]<name=PTG1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTG1 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_17<selection=GPIOB_17_PIN_SEL,PTG1>
//     <1=> KBI1_P17<selection=KBI1_P17_PIN_SEL,PTG1>
//     <-2=> Default
#define PTG1_SIG_SEL         -2

// Signal mapping for PTG2 pin
//   <o> PTG2 [GPIOB_18, KBI1_P18]<name=PTG2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTG2 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_18<selection=GPIOB_18_PIN_SEL,PTG2>
//     <1=> KBI1_P18<selection=KBI1_P18_PIN_SEL,PTG2>
//     <-2=> Default
#define PTG2_SIG_SEL         -2

// Signal mapping for PTG3 pin
//   <o> PTG3 [GPIOB_19, KBI1_P19]<name=PTG3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTG3 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_19<selection=GPIOB_19_PIN_SEL,PTG3>
//     <1=> KBI1_P19<selection=KBI1_P19_PIN_SEL,PTG3>
//     <-2=> Default
#define PTG3_SIG_SEL         -2

// Signal mapping for PTG4 pin
//   <o> PTG4 [GPIOB_20, KBI1_P20, FTM2_CH2, SPI1_SCK]<name=PTG4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTG4 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_20<selection=GPIOB_20_PIN_SEL,PTG4>
//     <1=> KBI1_P20<selection=KBI1_P20_PIN_SEL,PTG4>
//     <2=> FTM2_CH2<selection=FTM2_CH2_PIN_SEL,PTG4>
//     <3=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTG4>
//     <-2=> Default
#define PTG4_SIG_SEL         -2

// Signal mapping for PTG5 pin
//   <o> PTG5 (Alias:LED_RED) [GPIOB_21, KBI1_P21, FTM2_CH3, SPI1_MOSI]<name=PTG5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTG5 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_21<selection=GPIOB_21_PIN_SEL,PTG5 (Alias:LED_RED)>
//     <1=> KBI1_P21<selection=KBI1_P21_PIN_SEL,PTG5 (Alias:LED_RED)>
//     <2=> FTM2_CH3<selection=FTM2_CH3_PIN_SEL,PTG5 (Alias:LED_RED)>
//     <3=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTG5 (Alias:LED_RED)>
//     <0=> Default
#define PTG5_SIG_SEL         0

// Signal mapping for PTG6 pin
//   <o> PTG6 (Alias:LED_GREEN) [GPIOB_22, KBI1_P22, FTM2_CH4, SPI1_MISO]<name=PTG6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTG6 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_22<selection=GPIOB_22_PIN_SEL,PTG6 (Alias:LED_GREEN)>
//     <1=> KBI1_P22<selection=KBI1_P22_PIN_SEL,PTG6 (Alias:LED_GREEN)>
//     <2=> FTM2_CH4<selection=FTM2_CH4_PIN_SEL,PTG6 (Alias:LED_GREEN)>
//     <3=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTG6 (Alias:LED_GREEN)>
//     <0=> Default
#define PTG6_SIG_SEL         0

// Signal mapping for PTG7 pin
//   <o> PTG7 (Alias:LED_BLUE) [GPIOB_23, KBI1_P23, FTM2_CH5, SPI1_PCS]<name=PTG7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTG7 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_23<selection=GPIOB_23_PIN_SEL,PTG7 (Alias:LED_BLUE)>
//     <1=> KBI1_P23<selection=KBI1_P23_PIN_SEL,PTG7 (Alias:LED_BLUE)>
//     <2=> FTM2_CH5<selection=FTM2_CH5_PIN_SEL,PTG7 (Alias:LED_BLUE)>
//     <3=> SPI1_PCS<selection=SPI1_PCS_PIN_SEL,PTG7 (Alias:LED_BLUE)>
//     <0=> Default
#define PTG7_SIG_SEL         0

// </h>

// <h> Port H Pins

// Signal mapping for PTH0 pin
//   <o> PTH0 [GPIOB_24, KBI1_P24, FTM2_CH0]<name=PTH0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTH0 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_24<selection=GPIOB_24_PIN_SEL,PTH0>
//     <1=> KBI1_P24<selection=KBI1_P24_PIN_SEL,PTH0>
//     <2=> FTM2_CH0<selection=FTM2_CH0_PIN_SEL,PTH0>
//     <-2=> Default
#define PTH0_SIG_SEL         -2

// Signal mapping for PTH1 pin
//   <o> PTH1 [GPIOB_25, KBI1_P25, FTM2_CH1]<name=PTH1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTH1 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_25<selection=GPIOB_25_PIN_SEL,PTH1>
//     <1=> KBI1_P25<selection=KBI1_P25_PIN_SEL,PTH1>
//     <2=> FTM2_CH1<selection=FTM2_CH1_PIN_SEL,PTH1>
//     <-2=> Default
#define PTH1_SIG_SEL         -2

// Signal mapping for PTH2 pin
//   <o> PTH2 [GPIOB_26, KBI1_P26, BUSOUT, FTM1_CH0, CAN0_RX]<name=PTH2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTH2 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_26<selection=GPIOB_26_PIN_SEL,PTH2>
//     <1=> KBI1_P26<selection=KBI1_P26_PIN_SEL,PTH2>
//     <2=> BUSOUT<selection=BUSOUT_PIN_SEL,PTH2>
//     <4=> FTM1_CH0<selection=FTM1_CH0_PIN_SEL,PTH2>
//     <5=> CAN0_RX<selection=CAN0_RX_PIN_SEL,PTH2>
//     <-2=> Default
#define PTH2_SIG_SEL         -2

// Signal mapping for PTH3 pin
//   <o> PTH3 [GPIOB_27, KBI1_P27, I2C1_SDA]<name=PTH3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTH3 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_27<selection=GPIOB_27_PIN_SEL,PTH3>
//     <1=> KBI1_P27<selection=KBI1_P27_PIN_SEL,PTH3>
//     <2=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTH3>
//     <-2=> Default
#define PTH3_SIG_SEL         -2

// Signal mapping for PTH4 pin
//   <o> PTH4 [GPIOB_28, KBI1_P28, I2C1_SCL]<name=PTH4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTH4 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_28<selection=GPIOB_28_PIN_SEL,PTH4>
//     <1=> KBI1_P28<selection=KBI1_P28_PIN_SEL,PTH4>
//     <2=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTH4>
//     <-2=> Default
#define PTH4_SIG_SEL         -2

// Signal mapping for PTH5 pin
//   <o> PTH5 [GPIOB_29, KBI1_P29]<name=PTH5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTH5 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_29<selection=GPIOB_29_PIN_SEL,PTH5>
//     <1=> KBI1_P29<selection=KBI1_P29_PIN_SEL,PTH5>
//     <-2=> Default
#define PTH5_SIG_SEL         -2

// Signal mapping for PTH6 pin
//   <o> PTH6 [GPIOB_30, KBI1_P30]<name=PTH6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTH6 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_30<selection=GPIOB_30_PIN_SEL,PTH6>
//     <1=> KBI1_P30<selection=KBI1_P30_PIN_SEL,PTH6>
//     <-2=> Default
#define PTH6_SIG_SEL         -2

// Signal mapping for PTH7 pin
//   <o> PTH7 [GPIOB_31, KBI1_P31, PWT_IN1]<name=PTH7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTH7 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_31<selection=GPIOB_31_PIN_SEL,PTH7>
//     <1=> KBI1_P31<selection=KBI1_P31_PIN_SEL,PTH7>
//     <2=> PWT_IN1<selection=PWT_IN1_PIN_SEL,PTH7>
//     <-2=> Default
#define PTH7_SIG_SEL         -2

// </h>

// <h> Port I Pins

// Signal mapping for PTI0 pin
//   <o> PTI0 [GPIOC_0, IRQ, UART2_RX]<name=PTI0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTI0 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOC_0<selection=GPIOC_0_PIN_SEL,PTI0>
//     <2=> IRQ<selection=IRQ_PIN_SEL,PTI0>
//     <3=> UART2_RX<selection=UART2_RX_PIN_SEL,PTI0>
//     <-2=> Default
#define PTI0_SIG_SEL         -2

// Signal mapping for PTI1 pin
//   <o> PTI1 [GPIOC_1, IRQ, UART2_TX]<name=PTI1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTI1 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOC_1<selection=GPIOC_1_PIN_SEL,PTI1>
//     <2=> IRQ<selection=IRQ_PIN_SEL,PTI1>
//     <3=> UART2_TX<selection=UART2_TX_PIN_SEL,PTI1>
//     <-2=> Default
#define PTI1_SIG_SEL         -2

// Signal mapping for PTI2 pin
//   <o> PTI2 [GPIOC_2, IRQ]<name=PTI2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTI2 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOC_2<selection=GPIOC_2_PIN_SEL,PTI2>
//     <1=> IRQ<selection=IRQ_PIN_SEL,PTI2>
//     <-2=> Default
#define PTI2_SIG_SEL         -2

// Signal mapping for PTI3 pin
//   <o> PTI3 [GPIOC_3, IRQ]<name=PTI3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTI3 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOC_3<selection=GPIOC_3_PIN_SEL,PTI3>
//     <1=> IRQ<selection=IRQ_PIN_SEL,PTI3>
//     <-2=> Default
#define PTI3_SIG_SEL         -2

// Signal mapping for PTI4 pin
//   <o> PTI4 [GPIOC_4, IRQ]<name=PTI4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTI4 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOC_4<selection=GPIOC_4_PIN_SEL,PTI4>
//     <2=> IRQ<selection=IRQ_PIN_SEL,PTI4>
//     <-2=> Default
#define PTI4_SIG_SEL         -2

// Signal mapping for PTI5 pin
//   <o> PTI5 [GPIOC_5, IRQ]<name=PTI5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTI5 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOC_5<selection=GPIOC_5_PIN_SEL,PTI5>
//     <1=> IRQ<selection=IRQ_PIN_SEL,PTI5>
//     <-2=> Default
#define PTI5_SIG_SEL         -2

// Signal mapping for PTI6 pin
//   <o> PTI6 [GPIOC_6, IRQ]<name=PTI6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTI6 pin
//     <-2=> Disabled (reset default)
//     <0=> GPIOC_6<selection=GPIOC_6_PIN_SEL,PTI6>
//     <1=> IRQ<selection=IRQ_PIN_SEL,PTI6>
//     <-2=> Default
#define PTI6_SIG_SEL         -2

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

// Pin Mapping for BUSOUT signal
//   <o> BUSOUT [PTH2]<name=BUSOUT_PIN_SEL>
//   <i> Shows which pin BUSOUT is mapped to
//     <0=> Disabled
//     <1=> PTH2<selection=PTH2_SIG_SEL,BUSOUT>
//     <0=> Default
#define BUSOUT_PIN_SEL       0
#if (BUSOUT_PIN_SEL == 1)
#define BUSOUT_GPIO          USBDM::GpioH<2>
#define BUSOUT_FN            2
#endif

// Pin Mapping for IRQ signal
//   <o> IRQ [PTI2, PTI3, PTI5, PTI6, PTA5, PTI0, PTI1, PTI4]<name=IRQ_PIN_SEL>
//   <i> Shows which pin IRQ is mapped to
//     <0=> Disabled
//     <1=> PTI2<selection=PTI2_SIG_SEL,IRQ>
//     <2=> PTI3<selection=PTI3_SIG_SEL,IRQ>
//     <3=> PTI5<selection=PTI5_SIG_SEL,IRQ>
//     <4=> PTI6<selection=PTI6_SIG_SEL,IRQ>
//     <5=> PTA5<selection=PTA5_SIG_SEL,IRQ>
//     <6=> PTI0<selection=PTI0_SIG_SEL,IRQ>
//     <7=> PTI1<selection=PTI1_SIG_SEL,IRQ>
//     <8=> PTI4<selection=PTI4_SIG_SEL,IRQ>
//     <0=> Default
#define IRQ_PIN_SEL          0
#if (IRQ_PIN_SEL == 1)
#define IRQ_GPIO             USBDM::GpioI<2>
#define IRQ_FN               1
#elif (IRQ_PIN_SEL == 2)
#define IRQ_GPIO             USBDM::GpioI<3>
#define IRQ_FN               1
#elif (IRQ_PIN_SEL == 3)
#define IRQ_GPIO             USBDM::GpioI<5>
#define IRQ_FN               1
#elif (IRQ_PIN_SEL == 4)
#define IRQ_GPIO             USBDM::GpioI<6>
#define IRQ_FN               1
#elif (IRQ_PIN_SEL == 5)
#define IRQ_GPIO             USBDM::GpioA<5>
#define IRQ_FN               2
#elif (IRQ_PIN_SEL == 6)
#define IRQ_GPIO             USBDM::GpioI<0>
#define IRQ_FN               2
#elif (IRQ_PIN_SEL == 7)
#define IRQ_GPIO             USBDM::GpioI<1>
#define IRQ_FN               2
#elif (IRQ_PIN_SEL == 8)
#define IRQ_GPIO             USBDM::GpioI<4>
#define IRQ_FN               2
#endif

// Pin Mapping for KBI0_P0 signal
//   <o> KBI0_P0 [PTA0]<name=KBI0_P0_PIN_SEL>
//   <i> Shows which pin KBI0_P0 is mapped to
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,KBI0_P0>
//     <0=> Default
#define KBI0_P0_PIN_SEL      0
#if (KBI0_P0_PIN_SEL == 1)
#define KBI0_P0_GPIO         USBDM::GpioA<0>
#define KBI0_P0_FN           1
#endif

// Pin Mapping for KBI0_P1 signal
//   <o> KBI0_P1 [PTA1]<name=KBI0_P1_PIN_SEL>
//   <i> Shows which pin KBI0_P1 is mapped to
//     <0=> Disabled
//     <1=> PTA1<selection=PTA1_SIG_SEL,KBI0_P1>
//     <0=> Default
#define KBI0_P1_PIN_SEL      0
#if (KBI0_P1_PIN_SEL == 1)
#define KBI0_P1_GPIO         USBDM::GpioA<1>
#define KBI0_P1_FN           1
#endif

// Pin Mapping for KBI0_P2 signal
//   <o> KBI0_P2 [PTA2]<name=KBI0_P2_PIN_SEL>
//   <i> Shows which pin KBI0_P2 is mapped to
//     <0=> Disabled
//     <1=> PTA2<selection=PTA2_SIG_SEL,KBI0_P2>
//     <0=> Default
#define KBI0_P2_PIN_SEL      0
#if (KBI0_P2_PIN_SEL == 1)
#define KBI0_P2_GPIO         USBDM::GpioA<2>
#define KBI0_P2_FN           1
#endif

// Pin Mapping for KBI0_P3 signal
//   <o> KBI0_P3 [PTA3]<name=KBI0_P3_PIN_SEL>
//   <i> Shows which pin KBI0_P3 is mapped to
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,KBI0_P3>
//     <0=> Default
#define KBI0_P3_PIN_SEL      0
#if (KBI0_P3_PIN_SEL == 1)
#define KBI0_P3_GPIO         USBDM::GpioA<3>
#define KBI0_P3_FN           1
#endif

// Pin Mapping for KBI0_P4 signal
//   <o> KBI0_P4 [PTA4]<name=KBI0_P4_PIN_SEL>
//   <i> Shows which pin KBI0_P4 is mapped to
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,KBI0_P4>
//     <0=> Default
#define KBI0_P4_PIN_SEL      0
#if (KBI0_P4_PIN_SEL == 1)
#define KBI0_P4_GPIO         USBDM::GpioA<4>
#define KBI0_P4_FN           1
#endif

// Pin Mapping for KBI0_P5 signal
//   <o> KBI0_P5 [PTA5]<name=KBI0_P5_PIN_SEL>
//   <i> Shows which pin KBI0_P5 is mapped to
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,KBI0_P5>
//     <0=> Default
#define KBI0_P5_PIN_SEL      0
#if (KBI0_P5_PIN_SEL == 1)
#define KBI0_P5_GPIO         USBDM::GpioA<5>
#define KBI0_P5_FN           1
#endif

// Pin Mapping for KBI0_P6 signal
//   <o> KBI0_P6 [PTA6]<name=KBI0_P6_PIN_SEL>
//   <i> Shows which pin KBI0_P6 is mapped to
//     <0=> Disabled
//     <1=> PTA6<selection=PTA6_SIG_SEL,KBI0_P6>
//     <0=> Default
#define KBI0_P6_PIN_SEL      0
#if (KBI0_P6_PIN_SEL == 1)
#define KBI0_P6_GPIO         USBDM::GpioA<6>
#define KBI0_P6_FN           1
#endif

// Pin Mapping for KBI0_P7 signal
//   <o> KBI0_P7 [PTA7]<name=KBI0_P7_PIN_SEL>
//   <i> Shows which pin KBI0_P7 is mapped to
//     <0=> Disabled
//     <1=> PTA7<selection=PTA7_SIG_SEL,KBI0_P7>
//     <0=> Default
#define KBI0_P7_PIN_SEL      0
#if (KBI0_P7_PIN_SEL == 1)
#define KBI0_P7_GPIO         USBDM::GpioA<7>
#define KBI0_P7_FN           1
#endif

// Pin Mapping for KBI0_P8 signal
//   <o> KBI0_P8 [PTB0]<name=KBI0_P8_PIN_SEL>
//   <i> Shows which pin KBI0_P8 is mapped to
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,KBI0_P8>
//     <0=> Default
#define KBI0_P8_PIN_SEL      0
#if (KBI0_P8_PIN_SEL == 1)
#define KBI0_P8_GPIO         USBDM::GpioB<0>
#define KBI0_P8_FN           1
#endif

// Pin Mapping for KBI0_P9 signal
//   <o> KBI0_P9 [PTB1]<name=KBI0_P9_PIN_SEL>
//   <i> Shows which pin KBI0_P9 is mapped to
//     <0=> Disabled
//     <1=> PTB1<selection=PTB1_SIG_SEL,KBI0_P9>
//     <0=> Default
#define KBI0_P9_PIN_SEL      0
#if (KBI0_P9_PIN_SEL == 1)
#define KBI0_P9_GPIO         USBDM::GpioB<1>
#define KBI0_P9_FN           1
#endif

// Pin Mapping for KBI0_P10 signal
//   <o> KBI0_P10 [PTB2]<name=KBI0_P10_PIN_SEL>
//   <i> Shows which pin KBI0_P10 is mapped to
//     <0=> Disabled
//     <1=> PTB2<selection=PTB2_SIG_SEL,KBI0_P10>
//     <0=> Default
#define KBI0_P10_PIN_SEL     0
#if (KBI0_P10_PIN_SEL == 1)
#define KBI0_P10_GPIO        USBDM::GpioB<2>
#define KBI0_P10_FN          1
#endif

// Pin Mapping for KBI0_P11 signal
//   <o> KBI0_P11 [PTB3]<name=KBI0_P11_PIN_SEL>
//   <i> Shows which pin KBI0_P11 is mapped to
//     <0=> Disabled
//     <1=> PTB3<selection=PTB3_SIG_SEL,KBI0_P11>
//     <0=> Default
#define KBI0_P11_PIN_SEL     0
#if (KBI0_P11_PIN_SEL == 1)
#define KBI0_P11_GPIO        USBDM::GpioB<3>
#define KBI0_P11_FN          1
#endif

// Pin Mapping for KBI0_P12 signal
//   <o> KBI0_P12 [PTB4]<name=KBI0_P12_PIN_SEL>
//   <i> Shows which pin KBI0_P12 is mapped to
//     <0=> Disabled
//     <1=> PTB4<selection=PTB4_SIG_SEL,KBI0_P12>
//     <0=> Default
#define KBI0_P12_PIN_SEL     0
#if (KBI0_P12_PIN_SEL == 1)
#define KBI0_P12_GPIO        USBDM::GpioB<4>
#define KBI0_P12_FN          1
#endif

// Pin Mapping for KBI0_P13 signal
//   <o> KBI0_P13 [PTB5]<name=KBI0_P13_PIN_SEL>
//   <i> Shows which pin KBI0_P13 is mapped to
//     <0=> Disabled
//     <1=> PTB5<selection=PTB5_SIG_SEL,KBI0_P13>
//     <0=> Default
#define KBI0_P13_PIN_SEL     0
#if (KBI0_P13_PIN_SEL == 1)
#define KBI0_P13_GPIO        USBDM::GpioB<5>
#define KBI0_P13_FN          1
#endif

// Pin Mapping for KBI0_P14 signal
//   <o> KBI0_P14 [PTB6]<name=KBI0_P14_PIN_SEL>
//   <i> Shows which pin KBI0_P14 is mapped to
//     <0=> Disabled
//     <1=> PTB6<selection=PTB6_SIG_SEL,KBI0_P14>
//     <0=> Default
#define KBI0_P14_PIN_SEL     0
#if (KBI0_P14_PIN_SEL == 1)
#define KBI0_P14_GPIO        USBDM::GpioB<6>
#define KBI0_P14_FN          1
#endif

// Pin Mapping for KBI0_P15 signal
//   <o> KBI0_P15 [PTB7]<name=KBI0_P15_PIN_SEL>
//   <i> Shows which pin KBI0_P15 is mapped to
//     <0=> Disabled
//     <1=> PTB7<selection=PTB7_SIG_SEL,KBI0_P15>
//     <0=> Default
#define KBI0_P15_PIN_SEL     0
#if (KBI0_P15_PIN_SEL == 1)
#define KBI0_P15_GPIO        USBDM::GpioB<7>
#define KBI0_P15_FN          1
#endif

// Pin Mapping for KBI0_P16 signal
//   <o> KBI0_P16 [PTC0]<name=KBI0_P16_PIN_SEL>
//   <i> Shows which pin KBI0_P16 is mapped to
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,KBI0_P16>
//     <0=> Default
#define KBI0_P16_PIN_SEL     0
#if (KBI0_P16_PIN_SEL == 1)
#define KBI0_P16_GPIO        USBDM::GpioC<0>
#define KBI0_P16_FN          1
#endif

// Pin Mapping for KBI0_P17 signal
//   <o> KBI0_P17 [PTC1]<name=KBI0_P17_PIN_SEL>
//   <i> Shows which pin KBI0_P17 is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,KBI0_P17>
//     <0=> Default
#define KBI0_P17_PIN_SEL     0
#if (KBI0_P17_PIN_SEL == 1)
#define KBI0_P17_GPIO        USBDM::GpioC<1>
#define KBI0_P17_FN          1
#endif

// Pin Mapping for KBI0_P18 signal
//   <o> KBI0_P18 [PTC2]<name=KBI0_P18_PIN_SEL>
//   <i> Shows which pin KBI0_P18 is mapped to
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,KBI0_P18>
//     <0=> Default
#define KBI0_P18_PIN_SEL     0
#if (KBI0_P18_PIN_SEL == 1)
#define KBI0_P18_GPIO        USBDM::GpioC<2>
#define KBI0_P18_FN          1
#endif

// Pin Mapping for KBI0_P19 signal
//   <o> KBI0_P19 [PTC3]<name=KBI0_P19_PIN_SEL>
//   <i> Shows which pin KBI0_P19 is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,KBI0_P19>
//     <0=> Default
#define KBI0_P19_PIN_SEL     0
#if (KBI0_P19_PIN_SEL == 1)
#define KBI0_P19_GPIO        USBDM::GpioC<3>
#define KBI0_P19_FN          1
#endif

// Pin Mapping for KBI0_P20 signal
//   <o> KBI0_P20 [PTC4]<name=KBI0_P20_PIN_SEL>
//   <i> Shows which pin KBI0_P20 is mapped to
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,KBI0_P20>
//     <0=> Default
#define KBI0_P20_PIN_SEL     0
#if (KBI0_P20_PIN_SEL == 1)
#define KBI0_P20_GPIO        USBDM::GpioC<4>
#define KBI0_P20_FN          1
#endif

// Pin Mapping for KBI0_P21 signal
//   <o> KBI0_P21 [PTC5]<name=KBI0_P21_PIN_SEL>
//   <i> Shows which pin KBI0_P21 is mapped to
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,KBI0_P21>
//     <0=> Default
#define KBI0_P21_PIN_SEL     0
#if (KBI0_P21_PIN_SEL == 1)
#define KBI0_P21_GPIO        USBDM::GpioC<5>
#define KBI0_P21_FN          1
#endif

// Pin Mapping for KBI0_P22 signal
//   <o> KBI0_P22 [PTC6]<name=KBI0_P22_PIN_SEL>
//   <i> Shows which pin KBI0_P22 is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,KBI0_P22>
//     <0=> Default
#define KBI0_P22_PIN_SEL     0
#if (KBI0_P22_PIN_SEL == 1)
#define KBI0_P22_GPIO        USBDM::GpioC<6>
#define KBI0_P22_FN          1
#endif

// Pin Mapping for KBI0_P23 signal
//   <o> KBI0_P23 [PTC7]<name=KBI0_P23_PIN_SEL>
//   <i> Shows which pin KBI0_P23 is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,KBI0_P23>
//     <0=> Default
#define KBI0_P23_PIN_SEL     0
#if (KBI0_P23_PIN_SEL == 1)
#define KBI0_P23_GPIO        USBDM::GpioC<7>
#define KBI0_P23_FN          1
#endif

// Pin Mapping for KBI0_P24 signal
//   <o> KBI0_P24 [PTD0]<name=KBI0_P24_PIN_SEL>
//   <i> Shows which pin KBI0_P24 is mapped to
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,KBI0_P24>
//     <0=> Default
#define KBI0_P24_PIN_SEL     0
#if (KBI0_P24_PIN_SEL == 1)
#define KBI0_P24_GPIO        USBDM::GpioD<0>
#define KBI0_P24_FN          1
#endif

// Pin Mapping for KBI0_P25 signal
//   <o> KBI0_P25 [PTD1]<name=KBI0_P25_PIN_SEL>
//   <i> Shows which pin KBI0_P25 is mapped to
//     <0=> Disabled
//     <1=> PTD1<selection=PTD1_SIG_SEL,KBI0_P25>
//     <0=> Default
#define KBI0_P25_PIN_SEL     0
#if (KBI0_P25_PIN_SEL == 1)
#define KBI0_P25_GPIO        USBDM::GpioD<1>
#define KBI0_P25_FN          1
#endif

// Pin Mapping for KBI0_P26 signal
//   <o> KBI0_P26 [PTD2]<name=KBI0_P26_PIN_SEL>
//   <i> Shows which pin KBI0_P26 is mapped to
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,KBI0_P26>
//     <0=> Default
#define KBI0_P26_PIN_SEL     0
#if (KBI0_P26_PIN_SEL == 1)
#define KBI0_P26_GPIO        USBDM::GpioD<2>
#define KBI0_P26_FN          1
#endif

// Pin Mapping for KBI0_P27 signal
//   <o> KBI0_P27 [PTD3]<name=KBI0_P27_PIN_SEL>
//   <i> Shows which pin KBI0_P27 is mapped to
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,KBI0_P27>
//     <0=> Default
#define KBI0_P27_PIN_SEL     0
#if (KBI0_P27_PIN_SEL == 1)
#define KBI0_P27_GPIO        USBDM::GpioD<3>
#define KBI0_P27_FN          1
#endif

// Pin Mapping for KBI0_P28 signal
//   <o> KBI0_P28 [PTD4]<name=KBI0_P28_PIN_SEL>
//   <i> Shows which pin KBI0_P28 is mapped to
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,KBI0_P28>
//     <0=> Default
#define KBI0_P28_PIN_SEL     0
#if (KBI0_P28_PIN_SEL == 1)
#define KBI0_P28_GPIO        USBDM::GpioD<4>
#define KBI0_P28_FN          1
#endif

// Pin Mapping for KBI0_P29 signal
//   <o> KBI0_P29 [PTD5]<name=KBI0_P29_PIN_SEL>
//   <i> Shows which pin KBI0_P29 is mapped to
//     <0=> Disabled
//     <1=> PTD5<selection=PTD5_SIG_SEL,KBI0_P29>
//     <0=> Default
#define KBI0_P29_PIN_SEL     0
#if (KBI0_P29_PIN_SEL == 1)
#define KBI0_P29_GPIO        USBDM::GpioD<5>
#define KBI0_P29_FN          1
#endif

// Pin Mapping for KBI0_P30 signal
//   <o> KBI0_P30 [PTD6]<name=KBI0_P30_PIN_SEL>
//   <i> Shows which pin KBI0_P30 is mapped to
//     <0=> Disabled
//     <1=> PTD6<selection=PTD6_SIG_SEL,KBI0_P30>
//     <0=> Default
#define KBI0_P30_PIN_SEL     0
#if (KBI0_P30_PIN_SEL == 1)
#define KBI0_P30_GPIO        USBDM::GpioD<6>
#define KBI0_P30_FN          1
#endif

// Pin Mapping for KBI0_P31 signal
//   <o> KBI0_P31 [PTD7]<name=KBI0_P31_PIN_SEL>
//   <i> Shows which pin KBI0_P31 is mapped to
//     <0=> Disabled
//     <1=> PTD7<selection=PTD7_SIG_SEL,KBI0_P31>
//     <0=> Default
#define KBI0_P31_PIN_SEL     0
#if (KBI0_P31_PIN_SEL == 1)
#define KBI0_P31_GPIO        USBDM::GpioD<7>
#define KBI0_P31_FN          1
#endif

// Pin Mapping for KBI1_P0 signal
//   <o> KBI1_P0 [PTE0]<name=KBI1_P0_PIN_SEL>
//   <i> Shows which pin KBI1_P0 is mapped to
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,KBI1_P0>
//     <0=> Default
#define KBI1_P0_PIN_SEL      0
#if (KBI1_P0_PIN_SEL == 1)
#define KBI1_P0_GPIO         USBDM::GpioE<0>
#define KBI1_P0_FN           1
#endif

// Pin Mapping for KBI1_P1 signal
//   <o> KBI1_P1 [PTE1]<name=KBI1_P1_PIN_SEL>
//   <i> Shows which pin KBI1_P1 is mapped to
//     <0=> Disabled
//     <1=> PTE1<selection=PTE1_SIG_SEL,KBI1_P1>
//     <0=> Default
#define KBI1_P1_PIN_SEL      0
#if (KBI1_P1_PIN_SEL == 1)
#define KBI1_P1_GPIO         USBDM::GpioE<1>
#define KBI1_P1_FN           1
#endif

// Pin Mapping for KBI1_P2 signal
//   <o> KBI1_P2 [PTE2]<name=KBI1_P2_PIN_SEL>
//   <i> Shows which pin KBI1_P2 is mapped to
//     <0=> Disabled
//     <1=> PTE2<selection=PTE2_SIG_SEL,KBI1_P2>
//     <0=> Default
#define KBI1_P2_PIN_SEL      0
#if (KBI1_P2_PIN_SEL == 1)
#define KBI1_P2_GPIO         USBDM::GpioE<2>
#define KBI1_P2_FN           1
#endif

// Pin Mapping for KBI1_P3 signal
//   <o> KBI1_P3 [PTE3]<name=KBI1_P3_PIN_SEL>
//   <i> Shows which pin KBI1_P3 is mapped to
//     <0=> Disabled
//     <1=> PTE3<selection=PTE3_SIG_SEL,KBI1_P3>
//     <0=> Default
#define KBI1_P3_PIN_SEL      0
#if (KBI1_P3_PIN_SEL == 1)
#define KBI1_P3_GPIO         USBDM::GpioE<3>
#define KBI1_P3_FN           1
#endif

// Pin Mapping for KBI1_P4 signal
//   <o> KBI1_P4 [PTE4]<name=KBI1_P4_PIN_SEL>
//   <i> Shows which pin KBI1_P4 is mapped to
//     <0=> Disabled
//     <1=> PTE4<selection=PTE4_SIG_SEL,KBI1_P4>
//     <0=> Default
#define KBI1_P4_PIN_SEL      0
#if (KBI1_P4_PIN_SEL == 1)
#define KBI1_P4_GPIO         USBDM::GpioE<4>
#define KBI1_P4_FN           1
#endif

// Pin Mapping for KBI1_P5 signal
//   <o> KBI1_P5 [PTE5]<name=KBI1_P5_PIN_SEL>
//   <i> Shows which pin KBI1_P5 is mapped to
//     <0=> Disabled
//     <1=> PTE5<selection=PTE5_SIG_SEL,KBI1_P5>
//     <0=> Default
#define KBI1_P5_PIN_SEL      0
#if (KBI1_P5_PIN_SEL == 1)
#define KBI1_P5_GPIO         USBDM::GpioE<5>
#define KBI1_P5_FN           1
#endif

// Pin Mapping for KBI1_P6 signal
//   <o> KBI1_P6 [PTE6]<name=KBI1_P6_PIN_SEL>
//   <i> Shows which pin KBI1_P6 is mapped to
//     <0=> Disabled
//     <1=> PTE6<selection=PTE6_SIG_SEL,KBI1_P6>
//     <0=> Default
#define KBI1_P6_PIN_SEL      0
#if (KBI1_P6_PIN_SEL == 1)
#define KBI1_P6_GPIO         USBDM::GpioE<6>
#define KBI1_P6_FN           1
#endif

// Pin Mapping for KBI1_P7 signal
//   <o> KBI1_P7 [PTE7]<name=KBI1_P7_PIN_SEL>
//   <i> Shows which pin KBI1_P7 is mapped to
//     <0=> Disabled
//     <1=> PTE7<selection=PTE7_SIG_SEL,KBI1_P7>
//     <0=> Default
#define KBI1_P7_PIN_SEL      0
#if (KBI1_P7_PIN_SEL == 1)
#define KBI1_P7_GPIO         USBDM::GpioE<7>
#define KBI1_P7_FN           1
#endif

// Pin Mapping for KBI1_P8 signal
//   <o> KBI1_P8 [PTF0]<name=KBI1_P8_PIN_SEL>
//   <i> Shows which pin KBI1_P8 is mapped to
//     <0=> Disabled
//     <1=> PTF0<selection=PTF0_SIG_SEL,KBI1_P8>
//     <0=> Default
#define KBI1_P8_PIN_SEL      0
#if (KBI1_P8_PIN_SEL == 1)
#define KBI1_P8_GPIO         USBDM::GpioF<0>
#define KBI1_P8_FN           1
#endif

// Pin Mapping for KBI1_P9 signal
//   <o> KBI1_P9 [PTF1]<name=KBI1_P9_PIN_SEL>
//   <i> Shows which pin KBI1_P9 is mapped to
//     <0=> Disabled
//     <1=> PTF1<selection=PTF1_SIG_SEL,KBI1_P9>
//     <0=> Default
#define KBI1_P9_PIN_SEL      0
#if (KBI1_P9_PIN_SEL == 1)
#define KBI1_P9_GPIO         USBDM::GpioF<1>
#define KBI1_P9_FN           1
#endif

// Pin Mapping for KBI1_P10 signal
//   <o> KBI1_P10 [PTF2]<name=KBI1_P10_PIN_SEL>
//   <i> Shows which pin KBI1_P10 is mapped to
//     <0=> Disabled
//     <1=> PTF2<selection=PTF2_SIG_SEL,KBI1_P10>
//     <0=> Default
#define KBI1_P10_PIN_SEL     0
#if (KBI1_P10_PIN_SEL == 1)
#define KBI1_P10_GPIO        USBDM::GpioF<2>
#define KBI1_P10_FN          1
#endif

// Pin Mapping for KBI1_P11 signal
//   <o> KBI1_P11 [PTF3]<name=KBI1_P11_PIN_SEL>
//   <i> Shows which pin KBI1_P11 is mapped to
//     <0=> Disabled
//     <1=> PTF3<selection=PTF3_SIG_SEL,KBI1_P11>
//     <0=> Default
#define KBI1_P11_PIN_SEL     0
#if (KBI1_P11_PIN_SEL == 1)
#define KBI1_P11_GPIO        USBDM::GpioF<3>
#define KBI1_P11_FN          1
#endif

// Pin Mapping for KBI1_P12 signal
//   <o> KBI1_P12 [PTF4]<name=KBI1_P12_PIN_SEL>
//   <i> Shows which pin KBI1_P12 is mapped to
//     <0=> Disabled
//     <1=> PTF4<selection=PTF4_SIG_SEL,KBI1_P12>
//     <0=> Default
#define KBI1_P12_PIN_SEL     0
#if (KBI1_P12_PIN_SEL == 1)
#define KBI1_P12_GPIO        USBDM::GpioF<4>
#define KBI1_P12_FN          1
#endif

// Pin Mapping for KBI1_P13 signal
//   <o> KBI1_P13 [PTF5]<name=KBI1_P13_PIN_SEL>
//   <i> Shows which pin KBI1_P13 is mapped to
//     <0=> Disabled
//     <1=> PTF5<selection=PTF5_SIG_SEL,KBI1_P13>
//     <0=> Default
#define KBI1_P13_PIN_SEL     0
#if (KBI1_P13_PIN_SEL == 1)
#define KBI1_P13_GPIO        USBDM::GpioF<5>
#define KBI1_P13_FN          1
#endif

// Pin Mapping for KBI1_P14 signal
//   <o> KBI1_P14 [PTF6]<name=KBI1_P14_PIN_SEL>
//   <i> Shows which pin KBI1_P14 is mapped to
//     <0=> Disabled
//     <1=> PTF6<selection=PTF6_SIG_SEL,KBI1_P14>
//     <0=> Default
#define KBI1_P14_PIN_SEL     0
#if (KBI1_P14_PIN_SEL == 1)
#define KBI1_P14_GPIO        USBDM::GpioF<6>
#define KBI1_P14_FN          1
#endif

// Pin Mapping for KBI1_P15 signal
//   <o> KBI1_P15 [PTF7]<name=KBI1_P15_PIN_SEL>
//   <i> Shows which pin KBI1_P15 is mapped to
//     <0=> Disabled
//     <1=> PTF7<selection=PTF7_SIG_SEL,KBI1_P15>
//     <0=> Default
#define KBI1_P15_PIN_SEL     0
#if (KBI1_P15_PIN_SEL == 1)
#define KBI1_P15_GPIO        USBDM::GpioF<7>
#define KBI1_P15_FN          1
#endif

// Pin Mapping for KBI1_P16 signal
//   <o> KBI1_P16 [PTG0]<name=KBI1_P16_PIN_SEL>
//   <i> Shows which pin KBI1_P16 is mapped to
//     <0=> Disabled
//     <1=> PTG0<selection=PTG0_SIG_SEL,KBI1_P16>
//     <0=> Default
#define KBI1_P16_PIN_SEL     0
#if (KBI1_P16_PIN_SEL == 1)
#define KBI1_P16_GPIO        USBDM::GpioG<0>
#define KBI1_P16_FN          1
#endif

// Pin Mapping for KBI1_P17 signal
//   <o> KBI1_P17 [PTG1]<name=KBI1_P17_PIN_SEL>
//   <i> Shows which pin KBI1_P17 is mapped to
//     <0=> Disabled
//     <1=> PTG1<selection=PTG1_SIG_SEL,KBI1_P17>
//     <0=> Default
#define KBI1_P17_PIN_SEL     0
#if (KBI1_P17_PIN_SEL == 1)
#define KBI1_P17_GPIO        USBDM::GpioG<1>
#define KBI1_P17_FN          1
#endif

// Pin Mapping for KBI1_P18 signal
//   <o> KBI1_P18 [PTG2]<name=KBI1_P18_PIN_SEL>
//   <i> Shows which pin KBI1_P18 is mapped to
//     <0=> Disabled
//     <1=> PTG2<selection=PTG2_SIG_SEL,KBI1_P18>
//     <0=> Default
#define KBI1_P18_PIN_SEL     0
#if (KBI1_P18_PIN_SEL == 1)
#define KBI1_P18_GPIO        USBDM::GpioG<2>
#define KBI1_P18_FN          1
#endif

// Pin Mapping for KBI1_P19 signal
//   <o> KBI1_P19 [PTG3]<name=KBI1_P19_PIN_SEL>
//   <i> Shows which pin KBI1_P19 is mapped to
//     <0=> Disabled
//     <1=> PTG3<selection=PTG3_SIG_SEL,KBI1_P19>
//     <0=> Default
#define KBI1_P19_PIN_SEL     0
#if (KBI1_P19_PIN_SEL == 1)
#define KBI1_P19_GPIO        USBDM::GpioG<3>
#define KBI1_P19_FN          1
#endif

// Pin Mapping for KBI1_P20 signal
//   <o> KBI1_P20 [PTG4]<name=KBI1_P20_PIN_SEL>
//   <i> Shows which pin KBI1_P20 is mapped to
//     <0=> Disabled
//     <1=> PTG4<selection=PTG4_SIG_SEL,KBI1_P20>
//     <0=> Default
#define KBI1_P20_PIN_SEL     0
#if (KBI1_P20_PIN_SEL == 1)
#define KBI1_P20_GPIO        USBDM::GpioG<4>
#define KBI1_P20_FN          1
#endif

// Pin Mapping for KBI1_P21 signal
//   <o> KBI1_P21 [PTG5]<name=KBI1_P21_PIN_SEL>
//   <i> Shows which pin KBI1_P21 is mapped to
//     <0=> Disabled
//     <1=> PTG5 (Alias:LED_RED)<selection=PTG5_SIG_SEL,KBI1_P21>
//     <0=> Default
#define KBI1_P21_PIN_SEL     0
#if (KBI1_P21_PIN_SEL == 1)
#define KBI1_P21_GPIO        USBDM::GpioG<5>
#define KBI1_P21_FN          1
#endif

// Pin Mapping for KBI1_P22 signal
//   <o> KBI1_P22 [PTG6]<name=KBI1_P22_PIN_SEL>
//   <i> Shows which pin KBI1_P22 is mapped to
//     <0=> Disabled
//     <1=> PTG6 (Alias:LED_GREEN)<selection=PTG6_SIG_SEL,KBI1_P22>
//     <0=> Default
#define KBI1_P22_PIN_SEL     0
#if (KBI1_P22_PIN_SEL == 1)
#define KBI1_P22_GPIO        USBDM::GpioG<6>
#define KBI1_P22_FN          1
#endif

// Pin Mapping for KBI1_P23 signal
//   <o> KBI1_P23 [PTG7]<name=KBI1_P23_PIN_SEL>
//   <i> Shows which pin KBI1_P23 is mapped to
//     <0=> Disabled
//     <1=> PTG7 (Alias:LED_BLUE)<selection=PTG7_SIG_SEL,KBI1_P23>
//     <0=> Default
#define KBI1_P23_PIN_SEL     0
#if (KBI1_P23_PIN_SEL == 1)
#define KBI1_P23_GPIO        USBDM::GpioG<7>
#define KBI1_P23_FN          1
#endif

// Pin Mapping for KBI1_P24 signal
//   <o> KBI1_P24 [PTH0]<name=KBI1_P24_PIN_SEL>
//   <i> Shows which pin KBI1_P24 is mapped to
//     <0=> Disabled
//     <1=> PTH0<selection=PTH0_SIG_SEL,KBI1_P24>
//     <0=> Default
#define KBI1_P24_PIN_SEL     0
#if (KBI1_P24_PIN_SEL == 1)
#define KBI1_P24_GPIO        USBDM::GpioH<0>
#define KBI1_P24_FN          1
#endif

// Pin Mapping for KBI1_P25 signal
//   <o> KBI1_P25 [PTH1]<name=KBI1_P25_PIN_SEL>
//   <i> Shows which pin KBI1_P25 is mapped to
//     <0=> Disabled
//     <1=> PTH1<selection=PTH1_SIG_SEL,KBI1_P25>
//     <0=> Default
#define KBI1_P25_PIN_SEL     0
#if (KBI1_P25_PIN_SEL == 1)
#define KBI1_P25_GPIO        USBDM::GpioH<1>
#define KBI1_P25_FN          1
#endif

// Pin Mapping for KBI1_P26 signal
//   <o> KBI1_P26 [PTH2]<name=KBI1_P26_PIN_SEL>
//   <i> Shows which pin KBI1_P26 is mapped to
//     <0=> Disabled
//     <1=> PTH2<selection=PTH2_SIG_SEL,KBI1_P26>
//     <0=> Default
#define KBI1_P26_PIN_SEL     0
#if (KBI1_P26_PIN_SEL == 1)
#define KBI1_P26_GPIO        USBDM::GpioH<2>
#define KBI1_P26_FN          1
#endif

// Pin Mapping for KBI1_P27 signal
//   <o> KBI1_P27 [PTH3]<name=KBI1_P27_PIN_SEL>
//   <i> Shows which pin KBI1_P27 is mapped to
//     <0=> Disabled
//     <1=> PTH3<selection=PTH3_SIG_SEL,KBI1_P27>
//     <0=> Default
#define KBI1_P27_PIN_SEL     0
#if (KBI1_P27_PIN_SEL == 1)
#define KBI1_P27_GPIO        USBDM::GpioH<3>
#define KBI1_P27_FN          1
#endif

// Pin Mapping for KBI1_P28 signal
//   <o> KBI1_P28 [PTH4]<name=KBI1_P28_PIN_SEL>
//   <i> Shows which pin KBI1_P28 is mapped to
//     <0=> Disabled
//     <1=> PTH4<selection=PTH4_SIG_SEL,KBI1_P28>
//     <0=> Default
#define KBI1_P28_PIN_SEL     0
#if (KBI1_P28_PIN_SEL == 1)
#define KBI1_P28_GPIO        USBDM::GpioH<4>
#define KBI1_P28_FN          1
#endif

// Pin Mapping for KBI1_P29 signal
//   <o> KBI1_P29 [PTH5]<name=KBI1_P29_PIN_SEL>
//   <i> Shows which pin KBI1_P29 is mapped to
//     <0=> Disabled
//     <1=> PTH5<selection=PTH5_SIG_SEL,KBI1_P29>
//     <0=> Default
#define KBI1_P29_PIN_SEL     0
#if (KBI1_P29_PIN_SEL == 1)
#define KBI1_P29_GPIO        USBDM::GpioH<5>
#define KBI1_P29_FN          1
#endif

// Pin Mapping for KBI1_P30 signal
//   <o> KBI1_P30 [PTH6]<name=KBI1_P30_PIN_SEL>
//   <i> Shows which pin KBI1_P30 is mapped to
//     <0=> Disabled
//     <1=> PTH6<selection=PTH6_SIG_SEL,KBI1_P30>
//     <0=> Default
#define KBI1_P30_PIN_SEL     0
#if (KBI1_P30_PIN_SEL == 1)
#define KBI1_P30_GPIO        USBDM::GpioH<6>
#define KBI1_P30_FN          1
#endif

// Pin Mapping for KBI1_P31 signal
//   <o> KBI1_P31 [PTH7]<name=KBI1_P31_PIN_SEL>
//   <i> Shows which pin KBI1_P31 is mapped to
//     <0=> Disabled
//     <1=> PTH7<selection=PTH7_SIG_SEL,KBI1_P31>
//     <0=> Default
#define KBI1_P31_PIN_SEL     0
#if (KBI1_P31_PIN_SEL == 1)
#define KBI1_P31_GPIO        USBDM::GpioH<7>
#define KBI1_P31_FN          1
#endif

// Pin Mapping for PWT_IN0 signal
//   <o> PWT_IN0 [PTD5, PTE2]<name=PWT_IN0_PIN_SEL>
//   <i> Shows which pin PWT_IN0 is mapped to
//     <0=> Disabled
//     <1=> PTD5<selection=PTD5_SIG_SEL,PWT_IN0>
//     <2=> PTE2<selection=PTE2_SIG_SEL,PWT_IN0>
//     <0=> Default
#define PWT_IN0_PIN_SEL      0
#if (PWT_IN0_PIN_SEL == 1)
#define PWT_IN0_GPIO         USBDM::GpioD<5>
#define PWT_IN0_FN           2
#elif (PWT_IN0_PIN_SEL == 2)
#define PWT_IN0_GPIO         USBDM::GpioE<2>
#define PWT_IN0_FN           3
#endif

// Pin Mapping for PWT_IN1 signal
//   <o> PWT_IN1 [PTH7, PTB0]<name=PWT_IN1_PIN_SEL>
//   <i> Shows which pin PWT_IN1 is mapped to
//     <0=> Disabled
//     <1=> PTH7<selection=PTH7_SIG_SEL,PWT_IN1>
//     <2=> PTB0<selection=PTB0_SIG_SEL,PWT_IN1>
//     <0=> Default
#define PWT_IN1_PIN_SEL      0
#if (PWT_IN1_PIN_SEL == 1)
#define PWT_IN1_GPIO         USBDM::GpioH<7>
#define PWT_IN1_FN           2
#elif (PWT_IN1_PIN_SEL == 2)
#define PWT_IN1_GPIO         USBDM::GpioB<0>
#define PWT_IN1_FN           3
#endif

// </h>

// <h> Analogue Comparator (ACMP0)

// Pin Mapping for ACMP0_IN0 signal
//   <o> ACMP0_IN0 [PTA0]<name=ACMP0_IN0_PIN_SEL>
//   <i> Shows which pin ACMP0_IN0 is mapped to
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,ACMP0_IN0>
//     <0=> Default
#define ACMP0_IN0_PIN_SEL    0
#if (ACMP0_IN0_PIN_SEL == 1)
#define ACMP0_IN0_GPIO       USBDM::GpioA<0>
#define ACMP0_IN0_FN         4
#endif

// Pin Mapping for ACMP0_IN1 signal
//   <o> ACMP0_IN1 [PTA1]<name=ACMP0_IN1_PIN_SEL>
//   <i> Shows which pin ACMP0_IN1 is mapped to
//     <0=> Disabled
//     <1=> PTA1<selection=PTA1_SIG_SEL,ACMP0_IN1>
//     <0=> Default
#define ACMP0_IN1_PIN_SEL    0
#if (ACMP0_IN1_PIN_SEL == 1)
#define ACMP0_IN1_GPIO       USBDM::GpioA<1>
#define ACMP0_IN1_FN         4
#endif

// Pin Mapping for ACMP0_IN2 signal
//   <o> ACMP0_IN2 [PTC4]<name=ACMP0_IN2_PIN_SEL>
//   <i> Shows which pin ACMP0_IN2 is mapped to
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,ACMP0_IN2>
//     <0=> Default
#define ACMP0_IN2_PIN_SEL    0
#if (ACMP0_IN2_PIN_SEL == 1)
#define ACMP0_IN2_GPIO       USBDM::GpioC<4>
#define ACMP0_IN2_FN         4
#endif

// Pin Mapping for ACMP0_OUT signal
//   <o> ACMP0_OUT [PTA4]<name=ACMP0_OUT_PIN_SEL>
//   <i> Shows which pin ACMP0_OUT is mapped to
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,ACMP0_OUT>
//     <0=> Default
#define ACMP0_OUT_PIN_SEL    0
#if (ACMP0_OUT_PIN_SEL == 1)
#define ACMP0_OUT_GPIO       USBDM::GpioA<4>
#define ACMP0_OUT_FN         3
#endif

// </h>

// <h> Analogue Comparator (ACMP1)

// Pin Mapping for ACMP1_IN0 signal
//   <o> ACMP1_IN0 [PTA6]<name=ACMP1_IN0_PIN_SEL>
//   <i> Shows which pin ACMP1_IN0 is mapped to
//     <0=> Disabled
//     <1=> PTA6<selection=PTA6_SIG_SEL,ACMP1_IN0>
//     <0=> Default
#define ACMP1_IN0_PIN_SEL    0
#if (ACMP1_IN0_PIN_SEL == 1)
#define ACMP1_IN0_GPIO       USBDM::GpioA<6>
#define ACMP1_IN0_FN         3
#endif

// Pin Mapping for ACMP1_IN1 signal
//   <o> ACMP1_IN1 [PTA7]<name=ACMP1_IN1_PIN_SEL>
//   <i> Shows which pin ACMP1_IN1 is mapped to
//     <0=> Disabled
//     <1=> PTA7<selection=PTA7_SIG_SEL,ACMP1_IN1>
//     <0=> Default
#define ACMP1_IN1_PIN_SEL    0
#if (ACMP1_IN1_PIN_SEL == 1)
#define ACMP1_IN1_GPIO       USBDM::GpioA<7>
#define ACMP1_IN1_FN         3
#endif

// Pin Mapping for ACMP1_IN2 signal
//   <o> ACMP1_IN2 [PTB4]<name=ACMP1_IN2_PIN_SEL>
//   <i> Shows which pin ACMP1_IN2 is mapped to
//     <0=> Disabled
//     <1=> PTB4<selection=PTB4_SIG_SEL,ACMP1_IN2>
//     <0=> Default
#define ACMP1_IN2_PIN_SEL    0
#if (ACMP1_IN2_PIN_SEL == 1)
#define ACMP1_IN2_GPIO       USBDM::GpioB<4>
#define ACMP1_IN2_FN         4
#endif

// Pin Mapping for ACMP1_OUT signal
//   <o> ACMP1_OUT [PTB5]<name=ACMP1_OUT_PIN_SEL>
//   <i> Shows which pin ACMP1_OUT is mapped to
//     <0=> Disabled
//     <1=> PTB5<selection=PTB5_SIG_SEL,ACMP1_OUT>
//     <0=> Default
#define ACMP1_OUT_PIN_SEL    0
#if (ACMP1_OUT_PIN_SEL == 1)
#define ACMP1_OUT_GPIO       USBDM::GpioB<5>
#define ACMP1_OUT_FN         4
#endif

// </h>

// <h> Analogue to Digital (ADC0)

// Pin Mapping for ADC0_SE0 signal
//   <o> ADC0_SE0 [PTA0]<name=ADC0_SE0_PIN_SEL>
//   <i> Shows which pin ADC0_SE0 is mapped to
//     <0=> Disabled
//     <1=> PTA0 (reset default)<selection=PTA0_SIG_SEL,ADC0_SE0 (reset default)>
//     <2=> PTA0<selection=PTA0_SIG_SEL,ADC0_SE0>
//     <1=> Default
#define ADC0_SE0_PIN_SEL     1
#if (ADC0_SE0_PIN_SEL == 2)
#define ADC0_SE0_GPIO        USBDM::GpioA<0>
#define ADC0_SE0_FN          5
#endif

// Pin Mapping for ADC0_SE1 signal
//   <o> ADC0_SE1 [PTA1]<name=ADC0_SE1_PIN_SEL>
//   <i> Shows which pin ADC0_SE1 is mapped to
//     <0=> Disabled
//     <1=> PTA1 (reset default)<selection=PTA1_SIG_SEL,ADC0_SE1 (reset default)>
//     <2=> PTA1<selection=PTA1_SIG_SEL,ADC0_SE1>
//     <1=> Default
#define ADC0_SE1_PIN_SEL     1
#if (ADC0_SE1_PIN_SEL == 2)
#define ADC0_SE1_GPIO        USBDM::GpioA<1>
#define ADC0_SE1_FN          5
#endif

// Pin Mapping for ADC0_SE2 signal
//   <o> ADC0_SE2 [PTA6]<name=ADC0_SE2_PIN_SEL>
//   <i> Shows which pin ADC0_SE2 is mapped to
//     <0=> Disabled
//     <1=> PTA6 (reset default)<selection=PTA6_SIG_SEL,ADC0_SE2 (reset default)>
//     <2=> PTA6<selection=PTA6_SIG_SEL,ADC0_SE2>
//     <1=> Default
#define ADC0_SE2_PIN_SEL     1
#if (ADC0_SE2_PIN_SEL == 2)
#define ADC0_SE2_GPIO        USBDM::GpioA<6>
#define ADC0_SE2_FN          4
#endif

// Pin Mapping for ADC0_SE3 signal
//   <o> ADC0_SE3 [PTA7]<name=ADC0_SE3_PIN_SEL>
//   <i> Shows which pin ADC0_SE3 is mapped to
//     <0=> Disabled
//     <1=> PTA7 (reset default)<selection=PTA7_SIG_SEL,ADC0_SE3 (reset default)>
//     <2=> PTA7<selection=PTA7_SIG_SEL,ADC0_SE3>
//     <1=> Default
#define ADC0_SE3_PIN_SEL     1
#if (ADC0_SE3_PIN_SEL == 2)
#define ADC0_SE3_GPIO        USBDM::GpioA<7>
#define ADC0_SE3_FN          4
#endif

// Pin Mapping for ADC0_SE4 signal
//   <o> ADC0_SE4 [PTB0]<name=ADC0_SE4_PIN_SEL>
//   <i> Shows which pin ADC0_SE4 is mapped to
//     <0=> Disabled
//     <1=> PTB0 (reset default)<selection=PTB0_SIG_SEL,ADC0_SE4 (reset default)>
//     <2=> PTB0<selection=PTB0_SIG_SEL,ADC0_SE4>
//     <1=> Default
#define ADC0_SE4_PIN_SEL     1
#if (ADC0_SE4_PIN_SEL == 2)
#define ADC0_SE4_GPIO        USBDM::GpioB<0>
#define ADC0_SE4_FN          4
#endif

// Pin Mapping for ADC0_SE5 signal
//   <o> ADC0_SE5 [PTB1]<name=ADC0_SE5_PIN_SEL>
//   <i> Shows which pin ADC0_SE5 is mapped to
//     <0=> Disabled
//     <1=> PTB1 (reset default)<selection=PTB1_SIG_SEL,ADC0_SE5 (reset default)>
//     <2=> PTB1<selection=PTB1_SIG_SEL,ADC0_SE5>
//     <1=> Default
#define ADC0_SE5_PIN_SEL     1
#if (ADC0_SE5_PIN_SEL == 2)
#define ADC0_SE5_GPIO        USBDM::GpioB<1>
#define ADC0_SE5_FN          4
#endif

// Pin Mapping for ADC0_SE6 signal
//   <o> ADC0_SE6 [PTB2]<name=ADC0_SE6_PIN_SEL>
//   <i> Shows which pin ADC0_SE6 is mapped to
//     <0=> Disabled
//     <1=> PTB2 (reset default)<selection=PTB2_SIG_SEL,ADC0_SE6 (reset default)>
//     <2=> PTB2<selection=PTB2_SIG_SEL,ADC0_SE6>
//     <1=> Default
#define ADC0_SE6_PIN_SEL     1
#if (ADC0_SE6_PIN_SEL == 2)
#define ADC0_SE6_GPIO        USBDM::GpioB<2>
#define ADC0_SE6_FN          4
#endif

// Pin Mapping for ADC0_SE7 signal
//   <o> ADC0_SE7 [PTB3]<name=ADC0_SE7_PIN_SEL>
//   <i> Shows which pin ADC0_SE7 is mapped to
//     <0=> Disabled
//     <1=> PTB3 (reset default)<selection=PTB3_SIG_SEL,ADC0_SE7 (reset default)>
//     <2=> PTB3<selection=PTB3_SIG_SEL,ADC0_SE7>
//     <1=> Default
#define ADC0_SE7_PIN_SEL     1
#if (ADC0_SE7_PIN_SEL == 2)
#define ADC0_SE7_GPIO        USBDM::GpioB<3>
#define ADC0_SE7_FN          4
#endif

// Pin Mapping for ADC0_SE8 signal
//   <o> ADC0_SE8 [PTC0]<name=ADC0_SE8_PIN_SEL>
//   <i> Shows which pin ADC0_SE8 is mapped to
//     <0=> Disabled
//     <1=> PTC0 (reset default)<selection=PTC0_SIG_SEL,ADC0_SE8 (reset default)>
//     <2=> PTC0<selection=PTC0_SIG_SEL,ADC0_SE8>
//     <1=> Default
#define ADC0_SE8_PIN_SEL     1
#if (ADC0_SE8_PIN_SEL == 2)
#define ADC0_SE8_GPIO        USBDM::GpioC<0>
#define ADC0_SE8_FN          4
#endif

// Pin Mapping for ADC0_SE9 signal
//   <o> ADC0_SE9 [PTC1]<name=ADC0_SE9_PIN_SEL>
//   <i> Shows which pin ADC0_SE9 is mapped to
//     <0=> Disabled
//     <1=> PTC1 (reset default)<selection=PTC1_SIG_SEL,ADC0_SE9 (reset default)>
//     <2=> PTC1<selection=PTC1_SIG_SEL,ADC0_SE9>
//     <1=> Default
#define ADC0_SE9_PIN_SEL     1
#if (ADC0_SE9_PIN_SEL == 2)
#define ADC0_SE9_GPIO        USBDM::GpioC<1>
#define ADC0_SE9_FN          4
#endif

// Pin Mapping for ADC0_SE10 signal
//   <o> ADC0_SE10 [PTC2]<name=ADC0_SE10_PIN_SEL>
//   <i> Shows which pin ADC0_SE10 is mapped to
//     <0=> Disabled
//     <1=> PTC2 (reset default)<selection=PTC2_SIG_SEL,ADC0_SE10 (reset default)>
//     <2=> PTC2<selection=PTC2_SIG_SEL,ADC0_SE10>
//     <1=> Default
#define ADC0_SE10_PIN_SEL    1
#if (ADC0_SE10_PIN_SEL == 2)
#define ADC0_SE10_GPIO       USBDM::GpioC<2>
#define ADC0_SE10_FN         4
#endif

// Pin Mapping for ADC0_SE11 signal
//   <o> ADC0_SE11 [PTC3]<name=ADC0_SE11_PIN_SEL>
//   <i> Shows which pin ADC0_SE11 is mapped to
//     <0=> Disabled
//     <1=> PTC3 (reset default)<selection=PTC3_SIG_SEL,ADC0_SE11 (reset default)>
//     <2=> PTC3<selection=PTC3_SIG_SEL,ADC0_SE11>
//     <1=> Default
#define ADC0_SE11_PIN_SEL    1
#if (ADC0_SE11_PIN_SEL == 2)
#define ADC0_SE11_GPIO       USBDM::GpioC<3>
#define ADC0_SE11_FN         4
#endif

// Pin Mapping for ADC0_SE12 signal
//   <o> ADC0_SE12 [PTF4]<name=ADC0_SE12_PIN_SEL>
//   <i> Shows which pin ADC0_SE12 is mapped to
//     <0=> Disabled
//     <1=> PTF4 (reset default)<selection=PTF4_SIG_SEL,ADC0_SE12 (reset default)>
//     <2=> PTF4<selection=PTF4_SIG_SEL,ADC0_SE12>
//     <1=> Default
#define ADC0_SE12_PIN_SEL    1
#if (ADC0_SE12_PIN_SEL == 2)
#define ADC0_SE12_GPIO       USBDM::GpioF<4>
#define ADC0_SE12_FN         4
#endif

// Pin Mapping for ADC0_SE13 signal
//   <o> ADC0_SE13 [PTF5]<name=ADC0_SE13_PIN_SEL>
//   <i> Shows which pin ADC0_SE13 is mapped to
//     <0=> Disabled
//     <1=> PTF5 (reset default)<selection=PTF5_SIG_SEL,ADC0_SE13 (reset default)>
//     <2=> PTF5<selection=PTF5_SIG_SEL,ADC0_SE13>
//     <1=> Default
#define ADC0_SE13_PIN_SEL    1
#if (ADC0_SE13_PIN_SEL == 2)
#define ADC0_SE13_GPIO       USBDM::GpioF<5>
#define ADC0_SE13_FN         4
#endif

// Pin Mapping for ADC0_SE14 signal
//   <o> ADC0_SE14 [PTF6]<name=ADC0_SE14_PIN_SEL>
//   <i> Shows which pin ADC0_SE14 is mapped to
//     <0=> Disabled
//     <1=> PTF6 (reset default)<selection=PTF6_SIG_SEL,ADC0_SE14 (reset default)>
//     <2=> PTF6<selection=PTF6_SIG_SEL,ADC0_SE14>
//     <1=> Default
#define ADC0_SE14_PIN_SEL    1
#if (ADC0_SE14_PIN_SEL == 2)
#define ADC0_SE14_GPIO       USBDM::GpioF<6>
#define ADC0_SE14_FN         4
#endif

// Pin Mapping for ADC0_SE15 signal
//   <o> ADC0_SE15 [PTF7]<name=ADC0_SE15_PIN_SEL>
//   <i> Shows which pin ADC0_SE15 is mapped to
//     <0=> Disabled
//     <1=> PTF7 (reset default)<selection=PTF7_SIG_SEL,ADC0_SE15 (reset default)>
//     <2=> PTF7<selection=PTF7_SIG_SEL,ADC0_SE15>
//     <1=> Default
#define ADC0_SE15_PIN_SEL    1
#if (ADC0_SE15_PIN_SEL == 2)
#define ADC0_SE15_GPIO       USBDM::GpioF<7>
#define ADC0_SE15_FN         4
#endif

// </h>

// <h> CAN Bus (CAN0)

// Pin Mapping for CAN0_RX signal
//   <o> CAN0_RX [PTC6, PTH2]<name=CAN0_RX_PIN_SEL>
//   <i> Shows which pin CAN0_RX is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,CAN0_RX>
//     <2=> PTH2<selection=PTH2_SIG_SEL,CAN0_RX>
//     <0=> Default
#define CAN0_RX_PIN_SEL      0
#if (CAN0_RX_PIN_SEL == 1)
#define CAN0_RX_GPIO         USBDM::GpioC<6>
#define CAN0_RX_FN           5
#elif (CAN0_RX_PIN_SEL == 2)
#define CAN0_RX_GPIO         USBDM::GpioH<2>
#define CAN0_RX_FN           5
#endif

// Pin Mapping for CAN0_TX signal
//   <o> CAN0_TX [PTC7, PTE7]<name=CAN0_TX_PIN_SEL>
//   <i> Shows which pin CAN0_TX is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,CAN0_TX>
//     <2=> PTE7<selection=PTE7_SIG_SEL,CAN0_TX>
//     <0=> Default
#define CAN0_TX_PIN_SEL      0
#if (CAN0_TX_PIN_SEL == 1)
#define CAN0_TX_GPIO         USBDM::GpioC<7>
#define CAN0_TX_FN           5
#elif (CAN0_TX_PIN_SEL == 2)
#define CAN0_TX_GPIO         USBDM::GpioE<7>
#define CAN0_TX_FN           5
#endif

// </h>

// <h> Clock and Timing

// Pin Mapping for EXTAL signal
//   <o> EXTAL [PTB7]<name=EXTAL_PIN_SEL>
//   <i> Shows which pin EXTAL is mapped to
//     <0=> Disabled
//     <1=> PTB7 (reset default)<selection=PTB7_SIG_SEL,EXTAL (reset default)>
//     <2=> PTB7<selection=PTB7_SIG_SEL,EXTAL>
//     <1=> Default
#define EXTAL_PIN_SEL        1
#if (EXTAL_PIN_SEL == 2)
#define EXTAL_GPIO           USBDM::GpioB<7>
#define EXTAL_FN             6
#endif

// Pin Mapping for RTC_CLKOUT signal
//   <o> RTC_CLKOUT [PTC4, PTC5]<name=RTC_CLKOUT_PIN_SEL>
//   <i> Shows which pin RTC_CLKOUT is mapped to
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,RTC_CLKOUT>
//     <2=> PTC5<selection=PTC5_SIG_SEL,RTC_CLKOUT>
//     <0=> Default
#define RTC_CLKOUT_PIN_SEL   0
#if (RTC_CLKOUT_PIN_SEL == 1)
#define RTC_CLKOUT_GPIO      USBDM::GpioC<4>
#define RTC_CLKOUT_FN        2
#elif (RTC_CLKOUT_PIN_SEL == 2)
#define RTC_CLKOUT_GPIO      USBDM::GpioC<5>
#define RTC_CLKOUT_FN        5
#endif

// Pin Mapping for TCLK0 signal
//   <o> TCLK0 [PTA5]<name=TCLK0_PIN_SEL>
//   <i> Shows which pin TCLK0 is mapped to
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,TCLK0>
//     <0=> Default
#define TCLK0_PIN_SEL        0
#if (TCLK0_PIN_SEL == 1)
#define TCLK0_GPIO           USBDM::GpioA<5>
#define TCLK0_FN             3
#endif

// Pin Mapping for TCLK1 signal
//   <o> TCLK1 [PTE0]<name=TCLK1_PIN_SEL>
//   <i> Shows which pin TCLK1 is mapped to
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,TCLK1>
//     <0=> Default
#define TCLK1_PIN_SEL        0
#if (TCLK1_PIN_SEL == 1)
#define TCLK1_GPIO           USBDM::GpioE<0>
#define TCLK1_FN             3
#endif

// Pin Mapping for TCLK2 signal
//   <o> TCLK2 [PTE7]<name=TCLK2_PIN_SEL>
//   <i> Shows which pin TCLK2 is mapped to
//     <0=> Disabled
//     <1=> PTE7<selection=PTE7_SIG_SEL,TCLK2>
//     <0=> Default
#define TCLK2_PIN_SEL        0
#if (TCLK2_PIN_SEL == 1)
#define TCLK2_GPIO           USBDM::GpioE<7>
#define TCLK2_FN             2
#endif

// Pin Mapping for XTAL signal
//   <o> XTAL [PTB6]<name=XTAL_PIN_SEL>
//   <i> Shows which pin XTAL is mapped to
//     <0=> Disabled
//     <1=> PTB6 (reset default)<selection=PTB6_SIG_SEL,XTAL (reset default)>
//     <2=> PTB6<selection=PTB6_SIG_SEL,XTAL>
//     <1=> Default
#define XTAL_PIN_SEL         1
#if (XTAL_PIN_SEL == 2)
#define XTAL_GPIO            USBDM::GpioB<6>
#define XTAL_FN              6
#endif

// </h>

// <h> FlexTimer (FTM0)

// Pin Mapping for FTM0_CH0 signal
//   <o> FTM0_CH0 [PTA0, PTB2]<name=FTM0_CH0_PIN_SEL>
//   <i> Shows which pin FTM0_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,FTM0_CH0>
//     <2=> PTB2<selection=PTB2_SIG_SEL,FTM0_CH0>
//     <0=> Default
#define FTM0_CH0_PIN_SEL     0
#if (FTM0_CH0_PIN_SEL == 1)
#define FTM0_CH0_GPIO        USBDM::GpioA<0>
#define FTM0_CH0_FN          2
#elif (FTM0_CH0_PIN_SEL == 2)
#define FTM0_CH0_GPIO        USBDM::GpioB<2>
#define FTM0_CH0_FN          3
#endif

// Pin Mapping for FTM0_CH1 signal
//   <o> FTM0_CH1 [PTA1, PTB3]<name=FTM0_CH1_PIN_SEL>
//   <i> Shows which pin FTM0_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTA1<selection=PTA1_SIG_SEL,FTM0_CH1>
//     <2=> PTB3<selection=PTB3_SIG_SEL,FTM0_CH1>
//     <0=> Default
#define FTM0_CH1_PIN_SEL     0
#if (FTM0_CH1_PIN_SEL == 1)
#define FTM0_CH1_GPIO        USBDM::GpioA<1>
#define FTM0_CH1_FN          2
#elif (FTM0_CH1_PIN_SEL == 2)
#define FTM0_CH1_GPIO        USBDM::GpioB<3>
#define FTM0_CH1_FN          3
#endif

// </h>

// <h> FlexTimer (FTM1)

// Pin Mapping for FTM1_CH0 signal
//   <o> FTM1_CH0 [PTC4, PTH2]<name=FTM1_CH0_PIN_SEL>
//   <i> Shows which pin FTM1_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,FTM1_CH0>
//     <2=> PTH2<selection=PTH2_SIG_SEL,FTM1_CH0>
//     <0=> Default
#define FTM1_CH0_PIN_SEL     0
#if (FTM1_CH0_PIN_SEL == 1)
#define FTM1_CH0_GPIO        USBDM::GpioC<4>
#define FTM1_CH0_FN          3
#elif (FTM1_CH0_PIN_SEL == 2)
#define FTM1_CH0_GPIO        USBDM::GpioH<2>
#define FTM1_CH0_FN          4
#endif

// Pin Mapping for FTM1_CH1 signal
//   <o> FTM1_CH1 [PTC5, PTE7]<name=FTM1_CH1_PIN_SEL>
//   <i> Shows which pin FTM1_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,FTM1_CH1>
//     <2=> PTE7<selection=PTE7_SIG_SEL,FTM1_CH1>
//     <0=> Default
#define FTM1_CH1_PIN_SEL     0
#if (FTM1_CH1_PIN_SEL == 1)
#define FTM1_CH1_GPIO        USBDM::GpioC<5>
#define FTM1_CH1_FN          3
#elif (FTM1_CH1_PIN_SEL == 2)
#define FTM1_CH1_GPIO        USBDM::GpioE<7>
#define FTM1_CH1_FN          4
#endif

// </h>

// <h> FlexTimer (FTM2)

// Pin Mapping for FTM2_CH0 signal
//   <o> FTM2_CH0 [PTC0, PTF0, PTH0]<name=FTM2_CH0_PIN_SEL>
//   <i> Shows which pin FTM2_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,FTM2_CH0>
//     <2=> PTF0<selection=PTF0_SIG_SEL,FTM2_CH0>
//     <3=> PTH0<selection=PTH0_SIG_SEL,FTM2_CH0>
//     <0=> Default
#define FTM2_CH0_PIN_SEL     0
#if (FTM2_CH0_PIN_SEL == 1)
#define FTM2_CH0_GPIO        USBDM::GpioC<0>
#define FTM2_CH0_FN          2
#elif (FTM2_CH0_PIN_SEL == 2)
#define FTM2_CH0_GPIO        USBDM::GpioF<0>
#define FTM2_CH0_FN          2
#elif (FTM2_CH0_PIN_SEL == 3)
#define FTM2_CH0_GPIO        USBDM::GpioH<0>
#define FTM2_CH0_FN          2
#endif

// Pin Mapping for FTM2_CH1 signal
//   <o> FTM2_CH1 [PTC1, PTF1, PTH1]<name=FTM2_CH1_PIN_SEL>
//   <i> Shows which pin FTM2_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,FTM2_CH1>
//     <2=> PTF1<selection=PTF1_SIG_SEL,FTM2_CH1>
//     <3=> PTH1<selection=PTH1_SIG_SEL,FTM2_CH1>
//     <0=> Default
#define FTM2_CH1_PIN_SEL     0
#if (FTM2_CH1_PIN_SEL == 1)
#define FTM2_CH1_GPIO        USBDM::GpioC<1>
#define FTM2_CH1_FN          2
#elif (FTM2_CH1_PIN_SEL == 2)
#define FTM2_CH1_GPIO        USBDM::GpioF<1>
#define FTM2_CH1_FN          2
#elif (FTM2_CH1_PIN_SEL == 3)
#define FTM2_CH1_GPIO        USBDM::GpioH<1>
#define FTM2_CH1_FN          2
#endif

// Pin Mapping for FTM2_CH2 signal
//   <o> FTM2_CH2 [PTC2, PTD0, PTG4]<name=FTM2_CH2_PIN_SEL>
//   <i> Shows which pin FTM2_CH2 is mapped to
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,FTM2_CH2>
//     <2=> PTD0<selection=PTD0_SIG_SEL,FTM2_CH2>
//     <3=> PTG4<selection=PTG4_SIG_SEL,FTM2_CH2>
//     <0=> Default
#define FTM2_CH2_PIN_SEL     0
#if (FTM2_CH2_PIN_SEL == 1)
#define FTM2_CH2_GPIO        USBDM::GpioC<2>
#define FTM2_CH2_FN          2
#elif (FTM2_CH2_PIN_SEL == 2)
#define FTM2_CH2_GPIO        USBDM::GpioD<0>
#define FTM2_CH2_FN          2
#elif (FTM2_CH2_PIN_SEL == 3)
#define FTM2_CH2_GPIO        USBDM::GpioG<4>
#define FTM2_CH2_FN          2
#endif

// Pin Mapping for FTM2_CH3 signal
//   <o> FTM2_CH3 [PTC3, PTD1, PTG5]<name=FTM2_CH3_PIN_SEL>
//   <i> Shows which pin FTM2_CH3 is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,FTM2_CH3>
//     <2=> PTD1<selection=PTD1_SIG_SEL,FTM2_CH3>
//     <3=> PTG5 (Alias:LED_RED)<selection=PTG5_SIG_SEL,FTM2_CH3>
//     <0=> Default
#define FTM2_CH3_PIN_SEL     0
#if (FTM2_CH3_PIN_SEL == 1)
#define FTM2_CH3_GPIO        USBDM::GpioC<3>
#define FTM2_CH3_FN          2
#elif (FTM2_CH3_PIN_SEL == 2)
#define FTM2_CH3_GPIO        USBDM::GpioD<1>
#define FTM2_CH3_FN          2
#elif (FTM2_CH3_PIN_SEL == 3)
#define FTM2_CH3_GPIO        USBDM::GpioG<5>
#define FTM2_CH3_FN          2
#endif

// Pin Mapping for FTM2_CH4 signal
//   <o> FTM2_CH4 [PTB4, PTG6]<name=FTM2_CH4_PIN_SEL>
//   <i> Shows which pin FTM2_CH4 is mapped to
//     <0=> Disabled
//     <1=> PTB4<selection=PTB4_SIG_SEL,FTM2_CH4>
//     <2=> PTG6 (Alias:LED_GREEN)<selection=PTG6_SIG_SEL,FTM2_CH4>
//     <0=> Default
#define FTM2_CH4_PIN_SEL     0
#if (FTM2_CH4_PIN_SEL == 1)
#define FTM2_CH4_GPIO        USBDM::GpioB<4>
#define FTM2_CH4_FN          2
#elif (FTM2_CH4_PIN_SEL == 2)
#define FTM2_CH4_GPIO        USBDM::GpioG<6>
#define FTM2_CH4_FN          2
#endif

// Pin Mapping for FTM2_CH5 signal
//   <o> FTM2_CH5 [PTB5, PTG7]<name=FTM2_CH5_PIN_SEL>
//   <i> Shows which pin FTM2_CH5 is mapped to
//     <0=> Disabled
//     <1=> PTB5<selection=PTB5_SIG_SEL,FTM2_CH5>
//     <2=> PTG7 (Alias:LED_BLUE)<selection=PTG7_SIG_SEL,FTM2_CH5>
//     <0=> Default
#define FTM2_CH5_PIN_SEL     0
#if (FTM2_CH5_PIN_SEL == 1)
#define FTM2_CH5_GPIO        USBDM::GpioB<5>
#define FTM2_CH5_FN          2
#elif (FTM2_CH5_PIN_SEL == 2)
#define FTM2_CH5_GPIO        USBDM::GpioG<7>
#define FTM2_CH5_FN          2
#endif

// Pin Mapping for FTM2_FLT1 signal
//   <o> FTM2_FLT1 [PTA6]<name=FTM2_FLT1_PIN_SEL>
//   <i> Shows which pin FTM2_FLT1 is mapped to
//     <0=> Disabled
//     <1=> PTA6<selection=PTA6_SIG_SEL,FTM2_FLT1>
//     <0=> Default
#define FTM2_FLT1_PIN_SEL    0
#if (FTM2_FLT1_PIN_SEL == 1)
#define FTM2_FLT1_GPIO       USBDM::GpioA<6>
#define FTM2_FLT1_FN         2
#endif

// Pin Mapping for FTM2_FLT2 signal
//   <o> FTM2_FLT2 [PTA7]<name=FTM2_FLT2_PIN_SEL>
//   <i> Shows which pin FTM2_FLT2 is mapped to
//     <0=> Disabled
//     <1=> PTA7<selection=PTA7_SIG_SEL,FTM2_FLT2>
//     <0=> Default
#define FTM2_FLT2_PIN_SEL    0
#if (FTM2_FLT2_PIN_SEL == 1)
#define FTM2_FLT2_GPIO       USBDM::GpioA<7>
#define FTM2_FLT2_FN         2
#endif

// </h>

// <h> General Purpose I/O (GPIOA)

// Pin Mapping for GPIOA_0 signal
//   <o> GPIOA_0 [PTA0]<name=GPIOA_0_PIN_SEL>
//   <i> Shows which pin GPIOA_0 is mapped to
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,GPIOA_0>
//     <0=> Default
#define GPIOA_0_PIN_SEL      0
#if (GPIOA_0_PIN_SEL == 1)
#define GPIOA_0_GPIO         USBDM::GpioA<0>
#define GPIOA_0_FN           0
#endif

// Pin Mapping for GPIOA_1 signal
//   <o> GPIOA_1 [PTA1]<name=GPIOA_1_PIN_SEL>
//   <i> Shows which pin GPIOA_1 is mapped to
//     <0=> Disabled
//     <1=> PTA1<selection=PTA1_SIG_SEL,GPIOA_1>
//     <0=> Default
#define GPIOA_1_PIN_SEL      0
#if (GPIOA_1_PIN_SEL == 1)
#define GPIOA_1_GPIO         USBDM::GpioA<1>
#define GPIOA_1_FN           0
#endif

// Pin Mapping for GPIOA_2 signal
//   <o> GPIOA_2 [PTA2]<name=GPIOA_2_PIN_SEL>
//   <i> Shows which pin GPIOA_2 is mapped to
//     <0=> Disabled
//     <1=> PTA2<selection=PTA2_SIG_SEL,GPIOA_2>
//     <0=> Default
#define GPIOA_2_PIN_SEL      0
#if (GPIOA_2_PIN_SEL == 1)
#define GPIOA_2_GPIO         USBDM::GpioA<2>
#define GPIOA_2_FN           0
#endif

// Pin Mapping for GPIOA_3 signal
//   <o> GPIOA_3 [PTA3]<name=GPIOA_3_PIN_SEL>
//   <i> Shows which pin GPIOA_3 is mapped to
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,GPIOA_3>
//     <0=> Default
#define GPIOA_3_PIN_SEL      0
#if (GPIOA_3_PIN_SEL == 1)
#define GPIOA_3_GPIO         USBDM::GpioA<3>
#define GPIOA_3_FN           0
#endif

// Pin Mapping for GPIOA_4 signal
//   <o> GPIOA_4 [PTA4]<name=GPIOA_4_PIN_SEL>
//   <i> Shows which pin GPIOA_4 is mapped to
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,GPIOA_4>
//     <0=> Default
#define GPIOA_4_PIN_SEL      0
#if (GPIOA_4_PIN_SEL == 1)
#define GPIOA_4_GPIO         USBDM::GpioA<4>
#define GPIOA_4_FN           0
#endif

// Pin Mapping for GPIOA_5 signal
//   <o> GPIOA_5 [PTA5]<name=GPIOA_5_PIN_SEL>
//   <i> Shows which pin GPIOA_5 is mapped to
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,GPIOA_5>
//     <0=> Default
#define GPIOA_5_PIN_SEL      0
#if (GPIOA_5_PIN_SEL == 1)
#define GPIOA_5_GPIO         USBDM::GpioA<5>
#define GPIOA_5_FN           0
#endif

// Pin Mapping for GPIOA_6 signal
//   <o> GPIOA_6 [PTA6]<name=GPIOA_6_PIN_SEL>
//   <i> Shows which pin GPIOA_6 is mapped to
//     <0=> Disabled
//     <1=> PTA6<selection=PTA6_SIG_SEL,GPIOA_6>
//     <0=> Default
#define GPIOA_6_PIN_SEL      0
#if (GPIOA_6_PIN_SEL == 1)
#define GPIOA_6_GPIO         USBDM::GpioA<6>
#define GPIOA_6_FN           0
#endif

// Pin Mapping for GPIOA_7 signal
//   <o> GPIOA_7 [PTA7]<name=GPIOA_7_PIN_SEL>
//   <i> Shows which pin GPIOA_7 is mapped to
//     <0=> Disabled
//     <1=> PTA7<selection=PTA7_SIG_SEL,GPIOA_7>
//     <0=> Default
#define GPIOA_7_PIN_SEL      0
#if (GPIOA_7_PIN_SEL == 1)
#define GPIOA_7_GPIO         USBDM::GpioA<7>
#define GPIOA_7_FN           0
#endif

// Pin Mapping for GPIOA_8 signal
//   <o> GPIOA_8 [PTB0]<name=GPIOA_8_PIN_SEL>
//   <i> Shows which pin GPIOA_8 is mapped to
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,GPIOA_8>
//     <0=> Default
#define GPIOA_8_PIN_SEL      0
#if (GPIOA_8_PIN_SEL == 1)
#define GPIOA_8_GPIO         USBDM::GpioB<0>
#define GPIOA_8_FN           0
#endif

// Pin Mapping for GPIOA_9 signal
//   <o> GPIOA_9 [PTB1]<name=GPIOA_9_PIN_SEL>
//   <i> Shows which pin GPIOA_9 is mapped to
//     <0=> Disabled
//     <1=> PTB1<selection=PTB1_SIG_SEL,GPIOA_9>
//     <0=> Default
#define GPIOA_9_PIN_SEL      0
#if (GPIOA_9_PIN_SEL == 1)
#define GPIOA_9_GPIO         USBDM::GpioB<1>
#define GPIOA_9_FN           0
#endif

// Pin Mapping for GPIOA_10 signal
//   <o> GPIOA_10 [PTB2]<name=GPIOA_10_PIN_SEL>
//   <i> Shows which pin GPIOA_10 is mapped to
//     <0=> Disabled
//     <1=> PTB2<selection=PTB2_SIG_SEL,GPIOA_10>
//     <0=> Default
#define GPIOA_10_PIN_SEL     0
#if (GPIOA_10_PIN_SEL == 1)
#define GPIOA_10_GPIO        USBDM::GpioB<2>
#define GPIOA_10_FN          0
#endif

// Pin Mapping for GPIOA_11 signal
//   <o> GPIOA_11 [PTB3]<name=GPIOA_11_PIN_SEL>
//   <i> Shows which pin GPIOA_11 is mapped to
//     <0=> Disabled
//     <1=> PTB3<selection=PTB3_SIG_SEL,GPIOA_11>
//     <0=> Default
#define GPIOA_11_PIN_SEL     0
#if (GPIOA_11_PIN_SEL == 1)
#define GPIOA_11_GPIO        USBDM::GpioB<3>
#define GPIOA_11_FN          0
#endif

// Pin Mapping for GPIOA_12 signal
//   <o> GPIOA_12 [PTB4]<name=GPIOA_12_PIN_SEL>
//   <i> Shows which pin GPIOA_12 is mapped to
//     <0=> Disabled
//     <1=> PTB4<selection=PTB4_SIG_SEL,GPIOA_12>
//     <0=> Default
#define GPIOA_12_PIN_SEL     0
#if (GPIOA_12_PIN_SEL == 1)
#define GPIOA_12_GPIO        USBDM::GpioB<4>
#define GPIOA_12_FN          0
#endif

// Pin Mapping for GPIOA_13 signal
//   <o> GPIOA_13 [PTB5]<name=GPIOA_13_PIN_SEL>
//   <i> Shows which pin GPIOA_13 is mapped to
//     <0=> Disabled
//     <1=> PTB5<selection=PTB5_SIG_SEL,GPIOA_13>
//     <0=> Default
#define GPIOA_13_PIN_SEL     0
#if (GPIOA_13_PIN_SEL == 1)
#define GPIOA_13_GPIO        USBDM::GpioB<5>
#define GPIOA_13_FN          0
#endif

// Pin Mapping for GPIOA_14 signal
//   <o> GPIOA_14 [PTB6]<name=GPIOA_14_PIN_SEL>
//   <i> Shows which pin GPIOA_14 is mapped to
//     <0=> Disabled
//     <1=> PTB6<selection=PTB6_SIG_SEL,GPIOA_14>
//     <0=> Default
#define GPIOA_14_PIN_SEL     0
#if (GPIOA_14_PIN_SEL == 1)
#define GPIOA_14_GPIO        USBDM::GpioB<6>
#define GPIOA_14_FN          0
#endif

// Pin Mapping for GPIOA_15 signal
//   <o> GPIOA_15 [PTB7]<name=GPIOA_15_PIN_SEL>
//   <i> Shows which pin GPIOA_15 is mapped to
//     <0=> Disabled
//     <1=> PTB7<selection=PTB7_SIG_SEL,GPIOA_15>
//     <0=> Default
#define GPIOA_15_PIN_SEL     0
#if (GPIOA_15_PIN_SEL == 1)
#define GPIOA_15_GPIO        USBDM::GpioB<7>
#define GPIOA_15_FN          0
#endif

// Pin Mapping for GPIOA_16 signal
//   <o> GPIOA_16 [PTC0]<name=GPIOA_16_PIN_SEL>
//   <i> Shows which pin GPIOA_16 is mapped to
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,GPIOA_16>
//     <0=> Default
#define GPIOA_16_PIN_SEL     0
#if (GPIOA_16_PIN_SEL == 1)
#define GPIOA_16_GPIO        USBDM::GpioC<0>
#define GPIOA_16_FN          0
#endif

// Pin Mapping for GPIOA_17 signal
//   <o> GPIOA_17 [PTC1]<name=GPIOA_17_PIN_SEL>
//   <i> Shows which pin GPIOA_17 is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,GPIOA_17>
//     <0=> Default
#define GPIOA_17_PIN_SEL     0
#if (GPIOA_17_PIN_SEL == 1)
#define GPIOA_17_GPIO        USBDM::GpioC<1>
#define GPIOA_17_FN          0
#endif

// Pin Mapping for GPIOA_18 signal
//   <o> GPIOA_18 [PTC2]<name=GPIOA_18_PIN_SEL>
//   <i> Shows which pin GPIOA_18 is mapped to
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,GPIOA_18>
//     <0=> Default
#define GPIOA_18_PIN_SEL     0
#if (GPIOA_18_PIN_SEL == 1)
#define GPIOA_18_GPIO        USBDM::GpioC<2>
#define GPIOA_18_FN          0
#endif

// Pin Mapping for GPIOA_19 signal
//   <o> GPIOA_19 [PTC3]<name=GPIOA_19_PIN_SEL>
//   <i> Shows which pin GPIOA_19 is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,GPIOA_19>
//     <0=> Default
#define GPIOA_19_PIN_SEL     0
#if (GPIOA_19_PIN_SEL == 1)
#define GPIOA_19_GPIO        USBDM::GpioC<3>
#define GPIOA_19_FN          0
#endif

// Pin Mapping for GPIOA_20 signal
//   <o> GPIOA_20 [PTC4]<name=GPIOA_20_PIN_SEL>
//   <i> Shows which pin GPIOA_20 is mapped to
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,GPIOA_20>
//     <0=> Default
#define GPIOA_20_PIN_SEL     0
#if (GPIOA_20_PIN_SEL == 1)
#define GPIOA_20_GPIO        USBDM::GpioC<4>
#define GPIOA_20_FN          0
#endif

// Pin Mapping for GPIOA_21 signal
//   <o> GPIOA_21 [PTC5]<name=GPIOA_21_PIN_SEL>
//   <i> Shows which pin GPIOA_21 is mapped to
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,GPIOA_21>
//     <0=> Default
#define GPIOA_21_PIN_SEL     0
#if (GPIOA_21_PIN_SEL == 1)
#define GPIOA_21_GPIO        USBDM::GpioC<5>
#define GPIOA_21_FN          0
#endif

// Pin Mapping for GPIOA_22 signal
//   <o> GPIOA_22 [PTC6]<name=GPIOA_22_PIN_SEL>
//   <i> Shows which pin GPIOA_22 is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,GPIOA_22>
//     <0=> Default
#define GPIOA_22_PIN_SEL     0
#if (GPIOA_22_PIN_SEL == 1)
#define GPIOA_22_GPIO        USBDM::GpioC<6>
#define GPIOA_22_FN          0
#endif

// Pin Mapping for GPIOA_23 signal
//   <o> GPIOA_23 [PTC7]<name=GPIOA_23_PIN_SEL>
//   <i> Shows which pin GPIOA_23 is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,GPIOA_23>
//     <0=> Default
#define GPIOA_23_PIN_SEL     0
#if (GPIOA_23_PIN_SEL == 1)
#define GPIOA_23_GPIO        USBDM::GpioC<7>
#define GPIOA_23_FN          0
#endif

// Pin Mapping for GPIOA_24 signal
//   <o> GPIOA_24 [PTD0]<name=GPIOA_24_PIN_SEL>
//   <i> Shows which pin GPIOA_24 is mapped to
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,GPIOA_24>
//     <0=> Default
#define GPIOA_24_PIN_SEL     0
#if (GPIOA_24_PIN_SEL == 1)
#define GPIOA_24_GPIO        USBDM::GpioD<0>
#define GPIOA_24_FN          0
#endif

// Pin Mapping for GPIOA_25 signal
//   <o> GPIOA_25 [PTD1]<name=GPIOA_25_PIN_SEL>
//   <i> Shows which pin GPIOA_25 is mapped to
//     <0=> Disabled
//     <1=> PTD1<selection=PTD1_SIG_SEL,GPIOA_25>
//     <0=> Default
#define GPIOA_25_PIN_SEL     0
#if (GPIOA_25_PIN_SEL == 1)
#define GPIOA_25_GPIO        USBDM::GpioD<1>
#define GPIOA_25_FN          0
#endif

// Pin Mapping for GPIOA_26 signal
//   <o> GPIOA_26 [PTD2]<name=GPIOA_26_PIN_SEL>
//   <i> Shows which pin GPIOA_26 is mapped to
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,GPIOA_26>
//     <0=> Default
#define GPIOA_26_PIN_SEL     0
#if (GPIOA_26_PIN_SEL == 1)
#define GPIOA_26_GPIO        USBDM::GpioD<2>
#define GPIOA_26_FN          0
#endif

// Pin Mapping for GPIOA_27 signal
//   <o> GPIOA_27 [PTD3]<name=GPIOA_27_PIN_SEL>
//   <i> Shows which pin GPIOA_27 is mapped to
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,GPIOA_27>
//     <0=> Default
#define GPIOA_27_PIN_SEL     0
#if (GPIOA_27_PIN_SEL == 1)
#define GPIOA_27_GPIO        USBDM::GpioD<3>
#define GPIOA_27_FN          0
#endif

// Pin Mapping for GPIOA_28 signal
//   <o> GPIOA_28 [PTD4]<name=GPIOA_28_PIN_SEL>
//   <i> Shows which pin GPIOA_28 is mapped to
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,GPIOA_28>
//     <0=> Default
#define GPIOA_28_PIN_SEL     0
#if (GPIOA_28_PIN_SEL == 1)
#define GPIOA_28_GPIO        USBDM::GpioD<4>
#define GPIOA_28_FN          0
#endif

// Pin Mapping for GPIOA_29 signal
//   <o> GPIOA_29 [PTD5]<name=GPIOA_29_PIN_SEL>
//   <i> Shows which pin GPIOA_29 is mapped to
//     <0=> Disabled
//     <1=> PTD5<selection=PTD5_SIG_SEL,GPIOA_29>
//     <0=> Default
#define GPIOA_29_PIN_SEL     0
#if (GPIOA_29_PIN_SEL == 1)
#define GPIOA_29_GPIO        USBDM::GpioD<5>
#define GPIOA_29_FN          0
#endif

// Pin Mapping for GPIOA_30 signal
//   <o> GPIOA_30 [PTD6]<name=GPIOA_30_PIN_SEL>
//   <i> Shows which pin GPIOA_30 is mapped to
//     <0=> Disabled
//     <1=> PTD6<selection=PTD6_SIG_SEL,GPIOA_30>
//     <0=> Default
#define GPIOA_30_PIN_SEL     0
#if (GPIOA_30_PIN_SEL == 1)
#define GPIOA_30_GPIO        USBDM::GpioD<6>
#define GPIOA_30_FN          0
#endif

// Pin Mapping for GPIOA_31 signal
//   <o> GPIOA_31 [PTD7]<name=GPIOA_31_PIN_SEL>
//   <i> Shows which pin GPIOA_31 is mapped to
//     <0=> Disabled
//     <1=> PTD7<selection=PTD7_SIG_SEL,GPIOA_31>
//     <0=> Default
#define GPIOA_31_PIN_SEL     0
#if (GPIOA_31_PIN_SEL == 1)
#define GPIOA_31_GPIO        USBDM::GpioD<7>
#define GPIOA_31_FN          0
#endif

// </h>

// <h> General Purpose I/O (GPIOB)

// Pin Mapping for GPIOB_0 signal
//   <o> GPIOB_0 [PTE0]<name=GPIOB_0_PIN_SEL>
//   <i> Shows which pin GPIOB_0 is mapped to
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,GPIOB_0>
//     <0=> Default
#define GPIOB_0_PIN_SEL      0
#if (GPIOB_0_PIN_SEL == 1)
#define GPIOB_0_GPIO         USBDM::GpioE<0>
#define GPIOB_0_FN           0
#endif

// Pin Mapping for GPIOB_1 signal
//   <o> GPIOB_1 [PTE1]<name=GPIOB_1_PIN_SEL>
//   <i> Shows which pin GPIOB_1 is mapped to
//     <0=> Disabled
//     <1=> PTE1<selection=PTE1_SIG_SEL,GPIOB_1>
//     <0=> Default
#define GPIOB_1_PIN_SEL      0
#if (GPIOB_1_PIN_SEL == 1)
#define GPIOB_1_GPIO         USBDM::GpioE<1>
#define GPIOB_1_FN           0
#endif

// Pin Mapping for GPIOB_2 signal
//   <o> GPIOB_2 [PTE2]<name=GPIOB_2_PIN_SEL>
//   <i> Shows which pin GPIOB_2 is mapped to
//     <0=> Disabled
//     <1=> PTE2<selection=PTE2_SIG_SEL,GPIOB_2>
//     <0=> Default
#define GPIOB_2_PIN_SEL      0
#if (GPIOB_2_PIN_SEL == 1)
#define GPIOB_2_GPIO         USBDM::GpioE<2>
#define GPIOB_2_FN           0
#endif

// Pin Mapping for GPIOB_3 signal
//   <o> GPIOB_3 [PTE3]<name=GPIOB_3_PIN_SEL>
//   <i> Shows which pin GPIOB_3 is mapped to
//     <0=> Disabled
//     <1=> PTE3<selection=PTE3_SIG_SEL,GPIOB_3>
//     <0=> Default
#define GPIOB_3_PIN_SEL      0
#if (GPIOB_3_PIN_SEL == 1)
#define GPIOB_3_GPIO         USBDM::GpioE<3>
#define GPIOB_3_FN           0
#endif

// Pin Mapping for GPIOB_4 signal
//   <o> GPIOB_4 [PTE4]<name=GPIOB_4_PIN_SEL>
//   <i> Shows which pin GPIOB_4 is mapped to
//     <0=> Disabled
//     <1=> PTE4<selection=PTE4_SIG_SEL,GPIOB_4>
//     <0=> Default
#define GPIOB_4_PIN_SEL      0
#if (GPIOB_4_PIN_SEL == 1)
#define GPIOB_4_GPIO         USBDM::GpioE<4>
#define GPIOB_4_FN           0
#endif

// Pin Mapping for GPIOB_5 signal
//   <o> GPIOB_5 [PTE5]<name=GPIOB_5_PIN_SEL>
//   <i> Shows which pin GPIOB_5 is mapped to
//     <0=> Disabled
//     <1=> PTE5<selection=PTE5_SIG_SEL,GPIOB_5>
//     <0=> Default
#define GPIOB_5_PIN_SEL      0
#if (GPIOB_5_PIN_SEL == 1)
#define GPIOB_5_GPIO         USBDM::GpioE<5>
#define GPIOB_5_FN           0
#endif

// Pin Mapping for GPIOB_6 signal
//   <o> GPIOB_6 [PTE6]<name=GPIOB_6_PIN_SEL>
//   <i> Shows which pin GPIOB_6 is mapped to
//     <0=> Disabled
//     <1=> PTE6<selection=PTE6_SIG_SEL,GPIOB_6>
//     <0=> Default
#define GPIOB_6_PIN_SEL      0
#if (GPIOB_6_PIN_SEL == 1)
#define GPIOB_6_GPIO         USBDM::GpioE<6>
#define GPIOB_6_FN           0
#endif

// Pin Mapping for GPIOB_7 signal
//   <o> GPIOB_7 [PTE7]<name=GPIOB_7_PIN_SEL>
//   <i> Shows which pin GPIOB_7 is mapped to
//     <0=> Disabled
//     <1=> PTE7<selection=PTE7_SIG_SEL,GPIOB_7>
//     <0=> Default
#define GPIOB_7_PIN_SEL      0
#if (GPIOB_7_PIN_SEL == 1)
#define GPIOB_7_GPIO         USBDM::GpioE<7>
#define GPIOB_7_FN           0
#endif

// Pin Mapping for GPIOB_8 signal
//   <o> GPIOB_8 [PTF0]<name=GPIOB_8_PIN_SEL>
//   <i> Shows which pin GPIOB_8 is mapped to
//     <0=> Disabled
//     <1=> PTF0<selection=PTF0_SIG_SEL,GPIOB_8>
//     <0=> Default
#define GPIOB_8_PIN_SEL      0
#if (GPIOB_8_PIN_SEL == 1)
#define GPIOB_8_GPIO         USBDM::GpioF<0>
#define GPIOB_8_FN           0
#endif

// Pin Mapping for GPIOB_9 signal
//   <o> GPIOB_9 [PTF1]<name=GPIOB_9_PIN_SEL>
//   <i> Shows which pin GPIOB_9 is mapped to
//     <0=> Disabled
//     <1=> PTF1<selection=PTF1_SIG_SEL,GPIOB_9>
//     <0=> Default
#define GPIOB_9_PIN_SEL      0
#if (GPIOB_9_PIN_SEL == 1)
#define GPIOB_9_GPIO         USBDM::GpioF<1>
#define GPIOB_9_FN           0
#endif

// Pin Mapping for GPIOB_10 signal
//   <o> GPIOB_10 [PTF2]<name=GPIOB_10_PIN_SEL>
//   <i> Shows which pin GPIOB_10 is mapped to
//     <0=> Disabled
//     <1=> PTF2<selection=PTF2_SIG_SEL,GPIOB_10>
//     <0=> Default
#define GPIOB_10_PIN_SEL     0
#if (GPIOB_10_PIN_SEL == 1)
#define GPIOB_10_GPIO        USBDM::GpioF<2>
#define GPIOB_10_FN          0
#endif

// Pin Mapping for GPIOB_11 signal
//   <o> GPIOB_11 [PTF3]<name=GPIOB_11_PIN_SEL>
//   <i> Shows which pin GPIOB_11 is mapped to
//     <0=> Disabled
//     <1=> PTF3<selection=PTF3_SIG_SEL,GPIOB_11>
//     <0=> Default
#define GPIOB_11_PIN_SEL     0
#if (GPIOB_11_PIN_SEL == 1)
#define GPIOB_11_GPIO        USBDM::GpioF<3>
#define GPIOB_11_FN          0
#endif

// Pin Mapping for GPIOB_12 signal
//   <o> GPIOB_12 [PTF4]<name=GPIOB_12_PIN_SEL>
//   <i> Shows which pin GPIOB_12 is mapped to
//     <0=> Disabled
//     <1=> PTF4<selection=PTF4_SIG_SEL,GPIOB_12>
//     <0=> Default
#define GPIOB_12_PIN_SEL     0
#if (GPIOB_12_PIN_SEL == 1)
#define GPIOB_12_GPIO        USBDM::GpioF<4>
#define GPIOB_12_FN          0
#endif

// Pin Mapping for GPIOB_13 signal
//   <o> GPIOB_13 [PTF5]<name=GPIOB_13_PIN_SEL>
//   <i> Shows which pin GPIOB_13 is mapped to
//     <0=> Disabled
//     <1=> PTF5<selection=PTF5_SIG_SEL,GPIOB_13>
//     <0=> Default
#define GPIOB_13_PIN_SEL     0
#if (GPIOB_13_PIN_SEL == 1)
#define GPIOB_13_GPIO        USBDM::GpioF<5>
#define GPIOB_13_FN          0
#endif

// Pin Mapping for GPIOB_14 signal
//   <o> GPIOB_14 [PTF6]<name=GPIOB_14_PIN_SEL>
//   <i> Shows which pin GPIOB_14 is mapped to
//     <0=> Disabled
//     <1=> PTF6<selection=PTF6_SIG_SEL,GPIOB_14>
//     <0=> Default
#define GPIOB_14_PIN_SEL     0
#if (GPIOB_14_PIN_SEL == 1)
#define GPIOB_14_GPIO        USBDM::GpioF<6>
#define GPIOB_14_FN          0
#endif

// Pin Mapping for GPIOB_15 signal
//   <o> GPIOB_15 [PTF7]<name=GPIOB_15_PIN_SEL>
//   <i> Shows which pin GPIOB_15 is mapped to
//     <0=> Disabled
//     <1=> PTF7<selection=PTF7_SIG_SEL,GPIOB_15>
//     <0=> Default
#define GPIOB_15_PIN_SEL     0
#if (GPIOB_15_PIN_SEL == 1)
#define GPIOB_15_GPIO        USBDM::GpioF<7>
#define GPIOB_15_FN          0
#endif

// Pin Mapping for GPIOB_16 signal
//   <o> GPIOB_16 [PTG0]<name=GPIOB_16_PIN_SEL>
//   <i> Shows which pin GPIOB_16 is mapped to
//     <0=> Disabled
//     <1=> PTG0<selection=PTG0_SIG_SEL,GPIOB_16>
//     <0=> Default
#define GPIOB_16_PIN_SEL     0
#if (GPIOB_16_PIN_SEL == 1)
#define GPIOB_16_GPIO        USBDM::GpioG<0>
#define GPIOB_16_FN          0
#endif

// Pin Mapping for GPIOB_17 signal
//   <o> GPIOB_17 [PTG1]<name=GPIOB_17_PIN_SEL>
//   <i> Shows which pin GPIOB_17 is mapped to
//     <0=> Disabled
//     <1=> PTG1<selection=PTG1_SIG_SEL,GPIOB_17>
//     <0=> Default
#define GPIOB_17_PIN_SEL     0
#if (GPIOB_17_PIN_SEL == 1)
#define GPIOB_17_GPIO        USBDM::GpioG<1>
#define GPIOB_17_FN          0
#endif

// Pin Mapping for GPIOB_18 signal
//   <o> GPIOB_18 [PTG2]<name=GPIOB_18_PIN_SEL>
//   <i> Shows which pin GPIOB_18 is mapped to
//     <0=> Disabled
//     <1=> PTG2<selection=PTG2_SIG_SEL,GPIOB_18>
//     <0=> Default
#define GPIOB_18_PIN_SEL     0
#if (GPIOB_18_PIN_SEL == 1)
#define GPIOB_18_GPIO        USBDM::GpioG<2>
#define GPIOB_18_FN          0
#endif

// Pin Mapping for GPIOB_19 signal
//   <o> GPIOB_19 [PTG3]<name=GPIOB_19_PIN_SEL>
//   <i> Shows which pin GPIOB_19 is mapped to
//     <0=> Disabled
//     <1=> PTG3<selection=PTG3_SIG_SEL,GPIOB_19>
//     <0=> Default
#define GPIOB_19_PIN_SEL     0
#if (GPIOB_19_PIN_SEL == 1)
#define GPIOB_19_GPIO        USBDM::GpioG<3>
#define GPIOB_19_FN          0
#endif

// Pin Mapping for GPIOB_20 signal
//   <o> GPIOB_20 [PTG4]<name=GPIOB_20_PIN_SEL>
//   <i> Shows which pin GPIOB_20 is mapped to
//     <0=> Disabled
//     <1=> PTG4<selection=PTG4_SIG_SEL,GPIOB_20>
//     <0=> Default
#define GPIOB_20_PIN_SEL     0
#if (GPIOB_20_PIN_SEL == 1)
#define GPIOB_20_GPIO        USBDM::GpioG<4>
#define GPIOB_20_FN          0
#endif

// Pin Mapping for GPIOB_21 signal
//   <o> GPIOB_21 [PTG5]<name=GPIOB_21_PIN_SEL>
//   <i> Shows which pin GPIOB_21 is mapped to
//     <0=> Disabled
//     <1=> PTG5 (Alias:LED_RED)<selection=PTG5_SIG_SEL,GPIOB_21>
//     <1=> Default
#define GPIOB_21_PIN_SEL     1
#if (GPIOB_21_PIN_SEL == 1)
#define GPIOB_21_GPIO        USBDM::GpioG<5>
#define GPIOB_21_FN          0
#endif

// Pin Mapping for GPIOB_22 signal
//   <o> GPIOB_22 [PTG6]<name=GPIOB_22_PIN_SEL>
//   <i> Shows which pin GPIOB_22 is mapped to
//     <0=> Disabled
//     <1=> PTG6 (Alias:LED_GREEN)<selection=PTG6_SIG_SEL,GPIOB_22>
//     <1=> Default
#define GPIOB_22_PIN_SEL     1
#if (GPIOB_22_PIN_SEL == 1)
#define GPIOB_22_GPIO        USBDM::GpioG<6>
#define GPIOB_22_FN          0
#endif

// Pin Mapping for GPIOB_23 signal
//   <o> GPIOB_23 [PTG7]<name=GPIOB_23_PIN_SEL>
//   <i> Shows which pin GPIOB_23 is mapped to
//     <0=> Disabled
//     <1=> PTG7 (Alias:LED_BLUE)<selection=PTG7_SIG_SEL,GPIOB_23>
//     <1=> Default
#define GPIOB_23_PIN_SEL     1
#if (GPIOB_23_PIN_SEL == 1)
#define GPIOB_23_GPIO        USBDM::GpioG<7>
#define GPIOB_23_FN          0
#endif

// Pin Mapping for GPIOB_24 signal
//   <o> GPIOB_24 [PTH0]<name=GPIOB_24_PIN_SEL>
//   <i> Shows which pin GPIOB_24 is mapped to
//     <0=> Disabled
//     <1=> PTH0<selection=PTH0_SIG_SEL,GPIOB_24>
//     <0=> Default
#define GPIOB_24_PIN_SEL     0
#if (GPIOB_24_PIN_SEL == 1)
#define GPIOB_24_GPIO        USBDM::GpioH<0>
#define GPIOB_24_FN          0
#endif

// Pin Mapping for GPIOB_25 signal
//   <o> GPIOB_25 [PTH1]<name=GPIOB_25_PIN_SEL>
//   <i> Shows which pin GPIOB_25 is mapped to
//     <0=> Disabled
//     <1=> PTH1<selection=PTH1_SIG_SEL,GPIOB_25>
//     <0=> Default
#define GPIOB_25_PIN_SEL     0
#if (GPIOB_25_PIN_SEL == 1)
#define GPIOB_25_GPIO        USBDM::GpioH<1>
#define GPIOB_25_FN          0
#endif

// Pin Mapping for GPIOB_26 signal
//   <o> GPIOB_26 [PTH2]<name=GPIOB_26_PIN_SEL>
//   <i> Shows which pin GPIOB_26 is mapped to
//     <0=> Disabled
//     <1=> PTH2<selection=PTH2_SIG_SEL,GPIOB_26>
//     <0=> Default
#define GPIOB_26_PIN_SEL     0
#if (GPIOB_26_PIN_SEL == 1)
#define GPIOB_26_GPIO        USBDM::GpioH<2>
#define GPIOB_26_FN          0
#endif

// Pin Mapping for GPIOB_27 signal
//   <o> GPIOB_27 [PTH3]<name=GPIOB_27_PIN_SEL>
//   <i> Shows which pin GPIOB_27 is mapped to
//     <0=> Disabled
//     <1=> PTH3<selection=PTH3_SIG_SEL,GPIOB_27>
//     <0=> Default
#define GPIOB_27_PIN_SEL     0
#if (GPIOB_27_PIN_SEL == 1)
#define GPIOB_27_GPIO        USBDM::GpioH<3>
#define GPIOB_27_FN          0
#endif

// Pin Mapping for GPIOB_28 signal
//   <o> GPIOB_28 [PTH4]<name=GPIOB_28_PIN_SEL>
//   <i> Shows which pin GPIOB_28 is mapped to
//     <0=> Disabled
//     <1=> PTH4<selection=PTH4_SIG_SEL,GPIOB_28>
//     <0=> Default
#define GPIOB_28_PIN_SEL     0
#if (GPIOB_28_PIN_SEL == 1)
#define GPIOB_28_GPIO        USBDM::GpioH<4>
#define GPIOB_28_FN          0
#endif

// Pin Mapping for GPIOB_29 signal
//   <o> GPIOB_29 [PTH5]<name=GPIOB_29_PIN_SEL>
//   <i> Shows which pin GPIOB_29 is mapped to
//     <0=> Disabled
//     <1=> PTH5<selection=PTH5_SIG_SEL,GPIOB_29>
//     <0=> Default
#define GPIOB_29_PIN_SEL     0
#if (GPIOB_29_PIN_SEL == 1)
#define GPIOB_29_GPIO        USBDM::GpioH<5>
#define GPIOB_29_FN          0
#endif

// Pin Mapping for GPIOB_30 signal
//   <o> GPIOB_30 [PTH6]<name=GPIOB_30_PIN_SEL>
//   <i> Shows which pin GPIOB_30 is mapped to
//     <0=> Disabled
//     <1=> PTH6<selection=PTH6_SIG_SEL,GPIOB_30>
//     <0=> Default
#define GPIOB_30_PIN_SEL     0
#if (GPIOB_30_PIN_SEL == 1)
#define GPIOB_30_GPIO        USBDM::GpioH<6>
#define GPIOB_30_FN          0
#endif

// Pin Mapping for GPIOB_31 signal
//   <o> GPIOB_31 [PTH7]<name=GPIOB_31_PIN_SEL>
//   <i> Shows which pin GPIOB_31 is mapped to
//     <0=> Disabled
//     <1=> PTH7<selection=PTH7_SIG_SEL,GPIOB_31>
//     <0=> Default
#define GPIOB_31_PIN_SEL     0
#if (GPIOB_31_PIN_SEL == 1)
#define GPIOB_31_GPIO        USBDM::GpioH<7>
#define GPIOB_31_FN          0
#endif

// </h>

// <h> General Purpose I/O (GPIOC)

// Pin Mapping for GPIOC_0 signal
//   <o> GPIOC_0 [PTI0]<name=GPIOC_0_PIN_SEL>
//   <i> Shows which pin GPIOC_0 is mapped to
//     <0=> Disabled
//     <1=> PTI0<selection=PTI0_SIG_SEL,GPIOC_0>
//     <0=> Default
#define GPIOC_0_PIN_SEL      0
#if (GPIOC_0_PIN_SEL == 1)
#define GPIOC_0_GPIO         USBDM::GpioI<0>
#define GPIOC_0_FN           0
#endif

// Pin Mapping for GPIOC_1 signal
//   <o> GPIOC_1 [PTI1]<name=GPIOC_1_PIN_SEL>
//   <i> Shows which pin GPIOC_1 is mapped to
//     <0=> Disabled
//     <1=> PTI1<selection=PTI1_SIG_SEL,GPIOC_1>
//     <0=> Default
#define GPIOC_1_PIN_SEL      0
#if (GPIOC_1_PIN_SEL == 1)
#define GPIOC_1_GPIO         USBDM::GpioI<1>
#define GPIOC_1_FN           0
#endif

// Pin Mapping for GPIOC_2 signal
//   <o> GPIOC_2 [PTI2]<name=GPIOC_2_PIN_SEL>
//   <i> Shows which pin GPIOC_2 is mapped to
//     <0=> Disabled
//     <1=> PTI2<selection=PTI2_SIG_SEL,GPIOC_2>
//     <0=> Default
#define GPIOC_2_PIN_SEL      0
#if (GPIOC_2_PIN_SEL == 1)
#define GPIOC_2_GPIO         USBDM::GpioI<2>
#define GPIOC_2_FN           0
#endif

// Pin Mapping for GPIOC_3 signal
//   <o> GPIOC_3 [PTI3]<name=GPIOC_3_PIN_SEL>
//   <i> Shows which pin GPIOC_3 is mapped to
//     <0=> Disabled
//     <1=> PTI3<selection=PTI3_SIG_SEL,GPIOC_3>
//     <0=> Default
#define GPIOC_3_PIN_SEL      0
#if (GPIOC_3_PIN_SEL == 1)
#define GPIOC_3_GPIO         USBDM::GpioI<3>
#define GPIOC_3_FN           0
#endif

// Pin Mapping for GPIOC_4 signal
//   <o> GPIOC_4 [PTI4]<name=GPIOC_4_PIN_SEL>
//   <i> Shows which pin GPIOC_4 is mapped to
//     <0=> Disabled
//     <1=> PTI4<selection=PTI4_SIG_SEL,GPIOC_4>
//     <0=> Default
#define GPIOC_4_PIN_SEL      0
#if (GPIOC_4_PIN_SEL == 1)
#define GPIOC_4_GPIO         USBDM::GpioI<4>
#define GPIOC_4_FN           0
#endif

// Pin Mapping for GPIOC_5 signal
//   <o> GPIOC_5 [PTI5]<name=GPIOC_5_PIN_SEL>
//   <i> Shows which pin GPIOC_5 is mapped to
//     <0=> Disabled
//     <1=> PTI5<selection=PTI5_SIG_SEL,GPIOC_5>
//     <0=> Default
#define GPIOC_5_PIN_SEL      0
#if (GPIOC_5_PIN_SEL == 1)
#define GPIOC_5_GPIO         USBDM::GpioI<5>
#define GPIOC_5_FN           0
#endif

// Pin Mapping for GPIOC_6 signal
//   <o> GPIOC_6 [PTI6]<name=GPIOC_6_PIN_SEL>
//   <i> Shows which pin GPIOC_6 is mapped to
//     <0=> Disabled
//     <1=> PTI6<selection=PTI6_SIG_SEL,GPIOC_6>
//     <0=> Default
#define GPIOC_6_PIN_SEL      0
#if (GPIOC_6_PIN_SEL == 1)
#define GPIOC_6_GPIO         USBDM::GpioI<6>
#define GPIOC_6_FN           0
#endif

// </h>

// <h> Inter-Integrated Circuit (I2C0)

// Pin Mapping for I2C0_SCL signal
//   <o> I2C0_SCL [PTB7, PTA3]<name=I2C0_SCL_PIN_SEL>
//   <i> Shows which pin I2C0_SCL is mapped to
//     <0=> Disabled
//     <1=> PTB7<selection=PTB7_SIG_SEL,I2C0_SCL>
//     <2=> PTA3<selection=PTA3_SIG_SEL,I2C0_SCL>
//     <0=> Default
#define I2C0_SCL_PIN_SEL     0
#if (I2C0_SCL_PIN_SEL == 1)
#define I2C0_SCL_GPIO        USBDM::GpioB<7>
#define I2C0_SCL_FN          2
#elif (I2C0_SCL_PIN_SEL == 2)
#define I2C0_SCL_GPIO        USBDM::GpioA<3>
#define I2C0_SCL_FN          3
#endif

// Pin Mapping for I2C0_4WSDAOUT signal
//   <o> I2C0_4WSDAOUT [PTA1]<name=I2C0_4WSDAOUT_PIN_SEL>
//   <i> Shows which pin I2C0_4WSDAOUT is mapped to
//     <0=> Disabled
//     <1=> PTA1<selection=PTA1_SIG_SEL,I2C0_4WSDAOUT>
//     <0=> Default
#define I2C0_4WSDAOUT_PIN_SEL 0
#if (I2C0_4WSDAOUT_PIN_SEL == 1)
#define I2C0_4WSDAOUT_GPIO   USBDM::GpioA<1>
#define I2C0_4WSDAOUT_FN     3
#endif

// Pin Mapping for I2C0_SDA signal
//   <o> I2C0_SDA [PTB6, PTA2]<name=I2C0_SDA_PIN_SEL>
//   <i> Shows which pin I2C0_SDA is mapped to
//     <0=> Disabled
//     <1=> PTB6<selection=PTB6_SIG_SEL,I2C0_SDA>
//     <2=> PTA2<selection=PTA2_SIG_SEL,I2C0_SDA>
//     <0=> Default
#define I2C0_SDA_PIN_SEL     0
#if (I2C0_SDA_PIN_SEL == 1)
#define I2C0_SDA_GPIO        USBDM::GpioB<6>
#define I2C0_SDA_FN          2
#elif (I2C0_SDA_PIN_SEL == 2)
#define I2C0_SDA_GPIO        USBDM::GpioA<2>
#define I2C0_SDA_FN          3
#endif

// Pin Mapping for I2C0_4WSCLOUT signal
//   <o> I2C0_4WSCLOUT [PTA0]<name=I2C0_4WSCLOUT_PIN_SEL>
//   <i> Shows which pin I2C0_4WSCLOUT is mapped to
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,I2C0_4WSCLOUT>
//     <0=> Default
#define I2C0_4WSCLOUT_PIN_SEL 0
#if (I2C0_4WSCLOUT_PIN_SEL == 1)
#define I2C0_4WSCLOUT_GPIO   USBDM::GpioA<0>
#define I2C0_4WSCLOUT_FN     3
#endif

// </h>

// <h> Inter-Integrated Circuit (I2C1)

// Pin Mapping for I2C1_SDA signal
//   <o> I2C1_SDA [PTH3, PTE0]<name=I2C1_SDA_PIN_SEL>
//   <i> Shows which pin I2C1_SDA is mapped to
//     <0=> Disabled
//     <1=> PTH3<selection=PTH3_SIG_SEL,I2C1_SDA>
//     <2=> PTE0<selection=PTE0_SIG_SEL,I2C1_SDA>
//     <0=> Default
#define I2C1_SDA_PIN_SEL     0
#if (I2C1_SDA_PIN_SEL == 1)
#define I2C1_SDA_GPIO        USBDM::GpioH<3>
#define I2C1_SDA_FN          2
#elif (I2C1_SDA_PIN_SEL == 2)
#define I2C1_SDA_GPIO        USBDM::GpioE<0>
#define I2C1_SDA_FN          4
#endif

// Pin Mapping for I2C1_SCL signal
//   <o> I2C1_SCL [PTH4, PTE1]<name=I2C1_SCL_PIN_SEL>
//   <i> Shows which pin I2C1_SCL is mapped to
//     <0=> Disabled
//     <1=> PTH4<selection=PTH4_SIG_SEL,I2C1_SCL>
//     <2=> PTE1<selection=PTE1_SIG_SEL,I2C1_SCL>
//     <0=> Default
#define I2C1_SCL_PIN_SEL     0
#if (I2C1_SCL_PIN_SEL == 1)
#define I2C1_SCL_GPIO        USBDM::GpioH<4>
#define I2C1_SCL_FN          2
#elif (I2C1_SCL_PIN_SEL == 2)
#define I2C1_SCL_GPIO        USBDM::GpioE<1>
#define I2C1_SCL_FN          4
#endif

// </h>

// <h> Debug and Control

// Pin Mapping for NMI_b signal
//   <o> NMI_b [PTB4]<name=NMI_b_PIN_SEL>
//   <i> Shows which pin NMI_b is mapped to
//     <0=> Disabled
//     <1=> PTB4 (reset default)<selection=PTB4_SIG_SEL,NMI_b (reset default)>
//     <2=> PTB4<selection=PTB4_SIG_SEL,NMI_b>
//     <1=> Default
#define NMI_b_PIN_SEL        1
#if (NMI_b_PIN_SEL == 2)
#define NMI_b_GPIO           USBDM::GpioB<4>
#define NMI_b_FN             5
#endif

// Pin Mapping for RESET_b signal
//   <o> RESET_b [PTA5]<name=RESET_b_PIN_SEL>
//   <i> Shows which pin RESET_b is mapped to
//     <0=> Disabled
//     <1=> PTA5 (reset default)<selection=PTA5_SIG_SEL,RESET_b (reset default)>
//     <2=> PTA5<selection=PTA5_SIG_SEL,RESET_b>
//     <1=> Default
#define RESET_b_PIN_SEL      1
#if (RESET_b_PIN_SEL == 2)
#define RESET_b_GPIO         USBDM::GpioA<5>
#define RESET_b_FN           4
#endif

// Pin Mapping for SWD_CLK signal
//   <o> SWD_CLK [PTC4]<name=SWD_CLK_PIN_SEL>
//   <i> Shows which pin SWD_CLK is mapped to
//     <0=> Disabled
//     <1=> PTC4 (reset default)<selection=PTC4_SIG_SEL,SWD_CLK (reset default)>
//     <2=> PTC4<selection=PTC4_SIG_SEL,SWD_CLK>
//     <1=> Default
#define SWD_CLK_PIN_SEL      1
#if (SWD_CLK_PIN_SEL == 2)
#define SWD_CLK_GPIO         USBDM::GpioC<4>
#define SWD_CLK_FN           5
#endif

// Pin Mapping for SWD_DIO signal
//   <o> SWD_DIO [PTA4]<name=SWD_DIO_PIN_SEL>
//   <i> Shows which pin SWD_DIO is mapped to
//     <0=> Disabled
//     <1=> PTA4 (reset default)<selection=PTA4_SIG_SEL,SWD_DIO (reset default)>
//     <2=> PTA4<selection=PTA4_SIG_SEL,SWD_DIO>
//     <1=> Default
#define SWD_DIO_PIN_SEL      1
#if (SWD_DIO_PIN_SEL == 2)
#define SWD_DIO_GPIO         USBDM::GpioA<4>
#define SWD_DIO_FN           4
#endif

// </h>

// <h> Serial Peripheral Interface (SPI0)

// Pin Mapping for SPI0_MISO signal
//   <o> SPI0_MISO [PTE2, PTB4]<name=SPI0_MISO_PIN_SEL>
//   <i> Shows which pin SPI0_MISO is mapped to
//     <0=> Disabled
//     <1=> PTE2<selection=PTE2_SIG_SEL,SPI0_MISO>
//     <2=> PTB4<selection=PTB4_SIG_SEL,SPI0_MISO>
//     <0=> Default
#define SPI0_MISO_PIN_SEL    0
#if (SPI0_MISO_PIN_SEL == 1)
#define SPI0_MISO_GPIO       USBDM::GpioE<2>
#define SPI0_MISO_FN         2
#elif (SPI0_MISO_PIN_SEL == 2)
#define SPI0_MISO_GPIO       USBDM::GpioB<4>
#define SPI0_MISO_FN         3
#endif

// Pin Mapping for SPI0_MOSI signal
//   <o> SPI0_MOSI [PTB3, PTE1]<name=SPI0_MOSI_PIN_SEL>
//   <i> Shows which pin SPI0_MOSI is mapped to
//     <0=> Disabled
//     <1=> PTB3<selection=PTB3_SIG_SEL,SPI0_MOSI>
//     <2=> PTE1<selection=PTE1_SIG_SEL,SPI0_MOSI>
//     <0=> Default
#define SPI0_MOSI_PIN_SEL    0
#if (SPI0_MOSI_PIN_SEL == 1)
#define SPI0_MOSI_GPIO       USBDM::GpioB<3>
#define SPI0_MOSI_FN         2
#elif (SPI0_MOSI_PIN_SEL == 2)
#define SPI0_MOSI_GPIO       USBDM::GpioE<1>
#define SPI0_MOSI_FN         2
#endif

// Pin Mapping for SPI0_PCS signal
//   <o> SPI0_PCS [PTE3, PTB5]<name=SPI0_PCS_PIN_SEL>
//   <i> Shows which pin SPI0_PCS is mapped to
//     <0=> Disabled
//     <1=> PTE3<selection=PTE3_SIG_SEL,SPI0_PCS>
//     <2=> PTB5<selection=PTB5_SIG_SEL,SPI0_PCS>
//     <0=> Default
#define SPI0_PCS_PIN_SEL     0
#if (SPI0_PCS_PIN_SEL == 1)
#define SPI0_PCS_GPIO        USBDM::GpioE<3>
#define SPI0_PCS_FN          2
#elif (SPI0_PCS_PIN_SEL == 2)
#define SPI0_PCS_GPIO        USBDM::GpioB<5>
#define SPI0_PCS_FN          3
#endif

// Pin Mapping for SPI0_SCK signal
//   <o> SPI0_SCK [PTB2, PTE0]<name=SPI0_SCK_PIN_SEL>
//   <i> Shows which pin SPI0_SCK is mapped to
//     <0=> Disabled
//     <1=> PTB2<selection=PTB2_SIG_SEL,SPI0_SCK>
//     <2=> PTE0<selection=PTE0_SIG_SEL,SPI0_SCK>
//     <0=> Default
#define SPI0_SCK_PIN_SEL     0
#if (SPI0_SCK_PIN_SEL == 1)
#define SPI0_SCK_GPIO        USBDM::GpioB<2>
#define SPI0_SCK_FN          2
#elif (SPI0_SCK_PIN_SEL == 2)
#define SPI0_SCK_GPIO        USBDM::GpioE<0>
#define SPI0_SCK_FN          2
#endif

// </h>

// <h> Serial Peripheral Interface (SPI1)

// Pin Mapping for SPI1_MISO signal
//   <o> SPI1_MISO [PTD2, PTG6]<name=SPI1_MISO_PIN_SEL>
//   <i> Shows which pin SPI1_MISO is mapped to
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,SPI1_MISO>
//     <2=> PTG6 (Alias:LED_GREEN)<selection=PTG6_SIG_SEL,SPI1_MISO>
//     <0=> Default
#define SPI1_MISO_PIN_SEL    0
#if (SPI1_MISO_PIN_SEL == 1)
#define SPI1_MISO_GPIO       USBDM::GpioD<2>
#define SPI1_MISO_FN         2
#elif (SPI1_MISO_PIN_SEL == 2)
#define SPI1_MISO_GPIO       USBDM::GpioG<6>
#define SPI1_MISO_FN         3
#endif

// Pin Mapping for SPI1_MOSI signal
//   <o> SPI1_MOSI [PTD1, PTG5]<name=SPI1_MOSI_PIN_SEL>
//   <i> Shows which pin SPI1_MOSI is mapped to
//     <0=> Disabled
//     <1=> PTD1<selection=PTD1_SIG_SEL,SPI1_MOSI>
//     <2=> PTG5 (Alias:LED_RED)<selection=PTG5_SIG_SEL,SPI1_MOSI>
//     <0=> Default
#define SPI1_MOSI_PIN_SEL    0
#if (SPI1_MOSI_PIN_SEL == 1)
#define SPI1_MOSI_GPIO       USBDM::GpioD<1>
#define SPI1_MOSI_FN         3
#elif (SPI1_MOSI_PIN_SEL == 2)
#define SPI1_MOSI_GPIO       USBDM::GpioG<5>
#define SPI1_MOSI_FN         3
#endif

// Pin Mapping for SPI1_PCS signal
//   <o> SPI1_PCS [PTD3, PTG7]<name=SPI1_PCS_PIN_SEL>
//   <i> Shows which pin SPI1_PCS is mapped to
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,SPI1_PCS>
//     <2=> PTG7 (Alias:LED_BLUE)<selection=PTG7_SIG_SEL,SPI1_PCS>
//     <0=> Default
#define SPI1_PCS_PIN_SEL     0
#if (SPI1_PCS_PIN_SEL == 1)
#define SPI1_PCS_GPIO        USBDM::GpioD<3>
#define SPI1_PCS_FN          2
#elif (SPI1_PCS_PIN_SEL == 2)
#define SPI1_PCS_GPIO        USBDM::GpioG<7>
#define SPI1_PCS_FN          3
#endif

// Pin Mapping for SPI1_SCK signal
//   <o> SPI1_SCK [PTD0, PTG4]<name=SPI1_SCK_PIN_SEL>
//   <i> Shows which pin SPI1_SCK is mapped to
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,SPI1_SCK>
//     <2=> PTG4<selection=PTG4_SIG_SEL,SPI1_SCK>
//     <0=> Default
#define SPI1_SCK_PIN_SEL     0
#if (SPI1_SCK_PIN_SEL == 1)
#define SPI1_SCK_GPIO        USBDM::GpioD<0>
#define SPI1_SCK_FN          3
#elif (SPI1_SCK_PIN_SEL == 2)
#define SPI1_SCK_GPIO        USBDM::GpioG<4>
#define SPI1_SCK_FN          3
#endif

// </h>

// <h> Universal Asynchronous Rx/Tx (UART0)

// Pin Mapping for UART0_RX signal
//   <o> UART0_RX [PTA2, PTB0]<name=UART0_RX_PIN_SEL>
//   <i> Shows which pin UART0_RX is mapped to
//     <0=> Disabled
//     <1=> PTA2<selection=PTA2_SIG_SEL,UART0_RX>
//     <2=> PTB0<selection=PTB0_SIG_SEL,UART0_RX>
//     <0=> Default
#define UART0_RX_PIN_SEL     0
#if (UART0_RX_PIN_SEL == 1)
#define UART0_RX_GPIO        USBDM::GpioA<2>
#define UART0_RX_FN          2
#elif (UART0_RX_PIN_SEL == 2)
#define UART0_RX_GPIO        USBDM::GpioB<0>
#define UART0_RX_FN          2
#endif

// Pin Mapping for UART0_TX signal
//   <o> UART0_TX [PTA3, PTB1]<name=UART0_TX_PIN_SEL>
//   <i> Shows which pin UART0_TX is mapped to
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,UART0_TX>
//     <2=> PTB1<selection=PTB1_SIG_SEL,UART0_TX>
//     <0=> Default
#define UART0_TX_PIN_SEL     0
#if (UART0_TX_PIN_SEL == 1)
#define UART0_TX_GPIO        USBDM::GpioA<3>
#define UART0_TX_FN          2
#elif (UART0_TX_PIN_SEL == 2)
#define UART0_TX_GPIO        USBDM::GpioB<1>
#define UART0_TX_FN          2
#endif

// </h>

// <h> Universal Asynchronous Rx/Tx (UART1)

// Pin Mapping for UART1_RX signal
//   <o> UART1_RX [PTC6, PTF2]<name=UART1_RX_PIN_SEL>
//   <i> Shows which pin UART1_RX is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,UART1_RX>
//     <2=> PTF2<selection=PTF2_SIG_SEL,UART1_RX>
//     <0=> Default
#define UART1_RX_PIN_SEL     0
#if (UART1_RX_PIN_SEL == 1)
#define UART1_RX_GPIO        USBDM::GpioC<6>
#define UART1_RX_FN          2
#elif (UART1_RX_PIN_SEL == 2)
#define UART1_RX_GPIO        USBDM::GpioF<2>
#define UART1_RX_FN          2
#endif

// Pin Mapping for UART1_TX signal
//   <o> UART1_TX [PTC7, PTF3]<name=UART1_TX_PIN_SEL>
//   <i> Shows which pin UART1_TX is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,UART1_TX>
//     <2=> PTF3<selection=PTF3_SIG_SEL,UART1_TX>
//     <0=> Default
#define UART1_TX_PIN_SEL     0
#if (UART1_TX_PIN_SEL == 1)
#define UART1_TX_GPIO        USBDM::GpioC<7>
#define UART1_TX_FN          2
#elif (UART1_TX_PIN_SEL == 2)
#define UART1_TX_GPIO        USBDM::GpioF<3>
#define UART1_TX_FN          2
#endif

// </h>

// <h> Universal Asynchronous Rx/Tx (UART2)

// Pin Mapping for UART2_RX signal
//   <o> UART2_RX [PTD6, PTI0]<name=UART2_RX_PIN_SEL>
//   <i> Shows which pin UART2_RX is mapped to
//     <0=> Disabled
//     <1=> PTD6<selection=PTD6_SIG_SEL,UART2_RX>
//     <2=> PTI0<selection=PTI0_SIG_SEL,UART2_RX>
//     <0=> Default
#define UART2_RX_PIN_SEL     0
#if (UART2_RX_PIN_SEL == 1)
#define UART2_RX_GPIO        USBDM::GpioD<6>
#define UART2_RX_FN          2
#elif (UART2_RX_PIN_SEL == 2)
#define UART2_RX_GPIO        USBDM::GpioI<0>
#define UART2_RX_FN          3
#endif

// Pin Mapping for UART2_TX signal
//   <o> UART2_TX [PTD7, PTI1]<name=UART2_TX_PIN_SEL>
//   <i> Shows which pin UART2_TX is mapped to
//     <0=> Disabled
//     <1=> PTD7<selection=PTD7_SIG_SEL,UART2_TX>
//     <2=> PTI1<selection=PTI1_SIG_SEL,UART2_TX>
//     <0=> Default
#define UART2_TX_PIN_SEL     0
#if (UART2_TX_PIN_SEL == 1)
#define UART2_TX_GPIO        USBDM::GpioD<7>
#define UART2_TX_FN          2
#elif (UART2_TX_PIN_SEL == 2)
#define UART2_TX_GPIO        USBDM::GpioI<1>
#define UART2_TX_FN          3
#endif

// </h>

// </e>

//-------- <<< end of configuration section >>> -----------------  

/*
 * Common Mux settings for PCR
 */
#define FIXED_ADC_FN             0                    // Fixed ADC Multiplexing value
#define FIXED_GPIO_FN            1                    // Fixed GPIO Multiplexing value
#define FIXED_PORT_CLOCK_REG     SCGC5                // Fixed PORT Clock

/*
 * Peripheral clock macros
 */
#define ACMP0_CLOCK_REG      SCGC
#define ACMP0_CLOCK_MASK     SIM_SCGC_ACMP0_MASK
#define ACMP1_CLOCK_REG      SCGC
#define ACMP1_CLOCK_MASK     SIM_SCGC_ACMP1_MASK
#define ADC0_CLOCK_REG       SCGC
#define ADC0_CLOCK_MASK      SIM_SCGC_ADC0_MASK
#define CRC_CLOCK_REG        SCGC
#define CRC_CLOCK_MASK       SIM_SCGC_CRC_MASK
#define FTM0_CLOCK_REG       SCGC
#define FTM0_CLOCK_MASK      SIM_SCGC_FTM0_MASK
#define FTM1_CLOCK_REG       SCGC
#define FTM1_CLOCK_MASK      SIM_SCGC_FTM1_MASK
#define FTM2_CLOCK_REG       SCGC
#define FTM2_CLOCK_MASK      SIM_SCGC_FTM2_MASK
#define I2C0_CLOCK_REG       SCGC
#define I2C0_CLOCK_MASK      SIM_SCGC_I2C0_MASK
#define I2C1_CLOCK_REG       SCGC
#define I2C1_CLOCK_MASK      SIM_SCGC_I2C1_MASK
#define IRQ_CLOCK_REG        SCGC
#define IRQ_CLOCK_MASK       SIM_SCGC_IRQ_MASK
#define KBI0_CLOCK_REG       SCGC
#define KBI0_CLOCK_MASK      SIM_SCGC_KBI0_MASK
#define KBI1_CLOCK_REG       SCGC
#define KBI1_CLOCK_MASK      SIM_SCGC_KBI1_MASK
#define MSCAN_CLOCK_REG      SCGC
#define MSCAN_CLOCK_MASK     SIM_SCGC_MSCAN_MASK
#define PIT_CLOCK_REG        SCGC
#define PIT_CLOCK_MASK       SIM_SCGC_PIT_MASK
#define PWT_CLOCK_REG        SCGC
#define PWT_CLOCK_MASK       SIM_SCGC_PWT_MASK
#define RTC_CLOCK_REG        SCGC
#define RTC_CLOCK_MASK       SIM_SCGC_RTC_MASK
#define SPI0_CLOCK_REG       SCGC
#define SPI0_CLOCK_MASK      SIM_SCGC_SPI0_MASK
#define SPI1_CLOCK_REG       SCGC
#define SPI1_CLOCK_MASK      SIM_SCGC_SPI1_MASK
#define SWD_CLOCK_REG        SCGC
#define SWD_CLOCK_MASK       SIM_SCGC_SWD_MASK
#define UART0_CLOCK_REG      SCGC
#define UART0_CLOCK_MASK     SIM_SCGC_UART0_MASK
#define UART1_CLOCK_REG      SCGC
#define UART1_CLOCK_MASK     SIM_SCGC_UART1_MASK
#define UART2_CLOCK_REG      SCGC
#define UART2_CLOCK_MASK     SIM_SCGC_UART2_MASK
#define PORT_CLOCK_REG       SCGC5

/*
Clock Information Summary
ACMP0      SCGC         SIM_SCGC_ACMP0_MASK
ACMP1      SCGC         SIM_SCGC_ACMP1_MASK
ADC0       SCGC         SIM_SCGC_ADC0_MASK
CRC        SCGC         SIM_SCGC_CRC_MASK
FTM0       SCGC         SIM_SCGC_FTM0_MASK
FTM1       SCGC         SIM_SCGC_FTM1_MASK
FTM2       SCGC         SIM_SCGC_FTM2_MASK
I2C0       SCGC         SIM_SCGC_I2C0_MASK
I2C1       SCGC         SIM_SCGC_I2C1_MASK
IRQ        SCGC         SIM_SCGC_IRQ_MASK
KBI0       SCGC         SIM_SCGC_KBI0_MASK
KBI1       SCGC         SIM_SCGC_KBI1_MASK
MSCAN      SCGC         SIM_SCGC_MSCAN_MASK
PIT        SCGC         SIM_SCGC_PIT_MASK
PWT        SCGC         SIM_SCGC_PWT_MASK
RTC        SCGC         SIM_SCGC_RTC_MASK
SPI0       SCGC         SIM_SCGC_SPI0_MASK
SPI1       SCGC         SIM_SCGC_SPI1_MASK
SWD        SCGC         SIM_SCGC_SWD_MASK
UART0      SCGC         SIM_SCGC_UART0_MASK
UART1      SCGC         SIM_SCGC_UART1_MASK
UART2      SCGC         SIM_SCGC_UART2_MASK
*/

namespace USBDM {

/*
 * Peripheral Pin Tables
 */
/**
* @addtogroup PeripheralPinTables Peripheral Pin Tables
* @brief Provides information about pins used by a peripheral
* @{
*/
/**
 * Struct for pin information
 */
struct PcrInfo {
   uint32_t clockMask;   //!< Clock mask for PORT
   uint32_t pcrAddress;  //!< PCR[x] register address
   int      muxValue;    //!< PCR mux value to select this function
};
/**
 * @}
 ** PeripheralPinTables
 */

} // End namespace USBDM

#endif /* PIN_MAPPING_H_ */
