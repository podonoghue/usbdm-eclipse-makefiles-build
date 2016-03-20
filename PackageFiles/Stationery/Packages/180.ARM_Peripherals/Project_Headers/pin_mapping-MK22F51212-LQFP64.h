/**
 * @file      pin_mapping.h (derived from pin_mapping-MK22F51212-LQFP64.h)
 * @version   1.2.0
 * @brief     Pin declarations for MK22F51212-LQFP64, generated from MK22F51212.csv
 *            Devices   [MK22FN512M12, MK22FN256M12, MK22FN256M12]
 *            Reference [K22P121M120SF7RM, K22P121M120SF8RM, K22P121M120SF8RM]
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

// <h> Clock settings for FTM3

// FTM3_SC.CLKS ================================
//
//   <o>    FTM3_SC.CLKS Clock source
//   <i>    Selects the clock source for the FTM3 module. [FTM3_SC.CLKS]
//     <0=> Disabled
//     <1=> System clock
//     <2=> Fixed frequency clock
//     <3=> External clock
//     <1=> Default
// FTM3_SC.PS ================================
//
//   <o1>    FTM3_SC.PS Clock prescaler
//   <i>    Selects the prescaler for the FTM3 module. [FTM3_SC.PS]
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
//   <o>    ADC0_DM0<name=ADC0_DM0_SIG_SEL><constant>
//   <i>    ADC0_DM0 has no pin-mapping hardware
//   <info> ADC0_DM0/ADC1_DM3/ADC0_SE19
//     <-3=> ADC0_DM0/ADC1_DM3/ADC0_SE19 (fixed)<selection=ADC0_DM0_PIN_SEL,ADC0_DM0><selection=ADC1_DM3_PIN_SEL,ADC0_DM0><selection=ADC0_SE19_PIN_SEL,ADC0_DM0>
#define ADC0_DM0_SIG_SEL     -3

// Signal mapping for ADC0_DM1 pin
//   <o>    ADC0_DM1<name=ADC0_DM1_SIG_SEL><constant>
//   <i>    ADC0_DM1 has no pin-mapping hardware
//   <info> ADC0_DM1
//     <-3=> ADC0_DM1 (fixed)<selection=ADC0_DM1_PIN_SEL,ADC0_DM1>
#define ADC0_DM1_SIG_SEL     -3

// Signal mapping for ADC0_DP0 pin
//   <o>    ADC0_DP0<name=ADC0_DP0_SIG_SEL><constant>
//   <i>    ADC0_DP0 has no pin-mapping hardware
//   <info> ADC0_DP0/ADC1_DP3/ADC0_SE0
//     <-3=> ADC0_DP0/ADC1_DP3/ADC0_SE0 (fixed)<selection=ADC0_DP0_PIN_SEL,ADC0_DP0><selection=ADC1_DP3_PIN_SEL,ADC0_DP0><selection=ADC0_SE0_PIN_SEL,ADC0_DP0>
#define ADC0_DP0_SIG_SEL     -3

// Signal mapping for ADC0_DP1 pin
//   <o>    ADC0_DP1<name=ADC0_DP1_SIG_SEL><constant>
//   <i>    ADC0_DP1 has no pin-mapping hardware
//   <info> ADC0_DP1
//     <-3=> ADC0_DP1 (fixed)<selection=ADC0_DP1_PIN_SEL,ADC0_DP1>
#define ADC0_DP1_SIG_SEL     -3

// Signal mapping for ADC0_SE16 pin
//   <o>    ADC0_SE16<name=ADC0_SE16_SIG_SEL><constant>
//   <i>    ADC0_SE16 has no pin-mapping hardware
//   <info> ADC0_SE16/CMP1_IN2/ADC0_SE21
//     <-3=> ADC0_SE16/CMP1_IN2/ADC0_SE21 (fixed)<selection=ADC0_SE16_PIN_SEL,ADC0_SE16><selection=CMP1_IN2_PIN_SEL,ADC0_SE16><selection=ADC0_SE21_PIN_SEL,ADC0_SE16>
#define ADC0_SE16_SIG_SEL    -3

// Signal mapping for ADC1_DM0 pin
//   <o>    ADC1_DM0<name=ADC1_DM0_SIG_SEL><constant>
//   <i>    ADC1_DM0 has no pin-mapping hardware
//   <info> ADC1_DM0/ADC0_DM3/ADC1_SE19
//     <-3=> ADC1_DM0/ADC0_DM3/ADC1_SE19 (fixed)<selection=ADC1_DM0_PIN_SEL,ADC1_DM0><selection=ADC0_DM3_PIN_SEL,ADC1_DM0><selection=ADC1_SE19_PIN_SEL,ADC1_DM0>
#define ADC1_DM0_SIG_SEL     -3

// Signal mapping for ADC1_DM1 pin
//   <o>    ADC1_DM1<name=ADC1_DM1_SIG_SEL><constant>
//   <i>    ADC1_DM1 has no pin-mapping hardware
//   <info> ADC1_DM1/ADC0_DM2
//     <-3=> ADC1_DM1/ADC0_DM2 (fixed)<selection=ADC1_DM1_PIN_SEL,ADC1_DM1><selection=ADC0_DM2_PIN_SEL,ADC1_DM1>
#define ADC1_DM1_SIG_SEL     -3

// Signal mapping for ADC1_DP0 pin
//   <o>    ADC1_DP0<name=ADC1_DP0_SIG_SEL><constant>
//   <i>    ADC1_DP0 has no pin-mapping hardware
//   <info> ADC1_DP0/ADC0_DP3/ADC1_SE0/ADC0_SE3
//     <-3=> ADC1_DP0/ADC0_DP3/ADC1_SE0/ADC0_SE3 (fixed)<selection=ADC1_DP0_PIN_SEL,ADC1_DP0><selection=ADC0_DP3_PIN_SEL,ADC1_DP0><selection=ADC1_SE0_PIN_SEL,ADC1_DP0><selection=ADC0_SE3_PIN_SEL,ADC1_DP0>
#define ADC1_DP0_SIG_SEL     -3

// Signal mapping for ADC1_DP1 pin
//   <o>    ADC1_DP1<name=ADC1_DP1_SIG_SEL><constant>
//   <i>    ADC1_DP1 has no pin-mapping hardware
//   <info> ADC1_DP1/ADC0_DP2
//     <-3=> ADC1_DP1/ADC0_DP2 (fixed)<selection=ADC1_DP1_PIN_SEL,ADC1_DP1><selection=ADC0_DP2_PIN_SEL,ADC1_DP1>
#define ADC1_DP1_SIG_SEL     -3

// Signal mapping for ADC1_SE16 pin
//   <o>    ADC1_SE16<name=ADC1_SE16_SIG_SEL><constant>
//   <i>    ADC1_SE16 has no pin-mapping hardware
//   <info> ADC1_SE16/ADC0_SE22
//     <-3=> ADC1_SE16/ADC0_SE22 (fixed)<selection=ADC1_SE16_PIN_SEL,ADC1_SE16><selection=ADC0_SE22_PIN_SEL,ADC1_SE16>
#define ADC1_SE16_SIG_SEL    -3

// Signal mapping for DAC0_OUT pin
//   <o>    DAC0_OUT<name=DAC0_OUT_SIG_SEL><constant>
//   <i>    DAC0_OUT has no pin-mapping hardware
//   <info> DAC0_OUT/CMP1_IN3/ADC0_SE23
//     <-3=> DAC0_OUT/CMP1_IN3/ADC0_SE23 (fixed)<selection=DAC0_OUT_PIN_SEL,DAC0_OUT><selection=CMP1_IN3_PIN_SEL,DAC0_OUT><selection=ADC0_SE23_PIN_SEL,DAC0_OUT>
#define DAC0_OUT_SIG_SEL     -3

// Signal mapping for DAC1_OUT pin
//   <o>    DAC1_OUT<name=DAC1_OUT_SIG_SEL><constant>
//   <i>    DAC1_OUT has no pin-mapping hardware
//   <info> DAC1_OUT/CMP0_IN4/ADC1_SE23
//     <-3=> DAC1_OUT/CMP0_IN4/ADC1_SE23 (fixed)<selection=DAC1_OUT_PIN_SEL,DAC1_OUT><selection=CMP0_IN4_PIN_SEL,DAC1_OUT><selection=ADC1_SE23_PIN_SEL,DAC1_OUT>
#define DAC1_OUT_SIG_SEL     -3

// Signal mapping for RESET_b pin
//   <o>    RESET_b<name=RESET_b_SIG_SEL><constant>
//   <i>    RESET_b has no pin-mapping hardware
//   <info> RESET_b
//     <-3=> RESET_b (fixed)<selection=RESET_b_PIN_SEL,RESET_b>
#define RESET_b_SIG_SEL      -3

// Signal mapping for RTC_WAKEUP_B pin
//   <o>    RTC_WAKEUP_B<name=RTC_WAKEUP_B_SIG_SEL><constant>
//   <i>    RTC_WAKEUP_B has no pin-mapping hardware
//   <info> RTC_WAKEUP_B
//     <-3=> RTC_WAKEUP_B (fixed)<selection=RTC_WAKEUP_B_PIN_SEL,RTC_WAKEUP_B>
#define RTC_WAKEUP_B_SIG_SEL -3

// Signal mapping for VREF_OUT pin
//   <o>    VREF_OUT<name=VREF_OUT_SIG_SEL><constant>
//   <i>    VREF_OUT has no pin-mapping hardware
//   <info> VREF_OUT/CMP1_IN5/CMP0_IN5/ADC1_SE18
//     <-3=> VREF_OUT/CMP1_IN5/CMP0_IN5/ADC1_SE18 (fixed)<selection=VREF_OUT_PIN_SEL,VREF_OUT><selection=CMP1_IN5_PIN_SEL,VREF_OUT><selection=CMP0_IN5_PIN_SEL,VREF_OUT><selection=ADC1_SE18_PIN_SEL,VREF_OUT>
#define VREF_OUT_SIG_SEL     -3

// </h>

// <h> Port A Pins

// Signal mapping for PTA0 pin
//   <o>    PTA0<name=PTA0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA0 pin
//   <info> GPIOA_0, UART0_CTS_b, FTM0_CH5, JTAG_TCLK/SWD_CLK
//     <-2=> JTAG_TCLK/SWD_CLK (reset default)<selection=JTAG_TCLK_PIN_SEL,PTA0 (reset default)><selection=SWD_CLK_PIN_SEL,PTA0 (reset default)>
//     <1=> GPIOA_0<selection=GPIOA_0_PIN_SEL,PTA0>
//     <2=> UART0_CTS_b<selection=UART0_CTS_b_PIN_SEL,PTA0>
//     <3=> FTM0_CH5<selection=FTM0_CH5_PIN_SEL,PTA0>
//     <7=> JTAG_TCLK/SWD_CLK<selection=JTAG_TCLK_PIN_SEL,PTA0><selection=SWD_CLK_PIN_SEL,PTA0>
//     <-2=> Default
#define PTA0_SIG_SEL         -2

// Signal mapping for PTA1 pin
//   <o>    PTA1<name=PTA1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA1 pin
//   <info> GPIOA_1, UART0_RX, FTM0_CH6, JTAG_TDI
//     <-2=> JTAG_TDI (reset default)<selection=JTAG_TDI_PIN_SEL,PTA1 (reset default)>
//     <1=> GPIOA_1<selection=GPIOA_1_PIN_SEL,PTA1>
//     <2=> UART0_RX<selection=UART0_RX_PIN_SEL,PTA1>
//     <3=> FTM0_CH6<selection=FTM0_CH6_PIN_SEL,PTA1>
//     <7=> JTAG_TDI<selection=JTAG_TDI_PIN_SEL,PTA1>
//     <3=> Default
#define PTA1_SIG_SEL         3

// Signal mapping for PTA2 pin
//   <o>    PTA2<name=PTA2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA2 pin
//   <info> GPIOA_2, UART0_TX, FTM0_CH7, JTAG_TDO/TRACE_SWO
//     <-2=> JTAG_TDO/TRACE_SWO (reset default)<selection=JTAG_TDO_PIN_SEL,PTA2 (reset default)><selection=TRACE_SWO_PIN_SEL,PTA2 (reset default)>
//     <1=> GPIOA_2<selection=GPIOA_2_PIN_SEL,PTA2>
//     <2=> UART0_TX<selection=UART0_TX_PIN_SEL,PTA2>
//     <3=> FTM0_CH7<selection=FTM0_CH7_PIN_SEL,PTA2>
//     <7=> JTAG_TDO/TRACE_SWO<selection=JTAG_TDO_PIN_SEL,PTA2><selection=TRACE_SWO_PIN_SEL,PTA2>
//     <3=> Default
#define PTA2_SIG_SEL         3

// Signal mapping for PTA3 pin
//   <o>    PTA3<name=PTA3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA3 pin
//   <info> GPIOA_3, UART0_RTS_b, FTM0_CH0, JTAG_TMS/SWD_DIO
//     <-2=> JTAG_TMS/SWD_DIO (reset default)<selection=JTAG_TMS_PIN_SEL,PTA3 (reset default)><selection=SWD_DIO_PIN_SEL,PTA3 (reset default)>
//     <1=> GPIOA_3<selection=GPIOA_3_PIN_SEL,PTA3>
//     <2=> UART0_RTS_b<selection=UART0_RTS_b_PIN_SEL,PTA3>
//     <3=> FTM0_CH0<selection=FTM0_CH0_PIN_SEL,PTA3>
//     <7=> JTAG_TMS/SWD_DIO<selection=JTAG_TMS_PIN_SEL,PTA3><selection=SWD_DIO_PIN_SEL,PTA3>
//     <-2=> Default
#define PTA3_SIG_SEL         -2

// Signal mapping for PTA4 pin
//   <o>    PTA4<name=PTA4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA4 pin
//   <info> GPIOA_4/LLWU_P3, FTM0_CH1, NMI_b
//     <-2=> NMI_b (reset default)<selection=NMI_b_PIN_SEL,PTA4 (reset default)>
//     <1=> GPIOA_4/LLWU_P3<selection=GPIOA_4_PIN_SEL,PTA4><selection=LLWU_P3_PIN_SEL,PTA4>
//     <3=> FTM0_CH1<selection=FTM0_CH1_PIN_SEL,PTA4>
//     <7=> NMI_b<selection=NMI_b_PIN_SEL,PTA4>
//     <3=> Default
#define PTA4_SIG_SEL         3

// Signal mapping for PTA5 pin
//   <o>    PTA5<name=PTA5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA5 pin
//   <info> GPIOA_5, USB_CLKIN, FTM0_CH2, I2S0_TX_BCLK, JTAG_TRST_b
//     <-2=> JTAG_TRST_b (reset default)<selection=JTAG_TRST_b_PIN_SEL,PTA5 (reset default)>
//     <1=> GPIOA_5<selection=GPIOA_5_PIN_SEL,PTA5>
//     <2=> USB_CLKIN<selection=USB_CLKIN_PIN_SEL,PTA5>
//     <3=> FTM0_CH2<selection=FTM0_CH2_PIN_SEL,PTA5>
//     <6=> I2S0_TX_BCLK<selection=I2S0_TX_BCLK_PIN_SEL,PTA5>
//     <7=> JTAG_TRST_b<selection=JTAG_TRST_b_PIN_SEL,PTA5>
//     <1=> Default
#define PTA5_SIG_SEL         1

// Signal mapping for PTA10 pin
//   <o>    PTA10<name=PTA10_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA10 pin
//   <info> GPIOA_10, FTM2_CH0, FTM2_QD_PHA
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_10<selection=GPIOA_10_PIN_SEL,PTA10>
//     <3=> FTM2_CH0<selection=FTM2_CH0_PIN_SEL,PTA10>
//     <6=> FTM2_QD_PHA<selection=FTM2_QD_PHA_PIN_SEL,PTA10>
//     <-2=> Default
#define PTA10_SIG_SEL        -2

// Signal mapping for PTA11 pin
//   <o>    PTA11<name=PTA11_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA11 pin
//   <info> GPIOA_11, FTM2_CH1, FTM2_QD_PHB
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_11<selection=GPIOA_11_PIN_SEL,PTA11>
//     <3=> FTM2_CH1<selection=FTM2_CH1_PIN_SEL,PTA11>
//     <6=> FTM2_QD_PHB<selection=FTM2_QD_PHB_PIN_SEL,PTA11>
//     <-2=> Default
#define PTA11_SIG_SEL        -2

// Signal mapping for PTA12 pin
//   <o>    PTA12<name=PTA12_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA12 pin
//   <info> GPIOA_12, FTM1_CH0, I2S0_TXD0, FTM1_QD_PHA
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_12<selection=GPIOA_12_PIN_SEL,PTA12>
//     <3=> FTM1_CH0<selection=FTM1_CH0_PIN_SEL,PTA12>
//     <6=> I2S0_TXD0<selection=I2S0_TXD0_PIN_SEL,PTA12>
//     <7=> FTM1_QD_PHA<selection=FTM1_QD_PHA_PIN_SEL,PTA12>
//     <-2=> Default
#define PTA12_SIG_SEL        -2

// Signal mapping for PTA13 pin
//   <o>    PTA13<name=PTA13_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA13 pin
//   <info> GPIOA_13/LLWU_P4, FTM1_CH1, I2S0_TX_FS, FTM1_QD_PHB
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_13/LLWU_P4<selection=GPIOA_13_PIN_SEL,PTA13><selection=LLWU_P4_PIN_SEL,PTA13>
//     <3=> FTM1_CH1<selection=FTM1_CH1_PIN_SEL,PTA13>
//     <6=> I2S0_TX_FS<selection=I2S0_TX_FS_PIN_SEL,PTA13>
//     <7=> FTM1_QD_PHB<selection=FTM1_QD_PHB_PIN_SEL,PTA13>
//     <-2=> Default
#define PTA13_SIG_SEL        -2

// Signal mapping for PTA14 pin
//   <o>    PTA14<name=PTA14_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA14 pin
//   <info> GPIOA_14, SPI0_PCS0, UART0_TX, I2S0_RX_BCLK
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_14<selection=GPIOA_14_PIN_SEL,PTA14>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTA14>
//     <3=> UART0_TX<selection=UART0_TX_PIN_SEL,PTA14>
//     <6=> I2S0_RX_BCLK<selection=I2S0_RX_BCLK_PIN_SEL,PTA14>
//     <-2=> Default
#define PTA14_SIG_SEL        -2

// Signal mapping for PTA15 pin
//   <o>    PTA15<name=PTA15_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA15 pin
//   <info> GPIOA_15, SPI0_SCK, UART0_RX, I2S0_RXD0
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_15<selection=GPIOA_15_PIN_SEL,PTA15>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTA15>
//     <3=> UART0_RX<selection=UART0_RX_PIN_SEL,PTA15>
//     <6=> I2S0_RXD0<selection=I2S0_RXD0_PIN_SEL,PTA15>
//     <-2=> Default
#define PTA15_SIG_SEL        -2

// Signal mapping for PTA16 pin
//   <o>    PTA16<name=PTA16_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA16 pin
//   <info> GPIOA_16, SPI0_SOUT, UART0_CTS_b, I2S0_RX_FS
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_16<selection=GPIOA_16_PIN_SEL,PTA16>
//     <2=> SPI0_SOUT<selection=SPI0_SOUT_PIN_SEL,PTA16>
//     <3=> UART0_CTS_b<selection=UART0_CTS_b_PIN_SEL,PTA16>
//     <6=> I2S0_RX_FS<selection=I2S0_RX_FS_PIN_SEL,PTA16>
//     <-2=> Default
#define PTA16_SIG_SEL        -2

// Signal mapping for PTA17 pin
//   <o>    PTA17<name=PTA17_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA17 pin
//   <info> ADC1_SE17, GPIOA_17, SPI0_SIN, UART0_RTS_b, I2S0_MCLK
//     <-2=> ADC1_SE17 (reset default)<selection=ADC1_SE17_PIN_SEL,PTA17 (reset default)>
//     <0=> ADC1_SE17<selection=ADC1_SE17_PIN_SEL,PTA17>
//     <1=> GPIOA_17<selection=GPIOA_17_PIN_SEL,PTA17>
//     <2=> SPI0_SIN<selection=SPI0_SIN_PIN_SEL,PTA17>
//     <3=> UART0_RTS_b<selection=UART0_RTS_b_PIN_SEL,PTA17>
//     <6=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTA17>
//     <-2=> Default
#define PTA17_SIG_SEL        -2

// Signal mapping for PTA18 pin
//   <o>    PTA18<name=PTA18_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA18 pin
//   <info> EXTAL0, GPIOA_18, FTM0_FLT2, FTM_CLKIN0
//     <-2=> EXTAL0 (reset default)<selection=EXTAL0_PIN_SEL,PTA18 (reset default)>
//     <0=> EXTAL0<selection=EXTAL0_PIN_SEL,PTA18>
//     <1=> GPIOA_18<selection=GPIOA_18_PIN_SEL,PTA18>
//     <3=> FTM0_FLT2<selection=FTM0_FLT2_PIN_SEL,PTA18>
//     <4=> FTM_CLKIN0<selection=FTM_CLKIN0_PIN_SEL,PTA18>
//     <0=> Default
#define PTA18_SIG_SEL        0

// Signal mapping for PTA19 pin
//   <o>    PTA19<name=PTA19_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA19 pin
//   <info> XTAL0, GPIOA_19, FTM1_FLT0, FTM_CLKIN1, LPTMR0_ALT1
//     <-2=> XTAL0 (reset default)<selection=XTAL0_PIN_SEL,PTA19 (reset default)>
//     <0=> XTAL0<selection=XTAL0_PIN_SEL,PTA19>
//     <1=> GPIOA_19<selection=GPIOA_19_PIN_SEL,PTA19>
//     <3=> FTM1_FLT0<selection=FTM1_FLT0_PIN_SEL,PTA19>
//     <4=> FTM_CLKIN1<selection=FTM_CLKIN1_PIN_SEL,PTA19>
//     <6=> LPTMR0_ALT1<selection=LPTMR0_ALT1_PIN_SEL,PTA19>
//     <0=> Default
#define PTA19_SIG_SEL        0

// Signal mapping for PTA29 pin
//   <o>    PTA29<name=PTA29_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTA29 pin
//   <info> GPIOA_29, FB_A24
//     <-2=> Disabled (reset default)
//     <1=> GPIOA_29<selection=GPIOA_29_PIN_SEL,PTA29>
//     <6=> FB_A24<selection=FB_A24_PIN_SEL,PTA29>
//     <-2=> Default
#define PTA29_SIG_SEL        -2

// </h>

// <h> Port B Pins

// Signal mapping for PTB0 pin
//   <o>    PTB0<name=PTB0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB0 pin
//   <info> ADC0_SE8/ADC1_SE8, GPIOB_0/LLWU_P5, I2C0_SCL, FTM1_CH0, FTM1_QD_PHA
//     <-2=> ADC0_SE8/ADC1_SE8 (reset default)<selection=ADC0_SE8_PIN_SEL,PTB0 (reset default)><selection=ADC1_SE8_PIN_SEL,PTB0 (reset default)>
//     <0=> ADC0_SE8/ADC1_SE8<selection=ADC0_SE8_PIN_SEL,PTB0><selection=ADC1_SE8_PIN_SEL,PTB0>
//     <1=> GPIOB_0/LLWU_P5<selection=GPIOB_0_PIN_SEL,PTB0><selection=LLWU_P5_PIN_SEL,PTB0>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTB0>
//     <3=> FTM1_CH0<selection=FTM1_CH0_PIN_SEL,PTB0>
//     <6=> FTM1_QD_PHA<selection=FTM1_QD_PHA_PIN_SEL,PTB0>
//     <0=> Default
#define PTB0_SIG_SEL         0

// Signal mapping for PTB1 pin
//   <o>    PTB1<name=PTB1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB1 pin
//   <info> ADC0_SE9/ADC1_SE9, GPIOB_1, I2C0_SDA, FTM1_CH1, FTM1_QD_PHB
//     <-2=> ADC0_SE9/ADC1_SE9 (reset default)<selection=ADC0_SE9_PIN_SEL,PTB1 (reset default)><selection=ADC1_SE9_PIN_SEL,PTB1 (reset default)>
//     <0=> ADC0_SE9/ADC1_SE9<selection=ADC0_SE9_PIN_SEL,PTB1><selection=ADC1_SE9_PIN_SEL,PTB1>
//     <1=> GPIOB_1<selection=GPIOB_1_PIN_SEL,PTB1>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTB1>
//     <3=> FTM1_CH1<selection=FTM1_CH1_PIN_SEL,PTB1>
//     <6=> FTM1_QD_PHB<selection=FTM1_QD_PHB_PIN_SEL,PTB1>
//     <0=> Default
#define PTB1_SIG_SEL         0

// Signal mapping for PTB2 pin
//   <o>    PTB2<name=PTB2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB2 pin
//   <info> ADC0_SE12, GPIOB_2, I2C0_SCL, UART0_RTS_b, FTM0_FLT3
//     <-2=> ADC0_SE12 (reset default)<selection=ADC0_SE12_PIN_SEL,PTB2 (reset default)>
//     <0=> ADC0_SE12<selection=ADC0_SE12_PIN_SEL,PTB2>
//     <1=> GPIOB_2<selection=GPIOB_2_PIN_SEL,PTB2>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTB2>
//     <3=> UART0_RTS_b<selection=UART0_RTS_b_PIN_SEL,PTB2>
//     <6=> FTM0_FLT3<selection=FTM0_FLT3_PIN_SEL,PTB2>
//     <0=> Default
#define PTB2_SIG_SEL         0

// Signal mapping for PTB3 pin
//   <o>    PTB3<name=PTB3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB3 pin
//   <info> ADC0_SE13, GPIOB_3, I2C0_SDA, UART0_CTS_b, FTM0_FLT0
//     <-2=> ADC0_SE13 (reset default)<selection=ADC0_SE13_PIN_SEL,PTB3 (reset default)>
//     <0=> ADC0_SE13<selection=ADC0_SE13_PIN_SEL,PTB3>
//     <1=> GPIOB_3<selection=GPIOB_3_PIN_SEL,PTB3>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTB3>
//     <3=> UART0_CTS_b<selection=UART0_CTS_b_PIN_SEL,PTB3>
//     <6=> FTM0_FLT0<selection=FTM0_FLT0_PIN_SEL,PTB3>
//     <0=> Default
#define PTB3_SIG_SEL         0

// Signal mapping for PTB6 pin
//   <o>    PTB6<name=PTB6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB6 pin
//   <info> ADC1_SE12, GPIOB_6, FB_AD23
//     <-2=> ADC1_SE12 (reset default)<selection=ADC1_SE12_PIN_SEL,PTB6 (reset default)>
//     <0=> ADC1_SE12<selection=ADC1_SE12_PIN_SEL,PTB6>
//     <1=> GPIOB_6<selection=GPIOB_6_PIN_SEL,PTB6>
//     <5=> FB_AD23<selection=FB_AD23_PIN_SEL,PTB6>
//     <-2=> Default
#define PTB6_SIG_SEL         -2

// Signal mapping for PTB7 pin
//   <o>    PTB7<name=PTB7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB7 pin
//   <info> ADC1_SE13, GPIOB_7, FB_AD22
//     <-2=> ADC1_SE13 (reset default)<selection=ADC1_SE13_PIN_SEL,PTB7 (reset default)>
//     <0=> ADC1_SE13<selection=ADC1_SE13_PIN_SEL,PTB7>
//     <1=> GPIOB_7<selection=GPIOB_7_PIN_SEL,PTB7>
//     <5=> FB_AD22<selection=FB_AD22_PIN_SEL,PTB7>
//     <-2=> Default
#define PTB7_SIG_SEL         -2

// Signal mapping for PTB8 pin
//   <o>    PTB8<name=PTB8_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB8 pin
//   <info> GPIOB_8, LPUART0_RTS_b, FB_AD21
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_8<selection=GPIOB_8_PIN_SEL,PTB8>
//     <3=> LPUART0_RTS_b<selection=LPUART0_RTS_b_PIN_SEL,PTB8>
//     <5=> FB_AD21<selection=FB_AD21_PIN_SEL,PTB8>
//     <-2=> Default
#define PTB8_SIG_SEL         -2

// Signal mapping for PTB9 pin
//   <o>    PTB9<name=PTB9_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB9 pin
//   <info> GPIOB_9, SPI1_PCS1, LPUART0_CTS_b, FB_AD20
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_9<selection=GPIOB_9_PIN_SEL,PTB9>
//     <2=> SPI1_PCS1<selection=SPI1_PCS1_PIN_SEL,PTB9>
//     <3=> LPUART0_CTS_b<selection=LPUART0_CTS_b_PIN_SEL,PTB9>
//     <5=> FB_AD20<selection=FB_AD20_PIN_SEL,PTB9>
//     <-2=> Default
#define PTB9_SIG_SEL         -2

// Signal mapping for PTB10 pin
//   <o>    PTB10<name=PTB10_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB10 pin
//   <info> ADC1_SE14, GPIOB_10, SPI1_PCS0, LPUART0_RX, FB_AD19, FTM0_FLT1
//     <-2=> ADC1_SE14 (reset default)<selection=ADC1_SE14_PIN_SEL,PTB10 (reset default)>
//     <0=> ADC1_SE14<selection=ADC1_SE14_PIN_SEL,PTB10>
//     <1=> GPIOB_10<selection=GPIOB_10_PIN_SEL,PTB10>
//     <2=> SPI1_PCS0<selection=SPI1_PCS0_PIN_SEL,PTB10>
//     <3=> LPUART0_RX<selection=LPUART0_RX_PIN_SEL,PTB10>
//     <5=> FB_AD19<selection=FB_AD19_PIN_SEL,PTB10>
//     <6=> FTM0_FLT1<selection=FTM0_FLT1_PIN_SEL,PTB10>
//     <-2=> Default
#define PTB10_SIG_SEL        -2

// Signal mapping for PTB11 pin
//   <o>    PTB11<name=PTB11_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB11 pin
//   <info> ADC1_SE15, GPIOB_11, SPI1_SCK, LPUART0_TX, FB_AD18, FTM0_FLT2
//     <-2=> ADC1_SE15 (reset default)<selection=ADC1_SE15_PIN_SEL,PTB11 (reset default)>
//     <0=> ADC1_SE15<selection=ADC1_SE15_PIN_SEL,PTB11>
//     <1=> GPIOB_11<selection=GPIOB_11_PIN_SEL,PTB11>
//     <2=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTB11>
//     <3=> LPUART0_TX<selection=LPUART0_TX_PIN_SEL,PTB11>
//     <5=> FB_AD18<selection=FB_AD18_PIN_SEL,PTB11>
//     <6=> FTM0_FLT2<selection=FTM0_FLT2_PIN_SEL,PTB11>
//     <-2=> Default
#define PTB11_SIG_SEL        -2

// Signal mapping for PTB16 pin
//   <o>    PTB16<name=PTB16_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB16 pin
//   <info> GPIOB_16, SPI1_SOUT, UART0_RX, FTM_CLKIN0, FB_AD17, EWM_IN
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_16<selection=GPIOB_16_PIN_SEL,PTB16>
//     <2=> SPI1_SOUT<selection=SPI1_SOUT_PIN_SEL,PTB16>
//     <3=> UART0_RX<selection=UART0_RX_PIN_SEL,PTB16>
//     <4=> FTM_CLKIN0<selection=FTM_CLKIN0_PIN_SEL,PTB16>
//     <5=> FB_AD17<selection=FB_AD17_PIN_SEL,PTB16>
//     <6=> EWM_IN<selection=EWM_IN_PIN_SEL,PTB16>
//     <1=> Default
#define PTB16_SIG_SEL        1

// Signal mapping for PTB17 pin
//   <o>    PTB17<name=PTB17_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB17 pin
//   <info> GPIOB_17, SPI1_SIN, UART0_TX, FTM_CLKIN1, FB_AD16, EWM_OUT_b
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
//   <o>    PTB18<name=PTB18_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB18 pin
//   <info> GPIOB_18, FTM2_CH0, I2S0_TX_BCLK, FB_AD15, FTM2_QD_PHA
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_18<selection=GPIOB_18_PIN_SEL,PTB18>
//     <3=> FTM2_CH0<selection=FTM2_CH0_PIN_SEL,PTB18>
//     <4=> I2S0_TX_BCLK<selection=I2S0_TX_BCLK_PIN_SEL,PTB18>
//     <5=> FB_AD15<selection=FB_AD15_PIN_SEL,PTB18>
//     <6=> FTM2_QD_PHA<selection=FTM2_QD_PHA_PIN_SEL,PTB18>
//     <1=> Default
#define PTB18_SIG_SEL        1

// Signal mapping for PTB19 pin
//   <o>    PTB19<name=PTB19_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB19 pin
//   <info> GPIOB_19, FTM2_CH1, I2S0_TX_FS, FB_OE_b, FTM2_QD_PHB
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_19<selection=GPIOB_19_PIN_SEL,PTB19>
//     <3=> FTM2_CH1<selection=FTM2_CH1_PIN_SEL,PTB19>
//     <4=> I2S0_TX_FS<selection=I2S0_TX_FS_PIN_SEL,PTB19>
//     <5=> FB_OE_b<selection=FB_OE_b_PIN_SEL,PTB19>
//     <6=> FTM2_QD_PHB<selection=FTM2_QD_PHB_PIN_SEL,PTB19>
//     <1=> Default
#define PTB19_SIG_SEL        1

// Signal mapping for PTB20 pin
//   <o>    PTB20<name=PTB20_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB20 pin
//   <info> GPIOB_20, FB_AD31, CMP0_OUT
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_20<selection=GPIOB_20_PIN_SEL,PTB20>
//     <5=> FB_AD31<selection=FB_AD31_PIN_SEL,PTB20>
//     <6=> CMP0_OUT<selection=CMP0_OUT_PIN_SEL,PTB20>
//     <-2=> Default
#define PTB20_SIG_SEL        -2

// Signal mapping for PTB21 pin
//   <o>    PTB21<name=PTB21_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB21 pin
//   <info> GPIOB_21, FB_AD30, CMP1_OUT
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_21<selection=GPIOB_21_PIN_SEL,PTB21>
//     <5=> FB_AD30<selection=FB_AD30_PIN_SEL,PTB21>
//     <6=> CMP1_OUT<selection=CMP1_OUT_PIN_SEL,PTB21>
//     <-2=> Default
#define PTB21_SIG_SEL        -2

// Signal mapping for PTB22 pin
//   <o>    PTB22<name=PTB22_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB22 pin
//   <info> GPIOB_22, FB_AD29
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_22<selection=GPIOB_22_PIN_SEL,PTB22>
//     <5=> FB_AD29<selection=FB_AD29_PIN_SEL,PTB22>
//     <-2=> Default
#define PTB22_SIG_SEL        -2

// Signal mapping for PTB23 pin
//   <o>    PTB23<name=PTB23_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTB23 pin
//   <info> GPIOB_23, SPI0_PCS5, FB_AD28
//     <-2=> Disabled (reset default)
//     <1=> GPIOB_23<selection=GPIOB_23_PIN_SEL,PTB23>
//     <3=> SPI0_PCS5<selection=SPI0_PCS5_PIN_SEL,PTB23>
//     <5=> FB_AD28<selection=FB_AD28_PIN_SEL,PTB23>
//     <-2=> Default
#define PTB23_SIG_SEL        -2

// </h>

// <h> Port C Pins

// Signal mapping for PTC0 pin
//   <o>    PTC0<name=PTC0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC0 pin
//   <info> ADC0_SE14, GPIOC_0, SPI0_PCS4, PDB0_EXTRG, USB_SOF_OUT, FB_AD14
//     <-2=> ADC0_SE14 (reset default)<selection=ADC0_SE14_PIN_SEL,PTC0 (reset default)>
//     <0=> ADC0_SE14<selection=ADC0_SE14_PIN_SEL,PTC0>
//     <1=> GPIOC_0<selection=GPIOC_0_PIN_SEL,PTC0>
//     <2=> SPI0_PCS4<selection=SPI0_PCS4_PIN_SEL,PTC0>
//     <3=> PDB0_EXTRG<selection=PDB0_EXTRG_PIN_SEL,PTC0>
//     <4=> USB_SOF_OUT<selection=USB_SOF_OUT_PIN_SEL,PTC0>
//     <5=> FB_AD14<selection=FB_AD14_PIN_SEL,PTC0>
//     <-2=> Default
#define PTC0_SIG_SEL         -2

// Signal mapping for PTC1 pin
//   <o>    PTC1<name=PTC1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC1 pin
//   <info> ADC0_SE15, GPIOC_1/LLWU_P6, SPI0_PCS3, UART1_RTS_b, FTM0_CH0, FB_AD13, I2S0_TXD0, LPUART0_RTS_b
//     <-2=> ADC0_SE15 (reset default)<selection=ADC0_SE15_PIN_SEL,PTC1 (reset default)>
//     <0=> ADC0_SE15<selection=ADC0_SE15_PIN_SEL,PTC1>
//     <1=> GPIOC_1/LLWU_P6<selection=GPIOC_1_PIN_SEL,PTC1><selection=LLWU_P6_PIN_SEL,PTC1>
//     <2=> SPI0_PCS3<selection=SPI0_PCS3_PIN_SEL,PTC1>
//     <3=> UART1_RTS_b<selection=UART1_RTS_b_PIN_SEL,PTC1>
//     <4=> FTM0_CH0<selection=FTM0_CH0_PIN_SEL,PTC1>
//     <5=> FB_AD13<selection=FB_AD13_PIN_SEL,PTC1>
//     <6=> I2S0_TXD0<selection=I2S0_TXD0_PIN_SEL,PTC1>
//     <7=> LPUART0_RTS_b<selection=LPUART0_RTS_b_PIN_SEL,PTC1>
//     <0=> Default
#define PTC1_SIG_SEL         0

// Signal mapping for PTC2 pin
//   <o>    PTC2<name=PTC2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC2 pin
//   <info> ADC0_SE4b/CMP1_IN0, GPIOC_2, SPI0_PCS2, UART1_CTS_b, FTM0_CH1, FB_AD12, I2S0_TX_FS, LPUART0_CTS_b
//     <-2=> ADC0_SE4b/CMP1_IN0 (reset default)<selection=ADC0_SE4b_PIN_SEL,PTC2 (reset default)><selection=CMP1_IN0_PIN_SEL,PTC2 (reset default)>
//     <0=> ADC0_SE4b/CMP1_IN0<selection=ADC0_SE4b_PIN_SEL,PTC2><selection=CMP1_IN0_PIN_SEL,PTC2>
//     <1=> GPIOC_2<selection=GPIOC_2_PIN_SEL,PTC2>
//     <2=> SPI0_PCS2<selection=SPI0_PCS2_PIN_SEL,PTC2>
//     <3=> UART1_CTS_b<selection=UART1_CTS_b_PIN_SEL,PTC2>
//     <4=> FTM0_CH1<selection=FTM0_CH1_PIN_SEL,PTC2>
//     <5=> FB_AD12<selection=FB_AD12_PIN_SEL,PTC2>
//     <6=> I2S0_TX_FS<selection=I2S0_TX_FS_PIN_SEL,PTC2>
//     <7=> LPUART0_CTS_b<selection=LPUART0_CTS_b_PIN_SEL,PTC2>
//     <0=> Default
#define PTC2_SIG_SEL         0

// Signal mapping for PTC3 pin
//   <o>    PTC3<name=PTC3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC3 pin
//   <info> CMP1_IN1, GPIOC_3/LLWU_P7, SPI0_PCS1, UART1_RX, FTM0_CH2, CLKOUT, I2S0_TX_BCLK, LPUART0_RX
//     <-2=> CMP1_IN1 (reset default)<selection=CMP1_IN1_PIN_SEL,PTC3 (reset default)>
//     <0=> CMP1_IN1<selection=CMP1_IN1_PIN_SEL,PTC3>
//     <1=> GPIOC_3/LLWU_P7<selection=GPIOC_3_PIN_SEL,PTC3><selection=LLWU_P7_PIN_SEL,PTC3>
//     <2=> SPI0_PCS1<selection=SPI0_PCS1_PIN_SEL,PTC3>
//     <3=> UART1_RX<selection=UART1_RX_PIN_SEL,PTC3>
//     <4=> FTM0_CH2<selection=FTM0_CH2_PIN_SEL,PTC3>
//     <5=> CLKOUT<selection=CLKOUT_PIN_SEL,PTC3>
//     <6=> I2S0_TX_BCLK<selection=I2S0_TX_BCLK_PIN_SEL,PTC3>
//     <7=> LPUART0_RX<selection=LPUART0_RX_PIN_SEL,PTC3>
//     <1=> Default
#define PTC3_SIG_SEL         1

// Signal mapping for PTC4 pin
//   <o>    PTC4<name=PTC4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC4 pin
//   <info> GPIOC_4/LLWU_P8, SPI0_PCS0, UART1_TX, FTM0_CH3, FB_AD11, CMP1_OUT, LPUART0_TX
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_4/LLWU_P8<selection=GPIOC_4_PIN_SEL,PTC4><selection=LLWU_P8_PIN_SEL,PTC4>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTC4>
//     <3=> UART1_TX<selection=UART1_TX_PIN_SEL,PTC4>
//     <4=> FTM0_CH3<selection=FTM0_CH3_PIN_SEL,PTC4>
//     <5=> FB_AD11<selection=FB_AD11_PIN_SEL,PTC4>
//     <6=> CMP1_OUT<selection=CMP1_OUT_PIN_SEL,PTC4>
//     <7=> LPUART0_TX<selection=LPUART0_TX_PIN_SEL,PTC4>
//     <-2=> Default
#define PTC4_SIG_SEL         -2

// Signal mapping for PTC5 pin
//   <o>    PTC5<name=PTC5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC5 pin
//   <info> GPIOC_5/LLWU_P9, SPI0_SCK, LPTMR0_ALT2, I2S0_RXD0, FB_AD10, CMP0_OUT, FTM0_CH2
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
//   <o>    PTC6<name=PTC6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC6 pin
//   <info> CMP0_IN0, GPIOC_6/LLWU_P10, SPI0_SOUT, PDB0_EXTRG, I2S0_RX_BCLK, FB_AD9, I2S0_MCLK
//     <-2=> CMP0_IN0 (reset default)<selection=CMP0_IN0_PIN_SEL,PTC6 (reset default)>
//     <0=> CMP0_IN0<selection=CMP0_IN0_PIN_SEL,PTC6>
//     <1=> GPIOC_6/LLWU_P10<selection=GPIOC_6_PIN_SEL,PTC6><selection=LLWU_P10_PIN_SEL,PTC6>
//     <2=> SPI0_SOUT<selection=SPI0_SOUT_PIN_SEL,PTC6>
//     <3=> PDB0_EXTRG<selection=PDB0_EXTRG_PIN_SEL,PTC6>
//     <4=> I2S0_RX_BCLK<selection=I2S0_RX_BCLK_PIN_SEL,PTC6>
//     <5=> FB_AD9<selection=FB_AD9_PIN_SEL,PTC6>
//     <6=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTC6>
//     <1=> Default
#define PTC6_SIG_SEL         1

// Signal mapping for PTC7 pin
//   <o>    PTC7<name=PTC7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC7 pin
//   <info> CMP0_IN1, GPIOC_7, SPI0_SIN, USB_SOF_OUT, I2S0_RX_FS, FB_AD8
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
//   <o>    PTC8<name=PTC8_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC8 pin
//   <info> ADC1_SE4b/CMP0_IN2, GPIOC_8, FTM3_CH4, I2S0_MCLK, FB_AD7
//     <-2=> ADC1_SE4b/CMP0_IN2 (reset default)<selection=ADC1_SE4b_PIN_SEL,PTC8 (reset default)><selection=CMP0_IN2_PIN_SEL,PTC8 (reset default)>
//     <0=> ADC1_SE4b/CMP0_IN2<selection=ADC1_SE4b_PIN_SEL,PTC8><selection=CMP0_IN2_PIN_SEL,PTC8>
//     <1=> GPIOC_8<selection=GPIOC_8_PIN_SEL,PTC8>
//     <3=> FTM3_CH4<selection=FTM3_CH4_PIN_SEL,PTC8>
//     <4=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTC8>
//     <5=> FB_AD7<selection=FB_AD7_PIN_SEL,PTC8>
//     <-2=> Default
#define PTC8_SIG_SEL         -2

// Signal mapping for PTC9 pin
//   <o>    PTC9<name=PTC9_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC9 pin
//   <info> ADC1_SE5b/CMP0_IN3, GPIOC_9, FTM3_CH5, I2S0_RX_BCLK, FB_AD6, FTM2_FLT0
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
//   <o>    PTC10<name=PTC10_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC10 pin
//   <info> ADC1_SE6b, GPIOC_10, I2C1_SCL, FTM3_CH6, I2S0_RX_FS, FB_AD5
//     <-2=> ADC1_SE6b (reset default)<selection=ADC1_SE6b_PIN_SEL,PTC10 (reset default)>
//     <0=> ADC1_SE6b<selection=ADC1_SE6b_PIN_SEL,PTC10>
//     <1=> GPIOC_10<selection=GPIOC_10_PIN_SEL,PTC10>
//     <2=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTC10>
//     <3=> FTM3_CH6<selection=FTM3_CH6_PIN_SEL,PTC10>
//     <4=> I2S0_RX_FS<selection=I2S0_RX_FS_PIN_SEL,PTC10>
//     <5=> FB_AD5<selection=FB_AD5_PIN_SEL,PTC10>
//     <-2=> Default
#define PTC10_SIG_SEL        -2

// Signal mapping for PTC11 pin
//   <o>    PTC11<name=PTC11_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC11 pin
//   <info> ADC1_SE7b, GPIOC_11/LLWU_P11, I2C1_SDA, FTM3_CH7, FB_RW_b
//     <-2=> ADC1_SE7b (reset default)<selection=ADC1_SE7b_PIN_SEL,PTC11 (reset default)>
//     <0=> ADC1_SE7b<selection=ADC1_SE7b_PIN_SEL,PTC11>
//     <1=> GPIOC_11/LLWU_P11<selection=GPIOC_11_PIN_SEL,PTC11><selection=LLWU_P11_PIN_SEL,PTC11>
//     <2=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTC11>
//     <3=> FTM3_CH7<selection=FTM3_CH7_PIN_SEL,PTC11>
//     <5=> FB_RW_b<selection=FB_RW_b_PIN_SEL,PTC11>
//     <-2=> Default
#define PTC11_SIG_SEL        -2

// Signal mapping for PTC12 pin
//   <o>    PTC12<name=PTC12_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC12 pin
//   <info> GPIOC_12, FB_AD27, FTM3_FLT0
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_12<selection=GPIOC_12_PIN_SEL,PTC12>
//     <5=> FB_AD27<selection=FB_AD27_PIN_SEL,PTC12>
//     <6=> FTM3_FLT0<selection=FTM3_FLT0_PIN_SEL,PTC12>
//     <-2=> Default
#define PTC12_SIG_SEL        -2

// Signal mapping for PTC13 pin
//   <o>    PTC13<name=PTC13_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC13 pin
//   <info> GPIOC_13, FB_AD26
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_13<selection=GPIOC_13_PIN_SEL,PTC13>
//     <5=> FB_AD26<selection=FB_AD26_PIN_SEL,PTC13>
//     <-2=> Default
#define PTC13_SIG_SEL        -2

// Signal mapping for PTC14 pin
//   <o>    PTC14<name=PTC14_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC14 pin
//   <info> GPIOC_14, FB_AD25
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_14<selection=GPIOC_14_PIN_SEL,PTC14>
//     <5=> FB_AD25<selection=FB_AD25_PIN_SEL,PTC14>
//     <-2=> Default
#define PTC14_SIG_SEL        -2

// Signal mapping for PTC15 pin
//   <o>    PTC15<name=PTC15_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC15 pin
//   <info> GPIOC_15, FB_AD24
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_15<selection=GPIOC_15_PIN_SEL,PTC15>
//     <5=> FB_AD24<selection=FB_AD24_PIN_SEL,PTC15>
//     <-2=> Default
#define PTC15_SIG_SEL        -2

// Signal mapping for PTC16 pin
//   <o>    PTC16<name=PTC16_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC16 pin
//   <info> GPIOC_16, LPUART0_RX, FB_CS5_b/FB_TSIZ1/FB_BE23_16_BLS15_8_b
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_16<selection=GPIOC_16_PIN_SEL,PTC16>
//     <3=> LPUART0_RX<selection=LPUART0_RX_PIN_SEL,PTC16>
//     <5=> FB_CS5_b/FB_TSIZ1/FB_BE23_16_BLS15_8_b<selection=FB_CS5_b_PIN_SEL,PTC16><selection=FB_TSIZ1_PIN_SEL,PTC16><selection=FB_BE23_16_BLS15_8_b_PIN_SEL,PTC16>
//     <-2=> Default
#define PTC16_SIG_SEL        -2

// Signal mapping for PTC17 pin
//   <o>    PTC17<name=PTC17_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC17 pin
//   <info> GPIOC_17, LPUART0_TX, FB_CS4_b/FB_TSIZ0/FB_BE31_24_BLS7_0_b
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_17<selection=GPIOC_17_PIN_SEL,PTC17>
//     <3=> LPUART0_TX<selection=LPUART0_TX_PIN_SEL,PTC17>
//     <5=> FB_CS4_b/FB_TSIZ0/FB_BE31_24_BLS7_0_b<selection=FB_CS4_b_PIN_SEL,PTC17><selection=FB_TSIZ0_PIN_SEL,PTC17><selection=FB_BE31_24_BLS7_0_b_PIN_SEL,PTC17>
//     <-2=> Default
#define PTC17_SIG_SEL        -2

// Signal mapping for PTC18 pin
//   <o>    PTC18<name=PTC18_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC18 pin
//   <info> GPIOC_18, LPUART0_RTS_b, FB_TBST_b/FB_CS2_b/FB_BE15_8_BLS23_16_b
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_18<selection=GPIOC_18_PIN_SEL,PTC18>
//     <3=> LPUART0_RTS_b<selection=LPUART0_RTS_b_PIN_SEL,PTC18>
//     <5=> FB_TBST_b/FB_CS2_b/FB_BE15_8_BLS23_16_b<selection=FB_TBST_b_PIN_SEL,PTC18><selection=FB_CS2_b_PIN_SEL,PTC18><selection=FB_BE15_8_BLS23_16_b_PIN_SEL,PTC18>
//     <-2=> Default
#define PTC18_SIG_SEL        -2

// Signal mapping for PTC19 pin
//   <o>    PTC19<name=PTC19_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTC19 pin
//   <info> GPIOC_19, LPUART0_CTS_b, FB_CS3_b/FB_BE7_0_BLS31_24_b, FB_TA_b
//     <-2=> Disabled (reset default)
//     <1=> GPIOC_19<selection=GPIOC_19_PIN_SEL,PTC19>
//     <3=> LPUART0_CTS_b<selection=LPUART0_CTS_b_PIN_SEL,PTC19>
//     <5=> FB_CS3_b/FB_BE7_0_BLS31_24_b<selection=FB_CS3_b_PIN_SEL,PTC19><selection=FB_BE7_0_BLS31_24_b_PIN_SEL,PTC19>
//     <6=> FB_TA_b<selection=FB_TA_b_PIN_SEL,PTC19>
//     <-2=> Default
#define PTC19_SIG_SEL        -2

// </h>

// <h> Port D Pins

// Signal mapping for PTD0 pin
//   <o>    PTD0<name=PTD0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD0 pin
//   <info> GPIOD_0/LLWU_P12, SPI0_PCS0, UART2_RTS_b, FTM3_CH0, FB_ALE/FB_CS1_b/FB_TS_b, LPUART0_RTS_b
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_0/LLWU_P12<selection=GPIOD_0_PIN_SEL,PTD0><selection=LLWU_P12_PIN_SEL,PTD0>
//     <2=> SPI0_PCS0<selection=SPI0_PCS0_PIN_SEL,PTD0>
//     <3=> UART2_RTS_b<selection=UART2_RTS_b_PIN_SEL,PTD0>
//     <4=> FTM3_CH0<selection=FTM3_CH0_PIN_SEL,PTD0>
//     <5=> FB_ALE/FB_CS1_b/FB_TS_b<selection=FB_ALE_PIN_SEL,PTD0><selection=FB_CS1_b_PIN_SEL,PTD0><selection=FB_TS_b_PIN_SEL,PTD0>
//     <6=> LPUART0_RTS_b<selection=LPUART0_RTS_b_PIN_SEL,PTD0>
//     <-2=> Default
#define PTD0_SIG_SEL         -2

// Signal mapping for PTD1 pin
//   <o>    PTD1<name=PTD1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD1 pin
//   <info> ADC0_SE5b, GPIOD_1, SPI0_SCK, UART2_CTS_b, FTM3_CH1, FB_CS0_b, LPUART0_CTS_b
//     <-2=> ADC0_SE5b (reset default)<selection=ADC0_SE5b_PIN_SEL,PTD1 (reset default)>
//     <0=> ADC0_SE5b<selection=ADC0_SE5b_PIN_SEL,PTD1>
//     <1=> GPIOD_1<selection=GPIOD_1_PIN_SEL,PTD1>
//     <2=> SPI0_SCK<selection=SPI0_SCK_PIN_SEL,PTD1>
//     <3=> UART2_CTS_b<selection=UART2_CTS_b_PIN_SEL,PTD1>
//     <4=> FTM3_CH1<selection=FTM3_CH1_PIN_SEL,PTD1>
//     <5=> FB_CS0_b<selection=FB_CS0_b_PIN_SEL,PTD1>
//     <6=> LPUART0_CTS_b<selection=LPUART0_CTS_b_PIN_SEL,PTD1>
//     <-2=> Default
#define PTD1_SIG_SEL         -2

// Signal mapping for PTD2 pin
//   <o>    PTD2<name=PTD2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD2 pin
//   <info> GPIOD_2/LLWU_P13, SPI0_SOUT, UART2_RX, FTM3_CH2, FB_AD4, LPUART0_RX, I2C0_SCL
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_2/LLWU_P13<selection=GPIOD_2_PIN_SEL,PTD2><selection=LLWU_P13_PIN_SEL,PTD2>
//     <2=> SPI0_SOUT<selection=SPI0_SOUT_PIN_SEL,PTD2>
//     <3=> UART2_RX<selection=UART2_RX_PIN_SEL,PTD2>
//     <4=> FTM3_CH2<selection=FTM3_CH2_PIN_SEL,PTD2>
//     <5=> FB_AD4<selection=FB_AD4_PIN_SEL,PTD2>
//     <6=> LPUART0_RX<selection=LPUART0_RX_PIN_SEL,PTD2>
//     <7=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTD2>
//     <1=> Default
#define PTD2_SIG_SEL         1

// Signal mapping for PTD3 pin
//   <o>    PTD3<name=PTD3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD3 pin
//   <info> GPIOD_3, SPI0_SIN, UART2_TX, FTM3_CH3, FB_AD3, LPUART0_TX, I2C0_SDA
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_3<selection=GPIOD_3_PIN_SEL,PTD3>
//     <2=> SPI0_SIN<selection=SPI0_SIN_PIN_SEL,PTD3>
//     <3=> UART2_TX<selection=UART2_TX_PIN_SEL,PTD3>
//     <4=> FTM3_CH3<selection=FTM3_CH3_PIN_SEL,PTD3>
//     <5=> FB_AD3<selection=FB_AD3_PIN_SEL,PTD3>
//     <6=> LPUART0_TX<selection=LPUART0_TX_PIN_SEL,PTD3>
//     <7=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTD3>
//     <1=> Default
#define PTD3_SIG_SEL         1

// Signal mapping for PTD4 pin
//   <o>    PTD4<name=PTD4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD4 pin
//   <info> GPIOD_4/LLWU_P14, SPI0_PCS1, UART0_RTS_b, FTM0_CH4, FB_AD2, EWM_IN, SPI1_PCS0
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_4/LLWU_P14<selection=GPIOD_4_PIN_SEL,PTD4><selection=LLWU_P14_PIN_SEL,PTD4>
//     <2=> SPI0_PCS1<selection=SPI0_PCS1_PIN_SEL,PTD4>
//     <3=> UART0_RTS_b<selection=UART0_RTS_b_PIN_SEL,PTD4>
//     <4=> FTM0_CH4<selection=FTM0_CH4_PIN_SEL,PTD4>
//     <5=> FB_AD2<selection=FB_AD2_PIN_SEL,PTD4>
//     <6=> EWM_IN<selection=EWM_IN_PIN_SEL,PTD4>
//     <7=> SPI1_PCS0<selection=SPI1_PCS0_PIN_SEL,PTD4>
//     <1=> Default
#define PTD4_SIG_SEL         1

// Signal mapping for PTD5 pin
//   <o>    PTD5<name=PTD5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD5 pin
//   <info> ADC0_SE6b, GPIOD_5, SPI0_PCS2, UART0_CTS_b, FTM0_CH5, FB_AD1, EWM_OUT_b, SPI1_SCK
//     <-2=> ADC0_SE6b (reset default)<selection=ADC0_SE6b_PIN_SEL,PTD5 (reset default)>
//     <0=> ADC0_SE6b<selection=ADC0_SE6b_PIN_SEL,PTD5>
//     <1=> GPIOD_5<selection=GPIOD_5_PIN_SEL,PTD5>
//     <2=> SPI0_PCS2<selection=SPI0_PCS2_PIN_SEL,PTD5>
//     <3=> UART0_CTS_b<selection=UART0_CTS_b_PIN_SEL,PTD5>
//     <4=> FTM0_CH5<selection=FTM0_CH5_PIN_SEL,PTD5>
//     <5=> FB_AD1<selection=FB_AD1_PIN_SEL,PTD5>
//     <6=> EWM_OUT_b<selection=EWM_OUT_b_PIN_SEL,PTD5>
//     <7=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTD5>
//     <4=> Default
#define PTD5_SIG_SEL         4

// Signal mapping for PTD6 pin
//   <o>    PTD6<name=PTD6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD6 pin
//   <info> ADC0_SE7b, GPIOD_6/LLWU_P15, SPI0_PCS3, UART0_RX, FTM0_CH6, FB_AD0, FTM0_FLT0, SPI1_SOUT
//     <-2=> ADC0_SE7b (reset default)<selection=ADC0_SE7b_PIN_SEL,PTD6 (reset default)>
//     <0=> ADC0_SE7b<selection=ADC0_SE7b_PIN_SEL,PTD6>
//     <1=> GPIOD_6/LLWU_P15<selection=GPIOD_6_PIN_SEL,PTD6><selection=LLWU_P15_PIN_SEL,PTD6>
//     <2=> SPI0_PCS3<selection=SPI0_PCS3_PIN_SEL,PTD6>
//     <3=> UART0_RX<selection=UART0_RX_PIN_SEL,PTD6>
//     <4=> FTM0_CH6<selection=FTM0_CH6_PIN_SEL,PTD6>
//     <5=> FB_AD0<selection=FB_AD0_PIN_SEL,PTD6>
//     <6=> FTM0_FLT0<selection=FTM0_FLT0_PIN_SEL,PTD6>
//     <7=> SPI1_SOUT<selection=SPI1_SOUT_PIN_SEL,PTD6>
//     <7=> Default
#define PTD6_SIG_SEL         7

// Signal mapping for PTD7 pin
//   <o>    PTD7<name=PTD7_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD7 pin
//   <info> GPIOD_7, UART0_TX, FTM0_CH7, FTM0_FLT1, SPI1_SIN
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_7<selection=GPIOD_7_PIN_SEL,PTD7>
//     <3=> UART0_TX<selection=UART0_TX_PIN_SEL,PTD7>
//     <4=> FTM0_CH7<selection=FTM0_CH7_PIN_SEL,PTD7>
//     <6=> FTM0_FLT1<selection=FTM0_FLT1_PIN_SEL,PTD7>
//     <7=> SPI1_SIN<selection=SPI1_SIN_PIN_SEL,PTD7>
//     <7=> Default
#define PTD7_SIG_SEL         7

// Signal mapping for PTD8 pin
//   <o>    PTD8<name=PTD8_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD8 pin
//   <info> GPIOD_8, I2C0_SCL, LPUART0_RX, FB_A16
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_8<selection=GPIOD_8_PIN_SEL,PTD8>
//     <2=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTD8>
//     <5=> LPUART0_RX<selection=LPUART0_RX_PIN_SEL,PTD8>
//     <6=> FB_A16<selection=FB_A16_PIN_SEL,PTD8>
//     <-2=> Default
#define PTD8_SIG_SEL         -2

// Signal mapping for PTD9 pin
//   <o>    PTD9<name=PTD9_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD9 pin
//   <info> GPIOD_9, I2C0_SDA, LPUART0_TX, FB_A17
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_9<selection=GPIOD_9_PIN_SEL,PTD9>
//     <2=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTD9>
//     <5=> LPUART0_TX<selection=LPUART0_TX_PIN_SEL,PTD9>
//     <6=> FB_A17<selection=FB_A17_PIN_SEL,PTD9>
//     <-2=> Default
#define PTD9_SIG_SEL         -2

// Signal mapping for PTD10 pin
//   <o>    PTD10<name=PTD10_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD10 pin
//   <info> GPIOD_10, LPUART0_RTS_b, FB_A18
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_10<selection=GPIOD_10_PIN_SEL,PTD10>
//     <5=> LPUART0_RTS_b<selection=LPUART0_RTS_b_PIN_SEL,PTD10>
//     <6=> FB_A18<selection=FB_A18_PIN_SEL,PTD10>
//     <-2=> Default
#define PTD10_SIG_SEL        -2

// Signal mapping for PTD11 pin
//   <o>    PTD11<name=PTD11_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD11 pin
//   <info> GPIOD_11, LPUART0_CTS_b, FB_A19
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_11<selection=GPIOD_11_PIN_SEL,PTD11>
//     <5=> LPUART0_CTS_b<selection=LPUART0_CTS_b_PIN_SEL,PTD11>
//     <6=> FB_A19<selection=FB_A19_PIN_SEL,PTD11>
//     <-2=> Default
#define PTD11_SIG_SEL        -2

// Signal mapping for PTD12 pin
//   <o>    PTD12<name=PTD12_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD12 pin
//   <info> GPIOD_12, FTM3_FLT0, FB_A20
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_12<selection=GPIOD_12_PIN_SEL,PTD12>
//     <3=> FTM3_FLT0<selection=FTM3_FLT0_PIN_SEL,PTD12>
//     <6=> FB_A20<selection=FB_A20_PIN_SEL,PTD12>
//     <-2=> Default
#define PTD12_SIG_SEL        -2

// Signal mapping for PTD13 pin
//   <o>    PTD13<name=PTD13_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD13 pin
//   <info> GPIOD_13, FB_A21
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_13<selection=GPIOD_13_PIN_SEL,PTD13>
//     <6=> FB_A21<selection=FB_A21_PIN_SEL,PTD13>
//     <-2=> Default
#define PTD13_SIG_SEL        -2

// Signal mapping for PTD14 pin
//   <o>    PTD14<name=PTD14_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD14 pin
//   <info> GPIOD_14, FB_A22
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_14<selection=GPIOD_14_PIN_SEL,PTD14>
//     <6=> FB_A22<selection=FB_A22_PIN_SEL,PTD14>
//     <-2=> Default
#define PTD14_SIG_SEL        -2

// Signal mapping for PTD15 pin
//   <o>    PTD15<name=PTD15_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTD15 pin
//   <info> GPIOD_15, FB_A23
//     <-2=> Disabled (reset default)
//     <1=> GPIOD_15<selection=GPIOD_15_PIN_SEL,PTD15>
//     <6=> FB_A23<selection=FB_A23_PIN_SEL,PTD15>
//     <-2=> Default
#define PTD15_SIG_SEL        -2

// </h>

// <h> Port E Pins

// Signal mapping for PTE0 pin
//   <o>    PTE0<name=PTE0_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE0 pin
//   <info> ADC1_SE4a, GPIOE_0/CLKOUT32K, SPI1_PCS1, UART1_TX, I2C1_SDA, RTC_CLKOUT
//     <-2=> ADC1_SE4a (reset default)<selection=ADC1_SE4a_PIN_SEL,PTE0 (reset default)>
//     <0=> ADC1_SE4a<selection=ADC1_SE4a_PIN_SEL,PTE0>
//     <1=> GPIOE_0/CLKOUT32K<selection=GPIOE_0_PIN_SEL,PTE0><selection=CLKOUT32K_PIN_SEL,PTE0>
//     <2=> SPI1_PCS1<selection=SPI1_PCS1_PIN_SEL,PTE0>
//     <3=> UART1_TX<selection=UART1_TX_PIN_SEL,PTE0>
//     <6=> I2C1_SDA<selection=I2C1_SDA_PIN_SEL,PTE0>
//     <7=> RTC_CLKOUT<selection=RTC_CLKOUT_PIN_SEL,PTE0>
//     <6=> Default
#define PTE0_SIG_SEL         6

// Signal mapping for PTE1 pin
//   <o>    PTE1<name=PTE1_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE1 pin
//   <info> ADC1_SE5a, GPIOE_1/LLWU_P0, SPI1_SOUT, UART1_RX, I2C1_SCL, SPI1_SIN
//     <-2=> ADC1_SE5a (reset default)<selection=ADC1_SE5a_PIN_SEL,PTE1 (reset default)>
//     <0=> ADC1_SE5a<selection=ADC1_SE5a_PIN_SEL,PTE1>
//     <1=> GPIOE_1/LLWU_P0<selection=GPIOE_1_PIN_SEL,PTE1><selection=LLWU_P0_PIN_SEL,PTE1>
//     <2=> SPI1_SOUT<selection=SPI1_SOUT_PIN_SEL,PTE1>
//     <3=> UART1_RX<selection=UART1_RX_PIN_SEL,PTE1>
//     <6=> I2C1_SCL<selection=I2C1_SCL_PIN_SEL,PTE1>
//     <7=> SPI1_SIN<selection=SPI1_SIN_PIN_SEL,PTE1>
//     <6=> Default
#define PTE1_SIG_SEL         6

// Signal mapping for PTE2 pin
//   <o>    PTE2<name=PTE2_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE2 pin
//   <info> ADC1_SE6a, GPIOE_2/LLWU_P1, SPI1_SCK, UART1_CTS_b
//     <-2=> ADC1_SE6a (reset default)<selection=ADC1_SE6a_PIN_SEL,PTE2 (reset default)>
//     <0=> ADC1_SE6a<selection=ADC1_SE6a_PIN_SEL,PTE2>
//     <1=> GPIOE_2/LLWU_P1<selection=GPIOE_2_PIN_SEL,PTE2><selection=LLWU_P1_PIN_SEL,PTE2>
//     <2=> SPI1_SCK<selection=SPI1_SCK_PIN_SEL,PTE2>
//     <3=> UART1_CTS_b<selection=UART1_CTS_b_PIN_SEL,PTE2>
//     <-2=> Default
#define PTE2_SIG_SEL         -2

// Signal mapping for PTE3 pin
//   <o>    PTE3<name=PTE3_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE3 pin
//   <info> ADC1_SE7a, GPIOE_3, SPI1_SIN, UART1_RTS_b, SPI1_SOUT
//     <-2=> ADC1_SE7a (reset default)<selection=ADC1_SE7a_PIN_SEL,PTE3 (reset default)>
//     <0=> ADC1_SE7a<selection=ADC1_SE7a_PIN_SEL,PTE3>
//     <1=> GPIOE_3<selection=GPIOE_3_PIN_SEL,PTE3>
//     <2=> SPI1_SIN<selection=SPI1_SIN_PIN_SEL,PTE3>
//     <3=> UART1_RTS_b<selection=UART1_RTS_b_PIN_SEL,PTE3>
//     <7=> SPI1_SOUT<selection=SPI1_SOUT_PIN_SEL,PTE3>
//     <-2=> Default
#define PTE3_SIG_SEL         -2

// Signal mapping for PTE4 pin
//   <o>    PTE4<name=PTE4_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE4 pin
//   <info> GPIOE_4/LLWU_P2, SPI1_PCS0, LPUART0_TX
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_4/LLWU_P2<selection=GPIOE_4_PIN_SEL,PTE4><selection=LLWU_P2_PIN_SEL,PTE4>
//     <2=> SPI1_PCS0<selection=SPI1_PCS0_PIN_SEL,PTE4>
//     <3=> LPUART0_TX<selection=LPUART0_TX_PIN_SEL,PTE4>
//     <-2=> Default
#define PTE4_SIG_SEL         -2

// Signal mapping for PTE5 pin
//   <o>    PTE5<name=PTE5_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE5 pin
//   <info> GPIOE_5, SPI1_PCS2, LPUART0_RX, FTM3_CH0
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_5<selection=GPIOE_5_PIN_SEL,PTE5>
//     <2=> SPI1_PCS2<selection=SPI1_PCS2_PIN_SEL,PTE5>
//     <3=> LPUART0_RX<selection=LPUART0_RX_PIN_SEL,PTE5>
//     <6=> FTM3_CH0<selection=FTM3_CH0_PIN_SEL,PTE5>
//     <-2=> Default
#define PTE5_SIG_SEL         -2

// Signal mapping for PTE6 pin
//   <o>    PTE6<name=PTE6_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE6 pin
//   <info> GPIOE_6, SPI1_PCS3, LPUART0_CTS_b, I2S0_MCLK, FTM3_CH1, USB_SOF_OUT
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_6<selection=GPIOE_6_PIN_SEL,PTE6>
//     <2=> SPI1_PCS3<selection=SPI1_PCS3_PIN_SEL,PTE6>
//     <3=> LPUART0_CTS_b<selection=LPUART0_CTS_b_PIN_SEL,PTE6>
//     <4=> I2S0_MCLK<selection=I2S0_MCLK_PIN_SEL,PTE6>
//     <6=> FTM3_CH1<selection=FTM3_CH1_PIN_SEL,PTE6>
//     <7=> USB_SOF_OUT<selection=USB_SOF_OUT_PIN_SEL,PTE6>
//     <-2=> Default
#define PTE6_SIG_SEL         -2

// Signal mapping for PTE24 pin
//   <o>    PTE24<name=PTE24_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE24 pin
//   <info> ADC0_SE17, GPIOE_24, I2C0_SCL, EWM_OUT_b
//     <-2=> ADC0_SE17 (reset default)<selection=ADC0_SE17_PIN_SEL,PTE24 (reset default)>
//     <0=> ADC0_SE17<selection=ADC0_SE17_PIN_SEL,PTE24>
//     <1=> GPIOE_24<selection=GPIOE_24_PIN_SEL,PTE24>
//     <5=> I2C0_SCL<selection=I2C0_SCL_PIN_SEL,PTE24>
//     <6=> EWM_OUT_b<selection=EWM_OUT_b_PIN_SEL,PTE24>
//     <-2=> Default
#define PTE24_SIG_SEL        -2

// Signal mapping for PTE25 pin
//   <o>    PTE25<name=PTE25_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE25 pin
//   <info> ADC0_SE18, GPIOE_25, I2C0_SDA, EWM_IN
//     <-2=> ADC0_SE18 (reset default)<selection=ADC0_SE18_PIN_SEL,PTE25 (reset default)>
//     <0=> ADC0_SE18<selection=ADC0_SE18_PIN_SEL,PTE25>
//     <1=> GPIOE_25<selection=GPIOE_25_PIN_SEL,PTE25>
//     <5=> I2C0_SDA<selection=I2C0_SDA_PIN_SEL,PTE25>
//     <6=> EWM_IN<selection=EWM_IN_PIN_SEL,PTE25>
//     <-2=> Default
#define PTE25_SIG_SEL        -2

// Signal mapping for PTE26 pin
//   <o>    PTE26<name=PTE26_SIG_SEL>
//   <i>    Selects which peripheral signal is mapped to PTE26 pin
//   <info> GPIOE_26/CLKOUT32K, RTC_CLKOUT, USB_CLKIN
//     <-2=> Disabled (reset default)
//     <1=> GPIOE_26/CLKOUT32K<selection=GPIOE_26_PIN_SEL,PTE26><selection=CLKOUT32K_PIN_SEL,PTE26>
//     <6=> RTC_CLKOUT<selection=RTC_CLKOUT_PIN_SEL,PTE26>
//     <7=> USB_CLKIN<selection=USB_CLKIN_PIN_SEL,PTE26>
//     <-2=> Default
#define PTE26_SIG_SEL        -2

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

// Pin Mapping for RTC_WAKEUP_B signal
//   <o>    RTC_WAKEUP_B<name=RTC_WAKEUP_B_PIN_SEL><constant>
//   <i>    Shows which pin RTC_WAKEUP_B is mapped to
//   <info>  [RTC_WAKEUP_B]
//     <0=> RTC_WAKEUP_B<selection=RTC_WAKEUP_B_SIG_SEL,RTC_WAKEUP_B>
//     <0=> Default
#define RTC_WAKEUP_B_PIN_SEL 0

// </h>

// <h> Analogue to Digital (ADC0)

// Pin Mapping for ADC0_DM0 signal
//   <o>    ADC0_DM0<name=ADC0_DM0_PIN_SEL><constant>
//   <i>    Shows which pin ADC0_DM0 is mapped to
//   <info>  [ADC0_DM0]
//     <0=> ADC0_DM0<selection=ADC0_DM0_SIG_SEL,ADC0_DM0/ADC1_DM3/ADC0_SE19>
//     <0=> Default
#define ADC0_DM0_PIN_SEL     0

// Pin Mapping for ADC0_DM1 signal
//   <o>    ADC0_DM1<name=ADC0_DM1_PIN_SEL><constant>
//   <i>    Shows which pin ADC0_DM1 is mapped to
//   <info>  [ADC0_DM1]
//     <0=> ADC0_DM1<selection=ADC0_DM1_SIG_SEL,ADC0_DM1>
//     <0=> Default
#define ADC0_DM1_PIN_SEL     0

// Pin Mapping for ADC0_DM2 signal
//   <o>    ADC0_DM2<name=ADC0_DM2_PIN_SEL><constant>
//   <i>    Shows which pin ADC0_DM2 is mapped to
//   <info>  [ADC1_DM1]
//     <0=> ADC1_DM1<selection=ADC1_DM1_SIG_SEL,ADC1_DM1/ADC0_DM2>
//     <0=> Default
#define ADC0_DM2_PIN_SEL     0

// Pin Mapping for ADC0_DM3 signal
//   <o>    ADC0_DM3<name=ADC0_DM3_PIN_SEL><constant>
//   <i>    Shows which pin ADC0_DM3 is mapped to
//   <info>  [ADC1_DM0]
//     <0=> ADC1_DM0<selection=ADC1_DM0_SIG_SEL,ADC1_DM0/ADC0_DM3/ADC1_SE19>
//     <0=> Default
#define ADC0_DM3_PIN_SEL     0

// Pin Mapping for ADC0_DP0 signal
//   <o>    ADC0_DP0<name=ADC0_DP0_PIN_SEL><constant>
//   <i>    Shows which pin ADC0_DP0 is mapped to
//   <info>  [ADC0_DP0]
//     <0=> ADC0_DP0<selection=ADC0_DP0_SIG_SEL,ADC0_DP0/ADC1_DP3/ADC0_SE0>
//     <0=> Default
#define ADC0_DP0_PIN_SEL     0

// Pin Mapping for ADC0_DP1 signal
//   <o>    ADC0_DP1<name=ADC0_DP1_PIN_SEL><constant>
//   <i>    Shows which pin ADC0_DP1 is mapped to
//   <info>  [ADC0_DP1]
//     <0=> ADC0_DP1<selection=ADC0_DP1_SIG_SEL,ADC0_DP1>
//     <0=> Default
#define ADC0_DP1_PIN_SEL     0

// Pin Mapping for ADC0_DP2 signal
//   <o>    ADC0_DP2<name=ADC0_DP2_PIN_SEL><constant>
//   <i>    Shows which pin ADC0_DP2 is mapped to
//   <info>  [ADC1_DP1]
//     <0=> ADC1_DP1<selection=ADC1_DP1_SIG_SEL,ADC1_DP1/ADC0_DP2>
//     <0=> Default
#define ADC0_DP2_PIN_SEL     0

// Pin Mapping for ADC0_DP3 signal
//   <o>    ADC0_DP3<name=ADC0_DP3_PIN_SEL><constant>
//   <i>    Shows which pin ADC0_DP3 is mapped to
//   <info>  [ADC1_DP0]
//     <0=> ADC1_DP0<selection=ADC1_DP0_SIG_SEL,ADC1_DP0/ADC0_DP3/ADC1_SE0/ADC0_SE3>
//     <0=> Default
#define ADC0_DP3_PIN_SEL     0

// Pin Mapping for ADC0_SE0 signal
//   <o>    ADC0_SE0<name=ADC0_SE0_PIN_SEL><constant>
//   <i>    Shows which pin ADC0_SE0 is mapped to
//   <info>  [ADC0_DP0]
//     <0=> ADC0_DP0<selection=ADC0_DP0_SIG_SEL,ADC0_DP0/ADC1_DP3/ADC0_SE0>
//     <0=> Default
#define ADC0_SE0_PIN_SEL     0

// Pin Mapping for ADC0_SE3 signal
//   <o>    ADC0_SE3<name=ADC0_SE3_PIN_SEL><constant>
//   <i>    Shows which pin ADC0_SE3 is mapped to
//   <info>  [ADC1_DP0]
//     <0=> ADC1_DP0<selection=ADC1_DP0_SIG_SEL,ADC1_DP0/ADC0_DP3/ADC1_SE0/ADC0_SE3>
//     <0=> Default
#define ADC0_SE3_PIN_SEL     0

// Pin Mapping for ADC0_SE4b signal
//   <o>    ADC0_SE4b<name=ADC0_SE4b_PIN_SEL>
//   <i>    Shows which pin ADC0_SE4b is mapped to
//   <info>  [PTC2]
//     <0=> Disabled
//     <1=> PTC2 (reset default)<selection=PTC2_SIG_SEL,ADC0_SE4b/CMP1_IN0 (reset default)>
//     <2=> PTC2<selection=PTC2_SIG_SEL,ADC0_SE4b/CMP1_IN0>
//     <2=> Default
#define ADC0_SE4b_PIN_SEL    2

// Pin Mapping for ADC0_SE5b signal
//   <o>    ADC0_SE5b<name=ADC0_SE5b_PIN_SEL>
//   <i>    Shows which pin ADC0_SE5b is mapped to
//   <info>  [PTD1]
//     <0=> Disabled
//     <1=> PTD1 (reset default)<selection=PTD1_SIG_SEL,ADC0_SE5b (reset default)>
//     <2=> PTD1<selection=PTD1_SIG_SEL,ADC0_SE5b>
//     <1=> Default
#define ADC0_SE5b_PIN_SEL    1

// Pin Mapping for ADC0_SE6b signal
//   <o>    ADC0_SE6b<name=ADC0_SE6b_PIN_SEL>
//   <i>    Shows which pin ADC0_SE6b is mapped to
//   <info>  [PTD5]
//     <0=> Disabled
//     <1=> PTD5 (reset default)<selection=PTD5_SIG_SEL,ADC0_SE6b (reset default)>
//     <2=> PTD5<selection=PTD5_SIG_SEL,ADC0_SE6b>
//     <0=> Default
#define ADC0_SE6b_PIN_SEL    0

// Pin Mapping for ADC0_SE7b signal
//   <o>    ADC0_SE7b<name=ADC0_SE7b_PIN_SEL>
//   <i>    Shows which pin ADC0_SE7b is mapped to
//   <info>  [PTD6]
//     <0=> Disabled
//     <1=> PTD6 (reset default)<selection=PTD6_SIG_SEL,ADC0_SE7b (reset default)>
//     <2=> PTD6<selection=PTD6_SIG_SEL,ADC0_SE7b>
//     <0=> Default
#define ADC0_SE7b_PIN_SEL    0

// Pin Mapping for ADC0_SE8 signal
//   <o>    ADC0_SE8<name=ADC0_SE8_PIN_SEL>
//   <i>    Shows which pin ADC0_SE8 is mapped to
//   <info>  [PTB0]
//     <0=> Disabled
//     <1=> PTB0 (reset default)<selection=PTB0_SIG_SEL,ADC0_SE8/ADC1_SE8 (reset default)>
//     <2=> PTB0<selection=PTB0_SIG_SEL,ADC0_SE8/ADC1_SE8>
//     <2=> Default
#define ADC0_SE8_PIN_SEL     2

// Pin Mapping for ADC0_SE9 signal
//   <o>    ADC0_SE9<name=ADC0_SE9_PIN_SEL>
//   <i>    Shows which pin ADC0_SE9 is mapped to
//   <info>  [PTB1]
//     <0=> Disabled
//     <1=> PTB1 (reset default)<selection=PTB1_SIG_SEL,ADC0_SE9/ADC1_SE9 (reset default)>
//     <2=> PTB1<selection=PTB1_SIG_SEL,ADC0_SE9/ADC1_SE9>
//     <2=> Default
#define ADC0_SE9_PIN_SEL     2

// Pin Mapping for ADC0_SE12 signal
//   <o>    ADC0_SE12<name=ADC0_SE12_PIN_SEL>
//   <i>    Shows which pin ADC0_SE12 is mapped to
//   <info>  [PTB2]
//     <0=> Disabled
//     <1=> PTB2 (reset default)<selection=PTB2_SIG_SEL,ADC0_SE12 (reset default)>
//     <2=> PTB2<selection=PTB2_SIG_SEL,ADC0_SE12>
//     <2=> Default
#define ADC0_SE12_PIN_SEL    2

// Pin Mapping for ADC0_SE13 signal
//   <o>    ADC0_SE13<name=ADC0_SE13_PIN_SEL>
//   <i>    Shows which pin ADC0_SE13 is mapped to
//   <info>  [PTB3]
//     <0=> Disabled
//     <1=> PTB3 (reset default)<selection=PTB3_SIG_SEL,ADC0_SE13 (reset default)>
//     <2=> PTB3<selection=PTB3_SIG_SEL,ADC0_SE13>
//     <2=> Default
#define ADC0_SE13_PIN_SEL    2

// Pin Mapping for ADC0_SE14 signal
//   <o>    ADC0_SE14<name=ADC0_SE14_PIN_SEL>
//   <i>    Shows which pin ADC0_SE14 is mapped to
//   <info>  [PTC0]
//     <0=> Disabled
//     <1=> PTC0 (reset default)<selection=PTC0_SIG_SEL,ADC0_SE14 (reset default)>
//     <2=> PTC0<selection=PTC0_SIG_SEL,ADC0_SE14>
//     <1=> Default
#define ADC0_SE14_PIN_SEL    1

// Pin Mapping for ADC0_SE15 signal
//   <o>    ADC0_SE15<name=ADC0_SE15_PIN_SEL>
//   <i>    Shows which pin ADC0_SE15 is mapped to
//   <info>  [PTC1]
//     <0=> Disabled
//     <1=> PTC1 (reset default)<selection=PTC1_SIG_SEL,ADC0_SE15 (reset default)>
//     <2=> PTC1<selection=PTC1_SIG_SEL,ADC0_SE15>
//     <2=> Default
#define ADC0_SE15_PIN_SEL    2

// Pin Mapping for ADC0_SE16 signal
//   <o>    ADC0_SE16<name=ADC0_SE16_PIN_SEL><constant>
//   <i>    Shows which pin ADC0_SE16 is mapped to
//   <info>  [ADC0_SE16]
//     <0=> ADC0_SE16<selection=ADC0_SE16_SIG_SEL,ADC0_SE16/CMP1_IN2/ADC0_SE21>
//     <0=> Default
#define ADC0_SE16_PIN_SEL    0

// Pin Mapping for ADC0_SE17 signal
//   <o>    ADC0_SE17<name=ADC0_SE17_PIN_SEL>
//   <i>    Shows which pin ADC0_SE17 is mapped to
//   <info>  [PTE24]
//     <0=> Disabled
//     <1=> PTE24 (reset default)<selection=PTE24_SIG_SEL,ADC0_SE17 (reset default)>
//     <2=> PTE24<selection=PTE24_SIG_SEL,ADC0_SE17>
//     <1=> Default
#define ADC0_SE17_PIN_SEL    1

// Pin Mapping for ADC0_SE18 signal
//   <o>    ADC0_SE18<name=ADC0_SE18_PIN_SEL>
//   <i>    Shows which pin ADC0_SE18 is mapped to
//   <info>  [PTE25]
//     <0=> Disabled
//     <1=> PTE25 (reset default)<selection=PTE25_SIG_SEL,ADC0_SE18 (reset default)>
//     <2=> PTE25<selection=PTE25_SIG_SEL,ADC0_SE18>
//     <1=> Default
#define ADC0_SE18_PIN_SEL    1

// Pin Mapping for ADC0_SE19 signal
//   <o>    ADC0_SE19<name=ADC0_SE19_PIN_SEL><constant>
//   <i>    Shows which pin ADC0_SE19 is mapped to
//   <info>  [ADC0_DM0]
//     <0=> ADC0_DM0<selection=ADC0_DM0_SIG_SEL,ADC0_DM0/ADC1_DM3/ADC0_SE19>
//     <0=> Default
#define ADC0_SE19_PIN_SEL    0

// Pin Mapping for ADC0_SE21 signal
//   <o>    ADC0_SE21<name=ADC0_SE21_PIN_SEL><constant>
//   <i>    Shows which pin ADC0_SE21 is mapped to
//   <info>  [ADC0_SE16]
//     <0=> ADC0_SE16<selection=ADC0_SE16_SIG_SEL,ADC0_SE16/CMP1_IN2/ADC0_SE21>
//     <0=> Default
#define ADC0_SE21_PIN_SEL    0

// Pin Mapping for ADC0_SE22 signal
//   <o>    ADC0_SE22<name=ADC0_SE22_PIN_SEL><constant>
//   <i>    Shows which pin ADC0_SE22 is mapped to
//   <info>  [ADC1_SE16]
//     <0=> ADC1_SE16<selection=ADC1_SE16_SIG_SEL,ADC1_SE16/ADC0_SE22>
//     <0=> Default
#define ADC0_SE22_PIN_SEL    0

// Pin Mapping for ADC0_SE23 signal
//   <o>    ADC0_SE23<name=ADC0_SE23_PIN_SEL><constant>
//   <i>    Shows which pin ADC0_SE23 is mapped to
//   <info>  [DAC0_OUT]
//     <0=> DAC0_OUT<selection=DAC0_OUT_SIG_SEL,DAC0_OUT/CMP1_IN3/ADC0_SE23>
//     <0=> Default
#define ADC0_SE23_PIN_SEL    0

// </h>

// <h> Analogue to Digital (ADC1)

// Pin Mapping for ADC1_DM0 signal
//   <o>    ADC1_DM0<name=ADC1_DM0_PIN_SEL><constant>
//   <i>    Shows which pin ADC1_DM0 is mapped to
//   <info>  [ADC1_DM0]
//     <0=> ADC1_DM0<selection=ADC1_DM0_SIG_SEL,ADC1_DM0/ADC0_DM3/ADC1_SE19>
//     <0=> Default
#define ADC1_DM0_PIN_SEL     0

// Pin Mapping for ADC1_DM1 signal
//   <o>    ADC1_DM1<name=ADC1_DM1_PIN_SEL><constant>
//   <i>    Shows which pin ADC1_DM1 is mapped to
//   <info>  [ADC1_DM1]
//     <0=> ADC1_DM1<selection=ADC1_DM1_SIG_SEL,ADC1_DM1/ADC0_DM2>
//     <0=> Default
#define ADC1_DM1_PIN_SEL     0

// Pin Mapping for ADC1_DM3 signal
//   <o>    ADC1_DM3<name=ADC1_DM3_PIN_SEL><constant>
//   <i>    Shows which pin ADC1_DM3 is mapped to
//   <info>  [ADC0_DM0]
//     <0=> ADC0_DM0<selection=ADC0_DM0_SIG_SEL,ADC0_DM0/ADC1_DM3/ADC0_SE19>
//     <0=> Default
#define ADC1_DM3_PIN_SEL     0

// Pin Mapping for ADC1_DP0 signal
//   <o>    ADC1_DP0<name=ADC1_DP0_PIN_SEL><constant>
//   <i>    Shows which pin ADC1_DP0 is mapped to
//   <info>  [ADC1_DP0]
//     <0=> ADC1_DP0<selection=ADC1_DP0_SIG_SEL,ADC1_DP0/ADC0_DP3/ADC1_SE0/ADC0_SE3>
//     <0=> Default
#define ADC1_DP0_PIN_SEL     0

// Pin Mapping for ADC1_DP1 signal
//   <o>    ADC1_DP1<name=ADC1_DP1_PIN_SEL><constant>
//   <i>    Shows which pin ADC1_DP1 is mapped to
//   <info>  [ADC1_DP1]
//     <0=> ADC1_DP1<selection=ADC1_DP1_SIG_SEL,ADC1_DP1/ADC0_DP2>
//     <0=> Default
#define ADC1_DP1_PIN_SEL     0

// Pin Mapping for ADC1_DP3 signal
//   <o>    ADC1_DP3<name=ADC1_DP3_PIN_SEL><constant>
//   <i>    Shows which pin ADC1_DP3 is mapped to
//   <info>  [ADC0_DP0]
//     <0=> ADC0_DP0<selection=ADC0_DP0_SIG_SEL,ADC0_DP0/ADC1_DP3/ADC0_SE0>
//     <0=> Default
#define ADC1_DP3_PIN_SEL     0

// Pin Mapping for ADC1_SE0 signal
//   <o>    ADC1_SE0<name=ADC1_SE0_PIN_SEL><constant>
//   <i>    Shows which pin ADC1_SE0 is mapped to
//   <info>  [ADC1_DP0]
//     <0=> ADC1_DP0<selection=ADC1_DP0_SIG_SEL,ADC1_DP0/ADC0_DP3/ADC1_SE0/ADC0_SE3>
//     <0=> Default
#define ADC1_SE0_PIN_SEL     0

// Pin Mapping for ADC1_SE4a signal
//   <o>    ADC1_SE4a<name=ADC1_SE4a_PIN_SEL>
//   <i>    Shows which pin ADC1_SE4a is mapped to
//   <info>  [PTE0]
//     <0=> Disabled
//     <1=> PTE0 (reset default)<selection=PTE0_SIG_SEL,ADC1_SE4a (reset default)>
//     <2=> PTE0<selection=PTE0_SIG_SEL,ADC1_SE4a>
//     <0=> Default
#define ADC1_SE4a_PIN_SEL    0

// Pin Mapping for ADC1_SE4b signal
//   <o>    ADC1_SE4b<name=ADC1_SE4b_PIN_SEL>
//   <i>    Shows which pin ADC1_SE4b is mapped to
//   <info>  [PTC8]
//     <0=> Disabled
//     <1=> PTC8 (reset default)<selection=PTC8_SIG_SEL,ADC1_SE4b/CMP0_IN2 (reset default)>
//     <2=> PTC8<selection=PTC8_SIG_SEL,ADC1_SE4b/CMP0_IN2>
//     <1=> Default
#define ADC1_SE4b_PIN_SEL    1

// Pin Mapping for ADC1_SE5a signal
//   <o>    ADC1_SE5a<name=ADC1_SE5a_PIN_SEL>
//   <i>    Shows which pin ADC1_SE5a is mapped to
//   <info>  [PTE1]
//     <0=> Disabled
//     <1=> PTE1 (reset default)<selection=PTE1_SIG_SEL,ADC1_SE5a (reset default)>
//     <2=> PTE1<selection=PTE1_SIG_SEL,ADC1_SE5a>
//     <0=> Default
#define ADC1_SE5a_PIN_SEL    0

// Pin Mapping for ADC1_SE5b signal
//   <o>    ADC1_SE5b<name=ADC1_SE5b_PIN_SEL>
//   <i>    Shows which pin ADC1_SE5b is mapped to
//   <info>  [PTC9]
//     <0=> Disabled
//     <1=> PTC9 (reset default)<selection=PTC9_SIG_SEL,ADC1_SE5b/CMP0_IN3 (reset default)>
//     <2=> PTC9<selection=PTC9_SIG_SEL,ADC1_SE5b/CMP0_IN3>
//     <1=> Default
#define ADC1_SE5b_PIN_SEL    1

// Pin Mapping for ADC1_SE6a signal
//   <o>    ADC1_SE6a<name=ADC1_SE6a_PIN_SEL>
//   <i>    Shows which pin ADC1_SE6a is mapped to
//   <info>  [PTE2]
//     <0=> Disabled
//     <1=> PTE2 (reset default)<selection=PTE2_SIG_SEL,ADC1_SE6a (reset default)>
//     <2=> PTE2<selection=PTE2_SIG_SEL,ADC1_SE6a>
//     <1=> Default
#define ADC1_SE6a_PIN_SEL    1

// Pin Mapping for ADC1_SE6b signal
//   <o>    ADC1_SE6b<name=ADC1_SE6b_PIN_SEL>
//   <i>    Shows which pin ADC1_SE6b is mapped to
//   <info>  [PTC10]
//     <0=> Disabled
//     <1=> PTC10 (reset default)<selection=PTC10_SIG_SEL,ADC1_SE6b (reset default)>
//     <2=> PTC10<selection=PTC10_SIG_SEL,ADC1_SE6b>
//     <1=> Default
#define ADC1_SE6b_PIN_SEL    1

// Pin Mapping for ADC1_SE7a signal
//   <o>    ADC1_SE7a<name=ADC1_SE7a_PIN_SEL>
//   <i>    Shows which pin ADC1_SE7a is mapped to
//   <info>  [PTE3]
//     <0=> Disabled
//     <1=> PTE3 (reset default)<selection=PTE3_SIG_SEL,ADC1_SE7a (reset default)>
//     <2=> PTE3<selection=PTE3_SIG_SEL,ADC1_SE7a>
//     <1=> Default
#define ADC1_SE7a_PIN_SEL    1

// Pin Mapping for ADC1_SE7b signal
//   <o>    ADC1_SE7b<name=ADC1_SE7b_PIN_SEL>
//   <i>    Shows which pin ADC1_SE7b is mapped to
//   <info>  [PTC11]
//     <0=> Disabled
//     <1=> PTC11 (reset default)<selection=PTC11_SIG_SEL,ADC1_SE7b (reset default)>
//     <2=> PTC11<selection=PTC11_SIG_SEL,ADC1_SE7b>
//     <1=> Default
#define ADC1_SE7b_PIN_SEL    1

// Pin Mapping for ADC1_SE8 signal
//   <o>    ADC1_SE8<name=ADC1_SE8_PIN_SEL>
//   <i>    Shows which pin ADC1_SE8 is mapped to
//   <info>  [PTB0]
//     <0=> Disabled
//     <1=> PTB0 (reset default)<selection=PTB0_SIG_SEL,ADC0_SE8/ADC1_SE8 (reset default)>
//     <2=> PTB0<selection=PTB0_SIG_SEL,ADC0_SE8/ADC1_SE8>
//     <2=> Default
#define ADC1_SE8_PIN_SEL     2

// Pin Mapping for ADC1_SE9 signal
//   <o>    ADC1_SE9<name=ADC1_SE9_PIN_SEL>
//   <i>    Shows which pin ADC1_SE9 is mapped to
//   <info>  [PTB1]
//     <0=> Disabled
//     <1=> PTB1 (reset default)<selection=PTB1_SIG_SEL,ADC0_SE9/ADC1_SE9 (reset default)>
//     <2=> PTB1<selection=PTB1_SIG_SEL,ADC0_SE9/ADC1_SE9>
//     <2=> Default
#define ADC1_SE9_PIN_SEL     2

// Pin Mapping for ADC1_SE12 signal
//   <o>    ADC1_SE12<name=ADC1_SE12_PIN_SEL>
//   <i>    Shows which pin ADC1_SE12 is mapped to
//   <info>  [PTB6]
//     <0=> Disabled
//     <1=> PTB6 (reset default)<selection=PTB6_SIG_SEL,ADC1_SE12 (reset default)>
//     <2=> PTB6<selection=PTB6_SIG_SEL,ADC1_SE12>
//     <1=> Default
#define ADC1_SE12_PIN_SEL    1

// Pin Mapping for ADC1_SE13 signal
//   <o>    ADC1_SE13<name=ADC1_SE13_PIN_SEL>
//   <i>    Shows which pin ADC1_SE13 is mapped to
//   <info>  [PTB7]
//     <0=> Disabled
//     <1=> PTB7 (reset default)<selection=PTB7_SIG_SEL,ADC1_SE13 (reset default)>
//     <2=> PTB7<selection=PTB7_SIG_SEL,ADC1_SE13>
//     <1=> Default
#define ADC1_SE13_PIN_SEL    1

// Pin Mapping for ADC1_SE14 signal
//   <o>    ADC1_SE14<name=ADC1_SE14_PIN_SEL>
//   <i>    Shows which pin ADC1_SE14 is mapped to
//   <info>  [PTB10]
//     <0=> Disabled
//     <1=> PTB10 (reset default)<selection=PTB10_SIG_SEL,ADC1_SE14 (reset default)>
//     <2=> PTB10<selection=PTB10_SIG_SEL,ADC1_SE14>
//     <1=> Default
#define ADC1_SE14_PIN_SEL    1

// Pin Mapping for ADC1_SE15 signal
//   <o>    ADC1_SE15<name=ADC1_SE15_PIN_SEL>
//   <i>    Shows which pin ADC1_SE15 is mapped to
//   <info>  [PTB11]
//     <0=> Disabled
//     <1=> PTB11 (reset default)<selection=PTB11_SIG_SEL,ADC1_SE15 (reset default)>
//     <2=> PTB11<selection=PTB11_SIG_SEL,ADC1_SE15>
//     <1=> Default
#define ADC1_SE15_PIN_SEL    1

// Pin Mapping for ADC1_SE16 signal
//   <o>    ADC1_SE16<name=ADC1_SE16_PIN_SEL><constant>
//   <i>    Shows which pin ADC1_SE16 is mapped to
//   <info>  [ADC1_SE16]
//     <0=> ADC1_SE16<selection=ADC1_SE16_SIG_SEL,ADC1_SE16/ADC0_SE22>
//     <0=> Default
#define ADC1_SE16_PIN_SEL    0

// Pin Mapping for ADC1_SE17 signal
//   <o>    ADC1_SE17<name=ADC1_SE17_PIN_SEL>
//   <i>    Shows which pin ADC1_SE17 is mapped to
//   <info>  [PTA17]
//     <0=> Disabled
//     <1=> PTA17 (reset default)<selection=PTA17_SIG_SEL,ADC1_SE17 (reset default)>
//     <2=> PTA17<selection=PTA17_SIG_SEL,ADC1_SE17>
//     <1=> Default
#define ADC1_SE17_PIN_SEL    1

// Pin Mapping for ADC1_SE18 signal
//   <o>    ADC1_SE18<name=ADC1_SE18_PIN_SEL><constant>
//   <i>    Shows which pin ADC1_SE18 is mapped to
//   <info>  [VREF_OUT]
//     <0=> VREF_OUT<selection=VREF_OUT_SIG_SEL,VREF_OUT/CMP1_IN5/CMP0_IN5/ADC1_SE18>
//     <0=> Default
#define ADC1_SE18_PIN_SEL    0

// Pin Mapping for ADC1_SE19 signal
//   <o>    ADC1_SE19<name=ADC1_SE19_PIN_SEL><constant>
//   <i>    Shows which pin ADC1_SE19 is mapped to
//   <info>  [ADC1_DM0]
//     <0=> ADC1_DM0<selection=ADC1_DM0_SIG_SEL,ADC1_DM0/ADC0_DM3/ADC1_SE19>
//     <0=> Default
#define ADC1_SE19_PIN_SEL    0

// Pin Mapping for ADC1_SE23 signal
//   <o>    ADC1_SE23<name=ADC1_SE23_PIN_SEL><constant>
//   <i>    Shows which pin ADC1_SE23 is mapped to
//   <info>  [DAC1_OUT]
//     <0=> DAC1_OUT<selection=DAC1_OUT_SIG_SEL,DAC1_OUT/CMP0_IN4/ADC1_SE23>
//     <0=> Default
#define ADC1_SE23_PIN_SEL    0

// </h>

// <h> Clock and Timing

// Pin Mapping for CLKOUT signal
//   <o>    CLKOUT<name=CLKOUT_PIN_SEL>
//   <i>    Shows which pin CLKOUT is mapped to
//   <info>  [PTC3]
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,CLKOUT>
//     <0=> Default
#define CLKOUT_PIN_SEL       0

// Pin Mapping for CLKOUT32K signal
//   <o>    CLKOUT32K<name=CLKOUT32K_PIN_SEL>
//   <i>    Shows which pin CLKOUT32K is mapped to
//   <info>  [PTE0, PTE26]
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,GPIOE_0/CLKOUT32K>
//     <2=> PTE26<selection=PTE26_SIG_SEL,GPIOE_26/CLKOUT32K>
//     <0=> Default
#define CLKOUT32K_PIN_SEL    0

// Pin Mapping for EXTAL0 signal
//   <o>    EXTAL0<name=EXTAL0_PIN_SEL>
//   <i>    Shows which pin EXTAL0 is mapped to
//   <info>  [PTA18]
//     <0=> Disabled
//     <1=> PTA18 (reset default)<selection=PTA18_SIG_SEL,EXTAL0 (reset default)>
//     <2=> PTA18<selection=PTA18_SIG_SEL,EXTAL0>
//     <2=> Default
#define EXTAL0_PIN_SEL       2

// Pin Mapping for FTM_CLKIN0 signal
//   <o>    FTM_CLKIN0<name=FTM_CLKIN0_PIN_SEL>
//   <i>    Shows which pin FTM_CLKIN0 is mapped to
//   <info>  [PTA18, PTB16]
//     <0=> Disabled
//     <1=> PTA18<selection=PTA18_SIG_SEL,FTM_CLKIN0>
//     <2=> PTB16<selection=PTB16_SIG_SEL,FTM_CLKIN0>
//     <0=> Default
#define FTM_CLKIN0_PIN_SEL   0

// Pin Mapping for FTM_CLKIN1 signal
//   <o>    FTM_CLKIN1<name=FTM_CLKIN1_PIN_SEL>
//   <i>    Shows which pin FTM_CLKIN1 is mapped to
//   <info>  [PTA19, PTB17]
//     <0=> Disabled
//     <1=> PTA19<selection=PTA19_SIG_SEL,FTM_CLKIN1>
//     <2=> PTB17<selection=PTB17_SIG_SEL,FTM_CLKIN1>
//     <0=> Default
#define FTM_CLKIN1_PIN_SEL   0

// Pin Mapping for RTC_CLKOUT signal
//   <o>    RTC_CLKOUT<name=RTC_CLKOUT_PIN_SEL>
//   <i>    Shows which pin RTC_CLKOUT is mapped to
//   <info>  [PTE26, PTE0]
//     <0=> Disabled
//     <1=> PTE26<selection=PTE26_SIG_SEL,RTC_CLKOUT>
//     <2=> PTE0<selection=PTE0_SIG_SEL,RTC_CLKOUT>
//     <0=> Default
#define RTC_CLKOUT_PIN_SEL   0

// Pin Mapping for XTAL0 signal
//   <o>    XTAL0<name=XTAL0_PIN_SEL>
//   <i>    Shows which pin XTAL0 is mapped to
//   <info>  [PTA19]
//     <0=> Disabled
//     <1=> PTA19 (reset default)<selection=PTA19_SIG_SEL,XTAL0 (reset default)>
//     <2=> PTA19<selection=PTA19_SIG_SEL,XTAL0>
//     <2=> Default
#define XTAL0_PIN_SEL        2

// </h>

// <h> Analogue Comparator (CMP0)

// Pin Mapping for CMP0_IN0 signal
//   <o>    CMP0_IN0<name=CMP0_IN0_PIN_SEL>
//   <i>    Shows which pin CMP0_IN0 is mapped to
//   <info>  [PTC6]
//     <0=> Disabled
//     <1=> PTC6 (reset default)<selection=PTC6_SIG_SEL,CMP0_IN0 (reset default)>
//     <2=> PTC6<selection=PTC6_SIG_SEL,CMP0_IN0>
//     <0=> Default
#define CMP0_IN0_PIN_SEL     0

// Pin Mapping for CMP0_IN1 signal
//   <o>    CMP0_IN1<name=CMP0_IN1_PIN_SEL>
//   <i>    Shows which pin CMP0_IN1 is mapped to
//   <info>  [PTC7]
//     <0=> Disabled
//     <1=> PTC7 (reset default)<selection=PTC7_SIG_SEL,CMP0_IN1 (reset default)>
//     <2=> PTC7<selection=PTC7_SIG_SEL,CMP0_IN1>
//     <1=> Default
#define CMP0_IN1_PIN_SEL     1

// Pin Mapping for CMP0_IN2 signal
//   <o>    CMP0_IN2<name=CMP0_IN2_PIN_SEL>
//   <i>    Shows which pin CMP0_IN2 is mapped to
//   <info>  [PTC8]
//     <0=> Disabled
//     <1=> PTC8 (reset default)<selection=PTC8_SIG_SEL,ADC1_SE4b/CMP0_IN2 (reset default)>
//     <2=> PTC8<selection=PTC8_SIG_SEL,ADC1_SE4b/CMP0_IN2>
//     <1=> Default
#define CMP0_IN2_PIN_SEL     1

// Pin Mapping for CMP0_IN3 signal
//   <o>    CMP0_IN3<name=CMP0_IN3_PIN_SEL>
//   <i>    Shows which pin CMP0_IN3 is mapped to
//   <info>  [PTC9]
//     <0=> Disabled
//     <1=> PTC9 (reset default)<selection=PTC9_SIG_SEL,ADC1_SE5b/CMP0_IN3 (reset default)>
//     <2=> PTC9<selection=PTC9_SIG_SEL,ADC1_SE5b/CMP0_IN3>
//     <1=> Default
#define CMP0_IN3_PIN_SEL     1

// Pin Mapping for CMP0_IN4 signal
//   <o>    CMP0_IN4<name=CMP0_IN4_PIN_SEL><constant>
//   <i>    Shows which pin CMP0_IN4 is mapped to
//   <info>  [DAC1_OUT]
//     <0=> DAC1_OUT<selection=DAC1_OUT_SIG_SEL,DAC1_OUT/CMP0_IN4/ADC1_SE23>
//     <0=> Default
#define CMP0_IN4_PIN_SEL     0

// Pin Mapping for CMP0_IN5 signal
//   <o>    CMP0_IN5<name=CMP0_IN5_PIN_SEL><constant>
//   <i>    Shows which pin CMP0_IN5 is mapped to
//   <info>  [VREF_OUT]
//     <0=> VREF_OUT<selection=VREF_OUT_SIG_SEL,VREF_OUT/CMP1_IN5/CMP0_IN5/ADC1_SE18>
//     <0=> Default
#define CMP0_IN5_PIN_SEL     0

// Pin Mapping for CMP0_OUT signal
//   <o>    CMP0_OUT<name=CMP0_OUT_PIN_SEL>
//   <i>    Shows which pin CMP0_OUT is mapped to
//   <info>  [PTB20, PTC5]
//     <0=> Disabled
//     <1=> PTB20<selection=PTB20_SIG_SEL,CMP0_OUT>
//     <2=> PTC5<selection=PTC5_SIG_SEL,CMP0_OUT>
//     <0=> Default
#define CMP0_OUT_PIN_SEL     0

// </h>

// <h> Analogue Comparator (CMP1)

// Pin Mapping for CMP1_IN0 signal
//   <o>    CMP1_IN0<name=CMP1_IN0_PIN_SEL>
//   <i>    Shows which pin CMP1_IN0 is mapped to
//   <info>  [PTC2]
//     <0=> Disabled
//     <1=> PTC2 (reset default)<selection=PTC2_SIG_SEL,ADC0_SE4b/CMP1_IN0 (reset default)>
//     <2=> PTC2<selection=PTC2_SIG_SEL,ADC0_SE4b/CMP1_IN0>
//     <2=> Default
#define CMP1_IN0_PIN_SEL     2

// Pin Mapping for CMP1_IN1 signal
//   <o>    CMP1_IN1<name=CMP1_IN1_PIN_SEL>
//   <i>    Shows which pin CMP1_IN1 is mapped to
//   <info>  [PTC3]
//     <0=> Disabled
//     <1=> PTC3 (reset default)<selection=PTC3_SIG_SEL,CMP1_IN1 (reset default)>
//     <2=> PTC3<selection=PTC3_SIG_SEL,CMP1_IN1>
//     <0=> Default
#define CMP1_IN1_PIN_SEL     0

// Pin Mapping for CMP1_IN2 signal
//   <o>    CMP1_IN2<name=CMP1_IN2_PIN_SEL><constant>
//   <i>    Shows which pin CMP1_IN2 is mapped to
//   <info>  [ADC0_SE16]
//     <0=> ADC0_SE16<selection=ADC0_SE16_SIG_SEL,ADC0_SE16/CMP1_IN2/ADC0_SE21>
//     <0=> Default
#define CMP1_IN2_PIN_SEL     0

// Pin Mapping for CMP1_IN3 signal
//   <o>    CMP1_IN3<name=CMP1_IN3_PIN_SEL><constant>
//   <i>    Shows which pin CMP1_IN3 is mapped to
//   <info>  [DAC0_OUT]
//     <0=> DAC0_OUT<selection=DAC0_OUT_SIG_SEL,DAC0_OUT/CMP1_IN3/ADC0_SE23>
//     <0=> Default
#define CMP1_IN3_PIN_SEL     0

// Pin Mapping for CMP1_IN5 signal
//   <o>    CMP1_IN5<name=CMP1_IN5_PIN_SEL><constant>
//   <i>    Shows which pin CMP1_IN5 is mapped to
//   <info>  [VREF_OUT]
//     <0=> VREF_OUT<selection=VREF_OUT_SIG_SEL,VREF_OUT/CMP1_IN5/CMP0_IN5/ADC1_SE18>
//     <0=> Default
#define CMP1_IN5_PIN_SEL     0

// Pin Mapping for CMP1_OUT signal
//   <o>    CMP1_OUT<name=CMP1_OUT_PIN_SEL>
//   <i>    Shows which pin CMP1_OUT is mapped to
//   <info>  [PTB21, PTC4]
//     <0=> Disabled
//     <1=> PTB21<selection=PTB21_SIG_SEL,CMP1_OUT>
//     <2=> PTC4<selection=PTC4_SIG_SEL,CMP1_OUT>
//     <0=> Default
#define CMP1_OUT_PIN_SEL     0

// </h>

// <h> Digital to Analogue (DAC0)

// Pin Mapping for DAC0_OUT signal
//   <o>    DAC0_OUT<name=DAC0_OUT_PIN_SEL><constant>
//   <i>    Shows which pin DAC0_OUT is mapped to
//   <info>  [DAC0_OUT]
//     <0=> DAC0_OUT<selection=DAC0_OUT_SIG_SEL,DAC0_OUT/CMP1_IN3/ADC0_SE23>
//     <0=> Default
#define DAC0_OUT_PIN_SEL     0

// </h>

// <h> Digital to Analogue (DAC1)

// Pin Mapping for DAC1_OUT signal
//   <o>    DAC1_OUT<name=DAC1_OUT_PIN_SEL><constant>
//   <i>    Shows which pin DAC1_OUT is mapped to
//   <info>  [DAC1_OUT]
//     <0=> DAC1_OUT<selection=DAC1_OUT_SIG_SEL,DAC1_OUT/CMP0_IN4/ADC1_SE23>
//     <0=> Default
#define DAC1_OUT_PIN_SEL     0

// </h>

// <h> External Watchdog Monitor (EWM)

// Pin Mapping for EWM_IN signal
//   <o>    EWM_IN<name=EWM_IN_PIN_SEL>
//   <i>    Shows which pin EWM_IN is mapped to
//   <info>  [PTB16, PTD4, PTE25]
//     <0=> Disabled
//     <1=> PTB16<selection=PTB16_SIG_SEL,EWM_IN>
//     <2=> PTD4<selection=PTD4_SIG_SEL,EWM_IN>
//     <3=> PTE25<selection=PTE25_SIG_SEL,EWM_IN>
//     <0=> Default
#define EWM_IN_PIN_SEL       0

// Pin Mapping for EWM_OUT_b signal
//   <o>    EWM_OUT_b<name=EWM_OUT_b_PIN_SEL>
//   <i>    Shows which pin EWM_OUT_b is mapped to
//   <info>  [PTB17, PTD5, PTE24]
//     <0=> Disabled
//     <1=> PTB17<selection=PTB17_SIG_SEL,EWM_OUT_b>
//     <2=> PTD5<selection=PTD5_SIG_SEL,EWM_OUT_b>
//     <3=> PTE24<selection=PTE24_SIG_SEL,EWM_OUT_b>
//     <0=> Default
#define EWM_OUT_b_PIN_SEL    0

// </h>

// <h> Flexbus

// Pin Mapping for FB_A16 signal
//   <o>    FB_A16<name=FB_A16_PIN_SEL>
//   <i>    Shows which pin FB_A16 is mapped to
//   <info>  [PTD8]
//     <0=> Disabled
//     <1=> PTD8<selection=PTD8_SIG_SEL,FB_A16>
//     <0=> Default
#define FB_A16_PIN_SEL       0

// Pin Mapping for FB_A17 signal
//   <o>    FB_A17<name=FB_A17_PIN_SEL>
//   <i>    Shows which pin FB_A17 is mapped to
//   <info>  [PTD9]
//     <0=> Disabled
//     <1=> PTD9<selection=PTD9_SIG_SEL,FB_A17>
//     <0=> Default
#define FB_A17_PIN_SEL       0

// Pin Mapping for FB_A18 signal
//   <o>    FB_A18<name=FB_A18_PIN_SEL>
//   <i>    Shows which pin FB_A18 is mapped to
//   <info>  [PTD10]
//     <0=> Disabled
//     <1=> PTD10<selection=PTD10_SIG_SEL,FB_A18>
//     <0=> Default
#define FB_A18_PIN_SEL       0

// Pin Mapping for FB_A19 signal
//   <o>    FB_A19<name=FB_A19_PIN_SEL>
//   <i>    Shows which pin FB_A19 is mapped to
//   <info>  [PTD11]
//     <0=> Disabled
//     <1=> PTD11<selection=PTD11_SIG_SEL,FB_A19>
//     <0=> Default
#define FB_A19_PIN_SEL       0

// Pin Mapping for FB_A20 signal
//   <o>    FB_A20<name=FB_A20_PIN_SEL>
//   <i>    Shows which pin FB_A20 is mapped to
//   <info>  [PTD12]
//     <0=> Disabled
//     <1=> PTD12<selection=PTD12_SIG_SEL,FB_A20>
//     <0=> Default
#define FB_A20_PIN_SEL       0

// Pin Mapping for FB_A21 signal
//   <o>    FB_A21<name=FB_A21_PIN_SEL>
//   <i>    Shows which pin FB_A21 is mapped to
//   <info>  [PTD13]
//     <0=> Disabled
//     <1=> PTD13<selection=PTD13_SIG_SEL,FB_A21>
//     <0=> Default
#define FB_A21_PIN_SEL       0

// Pin Mapping for FB_A22 signal
//   <o>    FB_A22<name=FB_A22_PIN_SEL>
//   <i>    Shows which pin FB_A22 is mapped to
//   <info>  [PTD14]
//     <0=> Disabled
//     <1=> PTD14<selection=PTD14_SIG_SEL,FB_A22>
//     <0=> Default
#define FB_A22_PIN_SEL       0

// Pin Mapping for FB_A23 signal
//   <o>    FB_A23<name=FB_A23_PIN_SEL>
//   <i>    Shows which pin FB_A23 is mapped to
//   <info>  [PTD15]
//     <0=> Disabled
//     <1=> PTD15<selection=PTD15_SIG_SEL,FB_A23>
//     <0=> Default
#define FB_A23_PIN_SEL       0

// Pin Mapping for FB_A24 signal
//   <o>    FB_A24<name=FB_A24_PIN_SEL>
//   <i>    Shows which pin FB_A24 is mapped to
//   <info>  [PTA29]
//     <0=> Disabled
//     <1=> PTA29<selection=PTA29_SIG_SEL,FB_A24>
//     <0=> Default
#define FB_A24_PIN_SEL       0

// Pin Mapping for FB_AD0 signal
//   <o>    FB_AD0<name=FB_AD0_PIN_SEL>
//   <i>    Shows which pin FB_AD0 is mapped to
//   <info>  [PTD6]
//     <0=> Disabled
//     <1=> PTD6<selection=PTD6_SIG_SEL,FB_AD0>
//     <0=> Default
#define FB_AD0_PIN_SEL       0

// Pin Mapping for FB_AD1 signal
//   <o>    FB_AD1<name=FB_AD1_PIN_SEL>
//   <i>    Shows which pin FB_AD1 is mapped to
//   <info>  [PTD5]
//     <0=> Disabled
//     <1=> PTD5<selection=PTD5_SIG_SEL,FB_AD1>
//     <0=> Default
#define FB_AD1_PIN_SEL       0

// Pin Mapping for FB_AD2 signal
//   <o>    FB_AD2<name=FB_AD2_PIN_SEL>
//   <i>    Shows which pin FB_AD2 is mapped to
//   <info>  [PTD4]
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,FB_AD2>
//     <0=> Default
#define FB_AD2_PIN_SEL       0

// Pin Mapping for FB_AD3 signal
//   <o>    FB_AD3<name=FB_AD3_PIN_SEL>
//   <i>    Shows which pin FB_AD3 is mapped to
//   <info>  [PTD3]
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,FB_AD3>
//     <0=> Default
#define FB_AD3_PIN_SEL       0

// Pin Mapping for FB_AD4 signal
//   <o>    FB_AD4<name=FB_AD4_PIN_SEL>
//   <i>    Shows which pin FB_AD4 is mapped to
//   <info>  [PTD2]
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,FB_AD4>
//     <0=> Default
#define FB_AD4_PIN_SEL       0

// Pin Mapping for FB_AD5 signal
//   <o>    FB_AD5<name=FB_AD5_PIN_SEL>
//   <i>    Shows which pin FB_AD5 is mapped to
//   <info>  [PTC10]
//     <0=> Disabled
//     <1=> PTC10<selection=PTC10_SIG_SEL,FB_AD5>
//     <0=> Default
#define FB_AD5_PIN_SEL       0

// Pin Mapping for FB_AD6 signal
//   <o>    FB_AD6<name=FB_AD6_PIN_SEL>
//   <i>    Shows which pin FB_AD6 is mapped to
//   <info>  [PTC9]
//     <0=> Disabled
//     <1=> PTC9<selection=PTC9_SIG_SEL,FB_AD6>
//     <0=> Default
#define FB_AD6_PIN_SEL       0

// Pin Mapping for FB_AD7 signal
//   <o>    FB_AD7<name=FB_AD7_PIN_SEL>
//   <i>    Shows which pin FB_AD7 is mapped to
//   <info>  [PTC8]
//     <0=> Disabled
//     <1=> PTC8<selection=PTC8_SIG_SEL,FB_AD7>
//     <0=> Default
#define FB_AD7_PIN_SEL       0

// Pin Mapping for FB_AD8 signal
//   <o>    FB_AD8<name=FB_AD8_PIN_SEL>
//   <i>    Shows which pin FB_AD8 is mapped to
//   <info>  [PTC7]
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,FB_AD8>
//     <0=> Default
#define FB_AD8_PIN_SEL       0

// Pin Mapping for FB_AD9 signal
//   <o>    FB_AD9<name=FB_AD9_PIN_SEL>
//   <i>    Shows which pin FB_AD9 is mapped to
//   <info>  [PTC6]
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,FB_AD9>
//     <0=> Default
#define FB_AD9_PIN_SEL       0

// Pin Mapping for FB_AD10 signal
//   <o>    FB_AD10<name=FB_AD10_PIN_SEL>
//   <i>    Shows which pin FB_AD10 is mapped to
//   <info>  [PTC5]
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,FB_AD10>
//     <0=> Default
#define FB_AD10_PIN_SEL      0

// Pin Mapping for FB_AD11 signal
//   <o>    FB_AD11<name=FB_AD11_PIN_SEL>
//   <i>    Shows which pin FB_AD11 is mapped to
//   <info>  [PTC4]
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,FB_AD11>
//     <0=> Default
#define FB_AD11_PIN_SEL      0

// Pin Mapping for FB_AD12 signal
//   <o>    FB_AD12<name=FB_AD12_PIN_SEL>
//   <i>    Shows which pin FB_AD12 is mapped to
//   <info>  [PTC2]
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,FB_AD12>
//     <0=> Default
#define FB_AD12_PIN_SEL      0

// Pin Mapping for FB_AD13 signal
//   <o>    FB_AD13<name=FB_AD13_PIN_SEL>
//   <i>    Shows which pin FB_AD13 is mapped to
//   <info>  [PTC1]
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,FB_AD13>
//     <0=> Default
#define FB_AD13_PIN_SEL      0

// Pin Mapping for FB_AD14 signal
//   <o>    FB_AD14<name=FB_AD14_PIN_SEL>
//   <i>    Shows which pin FB_AD14 is mapped to
//   <info>  [PTC0]
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,FB_AD14>
//     <0=> Default
#define FB_AD14_PIN_SEL      0

// Pin Mapping for FB_AD15 signal
//   <o>    FB_AD15<name=FB_AD15_PIN_SEL>
//   <i>    Shows which pin FB_AD15 is mapped to
//   <info>  [PTB18]
//     <0=> Disabled
//     <1=> PTB18<selection=PTB18_SIG_SEL,FB_AD15>
//     <0=> Default
#define FB_AD15_PIN_SEL      0

// Pin Mapping for FB_AD16 signal
//   <o>    FB_AD16<name=FB_AD16_PIN_SEL>
//   <i>    Shows which pin FB_AD16 is mapped to
//   <info>  [PTB17]
//     <0=> Disabled
//     <1=> PTB17<selection=PTB17_SIG_SEL,FB_AD16>
//     <0=> Default
#define FB_AD16_PIN_SEL      0

// Pin Mapping for FB_AD17 signal
//   <o>    FB_AD17<name=FB_AD17_PIN_SEL>
//   <i>    Shows which pin FB_AD17 is mapped to
//   <info>  [PTB16]
//     <0=> Disabled
//     <1=> PTB16<selection=PTB16_SIG_SEL,FB_AD17>
//     <0=> Default
#define FB_AD17_PIN_SEL      0

// Pin Mapping for FB_AD18 signal
//   <o>    FB_AD18<name=FB_AD18_PIN_SEL>
//   <i>    Shows which pin FB_AD18 is mapped to
//   <info>  [PTB11]
//     <0=> Disabled
//     <1=> PTB11<selection=PTB11_SIG_SEL,FB_AD18>
//     <0=> Default
#define FB_AD18_PIN_SEL      0

// Pin Mapping for FB_AD19 signal
//   <o>    FB_AD19<name=FB_AD19_PIN_SEL>
//   <i>    Shows which pin FB_AD19 is mapped to
//   <info>  [PTB10]
//     <0=> Disabled
//     <1=> PTB10<selection=PTB10_SIG_SEL,FB_AD19>
//     <0=> Default
#define FB_AD19_PIN_SEL      0

// Pin Mapping for FB_AD20 signal
//   <o>    FB_AD20<name=FB_AD20_PIN_SEL>
//   <i>    Shows which pin FB_AD20 is mapped to
//   <info>  [PTB9]
//     <0=> Disabled
//     <1=> PTB9<selection=PTB9_SIG_SEL,FB_AD20>
//     <0=> Default
#define FB_AD20_PIN_SEL      0

// Pin Mapping for FB_AD21 signal
//   <o>    FB_AD21<name=FB_AD21_PIN_SEL>
//   <i>    Shows which pin FB_AD21 is mapped to
//   <info>  [PTB8]
//     <0=> Disabled
//     <1=> PTB8<selection=PTB8_SIG_SEL,FB_AD21>
//     <0=> Default
#define FB_AD21_PIN_SEL      0

// Pin Mapping for FB_AD22 signal
//   <o>    FB_AD22<name=FB_AD22_PIN_SEL>
//   <i>    Shows which pin FB_AD22 is mapped to
//   <info>  [PTB7]
//     <0=> Disabled
//     <1=> PTB7<selection=PTB7_SIG_SEL,FB_AD22>
//     <0=> Default
#define FB_AD22_PIN_SEL      0

// Pin Mapping for FB_AD23 signal
//   <o>    FB_AD23<name=FB_AD23_PIN_SEL>
//   <i>    Shows which pin FB_AD23 is mapped to
//   <info>  [PTB6]
//     <0=> Disabled
//     <1=> PTB6<selection=PTB6_SIG_SEL,FB_AD23>
//     <0=> Default
#define FB_AD23_PIN_SEL      0

// Pin Mapping for FB_AD24 signal
//   <o>    FB_AD24<name=FB_AD24_PIN_SEL>
//   <i>    Shows which pin FB_AD24 is mapped to
//   <info>  [PTC15]
//     <0=> Disabled
//     <1=> PTC15<selection=PTC15_SIG_SEL,FB_AD24>
//     <0=> Default
#define FB_AD24_PIN_SEL      0

// Pin Mapping for FB_AD25 signal
//   <o>    FB_AD25<name=FB_AD25_PIN_SEL>
//   <i>    Shows which pin FB_AD25 is mapped to
//   <info>  [PTC14]
//     <0=> Disabled
//     <1=> PTC14<selection=PTC14_SIG_SEL,FB_AD25>
//     <0=> Default
#define FB_AD25_PIN_SEL      0

// Pin Mapping for FB_AD26 signal
//   <o>    FB_AD26<name=FB_AD26_PIN_SEL>
//   <i>    Shows which pin FB_AD26 is mapped to
//   <info>  [PTC13]
//     <0=> Disabled
//     <1=> PTC13<selection=PTC13_SIG_SEL,FB_AD26>
//     <0=> Default
#define FB_AD26_PIN_SEL      0

// Pin Mapping for FB_AD27 signal
//   <o>    FB_AD27<name=FB_AD27_PIN_SEL>
//   <i>    Shows which pin FB_AD27 is mapped to
//   <info>  [PTC12]
//     <0=> Disabled
//     <1=> PTC12<selection=PTC12_SIG_SEL,FB_AD27>
//     <0=> Default
#define FB_AD27_PIN_SEL      0

// Pin Mapping for FB_AD28 signal
//   <o>    FB_AD28<name=FB_AD28_PIN_SEL>
//   <i>    Shows which pin FB_AD28 is mapped to
//   <info>  [PTB23]
//     <0=> Disabled
//     <1=> PTB23<selection=PTB23_SIG_SEL,FB_AD28>
//     <0=> Default
#define FB_AD28_PIN_SEL      0

// Pin Mapping for FB_AD29 signal
//   <o>    FB_AD29<name=FB_AD29_PIN_SEL>
//   <i>    Shows which pin FB_AD29 is mapped to
//   <info>  [PTB22]
//     <0=> Disabled
//     <1=> PTB22<selection=PTB22_SIG_SEL,FB_AD29>
//     <0=> Default
#define FB_AD29_PIN_SEL      0

// Pin Mapping for FB_AD30 signal
//   <o>    FB_AD30<name=FB_AD30_PIN_SEL>
//   <i>    Shows which pin FB_AD30 is mapped to
//   <info>  [PTB21]
//     <0=> Disabled
//     <1=> PTB21<selection=PTB21_SIG_SEL,FB_AD30>
//     <0=> Default
#define FB_AD30_PIN_SEL      0

// Pin Mapping for FB_AD31 signal
//   <o>    FB_AD31<name=FB_AD31_PIN_SEL>
//   <i>    Shows which pin FB_AD31 is mapped to
//   <info>  [PTB20]
//     <0=> Disabled
//     <1=> PTB20<selection=PTB20_SIG_SEL,FB_AD31>
//     <0=> Default
#define FB_AD31_PIN_SEL      0

// Pin Mapping for FB_ALE signal
//   <o>    FB_ALE<name=FB_ALE_PIN_SEL>
//   <i>    Shows which pin FB_ALE is mapped to
//   <info>  [PTD0]
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,FB_ALE/FB_CS1_b/FB_TS_b>
//     <0=> Default
#define FB_ALE_PIN_SEL       0

// Pin Mapping for FB_BE7_0_BLS31_24_b signal
//   <o>    FB_BE7_0_BLS31_24_b<name=FB_BE7_0_BLS31_24_b_PIN_SEL>
//   <i>    Shows which pin FB_BE7_0_BLS31_24_b is mapped to
//   <info>  [PTC19]
//     <0=> Disabled
//     <1=> PTC19<selection=PTC19_SIG_SEL,FB_CS3_b/FB_BE7_0_BLS31_24_b>
//     <0=> Default
#define FB_BE7_0_BLS31_24_b_PIN_SEL 0

// Pin Mapping for FB_BE15_8_BLS23_16_b signal
//   <o>    FB_BE15_8_BLS23_16_b<name=FB_BE15_8_BLS23_16_b_PIN_SEL>
//   <i>    Shows which pin FB_BE15_8_BLS23_16_b is mapped to
//   <info>  [PTC18]
//     <0=> Disabled
//     <1=> PTC18<selection=PTC18_SIG_SEL,FB_TBST_b/FB_CS2_b/FB_BE15_8_BLS23_16_b>
//     <0=> Default
#define FB_BE15_8_BLS23_16_b_PIN_SEL 0

// Pin Mapping for FB_BE23_16_BLS15_8_b signal
//   <o>    FB_BE23_16_BLS15_8_b<name=FB_BE23_16_BLS15_8_b_PIN_SEL>
//   <i>    Shows which pin FB_BE23_16_BLS15_8_b is mapped to
//   <info>  [PTC16]
//     <0=> Disabled
//     <1=> PTC16<selection=PTC16_SIG_SEL,FB_CS5_b/FB_TSIZ1/FB_BE23_16_BLS15_8_b>
//     <0=> Default
#define FB_BE23_16_BLS15_8_b_PIN_SEL 0

// Pin Mapping for FB_BE31_24_BLS7_0_b signal
//   <o>    FB_BE31_24_BLS7_0_b<name=FB_BE31_24_BLS7_0_b_PIN_SEL>
//   <i>    Shows which pin FB_BE31_24_BLS7_0_b is mapped to
//   <info>  [PTC17]
//     <0=> Disabled
//     <1=> PTC17<selection=PTC17_SIG_SEL,FB_CS4_b/FB_TSIZ0/FB_BE31_24_BLS7_0_b>
//     <0=> Default
#define FB_BE31_24_BLS7_0_b_PIN_SEL 0

// Pin Mapping for FB_CS0_b signal
//   <o>    FB_CS0_b<name=FB_CS0_b_PIN_SEL>
//   <i>    Shows which pin FB_CS0_b is mapped to
//   <info>  [PTD1]
//     <0=> Disabled
//     <1=> PTD1<selection=PTD1_SIG_SEL,FB_CS0_b>
//     <0=> Default
#define FB_CS0_b_PIN_SEL     0

// Pin Mapping for FB_CS1_b signal
//   <o>    FB_CS1_b<name=FB_CS1_b_PIN_SEL>
//   <i>    Shows which pin FB_CS1_b is mapped to
//   <info>  [PTD0]
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,FB_ALE/FB_CS1_b/FB_TS_b>
//     <0=> Default
#define FB_CS1_b_PIN_SEL     0

// Pin Mapping for FB_CS2_b signal
//   <o>    FB_CS2_b<name=FB_CS2_b_PIN_SEL>
//   <i>    Shows which pin FB_CS2_b is mapped to
//   <info>  [PTC18]
//     <0=> Disabled
//     <1=> PTC18<selection=PTC18_SIG_SEL,FB_TBST_b/FB_CS2_b/FB_BE15_8_BLS23_16_b>
//     <0=> Default
#define FB_CS2_b_PIN_SEL     0

// Pin Mapping for FB_CS3_b signal
//   <o>    FB_CS3_b<name=FB_CS3_b_PIN_SEL>
//   <i>    Shows which pin FB_CS3_b is mapped to
//   <info>  [PTC19]
//     <0=> Disabled
//     <1=> PTC19<selection=PTC19_SIG_SEL,FB_CS3_b/FB_BE7_0_BLS31_24_b>
//     <0=> Default
#define FB_CS3_b_PIN_SEL     0

// Pin Mapping for FB_CS4_b signal
//   <o>    FB_CS4_b<name=FB_CS4_b_PIN_SEL>
//   <i>    Shows which pin FB_CS4_b is mapped to
//   <info>  [PTC17]
//     <0=> Disabled
//     <1=> PTC17<selection=PTC17_SIG_SEL,FB_CS4_b/FB_TSIZ0/FB_BE31_24_BLS7_0_b>
//     <0=> Default
#define FB_CS4_b_PIN_SEL     0

// Pin Mapping for FB_CS5_b signal
//   <o>    FB_CS5_b<name=FB_CS5_b_PIN_SEL>
//   <i>    Shows which pin FB_CS5_b is mapped to
//   <info>  [PTC16]
//     <0=> Disabled
//     <1=> PTC16<selection=PTC16_SIG_SEL,FB_CS5_b/FB_TSIZ1/FB_BE23_16_BLS15_8_b>
//     <0=> Default
#define FB_CS5_b_PIN_SEL     0

// Pin Mapping for FB_OE_b signal
//   <o>    FB_OE_b<name=FB_OE_b_PIN_SEL>
//   <i>    Shows which pin FB_OE_b is mapped to
//   <info>  [PTB19]
//     <0=> Disabled
//     <1=> PTB19<selection=PTB19_SIG_SEL,FB_OE_b>
//     <0=> Default
#define FB_OE_b_PIN_SEL      0

// Pin Mapping for FB_RW_b signal
//   <o>    FB_RW_b<name=FB_RW_b_PIN_SEL>
//   <i>    Shows which pin FB_RW_b is mapped to
//   <info>  [PTC11]
//     <0=> Disabled
//     <1=> PTC11<selection=PTC11_SIG_SEL,FB_RW_b>
//     <0=> Default
#define FB_RW_b_PIN_SEL      0

// Pin Mapping for FB_TA_b signal
//   <o>    FB_TA_b<name=FB_TA_b_PIN_SEL>
//   <i>    Shows which pin FB_TA_b is mapped to
//   <info>  [PTC19]
//     <0=> Disabled
//     <1=> PTC19<selection=PTC19_SIG_SEL,FB_TA_b>
//     <0=> Default
#define FB_TA_b_PIN_SEL      0

// Pin Mapping for FB_TBST_b signal
//   <o>    FB_TBST_b<name=FB_TBST_b_PIN_SEL>
//   <i>    Shows which pin FB_TBST_b is mapped to
//   <info>  [PTC18]
//     <0=> Disabled
//     <1=> PTC18<selection=PTC18_SIG_SEL,FB_TBST_b/FB_CS2_b/FB_BE15_8_BLS23_16_b>
//     <0=> Default
#define FB_TBST_b_PIN_SEL    0

// Pin Mapping for FB_TSIZ0 signal
//   <o>    FB_TSIZ0<name=FB_TSIZ0_PIN_SEL>
//   <i>    Shows which pin FB_TSIZ0 is mapped to
//   <info>  [PTC17]
//     <0=> Disabled
//     <1=> PTC17<selection=PTC17_SIG_SEL,FB_CS4_b/FB_TSIZ0/FB_BE31_24_BLS7_0_b>
//     <0=> Default
#define FB_TSIZ0_PIN_SEL     0

// Pin Mapping for FB_TSIZ1 signal
//   <o>    FB_TSIZ1<name=FB_TSIZ1_PIN_SEL>
//   <i>    Shows which pin FB_TSIZ1 is mapped to
//   <info>  [PTC16]
//     <0=> Disabled
//     <1=> PTC16<selection=PTC16_SIG_SEL,FB_CS5_b/FB_TSIZ1/FB_BE23_16_BLS15_8_b>
//     <0=> Default
#define FB_TSIZ1_PIN_SEL     0

// Pin Mapping for FB_TS_b signal
//   <o>    FB_TS_b<name=FB_TS_b_PIN_SEL>
//   <i>    Shows which pin FB_TS_b is mapped to
//   <info>  [PTD0]
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,FB_ALE/FB_CS1_b/FB_TS_b>
//     <0=> Default
#define FB_TS_b_PIN_SEL      0

// </h>

// <h> FlexTimer (FTM0)

// Pin Mapping for FTM0_CH0 signal
//   <o>    FTM0_CH0<name=FTM0_CH0_PIN_SEL>
//   <i>    Shows which pin FTM0_CH0 is mapped to
//   <info>  [PTA3, PTC1]
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,FTM0_CH0>
//     <2=> PTC1<selection=PTC1_SIG_SEL,FTM0_CH0>
//     <0=> Default
#define FTM0_CH0_PIN_SEL     0

// Pin Mapping for FTM0_CH1 signal
//   <o>    FTM0_CH1<name=FTM0_CH1_PIN_SEL>
//   <i>    Shows which pin FTM0_CH1 is mapped to
//   <info>  [PTA4, PTC2]
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,FTM0_CH1>
//     <2=> PTC2<selection=PTC2_SIG_SEL,FTM0_CH1>
//     <1=> Default
#define FTM0_CH1_PIN_SEL     1

// Pin Mapping for FTM0_CH2 signal
//   <o>    FTM0_CH2<name=FTM0_CH2_PIN_SEL>
//   <i>    Shows which pin FTM0_CH2 is mapped to
//   <info>  [PTA5, PTC3, PTC5]
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,FTM0_CH2>
//     <2=> PTC3<selection=PTC3_SIG_SEL,FTM0_CH2>
//     <3=> PTC5<selection=PTC5_SIG_SEL,FTM0_CH2>
//     <0=> Default
#define FTM0_CH2_PIN_SEL     0

// Pin Mapping for FTM0_CH3 signal
//   <o>    FTM0_CH3<name=FTM0_CH3_PIN_SEL>
//   <i>    Shows which pin FTM0_CH3 is mapped to
//   <info>  [PTC4]
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,FTM0_CH3>
//     <0=> Default
#define FTM0_CH3_PIN_SEL     0

// Pin Mapping for FTM0_CH4 signal
//   <o>    FTM0_CH4<name=FTM0_CH4_PIN_SEL>
//   <i>    Shows which pin FTM0_CH4 is mapped to
//   <info>  [PTD4]
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,FTM0_CH4>
//     <0=> Default
#define FTM0_CH4_PIN_SEL     0

// Pin Mapping for FTM0_CH5 signal
//   <o>    FTM0_CH5<name=FTM0_CH5_PIN_SEL>
//   <i>    Shows which pin FTM0_CH5 is mapped to
//   <info>  [PTA0, PTD5]
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,FTM0_CH5>
//     <2=> PTD5<selection=PTD5_SIG_SEL,FTM0_CH5>
//     <2=> Default
#define FTM0_CH5_PIN_SEL     2

// Pin Mapping for FTM0_CH6 signal
//   <o>    FTM0_CH6<name=FTM0_CH6_PIN_SEL>
//   <i>    Shows which pin FTM0_CH6 is mapped to
//   <info>  [PTA1, PTD6]
//     <0=> Disabled
//     <1=> PTA1<selection=PTA1_SIG_SEL,FTM0_CH6>
//     <2=> PTD6<selection=PTD6_SIG_SEL,FTM0_CH6>
//     <1=> Default
#define FTM0_CH6_PIN_SEL     1

// Pin Mapping for FTM0_CH7 signal
//   <o>    FTM0_CH7<name=FTM0_CH7_PIN_SEL>
//   <i>    Shows which pin FTM0_CH7 is mapped to
//   <info>  [PTA2, PTD7]
//     <0=> Disabled
//     <1=> PTA2<selection=PTA2_SIG_SEL,FTM0_CH7>
//     <2=> PTD7<selection=PTD7_SIG_SEL,FTM0_CH7>
//     <1=> Default
#define FTM0_CH7_PIN_SEL     1

// Pin Mapping for FTM0_FLT0 signal
//   <o>    FTM0_FLT0<name=FTM0_FLT0_PIN_SEL>
//   <i>    Shows which pin FTM0_FLT0 is mapped to
//   <info>  [PTB3, PTD6]
//     <0=> Disabled
//     <1=> PTB3<selection=PTB3_SIG_SEL,FTM0_FLT0>
//     <2=> PTD6<selection=PTD6_SIG_SEL,FTM0_FLT0>
//     <0=> Default
#define FTM0_FLT0_PIN_SEL    0

// Pin Mapping for FTM0_FLT1 signal
//   <o>    FTM0_FLT1<name=FTM0_FLT1_PIN_SEL>
//   <i>    Shows which pin FTM0_FLT1 is mapped to
//   <info>  [PTB10, PTD7]
//     <0=> Disabled
//     <1=> PTB10<selection=PTB10_SIG_SEL,FTM0_FLT1>
//     <2=> PTD7<selection=PTD7_SIG_SEL,FTM0_FLT1>
//     <0=> Default
#define FTM0_FLT1_PIN_SEL    0

// Pin Mapping for FTM0_FLT2 signal
//   <o>    FTM0_FLT2<name=FTM0_FLT2_PIN_SEL>
//   <i>    Shows which pin FTM0_FLT2 is mapped to
//   <info>  [PTA18, PTB11]
//     <0=> Disabled
//     <1=> PTA18<selection=PTA18_SIG_SEL,FTM0_FLT2>
//     <2=> PTB11<selection=PTB11_SIG_SEL,FTM0_FLT2>
//     <0=> Default
#define FTM0_FLT2_PIN_SEL    0

// Pin Mapping for FTM0_FLT3 signal
//   <o>    FTM0_FLT3<name=FTM0_FLT3_PIN_SEL>
//   <i>    Shows which pin FTM0_FLT3 is mapped to
//   <info>  [PTB2]
//     <0=> Disabled
//     <1=> PTB2<selection=PTB2_SIG_SEL,FTM0_FLT3>
//     <0=> Default
#define FTM0_FLT3_PIN_SEL    0

// </h>

// <h> FlexTimer (FTM1)

// Pin Mapping for FTM1_CH0 signal
//   <o>    FTM1_CH0<name=FTM1_CH0_PIN_SEL>
//   <i>    Shows which pin FTM1_CH0 is mapped to
//   <info>  [PTA12, PTB0]
//     <0=> Disabled
//     <1=> PTA12<selection=PTA12_SIG_SEL,FTM1_CH0>
//     <2=> PTB0<selection=PTB0_SIG_SEL,FTM1_CH0>
//     <0=> Default
#define FTM1_CH0_PIN_SEL     0

// Pin Mapping for FTM1_CH1 signal
//   <o>    FTM1_CH1<name=FTM1_CH1_PIN_SEL>
//   <i>    Shows which pin FTM1_CH1 is mapped to
//   <info>  [PTA13, PTB1]
//     <0=> Disabled
//     <1=> PTA13<selection=PTA13_SIG_SEL,FTM1_CH1>
//     <2=> PTB1<selection=PTB1_SIG_SEL,FTM1_CH1>
//     <0=> Default
#define FTM1_CH1_PIN_SEL     0

// Pin Mapping for FTM1_FLT0 signal
//   <o>    FTM1_FLT0<name=FTM1_FLT0_PIN_SEL>
//   <i>    Shows which pin FTM1_FLT0 is mapped to
//   <info>  [PTA19]
//     <0=> Disabled
//     <1=> PTA19<selection=PTA19_SIG_SEL,FTM1_FLT0>
//     <0=> Default
#define FTM1_FLT0_PIN_SEL    0

// Pin Mapping for FTM1_QD_PHA signal
//   <o>    FTM1_QD_PHA<name=FTM1_QD_PHA_PIN_SEL>
//   <i>    Shows which pin FTM1_QD_PHA is mapped to
//   <info>  [PTB0, PTA12]
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,FTM1_QD_PHA>
//     <2=> PTA12<selection=PTA12_SIG_SEL,FTM1_QD_PHA>
//     <0=> Default
#define FTM1_QD_PHA_PIN_SEL  0

// Pin Mapping for FTM1_QD_PHB signal
//   <o>    FTM1_QD_PHB<name=FTM1_QD_PHB_PIN_SEL>
//   <i>    Shows which pin FTM1_QD_PHB is mapped to
//   <info>  [PTB1, PTA13]
//     <0=> Disabled
//     <1=> PTB1<selection=PTB1_SIG_SEL,FTM1_QD_PHB>
//     <2=> PTA13<selection=PTA13_SIG_SEL,FTM1_QD_PHB>
//     <0=> Default
#define FTM1_QD_PHB_PIN_SEL  0

// </h>

// <h> FlexTimer (FTM2)

// Pin Mapping for FTM2_CH0 signal
//   <o>    FTM2_CH0<name=FTM2_CH0_PIN_SEL>
//   <i>    Shows which pin FTM2_CH0 is mapped to
//   <info>  [PTA10, PTB18]
//     <0=> Disabled
//     <1=> PTA10<selection=PTA10_SIG_SEL,FTM2_CH0>
//     <2=> PTB18<selection=PTB18_SIG_SEL,FTM2_CH0>
//     <0=> Default
#define FTM2_CH0_PIN_SEL     0

// Pin Mapping for FTM2_CH1 signal
//   <o>    FTM2_CH1<name=FTM2_CH1_PIN_SEL>
//   <i>    Shows which pin FTM2_CH1 is mapped to
//   <info>  [PTA11, PTB19]
//     <0=> Disabled
//     <1=> PTA11<selection=PTA11_SIG_SEL,FTM2_CH1>
//     <2=> PTB19<selection=PTB19_SIG_SEL,FTM2_CH1>
//     <0=> Default
#define FTM2_CH1_PIN_SEL     0

// Pin Mapping for FTM2_FLT0 signal
//   <o>    FTM2_FLT0<name=FTM2_FLT0_PIN_SEL>
//   <i>    Shows which pin FTM2_FLT0 is mapped to
//   <info>  [PTC9]
//     <0=> Disabled
//     <1=> PTC9<selection=PTC9_SIG_SEL,FTM2_FLT0>
//     <0=> Default
#define FTM2_FLT0_PIN_SEL    0

// Pin Mapping for FTM2_QD_PHA signal
//   <o>    FTM2_QD_PHA<name=FTM2_QD_PHA_PIN_SEL>
//   <i>    Shows which pin FTM2_QD_PHA is mapped to
//   <info>  [PTA10, PTB18]
//     <0=> Disabled
//     <1=> PTA10<selection=PTA10_SIG_SEL,FTM2_QD_PHA>
//     <2=> PTB18<selection=PTB18_SIG_SEL,FTM2_QD_PHA>
//     <0=> Default
#define FTM2_QD_PHA_PIN_SEL  0

// Pin Mapping for FTM2_QD_PHB signal
//   <o>    FTM2_QD_PHB<name=FTM2_QD_PHB_PIN_SEL>
//   <i>    Shows which pin FTM2_QD_PHB is mapped to
//   <info>  [PTA11, PTB19]
//     <0=> Disabled
//     <1=> PTA11<selection=PTA11_SIG_SEL,FTM2_QD_PHB>
//     <2=> PTB19<selection=PTB19_SIG_SEL,FTM2_QD_PHB>
//     <0=> Default
#define FTM2_QD_PHB_PIN_SEL  0

// </h>

// <h> FlexTimer (FTM3)

// Pin Mapping for FTM3_CH0 signal
//   <o>    FTM3_CH0<name=FTM3_CH0_PIN_SEL>
//   <i>    Shows which pin FTM3_CH0 is mapped to
//   <info>  [PTD0, PTE5]
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,FTM3_CH0>
//     <2=> PTE5<selection=PTE5_SIG_SEL,FTM3_CH0>
//     <0=> Default
#define FTM3_CH0_PIN_SEL     0

// Pin Mapping for FTM3_CH1 signal
//   <o>    FTM3_CH1<name=FTM3_CH1_PIN_SEL>
//   <i>    Shows which pin FTM3_CH1 is mapped to
//   <info>  [PTD1, PTE6]
//     <0=> Disabled
//     <1=> PTD1<selection=PTD1_SIG_SEL,FTM3_CH1>
//     <2=> PTE6<selection=PTE6_SIG_SEL,FTM3_CH1>
//     <0=> Default
#define FTM3_CH1_PIN_SEL     0

// Pin Mapping for FTM3_CH2 signal
//   <o>    FTM3_CH2<name=FTM3_CH2_PIN_SEL>
//   <i>    Shows which pin FTM3_CH2 is mapped to
//   <info>  [PTD2]
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,FTM3_CH2>
//     <0=> Default
#define FTM3_CH2_PIN_SEL     0

// Pin Mapping for FTM3_CH3 signal
//   <o>    FTM3_CH3<name=FTM3_CH3_PIN_SEL>
//   <i>    Shows which pin FTM3_CH3 is mapped to
//   <info>  [PTD3]
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,FTM3_CH3>
//     <0=> Default
#define FTM3_CH3_PIN_SEL     0

// Pin Mapping for FTM3_CH4 signal
//   <o>    FTM3_CH4<name=FTM3_CH4_PIN_SEL>
//   <i>    Shows which pin FTM3_CH4 is mapped to
//   <info>  [PTC8]
//     <0=> Disabled
//     <1=> PTC8<selection=PTC8_SIG_SEL,FTM3_CH4>
//     <0=> Default
#define FTM3_CH4_PIN_SEL     0

// Pin Mapping for FTM3_CH5 signal
//   <o>    FTM3_CH5<name=FTM3_CH5_PIN_SEL>
//   <i>    Shows which pin FTM3_CH5 is mapped to
//   <info>  [PTC9]
//     <0=> Disabled
//     <1=> PTC9<selection=PTC9_SIG_SEL,FTM3_CH5>
//     <0=> Default
#define FTM3_CH5_PIN_SEL     0

// Pin Mapping for FTM3_CH6 signal
//   <o>    FTM3_CH6<name=FTM3_CH6_PIN_SEL>
//   <i>    Shows which pin FTM3_CH6 is mapped to
//   <info>  [PTC10]
//     <0=> Disabled
//     <1=> PTC10<selection=PTC10_SIG_SEL,FTM3_CH6>
//     <0=> Default
#define FTM3_CH6_PIN_SEL     0

// Pin Mapping for FTM3_CH7 signal
//   <o>    FTM3_CH7<name=FTM3_CH7_PIN_SEL>
//   <i>    Shows which pin FTM3_CH7 is mapped to
//   <info>  [PTC11]
//     <0=> Disabled
//     <1=> PTC11<selection=PTC11_SIG_SEL,FTM3_CH7>
//     <0=> Default
#define FTM3_CH7_PIN_SEL     0

// Pin Mapping for FTM3_FLT0 signal
//   <o>    FTM3_FLT0<name=FTM3_FLT0_PIN_SEL>
//   <i>    Shows which pin FTM3_FLT0 is mapped to
//   <info>  [PTD12, PTC12]
//     <0=> Disabled
//     <1=> PTD12<selection=PTD12_SIG_SEL,FTM3_FLT0>
//     <2=> PTC12<selection=PTC12_SIG_SEL,FTM3_FLT0>
//     <0=> Default
#define FTM3_FLT0_PIN_SEL    0

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
//     <1=> PTA4<selection=PTA4_SIG_SEL,GPIOA_4/LLWU_P3>
//     <0=> Default
#define GPIOA_4_PIN_SEL      0

// Pin Mapping for GPIOA_5 signal
//   <o>    GPIOA_5<name=GPIOA_5_PIN_SEL>
//   <i>    Shows which pin GPIOA_5 is mapped to
//   <info>  [PTA5]
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,GPIOA_5>
//     <1=> Default
#define GPIOA_5_PIN_SEL      1

// Pin Mapping for GPIOA_10 signal
//   <o>    GPIOA_10<name=GPIOA_10_PIN_SEL>
//   <i>    Shows which pin GPIOA_10 is mapped to
//   <info>  [PTA10]
//     <0=> Disabled
//     <1=> PTA10<selection=PTA10_SIG_SEL,GPIOA_10>
//     <0=> Default
#define GPIOA_10_PIN_SEL     0

// Pin Mapping for GPIOA_11 signal
//   <o>    GPIOA_11<name=GPIOA_11_PIN_SEL>
//   <i>    Shows which pin GPIOA_11 is mapped to
//   <info>  [PTA11]
//     <0=> Disabled
//     <1=> PTA11<selection=PTA11_SIG_SEL,GPIOA_11>
//     <0=> Default
#define GPIOA_11_PIN_SEL     0

// Pin Mapping for GPIOA_12 signal
//   <o>    GPIOA_12<name=GPIOA_12_PIN_SEL>
//   <i>    Shows which pin GPIOA_12 is mapped to
//   <info>  [PTA12]
//     <0=> Disabled
//     <1=> PTA12<selection=PTA12_SIG_SEL,GPIOA_12>
//     <0=> Default
#define GPIOA_12_PIN_SEL     0

// Pin Mapping for GPIOA_13 signal
//   <o>    GPIOA_13<name=GPIOA_13_PIN_SEL>
//   <i>    Shows which pin GPIOA_13 is mapped to
//   <info>  [PTA13]
//     <0=> Disabled
//     <1=> PTA13<selection=PTA13_SIG_SEL,GPIOA_13/LLWU_P4>
//     <0=> Default
#define GPIOA_13_PIN_SEL     0

// Pin Mapping for GPIOA_14 signal
//   <o>    GPIOA_14<name=GPIOA_14_PIN_SEL>
//   <i>    Shows which pin GPIOA_14 is mapped to
//   <info>  [PTA14]
//     <0=> Disabled
//     <1=> PTA14<selection=PTA14_SIG_SEL,GPIOA_14>
//     <0=> Default
#define GPIOA_14_PIN_SEL     0

// Pin Mapping for GPIOA_15 signal
//   <o>    GPIOA_15<name=GPIOA_15_PIN_SEL>
//   <i>    Shows which pin GPIOA_15 is mapped to
//   <info>  [PTA15]
//     <0=> Disabled
//     <1=> PTA15<selection=PTA15_SIG_SEL,GPIOA_15>
//     <0=> Default
#define GPIOA_15_PIN_SEL     0

// Pin Mapping for GPIOA_16 signal
//   <o>    GPIOA_16<name=GPIOA_16_PIN_SEL>
//   <i>    Shows which pin GPIOA_16 is mapped to
//   <info>  [PTA16]
//     <0=> Disabled
//     <1=> PTA16<selection=PTA16_SIG_SEL,GPIOA_16>
//     <0=> Default
#define GPIOA_16_PIN_SEL     0

// Pin Mapping for GPIOA_17 signal
//   <o>    GPIOA_17<name=GPIOA_17_PIN_SEL>
//   <i>    Shows which pin GPIOA_17 is mapped to
//   <info>  [PTA17]
//     <0=> Disabled
//     <1=> PTA17<selection=PTA17_SIG_SEL,GPIOA_17>
//     <0=> Default
#define GPIOA_17_PIN_SEL     0

// Pin Mapping for GPIOA_18 signal
//   <o>    GPIOA_18<name=GPIOA_18_PIN_SEL>
//   <i>    Shows which pin GPIOA_18 is mapped to
//   <info>  [PTA18]
//     <0=> Disabled
//     <1=> PTA18<selection=PTA18_SIG_SEL,GPIOA_18>
//     <0=> Default
#define GPIOA_18_PIN_SEL     0

// Pin Mapping for GPIOA_19 signal
//   <o>    GPIOA_19<name=GPIOA_19_PIN_SEL>
//   <i>    Shows which pin GPIOA_19 is mapped to
//   <info>  [PTA19]
//     <0=> Disabled
//     <1=> PTA19<selection=PTA19_SIG_SEL,GPIOA_19>
//     <0=> Default
#define GPIOA_19_PIN_SEL     0

// Pin Mapping for GPIOA_29 signal
//   <o>    GPIOA_29<name=GPIOA_29_PIN_SEL>
//   <i>    Shows which pin GPIOA_29 is mapped to
//   <info>  [PTA29]
//     <0=> Disabled
//     <1=> PTA29<selection=PTA29_SIG_SEL,GPIOA_29>
//     <0=> Default
#define GPIOA_29_PIN_SEL     0

// </h>

// <h> General Purpose I/O (GPIOB)

// Pin Mapping for GPIOB_0 signal
//   <o>    GPIOB_0<name=GPIOB_0_PIN_SEL>
//   <i>    Shows which pin GPIOB_0 is mapped to
//   <info>  [PTB0]
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,GPIOB_0/LLWU_P5>
//     <0=> Default
#define GPIOB_0_PIN_SEL      0

// Pin Mapping for GPIOB_1 signal
//   <o>    GPIOB_1<name=GPIOB_1_PIN_SEL>
//   <i>    Shows which pin GPIOB_1 is mapped to
//   <info>  [PTB1]
//     <0=> Disabled
//     <1=> PTB1<selection=PTB1_SIG_SEL,GPIOB_1>
//     <0=> Default
#define GPIOB_1_PIN_SEL      0

// Pin Mapping for GPIOB_2 signal
//   <o>    GPIOB_2<name=GPIOB_2_PIN_SEL>
//   <i>    Shows which pin GPIOB_2 is mapped to
//   <info>  [PTB2]
//     <0=> Disabled
//     <1=> PTB2<selection=PTB2_SIG_SEL,GPIOB_2>
//     <0=> Default
#define GPIOB_2_PIN_SEL      0

// Pin Mapping for GPIOB_3 signal
//   <o>    GPIOB_3<name=GPIOB_3_PIN_SEL>
//   <i>    Shows which pin GPIOB_3 is mapped to
//   <info>  [PTB3]
//     <0=> Disabled
//     <1=> PTB3<selection=PTB3_SIG_SEL,GPIOB_3>
//     <0=> Default
#define GPIOB_3_PIN_SEL      0

// Pin Mapping for GPIOB_6 signal
//   <o>    GPIOB_6<name=GPIOB_6_PIN_SEL>
//   <i>    Shows which pin GPIOB_6 is mapped to
//   <info>  [PTB6]
//     <0=> Disabled
//     <1=> PTB6<selection=PTB6_SIG_SEL,GPIOB_6>
//     <0=> Default
#define GPIOB_6_PIN_SEL      0

// Pin Mapping for GPIOB_7 signal
//   <o>    GPIOB_7<name=GPIOB_7_PIN_SEL>
//   <i>    Shows which pin GPIOB_7 is mapped to
//   <info>  [PTB7]
//     <0=> Disabled
//     <1=> PTB7<selection=PTB7_SIG_SEL,GPIOB_7>
//     <0=> Default
#define GPIOB_7_PIN_SEL      0

// Pin Mapping for GPIOB_8 signal
//   <o>    GPIOB_8<name=GPIOB_8_PIN_SEL>
//   <i>    Shows which pin GPIOB_8 is mapped to
//   <info>  [PTB8]
//     <0=> Disabled
//     <1=> PTB8<selection=PTB8_SIG_SEL,GPIOB_8>
//     <0=> Default
#define GPIOB_8_PIN_SEL      0

// Pin Mapping for GPIOB_9 signal
//   <o>    GPIOB_9<name=GPIOB_9_PIN_SEL>
//   <i>    Shows which pin GPIOB_9 is mapped to
//   <info>  [PTB9]
//     <0=> Disabled
//     <1=> PTB9<selection=PTB9_SIG_SEL,GPIOB_9>
//     <0=> Default
#define GPIOB_9_PIN_SEL      0

// Pin Mapping for GPIOB_10 signal
//   <o>    GPIOB_10<name=GPIOB_10_PIN_SEL>
//   <i>    Shows which pin GPIOB_10 is mapped to
//   <info>  [PTB10]
//     <0=> Disabled
//     <1=> PTB10<selection=PTB10_SIG_SEL,GPIOB_10>
//     <0=> Default
#define GPIOB_10_PIN_SEL     0

// Pin Mapping for GPIOB_11 signal
//   <o>    GPIOB_11<name=GPIOB_11_PIN_SEL>
//   <i>    Shows which pin GPIOB_11 is mapped to
//   <info>  [PTB11]
//     <0=> Disabled
//     <1=> PTB11<selection=PTB11_SIG_SEL,GPIOB_11>
//     <0=> Default
#define GPIOB_11_PIN_SEL     0

// Pin Mapping for GPIOB_16 signal
//   <o>    GPIOB_16<name=GPIOB_16_PIN_SEL>
//   <i>    Shows which pin GPIOB_16 is mapped to
//   <info>  [PTB16]
//     <0=> Disabled
//     <1=> PTB16<selection=PTB16_SIG_SEL,GPIOB_16>
//     <1=> Default
#define GPIOB_16_PIN_SEL     1

// Pin Mapping for GPIOB_17 signal
//   <o>    GPIOB_17<name=GPIOB_17_PIN_SEL>
//   <i>    Shows which pin GPIOB_17 is mapped to
//   <info>  [PTB17]
//     <0=> Disabled
//     <1=> PTB17<selection=PTB17_SIG_SEL,GPIOB_17>
//     <0=> Default
#define GPIOB_17_PIN_SEL     0

// Pin Mapping for GPIOB_18 signal
//   <o>    GPIOB_18<name=GPIOB_18_PIN_SEL>
//   <i>    Shows which pin GPIOB_18 is mapped to
//   <info>  [PTB18]
//     <0=> Disabled
//     <1=> PTB18<selection=PTB18_SIG_SEL,GPIOB_18>
//     <1=> Default
#define GPIOB_18_PIN_SEL     1

// Pin Mapping for GPIOB_19 signal
//   <o>    GPIOB_19<name=GPIOB_19_PIN_SEL>
//   <i>    Shows which pin GPIOB_19 is mapped to
//   <info>  [PTB19]
//     <0=> Disabled
//     <1=> PTB19<selection=PTB19_SIG_SEL,GPIOB_19>
//     <1=> Default
#define GPIOB_19_PIN_SEL     1

// Pin Mapping for GPIOB_20 signal
//   <o>    GPIOB_20<name=GPIOB_20_PIN_SEL>
//   <i>    Shows which pin GPIOB_20 is mapped to
//   <info>  [PTB20]
//     <0=> Disabled
//     <1=> PTB20<selection=PTB20_SIG_SEL,GPIOB_20>
//     <0=> Default
#define GPIOB_20_PIN_SEL     0

// Pin Mapping for GPIOB_21 signal
//   <o>    GPIOB_21<name=GPIOB_21_PIN_SEL>
//   <i>    Shows which pin GPIOB_21 is mapped to
//   <info>  [PTB21]
//     <0=> Disabled
//     <1=> PTB21<selection=PTB21_SIG_SEL,GPIOB_21>
//     <0=> Default
#define GPIOB_21_PIN_SEL     0

// Pin Mapping for GPIOB_22 signal
//   <o>    GPIOB_22<name=GPIOB_22_PIN_SEL>
//   <i>    Shows which pin GPIOB_22 is mapped to
//   <info>  [PTB22]
//     <0=> Disabled
//     <1=> PTB22<selection=PTB22_SIG_SEL,GPIOB_22>
//     <0=> Default
#define GPIOB_22_PIN_SEL     0

// Pin Mapping for GPIOB_23 signal
//   <o>    GPIOB_23<name=GPIOB_23_PIN_SEL>
//   <i>    Shows which pin GPIOB_23 is mapped to
//   <info>  [PTB23]
//     <0=> Disabled
//     <1=> PTB23<selection=PTB23_SIG_SEL,GPIOB_23>
//     <0=> Default
#define GPIOB_23_PIN_SEL     0

// </h>

// <h> General Purpose I/O (GPIOC)

// Pin Mapping for GPIOC_0 signal
//   <o>    GPIOC_0<name=GPIOC_0_PIN_SEL>
//   <i>    Shows which pin GPIOC_0 is mapped to
//   <info>  [PTC0]
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,GPIOC_0>
//     <0=> Default
#define GPIOC_0_PIN_SEL      0

// Pin Mapping for GPIOC_1 signal
//   <o>    GPIOC_1<name=GPIOC_1_PIN_SEL>
//   <i>    Shows which pin GPIOC_1 is mapped to
//   <info>  [PTC1]
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,GPIOC_1/LLWU_P6>
//     <0=> Default
#define GPIOC_1_PIN_SEL      0

// Pin Mapping for GPIOC_2 signal
//   <o>    GPIOC_2<name=GPIOC_2_PIN_SEL>
//   <i>    Shows which pin GPIOC_2 is mapped to
//   <info>  [PTC2]
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,GPIOC_2>
//     <0=> Default
#define GPIOC_2_PIN_SEL      0

// Pin Mapping for GPIOC_3 signal
//   <o>    GPIOC_3<name=GPIOC_3_PIN_SEL>
//   <i>    Shows which pin GPIOC_3 is mapped to
//   <info>  [PTC3]
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,GPIOC_3/LLWU_P7>
//     <1=> Default
#define GPIOC_3_PIN_SEL      1

// Pin Mapping for GPIOC_4 signal
//   <o>    GPIOC_4<name=GPIOC_4_PIN_SEL>
//   <i>    Shows which pin GPIOC_4 is mapped to
//   <info>  [PTC4]
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,GPIOC_4/LLWU_P8>
//     <0=> Default
#define GPIOC_4_PIN_SEL      0

// Pin Mapping for GPIOC_5 signal
//   <o>    GPIOC_5<name=GPIOC_5_PIN_SEL>
//   <i>    Shows which pin GPIOC_5 is mapped to
//   <info>  [PTC5]
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,GPIOC_5/LLWU_P9>
//     <0=> Default
#define GPIOC_5_PIN_SEL      0

// Pin Mapping for GPIOC_6 signal
//   <o>    GPIOC_6<name=GPIOC_6_PIN_SEL>
//   <i>    Shows which pin GPIOC_6 is mapped to
//   <info>  [PTC6]
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,GPIOC_6/LLWU_P10>
//     <1=> Default
#define GPIOC_6_PIN_SEL      1

// Pin Mapping for GPIOC_7 signal
//   <o>    GPIOC_7<name=GPIOC_7_PIN_SEL>
//   <i>    Shows which pin GPIOC_7 is mapped to
//   <info>  [PTC7]
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,GPIOC_7>
//     <0=> Default
#define GPIOC_7_PIN_SEL      0

// Pin Mapping for GPIOC_8 signal
//   <o>    GPIOC_8<name=GPIOC_8_PIN_SEL>
//   <i>    Shows which pin GPIOC_8 is mapped to
//   <info>  [PTC8]
//     <0=> Disabled
//     <1=> PTC8<selection=PTC8_SIG_SEL,GPIOC_8>
//     <0=> Default
#define GPIOC_8_PIN_SEL      0

// Pin Mapping for GPIOC_9 signal
//   <o>    GPIOC_9<name=GPIOC_9_PIN_SEL>
//   <i>    Shows which pin GPIOC_9 is mapped to
//   <info>  [PTC9]
//     <0=> Disabled
//     <1=> PTC9<selection=PTC9_SIG_SEL,GPIOC_9>
//     <0=> Default
#define GPIOC_9_PIN_SEL      0

// Pin Mapping for GPIOC_10 signal
//   <o>    GPIOC_10<name=GPIOC_10_PIN_SEL>
//   <i>    Shows which pin GPIOC_10 is mapped to
//   <info>  [PTC10]
//     <0=> Disabled
//     <1=> PTC10<selection=PTC10_SIG_SEL,GPIOC_10>
//     <0=> Default
#define GPIOC_10_PIN_SEL     0

// Pin Mapping for GPIOC_11 signal
//   <o>    GPIOC_11<name=GPIOC_11_PIN_SEL>
//   <i>    Shows which pin GPIOC_11 is mapped to
//   <info>  [PTC11]
//     <0=> Disabled
//     <1=> PTC11<selection=PTC11_SIG_SEL,GPIOC_11/LLWU_P11>
//     <0=> Default
#define GPIOC_11_PIN_SEL     0

// Pin Mapping for GPIOC_12 signal
//   <o>    GPIOC_12<name=GPIOC_12_PIN_SEL>
//   <i>    Shows which pin GPIOC_12 is mapped to
//   <info>  [PTC12]
//     <0=> Disabled
//     <1=> PTC12<selection=PTC12_SIG_SEL,GPIOC_12>
//     <0=> Default
#define GPIOC_12_PIN_SEL     0

// Pin Mapping for GPIOC_13 signal
//   <o>    GPIOC_13<name=GPIOC_13_PIN_SEL>
//   <i>    Shows which pin GPIOC_13 is mapped to
//   <info>  [PTC13]
//     <0=> Disabled
//     <1=> PTC13<selection=PTC13_SIG_SEL,GPIOC_13>
//     <0=> Default
#define GPIOC_13_PIN_SEL     0

// Pin Mapping for GPIOC_14 signal
//   <o>    GPIOC_14<name=GPIOC_14_PIN_SEL>
//   <i>    Shows which pin GPIOC_14 is mapped to
//   <info>  [PTC14]
//     <0=> Disabled
//     <1=> PTC14<selection=PTC14_SIG_SEL,GPIOC_14>
//     <0=> Default
#define GPIOC_14_PIN_SEL     0

// Pin Mapping for GPIOC_15 signal
//   <o>    GPIOC_15<name=GPIOC_15_PIN_SEL>
//   <i>    Shows which pin GPIOC_15 is mapped to
//   <info>  [PTC15]
//     <0=> Disabled
//     <1=> PTC15<selection=PTC15_SIG_SEL,GPIOC_15>
//     <0=> Default
#define GPIOC_15_PIN_SEL     0

// Pin Mapping for GPIOC_16 signal
//   <o>    GPIOC_16<name=GPIOC_16_PIN_SEL>
//   <i>    Shows which pin GPIOC_16 is mapped to
//   <info>  [PTC16]
//     <0=> Disabled
//     <1=> PTC16<selection=PTC16_SIG_SEL,GPIOC_16>
//     <0=> Default
#define GPIOC_16_PIN_SEL     0

// Pin Mapping for GPIOC_17 signal
//   <o>    GPIOC_17<name=GPIOC_17_PIN_SEL>
//   <i>    Shows which pin GPIOC_17 is mapped to
//   <info>  [PTC17]
//     <0=> Disabled
//     <1=> PTC17<selection=PTC17_SIG_SEL,GPIOC_17>
//     <0=> Default
#define GPIOC_17_PIN_SEL     0

// Pin Mapping for GPIOC_18 signal
//   <o>    GPIOC_18<name=GPIOC_18_PIN_SEL>
//   <i>    Shows which pin GPIOC_18 is mapped to
//   <info>  [PTC18]
//     <0=> Disabled
//     <1=> PTC18<selection=PTC18_SIG_SEL,GPIOC_18>
//     <0=> Default
#define GPIOC_18_PIN_SEL     0

// Pin Mapping for GPIOC_19 signal
//   <o>    GPIOC_19<name=GPIOC_19_PIN_SEL>
//   <i>    Shows which pin GPIOC_19 is mapped to
//   <info>  [PTC19]
//     <0=> Disabled
//     <1=> PTC19<selection=PTC19_SIG_SEL,GPIOC_19>
//     <0=> Default
#define GPIOC_19_PIN_SEL     0

// </h>

// <h> General Purpose I/O (GPIOD)

// Pin Mapping for GPIOD_0 signal
//   <o>    GPIOD_0<name=GPIOD_0_PIN_SEL>
//   <i>    Shows which pin GPIOD_0 is mapped to
//   <info>  [PTD0]
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,GPIOD_0/LLWU_P12>
//     <0=> Default
#define GPIOD_0_PIN_SEL      0

// Pin Mapping for GPIOD_1 signal
//   <o>    GPIOD_1<name=GPIOD_1_PIN_SEL>
//   <i>    Shows which pin GPIOD_1 is mapped to
//   <info>  [PTD1]
//     <0=> Disabled
//     <1=> PTD1<selection=PTD1_SIG_SEL,GPIOD_1>
//     <0=> Default
#define GPIOD_1_PIN_SEL      0

// Pin Mapping for GPIOD_2 signal
//   <o>    GPIOD_2<name=GPIOD_2_PIN_SEL>
//   <i>    Shows which pin GPIOD_2 is mapped to
//   <info>  [PTD2]
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,GPIOD_2/LLWU_P13>
//     <1=> Default
#define GPIOD_2_PIN_SEL      1

// Pin Mapping for GPIOD_3 signal
//   <o>    GPIOD_3<name=GPIOD_3_PIN_SEL>
//   <i>    Shows which pin GPIOD_3 is mapped to
//   <info>  [PTD3]
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,GPIOD_3>
//     <1=> Default
#define GPIOD_3_PIN_SEL      1

// Pin Mapping for GPIOD_4 signal
//   <o>    GPIOD_4<name=GPIOD_4_PIN_SEL>
//   <i>    Shows which pin GPIOD_4 is mapped to
//   <info>  [PTD4]
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,GPIOD_4/LLWU_P14>
//     <1=> Default
#define GPIOD_4_PIN_SEL      1

// Pin Mapping for GPIOD_5 signal
//   <o>    GPIOD_5<name=GPIOD_5_PIN_SEL>
//   <i>    Shows which pin GPIOD_5 is mapped to
//   <info>  [PTD5]
//     <0=> Disabled
//     <1=> PTD5<selection=PTD5_SIG_SEL,GPIOD_5>
//     <0=> Default
#define GPIOD_5_PIN_SEL      0

// Pin Mapping for GPIOD_6 signal
//   <o>    GPIOD_6<name=GPIOD_6_PIN_SEL>
//   <i>    Shows which pin GPIOD_6 is mapped to
//   <info>  [PTD6]
//     <0=> Disabled
//     <1=> PTD6<selection=PTD6_SIG_SEL,GPIOD_6/LLWU_P15>
//     <0=> Default
#define GPIOD_6_PIN_SEL      0

// Pin Mapping for GPIOD_7 signal
//   <o>    GPIOD_7<name=GPIOD_7_PIN_SEL>
//   <i>    Shows which pin GPIOD_7 is mapped to
//   <info>  [PTD7]
//     <0=> Disabled
//     <1=> PTD7<selection=PTD7_SIG_SEL,GPIOD_7>
//     <0=> Default
#define GPIOD_7_PIN_SEL      0

// Pin Mapping for GPIOD_8 signal
//   <o>    GPIOD_8<name=GPIOD_8_PIN_SEL>
//   <i>    Shows which pin GPIOD_8 is mapped to
//   <info>  [PTD8]
//     <0=> Disabled
//     <1=> PTD8<selection=PTD8_SIG_SEL,GPIOD_8>
//     <0=> Default
#define GPIOD_8_PIN_SEL      0

// Pin Mapping for GPIOD_9 signal
//   <o>    GPIOD_9<name=GPIOD_9_PIN_SEL>
//   <i>    Shows which pin GPIOD_9 is mapped to
//   <info>  [PTD9]
//     <0=> Disabled
//     <1=> PTD9<selection=PTD9_SIG_SEL,GPIOD_9>
//     <0=> Default
#define GPIOD_9_PIN_SEL      0

// Pin Mapping for GPIOD_10 signal
//   <o>    GPIOD_10<name=GPIOD_10_PIN_SEL>
//   <i>    Shows which pin GPIOD_10 is mapped to
//   <info>  [PTD10]
//     <0=> Disabled
//     <1=> PTD10<selection=PTD10_SIG_SEL,GPIOD_10>
//     <0=> Default
#define GPIOD_10_PIN_SEL     0

// Pin Mapping for GPIOD_11 signal
//   <o>    GPIOD_11<name=GPIOD_11_PIN_SEL>
//   <i>    Shows which pin GPIOD_11 is mapped to
//   <info>  [PTD11]
//     <0=> Disabled
//     <1=> PTD11<selection=PTD11_SIG_SEL,GPIOD_11>
//     <0=> Default
#define GPIOD_11_PIN_SEL     0

// Pin Mapping for GPIOD_12 signal
//   <o>    GPIOD_12<name=GPIOD_12_PIN_SEL>
//   <i>    Shows which pin GPIOD_12 is mapped to
//   <info>  [PTD12]
//     <0=> Disabled
//     <1=> PTD12<selection=PTD12_SIG_SEL,GPIOD_12>
//     <0=> Default
#define GPIOD_12_PIN_SEL     0

// Pin Mapping for GPIOD_13 signal
//   <o>    GPIOD_13<name=GPIOD_13_PIN_SEL>
//   <i>    Shows which pin GPIOD_13 is mapped to
//   <info>  [PTD13]
//     <0=> Disabled
//     <1=> PTD13<selection=PTD13_SIG_SEL,GPIOD_13>
//     <0=> Default
#define GPIOD_13_PIN_SEL     0

// Pin Mapping for GPIOD_14 signal
//   <o>    GPIOD_14<name=GPIOD_14_PIN_SEL>
//   <i>    Shows which pin GPIOD_14 is mapped to
//   <info>  [PTD14]
//     <0=> Disabled
//     <1=> PTD14<selection=PTD14_SIG_SEL,GPIOD_14>
//     <0=> Default
#define GPIOD_14_PIN_SEL     0

// Pin Mapping for GPIOD_15 signal
//   <o>    GPIOD_15<name=GPIOD_15_PIN_SEL>
//   <i>    Shows which pin GPIOD_15 is mapped to
//   <info>  [PTD15]
//     <0=> Disabled
//     <1=> PTD15<selection=PTD15_SIG_SEL,GPIOD_15>
//     <0=> Default
#define GPIOD_15_PIN_SEL     0

// </h>

// <h> General Purpose I/O (GPIOE)

// Pin Mapping for GPIOE_0 signal
//   <o>    GPIOE_0<name=GPIOE_0_PIN_SEL>
//   <i>    Shows which pin GPIOE_0 is mapped to
//   <info>  [PTE0]
//     <0=> Disabled
//     <1=> PTE0<selection=PTE0_SIG_SEL,GPIOE_0/CLKOUT32K>
//     <0=> Default
#define GPIOE_0_PIN_SEL      0

// Pin Mapping for GPIOE_1 signal
//   <o>    GPIOE_1<name=GPIOE_1_PIN_SEL>
//   <i>    Shows which pin GPIOE_1 is mapped to
//   <info>  [PTE1]
//     <0=> Disabled
//     <1=> PTE1<selection=PTE1_SIG_SEL,GPIOE_1/LLWU_P0>
//     <0=> Default
#define GPIOE_1_PIN_SEL      0

// Pin Mapping for GPIOE_2 signal
//   <o>    GPIOE_2<name=GPIOE_2_PIN_SEL>
//   <i>    Shows which pin GPIOE_2 is mapped to
//   <info>  [PTE2]
//     <0=> Disabled
//     <1=> PTE2<selection=PTE2_SIG_SEL,GPIOE_2/LLWU_P1>
//     <0=> Default
#define GPIOE_2_PIN_SEL      0

// Pin Mapping for GPIOE_3 signal
//   <o>    GPIOE_3<name=GPIOE_3_PIN_SEL>
//   <i>    Shows which pin GPIOE_3 is mapped to
//   <info>  [PTE3]
//     <0=> Disabled
//     <1=> PTE3<selection=PTE3_SIG_SEL,GPIOE_3>
//     <0=> Default
#define GPIOE_3_PIN_SEL      0

// Pin Mapping for GPIOE_4 signal
//   <o>    GPIOE_4<name=GPIOE_4_PIN_SEL>
//   <i>    Shows which pin GPIOE_4 is mapped to
//   <info>  [PTE4]
//     <0=> Disabled
//     <1=> PTE4<selection=PTE4_SIG_SEL,GPIOE_4/LLWU_P2>
//     <0=> Default
#define GPIOE_4_PIN_SEL      0

// Pin Mapping for GPIOE_5 signal
//   <o>    GPIOE_5<name=GPIOE_5_PIN_SEL>
//   <i>    Shows which pin GPIOE_5 is mapped to
//   <info>  [PTE5]
//     <0=> Disabled
//     <1=> PTE5<selection=PTE5_SIG_SEL,GPIOE_5>
//     <0=> Default
#define GPIOE_5_PIN_SEL      0

// Pin Mapping for GPIOE_6 signal
//   <o>    GPIOE_6<name=GPIOE_6_PIN_SEL>
//   <i>    Shows which pin GPIOE_6 is mapped to
//   <info>  [PTE6]
//     <0=> Disabled
//     <1=> PTE6<selection=PTE6_SIG_SEL,GPIOE_6>
//     <0=> Default
#define GPIOE_6_PIN_SEL      0

// Pin Mapping for GPIOE_24 signal
//   <o>    GPIOE_24<name=GPIOE_24_PIN_SEL>
//   <i>    Shows which pin GPIOE_24 is mapped to
//   <info>  [PTE24]
//     <0=> Disabled
//     <1=> PTE24<selection=PTE24_SIG_SEL,GPIOE_24>
//     <0=> Default
#define GPIOE_24_PIN_SEL     0

// Pin Mapping for GPIOE_25 signal
//   <o>    GPIOE_25<name=GPIOE_25_PIN_SEL>
//   <i>    Shows which pin GPIOE_25 is mapped to
//   <info>  [PTE25]
//     <0=> Disabled
//     <1=> PTE25<selection=PTE25_SIG_SEL,GPIOE_25>
//     <0=> Default
#define GPIOE_25_PIN_SEL     0

// Pin Mapping for GPIOE_26 signal
//   <o>    GPIOE_26<name=GPIOE_26_PIN_SEL>
//   <i>    Shows which pin GPIOE_26 is mapped to
//   <info>  [PTE26]
//     <0=> Disabled
//     <1=> PTE26<selection=PTE26_SIG_SEL,GPIOE_26/CLKOUT32K>
//     <0=> Default
#define GPIOE_26_PIN_SEL     0

// </h>

// <h> Inter-Integrated Circuit (I2C0)

// Pin Mapping for I2C0_SCL signal
//   <o>    I2C0_SCL<name=I2C0_SCL_PIN_SEL>
//   <i>    Shows which pin I2C0_SCL is mapped to
//   <info>  [PTB0, PTB2, PTD8, PTE24, PTD2]
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,I2C0_SCL>
//     <2=> PTB2<selection=PTB2_SIG_SEL,I2C0_SCL>
//     <3=> PTD8<selection=PTD8_SIG_SEL,I2C0_SCL>
//     <4=> PTE24<selection=PTE24_SIG_SEL,I2C0_SCL>
//     <5=> PTD2<selection=PTD2_SIG_SEL,I2C0_SCL>
//     <0=> Default
#define I2C0_SCL_PIN_SEL     0

// Pin Mapping for I2C0_SDA signal
//   <o>    I2C0_SDA<name=I2C0_SDA_PIN_SEL>
//   <i>    Shows which pin I2C0_SDA is mapped to
//   <info>  [PTB1, PTB3, PTD9, PTE25, PTD3]
//     <0=> Disabled
//     <1=> PTB1<selection=PTB1_SIG_SEL,I2C0_SDA>
//     <2=> PTB3<selection=PTB3_SIG_SEL,I2C0_SDA>
//     <3=> PTD9<selection=PTD9_SIG_SEL,I2C0_SDA>
//     <4=> PTE25<selection=PTE25_SIG_SEL,I2C0_SDA>
//     <5=> PTD3<selection=PTD3_SIG_SEL,I2C0_SDA>
//     <0=> Default
#define I2C0_SDA_PIN_SEL     0

// </h>

// <h> Inter-Integrated Circuit (I2C1)

// Pin Mapping for I2C1_SDA signal
//   <o>    I2C1_SDA<name=I2C1_SDA_PIN_SEL>
//   <i>    Shows which pin I2C1_SDA is mapped to
//   <info>  [PTC11, PTE0]
//     <0=> Disabled
//     <1=> PTC11<selection=PTC11_SIG_SEL,I2C1_SDA>
//     <2=> PTE0<selection=PTE0_SIG_SEL,I2C1_SDA>
//     <2=> Default
#define I2C1_SDA_PIN_SEL     2

// Pin Mapping for I2C1_SCL signal
//   <o>    I2C1_SCL<name=I2C1_SCL_PIN_SEL>
//   <i>    Shows which pin I2C1_SCL is mapped to
//   <info>  [PTC10, PTE1]
//     <0=> Disabled
//     <1=> PTC10<selection=PTC10_SIG_SEL,I2C1_SCL>
//     <2=> PTE1<selection=PTE1_SIG_SEL,I2C1_SCL>
//     <2=> Default
#define I2C1_SCL_PIN_SEL     2

// </h>

// <h> Integrated Interchip Sound (I2S0)

// Pin Mapping for I2S0_MCLK signal
//   <o>    I2S0_MCLK<name=I2S0_MCLK_PIN_SEL>
//   <i>    Shows which pin I2S0_MCLK is mapped to
//   <info>  [PTC8, PTE6, PTA17, PTC6]
//     <0=> Disabled
//     <1=> PTC8<selection=PTC8_SIG_SEL,I2S0_MCLK>
//     <2=> PTE6<selection=PTE6_SIG_SEL,I2S0_MCLK>
//     <3=> PTA17<selection=PTA17_SIG_SEL,I2S0_MCLK>
//     <4=> PTC6<selection=PTC6_SIG_SEL,I2S0_MCLK>
//     <0=> Default
#define I2S0_MCLK_PIN_SEL    0

// Pin Mapping for I2S0_RX_FS signal
//   <o>    I2S0_RX_FS<name=I2S0_RX_FS_PIN_SEL>
//   <i>    Shows which pin I2S0_RX_FS is mapped to
//   <info>  [PTC7, PTC10, PTA16]
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,I2S0_RX_FS>
//     <2=> PTC10<selection=PTC10_SIG_SEL,I2S0_RX_FS>
//     <3=> PTA16<selection=PTA16_SIG_SEL,I2S0_RX_FS>
//     <0=> Default
#define I2S0_RX_FS_PIN_SEL   0

// Pin Mapping for I2S0_TX_BCLK signal
//   <o>    I2S0_TX_BCLK<name=I2S0_TX_BCLK_PIN_SEL>
//   <i>    Shows which pin I2S0_TX_BCLK is mapped to
//   <info>  [PTB18, PTA5, PTC3]
//     <0=> Disabled
//     <1=> PTB18<selection=PTB18_SIG_SEL,I2S0_TX_BCLK>
//     <2=> PTA5<selection=PTA5_SIG_SEL,I2S0_TX_BCLK>
//     <3=> PTC3<selection=PTC3_SIG_SEL,I2S0_TX_BCLK>
//     <0=> Default
#define I2S0_TX_BCLK_PIN_SEL 0

// Pin Mapping for I2S0_TXD0 signal
//   <o>    I2S0_TXD0<name=I2S0_TXD0_PIN_SEL>
//   <i>    Shows which pin I2S0_TXD0 is mapped to
//   <info>  [PTA12, PTC1]
//     <0=> Disabled
//     <1=> PTA12<selection=PTA12_SIG_SEL,I2S0_TXD0>
//     <2=> PTC1<selection=PTC1_SIG_SEL,I2S0_TXD0>
//     <0=> Default
#define I2S0_TXD0_PIN_SEL    0

// Pin Mapping for I2S0_RX_BCLK signal
//   <o>    I2S0_RX_BCLK<name=I2S0_RX_BCLK_PIN_SEL>
//   <i>    Shows which pin I2S0_RX_BCLK is mapped to
//   <info>  [PTC6, PTC9, PTA14]
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,I2S0_RX_BCLK>
//     <2=> PTC9<selection=PTC9_SIG_SEL,I2S0_RX_BCLK>
//     <3=> PTA14<selection=PTA14_SIG_SEL,I2S0_RX_BCLK>
//     <0=> Default
#define I2S0_RX_BCLK_PIN_SEL 0

// Pin Mapping for I2S0_TX_FS signal
//   <o>    I2S0_TX_FS<name=I2S0_TX_FS_PIN_SEL>
//   <i>    Shows which pin I2S0_TX_FS is mapped to
//   <info>  [PTB19, PTA13, PTC2]
//     <0=> Disabled
//     <1=> PTB19<selection=PTB19_SIG_SEL,I2S0_TX_FS>
//     <2=> PTA13<selection=PTA13_SIG_SEL,I2S0_TX_FS>
//     <3=> PTC2<selection=PTC2_SIG_SEL,I2S0_TX_FS>
//     <0=> Default
#define I2S0_TX_FS_PIN_SEL   0

// Pin Mapping for I2S0_RXD0 signal
//   <o>    I2S0_RXD0<name=I2S0_RXD0_PIN_SEL>
//   <i>    Shows which pin I2S0_RXD0 is mapped to
//   <info>  [PTC5, PTA15]
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,I2S0_RXD0>
//     <2=> PTA15<selection=PTA15_SIG_SEL,I2S0_RXD0>
//     <0=> Default
#define I2S0_RXD0_PIN_SEL    0

// </h>

// <h> Debug and Control

// Pin Mapping for JTAG_TCLK signal
//   <o>    JTAG_TCLK<name=JTAG_TCLK_PIN_SEL>
//   <i>    Shows which pin JTAG_TCLK is mapped to
//   <info>  [PTA0]
//     <0=> Disabled
//     <1=> PTA0 (reset default)<selection=PTA0_SIG_SEL,JTAG_TCLK/SWD_CLK (reset default)>
//     <2=> PTA0<selection=PTA0_SIG_SEL,JTAG_TCLK/SWD_CLK>
//     <1=> Default
#define JTAG_TCLK_PIN_SEL    1

// Pin Mapping for JTAG_TDI signal
//   <o>    JTAG_TDI<name=JTAG_TDI_PIN_SEL>
//   <i>    Shows which pin JTAG_TDI is mapped to
//   <info>  [PTA1]
//     <0=> Disabled
//     <1=> PTA1 (reset default)<selection=PTA1_SIG_SEL,JTAG_TDI (reset default)>
//     <2=> PTA1<selection=PTA1_SIG_SEL,JTAG_TDI>
//     <0=> Default
#define JTAG_TDI_PIN_SEL     0

// Pin Mapping for JTAG_TDO signal
//   <o>    JTAG_TDO<name=JTAG_TDO_PIN_SEL>
//   <i>    Shows which pin JTAG_TDO is mapped to
//   <info>  [PTA2]
//     <0=> Disabled
//     <1=> PTA2 (reset default)<selection=PTA2_SIG_SEL,JTAG_TDO/TRACE_SWO (reset default)>
//     <2=> PTA2<selection=PTA2_SIG_SEL,JTAG_TDO/TRACE_SWO>
//     <0=> Default
#define JTAG_TDO_PIN_SEL     0

// Pin Mapping for JTAG_TMS signal
//   <o>    JTAG_TMS<name=JTAG_TMS_PIN_SEL>
//   <i>    Shows which pin JTAG_TMS is mapped to
//   <info>  [PTA3]
//     <0=> Disabled
//     <1=> PTA3 (reset default)<selection=PTA3_SIG_SEL,JTAG_TMS/SWD_DIO (reset default)>
//     <2=> PTA3<selection=PTA3_SIG_SEL,JTAG_TMS/SWD_DIO>
//     <1=> Default
#define JTAG_TMS_PIN_SEL     1

// Pin Mapping for JTAG_TRST_b signal
//   <o>    JTAG_TRST_b<name=JTAG_TRST_b_PIN_SEL>
//   <i>    Shows which pin JTAG_TRST_b is mapped to
//   <info>  [PTA5]
//     <0=> Disabled
//     <1=> PTA5 (reset default)<selection=PTA5_SIG_SEL,JTAG_TRST_b (reset default)>
//     <2=> PTA5<selection=PTA5_SIG_SEL,JTAG_TRST_b>
//     <0=> Default
#define JTAG_TRST_b_PIN_SEL  0

// Pin Mapping for NMI_b signal
//   <o>    NMI_b<name=NMI_b_PIN_SEL>
//   <i>    Shows which pin NMI_b is mapped to
//   <info>  [PTA4]
//     <0=> Disabled
//     <1=> PTA4 (reset default)<selection=PTA4_SIG_SEL,NMI_b (reset default)>
//     <2=> PTA4<selection=PTA4_SIG_SEL,NMI_b>
//     <0=> Default
#define NMI_b_PIN_SEL        0

// Pin Mapping for RESET_b signal
//   <o>    RESET_b<name=RESET_b_PIN_SEL><constant>
//   <i>    Shows which pin RESET_b is mapped to
//   <info>  [RESET_b]
//     <0=> RESET_b<selection=RESET_b_SIG_SEL,RESET_b>
//     <0=> Default
#define RESET_b_PIN_SEL      0

// Pin Mapping for SWD_CLK signal
//   <o>    SWD_CLK<name=SWD_CLK_PIN_SEL>
//   <i>    Shows which pin SWD_CLK is mapped to
//   <info>  [PTA0]
//     <0=> Disabled
//     <1=> PTA0 (reset default)<selection=PTA0_SIG_SEL,JTAG_TCLK/SWD_CLK (reset default)>
//     <2=> PTA0<selection=PTA0_SIG_SEL,JTAG_TCLK/SWD_CLK>
//     <1=> Default
#define SWD_CLK_PIN_SEL      1

// Pin Mapping for SWD_DIO signal
//   <o>    SWD_DIO<name=SWD_DIO_PIN_SEL>
//   <i>    Shows which pin SWD_DIO is mapped to
//   <info>  [PTA3]
//     <0=> Disabled
//     <1=> PTA3 (reset default)<selection=PTA3_SIG_SEL,JTAG_TMS/SWD_DIO (reset default)>
//     <2=> PTA3<selection=PTA3_SIG_SEL,JTAG_TMS/SWD_DIO>
//     <1=> Default
#define SWD_DIO_PIN_SEL      1

// Pin Mapping for TRACE_SWO signal
//   <o>    TRACE_SWO<name=TRACE_SWO_PIN_SEL>
//   <i>    Shows which pin TRACE_SWO is mapped to
//   <info>  [PTA2]
//     <0=> Disabled
//     <1=> PTA2 (reset default)<selection=PTA2_SIG_SEL,JTAG_TDO/TRACE_SWO (reset default)>
//     <2=> PTA2<selection=PTA2_SIG_SEL,JTAG_TDO/TRACE_SWO>
//     <0=> Default
#define TRACE_SWO_PIN_SEL    0

// </h>

// <h> Low-Leakage Wake-up Unit (LLWU)

// Pin Mapping for LLWU_P0 signal
//   <o>    LLWU_P0<name=LLWU_P0_PIN_SEL>
//   <i>    Shows which pin LLWU_P0 is mapped to
//   <info>  [PTE1]
//     <0=> Disabled
//     <1=> PTE1<selection=PTE1_SIG_SEL,GPIOE_1/LLWU_P0>
//     <0=> Default
#define LLWU_P0_PIN_SEL      0

// Pin Mapping for LLWU_P1 signal
//   <o>    LLWU_P1<name=LLWU_P1_PIN_SEL>
//   <i>    Shows which pin LLWU_P1 is mapped to
//   <info>  [PTE2]
//     <0=> Disabled
//     <1=> PTE2<selection=PTE2_SIG_SEL,GPIOE_2/LLWU_P1>
//     <0=> Default
#define LLWU_P1_PIN_SEL      0

// Pin Mapping for LLWU_P2 signal
//   <o>    LLWU_P2<name=LLWU_P2_PIN_SEL>
//   <i>    Shows which pin LLWU_P2 is mapped to
//   <info>  [PTE4]
//     <0=> Disabled
//     <1=> PTE4<selection=PTE4_SIG_SEL,GPIOE_4/LLWU_P2>
//     <0=> Default
#define LLWU_P2_PIN_SEL      0

// Pin Mapping for LLWU_P3 signal
//   <o>    LLWU_P3<name=LLWU_P3_PIN_SEL>
//   <i>    Shows which pin LLWU_P3 is mapped to
//   <info>  [PTA4]
//     <0=> Disabled
//     <1=> PTA4<selection=PTA4_SIG_SEL,GPIOA_4/LLWU_P3>
//     <0=> Default
#define LLWU_P3_PIN_SEL      0

// Pin Mapping for LLWU_P4 signal
//   <o>    LLWU_P4<name=LLWU_P4_PIN_SEL>
//   <i>    Shows which pin LLWU_P4 is mapped to
//   <info>  [PTA13]
//     <0=> Disabled
//     <1=> PTA13<selection=PTA13_SIG_SEL,GPIOA_13/LLWU_P4>
//     <0=> Default
#define LLWU_P4_PIN_SEL      0

// Pin Mapping for LLWU_P5 signal
//   <o>    LLWU_P5<name=LLWU_P5_PIN_SEL>
//   <i>    Shows which pin LLWU_P5 is mapped to
//   <info>  [PTB0]
//     <0=> Disabled
//     <1=> PTB0<selection=PTB0_SIG_SEL,GPIOB_0/LLWU_P5>
//     <0=> Default
#define LLWU_P5_PIN_SEL      0

// Pin Mapping for LLWU_P6 signal
//   <o>    LLWU_P6<name=LLWU_P6_PIN_SEL>
//   <i>    Shows which pin LLWU_P6 is mapped to
//   <info>  [PTC1]
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,GPIOC_1/LLWU_P6>
//     <0=> Default
#define LLWU_P6_PIN_SEL      0

// Pin Mapping for LLWU_P7 signal
//   <o>    LLWU_P7<name=LLWU_P7_PIN_SEL>
//   <i>    Shows which pin LLWU_P7 is mapped to
//   <info>  [PTC3]
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,GPIOC_3/LLWU_P7>
//     <1=> Default
#define LLWU_P7_PIN_SEL      1

// Pin Mapping for LLWU_P8 signal
//   <o>    LLWU_P8<name=LLWU_P8_PIN_SEL>
//   <i>    Shows which pin LLWU_P8 is mapped to
//   <info>  [PTC4]
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,GPIOC_4/LLWU_P8>
//     <0=> Default
#define LLWU_P8_PIN_SEL      0

// Pin Mapping for LLWU_P9 signal
//   <o>    LLWU_P9<name=LLWU_P9_PIN_SEL>
//   <i>    Shows which pin LLWU_P9 is mapped to
//   <info>  [PTC5]
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,GPIOC_5/LLWU_P9>
//     <0=> Default
#define LLWU_P9_PIN_SEL      0

// Pin Mapping for LLWU_P10 signal
//   <o>    LLWU_P10<name=LLWU_P10_PIN_SEL>
//   <i>    Shows which pin LLWU_P10 is mapped to
//   <info>  [PTC6]
//     <0=> Disabled
//     <1=> PTC6<selection=PTC6_SIG_SEL,GPIOC_6/LLWU_P10>
//     <1=> Default
#define LLWU_P10_PIN_SEL     1

// Pin Mapping for LLWU_P11 signal
//   <o>    LLWU_P11<name=LLWU_P11_PIN_SEL>
//   <i>    Shows which pin LLWU_P11 is mapped to
//   <info>  [PTC11]
//     <0=> Disabled
//     <1=> PTC11<selection=PTC11_SIG_SEL,GPIOC_11/LLWU_P11>
//     <0=> Default
#define LLWU_P11_PIN_SEL     0

// Pin Mapping for LLWU_P12 signal
//   <o>    LLWU_P12<name=LLWU_P12_PIN_SEL>
//   <i>    Shows which pin LLWU_P12 is mapped to
//   <info>  [PTD0]
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,GPIOD_0/LLWU_P12>
//     <0=> Default
#define LLWU_P12_PIN_SEL     0

// Pin Mapping for LLWU_P13 signal
//   <o>    LLWU_P13<name=LLWU_P13_PIN_SEL>
//   <i>    Shows which pin LLWU_P13 is mapped to
//   <info>  [PTD2]
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,GPIOD_2/LLWU_P13>
//     <1=> Default
#define LLWU_P13_PIN_SEL     1

// Pin Mapping for LLWU_P14 signal
//   <o>    LLWU_P14<name=LLWU_P14_PIN_SEL>
//   <i>    Shows which pin LLWU_P14 is mapped to
//   <info>  [PTD4]
//     <0=> Disabled
//     <1=> PTD4<selection=PTD4_SIG_SEL,GPIOD_4/LLWU_P14>
//     <1=> Default
#define LLWU_P14_PIN_SEL     1

// Pin Mapping for LLWU_P15 signal
//   <o>    LLWU_P15<name=LLWU_P15_PIN_SEL>
//   <i>    Shows which pin LLWU_P15 is mapped to
//   <info>  [PTD6]
//     <0=> Disabled
//     <1=> PTD6<selection=PTD6_SIG_SEL,GPIOD_6/LLWU_P15>
//     <0=> Default
#define LLWU_P15_PIN_SEL     0

// </h>

// <h> Low Power Timer (LPTMR)

// Pin Mapping for LPTMR0_ALT1 signal
//   <o>    LPTMR0_ALT1<name=LPTMR0_ALT1_PIN_SEL>
//   <i>    Shows which pin LPTMR0_ALT1 is mapped to
//   <info>  [PTA19]
//     <0=> Disabled
//     <1=> PTA19<selection=PTA19_SIG_SEL,LPTMR0_ALT1>
//     <0=> Default
#define LPTMR0_ALT1_PIN_SEL  0

// Pin Mapping for LPTMR0_ALT2 signal
//   <o>    LPTMR0_ALT2<name=LPTMR0_ALT2_PIN_SEL>
//   <i>    Shows which pin LPTMR0_ALT2 is mapped to
//   <info>  [PTC5]
//     <0=> Disabled
//     <1=> PTC5<selection=PTC5_SIG_SEL,LPTMR0_ALT2>
//     <0=> Default
#define LPTMR0_ALT2_PIN_SEL  0

// </h>

// <h> Low Power UART (LPUART0)

// Pin Mapping for LPUART0_CTS_b signal
//   <o>    LPUART0_CTS_b<name=LPUART0_CTS_b_PIN_SEL>
//   <i>    Shows which pin LPUART0_CTS_b is mapped to
//   <info>  [PTB9, PTC19, PTE6, PTD11, PTD1, PTC2]
//     <0=> Disabled
//     <1=> PTB9<selection=PTB9_SIG_SEL,LPUART0_CTS_b>
//     <2=> PTC19<selection=PTC19_SIG_SEL,LPUART0_CTS_b>
//     <3=> PTE6<selection=PTE6_SIG_SEL,LPUART0_CTS_b>
//     <4=> PTD11<selection=PTD11_SIG_SEL,LPUART0_CTS_b>
//     <5=> PTD1<selection=PTD1_SIG_SEL,LPUART0_CTS_b>
//     <6=> PTC2<selection=PTC2_SIG_SEL,LPUART0_CTS_b>
//     <0=> Default
#define LPUART0_CTS_b_PIN_SEL 0

// Pin Mapping for LPUART0_RTS_b signal
//   <o>    LPUART0_RTS_b<name=LPUART0_RTS_b_PIN_SEL>
//   <i>    Shows which pin LPUART0_RTS_b is mapped to
//   <info>  [PTB8, PTC18, PTD10, PTD0, PTC1]
//     <0=> Disabled
//     <1=> PTB8<selection=PTB8_SIG_SEL,LPUART0_RTS_b>
//     <2=> PTC18<selection=PTC18_SIG_SEL,LPUART0_RTS_b>
//     <3=> PTD10<selection=PTD10_SIG_SEL,LPUART0_RTS_b>
//     <4=> PTD0<selection=PTD0_SIG_SEL,LPUART0_RTS_b>
//     <5=> PTC1<selection=PTC1_SIG_SEL,LPUART0_RTS_b>
//     <0=> Default
#define LPUART0_RTS_b_PIN_SEL 0

// Pin Mapping for LPUART0_RX signal
//   <o>    LPUART0_RX<name=LPUART0_RX_PIN_SEL>
//   <i>    Shows which pin LPUART0_RX is mapped to
//   <info>  [PTB10, PTC16, PTE5, PTD8, PTD2, PTC3]
//     <0=> Disabled
//     <1=> PTB10<selection=PTB10_SIG_SEL,LPUART0_RX>
//     <2=> PTC16<selection=PTC16_SIG_SEL,LPUART0_RX>
//     <3=> PTE5<selection=PTE5_SIG_SEL,LPUART0_RX>
//     <4=> PTD8<selection=PTD8_SIG_SEL,LPUART0_RX>
//     <5=> PTD2<selection=PTD2_SIG_SEL,LPUART0_RX>
//     <6=> PTC3<selection=PTC3_SIG_SEL,LPUART0_RX>
//     <0=> Default
#define LPUART0_RX_PIN_SEL   0

// Pin Mapping for LPUART0_TX signal
//   <o>    LPUART0_TX<name=LPUART0_TX_PIN_SEL>
//   <i>    Shows which pin LPUART0_TX is mapped to
//   <info>  [PTB11, PTC17, PTE4, PTD9, PTD3, PTC4]
//     <0=> Disabled
//     <1=> PTB11<selection=PTB11_SIG_SEL,LPUART0_TX>
//     <2=> PTC17<selection=PTC17_SIG_SEL,LPUART0_TX>
//     <3=> PTE4<selection=PTE4_SIG_SEL,LPUART0_TX>
//     <4=> PTD9<selection=PTD9_SIG_SEL,LPUART0_TX>
//     <5=> PTD3<selection=PTD3_SIG_SEL,LPUART0_TX>
//     <6=> PTC4<selection=PTC4_SIG_SEL,LPUART0_TX>
//     <0=> Default
#define LPUART0_TX_PIN_SEL   0

// </h>

// <h> Programmable Delay Block (PDB0)

// Pin Mapping for PDB0_EXTRG signal
//   <o>    PDB0_EXTRG<name=PDB0_EXTRG_PIN_SEL>
//   <i>    Shows which pin PDB0_EXTRG is mapped to
//   <info>  [PTC0, PTC6]
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,PDB0_EXTRG>
//     <2=> PTC6<selection=PTC6_SIG_SEL,PDB0_EXTRG>
//     <0=> Default
#define PDB0_EXTRG_PIN_SEL   0

// </h>

// <h> Serial Peripheral Interface (SPI0)

// Pin Mapping for SPI0_PCS0 signal
//   <o>    SPI0_PCS0<name=SPI0_PCS0_PIN_SEL>
//   <i>    Shows which pin SPI0_PCS0 is mapped to
//   <info>  [PTA14, PTC4, PTD0]
//     <0=> Disabled
//     <1=> PTA14<selection=PTA14_SIG_SEL,SPI0_PCS0>
//     <2=> PTC4<selection=PTC4_SIG_SEL,SPI0_PCS0>
//     <3=> PTD0<selection=PTD0_SIG_SEL,SPI0_PCS0>
//     <0=> Default
#define SPI0_PCS0_PIN_SEL    0

// Pin Mapping for SPI0_PCS1 signal
//   <o>    SPI0_PCS1<name=SPI0_PCS1_PIN_SEL>
//   <i>    Shows which pin SPI0_PCS1 is mapped to
//   <info>  [PTC3, PTD4]
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,SPI0_PCS1>
//     <2=> PTD4<selection=PTD4_SIG_SEL,SPI0_PCS1>
//     <0=> Default
#define SPI0_PCS1_PIN_SEL    0

// Pin Mapping for SPI0_PCS2 signal
//   <o>    SPI0_PCS2<name=SPI0_PCS2_PIN_SEL>
//   <i>    Shows which pin SPI0_PCS2 is mapped to
//   <info>  [PTC2, PTD5]
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,SPI0_PCS2>
//     <2=> PTD5<selection=PTD5_SIG_SEL,SPI0_PCS2>
//     <0=> Default
#define SPI0_PCS2_PIN_SEL    0

// Pin Mapping for SPI0_PCS3 signal
//   <o>    SPI0_PCS3<name=SPI0_PCS3_PIN_SEL>
//   <i>    Shows which pin SPI0_PCS3 is mapped to
//   <info>  [PTC1, PTD6]
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,SPI0_PCS3>
//     <2=> PTD6<selection=PTD6_SIG_SEL,SPI0_PCS3>
//     <0=> Default
#define SPI0_PCS3_PIN_SEL    0

// Pin Mapping for SPI0_PCS4 signal
//   <o>    SPI0_PCS4<name=SPI0_PCS4_PIN_SEL>
//   <i>    Shows which pin SPI0_PCS4 is mapped to
//   <info>  [PTC0]
//     <0=> Disabled
//     <1=> PTC0<selection=PTC0_SIG_SEL,SPI0_PCS4>
//     <0=> Default
#define SPI0_PCS4_PIN_SEL    0

// Pin Mapping for SPI0_PCS5 signal
//   <o>    SPI0_PCS5<name=SPI0_PCS5_PIN_SEL>
//   <i>    Shows which pin SPI0_PCS5 is mapped to
//   <info>  [PTB23]
//     <0=> Disabled
//     <1=> PTB23<selection=PTB23_SIG_SEL,SPI0_PCS5>
//     <0=> Default
#define SPI0_PCS5_PIN_SEL    0

// Pin Mapping for SPI0_SCK signal
//   <o>    SPI0_SCK<name=SPI0_SCK_PIN_SEL>
//   <i>    Shows which pin SPI0_SCK is mapped to
//   <info>  [PTA15, PTC5, PTD1]
//     <0=> Disabled
//     <1=> PTA15<selection=PTA15_SIG_SEL,SPI0_SCK>
//     <2=> PTC5<selection=PTC5_SIG_SEL,SPI0_SCK>
//     <3=> PTD1<selection=PTD1_SIG_SEL,SPI0_SCK>
//     <0=> Default
#define SPI0_SCK_PIN_SEL     0

// Pin Mapping for SPI0_SIN signal
//   <o>    SPI0_SIN<name=SPI0_SIN_PIN_SEL>
//   <i>    Shows which pin SPI0_SIN is mapped to
//   <info>  [PTA17, PTC7, PTD3]
//     <0=> Disabled
//     <1=> PTA17<selection=PTA17_SIG_SEL,SPI0_SIN>
//     <2=> PTC7<selection=PTC7_SIG_SEL,SPI0_SIN>
//     <3=> PTD3<selection=PTD3_SIG_SEL,SPI0_SIN>
//     <0=> Default
#define SPI0_SIN_PIN_SEL     0

// Pin Mapping for SPI0_SOUT signal
//   <o>    SPI0_SOUT<name=SPI0_SOUT_PIN_SEL>
//   <i>    Shows which pin SPI0_SOUT is mapped to
//   <info>  [PTA16, PTC6, PTD2]
//     <0=> Disabled
//     <1=> PTA16<selection=PTA16_SIG_SEL,SPI0_SOUT>
//     <2=> PTC6<selection=PTC6_SIG_SEL,SPI0_SOUT>
//     <3=> PTD2<selection=PTD2_SIG_SEL,SPI0_SOUT>
//     <0=> Default
#define SPI0_SOUT_PIN_SEL    0

// </h>

// <h> Serial Peripheral Interface (SPI1)

// Pin Mapping for SPI1_PCS0 signal
//   <o>    SPI1_PCS0<name=SPI1_PCS0_PIN_SEL>
//   <i>    Shows which pin SPI1_PCS0 is mapped to
//   <info>  [PTB10, PTE4, PTD4]
//     <0=> Disabled
//     <1=> PTB10<selection=PTB10_SIG_SEL,SPI1_PCS0>
//     <2=> PTE4<selection=PTE4_SIG_SEL,SPI1_PCS0>
//     <3=> PTD4<selection=PTD4_SIG_SEL,SPI1_PCS0>
//     <0=> Default
#define SPI1_PCS0_PIN_SEL    0

// Pin Mapping for SPI1_PCS1 signal
//   <o>    SPI1_PCS1<name=SPI1_PCS1_PIN_SEL>
//   <i>    Shows which pin SPI1_PCS1 is mapped to
//   <info>  [PTB9, PTE0]
//     <0=> Disabled
//     <1=> PTB9<selection=PTB9_SIG_SEL,SPI1_PCS1>
//     <2=> PTE0<selection=PTE0_SIG_SEL,SPI1_PCS1>
//     <0=> Default
#define SPI1_PCS1_PIN_SEL    0

// Pin Mapping for SPI1_PCS2 signal
//   <o>    SPI1_PCS2<name=SPI1_PCS2_PIN_SEL>
//   <i>    Shows which pin SPI1_PCS2 is mapped to
//   <info>  [PTE5]
//     <0=> Disabled
//     <1=> PTE5<selection=PTE5_SIG_SEL,SPI1_PCS2>
//     <0=> Default
#define SPI1_PCS2_PIN_SEL    0

// Pin Mapping for SPI1_PCS3 signal
//   <o>    SPI1_PCS3<name=SPI1_PCS3_PIN_SEL>
//   <i>    Shows which pin SPI1_PCS3 is mapped to
//   <info>  [PTE6]
//     <0=> Disabled
//     <1=> PTE6<selection=PTE6_SIG_SEL,SPI1_PCS3>
//     <0=> Default
#define SPI1_PCS3_PIN_SEL    0

// Pin Mapping for SPI1_SCK signal
//   <o>    SPI1_SCK<name=SPI1_SCK_PIN_SEL>
//   <i>    Shows which pin SPI1_SCK is mapped to
//   <info>  [PTB11, PTE2, PTD5]
//     <0=> Disabled
//     <1=> PTB11<selection=PTB11_SIG_SEL,SPI1_SCK>
//     <2=> PTE2<selection=PTE2_SIG_SEL,SPI1_SCK>
//     <3=> PTD5<selection=PTD5_SIG_SEL,SPI1_SCK>
//     <0=> Default
#define SPI1_SCK_PIN_SEL     0

// Pin Mapping for SPI1_SIN signal
//   <o>    SPI1_SIN<name=SPI1_SIN_PIN_SEL>
//   <i>    Shows which pin SPI1_SIN is mapped to
//   <info>  [PTB17, PTE3, PTD7, PTE1]
//     <0=> Disabled
//     <1=> PTB17<selection=PTB17_SIG_SEL,SPI1_SIN>
//     <2=> PTE3<selection=PTE3_SIG_SEL,SPI1_SIN>
//     <3=> PTD7<selection=PTD7_SIG_SEL,SPI1_SIN>
//     <4=> PTE1<selection=PTE1_SIG_SEL,SPI1_SIN>
//     <3=> Default
#define SPI1_SIN_PIN_SEL     3

// Pin Mapping for SPI1_SOUT signal
//   <o>    SPI1_SOUT<name=SPI1_SOUT_PIN_SEL>
//   <i>    Shows which pin SPI1_SOUT is mapped to
//   <info>  [PTB16, PTE1, PTD6, PTE3]
//     <0=> Disabled
//     <1=> PTB16<selection=PTB16_SIG_SEL,SPI1_SOUT>
//     <2=> PTE1<selection=PTE1_SIG_SEL,SPI1_SOUT>
//     <3=> PTD6<selection=PTD6_SIG_SEL,SPI1_SOUT>
//     <4=> PTE3<selection=PTE3_SIG_SEL,SPI1_SOUT>
//     <3=> Default
#define SPI1_SOUT_PIN_SEL    3

// </h>

// <h> Universal Asynchronous Rx/Tx (UART0)

// Pin Mapping for UART0_CTS_b signal
//   <o>    UART0_CTS_b<name=UART0_CTS_b_PIN_SEL>
//   <i>    Shows which pin UART0_CTS_b is mapped to
//   <info>  [PTA0, PTA16, PTB3, PTD5]
//     <0=> Disabled
//     <1=> PTA0<selection=PTA0_SIG_SEL,UART0_CTS_b>
//     <2=> PTA16<selection=PTA16_SIG_SEL,UART0_CTS_b>
//     <3=> PTB3<selection=PTB3_SIG_SEL,UART0_CTS_b>
//     <4=> PTD5<selection=PTD5_SIG_SEL,UART0_CTS_b>
//     <0=> Default
#define UART0_CTS_b_PIN_SEL  0

// Pin Mapping for UART0_RTS_b signal
//   <o>    UART0_RTS_b<name=UART0_RTS_b_PIN_SEL>
//   <i>    Shows which pin UART0_RTS_b is mapped to
//   <info>  [PTA3, PTA17, PTB2, PTD4]
//     <0=> Disabled
//     <1=> PTA3<selection=PTA3_SIG_SEL,UART0_RTS_b>
//     <2=> PTA17<selection=PTA17_SIG_SEL,UART0_RTS_b>
//     <3=> PTB2<selection=PTB2_SIG_SEL,UART0_RTS_b>
//     <4=> PTD4<selection=PTD4_SIG_SEL,UART0_RTS_b>
//     <0=> Default
#define UART0_RTS_b_PIN_SEL  0

// Pin Mapping for UART0_RX signal
//   <o>    UART0_RX<name=UART0_RX_PIN_SEL>
//   <i>    Shows which pin UART0_RX is mapped to
//   <info>  [PTA1, PTA15, PTB16, PTD6]
//     <0=> Disabled
//     <1=> PTA1<selection=PTA1_SIG_SEL,UART0_RX>
//     <2=> PTA15<selection=PTA15_SIG_SEL,UART0_RX>
//     <3=> PTB16<selection=PTB16_SIG_SEL,UART0_RX>
//     <4=> PTD6<selection=PTD6_SIG_SEL,UART0_RX>
//     <0=> Default
#define UART0_RX_PIN_SEL     0

// Pin Mapping for UART0_TX signal
//   <o>    UART0_TX<name=UART0_TX_PIN_SEL>
//   <i>    Shows which pin UART0_TX is mapped to
//   <info>  [PTA2, PTA14, PTB17, PTD7]
//     <0=> Disabled
//     <1=> PTA2<selection=PTA2_SIG_SEL,UART0_TX>
//     <2=> PTA14<selection=PTA14_SIG_SEL,UART0_TX>
//     <3=> PTB17<selection=PTB17_SIG_SEL,UART0_TX>
//     <4=> PTD7<selection=PTD7_SIG_SEL,UART0_TX>
//     <0=> Default
#define UART0_TX_PIN_SEL     0

// </h>

// <h> Universal Asynchronous Rx/Tx (UART1)

// Pin Mapping for UART1_CTS_b signal
//   <o>    UART1_CTS_b<name=UART1_CTS_b_PIN_SEL>
//   <i>    Shows which pin UART1_CTS_b is mapped to
//   <info>  [PTC2, PTE2]
//     <0=> Disabled
//     <1=> PTC2<selection=PTC2_SIG_SEL,UART1_CTS_b>
//     <2=> PTE2<selection=PTE2_SIG_SEL,UART1_CTS_b>
//     <0=> Default
#define UART1_CTS_b_PIN_SEL  0

// Pin Mapping for UART1_RTS_b signal
//   <o>    UART1_RTS_b<name=UART1_RTS_b_PIN_SEL>
//   <i>    Shows which pin UART1_RTS_b is mapped to
//   <info>  [PTC1, PTE3]
//     <0=> Disabled
//     <1=> PTC1<selection=PTC1_SIG_SEL,UART1_RTS_b>
//     <2=> PTE3<selection=PTE3_SIG_SEL,UART1_RTS_b>
//     <0=> Default
#define UART1_RTS_b_PIN_SEL  0

// Pin Mapping for UART1_RX signal
//   <o>    UART1_RX<name=UART1_RX_PIN_SEL>
//   <i>    Shows which pin UART1_RX is mapped to
//   <info>  [PTC3, PTE1]
//     <0=> Disabled
//     <1=> PTC3<selection=PTC3_SIG_SEL,UART1_RX>
//     <2=> PTE1<selection=PTE1_SIG_SEL,UART1_RX>
//     <0=> Default
#define UART1_RX_PIN_SEL     0

// Pin Mapping for UART1_TX signal
//   <o>    UART1_TX<name=UART1_TX_PIN_SEL>
//   <i>    Shows which pin UART1_TX is mapped to
//   <info>  [PTC4, PTE0]
//     <0=> Disabled
//     <1=> PTC4<selection=PTC4_SIG_SEL,UART1_TX>
//     <2=> PTE0<selection=PTE0_SIG_SEL,UART1_TX>
//     <0=> Default
#define UART1_TX_PIN_SEL     0

// </h>

// <h> Universal Asynchronous Rx/Tx (UART2)

// Pin Mapping for UART2_CTS_b signal
//   <o>    UART2_CTS_b<name=UART2_CTS_b_PIN_SEL>
//   <i>    Shows which pin UART2_CTS_b is mapped to
//   <info>  [PTD1]
//     <0=> Disabled
//     <1=> PTD1<selection=PTD1_SIG_SEL,UART2_CTS_b>
//     <0=> Default
#define UART2_CTS_b_PIN_SEL  0

// Pin Mapping for UART2_RTS_b signal
//   <o>    UART2_RTS_b<name=UART2_RTS_b_PIN_SEL>
//   <i>    Shows which pin UART2_RTS_b is mapped to
//   <info>  [PTD0]
//     <0=> Disabled
//     <1=> PTD0<selection=PTD0_SIG_SEL,UART2_RTS_b>
//     <0=> Default
#define UART2_RTS_b_PIN_SEL  0

// Pin Mapping for UART2_RX signal
//   <o>    UART2_RX<name=UART2_RX_PIN_SEL>
//   <i>    Shows which pin UART2_RX is mapped to
//   <info>  [PTD2]
//     <0=> Disabled
//     <1=> PTD2<selection=PTD2_SIG_SEL,UART2_RX>
//     <0=> Default
#define UART2_RX_PIN_SEL     0

// Pin Mapping for UART2_TX signal
//   <o>    UART2_TX<name=UART2_TX_PIN_SEL>
//   <i>    Shows which pin UART2_TX is mapped to
//   <info>  [PTD3]
//     <0=> Disabled
//     <1=> PTD3<selection=PTD3_SIG_SEL,UART2_TX>
//     <0=> Default
#define UART2_TX_PIN_SEL     0

// </h>

// <h> Universal Serial Bus

// Pin Mapping for USB_CLKIN signal
//   <o>    USB_CLKIN<name=USB_CLKIN_PIN_SEL>
//   <i>    Shows which pin USB_CLKIN is mapped to
//   <info>  [PTA5, PTE26]
//     <0=> Disabled
//     <1=> PTA5<selection=PTA5_SIG_SEL,USB_CLKIN>
//     <2=> PTE26<selection=PTE26_SIG_SEL,USB_CLKIN>
//     <0=> Default
#define USB_CLKIN_PIN_SEL    0

// Pin Mapping for USB_SOF_OUT signal
//   <o>    USB_SOF_OUT<name=USB_SOF_OUT_PIN_SEL>
//   <i>    Shows which pin USB_SOF_OUT is mapped to
//   <info>  [PTC7, PTC0, PTE6]
//     <0=> Disabled
//     <1=> PTC7<selection=PTC7_SIG_SEL,USB_SOF_OUT>
//     <2=> PTC0<selection=PTC0_SIG_SEL,USB_SOF_OUT>
//     <3=> PTE6<selection=PTE6_SIG_SEL,USB_SOF_OUT>
//     <0=> Default
#define USB_SOF_OUT_PIN_SEL  0

// </h>

// <h> Voltage Reference (VREF)

// Pin Mapping for VREF_OUT signal
//   <o>    VREF_OUT<name=VREF_OUT_PIN_SEL><constant>
//   <i>    Shows which pin VREF_OUT is mapped to
//   <info>  [VREF_OUT]
//     <0=> VREF_OUT<selection=VREF_OUT_SIG_SEL,VREF_OUT/CMP1_IN5/CMP0_IN5/ADC1_SE18>
//     <0=> Default
#define VREF_OUT_PIN_SEL     0

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

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {PORTA_IRQn};

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

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {PORTB_IRQn};

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

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {PORTC_IRQn};

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

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {PORTD_IRQn};

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

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {PORTE_IRQn};

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
   static constexpr uint32_t clockMask = SIM_SCGC6_ADC0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC6);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {ADC0_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
         /*  0 */  { 0, 0, 0, 0, 0 },
         /*  1 */  { 0, 0, 0, 0, 0 },
         /*  2 */  { 0, 0, 0, 0, 0 },
         /*  3 */  { 0, 0, 0, 0, 0 },
