/**
 * @file      pin_mapping.h (derived from pin_mapping-MKL46Z4.h)
 * @version   1.1.0
 * @brief     Pin declarations for MKL46Z4
 */

#ifndef PIN_MAPPING_H_
#define PIN_MAPPING_H_

#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

//================================
// Validators
// <validate=net.sourceforge.usbdm.annotationEditor.validators.PinMappingValidator>

// <h> Clock settings for TPM

// TPM_SC.CMOD ================================
//
//   <o> TPM_SC.CMOD Clock source
//   <i> Selects the clock source for the TPM module. [TPM_SC.CMOD]
//     <0=> Disabled
//     <1=> Internal clock
//     <2=> External clock
//     <3=> Reserved
//     <1=> Default
// TPM_SC.PS ================================
//
//   <o1> TPM_SC.PS Clock prescaler
//   <i> Selects the prescaler for the TPM module. [TPM_SC.PS]
//     <0=> Divide by 1
//     <1=> Divide by 2
//     <2=> Divide by 4
//     <3=> Divide by 8
//     <4=> Divide by 16
//     <5=> Divide by 32
//     <6=> Divide by 64
//     <7=> Divide by 128
//     <0=> Default
#define TPM_SC               (TPM_SC_CMOD(0x1)|TPM_SC_PS(0x0))

// </h>

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
#define TPM0_SC              (TPM_SC_CMOD(0x1)|TPM_SC_PS(0x0))

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
#define TPM1_SC              (TPM_SC_CMOD(0x1)|TPM_SC_PS(0x0))

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
#define TPM2_SC              (TPM_SC_CMOD(0x1)|TPM_SC_PS(0x0))

// </h>

// Use USBDM namespace
//
//   <q> Place CPP objects in the USBDM namespace 
//   <i> This will require us of "using namespace USBDM" directive
//     <0=> Disabled
//     <1=> Enabled
#define USBDM_USE_NAMESPACES 0

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

// <h> Port A Pins

// Signal mapping for PTA0 pin
//   <o> PTA0 [TSI0_CH1, GPIOA_0, TPM0_CH5, SWD_CLK]<name=PTA0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA0 pin
//     <-2=> SWD_CLK (reset default)<selection=SWD_CLK_PIN_SEL,PTA0 (reset default)>
//     <0=> TSI0_CH1<selection=TSI0_CH1_PIN_SEL,PTA0>
//     <1=> GPIOA_0<selection=GPIOA_0_PIN_SEL,PTA0>
//     <3=> TPM0_CH5<selection=TPM0_CH5_PIN_SEL,PTA0>
//     <7=> SWD_CLK<selection=SWD_CLK_PIN_SEL,PTA0>
//     <-2=> Default
#define PTA0_SIG_SEL         -2

// Signal mapping for PTA1 pin
//   <o> PTA1 (Alias:D0) [TSI0_CH2, GPIOA_1, UART0_RX, TPM2_CH0]<name=PTA1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA1 pin
//     <-2=> Disabled (reset default)
//     <0=> TSI0_CH2<selection=TSI0_CH2_PIN_SEL,PTA1 (Alias:D0)>
//     <1=> GPIOA_1<selection=GPIOA_1_PIN_SEL,PTA1 (Alias:D0)>
//     <2=> UART0_RX<selection=UART0_RX_PIN_SEL,PTA1 (Alias:D0)>
//     <3=> TPM2_CH0<selection=TPM2_CH0_PIN_SEL,PTA1 (Alias:D0)>
//     <1=> Default
#define PTA1_SIG_SEL         1

// Signal mapping for PTA2 pin
//   <o> PTA2 (Alias:D1) [TSI0_CH3, GPIOA_2, UART0_TX, TPM2_CH1]<name=PTA2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA2 pin
//     <-2=> Disabled (reset default)
//     <0=> TSI0_CH3<selection=TSI0_CH3_PIN_SEL,PTA2 (Alias:D1)>
//     <1=> GPIOA_2<selection=GPIOA_2_PIN_SEL,PTA2 (Alias:D1)>
//     <2=> UART0_TX<selection=UART0_TX_PIN_SEL,PTA2 (Alias:D1)>
//     <3=> TPM2_CH1<selection=TPM2_CH1_PIN_SEL,PTA2 (Alias:D1)>
//     <1=> Default
#define PTA2_SIG_SEL         1

// Signal mapping for PTA3 pin
//   <o> PTA3 [TSI0_CH4, GPIOA_3, I2C1_SCL, TPM0_CH0, SWD_DIO]<name=PTA3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA3 pin
//     <-2=> SWD_DIO (reset default)<selection=SWD_DIO_PIN_SEL,PTA3 (reset default)>
//     <0=> TSI0_CH4<selection=TSI0_CH4_PIN_SEL,PTA3>
//     <1=> GPIOA_3<selection=GPIOA_3_PIN_SEL,PTA3>
//     <2=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTA3>
//     <3=> TPM0_CH0<selection=TPM0_CH0_PIN_SEL,PTA3>
//     <7=> SWD_DIO<selection=SWD_DIO_PIN_SEL,PTA3>
//     <-2=> Default
#define PTA3_SIG_SEL         -2

// Signal mapping for PTA4 pin
//   <o> PTA4 (Alias:D4) [TSI0_CH5, GPIOA_4, I2C1_SDA, TPM0_CH1, NMI_b]<name=PTA4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA4 pin
//     <-2=> NMI_b (reset default)<selection=NMI_b_PIN_SEL,PTA4 (Alias:D4) (reset default)>
//     <0=> TSI0_CH5<selection=TSI0_CH5_PIN_SEL,PTA4 (Alias:D4)>
//     <1=> GPIOA_4<selection=GPIOA_4_PIN_SEL,PTA4 (Alias:D4)>
//     <2=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTA4 (Alias:D4)>
//     <3=> TPM0_CH1<selection=TPM0_CH1_PIN_SEL,PTA4 (Alias:D4)>
//     <7=> NMI_b<selection=NMI_b_PIN_SEL,PTA4 (Alias:D4)>
//     <1=> Default
#define PTA4_SIG_SEL         1

// Signal mapping for PTA5 pin
//   <o> PTA5 (Alias:D5) [GPIOA_5, USB_CLKIN, TPM0_CH2, I2S0_TX_BCLK]<name=PTA5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA5 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_5<selection=GPIOA_5_PIN_SEL,PTA5 (Alias:D5)>
//     <2=> USB_CLKIN<selection=USB_CLKIN_PIN_SEL,PTA5 (Alias:D5)>
//     <3=> TPM0_CH2<selection=TPM0_CH2_PIN_SEL,PTA5 (Alias:D5)>
//     <6=> I2S0_TX_BCLK<selection=I2S0_TX_BCLK_PIN_SEL,PTA5 (Alias:D5)>
//     <1=> Default
#define PTA5_SIG_SEL         1

// Signal mapping for PTA6 pin
//   <o> PTA6 [GPIOA_6, TPM0_CH3]<name=PTA6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA6 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_6<selection=GPIOA_6_PIN_SEL,PTA6>
//     <3=> TPM0_CH3<selection=TPM0_CH3_PIN_SEL,PTA6>
//     <-2=> Default
#define PTA6_SIG_SEL         -2

// Signal mapping for PTA7 pin
//   <o> PTA7 [GPIOA_7, TPM0_CH4]<name=PTA7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA7 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_7<selection=GPIOA_7_PIN_SEL,PTA7>
//     <3=> TPM0_CH4<selection=TPM0_CH4_PIN_SEL,PTA7>
//     <-2=> Default
#define PTA7_SIG_SEL         -2

// Signal mapping for PTA12 pin
//   <o> PTA12 (Alias:D3) [GPIOA_12, TPM1_CH0, I2S0_TXD0]<name=PTA12_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA12 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_12<selection=GPIOA_12_PIN_SEL,PTA12 (Alias:D3)>
//     <3=> TPM1_CH0<selection=TPM1_CH0_PIN_SEL,PTA12 (Alias:D3)>
//     <6=> I2S0_TXD0<selection=I2S0_TXD0_PIN_SEL,PTA12 (Alias:D3)>
//     <1=> Default
#define PTA12_SIG_SEL        1

// Signal mapping for PTA13 pin
//   <o> PTA13 (Alias:D8) [GPIOA_13, TPM1_CH1, I2S0_TX_FS]<name=PTA13_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA13 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_13<selection=GPIOA_13_PIN_SEL,PTA13 (Alias:D8)>
//     <3=> TPM1_CH1<selection=TPM1_CH1_PIN_SEL,PTA13 (Alias:D8)>
//     <6=> I2S0_TX_FS<selection=I2S0_TX_FS_PIN_SEL,PTA13 (Alias:D8)>
//     <1=> Default
#define PTA13_SIG_SEL        1

// Signal mapping for PTA14 pin
//   <o> PTA14 [GPIOA_14, SPI0_PCS0, UART0_TX, I2S0_RX_BCLK, I2S0_TXD0]<name=PTA14_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA14 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_14<selection=GPIOA_14_PIN_SEL,PTA14>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTA14>
//     <3=> UART0_TX<selection=UART0_TX_PIN_SEL,PTA14>
//     <6=> I2S0_RX_BCLK<selection=I2S0_RX_BCLK_PIN_SEL,PTA14>
//     <7=> I2S0_TXD0<selection=I2S0_TXD0_PIN_SEL,PTA14>
//     <-2=> Default
#define PTA14_SIG_SEL        -2

// Signal mapping for PTA15 pin
//   <o> PTA15 [GPIOA_15, SPI0_SCK, UART0_RX, I2S0_RXD0]<name=PTA15_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA15 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_15<selection=GPIOA_15_PIN_SEL,PTA15>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTA15>
//     <3=> UART0_RX<selection=UART0_RX_PIN_SEL,PTA15>
//     <6=> I2S0_RXD0<selection=I2S0_RXD0_PIN_SEL,PTA15>
//     <-2=> Default
#define PTA15_SIG_SEL        -2

// Signal mapping for PTA16 pin
//   <o> PTA16 [GPIOA_16, SPI0_MOSI, SPI0_MISO, I2S0_RX_FS, I2S0_RXD0]<name=PTA16_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA16 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_16<selection=GPIOA_16_PIN_SEL,PTA16>
//     <2=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTA16>
//     <5=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTA16>
//     <6=> I2S0_RX_FS<selection=I2S0_RX_FS_PIN_SEL,PTA16>
//     <7=> I2S0_RXD0<selection=I2S0_RXD0_PIN_SEL,PTA16>
//     <-2=> Default
#define PTA16_SIG_SEL        -2

// Signal mapping for PTA17 pin
//   <o> PTA17 [GPIOA_17, SPI0_MISO, SPI0_MOSI, I2S0_MCLK]<name=PTA17_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA17 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_17<selection=GPIOA_17_PIN_SEL,PTA17>
//     <2=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTA17>
//     <5=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTA17>
//     <6=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTA17>
//     <-2=> Default
#define PTA17_SIG_SEL        -2

// Signal mapping for PTA18 pin
//   <o> PTA18 [EXTAL0, GPIOA_18, UART1_RX, TPM_CLKIN0]<name=PTA18_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA18 pin
//     <-2=> EXTAL0 (reset default)<selection=EXTAL0_PIN_SEL,PTA18 (reset default)>
//     <0=> EXTAL0<selection=EXTAL0_PIN_SEL,PTA18>
//     <1=> GPIOA_18<selection=GPIOA_18_PIN_SEL,PTA18>
//     <3=> UART1_RX<selection=UART1_RX_PIN_SEL,PTA18>
//     <4=> TPM_CLKIN0<selection=TPM_CLKIN0_PIN_SEL,PTA18>
//     <-2=> Default
#define PTA18_SIG_SEL        -2

// Signal mapping for PTA19 pin
//   <o> PTA19 [XTAL0, GPIOA_19, UART1_TX, TPM_CLKIN1, LPTMR0_ALT1]<name=PTA19_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA19 pin
//     <-2=> XTAL0 (reset default)<selection=XTAL0_PIN_SEL,PTA19 (reset default)>
//     <0=> XTAL0<selection=XTAL0_PIN_SEL,PTA19>
//     <1=> GPIOA_19<selection=GPIOA_19_PIN_SEL,PTA19>
//     <3=> UART1_TX<selection=UART1_TX_PIN_SEL,PTA19>
//     <4=> TPM_CLKIN1<selection=TPM_CLKIN1_PIN_SEL,PTA19>
//     <6=> LPTMR0_ALT1<selection=LPTMR0_ALT1_PIN_SEL,PTA19>
//     <-2=> Default
#define PTA19_SIG_SEL        -2

// Signal mapping for PTA20 pin
//   <o> PTA20 [RESET_b, GPIOA_20, RESET_b]<name=PTA20_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA20 pin
//     <-2=> RESET_b (reset default)<selection=RESET_b_PIN_SEL,PTA20 (reset default)>
//     <0=> RESET_b<selection=RESET_b_PIN_SEL,PTA20>
//     <1=> GPIOA_20<selection=GPIOA_20_PIN_SEL,PTA20>
//     <7=> RESET_b<selection=RESET_b_PIN_SEL,PTA20>
//     <-2=> Default
#define PTA20_SIG_SEL        -2

// </h>

// <h> Port B Pins

// Signal mapping for PTB0 pin
//   <o> PTB0 (Alias:A0) [LCD_P0/ADC0_SE8/TSI0_CH0, GPIOB_0/LLWU_P5, I2C0_SCL, TPM1_CH0, LCD_P0_fault]<name=PTB0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB0 pin
//     <-2=> LCD_P0/ADC0_SE8/TSI0_CH0 (reset default)<selection=LCD_P0_PIN_SEL,PTB0 (Alias:A0) (reset default)><selection=ADC0_SE8_PIN_SEL,PTB0 (Alias:A0) (reset default)><selection=TSI0_CH0_PIN_SEL,PTB0 (Alias:A0) (reset default)>
//     <0=> LCD_P0/ADC0_SE8/TSI0_CH0<selection=LCD_P0_PIN_SEL,PTB0 (Alias:A0)><selection=ADC0_SE8_PIN_SEL,PTB0 (Alias:A0)><selection=TSI0_CH0_PIN_SEL,PTB0 (Alias:A0)>
//     <1=> GPIOB_0/LLWU_P5<selection=GPIOB_0_PIN_SEL,PTB0 (Alias:A0)><selection=LLWU_P5_PIN_SEL,PTB0 (Alias:A0)>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTB0 (Alias:A0)>
//     <3=> TPM1_CH0<selection=TPM1_CH0_PIN_SEL,PTB0 (Alias:A0)>
//     <7=> LCD_P0_fault<selection=LCD_P0_fault_PIN_SEL,PTB0 (Alias:A0)>
//     <0=> Default
#define PTB0_SIG_SEL         0

// Signal mapping for PTB1 pin
//   <o> PTB1 (Alias:A1) [LCD_P1/ADC0_SE9/TSI0_CH6, GPIOB_1, I2C0_SDA, TPM1_CH1, LCD_P1_fault]<name=PTB1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB1 pin
//     <-2=> LCD_P1/ADC0_SE9/TSI0_CH6 (reset default)<selection=LCD_P1_PIN_SEL,PTB1 (Alias:A1) (reset default)><selection=ADC0_SE9_PIN_SEL,PTB1 (Alias:A1) (reset default)><selection=TSI0_CH6_PIN_SEL,PTB1 (Alias:A1) (reset default)>
//     <0=> LCD_P1/ADC0_SE9/TSI0_CH6<selection=LCD_P1_PIN_SEL,PTB1 (Alias:A1)><selection=ADC0_SE9_PIN_SEL,PTB1 (Alias:A1)><selection=TSI0_CH6_PIN_SEL,PTB1 (Alias:A1)>
//     <1=> GPIOB_1<selection=GPIOB_1_PIN_SEL,PTB1 (Alias:A1)>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTB1 (Alias:A1)>
//     <3=> TPM1_CH1<selection=TPM1_CH1_PIN_SEL,PTB1 (Alias:A1)>
//     <7=> LCD_P1_fault<selection=LCD_P1_fault_PIN_SEL,PTB1 (Alias:A1)>
//     <0=> Default
#define PTB1_SIG_SEL         0

// Signal mapping for PTB2 pin
//   <o> PTB2 (Alias:A2) [LCD_P2/ADC0_SE12/TSI0_CH7, GPIOB_2, I2C0_SCL, TPM2_CH0, LCD_P2_fault]<name=PTB2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB2 pin
//     <-2=> LCD_P2/ADC0_SE12/TSI0_CH7 (reset default)<selection=LCD_P2_PIN_SEL,PTB2 (Alias:A2) (reset default)><selection=ADC0_SE12_PIN_SEL,PTB2 (Alias:A2) (reset default)><selection=TSI0_CH7_PIN_SEL,PTB2 (Alias:A2) (reset default)>
//     <0=> LCD_P2/ADC0_SE12/TSI0_CH7<selection=LCD_P2_PIN_SEL,PTB2 (Alias:A2)><selection=ADC0_SE12_PIN_SEL,PTB2 (Alias:A2)><selection=TSI0_CH7_PIN_SEL,PTB2 (Alias:A2)>
//     <1=> GPIOB_2<selection=GPIOB_2_PIN_SEL,PTB2 (Alias:A2)>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTB2 (Alias:A2)>
//     <3=> TPM2_CH0<selection=TPM2_CH0_PIN_SEL,PTB2 (Alias:A2)>
//     <7=> LCD_P2_fault<selection=LCD_P2_fault_PIN_SEL,PTB2 (Alias:A2)>
//     <0=> Default
#define PTB2_SIG_SEL         0

// Signal mapping for PTB3 pin
//   <o> PTB3 (Alias:A3) [LCD_P3/ADC0_SE13/TSI0_CH8, GPIOB_3, I2C0_SDA, TPM2_CH1, LCD_P3_fault]<name=PTB3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB3 pin
//     <-2=> LCD_P3/ADC0_SE13/TSI0_CH8 (reset default)<selection=LCD_P3_PIN_SEL,PTB3 (Alias:A3) (reset default)><selection=ADC0_SE13_PIN_SEL,PTB3 (Alias:A3) (reset default)><selection=TSI0_CH8_PIN_SEL,PTB3 (Alias:A3) (reset default)>
//     <0=> LCD_P3/ADC0_SE13/TSI0_CH8<selection=LCD_P3_PIN_SEL,PTB3 (Alias:A3)><selection=ADC0_SE13_PIN_SEL,PTB3 (Alias:A3)><selection=TSI0_CH8_PIN_SEL,PTB3 (Alias:A3)>
//     <1=> GPIOB_3<selection=GPIOB_3_PIN_SEL,PTB3 (Alias:A3)>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTB3 (Alias:A3)>
//     <3=> TPM2_CH1<selection=TPM2_CH1_PIN_SEL,PTB3 (Alias:A3)>
//     <7=> LCD_P3_fault<selection=LCD_P3_fault_PIN_SEL,PTB3 (Alias:A3)>
//     <0=> Default
#define PTB3_SIG_SEL         0

// Signal mapping for PTB7 pin
//   <o> PTB7 [LCD_P7, GPIOB_7, LCD_P7_fault]<name=PTB7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB7 pin
//     <-2=> LCD_P7 (reset default)<selection=LCD_P7_PIN_SEL,PTB7 (reset default)>
//     <0=> LCD_P7<selection=LCD_P7_PIN_SEL,PTB7>
//     <1=> GPIOB_7<selection=GPIOB_7_PIN_SEL,PTB7>
//     <7=> LCD_P7_fault<selection=LCD_P7_fault_PIN_SEL,PTB7>
//     <-2=> Default
#define PTB7_SIG_SEL         -2

// Signal mapping for PTB8 pin
//   <o> PTB8 [LCD_P8, GPIOB_8, SPI1_PCS0, EXTRG_IN, LCD_P8_fault]<name=PTB8_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB8 pin
//     <-2=> LCD_P8 (reset default)<selection=LCD_P8_PIN_SEL,PTB8 (reset default)>
//     <0=> LCD_P8<selection=LCD_P8_PIN_SEL,PTB8>
//     <1=> GPIOB_8<selection=GPIOB_8_PIN_SEL,PTB8>
//     <2=> SPI1_PCS0<selection=SPI1_PCS0_PIN_SEL,PTB8>
//     <3=> EXTRG_IN<selection=EXTRG_IN_PIN_SEL,PTB8>
//     <7=> LCD_P8_fault<selection=LCD_P8_fault_PIN_SEL,PTB8>
//     <-2=> Default
#define PTB8_SIG_SEL         -2

// Signal mapping for PTB9 pin
//   <o> PTB9 [LCD_P9, GPIOB_9, SPI1_SCK, LCD_P9_fault]<name=PTB9_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB9 pin
//     <-2=> LCD_P9 (reset default)<selection=LCD_P9_PIN_SEL,PTB9 (reset default)>
//     <0=> LCD_P9<selection=LCD_P9_PIN_SEL,PTB9>
//     <1=> GPIOB_9<selection=GPIOB_9_PIN_SEL,PTB9>
//     <2=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTB9>
//     <7=> LCD_P9_fault<selection=LCD_P9_fault_PIN_SEL,PTB9>
//     <-2=> Default
#define PTB9_SIG_SEL         -2

// Signal mapping for PTB10 pin
//   <o> PTB10 [LCD_P10, GPIOB_10, SPI1_PCS0, LCD_P10_fault]<name=PTB10_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB10 pin
//     <-2=> LCD_P10 (reset default)<selection=LCD_P10_PIN_SEL,PTB10 (reset default)>
//     <0=> LCD_P10<selection=LCD_P10_PIN_SEL,PTB10>
//     <1=> GPIOB_10<selection=GPIOB_10_PIN_SEL,PTB10>
//     <2=> SPI1_PCS0<selection=SPI1_PCS0_PIN_SEL,PTB10>
//     <7=> LCD_P10_fault<selection=LCD_P10_fault_PIN_SEL,PTB10>
//     <-2=> Default
#define PTB10_SIG_SEL        -2

// Signal mapping for PTB11 pin
//   <o> PTB11 [LCD_P11, GPIOB_11, SPI1_SCK, LCD_P11_fault]<name=PTB11_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB11 pin
//     <-2=> LCD_P11 (reset default)<selection=LCD_P11_PIN_SEL,PTB11 (reset default)>
//     <0=> LCD_P11<selection=LCD_P11_PIN_SEL,PTB11>
//     <1=> GPIOB_11<selection=GPIOB_11_PIN_SEL,PTB11>
//     <2=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTB11>
//     <7=> LCD_P11_fault<selection=LCD_P11_fault_PIN_SEL,PTB11>
//     <-2=> Default
#define PTB11_SIG_SEL        -2

// Signal mapping for PTB16 pin
//   <o> PTB16 [LCD_P12/TSI0_CH9, GPIOB_16, SPI1_MOSI, UART0_RX, TPM_CLKIN0, SPI1_MISO, LCD_P12_fault]<name=PTB16_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB16 pin
//     <-2=> LCD_P12/TSI0_CH9 (reset default)<selection=LCD_P12_PIN_SEL,PTB16 (reset default)><selection=TSI0_CH9_PIN_SEL,PTB16 (reset default)>
//     <0=> LCD_P12/TSI0_CH9<selection=LCD_P12_PIN_SEL,PTB16><selection=TSI0_CH9_PIN_SEL,PTB16>
//     <1=> GPIOB_16<selection=GPIOB_16_PIN_SEL,PTB16>
//     <2=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTB16>
//     <3=> UART0_RX<selection=UART0_RX_PIN_SEL,PTB16>
//     <4=> TPM_CLKIN0<selection=TPM_CLKIN0_PIN_SEL,PTB16>
//     <5=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTB16>
//     <7=> LCD_P12_fault<selection=LCD_P12_fault_PIN_SEL,PTB16>
//     <-2=> Default
#define PTB16_SIG_SEL        -2

// Signal mapping for PTB17 pin
//   <o> PTB17 [LCD_P13/TSI0_CH10, GPIOB_17, SPI1_MISO, UART0_TX, TPM_CLKIN1, SPI1_MOSI, LCD_P13_fault]<name=PTB17_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB17 pin
//     <-2=> LCD_P13/TSI0_CH10 (reset default)<selection=LCD_P13_PIN_SEL,PTB17 (reset default)><selection=TSI0_CH10_PIN_SEL,PTB17 (reset default)>
//     <0=> LCD_P13/TSI0_CH10<selection=LCD_P13_PIN_SEL,PTB17><selection=TSI0_CH10_PIN_SEL,PTB17>
//     <1=> GPIOB_17<selection=GPIOB_17_PIN_SEL,PTB17>
//     <2=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTB17>
//     <3=> UART0_TX<selection=UART0_TX_PIN_SEL,PTB17>
//     <4=> TPM_CLKIN1<selection=TPM_CLKIN1_PIN_SEL,PTB17>
//     <5=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTB17>
//     <7=> LCD_P13_fault<selection=LCD_P13_fault_PIN_SEL,PTB17>
//     <-2=> Default
#define PTB17_SIG_SEL        -2

// Signal mapping for PTB18 pin
//   <o> PTB18 [LCD_P14/TSI0_CH11, GPIOB_18, TPM2_CH0, I2S0_TX_BCLK, LCD_P14_fault]<name=PTB18_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB18 pin
//     <-2=> LCD_P14/TSI0_CH11 (reset default)<selection=LCD_P14_PIN_SEL,PTB18 (reset default)><selection=TSI0_CH11_PIN_SEL,PTB18 (reset default)>
//     <0=> LCD_P14/TSI0_CH11<selection=LCD_P14_PIN_SEL,PTB18><selection=TSI0_CH11_PIN_SEL,PTB18>
//     <1=> GPIOB_18<selection=GPIOB_18_PIN_SEL,PTB18>
//     <3=> TPM2_CH0<selection=TPM2_CH0_PIN_SEL,PTB18>
//     <4=> I2S0_TX_BCLK<selection=I2S0_TX_BCLK_PIN_SEL,PTB18>
//     <7=> LCD_P14_fault<selection=LCD_P14_fault_PIN_SEL,PTB18>
//     <-2=> Default
#define PTB18_SIG_SEL        -2

// Signal mapping for PTB19 pin
//   <o> PTB19 [LCD_P15/TSI0_CH12, GPIOB_19, TPM2_CH1, I2S0_TX_FS, LCD_P15_fault]<name=PTB19_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB19 pin
//     <-2=> LCD_P15/TSI0_CH12 (reset default)<selection=LCD_P15_PIN_SEL,PTB19 (reset default)><selection=TSI0_CH12_PIN_SEL,PTB19 (reset default)>
//     <0=> LCD_P15/TSI0_CH12<selection=LCD_P15_PIN_SEL,PTB19><selection=TSI0_CH12_PIN_SEL,PTB19>
//     <1=> GPIOB_19<selection=GPIOB_19_PIN_SEL,PTB19>
//     <3=> TPM2_CH1<selection=TPM2_CH1_PIN_SEL,PTB19>
//     <4=> I2S0_TX_FS<selection=I2S0_TX_FS_PIN_SEL,PTB19>
//     <7=> LCD_P15_fault<selection=LCD_P15_fault_PIN_SEL,PTB19>
//     <-2=> Default
#define PTB19_SIG_SEL        -2

// Signal mapping for PTB20 pin
//   <o> PTB20 [LCD_P16, GPIOB_20, CMP0_OUT, LCD_P16_fault]<name=PTB20_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB20 pin
//     <-2=> LCD_P16 (reset default)<selection=LCD_P16_PIN_SEL,PTB20 (reset default)>
//     <0=> LCD_P16<selection=LCD_P16_PIN_SEL,PTB20>
//     <1=> GPIOB_20<selection=GPIOB_20_PIN_SEL,PTB20>
//     <6=> CMP0_OUT<selection=CMP0_OUT_PIN_SEL,PTB20>
//     <7=> LCD_P16_fault<selection=LCD_P16_fault_PIN_SEL,PTB20>
//     <-2=> Default
#define PTB20_SIG_SEL        -2

// Signal mapping for PTB21 pin
//   <o> PTB21 [LCD_P17, GPIOB_21, LCD_P17_fault]<name=PTB21_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB21 pin
//     <-2=> LCD_P17 (reset default)<selection=LCD_P17_PIN_SEL,PTB21 (reset default)>
//     <0=> LCD_P17<selection=LCD_P17_PIN_SEL,PTB21>
//     <1=> GPIOB_21<selection=GPIOB_21_PIN_SEL,PTB21>
//     <7=> LCD_P17_fault<selection=LCD_P17_fault_PIN_SEL,PTB21>
//     <-2=> Default
#define PTB21_SIG_SEL        -2

// Signal mapping for PTB22 pin
//   <o> PTB22 [LCD_P18, GPIOB_22, LCD_P18_fault]<name=PTB22_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB22 pin
//     <-2=> LCD_P18 (reset default)<selection=LCD_P18_PIN_SEL,PTB22 (reset default)>
//     <0=> LCD_P18<selection=LCD_P18_PIN_SEL,PTB22>
//     <1=> GPIOB_22<selection=GPIOB_22_PIN_SEL,PTB22>
//     <7=> LCD_P18_fault<selection=LCD_P18_fault_PIN_SEL,PTB22>
//     <-2=> Default
#define PTB22_SIG_SEL        -2

// Signal mapping for PTB23 pin
//   <o> PTB23 [LCD_P19, GPIOB_23, LCD_P19_fault]<name=PTB23_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB23 pin
//     <-2=> LCD_P19 (reset default)<selection=LCD_P19_PIN_SEL,PTB23 (reset default)>
//     <0=> LCD_P19<selection=LCD_P19_PIN_SEL,PTB23>
//     <1=> GPIOB_23<selection=GPIOB_23_PIN_SEL,PTB23>
//     <7=> LCD_P19_fault<selection=LCD_P19_fault_PIN_SEL,PTB23>
//     <-2=> Default
#define PTB23_SIG_SEL        -2

// </h>

// <h> Port C Pins

// Signal mapping for PTC0 pin
//   <o> PTC0 [LCD_P20/ADC0_SE14/TSI0_CH13, GPIOC_0, EXTRG_IN, USB_SOF_OUT, CMP0_OUT, I2S0_TXD0, LCD_P20_fault]<name=PTC0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC0 pin
//     <-2=> LCD_P20/ADC0_SE14/TSI0_CH13 (reset default)<selection=LCD_P20_PIN_SEL,PTC0 (reset default)><selection=ADC0_SE14_PIN_SEL,PTC0 (reset default)><selection=TSI0_CH13_PIN_SEL,PTC0 (reset default)>
//     <0=> LCD_P20/ADC0_SE14/TSI0_CH13<selection=LCD_P20_PIN_SEL,PTC0><selection=ADC0_SE14_PIN_SEL,PTC0><selection=TSI0_CH13_PIN_SEL,PTC0>
//     <1=> GPIOC_0<selection=GPIOC_0_PIN_SEL,PTC0>
//     <3=> EXTRG_IN<selection=EXTRG_IN_PIN_SEL,PTC0>
//     <4=> USB_SOF_OUT<selection=USB_SOF_OUT_PIN_SEL,PTC0>
//     <5=> CMP0_OUT<selection=CMP0_OUT_PIN_SEL,PTC0>
//     <6=> I2S0_TXD0<selection=I2S0_TXD0_PIN_SEL,PTC0>
//     <7=> LCD_P20_fault<selection=LCD_P20_fault_PIN_SEL,PTC0>
//     <-2=> Default
#define PTC0_SIG_SEL         -2

// Signal mapping for PTC1 pin
//   <o> PTC1 (Alias:A5) [LCD_P21/ADC0_SE15/TSI0_CH14, GPIOC_1/LLWU_P6/RTC_CLKIN, I2C1_SCL, TPM0_CH0, I2S0_TXD0, LCD_P21_fault]<name=PTC1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC1 pin
//     <-2=> LCD_P21/ADC0_SE15/TSI0_CH14 (reset default)<selection=LCD_P21_PIN_SEL,PTC1 (Alias:A5) (reset default)><selection=ADC0_SE15_PIN_SEL,PTC1 (Alias:A5) (reset default)><selection=TSI0_CH14_PIN_SEL,PTC1 (Alias:A5) (reset default)>
//     <0=> LCD_P21/ADC0_SE15/TSI0_CH14<selection=LCD_P21_PIN_SEL,PTC1 (Alias:A5)><selection=ADC0_SE15_PIN_SEL,PTC1 (Alias:A5)><selection=TSI0_CH14_PIN_SEL,PTC1 (Alias:A5)>
//     <1=> GPIOC_1/LLWU_P6/RTC_CLKIN<selection=GPIOC_1_PIN_SEL,PTC1 (Alias:A5)><selection=LLWU_P6_PIN_SEL,PTC1 (Alias:A5)><selection=RTC_CLKIN_PIN_SEL,PTC1 (Alias:A5)>
//     <2=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTC1 (Alias:A5)>
//     <4=> TPM0_CH0<selection=TPM0_CH0_PIN_SEL,PTC1 (Alias:A5)>
//     <6=> I2S0_TXD0<selection=I2S0_TXD0_PIN_SEL,PTC1 (Alias:A5)>
//     <7=> LCD_P21_fault<selection=LCD_P21_fault_PIN_SEL,PTC1 (Alias:A5)>
//     <0=> Default
#define PTC1_SIG_SEL         0

// Signal mapping for PTC2 pin
//   <o> PTC2 (Alias:A4) [LCD_P22/ADC0_SE11/TSI0_CH15, GPIOC_2, I2C1_SDA, TPM0_CH1, I2S0_TX_FS, LCD_P22_fault]<name=PTC2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC2 pin
//     <-2=> LCD_P22/ADC0_SE11/TSI0_CH15 (reset default)<selection=LCD_P22_PIN_SEL,PTC2 (Alias:A4) (reset default)><selection=ADC0_SE11_PIN_SEL,PTC2 (Alias:A4) (reset default)><selection=TSI0_CH15_PIN_SEL,PTC2 (Alias:A4) (reset default)>
//     <0=> LCD_P22/ADC0_SE11/TSI0_CH15<selection=LCD_P22_PIN_SEL,PTC2 (Alias:A4)><selection=ADC0_SE11_PIN_SEL,PTC2 (Alias:A4)><selection=TSI0_CH15_PIN_SEL,PTC2 (Alias:A4)>
//     <1=> GPIOC_2<selection=GPIOC_2_PIN_SEL,PTC2 (Alias:A4)>
//     <2=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTC2 (Alias:A4)>
//     <4=> TPM0_CH1<selection=TPM0_CH1_PIN_SEL,PTC2 (Alias:A4)>
//     <6=> I2S0_TX_FS<selection=I2S0_TX_FS_PIN_SEL,PTC2 (Alias:A4)>
//     <7=> LCD_P22_fault<selection=LCD_P22_fault_PIN_SEL,PTC2 (Alias:A4)>
//     <0=> Default
#define PTC2_SIG_SEL         0

// Signal mapping for PTC3 pin
//   <o> PTC3 [LCD_P23, GPIOC_3/LLWU_P7, UART1_RX, TPM0_CH2, CLKOUT, I2S0_TX_BCLK, LCD_P23_fault]<name=PTC3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC3 pin
//     <-2=> LCD_P23 (reset default)<selection=LCD_P23_PIN_SEL,PTC3 (reset default)>
//     <0=> LCD_P23<selection=LCD_P23_PIN_SEL,PTC3>
//     <1=> GPIOC_3/LLWU_P7<selection=GPIOC_3_PIN_SEL,PTC3><selection=LLWU_P7_PIN_SEL,PTC3>
//     <3=> UART1_RX<selection=UART1_RX_PIN_SEL,PTC3>
//     <4=> TPM0_CH2<selection=TPM0_CH2_PIN_SEL,PTC3>
//     <5=> CLKOUT<selection=CLKOUT_PIN_SEL,PTC3>
//     <6=> I2S0_TX_BCLK<selection=I2S0_TX_BCLK_PIN_SEL,PTC3>
//     <7=> LCD_P23_fault<selection=LCD_P23_fault_PIN_SEL,PTC3>
//     <-2=> Default
#define PTC3_SIG_SEL         -2

