/**
 * @file      pin_mapping.h (derived from pin_mapping-MK64F12.h)
 * @version   1.1.0
 * @brief     Pin declarations for MK64F12
 */

#ifndef PIN_MAPPING_H_
#define PIN_MAPPING_H_

#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

//================================
// Validators
// <validate=net.sourceforge.usbdm.annotationEditor.validators.PinMappingValidator>

// <h> Clock settings for FTM

// FTM_SC.CLKS ================================
//
//   <o> FTM_SC.CLKS Clock source
//   <i> Selects the clock source for the FTM module. [FTM_SC.CLKS]
//     <0=> Disabled
//     <1=> System clock
//     <2=> Fixed frequency clock
//     <3=> External clock
//     <1=> Default
// FTM_SC.PS ================================
//
//   <o1> FTM_SC.PS Clock prescaler
//   <i> Selects the prescaler for the FTM module. [FTM_SC.PS]
//     <0=> Divide by 1
//     <1=> Divide by 2
//     <2=> Divide by 4
//     <3=> Divide by 8
//     <4=> Divide by 16
//     <5=> Divide by 32
//     <6=> Divide by 64
//     <7=> Divide by 128
//     <0=> Default
#define FTM_SC               (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0))

// </h>

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
#define FTM2_SC              (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0))

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
#define FTM3_SC              (FTM_SC_CLKS(0x1)|FTM_SC_PS(0x0))

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

// <h> Miscellaneous Pins

// Signal mapping for ADC0_DM0 pin
//   <o> ADC0_DM0 [ADC0_DM0/ADC1_DM3/ADC0_SE19]<name=ADC0_DM0_SIG_SEL><constant>
//   <i> ADC0_DM0 has no pin-mapping hardware
//     <-3=> ADC0_DM0/ADC1_DM3/ADC0_SE19 (fixed)<selection=ADC0_DM0_PIN_SEL,ADC0_DM0><selection=ADC1_DM3_PIN_SEL,ADC0_DM0><selection=ADC0_SE19_PIN_SEL,ADC0_DM0>
#define ADC0_DM0_SIG_SEL     -3

// Signal mapping for ADC0_DM1 pin
//   <o> ADC0_DM1 [ADC0_DM1/ADC0_SE20]<name=ADC0_DM1_SIG_SEL><constant>
//   <i> ADC0_DM1 has no pin-mapping hardware
//     <-3=> ADC0_DM1/ADC0_SE20 (fixed)<selection=ADC0_DM1_PIN_SEL,ADC0_DM1><selection=ADC0_SE20_PIN_SEL,ADC0_DM1>
#define ADC0_DM1_SIG_SEL     -3

// Signal mapping for ADC0_DP0 pin
//   <o> ADC0_DP0 [ADC0_DP0/ADC1_DP3/ADC0_SE0]<name=ADC0_DP0_SIG_SEL><constant>
//   <i> ADC0_DP0 has no pin-mapping hardware
//     <-3=> ADC0_DP0/ADC1_DP3/ADC0_SE0 (fixed)<selection=ADC0_DP0_PIN_SEL,ADC0_DP0><selection=ADC1_DP3_PIN_SEL,ADC0_DP0><selection=ADC0_SE0_PIN_SEL,ADC0_DP0>
#define ADC0_DP0_SIG_SEL     -3

// Signal mapping for ADC0_DP1 pin
//   <o> ADC0_DP1 [ADC0_DP1/ADC0_SE1]<name=ADC0_DP1_SIG_SEL><constant>
//   <i> ADC0_DP1 has no pin-mapping hardware
//     <-3=> ADC0_DP1/ADC0_SE1 (fixed)<selection=ADC0_DP1_PIN_SEL,ADC0_DP1><selection=ADC0_SE1_PIN_SEL,ADC0_DP1>
#define ADC0_DP1_SIG_SEL     -3

// Signal mapping for ADC0_SE16 pin
//   <o> ADC0_SE16 [ADC0_SE16/CMP1_IN2/ADC0_SE21]<name=ADC0_SE16_SIG_SEL><constant>
//   <i> ADC0_SE16 has no pin-mapping hardware
//     <-3=> ADC0_SE16/CMP1_IN2/ADC0_SE21 (fixed)<selection=ADC0_SE16_PIN_SEL,ADC0_SE16><selection=CMP1_IN2_PIN_SEL,ADC0_SE16><selection=ADC0_SE21_PIN_SEL,ADC0_SE16>
#define ADC0_SE16_SIG_SEL    -3

// Signal mapping for ADC0_SE23 pin
//   <o> ADC0_SE23 [DAC0_OUT/CMP1_IN3/ADC0_SE23]<name=ADC0_SE23_SIG_SEL><constant>
//   <i> ADC0_SE23 has no pin-mapping hardware
//     <-3=> DAC0_OUT/CMP1_IN3/ADC0_SE23 (fixed)<selection=DAC0_OUT_PIN_SEL,ADC0_SE23><selection=CMP1_IN3_PIN_SEL,ADC0_SE23><selection=ADC0_SE23_PIN_SEL,ADC0_SE23>
#define ADC0_SE23_SIG_SEL    -3

// Signal mapping for ADC1_DM0 pin
//   <o> ADC1_DM0 [ADC1_DM0/ADC0_DM3/ADC1_SE19]<name=ADC1_DM0_SIG_SEL><constant>
//   <i> ADC1_DM0 has no pin-mapping hardware
//     <-3=> ADC1_DM0/ADC0_DM3/ADC1_SE19 (fixed)<selection=ADC1_DM0_PIN_SEL,ADC1_DM0><selection=ADC0_DM3_PIN_SEL,ADC1_DM0><selection=ADC1_SE19_PIN_SEL,ADC1_DM0>
#define ADC1_DM0_SIG_SEL     -3

// Signal mapping for ADC1_DM1 pin
//   <o> ADC1_DM1 [ADC1_DM1/ADC1_SE20]<name=ADC1_DM1_SIG_SEL><constant>
//   <i> ADC1_DM1 has no pin-mapping hardware
//     <-3=> ADC1_DM1/ADC1_SE20 (fixed)<selection=ADC1_DM1_PIN_SEL,ADC1_DM1><selection=ADC1_SE20_PIN_SEL,ADC1_DM1>
#define ADC1_DM1_SIG_SEL     -3

// Signal mapping for ADC1_DP0 pin
//   <o> ADC1_DP0 [ADC1_DP0/ADC0_DP3/ADC1_SE0/ADC0_SE3]<name=ADC1_DP0_SIG_SEL><constant>
//   <i> ADC1_DP0 has no pin-mapping hardware
//     <-3=> ADC1_DP0/ADC0_DP3/ADC1_SE0/ADC0_SE3 (fixed)<selection=ADC1_DP0_PIN_SEL,ADC1_DP0><selection=ADC0_DP3_PIN_SEL,ADC1_DP0><selection=ADC1_SE0_PIN_SEL,ADC1_DP0><selection=ADC0_SE3_PIN_SEL,ADC1_DP0>
#define ADC1_DP0_SIG_SEL     -3

// Signal mapping for ADC1_DP1 pin
//   <o> ADC1_DP1 [ADC1_DP1/ADC1_SE1]<name=ADC1_DP1_SIG_SEL><constant>
//   <i> ADC1_DP1 has no pin-mapping hardware
//     <-3=> ADC1_DP1/ADC1_SE1 (fixed)<selection=ADC1_DP1_PIN_SEL,ADC1_DP1><selection=ADC1_SE1_PIN_SEL,ADC1_DP1>
#define ADC1_DP1_SIG_SEL     -3

// Signal mapping for ADC1_SE16 pin
//   <o> ADC1_SE16 [ADC1_SE16/CMP2_IN2/ADC0_SE22]<name=ADC1_SE16_SIG_SEL><constant>
//   <i> ADC1_SE16 has no pin-mapping hardware
//     <-3=> ADC1_SE16/CMP2_IN2/ADC0_SE22 (fixed)<selection=ADC1_SE16_PIN_SEL,ADC1_SE16><selection=CMP2_IN2_PIN_SEL,ADC1_SE16><selection=ADC0_SE22_PIN_SEL,ADC1_SE16>
#define ADC1_SE16_SIG_SEL    -3

// Signal mapping for ADC1_SE18 pin
//   <o> ADC1_SE18 [VREF_OUT/CMP1_IN5/CMP0_IN5/ADC1_SE18]<name=ADC1_SE18_SIG_SEL><constant>
//   <i> ADC1_SE18 has no pin-mapping hardware
//     <-3=> VREF_OUT/CMP1_IN5/CMP0_IN5/ADC1_SE18 (fixed)<selection=VREF_OUT_PIN_SEL,ADC1_SE18><selection=CMP1_IN5_PIN_SEL,ADC1_SE18><selection=CMP0_IN5_PIN_SEL,ADC1_SE18><selection=ADC1_SE18_PIN_SEL,ADC1_SE18>
#define ADC1_SE18_SIG_SEL    -3

// Signal mapping for ADC1_SE23 pin
//   <o> ADC1_SE23 [DAC1_OUT/CMP0_IN4/CMP2_IN3/ADC1_SE23]<name=ADC1_SE23_SIG_SEL><constant>
//   <i> ADC1_SE23 has no pin-mapping hardware
//     <-3=> DAC1_OUT/CMP0_IN4/CMP2_IN3/ADC1_SE23 (fixed)<selection=DAC1_OUT_PIN_SEL,ADC1_SE23><selection=CMP0_IN4_PIN_SEL,ADC1_SE23><selection=CMP2_IN3_PIN_SEL,ADC1_SE23><selection=ADC1_SE23_PIN_SEL,ADC1_SE23>
#define ADC1_SE23_SIG_SEL    -3

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
//   <o> PTA0 (Alias:D8) [GPIOA_0, UART0_CTS_b/UART0_COL_b, FTM0_CH5, JTAG_TCLK/SWD_CLK]<name=PTA0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA0 pin
//     <-2=> JTAG_TCLK/SWD_CLK (reset default)<selection=JTAG_TCLK_PIN_SEL,PTA0 (Alias:D8) (reset default)><selection=SWD_CLK_PIN_SEL,PTA0 (Alias:D8) (reset default)>
//     <1=> GPIOA_0<selection=GPIOA_0_PIN_SEL,PTA0 (Alias:D8)>
//     <2=> UART0_CTS_b/UART0_COL_b<selection=UART0_CTS_b_PIN_SEL,PTA0 (Alias:D8)><selection=UART0_COL_b_PIN_SEL,PTA0 (Alias:D8)>
//     <3=> FTM0_CH5<selection=FTM0_CH5_PIN_SEL,PTA0 (Alias:D8)>
//     <7=> JTAG_TCLK/SWD_CLK<selection=JTAG_TCLK_PIN_SEL,PTA0 (Alias:D8)><selection=SWD_CLK_PIN_SEL,PTA0 (Alias:D8)>
//     <-2=> Default
#define PTA0_SIG_SEL         -2

// Signal mapping for PTA1 pin
//   <o> PTA1 (Alias:D3) [GPIOA_1, UART0_RX, FTM0_CH6, JTAG_TDI]<name=PTA1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA1 pin
//     <-2=> JTAG_TDI (reset default)<selection=JTAG_TDI_PIN_SEL,PTA1 (Alias:D3) (reset default)>
//     <1=> GPIOA_1<selection=GPIOA_1_PIN_SEL,PTA1 (Alias:D3)>
//     <2=> UART0_RX<selection=UART0_RX_PIN_SEL,PTA1 (Alias:D3)>
//     <3=> FTM0_CH6<selection=FTM0_CH6_PIN_SEL,PTA1 (Alias:D3)>
//     <7=> JTAG_TDI<selection=JTAG_TDI_PIN_SEL,PTA1 (Alias:D3)>
//     <1=> Default
#define PTA1_SIG_SEL         1

// Signal mapping for PTA2 pin
//   <o> PTA2 (Alias:D5) [GPIOA_2, UART0_TX, FTM0_CH7, JTAG_TDO/TRACE_SWO]<name=PTA2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA2 pin
//     <-2=> JTAG_TDO/TRACE_SWO (reset default)<selection=JTAG_TDO_PIN_SEL,PTA2 (Alias:D5) (reset default)><selection=TRACE_SWO_PIN_SEL,PTA2 (Alias:D5) (reset default)>
//     <1=> GPIOA_2<selection=GPIOA_2_PIN_SEL,PTA2 (Alias:D5)>
//     <2=> UART0_TX<selection=UART0_TX_PIN_SEL,PTA2 (Alias:D5)>
//     <3=> FTM0_CH7<selection=FTM0_CH7_PIN_SEL,PTA2 (Alias:D5)>
//     <7=> JTAG_TDO/TRACE_SWO<selection=JTAG_TDO_PIN_SEL,PTA2 (Alias:D5)><selection=TRACE_SWO_PIN_SEL,PTA2 (Alias:D5)>
//     <1=> Default
#define PTA2_SIG_SEL         1

// Signal mapping for PTA3 pin
//   <o> PTA3 [GPIOA_3, UART0_RTS_b, FTM0_CH0, JTAG_TMS/SWD_DIO]<name=PTA3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA3 pin
//     <-2=> JTAG_TMS/SWD_DIO (reset default)<selection=JTAG_TMS_PIN_SEL,PTA3 (reset default)><selection=SWD_DIO_PIN_SEL,PTA3 (reset default)>
//     <1=> GPIOA_3<selection=GPIOA_3_PIN_SEL,PTA3>
//     <2=> UART0_RTS_b<selection=UART0_RTS_b_PIN_SEL,PTA3>
//     <3=> FTM0_CH0<selection=FTM0_CH0_PIN_SEL,PTA3>
//     <7=> JTAG_TMS/SWD_DIO<selection=JTAG_TMS_PIN_SEL,PTA3><selection=SWD_DIO_PIN_SEL,PTA3>
//     <-2=> Default
#define PTA3_SIG_SEL         -2

// Signal mapping for PTA4 pin
//   <o> PTA4 [GPIOA_4/LLWU_P3, FTM0_CH1, NMI_b]<name=PTA4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA4 pin
//     <-2=> NMI_b (reset default)<selection=NMI_b_PIN_SEL,PTA4 (reset default)>
//     <1=> GPIOA_4/LLWU_P3<selection=GPIOA_4_PIN_SEL,PTA4><selection=LLWU_P3_PIN_SEL,PTA4>
//     <3=> FTM0_CH1<selection=FTM0_CH1_PIN_SEL,PTA4>
//     <7=> NMI_b<selection=NMI_b_PIN_SEL,PTA4>
//     <-2=> Default
#define PTA4_SIG_SEL         -2

// Signal mapping for PTA5 pin
//   <o> PTA5 [GPIOA_5, USB_CLKIN, FTM0_CH2, RMII0_RXER/MII0_RXER, CMP2_OUT, I2S0_TX_BCLK, JTAG_TRST_b]<name=PTA5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA5 pin
//     <-2=> JTAG_TRST_b (reset default)<selection=JTAG_TRST_b_PIN_SEL,PTA5 (reset default)>
//     <1=> GPIOA_5<selection=GPIOA_5_PIN_SEL,PTA5>
//     <2=> USB_CLKIN<selection=USB_CLKIN_PIN_SEL,PTA5>
//     <3=> FTM0_CH2<selection=FTM0_CH2_PIN_SEL,PTA5>
//     <4=> RMII0_RXER/MII0_RXER<selection=RMII0_RXER_PIN_SEL,PTA5><selection=MII0_RXER_PIN_SEL,PTA5>
//     <5=> CMP2_OUT<selection=CMP2_OUT_PIN_SEL,PTA5>
//     <6=> I2S0_TX_BCLK<selection=I2S0_TX_BCLK_PIN_SEL,PTA5>
//     <7=> JTAG_TRST_b<selection=JTAG_TRST_b_PIN_SEL,PTA5>
//     <-2=> Default
#define PTA5_SIG_SEL         -2

// Signal mapping for PTA6 pin
//   <o> PTA6 [GPIOA_6, FTM0_CH3, CLKOUT, TRACE_CLKOUT]<name=PTA6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA6 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_6<selection=GPIOA_6_PIN_SEL,PTA6>
//     <3=> FTM0_CH3<selection=FTM0_CH3_PIN_SEL,PTA6>
//     <5=> CLKOUT<selection=CLKOUT_PIN_SEL,PTA6>
//     <7=> TRACE_CLKOUT<selection=TRACE_CLKOUT_PIN_SEL,PTA6>
//     <-2=> Default
#define PTA6_SIG_SEL         -2

// Signal mapping for PTA7 pin
//   <o> PTA7 [ADC0_SE10, GPIOA_7, FTM0_CH4, TRACE_D3]<name=PTA7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA7 pin
//     <-2=> ADC0_SE10 (reset default)<selection=ADC0_SE10_PIN_SEL,PTA7 (reset default)>
//     <0=> ADC0_SE10<selection=ADC0_SE10_PIN_SEL,PTA7>
//     <1=> GPIOA_7<selection=GPIOA_7_PIN_SEL,PTA7>
//     <3=> FTM0_CH4<selection=FTM0_CH4_PIN_SEL,PTA7>
//     <7=> TRACE_D3<selection=TRACE_D3_PIN_SEL,PTA7>
//     <-2=> Default
#define PTA7_SIG_SEL         -2

// Signal mapping for PTA8 pin
//   <o> PTA8 [ADC0_SE11, GPIOA_8, FTM1_CH0, FTM1_QD_PHA, TRACE_D2]<name=PTA8_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA8 pin
//     <-2=> ADC0_SE11 (reset default)<selection=ADC0_SE11_PIN_SEL,PTA8 (reset default)>
//     <0=> ADC0_SE11<selection=ADC0_SE11_PIN_SEL,PTA8>
//     <1=> GPIOA_8<selection=GPIOA_8_PIN_SEL,PTA8>
//     <3=> FTM1_CH0<selection=FTM1_CH0_PIN_SEL,PTA8>
//     <6=> FTM1_QD_PHA<selection=FTM1_QD_PHA_PIN_SEL,PTA8>
//     <7=> TRACE_D2<selection=TRACE_D2_PIN_SEL,PTA8>
//     <-2=> Default
#define PTA8_SIG_SEL         -2

// Signal mapping for PTA9 pin
//   <o> PTA9 [GPIOA_9, FTM1_CH1, MII0_RXD3, FTM1_QD_PHB, TRACE_D1]<name=PTA9_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA9 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_9<selection=GPIOA_9_PIN_SEL,PTA9>
//     <3=> FTM1_CH1<selection=FTM1_CH1_PIN_SEL,PTA9>
//     <4=> MII0_RXD3<selection=MII0_RXD3_PIN_SEL,PTA9>
//     <6=> FTM1_QD_PHB<selection=FTM1_QD_PHB_PIN_SEL,PTA9>
//     <7=> TRACE_D1<selection=TRACE_D1_PIN_SEL,PTA9>
//     <-2=> Default
#define PTA9_SIG_SEL         -2

// Signal mapping for PTA10 pin
//   <o> PTA10 [GPIOA_10, FTM2_CH0, MII0_RXD2, FTM2_QD_PHA, TRACE_D0]<name=PTA10_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA10 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_10<selection=GPIOA_10_PIN_SEL,PTA10>
//     <3=> FTM2_CH0<selection=FTM2_CH0_PIN_SEL,PTA10>
//     <4=> MII0_RXD2<selection=MII0_RXD2_PIN_SEL,PTA10>
//     <6=> FTM2_QD_PHA<selection=FTM2_QD_PHA_PIN_SEL,PTA10>
//     <7=> TRACE_D0<selection=TRACE_D0_PIN_SEL,PTA10>
//     <-2=> Default
#define PTA10_SIG_SEL        -2

// Signal mapping for PTA11 pin
//   <o> PTA11 [GPIOA_11, FTM2_CH1, MII0_RXCLK, I2C2_SDA, FTM2_QD_PHB]<name=PTA11_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA11 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_11<selection=GPIOA_11_PIN_SEL,PTA11>
//     <3=> FTM2_CH1<selection=FTM2_CH1_PIN_SEL,PTA11>
//     <4=> MII0_RXCLK<selection=MII0_RXCLK_PIN_SEL,PTA11>
//     <5=> I2C2_SDA<selection=I2C2_SDA_PIN_SEL,PTA11>
//     <6=> FTM2_QD_PHB<selection=FTM2_QD_PHB_PIN_SEL,PTA11>
//     <-2=> Default
#define PTA11_SIG_SEL        -2

// Signal mapping for PTA12 pin
//   <o> PTA12 [CMP2_IN0, GPIOA_12, CAN0_TX, FTM1_CH0, RMII0_RXD1/MII0_RXD1, I2C2_SCL, I2S0_TXD0, FTM1_QD_PHA]<name=PTA12_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA12 pin
//     <-2=> CMP2_IN0 (reset default)<selection=CMP2_IN0_PIN_SEL,PTA12 (reset default)>
//     <0=> CMP2_IN0<selection=CMP2_IN0_PIN_SEL,PTA12>
//     <1=> GPIOA_12<selection=GPIOA_12_PIN_SEL,PTA12>
//     <2=> CAN0_TX<selection=CAN0_TX_PIN_SEL,PTA12>
//     <3=> FTM1_CH0<selection=FTM1_CH0_PIN_SEL,PTA12>
//     <4=> RMII0_RXD1/MII0_RXD1<selection=RMII0_RXD1_PIN_SEL,PTA12><selection=MII0_RXD1_PIN_SEL,PTA12>
//     <5=> I2C2_SCL<selection=I2C2_SCL_PIN_SEL,PTA12>
//     <6=> I2S0_TXD0<selection=I2S0_TXD0_PIN_SEL,PTA12>
//     <7=> FTM1_QD_PHA<selection=FTM1_QD_PHA_PIN_SEL,PTA12>
//     <-2=> Default
#define PTA12_SIG_SEL        -2

// Signal mapping for PTA13 pin
//   <o> PTA13 [CMP2_IN1, GPIOA_13/LLWU_P4, CAN0_RX, FTM1_CH1, RMII0_RXD0/MII0_RXD0, I2C2_SDA, I2S0_TX_FS, FTM1_QD_PHB]<name=PTA13_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA13 pin
//     <-2=> CMP2_IN1 (reset default)<selection=CMP2_IN1_PIN_SEL,PTA13 (reset default)>
//     <0=> CMP2_IN1<selection=CMP2_IN1_PIN_SEL,PTA13>
//     <1=> GPIOA_13/LLWU_P4<selection=GPIOA_13_PIN_SEL,PTA13><selection=LLWU_P4_PIN_SEL,PTA13>
//     <2=> CAN0_RX<selection=CAN0_RX_PIN_SEL,PTA13>
//     <3=> FTM1_CH1<selection=FTM1_CH1_PIN_SEL,PTA13>
//     <4=> RMII0_RXD0/MII0_RXD0<selection=RMII0_RXD0_PIN_SEL,PTA13><selection=MII0_RXD0_PIN_SEL,PTA13>
//     <5=> I2C2_SDA<selection=I2C2_SDA_PIN_SEL,PTA13>
//     <6=> I2S0_TX_FS<selection=I2S0_TX_FS_PIN_SEL,PTA13>
//     <7=> FTM1_QD_PHB<selection=FTM1_QD_PHB_PIN_SEL,PTA13>
//     <-2=> Default
#define PTA13_SIG_SEL        -2

// Signal mapping for PTA14 pin
//   <o> PTA14 [GPIOA_14, SPI0_PCS0, UART0_TX, RMII0_CRS_DV/MII0_RXDV, I2C2_SCL, I2S0_RX_BCLK, I2S0_TXD1]<name=PTA14_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA14 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_14<selection=GPIOA_14_PIN_SEL,PTA14>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTA14>
//     <3=> UART0_TX<selection=UART0_TX_PIN_SEL,PTA14>
//     <4=> RMII0_CRS_DV/MII0_RXDV<selection=RMII0_CRS_DV_PIN_SEL,PTA14><selection=MII0_RXDV_PIN_SEL,PTA14>
//     <5=> I2C2_SCL<selection=I2C2_SCL_PIN_SEL,PTA14>
//     <6=> I2S0_RX_BCLK<selection=I2S0_RX_BCLK_PIN_SEL,PTA14>
//     <7=> I2S0_TXD1<selection=I2S0_TXD1_PIN_SEL,PTA14>
//     <-2=> Default
#define PTA14_SIG_SEL        -2

// Signal mapping for PTA15 pin
//   <o> PTA15 [GPIOA_15, SPI0_SCK, UART0_RX, RMII0_TXEN/MII0_TXEN, I2S0_RXD0]<name=PTA15_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA15 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_15<selection=GPIOA_15_PIN_SEL,PTA15>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTA15>
//     <3=> UART0_RX<selection=UART0_RX_PIN_SEL,PTA15>
//     <4=> RMII0_TXEN/MII0_TXEN<selection=RMII0_TXEN_PIN_SEL,PTA15><selection=MII0_TXEN_PIN_SEL,PTA15>
//     <6=> I2S0_RXD0<selection=I2S0_RXD0_PIN_SEL,PTA15>
//     <-2=> Default
#define PTA15_SIG_SEL        -2

// Signal mapping for PTA16 pin
//   <o> PTA16 [GPIOA_16, SPI0_SOUT, UART0_CTS_b/UART0_COL_b, RMII0_TXD0/MII0_TXD0, I2S0_RX_FS, I2S0_RXD1]<name=PTA16_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA16 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_16<selection=GPIOA_16_PIN_SEL,PTA16>
//     <2=> SPI0_SOUT<selection=SPI0_SOUT_PIN_SEL,PTA16>
//     <3=> UART0_CTS_b/UART0_COL_b<selection=UART0_CTS_b_PIN_SEL,PTA16><selection=UART0_COL_b_PIN_SEL,PTA16>
//     <4=> RMII0_TXD0/MII0_TXD0<selection=RMII0_TXD0_PIN_SEL,PTA16><selection=MII0_TXD0_PIN_SEL,PTA16>
//     <6=> I2S0_RX_FS<selection=I2S0_RX_FS_PIN_SEL,PTA16>
//     <7=> I2S0_RXD1<selection=I2S0_RXD1_PIN_SEL,PTA16>
//     <-2=> Default
#define PTA16_SIG_SEL        -2

// Signal mapping for PTA17 pin
//   <o> PTA17 [ADC1_SE17, GPIOA_17, SPI0_SIN, UART0_RTS_b, RMII0_TXD1/MII0_TXD1, I2S0_MCLK]<name=PTA17_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA17 pin
//     <-2=> ADC1_SE17 (reset default)<selection=ADC1_SE17_PIN_SEL,PTA17 (reset default)>
//     <0=> ADC1_SE17<selection=ADC1_SE17_PIN_SEL,PTA17>
//     <1=> GPIOA_17<selection=GPIOA_17_PIN_SEL,PTA17>
//     <2=> SPI0_SIN<selection=SPI0_SIN_PIN_SEL,PTA17>
//     <3=> UART0_RTS_b<selection=UART0_RTS_b_PIN_SEL,PTA17>
//     <4=> RMII0_TXD1/MII0_TXD1<selection=RMII0_TXD1_PIN_SEL,PTA17><selection=MII0_TXD1_PIN_SEL,PTA17>
//     <6=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTA17>
//     <-2=> Default
#define PTA17_SIG_SEL        -2

// Signal mapping for PTA18 pin
//   <o> PTA18 [EXTAL0, GPIOA_18, FTM0_FLT2, FTM_CLKIN0]<name=PTA18_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA18 pin
//     <-2=> EXTAL0 (reset default)<selection=EXTAL0_PIN_SEL,PTA18 (reset default)>
//     <0=> EXTAL0<selection=EXTAL0_PIN_SEL,PTA18>
//     <1=> GPIOA_18<selection=GPIOA_18_PIN_SEL,PTA18>
//     <3=> FTM0_FLT2<selection=FTM0_FLT2_PIN_SEL,PTA18>
//     <4=> FTM_CLKIN0<selection=FTM_CLKIN0_PIN_SEL,PTA18>
//     <-2=> Default
#define PTA18_SIG_SEL        -2

// Signal mapping for PTA19 pin
//   <o> PTA19 [XTAL0, GPIOA_19, FTM1_FLT0, FTM_CLKIN1, LPTMR0_ALT1]<name=PTA19_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA19 pin
//     <-2=> XTAL0 (reset default)<selection=XTAL0_PIN_SEL,PTA19 (reset default)>
//     <0=> XTAL0<selection=XTAL0_PIN_SEL,PTA19>
//     <1=> GPIOA_19<selection=GPIOA_19_PIN_SEL,PTA19>
//     <3=> FTM1_FLT0<selection=FTM1_FLT0_PIN_SEL,PTA19>
//     <4=> FTM_CLKIN1<selection=FTM_CLKIN1_PIN_SEL,PTA19>
//     <6=> LPTMR0_ALT1<selection=LPTMR0_ALT1_PIN_SEL,PTA19>
//     <-2=> Default
#define PTA19_SIG_SEL        -2

// Signal mapping for PTA24 pin
//   <o> PTA24 [GPIOA_24, MII0_TXD2, FB_A29]<name=PTA24_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA24 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_24<selection=GPIOA_24_PIN_SEL,PTA24>
//     <4=> MII0_TXD2<selection=MII0_TXD2_PIN_SEL,PTA24>
//     <6=> FB_A29<selection=FB_A29_PIN_SEL,PTA24>
//     <-2=> Default
#define PTA24_SIG_SEL        -2

// Signal mapping for PTA25 pin
//   <o> PTA25 [GPIOA_25, MII0_TXCLK, FB_A28]<name=PTA25_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA25 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_25<selection=GPIOA_25_PIN_SEL,PTA25>
//     <4=> MII0_TXCLK<selection=MII0_TXCLK_PIN_SEL,PTA25>
//     <6=> FB_A28<selection=FB_A28_PIN_SEL,PTA25>
//     <-2=> Default
#define PTA25_SIG_SEL        -2

// Signal mapping for PTA26 pin
//   <o> PTA26 [GPIOA_26, MII0_TXD3, FB_A27]<name=PTA26_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA26 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_26<selection=GPIOA_26_PIN_SEL,PTA26>
//     <4=> MII0_TXD3<selection=MII0_TXD3_PIN_SEL,PTA26>
//     <6=> FB_A27<selection=FB_A27_PIN_SEL,PTA26>
//     <-2=> Default
#define PTA26_SIG_SEL        -2

// Signal mapping for PTA27 pin
//   <o> PTA27 [GPIOA_27, MII0_CRS, FB_A26]<name=PTA27_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA27 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_27<selection=GPIOA_27_PIN_SEL,PTA27>
//     <4=> MII0_CRS<selection=MII0_CRS_PIN_SEL,PTA27>
//     <6=> FB_A26<selection=FB_A26_PIN_SEL,PTA27>
//     <-2=> Default
#define PTA27_SIG_SEL        -2

// Signal mapping for PTA28 pin
//   <o> PTA28 [GPIOA_28, MII0_TXER, FB_A25]<name=PTA28_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA28 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_28<selection=GPIOA_28_PIN_SEL,PTA28>
//     <4=> MII0_TXER<selection=MII0_TXER_PIN_SEL,PTA28>
//     <6=> FB_A25<selection=FB_A25_PIN_SEL,PTA28>
//     <-2=> Default
#define PTA28_SIG_SEL        -2

// Signal mapping for PTA29 pin
//   <o> PTA29 [GPIOA_29, MII0_COL, FB_A24]<name=PTA29_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTA29 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_29<selection=GPIOA_29_PIN_SEL,PTA29>
//     <4=> MII0_COL<selection=MII0_COL_PIN_SEL,PTA29>
//     <6=> FB_A24<selection=FB_A24_PIN_SEL,PTA29>
//     <-2=> Default
#define PTA29_SIG_SEL        -2

// </h>

// <h> Port B Pins

// Signal mapping for PTB0 pin
//   <o> PTB0 [ADC0_SE8/ADC1_SE8, GPIOB_0/LLWU_P5, I2C0_SCL, FTM1_CH0, RMII0_MDIO/MII0_MDIO, FTM1_QD_PHA]<name=PTB0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB0 pin
//     <-2=> ADC0_SE8/ADC1_SE8 (reset default)<selection=ADC0_SE8_PIN_SEL,PTB0 (reset default)><selection=ADC1_SE8_PIN_SEL,PTB0 (reset default)>
//     <0=> ADC0_SE8/ADC1_SE8<selection=ADC0_SE8_PIN_SEL,PTB0><selection=ADC1_SE8_PIN_SEL,PTB0>
//     <1=> GPIOB_0/LLWU_P5<selection=GPIOB_0_PIN_SEL,PTB0><selection=LLWU_P5_PIN_SEL,PTB0>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTB0>
//     <3=> FTM1_CH0<selection=FTM1_CH0_PIN_SEL,PTB0>
//     <4=> RMII0_MDIO/MII0_MDIO<selection=RMII0_MDIO_PIN_SEL,PTB0><selection=MII0_MDIO_PIN_SEL,PTB0>
//     <6=> FTM1_QD_PHA<selection=FTM1_QD_PHA_PIN_SEL,PTB0>
//     <-2=> Default
#define PTB0_SIG_SEL         -2

// Signal mapping for PTB1 pin
//   <o> PTB1 [ADC0_SE9/ADC1_SE9, GPIOB_1, I2C0_SDA, FTM1_CH1, RMII0_MDC/MII0_MDC, FTM1_QD_PHB]<name=PTB1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB1 pin
//     <-2=> ADC0_SE9/ADC1_SE9 (reset default)<selection=ADC0_SE9_PIN_SEL,PTB1 (reset default)><selection=ADC1_SE9_PIN_SEL,PTB1 (reset default)>
//     <0=> ADC0_SE9/ADC1_SE9<selection=ADC0_SE9_PIN_SEL,PTB1><selection=ADC1_SE9_PIN_SEL,PTB1>
//     <1=> GPIOB_1<selection=GPIOB_1_PIN_SEL,PTB1>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTB1>
//     <3=> FTM1_CH1<selection=FTM1_CH1_PIN_SEL,PTB1>
//     <4=> RMII0_MDC/MII0_MDC<selection=RMII0_MDC_PIN_SEL,PTB1><selection=MII0_MDC_PIN_SEL,PTB1>
//     <6=> FTM1_QD_PHB<selection=FTM1_QD_PHB_PIN_SEL,PTB1>
//     <-2=> Default
#define PTB1_SIG_SEL         -2

// Signal mapping for PTB2 pin
//   <o> PTB2 (Alias:A0) [ADC0_SE12, GPIOB_2, I2C0_SCL, UART0_RTS_b, ENET0_1588_TMR0, FTM0_FLT3]<name=PTB2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB2 pin
//     <-2=> ADC0_SE12 (reset default)<selection=ADC0_SE12_PIN_SEL,PTB2 (Alias:A0) (reset default)>
//     <0=> ADC0_SE12<selection=ADC0_SE12_PIN_SEL,PTB2 (Alias:A0)>
//     <1=> GPIOB_2<selection=GPIOB_2_PIN_SEL,PTB2 (Alias:A0)>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTB2 (Alias:A0)>
//     <3=> UART0_RTS_b<selection=UART0_RTS_b_PIN_SEL,PTB2 (Alias:A0)>
//     <4=> ENET0_1588_TMR0<selection=ENET0_1588_TMR0_PIN_SEL,PTB2 (Alias:A0)>
//     <6=> FTM0_FLT3<selection=FTM0_FLT3_PIN_SEL,PTB2 (Alias:A0)>
//     <0=> Default
#define PTB2_SIG_SEL         0

// Signal mapping for PTB3 pin
//   <o> PTB3 (Alias:A1) [ADC0_SE13, GPIOB_3, I2C0_SDA, UART0_CTS_b/UART0_COL_b, ENET0_1588_TMR1, FTM0_FLT0]<name=PTB3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB3 pin
//     <-2=> ADC0_SE13 (reset default)<selection=ADC0_SE13_PIN_SEL,PTB3 (Alias:A1) (reset default)>
//     <0=> ADC0_SE13<selection=ADC0_SE13_PIN_SEL,PTB3 (Alias:A1)>
//     <1=> GPIOB_3<selection=GPIOB_3_PIN_SEL,PTB3 (Alias:A1)>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTB3 (Alias:A1)>
//     <3=> UART0_CTS_b/UART0_COL_b<selection=UART0_CTS_b_PIN_SEL,PTB3 (Alias:A1)><selection=UART0_COL_b_PIN_SEL,PTB3 (Alias:A1)>
//     <4=> ENET0_1588_TMR1<selection=ENET0_1588_TMR1_PIN_SEL,PTB3 (Alias:A1)>
//     <6=> FTM0_FLT0<selection=FTM0_FLT0_PIN_SEL,PTB3 (Alias:A1)>
//     <0=> Default
#define PTB3_SIG_SEL         0

// Signal mapping for PTB4 pin
//   <o> PTB4 [ADC1_SE10, GPIOB_4, ENET0_1588_TMR2, FTM1_FLT0]<name=PTB4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB4 pin
//     <-2=> ADC1_SE10 (reset default)<selection=ADC1_SE10_PIN_SEL,PTB4 (reset default)>
//     <0=> ADC1_SE10<selection=ADC1_SE10_PIN_SEL,PTB4>
//     <1=> GPIOB_4<selection=GPIOB_4_PIN_SEL,PTB4>
//     <4=> ENET0_1588_TMR2<selection=ENET0_1588_TMR2_PIN_SEL,PTB4>
//     <6=> FTM1_FLT0<selection=FTM1_FLT0_PIN_SEL,PTB4>
//     <-2=> Default
#define PTB4_SIG_SEL         -2

// Signal mapping for PTB5 pin
//   <o> PTB5 [ADC1_SE11, GPIOB_5, ENET0_1588_TMR3, FTM2_FLT0]<name=PTB5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB5 pin
//     <-2=> ADC1_SE11 (reset default)<selection=ADC1_SE11_PIN_SEL,PTB5 (reset default)>
//     <0=> ADC1_SE11<selection=ADC1_SE11_PIN_SEL,PTB5>
//     <1=> GPIOB_5<selection=GPIOB_5_PIN_SEL,PTB5>
//     <4=> ENET0_1588_TMR3<selection=ENET0_1588_TMR3_PIN_SEL,PTB5>
//     <6=> FTM2_FLT0<selection=FTM2_FLT0_PIN_SEL,PTB5>
//     <-2=> Default
#define PTB5_SIG_SEL         -2

// Signal mapping for PTB6 pin
//   <o> PTB6 [ADC1_SE12, GPIOB_6, FB_AD23]<name=PTB6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB6 pin
//     <-2=> ADC1_SE12 (reset default)<selection=ADC1_SE12_PIN_SEL,PTB6 (reset default)>
//     <0=> ADC1_SE12<selection=ADC1_SE12_PIN_SEL,PTB6>
//     <1=> GPIOB_6<selection=GPIOB_6_PIN_SEL,PTB6>
//     <5=> FB_AD23<selection=FB_AD23_PIN_SEL,PTB6>
//     <-2=> Default
#define PTB6_SIG_SEL         -2

// Signal mapping for PTB7 pin
//   <o> PTB7 [ADC1_SE13, GPIOB_7, FB_AD22]<name=PTB7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB7 pin
//     <-2=> ADC1_SE13 (reset default)<selection=ADC1_SE13_PIN_SEL,PTB7 (reset default)>
//     <0=> ADC1_SE13<selection=ADC1_SE13_PIN_SEL,PTB7>
//     <1=> GPIOB_7<selection=GPIOB_7_PIN_SEL,PTB7>
//     <5=> FB_AD22<selection=FB_AD22_PIN_SEL,PTB7>
//     <-2=> Default
#define PTB7_SIG_SEL         -2

// Signal mapping for PTB8 pin
//   <o> PTB8 [GPIOB_8, UART3_RTS_b, FB_AD21]<name=PTB8_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB8 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_8<selection=GPIOB_8_PIN_SEL,PTB8>
//     <3=> UART3_RTS_b<selection=UART3_RTS_b_PIN_SEL,PTB8>
//     <5=> FB_AD21<selection=FB_AD21_PIN_SEL,PTB8>
//     <-2=> Default
#define PTB8_SIG_SEL         -2

// Signal mapping for PTB9 pin
//   <o> PTB9 (Alias:D2) [GPIOB_9, SPI1_PCS1, UART3_CTS_b, FB_AD20]<name=PTB9_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB9 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_9<selection=GPIOB_9_PIN_SEL,PTB9 (Alias:D2)>
//     <2=> SPI1_PCS1<selection=SPI1_PCS1_PIN_SEL,PTB9 (Alias:D2)>
//     <3=> UART3_CTS_b<selection=UART3_CTS_b_PIN_SEL,PTB9 (Alias:D2)>
//     <5=> FB_AD20<selection=FB_AD20_PIN_SEL,PTB9 (Alias:D2)>
//     <1=> Default
#define PTB9_SIG_SEL         1

// Signal mapping for PTB10 pin
//   <o> PTB10 (Alias:A2) [ADC1_SE14, GPIOB_10, SPI1_PCS0, UART3_RX, FB_AD19, FTM0_FLT1]<name=PTB10_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB10 pin
//     <-2=> ADC1_SE14 (reset default)<selection=ADC1_SE14_PIN_SEL,PTB10 (Alias:A2) (reset default)>
//     <0=> ADC1_SE14<selection=ADC1_SE14_PIN_SEL,PTB10 (Alias:A2)>
//     <1=> GPIOB_10<selection=GPIOB_10_PIN_SEL,PTB10 (Alias:A2)>
//     <2=> SPI1_PCS0<selection=SPI1_PCS0_PIN_SEL,PTB10 (Alias:A2)>
//     <3=> UART3_RX<selection=UART3_RX_PIN_SEL,PTB10 (Alias:A2)>
//     <5=> FB_AD19<selection=FB_AD19_PIN_SEL,PTB10 (Alias:A2)>
//     <6=> FTM0_FLT1<selection=FTM0_FLT1_PIN_SEL,PTB10 (Alias:A2)>
//     <0=> Default
#define PTB10_SIG_SEL        0

// Signal mapping for PTB11 pin
//   <o> PTB11 (Alias:A3) [ADC1_SE15, GPIOB_11, SPI1_SCK, UART3_TX, FB_AD18, FTM0_FLT2]<name=PTB11_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB11 pin
//     <-2=> ADC1_SE15 (reset default)<selection=ADC1_SE15_PIN_SEL,PTB11 (Alias:A3) (reset default)>
//     <0=> ADC1_SE15<selection=ADC1_SE15_PIN_SEL,PTB11 (Alias:A3)>
//     <1=> GPIOB_11<selection=GPIOB_11_PIN_SEL,PTB11 (Alias:A3)>
//     <2=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTB11 (Alias:A3)>
//     <3=> UART3_TX<selection=UART3_TX_PIN_SEL,PTB11 (Alias:A3)>
//     <5=> FB_AD18<selection=FB_AD18_PIN_SEL,PTB11 (Alias:A3)>
//     <6=> FTM0_FLT2<selection=FTM0_FLT2_PIN_SEL,PTB11 (Alias:A3)>
//     <0=> Default
#define PTB11_SIG_SEL        0

// Signal mapping for PTB12 pin
//   <o> PTB12 [GPIOB_12, UART3_RTS_b, FTM1_CH0, FTM0_CH4, FTM1_QD_PHA]<name=PTB12_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB12 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_12<selection=GPIOB_12_PIN_SEL,PTB12>
//     <2=> UART3_RTS_b<selection=UART3_RTS_b_PIN_SEL,PTB12>
//     <3=> FTM1_CH0<selection=FTM1_CH0_PIN_SEL,PTB12>
//     <4=> FTM0_CH4<selection=FTM0_CH4_PIN_SEL,PTB12>
//     <6=> FTM1_QD_PHA<selection=FTM1_QD_PHA_PIN_SEL,PTB12>
//     <-2=> Default
#define PTB12_SIG_SEL        -2

// Signal mapping for PTB13 pin
//   <o> PTB13 [GPIOB_13, UART3_CTS_b, FTM1_CH1, FTM0_CH5, FTM1_QD_PHB]<name=PTB13_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB13 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_13<selection=GPIOB_13_PIN_SEL,PTB13>
//     <2=> UART3_CTS_b<selection=UART3_CTS_b_PIN_SEL,PTB13>
//     <3=> FTM1_CH1<selection=FTM1_CH1_PIN_SEL,PTB13>
//     <4=> FTM0_CH5<selection=FTM0_CH5_PIN_SEL,PTB13>
//     <6=> FTM1_QD_PHB<selection=FTM1_QD_PHB_PIN_SEL,PTB13>
//     <-2=> Default
#define PTB13_SIG_SEL        -2

// Signal mapping for PTB16 pin
//   <o> PTB16 [GPIOB_16, SPI1_SOUT, UART0_RX, FTM_CLKIN0, FB_AD17, EWM_IN]<name=PTB16_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB16 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_16<selection=GPIOB_16_PIN_SEL,PTB16>
//     <2=> SPI1_SOUT<selection=SPI1_SOUT_PIN_SEL,PTB16>
//     <3=> UART0_RX<selection=UART0_RX_PIN_SEL,PTB16>
//     <4=> FTM_CLKIN0<selection=FTM_CLKIN0_PIN_SEL,PTB16>
//     <5=> FB_AD17<selection=FB_AD17_PIN_SEL,PTB16>
//     <6=> EWM_IN<selection=EWM_IN_PIN_SEL,PTB16>
//     <-2=> Default
#define PTB16_SIG_SEL        -2

// Signal mapping for PTB17 pin
//   <o> PTB17 [GPIOB_17, SPI1_SIN, UART0_TX, FTM_CLKIN1, FB_AD16, EWM_OUT_b]<name=PTB17_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB17 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_17<selection=GPIOB_17_PIN_SEL,PTB17>
//     <2=> SPI1_SIN<selection=SPI1_SIN_PIN_SEL,PTB17>
//     <3=> UART0_TX<selection=UART0_TX_PIN_SEL,PTB17>
//     <4=> FTM_CLKIN1<selection=FTM_CLKIN1_PIN_SEL,PTB17>
//     <5=> FB_AD16<selection=FB_AD16_PIN_SEL,PTB17>
//     <6=> EWM_OUT_b<selection=EWM_OUT_b_PIN_SEL,PTB17>
//     <-2=> Default
#define PTB17_SIG_SEL        -2

// Signal mapping for PTB18 pin
//   <o> PTB18 [GPIOB_18, CAN0_TX, FTM2_CH0, I2S0_TX_BCLK, FB_AD15, FTM2_QD_PHA]<name=PTB18_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB18 pin
//     <-2=> Disabled (reset default)
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
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_19<selection=GPIOB_19_PIN_SEL,PTB19>
//     <2=> CAN0_RX<selection=CAN0_RX_PIN_SEL,PTB19>
//     <3=> FTM2_CH1<selection=FTM2_CH1_PIN_SEL,PTB19>
//     <4=> I2S0_TX_FS<selection=I2S0_TX_FS_PIN_SEL,PTB19>
//     <5=> FB_OE_b<selection=FB_OE_b_PIN_SEL,PTB19>
//     <6=> FTM2_QD_PHB<selection=FTM2_QD_PHB_PIN_SEL,PTB19>
//     <-2=> Default
#define PTB19_SIG_SEL        -2

// Signal mapping for PTB20 pin
//   <o> PTB20 [GPIOB_20, SPI2_PCS0, FB_AD31, CMP0_OUT]<name=PTB20_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB20 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_20<selection=GPIOB_20_PIN_SEL,PTB20>
//     <2=> SPI2_PCS0<selection=SPI2_PCS0_PIN_SEL,PTB20>
//     <5=> FB_AD31<selection=FB_AD31_PIN_SEL,PTB20>
//     <6=> CMP0_OUT<selection=CMP0_OUT_PIN_SEL,PTB20>
//     <-2=> Default
#define PTB20_SIG_SEL        -2

// Signal mapping for PTB21 pin
//   <o> PTB21 (Alias:LED_BLUE) [GPIOB_21, SPI2_SCK, FB_AD30, CMP1_OUT]<name=PTB21_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB21 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_21<selection=GPIOB_21_PIN_SEL,PTB21 (Alias:LED_BLUE)>
//     <2=> SPI2_SCK<selection=SPI2_SCK_PIN_SEL,PTB21 (Alias:LED_BLUE)>
//     <5=> FB_AD30<selection=FB_AD30_PIN_SEL,PTB21 (Alias:LED_BLUE)>
//     <6=> CMP1_OUT<selection=CMP1_OUT_PIN_SEL,PTB21 (Alias:LED_BLUE)>
//     <1=> Default
#define PTB21_SIG_SEL        1

// Signal mapping for PTB22 pin
//   <o> PTB22 (Alias:LED_RED) [GPIOB_22, SPI2_SOUT, FB_AD29, CMP2_OUT]<name=PTB22_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB22 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_22<selection=GPIOB_22_PIN_SEL,PTB22 (Alias:LED_RED)>
//     <2=> SPI2_SOUT<selection=SPI2_SOUT_PIN_SEL,PTB22 (Alias:LED_RED)>
//     <5=> FB_AD29<selection=FB_AD29_PIN_SEL,PTB22 (Alias:LED_RED)>
//     <6=> CMP2_OUT<selection=CMP2_OUT_PIN_SEL,PTB22 (Alias:LED_RED)>
//     <1=> Default
#define PTB22_SIG_SEL        1

// Signal mapping for PTB23 pin
//   <o> PTB23 (Alias:D4) [GPIOB_23, SPI2_SIN, SPI0_PCS5, FB_AD28]<name=PTB23_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTB23 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_23<selection=GPIOB_23_PIN_SEL,PTB23 (Alias:D4)>
//     <2=> SPI2_SIN<selection=SPI2_SIN_PIN_SEL,PTB23 (Alias:D4)>
//     <3=> SPI0_PCS5<selection=SPI0_PCS5_PIN_SEL,PTB23 (Alias:D4)>
//     <5=> FB_AD28<selection=FB_AD28_PIN_SEL,PTB23 (Alias:D4)>
//     <1=> Default
#define PTB23_SIG_SEL        1

// </h>

// <h> Port C Pins

// Signal mapping for PTC0 pin
//   <o> PTC0 [ADC0_SE14, GPIOC_0, SPI0_PCS4, PDB0_EXTRG, USB_SOF_OUT, FB_AD14, I2S0_TXD1]<name=PTC0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC0 pin
//     <-2=> ADC0_SE14 (reset default)<selection=ADC0_SE14_PIN_SEL,PTC0 (reset default)>
//     <0=> ADC0_SE14<selection=ADC0_SE14_PIN_SEL,PTC0>
//     <1=> GPIOC_0<selection=GPIOC_0_PIN_SEL,PTC0>
//     <2=> SPI0_PCS4<selection=SPI0_PCS4_PIN_SEL,PTC0>
//     <3=> PDB0_EXTRG<selection=PDB0_EXTRG_PIN_SEL,PTC0>
//     <4=> USB_SOF_OUT<selection=USB_SOF_OUT_PIN_SEL,PTC0>
//     <5=> FB_AD14<selection=FB_AD14_PIN_SEL,PTC0>
//     <6=> I2S0_TXD1<selection=I2S0_TXD1_PIN_SEL,PTC0>
//     <-2=> Default
#define PTC0_SIG_SEL         -2

// Signal mapping for PTC1 pin
//   <o> PTC1 [ADC0_SE15, GPIOC_1/LLWU_P6, SPI0_PCS3, UART1_RTS_b, FTM0_CH0, FB_AD13, I2S0_TXD0]<name=PTC1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC1 pin
//     <-2=> ADC0_SE15 (reset default)<selection=ADC0_SE15_PIN_SEL,PTC1 (reset default)>
//     <0=> ADC0_SE15<selection=ADC0_SE15_PIN_SEL,PTC1>
//     <1=> GPIOC_1/LLWU_P6<selection=GPIOC_1_PIN_SEL,PTC1><selection=LLWU_P6_PIN_SEL,PTC1>
//     <2=> SPI0_PCS3<selection=SPI0_PCS3_PIN_SEL,PTC1>
//     <3=> UART1_RTS_b<selection=UART1_RTS_b_PIN_SEL,PTC1>
//     <4=> FTM0_CH0<selection=FTM0_CH0_PIN_SEL,PTC1>
//     <5=> FB_AD13<selection=FB_AD13_PIN_SEL,PTC1>
//     <6=> I2S0_TXD0<selection=I2S0_TXD0_PIN_SEL,PTC1>
//     <-2=> Default
#define PTC1_SIG_SEL         -2

// Signal mapping for PTC2 pin
//   <o> PTC2 (Alias:D6) [ADC0_SE4b/CMP1_IN0, GPIOC_2, SPI0_PCS2, UART1_CTS_b, FTM0_CH1, FB_AD12, I2S0_TX_FS]<name=PTC2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC2 pin
//     <-2=> ADC0_SE4b/CMP1_IN0 (reset default)<selection=ADC0_SE4b_PIN_SEL,PTC2 (Alias:D6) (reset default)><selection=CMP1_IN0_PIN_SEL,PTC2 (Alias:D6) (reset default)>
//     <0=> ADC0_SE4b/CMP1_IN0<selection=ADC0_SE4b_PIN_SEL,PTC2 (Alias:D6)><selection=CMP1_IN0_PIN_SEL,PTC2 (Alias:D6)>
//     <1=> GPIOC_2<selection=GPIOC_2_PIN_SEL,PTC2 (Alias:D6)>
//     <2=> SPI0_PCS2<selection=SPI0_PCS2_PIN_SEL,PTC2 (Alias:D6)>
//     <3=> UART1_CTS_b<selection=UART1_CTS_b_PIN_SEL,PTC2 (Alias:D6)>
//     <4=> FTM0_CH1<selection=FTM0_CH1_PIN_SEL,PTC2 (Alias:D6)>
//     <5=> FB_AD12<selection=FB_AD12_PIN_SEL,PTC2 (Alias:D6)>
//     <6=> I2S0_TX_FS<selection=I2S0_TX_FS_PIN_SEL,PTC2 (Alias:D6)>
//     <1=> Default
#define PTC2_SIG_SEL         1

// Signal mapping for PTC3 pin
//   <o> PTC3 (Alias:D7) [CMP1_IN1, GPIOC_3/LLWU_P7, SPI0_PCS1, UART1_RX, FTM0_CH2, CLKOUT, I2S0_TX_BCLK]<name=PTC3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC3 pin
//     <-2=> CMP1_IN1 (reset default)<selection=CMP1_IN1_PIN_SEL,PTC3 (Alias:D7) (reset default)>
//     <0=> CMP1_IN1<selection=CMP1_IN1_PIN_SEL,PTC3 (Alias:D7)>
//     <1=> GPIOC_3/LLWU_P7<selection=GPIOC_3_PIN_SEL,PTC3 (Alias:D7)><selection=LLWU_P7_PIN_SEL,PTC3 (Alias:D7)>
//     <2=> SPI0_PCS1<selection=SPI0_PCS1_PIN_SEL,PTC3 (Alias:D7)>
//     <3=> UART1_RX<selection=UART1_RX_PIN_SEL,PTC3 (Alias:D7)>
//     <4=> FTM0_CH2<selection=FTM0_CH2_PIN_SEL,PTC3 (Alias:D7)>
//     <5=> CLKOUT<selection=CLKOUT_PIN_SEL,PTC3 (Alias:D7)>
//     <6=> I2S0_TX_BCLK<selection=I2S0_TX_BCLK_PIN_SEL,PTC3 (Alias:D7)>
//     <1=> Default
#define PTC3_SIG_SEL         1

// Signal mapping for PTC4 pin
//   <o> PTC4 (Alias:D9) [GPIOC_4/LLWU_P8, SPI0_PCS0, UART1_TX, FTM0_CH3, FB_AD11, CMP1_OUT]<name=PTC4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC4 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_4/LLWU_P8<selection=GPIOC_4_PIN_SEL,PTC4 (Alias:D9)><selection=LLWU_P8_PIN_SEL,PTC4 (Alias:D9)>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTC4 (Alias:D9)>
//     <3=> UART1_TX<selection=UART1_TX_PIN_SEL,PTC4 (Alias:D9)>
//     <4=> FTM0_CH3<selection=FTM0_CH3_PIN_SEL,PTC4 (Alias:D9)>
//     <5=> FB_AD11<selection=FB_AD11_PIN_SEL,PTC4 (Alias:D9)>
//     <6=> CMP1_OUT<selection=CMP1_OUT_PIN_SEL,PTC4 (Alias:D9)>
//     <1=> Default
#define PTC4_SIG_SEL         1

// Signal mapping for PTC5 pin
//   <o> PTC5 [GPIOC_5/LLWU_P9, SPI0_SCK, LPTMR0_ALT2, I2S0_RXD0, FB_AD10, CMP0_OUT, FTM0_CH2]<name=PTC5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC5 pin
//     <-2=> Disabled (reset default)
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
//     <-2=> CMP0_IN0 (reset default)<selection=CMP0_IN0_PIN_SEL,PTC6 (reset default)>
//     <0=> CMP0_IN0<selection=CMP0_IN0_PIN_SEL,PTC6>
//     <1=> GPIOC_6/LLWU_P10<selection=GPIOC_6_PIN_SEL,PTC6><selection=LLWU_P10_PIN_SEL,PTC6>
//     <2=> SPI0_SOUT<selection=SPI0_SOUT_PIN_SEL,PTC6>
//     <3=> PDB0_EXTRG<selection=PDB0_EXTRG_PIN_SEL,PTC6>
//     <4=> I2S0_RX_BCLK<selection=I2S0_RX_BCLK_PIN_SEL,PTC6>
//     <5=> FB_AD9<selection=FB_AD9_PIN_SEL,PTC6>
//     <6=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTC6>
//     <-2=> Default
#define PTC6_SIG_SEL         -2

// Signal mapping for PTC7 pin
//   <o> PTC7 [CMP0_IN1, GPIOC_7, SPI0_SIN, USB_SOF_OUT, I2S0_RX_FS, FB_AD8]<name=PTC7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC7 pin
//     <-2=> CMP0_IN1 (reset default)<selection=CMP0_IN1_PIN_SEL,PTC7 (reset default)>
//     <0=> CMP0_IN1<selection=CMP0_IN1_PIN_SEL,PTC7>
//     <1=> GPIOC_7<selection=GPIOC_7_PIN_SEL,PTC7>
//     <2=> SPI0_SIN<selection=SPI0_SIN_PIN_SEL,PTC7>
//     <3=> USB_SOF_OUT<selection=USB_SOF_OUT_PIN_SEL,PTC7>
//     <4=> I2S0_RX_FS<selection=I2S0_RX_FS_PIN_SEL,PTC7>
//     <5=> FB_AD8<selection=FB_AD8_PIN_SEL,PTC7>
//     <-2=> Default
#define PTC7_SIG_SEL         -2

// Signal mapping for PTC8 pin
//   <o> PTC8 [ADC1_SE4b/CMP0_IN2, GPIOC_8, FTM3_CH4, I2S0_MCLK, FB_AD7]<name=PTC8_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC8 pin
//     <-2=> ADC1_SE4b/CMP0_IN2 (reset default)<selection=ADC1_SE4b_PIN_SEL,PTC8 (reset default)><selection=CMP0_IN2_PIN_SEL,PTC8 (reset default)>
//     <0=> ADC1_SE4b/CMP0_IN2<selection=ADC1_SE4b_PIN_SEL,PTC8><selection=CMP0_IN2_PIN_SEL,PTC8>
//     <1=> GPIOC_8<selection=GPIOC_8_PIN_SEL,PTC8>
//     <3=> FTM3_CH4<selection=FTM3_CH4_PIN_SEL,PTC8>
//     <4=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTC8>
//     <5=> FB_AD7<selection=FB_AD7_PIN_SEL,PTC8>
//     <-2=> Default
#define PTC8_SIG_SEL         -2

// Signal mapping for PTC9 pin
//   <o> PTC9 [ADC1_SE5b/CMP0_IN3, GPIOC_9, FTM3_CH5, I2S0_RX_BCLK, FB_AD6, FTM2_FLT0]<name=PTC9_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC9 pin
//     <-2=> ADC1_SE5b/CMP0_IN3 (reset default)<selection=ADC1_SE5b_PIN_SEL,PTC9 (reset default)><selection=CMP0_IN3_PIN_SEL,PTC9 (reset default)>
//     <0=> ADC1_SE5b/CMP0_IN3<selection=ADC1_SE5b_PIN_SEL,PTC9><selection=CMP0_IN3_PIN_SEL,PTC9>
//     <1=> GPIOC_9<selection=GPIOC_9_PIN_SEL,PTC9>
//     <3=> FTM3_CH5<selection=FTM3_CH5_PIN_SEL,PTC9>
//     <4=> I2S0_RX_BCLK<selection=I2S0_RX_BCLK_PIN_SEL,PTC9>
//     <5=> FB_AD6<selection=FB_AD6_PIN_SEL,PTC9>
//     <6=> FTM2_FLT0<selection=FTM2_FLT0_PIN_SEL,PTC9>
//     <-2=> Default
#define PTC9_SIG_SEL         -2

// Signal mapping for PTC10 pin
//   <o> PTC10 (Alias:A5) [ADC1_SE6b, GPIOC_10, I2C1_SCL, FTM3_CH6, I2S0_RX_FS, FB_AD5]<name=PTC10_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC10 pin
//     <-2=> ADC1_SE6b (reset default)<selection=ADC1_SE6b_PIN_SEL,PTC10 (Alias:A5) (reset default)>
//     <0=> ADC1_SE6b<selection=ADC1_SE6b_PIN_SEL,PTC10 (Alias:A5)>
//     <1=> GPIOC_10<selection=GPIOC_10_PIN_SEL,PTC10 (Alias:A5)>
//     <2=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTC10 (Alias:A5)>
//     <3=> FTM3_CH6<selection=FTM3_CH6_PIN_SEL,PTC10 (Alias:A5)>
//     <4=> I2S0_RX_FS<selection=I2S0_RX_FS_PIN_SEL,PTC10 (Alias:A5)>
//     <5=> FB_AD5<selection=FB_AD5_PIN_SEL,PTC10 (Alias:A5)>
//     <1=> Default
#define PTC10_SIG_SEL        1

// Signal mapping for PTC11 pin
//   <o> PTC11 (Alias:A4) [ADC1_SE7b, GPIOC_11/LLWU_P11, I2C1_SDA, FTM3_CH7, I2S0_RXD1, FB_RW_b]<name=PTC11_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC11 pin
//     <-2=> ADC1_SE7b (reset default)<selection=ADC1_SE7b_PIN_SEL,PTC11 (Alias:A4) (reset default)>
//     <0=> ADC1_SE7b<selection=ADC1_SE7b_PIN_SEL,PTC11 (Alias:A4)>
//     <1=> GPIOC_11/LLWU_P11<selection=GPIOC_11_PIN_SEL,PTC11 (Alias:A4)><selection=LLWU_P11_PIN_SEL,PTC11 (Alias:A4)>
//     <2=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTC11 (Alias:A4)>
//     <3=> FTM3_CH7<selection=FTM3_CH7_PIN_SEL,PTC11 (Alias:A4)>
//     <4=> I2S0_RXD1<selection=I2S0_RXD1_PIN_SEL,PTC11 (Alias:A4)>
//     <5=> FB_RW_b<selection=FB_RW_b_PIN_SEL,PTC11 (Alias:A4)>
//     <1=> Default
#define PTC11_SIG_SEL        1

// Signal mapping for PTC12 pin
//   <o> PTC12 [GPIOC_12, UART4_RTS_b, FB_AD27, FTM3_FLT0]<name=PTC12_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC12 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_12<selection=GPIOC_12_PIN_SEL,PTC12>
//     <3=> UART4_RTS_b<selection=UART4_RTS_b_PIN_SEL,PTC12>
//     <5=> FB_AD27<selection=FB_AD27_PIN_SEL,PTC12>
//     <6=> FTM3_FLT0<selection=FTM3_FLT0_PIN_SEL,PTC12>
//     <-2=> Default
#define PTC12_SIG_SEL        -2

// Signal mapping for PTC13 pin
//   <o> PTC13 [GPIOC_13, UART4_CTS_b, FB_AD26]<name=PTC13_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC13 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_13<selection=GPIOC_13_PIN_SEL,PTC13>
//     <3=> UART4_CTS_b<selection=UART4_CTS_b_PIN_SEL,PTC13>
//     <5=> FB_AD26<selection=FB_AD26_PIN_SEL,PTC13>
//     <-2=> Default
#define PTC13_SIG_SEL        -2

// Signal mapping for PTC14 pin
//   <o> PTC14 [GPIOC_14, UART4_RX, FB_AD25]<name=PTC14_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC14 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_14<selection=GPIOC_14_PIN_SEL,PTC14>
//     <3=> UART4_RX<selection=UART4_RX_PIN_SEL,PTC14>
//     <5=> FB_AD25<selection=FB_AD25_PIN_SEL,PTC14>
//     <-2=> Default
#define PTC14_SIG_SEL        -2

// Signal mapping for PTC15 pin
//   <o> PTC15 [GPIOC_15, UART4_TX, FB_AD24]<name=PTC15_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC15 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_15<selection=GPIOC_15_PIN_SEL,PTC15>
//     <3=> UART4_TX<selection=UART4_TX_PIN_SEL,PTC15>
//     <5=> FB_AD24<selection=FB_AD24_PIN_SEL,PTC15>
//     <-2=> Default
#define PTC15_SIG_SEL        -2

// Signal mapping for PTC16 pin
//   <o> PTC16 (Alias:D0) [GPIOC_16, UART3_RX, ENET0_1588_TMR0, FB_CS5_b/FB_TSIZ1/FB_BE23_16_BLS15_8_b]<name=PTC16_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC16 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_16<selection=GPIOC_16_PIN_SEL,PTC16 (Alias:D0)>
//     <3=> UART3_RX<selection=UART3_RX_PIN_SEL,PTC16 (Alias:D0)>
//     <4=> ENET0_1588_TMR0<selection=ENET0_1588_TMR0_PIN_SEL,PTC16 (Alias:D0)>
//     <5=> FB_CS5_b/FB_TSIZ1/FB_BE23_16_BLS15_8_b<selection=FB_CS5_b_PIN_SEL,PTC16 (Alias:D0)><selection=FB_TSIZ1_PIN_SEL,PTC16 (Alias:D0)><selection=FB_BE23_16_BLS15_8_b_PIN_SEL,PTC16 (Alias:D0)>
//     <-2=> Default
#define PTC16_SIG_SEL        -2

// Signal mapping for PTC17 pin
//   <o> PTC17 (Alias:D1) [GPIOC_17, UART3_TX, ENET0_1588_TMR1, FB_CS4_b/FB_TSIZ0/FB_BE31_24_BLS7_0_b]<name=PTC17_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC17 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_17<selection=GPIOC_17_PIN_SEL,PTC17 (Alias:D1)>
//     <3=> UART3_TX<selection=UART3_TX_PIN_SEL,PTC17 (Alias:D1)>
//     <4=> ENET0_1588_TMR1<selection=ENET0_1588_TMR1_PIN_SEL,PTC17 (Alias:D1)>
//     <5=> FB_CS4_b/FB_TSIZ0/FB_BE31_24_BLS7_0_b<selection=FB_CS4_b_PIN_SEL,PTC17 (Alias:D1)><selection=FB_TSIZ0_PIN_SEL,PTC17 (Alias:D1)><selection=FB_BE31_24_BLS7_0_b_PIN_SEL,PTC17 (Alias:D1)>
//     <-2=> Default
#define PTC17_SIG_SEL        -2

// Signal mapping for PTC18 pin
//   <o> PTC18 [GPIOC_18, UART3_RTS_b, ENET0_1588_TMR2, FB_TBST_b/FB_CS2_b/FB_BE15_8_BLS23_16_b]<name=PTC18_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC18 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_18<selection=GPIOC_18_PIN_SEL,PTC18>
//     <3=> UART3_RTS_b<selection=UART3_RTS_b_PIN_SEL,PTC18>
//     <4=> ENET0_1588_TMR2<selection=ENET0_1588_TMR2_PIN_SEL,PTC18>
//     <5=> FB_TBST_b/FB_CS2_b/FB_BE15_8_BLS23_16_b<selection=FB_TBST_b_PIN_SEL,PTC18><selection=FB_CS2_b_PIN_SEL,PTC18><selection=FB_BE15_8_BLS23_16_b_PIN_SEL,PTC18>
//     <-2=> Default
#define PTC18_SIG_SEL        -2

// Signal mapping for PTC19 pin
//   <o> PTC19 [GPIOC_19, UART3_CTS_b, ENET0_1588_TMR3, FB_CS3_b/FB_BE7_0_BLS31_24_b, FB_TA_b]<name=PTC19_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTC19 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_19<selection=GPIOC_19_PIN_SEL,PTC19>
//     <3=> UART3_CTS_b<selection=UART3_CTS_b_PIN_SEL,PTC19>
//     <4=> ENET0_1588_TMR3<selection=ENET0_1588_TMR3_PIN_SEL,PTC19>
//     <5=> FB_CS3_b/FB_BE7_0_BLS31_24_b<selection=FB_CS3_b_PIN_SEL,PTC19><selection=FB_BE7_0_BLS31_24_b_PIN_SEL,PTC19>
//     <6=> FB_TA_b<selection=FB_TA_b_PIN_SEL,PTC19>
//     <-2=> Default
#define PTC19_SIG_SEL        -2

// </h>

// <h> Port D Pins

// Signal mapping for PTD0 pin
//   <o> PTD0 (Alias:D10) [GPIOD_0/LLWU_P12, SPI0_PCS0, UART2_RTS_b, FTM3_CH0, FB_ALE/FB_CS1_b/FB_TS_b]<name=PTD0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD0 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_0/LLWU_P12<selection=GPIOD_0_PIN_SEL,PTD0 (Alias:D10)><selection=LLWU_P12_PIN_SEL,PTD0 (Alias:D10)>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTD0 (Alias:D10)>
//     <3=> UART2_RTS_b<selection=UART2_RTS_b_PIN_SEL,PTD0 (Alias:D10)>
//     <4=> FTM3_CH0<selection=FTM3_CH0_PIN_SEL,PTD0 (Alias:D10)>
//     <5=> FB_ALE/FB_CS1_b/FB_TS_b<selection=FB_ALE_PIN_SEL,PTD0 (Alias:D10)><selection=FB_CS1_b_PIN_SEL,PTD0 (Alias:D10)><selection=FB_TS_b_PIN_SEL,PTD0 (Alias:D10)>
//     <1=> Default
#define PTD0_SIG_SEL         1

// Signal mapping for PTD1 pin
//   <o> PTD1 (Alias:D13) [ADC0_SE5b, GPIOD_1, SPI0_SCK, UART2_CTS_b, FTM3_CH1, FB_CS0_b]<name=PTD1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD1 pin
//     <-2=> ADC0_SE5b (reset default)<selection=ADC0_SE5b_PIN_SEL,PTD1 (Alias:D13) (reset default)>
//     <0=> ADC0_SE5b<selection=ADC0_SE5b_PIN_SEL,PTD1 (Alias:D13)>
//     <1=> GPIOD_1<selection=GPIOD_1_PIN_SEL,PTD1 (Alias:D13)>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTD1 (Alias:D13)>
//     <3=> UART2_CTS_b<selection=UART2_CTS_b_PIN_SEL,PTD1 (Alias:D13)>
//     <4=> FTM3_CH1<selection=FTM3_CH1_PIN_SEL,PTD1 (Alias:D13)>
//     <5=> FB_CS0_b<selection=FB_CS0_b_PIN_SEL,PTD1 (Alias:D13)>
//     <1=> Default
#define PTD1_SIG_SEL         1

// Signal mapping for PTD2 pin
//   <o> PTD2 (Alias:D11) [GPIOD_2/LLWU_P13, SPI0_SOUT, UART2_RX, FTM3_CH2, FB_AD4, I2C0_SCL]<name=PTD2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD2 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_2/LLWU_P13<selection=GPIOD_2_PIN_SEL,PTD2 (Alias:D11)><selection=LLWU_P13_PIN_SEL,PTD2 (Alias:D11)>
//     <2=> SPI0_SOUT<selection=SPI0_SOUT_PIN_SEL,PTD2 (Alias:D11)>
//     <3=> UART2_RX<selection=UART2_RX_PIN_SEL,PTD2 (Alias:D11)>
//     <4=> FTM3_CH2<selection=FTM3_CH2_PIN_SEL,PTD2 (Alias:D11)>
//     <5=> FB_AD4<selection=FB_AD4_PIN_SEL,PTD2 (Alias:D11)>
//     <7=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTD2 (Alias:D11)>
//     <1=> Default
#define PTD2_SIG_SEL         1

// Signal mapping for PTD3 pin
//   <o> PTD3 (Alias:D12) [GPIOD_3, SPI0_SIN, UART2_TX, FTM3_CH3, FB_AD3, I2C0_SDA]<name=PTD3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD3 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_3<selection=GPIOD_3_PIN_SEL,PTD3 (Alias:D12)>
//     <2=> SPI0_SIN<selection=SPI0_SIN_PIN_SEL,PTD3 (Alias:D12)>
//     <3=> UART2_TX<selection=UART2_TX_PIN_SEL,PTD3 (Alias:D12)>
//     <4=> FTM3_CH3<selection=FTM3_CH3_PIN_SEL,PTD3 (Alias:D12)>
//     <5=> FB_AD3<selection=FB_AD3_PIN_SEL,PTD3 (Alias:D12)>
//     <7=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTD3 (Alias:D12)>
//     <1=> Default
#define PTD3_SIG_SEL         1

// Signal mapping for PTD4 pin
//   <o> PTD4 (Alias:nRF24L01_cs) [GPIOD_4/LLWU_P14, SPI0_PCS1, UART0_RTS_b, FTM0_CH4, FB_AD2, EWM_IN, SPI1_PCS0]<name=PTD4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD4 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_4/LLWU_P14<selection=GPIOD_4_PIN_SEL,PTD4 (Alias:nRF24L01_cs)><selection=LLWU_P14_PIN_SEL,PTD4 (Alias:nRF24L01_cs)>
//     <2=> SPI0_PCS1<selection=SPI0_PCS1_PIN_SEL,PTD4 (Alias:nRF24L01_cs)>
//     <3=> UART0_RTS_b<selection=UART0_RTS_b_PIN_SEL,PTD4 (Alias:nRF24L01_cs)>
//     <4=> FTM0_CH4<selection=FTM0_CH4_PIN_SEL,PTD4 (Alias:nRF24L01_cs)>
//     <5=> FB_AD2<selection=FB_AD2_PIN_SEL,PTD4 (Alias:nRF24L01_cs)>
//     <6=> EWM_IN<selection=EWM_IN_PIN_SEL,PTD4 (Alias:nRF24L01_cs)>
//     <7=> SPI1_PCS0<selection=SPI1_PCS0_PIN_SEL,PTD4 (Alias:nRF24L01_cs)>
//     <7=> Default
#define PTD4_SIG_SEL         7

// Signal mapping for PTD5 pin
//   <o> PTD5 (Alias:nRF24L01_sck) [ADC0_SE6b, GPIOD_5, SPI0_PCS2, UART0_CTS_b/UART0_COL_b, FTM0_CH5, FB_AD1, EWM_OUT_b, SPI1_SCK]<name=PTD5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD5 pin
//     <-2=> ADC0_SE6b (reset default)<selection=ADC0_SE6b_PIN_SEL,PTD5 (Alias:nRF24L01_sck) (reset default)>
//     <0=> ADC0_SE6b<selection=ADC0_SE6b_PIN_SEL,PTD5 (Alias:nRF24L01_sck)>
//     <1=> GPIOD_5<selection=GPIOD_5_PIN_SEL,PTD5 (Alias:nRF24L01_sck)>
//     <2=> SPI0_PCS2<selection=SPI0_PCS2_PIN_SEL,PTD5 (Alias:nRF24L01_sck)>
//     <3=> UART0_CTS_b/UART0_COL_b<selection=UART0_CTS_b_PIN_SEL,PTD5 (Alias:nRF24L01_sck)><selection=UART0_COL_b_PIN_SEL,PTD5 (Alias:nRF24L01_sck)>
//     <4=> FTM0_CH5<selection=FTM0_CH5_PIN_SEL,PTD5 (Alias:nRF24L01_sck)>
//     <5=> FB_AD1<selection=FB_AD1_PIN_SEL,PTD5 (Alias:nRF24L01_sck)>
//     <6=> EWM_OUT_b<selection=EWM_OUT_b_PIN_SEL,PTD5 (Alias:nRF24L01_sck)>
//     <7=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTD5 (Alias:nRF24L01_sck)>
//     <7=> Default
#define PTD5_SIG_SEL         7

// Signal mapping for PTD6 pin
//   <o> PTD6 (Alias:nRF24L01_mosi) [ADC0_SE7b, GPIOD_6/LLWU_P15, SPI0_PCS3, UART0_RX, FTM0_CH6, FB_AD0, FTM0_FLT0, SPI1_SOUT]<name=PTD6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD6 pin
//     <-2=> ADC0_SE7b (reset default)<selection=ADC0_SE7b_PIN_SEL,PTD6 (Alias:nRF24L01_mosi) (reset default)>
//     <0=> ADC0_SE7b<selection=ADC0_SE7b_PIN_SEL,PTD6 (Alias:nRF24L01_mosi)>
//     <1=> GPIOD_6/LLWU_P15<selection=GPIOD_6_PIN_SEL,PTD6 (Alias:nRF24L01_mosi)><selection=LLWU_P15_PIN_SEL,PTD6 (Alias:nRF24L01_mosi)>
//     <2=> SPI0_PCS3<selection=SPI0_PCS3_PIN_SEL,PTD6 (Alias:nRF24L01_mosi)>
//     <3=> UART0_RX<selection=UART0_RX_PIN_SEL,PTD6 (Alias:nRF24L01_mosi)>
//     <4=> FTM0_CH6<selection=FTM0_CH6_PIN_SEL,PTD6 (Alias:nRF24L01_mosi)>
//     <5=> FB_AD0<selection=FB_AD0_PIN_SEL,PTD6 (Alias:nRF24L01_mosi)>
//     <6=> FTM0_FLT0<selection=FTM0_FLT0_PIN_SEL,PTD6 (Alias:nRF24L01_mosi)>
//     <7=> SPI1_SOUT<selection=SPI1_SOUT_PIN_SEL,PTD6 (Alias:nRF24L01_mosi)>
//     <7=> Default
#define PTD6_SIG_SEL         7

// Signal mapping for PTD7 pin
//   <o> PTD7 (Alias:nRF24L01_miso) [GPIOD_7, CMT_IRO, UART0_TX, FTM0_CH7, FTM0_FLT1, SPI1_SIN]<name=PTD7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD7 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_7<selection=GPIOD_7_PIN_SEL,PTD7 (Alias:nRF24L01_miso)>
//     <2=> CMT_IRO<selection=CMT_IRO_PIN_SEL,PTD7 (Alias:nRF24L01_miso)>
//     <3=> UART0_TX<selection=UART0_TX_PIN_SEL,PTD7 (Alias:nRF24L01_miso)>
//     <4=> FTM0_CH7<selection=FTM0_CH7_PIN_SEL,PTD7 (Alias:nRF24L01_miso)>
//     <6=> FTM0_FLT1<selection=FTM0_FLT1_PIN_SEL,PTD7 (Alias:nRF24L01_miso)>
//     <7=> SPI1_SIN<selection=SPI1_SIN_PIN_SEL,PTD7 (Alias:nRF24L01_miso)>
//     <7=> Default
#define PTD7_SIG_SEL         7

// Signal mapping for PTD8 pin
//   <o> PTD8 [GPIOD_8, I2C0_SCL, UART5_RX, FB_A16]<name=PTD8_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD8 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_8<selection=GPIOD_8_PIN_SEL,PTD8>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTD8>
//     <3=> UART5_RX<selection=UART5_RX_PIN_SEL,PTD8>
//     <6=> FB_A16<selection=FB_A16_PIN_SEL,PTD8>
//     <-2=> Default
#define PTD8_SIG_SEL         -2

// Signal mapping for PTD9 pin
//   <o> PTD9 [GPIOD_9, I2C0_SDA, UART5_TX, FB_A17]<name=PTD9_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD9 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_9<selection=GPIOD_9_PIN_SEL,PTD9>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTD9>
//     <3=> UART5_TX<selection=UART5_TX_PIN_SEL,PTD9>
//     <6=> FB_A17<selection=FB_A17_PIN_SEL,PTD9>
//     <-2=> Default
#define PTD9_SIG_SEL         -2

// Signal mapping for PTD10 pin
//   <o> PTD10 [GPIOD_10, UART5_RTS_b, FB_A18]<name=PTD10_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD10 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_10<selection=GPIOD_10_PIN_SEL,PTD10>
//     <3=> UART5_RTS_b<selection=UART5_RTS_b_PIN_SEL,PTD10>
//     <6=> FB_A18<selection=FB_A18_PIN_SEL,PTD10>
//     <-2=> Default
#define PTD10_SIG_SEL        -2

// Signal mapping for PTD11 pin
//   <o> PTD11 [GPIOD_11, SPI2_PCS0, UART5_CTS_b, SDHC0_CLKIN, FB_A19]<name=PTD11_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD11 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_11<selection=GPIOD_11_PIN_SEL,PTD11>
//     <2=> SPI2_PCS0<selection=SPI2_PCS0_PIN_SEL,PTD11>
//     <3=> UART5_CTS_b<selection=UART5_CTS_b_PIN_SEL,PTD11>
//     <4=> SDHC0_CLKIN<selection=SDHC0_CLKIN_PIN_SEL,PTD11>
//     <6=> FB_A19<selection=FB_A19_PIN_SEL,PTD11>
//     <-2=> Default
#define PTD11_SIG_SEL        -2

// Signal mapping for PTD12 pin
//   <o> PTD12 [GPIOD_12, SPI2_SCK, FTM3_FLT0, SDHC0_D4, FB_A20]<name=PTD12_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD12 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_12<selection=GPIOD_12_PIN_SEL,PTD12>
//     <2=> SPI2_SCK<selection=SPI2_SCK_PIN_SEL,PTD12>
//     <3=> FTM3_FLT0<selection=FTM3_FLT0_PIN_SEL,PTD12>
//     <4=> SDHC0_D4<selection=SDHC0_D4_PIN_SEL,PTD12>
//     <6=> FB_A20<selection=FB_A20_PIN_SEL,PTD12>
//     <-2=> Default
#define PTD12_SIG_SEL        -2

// Signal mapping for PTD13 pin
//   <o> PTD13 [GPIOD_13, SPI2_SOUT, SDHC0_D5, FB_A21]<name=PTD13_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD13 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_13<selection=GPIOD_13_PIN_SEL,PTD13>
//     <2=> SPI2_SOUT<selection=SPI2_SOUT_PIN_SEL,PTD13>
//     <4=> SDHC0_D5<selection=SDHC0_D5_PIN_SEL,PTD13>
//     <6=> FB_A21<selection=FB_A21_PIN_SEL,PTD13>
//     <-2=> Default
#define PTD13_SIG_SEL        -2

// Signal mapping for PTD14 pin
//   <o> PTD14 [GPIOD_14, SPI2_SIN, SDHC0_D6, FB_A22]<name=PTD14_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD14 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_14<selection=GPIOD_14_PIN_SEL,PTD14>
//     <2=> SPI2_SIN<selection=SPI2_SIN_PIN_SEL,PTD14>
//     <4=> SDHC0_D6<selection=SDHC0_D6_PIN_SEL,PTD14>
//     <6=> FB_A22<selection=FB_A22_PIN_SEL,PTD14>
//     <-2=> Default
#define PTD14_SIG_SEL        -2

// Signal mapping for PTD15 pin
//   <o> PTD15 [GPIOD_15, SPI2_PCS1, SDHC0_D7, FB_A23]<name=PTD15_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTD15 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_15<selection=GPIOD_15_PIN_SEL,PTD15>
//     <2=> SPI2_PCS1<selection=SPI2_PCS1_PIN_SEL,PTD15>
//     <4=> SDHC0_D7<selection=SDHC0_D7_PIN_SEL,PTD15>
//     <6=> FB_A23<selection=FB_A23_PIN_SEL,PTD15>
//     <-2=> Default
#define PTD15_SIG_SEL        -2

// </h>

// <h> Port E Pins

// Signal mapping for PTE0 pin
//   <o> PTE0 [ADC1_SE4a, GPIOE_0, SPI1_PCS1, UART1_TX, SDHC0_D1, TRACE_CLKOUT, I2C1_SDA, RTC_CLKOUT]<name=PTE0_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE0 pin
//     <-2=> ADC1_SE4a (reset default)<selection=ADC1_SE4a_PIN_SEL,PTE0 (reset default)>
//     <0=> ADC1_SE4a<selection=ADC1_SE4a_PIN_SEL,PTE0>
//     <1=> GPIOE_0<selection=GPIOE_0_PIN_SEL,PTE0>
//     <2=> SPI1_PCS1<selection=SPI1_PCS1_PIN_SEL,PTE0>
//     <3=> UART1_TX<selection=UART1_TX_PIN_SEL,PTE0>
//     <4=> SDHC0_D1<selection=SDHC0_D1_PIN_SEL,PTE0>
//     <5=> TRACE_CLKOUT<selection=TRACE_CLKOUT_PIN_SEL,PTE0>
//     <6=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTE0>
//     <7=> RTC_CLKOUT<selection=RTC_CLKOUT_PIN_SEL,PTE0>
//     <-2=> Default
#define PTE0_SIG_SEL         -2

// Signal mapping for PTE1 pin
//   <o> PTE1 [ADC1_SE5a, GPIOE_1/LLWU_P0, SPI1_SOUT, UART1_RX, SDHC0_D0, TRACE_D3, I2C1_SCL, SPI1_SIN]<name=PTE1_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE1 pin
//     <-2=> ADC1_SE5a (reset default)<selection=ADC1_SE5a_PIN_SEL,PTE1 (reset default)>
//     <0=> ADC1_SE5a<selection=ADC1_SE5a_PIN_SEL,PTE1>
//     <1=> GPIOE_1/LLWU_P0<selection=GPIOE_1_PIN_SEL,PTE1><selection=LLWU_P0_PIN_SEL,PTE1>
//     <2=> SPI1_SOUT<selection=SPI1_SOUT_PIN_SEL,PTE1>
//     <3=> UART1_RX<selection=UART1_RX_PIN_SEL,PTE1>
//     <4=> SDHC0_D0<selection=SDHC0_D0_PIN_SEL,PTE1>
//     <5=> TRACE_D3<selection=TRACE_D3_PIN_SEL,PTE1>
//     <6=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTE1>
//     <7=> SPI1_SIN<selection=SPI1_SIN_PIN_SEL,PTE1>
//     <-2=> Default
#define PTE1_SIG_SEL         -2

// Signal mapping for PTE2 pin
//   <o> PTE2 [ADC0_DP2/ADC1_SE6a/ADC0_SE2, GPIOE_2/LLWU_P1, SPI1_SCK, UART1_CTS_b, SDHC0_DCLK, TRACE_D2]<name=PTE2_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE2 pin
//     <-2=> ADC0_DP2/ADC1_SE6a/ADC0_SE2 (reset default)<selection=ADC0_DP2_PIN_SEL,PTE2 (reset default)><selection=ADC1_SE6a_PIN_SEL,PTE2 (reset default)><selection=ADC0_SE2_PIN_SEL,PTE2 (reset default)>
//     <0=> ADC0_DP2/ADC1_SE6a/ADC0_SE2<selection=ADC0_DP2_PIN_SEL,PTE2><selection=ADC1_SE6a_PIN_SEL,PTE2><selection=ADC0_SE2_PIN_SEL,PTE2>
//     <1=> GPIOE_2/LLWU_P1<selection=GPIOE_2_PIN_SEL,PTE2><selection=LLWU_P1_PIN_SEL,PTE2>
//     <2=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTE2>
//     <3=> UART1_CTS_b<selection=UART1_CTS_b_PIN_SEL,PTE2>
//     <4=> SDHC0_DCLK<selection=SDHC0_DCLK_PIN_SEL,PTE2>
//     <5=> TRACE_D2<selection=TRACE_D2_PIN_SEL,PTE2>
//     <-2=> Default
#define PTE2_SIG_SEL         -2

// Signal mapping for PTE3 pin
//   <o> PTE3 [ADC0_DM2/ADC1_SE7a, GPIOE_3, SPI1_SIN, UART1_RTS_b, SDHC0_CMD, TRACE_D1, SPI1_SOUT]<name=PTE3_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE3 pin
//     <-2=> ADC0_DM2/ADC1_SE7a (reset default)<selection=ADC0_DM2_PIN_SEL,PTE3 (reset default)><selection=ADC1_SE7a_PIN_SEL,PTE3 (reset default)>
//     <0=> ADC0_DM2/ADC1_SE7a<selection=ADC0_DM2_PIN_SEL,PTE3><selection=ADC1_SE7a_PIN_SEL,PTE3>
//     <1=> GPIOE_3<selection=GPIOE_3_PIN_SEL,PTE3>
//     <2=> SPI1_SIN<selection=SPI1_SIN_PIN_SEL,PTE3>
//     <3=> UART1_RTS_b<selection=UART1_RTS_b_PIN_SEL,PTE3>
//     <4=> SDHC0_CMD<selection=SDHC0_CMD_PIN_SEL,PTE3>
//     <5=> TRACE_D1<selection=TRACE_D1_PIN_SEL,PTE3>
//     <7=> SPI1_SOUT<selection=SPI1_SOUT_PIN_SEL,PTE3>
//     <-2=> Default
#define PTE3_SIG_SEL         -2

// Signal mapping for PTE4 pin
//   <o> PTE4 [GPIOE_4/LLWU_P2, SPI1_PCS0, UART3_TX, SDHC0_D3, TRACE_D0]<name=PTE4_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE4 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_4/LLWU_P2<selection=GPIOE_4_PIN_SEL,PTE4><selection=LLWU_P2_PIN_SEL,PTE4>
//     <2=> SPI1_PCS0<selection=SPI1_PCS0_PIN_SEL,PTE4>
//     <3=> UART3_TX<selection=UART3_TX_PIN_SEL,PTE4>
//     <4=> SDHC0_D3<selection=SDHC0_D3_PIN_SEL,PTE4>
//     <5=> TRACE_D0<selection=TRACE_D0_PIN_SEL,PTE4>
//     <-2=> Default
#define PTE4_SIG_SEL         -2

// Signal mapping for PTE5 pin
//   <o> PTE5 [GPIOE_5, SPI1_PCS2, UART3_RX, SDHC0_D2, FTM3_CH0]<name=PTE5_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE5 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_5<selection=GPIOE_5_PIN_SEL,PTE5>
//     <2=> SPI1_PCS2<selection=SPI1_PCS2_PIN_SEL,PTE5>
//     <3=> UART3_RX<selection=UART3_RX_PIN_SEL,PTE5>
//     <4=> SDHC0_D2<selection=SDHC0_D2_PIN_SEL,PTE5>
//     <6=> FTM3_CH0<selection=FTM3_CH0_PIN_SEL,PTE5>
//     <-2=> Default
#define PTE5_SIG_SEL         -2

// Signal mapping for PTE6 pin
//   <o> PTE6 [GPIOE_6, SPI1_PCS3, UART3_CTS_b, I2S0_MCLK, FTM3_CH1, USB_SOF_OUT]<name=PTE6_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE6 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_6<selection=GPIOE_6_PIN_SEL,PTE6>
//     <2=> SPI1_PCS3<selection=SPI1_PCS3_PIN_SEL,PTE6>
//     <3=> UART3_CTS_b<selection=UART3_CTS_b_PIN_SEL,PTE6>
//     <4=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTE6>
//     <6=> FTM3_CH1<selection=FTM3_CH1_PIN_SEL,PTE6>
//     <7=> USB_SOF_OUT<selection=USB_SOF_OUT_PIN_SEL,PTE6>
//     <-2=> Default
#define PTE6_SIG_SEL         -2

// Signal mapping for PTE7 pin
//   <o> PTE7 [GPIOE_7, UART3_RTS_b, I2S0_RXD0, FTM3_CH2]<name=PTE7_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE7 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_7<selection=GPIOE_7_PIN_SEL,PTE7>
//     <3=> UART3_RTS_b<selection=UART3_RTS_b_PIN_SEL,PTE7>
//     <4=> I2S0_RXD0<selection=I2S0_RXD0_PIN_SEL,PTE7>
//     <6=> FTM3_CH2<selection=FTM3_CH2_PIN_SEL,PTE7>
//     <-2=> Default
#define PTE7_SIG_SEL         -2

// Signal mapping for PTE8 pin
//   <o> PTE8 [GPIOE_8, I2S0_RXD1, UART5_TX, I2S0_RX_FS, FTM3_CH3]<name=PTE8_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE8 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_8<selection=GPIOE_8_PIN_SEL,PTE8>
//     <2=> I2S0_RXD1<selection=I2S0_RXD1_PIN_SEL,PTE8>
//     <3=> UART5_TX<selection=UART5_TX_PIN_SEL,PTE8>
//     <4=> I2S0_RX_FS<selection=I2S0_RX_FS_PIN_SEL,PTE8>
//     <6=> FTM3_CH3<selection=FTM3_CH3_PIN_SEL,PTE8>
//     <-2=> Default
#define PTE8_SIG_SEL         -2

// Signal mapping for PTE9 pin
//   <o> PTE9 [GPIOE_9, I2S0_TXD1, UART5_RX, I2S0_RX_BCLK, FTM3_CH4]<name=PTE9_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE9 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_9<selection=GPIOE_9_PIN_SEL,PTE9>
//     <2=> I2S0_TXD1<selection=I2S0_TXD1_PIN_SEL,PTE9>
//     <3=> UART5_RX<selection=UART5_RX_PIN_SEL,PTE9>
//     <4=> I2S0_RX_BCLK<selection=I2S0_RX_BCLK_PIN_SEL,PTE9>
//     <6=> FTM3_CH4<selection=FTM3_CH4_PIN_SEL,PTE9>
//     <-2=> Default
#define PTE9_SIG_SEL         -2

// Signal mapping for PTE10 pin
//   <o> PTE10 [GPIOE_10, UART5_CTS_b, I2S0_TXD0, FTM3_CH5]<name=PTE10_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE10 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_10<selection=GPIOE_10_PIN_SEL,PTE10>
//     <3=> UART5_CTS_b<selection=UART5_CTS_b_PIN_SEL,PTE10>
//     <4=> I2S0_TXD0<selection=I2S0_TXD0_PIN_SEL,PTE10>
//     <6=> FTM3_CH5<selection=FTM3_CH5_PIN_SEL,PTE10>
//     <-2=> Default
#define PTE10_SIG_SEL        -2

// Signal mapping for PTE11 pin
//   <o> PTE11 [GPIOE_11, UART5_RTS_b, I2S0_TX_FS, FTM3_CH6]<name=PTE11_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE11 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_11<selection=GPIOE_11_PIN_SEL,PTE11>
//     <3=> UART5_RTS_b<selection=UART5_RTS_b_PIN_SEL,PTE11>
//     <4=> I2S0_TX_FS<selection=I2S0_TX_FS_PIN_SEL,PTE11>
//     <6=> FTM3_CH6<selection=FTM3_CH6_PIN_SEL,PTE11>
//     <-2=> Default
#define PTE11_SIG_SEL        -2

// Signal mapping for PTE12 pin
//   <o> PTE12 [GPIOE_12, I2S0_TX_BCLK, FTM3_CH7]<name=PTE12_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE12 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_12<selection=GPIOE_12_PIN_SEL,PTE12>
//     <4=> I2S0_TX_BCLK<selection=I2S0_TX_BCLK_PIN_SEL,PTE12>
//     <6=> FTM3_CH7<selection=FTM3_CH7_PIN_SEL,PTE12>
//     <-2=> Default
#define PTE12_SIG_SEL        -2

// Signal mapping for PTE24 pin
//   <o> PTE24 (Alias:D15) [ADC0_SE17, GPIOE_24, UART4_TX, I2C0_SCL, EWM_OUT_b]<name=PTE24_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE24 pin
//     <-2=> ADC0_SE17 (reset default)<selection=ADC0_SE17_PIN_SEL,PTE24 (Alias:D15) (reset default)>
//     <0=> ADC0_SE17<selection=ADC0_SE17_PIN_SEL,PTE24 (Alias:D15)>
//     <1=> GPIOE_24<selection=GPIOE_24_PIN_SEL,PTE24 (Alias:D15)>
//     <3=> UART4_TX<selection=UART4_TX_PIN_SEL,PTE24 (Alias:D15)>
//     <5=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTE24 (Alias:D15)>
//     <6=> EWM_OUT_b<selection=EWM_OUT_b_PIN_SEL,PTE24 (Alias:D15)>
//     <1=> Default
#define PTE24_SIG_SEL        1

// Signal mapping for PTE25 pin
//   <o> PTE25 (Alias:D14) [ADC0_SE18, GPIOE_25, UART4_RX, I2C0_SDA, EWM_IN]<name=PTE25_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE25 pin
//     <-2=> ADC0_SE18 (reset default)<selection=ADC0_SE18_PIN_SEL,PTE25 (Alias:D14) (reset default)>
//     <0=> ADC0_SE18<selection=ADC0_SE18_PIN_SEL,PTE25 (Alias:D14)>
//     <1=> GPIOE_25<selection=GPIOE_25_PIN_SEL,PTE25 (Alias:D14)>
//     <3=> UART4_RX<selection=UART4_RX_PIN_SEL,PTE25 (Alias:D14)>
//     <5=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTE25 (Alias:D14)>
//     <6=> EWM_IN<selection=EWM_IN_PIN_SEL,PTE25 (Alias:D14)>
//     <1=> Default
#define PTE25_SIG_SEL        1

// Signal mapping for PTE26 pin
//   <o> PTE26 (Alias:LED_GREEN) [GPIOE_26, ENET_1588_CLKIN, UART4_CTS_b, RTC_CLKOUT, USB_CLKIN]<name=PTE26_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE26 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_26<selection=GPIOE_26_PIN_SEL,PTE26 (Alias:LED_GREEN)>
//     <2=> ENET_1588_CLKIN<selection=ENET_1588_CLKIN_PIN_SEL,PTE26 (Alias:LED_GREEN)>
//     <3=> UART4_CTS_b<selection=UART4_CTS_b_PIN_SEL,PTE26 (Alias:LED_GREEN)>
//     <6=> RTC_CLKOUT<selection=RTC_CLKOUT_PIN_SEL,PTE26 (Alias:LED_GREEN)>
//     <7=> USB_CLKIN<selection=USB_CLKIN_PIN_SEL,PTE26 (Alias:LED_GREEN)>
//     <1=> Default
#define PTE26_SIG_SEL        1

// Signal mapping for PTE27 pin
//   <o> PTE27 [GPIOE_27, UART4_RTS_b]<name=PTE27_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE27 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_27<selection=GPIOE_27_PIN_SEL,PTE27>
//     <3=> UART4_RTS_b<selection=UART4_RTS_b_PIN_SEL,PTE27>
//     <-2=> Default
#define PTE27_SIG_SEL        -2

// Signal mapping for PTE28 pin
//   <o> PTE28 [GPIOE_28]<name=PTE28_SIG_SEL>
//   <i> Selects which peripheral signal is mapped to PTE28 pin
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_28<selection=GPIOE_28_PIN_SEL,PTE28>
//     <-2=> Default
#define PTE28_SIG_SEL        -2

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
//     <0=> ADC0_DM0<selection=ADC0_DM0_SIG_SEL,ADC0_DM0/ADC1_DM3/ADC0_SE19>
//     <0=> Default
#define ADC0_DM0_PIN_SEL     0
#define ADC0_DM0_GPIO        0
#define ADC0_DM0_FN          0

// Pin Mapping for ADC0_DM1 signal
//   <o> ADC0_DM1 [ADC0_DM1]<name=ADC0_DM1_PIN_SEL><constant>
//   <i> Shows which pin ADC0_DM1 is mapped to
//     <0=> ADC0_DM1<selection=ADC0_DM1_SIG_SEL,ADC0_DM1/ADC0_SE20>
//     <0=> Default
#define ADC0_DM1_PIN_SEL     0
#define ADC0_DM1_GPIO        0
#define ADC0_DM1_FN          0

// Pin Mapping for ADC0_DM2 signal
//   <o> ADC0_DM2 [PTE3]<name=ADC0_DM2_PIN_SEL>
//   <i> Shows which pin ADC0_DM2 is mapped to
//     <0=> Disabled
//     <1=> PTE3 (reset default)<selection=PTE3_SIG_SEL,ADC0_DM2/ADC1_SE7a (reset default)>
//     <2=> PTE3<selection=PTE3_SIG_SEL,ADC0_DM2/ADC1_SE7a>
//     <1=> Default
#define ADC0_DM2_PIN_SEL     1
#if ADC0_DM2_PIN_SEL == 2
#define ADC0_DM2_GPIO        digitalIO_PTE3
#define ADC0_DM2_FN          0
#endif

// Pin Mapping for ADC0_DM3 signal
//   <o> ADC0_DM3 [ADC1_DM0]<name=ADC0_DM3_PIN_SEL><constant>
//   <i> Shows which pin ADC0_DM3 is mapped to
//     <0=> ADC1_DM0<selection=ADC1_DM0_SIG_SEL,ADC1_DM0/ADC0_DM3/ADC1_SE19>
//     <0=> Default
#define ADC0_DM3_PIN_SEL     0
#define ADC0_DM3_GPIO        0
#define ADC0_DM3_FN          0

// Pin Mapping for ADC0_DP0 signal
//   <o> ADC0_DP0 [ADC0_DP0]<name=ADC0_DP0_PIN_SEL><constant>
//   <i> Shows which pin ADC0_DP0 is mapped to
//     <0=> ADC0_DP0<selection=ADC0_DP0_SIG_SEL,ADC0_DP0/ADC1_DP3/ADC0_SE0>
//     <0=> Default
#define ADC0_DP0_PIN_SEL     0
#define ADC0_DP0_GPIO        0
#define ADC0_DP0_FN          0

// Pin Mapping for ADC0_DP1 signal
//   <o> ADC0_DP1 [ADC0_DP1]<name=ADC0_DP1_PIN_SEL><constant>
//   <i> Shows which pin ADC0_DP1 is mapped to
//     <0=> ADC0_DP1<selection=ADC0_DP1_SIG_SEL,ADC0_DP1/ADC0_SE1>
//     <0=> Default
#define ADC0_DP1_PIN_SEL     0
#define ADC0_DP1_GPIO        0
#define ADC0_DP1_FN          0

// Pin Mapping for ADC0_DP2 signal
//   <o> ADC0_DP2 [PTE2]<name=ADC0_DP2_PIN_SEL>
//   <i> Shows which pin ADC0_DP2 is mapped to
//     <0=> Disabled
//     <1=> PTE2 (reset default)<selection=PTE2_SIG_SEL,ADC0_DP2/ADC1_SE6a/ADC0_SE2 (reset default)>
//     <2=> PTE2<selection=PTE2_SIG_SEL,ADC0_DP2/ADC1_SE6a/ADC0_SE2>
//     <1=> Default
#define ADC0_DP2_PIN_SEL     1
#if ADC0_DP2_PIN_SEL == 2
#define ADC0_DP2_GPIO        digitalIO_PTE2
#define ADC0_DP2_FN          0
#endif

// Pin Mapping for ADC0_DP3 signal
//   <o> ADC0_DP3 [ADC1_DP0]<name=ADC0_DP3_PIN_SEL><constant>
//   <i> Shows which pin ADC0_DP3 is mapped to
//     <0=> ADC1_DP0<selection=ADC1_DP0_SIG_SEL,ADC1_DP0/ADC0_DP3/ADC1_SE0/ADC0_SE3>
//     <0=> Default
#define ADC0_DP3_PIN_SEL     0
#define ADC0_DP3_GPIO        0
#define ADC0_DP3_FN          0

// Pin Mapping for ADC0_SE0 signal
//   <o> ADC0_SE0 [ADC0_DP0]<name=ADC0_SE0_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE0 is mapped to
//     <0=> ADC0_DP0<selection=ADC0_DP0_SIG_SEL,ADC0_DP0/ADC1_DP3/ADC0_SE0>
//     <0=> Default
#define ADC0_SE0_PIN_SEL     0
#define ADC0_SE0_GPIO        0
#define ADC0_SE0_FN          0

// Pin Mapping for ADC0_SE1 signal
//   <o> ADC0_SE1 [ADC0_DP1]<name=ADC0_SE1_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE1 is mapped to
//     <0=> ADC0_DP1<selection=ADC0_DP1_SIG_SEL,ADC0_DP1/ADC0_SE1>
//     <0=> Default
#define ADC0_SE1_PIN_SEL     0
#define ADC0_SE1_GPIO        0
#define ADC0_SE1_FN          0

// Pin Mapping for ADC0_SE2 signal
//   <o> ADC0_SE2 [PTE2]<name=ADC0_SE2_PIN_SEL>
//   <i> Shows which pin ADC0_SE2 is mapped to
//     <0=> Disabled
//     <1=> PTE2 (reset default)<selection=PTE2_SIG_SEL,ADC0_DP2/ADC1_SE6a/ADC0_SE2 (reset default)>
//     <2=> PTE2<selection=PTE2_SIG_SEL,ADC0_DP2/ADC1_SE6a/ADC0_SE2>
//     <1=> Default
#define ADC0_SE2_PIN_SEL     1
#if ADC0_SE2_PIN_SEL == 2
#define ADC0_SE2_GPIO        digitalIO_PTE2
#define ADC0_SE2_FN          0
#endif

// Pin Mapping for ADC0_SE3 signal
//   <o> ADC0_SE3 [ADC1_DP0]<name=ADC0_SE3_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE3 is mapped to
//     <0=> ADC1_DP0<selection=ADC1_DP0_SIG_SEL,ADC1_DP0/ADC0_DP3/ADC1_SE0/ADC0_SE3>
//     <0=> Default
#define ADC0_SE3_PIN_SEL     0
#define ADC0_SE3_GPIO        0
#define ADC0_SE3_FN          0

// Pin Mapping for ADC0_SE4b signal
//   <o> ADC0_SE4b [PTC2]<name=ADC0_SE4b_PIN_SEL>
//   <i> Shows which pin ADC0_SE4b is mapped to
//     <0=> Disabled
//     <1=> PTC2 (Alias:D6) (reset default)<selection=PTC2_SIG_SEL,ADC0_SE4b/CMP1_IN0 (reset default)>
//     <2=> PTC2 (Alias:D6)<selection=PTC2_SIG_SEL,ADC0_SE4b/CMP1_IN0>
//     <0=> Default
#define ADC0_SE4b_PIN_SEL    0
#if ADC0_SE4b_PIN_SEL == 2
#define ADC0_SE4b_GPIO       digitalIO_PTC2
#define ADC0_SE4b_FN         0
#endif

// Pin Mapping for ADC0_SE5b signal
//   <o> ADC0_SE5b [PTD1]<name=ADC0_SE5b_PIN_SEL>
//   <i> Shows which pin ADC0_SE5b is mapped to
//     <0=> Disabled
//     <1=> PTD1 (Alias:D13) (reset default)<selection=PTD1_SIG_SEL,ADC0_SE5b (reset default)>
//     <2=> PTD1 (Alias:D13)<selection=PTD1_SIG_SEL,ADC0_SE5b>
//     <0=> Default
#define ADC0_SE5b_PIN_SEL    0
#if ADC0_SE5b_PIN_SEL == 2
#define ADC0_SE5b_GPIO       digitalIO_PTD1
#define ADC0_SE5b_FN         0
#endif

// Pin Mapping for ADC0_SE6b signal
//   <o> ADC0_SE6b [PTD5]<name=ADC0_SE6b_PIN_SEL>
//   <i> Shows which pin ADC0_SE6b is mapped to
//     <0=> Disabled
//     <1=> PTD5 (Alias:nRF24L01_sck) (reset default)<selection=PTD5_SIG_SEL,ADC0_SE6b (reset default)>
//     <2=> PTD5 (Alias:nRF24L01_sck)<selection=PTD5_SIG_SEL,ADC0_SE6b>
//     <0=> Default
#define ADC0_SE6b_PIN_SEL    0
#if ADC0_SE6b_PIN_SEL == 2
#define ADC0_SE6b_GPIO       digitalIO_PTD5
#define ADC0_SE6b_FN         0
#endif

// Pin Mapping for ADC0_SE7b signal
//   <o> ADC0_SE7b [PTD6]<name=ADC0_SE7b_PIN_SEL>
//   <i> Shows which pin ADC0_SE7b is mapped to
//     <0=> Disabled
//     <1=> PTD6 (Alias:nRF24L01_mosi) (reset default)<selection=PTD6_SIG_SEL,ADC0_SE7b (reset default)>
//     <2=> PTD6 (Alias:nRF24L01_mosi)<selection=PTD6_SIG_SEL,ADC0_SE7b>
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
//     <1=> PTB0 (reset default)<selection=PTB0_SIG_SEL,ADC0_SE8/ADC1_SE8 (reset default)>
//     <2=> PTB0<selection=PTB0_SIG_SEL,ADC0_SE8/ADC1_SE8>
//     <1=> Default
#define ADC0_SE8_PIN_SEL     1
#if ADC0_SE8_PIN_SEL == 2
#define ADC0_SE8_GPIO        digitalIO_PTB0
#define ADC0_SE8_FN          0
#endif

// Pin Mapping for ADC0_SE9 signal
//   <o> ADC0_SE9 [PTB1]<name=ADC0_SE9_PIN_SEL>
//   <i> Shows which pin ADC0_SE9 is mapped to
//     <0=> Disabled
//     <1=> PTB1 (reset default)<selection=PTB1_SIG_SEL,ADC0_SE9/ADC1_SE9 (reset default)>
//     <2=> PTB1<selection=PTB1_SIG_SEL,ADC0_SE9/ADC1_SE9>
//     <1=> Default
#define ADC0_SE9_PIN_SEL     1
#if ADC0_SE9_PIN_SEL == 2
#define ADC0_SE9_GPIO        digitalIO_PTB1
#define ADC0_SE9_FN          0
#endif

// Pin Mapping for ADC0_SE10 signal
//   <o> ADC0_SE10 [PTA7]<name=ADC0_SE10_PIN_SEL>
//   <i> Shows which pin ADC0_SE10 is mapped to
//     <0=> Disabled
//     <1=> PTA7 (reset default)<selection=PTA7_SIG_SEL,ADC0_SE10 (reset default)>
//     <2=> PTA7<selection=PTA7_SIG_SEL,ADC0_SE10>
//     <1=> Default
#define ADC0_SE10_PIN_SEL    1
#if ADC0_SE10_PIN_SEL == 2
#define ADC0_SE10_GPIO       digitalIO_PTA7
#define ADC0_SE10_FN         0
#endif

// Pin Mapping for ADC0_SE11 signal
//   <o> ADC0_SE11 [PTA8]<name=ADC0_SE11_PIN_SEL>
//   <i> Shows which pin ADC0_SE11 is mapped to
//     <0=> Disabled
//     <1=> PTA8 (reset default)<selection=PTA8_SIG_SEL,ADC0_SE11 (reset default)>
//     <2=> PTA8<selection=PTA8_SIG_SEL,ADC0_SE11>
//     <1=> Default
#define ADC0_SE11_PIN_SEL    1
#if ADC0_SE11_PIN_SEL == 2
#define ADC0_SE11_GPIO       digitalIO_PTA8
#define ADC0_SE11_FN         0
#endif

// Pin Mapping for ADC0_SE12 signal
//   <o> ADC0_SE12 [PTB2]<name=ADC0_SE12_PIN_SEL>
//   <i> Shows which pin ADC0_SE12 is mapped to
//     <0=> Disabled
//     <1=> PTB2 (Alias:A0) (reset default)<selection=PTB2_SIG_SEL,ADC0_SE12 (reset default)>
//     <2=> PTB2 (Alias:A0)<selection=PTB2_SIG_SEL,ADC0_SE12>
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
//     <1=> PTB3 (Alias:A1) (reset default)<selection=PTB3_SIG_SEL,ADC0_SE13 (reset default)>
//     <2=> PTB3 (Alias:A1)<selection=PTB3_SIG_SEL,ADC0_SE13>
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
//     <1=> PTC0 (reset default)<selection=PTC0_SIG_SEL,ADC0_SE14 (reset default)>
//     <2=> PTC0<selection=PTC0_SIG_SEL,ADC0_SE14>
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
//     <1=> PTC1 (reset default)<selection=PTC1_SIG_SEL,ADC0_SE15 (reset default)>
//     <2=> PTC1<selection=PTC1_SIG_SEL,ADC0_SE15>
//     <1=> Default
#define ADC0_SE15_PIN_SEL    1
#if ADC0_SE15_PIN_SEL == 2
#define ADC0_SE15_GPIO       digitalIO_PTC1
#define ADC0_SE15_FN         0
#endif

// Pin Mapping for ADC0_SE16 signal
//   <o> ADC0_SE16 [ADC0_SE16]<name=ADC0_SE16_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE16 is mapped to
//     <0=> ADC0_SE16<selection=ADC0_SE16_SIG_SEL,ADC0_SE16/CMP1_IN2/ADC0_SE21>
//     <0=> Default
#define ADC0_SE16_PIN_SEL    0
#define ADC0_SE16_GPIO       0
#define ADC0_SE16_FN         0

// Pin Mapping for ADC0_SE17 signal
//   <o> ADC0_SE17 [PTE24]<name=ADC0_SE17_PIN_SEL>
//   <i> Shows which pin ADC0_SE17 is mapped to
//     <0=> Disabled
//     <1=> PTE24 (Alias:D15) (reset default)<selection=PTE24_SIG_SEL,ADC0_SE17 (reset default)>
//     <2=> PTE24 (Alias:D15)<selection=PTE24_SIG_SEL,ADC0_SE17>
//     <0=> Default
#define ADC0_SE17_PIN_SEL    0
#if ADC0_SE17_PIN_SEL == 2
#define ADC0_SE17_GPIO       digitalIO_PTE24
#define ADC0_SE17_FN         0
#endif

// Pin Mapping for ADC0_SE18 signal
//   <o> ADC0_SE18 [PTE25]<name=ADC0_SE18_PIN_SEL>
//   <i> Shows which pin ADC0_SE18 is mapped to
//     <0=> Disabled
//     <1=> PTE25 (Alias:D14) (reset default)<selection=PTE25_SIG_SEL,ADC0_SE18 (reset default)>
//     <2=> PTE25 (Alias:D14)<selection=PTE25_SIG_SEL,ADC0_SE18>
//     <0=> Default
#define ADC0_SE18_PIN_SEL    0
#if ADC0_SE18_PIN_SEL == 2
#define ADC0_SE18_GPIO       digitalIO_PTE25
#define ADC0_SE18_FN         0
#endif

// Pin Mapping for ADC0_SE19 signal
//   <o> ADC0_SE19 [ADC0_DM0]<name=ADC0_SE19_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE19 is mapped to
//     <0=> ADC0_DM0<selection=ADC0_DM0_SIG_SEL,ADC0_DM0/ADC1_DM3/ADC0_SE19>
//     <0=> Default
#define ADC0_SE19_PIN_SEL    0
#define ADC0_SE19_GPIO       0
#define ADC0_SE19_FN         0

// Pin Mapping for ADC0_SE20 signal
//   <o> ADC0_SE20 [ADC0_DM1]<name=ADC0_SE20_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE20 is mapped to
//     <0=> ADC0_DM1<selection=ADC0_DM1_SIG_SEL,ADC0_DM1/ADC0_SE20>
//     <0=> Default
#define ADC0_SE20_PIN_SEL    0
#define ADC0_SE20_GPIO       0
#define ADC0_SE20_FN         0

// Pin Mapping for ADC0_SE21 signal
//   <o> ADC0_SE21 [ADC0_SE16]<name=ADC0_SE21_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE21 is mapped to
//     <0=> ADC0_SE16<selection=ADC0_SE16_SIG_SEL,ADC0_SE16/CMP1_IN2/ADC0_SE21>
//     <0=> Default
#define ADC0_SE21_PIN_SEL    0
#define ADC0_SE21_GPIO       0
#define ADC0_SE21_FN         0

// Pin Mapping for ADC0_SE22 signal
//   <o> ADC0_SE22 [ADC1_SE16]<name=ADC0_SE22_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE22 is mapped to
//     <0=> ADC1_SE16<selection=ADC1_SE16_SIG_SEL,ADC1_SE16/CMP2_IN2/ADC0_SE22>
//     <0=> Default
#define ADC0_SE22_PIN_SEL    0
#define ADC0_SE22_GPIO       0
#define ADC0_SE22_FN         0

// Pin Mapping for ADC0_SE23 signal
//   <o> ADC0_SE23 [ADC0_SE23]<name=ADC0_SE23_PIN_SEL><constant>
//   <i> Shows which pin ADC0_SE23 is mapped to
//     <0=> ADC0_SE23<selection=ADC0_SE23_SIG_SEL,DAC0_OUT/CMP1_IN3/ADC0_SE23>
//     <0=> Default
#define ADC0_SE23_PIN_SEL    0
#define ADC0_SE23_GPIO       0
#define ADC0_SE23_FN         0

// </h>

// <h> Analogue to Digital (ADC1)

// Pin Mapping for ADC1_DM0 signal
//   <o> ADC1_DM0 [ADC1_DM0]<name=ADC1_DM0_PIN_SEL><constant>
//   <i> Shows which pin ADC1_DM0 is mapped to
//     <0=> ADC1_DM0<selection=ADC1_DM0_SIG_SEL,ADC1_DM0/ADC0_DM3/ADC1_SE19>
//     <0=> Default
#define ADC1_DM0_PIN_SEL     0
#define ADC1_DM0_GPIO        0
#define ADC1_DM0_FN          0

// Pin Mapping for ADC1_DM1 signal
//   <o> ADC1_DM1 [ADC1_DM1]<name=ADC1_DM1_PIN_SEL><constant>
//   <i> Shows which pin ADC1_DM1 is mapped to
//     <0=> ADC1_DM1<selection=ADC1_DM1_SIG_SEL,ADC1_DM1/ADC1_SE20>
//     <0=> Default
#define ADC1_DM1_PIN_SEL     0
#define ADC1_DM1_GPIO        0
#define ADC1_DM1_FN          0

// Pin Mapping for ADC1_DM3 signal
//   <o> ADC1_DM3 [ADC0_DM0]<name=ADC1_DM3_PIN_SEL><constant>
//   <i> Shows which pin ADC1_DM3 is mapped to
//     <0=> ADC0_DM0<selection=ADC0_DM0_SIG_SEL,ADC0_DM0/ADC1_DM3/ADC0_SE19>
//     <0=> Default
#define ADC1_DM3_PIN_SEL     0
#define ADC1_DM3_GPIO        0
#define ADC1_DM3_FN          0

// Pin Mapping for ADC1_DP0 signal
//   <o> ADC1_DP0 [ADC1_DP0]<name=ADC1_DP0_PIN_SEL><constant>
//   <i> Shows which pin ADC1_DP0 is mapped to
//     <0=> ADC1_DP0<selection=ADC1_DP0_SIG_SEL,ADC1_DP0/ADC0_DP3/ADC1_SE0/ADC0_SE3>
//     <0=> Default
#define ADC1_DP0_PIN_SEL     0
#define ADC1_DP0_GPIO        0
#define ADC1_DP0_FN          0

// Pin Mapping for ADC1_DP1 signal
//   <o> ADC1_DP1 [ADC1_DP1]<name=ADC1_DP1_PIN_SEL><constant>
//   <i> Shows which pin ADC1_DP1 is mapped to
//     <0=> ADC1_DP1<selection=ADC1_DP1_SIG_SEL,ADC1_DP1/ADC1_SE1>
//     <0=> Default
#define ADC1_DP1_PIN_SEL     0
#define ADC1_DP1_GPIO        0
#define ADC1_DP1_FN          0

// Pin Mapping for ADC1_DP3 signal
//   <o> ADC1_DP3 [ADC0_DP0]<name=ADC1_DP3_PIN_SEL><constant>
//   <i> Shows which pin ADC1_DP3 is mapped to
//     <0=> ADC0_DP0<selection=ADC0_DP0_SIG_SEL,ADC0_DP0/ADC1_DP3/ADC0_SE0>
//     <0=> Default
#define ADC1_DP3_PIN_SEL     0
#define ADC1_DP3_GPIO        0
#define ADC1_DP3_FN          0

// Pin Mapping for ADC1_SE0 signal
//   <o> ADC1_SE0 [ADC1_DP0]<name=ADC1_SE0_PIN_SEL><constant>
//   <i> Shows which pin ADC1_SE0 is mapped to
//     <0=> ADC1_DP0<selection=ADC1_DP0_SIG_SEL,ADC1_DP0/ADC0_DP3/ADC1_SE0/ADC0_SE3>
//     <0=> Default
#define ADC1_SE0_PIN_SEL     0
#define ADC1_SE0_GPIO        0
#define ADC1_SE0_FN          0

// Pin Mapping for ADC1_SE1 signal
//   <o> ADC1_SE1 [ADC1_DP1]<name=ADC1_SE1_PIN_SEL><constant>
//   <i> Shows which pin ADC1_SE1 is mapped to
//     <0=> ADC1_DP1<selection=ADC1_DP1_SIG_SEL,ADC1_DP1/ADC1_SE1>
//     <0=> Default
#define ADC1_SE1_PIN_SEL     0
#define ADC1_SE1_GPIO        0
#define ADC1_SE1_FN          0

// Pin Mapping for ADC1_SE4a signal
//   <o> ADC1_SE4a [PTE0]<name=ADC1_SE4a_PIN_SEL>
//   <i> Shows which pin ADC1_SE4a is mapped to
//     <0=> Disabled
//     <1=> PTE0 (reset default)<selection=PTE0_SIG_SEL,ADC1_SE4a (reset default)>
//     <2=> PTE0<selection=PTE0_SIG_SEL,ADC1_SE4a>
//     <1=> Default
#define ADC1_SE4a_PIN_SEL    1
#if ADC1_SE4a_PIN_SEL == 2
#define ADC1_SE4a_GPIO       digitalIO_PTE0
#define ADC1_SE4a_FN         0
#endif

// Pin Mapping for ADC1_SE4b signal
//   <o> ADC1_SE4b [PTC8]<name=ADC1_SE4b_PIN_SEL>
//   <i> Shows which pin ADC1_SE4b is mapped to
//     <0=> Disabled
//     <1=> PTC8 (reset default)<selection=PTC8_SIG_SEL,ADC1_SE4b/CMP0_IN2 (reset default)>
//     <2=> PTC8<selection=PTC8_SIG_SEL,ADC1_SE4b/CMP0_IN2>
//     <1=> Default
#define ADC1_SE4b_PIN_SEL    1
#if ADC1_SE4b_PIN_SEL == 2
#define ADC1_SE4b_GPIO       digitalIO_PTC8
#define ADC1_SE4b_FN         0
#endif

// Pin Mapping for ADC1_SE5a signal
//   <o> ADC1_SE5a [PTE1]<name=ADC1_SE5a_PIN_SEL>
//   <i> Shows which pin ADC1_SE5a is mapped to
//     <0=> Disabled
//     <1=> PTE1 (reset default)<selection=PTE1_SIG_SEL,ADC1_SE5a (reset default)>
//     <2=> PTE1<selection=PTE1_SIG_SEL,ADC1_SE5a>
//     <1=> Default
#define ADC1_SE5a_PIN_SEL    1
#if ADC1_SE5a_PIN_SEL == 2
#define ADC1_SE5a_GPIO       digitalIO_PTE1
#define ADC1_SE5a_FN         0
#endif

// Pin Mapping for ADC1_SE5b signal
//   <o> ADC1_SE5b [PTC9]<name=ADC1_SE5b_PIN_SEL>
//   <i> Shows which pin ADC1_SE5b is mapped to
//     <0=> Disabled
//     <1=> PTC9 (reset default)<selection=PTC9_SIG_SEL,ADC1_SE5b/CMP0_IN3 (reset default)>
//     <2=> PTC9<selection=PTC9_SIG_SEL,ADC1_SE5b/CMP0_IN3>
//     <1=> Default
#define ADC1_SE5b_PIN_SEL    1
#if ADC1_SE5b_PIN_SEL == 2
#define ADC1_SE5b_GPIO       digitalIO_PTC9
#define ADC1_SE5b_FN         0
#endif

// Pin Mapping for ADC1_SE6a signal
//   <o> ADC1_SE6a [PTE2]<name=ADC1_SE6a_PIN_SEL>
//   <i> Shows which pin ADC1_SE6a is mapped to
//     <0=> Disabled
//     <1=> PTE2 (reset default)<selection=PTE2_SIG_SEL,ADC0_DP2/ADC1_SE6a/ADC0_SE2 (reset default)>
//     <2=> PTE2<selection=PTE2_SIG_SEL,ADC0_DP2/ADC1_SE6a/ADC0_SE2>
//     <1=> Default
#define ADC1_SE6a_PIN_SEL    1
#if ADC1_SE6a_PIN_SEL == 2
#define ADC1_SE6a_GPIO       digitalIO_PTE2
#define ADC1_SE6a_FN         0
#endif

// Pin Mapping for ADC1_SE6b signal
//   <o> ADC1_SE6b [PTC10]<name=ADC1_SE6b_PIN_SEL>
//   <i> Shows which pin ADC1_SE6b is mapped to
//     <0=> Disabled
//     <1=> PTC10 (Alias:A5) (reset default)<selection=PTC10_SIG_SEL,ADC1_SE6b (reset default)>
//     <2=> PTC10 (Alias:A5)<selection=PTC10_SIG_SEL,ADC1_SE6b>
//     <0=> Default
#define ADC1_SE6b_PIN_SEL    0
#if ADC1_SE6b_PIN_SEL == 2
#define ADC1_SE6b_GPIO       digitalIO_PTC10
#define ADC1_SE6b_FN         0
#endif

// Pin Mapping for ADC1_SE7a signal
//   <o> ADC1_SE7a [PTE3]<name=ADC1_SE7a_PIN_SEL>
//   <i> Shows which pin ADC1_SE7a is mapped to
//     <0=> Disabled
//     <1=> PTE3 (reset default)<selection=PTE3_SIG_SEL,ADC0_DM2/ADC1_SE7a (reset default)>
//     <2=> PTE3<selection=PTE3_SIG_SEL,ADC0_DM2/ADC1_SE7a>
//     <1=> Default
#define ADC1_SE7a_PIN_SEL    1
#if ADC1_SE7a_PIN_SEL == 2
#define ADC1_SE7a_GPIO       digitalIO_PTE3
#define ADC1_SE7a_FN         0
#endif

// Pin Mapping for ADC1_SE7b signal
//   <o> ADC1_SE7b [PTC11]<name=ADC1_SE7b_PIN_SEL>
//   <i> Shows which pin ADC1_SE7b is mapped to
//     <0=> Disabled
//     <1=> PTC11 (Alias:A4) (reset default)<selection=PTC11_SIG_SEL,ADC1_SE7b (reset default)>
//     <2=> PTC11 (Alias:A4)<selection=PTC11_SIG_SEL,ADC1_SE7b>
//     <0=> Default
#define ADC1_SE7b_PIN_SEL    0
#if ADC1_SE7b_PIN_SEL == 2
#define ADC1_SE7b_GPIO       digitalIO_PTC11
#define ADC1_SE7b_FN         0
#endif

// Pin Mapping for ADC1_SE8 signal
//   <o> ADC1_SE8 [PTB0]<name=ADC1_SE8_PIN_SEL>
//   <i> Shows which pin ADC1_SE8 is mapped to
//     <0=> Disabled
//     <1=> PTB0 (reset default)<selection=PTB0_SIG_SEL,ADC0_SE8/ADC1_SE8 (reset default)>
//     <2=> PTB0<selection=PTB0_SIG_SEL,ADC0_SE8/ADC1_SE8>
//     <1=> Default
#define ADC1_SE8_PIN_SEL     1
#if ADC1_SE8_PIN_SEL == 2
#define ADC1_SE8_GPIO        digitalIO_PTB0
#define ADC1_SE8_FN          0
#endif

// Pin Mapping for ADC1_SE9 signal
//   <o> ADC1_SE9 [PTB1]<name=ADC1_SE9_PIN_SEL>
//   <i> Shows which pin ADC1_SE9 is mapped to
//     <0=> Disabled
//     <1=> PTB1 (reset default)<selection=PTB1_SIG_SEL,ADC0_SE9/ADC1_SE9 (reset default)>
//     <2=> PTB1<selection=PTB1_SIG_SEL,ADC0_SE9/ADC1_SE9>
//     <1=> Default
#define ADC1_SE9_PIN_SEL     1
#if ADC1_SE9_PIN_SEL == 2
#define ADC1_SE9_GPIO        digitalIO_PTB1
#define ADC1_SE9_FN          0
#endif

// Pin Mapping for ADC1_SE10 signal
//   <o> ADC1_SE10 [PTB4]<name=ADC1_SE10_PIN_SEL>
//   <i> Shows which pin ADC1_SE10 is mapped to
//     <0=> Disabled
//     <1=> PTB4 (reset default)<selection=PTB4_SIG_SEL,ADC1_SE10 (reset default)>
//     <2=> PTB4<selection=PTB4_SIG_SEL,ADC1_SE10>
//     <1=> Default
#define ADC1_SE10_PIN_SEL    1
#if ADC1_SE10_PIN_SEL == 2
#define ADC1_SE10_GPIO       digitalIO_PTB4
#define ADC1_SE10_FN         0
#endif

// Pin Mapping for ADC1_SE11 signal
//   <o> ADC1_SE11 [PTB5]<name=ADC1_SE11_PIN_SEL>
//   <i> Shows which pin ADC1_SE11 is mapped to
//     <0=> Disabled
//     <1=> PTB5 (reset default)<selection=PTB5_SIG_SEL,ADC1_SE11 (reset default)>
//     <2=> PTB5<selection=PTB5_SIG_SEL,ADC1_SE11>
//     <1=> Default
#define ADC1_SE11_PIN_SEL    1
#if ADC1_SE11_PIN_SEL == 2
#define ADC1_SE11_GPIO       digitalIO_PTB5
#define ADC1_SE11_FN         0
#endif

// Pin Mapping for ADC1_SE12 signal
//   <o> ADC1_SE12 [PTB6]<name=ADC1_SE12_PIN_SEL>
//   <i> Shows which pin ADC1_SE12 is mapped to
//     <0=> Disabled
//     <1=> PTB6 (reset default)<selection=PTB6_SIG_SEL,ADC1_SE12 (reset default)>
//     <2=> PTB6<selection=PTB6_SIG_SEL,ADC1_SE12>
//     <1=> Default
#define ADC1_SE12_PIN_SEL    1
#if ADC1_SE12_PIN_SEL == 2
#define ADC1_SE12_GPIO       digitalIO_PTB6
#define ADC1_SE12_FN         0
#endif

// Pin Mapping for ADC1_SE13 signal
//   <o> ADC1_SE13 [PTB7]<name=ADC1_SE13_PIN_SEL>
//   <i> Shows which pin ADC1_SE13 is mapped to
//     <0=> Disabled
//     <1=> PTB7 (reset default)<selection=PTB7_SIG_SEL,ADC1_SE13 (reset default)>
//     <2=> PTB7<selection=PTB7_SIG_SEL,ADC1_SE13>
//     <1=> Default
#define ADC1_SE13_PIN_SEL    1
#if ADC1_SE13_PIN_SEL == 2
#define ADC1_SE13_GPIO       digitalIO_PTB7
#define ADC1_SE13_FN         0
#endif

// Pin Mapping for ADC1_SE14 signal
//   <o> ADC1_SE14 [PTB10]<name=ADC1_SE14_PIN_SEL>
//   <i> Shows which pin ADC1_SE14 is mapped to
//     <0=> Disabled
//     <1=> PTB10 (Alias:A2) (reset default)<selection=PTB10_SIG_SEL,ADC1_SE14 (reset default)>
//     <2=> PTB10 (Alias:A2)<selection=PTB10_SIG_SEL,ADC1_SE14>
//     <2=> Default
#define ADC1_SE14_PIN_SEL    2
#if ADC1_SE14_PIN_SEL == 2
#define ADC1_SE14_GPIO       digitalIO_PTB10
#define ADC1_SE14_FN         0
#endif

// Pin Mapping for ADC1_SE15 signal
//   <o> ADC1_SE15 [PTB11]<name=ADC1_SE15_PIN_SEL>
//   <i> Shows which pin ADC1_SE15 is mapped to
//     <0=> Disabled
//     <1=> PTB11 (Alias:A3) (reset default)<selection=PTB11_SIG_SEL,ADC1_SE15 (reset default)>
//     <2=> PTB11 (Alias:A3)<selection=PTB11_SIG_SEL,ADC1_SE15>
//     <2=> Default
#define ADC1_SE15_PIN_SEL    2
#if ADC1_SE15_PIN_SEL == 2
#define ADC1_SE15_GPIO       digitalIO_PTB11
#define ADC1_SE15_FN         0
#endif

// Pin Mapping for ADC1_SE16 signal
//   <o> ADC1_SE16 [ADC1_SE16]<name=ADC1_SE16_PIN_SEL><constant>
//   <i> Shows which pin ADC1_SE16 is mapped to
//     <0=> ADC1_SE16<selection=ADC1_SE16_SIG_SEL,ADC1_SE16/CMP2_IN2/ADC0_SE22>
//     <0=> Default
#define ADC1_SE16_PIN_SEL    0
#define ADC1_SE16_GPIO       0
#define ADC1_SE16_FN         0

// Pin Mapping for ADC1_SE17 signal
//   <o> ADC1_SE17 [PTA17]<name=ADC1_SE17_PIN_SEL>
//   <i> Shows which pin ADC1_SE17 is mapped to
//     <0=> Disabled
//     <1=> PTA17 (reset default)<selection=PTA17_SIG_SEL,ADC1_SE17 (reset default)>
//     <2=> PTA17<selection=PTA17_SIG_SEL,ADC1_SE17>
//     <1=> Default
#define ADC1_SE17_PIN_SEL    1
#if ADC1_SE17_PIN_SEL == 2
#define ADC1_SE17_GPIO       digitalIO_PTA17
#define ADC1_SE17_FN         0
#endif

// Pin Mapping for ADC1_SE18 signal
//   <o> ADC1_SE18 [ADC1_SE18]<name=ADC1_SE18_PIN_SEL><constant>
//   <i> Shows which pin ADC1_SE18 is mapped to
//     <0=> ADC1_SE18<selection=ADC1_SE18_SIG_SEL,VREF_OUT/CMP1_IN5/CMP0_IN5/ADC1_SE18>
//     <0=> Default
#define ADC1_SE18_PIN_SEL    0
#define ADC1_SE18_GPIO       0
#define ADC1_SE18_FN         0

// Pin Mapping for ADC1_SE19 signal
//   <o> ADC1_SE19 [ADC1_DM0]<name=ADC1_SE19_PIN_SEL><constant>
//   <i> Shows which pin ADC1_SE19 is mapped to
//     <0=> ADC1_DM0<selection=ADC1_DM0_SIG_SEL,ADC1_DM0/ADC0_DM3/ADC1_SE19>
//     <0=> Default
#define ADC1_SE19_PIN_SEL    0
#define ADC1_SE19_GPIO       0
#define ADC1_SE19_FN         0

// Pin Mapping for ADC1_SE20 signal
//   <o> ADC1_SE20 [ADC1_DM1]<name=ADC1_SE20_PIN_SEL><constant>
//   <i> Shows which pin ADC1_SE20 is mapped to
//     <0=> ADC1_DM1<selection=ADC1_DM1_SIG_SEL,ADC1_DM1/ADC1_SE20>
//     <0=> Default
#define ADC1_SE20_PIN_SEL    0
#define ADC1_SE20_GPIO       0
#define ADC1_SE20_FN         0

// Pin Mapping for ADC1_SE23 signal
//   <o> ADC1_SE23 [ADC1_SE23]<name=ADC1_SE23_PIN_SEL><constant>
//   <i> Shows which pin ADC1_SE23 is mapped to
//     <0=> ADC1_SE23<selection=ADC1_SE23_SIG_SEL,DAC1_OUT/CMP0_IN4/CMP2_IN3/ADC1_SE23>
//     <0=> Default
#define ADC1_SE23_PIN_SEL    0
#define ADC1_SE23_GPIO       0
#define ADC1_SE23_FN         0

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
#if CAN0_RX_PIN_SEL == 1
#define CAN0_RX_GPIO         digitalIO_PTA13
#define CAN0_RX_FN           2
#elif CAN0_RX_PIN_SEL == 2
#define CAN0_RX_GPIO         digitalIO_PTB19
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
#if CAN0_TX_PIN_SEL == 1
#define CAN0_TX_GPIO         digitalIO_PTA12
#define CAN0_TX_FN           2
#elif CAN0_TX_PIN_SEL == 2
#define CAN0_TX_GPIO         digitalIO_PTB18
#define CAN0_TX_FN           2
#endif

// </h>

// <h> Clock and Timing

// Pin Mapping for CLKOUT signal
//   <o> CLKOUT [PTA6, PTC3]<name=CLKOUT_PIN_SEL>
//   <i> Shows which pin CLKOUT is mapped to
//     <0=> Disabled
//     <1=> PTA6<selection=PTA6_SIG_SEL,CLKOUT>
//     <2=> PTC3 (Alias:D7)<selection=PTC3_SIG_SEL,CLKOUT>
//     <0=> Default
#define CLKOUT_PIN_SEL       0
#if CLKOUT_PIN_SEL == 1
#define CLKOUT_GPIO          digitalIO_PTA6
#define CLKOUT_FN            5
#elif CLKOUT_PIN_SEL == 2
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
#if FTM_CLKIN0_PIN_SEL == 1
#define FTM_CLKIN0_GPIO      digitalIO_PTA18
#define FTM_CLKIN0_FN        4
#elif FTM_CLKIN0_PIN_SEL == 2
#define FTM_CLKIN0_GPIO      digitalIO_PTB16
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
#if FTM_CLKIN1_PIN_SEL == 1
#define FTM_CLKIN1_GPIO      digitalIO_PTA19
#define FTM_CLKIN1_FN        4
#elif FTM_CLKIN1_PIN_SEL == 2
#define FTM_CLKIN1_GPIO      digitalIO_PTB17
#define FTM_CLKIN1_FN        4
#endif

// Pin Mapping for RTC_CLKOUT signal
//   <o> RTC_CLKOUT [PTE26, PTE0]<name=RTC_CLKOUT_PIN_SEL>
//   <i> Shows which pin RTC_CLKOUT is mapped to
//     <0=> Disabled
//     <1=> PTE26 (Alias:LED_GREEN)<selection=PTE26_SIG_SEL,RTC_CLKOUT>
//     <2=> PTE0<selection=PTE0_SIG_SEL,RTC_CLKOUT>
//     <0=> Default
#define RTC_CLKOUT_PIN_SEL   0
#if RTC_CLKOUT_PIN_SEL == 1
#define RTC_CLKOUT_GPIO      digitalIO_PTE26
#define RTC_CLKOUT_FN        6
#elif RTC_CLKOUT_PIN_SEL == 2
#define RTC_CLKOUT_GPIO      digitalIO_PTE0
#define RTC_CLKOUT_FN        7
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
//     <1=> PTC6 (reset default)<selection=PTC6_SIG_SEL,CMP0_IN0 (reset default)>
//     <2=> PTC6<selection=PTC6_SIG_SEL,CMP0_IN0>
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
//     <1=> PTC7 (reset default)<selection=PTC7_SIG_SEL,CMP0_IN1 (reset default)>
//     <2=> PTC7<selection=PTC7_SIG_SEL,CMP0_IN1>
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
//     <1=> PTC8 (reset default)<selection=PTC8_SIG_SEL,ADC1_SE4b/CMP0_IN2 (reset default)>
//     <2=> PTC8<selection=PTC8_SIG_SEL,ADC1_SE4b/CMP0_IN2>
//     <1=> Default
#define CMP0_IN2_PIN_SEL     1
#if CMP0_IN2_PIN_SEL == 2
#define CMP0_IN2_GPIO        digitalIO_PTC8
#define CMP0_IN2_FN          0
#endif

// Pin Mapping for CMP0_IN3 signal
//   <o> CMP0_IN3 [PTC9]<name=CMP0_IN3_PIN_SEL>
//   <i> Shows which pin CMP0_IN3 is mapped to
//     <0=> Disabled
//     <1=> PTC9 (reset default)<selection=PTC9_SIG_SEL,ADC1_SE5b/CMP0_IN3 (reset default)>
//     <2=> PTC9<selection=PTC9_SIG_SEL,ADC1_SE5b/CMP0_IN3>
//     <1=> Default
#define CMP0_IN3_PIN_SEL     1
#if CMP0_IN3_PIN_SEL == 2
#define CMP0_IN3_GPIO        digitalIO_PTC9
#define CMP0_IN3_FN          0
#endif

// Pin Mapping for CMP0_IN4 signal
//   <o> CMP0_IN4 [ADC1_SE23]<name=CMP0_IN4_PIN_SEL><constant>
//   <i> Shows which pin CMP0_IN4 is mapped to
//     <0=> ADC1_SE23<selection=ADC1_SE23_SIG_SEL,DAC1_OUT/CMP0_IN4/CMP2_IN3/ADC1_SE23>
//     <0=> Default
#define CMP0_IN4_PIN_SEL     0
#define CMP0_IN4_GPIO        0
#define CMP0_IN4_FN          0

// Pin Mapping for CMP0_IN5 signal
//   <o> CMP0_IN5 [ADC1_SE18]<name=CMP0_IN5_PIN_SEL><constant>
//   <i> Shows which pin CMP0_IN5 is mapped to
//     <0=> ADC1_SE18<selection=ADC1_SE18_SIG_SEL,VREF_OUT/CMP1_IN5/CMP0_IN5/ADC1_SE18>
//     <0=> Default
#define CMP0_IN5_PIN_SEL     0
#define CMP0_IN5_GPIO        0
#define CMP0_IN5_FN          0

// Pin Mapping for CMP0_OUT signal
//   <o> CMP0_OUT [PTB20, PTC5]<name=CMP0_OUT_PIN_SEL>
//   <i> Shows which pin CMP0_OUT is mapped to
//     <0=> Disabled
//     <1=> PTB20<selection=PTB20_SIG_SEL,CMP0_OUT>
//     <2=> PTC5<selection=PTC5_SIG_SEL,CMP0_OUT>
//     <0=> Default
#define CMP0_OUT_PIN_SEL     0
#if CMP0_OUT_PIN_SEL == 1
#define CMP0_OUT_GPIO        digitalIO_PTB20
#define CMP0_OUT_FN          6
#elif CMP0_OUT_PIN_SEL == 2
#define CMP0_OUT_GPIO        digitalIO_PTC5
#define CMP0_OUT_FN          6
#endif

// </h>

// <h> Analogue Comparator (CMP1)

// Pin Mapping for CMP1_IN0 signal
//   <o> CMP1_IN0 [PTC2]<name=CMP1_IN0_PIN_SEL>
//   <i> Shows which pin CMP1_IN0 is mapped to
//     <0=> Disabled
//     <1=> PTC2 (Alias:D6) (reset default)<selection=PTC2_SIG_SEL,ADC0_SE4b/CMP1_IN0 (reset default)>
//     <2=> PTC2 (Alias:D6)<selection=PTC2_SIG_SEL,ADC0_SE4b/CMP1_IN0>
//     <0=> Default
#define CMP1_IN0_PIN_SEL     0
#if CMP1_IN0_PIN_SEL == 2
#define CMP1_IN0_GPIO        digitalIO_PTC2
#define CMP1_IN0_FN          0
#endif

// Pin Mapping for CMP1_IN1 signal
//   <o> CMP1_IN1 [PTC3]<name=CMP1_IN1_PIN_SEL>
//   <i> Shows which pin CMP1_IN1 is mapped to
//     <0=> Disabled
//     <1=> PTC3 (Alias:D7) (reset default)<selection=PTC3_SIG_SEL,CMP1_IN1 (reset default)>
//     <2=> PTC3 (Alias:D7)<selection=PTC3_SIG_SEL,CMP1_IN1>
//     <0=> Default
#define CMP1_IN1_PIN_SEL     0
#if CMP1_IN1_PIN_SEL == 2
#define CMP1_IN1_GPIO        digitalIO_PTC3
#define CMP1_IN1_FN          0
#endif

// Pin Mapping for CMP1_IN2 signal
//   <o> CMP1_IN2 [ADC0_SE16]<name=CMP1_IN2_PIN_SEL><constant>
//   <i> Shows which pin CMP1_IN2 is mapped to
//     <0=> ADC0_SE16<selection=ADC0_SE16_SIG_SEL,ADC0_SE16/CMP1_IN2/ADC0_SE21>
//     <0=> Default
#define CMP1_IN2_PIN_SEL     0
#define CMP1_IN2_GPIO        0
#define CMP1_IN2_FN          0

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
//   <o> CMP1_OUT [PTB21, PTC4]<name=CMP1_OUT_PIN_SEL>
//   <i> Shows which pin CMP1_OUT is mapped to
//     <0=> Disabled
//     <1=> PTB21 (Alias:LED_BLUE)<selection=PTB21_SIG_SEL,CMP1_OUT>
//     <2=> PTC4 (Alias:D9)<selection=PTC4_SIG_SEL,CMP1_OUT>
//     <0=> Default
#define CMP1_OUT_PIN_SEL     0
#if CMP1_OUT_PIN_SEL == 1
#define CMP1_OUT_GPIO        digitalIO_PTB21
#define CMP1_OUT_FN          6
#elif CMP1_OUT_PIN_SEL == 2
#define CMP1_OUT_GPIO        digitalIO_PTC4
#define CMP1_OUT_FN          6
#endif

// </h>

// <h> Analogue Comparator (CMP2)

// Pin Mapping for CMP2_IN0 signal
//   <o> CMP2_IN0 [PTA12]<name=CMP2_IN0_PIN_SEL>
//   <i> Shows which pin CMP2_IN0 is mapped to
//     <0=> Disabled
//     <1=> PTA12 (reset default)<selection=PTA12_SIG_SEL,CMP2_IN0 (reset default)>
//     <2=> PTA12<selection=PTA12_SIG_SEL,CMP2_IN0>
//     <1=> Default
#define CMP2_IN0_PIN_SEL     1
#if CMP2_IN0_PIN_SEL == 2
#define CMP2_IN0_GPIO        digitalIO_PTA12
#define CMP2_IN0_FN          0
#endif

// Pin Mapping for CMP2_IN1 signal
//   <o> CMP2_IN1 [PTA13]<name=CMP2_IN1_PIN_SEL>
//   <i> Shows which pin CMP2_IN1 is mapped to
//     <0=> Disabled
//     <1=> PTA13 (reset default)<selection=PTA13_SIG_SEL,CMP2_IN1 (reset default)>
//     <2=> PTA13<selection=PTA13_SIG_SEL,CMP2_IN1>
//     <1=> Default
#define CMP2_IN1_PIN_SEL     1
#if CMP2_IN1_PIN_SEL == 2
#define CMP2_IN1_GPIO        digitalIO_PTA13
#define CMP2_IN1_FN          0
#endif

// Pin Mapping for CMP2_IN2 signal
//   <o> CMP2_IN2 [ADC1_SE16]<name=CMP2_IN2_PIN_SEL><constant>
//   <i> Shows which pin CMP2_IN2 is mapped to
//     <0=> ADC1_SE16<selection=ADC1_SE16_SIG_SEL,ADC1_SE16/CMP2_IN2/ADC0_SE22>
//     <0=> Default
#define CMP2_IN2_PIN_SEL     0
#define CMP2_IN2_GPIO        0
#define CMP2_IN2_FN          0

// Pin Mapping for CMP2_IN3 signal
//   <o> CMP2_IN3 [ADC1_SE23]<name=CMP2_IN3_PIN_SEL><constant>
//   <i> Shows which pin CMP2_IN3 is mapped to
//     <0=> ADC1_SE23<selection=ADC1_SE23_SIG_SEL,DAC1_OUT/CMP0_IN4/CMP2_IN3/ADC1_SE23>
//     <0=> Default
#define CMP2_IN3_PIN_SEL     0
#define CMP2_IN3_GPIO        0
#define CMP2_IN3_FN          0

// Pin Mapping for CMP2_OUT signal
//   <o> CMP2_OUT [PTA5, PTB22]<name=CMP2_OUT_PIN_SEL>
//   <i> Shows which pin CMP2_OUT is mapped to
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,CMP2_OUT>
//     <2=> PTB22 (Alias:LED_RED)<selection=PTB22_SIG_SEL,CMP2_OUT>
//     <0=> Default
#define CMP2_OUT_PIN_SEL     0
#if CMP2_OUT_PIN_SEL == 1
#define CMP2_OUT_GPIO        digitalIO_PTA5
#define CMP2_OUT_FN          5
#elif CMP2_OUT_PIN_SEL == 2
#define CMP2_OUT_GPIO        digitalIO_PTB22
#define CMP2_OUT_FN          6
#endif

// </h>

// <h> Carrier Modulator Transmitter (CMT)

// Pin Mapping for CMT_IRO signal
//   <o> CMT_IRO [PTD7]<name=CMT_IRO_PIN_SEL>
//   <i> Shows which pin CMT_IRO is mapped to
//     <0=> Disabled
//     <1=> PTD7 (Alias:nRF24L01_miso)<selection=PTD7_SIG_SEL,CMT_IRO>
//     <0=> Default
#define CMT_IRO_PIN_SEL      0
#if CMT_IRO_PIN_SEL == 1
#define CMT_IRO_GPIO         digitalIO_PTD7
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

// <h> Digital to Analogue (DAC1)

// Pin Mapping for DAC1_OUT signal
//   <o> DAC1_OUT [ADC1_SE23]<name=DAC1_OUT_PIN_SEL><constant>
//   <i> Shows which pin DAC1_OUT is mapped to
//     <0=> ADC1_SE23<selection=ADC1_SE23_SIG_SEL,DAC1_OUT/CMP0_IN4/CMP2_IN3/ADC1_SE23>
//     <0=> Default
#define DAC1_OUT_PIN_SEL     0
#define DAC1_OUT_GPIO        0
#define DAC1_OUT_FN          0

// </h>

// <h> Ethernet (ENET0)

// Pin Mapping for ENET0_1588_TMR0 signal
//   <o> ENET0_1588_TMR0 [PTB2, PTC16]<name=ENET0_1588_TMR0_PIN_SEL>
//   <i> Shows which pin ENET0_1588_TMR0 is mapped to
//     <0=> Disabled
//     <1=> PTB2 (Alias:A0)<selection=PTB2_SIG_SEL,ENET0_1588_TMR0>
//     <2=> PTC16 (Alias:D0)<selection=PTC16_SIG_SEL,ENET0_1588_TMR0>
//     <0=> Default
#define ENET0_1588_TMR0_PIN_SEL 0
#if ENET0_1588_TMR0_PIN_SEL == 1
#define ENET0_1588_TMR0_GPIO digitalIO_PTB2
#define ENET0_1588_TMR0_FN   4
#elif ENET0_1588_TMR0_PIN_SEL == 2
#define ENET0_1588_TMR0_GPIO digitalIO_PTC16
#define ENET0_1588_TMR0_FN   4
#endif

// Pin Mapping for ENET0_1588_TMR3 signal
//   <o> ENET0_1588_TMR3 [PTB5, PTC19]<name=ENET0_1588_TMR3_PIN_SEL>
//   <i> Shows which pin ENET0_1588_TMR3 is mapped to
//     <0=> Disabled
//     <1=> PTB5<selection=PTB5_SIG_SEL,ENET0_1588_TMR3>
//     <2=> PTC19<selection=PTC19_SIG_SEL,ENET0_1588_TMR3>
//     <0=> Default
#define ENET0_1588_TMR3_PIN_SEL 0
#if ENET0_1588_TMR3_PIN_SEL == 1
#define ENET0_1588_TMR3_GPIO digitalIO_PTB5
#define ENET0_1588_TMR3_FN   4
#elif ENET0_1588_TMR3_PIN_SEL == 2
#define ENET0_1588_TMR3_GPIO digitalIO_PTC19
#define ENET0_1588_TMR3_FN   4
#endif

// Pin Mapping for ENET0_1588_TMR1 signal
//   <o> ENET0_1588_TMR1 [PTB3, PTC17]<name=ENET0_1588_TMR1_PIN_SEL>
//   <i> Shows which pin ENET0_1588_TMR1 is mapped to
//     <0=> Disabled
//     <1=> PTB3 (Alias:A1)<selection=PTB3_SIG_SEL,ENET0_1588_TMR1>
//     <2=> PTC17 (Alias:D1)<selection=PTC17_SIG_SEL,ENET0_1588_TMR1>
//     <0=> Default
#define ENET0_1588_TMR1_PIN_SEL 0
#if ENET0_1588_TMR1_PIN_SEL == 1
#define ENET0_1588_TMR1_GPIO digitalIO_PTB3
#define ENET0_1588_TMR1_FN   4
#elif ENET0_1588_TMR1_PIN_SEL == 2
#define ENET0_1588_TMR1_GPIO digitalIO_PTC17
#define ENET0_1588_TMR1_FN   4
#endif

// Pin Mapping for ENET0_1588_TMR2 signal
//   <o> ENET0_1588_TMR2 [PTB4, PTC18]<name=ENET0_1588_TMR2_PIN_SEL>
//   <i> Shows which pin ENET0_1588_TMR2 is mapped to
//     <0=> Disabled
//     <1=> PTB4<selection=PTB4_SIG_SEL,ENET0_1588_TMR2>
//     <2=> PTC18<selection=PTC18_SIG_SEL,ENET0_1588_TMR2>
//     <0=> Default
#define ENET0_1588_TMR2_PIN_SEL 0
#if ENET0_1588_TMR2_PIN_SEL == 1
#define ENET0_1588_TMR2_GPIO digitalIO_PTB4
#define ENET0_1588_TMR2_FN   4
#elif ENET0_1588_TMR2_PIN_SEL == 2
#define ENET0_1588_TMR2_GPIO digitalIO_PTC18
#define ENET0_1588_TMR2_FN   4
#endif

// </h>

// <h> Ethernet (ENET)

// Pin Mapping for ENET_1588_CLKIN signal
//   <o> ENET_1588_CLKIN [PTE26]<name=ENET_1588_CLKIN_PIN_SEL>
//   <i> Shows which pin ENET_1588_CLKIN is mapped to
//     <0=> Disabled
//     <1=> PTE26 (Alias:LED_GREEN)<selection=PTE26_SIG_SEL,ENET_1588_CLKIN>
//     <0=> Default
#define ENET_1588_CLKIN_PIN_SEL 0
#if ENET_1588_CLKIN_PIN_SEL == 1
#define ENET_1588_CLKIN_GPIO digitalIO_PTE26
#define ENET_1588_CLKIN_FN   2
#endif

// </h>

// <h> External Watchdog Monitor (EWM)

// Pin Mapping for EWM_IN signal
//   <o> EWM_IN [PTB16, PTD4, PTE25]<name=EWM_IN_PIN_SEL>
//   <i> Shows which pin EWM_IN is mapped to
//     <0=> Disabled
//     <1=> PTB16<selection=PTB16_SIG_SEL,EWM_IN>
//     <2=> PTD4 (Alias:nRF24L01_cs)<selection=PTD4_SIG_SEL,EWM_IN>
//     <3=> PTE25 (Alias:D14)<selection=PTE25_SIG_SEL,EWM_IN>
//     <0=> Default
#define EWM_IN_PIN_SEL       0
#if EWM_IN_PIN_SEL == 1
#define EWM_IN_GPIO          digitalIO_PTB16
#define EWM_IN_FN            6
#elif EWM_IN_PIN_SEL == 2
#define EWM_IN_GPIO          digitalIO_PTD4
#define EWM_IN_FN            6
#elif EWM_IN_PIN_SEL == 3
#define EWM_IN_GPIO          digitalIO_PTE25
#define EWM_IN_FN            6
#endif

// Pin Mapping for EWM_OUT_b signal
//   <o> EWM_OUT_b [PTB17, PTD5, PTE24]<name=EWM_OUT_b_PIN_SEL>
//   <i> Shows which pin EWM_OUT_b is mapped to
//     <0=> Disabled
//     <1=> PTB17<selection=PTB17_SIG_SEL,EWM_OUT_b>
//     <2=> PTD5 (Alias:nRF24L01_sck)<selection=PTD5_SIG_SEL,EWM_OUT_b>
//     <3=> PTE24 (Alias:D15)<selection=PTE24_SIG_SEL,EWM_OUT_b>
//     <0=> Default
#define EWM_OUT_b_PIN_SEL    0
#if EWM_OUT_b_PIN_SEL == 1
#define EWM_OUT_b_GPIO       digitalIO_PTB17
#define EWM_OUT_b_FN         6
#elif EWM_OUT_b_PIN_SEL == 2
#define EWM_OUT_b_GPIO       digitalIO_PTD5
#define EWM_OUT_b_FN         6
#elif EWM_OUT_b_PIN_SEL == 3
#define EWM_OUT_b_GPIO       digitalIO_PTE24
#define EWM_OUT_b_FN         6
#endif

// </h>

// <h> Flexbus

// Pin Mapping for FB_A16 signal
//   <o> FB_A16 [PTD8]<name=FB_A16_PIN_SEL>
//   <i> Shows which pin FB_A16 is mapped to
//     <0=> Disabled
//     <1=> PTD8<selection=PTD8_SIG_SEL,FB_A16>
//     <0=> Default
#define FB_A16_PIN_SEL       0
#if FB_A16_PIN_SEL == 1
#define FB_A16_GPIO          digitalIO_PTD8
#define FB_A16_FN            6
#endif

// Pin Mapping for FB_A17 signal
//   <o> FB_A17 [PTD9]<name=FB_A17_PIN_SEL>
//   <i> Shows which pin FB_A17 is mapped to
//     <0=> Disabled
//     <1=> PTD9<selection=PTD9_SIG_SEL,FB_A17>
//     <0=> Default
#define FB_A17_PIN_SEL       0
#if FB_A17_PIN_SEL == 1
#define FB_A17_GPIO          digitalIO_PTD9
#define FB_A17_FN            6
#endif

// Pin Mapping for FB_A18 signal
//   <o> FB_A18 [PTD10]<name=FB_A18_PIN_SEL>
//   <i> Shows which pin FB_A18 is mapped to
//     <0=> Disabled
//     <1=> PTD10<selection=PTD10_SIG_SEL,FB_A18>
//     <0=> Default
#define FB_A18_PIN_SEL       0
#if FB_A18_PIN_SEL == 1
#define FB_A18_GPIO          digitalIO_PTD10
#define FB_A18_FN            6
#endif

// Pin Mapping for FB_A19 signal
//   <o> FB_A19 [PTD11]<name=FB_A19_PIN_SEL>
//   <i> Shows which pin FB_A19 is mapped to
//     <0=> Disabled
//     <1=> PTD11<selection=PTD11_SIG_SEL,FB_A19>
//     <0=> Default
#define FB_A19_PIN_SEL       0
#if FB_A19_PIN_SEL == 1
#define FB_A19_GPIO          digitalIO_PTD11
#define FB_A19_FN            6
#endif

// Pin Mapping for FB_A20 signal
//   <o> FB_A20 [PTD12]<name=FB_A20_PIN_SEL>
//   <i> Shows which pin FB_A20 is mapped to
//     <0=> Disabled
//     <1=> PTD12<selection=PTD12_SIG_SEL,FB_A20>
//     <0=> Default
#define FB_A20_PIN_SEL       0
#if FB_A20_PIN_SEL == 1
#define FB_A20_GPIO          digitalIO_PTD12
#define FB_A20_FN            6
#endif

// Pin Mapping for FB_A21 signal
//   <o> FB_A21 [PTD13]<name=FB_A21_PIN_SEL>
//   <i> Shows which pin FB_A21 is mapped to
//     <0=> Disabled
//     <1=> PTD13<selection=PTD13_SIG_SEL,FB_A21>
//     <0=> Default
#define FB_A21_PIN_SEL       0
#if FB_A21_PIN_SEL == 1
#define FB_A21_GPIO          digitalIO_PTD13
#define FB_A21_FN            6
#endif

// Pin Mapping for FB_A22 signal
//   <o> FB_A22 [PTD14]<name=FB_A22_PIN_SEL>
//   <i> Shows which pin FB_A22 is mapped to
//     <0=> Disabled
//     <1=> PTD14<selection=PTD14_SIG_SEL,FB_A22>
//     <0=> Default
#define FB_A22_PIN_SEL       0
#if FB_A22_PIN_SEL == 1
#define FB_A22_GPIO          digitalIO_PTD14
#define FB_A22_FN            6
#endif

// Pin Mapping for FB_A23 signal
//   <o> FB_A23 [PTD15]<name=FB_A23_PIN_SEL>
//   <i> Shows which pin FB_A23 is mapped to
//     <0=> Disabled
//     <1=> PTD15<selection=PTD15_SIG_SEL,FB_A23>
//     <0=> Default
#define FB_A23_PIN_SEL       0
#if FB_A23_PIN_SEL == 1
#define FB_A23_GPIO          digitalIO_PTD15
#define FB_A23_FN            6
#endif

// Pin Mapping for FB_A24 signal
//   <o> FB_A24 [PTA29]<name=FB_A24_PIN_SEL>
//   <i> Shows which pin FB_A24 is mapped to
//     <0=> Disabled
//     <1=> PTA29<selection=PTA29_SIG_SEL,FB_A24>
//     <0=> Default
#define FB_A24_PIN_SEL       0
#if FB_A24_PIN_SEL == 1
#define FB_A24_GPIO          digitalIO_PTA29
#define FB_A24_FN            6
#endif

// Pin Mapping for FB_A25 signal
//   <o> FB_A25 [PTA28]<name=FB_A25_PIN_SEL>
//   <i> Shows which pin FB_A25 is mapped to
//     <0=> Disabled
//     <1=> PTA28<selection=PTA28_SIG_SEL,FB_A25>
//     <0=> Default
#define FB_A25_PIN_SEL       0
#if FB_A25_PIN_SEL == 1
#define FB_A25_GPIO          digitalIO_PTA28
#define FB_A25_FN            6
#endif

// Pin Mapping for FB_A26 signal
//   <o> FB_A26 [PTA27]<name=FB_A26_PIN_SEL>
//   <i> Shows which pin FB_A26 is mapped to
//     <0=> Disabled
//     <1=> PTA27<selection=PTA27_SIG_SEL,FB_A26>
//     <0=> Default
#define FB_A26_PIN_SEL       0
#if FB_A26_PIN_SEL == 1
#define FB_A26_GPIO          digitalIO_PTA27
#define FB_A26_FN            6
#endif

// Pin Mapping for FB_A27 signal
//   <o> FB_A27 [PTA26]<name=FB_A27_PIN_SEL>
//   <i> Shows which pin FB_A27 is mapped to
//     <0=> Disabled
//     <1=> PTA26<selection=PTA26_SIG_SEL,FB_A27>
//     <0=> Default
#define FB_A27_PIN_SEL       0
#if FB_A27_PIN_SEL == 1
#define FB_A27_GPIO          digitalIO_PTA26
#define FB_A27_FN            6
#endif

// Pin Mapping for FB_A28 signal
//   <o> FB_A28 [PTA25]<name=FB_A28_PIN_SEL>
//   <i> Shows which pin FB_A28 is mapped to
//     <0=> Disabled
//     <1=> PTA25<selection=PTA25_SIG_SEL,FB_A28>
//     <0=> Default
#define FB_A28_PIN_SEL       0
#if FB_A28_PIN_SEL == 1
#define FB_A28_GPIO          digitalIO_PTA25
#define FB_A28_FN            6
#endif

// Pin Mapping for FB_A29 signal
//   <o> FB_A29 [PTA24]<name=FB_A29_PIN_SEL>
//   <i> Shows which pin FB_A29 is mapped to
//     <0=> Disabled
//     <1=> PTA24<selection=PTA24_SIG_SEL,FB_A29>
//     <0=> Default
#define FB_A29_PIN_SEL       0
#if FB_A29_PIN_SEL == 1
#define FB_A29_GPIO          digitalIO_PTA24
#define FB_A29_FN            6
#endif

// Pin Mapping for FB_AD0 signal
//   <o> FB_AD0 [PTD6]<name=FB_AD0_PIN_SEL>
//   <i> Shows which pin FB_AD0 is mapped to
//     <0=> Disabled
//     <1=> PTD6 (Alias:nRF24L01_mosi)<selection=PTD6_SIG_SEL,FB_AD0>
//     <0=> Default
#define FB_AD0_PIN_SEL       0
#if FB_AD0_PIN_SEL == 1
#define FB_AD0_GPIO          digitalIO_PTD6
#define FB_AD0_FN            5
#endif

// Pin Mapping for FB_AD1 signal
//   <o> FB_AD1 [PTD5]<name=FB_AD1_PIN_SEL>
//   <i> Shows which pin FB_AD1 is mapped to
//     <0=> Disabled
//     <1=> PTD5 (Alias:nRF24L01_sck)<selection=PTD5_SIG_SEL,FB_AD1>
//     <0=> Default
#define FB_AD1_PIN_SEL       0
#if FB_AD1_PIN_SEL == 1
#define FB_AD1_GPIO          digitalIO_PTD5
#define FB_AD1_FN            5
#endif

// Pin Mapping for FB_AD2 signal
//   <o> FB_AD2 [PTD4]<name=FB_AD2_PIN_SEL>
//   <i> Shows which pin FB_AD2 is mapped to
//     <0=> Disabled
//     <1=> PTD4 (Alias:nRF24L01_cs)<selection=PTD4_SIG_SEL,FB_AD2>
//     <0=> Default
#define FB_AD2_PIN_SEL       0
#if FB_AD2_PIN_SEL == 1
#define FB_AD2_GPIO          digitalIO_PTD4
#define FB_AD2_FN            5
#endif

// Pin Mapping for FB_AD3 signal
//   <o> FB_AD3 [PTD3]<name=FB_AD3_PIN_SEL>
//   <i> Shows which pin FB_AD3 is mapped to
//     <0=> Disabled
//     <1=> PTD3 (Alias:D12)<selection=PTD3_SIG_SEL,FB_AD3>
//     <0=> Default
#define FB_AD3_PIN_SEL       0
#if FB_AD3_PIN_SEL == 1
#define FB_AD3_GPIO          digitalIO_PTD3
#define FB_AD3_FN            5
#endif

// Pin Mapping for FB_AD4 signal
//   <o> FB_AD4 [PTD2]<name=FB_AD4_PIN_SEL>
//   <i> Shows which pin FB_AD4 is mapped to
//     <0=> Disabled
//     <1=> PTD2 (Alias:D11)<selection=PTD2_SIG_SEL,FB_AD4>
//     <0=> Default
#define FB_AD4_PIN_SEL       0
#if FB_AD4_PIN_SEL == 1
#define FB_AD4_GPIO          digitalIO_PTD2
#define FB_AD4_FN            5
#endif

// Pin Mapping for FB_AD5 signal
//   <o> FB_AD5 [PTC10]<name=FB_AD5_PIN_SEL>
//   <i> Shows which pin FB_AD5 is mapped to
//     <0=> Disabled
//     <1=> PTC10 (Alias:A5)<selection=PTC10_SIG_SEL,FB_AD5>
//     <0=> Default
#define FB_AD5_PIN_SEL       0
#if FB_AD5_PIN_SEL == 1
#define FB_AD5_GPIO          digitalIO_PTC10
#define FB_AD5_FN            5
#endif

// Pin Mapping for FB_AD6 signal
//   <o> FB_AD6 [PTC9]<name=FB_AD6_PIN_SEL>
//   <i> Shows which pin FB_AD6 is mapped to
//     <0=> Disabled
//     <1=> PTC9<selection=PTC9_SIG_SEL,FB_AD6>
//     <0=> Default
#define FB_AD6_PIN_SEL       0
#if FB_AD6_PIN_SEL == 1
#define FB_AD6_GPIO          digitalIO_PTC9
#define FB_AD6_FN            5
#endif

// Pin Mapping for FB_AD7 signal
//   <o> FB_AD7 [PTC8]<name=FB_AD7_PIN_SEL>
//   <i> Shows which pin FB_AD7 is mapped to
//     <0=> Disabled
//     <1=> PTC8<selection=PTC8_SIG_SEL,FB_AD7>
//     <0=> Default
#define FB_AD7_PIN_SEL       0
#if FB_AD7_PIN_SEL == 1
#define FB_AD7_GPIO          digitalIO_PTC8
#define FB_AD7_FN            5
#endif

// Pin Mapping for FB_AD8 signal
//   <o> FB_AD8 [PTC7]<name=FB_AD8_PIN_SEL>
//   <i> Shows which pin FB_AD8 is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,FB_AD8>
//     <0=> Default
#define FB_AD8_PIN_SEL       0
#if FB_AD8_PIN_SEL == 1
#define FB_AD8_GPIO          digitalIO_PTC7
#define FB_AD8_FN            5
#endif

// Pin Mapping for FB_AD9 signal
//   <o> FB_AD9 [PTC6]<name=FB_AD9_PIN_SEL>
//   <i> Shows which pin FB_AD9 is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,FB_AD9>
//     <0=> Default
#define FB_AD9_PIN_SEL       0
#if FB_AD9_PIN_SEL == 1
#define FB_AD9_GPIO          digitalIO_PTC6
#define FB_AD9_FN            5
#endif

// Pin Mapping for FB_AD10 signal
//   <o> FB_AD10 [PTC5]<name=FB_AD10_PIN_SEL>
//   <i> Shows which pin FB_AD10 is mapped to
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,FB_AD10>
//     <0=> Default
#define FB_AD10_PIN_SEL      0
#if FB_AD10_PIN_SEL == 1
#define FB_AD10_GPIO         digitalIO_PTC5
#define FB_AD10_FN           5
#endif

// Pin Mapping for FB_AD11 signal
//   <o> FB_AD11 [PTC4]<name=FB_AD11_PIN_SEL>
//   <i> Shows which pin FB_AD11 is mapped to
//     <0=> Disabled
//     <1=> PTC4 (Alias:D9)<selection=PTC4_SIG_SEL,FB_AD11>
//     <0=> Default
#define FB_AD11_PIN_SEL      0
#if FB_AD11_PIN_SEL == 1
#define FB_AD11_GPIO         digitalIO_PTC4
#define FB_AD11_FN           5
#endif

// Pin Mapping for FB_AD12 signal
//   <o> FB_AD12 [PTC2]<name=FB_AD12_PIN_SEL>
//   <i> Shows which pin FB_AD12 is mapped to
//     <0=> Disabled
//     <1=> PTC2 (Alias:D6)<selection=PTC2_SIG_SEL,FB_AD12>
//     <0=> Default
#define FB_AD12_PIN_SEL      0
#if FB_AD12_PIN_SEL == 1
#define FB_AD12_GPIO         digitalIO_PTC2
#define FB_AD12_FN           5
#endif

// Pin Mapping for FB_AD13 signal
//   <o> FB_AD13 [PTC1]<name=FB_AD13_PIN_SEL>
//   <i> Shows which pin FB_AD13 is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,FB_AD13>
//     <0=> Default
#define FB_AD13_PIN_SEL      0
#if FB_AD13_PIN_SEL == 1
#define FB_AD13_GPIO         digitalIO_PTC1
#define FB_AD13_FN           5
#endif

// Pin Mapping for FB_AD14 signal
//   <o> FB_AD14 [PTC0]<name=FB_AD14_PIN_SEL>
//   <i> Shows which pin FB_AD14 is mapped to
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,FB_AD14>
//     <0=> Default
#define FB_AD14_PIN_SEL      0
#if FB_AD14_PIN_SEL == 1
#define FB_AD14_GPIO         digitalIO_PTC0
#define FB_AD14_FN           5
#endif

// Pin Mapping for FB_AD15 signal
//   <o> FB_AD15 [PTB18]<name=FB_AD15_PIN_SEL>
//   <i> Shows which pin FB_AD15 is mapped to
//     <0=> Disabled
//     <1=> PTB18<selection=PTB18_SIG_SEL,FB_AD15>
//     <0=> Default
#define FB_AD15_PIN_SEL      0
#if FB_AD15_PIN_SEL == 1
#define FB_AD15_GPIO         digitalIO_PTB18
#define FB_AD15_FN           5
#endif

// Pin Mapping for FB_AD16 signal
//   <o> FB_AD16 [PTB17]<name=FB_AD16_PIN_SEL>
//   <i> Shows which pin FB_AD16 is mapped to
//     <0=> Disabled
//     <1=> PTB17<selection=PTB17_SIG_SEL,FB_AD16>
//     <0=> Default
#define FB_AD16_PIN_SEL      0
#if FB_AD16_PIN_SEL == 1
#define FB_AD16_GPIO         digitalIO_PTB17
#define FB_AD16_FN           5
#endif

// Pin Mapping for FB_AD17 signal
//   <o> FB_AD17 [PTB16]<name=FB_AD17_PIN_SEL>
//   <i> Shows which pin FB_AD17 is mapped to
//     <0=> Disabled
//     <1=> PTB16<selection=PTB16_SIG_SEL,FB_AD17>
//     <0=> Default
#define FB_AD17_PIN_SEL      0
#if FB_AD17_PIN_SEL == 1
#define FB_AD17_GPIO         digitalIO_PTB16
#define FB_AD17_FN           5
#endif

// Pin Mapping for FB_AD18 signal
//   <o> FB_AD18 [PTB11]<name=FB_AD18_PIN_SEL>
//   <i> Shows which pin FB_AD18 is mapped to
//     <0=> Disabled
//     <1=> PTB11 (Alias:A3)<selection=PTB11_SIG_SEL,FB_AD18>
//     <0=> Default
#define FB_AD18_PIN_SEL      0
#if FB_AD18_PIN_SEL == 1
#define FB_AD18_GPIO         digitalIO_PTB11
#define FB_AD18_FN           5
#endif

// Pin Mapping for FB_AD19 signal
//   <o> FB_AD19 [PTB10]<name=FB_AD19_PIN_SEL>
//   <i> Shows which pin FB_AD19 is mapped to
//     <0=> Disabled
//     <1=> PTB10 (Alias:A2)<selection=PTB10_SIG_SEL,FB_AD19>
//     <0=> Default
#define FB_AD19_PIN_SEL      0
#if FB_AD19_PIN_SEL == 1
#define FB_AD19_GPIO         digitalIO_PTB10
#define FB_AD19_FN           5
#endif

// Pin Mapping for FB_AD20 signal
//   <o> FB_AD20 [PTB9]<name=FB_AD20_PIN_SEL>
//   <i> Shows which pin FB_AD20 is mapped to
//     <0=> Disabled
//     <1=> PTB9 (Alias:D2)<selection=PTB9_SIG_SEL,FB_AD20>
//     <0=> Default
#define FB_AD20_PIN_SEL      0
#if FB_AD20_PIN_SEL == 1
#define FB_AD20_GPIO         digitalIO_PTB9
#define FB_AD20_FN           5
#endif

// Pin Mapping for FB_AD21 signal
//   <o> FB_AD21 [PTB8]<name=FB_AD21_PIN_SEL>
//   <i> Shows which pin FB_AD21 is mapped to
//     <0=> Disabled
//     <1=> PTB8<selection=PTB8_SIG_SEL,FB_AD21>
//     <0=> Default
#define FB_AD21_PIN_SEL      0
#if FB_AD21_PIN_SEL == 1
#define FB_AD21_GPIO         digitalIO_PTB8
#define FB_AD21_FN           5
#endif

// Pin Mapping for FB_AD22 signal
//   <o> FB_AD22 [PTB7]<name=FB_AD22_PIN_SEL>
//   <i> Shows which pin FB_AD22 is mapped to
//     <0=> Disabled
//     <1=> PTB7<selection=PTB7_SIG_SEL,FB_AD22>
//     <0=> Default
#define FB_AD22_PIN_SEL      0
#if FB_AD22_PIN_SEL == 1
#define FB_AD22_GPIO         digitalIO_PTB7
#define FB_AD22_FN           5
#endif

// Pin Mapping for FB_AD23 signal
//   <o> FB_AD23 [PTB6]<name=FB_AD23_PIN_SEL>
//   <i> Shows which pin FB_AD23 is mapped to
//     <0=> Disabled
//     <1=> PTB6<selection=PTB6_SIG_SEL,FB_AD23>
//     <0=> Default
#define FB_AD23_PIN_SEL      0
#if FB_AD23_PIN_SEL == 1
#define FB_AD23_GPIO         digitalIO_PTB6
#define FB_AD23_FN           5
#endif

// Pin Mapping for FB_AD24 signal
//   <o> FB_AD24 [PTC15]<name=FB_AD24_PIN_SEL>
//   <i> Shows which pin FB_AD24 is mapped to
//     <0=> Disabled
//     <1=> PTC15<selection=PTC15_SIG_SEL,FB_AD24>
//     <0=> Default
#define FB_AD24_PIN_SEL      0
#if FB_AD24_PIN_SEL == 1
#define FB_AD24_GPIO         digitalIO_PTC15
#define FB_AD24_FN           5
#endif

// Pin Mapping for FB_AD25 signal
//   <o> FB_AD25 [PTC14]<name=FB_AD25_PIN_SEL>
//   <i> Shows which pin FB_AD25 is mapped to
//     <0=> Disabled
//     <1=> PTC14<selection=PTC14_SIG_SEL,FB_AD25>
//     <0=> Default
#define FB_AD25_PIN_SEL      0
#if FB_AD25_PIN_SEL == 1
#define FB_AD25_GPIO         digitalIO_PTC14
#define FB_AD25_FN           5
#endif

// Pin Mapping for FB_AD26 signal
//   <o> FB_AD26 [PTC13]<name=FB_AD26_PIN_SEL>
//   <i> Shows which pin FB_AD26 is mapped to
//     <0=> Disabled
//     <1=> PTC13<selection=PTC13_SIG_SEL,FB_AD26>
//     <0=> Default
#define FB_AD26_PIN_SEL      0
#if FB_AD26_PIN_SEL == 1
#define FB_AD26_GPIO         digitalIO_PTC13
#define FB_AD26_FN           5
#endif

// Pin Mapping for FB_AD27 signal
//   <o> FB_AD27 [PTC12]<name=FB_AD27_PIN_SEL>
//   <i> Shows which pin FB_AD27 is mapped to
//     <0=> Disabled
//     <1=> PTC12<selection=PTC12_SIG_SEL,FB_AD27>
//     <0=> Default
#define FB_AD27_PIN_SEL      0
#if FB_AD27_PIN_SEL == 1
#define FB_AD27_GPIO         digitalIO_PTC12
#define FB_AD27_FN           5
#endif

// Pin Mapping for FB_AD28 signal
//   <o> FB_AD28 [PTB23]<name=FB_AD28_PIN_SEL>
//   <i> Shows which pin FB_AD28 is mapped to
//     <0=> Disabled
//     <1=> PTB23 (Alias:D4)<selection=PTB23_SIG_SEL,FB_AD28>
//     <0=> Default
#define FB_AD28_PIN_SEL      0
#if FB_AD28_PIN_SEL == 1
#define FB_AD28_GPIO         digitalIO_PTB23
#define FB_AD28_FN           5
#endif

// Pin Mapping for FB_AD29 signal
//   <o> FB_AD29 [PTB22]<name=FB_AD29_PIN_SEL>
//   <i> Shows which pin FB_AD29 is mapped to
//     <0=> Disabled
//     <1=> PTB22 (Alias:LED_RED)<selection=PTB22_SIG_SEL,FB_AD29>
//     <0=> Default
#define FB_AD29_PIN_SEL      0
#if FB_AD29_PIN_SEL == 1
#define FB_AD29_GPIO         digitalIO_PTB22
#define FB_AD29_FN           5
#endif

// Pin Mapping for FB_AD30 signal
//   <o> FB_AD30 [PTB21]<name=FB_AD30_PIN_SEL>
//   <i> Shows which pin FB_AD30 is mapped to
//     <0=> Disabled
//     <1=> PTB21 (Alias:LED_BLUE)<selection=PTB21_SIG_SEL,FB_AD30>
//     <0=> Default
#define FB_AD30_PIN_SEL      0
#if FB_AD30_PIN_SEL == 1
#define FB_AD30_GPIO         digitalIO_PTB21
#define FB_AD30_FN           5
#endif

// Pin Mapping for FB_AD31 signal
//   <o> FB_AD31 [PTB20]<name=FB_AD31_PIN_SEL>
//   <i> Shows which pin FB_AD31 is mapped to
//     <0=> Disabled
//     <1=> PTB20<selection=PTB20_SIG_SEL,FB_AD31>
//     <0=> Default
#define FB_AD31_PIN_SEL      0
#if FB_AD31_PIN_SEL == 1
#define FB_AD31_GPIO         digitalIO_PTB20
#define FB_AD31_FN           5
#endif

// Pin Mapping for FB_ALE signal
//   <o> FB_ALE [PTD0]<name=FB_ALE_PIN_SEL>
//   <i> Shows which pin FB_ALE is mapped to
//     <0=> Disabled
//     <1=> PTD0 (Alias:D10)<selection=PTD0_SIG_SEL,FB_ALE/FB_CS1_b/FB_TS_b>
//     <0=> Default
#define FB_ALE_PIN_SEL       0
#if FB_ALE_PIN_SEL == 1
#define FB_ALE_GPIO          digitalIO_PTD0
#define FB_ALE_FN            5
#endif

// Pin Mapping for FB_BE7_0_BLS31_24_b signal
//   <o> FB_BE7_0_BLS31_24_b [PTC19]<name=FB_BE7_0_BLS31_24_b_PIN_SEL>
//   <i> Shows which pin FB_BE7_0_BLS31_24_b is mapped to
//     <0=> Disabled
//     <1=> PTC19<selection=PTC19_SIG_SEL,FB_CS3_b/FB_BE7_0_BLS31_24_b>
//     <0=> Default
#define FB_BE7_0_BLS31_24_b_PIN_SEL 0
#if FB_BE7_0_BLS31_24_b_PIN_SEL == 1
#define FB_BE7_0_BLS31_24_b_GPIO digitalIO_PTC19
#define FB_BE7_0_BLS31_24_b_FN 5
#endif

// Pin Mapping for FB_BE15_8_BLS23_16_b signal
//   <o> FB_BE15_8_BLS23_16_b [PTC18]<name=FB_BE15_8_BLS23_16_b_PIN_SEL>
//   <i> Shows which pin FB_BE15_8_BLS23_16_b is mapped to
//     <0=> Disabled
//     <1=> PTC18<selection=PTC18_SIG_SEL,FB_TBST_b/FB_CS2_b/FB_BE15_8_BLS23_16_b>
//     <0=> Default
#define FB_BE15_8_BLS23_16_b_PIN_SEL 0
#if FB_BE15_8_BLS23_16_b_PIN_SEL == 1
#define FB_BE15_8_BLS23_16_b_GPIO digitalIO_PTC18
#define FB_BE15_8_BLS23_16_b_FN 5
#endif

// Pin Mapping for FB_BE23_16_BLS15_8_b signal
//   <o> FB_BE23_16_BLS15_8_b [PTC16]<name=FB_BE23_16_BLS15_8_b_PIN_SEL>
//   <i> Shows which pin FB_BE23_16_BLS15_8_b is mapped to
//     <0=> Disabled
//     <1=> PTC16 (Alias:D0)<selection=PTC16_SIG_SEL,FB_CS5_b/FB_TSIZ1/FB_BE23_16_BLS15_8_b>
//     <0=> Default
#define FB_BE23_16_BLS15_8_b_PIN_SEL 0
#if FB_BE23_16_BLS15_8_b_PIN_SEL == 1
#define FB_BE23_16_BLS15_8_b_GPIO digitalIO_PTC16
#define FB_BE23_16_BLS15_8_b_FN 5
#endif

// Pin Mapping for FB_BE31_24_BLS7_0_b signal
//   <o> FB_BE31_24_BLS7_0_b [PTC17]<name=FB_BE31_24_BLS7_0_b_PIN_SEL>
//   <i> Shows which pin FB_BE31_24_BLS7_0_b is mapped to
//     <0=> Disabled
//     <1=> PTC17 (Alias:D1)<selection=PTC17_SIG_SEL,FB_CS4_b/FB_TSIZ0/FB_BE31_24_BLS7_0_b>
//     <0=> Default
#define FB_BE31_24_BLS7_0_b_PIN_SEL 0
#if FB_BE31_24_BLS7_0_b_PIN_SEL == 1
#define FB_BE31_24_BLS7_0_b_GPIO digitalIO_PTC17
#define FB_BE31_24_BLS7_0_b_FN 5
#endif

// Pin Mapping for FB_CS0_b signal
//   <o> FB_CS0_b [PTD1]<name=FB_CS0_b_PIN_SEL>
//   <i> Shows which pin FB_CS0_b is mapped to
//     <0=> Disabled
//     <1=> PTD1 (Alias:D13)<selection=PTD1_SIG_SEL,FB_CS0_b>
//     <0=> Default
#define FB_CS0_b_PIN_SEL     0
#if FB_CS0_b_PIN_SEL == 1
#define FB_CS0_b_GPIO        digitalIO_PTD1
#define FB_CS0_b_FN          5
#endif

// Pin Mapping for FB_CS1_b signal
//   <o> FB_CS1_b [PTD0]<name=FB_CS1_b_PIN_SEL>
//   <i> Shows which pin FB_CS1_b is mapped to
//     <0=> Disabled
//     <1=> PTD0 (Alias:D10)<selection=PTD0_SIG_SEL,FB_ALE/FB_CS1_b/FB_TS_b>
//     <0=> Default
#define FB_CS1_b_PIN_SEL     0
#if FB_CS1_b_PIN_SEL == 1
#define FB_CS1_b_GPIO        digitalIO_PTD0
#define FB_CS1_b_FN          5
#endif

// Pin Mapping for FB_CS2_b signal
//   <o> FB_CS2_b [PTC18]<name=FB_CS2_b_PIN_SEL>
//   <i> Shows which pin FB_CS2_b is mapped to
//     <0=> Disabled
//     <1=> PTC18<selection=PTC18_SIG_SEL,FB_TBST_b/FB_CS2_b/FB_BE15_8_BLS23_16_b>
//     <0=> Default
#define FB_CS2_b_PIN_SEL     0
#if FB_CS2_b_PIN_SEL == 1
#define FB_CS2_b_GPIO        digitalIO_PTC18
#define FB_CS2_b_FN          5
#endif

// Pin Mapping for FB_CS3_b signal
//   <o> FB_CS3_b [PTC19]<name=FB_CS3_b_PIN_SEL>
//   <i> Shows which pin FB_CS3_b is mapped to
//     <0=> Disabled
//     <1=> PTC19<selection=PTC19_SIG_SEL,FB_CS3_b/FB_BE7_0_BLS31_24_b>
//     <0=> Default
#define FB_CS3_b_PIN_SEL     0
#if FB_CS3_b_PIN_SEL == 1
#define FB_CS3_b_GPIO        digitalIO_PTC19
#define FB_CS3_b_FN          5
#endif

// Pin Mapping for FB_CS4_b signal
//   <o> FB_CS4_b [PTC17]<name=FB_CS4_b_PIN_SEL>
//   <i> Shows which pin FB_CS4_b is mapped to
//     <0=> Disabled
//     <1=> PTC17 (Alias:D1)<selection=PTC17_SIG_SEL,FB_CS4_b/FB_TSIZ0/FB_BE31_24_BLS7_0_b>
//     <0=> Default
#define FB_CS4_b_PIN_SEL     0
#if FB_CS4_b_PIN_SEL == 1
#define FB_CS4_b_GPIO        digitalIO_PTC17
#define FB_CS4_b_FN          5
#endif

// Pin Mapping for FB_CS5_b signal
//   <o> FB_CS5_b [PTC16]<name=FB_CS5_b_PIN_SEL>
//   <i> Shows which pin FB_CS5_b is mapped to
//     <0=> Disabled
//     <1=> PTC16 (Alias:D0)<selection=PTC16_SIG_SEL,FB_CS5_b/FB_TSIZ1/FB_BE23_16_BLS15_8_b>
//     <0=> Default
#define FB_CS5_b_PIN_SEL     0
#if FB_CS5_b_PIN_SEL == 1
#define FB_CS5_b_GPIO        digitalIO_PTC16
#define FB_CS5_b_FN          5
#endif

// Pin Mapping for FB_OE_b signal
//   <o> FB_OE_b [PTB19]<name=FB_OE_b_PIN_SEL>
//   <i> Shows which pin FB_OE_b is mapped to
//     <0=> Disabled
//     <1=> PTB19<selection=PTB19_SIG_SEL,FB_OE_b>
//     <0=> Default
#define FB_OE_b_PIN_SEL      0
#if FB_OE_b_PIN_SEL == 1
#define FB_OE_b_GPIO         digitalIO_PTB19
#define FB_OE_b_FN           5
#endif

// Pin Mapping for FB_RW_b signal
//   <o> FB_RW_b [PTC11]<name=FB_RW_b_PIN_SEL>
//   <i> Shows which pin FB_RW_b is mapped to
//     <0=> Disabled
//     <1=> PTC11 (Alias:A4)<selection=PTC11_SIG_SEL,FB_RW_b>
//     <0=> Default
#define FB_RW_b_PIN_SEL      0
#if FB_RW_b_PIN_SEL == 1
#define FB_RW_b_GPIO         digitalIO_PTC11
#define FB_RW_b_FN           5
#endif

// Pin Mapping for FB_TA_b signal
//   <o> FB_TA_b [PTC19]<name=FB_TA_b_PIN_SEL>
//   <i> Shows which pin FB_TA_b is mapped to
//     <0=> Disabled
//     <1=> PTC19<selection=PTC19_SIG_SEL,FB_TA_b>
//     <0=> Default
#define FB_TA_b_PIN_SEL      0
#if FB_TA_b_PIN_SEL == 1
#define FB_TA_b_GPIO         digitalIO_PTC19
#define FB_TA_b_FN           6
#endif

// Pin Mapping for FB_TBST_b signal
//   <o> FB_TBST_b [PTC18]<name=FB_TBST_b_PIN_SEL>
//   <i> Shows which pin FB_TBST_b is mapped to
//     <0=> Disabled
//     <1=> PTC18<selection=PTC18_SIG_SEL,FB_TBST_b/FB_CS2_b/FB_BE15_8_BLS23_16_b>
//     <0=> Default
#define FB_TBST_b_PIN_SEL    0
#if FB_TBST_b_PIN_SEL == 1
#define FB_TBST_b_GPIO       digitalIO_PTC18
#define FB_TBST_b_FN         5
#endif

// Pin Mapping for FB_TSIZ0 signal
//   <o> FB_TSIZ0 [PTC17]<name=FB_TSIZ0_PIN_SEL>
//   <i> Shows which pin FB_TSIZ0 is mapped to
//     <0=> Disabled
//     <1=> PTC17 (Alias:D1)<selection=PTC17_SIG_SEL,FB_CS4_b/FB_TSIZ0/FB_BE31_24_BLS7_0_b>
//     <0=> Default
#define FB_TSIZ0_PIN_SEL     0
#if FB_TSIZ0_PIN_SEL == 1
#define FB_TSIZ0_GPIO        digitalIO_PTC17
#define FB_TSIZ0_FN          5
#endif

// Pin Mapping for FB_TSIZ1 signal
//   <o> FB_TSIZ1 [PTC16]<name=FB_TSIZ1_PIN_SEL>
//   <i> Shows which pin FB_TSIZ1 is mapped to
//     <0=> Disabled
//     <1=> PTC16 (Alias:D0)<selection=PTC16_SIG_SEL,FB_CS5_b/FB_TSIZ1/FB_BE23_16_BLS15_8_b>
//     <0=> Default
#define FB_TSIZ1_PIN_SEL     0
#if FB_TSIZ1_PIN_SEL == 1
#define FB_TSIZ1_GPIO        digitalIO_PTC16
#define FB_TSIZ1_FN          5
#endif

// Pin Mapping for FB_TS_b signal
//   <o> FB_TS_b [PTD0]<name=FB_TS_b_PIN_SEL>
//   <i> Shows which pin FB_TS_b is mapped to
//     <0=> Disabled
//     <1=> PTD0 (Alias:D10)<selection=PTD0_SIG_SEL,FB_ALE/FB_CS1_b/FB_TS_b>
//     <0=> Default
#define FB_TS_b_PIN_SEL      0
#if FB_TS_b_PIN_SEL == 1
#define FB_TS_b_GPIO         digitalIO_PTD0
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
#if FTM0_CH0_PIN_SEL == 1
#define FTM0_CH0_GPIO        digitalIO_PTA3
#define FTM0_CH0_FN          3
#elif FTM0_CH0_PIN_SEL == 2
#define FTM0_CH0_GPIO        digitalIO_PTC1
#define FTM0_CH0_FN          4
#endif

// Pin Mapping for FTM0_CH1 signal
//   <o> FTM0_CH1 [PTA4, PTC2]<name=FTM0_CH1_PIN_SEL>
//   <i> Shows which pin FTM0_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,FTM0_CH1>
//     <2=> PTC2 (Alias:D6)<selection=PTC2_SIG_SEL,FTM0_CH1>
//     <0=> Default
#define FTM0_CH1_PIN_SEL     0
#if FTM0_CH1_PIN_SEL == 1
#define FTM0_CH1_GPIO        digitalIO_PTA4
#define FTM0_CH1_FN          3
#elif FTM0_CH1_PIN_SEL == 2
#define FTM0_CH1_GPIO        digitalIO_PTC2
#define FTM0_CH1_FN          4
#endif

// Pin Mapping for FTM0_CH2 signal
//   <o> FTM0_CH2 [PTA5, PTC3, PTC5]<name=FTM0_CH2_PIN_SEL>
//   <i> Shows which pin FTM0_CH2 is mapped to
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,FTM0_CH2>
//     <2=> PTC3 (Alias:D7)<selection=PTC3_SIG_SEL,FTM0_CH2>
//     <3=> PTC5<selection=PTC5_SIG_SEL,FTM0_CH2>
//     <0=> Default
#define FTM0_CH2_PIN_SEL     0
#if FTM0_CH2_PIN_SEL == 1
#define FTM0_CH2_GPIO        digitalIO_PTA5
#define FTM0_CH2_FN          3
#elif FTM0_CH2_PIN_SEL == 2
#define FTM0_CH2_GPIO        digitalIO_PTC3
#define FTM0_CH2_FN          4
#elif FTM0_CH2_PIN_SEL == 3
#define FTM0_CH2_GPIO        digitalIO_PTC5
#define FTM0_CH2_FN          7
#endif

// Pin Mapping for FTM0_CH3 signal
//   <o> FTM0_CH3 [PTA6, PTC4]<name=FTM0_CH3_PIN_SEL>
//   <i> Shows which pin FTM0_CH3 is mapped to
//     <0=> Disabled
//     <1=> PTA6<selection=PTA6_SIG_SEL,FTM0_CH3>
//     <2=> PTC4 (Alias:D9)<selection=PTC4_SIG_SEL,FTM0_CH3>
//     <0=> Default
#define FTM0_CH3_PIN_SEL     0
#if FTM0_CH3_PIN_SEL == 1
#define FTM0_CH3_GPIO        digitalIO_PTA6
#define FTM0_CH3_FN          3
#elif FTM0_CH3_PIN_SEL == 2
#define FTM0_CH3_GPIO        digitalIO_PTC4
#define FTM0_CH3_FN          4
#endif

// Pin Mapping for FTM0_CH4 signal
//   <o> FTM0_CH4 [PTA7, PTB12, PTD4]<name=FTM0_CH4_PIN_SEL>
//   <i> Shows which pin FTM0_CH4 is mapped to
//     <0=> Disabled
//     <1=> PTA7<selection=PTA7_SIG_SEL,FTM0_CH4>
//     <2=> PTB12<selection=PTB12_SIG_SEL,FTM0_CH4>
//     <3=> PTD4 (Alias:nRF24L01_cs)<selection=PTD4_SIG_SEL,FTM0_CH4>
//     <0=> Default
#define FTM0_CH4_PIN_SEL     0
#if FTM0_CH4_PIN_SEL == 1
#define FTM0_CH4_GPIO        digitalIO_PTA7
#define FTM0_CH4_FN          3
#elif FTM0_CH4_PIN_SEL == 2
#define FTM0_CH4_GPIO        digitalIO_PTB12
#define FTM0_CH4_FN          4
#elif FTM0_CH4_PIN_SEL == 3
#define FTM0_CH4_GPIO        digitalIO_PTD4
#define FTM0_CH4_FN          4
#endif

// Pin Mapping for FTM0_CH5 signal
//   <o> FTM0_CH5 [PTA0, PTB13, PTD5]<name=FTM0_CH5_PIN_SEL>
//   <i> Shows which pin FTM0_CH5 is mapped to
//     <0=> Disabled
//     <1=> PTA0 (Alias:D8)<selection=PTA0_SIG_SEL,FTM0_CH5>
//     <2=> PTB13<selection=PTB13_SIG_SEL,FTM0_CH5>
//     <3=> PTD5 (Alias:nRF24L01_sck)<selection=PTD5_SIG_SEL,FTM0_CH5>
//     <0=> Default
#define FTM0_CH5_PIN_SEL     0
#if FTM0_CH5_PIN_SEL == 1
#define FTM0_CH5_GPIO        digitalIO_PTA0
#define FTM0_CH5_FN          3
#elif FTM0_CH5_PIN_SEL == 2
#define FTM0_CH5_GPIO        digitalIO_PTB13
#define FTM0_CH5_FN          4
#elif FTM0_CH5_PIN_SEL == 3
#define FTM0_CH5_GPIO        digitalIO_PTD5
#define FTM0_CH5_FN          4
#endif

// Pin Mapping for FTM0_CH6 signal
//   <o> FTM0_CH6 [PTA1, PTD6]<name=FTM0_CH6_PIN_SEL>
//   <i> Shows which pin FTM0_CH6 is mapped to
//     <0=> Disabled
//     <1=> PTA1 (Alias:D3)<selection=PTA1_SIG_SEL,FTM0_CH6>
//     <2=> PTD6 (Alias:nRF24L01_mosi)<selection=PTD6_SIG_SEL,FTM0_CH6>
//     <0=> Default
#define FTM0_CH6_PIN_SEL     0
#if FTM0_CH6_PIN_SEL == 1
#define FTM0_CH6_GPIO        digitalIO_PTA1
#define FTM0_CH6_FN          3
#elif FTM0_CH6_PIN_SEL == 2
#define FTM0_CH6_GPIO        digitalIO_PTD6
#define FTM0_CH6_FN          4
#endif

// Pin Mapping for FTM0_CH7 signal
//   <o> FTM0_CH7 [PTA2, PTD7]<name=FTM0_CH7_PIN_SEL>
//   <i> Shows which pin FTM0_CH7 is mapped to
//     <0=> Disabled
//     <1=> PTA2 (Alias:D5)<selection=PTA2_SIG_SEL,FTM0_CH7>
//     <2=> PTD7 (Alias:nRF24L01_miso)<selection=PTD7_SIG_SEL,FTM0_CH7>
//     <0=> Default
#define FTM0_CH7_PIN_SEL     0
#if FTM0_CH7_PIN_SEL == 1
#define FTM0_CH7_GPIO        digitalIO_PTA2
#define FTM0_CH7_FN          3
#elif FTM0_CH7_PIN_SEL == 2
#define FTM0_CH7_GPIO        digitalIO_PTD7
#define FTM0_CH7_FN          4
#endif

// Pin Mapping for FTM0_FLT0 signal
//   <o> FTM0_FLT0 [PTB3, PTD6]<name=FTM0_FLT0_PIN_SEL>
//   <i> Shows which pin FTM0_FLT0 is mapped to
//     <0=> Disabled
//     <1=> PTB3 (Alias:A1)<selection=PTB3_SIG_SEL,FTM0_FLT0>
//     <2=> PTD6 (Alias:nRF24L01_mosi)<selection=PTD6_SIG_SEL,FTM0_FLT0>
//     <0=> Default
#define FTM0_FLT0_PIN_SEL    0
#if FTM0_FLT0_PIN_SEL == 1
#define FTM0_FLT0_GPIO       digitalIO_PTB3
#define FTM0_FLT0_FN         6
#elif FTM0_FLT0_PIN_SEL == 2
#define FTM0_FLT0_GPIO       digitalIO_PTD6
#define FTM0_FLT0_FN         6
#endif

// Pin Mapping for FTM0_FLT1 signal
//   <o> FTM0_FLT1 [PTB10, PTD7]<name=FTM0_FLT1_PIN_SEL>
//   <i> Shows which pin FTM0_FLT1 is mapped to
//     <0=> Disabled
//     <1=> PTB10 (Alias:A2)<selection=PTB10_SIG_SEL,FTM0_FLT1>
//     <2=> PTD7 (Alias:nRF24L01_miso)<selection=PTD7_SIG_SEL,FTM0_FLT1>
//     <0=> Default
#define FTM0_FLT1_PIN_SEL    0
#if FTM0_FLT1_PIN_SEL == 1
#define FTM0_FLT1_GPIO       digitalIO_PTB10
#define FTM0_FLT1_FN         6
#elif FTM0_FLT1_PIN_SEL == 2
#define FTM0_FLT1_GPIO       digitalIO_PTD7
#define FTM0_FLT1_FN         6
#endif

// Pin Mapping for FTM0_FLT2 signal
//   <o> FTM0_FLT2 [PTA18, PTB11]<name=FTM0_FLT2_PIN_SEL>
//   <i> Shows which pin FTM0_FLT2 is mapped to
//     <0=> Disabled
//     <1=> PTA18<selection=PTA18_SIG_SEL,FTM0_FLT2>
//     <2=> PTB11 (Alias:A3)<selection=PTB11_SIG_SEL,FTM0_FLT2>
//     <0=> Default
#define FTM0_FLT2_PIN_SEL    0
#if FTM0_FLT2_PIN_SEL == 1
#define FTM0_FLT2_GPIO       digitalIO_PTA18
#define FTM0_FLT2_FN         3
#elif FTM0_FLT2_PIN_SEL == 2
#define FTM0_FLT2_GPIO       digitalIO_PTB11
#define FTM0_FLT2_FN         6
#endif

// Pin Mapping for FTM0_FLT3 signal
//   <o> FTM0_FLT3 [PTB2]<name=FTM0_FLT3_PIN_SEL>
//   <i> Shows which pin FTM0_FLT3 is mapped to
//     <0=> Disabled
//     <1=> PTB2 (Alias:A0)<selection=PTB2_SIG_SEL,FTM0_FLT3>
//     <0=> Default
#define FTM0_FLT3_PIN_SEL    0
#if FTM0_FLT3_PIN_SEL == 1
#define FTM0_FLT3_GPIO       digitalIO_PTB2
#define FTM0_FLT3_FN         6
#endif

// </h>

// <h> FlexTimer (FTM1)

// Pin Mapping for FTM1_CH0 signal
//   <o> FTM1_CH0 [PTA8, PTA12, PTB0, PTB12]<name=FTM1_CH0_PIN_SEL>
//   <i> Shows which pin FTM1_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTA8<selection=PTA8_SIG_SEL,FTM1_CH0>
//     <2=> PTA12<selection=PTA12_SIG_SEL,FTM1_CH0>
//     <3=> PTB0<selection=PTB0_SIG_SEL,FTM1_CH0>
//     <4=> PTB12<selection=PTB12_SIG_SEL,FTM1_CH0>
//     <0=> Default
#define FTM1_CH0_PIN_SEL     0
#if FTM1_CH0_PIN_SEL == 1
#define FTM1_CH0_GPIO        digitalIO_PTA8
#define FTM1_CH0_FN          3
#elif FTM1_CH0_PIN_SEL == 2
#define FTM1_CH0_GPIO        digitalIO_PTA12
#define FTM1_CH0_FN          3
#elif FTM1_CH0_PIN_SEL == 3
#define FTM1_CH0_GPIO        digitalIO_PTB0
#define FTM1_CH0_FN          3
#elif FTM1_CH0_PIN_SEL == 4
#define FTM1_CH0_GPIO        digitalIO_PTB12
#define FTM1_CH0_FN          3
#endif

// Pin Mapping for FTM1_CH1 signal
//   <o> FTM1_CH1 [PTA9, PTA13, PTB1, PTB13]<name=FTM1_CH1_PIN_SEL>
//   <i> Shows which pin FTM1_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTA9<selection=PTA9_SIG_SEL,FTM1_CH1>
//     <2=> PTA13<selection=PTA13_SIG_SEL,FTM1_CH1>
//     <3=> PTB1<selection=PTB1_SIG_SEL,FTM1_CH1>
//     <4=> PTB13<selection=PTB13_SIG_SEL,FTM1_CH1>
//     <0=> Default
#define FTM1_CH1_PIN_SEL     0
#if FTM1_CH1_PIN_SEL == 1
#define FTM1_CH1_GPIO        digitalIO_PTA9
#define FTM1_CH1_FN          3
#elif FTM1_CH1_PIN_SEL == 2
#define FTM1_CH1_GPIO        digitalIO_PTA13
#define FTM1_CH1_FN          3
#elif FTM1_CH1_PIN_SEL == 3
#define FTM1_CH1_GPIO        digitalIO_PTB1
#define FTM1_CH1_FN          3
#elif FTM1_CH1_PIN_SEL == 4
#define FTM1_CH1_GPIO        digitalIO_PTB13
#define FTM1_CH1_FN          3
#endif

// Pin Mapping for FTM1_FLT0 signal
//   <o> FTM1_FLT0 [PTA19, PTB4]<name=FTM1_FLT0_PIN_SEL>
//   <i> Shows which pin FTM1_FLT0 is mapped to
//     <0=> Disabled
//     <1=> PTA19<selection=PTA19_SIG_SEL,FTM1_FLT0>
//     <2=> PTB4<selection=PTB4_SIG_SEL,FTM1_FLT0>
//     <0=> Default
#define FTM1_FLT0_PIN_SEL    0
#if FTM1_FLT0_PIN_SEL == 1
#define FTM1_FLT0_GPIO       digitalIO_PTA19
#define FTM1_FLT0_FN         3
#elif FTM1_FLT0_PIN_SEL == 2
#define FTM1_FLT0_GPIO       digitalIO_PTB4
#define FTM1_FLT0_FN         6
#endif

// Pin Mapping for FTM1_QD_PHA signal
//   <o> FTM1_QD_PHA [PTA8, PTB0, PTB12, PTA12]<name=FTM1_QD_PHA_PIN_SEL>
//   <i> Shows which pin FTM1_QD_PHA is mapped to
//     <0=> Disabled
//     <1=> PTA8<selection=PTA8_SIG_SEL,FTM1_QD_PHA>
//     <2=> PTB0<selection=PTB0_SIG_SEL,FTM1_QD_PHA>
//     <3=> PTB12<selection=PTB12_SIG_SEL,FTM1_QD_PHA>
//     <4=> PTA12<selection=PTA12_SIG_SEL,FTM1_QD_PHA>
//     <0=> Default
#define FTM1_QD_PHA_PIN_SEL  0
#if FTM1_QD_PHA_PIN_SEL == 1
#define FTM1_QD_PHA_GPIO     digitalIO_PTA8
#define FTM1_QD_PHA_FN       6
#elif FTM1_QD_PHA_PIN_SEL == 2
#define FTM1_QD_PHA_GPIO     digitalIO_PTB0
#define FTM1_QD_PHA_FN       6
#elif FTM1_QD_PHA_PIN_SEL == 3
#define FTM1_QD_PHA_GPIO     digitalIO_PTB12
#define FTM1_QD_PHA_FN       6
#elif FTM1_QD_PHA_PIN_SEL == 4
#define FTM1_QD_PHA_GPIO     digitalIO_PTA12
#define FTM1_QD_PHA_FN       7
#endif

// Pin Mapping for FTM1_QD_PHB signal
//   <o> FTM1_QD_PHB [PTA9, PTB1, PTB13, PTA13]<name=FTM1_QD_PHB_PIN_SEL>
//   <i> Shows which pin FTM1_QD_PHB is mapped to
//     <0=> Disabled
//     <1=> PTA9<selection=PTA9_SIG_SEL,FTM1_QD_PHB>
//     <2=> PTB1<selection=PTB1_SIG_SEL,FTM1_QD_PHB>
//     <3=> PTB13<selection=PTB13_SIG_SEL,FTM1_QD_PHB>
//     <4=> PTA13<selection=PTA13_SIG_SEL,FTM1_QD_PHB>
//     <0=> Default
#define FTM1_QD_PHB_PIN_SEL  0
#if FTM1_QD_PHB_PIN_SEL == 1
#define FTM1_QD_PHB_GPIO     digitalIO_PTA9
#define FTM1_QD_PHB_FN       6
#elif FTM1_QD_PHB_PIN_SEL == 2
#define FTM1_QD_PHB_GPIO     digitalIO_PTB1
#define FTM1_QD_PHB_FN       6
#elif FTM1_QD_PHB_PIN_SEL == 3
#define FTM1_QD_PHB_GPIO     digitalIO_PTB13
#define FTM1_QD_PHB_FN       6
#elif FTM1_QD_PHB_PIN_SEL == 4
#define FTM1_QD_PHB_GPIO     digitalIO_PTA13
#define FTM1_QD_PHB_FN       7
#endif

// </h>

// <h> FlexTimer (FTM2)

// Pin Mapping for FTM2_CH0 signal
//   <o> FTM2_CH0 [PTA10, PTB18]<name=FTM2_CH0_PIN_SEL>
//   <i> Shows which pin FTM2_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTA10<selection=PTA10_SIG_SEL,FTM2_CH0>
//     <2=> PTB18<selection=PTB18_SIG_SEL,FTM2_CH0>
//     <0=> Default
#define FTM2_CH0_PIN_SEL     0
#if FTM2_CH0_PIN_SEL == 1
#define FTM2_CH0_GPIO        digitalIO_PTA10
#define FTM2_CH0_FN          3
#elif FTM2_CH0_PIN_SEL == 2
#define FTM2_CH0_GPIO        digitalIO_PTB18
#define FTM2_CH0_FN          3
#endif

// Pin Mapping for FTM2_CH1 signal
//   <o> FTM2_CH1 [PTA11, PTB19]<name=FTM2_CH1_PIN_SEL>
//   <i> Shows which pin FTM2_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTA11<selection=PTA11_SIG_SEL,FTM2_CH1>
//     <2=> PTB19<selection=PTB19_SIG_SEL,FTM2_CH1>
//     <0=> Default
#define FTM2_CH1_PIN_SEL     0
#if FTM2_CH1_PIN_SEL == 1
#define FTM2_CH1_GPIO        digitalIO_PTA11
#define FTM2_CH1_FN          3
#elif FTM2_CH1_PIN_SEL == 2
#define FTM2_CH1_GPIO        digitalIO_PTB19
#define FTM2_CH1_FN          3
#endif

// Pin Mapping for FTM2_FLT0 signal
//   <o> FTM2_FLT0 [PTB5, PTC9]<name=FTM2_FLT0_PIN_SEL>
//   <i> Shows which pin FTM2_FLT0 is mapped to
//     <0=> Disabled
//     <1=> PTB5<selection=PTB5_SIG_SEL,FTM2_FLT0>
//     <2=> PTC9<selection=PTC9_SIG_SEL,FTM2_FLT0>
//     <0=> Default
#define FTM2_FLT0_PIN_SEL    0
#if FTM2_FLT0_PIN_SEL == 1
#define FTM2_FLT0_GPIO       digitalIO_PTB5
#define FTM2_FLT0_FN         6
#elif FTM2_FLT0_PIN_SEL == 2
#define FTM2_FLT0_GPIO       digitalIO_PTC9
#define FTM2_FLT0_FN         6
#endif

// Pin Mapping for FTM2_QD_PHA signal
//   <o> FTM2_QD_PHA [PTA10, PTB18]<name=FTM2_QD_PHA_PIN_SEL>
//   <i> Shows which pin FTM2_QD_PHA is mapped to
//     <0=> Disabled
//     <1=> PTA10<selection=PTA10_SIG_SEL,FTM2_QD_PHA>
//     <2=> PTB18<selection=PTB18_SIG_SEL,FTM2_QD_PHA>
//     <0=> Default
#define FTM2_QD_PHA_PIN_SEL  0
#if FTM2_QD_PHA_PIN_SEL == 1
#define FTM2_QD_PHA_GPIO     digitalIO_PTA10
#define FTM2_QD_PHA_FN       6
#elif FTM2_QD_PHA_PIN_SEL == 2
#define FTM2_QD_PHA_GPIO     digitalIO_PTB18
#define FTM2_QD_PHA_FN       6
#endif

// Pin Mapping for FTM2_QD_PHB signal
//   <o> FTM2_QD_PHB [PTA11, PTB19]<name=FTM2_QD_PHB_PIN_SEL>
//   <i> Shows which pin FTM2_QD_PHB is mapped to
//     <0=> Disabled
//     <1=> PTA11<selection=PTA11_SIG_SEL,FTM2_QD_PHB>
//     <2=> PTB19<selection=PTB19_SIG_SEL,FTM2_QD_PHB>
//     <0=> Default
#define FTM2_QD_PHB_PIN_SEL  0
#if FTM2_QD_PHB_PIN_SEL == 1
#define FTM2_QD_PHB_GPIO     digitalIO_PTA11
#define FTM2_QD_PHB_FN       6
#elif FTM2_QD_PHB_PIN_SEL == 2
#define FTM2_QD_PHB_GPIO     digitalIO_PTB19
#define FTM2_QD_PHB_FN       6
#endif

// </h>

// <h> FlexTimer (FTM3)

// Pin Mapping for FTM3_CH0 signal
//   <o> FTM3_CH0 [PTD0, PTE5]<name=FTM3_CH0_PIN_SEL>
//   <i> Shows which pin FTM3_CH0 is mapped to
//     <0=> Disabled
//     <1=> PTD0 (Alias:D10)<selection=PTD0_SIG_SEL,FTM3_CH0>
//     <2=> PTE5<selection=PTE5_SIG_SEL,FTM3_CH0>
//     <0=> Default
#define FTM3_CH0_PIN_SEL     0
#if FTM3_CH0_PIN_SEL == 1
#define FTM3_CH0_GPIO        digitalIO_PTD0
#define FTM3_CH0_FN          4
#elif FTM3_CH0_PIN_SEL == 2
#define FTM3_CH0_GPIO        digitalIO_PTE5
#define FTM3_CH0_FN          6
#endif

// Pin Mapping for FTM3_CH1 signal
//   <o> FTM3_CH1 [PTD1, PTE6]<name=FTM3_CH1_PIN_SEL>
//   <i> Shows which pin FTM3_CH1 is mapped to
//     <0=> Disabled
//     <1=> PTD1 (Alias:D13)<selection=PTD1_SIG_SEL,FTM3_CH1>
//     <2=> PTE6<selection=PTE6_SIG_SEL,FTM3_CH1>
//     <0=> Default
#define FTM3_CH1_PIN_SEL     0
#if FTM3_CH1_PIN_SEL == 1
#define FTM3_CH1_GPIO        digitalIO_PTD1
#define FTM3_CH1_FN          4
#elif FTM3_CH1_PIN_SEL == 2
#define FTM3_CH1_GPIO        digitalIO_PTE6
#define FTM3_CH1_FN          6
#endif

// Pin Mapping for FTM3_CH2 signal
//   <o> FTM3_CH2 [PTD2, PTE7]<name=FTM3_CH2_PIN_SEL>
//   <i> Shows which pin FTM3_CH2 is mapped to
//     <0=> Disabled
//     <1=> PTD2 (Alias:D11)<selection=PTD2_SIG_SEL,FTM3_CH2>
//     <2=> PTE7<selection=PTE7_SIG_SEL,FTM3_CH2>
//     <0=> Default
#define FTM3_CH2_PIN_SEL     0
#if FTM3_CH2_PIN_SEL == 1
#define FTM3_CH2_GPIO        digitalIO_PTD2
#define FTM3_CH2_FN          4
#elif FTM3_CH2_PIN_SEL == 2
#define FTM3_CH2_GPIO        digitalIO_PTE7
#define FTM3_CH2_FN          6
#endif

// Pin Mapping for FTM3_CH3 signal
//   <o> FTM3_CH3 [PTD3, PTE8]<name=FTM3_CH3_PIN_SEL>
//   <i> Shows which pin FTM3_CH3 is mapped to
//     <0=> Disabled
//     <1=> PTD3 (Alias:D12)<selection=PTD3_SIG_SEL,FTM3_CH3>
//     <2=> PTE8<selection=PTE8_SIG_SEL,FTM3_CH3>
//     <0=> Default
#define FTM3_CH3_PIN_SEL     0
#if FTM3_CH3_PIN_SEL == 1
#define FTM3_CH3_GPIO        digitalIO_PTD3
#define FTM3_CH3_FN          4
#elif FTM3_CH3_PIN_SEL == 2
#define FTM3_CH3_GPIO        digitalIO_PTE8
#define FTM3_CH3_FN          6
#endif

// Pin Mapping for FTM3_CH4 signal
//   <o> FTM3_CH4 [PTC8, PTE9]<name=FTM3_CH4_PIN_SEL>
//   <i> Shows which pin FTM3_CH4 is mapped to
//     <0=> Disabled
//     <1=> PTC8<selection=PTC8_SIG_SEL,FTM3_CH4>
//     <2=> PTE9<selection=PTE9_SIG_SEL,FTM3_CH4>
//     <0=> Default
#define FTM3_CH4_PIN_SEL     0
#if FTM3_CH4_PIN_SEL == 1
#define FTM3_CH4_GPIO        digitalIO_PTC8
#define FTM3_CH4_FN          3
#elif FTM3_CH4_PIN_SEL == 2
#define FTM3_CH4_GPIO        digitalIO_PTE9
#define FTM3_CH4_FN          6
#endif

// Pin Mapping for FTM3_CH5 signal
//   <o> FTM3_CH5 [PTC9, PTE10]<name=FTM3_CH5_PIN_SEL>
//   <i> Shows which pin FTM3_CH5 is mapped to
//     <0=> Disabled
//     <1=> PTC9<selection=PTC9_SIG_SEL,FTM3_CH5>
//     <2=> PTE10<selection=PTE10_SIG_SEL,FTM3_CH5>
//     <0=> Default
#define FTM3_CH5_PIN_SEL     0
#if FTM3_CH5_PIN_SEL == 1
#define FTM3_CH5_GPIO        digitalIO_PTC9
#define FTM3_CH5_FN          3
#elif FTM3_CH5_PIN_SEL == 2
#define FTM3_CH5_GPIO        digitalIO_PTE10
#define FTM3_CH5_FN          6
#endif

// Pin Mapping for FTM3_CH6 signal
//   <o> FTM3_CH6 [PTC10, PTE11]<name=FTM3_CH6_PIN_SEL>
//   <i> Shows which pin FTM3_CH6 is mapped to
//     <0=> Disabled
//     <1=> PTC10 (Alias:A5)<selection=PTC10_SIG_SEL,FTM3_CH6>
//     <2=> PTE11<selection=PTE11_SIG_SEL,FTM3_CH6>
//     <0=> Default
#define FTM3_CH6_PIN_SEL     0
#if FTM3_CH6_PIN_SEL == 1
#define FTM3_CH6_GPIO        digitalIO_PTC10
#define FTM3_CH6_FN          3
#elif FTM3_CH6_PIN_SEL == 2
#define FTM3_CH6_GPIO        digitalIO_PTE11
#define FTM3_CH6_FN          6
#endif

// Pin Mapping for FTM3_CH7 signal
//   <o> FTM3_CH7 [PTC11, PTE12]<name=FTM3_CH7_PIN_SEL>
//   <i> Shows which pin FTM3_CH7 is mapped to
//     <0=> Disabled
//     <1=> PTC11 (Alias:A4)<selection=PTC11_SIG_SEL,FTM3_CH7>
//     <2=> PTE12<selection=PTE12_SIG_SEL,FTM3_CH7>
//     <0=> Default
#define FTM3_CH7_PIN_SEL     0
#if FTM3_CH7_PIN_SEL == 1
#define FTM3_CH7_GPIO        digitalIO_PTC11
#define FTM3_CH7_FN          3
#elif FTM3_CH7_PIN_SEL == 2
#define FTM3_CH7_GPIO        digitalIO_PTE12
#define FTM3_CH7_FN          6
#endif

// Pin Mapping for FTM3_FLT0 signal
//   <o> FTM3_FLT0 [PTD12, PTC12]<name=FTM3_FLT0_PIN_SEL>
//   <i> Shows which pin FTM3_FLT0 is mapped to
//     <0=> Disabled
//     <1=> PTD12<selection=PTD12_SIG_SEL,FTM3_FLT0>
//     <2=> PTC12<selection=PTC12_SIG_SEL,FTM3_FLT0>
//     <0=> Default
#define FTM3_FLT0_PIN_SEL    0
#if FTM3_FLT0_PIN_SEL == 1
#define FTM3_FLT0_GPIO       digitalIO_PTD12
#define FTM3_FLT0_FN         3
#elif FTM3_FLT0_PIN_SEL == 2
#define FTM3_FLT0_GPIO       digitalIO_PTC12
#define FTM3_FLT0_FN         6
#endif

// </h>

// <h> General Purpose I/O (GPIOA)

// Pin Mapping for GPIOA_0 signal
//   <o> GPIOA_0 [PTA0]<name=GPIOA_0_PIN_SEL>
//   <i> Shows which pin GPIOA_0 is mapped to
//     <0=> Disabled
//     <1=> PTA0 (Alias:D8)<selection=PTA0_SIG_SEL,GPIOA_0>
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
//     <1=> PTA1 (Alias:D3)<selection=PTA1_SIG_SEL,GPIOA_1>
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
//     <1=> PTA2 (Alias:D5)<selection=PTA2_SIG_SEL,GPIOA_2>
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
//     <1=> PTA4<selection=PTA4_SIG_SEL,GPIOA_4/LLWU_P3>
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

// Pin Mapping for GPIOA_8 signal
//   <o> GPIOA_8 [PTA8]<name=GPIOA_8_PIN_SEL>
//   <i> Shows which pin GPIOA_8 is mapped to
//     <0=> Disabled
//     <1=> PTA8<selection=PTA8_SIG_SEL,GPIOA_8>
//     <0=> Default
#define GPIOA_8_PIN_SEL      0
#if GPIOA_8_PIN_SEL == 1
#define GPIOA_8_GPIO         digitalIO_PTA8
#define GPIOA_8_FN           1
#endif

// Pin Mapping for GPIOA_9 signal
//   <o> GPIOA_9 [PTA9]<name=GPIOA_9_PIN_SEL>
//   <i> Shows which pin GPIOA_9 is mapped to
//     <0=> Disabled
//     <1=> PTA9<selection=PTA9_SIG_SEL,GPIOA_9>
//     <0=> Default
#define GPIOA_9_PIN_SEL      0
#if GPIOA_9_PIN_SEL == 1
#define GPIOA_9_GPIO         digitalIO_PTA9
#define GPIOA_9_FN           1
#endif

// Pin Mapping for GPIOA_10 signal
//   <o> GPIOA_10 [PTA10]<name=GPIOA_10_PIN_SEL>
//   <i> Shows which pin GPIOA_10 is mapped to
//     <0=> Disabled
//     <1=> PTA10<selection=PTA10_SIG_SEL,GPIOA_10>
//     <0=> Default
#define GPIOA_10_PIN_SEL     0
#if GPIOA_10_PIN_SEL == 1
#define GPIOA_10_GPIO        digitalIO_PTA10
#define GPIOA_10_FN          1
#endif

// Pin Mapping for GPIOA_11 signal
//   <o> GPIOA_11 [PTA11]<name=GPIOA_11_PIN_SEL>
//   <i> Shows which pin GPIOA_11 is mapped to
//     <0=> Disabled
//     <1=> PTA11<selection=PTA11_SIG_SEL,GPIOA_11>
//     <0=> Default
#define GPIOA_11_PIN_SEL     0
#if GPIOA_11_PIN_SEL == 1
#define GPIOA_11_GPIO        digitalIO_PTA11
#define GPIOA_11_FN          1
#endif

// Pin Mapping for GPIOA_12 signal
//   <o> GPIOA_12 [PTA12]<name=GPIOA_12_PIN_SEL>
//   <i> Shows which pin GPIOA_12 is mapped to
//     <0=> Disabled
//     <1=> PTA12<selection=PTA12_SIG_SEL,GPIOA_12>
//     <0=> Default
#define GPIOA_12_PIN_SEL     0
#if GPIOA_12_PIN_SEL == 1
#define GPIOA_12_GPIO        digitalIO_PTA12
#define GPIOA_12_FN          1
#endif

// Pin Mapping for GPIOA_13 signal
//   <o> GPIOA_13 [PTA13]<name=GPIOA_13_PIN_SEL>
//   <i> Shows which pin GPIOA_13 is mapped to
//     <0=> Disabled
//     <1=> PTA13<selection=PTA13_SIG_SEL,GPIOA_13/LLWU_P4>
//     <0=> Default
#define GPIOA_13_PIN_SEL     0
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

// Pin Mapping for GPIOA_24 signal
//   <o> GPIOA_24 [PTA24]<name=GPIOA_24_PIN_SEL>
//   <i> Shows which pin GPIOA_24 is mapped to
//     <0=> Disabled
//     <1=> PTA24<selection=PTA24_SIG_SEL,GPIOA_24>
//     <0=> Default
#define GPIOA_24_PIN_SEL     0
#if GPIOA_24_PIN_SEL == 1
#define GPIOA_24_GPIO        digitalIO_PTA24
#define GPIOA_24_FN          1
#endif

// Pin Mapping for GPIOA_25 signal
//   <o> GPIOA_25 [PTA25]<name=GPIOA_25_PIN_SEL>
//   <i> Shows which pin GPIOA_25 is mapped to
//     <0=> Disabled
//     <1=> PTA25<selection=PTA25_SIG_SEL,GPIOA_25>
//     <0=> Default
#define GPIOA_25_PIN_SEL     0
#if GPIOA_25_PIN_SEL == 1
#define GPIOA_25_GPIO        digitalIO_PTA25
#define GPIOA_25_FN          1
#endif

// Pin Mapping for GPIOA_26 signal
//   <o> GPIOA_26 [PTA26]<name=GPIOA_26_PIN_SEL>
//   <i> Shows which pin GPIOA_26 is mapped to
//     <0=> Disabled
//     <1=> PTA26<selection=PTA26_SIG_SEL,GPIOA_26>
//     <0=> Default
#define GPIOA_26_PIN_SEL     0
#if GPIOA_26_PIN_SEL == 1
#define GPIOA_26_GPIO        digitalIO_PTA26
#define GPIOA_26_FN          1
#endif

// Pin Mapping for GPIOA_27 signal
//   <o> GPIOA_27 [PTA27]<name=GPIOA_27_PIN_SEL>
//   <i> Shows which pin GPIOA_27 is mapped to
//     <0=> Disabled
//     <1=> PTA27<selection=PTA27_SIG_SEL,GPIOA_27>
//     <0=> Default
#define GPIOA_27_PIN_SEL     0
#if GPIOA_27_PIN_SEL == 1
#define GPIOA_27_GPIO        digitalIO_PTA27
#define GPIOA_27_FN          1
#endif

// Pin Mapping for GPIOA_28 signal
//   <o> GPIOA_28 [PTA28]<name=GPIOA_28_PIN_SEL>
//   <i> Shows which pin GPIOA_28 is mapped to
//     <0=> Disabled
//     <1=> PTA28<selection=PTA28_SIG_SEL,GPIOA_28>
//     <0=> Default
#define GPIOA_28_PIN_SEL     0
#if GPIOA_28_PIN_SEL == 1
#define GPIOA_28_GPIO        digitalIO_PTA28
#define GPIOA_28_FN          1
#endif

// Pin Mapping for GPIOA_29 signal
//   <o> GPIOA_29 [PTA29]<name=GPIOA_29_PIN_SEL>
//   <i> Shows which pin GPIOA_29 is mapped to
//     <0=> Disabled
//     <1=> PTA29<selection=PTA29_SIG_SEL,GPIOA_29>
//     <0=> Default
#define GPIOA_29_PIN_SEL     0
#if GPIOA_29_PIN_SEL == 1
#define GPIOA_29_GPIO        digitalIO_PTA29
#define GPIOA_29_FN          1
#endif

// </h>

// <h> General Purpose I/O (GPIOB)

// Pin Mapping for GPIOB_0 signal
//   <o> GPIOB_0 [PTB0]<name=GPIOB_0_PIN_SEL>
//   <i> Shows which pin GPIOB_0 is mapped to
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,GPIOB_0/LLWU_P5>
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
//     <1=> PTB2 (Alias:A0)<selection=PTB2_SIG_SEL,GPIOB_2>
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
//     <1=> PTB3 (Alias:A1)<selection=PTB3_SIG_SEL,GPIOB_3>
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
//     <1=> PTB9 (Alias:D2)<selection=PTB9_SIG_SEL,GPIOB_9>
//     <1=> Default
#define GPIOB_9_PIN_SEL      1
#if GPIOB_9_PIN_SEL == 1
#define GPIOB_9_GPIO         digitalIO_PTB9
#define GPIOB_9_FN           1
#endif

// Pin Mapping for GPIOB_10 signal
//   <o> GPIOB_10 [PTB10]<name=GPIOB_10_PIN_SEL>
//   <i> Shows which pin GPIOB_10 is mapped to
//     <0=> Disabled
//     <1=> PTB10 (Alias:A2)<selection=PTB10_SIG_SEL,GPIOB_10>
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
//     <1=> PTB11 (Alias:A3)<selection=PTB11_SIG_SEL,GPIOB_11>
//     <0=> Default
#define GPIOB_11_PIN_SEL     0
#if GPIOB_11_PIN_SEL == 1
#define GPIOB_11_GPIO        digitalIO_PTB11
#define GPIOB_11_FN          1
#endif

// Pin Mapping for GPIOB_12 signal
//   <o> GPIOB_12 [PTB12]<name=GPIOB_12_PIN_SEL>
//   <i> Shows which pin GPIOB_12 is mapped to
//     <0=> Disabled
//     <1=> PTB12<selection=PTB12_SIG_SEL,GPIOB_12>
//     <0=> Default
#define GPIOB_12_PIN_SEL     0
#if GPIOB_12_PIN_SEL == 1
#define GPIOB_12_GPIO        digitalIO_PTB12
#define GPIOB_12_FN          1
#endif

// Pin Mapping for GPIOB_13 signal
//   <o> GPIOB_13 [PTB13]<name=GPIOB_13_PIN_SEL>
//   <i> Shows which pin GPIOB_13 is mapped to
//     <0=> Disabled
//     <1=> PTB13<selection=PTB13_SIG_SEL,GPIOB_13>
//     <0=> Default
#define GPIOB_13_PIN_SEL     0
#if GPIOB_13_PIN_SEL == 1
#define GPIOB_13_GPIO        digitalIO_PTB13
#define GPIOB_13_FN          1
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
//     <1=> PTB21 (Alias:LED_BLUE)<selection=PTB21_SIG_SEL,GPIOB_21>
//     <1=> Default
#define GPIOB_21_PIN_SEL     1
#if GPIOB_21_PIN_SEL == 1
#define GPIOB_21_GPIO        digitalIO_PTB21
#define GPIOB_21_FN          1
#endif

// Pin Mapping for GPIOB_22 signal
//   <o> GPIOB_22 [PTB22]<name=GPIOB_22_PIN_SEL>
//   <i> Shows which pin GPIOB_22 is mapped to
//     <0=> Disabled
//     <1=> PTB22 (Alias:LED_RED)<selection=PTB22_SIG_SEL,GPIOB_22>
//     <1=> Default
#define GPIOB_22_PIN_SEL     1
#if GPIOB_22_PIN_SEL == 1
#define GPIOB_22_GPIO        digitalIO_PTB22
#define GPIOB_22_FN          1
#endif

// Pin Mapping for GPIOB_23 signal
//   <o> GPIOB_23 [PTB23]<name=GPIOB_23_PIN_SEL>
//   <i> Shows which pin GPIOB_23 is mapped to
//     <0=> Disabled
//     <1=> PTB23 (Alias:D4)<selection=PTB23_SIG_SEL,GPIOB_23>
//     <1=> Default
#define GPIOB_23_PIN_SEL     1
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
//     <1=> PTC1<selection=PTC1_SIG_SEL,GPIOC_1/LLWU_P6>
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
//     <1=> PTC2 (Alias:D6)<selection=PTC2_SIG_SEL,GPIOC_2>
//     <1=> Default
#define GPIOC_2_PIN_SEL      1
#if GPIOC_2_PIN_SEL == 1
#define GPIOC_2_GPIO         digitalIO_PTC2
#define GPIOC_2_FN           1
#endif

// Pin Mapping for GPIOC_3 signal
//   <o> GPIOC_3 [PTC3]<name=GPIOC_3_PIN_SEL>
//   <i> Shows which pin GPIOC_3 is mapped to
//     <0=> Disabled
//     <1=> PTC3 (Alias:D7)<selection=PTC3_SIG_SEL,GPIOC_3/LLWU_P7>
//     <1=> Default
#define GPIOC_3_PIN_SEL      1
#if GPIOC_3_PIN_SEL == 1
#define GPIOC_3_GPIO         digitalIO_PTC3
#define GPIOC_3_FN           1
#endif

// Pin Mapping for GPIOC_4 signal
//   <o> GPIOC_4 [PTC4]<name=GPIOC_4_PIN_SEL>
//   <i> Shows which pin GPIOC_4 is mapped to
//     <0=> Disabled
//     <1=> PTC4 (Alias:D9)<selection=PTC4_SIG_SEL,GPIOC_4/LLWU_P8>
//     <1=> Default
#define GPIOC_4_PIN_SEL      1
#if GPIOC_4_PIN_SEL == 1
#define GPIOC_4_GPIO         digitalIO_PTC4
#define GPIOC_4_FN           1
#endif

// Pin Mapping for GPIOC_5 signal
//   <o> GPIOC_5 [PTC5]<name=GPIOC_5_PIN_SEL>
//   <i> Shows which pin GPIOC_5 is mapped to
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,GPIOC_5/LLWU_P9>
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
//     <1=> PTC8<selection=PTC8_SIG_SEL,GPIOC_8>
//     <0=> Default
#define GPIOC_8_PIN_SEL      0
#if GPIOC_8_PIN_SEL == 1
#define GPIOC_8_GPIO         digitalIO_PTC8
#define GPIOC_8_FN           1
#endif

// Pin Mapping for GPIOC_9 signal
//   <o> GPIOC_9 [PTC9]<name=GPIOC_9_PIN_SEL>
//   <i> Shows which pin GPIOC_9 is mapped to
//     <0=> Disabled
//     <1=> PTC9<selection=PTC9_SIG_SEL,GPIOC_9>
//     <0=> Default
#define GPIOC_9_PIN_SEL      0
#if GPIOC_9_PIN_SEL == 1
#define GPIOC_9_GPIO         digitalIO_PTC9
#define GPIOC_9_FN           1
#endif

// Pin Mapping for GPIOC_10 signal
//   <o> GPIOC_10 [PTC10]<name=GPIOC_10_PIN_SEL>
//   <i> Shows which pin GPIOC_10 is mapped to
//     <0=> Disabled
//     <1=> PTC10 (Alias:A5)<selection=PTC10_SIG_SEL,GPIOC_10>
//     <1=> Default
#define GPIOC_10_PIN_SEL     1
#if GPIOC_10_PIN_SEL == 1
#define GPIOC_10_GPIO        digitalIO_PTC10
#define GPIOC_10_FN          1
#endif

// Pin Mapping for GPIOC_11 signal
//   <o> GPIOC_11 [PTC11]<name=GPIOC_11_PIN_SEL>
//   <i> Shows which pin GPIOC_11 is mapped to
//     <0=> Disabled
//     <1=> PTC11 (Alias:A4)<selection=PTC11_SIG_SEL,GPIOC_11/LLWU_P11>
//     <1=> Default
#define GPIOC_11_PIN_SEL     1
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

// Pin Mapping for GPIOC_14 signal
//   <o> GPIOC_14 [PTC14]<name=GPIOC_14_PIN_SEL>
//   <i> Shows which pin GPIOC_14 is mapped to
//     <0=> Disabled
//     <1=> PTC14<selection=PTC14_SIG_SEL,GPIOC_14>
//     <0=> Default
#define GPIOC_14_PIN_SEL     0
#if GPIOC_14_PIN_SEL == 1
#define GPIOC_14_GPIO        digitalIO_PTC14
#define GPIOC_14_FN          1
#endif

// Pin Mapping for GPIOC_15 signal
//   <o> GPIOC_15 [PTC15]<name=GPIOC_15_PIN_SEL>
//   <i> Shows which pin GPIOC_15 is mapped to
//     <0=> Disabled
//     <1=> PTC15<selection=PTC15_SIG_SEL,GPIOC_15>
//     <0=> Default
#define GPIOC_15_PIN_SEL     0
#if GPIOC_15_PIN_SEL == 1
#define GPIOC_15_GPIO        digitalIO_PTC15
#define GPIOC_15_FN          1
#endif

// Pin Mapping for GPIOC_16 signal
//   <o> GPIOC_16 [PTC16]<name=GPIOC_16_PIN_SEL>
//   <i> Shows which pin GPIOC_16 is mapped to
//     <0=> Disabled
//     <1=> PTC16 (Alias:D0)<selection=PTC16_SIG_SEL,GPIOC_16>
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
//     <1=> PTC17 (Alias:D1)<selection=PTC17_SIG_SEL,GPIOC_17>
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

// Pin Mapping for GPIOC_19 signal
//   <o> GPIOC_19 [PTC19]<name=GPIOC_19_PIN_SEL>
//   <i> Shows which pin GPIOC_19 is mapped to
//     <0=> Disabled
//     <1=> PTC19<selection=PTC19_SIG_SEL,GPIOC_19>
//     <0=> Default
#define GPIOC_19_PIN_SEL     0
#if GPIOC_19_PIN_SEL == 1
#define GPIOC_19_GPIO        digitalIO_PTC19
#define GPIOC_19_FN          1
#endif

// </h>

// <h> General Purpose I/O (GPIOD)

// Pin Mapping for GPIOD_0 signal
//   <o> GPIOD_0 [PTD0]<name=GPIOD_0_PIN_SEL>
//   <i> Shows which pin GPIOD_0 is mapped to
//     <0=> Disabled
//     <1=> PTD0 (Alias:D10)<selection=PTD0_SIG_SEL,GPIOD_0/LLWU_P12>
//     <1=> Default
#define GPIOD_0_PIN_SEL      1
#if GPIOD_0_PIN_SEL == 1
#define GPIOD_0_GPIO         digitalIO_PTD0
#define GPIOD_0_FN           1
#endif

// Pin Mapping for GPIOD_1 signal
//   <o> GPIOD_1 [PTD1]<name=GPIOD_1_PIN_SEL>
//   <i> Shows which pin GPIOD_1 is mapped to
//     <0=> Disabled
//     <1=> PTD1 (Alias:D13)<selection=PTD1_SIG_SEL,GPIOD_1>
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
//     <1=> PTD2 (Alias:D11)<selection=PTD2_SIG_SEL,GPIOD_2/LLWU_P13>
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
//     <1=> PTD3 (Alias:D12)<selection=PTD3_SIG_SEL,GPIOD_3>
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
//     <1=> PTD4 (Alias:nRF24L01_cs)<selection=PTD4_SIG_SEL,GPIOD_4/LLWU_P14>
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
//     <1=> PTD5 (Alias:nRF24L01_sck)<selection=PTD5_SIG_SEL,GPIOD_5>
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
//     <1=> PTD6 (Alias:nRF24L01_mosi)<selection=PTD6_SIG_SEL,GPIOD_6/LLWU_P15>
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
//     <1=> PTD7 (Alias:nRF24L01_miso)<selection=PTD7_SIG_SEL,GPIOD_7>
//     <0=> Default
#define GPIOD_7_PIN_SEL      0
#if GPIOD_7_PIN_SEL == 1
#define GPIOD_7_GPIO         digitalIO_PTD7
#define GPIOD_7_FN           1
#endif

// Pin Mapping for GPIOD_8 signal
//   <o> GPIOD_8 [PTD8]<name=GPIOD_8_PIN_SEL>
//   <i> Shows which pin GPIOD_8 is mapped to
//     <0=> Disabled
//     <1=> PTD8<selection=PTD8_SIG_SEL,GPIOD_8>
//     <0=> Default
#define GPIOD_8_PIN_SEL      0
#if GPIOD_8_PIN_SEL == 1
#define GPIOD_8_GPIO         digitalIO_PTD8
#define GPIOD_8_FN           1
#endif

// Pin Mapping for GPIOD_9 signal
//   <o> GPIOD_9 [PTD9]<name=GPIOD_9_PIN_SEL>
//   <i> Shows which pin GPIOD_9 is mapped to
//     <0=> Disabled
//     <1=> PTD9<selection=PTD9_SIG_SEL,GPIOD_9>
//     <0=> Default
#define GPIOD_9_PIN_SEL      0
#if GPIOD_9_PIN_SEL == 1
#define GPIOD_9_GPIO         digitalIO_PTD9
#define GPIOD_9_FN           1
#endif

// Pin Mapping for GPIOD_10 signal
//   <o> GPIOD_10 [PTD10]<name=GPIOD_10_PIN_SEL>
//   <i> Shows which pin GPIOD_10 is mapped to
//     <0=> Disabled
//     <1=> PTD10<selection=PTD10_SIG_SEL,GPIOD_10>
//     <0=> Default
#define GPIOD_10_PIN_SEL     0
#if GPIOD_10_PIN_SEL == 1
#define GPIOD_10_GPIO        digitalIO_PTD10
#define GPIOD_10_FN          1
#endif

// Pin Mapping for GPIOD_11 signal
//   <o> GPIOD_11 [PTD11]<name=GPIOD_11_PIN_SEL>
//   <i> Shows which pin GPIOD_11 is mapped to
//     <0=> Disabled
//     <1=> PTD11<selection=PTD11_SIG_SEL,GPIOD_11>
//     <0=> Default
#define GPIOD_11_PIN_SEL     0
#if GPIOD_11_PIN_SEL == 1
#define GPIOD_11_GPIO        digitalIO_PTD11
#define GPIOD_11_FN          1
#endif

// Pin Mapping for GPIOD_12 signal
//   <o> GPIOD_12 [PTD12]<name=GPIOD_12_PIN_SEL>
//   <i> Shows which pin GPIOD_12 is mapped to
//     <0=> Disabled
//     <1=> PTD12<selection=PTD12_SIG_SEL,GPIOD_12>
//     <0=> Default
#define GPIOD_12_PIN_SEL     0
#if GPIOD_12_PIN_SEL == 1
#define GPIOD_12_GPIO        digitalIO_PTD12
#define GPIOD_12_FN          1
#endif

// Pin Mapping for GPIOD_13 signal
//   <o> GPIOD_13 [PTD13]<name=GPIOD_13_PIN_SEL>
//   <i> Shows which pin GPIOD_13 is mapped to
//     <0=> Disabled
//     <1=> PTD13<selection=PTD13_SIG_SEL,GPIOD_13>
//     <0=> Default
#define GPIOD_13_PIN_SEL     0
#if GPIOD_13_PIN_SEL == 1
#define GPIOD_13_GPIO        digitalIO_PTD13
#define GPIOD_13_FN          1
#endif

// Pin Mapping for GPIOD_14 signal
//   <o> GPIOD_14 [PTD14]<name=GPIOD_14_PIN_SEL>
//   <i> Shows which pin GPIOD_14 is mapped to
//     <0=> Disabled
//     <1=> PTD14<selection=PTD14_SIG_SEL,GPIOD_14>
//     <0=> Default
#define GPIOD_14_PIN_SEL     0
#if GPIOD_14_PIN_SEL == 1
#define GPIOD_14_GPIO        digitalIO_PTD14
#define GPIOD_14_FN          1
#endif

// Pin Mapping for GPIOD_15 signal
//   <o> GPIOD_15 [PTD15]<name=GPIOD_15_PIN_SEL>
//   <i> Shows which pin GPIOD_15 is mapped to
//     <0=> Disabled
//     <1=> PTD15<selection=PTD15_SIG_SEL,GPIOD_15>
//     <0=> Default
#define GPIOD_15_PIN_SEL     0
#if GPIOD_15_PIN_SEL == 1
#define GPIOD_15_GPIO        digitalIO_PTD15
#define GPIOD_15_FN          1
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
//     <1=> PTE1<selection=PTE1_SIG_SEL,GPIOE_1/LLWU_P0>
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
//     <1=> PTE2<selection=PTE2_SIG_SEL,GPIOE_2/LLWU_P1>
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
//     <1=> PTE4<selection=PTE4_SIG_SEL,GPIOE_4/LLWU_P2>
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

// Pin Mapping for GPIOE_8 signal
//   <o> GPIOE_8 [PTE8]<name=GPIOE_8_PIN_SEL>
//   <i> Shows which pin GPIOE_8 is mapped to
//     <0=> Disabled
//     <1=> PTE8<selection=PTE8_SIG_SEL,GPIOE_8>
//     <0=> Default
#define GPIOE_8_PIN_SEL      0
#if GPIOE_8_PIN_SEL == 1
#define GPIOE_8_GPIO         digitalIO_PTE8
#define GPIOE_8_FN           1
#endif

// Pin Mapping for GPIOE_9 signal
//   <o> GPIOE_9 [PTE9]<name=GPIOE_9_PIN_SEL>
//   <i> Shows which pin GPIOE_9 is mapped to
//     <0=> Disabled
//     <1=> PTE9<selection=PTE9_SIG_SEL,GPIOE_9>
//     <0=> Default
#define GPIOE_9_PIN_SEL      0
#if GPIOE_9_PIN_SEL == 1
#define GPIOE_9_GPIO         digitalIO_PTE9
#define GPIOE_9_FN           1
#endif

// Pin Mapping for GPIOE_10 signal
//   <o> GPIOE_10 [PTE10]<name=GPIOE_10_PIN_SEL>
//   <i> Shows which pin GPIOE_10 is mapped to
//     <0=> Disabled
//     <1=> PTE10<selection=PTE10_SIG_SEL,GPIOE_10>
//     <0=> Default
#define GPIOE_10_PIN_SEL     0
#if GPIOE_10_PIN_SEL == 1
#define GPIOE_10_GPIO        digitalIO_PTE10
#define GPIOE_10_FN          1
#endif

// Pin Mapping for GPIOE_11 signal
//   <o> GPIOE_11 [PTE11]<name=GPIOE_11_PIN_SEL>
//   <i> Shows which pin GPIOE_11 is mapped to
//     <0=> Disabled
//     <1=> PTE11<selection=PTE11_SIG_SEL,GPIOE_11>
//     <0=> Default
#define GPIOE_11_PIN_SEL     0
#if GPIOE_11_PIN_SEL == 1
#define GPIOE_11_GPIO        digitalIO_PTE11
#define GPIOE_11_FN          1
#endif

// Pin Mapping for GPIOE_12 signal
//   <o> GPIOE_12 [PTE12]<name=GPIOE_12_PIN_SEL>
//   <i> Shows which pin GPIOE_12 is mapped to
//     <0=> Disabled
//     <1=> PTE12<selection=PTE12_SIG_SEL,GPIOE_12>
//     <0=> Default
#define GPIOE_12_PIN_SEL     0
#if GPIOE_12_PIN_SEL == 1
#define GPIOE_12_GPIO        digitalIO_PTE12
#define GPIOE_12_FN          1
#endif

// Pin Mapping for GPIOE_24 signal
//   <o> GPIOE_24 [PTE24]<name=GPIOE_24_PIN_SEL>
//   <i> Shows which pin GPIOE_24 is mapped to
//     <0=> Disabled
//     <1=> PTE24 (Alias:D15)<selection=PTE24_SIG_SEL,GPIOE_24>
//     <1=> Default
#define GPIOE_24_PIN_SEL     1
#if GPIOE_24_PIN_SEL == 1
#define GPIOE_24_GPIO        digitalIO_PTE24
#define GPIOE_24_FN          1
#endif

// Pin Mapping for GPIOE_25 signal
//   <o> GPIOE_25 [PTE25]<name=GPIOE_25_PIN_SEL>
//   <i> Shows which pin GPIOE_25 is mapped to
//     <0=> Disabled
//     <1=> PTE25 (Alias:D14)<selection=PTE25_SIG_SEL,GPIOE_25>
//     <1=> Default
#define GPIOE_25_PIN_SEL     1
#if GPIOE_25_PIN_SEL == 1
#define GPIOE_25_GPIO        digitalIO_PTE25
#define GPIOE_25_FN          1
#endif

// Pin Mapping for GPIOE_26 signal
//   <o> GPIOE_26 [PTE26]<name=GPIOE_26_PIN_SEL>
//   <i> Shows which pin GPIOE_26 is mapped to
//     <0=> Disabled
//     <1=> PTE26 (Alias:LED_GREEN)<selection=PTE26_SIG_SEL,GPIOE_26>
//     <1=> Default
#define GPIOE_26_PIN_SEL     1
#if GPIOE_26_PIN_SEL == 1
#define GPIOE_26_GPIO        digitalIO_PTE26
#define GPIOE_26_FN          1
#endif

// Pin Mapping for GPIOE_27 signal
//   <o> GPIOE_27 [PTE27]<name=GPIOE_27_PIN_SEL>
//   <i> Shows which pin GPIOE_27 is mapped to
//     <0=> Disabled
//     <1=> PTE27<selection=PTE27_SIG_SEL,GPIOE_27>
//     <0=> Default
#define GPIOE_27_PIN_SEL     0
#if GPIOE_27_PIN_SEL == 1
#define GPIOE_27_GPIO        digitalIO_PTE27
#define GPIOE_27_FN          1
#endif

// Pin Mapping for GPIOE_28 signal
//   <o> GPIOE_28 [PTE28]<name=GPIOE_28_PIN_SEL>
//   <i> Shows which pin GPIOE_28 is mapped to
//     <0=> Disabled
//     <1=> PTE28<selection=PTE28_SIG_SEL,GPIOE_28>
//     <0=> Default
#define GPIOE_28_PIN_SEL     0
#if GPIOE_28_PIN_SEL == 1
#define GPIOE_28_GPIO        digitalIO_PTE28
#define GPIOE_28_FN          1
#endif

// </h>

// <h> Inter-Integrated Circuit (I2C0)

// Pin Mapping for I2C0_SCL signal
//   <o> I2C0_SCL [PTB0, PTB2, PTD8, PTE24, PTD2]<name=I2C0_SCL_PIN_SEL>
//   <i> Shows which pin I2C0_SCL is mapped to
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,I2C0_SCL>
//     <2=> PTB2 (Alias:A0)<selection=PTB2_SIG_SEL,I2C0_SCL>
//     <3=> PTD8<selection=PTD8_SIG_SEL,I2C0_SCL>
//     <4=> PTE24 (Alias:D15)<selection=PTE24_SIG_SEL,I2C0_SCL>
//     <5=> PTD2 (Alias:D11)<selection=PTD2_SIG_SEL,I2C0_SCL>
//     <0=> Default
#define I2C0_SCL_PIN_SEL     0
#if I2C0_SCL_PIN_SEL == 1
#define I2C0_SCL_GPIO        digitalIO_PTB0
#define I2C0_SCL_FN          2
#elif I2C0_SCL_PIN_SEL == 2
#define I2C0_SCL_GPIO        digitalIO_PTB2
#define I2C0_SCL_FN          2
#elif I2C0_SCL_PIN_SEL == 3
#define I2C0_SCL_GPIO        digitalIO_PTD8
#define I2C0_SCL_FN          2
#elif I2C0_SCL_PIN_SEL == 4
#define I2C0_SCL_GPIO        digitalIO_PTE24
#define I2C0_SCL_FN          5
#elif I2C0_SCL_PIN_SEL == 5
#define I2C0_SCL_GPIO        digitalIO_PTD2
#define I2C0_SCL_FN          7
#endif

// Pin Mapping for I2C0_SDA signal
//   <o> I2C0_SDA [PTB1, PTB3, PTD9, PTE25, PTD3]<name=I2C0_SDA_PIN_SEL>
//   <i> Shows which pin I2C0_SDA is mapped to
//     <0=> Disabled
//     <1=> PTB1<selection=PTB1_SIG_SEL,I2C0_SDA>
//     <2=> PTB3 (Alias:A1)<selection=PTB3_SIG_SEL,I2C0_SDA>
//     <3=> PTD9<selection=PTD9_SIG_SEL,I2C0_SDA>
//     <4=> PTE25 (Alias:D14)<selection=PTE25_SIG_SEL,I2C0_SDA>
//     <5=> PTD3 (Alias:D12)<selection=PTD3_SIG_SEL,I2C0_SDA>
//     <0=> Default
#define I2C0_SDA_PIN_SEL     0
#if I2C0_SDA_PIN_SEL == 1
#define I2C0_SDA_GPIO        digitalIO_PTB1
#define I2C0_SDA_FN          2
#elif I2C0_SDA_PIN_SEL == 2
#define I2C0_SDA_GPIO        digitalIO_PTB3
#define I2C0_SDA_FN          2
#elif I2C0_SDA_PIN_SEL == 3
#define I2C0_SDA_GPIO        digitalIO_PTD9
#define I2C0_SDA_FN          2
#elif I2C0_SDA_PIN_SEL == 4
#define I2C0_SDA_GPIO        digitalIO_PTE25
#define I2C0_SDA_FN          5
#elif I2C0_SDA_PIN_SEL == 5
#define I2C0_SDA_GPIO        digitalIO_PTD3
#define I2C0_SDA_FN          7
#endif

// </h>

// <h> Inter-Integrated Circuit (I2C1)

// Pin Mapping for I2C1_SDA signal
//   <o> I2C1_SDA [PTC11, PTE0]<name=I2C1_SDA_PIN_SEL>
//   <i> Shows which pin I2C1_SDA is mapped to
//     <0=> Disabled
//     <1=> PTC11 (Alias:A4)<selection=PTC11_SIG_SEL,I2C1_SDA>
//     <2=> PTE0<selection=PTE0_SIG_SEL,I2C1_SDA>
//     <0=> Default
#define I2C1_SDA_PIN_SEL     0
#if I2C1_SDA_PIN_SEL == 1
#define I2C1_SDA_GPIO        digitalIO_PTC11
#define I2C1_SDA_FN          2
#elif I2C1_SDA_PIN_SEL == 2
#define I2C1_SDA_GPIO        digitalIO_PTE0
#define I2C1_SDA_FN          6
#endif

// Pin Mapping for I2C1_SCL signal
//   <o> I2C1_SCL [PTC10, PTE1]<name=I2C1_SCL_PIN_SEL>
//   <i> Shows which pin I2C1_SCL is mapped to
//     <0=> Disabled
//     <1=> PTC10 (Alias:A5)<selection=PTC10_SIG_SEL,I2C1_SCL>
//     <2=> PTE1<selection=PTE1_SIG_SEL,I2C1_SCL>
//     <0=> Default
#define I2C1_SCL_PIN_SEL     0
#if I2C1_SCL_PIN_SEL == 1
#define I2C1_SCL_GPIO        digitalIO_PTC10
#define I2C1_SCL_FN          2
#elif I2C1_SCL_PIN_SEL == 2
#define I2C1_SCL_GPIO        digitalIO_PTE1
#define I2C1_SCL_FN          6
#endif

// </h>

// <h> Inter-Integrated Circuit (I2C2)

// Pin Mapping for I2C2_SDA signal
//   <o> I2C2_SDA [PTA11, PTA13]<name=I2C2_SDA_PIN_SEL>
//   <i> Shows which pin I2C2_SDA is mapped to
//     <0=> Disabled
//     <1=> PTA11<selection=PTA11_SIG_SEL,I2C2_SDA>
//     <2=> PTA13<selection=PTA13_SIG_SEL,I2C2_SDA>
//     <0=> Default
#define I2C2_SDA_PIN_SEL     0
#if I2C2_SDA_PIN_SEL == 1
#define I2C2_SDA_GPIO        digitalIO_PTA11
#define I2C2_SDA_FN          5
#elif I2C2_SDA_PIN_SEL == 2
#define I2C2_SDA_GPIO        digitalIO_PTA13
#define I2C2_SDA_FN          5
#endif

// Pin Mapping for I2C2_SCL signal
//   <o> I2C2_SCL [PTA12, PTA14]<name=I2C2_SCL_PIN_SEL>
//   <i> Shows which pin I2C2_SCL is mapped to
//     <0=> Disabled
//     <1=> PTA12<selection=PTA12_SIG_SEL,I2C2_SCL>
//     <2=> PTA14<selection=PTA14_SIG_SEL,I2C2_SCL>
//     <0=> Default
#define I2C2_SCL_PIN_SEL     0
#if I2C2_SCL_PIN_SEL == 1
#define I2C2_SCL_GPIO        digitalIO_PTA12
#define I2C2_SCL_FN          5
#elif I2C2_SCL_PIN_SEL == 2
#define I2C2_SCL_GPIO        digitalIO_PTA14
#define I2C2_SCL_FN          5
#endif

// </h>

// <h> Integrated Interchip Sound (I2S0)

// Pin Mapping for I2S0_RX_BCLK signal
//   <o> I2S0_RX_BCLK [PTC6, PTC9, PTE9, PTA14]<name=I2S0_RX_BCLK_PIN_SEL>
//   <i> Shows which pin I2S0_RX_BCLK is mapped to
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,I2S0_RX_BCLK>
//     <2=> PTC9<selection=PTC9_SIG_SEL,I2S0_RX_BCLK>
//     <3=> PTE9<selection=PTE9_SIG_SEL,I2S0_RX_BCLK>
//     <4=> PTA14<selection=PTA14_SIG_SEL,I2S0_RX_BCLK>
//     <0=> Default
#define I2S0_RX_BCLK_PIN_SEL 0
#if I2S0_RX_BCLK_PIN_SEL == 1
#define I2S0_RX_BCLK_GPIO    digitalIO_PTC6
#define I2S0_RX_BCLK_FN      4
#elif I2S0_RX_BCLK_PIN_SEL == 2
#define I2S0_RX_BCLK_GPIO    digitalIO_PTC9
#define I2S0_RX_BCLK_FN      4
#elif I2S0_RX_BCLK_PIN_SEL == 3
#define I2S0_RX_BCLK_GPIO    digitalIO_PTE9
#define I2S0_RX_BCLK_FN      4
#elif I2S0_RX_BCLK_PIN_SEL == 4
#define I2S0_RX_BCLK_GPIO    digitalIO_PTA14
#define I2S0_RX_BCLK_FN      6
#endif

// Pin Mapping for I2S0_TX_FS signal
//   <o> I2S0_TX_FS [PTB19, PTE11, PTA13, PTC2]<name=I2S0_TX_FS_PIN_SEL>
//   <i> Shows which pin I2S0_TX_FS is mapped to
//     <0=> Disabled
//     <1=> PTB19<selection=PTB19_SIG_SEL,I2S0_TX_FS>
//     <2=> PTE11<selection=PTE11_SIG_SEL,I2S0_TX_FS>
//     <3=> PTA13<selection=PTA13_SIG_SEL,I2S0_TX_FS>
//     <4=> PTC2 (Alias:D6)<selection=PTC2_SIG_SEL,I2S0_TX_FS>
//     <0=> Default
#define I2S0_TX_FS_PIN_SEL   0
#if I2S0_TX_FS_PIN_SEL == 1
#define I2S0_TX_FS_GPIO      digitalIO_PTB19
#define I2S0_TX_FS_FN        4
#elif I2S0_TX_FS_PIN_SEL == 2
#define I2S0_TX_FS_GPIO      digitalIO_PTE11
#define I2S0_TX_FS_FN        4
#elif I2S0_TX_FS_PIN_SEL == 3
#define I2S0_TX_FS_GPIO      digitalIO_PTA13
#define I2S0_TX_FS_FN        6
#elif I2S0_TX_FS_PIN_SEL == 4
#define I2S0_TX_FS_GPIO      digitalIO_PTC2
#define I2S0_TX_FS_FN        6
#endif

// Pin Mapping for I2S0_MCLK signal
//   <o> I2S0_MCLK [PTC8, PTE6, PTA17, PTC6]<name=I2S0_MCLK_PIN_SEL>
//   <i> Shows which pin I2S0_MCLK is mapped to
//     <0=> Disabled
//     <1=> PTC8<selection=PTC8_SIG_SEL,I2S0_MCLK>
//     <2=> PTE6<selection=PTE6_SIG_SEL,I2S0_MCLK>
//     <3=> PTA17<selection=PTA17_SIG_SEL,I2S0_MCLK>
//     <4=> PTC6<selection=PTC6_SIG_SEL,I2S0_MCLK>
//     <0=> Default
#define I2S0_MCLK_PIN_SEL    0
#if I2S0_MCLK_PIN_SEL == 1
#define I2S0_MCLK_GPIO       digitalIO_PTC8
#define I2S0_MCLK_FN         4
#elif I2S0_MCLK_PIN_SEL == 2
#define I2S0_MCLK_GPIO       digitalIO_PTE6
#define I2S0_MCLK_FN         4
#elif I2S0_MCLK_PIN_SEL == 3
#define I2S0_MCLK_GPIO       digitalIO_PTA17
#define I2S0_MCLK_FN         6
#elif I2S0_MCLK_PIN_SEL == 4
#define I2S0_MCLK_GPIO       digitalIO_PTC6
#define I2S0_MCLK_FN         6
#endif

// Pin Mapping for I2S0_RX_FS signal
//   <o> I2S0_RX_FS [PTC7, PTC10, PTE8, PTA16]<name=I2S0_RX_FS_PIN_SEL>
//   <i> Shows which pin I2S0_RX_FS is mapped to
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,I2S0_RX_FS>
//     <2=> PTC10 (Alias:A5)<selection=PTC10_SIG_SEL,I2S0_RX_FS>
//     <3=> PTE8<selection=PTE8_SIG_SEL,I2S0_RX_FS>
//     <4=> PTA16<selection=PTA16_SIG_SEL,I2S0_RX_FS>
//     <0=> Default
#define I2S0_RX_FS_PIN_SEL   0
#if I2S0_RX_FS_PIN_SEL == 1
#define I2S0_RX_FS_GPIO      digitalIO_PTC7
#define I2S0_RX_FS_FN        4
#elif I2S0_RX_FS_PIN_SEL == 2
#define I2S0_RX_FS_GPIO      digitalIO_PTC10
#define I2S0_RX_FS_FN        4
#elif I2S0_RX_FS_PIN_SEL == 3
#define I2S0_RX_FS_GPIO      digitalIO_PTE8
#define I2S0_RX_FS_FN        4
#elif I2S0_RX_FS_PIN_SEL == 4
#define I2S0_RX_FS_GPIO      digitalIO_PTA16
#define I2S0_RX_FS_FN        6
#endif

// Pin Mapping for I2S0_TX_BCLK signal
//   <o> I2S0_TX_BCLK [PTB18, PTE12, PTA5, PTC3]<name=I2S0_TX_BCLK_PIN_SEL>
//   <i> Shows which pin I2S0_TX_BCLK is mapped to
//     <0=> Disabled
//     <1=> PTB18<selection=PTB18_SIG_SEL,I2S0_TX_BCLK>
//     <2=> PTE12<selection=PTE12_SIG_SEL,I2S0_TX_BCLK>
//     <3=> PTA5<selection=PTA5_SIG_SEL,I2S0_TX_BCLK>
//     <4=> PTC3 (Alias:D7)<selection=PTC3_SIG_SEL,I2S0_TX_BCLK>
//     <0=> Default
#define I2S0_TX_BCLK_PIN_SEL 0
#if I2S0_TX_BCLK_PIN_SEL == 1
#define I2S0_TX_BCLK_GPIO    digitalIO_PTB18
#define I2S0_TX_BCLK_FN      4
#elif I2S0_TX_BCLK_PIN_SEL == 2
#define I2S0_TX_BCLK_GPIO    digitalIO_PTE12
#define I2S0_TX_BCLK_FN      4
#elif I2S0_TX_BCLK_PIN_SEL == 3
#define I2S0_TX_BCLK_GPIO    digitalIO_PTA5
#define I2S0_TX_BCLK_FN      6
#elif I2S0_TX_BCLK_PIN_SEL == 4
#define I2S0_TX_BCLK_GPIO    digitalIO_PTC3
#define I2S0_TX_BCLK_FN      6
#endif

// Pin Mapping for I2S0_TXD1 signal
//   <o> I2S0_TXD1 [PTE9, PTC0, PTA14]<name=I2S0_TXD1_PIN_SEL>
//   <i> Shows which pin I2S0_TXD1 is mapped to
//     <0=> Disabled
//     <1=> PTE9<selection=PTE9_SIG_SEL,I2S0_TXD1>
//     <2=> PTC0<selection=PTC0_SIG_SEL,I2S0_TXD1>
//     <3=> PTA14<selection=PTA14_SIG_SEL,I2S0_TXD1>
//     <0=> Default
#define I2S0_TXD1_PIN_SEL    0
#if I2S0_TXD1_PIN_SEL == 1
#define I2S0_TXD1_GPIO       digitalIO_PTE9
#define I2S0_TXD1_FN         2
#elif I2S0_TXD1_PIN_SEL == 2
#define I2S0_TXD1_GPIO       digitalIO_PTC0
#define I2S0_TXD1_FN         6
#elif I2S0_TXD1_PIN_SEL == 3
#define I2S0_TXD1_GPIO       digitalIO_PTA14
#define I2S0_TXD1_FN         7
#endif

// Pin Mapping for I2S0_TXD0 signal
//   <o> I2S0_TXD0 [PTE10, PTA12, PTC1]<name=I2S0_TXD0_PIN_SEL>
//   <i> Shows which pin I2S0_TXD0 is mapped to
//     <0=> Disabled
//     <1=> PTE10<selection=PTE10_SIG_SEL,I2S0_TXD0>
//     <2=> PTA12<selection=PTA12_SIG_SEL,I2S0_TXD0>
//     <3=> PTC1<selection=PTC1_SIG_SEL,I2S0_TXD0>
//     <0=> Default
#define I2S0_TXD0_PIN_SEL    0
#if I2S0_TXD0_PIN_SEL == 1
#define I2S0_TXD0_GPIO       digitalIO_PTE10
#define I2S0_TXD0_FN         4
#elif I2S0_TXD0_PIN_SEL == 2
#define I2S0_TXD0_GPIO       digitalIO_PTA12
#define I2S0_TXD0_FN         6
#elif I2S0_TXD0_PIN_SEL == 3
#define I2S0_TXD0_GPIO       digitalIO_PTC1
#define I2S0_TXD0_FN         6
#endif

// Pin Mapping for I2S0_RXD1 signal
//   <o> I2S0_RXD1 [PTE8, PTC11, PTA16]<name=I2S0_RXD1_PIN_SEL>
//   <i> Shows which pin I2S0_RXD1 is mapped to
//     <0=> Disabled
//     <1=> PTE8<selection=PTE8_SIG_SEL,I2S0_RXD1>
//     <2=> PTC11 (Alias:A4)<selection=PTC11_SIG_SEL,I2S0_RXD1>
//     <3=> PTA16<selection=PTA16_SIG_SEL,I2S0_RXD1>
//     <0=> Default
#define I2S0_RXD1_PIN_SEL    0
#if I2S0_RXD1_PIN_SEL == 1
#define I2S0_RXD1_GPIO       digitalIO_PTE8
#define I2S0_RXD1_FN         2
#elif I2S0_RXD1_PIN_SEL == 2
#define I2S0_RXD1_GPIO       digitalIO_PTC11
#define I2S0_RXD1_FN         4
#elif I2S0_RXD1_PIN_SEL == 3
#define I2S0_RXD1_GPIO       digitalIO_PTA16
#define I2S0_RXD1_FN         7
#endif

// Pin Mapping for I2S0_RXD0 signal
//   <o> I2S0_RXD0 [PTC5, PTE7, PTA15]<name=I2S0_RXD0_PIN_SEL>
//   <i> Shows which pin I2S0_RXD0 is mapped to
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,I2S0_RXD0>
//     <2=> PTE7<selection=PTE7_SIG_SEL,I2S0_RXD0>
//     <3=> PTA15<selection=PTA15_SIG_SEL,I2S0_RXD0>
//     <0=> Default
#define I2S0_RXD0_PIN_SEL    0
#if I2S0_RXD0_PIN_SEL == 1
#define I2S0_RXD0_GPIO       digitalIO_PTC5
#define I2S0_RXD0_FN         4
#elif I2S0_RXD0_PIN_SEL == 2
#define I2S0_RXD0_GPIO       digitalIO_PTE7
#define I2S0_RXD0_FN         4
#elif I2S0_RXD0_PIN_SEL == 3
#define I2S0_RXD0_GPIO       digitalIO_PTA15
#define I2S0_RXD0_FN         6
#endif

// </h>

// <h> Debug and Control

// Pin Mapping for JTAG_TCLK signal
//   <o> JTAG_TCLK [PTA0]<name=JTAG_TCLK_PIN_SEL>
//   <i> Shows which pin JTAG_TCLK is mapped to
//     <0=> Disabled
//     <1=> PTA0 (Alias:D8) (reset default)<selection=PTA0_SIG_SEL,JTAG_TCLK/SWD_CLK (reset default)>
//     <2=> PTA0 (Alias:D8)<selection=PTA0_SIG_SEL,JTAG_TCLK/SWD_CLK>
//     <1=> Default
#define JTAG_TCLK_PIN_SEL    1
#if JTAG_TCLK_PIN_SEL == 2
#define JTAG_TCLK_GPIO       digitalIO_PTA0
#define JTAG_TCLK_FN         7
#endif

// Pin Mapping for JTAG_TDI signal
//   <o> JTAG_TDI [PTA1]<name=JTAG_TDI_PIN_SEL>
//   <i> Shows which pin JTAG_TDI is mapped to
//     <0=> Disabled
//     <1=> PTA1 (Alias:D3) (reset default)<selection=PTA1_SIG_SEL,JTAG_TDI (reset default)>
//     <2=> PTA1 (Alias:D3)<selection=PTA1_SIG_SEL,JTAG_TDI>
//     <0=> Default
#define JTAG_TDI_PIN_SEL     0
#if JTAG_TDI_PIN_SEL == 2
#define JTAG_TDI_GPIO        digitalIO_PTA1
#define JTAG_TDI_FN          7
#endif

// Pin Mapping for JTAG_TDO signal
//   <o> JTAG_TDO [PTA2]<name=JTAG_TDO_PIN_SEL>
//   <i> Shows which pin JTAG_TDO is mapped to
//     <0=> Disabled
//     <1=> PTA2 (Alias:D5) (reset default)<selection=PTA2_SIG_SEL,JTAG_TDO/TRACE_SWO (reset default)>
//     <2=> PTA2 (Alias:D5)<selection=PTA2_SIG_SEL,JTAG_TDO/TRACE_SWO>
//     <0=> Default
#define JTAG_TDO_PIN_SEL     0
#if JTAG_TDO_PIN_SEL == 2
#define JTAG_TDO_GPIO        digitalIO_PTA2
#define JTAG_TDO_FN          7
#endif

// Pin Mapping for JTAG_TMS signal
//   <o> JTAG_TMS [PTA3]<name=JTAG_TMS_PIN_SEL>
//   <i> Shows which pin JTAG_TMS is mapped to
//     <0=> Disabled
//     <1=> PTA3 (reset default)<selection=PTA3_SIG_SEL,JTAG_TMS/SWD_DIO (reset default)>
//     <2=> PTA3<selection=PTA3_SIG_SEL,JTAG_TMS/SWD_DIO>
//     <1=> Default
#define JTAG_TMS_PIN_SEL     1
#if JTAG_TMS_PIN_SEL == 2
#define JTAG_TMS_GPIO        digitalIO_PTA3
#define JTAG_TMS_FN          7
#endif

// Pin Mapping for JTAG_TRST_b signal
//   <o> JTAG_TRST_b [PTA5]<name=JTAG_TRST_b_PIN_SEL>
//   <i> Shows which pin JTAG_TRST_b is mapped to
//     <0=> Disabled
//     <1=> PTA5 (reset default)<selection=PTA5_SIG_SEL,JTAG_TRST_b (reset default)>
//     <2=> PTA5<selection=PTA5_SIG_SEL,JTAG_TRST_b>
//     <1=> Default
#define JTAG_TRST_b_PIN_SEL  1
#if JTAG_TRST_b_PIN_SEL == 2
#define JTAG_TRST_b_GPIO     digitalIO_PTA5
#define JTAG_TRST_b_FN       7
#endif

// Pin Mapping for NMI_b signal
//   <o> NMI_b [PTA4]<name=NMI_b_PIN_SEL>
//   <i> Shows which pin NMI_b is mapped to
//     <0=> Disabled
//     <1=> PTA4 (reset default)<selection=PTA4_SIG_SEL,NMI_b (reset default)>
//     <2=> PTA4<selection=PTA4_SIG_SEL,NMI_b>
//     <1=> Default
#define NMI_b_PIN_SEL        1
#if NMI_b_PIN_SEL == 2
#define NMI_b_GPIO           digitalIO_PTA4
#define NMI_b_FN             7
#endif

// Pin Mapping for SWD_CLK signal
//   <o> SWD_CLK [PTA0]<name=SWD_CLK_PIN_SEL>
//   <i> Shows which pin SWD_CLK is mapped to
//     <0=> Disabled
//     <1=> PTA0 (Alias:D8) (reset default)<selection=PTA0_SIG_SEL,JTAG_TCLK/SWD_CLK (reset default)>
//     <2=> PTA0 (Alias:D8)<selection=PTA0_SIG_SEL,JTAG_TCLK/SWD_CLK>
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
//     <1=> PTA3 (reset default)<selection=PTA3_SIG_SEL,JTAG_TMS/SWD_DIO (reset default)>
//     <2=> PTA3<selection=PTA3_SIG_SEL,JTAG_TMS/SWD_DIO>
//     <1=> Default
#define SWD_DIO_PIN_SEL      1
#if SWD_DIO_PIN_SEL == 2
#define SWD_DIO_GPIO         digitalIO_PTA3
#define SWD_DIO_FN           7
#endif

// Pin Mapping for TRACE_CLKOUT signal
//   <o> TRACE_CLKOUT [PTE0, PTA6]<name=TRACE_CLKOUT_PIN_SEL>
//   <i> Shows which pin TRACE_CLKOUT is mapped to
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,TRACE_CLKOUT>
//     <2=> PTA6<selection=PTA6_SIG_SEL,TRACE_CLKOUT>
//     <0=> Default
#define TRACE_CLKOUT_PIN_SEL 0
#if TRACE_CLKOUT_PIN_SEL == 1
#define TRACE_CLKOUT_GPIO    digitalIO_PTE0
#define TRACE_CLKOUT_FN      5
#elif TRACE_CLKOUT_PIN_SEL == 2
#define TRACE_CLKOUT_GPIO    digitalIO_PTA6
#define TRACE_CLKOUT_FN      7
#endif

// Pin Mapping for TRACE_D0 signal
//   <o> TRACE_D0 [PTE4, PTA10]<name=TRACE_D0_PIN_SEL>
//   <i> Shows which pin TRACE_D0 is mapped to
//     <0=> Disabled
//     <1=> PTE4<selection=PTE4_SIG_SEL,TRACE_D0>
//     <2=> PTA10<selection=PTA10_SIG_SEL,TRACE_D0>
//     <0=> Default
#define TRACE_D0_PIN_SEL     0
#if TRACE_D0_PIN_SEL == 1
#define TRACE_D0_GPIO        digitalIO_PTE4
#define TRACE_D0_FN          5
#elif TRACE_D0_PIN_SEL == 2
#define TRACE_D0_GPIO        digitalIO_PTA10
#define TRACE_D0_FN          7
#endif

// Pin Mapping for TRACE_D1 signal
//   <o> TRACE_D1 [PTE3, PTA9]<name=TRACE_D1_PIN_SEL>
//   <i> Shows which pin TRACE_D1 is mapped to
//     <0=> Disabled
//     <1=> PTE3<selection=PTE3_SIG_SEL,TRACE_D1>
//     <2=> PTA9<selection=PTA9_SIG_SEL,TRACE_D1>
//     <0=> Default
#define TRACE_D1_PIN_SEL     0
#if TRACE_D1_PIN_SEL == 1
#define TRACE_D1_GPIO        digitalIO_PTE3
#define TRACE_D1_FN          5
#elif TRACE_D1_PIN_SEL == 2
#define TRACE_D1_GPIO        digitalIO_PTA9
#define TRACE_D1_FN          7
#endif

// Pin Mapping for TRACE_D2 signal
//   <o> TRACE_D2 [PTE2, PTA8]<name=TRACE_D2_PIN_SEL>
//   <i> Shows which pin TRACE_D2 is mapped to
//     <0=> Disabled
//     <1=> PTE2<selection=PTE2_SIG_SEL,TRACE_D2>
//     <2=> PTA8<selection=PTA8_SIG_SEL,TRACE_D2>
//     <0=> Default
#define TRACE_D2_PIN_SEL     0
#if TRACE_D2_PIN_SEL == 1
#define TRACE_D2_GPIO        digitalIO_PTE2
#define TRACE_D2_FN          5
#elif TRACE_D2_PIN_SEL == 2
#define TRACE_D2_GPIO        digitalIO_PTA8
#define TRACE_D2_FN          7
#endif

// Pin Mapping for TRACE_D3 signal
//   <o> TRACE_D3 [PTE1, PTA7]<name=TRACE_D3_PIN_SEL>
//   <i> Shows which pin TRACE_D3 is mapped to
//     <0=> Disabled
//     <1=> PTE1<selection=PTE1_SIG_SEL,TRACE_D3>
//     <2=> PTA7<selection=PTA7_SIG_SEL,TRACE_D3>
//     <0=> Default
#define TRACE_D3_PIN_SEL     0
#if TRACE_D3_PIN_SEL == 1
#define TRACE_D3_GPIO        digitalIO_PTE1
#define TRACE_D3_FN          5
#elif TRACE_D3_PIN_SEL == 2
#define TRACE_D3_GPIO        digitalIO_PTA7
#define TRACE_D3_FN          7
#endif

// Pin Mapping for TRACE_SWO signal
//   <o> TRACE_SWO [PTA2]<name=TRACE_SWO_PIN_SEL>
//   <i> Shows which pin TRACE_SWO is mapped to
//     <0=> Disabled
//     <1=> PTA2 (Alias:D5) (reset default)<selection=PTA2_SIG_SEL,JTAG_TDO/TRACE_SWO (reset default)>
//     <2=> PTA2 (Alias:D5)<selection=PTA2_SIG_SEL,JTAG_TDO/TRACE_SWO>
//     <0=> Default
#define TRACE_SWO_PIN_SEL    0
#if TRACE_SWO_PIN_SEL == 2
#define TRACE_SWO_GPIO       digitalIO_PTA2
#define TRACE_SWO_FN         7
#endif

// </h>

// <h> Low-Leakage Wake-up Unit (LLWU)

// Pin Mapping for LLWU_P0 signal
//   <o> LLWU_P0 [PTE1]<name=LLWU_P0_PIN_SEL>
//   <i> Shows which pin LLWU_P0 is mapped to
//     <0=> Disabled
//     <1=> PTE1<selection=PTE1_SIG_SEL,GPIOE_1/LLWU_P0>
//     <0=> Default
#define LLWU_P0_PIN_SEL      0
#if LLWU_P0_PIN_SEL == 1
#define LLWU_P0_GPIO         digitalIO_PTE1
#define LLWU_P0_FN           1
#endif

// Pin Mapping for LLWU_P1 signal
//   <o> LLWU_P1 [PTE2]<name=LLWU_P1_PIN_SEL>
//   <i> Shows which pin LLWU_P1 is mapped to
//     <0=> Disabled
//     <1=> PTE2<selection=PTE2_SIG_SEL,GPIOE_2/LLWU_P1>
//     <0=> Default
#define LLWU_P1_PIN_SEL      0
#if LLWU_P1_PIN_SEL == 1
#define LLWU_P1_GPIO         digitalIO_PTE2
#define LLWU_P1_FN           1
#endif

// Pin Mapping for LLWU_P2 signal
//   <o> LLWU_P2 [PTE4]<name=LLWU_P2_PIN_SEL>
//   <i> Shows which pin LLWU_P2 is mapped to
//     <0=> Disabled
//     <1=> PTE4<selection=PTE4_SIG_SEL,GPIOE_4/LLWU_P2>
//     <0=> Default
#define LLWU_P2_PIN_SEL      0
#if LLWU_P2_PIN_SEL == 1
#define LLWU_P2_GPIO         digitalIO_PTE4
#define LLWU_P2_FN           1
#endif

// Pin Mapping for LLWU_P3 signal
//   <o> LLWU_P3 [PTA4]<name=LLWU_P3_PIN_SEL>
//   <i> Shows which pin LLWU_P3 is mapped to
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,GPIOA_4/LLWU_P3>
//     <0=> Default
#define LLWU_P3_PIN_SEL      0
#if LLWU_P3_PIN_SEL == 1
#define LLWU_P3_GPIO         digitalIO_PTA4
#define LLWU_P3_FN           1
#endif

// Pin Mapping for LLWU_P4 signal
//   <o> LLWU_P4 [PTA13]<name=LLWU_P4_PIN_SEL>
//   <i> Shows which pin LLWU_P4 is mapped to
//     <0=> Disabled
//     <1=> PTA13<selection=PTA13_SIG_SEL,GPIOA_13/LLWU_P4>
//     <0=> Default
#define LLWU_P4_PIN_SEL      0
#if LLWU_P4_PIN_SEL == 1
#define LLWU_P4_GPIO         digitalIO_PTA13
#define LLWU_P4_FN           1
#endif

// Pin Mapping for LLWU_P5 signal
//   <o> LLWU_P5 [PTB0]<name=LLWU_P5_PIN_SEL>
//   <i> Shows which pin LLWU_P5 is mapped to
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,GPIOB_0/LLWU_P5>
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
//     <1=> PTC1<selection=PTC1_SIG_SEL,GPIOC_1/LLWU_P6>
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
//     <1=> PTC3 (Alias:D7)<selection=PTC3_SIG_SEL,GPIOC_3/LLWU_P7>
//     <1=> Default
#define LLWU_P7_PIN_SEL      1
#if LLWU_P7_PIN_SEL == 1
#define LLWU_P7_GPIO         digitalIO_PTC3
#define LLWU_P7_FN           1
#endif

// Pin Mapping for LLWU_P8 signal
//   <o> LLWU_P8 [PTC4]<name=LLWU_P8_PIN_SEL>
//   <i> Shows which pin LLWU_P8 is mapped to
//     <0=> Disabled
//     <1=> PTC4 (Alias:D9)<selection=PTC4_SIG_SEL,GPIOC_4/LLWU_P8>
//     <1=> Default
#define LLWU_P8_PIN_SEL      1
#if LLWU_P8_PIN_SEL == 1
#define LLWU_P8_GPIO         digitalIO_PTC4
#define LLWU_P8_FN           1
#endif

// Pin Mapping for LLWU_P9 signal
//   <o> LLWU_P9 [PTC5]<name=LLWU_P9_PIN_SEL>
//   <i> Shows which pin LLWU_P9 is mapped to
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,GPIOC_5/LLWU_P9>
//     <0=> Default
#define LLWU_P9_PIN_SEL      0
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

// Pin Mapping for LLWU_P11 signal
//   <o> LLWU_P11 [PTC11]<name=LLWU_P11_PIN_SEL>
//   <i> Shows which pin LLWU_P11 is mapped to
//     <0=> Disabled
//     <1=> PTC11 (Alias:A4)<selection=PTC11_SIG_SEL,GPIOC_11/LLWU_P11>
//     <1=> Default
#define LLWU_P11_PIN_SEL     1
#if LLWU_P11_PIN_SEL == 1
#define LLWU_P11_GPIO        digitalIO_PTC11
#define LLWU_P11_FN          1
#endif

// Pin Mapping for LLWU_P12 signal
//   <o> LLWU_P12 [PTD0]<name=LLWU_P12_PIN_SEL>
//   <i> Shows which pin LLWU_P12 is mapped to
//     <0=> Disabled
//     <1=> PTD0 (Alias:D10)<selection=PTD0_SIG_SEL,GPIOD_0/LLWU_P12>
//     <1=> Default
#define LLWU_P12_PIN_SEL     1
#if LLWU_P12_PIN_SEL == 1
#define LLWU_P12_GPIO        digitalIO_PTD0
#define LLWU_P12_FN          1
#endif

// Pin Mapping for LLWU_P13 signal
//   <o> LLWU_P13 [PTD2]<name=LLWU_P13_PIN_SEL>
//   <i> Shows which pin LLWU_P13 is mapped to
//     <0=> Disabled
//     <1=> PTD2 (Alias:D11)<selection=PTD2_SIG_SEL,GPIOD_2/LLWU_P13>
//     <1=> Default
#define LLWU_P13_PIN_SEL     1
#if LLWU_P13_PIN_SEL == 1
#define LLWU_P13_GPIO        digitalIO_PTD2
#define LLWU_P13_FN          1
#endif

// Pin Mapping for LLWU_P14 signal
//   <o> LLWU_P14 [PTD4]<name=LLWU_P14_PIN_SEL>
//   <i> Shows which pin LLWU_P14 is mapped to
//     <0=> Disabled
//     <1=> PTD4 (Alias:nRF24L01_cs)<selection=PTD4_SIG_SEL,GPIOD_4/LLWU_P14>
//     <0=> Default
#define LLWU_P14_PIN_SEL     0
#if LLWU_P14_PIN_SEL == 1
#define LLWU_P14_GPIO        digitalIO_PTD4
#define LLWU_P14_FN          1
#endif

// Pin Mapping for LLWU_P15 signal
//   <o> LLWU_P15 [PTD6]<name=LLWU_P15_PIN_SEL>
//   <i> Shows which pin LLWU_P15 is mapped to
//     <0=> Disabled
//     <1=> PTD6 (Alias:nRF24L01_mosi)<selection=PTD6_SIG_SEL,GPIOD_6/LLWU_P15>
//     <0=> Default
#define LLWU_P15_PIN_SEL     0
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
//     <1=> PTC5<selection=PTC5_SIG_SEL,LPTMR0_ALT2>
//     <0=> Default
#define LPTMR0_ALT2_PIN_SEL  0
#if LPTMR0_ALT2_PIN_SEL == 1
#define LPTMR0_ALT2_GPIO     digitalIO_PTC5
#define LPTMR0_ALT2_FN       3
#endif

// </h>

// <h> Ethernet (MII0)

// Pin Mapping for MII0_COL signal
//   <o> MII0_COL [PTA29]<name=MII0_COL_PIN_SEL>
//   <i> Shows which pin MII0_COL is mapped to
//     <0=> Disabled
//     <1=> PTA29<selection=PTA29_SIG_SEL,MII0_COL>
//     <0=> Default
#define MII0_COL_PIN_SEL     0
#if MII0_COL_PIN_SEL == 1
#define MII0_COL_GPIO        digitalIO_PTA29
#define MII0_COL_FN          4
#endif

// Pin Mapping for MII0_CRS signal
//   <o> MII0_CRS [PTA27]<name=MII0_CRS_PIN_SEL>
//   <i> Shows which pin MII0_CRS is mapped to
//     <0=> Disabled
//     <1=> PTA27<selection=PTA27_SIG_SEL,MII0_CRS>
//     <0=> Default
#define MII0_CRS_PIN_SEL     0
#if MII0_CRS_PIN_SEL == 1
#define MII0_CRS_GPIO        digitalIO_PTA27
#define MII0_CRS_FN          4
#endif

// Pin Mapping for MII0_MDC signal
//   <o> MII0_MDC [PTB1]<name=MII0_MDC_PIN_SEL>
//   <i> Shows which pin MII0_MDC is mapped to
//     <0=> Disabled
//     <1=> PTB1<selection=PTB1_SIG_SEL,RMII0_MDC/MII0_MDC>
//     <0=> Default
#define MII0_MDC_PIN_SEL     0
#if MII0_MDC_PIN_SEL == 1
#define MII0_MDC_GPIO        digitalIO_PTB1
#define MII0_MDC_FN          4
#endif

// Pin Mapping for MII0_MDIO signal
//   <o> MII0_MDIO [PTB0]<name=MII0_MDIO_PIN_SEL>
//   <i> Shows which pin MII0_MDIO is mapped to
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,RMII0_MDIO/MII0_MDIO>
//     <0=> Default
#define MII0_MDIO_PIN_SEL    0
#if MII0_MDIO_PIN_SEL == 1
#define MII0_MDIO_GPIO       digitalIO_PTB0
#define MII0_MDIO_FN         4
#endif

// Pin Mapping for MII0_RXCLK signal
//   <o> MII0_RXCLK [PTA11]<name=MII0_RXCLK_PIN_SEL>
//   <i> Shows which pin MII0_RXCLK is mapped to
//     <0=> Disabled
//     <1=> PTA11<selection=PTA11_SIG_SEL,MII0_RXCLK>
//     <0=> Default
#define MII0_RXCLK_PIN_SEL   0
#if MII0_RXCLK_PIN_SEL == 1
#define MII0_RXCLK_GPIO      digitalIO_PTA11
#define MII0_RXCLK_FN        4
#endif

// Pin Mapping for MII0_RXD0 signal
//   <o> MII0_RXD0 [PTA13]<name=MII0_RXD0_PIN_SEL>
//   <i> Shows which pin MII0_RXD0 is mapped to
//     <0=> Disabled
//     <1=> PTA13<selection=PTA13_SIG_SEL,RMII0_RXD0/MII0_RXD0>
//     <0=> Default
#define MII0_RXD0_PIN_SEL    0
#if MII0_RXD0_PIN_SEL == 1
#define MII0_RXD0_GPIO       digitalIO_PTA13
#define MII0_RXD0_FN         4
#endif

// Pin Mapping for MII0_RXD1 signal
//   <o> MII0_RXD1 [PTA12]<name=MII0_RXD1_PIN_SEL>
//   <i> Shows which pin MII0_RXD1 is mapped to
//     <0=> Disabled
//     <1=> PTA12<selection=PTA12_SIG_SEL,RMII0_RXD1/MII0_RXD1>
//     <0=> Default
#define MII0_RXD1_PIN_SEL    0
#if MII0_RXD1_PIN_SEL == 1
#define MII0_RXD1_GPIO       digitalIO_PTA12
#define MII0_RXD1_FN         4
#endif

// Pin Mapping for MII0_RXD2 signal
//   <o> MII0_RXD2 [PTA10]<name=MII0_RXD2_PIN_SEL>
//   <i> Shows which pin MII0_RXD2 is mapped to
//     <0=> Disabled
//     <1=> PTA10<selection=PTA10_SIG_SEL,MII0_RXD2>
//     <0=> Default
#define MII0_RXD2_PIN_SEL    0
#if MII0_RXD2_PIN_SEL == 1
#define MII0_RXD2_GPIO       digitalIO_PTA10
#define MII0_RXD2_FN         4
#endif

// Pin Mapping for MII0_RXD3 signal
//   <o> MII0_RXD3 [PTA9]<name=MII0_RXD3_PIN_SEL>
//   <i> Shows which pin MII0_RXD3 is mapped to
//     <0=> Disabled
//     <1=> PTA9<selection=PTA9_SIG_SEL,MII0_RXD3>
//     <0=> Default
#define MII0_RXD3_PIN_SEL    0
#if MII0_RXD3_PIN_SEL == 1
#define MII0_RXD3_GPIO       digitalIO_PTA9
#define MII0_RXD3_FN         4
#endif

// Pin Mapping for MII0_RXDV signal
//   <o> MII0_RXDV [PTA14]<name=MII0_RXDV_PIN_SEL>
//   <i> Shows which pin MII0_RXDV is mapped to
//     <0=> Disabled
//     <1=> PTA14<selection=PTA14_SIG_SEL,RMII0_CRS_DV/MII0_RXDV>
//     <0=> Default
#define MII0_RXDV_PIN_SEL    0
#if MII0_RXDV_PIN_SEL == 1
#define MII0_RXDV_GPIO       digitalIO_PTA14
#define MII0_RXDV_FN         4
#endif

// Pin Mapping for MII0_RXER signal
//   <o> MII0_RXER [PTA5]<name=MII0_RXER_PIN_SEL>
//   <i> Shows which pin MII0_RXER is mapped to
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,RMII0_RXER/MII0_RXER>
//     <0=> Default
#define MII0_RXER_PIN_SEL    0
#if MII0_RXER_PIN_SEL == 1
#define MII0_RXER_GPIO       digitalIO_PTA5
#define MII0_RXER_FN         4
#endif

// Pin Mapping for MII0_TXCLK signal
//   <o> MII0_TXCLK [PTA25]<name=MII0_TXCLK_PIN_SEL>
//   <i> Shows which pin MII0_TXCLK is mapped to
//     <0=> Disabled
//     <1=> PTA25<selection=PTA25_SIG_SEL,MII0_TXCLK>
//     <0=> Default
#define MII0_TXCLK_PIN_SEL   0
#if MII0_TXCLK_PIN_SEL == 1
#define MII0_TXCLK_GPIO      digitalIO_PTA25
#define MII0_TXCLK_FN        4
#endif

// Pin Mapping for MII0_TXD0 signal
//   <o> MII0_TXD0 [PTA16]<name=MII0_TXD0_PIN_SEL>
//   <i> Shows which pin MII0_TXD0 is mapped to
//     <0=> Disabled
//     <1=> PTA16<selection=PTA16_SIG_SEL,RMII0_TXD0/MII0_TXD0>
//     <0=> Default
#define MII0_TXD0_PIN_SEL    0
#if MII0_TXD0_PIN_SEL == 1
#define MII0_TXD0_GPIO       digitalIO_PTA16
#define MII0_TXD0_FN         4
#endif

// Pin Mapping for MII0_TXD1 signal
//   <o> MII0_TXD1 [PTA17]<name=MII0_TXD1_PIN_SEL>
//   <i> Shows which pin MII0_TXD1 is mapped to
//     <0=> Disabled
//     <1=> PTA17<selection=PTA17_SIG_SEL,RMII0_TXD1/MII0_TXD1>
//     <0=> Default
#define MII0_TXD1_PIN_SEL    0
#if MII0_TXD1_PIN_SEL == 1
#define MII0_TXD1_GPIO       digitalIO_PTA17
#define MII0_TXD1_FN         4
#endif

// Pin Mapping for MII0_TXD2 signal
//   <o> MII0_TXD2 [PTA24]<name=MII0_TXD2_PIN_SEL>
//   <i> Shows which pin MII0_TXD2 is mapped to
//     <0=> Disabled
//     <1=> PTA24<selection=PTA24_SIG_SEL,MII0_TXD2>
//     <0=> Default
#define MII0_TXD2_PIN_SEL    0
#if MII0_TXD2_PIN_SEL == 1
#define MII0_TXD2_GPIO       digitalIO_PTA24
#define MII0_TXD2_FN         4
#endif

// Pin Mapping for MII0_TXD3 signal
//   <o> MII0_TXD3 [PTA26]<name=MII0_TXD3_PIN_SEL>
//   <i> Shows which pin MII0_TXD3 is mapped to
//     <0=> Disabled
//     <1=> PTA26<selection=PTA26_SIG_SEL,MII0_TXD3>
//     <0=> Default
#define MII0_TXD3_PIN_SEL    0
#if MII0_TXD3_PIN_SEL == 1
#define MII0_TXD3_GPIO       digitalIO_PTA26
#define MII0_TXD3_FN         4
#endif

// Pin Mapping for MII0_TXEN signal
//   <o> MII0_TXEN [PTA15]<name=MII0_TXEN_PIN_SEL>
//   <i> Shows which pin MII0_TXEN is mapped to
//     <0=> Disabled
//     <1=> PTA15<selection=PTA15_SIG_SEL,RMII0_TXEN/MII0_TXEN>
//     <0=> Default
#define MII0_TXEN_PIN_SEL    0
#if MII0_TXEN_PIN_SEL == 1
#define MII0_TXEN_GPIO       digitalIO_PTA15
#define MII0_TXEN_FN         4
#endif

// Pin Mapping for MII0_TXER signal
//   <o> MII0_TXER [PTA28]<name=MII0_TXER_PIN_SEL>
//   <i> Shows which pin MII0_TXER is mapped to
//     <0=> Disabled
//     <1=> PTA28<selection=PTA28_SIG_SEL,MII0_TXER>
//     <0=> Default
#define MII0_TXER_PIN_SEL    0
#if MII0_TXER_PIN_SEL == 1
#define MII0_TXER_GPIO       digitalIO_PTA28
#define MII0_TXER_FN         4
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
#if PDB0_EXTRG_PIN_SEL == 1
#define PDB0_EXTRG_GPIO      digitalIO_PTC0
#define PDB0_EXTRG_FN        3
#elif PDB0_EXTRG_PIN_SEL == 2
#define PDB0_EXTRG_GPIO      digitalIO_PTC6
#define PDB0_EXTRG_FN        3
#endif

// </h>

// <h> Ethernet (RMII0)

// Pin Mapping for RMII0_CRS_DV signal
//   <o> RMII0_CRS_DV [PTA14]<name=RMII0_CRS_DV_PIN_SEL>
//   <i> Shows which pin RMII0_CRS_DV is mapped to
//     <0=> Disabled
//     <1=> PTA14<selection=PTA14_SIG_SEL,RMII0_CRS_DV/MII0_RXDV>
//     <0=> Default
#define RMII0_CRS_DV_PIN_SEL 0
#if RMII0_CRS_DV_PIN_SEL == 1
#define RMII0_CRS_DV_GPIO    digitalIO_PTA14
#define RMII0_CRS_DV_FN      4
#endif

// Pin Mapping for RMII0_MDC signal
//   <o> RMII0_MDC [PTB1]<name=RMII0_MDC_PIN_SEL>
//   <i> Shows which pin RMII0_MDC is mapped to
//     <0=> Disabled
//     <1=> PTB1<selection=PTB1_SIG_SEL,RMII0_MDC/MII0_MDC>
//     <0=> Default
#define RMII0_MDC_PIN_SEL    0
#if RMII0_MDC_PIN_SEL == 1
#define RMII0_MDC_GPIO       digitalIO_PTB1
#define RMII0_MDC_FN         4
#endif

// Pin Mapping for RMII0_MDIO signal
//   <o> RMII0_MDIO [PTB0]<name=RMII0_MDIO_PIN_SEL>
//   <i> Shows which pin RMII0_MDIO is mapped to
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,RMII0_MDIO/MII0_MDIO>
//     <0=> Default
#define RMII0_MDIO_PIN_SEL   0
#if RMII0_MDIO_PIN_SEL == 1
#define RMII0_MDIO_GPIO      digitalIO_PTB0
#define RMII0_MDIO_FN        4
#endif

// Pin Mapping for RMII0_RXD0 signal
//   <o> RMII0_RXD0 [PTA13]<name=RMII0_RXD0_PIN_SEL>
//   <i> Shows which pin RMII0_RXD0 is mapped to
//     <0=> Disabled
//     <1=> PTA13<selection=PTA13_SIG_SEL,RMII0_RXD0/MII0_RXD0>
//     <0=> Default
#define RMII0_RXD0_PIN_SEL   0
#if RMII0_RXD0_PIN_SEL == 1
#define RMII0_RXD0_GPIO      digitalIO_PTA13
#define RMII0_RXD0_FN        4
#endif

// Pin Mapping for RMII0_RXD1 signal
//   <o> RMII0_RXD1 [PTA12]<name=RMII0_RXD1_PIN_SEL>
//   <i> Shows which pin RMII0_RXD1 is mapped to
//     <0=> Disabled
//     <1=> PTA12<selection=PTA12_SIG_SEL,RMII0_RXD1/MII0_RXD1>
//     <0=> Default
#define RMII0_RXD1_PIN_SEL   0
#if RMII0_RXD1_PIN_SEL == 1
#define RMII0_RXD1_GPIO      digitalIO_PTA12
#define RMII0_RXD1_FN        4
#endif

// Pin Mapping for RMII0_RXER signal
//   <o> RMII0_RXER [PTA5]<name=RMII0_RXER_PIN_SEL>
//   <i> Shows which pin RMII0_RXER is mapped to
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,RMII0_RXER/MII0_RXER>
//     <0=> Default
#define RMII0_RXER_PIN_SEL   0
#if RMII0_RXER_PIN_SEL == 1
#define RMII0_RXER_GPIO      digitalIO_PTA5
#define RMII0_RXER_FN        4
#endif

// Pin Mapping for RMII0_TXD0 signal
//   <o> RMII0_TXD0 [PTA16]<name=RMII0_TXD0_PIN_SEL>
//   <i> Shows which pin RMII0_TXD0 is mapped to
//     <0=> Disabled
//     <1=> PTA16<selection=PTA16_SIG_SEL,RMII0_TXD0/MII0_TXD0>
//     <0=> Default
#define RMII0_TXD0_PIN_SEL   0
#if RMII0_TXD0_PIN_SEL == 1
#define RMII0_TXD0_GPIO      digitalIO_PTA16
#define RMII0_TXD0_FN        4
#endif

// Pin Mapping for RMII0_TXD1 signal
//   <o> RMII0_TXD1 [PTA17]<name=RMII0_TXD1_PIN_SEL>
//   <i> Shows which pin RMII0_TXD1 is mapped to
//     <0=> Disabled
//     <1=> PTA17<selection=PTA17_SIG_SEL,RMII0_TXD1/MII0_TXD1>
//     <0=> Default
#define RMII0_TXD1_PIN_SEL   0
#if RMII0_TXD1_PIN_SEL == 1
#define RMII0_TXD1_GPIO      digitalIO_PTA17
#define RMII0_TXD1_FN        4
#endif

// Pin Mapping for RMII0_TXEN signal
//   <o> RMII0_TXEN [PTA15]<name=RMII0_TXEN_PIN_SEL>
//   <i> Shows which pin RMII0_TXEN is mapped to
//     <0=> Disabled
//     <1=> PTA15<selection=PTA15_SIG_SEL,RMII0_TXEN/MII0_TXEN>
//     <0=> Default
#define RMII0_TXEN_PIN_SEL   0
#if RMII0_TXEN_PIN_SEL == 1
#define RMII0_TXEN_GPIO      digitalIO_PTA15
#define RMII0_TXEN_FN        4
#endif

// </h>

// <h> Secured Digital Host Controller (SDHC0)

// Pin Mapping for SDHC0_CLKIN signal
//   <o> SDHC0_CLKIN [PTD11]<name=SDHC0_CLKIN_PIN_SEL>
//   <i> Shows which pin SDHC0_CLKIN is mapped to
//     <0=> Disabled
//     <1=> PTD11<selection=PTD11_SIG_SEL,SDHC0_CLKIN>
//     <0=> Default
#define SDHC0_CLKIN_PIN_SEL  0
#if SDHC0_CLKIN_PIN_SEL == 1
#define SDHC0_CLKIN_GPIO     digitalIO_PTD11
#define SDHC0_CLKIN_FN       4
#endif

// Pin Mapping for SDHC0_CMD signal
//   <o> SDHC0_CMD [PTE3]<name=SDHC0_CMD_PIN_SEL>
//   <i> Shows which pin SDHC0_CMD is mapped to
//     <0=> Disabled
//     <1=> PTE3<selection=PTE3_SIG_SEL,SDHC0_CMD>
//     <0=> Default
#define SDHC0_CMD_PIN_SEL    0
#if SDHC0_CMD_PIN_SEL == 1
#define SDHC0_CMD_GPIO       digitalIO_PTE3
#define SDHC0_CMD_FN         4
#endif

// Pin Mapping for SDHC0_D0 signal
//   <o> SDHC0_D0 [PTE1]<name=SDHC0_D0_PIN_SEL>
//   <i> Shows which pin SDHC0_D0 is mapped to
//     <0=> Disabled
//     <1=> PTE1<selection=PTE1_SIG_SEL,SDHC0_D0>
//     <0=> Default
#define SDHC0_D0_PIN_SEL     0
#if SDHC0_D0_PIN_SEL == 1
#define SDHC0_D0_GPIO        digitalIO_PTE1
#define SDHC0_D0_FN          4
#endif

// Pin Mapping for SDHC0_D1 signal
//   <o> SDHC0_D1 [PTE0]<name=SDHC0_D1_PIN_SEL>
//   <i> Shows which pin SDHC0_D1 is mapped to
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,SDHC0_D1>
//     <0=> Default
#define SDHC0_D1_PIN_SEL     0
#if SDHC0_D1_PIN_SEL == 1
#define SDHC0_D1_GPIO        digitalIO_PTE0
#define SDHC0_D1_FN          4
#endif

// Pin Mapping for SDHC0_D2 signal
//   <o> SDHC0_D2 [PTE5]<name=SDHC0_D2_PIN_SEL>
//   <i> Shows which pin SDHC0_D2 is mapped to
//     <0=> Disabled
//     <1=> PTE5<selection=PTE5_SIG_SEL,SDHC0_D2>
//     <0=> Default
#define SDHC0_D2_PIN_SEL     0
#if SDHC0_D2_PIN_SEL == 1
#define SDHC0_D2_GPIO        digitalIO_PTE5
#define SDHC0_D2_FN          4
#endif

// Pin Mapping for SDHC0_D3 signal
//   <o> SDHC0_D3 [PTE4]<name=SDHC0_D3_PIN_SEL>
//   <i> Shows which pin SDHC0_D3 is mapped to
//     <0=> Disabled
//     <1=> PTE4<selection=PTE4_SIG_SEL,SDHC0_D3>
//     <0=> Default
#define SDHC0_D3_PIN_SEL     0
#if SDHC0_D3_PIN_SEL == 1
#define SDHC0_D3_GPIO        digitalIO_PTE4
#define SDHC0_D3_FN          4
#endif

// Pin Mapping for SDHC0_D4 signal
//   <o> SDHC0_D4 [PTD12]<name=SDHC0_D4_PIN_SEL>
//   <i> Shows which pin SDHC0_D4 is mapped to
//     <0=> Disabled
//     <1=> PTD12<selection=PTD12_SIG_SEL,SDHC0_D4>
//     <0=> Default
#define SDHC0_D4_PIN_SEL     0
#if SDHC0_D4_PIN_SEL == 1
#define SDHC0_D4_GPIO        digitalIO_PTD12
#define SDHC0_D4_FN          4
#endif

// Pin Mapping for SDHC0_D5 signal
//   <o> SDHC0_D5 [PTD13]<name=SDHC0_D5_PIN_SEL>
//   <i> Shows which pin SDHC0_D5 is mapped to
//     <0=> Disabled
//     <1=> PTD13<selection=PTD13_SIG_SEL,SDHC0_D5>
//     <0=> Default
#define SDHC0_D5_PIN_SEL     0
#if SDHC0_D5_PIN_SEL == 1
#define SDHC0_D5_GPIO        digitalIO_PTD13
#define SDHC0_D5_FN          4
#endif

// Pin Mapping for SDHC0_D6 signal
//   <o> SDHC0_D6 [PTD14]<name=SDHC0_D6_PIN_SEL>
//   <i> Shows which pin SDHC0_D6 is mapped to
//     <0=> Disabled
//     <1=> PTD14<selection=PTD14_SIG_SEL,SDHC0_D6>
//     <0=> Default
#define SDHC0_D6_PIN_SEL     0
#if SDHC0_D6_PIN_SEL == 1
#define SDHC0_D6_GPIO        digitalIO_PTD14
#define SDHC0_D6_FN          4
#endif

// Pin Mapping for SDHC0_D7 signal
//   <o> SDHC0_D7 [PTD15]<name=SDHC0_D7_PIN_SEL>
//   <i> Shows which pin SDHC0_D7 is mapped to
//     <0=> Disabled
//     <1=> PTD15<selection=PTD15_SIG_SEL,SDHC0_D7>
//     <0=> Default
#define SDHC0_D7_PIN_SEL     0
#if SDHC0_D7_PIN_SEL == 1
#define SDHC0_D7_GPIO        digitalIO_PTD15
#define SDHC0_D7_FN          4
#endif

// Pin Mapping for SDHC0_DCLK signal
//   <o> SDHC0_DCLK [PTE2]<name=SDHC0_DCLK_PIN_SEL>
//   <i> Shows which pin SDHC0_DCLK is mapped to
//     <0=> Disabled
//     <1=> PTE2<selection=PTE2_SIG_SEL,SDHC0_DCLK>
//     <0=> Default
#define SDHC0_DCLK_PIN_SEL   0
#if SDHC0_DCLK_PIN_SEL == 1
#define SDHC0_DCLK_GPIO      digitalIO_PTE2
#define SDHC0_DCLK_FN        4
#endif

// </h>

// <h> Serial Peripheral Interface (SPI0)

// Pin Mapping for SPI0_PCS0 signal
//   <o> SPI0_PCS0 [PTA14, PTC4, PTD0]<name=SPI0_PCS0_PIN_SEL>
//   <i> Shows which pin SPI0_PCS0 is mapped to
//     <0=> Disabled
//     <1=> PTA14<selection=PTA14_SIG_SEL,SPI0_PCS0>
//     <2=> PTC4 (Alias:D9)<selection=PTC4_SIG_SEL,SPI0_PCS0>
//     <3=> PTD0 (Alias:D10)<selection=PTD0_SIG_SEL,SPI0_PCS0>
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
#endif

// Pin Mapping for SPI0_PCS1 signal
//   <o> SPI0_PCS1 [PTC3, PTD4]<name=SPI0_PCS1_PIN_SEL>
//   <i> Shows which pin SPI0_PCS1 is mapped to
//     <0=> Disabled
//     <1=> PTC3 (Alias:D7)<selection=PTC3_SIG_SEL,SPI0_PCS1>
//     <2=> PTD4 (Alias:nRF24L01_cs)<selection=PTD4_SIG_SEL,SPI0_PCS1>
//     <0=> Default
#define SPI0_PCS1_PIN_SEL    0
#if SPI0_PCS1_PIN_SEL == 1
#define SPI0_PCS1_GPIO       digitalIO_PTC3
#define SPI0_PCS1_FN         2
#elif SPI0_PCS1_PIN_SEL == 2
#define SPI0_PCS1_GPIO       digitalIO_PTD4
#define SPI0_PCS1_FN         2
#endif

// Pin Mapping for SPI0_PCS2 signal
//   <o> SPI0_PCS2 [PTC2, PTD5]<name=SPI0_PCS2_PIN_SEL>
//   <i> Shows which pin SPI0_PCS2 is mapped to
//     <0=> Disabled
//     <1=> PTC2 (Alias:D6)<selection=PTC2_SIG_SEL,SPI0_PCS2>
//     <2=> PTD5 (Alias:nRF24L01_sck)<selection=PTD5_SIG_SEL,SPI0_PCS2>
//     <0=> Default
#define SPI0_PCS2_PIN_SEL    0
#if SPI0_PCS2_PIN_SEL == 1
#define SPI0_PCS2_GPIO       digitalIO_PTC2
#define SPI0_PCS2_FN         2
#elif SPI0_PCS2_PIN_SEL == 2
#define SPI0_PCS2_GPIO       digitalIO_PTD5
#define SPI0_PCS2_FN         2
#endif

// Pin Mapping for SPI0_PCS3 signal
//   <o> SPI0_PCS3 [PTC1, PTD6]<name=SPI0_PCS3_PIN_SEL>
//   <i> Shows which pin SPI0_PCS3 is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,SPI0_PCS3>
//     <2=> PTD6 (Alias:nRF24L01_mosi)<selection=PTD6_SIG_SEL,SPI0_PCS3>
//     <0=> Default
#define SPI0_PCS3_PIN_SEL    0
#if SPI0_PCS3_PIN_SEL == 1
#define SPI0_PCS3_GPIO       digitalIO_PTC1
#define SPI0_PCS3_FN         2
#elif SPI0_PCS3_PIN_SEL == 2
#define SPI0_PCS3_GPIO       digitalIO_PTD6
#define SPI0_PCS3_FN         2
#endif

// Pin Mapping for SPI0_PCS4 signal
//   <o> SPI0_PCS4 [PTC0]<name=SPI0_PCS4_PIN_SEL>
//   <i> Shows which pin SPI0_PCS4 is mapped to
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,SPI0_PCS4>
//     <0=> Default
#define SPI0_PCS4_PIN_SEL    0
#if SPI0_PCS4_PIN_SEL == 1
#define SPI0_PCS4_GPIO       digitalIO_PTC0
#define SPI0_PCS4_FN         2
#endif

// Pin Mapping for SPI0_PCS5 signal
//   <o> SPI0_PCS5 [PTB23]<name=SPI0_PCS5_PIN_SEL>
//   <i> Shows which pin SPI0_PCS5 is mapped to
//     <0=> Disabled
//     <1=> PTB23 (Alias:D4)<selection=PTB23_SIG_SEL,SPI0_PCS5>
//     <0=> Default
#define SPI0_PCS5_PIN_SEL    0
#if SPI0_PCS5_PIN_SEL == 1
#define SPI0_PCS5_GPIO       digitalIO_PTB23
#define SPI0_PCS5_FN         3
#endif

// Pin Mapping for SPI0_SCK signal
//   <o> SPI0_SCK [PTA15, PTC5, PTD1]<name=SPI0_SCK_PIN_SEL>
//   <i> Shows which pin SPI0_SCK is mapped to
//     <0=> Disabled
//     <1=> PTA15<selection=PTA15_SIG_SEL,SPI0_SCK>
//     <2=> PTC5<selection=PTC5_SIG_SEL,SPI0_SCK>
//     <3=> PTD1 (Alias:D13)<selection=PTD1_SIG_SEL,SPI0_SCK>
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
#endif

// Pin Mapping for SPI0_SIN signal
//   <o> SPI0_SIN [PTA17, PTC7, PTD3]<name=SPI0_SIN_PIN_SEL>
//   <i> Shows which pin SPI0_SIN is mapped to
//     <0=> Disabled
//     <1=> PTA17<selection=PTA17_SIG_SEL,SPI0_SIN>
//     <2=> PTC7<selection=PTC7_SIG_SEL,SPI0_SIN>
//     <3=> PTD3 (Alias:D12)<selection=PTD3_SIG_SEL,SPI0_SIN>
//     <0=> Default
#define SPI0_SIN_PIN_SEL     0
#if SPI0_SIN_PIN_SEL == 1
#define SPI0_SIN_GPIO        digitalIO_PTA17
#define SPI0_SIN_FN          2
#elif SPI0_SIN_PIN_SEL == 2
#define SPI0_SIN_GPIO        digitalIO_PTC7
#define SPI0_SIN_FN          2
#elif SPI0_SIN_PIN_SEL == 3
#define SPI0_SIN_GPIO        digitalIO_PTD3
#define SPI0_SIN_FN          2
#endif

// Pin Mapping for SPI0_SOUT signal
//   <o> SPI0_SOUT [PTA16, PTC6, PTD2]<name=SPI0_SOUT_PIN_SEL>
//   <i> Shows which pin SPI0_SOUT is mapped to
//     <0=> Disabled
//     <1=> PTA16<selection=PTA16_SIG_SEL,SPI0_SOUT>
//     <2=> PTC6<selection=PTC6_SIG_SEL,SPI0_SOUT>
//     <3=> PTD2 (Alias:D11)<selection=PTD2_SIG_SEL,SPI0_SOUT>
//     <0=> Default
#define SPI0_SOUT_PIN_SEL    0
#if SPI0_SOUT_PIN_SEL == 1
#define SPI0_SOUT_GPIO       digitalIO_PTA16
#define SPI0_SOUT_FN         2
#elif SPI0_SOUT_PIN_SEL == 2
#define SPI0_SOUT_GPIO       digitalIO_PTC6
#define SPI0_SOUT_FN         2
#elif SPI0_SOUT_PIN_SEL == 3
#define SPI0_SOUT_GPIO       digitalIO_PTD2
#define SPI0_SOUT_FN         2
#endif

// </h>

// <h> Serial Peripheral Interface (SPI1)

// Pin Mapping for SPI1_PCS0 signal
//   <o> SPI1_PCS0 [PTB10, PTE4, PTD4]<name=SPI1_PCS0_PIN_SEL>
//   <i> Shows which pin SPI1_PCS0 is mapped to
//     <0=> Disabled
//     <1=> PTB10 (Alias:A2)<selection=PTB10_SIG_SEL,SPI1_PCS0>
//     <2=> PTE4<selection=PTE4_SIG_SEL,SPI1_PCS0>
//     <3=> PTD4 (Alias:nRF24L01_cs)<selection=PTD4_SIG_SEL,SPI1_PCS0>
//     <3=> Default
#define SPI1_PCS0_PIN_SEL    3
#if SPI1_PCS0_PIN_SEL == 1
#define SPI1_PCS0_GPIO       digitalIO_PTB10
#define SPI1_PCS0_FN         2
#elif SPI1_PCS0_PIN_SEL == 2
#define SPI1_PCS0_GPIO       digitalIO_PTE4
#define SPI1_PCS0_FN         2
#elif SPI1_PCS0_PIN_SEL == 3
#define SPI1_PCS0_GPIO       digitalIO_PTD4
#define SPI1_PCS0_FN         7
#endif

// Pin Mapping for SPI1_PCS1 signal
//   <o> SPI1_PCS1 [PTB9, PTE0]<name=SPI1_PCS1_PIN_SEL>
//   <i> Shows which pin SPI1_PCS1 is mapped to
//     <0=> Disabled
//     <1=> PTB9 (Alias:D2)<selection=PTB9_SIG_SEL,SPI1_PCS1>
//     <2=> PTE0<selection=PTE0_SIG_SEL,SPI1_PCS1>
//     <0=> Default
#define SPI1_PCS1_PIN_SEL    0
#if SPI1_PCS1_PIN_SEL == 1
#define SPI1_PCS1_GPIO       digitalIO_PTB9
#define SPI1_PCS1_FN         2
#elif SPI1_PCS1_PIN_SEL == 2
#define SPI1_PCS1_GPIO       digitalIO_PTE0
#define SPI1_PCS1_FN         2
#endif

// Pin Mapping for SPI1_PCS2 signal
//   <o> SPI1_PCS2 [PTE5]<name=SPI1_PCS2_PIN_SEL>
//   <i> Shows which pin SPI1_PCS2 is mapped to
//     <0=> Disabled
//     <1=> PTE5<selection=PTE5_SIG_SEL,SPI1_PCS2>
//     <0=> Default
#define SPI1_PCS2_PIN_SEL    0
#if SPI1_PCS2_PIN_SEL == 1
#define SPI1_PCS2_GPIO       digitalIO_PTE5
#define SPI1_PCS2_FN         2
#endif

// Pin Mapping for SPI1_PCS3 signal
//   <o> SPI1_PCS3 [PTE6]<name=SPI1_PCS3_PIN_SEL>
//   <i> Shows which pin SPI1_PCS3 is mapped to
//     <0=> Disabled
//     <1=> PTE6<selection=PTE6_SIG_SEL,SPI1_PCS3>
//     <0=> Default
#define SPI1_PCS3_PIN_SEL    0
#if SPI1_PCS3_PIN_SEL == 1
#define SPI1_PCS3_GPIO       digitalIO_PTE6
#define SPI1_PCS3_FN         2
#endif

// Pin Mapping for SPI1_SCK signal
//   <o> SPI1_SCK [PTB11, PTE2, PTD5]<name=SPI1_SCK_PIN_SEL>
//   <i> Shows which pin SPI1_SCK is mapped to
//     <0=> Disabled
//     <1=> PTB11 (Alias:A3)<selection=PTB11_SIG_SEL,SPI1_SCK>
//     <2=> PTE2<selection=PTE2_SIG_SEL,SPI1_SCK>
//     <3=> PTD5 (Alias:nRF24L01_sck)<selection=PTD5_SIG_SEL,SPI1_SCK>
//     <3=> Default
#define SPI1_SCK_PIN_SEL     3
#if SPI1_SCK_PIN_SEL == 1
#define SPI1_SCK_GPIO        digitalIO_PTB11
#define SPI1_SCK_FN          2
#elif SPI1_SCK_PIN_SEL == 2
#define SPI1_SCK_GPIO        digitalIO_PTE2
#define SPI1_SCK_FN          2
#elif SPI1_SCK_PIN_SEL == 3
#define SPI1_SCK_GPIO        digitalIO_PTD5
#define SPI1_SCK_FN          7
#endif

// Pin Mapping for SPI1_SIN signal
//   <o> SPI1_SIN [PTB17, PTE3, PTD7, PTE1]<name=SPI1_SIN_PIN_SEL>
//   <i> Shows which pin SPI1_SIN is mapped to
//     <0=> Disabled
//     <1=> PTB17<selection=PTB17_SIG_SEL,SPI1_SIN>
//     <2=> PTE3<selection=PTE3_SIG_SEL,SPI1_SIN>
//     <3=> PTD7 (Alias:nRF24L01_miso)<selection=PTD7_SIG_SEL,SPI1_SIN>
//     <4=> PTE1<selection=PTE1_SIG_SEL,SPI1_SIN>
//     <3=> Default
#define SPI1_SIN_PIN_SEL     3
#if SPI1_SIN_PIN_SEL == 1
#define SPI1_SIN_GPIO        digitalIO_PTB17
#define SPI1_SIN_FN          2
#elif SPI1_SIN_PIN_SEL == 2
#define SPI1_SIN_GPIO        digitalIO_PTE3
#define SPI1_SIN_FN          2
#elif SPI1_SIN_PIN_SEL == 3
#define SPI1_SIN_GPIO        digitalIO_PTD7
#define SPI1_SIN_FN          7
#elif SPI1_SIN_PIN_SEL == 4
#define SPI1_SIN_GPIO        digitalIO_PTE1
#define SPI1_SIN_FN          7
#endif

// Pin Mapping for SPI1_SOUT signal
//   <o> SPI1_SOUT [PTB16, PTE1, PTD6, PTE3]<name=SPI1_SOUT_PIN_SEL>
//   <i> Shows which pin SPI1_SOUT is mapped to
//     <0=> Disabled
//     <1=> PTB16<selection=PTB16_SIG_SEL,SPI1_SOUT>
//     <2=> PTE1<selection=PTE1_SIG_SEL,SPI1_SOUT>
//     <3=> PTD6 (Alias:nRF24L01_mosi)<selection=PTD6_SIG_SEL,SPI1_SOUT>
//     <4=> PTE3<selection=PTE3_SIG_SEL,SPI1_SOUT>
//     <3=> Default
#define SPI1_SOUT_PIN_SEL    3
#if SPI1_SOUT_PIN_SEL == 1
#define SPI1_SOUT_GPIO       digitalIO_PTB16
#define SPI1_SOUT_FN         2
#elif SPI1_SOUT_PIN_SEL == 2
#define SPI1_SOUT_GPIO       digitalIO_PTE1
#define SPI1_SOUT_FN         2
#elif SPI1_SOUT_PIN_SEL == 3
#define SPI1_SOUT_GPIO       digitalIO_PTD6
#define SPI1_SOUT_FN         7
#elif SPI1_SOUT_PIN_SEL == 4
#define SPI1_SOUT_GPIO       digitalIO_PTE3
#define SPI1_SOUT_FN         7
#endif

// </h>

// <h> Serial Peripheral Interface (SPI2)

// Pin Mapping for SPI2_PCS0 signal
//   <o> SPI2_PCS0 [PTB20, PTD11]<name=SPI2_PCS0_PIN_SEL>
//   <i> Shows which pin SPI2_PCS0 is mapped to
//     <0=> Disabled
//     <1=> PTB20<selection=PTB20_SIG_SEL,SPI2_PCS0>
//     <2=> PTD11<selection=PTD11_SIG_SEL,SPI2_PCS0>
//     <0=> Default
#define SPI2_PCS0_PIN_SEL    0
#if SPI2_PCS0_PIN_SEL == 1
#define SPI2_PCS0_GPIO       digitalIO_PTB20
#define SPI2_PCS0_FN         2
#elif SPI2_PCS0_PIN_SEL == 2
#define SPI2_PCS0_GPIO       digitalIO_PTD11
#define SPI2_PCS0_FN         2
#endif

// Pin Mapping for SPI2_PCS1 signal
//   <o> SPI2_PCS1 [PTD15]<name=SPI2_PCS1_PIN_SEL>
//   <i> Shows which pin SPI2_PCS1 is mapped to
//     <0=> Disabled
//     <1=> PTD15<selection=PTD15_SIG_SEL,SPI2_PCS1>
//     <0=> Default
#define SPI2_PCS1_PIN_SEL    0
#if SPI2_PCS1_PIN_SEL == 1
#define SPI2_PCS1_GPIO       digitalIO_PTD15
#define SPI2_PCS1_FN         2
#endif

// Pin Mapping for SPI2_SCK signal
//   <o> SPI2_SCK [PTB21, PTD12]<name=SPI2_SCK_PIN_SEL>
//   <i> Shows which pin SPI2_SCK is mapped to
//     <0=> Disabled
//     <1=> PTB21 (Alias:LED_BLUE)<selection=PTB21_SIG_SEL,SPI2_SCK>
//     <2=> PTD12<selection=PTD12_SIG_SEL,SPI2_SCK>
//     <0=> Default
#define SPI2_SCK_PIN_SEL     0
#if SPI2_SCK_PIN_SEL == 1
#define SPI2_SCK_GPIO        digitalIO_PTB21
#define SPI2_SCK_FN          2
#elif SPI2_SCK_PIN_SEL == 2
#define SPI2_SCK_GPIO        digitalIO_PTD12
#define SPI2_SCK_FN          2
#endif

// Pin Mapping for SPI2_SIN signal
//   <o> SPI2_SIN [PTB23, PTD14]<name=SPI2_SIN_PIN_SEL>
//   <i> Shows which pin SPI2_SIN is mapped to
//     <0=> Disabled
//     <1=> PTB23 (Alias:D4)<selection=PTB23_SIG_SEL,SPI2_SIN>
//     <2=> PTD14<selection=PTD14_SIG_SEL,SPI2_SIN>
//     <0=> Default
#define SPI2_SIN_PIN_SEL     0
#if SPI2_SIN_PIN_SEL == 1
#define SPI2_SIN_GPIO        digitalIO_PTB23
#define SPI2_SIN_FN          2
#elif SPI2_SIN_PIN_SEL == 2
#define SPI2_SIN_GPIO        digitalIO_PTD14
#define SPI2_SIN_FN          2
#endif

// Pin Mapping for SPI2_SOUT signal
//   <o> SPI2_SOUT [PTB22, PTD13]<name=SPI2_SOUT_PIN_SEL>
//   <i> Shows which pin SPI2_SOUT is mapped to
//     <0=> Disabled
//     <1=> PTB22 (Alias:LED_RED)<selection=PTB22_SIG_SEL,SPI2_SOUT>
//     <2=> PTD13<selection=PTD13_SIG_SEL,SPI2_SOUT>
//     <0=> Default
#define SPI2_SOUT_PIN_SEL    0
#if SPI2_SOUT_PIN_SEL == 1
#define SPI2_SOUT_GPIO       digitalIO_PTB22
#define SPI2_SOUT_FN         2
#elif SPI2_SOUT_PIN_SEL == 2
#define SPI2_SOUT_GPIO       digitalIO_PTD13
#define SPI2_SOUT_FN         2
#endif

// </h>

// <h> Universal Asynchronous Rx/Tx (UART0)

// Pin Mapping for UART0_COL_b signal
//   <o> UART0_COL_b [PTA0, PTA16, PTB3, PTD5]<name=UART0_COL_b_PIN_SEL>
//   <i> Shows which pin UART0_COL_b is mapped to
//     <0=> Disabled
//     <1=> PTA0 (Alias:D8)<selection=PTA0_SIG_SEL,UART0_CTS_b/UART0_COL_b>
//     <2=> PTA16<selection=PTA16_SIG_SEL,UART0_CTS_b/UART0_COL_b>
//     <3=> PTB3 (Alias:A1)<selection=PTB3_SIG_SEL,UART0_CTS_b/UART0_COL_b>
//     <4=> PTD5 (Alias:nRF24L01_sck)<selection=PTD5_SIG_SEL,UART0_CTS_b/UART0_COL_b>
//     <0=> Default
#define UART0_COL_b_PIN_SEL  0
#if UART0_COL_b_PIN_SEL == 1
#define UART0_COL_b_GPIO     digitalIO_PTA0
#define UART0_COL_b_FN       2
#elif UART0_COL_b_PIN_SEL == 2
#define UART0_COL_b_GPIO     digitalIO_PTA16
#define UART0_COL_b_FN       3
#elif UART0_COL_b_PIN_SEL == 3
#define UART0_COL_b_GPIO     digitalIO_PTB3
#define UART0_COL_b_FN       3
#elif UART0_COL_b_PIN_SEL == 4
#define UART0_COL_b_GPIO     digitalIO_PTD5
#define UART0_COL_b_FN       3
#endif

// Pin Mapping for UART0_CTS_b signal
//   <o> UART0_CTS_b [PTA0, PTA16, PTB3, PTD5]<name=UART0_CTS_b_PIN_SEL>
//   <i> Shows which pin UART0_CTS_b is mapped to
//     <0=> Disabled
//     <1=> PTA0 (Alias:D8)<selection=PTA0_SIG_SEL,UART0_CTS_b/UART0_COL_b>
//     <2=> PTA16<selection=PTA16_SIG_SEL,UART0_CTS_b/UART0_COL_b>
//     <3=> PTB3 (Alias:A1)<selection=PTB3_SIG_SEL,UART0_CTS_b/UART0_COL_b>
//     <4=> PTD5 (Alias:nRF24L01_sck)<selection=PTD5_SIG_SEL,UART0_CTS_b/UART0_COL_b>
//     <0=> Default
#define UART0_CTS_b_PIN_SEL  0
#if UART0_CTS_b_PIN_SEL == 1
#define UART0_CTS_b_GPIO     digitalIO_PTA0
#define UART0_CTS_b_FN       2
#elif UART0_CTS_b_PIN_SEL == 2
#define UART0_CTS_b_GPIO     digitalIO_PTA16
#define UART0_CTS_b_FN       3
#elif UART0_CTS_b_PIN_SEL == 3
#define UART0_CTS_b_GPIO     digitalIO_PTB3
#define UART0_CTS_b_FN       3
#elif UART0_CTS_b_PIN_SEL == 4
#define UART0_CTS_b_GPIO     digitalIO_PTD5
#define UART0_CTS_b_FN       3
#endif

// Pin Mapping for UART0_RTS_b signal
//   <o> UART0_RTS_b [PTA3, PTA17, PTB2, PTD4]<name=UART0_RTS_b_PIN_SEL>
//   <i> Shows which pin UART0_RTS_b is mapped to
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,UART0_RTS_b>
//     <2=> PTA17<selection=PTA17_SIG_SEL,UART0_RTS_b>
//     <3=> PTB2 (Alias:A0)<selection=PTB2_SIG_SEL,UART0_RTS_b>
//     <4=> PTD4 (Alias:nRF24L01_cs)<selection=PTD4_SIG_SEL,UART0_RTS_b>
//     <0=> Default
#define UART0_RTS_b_PIN_SEL  0
#if UART0_RTS_b_PIN_SEL == 1
#define UART0_RTS_b_GPIO     digitalIO_PTA3
#define UART0_RTS_b_FN       2
#elif UART0_RTS_b_PIN_SEL == 2
#define UART0_RTS_b_GPIO     digitalIO_PTA17
#define UART0_RTS_b_FN       3
#elif UART0_RTS_b_PIN_SEL == 3
#define UART0_RTS_b_GPIO     digitalIO_PTB2
#define UART0_RTS_b_FN       3
#elif UART0_RTS_b_PIN_SEL == 4
#define UART0_RTS_b_GPIO     digitalIO_PTD4
#define UART0_RTS_b_FN       3
#endif

// Pin Mapping for UART0_RX signal
//   <o> UART0_RX [PTA1, PTA15, PTB16, PTD6]<name=UART0_RX_PIN_SEL>
//   <i> Shows which pin UART0_RX is mapped to
//     <0=> Disabled
//     <1=> PTA1 (Alias:D3)<selection=PTA1_SIG_SEL,UART0_RX>
//     <2=> PTA15<selection=PTA15_SIG_SEL,UART0_RX>
//     <3=> PTB16<selection=PTB16_SIG_SEL,UART0_RX>
//     <4=> PTD6 (Alias:nRF24L01_mosi)<selection=PTD6_SIG_SEL,UART0_RX>
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
#endif

// Pin Mapping for UART0_TX signal
//   <o> UART0_TX [PTA2, PTA14, PTB17, PTD7]<name=UART0_TX_PIN_SEL>
//   <i> Shows which pin UART0_TX is mapped to
//     <0=> Disabled
//     <1=> PTA2 (Alias:D5)<selection=PTA2_SIG_SEL,UART0_TX>
//     <2=> PTA14<selection=PTA14_SIG_SEL,UART0_TX>
//     <3=> PTB17<selection=PTB17_SIG_SEL,UART0_TX>
//     <4=> PTD7 (Alias:nRF24L01_miso)<selection=PTD7_SIG_SEL,UART0_TX>
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
#endif

// </h>

// <h> Universal Asynchronous Rx/Tx (UART1)

// Pin Mapping for UART1_CTS_b signal
//   <o> UART1_CTS_b [PTC2, PTE2]<name=UART1_CTS_b_PIN_SEL>
//   <i> Shows which pin UART1_CTS_b is mapped to
//     <0=> Disabled
//     <1=> PTC2 (Alias:D6)<selection=PTC2_SIG_SEL,UART1_CTS_b>
//     <2=> PTE2<selection=PTE2_SIG_SEL,UART1_CTS_b>
//     <0=> Default
#define UART1_CTS_b_PIN_SEL  0
#if UART1_CTS_b_PIN_SEL == 1
#define UART1_CTS_b_GPIO     digitalIO_PTC2
#define UART1_CTS_b_FN       3
#elif UART1_CTS_b_PIN_SEL == 2
#define UART1_CTS_b_GPIO     digitalIO_PTE2
#define UART1_CTS_b_FN       3
#endif

// Pin Mapping for UART1_RTS_b signal
//   <o> UART1_RTS_b [PTC1, PTE3]<name=UART1_RTS_b_PIN_SEL>
//   <i> Shows which pin UART1_RTS_b is mapped to
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,UART1_RTS_b>
//     <2=> PTE3<selection=PTE3_SIG_SEL,UART1_RTS_b>
//     <0=> Default
#define UART1_RTS_b_PIN_SEL  0
#if UART1_RTS_b_PIN_SEL == 1
#define UART1_RTS_b_GPIO     digitalIO_PTC1
#define UART1_RTS_b_FN       3
#elif UART1_RTS_b_PIN_SEL == 2
#define UART1_RTS_b_GPIO     digitalIO_PTE3
#define UART1_RTS_b_FN       3
#endif

// Pin Mapping for UART1_RX signal
//   <o> UART1_RX [PTC3, PTE1]<name=UART1_RX_PIN_SEL>
//   <i> Shows which pin UART1_RX is mapped to
//     <0=> Disabled
//     <1=> PTC3 (Alias:D7)<selection=PTC3_SIG_SEL,UART1_RX>
//     <2=> PTE1<selection=PTE1_SIG_SEL,UART1_RX>
//     <0=> Default
#define UART1_RX_PIN_SEL     0
#if UART1_RX_PIN_SEL == 1
#define UART1_RX_GPIO        digitalIO_PTC3
#define UART1_RX_FN          3
#elif UART1_RX_PIN_SEL == 2
#define UART1_RX_GPIO        digitalIO_PTE1
#define UART1_RX_FN          3
#endif

// Pin Mapping for UART1_TX signal
//   <o> UART1_TX [PTC4, PTE0]<name=UART1_TX_PIN_SEL>
//   <i> Shows which pin UART1_TX is mapped to
//     <0=> Disabled
//     <1=> PTC4 (Alias:D9)<selection=PTC4_SIG_SEL,UART1_TX>
//     <2=> PTE0<selection=PTE0_SIG_SEL,UART1_TX>
//     <0=> Default
#define UART1_TX_PIN_SEL     0
#if UART1_TX_PIN_SEL == 1
#define UART1_TX_GPIO        digitalIO_PTC4
#define UART1_TX_FN          3
#elif UART1_TX_PIN_SEL == 2
#define UART1_TX_GPIO        digitalIO_PTE0
#define UART1_TX_FN          3
#endif

// </h>

// <h> Universal Asynchronous Rx/Tx (UART2)

// Pin Mapping for UART2_CTS_b signal
//   <o> UART2_CTS_b [PTD1]<name=UART2_CTS_b_PIN_SEL>
//   <i> Shows which pin UART2_CTS_b is mapped to
//     <0=> Disabled
//     <1=> PTD1 (Alias:D13)<selection=PTD1_SIG_SEL,UART2_CTS_b>
//     <0=> Default
#define UART2_CTS_b_PIN_SEL  0
#if UART2_CTS_b_PIN_SEL == 1
#define UART2_CTS_b_GPIO     digitalIO_PTD1
#define UART2_CTS_b_FN       3
#endif

// Pin Mapping for UART2_RTS_b signal
//   <o> UART2_RTS_b [PTD0]<name=UART2_RTS_b_PIN_SEL>
//   <i> Shows which pin UART2_RTS_b is mapped to
//     <0=> Disabled
//     <1=> PTD0 (Alias:D10)<selection=PTD0_SIG_SEL,UART2_RTS_b>
//     <0=> Default
#define UART2_RTS_b_PIN_SEL  0
#if UART2_RTS_b_PIN_SEL == 1
#define UART2_RTS_b_GPIO     digitalIO_PTD0
#define UART2_RTS_b_FN       3
#endif

// Pin Mapping for UART2_RX signal
//   <o> UART2_RX [PTD2]<name=UART2_RX_PIN_SEL>
//   <i> Shows which pin UART2_RX is mapped to
//     <0=> Disabled
//     <1=> PTD2 (Alias:D11)<selection=PTD2_SIG_SEL,UART2_RX>
//     <0=> Default
#define UART2_RX_PIN_SEL     0
#if UART2_RX_PIN_SEL == 1
#define UART2_RX_GPIO        digitalIO_PTD2
#define UART2_RX_FN          3
#endif

// Pin Mapping for UART2_TX signal
//   <o> UART2_TX [PTD3]<name=UART2_TX_PIN_SEL>
//   <i> Shows which pin UART2_TX is mapped to
//     <0=> Disabled
//     <1=> PTD3 (Alias:D12)<selection=PTD3_SIG_SEL,UART2_TX>
//     <0=> Default
#define UART2_TX_PIN_SEL     0
#if UART2_TX_PIN_SEL == 1
#define UART2_TX_GPIO        digitalIO_PTD3
#define UART2_TX_FN          3
#endif

// </h>

// <h> Universal Asynchronous Rx/Tx (UART3)

// Pin Mapping for UART3_CTS_b signal
//   <o> UART3_CTS_b [PTB13, PTB9, PTC19, PTE6]<name=UART3_CTS_b_PIN_SEL>
//   <i> Shows which pin UART3_CTS_b is mapped to
//     <0=> Disabled
//     <1=> PTB13<selection=PTB13_SIG_SEL,UART3_CTS_b>
//     <2=> PTB9 (Alias:D2)<selection=PTB9_SIG_SEL,UART3_CTS_b>
//     <3=> PTC19<selection=PTC19_SIG_SEL,UART3_CTS_b>
//     <4=> PTE6<selection=PTE6_SIG_SEL,UART3_CTS_b>
//     <0=> Default
#define UART3_CTS_b_PIN_SEL  0
#if UART3_CTS_b_PIN_SEL == 1
#define UART3_CTS_b_GPIO     digitalIO_PTB13
#define UART3_CTS_b_FN       2
#elif UART3_CTS_b_PIN_SEL == 2
#define UART3_CTS_b_GPIO     digitalIO_PTB9
#define UART3_CTS_b_FN       3
#elif UART3_CTS_b_PIN_SEL == 3
#define UART3_CTS_b_GPIO     digitalIO_PTC19
#define UART3_CTS_b_FN       3
#elif UART3_CTS_b_PIN_SEL == 4
#define UART3_CTS_b_GPIO     digitalIO_PTE6
#define UART3_CTS_b_FN       3
#endif

// Pin Mapping for UART3_RTS_b signal
//   <o> UART3_RTS_b [PTB12, PTB8, PTC18, PTE7]<name=UART3_RTS_b_PIN_SEL>
//   <i> Shows which pin UART3_RTS_b is mapped to
//     <0=> Disabled
//     <1=> PTB12<selection=PTB12_SIG_SEL,UART3_RTS_b>
//     <2=> PTB8<selection=PTB8_SIG_SEL,UART3_RTS_b>
//     <3=> PTC18<selection=PTC18_SIG_SEL,UART3_RTS_b>
//     <4=> PTE7<selection=PTE7_SIG_SEL,UART3_RTS_b>
//     <0=> Default
#define UART3_RTS_b_PIN_SEL  0
#if UART3_RTS_b_PIN_SEL == 1
#define UART3_RTS_b_GPIO     digitalIO_PTB12
#define UART3_RTS_b_FN       2
#elif UART3_RTS_b_PIN_SEL == 2
#define UART3_RTS_b_GPIO     digitalIO_PTB8
#define UART3_RTS_b_FN       3
#elif UART3_RTS_b_PIN_SEL == 3
#define UART3_RTS_b_GPIO     digitalIO_PTC18
#define UART3_RTS_b_FN       3
#elif UART3_RTS_b_PIN_SEL == 4
#define UART3_RTS_b_GPIO     digitalIO_PTE7
#define UART3_RTS_b_FN       3
#endif

// Pin Mapping for UART3_RX signal
//   <o> UART3_RX [PTB10, PTC16, PTE5]<name=UART3_RX_PIN_SEL>
//   <i> Shows which pin UART3_RX is mapped to
//     <0=> Disabled
//     <1=> PTB10 (Alias:A2)<selection=PTB10_SIG_SEL,UART3_RX>
//     <2=> PTC16 (Alias:D0)<selection=PTC16_SIG_SEL,UART3_RX>
//     <3=> PTE5<selection=PTE5_SIG_SEL,UART3_RX>
//     <0=> Default
#define UART3_RX_PIN_SEL     0
#if UART3_RX_PIN_SEL == 1
#define UART3_RX_GPIO        digitalIO_PTB10
#define UART3_RX_FN          3
#elif UART3_RX_PIN_SEL == 2
#define UART3_RX_GPIO        digitalIO_PTC16
#define UART3_RX_FN          3
#elif UART3_RX_PIN_SEL == 3
#define UART3_RX_GPIO        digitalIO_PTE5
#define UART3_RX_FN          3
#endif

// Pin Mapping for UART3_TX signal
//   <o> UART3_TX [PTB11, PTC17, PTE4]<name=UART3_TX_PIN_SEL>
//   <i> Shows which pin UART3_TX is mapped to
//     <0=> Disabled
//     <1=> PTB11 (Alias:A3)<selection=PTB11_SIG_SEL,UART3_TX>
//     <2=> PTC17 (Alias:D1)<selection=PTC17_SIG_SEL,UART3_TX>
//     <3=> PTE4<selection=PTE4_SIG_SEL,UART3_TX>
//     <0=> Default
#define UART3_TX_PIN_SEL     0
#if UART3_TX_PIN_SEL == 1
#define UART3_TX_GPIO        digitalIO_PTB11
#define UART3_TX_FN          3
#elif UART3_TX_PIN_SEL == 2
#define UART3_TX_GPIO        digitalIO_PTC17
#define UART3_TX_FN          3
#elif UART3_TX_PIN_SEL == 3
#define UART3_TX_GPIO        digitalIO_PTE4
#define UART3_TX_FN          3
#endif

// </h>

// <h> Universal Asynchronous Rx/Tx (UART4)

// Pin Mapping for UART4_CTS_b signal
//   <o> UART4_CTS_b [PTC13, PTE26]<name=UART4_CTS_b_PIN_SEL>
//   <i> Shows which pin UART4_CTS_b is mapped to
//     <0=> Disabled
//     <1=> PTC13<selection=PTC13_SIG_SEL,UART4_CTS_b>
//     <2=> PTE26 (Alias:LED_GREEN)<selection=PTE26_SIG_SEL,UART4_CTS_b>
//     <0=> Default
#define UART4_CTS_b_PIN_SEL  0
#if UART4_CTS_b_PIN_SEL == 1
#define UART4_CTS_b_GPIO     digitalIO_PTC13
#define UART4_CTS_b_FN       3
#elif UART4_CTS_b_PIN_SEL == 2
#define UART4_CTS_b_GPIO     digitalIO_PTE26
#define UART4_CTS_b_FN       3
#endif

// Pin Mapping for UART4_RTS_b signal
//   <o> UART4_RTS_b [PTC12, PTE27]<name=UART4_RTS_b_PIN_SEL>
//   <i> Shows which pin UART4_RTS_b is mapped to
//     <0=> Disabled
//     <1=> PTC12<selection=PTC12_SIG_SEL,UART4_RTS_b>
//     <2=> PTE27<selection=PTE27_SIG_SEL,UART4_RTS_b>
//     <0=> Default
#define UART4_RTS_b_PIN_SEL  0
#if UART4_RTS_b_PIN_SEL == 1
#define UART4_RTS_b_GPIO     digitalIO_PTC12
#define UART4_RTS_b_FN       3
#elif UART4_RTS_b_PIN_SEL == 2
#define UART4_RTS_b_GPIO     digitalIO_PTE27
#define UART4_RTS_b_FN       3
#endif

// Pin Mapping for UART4_RX signal
//   <o> UART4_RX [PTC14, PTE25]<name=UART4_RX_PIN_SEL>
//   <i> Shows which pin UART4_RX is mapped to
//     <0=> Disabled
//     <1=> PTC14<selection=PTC14_SIG_SEL,UART4_RX>
//     <2=> PTE25 (Alias:D14)<selection=PTE25_SIG_SEL,UART4_RX>
//     <0=> Default
#define UART4_RX_PIN_SEL     0
#if UART4_RX_PIN_SEL == 1
#define UART4_RX_GPIO        digitalIO_PTC14
#define UART4_RX_FN          3
#elif UART4_RX_PIN_SEL == 2
#define UART4_RX_GPIO        digitalIO_PTE25
#define UART4_RX_FN          3
#endif

// Pin Mapping for UART4_TX signal
//   <o> UART4_TX [PTC15, PTE24]<name=UART4_TX_PIN_SEL>
//   <i> Shows which pin UART4_TX is mapped to
//     <0=> Disabled
//     <1=> PTC15<selection=PTC15_SIG_SEL,UART4_TX>
//     <2=> PTE24 (Alias:D15)<selection=PTE24_SIG_SEL,UART4_TX>
//     <0=> Default
#define UART4_TX_PIN_SEL     0
#if UART4_TX_PIN_SEL == 1
#define UART4_TX_GPIO        digitalIO_PTC15
#define UART4_TX_FN          3
#elif UART4_TX_PIN_SEL == 2
#define UART4_TX_GPIO        digitalIO_PTE24
#define UART4_TX_FN          3
#endif

// </h>

// <h> Universal Asynchronous Rx/Tx (UART5)

// Pin Mapping for UART5_CTS_b signal
//   <o> UART5_CTS_b [PTD11, PTE10]<name=UART5_CTS_b_PIN_SEL>
//   <i> Shows which pin UART5_CTS_b is mapped to
//     <0=> Disabled
//     <1=> PTD11<selection=PTD11_SIG_SEL,UART5_CTS_b>
//     <2=> PTE10<selection=PTE10_SIG_SEL,UART5_CTS_b>
//     <0=> Default
#define UART5_CTS_b_PIN_SEL  0
#if UART5_CTS_b_PIN_SEL == 1
#define UART5_CTS_b_GPIO     digitalIO_PTD11
#define UART5_CTS_b_FN       3
#elif UART5_CTS_b_PIN_SEL == 2
#define UART5_CTS_b_GPIO     digitalIO_PTE10
#define UART5_CTS_b_FN       3
#endif

// Pin Mapping for UART5_RTS_b signal
//   <o> UART5_RTS_b [PTD10, PTE11]<name=UART5_RTS_b_PIN_SEL>
//   <i> Shows which pin UART5_RTS_b is mapped to
//     <0=> Disabled
//     <1=> PTD10<selection=PTD10_SIG_SEL,UART5_RTS_b>
//     <2=> PTE11<selection=PTE11_SIG_SEL,UART5_RTS_b>
//     <0=> Default
#define UART5_RTS_b_PIN_SEL  0
#if UART5_RTS_b_PIN_SEL == 1
#define UART5_RTS_b_GPIO     digitalIO_PTD10
#define UART5_RTS_b_FN       3
#elif UART5_RTS_b_PIN_SEL == 2
#define UART5_RTS_b_GPIO     digitalIO_PTE11
#define UART5_RTS_b_FN       3
#endif

// Pin Mapping for UART5_RX signal
//   <o> UART5_RX [PTD8, PTE9]<name=UART5_RX_PIN_SEL>
//   <i> Shows which pin UART5_RX is mapped to
//     <0=> Disabled
//     <1=> PTD8<selection=PTD8_SIG_SEL,UART5_RX>
//     <2=> PTE9<selection=PTE9_SIG_SEL,UART5_RX>
//     <0=> Default
#define UART5_RX_PIN_SEL     0
#if UART5_RX_PIN_SEL == 1
#define UART5_RX_GPIO        digitalIO_PTD8
#define UART5_RX_FN          3
#elif UART5_RX_PIN_SEL == 2
#define UART5_RX_GPIO        digitalIO_PTE9
#define UART5_RX_FN          3
#endif

// Pin Mapping for UART5_TX signal
//   <o> UART5_TX [PTD9, PTE8]<name=UART5_TX_PIN_SEL>
//   <i> Shows which pin UART5_TX is mapped to
//     <0=> Disabled
//     <1=> PTD9<selection=PTD9_SIG_SEL,UART5_TX>
//     <2=> PTE8<selection=PTE8_SIG_SEL,UART5_TX>
//     <0=> Default
#define UART5_TX_PIN_SEL     0
#if UART5_TX_PIN_SEL == 1
#define UART5_TX_GPIO        digitalIO_PTD9
#define UART5_TX_FN          3
#elif UART5_TX_PIN_SEL == 2
#define UART5_TX_GPIO        digitalIO_PTE8
#define UART5_TX_FN          3
#endif

// </h>

// <h> Universal Serial Bus

// Pin Mapping for USB_CLKIN signal
//   <o> USB_CLKIN [PTA5, PTE26]<name=USB_CLKIN_PIN_SEL>
//   <i> Shows which pin USB_CLKIN is mapped to
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,USB_CLKIN>
//     <2=> PTE26 (Alias:LED_GREEN)<selection=PTE26_SIG_SEL,USB_CLKIN>
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
#define USB_SOF_OUT_FN       7
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

#define FIXED_ADC_FN             0                    // Fixed ADC Multiplexing value
#define FIXED_GPIO_FN            1                    // Fixed GPIO Multiplexing value
#define FIXED_PORT_CLOCK_REG     SCGC5                // Fixed PORT Clock
#define ADC0_CLOCK_REG       SCGC6
#define ADC0_CLOCK_MASK      SIM_SCGC6_ADC0_MASK
#define ADC1_CLOCK_REG       SCGC3
#define ADC1_CLOCK_MASK      SIM_SCGC3_ADC1_MASK
#define CMP_CLOCK_REG        SCGC4
#define CMP_CLOCK_MASK       SIM_SCGC4_CMP_MASK
#define CMT_CLOCK_REG        SCGC4
#define CMT_CLOCK_MASK       SIM_SCGC4_CMT_MASK
#define DAC0_CLOCK_REG       SCGC6
#define DAC0_CLOCK_MASK      SIM_SCGC6_DAC0_MASK
#define DAC1_CLOCK_REG       SCGC2
#define DAC1_CLOCK_MASK      SIM_SCGC2_DAC1_MASK
#define DMA_CLOCK_REG        SCGC7
#define DMA_CLOCK_MASK       SIM_SCGC7_DMA_MASK
#define DMAMUX_CLOCK_REG     SCGC6
#define DMAMUX_CLOCK_MASK    SIM_SCGC6_DMAMUX_MASK
#define ENET_CLOCK_REG       SCGC2
#define ENET_CLOCK_MASK      SIM_SCGC2_ENET_MASK
#define EWM_CLOCK_REG        SCGC4
#define EWM_CLOCK_MASK       SIM_SCGC4_EWM_MASK
#define FLEXBUS_CLOCK_REG    SCGC7
#define FLEXBUS_CLOCK_MASK   SIM_SCGC7_FLEXBUS_MASK
#define FLEXCAN_CLOCK_REG    SCGC6
#define FLEXCAN_CLOCK_MASK   SIM_SCGC6_FLEXCAN_MASK
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
#define RNGA_CLOCK_REG       SCGC6
#define RNGA_CLOCK_MASK      SIM_SCGC6_RNGA_MASK
#define RTC_CLOCK_REG        SCGC6
#define RTC_CLOCK_MASK       SIM_SCGC6_RTC_MASK
#define SDHC0_CLOCK_REG      SCGC3
#define SDHC0_CLOCK_MASK     SIM_SCGC3_SDHC0_MASK
#define SPI0_CLOCK_REG       SCGC6
#define SPI0_CLOCK_MASK      SIM_SCGC6_SPI0_MASK
#define SPI1_CLOCK_REG       SCGC6
#define SPI1_CLOCK_MASK      SIM_SCGC6_SPI1_MASK
#define SPI2_CLOCK_REG       SCGC3
#define SPI2_CLOCK_MASK      SIM_SCGC3_SPI2_MASK
#define UART0_CLOCK_REG      SCGC4
#define UART0_CLOCK_MASK     SIM_SCGC4_UART0_MASK
#define UART1_CLOCK_REG      SCGC4
#define UART1_CLOCK_MASK     SIM_SCGC4_UART1_MASK
#define UART2_CLOCK_REG      SCGC4
#define UART2_CLOCK_MASK     SIM_SCGC4_UART2_MASK
#define UART3_CLOCK_REG      SCGC4
#define UART3_CLOCK_MASK     SIM_SCGC4_UART3_MASK
#define UART4_CLOCK_REG      SCGC1
#define UART4_CLOCK_MASK     SIM_SCGC1_UART4_MASK
#define UART5_CLOCK_REG      SCGC1
#define UART5_CLOCK_MASK     SIM_SCGC1_UART5_MASK
#define USBDCD_CLOCK_REG     SCGC6
#define USBDCD_CLOCK_MASK    SIM_SCGC6_USBDCD_MASK
#define USBOTG_CLOCK_REG     SCGC4
#define USBOTG_CLOCK_MASK    SIM_SCGC4_USBOTG_MASK
#define VREF_CLOCK_REG       SCGC4
#define VREF_CLOCK_MASK      SIM_SCGC4_VREF_MASK
#define PORT_CLOCK_REG       SCGC5


#endif /* PIN_MAPPING_H_ */
