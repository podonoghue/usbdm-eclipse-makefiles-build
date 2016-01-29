/**
 * @file      pin_mapping.h (derived from pin_mapping-MKL27Z644.h)
 * @version   1.1.0
 * @brief     Pin declarations for MKL27Z644, generated from MKL27Z644.csv
 */

#ifndef PROJECT_HEADERS_PIN_MAPPING_H_
#define PROJECT_HEADERS_PIN_MAPPING_H_

#include <stddef.h>
#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

//================================
// Validators
// <validate=net.sourceforge.usbdm.annotationEditor.validators.PinMappingValidator>

// <h> Clock settings for TPM0

// TPM0_SC.CMOD ================================
//
//   <o> TPM0_SC.CMOD Clock source
//   <i> Selects the clock source for the TPM0 module. [TPM0_SC.CMOD]
//     <0=> Disabled
//     <1=> Internal clock
//     <2=> External clock
//     <3=> Reserved
//     <1=> Default
// TPM0_SC.PS ================================
//
//   <o1> TPM0_SC.PS Clock prescaler
//   <i> Selects the prescaler for the TPM0 module. [TPM0_SC.PS]
//     <0=> Divide by 1
//     <1=> Divide by 2
//     <2=> Divide by 4
//     <3=> Divide by 8
//     <4=> Divide by 16
//     <5=> Divide by 32
//     <6=> Divide by 64
//     <7=> Divide by 128
//     <0=> Default
constexpr uint16_t TPM0_SC              = (TPM_SC_CMOD(0x1)|TPM_SC_PS(0x0));

// </h>

// <h> Clock settings for TPM1

// TPM1_SC.CMOD ================================
//
//   <o> TPM1_SC.CMOD Clock source
//   <i> Selects the clock source for the TPM1 module. [TPM1_SC.CMOD]
//     <0=> Disabled
//     <1=> Internal clock
//     <2=> External clock
//     <3=> Reserved
//     <1=> Default
// TPM1_SC.PS ================================
//
//   <o1> TPM1_SC.PS Clock prescaler
//   <i> Selects the prescaler for the TPM1 module. [TPM1_SC.PS]
//     <0=> Divide by 1
//     <1=> Divide by 2
//     <2=> Divide by 4
//     <3=> Divide by 8
//     <4=> Divide by 16
//     <5=> Divide by 32
//     <6=> Divide by 64
//     <7=> Divide by 128
//     <0=> Default
constexpr uint16_t TPM1_SC              = (TPM_SC_CMOD(0x1)|TPM_SC_PS(0x0));

// </h>

// <h> Clock settings for TPM2

// TPM2_SC.CMOD ================================
//
//   <o> TPM2_SC.CMOD Clock source
//   <i> Selects the clock source for the TPM2 module. [TPM2_SC.CMOD]
//     <0=> Disabled
//     <1=> Internal clock
//     <2=> External clock
//     <3=> Reserved
//     <1=> Default
// TPM2_SC.PS ================================
//
//   <o1> TPM2_SC.PS Clock prescaler
//   <i> Selects the prescaler for the TPM2 module. [TPM2_SC.PS]
//     <0=> Divide by 1
//     <1=> Divide by 2
//     <2=> Divide by 4
//     <3=> Divide by 8
//     <4=> Divide by 16
//     <5=> Divide by 32
//     <6=> Divide by 64
//     <7=> Divide by 128
//     <0=> Default
constexpr uint16_t TPM2_SC              = (TPM_SC_CMOD(0x1)|TPM_SC_PS(0x0));

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
//   <o> PTA0 [GPIOA_0, TPM0_CH5, SWD_CLK]<name=PTA0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA0 pin
//     <-2=> SWD_CLK (reset default)<selection=SWD_CLK_PIN_SEL,PTA0 (reset default)>
//     <1=> GPIOA_0<selection=GPIOA_0_PIN_SEL,PTA0>
//     <3=> TPM0_CH5<selection=TPM0_CH5_PIN_SEL,PTA0>
//     <7=> SWD_CLK<selection=SWD_CLK_PIN_SEL,PTA0>
//     <-2=> Default
#define PTA0_SIG_SEL         -2

// Signal mapping for PTA1 pin
//   <o> PTA1 (Alias:D0) [GPIOA_1, LPUART0_RX, TPM2_CH0]<name=PTA1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA1 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_1<selection=GPIOA_1_PIN_SEL,PTA1 (Alias:D0)>
//     <2=> LPUART0_RX<selection=LPUART0_RX_PIN_SEL,PTA1 (Alias:D0)>
//     <3=> TPM2_CH0<selection=TPM2_CH0_PIN_SEL,PTA1 (Alias:D0)>
//     <3=> Default
#define PTA1_SIG_SEL         3

// Signal mapping for PTA2 pin
//   <o> PTA2 (Alias:D1) [GPIOA_2, LPUART0_TX, TPM2_CH1]<name=PTA2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA2 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_2<selection=GPIOA_2_PIN_SEL,PTA2 (Alias:D1)>
//     <2=> LPUART0_TX<selection=LPUART0_TX_PIN_SEL,PTA2 (Alias:D1)>
//     <3=> TPM2_CH1<selection=TPM2_CH1_PIN_SEL,PTA2 (Alias:D1)>
//     <3=> Default
#define PTA2_SIG_SEL         3

// Signal mapping for PTA3 pin
//   <o> PTA3 [GPIOA_3, I2C1_SCL, TPM0_CH0, SWD_DIO]<name=PTA3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA3 pin
//     <-2=> SWD_DIO (reset default)<selection=SWD_DIO_PIN_SEL,PTA3 (reset default)>
//     <1=> GPIOA_3<selection=GPIOA_3_PIN_SEL,PTA3>
//     <2=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTA3>
//     <3=> TPM0_CH0<selection=TPM0_CH0_PIN_SEL,PTA3>
//     <7=> SWD_DIO<selection=SWD_DIO_PIN_SEL,PTA3>
//     <-2=> Default
#define PTA3_SIG_SEL         -2

// Signal mapping for PTA4 pin
//   <o> PTA4 [GPIOA_4, I2C1_SDA, TPM0_CH1, NMI_b]<name=PTA4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA4 pin
//     <-2=> NMI_b (reset default)<selection=NMI_b_PIN_SEL,PTA4 (reset default)>
//     <1=> GPIOA_4<selection=GPIOA_4_PIN_SEL,PTA4>
//     <2=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTA4>
//     <3=> TPM0_CH1<selection=TPM0_CH1_PIN_SEL,PTA4>
//     <7=> NMI_b<selection=NMI_b_PIN_SEL,PTA4>
//     <-2=> Default
#define PTA4_SIG_SEL         -2

// Signal mapping for PTA5 pin
//   <o> PTA5 (Alias:D9) [GPIOA_5, USB_CLKIN, TPM0_CH2]<name=PTA5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA5 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_5<selection=GPIOA_5_PIN_SEL,PTA5 (Alias:D9)>
//     <2=> USB_CLKIN<selection=USB_CLKIN_PIN_SEL,PTA5 (Alias:D9)>
//     <3=> TPM0_CH2<selection=TPM0_CH2_PIN_SEL,PTA5 (Alias:D9)>
//     <3=> Default
#define PTA5_SIG_SEL         3

// Signal mapping for PTA12 pin
//   <o> PTA12 (Alias:D2) [GPIOA_12, TPM1_CH0]<name=PTA12_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA12 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_12<selection=GPIOA_12_PIN_SEL,PTA12 (Alias:D2)>
//     <3=> TPM1_CH0<selection=TPM1_CH0_PIN_SEL,PTA12 (Alias:D2)>
//     <3=> Default
#define PTA12_SIG_SEL        3

// Signal mapping for PTA13 pin
//   <o> PTA13 (Alias:D4, LED_BLUE) [GPIOA_13, TPM1_CH1]<name=PTA13_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA13 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_13<selection=GPIOA_13_PIN_SEL,PTA13 (Alias:D4, LED_BLUE)>
//     <3=> TPM1_CH1<selection=TPM1_CH1_PIN_SEL,PTA13 (Alias:D4, LED_BLUE)>
//     <3=> Default
#define PTA13_SIG_SEL        3

// Signal mapping for PTA18 pin
//   <o> PTA18 [EXTAL0, GPIOA_18, LPUART1_RX, TPM_CLKIN0]<name=PTA18_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA18 pin
//     <-2=> EXTAL0 (reset default)<selection=EXTAL0_PIN_SEL,PTA18 (reset default)>
//     <0=> EXTAL0<selection=EXTAL0_PIN_SEL,PTA18>
//     <1=> GPIOA_18<selection=GPIOA_18_PIN_SEL,PTA18>
//     <3=> LPUART1_RX<selection=LPUART1_RX_PIN_SEL,PTA18>
//     <4=> TPM_CLKIN0<selection=TPM_CLKIN0_PIN_SEL,PTA18>
//     <-2=> Default
#define PTA18_SIG_SEL        -2

// Signal mapping for PTA19 pin
//   <o> PTA19 [XTAL0, GPIOA_19, LPUART1_TX, TPM_CLKIN1, LPTMR0_ALT1]<name=PTA19_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA19 pin
//     <-2=> XTAL0 (reset default)<selection=XTAL0_PIN_SEL,PTA19 (reset default)>
//     <0=> XTAL0<selection=XTAL0_PIN_SEL,PTA19>
//     <1=> GPIOA_19<selection=GPIOA_19_PIN_SEL,PTA19>
//     <3=> LPUART1_TX<selection=LPUART1_TX_PIN_SEL,PTA19>
//     <4=> TPM_CLKIN1<selection=TPM_CLKIN1_PIN_SEL,PTA19>
//     <6=> LPTMR0_ALT1<selection=LPTMR0_ALT1_PIN_SEL,PTA19>
//     <-2=> Default
#define PTA19_SIG_SEL        -2

// Signal mapping for PTA20 pin
//   <o> PTA20 [GPIOA_20, RESET_b]<name=PTA20_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA20 pin
//     <-2=> RESET_b (reset default)<selection=RESET_b_PIN_SEL,PTA20 (reset default)>
//     <1=> GPIOA_20<selection=GPIOA_20_PIN_SEL,PTA20>
//     <7=> RESET_b<selection=RESET_b_PIN_SEL,PTA20>
//     <-2=> Default
#define PTA20_SIG_SEL        -2

// </h>

// <h> Port B Pins

// Signal mapping for PTB0 pin
//   <o> PTB0 (Alias:A5) [ADC0_SE8, GPIOB_0/LLWU_P5, I2C0_SCL, TPM1_CH0, SPI1_MOSI, SPI1_MISO]<name=PTB0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB0 pin
//     <-2=> ADC0_SE8 (reset default)<selection=ADC0_SE8_PIN_SEL,PTB0 (Alias:A5) (reset default)>
//     <0=> ADC0_SE8<selection=ADC0_SE8_PIN_SEL,PTB0 (Alias:A5)>
//     <1=> GPIOB_0/LLWU_P5<selection=GPIOB_0_PIN_SEL,PTB0 (Alias:A5)><selection=LLWU_P5_PIN_SEL,PTB0 (Alias:A5)>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTB0 (Alias:A5)>
//     <3=> TPM1_CH0<selection=TPM1_CH0_PIN_SEL,PTB0 (Alias:A5)>
//     <4=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTB0 (Alias:A5)>
//     <5=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTB0 (Alias:A5)>
//     <0=> Default
#define PTB0_SIG_SEL         0

// Signal mapping for PTB1 pin
//   <o> PTB1 (Alias:A4) [ADC0_SE9, GPIOB_1, I2C0_SDA, TPM1_CH1, SPI1_MISO, SPI1_MOSI]<name=PTB1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB1 pin
//     <-2=> ADC0_SE9 (reset default)<selection=ADC0_SE9_PIN_SEL,PTB1 (Alias:A4) (reset default)>
//     <0=> ADC0_SE9<selection=ADC0_SE9_PIN_SEL,PTB1 (Alias:A4)>
//     <1=> GPIOB_1<selection=GPIOB_1_PIN_SEL,PTB1 (Alias:A4)>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTB1 (Alias:A4)>
//     <3=> TPM1_CH1<selection=TPM1_CH1_PIN_SEL,PTB1 (Alias:A4)>
//     <4=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTB1 (Alias:A4)>
//     <5=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTB1 (Alias:A4)>
//     <0=> Default
#define PTB1_SIG_SEL         0

// Signal mapping for PTB2 pin
//   <o> PTB2 [ADC0_SE12, GPIOB_2, I2C0_SCL, TPM2_CH0]<name=PTB2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB2 pin
//     <-2=> ADC0_SE12 (reset default)<selection=ADC0_SE12_PIN_SEL,PTB2 (reset default)>
//     <0=> ADC0_SE12<selection=ADC0_SE12_PIN_SEL,PTB2>
//     <1=> GPIOB_2<selection=GPIOB_2_PIN_SEL,PTB2>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTB2>
//     <3=> TPM2_CH0<selection=TPM2_CH0_PIN_SEL,PTB2>
//     <-2=> Default
#define PTB2_SIG_SEL         -2

// Signal mapping for PTB3 pin
//   <o> PTB3 [ADC0_SE13, GPIOB_3, I2C0_SDA, TPM2_CH1]<name=PTB3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB3 pin
//     <-2=> ADC0_SE13 (reset default)<selection=ADC0_SE13_PIN_SEL,PTB3 (reset default)>
//     <0=> ADC0_SE13<selection=ADC0_SE13_PIN_SEL,PTB3>
//     <1=> GPIOB_3<selection=GPIOB_3_PIN_SEL,PTB3>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTB3>
//     <3=> TPM2_CH1<selection=TPM2_CH1_PIN_SEL,PTB3>
//     <-2=> Default
#define PTB3_SIG_SEL         -2

// Signal mapping for PTB16 pin
//   <o> PTB16 [GPIOB_16, SPI1_MOSI, LPUART0_RX, TPM_CLKIN0, SPI1_MISO]<name=PTB16_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB16 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_16<selection=GPIOB_16_PIN_SEL,PTB16>
//     <2=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTB16>
//     <3=> LPUART0_RX<selection=LPUART0_RX_PIN_SEL,PTB16>
//     <4=> TPM_CLKIN0<selection=TPM_CLKIN0_PIN_SEL,PTB16>
//     <5=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTB16>
//     <-2=> Default
#define PTB16_SIG_SEL        -2

// Signal mapping for PTB17 pin
//   <o> PTB17 [GPIOB_17, SPI1_MISO, LPUART0_TX, TPM_CLKIN1, SPI1_MOSI]<name=PTB17_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB17 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_17<selection=GPIOB_17_PIN_SEL,PTB17>
//     <2=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTB17>
//     <3=> LPUART0_TX<selection=LPUART0_TX_PIN_SEL,PTB17>
//     <4=> TPM_CLKIN1<selection=TPM_CLKIN1_PIN_SEL,PTB17>
//     <5=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTB17>
//     <-2=> Default
#define PTB17_SIG_SEL        -2

// Signal mapping for PTB18 pin
//   <o> PTB18 (Alias:LED_RED) [GPIOB_18, TPM2_CH0]<name=PTB18_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB18 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_18<selection=GPIOB_18_PIN_SEL,PTB18 (Alias:LED_RED)>
//     <3=> TPM2_CH0<selection=TPM2_CH0_PIN_SEL,PTB18 (Alias:LED_RED)>
//     <-2=> Default
#define PTB18_SIG_SEL        -2

// Signal mapping for PTB19 pin
//   <o> PTB19 (Alias:LED_GREEN) [GPIOB_19, TPM2_CH1]<name=PTB19_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB19 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_19<selection=GPIOB_19_PIN_SEL,PTB19 (Alias:LED_GREEN)>
//     <3=> TPM2_CH1<selection=TPM2_CH1_PIN_SEL,PTB19 (Alias:LED_GREEN)>
//     <-2=> Default
#define PTB19_SIG_SEL        -2

// </h>

// <h> Port C Pins

// Signal mapping for PTC0 pin
//   <o> PTC0 (Alias:A1) [ADC0_SE14, GPIOC_0, EXTRG_IN, audioUSB_SOF_OUT, CMP0_OUT]<name=PTC0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC0 pin
//     <-2=> ADC0_SE14 (reset default)<selection=ADC0_SE14_PIN_SEL,PTC0 (Alias:A1) (reset default)>
//     <0=> ADC0_SE14<selection=ADC0_SE14_PIN_SEL,PTC0 (Alias:A1)>
//     <1=> GPIOC_0<selection=GPIOC_0_PIN_SEL,PTC0 (Alias:A1)>
//     <3=> EXTRG_IN<selection=EXTRG_IN_PIN_SEL,PTC0 (Alias:A1)>
//     <4=> audioUSB_SOF_OUT<selection=audioUSB_SOF_OUT_PIN_SEL,PTC0 (Alias:A1)>
//     <5=> CMP0_OUT<selection=CMP0_OUT_PIN_SEL,PTC0 (Alias:A1)>
//     <0=> Default
#define PTC0_SIG_SEL         0

// Signal mapping for PTC1 pin
//   <o> PTC1 [ADC0_SE15, GPIOC_1/LLWU_P6/RTC_CLKIN, I2C1_SCL, TPM0_CH0]<name=PTC1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC1 pin
//     <-2=> ADC0_SE15 (reset default)<selection=ADC0_SE15_PIN_SEL,PTC1 (reset default)>
//     <0=> ADC0_SE15<selection=ADC0_SE15_PIN_SEL,PTC1>
//     <1=> GPIOC_1/LLWU_P6/RTC_CLKIN<selection=GPIOC_1_PIN_SEL,PTC1><selection=LLWU_P6_PIN_SEL,PTC1><selection=RTC_CLKIN_PIN_SEL,PTC1>
//     <2=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTC1>
//     <4=> TPM0_CH0<selection=TPM0_CH0_PIN_SEL,PTC1>
//     <-2=> Default
#define PTC1_SIG_SEL         -2

// Signal mapping for PTC2 pin
//   <o> PTC2 (Alias:MAG_INT) [ADC0_SE11, GPIOC_2, I2C1_SDA, TPM0_CH1]<name=PTC2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC2 pin
//     <-2=> ADC0_SE11 (reset default)<selection=ADC0_SE11_PIN_SEL,PTC2 (Alias:MAG_INT) (reset default)>
//     <0=> ADC0_SE11<selection=ADC0_SE11_PIN_SEL,PTC2 (Alias:MAG_INT)>
//     <1=> GPIOC_2<selection=GPIOC_2_PIN_SEL,PTC2 (Alias:MAG_INT)>
//     <2=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTC2 (Alias:MAG_INT)>
//     <4=> TPM0_CH1<selection=TPM0_CH1_PIN_SEL,PTC2 (Alias:MAG_INT)>
//     <-2=> Default
#define PTC2_SIG_SEL         -2

// Signal mapping for PTC3 pin
//   <o> PTC3 [GPIOC_3/LLWU_P7, SPI1_SCK, LPUART1_RX, TPM0_CH2, CLKOUT]<name=PTC3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC3 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_3/LLWU_P7<selection=GPIOC_3_PIN_SEL,PTC3><selection=LLWU_P7_PIN_SEL,PTC3>
//     <2=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTC3>
//     <3=> LPUART1_RX<selection=LPUART1_RX_PIN_SEL,PTC3>
//     <4=> TPM0_CH2<selection=TPM0_CH2_PIN_SEL,PTC3>
//     <5=> CLKOUT<selection=CLKOUT_PIN_SEL,PTC3>
//     <-2=> Default
#define PTC3_SIG_SEL         -2

// Signal mapping for PTC4 pin
//   <o> PTC4 (Alias:D10) [GPIOC_4/LLWU_P8, SPI0_PCS0, LPUART1_TX, TPM0_CH3, SPI1_PCS0]<name=PTC4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC4 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_4/LLWU_P8<selection=GPIOC_4_PIN_SEL,PTC4 (Alias:D10)><selection=LLWU_P8_PIN_SEL,PTC4 (Alias:D10)>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTC4 (Alias:D10)>
//     <3=> LPUART1_TX<selection=LPUART1_TX_PIN_SEL,PTC4 (Alias:D10)>
//     <4=> TPM0_CH3<selection=TPM0_CH3_PIN_SEL,PTC4 (Alias:D10)>
//     <5=> SPI1_PCS0<selection=SPI1_PCS0_PIN_SEL,PTC4 (Alias:D10)>
//     <1=> Default
#define PTC4_SIG_SEL         1

// Signal mapping for PTC5 pin
//   <o> PTC5 (Alias:D13) [GPIOC_5/LLWU_P9, SPI0_SCK, LPTMR0_ALT2, CMP0_OUT]<name=PTC5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC5 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_5/LLWU_P9<selection=GPIOC_5_PIN_SEL,PTC5 (Alias:D13)><selection=LLWU_P9_PIN_SEL,PTC5 (Alias:D13)>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTC5 (Alias:D13)>
//     <3=> LPTMR0_ALT2<selection=LPTMR0_ALT2_PIN_SEL,PTC5 (Alias:D13)>
//     <6=> CMP0_OUT<selection=CMP0_OUT_PIN_SEL,PTC5 (Alias:D13)>
//     <1=> Default
#define PTC5_SIG_SEL         1

// Signal mapping for PTC6 pin
//   <o> PTC6 (Alias:D11) [CMP0_IN0, GPIOC_6/LLWU_P10, SPI0_MOSI, EXTRG_IN, SPI0_MISO]<name=PTC6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC6 pin
//     <-2=> CMP0_IN0 (reset default)<selection=CMP0_IN0_PIN_SEL,PTC6 (Alias:D11) (reset default)>
//     <0=> CMP0_IN0<selection=CMP0_IN0_PIN_SEL,PTC6 (Alias:D11)>
//     <1=> GPIOC_6/LLWU_P10<selection=GPIOC_6_PIN_SEL,PTC6 (Alias:D11)><selection=LLWU_P10_PIN_SEL,PTC6 (Alias:D11)>
//     <2=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTC6 (Alias:D11)>
//     <3=> EXTRG_IN<selection=EXTRG_IN_PIN_SEL,PTC6 (Alias:D11)>
//     <5=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTC6 (Alias:D11)>
//     <1=> Default
#define PTC6_SIG_SEL         1

// Signal mapping for PTC7 pin
//   <o> PTC7 (Alias:D12) [CMP0_IN1, GPIOC_7, SPI0_MISO, audioUSB_SOF_OUT, SPI0_MOSI]<name=PTC7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC7 pin
//     <-2=> CMP0_IN1 (reset default)<selection=CMP0_IN1_PIN_SEL,PTC7 (Alias:D12) (reset default)>
//     <0=> CMP0_IN1<selection=CMP0_IN1_PIN_SEL,PTC7 (Alias:D12)>
//     <1=> GPIOC_7<selection=GPIOC_7_PIN_SEL,PTC7 (Alias:D12)>
//     <2=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTC7 (Alias:D12)>
//     <3=> audioUSB_SOF_OUT<selection=audioUSB_SOF_OUT_PIN_SEL,PTC7 (Alias:D12)>
//     <5=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTC7 (Alias:D12)>
//     <1=> Default
#define PTC7_SIG_SEL         1

// Signal mapping for PTC8 pin
//   <o> PTC8 (Alias:D7) [CMP0_IN2, GPIOC_8, I2C0_SCL, TPM0_CH4]<name=PTC8_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC8 pin
//     <-2=> CMP0_IN2 (reset default)<selection=CMP0_IN2_PIN_SEL,PTC8 (Alias:D7) (reset default)>
//     <0=> CMP0_IN2<selection=CMP0_IN2_PIN_SEL,PTC8 (Alias:D7)>
//     <1=> GPIOC_8<selection=GPIOC_8_PIN_SEL,PTC8 (Alias:D7)>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTC8 (Alias:D7)>
//     <3=> TPM0_CH4<selection=TPM0_CH4_PIN_SEL,PTC8 (Alias:D7)>
//     <1=> Default
#define PTC8_SIG_SEL         1

