/**
 * @file      pin_mapping.h (derived from pin_mapping-MK22F51212.h)
 * @version   1.0.0
 * @brief     Pin declarations for MK22F51212
 */

#ifndef PIN_MAPPING_H_
#define PIN_MAPPING_H_

#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

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

// <h> GPIO Options

// Inline port functions
//
//   <q> Force inline port functions 
//   <i> This option forces some small GPIO functions to be inlined
//   <i> This increases speed but may also increase code size
//     <0=> Disabled
//     <1=> Enabled
#define DO_INLINE_GPIO   0

// </h>

// <h> Pin Peripheral mapping

// ADC0_DM0 Pin Mapping
//   <o> ADC0_DM0  [ADC0_DM0/ADC1_DM3] <constant>
//   <i> Selects which peripheral function is mapped to ADC0_DM0 pin
//     <0=> ADC0_DM0/ADC1_DM3
//     <0=> Default
#define ADC0_DM0_SEL         0                   

// ADC0_DM1 Pin Mapping
//   <o> ADC0_DM1  [ADC0_DM1] <constant>
//   <i> Selects which peripheral function is mapped to ADC0_DM1 pin
//     <0=> ADC0_DM1
//     <0=> Default
#define ADC0_DM1_SEL         0                   

// ADC0_DP0 Pin Mapping
//   <o> ADC0_DP0  [ADC0_DP0/ADC1_DP3] <constant>
//   <i> Selects which peripheral function is mapped to ADC0_DP0 pin
//     <0=> ADC0_DP0/ADC1_DP3
//     <0=> Default
#define ADC0_DP0_SEL         0                   

// ADC0_DP1 Pin Mapping
//   <o> ADC0_DP1  [ADC0_DP1] <constant>
//   <i> Selects which peripheral function is mapped to ADC0_DP1 pin
//     <0=> ADC0_DP1
//     <0=> Default
#define ADC0_DP1_SEL         0                   

// ADC0_SE23 Pin Mapping
//   <o> ADC0_SE23  [ADC0_SE23] <constant>
//   <i> Selects which peripheral function is mapped to ADC0_SE23 pin
//     <0=> ADC0_SE23
//     <0=> Default
#define ADC0_SE23_SEL        0                   

// ADC1_DM0 Pin Mapping
//   <o> ADC1_DM0  [ADC1_DM0/ADC0_DM3] <constant>
//   <i> Selects which peripheral function is mapped to ADC1_DM0 pin
//     <0=> ADC1_DM0/ADC0_DM3
//     <0=> Default
#define ADC1_DM0_SEL         0                   

// ADC1_DM1 Pin Mapping
//   <o> ADC1_DM1  [ADC1_DM1/ADC0_DM2] <constant>
//   <i> Selects which peripheral function is mapped to ADC1_DM1 pin
//     <0=> ADC1_DM1/ADC0_DM2
//     <0=> Default
#define ADC1_DM1_SEL         0                   

// ADC1_DP0 Pin Mapping
//   <o> ADC1_DP0  [ADC1_DP0/ADC0_DP3] <constant>
//   <i> Selects which peripheral function is mapped to ADC1_DP0 pin
//     <0=> ADC1_DP0/ADC0_DP3
//     <0=> Default
#define ADC1_DP0_SEL         0                   

// ADC1_DP1 Pin Mapping
//   <o> ADC1_DP1  [ADC1_DP1/ADC0_DP2] <constant>
//   <i> Selects which peripheral function is mapped to ADC1_DP1 pin
//     <0=> ADC1_DP1/ADC0_DP2
//     <0=> Default
#define ADC1_DP1_SEL         0                   

// ADC1_SE18 Pin Mapping
//   <o> ADC1_SE18  [ADC1_SE18] <constant>
//   <i> Selects which peripheral function is mapped to ADC1_SE18 pin
//     <0=> ADC1_SE18
//     <0=> Default
#define ADC1_SE18_SEL        0                   

// ADC1_SE23 Pin Mapping
//   <o> ADC1_SE23  [ADC1_SE23] <constant>
//   <i> Selects which peripheral function is mapped to ADC1_SE23 pin
//     <0=> ADC1_SE23
//     <0=> Default
#define ADC1_SE23_SEL        0                   

