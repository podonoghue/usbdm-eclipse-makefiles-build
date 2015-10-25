/**
 * @file      pin_mapping.h (derived from pin_mapping-MK20D5.h)
 * @version   1.0.0
 * @brief     Pin declarations for MK20D5
 */

#ifndef PIN_MAPPING_H_
#define PIN_MAPPING_H_

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
#define FTM0_SC              (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0))

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
#define FTM1_SC              (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0))

// </h>

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
//   <i>  peripherals are configured or during reset initialisation
//     <0=> Pins mapped on demand
//     <1=> All pins are mapped on reset
#define DO_MAP_PINS_ON_RESET 0                   

// Pin peripheral signal mapping
//   <e> Mapping by Pin 
//   <i> This allows the mapping of peripheral functions to pins
//   <i> to be controlled by individual pin
//     <0=> Disabled
//     <1=> Enabled
#define MAP_BY_PINS_ENABLED  0                   

// Signal mapping for ADC0_DM0 pin
//   <o> ADC0_DM0 [ADC0_DM0]<name=ADC0_DM0_SIG_SEL><constant>
//   <i> ADC0_DM0 has no pin-mapping hardware
//     <-3=> ADC0_DM0 (fixed)<selection=ADC0_DM0_PIN_SEL,ADC0_DM0>
#define ADC0_DM0_SIG_SEL     -3                  

// Signal mapping for ADC0_DM3 pin
//   <o> ADC0_DM3 [ADC0_DM3]<name=ADC0_DM3_SIG_SEL><constant>
//   <i> ADC0_DM3 has no pin-mapping hardware
//     <-3=> ADC0_DM3 (fixed)<selection=ADC0_DM3_PIN_SEL,ADC0_DM3>
#define ADC0_DM3_SIG_SEL     -3                  

// Signal mapping for ADC0_DP0 pin
//   <o> ADC0_DP0 [ADC0_DP0]<name=ADC0_DP0_SIG_SEL><constant>
//   <i> ADC0_DP0 has no pin-mapping hardware
//     <-3=> ADC0_DP0 (fixed)<selection=ADC0_DP0_PIN_SEL,ADC0_DP0>
#define ADC0_DP0_SIG_SEL     -3                  

// Signal mapping for ADC0_DP3 pin
//   <o> ADC0_DP3 [ADC0_DP3]<name=ADC0_DP3_SIG_SEL><constant>
//   <i> ADC0_DP3 has no pin-mapping hardware
//     <-3=> ADC0_DP3 (fixed)<selection=ADC0_DP3_PIN_SEL,ADC0_DP3>
#define ADC0_DP3_SIG_SEL     -3                  

// Signal mapping for ADC0_SE23 pin
//   <o> ADC0_SE23 [ADC0_SE23/CMP1_IN3]<name=ADC0_SE23_SIG_SEL><constant>
//   <i> ADC0_SE23 has no pin-mapping hardware
//     <-3=> ADC0_SE23/CMP1_IN3 (fixed)<selection=ADC0_SE23_PIN_SEL,ADC0_SE23>
#define ADC0_SE23_SIG_SEL    -3                  

// Signal mapping for PTA0 pin
//   <o> PTA0 [TSI0_CH1, GPIOA_0, UART0_CTS_b/UART0_COL_b, FTM0_CH5, JTAG_TCLK/SWD_CLK]<name=PTA0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA0 pin
//     <-2=> JTAG_TCLK/SWD_CLK (reset default)
//     <0=> TSI0_CH1
//     <1=> GPIOA_0<selection=GPIOA_0_PIN_SEL,PTA0>
//     <2=> UART0_CTS_b/UART0_COL_b
//     <3=> FTM0_CH5<selection=FTM0_CH5_PIN_SEL,PTA0>
//     <7=> JTAG_TCLK/SWD_CLK
//     <-2=> Default
#define PTA0_SIG_SEL         -2                  

// Signal mapping for PTA1 pin
//   <o> PTA1 (Alias:D5) [TSI0_CH2, GPIOA_1, UART0_RX, FTM0_CH6, JTAG_TDI]<name=PTA1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA1 pin
//     <-2=> JTAG_TDI (reset default)
//     <0=> TSI0_CH2
//     <1=> GPIOA_1<selection=GPIOA_1_PIN_SEL,PTA1>
//     <2=> UART0_RX
//     <3=> FTM0_CH6<selection=FTM0_CH6_PIN_SEL,PTA1>
//     <7=> JTAG_TDI
//     <1=> Default
#define PTA1_SIG_SEL         1                   

// Signal mapping for PTA2 pin
//   <o> PTA2 (Alias:D9, LED_BLUE) [TSI0_CH3, GPIOA_2, UART0_TX, FTM0_CH7, JTAG_TDO/TRACE_SWO]<name=PTA2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA2 pin
//     <-2=> JTAG_TDO/TRACE_SWO (reset default)
//     <0=> TSI0_CH3
//     <1=> GPIOA_2<selection=GPIOA_2_PIN_SEL,PTA2>
//     <2=> UART0_TX
//     <3=> FTM0_CH7<selection=FTM0_CH7_PIN_SEL,PTA2>
//     <7=> JTAG_TDO/TRACE_SWO
//     <1=> Default
#define PTA2_SIG_SEL         1                   

// Signal mapping for PTA3 pin
//   <o> PTA3 [TSI0_CH4, GPIOA_3, UART0_RTS_b, FTM0_CH0, JTAG_TMS/SWD_DIO]<name=PTA3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA3 pin
//     <-2=> JTAG_TMS/SWD_DIO (reset default)
//     <0=> TSI0_CH4
//     <1=> GPIOA_3<selection=GPIOA_3_PIN_SEL,PTA3>
//     <2=> UART0_RTS_b
//     <3=> FTM0_CH0<selection=FTM0_CH0_PIN_SEL,PTA3>
//     <7=> JTAG_TMS/SWD_DIO
//     <-2=> Default
#define PTA3_SIG_SEL         -2                  

// Signal mapping for PTA4 pin
//   <o> PTA4 (Alias:D21) [TSI0_CH5, GPIOA_4/LLWU_P3, FTM0_CH1, NMI_b]<name=PTA4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA4 pin
//     <-2=> NMI_b (reset default)
//     <0=> TSI0_CH5
//     <1=> GPIOA_4/LLWU_P3<selection=GPIOA_4_PIN_SEL,PTA4>
//     <3=> FTM0_CH1<selection=FTM0_CH1_PIN_SEL,PTA4>
//     <7=> NMI_b
//     <-2=> Default
#define PTA4_SIG_SEL         -2                  

// Signal mapping for PTA5 pin
//   <o> PTA5 (Alias:D2) [GPIOA_5, USB_CLKIN, FTM0_CH2, I2S0_TX_BCLK, JTAG_TRST_b]<name=PTA5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA5 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_5<selection=GPIOA_5_PIN_SEL,PTA5>
//     <2=> USB_CLKIN
//     <3=> FTM0_CH2<selection=FTM0_CH2_PIN_SEL,PTA5>
//     <6=> I2S0_TX_BCLK<selection=I2S0_TX_BCLK_PIN_SEL,PTA5>
//     <7=> JTAG_TRST_b
//     <1=> Default
#define PTA5_SIG_SEL         1                   

// Signal mapping for PTA12 pin
//   <o> PTA12 (Alias:D8) [GPIOA_12, FTM1_CH0, I2S0_TXD0, FTM1_QD_PHA]<name=PTA12_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA12 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_12<selection=GPIOA_12_PIN_SEL,PTA12>
//     <3=> FTM1_CH0<selection=FTM1_CH0_PIN_SEL,PTA12>
//     <6=> I2S0_TXD0<selection=I2S0_TXD0_PIN_SEL,PTA12>
//     <7=> FTM1_QD_PHA
//     <1=> Default
#define PTA12_SIG_SEL        1                   

// Signal mapping for PTA13 pin
//   <o> PTA13 (Alias:D24) [GPIOA_13/LLWU_P4, FTM1_CH1, I2S0_TX_FS, FTM1_QD_PHB]<name=PTA13_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA13 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_13/LLWU_P4<selection=GPIOA_13_PIN_SEL,PTA13>
//     <3=> FTM1_CH1<selection=FTM1_CH1_PIN_SEL,PTA13>
//     <6=> I2S0_TX_FS<selection=I2S0_TX_FS_PIN_SEL,PTA13>
//     <7=> FTM1_QD_PHB
//     <1=> Default
#define PTA13_SIG_SEL        1                   

// Signal mapping for PTA18 pin
//   <o> PTA18 [EXTAL0, GPIOA_18, FTM0_FLT2, FTM0_CLKIN0/FTM1_CLKIN0]<name=PTA18_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA18 pin
//     <-2=> EXTAL0 (reset default)
//     <0=> EXTAL0
//     <1=> GPIOA_18<selection=GPIOA_18_PIN_SEL,PTA18>
//     <3=> FTM0_FLT2
//     <4=> FTM0_CLKIN0/FTM1_CLKIN0
//     <-2=> Default
#define PTA18_SIG_SEL        -2                  

// Signal mapping for PTA19 pin
//   <o> PTA19 [XTAL0, GPIOA_19, FTM1_FLT0, FTM0_CLKIN1/FTM1_CLKIN1, LPTMR0_ALT1]<name=PTA19_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA19 pin
//     <-2=> XTAL0 (reset default)
//     <0=> XTAL0
//     <1=> GPIOA_19<selection=GPIOA_19_PIN_SEL,PTA19>
//     <3=> FTM1_FLT0
//     <4=> FTM0_CLKIN1/FTM1_CLKIN1
//     <6=> LPTMR0_ALT1<selection=LPTMR0_ALT1_PIN_SEL,PTA19>
//     <-2=> Default
#define PTA19_SIG_SEL        -2                  

// Signal mapping for PTB0 pin
//   <o> PTB0 (Alias:A5, ACC_SCL) [ADC0_SE8/TSI0_CH0, GPIOB_0/LLWU_P5, I2C0_SCL, FTM1_CH0, FTM1_QD_PHA]<name=PTB0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB0 pin
//     <-2=> ADC0_SE8/TSI0_CH0 (reset default)<selection=ADC0_SE8_PIN_SEL,PTB0>
//     <0=> ADC0_SE8/TSI0_CH0<selection=ADC0_SE8_PIN_SEL,PTB0>
//     <1=> GPIOB_0/LLWU_P5<selection=GPIOB_0_PIN_SEL,PTB0>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTB0>
//     <3=> FTM1_CH0<selection=FTM1_CH0_PIN_SEL,PTB0>
//     <6=> FTM1_QD_PHA
//     <2=> Default
#define PTB0_SIG_SEL         2                   

