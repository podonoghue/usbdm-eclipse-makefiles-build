/**
 * @file      pin_mapping.h (derived from pin_mapping-MKM33Z5.h)
 * @version   1.0.0
 * @brief     Pin declarations for MKM33Z5
 */

#ifndef PIN_MAPPING_H_
#define PIN_MAPPING_H_

#include "derivative.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------  

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
//   <o> PTA0  [GPIOA_0] <constant>
//   <i> Selects which peripheral function is mapped to PTA0 pin
//     <1=> GPIOA_0
//     <1=> Default
#define PTA0_SEL             1                   

// PTA1 Pin Mapping
//   <o> PTA1  [GPIOA_1] <constant>
//   <i> Selects which peripheral function is mapped to PTA1 pin
//     <1=> GPIOA_1
//     <1=> Default
#define PTA1_SEL             1                   

// PTA2 Pin Mapping
//   <o> PTA2  [GPIOA_2] <constant>
//   <i> Selects which peripheral function is mapped to PTA2 pin
//     <1=> GPIOA_2
//     <1=> Default
#define PTA2_SEL             1                   

// PTA3 Pin Mapping
//   <o> PTA3  [GPIOA_3] <constant>
//   <i> Selects which peripheral function is mapped to PTA3 pin
//     <1=> GPIOA_3
//     <1=> Default
#define PTA3_SEL             1                   

// PTA4 Pin Mapping
//   <o> PTA4  [GPIOA_4] <constant>
//   <i> Selects which peripheral function is mapped to PTA4 pin
//     <1=> GPIOA_4
//     <1=> Default
#define PTA4_SEL             1                   

// PTA5 Pin Mapping
//   <o> PTA5  [GPIOA_5] <constant>
//   <i> Selects which peripheral function is mapped to PTA5 pin
//     <1=> GPIOA_5
//     <1=> Default
#define PTA5_SEL             1                   

// PTA6 Pin Mapping
//   <o> PTA6  [GPIOA_6] <constant>
//   <i> Selects which peripheral function is mapped to PTA6 pin
//     <1=> GPIOA_6
//     <1=> Default
#define PTA6_SEL             1                   

// PTA7 Pin Mapping
//   <o> PTA7  [GPIOA_7] <constant>
//   <i> Selects which peripheral function is mapped to PTA7 pin
//     <1=> GPIOA_7
//     <1=> Default
#define PTA7_SEL             1                   

// PTB0 Pin Mapping
//   <o> PTB0  [GPIOB_0] <constant>
//   <i> Selects which peripheral function is mapped to PTB0 pin
//     <1=> GPIOB_0
//     <1=> Default
#define PTB0_SEL             1                   

// PTB1 Pin Mapping
//   <o> PTB1  [GPIOB_1] <constant>
//   <i> Selects which peripheral function is mapped to PTB1 pin
//     <1=> GPIOB_1
//     <1=> Default
#define PTB1_SEL             1                   

// PTB2 Pin Mapping
//   <o> PTB2  [GPIOB_2] <constant>
//   <i> Selects which peripheral function is mapped to PTB2 pin
//     <1=> GPIOB_2
//     <1=> Default
#define PTB2_SEL             1                   

// PTB3 Pin Mapping
//   <o> PTB3  [GPIOB_3] <constant>
//   <i> Selects which peripheral function is mapped to PTB3 pin
//     <1=> GPIOB_3
//     <1=> Default
#define PTB3_SEL             1                   

// PTB4 Pin Mapping
//   <o> PTB4  [GPIOB_4] <constant>
//   <i> Selects which peripheral function is mapped to PTB4 pin
//     <1=> GPIOB_4
//     <1=> Default
#define PTB4_SEL             1                   

// PTB5 Pin Mapping
//   <o> PTB5  [GPIOB_5] <constant>
//   <i> Selects which peripheral function is mapped to PTB5 pin
//     <1=> GPIOB_5
//     <1=> Default
#define PTB5_SEL             1                   

// PTB6 Pin Mapping
//   <o> PTB6  [GPIOB_6] <constant>
//   <i> Selects which peripheral function is mapped to PTB6 pin
//     <1=> GPIOB_6
//     <1=> Default
#define PTB6_SEL             1                   