// Signal mapping for PTC9 pin
//   <o> PTC9 (Alias:D6) [CMP0_IN3, GPIOC_9, I2C0_SDA, TPM0_CH5]<name=PTC9_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC9 pin
//     <-2=> CMP0_IN3 (reset default)<selection=CMP0_IN3_PIN_SEL,PTC9 (Alias:D6) (reset default)>
//     <0=> CMP0_IN3<selection=CMP0_IN3_PIN_SEL,PTC9 (Alias:D6)>
//     <1=> GPIOC_9<selection=GPIOC_9_PIN_SEL,PTC9 (Alias:D6)>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTC9 (Alias:D6)>
//     <3=> TPM0_CH5<selection=TPM0_CH5_PIN_SEL,PTC9 (Alias:D6)>
//     <1=> Default
#define PTC9_SIG_SEL         1

// Signal mapping for PTC10 pin
//   <o> PTC10 [GPIOC_10, I2C1_SCL]<name=PTC10_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC10 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_10<selection=GPIOC_10_PIN_SEL,PTC10>
//     <2=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTC10>
//     <-2=> Default
#define PTC10_SIG_SEL        -2

// Signal mapping for PTC11 pin
//   <o> PTC11 [GPIOC_11, I2C1_SDA]<name=PTC11_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC11 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_11<selection=GPIOC_11_PIN_SEL,PTC11>
//     <2=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTC11>
//     <-2=> Default
#define PTC11_SIG_SEL        -2

// </h>

// <h> Port D Pins

// Signal mapping for PTD0 pin
//   <o> PTD0 [GPIOD_0, SPI0_PCS0, TPM0_CH0, FXIO0_D0]<name=PTD0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD0 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_0<selection=GPIOD_0_PIN_SEL,PTD0>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTD0>
//     <4=> TPM0_CH0<selection=TPM0_CH0_PIN_SEL,PTD0>
//     <6=> FXIO0_D0<selection=FXIO0_D0_PIN_SEL,PTD0>
//     <-2=> Default
#define PTD0_SIG_SEL         -2

// Signal mapping for PTD1 pin
//   <o> PTD1 [ADC0_SE5b, GPIOD_1, SPI0_SCK, TPM0_CH1, FXIO0_D1]<name=PTD1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD1 pin
//     <-2=> ADC0_SE5b (reset default)<selection=ADC0_SE5b_PIN_SEL,PTD1 (reset default)>
//     <0=> ADC0_SE5b<selection=ADC0_SE5b_PIN_SEL,PTD1>
//     <1=> GPIOD_1<selection=GPIOD_1_PIN_SEL,PTD1>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTD1>
//     <4=> TPM0_CH1<selection=TPM0_CH1_PIN_SEL,PTD1>
//     <6=> FXIO0_D1<selection=FXIO0_D1_PIN_SEL,PTD1>
//     <-2=> Default
#define PTD1_SIG_SEL         -2

// Signal mapping for PTD2 pin
//   <o> PTD2 [GPIOD_2, SPI0_MOSI, UART2_RX, TPM0_CH2, SPI0_MISO, FXIO0_D2]<name=PTD2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD2 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_2<selection=GPIOD_2_PIN_SEL,PTD2>
//     <2=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTD2>
//     <3=> UART2_RX<selection=UART2_RX_PIN_SEL,PTD2>
//     <4=> TPM0_CH2<selection=TPM0_CH2_PIN_SEL,PTD2>
//     <5=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTD2>
//     <6=> FXIO0_D2<selection=FXIO0_D2_PIN_SEL,PTD2>
//     <-2=> Default
#define PTD2_SIG_SEL         -2

// Signal mapping for PTD3 pin
//   <o> PTD3 [GPIOD_3, SPI0_MISO, UART2_TX, TPM0_CH3, SPI0_MOSI, FXIO0_D3]<name=PTD3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD3 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_3<selection=GPIOD_3_PIN_SEL,PTD3>
//     <2=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTD3>
//     <3=> UART2_TX<selection=UART2_TX_PIN_SEL,PTD3>
//     <4=> TPM0_CH3<selection=TPM0_CH3_PIN_SEL,PTD3>
//     <5=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTD3>
//     <6=> FXIO0_D3<selection=FXIO0_D3_PIN_SEL,PTD3>
//     <-2=> Default
#define PTD3_SIG_SEL         -2

// Signal mapping for PTD4 pin
//   <o> PTD4 [GPIOD_4/LLWU_P14, SPI1_PCS0, UART2_RX, TPM0_CH4, FXIO0_D4]<name=PTD4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD4 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_4/LLWU_P14<selection=GPIOD_4_PIN_SEL,PTD4><selection=LLWU_P14_PIN_SEL,PTD4>
//     <2=> SPI1_PCS0<selection=SPI1_PCS0_PIN_SEL,PTD4>
//     <3=> UART2_RX<selection=UART2_RX_PIN_SEL,PTD4>
//     <4=> TPM0_CH4<selection=TPM0_CH4_PIN_SEL,PTD4>
//     <6=> FXIO0_D4<selection=FXIO0_D4_PIN_SEL,PTD4>
//     <-2=> Default
#define PTD4_SIG_SEL         -2

// Signal mapping for PTD5 pin
//   <o> PTD5 [ADC0_SE6b, GPIOD_5, SPI1_SCK, UART2_TX, TPM0_CH5, FXIO0_D5]<name=PTD5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD5 pin
//     <-2=> ADC0_SE6b (reset default)<selection=ADC0_SE6b_PIN_SEL,PTD5 (reset default)>
//     <0=> ADC0_SE6b<selection=ADC0_SE6b_PIN_SEL,PTD5>
//     <1=> GPIOD_5<selection=GPIOD_5_PIN_SEL,PTD5>
//     <2=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTD5>
//     <3=> UART2_TX<selection=UART2_TX_PIN_SEL,PTD5>
//     <4=> TPM0_CH5<selection=TPM0_CH5_PIN_SEL,PTD5>
//     <6=> FXIO0_D5<selection=FXIO0_D5_PIN_SEL,PTD5>
//     <-2=> Default
#define PTD5_SIG_SEL         -2

// Signal mapping for PTD6 pin
//   <o> PTD6 (Alias:D14, ONBOARD_SDA) [ADC0_SE7b, GPIOD_6/LLWU_P15, SPI1_MOSI, LPUART0_RX, I2C1_SDA, SPI1_MISO, FXIO0_D6]<name=PTD6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD6 pin
//     <-2=> ADC0_SE7b (reset default)<selection=ADC0_SE7b_PIN_SEL,PTD6 (Alias:D14, ONBOARD_SDA) (reset default)>
//     <0=> ADC0_SE7b<selection=ADC0_SE7b_PIN_SEL,PTD6 (Alias:D14, ONBOARD_SDA)>
//     <1=> GPIOD_6/LLWU_P15<selection=GPIOD_6_PIN_SEL,PTD6 (Alias:D14, ONBOARD_SDA)><selection=LLWU_P15_PIN_SEL,PTD6 (Alias:D14, ONBOARD_SDA)>
//     <2=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTD6 (Alias:D14, ONBOARD_SDA)>
//     <3=> LPUART0_RX<selection=LPUART0_RX_PIN_SEL,PTD6 (Alias:D14, ONBOARD_SDA)>
//     <4=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTD6 (Alias:D14, ONBOARD_SDA)>
//     <5=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTD6 (Alias:D14, ONBOARD_SDA)>
//     <6=> FXIO0_D6<selection=FXIO0_D6_PIN_SEL,PTD6 (Alias:D14, ONBOARD_SDA)>
//     <4=> Default
#define PTD6_SIG_SEL         4

// Signal mapping for PTD7 pin
//   <o> PTD7 (Alias:D15, ONBOARD_SCL) [GPIOD_7, SPI1_MISO, LPUART0_TX, I2C1_SCL, SPI1_MOSI, FXIO0_D7]<name=PTD7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD7 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_7<selection=GPIOD_7_PIN_SEL,PTD7 (Alias:D15, ONBOARD_SCL)>
//     <2=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTD7 (Alias:D15, ONBOARD_SCL)>
//     <3=> LPUART0_TX<selection=LPUART0_TX_PIN_SEL,PTD7 (Alias:D15, ONBOARD_SCL)>
//     <4=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTD7 (Alias:D15, ONBOARD_SCL)>
//     <5=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTD7 (Alias:D15, ONBOARD_SCL)>
//     <6=> FXIO0_D7<selection=FXIO0_D7_PIN_SEL,PTD7 (Alias:D15, ONBOARD_SCL)>
//     <4=> Default
#define PTD7_SIG_SEL         4

// </h>

// <h> Port E Pins

// Signal mapping for PTE0 pin
//   <o> PTE0 [GPIOE_0/CLKOUT32K, SPI1_MISO, LPUART1_TX, RTC_CLKOUT, CMP0_OUT, I2C1_SDA]<name=PTE0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE0 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_0/CLKOUT32K<selection=GPIOE_0_PIN_SEL,PTE0><selection=CLKOUT32K_PIN_SEL,PTE0>
//     <2=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTE0>
//     <3=> LPUART1_TX<selection=LPUART1_TX_PIN_SEL,PTE0>
//     <4=> RTC_CLKOUT<selection=RTC_CLKOUT_PIN_SEL,PTE0>
//     <5=> CMP0_OUT<selection=CMP0_OUT_PIN_SEL,PTE0>
//     <6=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTE0>
//     <-2=> Default
#define PTE0_SIG_SEL         -2

// Signal mapping for PTE1 pin
//   <o> PTE1 [GPIOE_1, SPI1_MOSI, LPUART1_RX, SPI1_MISO, I2C1_SCL]<name=PTE1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE1 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_1<selection=GPIOE_1_PIN_SEL,PTE1>
//     <2=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTE1>
//     <3=> LPUART1_RX<selection=LPUART1_RX_PIN_SEL,PTE1>
//     <5=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTE1>
//     <6=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTE1>
//     <-2=> Default
#define PTE1_SIG_SEL         -2

// Signal mapping for PTE16 pin
//   <o> PTE16 (Alias:A0) [ADC0_DP1/ADC0_SE1, GPIOE_16, SPI0_PCS0, UART2_TX, TPM_CLKIN0, FXIO0_D0]<name=PTE16_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE16 pin
//     <-2=> ADC0_DP1/ADC0_SE1 (reset default)<selection=ADC0_DP1_PIN_SEL,PTE16 (Alias:A0) (reset default)><selection=ADC0_SE1_PIN_SEL,PTE16 (Alias:A0) (reset default)>
//     <0=> ADC0_DP1/ADC0_SE1<selection=ADC0_DP1_PIN_SEL,PTE16 (Alias:A0)><selection=ADC0_SE1_PIN_SEL,PTE16 (Alias:A0)>
//     <1=> GPIOE_16<selection=GPIOE_16_PIN_SEL,PTE16 (Alias:A0)>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTE16 (Alias:A0)>
//     <3=> UART2_TX<selection=UART2_TX_PIN_SEL,PTE16 (Alias:A0)>
//     <4=> TPM_CLKIN0<selection=TPM_CLKIN0_PIN_SEL,PTE16 (Alias:A0)>
//     <6=> FXIO0_D0<selection=FXIO0_D0_PIN_SEL,PTE16 (Alias:A0)>
//     <0=> Default
#define PTE16_SIG_SEL        0

// Signal mapping for PTE17 pin
//   <o> PTE17 [ADC0_DM1/ADC0_SE5a, GPIOE_17, SPI0_SCK, UART2_RX, TPM_CLKIN1, LPTMR0_ALT3, FXIO0_D1]<name=PTE17_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE17 pin
//     <-2=> ADC0_DM1/ADC0_SE5a (reset default)<selection=ADC0_DM1_PIN_SEL,PTE17 (reset default)><selection=ADC0_SE5a_PIN_SEL,PTE17 (reset default)>
//     <0=> ADC0_DM1/ADC0_SE5a<selection=ADC0_DM1_PIN_SEL,PTE17><selection=ADC0_SE5a_PIN_SEL,PTE17>
//     <1=> GPIOE_17<selection=GPIOE_17_PIN_SEL,PTE17>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTE17>
//     <3=> UART2_RX<selection=UART2_RX_PIN_SEL,PTE17>
//     <4=> TPM_CLKIN1<selection=TPM_CLKIN1_PIN_SEL,PTE17>
//     <5=> LPTMR0_ALT3<selection=LPTMR0_ALT3_PIN_SEL,PTE17>
//     <6=> FXIO0_D1<selection=FXIO0_D1_PIN_SEL,PTE17>
//     <-2=> Default
#define PTE17_SIG_SEL        -2

// Signal mapping for PTE18 pin
//   <o> PTE18 [ADC0_DP2/ADC0_SE2, GPIOE_18, SPI0_MOSI, I2C0_SDA, SPI0_MISO, FXIO0_D2]<name=PTE18_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE18 pin
//     <-2=> ADC0_DP2/ADC0_SE2 (reset default)<selection=ADC0_DP2_PIN_SEL,PTE18 (reset default)><selection=ADC0_SE2_PIN_SEL,PTE18 (reset default)>
//     <0=> ADC0_DP2/ADC0_SE2<selection=ADC0_DP2_PIN_SEL,PTE18><selection=ADC0_SE2_PIN_SEL,PTE18>
//     <1=> GPIOE_18<selection=GPIOE_18_PIN_SEL,PTE18>
//     <2=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTE18>
//     <4=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTE18>
//     <5=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTE18>
//     <6=> FXIO0_D2<selection=FXIO0_D2_PIN_SEL,PTE18>
//     <-2=> Default
#define PTE18_SIG_SEL        -2

// Signal mapping for PTE20 pin
//   <o> PTE20 (Alias:A2) [ADC0_DP0/ADC0_SE0, GPIOE_20, TPM1_CH0, LPUART0_TX, FXIO0_D4]<name=PTE20_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE20 pin
//     <-2=> ADC0_DP0/ADC0_SE0 (reset default)<selection=ADC0_DP0_PIN_SEL,PTE20 (Alias:A2) (reset default)><selection=ADC0_SE0_PIN_SEL,PTE20 (Alias:A2) (reset default)>
//     <0=> ADC0_DP0/ADC0_SE0<selection=ADC0_DP0_PIN_SEL,PTE20 (Alias:A2)><selection=ADC0_SE0_PIN_SEL,PTE20 (Alias:A2)>
//     <1=> GPIOE_20<selection=GPIOE_20_PIN_SEL,PTE20 (Alias:A2)>
//     <3=> TPM1_CH0<selection=TPM1_CH0_PIN_SEL,PTE20 (Alias:A2)>
//     <4=> LPUART0_TX<selection=LPUART0_TX_PIN_SEL,PTE20 (Alias:A2)>
//     <6=> FXIO0_D4<selection=FXIO0_D4_PIN_SEL,PTE20 (Alias:A2)>
//     <0=> Default
#define PTE20_SIG_SEL        0

// Signal mapping for PTE21 pin
//   <o> PTE21 (Alias:A3) [ADC0_DM0/ADC0_SE4a, GPIOE_21, TPM1_CH1, LPUART0_RX, FXIO0_D5]<name=PTE21_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE21 pin
//     <-2=> ADC0_DM0/ADC0_SE4a (reset default)<selection=ADC0_DM0_PIN_SEL,PTE21 (Alias:A3) (reset default)><selection=ADC0_SE4a_PIN_SEL,PTE21 (Alias:A3) (reset default)>
//     <0=> ADC0_DM0/ADC0_SE4a<selection=ADC0_DM0_PIN_SEL,PTE21 (Alias:A3)><selection=ADC0_SE4a_PIN_SEL,PTE21 (Alias:A3)>
//     <1=> GPIOE_21<selection=GPIOE_21_PIN_SEL,PTE21 (Alias:A3)>
//     <3=> TPM1_CH1<selection=TPM1_CH1_PIN_SEL,PTE21 (Alias:A3)>
//     <4=> LPUART0_RX<selection=LPUART0_RX_PIN_SEL,PTE21 (Alias:A3)>
//     <6=> FXIO0_D5<selection=FXIO0_D5_PIN_SEL,PTE21 (Alias:A3)>
//     <0=> Default
#define PTE21_SIG_SEL        0

// Signal mapping for PTE22 pin
//   <o> PTE22 [ADC0_DP3/ADC0_SE3, GPIOE_22, TPM2_CH0, UART2_TX, FXIO0_D6]<name=PTE22_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE22 pin
//     <-2=> ADC0_DP3/ADC0_SE3 (reset default)<selection=ADC0_DP3_PIN_SEL,PTE22 (reset default)><selection=ADC0_SE3_PIN_SEL,PTE22 (reset default)>
//     <0=> ADC0_DP3/ADC0_SE3<selection=ADC0_DP3_PIN_SEL,PTE22><selection=ADC0_SE3_PIN_SEL,PTE22>
//     <1=> GPIOE_22<selection=GPIOE_22_PIN_SEL,PTE22>
//     <3=> TPM2_CH0<selection=TPM2_CH0_PIN_SEL,PTE22>
//     <4=> UART2_TX<selection=UART2_TX_PIN_SEL,PTE22>
//     <6=> FXIO0_D6<selection=FXIO0_D6_PIN_SEL,PTE22>
//     <-2=> Default
#define PTE22_SIG_SEL        -2

// Signal mapping for PTE23 pin
//   <o> PTE23 [ADC0_DM3/ADC0_SE7a, GPIOE_23, TPM2_CH1, UART2_RX, FXIO0_D7]<name=PTE23_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE23 pin
//     <-2=> ADC0_DM3/ADC0_SE7a (reset default)<selection=ADC0_DM3_PIN_SEL,PTE23 (reset default)><selection=ADC0_SE7a_PIN_SEL,PTE23 (reset default)>
//     <0=> ADC0_DM3/ADC0_SE7a<selection=ADC0_DM3_PIN_SEL,PTE23><selection=ADC0_SE7a_PIN_SEL,PTE23>
//     <1=> GPIOE_23<selection=GPIOE_23_PIN_SEL,PTE23>
//     <3=> TPM2_CH1<selection=TPM2_CH1_PIN_SEL,PTE23>
//     <4=> UART2_RX<selection=UART2_RX_PIN_SEL,PTE23>
//     <6=> FXIO0_D7<selection=FXIO0_D7_PIN_SEL,PTE23>
//     <-2=> Default
#define PTE23_SIG_SEL        -2

// Signal mapping for PTE24 pin
//   <o> PTE24 (Alias:D5) [GPIOE_24, TPM0_CH0, I2C0_SCL]<name=PTE24_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE24 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_24<selection=GPIOE_24_PIN_SEL,PTE24 (Alias:D5)>
//     <3=> TPM0_CH0<selection=TPM0_CH0_PIN_SEL,PTE24 (Alias:D5)>
//     <5=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTE24 (Alias:D5)>
//     <3=> Default
#define PTE24_SIG_SEL        3

// Signal mapping for PTE25 pin
//   <o> PTE25 (Alias:D3) [GPIOE_25, TPM0_CH1, I2C0_SDA]<name=PTE25_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE25 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_25<selection=GPIOE_25_PIN_SEL,PTE25 (Alias:D3)>
//     <3=> TPM0_CH1<selection=TPM0_CH1_PIN_SEL,PTE25 (Alias:D3)>
//     <5=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTE25 (Alias:D3)>
//     <3=> Default
#define PTE25_SIG_SEL        3

// Signal mapping for PTE29 pin
//   <o> PTE29 [CMP0_IN5/ADC0_SE4b, GPIOE_29, TPM0_CH2, TPM_CLKIN0]<name=PTE29_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE29 pin
//     <-2=> CMP0_IN5/ADC0_SE4b (reset default)<selection=CMP0_IN5_PIN_SEL,PTE29 (reset default)><selection=ADC0_SE4b_PIN_SEL,PTE29 (reset default)>
//     <0=> CMP0_IN5/ADC0_SE4b<selection=CMP0_IN5_PIN_SEL,PTE29><selection=ADC0_SE4b_PIN_SEL,PTE29>
//     <1=> GPIOE_29<selection=GPIOE_29_PIN_SEL,PTE29>
//     <3=> TPM0_CH2<selection=TPM0_CH2_PIN_SEL,PTE29>
//     <4=> TPM_CLKIN0<selection=TPM_CLKIN0_PIN_SEL,PTE29>
//     <-2=> Default
#define PTE29_SIG_SEL        -2

// Signal mapping for PTE30 pin
//   <o> PTE30 [ADC0_SE23/CMP0_IN4, GPIOE_30, TPM0_CH3, TPM_CLKIN1, LPUART1_TX, LPTMR0_ALT1]<name=PTE30_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE30 pin
//     <-2=> ADC0_SE23/CMP0_IN4 (reset default)<selection=ADC0_SE23_PIN_SEL,PTE30 (reset default)><selection=CMP0_IN4_PIN_SEL,PTE30 (reset default)>
//     <0=> ADC0_SE23/CMP0_IN4<selection=ADC0_SE23_PIN_SEL,PTE30><selection=CMP0_IN4_PIN_SEL,PTE30>
//     <1=> GPIOE_30<selection=GPIOE_30_PIN_SEL,PTE30>
//     <3=> TPM0_CH3<selection=TPM0_CH3_PIN_SEL,PTE30>
//     <4=> TPM_CLKIN1<selection=TPM_CLKIN1_PIN_SEL,PTE30>
//     <5=> LPUART1_TX<selection=LPUART1_TX_PIN_SEL,PTE30>
//     <6=> LPTMR0_ALT1<selection=LPTMR0_ALT1_PIN_SEL,PTE30>
//     <-2=> Default
#define PTE30_SIG_SEL        -2

// Signal mapping for PTE31 pin
//   <o> PTE31 (Alias:D8) [GPIOE_31, TPM0_CH4]<name=PTE31_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE31 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_31<selection=GPIOE_31_PIN_SEL,PTE31 (Alias:D8)>
//     <3=> TPM0_CH4<selection=TPM0_CH4_PIN_SEL,PTE31 (Alias:D8)>
//     <3=> Default
#define PTE31_SIG_SEL        3

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

// <h> Analogue to Digital (ADC0)

// Pin Mapping for ADC0_DM0 signal
//   <o> ADC0_DM0 [PTE21]<name=ADC0_DM0_PIN_SEL>
//   <i> Shows which pin ADC0_DM0 is mapped to
//     <0=> Disabled
//     <1=> PTE21 (Alias:A3) (reset default)<selection=PTE21_SIG_SEL,ADC0_DM0/ADC0_SE4a (reset default)>
//     <2=> PTE21 (Alias:A3)<selection=PTE21_SIG_SEL,ADC0_DM0/ADC0_SE4a>
//     <2=> Default
#define ADC0_DM0_PIN_SEL     2
#if (ADC0_DM0_PIN_SEL == 2)
#define ADC0_DM0_GPIO        USBDM::GpioE<21>
#define ADC0_DM0_FN          0
#endif

// Pin Mapping for ADC0_DM1 signal
//   <o> ADC0_DM1 [PTE17]<name=ADC0_DM1_PIN_SEL>
//   <i> Shows which pin ADC0_DM1 is mapped to
//     <0=> Disabled
//     <1=> PTE17 (reset default)<selection=PTE17_SIG_SEL,ADC0_DM1/ADC0_SE5a (reset default)>
//     <2=> PTE17<selection=PTE17_SIG_SEL,ADC0_DM1/ADC0_SE5a>
//     <1=> Default
#define ADC0_DM1_PIN_SEL     1
#if (ADC0_DM1_PIN_SEL == 2)
#define ADC0_DM1_GPIO        USBDM::GpioE<17>
#define ADC0_DM1_FN          0
#endif