#if (ADC0_SE4b_PIN_SEL == 1)
         /*  4 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  2,  0 },
#else
         /*  4 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC0_SE5b_PIN_SEL == 1)
         /*  5 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  1,  0 },
#else
         /*  5 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC0_SE6b_PIN_SEL == 1)
         /*  6 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  5,  0 },
#else
         /*  6 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC0_SE7b_PIN_SEL == 1)
         /*  7 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  6,  0 },
#else
         /*  7 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC0_SE8_PIN_SEL == 1)
         /*  8 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  0,  0 },
#else
         /*  8 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC0_SE9_PIN_SEL == 1)
         /*  9 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  1,  0 },
#else
         /*  9 */  { 0, 0, 0, 0, 0 },
#endif
         /* 10 */  { 0, 0, 0, 0, 0 },
         /* 11 */  { 0, 0, 0, 0, 0 },
#if (ADC0_SE12_PIN_SEL == 1)
         /* 12 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  2,  0 },
#else
         /* 12 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC0_SE13_PIN_SEL == 1)
         /* 13 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  3,  0 },
#else
         /* 13 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC0_SE14_PIN_SEL == 1)
         /* 14 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  0,  0 },
#else
         /* 14 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC0_SE15_PIN_SEL == 1)
         /* 15 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  1,  0 },
#else
         /* 15 */  { 0, 0, 0, 0, 0 },
