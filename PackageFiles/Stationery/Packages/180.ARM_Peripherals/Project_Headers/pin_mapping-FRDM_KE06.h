/**
 * @file      pin_mapping.h (derived from pin_mapping-FRDM_KE06.h)
 * @version   1.2.0
 * @brief     Pin declarations for FRDM_KE06, generated from MKE06Z4.csv
 *            Devices   [MKE06Z64xxx4, MKE06Z128xxx4]
 *            Reference [MKE06P80M48SF0RM]
 */

#ifndef PROJECT_HEADERS_PIN_MAPPING_H_
#define PROJECT_HEADERS_PIN_MAPPING_H_

#include <stddef.h>
#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

//================================
// Validators
// <validate=net.sourceforge.usbdm.annotationEditor.validators.PinMappingValidator>

// <h> Clock settings for FTM0

// FTM0_SC.CLKS ================================
//
//   <o>    FTM0_SC.CLKS Clock source
//   <i>    Selects the clock source for the FTM0 module. [FTM0_SC.CLKS]
//     <0=> Disabled
//     <1=> System clock
//     <2=> Fixed frequency clock
//     <3=> External clock
//     <1=> Default
// FTM0_SC.PS ================================
//
//   <o1>    FTM0_SC.PS Clock prescaler
//   <i>    Selects the prescaler for the FTM0 module. [FTM0_SC.PS]
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

constexpr uint16_t FTM0_SC              = (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0));

} // End namespace

// </h>

// <h> Clock settings for FTM1

// FTM1_SC.CLKS ================================
//
//   <o>    FTM1_SC.CLKS Clock source
//   <i>    Selects the clock source for the FTM1 module. [FTM1_SC.CLKS]
//     <0=> Disabled
//     <1=> System clock
//     <2=> Fixed frequency clock
//     <3=> External clock
//     <1=> Default
// FTM1_SC.PS ================================
//
//   <o1>    FTM1_SC.PS Clock prescaler
//   <i>    Selects the prescaler for the FTM1 module. [FTM1_SC.PS]
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

constexpr uint16_t FTM1_SC              = (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0));

} // End namespace

// </h>

// <h> Clock settings for FTM2

// FTM2_SC.CLKS ================================
//
//   <o>    FTM2_SC.CLKS Clock source
//   <i>    Selects the clock source for the FTM2 module. [FTM2_SC.CLKS]
//     <0=> Disabled
//     <1=> System clock
//     <2=> Fixed frequency clock
//     <3=> External clock
//     <1=> Default
// FTM2_SC.PS ================================
//
//   <o1>    FTM2_SC.PS Clock prescaler
//   <i>    Selects the prescaler for the FTM2 module. [FTM2_SC.PS]
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

constexpr uint16_t FTM2_SC              = (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0));

} // End namespace

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
//   <o>    PTA0<name=PTA0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA0 pin
//   <info> GPIOA_0, KBI0_P0, FTM0_CH0, I2C0_4WSCLOUT, ACMP0_IN0, ADC0_SE0
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
//   <o>    PTA1<name=PTA1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA1 pin
//   <info> GPIOA_1, KBI0_P1, FTM0_CH1, I2C0_4WSDAOUT, ACMP0_IN1, ADC0_SE1
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
//   <o>    PTA2<name=PTA2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA2 pin
//   <info> GPIOA_2, KBI0_P2, UART0_RX, I2C0_SDA
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_2<selection=GPIOA_2_PIN_SEL,PTA2>
//     <1=> KBI0_P2<selection=KBI0_P2_PIN_SEL,PTA2>
//     <2=> UART0_RX<selection=UART0_RX_PIN_SEL,PTA2>
//     <3=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTA2>
//     <-2=> Default
#define PTA2_SIG_SEL         -2

// Signal mapping for PTA3 pin
//   <o>    PTA3<name=PTA3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA3 pin
//   <info> GPIOA_3, KBI0_P3, UART0_TX, I2C0_SCL
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_3<selection=GPIOA_3_PIN_SEL,PTA3>
//     <1=> KBI0_P3<selection=KBI0_P3_PIN_SEL,PTA3>
//     <2=> UART0_TX<selection=UART0_TX_PIN_SEL,PTA3>
//     <3=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTA3>
//     <-2=> Default
#define PTA3_SIG_SEL         -2

// Signal mapping for PTA4 pin
//   <o>    PTA4<name=PTA4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA4 pin
//   <info> GPIOA_4, KBI0_P4, ACMP0_OUT, SWD_DIO
//     <-2=> SWD_DIO (reset default)<selection=SWD_DIO_PIN_SEL,PTA4 (reset default)>
//     <0=> GPIOA_4<selection=GPIOA_4_PIN_SEL,PTA4>
//     <1=> KBI0_P4<selection=KBI0_P4_PIN_SEL,PTA4>
//     <3=> ACMP0_OUT<selection=ACMP0_OUT_PIN_SEL,PTA4>
//     <4=> SWD_DIO<selection=SWD_DIO_PIN_SEL,PTA4>
//     <-2=> Default
#define PTA4_SIG_SEL         -2

// Signal mapping for PTA5 pin
//   <o>    PTA5<name=PTA5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA5 pin
//   <info> GPIOA_5, KBI0_P5, IRQ, TCLK0, RESET_b
//     <-2=> RESET_b (reset default)<selection=RESET_b_PIN_SEL,PTA5 (reset default)>
//     <0=> GPIOA_5<selection=GPIOA_5_PIN_SEL,PTA5>
//     <1=> KBI0_P5<selection=KBI0_P5_PIN_SEL,PTA5>
//     <2=> IRQ<selection=IRQ_PIN_SEL,PTA5>
//     <3=> TCLK0<selection=TCLK0_PIN_SEL,PTA5>
//     <4=> RESET_b<selection=RESET_b_PIN_SEL,PTA5>
//     <-2=> Default
#define PTA5_SIG_SEL         -2

// Signal mapping for PTA6 pin
//   <o>    PTA6<name=PTA6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA6 pin
//   <info> GPIOA_6, KBI0_P6, FTM2_FLT1, ACMP1_IN0, ADC0_SE2
//     <-2=> ADC0_SE2 (reset default)<selection=ADC0_SE2_PIN_SEL,PTA6 (reset default)>
//     <0=> GPIOA_6<selection=GPIOA_6_PIN_SEL,PTA6>
//     <1=> KBI0_P6<selection=KBI0_P6_PIN_SEL,PTA6>
//     <2=> FTM2_FLT1<selection=FTM2_FLT1_PIN_SEL,PTA6>
//     <3=> ACMP1_IN0<selection=ACMP1_IN0_PIN_SEL,PTA6>
//     <4=> ADC0_SE2<selection=ADC0_SE2_PIN_SEL,PTA6>
//     <-2=> Default
#define PTA6_SIG_SEL         -2

// Signal mapping for PTA7 pin
//   <o>    PTA7<name=PTA7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA7 pin
//   <info> GPIOA_7, KBI0_P7, FTM2_FLT2, ACMP1_IN1, ADC0_SE3
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
//   <o>    PTB0<name=PTB0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB0 pin
//   <info> GPIOA_8, KBI0_P8, UART0_RX, PWT_IN1, ADC0_SE4
//     <-2=> ADC0_SE4 (reset default)<selection=ADC0_SE4_PIN_SEL,PTB0 (reset default)>
//     <0=> GPIOA_8<selection=GPIOA_8_PIN_SEL,PTB0>
//     <1=> KBI0_P8<selection=KBI0_P8_PIN_SEL,PTB0>
//     <2=> UART0_RX<selection=UART0_RX_PIN_SEL,PTB0>
//     <3=> PWT_IN1<selection=PWT_IN1_PIN_SEL,PTB0>
//     <4=> ADC0_SE4<selection=ADC0_SE4_PIN_SEL,PTB0>
//     <-2=> Default
#define PTB0_SIG_SEL         -2

// Signal mapping for PTB1 pin
//   <o>    PTB1<name=PTB1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB1 pin
//   <info> GPIOA_9, KBI0_P9, UART0_TX, ADC0_SE5
//     <-2=> ADC0_SE5 (reset default)<selection=ADC0_SE5_PIN_SEL,PTB1 (reset default)>
//     <0=> GPIOA_9<selection=GPIOA_9_PIN_SEL,PTB1>
//     <1=> KBI0_P9<selection=KBI0_P9_PIN_SEL,PTB1>
//     <2=> UART0_TX<selection=UART0_TX_PIN_SEL,PTB1>
//     <4=> ADC0_SE5<selection=ADC0_SE5_PIN_SEL,PTB1>
//     <-2=> Default
#define PTB1_SIG_SEL         -2

// Signal mapping for PTB2 pin
//   <o>    PTB2<name=PTB2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB2 pin
//   <info> GPIOA_10, KBI0_P10, SPI0_SCK, FTM0_CH0, ADC0_SE6
//     <-2=> ADC0_SE6 (reset default)<selection=ADC0_SE6_PIN_SEL,PTB2 (reset default)>
//     <0=> GPIOA_10<selection=GPIOA_10_PIN_SEL,PTB2>
//     <1=> KBI0_P10<selection=KBI0_P10_PIN_SEL,PTB2>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTB2>
//     <3=> FTM0_CH0<selection=FTM0_CH0_PIN_SEL,PTB2>
//     <4=> ADC0_SE6<selection=ADC0_SE6_PIN_SEL,PTB2>
//     <-2=> Default
#define PTB2_SIG_SEL         -2

// Signal mapping for PTB3 pin
//   <o>    PTB3<name=PTB3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB3 pin
//   <info> GPIOA_11, KBI0_P11, SPI0_MOSI, FTM0_CH1, ADC0_SE7
//     <-2=> ADC0_SE7 (reset default)<selection=ADC0_SE7_PIN_SEL,PTB3 (reset default)>
//     <0=> GPIOA_11<selection=GPIOA_11_PIN_SEL,PTB3>
//     <1=> KBI0_P11<selection=KBI0_P11_PIN_SEL,PTB3>
//     <2=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTB3>
//     <3=> FTM0_CH1<selection=FTM0_CH1_PIN_SEL,PTB3>
//     <4=> ADC0_SE7<selection=ADC0_SE7_PIN_SEL,PTB3>
//     <-2=> Default
#define PTB3_SIG_SEL         -2

// Signal mapping for PTB4 pin
//   <o>    PTB4<name=PTB4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB4 pin
//   <info> GPIOA_12, KBI0_P12, FTM2_CH4, SPI0_MISO, ACMP1_IN2, NMI_b
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
//   <o>    PTB5<name=PTB5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB5 pin
//   <info> GPIOA_13, KBI0_P13, FTM2_CH5, SPI0_PCS, ACMP1_OUT
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_13<selection=GPIOA_13_PIN_SEL,PTB5>
//     <1=> KBI0_P13<selection=KBI0_P13_PIN_SEL,PTB5>
//     <2=> FTM2_CH5<selection=FTM2_CH5_PIN_SEL,PTB5>
//     <3=> SPI0_PCS<selection=SPI0_PCS_PIN_SEL,PTB5>
//     <4=> ACMP1_OUT<selection=ACMP1_OUT_PIN_SEL,PTB5>
//     <-2=> Default
#define PTB5_SIG_SEL         -2

// Signal mapping for PTB6 pin
//   <o>    PTB6<name=PTB6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB6 pin
//   <info> GPIOA_14, KBI0_P14, I2C0_SDA, XTAL
//     <-2=> XTAL (reset default)<selection=XTAL_PIN_SEL,PTB6 (reset default)>
//     <0=> GPIOA_14<selection=GPIOA_14_PIN_SEL,PTB6>
//     <1=> KBI0_P14<selection=KBI0_P14_PIN_SEL,PTB6>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTB6>
//     <6=> XTAL<selection=XTAL_PIN_SEL,PTB6>
//     <-2=> Default
#define PTB6_SIG_SEL         -2

// Signal mapping for PTB7 pin
//   <o>    PTB7<name=PTB7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB7 pin
//   <info> GPIOA_15, KBI0_P15, I2C0_SCL, EXTAL
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
//   <o>    PTC0<name=PTC0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC0 pin
//   <info> GPIOA_16, KBI0_P16, FTM2_CH0, ADC0_SE8
//     <-2=> ADC0_SE8 (reset default)<selection=ADC0_SE8_PIN_SEL,PTC0 (reset default)>
//     <0=> GPIOA_16<selection=GPIOA_16_PIN_SEL,PTC0>
//     <1=> KBI0_P16<selection=KBI0_P16_PIN_SEL,PTC0>
//     <2=> FTM2_CH0<selection=FTM2_CH0_PIN_SEL,PTC0>
//     <4=> ADC0_SE8<selection=ADC0_SE8_PIN_SEL,PTC0>
//     <-2=> Default
#define PTC0_SIG_SEL         -2

// Signal mapping for PTC1 pin
//   <o>    PTC1<name=PTC1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC1 pin
//   <info> GPIOA_17, KBI0_P17, FTM2_CH1, ADC0_SE9
//     <-2=> ADC0_SE9 (reset default)<selection=ADC0_SE9_PIN_SEL,PTC1 (reset default)>
//     <0=> GPIOA_17<selection=GPIOA_17_PIN_SEL,PTC1>
//     <1=> KBI0_P17<selection=KBI0_P17_PIN_SEL,PTC1>
//     <2=> FTM2_CH1<selection=FTM2_CH1_PIN_SEL,PTC1>
//     <4=> ADC0_SE9<selection=ADC0_SE9_PIN_SEL,PTC1>
//     <-2=> Default
#define PTC1_SIG_SEL         -2

// Signal mapping for PTC2 pin
//   <o>    PTC2<name=PTC2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC2 pin
//   <info> GPIOA_18, KBI0_P18, FTM2_CH2, ADC0_SE10
//     <-2=> ADC0_SE10 (reset default)<selection=ADC0_SE10_PIN_SEL,PTC2 (reset default)>
//     <0=> GPIOA_18<selection=GPIOA_18_PIN_SEL,PTC2>
//     <1=> KBI0_P18<selection=KBI0_P18_PIN_SEL,PTC2>
//     <2=> FTM2_CH2<selection=FTM2_CH2_PIN_SEL,PTC2>
//     <4=> ADC0_SE10<selection=ADC0_SE10_PIN_SEL,PTC2>
//     <-2=> Default
#define PTC2_SIG_SEL         -2

// Signal mapping for PTC3 pin
//   <o>    PTC3<name=PTC3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC3 pin
//   <info> GPIOA_19, KBI0_P19, FTM2_CH3, ADC0_SE11
//     <-2=> ADC0_SE11 (reset default)<selection=ADC0_SE11_PIN_SEL,PTC3 (reset default)>
//     <0=> GPIOA_19<selection=GPIOA_19_PIN_SEL,PTC3>
//     <1=> KBI0_P19<selection=KBI0_P19_PIN_SEL,PTC3>
//     <2=> FTM2_CH3<selection=FTM2_CH3_PIN_SEL,PTC3>
//     <4=> ADC0_SE11<selection=ADC0_SE11_PIN_SEL,PTC3>
//     <-2=> Default
#define PTC3_SIG_SEL         -2

// Signal mapping for PTC4 pin
//   <o>    PTC4<name=PTC4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC4 pin
//   <info> GPIOA_20, KBI0_P20, RTC_CLKOUT, FTM1_CH0, ACMP0_IN2, SWD_CLK
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
//   <o>    PTC5<name=PTC5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC5 pin
//   <info> GPIOA_21, KBI0_P21, FTM1_CH1, RTC_CLKOUT
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_21<selection=GPIOA_21_PIN_SEL,PTC5>
//     <1=> KBI0_P21<selection=KBI0_P21_PIN_SEL,PTC5>
//     <3=> FTM1_CH1<selection=FTM1_CH1_PIN_SEL,PTC5>
//     <5=> RTC_CLKOUT<selection=RTC_CLKOUT_PIN_SEL,PTC5>
//     <-2=> Default
#define PTC5_SIG_SEL         -2

// Signal mapping for PTC6 pin
//   <o>    PTC6<name=PTC6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC6 pin
//   <info> GPIOA_22, KBI0_P22, UART1_RX, CAN0_RX
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_22<selection=GPIOA_22_PIN_SEL,PTC6>
//     <1=> KBI0_P22<selection=KBI0_P22_PIN_SEL,PTC6>
//     <2=> UART1_RX<selection=UART1_RX_PIN_SEL,PTC6>
//     <5=> CAN0_RX<selection=CAN0_RX_PIN_SEL,PTC6>
//     <-2=> Default
#define PTC6_SIG_SEL         -2

// Signal mapping for PTC7 pin
//   <o>    PTC7<name=PTC7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC7 pin
//   <info> GPIOA_23, KBI0_P23, UART1_TX, CAN0_TX
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
//   <o>    PTD0<name=PTD0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD0 pin
//   <info> GPIOA_24, KBI0_P24, FTM2_CH2, SPI1_SCK
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_24<selection=GPIOA_24_PIN_SEL,PTD0>
//     <1=> KBI0_P24<selection=KBI0_P24_PIN_SEL,PTD0>
//     <2=> FTM2_CH2<selection=FTM2_CH2_PIN_SEL,PTD0>
//     <3=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTD0>
//     <-2=> Default
#define PTD0_SIG_SEL         -2

// Signal mapping for PTD1 pin
//   <o>    PTD1<name=PTD1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD1 pin
//   <info> GPIOA_25, KBI0_P25, FTM2_CH3, SPI1_MOSI
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_25<selection=GPIOA_25_PIN_SEL,PTD1>
//     <1=> KBI0_P25<selection=KBI0_P25_PIN_SEL,PTD1>
//     <2=> FTM2_CH3<selection=FTM2_CH3_PIN_SEL,PTD1>
//     <3=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTD1>
//     <-2=> Default
#define PTD1_SIG_SEL         -2

