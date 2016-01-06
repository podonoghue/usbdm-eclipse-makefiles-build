/**
 * @file      pin_mapping.h (derived from pin_mapping-MK22F12.h)
 * @version   1.1.0
 * @brief     Pin declarations for MK22F12
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

constexpr uint16_t FTM0_SC              = (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0));

} // End namespace

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

constexpr uint16_t FTM1_SC              = (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0));

} // End namespace

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

constexpr uint16_t FTM2_SC              = (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0));

} // End namespace

// </h>

// <h> Clock settings for FTM3

// FTM3_SC.CLKS ================================
//
//   <o> FTM3_SC.CLKS Clock source
//   <i> Selects the clock source for the FTM3 module. [FTM3_SC.CLKS]
//     <0=> Disabled
//     <1=> System clock
//     <2=> Fixed frequency clock
//     <3=> External clock
//     <1=> Default
// FTM3_SC.PS ================================
//
//   <o1> FTM3_SC.PS Clock prescaler
//   <i> Selects the prescaler for the FTM3 module. [FTM3_SC.PS]
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

constexpr uint16_t FTM3_SC              = (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0));

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

// <h> Miscellaneous Pins

// Signal mapping for ADC0_DM0 pin
//   <o> ADC0_DM0 [ADC0_DM0/ADC1_DM3]<name=ADC0_DM0_SIG_SEL><constant>
//   <i> ADC0_DM0 has no pin-mapping hardware
//     <-3=> ADC0_DM0/ADC1_DM3 (fixed)<selection=ADC0_DM0_PIN_SEL,ADC0_DM0><selection=ADC1_DM3_PIN_SEL,ADC0_DM0>
#define ADC0_DM0_SIG_SEL     -3

// Signal mapping for ADC0_DP0 pin
//   <o> ADC0_DP0 [ADC0_DP0/ADC1_DP3]<name=ADC0_DP0_SIG_SEL><constant>
//   <i> ADC0_DP0 has no pin-mapping hardware
//     <-3=> ADC0_DP0/ADC1_DP3 (fixed)<selection=ADC0_DP0_PIN_SEL,ADC0_DP0><selection=ADC1_DP3_PIN_SEL,ADC0_DP0>
#define ADC0_DP0_SIG_SEL     -3

// Signal mapping for ADC0_SE23 pin
//   <o> ADC0_SE23 [DAC0_OUT/CMP1_IN3/ADC0_SE23]<name=ADC0_SE23_SIG_SEL><constant>
//   <i> ADC0_SE23 has no pin-mapping hardware
//     <-3=> DAC0_OUT/CMP1_IN3/ADC0_SE23 (fixed)<selection=DAC0_OUT_PIN_SEL,ADC0_SE23><selection=CMP1_IN3_PIN_SEL,ADC0_SE23><selection=ADC0_SE23_PIN_SEL,ADC0_SE23>
#define ADC0_SE23_SIG_SEL    -3

// Signal mapping for ADC1_DM0 pin
//   <o> ADC1_DM0 [ADC1_DM0/ADC0_DM3]<name=ADC1_DM0_SIG_SEL><constant>
//   <i> ADC1_DM0 has no pin-mapping hardware
//     <-3=> ADC1_DM0/ADC0_DM3 (fixed)<selection=ADC1_DM0_PIN_SEL,ADC1_DM0><selection=ADC0_DM3_PIN_SEL,ADC1_DM0>
#define ADC1_DM0_SIG_SEL     -3

// Signal mapping for ADC1_DP0 pin
//   <o> ADC1_DP0 [ADC1_DP0/ADC0_DP3]<name=ADC1_DP0_SIG_SEL><constant>
//   <i> ADC1_DP0 has no pin-mapping hardware
//     <-3=> ADC1_DP0/ADC0_DP3 (fixed)<selection=ADC1_DP0_PIN_SEL,ADC1_DP0><selection=ADC0_DP3_PIN_SEL,ADC1_DP0>
#define ADC1_DP0_SIG_SEL     -3

// Signal mapping for ADC1_SE18 pin
//   <o> ADC1_SE18 [VREF_OUT/CMP1_IN5/CMP0_IN5/ADC1_SE18]<name=ADC1_SE18_SIG_SEL><constant>
//   <i> ADC1_SE18 has no pin-mapping hardware
//     <-3=> VREF_OUT/CMP1_IN5/CMP0_IN5/ADC1_SE18 (fixed)<selection=VREF_OUT_PIN_SEL,ADC1_SE18><selection=CMP1_IN5_PIN_SEL,ADC1_SE18><selection=CMP0_IN5_PIN_SEL,ADC1_SE18><selection=ADC1_SE18_PIN_SEL,ADC1_SE18>
#define ADC1_SE18_SIG_SEL    -3

// Signal mapping for EXTAL32 pin
//   <o> EXTAL32 [EXTAL32]<name=EXTAL32_SIG_SEL><constant>
//   <i> EXTAL32 has no pin-mapping hardware
//     <-3=> EXTAL32 (fixed)<selection=EXTAL32_PIN_SEL,EXTAL32>
#define EXTAL32_SIG_SEL      -3

// Signal mapping for XTAL32 pin
//   <o> XTAL32 [XTAL32]<name=XTAL32_SIG_SEL><constant>
//   <i> XTAL32 has no pin-mapping hardware
//     <-3=> XTAL32 (fixed)<selection=XTAL32_PIN_SEL,XTAL32>
#define XTAL32_SIG_SEL       -3

// </h>

// <h> Port A Pins

// Signal mapping for PTA0 pin
//   <o> PTA0 [GPIOA_0, UART0_CTS_b, FTM0_CH5, JTAG_TCLK/SWD_CLK]<name=PTA0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA0 pin
//     <-2=> GPIOA_0 (reset default)<selection=GPIOA_0_PIN_SEL,PTA0 (reset default)>
//     <1=> GPIOA_0<selection=GPIOA_0_PIN_SEL,PTA0>
//     <2=> UART0_CTS_b<selection=UART0_CTS_b_PIN_SEL,PTA0>
//     <3=> FTM0_CH5<selection=FTM0_CH5_PIN_SEL,PTA0>
//     <7=> JTAG_TCLK/SWD_CLK<selection=JTAG_TCLK_PIN_SEL,PTA0><selection=SWD_CLK_PIN_SEL,PTA0>
//     <7=> Default
#define PTA0_SIG_SEL         7

// Signal mapping for PTA1 pin
//   <o> PTA1 [GPIOA_1, UART0_RX, FTM0_CH6, JTAG_TDI]<name=PTA1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA1 pin
//     <-2=> GPIOA_1 (reset default)<selection=GPIOA_1_PIN_SEL,PTA1 (reset default)>
//     <1=> GPIOA_1<selection=GPIOA_1_PIN_SEL,PTA1>
//     <2=> UART0_RX<selection=UART0_RX_PIN_SEL,PTA1>
//     <3=> FTM0_CH6<selection=FTM0_CH6_PIN_SEL,PTA1>
//     <7=> JTAG_TDI<selection=JTAG_TDI_PIN_SEL,PTA1>
//     <7=> Default
#define PTA1_SIG_SEL         7

// Signal mapping for PTA2 pin
//   <o> PTA2 [GPIOA_2, UART0_TX, FTM0_CH7, JTAG_TDO/TRACE_SWO]<name=PTA2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA2 pin
//     <-2=> GPIOA_2 (reset default)<selection=GPIOA_2_PIN_SEL,PTA2 (reset default)>
//     <1=> GPIOA_2<selection=GPIOA_2_PIN_SEL,PTA2>
//     <2=> UART0_TX<selection=UART0_TX_PIN_SEL,PTA2>
//     <3=> FTM0_CH7<selection=FTM0_CH7_PIN_SEL,PTA2>
//     <7=> JTAG_TDO/TRACE_SWO<selection=JTAG_TDO_PIN_SEL,PTA2><selection=TRACE_SWO_PIN_SEL,PTA2>
//     <7=> Default
#define PTA2_SIG_SEL         7

// Signal mapping for PTA3 pin
//   <o> PTA3 [GPIOA_3, UART0_RTS_b, FTM0_CH0, JTAG_TMS/SWD_DIO]<name=PTA3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA3 pin
//     <-2=> GPIOA_3 (reset default)<selection=GPIOA_3_PIN_SEL,PTA3 (reset default)>
//     <1=> GPIOA_3<selection=GPIOA_3_PIN_SEL,PTA3>
//     <2=> UART0_RTS_b<selection=UART0_RTS_b_PIN_SEL,PTA3>
//     <3=> FTM0_CH0<selection=FTM0_CH0_PIN_SEL,PTA3>
//     <7=> JTAG_TMS/SWD_DIO<selection=JTAG_TMS_PIN_SEL,PTA3><selection=SWD_DIO_PIN_SEL,PTA3>
//     <7=> Default
#define PTA3_SIG_SEL         7

// Signal mapping for PTA4 pin
//   <o> PTA4 [GPIOA_4/LLWU_P3, FTM0_CH1, NMI_b]<name=PTA4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA4 pin
//     <-2=> GPIOA_4/LLWU_P3 (reset default)<selection=GPIOA_4_PIN_SEL,PTA4 (reset default)><selection=LLWU_P3_PIN_SEL,PTA4 (reset default)>
//     <1=> GPIOA_4/LLWU_P3<selection=GPIOA_4_PIN_SEL,PTA4><selection=LLWU_P3_PIN_SEL,PTA4>
//     <3=> FTM0_CH1<selection=FTM0_CH1_PIN_SEL,PTA4>
//     <7=> NMI_b<selection=NMI_b_PIN_SEL,PTA4>
//     <7=> Default
#define PTA4_SIG_SEL         7

// Signal mapping for PTA5 pin
//   <o> PTA5 [GPIOA_5, USB_CLKIN, FTM0_CH2, CMP2_OUT, I2S0_TX_BCLK, JTAG_TRST_b]<name=PTA5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA5 pin
//     <-2=> GPIOA_5 (reset default)<selection=GPIOA_5_PIN_SEL,PTA5 (reset default)>
//     <1=> GPIOA_5<selection=GPIOA_5_PIN_SEL,PTA5>
//     <2=> USB_CLKIN<selection=USB_CLKIN_PIN_SEL,PTA5>
//     <3=> FTM0_CH2<selection=FTM0_CH2_PIN_SEL,PTA5>
//     <5=> CMP2_OUT<selection=CMP2_OUT_PIN_SEL,PTA5>
//     <6=> I2S0_TX_BCLK<selection=I2S0_TX_BCLK_PIN_SEL,PTA5>
//     <7=> JTAG_TRST_b<selection=JTAG_TRST_b_PIN_SEL,PTA5>
//     <-2=> Default
#define PTA5_SIG_SEL         -2

// Signal mapping for PTA12 pin
//   <o> PTA12 [CMP2_IN0, GPIOA_12, CAN0_TX, FTM1_CH0, I2C2_SCL, I2S0_TXD0, FTM1_QD_PHA]<name=PTA12_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA12 pin
//     <-2=> GPIOA_12 (reset default)<selection=GPIOA_12_PIN_SEL,PTA12 (reset default)>
//     <0=> CMP2_IN0<selection=CMP2_IN0_PIN_SEL,PTA12>
//     <1=> GPIOA_12<selection=GPIOA_12_PIN_SEL,PTA12>
//     <2=> CAN0_TX<selection=CAN0_TX_PIN_SEL,PTA12>
//     <3=> FTM1_CH0<selection=FTM1_CH0_PIN_SEL,PTA12>
//     <5=> I2C2_SCL<selection=I2C2_SCL_PIN_SEL,PTA12>
//     <6=> I2S0_TXD0<selection=I2S0_TXD0_PIN_SEL,PTA12>
//     <7=> FTM1_QD_PHA<selection=FTM1_QD_PHA_PIN_SEL,PTA12>
//     <0=> Default
#define PTA12_SIG_SEL        0

// Signal mapping for PTA13 pin
//   <o> PTA13 [CMP2_IN1, GPIOA_13/LLWU_P4, CAN0_RX, FTM1_CH1, I2C2_SDA, I2S0_TX_FS, FTM1_QD_PHB]<name=PTA13_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA13 pin
//     <-2=> GPIOA_13/LLWU_P4 (reset default)<selection=GPIOA_13_PIN_SEL,PTA13 (reset default)><selection=LLWU_P4_PIN_SEL,PTA13 (reset default)>
//     <0=> CMP2_IN1<selection=CMP2_IN1_PIN_SEL,PTA13>
//     <1=> GPIOA_13/LLWU_P4<selection=GPIOA_13_PIN_SEL,PTA13><selection=LLWU_P4_PIN_SEL,PTA13>
//     <2=> CAN0_RX<selection=CAN0_RX_PIN_SEL,PTA13>
//     <3=> FTM1_CH1<selection=FTM1_CH1_PIN_SEL,PTA13>
//     <5=> I2C2_SDA<selection=I2C2_SDA_PIN_SEL,PTA13>
//     <6=> I2S0_TX_FS<selection=I2S0_TX_FS_PIN_SEL,PTA13>
//     <7=> FTM1_QD_PHB<selection=FTM1_QD_PHB_PIN_SEL,PTA13>
//     <0=> Default
#define PTA13_SIG_SEL        0

// Signal mapping for PTA18 pin
//   <o> PTA18 [EXTAL0, GPIOA_18, FTM0_FLT2, FTM_CLKIN0]<name=PTA18_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA18 pin
//     <-2=> GPIOA_18 (reset default)<selection=GPIOA_18_PIN_SEL,PTA18 (reset default)>
//     <0=> EXTAL0<selection=EXTAL0_PIN_SEL,PTA18>
//     <1=> GPIOA_18<selection=GPIOA_18_PIN_SEL,PTA18>
//     <3=> FTM0_FLT2<selection=FTM0_FLT2_PIN_SEL,PTA18>
//     <4=> FTM_CLKIN0<selection=FTM_CLKIN0_PIN_SEL,PTA18>
//     <0=> Default
#define PTA18_SIG_SEL        0

// Signal mapping for PTA19 pin
//   <o> PTA19 [XTAL0, GPIOA_19, FTM1_FLT0, FTM_CLKIN1, LPTMR0_ALT1]<name=PTA19_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA19 pin
//     <-2=> GPIOA_19 (reset default)<selection=GPIOA_19_PIN_SEL,PTA19 (reset default)>
//     <0=> XTAL0<selection=XTAL0_PIN_SEL,PTA19>
//     <1=> GPIOA_19<selection=GPIOA_19_PIN_SEL,PTA19>
//     <3=> FTM1_FLT0<selection=FTM1_FLT0_PIN_SEL,PTA19>
//     <4=> FTM_CLKIN1<selection=FTM_CLKIN1_PIN_SEL,PTA19>
//     <6=> LPTMR0_ALT1<selection=LPTMR0_ALT1_PIN_SEL,PTA19>
//     <0=> Default
#define PTA19_SIG_SEL        0

// </h>

// <h> Port B Pins

// Signal mapping for PTB0 pin
//   <o> PTB0 [ADC0_SE8/ADC1_SE8, GPIOB_0/LLWU_P5, I2C0_SCL, FTM1_CH0, FTM1_QD_PHA]<name=PTB0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB0 pin
//     <-2=> GPIOB_0/LLWU_P5 (reset default)<selection=GPIOB_0_PIN_SEL,PTB0 (reset default)><selection=LLWU_P5_PIN_SEL,PTB0 (reset default)>
//     <0=> ADC0_SE8/ADC1_SE8<selection=ADC0_SE8_PIN_SEL,PTB0><selection=ADC1_SE8_PIN_SEL,PTB0>
//     <1=> GPIOB_0/LLWU_P5<selection=GPIOB_0_PIN_SEL,PTB0><selection=LLWU_P5_PIN_SEL,PTB0>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTB0>
//     <3=> FTM1_CH0<selection=FTM1_CH0_PIN_SEL,PTB0>
//     <6=> FTM1_QD_PHA<selection=FTM1_QD_PHA_PIN_SEL,PTB0>
//     <0=> Default
#define PTB0_SIG_SEL         0

// Signal mapping for PTB1 pin
//   <o> PTB1 [ADC0_SE9/ADC1_SE9, GPIOB_1, I2C0_SDA, FTM1_CH1, FTM1_QD_PHB]<name=PTB1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB1 pin
//     <-2=> GPIOB_1 (reset default)<selection=GPIOB_1_PIN_SEL,PTB1 (reset default)>
//     <0=> ADC0_SE9/ADC1_SE9<selection=ADC0_SE9_PIN_SEL,PTB1><selection=ADC1_SE9_PIN_SEL,PTB1>
//     <1=> GPIOB_1<selection=GPIOB_1_PIN_SEL,PTB1>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTB1>
//     <3=> FTM1_CH1<selection=FTM1_CH1_PIN_SEL,PTB1>
//     <6=> FTM1_QD_PHB<selection=FTM1_QD_PHB_PIN_SEL,PTB1>
//     <0=> Default
#define PTB1_SIG_SEL         0

// Signal mapping for PTB2 pin
//   <o> PTB2 [ADC0_SE12, GPIOB_2, I2C0_SCL, UART0_RTS_b, FTM0_FLT3]<name=PTB2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB2 pin
//     <-2=> GPIOB_2 (reset default)<selection=GPIOB_2_PIN_SEL,PTB2 (reset default)>
//     <0=> ADC0_SE12<selection=ADC0_SE12_PIN_SEL,PTB2>
//     <1=> GPIOB_2<selection=GPIOB_2_PIN_SEL,PTB2>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTB2>
//     <3=> UART0_RTS_b<selection=UART0_RTS_b_PIN_SEL,PTB2>
//     <6=> FTM0_FLT3<selection=FTM0_FLT3_PIN_SEL,PTB2>
//     <0=> Default
#define PTB2_SIG_SEL         0

// Signal mapping for PTB3 pin
//   <o> PTB3 [ADC0_SE13, GPIOB_3, I2C0_SDA, UART0_CTS_b, FTM0_FLT0]<name=PTB3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB3 pin
//     <-2=> GPIOB_3 (reset default)<selection=GPIOB_3_PIN_SEL,PTB3 (reset default)>
//     <0=> ADC0_SE13<selection=ADC0_SE13_PIN_SEL,PTB3>
//     <1=> GPIOB_3<selection=GPIOB_3_PIN_SEL,PTB3>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTB3>
//     <3=> UART0_CTS_b<selection=UART0_CTS_b_PIN_SEL,PTB3>
//     <6=> FTM0_FLT0<selection=FTM0_FLT0_PIN_SEL,PTB3>
//     <0=> Default
#define PTB3_SIG_SEL         0

// Signal mapping for PTB16 pin
//   <o> PTB16 [GPIOB_16, UART0_RX, FTM_CLKIN0, FB_AD17, EWM_IN]<name=PTB16_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB16 pin
//     <-2=> GPIOB_16 (reset default)<selection=GPIOB_16_PIN_SEL,PTB16 (reset default)>
//     <1=> GPIOB_16<selection=GPIOB_16_PIN_SEL,PTB16>
//     <3=> UART0_RX<selection=UART0_RX_PIN_SEL,PTB16>
//     <4=> FTM_CLKIN0<selection=FTM_CLKIN0_PIN_SEL,PTB16>
//     <5=> FB_AD17<selection=FB_AD17_PIN_SEL,PTB16>
//     <6=> EWM_IN<selection=EWM_IN_PIN_SEL,PTB16>
//     <-2=> Default
#define PTB16_SIG_SEL        -2

// Signal mapping for PTB17 pin
//   <o> PTB17 [GPIOB_17, UART0_TX, FTM_CLKIN1, FB_AD16, EWM_OUT_b]<name=PTB17_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB17 pin
//     <-2=> GPIOB_17 (reset default)<selection=GPIOB_17_PIN_SEL,PTB17 (reset default)>
//     <1=> GPIOB_17<selection=GPIOB_17_PIN_SEL,PTB17>
//     <3=> UART0_TX<selection=UART0_TX_PIN_SEL,PTB17>
//     <4=> FTM_CLKIN1<selection=FTM_CLKIN1_PIN_SEL,PTB17>
//     <5=> FB_AD16<selection=FB_AD16_PIN_SEL,PTB17>
//     <6=> EWM_OUT_b<selection=EWM_OUT_b_PIN_SEL,PTB17>
//     <-2=> Default
#define PTB17_SIG_SEL        -2

// Signal mapping for PTB18 pin
//   <o> PTB18 [GPIOB_18, CAN0_TX, FTM2_CH0, I2S0_TX_BCLK, FB_AD15, FTM2_QD_PHA]<name=PTB18_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB18 pin
//     <-2=> GPIOB_18 (reset default)<selection=GPIOB_18_PIN_SEL,PTB18 (reset default)>
//     <1=> GPIOB_18<selection=GPIOB_18_PIN_SEL,PTB18>
//     <2=> CAN0_TX<selection=CAN0_TX_PIN_SEL,PTB18>
//     <3=> FTM2_CH0<selection=FTM2_CH0_PIN_SEL,PTB18>
//     <4=> I2S0_TX_BCLK<selection=I2S0_TX_BCLK_PIN_SEL,PTB18>
//     <5=> FB_AD15<selection=FB_AD15_PIN_SEL,PTB18>
//     <6=> FTM2_QD_PHA<selection=FTM2_QD_PHA_PIN_SEL,PTB18>
//     <-2=> Default
#define PTB18_SIG_SEL        -2

// Signal mapping for PTB19 pin
//   <o> PTB19 [GPIOB_19, CAN0_RX, FTM2_CH1, I2S0_TX_FS, FB_OE_b, FTM2_QD_PHB]<name=PTB19_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB19 pin
//     <-2=> GPIOB_19 (reset default)<selection=GPIOB_19_PIN_SEL,PTB19 (reset default)>
//     <1=> GPIOB_19<selection=GPIOB_19_PIN_SEL,PTB19>
//     <2=> CAN0_RX<selection=CAN0_RX_PIN_SEL,PTB19>
//     <3=> FTM2_CH1<selection=FTM2_CH1_PIN_SEL,PTB19>
//     <4=> I2S0_TX_FS<selection=I2S0_TX_FS_PIN_SEL,PTB19>
//     <5=> FB_OE_b<selection=FB_OE_b_PIN_SEL,PTB19>
//     <6=> FTM2_QD_PHB<selection=FTM2_QD_PHB_PIN_SEL,PTB19>
//     <-2=> Default
#define PTB19_SIG_SEL        -2

// </h>

// <h> Port C Pins

// Signal mapping for PTC0 pin
//   <o> PTC0 [ADC0_SE14, GPIOC_0, SPI0_PCS4, PDB0_EXTRG, FB_AD14, I2S0_TXD1]<name=PTC0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC0 pin
//     <-2=> GPIOC_0 (reset default)<selection=GPIOC_0_PIN_SEL,PTC0 (reset default)>
//     <0=> ADC0_SE14<selection=ADC0_SE14_PIN_SEL,PTC0>
//     <1=> GPIOC_0<selection=GPIOC_0_PIN_SEL,PTC0>
//     <2=> SPI0_PCS4<selection=SPI0_PCS4_PIN_SEL,PTC0>
//     <3=> PDB0_EXTRG<selection=PDB0_EXTRG_PIN_SEL,PTC0>
//     <5=> FB_AD14<selection=FB_AD14_PIN_SEL,PTC0>
//     <6=> I2S0_TXD1<selection=I2S0_TXD1_PIN_SEL,PTC0>
//     <0=> Default
#define PTC0_SIG_SEL         0

// Signal mapping for PTC1 pin
//   <o> PTC1 [ADC0_SE15, GPIOC_1/LLWU_P6, SPI0_PCS3, UART1_RTS_b, FTM0_CH0, FB_AD13, I2S0_TXD0]<name=PTC1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC1 pin
//     <-2=> GPIOC_1/LLWU_P6 (reset default)<selection=GPIOC_1_PIN_SEL,PTC1 (reset default)><selection=LLWU_P6_PIN_SEL,PTC1 (reset default)>
//     <0=> ADC0_SE15<selection=ADC0_SE15_PIN_SEL,PTC1>
//     <1=> GPIOC_1/LLWU_P6<selection=GPIOC_1_PIN_SEL,PTC1><selection=LLWU_P6_PIN_SEL,PTC1>
//     <2=> SPI0_PCS3<selection=SPI0_PCS3_PIN_SEL,PTC1>
//     <3=> UART1_RTS_b<selection=UART1_RTS_b_PIN_SEL,PTC1>
//     <4=> FTM0_CH0<selection=FTM0_CH0_PIN_SEL,PTC1>
//     <5=> FB_AD13<selection=FB_AD13_PIN_SEL,PTC1>
//     <6=> I2S0_TXD0<selection=I2S0_TXD0_PIN_SEL,PTC1>
//     <0=> Default
#define PTC1_SIG_SEL         0

// Signal mapping for PTC2 pin
//   <o> PTC2 [ADC0_SE4b/CMP1_IN0, GPIOC_2, SPI0_PCS2, UART1_CTS_b, FTM0_CH1, FB_AD12, I2S0_TX_FS]<name=PTC2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC2 pin
//     <-2=> GPIOC_2 (reset default)<selection=GPIOC_2_PIN_SEL,PTC2 (reset default)>
//     <0=> ADC0_SE4b/CMP1_IN0<selection=ADC0_SE4b_PIN_SEL,PTC2><selection=CMP1_IN0_PIN_SEL,PTC2>
//     <1=> GPIOC_2<selection=GPIOC_2_PIN_SEL,PTC2>
//     <2=> SPI0_PCS2<selection=SPI0_PCS2_PIN_SEL,PTC2>
//     <3=> UART1_CTS_b<selection=UART1_CTS_b_PIN_SEL,PTC2>
//     <4=> FTM0_CH1<selection=FTM0_CH1_PIN_SEL,PTC2>
//     <5=> FB_AD12<selection=FB_AD12_PIN_SEL,PTC2>
//     <6=> I2S0_TX_FS<selection=I2S0_TX_FS_PIN_SEL,PTC2>
//     <0=> Default
#define PTC2_SIG_SEL         0

// Signal mapping for PTC3 pin
//   <o> PTC3 [CMP1_IN1, GPIOC_3/LLWU_P7, SPI0_PCS1, UART1_RX, FTM0_CH2, CLKOUT, I2S0_TX_BCLK]<name=PTC3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC3 pin
//     <-2=> GPIOC_3/LLWU_P7 (reset default)<selection=GPIOC_3_PIN_SEL,PTC3 (reset default)><selection=LLWU_P7_PIN_SEL,PTC3 (reset default)>
//     <0=> CMP1_IN1<selection=CMP1_IN1_PIN_SEL,PTC3>
//     <1=> GPIOC_3/LLWU_P7<selection=GPIOC_3_PIN_SEL,PTC3><selection=LLWU_P7_PIN_SEL,PTC3>
//     <2=> SPI0_PCS1<selection=SPI0_PCS1_PIN_SEL,PTC3>
//     <3=> UART1_RX<selection=UART1_RX_PIN_SEL,PTC3>
//     <4=> FTM0_CH2<selection=FTM0_CH2_PIN_SEL,PTC3>
//     <5=> CLKOUT<selection=CLKOUT_PIN_SEL,PTC3>
//     <6=> I2S0_TX_BCLK<selection=I2S0_TX_BCLK_PIN_SEL,PTC3>
//     <0=> Default
#define PTC3_SIG_SEL         0

// Signal mapping for PTC4 pin
//   <o> PTC4 [GPIOC_4/LLWU_P8, SPI0_PCS0, UART1_TX, FTM0_CH3, FB_AD11, CMP1_OUT]<name=PTC4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC4 pin
//     <-2=> GPIOC_4/LLWU_P8 (reset default)<selection=GPIOC_4_PIN_SEL,PTC4 (reset default)><selection=LLWU_P8_PIN_SEL,PTC4 (reset default)>
//     <1=> GPIOC_4/LLWU_P8<selection=GPIOC_4_PIN_SEL,PTC4><selection=LLWU_P8_PIN_SEL,PTC4>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTC4>
//     <3=> UART1_TX<selection=UART1_TX_PIN_SEL,PTC4>
//     <4=> FTM0_CH3<selection=FTM0_CH3_PIN_SEL,PTC4>
//     <5=> FB_AD11<selection=FB_AD11_PIN_SEL,PTC4>
//     <6=> CMP1_OUT<selection=CMP1_OUT_PIN_SEL,PTC4>
//     <-2=> Default
#define PTC4_SIG_SEL         -2

// Signal mapping for PTC5 pin
//   <o> PTC5 [GPIOC_5/LLWU_P9, SPI0_SCK, LPTMR0_ALT2, I2S0_RXD0, FB_AD10, CMP0_OUT, FTM0_CH2]<name=PTC5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC5 pin
//     <-2=> GPIOC_5/LLWU_P9 (reset default)<selection=GPIOC_5_PIN_SEL,PTC5 (reset default)><selection=LLWU_P9_PIN_SEL,PTC5 (reset default)>
//     <1=> GPIOC_5/LLWU_P9<selection=GPIOC_5_PIN_SEL,PTC5><selection=LLWU_P9_PIN_SEL,PTC5>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTC5>
//     <3=> LPTMR0_ALT2<selection=LPTMR0_ALT2_PIN_SEL,PTC5>
//     <4=> I2S0_RXD0<selection=I2S0_RXD0_PIN_SEL,PTC5>
//     <5=> FB_AD10<selection=FB_AD10_PIN_SEL,PTC5>
//     <6=> CMP0_OUT<selection=CMP0_OUT_PIN_SEL,PTC5>
//     <7=> FTM0_CH2<selection=FTM0_CH2_PIN_SEL,PTC5>
//     <-2=> Default
#define PTC5_SIG_SEL         -2

// Signal mapping for PTC6 pin
//   <o> PTC6 [CMP0_IN0, GPIOC_6/LLWU_P10, SPI0_SOUT, PDB0_EXTRG, I2S0_RX_BCLK, FB_AD9, I2S0_MCLK]<name=PTC6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC6 pin
//     <-2=> GPIOC_6/LLWU_P10 (reset default)<selection=GPIOC_6_PIN_SEL,PTC6 (reset default)><selection=LLWU_P10_PIN_SEL,PTC6 (reset default)>
//     <0=> CMP0_IN0<selection=CMP0_IN0_PIN_SEL,PTC6>
//     <1=> GPIOC_6/LLWU_P10<selection=GPIOC_6_PIN_SEL,PTC6><selection=LLWU_P10_PIN_SEL,PTC6>
//     <2=> SPI0_SOUT<selection=SPI0_SOUT_PIN_SEL,PTC6>
//     <3=> PDB0_EXTRG<selection=PDB0_EXTRG_PIN_SEL,PTC6>
//     <4=> I2S0_RX_BCLK<selection=I2S0_RX_BCLK_PIN_SEL,PTC6>
//     <5=> FB_AD9<selection=FB_AD9_PIN_SEL,PTC6>
//     <6=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTC6>
//     <0=> Default
#define PTC6_SIG_SEL         0

// Signal mapping for PTC7 pin
//   <o> PTC7 [CMP0_IN1, GPIOC_7, SPI0_SIN, USB_SOF_OUT, I2S0_RX_FS, FB_AD8]<name=PTC7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC7 pin
//     <-2=> GPIOC_7 (reset default)<selection=GPIOC_7_PIN_SEL,PTC7 (reset default)>
//     <0=> CMP0_IN1<selection=CMP0_IN1_PIN_SEL,PTC7>
//     <1=> GPIOC_7<selection=GPIOC_7_PIN_SEL,PTC7>
//     <2=> SPI0_SIN<selection=SPI0_SIN_PIN_SEL,PTC7>
//     <3=> USB_SOF_OUT<selection=USB_SOF_OUT_PIN_SEL,PTC7>
//     <4=> I2S0_RX_FS<selection=I2S0_RX_FS_PIN_SEL,PTC7>
//     <5=> FB_AD8<selection=FB_AD8_PIN_SEL,PTC7>
//     <0=> Default
#define PTC7_SIG_SEL         0

// Signal mapping for PTC8 pin
//   <o> PTC8 [ADC1_SE4b/CMP0_IN2, GPIOC_8, FTM3_CH4, I2S0_MCLK, FB_AD7]<name=PTC8_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC8 pin
//     <-2=> GPIOC_8 (reset default)<selection=GPIOC_8_PIN_SEL,PTC8 (reset default)>
//     <0=> ADC1_SE4b/CMP0_IN2<selection=ADC1_SE4b_PIN_SEL,PTC8><selection=CMP0_IN2_PIN_SEL,PTC8>
//     <1=> GPIOC_8<selection=GPIOC_8_PIN_SEL,PTC8>
//     <3=> FTM3_CH4<selection=FTM3_CH4_PIN_SEL,PTC8>
//     <4=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTC8>
//     <5=> FB_AD7<selection=FB_AD7_PIN_SEL,PTC8>
//     <0=> Default
#define PTC8_SIG_SEL         0

// Signal mapping for PTC9 pin
//   <o> PTC9 [ADC1_SE5b/CMP0_IN3, GPIOC_9, FTM3_CH5, I2S0_RX_BCLK, FB_AD6, FTM2_FLT0]<name=PTC9_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC9 pin
//     <-2=> GPIOC_9 (reset default)<selection=GPIOC_9_PIN_SEL,PTC9 (reset default)>
//     <0=> ADC1_SE5b/CMP0_IN3<selection=ADC1_SE5b_PIN_SEL,PTC9><selection=CMP0_IN3_PIN_SEL,PTC9>
//     <1=> GPIOC_9<selection=GPIOC_9_PIN_SEL,PTC9>
//     <3=> FTM3_CH5<selection=FTM3_CH5_PIN_SEL,PTC9>
//     <4=> I2S0_RX_BCLK<selection=I2S0_RX_BCLK_PIN_SEL,PTC9>
//     <5=> FB_AD6<selection=FB_AD6_PIN_SEL,PTC9>
//     <6=> FTM2_FLT0<selection=FTM2_FLT0_PIN_SEL,PTC9>
//     <0=> Default
#define PTC9_SIG_SEL         0

// Signal mapping for PTC10 pin
//   <o> PTC10 [ADC1_SE6b, GPIOC_10, I2C1_SCL, FTM3_CH6, I2S0_RX_FS, FB_AD5]<name=PTC10_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC10 pin
//     <-2=> GPIOC_10 (reset default)<selection=GPIOC_10_PIN_SEL,PTC10 (reset default)>
//     <0=> ADC1_SE6b<selection=ADC1_SE6b_PIN_SEL,PTC10>
//     <1=> GPIOC_10<selection=GPIOC_10_PIN_SEL,PTC10>
//     <2=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTC10>
//     <3=> FTM3_CH6<selection=FTM3_CH6_PIN_SEL,PTC10>
//     <4=> I2S0_RX_FS<selection=I2S0_RX_FS_PIN_SEL,PTC10>
//     <5=> FB_AD5<selection=FB_AD5_PIN_SEL,PTC10>
//     <0=> Default
#define PTC10_SIG_SEL        0

// Signal mapping for PTC11 pin
//   <o> PTC11 [ADC1_SE7b, GPIOC_11/LLWU_P11, I2C1_SDA, FTM3_CH7, I2S0_RXD1, FB_RW_b]<name=PTC11_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC11 pin
//     <-2=> GPIOC_11/LLWU_P11 (reset default)<selection=GPIOC_11_PIN_SEL,PTC11 (reset default)><selection=LLWU_P11_PIN_SEL,PTC11 (reset default)>
//     <0=> ADC1_SE7b<selection=ADC1_SE7b_PIN_SEL,PTC11>
//     <1=> GPIOC_11/LLWU_P11<selection=GPIOC_11_PIN_SEL,PTC11><selection=LLWU_P11_PIN_SEL,PTC11>
//     <2=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTC11>
//     <3=> FTM3_CH7<selection=FTM3_CH7_PIN_SEL,PTC11>
//     <4=> I2S0_RXD1<selection=I2S0_RXD1_PIN_SEL,PTC11>
//     <5=> FB_RW_b<selection=FB_RW_b_PIN_SEL,PTC11>
//     <0=> Default
#define PTC11_SIG_SEL        0

// </h>

// <h> Port D Pins

// Signal mapping for PTD0 pin
//   <o> PTD0 [GPIOD_0/LLWU_P12, SPI0_PCS0, UART2_RTS_b, FTM3_CH0, FB_ALE/FB_CS1_b/FB_TS_b]<name=PTD0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD0 pin
//     <-2=> GPIOD_0/LLWU_P12 (reset default)<selection=GPIOD_0_PIN_SEL,PTD0 (reset default)><selection=LLWU_P12_PIN_SEL,PTD0 (reset default)>
//     <1=> GPIOD_0/LLWU_P12<selection=GPIOD_0_PIN_SEL,PTD0><selection=LLWU_P12_PIN_SEL,PTD0>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTD0>
//     <3=> UART2_RTS_b<selection=UART2_RTS_b_PIN_SEL,PTD0>
//     <4=> FTM3_CH0<selection=FTM3_CH0_PIN_SEL,PTD0>
//     <5=> FB_ALE/FB_CS1_b/FB_TS_b<selection=FB_ALE_PIN_SEL,PTD0><selection=FB_CS1_b_PIN_SEL,PTD0><selection=FB_TS_b_PIN_SEL,PTD0>
//     <-2=> Default
#define PTD0_SIG_SEL         -2

// Signal mapping for PTD1 pin
//   <o> PTD1 [ADC0_SE5b, GPIOD_1, SPI0_SCK, UART2_CTS_b, FTM3_CH1, FB_CS0_b]<name=PTD1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD1 pin
//     <-2=> GPIOD_1 (reset default)<selection=GPIOD_1_PIN_SEL,PTD1 (reset default)>
//     <0=> ADC0_SE5b<selection=ADC0_SE5b_PIN_SEL,PTD1>
//     <1=> GPIOD_1<selection=GPIOD_1_PIN_SEL,PTD1>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTD1>
//     <3=> UART2_CTS_b<selection=UART2_CTS_b_PIN_SEL,PTD1>
//     <4=> FTM3_CH1<selection=FTM3_CH1_PIN_SEL,PTD1>
//     <5=> FB_CS0_b<selection=FB_CS0_b_PIN_SEL,PTD1>
//     <0=> Default
#define PTD1_SIG_SEL         0

// Signal mapping for PTD2 pin
//   <o> PTD2 [GPIOD_2/LLWU_P13, SPI0_SOUT, UART2_RX, FTM3_CH2, FB_AD4, I2C0_SCL]<name=PTD2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD2 pin
//     <-2=> GPIOD_2/LLWU_P13 (reset default)<selection=GPIOD_2_PIN_SEL,PTD2 (reset default)><selection=LLWU_P13_PIN_SEL,PTD2 (reset default)>
//     <1=> GPIOD_2/LLWU_P13<selection=GPIOD_2_PIN_SEL,PTD2><selection=LLWU_P13_PIN_SEL,PTD2>
//     <2=> SPI0_SOUT<selection=SPI0_SOUT_PIN_SEL,PTD2>
//     <3=> UART2_RX<selection=UART2_RX_PIN_SEL,PTD2>
//     <4=> FTM3_CH2<selection=FTM3_CH2_PIN_SEL,PTD2>
//     <5=> FB_AD4<selection=FB_AD4_PIN_SEL,PTD2>
//     <7=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTD2>
//     <-2=> Default
#define PTD2_SIG_SEL         -2

// Signal mapping for PTD3 pin
//   <o> PTD3 [GPIOD_3, SPI0_SIN, UART2_TX, FTM3_CH3, FB_AD3, I2C0_SDA]<name=PTD3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD3 pin
//     <-2=> GPIOD_3 (reset default)<selection=GPIOD_3_PIN_SEL,PTD3 (reset default)>
//     <1=> GPIOD_3<selection=GPIOD_3_PIN_SEL,PTD3>
//     <2=> SPI0_SIN<selection=SPI0_SIN_PIN_SEL,PTD3>
//     <3=> UART2_TX<selection=UART2_TX_PIN_SEL,PTD3>
//     <4=> FTM3_CH3<selection=FTM3_CH3_PIN_SEL,PTD3>
//     <5=> FB_AD3<selection=FB_AD3_PIN_SEL,PTD3>
//     <7=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTD3>
//     <-2=> Default
#define PTD3_SIG_SEL         -2

// Signal mapping for PTD4 pin
//   <o> PTD4 [GPIOD_4/LLWU_P14, SPI0_PCS1, UART0_RTS_b, FTM0_CH4, FB_AD2, EWM_IN]<name=PTD4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD4 pin
//     <-2=> GPIOD_4/LLWU_P14 (reset default)<selection=GPIOD_4_PIN_SEL,PTD4 (reset default)><selection=LLWU_P14_PIN_SEL,PTD4 (reset default)>
//     <1=> GPIOD_4/LLWU_P14<selection=GPIOD_4_PIN_SEL,PTD4><selection=LLWU_P14_PIN_SEL,PTD4>
//     <2=> SPI0_PCS1<selection=SPI0_PCS1_PIN_SEL,PTD4>
//     <3=> UART0_RTS_b<selection=UART0_RTS_b_PIN_SEL,PTD4>
//     <4=> FTM0_CH4<selection=FTM0_CH4_PIN_SEL,PTD4>
//     <5=> FB_AD2<selection=FB_AD2_PIN_SEL,PTD4>
//     <6=> EWM_IN<selection=EWM_IN_PIN_SEL,PTD4>
//     <-2=> Default
#define PTD4_SIG_SEL         -2

// Signal mapping for PTD5 pin
//   <o> PTD5 [ADC0_SE6b, GPIOD_5, SPI0_PCS2, UART0_CTS_b, FTM0_CH5, FB_AD1, EWM_OUT_b]<name=PTD5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD5 pin
//     <-2=> GPIOD_5 (reset default)<selection=GPIOD_5_PIN_SEL,PTD5 (reset default)>
//     <0=> ADC0_SE6b<selection=ADC0_SE6b_PIN_SEL,PTD5>
//     <1=> GPIOD_5<selection=GPIOD_5_PIN_SEL,PTD5>
//     <2=> SPI0_PCS2<selection=SPI0_PCS2_PIN_SEL,PTD5>
//     <3=> UART0_CTS_b<selection=UART0_CTS_b_PIN_SEL,PTD5>
//     <4=> FTM0_CH5<selection=FTM0_CH5_PIN_SEL,PTD5>
//     <5=> FB_AD1<selection=FB_AD1_PIN_SEL,PTD5>
//     <6=> EWM_OUT_b<selection=EWM_OUT_b_PIN_SEL,PTD5>
//     <0=> Default
#define PTD5_SIG_SEL         0

// Signal mapping for PTD6 pin
//   <o> PTD6 [ADC0_SE7b, GPIOD_6/LLWU_P15, SPI0_PCS3, UART0_RX, FTM0_CH6, FB_AD0, FTM0_FLT0]<name=PTD6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD6 pin
//     <-2=> GPIOD_6/LLWU_P15 (reset default)<selection=GPIOD_6_PIN_SEL,PTD6 (reset default)><selection=LLWU_P15_PIN_SEL,PTD6 (reset default)>
//     <0=> ADC0_SE7b<selection=ADC0_SE7b_PIN_SEL,PTD6>
//     <1=> GPIOD_6/LLWU_P15<selection=GPIOD_6_PIN_SEL,PTD6><selection=LLWU_P15_PIN_SEL,PTD6>
//     <2=> SPI0_PCS3<selection=SPI0_PCS3_PIN_SEL,PTD6>
//     <3=> UART0_RX<selection=UART0_RX_PIN_SEL,PTD6>
//     <4=> FTM0_CH6<selection=FTM0_CH6_PIN_SEL,PTD6>
//     <5=> FB_AD0<selection=FB_AD0_PIN_SEL,PTD6>
//     <6=> FTM0_FLT0<selection=FTM0_FLT0_PIN_SEL,PTD6>
//     <0=> Default
#define PTD6_SIG_SEL         0

// Signal mapping for PTD7 pin
//   <o> PTD7 [GPIOD_7, CMT_IRO, UART0_TX, FTM0_CH7, FTM0_FLT1]<name=PTD7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD7 pin
//     <-2=> GPIOD_7 (reset default)<selection=GPIOD_7_PIN_SEL,PTD7 (reset default)>
//     <1=> GPIOD_7<selection=GPIOD_7_PIN_SEL,PTD7>
//     <2=> CMT_IRO<selection=CMT_IRO_PIN_SEL,PTD7>
//     <3=> UART0_TX<selection=UART0_TX_PIN_SEL,PTD7>
//     <4=> FTM0_CH7<selection=FTM0_CH7_PIN_SEL,PTD7>
//     <6=> FTM0_FLT1<selection=FTM0_FLT1_PIN_SEL,PTD7>
//     <-2=> Default
#define PTD7_SIG_SEL         -2

// </h>

// <h> Port E Pins

// Signal mapping for PTE0 pin
//   <o> PTE0 [ADC1_SE4a, GPIOE_0, UART1_TX, TRACE_CLKOUT, I2C1_SDA, RTC_CLKOUT]<name=PTE0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE0 pin
//     <-2=> GPIOE_0 (reset default)<selection=GPIOE_0_PIN_SEL,PTE0 (reset default)>
//     <0=> ADC1_SE4a<selection=ADC1_SE4a_PIN_SEL,PTE0>
//     <1=> GPIOE_0<selection=GPIOE_0_PIN_SEL,PTE0>
//     <3=> UART1_TX<selection=UART1_TX_PIN_SEL,PTE0>
//     <5=> TRACE_CLKOUT<selection=TRACE_CLKOUT_PIN_SEL,PTE0>
//     <6=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTE0>
//     <7=> RTC_CLKOUT<selection=RTC_CLKOUT_PIN_SEL,PTE0>
//     <0=> Default
#define PTE0_SIG_SEL         0

// Signal mapping for PTE1 pin
//   <o> PTE1 [ADC1_SE5a, GPIOE_1/LLWU_P0, UART1_RX, TRACE_D3, I2C1_SCL]<name=PTE1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE1 pin
//     <-2=> GPIOE_1/LLWU_P0 (reset default)<selection=GPIOE_1_PIN_SEL,PTE1 (reset default)><selection=LLWU_P0_PIN_SEL,PTE1 (reset default)>
//     <0=> ADC1_SE5a<selection=ADC1_SE5a_PIN_SEL,PTE1>
//     <1=> GPIOE_1/LLWU_P0<selection=GPIOE_1_PIN_SEL,PTE1><selection=LLWU_P0_PIN_SEL,PTE1>
//     <3=> UART1_RX<selection=UART1_RX_PIN_SEL,PTE1>
//     <5=> TRACE_D3<selection=TRACE_D3_PIN_SEL,PTE1>
//     <6=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTE1>
//     <0=> Default
#define PTE1_SIG_SEL         0

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
//   <o> ADC0_DM0 [ADC0_DM0]<name=ADC0_DM0_PIN_SEL><constant>
//   <i> Shows which pin ADC0_DM0 is mapped to
//     <0=> ADC0_DM0<selection=ADC0_DM0_SIG_SEL,ADC0_DM0/ADC1_DM3>
//     <0=> Default
#define ADC0_DM0_PIN_SEL     0
#define ADC0_DM0_GPIO        0
#define ADC0_DM0_FN          0

// Pin Mapping for ADC0_DM3 signal
//   <o> ADC0_DM3 [ADC1_DM0]<name=ADC0_DM3_PIN_SEL><constant>
//   <i> Shows which pin ADC0_DM3 is mapped to
//     <0=> ADC1_DM0<selection=ADC1_DM0_SIG_SEL,ADC1_DM0/ADC0_DM3>
//     <0=> Default
#define ADC0_DM3_PIN_SEL     0
#define ADC0_DM3_GPIO        0
#define ADC0_DM3_FN          0

// Pin Mapping for ADC0_DP0 signal
//   <o> ADC0_DP0 [ADC0_DP0]<name=ADC0_DP0_PIN_SEL><constant>
//   <i> Shows which pin ADC0_DP0 is mapped to
//     <0=> ADC0_DP0<selection=ADC0_DP0_SIG_SEL,ADC0_DP0/ADC1_DP3>
//     <0=> Default
#define ADC0_DP0_PIN_SEL     0
#define ADC0_DP0_GPIO        0
#define ADC0_DP0_FN          0

// Pin Mapping for ADC0_DP3 signal
//   <o> ADC0_DP3 [ADC1_DP0]<name=ADC0_DP3_PIN_SEL><constant>
//   <i> Shows which pin ADC0_DP3 is mapped to
//     <0=> ADC1_DP0<selection=ADC1_DP0_SIG_SEL,ADC1_DP0/ADC0_DP3>
//     <0=> Default
#define ADC0_DP3_PIN_SEL     0
#define ADC0_DP3_GPIO        0
#define ADC0_DP3_FN          0

// Pin Mapping for ADC0_SE4b signal
//   <o> ADC0_SE4b [PTC2]<name=ADC0_SE4b_PIN_SEL>
//   <i> Shows which pin ADC0_SE4b is mapped to
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,ADC0_SE4b/CMP1_IN0>
//     <1=> Default
#define ADC0_SE4b_PIN_SEL    1

// Pin Mapping for ADC0_SE5b signal
//   <o> ADC0_SE5b [PTD1]<name=ADC0_SE5b_PIN_SEL>
//   <i> Shows which pin ADC0_SE5b is mapped to
//     <0=> Disabled
//     <1=> PTD1<selection=PTD1_SIG_SEL,ADC0_SE5b>
//     <1=> Default
#define ADC0_SE5b_PIN_SEL    1

// Pin Mapping for ADC0_SE6b signal
//   <o> ADC0_SE6b [PTD5]<name=ADC0_SE6b_PIN_SEL>
//   <i> Shows which pin ADC0_SE6b is mapped to
//     <0=> Disabled
//     <1=> PTD5<selection=PTD5_SIG_SEL,ADC0_SE6b>
//     <1=> Default
#define ADC0_SE6b_PIN_SEL    1

// Pin Mapping for ADC0_SE7b signal
//   <o> ADC0_SE7b [PTD6]<name=ADC0_SE7b_PIN_SEL>
//   <i> Shows which pin ADC0_SE7b is mapped to
//     <0=> Disabled
//     <1=> PTD6<selection=PTD6_SIG_SEL,ADC0_SE7b>
//     <1=> Default
#define ADC0_SE7b_PIN_SEL    1

// Pin Mapping for ADC0_SE8 signal
//   <o> ADC0_SE8 [PTB0]<name=ADC0_SE8_PIN_SEL>
//   <i> Shows which pin ADC0_SE8 is mapped to
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,ADC0_SE8/ADC1_SE8>
//     <1=> Default
#define ADC0_SE8_PIN_SEL     1

// Pin Mapping for ADC0_SE9 signal
//   <o> ADC0_SE9 [PTB1]<name=ADC0_SE9_PIN_SEL>
//   <i> Shows which pin ADC0_SE9 is mapped to
//     <0=> Disabled
//     <1=> PTB1<selection=PTB1_SIG_SEL,ADC0_SE9/ADC1_SE9>
//     <1=> Default
#define ADC0_SE9_PIN_SEL     1

// Pin Mapping for ADC0_SE12 signal
//   <o> ADC0_SE12 [PTB2]<name=ADC0_SE12_PIN_SEL>
//   <i> Shows which pin ADC0_SE12 is mapped to
//     <0=> Disabled
//     <1=> PTB2<selection=PTB2_SIG_SEL,ADC0_SE12>
//     <1=> Default
#define ADC0_SE12_PIN_SEL    1

// Pin Mapping for ADC0_SE13 signal
//   <o> ADC0_SE13 [PTB3]<name=ADC0_SE13_PIN_SEL>
//   <i> Shows which pin ADC0_SE13 is mapped to
//     <0=> Disabled
//     <1=> PTB3<selection=PTB3_SIG_SEL,ADC0_SE13>
//     <1=> Default
#define ADC0_SE13_PIN_SEL    1

// Pin Mapping for ADC0_SE14 signal
//   <o> ADC0_SE14 [PTC0]<name=ADC0_SE14_PIN_SEL>
//   <i> Shows which pin ADC0_SE14 is mapped to
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,ADC0_SE14>
//     <1=> Default
#define ADC0_SE14_PIN_SEL    1

// Pin Mapping for ADC0_SE15 signal
//   <o> ADC0_SE15 [PTC1]<name=ADC0_SE15_PIN_SEL>
//   <i> Shows which pin ADC0_SE15 is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,ADC0_SE15>
//     <1=> Default
#define ADC0_SE15_PIN_SEL    1

// Pin Mapping for ADC0_SE23 signal
//   <o> ADC0_SE23 [ADC0_SE23]<name=ADC0_SE23_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE23 is mapped to
//     <0=> ADC0_SE23<selection=ADC0_SE23_SIG_SEL,DAC0_OUT/CMP1_IN3/ADC0_SE23>
//     <0=> Default
#define ADC0_SE23_PIN_SEL    0

// </h>

// <h> Analogue to Digital (ADC1)

// Pin Mapping for ADC1_DM0 signal
//   <o> ADC1_DM0 [ADC1_DM0]<name=ADC1_DM0_PIN_SEL><constant>
//   <i> Shows which pin ADC1_DM0 is mapped to
//     <0=> ADC1_DM0<selection=ADC1_DM0_SIG_SEL,ADC1_DM0/ADC0_DM3>
//     <0=> Default
#define ADC1_DM0_PIN_SEL     0
#define ADC1_DM0_GPIO        0
#define ADC1_DM0_FN          0

// Pin Mapping for ADC1_DM3 signal
//   <o> ADC1_DM3 [ADC0_DM0]<name=ADC1_DM3_PIN_SEL><constant>
//   <i> Shows which pin ADC1_DM3 is mapped to
//     <0=> ADC0_DM0<selection=ADC0_DM0_SIG_SEL,ADC0_DM0/ADC1_DM3>
//     <0=> Default
#define ADC1_DM3_PIN_SEL     0
#define ADC1_DM3_GPIO        0
#define ADC1_DM3_FN          0

// Pin Mapping for ADC1_DP0 signal
//   <o> ADC1_DP0 [ADC1_DP0]<name=ADC1_DP0_PIN_SEL><constant>
//   <i> Shows which pin ADC1_DP0 is mapped to
//     <0=> ADC1_DP0<selection=ADC1_DP0_SIG_SEL,ADC1_DP0/ADC0_DP3>
//     <0=> Default
#define ADC1_DP0_PIN_SEL     0
#define ADC1_DP0_GPIO        0
#define ADC1_DP0_FN          0

// Pin Mapping for ADC1_DP3 signal
//   <o> ADC1_DP3 [ADC0_DP0]<name=ADC1_DP3_PIN_SEL><constant>
//   <i> Shows which pin ADC1_DP3 is mapped to
//     <0=> ADC0_DP0<selection=ADC0_DP0_SIG_SEL,ADC0_DP0/ADC1_DP3>
//     <0=> Default
#define ADC1_DP3_PIN_SEL     0
#define ADC1_DP3_GPIO        0
#define ADC1_DP3_FN          0

// Pin Mapping for ADC1_SE4a signal
//   <o> ADC1_SE4a [PTE0]<name=ADC1_SE4a_PIN_SEL>
//   <i> Shows which pin ADC1_SE4a is mapped to
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,ADC1_SE4a>
//     <1=> Default
#define ADC1_SE4a_PIN_SEL    1

// Pin Mapping for ADC1_SE4b signal
//   <o> ADC1_SE4b [PTC8]<name=ADC1_SE4b_PIN_SEL>
//   <i> Shows which pin ADC1_SE4b is mapped to
//     <0=> Disabled
//     <1=> PTC8<selection=PTC8_SIG_SEL,ADC1_SE4b/CMP0_IN2>
//     <1=> Default
#define ADC1_SE4b_PIN_SEL    1

// Pin Mapping for ADC1_SE5a signal
//   <o> ADC1_SE5a [PTE1]<name=ADC1_SE5a_PIN_SEL>
//   <i> Shows which pin ADC1_SE5a is mapped to
//     <0=> Disabled
//     <1=> PTE1<selection=PTE1_SIG_SEL,ADC1_SE5a>
//     <1=> Default
#define ADC1_SE5a_PIN_SEL    1

// Pin Mapping for ADC1_SE5b signal
//   <o> ADC1_SE5b [PTC9]<name=ADC1_SE5b_PIN_SEL>
//   <i> Shows which pin ADC1_SE5b is mapped to
//     <0=> Disabled
//     <1=> PTC9<selection=PTC9_SIG_SEL,ADC1_SE5b/CMP0_IN3>
//     <1=> Default
#define ADC1_SE5b_PIN_SEL    1

// Pin Mapping for ADC1_SE6b signal
//   <o> ADC1_SE6b [PTC10]<name=ADC1_SE6b_PIN_SEL>
//   <i> Shows which pin ADC1_SE6b is mapped to
//     <0=> Disabled
//     <1=> PTC10<selection=PTC10_SIG_SEL,ADC1_SE6b>
//     <1=> Default
#define ADC1_SE6b_PIN_SEL    1

// Pin Mapping for ADC1_SE7b signal
//   <o> ADC1_SE7b [PTC11]<name=ADC1_SE7b_PIN_SEL>
//   <i> Shows which pin ADC1_SE7b is mapped to
//     <0=> Disabled
//     <1=> PTC11<selection=PTC11_SIG_SEL,ADC1_SE7b>
//     <1=> Default
#define ADC1_SE7b_PIN_SEL    1

// Pin Mapping for ADC1_SE8 signal
//   <o> ADC1_SE8 [PTB0]<name=ADC1_SE8_PIN_SEL>
//   <i> Shows which pin ADC1_SE8 is mapped to
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,ADC0_SE8/ADC1_SE8>
//     <1=> Default
#define ADC1_SE8_PIN_SEL     1

// Pin Mapping for ADC1_SE9 signal
//   <o> ADC1_SE9 [PTB1]<name=ADC1_SE9_PIN_SEL>
//   <i> Shows which pin ADC1_SE9 is mapped to
//     <0=> Disabled
//     <1=> PTB1<selection=PTB1_SIG_SEL,ADC0_SE9/ADC1_SE9>
//     <1=> Default
#define ADC1_SE9_PIN_SEL     1

// Pin Mapping for ADC1_SE18 signal
//   <o> ADC1_SE18 [ADC1_SE18]<name=ADC1_SE18_PIN_SEL><constant>
//   <i> Shows which pin ADC1_SE18 is mapped to
//     <0=> ADC1_SE18<selection=ADC1_SE18_SIG_SEL,VREF_OUT/CMP1_IN5/CMP0_IN5/ADC1_SE18>
//     <0=> Default
#define ADC1_SE18_PIN_SEL    0

// </h>

// <h> CAN Bus (CAN0)

// Pin Mapping for CAN0_RX signal
//   <o> CAN0_RX [PTA13, PTB19]<name=CAN0_RX_PIN_SEL>
//   <i> Shows which pin CAN0_RX is mapped to
//     <0=> Disabled
//     <1=> PTA13<selection=PTA13_SIG_SEL,CAN0_RX>
//     <2=> PTB19<selection=PTB19_SIG_SEL,CAN0_RX>
//     <0=> Default
#define CAN0_RX_PIN_SEL      0
#if (CAN0_RX_PIN_SEL == 1)
#define CAN0_RX_GPIO         USBDM::GpioA<13>
#define CAN0_RX_FN           2
#elif (CAN0_RX_PIN_SEL == 2)
#define CAN0_RX_GPIO         USBDM::GpioB<19>
#define CAN0_RX_FN           2
#endif

// Pin Mapping for CAN0_TX signal
//   <o> CAN0_TX [PTA12, PTB18]<name=CAN0_TX_PIN_SEL>
//   <i> Shows which pin CAN0_TX is mapped to
//     <0=> Disabled
//     <1=> PTA12<selection=PTA12_SIG_SEL,CAN0_TX>
//     <2=> PTB18<selection=PTB18_SIG_SEL,CAN0_TX>
//     <0=> Default
#define CAN0_TX_PIN_SEL      0
#if (CAN0_TX_PIN_SEL == 1)
#define CAN0_TX_GPIO         USBDM::GpioA<12>
#define CAN0_TX_FN           2
#elif (CAN0_TX_PIN_SEL == 2)
#define CAN0_TX_GPIO         USBDM::GpioB<18>
#define CAN0_TX_FN           2
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
#if (CLKOUT_PIN_SEL == 1)
#define CLKOUT_GPIO          USBDM::GpioC<3>
#define CLKOUT_FN            5
#endif

// Pin Mapping for EXTAL0 signal
//   <o> EXTAL0 [PTA18]<name=EXTAL0_PIN_SEL>
//   <i> Shows which pin EXTAL0 is mapped to
//     <0=> Disabled
//     <1=> PTA18<selection=PTA18_SIG_SEL,EXTAL0>
//     <1=> Default
#define EXTAL0_PIN_SEL       1
#if (EXTAL0_PIN_SEL == 1)
#define EXTAL0_GPIO          USBDM::GpioA<18>
#define EXTAL0_FN            0
#endif

// Pin Mapping for EXTAL32 signal
//   <o> EXTAL32 [EXTAL32]<name=EXTAL32_PIN_SEL><constant>
//   <i> Shows which pin EXTAL32 is mapped to
//     <0=> EXTAL32<selection=EXTAL32_SIG_SEL,EXTAL32>
//     <0=> Default
#define EXTAL32_PIN_SEL      0
#define EXTAL32_GPIO         0
#define EXTAL32_FN           0

// Pin Mapping for FTM_CLKIN0 signal
//   <o> FTM_CLKIN0 [PTA18, PTB16]<name=FTM_CLKIN0_PIN_SEL>
//   <i> Shows which pin FTM_CLKIN0 is mapped to
//     <0=> Disabled
//     <1=> PTA18<selection=PTA18_SIG_SEL,FTM_CLKIN0>
//     <2=> PTB16<selection=PTB16_SIG_SEL,FTM_CLKIN0>
//     <0=> Default
#define FTM_CLKIN0_PIN_SEL   0
#if (FTM_CLKIN0_PIN_SEL == 1)
#define FTM_CLKIN0_GPIO      USBDM::GpioA<18>
#define FTM_CLKIN0_FN        4
#elif (FTM_CLKIN0_PIN_SEL == 2)
#define FTM_CLKIN0_GPIO      USBDM::GpioB<16>
#define FTM_CLKIN0_FN        4
#endif

// Pin Mapping for FTM_CLKIN1 signal
//   <o> FTM_CLKIN1 [PTA19, PTB17]<name=FTM_CLKIN1_PIN_SEL>
//   <i> Shows which pin FTM_CLKIN1 is mapped to
//     <0=> Disabled
//     <1=> PTA19<selection=PTA19_SIG_SEL,FTM_CLKIN1>
//     <2=> PTB17<selection=PTB17_SIG_SEL,FTM_CLKIN1>
//     <0=> Default
#define FTM_CLKIN1_PIN_SEL   0
#if (FTM_CLKIN1_PIN_SEL == 1)
#define FTM_CLKIN1_GPIO      USBDM::GpioA<19>
#define FTM_CLKIN1_FN        4
#elif (FTM_CLKIN1_PIN_SEL == 2)
#define FTM_CLKIN1_GPIO      USBDM::GpioB<17>
#define FTM_CLKIN1_FN        4
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
#define RTC_CLKOUT_FN        7
#endif

// Pin Mapping for XTAL0 signal
//   <o> XTAL0 [PTA19]<name=XTAL0_PIN_SEL>
//   <i> Shows which pin XTAL0 is mapped to
//     <0=> Disabled
//     <1=> PTA19<selection=PTA19_SIG_SEL,XTAL0>
//     <1=> Default
#define XTAL0_PIN_SEL        1
#if (XTAL0_PIN_SEL == 1)
#define XTAL0_GPIO           USBDM::GpioA<19>
#define XTAL0_FN             0
#endif

// Pin Mapping for XTAL32 signal
//   <o> XTAL32 [XTAL32]<name=XTAL32_PIN_SEL><constant>
//   <i> Shows which pin XTAL32 is mapped to
//     <0=> XTAL32<selection=XTAL32_SIG_SEL,XTAL32>
//     <0=> Default
#define XTAL32_PIN_SEL       0
#define XTAL32_GPIO          0
#define XTAL32_FN            0

// </h>

// <h> Analogue Comparator (CMP0)

// Pin Mapping for CMP0_IN0 signal
//   <o> CMP0_IN0 [PTC6]<name=CMP0_IN0_PIN_SEL>
//   <i> Shows which pin CMP0_IN0 is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,CMP0_IN0>
//     <1=> Default
#define CMP0_IN0_PIN_SEL     1
#if (CMP0_IN0_PIN_SEL == 1)
#define CMP0_IN0_GPIO        USBDM::GpioC<6>
#define CMP0_IN0_FN          0
#endif

// Pin Mapping for CMP0_IN1 signal
//   <o> CMP0_IN1 [PTC7]<name=CMP0_IN1_PIN_SEL>
//   <i> Shows which pin CMP0_IN1 is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,CMP0_IN1>
//     <1=> Default
#define CMP0_IN1_PIN_SEL     1
#if (CMP0_IN1_PIN_SEL == 1)
#define CMP0_IN1_GPIO        USBDM::GpioC<7>
#define CMP0_IN1_FN          0
#endif

// Pin Mapping for CMP0_IN2 signal
//   <o> CMP0_IN2 [PTC8]<name=CMP0_IN2_PIN_SEL>
//   <i> Shows which pin CMP0_IN2 is mapped to
//     <0=> Disabled
//     <1=> PTC8<selection=PTC8_SIG_SEL,ADC1_SE4b/CMP0_IN2>
//     <1=> Default
#define CMP0_IN2_PIN_SEL     1
#if (CMP0_IN2_PIN_SEL == 1)
#define CMP0_IN2_GPIO        USBDM::GpioC<8>
#define CMP0_IN2_FN          0
#endif

// Pin Mapping for CMP0_IN3 signal
//   <o> CMP0_IN3 [PTC9]<name=CMP0_IN3_PIN_SEL>
//   <i> Shows which pin CMP0_IN3 is mapped to
//     <0=> Disabled
//     <1=> PTC9<selection=PTC9_SIG_SEL,ADC1_SE5b/CMP0_IN3>
//     <1=> Default
#define CMP0_IN3_PIN_SEL     1
#if (CMP0_IN3_PIN_SEL == 1)
#define CMP0_IN3_GPIO        USBDM::GpioC<9>
#define CMP0_IN3_FN          0
#endif

// Pin Mapping for CMP0_IN5 signal
//   <o> CMP0_IN5 [ADC1_SE18]<name=CMP0_IN5_PIN_SEL><constant>
//   <i> Shows which pin CMP0_IN5 is mapped to
//     <0=> ADC1_SE18<selection=ADC1_SE18_SIG_SEL,VREF_OUT/CMP1_IN5/CMP0_IN5/ADC1_SE18>
//     <0=> Default
#define CMP0_IN5_PIN_SEL     0
#define CMP0_IN5_GPIO        0
#define CMP0_IN5_FN          0

// Pin Mapping for CMP0_OUT signal
//   <o> CMP0_OUT [PTC5]<name=CMP0_OUT_PIN_SEL>
//   <i> Shows which pin CMP0_OUT is mapped to
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,CMP0_OUT>
//     <0=> Default
#define CMP0_OUT_PIN_SEL     0
#if (CMP0_OUT_PIN_SEL == 1)
#define CMP0_OUT_GPIO        USBDM::GpioC<5>
#define CMP0_OUT_FN          6
#endif

// </h>

// <h> Analogue Comparator (CMP1)

// Pin Mapping for CMP1_IN0 signal
//   <o> CMP1_IN0 [PTC2]<name=CMP1_IN0_PIN_SEL>
//   <i> Shows which pin CMP1_IN0 is mapped to
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,ADC0_SE4b/CMP1_IN0>
//     <1=> Default
#define CMP1_IN0_PIN_SEL     1
#if (CMP1_IN0_PIN_SEL == 1)
#define CMP1_IN0_GPIO        USBDM::GpioC<2>
#define CMP1_IN0_FN          0
#endif

// Pin Mapping for CMP1_IN1 signal
//   <o> CMP1_IN1 [PTC3]<name=CMP1_IN1_PIN_SEL>
//   <i> Shows which pin CMP1_IN1 is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,CMP1_IN1>
//     <1=> Default
#define CMP1_IN1_PIN_SEL     1
#if (CMP1_IN1_PIN_SEL == 1)
#define CMP1_IN1_GPIO        USBDM::GpioC<3>
#define CMP1_IN1_FN          0
#endif

// Pin Mapping for CMP1_IN3 signal
//   <o> CMP1_IN3 [ADC0_SE23]<name=CMP1_IN3_PIN_SEL><constant>
//   <i> Shows which pin CMP1_IN3 is mapped to
//     <0=> ADC0_SE23<selection=ADC0_SE23_SIG_SEL,DAC0_OUT/CMP1_IN3/ADC0_SE23>
//     <0=> Default
#define CMP1_IN3_PIN_SEL     0
#define CMP1_IN3_GPIO        0
#define CMP1_IN3_FN          0

// Pin Mapping for CMP1_IN5 signal
//   <o> CMP1_IN5 [ADC1_SE18]<name=CMP1_IN5_PIN_SEL><constant>
//   <i> Shows which pin CMP1_IN5 is mapped to
//     <0=> ADC1_SE18<selection=ADC1_SE18_SIG_SEL,VREF_OUT/CMP1_IN5/CMP0_IN5/ADC1_SE18>
//     <0=> Default
#define CMP1_IN5_PIN_SEL     0
#define CMP1_IN5_GPIO        0
#define CMP1_IN5_FN          0

// Pin Mapping for CMP1_OUT signal
//   <o> CMP1_OUT [PTC4]<name=CMP1_OUT_PIN_SEL>
//   <i> Shows which pin CMP1_OUT is mapped to
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,CMP1_OUT>
//     <0=> Default
#define CMP1_OUT_PIN_SEL     0
#if (CMP1_OUT_PIN_SEL == 1)
#define CMP1_OUT_GPIO        USBDM::GpioC<4>
#define CMP1_OUT_FN          6
#endif

// </h>

// <h> Analogue Comparator (CMP2)

// Pin Mapping for CMP2_IN0 signal
//   <o> CMP2_IN0 [PTA12]<name=CMP2_IN0_PIN_SEL>
//   <i> Shows which pin CMP2_IN0 is mapped to
//     <0=> Disabled
//     <1=> PTA12<selection=PTA12_SIG_SEL,CMP2_IN0>
//     <1=> Default
#define CMP2_IN0_PIN_SEL     1
#if (CMP2_IN0_PIN_SEL == 1)
#define CMP2_IN0_GPIO        USBDM::GpioA<12>
#define CMP2_IN0_FN          0
#endif

// Pin Mapping for CMP2_IN1 signal
//   <o> CMP2_IN1 [PTA13]<name=CMP2_IN1_PIN_SEL>
//   <i> Shows which pin CMP2_IN1 is mapped to
//     <0=> Disabled
//     <1=> PTA13<selection=PTA13_SIG_SEL,CMP2_IN1>
//     <1=> Default
#define CMP2_IN1_PIN_SEL     1
#if (CMP2_IN1_PIN_SEL == 1)
#define CMP2_IN1_GPIO        USBDM::GpioA<13>
#define CMP2_IN1_FN          0
#endif

// Pin Mapping for CMP2_OUT signal
//   <o> CMP2_OUT [PTA5]<name=CMP2_OUT_PIN_SEL>
//   <i> Shows which pin CMP2_OUT is mapped to
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,CMP2_OUT>
//     <0=> Default
#define CMP2_OUT_PIN_SEL     0
#if (CMP2_OUT_PIN_SEL == 1)
#define CMP2_OUT_GPIO        USBDM::GpioA<5>
#define CMP2_OUT_FN          5
#endif

// </h>

// <h> Carrier Modulator Transmitter (CMT)

// Pin Mapping for CMT_IRO signal
//   <o> CMT_IRO [PTD7]<name=CMT_IRO_PIN_SEL>
//   <i> Shows which pin CMT_IRO is mapped to
//     <0=> Disabled
//     <1=> PTD7<selection=PTD7_SIG_SEL,CMT_IRO>
//     <0=> Default
#define CMT_IRO_PIN_SEL      0
#if (CMT_IRO_PIN_SEL == 1)
#define CMT_IRO_GPIO         USBDM::GpioD<7>
#define CMT_IRO_FN           2
#endif

// </h>

// <h> Digital to Analogue (DAC0)

// Pin Mapping for DAC0_OUT signal
//   <o> DAC0_OUT [ADC0_SE23]<name=DAC0_OUT_PIN_SEL><constant>
//   <i> Shows which pin DAC0_OUT is mapped to
//     <0=> ADC0_SE23<selection=ADC0_SE23_SIG_SEL,DAC0_OUT/CMP1_IN3/ADC0_SE23>
//     <0=> Default
#define DAC0_OUT_PIN_SEL     0
#define DAC0_OUT_GPIO        0
#define DAC0_OUT_FN          0

// </h>

// <h> External Watchdog Monitor (EWM)

// Pin Mapping for EWM_IN signal
//   <o> EWM_IN [PTB16, PTD4]<name=EWM_IN_PIN_SEL>
//   <i> Shows which pin EWM_IN is mapped to
//     <0=> Disabled
//     <1=> PTB16<selection=PTB16_SIG_SEL,EWM_IN>
//     <2=> PTD4<selection=PTD4_SIG_SEL,EWM_IN>
//     <0=> Default
#define EWM_IN_PIN_SEL       0
#if (EWM_IN_PIN_SEL == 1)
#define EWM_IN_GPIO          USBDM::GpioB<16>
#define EWM_IN_FN            6
#elif (EWM_IN_PIN_SEL == 2)
#define EWM_IN_GPIO          USBDM::GpioD<4>
#define EWM_IN_FN            6
#endif

// Pin Mapping for EWM_OUT_b signal
//   <o> EWM_OUT_b [PTB17, PTD5]<name=EWM_OUT_b_PIN_SEL>
//   <i> Shows which pin EWM_OUT_b is mapped to
//     <0=> Disabled
//     <1=> PTB17<selection=PTB17_SIG_SEL,EWM_OUT_b>
//     <2=> PTD5<selection=PTD5_SIG_SEL,EWM_OUT_b>
//     <0=> Default
#define EWM_OUT_b_PIN_SEL    0
#if (EWM_OUT_b_PIN_SEL == 1)
#define EWM_OUT_b_GPIO       USBDM::GpioB<17>
#define EWM_OUT_b_FN         6
#elif (EWM_OUT_b_PIN_SEL == 2)
#define EWM_OUT_b_GPIO       USBDM::GpioD<5>
#define EWM_OUT_b_FN         6
#endif

// </h>

// <h> Flexbus

// Pin Mapping for FB_AD0 signal
//   <o> FB_AD0 [PTD6]<name=FB_AD0_PIN_SEL>
//   <i> Shows which pin FB_AD0 is mapped to
//     <0=> Disabled
//     <1=> PTD6<selection=PTD6_SIG_SEL,FB_AD0>
//     <0=> Default
#define FB_AD0_PIN_SEL       0
#if (FB_AD0_PIN_SEL == 1)
#define FB_AD0_GPIO          USBDM::GpioD<6>
#define FB_AD0_FN            5
#endif

// Pin Mapping for FB_AD1 signal
//   <o> FB_AD1 [PTD5]<name=FB_AD1_PIN_SEL>
//   <i> Shows which pin FB_AD1 is mapped to
//     <0=> Disabled
//     <1=> PTD5<selection=PTD5_SIG_SEL,FB_AD1>
//     <0=> Default
#define FB_AD1_PIN_SEL       0
#if (FB_AD1_PIN_SEL == 1)
#define FB_AD1_GPIO          USBDM::GpioD<5>
#define FB_AD1_FN            5
#endif

// Pin Mapping for FB_AD2 signal
//   <o> FB_AD2 [PTD4]<name=FB_AD2_PIN_SEL>
//   <i> Shows which pin FB_AD2 is mapped to
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,FB_AD2>
//     <0=> Default
#define FB_AD2_PIN_SEL       0
#if (FB_AD2_PIN_SEL == 1)
#define FB_AD2_GPIO          USBDM::GpioD<4>
#define FB_AD2_FN            5
#endif

// Pin Mapping for FB_AD3 signal
//   <o> FB_AD3 [PTD3]<name=FB_AD3_PIN_SEL>
//   <i> Shows which pin FB_AD3 is mapped to
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,FB_AD3>
//     <0=> Default
#define FB_AD3_PIN_SEL       0
#if (FB_AD3_PIN_SEL == 1)
#define FB_AD3_GPIO          USBDM::GpioD<3>
#define FB_AD3_FN            5
#endif

// Pin Mapping for FB_AD4 signal
//   <o> FB_AD4 [PTD2]<name=FB_AD4_PIN_SEL>
//   <i> Shows which pin FB_AD4 is mapped to
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,FB_AD4>
//     <0=> Default
#define FB_AD4_PIN_SEL       0
#if (FB_AD4_PIN_SEL == 1)
#define FB_AD4_GPIO          USBDM::GpioD<2>
#define FB_AD4_FN            5
#endif

// Pin Mapping for FB_AD5 signal
//   <o> FB_AD5 [PTC10]<name=FB_AD5_PIN_SEL>
//   <i> Shows which pin FB_AD5 is mapped to
//     <0=> Disabled
//     <1=> PTC10<selection=PTC10_SIG_SEL,FB_AD5>
//     <0=> Default
#define FB_AD5_PIN_SEL       0
#if (FB_AD5_PIN_SEL == 1)
#define FB_AD5_GPIO          USBDM::GpioC<10>
#define FB_AD5_FN            5
#endif

// Pin Mapping for FB_AD6 signal
//   <o> FB_AD6 [PTC9]<name=FB_AD6_PIN_SEL>
//   <i> Shows which pin FB_AD6 is mapped to
//     <0=> Disabled
//     <1=> PTC9<selection=PTC9_SIG_SEL,FB_AD6>
//     <0=> Default
#define FB_AD6_PIN_SEL       0
#if (FB_AD6_PIN_SEL == 1)
#define FB_AD6_GPIO          USBDM::GpioC<9>
#define FB_AD6_FN            5
#endif

// Pin Mapping for FB_AD7 signal
//   <o> FB_AD7 [PTC8]<name=FB_AD7_PIN_SEL>
//   <i> Shows which pin FB_AD7 is mapped to
//     <0=> Disabled
//     <1=> PTC8<selection=PTC8_SIG_SEL,FB_AD7>
//     <0=> Default
#define FB_AD7_PIN_SEL       0
#if (FB_AD7_PIN_SEL == 1)
#define FB_AD7_GPIO          USBDM::GpioC<8>
#define FB_AD7_FN            5
#endif

// Pin Mapping for FB_AD8 signal
//   <o> FB_AD8 [PTC7]<name=FB_AD8_PIN_SEL>
//   <i> Shows which pin FB_AD8 is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,FB_AD8>
//     <0=> Default
#define FB_AD8_PIN_SEL       0
#if (FB_AD8_PIN_SEL == 1)
#define FB_AD8_GPIO          USBDM::GpioC<7>
#define FB_AD8_FN            5
#endif

// Pin Mapping for FB_AD9 signal
//   <o> FB_AD9 [PTC6]<name=FB_AD9_PIN_SEL>
//   <i> Shows which pin FB_AD9 is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,FB_AD9>
//     <0=> Default
#define FB_AD9_PIN_SEL       0
#if (FB_AD9_PIN_SEL == 1)
#define FB_AD9_GPIO          USBDM::GpioC<6>
#define FB_AD9_FN            5
#endif

// Pin Mapping for FB_AD10 signal
//   <o> FB_AD10 [PTC5]<name=FB_AD10_PIN_SEL>
//   <i> Shows which pin FB_AD10 is mapped to
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,FB_AD10>
//     <0=> Default
#define FB_AD10_PIN_SEL      0
#if (FB_AD10_PIN_SEL == 1)
#define FB_AD10_GPIO         USBDM::GpioC<5>
#define FB_AD10_FN           5
#endif

// Pin Mapping for FB_AD11 signal
//   <o> FB_AD11 [PTC4]<name=FB_AD11_PIN_SEL>
//   <i> Shows which pin FB_AD11 is mapped to
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,FB_AD11>
//     <0=> Default
#define FB_AD11_PIN_SEL      0
#if (FB_AD11_PIN_SEL == 1)
#define FB_AD11_GPIO         USBDM::GpioC<4>
#define FB_AD11_FN           5
#endif

// Pin Mapping for FB_AD12 signal
//   <o> FB_AD12 [PTC2]<name=FB_AD12_PIN_SEL>
//   <i> Shows which pin FB_AD12 is mapped to
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,FB_AD12>
//     <0=> Default
#define FB_AD12_PIN_SEL      0
#if (FB_AD12_PIN_SEL == 1)
#define FB_AD12_GPIO         USBDM::GpioC<2>
#define FB_AD12_FN           5
#endif

// Pin Mapping for FB_AD13 signal
//   <o> FB_AD13 [PTC1]<name=FB_AD13_PIN_SEL>
//   <i> Shows which pin FB_AD13 is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,FB_AD13>
//     <0=> Default
#define FB_AD13_PIN_SEL      0
#if (FB_AD13_PIN_SEL == 1)
#define FB_AD13_GPIO         USBDM::GpioC<1>
#define FB_AD13_FN           5
#endif

// Pin Mapping for FB_AD14 signal
//   <o> FB_AD14 [PTC0]<name=FB_AD14_PIN_SEL>
//   <i> Shows which pin FB_AD14 is mapped to
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,FB_AD14>
//     <0=> Default
#define FB_AD14_PIN_SEL      0
#if (FB_AD14_PIN_SEL == 1)
#define FB_AD14_GPIO         USBDM::GpioC<0>
#define FB_AD14_FN           5
#endif

// Pin Mapping for FB_AD15 signal
//   <o> FB_AD15 [PTB18]<name=FB_AD15_PIN_SEL>
//   <i> Shows which pin FB_AD15 is mapped to
//     <0=> Disabled
//     <1=> PTB18<selection=PTB18_SIG_SEL,FB_AD15>
//     <0=> Default
#define FB_AD15_PIN_SEL      0
#if (FB_AD15_PIN_SEL == 1)
#define FB_AD15_GPIO         USBDM::GpioB<18>
#define FB_AD15_FN           5
#endif

// Pin Mapping for FB_AD16 signal
//   <o> FB_AD16 [PTB17]<name=FB_AD16_PIN_SEL>
//   <i> Shows which pin FB_AD16 is mapped to
//     <0=> Disabled
//     <1=> PTB17<selection=PTB17_SIG_SEL,FB_AD16>
//     <0=> Default
#define FB_AD16_PIN_SEL      0
#if (FB_AD16_PIN_SEL == 1)
#define FB_AD16_GPIO         USBDM::GpioB<17>
#define FB_AD16_FN           5
#endif

// Pin Mapping for FB_AD17 signal
//   <o> FB_AD17 [PTB16]<name=FB_AD17_PIN_SEL>
//   <i> Shows which pin FB_AD17 is mapped to
//     <0=> Disabled
//     <1=> PTB16<selection=PTB16_SIG_SEL,FB_AD17>
//     <0=> Default
#define FB_AD17_PIN_SEL      0
#if (FB_AD17_PIN_SEL == 1)
#define FB_AD17_GPIO         USBDM::GpioB<16>
#define FB_AD17_FN           5
#endif

// Pin Mapping for FB_ALE signal
//   <o> FB_ALE [PTD0]<name=FB_ALE_PIN_SEL>
//   <i> Shows which pin FB_ALE is mapped to
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,FB_ALE/FB_CS1_b/FB_TS_b>
//     <0=> Default
#define FB_ALE_PIN_SEL       0
#if (FB_ALE_PIN_SEL == 1)
#define FB_ALE_GPIO          USBDM::GpioD<0>
#define FB_ALE_FN            5
#endif

// Pin Mapping for FB_CS0_b signal
//   <o> FB_CS0_b [PTD1]<name=FB_CS0_b_PIN_SEL>
//   <i> Shows which pin FB_CS0_b is mapped to
//     <0=> Disabled
//     <1=> PTD1<selection=PTD1_SIG_SEL,FB_CS0_b>
//     <0=> Default
#define FB_CS0_b_PIN_SEL     0
#if (FB_CS0_b_PIN_SEL == 1)
#define FB_CS0_b_GPIO        USBDM::GpioD<1>
#define FB_CS0_b_FN          5
#endif

// Pin Mapping for FB_CS1_b signal
//   <o> FB_CS1_b [PTD0]<name=FB_CS1_b_PIN_SEL>
//   <i> Shows which pin FB_CS1_b is mapped to
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,FB_ALE/FB_CS1_b/FB_TS_b>
//     <0=> Default
#define FB_CS1_b_PIN_SEL     0
#if (FB_CS1_b_PIN_SEL == 1)
#define FB_CS1_b_GPIO        USBDM::GpioD<0>
#define FB_CS1_b_FN          5
#endif

// Pin Mapping for FB_OE_b signal
//   <o> FB_OE_b [PTB19]<name=FB_OE_b_PIN_SEL>
//   <i> Shows which pin FB_OE_b is mapped to
//     <0=> Disabled
//     <1=> PTB19<selection=PTB19_SIG_SEL,FB_OE_b>
//     <0=> Default
#define FB_OE_b_PIN_SEL      0
#if (FB_OE_b_PIN_SEL == 1)
#define FB_OE_b_GPIO         USBDM::GpioB<19>
#define FB_OE_b_FN           5
#endif

// Pin Mapping for FB_RW_b signal
//   <o> FB_RW_b [PTC11]<name=FB_RW_b_PIN_SEL>
//   <i> Shows which pin FB_RW_b is mapped to
//     <0=> Disabled
//     <1=> PTC11<selection=PTC11_SIG_SEL,FB_RW_b>
//     <0=> Default
#define FB_RW_b_PIN_SEL      0
#if (FB_RW_b_PIN_SEL == 1)
#define FB_RW_b_GPIO         USBDM::GpioC<11>
#define FB_RW_b_FN           5
#endif

// Pin Mapping for FB_TS_b signal
//   <o> FB_TS_b [PTD0]<name=FB_TS_b_PIN_SEL>
//   <i> Shows which pin FB_TS_b is mapped to
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,FB_ALE/FB_CS1_b/FB_TS_b>
//     <0=> Default
#define FB_TS_b_PIN_SEL      0
#if (FB_TS_b_PIN_SEL == 1)
#define FB_TS_b_GPIO         USBDM::GpioD<0>
#define FB_TS_b_FN           5
#endif

// </h>

// <h> FlexTimer (FTM0)

// Pin Mapping for FTM0_CH0 signal
//   <o> FTM0_CH0 [PTA3, PTC1]<name=FTM0_CH0_PIN_SEL>
//   <i> Shows which pin FTM0_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,FTM0_CH0>
//     <2=> PTC1<selection=PTC1_SIG_SEL,FTM0_CH0>
//     <0=> Default
#define FTM0_CH0_PIN_SEL     0

// Pin Mapping for FTM0_CH1 signal
//   <o> FTM0_CH1 [PTA4, PTC2]<name=FTM0_CH1_PIN_SEL>
//   <i> Shows which pin FTM0_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,FTM0_CH1>
//     <2=> PTC2<selection=PTC2_SIG_SEL,FTM0_CH1>
//     <0=> Default
#define FTM0_CH1_PIN_SEL     0

// Pin Mapping for FTM0_CH2 signal
//   <o> FTM0_CH2 [PTA5, PTC3, PTC5]<name=FTM0_CH2_PIN_SEL>
//   <i> Shows which pin FTM0_CH2 is mapped to
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,FTM0_CH2>
//     <2=> PTC3<selection=PTC3_SIG_SEL,FTM0_CH2>
//     <3=> PTC5<selection=PTC5_SIG_SEL,FTM0_CH2>
//     <0=> Default
#define FTM0_CH2_PIN_SEL     0

// Pin Mapping for FTM0_CH3 signal
//   <o> FTM0_CH3 [PTC4]<name=FTM0_CH3_PIN_SEL>
//   <i> Shows which pin FTM0_CH3 is mapped to
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,FTM0_CH3>
//     <0=> Default
#define FTM0_CH3_PIN_SEL     0

// Pin Mapping for FTM0_CH4 signal
//   <o> FTM0_CH4 [PTD4]<name=FTM0_CH4_PIN_SEL>
//   <i> Shows which pin FTM0_CH4 is mapped to
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,FTM0_CH4>
//     <0=> Default
#define FTM0_CH4_PIN_SEL     0

// Pin Mapping for FTM0_CH5 signal
//   <o> FTM0_CH5 [PTA0, PTD5]<name=FTM0_CH5_PIN_SEL>
//   <i> Shows which pin FTM0_CH5 is mapped to
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,FTM0_CH5>
//     <2=> PTD5<selection=PTD5_SIG_SEL,FTM0_CH5>
//     <0=> Default
#define FTM0_CH5_PIN_SEL     0

// Pin Mapping for FTM0_CH6 signal
//   <o> FTM0_CH6 [PTA1, PTD6]<name=FTM0_CH6_PIN_SEL>
//   <i> Shows which pin FTM0_CH6 is mapped to
//     <0=> Disabled
//     <1=> PTA1<selection=PTA1_SIG_SEL,FTM0_CH6>
//     <2=> PTD6<selection=PTD6_SIG_SEL,FTM0_CH6>
//     <0=> Default
#define FTM0_CH6_PIN_SEL     0

// Pin Mapping for FTM0_CH7 signal
//   <o> FTM0_CH7 [PTA2, PTD7]<name=FTM0_CH7_PIN_SEL>
//   <i> Shows which pin FTM0_CH7 is mapped to
//     <0=> Disabled
//     <1=> PTA2<selection=PTA2_SIG_SEL,FTM0_CH7>
//     <2=> PTD7<selection=PTD7_SIG_SEL,FTM0_CH7>
//     <0=> Default
#define FTM0_CH7_PIN_SEL     0

// Pin Mapping for FTM0_FLT0 signal
//   <o> FTM0_FLT0 [PTB3, PTD6]<name=FTM0_FLT0_PIN_SEL>
//   <i> Shows which pin FTM0_FLT0 is mapped to
//     <0=> Disabled
//     <1=> PTB3<selection=PTB3_SIG_SEL,FTM0_FLT0>
//     <2=> PTD6<selection=PTD6_SIG_SEL,FTM0_FLT0>
//     <0=> Default
#define FTM0_FLT0_PIN_SEL    0
#if (FTM0_FLT0_PIN_SEL == 1)
#define FTM0_FLT0_GPIO       USBDM::GpioB<3>
#define FTM0_FLT0_FN         6
#elif (FTM0_FLT0_PIN_SEL == 2)
#define FTM0_FLT0_GPIO       USBDM::GpioD<6>
#define FTM0_FLT0_FN         6
#endif

// Pin Mapping for FTM0_FLT1 signal
//   <o> FTM0_FLT1 [PTD7]<name=FTM0_FLT1_PIN_SEL>
//   <i> Shows which pin FTM0_FLT1 is mapped to
//     <0=> Disabled
//     <1=> PTD7<selection=PTD7_SIG_SEL,FTM0_FLT1>
//     <0=> Default
#define FTM0_FLT1_PIN_SEL    0
#if (FTM0_FLT1_PIN_SEL == 1)
#define FTM0_FLT1_GPIO       USBDM::GpioD<7>
#define FTM0_FLT1_FN         6
#endif

// Pin Mapping for FTM0_FLT2 signal
//   <o> FTM0_FLT2 [PTA18]<name=FTM0_FLT2_PIN_SEL>
//   <i> Shows which pin FTM0_FLT2 is mapped to
//     <0=> Disabled
//     <1=> PTA18<selection=PTA18_SIG_SEL,FTM0_FLT2>
//     <0=> Default
#define FTM0_FLT2_PIN_SEL    0
#if (FTM0_FLT2_PIN_SEL == 1)
#define FTM0_FLT2_GPIO       USBDM::GpioA<18>
#define FTM0_FLT2_FN         3
#endif

// Pin Mapping for FTM0_FLT3 signal
//   <o> FTM0_FLT3 [PTB2]<name=FTM0_FLT3_PIN_SEL>
//   <i> Shows which pin FTM0_FLT3 is mapped to
//     <0=> Disabled
//     <1=> PTB2<selection=PTB2_SIG_SEL,FTM0_FLT3>
//     <0=> Default
#define FTM0_FLT3_PIN_SEL    0
#if (FTM0_FLT3_PIN_SEL == 1)
#define FTM0_FLT3_GPIO       USBDM::GpioB<2>
#define FTM0_FLT3_FN         6
#endif

// </h>

// <h> FlexTimer (FTM1)

// Pin Mapping for FTM1_CH0 signal
//   <o> FTM1_CH0 [PTA12, PTB0]<name=FTM1_CH0_PIN_SEL>
//   <i> Shows which pin FTM1_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTA12<selection=PTA12_SIG_SEL,FTM1_CH0>
//     <2=> PTB0<selection=PTB0_SIG_SEL,FTM1_CH0>
//     <0=> Default
#define FTM1_CH0_PIN_SEL     0

// Pin Mapping for FTM1_CH1 signal
//   <o> FTM1_CH1 [PTA13, PTB1]<name=FTM1_CH1_PIN_SEL>
//   <i> Shows which pin FTM1_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTA13<selection=PTA13_SIG_SEL,FTM1_CH1>
//     <2=> PTB1<selection=PTB1_SIG_SEL,FTM1_CH1>
//     <0=> Default
#define FTM1_CH1_PIN_SEL     0

// Pin Mapping for FTM1_FLT0 signal
//   <o> FTM1_FLT0 [PTA19]<name=FTM1_FLT0_PIN_SEL>
//   <i> Shows which pin FTM1_FLT0 is mapped to
//     <0=> Disabled
//     <1=> PTA19<selection=PTA19_SIG_SEL,FTM1_FLT0>
//     <0=> Default
#define FTM1_FLT0_PIN_SEL    0
#if (FTM1_FLT0_PIN_SEL == 1)
#define FTM1_FLT0_GPIO       USBDM::GpioA<19>
#define FTM1_FLT0_FN         3
#endif

// Pin Mapping for FTM1_QD_PHA signal
//   <o> FTM1_QD_PHA [PTB0, PTA12]<name=FTM1_QD_PHA_PIN_SEL>
//   <i> Shows which pin FTM1_QD_PHA is mapped to
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,FTM1_QD_PHA>
//     <2=> PTA12<selection=PTA12_SIG_SEL,FTM1_QD_PHA>
//     <0=> Default
#define FTM1_QD_PHA_PIN_SEL  0
#if (FTM1_QD_PHA_PIN_SEL == 1)
#define FTM1_QD_PHA_GPIO     USBDM::GpioB<0>
#define FTM1_QD_PHA_FN       6
#elif (FTM1_QD_PHA_PIN_SEL == 2)
#define FTM1_QD_PHA_GPIO     USBDM::GpioA<12>
#define FTM1_QD_PHA_FN       7
#endif

// Pin Mapping for FTM1_QD_PHB signal
//   <o> FTM1_QD_PHB [PTB1, PTA13]<name=FTM1_QD_PHB_PIN_SEL>
//   <i> Shows which pin FTM1_QD_PHB is mapped to
//     <0=> Disabled
//     <1=> PTB1<selection=PTB1_SIG_SEL,FTM1_QD_PHB>
//     <2=> PTA13<selection=PTA13_SIG_SEL,FTM1_QD_PHB>
//     <0=> Default
#define FTM1_QD_PHB_PIN_SEL  0
#if (FTM1_QD_PHB_PIN_SEL == 1)
#define FTM1_QD_PHB_GPIO     USBDM::GpioB<1>
#define FTM1_QD_PHB_FN       6
#elif (FTM1_QD_PHB_PIN_SEL == 2)
#define FTM1_QD_PHB_GPIO     USBDM::GpioA<13>
#define FTM1_QD_PHB_FN       7
#endif

// </h>

// <h> FlexTimer (FTM2)

// Pin Mapping for FTM2_CH0 signal
//   <o> FTM2_CH0 [PTB18]<name=FTM2_CH0_PIN_SEL>
//   <i> Shows which pin FTM2_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTB18<selection=PTB18_SIG_SEL,FTM2_CH0>
//     <0=> Default
#define FTM2_CH0_PIN_SEL     0

// Pin Mapping for FTM2_CH1 signal
//   <o> FTM2_CH1 [PTB19]<name=FTM2_CH1_PIN_SEL>
//   <i> Shows which pin FTM2_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTB19<selection=PTB19_SIG_SEL,FTM2_CH1>
//     <0=> Default
#define FTM2_CH1_PIN_SEL     0

// Pin Mapping for FTM2_FLT0 signal
//   <o> FTM2_FLT0 [PTC9]<name=FTM2_FLT0_PIN_SEL>
//   <i> Shows which pin FTM2_FLT0 is mapped to
//     <0=> Disabled
//     <1=> PTC9<selection=PTC9_SIG_SEL,FTM2_FLT0>
//     <0=> Default
#define FTM2_FLT0_PIN_SEL    0
#if (FTM2_FLT0_PIN_SEL == 1)
#define FTM2_FLT0_GPIO       USBDM::GpioC<9>
#define FTM2_FLT0_FN         6
#endif

// Pin Mapping for FTM2_QD_PHA signal
//   <o> FTM2_QD_PHA [PTB18]<name=FTM2_QD_PHA_PIN_SEL>
//   <i> Shows which pin FTM2_QD_PHA is mapped to
//     <0=> Disabled
//     <1=> PTB18<selection=PTB18_SIG_SEL,FTM2_QD_PHA>
//     <0=> Default
#define FTM2_QD_PHA_PIN_SEL  0
#if (FTM2_QD_PHA_PIN_SEL == 1)
#define FTM2_QD_PHA_GPIO     USBDM::GpioB<18>
#define FTM2_QD_PHA_FN       6
#endif

// Pin Mapping for FTM2_QD_PHB signal
//   <o> FTM2_QD_PHB [PTB19]<name=FTM2_QD_PHB_PIN_SEL>
//   <i> Shows which pin FTM2_QD_PHB is mapped to
//     <0=> Disabled
//     <1=> PTB19<selection=PTB19_SIG_SEL,FTM2_QD_PHB>
//     <0=> Default
#define FTM2_QD_PHB_PIN_SEL  0
#if (FTM2_QD_PHB_PIN_SEL == 1)
#define FTM2_QD_PHB_GPIO     USBDM::GpioB<19>
#define FTM2_QD_PHB_FN       6
#endif

// </h>

// <h> FlexTimer (FTM3)

// Pin Mapping for FTM3_CH0 signal
//   <o> FTM3_CH0 [PTD0]<name=FTM3_CH0_PIN_SEL>
//   <i> Shows which pin FTM3_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,FTM3_CH0>
//     <0=> Default
#define FTM3_CH0_PIN_SEL     0
#if (FTM3_CH0_PIN_SEL == 1)
#define FTM3_CH0_GPIO        USBDM::GpioD<0>
#define FTM3_CH0_FN          4
#endif

// Pin Mapping for FTM3_CH1 signal
//   <o> FTM3_CH1 [PTD1]<name=FTM3_CH1_PIN_SEL>
//   <i> Shows which pin FTM3_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTD1<selection=PTD1_SIG_SEL,FTM3_CH1>
//     <0=> Default
#define FTM3_CH1_PIN_SEL     0
#if (FTM3_CH1_PIN_SEL == 1)
#define FTM3_CH1_GPIO        USBDM::GpioD<1>
#define FTM3_CH1_FN          4
#endif

// Pin Mapping for FTM3_CH2 signal
//   <o> FTM3_CH2 [PTD2]<name=FTM3_CH2_PIN_SEL>
//   <i> Shows which pin FTM3_CH2 is mapped to
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,FTM3_CH2>
//     <0=> Default
#define FTM3_CH2_PIN_SEL     0
#if (FTM3_CH2_PIN_SEL == 1)
#define FTM3_CH2_GPIO        USBDM::GpioD<2>
#define FTM3_CH2_FN          4
#endif

// Pin Mapping for FTM3_CH3 signal
//   <o> FTM3_CH3 [PTD3]<name=FTM3_CH3_PIN_SEL>
//   <i> Shows which pin FTM3_CH3 is mapped to
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,FTM3_CH3>
//     <0=> Default
#define FTM3_CH3_PIN_SEL     0
#if (FTM3_CH3_PIN_SEL == 1)
#define FTM3_CH3_GPIO        USBDM::GpioD<3>
#define FTM3_CH3_FN          4
#endif

// Pin Mapping for FTM3_CH4 signal
//   <o> FTM3_CH4 [PTC8]<name=FTM3_CH4_PIN_SEL>
//   <i> Shows which pin FTM3_CH4 is mapped to
//     <0=> Disabled
//     <1=> PTC8<selection=PTC8_SIG_SEL,FTM3_CH4>
//     <0=> Default
#define FTM3_CH4_PIN_SEL     0
#if (FTM3_CH4_PIN_SEL == 1)
#define FTM3_CH4_GPIO        USBDM::GpioC<8>
#define FTM3_CH4_FN          3
#endif

// Pin Mapping for FTM3_CH5 signal
//   <o> FTM3_CH5 [PTC9]<name=FTM3_CH5_PIN_SEL>
//   <i> Shows which pin FTM3_CH5 is mapped to
//     <0=> Disabled
//     <1=> PTC9<selection=PTC9_SIG_SEL,FTM3_CH5>
//     <0=> Default
#define FTM3_CH5_PIN_SEL     0
#if (FTM3_CH5_PIN_SEL == 1)
#define FTM3_CH5_GPIO        USBDM::GpioC<9>
#define FTM3_CH5_FN          3
#endif

// Pin Mapping for FTM3_CH6 signal
//   <o> FTM3_CH6 [PTC10]<name=FTM3_CH6_PIN_SEL>
//   <i> Shows which pin FTM3_CH6 is mapped to
//     <0=> Disabled
//     <1=> PTC10<selection=PTC10_SIG_SEL,FTM3_CH6>
//     <0=> Default
#define FTM3_CH6_PIN_SEL     0
#if (FTM3_CH6_PIN_SEL == 1)
#define FTM3_CH6_GPIO        USBDM::GpioC<10>
#define FTM3_CH6_FN          3
#endif

// Pin Mapping for FTM3_CH7 signal
//   <o> FTM3_CH7 [PTC11]<name=FTM3_CH7_PIN_SEL>
//   <i> Shows which pin FTM3_CH7 is mapped to
//     <0=> Disabled
//     <1=> PTC11<selection=PTC11_SIG_SEL,FTM3_CH7>
//     <0=> Default
#define FTM3_CH7_PIN_SEL     0
#if (FTM3_CH7_PIN_SEL == 1)
#define FTM3_CH7_GPIO        USBDM::GpioC<11>
#define FTM3_CH7_FN          3
#endif

// </h>

// <h> General Purpose I/O (GPIOA)

// Pin Mapping for GPIOA_0 signal
//   <o> GPIOA_0 [PTA0]<name=GPIOA_0_PIN_SEL>
//   <i> Shows which pin GPIOA_0 is mapped to
//     <0=> Disabled
//     <1=> PTA0 (reset default)<selection=PTA0_SIG_SEL,GPIOA_0 (reset default)>
//     <2=> PTA0<selection=PTA0_SIG_SEL,GPIOA_0>
//     <0=> Default
#define GPIOA_0_PIN_SEL      0
#if (GPIOA_0_PIN_SEL == 2)
#define GPIOA_0_GPIO         USBDM::GpioA<0>
#define GPIOA_0_FN           1
#endif

// Pin Mapping for GPIOA_1 signal
//   <o> GPIOA_1 [PTA1]<name=GPIOA_1_PIN_SEL>
//   <i> Shows which pin GPIOA_1 is mapped to
//     <0=> Disabled
//     <1=> PTA1 (reset default)<selection=PTA1_SIG_SEL,GPIOA_1 (reset default)>
//     <2=> PTA1<selection=PTA1_SIG_SEL,GPIOA_1>
//     <0=> Default
#define GPIOA_1_PIN_SEL      0
#if (GPIOA_1_PIN_SEL == 2)
#define GPIOA_1_GPIO         USBDM::GpioA<1>
#define GPIOA_1_FN           1
#endif

// Pin Mapping for GPIOA_2 signal
//   <o> GPIOA_2 [PTA2]<name=GPIOA_2_PIN_SEL>
//   <i> Shows which pin GPIOA_2 is mapped to
//     <0=> Disabled
//     <1=> PTA2 (reset default)<selection=PTA2_SIG_SEL,GPIOA_2 (reset default)>
//     <2=> PTA2<selection=PTA2_SIG_SEL,GPIOA_2>
//     <0=> Default
#define GPIOA_2_PIN_SEL      0
#if (GPIOA_2_PIN_SEL == 2)
#define GPIOA_2_GPIO         USBDM::GpioA<2>
#define GPIOA_2_FN           1
#endif

// Pin Mapping for GPIOA_3 signal
//   <o> GPIOA_3 [PTA3]<name=GPIOA_3_PIN_SEL>
//   <i> Shows which pin GPIOA_3 is mapped to
//     <0=> Disabled
//     <1=> PTA3 (reset default)<selection=PTA3_SIG_SEL,GPIOA_3 (reset default)>
//     <2=> PTA3<selection=PTA3_SIG_SEL,GPIOA_3>
//     <0=> Default
#define GPIOA_3_PIN_SEL      0
#if (GPIOA_3_PIN_SEL == 2)
#define GPIOA_3_GPIO         USBDM::GpioA<3>
#define GPIOA_3_FN           1
#endif

// Pin Mapping for GPIOA_4 signal
//   <o> GPIOA_4 [PTA4]<name=GPIOA_4_PIN_SEL>
//   <i> Shows which pin GPIOA_4 is mapped to
//     <0=> Disabled
//     <1=> PTA4 (reset default)<selection=PTA4_SIG_SEL,GPIOA_4/LLWU_P3 (reset default)>
//     <2=> PTA4<selection=PTA4_SIG_SEL,GPIOA_4/LLWU_P3>
//     <0=> Default
#define GPIOA_4_PIN_SEL      0
#if (GPIOA_4_PIN_SEL == 2)
#define GPIOA_4_GPIO         USBDM::GpioA<4>
#define GPIOA_4_FN           1
#endif

// Pin Mapping for GPIOA_5 signal
//   <o> GPIOA_5 [PTA5]<name=GPIOA_5_PIN_SEL>
//   <i> Shows which pin GPIOA_5 is mapped to
//     <0=> Disabled
//     <1=> PTA5 (reset default)<selection=PTA5_SIG_SEL,GPIOA_5 (reset default)>
//     <2=> PTA5<selection=PTA5_SIG_SEL,GPIOA_5>
//     <1=> Default
#define GPIOA_5_PIN_SEL      1
#if (GPIOA_5_PIN_SEL == 2)
#define GPIOA_5_GPIO         USBDM::GpioA<5>
#define GPIOA_5_FN           1
#endif

// Pin Mapping for GPIOA_12 signal
//   <o> GPIOA_12 [PTA12]<name=GPIOA_12_PIN_SEL>
//   <i> Shows which pin GPIOA_12 is mapped to
//     <0=> Disabled
//     <1=> PTA12 (reset default)<selection=PTA12_SIG_SEL,GPIOA_12 (reset default)>
//     <2=> PTA12<selection=PTA12_SIG_SEL,GPIOA_12>
//     <0=> Default
#define GPIOA_12_PIN_SEL     0
#if (GPIOA_12_PIN_SEL == 2)
#define GPIOA_12_GPIO        USBDM::GpioA<12>
#define GPIOA_12_FN          1
#endif

// Pin Mapping for GPIOA_13 signal
//   <o> GPIOA_13 [PTA13]<name=GPIOA_13_PIN_SEL>
//   <i> Shows which pin GPIOA_13 is mapped to
//     <0=> Disabled
//     <1=> PTA13 (reset default)<selection=PTA13_SIG_SEL,GPIOA_13/LLWU_P4 (reset default)>
//     <2=> PTA13<selection=PTA13_SIG_SEL,GPIOA_13/LLWU_P4>
//     <0=> Default
#define GPIOA_13_PIN_SEL     0
#if (GPIOA_13_PIN_SEL == 2)
#define GPIOA_13_GPIO        USBDM::GpioA<13>
#define GPIOA_13_FN          1
#endif

// Pin Mapping for GPIOA_18 signal
//   <o> GPIOA_18 [PTA18]<name=GPIOA_18_PIN_SEL>
//   <i> Shows which pin GPIOA_18 is mapped to
//     <0=> Disabled
//     <1=> PTA18 (reset default)<selection=PTA18_SIG_SEL,GPIOA_18 (reset default)>
//     <2=> PTA18<selection=PTA18_SIG_SEL,GPIOA_18>
//     <0=> Default
#define GPIOA_18_PIN_SEL     0
#if (GPIOA_18_PIN_SEL == 2)
#define GPIOA_18_GPIO        USBDM::GpioA<18>
#define GPIOA_18_FN          1
#endif

// Pin Mapping for GPIOA_19 signal
//   <o> GPIOA_19 [PTA19]<name=GPIOA_19_PIN_SEL>
//   <i> Shows which pin GPIOA_19 is mapped to
//     <0=> Disabled
//     <1=> PTA19 (reset default)<selection=PTA19_SIG_SEL,GPIOA_19 (reset default)>
//     <2=> PTA19<selection=PTA19_SIG_SEL,GPIOA_19>
//     <0=> Default
#define GPIOA_19_PIN_SEL     0
#if (GPIOA_19_PIN_SEL == 2)
#define GPIOA_19_GPIO        USBDM::GpioA<19>
#define GPIOA_19_FN          1
#endif

// </h>

// <h> General Purpose I/O (GPIOB)

// Pin Mapping for GPIOB_0 signal
//   <o> GPIOB_0 [PTB0]<name=GPIOB_0_PIN_SEL>
//   <i> Shows which pin GPIOB_0 is mapped to
//     <0=> Disabled
//     <1=> PTB0 (reset default)<selection=PTB0_SIG_SEL,GPIOB_0/LLWU_P5 (reset default)>
//     <2=> PTB0<selection=PTB0_SIG_SEL,GPIOB_0/LLWU_P5>
//     <0=> Default
#define GPIOB_0_PIN_SEL      0
#if (GPIOB_0_PIN_SEL == 2)
#define GPIOB_0_GPIO         USBDM::GpioB<0>
#define GPIOB_0_FN           1
#endif

// Pin Mapping for GPIOB_1 signal
//   <o> GPIOB_1 [PTB1]<name=GPIOB_1_PIN_SEL>
//   <i> Shows which pin GPIOB_1 is mapped to
//     <0=> Disabled
//     <1=> PTB1 (reset default)<selection=PTB1_SIG_SEL,GPIOB_1 (reset default)>
//     <2=> PTB1<selection=PTB1_SIG_SEL,GPIOB_1>
//     <0=> Default
#define GPIOB_1_PIN_SEL      0
#if (GPIOB_1_PIN_SEL == 2)
#define GPIOB_1_GPIO         USBDM::GpioB<1>
#define GPIOB_1_FN           1
#endif

// Pin Mapping for GPIOB_2 signal
//   <o> GPIOB_2 [PTB2]<name=GPIOB_2_PIN_SEL>
//   <i> Shows which pin GPIOB_2 is mapped to
//     <0=> Disabled
//     <1=> PTB2 (reset default)<selection=PTB2_SIG_SEL,GPIOB_2 (reset default)>
//     <2=> PTB2<selection=PTB2_SIG_SEL,GPIOB_2>
//     <0=> Default
#define GPIOB_2_PIN_SEL      0
#if (GPIOB_2_PIN_SEL == 2)
#define GPIOB_2_GPIO         USBDM::GpioB<2>
#define GPIOB_2_FN           1
#endif

// Pin Mapping for GPIOB_3 signal
//   <o> GPIOB_3 [PTB3]<name=GPIOB_3_PIN_SEL>
//   <i> Shows which pin GPIOB_3 is mapped to
//     <0=> Disabled
//     <1=> PTB3 (reset default)<selection=PTB3_SIG_SEL,GPIOB_3 (reset default)>
//     <2=> PTB3<selection=PTB3_SIG_SEL,GPIOB_3>
//     <0=> Default
#define GPIOB_3_PIN_SEL      0
#if (GPIOB_3_PIN_SEL == 2)
#define GPIOB_3_GPIO         USBDM::GpioB<3>
#define GPIOB_3_FN           1
#endif

// Pin Mapping for GPIOB_16 signal
//   <o> GPIOB_16 [PTB16]<name=GPIOB_16_PIN_SEL>
//   <i> Shows which pin GPIOB_16 is mapped to
//     <0=> Disabled
//     <1=> PTB16 (reset default)<selection=PTB16_SIG_SEL,GPIOB_16 (reset default)>
//     <2=> PTB16<selection=PTB16_SIG_SEL,GPIOB_16>
//     <1=> Default
#define GPIOB_16_PIN_SEL     1
#if (GPIOB_16_PIN_SEL == 2)
#define GPIOB_16_GPIO        USBDM::GpioB<16>
#define GPIOB_16_FN          1
#endif

// Pin Mapping for GPIOB_17 signal
//   <o> GPIOB_17 [PTB17]<name=GPIOB_17_PIN_SEL>
//   <i> Shows which pin GPIOB_17 is mapped to
//     <0=> Disabled
//     <1=> PTB17 (reset default)<selection=PTB17_SIG_SEL,GPIOB_17 (reset default)>
//     <2=> PTB17<selection=PTB17_SIG_SEL,GPIOB_17>
//     <1=> Default
#define GPIOB_17_PIN_SEL     1
#if (GPIOB_17_PIN_SEL == 2)
#define GPIOB_17_GPIO        USBDM::GpioB<17>
#define GPIOB_17_FN          1
#endif

// Pin Mapping for GPIOB_18 signal
//   <o> GPIOB_18 [PTB18]<name=GPIOB_18_PIN_SEL>
//   <i> Shows which pin GPIOB_18 is mapped to
//     <0=> Disabled
//     <1=> PTB18 (reset default)<selection=PTB18_SIG_SEL,GPIOB_18 (reset default)>
//     <2=> PTB18<selection=PTB18_SIG_SEL,GPIOB_18>
//     <1=> Default
#define GPIOB_18_PIN_SEL     1
#if (GPIOB_18_PIN_SEL == 2)
#define GPIOB_18_GPIO        USBDM::GpioB<18>
#define GPIOB_18_FN          1
#endif

// Pin Mapping for GPIOB_19 signal
//   <o> GPIOB_19 [PTB19]<name=GPIOB_19_PIN_SEL>
//   <i> Shows which pin GPIOB_19 is mapped to
//     <0=> Disabled
//     <1=> PTB19 (reset default)<selection=PTB19_SIG_SEL,GPIOB_19 (reset default)>
//     <2=> PTB19<selection=PTB19_SIG_SEL,GPIOB_19>
//     <1=> Default
#define GPIOB_19_PIN_SEL     1
#if (GPIOB_19_PIN_SEL == 2)
#define GPIOB_19_GPIO        USBDM::GpioB<19>
#define GPIOB_19_FN          1
#endif

// </h>

// <h> General Purpose I/O (GPIOC)

// Pin Mapping for GPIOC_0 signal
//   <o> GPIOC_0 [PTC0]<name=GPIOC_0_PIN_SEL>
//   <i> Shows which pin GPIOC_0 is mapped to
//     <0=> Disabled
//     <1=> PTC0 (reset default)<selection=PTC0_SIG_SEL,GPIOC_0 (reset default)>
//     <2=> PTC0<selection=PTC0_SIG_SEL,GPIOC_0>
//     <0=> Default
#define GPIOC_0_PIN_SEL      0
#if (GPIOC_0_PIN_SEL == 2)
#define GPIOC_0_GPIO         USBDM::GpioC<0>
#define GPIOC_0_FN           1
#endif

// Pin Mapping for GPIOC_1 signal
//   <o> GPIOC_1 [PTC1]<name=GPIOC_1_PIN_SEL>
//   <i> Shows which pin GPIOC_1 is mapped to
//     <0=> Disabled
//     <1=> PTC1 (reset default)<selection=PTC1_SIG_SEL,GPIOC_1/LLWU_P6 (reset default)>
//     <2=> PTC1<selection=PTC1_SIG_SEL,GPIOC_1/LLWU_P6>
//     <0=> Default
#define GPIOC_1_PIN_SEL      0
#if (GPIOC_1_PIN_SEL == 2)
#define GPIOC_1_GPIO         USBDM::GpioC<1>
#define GPIOC_1_FN           1
#endif

// Pin Mapping for GPIOC_2 signal
//   <o> GPIOC_2 [PTC2]<name=GPIOC_2_PIN_SEL>
//   <i> Shows which pin GPIOC_2 is mapped to
//     <0=> Disabled
//     <1=> PTC2 (reset default)<selection=PTC2_SIG_SEL,GPIOC_2 (reset default)>
//     <2=> PTC2<selection=PTC2_SIG_SEL,GPIOC_2>
//     <0=> Default
#define GPIOC_2_PIN_SEL      0
#if (GPIOC_2_PIN_SEL == 2)
#define GPIOC_2_GPIO         USBDM::GpioC<2>
#define GPIOC_2_FN           1
#endif

// Pin Mapping for GPIOC_3 signal
//   <o> GPIOC_3 [PTC3]<name=GPIOC_3_PIN_SEL>
//   <i> Shows which pin GPIOC_3 is mapped to
//     <0=> Disabled
//     <1=> PTC3 (reset default)<selection=PTC3_SIG_SEL,GPIOC_3/LLWU_P7 (reset default)>
//     <2=> PTC3<selection=PTC3_SIG_SEL,GPIOC_3/LLWU_P7>
//     <0=> Default
#define GPIOC_3_PIN_SEL      0
#if (GPIOC_3_PIN_SEL == 2)
#define GPIOC_3_GPIO         USBDM::GpioC<3>
#define GPIOC_3_FN           1
#endif

// Pin Mapping for GPIOC_4 signal
//   <o> GPIOC_4 [PTC4]<name=GPIOC_4_PIN_SEL>
//   <i> Shows which pin GPIOC_4 is mapped to
//     <0=> Disabled
//     <1=> PTC4 (reset default)<selection=PTC4_SIG_SEL,GPIOC_4/LLWU_P8 (reset default)>
//     <2=> PTC4<selection=PTC4_SIG_SEL,GPIOC_4/LLWU_P8>
//     <1=> Default
#define GPIOC_4_PIN_SEL      1
#if (GPIOC_4_PIN_SEL == 2)
#define GPIOC_4_GPIO         USBDM::GpioC<4>
#define GPIOC_4_FN           1
#endif

// Pin Mapping for GPIOC_5 signal
//   <o> GPIOC_5 [PTC5]<name=GPIOC_5_PIN_SEL>
//   <i> Shows which pin GPIOC_5 is mapped to
//     <0=> Disabled
//     <1=> PTC5 (reset default)<selection=PTC5_SIG_SEL,GPIOC_5/LLWU_P9 (reset default)>
//     <2=> PTC5<selection=PTC5_SIG_SEL,GPIOC_5/LLWU_P9>
//     <1=> Default
#define GPIOC_5_PIN_SEL      1
#if (GPIOC_5_PIN_SEL == 2)
#define GPIOC_5_GPIO         USBDM::GpioC<5>
#define GPIOC_5_FN           1
#endif

// Pin Mapping for GPIOC_6 signal
//   <o> GPIOC_6 [PTC6]<name=GPIOC_6_PIN_SEL>
//   <i> Shows which pin GPIOC_6 is mapped to
//     <0=> Disabled
//     <1=> PTC6 (reset default)<selection=PTC6_SIG_SEL,GPIOC_6/LLWU_P10 (reset default)>
//     <2=> PTC6<selection=PTC6_SIG_SEL,GPIOC_6/LLWU_P10>
//     <0=> Default
#define GPIOC_6_PIN_SEL      0
#if (GPIOC_6_PIN_SEL == 2)
#define GPIOC_6_GPIO         USBDM::GpioC<6>
#define GPIOC_6_FN           1
#endif

// Pin Mapping for GPIOC_7 signal
//   <o> GPIOC_7 [PTC7]<name=GPIOC_7_PIN_SEL>
//   <i> Shows which pin GPIOC_7 is mapped to
//     <0=> Disabled
//     <1=> PTC7 (reset default)<selection=PTC7_SIG_SEL,GPIOC_7 (reset default)>
//     <2=> PTC7<selection=PTC7_SIG_SEL,GPIOC_7>
//     <0=> Default
#define GPIOC_7_PIN_SEL      0
#if (GPIOC_7_PIN_SEL == 2)
#define GPIOC_7_GPIO         USBDM::GpioC<7>
#define GPIOC_7_FN           1
#endif

// Pin Mapping for GPIOC_8 signal
//   <o> GPIOC_8 [PTC8]<name=GPIOC_8_PIN_SEL>
//   <i> Shows which pin GPIOC_8 is mapped to
//     <0=> Disabled
//     <1=> PTC8 (reset default)<selection=PTC8_SIG_SEL,GPIOC_8 (reset default)>
//     <2=> PTC8<selection=PTC8_SIG_SEL,GPIOC_8>
//     <0=> Default
#define GPIOC_8_PIN_SEL      0
#if (GPIOC_8_PIN_SEL == 2)
#define GPIOC_8_GPIO         USBDM::GpioC<8>
#define GPIOC_8_FN           1
#endif

// Pin Mapping for GPIOC_9 signal
//   <o> GPIOC_9 [PTC9]<name=GPIOC_9_PIN_SEL>
//   <i> Shows which pin GPIOC_9 is mapped to
//     <0=> Disabled
//     <1=> PTC9 (reset default)<selection=PTC9_SIG_SEL,GPIOC_9 (reset default)>
//     <2=> PTC9<selection=PTC9_SIG_SEL,GPIOC_9>
//     <0=> Default
#define GPIOC_9_PIN_SEL      0
#if (GPIOC_9_PIN_SEL == 2)
#define GPIOC_9_GPIO         USBDM::GpioC<9>
#define GPIOC_9_FN           1
#endif

// Pin Mapping for GPIOC_10 signal
//   <o> GPIOC_10 [PTC10]<name=GPIOC_10_PIN_SEL>
//   <i> Shows which pin GPIOC_10 is mapped to
//     <0=> Disabled
//     <1=> PTC10 (reset default)<selection=PTC10_SIG_SEL,GPIOC_10 (reset default)>
//     <2=> PTC10<selection=PTC10_SIG_SEL,GPIOC_10>
//     <0=> Default
#define GPIOC_10_PIN_SEL     0
#if (GPIOC_10_PIN_SEL == 2)
#define GPIOC_10_GPIO        USBDM::GpioC<10>
#define GPIOC_10_FN          1
#endif

// Pin Mapping for GPIOC_11 signal
//   <o> GPIOC_11 [PTC11]<name=GPIOC_11_PIN_SEL>
//   <i> Shows which pin GPIOC_11 is mapped to
//     <0=> Disabled
//     <1=> PTC11 (reset default)<selection=PTC11_SIG_SEL,GPIOC_11/LLWU_P11 (reset default)>
//     <2=> PTC11<selection=PTC11_SIG_SEL,GPIOC_11/LLWU_P11>
//     <0=> Default
#define GPIOC_11_PIN_SEL     0
#if (GPIOC_11_PIN_SEL == 2)
#define GPIOC_11_GPIO        USBDM::GpioC<11>
#define GPIOC_11_FN          1
#endif

// </h>

// <h> General Purpose I/O (GPIOD)

// Pin Mapping for GPIOD_0 signal
//   <o> GPIOD_0 [PTD0]<name=GPIOD_0_PIN_SEL>
//   <i> Shows which pin GPIOD_0 is mapped to
//     <0=> Disabled
//     <1=> PTD0 (reset default)<selection=PTD0_SIG_SEL,GPIOD_0/LLWU_P12 (reset default)>
//     <2=> PTD0<selection=PTD0_SIG_SEL,GPIOD_0/LLWU_P12>
//     <1=> Default
#define GPIOD_0_PIN_SEL      1
#if (GPIOD_0_PIN_SEL == 2)
#define GPIOD_0_GPIO         USBDM::GpioD<0>
#define GPIOD_0_FN           1
#endif

// Pin Mapping for GPIOD_1 signal
//   <o> GPIOD_1 [PTD1]<name=GPIOD_1_PIN_SEL>
//   <i> Shows which pin GPIOD_1 is mapped to
//     <0=> Disabled
//     <1=> PTD1 (reset default)<selection=PTD1_SIG_SEL,GPIOD_1 (reset default)>
//     <2=> PTD1<selection=PTD1_SIG_SEL,GPIOD_1>
//     <0=> Default
#define GPIOD_1_PIN_SEL      0
#if (GPIOD_1_PIN_SEL == 2)
#define GPIOD_1_GPIO         USBDM::GpioD<1>
#define GPIOD_1_FN           1
#endif

// Pin Mapping for GPIOD_2 signal
//   <o> GPIOD_2 [PTD2]<name=GPIOD_2_PIN_SEL>
//   <i> Shows which pin GPIOD_2 is mapped to
//     <0=> Disabled
//     <1=> PTD2 (reset default)<selection=PTD2_SIG_SEL,GPIOD_2/LLWU_P13 (reset default)>
//     <2=> PTD2<selection=PTD2_SIG_SEL,GPIOD_2/LLWU_P13>
//     <1=> Default
#define GPIOD_2_PIN_SEL      1
#if (GPIOD_2_PIN_SEL == 2)
#define GPIOD_2_GPIO         USBDM::GpioD<2>
#define GPIOD_2_FN           1
#endif

// Pin Mapping for GPIOD_3 signal
//   <o> GPIOD_3 [PTD3]<name=GPIOD_3_PIN_SEL>
//   <i> Shows which pin GPIOD_3 is mapped to
//     <0=> Disabled
//     <1=> PTD3 (reset default)<selection=PTD3_SIG_SEL,GPIOD_3 (reset default)>
//     <2=> PTD3<selection=PTD3_SIG_SEL,GPIOD_3>
//     <1=> Default
#define GPIOD_3_PIN_SEL      1
#if (GPIOD_3_PIN_SEL == 2)
#define GPIOD_3_GPIO         USBDM::GpioD<3>
#define GPIOD_3_FN           1
#endif

// Pin Mapping for GPIOD_4 signal
//   <o> GPIOD_4 [PTD4]<name=GPIOD_4_PIN_SEL>
//   <i> Shows which pin GPIOD_4 is mapped to
//     <0=> Disabled
//     <1=> PTD4 (reset default)<selection=PTD4_SIG_SEL,GPIOD_4/LLWU_P14 (reset default)>
//     <2=> PTD4<selection=PTD4_SIG_SEL,GPIOD_4/LLWU_P14>
//     <1=> Default
#define GPIOD_4_PIN_SEL      1
#if (GPIOD_4_PIN_SEL == 2)
#define GPIOD_4_GPIO         USBDM::GpioD<4>
#define GPIOD_4_FN           1
#endif

// Pin Mapping for GPIOD_5 signal
//   <o> GPIOD_5 [PTD5]<name=GPIOD_5_PIN_SEL>
//   <i> Shows which pin GPIOD_5 is mapped to
//     <0=> Disabled
//     <1=> PTD5 (reset default)<selection=PTD5_SIG_SEL,GPIOD_5 (reset default)>
//     <2=> PTD5<selection=PTD5_SIG_SEL,GPIOD_5>
//     <0=> Default
#define GPIOD_5_PIN_SEL      0
#if (GPIOD_5_PIN_SEL == 2)
#define GPIOD_5_GPIO         USBDM::GpioD<5>
#define GPIOD_5_FN           1
#endif

// Pin Mapping for GPIOD_6 signal
//   <o> GPIOD_6 [PTD6]<name=GPIOD_6_PIN_SEL>
//   <i> Shows which pin GPIOD_6 is mapped to
//     <0=> Disabled
//     <1=> PTD6 (reset default)<selection=PTD6_SIG_SEL,GPIOD_6/LLWU_P15 (reset default)>
//     <2=> PTD6<selection=PTD6_SIG_SEL,GPIOD_6/LLWU_P15>
//     <0=> Default
#define GPIOD_6_PIN_SEL      0
#if (GPIOD_6_PIN_SEL == 2)
#define GPIOD_6_GPIO         USBDM::GpioD<6>
#define GPIOD_6_FN           1
#endif

// Pin Mapping for GPIOD_7 signal
//   <o> GPIOD_7 [PTD7]<name=GPIOD_7_PIN_SEL>
//   <i> Shows which pin GPIOD_7 is mapped to
//     <0=> Disabled
//     <1=> PTD7 (reset default)<selection=PTD7_SIG_SEL,GPIOD_7 (reset default)>
//     <2=> PTD7<selection=PTD7_SIG_SEL,GPIOD_7>
//     <1=> Default
#define GPIOD_7_PIN_SEL      1
#if (GPIOD_7_PIN_SEL == 2)
#define GPIOD_7_GPIO         USBDM::GpioD<7>
#define GPIOD_7_FN           1
#endif

// </h>

// <h> General Purpose I/O (GPIOE)

// Pin Mapping for GPIOE_0 signal
//   <o> GPIOE_0 [PTE0]<name=GPIOE_0_PIN_SEL>
//   <i> Shows which pin GPIOE_0 is mapped to
//     <0=> Disabled
//     <1=> PTE0 (reset default)<selection=PTE0_SIG_SEL,GPIOE_0 (reset default)>
//     <2=> PTE0<selection=PTE0_SIG_SEL,GPIOE_0>
//     <0=> Default
#define GPIOE_0_PIN_SEL      0
#if (GPIOE_0_PIN_SEL == 2)
#define GPIOE_0_GPIO         USBDM::GpioE<0>
#define GPIOE_0_FN           1
#endif

// Pin Mapping for GPIOE_1 signal
//   <o> GPIOE_1 [PTE1]<name=GPIOE_1_PIN_SEL>
//   <i> Shows which pin GPIOE_1 is mapped to
//     <0=> Disabled
//     <1=> PTE1 (reset default)<selection=PTE1_SIG_SEL,GPIOE_1/LLWU_P0 (reset default)>
//     <2=> PTE1<selection=PTE1_SIG_SEL,GPIOE_1/LLWU_P0>
//     <0=> Default
#define GPIOE_1_PIN_SEL      0
#if (GPIOE_1_PIN_SEL == 2)
#define GPIOE_1_GPIO         USBDM::GpioE<1>
#define GPIOE_1_FN           1
#endif

// </h>

// <h> Inter-Integrated Circuit (I2C0)

// Pin Mapping for I2C0_SCL signal
//   <o> I2C0_SCL [PTB0, PTB2, PTD2]<name=I2C0_SCL_PIN_SEL>
//   <i> Shows which pin I2C0_SCL is mapped to
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,I2C0_SCL>
//     <2=> PTB2<selection=PTB2_SIG_SEL,I2C0_SCL>
//     <3=> PTD2<selection=PTD2_SIG_SEL,I2C0_SCL>
//     <0=> Default
#define I2C0_SCL_PIN_SEL     0

// Pin Mapping for I2C0_SDA signal
//   <o> I2C0_SDA [PTB1, PTB3, PTD3]<name=I2C0_SDA_PIN_SEL>
//   <i> Shows which pin I2C0_SDA is mapped to
//     <0=> Disabled
//     <1=> PTB1<selection=PTB1_SIG_SEL,I2C0_SDA>
//     <2=> PTB3<selection=PTB3_SIG_SEL,I2C0_SDA>
//     <3=> PTD3<selection=PTD3_SIG_SEL,I2C0_SDA>
//     <0=> Default
#define I2C0_SDA_PIN_SEL     0

// </h>

// <h> Inter-Integrated Circuit (I2C1)

// Pin Mapping for I2C1_SDA signal
//   <o> I2C1_SDA [PTC11, PTE0]<name=I2C1_SDA_PIN_SEL>
//   <i> Shows which pin I2C1_SDA is mapped to
//     <0=> Disabled
//     <1=> PTC11<selection=PTC11_SIG_SEL,I2C1_SDA>
//     <2=> PTE0<selection=PTE0_SIG_SEL,I2C1_SDA>
//     <0=> Default
#define I2C1_SDA_PIN_SEL     0

// Pin Mapping for I2C1_SCL signal
//   <o> I2C1_SCL [PTC10, PTE1]<name=I2C1_SCL_PIN_SEL>
//   <i> Shows which pin I2C1_SCL is mapped to
//     <0=> Disabled
//     <1=> PTC10<selection=PTC10_SIG_SEL,I2C1_SCL>
//     <2=> PTE1<selection=PTE1_SIG_SEL,I2C1_SCL>
//     <0=> Default
#define I2C1_SCL_PIN_SEL     0

// </h>

// <h> Inter-Integrated Circuit (I2C2)

// Pin Mapping for I2C2_SDA signal
//   <o> I2C2_SDA [PTA13]<name=I2C2_SDA_PIN_SEL>
//   <i> Shows which pin I2C2_SDA is mapped to
//     <0=> Disabled
//     <1=> PTA13<selection=PTA13_SIG_SEL,I2C2_SDA>
//     <0=> Default
#define I2C2_SDA_PIN_SEL     0

// Pin Mapping for I2C2_SCL signal
//   <o> I2C2_SCL [PTA12]<name=I2C2_SCL_PIN_SEL>
//   <i> Shows which pin I2C2_SCL is mapped to
//     <0=> Disabled
//     <1=> PTA12<selection=PTA12_SIG_SEL,I2C2_SCL>
//     <0=> Default
#define I2C2_SCL_PIN_SEL     0

// </h>

// <h> Integrated Interchip Sound (I2S0)

// Pin Mapping for I2S0_MCLK signal
//   <o> I2S0_MCLK [PTC8, PTC6]<name=I2S0_MCLK_PIN_SEL>
//   <i> Shows which pin I2S0_MCLK is mapped to
//     <0=> Disabled
//     <1=> PTC8<selection=PTC8_SIG_SEL,I2S0_MCLK>
//     <2=> PTC6<selection=PTC6_SIG_SEL,I2S0_MCLK>
//     <0=> Default
#define I2S0_MCLK_PIN_SEL    0
#if (I2S0_MCLK_PIN_SEL == 1)
#define I2S0_MCLK_GPIO       USBDM::GpioC<8>
#define I2S0_MCLK_FN         4
#elif (I2S0_MCLK_PIN_SEL == 2)
#define I2S0_MCLK_GPIO       USBDM::GpioC<6>
#define I2S0_MCLK_FN         6
#endif

// Pin Mapping for I2S0_RX_FS signal
//   <o> I2S0_RX_FS [PTC7, PTC10]<name=I2S0_RX_FS_PIN_SEL>
//   <i> Shows which pin I2S0_RX_FS is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,I2S0_RX_FS>
//     <2=> PTC10<selection=PTC10_SIG_SEL,I2S0_RX_FS>
//     <0=> Default
#define I2S0_RX_FS_PIN_SEL   0
#if (I2S0_RX_FS_PIN_SEL == 1)
#define I2S0_RX_FS_GPIO      USBDM::GpioC<7>
#define I2S0_RX_FS_FN        4
#elif (I2S0_RX_FS_PIN_SEL == 2)
#define I2S0_RX_FS_GPIO      USBDM::GpioC<10>
#define I2S0_RX_FS_FN        4
#endif

// Pin Mapping for I2S0_TX_BCLK signal
//   <o> I2S0_TX_BCLK [PTB18, PTA5, PTC3]<name=I2S0_TX_BCLK_PIN_SEL>
//   <i> Shows which pin I2S0_TX_BCLK is mapped to
//     <0=> Disabled
//     <1=> PTB18<selection=PTB18_SIG_SEL,I2S0_TX_BCLK>
//     <2=> PTA5<selection=PTA5_SIG_SEL,I2S0_TX_BCLK>
//     <3=> PTC3<selection=PTC3_SIG_SEL,I2S0_TX_BCLK>
//     <0=> Default
#define I2S0_TX_BCLK_PIN_SEL 0
#if (I2S0_TX_BCLK_PIN_SEL == 1)
#define I2S0_TX_BCLK_GPIO    USBDM::GpioB<18>
#define I2S0_TX_BCLK_FN      4
#elif (I2S0_TX_BCLK_PIN_SEL == 2)
#define I2S0_TX_BCLK_GPIO    USBDM::GpioA<5>
#define I2S0_TX_BCLK_FN      6
#elif (I2S0_TX_BCLK_PIN_SEL == 3)
#define I2S0_TX_BCLK_GPIO    USBDM::GpioC<3>
#define I2S0_TX_BCLK_FN      6
#endif

// Pin Mapping for I2S0_TXD1 signal
//   <o> I2S0_TXD1 [PTC0]<name=I2S0_TXD1_PIN_SEL>
//   <i> Shows which pin I2S0_TXD1 is mapped to
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,I2S0_TXD1>
//     <0=> Default
#define I2S0_TXD1_PIN_SEL    0
#if (I2S0_TXD1_PIN_SEL == 1)
#define I2S0_TXD1_GPIO       USBDM::GpioC<0>
#define I2S0_TXD1_FN         6
#endif

// Pin Mapping for I2S0_TXD0 signal
//   <o> I2S0_TXD0 [PTA12, PTC1]<name=I2S0_TXD0_PIN_SEL>
//   <i> Shows which pin I2S0_TXD0 is mapped to
//     <0=> Disabled
//     <1=> PTA12<selection=PTA12_SIG_SEL,I2S0_TXD0>
//     <2=> PTC1<selection=PTC1_SIG_SEL,I2S0_TXD0>
//     <0=> Default
#define I2S0_TXD0_PIN_SEL    0
#if (I2S0_TXD0_PIN_SEL == 1)
#define I2S0_TXD0_GPIO       USBDM::GpioA<12>
#define I2S0_TXD0_FN         6
#elif (I2S0_TXD0_PIN_SEL == 2)
#define I2S0_TXD0_GPIO       USBDM::GpioC<1>
#define I2S0_TXD0_FN         6
#endif

// Pin Mapping for I2S0_RX_BCLK signal
//   <o> I2S0_RX_BCLK [PTC6, PTC9]<name=I2S0_RX_BCLK_PIN_SEL>
//   <i> Shows which pin I2S0_RX_BCLK is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,I2S0_RX_BCLK>
//     <2=> PTC9<selection=PTC9_SIG_SEL,I2S0_RX_BCLK>
//     <0=> Default
#define I2S0_RX_BCLK_PIN_SEL 0
#if (I2S0_RX_BCLK_PIN_SEL == 1)
#define I2S0_RX_BCLK_GPIO    USBDM::GpioC<6>
#define I2S0_RX_BCLK_FN      4
#elif (I2S0_RX_BCLK_PIN_SEL == 2)
#define I2S0_RX_BCLK_GPIO    USBDM::GpioC<9>
#define I2S0_RX_BCLK_FN      4
#endif

// Pin Mapping for I2S0_TX_FS signal
//   <o> I2S0_TX_FS [PTB19, PTA13, PTC2]<name=I2S0_TX_FS_PIN_SEL>
//   <i> Shows which pin I2S0_TX_FS is mapped to
//     <0=> Disabled
//     <1=> PTB19<selection=PTB19_SIG_SEL,I2S0_TX_FS>
//     <2=> PTA13<selection=PTA13_SIG_SEL,I2S0_TX_FS>
//     <3=> PTC2<selection=PTC2_SIG_SEL,I2S0_TX_FS>
//     <0=> Default
#define I2S0_TX_FS_PIN_SEL   0
#if (I2S0_TX_FS_PIN_SEL == 1)
#define I2S0_TX_FS_GPIO      USBDM::GpioB<19>
#define I2S0_TX_FS_FN        4
#elif (I2S0_TX_FS_PIN_SEL == 2)
#define I2S0_TX_FS_GPIO      USBDM::GpioA<13>
#define I2S0_TX_FS_FN        6
#elif (I2S0_TX_FS_PIN_SEL == 3)
#define I2S0_TX_FS_GPIO      USBDM::GpioC<2>
#define I2S0_TX_FS_FN        6
#endif

// Pin Mapping for I2S0_RXD1 signal
//   <o> I2S0_RXD1 [PTC11]<name=I2S0_RXD1_PIN_SEL>
//   <i> Shows which pin I2S0_RXD1 is mapped to
//     <0=> Disabled
//     <1=> PTC11<selection=PTC11_SIG_SEL,I2S0_RXD1>
//     <0=> Default
#define I2S0_RXD1_PIN_SEL    0
#if (I2S0_RXD1_PIN_SEL == 1)
#define I2S0_RXD1_GPIO       USBDM::GpioC<11>
#define I2S0_RXD1_FN         4
#endif

// Pin Mapping for I2S0_RXD0 signal
//   <o> I2S0_RXD0 [PTC5]<name=I2S0_RXD0_PIN_SEL>
//   <i> Shows which pin I2S0_RXD0 is mapped to
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,I2S0_RXD0>
//     <0=> Default
#define I2S0_RXD0_PIN_SEL    0
#if (I2S0_RXD0_PIN_SEL == 1)
#define I2S0_RXD0_GPIO       USBDM::GpioC<5>
#define I2S0_RXD0_FN         4
#endif

// </h>

// <h> Debug and Control

// Pin Mapping for JTAG_TCLK signal
//   <o> JTAG_TCLK [PTA0]<name=JTAG_TCLK_PIN_SEL>
//   <i> Shows which pin JTAG_TCLK is mapped to
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,JTAG_TCLK/SWD_CLK>
//     <1=> Default
#define JTAG_TCLK_PIN_SEL    1
#if (JTAG_TCLK_PIN_SEL == 1)
#define JTAG_TCLK_GPIO       USBDM::GpioA<0>
#define JTAG_TCLK_FN         7
#endif

// Pin Mapping for JTAG_TDI signal
//   <o> JTAG_TDI [PTA1]<name=JTAG_TDI_PIN_SEL>
//   <i> Shows which pin JTAG_TDI is mapped to
//     <0=> Disabled
//     <1=> PTA1<selection=PTA1_SIG_SEL,JTAG_TDI>
//     <1=> Default
#define JTAG_TDI_PIN_SEL     1
#if (JTAG_TDI_PIN_SEL == 1)
#define JTAG_TDI_GPIO        USBDM::GpioA<1>
#define JTAG_TDI_FN          7
#endif

// Pin Mapping for JTAG_TDO signal
//   <o> JTAG_TDO [PTA2]<name=JTAG_TDO_PIN_SEL>
//   <i> Shows which pin JTAG_TDO is mapped to
//     <0=> Disabled
//     <1=> PTA2<selection=PTA2_SIG_SEL,JTAG_TDO/TRACE_SWO>
//     <1=> Default
#define JTAG_TDO_PIN_SEL     1
#if (JTAG_TDO_PIN_SEL == 1)
#define JTAG_TDO_GPIO        USBDM::GpioA<2>
#define JTAG_TDO_FN          7
#endif

// Pin Mapping for JTAG_TMS signal
//   <o> JTAG_TMS [PTA3]<name=JTAG_TMS_PIN_SEL>
//   <i> Shows which pin JTAG_TMS is mapped to
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,JTAG_TMS/SWD_DIO>
//     <1=> Default
#define JTAG_TMS_PIN_SEL     1
#if (JTAG_TMS_PIN_SEL == 1)
#define JTAG_TMS_GPIO        USBDM::GpioA<3>
#define JTAG_TMS_FN          7
#endif

// Pin Mapping for JTAG_TRST_b signal
//   <o> JTAG_TRST_b [PTA5]<name=JTAG_TRST_b_PIN_SEL>
//   <i> Shows which pin JTAG_TRST_b is mapped to
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,JTAG_TRST_b>
//     <0=> Default
#define JTAG_TRST_b_PIN_SEL  0
#if (JTAG_TRST_b_PIN_SEL == 1)
#define JTAG_TRST_b_GPIO     USBDM::GpioA<5>
#define JTAG_TRST_b_FN       7
#endif

// Pin Mapping for NMI_b signal
//   <o> NMI_b [PTA4]<name=NMI_b_PIN_SEL>
//   <i> Shows which pin NMI_b is mapped to
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,NMI_b>
//     <1=> Default
#define NMI_b_PIN_SEL        1
#if (NMI_b_PIN_SEL == 1)
#define NMI_b_GPIO           USBDM::GpioA<4>
#define NMI_b_FN             7
#endif

// Pin Mapping for SWD_CLK signal
//   <o> SWD_CLK [PTA0]<name=SWD_CLK_PIN_SEL>
//   <i> Shows which pin SWD_CLK is mapped to
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,JTAG_TCLK/SWD_CLK>
//     <1=> Default
#define SWD_CLK_PIN_SEL      1
#if (SWD_CLK_PIN_SEL == 1)
#define SWD_CLK_GPIO         USBDM::GpioA<0>
#define SWD_CLK_FN           7
#endif

// Pin Mapping for SWD_DIO signal
//   <o> SWD_DIO [PTA3]<name=SWD_DIO_PIN_SEL>
//   <i> Shows which pin SWD_DIO is mapped to
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,JTAG_TMS/SWD_DIO>
//     <1=> Default
#define SWD_DIO_PIN_SEL      1
#if (SWD_DIO_PIN_SEL == 1)
#define SWD_DIO_GPIO         USBDM::GpioA<3>
#define SWD_DIO_FN           7
#endif

// Pin Mapping for TRACE_CLKOUT signal
//   <o> TRACE_CLKOUT [PTE0]<name=TRACE_CLKOUT_PIN_SEL>
//   <i> Shows which pin TRACE_CLKOUT is mapped to
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,TRACE_CLKOUT>
//     <0=> Default
#define TRACE_CLKOUT_PIN_SEL 0
#if (TRACE_CLKOUT_PIN_SEL == 1)
#define TRACE_CLKOUT_GPIO    USBDM::GpioE<0>
#define TRACE_CLKOUT_FN      5
#endif

// Pin Mapping for TRACE_D3 signal
//   <o> TRACE_D3 [PTE1]<name=TRACE_D3_PIN_SEL>
//   <i> Shows which pin TRACE_D3 is mapped to
//     <0=> Disabled
//     <1=> PTE1<selection=PTE1_SIG_SEL,TRACE_D3>
//     <0=> Default
#define TRACE_D3_PIN_SEL     0
#if (TRACE_D3_PIN_SEL == 1)
#define TRACE_D3_GPIO        USBDM::GpioE<1>
#define TRACE_D3_FN          5
#endif

// Pin Mapping for TRACE_SWO signal
//   <o> TRACE_SWO [PTA2]<name=TRACE_SWO_PIN_SEL>
//   <i> Shows which pin TRACE_SWO is mapped to
//     <0=> Disabled
//     <1=> PTA2<selection=PTA2_SIG_SEL,JTAG_TDO/TRACE_SWO>
//     <1=> Default
#define TRACE_SWO_PIN_SEL    1
#if (TRACE_SWO_PIN_SEL == 1)
#define TRACE_SWO_GPIO       USBDM::GpioA<2>
#define TRACE_SWO_FN         7
#endif

// </h>

// <h> Low-Leakage Wake-up Unit (LLWU)

// Pin Mapping for LLWU_P0 signal
//   <o> LLWU_P0 [PTE1]<name=LLWU_P0_PIN_SEL>
//   <i> Shows which pin LLWU_P0 is mapped to
//     <0=> Disabled
//     <1=> PTE1 (reset default)<selection=PTE1_SIG_SEL,GPIOE_1/LLWU_P0 (reset default)>
//     <2=> PTE1<selection=PTE1_SIG_SEL,GPIOE_1/LLWU_P0>
//     <0=> Default
#define LLWU_P0_PIN_SEL      0
#if (LLWU_P0_PIN_SEL == 2)
#define LLWU_P0_GPIO         USBDM::GpioE<1>
#define LLWU_P0_FN           1
#endif

// Pin Mapping for LLWU_P3 signal
//   <o> LLWU_P3 [PTA4]<name=LLWU_P3_PIN_SEL>
//   <i> Shows which pin LLWU_P3 is mapped to
//     <0=> Disabled
//     <1=> PTA4 (reset default)<selection=PTA4_SIG_SEL,GPIOA_4/LLWU_P3 (reset default)>
//     <2=> PTA4<selection=PTA4_SIG_SEL,GPIOA_4/LLWU_P3>
//     <0=> Default
#define LLWU_P3_PIN_SEL      0
#if (LLWU_P3_PIN_SEL == 2)
#define LLWU_P3_GPIO         USBDM::GpioA<4>
#define LLWU_P3_FN           1
#endif

// Pin Mapping for LLWU_P4 signal
//   <o> LLWU_P4 [PTA13]<name=LLWU_P4_PIN_SEL>
//   <i> Shows which pin LLWU_P4 is mapped to
//     <0=> Disabled
//     <1=> PTA13 (reset default)<selection=PTA13_SIG_SEL,GPIOA_13/LLWU_P4 (reset default)>
//     <2=> PTA13<selection=PTA13_SIG_SEL,GPIOA_13/LLWU_P4>
//     <0=> Default
#define LLWU_P4_PIN_SEL      0
#if (LLWU_P4_PIN_SEL == 2)
#define LLWU_P4_GPIO         USBDM::GpioA<13>
#define LLWU_P4_FN           1
#endif

// Pin Mapping for LLWU_P5 signal
//   <o> LLWU_P5 [PTB0]<name=LLWU_P5_PIN_SEL>
//   <i> Shows which pin LLWU_P5 is mapped to
//     <0=> Disabled
//     <1=> PTB0 (reset default)<selection=PTB0_SIG_SEL,GPIOB_0/LLWU_P5 (reset default)>
//     <2=> PTB0<selection=PTB0_SIG_SEL,GPIOB_0/LLWU_P5>
//     <0=> Default
#define LLWU_P5_PIN_SEL      0
#if (LLWU_P5_PIN_SEL == 2)
#define LLWU_P5_GPIO         USBDM::GpioB<0>
#define LLWU_P5_FN           1
#endif

// Pin Mapping for LLWU_P6 signal
//   <o> LLWU_P6 [PTC1]<name=LLWU_P6_PIN_SEL>
//   <i> Shows which pin LLWU_P6 is mapped to
//     <0=> Disabled
//     <1=> PTC1 (reset default)<selection=PTC1_SIG_SEL,GPIOC_1/LLWU_P6 (reset default)>
//     <2=> PTC1<selection=PTC1_SIG_SEL,GPIOC_1/LLWU_P6>
//     <0=> Default
#define LLWU_P6_PIN_SEL      0
#if (LLWU_P6_PIN_SEL == 2)
#define LLWU_P6_GPIO         USBDM::GpioC<1>
#define LLWU_P6_FN           1
#endif

// Pin Mapping for LLWU_P7 signal
//   <o> LLWU_P7 [PTC3]<name=LLWU_P7_PIN_SEL>
//   <i> Shows which pin LLWU_P7 is mapped to
//     <0=> Disabled
//     <1=> PTC3 (reset default)<selection=PTC3_SIG_SEL,GPIOC_3/LLWU_P7 (reset default)>
//     <2=> PTC3<selection=PTC3_SIG_SEL,GPIOC_3/LLWU_P7>
//     <0=> Default
#define LLWU_P7_PIN_SEL      0
#if (LLWU_P7_PIN_SEL == 2)
#define LLWU_P7_GPIO         USBDM::GpioC<3>
#define LLWU_P7_FN           1
#endif

// Pin Mapping for LLWU_P8 signal
//   <o> LLWU_P8 [PTC4]<name=LLWU_P8_PIN_SEL>
//   <i> Shows which pin LLWU_P8 is mapped to
//     <0=> Disabled
//     <1=> PTC4 (reset default)<selection=PTC4_SIG_SEL,GPIOC_4/LLWU_P8 (reset default)>
//     <2=> PTC4<selection=PTC4_SIG_SEL,GPIOC_4/LLWU_P8>
//     <1=> Default
#define LLWU_P8_PIN_SEL      1
#if (LLWU_P8_PIN_SEL == 2)
#define LLWU_P8_GPIO         USBDM::GpioC<4>
#define LLWU_P8_FN           1
#endif

// Pin Mapping for LLWU_P9 signal
//   <o> LLWU_P9 [PTC5]<name=LLWU_P9_PIN_SEL>
//   <i> Shows which pin LLWU_P9 is mapped to
//     <0=> Disabled
//     <1=> PTC5 (reset default)<selection=PTC5_SIG_SEL,GPIOC_5/LLWU_P9 (reset default)>
//     <2=> PTC5<selection=PTC5_SIG_SEL,GPIOC_5/LLWU_P9>
//     <1=> Default
#define LLWU_P9_PIN_SEL      1
#if (LLWU_P9_PIN_SEL == 2)
#define LLWU_P9_GPIO         USBDM::GpioC<5>
#define LLWU_P9_FN           1
#endif

// Pin Mapping for LLWU_P10 signal
//   <o> LLWU_P10 [PTC6]<name=LLWU_P10_PIN_SEL>
//   <i> Shows which pin LLWU_P10 is mapped to
//     <0=> Disabled
//     <1=> PTC6 (reset default)<selection=PTC6_SIG_SEL,GPIOC_6/LLWU_P10 (reset default)>
//     <2=> PTC6<selection=PTC6_SIG_SEL,GPIOC_6/LLWU_P10>
//     <0=> Default
#define LLWU_P10_PIN_SEL     0
#if (LLWU_P10_PIN_SEL == 2)
#define LLWU_P10_GPIO        USBDM::GpioC<6>
#define LLWU_P10_FN          1
#endif

// Pin Mapping for LLWU_P11 signal
//   <o> LLWU_P11 [PTC11]<name=LLWU_P11_PIN_SEL>
//   <i> Shows which pin LLWU_P11 is mapped to
//     <0=> Disabled
//     <1=> PTC11 (reset default)<selection=PTC11_SIG_SEL,GPIOC_11/LLWU_P11 (reset default)>
//     <2=> PTC11<selection=PTC11_SIG_SEL,GPIOC_11/LLWU_P11>
//     <0=> Default
#define LLWU_P11_PIN_SEL     0
#if (LLWU_P11_PIN_SEL == 2)
#define LLWU_P11_GPIO        USBDM::GpioC<11>
#define LLWU_P11_FN          1
#endif

// Pin Mapping for LLWU_P12 signal
//   <o> LLWU_P12 [PTD0]<name=LLWU_P12_PIN_SEL>
//   <i> Shows which pin LLWU_P12 is mapped to
//     <0=> Disabled
//     <1=> PTD0 (reset default)<selection=PTD0_SIG_SEL,GPIOD_0/LLWU_P12 (reset default)>
//     <2=> PTD0<selection=PTD0_SIG_SEL,GPIOD_0/LLWU_P12>
//     <1=> Default
#define LLWU_P12_PIN_SEL     1
#if (LLWU_P12_PIN_SEL == 2)
#define LLWU_P12_GPIO        USBDM::GpioD<0>
#define LLWU_P12_FN          1
#endif

// Pin Mapping for LLWU_P13 signal
//   <o> LLWU_P13 [PTD2]<name=LLWU_P13_PIN_SEL>
//   <i> Shows which pin LLWU_P13 is mapped to
//     <0=> Disabled
//     <1=> PTD2 (reset default)<selection=PTD2_SIG_SEL,GPIOD_2/LLWU_P13 (reset default)>
//     <2=> PTD2<selection=PTD2_SIG_SEL,GPIOD_2/LLWU_P13>
//     <1=> Default
#define LLWU_P13_PIN_SEL     1
#if (LLWU_P13_PIN_SEL == 2)
#define LLWU_P13_GPIO        USBDM::GpioD<2>
#define LLWU_P13_FN          1
#endif

// Pin Mapping for LLWU_P14 signal
//   <o> LLWU_P14 [PTD4]<name=LLWU_P14_PIN_SEL>
//   <i> Shows which pin LLWU_P14 is mapped to
//     <0=> Disabled
//     <1=> PTD4 (reset default)<selection=PTD4_SIG_SEL,GPIOD_4/LLWU_P14 (reset default)>
//     <2=> PTD4<selection=PTD4_SIG_SEL,GPIOD_4/LLWU_P14>
//     <1=> Default
#define LLWU_P14_PIN_SEL     1
#if (LLWU_P14_PIN_SEL == 2)
#define LLWU_P14_GPIO        USBDM::GpioD<4>
#define LLWU_P14_FN          1
#endif

// Pin Mapping for LLWU_P15 signal
//   <o> LLWU_P15 [PTD6]<name=LLWU_P15_PIN_SEL>
//   <i> Shows which pin LLWU_P15 is mapped to
//     <0=> Disabled
//     <1=> PTD6 (reset default)<selection=PTD6_SIG_SEL,GPIOD_6/LLWU_P15 (reset default)>
//     <2=> PTD6<selection=PTD6_SIG_SEL,GPIOD_6/LLWU_P15>
//     <0=> Default
#define LLWU_P15_PIN_SEL     0
#if (LLWU_P15_PIN_SEL == 2)
#define LLWU_P15_GPIO        USBDM::GpioD<6>
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
#if (LPTMR0_ALT1_PIN_SEL == 1)
#define LPTMR0_ALT1_GPIO     USBDM::GpioA<19>
#define LPTMR0_ALT1_FN       6
#endif

// Pin Mapping for LPTMR0_ALT2 signal
//   <o> LPTMR0_ALT2 [PTC5]<name=LPTMR0_ALT2_PIN_SEL>
//   <i> Shows which pin LPTMR0_ALT2 is mapped to
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,LPTMR0_ALT2>
//     <0=> Default
#define LPTMR0_ALT2_PIN_SEL  0
#if (LPTMR0_ALT2_PIN_SEL == 1)
#define LPTMR0_ALT2_GPIO     USBDM::GpioC<5>
#define LPTMR0_ALT2_FN       3
#endif

// </h>

// <h> Programmable Delay Block (PDB0)

// Pin Mapping for PDB0_EXTRG signal
//   <o> PDB0_EXTRG [PTC0, PTC6]<name=PDB0_EXTRG_PIN_SEL>
//   <i> Shows which pin PDB0_EXTRG is mapped to
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,PDB0_EXTRG>
//     <2=> PTC6<selection=PTC6_SIG_SEL,PDB0_EXTRG>
//     <0=> Default
#define PDB0_EXTRG_PIN_SEL   0
#if (PDB0_EXTRG_PIN_SEL == 1)
#define PDB0_EXTRG_GPIO      USBDM::GpioC<0>
#define PDB0_EXTRG_FN        3
#elif (PDB0_EXTRG_PIN_SEL == 2)
#define PDB0_EXTRG_GPIO      USBDM::GpioC<6>
#define PDB0_EXTRG_FN        3
#endif

// </h>

// <h> Serial Peripheral Interface (SPI0)

// Pin Mapping for SPI0_PCS0 signal
//   <o> SPI0_PCS0 [PTC4, PTD0]<name=SPI0_PCS0_PIN_SEL>
//   <i> Shows which pin SPI0_PCS0 is mapped to
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,SPI0_PCS0>
//     <2=> PTD0<selection=PTD0_SIG_SEL,SPI0_PCS0>
//     <0=> Default
#define SPI0_PCS0_PIN_SEL    0

// Pin Mapping for SPI0_PCS1 signal
//   <o> SPI0_PCS1 [PTC3, PTD4]<name=SPI0_PCS1_PIN_SEL>
//   <i> Shows which pin SPI0_PCS1 is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,SPI0_PCS1>
//     <2=> PTD4<selection=PTD4_SIG_SEL,SPI0_PCS1>
//     <0=> Default
#define SPI0_PCS1_PIN_SEL    0

// Pin Mapping for SPI0_PCS2 signal
//   <o> SPI0_PCS2 [PTC2, PTD5]<name=SPI0_PCS2_PIN_SEL>
//   <i> Shows which pin SPI0_PCS2 is mapped to
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,SPI0_PCS2>
//     <2=> PTD5<selection=PTD5_SIG_SEL,SPI0_PCS2>
//     <0=> Default
#define SPI0_PCS2_PIN_SEL    0

// Pin Mapping for SPI0_PCS3 signal
//   <o> SPI0_PCS3 [PTC1, PTD6]<name=SPI0_PCS3_PIN_SEL>
//   <i> Shows which pin SPI0_PCS3 is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,SPI0_PCS3>
//     <2=> PTD6<selection=PTD6_SIG_SEL,SPI0_PCS3>
//     <0=> Default
#define SPI0_PCS3_PIN_SEL    0

// Pin Mapping for SPI0_PCS4 signal
//   <o> SPI0_PCS4 [PTC0]<name=SPI0_PCS4_PIN_SEL>
//   <i> Shows which pin SPI0_PCS4 is mapped to
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,SPI0_PCS4>
//     <0=> Default
#define SPI0_PCS4_PIN_SEL    0

// Pin Mapping for SPI0_SCK signal
//   <o> SPI0_SCK [PTC5, PTD1]<name=SPI0_SCK_PIN_SEL>
//   <i> Shows which pin SPI0_SCK is mapped to
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,SPI0_SCK>
//     <2=> PTD1<selection=PTD1_SIG_SEL,SPI0_SCK>
//     <0=> Default
#define SPI0_SCK_PIN_SEL     0

// Pin Mapping for SPI0_SIN signal
//   <o> SPI0_SIN [PTC7, PTD3]<name=SPI0_SIN_PIN_SEL>
//   <i> Shows which pin SPI0_SIN is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,SPI0_SIN>
//     <2=> PTD3<selection=PTD3_SIG_SEL,SPI0_SIN>
//     <0=> Default
#define SPI0_SIN_PIN_SEL     0

// Pin Mapping for SPI0_SOUT signal
//   <o> SPI0_SOUT [PTC6, PTD2]<name=SPI0_SOUT_PIN_SEL>
//   <i> Shows which pin SPI0_SOUT is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,SPI0_SOUT>
//     <2=> PTD2<selection=PTD2_SIG_SEL,SPI0_SOUT>
//     <0=> Default
#define SPI0_SOUT_PIN_SEL    0

// </h>

// <h> Universal Asynchronous Rx/Tx (UART0)

// Pin Mapping for UART0_CTS_b signal
//   <o> UART0_CTS_b [PTA0, PTB3, PTD5]<name=UART0_CTS_b_PIN_SEL>
//   <i> Shows which pin UART0_CTS_b is mapped to
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,UART0_CTS_b>
//     <2=> PTB3<selection=PTB3_SIG_SEL,UART0_CTS_b>
//     <3=> PTD5<selection=PTD5_SIG_SEL,UART0_CTS_b>
//     <0=> Default
#define UART0_CTS_b_PIN_SEL  0
#if (UART0_CTS_b_PIN_SEL == 1)
#define UART0_CTS_b_GPIO     USBDM::GpioA<0>
#define UART0_CTS_b_FN       2
#elif (UART0_CTS_b_PIN_SEL == 2)
#define UART0_CTS_b_GPIO     USBDM::GpioB<3>
#define UART0_CTS_b_FN       3
#elif (UART0_CTS_b_PIN_SEL == 3)
#define UART0_CTS_b_GPIO     USBDM::GpioD<5>
#define UART0_CTS_b_FN       3
#endif

// Pin Mapping for UART0_RTS_b signal
//   <o> UART0_RTS_b [PTA3, PTB2, PTD4]<name=UART0_RTS_b_PIN_SEL>
//   <i> Shows which pin UART0_RTS_b is mapped to
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,UART0_RTS_b>
//     <2=> PTB2<selection=PTB2_SIG_SEL,UART0_RTS_b>
//     <3=> PTD4<selection=PTD4_SIG_SEL,UART0_RTS_b>
//     <0=> Default
#define UART0_RTS_b_PIN_SEL  0
#if (UART0_RTS_b_PIN_SEL == 1)
#define UART0_RTS_b_GPIO     USBDM::GpioA<3>
#define UART0_RTS_b_FN       2
#elif (UART0_RTS_b_PIN_SEL == 2)
#define UART0_RTS_b_GPIO     USBDM::GpioB<2>
#define UART0_RTS_b_FN       3
#elif (UART0_RTS_b_PIN_SEL == 3)
#define UART0_RTS_b_GPIO     USBDM::GpioD<4>
#define UART0_RTS_b_FN       3
#endif

// Pin Mapping for UART0_RX signal
//   <o> UART0_RX [PTA1, PTB16, PTD6]<name=UART0_RX_PIN_SEL>
//   <i> Shows which pin UART0_RX is mapped to
//     <0=> Disabled
//     <1=> PTA1<selection=PTA1_SIG_SEL,UART0_RX>
//     <2=> PTB16<selection=PTB16_SIG_SEL,UART0_RX>
//     <3=> PTD6<selection=PTD6_SIG_SEL,UART0_RX>
//     <0=> Default
#define UART0_RX_PIN_SEL     0
#if (UART0_RX_PIN_SEL == 1)
#define UART0_RX_GPIO        USBDM::GpioA<1>
#define UART0_RX_FN          2
#elif (UART0_RX_PIN_SEL == 2)
#define UART0_RX_GPIO        USBDM::GpioB<16>
#define UART0_RX_FN          3
#elif (UART0_RX_PIN_SEL == 3)
#define UART0_RX_GPIO        USBDM::GpioD<6>
#define UART0_RX_FN          3
#endif

// Pin Mapping for UART0_TX signal
//   <o> UART0_TX [PTA2, PTB17, PTD7]<name=UART0_TX_PIN_SEL>
//   <i> Shows which pin UART0_TX is mapped to
//     <0=> Disabled
//     <1=> PTA2<selection=PTA2_SIG_SEL,UART0_TX>
//     <2=> PTB17<selection=PTB17_SIG_SEL,UART0_TX>
//     <3=> PTD7<selection=PTD7_SIG_SEL,UART0_TX>
//     <0=> Default
#define UART0_TX_PIN_SEL     0
#if (UART0_TX_PIN_SEL == 1)
#define UART0_TX_GPIO        USBDM::GpioA<2>
#define UART0_TX_FN          2
#elif (UART0_TX_PIN_SEL == 2)
#define UART0_TX_GPIO        USBDM::GpioB<17>
#define UART0_TX_FN          3
#elif (UART0_TX_PIN_SEL == 3)
#define UART0_TX_GPIO        USBDM::GpioD<7>
#define UART0_TX_FN          3
#endif

// </h>

// <h> Universal Asynchronous Rx/Tx (UART1)

// Pin Mapping for UART1_CTS_b signal
//   <o> UART1_CTS_b [PTC2]<name=UART1_CTS_b_PIN_SEL>
//   <i> Shows which pin UART1_CTS_b is mapped to
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,UART1_CTS_b>
//     <0=> Default
#define UART1_CTS_b_PIN_SEL  0
#if (UART1_CTS_b_PIN_SEL == 1)
#define UART1_CTS_b_GPIO     USBDM::GpioC<2>
#define UART1_CTS_b_FN       3
#endif

// Pin Mapping for UART1_RTS_b signal
//   <o> UART1_RTS_b [PTC1]<name=UART1_RTS_b_PIN_SEL>
//   <i> Shows which pin UART1_RTS_b is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,UART1_RTS_b>
//     <0=> Default
#define UART1_RTS_b_PIN_SEL  0
#if (UART1_RTS_b_PIN_SEL == 1)
#define UART1_RTS_b_GPIO     USBDM::GpioC<1>
#define UART1_RTS_b_FN       3
#endif

// Pin Mapping for UART1_RX signal
//   <o> UART1_RX [PTC3, PTE1]<name=UART1_RX_PIN_SEL>
//   <i> Shows which pin UART1_RX is mapped to
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,UART1_RX>
//     <2=> PTE1<selection=PTE1_SIG_SEL,UART1_RX>
//     <0=> Default
#define UART1_RX_PIN_SEL     0
#if (UART1_RX_PIN_SEL == 1)
#define UART1_RX_GPIO        USBDM::GpioC<3>
#define UART1_RX_FN          3
#elif (UART1_RX_PIN_SEL == 2)
#define UART1_RX_GPIO        USBDM::GpioE<1>
#define UART1_RX_FN          3
#endif

// Pin Mapping for UART1_TX signal
//   <o> UART1_TX [PTC4, PTE0]<name=UART1_TX_PIN_SEL>
//   <i> Shows which pin UART1_TX is mapped to
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,UART1_TX>
//     <2=> PTE0<selection=PTE0_SIG_SEL,UART1_TX>
//     <0=> Default
#define UART1_TX_PIN_SEL     0
#if (UART1_TX_PIN_SEL == 1)
#define UART1_TX_GPIO        USBDM::GpioC<4>
#define UART1_TX_FN          3
#elif (UART1_TX_PIN_SEL == 2)
#define UART1_TX_GPIO        USBDM::GpioE<0>
#define UART1_TX_FN          3
#endif

// </h>

// <h> Universal Asynchronous Rx/Tx (UART2)

// Pin Mapping for UART2_CTS_b signal
//   <o> UART2_CTS_b [PTD1]<name=UART2_CTS_b_PIN_SEL>
//   <i> Shows which pin UART2_CTS_b is mapped to
//     <0=> Disabled
//     <1=> PTD1<selection=PTD1_SIG_SEL,UART2_CTS_b>
//     <0=> Default
#define UART2_CTS_b_PIN_SEL  0
#if (UART2_CTS_b_PIN_SEL == 1)
#define UART2_CTS_b_GPIO     USBDM::GpioD<1>
#define UART2_CTS_b_FN       3
#endif

// Pin Mapping for UART2_RTS_b signal
//   <o> UART2_RTS_b [PTD0]<name=UART2_RTS_b_PIN_SEL>
//   <i> Shows which pin UART2_RTS_b is mapped to
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,UART2_RTS_b>
//     <0=> Default
#define UART2_RTS_b_PIN_SEL  0
#if (UART2_RTS_b_PIN_SEL == 1)
#define UART2_RTS_b_GPIO     USBDM::GpioD<0>
#define UART2_RTS_b_FN       3
#endif

// Pin Mapping for UART2_RX signal
//   <o> UART2_RX [PTD2]<name=UART2_RX_PIN_SEL>
//   <i> Shows which pin UART2_RX is mapped to
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,UART2_RX>
//     <0=> Default
#define UART2_RX_PIN_SEL     0
#if (UART2_RX_PIN_SEL == 1)
#define UART2_RX_GPIO        USBDM::GpioD<2>
#define UART2_RX_FN          3
#endif

// Pin Mapping for UART2_TX signal
//   <o> UART2_TX [PTD3]<name=UART2_TX_PIN_SEL>
//   <i> Shows which pin UART2_TX is mapped to
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,UART2_TX>
//     <0=> Default
#define UART2_TX_PIN_SEL     0
#if (UART2_TX_PIN_SEL == 1)
#define UART2_TX_GPIO        USBDM::GpioD<3>
#define UART2_TX_FN          3
#endif

// </h>

// <h> Universal Serial Bus

// Pin Mapping for USB_CLKIN signal
//   <o> USB_CLKIN [PTA5]<name=USB_CLKIN_PIN_SEL>
//   <i> Shows which pin USB_CLKIN is mapped to
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,USB_CLKIN>
//     <0=> Default
#define USB_CLKIN_PIN_SEL    0
#if (USB_CLKIN_PIN_SEL == 1)
#define USB_CLKIN_GPIO       USBDM::GpioA<5>
#define USB_CLKIN_FN         2
#endif

// Pin Mapping for USB_SOF_OUT signal
//   <o> USB_SOF_OUT [PTC7]<name=USB_SOF_OUT_PIN_SEL>
//   <i> Shows which pin USB_SOF_OUT is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,USB_SOF_OUT>
//     <0=> Default
#define USB_SOF_OUT_PIN_SEL  0
#if (USB_SOF_OUT_PIN_SEL == 1)
#define USB_SOF_OUT_GPIO     USBDM::GpioC<7>
#define USB_SOF_OUT_FN       3
#endif

// </h>

// <h> Voltage Reference (VREF)

// Pin Mapping for VREF_OUT signal
//   <o> VREF_OUT [ADC1_SE18]<name=VREF_OUT_PIN_SEL><constant>
//   <i> Shows which pin VREF_OUT is mapped to
//     <0=> ADC1_SE18<selection=ADC1_SE18_SIG_SEL,VREF_OUT/CMP1_IN5/CMP0_IN5/ADC1_SE18>
//     <0=> Default
#define VREF_OUT_PIN_SEL     0
#define VREF_OUT_GPIO        0
#define VREF_OUT_FN          0

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
#define ADC1_CLOCK_REG       SCGC3
#define ADC1_CLOCK_MASK      SIM_SCGC3_ADC1_MASK
#define CMP_CLOCK_REG        SCGC4
#define CMP_CLOCK_MASK       SIM_SCGC4_CMP_MASK
#define CMT_CLOCK_REG        SCGC4
#define CMT_CLOCK_MASK       SIM_SCGC4_CMT_MASK
#define CRC_CLOCK_REG        SCGC6
#define CRC_CLOCK_MASK       SIM_SCGC6_CRC_MASK
#define DAC0_CLOCK_REG       SCGC6
#define DAC0_CLOCK_MASK      SIM_SCGC6_DAC0_MASK
#define DMA_CLOCK_REG        SCGC7
#define DMA_CLOCK_MASK       SIM_SCGC7_DMA_MASK
#define DMAMUX_CLOCK_REG     SCGC6
#define DMAMUX_CLOCK_MASK    SIM_SCGC6_DMAMUX_MASK
#define EWM_CLOCK_REG        SCGC4
#define EWM_CLOCK_MASK       SIM_SCGC4_EWM_MASK
#define FLEXBUS_CLOCK_REG    SCGC7
#define FLEXBUS_CLOCK_MASK   SIM_SCGC7_FLEXBUS_MASK
#define FLEXCAN0_CLOCK_REG   SCGC6
#define FLEXCAN0_CLOCK_MASK  SIM_SCGC6_FLEXCAN0_MASK
#define FTM0_CLOCK_REG       SCGC6
#define FTM0_CLOCK_MASK      SIM_SCGC6_FTM0_MASK
#define FTM1_CLOCK_REG       SCGC6
#define FTM1_CLOCK_MASK      SIM_SCGC6_FTM1_MASK
#define FTM2_CLOCK_REG       SCGC6
#define FTM2_CLOCK_MASK      SIM_SCGC6_FTM2_MASK
#define FTM3_CLOCK_REG       SCGC3
#define FTM3_CLOCK_MASK      SIM_SCGC3_FTM3_MASK
#define I2C0_CLOCK_REG       SCGC4
#define I2C0_CLOCK_MASK      SIM_SCGC4_I2C0_MASK
#define I2C1_CLOCK_REG       SCGC4
#define I2C1_CLOCK_MASK      SIM_SCGC4_I2C1_MASK
#define I2C2_CLOCK_REG       SCGC1
#define I2C2_CLOCK_MASK      SIM_SCGC1_I2C2_MASK
#define I2S0_CLOCK_REG       SCGC6
#define I2S0_CLOCK_MASK      SIM_SCGC6_I2S0_MASK
#define LPTMR0_CLOCK_REG     SCGC5
#define LPTMR0_CLOCK_MASK    SIM_SCGC5_LPTMR_MASK
#define MPU_CLOCK_REG        SCGC7
#define MPU_CLOCK_MASK       SIM_SCGC7_MPU_MASK
#define PDB0_CLOCK_REG       SCGC6
#define PDB0_CLOCK_MASK      SIM_SCGC6_PDB0_MASK
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
#define SPI0_CLOCK_REG       SCGC6
#define SPI0_CLOCK_MASK      SIM_SCGC6_SPI0_MASK
#define UART0_CLOCK_REG      SCGC4
#define UART0_CLOCK_MASK     SIM_SCGC4_UART0_MASK
#define UART1_CLOCK_REG      SCGC4
#define UART1_CLOCK_MASK     SIM_SCGC4_UART1_MASK
#define UART2_CLOCK_REG      SCGC4
#define UART2_CLOCK_MASK     SIM_SCGC4_UART2_MASK
#define USBDCD_CLOCK_REG     SCGC6
#define USBDCD_CLOCK_MASK    SIM_SCGC6_USBDCD_MASK
#define USBOTG_CLOCK_REG     SCGC4
#define USBOTG_CLOCK_MASK    SIM_SCGC4_USBOTG_MASK
#define VREF_CLOCK_REG       SCGC4
#define VREF_CLOCK_MASK      SIM_SCGC4_VREF_MASK
#define PORT_CLOCK_REG       SCGC5

/*
Clock Information Summary
ADC0       SCGC6        SIM_SCGC6_ADC0_MASK
ADC1       SCGC3        SIM_SCGC3_ADC1_MASK
CMP        SCGC4        SIM_SCGC4_CMP_MASK
CMT        SCGC4        SIM_SCGC4_CMT_MASK
CRC        SCGC6        SIM_SCGC6_CRC_MASK
DAC0       SCGC6        SIM_SCGC6_DAC0_MASK
DMA        SCGC7        SIM_SCGC7_DMA_MASK
DMAMUX     SCGC6        SIM_SCGC6_DMAMUX_MASK
EWM        SCGC4        SIM_SCGC4_EWM_MASK
FLEXBUS    SCGC7        SIM_SCGC7_FLEXBUS_MASK
FLEXCAN0   SCGC6        SIM_SCGC6_FLEXCAN0_MASK
FTM0       SCGC6        SIM_SCGC6_FTM0_MASK
FTM1       SCGC6        SIM_SCGC6_FTM1_MASK
FTM2       SCGC6        SIM_SCGC6_FTM2_MASK
FTM3       SCGC3        SIM_SCGC3_FTM3_MASK
I2C0       SCGC4        SIM_SCGC4_I2C0_MASK
I2C1       SCGC4        SIM_SCGC4_I2C1_MASK
I2C2       SCGC1        SIM_SCGC1_I2C2_MASK
I2S0       SCGC6        SIM_SCGC6_I2S0_MASK
LPTMR0     SCGC5        SIM_SCGC5_LPTMR_MASK
MPU        SCGC7        SIM_SCGC7_MPU_MASK
PDB0       SCGC6        SIM_SCGC6_PDB0_MASK
PIT        SCGC6        SIM_SCGC6_PIT_MASK
PORTA      SCGC5        SIM_SCGC5_PORTA_MASK
PORTB      SCGC5        SIM_SCGC5_PORTB_MASK
PORTC      SCGC5        SIM_SCGC5_PORTC_MASK
PORTD      SCGC5        SIM_SCGC5_PORTD_MASK
PORTE      SCGC5        SIM_SCGC5_PORTE_MASK
RTC        SCGC6        SIM_SCGC6_RTC_MASK
SPI0       SCGC6        SIM_SCGC6_SPI0_MASK
UART0      SCGC4        SIM_SCGC4_UART0_MASK
UART1      SCGC4        SIM_SCGC4_UART1_MASK
UART2      SCGC4        SIM_SCGC4_UART2_MASK
USBDCD     SCGC6        SIM_SCGC6_USBDCD_MASK
USBOTG     SCGC4        SIM_SCGC4_USBOTG_MASK
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
 /*  0 */  { 0 },
 /*  1 */  { 0 },
 /*  2 */  { 0 },
 /*  3 */  { 0 },