// PTA0 Pin Mapping
//   <o> PTA0  [GPIOA_0, FTM0_CH5] 
//   <i> Selects which peripheral function is mapped to PTA0 pin
//     <1=> GPIOA_0
//     <3=> FTM0_CH5
//     <1=> Default
#define PTA0_SEL             1                   

// PTA1 Pin Mapping
//   <o> PTA1  (Alias:D9)  [GPIOA_1, FTM0_CH6] 
//   <i> Selects which peripheral function is mapped to PTA1 pin
//     <1=> GPIOA_1
//     <3=> FTM0_CH6
//     <1=> Default
#define PTA1_SEL             1                   

// PTA2 Pin Mapping
//   <o> PTA2  (Alias:D3)  [GPIOA_2, FTM0_CH7] 
//   <i> Selects which peripheral function is mapped to PTA2 pin
//     <1=> GPIOA_2
//     <3=> FTM0_CH7
//     <1=> Default
#define PTA2_SEL             1                   

// PTA3 Pin Mapping
//   <o> PTA3  [GPIOA_3, FTM0_CH0] 
//   <i> Selects which peripheral function is mapped to PTA3 pin
//     <1=> GPIOA_3
//     <3=> FTM0_CH0
//     <1=> Default
#define PTA3_SEL             1                   

// PTA4 Pin Mapping
//   <o> PTA4  (Alias:D4)  [GPIOA_4, FTM0_CH1] 
//   <i> Selects which peripheral function is mapped to PTA4 pin
//     <1=> GPIOA_4
//     <3=> FTM0_CH1
//     <1=> Default
#define PTA4_SEL             1                   

// PTA5 Pin Mapping
//   <o> PTA5  [GPIOA_5, FTM0_CH2] 
//   <i> Selects which peripheral function is mapped to PTA5 pin
//     <1=> GPIOA_5
//     <3=> FTM0_CH2
//     <1=> Default
#define PTA5_SEL             1                   

// PTA12 Pin Mapping
//   <o> PTA12  [GPIOA_12, FTM1_CH0] 
//   <i> Selects which peripheral function is mapped to PTA12 pin
//     <1=> GPIOA_12
//     <3=> FTM1_CH0
//     <1=> Default
#define PTA12_SEL            1                   

// PTA13 Pin Mapping
//   <o> PTA13  [GPIOA_13, FTM1_CH1] 
//   <i> Selects which peripheral function is mapped to PTA13 pin
//     <1=> GPIOA_13
//     <3=> FTM1_CH1
//     <1=> Default
#define PTA13_SEL            1                   

// PTA14 Pin Mapping
//   <o> PTA14  [GPIOA_14, SPI0_PCS0] 
//   <i> Selects which peripheral function is mapped to PTA14 pin
//     <1=> GPIOA_14
//     <2=> SPI0_PCS0
//     <1=> Default
#define PTA14_SEL            1                   

// PTA15 Pin Mapping
//   <o> PTA15  [GPIOA_15, SPI0_SCK] 
//   <i> Selects which peripheral function is mapped to PTA15 pin
//     <1=> GPIOA_15
//     <2=> SPI0_SCK
//     <1=> Default
#define PTA15_SEL            1                   

// PTA16 Pin Mapping
//   <o> PTA16  [GPIOA_16, SPI0_SOUT] 
//   <i> Selects which peripheral function is mapped to PTA16 pin
//     <1=> GPIOA_16
//     <2=> SPI0_SOUT
//     <1=> Default
#define PTA16_SEL            1                   

// PTA17 Pin Mapping
//   <o> PTA17  [ADC1_SE17, GPIOA_17, SPI0_SIN] 
//   <i> Selects which peripheral function is mapped to PTA17 pin
//     <0=> ADC1_SE17
//     <1=> GPIOA_17
//     <2=> SPI0_SIN
//     <0=> Default
#define PTA17_SEL            0                   

// PTA18 Pin Mapping
//   <o> PTA18  [GPIOA_18] <constant>
//   <i> Selects which peripheral function is mapped to PTA18 pin
//     <1=> GPIOA_18
//     <1=> Default
#define PTA18_SEL            1                   