// Signal mapping for PTB1 pin
//   <o> PTB1 (Alias:A4, ACC_SDA) [ADC0_SE9/TSI0_CH6, GPIOB_1, I2C0_SDA, FTM1_CH1, FTM1_QD_PHB]<name=PTB1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB1 pin
//     <-2=> ADC0_SE9/TSI0_CH6 (reset default)<selection=ADC0_SE9_PIN_SEL,PTB1>
//     <0=> ADC0_SE9/TSI0_CH6<selection=ADC0_SE9_PIN_SEL,PTB1>
//     <1=> GPIOB_1<selection=GPIOB_1_PIN_SEL,PTB1>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTB1>
//     <3=> FTM1_CH1<selection=FTM1_CH1_PIN_SEL,PTB1>
//     <6=> FTM1_QD_PHB
//     <2=> Default
#define PTB1_SIG_SEL         2                   

// Signal mapping for PTB2 pin
//   <o> PTB2 (Alias:D15) [ADC0_SE12/TSI0_CH7, GPIOB_2, I2C0_SCL, UART0_RTS_b, FTM0_FLT3]<name=PTB2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB2 pin
//     <-2=> ADC0_SE12/TSI0_CH7 (reset default)<selection=ADC0_SE12_PIN_SEL,PTB2>
//     <0=> ADC0_SE12/TSI0_CH7<selection=ADC0_SE12_PIN_SEL,PTB2>
//     <1=> GPIOB_2<selection=GPIOB_2_PIN_SEL,PTB2>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTB2>
//     <3=> UART0_RTS_b
//     <6=> FTM0_FLT3
//     <1=> Default
#define PTB2_SIG_SEL         1                   

// Signal mapping for PTB3 pin
//   <o> PTB3 (Alias:D14) [ADC0_SE13/TSI0_CH8, GPIOB_3, I2C0_SDA, UART0_CTS_b/UART0_COL_b, FTM0_FLT0]<name=PTB3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB3 pin
//     <-2=> ADC0_SE13/TSI0_CH8 (reset default)<selection=ADC0_SE13_PIN_SEL,PTB3>
//     <0=> ADC0_SE13/TSI0_CH8<selection=ADC0_SE13_PIN_SEL,PTB3>
//     <1=> GPIOB_3<selection=GPIOB_3_PIN_SEL,PTB3>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTB3>
//     <3=> UART0_CTS_b/UART0_COL_b
//     <6=> FTM0_FLT0
//     <1=> Default
#define PTB3_SIG_SEL         1                   

// Signal mapping for PTB16 pin
//   <o> PTB16 [TSI0_CH9, GPIOB_16, UART0_RX, EWM_IN]<name=PTB16_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB16 pin
//     <-2=> GPIOB_16 (reset default)<selection=GPIOB_16_PIN_SEL,PTB16>
//     <0=> TSI0_CH9
//     <1=> GPIOB_16<selection=GPIOB_16_PIN_SEL,PTB16>
//     <3=> UART0_RX
//     <6=> EWM_IN
//     <3=> Default
#define PTB16_SIG_SEL        3                   

// Signal mapping for PTB17 pin
//   <o> PTB17 [TSI0_CH10, GPIOB_17, UART0_TX, EWM_OUT_b]<name=PTB17_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB17 pin
//     <-2=> GPIOB_17 (reset default)<selection=GPIOB_17_PIN_SEL,PTB17>
//     <0=> TSI0_CH10
//     <1=> GPIOB_17<selection=GPIOB_17_PIN_SEL,PTB17>
//     <3=> UART0_TX
//     <6=> EWM_OUT_b
//     <3=> Default
#define PTB17_SIG_SEL        3                   

// Signal mapping for PTB18 pin
//   <o> PTB18 [TSI0_CH11, GPIOB_18, I2S0_TX_BCLK]<name=PTB18_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB18 pin
//     <-2=> GPIOB_18 (reset default)<selection=GPIOB_18_PIN_SEL,PTB18>
//     <0=> TSI0_CH11
//     <1=> GPIOB_18<selection=GPIOB_18_PIN_SEL,PTB18>
//     <4=> I2S0_TX_BCLK<selection=I2S0_TX_BCLK_PIN_SEL,PTB18>
//     <1=> Default
#define PTB18_SIG_SEL        1                   

// Signal mapping for PTB19 pin
//   <o> PTB19 [TSI0_CH12, GPIOB_19, I2S0_TX_FS]<name=PTB19_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB19 pin
//     <-2=> GPIOB_19 (reset default)<selection=GPIOB_19_PIN_SEL,PTB19>
//     <0=> TSI0_CH12
//     <1=> GPIOB_19<selection=GPIOB_19_PIN_SEL,PTB19>
//     <4=> I2S0_TX_FS<selection=I2S0_TX_FS_PIN_SEL,PTB19>
//     <1=> Default
#define PTB19_SIG_SEL        1                   

// Signal mapping for PTC0 pin
//   <o> PTC0 (Alias:A0) [ADC0_SE14/TSI0_CH13, GPIOC_0, SPI0_PCS4, PDB0_EXTRG]<name=PTC0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC0 pin
//     <-2=> ADC0_SE14/TSI0_CH13 (reset default)<selection=ADC0_SE14_PIN_SEL,PTC0>
//     <0=> ADC0_SE14/TSI0_CH13<selection=ADC0_SE14_PIN_SEL,PTC0>
//     <1=> GPIOC_0<selection=GPIOC_0_PIN_SEL,PTC0>
//     <2=> SPI0_PCS4<selection=SPI0_PCS4_PIN_SEL,PTC0>
//     <3=> PDB0_EXTRG
//     <0=> Default
#define PTC0_SIG_SEL         0                   

// Signal mapping for PTC1 pin
//   <o> PTC1 (Alias:A1) [ADC0_SE15/TSI0_CH14, GPIOC_1/LLWU_P6, SPI0_PCS3, UART1_RTS_b, FTM0_CH0, I2S0_TXD0]<name=PTC1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC1 pin
//     <-2=> ADC0_SE15/TSI0_CH14 (reset default)<selection=ADC0_SE15_PIN_SEL,PTC1>
//     <0=> ADC0_SE15/TSI0_CH14<selection=ADC0_SE15_PIN_SEL,PTC1>
//     <1=> GPIOC_1/LLWU_P6<selection=GPIOC_1_PIN_SEL,PTC1>
//     <2=> SPI0_PCS3<selection=SPI0_PCS3_PIN_SEL,PTC1>
//     <3=> UART1_RTS_b
//     <4=> FTM0_CH0<selection=FTM0_CH0_PIN_SEL,PTC1>
//     <6=> I2S0_TXD0<selection=I2S0_TXD0_PIN_SEL,PTC1>
//     <0=> Default
#define PTC1_SIG_SEL         0                   

// Signal mapping for PTC2 pin
//   <o> PTC2 (Alias:D10) [ADC0_SE4b/CMP1_IN0/TSI0_CH15, GPIOC_2, SPI0_PCS2, UART1_CTS_b, FTM0_CH1, I2S0_TX_FS]<name=PTC2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC2 pin
//     <-2=> ADC0_SE4b/CMP1_IN0/TSI0_CH15 (reset default)<selection=ADC0_SE4b_PIN_SEL,PTC2>
//     <0=> ADC0_SE4b/CMP1_IN0/TSI0_CH15<selection=ADC0_SE4b_PIN_SEL,PTC2>
//     <1=> GPIOC_2<selection=GPIOC_2_PIN_SEL,PTC2>
//     <2=> SPI0_PCS2<selection=SPI0_PCS2_PIN_SEL,PTC2>
//     <3=> UART1_CTS_b
//     <4=> FTM0_CH1<selection=FTM0_CH1_PIN_SEL,PTC2>
//     <6=> I2S0_TX_FS<selection=I2S0_TX_FS_PIN_SEL,PTC2>
//     <1=> Default
#define PTC2_SIG_SEL         1                   

// Signal mapping for PTC3 pin
//   <o> PTC3 (Alias:D6, LED_RED) [CMP1_IN1, GPIOC_3/LLWU_P7, SPI0_PCS1, UART1_RX, FTM0_CH2, I2S0_TX_BCLK]<name=PTC3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC3 pin
//     <-2=> CMP1_IN1 (reset default)
//     <0=> CMP1_IN1
//     <1=> GPIOC_3/LLWU_P7<selection=GPIOC_3_PIN_SEL,PTC3>
//     <2=> SPI0_PCS1<selection=SPI0_PCS1_PIN_SEL,PTC3>
//     <3=> UART1_RX
//     <4=> FTM0_CH2<selection=FTM0_CH2_PIN_SEL,PTC3>
//     <6=> I2S0_TX_BCLK<selection=I2S0_TX_BCLK_PIN_SEL,PTC3>
//     <1=> Default
#define PTC3_SIG_SEL         1                   

// Signal mapping for PTC4 pin
//   <o> PTC4 (Alias:D7) [GPIOC_4/LLWU_P8, SPI0_PCS0, UART1_TX, FTM0_CH3, CMP1_OUT]<name=PTC4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC4 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_4/LLWU_P8<selection=GPIOC_4_PIN_SEL,PTC4>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTC4>
//     <3=> UART1_TX
//     <4=> FTM0_CH3<selection=FTM0_CH3_PIN_SEL,PTC4>
//     <6=> CMP1_OUT
//     <1=> Default
#define PTC4_SIG_SEL         1                   

// Signal mapping for PTC5 pin
//   <o> PTC5 (Alias:D18) [GPIOC_5/LLWU_P9, SPI0_SCK, LPTMR0_ALT2, I2S0_RXD0, CMP0_OUT]<name=PTC5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC5 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_5/LLWU_P9<selection=GPIOC_5_PIN_SEL,PTC5>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTC5>
//     <3=> LPTMR0_ALT2<selection=LPTMR0_ALT2_PIN_SEL,PTC5>
//     <4=> I2S0_RXD0<selection=I2S0_RXD0_PIN_SEL,PTC5>
//     <6=> CMP0_OUT
//     <1=> Default
#define PTC5_SIG_SEL         1                   