#if (ADC0_SE4b_PIN_SEL == 1)
 /*  4 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  GPIOC_BasePtr,  2,  0 },
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
 /* 11 */  { 0 },
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
 /* 23 */  { 0 },
};

/**
 * Peripheral pin mapping information for Analogue Input
 */
constexpr PcrInfo Adc1Info[32] = {
 //          clockMask pcrAddress gpioAddress gpioBit muxValue
 /*  0 */  { 0 },
 /*  1 */  { 0 },
 /*  2 */  { 0 },
 /*  3 */  { 0 },
#if (ADC1_SE4b_PIN_SEL == 1)
 /*  4 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[8]),  GPIOC_BasePtr,  8,  0 },
#else
 /*  4 */  { 0 },
#endif
#if (ADC1_SE5b_PIN_SEL == 1)
 /*  5 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[9]),  GPIOC_BasePtr,  9,  0 },
#else
 /*  5 */  { 0 },
#endif
#if (ADC1_SE6b_PIN_SEL == 1)
 /*  6 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[10]), GPIOC_BasePtr,  10, 0 },
#else
 /*  6 */  { 0 },
#endif
#if (ADC1_SE7b_PIN_SEL == 1)
 /*  7 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[11]), GPIOC_BasePtr,  11, 0 },
#else
 /*  7 */  { 0 },
#endif
#if (ADC1_SE8_PIN_SEL == 1)
 /*  8 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOB_BasePtr,  0,  0 },
#else
 /*  8 */  { 0 },
#endif
#if (ADC1_SE9_PIN_SEL == 1)
 /*  9 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOB_BasePtr,  1,  0 },
#else
 /*  9 */  { 0 },
#endif
 /* 10 */  { 0 },
 /* 11 */  { 0 },
 /* 12 */  { 0 },
 /* 13 */  { 0 },
 /* 14 */  { 0 },
 /* 15 */  { 0 },
 /* 16 */  { 0 },
 /* 17 */  { 0 },
 /* 18 */  { 0 },
};