// Pin Mapping for ADC0_DM3 signal
//   <o> ADC0_DM3 [PTE23]<name=ADC0_DM3_PIN_SEL>
//   <i> Shows which pin ADC0_DM3 is mapped to
//     <0=> Disabled
//     <1=> PTE23 (reset default)<selection=PTE23_SIG_SEL,ADC0_DM3/ADC0_SE7a (reset default)>
//     <2=> PTE23<selection=PTE23_SIG_SEL,ADC0_DM3/ADC0_SE7a>
//     <1=> Default
#define ADC0_DM3_PIN_SEL     1
#if (ADC0_DM3_PIN_SEL == 2)
#define ADC0_DM3_GPIO        USBDM::GpioE<23>
#define ADC0_DM3_FN          0
#endif

// Pin Mapping for ADC0_DP0 signal
//   <o> ADC0_DP0 [PTE20]<name=ADC0_DP0_PIN_SEL>
//   <i> Shows which pin ADC0_DP0 is mapped to
//     <0=> Disabled
//     <1=> PTE20 (Alias:A2) (reset default)<selection=PTE20_SIG_SEL,ADC0_DP0/ADC0_SE0 (reset default)>
//     <2=> PTE20 (Alias:A2)<selection=PTE20_SIG_SEL,ADC0_DP0/ADC0_SE0>
//     <2=> Default
#define ADC0_DP0_PIN_SEL     2
#if (ADC0_DP0_PIN_SEL == 2)
#define ADC0_DP0_GPIO        USBDM::GpioE<20>
#define ADC0_DP0_FN          0
#endif

// Pin Mapping for ADC0_DP1 signal
//   <o> ADC0_DP1 [PTE16]<name=ADC0_DP1_PIN_SEL>
//   <i> Shows which pin ADC0_DP1 is mapped to
//     <0=> Disabled
//     <1=> PTE16 (Alias:A0) (reset default)<selection=PTE16_SIG_SEL,ADC0_DP1/ADC0_SE1 (reset default)>
//     <2=> PTE16 (Alias:A0)<selection=PTE16_SIG_SEL,ADC0_DP1/ADC0_SE1>
//     <2=> Default
#define ADC0_DP1_PIN_SEL     2
#if (ADC0_DP1_PIN_SEL == 2)
#define ADC0_DP1_GPIO        USBDM::GpioE<16>
#define ADC0_DP1_FN          0
#endif

// Pin Mapping for ADC0_DP2 signal
//   <o> ADC0_DP2 [PTE18]<name=ADC0_DP2_PIN_SEL>
//   <i> Shows which pin ADC0_DP2 is mapped to
//     <0=> Disabled
//     <1=> PTE18 (reset default)<selection=PTE18_SIG_SEL,ADC0_DP2/ADC0_SE2 (reset default)>
//     <2=> PTE18<selection=PTE18_SIG_SEL,ADC0_DP2/ADC0_SE2>
//     <1=> Default
#define ADC0_DP2_PIN_SEL     1
#if (ADC0_DP2_PIN_SEL == 2)
#define ADC0_DP2_GPIO        USBDM::GpioE<18>
#define ADC0_DP2_FN          0
#endif

// Pin Mapping for ADC0_DP3 signal
//   <o> ADC0_DP3 [PTE22]<name=ADC0_DP3_PIN_SEL>
//   <i> Shows which pin ADC0_DP3 is mapped to
//     <0=> Disabled
//     <1=> PTE22 (reset default)<selection=PTE22_SIG_SEL,ADC0_DP3/ADC0_SE3 (reset default)>
//     <2=> PTE22<selection=PTE22_SIG_SEL,ADC0_DP3/ADC0_SE3>
//     <1=> Default
#define ADC0_DP3_PIN_SEL     1
#if (ADC0_DP3_PIN_SEL == 2)
#define ADC0_DP3_GPIO        USBDM::GpioE<22>
#define ADC0_DP3_FN          0
#endif

// Pin Mapping for ADC0_SE0 signal
//   <o> ADC0_SE0 [PTE20]<name=ADC0_SE0_PIN_SEL>
//   <i> Shows which pin ADC0_SE0 is mapped to
//     <0=> Disabled
//     <1=> PTE20 (Alias:A2) (reset default)<selection=PTE20_SIG_SEL,ADC0_DP0/ADC0_SE0 (reset default)>
//     <2=> PTE20 (Alias:A2)<selection=PTE20_SIG_SEL,ADC0_DP0/ADC0_SE0>
//     <2=> Default
#define ADC0_SE0_PIN_SEL     2

// Pin Mapping for ADC0_SE1 signal
//   <o> ADC0_SE1 [PTE16]<name=ADC0_SE1_PIN_SEL>
//   <i> Shows which pin ADC0_SE1 is mapped to
//     <0=> Disabled
//     <1=> PTE16 (Alias:A0) (reset default)<selection=PTE16_SIG_SEL,ADC0_DP1/ADC0_SE1 (reset default)>
//     <2=> PTE16 (Alias:A0)<selection=PTE16_SIG_SEL,ADC0_DP1/ADC0_SE1>
//     <2=> Default
#define ADC0_SE1_PIN_SEL     2

// Pin Mapping for ADC0_SE2 signal
//   <o> ADC0_SE2 [PTE18]<name=ADC0_SE2_PIN_SEL>
//   <i> Shows which pin ADC0_SE2 is mapped to
//     <0=> Disabled
//     <1=> PTE18 (reset default)<selection=PTE18_SIG_SEL,ADC0_DP2/ADC0_SE2 (reset default)>
//     <2=> PTE18<selection=PTE18_SIG_SEL,ADC0_DP2/ADC0_SE2>
//     <1=> Default
#define ADC0_SE2_PIN_SEL     1

// Pin Mapping for ADC0_SE3 signal
//   <o> ADC0_SE3 [PTE22]<name=ADC0_SE3_PIN_SEL>
//   <i> Shows which pin ADC0_SE3 is mapped to
//     <0=> Disabled
//     <1=> PTE22 (reset default)<selection=PTE22_SIG_SEL,ADC0_DP3/ADC0_SE3 (reset default)>
//     <2=> PTE22<selection=PTE22_SIG_SEL,ADC0_DP3/ADC0_SE3>
//     <1=> Default
#define ADC0_SE3_PIN_SEL     1

// Pin Mapping for ADC0_SE4b signal
//   <o> ADC0_SE4b [PTE29]<name=ADC0_SE4b_PIN_SEL>
//   <i> Shows which pin ADC0_SE4b is mapped to
//     <0=> Disabled
//     <1=> PTE29 (reset default)<selection=PTE29_SIG_SEL,CMP0_IN5/ADC0_SE4b (reset default)>
//     <2=> PTE29<selection=PTE29_SIG_SEL,CMP0_IN5/ADC0_SE4b>
//     <1=> Default
#define ADC0_SE4b_PIN_SEL    1

// Pin Mapping for ADC0_SE4a signal
//   <o> ADC0_SE4a [PTE21]<name=ADC0_SE4a_PIN_SEL>
//   <i> Shows which pin ADC0_SE4a is mapped to
//     <0=> Disabled
//     <1=> PTE21 (Alias:A3) (reset default)<selection=PTE21_SIG_SEL,ADC0_DM0/ADC0_SE4a (reset default)>
//     <2=> PTE21 (Alias:A3)<selection=PTE21_SIG_SEL,ADC0_DM0/ADC0_SE4a>
//     <2=> Default
#define ADC0_SE4a_PIN_SEL    2

// Pin Mapping for ADC0_SE5b signal
//   <o> ADC0_SE5b [PTD1]<name=ADC0_SE5b_PIN_SEL>
//   <i> Shows which pin ADC0_SE5b is mapped to
//     <0=> Disabled
//     <1=> PTD1 (reset default)<selection=PTD1_SIG_SEL,ADC0_SE5b (reset default)>
//     <2=> PTD1<selection=PTD1_SIG_SEL,ADC0_SE5b>
//     <1=> Default
#define ADC0_SE5b_PIN_SEL    1

// Pin Mapping for ADC0_SE5a signal
//   <o> ADC0_SE5a [PTE17]<name=ADC0_SE5a_PIN_SEL>
//   <i> Shows which pin ADC0_SE5a is mapped to
//     <0=> Disabled
//     <1=> PTE17 (reset default)<selection=PTE17_SIG_SEL,ADC0_DM1/ADC0_SE5a (reset default)>
//     <2=> PTE17<selection=PTE17_SIG_SEL,ADC0_DM1/ADC0_SE5a>
//     <1=> Default
#define ADC0_SE5a_PIN_SEL    1

// Pin Mapping for ADC0_SE6b signal
//   <o> ADC0_SE6b [PTD5]<name=ADC0_SE6b_PIN_SEL>
//   <i> Shows which pin ADC0_SE6b is mapped to
//     <0=> Disabled
//     <1=> PTD5 (reset default)<selection=PTD5_SIG_SEL,ADC0_SE6b (reset default)>
//     <2=> PTD5<selection=PTD5_SIG_SEL,ADC0_SE6b>
//     <1=> Default
#define ADC0_SE6b_PIN_SEL    1

// Pin Mapping for ADC0_SE7a signal
//   <o> ADC0_SE7a [PTE23]<name=ADC0_SE7a_PIN_SEL>
//   <i> Shows which pin ADC0_SE7a is mapped to
//     <0=> Disabled
//     <1=> PTE23 (reset default)<selection=PTE23_SIG_SEL,ADC0_DM3/ADC0_SE7a (reset default)>
//     <2=> PTE23<selection=PTE23_SIG_SEL,ADC0_DM3/ADC0_SE7a>
//     <1=> Default
#define ADC0_SE7a_PIN_SEL    1

// Pin Mapping for ADC0_SE7b signal
//   <o> ADC0_SE7b [PTD6]<name=ADC0_SE7b_PIN_SEL>
//   <i> Shows which pin ADC0_SE7b is mapped to
//     <0=> Disabled
//     <1=> PTD6 (Alias:D14, ONBOARD_SDA) (reset default)<selection=PTD6_SIG_SEL,ADC0_SE7b (reset default)>
//     <2=> PTD6 (Alias:D14, ONBOARD_SDA)<selection=PTD6_SIG_SEL,ADC0_SE7b>
//     <0=> Default
#define ADC0_SE7b_PIN_SEL    0

// Pin Mapping for ADC0_SE8 signal
//   <o> ADC0_SE8 [PTB0]<name=ADC0_SE8_PIN_SEL>
//   <i> Shows which pin ADC0_SE8 is mapped to
//     <0=> Disabled
//     <1=> PTB0 (Alias:A5) (reset default)<selection=PTB0_SIG_SEL,ADC0_SE8 (reset default)>
//     <2=> PTB0 (Alias:A5)<selection=PTB0_SIG_SEL,ADC0_SE8>
//     <2=> Default
#define ADC0_SE8_PIN_SEL     2

// Pin Mapping for ADC0_SE9 signal
//   <o> ADC0_SE9 [PTB1]<name=ADC0_SE9_PIN_SEL>
//   <i> Shows which pin ADC0_SE9 is mapped to
//     <0=> Disabled
//     <1=> PTB1 (Alias:A4) (reset default)<selection=PTB1_SIG_SEL,ADC0_SE9 (reset default)>
//     <2=> PTB1 (Alias:A4)<selection=PTB1_SIG_SEL,ADC0_SE9>
//     <2=> Default
#define ADC0_SE9_PIN_SEL     2

// Pin Mapping for ADC0_SE11 signal
//   <o> ADC0_SE11 [PTC2]<name=ADC0_SE11_PIN_SEL>
//   <i> Shows which pin ADC0_SE11 is mapped to
//     <0=> Disabled
//     <1=> PTC2 (Alias:MAG_INT) (reset default)<selection=PTC2_SIG_SEL,ADC0_SE11 (reset default)>
//     <2=> PTC2 (Alias:MAG_INT)<selection=PTC2_SIG_SEL,ADC0_SE11>
//     <1=> Default
#define ADC0_SE11_PIN_SEL    1

// Pin Mapping for ADC0_SE12 signal
//   <o> ADC0_SE12 [PTB2]<name=ADC0_SE12_PIN_SEL>
//   <i> Shows which pin ADC0_SE12 is mapped to
//     <0=> Disabled
//     <1=> PTB2 (reset default)<selection=PTB2_SIG_SEL,ADC0_SE12 (reset default)>
//     <2=> PTB2<selection=PTB2_SIG_SEL,ADC0_SE12>
//     <1=> Default
#define ADC0_SE12_PIN_SEL    1

// Pin Mapping for ADC0_SE13 signal
//   <o> ADC0_SE13 [PTB3]<name=ADC0_SE13_PIN_SEL>
//   <i> Shows which pin ADC0_SE13 is mapped to
//     <0=> Disabled
//     <1=> PTB3 (reset default)<selection=PTB3_SIG_SEL,ADC0_SE13 (reset default)>
//     <2=> PTB3<selection=PTB3_SIG_SEL,ADC0_SE13>
//     <1=> Default
#define ADC0_SE13_PIN_SEL    1

// Pin Mapping for ADC0_SE14 signal
//   <o> ADC0_SE14 [PTC0]<name=ADC0_SE14_PIN_SEL>
//   <i> Shows which pin ADC0_SE14 is mapped to
//     <0=> Disabled
//     <1=> PTC0 (Alias:A1) (reset default)<selection=PTC0_SIG_SEL,ADC0_SE14 (reset default)>
//     <2=> PTC0 (Alias:A1)<selection=PTC0_SIG_SEL,ADC0_SE14>
//     <2=> Default
#define ADC0_SE14_PIN_SEL    2

// Pin Mapping for ADC0_SE15 signal
//   <o> ADC0_SE15 [PTC1]<name=ADC0_SE15_PIN_SEL>
//   <i> Shows which pin ADC0_SE15 is mapped to
//     <0=> Disabled
//     <1=> PTC1 (reset default)<selection=PTC1_SIG_SEL,ADC0_SE15 (reset default)>
//     <2=> PTC1<selection=PTC1_SIG_SEL,ADC0_SE15>
//     <1=> Default
#define ADC0_SE15_PIN_SEL    1

// Pin Mapping for ADC0_SE23 signal
//   <o> ADC0_SE23 [PTE30]<name=ADC0_SE23_PIN_SEL>
//   <i> Shows which pin ADC0_SE23 is mapped to
//     <0=> Disabled
//     <1=> PTE30 (reset default)<selection=PTE30_SIG_SEL,ADC0_SE23/CMP0_IN4 (reset default)>
//     <2=> PTE30<selection=PTE30_SIG_SEL,ADC0_SE23/CMP0_IN4>
//     <1=> Default
#define ADC0_SE23_PIN_SEL    1

// </h>

// <h> Clock and Timing

// Pin Mapping for CLKOUT signal
//   <o> CLKOUT [PTC3]<name=CLKOUT_PIN_SEL>
//   <i> Shows which pin CLKOUT is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,CLKOUT>
//     <0=> Default
#define CLKOUT_PIN_SEL       0
#if (CLKOUT_PIN_SEL == 1)
#define CLKOUT_GPIO          USBDM::GpioC<3>
#define CLKOUT_FN            5
#endif

// Pin Mapping for CLKOUT32K signal
//   <o> CLKOUT32K [PTE0]<name=CLKOUT32K_PIN_SEL>
//   <i> Shows which pin CLKOUT32K is mapped to
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,GPIOE_0/CLKOUT32K>
//     <0=> Default
#define CLKOUT32K_PIN_SEL    0
#if (CLKOUT32K_PIN_SEL == 1)
#define CLKOUT32K_GPIO       USBDM::GpioE<0>
#define CLKOUT32K_FN         1
#endif

// Pin Mapping for EXTAL0 signal
//   <o> EXTAL0 [PTA18]<name=EXTAL0_PIN_SEL>
//   <i> Shows which pin EXTAL0 is mapped to
//     <0=> Disabled
//     <1=> PTA18 (reset default)<selection=PTA18_SIG_SEL,EXTAL0 (reset default)>
//     <2=> PTA18<selection=PTA18_SIG_SEL,EXTAL0>
//     <1=> Default
#define EXTAL0_PIN_SEL       1
#if (EXTAL0_PIN_SEL == 2)
#define EXTAL0_GPIO          USBDM::GpioA<18>
#define EXTAL0_FN            0
#endif

// Pin Mapping for EXTRG_IN signal
//   <o> EXTRG_IN [PTC0, PTC6]<name=EXTRG_IN_PIN_SEL>
//   <i> Shows which pin EXTRG_IN is mapped to
//     <0=> Disabled
//     <1=> PTC0 (Alias:A1)<selection=PTC0_SIG_SEL,EXTRG_IN>
//     <2=> PTC6 (Alias:D11)<selection=PTC6_SIG_SEL,EXTRG_IN>
//     <0=> Default
#define EXTRG_IN_PIN_SEL     0
#if (EXTRG_IN_PIN_SEL == 1)
#define EXTRG_IN_GPIO        USBDM::GpioC<0>
#define EXTRG_IN_FN          3
#elif (EXTRG_IN_PIN_SEL == 2)
#define EXTRG_IN_GPIO        USBDM::GpioC<6>
#define EXTRG_IN_FN          3
#endif

// Pin Mapping for RTC_CLKIN signal
//   <o> RTC_CLKIN [PTC1]<name=RTC_CLKIN_PIN_SEL>
//   <i> Shows which pin RTC_CLKIN is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,GPIOC_1/LLWU_P6/RTC_CLKIN>
//     <0=> Default
#define RTC_CLKIN_PIN_SEL    0
#if (RTC_CLKIN_PIN_SEL == 1)
#define RTC_CLKIN_GPIO       USBDM::GpioC<1>
#define RTC_CLKIN_FN         1
#endif

// Pin Mapping for RTC_CLKOUT signal
//   <o> RTC_CLKOUT [PTE0]<name=RTC_CLKOUT_PIN_SEL>
//   <i> Shows which pin RTC_CLKOUT is mapped to
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,RTC_CLKOUT>
//     <0=> Default
#define RTC_CLKOUT_PIN_SEL   0
#if (RTC_CLKOUT_PIN_SEL == 1)
#define RTC_CLKOUT_GPIO      USBDM::GpioE<0>
#define RTC_CLKOUT_FN        4
#endif

// Pin Mapping for TPM_CLKIN0 signal
//   <o> TPM_CLKIN0 [PTA18, PTB16, PTE16, PTE29]<name=TPM_CLKIN0_PIN_SEL>
//   <i> Shows which pin TPM_CLKIN0 is mapped to
//     <0=> Disabled
//     <1=> PTA18<selection=PTA18_SIG_SEL,TPM_CLKIN0>
//     <2=> PTB16<selection=PTB16_SIG_SEL,TPM_CLKIN0>
//     <3=> PTE16 (Alias:A0)<selection=PTE16_SIG_SEL,TPM_CLKIN0>
//     <4=> PTE29<selection=PTE29_SIG_SEL,TPM_CLKIN0>
//     <0=> Default
#define TPM_CLKIN0_PIN_SEL   0
#if (TPM_CLKIN0_PIN_SEL == 1)
#define TPM_CLKIN0_GPIO      USBDM::GpioA<18>
#define TPM_CLKIN0_FN        4
#elif (TPM_CLKIN0_PIN_SEL == 2)
#define TPM_CLKIN0_GPIO      USBDM::GpioB<16>
#define TPM_CLKIN0_FN        4
#elif (TPM_CLKIN0_PIN_SEL == 3)
#define TPM_CLKIN0_GPIO      USBDM::GpioE<16>
#define TPM_CLKIN0_FN        4
#elif (TPM_CLKIN0_PIN_SEL == 4)
#define TPM_CLKIN0_GPIO      USBDM::GpioE<29>
#define TPM_CLKIN0_FN        4
#endif

// Pin Mapping for TPM_CLKIN1 signal
//   <o> TPM_CLKIN1 [PTA19, PTB17, PTE17, PTE30]<name=TPM_CLKIN1_PIN_SEL>
//   <i> Shows which pin TPM_CLKIN1 is mapped to
//     <0=> Disabled
//     <1=> PTA19<selection=PTA19_SIG_SEL,TPM_CLKIN1>
//     <2=> PTB17<selection=PTB17_SIG_SEL,TPM_CLKIN1>
//     <3=> PTE17<selection=PTE17_SIG_SEL,TPM_CLKIN1>
//     <4=> PTE30<selection=PTE30_SIG_SEL,TPM_CLKIN1>
//     <0=> Default
#define TPM_CLKIN1_PIN_SEL   0
#if (TPM_CLKIN1_PIN_SEL == 1)
#define TPM_CLKIN1_GPIO      USBDM::GpioA<19>
#define TPM_CLKIN1_FN        4
#elif (TPM_CLKIN1_PIN_SEL == 2)
#define TPM_CLKIN1_GPIO      USBDM::GpioB<17>
#define TPM_CLKIN1_FN        4
#elif (TPM_CLKIN1_PIN_SEL == 3)
#define TPM_CLKIN1_GPIO      USBDM::GpioE<17>
#define TPM_CLKIN1_FN        4
#elif (TPM_CLKIN1_PIN_SEL == 4)
#define TPM_CLKIN1_GPIO      USBDM::GpioE<30>
#define TPM_CLKIN1_FN        4
#endif

// Pin Mapping for XTAL0 signal
//   <o> XTAL0 [PTA19]<name=XTAL0_PIN_SEL>
//   <i> Shows which pin XTAL0 is mapped to
//     <0=> Disabled
//     <1=> PTA19 (reset default)<selection=PTA19_SIG_SEL,XTAL0 (reset default)>
//     <2=> PTA19<selection=PTA19_SIG_SEL,XTAL0>
//     <1=> Default
#define XTAL0_PIN_SEL        1
#if (XTAL0_PIN_SEL == 2)
#define XTAL0_GPIO           USBDM::GpioA<19>
#define XTAL0_FN             0
#endif

// </h>

// <h> Analogue Comparator (CMP0)

// Pin Mapping for CMP0_IN0 signal
//   <o> CMP0_IN0 [PTC6]<name=CMP0_IN0_PIN_SEL>
//   <i> Shows which pin CMP0_IN0 is mapped to
//     <0=> Disabled
//     <1=> PTC6 (Alias:D11) (reset default)<selection=PTC6_SIG_SEL,CMP0_IN0 (reset default)>
//     <2=> PTC6 (Alias:D11)<selection=PTC6_SIG_SEL,CMP0_IN0>
//     <0=> Default
#define CMP0_IN0_PIN_SEL     0
#if (CMP0_IN0_PIN_SEL == 2)
#define CMP0_IN0_GPIO        USBDM::GpioC<6>
#define CMP0_IN0_FN          0
#endif

// Pin Mapping for CMP0_IN1 signal
//   <o> CMP0_IN1 [PTC7]<name=CMP0_IN1_PIN_SEL>
//   <i> Shows which pin CMP0_IN1 is mapped to
//     <0=> Disabled
//     <1=> PTC7 (Alias:D12) (reset default)<selection=PTC7_SIG_SEL,CMP0_IN1 (reset default)>
//     <2=> PTC7 (Alias:D12)<selection=PTC7_SIG_SEL,CMP0_IN1>
//     <0=> Default
#define CMP0_IN1_PIN_SEL     0
#if (CMP0_IN1_PIN_SEL == 2)
#define CMP0_IN1_GPIO        USBDM::GpioC<7>
#define CMP0_IN1_FN          0
#endif

// Pin Mapping for CMP0_IN2 signal
//   <o> CMP0_IN2 [PTC8]<name=CMP0_IN2_PIN_SEL>
//   <i> Shows which pin CMP0_IN2 is mapped to
//     <0=> Disabled
//     <1=> PTC8 (Alias:D7) (reset default)<selection=PTC8_SIG_SEL,CMP0_IN2 (reset default)>
//     <2=> PTC8 (Alias:D7)<selection=PTC8_SIG_SEL,CMP0_IN2>
//     <0=> Default
#define CMP0_IN2_PIN_SEL     0
#if (CMP0_IN2_PIN_SEL == 2)
#define CMP0_IN2_GPIO        USBDM::GpioC<8>
#define CMP0_IN2_FN          0
#endif