#endif
         /* 16 */  { 0, 0, 0, 0, 0 },
#if (ADC0_SE17_PIN_SEL == 1)
         /* 17 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  24, 0 },
#else
         /* 17 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC0_SE18_PIN_SEL == 1)
         /* 18 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  25, 0 },
#else
         /* 18 */  { 0, 0, 0, 0, 0 },
#endif
         /* 19 */  { 0, 0, 0, 0, 0 },
         /* 20 */  { 0, 0, 0, 0, 0 },
         /* 21 */  { 0, 0, 0, 0, 0 },
         /* 22 */  { 0, 0, 0, 0, 0 },
         /* 23 */  { 0, 0, 0, 0, 0 },
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
   static constexpr uint32_t clockMask = SIM_SCGC6_ADC0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC6);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {ADC0_IRQn};

};

/**
 * Peripheral information for Analogue Input
 */
class Adc1Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = ADC1_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC6_ADC1_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC6);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {ADC1_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
         /*  0 */  { 0, 0, 0, 0, 0 },
         /*  1 */  { 0, 0, 0, 0, 0 },
         /*  2 */  { 0, 0, 0, 0, 0 },
         /*  3 */  { 0, 0, 0, 0, 0 },
#if (ADC1_SE4b_PIN_SEL == 1)
         /*  4 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  8,  0 },
#else
         /*  4 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC1_SE5b_PIN_SEL == 1)
         /*  5 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  9,  0 },
#else
         /*  5 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC1_SE6b_PIN_SEL == 1)
         /*  6 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  10, 0 },
#else
         /*  6 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC1_SE7b_PIN_SEL == 1)
         /*  7 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  11, 0 },
#else
         /*  7 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC1_SE8_PIN_SEL == 1)
         /*  8 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  0,  0 },
#else
         /*  8 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC1_SE9_PIN_SEL == 1)
         /*  9 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  1,  0 },
#else
         /*  9 */  { 0, 0, 0, 0, 0 },
#endif
         /* 10 */  { 0, 0, 0, 0, 0 },
         /* 11 */  { 0, 0, 0, 0, 0 },
#if (ADC1_SE12_PIN_SEL == 1)
         /* 12 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  6,  0 },
#else
         /* 12 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC1_SE13_PIN_SEL == 1)
         /* 13 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  7,  0 },
#else
         /* 13 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC1_SE14_PIN_SEL == 1)
         /* 14 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  10, 0 },
#else
         /* 14 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC1_SE15_PIN_SEL == 1)
         /* 15 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  11, 0 },
#else
         /* 15 */  { 0, 0, 0, 0, 0 },
#endif
         /* 16 */  { 0, 0, 0, 0, 0 },
#if (ADC1_SE17_PIN_SEL == 1)
         /* 17 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  17, 0 },
#else
         /* 17 */  { 0, 0, 0, 0, 0 },
#endif
         /* 18 */  { 0, 0, 0, 0, 0 },
         /* 19 */  { 0, 0, 0, 0, 0 },
         /* 20 */  { 0, 0, 0, 0, 0 },
         /* 21 */  { 0, 0, 0, 0, 0 },
         /* 22 */  { 0, 0, 0, 0, 0 },
         /* 23 */  { 0, 0, 0, 0, 0 },
   };
};