// PTA19 Pin Mapping
//   <o> PTA19  [GPIOA_19, LPTMR0_ALT1] 
//   <i> Selects which peripheral function is mapped to PTA19 pin
//     <1=> GPIOA_19
//     <6=> LPTMR0_ALT1
//     <1=> Default
#define PTA19_SEL            1                   

// PTB0 Pin Mapping
//   <o> PTB0  (Alias:A0)  [ADC0_SE8/ADC1_SE8, GPIOB_0, I2C0_SCL, FTM1_CH0] 
//   <i> Selects which peripheral function is mapped to PTB0 pin
//     <0=> ADC0_SE8/ADC1_SE8
//     <1=> GPIOB_0
//     <2=> I2C0_SCL
//     <3=> FTM1_CH0
//     <0=> Default
#define PTB0_SEL             0                   

// PTB1 Pin Mapping
//   <o> PTB1  (Alias:A1)  [ADC0_SE9/ADC1_SE9, GPIOB_1, I2C0_SDA, FTM1_CH1] 
//   <i> Selects which peripheral function is mapped to PTB1 pin
//     <0=> ADC0_SE9/ADC1_SE9
//     <1=> GPIOB_1
//     <2=> I2C0_SDA
//     <3=> FTM1_CH1
//     <0=> Default
#define PTB1_SEL             0                   

// PTB2 Pin Mapping
//   <o> PTB2  (Alias:A5)  [ADC0_SE12, GPIOB_2, I2C0_SCL] 
//   <i> Selects which peripheral function is mapped to PTB2 pin
//     <0=> ADC0_SE12
//     <1=> GPIOB_2
//     <2=> I2C0_SCL
//     <0=> Default
#define PTB2_SEL             0                   

// PTB3 Pin Mapping
//   <o> PTB3  (Alias:A4)  [ADC0_SE13, GPIOB_3, I2C0_SDA] 
//   <i> Selects which peripheral function is mapped to PTB3 pin
//     <0=> ADC0_SE13
//     <1=> GPIOB_3
//     <2=> I2C0_SDA
//     <0=> Default
#define PTB3_SEL             0                   

// PTB6 Pin Mapping
//   <o> PTB6  [ADC1_SE12, GPIOB_6] 
//   <i> Selects which peripheral function is mapped to PTB6 pin
//     <0=> ADC1_SE12
//     <1=> GPIOB_6
//     <0=> Default
#define PTB6_SEL             0                   

// PTB7 Pin Mapping
//   <o> PTB7  [ADC1_SE13, GPIOB_7] 
//   <i> Selects which peripheral function is mapped to PTB7 pin
//     <0=> ADC1_SE13
//     <1=> GPIOB_7
//     <0=> Default
#define PTB7_SEL             0                   

// PTB8 Pin Mapping
//   <o> PTB8  [GPIOB_8] <constant>
//   <i> Selects which peripheral function is mapped to PTB8 pin
//     <1=> GPIOB_8
//     <1=> Default
#define PTB8_SEL             1                   

// PTB9 Pin Mapping
//   <o> PTB9  [GPIOB_9, SPI1_PCS1] 
//   <i> Selects which peripheral function is mapped to PTB9 pin
//     <1=> GPIOB_9
//     <2=> SPI1_PCS1
//     <1=> Default
#define PTB9_SEL             1                   

// PTB10 Pin Mapping
//   <o> PTB10  [ADC1_SE14, GPIOB_10, SPI1_PCS0] 
//   <i> Selects which peripheral function is mapped to PTB10 pin
//     <0=> ADC1_SE14
//     <1=> GPIOB_10
//     <2=> SPI1_PCS0
//     <0=> Default
#define PTB10_SEL            0                   

// PTB11 Pin Mapping
//   <o> PTB11  [ADC1_SE15, GPIOB_11, SPI1_SCK] 
//   <i> Selects which peripheral function is mapped to PTB11 pin
//     <0=> ADC1_SE15
//     <1=> GPIOB_11
//     <2=> SPI1_SCK
//     <0=> Default
#define PTB11_SEL            0                   

