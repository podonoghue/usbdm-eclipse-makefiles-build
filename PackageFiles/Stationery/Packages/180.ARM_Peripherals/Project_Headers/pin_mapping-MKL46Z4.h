/**
 * @file      pin_mapping.h (derived from pin_mapping-MKL46Z4.h)
 * @version   1.0.0
 * @brief     Pin declarations for MKL46Z4
 */

#ifndef PIN_MAPPING_H_
#define PIN_MAPPING_H_

#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

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
//   <o> PTA0  [GPIOA_0, TPM0_CH5] 
//   <i> Selects which peripheral function is mapped to PTA0 pin
//     <1=> GPIOA_0
//     <3=> TPM0_CH5
//     <1=> Default
#define PTA0_SEL             1                   

// PTA1 Pin Mapping
//   <o> PTA1  (Alias:D0)  [GPIOA_1, TPM2_CH0] 
//   <i> Selects which peripheral function is mapped to PTA1 pin
//     <1=> GPIOA_1
//     <3=> TPM2_CH0
//     <1=> Default
#define PTA1_SEL             1                   

// PTA2 Pin Mapping
//   <o> PTA2  (Alias:D1)  [GPIOA_2, TPM2_CH1] 
//   <i> Selects which peripheral function is mapped to PTA2 pin
//     <1=> GPIOA_2
//     <3=> TPM2_CH1
//     <1=> Default
#define PTA2_SEL             1                   

// PTA3 Pin Mapping
//   <o> PTA3  [GPIOA_3, I2C1_SCL, TPM0_CH0] 
//   <i> Selects which peripheral function is mapped to PTA3 pin
//     <1=> GPIOA_3
//     <2=> I2C1_SCL
//     <3=> TPM0_CH0
//     <1=> Default
#define PTA3_SEL             1                   

// PTA4 Pin Mapping
//   <o> PTA4  (Alias:D4)  [GPIOA_4, I2C1_SDA, TPM0_CH1] 
//   <i> Selects which peripheral function is mapped to PTA4 pin
//     <1=> GPIOA_4
//     <2=> I2C1_SDA
//     <3=> TPM0_CH1
//     <1=> Default
#define PTA4_SEL             1                   

// PTA5 Pin Mapping
//   <o> PTA5  (Alias:D5)  [GPIOA_5, TPM0_CH2] 
//   <i> Selects which peripheral function is mapped to PTA5 pin
//     <1=> GPIOA_5
//     <3=> TPM0_CH2
//     <1=> Default
#define PTA5_SEL             1                   

// PTA6 Pin Mapping
//   <o> PTA6  [GPIOA_6, TPM0_CH3] 
//   <i> Selects which peripheral function is mapped to PTA6 pin
//     <1=> GPIOA_6
//     <3=> TPM0_CH3
//     <1=> Default
#define PTA6_SEL             1                   

// PTA7 Pin Mapping
//   <o> PTA7  [GPIOA_7, TPM0_CH4] 
//   <i> Selects which peripheral function is mapped to PTA7 pin
//     <1=> GPIOA_7
//     <3=> TPM0_CH4
//     <1=> Default
#define PTA7_SEL             1                   

// PTA12 Pin Mapping
//   <o> PTA12  (Alias:D3)  [GPIOA_12, TPM1_CH0] 
//   <i> Selects which peripheral function is mapped to PTA12 pin
//     <1=> GPIOA_12
//     <3=> TPM1_CH0
//     <1=> Default
#define PTA12_SEL            1                   

// PTA13 Pin Mapping
//   <o> PTA13  (Alias:D8)  [GPIOA_13, TPM1_CH1] 
//   <i> Selects which peripheral function is mapped to PTA13 pin
//     <1=> GPIOA_13
//     <3=> TPM1_CH1
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
//   <o> PTA16  [GPIOA_16, SPI0_MOSI, SPI0_MISO] 
//   <i> Selects which peripheral function is mapped to PTA16 pin
//     <1=> GPIOA_16
//     <2=> SPI0_MOSI
//     <5=> SPI0_MISO
//     <1=> Default
#define PTA16_SEL            1                   

// PTA17 Pin Mapping
//   <o> PTA17  [GPIOA_17, SPI0_MISO, SPI0_MOSI] 
//   <i> Selects which peripheral function is mapped to PTA17 pin
//     <1=> GPIOA_17
//     <2=> SPI0_MISO
//     <5=> SPI0_MOSI
//     <1=> Default
#define PTA17_SEL            1                   

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