/**
 * Peripheral information for Analogue Input
 */
class Adc1aInfo {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = ADC1_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC6_ADC1_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC6);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {ADC1_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
         /*  0 */  { 0, 0, 0, 0, 0 },
         /*  1 */  { 0, 0, 0, 0, 0 },
         /*  2 */  { 0, 0, 0, 0, 0 },
         /*  3 */  { 0, 0, 0, 0, 0 },
#if (ADC1_SE4a_PIN_SEL == 1)
         /*  4 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  0,  0 },
#else
         /*  4 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC1_SE5a_PIN_SEL == 1)
         /*  5 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  1,  0 },
#else
         /*  5 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC1_SE6a_PIN_SEL == 1)
         /*  6 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  2,  0 },
#else
         /*  6 */  { 0, 0, 0, 0, 0 },
#endif
#if (ADC1_SE7a_PIN_SEL == 1)
         /*  7 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  3,  0 },
#else
         /*  7 */  { 0, 0, 0, 0, 0 },
#endif
   };
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
   static constexpr uint32_t clockMask = SIM_SCGC4_CMP_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC4);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {CMP0_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (CMP0_IN0_PIN_SEL == 1)
         /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  6,  0 },
#else
         /*  0 */  { 0, 0, 0, 0, 0 },
#endif
#if (CMP0_IN1_PIN_SEL == 1)
         /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  7,  0 },