// Signal mapping for PTD2 pin
//   <o>    PTD2<name=PTD2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD2 pin
//   <info> GPIOA_26, KBI0_P26, SPI1_MISO
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_26<selection=GPIOA_26_PIN_SEL,PTD2>
//     <1=> KBI0_P26<selection=KBI0_P26_PIN_SEL,PTD2>
//     <2=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTD2>
//     <-2=> Default
#define PTD2_SIG_SEL         -2

// Signal mapping for PTD3 pin
//   <o>    PTD3<name=PTD3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD3 pin
//   <info> GPIOA_27, KBI0_P27, SPI1_PCS
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_27<selection=GPIOA_27_PIN_SEL,PTD3>
//     <1=> KBI0_P27<selection=KBI0_P27_PIN_SEL,PTD3>
//     <2=> SPI1_PCS<selection=SPI1_PCS_PIN_SEL,PTD3>
//     <-2=> Default
#define PTD3_SIG_SEL         -2

// Signal mapping for PTD4 pin
//   <o>    PTD4<name=PTD4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD4 pin
//   <info> GPIOA_28, KBI0_P28
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_28<selection=GPIOA_28_PIN_SEL,PTD4>
//     <1=> KBI0_P28<selection=KBI0_P28_PIN_SEL,PTD4>
//     <-2=> Default
#define PTD4_SIG_SEL         -2

// Signal mapping for PTD5 pin
//   <o>    PTD5<name=PTD5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD5 pin
//   <info> GPIOA_29, KBI0_P29, PWT_IN0
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_29<selection=GPIOA_29_PIN_SEL,PTD5>
//     <1=> KBI0_P29<selection=KBI0_P29_PIN_SEL,PTD5>
//     <2=> PWT_IN0<selection=PWT_IN0_PIN_SEL,PTD5>
//     <-2=> Default
#define PTD5_SIG_SEL         -2

// Signal mapping for PTD6 pin
//   <o>    PTD6<name=PTD6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD6 pin
//   <info> GPIOA_30, KBI0_P30, UART2_RX
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_30<selection=GPIOA_30_PIN_SEL,PTD6>
//     <1=> KBI0_P30<selection=KBI0_P30_PIN_SEL,PTD6>
//     <2=> UART2_RX<selection=UART2_RX_PIN_SEL,PTD6>
//     <-2=> Default
#define PTD6_SIG_SEL         -2

// Signal mapping for PTD7 pin
//   <o>    PTD7<name=PTD7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD7 pin
//   <info> GPIOA_31, KBI0_P31, UART2_TX
//     <-2=> Disabled (reset default)
//     <0=> GPIOA_31<selection=GPIOA_31_PIN_SEL,PTD7>
//     <1=> KBI0_P31<selection=KBI0_P31_PIN_SEL,PTD7>
//     <2=> UART2_TX<selection=UART2_TX_PIN_SEL,PTD7>
//     <-2=> Default
#define PTD7_SIG_SEL         -2

// </h>

// <h> Port E Pins

// Signal mapping for PTE0 pin
//   <o>    PTE0<name=PTE0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE0 pin
//   <info> GPIOB_0, KBI1_P0, SPI0_SCK, TCLK1, I2C1_SDA
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_0<selection=GPIOB_0_PIN_SEL,PTE0>
//     <1=> KBI1_P0<selection=KBI1_P0_PIN_SEL,PTE0>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTE0>
//     <3=> TCLK1<selection=TCLK1_PIN_SEL,PTE0>
//     <4=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTE0>
//     <-2=> Default
#define PTE0_SIG_SEL         -2

// Signal mapping for PTE1 pin
//   <o>    PTE1<name=PTE1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE1 pin
//   <info> GPIOB_1, KBI1_P1, SPI0_MOSI, I2C1_SCL
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_1<selection=GPIOB_1_PIN_SEL,PTE1>
//     <1=> KBI1_P1<selection=KBI1_P1_PIN_SEL,PTE1>
//     <2=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTE1>
//     <4=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTE1>
//     <-2=> Default
#define PTE1_SIG_SEL         -2

// Signal mapping for PTE2 pin
//   <o>    PTE2<name=PTE2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE2 pin
//   <info> GPIOB_2, KBI1_P2, SPI0_MISO, PWT_IN0
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_2<selection=GPIOB_2_PIN_SEL,PTE2>
//     <1=> KBI1_P2<selection=KBI1_P2_PIN_SEL,PTE2>
//     <2=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTE2>
//     <3=> PWT_IN0<selection=PWT_IN0_PIN_SEL,PTE2>
//     <-2=> Default
#define PTE2_SIG_SEL         -2

// Signal mapping for PTE3 pin
//   <o>    PTE3<name=PTE3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE3 pin
//   <info> GPIOB_3, KBI1_P3, SPI0_PCS
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_3<selection=GPIOB_3_PIN_SEL,PTE3>
//     <1=> KBI1_P3<selection=KBI1_P3_PIN_SEL,PTE3>
//     <2=> SPI0_PCS<selection=SPI0_PCS_PIN_SEL,PTE3>
//     <-2=> Default
#define PTE3_SIG_SEL         -2

// Signal mapping for PTE4 pin
//   <o>    PTE4<name=PTE4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE4 pin
//   <info> GPIOB_4, KBI1_P4
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_4<selection=GPIOB_4_PIN_SEL,PTE4>
//     <1=> KBI1_P4<selection=KBI1_P4_PIN_SEL,PTE4>
//     <-2=> Default
#define PTE4_SIG_SEL         -2

// Signal mapping for PTE5 pin
//   <o>    PTE5<name=PTE5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE5 pin
//   <info> GPIOB_5, KBI1_P5
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_5<selection=GPIOB_5_PIN_SEL,PTE5>
//     <1=> KBI1_P5<selection=KBI1_P5_PIN_SEL,PTE5>
//     <-2=> Default
#define PTE5_SIG_SEL         -2

// Signal mapping for PTE6 pin
//   <o>    PTE6<name=PTE6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE6 pin
//   <info> GPIOB_6, KBI1_P6
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_6<selection=GPIOB_6_PIN_SEL,PTE6>
//     <1=> KBI1_P6<selection=KBI1_P6_PIN_SEL,PTE6>
//     <-2=> Default
#define PTE6_SIG_SEL         -2

// Signal mapping for PTE7 pin
//   <o>    PTE7<name=PTE7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE7 pin
//   <info> GPIOB_7, KBI1_P7, TCLK2, FTM1_CH1, CAN0_TX
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
//   <o>    PTF0<name=PTF0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTF0 pin
//   <info> GPIOB_8, KBI1_P8, FTM2_CH0
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_8<selection=GPIOB_8_PIN_SEL,PTF0>
//     <1=> KBI1_P8<selection=KBI1_P8_PIN_SEL,PTF0>
//     <2=> FTM2_CH0<selection=FTM2_CH0_PIN_SEL,PTF0>
//     <-2=> Default
#define PTF0_SIG_SEL         -2

// Signal mapping for PTF1 pin
//   <o>    PTF1<name=PTF1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTF1 pin
//   <info> GPIOB_9, KBI1_P9, FTM2_CH1
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_9<selection=GPIOB_9_PIN_SEL,PTF1>
//     <1=> KBI1_P9<selection=KBI1_P9_PIN_SEL,PTF1>
//     <2=> FTM2_CH1<selection=FTM2_CH1_PIN_SEL,PTF1>
//     <-2=> Default
#define PTF1_SIG_SEL         -2

// Signal mapping for PTF2 pin
//   <o>    PTF2<name=PTF2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTF2 pin
//   <info> GPIOB_10, KBI1_P10, UART1_RX
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_10<selection=GPIOB_10_PIN_SEL,PTF2>
//     <1=> KBI1_P10<selection=KBI1_P10_PIN_SEL,PTF2>
//     <2=> UART1_RX<selection=UART1_RX_PIN_SEL,PTF2>
//     <-2=> Default
#define PTF2_SIG_SEL         -2

// Signal mapping for PTF3 pin
//   <o>    PTF3<name=PTF3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTF3 pin
//   <info> GPIOB_11, KBI1_P11, UART1_TX
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_11<selection=GPIOB_11_PIN_SEL,PTF3>
//     <1=> KBI1_P11<selection=KBI1_P11_PIN_SEL,PTF3>
//     <2=> UART1_TX<selection=UART1_TX_PIN_SEL,PTF3>
//     <-2=> Default
#define PTF3_SIG_SEL         -2

// Signal mapping for PTF4 pin
//   <o>    PTF4<name=PTF4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTF4 pin
//   <info> GPIOB_12, KBI1_P12, ADC0_SE12
//     <-2=> ADC0_SE12 (reset default)<selection=ADC0_SE12_PIN_SEL,PTF4 (reset default)>
//     <0=> GPIOB_12<selection=GPIOB_12_PIN_SEL,PTF4>
//     <1=> KBI1_P12<selection=KBI1_P12_PIN_SEL,PTF4>
//     <4=> ADC0_SE12<selection=ADC0_SE12_PIN_SEL,PTF4>
//     <-2=> Default
#define PTF4_SIG_SEL         -2

// Signal mapping for PTF5 pin
//   <o>    PTF5<name=PTF5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTF5 pin
//   <info> GPIOB_13, KBI1_P13, ADC0_SE13
//     <-2=> ADC0_SE13 (reset default)<selection=ADC0_SE13_PIN_SEL,PTF5 (reset default)>
//     <0=> GPIOB_13<selection=GPIOB_13_PIN_SEL,PTF5>
//     <1=> KBI1_P13<selection=KBI1_P13_PIN_SEL,PTF5>
//     <4=> ADC0_SE13<selection=ADC0_SE13_PIN_SEL,PTF5>
//     <-2=> Default
#define PTF5_SIG_SEL         -2

// Signal mapping for PTF6 pin
//   <o>    PTF6<name=PTF6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTF6 pin
//   <info> GPIOB_14, KBI1_P14, ADC0_SE14
//     <-2=> ADC0_SE14 (reset default)<selection=ADC0_SE14_PIN_SEL,PTF6 (reset default)>
//     <0=> GPIOB_14<selection=GPIOB_14_PIN_SEL,PTF6>
//     <1=> KBI1_P14<selection=KBI1_P14_PIN_SEL,PTF6>
//     <4=> ADC0_SE14<selection=ADC0_SE14_PIN_SEL,PTF6>
//     <-2=> Default
#define PTF6_SIG_SEL         -2

// Signal mapping for PTF7 pin
//   <o>    PTF7<name=PTF7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTF7 pin
//   <info> GPIOB_15, KBI1_P15, ADC0_SE15
//     <-2=> ADC0_SE15 (reset default)<selection=ADC0_SE15_PIN_SEL,PTF7 (reset default)>
//     <0=> GPIOB_15<selection=GPIOB_15_PIN_SEL,PTF7>
//     <1=> KBI1_P15<selection=KBI1_P15_PIN_SEL,PTF7>
//     <4=> ADC0_SE15<selection=ADC0_SE15_PIN_SEL,PTF7>
//     <-2=> Default
#define PTF7_SIG_SEL         -2

// </h>

// <h> Port G Pins

// Signal mapping for PTG0 pin
//   <o>    PTG0<name=PTG0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTG0 pin
//   <info> GPIOB_16, KBI1_P16
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_16<selection=GPIOB_16_PIN_SEL,PTG0>
//     <1=> KBI1_P16<selection=KBI1_P16_PIN_SEL,PTG0>
//     <-2=> Default
#define PTG0_SIG_SEL         -2

// Signal mapping for PTG1 pin
//   <o>    PTG1<name=PTG1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTG1 pin
//   <info> GPIOB_17, KBI1_P17
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_17<selection=GPIOB_17_PIN_SEL,PTG1>
//     <1=> KBI1_P17<selection=KBI1_P17_PIN_SEL,PTG1>
//     <-2=> Default
#define PTG1_SIG_SEL         -2

// Signal mapping for PTG2 pin
//   <o>    PTG2<name=PTG2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTG2 pin
//   <info> GPIOB_18, KBI1_P18
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_18<selection=GPIOB_18_PIN_SEL,PTG2>
//     <1=> KBI1_P18<selection=KBI1_P18_PIN_SEL,PTG2>
//     <-2=> Default
#define PTG2_SIG_SEL         -2

// Signal mapping for PTG3 pin
//   <o>    PTG3<name=PTG3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTG3 pin
//   <info> GPIOB_19, KBI1_P19
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_19<selection=GPIOB_19_PIN_SEL,PTG3>
//     <1=> KBI1_P19<selection=KBI1_P19_PIN_SEL,PTG3>
//     <-2=> Default
#define PTG3_SIG_SEL         -2

// Signal mapping for PTG4 pin
//   <o>    PTG4<name=PTG4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTG4 pin
//   <info> GPIOB_20, KBI1_P20, FTM2_CH2, SPI1_SCK
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_20<selection=GPIOB_20_PIN_SEL,PTG4>
//     <1=> KBI1_P20<selection=KBI1_P20_PIN_SEL,PTG4>
//     <2=> FTM2_CH2<selection=FTM2_CH2_PIN_SEL,PTG4>
//     <3=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTG4>
//     <-2=> Default
#define PTG4_SIG_SEL         -2

// Signal mapping for PTG5 pin
//   <o>    PTG5 (Alias:LED_RED)<name=PTG5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTG5 pin
//   <info> GPIOB_21, KBI1_P21, FTM2_CH3, SPI1_MOSI
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_21<selection=GPIOB_21_PIN_SEL,PTG5 (Alias:LED_RED)>
//     <1=> KBI1_P21<selection=KBI1_P21_PIN_SEL,PTG5 (Alias:LED_RED)>
//     <2=> FTM2_CH3<selection=FTM2_CH3_PIN_SEL,PTG5 (Alias:LED_RED)>
//     <3=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTG5 (Alias:LED_RED)>
//     <0=> Default
#define PTG5_SIG_SEL         0

// Signal mapping for PTG6 pin
//   <o>    PTG6 (Alias:LED_GREEN)<name=PTG6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTG6 pin
//   <info> GPIOB_22, KBI1_P22, FTM2_CH4, SPI1_MISO
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_22<selection=GPIOB_22_PIN_SEL,PTG6 (Alias:LED_GREEN)>
//     <1=> KBI1_P22<selection=KBI1_P22_PIN_SEL,PTG6 (Alias:LED_GREEN)>
//     <2=> FTM2_CH4<selection=FTM2_CH4_PIN_SEL,PTG6 (Alias:LED_GREEN)>
//     <3=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTG6 (Alias:LED_GREEN)>
//     <0=> Default
#define PTG6_SIG_SEL         0

// Signal mapping for PTG7 pin
//   <o>    PTG7 (Alias:LED_BLUE)<name=PTG7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTG7 pin
//   <info> GPIOB_23, KBI1_P23, FTM2_CH5, SPI1_PCS
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
//   <o>    PTH0<name=PTH0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTH0 pin
//   <info> GPIOB_24, KBI1_P24, FTM2_CH0
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_24<selection=GPIOB_24_PIN_SEL,PTH0>
//     <1=> KBI1_P24<selection=KBI1_P24_PIN_SEL,PTH0>
//     <2=> FTM2_CH0<selection=FTM2_CH0_PIN_SEL,PTH0>
//     <-2=> Default
#define PTH0_SIG_SEL         -2

// Signal mapping for PTH1 pin
//   <o>    PTH1<name=PTH1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTH1 pin
//   <info> GPIOB_25, KBI1_P25, FTM2_CH1
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_25<selection=GPIOB_25_PIN_SEL,PTH1>
//     <1=> KBI1_P25<selection=KBI1_P25_PIN_SEL,PTH1>
//     <2=> FTM2_CH1<selection=FTM2_CH1_PIN_SEL,PTH1>
//     <-2=> Default
#define PTH1_SIG_SEL         -2

// Signal mapping for PTH2 pin
//   <o>    PTH2<name=PTH2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTH2 pin
//   <info> GPIOB_26, KBI1_P26, BUSOUT, FTM1_CH0, CAN0_RX
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_26<selection=GPIOB_26_PIN_SEL,PTH2>
//     <1=> KBI1_P26<selection=KBI1_P26_PIN_SEL,PTH2>
//     <2=> BUSOUT<selection=BUSOUT_PIN_SEL,PTH2>
//     <4=> FTM1_CH0<selection=FTM1_CH0_PIN_SEL,PTH2>
//     <5=> CAN0_RX<selection=CAN0_RX_PIN_SEL,PTH2>
//     <-2=> Default
#define PTH2_SIG_SEL         -2

// Signal mapping for PTH3 pin
//   <o>    PTH3<name=PTH3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTH3 pin
//   <info> GPIOB_27, KBI1_P27, I2C1_SDA
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_27<selection=GPIOB_27_PIN_SEL,PTH3>
//     <1=> KBI1_P27<selection=KBI1_P27_PIN_SEL,PTH3>
//     <2=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTH3>
//     <-2=> Default
#define PTH3_SIG_SEL         -2

// Signal mapping for PTH4 pin
//   <o>    PTH4<name=PTH4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTH4 pin
//   <info> GPIOB_28, KBI1_P28, I2C1_SCL
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_28<selection=GPIOB_28_PIN_SEL,PTH4>
//     <1=> KBI1_P28<selection=KBI1_P28_PIN_SEL,PTH4>
//     <2=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTH4>
//     <-2=> Default
#define PTH4_SIG_SEL         -2

// Signal mapping for PTH5 pin
//   <o>    PTH5<name=PTH5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTH5 pin
//   <info> GPIOB_29, KBI1_P29
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_29<selection=GPIOB_29_PIN_SEL,PTH5>
//     <1=> KBI1_P29<selection=KBI1_P29_PIN_SEL,PTH5>
//     <-2=> Default
#define PTH5_SIG_SEL         -2