// PTA20 Pin Mapping
//   <o> PTA20  [GPIOA_20] <constant>
//   <i> Selects which peripheral function is mapped to PTA20 pin
//     <1=> GPIOA_20
//     <1=> Default
#define PTA20_SEL            1                   

// PTB0 Pin Mapping
//   <o> PTB0  (Alias:A0)  [ADC0_SE8, GPIOB_0, I2C0_SCL, TPM1_CH0] 
//   <i> Selects which peripheral function is mapped to PTB0 pin
//     <0=> ADC0_SE8
//     <1=> GPIOB_0
//     <2=> I2C0_SCL
//     <3=> TPM1_CH0
//     <0=> Default
#define PTB0_SEL             0                   

// PTB1 Pin Mapping
//   <o> PTB1  (Alias:A1)  [ADC0_SE9, GPIOB_1, I2C0_SDA, TPM1_CH1] 
//   <i> Selects which peripheral function is mapped to PTB1 pin
//     <0=> ADC0_SE9
//     <1=> GPIOB_1
//     <2=> I2C0_SDA
//     <3=> TPM1_CH1
//     <0=> Default
#define PTB1_SEL             0                   

// PTB2 Pin Mapping
//   <o> PTB2  (Alias:A2)  [ADC0_SE12, GPIOB_2, I2C0_SCL, TPM2_CH0] 
//   <i> Selects which peripheral function is mapped to PTB2 pin
//     <0=> ADC0_SE12
//     <1=> GPIOB_2
//     <2=> I2C0_SCL
//     <3=> TPM2_CH0
//     <0=> Default
#define PTB2_SEL             0                   

// PTB3 Pin Mapping
//   <o> PTB3  (Alias:A3)  [ADC0_SE13, GPIOB_3, I2C0_SDA, TPM2_CH1] 
//   <i> Selects which peripheral function is mapped to PTB3 pin
//     <0=> ADC0_SE13
//     <1=> GPIOB_3
//     <2=> I2C0_SDA
//     <3=> TPM2_CH1
//     <0=> Default
#define PTB3_SEL             0                   

// PTB7 Pin Mapping
//   <o> PTB7  [GPIOB_7] <constant>
//   <i> Selects which peripheral function is mapped to PTB7 pin
//     <1=> GPIOB_7
//     <1=> Default
#define PTB7_SEL             1                   

// PTB8 Pin Mapping
//   <o> PTB8  [GPIOB_8, SPI1_PCS0] 
//   <i> Selects which peripheral function is mapped to PTB8 pin
//     <1=> GPIOB_8
//     <2=> SPI1_PCS0
//     <1=> Default
#define PTB8_SEL             1                   

// PTB9 Pin Mapping
//   <o> PTB9  [GPIOB_9, SPI1_SCK] 
//   <i> Selects which peripheral function is mapped to PTB9 pin
//     <1=> GPIOB_9
//     <2=> SPI1_SCK
//     <1=> Default
#define PTB9_SEL             1                   

// PTB10 Pin Mapping
//   <o> PTB10  [GPIOB_10, SPI1_PCS0] 
//   <i> Selects which peripheral function is mapped to PTB10 pin
//     <1=> GPIOB_10
//     <2=> SPI1_PCS0
//     <1=> Default
#define PTB10_SEL            1                   

// PTB11 Pin Mapping
//   <o> PTB11  [GPIOB_11, SPI1_SCK] 
//   <i> Selects which peripheral function is mapped to PTB11 pin
//     <1=> GPIOB_11
//     <2=> SPI1_SCK
//     <1=> Default
#define PTB11_SEL            1                   

// PTB16 Pin Mapping
//   <o> PTB16  [GPIOB_16, SPI1_MOSI, SPI1_MISO] 
//   <i> Selects which peripheral function is mapped to PTB16 pin
//     <1=> GPIOB_16
//     <2=> SPI1_MOSI
//     <5=> SPI1_MISO
//     <1=> Default
#define PTB16_SEL            1                   

// PTB17 Pin Mapping
//   <o> PTB17  [GPIOB_17, SPI1_MISO, SPI1_MOSI] 
//   <i> Selects which peripheral function is mapped to PTB17 pin
//     <1=> GPIOB_17
//     <2=> SPI1_MISO
//     <5=> SPI1_MOSI
//     <1=> Default
#define PTB17_SEL            1                   