#else
         /*  1 */  { 0, 0, 0, 0, 0 },
#endif
#if (CMP0_IN2_PIN_SEL == 1)
         /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  8,  0 },
#else
         /*  2 */  { 0, 0, 0, 0, 0 },
#endif
#if (CMP0_IN3_PIN_SEL == 1)
         /*  3 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  9,  0 },
#else
         /*  3 */  { 0, 0, 0, 0, 0 },
#endif
         /*  4 */  { 0, 0, 0, 0, 0 },
         /*  5 */  { 0, 0, 0, 0, 0 },
   };
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
   static constexpr uint32_t clockMask = SIM_SCGC4_CMP_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC4);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {CMP1_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (CMP1_IN0_PIN_SEL == 1)
         /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  2,  0 },
#else
         /*  0 */  { 0, 0, 0, 0, 0 },
#endif
#if (CMP1_IN1_PIN_SEL == 1)
         /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  3,  0 },
#else
         /*  1 */  { 0, 0, 0, 0, 0 },
#endif
         /*  2 */  { 0, 0, 0, 0, 0 },
         /*  3 */  { 0, 0, 0, 0, 0 },
         /*  4 */  { 0, 0, 0, 0, 0 },
         /*  5 */  { 0, 0, 0, 0, 0 },
   };
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
 * Peripheral information for PWM, Input capture, Output compare
 */