// Signal mapping for PTH6 pin
//   <o>    PTH6<name=PTH6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTH6 pin
//   <info> GPIOB_30, KBI1_P30
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_30<selection=GPIOB_30_PIN_SEL,PTH6>
//     <1=> KBI1_P30<selection=KBI1_P30_PIN_SEL,PTH6>
//     <-2=> Default
#define PTH6_SIG_SEL         -2

// Signal mapping for PTH7 pin
//   <o>    PTH7<name=PTH7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTH7 pin
//   <info> GPIOB_31, KBI1_P31, PWT_IN1
//     <-2=> Disabled (reset default)
//     <0=> GPIOB_31<selection=GPIOB_31_PIN_SEL,PTH7>
//     <1=> KBI1_P31<selection=KBI1_P31_PIN_SEL,PTH7>
//     <2=> PWT_IN1<selection=PWT_IN1_PIN_SEL,PTH7>
//     <-2=> Default
#define PTH7_SIG_SEL         -2

// </h>

// <h> Port I Pins

// Signal mapping for PTI0 pin
//   <o>    PTI0<name=PTI0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTI0 pin
//   <info> GPIOC_0, IRQ, UART2_RX
//     <-2=> Disabled (reset default)
//     <0=> GPIOC_0<selection=GPIOC_0_PIN_SEL,PTI0>
//     <2=> IRQ<selection=IRQ_PIN_SEL,PTI0>
//     <3=> UART2_RX<selection=UART2_RX_PIN_SEL,PTI0>
//     <-2=> Default
#define PTI0_SIG_SEL         -2

// Signal mapping for PTI1 pin
//   <o>    PTI1<name=PTI1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTI1 pin
//   <info> GPIOC_1, IRQ, UART2_TX
//     <-2=> Disabled (reset default)
//     <0=> GPIOC_1<selection=GPIOC_1_PIN_SEL,PTI1>
//     <2=> IRQ<selection=IRQ_PIN_SEL,PTI1>
//     <3=> UART2_TX<selection=UART2_TX_PIN_SEL,PTI1>
//     <-2=> Default
#define PTI1_SIG_SEL         -2

// Signal mapping for PTI2 pin
//   <o>    PTI2<name=PTI2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTI2 pin
//   <info> GPIOC_2, IRQ
//     <-2=> Disabled (reset default)
//     <0=> GPIOC_2<selection=GPIOC_2_PIN_SEL,PTI2>
//     <1=> IRQ<selection=IRQ_PIN_SEL,PTI2>
//     <-2=> Default
#define PTI2_SIG_SEL         -2

// Signal mapping for PTI3 pin
//   <o>    PTI3<name=PTI3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTI3 pin
//   <info> GPIOC_3, IRQ
//     <-2=> Disabled (reset default)
//     <0=> GPIOC_3<selection=GPIOC_3_PIN_SEL,PTI3>
//     <1=> IRQ<selection=IRQ_PIN_SEL,PTI3>
//     <-2=> Default
#define PTI3_SIG_SEL         -2

// Signal mapping for PTI4 pin
//   <o>    PTI4<name=PTI4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTI4 pin
//   <info> GPIOC_4, IRQ
//     <-2=> Disabled (reset default)
//     <0=> GPIOC_4<selection=GPIOC_4_PIN_SEL,PTI4>
//     <2=> IRQ<selection=IRQ_PIN_SEL,PTI4>
//     <-2=> Default
#define PTI4_SIG_SEL         -2

// Signal mapping for PTI5 pin
//   <o>    PTI5<name=PTI5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTI5 pin
//   <info> GPIOC_5, IRQ
//     <-2=> Disabled (reset default)
//     <0=> GPIOC_5<selection=GPIOC_5_PIN_SEL,PTI5>
//     <1=> IRQ<selection=IRQ_PIN_SEL,PTI5>
//     <-2=> Default
#define PTI5_SIG_SEL         -2

// Signal mapping for PTI6 pin
//   <o>    PTI6<name=PTI6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTI6 pin
//   <info> GPIOC_6, IRQ
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
//   <o>    BUSOUT<name=BUSOUT_PIN_SEL>
//   <i>    Shows which pin BUSOUT is mapped to
//   <info>  [PTH2]
//     <0=> Disabled
//     <1=> PTH2<selection=PTH2_SIG_SEL,BUSOUT>
//     <0=> Default
#define BUSOUT_PIN_SEL       0

// Pin Mapping for IRQ signal
//   <o>    IRQ<name=IRQ_PIN_SEL>
//   <i>    Shows which pin IRQ is mapped to
//   <info>  [PTI2, PTI3, PTI5, PTI6, PTA5, PTI0, PTI1, PTI4]
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

// Pin Mapping for KBI0_P0 signal
//   <o>    KBI0_P0<name=KBI0_P0_PIN_SEL>
//   <i>    Shows which pin KBI0_P0 is mapped to
//   <info>  [PTA0]
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,KBI0_P0>
//     <0=> Default
#define KBI0_P0_PIN_SEL      0

// Pin Mapping for KBI0_P1 signal
//   <o>    KBI0_P1<name=KBI0_P1_PIN_SEL>
//   <i>    Shows which pin KBI0_P1 is mapped to
//   <info>  [PTA1]
//     <0=> Disabled
//     <1=> PTA1<selection=PTA1_SIG_SEL,KBI0_P1>
//     <0=> Default
#define KBI0_P1_PIN_SEL      0

// Pin Mapping for KBI0_P2 signal
//   <o>    KBI0_P2<name=KBI0_P2_PIN_SEL>
//   <i>    Shows which pin KBI0_P2 is mapped to
//   <info>  [PTA2]
//     <0=> Disabled
//     <1=> PTA2<selection=PTA2_SIG_SEL,KBI0_P2>
//     <0=> Default
#define KBI0_P2_PIN_SEL      0

// Pin Mapping for KBI0_P3 signal
//   <o>    KBI0_P3<name=KBI0_P3_PIN_SEL>
//   <i>    Shows which pin KBI0_P3 is mapped to
//   <info>  [PTA3]
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,KBI0_P3>
//     <0=> Default
#define KBI0_P3_PIN_SEL      0

// Pin Mapping for KBI0_P4 signal
//   <o>    KBI0_P4<name=KBI0_P4_PIN_SEL>
//   <i>    Shows which pin KBI0_P4 is mapped to
//   <info>  [PTA4]
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,KBI0_P4>
//     <0=> Default
#define KBI0_P4_PIN_SEL      0

// Pin Mapping for KBI0_P5 signal
//   <o>    KBI0_P5<name=KBI0_P5_PIN_SEL>
//   <i>    Shows which pin KBI0_P5 is mapped to
//   <info>  [PTA5]
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,KBI0_P5>
//     <0=> Default
#define KBI0_P5_PIN_SEL      0

// Pin Mapping for KBI0_P6 signal
//   <o>    KBI0_P6<name=KBI0_P6_PIN_SEL>
//   <i>    Shows which pin KBI0_P6 is mapped to
//   <info>  [PTA6]
//     <0=> Disabled
//     <1=> PTA6<selection=PTA6_SIG_SEL,KBI0_P6>
//     <0=> Default
#define KBI0_P6_PIN_SEL      0

// Pin Mapping for KBI0_P7 signal
//   <o>    KBI0_P7<name=KBI0_P7_PIN_SEL>
//   <i>    Shows which pin KBI0_P7 is mapped to
//   <info>  [PTA7]
//     <0=> Disabled
//     <1=> PTA7<selection=PTA7_SIG_SEL,KBI0_P7>
//     <0=> Default
#define KBI0_P7_PIN_SEL      0

// Pin Mapping for KBI0_P8 signal
//   <o>    KBI0_P8<name=KBI0_P8_PIN_SEL>
//   <i>    Shows which pin KBI0_P8 is mapped to
//   <info>  [PTB0]
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,KBI0_P8>
//     <0=> Default
#define KBI0_P8_PIN_SEL      0

// Pin Mapping for KBI0_P9 signal
//   <o>    KBI0_P9<name=KBI0_P9_PIN_SEL>
//   <i>    Shows which pin KBI0_P9 is mapped to
//   <info>  [PTB1]
//     <0=> Disabled
//     <1=> PTB1<selection=PTB1_SIG_SEL,KBI0_P9>
//     <0=> Default
#define KBI0_P9_PIN_SEL      0

// Pin Mapping for KBI0_P10 signal
//   <o>    KBI0_P10<name=KBI0_P10_PIN_SEL>
//   <i>    Shows which pin KBI0_P10 is mapped to
//   <info>  [PTB2]
//     <0=> Disabled
//     <1=> PTB2<selection=PTB2_SIG_SEL,KBI0_P10>
//     <0=> Default
#define KBI0_P10_PIN_SEL     0

// Pin Mapping for KBI0_P11 signal
//   <o>    KBI0_P11<name=KBI0_P11_PIN_SEL>
//   <i>    Shows which pin KBI0_P11 is mapped to
//   <info>  [PTB3]
//     <0=> Disabled
//     <1=> PTB3<selection=PTB3_SIG_SEL,KBI0_P11>
//     <0=> Default
#define KBI0_P11_PIN_SEL     0

// Pin Mapping for KBI0_P12 signal
//   <o>    KBI0_P12<name=KBI0_P12_PIN_SEL>
//   <i>    Shows which pin KBI0_P12 is mapped to
//   <info>  [PTB4]
//     <0=> Disabled
//     <1=> PTB4<selection=PTB4_SIG_SEL,KBI0_P12>
//     <0=> Default
#define KBI0_P12_PIN_SEL     0

// Pin Mapping for KBI0_P13 signal
//   <o>    KBI0_P13<name=KBI0_P13_PIN_SEL>
//   <i>    Shows which pin KBI0_P13 is mapped to
//   <info>  [PTB5]
//     <0=> Disabled
//     <1=> PTB5<selection=PTB5_SIG_SEL,KBI0_P13>
//     <0=> Default
#define KBI0_P13_PIN_SEL     0

// Pin Mapping for KBI0_P14 signal
//   <o>    KBI0_P14<name=KBI0_P14_PIN_SEL>
//   <i>    Shows which pin KBI0_P14 is mapped to
//   <info>  [PTB6]
//     <0=> Disabled
//     <1=> PTB6<selection=PTB6_SIG_SEL,KBI0_P14>
//     <0=> Default
#define KBI0_P14_PIN_SEL     0

// Pin Mapping for KBI0_P15 signal
//   <o>    KBI0_P15<name=KBI0_P15_PIN_SEL>
//   <i>    Shows which pin KBI0_P15 is mapped to
//   <info>  [PTB7]
//     <0=> Disabled
//     <1=> PTB7<selection=PTB7_SIG_SEL,KBI0_P15>
//     <0=> Default
#define KBI0_P15_PIN_SEL     0

// Pin Mapping for KBI0_P16 signal
//   <o>    KBI0_P16<name=KBI0_P16_PIN_SEL>
//   <i>    Shows which pin KBI0_P16 is mapped to
//   <info>  [PTC0]
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,KBI0_P16>
//     <0=> Default
#define KBI0_P16_PIN_SEL     0

// Pin Mapping for KBI0_P17 signal
//   <o>    KBI0_P17<name=KBI0_P17_PIN_SEL>
//   <i>    Shows which pin KBI0_P17 is mapped to
//   <info>  [PTC1]
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,KBI0_P17>
//     <0=> Default
#define KBI0_P17_PIN_SEL     0

// Pin Mapping for KBI0_P18 signal
//   <o>    KBI0_P18<name=KBI0_P18_PIN_SEL>
//   <i>    Shows which pin KBI0_P18 is mapped to
//   <info>  [PTC2]
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,KBI0_P18>
//     <0=> Default
#define KBI0_P18_PIN_SEL     0

// Pin Mapping for KBI0_P19 signal
//   <o>    KBI0_P19<name=KBI0_P19_PIN_SEL>
//   <i>    Shows which pin KBI0_P19 is mapped to
//   <info>  [PTC3]
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,KBI0_P19>
//     <0=> Default
#define KBI0_P19_PIN_SEL     0

// Pin Mapping for KBI0_P20 signal
//   <o>    KBI0_P20<name=KBI0_P20_PIN_SEL>
//   <i>    Shows which pin KBI0_P20 is mapped to
//   <info>  [PTC4]
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,KBI0_P20>
//     <0=> Default
#define KBI0_P20_PIN_SEL     0

// Pin Mapping for KBI0_P21 signal
//   <o>    KBI0_P21<name=KBI0_P21_PIN_SEL>
//   <i>    Shows which pin KBI0_P21 is mapped to
//   <info>  [PTC5]
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,KBI0_P21>
//     <0=> Default
#define KBI0_P21_PIN_SEL     0

// Pin Mapping for KBI0_P22 signal
//   <o>    KBI0_P22<name=KBI0_P22_PIN_SEL>
//   <i>    Shows which pin KBI0_P22 is mapped to
//   <info>  [PTC6]
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,KBI0_P22>
//     <0=> Default
#define KBI0_P22_PIN_SEL     0

// Pin Mapping for KBI0_P23 signal
//   <o>    KBI0_P23<name=KBI0_P23_PIN_SEL>
//   <i>    Shows which pin KBI0_P23 is mapped to
//   <info>  [PTC7]
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,KBI0_P23>
//     <0=> Default
#define KBI0_P23_PIN_SEL     0

// Pin Mapping for KBI0_P24 signal
//   <o>    KBI0_P24<name=KBI0_P24_PIN_SEL>
//   <i>    Shows which pin KBI0_P24 is mapped to
//   <info>  [PTD0]
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,KBI0_P24>
//     <0=> Default
#define KBI0_P24_PIN_SEL     0

// Pin Mapping for KBI0_P25 signal
//   <o>    KBI0_P25<name=KBI0_P25_PIN_SEL>
//   <i>    Shows which pin KBI0_P25 is mapped to
//   <info>  [PTD1]
//     <0=> Disabled
//     <1=> PTD1<selection=PTD1_SIG_SEL,KBI0_P25>
//     <0=> Default
#define KBI0_P25_PIN_SEL     0

// Pin Mapping for KBI0_P26 signal
//   <o>    KBI0_P26<name=KBI0_P26_PIN_SEL>
//   <i>    Shows which pin KBI0_P26 is mapped to
//   <info>  [PTD2]
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,KBI0_P26>
//     <0=> Default
#define KBI0_P26_PIN_SEL     0

// Pin Mapping for KBI0_P27 signal
//   <o>    KBI0_P27<name=KBI0_P27_PIN_SEL>
//   <i>    Shows which pin KBI0_P27 is mapped to
//   <info>  [PTD3]
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,KBI0_P27>
//     <0=> Default
#define KBI0_P27_PIN_SEL     0

// Pin Mapping for KBI0_P28 signal
//   <o>    KBI0_P28<name=KBI0_P28_PIN_SEL>
//   <i>    Shows which pin KBI0_P28 is mapped to
//   <info>  [PTD4]
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,KBI0_P28>
//     <0=> Default
#define KBI0_P28_PIN_SEL     0

// Pin Mapping for KBI0_P29 signal
//   <o>    KBI0_P29<name=KBI0_P29_PIN_SEL>
//   <i>    Shows which pin KBI0_P29 is mapped to
//   <info>  [PTD5]
//     <0=> Disabled
//     <1=> PTD5<selection=PTD5_SIG_SEL,KBI0_P29>
//     <0=> Default
#define KBI0_P29_PIN_SEL     0

// Pin Mapping for KBI0_P30 signal
//   <o>    KBI0_P30<name=KBI0_P30_PIN_SEL>
//   <i>    Shows which pin KBI0_P30 is mapped to
//   <info>  [PTD6]
//     <0=> Disabled
//     <1=> PTD6<selection=PTD6_SIG_SEL,KBI0_P30>
//     <0=> Default
#define KBI0_P30_PIN_SEL     0

// Pin Mapping for KBI0_P31 signal
//   <o>    KBI0_P31<name=KBI0_P31_PIN_SEL>
//   <i>    Shows which pin KBI0_P31 is mapped to
//   <info>  [PTD7]
//     <0=> Disabled
//     <1=> PTD7<selection=PTD7_SIG_SEL,KBI0_P31>
//     <0=> Default
#define KBI0_P31_PIN_SEL     0

// Pin Mapping for KBI1_P0 signal
//   <o>    KBI1_P0<name=KBI1_P0_PIN_SEL>
//   <i>    Shows which pin KBI1_P0 is mapped to
//   <info>  [PTE0]
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,KBI1_P0>
//     <0=> Default
#define KBI1_P0_PIN_SEL      0

// Pin Mapping for KBI1_P1 signal
//   <o>    KBI1_P1<name=KBI1_P1_PIN_SEL>
//   <i>    Shows which pin KBI1_P1 is mapped to
//   <info>  [PTE1]
//     <0=> Disabled
//     <1=> PTE1<selection=PTE1_SIG_SEL,KBI1_P1>
//     <0=> Default
#define KBI1_P1_PIN_SEL      0

// Pin Mapping for KBI1_P2 signal
//   <o>    KBI1_P2<name=KBI1_P2_PIN_SEL>
//   <i>    Shows which pin KBI1_P2 is mapped to
//   <info>  [PTE2]
//     <0=> Disabled
//     <1=> PTE2<selection=PTE2_SIG_SEL,KBI1_P2>
//     <0=> Default
#define KBI1_P2_PIN_SEL      0

// Pin Mapping for KBI1_P3 signal
//   <o>    KBI1_P3<name=KBI1_P3_PIN_SEL>
//   <i>    Shows which pin KBI1_P3 is mapped to
//   <info>  [PTE3]
//     <0=> Disabled
//     <1=> PTE3<selection=PTE3_SIG_SEL,KBI1_P3>
//     <0=> Default
#define KBI1_P3_PIN_SEL      0