// PTB7 Pin Mapping
//   <o> PTB7  [GPIOB_7] <constant>
//   <i> Selects which peripheral function is mapped to PTB7 pin
//     <1=> GPIOB_7
//     <1=> Default
#define PTB7_SEL             1                   

// PTC0 Pin Mapping
//   <o> PTC0  [GPIOC_0] <constant>
//   <i> Selects which peripheral function is mapped to PTC0 pin
//     <1=> GPIOC_0
//     <1=> Default
#define PTC0_SEL             1                   

// PTC1 Pin Mapping
//   <o> PTC1  [GPIOC_1] <constant>
//   <i> Selects which peripheral function is mapped to PTC1 pin
//     <1=> GPIOC_1
//     <1=> Default
#define PTC1_SEL             1                   

// PTC2 Pin Mapping
//   <o> PTC2  [GPIOC_2] <constant>
//   <i> Selects which peripheral function is mapped to PTC2 pin
//     <1=> GPIOC_2
//     <1=> Default
#define PTC2_SEL             1                   

// PTC3 Pin Mapping
//   <o> PTC3  [GPIOC_3] <constant>
//   <i> Selects which peripheral function is mapped to PTC3 pin
//     <1=> GPIOC_3
//     <1=> Default
#define PTC3_SEL             1                   

// PTC4 Pin Mapping
//   <o> PTC4  [GPIOC_4] <constant>
//   <i> Selects which peripheral function is mapped to PTC4 pin
//     <1=> GPIOC_4
//     <1=> Default
#define PTC4_SEL             1                   

// PTC5 Pin Mapping
//   <o> PTC5  [ADC0_SE0, GPIOC_5] 
//   <i> Selects which peripheral function is mapped to PTC5 pin
//     <0=> ADC0_SE0
//     <1=> GPIOC_5
//     <0=> Default
#define PTC5_SEL             0                   

// PTC6 Pin Mapping
//   <o> PTC6  [ADC0_SE1, GPIOC_6] 
//   <i> Selects which peripheral function is mapped to PTC6 pin
//     <0=> ADC0_SE1
//     <1=> GPIOC_6
//     <0=> Default
#define PTC6_SEL             0                   

// PTC7 Pin Mapping
//   <o> PTC7  [ADC0_SE2, GPIOC_7] 
//   <i> Selects which peripheral function is mapped to PTC7 pin
//     <0=> ADC0_SE2
//     <1=> GPIOC_7
//     <0=> Default
#define PTC7_SEL             0                   

// PTD0 Pin Mapping
//   <o> PTD0  [GPIOD_0] <constant>
//   <i> Selects which peripheral function is mapped to PTD0 pin
//     <1=> GPIOD_0
//     <1=> Default
#define PTD0_SEL             1                   

// PTD1 Pin Mapping
//   <o> PTD1  [GPIOD_1, SPI0_SS_B] 
//   <i> Selects which peripheral function is mapped to PTD1 pin
//     <1=> GPIOD_1
//     <3=> SPI0_SS_B
//     <1=> Default
#define PTD1_SEL             1                   

// PTD2 Pin Mapping
//   <o> PTD2  [GPIOD_2, SPI0_SCK] 
//   <i> Selects which peripheral function is mapped to PTD2 pin
//     <1=> GPIOD_2
//     <3=> SPI0_SCK
//     <1=> Default
#define PTD2_SEL             1                   

// PTD3 Pin Mapping
//   <o> PTD3  [GPIOD_3, SPI0_MOSI] 
//   <i> Selects which peripheral function is mapped to PTD3 pin
//     <1=> GPIOD_3
//     <3=> SPI0_MOSI
//     <1=> Default
#define PTD3_SEL             1                   

// PTD4 Pin Mapping
//   <o> PTD4  [ADC0_SE3, GPIOD_4, SPI0_MISO] 
//   <i> Selects which peripheral function is mapped to PTD4 pin
//     <0=> ADC0_SE3
//     <1=> GPIOD_4
//     <3=> SPI0_MISO
//     <0=> Default
#define PTD4_SEL             0                   