class Ftm0Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = FTM0_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC6_FTM0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC6);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {FTM0_IRQn};

   //! Base value for tmr->SC register
   static constexpr uint32_t scValue  = FTM0_SC;

   //! Indexes of special functions in PcrInfo[] table
   static constexpr int QUAD_INDEX  = 8;
   static constexpr int CLOCK_INDEX = 10;
   static constexpr int FAULT_INDEX = 12;

   static constexpr int NUM_CHANNELS  = 8;

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (FTM0_CH0_PIN_SEL == 1)
         /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  3,  3 },
#elif (FTM0_CH0_PIN_SEL == 2)
         /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  1,  4 },
#else
         /*  0 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM0_CH1_PIN_SEL == 1)
         /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  4,  3 },
#elif (FTM0_CH1_PIN_SEL == 2)
         /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  2,  4 },
#else
         /*  1 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM0_CH2_PIN_SEL == 1)
         /*  2 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  5,  3 },
#elif (FTM0_CH2_PIN_SEL == 2)
         /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  3,  4 },
#elif (FTM0_CH2_PIN_SEL == 3)
         /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  5,  7 },
#else
         /*  2 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM0_CH3_PIN_SEL == 1)
         /*  3 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  4,  4 },
#else
         /*  3 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM0_CH4_PIN_SEL == 1)
         /*  4 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  4,  4 },
#else
         /*  4 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM0_CH5_PIN_SEL == 1)
         /*  5 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  0,  3 },
#elif (FTM0_CH5_PIN_SEL == 2)
         /*  5 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  5,  4 },
#else
         /*  5 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM0_CH6_PIN_SEL == 1)
         /*  6 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  1,  3 },
#elif (FTM0_CH6_PIN_SEL == 2)
         /*  6 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  6,  4 },
#else
         /*  6 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM0_CH7_PIN_SEL == 1)
         /*  7 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  2,  3 },
#elif (FTM0_CH7_PIN_SEL == 2)
         /*  7 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  7,  4 },
#else
         /*  7 */  { 0, 0, 0, 0, 0 },