// Signal mapping for PTC6 pin
//   <o> PTC6 (Alias:D19, ACC_INT2) [CMP0_IN0, GPIOC_6/LLWU_P10, SPI0_SOUT, PDB0_EXTRG, I2S0_RX_BCLK, I2S0_MCLK]<name=PTC6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC6 pin
//     <-2=> CMP0_IN0 (reset default)
//     <0=> CMP0_IN0
//     <1=> GPIOC_6/LLWU_P10<selection=GPIOC_6_PIN_SEL,PTC6>
//     <2=> SPI0_SOUT<selection=SPI0_SOUT_PIN_SEL,PTC6>
//     <3=> PDB0_EXTRG
//     <4=> I2S0_RX_BCLK<selection=I2S0_RX_BCLK_PIN_SEL,PTC6>
//     <6=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTC6>
//     <1=> Default
#define PTC6_SIG_SEL         1                   

// Signal mapping for PTC7 pin
//   <o> PTC7 (Alias:D20) [CMP0_IN1, GPIOC_7, SPI0_SIN, USB_SOF_OUT, I2S0_RX_FS]<name=PTC7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC7 pin
//     <-2=> CMP0_IN1 (reset default)
//     <0=> CMP0_IN1
//     <1=> GPIOC_7<selection=GPIOC_7_PIN_SEL,PTC7>
//     <2=> SPI0_SIN<selection=SPI0_SIN_PIN_SEL,PTC7>
//     <3=> USB_SOF_OUT
//     <4=> I2S0_RX_FS<selection=I2S0_RX_FS_PIN_SEL,PTC7>
//     <1=> Default
#define PTC7_SIG_SEL         1                   

// Signal mapping for PTC8 pin
//   <o> PTC8 (Alias:D4) [CMP0_IN2, GPIOC_8, I2S0_MCLK]<name=PTC8_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC8 pin
//     <-2=> CMP0_IN2 (reset default)
//     <0=> CMP0_IN2
//     <1=> GPIOC_8<selection=GPIOC_8_PIN_SEL,PTC8>
//     <4=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTC8>
//     <1=> Default
#define PTC8_SIG_SEL         1                   

// Signal mapping for PTC9 pin
//   <o> PTC9 (Alias:D23) [CMP0_IN3, GPIOC_9, I2S0_RX_BCLK]<name=PTC9_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC9 pin
//     <-2=> CMP0_IN3 (reset default)
//     <0=> CMP0_IN3
//     <1=> GPIOC_9<selection=GPIOC_9_PIN_SEL,PTC9>
//     <4=> I2S0_RX_BCLK<selection=I2S0_RX_BCLK_PIN_SEL,PTC9>
//     <1=> Default
#define PTC9_SIG_SEL         1                   

// Signal mapping for PTC10 pin
//   <o> PTC10 (Alias:D25) [GPIOC_10, I2S0_RX_FS]<name=PTC10_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC10 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_10<selection=GPIOC_10_PIN_SEL,PTC10>
//     <4=> I2S0_RX_FS<selection=I2S0_RX_FS_PIN_SEL,PTC10>
//     <-2=> Default
#define PTC10_SIG_SEL        -2                  

// Signal mapping for PTC11 pin
//   <o> PTC11 (Alias:D17, ACC_INT1) [GPIOC_11/LLWU_P11]<name=PTC11_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC11 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_11/LLWU_P11<selection=GPIOC_11_PIN_SEL,PTC11>
//     <-2=> Default
#define PTC11_SIG_SEL        -2                  

// Signal mapping for PTD0 pin
//   <o> PTD0 (Alias:D16) [GPIOD_0/LLWU_P12, SPI0_PCS0, UART2_RTS_b]<name=PTD0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD0 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_0/LLWU_P12<selection=GPIOD_0_PIN_SEL,PTD0>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTD0>
//     <3=> UART2_RTS_b
//     <-2=> Default
#define PTD0_SIG_SEL         -2                  

// Signal mapping for PTD1 pin
//   <o> PTD1 (Alias:D13) [ADC0_SE5b, GPIOD_1, SPI0_SCK, UART2_CTS_b]<name=PTD1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD1 pin
//     <-2=> ADC0_SE5b (reset default)<selection=ADC0_SE5b_PIN_SEL,PTD1>
//     <0=> ADC0_SE5b<selection=ADC0_SE5b_PIN_SEL,PTD1>
//     <1=> GPIOD_1<selection=GPIOD_1_PIN_SEL,PTD1>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTD1>
//     <3=> UART2_CTS_b
//     <2=> Default
#define PTD1_SIG_SEL         2                   

// Signal mapping for PTD2 pin
//   <o> PTD2 (Alias:D11) [GPIOD_2/LLWU_P13, SPI0_SOUT, UART2_RX]<name=PTD2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD2 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_2/LLWU_P13<selection=GPIOD_2_PIN_SEL,PTD2>
//     <2=> SPI0_SOUT<selection=SPI0_SOUT_PIN_SEL,PTD2>
//     <3=> UART2_RX
//     <2=> Default
#define PTD2_SIG_SEL         2                   

// Signal mapping for PTD3 pin
//   <o> PTD3 (Alias:D12) [GPIOD_3, SPI0_SIN, UART2_TX]<name=PTD3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD3 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_3<selection=GPIOD_3_PIN_SEL,PTD3>
//     <2=> SPI0_SIN<selection=SPI0_SIN_PIN_SEL,PTD3>
//     <3=> UART2_TX
//     <2=> Default
#define PTD3_SIG_SEL         2                   

// Signal mapping for PTD4 pin
//   <o> PTD4 (Alias:D3, LED_GREEN) [GPIOD_4/LLWU_P14, SPI0_PCS1, UART0_RTS_b, FTM0_CH4, EWM_IN]<name=PTD4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD4 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_4/LLWU_P14<selection=GPIOD_4_PIN_SEL,PTD4>
//     <2=> SPI0_PCS1<selection=SPI0_PCS1_PIN_SEL,PTD4>
//     <3=> UART0_RTS_b
//     <4=> FTM0_CH4<selection=FTM0_CH4_PIN_SEL,PTD4>
//     <6=> EWM_IN
//     <1=> Default
#define PTD4_SIG_SEL         1                   

// Signal mapping for PTD5 pin
//   <o> PTD5 (Alias:A3) [ADC0_SE6b, GPIOD_5, SPI0_PCS2, UART0_CTS_b/UART0_COL_b, FTM0_CH5, EWM_OUT_b]<name=PTD5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD5 pin
//     <-2=> ADC0_SE6b (reset default)<selection=ADC0_SE6b_PIN_SEL,PTD5>
//     <0=> ADC0_SE6b<selection=ADC0_SE6b_PIN_SEL,PTD5>
//     <1=> GPIOD_5<selection=GPIOD_5_PIN_SEL,PTD5>
//     <2=> SPI0_PCS2<selection=SPI0_PCS2_PIN_SEL,PTD5>
//     <3=> UART0_CTS_b/UART0_COL_b
//     <4=> FTM0_CH5<selection=FTM0_CH5_PIN_SEL,PTD5>
//     <6=> EWM_OUT_b
//     <0=> Default
#define PTD5_SIG_SEL         0                   

// Signal mapping for PTD6 pin
//   <o> PTD6 (Alias:A2) [ADC0_SE7b, GPIOD_6/LLWU_P15, SPI0_PCS3, UART0_RX, FTM0_CH6, FTM0_FLT0]<name=PTD6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD6 pin
//     <-2=> ADC0_SE7b (reset default)<selection=ADC0_SE7b_PIN_SEL,PTD6>
//     <0=> ADC0_SE7b<selection=ADC0_SE7b_PIN_SEL,PTD6>
//     <1=> GPIOD_6/LLWU_P15<selection=GPIOD_6_PIN_SEL,PTD6>
//     <2=> SPI0_PCS3<selection=SPI0_PCS3_PIN_SEL,PTD6>
//     <3=> UART0_RX
//     <4=> FTM0_CH6<selection=FTM0_CH6_PIN_SEL,PTD6>
//     <6=> FTM0_FLT0
//     <0=> Default
#define PTD6_SIG_SEL         0                   

// Signal mapping for PTD7 pin
//   <o> PTD7 (Alias:D22) [GPIOD_7, CMT_IRO, UART0_TX, FTM0_CH7, FTM0_FLT1]<name=PTD7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD7 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_7<selection=GPIOD_7_PIN_SEL,PTD7>
//     <2=> CMT_IRO
//     <3=> UART0_TX
//     <4=> FTM0_CH7<selection=FTM0_CH7_PIN_SEL,PTD7>
//     <6=> FTM0_FLT1
//     <-2=> Default
#define PTD7_SIG_SEL         -2                  

// Signal mapping for PTE0 pin
//   <o> PTE0 (Alias:D1) [GPIOE_0, UART1_TX, RTC_CLKOUT]<name=PTE0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE0 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_0<selection=GPIOE_0_PIN_SEL,PTE0>
//     <3=> UART1_TX
//     <7=> RTC_CLKOUT
//     <1=> Default
#define PTE0_SIG_SEL         1                   

// Signal mapping for PTE1 pin
//   <o> PTE1 (Alias:D0) [GPIOE_1/LLWU_P0, UART1_RX]<name=PTE1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE1 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_1/LLWU_P0<selection=GPIOE_1_PIN_SEL,PTE1>
//     <3=> UART1_RX
//     <1=> Default
#define PTE1_SIG_SEL         1                   

// </e>

// Pin peripheral signal mapping
//   <e> Mapping by Peripheral Function 
//   <i> This allows the mapping of peripheral functions to pins
//   <i> to be controlled by peripheral function
//     <0=> Disabled
//     <1=> Enabled
#define MAP_BY_FUNCTION_ENABLED 0                   

// Pin Mapping for ADC0_DM0 signal
//   <o> ADC0_DM0 [ADC0_DM0]<name=ADC0_DM0_PIN_SEL><constant>
//   <i> Shows which pin ADC0_DM0 is mapped to
//     <0=> Disabled
//     <1=> ADC0_DM0
#define ADC0_DM0_PIN_SEL     1                   
#if ADC0_DM0_PIN_SEL == 1
#define ADC0_DM0_GPIO        0                   
#define ADC0_DM0_FN          0                   
#endif