// PTD5 Pin Mapping
//   <o> PTD5  [ADC0_SE4, GPIOD_5] 
//   <i> Selects which peripheral function is mapped to PTD5 pin
//     <0=> ADC0_SE4
//     <1=> GPIOD_5
//     <0=> Default
#define PTD5_SEL             0                   

// PTD6 Pin Mapping
//   <o> PTD6  [ADC0_SE5, GPIOD_6] 
//   <i> Selects which peripheral function is mapped to PTD6 pin
//     <0=> ADC0_SE5
//     <1=> GPIOD_6
//     <0=> Default
#define PTD6_SEL             0                   

// PTD7 Pin Mapping
//   <o> PTD7  [GPIOD_7, I2C0_SCL] 
//   <i> Selects which peripheral function is mapped to PTD7 pin
//     <1=> GPIOD_7
//     <2=> I2C0_SCL
//     <1=> Default
#define PTD7_SEL             1                   

// PTE0 Pin Mapping
//   <o> PTE0  [GPIOE_0, I2C0_SDA] 
//   <i> Selects which peripheral function is mapped to PTE0 pin
//     <1=> GPIOE_0
//     <2=> I2C0_SDA
//     <1=> Default
#define PTE0_SEL             1                   

// PTE1 Pin Mapping
//   <o> PTE1  [GPIOE_1] <constant>
//   <i> Selects which peripheral function is mapped to PTE1 pin
//     <1=> GPIOE_1
//     <1=> Default
#define PTE1_SEL             1                   

// PTE2 Pin Mapping
//   <o> PTE2  [GPIOE_2, I2C1_SDA] 
//   <i> Selects which peripheral function is mapped to PTE2 pin
//     <1=> GPIOE_2
//     <4=> I2C1_SDA
//     <1=> Default
#define PTE2_SEL             1                   

// PTE3 Pin Mapping
//   <o> PTE3  [GPIOE_3, I2C1_SCL] 
//   <i> Selects which peripheral function is mapped to PTE3 pin
//     <1=> GPIOE_3
//     <4=> I2C1_SCL
//     <1=> Default
#define PTE3_SEL             1                   

// PTE4 Pin Mapping
//   <o> PTE4  [GPIOE_4] <constant>
//   <i> Selects which peripheral function is mapped to PTE4 pin
//     <1=> GPIOE_4
//     <1=> Default
#define PTE4_SEL             1                   

// PTE5 Pin Mapping
//   <o> PTE5  [GPIOE_5] <constant>
//   <i> Selects which peripheral function is mapped to PTE5 pin
//     <1=> GPIOE_5
//     <1=> Default
#define PTE5_SEL             1                   

// PTE6 Pin Mapping
//   <o> PTE6  [GPIOE_6, I2C0_SCL] 
//   <i> Selects which peripheral function is mapped to PTE6 pin
//     <1=> GPIOE_6
//     <5=> I2C0_SCL
//     <1=> Default
#define PTE6_SEL             1                   

// PTE7 Pin Mapping
//   <o> PTE7  [ADC0_SE6, GPIOE_7, I2C0_SDA] 
//   <i> Selects which peripheral function is mapped to PTE7 pin
//     <0=> ADC0_SE6
//     <1=> GPIOE_7
//     <5=> I2C0_SDA
//     <0=> Default
#define PTE7_SEL             0                   

// PTF0 Pin Mapping
//   <o> PTF0  [ADC0_SE7, GPIOF_0] 
//   <i> Selects which peripheral function is mapped to PTF0 pin
//     <0=> ADC0_SE7
//     <1=> GPIOF_0
//     <0=> Default
#define PTF0_SEL             0                   

// PTF1 Pin Mapping
//   <o> PTF1  [ADC0_SE8, GPIOF_1] 
//   <i> Selects which peripheral function is mapped to PTF1 pin
//     <0=> ADC0_SE8
//     <1=> GPIOF_1
//     <0=> Default
#define PTF1_SEL             0                   