// Signal mapping for PTC4 pin
//   <o> PTC4 [LCD_P24, GPIOC_4/LLWU_P8, SPI0_PCS0, UART1_TX, TPM0_CH3, I2S0_MCLK, LCD_P24_fault]<name=PTC4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC4 pin
//     <-2=> LCD_P24 (reset default)<selection=LCD_P24_PIN_SEL,PTC4 (reset default)>
//     <0=> LCD_P24<selection=LCD_P24_PIN_SEL,PTC4>
//     <1=> GPIOC_4/LLWU_P8<selection=GPIOC_4_PIN_SEL,PTC4><selection=LLWU_P8_PIN_SEL,PTC4>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTC4>
//     <3=> UART1_TX<selection=UART1_TX_PIN_SEL,PTC4>
//     <4=> TPM0_CH3<selection=TPM0_CH3_PIN_SEL,PTC4>
//     <5=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTC4>
//     <7=> LCD_P24_fault<selection=LCD_P24_fault_PIN_SEL,PTC4>
//     <-2=> Default
#define PTC4_SIG_SEL         -2

// Signal mapping for PTC5 pin
//   <o> PTC5 (Alias:ACC_INT1) [LCD_P25, GPIOC_5/LLWU_P9, SPI0_SCK, LPTMR0_ALT2, I2S0_RXD0, CMP0_OUT, LCD_P25_fault]<name=PTC5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC5 pin
//     <-2=> LCD_P25 (reset default)<selection=LCD_P25_PIN_SEL,PTC5 (Alias:ACC_INT1) (reset default)>
//     <0=> LCD_P25<selection=LCD_P25_PIN_SEL,PTC5 (Alias:ACC_INT1)>
//     <1=> GPIOC_5/LLWU_P9<selection=GPIOC_5_PIN_SEL,PTC5 (Alias:ACC_INT1)><selection=LLWU_P9_PIN_SEL,PTC5 (Alias:ACC_INT1)>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTC5 (Alias:ACC_INT1)>
//     <3=> LPTMR0_ALT2<selection=LPTMR0_ALT2_PIN_SEL,PTC5 (Alias:ACC_INT1)>
//     <4=> I2S0_RXD0<selection=I2S0_RXD0_PIN_SEL,PTC5 (Alias:ACC_INT1)>
//     <6=> CMP0_OUT<selection=CMP0_OUT_PIN_SEL,PTC5 (Alias:ACC_INT1)>
//     <7=> LCD_P25_fault<selection=LCD_P25_fault_PIN_SEL,PTC5 (Alias:ACC_INT1)>
//     <1=> Default
#define PTC5_SIG_SEL         1

// Signal mapping for PTC6 pin
//   <o> PTC6 [LCD_P26/CMP0_IN0, GPIOC_6/LLWU_P10, SPI0_MOSI, EXTRG_IN, I2S0_RX_BCLK, SPI0_MISO, I2S0_MCLK, LCD_P26_fault]<name=PTC6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC6 pin
//     <-2=> LCD_P26/CMP0_IN0 (reset default)<selection=LCD_P26_PIN_SEL,PTC6 (reset default)><selection=CMP0_IN0_PIN_SEL,PTC6 (reset default)>
//     <0=> LCD_P26/CMP0_IN0<selection=LCD_P26_PIN_SEL,PTC6><selection=CMP0_IN0_PIN_SEL,PTC6>
//     <1=> GPIOC_6/LLWU_P10<selection=GPIOC_6_PIN_SEL,PTC6><selection=LLWU_P10_PIN_SEL,PTC6>
//     <2=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTC6>
//     <3=> EXTRG_IN<selection=EXTRG_IN_PIN_SEL,PTC6>
//     <4=> I2S0_RX_BCLK<selection=I2S0_RX_BCLK_PIN_SEL,PTC6>
//     <5=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTC6>
//     <6=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTC6>
//     <7=> LCD_P26_fault<selection=LCD_P26_fault_PIN_SEL,PTC6>
//     <-2=> Default
#define PTC6_SIG_SEL         -2

// Signal mapping for PTC7 pin
//   <o> PTC7 [LCD_P27/CMP0_IN1, GPIOC_7, SPI0_MISO, USB_SOF_OUT, I2S0_RX_FS, SPI0_MOSI, LCD_P27_fault]<name=PTC7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC7 pin
//     <-2=> LCD_P27/CMP0_IN1 (reset default)<selection=LCD_P27_PIN_SEL,PTC7 (reset default)><selection=CMP0_IN1_PIN_SEL,PTC7 (reset default)>
//     <0=> LCD_P27/CMP0_IN1<selection=LCD_P27_PIN_SEL,PTC7><selection=CMP0_IN1_PIN_SEL,PTC7>
//     <1=> GPIOC_7<selection=GPIOC_7_PIN_SEL,PTC7>
//     <2=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTC7>
//     <3=> USB_SOF_OUT<selection=USB_SOF_OUT_PIN_SEL,PTC7>
//     <4=> I2S0_RX_FS<selection=I2S0_RX_FS_PIN_SEL,PTC7>
//     <5=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTC7>
//     <7=> LCD_P27_fault<selection=LCD_P27_fault_PIN_SEL,PTC7>
//     <-2=> Default
#define PTC7_SIG_SEL         -2

// Signal mapping for PTC8 pin
//   <o> PTC8 (Alias:D6) [LCD_P28/CMP0_IN2, GPIOC_8, I2C0_SCL, TPM0_CH4, I2S0_MCLK, LCD_P28_fault]<name=PTC8_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC8 pin
//     <-2=> LCD_P28/CMP0_IN2 (reset default)<selection=LCD_P28_PIN_SEL,PTC8 (Alias:D6) (reset default)><selection=CMP0_IN2_PIN_SEL,PTC8 (Alias:D6) (reset default)>
//     <0=> LCD_P28/CMP0_IN2<selection=LCD_P28_PIN_SEL,PTC8 (Alias:D6)><selection=CMP0_IN2_PIN_SEL,PTC8 (Alias:D6)>
//     <1=> GPIOC_8<selection=GPIOC_8_PIN_SEL,PTC8 (Alias:D6)>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTC8 (Alias:D6)>
//     <3=> TPM0_CH4<selection=TPM0_CH4_PIN_SEL,PTC8 (Alias:D6)>
//     <4=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTC8 (Alias:D6)>
//     <7=> LCD_P28_fault<selection=LCD_P28_fault_PIN_SEL,PTC8 (Alias:D6)>
//     <1=> Default
#define PTC8_SIG_SEL         1

// Signal mapping for PTC9 pin
//   <o> PTC9 (Alias:D7) [LCD_P29/CMP0_IN3, GPIOC_9, I2C0_SDA, TPM0_CH5, I2S0_RX_BCLK, LCD_P29_fault]<name=PTC9_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC9 pin
//     <-2=> LCD_P29/CMP0_IN3 (reset default)<selection=LCD_P29_PIN_SEL,PTC9 (Alias:D7) (reset default)><selection=CMP0_IN3_PIN_SEL,PTC9 (Alias:D7) (reset default)>
//     <0=> LCD_P29/CMP0_IN3<selection=LCD_P29_PIN_SEL,PTC9 (Alias:D7)><selection=CMP0_IN3_PIN_SEL,PTC9 (Alias:D7)>
//     <1=> GPIOC_9<selection=GPIOC_9_PIN_SEL,PTC9 (Alias:D7)>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTC9 (Alias:D7)>
//     <3=> TPM0_CH5<selection=TPM0_CH5_PIN_SEL,PTC9 (Alias:D7)>
//     <4=> I2S0_RX_BCLK<selection=I2S0_RX_BCLK_PIN_SEL,PTC9 (Alias:D7)>
//     <7=> LCD_P29_fault<selection=LCD_P29_fault_PIN_SEL,PTC9 (Alias:D7)>
//     <1=> Default
#define PTC9_SIG_SEL         1

// Signal mapping for PTC10 pin
//   <o> PTC10 [LCD_P30, GPIOC_10, I2C1_SCL, I2S0_RX_FS, LCD_P30_fault]<name=PTC10_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC10 pin
//     <-2=> LCD_P30 (reset default)<selection=LCD_P30_PIN_SEL,PTC10 (reset default)>
//     <0=> LCD_P30<selection=LCD_P30_PIN_SEL,PTC10>
//     <1=> GPIOC_10<selection=GPIOC_10_PIN_SEL,PTC10>
//     <2=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTC10>
//     <4=> I2S0_RX_FS<selection=I2S0_RX_FS_PIN_SEL,PTC10>
//     <7=> LCD_P30_fault<selection=LCD_P30_fault_PIN_SEL,PTC10>
//     <-2=> Default
#define PTC10_SIG_SEL        -2

// Signal mapping for PTC11 pin
//   <o> PTC11 [LCD_P31, GPIOC_11, I2C1_SDA, I2S0_RXD0, LCD_P31_fault]<name=PTC11_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC11 pin
//     <-2=> LCD_P31 (reset default)<selection=LCD_P31_PIN_SEL,PTC11 (reset default)>
//     <0=> LCD_P31<selection=LCD_P31_PIN_SEL,PTC11>
//     <1=> GPIOC_11<selection=GPIOC_11_PIN_SEL,PTC11>
//     <2=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTC11>
//     <4=> I2S0_RXD0<selection=I2S0_RXD0_PIN_SEL,PTC11>
//     <7=> LCD_P31_fault<selection=LCD_P31_fault_PIN_SEL,PTC11>
//     <-2=> Default
#define PTC11_SIG_SEL        -2

// Signal mapping for PTC12 pin
//   <o> PTC12 [LCD_P32, GPIOC_12, TPM_CLKIN0, LCD_P32_fault]<name=PTC12_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC12 pin
//     <-2=> LCD_P32 (reset default)<selection=LCD_P32_PIN_SEL,PTC12 (reset default)>
//     <0=> LCD_P32<selection=LCD_P32_PIN_SEL,PTC12>
//     <1=> GPIOC_12<selection=GPIOC_12_PIN_SEL,PTC12>
//     <4=> TPM_CLKIN0<selection=TPM_CLKIN0_PIN_SEL,PTC12>
//     <7=> LCD_P32_fault<selection=LCD_P32_fault_PIN_SEL,PTC12>
//     <-2=> Default
#define PTC12_SIG_SEL        -2

// Signal mapping for PTC13 pin
//   <o> PTC13 [LCD_P33, GPIOC_13, TPM_CLKIN1, LCD_P33_fault]<name=PTC13_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC13 pin
//     <-2=> LCD_P33 (reset default)<selection=LCD_P33_PIN_SEL,PTC13 (reset default)>
//     <0=> LCD_P33<selection=LCD_P33_PIN_SEL,PTC13>
//     <1=> GPIOC_13<selection=GPIOC_13_PIN_SEL,PTC13>
//     <4=> TPM_CLKIN1<selection=TPM_CLKIN1_PIN_SEL,PTC13>
//     <7=> LCD_P33_fault<selection=LCD_P33_fault_PIN_SEL,PTC13>
//     <-2=> Default
#define PTC13_SIG_SEL        -2

// Signal mapping for PTC16 pin
//   <o> PTC16 [LCD_P36, GPIOC_16, LCD_P36_fault]<name=PTC16_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC16 pin
//     <-2=> LCD_P36 (reset default)<selection=LCD_P36_PIN_SEL,PTC16 (reset default)>
//     <0=> LCD_P36<selection=LCD_P36_PIN_SEL,PTC16>
//     <1=> GPIOC_16<selection=GPIOC_16_PIN_SEL,PTC16>
//     <7=> LCD_P36_fault<selection=LCD_P36_fault_PIN_SEL,PTC16>
//     <-2=> Default
#define PTC16_SIG_SEL        -2

// Signal mapping for PTC17 pin
//   <o> PTC17 [LCD_P37, GPIOC_17, LCD_P37_fault]<name=PTC17_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC17 pin
//     <-2=> LCD_P37 (reset default)<selection=LCD_P37_PIN_SEL,PTC17 (reset default)>
//     <0=> LCD_P37<selection=LCD_P37_PIN_SEL,PTC17>
//     <1=> GPIOC_17<selection=GPIOC_17_PIN_SEL,PTC17>
//     <7=> LCD_P37_fault<selection=LCD_P37_fault_PIN_SEL,PTC17>
//     <-2=> Default
#define PTC17_SIG_SEL        -2

// Signal mapping for PTC18 pin
//   <o> PTC18 [LCD_P38, GPIOC_18, LCD_P38_fault]<name=PTC18_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC18 pin
//     <-2=> LCD_P38 (reset default)<selection=LCD_P38_PIN_SEL,PTC18 (reset default)>
//     <0=> LCD_P38<selection=LCD_P38_PIN_SEL,PTC18>
//     <1=> GPIOC_18<selection=GPIOC_18_PIN_SEL,PTC18>
//     <7=> LCD_P38_fault<selection=LCD_P38_fault_PIN_SEL,PTC18>
//     <-2=> Default
#define PTC18_SIG_SEL        -2

// </h>

// <h> Port D Pins

// Signal mapping for PTD0 pin
//   <o> PTD0 [LCD_P40, GPIOD_0, SPI0_PCS0, TPM0_CH0, LCD_P40_fault]<name=PTD0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD0 pin
//     <-2=> LCD_P40 (reset default)<selection=LCD_P40_PIN_SEL,PTD0 (reset default)>
//     <0=> LCD_P40<selection=LCD_P40_PIN_SEL,PTD0>
//     <1=> GPIOD_0<selection=GPIOD_0_PIN_SEL,PTD0>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTD0>
//     <4=> TPM0_CH0<selection=TPM0_CH0_PIN_SEL,PTD0>
//     <7=> LCD_P40_fault<selection=LCD_P40_fault_PIN_SEL,PTD0>
//     <-2=> Default
#define PTD0_SIG_SEL         -2

// Signal mapping for PTD1 pin
//   <o> PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE) [LCD_P41/ADC0_SE5b, GPIOD_1, SPI0_SCK, TPM0_CH1, LCD_P41_fault]<name=PTD1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD1 pin
//     <-2=> LCD_P41/ADC0_SE5b (reset default)<selection=LCD_P41_PIN_SEL,PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE) (reset default)><selection=ADC0_SE5b_PIN_SEL,PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE) (reset default)>
//     <0=> LCD_P41/ADC0_SE5b<selection=LCD_P41_PIN_SEL,PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE)><selection=ADC0_SE5b_PIN_SEL,PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE)>
//     <1=> GPIOD_1<selection=GPIOD_1_PIN_SEL,PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE)>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE)>
//     <4=> TPM0_CH1<selection=TPM0_CH1_PIN_SEL,PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE)>
//     <7=> LCD_P41_fault<selection=LCD_P41_fault_PIN_SEL,PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE)>
//     <4=> Default
#define PTD1_SIG_SEL         4

// Signal mapping for PTD2 pin
//   <o> PTD2 (Alias:D9) [LCD_P42, GPIOD_2, SPI0_MOSI, UART2_RX, TPM0_CH2, SPI0_MISO, LCD_P42_fault]<name=PTD2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD2 pin
//     <-2=> LCD_P42 (reset default)<selection=LCD_P42_PIN_SEL,PTD2 (Alias:D9) (reset default)>
//     <0=> LCD_P42<selection=LCD_P42_PIN_SEL,PTD2 (Alias:D9)>
//     <1=> GPIOD_2<selection=GPIOD_2_PIN_SEL,PTD2 (Alias:D9)>
//     <2=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTD2 (Alias:D9)>
//     <3=> UART2_RX<selection=UART2_RX_PIN_SEL,PTD2 (Alias:D9)>
//     <4=> TPM0_CH2<selection=TPM0_CH2_PIN_SEL,PTD2 (Alias:D9)>
//     <5=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTD2 (Alias:D9)>
//     <7=> LCD_P42_fault<selection=LCD_P42_fault_PIN_SEL,PTD2 (Alias:D9)>
//     <1=> Default
#define PTD2_SIG_SEL         1

// Signal mapping for PTD3 pin
//   <o> PTD3 (Alias:D2) [LCD_P43, GPIOD_3, SPI0_MISO, UART2_TX, TPM0_CH3, SPI0_MOSI, LCD_P43_fault]<name=PTD3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD3 pin
//     <-2=> LCD_P43 (reset default)<selection=LCD_P43_PIN_SEL,PTD3 (Alias:D2) (reset default)>
//     <0=> LCD_P43<selection=LCD_P43_PIN_SEL,PTD3 (Alias:D2)>
//     <1=> GPIOD_3<selection=GPIOD_3_PIN_SEL,PTD3 (Alias:D2)>
//     <2=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTD3 (Alias:D2)>
//     <3=> UART2_TX<selection=UART2_TX_PIN_SEL,PTD3 (Alias:D2)>
//     <4=> TPM0_CH3<selection=TPM0_CH3_PIN_SEL,PTD3 (Alias:D2)>
//     <5=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTD3 (Alias:D2)>
//     <7=> LCD_P43_fault<selection=LCD_P43_fault_PIN_SEL,PTD3 (Alias:D2)>
//     <1=> Default
#define PTD3_SIG_SEL         1

// Signal mapping for PTD4 pin
//   <o> PTD4 (Alias:D10) [LCD_P44, GPIOD_4/LLWU_P14, SPI1_PCS0, UART2_RX, TPM0_CH4, LCD_P44_fault]<name=PTD4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD4 pin
//     <-2=> LCD_P44 (reset default)<selection=LCD_P44_PIN_SEL,PTD4 (Alias:D10) (reset default)>
//     <0=> LCD_P44<selection=LCD_P44_PIN_SEL,PTD4 (Alias:D10)>
//     <1=> GPIOD_4/LLWU_P14<selection=GPIOD_4_PIN_SEL,PTD4 (Alias:D10)><selection=LLWU_P14_PIN_SEL,PTD4 (Alias:D10)>
//     <2=> SPI1_PCS0<selection=SPI1_PCS0_PIN_SEL,PTD4 (Alias:D10)>
//     <3=> UART2_RX<selection=UART2_RX_PIN_SEL,PTD4 (Alias:D10)>
//     <4=> TPM0_CH4<selection=TPM0_CH4_PIN_SEL,PTD4 (Alias:D10)>
//     <7=> LCD_P44_fault<selection=LCD_P44_fault_PIN_SEL,PTD4 (Alias:D10)>
//     <1=> Default
#define PTD4_SIG_SEL         1

// Signal mapping for PTD5 pin
//   <o> PTD5 (Alias:D13, LED_GREEN) [LCD_P45/ADC0_SE6b, GPIOD_5, SPI1_SCK, UART2_TX, TPM0_CH5, LCD_P45_fault]<name=PTD5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD5 pin
//     <-2=> LCD_P45/ADC0_SE6b (reset default)<selection=LCD_P45_PIN_SEL,PTD5 (Alias:D13, LED_GREEN) (reset default)><selection=ADC0_SE6b_PIN_SEL,PTD5 (Alias:D13, LED_GREEN) (reset default)>
//     <0=> LCD_P45/ADC0_SE6b<selection=LCD_P45_PIN_SEL,PTD5 (Alias:D13, LED_GREEN)><selection=ADC0_SE6b_PIN_SEL,PTD5 (Alias:D13, LED_GREEN)>
//     <1=> GPIOD_5<selection=GPIOD_5_PIN_SEL,PTD5 (Alias:D13, LED_GREEN)>
//     <2=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTD5 (Alias:D13, LED_GREEN)>
//     <3=> UART2_TX<selection=UART2_TX_PIN_SEL,PTD5 (Alias:D13, LED_GREEN)>
//     <4=> TPM0_CH5<selection=TPM0_CH5_PIN_SEL,PTD5 (Alias:D13, LED_GREEN)>
//     <7=> LCD_P45_fault<selection=LCD_P45_fault_PIN_SEL,PTD5 (Alias:D13, LED_GREEN)>
//     <4=> Default
#define PTD5_SIG_SEL         4

// Signal mapping for PTD6 pin
//   <o> PTD6 (Alias:D11) [LCD_P46/ADC0_SE7b, GPIOD_6/LLWU_P15, SPI1_MOSI, UART0_RX, SPI1_MISO, LCD_P46_fault]<name=PTD6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD6 pin
//     <-2=> LCD_P46/ADC0_SE7b (reset default)<selection=LCD_P46_PIN_SEL,PTD6 (Alias:D11) (reset default)><selection=ADC0_SE7b_PIN_SEL,PTD6 (Alias:D11) (reset default)>
//     <0=> LCD_P46/ADC0_SE7b<selection=LCD_P46_PIN_SEL,PTD6 (Alias:D11)><selection=ADC0_SE7b_PIN_SEL,PTD6 (Alias:D11)>
//     <1=> GPIOD_6/LLWU_P15<selection=GPIOD_6_PIN_SEL,PTD6 (Alias:D11)><selection=LLWU_P15_PIN_SEL,PTD6 (Alias:D11)>
//     <2=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTD6 (Alias:D11)>
//     <3=> UART0_RX<selection=UART0_RX_PIN_SEL,PTD6 (Alias:D11)>
//     <5=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTD6 (Alias:D11)>
//     <7=> LCD_P46_fault<selection=LCD_P46_fault_PIN_SEL,PTD6 (Alias:D11)>
//     <1=> Default
#define PTD6_SIG_SEL         1

// Signal mapping for PTD7 pin
//   <o> PTD7 (Alias:D12) [LCD_P47, GPIOD_7, SPI1_MISO, UART0_TX, SPI1_MOSI, LCD_P47_fault]<name=PTD7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD7 pin
//     <-2=> LCD_P47 (reset default)<selection=LCD_P47_PIN_SEL,PTD7 (Alias:D12) (reset default)>
//     <0=> LCD_P47<selection=LCD_P47_PIN_SEL,PTD7 (Alias:D12)>
//     <1=> GPIOD_7<selection=GPIOD_7_PIN_SEL,PTD7 (Alias:D12)>
//     <2=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTD7 (Alias:D12)>
//     <3=> UART0_TX<selection=UART0_TX_PIN_SEL,PTD7 (Alias:D12)>
//     <5=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTD7 (Alias:D12)>
//     <7=> LCD_P47_fault<selection=LCD_P47_fault_PIN_SEL,PTD7 (Alias:D12)>
//     <1=> Default
#define PTD7_SIG_SEL         1

// </h>

// <h> Port E Pins

// Signal mapping for PTE0 pin
//   <o> PTE0 (Alias:D14) [LCD_P48, GPIOE_0, SPI1_MISO, UART1_TX, RTC_CLKOUT, CMP0_OUT, I2C1_SDA, LCD_P48_fault]<name=PTE0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE0 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD_P48<selection=LCD_P48_PIN_SEL,PTE0 (Alias:D14)>
//     <1=> GPIOE_0<selection=GPIOE_0_PIN_SEL,PTE0 (Alias:D14)>
//     <2=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTE0 (Alias:D14)>
//     <3=> UART1_TX<selection=UART1_TX_PIN_SEL,PTE0 (Alias:D14)>
//     <4=> RTC_CLKOUT<selection=RTC_CLKOUT_PIN_SEL,PTE0 (Alias:D14)>
//     <5=> CMP0_OUT<selection=CMP0_OUT_PIN_SEL,PTE0 (Alias:D14)>
//     <6=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTE0 (Alias:D14)>
//     <7=> LCD_P48_fault<selection=LCD_P48_fault_PIN_SEL,PTE0 (Alias:D14)>
//     <1=> Default
#define PTE0_SIG_SEL         1

// Signal mapping for PTE1 pin
//   <o> PTE1 (Alias:D15) [LCD_P49, GPIOE_1, SPI1_MOSI, UART1_RX, SPI1_MISO, I2C1_SCL, LCD_P49_fault]<name=PTE1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE1 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD_P49<selection=LCD_P49_PIN_SEL,PTE1 (Alias:D15)>
//     <1=> GPIOE_1<selection=GPIOE_1_PIN_SEL,PTE1 (Alias:D15)>
//     <2=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTE1 (Alias:D15)>
//     <3=> UART1_RX<selection=UART1_RX_PIN_SEL,PTE1 (Alias:D15)>
//     <5=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTE1 (Alias:D15)>
//     <6=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTE1 (Alias:D15)>
//     <7=> LCD_P49_fault<selection=LCD_P49_fault_PIN_SEL,PTE1 (Alias:D15)>
//     <1=> Default
#define PTE1_SIG_SEL         1

// Signal mapping for PTE2 pin
//   <o> PTE2 [LCD_P50, GPIOE_2, SPI1_SCK, LCD_P50_fault]<name=PTE2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE2 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD_P50<selection=LCD_P50_PIN_SEL,PTE2>
//     <1=> GPIOE_2<selection=GPIOE_2_PIN_SEL,PTE2>
//     <2=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTE2>
//     <7=> LCD_P50_fault<selection=LCD_P50_fault_PIN_SEL,PTE2>
//     <-2=> Default
#define PTE2_SIG_SEL         -2

// Signal mapping for PTE3 pin
//   <o> PTE3 [LCD_P51, GPIOE_3, SPI1_MISO, SPI1_MOSI, LCD_P51_fault]<name=PTE3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE3 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD_P51<selection=LCD_P51_PIN_SEL,PTE3>
//     <1=> GPIOE_3<selection=GPIOE_3_PIN_SEL,PTE3>
//     <2=> SPI1_MISO<selection=SPI1_MISO_PIN_SEL,PTE3>
//     <5=> SPI1_MOSI<selection=SPI1_MOSI_PIN_SEL,PTE3>
//     <7=> LCD_P51_fault<selection=LCD_P51_fault_PIN_SEL,PTE3>
//     <-2=> Default
#define PTE3_SIG_SEL         -2

// Signal mapping for PTE4 pin
//   <o> PTE4 [LCD_P52, GPIOE_4, SPI1_PCS0, LCD_P52_fault]<name=PTE4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE4 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD_P52<selection=LCD_P52_PIN_SEL,PTE4>
//     <1=> GPIOE_4<selection=GPIOE_4_PIN_SEL,PTE4>
//     <2=> SPI1_PCS0<selection=SPI1_PCS0_PIN_SEL,PTE4>
//     <7=> LCD_P52_fault<selection=LCD_P52_fault_PIN_SEL,PTE4>
//     <-2=> Default
#define PTE4_SIG_SEL         -2

// Signal mapping for PTE5 pin
//   <o> PTE5 [LCD_P53, GPIOE_5, LCD_P53_fault]<name=PTE5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE5 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD_P53<selection=LCD_P53_PIN_SEL,PTE5>
//     <1=> GPIOE_5<selection=GPIOE_5_PIN_SEL,PTE5>
//     <7=> LCD_P53_fault<selection=LCD_P53_fault_PIN_SEL,PTE5>
//     <-2=> Default
#define PTE5_SIG_SEL         -2

// Signal mapping for PTE6 pin
//   <o> PTE6 [LCD_P54, GPIOE_6, I2S0_MCLK, USB_SOF_OUT, LCD_P54_fault]<name=PTE6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE6 pin
//     <-2=> Disabled (reset default)
//     <0=> LCD_P54<selection=LCD_P54_PIN_SEL,PTE6>
//     <1=> GPIOE_6<selection=GPIOE_6_PIN_SEL,PTE6>
//     <4=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTE6>
//     <5=> USB_SOF_OUT<selection=USB_SOF_OUT_PIN_SEL,PTE6>
//     <7=> LCD_P54_fault<selection=LCD_P54_fault_PIN_SEL,PTE6>
//     <-2=> Default
#define PTE6_SIG_SEL         -2

// Signal mapping for PTE16 pin
//   <o> PTE16 [LCD_P55/ADC0_DP1/ADC0_SE1, GPIOE_16, SPI0_PCS0, UART2_TX, TPM_CLKIN0, LCD_P55_fault]<name=PTE16_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE16 pin
//     <-2=> LCD_P55/ADC0_DP1/ADC0_SE1 (reset default)<selection=LCD_P55_PIN_SEL,PTE16 (reset default)><selection=ADC0_DP1_PIN_SEL,PTE16 (reset default)><selection=ADC0_SE1_PIN_SEL,PTE16 (reset default)>
//     <0=> LCD_P55/ADC0_DP1/ADC0_SE1<selection=LCD_P55_PIN_SEL,PTE16><selection=ADC0_DP1_PIN_SEL,PTE16><selection=ADC0_SE1_PIN_SEL,PTE16>
//     <1=> GPIOE_16<selection=GPIOE_16_PIN_SEL,PTE16>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTE16>
//     <3=> UART2_TX<selection=UART2_TX_PIN_SEL,PTE16>
//     <4=> TPM_CLKIN0<selection=TPM_CLKIN0_PIN_SEL,PTE16>
//     <7=> LCD_P55_fault<selection=LCD_P55_fault_PIN_SEL,PTE16>
//     <-2=> Default
#define PTE16_SIG_SEL        -2

// Signal mapping for PTE17 pin
//   <o> PTE17 [LCD_P56/ADC0_DM1/ADC0_SE5a, GPIOE_17, SPI0_SCK, UART2_RX, TPM_CLKIN1, LPTMR0_ALT3, LCD_P56_fault]<name=PTE17_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE17 pin
//     <-2=> LCD_P56/ADC0_DM1/ADC0_SE5a (reset default)<selection=LCD_P56_PIN_SEL,PTE17 (reset default)><selection=ADC0_DM1_PIN_SEL,PTE17 (reset default)><selection=ADC0_SE5a_PIN_SEL,PTE17 (reset default)>
//     <0=> LCD_P56/ADC0_DM1/ADC0_SE5a<selection=LCD_P56_PIN_SEL,PTE17><selection=ADC0_DM1_PIN_SEL,PTE17><selection=ADC0_SE5a_PIN_SEL,PTE17>
//     <1=> GPIOE_17<selection=GPIOE_17_PIN_SEL,PTE17>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTE17>
//     <3=> UART2_RX<selection=UART2_RX_PIN_SEL,PTE17>
//     <4=> TPM_CLKIN1<selection=TPM_CLKIN1_PIN_SEL,PTE17>
//     <6=> LPTMR0_ALT3<selection=LPTMR0_ALT3_PIN_SEL,PTE17>
//     <7=> LCD_P56_fault<selection=LCD_P56_fault_PIN_SEL,PTE17>
//     <-2=> Default
#define PTE17_SIG_SEL        -2

// Signal mapping for PTE18 pin
//   <o> PTE18 [LCD_P57/ADC0_DP2/ADC0_SE2, GPIOE_18, SPI0_MOSI, I2C0_SDA, SPI0_MISO, LCD_P57_fault]<name=PTE18_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE18 pin
//     <-2=> LCD_P57/ADC0_DP2/ADC0_SE2 (reset default)<selection=LCD_P57_PIN_SEL,PTE18 (reset default)><selection=ADC0_DP2_PIN_SEL,PTE18 (reset default)><selection=ADC0_SE2_PIN_SEL,PTE18 (reset default)>
//     <0=> LCD_P57/ADC0_DP2/ADC0_SE2<selection=LCD_P57_PIN_SEL,PTE18><selection=ADC0_DP2_PIN_SEL,PTE18><selection=ADC0_SE2_PIN_SEL,PTE18>
//     <1=> GPIOE_18<selection=GPIOE_18_PIN_SEL,PTE18>
//     <2=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTE18>
//     <4=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTE18>
//     <5=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTE18>
//     <7=> LCD_P57_fault<selection=LCD_P57_fault_PIN_SEL,PTE18>
//     <-2=> Default
#define PTE18_SIG_SEL        -2

// Signal mapping for PTE19 pin
//   <o> PTE19 [LCD_P58/ADC0_DM2/ADC0_SE6a, GPIOE_19, SPI0_MISO, I2C0_SCL, SPI0_MOSI, LCD_P58_fault]<name=PTE19_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE19 pin
//     <-2=> LCD_P58/ADC0_DM2/ADC0_SE6a (reset default)<selection=LCD_P58_PIN_SEL,PTE19 (reset default)><selection=ADC0_DM2_PIN_SEL,PTE19 (reset default)><selection=ADC0_SE6a_PIN_SEL,PTE19 (reset default)>
//     <0=> LCD_P58/ADC0_DM2/ADC0_SE6a<selection=LCD_P58_PIN_SEL,PTE19><selection=ADC0_DM2_PIN_SEL,PTE19><selection=ADC0_SE6a_PIN_SEL,PTE19>
//     <1=> GPIOE_19<selection=GPIOE_19_PIN_SEL,PTE19>
//     <2=> SPI0_MISO<selection=SPI0_MISO_PIN_SEL,PTE19>
//     <4=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTE19>
//     <5=> SPI0_MOSI<selection=SPI0_MOSI_PIN_SEL,PTE19>
//     <7=> LCD_P58_fault<selection=LCD_P58_fault_PIN_SEL,PTE19>
//     <-2=> Default
#define PTE19_SIG_SEL        -2

// Signal mapping for PTE20 pin
//   <o> PTE20 [LCD_P59/ADC0_DP0/ADC0_SE0, GPIOE_20, TPM1_CH0, UART0_TX, LCD_P59_fault]<name=PTE20_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE20 pin
//     <-2=> LCD_P59/ADC0_DP0/ADC0_SE0 (reset default)<selection=LCD_P59_PIN_SEL,PTE20 (reset default)><selection=ADC0_DP0_PIN_SEL,PTE20 (reset default)><selection=ADC0_SE0_PIN_SEL,PTE20 (reset default)>
//     <0=> LCD_P59/ADC0_DP0/ADC0_SE0<selection=LCD_P59_PIN_SEL,PTE20><selection=ADC0_DP0_PIN_SEL,PTE20><selection=ADC0_SE0_PIN_SEL,PTE20>
//     <1=> GPIOE_20<selection=GPIOE_20_PIN_SEL,PTE20>
//     <3=> TPM1_CH0<selection=TPM1_CH0_PIN_SEL,PTE20>
//     <4=> UART0_TX<selection=UART0_TX_PIN_SEL,PTE20>
//     <7=> LCD_P59_fault<selection=LCD_P59_fault_PIN_SEL,PTE20>
//     <-2=> Default
#define PTE20_SIG_SEL        -2

// Signal mapping for PTE21 pin
//   <o> PTE21 [LCD_P60/ADC0_DM0/ADC0_SE4a, GPIOE_21, TPM1_CH1, UART0_RX, LCD_P60_fault]<name=PTE21_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE21 pin
//     <-2=> LCD_P60/ADC0_DM0/ADC0_SE4a (reset default)<selection=LCD_P60_PIN_SEL,PTE21 (reset default)><selection=ADC0_DM0_PIN_SEL,PTE21 (reset default)><selection=ADC0_SE4a_PIN_SEL,PTE21 (reset default)>
//     <0=> LCD_P60/ADC0_DM0/ADC0_SE4a<selection=LCD_P60_PIN_SEL,PTE21><selection=ADC0_DM0_PIN_SEL,PTE21><selection=ADC0_SE4a_PIN_SEL,PTE21>
//     <1=> GPIOE_21<selection=GPIOE_21_PIN_SEL,PTE21>
//     <3=> TPM1_CH1<selection=TPM1_CH1_PIN_SEL,PTE21>
//     <4=> UART0_RX<selection=UART0_RX_PIN_SEL,PTE21>
//     <7=> LCD_P60_fault<selection=LCD_P60_fault_PIN_SEL,PTE21>
//     <-2=> Default
#define PTE21_SIG_SEL        -2

// Signal mapping for PTE22 pin
//   <o> PTE22 (Alias:LIGHT_SENS) [ADC0_DP3/ADC0_SE3, GPIOE_22, TPM2_CH0, UART2_TX]<name=PTE22_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE22 pin
//     <-2=> ADC0_DP3/ADC0_SE3 (reset default)<selection=ADC0_DP3_PIN_SEL,PTE22 (Alias:LIGHT_SENS) (reset default)><selection=ADC0_SE3_PIN_SEL,PTE22 (Alias:LIGHT_SENS) (reset default)>
//     <0=> ADC0_DP3/ADC0_SE3<selection=ADC0_DP3_PIN_SEL,PTE22 (Alias:LIGHT_SENS)><selection=ADC0_SE3_PIN_SEL,PTE22 (Alias:LIGHT_SENS)>
//     <1=> GPIOE_22<selection=GPIOE_22_PIN_SEL,PTE22 (Alias:LIGHT_SENS)>
//     <3=> TPM2_CH0<selection=TPM2_CH0_PIN_SEL,PTE22 (Alias:LIGHT_SENS)>
//     <4=> UART2_TX<selection=UART2_TX_PIN_SEL,PTE22 (Alias:LIGHT_SENS)>
//     <0=> Default
#define PTE22_SIG_SEL        0