// PTB16 Pin Mapping
//   <o> PTB16  (Alias:D2)  [GPIOB_16, SPI1_SOUT] 
//   <i> Selects which peripheral function is mapped to PTB16 pin
//     <1=> GPIOB_16
//     <2=> SPI1_SOUT
//     <1=> Default
#define PTB16_SEL            1                   

// PTB17 Pin Mapping
//   <o> PTB17  [GPIOB_17, SPI1_SIN] 
//   <i> Selects which peripheral function is mapped to PTB17 pin
//     <1=> GPIOB_17
//     <2=> SPI1_SIN
//     <1=> Default
#define PTB17_SEL            1                   

// PTB18 Pin Mapping
//   <o> PTB18  (Alias:D5)  [GPIOB_18, FTM2_CH0] 
//   <i> Selects which peripheral function is mapped to PTB18 pin
//     <1=> GPIOB_18
//     <3=> FTM2_CH0
//     <1=> Default
#define PTB18_SEL            1                   

// PTB19 Pin Mapping
//   <o> PTB19  (Alias:D8)  [GPIOB_19, FTM2_CH1] 
//   <i> Selects which peripheral function is mapped to PTB19 pin
//     <1=> GPIOB_19
//     <3=> FTM2_CH1
//     <1=> Default
#define PTB19_SEL            1                   

// PTB20 Pin Mapping
//   <o> PTB20  [GPIOB_20] <constant>
//   <i> Selects which peripheral function is mapped to PTB20 pin
//     <1=> GPIOB_20
//     <1=> Default
#define PTB20_SEL            1                   

// PTB21 Pin Mapping
//   <o> PTB21  [GPIOB_21] <constant>
//   <i> Selects which peripheral function is mapped to PTB21 pin
//     <1=> GPIOB_21
//     <1=> Default
#define PTB21_SEL            1                   

// PTB22 Pin Mapping
//   <o> PTB22  [GPIOB_22] <constant>
//   <i> Selects which peripheral function is mapped to PTB22 pin
//     <1=> GPIOB_22
//     <1=> Default
#define PTB22_SEL            1                   

// PTB23 Pin Mapping
//   <o> PTB23  [GPIOB_23, SPI0_PCS5] 
//   <i> Selects which peripheral function is mapped to PTB23 pin
//     <1=> GPIOB_23
//     <3=> SPI0_PCS5
//     <1=> Default
#define PTB23_SEL            1                   

// PTC0 Pin Mapping
//   <o> PTC0  [ADC0_SE14, GPIOC_0, SPI0_PCS4] 
//   <i> Selects which peripheral function is mapped to PTC0 pin
//     <0=> ADC0_SE14
//     <1=> GPIOC_0
//     <2=> SPI0_PCS4
//     <0=> Default
#define PTC0_SEL             0                   

// PTC1 Pin Mapping
//   <o> PTC1  (Alias:A2)  [ADC0_SE15, GPIOC_1, SPI0_PCS3, FTM0_CH0] 
//   <i> Selects which peripheral function is mapped to PTC1 pin
//     <0=> ADC0_SE15
//     <1=> GPIOC_1
//     <2=> SPI0_PCS3
//     <4=> FTM0_CH0
//     <0=> Default
#define PTC1_SEL             0                   

// PTC2 Pin Mapping
//   <o> PTC2  (Alias:A3)  [ADC0_SE4b, GPIOC_2, SPI0_PCS2, FTM0_CH1] 
//   <i> Selects which peripheral function is mapped to PTC2 pin
//     <0=> ADC0_SE4b
//     <1=> GPIOC_2
//     <2=> SPI0_PCS2
//     <4=> FTM0_CH1
//     <0=> Default
#define PTC2_SEL             0                   

// PTC3 Pin Mapping
//   <o> PTC3  (Alias:D6)  [GPIOC_3, SPI0_PCS1, FTM0_CH2] 
//   <i> Selects which peripheral function is mapped to PTC3 pin
//     <1=> GPIOC_3
//     <2=> SPI0_PCS1
//     <4=> FTM0_CH2
//     <1=> Default
#define PTC3_SEL             1                   