// PTF2 Pin Mapping
//   <o> PTF2  [ADC0_SE9, GPIOF_2] 
//   <i> Selects which peripheral function is mapped to PTF2 pin
//     <0=> ADC0_SE9
//     <1=> GPIOF_2
//     <0=> Default
#define PTF2_SEL             0                   

// PTF3 Pin Mapping
//   <o> PTF3  [GPIOF_3, SPI1_SS_B] 
//   <i> Selects which peripheral function is mapped to PTF3 pin
//     <1=> GPIOF_3
//     <2=> SPI1_SS_B
//     <1=> Default
#define PTF3_SEL             1                   

// PTF4 Pin Mapping
//   <o> PTF4  [GPIOF_4, SPI1_SCK] 
//   <i> Selects which peripheral function is mapped to PTF4 pin
//     <1=> GPIOF_4
//     <2=> SPI1_SCK
//     <1=> Default
#define PTF4_SEL             1                   

// PTF5 Pin Mapping
//   <o> PTF5  [GPIOF_5, SPI1_MISO, I2C1_SCL] 
//   <i> Selects which peripheral function is mapped to PTF5 pin
//     <1=> GPIOF_5
//     <2=> SPI1_MISO
//     <3=> I2C1_SCL
//     <1=> Default
#define PTF5_SEL             1                   

// PTF6 Pin Mapping
//   <o> PTF6  [GPIOF_6, SPI1_MOSI, I2C1_SDA] 
//   <i> Selects which peripheral function is mapped to PTF6 pin
//     <1=> GPIOF_6
//     <2=> SPI1_MOSI
//     <3=> I2C1_SDA
//     <1=> Default
#define PTF6_SEL             1                   

// PTF7 Pin Mapping
//   <o> PTF7  [GPIOF_7] <constant>
//   <i> Selects which peripheral function is mapped to PTF7 pin
//     <1=> GPIOF_7
//     <1=> Default
#define PTF7_SEL             1                   

// PTG0 Pin Mapping
//   <o> PTG0  [GPIOG_0] <constant>
//   <i> Selects which peripheral function is mapped to PTG0 pin
//     <1=> GPIOG_0
//     <1=> Default
#define PTG0_SEL             1                   

// PTG1 Pin Mapping
//   <o> PTG1  [ADC0_SE10, GPIOG_1] 
//   <i> Selects which peripheral function is mapped to PTG1 pin
//     <0=> ADC0_SE10
//     <1=> GPIOG_1
//     <0=> Default
#define PTG1_SEL             0                   

// PTG2 Pin Mapping
//   <o> PTG2  [ADC0_SE11, GPIOG_2, SPI0_SS_B] 
//   <i> Selects which peripheral function is mapped to PTG2 pin
//     <0=> ADC0_SE11
//     <1=> GPIOG_2
//     <2=> SPI0_SS_B
//     <0=> Default
#define PTG2_SEL             0                   

// PTG3 Pin Mapping
//   <o> PTG3  [GPIOG_3, SPI0_SCK, I2C0_SCL] 
//   <i> Selects which peripheral function is mapped to PTG3 pin
//     <1=> GPIOG_3
//     <2=> SPI0_SCK
//     <3=> I2C0_SCL
//     <1=> Default
#define PTG3_SEL             1                   

// PTG4 Pin Mapping
//   <o> PTG4  [GPIOG_4, SPI0_MOSI, I2C0_SDA] 
//   <i> Selects which peripheral function is mapped to PTG4 pin
//     <1=> GPIOG_4
//     <2=> SPI0_MOSI
//     <3=> I2C0_SDA
//     <1=> Default
#define PTG4_SEL             1                   

// PTG5 Pin Mapping
//   <o> PTG5  [GPIOG_5, SPI0_MISO] 
//   <i> Selects which peripheral function is mapped to PTG5 pin
//     <1=> GPIOG_5
//     <2=> SPI0_MISO
//     <1=> Default
#define PTG5_SEL             1                   

// PTG6 Pin Mapping
//   <o> PTG6  [GPIOG_6] <constant>
//   <i> Selects which peripheral function is mapped to PTG6 pin
//     <1=> GPIOG_6
//     <1=> Default
#define PTG6_SEL             1                   