// Signal mapping for PTE23 pin
//   <o> PTE23 [ADC0_DM3/ADC0_SE7a, GPIOE_23, TPM2_CH1, UART2_RX]<name=PTE23_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE23 pin
//     <-2=> ADC0_DM3/ADC0_SE7a (reset default)<selection=ADC0_DM3_PIN_SEL,PTE23 (reset default)><selection=ADC0_SE7a_PIN_SEL,PTE23 (reset default)>
//     <0=> ADC0_DM3/ADC0_SE7a<selection=ADC0_DM3_PIN_SEL,PTE23><selection=ADC0_SE7a_PIN_SEL,PTE23>
//     <1=> GPIOE_23<selection=GPIOE_23_PIN_SEL,PTE23>
//     <3=> TPM2_CH1<selection=TPM2_CH1_PIN_SEL,PTE23>
//     <4=> UART2_RX<selection=UART2_RX_PIN_SEL,PTE23>
//     <-2=> Default
#define PTE23_SIG_SEL        -2

// Signal mapping for PTE24 pin
//   <o> PTE24 (Alias:MAG_SCL, ACC_SCL) [GPIOE_24, TPM0_CH0, I2C0_SCL]<name=PTE24_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE24 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_24<selection=GPIOE_24_PIN_SEL,PTE24 (Alias:MAG_SCL, ACC_SCL)>
//     <3=> TPM0_CH0<selection=TPM0_CH0_PIN_SEL,PTE24 (Alias:MAG_SCL, ACC_SCL)>
//     <5=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTE24 (Alias:MAG_SCL, ACC_SCL)>
//     <5=> Default
#define PTE24_SIG_SEL        5

// Signal mapping for PTE25 pin
//   <o> PTE25 (Alias:MAG_SDA, ACC_SDA) [GPIOE_25, TPM0_CH1, I2C0_SDA]<name=PTE25_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE25 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_25<selection=GPIOE_25_PIN_SEL,PTE25 (Alias:MAG_SDA, ACC_SDA)>
//     <3=> TPM0_CH1<selection=TPM0_CH1_PIN_SEL,PTE25 (Alias:MAG_SDA, ACC_SDA)>
//     <5=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTE25 (Alias:MAG_SDA, ACC_SDA)>
//     <5=> Default
#define PTE25_SIG_SEL        5

// Signal mapping for PTE26 pin
//   <o> PTE26 [GPIOE_26, TPM0_CH5, RTC_CLKOUT, USB_CLKIN]<name=PTE26_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE26 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_26<selection=GPIOE_26_PIN_SEL,PTE26>
//     <3=> TPM0_CH5<selection=TPM0_CH5_PIN_SEL,PTE26>
//     <6=> RTC_CLKOUT<selection=RTC_CLKOUT_PIN_SEL,PTE26>
//     <7=> USB_CLKIN<selection=USB_CLKIN_PIN_SEL,PTE26>
//     <-2=> Default
#define PTE26_SIG_SEL        -2

// Signal mapping for PTE29 pin
//   <o> PTE29 (Alias:LED_RED) [CMP0_IN5/ADC0_SE4b, GPIOE_29, TPM0_CH2, TPM_CLKIN0]<name=PTE29_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE29 pin
//     <-2=> CMP0_IN5/ADC0_SE4b (reset default)<selection=CMP0_IN5_PIN_SEL,PTE29 (Alias:LED_RED) (reset default)><selection=ADC0_SE4b_PIN_SEL,PTE29 (Alias:LED_RED) (reset default)>
//     <0=> CMP0_IN5/ADC0_SE4b<selection=CMP0_IN5_PIN_SEL,PTE29 (Alias:LED_RED)><selection=ADC0_SE4b_PIN_SEL,PTE29 (Alias:LED_RED)>
//     <1=> GPIOE_29<selection=GPIOE_29_PIN_SEL,PTE29 (Alias:LED_RED)>
//     <3=> TPM0_CH2<selection=TPM0_CH2_PIN_SEL,PTE29 (Alias:LED_RED)>
//     <4=> TPM_CLKIN0<selection=TPM_CLKIN0_PIN_SEL,PTE29 (Alias:LED_RED)>
//     <3=> Default
#define PTE29_SIG_SEL        3

// Signal mapping for PTE30 pin
//   <o> PTE30 [DAC0_OUT/ADC0_SE23/CMP0_IN4, GPIOE_30, TPM0_CH3, TPM_CLKIN1]<name=PTE30_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE30 pin
//     <-2=> DAC0_OUT/ADC0_SE23/CMP0_IN4 (reset default)<selection=DAC0_OUT_PIN_SEL,PTE30 (reset default)><selection=ADC0_SE23_PIN_SEL,PTE30 (reset default)><selection=CMP0_IN4_PIN_SEL,PTE30 (reset default)>
//     <0=> DAC0_OUT/ADC0_SE23/CMP0_IN4<selection=DAC0_OUT_PIN_SEL,PTE30><selection=ADC0_SE23_PIN_SEL,PTE30><selection=CMP0_IN4_PIN_SEL,PTE30>
//     <1=> GPIOE_30<selection=GPIOE_30_PIN_SEL,PTE30>
//     <3=> TPM0_CH3<selection=TPM0_CH3_PIN_SEL,PTE30>
//     <4=> TPM_CLKIN1<selection=TPM_CLKIN1_PIN_SEL,PTE30>
//     <-2=> Default
#define PTE30_SIG_SEL        -2

// Signal mapping for PTE31 pin
//   <o> PTE31 [GPIOE_31, TPM0_CH4]<name=PTE31_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE31 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_31<selection=GPIOE_31_PIN_SEL,PTE31>
//     <3=> TPM0_CH4<selection=TPM0_CH4_PIN_SEL,PTE31>
//     <-2=> Default
#define PTE31_SIG_SEL        -2

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
//     <1=> PTE21 (reset default)<selection=PTE21_SIG_SEL,LCD_P60/ADC0_DM0/ADC0_SE4a (reset default)>
//     <2=> PTE21<selection=PTE21_SIG_SEL,LCD_P60/ADC0_DM0/ADC0_SE4a>
//     <1=> Default
#define ADC0_DM0_PIN_SEL     1
#if ADC0_DM0_PIN_SEL == 2
#define ADC0_DM0_GPIO        digitalIO_PTE21
#define ADC0_DM0_FN          0
#endif

// Pin Mapping for ADC0_DM1 signal
//   <o> ADC0_DM1 [PTE17]<name=ADC0_DM1_PIN_SEL>
//   <i> Shows which pin ADC0_DM1 is mapped to
//     <0=> Disabled
//     <1=> PTE17 (reset default)<selection=PTE17_SIG_SEL,LCD_P56/ADC0_DM1/ADC0_SE5a (reset default)>
//     <2=> PTE17<selection=PTE17_SIG_SEL,LCD_P56/ADC0_DM1/ADC0_SE5a>
//     <1=> Default
#define ADC0_DM1_PIN_SEL     1
#if ADC0_DM1_PIN_SEL == 2
#define ADC0_DM1_GPIO        digitalIO_PTE17
#define ADC0_DM1_FN          0
#endif

// Pin Mapping for ADC0_DM2 signal
//   <o> ADC0_DM2 [PTE19]<name=ADC0_DM2_PIN_SEL>
//   <i> Shows which pin ADC0_DM2 is mapped to
//     <0=> Disabled
//     <1=> PTE19 (reset default)<selection=PTE19_SIG_SEL,LCD_P58/ADC0_DM2/ADC0_SE6a (reset default)>
//     <2=> PTE19<selection=PTE19_SIG_SEL,LCD_P58/ADC0_DM2/ADC0_SE6a>
//     <1=> Default
#define ADC0_DM2_PIN_SEL     1
#if ADC0_DM2_PIN_SEL == 2
#define ADC0_DM2_GPIO        digitalIO_PTE19
#define ADC0_DM2_FN          0
#endif

// Pin Mapping for ADC0_DM3 signal
//   <o> ADC0_DM3 [PTE23]<name=ADC0_DM3_PIN_SEL>
//   <i> Shows which pin ADC0_DM3 is mapped to
//     <0=> Disabled
//     <1=> PTE23 (reset default)<selection=PTE23_SIG_SEL,ADC0_DM3/ADC0_SE7a (reset default)>
//     <2=> PTE23<selection=PTE23_SIG_SEL,ADC0_DM3/ADC0_SE7a>
//     <1=> Default
#define ADC0_DM3_PIN_SEL     1
#if ADC0_DM3_PIN_SEL == 2
#define ADC0_DM3_GPIO        digitalIO_PTE23
#define ADC0_DM3_FN          0
#endif

// Pin Mapping for ADC0_DP0 signal
//   <o> ADC0_DP0 [PTE20]<name=ADC0_DP0_PIN_SEL>
//   <i> Shows which pin ADC0_DP0 is mapped to
//     <0=> Disabled
//     <1=> PTE20 (reset default)<selection=PTE20_SIG_SEL,LCD_P59/ADC0_DP0/ADC0_SE0 (reset default)>
//     <2=> PTE20<selection=PTE20_SIG_SEL,LCD_P59/ADC0_DP0/ADC0_SE0>
//     <1=> Default
#define ADC0_DP0_PIN_SEL     1
#if ADC0_DP0_PIN_SEL == 2
#define ADC0_DP0_GPIO        digitalIO_PTE20
#define ADC0_DP0_FN          0
#endif

// Pin Mapping for ADC0_DP1 signal
//   <o> ADC0_DP1 [PTE16]<name=ADC0_DP1_PIN_SEL>
//   <i> Shows which pin ADC0_DP1 is mapped to
//     <0=> Disabled
//     <1=> PTE16 (reset default)<selection=PTE16_SIG_SEL,LCD_P55/ADC0_DP1/ADC0_SE1 (reset default)>
//     <2=> PTE16<selection=PTE16_SIG_SEL,LCD_P55/ADC0_DP1/ADC0_SE1>
//     <1=> Default
#define ADC0_DP1_PIN_SEL     1
#if ADC0_DP1_PIN_SEL == 2
#define ADC0_DP1_GPIO        digitalIO_PTE16
#define ADC0_DP1_FN          0
#endif

// Pin Mapping for ADC0_DP2 signal
//   <o> ADC0_DP2 [PTE18]<name=ADC0_DP2_PIN_SEL>
//   <i> Shows which pin ADC0_DP2 is mapped to
//     <0=> Disabled
//     <1=> PTE18 (reset default)<selection=PTE18_SIG_SEL,LCD_P57/ADC0_DP2/ADC0_SE2 (reset default)>
//     <2=> PTE18<selection=PTE18_SIG_SEL,LCD_P57/ADC0_DP2/ADC0_SE2>
//     <1=> Default
#define ADC0_DP2_PIN_SEL     1
#if ADC0_DP2_PIN_SEL == 2
#define ADC0_DP2_GPIO        digitalIO_PTE18
#define ADC0_DP2_FN          0
#endif

// Pin Mapping for ADC0_DP3 signal
//   <o> ADC0_DP3 [PTE22]<name=ADC0_DP3_PIN_SEL>
//   <i> Shows which pin ADC0_DP3 is mapped to
//     <0=> Disabled
//     <1=> PTE22 (Alias:LIGHT_SENS) (reset default)<selection=PTE22_SIG_SEL,ADC0_DP3/ADC0_SE3 (reset default)>
//     <2=> PTE22 (Alias:LIGHT_SENS)<selection=PTE22_SIG_SEL,ADC0_DP3/ADC0_SE3>
//     <2=> Default
#define ADC0_DP3_PIN_SEL     2
#if ADC0_DP3_PIN_SEL == 2
#define ADC0_DP3_GPIO        digitalIO_PTE22
#define ADC0_DP3_FN          0
#endif

// Pin Mapping for ADC0_SE0 signal
//   <o> ADC0_SE0 [PTE20]<name=ADC0_SE0_PIN_SEL>
//   <i> Shows which pin ADC0_SE0 is mapped to
//     <0=> Disabled
//     <1=> PTE20 (reset default)<selection=PTE20_SIG_SEL,LCD_P59/ADC0_DP0/ADC0_SE0 (reset default)>
//     <2=> PTE20<selection=PTE20_SIG_SEL,LCD_P59/ADC0_DP0/ADC0_SE0>
//     <1=> Default
#define ADC0_SE0_PIN_SEL     1
#if ADC0_SE0_PIN_SEL == 2
#define ADC0_SE0_GPIO        digitalIO_PTE20
#define ADC0_SE0_FN          0
#endif

// Pin Mapping for ADC0_SE1 signal
//   <o> ADC0_SE1 [PTE16]<name=ADC0_SE1_PIN_SEL>
//   <i> Shows which pin ADC0_SE1 is mapped to
//     <0=> Disabled
//     <1=> PTE16 (reset default)<selection=PTE16_SIG_SEL,LCD_P55/ADC0_DP1/ADC0_SE1 (reset default)>
//     <2=> PTE16<selection=PTE16_SIG_SEL,LCD_P55/ADC0_DP1/ADC0_SE1>
//     <1=> Default
#define ADC0_SE1_PIN_SEL     1
#if ADC0_SE1_PIN_SEL == 2
#define ADC0_SE1_GPIO        digitalIO_PTE16
#define ADC0_SE1_FN          0
#endif

// Pin Mapping for ADC0_SE2 signal
//   <o> ADC0_SE2 [PTE18]<name=ADC0_SE2_PIN_SEL>
//   <i> Shows which pin ADC0_SE2 is mapped to
//     <0=> Disabled
//     <1=> PTE18 (reset default)<selection=PTE18_SIG_SEL,LCD_P57/ADC0_DP2/ADC0_SE2 (reset default)>
//     <2=> PTE18<selection=PTE18_SIG_SEL,LCD_P57/ADC0_DP2/ADC0_SE2>
//     <1=> Default
#define ADC0_SE2_PIN_SEL     1
#if ADC0_SE2_PIN_SEL == 2
#define ADC0_SE2_GPIO        digitalIO_PTE18
#define ADC0_SE2_FN          0
#endif

// Pin Mapping for ADC0_SE3 signal
//   <o> ADC0_SE3 [PTE22]<name=ADC0_SE3_PIN_SEL>
//   <i> Shows which pin ADC0_SE3 is mapped to
//     <0=> Disabled
//     <1=> PTE22 (Alias:LIGHT_SENS) (reset default)<selection=PTE22_SIG_SEL,ADC0_DP3/ADC0_SE3 (reset default)>
//     <2=> PTE22 (Alias:LIGHT_SENS)<selection=PTE22_SIG_SEL,ADC0_DP3/ADC0_SE3>
//     <2=> Default
#define ADC0_SE3_PIN_SEL     2
#if ADC0_SE3_PIN_SEL == 2
#define ADC0_SE3_GPIO        digitalIO_PTE22
#define ADC0_SE3_FN          0
#endif

// Pin Mapping for ADC0_SE4b signal
//   <o> ADC0_SE4b [PTE29]<name=ADC0_SE4b_PIN_SEL>
//   <i> Shows which pin ADC0_SE4b is mapped to
//     <0=> Disabled
//     <1=> PTE29 (Alias:LED_RED) (reset default)<selection=PTE29_SIG_SEL,CMP0_IN5/ADC0_SE4b (reset default)>
//     <2=> PTE29 (Alias:LED_RED)<selection=PTE29_SIG_SEL,CMP0_IN5/ADC0_SE4b>
//     <0=> Default
#define ADC0_SE4b_PIN_SEL    0
#if ADC0_SE4b_PIN_SEL == 2
#define ADC0_SE4b_GPIO       digitalIO_PTE29
#define ADC0_SE4b_FN         0
#endif

// Pin Mapping for ADC0_SE4a signal
//   <o> ADC0_SE4a [PTE21]<name=ADC0_SE4a_PIN_SEL>
//   <i> Shows which pin ADC0_SE4a is mapped to
//     <0=> Disabled
//     <1=> PTE21 (reset default)<selection=PTE21_SIG_SEL,LCD_P60/ADC0_DM0/ADC0_SE4a (reset default)>
//     <2=> PTE21<selection=PTE21_SIG_SEL,LCD_P60/ADC0_DM0/ADC0_SE4a>
//     <1=> Default
#define ADC0_SE4a_PIN_SEL    1
#if ADC0_SE4a_PIN_SEL == 2
#define ADC0_SE4a_GPIO       digitalIO_PTE21
#define ADC0_SE4a_FN         0
#endif

// Pin Mapping for ADC0_SE5b signal
//   <o> ADC0_SE5b [PTD1]<name=ADC0_SE5b_PIN_SEL>
//   <i> Shows which pin ADC0_SE5b is mapped to
//     <0=> Disabled
//     <1=> PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE) (reset default)<selection=PTD1_SIG_SEL,LCD_P41/ADC0_SE5b (reset default)>
//     <2=> PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE)<selection=PTD1_SIG_SEL,LCD_P41/ADC0_SE5b>
//     <0=> Default
#define ADC0_SE5b_PIN_SEL    0
#if ADC0_SE5b_PIN_SEL == 2
#define ADC0_SE5b_GPIO       digitalIO_PTD1
#define ADC0_SE5b_FN         0
#endif

// Pin Mapping for ADC0_SE5a signal
//   <o> ADC0_SE5a [PTE17]<name=ADC0_SE5a_PIN_SEL>
//   <i> Shows which pin ADC0_SE5a is mapped to
//     <0=> Disabled
//     <1=> PTE17 (reset default)<selection=PTE17_SIG_SEL,LCD_P56/ADC0_DM1/ADC0_SE5a (reset default)>
//     <2=> PTE17<selection=PTE17_SIG_SEL,LCD_P56/ADC0_DM1/ADC0_SE5a>
//     <1=> Default
#define ADC0_SE5a_PIN_SEL    1
#if ADC0_SE5a_PIN_SEL == 2
#define ADC0_SE5a_GPIO       digitalIO_PTE17
#define ADC0_SE5a_FN         0
#endif

// Pin Mapping for ADC0_SE6b signal
//   <o> ADC0_SE6b [PTD5]<name=ADC0_SE6b_PIN_SEL>
//   <i> Shows which pin ADC0_SE6b is mapped to
//     <0=> Disabled
//     <1=> PTD5 (Alias:D13, LED_GREEN) (reset default)<selection=PTD5_SIG_SEL,LCD_P45/ADC0_SE6b (reset default)>
//     <2=> PTD5 (Alias:D13, LED_GREEN)<selection=PTD5_SIG_SEL,LCD_P45/ADC0_SE6b>
//     <0=> Default
#define ADC0_SE6b_PIN_SEL    0
#if ADC0_SE6b_PIN_SEL == 2
#define ADC0_SE6b_GPIO       digitalIO_PTD5
#define ADC0_SE6b_FN         0
#endif

// Pin Mapping for ADC0_SE6a signal
//   <o> ADC0_SE6a [PTE19]<name=ADC0_SE6a_PIN_SEL>
//   <i> Shows which pin ADC0_SE6a is mapped to
//     <0=> Disabled
//     <1=> PTE19 (reset default)<selection=PTE19_SIG_SEL,LCD_P58/ADC0_DM2/ADC0_SE6a (reset default)>
//     <2=> PTE19<selection=PTE19_SIG_SEL,LCD_P58/ADC0_DM2/ADC0_SE6a>
//     <1=> Default
#define ADC0_SE6a_PIN_SEL    1
#if ADC0_SE6a_PIN_SEL == 2
#define ADC0_SE6a_GPIO       digitalIO_PTE19
#define ADC0_SE6a_FN         0
#endif

// Pin Mapping for ADC0_SE7a signal
//   <o> ADC0_SE7a [PTE23]<name=ADC0_SE7a_PIN_SEL>
//   <i> Shows which pin ADC0_SE7a is mapped to
//     <0=> Disabled
//     <1=> PTE23 (reset default)<selection=PTE23_SIG_SEL,ADC0_DM3/ADC0_SE7a (reset default)>
//     <2=> PTE23<selection=PTE23_SIG_SEL,ADC0_DM3/ADC0_SE7a>
//     <1=> Default
#define ADC0_SE7a_PIN_SEL    1
#if ADC0_SE7a_PIN_SEL == 2
#define ADC0_SE7a_GPIO       digitalIO_PTE23
#define ADC0_SE7a_FN         0
#endif

// Pin Mapping for ADC0_SE7b signal
//   <o> ADC0_SE7b [PTD6]<name=ADC0_SE7b_PIN_SEL>
//   <i> Shows which pin ADC0_SE7b is mapped to
//     <0=> Disabled
//     <1=> PTD6 (Alias:D11) (reset default)<selection=PTD6_SIG_SEL,LCD_P46/ADC0_SE7b (reset default)>
//     <2=> PTD6 (Alias:D11)<selection=PTD6_SIG_SEL,LCD_P46/ADC0_SE7b>
//     <0=> Default
#define ADC0_SE7b_PIN_SEL    0
#if ADC0_SE7b_PIN_SEL == 2
#define ADC0_SE7b_GPIO       digitalIO_PTD6
#define ADC0_SE7b_FN         0
#endif

// Pin Mapping for ADC0_SE8 signal
//   <o> ADC0_SE8 [PTB0]<name=ADC0_SE8_PIN_SEL>
//   <i> Shows which pin ADC0_SE8 is mapped to
//     <0=> Disabled
//     <1=> PTB0 (Alias:A0) (reset default)<selection=PTB0_SIG_SEL,LCD_P0/ADC0_SE8/TSI0_CH0 (reset default)>
//     <2=> PTB0 (Alias:A0)<selection=PTB0_SIG_SEL,LCD_P0/ADC0_SE8/TSI0_CH0>
//     <2=> Default
#define ADC0_SE8_PIN_SEL     2
#if ADC0_SE8_PIN_SEL == 2
#define ADC0_SE8_GPIO        digitalIO_PTB0
#define ADC0_SE8_FN          0
#endif

// Pin Mapping for ADC0_SE9 signal
//   <o> ADC0_SE9 [PTB1]<name=ADC0_SE9_PIN_SEL>
//   <i> Shows which pin ADC0_SE9 is mapped to
//     <0=> Disabled
//     <1=> PTB1 (Alias:A1) (reset default)<selection=PTB1_SIG_SEL,LCD_P1/ADC0_SE9/TSI0_CH6 (reset default)>
//     <2=> PTB1 (Alias:A1)<selection=PTB1_SIG_SEL,LCD_P1/ADC0_SE9/TSI0_CH6>
//     <2=> Default
#define ADC0_SE9_PIN_SEL     2
#if ADC0_SE9_PIN_SEL == 2
#define ADC0_SE9_GPIO        digitalIO_PTB1
#define ADC0_SE9_FN          0
#endif

// Pin Mapping for ADC0_SE11 signal
//   <o> ADC0_SE11 [PTC2]<name=ADC0_SE11_PIN_SEL>
//   <i> Shows which pin ADC0_SE11 is mapped to
//     <0=> Disabled
//     <1=> PTC2 (Alias:A4) (reset default)<selection=PTC2_SIG_SEL,LCD_P22/ADC0_SE11/TSI0_CH15 (reset default)>
//     <2=> PTC2 (Alias:A4)<selection=PTC2_SIG_SEL,LCD_P22/ADC0_SE11/TSI0_CH15>
//     <2=> Default
#define ADC0_SE11_PIN_SEL    2
#if ADC0_SE11_PIN_SEL == 2
#define ADC0_SE11_GPIO       digitalIO_PTC2
#define ADC0_SE11_FN         0
#endif

// Pin Mapping for ADC0_SE12 signal
//   <o> ADC0_SE12 [PTB2]<name=ADC0_SE12_PIN_SEL>
//   <i> Shows which pin ADC0_SE12 is mapped to
//     <0=> Disabled
//     <1=> PTB2 (Alias:A2) (reset default)<selection=PTB2_SIG_SEL,LCD_P2/ADC0_SE12/TSI0_CH7 (reset default)>
//     <2=> PTB2 (Alias:A2)<selection=PTB2_SIG_SEL,LCD_P2/ADC0_SE12/TSI0_CH7>
//     <2=> Default
#define ADC0_SE12_PIN_SEL    2
#if ADC0_SE12_PIN_SEL == 2
#define ADC0_SE12_GPIO       digitalIO_PTB2
#define ADC0_SE12_FN         0
#endif

// Pin Mapping for ADC0_SE13 signal
//   <o> ADC0_SE13 [PTB3]<name=ADC0_SE13_PIN_SEL>
//   <i> Shows which pin ADC0_SE13 is mapped to
//     <0=> Disabled
//     <1=> PTB3 (Alias:A3) (reset default)<selection=PTB3_SIG_SEL,LCD_P3/ADC0_SE13/TSI0_CH8 (reset default)>
//     <2=> PTB3 (Alias:A3)<selection=PTB3_SIG_SEL,LCD_P3/ADC0_SE13/TSI0_CH8>
//     <2=> Default
#define ADC0_SE13_PIN_SEL    2
#if ADC0_SE13_PIN_SEL == 2
#define ADC0_SE13_GPIO       digitalIO_PTB3
#define ADC0_SE13_FN         0
#endif

// Pin Mapping for ADC0_SE14 signal
//   <o> ADC0_SE14 [PTC0]<name=ADC0_SE14_PIN_SEL>
//   <i> Shows which pin ADC0_SE14 is mapped to
//     <0=> Disabled
//     <1=> PTC0 (reset default)<selection=PTC0_SIG_SEL,LCD_P20/ADC0_SE14/TSI0_CH13 (reset default)>
//     <2=> PTC0<selection=PTC0_SIG_SEL,LCD_P20/ADC0_SE14/TSI0_CH13>
//     <1=> Default
#define ADC0_SE14_PIN_SEL    1
#if ADC0_SE14_PIN_SEL == 2
#define ADC0_SE14_GPIO       digitalIO_PTC0
#define ADC0_SE14_FN         0
#endif

// Pin Mapping for ADC0_SE15 signal
//   <o> ADC0_SE15 [PTC1]<name=ADC0_SE15_PIN_SEL>
//   <i> Shows which pin ADC0_SE15 is mapped to
//     <0=> Disabled
//     <1=> PTC1 (Alias:A5) (reset default)<selection=PTC1_SIG_SEL,LCD_P21/ADC0_SE15/TSI0_CH14 (reset default)>
//     <2=> PTC1 (Alias:A5)<selection=PTC1_SIG_SEL,LCD_P21/ADC0_SE15/TSI0_CH14>
//     <2=> Default
#define ADC0_SE15_PIN_SEL    2
#if ADC0_SE15_PIN_SEL == 2
#define ADC0_SE15_GPIO       digitalIO_PTC1
#define ADC0_SE15_FN         0
#endif

// Pin Mapping for ADC0_SE23 signal
//   <o> ADC0_SE23 [PTE30]<name=ADC0_SE23_PIN_SEL>
//   <i> Shows which pin ADC0_SE23 is mapped to
//     <0=> Disabled
//     <1=> PTE30 (reset default)<selection=PTE30_SIG_SEL,DAC0_OUT/ADC0_SE23/CMP0_IN4 (reset default)>
//     <2=> PTE30<selection=PTE30_SIG_SEL,DAC0_OUT/ADC0_SE23/CMP0_IN4>
//     <1=> Default
#define ADC0_SE23_PIN_SEL    1
#if ADC0_SE23_PIN_SEL == 2
#define ADC0_SE23_GPIO       digitalIO_PTE30
#define ADC0_SE23_FN         0
#endif

// </h>

// <h> Clock and Timing

// Pin Mapping for CLKOUT signal
//   <o> CLKOUT [PTC3]<name=CLKOUT_PIN_SEL>
//   <i> Shows which pin CLKOUT is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,CLKOUT>
//     <0=> Default
#define CLKOUT_PIN_SEL       0
#if CLKOUT_PIN_SEL == 1
#define CLKOUT_GPIO          digitalIO_PTC3
#define CLKOUT_FN            5
#endif

// Pin Mapping for EXTAL0 signal
//   <o> EXTAL0 [PTA18]<name=EXTAL0_PIN_SEL>
//   <i> Shows which pin EXTAL0 is mapped to
//     <0=> Disabled
//     <1=> PTA18 (reset default)<selection=PTA18_SIG_SEL,EXTAL0 (reset default)>
//     <2=> PTA18<selection=PTA18_SIG_SEL,EXTAL0>
//     <1=> Default
#define EXTAL0_PIN_SEL       1
#if EXTAL0_PIN_SEL == 2
#define EXTAL0_GPIO          digitalIO_PTA18
#define EXTAL0_FN            0
#endif

// Pin Mapping for EXTRG_IN signal
//   <o> EXTRG_IN [PTB8, PTC0, PTC6]<name=EXTRG_IN_PIN_SEL>
//   <i> Shows which pin EXTRG_IN is mapped to
//     <0=> Disabled
//     <1=> PTB8<selection=PTB8_SIG_SEL,EXTRG_IN>
//     <2=> PTC0<selection=PTC0_SIG_SEL,EXTRG_IN>
//     <3=> PTC6<selection=PTC6_SIG_SEL,EXTRG_IN>
//     <0=> Default
#define EXTRG_IN_PIN_SEL     0
#if EXTRG_IN_PIN_SEL == 1
#define EXTRG_IN_GPIO        digitalIO_PTB8
#define EXTRG_IN_FN          3
#elif EXTRG_IN_PIN_SEL == 2
#define EXTRG_IN_GPIO        digitalIO_PTC0
#define EXTRG_IN_FN          3
#elif EXTRG_IN_PIN_SEL == 3
#define EXTRG_IN_GPIO        digitalIO_PTC6
#define EXTRG_IN_FN          3
#endif

// Pin Mapping for RTC_CLKIN signal
//   <o> RTC_CLKIN [PTC1]<name=RTC_CLKIN_PIN_SEL>
//   <i> Shows which pin RTC_CLKIN is mapped to
//     <0=> Disabled
//     <1=> PTC1 (Alias:A5)<selection=PTC1_SIG_SEL,GPIOC_1/LLWU_P6/RTC_CLKIN>
//     <0=> Default
#define RTC_CLKIN_PIN_SEL    0
#if RTC_CLKIN_PIN_SEL == 1
#define RTC_CLKIN_GPIO       digitalIO_PTC1
#define RTC_CLKIN_FN         1
#endif

// Pin Mapping for RTC_CLKOUT signal
//   <o> RTC_CLKOUT [PTE0, PTE26]<name=RTC_CLKOUT_PIN_SEL>
//   <i> Shows which pin RTC_CLKOUT is mapped to
//     <0=> Disabled
//     <1=> PTE0 (Alias:D14)<selection=PTE0_SIG_SEL,RTC_CLKOUT>
//     <2=> PTE26<selection=PTE26_SIG_SEL,RTC_CLKOUT>
//     <0=> Default
#define RTC_CLKOUT_PIN_SEL   0
#if RTC_CLKOUT_PIN_SEL == 1
#define RTC_CLKOUT_GPIO      digitalIO_PTE0
#define RTC_CLKOUT_FN        4
#elif RTC_CLKOUT_PIN_SEL == 2
#define RTC_CLKOUT_GPIO      digitalIO_PTE26
#define RTC_CLKOUT_FN        6
#endif

// Pin Mapping for TPM_CLKIN0 signal
//   <o> TPM_CLKIN0 [PTA18, PTB16, PTC12, PTE16, PTE29]<name=TPM_CLKIN0_PIN_SEL>
//   <i> Shows which pin TPM_CLKIN0 is mapped to
//     <0=> Disabled
//     <1=> PTA18<selection=PTA18_SIG_SEL,TPM_CLKIN0>
//     <2=> PTB16<selection=PTB16_SIG_SEL,TPM_CLKIN0>
//     <3=> PTC12<selection=PTC12_SIG_SEL,TPM_CLKIN0>
//     <4=> PTE16<selection=PTE16_SIG_SEL,TPM_CLKIN0>
//     <5=> PTE29 (Alias:LED_RED)<selection=PTE29_SIG_SEL,TPM_CLKIN0>
//     <0=> Default
#define TPM_CLKIN0_PIN_SEL   0
#if TPM_CLKIN0_PIN_SEL == 1
#define TPM_CLKIN0_GPIO      digitalIO_PTA18
#define TPM_CLKIN0_FN        4
#elif TPM_CLKIN0_PIN_SEL == 2
#define TPM_CLKIN0_GPIO      digitalIO_PTB16
#define TPM_CLKIN0_FN        4
#elif TPM_CLKIN0_PIN_SEL == 3
#define TPM_CLKIN0_GPIO      digitalIO_PTC12
#define TPM_CLKIN0_FN        4
#elif TPM_CLKIN0_PIN_SEL == 4
#define TPM_CLKIN0_GPIO      digitalIO_PTE16
#define TPM_CLKIN0_FN        4
#elif TPM_CLKIN0_PIN_SEL == 5
#define TPM_CLKIN0_GPIO      digitalIO_PTE29
#define TPM_CLKIN0_FN        4
#endif

// Pin Mapping for TPM_CLKIN1 signal
//   <o> TPM_CLKIN1 [PTA19, PTB17, PTC13, PTE17, PTE30]<name=TPM_CLKIN1_PIN_SEL>
//   <i> Shows which pin TPM_CLKIN1 is mapped to
//     <0=> Disabled
//     <1=> PTA19<selection=PTA19_SIG_SEL,TPM_CLKIN1>
//     <2=> PTB17<selection=PTB17_SIG_SEL,TPM_CLKIN1>
//     <3=> PTC13<selection=PTC13_SIG_SEL,TPM_CLKIN1>
//     <4=> PTE17<selection=PTE17_SIG_SEL,TPM_CLKIN1>
//     <5=> PTE30<selection=PTE30_SIG_SEL,TPM_CLKIN1>
//     <0=> Default
#define TPM_CLKIN1_PIN_SEL   0
#if TPM_CLKIN1_PIN_SEL == 1
#define TPM_CLKIN1_GPIO      digitalIO_PTA19
#define TPM_CLKIN1_FN        4
#elif TPM_CLKIN1_PIN_SEL == 2
#define TPM_CLKIN1_GPIO      digitalIO_PTB17
#define TPM_CLKIN1_FN        4
#elif TPM_CLKIN1_PIN_SEL == 3
#define TPM_CLKIN1_GPIO      digitalIO_PTC13
#define TPM_CLKIN1_FN        4
#elif TPM_CLKIN1_PIN_SEL == 4
#define TPM_CLKIN1_GPIO      digitalIO_PTE17
#define TPM_CLKIN1_FN        4
#elif TPM_CLKIN1_PIN_SEL == 5
#define TPM_CLKIN1_GPIO      digitalIO_PTE30
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
#if XTAL0_PIN_SEL == 2
#define XTAL0_GPIO           digitalIO_PTA19
#define XTAL0_FN             0
#endif

// </h>

// <h> Analogue Comparator (CMP0)

// Pin Mapping for CMP0_IN0 signal
//   <o> CMP0_IN0 [PTC6]<name=CMP0_IN0_PIN_SEL>
//   <i> Shows which pin CMP0_IN0 is mapped to
//     <0=> Disabled
//     <1=> PTC6 (reset default)<selection=PTC6_SIG_SEL,LCD_P26/CMP0_IN0 (reset default)>
//     <2=> PTC6<selection=PTC6_SIG_SEL,LCD_P26/CMP0_IN0>
//     <1=> Default
#define CMP0_IN0_PIN_SEL     1
#if CMP0_IN0_PIN_SEL == 2
#define CMP0_IN0_GPIO        digitalIO_PTC6
#define CMP0_IN0_FN          0
#endif

// Pin Mapping for CMP0_IN1 signal
//   <o> CMP0_IN1 [PTC7]<name=CMP0_IN1_PIN_SEL>
//   <i> Shows which pin CMP0_IN1 is mapped to
//     <0=> Disabled
//     <1=> PTC7 (reset default)<selection=PTC7_SIG_SEL,LCD_P27/CMP0_IN1 (reset default)>
//     <2=> PTC7<selection=PTC7_SIG_SEL,LCD_P27/CMP0_IN1>
//     <1=> Default
#define CMP0_IN1_PIN_SEL     1
#if CMP0_IN1_PIN_SEL == 2
#define CMP0_IN1_GPIO        digitalIO_PTC7
#define CMP0_IN1_FN          0
#endif