// Pin Mapping for CMP0_IN3 signal
//   <o> CMP0_IN3 [PTC9]<name=CMP0_IN3_PIN_SEL>
//   <i> Shows which pin CMP0_IN3 is mapped to
//     <0=> Disabled
//     <1=> PTC9 (Alias:D6) (reset default)<selection=PTC9_SIG_SEL,CMP0_IN3 (reset default)>
//     <2=> PTC9 (Alias:D6)<selection=PTC9_SIG_SEL,CMP0_IN3>
//     <0=> Default
#define CMP0_IN3_PIN_SEL     0
#if (CMP0_IN3_PIN_SEL == 2)
#define CMP0_IN3_GPIO        USBDM::GpioC<9>
#define CMP0_IN3_FN          0
#endif

// Pin Mapping for CMP0_IN4 signal
//   <o> CMP0_IN4 [PTE30]<name=CMP0_IN4_PIN_SEL>
//   <i> Shows which pin CMP0_IN4 is mapped to
//     <0=> Disabled
//     <1=> PTE30 (reset default)<selection=PTE30_SIG_SEL,ADC0_SE23/CMP0_IN4 (reset default)>
//     <2=> PTE30<selection=PTE30_SIG_SEL,ADC0_SE23/CMP0_IN4>
//     <1=> Default
#define CMP0_IN4_PIN_SEL     1
#if (CMP0_IN4_PIN_SEL == 2)
#define CMP0_IN4_GPIO        USBDM::GpioE<30>
#define CMP0_IN4_FN          0
#endif

// Pin Mapping for CMP0_IN5 signal
//   <o> CMP0_IN5 [PTE29]<name=CMP0_IN5_PIN_SEL>
//   <i> Shows which pin CMP0_IN5 is mapped to
//     <0=> Disabled
//     <1=> PTE29 (reset default)<selection=PTE29_SIG_SEL,CMP0_IN5/ADC0_SE4b (reset default)>
//     <2=> PTE29<selection=PTE29_SIG_SEL,CMP0_IN5/ADC0_SE4b>
//     <1=> Default
#define CMP0_IN5_PIN_SEL     1
#if (CMP0_IN5_PIN_SEL == 2)
#define CMP0_IN5_GPIO        USBDM::GpioE<29>
#define CMP0_IN5_FN          0
#endif

// Pin Mapping for CMP0_OUT signal
//   <o> CMP0_OUT [PTC0, PTE0, PTC5]<name=CMP0_OUT_PIN_SEL>
//   <i> Shows which pin CMP0_OUT is mapped to
//     <0=> Disabled
//     <1=> PTC0 (Alias:A1)<selection=PTC0_SIG_SEL,CMP0_OUT>
//     <2=> PTE0<selection=PTE0_SIG_SEL,CMP0_OUT>
//     <3=> PTC5 (Alias:D13)<selection=PTC5_SIG_SEL,CMP0_OUT>
//     <0=> Default
#define CMP0_OUT_PIN_SEL     0
#if (CMP0_OUT_PIN_SEL == 1)
#define CMP0_OUT_GPIO        USBDM::GpioC<0>
#define CMP0_OUT_FN          5
#elif (CMP0_OUT_PIN_SEL == 2)
#define CMP0_OUT_GPIO        USBDM::GpioE<0>
#define CMP0_OUT_FN          5
#elif (CMP0_OUT_PIN_SEL == 3)
#define CMP0_OUT_GPIO        USBDM::GpioC<5>
#define CMP0_OUT_FN          6
#endif

// </h>

// <h> Flexbus (FXIO0)

// Pin Mapping for FXIO0_D0 signal
//   <o> FXIO0_D0 [PTD0, PTE16]<name=FXIO0_D0_PIN_SEL>
//   <i> Shows which pin FXIO0_D0 is mapped to
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,FXIO0_D0>
//     <2=> PTE16 (Alias:A0)<selection=PTE16_SIG_SEL,FXIO0_D0>
//     <0=> Default
#define FXIO0_D0_PIN_SEL     0
#if (FXIO0_D0_PIN_SEL == 1)
#define FXIO0_D0_GPIO        USBDM::GpioD<0>
#define FXIO0_D0_FN          6
#elif (FXIO0_D0_PIN_SEL == 2)
#define FXIO0_D0_GPIO        USBDM::GpioE<16>
#define FXIO0_D0_FN          6
#endif

// Pin Mapping for FXIO0_D1 signal
//   <o> FXIO0_D1 [PTD1, PTE17]<name=FXIO0_D1_PIN_SEL>
//   <i> Shows which pin FXIO0_D1 is mapped to
//     <0=> Disabled
//     <1=> PTD1<selection=PTD1_SIG_SEL,FXIO0_D1>
//     <2=> PTE17<selection=PTE17_SIG_SEL,FXIO0_D1>
//     <0=> Default
#define FXIO0_D1_PIN_SEL     0
#if (FXIO0_D1_PIN_SEL == 1)
#define FXIO0_D1_GPIO        USBDM::GpioD<1>
#define FXIO0_D1_FN          6
#elif (FXIO0_D1_PIN_SEL == 2)
#define FXIO0_D1_GPIO        USBDM::GpioE<17>
#define FXIO0_D1_FN          6
#endif

// Pin Mapping for FXIO0_D2 signal
//   <o> FXIO0_D2 [PTD2, PTE18]<name=FXIO0_D2_PIN_SEL>
//   <i> Shows which pin FXIO0_D2 is mapped to
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,FXIO0_D2>
//     <2=> PTE18<selection=PTE18_SIG_SEL,FXIO0_D2>
//     <0=> Default
#define FXIO0_D2_PIN_SEL     0
#if (FXIO0_D2_PIN_SEL == 1)
#define FXIO0_D2_GPIO        USBDM::GpioD<2>
#define FXIO0_D2_FN          6
#elif (FXIO0_D2_PIN_SEL == 2)
#define FXIO0_D2_GPIO        USBDM::GpioE<18>
#define FXIO0_D2_FN          6
#endif

// Pin Mapping for FXIO0_D3 signal
//   <o> FXIO0_D3 [PTD3]<name=FXIO0_D3_PIN_SEL>
//   <i> Shows which pin FXIO0_D3 is mapped to
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,FXIO0_D3>
//     <0=> Default
#define FXIO0_D3_PIN_SEL     0
#if (FXIO0_D3_PIN_SEL == 1)
#define FXIO0_D3_GPIO        USBDM::GpioD<3>
#define FXIO0_D3_FN          6
#endif

// Pin Mapping for FXIO0_D4 signal
//   <o> FXIO0_D4 [PTD4, PTE20]<name=FXIO0_D4_PIN_SEL>
//   <i> Shows which pin FXIO0_D4 is mapped to
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,FXIO0_D4>
//     <2=> PTE20 (Alias:A2)<selection=PTE20_SIG_SEL,FXIO0_D4>
//     <0=> Default
#define FXIO0_D4_PIN_SEL     0
#if (FXIO0_D4_PIN_SEL == 1)
#define FXIO0_D4_GPIO        USBDM::GpioD<4>
#define FXIO0_D4_FN          6
#elif (FXIO0_D4_PIN_SEL == 2)
#define FXIO0_D4_GPIO        USBDM::GpioE<20>
#define FXIO0_D4_FN          6
#endif

// Pin Mapping for FXIO0_D5 signal
//   <o> FXIO0_D5 [PTD5, PTE21]<name=FXIO0_D5_PIN_SEL>
//   <i> Shows which pin FXIO0_D5 is mapped to
//     <0=> Disabled
//     <1=> PTD5<selection=PTD5_SIG_SEL,FXIO0_D5>
//     <2=> PTE21 (Alias:A3)<selection=PTE21_SIG_SEL,FXIO0_D5>
//     <0=> Default
#define FXIO0_D5_PIN_SEL     0
#if (FXIO0_D5_PIN_SEL == 1)
#define FXIO0_D5_GPIO        USBDM::GpioD<5>
#define FXIO0_D5_FN          6
#elif (FXIO0_D5_PIN_SEL == 2)
#define FXIO0_D5_GPIO        USBDM::GpioE<21>
#define FXIO0_D5_FN          6
#endif

// Pin Mapping for FXIO0_D6 signal
//   <o> FXIO0_D6 [PTD6, PTE22]<name=FXIO0_D6_PIN_SEL>
//   <i> Shows which pin FXIO0_D6 is mapped to
//     <0=> Disabled
//     <1=> PTD6 (Alias:D14, ONBOARD_SDA)<selection=PTD6_SIG_SEL,FXIO0_D6>
//     <2=> PTE22<selection=PTE22_SIG_SEL,FXIO0_D6>
//     <0=> Default
#define FXIO0_D6_PIN_SEL     0
#if (FXIO0_D6_PIN_SEL == 1)
#define FXIO0_D6_GPIO        USBDM::GpioD<6>
#define FXIO0_D6_FN          6
#elif (FXIO0_D6_PIN_SEL == 2)
#define FXIO0_D6_GPIO        USBDM::GpioE<22>
#define FXIO0_D6_FN          6
#endif

// Pin Mapping for FXIO0_D7 signal
//   <o> FXIO0_D7 [PTD7, PTE23]<name=FXIO0_D7_PIN_SEL>
//   <i> Shows which pin FXIO0_D7 is mapped to
//     <0=> Disabled
//     <1=> PTD7 (Alias:D15, ONBOARD_SCL)<selection=PTD7_SIG_SEL,FXIO0_D7>
//     <2=> PTE23<selection=PTE23_SIG_SEL,FXIO0_D7>
//     <0=> Default
#define FXIO0_D7_PIN_SEL     0
#if (FXIO0_D7_PIN_SEL == 1)
#define FXIO0_D7_GPIO        USBDM::GpioD<7>
#define FXIO0_D7_FN          6
#elif (FXIO0_D7_PIN_SEL == 2)
#define FXIO0_D7_GPIO        USBDM::GpioE<23>
#define FXIO0_D7_FN          6
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
#define GPIOA_0_FN           1
#endif

// Pin Mapping for GPIOA_1 signal
//   <o> GPIOA_1 [PTA1]<name=GPIOA_1_PIN_SEL>
//   <i> Shows which pin GPIOA_1 is mapped to
//     <0=> Disabled
//     <1=> PTA1 (Alias:D0)<selection=PTA1_SIG_SEL,GPIOA_1>
//     <0=> Default
#define GPIOA_1_PIN_SEL      0
#if (GPIOA_1_PIN_SEL == 1)
#define GPIOA_1_GPIO         USBDM::GpioA<1>
#define GPIOA_1_FN           1
#endif

// Pin Mapping for GPIOA_2 signal
//   <o> GPIOA_2 [PTA2]<name=GPIOA_2_PIN_SEL>
//   <i> Shows which pin GPIOA_2 is mapped to
//     <0=> Disabled
//     <1=> PTA2 (Alias:D1)<selection=PTA2_SIG_SEL,GPIOA_2>
//     <0=> Default
#define GPIOA_2_PIN_SEL      0
#if (GPIOA_2_PIN_SEL == 1)
#define GPIOA_2_GPIO         USBDM::GpioA<2>
#define GPIOA_2_FN           1
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
#define GPIOA_3_FN           1
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
#define GPIOA_4_FN           1
#endif

// Pin Mapping for GPIOA_5 signal
//   <o> GPIOA_5 [PTA5]<name=GPIOA_5_PIN_SEL>
//   <i> Shows which pin GPIOA_5 is mapped to
//     <0=> Disabled
//     <1=> PTA5 (Alias:D9)<selection=PTA5_SIG_SEL,GPIOA_5>
//     <0=> Default
#define GPIOA_5_PIN_SEL      0
#if (GPIOA_5_PIN_SEL == 1)
#define GPIOA_5_GPIO         USBDM::GpioA<5>
#define GPIOA_5_FN           1
#endif

// Pin Mapping for GPIOA_12 signal
//   <o> GPIOA_12 [PTA12]<name=GPIOA_12_PIN_SEL>
//   <i> Shows which pin GPIOA_12 is mapped to
//     <0=> Disabled
//     <1=> PTA12 (Alias:D2)<selection=PTA12_SIG_SEL,GPIOA_12>
//     <0=> Default
#define GPIOA_12_PIN_SEL     0
#if (GPIOA_12_PIN_SEL == 1)
#define GPIOA_12_GPIO        USBDM::GpioA<12>
#define GPIOA_12_FN          1
#endif

// Pin Mapping for GPIOA_13 signal
//   <o> GPIOA_13 [PTA13]<name=GPIOA_13_PIN_SEL>
//   <i> Shows which pin GPIOA_13 is mapped to
//     <0=> Disabled
//     <1=> PTA13 (Alias:D4, LED_BLUE)<selection=PTA13_SIG_SEL,GPIOA_13>
//     <0=> Default
#define GPIOA_13_PIN_SEL     0
#if (GPIOA_13_PIN_SEL == 1)
#define GPIOA_13_GPIO        USBDM::GpioA<13>
#define GPIOA_13_FN          1
#endif

// Pin Mapping for GPIOA_18 signal
//   <o> GPIOA_18 [PTA18]<name=GPIOA_18_PIN_SEL>
//   <i> Shows which pin GPIOA_18 is mapped to
//     <0=> Disabled
//     <1=> PTA18<selection=PTA18_SIG_SEL,GPIOA_18>
//     <0=> Default
#define GPIOA_18_PIN_SEL     0
#if (GPIOA_18_PIN_SEL == 1)
#define GPIOA_18_GPIO        USBDM::GpioA<18>
#define GPIOA_18_FN          1
#endif

// Pin Mapping for GPIOA_19 signal
//   <o> GPIOA_19 [PTA19]<name=GPIOA_19_PIN_SEL>
//   <i> Shows which pin GPIOA_19 is mapped to
//     <0=> Disabled
//     <1=> PTA19<selection=PTA19_SIG_SEL,GPIOA_19>
//     <0=> Default
#define GPIOA_19_PIN_SEL     0
#if (GPIOA_19_PIN_SEL == 1)
#define GPIOA_19_GPIO        USBDM::GpioA<19>
#define GPIOA_19_FN          1
#endif

// Pin Mapping for GPIOA_20 signal
//   <o> GPIOA_20 [PTA20]<name=GPIOA_20_PIN_SEL>
//   <i> Shows which pin GPIOA_20 is mapped to
//     <0=> Disabled
//     <1=> PTA20<selection=PTA20_SIG_SEL,GPIOA_20>
//     <0=> Default
#define GPIOA_20_PIN_SEL     0
#if (GPIOA_20_PIN_SEL == 1)
#define GPIOA_20_GPIO        USBDM::GpioA<20>
#define GPIOA_20_FN          1
#endif

// </h>

// <h> General Purpose I/O (GPIOB)

// Pin Mapping for GPIOB_0 signal
//   <o> GPIOB_0 [PTB0]<name=GPIOB_0_PIN_SEL>
//   <i> Shows which pin GPIOB_0 is mapped to
//     <0=> Disabled
//     <1=> PTB0 (Alias:A5)<selection=PTB0_SIG_SEL,GPIOB_0/LLWU_P5>
//     <0=> Default
#define GPIOB_0_PIN_SEL      0
#if (GPIOB_0_PIN_SEL == 1)
#define GPIOB_0_GPIO         USBDM::GpioB<0>
#define GPIOB_0_FN           1
#endif

// Pin Mapping for GPIOB_1 signal
//   <o> GPIOB_1 [PTB1]<name=GPIOB_1_PIN_SEL>
//   <i> Shows which pin GPIOB_1 is mapped to
//     <0=> Disabled
//     <1=> PTB1 (Alias:A4)<selection=PTB1_SIG_SEL,GPIOB_1>
//     <0=> Default
#define GPIOB_1_PIN_SEL      0
#if (GPIOB_1_PIN_SEL == 1)
#define GPIOB_1_GPIO         USBDM::GpioB<1>
#define GPIOB_1_FN           1
#endif

// Pin Mapping for GPIOB_2 signal
//   <o> GPIOB_2 [PTB2]<name=GPIOB_2_PIN_SEL>
//   <i> Shows which pin GPIOB_2 is mapped to
//     <0=> Disabled
//     <1=> PTB2<selection=PTB2_SIG_SEL,GPIOB_2>
//     <0=> Default
#define GPIOB_2_PIN_SEL      0
#if (GPIOB_2_PIN_SEL == 1)
#define GPIOB_2_GPIO         USBDM::GpioB<2>
#define GPIOB_2_FN           1
#endif

// Pin Mapping for GPIOB_3 signal
//   <o> GPIOB_3 [PTB3]<name=GPIOB_3_PIN_SEL>
//   <i> Shows which pin GPIOB_3 is mapped to
//     <0=> Disabled
//     <1=> PTB3<selection=PTB3_SIG_SEL,GPIOB_3>
//     <0=> Default
#define GPIOB_3_PIN_SEL      0
#if (GPIOB_3_PIN_SEL == 1)
#define GPIOB_3_GPIO         USBDM::GpioB<3>
#define GPIOB_3_FN           1
#endif

// Pin Mapping for GPIOB_16 signal
//   <o> GPIOB_16 [PTB16]<name=GPIOB_16_PIN_SEL>
//   <i> Shows which pin GPIOB_16 is mapped to
//     <0=> Disabled
//     <1=> PTB16<selection=PTB16_SIG_SEL,GPIOB_16>
//     <0=> Default
#define GPIOB_16_PIN_SEL     0
#if (GPIOB_16_PIN_SEL == 1)
#define GPIOB_16_GPIO        USBDM::GpioB<16>
#define GPIOB_16_FN          1
#endif

// Pin Mapping for GPIOB_17 signal
//   <o> GPIOB_17 [PTB17]<name=GPIOB_17_PIN_SEL>
//   <i> Shows which pin GPIOB_17 is mapped to
//     <0=> Disabled
//     <1=> PTB17<selection=PTB17_SIG_SEL,GPIOB_17>
//     <0=> Default
#define GPIOB_17_PIN_SEL     0
#if (GPIOB_17_PIN_SEL == 1)
#define GPIOB_17_GPIO        USBDM::GpioB<17>
#define GPIOB_17_FN          1
#endif

// Pin Mapping for GPIOB_18 signal
//   <o> GPIOB_18 [PTB18]<name=GPIOB_18_PIN_SEL>
//   <i> Shows which pin GPIOB_18 is mapped to
//     <0=> Disabled
//     <1=> PTB18 (Alias:LED_RED)<selection=PTB18_SIG_SEL,GPIOB_18>
//     <0=> Default
#define GPIOB_18_PIN_SEL     0
#if (GPIOB_18_PIN_SEL == 1)
#define GPIOB_18_GPIO        USBDM::GpioB<18>
#define GPIOB_18_FN          1
#endif

// Pin Mapping for GPIOB_19 signal
//   <o> GPIOB_19 [PTB19]<name=GPIOB_19_PIN_SEL>
//   <i> Shows which pin GPIOB_19 is mapped to
//     <0=> Disabled
//     <1=> PTB19 (Alias:LED_GREEN)<selection=PTB19_SIG_SEL,GPIOB_19>
//     <0=> Default
#define GPIOB_19_PIN_SEL     0
#if (GPIOB_19_PIN_SEL == 1)
#define GPIOB_19_GPIO        USBDM::GpioB<19>
#define GPIOB_19_FN          1
#endif

// </h>

// <h> General Purpose I/O (GPIOC)

// Pin Mapping for GPIOC_0 signal
//   <o> GPIOC_0 [PTC0]<name=GPIOC_0_PIN_SEL>
//   <i> Shows which pin GPIOC_0 is mapped to
//     <0=> Disabled
//     <1=> PTC0 (Alias:A1)<selection=PTC0_SIG_SEL,GPIOC_0>
//     <0=> Default
#define GPIOC_0_PIN_SEL      0
#if (GPIOC_0_PIN_SEL == 1)
#define GPIOC_0_GPIO         USBDM::GpioC<0>
#define GPIOC_0_FN           1
#endif

// Pin Mapping for GPIOC_1 signal
//   <o> GPIOC_1 [PTC1]<name=GPIOC_1_PIN_SEL>
//   <i> Shows which pin GPIOC_1 is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,GPIOC_1/LLWU_P6/RTC_CLKIN>
//     <0=> Default
#define GPIOC_1_PIN_SEL      0
#if (GPIOC_1_PIN_SEL == 1)
#define GPIOC_1_GPIO         USBDM::GpioC<1>
#define GPIOC_1_FN           1
#endif

// Pin Mapping for GPIOC_2 signal
//   <o> GPIOC_2 [PTC2]<name=GPIOC_2_PIN_SEL>
//   <i> Shows which pin GPIOC_2 is mapped to
//     <0=> Disabled
//     <1=> PTC2 (Alias:MAG_INT)<selection=PTC2_SIG_SEL,GPIOC_2>
//     <0=> Default
#define GPIOC_2_PIN_SEL      0
#if (GPIOC_2_PIN_SEL == 1)
#define GPIOC_2_GPIO         USBDM::GpioC<2>
#define GPIOC_2_FN           1
#endif

// Pin Mapping for GPIOC_3 signal
//   <o> GPIOC_3 [PTC3]<name=GPIOC_3_PIN_SEL>
//   <i> Shows which pin GPIOC_3 is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,GPIOC_3/LLWU_P7>
//     <0=> Default
#define GPIOC_3_PIN_SEL      0
#if (GPIOC_3_PIN_SEL == 1)
#define GPIOC_3_GPIO         USBDM::GpioC<3>
#define GPIOC_3_FN           1
#endif

// Pin Mapping for GPIOC_4 signal
//   <o> GPIOC_4 [PTC4]<name=GPIOC_4_PIN_SEL>
//   <i> Shows which pin GPIOC_4 is mapped to
//     <0=> Disabled
//     <1=> PTC4 (Alias:D10)<selection=PTC4_SIG_SEL,GPIOC_4/LLWU_P8>
//     <1=> Default
#define GPIOC_4_PIN_SEL      1
#if (GPIOC_4_PIN_SEL == 1)
#define GPIOC_4_GPIO         USBDM::GpioC<4>
#define GPIOC_4_FN           1
#endif

// Pin Mapping for GPIOC_5 signal
//   <o> GPIOC_5 [PTC5]<name=GPIOC_5_PIN_SEL>
//   <i> Shows which pin GPIOC_5 is mapped to
//     <0=> Disabled
//     <1=> PTC5 (Alias:D13)<selection=PTC5_SIG_SEL,GPIOC_5/LLWU_P9>
//     <1=> Default
#define GPIOC_5_PIN_SEL      1
#if (GPIOC_5_PIN_SEL == 1)
#define GPIOC_5_GPIO         USBDM::GpioC<5>
#define GPIOC_5_FN           1
#endif

// Pin Mapping for GPIOC_6 signal
//   <o> GPIOC_6 [PTC6]<name=GPIOC_6_PIN_SEL>
//   <i> Shows which pin GPIOC_6 is mapped to
//     <0=> Disabled
//     <1=> PTC6 (Alias:D11)<selection=PTC6_SIG_SEL,GPIOC_6/LLWU_P10>
//     <1=> Default
#define GPIOC_6_PIN_SEL      1
#if (GPIOC_6_PIN_SEL == 1)
#define GPIOC_6_GPIO         USBDM::GpioC<6>
#define GPIOC_6_FN           1
#endif

// Pin Mapping for GPIOC_7 signal
//   <o> GPIOC_7 [PTC7]<name=GPIOC_7_PIN_SEL>
//   <i> Shows which pin GPIOC_7 is mapped to
//     <0=> Disabled
//     <1=> PTC7 (Alias:D12)<selection=PTC7_SIG_SEL,GPIOC_7>
//     <1=> Default
#define GPIOC_7_PIN_SEL      1
#if (GPIOC_7_PIN_SEL == 1)
#define GPIOC_7_GPIO         USBDM::GpioC<7>
#define GPIOC_7_FN           1
#endif