/**
 * Peripheral pin mapping information for Analogue Input
 */
constexpr PcrInfo Adc1aInfo[32] = {
 //          clockMask pcrAddress gpioAddress gpioBit muxValue
 /*  0 */  { 0 },
 /*  1 */  { 0 },
 /*  2 */  { 0 },
 /*  3 */  { 0 },
#if (ADC1_SE4a_PIN_SEL == 1)
 /*  4 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOE_BasePtr,  0,  0 },
#else
 /*  4 */  { 0 },
#endif
#if (ADC1_SE5a_PIN_SEL == 1)
 /*  5 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOE_BasePtr,  1,  0 },
#else
 /*  5 */  { 0 },
#endif
};

/**
 * Peripheral pin mapping information for PWM, Input capture, Output compare
 */
constexpr PcrInfo Ftm0Info[32] = {
 //          clockMask pcrAddress gpioAddress gpioBit muxValue
#if (FTM0_CH0_PIN_SEL == 1)
 /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[3]),  GPIOA_BasePtr,  3,  3 },
#elif (FTM0_CH0_PIN_SEL == 2)
 /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOC_BasePtr,  1,  4 },
#else
 /*  0 */  { 0 },
#endif
#if (FTM0_CH1_PIN_SEL == 1)
 /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[4]),  GPIOA_BasePtr,  4,  3 },