// Pin Mapping for ADC0_DM3 signal
//   <o> ADC0_DM3 [ADC0_DM3]<name=ADC0_DM3_PIN_SEL><constant>
//   <i> Shows which pin ADC0_DM3 is mapped to
//     <0=> Disabled
//     <1=> ADC0_DM3
#define ADC0_DM3_PIN_SEL     1                   
#if ADC0_DM3_PIN_SEL == 1
#define ADC0_DM3_GPIO        0                   
#define ADC0_DM3_FN          0                   
#endif

// Pin Mapping for ADC0_DP0 signal
//   <o> ADC0_DP0 [ADC0_DP0]<name=ADC0_DP0_PIN_SEL><constant>
//   <i> Shows which pin ADC0_DP0 is mapped to
//     <0=> Disabled
//     <1=> ADC0_DP0
#define ADC0_DP0_PIN_SEL     1                   
#if ADC0_DP0_PIN_SEL == 1
#define ADC0_DP0_GPIO        0                   
#define ADC0_DP0_FN          0                   
#endif

// Pin Mapping for ADC0_DP3 signal
//   <o> ADC0_DP3 [ADC0_DP3]<name=ADC0_DP3_PIN_SEL><constant>
//   <i> Shows which pin ADC0_DP3 is mapped to
//     <0=> Disabled
//     <1=> ADC0_DP3
#define ADC0_DP3_PIN_SEL     1                   
#if ADC0_DP3_PIN_SEL == 1
#define ADC0_DP3_GPIO        0                   
#define ADC0_DP3_FN          0                   
#endif

// Pin Mapping for ADC0_SE4b signal
//   <o> ADC0_SE4b [PTC2]<name=ADC0_SE4b_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE4b is mapped to
//     <0=> Disabled
//     <1=> PTC2
#define ADC0_SE4b_PIN_SEL    0                   
#if ADC0_SE4b_PIN_SEL == 1
#define ADC0_SE4b_GPIO       digitalIO_PTC2      
#define ADC0_SE4b_FN         0                   
#endif

// Pin Mapping for ADC0_SE5b signal
//   <o> ADC0_SE5b [PTD1]<name=ADC0_SE5b_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE5b is mapped to
//     <0=> Disabled
//     <1=> PTD1
#define ADC0_SE5b_PIN_SEL    0                   
#if ADC0_SE5b_PIN_SEL == 1
#define ADC0_SE5b_GPIO       digitalIO_PTD1      
#define ADC0_SE5b_FN         0                   
#endif

// Pin Mapping for ADC0_SE6b signal
//   <o> ADC0_SE6b [PTD5]<name=ADC0_SE6b_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE6b is mapped to
//     <0=> Disabled
//     <1=> PTD5
#define ADC0_SE6b_PIN_SEL    1                   
#if ADC0_SE6b_PIN_SEL == 1
#define ADC0_SE6b_GPIO       digitalIO_PTD5      
#define ADC0_SE6b_FN         0                   
#endif

// Pin Mapping for ADC0_SE7b signal
//   <o> ADC0_SE7b [PTD6]<name=ADC0_SE7b_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE7b is mapped to
//     <0=> Disabled
//     <1=> PTD6
#define ADC0_SE7b_PIN_SEL    1                   
#if ADC0_SE7b_PIN_SEL == 1
#define ADC0_SE7b_GPIO       digitalIO_PTD6      
#define ADC0_SE7b_FN         0                   
#endif

// Pin Mapping for ADC0_SE8 signal
//   <o> ADC0_SE8 [PTB0]<name=ADC0_SE8_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE8 is mapped to
//     <0=> Disabled
//     <1=> PTB0
#define ADC0_SE8_PIN_SEL     0                   
#if ADC0_SE8_PIN_SEL == 1
#define ADC0_SE8_GPIO        digitalIO_PTB0      
#define ADC0_SE8_FN          0                   
#endif

// Pin Mapping for ADC0_SE9 signal
//   <o> ADC0_SE9 [PTB1]<name=ADC0_SE9_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE9 is mapped to
//     <0=> Disabled
//     <1=> PTB1
#define ADC0_SE9_PIN_SEL     0                   
#if ADC0_SE9_PIN_SEL == 1
#define ADC0_SE9_GPIO        digitalIO_PTB1      
#define ADC0_SE9_FN          0                   
#endif

// Pin Mapping for ADC0_SE12 signal
//   <o> ADC0_SE12 [PTB2]<name=ADC0_SE12_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE12 is mapped to
//     <0=> Disabled
//     <1=> PTB2
#define ADC0_SE12_PIN_SEL    0                   
#if ADC0_SE12_PIN_SEL == 1
#define ADC0_SE12_GPIO       digitalIO_PTB2      
#define ADC0_SE12_FN         0                   
#endif

// Pin Mapping for ADC0_SE13 signal
//   <o> ADC0_SE13 [PTB3]<name=ADC0_SE13_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE13 is mapped to
//     <0=> Disabled
//     <1=> PTB3
#define ADC0_SE13_PIN_SEL    0                   
#if ADC0_SE13_PIN_SEL == 1
#define ADC0_SE13_GPIO       digitalIO_PTB3      
#define ADC0_SE13_FN         0                   
#endif

// Pin Mapping for ADC0_SE14 signal
//   <o> ADC0_SE14 [PTC0]<name=ADC0_SE14_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE14 is mapped to
//     <0=> Disabled
//     <1=> PTC0
#define ADC0_SE14_PIN_SEL    1                   
#if ADC0_SE14_PIN_SEL == 1
#define ADC0_SE14_GPIO       digitalIO_PTC0      
#define ADC0_SE14_FN         0                   
#endif

// Pin Mapping for ADC0_SE15 signal
//   <o> ADC0_SE15 [PTC1]<name=ADC0_SE15_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE15 is mapped to
//     <0=> Disabled
//     <1=> PTC1
#define ADC0_SE15_PIN_SEL    1                   
#if ADC0_SE15_PIN_SEL == 1
#define ADC0_SE15_GPIO       digitalIO_PTC1      
#define ADC0_SE15_FN         0                   
#endif

// Pin Mapping for ADC0_SE23 signal
//   <o> ADC0_SE23 [ADC0_SE23]<name=ADC0_SE23_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE23 is mapped to
//     <0=> Disabled
//     <1=> ADC0_SE23
#define ADC0_SE23_PIN_SEL    1                   
#if ADC0_SE23_PIN_SEL == 1
#define ADC0_SE23_GPIO       0                   
#define ADC0_SE23_FN         0                   
#endif

// Pin Mapping for FTM0_CH0 signal
//   <o> FTM0_CH0 [PTA3, PTC1]<name=FTM0_CH0_PIN_SEL><constant>
//   <i> Shows which pin FTM0_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTA3
//     <2=> PTC1
#define FTM0_CH0_PIN_SEL     0                   
#if FTM0_CH0_PIN_SEL == 1
#define FTM0_CH0_GPIO        digitalIO_PTA3      
#define FTM0_CH0_FN          3                   
#elif FTM0_CH0_PIN_SEL == 2
#define FTM0_CH0_GPIO        digitalIO_PTC1      
#define FTM0_CH0_FN          4                   
#endif

// Pin Mapping for FTM0_CH1 signal
//   <o> FTM0_CH1 [PTA4, PTC2]<name=FTM0_CH1_PIN_SEL><constant>
//   <i> Shows which pin FTM0_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTA4
//     <2=> PTC2
#define FTM0_CH1_PIN_SEL     0                   
#if FTM0_CH1_PIN_SEL == 1
#define FTM0_CH1_GPIO        digitalIO_PTA4      
#define FTM0_CH1_FN          3                   
#elif FTM0_CH1_PIN_SEL == 2
#define FTM0_CH1_GPIO        digitalIO_PTC2      
#define FTM0_CH1_FN          4                   
#endif

// Pin Mapping for FTM0_CH2 signal
//   <o> FTM0_CH2 [PTA5, PTC3]<name=FTM0_CH2_PIN_SEL><constant>
//   <i> Shows which pin FTM0_CH2 is mapped to
//     <0=> Disabled
//     <1=> PTA5
//     <2=> PTC3
#define FTM0_CH2_PIN_SEL     0                   
#if FTM0_CH2_PIN_SEL == 1
#define FTM0_CH2_GPIO        digitalIO_PTA5      
#define FTM0_CH2_FN          3                   
#elif FTM0_CH2_PIN_SEL == 2
#define FTM0_CH2_GPIO        digitalIO_PTC3      
#define FTM0_CH2_FN          4                   
#endif

// Pin Mapping for FTM0_CH3 signal
//   <o> FTM0_CH3 [PTC4]<name=FTM0_CH3_PIN_SEL><constant>
//   <i> Shows which pin FTM0_CH3 is mapped to
//     <0=> Disabled
//     <1=> PTC4
#define FTM0_CH3_PIN_SEL     0                   
#if FTM0_CH3_PIN_SEL == 1
#define FTM0_CH3_GPIO        digitalIO_PTC4      
#define FTM0_CH3_FN          4                   
#endif

// Pin Mapping for FTM0_CH4 signal
//   <o> FTM0_CH4 [PTD4]<name=FTM0_CH4_PIN_SEL><constant>
//   <i> Shows which pin FTM0_CH4 is mapped to
//     <0=> Disabled
//     <1=> PTD4
#define FTM0_CH4_PIN_SEL     0                   
#if FTM0_CH4_PIN_SEL == 1
#define FTM0_CH4_GPIO        digitalIO_PTD4      
#define FTM0_CH4_FN          4                   
#endif

// Pin Mapping for FTM0_CH5 signal
//   <o> FTM0_CH5 [PTA0, PTD5]<name=FTM0_CH5_PIN_SEL><constant>
//   <i> Shows which pin FTM0_CH5 is mapped to
//     <0=> Disabled
//     <1=> PTA0
//     <2=> PTD5
#define FTM0_CH5_PIN_SEL     0                   
#if FTM0_CH5_PIN_SEL == 1
#define FTM0_CH5_GPIO        digitalIO_PTA0      
#define FTM0_CH5_FN          3                   
#elif FTM0_CH5_PIN_SEL == 2
#define FTM0_CH5_GPIO        digitalIO_PTD5      
#define FTM0_CH5_FN          4                   
#endif