// Pin Mapping for GPIOC_8 signal
//   <o> GPIOC_8 [PTC8]<name=GPIOC_8_PIN_SEL>
//   <i> Shows which pin GPIOC_8 is mapped to
//     <0=> Disabled
//     <1=> PTC8 (Alias:D7)<selection=PTC8_SIG_SEL,GPIOC_8>
//     <1=> Default
#define GPIOC_8_PIN_SEL      1
#if (GPIOC_8_PIN_SEL == 1)
#define GPIOC_8_GPIO         USBDM::GpioC<8>
#define GPIOC_8_FN           1
#endif

// Pin Mapping for GPIOC_9 signal
//   <o> GPIOC_9 [PTC9]<name=GPIOC_9_PIN_SEL>
//   <i> Shows which pin GPIOC_9 is mapped to
//     <0=> Disabled
//     <1=> PTC9 (Alias:D6)<selection=PTC9_SIG_SEL,GPIOC_9>
//     <1=> Default
#define GPIOC_9_PIN_SEL      1
#if (GPIOC_9_PIN_SEL == 1)
#define GPIOC_9_GPIO         USBDM::GpioC<9>
#define GPIOC_9_FN           1
#endif

// Pin Mapping for GPIOC_10 signal
//   <o> GPIOC_10 [PTC10]<name=GPIOC_10_PIN_SEL>
//   <i> Shows which pin GPIOC_10 is mapped to
//     <0=> Disabled
//     <1=> PTC10<selection=PTC10_SIG_SEL,GPIOC_10>
//     <0=> Default
#define GPIOC_10_PIN_SEL     0
#if (GPIOC_10_PIN_SEL == 1)
#define GPIOC_10_GPIO        USBDM::GpioC<10>
#define GPIOC_10_FN          1
#endif

// Pin Mapping for GPIOC_11 signal
//   <o> GPIOC_11 [PTC11]<name=GPIOC_11_PIN_SEL>
//   <i> Shows which pin GPIOC_11 is mapped to
//     <0=> Disabled
//     <1=> PTC11<selection=PTC11_SIG_SEL,GPIOC_11>
//     <0=> Default
#define GPIOC_11_PIN_SEL     0
#if (GPIOC_11_PIN_SEL == 1)
#define GPIOC_11_GPIO        USBDM::GpioC<11>
#define GPIOC_11_FN          1
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
#if (GPIOD_0_PIN_SEL == 1)
#define GPIOD_0_GPIO         USBDM::GpioD<0>
#define GPIOD_0_FN           1
#endif

// Pin Mapping for GPIOD_1 signal
//   <o> GPIOD_1 [PTD1]<name=GPIOD_1_PIN_SEL>
//   <i> Shows which pin GPIOD_1 is mapped to
//     <0=> Disabled
//     <1=> PTD1<selection=PTD1_SIG_SEL,GPIOD_1>
//     <0=> Default
#define GPIOD_1_PIN_SEL      0
#if (GPIOD_1_PIN_SEL == 1)
#define GPIOD_1_GPIO         USBDM::GpioD<1>
#define GPIOD_1_FN           1
#endif

// Pin Mapping for GPIOD_2 signal
//   <o> GPIOD_2 [PTD2]<name=GPIOD_2_PIN_SEL>
//   <i> Shows which pin GPIOD_2 is mapped to
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,GPIOD_2>
//     <0=> Default
#define GPIOD_2_PIN_SEL      0
#if (GPIOD_2_PIN_SEL == 1)
#define GPIOD_2_GPIO         USBDM::GpioD<2>
#define GPIOD_2_FN           1
#endif

// Pin Mapping for GPIOD_3 signal
//   <o> GPIOD_3 [PTD3]<name=GPIOD_3_PIN_SEL>
//   <i> Shows which pin GPIOD_3 is mapped to
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,GPIOD_3>
//     <0=> Default
#define GPIOD_3_PIN_SEL      0
#if (GPIOD_3_PIN_SEL == 1)
#define GPIOD_3_GPIO         USBDM::GpioD<3>
#define GPIOD_3_FN           1
#endif

// Pin Mapping for GPIOD_4 signal
//   <o> GPIOD_4 [PTD4]<name=GPIOD_4_PIN_SEL>
//   <i> Shows which pin GPIOD_4 is mapped to
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,GPIOD_4/LLWU_P14>
//     <0=> Default
#define GPIOD_4_PIN_SEL      0
#if (GPIOD_4_PIN_SEL == 1)
#define GPIOD_4_GPIO         USBDM::GpioD<4>
#define GPIOD_4_FN           1
#endif

// Pin Mapping for GPIOD_5 signal
//   <o> GPIOD_5 [PTD5]<name=GPIOD_5_PIN_SEL>
//   <i> Shows which pin GPIOD_5 is mapped to
//     <0=> Disabled
//     <1=> PTD5<selection=PTD5_SIG_SEL,GPIOD_5>
//     <0=> Default
#define GPIOD_5_PIN_SEL      0
#if (GPIOD_5_PIN_SEL == 1)
#define GPIOD_5_GPIO         USBDM::GpioD<5>
#define GPIOD_5_FN           1
#endif

// Pin Mapping for GPIOD_6 signal
//   <o> GPIOD_6 [PTD6]<name=GPIOD_6_PIN_SEL>
//   <i> Shows which pin GPIOD_6 is mapped to
//     <0=> Disabled
//     <1=> PTD6 (Alias:D14, ONBOARD_SDA)<selection=PTD6_SIG_SEL,GPIOD_6/LLWU_P15>
//     <0=> Default
#define GPIOD_6_PIN_SEL      0
#if (GPIOD_6_PIN_SEL == 1)
#define GPIOD_6_GPIO         USBDM::GpioD<6>
#define GPIOD_6_FN           1
#endif

// Pin Mapping for GPIOD_7 signal
//   <o> GPIOD_7 [PTD7]<name=GPIOD_7_PIN_SEL>
//   <i> Shows which pin GPIOD_7 is mapped to
//     <0=> Disabled
//     <1=> PTD7 (Alias:D15, ONBOARD_SCL)<selection=PTD7_SIG_SEL,GPIOD_7>
//     <0=> Default
#define GPIOD_7_PIN_SEL      0
#if (GPIOD_7_PIN_SEL == 1)
#define GPIOD_7_GPIO         USBDM::GpioD<7>
#define GPIOD_7_FN           1
#endif

// </h>

// <h> General Purpose I/O (GPIOE)

// Pin Mapping for GPIOE_0 signal
//   <o> GPIOE_0 [PTE0]<name=GPIOE_0_PIN_SEL>
//   <i> Shows which pin GPIOE_0 is mapped to
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,GPIOE_0/CLKOUT32K>
//     <0=> Default
#define GPIOE_0_PIN_SEL      0
#if (GPIOE_0_PIN_SEL == 1)
#define GPIOE_0_GPIO         USBDM::GpioE<0>
#define GPIOE_0_FN           1
#endif

// Pin Mapping for GPIOE_1 signal
//   <o> GPIOE_1 [PTE1]<name=GPIOE_1_PIN_SEL>
//   <i> Shows which pin GPIOE_1 is mapped to
//     <0=> Disabled
//     <1=> PTE1<selection=PTE1_SIG_SEL,GPIOE_1>
//     <0=> Default
#define GPIOE_1_PIN_SEL      0
#if (GPIOE_1_PIN_SEL == 1)
#define GPIOE_1_GPIO         USBDM::GpioE<1>
#define GPIOE_1_FN           1
#endif

// Pin Mapping for GPIOE_16 signal
//   <o> GPIOE_16 [PTE16]<name=GPIOE_16_PIN_SEL>
//   <i> Shows which pin GPIOE_16 is mapped to
//     <0=> Disabled
//     <1=> PTE16 (Alias:A0)<selection=PTE16_SIG_SEL,GPIOE_16>
//     <0=> Default
#define GPIOE_16_PIN_SEL     0
#if (GPIOE_16_PIN_SEL == 1)
#define GPIOE_16_GPIO        USBDM::GpioE<16>
#define GPIOE_16_FN          1
#endif

// Pin Mapping for GPIOE_17 signal
//   <o> GPIOE_17 [PTE17]<name=GPIOE_17_PIN_SEL>
//   <i> Shows which pin GPIOE_17 is mapped to
//     <0=> Disabled
//     <1=> PTE17<selection=PTE17_SIG_SEL,GPIOE_17>
//     <0=> Default
#define GPIOE_17_PIN_SEL     0
#if (GPIOE_17_PIN_SEL == 1)
#define GPIOE_17_GPIO        USBDM::GpioE<17>
#define GPIOE_17_FN          1
#endif

// Pin Mapping for GPIOE_18 signal
//   <o> GPIOE_18 [PTE18]<name=GPIOE_18_PIN_SEL>
//   <i> Shows which pin GPIOE_18 is mapped to
//     <0=> Disabled
//     <1=> PTE18<selection=PTE18_SIG_SEL,GPIOE_18>
//     <0=> Default
#define GPIOE_18_PIN_SEL     0
#if (GPIOE_18_PIN_SEL == 1)
#define GPIOE_18_GPIO        USBDM::GpioE<18>
#define GPIOE_18_FN          1
#endif

// Pin Mapping for GPIOE_20 signal
//   <o> GPIOE_20 [PTE20]<name=GPIOE_20_PIN_SEL>
//   <i> Shows which pin GPIOE_20 is mapped to
//     <0=> Disabled
//     <1=> PTE20 (Alias:A2)<selection=PTE20_SIG_SEL,GPIOE_20>
//     <0=> Default
#define GPIOE_20_PIN_SEL     0
#if (GPIOE_20_PIN_SEL == 1)
#define GPIOE_20_GPIO        USBDM::GpioE<20>
#define GPIOE_20_FN          1
#endif

// Pin Mapping for GPIOE_21 signal
//   <o> GPIOE_21 [PTE21]<name=GPIOE_21_PIN_SEL>
//   <i> Shows which pin GPIOE_21 is mapped to
//     <0=> Disabled
//     <1=> PTE21 (Alias:A3)<selection=PTE21_SIG_SEL,GPIOE_21>
//     <0=> Default
#define GPIOE_21_PIN_SEL     0
#if (GPIOE_21_PIN_SEL == 1)
#define GPIOE_21_GPIO        USBDM::GpioE<21>
#define GPIOE_21_FN          1
#endif

// Pin Mapping for GPIOE_22 signal
//   <o> GPIOE_22 [PTE22]<name=GPIOE_22_PIN_SEL>
//   <i> Shows which pin GPIOE_22 is mapped to
//     <0=> Disabled
//     <1=> PTE22<selection=PTE22_SIG_SEL,GPIOE_22>
//     <0=> Default
#define GPIOE_22_PIN_SEL     0
#if (GPIOE_22_PIN_SEL == 1)
#define GPIOE_22_GPIO        USBDM::GpioE<22>
#define GPIOE_22_FN          1
#endif

// Pin Mapping for GPIOE_23 signal
//   <o> GPIOE_23 [PTE23]<name=GPIOE_23_PIN_SEL>
//   <i> Shows which pin GPIOE_23 is mapped to
//     <0=> Disabled
//     <1=> PTE23<selection=PTE23_SIG_SEL,GPIOE_23>
//     <0=> Default
#define GPIOE_23_PIN_SEL     0
#if (GPIOE_23_PIN_SEL == 1)
#define GPIOE_23_GPIO        USBDM::GpioE<23>
#define GPIOE_23_FN          1
#endif

// Pin Mapping for GPIOE_24 signal
//   <o> GPIOE_24 [PTE24]<name=GPIOE_24_PIN_SEL>
//   <i> Shows which pin GPIOE_24 is mapped to
//     <0=> Disabled
//     <1=> PTE24 (Alias:D5)<selection=PTE24_SIG_SEL,GPIOE_24>
//     <0=> Default
#define GPIOE_24_PIN_SEL     0
#if (GPIOE_24_PIN_SEL == 1)
#define GPIOE_24_GPIO        USBDM::GpioE<24>
#define GPIOE_24_FN          1
#endif

// Pin Mapping for GPIOE_25 signal
//   <o> GPIOE_25 [PTE25]<name=GPIOE_25_PIN_SEL>
//   <i> Shows which pin GPIOE_25 is mapped to
//     <0=> Disabled
//     <1=> PTE25 (Alias:D3)<selection=PTE25_SIG_SEL,GPIOE_25>
//     <0=> Default
#define GPIOE_25_PIN_SEL     0
#if (GPIOE_25_PIN_SEL == 1)
#define GPIOE_25_GPIO        USBDM::GpioE<25>
#define GPIOE_25_FN          1
#endif

// Pin Mapping for GPIOE_29 signal
//   <o> GPIOE_29 [PTE29]<name=GPIOE_29_PIN_SEL>
//   <i> Shows which pin GPIOE_29 is mapped to
//     <0=> Disabled
//     <1=> PTE29<selection=PTE29_SIG_SEL,GPIOE_29>
//     <0=> Default
#define GPIOE_29_PIN_SEL     0
#if (GPIOE_29_PIN_SEL == 1)
#define GPIOE_29_GPIO        USBDM::GpioE<29>
#define GPIOE_29_FN          1
#endif

// Pin Mapping for GPIOE_30 signal
//   <o> GPIOE_30 [PTE30]<name=GPIOE_30_PIN_SEL>
//   <i> Shows which pin GPIOE_30 is mapped to
//     <0=> Disabled
//     <1=> PTE30<selection=PTE30_SIG_SEL,GPIOE_30>
//     <0=> Default
#define GPIOE_30_PIN_SEL     0
#if (GPIOE_30_PIN_SEL == 1)
#define GPIOE_30_GPIO        USBDM::GpioE<30>
#define GPIOE_30_FN          1
#endif

// Pin Mapping for GPIOE_31 signal
//   <o> GPIOE_31 [PTE31]<name=GPIOE_31_PIN_SEL>
//   <i> Shows which pin GPIOE_31 is mapped to
//     <0=> Disabled
//     <1=> PTE31 (Alias:D8)<selection=PTE31_SIG_SEL,GPIOE_31>
//     <0=> Default
#define GPIOE_31_PIN_SEL     0
#if (GPIOE_31_PIN_SEL == 1)
#define GPIOE_31_GPIO        USBDM::GpioE<31>
#define GPIOE_31_FN          1
#endif

// </h>

// <h> Inter-Integrated Circuit (I2C0)

// Pin Mapping for I2C0_SCL signal
//   <o> I2C0_SCL [PTB0, PTB2, PTC8, PTE24]<name=I2C0_SCL_PIN_SEL>
//   <i> Shows which pin I2C0_SCL is mapped to
//     <0=> Disabled
//     <1=> PTB0 (Alias:A5)<selection=PTB0_SIG_SEL,I2C0_SCL>
//     <2=> PTB2<selection=PTB2_SIG_SEL,I2C0_SCL>
//     <3=> PTC8 (Alias:D7)<selection=PTC8_SIG_SEL,I2C0_SCL>
//     <4=> PTE24 (Alias:D5)<selection=PTE24_SIG_SEL,I2C0_SCL>
//     <0=> Default
#define I2C0_SCL_PIN_SEL     0

// Pin Mapping for I2C0_SDA signal
//   <o> I2C0_SDA [PTB1, PTB3, PTC9, PTE18, PTE25]<name=I2C0_SDA_PIN_SEL>
//   <i> Shows which pin I2C0_SDA is mapped to
//     <0=> Disabled
//     <1=> PTB1 (Alias:A4)<selection=PTB1_SIG_SEL,I2C0_SDA>
//     <2=> PTB3<selection=PTB3_SIG_SEL,I2C0_SDA>
//     <3=> PTC9 (Alias:D6)<selection=PTC9_SIG_SEL,I2C0_SDA>
//     <4=> PTE18<selection=PTE18_SIG_SEL,I2C0_SDA>
//     <5=> PTE25 (Alias:D3)<selection=PTE25_SIG_SEL,I2C0_SDA>
//     <0=> Default
#define I2C0_SDA_PIN_SEL     0

// </h>

// <h> Inter-Integrated Circuit (I2C1)

// Pin Mapping for I2C1_SDA signal
//   <o> I2C1_SDA [PTA4, PTC2, PTC11, PTD6, PTE0]<name=I2C1_SDA_PIN_SEL>
//   <i> Shows which pin I2C1_SDA is mapped to
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,I2C1_SDA>
//     <2=> PTC2 (Alias:MAG_INT)<selection=PTC2_SIG_SEL,I2C1_SDA>
//     <3=> PTC11<selection=PTC11_SIG_SEL,I2C1_SDA>
//     <4=> PTD6 (Alias:D14, ONBOARD_SDA)<selection=PTD6_SIG_SEL,I2C1_SDA>
//     <5=> PTE0<selection=PTE0_SIG_SEL,I2C1_SDA>
//     <4=> Default
#define I2C1_SDA_PIN_SEL     4

// Pin Mapping for I2C1_SCL signal
//   <o> I2C1_SCL [PTA3, PTC1, PTC10, PTD7, PTE1]<name=I2C1_SCL_PIN_SEL>
//   <i> Shows which pin I2C1_SCL is mapped to
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,I2C1_SCL>
//     <2=> PTC1<selection=PTC1_SIG_SEL,I2C1_SCL>
//     <3=> PTC10<selection=PTC10_SIG_SEL,I2C1_SCL>
//     <4=> PTD7 (Alias:D15, ONBOARD_SCL)<selection=PTD7_SIG_SEL,I2C1_SCL>
//     <5=> PTE1<selection=PTE1_SIG_SEL,I2C1_SCL>
//     <4=> Default
#define I2C1_SCL_PIN_SEL     4

// </h>

// <h> Low-Leakage Wake-up Unit (LLWU)

// Pin Mapping for LLWU_P5 signal
//   <o> LLWU_P5 [PTB0]<name=LLWU_P5_PIN_SEL>
//   <i> Shows which pin LLWU_P5 is mapped to
//     <0=> Disabled
//     <1=> PTB0 (Alias:A5)<selection=PTB0_SIG_SEL,GPIOB_0/LLWU_P5>
//     <0=> Default
#define LLWU_P5_PIN_SEL      0
#if (LLWU_P5_PIN_SEL == 1)
#define LLWU_P5_GPIO         USBDM::GpioB<0>
#define LLWU_P5_FN           1
#endif

// Pin Mapping for LLWU_P6 signal
//   <o> LLWU_P6 [PTC1]<name=LLWU_P6_PIN_SEL>
//   <i> Shows which pin LLWU_P6 is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,GPIOC_1/LLWU_P6/RTC_CLKIN>
//     <0=> Default
#define LLWU_P6_PIN_SEL      0
#if (LLWU_P6_PIN_SEL == 1)
#define LLWU_P6_GPIO         USBDM::GpioC<1>
#define LLWU_P6_FN           1
#endif

// Pin Mapping for LLWU_P7 signal
//   <o> LLWU_P7 [PTC3]<name=LLWU_P7_PIN_SEL>
//   <i> Shows which pin LLWU_P7 is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,GPIOC_3/LLWU_P7>
//     <0=> Default
#define LLWU_P7_PIN_SEL      0
#if (LLWU_P7_PIN_SEL == 1)
#define LLWU_P7_GPIO         USBDM::GpioC<3>
#define LLWU_P7_FN           1
#endif

// Pin Mapping for LLWU_P8 signal
//   <o> LLWU_P8 [PTC4]<name=LLWU_P8_PIN_SEL>
//   <i> Shows which pin LLWU_P8 is mapped to
//     <0=> Disabled
//     <1=> PTC4 (Alias:D10)<selection=PTC4_SIG_SEL,GPIOC_4/LLWU_P8>
//     <1=> Default
#define LLWU_P8_PIN_SEL      1
#if (LLWU_P8_PIN_SEL == 1)
#define LLWU_P8_GPIO         USBDM::GpioC<4>
#define LLWU_P8_FN           1
#endif

// Pin Mapping for LLWU_P9 signal
//   <o> LLWU_P9 [PTC5]<name=LLWU_P9_PIN_SEL>
//   <i> Shows which pin LLWU_P9 is mapped to
//     <0=> Disabled
//     <1=> PTC5 (Alias:D13)<selection=PTC5_SIG_SEL,GPIOC_5/LLWU_P9>
//     <1=> Default
#define LLWU_P9_PIN_SEL      1
#if (LLWU_P9_PIN_SEL == 1)
#define LLWU_P9_GPIO         USBDM::GpioC<5>
#define LLWU_P9_FN           1
#endif

// Pin Mapping for LLWU_P10 signal
//   <o> LLWU_P10 [PTC6]<name=LLWU_P10_PIN_SEL>
//   <i> Shows which pin LLWU_P10 is mapped to
//     <0=> Disabled
//     <1=> PTC6 (Alias:D11)<selection=PTC6_SIG_SEL,GPIOC_6/LLWU_P10>
//     <1=> Default
#define LLWU_P10_PIN_SEL     1
#if (LLWU_P10_PIN_SEL == 1)
#define LLWU_P10_GPIO        USBDM::GpioC<6>
#define LLWU_P10_FN          1
#endif

// Pin Mapping for LLWU_P14 signal
//   <o> LLWU_P14 [PTD4]<name=LLWU_P14_PIN_SEL>
//   <i> Shows which pin LLWU_P14 is mapped to
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,GPIOD_4/LLWU_P14>
//     <0=> Default
#define LLWU_P14_PIN_SEL     0
#if (LLWU_P14_PIN_SEL == 1)
#define LLWU_P14_GPIO        USBDM::GpioD<4>
#define LLWU_P14_FN          1
#endif

// Pin Mapping for LLWU_P15 signal
//   <o> LLWU_P15 [PTD6]<name=LLWU_P15_PIN_SEL>
//   <i> Shows which pin LLWU_P15 is mapped to
//     <0=> Disabled
//     <1=> PTD6 (Alias:D14, ONBOARD_SDA)<selection=PTD6_SIG_SEL,GPIOD_6/LLWU_P15>
//     <0=> Default
#define LLWU_P15_PIN_SEL     0
#if (LLWU_P15_PIN_SEL == 1)
#define LLWU_P15_GPIO        USBDM::GpioD<6>
#define LLWU_P15_FN          1
#endif

// </h>

// <h> Low Power Timer (LPTMR)

// Pin Mapping for LPTMR0_ALT1 signal
//   <o> LPTMR0_ALT1 [PTA19, PTE30]<name=LPTMR0_ALT1_PIN_SEL>
//   <i> Shows which pin LPTMR0_ALT1 is mapped to
//     <0=> Disabled
//     <1=> PTA19<selection=PTA19_SIG_SEL,LPTMR0_ALT1>
//     <2=> PTE30<selection=PTE30_SIG_SEL,LPTMR0_ALT1>
//     <0=> Default
#define LPTMR0_ALT1_PIN_SEL  0
#if (LPTMR0_ALT1_PIN_SEL == 1)
#define LPTMR0_ALT1_GPIO     USBDM::GpioA<19>
#define LPTMR0_ALT1_FN       6
#elif (LPTMR0_ALT1_PIN_SEL == 2)
#define LPTMR0_ALT1_GPIO     USBDM::GpioE<30>
#define LPTMR0_ALT1_FN       6
#endif

// Pin Mapping for LPTMR0_ALT2 signal
//   <o> LPTMR0_ALT2 [PTC5]<name=LPTMR0_ALT2_PIN_SEL>
//   <i> Shows which pin LPTMR0_ALT2 is mapped to
//     <0=> Disabled
//     <1=> PTC5 (Alias:D13)<selection=PTC5_SIG_SEL,LPTMR0_ALT2>
//     <0=> Default
#define LPTMR0_ALT2_PIN_SEL  0
#if (LPTMR0_ALT2_PIN_SEL == 1)
#define LPTMR0_ALT2_GPIO     USBDM::GpioC<5>
#define LPTMR0_ALT2_FN       3
#endif