// Pin Mapping for CMP0_IN2 signal
//   <o> CMP0_IN2 [PTC8]<name=CMP0_IN2_PIN_SEL>
//   <i> Shows which pin CMP0_IN2 is mapped to
//     <0=> Disabled
//     <1=> PTC8 (Alias:D6) (reset default)<selection=PTC8_SIG_SEL,LCD_P28/CMP0_IN2 (reset default)>
//     <2=> PTC8 (Alias:D6)<selection=PTC8_SIG_SEL,LCD_P28/CMP0_IN2>
//     <0=> Default
#define CMP0_IN2_PIN_SEL     0
#if CMP0_IN2_PIN_SEL == 2
#define CMP0_IN2_GPIO        digitalIO_PTC8
#define CMP0_IN2_FN          0
#endif

// Pin Mapping for CMP0_IN3 signal
//   <o> CMP0_IN3 [PTC9]<name=CMP0_IN3_PIN_SEL>
//   <i> Shows which pin CMP0_IN3 is mapped to
//     <0=> Disabled
//     <1=> PTC9 (Alias:D7) (reset default)<selection=PTC9_SIG_SEL,LCD_P29/CMP0_IN3 (reset default)>
//     <2=> PTC9 (Alias:D7)<selection=PTC9_SIG_SEL,LCD_P29/CMP0_IN3>
//     <0=> Default
#define CMP0_IN3_PIN_SEL     0
#if CMP0_IN3_PIN_SEL == 2
#define CMP0_IN3_GPIO        digitalIO_PTC9
#define CMP0_IN3_FN          0
#endif

// Pin Mapping for CMP0_IN4 signal
//   <o> CMP0_IN4 [PTE30]<name=CMP0_IN4_PIN_SEL>
//   <i> Shows which pin CMP0_IN4 is mapped to
//     <0=> Disabled
//     <1=> PTE30 (reset default)<selection=PTE30_SIG_SEL,DAC0_OUT/ADC0_SE23/CMP0_IN4 (reset default)>
//     <2=> PTE30<selection=PTE30_SIG_SEL,DAC0_OUT/ADC0_SE23/CMP0_IN4>
//     <1=> Default
#define CMP0_IN4_PIN_SEL     1
#if CMP0_IN4_PIN_SEL == 2
#define CMP0_IN4_GPIO        digitalIO_PTE30
#define CMP0_IN4_FN          0
#endif

// Pin Mapping for CMP0_IN5 signal
//   <o> CMP0_IN5 [PTE29]<name=CMP0_IN5_PIN_SEL>
//   <i> Shows which pin CMP0_IN5 is mapped to
//     <0=> Disabled
//     <1=> PTE29 (Alias:LED_RED) (reset default)<selection=PTE29_SIG_SEL,CMP0_IN5/ADC0_SE4b (reset default)>
//     <2=> PTE29 (Alias:LED_RED)<selection=PTE29_SIG_SEL,CMP0_IN5/ADC0_SE4b>
//     <0=> Default
#define CMP0_IN5_PIN_SEL     0
#if CMP0_IN5_PIN_SEL == 2
#define CMP0_IN5_GPIO        digitalIO_PTE29
#define CMP0_IN5_FN          0
#endif

// Pin Mapping for CMP0_OUT signal
//   <o> CMP0_OUT [PTC0, PTE0, PTB20, PTC5]<name=CMP0_OUT_PIN_SEL>
//   <i> Shows which pin CMP0_OUT is mapped to
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,CMP0_OUT>
//     <2=> PTE0 (Alias:D14)<selection=PTE0_SIG_SEL,CMP0_OUT>
//     <3=> PTB20<selection=PTB20_SIG_SEL,CMP0_OUT>
//     <4=> PTC5 (Alias:ACC_INT1)<selection=PTC5_SIG_SEL,CMP0_OUT>
//     <0=> Default
#define CMP0_OUT_PIN_SEL     0
#if CMP0_OUT_PIN_SEL == 1
#define CMP0_OUT_GPIO        digitalIO_PTC0
#define CMP0_OUT_FN          5
#elif CMP0_OUT_PIN_SEL == 2
#define CMP0_OUT_GPIO        digitalIO_PTE0
#define CMP0_OUT_FN          5
#elif CMP0_OUT_PIN_SEL == 3
#define CMP0_OUT_GPIO        digitalIO_PTB20
#define CMP0_OUT_FN          6
#elif CMP0_OUT_PIN_SEL == 4
#define CMP0_OUT_GPIO        digitalIO_PTC5
#define CMP0_OUT_FN          6
#endif

// </h>

// <h> Digital to Analogue (DAC0)

// Pin Mapping for DAC0_OUT signal
//   <o> DAC0_OUT [PTE30]<name=DAC0_OUT_PIN_SEL>
//   <i> Shows which pin DAC0_OUT is mapped to
//     <0=> Disabled
//     <1=> PTE30 (reset default)<selection=PTE30_SIG_SEL,DAC0_OUT/ADC0_SE23/CMP0_IN4 (reset default)>
//     <2=> PTE30<selection=PTE30_SIG_SEL,DAC0_OUT/ADC0_SE23/CMP0_IN4>
//     <1=> Default
#define DAC0_OUT_PIN_SEL     1
#if DAC0_OUT_PIN_SEL == 2
#define DAC0_OUT_GPIO        digitalIO_PTE30
#define DAC0_OUT_FN          0
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
#if GPIOA_0_PIN_SEL == 1
#define GPIOA_0_GPIO         digitalIO_PTA0
#define GPIOA_0_FN           1
#endif

// Pin Mapping for GPIOA_1 signal
//   <o> GPIOA_1 [PTA1]<name=GPIOA_1_PIN_SEL>
//   <i> Shows which pin GPIOA_1 is mapped to
//     <0=> Disabled
//     <1=> PTA1 (Alias:D0)<selection=PTA1_SIG_SEL,GPIOA_1>
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
//     <1=> PTA2 (Alias:D1)<selection=PTA2_SIG_SEL,GPIOA_2>
//     <1=> Default
#define GPIOA_2_PIN_SEL      1
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
//     <1=> PTA4 (Alias:D4)<selection=PTA4_SIG_SEL,GPIOA_4>
//     <1=> Default
#define GPIOA_4_PIN_SEL      1
#if GPIOA_4_PIN_SEL == 1
#define GPIOA_4_GPIO         digitalIO_PTA4
#define GPIOA_4_FN           1
#endif

// Pin Mapping for GPIOA_5 signal
//   <o> GPIOA_5 [PTA5]<name=GPIOA_5_PIN_SEL>
//   <i> Shows which pin GPIOA_5 is mapped to
//     <0=> Disabled
//     <1=> PTA5 (Alias:D5)<selection=PTA5_SIG_SEL,GPIOA_5>
//     <1=> Default
#define GPIOA_5_PIN_SEL      1
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

// Pin Mapping for GPIOA_12 signal
//   <o> GPIOA_12 [PTA12]<name=GPIOA_12_PIN_SEL>
//   <i> Shows which pin GPIOA_12 is mapped to
//     <0=> Disabled
//     <1=> PTA12 (Alias:D3)<selection=PTA12_SIG_SEL,GPIOA_12>
//     <1=> Default
#define GPIOA_12_PIN_SEL     1
#if GPIOA_12_PIN_SEL == 1
#define GPIOA_12_GPIO        digitalIO_PTA12
#define GPIOA_12_FN          1
#endif

// Pin Mapping for GPIOA_13 signal
//   <o> GPIOA_13 [PTA13]<name=GPIOA_13_PIN_SEL>
//   <i> Shows which pin GPIOA_13 is mapped to
//     <0=> Disabled
//     <1=> PTA13 (Alias:D8)<selection=PTA13_SIG_SEL,GPIOA_13>
//     <1=> Default
#define GPIOA_13_PIN_SEL     1
#if GPIOA_13_PIN_SEL == 1
#define GPIOA_13_GPIO        digitalIO_PTA13
#define GPIOA_13_FN          1
#endif

// Pin Mapping for GPIOA_14 signal
//   <o> GPIOA_14 [PTA14]<name=GPIOA_14_PIN_SEL>
//   <i> Shows which pin GPIOA_14 is mapped to
//     <0=> Disabled
//     <1=> PTA14<selection=PTA14_SIG_SEL,GPIOA_14>
//     <0=> Default
#define GPIOA_14_PIN_SEL     0
#if GPIOA_14_PIN_SEL == 1
#define GPIOA_14_GPIO        digitalIO_PTA14
#define GPIOA_14_FN          1
#endif

// Pin Mapping for GPIOA_15 signal
//   <o> GPIOA_15 [PTA15]<name=GPIOA_15_PIN_SEL>
//   <i> Shows which pin GPIOA_15 is mapped to
//     <0=> Disabled
//     <1=> PTA15<selection=PTA15_SIG_SEL,GPIOA_15>
//     <0=> Default
#define GPIOA_15_PIN_SEL     0
#if GPIOA_15_PIN_SEL == 1
#define GPIOA_15_GPIO        digitalIO_PTA15
#define GPIOA_15_FN          1
#endif

// Pin Mapping for GPIOA_16 signal
//   <o> GPIOA_16 [PTA16]<name=GPIOA_16_PIN_SEL>
//   <i> Shows which pin GPIOA_16 is mapped to
//     <0=> Disabled
//     <1=> PTA16<selection=PTA16_SIG_SEL,GPIOA_16>
//     <0=> Default
#define GPIOA_16_PIN_SEL     0
#if GPIOA_16_PIN_SEL == 1
#define GPIOA_16_GPIO        digitalIO_PTA16
#define GPIOA_16_FN          1
#endif

// Pin Mapping for GPIOA_17 signal
//   <o> GPIOA_17 [PTA17]<name=GPIOA_17_PIN_SEL>
//   <i> Shows which pin GPIOA_17 is mapped to
//     <0=> Disabled
//     <1=> PTA17<selection=PTA17_SIG_SEL,GPIOA_17>
//     <0=> Default
#define GPIOA_17_PIN_SEL     0
#if GPIOA_17_PIN_SEL == 1
#define GPIOA_17_GPIO        digitalIO_PTA17
#define GPIOA_17_FN          1
#endif

// Pin Mapping for GPIOA_18 signal
//   <o> GPIOA_18 [PTA18]<name=GPIOA_18_PIN_SEL>
//   <i> Shows which pin GPIOA_18 is mapped to
//     <0=> Disabled
//     <1=> PTA18<selection=PTA18_SIG_SEL,GPIOA_18>
//     <0=> Default
#define GPIOA_18_PIN_SEL     0
#if GPIOA_18_PIN_SEL == 1
#define GPIOA_18_GPIO        digitalIO_PTA18
#define GPIOA_18_FN          1
#endif

// Pin Mapping for GPIOA_19 signal
//   <o> GPIOA_19 [PTA19]<name=GPIOA_19_PIN_SEL>
//   <i> Shows which pin GPIOA_19 is mapped to
//     <0=> Disabled
//     <1=> PTA19<selection=PTA19_SIG_SEL,GPIOA_19>
//     <0=> Default
#define GPIOA_19_PIN_SEL     0
#if GPIOA_19_PIN_SEL == 1
#define GPIOA_19_GPIO        digitalIO_PTA19
#define GPIOA_19_FN          1
#endif

// Pin Mapping for GPIOA_20 signal
//   <o> GPIOA_20 [PTA20]<name=GPIOA_20_PIN_SEL>
//   <i> Shows which pin GPIOA_20 is mapped to
//     <0=> Disabled
//     <1=> PTA20<selection=PTA20_SIG_SEL,GPIOA_20>
//     <0=> Default
#define GPIOA_20_PIN_SEL     0
#if GPIOA_20_PIN_SEL == 1
#define GPIOA_20_GPIO        digitalIO_PTA20
#define GPIOA_20_FN          1
#endif

// </h>

// <h> General Purpose I/O (GPIOB)

// Pin Mapping for GPIOB_0 signal
//   <o> GPIOB_0 [PTB0]<name=GPIOB_0_PIN_SEL>
//   <i> Shows which pin GPIOB_0 is mapped to
//     <0=> Disabled
//     <1=> PTB0 (Alias:A0)<selection=PTB0_SIG_SEL,GPIOB_0/LLWU_P5>
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
//     <1=> PTB1 (Alias:A1)<selection=PTB1_SIG_SEL,GPIOB_1>
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
//     <1=> PTB2 (Alias:A2)<selection=PTB2_SIG_SEL,GPIOB_2>
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
//     <1=> PTB3 (Alias:A3)<selection=PTB3_SIG_SEL,GPIOB_3>
//     <0=> Default
#define GPIOB_3_PIN_SEL      0
#if GPIOB_3_PIN_SEL == 1
#define GPIOB_3_GPIO         digitalIO_PTB3
#define GPIOB_3_FN           1
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

// Pin Mapping for GPIOB_8 signal
//   <o> GPIOB_8 [PTB8]<name=GPIOB_8_PIN_SEL>
//   <i> Shows which pin GPIOB_8 is mapped to
//     <0=> Disabled
//     <1=> PTB8<selection=PTB8_SIG_SEL,GPIOB_8>
//     <0=> Default
#define GPIOB_8_PIN_SEL      0
#if GPIOB_8_PIN_SEL == 1
#define GPIOB_8_GPIO         digitalIO_PTB8
#define GPIOB_8_FN           1
#endif

// Pin Mapping for GPIOB_9 signal
//   <o> GPIOB_9 [PTB9]<name=GPIOB_9_PIN_SEL>
//   <i> Shows which pin GPIOB_9 is mapped to
//     <0=> Disabled
//     <1=> PTB9<selection=PTB9_SIG_SEL,GPIOB_9>
//     <0=> Default
#define GPIOB_9_PIN_SEL      0
#if GPIOB_9_PIN_SEL == 1
#define GPIOB_9_GPIO         digitalIO_PTB9
#define GPIOB_9_FN           1
#endif

// Pin Mapping for GPIOB_10 signal
//   <o> GPIOB_10 [PTB10]<name=GPIOB_10_PIN_SEL>
//   <i> Shows which pin GPIOB_10 is mapped to
//     <0=> Disabled
//     <1=> PTB10<selection=PTB10_SIG_SEL,GPIOB_10>
//     <0=> Default
#define GPIOB_10_PIN_SEL     0
#if GPIOB_10_PIN_SEL == 1
#define GPIOB_10_GPIO        digitalIO_PTB10
#define GPIOB_10_FN          1
#endif

// Pin Mapping for GPIOB_11 signal
//   <o> GPIOB_11 [PTB11]<name=GPIOB_11_PIN_SEL>
//   <i> Shows which pin GPIOB_11 is mapped to
//     <0=> Disabled
//     <1=> PTB11<selection=PTB11_SIG_SEL,GPIOB_11>
//     <0=> Default
#define GPIOB_11_PIN_SEL     0
#if GPIOB_11_PIN_SEL == 1
#define GPIOB_11_GPIO        digitalIO_PTB11
#define GPIOB_11_FN          1
#endif

// Pin Mapping for GPIOB_16 signal
//   <o> GPIOB_16 [PTB16]<name=GPIOB_16_PIN_SEL>
//   <i> Shows which pin GPIOB_16 is mapped to
//     <0=> Disabled
//     <1=> PTB16<selection=PTB16_SIG_SEL,GPIOB_16>
//     <0=> Default
#define GPIOB_16_PIN_SEL     0
#if GPIOB_16_PIN_SEL == 1
#define GPIOB_16_GPIO        digitalIO_PTB16
#define GPIOB_16_FN          1
#endif

// Pin Mapping for GPIOB_17 signal
//   <o> GPIOB_17 [PTB17]<name=GPIOB_17_PIN_SEL>
//   <i> Shows which pin GPIOB_17 is mapped to
//     <0=> Disabled
//     <1=> PTB17<selection=PTB17_SIG_SEL,GPIOB_17>
//     <0=> Default
#define GPIOB_17_PIN_SEL     0
#if GPIOB_17_PIN_SEL == 1
#define GPIOB_17_GPIO        digitalIO_PTB17
#define GPIOB_17_FN          1
#endif

// Pin Mapping for GPIOB_18 signal
//   <o> GPIOB_18 [PTB18]<name=GPIOB_18_PIN_SEL>
//   <i> Shows which pin GPIOB_18 is mapped to
//     <0=> Disabled
//     <1=> PTB18<selection=PTB18_SIG_SEL,GPIOB_18>
//     <0=> Default
#define GPIOB_18_PIN_SEL     0
#if GPIOB_18_PIN_SEL == 1
#define GPIOB_18_GPIO        digitalIO_PTB18
#define GPIOB_18_FN          1
#endif

// Pin Mapping for GPIOB_19 signal
//   <o> GPIOB_19 [PTB19]<name=GPIOB_19_PIN_SEL>
//   <i> Shows which pin GPIOB_19 is mapped to
//     <0=> Disabled
//     <1=> PTB19<selection=PTB19_SIG_SEL,GPIOB_19>
//     <0=> Default
#define GPIOB_19_PIN_SEL     0
#if GPIOB_19_PIN_SEL == 1
#define GPIOB_19_GPIO        digitalIO_PTB19
#define GPIOB_19_FN          1
#endif

// Pin Mapping for GPIOB_20 signal
//   <o> GPIOB_20 [PTB20]<name=GPIOB_20_PIN_SEL>
//   <i> Shows which pin GPIOB_20 is mapped to
//     <0=> Disabled
//     <1=> PTB20<selection=PTB20_SIG_SEL,GPIOB_20>
//     <0=> Default
#define GPIOB_20_PIN_SEL     0
#if GPIOB_20_PIN_SEL == 1
#define GPIOB_20_GPIO        digitalIO_PTB20
#define GPIOB_20_FN          1
#endif

// Pin Mapping for GPIOB_21 signal
//   <o> GPIOB_21 [PTB21]<name=GPIOB_21_PIN_SEL>
//   <i> Shows which pin GPIOB_21 is mapped to
//     <0=> Disabled
//     <1=> PTB21<selection=PTB21_SIG_SEL,GPIOB_21>
//     <0=> Default
#define GPIOB_21_PIN_SEL     0
#if GPIOB_21_PIN_SEL == 1
#define GPIOB_21_GPIO        digitalIO_PTB21
#define GPIOB_21_FN          1
#endif

// Pin Mapping for GPIOB_22 signal
//   <o> GPIOB_22 [PTB22]<name=GPIOB_22_PIN_SEL>
//   <i> Shows which pin GPIOB_22 is mapped to
//     <0=> Disabled
//     <1=> PTB22<selection=PTB22_SIG_SEL,GPIOB_22>
//     <0=> Default
#define GPIOB_22_PIN_SEL     0
#if GPIOB_22_PIN_SEL == 1
#define GPIOB_22_GPIO        digitalIO_PTB22
#define GPIOB_22_FN          1
#endif

// Pin Mapping for GPIOB_23 signal
//   <o> GPIOB_23 [PTB23]<name=GPIOB_23_PIN_SEL>
//   <i> Shows which pin GPIOB_23 is mapped to
//     <0=> Disabled
//     <1=> PTB23<selection=PTB23_SIG_SEL,GPIOB_23>
//     <0=> Default
#define GPIOB_23_PIN_SEL     0
#if GPIOB_23_PIN_SEL == 1
#define GPIOB_23_GPIO        digitalIO_PTB23
#define GPIOB_23_FN          1
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
//     <1=> PTC1 (Alias:A5)<selection=PTC1_SIG_SEL,GPIOC_1/LLWU_P6/RTC_CLKIN>
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
//     <1=> PTC2 (Alias:A4)<selection=PTC2_SIG_SEL,GPIOC_2>
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
//     <1=> PTC3<selection=PTC3_SIG_SEL,GPIOC_3/LLWU_P7>
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
//     <1=> PTC4<selection=PTC4_SIG_SEL,GPIOC_4/LLWU_P8>
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
//     <1=> PTC5 (Alias:ACC_INT1)<selection=PTC5_SIG_SEL,GPIOC_5/LLWU_P9>
//     <1=> Default
#define GPIOC_5_PIN_SEL      1
#if GPIOC_5_PIN_SEL == 1
#define GPIOC_5_GPIO         digitalIO_PTC5
#define GPIOC_5_FN           1
#endif

// Pin Mapping for GPIOC_6 signal
//   <o> GPIOC_6 [PTC6]<name=GPIOC_6_PIN_SEL>
//   <i> Shows which pin GPIOC_6 is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,GPIOC_6/LLWU_P10>
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

// Pin Mapping for GPIOC_8 signal
//   <o> GPIOC_8 [PTC8]<name=GPIOC_8_PIN_SEL>
//   <i> Shows which pin GPIOC_8 is mapped to
//     <0=> Disabled
//     <1=> PTC8 (Alias:D6)<selection=PTC8_SIG_SEL,GPIOC_8>
//     <1=> Default
#define GPIOC_8_PIN_SEL      1
#if GPIOC_8_PIN_SEL == 1
#define GPIOC_8_GPIO         digitalIO_PTC8
#define GPIOC_8_FN           1
#endif

// Pin Mapping for GPIOC_9 signal
//   <o> GPIOC_9 [PTC9]<name=GPIOC_9_PIN_SEL>
//   <i> Shows which pin GPIOC_9 is mapped to
//     <0=> Disabled
//     <1=> PTC9 (Alias:D7)<selection=PTC9_SIG_SEL,GPIOC_9>
//     <1=> Default
#define GPIOC_9_PIN_SEL      1
#if GPIOC_9_PIN_SEL == 1
#define GPIOC_9_GPIO         digitalIO_PTC9
#define GPIOC_9_FN           1
#endif

// Pin Mapping for GPIOC_10 signal
//   <o> GPIOC_10 [PTC10]<name=GPIOC_10_PIN_SEL>
//   <i> Shows which pin GPIOC_10 is mapped to
//     <0=> Disabled
//     <1=> PTC10<selection=PTC10_SIG_SEL,GPIOC_10>
//     <0=> Default
#define GPIOC_10_PIN_SEL     0
#if GPIOC_10_PIN_SEL == 1
#define GPIOC_10_GPIO        digitalIO_PTC10
#define GPIOC_10_FN          1
#endif

// Pin Mapping for GPIOC_11 signal
//   <o> GPIOC_11 [PTC11]<name=GPIOC_11_PIN_SEL>
//   <i> Shows which pin GPIOC_11 is mapped to
//     <0=> Disabled
//     <1=> PTC11<selection=PTC11_SIG_SEL,GPIOC_11>
//     <0=> Default
#define GPIOC_11_PIN_SEL     0
#if GPIOC_11_PIN_SEL == 1
#define GPIOC_11_GPIO        digitalIO_PTC11
#define GPIOC_11_FN          1
#endif

// Pin Mapping for GPIOC_12 signal
//   <o> GPIOC_12 [PTC12]<name=GPIOC_12_PIN_SEL>
//   <i> Shows which pin GPIOC_12 is mapped to
//     <0=> Disabled
//     <1=> PTC12<selection=PTC12_SIG_SEL,GPIOC_12>
//     <0=> Default
#define GPIOC_12_PIN_SEL     0
#if GPIOC_12_PIN_SEL == 1
#define GPIOC_12_GPIO        digitalIO_PTC12
#define GPIOC_12_FN          1
#endif

// Pin Mapping for GPIOC_13 signal
//   <o> GPIOC_13 [PTC13]<name=GPIOC_13_PIN_SEL>
//   <i> Shows which pin GPIOC_13 is mapped to
//     <0=> Disabled
//     <1=> PTC13<selection=PTC13_SIG_SEL,GPIOC_13>
//     <0=> Default
#define GPIOC_13_PIN_SEL     0
#if GPIOC_13_PIN_SEL == 1
#define GPIOC_13_GPIO        digitalIO_PTC13
#define GPIOC_13_FN          1
#endif

// Pin Mapping for GPIOC_16 signal
//   <o> GPIOC_16 [PTC16]<name=GPIOC_16_PIN_SEL>
//   <i> Shows which pin GPIOC_16 is mapped to
//     <0=> Disabled
//     <1=> PTC16<selection=PTC16_SIG_SEL,GPIOC_16>
//     <0=> Default
#define GPIOC_16_PIN_SEL     0
#if GPIOC_16_PIN_SEL == 1
#define GPIOC_16_GPIO        digitalIO_PTC16
#define GPIOC_16_FN          1
#endif

// Pin Mapping for GPIOC_17 signal
//   <o> GPIOC_17 [PTC17]<name=GPIOC_17_PIN_SEL>
//   <i> Shows which pin GPIOC_17 is mapped to
//     <0=> Disabled
//     <1=> PTC17<selection=PTC17_SIG_SEL,GPIOC_17>
//     <0=> Default
#define GPIOC_17_PIN_SEL     0
#if GPIOC_17_PIN_SEL == 1
#define GPIOC_17_GPIO        digitalIO_PTC17
#define GPIOC_17_FN          1
#endif

// Pin Mapping for GPIOC_18 signal
//   <o> GPIOC_18 [PTC18]<name=GPIOC_18_PIN_SEL>
//   <i> Shows which pin GPIOC_18 is mapped to
//     <0=> Disabled
//     <1=> PTC18<selection=PTC18_SIG_SEL,GPIOC_18>
//     <0=> Default
#define GPIOC_18_PIN_SEL     0
#if GPIOC_18_PIN_SEL == 1
#define GPIOC_18_GPIO        digitalIO_PTC18
#define GPIOC_18_FN          1
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
//     <1=> PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE)<selection=PTD1_SIG_SEL,GPIOD_1>
//     <0=> Default
#define GPIOD_1_PIN_SEL      0
#if GPIOD_1_PIN_SEL == 1
#define GPIOD_1_GPIO         digitalIO_PTD1
#define GPIOD_1_FN           1
#endif

// Pin Mapping for GPIOD_2 signal
//   <o> GPIOD_2 [PTD2]<name=GPIOD_2_PIN_SEL>
//   <i> Shows which pin GPIOD_2 is mapped to
//     <0=> Disabled
//     <1=> PTD2 (Alias:D9)<selection=PTD2_SIG_SEL,GPIOD_2>
//     <1=> Default
#define GPIOD_2_PIN_SEL      1
#if GPIOD_2_PIN_SEL == 1
#define GPIOD_2_GPIO         digitalIO_PTD2
#define GPIOD_2_FN           1
#endif

// Pin Mapping for GPIOD_3 signal
//   <o> GPIOD_3 [PTD3]<name=GPIOD_3_PIN_SEL>
//   <i> Shows which pin GPIOD_3 is mapped to
//     <0=> Disabled
//     <1=> PTD3 (Alias:D2)<selection=PTD3_SIG_SEL,GPIOD_3>
//     <1=> Default
#define GPIOD_3_PIN_SEL      1
#if GPIOD_3_PIN_SEL == 1
#define GPIOD_3_GPIO         digitalIO_PTD3
#define GPIOD_3_FN           1
#endif

// Pin Mapping for GPIOD_4 signal
//   <o> GPIOD_4 [PTD4]<name=GPIOD_4_PIN_SEL>
//   <i> Shows which pin GPIOD_4 is mapped to
//     <0=> Disabled
//     <1=> PTD4 (Alias:D10)<selection=PTD4_SIG_SEL,GPIOD_4/LLWU_P14>
//     <1=> Default
#define GPIOD_4_PIN_SEL      1
#if GPIOD_4_PIN_SEL == 1
#define GPIOD_4_GPIO         digitalIO_PTD4
#define GPIOD_4_FN           1
#endif

// Pin Mapping for GPIOD_5 signal
//   <o> GPIOD_5 [PTD5]<name=GPIOD_5_PIN_SEL>
//   <i> Shows which pin GPIOD_5 is mapped to
//     <0=> Disabled
//     <1=> PTD5 (Alias:D13, LED_GREEN)<selection=PTD5_SIG_SEL,GPIOD_5>
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
//     <1=> PTD6 (Alias:D11)<selection=PTD6_SIG_SEL,GPIOD_6/LLWU_P15>
//     <1=> Default
#define GPIOD_6_PIN_SEL      1
#if GPIOD_6_PIN_SEL == 1
#define GPIOD_6_GPIO         digitalIO_PTD6
#define GPIOD_6_FN           1
#endif

// Pin Mapping for GPIOD_7 signal
//   <o> GPIOD_7 [PTD7]<name=GPIOD_7_PIN_SEL>
//   <i> Shows which pin GPIOD_7 is mapped to
//     <0=> Disabled
//     <1=> PTD7 (Alias:D12)<selection=PTD7_SIG_SEL,GPIOD_7>
//     <1=> Default
#define GPIOD_7_PIN_SEL      1
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
//     <1=> PTE0 (Alias:D14)<selection=PTE0_SIG_SEL,GPIOE_0>
//     <1=> Default
#define GPIOE_0_PIN_SEL      1
#if GPIOE_0_PIN_SEL == 1
#define GPIOE_0_GPIO         digitalIO_PTE0
#define GPIOE_0_FN           1
#endif

// Pin Mapping for GPIOE_1 signal
//   <o> GPIOE_1 [PTE1]<name=GPIOE_1_PIN_SEL>
//   <i> Shows which pin GPIOE_1 is mapped to
//     <0=> Disabled
//     <1=> PTE1 (Alias:D15)<selection=PTE1_SIG_SEL,GPIOE_1>
//     <1=> Default
#define GPIOE_1_PIN_SEL      1
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

// Pin Mapping for GPIOE_16 signal
//   <o> GPIOE_16 [PTE16]<name=GPIOE_16_PIN_SEL>
//   <i> Shows which pin GPIOE_16 is mapped to
//     <0=> Disabled
//     <1=> PTE16<selection=PTE16_SIG_SEL,GPIOE_16>
//     <0=> Default
#define GPIOE_16_PIN_SEL     0
#if GPIOE_16_PIN_SEL == 1
#define GPIOE_16_GPIO        digitalIO_PTE16
#define GPIOE_16_FN          1
#endif

// Pin Mapping for GPIOE_17 signal
//   <o> GPIOE_17 [PTE17]<name=GPIOE_17_PIN_SEL>
//   <i> Shows which pin GPIOE_17 is mapped to
//     <0=> Disabled
//     <1=> PTE17<selection=PTE17_SIG_SEL,GPIOE_17>
//     <0=> Default
#define GPIOE_17_PIN_SEL     0
#if GPIOE_17_PIN_SEL == 1
#define GPIOE_17_GPIO        digitalIO_PTE17
#define GPIOE_17_FN          1
#endif

// Pin Mapping for GPIOE_18 signal
//   <o> GPIOE_18 [PTE18]<name=GPIOE_18_PIN_SEL>
//   <i> Shows which pin GPIOE_18 is mapped to
//     <0=> Disabled
//     <1=> PTE18<selection=PTE18_SIG_SEL,GPIOE_18>
//     <0=> Default
#define GPIOE_18_PIN_SEL     0
#if GPIOE_18_PIN_SEL == 1
#define GPIOE_18_GPIO        digitalIO_PTE18
#define GPIOE_18_FN          1
#endif

// Pin Mapping for GPIOE_19 signal
//   <o> GPIOE_19 [PTE19]<name=GPIOE_19_PIN_SEL>
//   <i> Shows which pin GPIOE_19 is mapped to
//     <0=> Disabled
//     <1=> PTE19<selection=PTE19_SIG_SEL,GPIOE_19>
//     <0=> Default
#define GPIOE_19_PIN_SEL     0
#if GPIOE_19_PIN_SEL == 1
#define GPIOE_19_GPIO        digitalIO_PTE19
#define GPIOE_19_FN          1
#endif

// Pin Mapping for GPIOE_20 signal
//   <o> GPIOE_20 [PTE20]<name=GPIOE_20_PIN_SEL>
//   <i> Shows which pin GPIOE_20 is mapped to
//     <0=> Disabled
//     <1=> PTE20<selection=PTE20_SIG_SEL,GPIOE_20>
//     <0=> Default
#define GPIOE_20_PIN_SEL     0
#if GPIOE_20_PIN_SEL == 1
#define GPIOE_20_GPIO        digitalIO_PTE20
#define GPIOE_20_FN          1
#endif

// Pin Mapping for GPIOE_21 signal
//   <o> GPIOE_21 [PTE21]<name=GPIOE_21_PIN_SEL>
//   <i> Shows which pin GPIOE_21 is mapped to
//     <0=> Disabled
//     <1=> PTE21<selection=PTE21_SIG_SEL,GPIOE_21>
//     <0=> Default
#define GPIOE_21_PIN_SEL     0
#if GPIOE_21_PIN_SEL == 1
#define GPIOE_21_GPIO        digitalIO_PTE21
#define GPIOE_21_FN          1
#endif

// Pin Mapping for GPIOE_22 signal
//   <o> GPIOE_22 [PTE22]<name=GPIOE_22_PIN_SEL>
//   <i> Shows which pin GPIOE_22 is mapped to
//     <0=> Disabled
//     <1=> PTE22 (Alias:LIGHT_SENS)<selection=PTE22_SIG_SEL,GPIOE_22>
//     <0=> Default
#define GPIOE_22_PIN_SEL     0
#if GPIOE_22_PIN_SEL == 1
#define GPIOE_22_GPIO        digitalIO_PTE22
#define GPIOE_22_FN          1
#endif

// Pin Mapping for GPIOE_23 signal
//   <o> GPIOE_23 [PTE23]<name=GPIOE_23_PIN_SEL>
//   <i> Shows which pin GPIOE_23 is mapped to
//     <0=> Disabled
//     <1=> PTE23<selection=PTE23_SIG_SEL,GPIOE_23>
//     <0=> Default
#define GPIOE_23_PIN_SEL     0
#if GPIOE_23_PIN_SEL == 1
#define GPIOE_23_GPIO        digitalIO_PTE23
#define GPIOE_23_FN          1
#endif

// Pin Mapping for GPIOE_24 signal
//   <o> GPIOE_24 [PTE24]<name=GPIOE_24_PIN_SEL>
//   <i> Shows which pin GPIOE_24 is mapped to
//     <0=> Disabled
//     <1=> PTE24 (Alias:MAG_SCL, ACC_SCL)<selection=PTE24_SIG_SEL,GPIOE_24>
//     <0=> Default
#define GPIOE_24_PIN_SEL     0
#if GPIOE_24_PIN_SEL == 1
#define GPIOE_24_GPIO        digitalIO_PTE24
#define GPIOE_24_FN          1
#endif

// Pin Mapping for GPIOE_25 signal
//   <o> GPIOE_25 [PTE25]<name=GPIOE_25_PIN_SEL>
//   <i> Shows which pin GPIOE_25 is mapped to
//     <0=> Disabled
//     <1=> PTE25 (Alias:MAG_SDA, ACC_SDA)<selection=PTE25_SIG_SEL,GPIOE_25>
//     <0=> Default
#define GPIOE_25_PIN_SEL     0
#if GPIOE_25_PIN_SEL == 1
#define GPIOE_25_GPIO        digitalIO_PTE25
#define GPIOE_25_FN          1
#endif

// Pin Mapping for GPIOE_26 signal
//   <o> GPIOE_26 [PTE26]<name=GPIOE_26_PIN_SEL>
//   <i> Shows which pin GPIOE_26 is mapped to
//     <0=> Disabled
//     <1=> PTE26<selection=PTE26_SIG_SEL,GPIOE_26>
//     <0=> Default
#define GPIOE_26_PIN_SEL     0
#if GPIOE_26_PIN_SEL == 1
#define GPIOE_26_GPIO        digitalIO_PTE26
#define GPIOE_26_FN          1
#endif

// Pin Mapping for GPIOE_29 signal
//   <o> GPIOE_29 [PTE29]<name=GPIOE_29_PIN_SEL>
//   <i> Shows which pin GPIOE_29 is mapped to
//     <0=> Disabled
//     <1=> PTE29 (Alias:LED_RED)<selection=PTE29_SIG_SEL,GPIOE_29>
//     <0=> Default
#define GPIOE_29_PIN_SEL     0
#if GPIOE_29_PIN_SEL == 1
#define GPIOE_29_GPIO        digitalIO_PTE29
#define GPIOE_29_FN          1
#endif

// Pin Mapping for GPIOE_30 signal
//   <o> GPIOE_30 [PTE30]<name=GPIOE_30_PIN_SEL>
//   <i> Shows which pin GPIOE_30 is mapped to
//     <0=> Disabled
//     <1=> PTE30<selection=PTE30_SIG_SEL,GPIOE_30>
//     <0=> Default
#define GPIOE_30_PIN_SEL     0
#if GPIOE_30_PIN_SEL == 1
#define GPIOE_30_GPIO        digitalIO_PTE30
#define GPIOE_30_FN          1
#endif