#elif (FTM0_CH1_PIN_SEL == 2)
 /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  GPIOC_BasePtr,  2,  4 },
#else
 /*  1 */  { 0 },
#endif
#if (FTM0_CH2_PIN_SEL == 1)
 /*  2 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[5]),  GPIOA_BasePtr,  5,  3 },
#elif (FTM0_CH2_PIN_SEL == 2)
 /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),  GPIOC_BasePtr,  3,  4 },
#elif (FTM0_CH2_PIN_SEL == 3)
 /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[5]),  GPIOC_BasePtr,  5,  7 },
#else
 /*  2 */  { 0 },
#endif
#if (FTM0_CH3_PIN_SEL == 1)
 /*  3 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),  GPIOC_BasePtr,  4,  4 },
#else
 /*  3 */  { 0 },
#endif
#if (FTM0_CH4_PIN_SEL == 1)
 /*  4 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),  GPIOD_BasePtr,  4,  4 },
#else
 /*  4 */  { 0 },
#endif
#if (FTM0_CH5_PIN_SEL == 1)
 /*  5 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOA_BasePtr,  0,  3 },
#elif (FTM0_CH5_PIN_SEL == 2)
 /*  5 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  GPIOD_BasePtr,  5,  4 },
#else
 /*  5 */  { 0 },