// Pin Mapping for LPTMR0_ALT3 signal
//   <o> LPTMR0_ALT3 [PTE17]<name=LPTMR0_ALT3_PIN_SEL>
//   <i> Shows which pin LPTMR0_ALT3 is mapped to
//     <0=> Disabled
//     <1=> PTE17<selection=PTE17_SIG_SEL,LPTMR0_ALT3>
//     <0=> Default
#define LPTMR0_ALT3_PIN_SEL  0
#if (LPTMR0_ALT3_PIN_SEL == 1)
#define LPTMR0_ALT3_GPIO     USBDM::GpioE<17>
#define LPTMR0_ALT3_FN       5
#endif

// </h>

// <h> Low Power UART (LPUART0)

// Pin Mapping for LPUART0_RX signal
//   <o> LPUART0_RX [PTA1, PTB16, PTD6, PTE21]<name=LPUART0_RX_PIN_SEL>
//   <i> Shows which pin LPUART0_RX is mapped to
//     <0=> Disabled
//     <1=> PTA1 (Alias:D0)<selection=PTA1_SIG_SEL,LPUART0_RX>
//     <2=> PTB16<selection=PTB16_SIG_SEL,LPUART0_RX>
//     <3=> PTD6 (Alias:D14, ONBOARD_SDA)<selection=PTD6_SIG_SEL,LPUART0_RX>
//     <4=> PTE21 (Alias:A3)<selection=PTE21_SIG_SEL,LPUART0_RX>
//     <0=> Default
#define LPUART0_RX_PIN_SEL   0
#if (LPUART0_RX_PIN_SEL == 1)
#define LPUART0_RX_GPIO      USBDM::GpioA<1>
#define LPUART0_RX_FN        2
#elif (LPUART0_RX_PIN_SEL == 2)
#define LPUART0_RX_GPIO      USBDM::GpioB<16>
#define LPUART0_RX_FN        3
#elif (LPUART0_RX_PIN_SEL == 3)
#define LPUART0_RX_GPIO      USBDM::GpioD<6>
#define LPUART0_RX_FN        3
#elif (LPUART0_RX_PIN_SEL == 4)
#define LPUART0_RX_GPIO      USBDM::GpioE<21>
#define LPUART0_RX_FN        4
#endif

// Pin Mapping for LPUART0_TX signal
//   <o> LPUART0_TX [PTA2, PTB17, PTD7, PTE20]<name=LPUART0_TX_PIN_SEL>
//   <i> Shows which pin LPUART0_TX is mapped to
//     <0=> Disabled
//     <1=> PTA2 (Alias:D1)<selection=PTA2_SIG_SEL,LPUART0_TX>
//     <2=> PTB17<selection=PTB17_SIG_SEL,LPUART0_TX>
//     <3=> PTD7 (Alias:D15, ONBOARD_SCL)<selection=PTD7_SIG_SEL,LPUART0_TX>
//     <4=> PTE20 (Alias:A2)<selection=PTE20_SIG_SEL,LPUART0_TX>
//     <0=> Default
#define LPUART0_TX_PIN_SEL   0
#if (LPUART0_TX_PIN_SEL == 1)
#define LPUART0_TX_GPIO      USBDM::GpioA<2>
#define LPUART0_TX_FN        2
#elif (LPUART0_TX_PIN_SEL == 2)
#define LPUART0_TX_GPIO      USBDM::GpioB<17>
#define LPUART0_TX_FN        3
#elif (LPUART0_TX_PIN_SEL == 3)
#define LPUART0_TX_GPIO      USBDM::GpioD<7>
#define LPUART0_TX_FN        3
#elif (LPUART0_TX_PIN_SEL == 4)
#define LPUART0_TX_GPIO      USBDM::GpioE<20>
#define LPUART0_TX_FN        4
#endif

// </h>

// <h> Low Power UART (LPUART1)

// Pin Mapping for LPUART1_RX signal
//   <o> LPUART1_RX [PTA18, PTC3, PTE1]<name=LPUART1_RX_PIN_SEL>
//   <i> Shows which pin LPUART1_RX is mapped to
//     <0=> Disabled
//     <1=> PTA18<selection=PTA18_SIG_SEL,LPUART1_RX>
//     <2=> PTC3<selection=PTC3_SIG_SEL,LPUART1_RX>
//     <3=> PTE1<selection=PTE1_SIG_SEL,LPUART1_RX>
//     <0=> Default
#define LPUART1_RX_PIN_SEL   0
#if (LPUART1_RX_PIN_SEL == 1)
#define LPUART1_RX_GPIO      USBDM::GpioA<18>
#define LPUART1_RX_FN        3
#elif (LPUART1_RX_PIN_SEL == 2)
#define LPUART1_RX_GPIO      USBDM::GpioC<3>
#define LPUART1_RX_FN        3
#elif (LPUART1_RX_PIN_SEL == 3)
#define LPUART1_RX_GPIO      USBDM::GpioE<1>
#define LPUART1_RX_FN        3
#endif

// Pin Mapping for LPUART1_TX signal
//   <o> LPUART1_TX [PTA19, PTC4, PTE0, PTE30]<name=LPUART1_TX_PIN_SEL>
//   <i> Shows which pin LPUART1_TX is mapped to
//     <0=> Disabled
//     <1=> PTA19<selection=PTA19_SIG_SEL,LPUART1_TX>
//     <2=> PTC4 (Alias:D10)<selection=PTC4_SIG_SEL,LPUART1_TX>
//     <3=> PTE0<selection=PTE0_SIG_SEL,LPUART1_TX>
//     <4=> PTE30<selection=PTE30_SIG_SEL,LPUART1_TX>
//     <0=> Default
#define LPUART1_TX_PIN_SEL   0
#if (LPUART1_TX_PIN_SEL == 1)
#define LPUART1_TX_GPIO      USBDM::GpioA<19>
#define LPUART1_TX_FN        3
#elif (LPUART1_TX_PIN_SEL == 2)
#define LPUART1_TX_GPIO      USBDM::GpioC<4>
#define LPUART1_TX_FN        3
#elif (LPUART1_TX_PIN_SEL == 3)
#define LPUART1_TX_GPIO      USBDM::GpioE<0>
#define LPUART1_TX_FN        3
#elif (LPUART1_TX_PIN_SEL == 4)
#define LPUART1_TX_GPIO      USBDM::GpioE<30>
#define LPUART1_TX_FN        5
#endif

// </h>

// <h> Debug and Control

// Pin Mapping for NMI_b signal
//   <o> NMI_b [PTA4]<name=NMI_b_PIN_SEL>
//   <i> Shows which pin NMI_b is mapped to
//     <0=> Disabled
//     <1=> PTA4 (reset default)<selection=PTA4_SIG_SEL,NMI_b (reset default)>
//     <2=> PTA4<selection=PTA4_SIG_SEL,NMI_b>
//     <1=> Default
#define NMI_b_PIN_SEL        1
#if (NMI_b_PIN_SEL == 2)
#define NMI_b_GPIO           USBDM::GpioA<4>
#define NMI_b_FN             7
#endif

// Pin Mapping for RESET_b signal
//   <o> RESET_b [PTA20]<name=RESET_b_PIN_SEL>
//   <i> Shows which pin RESET_b is mapped to
//     <0=> Disabled
//     <1=> PTA20 (reset default)<selection=PTA20_SIG_SEL,RESET_b (reset default)>
//     <2=> PTA20<selection=PTA20_SIG_SEL,RESET_b>
//     <1=> Default
#define RESET_b_PIN_SEL      1
#if (RESET_b_PIN_SEL == 2)
#define RESET_b_GPIO         USBDM::GpioA<20>
#define RESET_b_FN           7
#endif

// Pin Mapping for SWD_CLK signal
//   <o> SWD_CLK [PTA0]<name=SWD_CLK_PIN_SEL>
//   <i> Shows which pin SWD_CLK is mapped to
//     <0=> Disabled
//     <1=> PTA0 (reset default)<selection=PTA0_SIG_SEL,SWD_CLK (reset default)>
//     <2=> PTA0<selection=PTA0_SIG_SEL,SWD_CLK>
//     <1=> Default
#define SWD_CLK_PIN_SEL      1
#if (SWD_CLK_PIN_SEL == 2)
#define SWD_CLK_GPIO         USBDM::GpioA<0>
#define SWD_CLK_FN           7
#endif

// Pin Mapping for SWD_DIO signal
//   <o> SWD_DIO [PTA3]<name=SWD_DIO_PIN_SEL>
//   <i> Shows which pin SWD_DIO is mapped to
//     <0=> Disabled
//     <1=> PTA3 (reset default)<selection=PTA3_SIG_SEL,SWD_DIO (reset default)>
//     <2=> PTA3<selection=PTA3_SIG_SEL,SWD_DIO>
//     <1=> Default
#define SWD_DIO_PIN_SEL      1
#if (SWD_DIO_PIN_SEL == 2)
#define SWD_DIO_GPIO         USBDM::GpioA<3>
#define SWD_DIO_FN           7
#endif

// </h>

// <h> Serial Peripheral Interface (SPI0)

// Pin Mapping for SPI0_MISO signal
//   <o> SPI0_MISO [PTC7, PTD3, PTC6, PTD2, PTE18]<name=SPI0_MISO_PIN_SEL>
//   <i> Shows which pin SPI0_MISO is mapped to
//     <0=> Disabled
//     <1=> PTC7 (Alias:D12)<selection=PTC7_SIG_SEL,SPI0_MISO>
//     <2=> PTD3<selection=PTD3_SIG_SEL,SPI0_MISO>
//     <3=> PTC6 (Alias:D11)<selection=PTC6_SIG_SEL,SPI0_MISO>
//     <4=> PTD2<selection=PTD2_SIG_SEL,SPI0_MISO>
//     <5=> PTE18<selection=PTE18_SIG_SEL,SPI0_MISO>
//     <0=> Default
#define SPI0_MISO_PIN_SEL    0

// Pin Mapping for SPI0_MOSI signal
//   <o> SPI0_MOSI [PTC6, PTD2, PTE18, PTC7, PTD3]<name=SPI0_MOSI_PIN_SEL>
//   <i> Shows which pin SPI0_MOSI is mapped to
//     <0=> Disabled
//     <1=> PTC6 (Alias:D11)<selection=PTC6_SIG_SEL,SPI0_MOSI>
//     <2=> PTD2<selection=PTD2_SIG_SEL,SPI0_MOSI>
//     <3=> PTE18<selection=PTE18_SIG_SEL,SPI0_MOSI>
//     <4=> PTC7 (Alias:D12)<selection=PTC7_SIG_SEL,SPI0_MOSI>
//     <5=> PTD3<selection=PTD3_SIG_SEL,SPI0_MOSI>
//     <0=> Default
#define SPI0_MOSI_PIN_SEL    0

// Pin Mapping for SPI0_PCS0 signal
//   <o> SPI0_PCS0 [PTC4, PTD0, PTE16]<name=SPI0_PCS0_PIN_SEL>
//   <i> Shows which pin SPI0_PCS0 is mapped to
//     <0=> Disabled
//     <1=> PTC4 (Alias:D10)<selection=PTC4_SIG_SEL,SPI0_PCS0>
//     <2=> PTD0<selection=PTD0_SIG_SEL,SPI0_PCS0>
//     <3=> PTE16 (Alias:A0)<selection=PTE16_SIG_SEL,SPI0_PCS0>
//     <0=> Default
#define SPI0_PCS0_PIN_SEL    0

// Pin Mapping for SPI0_SCK signal
//   <o> SPI0_SCK [PTC5, PTD1, PTE17]<name=SPI0_SCK_PIN_SEL>
//   <i> Shows which pin SPI0_SCK is mapped to
//     <0=> Disabled
//     <1=> PTC5 (Alias:D13)<selection=PTC5_SIG_SEL,SPI0_SCK>
//     <2=> PTD1<selection=PTD1_SIG_SEL,SPI0_SCK>
//     <3=> PTE17<selection=PTE17_SIG_SEL,SPI0_SCK>
//     <0=> Default
#define SPI0_SCK_PIN_SEL     0

// </h>

// <h> Serial Peripheral Interface (SPI1)

// Pin Mapping for SPI1_MISO signal
//   <o> SPI1_MISO [PTB17, PTD7, PTE0, PTB1, PTB0, PTB16, PTD6, PTE1]<name=SPI1_MISO_PIN_SEL>
//   <i> Shows which pin SPI1_MISO is mapped to
//     <0=> Disabled
//     <1=> PTB17<selection=PTB17_SIG_SEL,SPI1_MISO>
//     <2=> PTD7 (Alias:D15, ONBOARD_SCL)<selection=PTD7_SIG_SEL,SPI1_MISO>
//     <3=> PTE0<selection=PTE0_SIG_SEL,SPI1_MISO>
//     <4=> PTB1 (Alias:A4)<selection=PTB1_SIG_SEL,SPI1_MISO>
//     <5=> PTB0 (Alias:A5)<selection=PTB0_SIG_SEL,SPI1_MISO>
//     <6=> PTB16<selection=PTB16_SIG_SEL,SPI1_MISO>
//     <7=> PTD6 (Alias:D14, ONBOARD_SDA)<selection=PTD6_SIG_SEL,SPI1_MISO>
//     <8=> PTE1<selection=PTE1_SIG_SEL,SPI1_MISO>
//     <0=> Default
#define SPI1_MISO_PIN_SEL    0

// Pin Mapping for SPI1_MOSI signal
//   <o> SPI1_MOSI [PTB16, PTD6, PTE1, PTB0, PTB1, PTB17, PTD7]<name=SPI1_MOSI_PIN_SEL>
//   <i> Shows which pin SPI1_MOSI is mapped to
//     <0=> Disabled
//     <1=> PTB16<selection=PTB16_SIG_SEL,SPI1_MOSI>
//     <2=> PTD6 (Alias:D14, ONBOARD_SDA)<selection=PTD6_SIG_SEL,SPI1_MOSI>
//     <3=> PTE1<selection=PTE1_SIG_SEL,SPI1_MOSI>
//     <4=> PTB0 (Alias:A5)<selection=PTB0_SIG_SEL,SPI1_MOSI>
//     <5=> PTB1 (Alias:A4)<selection=PTB1_SIG_SEL,SPI1_MOSI>
//     <6=> PTB17<selection=PTB17_SIG_SEL,SPI1_MOSI>
//     <7=> PTD7 (Alias:D15, ONBOARD_SCL)<selection=PTD7_SIG_SEL,SPI1_MOSI>
//     <0=> Default
#define SPI1_MOSI_PIN_SEL    0

// Pin Mapping for SPI1_PCS0 signal
//   <o> SPI1_PCS0 [PTD4, PTC4]<name=SPI1_PCS0_PIN_SEL>
//   <i> Shows which pin SPI1_PCS0 is mapped to
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,SPI1_PCS0>
//     <2=> PTC4 (Alias:D10)<selection=PTC4_SIG_SEL,SPI1_PCS0>
//     <0=> Default
#define SPI1_PCS0_PIN_SEL    0

// Pin Mapping for SPI1_SCK signal
//   <o> SPI1_SCK [PTC3, PTD5]<name=SPI1_SCK_PIN_SEL>
//   <i> Shows which pin SPI1_SCK is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,SPI1_SCK>
//     <2=> PTD5<selection=PTD5_SIG_SEL,SPI1_SCK>
//     <0=> Default
#define SPI1_SCK_PIN_SEL     0

// </h>

// <h> Timer (TPM0)

// Pin Mapping for TPM0_CH0 signal
//   <o> TPM0_CH0 [PTA3, PTE24, PTC1, PTD0]<name=TPM0_CH0_PIN_SEL>
//   <i> Shows which pin TPM0_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,TPM0_CH0>
//     <2=> PTE24 (Alias:D5)<selection=PTE24_SIG_SEL,TPM0_CH0>
//     <3=> PTC1<selection=PTC1_SIG_SEL,TPM0_CH0>
//     <4=> PTD0<selection=PTD0_SIG_SEL,TPM0_CH0>
//     <2=> Default
#define TPM0_CH0_PIN_SEL     2

// Pin Mapping for TPM0_CH1 signal
//   <o> TPM0_CH1 [PTA4, PTE25, PTC2, PTD1]<name=TPM0_CH1_PIN_SEL>
//   <i> Shows which pin TPM0_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,TPM0_CH1>
//     <2=> PTE25 (Alias:D3)<selection=PTE25_SIG_SEL,TPM0_CH1>
//     <3=> PTC2 (Alias:MAG_INT)<selection=PTC2_SIG_SEL,TPM0_CH1>
//     <4=> PTD1<selection=PTD1_SIG_SEL,TPM0_CH1>
//     <2=> Default
#define TPM0_CH1_PIN_SEL     2

// Pin Mapping for TPM0_CH2 signal
//   <o> TPM0_CH2 [PTA5, PTE29, PTC3, PTD2]<name=TPM0_CH2_PIN_SEL>
//   <i> Shows which pin TPM0_CH2 is mapped to
//     <0=> Disabled
//     <1=> PTA5 (Alias:D9)<selection=PTA5_SIG_SEL,TPM0_CH2>
//     <2=> PTE29<selection=PTE29_SIG_SEL,TPM0_CH2>
//     <3=> PTC3<selection=PTC3_SIG_SEL,TPM0_CH2>
//     <4=> PTD2<selection=PTD2_SIG_SEL,TPM0_CH2>
//     <1=> Default
#define TPM0_CH2_PIN_SEL     1

// Pin Mapping for TPM0_CH3 signal
//   <o> TPM0_CH3 [PTE30, PTC4, PTD3]<name=TPM0_CH3_PIN_SEL>
//   <i> Shows which pin TPM0_CH3 is mapped to
//     <0=> Disabled
//     <1=> PTE30<selection=PTE30_SIG_SEL,TPM0_CH3>
//     <2=> PTC4 (Alias:D10)<selection=PTC4_SIG_SEL,TPM0_CH3>
//     <3=> PTD3<selection=PTD3_SIG_SEL,TPM0_CH3>
//     <0=> Default
#define TPM0_CH3_PIN_SEL     0

// Pin Mapping for TPM0_CH4 signal
//   <o> TPM0_CH4 [PTC8, PTE31, PTD4]<name=TPM0_CH4_PIN_SEL>
//   <i> Shows which pin TPM0_CH4 is mapped to
//     <0=> Disabled
//     <1=> PTC8 (Alias:D7)<selection=PTC8_SIG_SEL,TPM0_CH4>
//     <2=> PTE31 (Alias:D8)<selection=PTE31_SIG_SEL,TPM0_CH4>
//     <3=> PTD4<selection=PTD4_SIG_SEL,TPM0_CH4>
//     <2=> Default
#define TPM0_CH4_PIN_SEL     2

// Pin Mapping for TPM0_CH5 signal
//   <o> TPM0_CH5 [PTA0, PTC9, PTD5]<name=TPM0_CH5_PIN_SEL>
//   <i> Shows which pin TPM0_CH5 is mapped to
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,TPM0_CH5>
//     <2=> PTC9 (Alias:D6)<selection=PTC9_SIG_SEL,TPM0_CH5>
//     <3=> PTD5<selection=PTD5_SIG_SEL,TPM0_CH5>
//     <0=> Default
#define TPM0_CH5_PIN_SEL     0

// </h>

// <h> Timer (TPM1)

// Pin Mapping for TPM1_CH0 signal
//   <o> TPM1_CH0 [PTA12, PTB0, PTE20]<name=TPM1_CH0_PIN_SEL>
//   <i> Shows which pin TPM1_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTA12 (Alias:D2)<selection=PTA12_SIG_SEL,TPM1_CH0>
//     <2=> PTB0 (Alias:A5)<selection=PTB0_SIG_SEL,TPM1_CH0>
//     <3=> PTE20 (Alias:A2)<selection=PTE20_SIG_SEL,TPM1_CH0>
//     <1=> Default
#define TPM1_CH0_PIN_SEL     1

// Pin Mapping for TPM1_CH1 signal
//   <o> TPM1_CH1 [PTA13, PTB1, PTE21]<name=TPM1_CH1_PIN_SEL>
//   <i> Shows which pin TPM1_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTA13 (Alias:D4, LED_BLUE)<selection=PTA13_SIG_SEL,TPM1_CH1>
//     <2=> PTB1 (Alias:A4)<selection=PTB1_SIG_SEL,TPM1_CH1>
//     <3=> PTE21 (Alias:A3)<selection=PTE21_SIG_SEL,TPM1_CH1>
//     <1=> Default
#define TPM1_CH1_PIN_SEL     1

// </h>

// <h> Timer (TPM2)

// Pin Mapping for TPM2_CH0 signal
//   <o> TPM2_CH0 [PTA1, PTB2, PTB18, PTE22]<name=TPM2_CH0_PIN_SEL>
//   <i> Shows which pin TPM2_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTA1 (Alias:D0)<selection=PTA1_SIG_SEL,TPM2_CH0>
//     <2=> PTB2<selection=PTB2_SIG_SEL,TPM2_CH0>
//     <3=> PTB18 (Alias:LED_RED)<selection=PTB18_SIG_SEL,TPM2_CH0>
//     <4=> PTE22<selection=PTE22_SIG_SEL,TPM2_CH0>
//     <1=> Default
#define TPM2_CH0_PIN_SEL     1

// Pin Mapping for TPM2_CH1 signal
//   <o> TPM2_CH1 [PTA2, PTB3, PTB19, PTE23]<name=TPM2_CH1_PIN_SEL>
//   <i> Shows which pin TPM2_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTA2 (Alias:D1)<selection=PTA2_SIG_SEL,TPM2_CH1>
//     <2=> PTB3<selection=PTB3_SIG_SEL,TPM2_CH1>
//     <3=> PTB19 (Alias:LED_GREEN)<selection=PTB19_SIG_SEL,TPM2_CH1>
//     <4=> PTE23<selection=PTE23_SIG_SEL,TPM2_CH1>
//     <1=> Default
#define TPM2_CH1_PIN_SEL     1

// </h>

// <h> Universal Asynchronous Rx/Tx (UART2)

// Pin Mapping for UART2_RX signal
//   <o> UART2_RX [PTD2, PTD4, PTE17, PTE23]<name=UART2_RX_PIN_SEL>
//   <i> Shows which pin UART2_RX is mapped to
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,UART2_RX>
//     <2=> PTD4<selection=PTD4_SIG_SEL,UART2_RX>
//     <3=> PTE17<selection=PTE17_SIG_SEL,UART2_RX>
//     <4=> PTE23<selection=PTE23_SIG_SEL,UART2_RX>
//     <0=> Default
#define UART2_RX_PIN_SEL     0
#if (UART2_RX_PIN_SEL == 1)
#define UART2_RX_GPIO        USBDM::GpioD<2>
#define UART2_RX_FN          3
#elif (UART2_RX_PIN_SEL == 2)
#define UART2_RX_GPIO        USBDM::GpioD<4>
#define UART2_RX_FN          3
#elif (UART2_RX_PIN_SEL == 3)
#define UART2_RX_GPIO        USBDM::GpioE<17>
#define UART2_RX_FN          3
#elif (UART2_RX_PIN_SEL == 4)
#define UART2_RX_GPIO        USBDM::GpioE<23>
#define UART2_RX_FN          4
#endif