// Pin Mapping for FTM0_CH6 signal
//   <o> FTM0_CH6 [PTA1, PTD6]<name=FTM0_CH6_PIN_SEL><constant>
//   <i> Shows which pin FTM0_CH6 is mapped to
//     <0=> Disabled
//     <1=> PTA1
//     <2=> PTD6
#define FTM0_CH6_PIN_SEL     0                   
#if FTM0_CH6_PIN_SEL == 1
#define FTM0_CH6_GPIO        digitalIO_PTA1      
#define FTM0_CH6_FN          3                   
#elif FTM0_CH6_PIN_SEL == 2
#define FTM0_CH6_GPIO        digitalIO_PTD6      
#define FTM0_CH6_FN          4                   
#endif

// Pin Mapping for FTM0_CH7 signal
//   <o> FTM0_CH7 [PTA2, PTD7]<name=FTM0_CH7_PIN_SEL><constant>
//   <i> Shows which pin FTM0_CH7 is mapped to
//     <0=> Disabled
//     <1=> PTA2
//     <2=> PTD7
#define FTM0_CH7_PIN_SEL     0                   
#if FTM0_CH7_PIN_SEL == 1
#define FTM0_CH7_GPIO        digitalIO_PTA2      
#define FTM0_CH7_FN          3                   
#elif FTM0_CH7_PIN_SEL == 2
#define FTM0_CH7_GPIO        digitalIO_PTD7      
#define FTM0_CH7_FN          4                   
#endif

// Pin Mapping for FTM1_CH0 signal
//   <o> FTM1_CH0 [PTA12, PTB0]<name=FTM1_CH0_PIN_SEL><constant>
//   <i> Shows which pin FTM1_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTA12
//     <2=> PTB0
#define FTM1_CH0_PIN_SEL     0                   
#if FTM1_CH0_PIN_SEL == 1
#define FTM1_CH0_GPIO        digitalIO_PTA12     
#define FTM1_CH0_FN          3                   
#elif FTM1_CH0_PIN_SEL == 2
#define FTM1_CH0_GPIO        digitalIO_PTB0      
#define FTM1_CH0_FN          3                   
#endif

// Pin Mapping for FTM1_CH1 signal
//   <o> FTM1_CH1 [PTA13, PTB1]<name=FTM1_CH1_PIN_SEL><constant>
//   <i> Shows which pin FTM1_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTA13
//     <2=> PTB1
#define FTM1_CH1_PIN_SEL     0                   
#if FTM1_CH1_PIN_SEL == 1
#define FTM1_CH1_GPIO        digitalIO_PTA13     
#define FTM1_CH1_FN          3                   
#elif FTM1_CH1_PIN_SEL == 2
#define FTM1_CH1_GPIO        digitalIO_PTB1      
#define FTM1_CH1_FN          3                   
#endif

// Pin Mapping for GPIOA_0 signal
//   <o> GPIOA_0 [PTA0]<name=GPIOA_0_PIN_SEL><constant>
//   <i> Shows which pin GPIOA_0 is mapped to
//     <0=> Disabled
//     <1=> PTA0
#define GPIOA_0_PIN_SEL      0                   
#if GPIOA_0_PIN_SEL == 1
#define GPIOA_0_GPIO         digitalIO_PTA0      
#define GPIOA_0_FN           1                   
#endif

// Pin Mapping for GPIOA_1 signal
//   <o> GPIOA_1 [PTA1]<name=GPIOA_1_PIN_SEL><constant>
//   <i> Shows which pin GPIOA_1 is mapped to
//     <0=> Disabled
//     <1=> PTA1
#define GPIOA_1_PIN_SEL      1                   
#if GPIOA_1_PIN_SEL == 1
#define GPIOA_1_GPIO         digitalIO_PTA1      
#define GPIOA_1_FN           1                   
#endif

// Pin Mapping for GPIOA_2 signal
//   <o> GPIOA_2 [PTA2]<name=GPIOA_2_PIN_SEL><constant>
//   <i> Shows which pin GPIOA_2 is mapped to
//     <0=> Disabled
//     <1=> PTA2
#define GPIOA_2_PIN_SEL      1                   
#if GPIOA_2_PIN_SEL == 1
#define GPIOA_2_GPIO         digitalIO_PTA2      
#define GPIOA_2_FN           1                   
#endif

// Pin Mapping for GPIOA_3 signal
//   <o> GPIOA_3 [PTA3]<name=GPIOA_3_PIN_SEL><constant>
//   <i> Shows which pin GPIOA_3 is mapped to
//     <0=> Disabled
//     <1=> PTA3
#define GPIOA_3_PIN_SEL      0                   
#if GPIOA_3_PIN_SEL == 1
#define GPIOA_3_GPIO         digitalIO_PTA3      
#define GPIOA_3_FN           1                   
#endif

// Pin Mapping for GPIOA_4 signal
//   <o> GPIOA_4 [PTA4]<name=GPIOA_4_PIN_SEL><constant>
//   <i> Shows which pin GPIOA_4 is mapped to
//     <0=> Disabled
//     <1=> PTA4
#define GPIOA_4_PIN_SEL      0                   
#if GPIOA_4_PIN_SEL == 1
#define GPIOA_4_GPIO         digitalIO_PTA4      
#define GPIOA_4_FN           1                   
#endif

// Pin Mapping for GPIOA_5 signal
//   <o> GPIOA_5 [PTA5]<name=GPIOA_5_PIN_SEL><constant>
//   <i> Shows which pin GPIOA_5 is mapped to
//     <0=> Disabled
//     <1=> PTA5
#define GPIOA_5_PIN_SEL      1                   
#if GPIOA_5_PIN_SEL == 1
#define GPIOA_5_GPIO         digitalIO_PTA5      
#define GPIOA_5_FN           1                   
#endif

// Pin Mapping for GPIOA_12 signal
//   <o> GPIOA_12 [PTA12]<name=GPIOA_12_PIN_SEL><constant>
//   <i> Shows which pin GPIOA_12 is mapped to
//     <0=> Disabled
//     <1=> PTA12
#define GPIOA_12_PIN_SEL     1                   
#if GPIOA_12_PIN_SEL == 1
#define GPIOA_12_GPIO        digitalIO_PTA12     
#define GPIOA_12_FN          1                   
#endif

// Pin Mapping for GPIOA_13 signal
//   <o> GPIOA_13 [PTA13]<name=GPIOA_13_PIN_SEL><constant>
//   <i> Shows which pin GPIOA_13 is mapped to
//     <0=> Disabled
//     <1=> PTA13
#define GPIOA_13_PIN_SEL     1                   
#if GPIOA_13_PIN_SEL == 1
#define GPIOA_13_GPIO        digitalIO_PTA13     
#define GPIOA_13_FN          1                   
#endif

// Pin Mapping for GPIOA_18 signal
//   <o> GPIOA_18 [PTA18]<name=GPIOA_18_PIN_SEL><constant>
//   <i> Shows which pin GPIOA_18 is mapped to
//     <0=> Disabled
//     <1=> PTA18
#define GPIOA_18_PIN_SEL     0                   
#if GPIOA_18_PIN_SEL == 1
#define GPIOA_18_GPIO        digitalIO_PTA18     
#define GPIOA_18_FN          1                   
#endif

// Pin Mapping for GPIOA_19 signal
//   <o> GPIOA_19 [PTA19]<name=GPIOA_19_PIN_SEL><constant>
//   <i> Shows which pin GPIOA_19 is mapped to
//     <0=> Disabled
//     <1=> PTA19
#define GPIOA_19_PIN_SEL     0                   
#if GPIOA_19_PIN_SEL == 1
#define GPIOA_19_GPIO        digitalIO_PTA19     
#define GPIOA_19_FN          1                   
#endif

// Pin Mapping for GPIOB_0 signal
//   <o> GPIOB_0 [PTB0]<name=GPIOB_0_PIN_SEL><constant>
//   <i> Shows which pin GPIOB_0 is mapped to
//     <0=> Disabled
//     <1=> PTB0
#define GPIOB_0_PIN_SEL      0                   
#if GPIOB_0_PIN_SEL == 1
#define GPIOB_0_GPIO         digitalIO_PTB0      
#define GPIOB_0_FN           1                   
#endif

// Pin Mapping for GPIOB_1 signal
//   <o> GPIOB_1 [PTB1]<name=GPIOB_1_PIN_SEL><constant>
//   <i> Shows which pin GPIOB_1 is mapped to
//     <0=> Disabled
//     <1=> PTB1
#define GPIOB_1_PIN_SEL      0                   
#if GPIOB_1_PIN_SEL == 1
#define GPIOB_1_GPIO         digitalIO_PTB1      
#define GPIOB_1_FN           1                   
#endif

// Pin Mapping for GPIOB_2 signal
//   <o> GPIOB_2 [PTB2]<name=GPIOB_2_PIN_SEL><constant>
//   <i> Shows which pin GPIOB_2 is mapped to
//     <0=> Disabled
//     <1=> PTB2
#define GPIOB_2_PIN_SEL      1                   
#if GPIOB_2_PIN_SEL == 1
#define GPIOB_2_GPIO         digitalIO_PTB2      
#define GPIOB_2_FN           1                   
#endif

// Pin Mapping for GPIOB_3 signal
//   <o> GPIOB_3 [PTB3]<name=GPIOB_3_PIN_SEL><constant>
//   <i> Shows which pin GPIOB_3 is mapped to
//     <0=> Disabled
//     <1=> PTB3
#define GPIOB_3_PIN_SEL      1                   
#if GPIOB_3_PIN_SEL == 1
#define GPIOB_3_GPIO         digitalIO_PTB3      
#define GPIOB_3_FN           1                   
#endif

// Pin Mapping for GPIOB_16 signal
//   <o> GPIOB_16 [PTB16]<name=GPIOB_16_PIN_SEL><constant>
//   <i> Shows which pin GPIOB_16 is mapped to
//     <0=> Disabled
//     <1=> PTB16
#define GPIOB_16_PIN_SEL     0                   
#if GPIOB_16_PIN_SEL == 1
#define GPIOB_16_GPIO        digitalIO_PTB16     
#define GPIOB_16_FN          1                   
#endif