#endif
#if (FTM0_CH6_PIN_SEL == 1)
 /*  6 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOA_BasePtr,  1,  3 },
#elif (FTM0_CH6_PIN_SEL == 2)
 /*  6 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),  GPIOD_BasePtr,  6,  4 },
#else
 /*  6 */  { 0 },
#endif
#if (FTM0_CH7_PIN_SEL == 1)
 /*  7 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[2]),  GPIOA_BasePtr,  2,  3 },
#elif (FTM0_CH7_PIN_SEL == 2)
 /*  7 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[7]),  GPIOD_BasePtr,  7,  4 },
#else
 /*  7 */  { 0 },
#endif
};

/**
 * Peripheral pin mapping information for PWM, Input capture, Output compare
 */
constexpr PcrInfo Ftm1Info[32] = {
 //          clockMask pcrAddress gpioAddress gpioBit muxValue
#if (FTM1_CH0_PIN_SEL == 1)
 /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]), GPIOA_BasePtr,  12, 3 },
#elif (FTM1_CH0_PIN_SEL == 2)
 /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOB_BasePtr,  0,  3 },
#else
 /*  0 */  { 0 },
#endif
#if (FTM1_CH1_PIN_SEL == 1)
 /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]), GPIOA_BasePtr,  13, 3 },