// Pin Mapping for GPIOE_31 signal
//   <o> GPIOE_31 [PTE31]<name=GPIOE_31_PIN_SEL>
//   <i> Shows which pin GPIOE_31 is mapped to
//     <0=> Disabled
//     <1=> PTE31<selection=PTE31_SIG_SEL,GPIOE_31>
//     <0=> Default
#define GPIOE_31_PIN_SEL     0
#if GPIOE_31_PIN_SEL == 1
#define GPIOE_31_GPIO        digitalIO_PTE31
#define GPIOE_31_FN          1
#endif

// </h>

// <h> Inter-Integrated Circuit (I2C0)

// Pin Mapping for I2C0_SCL signal
//   <o> I2C0_SCL [PTB0, PTB2, PTC8, PTE19, PTE24]<name=I2C0_SCL_PIN_SEL>
//   <i> Shows which pin I2C0_SCL is mapped to
//     <0=> Disabled
//     <1=> PTB0 (Alias:A0)<selection=PTB0_SIG_SEL,I2C0_SCL>
//     <2=> PTB2 (Alias:A2)<selection=PTB2_SIG_SEL,I2C0_SCL>
//     <3=> PTC8 (Alias:D6)<selection=PTC8_SIG_SEL,I2C0_SCL>
//     <4=> PTE19<selection=PTE19_SIG_SEL,I2C0_SCL>
//     <5=> PTE24 (Alias:MAG_SCL, ACC_SCL)<selection=PTE24_SIG_SEL,I2C0_SCL>
//     <5=> Default
#define I2C0_SCL_PIN_SEL     5
#if I2C0_SCL_PIN_SEL == 1
#define I2C0_SCL_GPIO        digitalIO_PTB0
#define I2C0_SCL_FN          2
#elif I2C0_SCL_PIN_SEL == 2
#define I2C0_SCL_GPIO        digitalIO_PTB2
#define I2C0_SCL_FN          2
#elif I2C0_SCL_PIN_SEL == 3
#define I2C0_SCL_GPIO        digitalIO_PTC8
#define I2C0_SCL_FN          2
#elif I2C0_SCL_PIN_SEL == 4
#define I2C0_SCL_GPIO        digitalIO_PTE19
#define I2C0_SCL_FN          4
#elif I2C0_SCL_PIN_SEL == 5
#define I2C0_SCL_GPIO        digitalIO_PTE24
#define I2C0_SCL_FN          5
#endif

// Pin Mapping for I2C0_SDA signal
//   <o> I2C0_SDA [PTB1, PTB3, PTC9, PTE18, PTE25]<name=I2C0_SDA_PIN_SEL>
//   <i> Shows which pin I2C0_SDA is mapped to
//     <0=> Disabled
//     <1=> PTB1 (Alias:A1)<selection=PTB1_SIG_SEL,I2C0_SDA>
//     <2=> PTB3 (Alias:A3)<selection=PTB3_SIG_SEL,I2C0_SDA>
//     <3=> PTC9 (Alias:D7)<selection=PTC9_SIG_SEL,I2C0_SDA>
//     <4=> PTE18<selection=PTE18_SIG_SEL,I2C0_SDA>
//     <5=> PTE25 (Alias:MAG_SDA, ACC_SDA)<selection=PTE25_SIG_SEL,I2C0_SDA>
//     <5=> Default
#define I2C0_SDA_PIN_SEL     5
#if I2C0_SDA_PIN_SEL == 1
#define I2C0_SDA_GPIO        digitalIO_PTB1
#define I2C0_SDA_FN          2
#elif I2C0_SDA_PIN_SEL == 2
#define I2C0_SDA_GPIO        digitalIO_PTB3
#define I2C0_SDA_FN          2
#elif I2C0_SDA_PIN_SEL == 3
#define I2C0_SDA_GPIO        digitalIO_PTC9
#define I2C0_SDA_FN          2
#elif I2C0_SDA_PIN_SEL == 4
#define I2C0_SDA_GPIO        digitalIO_PTE18
#define I2C0_SDA_FN          4
#elif I2C0_SDA_PIN_SEL == 5
#define I2C0_SDA_GPIO        digitalIO_PTE25
#define I2C0_SDA_FN          5
#endif

// </h>

// <h> Inter-Integrated Circuit (I2C1)

// Pin Mapping for I2C1_SDA signal
//   <o> I2C1_SDA [PTA4, PTC2, PTC11, PTE0]<name=I2C1_SDA_PIN_SEL>
//   <i> Shows which pin I2C1_SDA is mapped to
//     <0=> Disabled
//     <1=> PTA4 (Alias:D4)<selection=PTA4_SIG_SEL,I2C1_SDA>
//     <2=> PTC2 (Alias:A4)<selection=PTC2_SIG_SEL,I2C1_SDA>
//     <3=> PTC11<selection=PTC11_SIG_SEL,I2C1_SDA>
//     <4=> PTE0 (Alias:D14)<selection=PTE0_SIG_SEL,I2C1_SDA>
//     <0=> Default
#define I2C1_SDA_PIN_SEL     0
#if I2C1_SDA_PIN_SEL == 1
#define I2C1_SDA_GPIO        digitalIO_PTA4
#define I2C1_SDA_FN          2
#elif I2C1_SDA_PIN_SEL == 2
#define I2C1_SDA_GPIO        digitalIO_PTC2
#define I2C1_SDA_FN          2
#elif I2C1_SDA_PIN_SEL == 3
#define I2C1_SDA_GPIO        digitalIO_PTC11
#define I2C1_SDA_FN          2
#elif I2C1_SDA_PIN_SEL == 4
#define I2C1_SDA_GPIO        digitalIO_PTE0
#define I2C1_SDA_FN          6
#endif

// Pin Mapping for I2C1_SCL signal
//   <o> I2C1_SCL [PTA3, PTC1, PTC10, PTE1]<name=I2C1_SCL_PIN_SEL>
//   <i> Shows which pin I2C1_SCL is mapped to
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,I2C1_SCL>
//     <2=> PTC1 (Alias:A5)<selection=PTC1_SIG_SEL,I2C1_SCL>
//     <3=> PTC10<selection=PTC10_SIG_SEL,I2C1_SCL>
//     <4=> PTE1 (Alias:D15)<selection=PTE1_SIG_SEL,I2C1_SCL>
//     <0=> Default
#define I2C1_SCL_PIN_SEL     0
#if I2C1_SCL_PIN_SEL == 1
#define I2C1_SCL_GPIO        digitalIO_PTA3
#define I2C1_SCL_FN          2
#elif I2C1_SCL_PIN_SEL == 2
#define I2C1_SCL_GPIO        digitalIO_PTC1
#define I2C1_SCL_FN          2
#elif I2C1_SCL_PIN_SEL == 3
#define I2C1_SCL_GPIO        digitalIO_PTC10
#define I2C1_SCL_FN          2
#elif I2C1_SCL_PIN_SEL == 4
#define I2C1_SCL_GPIO        digitalIO_PTE1
#define I2C1_SCL_FN          6
#endif

// </h>

// <h> Integrated Interchip Sound (I2S0)

// Pin Mapping for I2S0_MCLK signal
//   <o> I2S0_MCLK [PTC8, PTE6, PTC4, PTA17, PTC6]<name=I2S0_MCLK_PIN_SEL>
//   <i> Shows which pin I2S0_MCLK is mapped to
//     <0=> Disabled
//     <1=> PTC8 (Alias:D6)<selection=PTC8_SIG_SEL,I2S0_MCLK>
//     <2=> PTE6<selection=PTE6_SIG_SEL,I2S0_MCLK>
//     <3=> PTC4<selection=PTC4_SIG_SEL,I2S0_MCLK>
//     <4=> PTA17<selection=PTA17_SIG_SEL,I2S0_MCLK>
//     <5=> PTC6<selection=PTC6_SIG_SEL,I2S0_MCLK>
//     <0=> Default
#define I2S0_MCLK_PIN_SEL    0
#if I2S0_MCLK_PIN_SEL == 1
#define I2S0_MCLK_GPIO       digitalIO_PTC8
#define I2S0_MCLK_FN         4
#elif I2S0_MCLK_PIN_SEL == 2
#define I2S0_MCLK_GPIO       digitalIO_PTE6
#define I2S0_MCLK_FN         4
#elif I2S0_MCLK_PIN_SEL == 3
#define I2S0_MCLK_GPIO       digitalIO_PTC4
#define I2S0_MCLK_FN         5
#elif I2S0_MCLK_PIN_SEL == 4
#define I2S0_MCLK_GPIO       digitalIO_PTA17
#define I2S0_MCLK_FN         6
#elif I2S0_MCLK_PIN_SEL == 5
#define I2S0_MCLK_GPIO       digitalIO_PTC6
#define I2S0_MCLK_FN         6
#endif

// Pin Mapping for I2S0_RX_FS signal
//   <o> I2S0_RX_FS [PTC7, PTC10, PTA16]<name=I2S0_RX_FS_PIN_SEL>
//   <i> Shows which pin I2S0_RX_FS is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,I2S0_RX_FS>
//     <2=> PTC10<selection=PTC10_SIG_SEL,I2S0_RX_FS>
//     <3=> PTA16<selection=PTA16_SIG_SEL,I2S0_RX_FS>
//     <0=> Default
#define I2S0_RX_FS_PIN_SEL   0
#if I2S0_RX_FS_PIN_SEL == 1
#define I2S0_RX_FS_GPIO      digitalIO_PTC7
#define I2S0_RX_FS_FN        4
#elif I2S0_RX_FS_PIN_SEL == 2
#define I2S0_RX_FS_GPIO      digitalIO_PTC10
#define I2S0_RX_FS_FN        4
#elif I2S0_RX_FS_PIN_SEL == 3
#define I2S0_RX_FS_GPIO      digitalIO_PTA16
#define I2S0_RX_FS_FN        6
#endif

// Pin Mapping for I2S0_TX_BCLK signal
//   <o> I2S0_TX_BCLK [PTB18, PTA5, PTC3]<name=I2S0_TX_BCLK_PIN_SEL>
//   <i> Shows which pin I2S0_TX_BCLK is mapped to
//     <0=> Disabled
//     <1=> PTB18<selection=PTB18_SIG_SEL,I2S0_TX_BCLK>
//     <2=> PTA5 (Alias:D5)<selection=PTA5_SIG_SEL,I2S0_TX_BCLK>
//     <3=> PTC3<selection=PTC3_SIG_SEL,I2S0_TX_BCLK>
//     <0=> Default
#define I2S0_TX_BCLK_PIN_SEL 0
#if I2S0_TX_BCLK_PIN_SEL == 1
#define I2S0_TX_BCLK_GPIO    digitalIO_PTB18
#define I2S0_TX_BCLK_FN      4
#elif I2S0_TX_BCLK_PIN_SEL == 2
#define I2S0_TX_BCLK_GPIO    digitalIO_PTA5
#define I2S0_TX_BCLK_FN      6
#elif I2S0_TX_BCLK_PIN_SEL == 3
#define I2S0_TX_BCLK_GPIO    digitalIO_PTC3
#define I2S0_TX_BCLK_FN      6
#endif

// Pin Mapping for I2S0_TXD0 signal
//   <o> I2S0_TXD0 [PTA12, PTC0, PTC1, PTA14]<name=I2S0_TXD0_PIN_SEL>
//   <i> Shows which pin I2S0_TXD0 is mapped to
//     <0=> Disabled
//     <1=> PTA12 (Alias:D3)<selection=PTA12_SIG_SEL,I2S0_TXD0>
//     <2=> PTC0<selection=PTC0_SIG_SEL,I2S0_TXD0>
//     <3=> PTC1 (Alias:A5)<selection=PTC1_SIG_SEL,I2S0_TXD0>
//     <4=> PTA14<selection=PTA14_SIG_SEL,I2S0_TXD0>
//     <0=> Default
#define I2S0_TXD0_PIN_SEL    0
#if I2S0_TXD0_PIN_SEL == 1
#define I2S0_TXD0_GPIO       digitalIO_PTA12
#define I2S0_TXD0_FN         6
#elif I2S0_TXD0_PIN_SEL == 2
#define I2S0_TXD0_GPIO       digitalIO_PTC0
#define I2S0_TXD0_FN         6
#elif I2S0_TXD0_PIN_SEL == 3
#define I2S0_TXD0_GPIO       digitalIO_PTC1
#define I2S0_TXD0_FN         6
#elif I2S0_TXD0_PIN_SEL == 4
#define I2S0_TXD0_GPIO       digitalIO_PTA14
#define I2S0_TXD0_FN         7
#endif

// Pin Mapping for I2S0_RX_BCLK signal
//   <o> I2S0_RX_BCLK [PTC6, PTC9, PTA14]<name=I2S0_RX_BCLK_PIN_SEL>
//   <i> Shows which pin I2S0_RX_BCLK is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,I2S0_RX_BCLK>
//     <2=> PTC9 (Alias:D7)<selection=PTC9_SIG_SEL,I2S0_RX_BCLK>
//     <3=> PTA14<selection=PTA14_SIG_SEL,I2S0_RX_BCLK>
//     <0=> Default
#define I2S0_RX_BCLK_PIN_SEL 0
#if I2S0_RX_BCLK_PIN_SEL == 1
#define I2S0_RX_BCLK_GPIO    digitalIO_PTC6
#define I2S0_RX_BCLK_FN      4
#elif I2S0_RX_BCLK_PIN_SEL == 2
#define I2S0_RX_BCLK_GPIO    digitalIO_PTC9
#define I2S0_RX_BCLK_FN      4
#elif I2S0_RX_BCLK_PIN_SEL == 3
#define I2S0_RX_BCLK_GPIO    digitalIO_PTA14
#define I2S0_RX_BCLK_FN      6
#endif

// Pin Mapping for I2S0_TX_FS signal
//   <o> I2S0_TX_FS [PTB19, PTA13, PTC2]<name=I2S0_TX_FS_PIN_SEL>
//   <i> Shows which pin I2S0_TX_FS is mapped to
//     <0=> Disabled
//     <1=> PTB19<selection=PTB19_SIG_SEL,I2S0_TX_FS>
//     <2=> PTA13 (Alias:D8)<selection=PTA13_SIG_SEL,I2S0_TX_FS>
//     <3=> PTC2 (Alias:A4)<selection=PTC2_SIG_SEL,I2S0_TX_FS>
//     <0=> Default
#define I2S0_TX_FS_PIN_SEL   0
#if I2S0_TX_FS_PIN_SEL == 1
#define I2S0_TX_FS_GPIO      digitalIO_PTB19
#define I2S0_TX_FS_FN        4
#elif I2S0_TX_FS_PIN_SEL == 2
#define I2S0_TX_FS_GPIO      digitalIO_PTA13
#define I2S0_TX_FS_FN        6
#elif I2S0_TX_FS_PIN_SEL == 3
#define I2S0_TX_FS_GPIO      digitalIO_PTC2
#define I2S0_TX_FS_FN        6
#endif

// Pin Mapping for I2S0_RXD0 signal
//   <o> I2S0_RXD0 [PTC5, PTC11, PTA15, PTA16]<name=I2S0_RXD0_PIN_SEL>
//   <i> Shows which pin I2S0_RXD0 is mapped to
//     <0=> Disabled
//     <1=> PTC5 (Alias:ACC_INT1)<selection=PTC5_SIG_SEL,I2S0_RXD0>
//     <2=> PTC11<selection=PTC11_SIG_SEL,I2S0_RXD0>
//     <3=> PTA15<selection=PTA15_SIG_SEL,I2S0_RXD0>
//     <4=> PTA16<selection=PTA16_SIG_SEL,I2S0_RXD0>
//     <0=> Default
#define I2S0_RXD0_PIN_SEL    0
#if I2S0_RXD0_PIN_SEL == 1
#define I2S0_RXD0_GPIO       digitalIO_PTC5
#define I2S0_RXD0_FN         4
#elif I2S0_RXD0_PIN_SEL == 2
#define I2S0_RXD0_GPIO       digitalIO_PTC11
#define I2S0_RXD0_FN         4
#elif I2S0_RXD0_PIN_SEL == 3
#define I2S0_RXD0_GPIO       digitalIO_PTA15
#define I2S0_RXD0_FN         6
#elif I2S0_RXD0_PIN_SEL == 4
#define I2S0_RXD0_GPIO       digitalIO_PTA16
#define I2S0_RXD0_FN         7
#endif

// </h>

// <h> Liquid Crystal Display

// Pin Mapping for LCD_P0 signal
//   <o> LCD_P0 [PTB0]<name=LCD_P0_PIN_SEL>
//   <i> Shows which pin LCD_P0 is mapped to
//     <0=> Disabled
//     <1=> PTB0 (Alias:A0) (reset default)<selection=PTB0_SIG_SEL,LCD_P0/ADC0_SE8/TSI0_CH0 (reset default)>
//     <2=> PTB0 (Alias:A0)<selection=PTB0_SIG_SEL,LCD_P0/ADC0_SE8/TSI0_CH0>
//     <2=> Default
#define LCD_P0_PIN_SEL       2
#if LCD_P0_PIN_SEL == 2
#define LCD_P0_GPIO          digitalIO_PTB0
#define LCD_P0_FN            0
#endif

// Pin Mapping for LCD_P0_fault signal
//   <o> LCD_P0_fault [PTB0]<name=LCD_P0_fault_PIN_SEL>
//   <i> Shows which pin LCD_P0_fault is mapped to
//     <0=> Disabled
//     <1=> PTB0 (Alias:A0)<selection=PTB0_SIG_SEL,LCD_P0_fault>
//     <0=> Default
#define LCD_P0_fault_PIN_SEL 0
#if LCD_P0_fault_PIN_SEL == 1
#define LCD_P0_fault_GPIO    digitalIO_PTB0
#define LCD_P0_fault_FN      7
#endif

// Pin Mapping for LCD_P1 signal
//   <o> LCD_P1 [PTB1]<name=LCD_P1_PIN_SEL>
//   <i> Shows which pin LCD_P1 is mapped to
//     <0=> Disabled
//     <1=> PTB1 (Alias:A1) (reset default)<selection=PTB1_SIG_SEL,LCD_P1/ADC0_SE9/TSI0_CH6 (reset default)>
//     <2=> PTB1 (Alias:A1)<selection=PTB1_SIG_SEL,LCD_P1/ADC0_SE9/TSI0_CH6>
//     <2=> Default
#define LCD_P1_PIN_SEL       2
#if LCD_P1_PIN_SEL == 2
#define LCD_P1_GPIO          digitalIO_PTB1
#define LCD_P1_FN            0
#endif

// Pin Mapping for LCD_P1_fault signal
//   <o> LCD_P1_fault [PTB1]<name=LCD_P1_fault_PIN_SEL>
//   <i> Shows which pin LCD_P1_fault is mapped to
//     <0=> Disabled
//     <1=> PTB1 (Alias:A1)<selection=PTB1_SIG_SEL,LCD_P1_fault>
//     <0=> Default
#define LCD_P1_fault_PIN_SEL 0
#if LCD_P1_fault_PIN_SEL == 1
#define LCD_P1_fault_GPIO    digitalIO_PTB1
#define LCD_P1_fault_FN      7
#endif

// Pin Mapping for LCD_P2 signal
//   <o> LCD_P2 [PTB2]<name=LCD_P2_PIN_SEL>
//   <i> Shows which pin LCD_P2 is mapped to
//     <0=> Disabled
//     <1=> PTB2 (Alias:A2) (reset default)<selection=PTB2_SIG_SEL,LCD_P2/ADC0_SE12/TSI0_CH7 (reset default)>
//     <2=> PTB2 (Alias:A2)<selection=PTB2_SIG_SEL,LCD_P2/ADC0_SE12/TSI0_CH7>
//     <2=> Default
#define LCD_P2_PIN_SEL       2
#if LCD_P2_PIN_SEL == 2
#define LCD_P2_GPIO          digitalIO_PTB2
#define LCD_P2_FN            0
#endif

// Pin Mapping for LCD_P2_fault signal
//   <o> LCD_P2_fault [PTB2]<name=LCD_P2_fault_PIN_SEL>
//   <i> Shows which pin LCD_P2_fault is mapped to
//     <0=> Disabled
//     <1=> PTB2 (Alias:A2)<selection=PTB2_SIG_SEL,LCD_P2_fault>
//     <0=> Default
#define LCD_P2_fault_PIN_SEL 0
#if LCD_P2_fault_PIN_SEL == 1
#define LCD_P2_fault_GPIO    digitalIO_PTB2
#define LCD_P2_fault_FN      7
#endif

// Pin Mapping for LCD_P3 signal
//   <o> LCD_P3 [PTB3]<name=LCD_P3_PIN_SEL>
//   <i> Shows which pin LCD_P3 is mapped to
//     <0=> Disabled
//     <1=> PTB3 (Alias:A3) (reset default)<selection=PTB3_SIG_SEL,LCD_P3/ADC0_SE13/TSI0_CH8 (reset default)>
//     <2=> PTB3 (Alias:A3)<selection=PTB3_SIG_SEL,LCD_P3/ADC0_SE13/TSI0_CH8>
//     <2=> Default
#define LCD_P3_PIN_SEL       2
#if LCD_P3_PIN_SEL == 2
#define LCD_P3_GPIO          digitalIO_PTB3
#define LCD_P3_FN            0
#endif

// Pin Mapping for LCD_P3_fault signal
//   <o> LCD_P3_fault [PTB3]<name=LCD_P3_fault_PIN_SEL>
//   <i> Shows which pin LCD_P3_fault is mapped to
//     <0=> Disabled
//     <1=> PTB3 (Alias:A3)<selection=PTB3_SIG_SEL,LCD_P3_fault>
//     <0=> Default
#define LCD_P3_fault_PIN_SEL 0
#if LCD_P3_fault_PIN_SEL == 1
#define LCD_P3_fault_GPIO    digitalIO_PTB3
#define LCD_P3_fault_FN      7
#endif

// Pin Mapping for LCD_P7 signal
//   <o> LCD_P7 [PTB7]<name=LCD_P7_PIN_SEL>
//   <i> Shows which pin LCD_P7 is mapped to
//     <0=> Disabled
//     <1=> PTB7 (reset default)<selection=PTB7_SIG_SEL,LCD_P7 (reset default)>
//     <2=> PTB7<selection=PTB7_SIG_SEL,LCD_P7>
//     <1=> Default
#define LCD_P7_PIN_SEL       1
#if LCD_P7_PIN_SEL == 2
#define LCD_P7_GPIO          digitalIO_PTB7
#define LCD_P7_FN            0
#endif

// Pin Mapping for LCD_P7_fault signal
//   <o> LCD_P7_fault [PTB7]<name=LCD_P7_fault_PIN_SEL>
//   <i> Shows which pin LCD_P7_fault is mapped to
//     <0=> Disabled
//     <1=> PTB7<selection=PTB7_SIG_SEL,LCD_P7_fault>
//     <0=> Default
#define LCD_P7_fault_PIN_SEL 0
#if LCD_P7_fault_PIN_SEL == 1
#define LCD_P7_fault_GPIO    digitalIO_PTB7
#define LCD_P7_fault_FN      7
#endif

// Pin Mapping for LCD_P8 signal
//   <o> LCD_P8 [PTB8]<name=LCD_P8_PIN_SEL>
//   <i> Shows which pin LCD_P8 is mapped to
//     <0=> Disabled
//     <1=> PTB8 (reset default)<selection=PTB8_SIG_SEL,LCD_P8 (reset default)>
//     <2=> PTB8<selection=PTB8_SIG_SEL,LCD_P8>
//     <1=> Default
#define LCD_P8_PIN_SEL       1
#if LCD_P8_PIN_SEL == 2
#define LCD_P8_GPIO          digitalIO_PTB8
#define LCD_P8_FN            0
#endif

// Pin Mapping for LCD_P8_fault signal
//   <o> LCD_P8_fault [PTB8]<name=LCD_P8_fault_PIN_SEL>
//   <i> Shows which pin LCD_P8_fault is mapped to
//     <0=> Disabled
//     <1=> PTB8<selection=PTB8_SIG_SEL,LCD_P8_fault>
//     <0=> Default
#define LCD_P8_fault_PIN_SEL 0
#if LCD_P8_fault_PIN_SEL == 1
#define LCD_P8_fault_GPIO    digitalIO_PTB8
#define LCD_P8_fault_FN      7
#endif

// Pin Mapping for LCD_P9 signal
//   <o> LCD_P9 [PTB9]<name=LCD_P9_PIN_SEL>
//   <i> Shows which pin LCD_P9 is mapped to
//     <0=> Disabled
//     <1=> PTB9 (reset default)<selection=PTB9_SIG_SEL,LCD_P9 (reset default)>
//     <2=> PTB9<selection=PTB9_SIG_SEL,LCD_P9>
//     <1=> Default
#define LCD_P9_PIN_SEL       1
#if LCD_P9_PIN_SEL == 2
#define LCD_P9_GPIO          digitalIO_PTB9
#define LCD_P9_FN            0
#endif

// Pin Mapping for LCD_P9_fault signal
//   <o> LCD_P9_fault [PTB9]<name=LCD_P9_fault_PIN_SEL>
//   <i> Shows which pin LCD_P9_fault is mapped to
//     <0=> Disabled
//     <1=> PTB9<selection=PTB9_SIG_SEL,LCD_P9_fault>
//     <0=> Default
#define LCD_P9_fault_PIN_SEL 0
#if LCD_P9_fault_PIN_SEL == 1
#define LCD_P9_fault_GPIO    digitalIO_PTB9
#define LCD_P9_fault_FN      7
#endif

// Pin Mapping for LCD_P10 signal
//   <o> LCD_P10 [PTB10]<name=LCD_P10_PIN_SEL>
//   <i> Shows which pin LCD_P10 is mapped to
//     <0=> Disabled
//     <1=> PTB10 (reset default)<selection=PTB10_SIG_SEL,LCD_P10 (reset default)>
//     <2=> PTB10<selection=PTB10_SIG_SEL,LCD_P10>
//     <1=> Default
#define LCD_P10_PIN_SEL      1
#if LCD_P10_PIN_SEL == 2
#define LCD_P10_GPIO         digitalIO_PTB10
#define LCD_P10_FN           0
#endif

// Pin Mapping for LCD_P10_fault signal
//   <o> LCD_P10_fault [PTB10]<name=LCD_P10_fault_PIN_SEL>
//   <i> Shows which pin LCD_P10_fault is mapped to
//     <0=> Disabled
//     <1=> PTB10<selection=PTB10_SIG_SEL,LCD_P10_fault>
//     <0=> Default
#define LCD_P10_fault_PIN_SEL 0
#if LCD_P10_fault_PIN_SEL == 1
#define LCD_P10_fault_GPIO   digitalIO_PTB10
#define LCD_P10_fault_FN     7
#endif

// Pin Mapping for LCD_P11 signal
//   <o> LCD_P11 [PTB11]<name=LCD_P11_PIN_SEL>
//   <i> Shows which pin LCD_P11 is mapped to
//     <0=> Disabled
//     <1=> PTB11 (reset default)<selection=PTB11_SIG_SEL,LCD_P11 (reset default)>
//     <2=> PTB11<selection=PTB11_SIG_SEL,LCD_P11>
//     <1=> Default
#define LCD_P11_PIN_SEL      1
#if LCD_P11_PIN_SEL == 2
#define LCD_P11_GPIO         digitalIO_PTB11
#define LCD_P11_FN           0
#endif

// Pin Mapping for LCD_P11_fault signal
//   <o> LCD_P11_fault [PTB11]<name=LCD_P11_fault_PIN_SEL>
//   <i> Shows which pin LCD_P11_fault is mapped to
//     <0=> Disabled
//     <1=> PTB11<selection=PTB11_SIG_SEL,LCD_P11_fault>
//     <0=> Default
#define LCD_P11_fault_PIN_SEL 0
#if LCD_P11_fault_PIN_SEL == 1
#define LCD_P11_fault_GPIO   digitalIO_PTB11
#define LCD_P11_fault_FN     7
#endif

// Pin Mapping for LCD_P12 signal
//   <o> LCD_P12 [PTB16]<name=LCD_P12_PIN_SEL>
//   <i> Shows which pin LCD_P12 is mapped to
//     <0=> Disabled
//     <1=> PTB16 (reset default)<selection=PTB16_SIG_SEL,LCD_P12/TSI0_CH9 (reset default)>
//     <2=> PTB16<selection=PTB16_SIG_SEL,LCD_P12/TSI0_CH9>
//     <1=> Default
#define LCD_P12_PIN_SEL      1
#if LCD_P12_PIN_SEL == 2
#define LCD_P12_GPIO         digitalIO_PTB16
#define LCD_P12_FN           0
#endif

// Pin Mapping for LCD_P12_fault signal
//   <o> LCD_P12_fault [PTB16]<name=LCD_P12_fault_PIN_SEL>
//   <i> Shows which pin LCD_P12_fault is mapped to
//     <0=> Disabled
//     <1=> PTB16<selection=PTB16_SIG_SEL,LCD_P12_fault>
//     <0=> Default
#define LCD_P12_fault_PIN_SEL 0
#if LCD_P12_fault_PIN_SEL == 1
#define LCD_P12_fault_GPIO   digitalIO_PTB16
#define LCD_P12_fault_FN     7
#endif

// Pin Mapping for LCD_P13 signal
//   <o> LCD_P13 [PTB17]<name=LCD_P13_PIN_SEL>
//   <i> Shows which pin LCD_P13 is mapped to
//     <0=> Disabled
//     <1=> PTB17 (reset default)<selection=PTB17_SIG_SEL,LCD_P13/TSI0_CH10 (reset default)>
//     <2=> PTB17<selection=PTB17_SIG_SEL,LCD_P13/TSI0_CH10>
//     <1=> Default
#define LCD_P13_PIN_SEL      1
#if LCD_P13_PIN_SEL == 2
#define LCD_P13_GPIO         digitalIO_PTB17
#define LCD_P13_FN           0
#endif

// Pin Mapping for LCD_P13_fault signal
//   <o> LCD_P13_fault [PTB17]<name=LCD_P13_fault_PIN_SEL>
//   <i> Shows which pin LCD_P13_fault is mapped to
//     <0=> Disabled
//     <1=> PTB17<selection=PTB17_SIG_SEL,LCD_P13_fault>
//     <0=> Default
#define LCD_P13_fault_PIN_SEL 0
#if LCD_P13_fault_PIN_SEL == 1
#define LCD_P13_fault_GPIO   digitalIO_PTB17
#define LCD_P13_fault_FN     7
#endif

// Pin Mapping for LCD_P14 signal
//   <o> LCD_P14 [PTB18]<name=LCD_P14_PIN_SEL>
//   <i> Shows which pin LCD_P14 is mapped to
//     <0=> Disabled
//     <1=> PTB18 (reset default)<selection=PTB18_SIG_SEL,LCD_P14/TSI0_CH11 (reset default)>
//     <2=> PTB18<selection=PTB18_SIG_SEL,LCD_P14/TSI0_CH11>
//     <1=> Default
#define LCD_P14_PIN_SEL      1
#if LCD_P14_PIN_SEL == 2
#define LCD_P14_GPIO         digitalIO_PTB18
#define LCD_P14_FN           0
#endif

// Pin Mapping for LCD_P14_fault signal
//   <o> LCD_P14_fault [PTB18]<name=LCD_P14_fault_PIN_SEL>
//   <i> Shows which pin LCD_P14_fault is mapped to
//     <0=> Disabled
//     <1=> PTB18<selection=PTB18_SIG_SEL,LCD_P14_fault>
//     <0=> Default
#define LCD_P14_fault_PIN_SEL 0
#if LCD_P14_fault_PIN_SEL == 1
#define LCD_P14_fault_GPIO   digitalIO_PTB18
#define LCD_P14_fault_FN     7
#endif

// Pin Mapping for LCD_P15 signal
//   <o> LCD_P15 [PTB19]<name=LCD_P15_PIN_SEL>
//   <i> Shows which pin LCD_P15 is mapped to
//     <0=> Disabled
//     <1=> PTB19 (reset default)<selection=PTB19_SIG_SEL,LCD_P15/TSI0_CH12 (reset default)>
//     <2=> PTB19<selection=PTB19_SIG_SEL,LCD_P15/TSI0_CH12>
//     <1=> Default
#define LCD_P15_PIN_SEL      1
#if LCD_P15_PIN_SEL == 2
#define LCD_P15_GPIO         digitalIO_PTB19
#define LCD_P15_FN           0
#endif

// Pin Mapping for LCD_P15_fault signal
//   <o> LCD_P15_fault [PTB19]<name=LCD_P15_fault_PIN_SEL>
//   <i> Shows which pin LCD_P15_fault is mapped to
//     <0=> Disabled
//     <1=> PTB19<selection=PTB19_SIG_SEL,LCD_P15_fault>
//     <0=> Default
#define LCD_P15_fault_PIN_SEL 0
#if LCD_P15_fault_PIN_SEL == 1
#define LCD_P15_fault_GPIO   digitalIO_PTB19
#define LCD_P15_fault_FN     7
#endif

// Pin Mapping for LCD_P16 signal
//   <o> LCD_P16 [PTB20]<name=LCD_P16_PIN_SEL>
//   <i> Shows which pin LCD_P16 is mapped to
//     <0=> Disabled
//     <1=> PTB20 (reset default)<selection=PTB20_SIG_SEL,LCD_P16 (reset default)>
//     <2=> PTB20<selection=PTB20_SIG_SEL,LCD_P16>
//     <1=> Default
#define LCD_P16_PIN_SEL      1
#if LCD_P16_PIN_SEL == 2
#define LCD_P16_GPIO         digitalIO_PTB20
#define LCD_P16_FN           0
#endif

// Pin Mapping for LCD_P16_fault signal
//   <o> LCD_P16_fault [PTB20]<name=LCD_P16_fault_PIN_SEL>
//   <i> Shows which pin LCD_P16_fault is mapped to
//     <0=> Disabled
//     <1=> PTB20<selection=PTB20_SIG_SEL,LCD_P16_fault>
//     <0=> Default
#define LCD_P16_fault_PIN_SEL 0
#if LCD_P16_fault_PIN_SEL == 1
#define LCD_P16_fault_GPIO   digitalIO_PTB20
#define LCD_P16_fault_FN     7
#endif

// Pin Mapping for LCD_P17 signal
//   <o> LCD_P17 [PTB21]<name=LCD_P17_PIN_SEL>
//   <i> Shows which pin LCD_P17 is mapped to
//     <0=> Disabled
//     <1=> PTB21 (reset default)<selection=PTB21_SIG_SEL,LCD_P17 (reset default)>
//     <2=> PTB21<selection=PTB21_SIG_SEL,LCD_P17>
//     <1=> Default
#define LCD_P17_PIN_SEL      1
#if LCD_P17_PIN_SEL == 2
#define LCD_P17_GPIO         digitalIO_PTB21
#define LCD_P17_FN           0
#endif

// Pin Mapping for LCD_P17_fault signal
//   <o> LCD_P17_fault [PTB21]<name=LCD_P17_fault_PIN_SEL>
//   <i> Shows which pin LCD_P17_fault is mapped to
//     <0=> Disabled
//     <1=> PTB21<selection=PTB21_SIG_SEL,LCD_P17_fault>
//     <0=> Default
#define LCD_P17_fault_PIN_SEL 0
#if LCD_P17_fault_PIN_SEL == 1
#define LCD_P17_fault_GPIO   digitalIO_PTB21
#define LCD_P17_fault_FN     7
#endif

// Pin Mapping for LCD_P18 signal
//   <o> LCD_P18 [PTB22]<name=LCD_P18_PIN_SEL>
//   <i> Shows which pin LCD_P18 is mapped to
//     <0=> Disabled
//     <1=> PTB22 (reset default)<selection=PTB22_SIG_SEL,LCD_P18 (reset default)>
//     <2=> PTB22<selection=PTB22_SIG_SEL,LCD_P18>
//     <1=> Default
#define LCD_P18_PIN_SEL      1
#if LCD_P18_PIN_SEL == 2
#define LCD_P18_GPIO         digitalIO_PTB22
#define LCD_P18_FN           0
#endif