// Pin Mapping for GPIOB_17 signal
//   <o> GPIOB_17 [PTB17]<name=GPIOB_17_PIN_SEL><constant>
//   <i> Shows which pin GPIOB_17 is mapped to
//     <0=> Disabled
//     <1=> PTB17
#define GPIOB_17_PIN_SEL     0                   
#if GPIOB_17_PIN_SEL == 1
#define GPIOB_17_GPIO        digitalIO_PTB17     
#define GPIOB_17_FN          1                   
#endif

// Pin Mapping for GPIOB_18 signal
//   <o> GPIOB_18 [PTB18]<name=GPIOB_18_PIN_SEL><constant>
//   <i> Shows which pin GPIOB_18 is mapped to
//     <0=> Disabled
//     <1=> PTB18
#define GPIOB_18_PIN_SEL     1                   
#if GPIOB_18_PIN_SEL == 1
#define GPIOB_18_GPIO        digitalIO_PTB18     
#define GPIOB_18_FN          1                   
#endif

// Pin Mapping for GPIOB_19 signal
//   <o> GPIOB_19 [PTB19]<name=GPIOB_19_PIN_SEL><constant>
//   <i> Shows which pin GPIOB_19 is mapped to
//     <0=> Disabled
//     <1=> PTB19
#define GPIOB_19_PIN_SEL     1                   
#if GPIOB_19_PIN_SEL == 1
#define GPIOB_19_GPIO        digitalIO_PTB19     
#define GPIOB_19_FN          1                   
#endif

// Pin Mapping for GPIOC_0 signal
//   <o> GPIOC_0 [PTC0]<name=GPIOC_0_PIN_SEL><constant>
//   <i> Shows which pin GPIOC_0 is mapped to
//     <0=> Disabled
//     <1=> PTC0
#define GPIOC_0_PIN_SEL      0                   
#if GPIOC_0_PIN_SEL == 1
#define GPIOC_0_GPIO         digitalIO_PTC0      
#define GPIOC_0_FN           1                   
#endif

// Pin Mapping for GPIOC_1 signal
//   <o> GPIOC_1 [PTC1]<name=GPIOC_1_PIN_SEL><constant>
//   <i> Shows which pin GPIOC_1 is mapped to
//     <0=> Disabled
//     <1=> PTC1
#define GPIOC_1_PIN_SEL      0                   
#if GPIOC_1_PIN_SEL == 1
#define GPIOC_1_GPIO         digitalIO_PTC1      
#define GPIOC_1_FN           1                   
#endif

// Pin Mapping for GPIOC_2 signal
//   <o> GPIOC_2 [PTC2]<name=GPIOC_2_PIN_SEL><constant>
//   <i> Shows which pin GPIOC_2 is mapped to
//     <0=> Disabled
//     <1=> PTC2
#define GPIOC_2_PIN_SEL      1                   
#if GPIOC_2_PIN_SEL == 1
#define GPIOC_2_GPIO         digitalIO_PTC2      
#define GPIOC_2_FN           1                   
#endif

// Pin Mapping for GPIOC_3 signal
//   <o> GPIOC_3 [PTC3]<name=GPIOC_3_PIN_SEL><constant>
//   <i> Shows which pin GPIOC_3 is mapped to
//     <0=> Disabled
//     <1=> PTC3
#define GPIOC_3_PIN_SEL      1                   
#if GPIOC_3_PIN_SEL == 1
#define GPIOC_3_GPIO         digitalIO_PTC3      
#define GPIOC_3_FN           1                   
#endif

// Pin Mapping for GPIOC_4 signal
//   <o> GPIOC_4 [PTC4]<name=GPIOC_4_PIN_SEL><constant>
//   <i> Shows which pin GPIOC_4 is mapped to
//     <0=> Disabled
//     <1=> PTC4
#define GPIOC_4_PIN_SEL      1                   
#if GPIOC_4_PIN_SEL == 1
#define GPIOC_4_GPIO         digitalIO_PTC4      
#define GPIOC_4_FN           1                   
#endif

// Pin Mapping for GPIOC_5 signal
//   <o> GPIOC_5 [PTC5]<name=GPIOC_5_PIN_SEL><constant>
//   <i> Shows which pin GPIOC_5 is mapped to
//     <0=> Disabled
//     <1=> PTC5
#define GPIOC_5_PIN_SEL      1                   
#if GPIOC_5_PIN_SEL == 1
#define GPIOC_5_GPIO         digitalIO_PTC5      
#define GPIOC_5_FN           1                   
#endif

// Pin Mapping for GPIOC_6 signal
//   <o> GPIOC_6 [PTC6]<name=GPIOC_6_PIN_SEL><constant>
//   <i> Shows which pin GPIOC_6 is mapped to
//     <0=> Disabled
//     <1=> PTC6
#define GPIOC_6_PIN_SEL      1                   
#if GPIOC_6_PIN_SEL == 1
#define GPIOC_6_GPIO         digitalIO_PTC6      
#define GPIOC_6_FN           1                   
#endif

// Pin Mapping for GPIOC_7 signal
//   <o> GPIOC_7 [PTC7]<name=GPIOC_7_PIN_SEL><constant>
//   <i> Shows which pin GPIOC_7 is mapped to
//     <0=> Disabled
//     <1=> PTC7
#define GPIOC_7_PIN_SEL      1                   
#if GPIOC_7_PIN_SEL == 1
#define GPIOC_7_GPIO         digitalIO_PTC7      
#define GPIOC_7_FN           1                   
#endif

// Pin Mapping for GPIOC_8 signal
//   <o> GPIOC_8 [PTC8]<name=GPIOC_8_PIN_SEL><constant>
//   <i> Shows which pin GPIOC_8 is mapped to
//     <0=> Disabled
//     <1=> PTC8
#define GPIOC_8_PIN_SEL      1                   
#if GPIOC_8_PIN_SEL == 1
#define GPIOC_8_GPIO         digitalIO_PTC8      
#define GPIOC_8_FN           1                   
#endif

// Pin Mapping for GPIOC_9 signal
//   <o> GPIOC_9 [PTC9]<name=GPIOC_9_PIN_SEL><constant>
//   <i> Shows which pin GPIOC_9 is mapped to
//     <0=> Disabled
//     <1=> PTC9
#define GPIOC_9_PIN_SEL      1                   
#if GPIOC_9_PIN_SEL == 1
#define GPIOC_9_GPIO         digitalIO_PTC9      
#define GPIOC_9_FN           1                   
#endif

// Pin Mapping for GPIOC_10 signal
//   <o> GPIOC_10 [PTC10]<name=GPIOC_10_PIN_SEL><constant>
//   <i> Shows which pin GPIOC_10 is mapped to
//     <0=> Disabled
//     <1=> PTC10
#define GPIOC_10_PIN_SEL     0                   
#if GPIOC_10_PIN_SEL == 1
#define GPIOC_10_GPIO        digitalIO_PTC10     
#define GPIOC_10_FN          1                   
#endif

// Pin Mapping for GPIOC_11 signal
//   <o> GPIOC_11 [PTC11]<name=GPIOC_11_PIN_SEL><constant>
//   <i> Shows which pin GPIOC_11 is mapped to
//     <0=> Disabled
//     <1=> PTC11
#define GPIOC_11_PIN_SEL     0                   
#if GPIOC_11_PIN_SEL == 1
#define GPIOC_11_GPIO        digitalIO_PTC11     
#define GPIOC_11_FN          1                   
#endif

// Pin Mapping for GPIOD_0 signal
//   <o> GPIOD_0 [PTD0]<name=GPIOD_0_PIN_SEL><constant>
//   <i> Shows which pin GPIOD_0 is mapped to
//     <0=> Disabled
//     <1=> PTD0
#define GPIOD_0_PIN_SEL      0                   
#if GPIOD_0_PIN_SEL == 1
#define GPIOD_0_GPIO         digitalIO_PTD0      
#define GPIOD_0_FN           1                   
#endif

// Pin Mapping for GPIOD_1 signal
//   <o> GPIOD_1 [PTD1]<name=GPIOD_1_PIN_SEL><constant>
//   <i> Shows which pin GPIOD_1 is mapped to
//     <0=> Disabled
//     <1=> PTD1
#define GPIOD_1_PIN_SEL      0                   
#if GPIOD_1_PIN_SEL == 1
#define GPIOD_1_GPIO         digitalIO_PTD1      
#define GPIOD_1_FN           1                   
#endif

// Pin Mapping for GPIOD_2 signal
//   <o> GPIOD_2 [PTD2]<name=GPIOD_2_PIN_SEL><constant>
//   <i> Shows which pin GPIOD_2 is mapped to
//     <0=> Disabled
//     <1=> PTD2
#define GPIOD_2_PIN_SEL      0                   
#if GPIOD_2_PIN_SEL == 1
#define GPIOD_2_GPIO         digitalIO_PTD2      
#define GPIOD_2_FN           1                   
#endif

// Pin Mapping for GPIOD_3 signal
//   <o> GPIOD_3 [PTD3]<name=GPIOD_3_PIN_SEL><constant>
//   <i> Shows which pin GPIOD_3 is mapped to
//     <0=> Disabled
//     <1=> PTD3
#define GPIOD_3_PIN_SEL      0                   
#if GPIOD_3_PIN_SEL == 1
#define GPIOD_3_GPIO         digitalIO_PTD3      
#define GPIOD_3_FN           1                   
#endif

// Pin Mapping for GPIOD_4 signal
//   <o> GPIOD_4 [PTD4]<name=GPIOD_4_PIN_SEL><constant>
//   <i> Shows which pin GPIOD_4 is mapped to
//     <0=> Disabled
//     <1=> PTD4
#define GPIOD_4_PIN_SEL      1                   
#if GPIOD_4_PIN_SEL == 1
#define GPIOD_4_GPIO         digitalIO_PTD4      
#define GPIOD_4_FN           1                   
#endif

// Pin Mapping for GPIOD_5 signal
//   <o> GPIOD_5 [PTD5]<name=GPIOD_5_PIN_SEL><constant>
//   <i> Shows which pin GPIOD_5 is mapped to
//     <0=> Disabled
//     <1=> PTD5
#define GPIOD_5_PIN_SEL      0                   
#if GPIOD_5_PIN_SEL == 1
#define GPIOD_5_GPIO         digitalIO_PTD5      
#define GPIOD_5_FN           1                   
#endif