// PTB18 Pin Mapping
//   <o> PTB18  [GPIOB_18, TPM2_CH0] 
//   <i> Selects which peripheral function is mapped to PTB18 pin
//     <1=> GPIOB_18
//     <3=> TPM2_CH0
//     <1=> Default
#define PTB18_SEL            1                   

// PTB19 Pin Mapping
//   <o> PTB19  [GPIOB_19, TPM2_CH1] 
//   <i> Selects which peripheral function is mapped to PTB19 pin
//     <1=> GPIOB_19
//     <3=> TPM2_CH1
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
//   <o> PTB23  [GPIOB_23] <constant>
//   <i> Selects which peripheral function is mapped to PTB23 pin
//     <1=> GPIOB_23
//     <1=> Default
#define PTB23_SEL            1                   

// PTC0 Pin Mapping
//   <o> PTC0  [ADC0_SE14, GPIOC_0] 
//   <i> Selects which peripheral function is mapped to PTC0 pin
//     <0=> ADC0_SE14
//     <1=> GPIOC_0
//     <0=> Default
#define PTC0_SEL             0                   

// PTC1 Pin Mapping
//   <o> PTC1  (Alias:A5)  [ADC0_SE15, GPIOC_1, I2C1_SCL, TPM0_CH0] 
//   <i> Selects which peripheral function is mapped to PTC1 pin
//     <0=> ADC0_SE15
//     <1=> GPIOC_1
//     <2=> I2C1_SCL
//     <4=> TPM0_CH0
//     <0=> Default
#define PTC1_SEL             0                   

// PTC2 Pin Mapping
//   <o> PTC2  (Alias:A4)  [ADC0_SE11, GPIOC_2, I2C1_SDA, TPM0_CH1] 
//   <i> Selects which peripheral function is mapped to PTC2 pin
//     <0=> ADC0_SE11
//     <1=> GPIOC_2
//     <2=> I2C1_SDA
//     <4=> TPM0_CH1
//     <0=> Default
#define PTC2_SEL             0                   

// PTC3 Pin Mapping
//   <o> PTC3  [GPIOC_3, TPM0_CH2] 
//   <i> Selects which peripheral function is mapped to PTC3 pin
//     <1=> GPIOC_3
//     <4=> TPM0_CH2
//     <1=> Default
#define PTC3_SEL             1                   

// PTC4 Pin Mapping
//   <o> PTC4  [GPIOC_4, SPI0_PCS0, TPM0_CH3] 
//   <i> Selects which peripheral function is mapped to PTC4 pin
//     <1=> GPIOC_4
//     <2=> SPI0_PCS0
//     <4=> TPM0_CH3
//     <1=> Default
#define PTC4_SEL             1                   

// PTC5 Pin Mapping
//   <o> PTC5  (Alias:ACC_INT1)  [GPIOC_5, SPI0_SCK, LPTMR0_ALT2] 
//   <i> Selects which peripheral function is mapped to PTC5 pin
//     <1=> GPIOC_5
//     <2=> SPI0_SCK
//     <3=> LPTMR0_ALT2
//     <1=> Default
#define PTC5_SEL             1                   

// PTC6 Pin Mapping
//   <o> PTC6  [GPIOC_6, SPI0_MOSI, SPI0_MISO] 
//   <i> Selects which peripheral function is mapped to PTC6 pin
//     <1=> GPIOC_6
//     <2=> SPI0_MOSI
//     <5=> SPI0_MISO
//     <1=> Default
#define PTC6_SEL             1                   

// PTC7 Pin Mapping
//   <o> PTC7  [GPIOC_7, SPI0_MISO, SPI0_MOSI] 
//   <i> Selects which peripheral function is mapped to PTC7 pin
//     <1=> GPIOC_7
//     <2=> SPI0_MISO
//     <5=> SPI0_MOSI
//     <1=> Default
#define PTC7_SEL             1                   

// PTC8 Pin Mapping
//   <o> PTC8  (Alias:D6)  [GPIOC_8, I2C0_SCL, TPM0_CH4] 
//   <i> Selects which peripheral function is mapped to PTC8 pin
//     <1=> GPIOC_8
//     <2=> I2C0_SCL
//     <3=> TPM0_CH4
//     <1=> Default
#define PTC8_SEL             1                   