#endif
         /*  8 */  { 0, 0, 0, 0, 0 },
         /*  9 */  { 0, 0, 0, 0, 0 },
         /* 10 */  { 0, 0, 0, 0, 0 },
         /* 11 */  { 0, 0, 0, 0, 0 },
#if (FTM0_FLT0_PIN_SEL == 1)
         /* 12 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  3,  6 },
#elif (FTM0_FLT0_PIN_SEL == 2)
         /* 12 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  6,  6 },
#else
         /* 12 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM0_FLT1_PIN_SEL == 1)
         /* 13 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  10, 6 },
#elif (FTM0_FLT1_PIN_SEL == 2)
         /* 13 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  7,  6 },
#else
         /* 13 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM0_FLT2_PIN_SEL == 1)
         /* 14 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  18, 3 },
#elif (FTM0_FLT2_PIN_SEL == 2)
         /* 14 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  11, 6 },
#else
         /* 14 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM0_FLT3_PIN_SEL == 1)
         /* 15 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  2,  6 },
#else
         /* 15 */  { 0, 0, 0, 0, 0 },
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
   static constexpr uint32_t clockMask = SIM_SCGC6_FTM1_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC6);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {FTM1_IRQn};

   //! Base value for tmr->SC register
   static constexpr uint32_t scValue  = FTM1_SC;

   //! Indexes of special functions in PcrInfo[] table
   static constexpr int QUAD_INDEX  = 8;
   static constexpr int CLOCK_INDEX = 10;
   static constexpr int FAULT_INDEX = 12;

   static constexpr int NUM_CHANNELS  = 2;

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (FTM1_CH0_PIN_SEL == 1)
         /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  12, 3 },