// PTC4 Pin Mapping
//   <o> PTC4  [GPIOC_4, SPI0_PCS0, FTM0_CH3] 
//   <i> Selects which peripheral function is mapped to PTC4 pin
//     <1=> GPIOC_4
//     <2=> SPI0_PCS0
//     <4=> FTM0_CH3
//     <1=> Default
#define PTC4_SEL             1                   

// PTC5 Pin Mapping
//   <o> PTC5  [GPIOC_5, SPI0_SCK, LPTMR0_ALT2, FTM0_CH2] 
//   <i> Selects which peripheral function is mapped to PTC5 pin
//     <1=> GPIOC_5
//     <2=> SPI0_SCK
//     <3=> LPTMR0_ALT2
//     <7=> FTM0_CH2
//     <1=> Default
#define PTC5_SEL             1                   

// PTC6 Pin Mapping
//   <o> PTC6  (Alias:D7)  [GPIOC_6, SPI0_SOUT] 
//   <i> Selects which peripheral function is mapped to PTC6 pin
//     <1=> GPIOC_6
//     <2=> SPI0_SOUT
//     <1=> Default
#define PTC6_SEL             1                   

// PTC7 Pin Mapping
//   <o> PTC7  [GPIOC_7, SPI0_SIN] 
//   <i> Selects which peripheral function is mapped to PTC7 pin
//     <1=> GPIOC_7
//     <2=> SPI0_SIN
//     <1=> Default
#define PTC7_SEL             1                   

// PTC8 Pin Mapping
//   <o> PTC8  [ADC1_SE4b, GPIOC_8] 
//   <i> Selects which peripheral function is mapped to PTC8 pin
//     <0=> ADC1_SE4b
//     <1=> GPIOC_8
//     <0=> Default
#define PTC8_SEL             0                   

// PTC9 Pin Mapping
//   <o> PTC9  [ADC1_SE5b, GPIOC_9] 
//   <i> Selects which peripheral function is mapped to PTC9 pin
//     <0=> ADC1_SE5b
//     <1=> GPIOC_9
//     <0=> Default
#define PTC9_SEL             0                   

// PTC10 Pin Mapping
//   <o> PTC10  [ADC1_SE6b, GPIOC_10, I2C1_SCL] 
//   <i> Selects which peripheral function is mapped to PTC10 pin
//     <0=> ADC1_SE6b
//     <1=> GPIOC_10
//     <2=> I2C1_SCL
//     <0=> Default
#define PTC10_SEL            0                   

// PTC11 Pin Mapping
//   <o> PTC11  [ADC1_SE7b, GPIOC_11, I2C1_SDA] 
//   <i> Selects which peripheral function is mapped to PTC11 pin
//     <0=> ADC1_SE7b
//     <1=> GPIOC_11
//     <2=> I2C1_SDA
//     <0=> Default
#define PTC11_SEL            0                   

// PTC12 Pin Mapping
//   <o> PTC12  [GPIOC_12] <constant>
//   <i> Selects which peripheral function is mapped to PTC12 pin
//     <1=> GPIOC_12
//     <1=> Default
#define PTC12_SEL            1                   

// PTC13 Pin Mapping
//   <o> PTC13  [GPIOC_13] <constant>
//   <i> Selects which peripheral function is mapped to PTC13 pin
//     <1=> GPIOC_13
//     <1=> Default
#define PTC13_SEL            1                   

// PTC14 Pin Mapping
//   <o> PTC14  [GPIOC_14] <constant>
//   <i> Selects which peripheral function is mapped to PTC14 pin
//     <1=> GPIOC_14
//     <1=> Default
#define PTC14_SEL            1                   

// PTC15 Pin Mapping
//   <o> PTC15  [GPIOC_15] <constant>
//   <i> Selects which peripheral function is mapped to PTC15 pin
//     <1=> GPIOC_15
//     <1=> Default
#define PTC15_SEL            1                   

// PTC16 Pin Mapping
//   <o> PTC16  [GPIOC_16] <constant>
//   <i> Selects which peripheral function is mapped to PTC16 pin
//     <1=> GPIOC_16
//     <1=> Default
#define PTC16_SEL            1                   