// PTC9 Pin Mapping
//   <o> PTC9  (Alias:D7)  [GPIOC_9, I2C0_SDA, TPM0_CH5] 
//   <i> Selects which peripheral function is mapped to PTC9 pin
//     <1=> GPIOC_9
//     <2=> I2C0_SDA
//     <3=> TPM0_CH5
//     <1=> Default
#define PTC9_SEL             1                   

// PTC10 Pin Mapping
//   <o> PTC10  [GPIOC_10, I2C1_SCL] 
//   <i> Selects which peripheral function is mapped to PTC10 pin
//     <1=> GPIOC_10
//     <2=> I2C1_SCL
//     <1=> Default
#define PTC10_SEL            1                   

// PTC11 Pin Mapping
//   <o> PTC11  [GPIOC_11, I2C1_SDA] 
//   <i> Selects which peripheral function is mapped to PTC11 pin
//     <1=> GPIOC_11
//     <2=> I2C1_SDA
//     <1=> Default
#define PTC11_SEL            1                   

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

// PTD0 Pin Mapping
//   <o> PTD0  [GPIOD_0, SPI0_PCS0, TPM0_CH0] 
//   <i> Selects which peripheral function is mapped to PTD0 pin
//     <1=> GPIOD_0
//     <2=> SPI0_PCS0
//     <4=> TPM0_CH0
//     <1=> Default
#define PTD0_SEL             1                   

// PTD1 Pin Mapping
//   <o> PTD1  (Alias:ACC_INT2, MAG_INT)  [ADC0_SE5b, GPIOD_1, SPI0_SCK, TPM0_CH1] 
//   <i> Selects which peripheral function is mapped to PTD1 pin
//     <0=> ADC0_SE5b
//     <1=> GPIOD_1
//     <2=> SPI0_SCK
//     <4=> TPM0_CH1
//     <0=> Default
#define PTD1_SEL             0                   

// PTD2 Pin Mapping
//   <o> PTD2  (Alias:D9)  [GPIOD_2, SPI0_MOSI, TPM0_CH2, SPI0_MISO] 
//   <i> Selects which peripheral function is mapped to PTD2 pin
//     <1=> GPIOD_2
//     <2=> SPI0_MOSI
//     <4=> TPM0_CH2
//     <5=> SPI0_MISO
//     <1=> Default
#define PTD2_SEL             1                   

// PTD3 Pin Mapping
//   <o> PTD3  (Alias:D2)  [GPIOD_3, SPI0_MISO, TPM0_CH3, SPI0_MOSI] 
//   <i> Selects which peripheral function is mapped to PTD3 pin
//     <1=> GPIOD_3
//     <2=> SPI0_MISO
//     <4=> TPM0_CH3
//     <5=> SPI0_MOSI
//     <1=> Default
#define PTD3_SEL             1                   

// PTD4 Pin Mapping
//   <o> PTD4  (Alias:D10)  [GPIOD_4, SPI1_PCS0, TPM0_CH4] 
//   <i> Selects which peripheral function is mapped to PTD4 pin
//     <1=> GPIOD_4
//     <2=> SPI1_PCS0
//     <4=> TPM0_CH4
//     <1=> Default
#define PTD4_SEL             1                   

// PTD5 Pin Mapping
//   <o> PTD5  (Alias:D13, RED_LED)  [ADC0_SE6b, GPIOD_5, SPI1_SCK, TPM0_CH5] 
//   <i> Selects which peripheral function is mapped to PTD5 pin
//     <0=> ADC0_SE6b
//     <1=> GPIOD_5
//     <2=> SPI1_SCK
//     <4=> TPM0_CH5
//     <0=> Default
#define PTD5_SEL             0                   

// PTD6 Pin Mapping
//   <o> PTD6  (Alias:D11)  [ADC0_SE7b, GPIOD_6, SPI1_MOSI, SPI1_MISO] 
//   <i> Selects which peripheral function is mapped to PTD6 pin
//     <0=> ADC0_SE7b
//     <1=> GPIOD_6
//     <2=> SPI1_MOSI
//     <5=> SPI1_MISO
//     <0=> Default
#define PTD6_SEL             0                   

// PTD7 Pin Mapping
//   <o> PTD7  (Alias:D12)  [GPIOD_7, SPI1_MISO, SPI1_MOSI] 
//   <i> Selects which peripheral function is mapped to PTD7 pin
//     <1=> GPIOD_7
//     <2=> SPI1_MISO
//     <5=> SPI1_MOSI
//     <1=> Default
#define PTD7_SEL             1                   