#elif (FTM1_CH0_PIN_SEL == 2)
         /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  0,  3 },
#else
         /*  0 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM1_CH1_PIN_SEL == 1)
         /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  13, 3 },
#elif (FTM1_CH1_PIN_SEL == 2)
         /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  1,  3 },
#else
         /*  1 */  { 0, 0, 0, 0, 0 },
#endif
         /*  2 */  { 0, 0, 0, 0, 0 },
         /*  3 */  { 0, 0, 0, 0, 0 },
         /*  4 */  { 0, 0, 0, 0, 0 },
         /*  5 */  { 0, 0, 0, 0, 0 },
         /*  6 */  { 0, 0, 0, 0, 0 },
         /*  7 */  { 0, 0, 0, 0, 0 },
#if (FTM1_QD_PHA_PIN_SEL == 1)
         /*  8 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  0,  6 },
#elif (FTM1_QD_PHA_PIN_SEL == 2)
         /*  8 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  12, 7 },
#else
         /*  8 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM1_QD_PHB_PIN_SEL == 1)
         /*  9 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  1,  6 },
#elif (FTM1_QD_PHB_PIN_SEL == 2)
         /*  9 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  13, 7 },
#else
         /*  9 */  { 0, 0, 0, 0, 0 },
#endif
         /* 10 */  { 0, 0, 0, 0, 0 },
         /* 11 */  { 0, 0, 0, 0, 0 },
#if (FTM1_FLT0_PIN_SEL == 1)
         /* 12 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  19, 3 },
#else
         /* 12 */  { 0, 0, 0, 0, 0 },
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
   static constexpr uint32_t clockMask = SIM_SCGC6_FTM2_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC6);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {FTM2_IRQn};

   //! Base value for tmr->SC register
   static constexpr uint32_t scValue  = FTM2_SC;

   //! Indexes of special functions in PcrInfo[] table
   static constexpr int QUAD_INDEX  = 8;
   static constexpr int CLOCK_INDEX = 10;
   static constexpr int FAULT_INDEX = 12;

   static constexpr int NUM_CHANNELS  = 2;

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (FTM2_CH0_PIN_SEL == 1)
         /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  10, 3 },
#elif (FTM2_CH0_PIN_SEL == 2)
         /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  18, 3 },
#else
         /*  0 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM2_CH1_PIN_SEL == 1)
         /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  11, 3 },
#elif (FTM2_CH1_PIN_SEL == 2)
         /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  19, 3 },
#else
         /*  1 */  { 0, 0, 0, 0, 0 },
#endif
         /*  2 */  { 0, 0, 0, 0, 0 },
         /*  3 */  { 0, 0, 0, 0, 0 },
         /*  4 */  { 0, 0, 0, 0, 0 },
         /*  5 */  { 0, 0, 0, 0, 0 },
         /*  6 */  { 0, 0, 0, 0, 0 },
         /*  7 */  { 0, 0, 0, 0, 0 },
#if (FTM2_QD_PHA_PIN_SEL == 1)
         /*  8 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  10, 6 },
#elif (FTM2_QD_PHA_PIN_SEL == 2)
         /*  8 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  18, 6 },
#else
         /*  8 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM2_QD_PHB_PIN_SEL == 1)
         /*  9 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  11, 6 },
#elif (FTM2_QD_PHB_PIN_SEL == 2)
         /*  9 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  19, 6 },
#else
         /*  9 */  { 0, 0, 0, 0, 0 },
#endif
         /* 10 */  { 0, 0, 0, 0, 0 },
         /* 11 */  { 0, 0, 0, 0, 0 },
#if (FTM2_FLT0_PIN_SEL == 1)
         /* 12 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  9,  6 },
#else
         /* 12 */  { 0, 0, 0, 0, 0 },
#endif
   };
};

/**
 * Peripheral information for PWM, Input capture, Output compare
 */
class Ftm3Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = FTM3_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 0;

   //! Base value for tmr->SC register
   static constexpr uint32_t scValue  = FTM3_SC;

   //! Indexes of special functions in PcrInfo[] table
   static constexpr int QUAD_INDEX  = 8;
   static constexpr int CLOCK_INDEX = 10;
   static constexpr int FAULT_INDEX = 12;

   static constexpr int NUM_CHANNELS  = 8;

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (FTM3_CH0_PIN_SEL == 1)
         /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  0,  4 },
#elif (FTM3_CH0_PIN_SEL == 2)
         /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  5,  6 },
#else
         /*  0 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM3_CH1_PIN_SEL == 1)
         /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  1,  4 },
#elif (FTM3_CH1_PIN_SEL == 2)
         /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  6,  6 },
#else
         /*  1 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM3_CH2_PIN_SEL == 1)
         /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  2,  4 },
#else
         /*  2 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM3_CH3_PIN_SEL == 1)
         /*  3 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  3,  4 },
#else
         /*  3 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM3_CH4_PIN_SEL == 1)
         /*  4 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  8,  3 },
#else
         /*  4 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM3_CH5_PIN_SEL == 1)
         /*  5 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  9,  3 },
#else
         /*  5 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM3_CH6_PIN_SEL == 1)
         /*  6 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  10, 3 },
#else
         /*  6 */  { 0, 0, 0, 0, 0 },
#endif
#if (FTM3_CH7_PIN_SEL == 1)
         /*  7 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  11, 3 },
#else
         /*  7 */  { 0, 0, 0, 0, 0 },
#endif
         /*  8 */  { 0, 0, 0, 0, 0 },
         /*  9 */  { 0, 0, 0, 0, 0 },
         /* 10 */  { 0, 0, 0, 0, 0 },
         /* 11 */  { 0, 0, 0, 0, 0 },
#if (FTM3_FLT0_PIN_SEL == 1)
         /* 12 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  12, 3 },
#elif (FTM3_FLT0_PIN_SEL == 2)
         /* 12 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  12, 6 },
#else
         /* 12 */  { 0, 0, 0, 0, 0 },
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
   static constexpr uint32_t clockMask = SIM_SCGC4_I2C0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC4);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {I2C0_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (I2C0_SCL_PIN_SEL == 1)
         /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  0,  2 },
#elif (I2C0_SCL_PIN_SEL == 2)
         /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  2,  2 },
#elif (I2C0_SCL_PIN_SEL == 3)
         /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  8,  2 },
#elif (I2C0_SCL_PIN_SEL == 4)
         /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  24, 5 },
#elif (I2C0_SCL_PIN_SEL == 5)
         /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  2,  7 },
#else
         /*  0 */  { 0, 0, 0, 0, 0 },
#endif
#if (I2C0_SDA_PIN_SEL == 1)
         /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  1,  2 },
#elif (I2C0_SDA_PIN_SEL == 2)
         /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  3,  2 },
#elif (I2C0_SDA_PIN_SEL == 3)
         /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  9,  2 },
#elif (I2C0_SDA_PIN_SEL == 4)
         /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  25, 5 },
#elif (I2C0_SDA_PIN_SEL == 5)
         /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  3,  7 },
#else
         /*  1 */  { 0, 0, 0, 0, 0 },
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
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {I2C1_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (I2C1_SCL_PIN_SEL == 1)
         /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  10, 2 },
#elif (I2C1_SCL_PIN_SEL == 2)
         /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  1,  6 },
#else
         /*  0 */  { 0, 0, 0, 0, 0 },
#endif
#if (I2C1_SDA_PIN_SEL == 1)
         /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  11, 2 },
#elif (I2C1_SDA_PIN_SEL == 2)
         /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  0,  6 },
#else
         /*  1 */  { 0, 0, 0, 0, 0 },
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
   static constexpr uint32_t clockMask = SIM_SCGC5_LPTMR_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC5);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {LPTMR0_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
         /*  0 */  { 0, 0, 0, 0, 0 },
#if (LPTMR0_ALT1_PIN_SEL == 1)
         /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  19, 6 },
#else
         /*  1 */  { 0, 0, 0, 0, 0 },
#endif
#if (LPTMR0_ALT2_PIN_SEL == 1)
         /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  5,  3 },
#else
         /*  2 */  { 0, 0, 0, 0, 0 },
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
   static constexpr uint32_t clockMask = SIM_SCGC6_PIT_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC6);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 4;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {PIT0_IRQn, PIT1_IRQn, PIT2_IRQn, PIT3_IRQn};

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
         /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  1,  1 },
#else
         /*  0 */  { 0, 0, 0, 0, 0 },
#endif
#if (LLWU_P1_PIN_SEL == 1)
         /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  2,  1 },
#else
         /*  1 */  { 0, 0, 0, 0, 0 },
#endif
#if (LLWU_P2_PIN_SEL == 1)
         /*  2 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  4,  1 },
#else
         /*  2 */  { 0, 0, 0, 0, 0 },
#endif
#if (LLWU_P3_PIN_SEL == 1)
         /*  3 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  4,  1 },
#else
         /*  3 */  { 0, 0, 0, 0, 0 },
#endif
#if (LLWU_P4_PIN_SEL == 1)
         /*  4 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  13, 1 },
#else
         /*  4 */  { 0, 0, 0, 0, 0 },
#endif
#if (LLWU_P5_PIN_SEL == 1)
         /*  5 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  0,  1 },
#else
         /*  5 */  { 0, 0, 0, 0, 0 },
#endif
#if (LLWU_P6_PIN_SEL == 1)
         /*  6 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  1,  1 },
#else
         /*  6 */  { 0, 0, 0, 0, 0 },
#endif
#if (LLWU_P7_PIN_SEL == 1)
         /*  7 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  3,  1 },
#else
         /*  7 */  { 0, 0, 0, 0, 0 },
#endif
#if (LLWU_P8_PIN_SEL == 1)
         /*  8 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  4,  1 },
#else
         /*  8 */  { 0, 0, 0, 0, 0 },
#endif
#if (LLWU_P9_PIN_SEL == 1)
         /*  9 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  5,  1 },
#else
         /*  9 */  { 0, 0, 0, 0, 0 },
#endif
#if (LLWU_P10_PIN_SEL == 1)
         /* 10 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  6,  1 },
#else
         /* 10 */  { 0, 0, 0, 0, 0 },
#endif
#if (LLWU_P11_PIN_SEL == 1)
         /* 11 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  11, 1 },
#else
         /* 11 */  { 0, 0, 0, 0, 0 },
#endif
#if (LLWU_P12_PIN_SEL == 1)
         /* 12 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  0,  1 },
#else
         /* 12 */  { 0, 0, 0, 0, 0 },
#endif
#if (LLWU_P13_PIN_SEL == 1)
         /* 13 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  2,  1 },
#else
         /* 13 */  { 0, 0, 0, 0, 0 },
#endif
#if (LLWU_P14_PIN_SEL == 1)
         /* 14 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  4,  1 },
#else
         /* 14 */  { 0, 0, 0, 0, 0 },
#endif
#if (LLWU_P15_PIN_SEL == 1)
         /* 15 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  6,  1 },
#else
         /* 15 */  { 0, 0, 0, 0, 0 },
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
   static constexpr uint32_t clockMask = SIM_SCGC6_SPI0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC6);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {SPI0_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (SPI0_SCK_PIN_SEL == 1)
         /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  15, 2 },
#elif (SPI0_SCK_PIN_SEL == 2)
         /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  5,  2 },
#elif (SPI0_SCK_PIN_SEL == 3)
         /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  1,  2 },
#else
         /*  0 */  { 0, 0, 0, 0, 0 },
#endif
#if (SPI0_SIN_PIN_SEL == 1)
         /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  17, 2 },
#elif (SPI0_SIN_PIN_SEL == 2)
         /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  7,  2 },
#elif (SPI0_SIN_PIN_SEL == 3)
         /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  3,  2 },
#else
         /*  1 */  { 0, 0, 0, 0, 0 },
#endif
#if (SPI0_SOUT_PIN_SEL == 1)
         /*  2 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  16, 2 },
#elif (SPI0_SOUT_PIN_SEL == 2)
         /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  6,  2 },
#elif (SPI0_SOUT_PIN_SEL == 3)
         /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  2,  2 },
#else
         /*  2 */  { 0, 0, 0, 0, 0 },
#endif
#if (SPI0_PCS0_PIN_SEL == 1)
         /*  3 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  14, 2 },
#elif (SPI0_PCS0_PIN_SEL == 2)
         /*  3 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  4,  2 },
#elif (SPI0_PCS0_PIN_SEL == 3)
         /*  3 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  0,  2 },
#else
         /*  3 */  { 0, 0, 0, 0, 0 },
#endif
#if (SPI0_PCS1_PIN_SEL == 1)
         /*  4 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  3,  2 },
#elif (SPI0_PCS1_PIN_SEL == 2)
         /*  4 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  4,  2 },
#else
         /*  4 */  { 0, 0, 0, 0, 0 },
#endif
#if (SPI0_PCS2_PIN_SEL == 1)
         /*  5 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  2,  2 },
#elif (SPI0_PCS2_PIN_SEL == 2)
         /*  5 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  5,  2 },
#else
         /*  5 */  { 0, 0, 0, 0, 0 },
#endif
#if (SPI0_PCS3_PIN_SEL == 1)
         /*  6 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  1,  2 },
#elif (SPI0_PCS3_PIN_SEL == 2)
         /*  6 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  6,  2 },
#else
         /*  6 */  { 0, 0, 0, 0, 0 },
#endif
#if (SPI0_PCS4_PIN_SEL == 1)
         /*  7 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  0,  2 },
#else
         /*  7 */  { 0, 0, 0, 0, 0 },
#endif
#if (SPI0_PCS5_PIN_SEL == 1)
         /*  8 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  23, 3 },
#else
         /*  8 */  { 0, 0, 0, 0, 0 },
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
   static constexpr uint32_t clockMask = SIM_SCGC6_SPI1_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC6);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {SPI1_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (SPI1_SCK_PIN_SEL == 1)
         /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  11, 2 },
#elif (SPI1_SCK_PIN_SEL == 2)
         /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  2,  2 },
#elif (SPI1_SCK_PIN_SEL == 3)
         /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  5,  7 },
#else
         /*  0 */  { 0, 0, 0, 0, 0 },
#endif
#if (SPI1_SIN_PIN_SEL == 1)
         /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  17, 2 },
#elif (SPI1_SIN_PIN_SEL == 2)
         /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  3,  2 },
#elif (SPI1_SIN_PIN_SEL == 3)
         /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  7,  7 },
#elif (SPI1_SIN_PIN_SEL == 4)
         /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  1,  7 },
#else
         /*  1 */  { 0, 0, 0, 0, 0 },
#endif
#if (SPI1_SOUT_PIN_SEL == 1)
         /*  2 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  16, 2 },
#elif (SPI1_SOUT_PIN_SEL == 2)
         /*  2 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  1,  2 },
#elif (SPI1_SOUT_PIN_SEL == 3)
         /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  6,  7 },
#elif (SPI1_SOUT_PIN_SEL == 4)
         /*  2 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  3,  7 },
#else
         /*  2 */  { 0, 0, 0, 0, 0 },
#endif
#if (SPI1_PCS0_PIN_SEL == 1)
         /*  3 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  10, 2 },
#elif (SPI1_PCS0_PIN_SEL == 2)
         /*  3 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  4,  2 },
#elif (SPI1_PCS0_PIN_SEL == 3)
         /*  3 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  4,  7 },
#else
         /*  3 */  { 0, 0, 0, 0, 0 },
#endif
#if (SPI1_PCS1_PIN_SEL == 1)
         /*  4 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  9,  2 },
#elif (SPI1_PCS1_PIN_SEL == 2)
         /*  4 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  0,  2 },
#else
         /*  4 */  { 0, 0, 0, 0, 0 },
#endif
#if (SPI1_PCS2_PIN_SEL == 1)
         /*  5 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  5,  2 },
#else
         /*  5 */  { 0, 0, 0, 0, 0 },
#endif
#if (SPI1_PCS3_PIN_SEL == 1)
         /*  6 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  6,  2 },
#else
         /*  6 */  { 0, 0, 0, 0, 0 },
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
   static constexpr uint32_t irqCount  = 2;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {UART0_RX_TX_IRQn, UART0_ERR_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (UART0_TX_PIN_SEL == 1)
         /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  2,  2 },
#elif (UART0_TX_PIN_SEL == 2)
         /*  0 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  14, 3 },
#elif (UART0_TX_PIN_SEL == 3)
         /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  17, 3 },
#elif (UART0_TX_PIN_SEL == 4)
         /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  7,  3 },
#else
         /*  0 */  { 0, 0, 0, 0, 0 },
#endif
#if (UART0_RX_PIN_SEL == 1)
         /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  1,  2 },
#elif (UART0_RX_PIN_SEL == 2)
         /*  1 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  15, 3 },
#elif (UART0_RX_PIN_SEL == 3)
         /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  16, 3 },
#elif (UART0_RX_PIN_SEL == 4)
         /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  6,  3 },
#else
         /*  1 */  { 0, 0, 0, 0, 0 },
#endif
#if (UART0_RTS_b_PIN_SEL == 1)
         /*  2 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  3,  2 },
#elif (UART0_RTS_b_PIN_SEL == 2)
         /*  2 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  17, 3 },
#elif (UART0_RTS_b_PIN_SEL == 3)
         /*  2 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  2,  3 },
#elif (UART0_RTS_b_PIN_SEL == 4)
         /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  4,  3 },
#else
         /*  2 */  { 0, 0, 0, 0, 0 },
#endif
#if (UART0_CTS_b_PIN_SEL == 1)
         /*  3 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  0,  2 },
#elif (UART0_CTS_b_PIN_SEL == 2)
         /*  3 */  { PORTA_CLOCK_MASK, PORTA_BasePtr,  GPIOA_BasePtr,  16, 3 },
#elif (UART0_CTS_b_PIN_SEL == 3)
         /*  3 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  3,  3 },
#elif (UART0_CTS_b_PIN_SEL == 4)
         /*  3 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  5,  3 },
#else
         /*  3 */  { 0, 0, 0, 0, 0 },
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
   static constexpr uint32_t clockMask = SIM_SCGC4_UART1_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC4);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 2;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {UART1_RX_TX_IRQn, UART1_ERR_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (UART1_TX_PIN_SEL == 1)
         /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  4,  3 },
#elif (UART1_TX_PIN_SEL == 2)
         /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  0,  3 },
#else
         /*  0 */  { 0, 0, 0, 0, 0 },
#endif
#if (UART1_RX_PIN_SEL == 1)
         /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  3,  3 },
#elif (UART1_RX_PIN_SEL == 2)
         /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  1,  3 },
#else
         /*  1 */  { 0, 0, 0, 0, 0 },
#endif
#if (UART1_RTS_b_PIN_SEL == 1)
         /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  1,  3 },
#elif (UART1_RTS_b_PIN_SEL == 2)
         /*  2 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  3,  3 },
#else
         /*  2 */  { 0, 0, 0, 0, 0 },
#endif
#if (UART1_CTS_b_PIN_SEL == 1)
         /*  3 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  2,  3 },
#elif (UART1_CTS_b_PIN_SEL == 2)
         /*  3 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  2,  3 },
#else
         /*  3 */  { 0, 0, 0, 0, 0 },
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
   static constexpr uint32_t clockMask = SIM_SCGC4_UART2_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC4);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 2;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {UART2_RX_TX_IRQn, UART2_ERR_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (UART2_TX_PIN_SEL == 1)
         /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  3,  3 },
#else
         /*  0 */  { 0, 0, 0, 0, 0 },
#endif
#if (UART2_RX_PIN_SEL == 1)
         /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  2,  3 },
#else
         /*  1 */  { 0, 0, 0, 0, 0 },
#endif
#if (UART2_RTS_b_PIN_SEL == 1)
         /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  0,  3 },
#else
         /*  2 */  { 0, 0, 0, 0, 0 },
#endif
#if (UART2_CTS_b_PIN_SEL == 1)
         /*  3 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  1,  3 },
#else
         /*  3 */  { 0, 0, 0, 0, 0 },
#endif
   };
};

/**
 * Peripheral information for LPUART, Low Power Universal Asynchonous Receiver/Transmitter
 */
class Lpuart0Info {
public:
   //! Hardware base pointer
   static constexpr uint32_t basePtr   = LPUART0_BasePtr;

   //! Base value for PCR (excluding MUX value)
   static constexpr uint32_t pcrValue  = DEFAULT_PCR;

   //! Clock mask for peripheral
   static constexpr uint32_t clockMask = SIM_SCGC6_LPUART0_MASK;

   //! Address of clock register for peripheral
   static constexpr uint32_t clockReg  = SIM_BasePtr+offsetof(SIM_Type,SCGC6);

   //! Number of IRQs for hardware
   static constexpr uint32_t irqCount  = 1;

   //! IRQ numbers for hardware
   static constexpr IRQn_Type irqNums[]  = {LPUART0_RX_TX_IRQn};

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
#if (LPUART0_TX_PIN_SEL == 1)
         /*  0 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  11, 3 },
#elif (LPUART0_TX_PIN_SEL == 2)
         /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  17, 3 },
#elif (LPUART0_TX_PIN_SEL == 3)
         /*  0 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  4,  3 },
#elif (LPUART0_TX_PIN_SEL == 4)
         /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  9,  5 },
#elif (LPUART0_TX_PIN_SEL == 5)
         /*  0 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  3,  6 },
#elif (LPUART0_TX_PIN_SEL == 6)
         /*  0 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  4,  7 },
#else
         /*  0 */  { 0, 0, 0, 0, 0 },
#endif
#if (LPUART0_RX_PIN_SEL == 1)
         /*  1 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  10, 3 },
#elif (LPUART0_RX_PIN_SEL == 2)
         /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  16, 3 },
#elif (LPUART0_RX_PIN_SEL == 3)
         /*  1 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  5,  3 },
#elif (LPUART0_RX_PIN_SEL == 4)
         /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  8,  5 },
#elif (LPUART0_RX_PIN_SEL == 5)
         /*  1 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  2,  6 },
#elif (LPUART0_RX_PIN_SEL == 6)
         /*  1 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  3,  7 },
#else
         /*  1 */  { 0, 0, 0, 0, 0 },
#endif
#if (LPUART0_RTS_b_PIN_SEL == 1)
         /*  2 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  8,  3 },
#elif (LPUART0_RTS_b_PIN_SEL == 2)
         /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  18, 3 },
#elif (LPUART0_RTS_b_PIN_SEL == 3)
         /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  10, 5 },
#elif (LPUART0_RTS_b_PIN_SEL == 4)
         /*  2 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  0,  6 },
#elif (LPUART0_RTS_b_PIN_SEL == 5)
         /*  2 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  1,  7 },
#else
         /*  2 */  { 0, 0, 0, 0, 0 },
#endif
#if (LPUART0_CTS_b_PIN_SEL == 1)
         /*  3 */  { PORTB_CLOCK_MASK, PORTB_BasePtr,  GPIOB_BasePtr,  9,  3 },
#elif (LPUART0_CTS_b_PIN_SEL == 2)
         /*  3 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  19, 3 },
#elif (LPUART0_CTS_b_PIN_SEL == 3)
         /*  3 */  { PORTE_CLOCK_MASK, PORTE_BasePtr,  GPIOE_BasePtr,  6,  3 },
#elif (LPUART0_CTS_b_PIN_SEL == 4)
         /*  3 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  11, 5 },
#elif (LPUART0_CTS_b_PIN_SEL == 5)
         /*  3 */  { PORTD_CLOCK_MASK, PORTD_BasePtr,  GPIOD_BasePtr,  1,  6 },
#elif (LPUART0_CTS_b_PIN_SEL == 6)
         /*  3 */  { PORTC_CLOCK_MASK, PORTC_BasePtr,  GPIOC_BasePtr,  2,  7 },
#else
         /*  3 */  { 0, 0, 0, 0, 0 },
#endif
   };
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

   //! Information for each pin of peripheral
   static constexpr PcrInfo  info[32] = {

         //          clockMask         pcrAddress      gpioAddress gpioBit muxValue
         /*  0 */  { 0, 0, 0, 0, 0 },
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
template<uint8_t channel> using Adc1 = Adc_T<Adc1Info, channel>;

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
template<uint8_t channel> using Adc1a = Adc_T<Adc1aInfo, channel>;

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
template<uint8_t channel> using Ftm3 = TmrBase_T<Ftm3Info, channel>;

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

namespace USBDM {

/**
 * @addtogroup DMA_Group Direct Memory Access (DMA)
 * @brief Support for DMA operations
 * @{
 */
enum {
   DMA0_SLOT_Disabled                   = 0,
   DMA0_SLOT_UART0_Receive              = 2,
   DMA0_SLOT_UART0_Transmit             = 3,
   DMA0_SLOT_UART1_Receive              = 4,
   DMA0_SLOT_UART1_Transmit             = 5,
   DMA0_SLOT_UART2_Receive              = 6,
   DMA0_SLOT_UART2_Transmit             = 7,
   DMA0_SLOT_I2S0_Receive               = 12,
   DMA0_SLOT_I2S0_Transmit              = 13,
   DMA0_SLOT_SPI0_Receive               = 14,
   DMA0_SLOT_SPI0_Transmit              = 15,
   DMA0_SLOT_SPI0_TransmitReceive       = 16,
   DMA0_SLOT_I2C0                       = 18,
   DMA0_SLOT_I2C1                       = 19,
   DMA0_SLOT_FTM0_Ch_0                  = 20,
   DMA0_SLOT_FTM0_Ch_1                  = 21,
   DMA0_SLOT_FTM0_Ch_2                  = 22,
   DMA0_SLOT_FTM0_Ch_3                  = 23,
   DMA0_SLOT_FTM0_Ch_4                  = 24,
   DMA0_SLOT_FTM0_Ch_5                  = 25,
   DMA0_SLOT_FTM0_Ch_6                  = 26,
   DMA0_SLOT_FTM0_Ch_7                  = 27,
   DMA0_SLOT_FTM1_Ch_0                  = 28,
   DMA0_SLOT_FTM1_Ch_1                  = 29,
   DMA0_SLOT_FTM2_Ch_0                  = 30,
   DMA0_SLOT_FTM2_Ch_1                  = 31,
   DMA0_SLOT_FTM3_Ch_0                  = 32,
   DMA0_SLOT_FTM3_Ch_1                  = 33,
   DMA0_SLOT_FTM3_Ch_2                  = 34,
   DMA0_SLOT_FTM3_Ch_3                  = 35,
   DMA0_SLOT_FTM3_Ch_4                  = 36,
   DMA0_SLOT_FTM3_Ch_5                  = 37,
   DMA0_SLOT_FTM3_Ch_6                  = 38,
   DMA0_SLOT_FTM3_Ch_7                  = 39,
   DMA0_SLOT_ADC0                       = 40,
   DMA0_SLOT_ADC1                       = 41,
   DMA0_SLOT_CMP0                       = 42,
   DMA0_SLOT_CMP1                       = 43,
   DMA0_SLOT_DAC0                       = 45,
   DMA0_SLOT_DAC1                       = 46,
   DMA0_SLOT_PDB                        = 48,
   DMA0_SLOT_PortA                      = 49,
   DMA0_SLOT_PortB                      = 50,
   DMA0_SLOT_PortC                      = 51,
   DMA0_SLOT_PortD                      = 52,
   DMA0_SLOT_PortE                      = 53,
   DMA0_SLOT_LPUART_Receive             = 58,
   DMA0_SLOT_LPUART_Transmit            = 59,
   DMA0_SLOT_AlwaysEnabled0             = 60,
   DMA0_SLOT_AlwaysEnabled1             = 61,
   DMA0_SLOT_AlwaysEnabled2             = 62,
   DMA0_SLOT_AlwaysEnabled3             = 63,
};
/**
 * @}
 */

} // End namespace USBDM

#endif /* PIN_MAPPING_H_ */