// PTC17 Pin Mapping
//   <o> PTC17  [GPIOC_17] <constant>
//   <i> Selects which peripheral function is mapped to PTC17 pin
//     <1=> GPIOC_17
//     <1=> Default
#define PTC17_SEL            1                   

// PTC18 Pin Mapping
//   <o> PTC18  [GPIOC_18] <constant>
//   <i> Selects which peripheral function is mapped to PTC18 pin
//     <1=> GPIOC_18
//     <1=> Default
#define PTC18_SEL            1                   

// PTC19 Pin Mapping
//   <o> PTC19  [GPIOC_19] <constant>
//   <i> Selects which peripheral function is mapped to PTC19 pin
//     <1=> GPIOC_19
//     <1=> Default
#define PTC19_SEL            1                   

// PTD0 Pin Mapping
//   <o> PTD0  [GPIOD_0, SPI0_PCS0] 
//   <i> Selects which peripheral function is mapped to PTD0 pin
//     <1=> GPIOD_0
//     <2=> SPI0_PCS0
//     <1=> Default
#define PTD0_SEL             1                   

// PTD1 Pin Mapping
//   <o> PTD1  [ADC0_SE5b, GPIOD_1, SPI0_SCK] 
//   <i> Selects which peripheral function is mapped to PTD1 pin
//     <0=> ADC0_SE5b
//     <1=> GPIOD_1
//     <2=> SPI0_SCK
//     <0=> Default
#define PTD1_SEL             0                   

// PTD2 Pin Mapping
//   <o> PTD2  (Alias:D0)  [GPIOD_2, SPI0_SOUT, I2C0_SCL] 
//   <i> Selects which peripheral function is mapped to PTD2 pin
//     <1=> GPIOD_2
//     <2=> SPI0_SOUT
//     <7=> I2C0_SCL
//     <1=> Default
#define PTD2_SEL             1                   

// PTD3 Pin Mapping
//   <o> PTD3  (Alias:D1)  [GPIOD_3, SPI0_SIN, I2C0_SDA] 
//   <i> Selects which peripheral function is mapped to PTD3 pin
//     <1=> GPIOD_3
//     <2=> SPI0_SIN
//     <7=> I2C0_SDA
//     <1=> Default
#define PTD3_SEL             1                   

// PTD4 Pin Mapping
//   <o> PTD4  (Alias:D10)  [GPIOD_4, SPI0_PCS1, FTM0_CH4, SPI1_PCS0] 
//   <i> Selects which peripheral function is mapped to PTD4 pin
//     <1=> GPIOD_4
//     <2=> SPI0_PCS1
//     <4=> FTM0_CH4
//     <7=> SPI1_PCS0
//     <1=> Default
#define PTD4_SEL             1                   

// PTD5 Pin Mapping
//   <o> PTD5  (Alias:D13)  [ADC0_SE6b, GPIOD_5, SPI0_PCS2, FTM0_CH5, SPI1_SCK] 
//   <i> Selects which peripheral function is mapped to PTD5 pin
//     <0=> ADC0_SE6b
//     <1=> GPIOD_5
//     <2=> SPI0_PCS2
//     <4=> FTM0_CH5
//     <7=> SPI1_SCK
//     <0=> Default
#define PTD5_SEL             0                   

// PTD6 Pin Mapping
//   <o> PTD6  (Alias:D11)  [ADC0_SE7b, GPIOD_6, SPI0_PCS3, FTM0_CH6, SPI1_SOUT] 
//   <i> Selects which peripheral function is mapped to PTD6 pin
//     <0=> ADC0_SE7b
//     <1=> GPIOD_6
//     <2=> SPI0_PCS3
//     <4=> FTM0_CH6
//     <7=> SPI1_SOUT
//     <0=> Default
#define PTD6_SEL             0                   

// PTD7 Pin Mapping
//   <o> PTD7  (Alias:D12)  [GPIOD_7, FTM0_CH7, SPI1_SIN] 
//   <i> Selects which peripheral function is mapped to PTD7 pin
//     <1=> GPIOD_7
//     <4=> FTM0_CH7
//     <7=> SPI1_SIN
//     <1=> Default
#define PTD7_SEL             1                   