#elif (FTM1_CH1_PIN_SEL == 2)
 /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOB_BasePtr,  1,  3 },
#else
 /*  1 */  { 0 },
#endif
};

/**
 * Peripheral pin mapping information for PWM, Input capture, Output compare
 */
constexpr PcrInfo Ftm2Info[32] = {
 //          clockMask pcrAddress gpioAddress gpioBit muxValue
#if (FTM2_CH0_PIN_SEL == 1)
 /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[18]), GPIOB_BasePtr,  18, 3 },
#else
 /*  0 */  { 0 },
#endif
#if (FTM2_CH1_PIN_SEL == 1)
 /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[19]), GPIOB_BasePtr,  19, 3 },
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
#else
 /*  0 */  { 0 },
#endif
#if (SPI0_SIN_PIN_SEL == 1)
 /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[7]),  GPIOC_BasePtr,  7,  2 },
#elif (SPI0_SIN_PIN_SEL == 2)
 /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[3]),  GPIOD_BasePtr,  3,  2 },
#else
 /*  1 */  { 0 },
#endif
#if (SPI0_SOUT_PIN_SEL == 1)
 /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[6]),  GPIOC_BasePtr,  6,  2 },
#elif (SPI0_SOUT_PIN_SEL == 2)
 /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[2]),  GPIOD_BasePtr,  2,  2 },
