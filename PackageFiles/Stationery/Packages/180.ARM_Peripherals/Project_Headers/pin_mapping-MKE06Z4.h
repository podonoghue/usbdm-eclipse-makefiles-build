/**
 * @file      pin_mapping.h (derived from pin_mapping-MKE06Z4.h)
 * @version   1.0.0
 * @brief     Pin declarations for MKE06Z4
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

// PTA0 Pin Mapping
//   <o> PTA0  [GPIOA_0, FTM0_CH0, I2C0_4WSCLOUT, ADC0_SE0] 
//   <i> Selects which peripheral function is mapped to PTA0 pin
//     <0=> GPIOA_0
//     <2=> FTM0_CH0
//     <3=> I2C0_4WSCLOUT
//     <5=> ADC0_SE0
//     <0=> Default
#define PTA0_SEL             0                   

// PTA1 Pin Mapping
//   <o> PTA1  [GPIOA_1, FTM0_CH1, I2C0_4WSDAOUT, ADC0_SE1] 
//   <i> Selects which peripheral function is mapped to PTA1 pin
//     <0=> GPIOA_1
//     <2=> FTM0_CH1
//     <3=> I2C0_4WSDAOUT
//     <5=> ADC0_SE1
//     <0=> Default
#define PTA1_SEL             0                   

// PTA2 Pin Mapping
//   <o> PTA2  [GPIOA_2, I2C0_SDA] 
//   <i> Selects which peripheral function is mapped to PTA2 pin
//     <0=> GPIOA_2
//     <3=> I2C0_SDA
//     <0=> Default
#define PTA2_SEL             0                   

// PTA3 Pin Mapping
//   <o> PTA3  [GPIOA_3, I2C0_SCL] 
//   <i> Selects which peripheral function is mapped to PTA3 pin
//     <0=> GPIOA_3
//     <3=> I2C0_SCL
//     <0=> Default
#define PTA3_SEL             0                   

// PTA5 Pin Mapping
//   <o> PTA5  [GPIOA_5] <constant>
//   <i> Selects which peripheral function is mapped to PTA5 pin
//     <0=> GPIOA_5
//     <0=> Default
#define PTA5_SEL             0                   

// PTA6 Pin Mapping
//   <o> PTA6  [GPIOA_6, ADC0_SE2] 
//   <i> Selects which peripheral function is mapped to PTA6 pin
//     <0=> GPIOA_6
//     <4=> ADC0_SE2
//     <0=> Default
#define PTA6_SEL             0                   

// PTA7 Pin Mapping
//   <o> PTA7  [GPIOA_7, ADC0_SE3] 
//   <i> Selects which peripheral function is mapped to PTA7 pin
//     <0=> GPIOA_7
//     <4=> ADC0_SE3
//     <0=> Default
#define PTA7_SEL             0                   

// PTB0 Pin Mapping
//   <o> PTB0  [GPIOA_8, ADC0_SE4] 
//   <i> Selects which peripheral function is mapped to PTB0 pin
//     <0=> GPIOA_8
//     <4=> ADC0_SE4
//     <0=> Default
#define PTB0_SEL             0                   

// PTB1 Pin Mapping
//   <o> PTB1  [GPIOA_9, ADC0_SE5] 
//   <i> Selects which peripheral function is mapped to PTB1 pin
//     <0=> GPIOA_9
//     <4=> ADC0_SE5
//     <0=> Default
#define PTB1_SEL             0                   

// PTB2 Pin Mapping
//   <o> PTB2  [GPIOA_10, SPI0_SCK, FTM0_CH0, ADC0_SE6] 
//   <i> Selects which peripheral function is mapped to PTB2 pin
//     <0=> GPIOA_10
//     <2=> SPI0_SCK
//     <3=> FTM0_CH0
//     <4=> ADC0_SE6
//     <0=> Default
#define PTB2_SEL             0                   

// PTB3 Pin Mapping
//   <o> PTB3  [GPIOA_11, SPI0_MOSI, FTM0_CH1, ADC0_SE7] 
//   <i> Selects which peripheral function is mapped to PTB3 pin
//     <0=> GPIOA_11
//     <2=> SPI0_MOSI
//     <3=> FTM0_CH1
//     <4=> ADC0_SE7
//     <0=> Default
#define PTB3_SEL             0                   

// PTB4 Pin Mapping
//   <o> PTB4  [GPIOA_12, FTM2_CH4, SPI0_MISO] 
//   <i> Selects which peripheral function is mapped to PTB4 pin
//     <0=> GPIOA_12
//     <2=> FTM2_CH4
//     <3=> SPI0_MISO
//     <0=> Default
#define PTB4_SEL             0                   

// PTB5 Pin Mapping
//   <o> PTB5  [GPIOA_13, FTM2_CH5, SPI0_PCS] 
//   <i> Selects which peripheral function is mapped to PTB5 pin
//     <0=> GPIOA_13
//     <2=> FTM2_CH5
//     <3=> SPI0_PCS
//     <0=> Default
#define PTB5_SEL             0                   

// PTB6 Pin Mapping
//   <o> PTB6  [GPIOA_14, I2C0_SDA] 
//   <i> Selects which peripheral function is mapped to PTB6 pin
//     <0=> GPIOA_14
//     <2=> I2C0_SDA
//     <0=> Default
#define PTB6_SEL             0                   

// PTB7 Pin Mapping
//   <o> PTB7  [GPIOA_15, I2C0_SCL] 
//   <i> Selects which peripheral function is mapped to PTB7 pin
//     <0=> GPIOA_15
//     <2=> I2C0_SCL
//     <0=> Default
#define PTB7_SEL             0                   

// PTC0 Pin Mapping
//   <o> PTC0  [GPIOA_16, FTM2_CH0, ADC0_SE8] 
//   <i> Selects which peripheral function is mapped to PTC0 pin
//     <0=> GPIOA_16
//     <2=> FTM2_CH0
//     <4=> ADC0_SE8
//     <0=> Default
#define PTC0_SEL             0                   

// PTC1 Pin Mapping
//   <o> PTC1  [GPIOA_17, FTM2_CH1, ADC0_SE9] 
//   <i> Selects which peripheral function is mapped to PTC1 pin
//     <0=> GPIOA_17
//     <2=> FTM2_CH1
//     <4=> ADC0_SE9
//     <0=> Default
#define PTC1_SEL             0                   

// PTC2 Pin Mapping
//   <o> PTC2  [GPIOA_18, FTM2_CH2, ADC0_SE10] 
//   <i> Selects which peripheral function is mapped to PTC2 pin
//     <0=> GPIOA_18
//     <2=> FTM2_CH2
//     <4=> ADC0_SE10
//     <0=> Default
#define PTC2_SEL             0                   

// PTC3 Pin Mapping
//   <o> PTC3  [GPIOA_19, FTM2_CH3, ADC0_SE11] 
//   <i> Selects which peripheral function is mapped to PTC3 pin
//     <0=> GPIOA_19
//     <2=> FTM2_CH3
//     <4=> ADC0_SE11
//     <0=> Default
#define PTC3_SEL             0                   

// PTC4 Pin Mapping
//   <o> PTC4  [GPIOA_20, FTM1_CH0] 
//   <i> Selects which peripheral function is mapped to PTC4 pin
//     <0=> GPIOA_20
//     <3=> FTM1_CH0
//     <0=> Default
#define PTC4_SEL             0                   

// PTC5 Pin Mapping
//   <o> PTC5  [GPIOA_21, FTM1_CH1] 
//   <i> Selects which peripheral function is mapped to PTC5 pin
//     <0=> GPIOA_21
//     <3=> FTM1_CH1
//     <0=> Default
#define PTC5_SEL             0                   

// PTC6 Pin Mapping
//   <o> PTC6  [GPIOA_22] <constant>
//   <i> Selects which peripheral function is mapped to PTC6 pin
//     <0=> GPIOA_22
//     <0=> Default
#define PTC6_SEL             0                   

// PTC7 Pin Mapping
//   <o> PTC7  [GPIOA_23] <constant>
//   <i> Selects which peripheral function is mapped to PTC7 pin
//     <0=> GPIOA_23
//     <0=> Default
#define PTC7_SEL             0                   

// PTD0 Pin Mapping
//   <o> PTD0  [GPIOA_24, FTM2_CH2, SPI1_SCK] 
//   <i> Selects which peripheral function is mapped to PTD0 pin
//     <0=> GPIOA_24
//     <2=> FTM2_CH2
//     <3=> SPI1_SCK
//     <0=> Default
#define PTD0_SEL             0                   

// PTD1 Pin Mapping
//   <o> PTD1  [GPIOA_25, FTM2_CH3, SPI1_MOSI] 
//   <i> Selects which peripheral function is mapped to PTD1 pin
//     <0=> GPIOA_25
//     <2=> FTM2_CH3
//     <3=> SPI1_MOSI
//     <0=> Default
#define PTD1_SEL             0                   

// PTD2 Pin Mapping
//   <o> PTD2  [GPIOA_26, SPI1_MISO] 
//   <i> Selects which peripheral function is mapped to PTD2 pin
//     <0=> GPIOA_26
//     <2=> SPI1_MISO
//     <0=> Default
#define PTD2_SEL             0                   

// PTD3 Pin Mapping
//   <o> PTD3  [GPIOA_27, SPI1_PCS] 
//   <i> Selects which peripheral function is mapped to PTD3 pin
//     <0=> GPIOA_27
//     <2=> SPI1_PCS
//     <0=> Default
#define PTD3_SEL             0                   

// PTD4 Pin Mapping
//   <o> PTD4  [GPIOA_28] <constant>
//   <i> Selects which peripheral function is mapped to PTD4 pin
//     <0=> GPIOA_28
//     <0=> Default
#define PTD4_SEL             0                   

// PTD5 Pin Mapping
//   <o> PTD5  [GPIOA_29] <constant>
//   <i> Selects which peripheral function is mapped to PTD5 pin
//     <0=> GPIOA_29
//     <0=> Default
#define PTD5_SEL             0                   

// PTD6 Pin Mapping
//   <o> PTD6  [GPIOA_30] <constant>
//   <i> Selects which peripheral function is mapped to PTD6 pin
//     <0=> GPIOA_30
//     <0=> Default
#define PTD6_SEL             0                   

// PTD7 Pin Mapping
//   <o> PTD7  [GPIOA_31] <constant>
//   <i> Selects which peripheral function is mapped to PTD7 pin
//     <0=> GPIOA_31
//     <0=> Default
#define PTD7_SEL             0                   

// PTE0 Pin Mapping
//   <o> PTE0  [GPIOB_0, SPI0_SCK, I2C1_SDA] 
//   <i> Selects which peripheral function is mapped to PTE0 pin
//     <0=> GPIOB_0
//     <2=> SPI0_SCK
//     <4=> I2C1_SDA
//     <0=> Default
#define PTE0_SEL             0                   

// PTE1 Pin Mapping
//   <o> PTE1  [GPIOB_1, SPI0_MOSI, I2C1_SCL] 
//   <i> Selects which peripheral function is mapped to PTE1 pin
//     <0=> GPIOB_1
//     <2=> SPI0_MOSI
//     <4=> I2C1_SCL
//     <0=> Default
#define PTE1_SEL             0                   

// PTE2 Pin Mapping
//   <o> PTE2  [GPIOB_2, SPI0_MISO] 
//   <i> Selects which peripheral function is mapped to PTE2 pin
//     <0=> GPIOB_2
//     <2=> SPI0_MISO
//     <0=> Default
#define PTE2_SEL             0                   

// PTE3 Pin Mapping
//   <o> PTE3  [GPIOB_3, SPI0_PCS] 
//   <i> Selects which peripheral function is mapped to PTE3 pin
//     <0=> GPIOB_3
//     <2=> SPI0_PCS
//     <0=> Default
#define PTE3_SEL             0                   

// PTE4 Pin Mapping
//   <o> PTE4  [GPIOB_4] <constant>
//   <i> Selects which peripheral function is mapped to PTE4 pin
//     <0=> GPIOB_4
//     <0=> Default
#define PTE4_SEL             0                   

// PTE5 Pin Mapping
//   <o> PTE5  [GPIOB_5] <constant>
//   <i> Selects which peripheral function is mapped to PTE5 pin
//     <0=> GPIOB_5
//     <0=> Default
#define PTE5_SEL             0                   

// PTE6 Pin Mapping
//   <o> PTE6  [GPIOB_6] <constant>
//   <i> Selects which peripheral function is mapped to PTE6 pin
//     <0=> GPIOB_6
//     <0=> Default
#define PTE6_SEL             0                   

// PTE7 Pin Mapping
//   <o> PTE7  [GPIOB_7, FTM1_CH1] 
//   <i> Selects which peripheral function is mapped to PTE7 pin
//     <0=> GPIOB_7
//     <4=> FTM1_CH1
//     <0=> Default
#define PTE7_SEL             0                   

// PTF0 Pin Mapping
//   <o> PTF0  [GPIOB_8, FTM2_CH0] 
//   <i> Selects which peripheral function is mapped to PTF0 pin
//     <0=> GPIOB_8
//     <2=> FTM2_CH0
//     <0=> Default
#define PTF0_SEL             0                   

// PTF1 Pin Mapping
//   <o> PTF1  [GPIOB_9, FTM2_CH1] 
//   <i> Selects which peripheral function is mapped to PTF1 pin
//     <0=> GPIOB_9
//     <2=> FTM2_CH1
//     <0=> Default
#define PTF1_SEL             0                   

// PTF2 Pin Mapping
//   <o> PTF2  [GPIOB_10] <constant>
//   <i> Selects which peripheral function is mapped to PTF2 pin
//     <0=> GPIOB_10
//     <0=> Default
#define PTF2_SEL             0                   

// PTF3 Pin Mapping
//   <o> PTF3  [GPIOB_11] <constant>
//   <i> Selects which peripheral function is mapped to PTF3 pin
//     <0=> GPIOB_11
//     <0=> Default
#define PTF3_SEL             0                   

// PTF4 Pin Mapping
//   <o> PTF4  [GPIOB_12, ADC0_SE12] 
//   <i> Selects which peripheral function is mapped to PTF4 pin
//     <0=> GPIOB_12
//     <4=> ADC0_SE12
//     <0=> Default
#define PTF4_SEL             0                   

// PTF5 Pin Mapping
//   <o> PTF5  [GPIOB_13, ADC0_SE13] 
//   <i> Selects which peripheral function is mapped to PTF5 pin
//     <0=> GPIOB_13
//     <4=> ADC0_SE13
//     <0=> Default
#define PTF5_SEL             0                   

// PTF6 Pin Mapping
//   <o> PTF6  [GPIOB_14, ADC0_SE14] 
//   <i> Selects which peripheral function is mapped to PTF6 pin
//     <0=> GPIOB_14
//     <4=> ADC0_SE14
//     <0=> Default
#define PTF6_SEL             0                   

// PTF7 Pin Mapping
//   <o> PTF7  [GPIOB_15, ADC0_SE15] 
//   <i> Selects which peripheral function is mapped to PTF7 pin
//     <0=> GPIOB_15
//     <4=> ADC0_SE15
//     <0=> Default
#define PTF7_SEL             0                   

// PTG0 Pin Mapping
//   <o> PTG0  [GPIOB_16] <constant>
//   <i> Selects which peripheral function is mapped to PTG0 pin
//     <0=> GPIOB_16
//     <0=> Default
#define PTG0_SEL             0                   

// PTG1 Pin Mapping
//   <o> PTG1  [GPIOB_17] <constant>
//   <i> Selects which peripheral function is mapped to PTG1 pin
//     <0=> GPIOB_17
//     <0=> Default
#define PTG1_SEL             0                   

// PTG2 Pin Mapping
//   <o> PTG2  [GPIOB_18] <constant>
//   <i> Selects which peripheral function is mapped to PTG2 pin
//     <0=> GPIOB_18
//     <0=> Default
#define PTG2_SEL             0                   

// PTG3 Pin Mapping
//   <o> PTG3  [GPIOB_19] <constant>
//   <i> Selects which peripheral function is mapped to PTG3 pin
//     <0=> GPIOB_19
//     <0=> Default
#define PTG3_SEL             0                   

// PTG4 Pin Mapping
//   <o> PTG4  [GPIOB_20, FTM2_CH2, SPI1_SCK] 
//   <i> Selects which peripheral function is mapped to PTG4 pin
//     <0=> GPIOB_20
//     <2=> FTM2_CH2
//     <3=> SPI1_SCK
//     <0=> Default
#define PTG4_SEL             0                   

// PTG5 Pin Mapping
//   <o> PTG5  [GPIOB_21, FTM2_CH3, SPI1_MOSI] 
//   <i> Selects which peripheral function is mapped to PTG5 pin
//     <0=> GPIOB_21
//     <2=> FTM2_CH3
//     <3=> SPI1_MOSI
//     <0=> Default
#define PTG5_SEL             0                   

// PTG6 Pin Mapping
//   <o> PTG6  [GPIOB_22, FTM2_CH4, SPI1_MISO] 
//   <i> Selects which peripheral function is mapped to PTG6 pin
//     <0=> GPIOB_22
//     <2=> FTM2_CH4
//     <3=> SPI1_MISO
//     <0=> Default
#define PTG6_SEL             0                   

// PTG7 Pin Mapping
//   <o> PTG7  [GPIOB_23, FTM2_CH5, SPI1_PCS] 
//   <i> Selects which peripheral function is mapped to PTG7 pin
//     <0=> GPIOB_23
//     <2=> FTM2_CH5
//     <3=> SPI1_PCS
//     <0=> Default
#define PTG7_SEL             0                   

// PTH0 Pin Mapping
//   <o> PTH0  [GPIOB_24, FTM2_CH0] 
//   <i> Selects which peripheral function is mapped to PTH0 pin
//     <0=> GPIOB_24
//     <2=> FTM2_CH0
//     <0=> Default
#define PTH0_SEL             0                   

// PTH1 Pin Mapping
//   <o> PTH1  [GPIOB_25, FTM2_CH1] 
//   <i> Selects which peripheral function is mapped to PTH1 pin
//     <0=> GPIOB_25
//     <2=> FTM2_CH1
//     <0=> Default
#define PTH1_SEL             0                   

// PTH2 Pin Mapping
//   <o> PTH2  [GPIOB_26, FTM1_CH0] 
//   <i> Selects which peripheral function is mapped to PTH2 pin
//     <0=> GPIOB_26
//     <4=> FTM1_CH0
//     <0=> Default
#define PTH2_SEL             0                   

// PTH3 Pin Mapping
//   <o> PTH3  [GPIOB_27, I2C1_SDA] 
//   <i> Selects which peripheral function is mapped to PTH3 pin
//     <0=> GPIOB_27
//     <2=> I2C1_SDA
//     <0=> Default
#define PTH3_SEL             0                   

// PTH4 Pin Mapping
//   <o> PTH4  [GPIOB_28, I2C1_SCL] 
//   <i> Selects which peripheral function is mapped to PTH4 pin
//     <0=> GPIOB_28
//     <2=> I2C1_SCL
//     <0=> Default
#define PTH4_SEL             0                   

// PTH5 Pin Mapping
//   <o> PTH5  [GPIOB_29] <constant>
//   <i> Selects which peripheral function is mapped to PTH5 pin
//     <0=> GPIOB_29
//     <0=> Default
#define PTH5_SEL             0                   

// PTH6 Pin Mapping
//   <o> PTH6  [GPIOB_30] <constant>
//   <i> Selects which peripheral function is mapped to PTH6 pin
//     <0=> GPIOB_30
//     <0=> Default
#define PTH6_SEL             0                   

// PTH7 Pin Mapping
//   <o> PTH7  [GPIOB_31] <constant>
//   <i> Selects which peripheral function is mapped to PTH7 pin
//     <0=> GPIOB_31
//     <0=> Default
#define PTH7_SEL             0                   

// PTI0 Pin Mapping
//   <o> PTI0  [GPIOC_0] <constant>
//   <i> Selects which peripheral function is mapped to PTI0 pin
//     <0=> GPIOC_0
//     <0=> Default
#define PTI0_SEL             0                   

// PTI1 Pin Mapping
//   <o> PTI1  [GPIOC_1] <constant>
//   <i> Selects which peripheral function is mapped to PTI1 pin
//     <0=> GPIOC_1
//     <0=> Default
#define PTI1_SEL             0                   

// PTI2 Pin Mapping
//   <o> PTI2  [GPIOC_2] <constant>
//   <i> Selects which peripheral function is mapped to PTI2 pin
//     <0=> GPIOC_2
//     <0=> Default
#define PTI2_SEL             0                   

// PTI3 Pin Mapping
//   <o> PTI3  [GPIOC_3] <constant>
//   <i> Selects which peripheral function is mapped to PTI3 pin
//     <0=> GPIOC_3
//     <0=> Default
#define PTI3_SEL             0                   

// PTI4 Pin Mapping
//   <o> PTI4  [GPIOC_4] <constant>
//   <i> Selects which peripheral function is mapped to PTI4 pin
//     <0=> GPIOC_4
//     <0=> Default
#define PTI4_SEL             0                   

// PTI5 Pin Mapping
//   <o> PTI5  [GPIOC_5] <constant>
//   <i> Selects which peripheral function is mapped to PTI5 pin
//     <0=> GPIOC_5
//     <0=> Default
#define PTI5_SEL             0                   

// PTI6 Pin Mapping
//   <o> PTI6  [GPIOC_6] <constant>
//   <i> Selects which peripheral function is mapped to PTI6 pin
//     <0=> GPIOC_6
//     <0=> Default
#define PTI6_SEL             0                   

// </h>

//-------- <<< end of configuration section >>> -----------------  

#define FIXED_ADC_FN   0 //!< Fixed ADC Multiplexing value for pins
#define FIXED_GPIO_FN  1 //!< Fixed GPIO Multiplexing value for pins
#define FIXED_PORT_CLOCK_REG  SIM->SCGC5 //!< Fixed PORT Clock varies with port

#endif /* PIN_MAPPING_H_ */