// Pin Mapping for KBI1_P4 signal
//   <o>    KBI1_P4<name=KBI1_P4_PIN_SEL>
//   <i>    Shows which pin KBI1_P4 is mapped to
//   <info>  [PTE4]
//     <0=> Disabled
//     <1=> PTE4<selection=PTE4_SIG_SEL,KBI1_P4>
//     <0=> Default
#define KBI1_P4_PIN_SEL      0

// Pin Mapping for KBI1_P5 signal
//   <o>    KBI1_P5<name=KBI1_P5_PIN_SEL>
//   <i>    Shows which pin KBI1_P5 is mapped to
//   <info>  [PTE5]
//     <0=> Disabled
//     <1=> PTE5<selection=PTE5_SIG_SEL,KBI1_P5>
//     <0=> Default
#define KBI1_P5_PIN_SEL      0

// Pin Mapping for KBI1_P6 signal
//   <o>    KBI1_P6<name=KBI1_P6_PIN_SEL>
//   <i>    Shows which pin KBI1_P6 is mapped to
//   <info>  [PTE6]
//     <0=> Disabled
//     <1=> PTE6<selection=PTE6_SIG_SEL,KBI1_P6>
//     <0=> Default
#define KBI1_P6_PIN_SEL      0

// Pin Mapping for KBI1_P7 signal
//   <o>    KBI1_P7<name=KBI1_P7_PIN_SEL>
//   <i>    Shows which pin KBI1_P7 is mapped to
//   <info>  [PTE7]
//     <0=> Disabled
//     <1=> PTE7<selection=PTE7_SIG_SEL,KBI1_P7>
//     <0=> Default
#define KBI1_P7_PIN_SEL      0

// Pin Mapping for KBI1_P8 signal
//   <o>    KBI1_P8<name=KBI1_P8_PIN_SEL>
//   <i>    Shows which pin KBI1_P8 is mapped to
//   <info>  [PTF0]
//     <0=> Disabled
//     <1=> PTF0<selection=PTF0_SIG_SEL,KBI1_P8>
//     <0=> Default
#define KBI1_P8_PIN_SEL      0

// Pin Mapping for KBI1_P9 signal
//   <o>    KBI1_P9<name=KBI1_P9_PIN_SEL>
//   <i>    Shows which pin KBI1_P9 is mapped to
//   <info>  [PTF1]
//     <0=> Disabled
//     <1=> PTF1<selection=PTF1_SIG_SEL,KBI1_P9>
//     <0=> Default
#define KBI1_P9_PIN_SEL      0

// Pin Mapping for KBI1_P10 signal
//   <o>    KBI1_P10<name=KBI1_P10_PIN_SEL>
//   <i>    Shows which pin KBI1_P10 is mapped to
//   <info>  [PTF2]
//     <0=> Disabled
//     <1=> PTF2<selection=PTF2_SIG_SEL,KBI1_P10>
//     <0=> Default
#define KBI1_P10_PIN_SEL     0

// Pin Mapping for KBI1_P11 signal
//   <o>    KBI1_P11<name=KBI1_P11_PIN_SEL>
//   <i>    Shows which pin KBI1_P11 is mapped to
//   <info>  [PTF3]
//     <0=> Disabled
//     <1=> PTF3<selection=PTF3_SIG_SEL,KBI1_P11>
//     <0=> Default
#define KBI1_P11_PIN_SEL     0

// Pin Mapping for KBI1_P12 signal
//   <o>    KBI1_P12<name=KBI1_P12_PIN_SEL>
//   <i>    Shows which pin KBI1_P12 is mapped to
//   <info>  [PTF4]
//     <0=> Disabled
//     <1=> PTF4<selection=PTF4_SIG_SEL,KBI1_P12>
//     <0=> Default
#define KBI1_P12_PIN_SEL     0

// Pin Mapping for KBI1_P13 signal
//   <o>    KBI1_P13<name=KBI1_P13_PIN_SEL>
//   <i>    Shows which pin KBI1_P13 is mapped to
//   <info>  [PTF5]
//     <0=> Disabled
//     <1=> PTF5<selection=PTF5_SIG_SEL,KBI1_P13>
//     <0=> Default
#define KBI1_P13_PIN_SEL     0

// Pin Mapping for KBI1_P14 signal
//   <o>    KBI1_P14<name=KBI1_P14_PIN_SEL>
//   <i>    Shows which pin KBI1_P14 is mapped to
//   <info>  [PTF6]
//     <0=> Disabled
//     <1=> PTF6<selection=PTF6_SIG_SEL,KBI1_P14>
//     <0=> Default
#define KBI1_P14_PIN_SEL     0

// Pin Mapping for KBI1_P15 signal
//   <o>    KBI1_P15<name=KBI1_P15_PIN_SEL>
//   <i>    Shows which pin KBI1_P15 is mapped to
//   <info>  [PTF7]
//     <0=> Disabled
//     <1=> PTF7<selection=PTF7_SIG_SEL,KBI1_P15>
//     <0=> Default
#define KBI1_P15_PIN_SEL     0

// Pin Mapping for KBI1_P16 signal
//   <o>    KBI1_P16<name=KBI1_P16_PIN_SEL>
//   <i>    Shows which pin KBI1_P16 is mapped to
//   <info>  [PTG0]
//     <0=> Disabled
//     <1=> PTG0<selection=PTG0_SIG_SEL,KBI1_P16>
//     <0=> Default
#define KBI1_P16_PIN_SEL     0

// Pin Mapping for KBI1_P17 signal
//   <o>    KBI1_P17<name=KBI1_P17_PIN_SEL>
//   <i>    Shows which pin KBI1_P17 is mapped to
//   <info>  [PTG1]
//     <0=> Disabled
//     <1=> PTG1<selection=PTG1_SIG_SEL,KBI1_P17>
//     <0=> Default
#define KBI1_P17_PIN_SEL     0

// Pin Mapping for KBI1_P18 signal
//   <o>    KBI1_P18<name=KBI1_P18_PIN_SEL>
//   <i>    Shows which pin KBI1_P18 is mapped to
//   <info>  [PTG2]
//     <0=> Disabled
//     <1=> PTG2<selection=PTG2_SIG_SEL,KBI1_P18>
//     <0=> Default
#define KBI1_P18_PIN_SEL     0

// Pin Mapping for KBI1_P19 signal
//   <o>    KBI1_P19<name=KBI1_P19_PIN_SEL>
//   <i>    Shows which pin KBI1_P19 is mapped to
//   <info>  [PTG3]
//     <0=> Disabled
//     <1=> PTG3<selection=PTG3_SIG_SEL,KBI1_P19>
//     <0=> Default
#define KBI1_P19_PIN_SEL     0

// Pin Mapping for KBI1_P20 signal
//   <o>    KBI1_P20<name=KBI1_P20_PIN_SEL>
//   <i>    Shows which pin KBI1_P20 is mapped to
//   <info>  [PTG4]
//     <0=> Disabled
//     <1=> PTG4<selection=PTG4_SIG_SEL,KBI1_P20>
//     <0=> Default
#define KBI1_P20_PIN_SEL     0

// Pin Mapping for KBI1_P21 signal
//   <o>    KBI1_P21<name=KBI1_P21_PIN_SEL>
//   <i>    Shows which pin KBI1_P21 is mapped to
//   <info>  [PTG5]
//     <0=> Disabled
//     <1=> PTG5 (Alias:LED_RED)<selection=PTG5_SIG_SEL,KBI1_P21>
//     <0=> Default
#define KBI1_P21_PIN_SEL     0

// Pin Mapping for KBI1_P22 signal
//   <o>    KBI1_P22<name=KBI1_P22_PIN_SEL>
//   <i>    Shows which pin KBI1_P22 is mapped to
//   <info>  [PTG6]
//     <0=> Disabled
//     <1=> PTG6 (Alias:LED_GREEN)<selection=PTG6_SIG_SEL,KBI1_P22>
//     <0=> Default
#define KBI1_P22_PIN_SEL     0

// Pin Mapping for KBI1_P23 signal
//   <o>    KBI1_P23<name=KBI1_P23_PIN_SEL>
//   <i>    Shows which pin KBI1_P23 is mapped to
//   <info>  [PTG7]
//     <0=> Disabled
//     <1=> PTG7 (Alias:LED_BLUE)<selection=PTG7_SIG_SEL,KBI1_P23>
//     <0=> Default
#define KBI1_P23_PIN_SEL     0

// Pin Mapping for KBI1_P24 signal
//   <o>    KBI1_P24<name=KBI1_P24_PIN_SEL>
//   <i>    Shows which pin KBI1_P24 is mapped to
//   <info>  [PTH0]
//     <0=> Disabled
//     <1=> PTH0<selection=PTH0_SIG_SEL,KBI1_P24>
//     <0=> Default
#define KBI1_P24_PIN_SEL     0

// Pin Mapping for KBI1_P25 signal
//   <o>    KBI1_P25<name=KBI1_P25_PIN_SEL>
//   <i>    Shows which pin KBI1_P25 is mapped to
//   <info>  [PTH1]
//     <0=> Disabled
//     <1=> PTH1<selection=PTH1_SIG_SEL,KBI1_P25>
//     <0=> Default
#define KBI1_P25_PIN_SEL     0

// Pin Mapping for KBI1_P26 signal
//   <o>    KBI1_P26<name=KBI1_P26_PIN_SEL>
//   <i>    Shows which pin KBI1_P26 is mapped to
//   <info>  [PTH2]
//     <0=> Disabled
//     <1=> PTH2<selection=PTH2_SIG_SEL,KBI1_P26>
//     <0=> Default
#define KBI1_P26_PIN_SEL     0

// Pin Mapping for KBI1_P27 signal
//   <o>    KBI1_P27<name=KBI1_P27_PIN_SEL>
//   <i>    Shows which pin KBI1_P27 is mapped to
//   <info>  [PTH3]
//     <0=> Disabled
//     <1=> PTH3<selection=PTH3_SIG_SEL,KBI1_P27>
//     <0=> Default
#define KBI1_P27_PIN_SEL     0

// Pin Mapping for KBI1_P28 signal
//   <o>    KBI1_P28<name=KBI1_P28_PIN_SEL>
//   <i>    Shows which pin KBI1_P28 is mapped to
//   <info>  [PTH4]
//     <0=> Disabled
//     <1=> PTH4<selection=PTH4_SIG_SEL,KBI1_P28>
//     <0=> Default
#define KBI1_P28_PIN_SEL     0

// Pin Mapping for KBI1_P29 signal
//   <o>    KBI1_P29<name=KBI1_P29_PIN_SEL>
//   <i>    Shows which pin KBI1_P29 is mapped to
//   <info>  [PTH5]
//     <0=> Disabled
//     <1=> PTH5<selection=PTH5_SIG_SEL,KBI1_P29>
//     <0=> Default
#define KBI1_P29_PIN_SEL     0

// Pin Mapping for KBI1_P30 signal
//   <o>    KBI1_P30<name=KBI1_P30_PIN_SEL>
//   <i>    Shows which pin KBI1_P30 is mapped to
//   <info>  [PTH6]
//     <0=> Disabled
//     <1=> PTH6<selection=PTH6_SIG_SEL,KBI1_P30>
//     <0=> Default
#define KBI1_P30_PIN_SEL     0

// Pin Mapping for KBI1_P31 signal
//   <o>    KBI1_P31<name=KBI1_P31_PIN_SEL>
//   <i>    Shows which pin KBI1_P31 is mapped to
//   <info>  [PTH7]
//     <0=> Disabled
//     <1=> PTH7<selection=PTH7_SIG_SEL,KBI1_P31>
//     <0=> Default
#define KBI1_P31_PIN_SEL     0

// Pin Mapping for PWT_IN0 signal
//   <o>    PWT_IN0<name=PWT_IN0_PIN_SEL>
//   <i>    Shows which pin PWT_IN0 is mapped to
//   <info>  [PTD5, PTE2]
//     <0=> Disabled
//     <1=> PTD5<selection=PTD5_SIG_SEL,PWT_IN0>
//     <2=> PTE2<selection=PTE2_SIG_SEL,PWT_IN0>
//     <0=> Default
#define PWT_IN0_PIN_SEL      0

// Pin Mapping for PWT_IN1 signal
//   <o>    PWT_IN1<name=PWT_IN1_PIN_SEL>
//   <i>    Shows which pin PWT_IN1 is mapped to
//   <info>  [PTH7, PTB0]
//     <0=> Disabled
//     <1=> PTH7<selection=PTH7_SIG_SEL,PWT_IN1>
//     <2=> PTB0<selection=PTB0_SIG_SEL,PWT_IN1>
//     <0=> Default
#define PWT_IN1_PIN_SEL      0

// </h>

// <h> Analogue Comparator (ACMP0)

// Pin Mapping for ACMP0_IN0 signal
//   <o>    ACMP0_IN0<name=ACMP0_IN0_PIN_SEL>
//   <i>    Shows which pin ACMP0_IN0 is mapped to
//   <info>  [PTA0]
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,ACMP0_IN0>
//     <0=> Default
#define ACMP0_IN0_PIN_SEL    0

// Pin Mapping for ACMP0_IN1 signal
//   <o>    ACMP0_IN1<name=ACMP0_IN1_PIN_SEL>
//   <i>    Shows which pin ACMP0_IN1 is mapped to
//   <info>  [PTA1]
//     <0=> Disabled
//     <1=> PTA1<selection=PTA1_SIG_SEL,ACMP0_IN1>
//     <0=> Default
#define ACMP0_IN1_PIN_SEL    0

// Pin Mapping for ACMP0_IN2 signal
//   <o>    ACMP0_IN2<name=ACMP0_IN2_PIN_SEL>
//   <i>    Shows which pin ACMP0_IN2 is mapped to
//   <info>  [PTC4]
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,ACMP0_IN2>
//     <0=> Default
#define ACMP0_IN2_PIN_SEL    0

// Pin Mapping for ACMP0_OUT signal
//   <o>    ACMP0_OUT<name=ACMP0_OUT_PIN_SEL>
//   <i>    Shows which pin ACMP0_OUT is mapped to
//   <info>  [PTA4]
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,ACMP0_OUT>
//     <0=> Default
#define ACMP0_OUT_PIN_SEL    0

// </h>

// <h> Analogue Comparator (ACMP1)

// Pin Mapping for ACMP1_IN0 signal
//   <o>    ACMP1_IN0<name=ACMP1_IN0_PIN_SEL>
//   <i>    Shows which pin ACMP1_IN0 is mapped to
//   <info>  [PTA6]
//     <0=> Disabled
//     <1=> PTA6<selection=PTA6_SIG_SEL,ACMP1_IN0>
//     <0=> Default
#define ACMP1_IN0_PIN_SEL    0

// Pin Mapping for ACMP1_IN1 signal
//   <o>    ACMP1_IN1<name=ACMP1_IN1_PIN_SEL>
//   <i>    Shows which pin ACMP1_IN1 is mapped to
//   <info>  [PTA7]
//     <0=> Disabled
//     <1=> PTA7<selection=PTA7_SIG_SEL,ACMP1_IN1>
//     <0=> Default
#define ACMP1_IN1_PIN_SEL    0

// Pin Mapping for ACMP1_IN2 signal
//   <o>    ACMP1_IN2<name=ACMP1_IN2_PIN_SEL>
//   <i>    Shows which pin ACMP1_IN2 is mapped to
//   <info>  [PTB4]
//     <0=> Disabled
//     <1=> PTB4<selection=PTB4_SIG_SEL,ACMP1_IN2>
//     <0=> Default
#define ACMP1_IN2_PIN_SEL    0

// Pin Mapping for ACMP1_OUT signal
//   <o>    ACMP1_OUT<name=ACMP1_OUT_PIN_SEL>
//   <i>    Shows which pin ACMP1_OUT is mapped to
//   <info>  [PTB5]
//     <0=> Disabled
//     <1=> PTB5<selection=PTB5_SIG_SEL,ACMP1_OUT>
//     <0=> Default
#define ACMP1_OUT_PIN_SEL    0

// </h>

// <h> Analogue to Digital (ADC0)

// Pin Mapping for ADC0_SE0 signal
//   <o>    ADC0_SE0<name=ADC0_SE0_PIN_SEL>
//   <i>    Shows which pin ADC0_SE0 is mapped to
//   <info>  [PTA0]
//     <0=> Disabled
//     <1=> PTA0 (reset default)<selection=PTA0_SIG_SEL,ADC0_SE0 (reset default)>
//     <2=> PTA0<selection=PTA0_SIG_SEL,ADC0_SE0>
//     <1=> Default
#define ADC0_SE0_PIN_SEL     1

// Pin Mapping for ADC0_SE1 signal
//   <o>    ADC0_SE1<name=ADC0_SE1_PIN_SEL>
//   <i>    Shows which pin ADC0_SE1 is mapped to
//   <info>  [PTA1]
//     <0=> Disabled
//     <1=> PTA1 (reset default)<selection=PTA1_SIG_SEL,ADC0_SE1 (reset default)>
//     <2=> PTA1<selection=PTA1_SIG_SEL,ADC0_SE1>
//     <1=> Default
#define ADC0_SE1_PIN_SEL     1

// Pin Mapping for ADC0_SE2 signal
//   <o>    ADC0_SE2<name=ADC0_SE2_PIN_SEL>
//   <i>    Shows which pin ADC0_SE2 is mapped to
//   <info>  [PTA6]
//     <0=> Disabled
//     <1=> PTA6 (reset default)<selection=PTA6_SIG_SEL,ADC0_SE2 (reset default)>
//     <2=> PTA6<selection=PTA6_SIG_SEL,ADC0_SE2>
//     <1=> Default
#define ADC0_SE2_PIN_SEL     1