#else
 /*  2 */  { 0 },
#endif
#if (SPI0_PCS0_PIN_SEL == 1)
 /*  3 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[4]),  GPIOC_BasePtr,  4,  2 },
#elif (SPI0_PCS0_PIN_SEL == 2)
 /*  3 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOD_BasePtr,  0,  2 },
#else
 /*  3 */  { 0 },
#endif
#if (SPI0_PCS1_PIN_SEL == 1)
 /*  4 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[3]),  GPIOC_BasePtr,  3,  2 },
#elif (SPI0_PCS1_PIN_SEL == 2)
 /*  4 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[4]),  GPIOD_BasePtr,  4,  2 },
#else
 /*  4 */  { 0 },
#endif
#if (SPI0_PCS2_PIN_SEL == 1)
 /*  5 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[2]),  GPIOC_BasePtr,  2,  2 },
#elif (SPI0_PCS2_PIN_SEL == 2)
 /*  5 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[5]),  GPIOD_BasePtr,  5,  2 },
#else
 /*  5 */  { 0 },
#endif
#if (SPI0_PCS3_PIN_SEL == 1)
 /*  6 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOC_BasePtr,  1,  2 },
#elif (SPI0_PCS3_PIN_SEL == 2)
 /*  6 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[6]),  GPIOD_BasePtr,  6,  2 },
#else
 /*  6 */  { 0 },