// Pin Mapping for UART2_TX signal
//   <o> UART2_TX [PTD3, PTD5, PTE16, PTE22]<name=UART2_TX_PIN_SEL>
//   <i> Shows which pin UART2_TX is mapped to
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,UART2_TX>
//     <2=> PTD5<selection=PTD5_SIG_SEL,UART2_TX>
//     <3=> PTE16 (Alias:A0)<selection=PTE16_SIG_SEL,UART2_TX>
//     <4=> PTE22<selection=PTE22_SIG_SEL,UART2_TX>
//     <0=> Default
#define UART2_TX_PIN_SEL     0
#if (UART2_TX_PIN_SEL == 1)
#define UART2_TX_GPIO        USBDM::GpioD<3>
#define UART2_TX_FN          3
#elif (UART2_TX_PIN_SEL == 2)
#define UART2_TX_GPIO        USBDM::GpioD<5>
#define UART2_TX_FN          3
#elif (UART2_TX_PIN_SEL == 3)
#define UART2_TX_GPIO        USBDM::GpioE<16>
#define UART2_TX_FN          3
#elif (UART2_TX_PIN_SEL == 4)
#define UART2_TX_GPIO        USBDM::GpioE<22>
#define UART2_TX_FN          4
#endif

// </h>

// <h> Universal Serial Bus

// Pin Mapping for USB_CLKIN signal
//   <o> USB_CLKIN [PTA5]<name=USB_CLKIN_PIN_SEL>
//   <i> Shows which pin USB_CLKIN is mapped to
//     <0=> Disabled
//     <1=> PTA5 (Alias:D9)<selection=PTA5_SIG_SEL,USB_CLKIN>
//     <0=> Default
#define USB_CLKIN_PIN_SEL    0
#if (USB_CLKIN_PIN_SEL == 1)
#define USB_CLKIN_GPIO       USBDM::GpioA<5>
#define USB_CLKIN_FN         2
#endif

// Pin Mapping for audioUSB_SOF_OUT signal
//   <o> audioUSB_SOF_OUT [PTC7, PTC0]<name=audioUSB_SOF_OUT_PIN_SEL>
//   <i> Shows which pin audioUSB_SOF_OUT is mapped to
//     <0=> Disabled
//     <1=> PTC7 (Alias:D12)<selection=PTC7_SIG_SEL,audioUSB_SOF_OUT>
//     <2=> PTC0 (Alias:A1)<selection=PTC0_SIG_SEL,audioUSB_SOF_OUT>
//     <0=> Default
#define audioUSB_SOF_OUT_PIN_SEL 0
#if (audioUSB_SOF_OUT_PIN_SEL == 1)
#define audioUSB_SOF_OUT_GPIO USBDM::GpioC<7>
#define audioUSB_SOF_OUT_FN  3
#elif (audioUSB_SOF_OUT_PIN_SEL == 2)
#define audioUSB_SOF_OUT_GPIO USBDM::GpioC<0>
#define audioUSB_SOF_OUT_FN  4
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
#define ADC0_CLOCK_REG       SCGC6
#define ADC0_CLOCK_MASK      SIM_SCGC6_ADC0_MASK
#define CMP0_CLOCK_REG       SCGC4
#define CMP0_CLOCK_MASK      SIM_SCGC4_CMP0_MASK
#define CRC_CLOCK_REG        SCGC6
#define CRC_CLOCK_MASK       SIM_SCGC6_CRC_MASK
#define DMA_CLOCK_REG        SCGC7
#define DMA_CLOCK_MASK       SIM_SCGC7_DMA_MASK
#define DMAMUX_CLOCK_REG     SCGC6
#define DMAMUX_CLOCK_MASK    SIM_SCGC6_DMAMUX_MASK
#define FLEXIO_CLOCK_REG     SCGC5
#define FLEXIO_CLOCK_MASK    SIM_SCGC5_FLEXIO_MASK
#define FTF_CLOCK_REG        SCGC6
#define FTF_CLOCK_MASK       SIM_SCGC6_FTF_MASK
#define I2C0_CLOCK_REG       SCGC4
#define I2C0_CLOCK_MASK      SIM_SCGC4_I2C0_MASK
#define I2C1_CLOCK_REG       SCGC4
#define I2C1_CLOCK_MASK      SIM_SCGC4_I2C1_MASK
#define LPTMR0_CLOCK_REG     SCGC5
#define LPTMR0_CLOCK_MASK    SIM_SCGC5_LPTMR_MASK
#define LPUART0_CLOCK_REG    SCGC5
#define LPUART0_CLOCK_MASK   SIM_SCGC5_LPUART0_MASK
#define LPUART1_CLOCK_REG    SCGC5
#define LPUART1_CLOCK_MASK   SIM_SCGC5_LPUART1_MASK
#define PIT_CLOCK_REG        SCGC6
#define PIT_CLOCK_MASK       SIM_SCGC6_PIT_MASK
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
#define RTC_CLOCK_REG        SCGC6
#define RTC_CLOCK_MASK       SIM_SCGC6_RTC_MASK
#define SPI0_CLOCK_REG       SCGC4
#define SPI0_CLOCK_MASK      SIM_SCGC4_SPI0_MASK
#define SPI1_CLOCK_REG       SCGC4
#define SPI1_CLOCK_MASK      SIM_SCGC4_SPI1_MASK
#define TPM0_CLOCK_REG       SCGC6
#define TPM0_CLOCK_MASK      SIM_SCGC6_TPM0_MASK
#define TPM1_CLOCK_REG       SCGC6
#define TPM1_CLOCK_MASK      SIM_SCGC6_TPM1_MASK
#define TPM2_CLOCK_REG       SCGC6
#define TPM2_CLOCK_MASK      SIM_SCGC6_TPM2_MASK
#define UART2_CLOCK_REG      SCGC4
#define UART2_CLOCK_MASK     SIM_SCGC4_UART2_MASK
#define USB_CLOCK_REG        SCGC4
#define USB_CLOCK_MASK       SIM_SCGC4_USB_MASK
#define VREF_CLOCK_REG       SCGC4
#define VREF_CLOCK_MASK      SIM_SCGC4_VREF_MASK
#define PORT_CLOCK_REG       SCGC5

/*
Clock Information Summary
ADC0       SCGC6        SIM_SCGC6_ADC0_MASK
CMP0       SCGC4        SIM_SCGC4_CMP0_MASK
CRC        SCGC6        SIM_SCGC6_CRC_MASK
DMA        SCGC7        SIM_SCGC7_DMA_MASK
DMAMUX     SCGC6        SIM_SCGC6_DMAMUX_MASK
FLEXIO     SCGC5        SIM_SCGC5_FLEXIO_MASK
FTF        SCGC6        SIM_SCGC6_FTF_MASK
I2C0       SCGC4        SIM_SCGC4_I2C0_MASK
I2C1       SCGC4        SIM_SCGC4_I2C1_MASK
LPTMR0     SCGC5        SIM_SCGC5_LPTMR_MASK
LPUART0    SCGC5        SIM_SCGC5_LPUART0_MASK
LPUART1    SCGC5        SIM_SCGC5_LPUART1_MASK
PIT        SCGC6        SIM_SCGC6_PIT_MASK
PORTA      SCGC5        SIM_SCGC5_PORTA_MASK
PORTB      SCGC5        SIM_SCGC5_PORTB_MASK
PORTC      SCGC5        SIM_SCGC5_PORTC_MASK
PORTD      SCGC5        SIM_SCGC5_PORTD_MASK
PORTE      SCGC5        SIM_SCGC5_PORTE_MASK
RTC        SCGC6        SIM_SCGC6_RTC_MASK
SPI0       SCGC4        SIM_SCGC4_SPI0_MASK
SPI1       SCGC4        SIM_SCGC4_SPI1_MASK
TPM0       SCGC6        SIM_SCGC6_TPM0_MASK
TPM1       SCGC6        SIM_SCGC6_TPM1_MASK
TPM2       SCGC6        SIM_SCGC6_TPM2_MASK
UART2      SCGC4        SIM_SCGC4_UART2_MASK
USB        SCGC4        SIM_SCGC4_USB_MASK
VREF       SCGC4        SIM_SCGC4_VREF_MASK
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
   uint32_t gpioAddress; //!< Address of GPIO hardware associated with pin
   uint8_t  gpioBit;     //!< Bit number of pin in GPIO
   uint8_t  muxValue;    //!< PCR mux value to select this function
};
/**
 * Peripheral pin mapping information for Analogue Input
 */
constexpr PcrInfo Adc0Info[32] = {
 //          clockMask pcrAddress gpioAddress gpioBit muxValue
#if (ADC0_SE0_PIN_SEL == 1)
 /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[20]), GPIOE_BasePtr,  20, 0 },
#else
 /*  0 */  { 0 },
#endif
#if (ADC0_SE1_PIN_SEL == 1)
 /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[16]), GPIOE_BasePtr,  16, 0 },
#else
 /*  1 */  { 0 },
#endif
#if (ADC0_SE2_PIN_SEL == 1)
 /*  2 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[18]), GPIOE_BasePtr,  18, 0 },
#else
 /*  2 */  { 0 },
#endif
#if (ADC0_SE3_PIN_SEL == 1)
 /*  3 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[22]), GPIOE_BasePtr,  22, 0 },
#else
 /*  3 */  { 0 },
#endif
#if (ADC0_SE4b_PIN_SEL == 1)
 /*  4 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[29]), GPIOE_BasePtr,  29, 0 },
#else
 /*  4 */  { 0 },
#endif
#if (ADC0_SE5b_PIN_SEL == 1)
 /*  5 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOD_BasePtr,  1,  0 },
#else
 /*  5 */  { 0 },
#endif
#if (ADC0_SE6b_PIN_SEL == 1)
 /*  6 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  GPIOD_BasePtr,  5,  0 },
#else
 /*  6 */  { 0 },
#endif
#if (ADC0_SE7b_PIN_SEL == 1)
 /*  7 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),  GPIOD_BasePtr,  6,  0 },
#else
 /*  7 */  { 0 },
#endif
#if (ADC0_SE8_PIN_SEL == 1)
 /*  8 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOB_BasePtr,  0,  0 },
#else
 /*  8 */  { 0 },
#endif
#if (ADC0_SE9_PIN_SEL == 1)
 /*  9 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOB_BasePtr,  1,  0 },
#else
 /*  9 */  { 0 },
#endif
 /* 10 */  { 0 },
#if (ADC0_SE11_PIN_SEL == 1)
 /* 11 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  GPIOC_BasePtr,  2,  0 },
#else
 /* 11 */  { 0 },
#endif
#if (ADC0_SE12_PIN_SEL == 1)
 /* 12 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  GPIOB_BasePtr,  2,  0 },
#else
 /* 12 */  { 0 },
#endif
#if (ADC0_SE13_PIN_SEL == 1)
 /* 13 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  GPIOB_BasePtr,  3,  0 },
#else
 /* 13 */  { 0 },
#endif
#if (ADC0_SE14_PIN_SEL == 1)
 /* 14 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOC_BasePtr,  0,  0 },
#else
 /* 14 */  { 0 },
#endif
#if (ADC0_SE15_PIN_SEL == 1)
 /* 15 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOC_BasePtr,  1,  0 },
#else
 /* 15 */  { 0 },
#endif
 /* 16 */  { 0 },
 /* 17 */  { 0 },
 /* 18 */  { 0 },
 /* 19 */  { 0 },
 /* 20 */  { 0 },
 /* 21 */  { 0 },
 /* 22 */  { 0 },
#if (ADC0_SE23_PIN_SEL == 1)
 /* 23 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[30]), GPIOE_BasePtr,  30, 0 },
#else
 /* 23 */  { 0 },
#endif
};

/**
 * Peripheral pin mapping information for Analogue Input
 */
constexpr PcrInfo Adc0aInfo[32] = {
 //          clockMask pcrAddress gpioAddress gpioBit muxValue
 /*  0 */  { 0 },
 /*  1 */  { 0 },
 /*  2 */  { 0 },
 /*  3 */  { 0 },
#if (ADC0_SE4a_PIN_SEL == 1)
 /*  4 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[21]), GPIOE_BasePtr,  21, 0 },
#else
 /*  4 */  { 0 },
#endif
#if (ADC0_SE5a_PIN_SEL == 1)
 /*  5 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[17]), GPIOE_BasePtr,  17, 0 },
#else
 /*  5 */  { 0 },
#endif
 /*  6 */  { 0 },
#if (ADC0_SE7a_PIN_SEL == 1)
 /*  7 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[23]), GPIOE_BasePtr,  23, 0 },
#else
 /*  7 */  { 0 },
#endif
};

/**
 * Peripheral pin mapping information for PWM, Input capture, Output compare
 */
constexpr PcrInfo Tpm0Info[32] = {
 //          clockMask pcrAddress gpioAddress gpioBit muxValue
#if (TPM0_CH0_PIN_SEL == 1)
 /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[3]),  GPIOA_BasePtr,  3,  3 },
#elif (TPM0_CH0_PIN_SEL == 2)
 /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[24]), GPIOE_BasePtr,  24, 3 },
#elif (TPM0_CH0_PIN_SEL == 3)
 /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOC_BasePtr,  1,  4 },
#elif (TPM0_CH0_PIN_SEL == 4)
 /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOD_BasePtr,  0,  4 },
#else
 /*  0 */  { 0 },
#endif
#if (TPM0_CH1_PIN_SEL == 1)
 /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),  GPIOA_BasePtr,  4,  3 },
#elif (TPM0_CH1_PIN_SEL == 2)
 /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[25]), GPIOE_BasePtr,  25, 3 },
#elif (TPM0_CH1_PIN_SEL == 3)
 /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  GPIOC_BasePtr,  2,  4 },
#elif (TPM0_CH1_PIN_SEL == 4)
 /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOD_BasePtr,  1,  4 },
#else
 /*  1 */  { 0 },
#endif
#if (TPM0_CH2_PIN_SEL == 1)
 /*  2 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),  GPIOA_BasePtr,  5,  3 },
#elif (TPM0_CH2_PIN_SEL == 2)
 /*  2 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[29]), GPIOE_BasePtr,  29, 3 },
#elif (TPM0_CH2_PIN_SEL == 3)
 /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),  GPIOC_BasePtr,  3,  4 },
#elif (TPM0_CH2_PIN_SEL == 4)
 /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[2]),  GPIOD_BasePtr,  2,  4 },
#else
 /*  2 */  { 0 },
#endif
#if (TPM0_CH3_PIN_SEL == 1)
 /*  3 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[30]), GPIOE_BasePtr,  30, 3 },
#elif (TPM0_CH3_PIN_SEL == 2)
 /*  3 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),  GPIOC_BasePtr,  4,  4 },
#elif (TPM0_CH3_PIN_SEL == 3)
 /*  3 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[3]),  GPIOD_BasePtr,  3,  4 },
#else
 /*  3 */  { 0 },
#endif
#if (TPM0_CH4_PIN_SEL == 1)
 /*  4 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[8]),  GPIOC_BasePtr,  8,  3 },
#elif (TPM0_CH4_PIN_SEL == 2)
 /*  4 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[31]), GPIOE_BasePtr,  31, 3 },
#elif (TPM0_CH4_PIN_SEL == 3)
 /*  4 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),  GPIOD_BasePtr,  4,  4 },
#else
 /*  4 */  { 0 },
#endif
#if (TPM0_CH5_PIN_SEL == 1)
 /*  5 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOA_BasePtr,  0,  3 },
#elif (TPM0_CH5_PIN_SEL == 2)
 /*  5 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[9]),  GPIOC_BasePtr,  9,  3 },
#elif (TPM0_CH5_PIN_SEL == 3)
 /*  5 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  GPIOD_BasePtr,  5,  4 },
#else
 /*  5 */  { 0 },
#endif
};

/**
 * Peripheral pin mapping information for PWM, Input capture, Output compare
 */
constexpr PcrInfo Tpm1Info[32] = {
 //          clockMask pcrAddress gpioAddress gpioBit muxValue
#if (TPM1_CH0_PIN_SEL == 1)
 /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]), GPIOA_BasePtr,  12, 3 },
#elif (TPM1_CH0_PIN_SEL == 2)
 /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOB_BasePtr,  0,  3 },
#elif (TPM1_CH0_PIN_SEL == 3)
 /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[20]), GPIOE_BasePtr,  20, 3 },
#else
 /*  0 */  { 0 },
#endif
#if (TPM1_CH1_PIN_SEL == 1)
 /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]), GPIOA_BasePtr,  13, 3 },
#elif (TPM1_CH1_PIN_SEL == 2)
 /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOB_BasePtr,  1,  3 },
#elif (TPM1_CH1_PIN_SEL == 3)
 /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[21]), GPIOE_BasePtr,  21, 3 },
#else
 /*  1 */  { 0 },
#endif
};

/**
 * Peripheral pin mapping information for PWM, Input capture, Output compare
 */
constexpr PcrInfo Tpm2Info[32] = {
 //          clockMask pcrAddress gpioAddress gpioBit muxValue
#if (TPM2_CH0_PIN_SEL == 1)
 /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOA_BasePtr,  1,  3 },
#elif (TPM2_CH0_PIN_SEL == 2)
 /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  GPIOB_BasePtr,  2,  3 },
#elif (TPM2_CH0_PIN_SEL == 3)
 /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[18]), GPIOB_BasePtr,  18, 3 },
#elif (TPM2_CH0_PIN_SEL == 4)
 /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[22]), GPIOE_BasePtr,  22, 3 },
#else
 /*  0 */  { 0 },
#endif
#if (TPM2_CH1_PIN_SEL == 1)
 /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),  GPIOA_BasePtr,  2,  3 },
#elif (TPM2_CH1_PIN_SEL == 2)
 /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  GPIOB_BasePtr,  3,  3 },
#elif (TPM2_CH1_PIN_SEL == 3)
 /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[19]), GPIOB_BasePtr,  19, 3 },
#elif (TPM2_CH1_PIN_SEL == 4)
 /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[23]), GPIOE_BasePtr,  23, 3 },
#else
 /*  1 */  { 0 },
#endif
};

/**
 * Peripheral pin mapping information for SPI, Serial Peripheral Interface
 */
constexpr PcrInfo Spi0Info[32] = {
 //          clockMask pcrAddress gpioAddress gpioBit muxValue
#if (SPI0_SCK_PIN_SEL == 1)
 /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[5]),  GPIOC_BasePtr,  5,  2 },
#elif (SPI0_SCK_PIN_SEL == 2)
 /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOD_BasePtr,  1,  2 },
#elif (SPI0_SCK_PIN_SEL == 3)
 /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[17]), GPIOE_BasePtr,  17, 2 },
#else
 /*  0 */  { 0 },
#endif
#if (SPI0_MISO_PIN_SEL == 1)
 /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[7]),  GPIOC_BasePtr,  7,  2 },
#elif (SPI0_MISO_PIN_SEL == 2)
 /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[3]),  GPIOD_BasePtr,  3,  2 },
#elif (SPI0_MISO_PIN_SEL == 3)
 /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[6]),  GPIOC_BasePtr,  6,  5 },
#elif (SPI0_MISO_PIN_SEL == 4)
 /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[2]),  GPIOD_BasePtr,  2,  5 },
#elif (SPI0_MISO_PIN_SEL == 5)
 /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[18]), GPIOE_BasePtr,  18, 5 },
#else
 /*  1 */  { 0 },
#endif
#if (SPI0_MOSI_PIN_SEL == 1)
 /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[6]),  GPIOC_BasePtr,  6,  2 },
#elif (SPI0_MOSI_PIN_SEL == 2)
 /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[2]),  GPIOD_BasePtr,  2,  2 },
#elif (SPI0_MOSI_PIN_SEL == 3)
 /*  2 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[18]), GPIOE_BasePtr,  18, 2 },
#elif (SPI0_MOSI_PIN_SEL == 4)
 /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[7]),  GPIOC_BasePtr,  7,  5 },
#elif (SPI0_MOSI_PIN_SEL == 5)
 /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[3]),  GPIOD_BasePtr,  3,  5 },
#else
 /*  2 */  { 0 },
#endif
#if (SPI0_PCS0_PIN_SEL == 1)
 /*  3 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),  GPIOC_BasePtr,  4,  2 },
#elif (SPI0_PCS0_PIN_SEL == 2)
 /*  3 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOD_BasePtr,  0,  2 },
#elif (SPI0_PCS0_PIN_SEL == 3)
 /*  3 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[16]), GPIOE_BasePtr,  16, 2 },
#else
 /*  3 */  { 0 },
#endif
};

/**
 * Peripheral pin mapping information for SPI, Serial Peripheral Interface
 */
constexpr PcrInfo Spi1Info[32] = {
 //          clockMask pcrAddress gpioAddress gpioBit muxValue
#if (SPI1_SCK_PIN_SEL == 1)
 /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),  GPIOC_BasePtr,  3,  2 },
#elif (SPI1_SCK_PIN_SEL == 2)
 /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  GPIOD_BasePtr,  5,  2 },
#else
 /*  0 */  { 0 },
#endif
#if (SPI1_MISO_PIN_SEL == 1)
 /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[17]), GPIOB_BasePtr,  17, 2 },
#elif (SPI1_MISO_PIN_SEL == 2)
 /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[7]),  GPIOD_BasePtr,  7,  2 },
#elif (SPI1_MISO_PIN_SEL == 3)
 /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOE_BasePtr,  0,  2 },
#elif (SPI1_MISO_PIN_SEL == 4)
 /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOB_BasePtr,  1,  4 },
#elif (SPI1_MISO_PIN_SEL == 5)
 /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOB_BasePtr,  0,  5 },
#elif (SPI1_MISO_PIN_SEL == 6)
 /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[16]), GPIOB_BasePtr,  16, 5 },
#elif (SPI1_MISO_PIN_SEL == 7)
 /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),  GPIOD_BasePtr,  6,  5 },
#elif (SPI1_MISO_PIN_SEL == 8)
 /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOE_BasePtr,  1,  5 },
#else
 /*  1 */  { 0 },
#endif
#if (SPI1_MOSI_PIN_SEL == 1)
 /*  2 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[16]), GPIOB_BasePtr,  16, 2 },
#elif (SPI1_MOSI_PIN_SEL == 2)
 /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),  GPIOD_BasePtr,  6,  2 },
#elif (SPI1_MOSI_PIN_SEL == 3)
 /*  2 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOE_BasePtr,  1,  2 },
#elif (SPI1_MOSI_PIN_SEL == 4)
 /*  2 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOB_BasePtr,  0,  4 },
#elif (SPI1_MOSI_PIN_SEL == 5)
 /*  2 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOB_BasePtr,  1,  5 },
#elif (SPI1_MOSI_PIN_SEL == 6)
 /*  2 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[17]), GPIOB_BasePtr,  17, 5 },
#elif (SPI1_MOSI_PIN_SEL == 7)
 /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[7]),  GPIOD_BasePtr,  7,  5 },
#else
 /*  2 */  { 0 },
#endif
#if (SPI1_PCS0_PIN_SEL == 1)
 /*  3 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),  GPIOD_BasePtr,  4,  2 },
#elif (SPI1_PCS0_PIN_SEL == 2)
 /*  3 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),  GPIOC_BasePtr,  4,  5 },
#else
 /*  3 */  { 0 },
#endif
};

/**
 * Peripheral pin mapping information for I2C, Inter-Integrated-Circuit Interface
 */
constexpr PcrInfo I2c0Info[32] = {
 //          clockMask pcrAddress gpioAddress gpioBit muxValue
#if (I2C0_SCL_PIN_SEL == 1)
 /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOB_BasePtr,  0,  2 },
#elif (I2C0_SCL_PIN_SEL == 2)
 /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[2]),  GPIOB_BasePtr,  2,  2 },
#elif (I2C0_SCL_PIN_SEL == 3)
 /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[8]),  GPIOC_BasePtr,  8,  2 },
#elif (I2C0_SCL_PIN_SEL == 4)
 /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[24]), GPIOE_BasePtr,  24, 5 },
#else
 /*  0 */  { 0 },
#endif
#if (I2C0_SDA_PIN_SEL == 1)
 /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOB_BasePtr,  1,  2 },
#elif (I2C0_SDA_PIN_SEL == 2)
 /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  GPIOB_BasePtr,  3,  2 },
#elif (I2C0_SDA_PIN_SEL == 3)
 /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[9]),  GPIOC_BasePtr,  9,  2 },