// PTG7 Pin Mapping
//   <o> PTG7  [GPIOG_7] <constant>
//   <i> Selects which peripheral function is mapped to PTG7 pin
//     <1=> GPIOG_7
//     <1=> Default
#define PTG7_SEL             1                   

// PTH0 Pin Mapping
//   <o> PTH0  [GPIOH_0] <constant>
//   <i> Selects which peripheral function is mapped to PTH0 pin
//     <1=> GPIOH_0
//     <1=> Default
#define PTH0_SEL             1                   

// PTH1 Pin Mapping
//   <o> PTH1  [GPIOH_1] <constant>
//   <i> Selects which peripheral function is mapped to PTH1 pin
//     <1=> GPIOH_1
//     <1=> Default
#define PTH1_SEL             1                   

// PTH2 Pin Mapping
//   <o> PTH2  [GPIOH_2] <constant>
//   <i> Selects which peripheral function is mapped to PTH2 pin
//     <1=> GPIOH_2
//     <1=> Default
#define PTH2_SEL             1                   

// PTH3 Pin Mapping
//   <o> PTH3  [GPIOH_3] <constant>
//   <i> Selects which peripheral function is mapped to PTH3 pin
//     <1=> GPIOH_3
//     <1=> Default
#define PTH3_SEL             1                   

// PTH4 Pin Mapping
//   <o> PTH4  [GPIOH_4] <constant>
//   <i> Selects which peripheral function is mapped to PTH4 pin
//     <1=> GPIOH_4
//     <1=> Default
#define PTH4_SEL             1                   

// PTH5 Pin Mapping
//   <o> PTH5  [GPIOH_5] <constant>
//   <i> Selects which peripheral function is mapped to PTH5 pin
//     <1=> GPIOH_5
//     <1=> Default
#define PTH5_SEL             1                   

// PTH6 Pin Mapping
//   <o> PTH6  [GPIOH_6, SPI1_SS_B] 
//   <i> Selects which peripheral function is mapped to PTH6 pin
//     <1=> GPIOH_6
//     <3=> SPI1_SS_B
//     <1=> Default
#define PTH6_SEL             1                   

// PTH7 Pin Mapping
//   <o> PTH7  [GPIOH_7, SPI1_SCK] 
//   <i> Selects which peripheral function is mapped to PTH7 pin
//     <1=> GPIOH_7
//     <3=> SPI1_SCK
//     <1=> Default
#define PTH7_SEL             1                   

// PTI0 Pin Mapping
//   <o> PTI0  [GPIOI_0, SPI1_MISO, SPI1_MOSI] 
//   <i> Selects which peripheral function is mapped to PTI0 pin
//     <1=> GPIOI_0
//     <4=> SPI1_MISO
//     <5=> SPI1_MOSI
//     <1=> Default
#define PTI0_SEL             1                   

// PTI1 Pin Mapping
//   <o> PTI1  [GPIOI_1, SPI1_MOSI, SPI1_MISO] 
//   <i> Selects which peripheral function is mapped to PTI1 pin
//     <1=> GPIOI_1
//     <4=> SPI1_MOSI
//     <5=> SPI1_MISO
//     <1=> Default
#define PTI1_SEL             1                   

// PTI2 Pin Mapping
//   <o> PTI2  [GPIOI_2] <constant>
//   <i> Selects which peripheral function is mapped to PTI2 pin
//     <1=> GPIOI_2
//     <1=> Default
#define PTI2_SEL             1                   

// PTI3 Pin Mapping
//   <o> PTI3  [GPIOI_3] <constant>
//   <i> Selects which peripheral function is mapped to PTI3 pin
//     <1=> GPIOI_3
//     <1=> Default
#define PTI3_SEL             1                   

// </h>

//-------- <<< end of configuration section >>> -----------------  

#define FIXED_ADC_FN   0 //!< Fixed ADC Multiplexing value for pins
#define FIXED_GPIO_FN  1 //!< Fixed GPIO Multiplexing value for pins
#define FIXED_PORT_CLOCK_REG  SIM->SCGC5 //!< Fixed PORT Clock varies with port

#endif /* PIN_MAPPING_H_ */