// Pin Mapping for ADC0_SE3 signal
//   <o>    ADC0_SE3<name=ADC0_SE3_PIN_SEL>
//   <i>    Shows which pin ADC0_SE3 is mapped to
//   <info>  [PTA7]
//     <0=> Disabled
//     <1=> PTA7 (reset default)<selection=PTA7_SIG_SEL,ADC0_SE3 (reset default)>
//     <2=> PTA7<selection=PTA7_SIG_SEL,ADC0_SE3>
//     <1=> Default
#define ADC0_SE3_PIN_SEL     1

// Pin Mapping for ADC0_SE4 signal
//   <o>    ADC0_SE4<name=ADC0_SE4_PIN_SEL>
//   <i>    Shows which pin ADC0_SE4 is mapped to
//   <info>  [PTB0]
//     <0=> Disabled
//     <1=> PTB0 (reset default)<selection=PTB0_SIG_SEL,ADC0_SE4 (reset default)>
//     <2=> PTB0<selection=PTB0_SIG_SEL,ADC0_SE4>
//     <1=> Default
#define ADC0_SE4_PIN_SEL     1

// Pin Mapping for ADC0_SE5 signal
//   <o>    ADC0_SE5<name=ADC0_SE5_PIN_SEL>
//   <i>    Shows which pin ADC0_SE5 is mapped to
//   <info>  [PTB1]
//     <0=> Disabled
//     <1=> PTB1 (reset default)<selection=PTB1_SIG_SEL,ADC0_SE5 (reset default)>
//     <2=> PTB1<selection=PTB1_SIG_SEL,ADC0_SE5>
//     <1=> Default
#define ADC0_SE5_PIN_SEL     1

// Pin Mapping for ADC0_SE6 signal
//   <o>    ADC0_SE6<name=ADC0_SE6_PIN_SEL>
//   <i>    Shows which pin ADC0_SE6 is mapped to
//   <info>  [PTB2]
//     <0=> Disabled
//     <1=> PTB2 (reset default)<selection=PTB2_SIG_SEL,ADC0_SE6 (reset default)>
//     <2=> PTB2<selection=PTB2_SIG_SEL,ADC0_SE6>
//     <1=> Default
#define ADC0_SE6_PIN_SEL     1

// Pin Mapping for ADC0_SE7 signal
//   <o>    ADC0_SE7<name=ADC0_SE7_PIN_SEL>
//   <i>    Shows which pin ADC0_SE7 is mapped to
//   <info>  [PTB3]
//     <0=> Disabled
//     <1=> PTB3 (reset default)<selection=PTB3_SIG_SEL,ADC0_SE7 (reset default)>
//     <2=> PTB3<selection=PTB3_SIG_SEL,ADC0_SE7>
//     <1=> Default
#define ADC0_SE7_PIN_SEL     1

// Pin Mapping for ADC0_SE8 signal
//   <o>    ADC0_SE8<name=ADC0_SE8_PIN_SEL>
//   <i>    Shows which pin ADC0_SE8 is mapped to
//   <info>  [PTC0]
//     <0=> Disabled
//     <1=> PTC0 (reset default)<selection=PTC0_SIG_SEL,ADC0_SE8 (reset default)>
//     <2=> PTC0<selection=PTC0_SIG_SEL,ADC0_SE8>
//     <1=> Default
#define ADC0_SE8_PIN_SEL     1

// Pin Mapping for ADC0_SE9 signal
//   <o>    ADC0_SE9<name=ADC0_SE9_PIN_SEL>
//   <i>    Shows which pin ADC0_SE9 is mapped to
//   <info>  [PTC1]
//     <0=> Disabled
//     <1=> PTC1 (reset default)<selection=PTC1_SIG_SEL,ADC0_SE9 (reset default)>
//     <2=> PTC1<selection=PTC1_SIG_SEL,ADC0_SE9>
//     <1=> Default
#define ADC0_SE9_PIN_SEL     1

// Pin Mapping for ADC0_SE10 signal
//   <o>    ADC0_SE10<name=ADC0_SE10_PIN_SEL>
//   <i>    Shows which pin ADC0_SE10 is mapped to
//   <info>  [PTC2]
//     <0=> Disabled
//     <1=> PTC2 (reset default)<selection=PTC2_SIG_SEL,ADC0_SE10 (reset default)>
//     <2=> PTC2<selection=PTC2_SIG_SEL,ADC0_SE10>
//     <1=> Default
#define ADC0_SE10_PIN_SEL    1

// Pin Mapping for ADC0_SE11 signal
//   <o>    ADC0_SE11<name=ADC0_SE11_PIN_SEL>
//   <i>    Shows which pin ADC0_SE11 is mapped to
//   <info>  [PTC3]
//     <0=> Disabled
//     <1=> PTC3 (reset default)<selection=PTC3_SIG_SEL,ADC0_SE11 (reset default)>
//     <2=> PTC3<selection=PTC3_SIG_SEL,ADC0_SE11>
//     <1=> Default
#define ADC0_SE11_PIN_SEL    1

// Pin Mapping for ADC0_SE12 signal
//   <o>    ADC0_SE12<name=ADC0_SE12_PIN_SEL>
//   <i>    Shows which pin ADC0_SE12 is mapped to
//   <info>  [PTF4]
//     <0=> Disabled
//     <1=> PTF4 (reset default)<selection=PTF4_SIG_SEL,ADC0_SE12 (reset default)>
//     <2=> PTF4<selection=PTF4_SIG_SEL,ADC0_SE12>
//     <1=> Default
#define ADC0_SE12_PIN_SEL    1

// Pin Mapping for ADC0_SE13 signal
//   <o>    ADC0_SE13<name=ADC0_SE13_PIN_SEL>
//   <i>    Shows which pin ADC0_SE13 is mapped to
//   <info>  [PTF5]
//     <0=> Disabled
//     <1=> PTF5 (reset default)<selection=PTF5_SIG_SEL,ADC0_SE13 (reset default)>
//     <2=> PTF5<selection=PTF5_SIG_SEL,ADC0_SE13>
//     <1=> Default
#define ADC0_SE13_PIN_SEL    1

// Pin Mapping for ADC0_SE14 signal
//   <o>    ADC0_SE14<name=ADC0_SE14_PIN_SEL>
//   <i>    Shows which pin ADC0_SE14 is mapped to
//   <info>  [PTF6]
//     <0=> Disabled
//     <1=> PTF6 (reset default)<selection=PTF6_SIG_SEL,ADC0_SE14 (reset default)>
//     <2=> PTF6<selection=PTF6_SIG_SEL,ADC0_SE14>
//     <1=> Default
#define ADC0_SE14_PIN_SEL    1

// Pin Mapping for ADC0_SE15 signal
//   <o>    ADC0_SE15<name=ADC0_SE15_PIN_SEL>
//   <i>    Shows which pin ADC0_SE15 is mapped to
//   <info>  [PTF7]
//     <0=> Disabled
//     <1=> PTF7 (reset default)<selection=PTF7_SIG_SEL,ADC0_SE15 (reset default)>
//     <2=> PTF7<selection=PTF7_SIG_SEL,ADC0_SE15>
//     <1=> Default
#define ADC0_SE15_PIN_SEL    1

// </h>

// <h> CAN Bus (CAN0)

// Pin Mapping for CAN0_RX signal
//   <o>    CAN0_RX<name=CAN0_RX_PIN_SEL>
//   <i>    Shows which pin CAN0_RX is mapped to
//   <info>  [PTC6, PTH2]
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,CAN0_RX>
//     <2=> PTH2<selection=PTH2_SIG_SEL,CAN0_RX>
//     <0=> Default
#define CAN0_RX_PIN_SEL      0

// Pin Mapping for CAN0_TX signal
//   <o>    CAN0_TX<name=CAN0_TX_PIN_SEL>
//   <i>    Shows which pin CAN0_TX is mapped to
//   <info>  [PTC7, PTE7]
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,CAN0_TX>
//     <2=> PTE7<selection=PTE7_SIG_SEL,CAN0_TX>
//     <0=> Default
#define CAN0_TX_PIN_SEL      0

// </h>

// <h> Clock and Timing

// Pin Mapping for EXTAL signal
//   <o>    EXTAL<name=EXTAL_PIN_SEL>
//   <i>    Shows which pin EXTAL is mapped to
//   <info>  [PTB7]
//     <0=> Disabled
//     <1=> PTB7 (reset default)<selection=PTB7_SIG_SEL,EXTAL (reset default)>
//     <2=> PTB7<selection=PTB7_SIG_SEL,EXTAL>
//     <1=> Default
#define EXTAL_PIN_SEL        1

// Pin Mapping for RTC_CLKOUT signal
//   <o>    RTC_CLKOUT<name=RTC_CLKOUT_PIN_SEL>
//   <i>    Shows which pin RTC_CLKOUT is mapped to
//   <info>  [PTC4, PTC5]
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,RTC_CLKOUT>
//     <2=> PTC5<selection=PTC5_SIG_SEL,RTC_CLKOUT>
//     <0=> Default
#define RTC_CLKOUT_PIN_SEL   0

// Pin Mapping for TCLK0 signal
//   <o>    TCLK0<name=TCLK0_PIN_SEL>
//   <i>    Shows which pin TCLK0 is mapped to
//   <info>  [PTA5]
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,TCLK0>
//     <0=> Default
#define TCLK0_PIN_SEL        0

// Pin Mapping for TCLK1 signal
//   <o>    TCLK1<name=TCLK1_PIN_SEL>
//   <i>    Shows which pin TCLK1 is mapped to
//   <info>  [PTE0]
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,TCLK1>
//     <0=> Default
#define TCLK1_PIN_SEL        0

// Pin Mapping for TCLK2 signal
//   <o>    TCLK2<name=TCLK2_PIN_SEL>
//   <i>    Shows which pin TCLK2 is mapped to
//   <info>  [PTE7]
//     <0=> Disabled
//     <1=> PTE7<selection=PTE7_SIG_SEL,TCLK2>
//     <0=> Default
#define TCLK2_PIN_SEL        0

// Pin Mapping for XTAL signal
//   <o>    XTAL<name=XTAL_PIN_SEL>
//   <i>    Shows which pin XTAL is mapped to
//   <info>  [PTB6]
//     <0=> Disabled
//     <1=> PTB6 (reset default)<selection=PTB6_SIG_SEL,XTAL (reset default)>
//     <2=> PTB6<selection=PTB6_SIG_SEL,XTAL>
//     <1=> Default
#define XTAL_PIN_SEL         1

// </h>

// <h> FlexTimer (FTM0)

// Pin Mapping for FTM0_CH0 signal
//   <o>    FTM0_CH0<name=FTM0_CH0_PIN_SEL>
//   <i>    Shows which pin FTM0_CH0 is mapped to
//   <info>  [PTA0, PTB2]
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,FTM0_CH0>
//     <2=> PTB2<selection=PTB2_SIG_SEL,FTM0_CH0>
//     <0=> Default
#define FTM0_CH0_PIN_SEL     0

// Pin Mapping for FTM0_CH1 signal
//   <o>    FTM0_CH1<name=FTM0_CH1_PIN_SEL>
//   <i>    Shows which pin FTM0_CH1 is mapped to
//   <info>  [PTA1, PTB3]
//     <0=> Disabled
//     <1=> PTA1<selection=PTA1_SIG_SEL,FTM0_CH1>
//     <2=> PTB3<selection=PTB3_SIG_SEL,FTM0_CH1>
//     <0=> Default
#define FTM0_CH1_PIN_SEL     0

// </h>

// <h> FlexTimer (FTM1)

// Pin Mapping for FTM1_CH0 signal
//   <o>    FTM1_CH0<name=FTM1_CH0_PIN_SEL>
//   <i>    Shows which pin FTM1_CH0 is mapped to
//   <info>  [PTC4, PTH2]
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,FTM1_CH0>
//     <2=> PTH2<selection=PTH2_SIG_SEL,FTM1_CH0>
//     <0=> Default
#define FTM1_CH0_PIN_SEL     0

// Pin Mapping for FTM1_CH1 signal
//   <o>    FTM1_CH1<name=FTM1_CH1_PIN_SEL>
//   <i>    Shows which pin FTM1_CH1 is mapped to
//   <info>  [PTC5, PTE7]
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,FTM1_CH1>
//     <2=> PTE7<selection=PTE7_SIG_SEL,FTM1_CH1>
//     <0=> Default
#define FTM1_CH1_PIN_SEL     0

// </h>

// <h> FlexTimer (FTM2)

// Pin Mapping for FTM2_CH0 signal
//   <o>    FTM2_CH0<name=FTM2_CH0_PIN_SEL>
//   <i>    Shows which pin FTM2_CH0 is mapped to
//   <info>  [PTC0, PTF0, PTH0]
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,FTM2_CH0>
//     <2=> PTF0<selection=PTF0_SIG_SEL,FTM2_CH0>
//     <3=> PTH0<selection=PTH0_SIG_SEL,FTM2_CH0>
//     <0=> Default
#define FTM2_CH0_PIN_SEL     0

// Pin Mapping for FTM2_CH1 signal
//   <o>    FTM2_CH1<name=FTM2_CH1_PIN_SEL>
//   <i>    Shows which pin FTM2_CH1 is mapped to
//   <info>  [PTC1, PTF1, PTH1]
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,FTM2_CH1>
//     <2=> PTF1<selection=PTF1_SIG_SEL,FTM2_CH1>
//     <3=> PTH1<selection=PTH1_SIG_SEL,FTM2_CH1>
//     <0=> Default
#define FTM2_CH1_PIN_SEL     0

// Pin Mapping for FTM2_CH2 signal
//   <o>    FTM2_CH2<name=FTM2_CH2_PIN_SEL>
//   <i>    Shows which pin FTM2_CH2 is mapped to
//   <info>  [PTC2, PTD0, PTG4]
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,FTM2_CH2>
//     <2=> PTD0<selection=PTD0_SIG_SEL,FTM2_CH2>
//     <3=> PTG4<selection=PTG4_SIG_SEL,FTM2_CH2>
//     <0=> Default
#define FTM2_CH2_PIN_SEL     0

// Pin Mapping for FTM2_CH3 signal
//   <o>    FTM2_CH3<name=FTM2_CH3_PIN_SEL>
//   <i>    Shows which pin FTM2_CH3 is mapped to
//   <info>  [PTC3, PTD1, PTG5]
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,FTM2_CH3>
//     <2=> PTD1<selection=PTD1_SIG_SEL,FTM2_CH3>
//     <3=> PTG5 (Alias:LED_RED)<selection=PTG5_SIG_SEL,FTM2_CH3>
//     <0=> Default
#define FTM2_CH3_PIN_SEL     0

// Pin Mapping for FTM2_CH4 signal
//   <o>    FTM2_CH4<name=FTM2_CH4_PIN_SEL>
//   <i>    Shows which pin FTM2_CH4 is mapped to
//   <info>  [PTB4, PTG6]
//     <0=> Disabled
//     <1=> PTB4<selection=PTB4_SIG_SEL,FTM2_CH4>
//     <2=> PTG6 (Alias:LED_GREEN)<selection=PTG6_SIG_SEL,FTM2_CH4>
//     <0=> Default
#define FTM2_CH4_PIN_SEL     0

// Pin Mapping for FTM2_CH5 signal
//   <o>    FTM2_CH5<name=FTM2_CH5_PIN_SEL>
//   <i>    Shows which pin FTM2_CH5 is mapped to
//   <info>  [PTB5, PTG7]
//     <0=> Disabled
//     <1=> PTB5<selection=PTB5_SIG_SEL,FTM2_CH5>
//     <2=> PTG7 (Alias:LED_BLUE)<selection=PTG7_SIG_SEL,FTM2_CH5>
//     <0=> Default
#define FTM2_CH5_PIN_SEL     0

// Pin Mapping for FTM2_FLT1 signal
//   <o>    FTM2_FLT1<name=FTM2_FLT1_PIN_SEL>
//   <i>    Shows which pin FTM2_FLT1 is mapped to
//   <info>  [PTA6]
//     <0=> Disabled
//     <1=> PTA6<selection=PTA6_SIG_SEL,FTM2_FLT1>
//     <0=> Default
#define FTM2_FLT1_PIN_SEL    0

// Pin Mapping for FTM2_FLT2 signal
//   <o>    FTM2_FLT2<name=FTM2_FLT2_PIN_SEL>
//   <i>    Shows which pin FTM2_FLT2 is mapped to
//   <info>  [PTA7]
//     <0=> Disabled
//     <1=> PTA7<selection=PTA7_SIG_SEL,FTM2_FLT2>
//     <0=> Default
#define FTM2_FLT2_PIN_SEL    0

// </h>

// <h> General Purpose I/O (GPIOA)

// Pin Mapping for GPIOA_0 signal
//   <o>    GPIOA_0<name=GPIOA_0_PIN_SEL>
//   <i>    Shows which pin GPIOA_0 is mapped to
//   <info>  [PTA0]
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,GPIOA_0>
//     <0=> Default
#define GPIOA_0_PIN_SEL      0

// Pin Mapping for GPIOA_1 signal
//   <o>    GPIOA_1<name=GPIOA_1_PIN_SEL>
//   <i>    Shows which pin GPIOA_1 is mapped to
//   <info>  [PTA1]
//     <0=> Disabled
//     <1=> PTA1<selection=PTA1_SIG_SEL,GPIOA_1>
//     <0=> Default
#define GPIOA_1_PIN_SEL      0

// Pin Mapping for GPIOA_2 signal
//   <o>    GPIOA_2<name=GPIOA_2_PIN_SEL>
//   <i>    Shows which pin GPIOA_2 is mapped to
//   <info>  [PTA2]
//     <0=> Disabled
//     <1=> PTA2<selection=PTA2_SIG_SEL,GPIOA_2>
//     <0=> Default
#define GPIOA_2_PIN_SEL      0