// Pin Mapping for GPIOD_6 signal
//   <o> GPIOD_6 [PTD6]<name=GPIOD_6_PIN_SEL><constant>
//   <i> Shows which pin GPIOD_6 is mapped to
//     <0=> Disabled
//     <1=> PTD6
#define GPIOD_6_PIN_SEL      0                   
#if GPIOD_6_PIN_SEL == 1
#define GPIOD_6_GPIO         digitalIO_PTD6      
#define GPIOD_6_FN           1                   
#endif

// Pin Mapping for GPIOD_7 signal
//   <o> GPIOD_7 [PTD7]<name=GPIOD_7_PIN_SEL><constant>
//   <i> Shows which pin GPIOD_7 is mapped to
//     <0=> Disabled
//     <1=> PTD7
#define GPIOD_7_PIN_SEL      0                   
#if GPIOD_7_PIN_SEL == 1
#define GPIOD_7_GPIO         digitalIO_PTD7      
#define GPIOD_7_FN           1                   
#endif

// Pin Mapping for GPIOE_0 signal
//   <o> GPIOE_0 [PTE0]<name=GPIOE_0_PIN_SEL><constant>
//   <i> Shows which pin GPIOE_0 is mapped to
//     <0=> Disabled
//     <1=> PTE0
#define GPIOE_0_PIN_SEL      1                   
#if GPIOE_0_PIN_SEL == 1
#define GPIOE_0_GPIO         digitalIO_PTE0      
#define GPIOE_0_FN           1                   
#endif

// Pin Mapping for GPIOE_1 signal
//   <o> GPIOE_1 [PTE1]<name=GPIOE_1_PIN_SEL><constant>
//   <i> Shows which pin GPIOE_1 is mapped to
//     <0=> Disabled
//     <1=> PTE1
#define GPIOE_1_PIN_SEL      1                   
#if GPIOE_1_PIN_SEL == 1
#define GPIOE_1_GPIO         digitalIO_PTE1      
#define GPIOE_1_FN           1                   
#endif

// Pin Mapping for I2C0_SCL signal
//   <o> I2C0_SCL [PTB0, PTB2]<name=I2C0_SCL_PIN_SEL><constant>
//   <i> Shows which pin I2C0_SCL is mapped to
//     <0=> Disabled
//     <1=> PTB0
//     <2=> PTB2
#define I2C0_SCL_PIN_SEL     1                   
#if I2C0_SCL_PIN_SEL == 1
#define I2C0_SCL_GPIO        digitalIO_PTB0      
#define I2C0_SCL_FN          2                   
#elif I2C0_SCL_PIN_SEL == 2
#define I2C0_SCL_GPIO        digitalIO_PTB2      
#define I2C0_SCL_FN          2                   
#endif

// Pin Mapping for I2C0_SDA signal
//   <o> I2C0_SDA [PTB1, PTB3]<name=I2C0_SDA_PIN_SEL><constant>
//   <i> Shows which pin I2C0_SDA is mapped to
//     <0=> Disabled
//     <1=> PTB1
//     <2=> PTB3
#define I2C0_SDA_PIN_SEL     1                   
#if I2C0_SDA_PIN_SEL == 1
#define I2C0_SDA_GPIO        digitalIO_PTB1      
#define I2C0_SDA_FN          2                   
#elif I2C0_SDA_PIN_SEL == 2
#define I2C0_SDA_GPIO        digitalIO_PTB3      
#define I2C0_SDA_FN          2                   
#endif

// Pin Mapping for I2S0_MCLK signal
//   <o> I2S0_MCLK [PTC6, PTC8]<name=I2S0_MCLK_PIN_SEL><constant>
//   <i> Shows which pin I2S0_MCLK is mapped to
//     <0=> Disabled
//     <1=> PTC6
//     <2=> PTC8
#define I2S0_MCLK_PIN_SEL    0                   
#if I2S0_MCLK_PIN_SEL == 1
#define I2S0_MCLK_GPIO       digitalIO_PTC6      
#define I2S0_MCLK_FN         6                   
#elif I2S0_MCLK_PIN_SEL == 2
#define I2S0_MCLK_GPIO       digitalIO_PTC8      
#define I2S0_MCLK_FN         4                   
#endif

// Pin Mapping for I2S0_RX_BCLK signal
//   <o> I2S0_RX_BCLK [PTC6, PTC9]<name=I2S0_RX_BCLK_PIN_SEL><constant>
//   <i> Shows which pin I2S0_RX_BCLK is mapped to
//     <0=> Disabled
//     <1=> PTC6
//     <2=> PTC9
#define I2S0_RX_BCLK_PIN_SEL 0                   
#if I2S0_RX_BCLK_PIN_SEL == 1
#define I2S0_RX_BCLK_GPIO    digitalIO_PTC6      
#define I2S0_RX_BCLK_FN      4                   
#elif I2S0_RX_BCLK_PIN_SEL == 2
#define I2S0_RX_BCLK_GPIO    digitalIO_PTC9      
#define I2S0_RX_BCLK_FN      4                   
#endif

// Pin Mapping for I2S0_TX_FS signal
//   <o> I2S0_TX_FS [PTA13, PTB19, PTC2]<name=I2S0_TX_FS_PIN_SEL><constant>
//   <i> Shows which pin I2S0_TX_FS is mapped to
//     <0=> Disabled
//     <1=> PTA13
//     <2=> PTB19
//     <3=> PTC2
#define I2S0_TX_FS_PIN_SEL   0                   
#if I2S0_TX_FS_PIN_SEL == 1
#define I2S0_TX_FS_GPIO      digitalIO_PTA13     
#define I2S0_TX_FS_FN        6                   
#elif I2S0_TX_FS_PIN_SEL == 2
#define I2S0_TX_FS_GPIO      digitalIO_PTB19     
#define I2S0_TX_FS_FN        4                   
#elif I2S0_TX_FS_PIN_SEL == 3
#define I2S0_TX_FS_GPIO      digitalIO_PTC2      
#define I2S0_TX_FS_FN        6                   
#endif

// Pin Mapping for I2S0_RXD0 signal
//   <o> I2S0_RXD0 [PTC5]<name=I2S0_RXD0_PIN_SEL><constant>
//   <i> Shows which pin I2S0_RXD0 is mapped to
//     <0=> Disabled
//     <1=> PTC5
#define I2S0_RXD0_PIN_SEL    0                   
#if I2S0_RXD0_PIN_SEL == 1
#define I2S0_RXD0_GPIO       digitalIO_PTC5      
#define I2S0_RXD0_FN         4                   
#endif

// Pin Mapping for I2S0_RX_FS signal
//   <o> I2S0_RX_FS [PTC7, PTC10]<name=I2S0_RX_FS_PIN_SEL><constant>
//   <i> Shows which pin I2S0_RX_FS is mapped to
//     <0=> Disabled
//     <1=> PTC7
//     <2=> PTC10
#define I2S0_RX_FS_PIN_SEL   0                   
#if I2S0_RX_FS_PIN_SEL == 1
#define I2S0_RX_FS_GPIO      digitalIO_PTC7      
#define I2S0_RX_FS_FN        4                   
#elif I2S0_RX_FS_PIN_SEL == 2
#define I2S0_RX_FS_GPIO      digitalIO_PTC10     
#define I2S0_RX_FS_FN        4                   
#endif

// Pin Mapping for I2S0_TX_BCLK signal
//   <o> I2S0_TX_BCLK [PTA5, PTB18, PTC3]<name=I2S0_TX_BCLK_PIN_SEL><constant>
//   <i> Shows which pin I2S0_TX_BCLK is mapped to
//     <0=> Disabled
//     <1=> PTA5
//     <2=> PTB18
//     <3=> PTC3
#define I2S0_TX_BCLK_PIN_SEL 0                   
#if I2S0_TX_BCLK_PIN_SEL == 1
#define I2S0_TX_BCLK_GPIO    digitalIO_PTA5      
#define I2S0_TX_BCLK_FN      6                   
#elif I2S0_TX_BCLK_PIN_SEL == 2
#define I2S0_TX_BCLK_GPIO    digitalIO_PTB18     
#define I2S0_TX_BCLK_FN      4                   
#elif I2S0_TX_BCLK_PIN_SEL == 3
#define I2S0_TX_BCLK_GPIO    digitalIO_PTC3      
#define I2S0_TX_BCLK_FN      6                   
#endif

// Pin Mapping for I2S0_TXD0 signal
//   <o> I2S0_TXD0 [PTA12, PTC1]<name=I2S0_TXD0_PIN_SEL><constant>
//   <i> Shows which pin I2S0_TXD0 is mapped to
//     <0=> Disabled
//     <1=> PTA12
//     <2=> PTC1
#define I2S0_TXD0_PIN_SEL    0                   
#if I2S0_TXD0_PIN_SEL == 1
#define I2S0_TXD0_GPIO       digitalIO_PTA12     
#define I2S0_TXD0_FN         6                   
#elif I2S0_TXD0_PIN_SEL == 2
#define I2S0_TXD0_GPIO       digitalIO_PTC1      
#define I2S0_TXD0_FN         6                   
#endif

// Pin Mapping for LPTMR0_ALT1 signal
//   <o> LPTMR0_ALT1 [PTA19]<name=LPTMR0_ALT1_PIN_SEL><constant>
//   <i> Shows which pin LPTMR0_ALT1 is mapped to
//     <0=> Disabled
//     <1=> PTA19
#define LPTMR0_ALT1_PIN_SEL  0                   
#if LPTMR0_ALT1_PIN_SEL == 1
#define LPTMR0_ALT1_GPIO     digitalIO_PTA19     
#define LPTMR0_ALT1_FN       6                   
#endif

// Pin Mapping for LPTMR0_ALT2 signal
//   <o> LPTMR0_ALT2 [PTC5]<name=LPTMR0_ALT2_PIN_SEL><constant>
//   <i> Shows which pin LPTMR0_ALT2 is mapped to
//     <0=> Disabled
//     <1=> PTC5
#define LPTMR0_ALT2_PIN_SEL  0                   
#if LPTMR0_ALT2_PIN_SEL == 1
#define LPTMR0_ALT2_GPIO     digitalIO_PTC5      
#define LPTMR0_ALT2_FN       3                   
#endif