// PTE0 Pin Mapping
//   <o> PTE0  (Alias:D14)  [GPIOE_0, SPI1_MISO, I2C1_SDA] 
//   <i> Selects which peripheral function is mapped to PTE0 pin
//     <1=> GPIOE_0
//     <2=> SPI1_MISO
//     <6=> I2C1_SDA
//     <1=> Default
#define PTE0_SEL             1                   

// PTE1 Pin Mapping
//   <o> PTE1  (Alias:D15)  [GPIOE_1, SPI1_MOSI, SPI1_MISO, I2C1_SCL] 
//   <i> Selects which peripheral function is mapped to PTE1 pin
//     <1=> GPIOE_1
//     <2=> SPI1_MOSI
//     <5=> SPI1_MISO
//     <6=> I2C1_SCL
//     <1=> Default
#define PTE1_SEL             1                   

// PTE2 Pin Mapping
//   <o> PTE2  [GPIOE_2, SPI1_SCK] 
//   <i> Selects which peripheral function is mapped to PTE2 pin
//     <1=> GPIOE_2
//     <2=> SPI1_SCK
//     <1=> Default
#define PTE2_SEL             1                   

// PTE3 Pin Mapping
//   <o> PTE3  [GPIOE_3, SPI1_MISO, SPI1_MOSI] 
//   <i> Selects which peripheral function is mapped to PTE3 pin
//     <1=> GPIOE_3
//     <2=> SPI1_MISO
//     <5=> SPI1_MOSI
//     <1=> Default
#define PTE3_SEL             1                   

// PTE4 Pin Mapping
//   <o> PTE4  [GPIOE_4, SPI1_PCS0] 
//   <i> Selects which peripheral function is mapped to PTE4 pin
//     <1=> GPIOE_4
//     <2=> SPI1_PCS0
//     <1=> Default
#define PTE4_SEL             1                   

// PTE5 Pin Mapping
//   <o> PTE5  [GPIOE_5] <constant>
//   <i> Selects which peripheral function is mapped to PTE5 pin
//     <1=> GPIOE_5
//     <1=> Default
#define PTE5_SEL             1                   

// PTE6 Pin Mapping
//   <o> PTE6  [GPIOE_6] <constant>
//   <i> Selects which peripheral function is mapped to PTE6 pin
//     <1=> GPIOE_6
//     <1=> Default
#define PTE6_SEL             1                   

// PTE16 Pin Mapping
//   <o> PTE16  [ADC0_DP1/ADC0_SE1, GPIOE_16, SPI0_PCS0] 
//   <i> Selects which peripheral function is mapped to PTE16 pin
//     <0=> ADC0_DP1/ADC0_SE1
//     <1=> GPIOE_16
//     <2=> SPI0_PCS0
//     <0=> Default
#define PTE16_SEL            0                   

// PTE17 Pin Mapping
//   <o> PTE17  [ADC0_DM1/ADC0_SE5a, GPIOE_17, SPI0_SCK, LPTMR0_ALT3] 
//   <i> Selects which peripheral function is mapped to PTE17 pin
//     <0=> ADC0_DM1/ADC0_SE5a
//     <1=> GPIOE_17
//     <2=> SPI0_SCK
//     <6=> LPTMR0_ALT3
//     <0=> Default
#define PTE17_SEL            0                   

// PTE18 Pin Mapping
//   <o> PTE18  [ADC0_DP2/ADC0_SE2, GPIOE_18, SPI0_MOSI, I2C0_SDA, SPI0_MISO] 
//   <i> Selects which peripheral function is mapped to PTE18 pin
//     <0=> ADC0_DP2/ADC0_SE2
//     <1=> GPIOE_18
//     <2=> SPI0_MOSI
//     <4=> I2C0_SDA
//     <5=> SPI0_MISO
//     <0=> Default
#define PTE18_SEL            0                   

// PTE19 Pin Mapping
//   <o> PTE19  [ADC0_DM2/ADC0_SE6a, GPIOE_19, SPI0_MISO, I2C0_SCL, SPI0_MOSI] 
//   <i> Selects which peripheral function is mapped to PTE19 pin
//     <0=> ADC0_DM2/ADC0_SE6a
//     <1=> GPIOE_19
//     <2=> SPI0_MISO
//     <4=> I2C0_SCL
//     <5=> SPI0_MOSI
//     <0=> Default
#define PTE19_SEL            0                   