// Pin Mapping for LCD_P18_fault signal
//   <o> LCD_P18_fault [PTB22]<name=LCD_P18_fault_PIN_SEL>
//   <i> Shows which pin LCD_P18_fault is mapped to
//     <0=> Disabled
//     <1=> PTB22<selection=PTB22_SIG_SEL,LCD_P18_fault>
//     <0=> Default
#define LCD_P18_fault_PIN_SEL 0
#if LCD_P18_fault_PIN_SEL == 1
#define LCD_P18_fault_GPIO   digitalIO_PTB22
#define LCD_P18_fault_FN     7
#endif

// Pin Mapping for LCD_P19 signal
//   <o> LCD_P19 [PTB23]<name=LCD_P19_PIN_SEL>
//   <i> Shows which pin LCD_P19 is mapped to
//     <0=> Disabled
//     <1=> PTB23 (reset default)<selection=PTB23_SIG_SEL,LCD_P19 (reset default)>
//     <2=> PTB23<selection=PTB23_SIG_SEL,LCD_P19>
//     <1=> Default
#define LCD_P19_PIN_SEL      1
#if LCD_P19_PIN_SEL == 2
#define LCD_P19_GPIO         digitalIO_PTB23
#define LCD_P19_FN           0
#endif

// Pin Mapping for LCD_P19_fault signal
//   <o> LCD_P19_fault [PTB23]<name=LCD_P19_fault_PIN_SEL>
//   <i> Shows which pin LCD_P19_fault is mapped to
//     <0=> Disabled
//     <1=> PTB23<selection=PTB23_SIG_SEL,LCD_P19_fault>
//     <0=> Default
#define LCD_P19_fault_PIN_SEL 0
#if LCD_P19_fault_PIN_SEL == 1
#define LCD_P19_fault_GPIO   digitalIO_PTB23
#define LCD_P19_fault_FN     7
#endif

// Pin Mapping for LCD_P20 signal
//   <o> LCD_P20 [PTC0]<name=LCD_P20_PIN_SEL>
//   <i> Shows which pin LCD_P20 is mapped to
//     <0=> Disabled
//     <1=> PTC0 (reset default)<selection=PTC0_SIG_SEL,LCD_P20/ADC0_SE14/TSI0_CH13 (reset default)>
//     <2=> PTC0<selection=PTC0_SIG_SEL,LCD_P20/ADC0_SE14/TSI0_CH13>
//     <1=> Default
#define LCD_P20_PIN_SEL      1
#if LCD_P20_PIN_SEL == 2
#define LCD_P20_GPIO         digitalIO_PTC0
#define LCD_P20_FN           0
#endif

// Pin Mapping for LCD_P20_fault signal
//   <o> LCD_P20_fault [PTC0]<name=LCD_P20_fault_PIN_SEL>
//   <i> Shows which pin LCD_P20_fault is mapped to
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,LCD_P20_fault>
//     <0=> Default
#define LCD_P20_fault_PIN_SEL 0
#if LCD_P20_fault_PIN_SEL == 1
#define LCD_P20_fault_GPIO   digitalIO_PTC0
#define LCD_P20_fault_FN     7
#endif

// Pin Mapping for LCD_P21 signal
//   <o> LCD_P21 [PTC1]<name=LCD_P21_PIN_SEL>
//   <i> Shows which pin LCD_P21 is mapped to
//     <0=> Disabled
//     <1=> PTC1 (Alias:A5) (reset default)<selection=PTC1_SIG_SEL,LCD_P21/ADC0_SE15/TSI0_CH14 (reset default)>
//     <2=> PTC1 (Alias:A5)<selection=PTC1_SIG_SEL,LCD_P21/ADC0_SE15/TSI0_CH14>
//     <2=> Default
#define LCD_P21_PIN_SEL      2
#if LCD_P21_PIN_SEL == 2
#define LCD_P21_GPIO         digitalIO_PTC1
#define LCD_P21_FN           0
#endif

// Pin Mapping for LCD_P21_fault signal
//   <o> LCD_P21_fault [PTC1]<name=LCD_P21_fault_PIN_SEL>
//   <i> Shows which pin LCD_P21_fault is mapped to
//     <0=> Disabled
//     <1=> PTC1 (Alias:A5)<selection=PTC1_SIG_SEL,LCD_P21_fault>
//     <0=> Default
#define LCD_P21_fault_PIN_SEL 0
#if LCD_P21_fault_PIN_SEL == 1
#define LCD_P21_fault_GPIO   digitalIO_PTC1
#define LCD_P21_fault_FN     7
#endif

// Pin Mapping for LCD_P22 signal
//   <o> LCD_P22 [PTC2]<name=LCD_P22_PIN_SEL>
//   <i> Shows which pin LCD_P22 is mapped to
//     <0=> Disabled
//     <1=> PTC2 (Alias:A4) (reset default)<selection=PTC2_SIG_SEL,LCD_P22/ADC0_SE11/TSI0_CH15 (reset default)>
//     <2=> PTC2 (Alias:A4)<selection=PTC2_SIG_SEL,LCD_P22/ADC0_SE11/TSI0_CH15>
//     <2=> Default
#define LCD_P22_PIN_SEL      2
#if LCD_P22_PIN_SEL == 2
#define LCD_P22_GPIO         digitalIO_PTC2
#define LCD_P22_FN           0
#endif

// Pin Mapping for LCD_P22_fault signal
//   <o> LCD_P22_fault [PTC2]<name=LCD_P22_fault_PIN_SEL>
//   <i> Shows which pin LCD_P22_fault is mapped to
//     <0=> Disabled
//     <1=> PTC2 (Alias:A4)<selection=PTC2_SIG_SEL,LCD_P22_fault>
//     <0=> Default
#define LCD_P22_fault_PIN_SEL 0
#if LCD_P22_fault_PIN_SEL == 1
#define LCD_P22_fault_GPIO   digitalIO_PTC2
#define LCD_P22_fault_FN     7
#endif

// Pin Mapping for LCD_P23 signal
//   <o> LCD_P23 [PTC3]<name=LCD_P23_PIN_SEL>
//   <i> Shows which pin LCD_P23 is mapped to
//     <0=> Disabled
//     <1=> PTC3 (reset default)<selection=PTC3_SIG_SEL,LCD_P23 (reset default)>
//     <2=> PTC3<selection=PTC3_SIG_SEL,LCD_P23>
//     <1=> Default
#define LCD_P23_PIN_SEL      1
#if LCD_P23_PIN_SEL == 2
#define LCD_P23_GPIO         digitalIO_PTC3
#define LCD_P23_FN           0
#endif

// Pin Mapping for LCD_P23_fault signal
//   <o> LCD_P23_fault [PTC3]<name=LCD_P23_fault_PIN_SEL>
//   <i> Shows which pin LCD_P23_fault is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,LCD_P23_fault>
//     <0=> Default
#define LCD_P23_fault_PIN_SEL 0
#if LCD_P23_fault_PIN_SEL == 1
#define LCD_P23_fault_GPIO   digitalIO_PTC3
#define LCD_P23_fault_FN     7
#endif

// Pin Mapping for LCD_P24 signal
//   <o> LCD_P24 [PTC4]<name=LCD_P24_PIN_SEL>
//   <i> Shows which pin LCD_P24 is mapped to
//     <0=> Disabled
//     <1=> PTC4 (reset default)<selection=PTC4_SIG_SEL,LCD_P24 (reset default)>
//     <2=> PTC4<selection=PTC4_SIG_SEL,LCD_P24>
//     <1=> Default
#define LCD_P24_PIN_SEL      1
#if LCD_P24_PIN_SEL == 2
#define LCD_P24_GPIO         digitalIO_PTC4
#define LCD_P24_FN           0
#endif

// Pin Mapping for LCD_P24_fault signal
//   <o> LCD_P24_fault [PTC4]<name=LCD_P24_fault_PIN_SEL>
//   <i> Shows which pin LCD_P24_fault is mapped to
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,LCD_P24_fault>
//     <0=> Default
#define LCD_P24_fault_PIN_SEL 0
#if LCD_P24_fault_PIN_SEL == 1
#define LCD_P24_fault_GPIO   digitalIO_PTC4
#define LCD_P24_fault_FN     7
#endif

// Pin Mapping for LCD_P25 signal
//   <o> LCD_P25 [PTC5]<name=LCD_P25_PIN_SEL>
//   <i> Shows which pin LCD_P25 is mapped to
//     <0=> Disabled
//     <1=> PTC5 (Alias:ACC_INT1) (reset default)<selection=PTC5_SIG_SEL,LCD_P25 (reset default)>
//     <2=> PTC5 (Alias:ACC_INT1)<selection=PTC5_SIG_SEL,LCD_P25>
//     <0=> Default
#define LCD_P25_PIN_SEL      0
#if LCD_P25_PIN_SEL == 2
#define LCD_P25_GPIO         digitalIO_PTC5
#define LCD_P25_FN           0
#endif

// Pin Mapping for LCD_P25_fault signal
//   <o> LCD_P25_fault [PTC5]<name=LCD_P25_fault_PIN_SEL>
//   <i> Shows which pin LCD_P25_fault is mapped to
//     <0=> Disabled
//     <1=> PTC5 (Alias:ACC_INT1)<selection=PTC5_SIG_SEL,LCD_P25_fault>
//     <0=> Default
#define LCD_P25_fault_PIN_SEL 0
#if LCD_P25_fault_PIN_SEL == 1
#define LCD_P25_fault_GPIO   digitalIO_PTC5
#define LCD_P25_fault_FN     7
#endif

// Pin Mapping for LCD_P26 signal
//   <o> LCD_P26 [PTC6]<name=LCD_P26_PIN_SEL>
//   <i> Shows which pin LCD_P26 is mapped to
//     <0=> Disabled
//     <1=> PTC6 (reset default)<selection=PTC6_SIG_SEL,LCD_P26/CMP0_IN0 (reset default)>
//     <2=> PTC6<selection=PTC6_SIG_SEL,LCD_P26/CMP0_IN0>
//     <1=> Default
#define LCD_P26_PIN_SEL      1
#if LCD_P26_PIN_SEL == 2
#define LCD_P26_GPIO         digitalIO_PTC6
#define LCD_P26_FN           0
#endif

// Pin Mapping for LCD_P26_fault signal
//   <o> LCD_P26_fault [PTC6]<name=LCD_P26_fault_PIN_SEL>
//   <i> Shows which pin LCD_P26_fault is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,LCD_P26_fault>
//     <0=> Default
#define LCD_P26_fault_PIN_SEL 0
#if LCD_P26_fault_PIN_SEL == 1
#define LCD_P26_fault_GPIO   digitalIO_PTC6
#define LCD_P26_fault_FN     7
#endif

// Pin Mapping for LCD_P27 signal
//   <o> LCD_P27 [PTC7]<name=LCD_P27_PIN_SEL>
//   <i> Shows which pin LCD_P27 is mapped to
//     <0=> Disabled
//     <1=> PTC7 (reset default)<selection=PTC7_SIG_SEL,LCD_P27/CMP0_IN1 (reset default)>
//     <2=> PTC7<selection=PTC7_SIG_SEL,LCD_P27/CMP0_IN1>
//     <1=> Default
#define LCD_P27_PIN_SEL      1
#if LCD_P27_PIN_SEL == 2
#define LCD_P27_GPIO         digitalIO_PTC7
#define LCD_P27_FN           0
#endif

// Pin Mapping for LCD_P27_fault signal
//   <o> LCD_P27_fault [PTC7]<name=LCD_P27_fault_PIN_SEL>
//   <i> Shows which pin LCD_P27_fault is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,LCD_P27_fault>
//     <0=> Default
#define LCD_P27_fault_PIN_SEL 0
#if LCD_P27_fault_PIN_SEL == 1
#define LCD_P27_fault_GPIO   digitalIO_PTC7
#define LCD_P27_fault_FN     7
#endif

// Pin Mapping for LCD_P28 signal
//   <o> LCD_P28 [PTC8]<name=LCD_P28_PIN_SEL>
//   <i> Shows which pin LCD_P28 is mapped to
//     <0=> Disabled
//     <1=> PTC8 (Alias:D6) (reset default)<selection=PTC8_SIG_SEL,LCD_P28/CMP0_IN2 (reset default)>
//     <2=> PTC8 (Alias:D6)<selection=PTC8_SIG_SEL,LCD_P28/CMP0_IN2>
//     <0=> Default
#define LCD_P28_PIN_SEL      0
#if LCD_P28_PIN_SEL == 2
#define LCD_P28_GPIO         digitalIO_PTC8
#define LCD_P28_FN           0
#endif

// Pin Mapping for LCD_P28_fault signal
//   <o> LCD_P28_fault [PTC8]<name=LCD_P28_fault_PIN_SEL>
//   <i> Shows which pin LCD_P28_fault is mapped to
//     <0=> Disabled
//     <1=> PTC8 (Alias:D6)<selection=PTC8_SIG_SEL,LCD_P28_fault>
//     <0=> Default
#define LCD_P28_fault_PIN_SEL 0
#if LCD_P28_fault_PIN_SEL == 1
#define LCD_P28_fault_GPIO   digitalIO_PTC8
#define LCD_P28_fault_FN     7
#endif

// Pin Mapping for LCD_P29 signal
//   <o> LCD_P29 [PTC9]<name=LCD_P29_PIN_SEL>
//   <i> Shows which pin LCD_P29 is mapped to
//     <0=> Disabled
//     <1=> PTC9 (Alias:D7) (reset default)<selection=PTC9_SIG_SEL,LCD_P29/CMP0_IN3 (reset default)>
//     <2=> PTC9 (Alias:D7)<selection=PTC9_SIG_SEL,LCD_P29/CMP0_IN3>
//     <0=> Default
#define LCD_P29_PIN_SEL      0
#if LCD_P29_PIN_SEL == 2
#define LCD_P29_GPIO         digitalIO_PTC9
#define LCD_P29_FN           0
#endif

// Pin Mapping for LCD_P29_fault signal
//   <o> LCD_P29_fault [PTC9]<name=LCD_P29_fault_PIN_SEL>
//   <i> Shows which pin LCD_P29_fault is mapped to
//     <0=> Disabled
//     <1=> PTC9 (Alias:D7)<selection=PTC9_SIG_SEL,LCD_P29_fault>
//     <0=> Default
#define LCD_P29_fault_PIN_SEL 0
#if LCD_P29_fault_PIN_SEL == 1
#define LCD_P29_fault_GPIO   digitalIO_PTC9
#define LCD_P29_fault_FN     7
#endif

// Pin Mapping for LCD_P30 signal
//   <o> LCD_P30 [PTC10]<name=LCD_P30_PIN_SEL>
//   <i> Shows which pin LCD_P30 is mapped to
//     <0=> Disabled
//     <1=> PTC10 (reset default)<selection=PTC10_SIG_SEL,LCD_P30 (reset default)>
//     <2=> PTC10<selection=PTC10_SIG_SEL,LCD_P30>
//     <1=> Default
#define LCD_P30_PIN_SEL      1
#if LCD_P30_PIN_SEL == 2
#define LCD_P30_GPIO         digitalIO_PTC10
#define LCD_P30_FN           0
#endif

// Pin Mapping for LCD_P30_fault signal
//   <o> LCD_P30_fault [PTC10]<name=LCD_P30_fault_PIN_SEL>
//   <i> Shows which pin LCD_P30_fault is mapped to
//     <0=> Disabled
//     <1=> PTC10<selection=PTC10_SIG_SEL,LCD_P30_fault>
//     <0=> Default
#define LCD_P30_fault_PIN_SEL 0
#if LCD_P30_fault_PIN_SEL == 1
#define LCD_P30_fault_GPIO   digitalIO_PTC10
#define LCD_P30_fault_FN     7
#endif

// Pin Mapping for LCD_P31 signal
//   <o> LCD_P31 [PTC11]<name=LCD_P31_PIN_SEL>
//   <i> Shows which pin LCD_P31 is mapped to
//     <0=> Disabled
//     <1=> PTC11 (reset default)<selection=PTC11_SIG_SEL,LCD_P31 (reset default)>
//     <2=> PTC11<selection=PTC11_SIG_SEL,LCD_P31>
//     <1=> Default
#define LCD_P31_PIN_SEL      1
#if LCD_P31_PIN_SEL == 2
#define LCD_P31_GPIO         digitalIO_PTC11
#define LCD_P31_FN           0
#endif

// Pin Mapping for LCD_P31_fault signal
//   <o> LCD_P31_fault [PTC11]<name=LCD_P31_fault_PIN_SEL>
//   <i> Shows which pin LCD_P31_fault is mapped to
//     <0=> Disabled
//     <1=> PTC11<selection=PTC11_SIG_SEL,LCD_P31_fault>
//     <0=> Default
#define LCD_P31_fault_PIN_SEL 0
#if LCD_P31_fault_PIN_SEL == 1
#define LCD_P31_fault_GPIO   digitalIO_PTC11
#define LCD_P31_fault_FN     7
#endif

// Pin Mapping for LCD_P32 signal
//   <o> LCD_P32 [PTC12]<name=LCD_P32_PIN_SEL>
//   <i> Shows which pin LCD_P32 is mapped to
//     <0=> Disabled
//     <1=> PTC12 (reset default)<selection=PTC12_SIG_SEL,LCD_P32 (reset default)>
//     <2=> PTC12<selection=PTC12_SIG_SEL,LCD_P32>
//     <1=> Default
#define LCD_P32_PIN_SEL      1
#if LCD_P32_PIN_SEL == 2
#define LCD_P32_GPIO         digitalIO_PTC12
#define LCD_P32_FN           0
#endif

// Pin Mapping for LCD_P32_fault signal
//   <o> LCD_P32_fault [PTC12]<name=LCD_P32_fault_PIN_SEL>
//   <i> Shows which pin LCD_P32_fault is mapped to
//     <0=> Disabled
//     <1=> PTC12<selection=PTC12_SIG_SEL,LCD_P32_fault>
//     <0=> Default
#define LCD_P32_fault_PIN_SEL 0
#if LCD_P32_fault_PIN_SEL == 1
#define LCD_P32_fault_GPIO   digitalIO_PTC12
#define LCD_P32_fault_FN     7
#endif

// Pin Mapping for LCD_P33 signal
//   <o> LCD_P33 [PTC13]<name=LCD_P33_PIN_SEL>
//   <i> Shows which pin LCD_P33 is mapped to
//     <0=> Disabled
//     <1=> PTC13 (reset default)<selection=PTC13_SIG_SEL,LCD_P33 (reset default)>
//     <2=> PTC13<selection=PTC13_SIG_SEL,LCD_P33>
//     <1=> Default
#define LCD_P33_PIN_SEL      1
#if LCD_P33_PIN_SEL == 2
#define LCD_P33_GPIO         digitalIO_PTC13
#define LCD_P33_FN           0
#endif

// Pin Mapping for LCD_P33_fault signal
//   <o> LCD_P33_fault [PTC13]<name=LCD_P33_fault_PIN_SEL>
//   <i> Shows which pin LCD_P33_fault is mapped to
//     <0=> Disabled
//     <1=> PTC13<selection=PTC13_SIG_SEL,LCD_P33_fault>
//     <0=> Default
#define LCD_P33_fault_PIN_SEL 0
#if LCD_P33_fault_PIN_SEL == 1
#define LCD_P33_fault_GPIO   digitalIO_PTC13
#define LCD_P33_fault_FN     7
#endif

// Pin Mapping for LCD_P36 signal
//   <o> LCD_P36 [PTC16]<name=LCD_P36_PIN_SEL>
//   <i> Shows which pin LCD_P36 is mapped to
//     <0=> Disabled
//     <1=> PTC16 (reset default)<selection=PTC16_SIG_SEL,LCD_P36 (reset default)>
//     <2=> PTC16<selection=PTC16_SIG_SEL,LCD_P36>
//     <1=> Default
#define LCD_P36_PIN_SEL      1
#if LCD_P36_PIN_SEL == 2
#define LCD_P36_GPIO         digitalIO_PTC16
#define LCD_P36_FN           0
#endif

// Pin Mapping for LCD_P36_fault signal
//   <o> LCD_P36_fault [PTC16]<name=LCD_P36_fault_PIN_SEL>
//   <i> Shows which pin LCD_P36_fault is mapped to
//     <0=> Disabled
//     <1=> PTC16<selection=PTC16_SIG_SEL,LCD_P36_fault>
//     <0=> Default
#define LCD_P36_fault_PIN_SEL 0
#if LCD_P36_fault_PIN_SEL == 1
#define LCD_P36_fault_GPIO   digitalIO_PTC16
#define LCD_P36_fault_FN     7
#endif

// Pin Mapping for LCD_P37 signal
//   <o> LCD_P37 [PTC17]<name=LCD_P37_PIN_SEL>
//   <i> Shows which pin LCD_P37 is mapped to
//     <0=> Disabled
//     <1=> PTC17 (reset default)<selection=PTC17_SIG_SEL,LCD_P37 (reset default)>
//     <2=> PTC17<selection=PTC17_SIG_SEL,LCD_P37>
//     <1=> Default
#define LCD_P37_PIN_SEL      1
#if LCD_P37_PIN_SEL == 2
#define LCD_P37_GPIO         digitalIO_PTC17
#define LCD_P37_FN           0
#endif

// Pin Mapping for LCD_P37_fault signal
//   <o> LCD_P37_fault [PTC17]<name=LCD_P37_fault_PIN_SEL>
//   <i> Shows which pin LCD_P37_fault is mapped to
//     <0=> Disabled
//     <1=> PTC17<selection=PTC17_SIG_SEL,LCD_P37_fault>
//     <0=> Default
#define LCD_P37_fault_PIN_SEL 0
#if LCD_P37_fault_PIN_SEL == 1
#define LCD_P37_fault_GPIO   digitalIO_PTC17
#define LCD_P37_fault_FN     7
#endif

// Pin Mapping for LCD_P38 signal
//   <o> LCD_P38 [PTC18]<name=LCD_P38_PIN_SEL>
//   <i> Shows which pin LCD_P38 is mapped to
//     <0=> Disabled
//     <1=> PTC18 (reset default)<selection=PTC18_SIG_SEL,LCD_P38 (reset default)>
//     <2=> PTC18<selection=PTC18_SIG_SEL,LCD_P38>
//     <1=> Default
#define LCD_P38_PIN_SEL      1
#if LCD_P38_PIN_SEL == 2
#define LCD_P38_GPIO         digitalIO_PTC18
#define LCD_P38_FN           0
#endif

// Pin Mapping for LCD_P38_fault signal
//   <o> LCD_P38_fault [PTC18]<name=LCD_P38_fault_PIN_SEL>
//   <i> Shows which pin LCD_P38_fault is mapped to
//     <0=> Disabled
//     <1=> PTC18<selection=PTC18_SIG_SEL,LCD_P38_fault>
//     <0=> Default
#define LCD_P38_fault_PIN_SEL 0
#if LCD_P38_fault_PIN_SEL == 1
#define LCD_P38_fault_GPIO   digitalIO_PTC18
#define LCD_P38_fault_FN     7
#endif

// Pin Mapping for LCD_P40 signal
//   <o> LCD_P40 [PTD0]<name=LCD_P40_PIN_SEL>
//   <i> Shows which pin LCD_P40 is mapped to
//     <0=> Disabled
//     <1=> PTD0 (reset default)<selection=PTD0_SIG_SEL,LCD_P40 (reset default)>
//     <2=> PTD0<selection=PTD0_SIG_SEL,LCD_P40>
//     <1=> Default
#define LCD_P40_PIN_SEL      1
#if LCD_P40_PIN_SEL == 2
#define LCD_P40_GPIO         digitalIO_PTD0
#define LCD_P40_FN           0
#endif

// Pin Mapping for LCD_P40_fault signal
//   <o> LCD_P40_fault [PTD0]<name=LCD_P40_fault_PIN_SEL>
//   <i> Shows which pin LCD_P40_fault is mapped to
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,LCD_P40_fault>
//     <0=> Default
#define LCD_P40_fault_PIN_SEL 0
#if LCD_P40_fault_PIN_SEL == 1
#define LCD_P40_fault_GPIO   digitalIO_PTD0
#define LCD_P40_fault_FN     7
#endif

// Pin Mapping for LCD_P41 signal
//   <o> LCD_P41 [PTD1]<name=LCD_P41_PIN_SEL>
//   <i> Shows which pin LCD_P41 is mapped to
//     <0=> Disabled
//     <1=> PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE) (reset default)<selection=PTD1_SIG_SEL,LCD_P41/ADC0_SE5b (reset default)>
//     <2=> PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE)<selection=PTD1_SIG_SEL,LCD_P41/ADC0_SE5b>
//     <0=> Default
#define LCD_P41_PIN_SEL      0
#if LCD_P41_PIN_SEL == 2
#define LCD_P41_GPIO         digitalIO_PTD1
#define LCD_P41_FN           0
#endif

// Pin Mapping for LCD_P41_fault signal
//   <o> LCD_P41_fault [PTD1]<name=LCD_P41_fault_PIN_SEL>
//   <i> Shows which pin LCD_P41_fault is mapped to
//     <0=> Disabled
//     <1=> PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE)<selection=PTD1_SIG_SEL,LCD_P41_fault>
//     <0=> Default
#define LCD_P41_fault_PIN_SEL 0
#if LCD_P41_fault_PIN_SEL == 1
#define LCD_P41_fault_GPIO   digitalIO_PTD1
#define LCD_P41_fault_FN     7
#endif

// Pin Mapping for LCD_P42 signal
//   <o> LCD_P42 [PTD2]<name=LCD_P42_PIN_SEL>
//   <i> Shows which pin LCD_P42 is mapped to
//     <0=> Disabled
//     <1=> PTD2 (Alias:D9) (reset default)<selection=PTD2_SIG_SEL,LCD_P42 (reset default)>
//     <2=> PTD2 (Alias:D9)<selection=PTD2_SIG_SEL,LCD_P42>
//     <0=> Default
#define LCD_P42_PIN_SEL      0
#if LCD_P42_PIN_SEL == 2
#define LCD_P42_GPIO         digitalIO_PTD2
#define LCD_P42_FN           0
#endif

// Pin Mapping for LCD_P42_fault signal
//   <o> LCD_P42_fault [PTD2]<name=LCD_P42_fault_PIN_SEL>
//   <i> Shows which pin LCD_P42_fault is mapped to
//     <0=> Disabled
//     <1=> PTD2 (Alias:D9)<selection=PTD2_SIG_SEL,LCD_P42_fault>
//     <0=> Default
#define LCD_P42_fault_PIN_SEL 0
#if LCD_P42_fault_PIN_SEL == 1
#define LCD_P42_fault_GPIO   digitalIO_PTD2
#define LCD_P42_fault_FN     7
#endif

// Pin Mapping for LCD_P43 signal
//   <o> LCD_P43 [PTD3]<name=LCD_P43_PIN_SEL>
//   <i> Shows which pin LCD_P43 is mapped to
//     <0=> Disabled
//     <1=> PTD3 (Alias:D2) (reset default)<selection=PTD3_SIG_SEL,LCD_P43 (reset default)>
//     <2=> PTD3 (Alias:D2)<selection=PTD3_SIG_SEL,LCD_P43>
//     <0=> Default
#define LCD_P43_PIN_SEL      0
#if LCD_P43_PIN_SEL == 2
#define LCD_P43_GPIO         digitalIO_PTD3
#define LCD_P43_FN           0
#endif

// Pin Mapping for LCD_P43_fault signal
//   <o> LCD_P43_fault [PTD3]<name=LCD_P43_fault_PIN_SEL>
//   <i> Shows which pin LCD_P43_fault is mapped to
//     <0=> Disabled
//     <1=> PTD3 (Alias:D2)<selection=PTD3_SIG_SEL,LCD_P43_fault>
//     <0=> Default
#define LCD_P43_fault_PIN_SEL 0
#if LCD_P43_fault_PIN_SEL == 1
#define LCD_P43_fault_GPIO   digitalIO_PTD3
#define LCD_P43_fault_FN     7
#endif

// Pin Mapping for LCD_P44 signal
//   <o> LCD_P44 [PTD4]<name=LCD_P44_PIN_SEL>
//   <i> Shows which pin LCD_P44 is mapped to
//     <0=> Disabled
//     <1=> PTD4 (Alias:D10) (reset default)<selection=PTD4_SIG_SEL,LCD_P44 (reset default)>
//     <2=> PTD4 (Alias:D10)<selection=PTD4_SIG_SEL,LCD_P44>
//     <0=> Default
#define LCD_P44_PIN_SEL      0
#if LCD_P44_PIN_SEL == 2
#define LCD_P44_GPIO         digitalIO_PTD4
#define LCD_P44_FN           0
#endif

// Pin Mapping for LCD_P44_fault signal
//   <o> LCD_P44_fault [PTD4]<name=LCD_P44_fault_PIN_SEL>
//   <i> Shows which pin LCD_P44_fault is mapped to
//     <0=> Disabled
//     <1=> PTD4 (Alias:D10)<selection=PTD4_SIG_SEL,LCD_P44_fault>
//     <0=> Default
#define LCD_P44_fault_PIN_SEL 0
#if LCD_P44_fault_PIN_SEL == 1
#define LCD_P44_fault_GPIO   digitalIO_PTD4
#define LCD_P44_fault_FN     7
#endif

// Pin Mapping for LCD_P45 signal
//   <o> LCD_P45 [PTD5]<name=LCD_P45_PIN_SEL>
//   <i> Shows which pin LCD_P45 is mapped to
//     <0=> Disabled
//     <1=> PTD5 (Alias:D13, LED_GREEN) (reset default)<selection=PTD5_SIG_SEL,LCD_P45/ADC0_SE6b (reset default)>
//     <2=> PTD5 (Alias:D13, LED_GREEN)<selection=PTD5_SIG_SEL,LCD_P45/ADC0_SE6b>
//     <0=> Default
#define LCD_P45_PIN_SEL      0
#if LCD_P45_PIN_SEL == 2
#define LCD_P45_GPIO         digitalIO_PTD5
#define LCD_P45_FN           0
#endif

// Pin Mapping for LCD_P45_fault signal
//   <o> LCD_P45_fault [PTD5]<name=LCD_P45_fault_PIN_SEL>
//   <i> Shows which pin LCD_P45_fault is mapped to
//     <0=> Disabled
//     <1=> PTD5 (Alias:D13, LED_GREEN)<selection=PTD5_SIG_SEL,LCD_P45_fault>
//     <0=> Default
#define LCD_P45_fault_PIN_SEL 0
#if LCD_P45_fault_PIN_SEL == 1
#define LCD_P45_fault_GPIO   digitalIO_PTD5
#define LCD_P45_fault_FN     7
#endif

// Pin Mapping for LCD_P46 signal
//   <o> LCD_P46 [PTD6]<name=LCD_P46_PIN_SEL>
//   <i> Shows which pin LCD_P46 is mapped to
//     <0=> Disabled
//     <1=> PTD6 (Alias:D11) (reset default)<selection=PTD6_SIG_SEL,LCD_P46/ADC0_SE7b (reset default)>
//     <2=> PTD6 (Alias:D11)<selection=PTD6_SIG_SEL,LCD_P46/ADC0_SE7b>
//     <0=> Default
#define LCD_P46_PIN_SEL      0
#if LCD_P46_PIN_SEL == 2
#define LCD_P46_GPIO         digitalIO_PTD6
#define LCD_P46_FN           0
#endif

// Pin Mapping for LCD_P46_fault signal
//   <o> LCD_P46_fault [PTD6]<name=LCD_P46_fault_PIN_SEL>
//   <i> Shows which pin LCD_P46_fault is mapped to
//     <0=> Disabled
//     <1=> PTD6 (Alias:D11)<selection=PTD6_SIG_SEL,LCD_P46_fault>
//     <0=> Default
#define LCD_P46_fault_PIN_SEL 0
#if LCD_P46_fault_PIN_SEL == 1
#define LCD_P46_fault_GPIO   digitalIO_PTD6
#define LCD_P46_fault_FN     7
#endif

// Pin Mapping for LCD_P47 signal
//   <o> LCD_P47 [PTD7]<name=LCD_P47_PIN_SEL>
//   <i> Shows which pin LCD_P47 is mapped to
//     <0=> Disabled
//     <1=> PTD7 (Alias:D12) (reset default)<selection=PTD7_SIG_SEL,LCD_P47 (reset default)>
//     <2=> PTD7 (Alias:D12)<selection=PTD7_SIG_SEL,LCD_P47>
//     <0=> Default
#define LCD_P47_PIN_SEL      0
#if LCD_P47_PIN_SEL == 2
#define LCD_P47_GPIO         digitalIO_PTD7
#define LCD_P47_FN           0
#endif

// Pin Mapping for LCD_P47_fault signal
//   <o> LCD_P47_fault [PTD7]<name=LCD_P47_fault_PIN_SEL>
//   <i> Shows which pin LCD_P47_fault is mapped to
//     <0=> Disabled
//     <1=> PTD7 (Alias:D12)<selection=PTD7_SIG_SEL,LCD_P47_fault>
//     <0=> Default
#define LCD_P47_fault_PIN_SEL 0
#if LCD_P47_fault_PIN_SEL == 1
#define LCD_P47_fault_GPIO   digitalIO_PTD7
#define LCD_P47_fault_FN     7
#endif

// Pin Mapping for LCD_P48 signal
//   <o> LCD_P48 [PTE0]<name=LCD_P48_PIN_SEL>
//   <i> Shows which pin LCD_P48 is mapped to
//     <0=> Disabled
//     <1=> PTE0 (Alias:D14)<selection=PTE0_SIG_SEL,LCD_P48>
//     <0=> Default
#define LCD_P48_PIN_SEL      0
#if LCD_P48_PIN_SEL == 1
#define LCD_P48_GPIO         digitalIO_PTE0
#define LCD_P48_FN           0
#endif

// Pin Mapping for LCD_P48_fault signal
//   <o> LCD_P48_fault [PTE0]<name=LCD_P48_fault_PIN_SEL>
//   <i> Shows which pin LCD_P48_fault is mapped to
//     <0=> Disabled
//     <1=> PTE0 (Alias:D14)<selection=PTE0_SIG_SEL,LCD_P48_fault>
//     <0=> Default
#define LCD_P48_fault_PIN_SEL 0
#if LCD_P48_fault_PIN_SEL == 1
#define LCD_P48_fault_GPIO   digitalIO_PTE0
#define LCD_P48_fault_FN     7
#endif

// Pin Mapping for LCD_P49 signal
//   <o> LCD_P49 [PTE1]<name=LCD_P49_PIN_SEL>
//   <i> Shows which pin LCD_P49 is mapped to
//     <0=> Disabled
//     <1=> PTE1 (Alias:D15)<selection=PTE1_SIG_SEL,LCD_P49>
//     <0=> Default
#define LCD_P49_PIN_SEL      0
#if LCD_P49_PIN_SEL == 1
#define LCD_P49_GPIO         digitalIO_PTE1
#define LCD_P49_FN           0
#endif

// Pin Mapping for LCD_P49_fault signal
//   <o> LCD_P49_fault [PTE1]<name=LCD_P49_fault_PIN_SEL>
//   <i> Shows which pin LCD_P49_fault is mapped to
//     <0=> Disabled
//     <1=> PTE1 (Alias:D15)<selection=PTE1_SIG_SEL,LCD_P49_fault>
//     <0=> Default
#define LCD_P49_fault_PIN_SEL 0
#if LCD_P49_fault_PIN_SEL == 1
#define LCD_P49_fault_GPIO   digitalIO_PTE1
#define LCD_P49_fault_FN     7
#endif

// Pin Mapping for LCD_P50 signal
//   <o> LCD_P50 [PTE2]<name=LCD_P50_PIN_SEL>
//   <i> Shows which pin LCD_P50 is mapped to
//     <0=> Disabled
//     <1=> PTE2<selection=PTE2_SIG_SEL,LCD_P50>
//     <0=> Default
#define LCD_P50_PIN_SEL      0
#if LCD_P50_PIN_SEL == 1
#define LCD_P50_GPIO         digitalIO_PTE2
#define LCD_P50_FN           0
#endif

// Pin Mapping for LCD_P50_fault signal
//   <o> LCD_P50_fault [PTE2]<name=LCD_P50_fault_PIN_SEL>
//   <i> Shows which pin LCD_P50_fault is mapped to
//     <0=> Disabled
//     <1=> PTE2<selection=PTE2_SIG_SEL,LCD_P50_fault>
//     <0=> Default
#define LCD_P50_fault_PIN_SEL 0
#if LCD_P50_fault_PIN_SEL == 1
#define LCD_P50_fault_GPIO   digitalIO_PTE2
#define LCD_P50_fault_FN     7
#endif