#elif (I2C0_SDA_PIN_SEL == 4)
 /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[18]), GPIOE_BasePtr,  18, 4 },
#elif (I2C0_SDA_PIN_SEL == 5)
 /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[25]), GPIOE_BasePtr,  25, 5 },
#else
 /*  1 */  { 0 },
#endif
};

/**
 * Peripheral pin mapping information for I2C, Inter-Integrated-Circuit Interface
 */
constexpr PcrInfo I2c1Info[32] = {
 //          clockMask pcrAddress gpioAddress gpioBit muxValue
#if (I2C1_SCL_PIN_SEL == 1)
 /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[3]),  GPIOA_BasePtr,  3,  2 },
#elif (I2C1_SCL_PIN_SEL == 2)
 /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOC_BasePtr,  1,  2 },
#elif (I2C1_SCL_PIN_SEL == 3)
 /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[10]), GPIOC_BasePtr,  10, 2 },
#elif (I2C1_SCL_PIN_SEL == 4)
 /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[7]),  GPIOD_BasePtr,  7,  4 },
#elif (I2C1_SCL_PIN_SEL == 5)
 /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOE_BasePtr,  1,  6 },
#else
 /*  0 */  { 0 },
#endif
#if (I2C1_SDA_PIN_SEL == 1)
 /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),  GPIOA_BasePtr,  4,  2 },
#elif (I2C1_SDA_PIN_SEL == 2)
 /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  GPIOC_BasePtr,  2,  2 },
#elif (I2C1_SDA_PIN_SEL == 3)
 /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[11]), GPIOC_BasePtr,  11, 2 },
#elif (I2C1_SDA_PIN_SEL == 4)
 /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),  GPIOD_BasePtr,  6,  4 },
#elif (I2C1_SDA_PIN_SEL == 5)
 /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOE_BasePtr,  0,  6 },
#else
 /*  1 */  { 0 },
#endif
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
using gpioA_0              = const USBDM::GpioA<0>;
using gpioA_1              = const USBDM::GpioA<1>;
using gpio_D0              = const USBDM::GpioA<1>;
using gpioA_2              = const USBDM::GpioA<2>;
using gpio_D1              = const USBDM::GpioA<2>;
using gpioA_3              = const USBDM::GpioA<3>;
using gpioA_4              = const USBDM::GpioA<4>;
using gpioA_5              = const USBDM::GpioA<5>;
using gpio_D9              = const USBDM::GpioA<5>;
using gpioA_12             = const USBDM::GpioA<12>;
using gpio_D2              = const USBDM::GpioA<12>;
using gpioA_13             = const USBDM::GpioA<13>;
using gpio_D4              = const USBDM::GpioA<13>;
using gpio_LED_BLUE        = const USBDM::GpioA<13>;
using gpioA_18             = const USBDM::GpioA<18>;
using gpioA_19             = const USBDM::GpioA<19>;
using gpioA_20             = const USBDM::GpioA<20>;
using gpioB_0              = const USBDM::GpioB<0>;
using gpio_A5              = const USBDM::GpioB<0>;
using gpioB_1              = const USBDM::GpioB<1>;
using gpio_A4              = const USBDM::GpioB<1>;
using gpioB_2              = const USBDM::GpioB<2>;
using gpioB_3              = const USBDM::GpioB<3>;
using gpioB_16             = const USBDM::GpioB<16>;
using gpioB_17             = const USBDM::GpioB<17>;
using gpioB_18             = const USBDM::GpioB<18>;
using gpio_LED_RED         = const USBDM::GpioB<18>;
using gpioB_19             = const USBDM::GpioB<19>;
using gpio_LED_GREEN       = const USBDM::GpioB<19>;
using gpioC_0              = const USBDM::GpioC<0>;
using gpio_A1              = const USBDM::GpioC<0>;
using gpioC_1              = const USBDM::GpioC<1>;
using gpioC_2              = const USBDM::GpioC<2>;
using gpio_MAG_INT         = const USBDM::GpioC<2>;
using gpioC_3              = const USBDM::GpioC<3>;
using gpioC_4              = const USBDM::GpioC<4>;
using gpio_D10             = const USBDM::GpioC<4>;
using gpioC_5              = const USBDM::GpioC<5>;
using gpio_D13             = const USBDM::GpioC<5>;
using gpioC_6              = const USBDM::GpioC<6>;
using gpio_D11             = const USBDM::GpioC<6>;
using gpioC_7              = const USBDM::GpioC<7>;
using gpio_D12             = const USBDM::GpioC<7>;
using gpioC_8              = const USBDM::GpioC<8>;
using gpio_D7              = const USBDM::GpioC<8>;
using gpioC_9              = const USBDM::GpioC<9>;
using gpio_D6              = const USBDM::GpioC<9>;
using gpioC_10             = const USBDM::GpioC<10>;
using gpioC_11             = const USBDM::GpioC<11>;
using gpioD_0              = const USBDM::GpioD<0>;
using gpioD_1              = const USBDM::GpioD<1>;
using gpioD_2              = const USBDM::GpioD<2>;
using gpioD_3              = const USBDM::GpioD<3>;
using gpioD_4              = const USBDM::GpioD<4>;
using gpioD_5              = const USBDM::GpioD<5>;
using gpioD_6              = const USBDM::GpioD<6>;
using gpio_D14             = const USBDM::GpioD<6>;
using gpio_ONBOARD_SDA     = const USBDM::GpioD<6>;
using gpioD_7              = const USBDM::GpioD<7>;
using gpio_D15             = const USBDM::GpioD<7>;
using gpio_ONBOARD_SCL     = const USBDM::GpioD<7>;
using gpioE_0              = const USBDM::GpioE<0>;
using gpioE_1              = const USBDM::GpioE<1>;
using gpioE_16             = const USBDM::GpioE<16>;
using gpio_A0              = const USBDM::GpioE<16>;
using gpioE_17             = const USBDM::GpioE<17>;
using gpioE_18             = const USBDM::GpioE<18>;
using gpioE_20             = const USBDM::GpioE<20>;
using gpio_A2              = const USBDM::GpioE<20>;
using gpioE_21             = const USBDM::GpioE<21>;
using gpio_A3              = const USBDM::GpioE<21>;
using gpioE_22             = const USBDM::GpioE<22>;
using gpioE_23             = const USBDM::GpioE<23>;
using gpioE_24             = const USBDM::GpioE<24>;
using gpio_D5              = const USBDM::GpioE<24>;
using gpioE_25             = const USBDM::GpioE<25>;
using gpio_D3              = const USBDM::GpioE<25>;
using gpioE_29             = const USBDM::GpioE<29>;
using gpioE_30             = const USBDM::GpioE<30>;
using gpioE_31             = const USBDM::GpioE<31>;
using gpio_D8              = const USBDM::GpioE<31>;
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
template<uint8_t adcChannel> using Adc0 =
   Adc_T<getPortClockMask(adcChannel,Adc0Info), getPcrReg(adcChannel,Adc0Info), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG), ADC0_CLOCK_MASK, adcChannel>;

#if (PTB0_SIG_SEL == 0)
using adc0_se8             = const USBDM::Adc0<8>;
using adc_A5               = const USBDM::Adc0<8>;
#endif
#if (PTB1_SIG_SEL == 0)
using adc0_se9             = const USBDM::Adc0<9>;
using adc_A4               = const USBDM::Adc0<9>;
#endif
#if (PTB2_SIG_SEL == 0)
using adc0_se12            = const USBDM::Adc0<12>;
#endif
#if (PTB3_SIG_SEL == 0)
using adc0_se13            = const USBDM::Adc0<13>;
#endif
#if (PTC0_SIG_SEL == 0)
using adc0_se14            = const USBDM::Adc0<14>;
using adc_A1               = const USBDM::Adc0<14>;
#endif
#if (PTC1_SIG_SEL == 0)
using adc0_se15            = const USBDM::Adc0<15>;
#endif
#if (PTC2_SIG_SEL == 0)
using adc0_se11            = const USBDM::Adc0<11>;
using adc_MAG_INT          = const USBDM::Adc0<11>;
#endif
#if (PTD1_SIG_SEL == 0)
using adc0_se5b            = const USBDM::Adc0<5>;
#endif
#if (PTD5_SIG_SEL == 0)
using adc0_se6b            = const USBDM::Adc0<6>;
#endif
#if (PTD6_SIG_SEL == 0)
using adc0_se7b            = const USBDM::Adc0<7>;
using adc_D14              = const USBDM::Adc0<7>;
using adc_ONBOARD_SDA      = const USBDM::Adc0<7>;
#endif
#if (PTE16_SIG_SEL == 0)
using adc0_se1             = const USBDM::Adc0<1>;
using adc_A0               = const USBDM::Adc0<1>;
#endif
#if (PTE18_SIG_SEL == 0)
using adc0_se2             = const USBDM::Adc0<2>;
#endif
#if (PTE20_SIG_SEL == 0)
using adc0_se0             = const USBDM::Adc0<0>;
using adc_A2               = const USBDM::Adc0<0>;
#endif
#if (PTE22_SIG_SEL == 0)
using adc0_se3             = const USBDM::Adc0<3>;
#endif
#if (PTE29_SIG_SEL == 0)
using adc0_se4b            = const USBDM::Adc0<4>;
#endif
#if (PTE30_SIG_SEL == 0)
using adc0_se23            = const USBDM::Adc0<23>;
#endif
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
template<uint8_t adcChannel> using Adc0a =
   Adc_T<getPortClockMask(adcChannel,Adc0aInfo), getPcrReg(adcChannel,Adc0aInfo), ADC0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, ADC0_CLOCK_REG), ADC0_CLOCK_MASK, adcChannel>;

#if (PTE17_SIG_SEL == 0)
using adc0_se5a            = const USBDM::Adc0a<5>;
#endif
#if (PTE21_SIG_SEL == 0)
using adc0_se4a            = const USBDM::Adc0a<4>;
using adc_A3               = const USBDM::Adc0a<4>;
#endif
#if (PTE23_SIG_SEL == 0)
using adc0_se7a            = const USBDM::Adc0a<7>;
#endif
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
/**
 * Convenience templated class representing a TPM
 *
 * Example
 * @code
 * // Instantiate the tpm channel (for TPM0 CH6)
 * const USBDM::Tpm0<6>   tpm0_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * tpm0_ch6.setPwmOutput(200, USBDM::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * tpm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * tpm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam tpmChannel    TPM channel
 */
template<uint8_t tpmChannel> using Tpm0 =
   Tpm_T<getPortClockMask(tpmChannel,Tpm0Info), getPcrReg(tpmChannel,Tpm0Info), getPcrMux(tpmChannel,Tpm0Info), TPM0_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM0_CLOCK_REG), TPM0_CLOCK_MASK, TPM0_SC, tpmChannel>;

#if (PTA0_SIG_SEL == 3)
using tpm0_ch5             = const USBDM::Tpm0<5>;
#endif
#if (PTA3_SIG_SEL == 3)
using tpm0_ch0             = const USBDM::Tpm0<0>;
#endif
#if (PTA4_SIG_SEL == 3)
using tpm0_ch1             = const USBDM::Tpm0<1>;
#endif
#if (PTA5_SIG_SEL == 3)
using tpm0_ch2             = const USBDM::Tpm0<2>;
using tpm_D9               = const USBDM::Tpm0<2>;
#endif
#if (PTC1_SIG_SEL == 4)
using tpm0_ch0             = const USBDM::Tpm0<0>;
#endif
#if (PTC2_SIG_SEL == 4)
using tpm0_ch1             = const USBDM::Tpm0<1>;
using tpm_MAG_INT          = const USBDM::Tpm0<1>;
#endif
#if (PTC3_SIG_SEL == 4)
using tpm0_ch2             = const USBDM::Tpm0<2>;
#endif
#if (PTC4_SIG_SEL == 4)
using tpm0_ch3             = const USBDM::Tpm0<3>;
using tpm_D10              = const USBDM::Tpm0<3>;
#endif
#if (PTC8_SIG_SEL == 3)
using tpm0_ch4             = const USBDM::Tpm0<4>;
using tpm_D7               = const USBDM::Tpm0<4>;
#endif
#if (PTC9_SIG_SEL == 3)
using tpm0_ch5             = const USBDM::Tpm0<5>;
using tpm_D6               = const USBDM::Tpm0<5>;
#endif
#if (PTD0_SIG_SEL == 4)
using tpm0_ch0             = const USBDM::Tpm0<0>;
#endif
#if (PTD1_SIG_SEL == 4)
using tpm0_ch1             = const USBDM::Tpm0<1>;
#endif
#if (PTD2_SIG_SEL == 4)
using tpm0_ch2             = const USBDM::Tpm0<2>;
#endif
#if (PTD3_SIG_SEL == 4)
using tpm0_ch3             = const USBDM::Tpm0<3>;
#endif
#if (PTD4_SIG_SEL == 4)
using tpm0_ch4             = const USBDM::Tpm0<4>;
#endif
#if (PTD5_SIG_SEL == 4)
using tpm0_ch5             = const USBDM::Tpm0<5>;
#endif
#if (PTE24_SIG_SEL == 3)
using tpm0_ch0             = const USBDM::Tpm0<0>;
using tpm_D5               = const USBDM::Tpm0<0>;
#endif
#if (PTE25_SIG_SEL == 3)
using tpm0_ch1             = const USBDM::Tpm0<1>;
using tpm_D3               = const USBDM::Tpm0<1>;
#endif
#if (PTE29_SIG_SEL == 3)
using tpm0_ch2             = const USBDM::Tpm0<2>;
#endif
#if (PTE30_SIG_SEL == 3)
using tpm0_ch3             = const USBDM::Tpm0<3>;
#endif
#if (PTE31_SIG_SEL == 3)
using tpm0_ch4             = const USBDM::Tpm0<4>;
using tpm_D8               = const USBDM::Tpm0<4>;
#endif
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
/**
 * Convenience templated class representing a TPM
 *
 * Example
 * @code
 * // Instantiate the tpm channel (for TPM0 CH6)
 * const USBDM::Tpm0<6>   tpm0_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * tpm0_ch6.setPwmOutput(200, USBDM::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * tpm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * tpm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam tpmChannel    TPM channel
 */
template<uint8_t tpmChannel> using Tpm1 =
   Tpm_T<getPortClockMask(tpmChannel,Tpm1Info), getPcrReg(tpmChannel,Tpm1Info), getPcrMux(tpmChannel,Tpm1Info), TPM1_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM1_CLOCK_REG), TPM1_CLOCK_MASK, TPM0_SC, tpmChannel>;

#if (PTA12_SIG_SEL == 3)
using tpm1_ch0             = const USBDM::Tpm1<0>;
using tpm_D2               = const USBDM::Tpm1<0>;
#endif
#if (PTA13_SIG_SEL == 3)
using tpm1_ch1             = const USBDM::Tpm1<1>;
using tpm_D4               = const USBDM::Tpm1<1>;
using tpm_LED_BLUE         = const USBDM::Tpm1<1>;
#endif
#if (PTB0_SIG_SEL == 3)
using tpm1_ch0             = const USBDM::Tpm1<0>;
using tpm_A5               = const USBDM::Tpm1<0>;
#endif
#if (PTB1_SIG_SEL == 3)
using tpm1_ch1             = const USBDM::Tpm1<1>;
using tpm_A4               = const USBDM::Tpm1<1>;
#endif
#if (PTE20_SIG_SEL == 3)
using tpm1_ch0             = const USBDM::Tpm1<0>;
using tpm_A2               = const USBDM::Tpm1<0>;
#endif
#if (PTE21_SIG_SEL == 3)
using tpm1_ch1             = const USBDM::Tpm1<1>;
using tpm_A3               = const USBDM::Tpm1<1>;
#endif
/**
 * @}
 */
/**
* @addtogroup PwmIO_Group PWM, Input capture, Output compare
* @brief Allows use of port pins as PWM outputs
* @{
*/
/**
 * Convenience templated class representing a TPM
 *
 * Example
 * @code
 * // Instantiate the tpm channel (for TPM0 CH6)
 * const USBDM::Tpm0<6>   tpm0_ch6;
 *
 * // Initialise PWM with initial period and alignment
 * tpm0_ch6.setPwmOutput(200, USBDM::ftm_leftAlign);
 *
 * // Change period (in ticks)
 * tpm0_ch6.setPeriod(500);
 *
 * // Change duty cycle (in percent)
 * tpm0_ch6.setDutyCycle(45);
 * @endcode
 *
 * @tparam tpmChannel    TPM channel
 */
template<uint8_t tpmChannel> using Tpm2 =
   Tpm_T<getPortClockMask(tpmChannel,Tpm2Info), getPcrReg(tpmChannel,Tpm2Info), getPcrMux(tpmChannel,Tpm2Info), TPM2_BasePtr, SIM_BasePtr+offsetof(SIM_Type, TPM2_CLOCK_REG), TPM2_CLOCK_MASK, TPM0_SC, tpmChannel>;

#if (PTA1_SIG_SEL == 3)
using tpm2_ch0             = const USBDM::Tpm2<0>;
using tpm_D0               = const USBDM::Tpm2<0>;
#endif
#if (PTA2_SIG_SEL == 3)
using tpm2_ch1             = const USBDM::Tpm2<1>;
using tpm_D1               = const USBDM::Tpm2<1>;
#endif
#if (PTB2_SIG_SEL == 3)
using tpm2_ch0             = const USBDM::Tpm2<0>;
#endif
#if (PTB3_SIG_SEL == 3)
using tpm2_ch1             = const USBDM::Tpm2<1>;
#endif
#if (PTB18_SIG_SEL == 3)
using tpm2_ch0             = const USBDM::Tpm2<0>;
using tpm_LED_RED          = const USBDM::Tpm2<0>;
#endif
#if (PTB19_SIG_SEL == 3)
using tpm2_ch1             = const USBDM::Tpm2<1>;
using tpm_LED_GREEN        = const USBDM::Tpm2<1>;
#endif
#if (PTE22_SIG_SEL == 3)
using tpm2_ch0             = const USBDM::Tpm2<0>;
#endif
#if (PTE23_SIG_SEL == 3)
using tpm2_ch1             = const USBDM::Tpm2<1>;
#endif
/**
 * @}
 */
/**
* @addtogroup SpiIO_Group SPI, Serial Peripheral Interface
* @brief Pins used for SPI functions
* @{
*/
/**
 * Convenience templated class representing an SPI pin
 *
 * Example
 * @code
 * using spi0_PCS0 = const USBDM::Spi0Pin<3>;
 * @endcode
 *
 * @tparam spiPinNum    SPI pin number (index into SpiInfo[])
 */
template<uint8_t spiPinNum> using Spi0Pin =
   Pcr_T<getPortClockMask(spiPinNum,Spi0Info), getPcrReg(spiPinNum,Spi0Info), PORT_PCR_MUX(getPcrMux(spiPinNum, Spi0Info))|DEFAULT_PCR>;

using spi0_PCS0            = const USBDM::Spi0Pin<3>;
using spi0_SCK             = const USBDM::Spi0Pin<0>;
using spi0_MOSI            = const USBDM::Spi0Pin<2>;
using spi0_MISO            = const USBDM::Spi0Pin<1>;
/**
 * @}
 */
/**
* @addtogroup SpiIO_Group SPI, Serial Peripheral Interface
* @brief Pins used for SPI functions
* @{
*/
/**
 * Convenience templated class representing an SPI pin
 *
 * Example
 * @code
 * using spi0_PCS0 = const USBDM::Spi0Pin<3>;
 * @endcode
 *
 * @tparam spiPinNum    SPI pin number (index into SpiInfo[])
 */
template<uint8_t spiPinNum> using Spi1Pin =
   Pcr_T<getPortClockMask(spiPinNum,Spi1Info), getPcrReg(spiPinNum,Spi1Info), PORT_PCR_MUX(getPcrMux(spiPinNum, Spi1Info))|DEFAULT_PCR>;

using spi1_MOSI            = const USBDM::Spi1Pin<2>;
using spi1_MISO            = const USBDM::Spi1Pin<1>;
using spi1_SCK             = const USBDM::Spi1Pin<0>;
using spi1_PCS0            = const USBDM::Spi1Pin<3>;
/**
 * @}
 */
/**
* @addtogroup I2CIO_Group I2C, Inter-Integrated-Circuit Interface
* @brief Pins used for I2C functions
* @{
*/
/**
 * Convenience templated class representing PCR associated with a I2C pin
 *
 * Example
 * @code
 * using i2c0_SCLPin = const USBDM::I2c0Pin<3>;
 * @endcode
 *
 * @tparam i2cPinIndex    I2C pin number (index into I2cInfo[])
 */
template<uint8_t i2cPinIndex> using I2c0Pcr =
   Pcr_T<getPortClockMask(i2cPinIndex,I2c0Info), getPcrReg(i2cPinIndex,I2c0Info), PORT_PCR_MUX(getPcrMux(i2cPinIndex, I2c0Info))|I2C_DEFAULT_PCR>;

/**
 * Convenience templated class representing a GPIO used as I2C pin
 *
 * Example
 * @code
 * using i2c0_SCLGpio = const USBDM::I2c0Gpio<3>;
 * @endcode
 *
 * @tparam i2cPinIndex    I2C pin number (index into I2cInfo[])
 */
template<uint8_t i2cPinIndex> using I2c0Gpio =
   Gpio_T<getPortClockMask(i2cPinIndex,I2c0Info), getPcrReg(i2cPinIndex,I2c0Info), PORT_PCR_MUX(FIXED_GPIO_FN)|I2C_DEFAULT_PCR,
             getGpioAddress(i2cPinIndex,I2c0Info),   getGpioBit(i2cPinIndex,I2c0Info)>;
using i2c0_SCLPcr    = const USBDM::I2c0Pcr<0>;
using i2c0_SCLGpio   = const USBDM::I2c0Gpio<0>;
using i2c0_SDAPcr    = const USBDM::I2c0Pcr<1>;
using i2c0_SDAGpio   = const USBDM::I2c0Gpio<1>;
/**
 * @}
 */
/**
* @addtogroup I2CIO_Group I2C, Inter-Integrated-Circuit Interface
* @brief Pins used for I2C functions
* @{
*/
/**
 * Convenience templated class representing PCR associated with a I2C pin
 *
 * Example
 * @code
 * using i2c0_SCLPin = const USBDM::I2c0Pin<3>;
 * @endcode
 *
 * @tparam i2cPinIndex    I2C pin number (index into I2cInfo[])
 */
template<uint8_t i2cPinIndex> using I2c1Pcr =
   Pcr_T<getPortClockMask(i2cPinIndex,I2c1Info), getPcrReg(i2cPinIndex,I2c1Info), PORT_PCR_MUX(getPcrMux(i2cPinIndex, I2c1Info))|I2C_DEFAULT_PCR>;

/**
 * Convenience templated class representing a GPIO used as I2C pin
 *
 * Example
 * @code
 * using i2c0_SCLGpio = const USBDM::I2c0Gpio<3>;
 * @endcode
 *
 * @tparam i2cPinIndex    I2C pin number (index into I2cInfo[])
 */
template<uint8_t i2cPinIndex> using I2c1Gpio =
   Gpio_T<getPortClockMask(i2cPinIndex,I2c1Info), getPcrReg(i2cPinIndex,I2c1Info), PORT_PCR_MUX(FIXED_GPIO_FN)|I2C_DEFAULT_PCR,
             getGpioAddress(i2cPinIndex,I2c1Info),   getGpioBit(i2cPinIndex,I2c1Info)>;
using i2c1_SCLPcr    = const USBDM::I2c1Pcr<0>;
using i2c1_SCLGpio   = const USBDM::I2c1Gpio<0>;
using i2c1_SDAPcr    = const USBDM::I2c1Pcr<1>;
using i2c1_SDAGpio   = const USBDM::I2c1Gpio<1>;
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