// PTE20 Pin Mapping
//   <o> PTE20  [ADC0_DP0/ADC0_SE0, GPIOE_20, TPM1_CH0] 
//   <i> Selects which peripheral function is mapped to PTE20 pin
//     <0=> ADC0_DP0/ADC0_SE0
//     <1=> GPIOE_20
//     <3=> TPM1_CH0
//     <0=> Default
#define PTE20_SEL            0                   

// PTE21 Pin Mapping
//   <o> PTE21  [ADC0_DM0/ADC0_SE4a, GPIOE_21, TPM1_CH1] 
//   <i> Selects which peripheral function is mapped to PTE21 pin
//     <0=> ADC0_DM0/ADC0_SE4a
//     <1=> GPIOE_21
//     <3=> TPM1_CH1
//     <0=> Default
#define PTE21_SEL            0                   

// PTE22 Pin Mapping
//   <o> PTE22  (Alias:LIGHT_SENS)  [ADC0_DP3/ADC0_SE3, GPIOE_22, TPM2_CH0] 
//   <i> Selects which peripheral function is mapped to PTE22 pin
//     <0=> ADC0_DP3/ADC0_SE3
//     <1=> GPIOE_22
//     <3=> TPM2_CH0
//     <0=> Default
#define PTE22_SEL            0                   

// PTE23 Pin Mapping
//   <o> PTE23  [ADC0_DM3/ADC0_SE7a, GPIOE_23, TPM2_CH1] 
//   <i> Selects which peripheral function is mapped to PTE23 pin
//     <0=> ADC0_DM3/ADC0_SE7a
//     <1=> GPIOE_23
//     <3=> TPM2_CH1
//     <0=> Default
#define PTE23_SEL            0                   

// PTE24 Pin Mapping
//   <o> PTE24  (Alias:ACC_SCL, MAG_SCL)  [GPIOE_24, TPM0_CH0, I2C0_SCL] 
//   <i> Selects which peripheral function is mapped to PTE24 pin
//     <1=> GPIOE_24
//     <3=> TPM0_CH0
//     <5=> I2C0_SCL
//     <1=> Default
#define PTE24_SEL            1                   

// PTE25 Pin Mapping
//   <o> PTE25  (Alias:ACC_SDA, MAG_SDA)  [GPIOE_25, TPM0_CH1, I2C0_SDA] 
//   <i> Selects which peripheral function is mapped to PTE25 pin
//     <1=> GPIOE_25
//     <3=> TPM0_CH1
//     <5=> I2C0_SDA
//     <1=> Default
#define PTE25_SEL            1                   

// PTE26 Pin Mapping
//   <o> PTE26  [GPIOE_26, TPM0_CH5] 
//   <i> Selects which peripheral function is mapped to PTE26 pin
//     <1=> GPIOE_26
//     <3=> TPM0_CH5
//     <1=> Default
#define PTE26_SEL            1                   

// PTE29 Pin Mapping
//   <o> PTE29  (Alias:GRN_LED)  [ADC0_SE4b, GPIOE_29, TPM0_CH2] 
//   <i> Selects which peripheral function is mapped to PTE29 pin
//     <0=> ADC0_SE4b
//     <1=> GPIOE_29
//     <3=> TPM0_CH2
//     <0=> Default
#define PTE29_SEL            0                   

// PTE30 Pin Mapping
//   <o> PTE30  [ADC0_SE23, GPIOE_30, TPM0_CH3] 
//   <i> Selects which peripheral function is mapped to PTE30 pin
//     <0=> ADC0_SE23
//     <1=> GPIOE_30
//     <3=> TPM0_CH3
//     <0=> Default
#define PTE30_SEL            0                   

// PTE31 Pin Mapping
//   <o> PTE31  [GPIOE_31, TPM0_CH4] 
//   <i> Selects which peripheral function is mapped to PTE31 pin
//     <1=> GPIOE_31
//     <3=> TPM0_CH4
//     <1=> Default
#define PTE31_SEL            1                   

// </h>

//-------- <<< end of configuration section >>> -----------------  

#define FIXED_ADC_FN   0 //!< Fixed ADC Multiplexing value for pins
#define FIXED_GPIO_FN  1 //!< Fixed GPIO Multiplexing value for pins
#define FIXED_PORT_CLOCK_REG  SIM->SCGC5 //!< Fixed PORT Clock varies with port

#endif /* PIN_MAPPING_H_ */