// Pin Mapping for LCD_P51 signal
//   <o> LCD_P51 [PTE3]<name=LCD_P51_PIN_SEL>
//   <i> Shows which pin LCD_P51 is mapped to
//     <0=> Disabled
//     <1=> PTE3<selection=PTE3_SIG_SEL,LCD_P51>
//     <0=> Default
#define LCD_P51_PIN_SEL      0
#if LCD_P51_PIN_SEL == 1
#define LCD_P51_GPIO         digitalIO_PTE3
#define LCD_P51_FN           0
#endif

// Pin Mapping for LCD_P51_fault signal
//   <o> LCD_P51_fault [PTE3]<name=LCD_P51_fault_PIN_SEL>
//   <i> Shows which pin LCD_P51_fault is mapped to
//     <0=> Disabled
//     <1=> PTE3<selection=PTE3_SIG_SEL,LCD_P51_fault>
//     <0=> Default
#define LCD_P51_fault_PIN_SEL 0
#if LCD_P51_fault_PIN_SEL == 1
#define LCD_P51_fault_GPIO   digitalIO_PTE3
#define LCD_P51_fault_FN     7
#endif

// Pin Mapping for LCD_P52 signal
//   <o> LCD_P52 [PTE4]<name=LCD_P52_PIN_SEL>
//   <i> Shows which pin LCD_P52 is mapped to
//     <0=> Disabled
//     <1=> PTE4<selection=PTE4_SIG_SEL,LCD_P52>
//     <0=> Default
#define LCD_P52_PIN_SEL      0
#if LCD_P52_PIN_SEL == 1
#define LCD_P52_GPIO         digitalIO_PTE4
#define LCD_P52_FN           0
#endif

// Pin Mapping for LCD_P52_fault signal
//   <o> LCD_P52_fault [PTE4]<name=LCD_P52_fault_PIN_SEL>
//   <i> Shows which pin LCD_P52_fault is mapped to
//     <0=> Disabled
//     <1=> PTE4<selection=PTE4_SIG_SEL,LCD_P52_fault>
//     <0=> Default
#define LCD_P52_fault_PIN_SEL 0
#if LCD_P52_fault_PIN_SEL == 1
#define LCD_P52_fault_GPIO   digitalIO_PTE4
#define LCD_P52_fault_FN     7
#endif

// Pin Mapping for LCD_P53 signal
//   <o> LCD_P53 [PTE5]<name=LCD_P53_PIN_SEL>
//   <i> Shows which pin LCD_P53 is mapped to
//     <0=> Disabled
//     <1=> PTE5<selection=PTE5_SIG_SEL,LCD_P53>
//     <0=> Default
#define LCD_P53_PIN_SEL      0
#if LCD_P53_PIN_SEL == 1
#define LCD_P53_GPIO         digitalIO_PTE5
#define LCD_P53_FN           0
#endif

// Pin Mapping for LCD_P53_fault signal
//   <o> LCD_P53_fault [PTE5]<name=LCD_P53_fault_PIN_SEL>
//   <i> Shows which pin LCD_P53_fault is mapped to
//     <0=> Disabled
//     <1=> PTE5<selection=PTE5_SIG_SEL,LCD_P53_fault>
//     <0=> Default
#define LCD_P53_fault_PIN_SEL 0
#if LCD_P53_fault_PIN_SEL == 1
#define LCD_P53_fault_GPIO   digitalIO_PTE5
#define LCD_P53_fault_FN     7
#endif

// Pin Mapping for LCD_P54 signal
//   <o> LCD_P54 [PTE6]<name=LCD_P54_PIN_SEL>
//   <i> Shows which pin LCD_P54 is mapped to
//     <0=> Disabled
//     <1=> PTE6<selection=PTE6_SIG_SEL,LCD_P54>
//     <0=> Default
#define LCD_P54_PIN_SEL      0
#if LCD_P54_PIN_SEL == 1
#define LCD_P54_GPIO         digitalIO_PTE6
#define LCD_P54_FN           0
#endif

// Pin Mapping for LCD_P54_fault signal
//   <o> LCD_P54_fault [PTE6]<name=LCD_P54_fault_PIN_SEL>
//   <i> Shows which pin LCD_P54_fault is mapped to
//     <0=> Disabled
//     <1=> PTE6<selection=PTE6_SIG_SEL,LCD_P54_fault>
//     <0=> Default
#define LCD_P54_fault_PIN_SEL 0
#if LCD_P54_fault_PIN_SEL == 1
#define LCD_P54_fault_GPIO   digitalIO_PTE6
#define LCD_P54_fault_FN     7
#endif

// Pin Mapping for LCD_P55 signal
//   <o> LCD_P55 [PTE16]<name=LCD_P55_PIN_SEL>
//   <i> Shows which pin LCD_P55 is mapped to
//     <0=> Disabled
//     <1=> PTE16 (reset default)<selection=PTE16_SIG_SEL,LCD_P55/ADC0_DP1/ADC0_SE1 (reset default)>
//     <2=> PTE16<selection=PTE16_SIG_SEL,LCD_P55/ADC0_DP1/ADC0_SE1>
//     <1=> Default
#define LCD_P55_PIN_SEL      1
#if LCD_P55_PIN_SEL == 2
#define LCD_P55_GPIO         digitalIO_PTE16
#define LCD_P55_FN           0
#endif

// Pin Mapping for LCD_P55_fault signal
//   <o> LCD_P55_fault [PTE16]<name=LCD_P55_fault_PIN_SEL>
//   <i> Shows which pin LCD_P55_fault is mapped to
//     <0=> Disabled
//     <1=> PTE16<selection=PTE16_SIG_SEL,LCD_P55_fault>
//     <0=> Default
#define LCD_P55_fault_PIN_SEL 0
#if LCD_P55_fault_PIN_SEL == 1
#define LCD_P55_fault_GPIO   digitalIO_PTE16
#define LCD_P55_fault_FN     7
#endif

// Pin Mapping for LCD_P56 signal
//   <o> LCD_P56 [PTE17]<name=LCD_P56_PIN_SEL>
//   <i> Shows which pin LCD_P56 is mapped to
//     <0=> Disabled
//     <1=> PTE17 (reset default)<selection=PTE17_SIG_SEL,LCD_P56/ADC0_DM1/ADC0_SE5a (reset default)>
//     <2=> PTE17<selection=PTE17_SIG_SEL,LCD_P56/ADC0_DM1/ADC0_SE5a>
//     <1=> Default
#define LCD_P56_PIN_SEL      1
#if LCD_P56_PIN_SEL == 2
#define LCD_P56_GPIO         digitalIO_PTE17
#define LCD_P56_FN           0
#endif

// Pin Mapping for LCD_P56_fault signal
//   <o> LCD_P56_fault [PTE17]<name=LCD_P56_fault_PIN_SEL>
//   <i> Shows which pin LCD_P56_fault is mapped to
//     <0=> Disabled
//     <1=> PTE17<selection=PTE17_SIG_SEL,LCD_P56_fault>
//     <0=> Default
#define LCD_P56_fault_PIN_SEL 0
#if LCD_P56_fault_PIN_SEL == 1
#define LCD_P56_fault_GPIO   digitalIO_PTE17
#define LCD_P56_fault_FN     7
#endif

// Pin Mapping for LCD_P57 signal
//   <o> LCD_P57 [PTE18]<name=LCD_P57_PIN_SEL>
//   <i> Shows which pin LCD_P57 is mapped to
//     <0=> Disabled
//     <1=> PTE18 (reset default)<selection=PTE18_SIG_SEL,LCD_P57/ADC0_DP2/ADC0_SE2 (reset default)>
//     <2=> PTE18<selection=PTE18_SIG_SEL,LCD_P57/ADC0_DP2/ADC0_SE2>
//     <1=> Default
#define LCD_P57_PIN_SEL      1
#if LCD_P57_PIN_SEL == 2
#define LCD_P57_GPIO         digitalIO_PTE18
#define LCD_P57_FN           0
#endif

// Pin Mapping for LCD_P57_fault signal
//   <o> LCD_P57_fault [PTE18]<name=LCD_P57_fault_PIN_SEL>
//   <i> Shows which pin LCD_P57_fault is mapped to
//     <0=> Disabled
//     <1=> PTE18<selection=PTE18_SIG_SEL,LCD_P57_fault>
//     <0=> Default
#define LCD_P57_fault_PIN_SEL 0
#if LCD_P57_fault_PIN_SEL == 1
#define LCD_P57_fault_GPIO   digitalIO_PTE18
#define LCD_P57_fault_FN     7
#endif

// Pin Mapping for LCD_P58 signal
//   <o> LCD_P58 [PTE19]<name=LCD_P58_PIN_SEL>
//   <i> Shows which pin LCD_P58 is mapped to
//     <0=> Disabled
//     <1=> PTE19 (reset default)<selection=PTE19_SIG_SEL,LCD_P58/ADC0_DM2/ADC0_SE6a (reset default)>
//     <2=> PTE19<selection=PTE19_SIG_SEL,LCD_P58/ADC0_DM2/ADC0_SE6a>
//     <1=> Default
#define LCD_P58_PIN_SEL      1
#if LCD_P58_PIN_SEL == 2
#define LCD_P58_GPIO         digitalIO_PTE19
#define LCD_P58_FN           0
#endif

// Pin Mapping for LCD_P58_fault signal
//   <o> LCD_P58_fault [PTE19]<name=LCD_P58_fault_PIN_SEL>
//   <i> Shows which pin LCD_P58_fault is mapped to
//     <0=> Disabled
//     <1=> PTE19<selection=PTE19_SIG_SEL,LCD_P58_fault>
//     <0=> Default
#define LCD_P58_fault_PIN_SEL 0
#if LCD_P58_fault_PIN_SEL == 1
#define LCD_P58_fault_GPIO   digitalIO_PTE19
#define LCD_P58_fault_FN     7
#endif

// Pin Mapping for LCD_P59 signal
//   <o> LCD_P59 [PTE20]<name=LCD_P59_PIN_SEL>
//   <i> Shows which pin LCD_P59 is mapped to
//     <0=> Disabled
//     <1=> PTE20 (reset default)<selection=PTE20_SIG_SEL,LCD_P59/ADC0_DP0/ADC0_SE0 (reset default)>
//     <2=> PTE20<selection=PTE20_SIG_SEL,LCD_P59/ADC0_DP0/ADC0_SE0>
//     <1=> Default
#define LCD_P59_PIN_SEL      1
#if LCD_P59_PIN_SEL == 2
#define LCD_P59_GPIO         digitalIO_PTE20
#define LCD_P59_FN           0
#endif

// Pin Mapping for LCD_P59_fault signal
//   <o> LCD_P59_fault [PTE20]<name=LCD_P59_fault_PIN_SEL>
//   <i> Shows which pin LCD_P59_fault is mapped to
//     <0=> Disabled
//     <1=> PTE20<selection=PTE20_SIG_SEL,LCD_P59_fault>
//     <0=> Default
#define LCD_P59_fault_PIN_SEL 0
#if LCD_P59_fault_PIN_SEL == 1
#define LCD_P59_fault_GPIO   digitalIO_PTE20
#define LCD_P59_fault_FN     7
#endif

// Pin Mapping for LCD_P60 signal
//   <o> LCD_P60 [PTE21]<name=LCD_P60_PIN_SEL>
//   <i> Shows which pin LCD_P60 is mapped to
//     <0=> Disabled
//     <1=> PTE21 (reset default)<selection=PTE21_SIG_SEL,LCD_P60/ADC0_DM0/ADC0_SE4a (reset default)>
//     <2=> PTE21<selection=PTE21_SIG_SEL,LCD_P60/ADC0_DM0/ADC0_SE4a>
//     <1=> Default
#define LCD_P60_PIN_SEL      1
#if LCD_P60_PIN_SEL == 2
#define LCD_P60_GPIO         digitalIO_PTE21
#define LCD_P60_FN           0
#endif

// Pin Mapping for LCD_P60_fault signal
//   <o> LCD_P60_fault [PTE21]<name=LCD_P60_fault_PIN_SEL>
//   <i> Shows which pin LCD_P60_fault is mapped to
//     <0=> Disabled
//     <1=> PTE21<selection=PTE21_SIG_SEL,LCD_P60_fault>
//     <0=> Default
#define LCD_P60_fault_PIN_SEL 0
#if LCD_P60_fault_PIN_SEL == 1
#define LCD_P60_fault_GPIO   digitalIO_PTE21
#define LCD_P60_fault_FN     7
#endif

// </h>

// <h> Low-Leakage Wake-up Unit (LLWU)

// Pin Mapping for LLWU_P5 signal
//   <o> LLWU_P5 [PTB0]<name=LLWU_P5_PIN_SEL>
//   <i> Shows which pin LLWU_P5 is mapped to
//     <0=> Disabled
//     <1=> PTB0 (Alias:A0)<selection=PTB0_SIG_SEL,GPIOB_0/LLWU_P5>
//     <0=> Default
#define LLWU_P5_PIN_SEL      0
#if LLWU_P5_PIN_SEL == 1
#define LLWU_P5_GPIO         digitalIO_PTB0
#define LLWU_P5_FN           1
#endif

// Pin Mapping for LLWU_P6 signal
//   <o> LLWU_P6 [PTC1]<name=LLWU_P6_PIN_SEL>
//   <i> Shows which pin LLWU_P6 is mapped to
//     <0=> Disabled
//     <1=> PTC1 (Alias:A5)<selection=PTC1_SIG_SEL,GPIOC_1/LLWU_P6/RTC_CLKIN>
//     <0=> Default
#define LLWU_P6_PIN_SEL      0
#if LLWU_P6_PIN_SEL == 1
#define LLWU_P6_GPIO         digitalIO_PTC1
#define LLWU_P6_FN           1
#endif

// Pin Mapping for LLWU_P7 signal
//   <o> LLWU_P7 [PTC3]<name=LLWU_P7_PIN_SEL>
//   <i> Shows which pin LLWU_P7 is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,GPIOC_3/LLWU_P7>
//     <0=> Default
#define LLWU_P7_PIN_SEL      0
#if LLWU_P7_PIN_SEL == 1
#define LLWU_P7_GPIO         digitalIO_PTC3
#define LLWU_P7_FN           1
#endif

// Pin Mapping for LLWU_P8 signal
//   <o> LLWU_P8 [PTC4]<name=LLWU_P8_PIN_SEL>
//   <i> Shows which pin LLWU_P8 is mapped to
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,GPIOC_4/LLWU_P8>
//     <0=> Default
#define LLWU_P8_PIN_SEL      0
#if LLWU_P8_PIN_SEL == 1
#define LLWU_P8_GPIO         digitalIO_PTC4
#define LLWU_P8_FN           1
#endif

// Pin Mapping for LLWU_P9 signal
//   <o> LLWU_P9 [PTC5]<name=LLWU_P9_PIN_SEL>
//   <i> Shows which pin LLWU_P9 is mapped to
//     <0=> Disabled
//     <1=> PTC5 (Alias:ACC_INT1)<selection=PTC5_SIG_SEL,GPIOC_5/LLWU_P9>
//     <1=> Default
#define LLWU_P9_PIN_SEL      1
#if LLWU_P9_PIN_SEL == 1
#define LLWU_P9_GPIO         digitalIO_PTC5
#define LLWU_P9_FN           1
#endif

// Pin Mapping for LLWU_P10 signal
//   <o> LLWU_P10 [PTC6]<name=LLWU_P10_PIN_SEL>
//   <i> Shows which pin LLWU_P10 is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,GPIOC_6/LLWU_P10>
//     <0=> Default
#define LLWU_P10_PIN_SEL     0
#if LLWU_P10_PIN_SEL == 1
#define LLWU_P10_GPIO        digitalIO_PTC6
#define LLWU_P10_FN          1
#endif

// Pin Mapping for LLWU_P14 signal
//   <o> LLWU_P14 [PTD4]<name=LLWU_P14_PIN_SEL>
//   <i> Shows which pin LLWU_P14 is mapped to
//     <0=> Disabled
//     <1=> PTD4 (Alias:D10)<selection=PTD4_SIG_SEL,GPIOD_4/LLWU_P14>
//     <1=> Default
#define LLWU_P14_PIN_SEL     1
#if LLWU_P14_PIN_SEL == 1
#define LLWU_P14_GPIO        digitalIO_PTD4
#define LLWU_P14_FN          1
#endif

// Pin Mapping for LLWU_P15 signal
//   <o> LLWU_P15 [PTD6]<name=LLWU_P15_PIN_SEL>
//   <i> Shows which pin LLWU_P15 is mapped to
//     <0=> Disabled
//     <1=> PTD6 (Alias:D11)<selection=PTD6_SIG_SEL,GPIOD_6/LLWU_P15>
//     <1=> Default
#define LLWU_P15_PIN_SEL     1
#if LLWU_P15_PIN_SEL == 1
#define LLWU_P15_GPIO        digitalIO_PTD6
#define LLWU_P15_FN          1
#endif

// </h>

// <h> Low Power Timer (LPTMR)

// Pin Mapping for LPTMR0_ALT1 signal
//   <o> LPTMR0_ALT1 [PTA19]<name=LPTMR0_ALT1_PIN_SEL>
//   <i> Shows which pin LPTMR0_ALT1 is mapped to
//     <0=> Disabled
//     <1=> PTA19<selection=PTA19_SIG_SEL,LPTMR0_ALT1>
//     <0=> Default
#define LPTMR0_ALT1_PIN_SEL  0
#if LPTMR0_ALT1_PIN_SEL == 1
#define LPTMR0_ALT1_GPIO     digitalIO_PTA19
#define LPTMR0_ALT1_FN       6
#endif

// Pin Mapping for LPTMR0_ALT2 signal
//   <o> LPTMR0_ALT2 [PTC5]<name=LPTMR0_ALT2_PIN_SEL>
//   <i> Shows which pin LPTMR0_ALT2 is mapped to
//     <0=> Disabled
//     <1=> PTC5 (Alias:ACC_INT1)<selection=PTC5_SIG_SEL,LPTMR0_ALT2>
//     <0=> Default
#define LPTMR0_ALT2_PIN_SEL  0
#if LPTMR0_ALT2_PIN_SEL == 1
#define LPTMR0_ALT2_GPIO     digitalIO_PTC5
#define LPTMR0_ALT2_FN       3
#endif

// Pin Mapping for LPTMR0_ALT3 signal
//   <o> LPTMR0_ALT3 [PTE17]<name=LPTMR0_ALT3_PIN_SEL>
//   <i> Shows which pin LPTMR0_ALT3 is mapped to
//     <0=> Disabled
//     <1=> PTE17<selection=PTE17_SIG_SEL,LPTMR0_ALT3>
//     <0=> Default
#define LPTMR0_ALT3_PIN_SEL  0
#if LPTMR0_ALT3_PIN_SEL == 1
#define LPTMR0_ALT3_GPIO     digitalIO_PTE17
#define LPTMR0_ALT3_FN       6
#endif

// </h>

// <h> Debug and Control

// Pin Mapping for NMI_b signal
//   <o> NMI_b [PTA4]<name=NMI_b_PIN_SEL>
//   <i> Shows which pin NMI_b is mapped to
//     <0=> Disabled
//     <1=> PTA4 (Alias:D4) (reset default)<selection=PTA4_SIG_SEL,NMI_b (reset default)>
//     <2=> PTA4 (Alias:D4)<selection=PTA4_SIG_SEL,NMI_b>
//     <0=> Default
#define NMI_b_PIN_SEL        0
#if NMI_b_PIN_SEL == 2
#define NMI_b_GPIO           digitalIO_PTA4
#define NMI_b_FN             7
#endif

// Pin Mapping for RESET_b signal
//   <o> RESET_b [PTA20, PTA20]<name=RESET_b_PIN_SEL>
//   <i> Shows which pin RESET_b is mapped to
//     <0=> Disabled
//     <1=> PTA20 (reset default)<selection=PTA20_SIG_SEL,RESET_b (reset default)>
//     <2=> PTA20<selection=PTA20_SIG_SEL,RESET_b>
//     <3=> PTA20<selection=PTA20_SIG_SEL,RESET_b>
//     <1=> Default
#define RESET_b_PIN_SEL      1
#if RESET_b_PIN_SEL == 2
#define RESET_b_GPIO         digitalIO_PTA20
#define RESET_b_FN           0
#elif RESET_b_PIN_SEL == 3
#define RESET_b_GPIO         digitalIO_PTA20
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
#if SWD_CLK_PIN_SEL == 2
#define SWD_CLK_GPIO         digitalIO_PTA0
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
#if SWD_DIO_PIN_SEL == 2
#define SWD_DIO_GPIO         digitalIO_PTA3
#define SWD_DIO_FN           7
#endif

// </h>

// <h> Serial Peripheral Interface (SPI0)

// Pin Mapping for SPI0_MISO signal
//   <o> SPI0_MISO [PTA17, PTC7, PTD3, PTE19, PTA16, PTC6, PTD2, PTE18]<name=SPI0_MISO_PIN_SEL>
//   <i> Shows which pin SPI0_MISO is mapped to
//     <0=> Disabled
//     <1=> PTA17<selection=PTA17_SIG_SEL,SPI0_MISO>
//     <2=> PTC7<selection=PTC7_SIG_SEL,SPI0_MISO>
//     <3=> PTD3 (Alias:D2)<selection=PTD3_SIG_SEL,SPI0_MISO>
//     <4=> PTE19<selection=PTE19_SIG_SEL,SPI0_MISO>
//     <5=> PTA16<selection=PTA16_SIG_SEL,SPI0_MISO>
//     <6=> PTC6<selection=PTC6_SIG_SEL,SPI0_MISO>
//     <7=> PTD2 (Alias:D9)<selection=PTD2_SIG_SEL,SPI0_MISO>
//     <8=> PTE18<selection=PTE18_SIG_SEL,SPI0_MISO>
//     <0=> Default
#define SPI0_MISO_PIN_SEL    0
#if SPI0_MISO_PIN_SEL == 1
#define SPI0_MISO_GPIO       digitalIO_PTA17
#define SPI0_MISO_FN         2
#elif SPI0_MISO_PIN_SEL == 2
#define SPI0_MISO_GPIO       digitalIO_PTC7
#define SPI0_MISO_FN         2
#elif SPI0_MISO_PIN_SEL == 3
#define SPI0_MISO_GPIO       digitalIO_PTD3
#define SPI0_MISO_FN         2
#elif SPI0_MISO_PIN_SEL == 4
#define SPI0_MISO_GPIO       digitalIO_PTE19
#define SPI0_MISO_FN         2
#elif SPI0_MISO_PIN_SEL == 5
#define SPI0_MISO_GPIO       digitalIO_PTA16
#define SPI0_MISO_FN         5
#elif SPI0_MISO_PIN_SEL == 6
#define SPI0_MISO_GPIO       digitalIO_PTC6
#define SPI0_MISO_FN         5
#elif SPI0_MISO_PIN_SEL == 7
#define SPI0_MISO_GPIO       digitalIO_PTD2
#define SPI0_MISO_FN         5
#elif SPI0_MISO_PIN_SEL == 8
#define SPI0_MISO_GPIO       digitalIO_PTE18
#define SPI0_MISO_FN         5
#endif

// Pin Mapping for SPI0_MOSI signal
//   <o> SPI0_MOSI [PTA16, PTC6, PTD2, PTE18, PTA17, PTC7, PTD3, PTE19]<name=SPI0_MOSI_PIN_SEL>
//   <i> Shows which pin SPI0_MOSI is mapped to
//     <0=> Disabled
//     <1=> PTA16<selection=PTA16_SIG_SEL,SPI0_MOSI>
//     <2=> PTC6<selection=PTC6_SIG_SEL,SPI0_MOSI>
//     <3=> PTD2 (Alias:D9)<selection=PTD2_SIG_SEL,SPI0_MOSI>
//     <4=> PTE18<selection=PTE18_SIG_SEL,SPI0_MOSI>
//     <5=> PTA17<selection=PTA17_SIG_SEL,SPI0_MOSI>
//     <6=> PTC7<selection=PTC7_SIG_SEL,SPI0_MOSI>
//     <7=> PTD3 (Alias:D2)<selection=PTD3_SIG_SEL,SPI0_MOSI>
//     <8=> PTE19<selection=PTE19_SIG_SEL,SPI0_MOSI>
//     <0=> Default
#define SPI0_MOSI_PIN_SEL    0
#if SPI0_MOSI_PIN_SEL == 1
#define SPI0_MOSI_GPIO       digitalIO_PTA16
#define SPI0_MOSI_FN         2
#elif SPI0_MOSI_PIN_SEL == 2
#define SPI0_MOSI_GPIO       digitalIO_PTC6
#define SPI0_MOSI_FN         2
#elif SPI0_MOSI_PIN_SEL == 3
#define SPI0_MOSI_GPIO       digitalIO_PTD2
#define SPI0_MOSI_FN         2
#elif SPI0_MOSI_PIN_SEL == 4
#define SPI0_MOSI_GPIO       digitalIO_PTE18
#define SPI0_MOSI_FN         2
#elif SPI0_MOSI_PIN_SEL == 5
#define SPI0_MOSI_GPIO       digitalIO_PTA17
#define SPI0_MOSI_FN         5
#elif SPI0_MOSI_PIN_SEL == 6
#define SPI0_MOSI_GPIO       digitalIO_PTC7
#define SPI0_MOSI_FN         5
#elif SPI0_MOSI_PIN_SEL == 7
#define SPI0_MOSI_GPIO       digitalIO_PTD3
#define SPI0_MOSI_FN         5
#elif SPI0_MOSI_PIN_SEL == 8
#define SPI0_MOSI_GPIO       digitalIO_PTE19
#define SPI0_MOSI_FN         5
#endif

// Pin Mapping for SPI0_PCS0 signal
//   <o> SPI0_PCS0 [PTA14, PTC4, PTD0, PTE16]<name=SPI0_PCS0_PIN_SEL>
//   <i> Shows which pin SPI0_PCS0 is mapped to
//     <0=> Disabled
//     <1=> PTA14<selection=PTA14_SIG_SEL,SPI0_PCS0>
//     <2=> PTC4<selection=PTC4_SIG_SEL,SPI0_PCS0>
//     <3=> PTD0<selection=PTD0_SIG_SEL,SPI0_PCS0>
//     <4=> PTE16<selection=PTE16_SIG_SEL,SPI0_PCS0>
//     <0=> Default
#define SPI0_PCS0_PIN_SEL    0
#if SPI0_PCS0_PIN_SEL == 1
#define SPI0_PCS0_GPIO       digitalIO_PTA14
#define SPI0_PCS0_FN         2
#elif SPI0_PCS0_PIN_SEL == 2
#define SPI0_PCS0_GPIO       digitalIO_PTC4
#define SPI0_PCS0_FN         2
#elif SPI0_PCS0_PIN_SEL == 3
#define SPI0_PCS0_GPIO       digitalIO_PTD0
#define SPI0_PCS0_FN         2
#elif SPI0_PCS0_PIN_SEL == 4
#define SPI0_PCS0_GPIO       digitalIO_PTE16
#define SPI0_PCS0_FN         2
#endif

// Pin Mapping for SPI0_SCK signal
//   <o> SPI0_SCK [PTA15, PTC5, PTD1, PTE17]<name=SPI0_SCK_PIN_SEL>
//   <i> Shows which pin SPI0_SCK is mapped to
//     <0=> Disabled
//     <1=> PTA15<selection=PTA15_SIG_SEL,SPI0_SCK>
//     <2=> PTC5 (Alias:ACC_INT1)<selection=PTC5_SIG_SEL,SPI0_SCK>
//     <3=> PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE)<selection=PTD1_SIG_SEL,SPI0_SCK>
//     <4=> PTE17<selection=PTE17_SIG_SEL,SPI0_SCK>
//     <0=> Default
#define SPI0_SCK_PIN_SEL     0
#if SPI0_SCK_PIN_SEL == 1
#define SPI0_SCK_GPIO        digitalIO_PTA15
#define SPI0_SCK_FN          2
#elif SPI0_SCK_PIN_SEL == 2
#define SPI0_SCK_GPIO        digitalIO_PTC5
#define SPI0_SCK_FN          2
#elif SPI0_SCK_PIN_SEL == 3
#define SPI0_SCK_GPIO        digitalIO_PTD1
#define SPI0_SCK_FN          2
#elif SPI0_SCK_PIN_SEL == 4
#define SPI0_SCK_GPIO        digitalIO_PTE17
#define SPI0_SCK_FN          2
#endif

// </h>

// <h> Serial Peripheral Interface (SPI1)

// Pin Mapping for SPI1_MISO signal
//   <o> SPI1_MISO [PTB17, PTD7, PTE0, PTE3, PTB16, PTD6, PTE1]<name=SPI1_MISO_PIN_SEL>
//   <i> Shows which pin SPI1_MISO is mapped to
//     <0=> Disabled
//     <1=> PTB17<selection=PTB17_SIG_SEL,SPI1_MISO>
//     <2=> PTD7 (Alias:D12)<selection=PTD7_SIG_SEL,SPI1_MISO>
//     <3=> PTE0 (Alias:D14)<selection=PTE0_SIG_SEL,SPI1_MISO>
//     <4=> PTE3<selection=PTE3_SIG_SEL,SPI1_MISO>
//     <5=> PTB16<selection=PTB16_SIG_SEL,SPI1_MISO>
//     <6=> PTD6 (Alias:D11)<selection=PTD6_SIG_SEL,SPI1_MISO>
//     <7=> PTE1 (Alias:D15)<selection=PTE1_SIG_SEL,SPI1_MISO>
//     <0=> Default
#define SPI1_MISO_PIN_SEL    0
#if SPI1_MISO_PIN_SEL == 1
#define SPI1_MISO_GPIO       digitalIO_PTB17
#define SPI1_MISO_FN         2
#elif SPI1_MISO_PIN_SEL == 2
#define SPI1_MISO_GPIO       digitalIO_PTD7
#define SPI1_MISO_FN         2
#elif SPI1_MISO_PIN_SEL == 3
#define SPI1_MISO_GPIO       digitalIO_PTE0
#define SPI1_MISO_FN         2
#elif SPI1_MISO_PIN_SEL == 4
#define SPI1_MISO_GPIO       digitalIO_PTE3
#define SPI1_MISO_FN         2
#elif SPI1_MISO_PIN_SEL == 5
#define SPI1_MISO_GPIO       digitalIO_PTB16
#define SPI1_MISO_FN         5
#elif SPI1_MISO_PIN_SEL == 6
#define SPI1_MISO_GPIO       digitalIO_PTD6
#define SPI1_MISO_FN         5
#elif SPI1_MISO_PIN_SEL == 7
#define SPI1_MISO_GPIO       digitalIO_PTE1
#define SPI1_MISO_FN         5
#endif

// Pin Mapping for SPI1_MOSI signal
//   <o> SPI1_MOSI [PTB16, PTD6, PTE1, PTB17, PTD7, PTE3]<name=SPI1_MOSI_PIN_SEL>
//   <i> Shows which pin SPI1_MOSI is mapped to
//     <0=> Disabled
//     <1=> PTB16<selection=PTB16_SIG_SEL,SPI1_MOSI>
//     <2=> PTD6 (Alias:D11)<selection=PTD6_SIG_SEL,SPI1_MOSI>
//     <3=> PTE1 (Alias:D15)<selection=PTE1_SIG_SEL,SPI1_MOSI>
//     <4=> PTB17<selection=PTB17_SIG_SEL,SPI1_MOSI>
//     <5=> PTD7 (Alias:D12)<selection=PTD7_SIG_SEL,SPI1_MOSI>
//     <6=> PTE3<selection=PTE3_SIG_SEL,SPI1_MOSI>
//     <0=> Default
#define SPI1_MOSI_PIN_SEL    0
#if SPI1_MOSI_PIN_SEL == 1
#define SPI1_MOSI_GPIO       digitalIO_PTB16
#define SPI1_MOSI_FN         2
#elif SPI1_MOSI_PIN_SEL == 2
#define SPI1_MOSI_GPIO       digitalIO_PTD6
#define SPI1_MOSI_FN         2
#elif SPI1_MOSI_PIN_SEL == 3
#define SPI1_MOSI_GPIO       digitalIO_PTE1
#define SPI1_MOSI_FN         2
#elif SPI1_MOSI_PIN_SEL == 4
#define SPI1_MOSI_GPIO       digitalIO_PTB17
#define SPI1_MOSI_FN         5
#elif SPI1_MOSI_PIN_SEL == 5
#define SPI1_MOSI_GPIO       digitalIO_PTD7
#define SPI1_MOSI_FN         5
#elif SPI1_MOSI_PIN_SEL == 6
#define SPI1_MOSI_GPIO       digitalIO_PTE3
#define SPI1_MOSI_FN         5
#endif

// Pin Mapping for SPI1_PCS0 signal
//   <o> SPI1_PCS0 [PTB8, PTB10, PTD4, PTE4]<name=SPI1_PCS0_PIN_SEL>
//   <i> Shows which pin SPI1_PCS0 is mapped to
//     <0=> Disabled
//     <1=> PTB8<selection=PTB8_SIG_SEL,SPI1_PCS0>
//     <2=> PTB10<selection=PTB10_SIG_SEL,SPI1_PCS0>
//     <3=> PTD4 (Alias:D10)<selection=PTD4_SIG_SEL,SPI1_PCS0>
//     <4=> PTE4<selection=PTE4_SIG_SEL,SPI1_PCS0>
//     <0=> Default
#define SPI1_PCS0_PIN_SEL    0
#if SPI1_PCS0_PIN_SEL == 1
#define SPI1_PCS0_GPIO       digitalIO_PTB8
#define SPI1_PCS0_FN         2
#elif SPI1_PCS0_PIN_SEL == 2
#define SPI1_PCS0_GPIO       digitalIO_PTB10
#define SPI1_PCS0_FN         2
#elif SPI1_PCS0_PIN_SEL == 3
#define SPI1_PCS0_GPIO       digitalIO_PTD4
#define SPI1_PCS0_FN         2
#elif SPI1_PCS0_PIN_SEL == 4
#define SPI1_PCS0_GPIO       digitalIO_PTE4
#define SPI1_PCS0_FN         2
#endif

// Pin Mapping for SPI1_SCK signal
//   <o> SPI1_SCK [PTB9, PTB11, PTD5, PTE2]<name=SPI1_SCK_PIN_SEL>
//   <i> Shows which pin SPI1_SCK is mapped to
//     <0=> Disabled
//     <1=> PTB9<selection=PTB9_SIG_SEL,SPI1_SCK>
//     <2=> PTB11<selection=PTB11_SIG_SEL,SPI1_SCK>
//     <3=> PTD5 (Alias:D13, LED_GREEN)<selection=PTD5_SIG_SEL,SPI1_SCK>
//     <4=> PTE2<selection=PTE2_SIG_SEL,SPI1_SCK>
//     <0=> Default
#define SPI1_SCK_PIN_SEL     0
#if SPI1_SCK_PIN_SEL == 1
#define SPI1_SCK_GPIO        digitalIO_PTB9
#define SPI1_SCK_FN          2
#elif SPI1_SCK_PIN_SEL == 2
#define SPI1_SCK_GPIO        digitalIO_PTB11
#define SPI1_SCK_FN          2
#elif SPI1_SCK_PIN_SEL == 3
#define SPI1_SCK_GPIO        digitalIO_PTD5
#define SPI1_SCK_FN          2
#elif SPI1_SCK_PIN_SEL == 4
#define SPI1_SCK_GPIO        digitalIO_PTE2
#define SPI1_SCK_FN          2
#endif

// </h>

// <h> Timer (TPM0)

// Pin Mapping for TPM0_CH0 signal
//   <o> TPM0_CH0 [PTA3, PTE24, PTC1, PTD0]<name=TPM0_CH0_PIN_SEL>
//   <i> Shows which pin TPM0_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,TPM0_CH0>
//     <2=> PTE24 (Alias:MAG_SCL, ACC_SCL)<selection=PTE24_SIG_SEL,TPM0_CH0>
//     <3=> PTC1 (Alias:A5)<selection=PTC1_SIG_SEL,TPM0_CH0>
//     <4=> PTD0<selection=PTD0_SIG_SEL,TPM0_CH0>
//     <0=> Default
#define TPM0_CH0_PIN_SEL     0
#if TPM0_CH0_PIN_SEL == 1
#define TPM0_CH0_GPIO        digitalIO_PTA3
#define TPM0_CH0_FN          3
#elif TPM0_CH0_PIN_SEL == 2
#define TPM0_CH0_GPIO        digitalIO_PTE24
#define TPM0_CH0_FN          3
#elif TPM0_CH0_PIN_SEL == 3
#define TPM0_CH0_GPIO        digitalIO_PTC1
#define TPM0_CH0_FN          4
#elif TPM0_CH0_PIN_SEL == 4
#define TPM0_CH0_GPIO        digitalIO_PTD0
#define TPM0_CH0_FN          4
#endif