// Pin Mapping for GPIOA_3 signal
//   <o>    GPIOA_3<name=GPIOA_3_PIN_SEL>
//   <i>    Shows which pin GPIOA_3 is mapped to
//   <info>  [PTA3]
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,GPIOA_3>
//     <0=> Default
#define GPIOA_3_PIN_SEL      0

// Pin Mapping for GPIOA_4 signal
//   <o>    GPIOA_4<name=GPIOA_4_PIN_SEL>
//   <i>    Shows which pin GPIOA_4 is mapped to
//   <info>  [PTA4]
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,GPIOA_4>
//     <0=> Default
#define GPIOA_4_PIN_SEL      0

// Pin Mapping for GPIOA_5 signal
//   <o>    GPIOA_5<name=GPIOA_5_PIN_SEL>
//   <i>    Shows which pin GPIOA_5 is mapped to
//   <info>  [PTA5]
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,GPIOA_5>
//     <0=> Default
#define GPIOA_5_PIN_SEL      0

// Pin Mapping for GPIOA_6 signal
//   <o>    GPIOA_6<name=GPIOA_6_PIN_SEL>
//   <i>    Shows which pin GPIOA_6 is mapped to
//   <info>  [PTA6]
//     <0=> Disabled
//     <1=> PTA6<selection=PTA6_SIG_SEL,GPIOA_6>
//     <0=> Default
#define GPIOA_6_PIN_SEL      0

// Pin Mapping for GPIOA_7 signal
//   <o>    GPIOA_7<name=GPIOA_7_PIN_SEL>
//   <i>    Shows which pin GPIOA_7 is mapped to
//   <info>  [PTA7]
//     <0=> Disabled
//     <1=> PTA7<selection=PTA7_SIG_SEL,GPIOA_7>
//     <0=> Default
#define GPIOA_7_PIN_SEL      0

// Pin Mapping for GPIOA_8 signal
//   <o>    GPIOA_8<name=GPIOA_8_PIN_SEL>
//   <i>    Shows which pin GPIOA_8 is mapped to
//   <info>  [PTB0]
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,GPIOA_8>
//     <0=> Default
#define GPIOA_8_PIN_SEL      0

// Pin Mapping for GPIOA_9 signal
//   <o>    GPIOA_9<name=GPIOA_9_PIN_SEL>
//   <i>    Shows which pin GPIOA_9 is mapped to
//   <info>  [PTB1]
//     <0=> Disabled
//     <1=> PTB1<selection=PTB1_SIG_SEL,GPIOA_9>
//     <0=> Default
#define GPIOA_9_PIN_SEL      0

// Pin Mapping for GPIOA_10 signal
//   <o>    GPIOA_10<name=GPIOA_10_PIN_SEL>
//   <i>    Shows which pin GPIOA_10 is mapped to
//   <info>  [PTB2]
//     <0=> Disabled
//     <1=> PTB2<selection=PTB2_SIG_SEL,GPIOA_10>
//     <0=> Default
#define GPIOA_10_PIN_SEL     0

// Pin Mapping for GPIOA_11 signal
//   <o>    GPIOA_11<name=GPIOA_11_PIN_SEL>
//   <i>    Shows which pin GPIOA_11 is mapped to
//   <info>  [PTB3]
//     <0=> Disabled
//     <1=> PTB3<selection=PTB3_SIG_SEL,GPIOA_11>
//     <0=> Default
#define GPIOA_11_PIN_SEL     0

// Pin Mapping for GPIOA_12 signal
//   <o>    GPIOA_12<name=GPIOA_12_PIN_SEL>
//   <i>    Shows which pin GPIOA_12 is mapped to
//   <info>  [PTB4]
//     <0=> Disabled
//     <1=> PTB4<selection=PTB4_SIG_SEL,GPIOA_12>
//     <0=> Default
#define GPIOA_12_PIN_SEL     0

// Pin Mapping for GPIOA_13 signal
//   <o>    GPIOA_13<name=GPIOA_13_PIN_SEL>
//   <i>    Shows which pin GPIOA_13 is mapped to
//   <info>  [PTB5]
//     <0=> Disabled
//     <1=> PTB5<selection=PTB5_SIG_SEL,GPIOA_13>
//     <0=> Default
#define GPIOA_13_PIN_SEL     0

// Pin Mapping for GPIOA_14 signal
//   <o>    GPIOA_14<name=GPIOA_14_PIN_SEL>
//   <i>    Shows which pin GPIOA_14 is mapped to
//   <info>  [PTB6]
//     <0=> Disabled
//     <1=> PTB6<selection=PTB6_SIG_SEL,GPIOA_14>
//     <0=> Default
#define GPIOA_14_PIN_SEL     0

// Pin Mapping for GPIOA_15 signal
//   <o>    GPIOA_15<name=GPIOA_15_PIN_SEL>
//   <i>    Shows which pin GPIOA_15 is mapped to
//   <info>  [PTB7]
//     <0=> Disabled
//     <1=> PTB7<selection=PTB7_SIG_SEL,GPIOA_15>
//     <0=> Default
#define GPIOA_15_PIN_SEL     0

// Pin Mapping for GPIOA_16 signal
//   <o>    GPIOA_16<name=GPIOA_16_PIN_SEL>
//   <i>    Shows which pin GPIOA_16 is mapped to
//   <info>  [PTC0]
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,GPIOA_16>
//     <0=> Default
#define GPIOA_16_PIN_SEL     0

// Pin Mapping for GPIOA_17 signal
//   <o>    GPIOA_17<name=GPIOA_17_PIN_SEL>
//   <i>    Shows which pin GPIOA_17 is mapped to
//   <info>  [PTC1]
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,GPIOA_17>
//     <0=> Default
#define GPIOA_17_PIN_SEL     0

// Pin Mapping for GPIOA_18 signal
//   <o>    GPIOA_18<name=GPIOA_18_PIN_SEL>
//   <i>    Shows which pin GPIOA_18 is mapped to
//   <info>  [PTC2]
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,GPIOA_18>
//     <0=> Default
#define GPIOA_18_PIN_SEL     0

// Pin Mapping for GPIOA_19 signal
//   <o>    GPIOA_19<name=GPIOA_19_PIN_SEL>
//   <i>    Shows which pin GPIOA_19 is mapped to
//   <info>  [PTC3]
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,GPIOA_19>
//     <0=> Default
#define GPIOA_19_PIN_SEL     0

// Pin Mapping for GPIOA_20 signal
//   <o>    GPIOA_20<name=GPIOA_20_PIN_SEL>
//   <i>    Shows which pin GPIOA_20 is mapped to
//   <info>  [PTC4]
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,GPIOA_20>
//     <0=> Default
#define GPIOA_20_PIN_SEL     0

// Pin Mapping for GPIOA_21 signal
//   <o>    GPIOA_21<name=GPIOA_21_PIN_SEL>
//   <i>    Shows which pin GPIOA_21 is mapped to
//   <info>  [PTC5]
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,GPIOA_21>
//     <0=> Default
#define GPIOA_21_PIN_SEL     0

// Pin Mapping for GPIOA_22 signal
//   <o>    GPIOA_22<name=GPIOA_22_PIN_SEL>
//   <i>    Shows which pin GPIOA_22 is mapped to
//   <info>  [PTC6]
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,GPIOA_22>
//     <0=> Default
#define GPIOA_22_PIN_SEL     0

// Pin Mapping for GPIOA_23 signal
//   <o>    GPIOA_23<name=GPIOA_23_PIN_SEL>
//   <i>    Shows which pin GPIOA_23 is mapped to
//   <info>  [PTC7]
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,GPIOA_23>
//     <0=> Default
#define GPIOA_23_PIN_SEL     0

// Pin Mapping for GPIOA_24 signal
//   <o>    GPIOA_24<name=GPIOA_24_PIN_SEL>
//   <i>    Shows which pin GPIOA_24 is mapped to
//   <info>  [PTD0]
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,GPIOA_24>
//     <0=> Default
#define GPIOA_24_PIN_SEL     0

// Pin Mapping for GPIOA_25 signal
//   <o>    GPIOA_25<name=GPIOA_25_PIN_SEL>
//   <i>    Shows which pin GPIOA_25 is mapped to
//   <info>  [PTD1]
//     <0=> Disabled
//     <1=> PTD1<selection=PTD1_SIG_SEL,GPIOA_25>
//     <0=> Default
#define GPIOA_25_PIN_SEL     0

// Pin Mapping for GPIOA_26 signal
//   <o>    GPIOA_26<name=GPIOA_26_PIN_SEL>
//   <i>    Shows which pin GPIOA_26 is mapped to
//   <info>  [PTD2]
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,GPIOA_26>
//     <0=> Default
#define GPIOA_26_PIN_SEL     0

// Pin Mapping for GPIOA_27 signal
//   <o>    GPIOA_27<name=GPIOA_27_PIN_SEL>
//   <i>    Shows which pin GPIOA_27 is mapped to
//   <info>  [PTD3]
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,GPIOA_27>
//     <0=> Default
#define GPIOA_27_PIN_SEL     0

// Pin Mapping for GPIOA_28 signal
//   <o>    GPIOA_28<name=GPIOA_28_PIN_SEL>
//   <i>    Shows which pin GPIOA_28 is mapped to
//   <info>  [PTD4]
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,GPIOA_28>
//     <0=> Default
#define GPIOA_28_PIN_SEL     0

// Pin Mapping for GPIOA_29 signal
//   <o>    GPIOA_29<name=GPIOA_29_PIN_SEL>
//   <i>    Shows which pin GPIOA_29 is mapped to
//   <info>  [PTD5]
//     <0=> Disabled
//     <1=> PTD5<selection=PTD5_SIG_SEL,GPIOA_29>
//     <0=> Default
#define GPIOA_29_PIN_SEL     0

// Pin Mapping for GPIOA_30 signal
//   <o>    GPIOA_30<name=GPIOA_30_PIN_SEL>
//   <i>    Shows which pin GPIOA_30 is mapped to
//   <info>  [PTD6]
//     <0=> Disabled
//     <1=> PTD6<selection=PTD6_SIG_SEL,GPIOA_30>
//     <0=> Default
#define GPIOA_30_PIN_SEL     0

// Pin Mapping for GPIOA_31 signal
//   <o>    GPIOA_31<name=GPIOA_31_PIN_SEL>
//   <i>    Shows which pin GPIOA_31 is mapped to
//   <info>  [PTD7]
//     <0=> Disabled
//     <1=> PTD7<selection=PTD7_SIG_SEL,GPIOA_31>
//     <0=> Default
#define GPIOA_31_PIN_SEL     0

// </h>

// <h> General Purpose I/O (GPIOB)

// Pin Mapping for GPIOB_0 signal
//   <o>    GPIOB_0<name=GPIOB_0_PIN_SEL>
//   <i>    Shows which pin GPIOB_0 is mapped to
//   <info>  [PTE0]
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,GPIOB_0>
//     <0=> Default
#define GPIOB_0_PIN_SEL      0

// Pin Mapping for GPIOB_1 signal
//   <o>    GPIOB_1<name=GPIOB_1_PIN_SEL>
//   <i>    Shows which pin GPIOB_1 is mapped to
//   <info>  [PTE1]
//     <0=> Disabled
//     <1=> PTE1<selection=PTE1_SIG_SEL,GPIOB_1>
//     <0=> Default
#define GPIOB_1_PIN_SEL      0

// Pin Mapping for GPIOB_2 signal
//   <o>    GPIOB_2<name=GPIOB_2_PIN_SEL>
//   <i>    Shows which pin GPIOB_2 is mapped to
//   <info>  [PTE2]
//     <0=> Disabled
//     <1=> PTE2<selection=PTE2_SIG_SEL,GPIOB_2>
//     <0=> Default
#define GPIOB_2_PIN_SEL      0

// Pin Mapping for GPIOB_3 signal
//   <o>    GPIOB_3<name=GPIOB_3_PIN_SEL>
//   <i>    Shows which pin GPIOB_3 is mapped to
//   <info>  [PTE3]
//     <0=> Disabled
//     <1=> PTE3<selection=PTE3_SIG_SEL,GPIOB_3>
//     <0=> Default
#define GPIOB_3_PIN_SEL      0

// Pin Mapping for GPIOB_4 signal
//   <o>    GPIOB_4<name=GPIOB_4_PIN_SEL>
//   <i>    Shows which pin GPIOB_4 is mapped to
//   <info>  [PTE4]
//     <0=> Disabled
//     <1=> PTE4<selection=PTE4_SIG_SEL,GPIOB_4>
//     <0=> Default
#define GPIOB_4_PIN_SEL      0

// Pin Mapping for GPIOB_5 signal
//   <o>    GPIOB_5<name=GPIOB_5_PIN_SEL>
//   <i>    Shows which pin GPIOB_5 is mapped to
//   <info>  [PTE5]
//     <0=> Disabled
//     <1=> PTE5<selection=PTE5_SIG_SEL,GPIOB_5>
//     <0=> Default
#define GPIOB_5_PIN_SEL      0

// Pin Mapping for GPIOB_6 signal
//   <o>    GPIOB_6<name=GPIOB_6_PIN_SEL>
//   <i>    Shows which pin GPIOB_6 is mapped to
//   <info>  [PTE6]
//     <0=> Disabled
//     <1=> PTE6<selection=PTE6_SIG_SEL,GPIOB_6>
//     <0=> Default
#define GPIOB_6_PIN_SEL      0

// Pin Mapping for GPIOB_7 signal
//   <o>    GPIOB_7<name=GPIOB_7_PIN_SEL>
//   <i>    Shows which pin GPIOB_7 is mapped to
//   <info>  [PTE7]
//     <0=> Disabled
//     <1=> PTE7<selection=PTE7_SIG_SEL,GPIOB_7>
//     <0=> Default
#define GPIOB_7_PIN_SEL      0

// Pin Mapping for GPIOB_8 signal
//   <o>    GPIOB_8<name=GPIOB_8_PIN_SEL>
//   <i>    Shows which pin GPIOB_8 is mapped to
//   <info>  [PTF0]
//     <0=> Disabled
//     <1=> PTF0<selection=PTF0_SIG_SEL,GPIOB_8>
//     <0=> Default
#define GPIOB_8_PIN_SEL      0

// Pin Mapping for GPIOB_9 signal
//   <o>    GPIOB_9<name=GPIOB_9_PIN_SEL>
//   <i>    Shows which pin GPIOB_9 is mapped to
//   <info>  [PTF1]
//     <0=> Disabled
//     <1=> PTF1<selection=PTF1_SIG_SEL,GPIOB_9>
//     <0=> Default
#define GPIOB_9_PIN_SEL      0

// Pin Mapping for GPIOB_10 signal
//   <o>    GPIOB_10<name=GPIOB_10_PIN_SEL>
//   <i>    Shows which pin GPIOB_10 is mapped to
//   <info>  [PTF2]
//     <0=> Disabled
//     <1=> PTF2<selection=PTF2_SIG_SEL,GPIOB_10>
//     <0=> Default
#define GPIOB_10_PIN_SEL     0

// Pin Mapping for GPIOB_11 signal
//   <o>    GPIOB_11<name=GPIOB_11_PIN_SEL>
//   <i>    Shows which pin GPIOB_11 is mapped to
//   <info>  [PTF3]
//     <0=> Disabled
//     <1=> PTF3<selection=PTF3_SIG_SEL,GPIOB_11>
//     <0=> Default
#define GPIOB_11_PIN_SEL     0

// Pin Mapping for GPIOB_12 signal
//   <o>    GPIOB_12<name=GPIOB_12_PIN_SEL>
//   <i>    Shows which pin GPIOB_12 is mapped to
//   <info>  [PTF4]
//     <0=> Disabled
//     <1=> PTF4<selection=PTF4_SIG_SEL,GPIOB_12>
//     <0=> Default
#define GPIOB_12_PIN_SEL     0

// Pin Mapping for GPIOB_13 signal
//   <o>    GPIOB_13<name=GPIOB_13_PIN_SEL>
//   <i>    Shows which pin GPIOB_13 is mapped to
//   <info>  [PTF5]
//     <0=> Disabled
//     <1=> PTF5<selection=PTF5_SIG_SEL,GPIOB_13>
//     <0=> Default
#define GPIOB_13_PIN_SEL     0

// Pin Mapping for GPIOB_14 signal
//   <o>    GPIOB_14<name=GPIOB_14_PIN_SEL>
//   <i>    Shows which pin GPIOB_14 is mapped to
//   <info>  [PTF6]
//     <0=> Disabled
//     <1=> PTF6<selection=PTF6_SIG_SEL,GPIOB_14>
//     <0=> Default
#define GPIOB_14_PIN_SEL     0

// Pin Mapping for GPIOB_15 signal
//   <o>    GPIOB_15<name=GPIOB_15_PIN_SEL>
//   <i>    Shows which pin GPIOB_15 is mapped to
//   <info>  [PTF7]
//     <0=> Disabled
//     <1=> PTF7<selection=PTF7_SIG_SEL,GPIOB_15>
//     <0=> Default
#define GPIOB_15_PIN_SEL     0

// Pin Mapping for GPIOB_16 signal
//   <o>    GPIOB_16<name=GPIOB_16_PIN_SEL>
//   <i>    Shows which pin GPIOB_16 is mapped to
//   <info>  [PTG0]
//     <0=> Disabled
//     <1=> PTG0<selection=PTG0_SIG_SEL,GPIOB_16>
//     <0=> Default
#define GPIOB_16_PIN_SEL     0