// PTE0 Pin Mapping
//   <o> PTE0  (Alias:D14)  [ADC1_SE4a, GPIOE_0, SPI1_PCS1, I2C1_SDA] 
//   <i> Selects which peripheral function is mapped to PTE0 pin
//     <0=> ADC1_SE4a
//     <1=> GPIOE_0
//     <2=> SPI1_PCS1
//     <6=> I2C1_SDA
//     <0=> Default
#define PTE0_SEL             0                   

// PTE1 Pin Mapping
//   <o> PTE1  (Alias:D15)  [ADC1_SE5a, GPIOE_1, SPI1_SOUT, I2C1_SCL, SPI1_SIN] 
//   <i> Selects which peripheral function is mapped to PTE1 pin
//     <0=> ADC1_SE5a
//     <1=> GPIOE_1
//     <2=> SPI1_SOUT
//     <6=> I2C1_SCL
//     <7=> SPI1_SIN
//     <0=> Default
#define PTE1_SEL             0                   

// PTE2 Pin Mapping
//   <o> PTE2  [ADC1_SE6a, GPIOE_2, SPI1_SCK] 
//   <i> Selects which peripheral function is mapped to PTE2 pin
//     <0=> ADC1_SE6a
//     <1=> GPIOE_2
//     <2=> SPI1_SCK
//     <0=> Default
#define PTE2_SEL             0                   

// PTE3 Pin Mapping
//   <o> PTE3  [ADC1_SE7a, GPIOE_3, SPI1_SIN, SPI1_SOUT] 
//   <i> Selects which peripheral function is mapped to PTE3 pin
//     <0=> ADC1_SE7a
//     <1=> GPIOE_3
//     <2=> SPI1_SIN
//     <7=> SPI1_SOUT
//     <0=> Default
#define PTE3_SEL             0                   

// PTE4 Pin Mapping
//   <o> PTE4  [GPIOE_4, SPI1_PCS0] 
//   <i> Selects which peripheral function is mapped to PTE4 pin
//     <1=> GPIOE_4
//     <2=> SPI1_PCS0
//     <1=> Default
#define PTE4_SEL             1                   

// PTE5 Pin Mapping
//   <o> PTE5  [GPIOE_5, SPI1_PCS2] 
//   <i> Selects which peripheral function is mapped to PTE5 pin
//     <1=> GPIOE_5
//     <2=> SPI1_PCS2
//     <1=> Default
#define PTE5_SEL             1                   

// PTE6 Pin Mapping
//   <o> PTE6  [GPIOE_6, SPI1_PCS3] 
//   <i> Selects which peripheral function is mapped to PTE6 pin
//     <1=> GPIOE_6
//     <2=> SPI1_PCS3
//     <1=> Default
#define PTE6_SEL             1                   

// PTE24 Pin Mapping
//   <o> PTE24  [ADC0_SE17, GPIOE_24, I2C0_SCL] 
//   <i> Selects which peripheral function is mapped to PTE24 pin
//     <0=> ADC0_SE17
//     <1=> GPIOE_24
//     <5=> I2C0_SCL
//     <0=> Default
#define PTE24_SEL            0                   

// PTE25 Pin Mapping
//   <o> PTE25  [ADC0_SE18, GPIOE_25, I2C0_SDA] 
//   <i> Selects which peripheral function is mapped to PTE25 pin
//     <0=> ADC0_SE18
//     <1=> GPIOE_25
//     <5=> I2C0_SDA
//     <0=> Default
#define PTE25_SEL            0                   

// PTE26 Pin Mapping
//   <o> PTE26  [GPIOE_26] <constant>
//   <i> Selects which peripheral function is mapped to PTE26 pin
//     <1=> GPIOE_26
//     <1=> Default
#define PTE26_SEL            1                   

// </h>

//-------- <<< end of configuration section >>> -----------------  

#define FIXED_ADC_FN   0 //!< Fixed ADC Multiplexing value for pins
#define FIXED_GPIO_FN  1 //!< Fixed GPIO Multiplexing value for pins
#define FIXED_PORT_CLOCK_REG  SIM->SCGC5 //!< Fixed PORT Clock varies with port

#endif /* PIN_MAPPING_H_ */