// Pin Mapping for SPI0_PCS0 signal
//   <o> SPI0_PCS0 [PTC4, PTD0]<name=SPI0_PCS0_PIN_SEL><constant>
//   <i> Shows which pin SPI0_PCS0 is mapped to
//     <0=> Disabled
//     <1=> PTC4
//     <2=> PTD0
#define SPI0_PCS0_PIN_SEL    0                   
#if SPI0_PCS0_PIN_SEL == 1
#define SPI0_PCS0_GPIO       digitalIO_PTC4      
#define SPI0_PCS0_FN         2                   
#elif SPI0_PCS0_PIN_SEL == 2
#define SPI0_PCS0_GPIO       digitalIO_PTD0      
#define SPI0_PCS0_FN         2                   
#endif

// Pin Mapping for SPI0_PCS1 signal
//   <o> SPI0_PCS1 [PTC3, PTD4]<name=SPI0_PCS1_PIN_SEL><constant>
//   <i> Shows which pin SPI0_PCS1 is mapped to
//     <0=> Disabled
//     <1=> PTC3
//     <2=> PTD4
#define SPI0_PCS1_PIN_SEL    0                   
#if SPI0_PCS1_PIN_SEL == 1
#define SPI0_PCS1_GPIO       digitalIO_PTC3      
#define SPI0_PCS1_FN         2                   
#elif SPI0_PCS1_PIN_SEL == 2
#define SPI0_PCS1_GPIO       digitalIO_PTD4      
#define SPI0_PCS1_FN         2                   
#endif

// Pin Mapping for SPI0_PCS2 signal
//   <o> SPI0_PCS2 [PTC2, PTD5]<name=SPI0_PCS2_PIN_SEL><constant>
//   <i> Shows which pin SPI0_PCS2 is mapped to
//     <0=> Disabled
//     <1=> PTC2
//     <2=> PTD5
#define SPI0_PCS2_PIN_SEL    0                   
#if SPI0_PCS2_PIN_SEL == 1
#define SPI0_PCS2_GPIO       digitalIO_PTC2      
#define SPI0_PCS2_FN         2                   
#elif SPI0_PCS2_PIN_SEL == 2
#define SPI0_PCS2_GPIO       digitalIO_PTD5      
#define SPI0_PCS2_FN         2                   
#endif

// Pin Mapping for SPI0_PCS3 signal
//   <o> SPI0_PCS3 [PTC1, PTD6]<name=SPI0_PCS3_PIN_SEL><constant>
//   <i> Shows which pin SPI0_PCS3 is mapped to
//     <0=> Disabled
//     <1=> PTC1
//     <2=> PTD6
#define SPI0_PCS3_PIN_SEL    0                   
#if SPI0_PCS3_PIN_SEL == 1
#define SPI0_PCS3_GPIO       digitalIO_PTC1      
#define SPI0_PCS3_FN         2                   
#elif SPI0_PCS3_PIN_SEL == 2
#define SPI0_PCS3_GPIO       digitalIO_PTD6      
#define SPI0_PCS3_FN         2                   
#endif

// Pin Mapping for SPI0_PCS4 signal
//   <o> SPI0_PCS4 [PTC0]<name=SPI0_PCS4_PIN_SEL><constant>
//   <i> Shows which pin SPI0_PCS4 is mapped to
//     <0=> Disabled
//     <1=> PTC0
#define SPI0_PCS4_PIN_SEL    0                   
#if SPI0_PCS4_PIN_SEL == 1
#define SPI0_PCS4_GPIO       digitalIO_PTC0      
#define SPI0_PCS4_FN         2                   
#endif

// Pin Mapping for SPI0_SCK signal
//   <o> SPI0_SCK [PTC5, PTD1]<name=SPI0_SCK_PIN_SEL><constant>
//   <i> Shows which pin SPI0_SCK is mapped to
//     <0=> Disabled
//     <1=> PTC5
//     <2=> PTD1
#define SPI0_SCK_PIN_SEL     2                   
#if SPI0_SCK_PIN_SEL == 1
#define SPI0_SCK_GPIO        digitalIO_PTC5      
#define SPI0_SCK_FN          2                   
#elif SPI0_SCK_PIN_SEL == 2
#define SPI0_SCK_GPIO        digitalIO_PTD1      
#define SPI0_SCK_FN          2                   
#endif

// Pin Mapping for SPI0_SIN signal
//   <o> SPI0_SIN [PTC7, PTD3]<name=SPI0_SIN_PIN_SEL><constant>
//   <i> Shows which pin SPI0_SIN is mapped to
//     <0=> Disabled
//     <1=> PTC7
//     <2=> PTD3
#define SPI0_SIN_PIN_SEL     2                   
#if SPI0_SIN_PIN_SEL == 1
#define SPI0_SIN_GPIO        digitalIO_PTC7      
#define SPI0_SIN_FN          2                   
#elif SPI0_SIN_PIN_SEL == 2
#define SPI0_SIN_GPIO        digitalIO_PTD3      
#define SPI0_SIN_FN          2                   
#endif

// Pin Mapping for SPI0_SOUT signal
//   <o> SPI0_SOUT [PTC6, PTD2]<name=SPI0_SOUT_PIN_SEL><constant>
//   <i> Shows which pin SPI0_SOUT is mapped to
//     <0=> Disabled
//     <1=> PTC6
//     <2=> PTD2
#define SPI0_SOUT_PIN_SEL    2                   
#if SPI0_SOUT_PIN_SEL == 1
#define SPI0_SOUT_GPIO       digitalIO_PTC6      
#define SPI0_SOUT_FN         2                   
#elif SPI0_SOUT_PIN_SEL == 2
#define SPI0_SOUT_GPIO       digitalIO_PTD2      
#define SPI0_SOUT_FN         2                   
#endif

// </e>

//-------- <<< end of configuration section >>> -----------------  

#define FIXED_ADC_FN         0                    // Fixed ADC Multiplexing value
#define FIXED_GPIO_FN        1                    // Fixed GPIO Multiplexing value
#define FIXED_PORT_CLOCK_REG SIM->SCGC5           // Fixed PORT Clock
#define ADC0_CLOCK_REG       SIM->SCGC6          
#define ADC0_CLOCK_MASK      SIM_SCGC6_ADC0_MASK 
#define CMP_CLOCK_REG        SIM->SCGC4          
#define CMP_CLOCK_MASK       SIM_SCGC4_CMP_MASK  
#define CMT_CLOCK_REG        SIM->SCGC4          
#define CMT_CLOCK_MASK       SIM_SCGC4_CMT_MASK  
#define CRC_CLOCK_REG        SIM->SCGC6          
#define CRC_CLOCK_MASK       SIM_SCGC6_CRC_MASK  
#define DMA_CLOCK_REG        SIM->SCGC7          
#define DMA_CLOCK_MASK       SIM_SCGC7_DMA_MASK  
#define DMAMUX_CLOCK_REG     SIM->SCGC6          
#define DMAMUX_CLOCK_MASK    SIM_SCGC6_DMAMUX_MASK
#define EWM_CLOCK_REG        SIM->SCGC4          
#define EWM_CLOCK_MASK       SIM_SCGC4_EWM_MASK  
#define FTM0_CLOCK_REG       SIM->SCGC6          
#define FTM0_CLOCK_MASK      SIM_SCGC6_FTM0_MASK 
#define FTM1_CLOCK_REG       SIM->SCGC6          
#define FTM1_CLOCK_MASK      SIM_SCGC6_FTM1_MASK 
#define I2C0_CLOCK_REG       SIM->SCGC4          
#define I2C0_CLOCK_MASK      SIM_SCGC4_I2C0_MASK 
#define I2S0_CLOCK_REG       SIM->SCGC6          
#define I2S0_CLOCK_MASK      SIM_SCGC6_I2S0_MASK 
#define LPTMR0_CLOCK_REG     SIM->SCGC5          
#define LPTMR0_CLOCK_MASK    SIM_SCGC5_LPTMR_MASK
#define PDB0_CLOCK_REG       SIM->SCGC6          
#define PDB0_CLOCK_MASK      SIM_SCGC6_PDB0_MASK 
#define PIT_CLOCK_REG        SIM->SCGC6          
#define PIT_CLOCK_MASK       SIM_SCGC6_PIT_MASK  
#define PORTA_CLOCK_REG      SIM->SCGC5          
#define PORTA_CLOCK_MASK     SIM_SCGC5_PORTA_MASK
#define PORTB_CLOCK_REG      SIM->SCGC5          
#define PORTB_CLOCK_MASK     SIM_SCGC5_PORTB_MASK
#define PORTC_CLOCK_REG      SIM->SCGC5          
#define PORTC_CLOCK_MASK     SIM_SCGC5_PORTC_MASK
#define PORTD_CLOCK_REG      SIM->SCGC5          
#define PORTD_CLOCK_MASK     SIM_SCGC5_PORTD_MASK
#define PORTE_CLOCK_REG      SIM->SCGC5          
#define PORTE_CLOCK_MASK     SIM_SCGC5_PORTE_MASK
#define RTC_CLOCK_REG        SIM->SCGC6          
#define RTC_CLOCK_MASK       SIM_SCGC6_RTC_MASK  
#define SPI0_CLOCK_REG       SIM->SCGC6          
#define SPI0_CLOCK_MASK      SIM_SCGC6_SPI0_MASK 
#define TSI_CLOCK_REG        SIM->SCGC5          
#define TSI_CLOCK_MASK       SIM_SCGC5_TSI_MASK  
#define UART0_CLOCK_REG      SIM->SCGC4          
#define UART0_CLOCK_MASK     SIM_SCGC4_UART0_MASK
#define UART1_CLOCK_REG      SIM->SCGC4          
#define UART1_CLOCK_MASK     SIM_SCGC4_UART1_MASK
#define UART2_CLOCK_REG      SIM->SCGC4          
#define UART2_CLOCK_MASK     SIM_SCGC4_UART2_MASK
#define USBDCD_CLOCK_REG     SIM->SCGC6          
#define USBDCD_CLOCK_MASK    SIM_SCGC6_USBDCD_MASK
#define USBOTG_CLOCK_REG     SIM->SCGC4          
#define USBOTG_CLOCK_MASK    SIM_SCGC4_USBOTG_MASK
#define VREF_CLOCK_REG       SIM->SCGC4          
#define VREF_CLOCK_MASK      SIM_SCGC4_VREF_MASK 
#define PORT_CLOCK_REG       SIM->SCGC5          


#endif /* PIN_MAPPING_H_ */