// Pin Mapping for GPIOB_17 signal
//   <o>    GPIOB_17<name=GPIOB_17_PIN_SEL>
//   <i>    Shows which pin GPIOB_17 is mapped to
//   <info>  [PTG1]
//     <0=> Disabled
//     <1=> PTG1<selection=PTG1_SIG_SEL,GPIOB_17>
//     <0=> Default
#define GPIOB_17_PIN_SEL     0

// Pin Mapping for GPIOB_18 signal
//   <o>    GPIOB_18<name=GPIOB_18_PIN_SEL>
//   <i>    Shows which pin GPIOB_18 is mapped to
//   <info>  [PTG2]
//     <0=> Disabled
//     <1=> PTG2<selection=PTG2_SIG_SEL,GPIOB_18>
//     <0=> Default
#define GPIOB_18_PIN_SEL     0

// Pin Mapping for GPIOB_19 signal
//   <o>    GPIOB_19<name=GPIOB_19_PIN_SEL>
//   <i>    Shows which pin GPIOB_19 is mapped to
//   <info>  [PTG3]
//     <0=> Disabled
//     <1=> PTG3<selection=PTG3_SIG_SEL,GPIOB_19>
//     <0=> Default
#define GPIOB_19_PIN_SEL     0

// Pin Mapping for GPIOB_20 signal
//   <o>    GPIOB_20<name=GPIOB_20_PIN_SEL>
//   <i>    Shows which pin GPIOB_20 is mapped to
//   <info>  [PTG4]
//     <0=> Disabled
//     <1=> PTG4<selection=PTG4_SIG_SEL,GPIOB_20>
//     <0=> Default
#define GPIOB_20_PIN_SEL     0

// Pin Mapping for GPIOB_21 signal
//   <o>    GPIOB_21<name=GPIOB_21_PIN_SEL>
//   <i>    Shows which pin GPIOB_21 is mapped to
//   <info>  [PTG5]
//     <0=> Disabled
//     <1=> PTG5 (Alias:LED_RED)<selection=PTG5_SIG_SEL,GPIOB_21>
//     <1=> Default
#define GPIOB_21_PIN_SEL     1

// Pin Mapping for GPIOB_22 signal
//   <o>    GPIOB_22<name=GPIOB_22_PIN_SEL>
//   <i>    Shows which pin GPIOB_22 is mapped to
//   <info>  [PTG6]
//     <0=> Disabled
//     <1=> PTG6 (Alias:LED_GREEN)<selection=PTG6_SIG_SEL,GPIOB_22>
//     <1=> Default
#define GPIOB_22_PIN_SEL     1

// Pin Mapping for GPIOB_23 signal
//   <o>    GPIOB_23<name=GPIOB_23_PIN_SEL>
//   <i>    Shows which pin GPIOB_23 is mapped to
//   <info>  [PTG7]
//     <0=> Disabled
//     <1=> PTG7 (Alias:LED_BLUE)<selection=PTG7_SIG_SEL,GPIOB_23>
//     <1=> Default
#define GPIOB_23_PIN_SEL     1

// Pin Mapping for GPIOB_24 signal
//   <o>    GPIOB_24<name=GPIOB_24_PIN_SEL>
//   <i>    Shows which pin GPIOB_24 is mapped to
//   <info>  [PTH0]
//     <0=> Disabled
//     <1=> PTH0<selection=PTH0_SIG_SEL,GPIOB_24>
//     <0=> Default
#define GPIOB_24_PIN_SEL     0

// Pin Mapping for GPIOB_25 signal
//   <o>    GPIOB_25<name=GPIOB_25_PIN_SEL>
//   <i>    Shows which pin GPIOB_25 is mapped to
//   <info>  [PTH1]
//     <0=> Disabled
//     <1=> PTH1<selection=PTH1_SIG_SEL,GPIOB_25>
//     <0=> Default
#define GPIOB_25_PIN_SEL     0

// Pin Mapping for GPIOB_26 signal
//   <o>    GPIOB_26<name=GPIOB_26_PIN_SEL>
//   <i>    Shows which pin GPIOB_26 is mapped to
//   <info>  [PTH2]
//     <0=> Disabled
//     <1=> PTH2<selection=PTH2_SIG_SEL,GPIOB_26>
//     <0=> Default
#define GPIOB_26_PIN_SEL     0

// Pin Mapping for GPIOB_27 signal
//   <o>    GPIOB_27<name=GPIOB_27_PIN_SEL>
//   <i>    Shows which pin GPIOB_27 is mapped to
//   <info>  [PTH3]
//     <0=> Disabled
//     <1=> PTH3<selection=PTH3_SIG_SEL,GPIOB_27>
//     <0=> Default
#define GPIOB_27_PIN_SEL     0

// Pin Mapping for GPIOB_28 signal
//   <o>    GPIOB_28<name=GPIOB_28_PIN_SEL>
//   <i>    Shows which pin GPIOB_28 is mapped to
//   <info>  [PTH4]
//     <0=> Disabled
//     <1=> PTH4<selection=PTH4_SIG_SEL,GPIOB_28>
//     <0=> Default
#define GPIOB_28_PIN_SEL     0

// Pin Mapping for GPIOB_29 signal
//   <o>    GPIOB_29<name=GPIOB_29_PIN_SEL>
//   <i>    Shows which pin GPIOB_29 is mapped to
//   <info>  [PTH5]
//     <0=> Disabled
//     <1=> PTH5<selection=PTH5_SIG_SEL,GPIOB_29>
//     <0=> Default
#define GPIOB_29_PIN_SEL     0

// Pin Mapping for GPIOB_30 signal
//   <o>    GPIOB_30<name=GPIOB_30_PIN_SEL>
//   <i>    Shows which pin GPIOB_30 is mapped to
//   <info>  [PTH6]
//     <0=> Disabled
//     <1=> PTH6<selection=PTH6_SIG_SEL,GPIOB_30>
//     <0=> Default
#define GPIOB_30_PIN_SEL     0

// Pin Mapping for GPIOB_31 signal
//   <o>    GPIOB_31<name=GPIOB_31_PIN_SEL>
//   <i>    Shows which pin GPIOB_31 is mapped to
//   <info>  [PTH7]
//     <0=> Disabled
//     <1=> PTH7<selection=PTH7_SIG_SEL,GPIOB_31>
//     <0=> Default
#define GPIOB_31_PIN_SEL     0

// </h>

// <h> General Purpose I/O (GPIOC)

// Pin Mapping for GPIOC_0 signal
//   <o>    GPIOC_0<name=GPIOC_0_PIN_SEL>
//   <i>    Shows which pin GPIOC_0 is mapped to
//   <info>  [PTI0]
//     <0=> Disabled
//     <1=> PTI0<selection=PTI0_SIG_SEL,GPIOC_0>
//     <0=> Default
#define GPIOC_0_PIN_SEL      0

// Pin Mapping for GPIOC_1 signal
//   <o>    GPIOC_1<name=GPIOC_1_PIN_SEL>
//   <i>    Shows which pin GPIOC_1 is mapped to
//   <info>  [PTI1]
//     <0=> Disabled
//     <1=> PTI1<selection=PTI1_SIG_SEL,GPIOC_1>
//     <0=> Default
#define GPIOC_1_PIN_SEL      0

// Pin Mapping for GPIOC_2 signal
//   <o>    GPIOC_2<name=GPIOC_2_PIN_SEL>
//   <i>    Shows which pin GPIOC_2 is mapped to
//   <info>  [PTI2]
//     <0=> Disabled
//     <1=> PTI2<selection=PTI2_SIG_SEL,GPIOC_2>
//     <0=> Default
#define GPIOC_2_PIN_SEL      0

// Pin Mapping for GPIOC_3 signal
//   <o>    GPIOC_3<name=GPIOC_3_PIN_SEL>
//   <i>    Shows which pin GPIOC_3 is mapped to
//   <info>  [PTI3]
//     <0=> Disabled
//     <1=> PTI3<selection=PTI3_SIG_SEL,GPIOC_3>
//     <0=> Default
#define GPIOC_3_PIN_SEL      0

// Pin Mapping for GPIOC_4 signal
//   <o>    GPIOC_4<name=GPIOC_4_PIN_SEL>
//   <i>    Shows which pin GPIOC_4 is mapped to
//   <info>  [PTI4]
//     <0=> Disabled
//     <1=> PTI4<selection=PTI4_SIG_SEL,GPIOC_4>
//     <0=> Default
#define GPIOC_4_PIN_SEL      0

// Pin Mapping for GPIOC_5 signal
//   <o>    GPIOC_5<name=GPIOC_5_PIN_SEL>
//   <i>    Shows which pin GPIOC_5 is mapped to
//   <info>  [PTI5]
//     <0=> Disabled
//     <1=> PTI5<selection=PTI5_SIG_SEL,GPIOC_5>
//     <0=> Default
#define GPIOC_5_PIN_SEL      0

// Pin Mapping for GPIOC_6 signal
//   <o>    GPIOC_6<name=GPIOC_6_PIN_SEL>
//   <i>    Shows which pin GPIOC_6 is mapped to
//   <info>  [PTI6]
//     <0=> Disabled
//     <1=> PTI6<selection=PTI6_SIG_SEL,GPIOC_6>
//     <0=> Default
#define GPIOC_6_PIN_SEL      0

// </h>

// <h> Inter-Integrated Circuit (I2C0)

// Pin Mapping for I2C0_SCL signal
//   <o>    I2C0_SCL<name=I2C0_SCL_PIN_SEL>
//   <i>    Shows which pin I2C0_SCL is mapped to
//   <info>  [PTB7, PTA3]
//     <0=> Disabled
//     <1=> PTB7<selection=PTB7_SIG_SEL,I2C0_SCL>
//     <2=> PTA3<selection=PTA3_SIG_SEL,I2C0_SCL>
//     <0=> Default
#define I2C0_SCL_PIN_SEL     0

// Pin Mapping for I2C0_4WSDAOUT signal
//   <o>    I2C0_4WSDAOUT<name=I2C0_4WSDAOUT_PIN_SEL>
//   <i>    Shows which pin I2C0_4WSDAOUT is mapped to
//   <info>  [PTA1]
//     <0=> Disabled
//     <1=> PTA1<selection=PTA1_SIG_SEL,I2C0_4WSDAOUT>
//     <0=> Default
#define I2C0_4WSDAOUT_PIN_SEL 0

// Pin Mapping for I2C0_SDA signal
//   <o>    I2C0_SDA<name=I2C0_SDA_PIN_SEL>
//   <i>    Shows which pin I2C0_SDA is mapped to
//   <info>  [PTB6, PTA2]
//     <0=> Disabled
//     <1=> PTB6<selection=PTB6_SIG_SEL,I2C0_SDA>
//     <2=> PTA2<selection=PTA2_SIG_SEL,I2C0_SDA>
//     <0=> Default
#define I2C0_SDA_PIN_SEL     0

// Pin Mapping for I2C0_4WSCLOUT signal
//   <o>    I2C0_4WSCLOUT<name=I2C0_4WSCLOUT_PIN_SEL>
//   <i>    Shows which pin I2C0_4WSCLOUT is mapped to
//   <info>  [PTA0]
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,I2C0_4WSCLOUT>
//     <0=> Default
#define I2C0_4WSCLOUT_PIN_SEL 0

// </h>

// <h> Inter-Integrated Circuit (I2C1)

// Pin Mapping for I2C1_SDA signal
//   <o>    I2C1_SDA<name=I2C1_SDA_PIN_SEL>
//   <i>    Shows which pin I2C1_SDA is mapped to
//   <info>  [PTH3, PTE0]
//     <0=> Disabled
//     <1=> PTH3<selection=PTH3_SIG_SEL,I2C1_SDA>
//     <2=> PTE0<selection=PTE0_SIG_SEL,I2C1_SDA>
//     <0=> Default
#define I2C1_SDA_PIN_SEL     0

// Pin Mapping for I2C1_SCL signal
//   <o>    I2C1_SCL<name=I2C1_SCL_PIN_SEL>
//   <i>    Shows which pin I2C1_SCL is mapped to
//   <info>  [PTH4, PTE1]
//     <0=> Disabled
//     <1=> PTH4<selection=PTH4_SIG_SEL,I2C1_SCL>
//     <2=> PTE1<selection=PTE1_SIG_SEL,I2C1_SCL>
//     <0=> Default
#define I2C1_SCL_PIN_SEL     0

// </h>

// <h> Debug and Control

// Pin Mapping for NMI_b signal
//   <o>    NMI_b<name=NMI_b_PIN_SEL>
//   <i>    Shows which pin NMI_b is mapped to
//   <info>  [PTB4]
//     <0=> Disabled
//     <1=> PTB4 (reset default)<selection=PTB4_SIG_SEL,NMI_b (reset default)>
//     <2=> PTB4<selection=PTB4_SIG_SEL,NMI_b>
//     <1=> Default
#define NMI_b_PIN_SEL        1

// Pin Mapping for RESET_b signal
//   <o>    RESET_b<name=RESET_b_PIN_SEL>
//   <i>    Shows which pin RESET_b is mapped to
//   <info>  [PTA5]
//     <0=> Disabled
//     <1=> PTA5 (reset default)<selection=PTA5_SIG_SEL,RESET_b (reset default)>
//     <2=> PTA5<selection=PTA5_SIG_SEL,RESET_b>
//     <1=> Default
#define RESET_b_PIN_SEL      1

// Pin Mapping for SWD_CLK signal
//   <o>    SWD_CLK<name=SWD_CLK_PIN_SEL>
//   <i>    Shows which pin SWD_CLK is mapped to
//   <info>  [PTC4]
//     <0=> Disabled
//     <1=> PTC4 (reset default)<selection=PTC4_SIG_SEL,SWD_CLK (reset default)>
//     <2=> PTC4<selection=PTC4_SIG_SEL,SWD_CLK>
//     <1=> Default
#define SWD_CLK_PIN_SEL      1

// Pin Mapping for SWD_DIO signal
//   <o>    SWD_DIO<name=SWD_DIO_PIN_SEL>
//   <i>    Shows which pin SWD_DIO is mapped to
//   <info>  [PTA4]
//     <0=> Disabled
//     <1=> PTA4 (reset default)<selection=PTA4_SIG_SEL,SWD_DIO (reset default)>
//     <2=> PTA4<selection=PTA4_SIG_SEL,SWD_DIO>
//     <1=> Default
#define SWD_DIO_PIN_SEL      1

// </h>

// <h> Serial Peripheral Interface (SPI0)

// Pin Mapping for SPI0_MISO signal
//   <o>    SPI0_MISO<name=SPI0_MISO_PIN_SEL>
//   <i>    Shows which pin SPI0_MISO is mapped to
//   <info>  [PTE2, PTB4]
//     <0=> Disabled
//     <1=> PTE2<selection=PTE2_SIG_SEL,SPI0_MISO>
//     <2=> PTB4<selection=PTB4_SIG_SEL,SPI0_MISO>
//     <0=> Default
#define SPI0_MISO_PIN_SEL    0

// Pin Mapping for SPI0_MOSI signal
//   <o>    SPI0_MOSI<name=SPI0_MOSI_PIN_SEL>
//   <i>    Shows which pin SPI0_MOSI is mapped to
//   <info>  [PTB3, PTE1]
//     <0=> Disabled
//     <1=> PTB3<selection=PTB3_SIG_SEL,SPI0_MOSI>
//     <2=> PTE1<selection=PTE1_SIG_SEL,SPI0_MOSI>
//     <0=> Default
#define SPI0_MOSI_PIN_SEL    0

// Pin Mapping for SPI0_PCS signal
//   <o>    SPI0_PCS<name=SPI0_PCS_PIN_SEL>
//   <i>    Shows which pin SPI0_PCS is mapped to
//   <info>  [PTE3, PTB5]
//     <0=> Disabled
//     <1=> PTE3<selection=PTE3_SIG_SEL,SPI0_PCS>
//     <2=> PTB5<selection=PTB5_SIG_SEL,SPI0_PCS>
//     <0=> Default
#define SPI0_PCS_PIN_SEL     0

// Pin Mapping for SPI0_SCK signal
//   <o>    SPI0_SCK<name=SPI0_SCK_PIN_SEL>
//   <i>    Shows which pin SPI0_SCK is mapped to
//   <info>  [PTB2, PTE0]
//     <0=> Disabled
//     <1=> PTB2<selection=PTB2_SIG_SEL,SPI0_SCK>
//     <2=> PTE0<selection=PTE0_SIG_SEL,SPI0_SCK>
//     <0=> Default
#define SPI0_SCK_PIN_SEL     0

// </h>

// <h> Serial Peripheral Interface (SPI1)

// Pin Mapping for SPI1_MISO signal
//   <o>    SPI1_MISO<name=SPI1_MISO_PIN_SEL>
//   <i>    Shows which pin SPI1_MISO is mapped to
//   <info>  [PTD2, PTG6]
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,SPI1_MISO>
//     <2=> PTG6 (Alias:LED_GREEN)<selection=PTG6_SIG_SEL,SPI1_MISO>
//     <0=> Default
#define SPI1_MISO_PIN_SEL    0

// Pin Mapping for SPI1_MOSI signal
//   <o>    SPI1_MOSI<name=SPI1_MOSI_PIN_SEL>
//   <i>    Shows which pin SPI1_MOSI is mapped to
//   <info>  [PTD1, PTG5]
//     <0=> Disabled
//     <1=> PTD1<selection=PTD1_SIG_SEL,SPI1_MOSI>
//     <2=> PTG5 (Alias:LED_RED)<selection=PTG5_SIG_SEL,SPI1_MOSI>
//     <0=> Default
#define SPI1_MOSI_PIN_SEL    0