#endif
#if (SPI0_PCS4_PIN_SEL == 1)
 /*  7 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOC_BasePtr,  0,  2 },
#else
 /*  7 */  { 0 },
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
 /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[2]),  GPIOD_BasePtr,  2,  7 },
#else
 /*  0 */  { 0 },
#endif
#if (I2C0_SDA_PIN_SEL == 1)
 /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOB_BasePtr,  1,  2 },
#elif (I2C0_SDA_PIN_SEL == 2)
 /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr+offsetof(PORT_Type,PCR[3]),  GPIOB_BasePtr,  3,  2 },
#elif (I2C0_SDA_PIN_SEL == 3)
 /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr+offsetof(PORT_Type,PCR[3]),  GPIOD_BasePtr,  3,  7 },
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
 /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[10]), GPIOC_BasePtr,  10, 2 },
#elif (I2C1_SCL_PIN_SEL == 2)
 /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[1]),  GPIOE_BasePtr,  1,  6 },
#else
 /*  0 */  { 0 },
#endif
#if (I2C1_SDA_PIN_SEL == 1)
 /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr+offsetof(PORT_Type,PCR[11]), GPIOC_BasePtr,  11, 2 },
#elif (I2C1_SDA_PIN_SEL == 2)
 /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr+offsetof(PORT_Type,PCR[0]),  GPIOE_BasePtr,  0,  6 },
#else
 /*  1 */  { 0 },
#endif
};

/**
 * Peripheral pin mapping information for I2C, Inter-Integrated-Circuit Interface
 */
constexpr PcrInfo I2c2Info[32] = {
 //          clockMask pcrAddress gpioAddress gpioBit muxValue
#if (I2C2_SCL_PIN_SEL == 1)
 /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[12]), GPIOA_BasePtr,  12, 5 },
#else
 /*  0 */  { 0 },
#endif
#if (I2C2_SDA_PIN_SEL == 1)
 /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr+offsetof(PORT_Type,PCR[13]), GPIOA_BasePtr,  13, 5 },
#else
 /*  1 */  { 0 },
#endif
};

/**
 * @}
 ** PeripheralPinTables
 */

} // End namespace USBDM

#endif /* PIN_MAPPING_H_ */