// Pin Mapping for TPM0_CH1 signal
//   <o> TPM0_CH1 [PTA4, PTE25, PTC2, PTD1]<name=TPM0_CH1_PIN_SEL>
//   <i> Shows which pin TPM0_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTA4 (Alias:D4)<selection=PTA4_SIG_SEL,TPM0_CH1>
//     <2=> PTE25 (Alias:MAG_SDA, ACC_SDA)<selection=PTE25_SIG_SEL,TPM0_CH1>
//     <3=> PTC2 (Alias:A4)<selection=PTC2_SIG_SEL,TPM0_CH1>
//     <4=> PTD1 (Alias:MAG_INT, ACC_INT2, LED_BLUE)<selection=PTD1_SIG_SEL,TPM0_CH1>
//     <4=> Default
#define TPM0_CH1_PIN_SEL     4
#if TPM0_CH1_PIN_SEL == 1
#define TPM0_CH1_GPIO        digitalIO_PTA4
#define TPM0_CH1_FN          3
#elif TPM0_CH1_PIN_SEL == 2
#define TPM0_CH1_GPIO        digitalIO_PTE25
#define TPM0_CH1_FN          3
#elif TPM0_CH1_PIN_SEL == 3
#define TPM0_CH1_GPIO        digitalIO_PTC2
#define TPM0_CH1_FN          4
#elif TPM0_CH1_PIN_SEL == 4
#define TPM0_CH1_GPIO        digitalIO_PTD1
#define TPM0_CH1_FN          4
#endif

// Pin Mapping for TPM0_CH2 signal
//   <o> TPM0_CH2 [PTA5, PTE29, PTC3, PTD2]<name=TPM0_CH2_PIN_SEL>
//   <i> Shows which pin TPM0_CH2 is mapped to
//     <0=> Disabled
//     <1=> PTA5 (Alias:D5)<selection=PTA5_SIG_SEL,TPM0_CH2>
//     <2=> PTE29 (Alias:LED_RED)<selection=PTE29_SIG_SEL,TPM0_CH2>
//     <3=> PTC3<selection=PTC3_SIG_SEL,TPM0_CH2>
//     <4=> PTD2 (Alias:D9)<selection=PTD2_SIG_SEL,TPM0_CH2>
//     <2=> Default
#define TPM0_CH2_PIN_SEL     2
#if TPM0_CH2_PIN_SEL == 1
#define TPM0_CH2_GPIO        digitalIO_PTA5
#define TPM0_CH2_FN          3
#elif TPM0_CH2_PIN_SEL == 2
#define TPM0_CH2_GPIO        digitalIO_PTE29
#define TPM0_CH2_FN          3
#elif TPM0_CH2_PIN_SEL == 3
#define TPM0_CH2_GPIO        digitalIO_PTC3
#define TPM0_CH2_FN          4
#elif TPM0_CH2_PIN_SEL == 4
#define TPM0_CH2_GPIO        digitalIO_PTD2
#define TPM0_CH2_FN          4
#endif

// Pin Mapping for TPM0_CH3 signal
//   <o> TPM0_CH3 [PTA6, PTE30, PTC4, PTD3]<name=TPM0_CH3_PIN_SEL>
//   <i> Shows which pin TPM0_CH3 is mapped to
//     <0=> Disabled
//     <1=> PTA6<selection=PTA6_SIG_SEL,TPM0_CH3>
//     <2=> PTE30<selection=PTE30_SIG_SEL,TPM0_CH3>
//     <3=> PTC4<selection=PTC4_SIG_SEL,TPM0_CH3>
//     <4=> PTD3 (Alias:D2)<selection=PTD3_SIG_SEL,TPM0_CH3>
//     <0=> Default
#define TPM0_CH3_PIN_SEL     0
#if TPM0_CH3_PIN_SEL == 1
#define TPM0_CH3_GPIO        digitalIO_PTA6
#define TPM0_CH3_FN          3
#elif TPM0_CH3_PIN_SEL == 2
#define TPM0_CH3_GPIO        digitalIO_PTE30
#define TPM0_CH3_FN          3
#elif TPM0_CH3_PIN_SEL == 3
#define TPM0_CH3_GPIO        digitalIO_PTC4
#define TPM0_CH3_FN          4
#elif TPM0_CH3_PIN_SEL == 4
#define TPM0_CH3_GPIO        digitalIO_PTD3
#define TPM0_CH3_FN          4
#endif

// Pin Mapping for TPM0_CH4 signal
//   <o> TPM0_CH4 [PTA7, PTC8, PTE31, PTD4]<name=TPM0_CH4_PIN_SEL>
//   <i> Shows which pin TPM0_CH4 is mapped to
//     <0=> Disabled
//     <1=> PTA7<selection=PTA7_SIG_SEL,TPM0_CH4>
//     <2=> PTC8 (Alias:D6)<selection=PTC8_SIG_SEL,TPM0_CH4>
//     <3=> PTE31<selection=PTE31_SIG_SEL,TPM0_CH4>
//     <4=> PTD4 (Alias:D10)<selection=PTD4_SIG_SEL,TPM0_CH4>
//     <0=> Default
#define TPM0_CH4_PIN_SEL     0
#if TPM0_CH4_PIN_SEL == 1
#define TPM0_CH4_GPIO        digitalIO_PTA7
#define TPM0_CH4_FN          3
#elif TPM0_CH4_PIN_SEL == 2
#define TPM0_CH4_GPIO        digitalIO_PTC8
#define TPM0_CH4_FN          3
#elif TPM0_CH4_PIN_SEL == 3
#define TPM0_CH4_GPIO        digitalIO_PTE31
#define TPM0_CH4_FN          3
#elif TPM0_CH4_PIN_SEL == 4
#define TPM0_CH4_GPIO        digitalIO_PTD4
#define TPM0_CH4_FN          4
#endif

// Pin Mapping for TPM0_CH5 signal
//   <o> TPM0_CH5 [PTA0, PTC9, PTE26, PTD5]<name=TPM0_CH5_PIN_SEL>
//   <i> Shows which pin TPM0_CH5 is mapped to
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,TPM0_CH5>
//     <2=> PTC9 (Alias:D7)<selection=PTC9_SIG_SEL,TPM0_CH5>
//     <3=> PTE26<selection=PTE26_SIG_SEL,TPM0_CH5>
//     <4=> PTD5 (Alias:D13, LED_GREEN)<selection=PTD5_SIG_SEL,TPM0_CH5>
//     <4=> Default
#define TPM0_CH5_PIN_SEL     4
#if TPM0_CH5_PIN_SEL == 1
#define TPM0_CH5_GPIO        digitalIO_PTA0
#define TPM0_CH5_FN          3
#elif TPM0_CH5_PIN_SEL == 2
#define TPM0_CH5_GPIO        digitalIO_PTC9
#define TPM0_CH5_FN          3
#elif TPM0_CH5_PIN_SEL == 3
#define TPM0_CH5_GPIO        digitalIO_PTE26
#define TPM0_CH5_FN          3
#elif TPM0_CH5_PIN_SEL == 4
#define TPM0_CH5_GPIO        digitalIO_PTD5
#define TPM0_CH5_FN          4
#endif

// </h>

// <h> Timer (TPM1)

// Pin Mapping for TPM1_CH0 signal
//   <o> TPM1_CH0 [PTA12, PTB0, PTE20]<name=TPM1_CH0_PIN_SEL>
//   <i> Shows which pin TPM1_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTA12 (Alias:D3)<selection=PTA12_SIG_SEL,TPM1_CH0>
//     <2=> PTB0 (Alias:A0)<selection=PTB0_SIG_SEL,TPM1_CH0>
//     <3=> PTE20<selection=PTE20_SIG_SEL,TPM1_CH0>
//     <0=> Default
#define TPM1_CH0_PIN_SEL     0
#if TPM1_CH0_PIN_SEL == 1
#define TPM1_CH0_GPIO        digitalIO_PTA12
#define TPM1_CH0_FN          3
#elif TPM1_CH0_PIN_SEL == 2
#define TPM1_CH0_GPIO        digitalIO_PTB0
#define TPM1_CH0_FN          3
#elif TPM1_CH0_PIN_SEL == 3
#define TPM1_CH0_GPIO        digitalIO_PTE20
#define TPM1_CH0_FN          3
#endif

// Pin Mapping for TPM1_CH1 signal
//   <o> TPM1_CH1 [PTA13, PTB1, PTE21]<name=TPM1_CH1_PIN_SEL>
//   <i> Shows which pin TPM1_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTA13 (Alias:D8)<selection=PTA13_SIG_SEL,TPM1_CH1>
//     <2=> PTB1 (Alias:A1)<selection=PTB1_SIG_SEL,TPM1_CH1>
//     <3=> PTE21<selection=PTE21_SIG_SEL,TPM1_CH1>
//     <0=> Default
#define TPM1_CH1_PIN_SEL     0
#if TPM1_CH1_PIN_SEL == 1
#define TPM1_CH1_GPIO        digitalIO_PTA13
#define TPM1_CH1_FN          3
#elif TPM1_CH1_PIN_SEL == 2
#define TPM1_CH1_GPIO        digitalIO_PTB1
#define TPM1_CH1_FN          3
#elif TPM1_CH1_PIN_SEL == 3
#define TPM1_CH1_GPIO        digitalIO_PTE21
#define TPM1_CH1_FN          3
#endif

// </h>

// <h> Timer (TPM2)

// Pin Mapping for TPM2_CH0 signal
//   <o> TPM2_CH0 [PTA1, PTB2, PTB18, PTE22]<name=TPM2_CH0_PIN_SEL>
//   <i> Shows which pin TPM2_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTA1 (Alias:D0)<selection=PTA1_SIG_SEL,TPM2_CH0>
//     <2=> PTB2 (Alias:A2)<selection=PTB2_SIG_SEL,TPM2_CH0>
//     <3=> PTB18<selection=PTB18_SIG_SEL,TPM2_CH0>
//     <4=> PTE22 (Alias:LIGHT_SENS)<selection=PTE22_SIG_SEL,TPM2_CH0>
//     <0=> Default
#define TPM2_CH0_PIN_SEL     0
#if TPM2_CH0_PIN_SEL == 1
#define TPM2_CH0_GPIO        digitalIO_PTA1
#define TPM2_CH0_FN          3
#elif TPM2_CH0_PIN_SEL == 2
#define TPM2_CH0_GPIO        digitalIO_PTB2
#define TPM2_CH0_FN          3
#elif TPM2_CH0_PIN_SEL == 3
#define TPM2_CH0_GPIO        digitalIO_PTB18
#define TPM2_CH0_FN          3
#elif TPM2_CH0_PIN_SEL == 4
#define TPM2_CH0_GPIO        digitalIO_PTE22
#define TPM2_CH0_FN          3
#endif

// Pin Mapping for TPM2_CH1 signal
//   <o> TPM2_CH1 [PTA2, PTB3, PTB19, PTE23]<name=TPM2_CH1_PIN_SEL>
//   <i> Shows which pin TPM2_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTA2 (Alias:D1)<selection=PTA2_SIG_SEL,TPM2_CH1>
//     <2=> PTB3 (Alias:A3)<selection=PTB3_SIG_SEL,TPM2_CH1>
//     <3=> PTB19<selection=PTB19_SIG_SEL,TPM2_CH1>
//     <4=> PTE23<selection=PTE23_SIG_SEL,TPM2_CH1>
//     <0=> Default
#define TPM2_CH1_PIN_SEL     0
#if TPM2_CH1_PIN_SEL == 1
#define TPM2_CH1_GPIO        digitalIO_PTA2
#define TPM2_CH1_FN          3
#elif TPM2_CH1_PIN_SEL == 2
#define TPM2_CH1_GPIO        digitalIO_PTB3
#define TPM2_CH1_FN          3
#elif TPM2_CH1_PIN_SEL == 3
#define TPM2_CH1_GPIO        digitalIO_PTB19
#define TPM2_CH1_FN          3
#elif TPM2_CH1_PIN_SEL == 4
#define TPM2_CH1_GPIO        digitalIO_PTE23
#define TPM2_CH1_FN          3
#endif

// </h>

// <h> Touch Sense Interface (TSI0)

// Pin Mapping for TSI0_CH0 signal
//   <o> TSI0_CH0 [PTB0]<name=TSI0_CH0_PIN_SEL>
//   <i> Shows which pin TSI0_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTB0 (Alias:A0) (reset default)<selection=PTB0_SIG_SEL,LCD_P0/ADC0_SE8/TSI0_CH0 (reset default)>
//     <2=> PTB0 (Alias:A0)<selection=PTB0_SIG_SEL,LCD_P0/ADC0_SE8/TSI0_CH0>
//     <2=> Default
#define TSI0_CH0_PIN_SEL     2
#if TSI0_CH0_PIN_SEL == 2
#define TSI0_CH0_GPIO        digitalIO_PTB0
#define TSI0_CH0_FN          0
#endif

// Pin Mapping for TSI0_CH1 signal
//   <o> TSI0_CH1 [PTA0]<name=TSI0_CH1_PIN_SEL>
//   <i> Shows which pin TSI0_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,TSI0_CH1>
//     <0=> Default
#define TSI0_CH1_PIN_SEL     0
#if TSI0_CH1_PIN_SEL == 1
#define TSI0_CH1_GPIO        digitalIO_PTA0
#define TSI0_CH1_FN          0
#endif

// Pin Mapping for TSI0_CH2 signal
//   <o> TSI0_CH2 [PTA1]<name=TSI0_CH2_PIN_SEL>
//   <i> Shows which pin TSI0_CH2 is mapped to
//     <0=> Disabled
//     <1=> PTA1 (Alias:D0)<selection=PTA1_SIG_SEL,TSI0_CH2>
//     <0=> Default
#define TSI0_CH2_PIN_SEL     0
#if TSI0_CH2_PIN_SEL == 1
#define TSI0_CH2_GPIO        digitalIO_PTA1
#define TSI0_CH2_FN          0
#endif

// Pin Mapping for TSI0_CH3 signal
//   <o> TSI0_CH3 [PTA2]<name=TSI0_CH3_PIN_SEL>
//   <i> Shows which pin TSI0_CH3 is mapped to
//     <0=> Disabled
//     <1=> PTA2 (Alias:D1)<selection=PTA2_SIG_SEL,TSI0_CH3>
//     <0=> Default
#define TSI0_CH3_PIN_SEL     0
#if TSI0_CH3_PIN_SEL == 1
#define TSI0_CH3_GPIO        digitalIO_PTA2
#define TSI0_CH3_FN          0
#endif

// Pin Mapping for TSI0_CH4 signal
//   <o> TSI0_CH4 [PTA3]<name=TSI0_CH4_PIN_SEL>
//   <i> Shows which pin TSI0_CH4 is mapped to
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,TSI0_CH4>
//     <0=> Default
#define TSI0_CH4_PIN_SEL     0
#if TSI0_CH4_PIN_SEL == 1
#define TSI0_CH4_GPIO        digitalIO_PTA3
#define TSI0_CH4_FN          0
#endif

// Pin Mapping for TSI0_CH5 signal
//   <o> TSI0_CH5 [PTA4]<name=TSI0_CH5_PIN_SEL>
//   <i> Shows which pin TSI0_CH5 is mapped to
//     <0=> Disabled
//     <1=> PTA4 (Alias:D4)<selection=PTA4_SIG_SEL,TSI0_CH5>
//     <0=> Default
#define TSI0_CH5_PIN_SEL     0
#if TSI0_CH5_PIN_SEL == 1
#define TSI0_CH5_GPIO        digitalIO_PTA4
#define TSI0_CH5_FN          0
#endif

// Pin Mapping for TSI0_CH6 signal
//   <o> TSI0_CH6 [PTB1]<name=TSI0_CH6_PIN_SEL>
//   <i> Shows which pin TSI0_CH6 is mapped to
//     <0=> Disabled
//     <1=> PTB1 (Alias:A1) (reset default)<selection=PTB1_SIG_SEL,LCD_P1/ADC0_SE9/TSI0_CH6 (reset default)>
//     <2=> PTB1 (Alias:A1)<selection=PTB1_SIG_SEL,LCD_P1/ADC0_SE9/TSI0_CH6>
//     <2=> Default
#define TSI0_CH6_PIN_SEL     2
#if TSI0_CH6_PIN_SEL == 2
#define TSI0_CH6_GPIO        digitalIO_PTB1
#define TSI0_CH6_FN          0
#endif

// Pin Mapping for TSI0_CH7 signal
//   <o> TSI0_CH7 [PTB2]<name=TSI0_CH7_PIN_SEL>
//   <i> Shows which pin TSI0_CH7 is mapped to
//     <0=> Disabled
//     <1=> PTB2 (Alias:A2) (reset default)<selection=PTB2_SIG_SEL,LCD_P2/ADC0_SE12/TSI0_CH7 (reset default)>
//     <2=> PTB2 (Alias:A2)<selection=PTB2_SIG_SEL,LCD_P2/ADC0_SE12/TSI0_CH7>
//     <2=> Default
#define TSI0_CH7_PIN_SEL     2
#if TSI0_CH7_PIN_SEL == 2
#define TSI0_CH7_GPIO        digitalIO_PTB2
#define TSI0_CH7_FN          0
#endif

// Pin Mapping for TSI0_CH8 signal
//   <o> TSI0_CH8 [PTB3]<name=TSI0_CH8_PIN_SEL>
//   <i> Shows which pin TSI0_CH8 is mapped to
//     <0=> Disabled
//     <1=> PTB3 (Alias:A3) (reset default)<selection=PTB3_SIG_SEL,LCD_P3/ADC0_SE13/TSI0_CH8 (reset default)>
//     <2=> PTB3 (Alias:A3)<selection=PTB3_SIG_SEL,LCD_P3/ADC0_SE13/TSI0_CH8>
//     <2=> Default
#define TSI0_CH8_PIN_SEL     2
#if TSI0_CH8_PIN_SEL == 2
#define TSI0_CH8_GPIO        digitalIO_PTB3
#define TSI0_CH8_FN          0
#endif

// Pin Mapping for TSI0_CH9 signal
//   <o> TSI0_CH9 [PTB16]<name=TSI0_CH9_PIN_SEL>
//   <i> Shows which pin TSI0_CH9 is mapped to
//     <0=> Disabled
//     <1=> PTB16 (reset default)<selection=PTB16_SIG_SEL,LCD_P12/TSI0_CH9 (reset default)>
//     <2=> PTB16<selection=PTB16_SIG_SEL,LCD_P12/TSI0_CH9>
//     <1=> Default
#define TSI0_CH9_PIN_SEL     1
#if TSI0_CH9_PIN_SEL == 2
#define TSI0_CH9_GPIO        digitalIO_PTB16
#define TSI0_CH9_FN          0
#endif

// Pin Mapping for TSI0_CH10 signal
//   <o> TSI0_CH10 [PTB17]<name=TSI0_CH10_PIN_SEL>
//   <i> Shows which pin TSI0_CH10 is mapped to
//     <0=> Disabled
//     <1=> PTB17 (reset default)<selection=PTB17_SIG_SEL,LCD_P13/TSI0_CH10 (reset default)>
//     <2=> PTB17<selection=PTB17_SIG_SEL,LCD_P13/TSI0_CH10>
//     <1=> Default
#define TSI0_CH10_PIN_SEL    1
#if TSI0_CH10_PIN_SEL == 2
#define TSI0_CH10_GPIO       digitalIO_PTB17
#define TSI0_CH10_FN         0
#endif

// Pin Mapping for TSI0_CH11 signal
//   <o> TSI0_CH11 [PTB18]<name=TSI0_CH11_PIN_SEL>
//   <i> Shows which pin TSI0_CH11 is mapped to
//     <0=> Disabled
//     <1=> PTB18 (reset default)<selection=PTB18_SIG_SEL,LCD_P14/TSI0_CH11 (reset default)>
//     <2=> PTB18<selection=PTB18_SIG_SEL,LCD_P14/TSI0_CH11>
//     <1=> Default
#define TSI0_CH11_PIN_SEL    1
#if TSI0_CH11_PIN_SEL == 2
#define TSI0_CH11_GPIO       digitalIO_PTB18
#define TSI0_CH11_FN         0
#endif

// Pin Mapping for TSI0_CH12 signal
//   <o> TSI0_CH12 [PTB19]<name=TSI0_CH12_PIN_SEL>
//   <i> Shows which pin TSI0_CH12 is mapped to
//     <0=> Disabled
//     <1=> PTB19 (reset default)<selection=PTB19_SIG_SEL,LCD_P15/TSI0_CH12 (reset default)>
//     <2=> PTB19<selection=PTB19_SIG_SEL,LCD_P15/TSI0_CH12>
//     <1=> Default
#define TSI0_CH12_PIN_SEL    1
#if TSI0_CH12_PIN_SEL == 2
#define TSI0_CH12_GPIO       digitalIO_PTB19
#define TSI0_CH12_FN         0
#endif

// Pin Mapping for TSI0_CH13 signal
//   <o> TSI0_CH13 [PTC0]<name=TSI0_CH13_PIN_SEL>
//   <i> Shows which pin TSI0_CH13 is mapped to
//     <0=> Disabled
//     <1=> PTC0 (reset default)<selection=PTC0_SIG_SEL,LCD_P20/ADC0_SE14/TSI0_CH13 (reset default)>
//     <2=> PTC0<selection=PTC0_SIG_SEL,LCD_P20/ADC0_SE14/TSI0_CH13>
//     <1=> Default
#define TSI0_CH13_PIN_SEL    1
#if TSI0_CH13_PIN_SEL == 2
#define TSI0_CH13_GPIO       digitalIO_PTC0
#define TSI0_CH13_FN         0
#endif

// Pin Mapping for TSI0_CH14 signal
//   <o> TSI0_CH14 [PTC1]<name=TSI0_CH14_PIN_SEL>
//   <i> Shows which pin TSI0_CH14 is mapped to
//     <0=> Disabled
//     <1=> PTC1 (Alias:A5) (reset default)<selection=PTC1_SIG_SEL,LCD_P21/ADC0_SE15/TSI0_CH14 (reset default)>
//     <2=> PTC1 (Alias:A5)<selection=PTC1_SIG_SEL,LCD_P21/ADC0_SE15/TSI0_CH14>
//     <2=> Default
#define TSI0_CH14_PIN_SEL    2
#if TSI0_CH14_PIN_SEL == 2
#define TSI0_CH14_GPIO       digitalIO_PTC1
#define TSI0_CH14_FN         0
#endif

// Pin Mapping for TSI0_CH15 signal
//   <o> TSI0_CH15 [PTC2]<name=TSI0_CH15_PIN_SEL>
//   <i> Shows which pin TSI0_CH15 is mapped to
//     <0=> Disabled
//     <1=> PTC2 (Alias:A4) (reset default)<selection=PTC2_SIG_SEL,LCD_P22/ADC0_SE11/TSI0_CH15 (reset default)>
//     <2=> PTC2 (Alias:A4)<selection=PTC2_SIG_SEL,LCD_P22/ADC0_SE11/TSI0_CH15>
//     <2=> Default
#define TSI0_CH15_PIN_SEL    2
#if TSI0_CH15_PIN_SEL == 2
#define TSI0_CH15_GPIO       digitalIO_PTC2
#define TSI0_CH15_FN         0
#endif

// </h>

// <h> Universal Asynchronous Rx/Tx (UART0)

// Pin Mapping for UART0_RX signal
//   <o> UART0_RX [PTA1, PTA15, PTB16, PTD6, PTE21]<name=UART0_RX_PIN_SEL>
//   <i> Shows which pin UART0_RX is mapped to
//     <0=> Disabled
//     <1=> PTA1 (Alias:D0)<selection=PTA1_SIG_SEL,UART0_RX>
//     <2=> PTA15<selection=PTA15_SIG_SEL,UART0_RX>
//     <3=> PTB16<selection=PTB16_SIG_SEL,UART0_RX>
//     <4=> PTD6 (Alias:D11)<selection=PTD6_SIG_SEL,UART0_RX>
//     <5=> PTE21<selection=PTE21_SIG_SEL,UART0_RX>
//     <0=> Default
#define UART0_RX_PIN_SEL     0
#if UART0_RX_PIN_SEL == 1
#define UART0_RX_GPIO        digitalIO_PTA1
#define UART0_RX_FN          2
#elif UART0_RX_PIN_SEL == 2
#define UART0_RX_GPIO        digitalIO_PTA15
#define UART0_RX_FN          3
#elif UART0_RX_PIN_SEL == 3
#define UART0_RX_GPIO        digitalIO_PTB16
#define UART0_RX_FN          3
#elif UART0_RX_PIN_SEL == 4
#define UART0_RX_GPIO        digitalIO_PTD6
#define UART0_RX_FN          3
#elif UART0_RX_PIN_SEL == 5
#define UART0_RX_GPIO        digitalIO_PTE21
#define UART0_RX_FN          4
#endif

// Pin Mapping for UART0_TX signal
//   <o> UART0_TX [PTA2, PTA14, PTB17, PTD7, PTE20]<name=UART0_TX_PIN_SEL>
//   <i> Shows which pin UART0_TX is mapped to
//     <0=> Disabled
//     <1=> PTA2 (Alias:D1)<selection=PTA2_SIG_SEL,UART0_TX>
//     <2=> PTA14<selection=PTA14_SIG_SEL,UART0_TX>
//     <3=> PTB17<selection=PTB17_SIG_SEL,UART0_TX>
//     <4=> PTD7 (Alias:D12)<selection=PTD7_SIG_SEL,UART0_TX>
//     <5=> PTE20<selection=PTE20_SIG_SEL,UART0_TX>
//     <0=> Default
#define UART0_TX_PIN_SEL     0
#if UART0_TX_PIN_SEL == 1
#define UART0_TX_GPIO        digitalIO_PTA2
#define UART0_TX_FN          2
#elif UART0_TX_PIN_SEL == 2
#define UART0_TX_GPIO        digitalIO_PTA14
#define UART0_TX_FN          3
#elif UART0_TX_PIN_SEL == 3
#define UART0_TX_GPIO        digitalIO_PTB17
#define UART0_TX_FN          3
#elif UART0_TX_PIN_SEL == 4
#define UART0_TX_GPIO        digitalIO_PTD7
#define UART0_TX_FN          3
#elif UART0_TX_PIN_SEL == 5
#define UART0_TX_GPIO        digitalIO_PTE20
#define UART0_TX_FN          4
#endif

// </h>

// <h> Universal Asynchronous Rx/Tx (UART1)

// Pin Mapping for UART1_RX signal
//   <o> UART1_RX [PTA18, PTC3, PTE1]<name=UART1_RX_PIN_SEL>
//   <i> Shows which pin UART1_RX is mapped to
//     <0=> Disabled
//     <1=> PTA18<selection=PTA18_SIG_SEL,UART1_RX>
//     <2=> PTC3<selection=PTC3_SIG_SEL,UART1_RX>
//     <3=> PTE1 (Alias:D15)<selection=PTE1_SIG_SEL,UART1_RX>
//     <0=> Default
#define UART1_RX_PIN_SEL     0
#if UART1_RX_PIN_SEL == 1
#define UART1_RX_GPIO        digitalIO_PTA18
#define UART1_RX_FN          3
#elif UART1_RX_PIN_SEL == 2
#define UART1_RX_GPIO        digitalIO_PTC3
#define UART1_RX_FN          3
#elif UART1_RX_PIN_SEL == 3
#define UART1_RX_GPIO        digitalIO_PTE1
#define UART1_RX_FN          3
#endif

// Pin Mapping for UART1_TX signal
//   <o> UART1_TX [PTA19, PTC4, PTE0]<name=UART1_TX_PIN_SEL>
//   <i> Shows which pin UART1_TX is mapped to
//     <0=> Disabled
//     <1=> PTA19<selection=PTA19_SIG_SEL,UART1_TX>
//     <2=> PTC4<selection=PTC4_SIG_SEL,UART1_TX>
//     <3=> PTE0 (Alias:D14)<selection=PTE0_SIG_SEL,UART1_TX>
//     <0=> Default
#define UART1_TX_PIN_SEL     0
#if UART1_TX_PIN_SEL == 1
#define UART1_TX_GPIO        digitalIO_PTA19
#define UART1_TX_FN          3
#elif UART1_TX_PIN_SEL == 2
#define UART1_TX_GPIO        digitalIO_PTC4
#define UART1_TX_FN          3
#elif UART1_TX_PIN_SEL == 3
#define UART1_TX_GPIO        digitalIO_PTE0
#define UART1_TX_FN          3
#endif

// </h>

// <h> Universal Asynchronous Rx/Tx (UART2)

// Pin Mapping for UART2_RX signal
//   <o> UART2_RX [PTD2, PTD4, PTE17, PTE23]<name=UART2_RX_PIN_SEL>
//   <i> Shows which pin UART2_RX is mapped to
//     <0=> Disabled
//     <1=> PTD2 (Alias:D9)<selection=PTD2_SIG_SEL,UART2_RX>
//     <2=> PTD4 (Alias:D10)<selection=PTD4_SIG_SEL,UART2_RX>
//     <3=> PTE17<selection=PTE17_SIG_SEL,UART2_RX>
//     <4=> PTE23<selection=PTE23_SIG_SEL,UART2_RX>
//     <0=> Default
#define UART2_RX_PIN_SEL     0
#if UART2_RX_PIN_SEL == 1
#define UART2_RX_GPIO        digitalIO_PTD2
#define UART2_RX_FN          3
#elif UART2_RX_PIN_SEL == 2
#define UART2_RX_GPIO        digitalIO_PTD4
#define UART2_RX_FN          3
#elif UART2_RX_PIN_SEL == 3
#define UART2_RX_GPIO        digitalIO_PTE17
#define UART2_RX_FN          3
#elif UART2_RX_PIN_SEL == 4
#define UART2_RX_GPIO        digitalIO_PTE23
#define UART2_RX_FN          4
#endif

// Pin Mapping for UART2_TX signal
//   <o> UART2_TX [PTD3, PTD5, PTE16, PTE22]<name=UART2_TX_PIN_SEL>
//   <i> Shows which pin UART2_TX is mapped to
//     <0=> Disabled
//     <1=> PTD3 (Alias:D2)<selection=PTD3_SIG_SEL,UART2_TX>
//     <2=> PTD5 (Alias:D13, LED_GREEN)<selection=PTD5_SIG_SEL,UART2_TX>
//     <3=> PTE16<selection=PTE16_SIG_SEL,UART2_TX>
//     <4=> PTE22 (Alias:LIGHT_SENS)<selection=PTE22_SIG_SEL,UART2_TX>
//     <0=> Default
#define UART2_TX_PIN_SEL     0
#if UART2_TX_PIN_SEL == 1
#define UART2_TX_GPIO        digitalIO_PTD3
#define UART2_TX_FN          3
#elif UART2_TX_PIN_SEL == 2
#define UART2_TX_GPIO        digitalIO_PTD5
#define UART2_TX_FN          3
#elif UART2_TX_PIN_SEL == 3
#define UART2_TX_GPIO        digitalIO_PTE16
#define UART2_TX_FN          3
#elif UART2_TX_PIN_SEL == 4
#define UART2_TX_GPIO        digitalIO_PTE22
#define UART2_TX_FN          4
#endif

// </h>

// <h> Universal Serial Bus

// Pin Mapping for USB_CLKIN signal
//   <o> USB_CLKIN [PTA5, PTE26]<name=USB_CLKIN_PIN_SEL>
//   <i> Shows which pin USB_CLKIN is mapped to
//     <0=> Disabled
//     <1=> PTA5 (Alias:D5)<selection=PTA5_SIG_SEL,USB_CLKIN>
//     <2=> PTE26<selection=PTE26_SIG_SEL,USB_CLKIN>
//     <0=> Default
#define USB_CLKIN_PIN_SEL    0
#if USB_CLKIN_PIN_SEL == 1
#define USB_CLKIN_GPIO       digitalIO_PTA5
#define USB_CLKIN_FN         2
#elif USB_CLKIN_PIN_SEL == 2
#define USB_CLKIN_GPIO       digitalIO_PTE26
#define USB_CLKIN_FN         7
#endif

// Pin Mapping for USB_SOF_OUT signal
//   <o> USB_SOF_OUT [PTC7, PTC0, PTE6]<name=USB_SOF_OUT_PIN_SEL>
//   <i> Shows which pin USB_SOF_OUT is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,USB_SOF_OUT>
//     <2=> PTC0<selection=PTC0_SIG_SEL,USB_SOF_OUT>
//     <3=> PTE6<selection=PTE6_SIG_SEL,USB_SOF_OUT>
//     <0=> Default
#define USB_SOF_OUT_PIN_SEL  0
#if USB_SOF_OUT_PIN_SEL == 1
#define USB_SOF_OUT_GPIO     digitalIO_PTC7
#define USB_SOF_OUT_FN       3
#elif USB_SOF_OUT_PIN_SEL == 2
#define USB_SOF_OUT_GPIO     digitalIO_PTC0
#define USB_SOF_OUT_FN       4
#elif USB_SOF_OUT_PIN_SEL == 3
#define USB_SOF_OUT_GPIO     digitalIO_PTE6
#define USB_SOF_OUT_FN       5
#endif

// </h>

// </e>

//-------- <<< end of configuration section >>> -----------------  

#define FIXED_ADC_FN             0                    // Fixed ADC Multiplexing value
#define FIXED_GPIO_FN            1                    // Fixed GPIO Multiplexing value
#define FIXED_PORT_CLOCK_REG     SCGC5                // Fixed PORT Clock
#define ADC0_CLOCK_REG       SCGC6
#define ADC0_CLOCK_MASK      SIM_SCGC6_ADC0_MASK
#define CMP0_CLOCK_REG       SCGC4
#define CMP0_CLOCK_MASK      SIM_SCGC4_CMP0_MASK
#define DAC0_CLOCK_REG       SCGC6
#define DAC0_CLOCK_MASK      SIM_SCGC6_DAC0_MASK
#define DMA_CLOCK_REG        SCGC7
#define DMA_CLOCK_MASK       SIM_SCGC7_DMA_MASK
#define DMAMUX_CLOCK_REG     SCGC6
#define DMAMUX_CLOCK_MASK    SIM_SCGC6_DMAMUX_MASK
#define I2C0_CLOCK_REG       SCGC4
#define I2C0_CLOCK_MASK      SIM_SCGC4_I2C0_MASK
#define I2C1_CLOCK_REG       SCGC4
#define I2C1_CLOCK_MASK      SIM_SCGC4_I2C1_MASK
#define I2S0_CLOCK_REG       SCGC6
#define I2S0_CLOCK_MASK      SIM_SCGC6_I2S0_MASK
#define LPTMR0_CLOCK_REG     SCGC5
#define LPTMR0_CLOCK_MASK    SIM_SCGC5_LPTMR_MASK
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
#define SLCD_CLOCK_REG       SCGC5
#define SLCD_CLOCK_MASK      SIM_SCGC5_SLCD_MASK
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
#define TSI_CLOCK_REG        SCGC5
#define TSI_CLOCK_MASK       SIM_SCGC5_TSI_MASK
#define UART0_CLOCK_REG      SCGC4
#define UART0_CLOCK_MASK     SIM_SCGC4_UART0_MASK
#define UART1_CLOCK_REG      SCGC4
#define UART1_CLOCK_MASK     SIM_SCGC4_UART1_MASK
#define UART2_CLOCK_REG      SCGC4
#define UART2_CLOCK_MASK     SIM_SCGC4_UART2_MASK
#define UART3_CLOCK_REG      SCGC4
#define UART3_CLOCK_MASK     SIM_SCGC4_UART3_MASK
#define USB_CLOCK_REG        SCGC4
#define USB_CLOCK_MASK       SIM_SCGC4_USB_MASK
#define PORT_CLOCK_REG       SCGC5


#endif /* PIN_MAPPING_H_ */