// Pin Mapping for SPI1_PCS signal
//   <o>    SPI1_PCS<name=SPI1_PCS_PIN_SEL>
//   <i>    Shows which pin SPI1_PCS is mapped to
//   <info>  [PTD3, PTG7]
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,SPI1_PCS>
//     <2=> PTG7 (Alias:LED_BLUE)<selection=PTG7_SIG_SEL,SPI1_PCS>
//     <0=> Default
#define SPI1_PCS_PIN_SEL     0

// Pin Mapping for SPI1_SCK signal
//   <o>    SPI1_SCK<name=SPI1_SCK_PIN_SEL>
//   <i>    Shows which pin SPI1_SCK is mapped to
//   <info>  [PTD0, PTG4]
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,SPI1_SCK>
//     <2=> PTG4<selection=PTG4_SIG_SEL,SPI1_SCK>
//     <0=> Default
#define SPI1_SCK_PIN_SEL     0

// </h>

// <h> Universal Asynchronous Rx/Tx (UART0)

// Pin Mapping for UART0_RX signal
//   <o>    UART0_RX<name=UART0_RX_PIN_SEL>
//   <i>    Shows which pin UART0_RX is mapped to
//   <info>  [PTA2, PTB0]
//     <0=> Disabled
//     <1=> PTA2<selection=PTA2_SIG_SEL,UART0_RX>
//     <2=> PTB0<selection=PTB0_SIG_SEL,UART0_RX>
//     <0=> Default
#define UART0_RX_PIN_SEL     0

// Pin Mapping for UART0_TX signal
//   <o>    UART0_TX<name=UART0_TX_PIN_SEL>
//   <i>    Shows which pin UART0_TX is mapped to
//   <info>  [PTA3, PTB1]
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,UART0_TX>
//     <2=> PTB1<selection=PTB1_SIG_SEL,UART0_TX>
//     <0=> Default
#define UART0_TX_PIN_SEL     0

// </h>

// <h> Universal Asynchronous Rx/Tx (UART1)

// Pin Mapping for UART1_RX signal
//   <o>    UART1_RX<name=UART1_RX_PIN_SEL>
//   <i>    Shows which pin UART1_RX is mapped to
//   <info>  [PTC6, PTF2]
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,UART1_RX>
//     <2=> PTF2<selection=PTF2_SIG_SEL,UART1_RX>
//     <0=> Default
#define UART1_RX_PIN_SEL     0

// Pin Mapping for UART1_TX signal
//   <o>    UART1_TX<name=UART1_TX_PIN_SEL>
//   <i>    Shows which pin UART1_TX is mapped to
//   <info>  [PTC7, PTF3]
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,UART1_TX>
//     <2=> PTF3<selection=PTF3_SIG_SEL,UART1_TX>
//     <0=> Default
#define UART1_TX_PIN_SEL     0

// </h>

// <h> Universal Asynchronous Rx/Tx (UART2)

// Pin Mapping for UART2_RX signal
//   <o>    UART2_RX<name=UART2_RX_PIN_SEL>
//   <i>    Shows which pin UART2_RX is mapped to
//   <info>  [PTD6, PTI0]
//     <0=> Disabled
//     <1=> PTD6<selection=PTD6_SIG_SEL,UART2_RX>
//     <2=> PTI0<selection=PTI0_SIG_SEL,UART2_RX>
//     <0=> Default
#define UART2_RX_PIN_SEL     0

// Pin Mapping for UART2_TX signal
//   <o>    UART2_TX<name=UART2_TX_PIN_SEL>
//   <i>    Shows which pin UART2_TX is mapped to
//   <info>  [PTD7, PTI1]
//     <0=> Disabled
//     <1=> PTD7<selection=PTD7_SIG_SEL,UART2_TX>
//     <2=> PTI1<selection=PTI1_SIG_SEL,UART2_TX>
//     <0=> Default
#define UART2_TX_PIN_SEL     0

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
 * Peripheral information for Analogue Input
 */
class Adc0Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = ADC0_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC_ADC0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {ADC0_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (ADC0_SE0_PIN_SEL == 1)
         /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  0,  5 },
#else
         /*  0 */  { 0 },
#endif
#if (ADC0_SE1_PIN_SEL == 1)
         /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  1,  5 },
#else
         /*  1 */  { 0 },
#endif
#if (ADC0_SE2_PIN_SEL == 1)
         /*  2 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  6,  4 },
#else
         /*  2 */  { 0 },
#endif
#if (ADC0_SE3_PIN_SEL == 1)
         /*  3 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  7,  4 },
#else
         /*  3 */  { 0 },
#endif
#if (ADC0_SE4_PIN_SEL == 1)
         /*  4 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  0,  4 },
#else
         /*  4 */  { 0 },
#endif
#if (ADC0_SE5_PIN_SEL == 1)
         /*  5 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  1,  4 },
#else
         /*  5 */  { 0 },
#endif
#if (ADC0_SE6_PIN_SEL == 1)
         /*  6 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  2,  4 },
#else
         /*  6 */  { 0 },
#endif
#if (ADC0_SE7_PIN_SEL == 1)
         /*  7 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  3,  4 },
#else
         /*  7 */  { 0 },
#endif
#if (ADC0_SE8_PIN_SEL == 1)
         /*  8 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  0,  4 },
#else
         /*  8 */  { 0 },
#endif
#if (ADC0_SE9_PIN_SEL == 1)
         /*  9 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  1,  4 },
#else
         /*  9 */  { 0 },
#endif
#if (ADC0_SE10_PIN_SEL == 1)
         /* 10 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  2,  4 },
#else
         /* 10 */  { 0 },
#endif
#if (ADC0_SE11_PIN_SEL == 1)
         /* 11 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  3,  4 },
#else
         /* 11 */  { 0 },
#endif
#if (ADC0_SE12_PIN_SEL == 1)
         /* 12 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  4,  4 },
#else
         /* 12 */  { 0 },
#endif
#if (ADC0_SE13_PIN_SEL == 1)
         /* 13 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  5,  4 },
#else
         /* 13 */  { 0 },
#endif
#if (ADC0_SE14_PIN_SEL == 1)
         /* 14 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  6,  4 },
#else
         /* 14 */  { 0 },
#endif
#if (ADC0_SE15_PIN_SEL == 1)
         /* 15 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  7,  4 },
#else
         /* 15 */  { 0 },
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
   static constexpr uint32_t clockMask = SIM_SCGC_ADC0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {ADC0_IRQn};

};

/**
 * Peripheral information for PWM, Input capture, Output compare
 */
class Ftm0Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = FTM0_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC_FTM0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {FTM0_IRQn};

   //! Base value for tmr->SC register
   static constexpr uint32_t scValue  = FTM0_SC;

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (FTM0_CH0_PIN_SEL == 1)
         /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  0,  2 },
#elif (FTM0_CH0_PIN_SEL == 2)
         /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  2,  3 },
#else
         /*  0 */  { 0 },
#endif
#if (FTM0_CH1_PIN_SEL == 1)
         /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  1,  2 },
#elif (FTM0_CH1_PIN_SEL == 2)
         /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  3,  3 },
#else
         /*  1 */  { 0 },
#endif
   };
};

/**
 * Peripheral information for PWM, Input capture, Output compare
 */
class Ftm1Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = FTM1_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC_FTM1_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {FTM1_IRQn};

   //! Base value for tmr->SC register
   static constexpr uint32_t scValue  = FTM1_SC;

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (FTM1_CH0_PIN_SEL == 1)
         /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  4,  3 },
#elif (FTM1_CH0_PIN_SEL == 2)
         /*  0 */  { PORTH_CLOCK_MASK, PORTH_BasePtr,  GPIOH_BasePtr,  2,  4 },
#else
         /*  0 */  { 0 },
#endif
#if (FTM1_CH1_PIN_SEL == 1)
         /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  5,  3 },
#elif (FTM1_CH1_PIN_SEL == 2)
         /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  7,  4 },
#else
         /*  1 */  { 0 },
#endif
   };
};

/**
 * Peripheral information for PWM, Input capture, Output compare
 */
class Ftm2Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = FTM2_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC_FTM2_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {FTM2_IRQn};

   //! Base value for tmr->SC register
   static constexpr uint32_t scValue  = FTM2_SC;

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (FTM2_CH0_PIN_SEL == 1)
         /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  0,  2 },
#elif (FTM2_CH0_PIN_SEL == 2)
         /*  0 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  0,  2 },
#elif (FTM2_CH0_PIN_SEL == 3)
         /*  0 */  { PORTH_CLOCK_MASK, PORTH_BasePtr,  GPIOH_BasePtr,  0,  2 },
#else
         /*  0 */  { 0 },
#endif
#if (FTM2_CH1_PIN_SEL == 1)
         /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  1,  2 },
#elif (FTM2_CH1_PIN_SEL == 2)
         /*  1 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  1,  2 },
#elif (FTM2_CH1_PIN_SEL == 3)
         /*  1 */  { PORTH_CLOCK_MASK, PORTH_BasePtr,  GPIOH_BasePtr,  1,  2 },
#else
         /*  1 */  { 0 },
#endif
#if (FTM2_CH2_PIN_SEL == 1)
         /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  2,  2 },
#elif (FTM2_CH2_PIN_SEL == 2)
         /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  0,  2 },
#elif (FTM2_CH2_PIN_SEL == 3)
         /*  2 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  4,  2 },
#else
         /*  2 */  { 0 },
#endif
#if (FTM2_CH3_PIN_SEL == 1)
         /*  3 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  3,  2 },
#elif (FTM2_CH3_PIN_SEL == 2)
         /*  3 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  1,  2 },
#elif (FTM2_CH3_PIN_SEL == 3)
         /*  3 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  5,  2 },
#else
         /*  3 */  { 0 },
#endif
#if (FTM2_CH4_PIN_SEL == 1)
         /*  4 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  4,  2 },
#elif (FTM2_CH4_PIN_SEL == 2)
         /*  4 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  6,  2 },
#else
         /*  4 */  { 0 },
#endif
#if (FTM2_CH5_PIN_SEL == 1)
         /*  5 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  5,  2 },
#elif (FTM2_CH5_PIN_SEL == 2)
         /*  5 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  7,  2 },
#else
         /*  5 */  { 0 },
#endif
         /*  6 */  { 0 },
         /*  7 */  { 0 },
         /*  8 */  { 0 },
         /*  9 */  { 0 },
         /* 10 */  { 0 },
         /* 11 */  { 0 },
         /* 12 */  { 0 },
#if (FTM2_FLT1_PIN_SEL == 1)
         /* 13 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  6,  2 },
#else
         /* 13 */  { 0 },
#endif
#if (FTM2_FLT2_PIN_SEL == 1)
         /* 14 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  7,  2 },
#else
         /* 14 */  { 0 },
#endif
   };
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
   static constexpr uint32_t clockMask = SIM_SCGC_I2C0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {I2C0_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (I2C0_SCL_PIN_SEL == 1)
         /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  7,  2 },
#elif (I2C0_SCL_PIN_SEL == 2)
         /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  3,  3 },
#else
         /*  0 */  { 0 },
#endif
#if (I2C0_SDA_PIN_SEL == 1)
         /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  6,  2 },
#elif (I2C0_SDA_PIN_SEL == 2)
         /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  2,  3 },
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
   static constexpr uint32_t clockMask = SIM_SCGC_I2C1_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {I2C1_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (I2C1_SCL_PIN_SEL == 1)
         /*  0 */  { PORTH_CLOCK_MASK, PORTH_BasePtr,  GPIOH_BasePtr,  4,  2 },
#elif (I2C1_SCL_PIN_SEL == 2)
         /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  1,  4 },
#else
         /*  0 */  { 0 },
#endif
#if (I2C1_SDA_PIN_SEL == 1)
         /*  1 */  { PORTH_CLOCK_MASK, PORTH_BasePtr,  GPIOH_BasePtr,  3,  2 },
#elif (I2C1_SDA_PIN_SEL == 2)
         /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  0,  4 },
#else
         /*  1 */  { 0 },
#endif
   };
};

/**
 * Peripheral information for Abstraction for Programmable Interrupt Timer
 */
class PitInfo {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = PIT_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC_PIT_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 2;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {PIT0_IRQn, PIT1_IRQn};

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
   static constexpr uint32_t clockMask = SIM_SCGC_SPI0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {SPI0_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (SPI0_SCK_PIN_SEL == 1)
         /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  2,  2 },
#elif (SPI0_SCK_PIN_SEL == 2)
         /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  0,  2 },
#else
         /*  0 */  { 0 },
#endif
#if (SPI0_MISO_PIN_SEL == 1)
         /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  2,  2 },
#elif (SPI0_MISO_PIN_SEL == 2)
         /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  4,  3 },
#else
         /*  1 */  { 0 },
#endif
#if (SPI0_MOSI_PIN_SEL == 1)
         /*  2 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  3,  2 },
#elif (SPI0_MOSI_PIN_SEL == 2)
         /*  2 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  1,  2 },
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
   static constexpr uint32_t clockMask = SIM_SCGC_SPI1_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {SPI1_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (SPI1_SCK_PIN_SEL == 1)
         /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  0,  3 },
#elif (SPI1_SCK_PIN_SEL == 2)
         /*  0 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  4,  3 },
#else
         /*  0 */  { 0 },
#endif
#if (SPI1_MISO_PIN_SEL == 1)
         /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  2,  2 },
#elif (SPI1_MISO_PIN_SEL == 2)
         /*  1 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  6,  3 },
#else
         /*  1 */  { 0 },
#endif
#if (SPI1_MOSI_PIN_SEL == 1)
         /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  1,  3 },
#elif (SPI1_MOSI_PIN_SEL == 2)
         /*  2 */  { PORTG_CLOCK_MASK, PORTG_BasePtr,  GPIOG_BasePtr,  5,  3 },
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
   static constexpr uint32_t clockMask = SIM_SCGC_UART0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {UART0_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (UART0_TX_PIN_SEL == 1)
         /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  3,  2 },
#elif (UART0_TX_PIN_SEL == 2)
         /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  1,  2 },
#else
         /*  0 */  { 0 },
#endif
#if (UART0_RX_PIN_SEL == 1)
         /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  2,  2 },
#elif (UART0_RX_PIN_SEL == 2)
         /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  0,  2 },
#else
         /*  1 */  { 0 },
#endif
   };
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
   static constexpr uint32_t clockMask = SIM_SCGC_UART1_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {UART1_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (UART1_TX_PIN_SEL == 1)
         /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  7,  2 },
#elif (UART1_TX_PIN_SEL == 2)
         /*  0 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  3,  2 },
#else
         /*  0 */  { 0 },
#endif
#if (UART1_RX_PIN_SEL == 1)
         /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  6,  2 },
#elif (UART1_RX_PIN_SEL == 2)
         /*  1 */  { PORTF_CLOCK_MASK, PORTF_BasePtr,  GPIOF_BasePtr,  2,  2 },
#else
         /*  1 */  { 0 },
#endif
   };
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
   static constexpr uint32_t clockMask = SIM_SCGC_UART2_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {UART2_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (UART2_TX_PIN_SEL == 1)
         /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  7,  2 },
#elif (UART2_TX_PIN_SEL == 2)
         /*  0 */  { PORTI_CLOCK_MASK, PORTI_BasePtr,  GPIOI_BasePtr,  1,  3 },
#else
         /*  0 */  { 0 },
#endif
#if (UART2_RX_PIN_SEL == 1)
         /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  6,  2 },
#elif (UART2_RX_PIN_SEL == 2)
         /*  1 */  { PORTI_CLOCK_MASK, PORTI_BasePtr,  GPIOI_BasePtr,  0,  3 },
#else
         /*  1 */  { 0 },
#endif
   };
};

/**
 * @}
 ** PeripheralPinTables
 */

} // End namespace USBDM

#include "gpio_defs.h"

namespace USBDM {

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

/**
 * @}
 */
/**
 * @addtogroup PwmIO_Group PWM, Input capture, Output compare
 * @brief Allows use of port pins as PWM outputs
 * @{
 */
/**
 * Convenience templated class representing a FTM
 *
 * Example
 * @code
 * // Instantiate the ftm channel (for FTM0 CH6)
 * const USBDM::Ftm0<6>   ftm0_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * ftm0_ch6.setPwmOutput(200, USBDM::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * ftm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * ftm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam channel    Timer channel
 */
template<uint8_t channel> using Ftm0 = TmrBase_T<Ftm0Info, channel>;

/**
 * @}
 */
/**
 * @addtogroup PwmIO_Group PWM, Input capture, Output compare
 * @brief Allows use of port pins as PWM outputs
 * @{
 */
/**
 * Convenience templated class representing a FTM
 *
 * Example
 * @code
 * // Instantiate the ftm channel (for FTM0 CH6)
 * const USBDM::Ftm0<6>   ftm0_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * ftm0_ch6.setPwmOutput(200, USBDM::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * ftm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * ftm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam channel    Timer channel
 */
template<uint8_t channel> using Ftm1 = TmrBase_T<Ftm1Info, channel>;

/**
 * @}
 */
/**
 * @addtogroup PwmIO_Group PWM, Input capture, Output compare
 * @brief Allows use of port pins as PWM outputs
 * @{
 */
/**
 * Convenience templated class representing a FTM
 *
 * Example
 * @code
 * // Instantiate the ftm channel (for FTM0 CH6)
 * const USBDM::Ftm0<6>   ftm0_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * ftm0_ch6.setPwmOutput(200, USBDM::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * ftm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * ftm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam channel    Timer channel
 */
template<uint8_t channel> using Ftm2 = TmrBase_T<Ftm2Info, channel>;

#if (PTG5_SIG_SEL == 2)
using ftm_LED_RED          = const USBDM::Ftm2<3>;
#endif
#if (PTG6_SIG_SEL == 2)
using ftm_LED_GREEN        = const USBDM::Ftm2<4>;
#endif
#if (PTG7_SIG_SEL == 2)
using ftm_LED_BLUE         = const USBDM::Ftm2<5>;
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
